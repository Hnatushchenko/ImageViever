#include "imageviever.h"
#include "ui_imageviever.h"

ImageViever::ImageViever(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageViever)
{
    ui->setupUi(this);

    QVBoxLayout *vbox = new QVBoxLayout(this);

    imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    scrollArea = new QScrollArea;

    vbox->addWidget(scrollArea, Qt::AlignCenter);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);

    QAction *open = new QAction("Open…", this);
    QAction *exit = new QAction("Exit", this);

    open->setShortcut(tr("CTRL+O"));

    QMenu *file = menuBar()->addMenu("File");
    file->addAction(open);
    file->addAction(exit);

    connect(open, &QAction::triggered, this, &ImageViever::openImage);
    connect(exit, &QAction::triggered, this, &QApplication::quit);



    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(vbox);
    setCentralWidget(centralWidget);
}

void ImageViever::openImage()
{
    QString openedFilePath = QFileDialog::getOpenFileName(this, "Open Image", QDir::homePath(), "Image Files (*.png *.jpg *.jpeg *.bmp *.tif)");

    if(openedFilePath.isEmpty())
    {
        return;
    }

    QPixmap pixmap(openedFilePath);

    imageLabel->setPixmap(pixmap);
    imageLabel->resize(pixmap.size().width(), pixmap.size().height());
    scrollArea->setWidget(imageLabel);
    this->resize(pixmap.size().width()+20, pixmap.size().height()+43);
}


ImageViever::~ImageViever()
{
    delete ui;
}

