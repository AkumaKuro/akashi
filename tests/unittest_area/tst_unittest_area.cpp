#include <QtTest>

#include <include/area_data.h>

Q_DECLARE_METATYPE(AreaData::Side);

namespace tests {
namespace unittests {

/**
 * @brief Unit Tester class for the area-related functions.
 */
class Area : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief An AreaData pointer to test with.
     */
    AreaData* m_area;

    /**
     * @brief A small musiclist to test with.
     */
    QStringList serverMusic = {
        "==Music==",
        "Announce The Truth (AA)",
        "Announce The Truth (AJ)"
    };

private slots:
    /**
     * @brief Initialises every tests with creating a new area with the title "Test Area", and the index of 0.
     */
    void init();

    /**
     * @brief Cleans up the area pointer.
     */
    void cleanup();

    /**
     * @test Tests various scenarios of a client joining and leaving, and what it changes on the area.
     */
    void clientJoinLeave();

    /**
     * @brief The data function for areaStatuses().
     */
    void areaStatuses_data();

    /**
     * @test Tests various attempts at changing area statuses.
     */
    void areaStatuses();

    /**
     * @brief The data function for changeHP().
     */
    void changeHP_data();

    /**
     * @test Tests changing Confidence bar values for the sides.
     */
    void changeHP();

    /**
     * @test Tests changing character in the area.
     */
    void changeCharacter();

    /**
     * @brief Tests entire testimony recorder.
     */
    void testimony();

    /**
     * @brief Tests the area jukebox.
     */
    void jukebox();

    /**
     * @brief The data function for validateCustomSong()
     */
    void validateCustomSong_data();

    /**
     * @brief Tests validation of custom song candidates.
     */
    void validateCustomSong();

    /**
     * @brief The data function for customCategory()
     */
    void addCustomCategory_data();

