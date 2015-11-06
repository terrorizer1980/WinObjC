//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsSecurityCryptographyCertificates.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSCCCertificate, WSCCCertificateRequestProperties, WSCCUserCertificateEnrollmentManager, WSCCCertificateEnrollmentManager,
    WSCCKeyAttestationHelper, WSCCCertificateQuery, WSCCCertificateStore, WSCCCertificateStores, WSCCKeyAlgorithmNames,
    WSCCKeyStorageProviderNames, WSCCChainBuildingParameters, WSCCChainValidationParameters, WSCCCertificateChain, WSCCCmsTimestampInfo,
    WSCCCmsSignerInfo, WSCCCmsAttachedSignature, WSCCCmsDetachedSignature;
@protocol WSCCICertificateRequestProperties
, WSCCICertificateRequestProperties2, WSCCICertificateEnrollmentManagerStatics, WSCCICertificateEnrollmentManagerStatics2,
    WSCCIKeyAttestationHelperStatics, WSCCICertificateStoresStatics, WSCCIUserCertificateEnrollmentManager, WSCCICertificateStore,
    WSCCIKeyAlgorithmNamesStatics, WSCCIKeyStorageProviderNamesStatics, WSCCIChainBuildingParameters, WSCCIChainValidationParameters,
    WSCCICertificateQuery, WSCCICertificateChain, WSCCICertificate, WSCCICertificateFactory, WSCCICmsTimestampInfo, WSCCICmsSignerInfo,
    WSCCICmsAttachedSignature, WSCCICmsAttachedSignatureFactory, WSCCICmsAttachedSignatureStatics, WSCCICmsDetachedSignature,
    WSCCICmsDetachedSignatureFactory, WSCCICmsDetachedSignatureStatics;

// Windows.Security.Cryptography.Certificates.EnrollKeyUsages
enum _WSCCEnrollKeyUsages {
    WSCCEnrollKeyUsagesNone = 0,
    WSCCEnrollKeyUsagesDecryption = 1,
    WSCCEnrollKeyUsagesSigning = 2,
    WSCCEnrollKeyUsagesKeyAgreement = 4,
    WSCCEnrollKeyUsagesAll = 16777215,
};
typedef unsigned WSCCEnrollKeyUsages;

// Windows.Security.Cryptography.Certificates.KeyProtectionLevel
enum _WSCCKeyProtectionLevel {
    WSCCKeyProtectionLevelNoConsent = 0,
    WSCCKeyProtectionLevelConsentOnly = 1,
    WSCCKeyProtectionLevelConsentWithPassword = 2,
    WSCCKeyProtectionLevelConsentWithFingerprint = 3,
};
typedef unsigned WSCCKeyProtectionLevel;

// Windows.Security.Cryptography.Certificates.ExportOption
enum _WSCCExportOption {
    WSCCExportOptionNotExportable = 0,
    WSCCExportOptionExportable = 1,
};
typedef unsigned WSCCExportOption;

// Windows.Security.Cryptography.Certificates.KeySize
enum _WSCCKeySize {
    WSCCKeySizeInvalid = 0,
    WSCCKeySizeRsa2048 = 2048,
    WSCCKeySizeRsa4096 = 4096,
};
typedef unsigned WSCCKeySize;

// Windows.Security.Cryptography.Certificates.InstallOptions
enum _WSCCInstallOptions {
    WSCCInstallOptionsNone = 0,
    WSCCInstallOptionsDeleteExpired = 1,
};
typedef unsigned WSCCInstallOptions;

// Windows.Security.Cryptography.Certificates.CertificateChainPolicy
enum _WSCCCertificateChainPolicy {
    WSCCCertificateChainPolicyBase = 0,
    WSCCCertificateChainPolicySsl = 1,
    WSCCCertificateChainPolicyNTAuthentication = 2,
    WSCCCertificateChainPolicyMicrosoftRoot = 3,
};
typedef unsigned WSCCCertificateChainPolicy;

// Windows.Security.Cryptography.Certificates.ChainValidationResult
enum _WSCCChainValidationResult {
    WSCCChainValidationResultSuccess = 0,
    WSCCChainValidationResultUntrusted = 1,
    WSCCChainValidationResultRevoked = 2,
    WSCCChainValidationResultExpired = 3,
    WSCCChainValidationResultIncompleteChain = 4,
    WSCCChainValidationResultInvalidSignature = 5,
    WSCCChainValidationResultWrongUsage = 6,
    WSCCChainValidationResultInvalidName = 7,
    WSCCChainValidationResultInvalidCertificateAuthorityPolicy = 8,
    WSCCChainValidationResultBasicConstraintsError = 9,
    WSCCChainValidationResultUnknownCriticalExtension = 10,
    WSCCChainValidationResultRevocationInformationMissing = 11,
    WSCCChainValidationResultRevocationFailure = 12,
    WSCCChainValidationResultOtherErrors = 13,
};
typedef unsigned WSCCChainValidationResult;

