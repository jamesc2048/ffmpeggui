#ifndef FFMPEGCAPABILITIES_H
#define FFMPEGCAPABILITIES_H

#include <QObject>

#include "pch.hpp"

enum class AnalysisState
{
    NotAnalysed,
    AnalysisComplete
};

class EncoderCapabilities : QObject
{
    Q_OBJECT

public:
    QString codecCaps;
    QString codec;
    QString codecDescription;

    EncoderCapabilities(QString cCaps, QString c, QString cDesc) :
        codecCaps(cCaps), codec(c), codecDescription(cDesc)
    {
    }
};

class FfmpegCapabilities : public QObject
{
    Q_OBJECT 

public:
    AnalysisState analysisState;
    QString ffmpegFilePath;

    QList<EncoderCapabilities> encoderCapabilities;

    explicit FfmpegCapabilities(QObject *parent = nullptr);
    void analyseFfmpeg();
    void checkForFfmpegInstallation();

signals:

public slots:
};

#endif // FFMPEGCAPABILITIES_H