    /**
     * @brief Tests the addition of categories into the custom musiclist.
     */
    void addCustomCategory();
};

void Area::init()
{
    m_area = new AreaData("Test Area", 0 ,&serverMusic);
}

void Area::cleanup()
{
    delete m_area;
}

void Area::clientJoinLeave()
{
    {
        // There must be exactly one client in the area, and it must have a charid of 5.
        m_area->clientJoinedArea(5);

        QCOMPARE(m_area->charactersTaken().size(), 1);
        QCOMPARE(m_area->charactersTaken().at(0), 5);
    }
    {
        // No clients must be left in the area.
        m_area->clientLeftArea(5);

        QCOMPARE(m_area->charactersTaken().size(), 0);
    }
}

void Area::areaStatuses_data()
{
    QTest::addColumn<QString>("statusCall");
    QTest::addColumn<AreaData::Status>("expectedStatus");
    QTest::addColumn<bool>("isSuccessful");

    QTest::newRow("Idle") << "idle" << AreaData::Status::IDLE << true;
    QTest::newRow("RP") << "rp" << AreaData::Status::RP << true;
    QTest::newRow("Casing") << "casing" << AreaData::Status::CASING << true;
    QTest::newRow("Looking for players (long)") << "looking-for-players" << AreaData::Status::LOOKING_FOR_PLAYERS << true;
    QTest::newRow("Looking for players (short)") << "lfp" << AreaData::Status::LOOKING_FOR_PLAYERS << true;
    QTest::newRow("Gaming") << "gaming" << AreaData::Status::GAMING << true;
    QTest::newRow("Recess") << "recess" << AreaData::Status::RECESS << true;
    QTest::newRow("Nonsense") << "blah" << AreaData::Status::IDLE << false;
}

void Area::areaStatuses()
{
    QFETCH(QString, statusCall);
    QFETCH(AreaData::Status, expectedStatus);
    QFETCH(bool, isSuccessful);

    bool l_success = m_area->changeStatus(statusCall);

    QCOMPARE(m_area->status(), expectedStatus);
    QCOMPARE(l_success, isSuccessful);
}

void Area::changeHP_data()
{
    QTest::addColumn<AreaData::Side>("side");
    QTest::addColumn<int>("setHP");
    QTest::addColumn<int>("expectedHP");

    QTest::newRow("Set = Expected (DEF)") << AreaData::Side::DEFENCE << 3 << 3;
    QTest::newRow("Set = Expected (PRO)") << AreaData::Side::PROSECUTOR << 5 << 5;
    QTest::newRow("Below Zero (DEF)") << AreaData::Side::DEFENCE << -5 << 0;
    QTest::newRow("Below Zero (PRO)") << AreaData::Side::PROSECUTOR << -7 << 0;
    QTest::newRow("Above Ten (DEF)") << AreaData::Side::DEFENCE << 12 << 10;
    QTest::newRow("Above Ten (PRO)") << AreaData::Side::PROSECUTOR << 14 << 10;
}

void Area::changeHP()
{
    QFETCH(AreaData::Side, side);
    QFETCH(int, setHP);
    QFETCH(int, expectedHP);

    m_area->changeHP(side, setHP);

    if (AreaData::Side::DEFENCE == side) {
        QCOMPARE(expectedHP, m_area->defHP());
    } else {
        QCOMPARE(expectedHP, m_area->proHP());
    }
}

void Area::changeCharacter()
{
    {
        // A client with a charid of 6 joins. There's only them in there.
        m_area->clientJoinedArea(6);

        QCOMPARE(m_area->charactersTaken().size(), 1);
        QCOMPARE(m_area->charactersTaken().at(0), 6);
    }
    {
        // Charid 7 is marked as taken. No other client in the area still.
        // Charids 6 and 7 are taken.
        m_area->changeCharacter(-1, 7);

        QCOMPARE(m_area->playerCount(), 1);
        QCOMPARE(m_area->charactersTaken().size(), 2);
        QCOMPARE(m_area->charactersTaken().at(0), 6);
        QCOMPARE(m_area->charactersTaken().at(1), 7);
    }
    {
        // Client switches to charid 8.
        // Charids 8 and 7 are taken.
        m_area->changeCharacter(6, 8);

        QCOMPARE(m_area->playerCount(), 1);
        QCOMPARE(m_area->charactersTaken().size(), 2);
        QCOMPARE(m_area->charactersTaken().at(0), 7);
        QCOMPARE(m_area->charactersTaken().at(1), 8);
    }
    {
        // Client attempts to switch to 7.
        // Nothing changes, as it is already taken.

        m_area->changeCharacter(8, 7);

        QCOMPARE(m_area->playerCount(), 1);
        QCOMPARE(m_area->charactersTaken().size(), 2);
        QCOMPARE(m_area->charactersTaken().at(0), 7);
        QCOMPARE(m_area->charactersTaken().at(1), 8);
    }
    {
        // Charid 7 is unlocked for use.
        // Charid 8 is taken.
        m_area->changeCharacter(7, -1);

        QCOMPARE(m_area->playerCount(), 1);
        QCOMPARE(m_area->charactersTaken().size(), 1);
        QCOMPARE(m_area->charactersTaken().at(0), 8);
    }
}

void Area::testimony()
{
    QVector<QStringList> l_testimony = {
        {"A"},
        {"B"},
        {"C"},
        {"D"},
        {"E"},
    };

    {
        // Add all statements, and check that they're added.
        for (const auto& l_statement : l_testimony)
        {
            m_area->recordStatement(l_statement);

            QCOMPARE(l_statement, m_area->testimony().at(m_area->statement() - 1));
        }
    }
    {
        // Restart testimony, advance two times.
        m_area->jumpToStatement(1);

        for (int i = 1; i < l_testimony.size() - 1; i++) {
           const auto& l_results = m_area->jumpToStatement(m_area->statement() + 1);

           QCOMPARE(l_results.first, l_testimony.at(i + 1));
           QCOMPARE(l_results.second, AreaData::TestimonyProgress::OK);
        }
    }
    {
        // Next advancement loops the testimony.
        const auto& l_results = m_area->jumpToStatement(m_area->statement() + 1);

        QCOMPARE(l_results.first, l_testimony.at(1));
        QCOMPARE(l_results.second, AreaData::TestimonyProgress::LOOPED);
    }
    {
        // Going back makes the testimony stay at the first statement.
        const auto& l_results = m_area->jumpToStatement(m_area->statement() - 1);

        QCOMPARE(l_results.first, l_testimony.at(1));
        QCOMPARE(l_results.second, AreaData::TestimonyProgress::STAYED_AT_FIRST);
    }
}

void Area::jukebox()
{
    QCOMPARE(1,1);
}

void Area::validateCustomSong_data()
{
    //Songname can also be the realname.
    QTest::addColumn<QString>("songname");
    QTest::addColumn<bool>("expectedResult");

    QTest::addRow("Songname - No extension") << "Announce The Truth (AA)" << false;
    QTest::addRow("Songname - Valid Extension") << "Announce The Truth (AA).opus" << true;
    QTest::addRow("Songname - Invalid Extension") << "Announce The Truth (AA).aac" << false;
    QTest::addRow("URL - Valid primary") << "https://my.cdn.com/mysong.opus" << true;
    QTest::addRow("URL - Valid secondary") << "https://your.cdn.com/mysong.opus" << true;
    QTest::addRow("URL - Invalid extension") << "https://my.cdn.com/mysong.aac." << false;
    QTest::addRow("URL - Invalid prefix") << "ftp://my.cdn.com/mysong.opus" << false;
    QTest::addRow("URL - Invalid missing prefix") << "my.cdn.com/mysong.opus" << false;
    QTest::addRow("URL - Invalid CDN") << "https://myipgrabber.com/mysong.opus" << false;
    QTest::addRow("URL - Subdomain Attack") << "https://my.cdn.com.fakedomain.com/mysong.opus" << false;
}

void Area::validateCustomSong()
{
    QFETCH(QString,songname);
    QFETCH(bool,expectedResult);

    bool l_result = m_area->validateCustomSong(songname, {"my.cdn.com","your.cdn.com"});
    QCOMPARE(expectedResult,l_result);
}

void Area::addCustomCategory_data()
{
    QTest::addColumn<QString>("category");
    QTest::addColumn<QStringList>("expectedCustomlist");
    QTest::addColumn<bool>("globalEnabled");

    QTest::addRow("Invalid - Same as main") << "Music" << QStringList{} << true;
}

void Area::addCustomCategory()
{
    QFETCH(QString,category);
    QFETCH(QStringList,expectedCustomlist);
    QFETCH(bool,globalEnabled);

    if(m_area->globalListEnabled() != globalEnabled)

    m_area->addCustomCategory(category);
}

}
}

QTEST_APPLESS_MAIN(tests::unittests::Area)

#include "tst_unittest_area.moc"
