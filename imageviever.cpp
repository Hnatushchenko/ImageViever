#include "imageviever.h"
#include "ui_imageviever.h"

ImageViever::ImageViever(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageViever)
{
    ui->setupUi(this);
}

ImageViever::~ImageViever()
{
    delete ui;
}

