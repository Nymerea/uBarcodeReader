import QtQuick 2.0
import Ubuntu.Components 1.1
import QZXing 2.3
/*!
    \brief MainView with a Label and Button elements.
*/

MainView {
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

    Page {
        title: i18n.tr("OpenFoodFacts")

        Image{
            id:imageToDecode
            source: "barcode.jpg"
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
        }
    }
}

