import QtQuick 2.0
import Ubuntu.Components 1.1
import QZXing 2.3
import QtMultimedia 5.0

MainView {
    id:mainView;
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "openfoodfacts.nymeria"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(75)

    /*Connections {
        target: imgGraber
    }*/

    Page {
        title: i18n.tr("OpenFoodFacts")

        Component.onCompleted: {
            qDecoder.scanRect = Qt.rect(mainView.mapFromItem(videoOutput, 0, 0).x, mainView.mapFromItem(videoOutput, 0, 0).y, videoOutput.width, videoOutput.height)
        }

        Camera {
            id:camera
            objectName: camera
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
            exposure {
                exposureCompensation: -1.0
                exposureMode: Camera.ExposurePortrait
            }
            flash.mode: Camera.FlashRedEyeReduction
            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview  // Show the preview in an Image
                }
            }
        }
        VideoOutput {
            id: videoOutput
            source: camera
            anchors.fill: parent
            focus : visible // to receive focus and capture key events when visible

            MouseArea {
                anchors.fill: parent
                onClicked: { qDecoder.grabWindow() }
            }
        }

       /* Image{
            id:imageToDecode
            source: "barcode.jpg"
            visible:true
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log(imageToDecode.source)
                    decoder.decodeImageFromFile(imageToDecode.source, 1000,1000, true)
                }
            }

        }

        QZXing{
            id: decoder

            //enabledDecoders: QZXing.DecoderFormat_EAN_13

            onDecodingStarted: console.log("Decoding of image started...")

            onTagFound: console.log("Barcode data: " + tag)

            onDecodingFinished: console.log("Decoding finished " + (succeeded==true ? "successfully" :    "unsuccessfully") )
        }*/
    }
}

