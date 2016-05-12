const char str_printf[] = "[%d]\n";
const char str_pop[] = "Stack underflow\n";
const char str_push[] = "Stack overflow\n";

const char bin_sr_Break[] = {
0x41, 0x83, 0x07, 0x01, 0x49, 0x83, 0x47, 0x10, 0x01, 0x41, 0xc7, 0x47, 0x08, 0x02,
0x00, 0x00, 0x00, 0xe8, 0xa4, 0x0f, 0x00, 0x00
};

const char bin_sr_Nop[] = {
0x49, 0x8b, 0x4f, 0x10, 0x41, 0x8b, 0x47, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x8d, 
0x51, 0x01, 0x85, 0xc0, 0x49, 0x89, 0x57, 0x10, 0x75, 0x11, 0x48, 0xb8, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xc2, 0x74, 0x02, 0xeb, 0x07, 0x31, 
0xc0, 0xe8, 0x87, 0x0f, 0x00, 0x00
};

const char bin_sr_Halt[] = {
0x41, 0x83, 0x07, 0x01, 0x49, 0x83, 0x47, 0x10, 0x01, 0x41, 0xc7, 0x47, 0x08, 0x01, 
0x00, 0x00, 0x00, 0xe8, 0xa4, 0x0f, 0x00, 0x00
};

const char bin_sr_Push[] = {
0x4d, 0x85, 0xff, 0x74, 0x66, 0x41, 0x8b, 0x47, 0x04, 0x4c, 0x89, 0xfb, 0x83, 0xf8,
0x1e, 0x7f, 0x42, 0x83, 0xc0, 0x01, 0x41, 0x8b, 0x57, 0x08, 0x41, 0x89, 0x47, 0x04,
0x48, 0x98, 0x41, 0xc7, 0x44, 0x87, 0x18, 0x11, 0x11, 0x11, 0x11, 0x49, 0x8b, 0x47,
0x10, 0x41, 0x83, 0x07, 0x02, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89, 0x47,
0x10, 0x75, 0x11, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48,
0x39, 0xd0, 0x74, 0x02, 0xeb, 0x24, 0x31, 0xc0, 0xe8, 0x6a, 0x0f, 0x00, 0x00, 0xbf,
0xe6, 0x50, 0x40, 0x00, 0xe8, 0xf0, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00,
0x00, 0x00, 0x31, 0xc0, 0xe8, 0x52, 0x0f, 0x00, 0x00, 0xe8, 0x67, 0xff, 0xff, 0xff
};

const char bin_sr_Print[] = {
0x4d, 0x85, 0xff, 0x53, 0x74, 0x6e, 0x49, 0x63, 0x47, 0x04, 0x4c, 0x89, 0xfb, 0x85,
0xc0, 0x78, 0x4b, 0x8d, 0x50, 0xff, 0x41, 0x8b, 0x74, 0x87, 0x18, 0xbf, 0x00, 0x00,
0x00, 0x00, 0x31, 0xc0, 0x41, 0x89, 0x57, 0x04, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x49,
0x8b, 0x4f, 0x10, 0x41, 0x8b, 0x47, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x8d, 0x51,
0x01, 0x85, 0xc0, 0x49, 0x89, 0x57, 0x10, 0x75, 0x14, 0x48, 0xb8, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xc2, 0x74, 0x05, 0x31, 0xc0, 0x5b, 0xeb,
0x24, 0x31, 0xc0, 0xe8, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x00, 0xe8,
0x00, 0x00, 0x00, 0x00, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8,
0x00, 0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x00, 0x00
};

const char bin_sr_Jne[] = {
0x4d, 0x85, 0xff, 0x74, 0x6e, 0x49, 0x63, 0x47, 0x04, 0x4c, 0x89, 0xfb, 0x85, 0xc0, 
0x78, 0x4b, 0x8d, 0x50, 0xff, 0x41, 0x8b, 0x44, 0x87, 0x18, 0x41, 0x89, 0x57, 0x04, 
0x85, 0xc0, 0x75, 0x28, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x83, 0x07, 0x02, 0x48, 0x83,
0xc0, 0x01, 0x41, 0x83, 0x7f, 0x08, 0x00, 0x49, 0x89, 0x47, 0x10, 0x75, 0x1d, 0x48,
0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xd0, 0x74, 0x0e,
0xeb, 0x30, 0x41, 0x81, 0x07, 0x13, 0x11, 0x11, 0x11, 0x49, 0x83, 0x47, 0x10, 0x01,
0x31, 0xc0, 0xe8, 0x62, 0x0f, 0x00, 0x00, 0xbf, 0xe5, 0x50, 0x40, 0x00, 0xe8, 0xe8,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x4a,
0x0f, 0x00, 0x00, 0xe8, 0x5f, 0xff, 0xff, 0xff
};

