#include "../include/mp3.h"

u8 asciiLUT[] = {
/* 0x00 */ 0x00, //
/* 0x01 */ 0x01, // ☺
/* 0x02 */ 0x02, // ☻
/* 0x03 */ 0x03, // ♥
/* 0x04 */ 0x04, // ♦
/* 0x05 */ 0x05, // ♣
/* 0x06 */ 0x06, // ♠
/* 0x07 */ 0x07, //
/* 0x08 */ 0x08, //
/* 0x09 */ 0x09, //
/* 0x0A */ 0x0A, // \n
/* 0x0B */ 0x0B, //
/* 0x0C */ 0x0C, //
/* 0x0D */ 0x0D, //
/* 0x0E */ 0x0E, //
/* 0x0F */ 0x0F, //
/* 0x10 */ 0x10, // ►
/* 0x11 */ 0x11, // ◄
/* 0x12 */ 0x12, // ↕
/* 0x13 */ 0x13, // ‼
/* 0x14 */ 0x14, // ¶
/* 0x15 */ 0x15, // §
/* 0x16 */ 0x16, // ▬
/* 0x17 */ 0x17, // ↨
/* 0x18 */ 0x18, // ↑
/* 0x19 */ 0x19, // ↓
/* 0x1A */ 0x1A, // →
/* 0x1B */ 0x1B, //
/* 0x1C */ 0x1C, // ∟
/* 0x1D */ 0x1D, // ↔
/* 0x1E */ 0x1E, // ▲
/* 0x1F */ 0x1F, // ▼
/* 0x20 */ 0x20, //
/* 0x21 */ 0x21, // !
/* 0x22 */ 0x22, // "
/* 0x23 */ 0x23, // #
/* 0x24 */ 0x24, // $
/* 0x25 */ 0x25, // %
/* 0x26 */ 0x26, // &
/* 0x27 */ 0x27, // '
/* 0x28 */ 0x28, // (
/* 0x29 */ 0x29, // )
/* 0x2A */ 0x2A, // *
/* 0x2B */ 0x2B, // +
/* 0x2C */ 0x2C, // ,
/* 0x2D */ 0x2D, // -
/* 0x2E */ 0x85, // .
/* 0x2F */ 0x2F, // /
/* 0x30 */ 0x30, // 0
/* 0x31 */ 0x31, // 1
/* 0x32 */ 0x32, // 2
/* 0x33 */ 0x33, // 3
/* 0x34 */ 0x34, // 4
/* 0x35 */ 0x35, // 5
/* 0x36 */ 0x36, // 6
/* 0x37 */ 0x37, // 7
/* 0x38 */ 0x38, // 8
/* 0x39 */ 0x39, // 9
/* 0x3A */ 0x3A, // :
/* 0x3B */ 0x3B, // ;
/* 0x3C */ 0x3C, // <
/* 0x3D */ 0x3D, // =
/* 0x3E */ 0x3E, // >
/* 0x3F */ 0x3F, // ?
/* 0x40 */ 0x40, // @
/* 0x41 */ 0x41, // A
/* 0x42 */ 0x42, // B
/* 0x43 */ 0x43, // C
/* 0x44 */ 0x44, // D
/* 0x45 */ 0x45, // E
/* 0x46 */ 0x46, // F
/* 0x47 */ 0x47, // G
/* 0x48 */ 0x48, // H
/* 0x49 */ 0x49, // I
/* 0x4A */ 0x4A, // J
/* 0x4B */ 0x4B, // K
/* 0x4C */ 0x4C, // L
/* 0x4D */ 0x4D, // M
/* 0x4E */ 0x4E, // N
/* 0x4F */ 0x4F, // O
/* 0x50 */ 0x50, // P
/* 0x51 */ 0x51, // Q
/* 0x52 */ 0x52, // R
/* 0x53 */ 0x53, // S
/* 0x54 */ 0x54, // T
/* 0x55 */ 0x55, // U
/* 0x56 */ 0x56, // V
/* 0x57 */ 0x57, // W
/* 0x58 */ 0x58, // X
/* 0x59 */ 0x59, // Y
/* 0x5A */ 0x5A, // Z
/* 0x5B */ 0x5B, // [
/* 0x5C */ 0x5C, // "\"
/* 0x5D */ 0x5D, // ]
/* 0x5E */ 0x5E, // ^
/* 0x5F */ 0x5F, // _
/* 0x60 */ 0x60, // `
/* 0x61 */ 0x61, // a
/* 0x62 */ 0x62, // b
/* 0x63 */ 0x63, // c
/* 0x64 */ 0x64, // d
/* 0x65 */ 0x65, // e
/* 0x66 */ 0x66, // f
/* 0x67 */ 0x67, // g
/* 0x68 */ 0x68, // h
/* 0x69 */ 0x69, // i
/* 0x6A */ 0x6A, // j
/* 0x6B */ 0x6B, // k
/* 0x6C */ 0x6C, // l
/* 0x6D */ 0x6D, // m
/* 0x6E */ 0x6E, // n
/* 0x6F */ 0x6F, // o
/* 0x70 */ 0x70, // p
/* 0x71 */ 0x71, // q
/* 0x72 */ 0x72, // r
/* 0x73 */ 0x73, // s
/* 0x74 */ 0x74, // t
/* 0x75 */ 0x75, // u
/* 0x76 */ 0x76, // v
/* 0x77 */ 0x77, // w
/* 0x78 */ 0x78, // x
/* 0x79 */ 0x79, // y
/* 0x7A */ 0x7A, // z
/* 0x7B */ 0x7B, // {
/* 0x7C */ 0x7C, // |
/* 0x7D */ 0x7D, // }
/* 0x7E */ 0x7E, // ~
/* 0x7F */ 0x7F, //
/* 0x80 */ 0x80, // €
/* 0x81 */ 0x81, // 
/* 0x82 */ 0x82, // ‚
/* 0x83 */ 0x83, // ƒ
/* 0x84 */ 0x84, // „
/* 0x85 */ 0x85, // …
/* 0x86 */ 0x86, // †
/* 0x87 */ 0x87, // ‡
/* 0x88 */ 0x88, // ˆ
/* 0x89 */ 0x89, // ‰
/* 0x8A */ 0x8A, // Š
/* 0x8B */ 0x8B, // ‹
/* 0x8C */ 0x8C, // Œ
/* 0x8D */ 0x8D, // 
/* 0x8E */ 0x8E, // Ž
/* 0x8F */ 0x8F, // 
/* 0x90 */ 0x90, // 
/* 0x91 */ 0x91, // ‘
/* 0x92 */ 0x92, // ’
/* 0x93 */ 0x93, // “
/* 0x94 */ 0x94, // ”
/* 0x95 */ 0xE3, // •
/* 0x96 */ 0x96, // –
/* 0x97 */ 0x97, // —
/* 0x98 */ 0x98, // ˜
/* 0x99 */ 0x99, // ™
/* 0x9A */ 0x9A, // š
/* 0x9B */ 0x9B, // ›
/* 0x9C */ 0x9C, // œ
/* 0x9D */ 0x9D, // 
/* 0x9E */ 0x9E, // ž
/* 0x9F */ 0x9F, // Ÿ
/* 0xA0 */ 0xA0, //  
/* 0xA1 */ 0xA1, // ¡
/* 0xA2 */ 0xA2, // ¢
/* 0xA3 */ 0xA3, // £
/* 0xA4 */ 0xA4, // ¤
/* 0xA5 */ 0xA5, // ¥
/* 0xA6 */ 0xA6, // ¦
/* 0xA7 */ 0xA7, // §
/* 0xA8 */ 0xA8, // ¨
/* 0xA9 */ 0xA9, // ©
/* 0xAA */ 0xAA, // ª
/* 0xAB */ 0xAB, // «
/* 0xAC */ 0xAC, // ¬
/* 0xAD */ 0xAD, // ­
/* 0xAE */ 0xAE, // ®
/* 0xAF */ 0xAF, // ¯
/* 0xB0 */ 0xB0, // °
/* 0xB1 */ 0xB1, // ±
/* 0xB2 */ 0xB2, // ²
/* 0xB3 */ 0xB3, // ³
/* 0xB4 */ 0xB4, // ´
/* 0xB5 */ 0xB5, // µ
/* 0xB6 */ 0xB6, // ¶
/* 0xB7 */ 0xB7, // ·
/* 0xB8 */ 0xB8, // ¸
/* 0xB9 */ 0xB9, // ¹
/* 0xBA */ 0xBA, // º
/* 0xBB */ 0xBB, // »
/* 0xBC */ 0xBC, // ¼
/* 0xBD */ 0xBD, // ½
/* 0xBE */ 0xBE, // ¾
/* 0xBF */ 0xBF, // ¿
/* 0xC0 */ 0xC0, // À
/* 0xC1 */ 0xC1, // Á
/* 0xC2 */ 0xC2, // Â
/* 0xC3 */ 0xC3, // Ã
/* 0xC4 */ 0xC4, // Ä
/* 0xC5 */ 0xC5, // Å
/* 0xC6 */ 0xC6, // Æ
/* 0xC7 */ 0xC7, // Ç
/* 0xC8 */ 0xC8, // È
/* 0xC9 */ 0xC9, // É
/* 0xCA */ 0xCA, // Ê
/* 0xCB */ 0xCB, // Ë
/* 0xCC */ 0xCC, // Ì
/* 0xCD */ 0xCD, // Í
/* 0xCE */ 0xCE, // Î
/* 0xCF */ 0xCF, // Ï
/* 0xD0 */ 0xD0, // Ð
/* 0xD1 */ 0xD1, // Ñ
/* 0xD2 */ 0xD2, // Ò
/* 0xD3 */ 0xD3, // Ó
/* 0xD4 */ 0xD4, // Ô
/* 0xD5 */ 0xD5, // Õ
/* 0xD6 */ 0xD6, // Ö
/* 0xD7 */ 0xD7, // ×
/* 0xD8 */ 0xD8, // Ø
/* 0xD9 */ 0xD9, // Ù
/* 0xDA */ 0xDA, // Ú
/* 0xDB */ 0xDB, // Û
/* 0xDC */ 0xDC, // Ü
/* 0xDD */ 0xDD, // Ý
/* 0xDE */ 0xDE, // Þ
/* 0xDF */ 0xDF, // ß
/* 0xE0 */ 0xE0, // à
/* 0xE1 */ 0xE1, // á
/* 0xE2 */ 0xE2, // â
/* 0xE3 */ 0xE3, // ã
/* 0xE4 */ 0xE4, // ä
/* 0xE5 */ 0xE5, // å
/* 0xE6 */ 0xE6, // æ
/* 0xE7 */ 0xE7, // ç
/* 0xE8 */ 0xE8, // è
/* 0xE9 */ 0xE9, // é
/* 0xEA */ 0xEA, // ê
/* 0xEB */ 0xEB, // ë
/* 0xEC */ 0xEC, // ì
/* 0xED */ 0xED, // í
/* 0xEE */ 0xEE, // î
/* 0xEF */ 0xEF, // ï
/* 0xF0 */ 0xF0, // ð
/* 0xF1 */ 0xF1, // ñ
/* 0xF2 */ 0xF2, // ò
/* 0xF3 */ 0xF3, // ó
/* 0xF4 */ 0xF4, // ô
/* 0xF5 */ 0xF5, // õ
/* 0xF6 */ 0xF6, // ö
/* 0xF7 */ 0xF7, // ÷
/* 0xF8 */ 0xF8, // ø
/* 0xF9 */ 0xF9, // ù
/* 0xFA */ 0xFA, // ú
/* 0xFB */ 0xFB, // û
/* 0xFC */ 0xFC, // ü
/* 0xFD */ 0xFD, // ý
/* 0xFE */ 0xFE, // þ
/* 0xFF */ 0xFF, // ÿ
};