// Windows.Security.Cryptography.Certificates.SignatureValidationResult
enum _WSCCSignatureValidationResult {
    WSCCSignatureValidationResultSuccess = 0,
    WSCCSignatureValidationResultInvalidParameter = 1,
    WSCCSignatureValidationResultBadMessage = 2,
    WSCCSignatureValidationResultInvalidSignature = 3,
    WSCCSignatureValidationResultOtherErrors = 4,
};
typedef unsigned WSCCSignatureValidationResult;

#include "WindowsNetworking.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

// Windows.Security.Cryptography.Certificates.Certificate
#ifndef __WSCCCertificate_DEFINED__
#define __WSCCCertificate_DEFINED__

WINRT_EXPORT
@interface WSCCCertificate : RTObject
+ (WSCCCertificate*)createCertificate:(RTObject<WSSIBuffer>*)certBlob ACTIVATOR;
@property (copy) NSString* friendlyName;
@property (readonly) id<NSFastEnumeration> /*String*/ enhancedKeyUsages;
@property (readonly) BOOL hasPrivateKey;
@property (readonly) BOOL isStronglyProtected;
@property (readonly) NSString* issuer;
@property (readonly) id<NSFastEnumeration> /*UInt8*/ serialNumber;
@property (readonly) NSString* subject;
@property (readonly) WFDateTime* validFrom;
@property (readonly) WFDateTime* validTo;
- (void)buildChainAsync:(id<NSFastEnumeration> /*WSCCCertificate*/)certificates
                success:(void (^)(WSCCCertificateChain*))success
                failure:(void (^)(NSError*))failure;
- (void)buildChainWithParametersAsync:(id<NSFastEnumeration> /*WSCCCertificate*/)certificates
                           parameters:(WSCCChainBuildingParameters*)parameters
                              success:(void (^)(WSCCCertificateChain*))success
                              failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*UInt8*/)getHashValue;
- (id<NSFastEnumeration> /*UInt8*/)getHashValueWithAlgorithm:(NSString*)hashAlgorithmName;
- (RTObject<WSSIBuffer>*)getCertificateBlob;
@end

#endif // __WSCCCertificate_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateRequestProperties
#ifndef __WSCCCertificateRequestProperties_DEFINED__
#define __WSCCCertificateRequestProperties_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateRequestProperties : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* subject;
@property WSCCEnrollKeyUsages keyUsages;
@property (copy) NSString* keyStorageProviderName;
@property unsigned keySize;
@property WSCCKeyProtectionLevel keyProtectionLevel;
@property (copy) NSString* keyAlgorithmName;
@property (copy) NSString* hashAlgorithmName;
@property (copy) NSString* friendlyName;
@property WSCCExportOption exportable;
@property (copy) NSString* smartcardReaderName;
@property (copy) WSCCCertificate* signingCertificate;
@property (copy) WSCCCertificate* attestationCredentialCertificate;
@end

#endif // __WSCCCertificateRequestProperties_DEFINED__

// Windows.Security.Cryptography.Certificates.UserCertificateEnrollmentManager
#ifndef __WSCCUserCertificateEnrollmentManager_DEFINED__
#define __WSCCUserCertificateEnrollmentManager_DEFINED__

WINRT_EXPORT
@interface WSCCUserCertificateEnrollmentManager : RTObject
- (void)createRequestAsync:(WSCCCertificateRequestProperties*)request
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)installCertificateAsync:(NSString*)certificate installOption:(WSCCInstallOptions)installOption;
- (RTObject<WFIAsyncAction>*)importPfxDataAsync:(NSString*)pfxData
                                       password:(NSString*)password
                                     exportable:(WSCCExportOption)exportable
                             keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                  installOption:(WSCCInstallOptions)installOption
                                   friendlyName:(NSString*)friendlyName;
- (RTObject<WFIAsyncAction>*)importPfxDataToKspAsync:(NSString*)pfxData
                                            password:(NSString*)password
                                          exportable:(WSCCExportOption)exportable
                                  keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                       installOption:(WSCCInstallOptions)installOption
                                        friendlyName:(NSString*)friendlyName
                                  keyStorageProvider:(NSString*)keyStorageProvider;
@end

