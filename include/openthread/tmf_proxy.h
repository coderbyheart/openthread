/*
 *  Copyright (c) 2017, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief
 *   This file includes the OpenThread API for TMF Proxy feature.
 */

#ifndef OPENTHREAD_TMF_PROXY_H_
#define OPENTHREAD_TMF_PROXY_H_

#include <openthread/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup api-tmf-proxy
 *
 * @brief
 *   This module includes functions for TMF proxy feature.
 *
 *   The functions in this module are available when tmf-proxy feature (`OPENTHREAD_ENABLE_TMF_PROXY`) is enabled.
 *
 * @{
 *
 */

/**
 * This function pointer is called when a TMF packet for host is received.
 *
 * @param[in]  aMessage  A pointer to the CoAP Message.
 * @param[in]  aContext  A pointer to application-specific context.
 *
 */
typedef void (*otTmfProxyStreamHandler)(otMessage *aMessage, uint16_t aLocator, uint16_t aPort,
                                        void *aContext);

/**
 * Start the TMF proxy.
 *
 * @param[in]  aInstance            A pointer to an OpenThread instance.
 * @param[in]  aHandler             A pointer to a function called to deliver TMF packet to host.
 * @param[in]  aContext             A pointer to application-specific context.
 *
 * @retval OT_ERROR_NONE        Successfully started the TMF proxy.
 * @retval OT_ERROR_ALREADY     Border agent proxy has been started before.
 *
 */
otError otTmfProxyStart(otInstance *aInstance, otTmfProxyStreamHandler aHandler, void *aContext);

/**
 * Stop the TMF proxy.
 *
 * @param[in]  aInstance            A pointer to an OpenThread instance.
 *
 * @retval OT_ERROR_NONE        Successfully stopped the TMF proxy.
 * @retval OT_ERROR_ALREADY     Border agent proxy is already stopped.
 *
 */
otError otTmfProxyStop(otInstance *aInstance);

/**
 * Send packet through TMF proxy.
 *
 * @param[in]  aInstance            A pointer to an OpenThread instance.
 * @param[in]  aMessage             A pointer to the CoAP Message.
 * @param[in]  aLocator             Rloc of destination.
 * @param[in]  aPort                Port of destination.
 *
 * @retval OT_ERROR_NONE             Successfully send the message.
 * @retval OT_ERROR_INVALID_STATE    Border agent proxy is not started.
 *
 * @warning No matter the call success or fail, the message is freed.
 *
 */
otError otTmfProxySend(otInstance *aInstance, otMessage *aMessage,
                       uint16_t aLocator, uint16_t aPort);

/**
 * Get the TMF proxy status (enabled/disabled)
 *
 * @param[in]  aInstance            A pointer to an OpenThread instance.
 *
 * @returns The TMF proxy status (true if enabled, false otherwise).
 */
bool otTmfProxyIsEnabled(otInstance *aInstance);

/**
 * @}
 *
 */

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // OPENTHREAD_TMF_PROXY_H_