const char bin_sr_Swap[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0xa5, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c, 
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x63, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0xff, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x79, 0x18, 0x74, 0x4d,
0x8d, 0x70, 0xfe, 0x83, 0xfe, 0x1e, 0x41, 0x89, 0x77, 0x04, 0x44, 0x8b, 0x41, 0x14,
0x7f, 0x5c, 0x83, 0xfa, 0x1e, 0x41, 0x89, 0x57, 0x04, 0x89, 0x79, 0x14, 0x7f, 0x50,
0x41, 0x89, 0x47, 0x04, 0x44, 0x89, 0x41, 0x18, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x8b,
0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89,
0x47, 0x10, 0x75, 0x29, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
0x48, 0x39, 0xd0, 0x74, 0x1a, 0xeb, 0x3c, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0x8c,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x2e,
0x0f, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x27, 0x0f, 0x00, 0x00, 0xbf, 0xe6, 0x50, 0x40,
0x00, 0xe8, 0x6d, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31,
0xc0, 0xe8, 0x0f, 0x0f, 0x00, 0x00, 0xe8, 0x0a, 0xff, 0xff, 0xff
};

const char bin_sr_Dup[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x94, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x71, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0x1e, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x71, 0x18, 0x7f, 0x3c,
0x83, 0xf8, 0x1e, 0x41, 0x89, 0x47, 0x04, 0x7f, 0x33, 0x83, 0xc0, 0x01, 0x41, 0x89,
0x47, 0x04, 0x89, 0x71, 0x1c, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x8b, 0x57, 0x08, 0x41,
0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89, 0x47, 0x10, 0x75,
0x29, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xd0,
0x74, 0x1a, 0xeb, 0x3c, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xdd, 0xf3, 0xff, 0xff,
0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x3f, 0x0f, 0x00, 0x00,
0x31, 0xc0, 0xe8, 0x38, 0x0f, 0x00, 0x00, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0xbe,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x20,
0x0f, 0x00, 0x00, 0xe8, 0x1b, 0xff, 0xff, 0xff
};

const char bin_sr_Je[] = {
0x4d, 0x85, 0xff, 0x74, 0x6e, 0x49, 0x63, 0x47, 0x04, 0x4c, 0x89, 0xfb, 0x85, 0xc0,
0x78, 0x4b, 0x8d, 0x50, 0xff, 0x41, 0x8b, 0x44, 0x87, 0x18, 0x41, 0x89, 0x57, 0x04,
0x85, 0xc0, 0x74, 0x28, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x83, 0x07, 0x02, 0x48, 0x83,
0xc0, 0x01, 0x41, 0x83, 0x7f, 0x08, 0x00, 0x49, 0x89, 0x47, 0x10, 0x75, 0x1d, 0x48,
0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xd0, 0x74, 0x0e,
0xeb, 0x30, 0x41, 0x81, 0x07, 0x13, 0x11, 0x11, 0x11, 0x49, 0x83, 0x47, 0x10, 0x01,
0x31, 0xc0, 0xe8, 0x62, 0x0f, 0x00, 0x00, 0xbf, 0xe5, 0x50, 0x40, 0x00, 0xe8, 0xe8,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x4a,
0x0f, 0x00, 0x00, 0xe8, 0x5f, 0xff, 0xff, 0xff
};

const char bin_sr_Inc[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x8b, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x68, 0x48, 0x63, 0xd0, 0x8d, 0x48, 0xff, 0x49, 0x8d,
0x34, 0x97, 0x41, 0x89, 0x4f, 0x04, 0x83, 0xf9, 0x1e, 0x8b, 0x7e, 0x18, 0x8d, 0x57,
0x01, 0x7f, 0x37, 0x41, 0x89, 0x47, 0x04, 0x89, 0x56, 0x18, 0x49, 0x8b, 0x47, 0x10,
0x41, 0x8b, 0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2,
0x49, 0x89, 0x47, 0x10, 0x75, 0x11, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0x7f, 0x48, 0x39, 0xd0, 0x74, 0x02, 0xeb, 0x3c, 0x31, 0xc0, 0xe8, 0x59, 0x0f,
0x00, 0x00, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xdf, 0xf3, 0xff, 0xff, 0xc7, 0x43,
0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x41, 0x0f, 0x00, 0x00, 0xbf, 0xd6,
0x50, 0x40, 0x00, 0xe8, 0xc7, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00,
0x00, 0x31, 0xc0, 0xe8, 0x29, 0x0f, 0x00, 0x00, 0xe8, 0x24, 0xff, 0xff, 0xff
};