#endif // __WSCCUserCertificateEnrollmentManager_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateEnrollmentManager
#ifndef __WSCCCertificateEnrollmentManager_DEFINED__
#define __WSCCCertificateEnrollmentManager_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateEnrollmentManager : RTObject
+ (void)createRequestAsync:(WSCCCertificateRequestProperties*)request
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)installCertificateAsync:(NSString*)certificate installOption:(WSCCInstallOptions)installOption;
+ (RTObject<WFIAsyncAction>*)importPfxDataAsync:(NSString*)pfxData
                                       password:(NSString*)password
                                     exportable:(WSCCExportOption)exportable
                             keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                  installOption:(WSCCInstallOptions)installOption
                                   friendlyName:(NSString*)friendlyName;
+ (RTObject<WFIAsyncAction>*)importPfxDataToKspAsync:(NSString*)pfxData
                                            password:(NSString*)password
                                          exportable:(WSCCExportOption)exportable
                                  keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                       installOption:(WSCCInstallOptions)installOption
                                        friendlyName:(NSString*)friendlyName
                                  keyStorageProvider:(NSString*)keyStorageProvider;
+ (WSCCUserCertificateEnrollmentManager*)userCertificateEnrollmentManager;
@end

#endif // __WSCCCertificateEnrollmentManager_DEFINED__

// Windows.Security.Cryptography.Certificates.KeyAttestationHelper
#ifndef __WSCCKeyAttestationHelper_DEFINED__
#define __WSCCKeyAttestationHelper_DEFINED__

WINRT_EXPORT
@interface WSCCKeyAttestationHelper : RTObject
+ (void)decryptTpmAttestationCredentialAsync:(NSString*)credential success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getTpmAttestationCredentialId:(NSString*)credential;
@end

#endif // __WSCCKeyAttestationHelper_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateQuery
#ifndef __WSCCCertificateQuery_DEFINED__
#define __WSCCCertificateQuery_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateQuery : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id<NSFastEnumeration> /*UInt8*/ thumbprint;
@property (copy) NSString* issuerName;
@property BOOL hardwareOnly;
@property (copy) NSString* friendlyName;
@property (readonly) id<NSFastEnumeration> /*String*/ enhancedKeyUsages;
@end

#endif // __WSCCCertificateQuery_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateStore
#ifndef __WSCCCertificateStore_DEFINED__
#define __WSCCCertificateStore_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateStore : RTObject
- (void)add:(WSCCCertificate*)certificate;
- (void)Delete:(WSCCCertificate*)certificate;
@end

#endif // __WSCCCertificateStore_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateStores
#ifndef __WSCCCertificateStores_DEFINED__
#define __WSCCCertificateStores_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateStores : RTObject
+ (void)findAllAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WSCCCertificate*/))success failure:(void (^)(NSError*))failure;
+ (void)findAllWithQueryAsync:(WSCCCertificateQuery*)query
                      success:(void (^)(id<NSFastEnumeration> /*WSCCCertificate*/))success
                      failure:(void (^)(NSError*))failure;
+ (WSCCCertificateStore*)getStoreByName:(NSString*)storeName;
+ (WSCCCertificateStore*)intermediateCertificationAuthorities;
+ (WSCCCertificateStore*)trustedRootCertificationAuthorities;
@end

#endif // __WSCCCertificateStores_DEFINED__

// Windows.Security.Cryptography.Certificates.KeyAlgorithmNames
#ifndef __WSCCKeyAlgorithmNames_DEFINED__
#define __WSCCKeyAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCKeyAlgorithmNames : RTObject
+ (NSString*)dsa;
+ (NSString*)ecdh256;
+ (NSString*)ecdh384;
+ (NSString*)ecdh521;
+ (NSString*)ecdsa256;
+ (NSString*)ecdsa384;
+ (NSString*)ecdsa521;
+ (NSString*)rsa;
@end

#endif // __WSCCKeyAlgorithmNames_DEFINED__

// Windows.Security.Cryptography.Certificates.KeyStorageProviderNames
#ifndef __WSCCKeyStorageProviderNames_DEFINED__
#define __WSCCKeyStorageProviderNames_DEFINED__

WINRT_EXPORT
@interface WSCCKeyStorageProviderNames : RTObject
+ (NSString*)platformKeyStorageProvider;
+ (NSString*)smartcardKeyStorageProvider;
+ (NSString*)softwareKeyStorageProvider;
@end

#endif // __WSCCKeyStorageProviderNames_DEFINED__

// Windows.Security.Cryptography.Certificates.ChainBuildingParameters
#ifndef __WSCCChainBuildingParameters_DEFINED__
#define __WSCCChainBuildingParameters_DEFINED__

WINRT_EXPORT
@interface WSCCChainBuildingParameters : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFDateTime* validationTimestamp;
@property BOOL revocationCheckEnabled;
@property BOOL networkRetrievalEnabled;
@property BOOL currentTimeValidationEnabled;
@property BOOL authorityInformationAccessEnabled;
@property (readonly) id<NSFastEnumeration> /*String*/ enhancedKeyUsages;
@property (readonly) id<NSFastEnumeration> /*WSCCCertificate*/ exclusiveTrustRoots;
@end

