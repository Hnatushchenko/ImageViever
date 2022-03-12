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
    imageLabel->setBackgroundRole(QPalette::Base);
    scrollArea = new QScrollArea;

    vbox->addWidget(scrollArea, Qt::AlignCenter);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);

    QAction *open = new QAction("Open…", this);
    QAction *saveAs = new QAction("Save As…", this);
    QAction *exit = new QAction("Exit", this);

    open->setShortcut(tr("CTRL+O"));
    saveAs->setShortcut(tr("CTRL+S"));

    QMenu *file = menuBar()->addMenu("File");
    file->addAction(open);
    file->addAction(saveAs);
    file->addAction(exit);

    connect(open, &QAction::triggered, this, &ImageViever::openImage);
    connect(saveAs, &QAction::triggered, this, &ImageViever::saveAs);
    connect(exit, &QAction::triggered, this, &QApplication::quit);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(vbox);
    setCentralWidget(centralWidget);
}

void ImageViever::openImage()
{
    QString newOpenedFilePath = QFileDialog::getOpenFileName(this, "Open Image", QDir::homePath(), "Image Files (*.png *.jpg *.jpeg *.bmp *.tif)");

    if(newOpenedFilePath.isEmpty())
    {
        return;
    }

    openedFilePath = newOpenedFilePath;

    QPixmap pixmap(openedFilePath);

    imageLabel->setPixmap(pixmap);
    imageLabel->resize(pixmap.size().width(), pixmap.size().height());
    scrollArea->setWidget(imageLabel);
    this->resize(pixmap.size().width()+20, pixmap.size().height()+43);

}

void ImageViever::saveAs()
{
    if(openedFilePath.isEmpty())
    {
        return;
    }

    QImage image(openedFilePath);

    QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Image File"), QDir::homePath(), tr("PNG (*.png);;JPEG (*.jpg)"));

    if (!saveFileName.isEmpty())
    {
        image.save(saveFileName);
    }
}


ImageViever::~ImageViever()
{
    delete ui;
}