const char bin_sr_Add[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x7f, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x55, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0xff, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x71, 0x18, 0x74, 0x3f,
0x83, 0xe8, 0x02, 0x41, 0x89, 0x47, 0x04, 0x03, 0x71, 0x14, 0x83, 0xf8, 0x1e, 0x7f,
0x54, 0x41, 0x89, 0x57, 0x04, 0x89, 0x71, 0x14, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x8b,
0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89,
0x47, 0x10, 0x75, 0x29, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
0x48, 0x39, 0xd0, 0x74, 0x1a, 0xeb, 0x3c, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0xda,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x3c,
0x0f, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x35, 0x0f, 0x00, 0x00, 0xe8, 0x30, 0xff, 0xff,
0xff, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xb6, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08,
0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x18, 0x0f, 0x00, 0x00
};

const char bin_sr_Sub[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x7f, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x55, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0xff, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x71, 0x18, 0x74, 0x3f,
0x83, 0xe8, 0x02, 0x41, 0x89, 0x47, 0x04, 0x2b, 0x71, 0x14, 0x83, 0xf8, 0x1e, 0x7f,
0x54, 0x41, 0x89, 0x57, 0x04, 0x89, 0x71, 0x14, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x8b,
0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89,
0x47, 0x10, 0x75, 0x29, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
0x48, 0x39, 0xd0, 0x74, 0x1a, 0xeb, 0x3c, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0xda,
0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x3c,
0x0f, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x35, 0x0f, 0x00, 0x00, 0xe8, 0x30, 0xff, 0xff,
0xff, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xb6, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08,
0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x18, 0x0f, 0x00, 0x00
};

const char bin_sr_Mul[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x80, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x56, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0xff, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x71, 0x18, 0x74, 0x40,
0x83, 0xe8, 0x02, 0x41, 0x89, 0x47, 0x04, 0x0f, 0xaf, 0x71, 0x14, 0x83, 0xf8, 0x1e,
0x7f, 0x54, 0x41, 0x89, 0x57, 0x04, 0x89, 0x71, 0x14, 0x49, 0x8b, 0x47, 0x10, 0x41,
0x8b, 0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49,
0x89, 0x47, 0x10, 0x75, 0x29, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x7f, 0x48, 0x39, 0xd0, 0x74, 0x1a, 0xeb, 0x3c, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8,
0xd9, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8,
0x3b, 0x0f, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x34, 0x0f, 0x00, 0x00, 0xe8, 0x2f, 0xff,
0xff, 0xff, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xb5, 0xf3, 0xff, 0xff, 0xc7, 0x43,
0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x17, 0x0f, 0x00, 0x00
};

const char bin_sr_Rand[] = {
0xe8, 0x8a, 0xf4, 0xff, 0xff, 0x4d, 0x85, 0xff, 0x74, 0x63, 0x41, 0x8b, 0x57, 0x04,
0x4c, 0x89, 0xfb, 0x83, 0xfa, 0x1e, 0x7f, 0x3f, 0x83, 0xc2, 0x01, 0x41, 0x89, 0x57,
0x04, 0x48, 0x63, 0xd2, 0x41, 0x89, 0x44, 0x97, 0x18, 0x49, 0x8b, 0x47, 0x10, 0x41,
0x8b, 0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49,
0x89, 0x47, 0x10, 0x75, 0x11, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x7f, 0x48, 0x39, 0xd0, 0x74, 0x02, 0xeb, 0x24, 0x31, 0xc0, 0xe8, 0x68, 0x0f, 0x00,
0x00, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xee, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08,
0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x50, 0x0f, 0x00, 0x00, 0xe8, 0x65, 0xff,
0xff, 0xff
};

const char bin_sr_Dec[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x8b, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x68, 0x48, 0x63, 0xd0, 0x8d, 0x48, 0xff, 0x49, 0x8d,
0x34, 0x97, 0x41, 0x89, 0x4f, 0x04, 0x83, 0xf9, 0x1e, 0x8b, 0x7e, 0x18, 0x8d, 0x57,
0xff, 0x7f, 0x37, 0x41, 0x89, 0x47, 0x04, 0x89, 0x56, 0x18, 0x49, 0x8b, 0x47, 0x10,
0x41, 0x8b, 0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2,
0x49, 0x89, 0x47, 0x10, 0x75, 0x11, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0x7f, 0x48, 0x39, 0xd0, 0x74, 0x02, 0xeb, 0x3c, 0x31, 0xc0, 0xe8, 0x59, 0x0f,
0x00, 0x00, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0x9f, 0xf3, 0xff, 0xff, 0xc7, 0x43,
0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x41, 0x0f, 0x00, 0x00, 0xbf, 0xd6,
0x50, 0x40, 0x00, 0xe8, 0x87, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02, 0x00, 0x00,
0x00, 0x31, 0xc0, 0xe8, 0x29, 0x0f, 0x00, 0x00, 0xe8, 0x24, 0xff, 0xff, 0xff
};