#endif // __WSCCChainBuildingParameters_DEFINED__

// Windows.Security.Cryptography.Certificates.ChainValidationParameters
#ifndef __WSCCChainValidationParameters_DEFINED__
#define __WSCCChainValidationParameters_DEFINED__

WINRT_EXPORT
@interface WSCCChainValidationParameters : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WNHostName* serverDnsName;
@property WSCCCertificateChainPolicy certificateChainPolicy;
@end

#endif // __WSCCChainValidationParameters_DEFINED__

// Windows.Security.Cryptography.Certificates.CertificateChain
#ifndef __WSCCCertificateChain_DEFINED__
#define __WSCCCertificateChain_DEFINED__

WINRT_EXPORT
@interface WSCCCertificateChain : RTObject
- (WSCCChainValidationResult)validate;
- (WSCCChainValidationResult)validateWithParameters:(WSCCChainValidationParameters*)parameter;
- (id<NSFastEnumeration> /*WSCCCertificate*/)getCertificates:(BOOL)includeRoot;
@end

#endif // __WSCCCertificateChain_DEFINED__

// Windows.Security.Cryptography.Certificates.CmsTimestampInfo
#ifndef __WSCCCmsTimestampInfo_DEFINED__
#define __WSCCCmsTimestampInfo_DEFINED__

WINRT_EXPORT
@interface WSCCCmsTimestampInfo : RTObject
@property (readonly) id<NSFastEnumeration> /*WSCCCertificate*/ certificates;
@property (readonly) WSCCCertificate* signingCertificate;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WSCCCmsTimestampInfo_DEFINED__

// Windows.Security.Cryptography.Certificates.CmsSignerInfo
#ifndef __WSCCCmsSignerInfo_DEFINED__
#define __WSCCCmsSignerInfo_DEFINED__

WINRT_EXPORT
@interface WSCCCmsSignerInfo : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* hashAlgorithmName;
@property (copy) WSCCCertificate* certificate;
@property (readonly) WSCCCmsTimestampInfo* timestampInfo;
@end

#endif // __WSCCCmsSignerInfo_DEFINED__

// Windows.Security.Cryptography.Certificates.CmsAttachedSignature
#ifndef __WSCCCmsAttachedSignature_DEFINED__
#define __WSCCCmsAttachedSignature_DEFINED__

WINRT_EXPORT
@interface WSCCCmsAttachedSignature : RTObject
+ (void)generateSignatureAsync:(RTObject<WSSIBuffer>*)data
                       signers:(id<NSFastEnumeration> /*WSCCCmsSignerInfo*/)signers
                  certificates:(id<NSFastEnumeration> /*WSCCCertificate*/)certificates
                       success:(void (^)(RTObject<WSSIBuffer>*))success
                       failure:(void (^)(NSError*))failure;
+ (WSCCCmsAttachedSignature*)createCmsAttachedSignature:(RTObject<WSSIBuffer>*)inputBlob ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WSCCCertificate*/ certificates;
@property (readonly) id<NSFastEnumeration> /*UInt8*/ content;
@property (readonly) id<NSFastEnumeration> /*WSCCCmsSignerInfo*/ signers;
- (WSCCSignatureValidationResult)verifySignature;
@end

#endif // __WSCCCmsAttachedSignature_DEFINED__

// Windows.Security.Cryptography.Certificates.CmsDetachedSignature
#ifndef __WSCCCmsDetachedSignature_DEFINED__
#define __WSCCCmsDetachedSignature_DEFINED__

WINRT_EXPORT
@interface WSCCCmsDetachedSignature : RTObject
+ (void)generateSignatureAsync:(RTObject<WSSIInputStream>*)data
                       signers:(id<NSFastEnumeration> /*WSCCCmsSignerInfo*/)signers
                  certificates:(id<NSFastEnumeration> /*WSCCCertificate*/)certificates
                       success:(void (^)(RTObject<WSSIBuffer>*))success
                       failure:(void (^)(NSError*))failure;
+ (WSCCCmsDetachedSignature*)createCmsDetachedSignature:(RTObject<WSSIBuffer>*)inputBlob ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WSCCCertificate*/ certificates;
@property (readonly) id<NSFastEnumeration> /*WSCCCmsSignerInfo*/ signers;
- (void)verifySignatureAsync:(RTObject<WSSIInputStream>*)data
                     success:(void (^)(WSCCSignatureValidationResult))success
                     failure:(void (^)(NSError*))failure;
@end

#endif // __WSCCCmsDetachedSignature_DEFINED__
