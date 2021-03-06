/*
 * Copyright (C) 2012-2013 Kito Cheng (kito@0xlab.org)
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

#ifndef _LIBELFXX_ELF_SYMBOL_H_
#define _LIBELFXX_ELF_SYMBOL_H_

#include <elf.h>
#include <stdint.h>
#include <stdio.h>
#include <string>

namespace libelfxx {

class ElfSymbol {
  public:
    enum class Type {
      NOTYPE,
      OBJECT,
      FUNCTION,
      SECTION,
      FILE,
      OTHER,
    };
    enum class Bind {
      LOCAL,
      GLOBAL,
      WEAK,
      OTHER,
    };

    ElfSymbol(const std::string &name, Elf32_Sym *sym);
    ElfSymbol(const std::string &name, Elf64_Sym *sym);

    bool isLocal() const;
    bool isGlobal() const;
    bool isWeak() const;
    Bind bind() const;

    bool isNoType() const;
    bool isObject() const;
    bool isFunction() const;
    bool isSection() const;
    bool isFile() const;
    Type type() const;

    uint64_t value() const;
    uint64_t size() const;
    uint8_t info() const;
    uint8_t other() const;
    uint16_t shndx() const;
    const std::string &name() const;
    uint32_t nameIdx() const;

    void print(FILE *fp);
  private:
    std::string _nameStr;
    uint32_t _name;
    uint8_t _info;
    uint8_t _other;
    uint16_t _shndx;
    uint64_t _value;
    uint64_t _size;
    Bind _bind;
    Type _type;
};

};

#endif