const char bin_sr_Drop[] = {
0x4d, 0x85, 0xff, 0x74, 0x5a, 0x41, 0x8b, 0x47, 0x04, 0x4c, 0x89, 0xfb, 0x85, 0xc0,
0x78, 0x37, 0x83, 0xe8, 0x01, 0x41, 0x8b, 0x57, 0x08, 0x41, 0x83, 0x07, 0x01, 0x41,
0x89, 0x47, 0x04, 0x49, 0x8b, 0x47, 0x10, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49,
0x89, 0x47, 0x10, 0x75, 0x11, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x7f, 0x48, 0x39, 0xd0, 0x74, 0x02, 0x31, 0xc0, 0xeb, 0x22, 0xe8, 0x76, 0x0f, 0x00,
0x00, 0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0xfc, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08,
0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x5e, 0x0f, 0x00, 0x00, 0xe8, 0x59, 0xff,
0xff, 0xff
};

const char bin_sr_Over[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x94, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x47, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc0, 0x78, 0x6a, 0x8d, 0x50, 0xff, 0x48, 0x63, 0xc8, 0x49, 0x8d,
0x0c, 0x8f, 0x83, 0xfa, 0xff, 0x41, 0x89, 0x57, 0x04, 0x8b, 0x69, 0x18, 0x74, 0x54,
0x83, 0xe8, 0x02, 0x4c, 0x89, 0xff, 0x41, 0x89, 0x47, 0x04, 0x44, 0x8b, 0x61, 0x14,
0x44, 0x89, 0xe6, 0xe8, 0x9c, 0x0f, 0x00, 0x00, 0x89, 0xee, 0x4c, 0x89, 0xff, 0xe8,
0x92, 0x0f, 0x00, 0x00, 0x44, 0x89, 0xe6, 0x4c, 0x89, 0xff, 0xe8, 0x87, 0x0f, 0x00,
0x00, 0x49, 0x8b, 0x77, 0x10, 0x41, 0x8b, 0x47, 0x08, 0x41, 0x83, 0x07, 0x01, 0x48,
0x8d, 0x56, 0x01, 0x85, 0xc0, 0x49, 0x89, 0x57, 0x10, 0x75, 0x29, 0x48, 0xb8, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xc2, 0x74, 0x1a, 0xeb, 0x24,
0xbf, 0xe5, 0x50, 0x40, 0x00, 0xe8, 0x7f, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02,
0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x21, 0x0f, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x1a,
0x0f, 0x00, 0x00, 0xe8, 0x15, 0xff, 0xff, 0xff
};

const char bin_sr_Mod[] = {
0x4d, 0x85, 0xff, 0x0f, 0x84, 0x9b, 0x00, 0x00, 0x00, 0x41, 0x8b, 0x4f, 0x04, 0x4c,
0x89, 0xfb, 0x85, 0xc9, 0x78, 0x78, 0x8d, 0x71, 0xff, 0x48, 0x63, 0xc1, 0x49, 0x8d,
0x3c, 0x87, 0x83, 0xfe, 0xff, 0x41, 0x89, 0x77, 0x04, 0x8b, 0x47, 0x18, 0x74, 0x62,
0x83, 0xe9, 0x02, 0x41, 0x89, 0x4f, 0x04, 0x44, 0x8b, 0x47, 0x14, 0x45, 0x85, 0xc0,
0x74, 0x44, 0x31, 0xd2, 0x41, 0xf7, 0xf0, 0x83, 0xf9, 0x1e, 0x7f, 0x30, 0x41, 0x89,
0x77, 0x04, 0x89, 0x57, 0x14, 0x49, 0x8b, 0x47, 0x10, 0x41, 0x8b, 0x57, 0x08, 0x41,
0x83, 0x07, 0x01, 0x48, 0x83, 0xc0, 0x01, 0x85, 0xd2, 0x49, 0x89, 0x47, 0x10, 0x75,
0x22, 0x48, 0xba, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x48, 0x39, 0xd0,
0x74, 0x13, 0xeb, 0x35, 0xbf, 0xe6, 0x50, 0x40, 0x00, 0xe8, 0xcf, 0xf3, 0xff, 0xff,
0xc7, 0x43, 0x08, 0x02, 0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x31, 0x0f, 0x00, 0x00,
0xbf, 0xd6, 0x50, 0x40, 0x00, 0xe8, 0xb7, 0xf3, 0xff, 0xff, 0xc7, 0x43, 0x08, 0x02,
0x00, 0x00, 0x00, 0x31, 0xc0, 0xe8, 0x19, 0x0f, 0x00, 0x00, 0xe8, 0x14, 0xff, 0xff,
0xff
};

const char bin_sr_Jump[] = {
0x41, 0x81, 0x07, 0x00, 0x00, 0x00, 0x00, 0x49, 0x83, 0x47, 0x10, 0x01, 0x31, 0xc0,
0xe8, 0x00, 0x00, 0x00, 0x00
};