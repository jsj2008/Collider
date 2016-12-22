# -*- coding: utf-8 -*-
# Deployment settings for GameSceneGL.
# This file is autogenerated by the mkb system and used by the s3e deployment
# tool during the build process.

config = {}
cmdline = ['/Applications/Marmalade.app/Contents/s3e/makefile_builder/mkb.py', '/Users/deltutto/My_Collider/atlasapp/GameSceneGL.mkb', '--deploy-only', '--buildenv=XCODE', '--aarch64', '--compiler=gcc']
mkb = '/Users/deltutto/My_Collider/atlasapp/GameSceneGL.mkb'
mkf = ['/Applications/Marmalade.app/Contents/s3e/s3e-default.mkf', '/Applications/Marmalade.app/Contents/modules/derbh/derbh.mkf', '/Users/deltutto/My_Collider/atlasapp/AppEasyCoreSDK/AppEasy.mkf', '/Users/deltutto/My_Collider/atlasapp/AppEasyCoreSDK/Libs/lua-vec/lua-vec.mkf', '/Applications/Marmalade.app/Contents/modules/iwgx/iwgx.mkf', '/Applications/Marmalade.app/Contents/modules/iwgl/iwgl.mkf', '/Applications/Marmalade.app/Contents/modules/iwutil/iwutil.mkf', '/Applications/Marmalade.app/Contents/modules/third_party/libjpeg/libjpeg.mkf', '/Applications/Marmalade.app/Contents/modules/third_party/libpng/libpng.mkf', '/Applications/Marmalade.app/Contents/modules/third_party/zlib/zlib.mkf', '/Applications/Marmalade.app/Contents/modules/iwgeom/iwgeom.mkf', '/Applications/Marmalade.app/Contents/modules/iwresmanager/iwresmanager.mkf', '/Applications/Marmalade.app/Contents/extensions/PVRTexTool/PVRTexTool.mkf', '/Applications/Marmalade.app/Contents/modules/iw2d/iw2d.mkf', '/Applications/Marmalade.app/Contents/modules/iwgxfont/iwgxfont.mkf', '/Applications/Marmalade.app/Contents/modules/third_party/tiniconv/tiniconv.mkf', '/Applications/Marmalade.app/Contents/modules/iwhttp/iwhttp.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/s3eWebView.mkf', '/Applications/Marmalade.app/Contents/platform_libs/android/android-support-v4/android-support-v4.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/s3eFacebook.mkf', '/Applications/Marmalade.app/Contents/platform_libs/android/marmalade-facebook-android-sdk/marmalade-facebook-android-sdk.mkf', '/Applications/Marmalade.app/Contents/platform_libs/android/bolts-android/bolts-android.mkf', '/Applications/Marmalade.app/Contents/platform_libs/iphone/marmalade-facebook-iphone-sdk/marmalade-facebook-iphone-sdk.mkf', '/Applications/Marmalade.app/Contents/modules/iwbilling/iwbilling.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eIOSAppStoreBilling/s3eIOSAppStoreBilling.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eWindowsStoreBilling/s3eWindowsStoreBilling.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eAmazonInAppPurchasing/s3eAmazonInAppPurchasing.mkf', '/Applications/Marmalade.app/Contents/platform_libs/android/amazon-in-app-purchasing-android-sdk/amazon-in-app-purchasing-android-sdk.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/s3eAndroidGooglePlayBilling.mkf', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/s3eSamsungInAppPurchasing.mkf', '/Users/deltutto/My_Collider/atlasapp/AppEasyCoreSDK/Libs/SoundEngine/SoundEngine.mkf', '/Users/deltutto/My_Collider/atlasapp/AppEasyCoreSDK/Libs/box2d/box2d.mkf', '/Applications/Marmalade.app/Contents/modules/third_party/sqlite/sqlite.mkf', '/Users/deltutto/My_Collider/atlasapp/AppEasyCoreSDK/Libs/lsqlite3/lsqlite3.mkf', '/Users/deltutto/My_Collider/atlasapp/GameSceneGL_deployment.mkf']

class DeployConfig(object):
    pass

######### ASSET GROUPS #############

assets = {}

assets['Default'] = [
    ('/Applications/Marmalade.app/Contents/extensions/s3eWebView/s3eWebView.js', 's3eWebView.js', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/Common.xml', 'Common.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/UIStyle.xml', 'UIStyle.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/test_detectors.xml', 'test_detectors.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/MenuScene.xml', 'MenuScene.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/ColourScene.xml', 'ColourScene.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/hunt_higgs_game.xml', 'hunt_higgs_game.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/eventDisplay.xml', 'eventDisplay.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/LandingScreen.xml', 'LandingScreen.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WebBrowserScene.xml', 'WebBrowserScene.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/LandingMenu.xml', 'LandingMenu.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/GameScene.xml', 'GameScene.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/LiveScene.xml', 'LiveScene.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/Credits.xml', 'Credits.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/TestList.xml', 'TestList.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame1.xml', 'WandZGame1.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame2.xml', 'WandZGame2.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame3.xml', 'WandZGame3.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/Gulim.ttf', 'Gulim.ttf', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/test_image.jpg', 'test_image.jpg', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/menu.png', 'menu.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/box.png', 'box.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/boxunder.png', 'boxunder.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/boxoutline.png', 'boxoutline.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/back.png', 'back.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/next.png', 'next.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/prev.png', 'prev.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/pointright.png', 'pointright.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/pointleft.png', 'pointleft.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/home.png', 'home.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/refresh.png', 'refresh.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/slide.png', 'slide.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/slide_groove.png', 'slide_groove.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/cross.png', 'cross.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/qmark.png', 'qmark.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon32.png', 'icon32.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon36.png', 'icon36.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon48.png', 'icon48.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon64.png', 'icon64.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon72.png', 'icon72.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icon128.png', 'icon128.png', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/HiggsGame.xml', 'HiggsGame.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/empty.xml', 'empty.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/electron.xml', 'electron.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/muon.xml', 'muon.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/neutrino.xml', 'neutrino.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/jet.xml', 'jet.xml', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/HiggsGame', 'HiggsGame', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame1', 'WandZGame1', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame2', 'WandZGame2', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/WandZGame3', 'WandZGame3', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/icons', 'icons', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data/images', 'images', 0),
    ('/Users/deltutto/My_Collider/atlasapp/data-ram/data-gles1/fonts.group.bin,/Users/deltutto/My_Collider/atlasapp/data/fonts.group.bin', 'fonts.group.bin', 0),
]

######### DEFAULT CONFIG #############

class DefaultConfig(DeployConfig):
    embed_icf = 1
    name = 'collider'
    pub_sign_key = 0
    priv_sign_key = 0
    caption = 'Collider'
    long_caption = 'collider'
    version = [1, 1, 0]
    config = ['/Users/deltutto/My_Collider/atlasapp/data/app.icf']
    data_dir = '/Users/deltutto/My_Collider/atlasapp/data'
    mkb_dir = '/Users/deltutto/My_Collider/atlasapp'
    iphone_link_lib = ['s3eWebView', 's3eFacebook', 's3eIOSAppStoreBilling']
    tvos_link_lib = []
    android_keystore = '/Users/deltutto/My_Collider/atlasapp/collider-release-key.keystore'
    osx_ext_dll = ['/Applications/Marmalade.app/Contents/extensions/PVRTexTool/lib/osx/libPVRTexTool.dylib', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/osx/libs3eWebView.dylib']
    iphone_extra_string = []
    iphone_provisioning_profile = '/Users/deltutto/Downloads/ColliderDistributionProvisioningProfile.mobileprovision'
    wp81_extra_pri = []
    ws8_ext_capabilities = []
    provider = 'deltutto'
    android_pkgname = 'com.deltutto.collider'
    ws8_ext_native_only_dll = []
    win10_ext_uap_capabilities = []
    iphone_minimum_ios_version = '8.0'
    tizen_so = []
    tvos_extra_string = []
    tvos_link_libs = []
    win10_ext_native_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win10/s3eWebViewExtension.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/win10/s3eFacebookExtension.dll']
    ws81_ext_native_only_dll = []
    android_external_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/android/res', '/Applications/Marmalade.app/Contents/platform_libs/android/marmalade-facebook-android-sdk/third_party/facebook/res', '/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/source/android/res', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/source/android/res']
    iphone_icon_ipad = '/Users/deltutto/My_Collider/atlasapp/data/icon72.png'
    iphone_icon_dir = 'data'
    win32_ext_dll = ['/Applications/Marmalade.app/Contents/extensions/PVRTexTool/lib/win32/PVRTexTool.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/s3eWebView.dll']
    iphone_icon_ipad_high_res = '/Users/deltutto/My_Collider/atlasapp/data/icon144.png'
    tvos_link_libdirs = []
    android_icon_hdpi = '/Users/deltutto/My_Collider/atlasapp/data/icon72_and.png'
    wp8_ext_capabilities = []
    ws8_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/ws8/WebViewModal.xaml=>', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws8_lib/Facebook_Client']
    iphone_extra_plugins = []
    ws81_ext_managed_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/ws81/s3eWebViewManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/ws81/s3eFacebookManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws81_lib/Facebook.Client.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws8_lib/Facebook.dll']
    iphone_icon_ipad_search_high_res = '/Users/deltutto/My_Collider/atlasapp/data/icon100.png'
    iphone_link_libdir = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/iphone', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/iphone', '/Applications/Marmalade.app/Contents/extensions/s3eIOSAppStoreBilling/lib/iphone']
    wp81_ext_capabilities = []
    android_extra_application_manifest = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/android/extra_app_manifest.xml', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/source/android/extra_app_manifest.xml', '/Applications/Marmalade.app/Contents/extensions/s3eAmazonInAppPurchasing/source/android/AmazonInAppPurchasingManifestSnippet.xml', '/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/source/android/ExtraAppManifests.xml', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/source/android/ExtraAppManifests.xml']
    win10_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win10/WebViewModal.xbf=>', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_win10_lib/Facebook.Client']
    ws8_ext_native_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/ws8/s3eWebViewExtension.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/ws8/s3eFacebookExtension.dll']
    android_keypass = 'OxfordPhysicsThing'
    iphone_link_libdirs = []
    android_external_assets = []
    iphone_icon_settings_high_res = '/Users/deltutto/My_Collider/atlasapp/data/icon58.png'
    android_manifest = '/Users/deltutto/My_Collider/atlasapp/AndroidManifest.xml'
    blackberry_extra_descriptor = []
    android_ext_target_sdk_version = []
    android_extra_manifest = ['/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/source/android/ExtraManifests.xml', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/source/android/ExtraManifests.xml']
    wp81_ext_sdk_ref = []
    tvos_link_libdir = []
    wp81_ext_device_capabilities = []
    android_icon_mdpi = '/Users/deltutto/My_Collider/atlasapp/data/icon48.png'
    android_extra_application_attributes_manifest = []
    iphone_sign_for_distribution = 1
    icon = '/Users/deltutto/My_Collider/atlasapp/data/icon512_ios.png'
    win10_ext_capabilities = []
    iphone_icon_high_res = '/Users/deltutto/My_Collider/atlasapp/data/icon114.png'
    linux_ext_lib = []
    copyright = 'University of Oxford'
    android_activity_hardware_accelerate = 1
    android_ext_min_sdk_version = [9, 9]
    android_aliasname = 'ColliderOxfordPhysics'
    wp81_ext_native_only_dll = []
    ws8_ext_managed_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/ws8/s3eWebViewManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/ws8/s3eFacebookManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws8_lib/Facebook.Client.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws8_lib/Facebook.dll']
    tvos_extra_plugins = []
    ws8_ext_sdk_manifest_part = []
    ws8_ext_device_capabilities = []
    ws81_extra_pri = []
    android_external_jars = ['/Applications/Marmalade.app/Contents/platform_libs/android/android-support-v4/android-support-v4.jar', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/android/s3eWebView.jar', '/Applications/Marmalade.app/Contents/platform_libs/android/bolts-android/bolts-android-1.1.2.jar', '/Applications/Marmalade.app/Contents/platform_libs/android/marmalade-facebook-android-sdk/lib/android/marmalade-facebook-android-sdk-3.23.1.jar', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/android/s3eFacebook.jar', '/Applications/Marmalade.app/Contents/platform_libs/android/amazon-in-app-purchasing-android-sdk/third_party/lib/in-app-purchasing-2.0.61.jar', '/Applications/Marmalade.app/Contents/extensions/s3eAmazonInAppPurchasing/lib/android/s3eAmazonInAppPurchasing.jar', '/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/lib/android/s3eAndroidGooglePlayBilling.jar', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/lib/android/s3eSamsungInAppPurchasing.jar', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/lib/android/iap2.0_lib.jar']
    win8_winrt_extra_res = []
    wp81_ext_sdk_manifest_part = []
    iphone_icon_ipad_ios7 = '/Users/deltutto/My_Collider/atlasapp/data/icon76.png'
    wp81_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/ws8/WebViewModal.xaml=>', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_wp81_lib/Facebook.Client']
    android_storepass = 'OxfordPhysicsThing'
    iphone_external_assets = []
    wp81_ext_managed_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/wp81/s3eWebViewManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/wp81/s3eFacebookManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_wp81_lib/Facebook.Client.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws81_lib/Facebook.dll']
    tvos_link_opts = []
    win10_ext_managed_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win10/s3eWebViewManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/win10/s3eFacebookManaged.winmd', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_win10_lib/Facebook.Client.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_win10_lib/Facebook.dll']
    iphone_icon_ipad_search_high_res_ios7 = '/Users/deltutto/My_Collider/atlasapp/data/icon80.png'
    iphone_extra_plist = ['/Applications/Marmalade.app/Contents/extensions/s3eFacebook/s3eFacebook.plist']
    ws81_ext_sdk_manifest_part = []
    ws81_ext_device_capabilities = []
    android_supports_gl_texture = []
    ws8_ext_sdk_ref = []
    tvos_asset_catalog = []
    version_string = '1.1.1'
    iphone_icon_high_res_ios7 = '/Users/deltutto/My_Collider/atlasapp/data/icon120.png'
    osx_extra_plist = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/osx/Info.plist']
    wp8_ext_native_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/wp8/s3eWebViewExtension.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/wp8/s3eFacebookExtension.dll']
    win10_ext_sdk_manifest_part = []
    iphone_icon_ipad_search = '/Users/deltutto/My_Collider/atlasapp/data/icon50.png'
    tvos_extra_plist = []
    win10_extra_pri = []
    iphone_icon_ipad_search_ios7 = '/Users/deltutto/My_Collider/atlasapp/data/icon40.png'
    win10_ext_device_capabilities = []
    win8_phone_extra_res = []
    win8_store_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_ws81_lib/Facebook.Client']
    win32_aux_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/locales', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/cef.pak', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/cef_100_percent.pak', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/cef_200_percent.pak', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/cef_extensions.pak', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/d3dcompiler_43.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/d3dcompiler_47.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/devtools_resources.pak', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/icudtl.dat', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/libcef.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/libEGL.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/libGLESv2.dll', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/natives_blob.bin', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/snapshot_blob.bin', '/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/win32/widevinecdmadapter.dll']
    iphone_link_opts = ['-weak_framework WebKit', '-F/Applications/Marmalade.app/Contents/platform_libs/iphone/marmalade-facebook-iphone-sdk -framework FacebookSDK', '-weak_framework UIKit -weak_framework Foundation -weak_framework CoreGraphics -weak_framework Social']
    ws81_ext_sdk_ref = []
    wp8_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/wp8/WebBrowserModal.xaml=>']
    iphone_disable_testflight = 0
    android_icon_ldpi = '/Users/deltutto/My_Collider/atlasapp/data/icon36.png'
    manufacturer = 'deltutto'
    ws81_ext_native_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/ws81/s3eWebViewExtension.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/ws81/s3eFacebookExtension.dll']
    ws8_extra_pri = []
    wp8_ext_managed_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/wp8/s3eWebViewManaged.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/wp8/s3eFacebookManaged.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_wp8_lib/Facebook.Client.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_wp8_lib/Facebook.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/third-party/facebook_wp8_lib/System.Net.Http.dll']
    android_extra_packages = ['com.facebook.android']
    android_icon = '/Users/deltutto/My_Collider/atlasapp/data/icon48.png'
    iphone_icon_settings = '/Users/deltutto/My_Collider/atlasapp/data/icon29.png'
    android_so = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/android/libs3eWebView.so', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/android/libs3eFacebook.so', '/Applications/Marmalade.app/Contents/extensions/s3eAmazonInAppPurchasing/lib/android/libs3eAmazonInAppPurchasing.so', '/Applications/Marmalade.app/Contents/extensions/s3eAndroidGooglePlayBilling/lib/android/libs3eAndroidGooglePlayBilling.so', '/Applications/Marmalade.app/Contents/extensions/s3eSamsungInAppPurchasing/lib/android/libs3eSamsungInAppPurchasing.so']
    wp8_ext_sdk_ref = []
    osx_extra_res = []
    ws81_extra_res = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/source/ws8/WebViewModal.xaml=>']
    wp81_ext_native_dll = ['/Applications/Marmalade.app/Contents/extensions/s3eWebView/lib/wp81/s3eWebViewExtension.dll', '/Applications/Marmalade.app/Contents/extensions/s3eFacebook/lib/wp81/s3eFacebookExtension.dll']
    iphone_icon = '/Users/deltutto/My_Collider/atlasapp/data/icon57.png'
    ws81_ext_capabilities = []
    iphone_icon_ipad_high_res_ios7 = '/Users/deltutto/My_Collider/atlasapp/data/icon152.png'
    iphone_link_libs = []
    android_extra_strings = ['(facebook_app_id,1159270594165661)']
    target = {
         'aarch64_gcc' : {
                   'debug'   : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Debug AARCH64/GameSceneGL.s3e',
                   'release' : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Release AARCH64/GameSceneGL.s3e',
                 },
         'aarch64_tvos' : {
                   'debug'   : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Debug AARCH64/GameSceneGL.framework',
                   'release' : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Release AARCH64/GameSceneGL.framework',
                 },
         'naclx86_64' : {
                   'debug'   : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Debug X86_64 NaCL/GameSceneGL.so.s64',
                   'release' : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Release X86_64 NaCL/GameSceneGL.so.s64',
                 },
         'x86' : {
                   'debug'   : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Debug/GameSceneGL.s86',
                   'release' : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Release/GameSceneGL.s86',
                 },
         'arm_gcc' : {
                   'debug'   : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Debug ARM/GameSceneGL.s3e',
                   'release' : r'/Users/deltutto/My_Collider/atlasapp/build_gamescenegl_xcode/build/Release ARM/GameSceneGL.s3e',
                 },
        }
    arm_arch = ''
    assets_original = assets
    assets = assets['Default']

default = DefaultConfig()
