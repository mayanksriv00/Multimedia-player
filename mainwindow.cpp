#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about_display.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //this->setStyleSheet("background-color: black;");
    ui->setupUi(this);
    //object creations
    m_player = new QMediaPlayer(this);
    m_videowidget = new QVideoWidget(this);

    ui->gridLayout->addWidget(m_videowidget,20,20);

   // m_slider = new QSlider;
    m_progressbar = new QProgressBar;
    m_player->setVideoOutput(m_videowidget);
   // this->setCentralWidget(m_videowidget);
    //m_slider=new QSlider(this);

    //ui->statusbar->addPermanentWidget(m_slider);
    //m_slider->setOrientation(Qt::Horizontal);

    connect(m_player,&QMediaPlayer::durationChanged,ui->horizontalSlider1,&QSlider::setMaximum);
    connect(m_player,&QMediaPlayer::positionChanged,ui->horizontalSlider1,&QSlider::setValue);
    connect(ui->horizontalSlider1,&QSlider::sliderMoved,m_player,&QMediaPlayer::setPosition);





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{

    m_player->setVideoOutput(m_videowidget);
    QString l_filename = QFileDialog::getOpenFileName(this,"Open a File","","Video Formats (*.*)");
    on_actionStop_triggered();

    m_player->setMedia(QUrl::fromLocalFile(l_filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    m_player->play();
    ui->statusbar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    m_player->pause();
    ui->statusbar->showMessage("Paused");
}

void MainWindow::on_actionStop_triggered()
{
    m_player->stop();
    ui->statusbar->showMessage("Stopped");

}

void MainWindow::on_actionMute_triggered()
{
    m_player->setVolume(0);
    ui->statusbar->showMessage("Muted");
}

void MainWindow::on_actionIncrease_Volume_triggered()
{
    m_volume=m_volume+10;
    m_player->setVolume(m_volume);
    ui->statusbar->showMessage("Volume increased");
}

void MainWindow::on_actionDecrease_volume_triggered()
{
    m_volume=m_volume-20;
    m_player->setVolume(m_volume);
    ui->statusbar->showMessage("Volume decreased");

}

void MainWindow::on_actionNext_triggered()
{

}

void MainWindow::on_actionQuit_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{
    About_display about_disp;
    about_disp.setModal(true);
    about_disp.exec();
}
