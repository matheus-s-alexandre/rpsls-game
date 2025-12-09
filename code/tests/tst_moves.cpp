// #include <QTest>
// #include "../logic/moves/rock.h"
// #include "../logic/moves/paper.h"
// #include "../logic/moves/scissors.h"
// #include "../logic/moves/lizard.h"
// #include "../logic/moves/spock.h"

// class TestMoves : public QObject {
//     Q_OBJECT

// private slots:
//     void testRock() {
//         Rock rock; Scissors scissors; Lizard lizard; Paper paper; Spock spock;
//         // Rock crushes Scissors
//         QVERIFY(rock.defeats(scissors));
//         // Rock crushes Lizard
//         QVERIFY(rock.defeats(lizard));
//         // Paper covers Rock
//         QVERIFY(!rock.defeats(paper));
//         // Spock vaporizes Rock
//         QVERIFY(!rock.defeats(spock));
//     }

//     void testScissors() {
//         Scissors scissors; Paper paper; Lizard lizard; Rock rock; Spock spock;
//         // Scissors cuts Paper
//         QVERIFY(scissors.defeats(paper));
//         // Scissors decapitates Lizard
//         QVERIFY(scissors.defeats(lizard));
//         // Rock crushes Scissors
//         QVERIFY(!scissors.defeats(rock));
//         // Spock smashes Scissors
//         QVERIFY(!scissors.defeats(spock));
//     }
// };

// QTEST_APPLESS_MAIN(TestMoves)
// #include "tst_moves.moc"
