/*
 * Copyright 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>

#include "Texture.h"

namespace android {

Texture::Texture() :
    mTextureName(0), mTextureTarget(TEXTURE_2D),
    mWidth(0), mHeight(0), mFiltering(false) {
    const float m[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
    memcpy(mTextureMatrix, m, sizeof(mTextureMatrix));
}

Texture::Texture(Target textureTarget, uint32_t textureName) :
            mTextureName(textureName), mTextureTarget(textureTarget),
            mWidth(0), mHeight(0), mFiltering(false) {
    const float m[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
    memcpy(mTextureMatrix, m, sizeof(mTextureMatrix));
}

void Texture::init(Target textureTarget, uint32_t textureName) {
    mTextureName = textureName;
    mTextureTarget = textureTarget;
}

Texture::~Texture() {
}


void Texture::setMatrix(float const* matrix) {
    memcpy(mTextureMatrix, matrix, sizeof(mTextureMatrix));
}

void Texture::setFiltering(bool enabled) {
    mFiltering = enabled;
}

void Texture::setDimensions(size_t width, size_t height) {
    mWidth = width;
    mHeight = height;
}

uint32_t Texture::getTextureName() const {
    return mTextureName;
}

uint32_t Texture::getTextureTarget() const {
    return mTextureTarget;
}

float const* Texture::getMatrix() const {
    return mTextureMatrix;
}

bool Texture::getFiltering() const {
    return mFiltering;
}

size_t Texture::getWidth() const {
    return mWidth;
}

size_t Texture::getHeight() const {
    return mHeight;
}

} /* namespace android */