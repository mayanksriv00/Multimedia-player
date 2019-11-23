#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QObject>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionMute_triggered();

    void on_actionIncrease_Volume_triggered();

    void on_actionDecrease_volume_triggered();

    void on_actionNext_triggered();

    void on_actionQuit_triggered();

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_destroyed();

    void on_actionAbout_triggered();

    void on_actionQuit_destroyed(QObject *arg1);

private:
    int m_volume=45;
    Ui::MainWindow *ui;
    QMediaPlayer* m_player;
    QVideoWidget* m_videowidget;
    QProgressBar* m_progressbar;
    QSlider* m_slider;


};
#endif // MAINWINDOW_H
