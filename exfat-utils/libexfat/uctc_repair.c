/*

	Hisilicon exFAT implementation.
	Copyright (C) HUAWEI

*/

#include "uctc_repair.h"

uint8_t upcase_table_r[5836] =
{
	0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00,
	0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
	0x08, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0b, 0x00,
	0x0c, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x0f, 0x00,
	0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00,
	0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00,
	0x18, 0x00, 0x19, 0x00, 0x1a, 0x00, 0x1b, 0x00,
	0x1c, 0x00, 0x1d, 0x00, 0x1e, 0x00, 0x1f, 0x00,
	0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x23, 0x00,
	0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00,
	0x28, 0x00, 0x29, 0x00, 0x2a, 0x00, 0x2b, 0x00,
	0x2c, 0x00, 0x2d, 0x00, 0x2e, 0x00, 0x2f, 0x00,
	0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x33, 0x00,
	0x34, 0x00, 0x35, 0x00, 0x36, 0x00, 0x37, 0x00,
	0x38, 0x00, 0x39, 0x00, 0x3a, 0x00, 0x3b, 0x00,
	0x3c, 0x00, 0x3d, 0x00, 0x3e, 0x00, 0x3f, 0x00,
	0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00,
	0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00,
	0x48, 0x00, 0x49, 0x00, 0x4a, 0x00, 0x4b, 0x00,
	0x4c, 0x00, 0x4d, 0x00, 0x4e, 0x00, 0x4f, 0x00,
	0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00,
	0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00,
	0x58, 0x00, 0x59, 0x00, 0x5a, 0x00, 0x5b, 0x00,
	0x5c, 0x00, 0x5d, 0x00, 0x5e, 0x00, 0x5f, 0x00,
	0x60, 0x00, 0x41, 0x00, 0x42, 0x00, 0x43, 0x00,
	0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x47, 0x00,
	0x48, 0x00, 0x49, 0x00, 0x4a, 0x00, 0x4b, 0x00,
	0x4c, 0x00, 0x4d, 0x00, 0x4e, 0x00, 0x4f, 0x00,
	0x50, 0x00, 0x51, 0x00, 0x52, 0x00, 0x53, 0x00,
	0x54, 0x00, 0x55, 0x00, 0x56, 0x00, 0x57, 0x00,
	0x58, 0x00, 0x59, 0x00, 0x5a, 0x00, 0x7b, 0x00,
	0x7c, 0x00, 0x7d, 0x00, 0x7e, 0x00, 0x7f, 0x00,
	0x80, 0x00, 0x81, 0x00, 0x82, 0x00, 0x83, 0x00,
	0x84, 0x00, 0x85, 0x00, 0x86, 0x00, 0x87, 0x00,
	0x88, 0x00, 0x89, 0x00, 0x8a, 0x00, 0x8b, 0x00,
	0x8c, 0x00, 0x8d, 0x00, 0x8e, 0x00, 0x8f, 0x00,
	0x90, 0x00, 0x91, 0x00, 0x92, 0x00, 0x93, 0x00,
	0x94, 0x00, 0x95, 0x00, 0x96, 0x00, 0x97, 0x00,
	0x98, 0x00, 0x99, 0x00, 0x9a, 0x00, 0x9b, 0x00,
	0x9c, 0x00, 0x9d, 0x00, 0x9e, 0x00, 0x9f, 0x00,
	0xa0, 0x00, 0xa1, 0x00, 0xa2, 0x00, 0xa3, 0x00,
	0xa4, 0x00, 0xa5, 0x00, 0xa6, 0x00, 0xa7, 0x00,
	0xa8, 0x00, 0xa9, 0x00, 0xaa, 0x00, 0xab, 0x00,
	0xac, 0x00, 0xad, 0x00, 0xae, 0x00, 0xaf, 0x00,
	0xb0, 0x00, 0xb1, 0x00, 0xb2, 0x00, 0xb3, 0x00,
	0xb4, 0x00, 0xb5, 0x00, 0xb6, 0x00, 0xb7, 0x00,
	0xb8, 0x00, 0xb9, 0x00, 0xba, 0x00, 0xbb, 0x00,
	0xbc, 0x00, 0xbd, 0x00, 0xbe, 0x00, 0xbf, 0x00,
	0xc0, 0x00, 0xc1, 0x00, 0xc2, 0x00, 0xc3, 0x00,
	0xc4, 0x00, 0xc5, 0x00, 0xc6, 0x00, 0xc7, 0x00,
	0xc8, 0x00, 0xc9, 0x00, 0xca, 0x00, 0xcb, 0x00,
	0xcc, 0x00, 0xcd, 0x00, 0xce, 0x00, 0xcf, 0x00,
	0xd0, 0x00, 0xd1, 0x00, 0xd2, 0x00, 0xd3, 0x00,
	0xd4, 0x00, 0xd5, 0x00, 0xd6, 0x00, 0xd7, 0x00,
	0xd8, 0x00, 0xd9, 0x00, 0xda, 0x00, 0xdb, 0x00,
	0xdc, 0x00, 0xdd, 0x00, 0xde, 0x00, 0xdf, 0x00,
	0xc0, 0x00, 0xc1, 0x00, 0xc2, 0x00, 0xc3, 0x00,
	0xc4, 0x00, 0xc5, 0x00, 0xc6, 0x00, 0xc7, 0x00,
	0xc8, 0x00, 0xc9, 0x00, 0xca, 0x00, 0xcb, 0x00,
	0xcc, 0x00, 0xcd, 0x00, 0xce, 0x00, 0xcf, 0x00,
	0xd0, 0x00, 0xd1, 0x00, 0xd2, 0x00, 0xd3, 0x00,
	0xd4, 0x00, 0xd5, 0x00, 0xd6, 0x00, 0xf7, 0x00,
	0xd8, 0x00, 0xd9, 0x00, 0xda, 0x00, 0xdb, 0x00,
	0xdc, 0x00, 0xdd, 0x00, 0xde, 0x00, 0x78, 0x01,
	0x00, 0x01, 0x00, 0x01, 0x02, 0x01, 0x02, 0x01,
	0x04, 0x01, 0x04, 0x01, 0x06, 0x01, 0x06, 0x01,
	0x08, 0x01, 0x08, 0x01, 0x0a, 0x01, 0x0a, 0x01,
	0x0c, 0x01, 0x0c, 0x01, 0x0e, 0x01, 0x0e, 0x01,
	0x10, 0x01, 0x10, 0x01, 0x12, 0x01, 0x12, 0x01,
	0x14, 0x01, 0x14, 0x01, 0x16, 0x01, 0x16, 0x01,
	0x18, 0x01, 0x18, 0x01, 0x1a, 0x01, 0x1a, 0x01,
	0x1c, 0x01, 0x1c, 0x01, 0x1e, 0x01, 0x1e, 0x01,
	0x20, 0x01, 0x20, 0x01, 0x22, 0x01, 0x22, 0x01,
	0x24, 0x01, 0x24, 0x01, 0x26, 0x01, 0x26, 0x01,
	0x28, 0x01, 0x28, 0x01, 0x2a, 0x01, 0x2a, 0x01,
	0x2c, 0x01, 0x2c, 0x01, 0x2e, 0x01, 0x2e, 0x01,
	0x30, 0x01, 0x31, 0x01, 0x32, 0x01, 0x32, 0x01,
	0x34, 0x01, 0x34, 0x01, 0x36, 0x01, 0x36, 0x01,
	0x38, 0x01, 0x39, 0x01, 0x39, 0x01, 0x3b, 0x01,
	0x3b, 0x01, 0x3d, 0x01, 0x3d, 0x01, 0x3f, 0x01,
	0x3f, 0x01, 0x41, 0x01, 0x41, 0x01, 0x43, 0x01,
	0x43, 0x01, 0x45, 0x01, 0x45, 0x01, 0x47, 0x01,
	0x47, 0x01, 0x49, 0x01, 0x4a, 0x01, 0x4a, 0x01,
	0x4c, 0x01, 0x4c, 0x01, 0x4e, 0x01, 0x4e, 0x01,
	0x50, 0x01, 0x50, 0x01, 0x52, 0x01, 0x52, 0x01,
	0x54, 0x01, 0x54, 0x01, 0x56, 0x01, 0x56, 0x01,
	0x58, 0x01, 0x58, 0x01, 0x5a, 0x01, 0x5a, 0x01,
	0x5c, 0x01, 0x5c, 0x01, 0x5e, 0x01, 0x5e, 0x01,
	0x60, 0x01, 0x60, 0x01, 0x62, 0x01, 0x62, 0x01,
	0x64, 0x01, 0x64, 0x01, 0x66, 0x01, 0x66, 0x01,
	0x68, 0x01, 0x68, 0x01, 0x6a, 0x01, 0x6a, 0x01,
	0x6c, 0x01, 0x6c, 0x01, 0x6e, 0x01, 0x6e, 0x01,
	0x70, 0x01, 0x70, 0x01, 0x72, 0x01, 0x72, 0x01,
	0x74, 0x01, 0x74, 0x01, 0x76, 0x01, 0x76, 0x01,
	0x78, 0x01, 0x79, 0x01, 0x79, 0x01, 0x7b, 0x01,
	0x7b, 0x01, 0x7d, 0x01, 0x7d, 0x01, 0x7f, 0x01,
	0x43, 0x02, 0x81, 0x01, 0x82, 0x01, 0x82, 0x01,
	0x84, 0x01, 0x84, 0x01, 0x86, 0x01, 0x87, 0x01,
	0x87, 0x01, 0x89, 0x01, 0x8a, 0x01, 0x8b, 0x01,
	0x8b, 0x01, 0x8d, 0x01, 0x8e, 0x01, 0x8f, 0x01,
	0x90, 0x01, 0x91, 0x01, 0x91, 0x01, 0x93, 0x01,
	0x94, 0x01, 0xf6, 0x01, 0x96, 0x01, 0x97, 0x01,
	0x98, 0x01, 0x98, 0x01, 0x3d, 0x02, 0x9b, 0x01,
	0x9c, 0x01, 0x9d, 0x01, 0x20, 0x02, 0x9f, 0x01,
	0xa0, 0x01, 0xa0, 0x01, 0xa2, 0x01, 0xa2, 0x01,
	0xa4, 0x01, 0xa4, 0x01, 0xa6, 0x01, 0xa7, 0x01,
	0xa7, 0x01, 0xa9, 0x01, 0xaa, 0x01, 0xab, 0x01,
	0xac, 0x01, 0xac, 0x01, 0xae, 0x01, 0xaf, 0x01,
	0xaf, 0x01, 0xb1, 0x01, 0xb2, 0x01, 0xb3, 0x01,
	0xb3, 0x01, 0xb5, 0x01, 0xb5, 0x01, 0xb7, 0x01,
	0xb8, 0x01, 0xb8, 0x01, 0xba, 0x01, 0xbb, 0x01,
	0xbc, 0x01, 0xbc, 0x01, 0xbe, 0x01, 0xf7, 0x01,
	0xc0, 0x01, 0xc1, 0x01, 0xc2, 0x01, 0xc3, 0x01,
	0xc4, 0x01, 0xc5, 0x01, 0xc4, 0x01, 0xc7, 0x01,
	0xc8, 0x01, 0xc7, 0x01, 0xca, 0x01, 0xcb, 0x01,
	0xca, 0x01, 0xcd, 0x01, 0xcd, 0x01, 0xcf, 0x01,
	0xcf, 0x01, 0xd1, 0x01, 0xd1, 0x01, 0xd3, 0x01,
	0xd3, 0x01, 0xd5, 0x01, 0xd5, 0x01, 0xd7, 0x01,
	0xd7, 0x01, 0xd9, 0x01, 0xd9, 0x01, 0xdb, 0x01,
	0xdb, 0x01, 0x8e, 0x01, 0xde, 0x01, 0xde, 0x01,
	0xe0, 0x01, 0xe0, 0x01, 0xe2, 0x01, 0xe2, 0x01,
	0xe4, 0x01, 0xe4, 0x01, 0xe6, 0x01, 0xe6, 0x01,
	0xe8, 0x01, 0xe8, 0x01, 0xea, 0x01, 0xea, 0x01,
	0xec, 0x01, 0xec, 0x01, 0xee, 0x01, 0xee, 0x01,
	0xf0, 0x01, 0xf1, 0x01, 0xf2, 0x01, 0xf1, 0x01,
	0xf4, 0x01, 0xf4, 0x01, 0xf6, 0x01, 0xf7, 0x01,
	0xf8, 0x01, 0xf8, 0x01, 0xfa, 0x01, 0xfa, 0x01,
	0xfc, 0x01, 0xfc, 0x01, 0xfe, 0x01, 0xfe, 0x01,
	0x00, 0x02, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x04, 0x02, 0x04, 0x02, 0x06, 0x02, 0x06, 0x02,
	0x08, 0x02, 0x08, 0x02, 0x0a, 0x02, 0x0a, 0x02,
	0x0c, 0x02, 0x0c, 0x02, 0x0e, 0x02, 0x0e, 0x02,
	0x10, 0x02, 0x10, 0x02, 0x12, 0x02, 0x12, 0x02,
	0x14, 0x02, 0x14, 0x02, 0x16, 0x02, 0x16, 0x02,
	0x18, 0x02, 0x18, 0x02, 0x1a, 0x02, 0x1a, 0x02,
	0x1c, 0x02, 0x1c, 0x02, 0x1e, 0x02, 0x1e, 0x02,
	0x20, 0x02, 0x21, 0x02, 0x22, 0x02, 0x22, 0x02,
	0x24, 0x02, 0x24, 0x02, 0x26, 0x02, 0x26, 0x02,
	0x28, 0x02, 0x28, 0x02, 0x2a, 0x02, 0x2a, 0x02,
	0x2c, 0x02, 0x2c, 0x02, 0x2e, 0x02, 0x2e, 0x02,
	0x30, 0x02, 0x30, 0x02, 0x32, 0x02, 0x32, 0x02,
	0x34, 0x02, 0x35, 0x02, 0x36, 0x02, 0x37, 0x02,
	0x38, 0x02, 0x39, 0x02, 0x65, 0x2c, 0x3b, 0x02,
	0x3b, 0x02, 0x3d, 0x02, 0x66, 0x2c, 0x3f, 0x02,
	0x40, 0x02, 0x41, 0x02, 0x41, 0x02, 0x43, 0x02,
	0x44, 0x02, 0x45, 0x02, 0x46, 0x02, 0x46, 0x02,
	0x48, 0x02, 0x48, 0x02, 0x4a, 0x02, 0x4a, 0x02,
	0x4c, 0x02, 0x4c, 0x02, 0x4e, 0x02, 0x4e, 0x02,
	0x50, 0x02, 0x51, 0x02, 0x52, 0x02, 0x81, 0x01,
	0x86, 0x01, 0x55, 0x02, 0x89, 0x01, 0x8a, 0x01,
	0x58, 0x02, 0x8f, 0x01, 0x5a, 0x02, 0x90, 0x01,
	0x5c, 0x02, 0x5d, 0x02, 0x5e, 0x02, 0x5f, 0x02,
	0x93, 0x01, 0x61, 0x02, 0x62, 0x02, 0x94, 0x01,
	0x64, 0x02, 0x65, 0x02, 0x66, 0x02, 0x67, 0x02,
	0x97, 0x01, 0x96, 0x01, 0x6a, 0x02, 0x62, 0x2c,
	0x6c, 0x02, 0x6d, 0x02, 0x6e, 0x02, 0x9c, 0x01,
	0x70, 0x02, 0x71, 0x02, 0x9d, 0x01, 0x73, 0x02,
	0x74, 0x02, 0x9f, 0x01, 0x76, 0x02, 0x77, 0x02,
	0x78, 0x02, 0x79, 0x02, 0x7a, 0x02, 0x7b, 0x02,
	0x7c, 0x02, 0x64, 0x2c, 0x7e, 0x02, 0x7f, 0x02,
	0xa6, 0x01, 0x81, 0x02, 0x82, 0x02, 0xa9, 0x01,
	0x84, 0x02, 0x85, 0x02, 0x86, 0x02, 0x87, 0x02,
	0xae, 0x01, 0x44, 0x02, 0xb1, 0x01, 0xb2, 0x01,
	0x45, 0x02, 0x8d, 0x02, 0x8e, 0x02, 0x8f, 0x02,
	0x90, 0x02, 0x91, 0x02, 0xb7, 0x01, 0x93, 0x02,
	0x94, 0x02, 0x95, 0x02, 0x96, 0x02, 0x97, 0x02,
	0x98, 0x02, 0x99, 0x02, 0x9a, 0x02, 0x9b, 0x02,
	0x9c, 0x02, 0x9d, 0x02, 0x9e, 0x02, 0x9f, 0x02,
	0xa0, 0x02, 0xa1, 0x02, 0xa2, 0x02, 0xa3, 0x02,
	0xa4, 0x02, 0xa5, 0x02, 0xa6, 0x02, 0xa7, 0x02,
	0xa8, 0x02, 0xa9, 0x02, 0xaa, 0x02, 0xab, 0x02,
	0xac, 0x02, 0xad, 0x02, 0xae, 0x02, 0xaf, 0x02,
	0xb0, 0x02, 0xb1, 0x02, 0xb2, 0x02, 0xb3, 0x02,
	0xb4, 0x02, 0xb5, 0x02, 0xb6, 0x02, 0xb7, 0x02,
	0xb8, 0x02, 0xb9, 0x02, 0xba, 0x02, 0xbb, 0x02,
	0xbc, 0x02, 0xbd, 0x02, 0xbe, 0x02, 0xbf, 0x02,
	0xc0, 0x02, 0xc1, 0x02, 0xc2, 0x02, 0xc3, 0x02,
	0xc4, 0x02, 0xc5, 0x02, 0xc6, 0x02, 0xc7, 0x02,
	0xc8, 0x02, 0xc9, 0x02, 0xca, 0x02, 0xcb, 0x02,
	0xcc, 0x02, 0xcd, 0x02, 0xce, 0x02, 0xcf, 0x02,
	0xd0, 0x02, 0xd1, 0x02, 0xd2, 0x02, 0xd3, 0x02,
	0xd4, 0x02, 0xd5, 0x02, 0xd6, 0x02, 0xd7, 0x02,
	0xd8, 0x02, 0xd9, 0x02, 0xda, 0x02, 0xdb, 0x02,
	0xdc, 0x02, 0xdd, 0x02, 0xde, 0x02, 0xdf, 0x02,
	0xe0, 0x02, 0xe1, 0x02, 0xe2, 0x02, 0xe3, 0x02,
	0xe4, 0x02, 0xe5, 0x02, 0xe6, 0x02, 0xe7, 0x02,
	0xe8, 0x02, 0xe9, 0x02, 0xea, 0x02, 0xeb, 0x02,
	0xec, 0x02, 0xed, 0x02, 0xee, 0x02, 0xef, 0x02,
	0xf0, 0x02, 0xf1, 0x02, 0xf2, 0x02, 0xf3, 0x02,
	0xf4, 0x02, 0xf5, 0x02, 0xf6, 0x02, 0xf7, 0x02,
	0xf8, 0x02, 0xf9, 0x02, 0xfa, 0x02, 0xfb, 0x02,
	0xfc, 0x02, 0xfd, 0x02, 0xfe, 0x02, 0xff, 0x02,
	0x00, 0x03, 0x01, 0x03, 0x02, 0x03, 0x03, 0x03,
	0x04, 0x03, 0x05, 0x03, 0x06, 0x03, 0x07, 0x03,
	0x08, 0x03, 0x09, 0x03, 0x0a, 0x03, 0x0b, 0x03,
	0x0c, 0x03, 0x0d, 0x03, 0x0e, 0x03, 0x0f, 0x03,
	0x10, 0x03, 0x11, 0x03, 0x12, 0x03, 0x13, 0x03,
	0x14, 0x03, 0x15, 0x03, 0x16, 0x03, 0x17, 0x03,
	0x18, 0x03, 0x19, 0x03, 0x1a, 0x03, 0x1b, 0x03,
	0x1c, 0x03, 0x1d, 0x03, 0x1e, 0x03, 0x1f, 0x03,
	0x20, 0x03, 0x21, 0x03, 0x22, 0x03, 0x23, 0x03,
	0x24, 0x03, 0x25, 0x03, 0x26, 0x03, 0x27, 0x03,
	0x28, 0x03, 0x29, 0x03, 0x2a, 0x03, 0x2b, 0x03,
	0x2c, 0x03, 0x2d, 0x03, 0x2e, 0x03, 0x2f, 0x03,
	0x30, 0x03, 0x31, 0x03, 0x32, 0x03, 0x33, 0x03,
	0x34, 0x03, 0x35, 0x03, 0x36, 0x03, 0x37, 0x03,
	0x38, 0x03, 0x39, 0x03, 0x3a, 0x03, 0x3b, 0x03,
	0x3c, 0x03, 0x3d, 0x03, 0x3e, 0x03, 0x3f, 0x03,
	0x40, 0x03, 0x41, 0x03, 0x42, 0x03, 0x43, 0x03,
	0x44, 0x03, 0x45, 0x03, 0x46, 0x03, 0x47, 0x03,
	0x48, 0x03, 0x49, 0x03, 0x4a, 0x03, 0x4b, 0x03,
	0x4c, 0x03, 0x4d, 0x03, 0x4e, 0x03, 0x4f, 0x03,
	0x50, 0x03, 0x51, 0x03, 0x52, 0x03, 0x53, 0x03,
	0x54, 0x03, 0x55, 0x03, 0x56, 0x03, 0x57, 0x03,
	0x58, 0x03, 0x59, 0x03, 0x5a, 0x03, 0x5b, 0x03,
	0x5c, 0x03, 0x5d, 0x03, 0x5e, 0x03, 0x5f, 0x03,
	0x60, 0x03, 0x61, 0x03, 0x62, 0x03, 0x63, 0x03,
	0x64, 0x03, 0x65, 0x03, 0x66, 0x03, 0x67, 0x03,
	0x68, 0x03, 0x69, 0x03, 0x6a, 0x03, 0x6b, 0x03,
	0x6c, 0x03, 0x6d, 0x03, 0x6e, 0x03, 0x6f, 0x03,
	0x70, 0x03, 0x71, 0x03, 0x72, 0x03, 0x73, 0x03,
	0x74, 0x03, 0x75, 0x03, 0x76, 0x03, 0x77, 0x03,
	0x78, 0x03, 0x79, 0x03, 0x7a, 0x03, 0xfd, 0x03,
	0xfe, 0x03, 0xff, 0x03, 0x7e, 0x03, 0x7f, 0x03,
	0x80, 0x03, 0x81, 0x03, 0x82, 0x03, 0x83, 0x03,
	0x84, 0x03, 0x85, 0x03, 0x86, 0x03, 0x87, 0x03,
	0x88, 0x03, 0x89, 0x03, 0x8a, 0x03, 0x8b, 0x03,
	0x8c, 0x03, 0x8d, 0x03, 0x8e, 0x03, 0x8f, 0x03,
	0x90, 0x03, 0x91, 0x03, 0x92, 0x03, 0x93, 0x03,
	0x94, 0x03, 0x95, 0x03, 0x96, 0x03, 0x97, 0x03,
	0x98, 0x03, 0x99, 0x03, 0x9a, 0x03, 0x9b, 0x03,
	0x9c, 0x03, 0x9d, 0x03, 0x9e, 0x03, 0x9f, 0x03,
	0xa0, 0x03, 0xa1, 0x03, 0xa2, 0x03, 0xa3, 0x03,
	0xa4, 0x03, 0xa5, 0x03, 0xa6, 0x03, 0xa7, 0x03,
	0xa8, 0x03, 0xa9, 0x03, 0xaa, 0x03, 0xab, 0x03,
	0x86, 0x03, 0x88, 0x03, 0x89, 0x03, 0x8a, 0x03,
	0xb0, 0x03, 0x91, 0x03, 0x92, 0x03, 0x93, 0x03,
	0x94, 0x03, 0x95, 0x03, 0x96, 0x03, 0x97, 0x03,
	0x98, 0x03, 0x99, 0x03, 0x9a, 0x03, 0x9b, 0x03,
	0x9c, 0x03, 0x9d, 0x03, 0x9e, 0x03, 0x9f, 0x03,
	0xa0, 0x03, 0xa1, 0x03, 0xa3, 0x03, 0xa3, 0x03,
	0xa4, 0x03, 0xa5, 0x03, 0xa6, 0x03, 0xa7, 0x03,
	0xa8, 0x03, 0xa9, 0x03, 0xaa, 0x03, 0xab, 0x03,
	0x8c, 0x03, 0x8e, 0x03, 0x8f, 0x03, 0xcf, 0x03,
	0xd0, 0x03, 0xd1, 0x03, 0xd2, 0x03, 0xd3, 0x03,
	0xd4, 0x03, 0xd5, 0x03, 0xd6, 0x03, 0xd7, 0x03,
	0xd8, 0x03, 0xd8, 0x03, 0xda, 0x03, 0xda, 0x03,
	0xdc, 0x03, 0xdc, 0x03, 0xde, 0x03, 0xde, 0x03,
	0xe0, 0x03, 0xe0, 0x03, 0xe2, 0x03, 0xe2, 0x03,
	0xe4, 0x03, 0xe4, 0x03, 0xe6, 0x03, 0xe6, 0x03,
	0xe8, 0x03, 0xe8, 0x03, 0xea, 0x03, 0xea, 0x03,
	0xec, 0x03, 0xec, 0x03, 0xee, 0x03, 0xee, 0x03,
	0xf0, 0x03, 0xf1, 0x03, 0xf9, 0x03, 0xf3, 0x03,
	0xf4, 0x03, 0xf5, 0x03, 0xf6, 0x03, 0xf7, 0x03,
	0xf7, 0x03, 0xf9, 0x03, 0xfa, 0x03, 0xfa, 0x03,
	0xfc, 0x03, 0xfd, 0x03, 0xfe, 0x03, 0xff, 0x03,
	0x00, 0x04, 0x01, 0x04, 0x02, 0x04, 0x03, 0x04,
	0x04, 0x04, 0x05, 0x04, 0x06, 0x04, 0x07, 0x04,
	0x08, 0x04, 0x09, 0x04, 0x0a, 0x04, 0x0b, 0x04,
	0x0c, 0x04, 0x0d, 0x04, 0x0e, 0x04, 0x0f, 0x04,
	0x10, 0x04, 0x11, 0x04, 0x12, 0x04, 0x13, 0x04,
	0x14, 0x04, 0x15, 0x04, 0x16, 0x04, 0x17, 0x04,
	0x18, 0x04, 0x19, 0x04, 0x1a, 0x04, 0x1b, 0x04,
	0x1c, 0x04, 0x1d, 0x04, 0x1e, 0x04, 0x1f, 0x04,
	0x20, 0x04, 0x21, 0x04, 0x22, 0x04, 0x23, 0x04,
	0x24, 0x04, 0x25, 0x04, 0x26, 0x04, 0x27, 0x04,
	0x28, 0x04, 0x29, 0x04, 0x2a, 0x04, 0x2b, 0x04,
	0x2c, 0x04, 0x2d, 0x04, 0x2e, 0x04, 0x2f, 0x04,
	0x10, 0x04, 0x11, 0x04, 0x12, 0x04, 0x13, 0x04,
	0x14, 0x04, 0x15, 0x04, 0x16, 0x04, 0x17, 0x04,
	0x18, 0x04, 0x19, 0x04, 0x1a, 0x04, 0x1b, 0x04,
	0x1c, 0x04, 0x1d, 0x04, 0x1e, 0x04, 0x1f, 0x04,
	0x20, 0x04, 0x21, 0x04, 0x22, 0x04, 0x23, 0x04,
	0x24, 0x04, 0x25, 0x04, 0x26, 0x04, 0x27, 0x04,
	0x28, 0x04, 0x29, 0x04, 0x2a, 0x04, 0x2b, 0x04,
	0x2c, 0x04, 0x2d, 0x04, 0x2e, 0x04, 0x2f, 0x04,
	0x00, 0x04, 0x01, 0x04, 0x02, 0x04, 0x03, 0x04,
	0x04, 0x04, 0x05, 0x04, 0x06, 0x04, 0x07, 0x04,
	0x08, 0x04, 0x09, 0x04, 0x0a, 0x04, 0x0b, 0x04,
	0x0c, 0x04, 0x0d, 0x04, 0x0e, 0x04, 0x0f, 0x04,
	0x60, 0x04, 0x60, 0x04, 0x62, 0x04, 0x62, 0x04,
	0x64, 0x04, 0x64, 0x04, 0x66, 0x04, 0x66, 0x04,
	0x68, 0x04, 0x68, 0x04, 0x6a, 0x04, 0x6a, 0x04,
	0x6c, 0x04, 0x6c, 0x04, 0x6e, 0x04, 0x6e, 0x04,
	0x70, 0x04, 0x70, 0x04, 0x72, 0x04, 0x72, 0x04,
	0x74, 0x04, 0x74, 0x04, 0x76, 0x04, 0x76, 0x04,
	0x78, 0x04, 0x78, 0x04, 0x7a, 0x04, 0x7a, 0x04,
	0x7c, 0x04, 0x7c, 0x04, 0x7e, 0x04, 0x7e, 0x04,
	0x80, 0x04, 0x80, 0x04, 0x82, 0x04, 0x83, 0x04,
	0x84, 0x04, 0x85, 0x04, 0x86, 0x04, 0x87, 0x04,
	0x88, 0x04, 0x89, 0x04, 0x8a, 0x04, 0x8a, 0x04,
	0x8c, 0x04, 0x8c, 0x04, 0x8e, 0x04, 0x8e, 0x04,
	0x90, 0x04, 0x90, 0x04, 0x92, 0x04, 0x92, 0x04,
	0x94, 0x04, 0x94, 0x04, 0x96, 0x04, 0x96, 0x04,
	0x98, 0x04, 0x98, 0x04, 0x9a, 0x04, 0x9a, 0x04,
	0x9c, 0x04, 0x9c, 0x04, 0x9e, 0x04, 0x9e, 0x04,
	0xa0, 0x04, 0xa0, 0x04, 0xa2, 0x04, 0xa2, 0x04,
	0xa4, 0x04, 0xa4, 0x04, 0xa6, 0x04, 0xa6, 0x04,
	0xa8, 0x04, 0xa8, 0x04, 0xaa, 0x04, 0xaa, 0x04,
	0xac, 0x04, 0xac, 0x04, 0xae, 0x04, 0xae, 0x04,
	0xb0, 0x04, 0xb0, 0x04, 0xb2, 0x04, 0xb2, 0x04,
	0xb4, 0x04, 0xb4, 0x04, 0xb6, 0x04, 0xb6, 0x04,
	0xb8, 0x04, 0xb8, 0x04, 0xba, 0x04, 0xba, 0x04,
	0xbc, 0x04, 0xbc, 0x04, 0xbe, 0x04, 0xbe, 0x04,
	0xc0, 0x04, 0xc1, 0x04, 0xc1, 0x04, 0xc3, 0x04,
	0xc3, 0x04, 0xc5, 0x04, 0xc5, 0x04, 0xc7, 0x04,
	0xc7, 0x04, 0xc9, 0x04, 0xc9, 0x04, 0xcb, 0x04,
	0xcb, 0x04, 0xcd, 0x04, 0xcd, 0x04, 0xc0, 0x04,
	0xd0, 0x04, 0xd0, 0x04, 0xd2, 0x04, 0xd2, 0x04,
	0xd4, 0x04, 0xd4, 0x04, 0xd6, 0x04, 0xd6, 0x04,
	0xd8, 0x04, 0xd8, 0x04, 0xda, 0x04, 0xda, 0x04,
	0xdc, 0x04, 0xdc, 0x04, 0xde, 0x04, 0xde, 0x04,
	0xe0, 0x04, 0xe0, 0x04, 0xe2, 0x04, 0xe2, 0x04,
	0xe4, 0x04, 0xe4, 0x04, 0xe6, 0x04, 0xe6, 0x04,
	0xe8, 0x04, 0xe8, 0x04, 0xea, 0x04, 0xea, 0x04,
	0xec, 0x04, 0xec, 0x04, 0xee, 0x04, 0xee, 0x04,
	0xf0, 0x04, 0xf0, 0x04, 0xf2, 0x04, 0xf2, 0x04,
	0xf4, 0x04, 0xf4, 0x04, 0xf6, 0x04, 0xf6, 0x04,
	0xf8, 0x04, 0xf8, 0x04, 0xfa, 0x04, 0xfa, 0x04,
	0xfc, 0x04, 0xfc, 0x04, 0xfe, 0x04, 0xfe, 0x04,
	0x00, 0x05, 0x00, 0x05, 0x02, 0x05, 0x02, 0x05,
	0x04, 0x05, 0x04, 0x05, 0x06, 0x05, 0x06, 0x05,
	0x08, 0x05, 0x08, 0x05, 0x0a, 0x05, 0x0a, 0x05,
	0x0c, 0x05, 0x0c, 0x05, 0x0e, 0x05, 0x0e, 0x05,
	0x10, 0x05, 0x10, 0x05, 0x12, 0x05, 0x12, 0x05,
	0x14, 0x05, 0x15, 0x05, 0x16, 0x05, 0x17, 0x05,
	0x18, 0x05, 0x19, 0x05, 0x1a, 0x05, 0x1b, 0x05,
	0x1c, 0x05, 0x1d, 0x05, 0x1e, 0x05, 0x1f, 0x05,
	0x20, 0x05, 0x21, 0x05, 0x22, 0x05, 0x23, 0x05,
	0x24, 0x05, 0x25, 0x05, 0x26, 0x05, 0x27, 0x05,
	0x28, 0x05, 0x29, 0x05, 0x2a, 0x05, 0x2b, 0x05,
	0x2c, 0x05, 0x2d, 0x05, 0x2e, 0x05, 0x2f, 0x05,
	0x30, 0x05, 0x31, 0x05, 0x32, 0x05, 0x33, 0x05,
	0x34, 0x05, 0x35, 0x05, 0x36, 0x05, 0x37, 0x05,
	0x38, 0x05, 0x39, 0x05, 0x3a, 0x05, 0x3b, 0x05,
	0x3c, 0x05, 0x3d, 0x05, 0x3e, 0x05, 0x3f, 0x05,
	0x40, 0x05, 0x41, 0x05, 0x42, 0x05, 0x43, 0x05,
	0x44, 0x05, 0x45, 0x05, 0x46, 0x05, 0x47, 0x05,
	0x48, 0x05, 0x49, 0x05, 0x4a, 0x05, 0x4b, 0x05,
	0x4c, 0x05, 0x4d, 0x05, 0x4e, 0x05, 0x4f, 0x05,
	0x50, 0x05, 0x51, 0x05, 0x52, 0x05, 0x53, 0x05,
	0x54, 0x05, 0x55, 0x05, 0x56, 0x05, 0x57, 0x05,
	0x58, 0x05, 0x59, 0x05, 0x5a, 0x05, 0x5b, 0x05,
	0x5c, 0x05, 0x5d, 0x05, 0x5e, 0x05, 0x5f, 0x05,
	0x60, 0x05, 0x31, 0x05, 0x32, 0x05, 0x33, 0x05,
	0x34, 0x05, 0x35, 0x05, 0x36, 0x05, 0x37, 0x05,
	0x38, 0x05, 0x39, 0x05, 0x3a, 0x05, 0x3b, 0x05,
	0x3c, 0x05, 0x3d, 0x05, 0x3e, 0x05, 0x3f, 0x05,
	0x40, 0x05, 0x41, 0x05, 0x42, 0x05, 0x43, 0x05,
	0x44, 0x05, 0x45, 0x05, 0x46, 0x05, 0x47, 0x05,
	0x48, 0x05, 0x49, 0x05, 0x4a, 0x05, 0x4b, 0x05,
	0x4c, 0x05, 0x4d, 0x05, 0x4e, 0x05, 0x4f, 0x05,
	0x50, 0x05, 0x51, 0x05, 0x52, 0x05, 0x53, 0x05,
	0x54, 0x05, 0x55, 0x05, 0x56, 0x05, 0xff, 0xff,
	0xf6, 0x17, 0x63, 0x2c, 0x7e, 0x1d, 0x7f, 0x1d,
	0x80, 0x1d, 0x81, 0x1d, 0x82, 0x1d, 0x83, 0x1d,
	0x84, 0x1d, 0x85, 0x1d, 0x86, 0x1d, 0x87, 0x1d,
	0x88, 0x1d, 0x89, 0x1d, 0x8a, 0x1d, 0x8b, 0x1d,
	0x8c, 0x1d, 0x8d, 0x1d, 0x8e, 0x1d, 0x8f, 0x1d,
	0x90, 0x1d, 0x91, 0x1d, 0x92, 0x1d, 0x93, 0x1d,
	0x94, 0x1d, 0x95, 0x1d, 0x96, 0x1d, 0x97, 0x1d,
	0x98, 0x1d, 0x99, 0x1d, 0x9a, 0x1d, 0x9b, 0x1d,
	0x9c, 0x1d, 0x9d, 0x1d, 0x9e, 0x1d, 0x9f, 0x1d,
	0xa0, 0x1d, 0xa1, 0x1d, 0xa2, 0x1d, 0xa3, 0x1d,
	0xa4, 0x1d, 0xa5, 0x1d, 0xa6, 0x1d, 0xa7, 0x1d,
	0xa8, 0x1d, 0xa9, 0x1d, 0xaa, 0x1d, 0xab, 0x1d,
	0xac, 0x1d, 0xad, 0x1d, 0xae, 0x1d, 0xaf, 0x1d,
	0xb0, 0x1d, 0xb1, 0x1d, 0xb2, 0x1d, 0xb3, 0x1d,
	0xb4, 0x1d, 0xb5, 0x1d, 0xb6, 0x1d, 0xb7, 0x1d,
	0xb8, 0x1d, 0xb9, 0x1d, 0xba, 0x1d, 0xbb, 0x1d,
	0xbc, 0x1d, 0xbd, 0x1d, 0xbe, 0x1d, 0xbf, 0x1d,
	0xc0, 0x1d, 0xc1, 0x1d, 0xc2, 0x1d, 0xc3, 0x1d,
	0xc4, 0x1d, 0xc5, 0x1d, 0xc6, 0x1d, 0xc7, 0x1d,
	0xc8, 0x1d, 0xc9, 0x1d, 0xca, 0x1d, 0xcb, 0x1d,
	0xcc, 0x1d, 0xcd, 0x1d, 0xce, 0x1d, 0xcf, 0x1d,
	0xd0, 0x1d, 0xd1, 0x1d, 0xd2, 0x1d, 0xd3, 0x1d,
	0xd4, 0x1d, 0xd5, 0x1d, 0xd6, 0x1d, 0xd7, 0x1d,
	0xd8, 0x1d, 0xd9, 0x1d, 0xda, 0x1d, 0xdb, 0x1d,
	0xdc, 0x1d, 0xdd, 0x1d, 0xde, 0x1d, 0xdf, 0x1d,
	0xe0, 0x1d, 0xe1, 0x1d, 0xe2, 0x1d, 0xe3, 0x1d,
	0xe4, 0x1d, 0xe5, 0x1d, 0xe6, 0x1d, 0xe7, 0x1d,
	0xe8, 0x1d, 0xe9, 0x1d, 0xea, 0x1d, 0xeb, 0x1d,
	0xec, 0x1d, 0xed, 0x1d, 0xee, 0x1d, 0xef, 0x1d,
	0xf0, 0x1d, 0xf1, 0x1d, 0xf2, 0x1d, 0xf3, 0x1d,
	0xf4, 0x1d, 0xf5, 0x1d, 0xf6, 0x1d, 0xf7, 0x1d,
	0xf8, 0x1d, 0xf9, 0x1d, 0xfa, 0x1d, 0xfb, 0x1d,
	0xfc, 0x1d, 0xfd, 0x1d, 0xfe, 0x1d, 0xff, 0x1d,
	0x00, 0x1e, 0x00, 0x1e, 0x02, 0x1e, 0x02, 0x1e,
	0x04, 0x1e, 0x04, 0x1e, 0x06, 0x1e, 0x06, 0x1e,
	0x08, 0x1e, 0x08, 0x1e, 0x0a, 0x1e, 0x0a, 0x1e,
	0x0c, 0x1e, 0x0c, 0x1e, 0x0e, 0x1e, 0x0e, 0x1e,
	0x10, 0x1e, 0x10, 0x1e, 0x12, 0x1e, 0x12, 0x1e,
	0x14, 0x1e, 0x14, 0x1e, 0x16, 0x1e, 0x16, 0x1e,
	0x18, 0x1e, 0x18, 0x1e, 0x1a, 0x1e, 0x1a, 0x1e,
	0x1c, 0x1e, 0x1c, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e,
	0x20, 0x1e, 0x20, 0x1e, 0x22, 0x1e, 0x22, 0x1e,
	0x24, 0x1e, 0x24, 0x1e, 0x26, 0x1e, 0x26, 0x1e,
	0x28, 0x1e, 0x28, 0x1e, 0x2a, 0x1e, 0x2a, 0x1e,
	0x2c, 0x1e, 0x2c, 0x1e, 0x2e, 0x1e, 0x2e, 0x1e,
	0x30, 0x1e, 0x30, 0x1e, 0x32, 0x1e, 0x32, 0x1e,
	0x34, 0x1e, 0x34, 0x1e, 0x36, 0x1e, 0x36, 0x1e,
	0x38, 0x1e, 0x38, 0x1e, 0x3a, 0x1e, 0x3a, 0x1e,
	0x3c, 0x1e, 0x3c, 0x1e, 0x3e, 0x1e, 0x3e, 0x1e,
	0x40, 0x1e, 0x40, 0x1e, 0x42, 0x1e, 0x42, 0x1e,
	0x44, 0x1e, 0x44, 0x1e, 0x46, 0x1e, 0x46, 0x1e,
	0x48, 0x1e, 0x48, 0x1e, 0x4a, 0x1e, 0x4a, 0x1e,
	0x4c, 0x1e, 0x4c, 0x1e, 0x4e, 0x1e, 0x4e, 0x1e,
	0x50, 0x1e, 0x50, 0x1e, 0x52, 0x1e, 0x52, 0x1e,
	0x54, 0x1e, 0x54, 0x1e, 0x56, 0x1e, 0x56, 0x1e,
	0x58, 0x1e, 0x58, 0x1e, 0x5a, 0x1e, 0x5a, 0x1e,
	0x5c, 0x1e, 0x5c, 0x1e, 0x5e, 0x1e, 0x5e, 0x1e,
	0x60, 0x1e, 0x60, 0x1e, 0x62, 0x1e, 0x62, 0x1e,
	0x64, 0x1e, 0x64, 0x1e, 0x66, 0x1e, 0x66, 0x1e,
	0x68, 0x1e, 0x68, 0x1e, 0x6a, 0x1e, 0x6a, 0x1e,
	0x6c, 0x1e, 0x6c, 0x1e, 0x6e, 0x1e, 0x6e, 0x1e,
	0x70, 0x1e, 0x70, 0x1e, 0x72, 0x1e, 0x72, 0x1e,
	0x74, 0x1e, 0x74, 0x1e, 0x76, 0x1e, 0x76, 0x1e,
	0x78, 0x1e, 0x78, 0x1e, 0x7a, 0x1e, 0x7a, 0x1e,
	0x7c, 0x1e, 0x7c, 0x1e, 0x7e, 0x1e, 0x7e, 0x1e,
	0x80, 0x1e, 0x80, 0x1e, 0x82, 0x1e, 0x82, 0x1e,
	0x84, 0x1e, 0x84, 0x1e, 0x86, 0x1e, 0x86, 0x1e,
	0x88, 0x1e, 0x88, 0x1e, 0x8a, 0x1e, 0x8a, 0x1e,
	0x8c, 0x1e, 0x8c, 0x1e, 0x8e, 0x1e, 0x8e, 0x1e,
	0x90, 0x1e, 0x90, 0x1e, 0x92, 0x1e, 0x92, 0x1e,
	0x94, 0x1e, 0x94, 0x1e, 0x96, 0x1e, 0x97, 0x1e,
	0x98, 0x1e, 0x99, 0x1e, 0x9a, 0x1e, 0x9b, 0x1e,
	0x9c, 0x1e, 0x9d, 0x1e, 0x9e, 0x1e, 0x9f, 0x1e,
	0xa0, 0x1e, 0xa0, 0x1e, 0xa2, 0x1e, 0xa2, 0x1e,
	0xa4, 0x1e, 0xa4, 0x1e, 0xa6, 0x1e, 0xa6, 0x1e,
	0xa8, 0x1e, 0xa8, 0x1e, 0xaa, 0x1e, 0xaa, 0x1e,
	0xac, 0x1e, 0xac, 0x1e, 0xae, 0x1e, 0xae, 0x1e,
	0xb0, 0x1e, 0xb0, 0x1e, 0xb2, 0x1e, 0xb2, 0x1e,
	0xb4, 0x1e, 0xb4, 0x1e, 0xb6, 0x1e, 0xb6, 0x1e,
	0xb8, 0x1e, 0xb8, 0x1e, 0xba, 0x1e, 0xba, 0x1e,
	0xbc, 0x1e, 0xbc, 0x1e, 0xbe, 0x1e, 0xbe, 0x1e,
	0xc0, 0x1e, 0xc0, 0x1e, 0xc2, 0x1e, 0xc2, 0x1e,
	0xc4, 0x1e, 0xc4, 0x1e, 0xc6, 0x1e, 0xc6, 0x1e,
	0xc8, 0x1e, 0xc8, 0x1e, 0xca, 0x1e, 0xca, 0x1e,
	0xcc, 0x1e, 0xcc, 0x1e, 0xce, 0x1e, 0xce, 0x1e,
	0xd0, 0x1e, 0xd0, 0x1e, 0xd2, 0x1e, 0xd2, 0x1e,
	0xd4, 0x1e, 0xd4, 0x1e, 0xd6, 0x1e, 0xd6, 0x1e,
	0xd8, 0x1e, 0xd8, 0x1e, 0xda, 0x1e, 0xda, 0x1e,
	0xdc, 0x1e, 0xdc, 0x1e, 0xde, 0x1e, 0xde, 0x1e,
	0xe0, 0x1e, 0xe0, 0x1e, 0xe2, 0x1e, 0xe2, 0x1e,
	0xe4, 0x1e, 0xe4, 0x1e, 0xe6, 0x1e, 0xe6, 0x1e,
	0xe8, 0x1e, 0xe8, 0x1e, 0xea, 0x1e, 0xea, 0x1e,
	0xec, 0x1e, 0xec, 0x1e, 0xee, 0x1e, 0xee, 0x1e,
	0xf0, 0x1e, 0xf0, 0x1e, 0xf2, 0x1e, 0xf2, 0x1e,
	0xf4, 0x1e, 0xf4, 0x1e, 0xf6, 0x1e, 0xf6, 0x1e,
	0xf8, 0x1e, 0xf8, 0x1e, 0xfa, 0x1e, 0xfb, 0x1e,
	0xfc, 0x1e, 0xfd, 0x1e, 0xfe, 0x1e, 0xff, 0x1e,
	0x08, 0x1f, 0x09, 0x1f, 0x0a, 0x1f, 0x0b, 0x1f,
	0x0c, 0x1f, 0x0d, 0x1f, 0x0e, 0x1f, 0x0f, 0x1f,
	0x08, 0x1f, 0x09, 0x1f, 0x0a, 0x1f, 0x0b, 0x1f,
	0x0c, 0x1f, 0x0d, 0x1f, 0x0e, 0x1f, 0x0f, 0x1f,
	0x18, 0x1f, 0x19, 0x1f, 0x1a, 0x1f, 0x1b, 0x1f,
	0x1c, 0x1f, 0x1d, 0x1f, 0x16, 0x1f, 0x17, 0x1f,
	0x18, 0x1f, 0x19, 0x1f, 0x1a, 0x1f, 0x1b, 0x1f,
	0x1c, 0x1f, 0x1d, 0x1f, 0x1e, 0x1f, 0x1f, 0x1f,
	0x28, 0x1f, 0x29, 0x1f, 0x2a, 0x1f, 0x2b, 0x1f,
	0x2c, 0x1f, 0x2d, 0x1f, 0x2e, 0x1f, 0x2f, 0x1f,
	0x28, 0x1f, 0x29, 0x1f, 0x2a, 0x1f, 0x2b, 0x1f,
	0x2c, 0x1f, 0x2d, 0x1f, 0x2e, 0x1f, 0x2f, 0x1f,
	0x38, 0x1f, 0x39, 0x1f, 0x3a, 0x1f, 0x3b, 0x1f,
	0x3c, 0x1f, 0x3d, 0x1f, 0x3e, 0x1f, 0x3f, 0x1f,
	0x38, 0x1f, 0x39, 0x1f, 0x3a, 0x1f, 0x3b, 0x1f,
	0x3c, 0x1f, 0x3d, 0x1f, 0x3e, 0x1f, 0x3f, 0x1f,
	0x48, 0x1f, 0x49, 0x1f, 0x4a, 0x1f, 0x4b, 0x1f,
	0x4c, 0x1f, 0x4d, 0x1f, 0x46, 0x1f, 0x47, 0x1f,
	0x48, 0x1f, 0x49, 0x1f, 0x4a, 0x1f, 0x4b, 0x1f,
	0x4c, 0x1f, 0x4d, 0x1f, 0x4e, 0x1f, 0x4f, 0x1f,
	0x50, 0x1f, 0x59, 0x1f, 0x52, 0x1f, 0x5b, 0x1f,
	0x54, 0x1f, 0x5d, 0x1f, 0x56, 0x1f, 0x5f, 0x1f,
	0x58, 0x1f, 0x59, 0x1f, 0x5a, 0x1f, 0x5b, 0x1f,
	0x5c, 0x1f, 0x5d, 0x1f, 0x5e, 0x1f, 0x5f, 0x1f,
	0x68, 0x1f, 0x69, 0x1f, 0x6a, 0x1f, 0x6b, 0x1f,
	0x6c, 0x1f, 0x6d, 0x1f, 0x6e, 0x1f, 0x6f, 0x1f,
	0x68, 0x1f, 0x69, 0x1f, 0x6a, 0x1f, 0x6b, 0x1f,
	0x6c, 0x1f, 0x6d, 0x1f, 0x6e, 0x1f, 0x6f, 0x1f,
	0xba, 0x1f, 0xbb, 0x1f, 0xc8, 0x1f, 0xc9, 0x1f,
	0xca, 0x1f, 0xcb, 0x1f, 0xda, 0x1f, 0xdb, 0x1f,
	0xf8, 0x1f, 0xf9, 0x1f, 0xea, 0x1f, 0xeb, 0x1f,
	0xfa, 0x1f, 0xfb, 0x1f, 0x7e, 0x1f, 0x7f, 0x1f,
	0x88, 0x1f, 0x89, 0x1f, 0x8a, 0x1f, 0x8b, 0x1f,
	0x8c, 0x1f, 0x8d, 0x1f, 0x8e, 0x1f, 0x8f, 0x1f,
	0x88, 0x1f, 0x89, 0x1f, 0x8a, 0x1f, 0x8b, 0x1f,
	0x8c, 0x1f, 0x8d, 0x1f, 0x8e, 0x1f, 0x8f, 0x1f,
	0x98, 0x1f, 0x99, 0x1f, 0x9a, 0x1f, 0x9b, 0x1f,
	0x9c, 0x1f, 0x9d, 0x1f, 0x9e, 0x1f, 0x9f, 0x1f,
	0x98, 0x1f, 0x99, 0x1f, 0x9a, 0x1f, 0x9b, 0x1f,
	0x9c, 0x1f, 0x9d, 0x1f, 0x9e, 0x1f, 0x9f, 0x1f,
	0xa8, 0x1f, 0xa9, 0x1f, 0xaa, 0x1f, 0xab, 0x1f,
	0xac, 0x1f, 0xad, 0x1f, 0xae, 0x1f, 0xaf, 0x1f,
	0xa8, 0x1f, 0xa9, 0x1f, 0xaa, 0x1f, 0xab, 0x1f,
	0xac, 0x1f, 0xad, 0x1f, 0xae, 0x1f, 0xaf, 0x1f,
	0xb8, 0x1f, 0xb9, 0x1f, 0xb2, 0x1f, 0xbc, 0x1f,
	0xb4, 0x1f, 0xb5, 0x1f, 0xb6, 0x1f, 0xb7, 0x1f,
	0xb8, 0x1f, 0xb9, 0x1f, 0xba, 0x1f, 0xbb, 0x1f,
	0xbc, 0x1f, 0xbd, 0x1f, 0xbe, 0x1f, 0xbf, 0x1f,
	0xc0, 0x1f, 0xc1, 0x1f, 0xc2, 0x1f, 0xc3, 0x1f,
	0xc4, 0x1f, 0xc5, 0x1f, 0xc6, 0x1f, 0xc7, 0x1f,
	0xc8, 0x1f, 0xc9, 0x1f, 0xca, 0x1f, 0xcb, 0x1f,
	0xc3, 0x1f, 0xcd, 0x1f, 0xce, 0x1f, 0xcf, 0x1f,
	0xd8, 0x1f, 0xd9, 0x1f, 0xd2, 0x1f, 0xd3, 0x1f,
	0xd4, 0x1f, 0xd5, 0x1f, 0xd6, 0x1f, 0xd7, 0x1f,
	0xd8, 0x1f, 0xd9, 0x1f, 0xda, 0x1f, 0xdb, 0x1f,
	0xdc, 0x1f, 0xdd, 0x1f, 0xde, 0x1f, 0xdf, 0x1f,
	0xe8, 0x1f, 0xe9, 0x1f, 0xe2, 0x1f, 0xe3, 0x1f,
	0xe4, 0x1f, 0xec, 0x1f, 0xe6, 0x1f, 0xe7, 0x1f,
	0xe8, 0x1f, 0xe9, 0x1f, 0xea, 0x1f, 0xeb, 0x1f,
	0xec, 0x1f, 0xed, 0x1f, 0xee, 0x1f, 0xef, 0x1f,
	0xf0, 0x1f, 0xf1, 0x1f, 0xf2, 0x1f, 0xf3, 0x1f,
	0xf4, 0x1f, 0xf5, 0x1f, 0xf6, 0x1f, 0xf7, 0x1f,
	0xf8, 0x1f, 0xf9, 0x1f, 0xfa, 0x1f, 0xfb, 0x1f,
	0xf3, 0x1f, 0xfd, 0x1f, 0xfe, 0x1f, 0xff, 0x1f,
	0x00, 0x20, 0x01, 0x20, 0x02, 0x20, 0x03, 0x20,
	0x04, 0x20, 0x05, 0x20, 0x06, 0x20, 0x07, 0x20,
	0x08, 0x20, 0x09, 0x20, 0x0a, 0x20, 0x0b, 0x20,
	0x0c, 0x20, 0x0d, 0x20, 0x0e, 0x20, 0x0f, 0x20,
	0x10, 0x20, 0x11, 0x20, 0x12, 0x20, 0x13, 0x20,
	0x14, 0x20, 0x15, 0x20, 0x16, 0x20, 0x17, 0x20,
	0x18, 0x20, 0x19, 0x20, 0x1a, 0x20, 0x1b, 0x20,
	0x1c, 0x20, 0x1d, 0x20, 0x1e, 0x20, 0x1f, 0x20,
	0x20, 0x20, 0x21, 0x20, 0x22, 0x20, 0x23, 0x20,
	0x24, 0x20, 0x25, 0x20, 0x26, 0x20, 0x27, 0x20,
	0x28, 0x20, 0x29, 0x20, 0x2a, 0x20, 0x2b, 0x20,
	0x2c, 0x20, 0x2d, 0x20, 0x2e, 0x20, 0x2f, 0x20,
	0x30, 0x20, 0x31, 0x20, 0x32, 0x20, 0x33, 0x20,
	0x34, 0x20, 0x35, 0x20, 0x36, 0x20, 0x37, 0x20,
	0x38, 0x20, 0x39, 0x20, 0x3a, 0x20, 0x3b, 0x20,
	0x3c, 0x20, 0x3d, 0x20, 0x3e, 0x20, 0x3f, 0x20,
	0x40, 0x20, 0x41, 0x20, 0x42, 0x20, 0x43, 0x20,
	0x44, 0x20, 0x45, 0x20, 0x46, 0x20, 0x47, 0x20,
	0x48, 0x20, 0x49, 0x20, 0x4a, 0x20, 0x4b, 0x20,
	0x4c, 0x20, 0x4d, 0x20, 0x4e, 0x20, 0x4f, 0x20,
	0x50, 0x20, 0x51, 0x20, 0x52, 0x20, 0x53, 0x20,
	0x54, 0x20, 0x55, 0x20, 0x56, 0x20, 0x57, 0x20,
	0x58, 0x20, 0x59, 0x20, 0x5a, 0x20, 0x5b, 0x20,
	0x5c, 0x20, 0x5d, 0x20, 0x5e, 0x20, 0x5f, 0x20,
	0x60, 0x20, 0x61, 0x20, 0x62, 0x20, 0x63, 0x20,
	0x64, 0x20, 0x65, 0x20, 0x66, 0x20, 0x67, 0x20,
	0x68, 0x20, 0x69, 0x20, 0x6a, 0x20, 0x6b, 0x20,
	0x6c, 0x20, 0x6d, 0x20, 0x6e, 0x20, 0x6f, 0x20,
	0x70, 0x20, 0x71, 0x20, 0x72, 0x20, 0x73, 0x20,
	0x74, 0x20, 0x75, 0x20, 0x76, 0x20, 0x77, 0x20,
	0x78, 0x20, 0x79, 0x20, 0x7a, 0x20, 0x7b, 0x20,
	0x7c, 0x20, 0x7d, 0x20, 0x7e, 0x20, 0x7f, 0x20,
	0x80, 0x20, 0x81, 0x20, 0x82, 0x20, 0x83, 0x20,
	0x84, 0x20, 0x85, 0x20, 0x86, 0x20, 0x87, 0x20,
	0x88, 0x20, 0x89, 0x20, 0x8a, 0x20, 0x8b, 0x20,
	0x8c, 0x20, 0x8d, 0x20, 0x8e, 0x20, 0x8f, 0x20,
	0x90, 0x20, 0x91, 0x20, 0x92, 0x20, 0x93, 0x20,
	0x94, 0x20, 0x95, 0x20, 0x96, 0x20, 0x97, 0x20,
	0x98, 0x20, 0x99, 0x20, 0x9a, 0x20, 0x9b, 0x20,
	0x9c, 0x20, 0x9d, 0x20, 0x9e, 0x20, 0x9f, 0x20,
	0xa0, 0x20, 0xa1, 0x20, 0xa2, 0x20, 0xa3, 0x20,
	0xa4, 0x20, 0xa5, 0x20, 0xa6, 0x20, 0xa7, 0x20,
	0xa8, 0x20, 0xa9, 0x20, 0xaa, 0x20, 0xab, 0x20,
	0xac, 0x20, 0xad, 0x20, 0xae, 0x20, 0xaf, 0x20,
	0xb0, 0x20, 0xb1, 0x20, 0xb2, 0x20, 0xb3, 0x20,
	0xb4, 0x20, 0xb5, 0x20, 0xb6, 0x20, 0xb7, 0x20,
	0xb8, 0x20, 0xb9, 0x20, 0xba, 0x20, 0xbb, 0x20,
	0xbc, 0x20, 0xbd, 0x20, 0xbe, 0x20, 0xbf, 0x20,
	0xc0, 0x20, 0xc1, 0x20, 0xc2, 0x20, 0xc3, 0x20,
	0xc4, 0x20, 0xc5, 0x20, 0xc6, 0x20, 0xc7, 0x20,
	0xc8, 0x20, 0xc9, 0x20, 0xca, 0x20, 0xcb, 0x20,
	0xcc, 0x20, 0xcd, 0x20, 0xce, 0x20, 0xcf, 0x20,
	0xd0, 0x20, 0xd1, 0x20, 0xd2, 0x20, 0xd3, 0x20,
	0xd4, 0x20, 0xd5, 0x20, 0xd6, 0x20, 0xd7, 0x20,
	0xd8, 0x20, 0xd9, 0x20, 0xda, 0x20, 0xdb, 0x20,
	0xdc, 0x20, 0xdd, 0x20, 0xde, 0x20, 0xdf, 0x20,
	0xe0, 0x20, 0xe1, 0x20, 0xe2, 0x20, 0xe3, 0x20,
	0xe4, 0x20, 0xe5, 0x20, 0xe6, 0x20, 0xe7, 0x20,
	0xe8, 0x20, 0xe9, 0x20, 0xea, 0x20, 0xeb, 0x20,
	0xec, 0x20, 0xed, 0x20, 0xee, 0x20, 0xef, 0x20,
	0xf0, 0x20, 0xf1, 0x20, 0xf2, 0x20, 0xf3, 0x20,
	0xf4, 0x20, 0xf5, 0x20, 0xf6, 0x20, 0xf7, 0x20,
	0xf8, 0x20, 0xf9, 0x20, 0xfa, 0x20, 0xfb, 0x20,
	0xfc, 0x20, 0xfd, 0x20, 0xfe, 0x20, 0xff, 0x20,
	0x00, 0x21, 0x01, 0x21, 0x02, 0x21, 0x03, 0x21,
	0x04, 0x21, 0x05, 0x21, 0x06, 0x21, 0x07, 0x21,
	0x08, 0x21, 0x09, 0x21, 0x0a, 0x21, 0x0b, 0x21,
	0x0c, 0x21, 0x0d, 0x21, 0x0e, 0x21, 0x0f, 0x21,
	0x10, 0x21, 0x11, 0x21, 0x12, 0x21, 0x13, 0x21,
	0x14, 0x21, 0x15, 0x21, 0x16, 0x21, 0x17, 0x21,
	0x18, 0x21, 0x19, 0x21, 0x1a, 0x21, 0x1b, 0x21,
	0x1c, 0x21, 0x1d, 0x21, 0x1e, 0x21, 0x1f, 0x21,
	0x20, 0x21, 0x21, 0x21, 0x22, 0x21, 0x23, 0x21,
	0x24, 0x21, 0x25, 0x21, 0x26, 0x21, 0x27, 0x21,
	0x28, 0x21, 0x29, 0x21, 0x2a, 0x21, 0x2b, 0x21,
	0x2c, 0x21, 0x2d, 0x21, 0x2e, 0x21, 0x2f, 0x21,
	0x30, 0x21, 0x31, 0x21, 0x32, 0x21, 0x33, 0x21,
	0x34, 0x21, 0x35, 0x21, 0x36, 0x21, 0x37, 0x21,
	0x38, 0x21, 0x39, 0x21, 0x3a, 0x21, 0x3b, 0x21,
	0x3c, 0x21, 0x3d, 0x21, 0x3e, 0x21, 0x3f, 0x21,
	0x40, 0x21, 0x41, 0x21, 0x42, 0x21, 0x43, 0x21,
	0x44, 0x21, 0x45, 0x21, 0x46, 0x21, 0x47, 0x21,
	0x48, 0x21, 0x49, 0x21, 0x4a, 0x21, 0x4b, 0x21,
	0x4c, 0x21, 0x4d, 0x21, 0x32, 0x21, 0x4f, 0x21,
	0x50, 0x21, 0x51, 0x21, 0x52, 0x21, 0x53, 0x21,
	0x54, 0x21, 0x55, 0x21, 0x56, 0x21, 0x57, 0x21,
	0x58, 0x21, 0x59, 0x21, 0x5a, 0x21, 0x5b, 0x21,
	0x5c, 0x21, 0x5d, 0x21, 0x5e, 0x21, 0x5f, 0x21,
	0x60, 0x21, 0x61, 0x21, 0x62, 0x21, 0x63, 0x21,
	0x64, 0x21, 0x65, 0x21, 0x66, 0x21, 0x67, 0x21,
	0x68, 0x21, 0x69, 0x21, 0x6a, 0x21, 0x6b, 0x21,
	0x6c, 0x21, 0x6d, 0x21, 0x6e, 0x21, 0x6f, 0x21,
	0x60, 0x21, 0x61, 0x21, 0x62, 0x21, 0x63, 0x21,
	0x64, 0x21, 0x65, 0x21, 0x66, 0x21, 0x67, 0x21,
	0x68, 0x21, 0x69, 0x21, 0x6a, 0x21, 0x6b, 0x21,
	0x6c, 0x21, 0x6d, 0x21, 0x6e, 0x21, 0x6f, 0x21,
	0x80, 0x21, 0x81, 0x21, 0x82, 0x21, 0x83, 0x21,
	0x83, 0x21, 0xff, 0xff, 0x4b, 0x03, 0xb6, 0x24,
	0xb7, 0x24, 0xb8, 0x24, 0xb9, 0x24, 0xba, 0x24,
	0xbb, 0x24, 0xbc, 0x24, 0xbd, 0x24, 0xbe, 0x24,
	0xbf, 0x24, 0xc0, 0x24, 0xc1, 0x24, 0xc2, 0x24,
	0xc3, 0x24, 0xc4, 0x24, 0xc5, 0x24, 0xc6, 0x24,
	0xc7, 0x24, 0xc8, 0x24, 0xc9, 0x24, 0xca, 0x24,
	0xcb, 0x24, 0xcc, 0x24, 0xcd, 0x24, 0xce, 0x24,
	0xcf, 0x24, 0xff, 0xff, 0x46, 0x07, 0x00, 0x2c,
	0x01, 0x2c, 0x02, 0x2c, 0x03, 0x2c, 0x04, 0x2c,
	0x05, 0x2c, 0x06, 0x2c, 0x07, 0x2c, 0x08, 0x2c,
	0x09, 0x2c, 0x0a, 0x2c, 0x0b, 0x2c, 0x0c, 0x2c,
	0x0d, 0x2c, 0x0e, 0x2c, 0x0f, 0x2c, 0x10, 0x2c,
	0x11, 0x2c, 0x12, 0x2c, 0x13, 0x2c, 0x14, 0x2c,
	0x15, 0x2c, 0x16, 0x2c, 0x17, 0x2c, 0x18, 0x2c,
	0x19, 0x2c, 0x1a, 0x2c, 0x1b, 0x2c, 0x1c, 0x2c,
	0x1d, 0x2c, 0x1e, 0x2c, 0x1f, 0x2c, 0x20, 0x2c,
	0x21, 0x2c, 0x22, 0x2c, 0x23, 0x2c, 0x24, 0x2c,
	0x25, 0x2c, 0x26, 0x2c, 0x27, 0x2c, 0x28, 0x2c,
	0x29, 0x2c, 0x2a, 0x2c, 0x2b, 0x2c, 0x2c, 0x2c,
	0x2d, 0x2c, 0x2e, 0x2c, 0x5f, 0x2c, 0x60, 0x2c,
	0x60, 0x2c, 0x62, 0x2c, 0x63, 0x2c, 0x64, 0x2c,
	0x65, 0x2c, 0x66, 0x2c, 0x67, 0x2c, 0x67, 0x2c,
	0x69, 0x2c, 0x69, 0x2c, 0x6b, 0x2c, 0x6b, 0x2c,
	0x6d, 0x2c, 0x6e, 0x2c, 0x6f, 0x2c, 0x70, 0x2c,
	0x71, 0x2c, 0x72, 0x2c, 0x73, 0x2c, 0x74, 0x2c,
	0x75, 0x2c, 0x75, 0x2c, 0x77, 0x2c, 0x78, 0x2c,
	0x79, 0x2c, 0x7a, 0x2c, 0x7b, 0x2c, 0x7c, 0x2c,
	0x7d, 0x2c, 0x7e, 0x2c, 0x7f, 0x2c, 0x80, 0x2c,
	0x80, 0x2c, 0x82, 0x2c, 0x82, 0x2c, 0x84, 0x2c,
	0x84, 0x2c, 0x86, 0x2c, 0x86, 0x2c, 0x88, 0x2c,
	0x88, 0x2c, 0x8a, 0x2c, 0x8a, 0x2c, 0x8c, 0x2c,
	0x8c, 0x2c, 0x8e, 0x2c, 0x8e, 0x2c, 0x90, 0x2c,
	0x90, 0x2c, 0x92, 0x2c, 0x92, 0x2c, 0x94, 0x2c,
	0x94, 0x2c, 0x96, 0x2c, 0x96, 0x2c, 0x98, 0x2c,
	0x98, 0x2c, 0x9a, 0x2c, 0x9a, 0x2c, 0x9c, 0x2c,
	0x9c, 0x2c, 0x9e, 0x2c, 0x9e, 0x2c, 0xa0, 0x2c,
	0xa0, 0x2c, 0xa2, 0x2c, 0xa2, 0x2c, 0xa4, 0x2c,
	0xa4, 0x2c, 0xa6, 0x2c, 0xa6, 0x2c, 0xa8, 0x2c,
	0xa8, 0x2c, 0xaa, 0x2c, 0xaa, 0x2c, 0xac, 0x2c,
	0xac, 0x2c, 0xae, 0x2c, 0xae, 0x2c, 0xb0, 0x2c,
	0xb0, 0x2c, 0xb2, 0x2c, 0xb2, 0x2c, 0xb4, 0x2c,
	0xb4, 0x2c, 0xb6, 0x2c, 0xb6, 0x2c, 0xb8, 0x2c,
	0xb8, 0x2c, 0xba, 0x2c, 0xba, 0x2c, 0xbc, 0x2c,
	0xbc, 0x2c, 0xbe, 0x2c, 0xbe, 0x2c, 0xc0, 0x2c,
	0xc0, 0x2c, 0xc2, 0x2c, 0xc2, 0x2c, 0xc4, 0x2c,
	0xc4, 0x2c, 0xc6, 0x2c, 0xc6, 0x2c, 0xc8, 0x2c,
	0xc8, 0x2c, 0xca, 0x2c, 0xca, 0x2c, 0xcc, 0x2c,
	0xcc, 0x2c, 0xce, 0x2c, 0xce, 0x2c, 0xd0, 0x2c,
	0xd0, 0x2c, 0xd2, 0x2c, 0xd2, 0x2c, 0xd4, 0x2c,
	0xd4, 0x2c, 0xd6, 0x2c, 0xd6, 0x2c, 0xd8, 0x2c,
	0xd8, 0x2c, 0xda, 0x2c, 0xda, 0x2c, 0xdc, 0x2c,
	0xdc, 0x2c, 0xde, 0x2c, 0xde, 0x2c, 0xe0, 0x2c,
	0xe0, 0x2c, 0xe2, 0x2c, 0xe2, 0x2c, 0xe4, 0x2c,
	0xe5, 0x2c, 0xe6, 0x2c, 0xe7, 0x2c, 0xe8, 0x2c,
	0xe9, 0x2c, 0xea, 0x2c, 0xeb, 0x2c, 0xec, 0x2c,
	0xed, 0x2c, 0xee, 0x2c, 0xef, 0x2c, 0xf0, 0x2c,
	0xf1, 0x2c, 0xf2, 0x2c, 0xf3, 0x2c, 0xf4, 0x2c,
	0xf5, 0x2c, 0xf6, 0x2c, 0xf7, 0x2c, 0xf8, 0x2c,
	0xf9, 0x2c, 0xfa, 0x2c, 0xfb, 0x2c, 0xfc, 0x2c,
	0xfd, 0x2c, 0xfe, 0x2c, 0xff, 0x2c, 0xa0, 0x10,
	0xa1, 0x10, 0xa2, 0x10, 0xa3, 0x10, 0xa4, 0x10,
	0xa5, 0x10, 0xa6, 0x10, 0xa7, 0x10, 0xa8, 0x10,
	0xa9, 0x10, 0xaa, 0x10, 0xab, 0x10, 0xac, 0x10,
	0xad, 0x10, 0xae, 0x10, 0xaf, 0x10, 0xb0, 0x10,
	0xb1, 0x10, 0xb2, 0x10, 0xb3, 0x10, 0xb4, 0x10,
	0xb5, 0x10, 0xb6, 0x10, 0xb7, 0x10, 0xb8, 0x10,
	0xb9, 0x10, 0xba, 0x10, 0xbb, 0x10, 0xbc, 0x10,
	0xbd, 0x10, 0xbe, 0x10, 0xbf, 0x10, 0xc0, 0x10,
	0xc1, 0x10, 0xc2, 0x10, 0xc3, 0x10, 0xc4, 0x10,
	0xc5, 0x10, 0xff, 0xff, 0x1b, 0xd2, 0x21, 0xff,
	0x22, 0xff, 0x23, 0xff, 0x24, 0xff, 0x25, 0xff,
	0x26, 0xff, 0x27, 0xff, 0x28, 0xff, 0x29, 0xff,
	0x2a, 0xff, 0x2b, 0xff, 0x2c, 0xff, 0x2d, 0xff,
	0x2e, 0xff, 0x2f, 0xff, 0x30, 0xff, 0x31, 0xff,
	0x32, 0xff, 0x33, 0xff, 0x34, 0xff, 0x35, 0xff,
	0x36, 0xff, 0x37, 0xff, 0x38, 0xff, 0x39, 0xff,
	0x3a, 0xff, 0x5b, 0xff, 0x5c, 0xff, 0x5d, 0xff,
	0x5e, 0xff, 0x5f, 0xff, 0x60, 0xff, 0x61, 0xff,
	0x62, 0xff, 0x63, 0xff, 0x64, 0xff, 0x65, 0xff,
	0x66, 0xff, 0x67, 0xff, 0x68, 0xff, 0x69, 0xff,
	0x6a, 0xff, 0x6b, 0xff, 0x6c, 0xff, 0x6d, 0xff,
	0x6e, 0xff, 0x6f, 0xff, 0x70, 0xff, 0x71, 0xff,
	0x72, 0xff, 0x73, 0xff, 0x74, 0xff, 0x75, 0xff,
	0x76, 0xff, 0x77, 0xff, 0x78, 0xff, 0x79, 0xff,
	0x7a, 0xff, 0x7b, 0xff, 0x7c, 0xff, 0x7d, 0xff,
	0x7e, 0xff, 0x7f, 0xff, 0x80, 0xff, 0x81, 0xff,
	0x82, 0xff, 0x83, 0xff, 0x84, 0xff, 0x85, 0xff,
	0x86, 0xff, 0x87, 0xff, 0x88, 0xff, 0x89, 0xff,
	0x8a, 0xff, 0x8b, 0xff, 0x8c, 0xff, 0x8d, 0xff,
	0x8e, 0xff, 0x8f, 0xff, 0x90, 0xff, 0x91, 0xff,
	0x92, 0xff, 0x93, 0xff, 0x94, 0xff, 0x95, 0xff,
	0x96, 0xff, 0x97, 0xff, 0x98, 0xff, 0x99, 0xff,
	0x9a, 0xff, 0x9b, 0xff, 0x9c, 0xff, 0x9d, 0xff,
	0x9e, 0xff, 0x9f, 0xff, 0xa0, 0xff, 0xa1, 0xff,
	0xa2, 0xff, 0xa3, 0xff, 0xa4, 0xff, 0xa5, 0xff,
	0xa6, 0xff, 0xa7, 0xff, 0xa8, 0xff, 0xa9, 0xff,
	0xaa, 0xff, 0xab, 0xff, 0xac, 0xff, 0xad, 0xff,
	0xae, 0xff, 0xaf, 0xff, 0xb0, 0xff, 0xb1, 0xff,
	0xb2, 0xff, 0xb3, 0xff, 0xb4, 0xff, 0xb5, 0xff,
	0xb6, 0xff, 0xb7, 0xff, 0xb8, 0xff, 0xb9, 0xff,
	0xba, 0xff, 0xbb, 0xff, 0xbc, 0xff, 0xbd, 0xff,
	0xbe, 0xff, 0xbf, 0xff, 0xc0, 0xff, 0xc1, 0xff,
	0xc2, 0xff, 0xc3, 0xff, 0xc4, 0xff, 0xc5, 0xff,
	0xc6, 0xff, 0xc7, 0xff, 0xc8, 0xff, 0xc9, 0xff,
	0xca, 0xff, 0xcb, 0xff, 0xcc, 0xff, 0xcd, 0xff,
	0xce, 0xff, 0xcf, 0xff, 0xd0, 0xff, 0xd1, 0xff,
	0xd2, 0xff, 0xd3, 0xff, 0xd4, 0xff, 0xd5, 0xff,
	0xd6, 0xff, 0xd7, 0xff, 0xd8, 0xff, 0xd9, 0xff,
	0xda, 0xff, 0xdb, 0xff, 0xdc, 0xff, 0xdd, 0xff,
	0xde, 0xff, 0xdf, 0xff, 0xe0, 0xff, 0xe1, 0xff,
	0xe2, 0xff, 0xe3, 0xff, 0xe4, 0xff, 0xe5, 0xff,
	0xe6, 0xff, 0xe7, 0xff, 0xe8, 0xff, 0xe9, 0xff,
	0xea, 0xff, 0xeb, 0xff, 0xec, 0xff, 0xed, 0xff,
	0xee, 0xff, 0xef, 0xff, 0xf0, 0xff, 0xf1, 0xff,
	0xf2, 0xff, 0xf3, 0xff, 0xf4, 0xff, 0xf5, 0xff,
	0xf6, 0xff, 0xf7, 0xff, 0xf8, 0xff, 0xf9, 0xff,
	0xfa, 0xff, 0xfb, 0xff, 0xfc, 0xff, 0xfd, 0xff,
	0xfe, 0xff, 0xff, 0xff
};
