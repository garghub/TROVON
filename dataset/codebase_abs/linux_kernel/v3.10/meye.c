static void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
unsigned long V_3 ;
V_1 = F_2 ( V_1 ) ;
V_2 = F_3 ( V_1 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , V_1 ) ;
V_3 = ( unsigned long ) V_2 ;
while ( V_1 > 0 ) {
F_4 ( F_5 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
}
return V_2 ;
}
static void F_6 ( void * V_2 , unsigned long V_1 )
{
unsigned long V_3 ;
if ( V_2 ) {
V_3 = ( unsigned long ) V_2 ;
while ( ( long ) V_1 > 0 ) {
F_7 ( F_5 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
F_8 ( V_2 ) ;
}
}
static int F_9 ( void )
{
T_1 * V_5 ;
int V_6 ;
memset ( V_7 . V_8 , 0 , sizeof( V_7 . V_8 ) ) ;
if ( F_10 ( & V_7 . V_9 -> V_10 , F_11 ( 32 ) ) )
return - 1 ;
V_7 . V_11 = F_12 ( & V_7 . V_9 -> V_10 ,
V_4 ,
& V_7 . V_12 ,
V_13 ) ;
if ( ! V_7 . V_11 ) {
V_7 . V_12 = 0 ;
return - 1 ;
}
V_5 = V_7 . V_11 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
T_2 V_15 ;
V_7 . V_8 [ V_6 ] = F_12 ( & V_7 . V_9 -> V_10 ,
V_4 ,
& V_15 ,
V_13 ) ;
if ( ! V_7 . V_8 [ V_6 ] ) {
int V_16 ;
V_5 = V_7 . V_11 ;
for ( V_16 = 0 ; V_16 < V_6 ; ++ V_16 ) {
V_15 = ( T_2 ) * V_5 ;
F_13 ( & V_7 . V_9 -> V_10 ,
V_4 ,
V_7 . V_8 [ V_16 ] , V_15 ) ;
V_5 ++ ;
}
F_13 ( & V_7 . V_9 -> V_10 ,
V_4 ,
V_7 . V_11 ,
V_7 . V_12 ) ;
V_7 . V_11 = NULL ;
V_7 . V_12 = 0 ;
return - 1 ;
}
* V_5 = ( T_1 ) V_15 ;
V_5 ++ ;
}
return 0 ;
}
static void F_14 ( void )
{
T_1 * V_5 ;
int V_6 ;
V_5 = V_7 . V_11 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
T_2 V_15 = ( T_2 ) * V_5 ;
if ( V_7 . V_8 [ V_6 ] )
F_13 ( & V_7 . V_9 -> V_10 ,
V_4 ,
V_7 . V_8 [ V_6 ] , V_15 ) ;
V_5 ++ ;
}
if ( V_7 . V_11 )
F_13 ( & V_7 . V_9 -> V_10 ,
V_4 ,
V_7 . V_11 ,
V_7 . V_12 ) ;
memset ( V_7 . V_8 , 0 , sizeof( V_7 . V_8 ) ) ;
V_7 . V_11 = NULL ;
V_7 . V_12 = 0 ;
}
static void F_15 ( T_3 * V_17 , int V_18 , int V_1 , int V_19 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < ( V_1 / V_4 ) * V_4 ; V_6 += V_4 ) {
memcpy ( V_17 + V_6 , V_7 . V_8 [ V_18 ++ ] , V_4 ) ;
if ( V_18 >= V_19 )
V_18 = 0 ;
}
memcpy ( V_17 + V_6 , V_7 . V_8 [ V_18 ] , V_1 % V_4 ) ;
}
static T_4 * F_16 ( int * V_20 , int V_21 )
{
static T_4 V_22 [] [ 70 ] = { {
0xdbff , 0x4300 , 0xff00 , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff ,
0xdbff , 0x4300 , 0xff01 , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff ,
} ,
{
0xdbff , 0x4300 , 0x5000 , 0x3c37 , 0x3c46 , 0x5032 , 0x4146 , 0x5a46 ,
0x5055 , 0x785f , 0x82c8 , 0x6e78 , 0x786e , 0xaff5 , 0x91b9 , 0xffc8 ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff ,
0xdbff , 0x4300 , 0x5501 , 0x5a5a , 0x6978 , 0xeb78 , 0x8282 , 0xffeb ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff , 0xffff ,
0xffff , 0xffff , 0xffff ,
} ,
{
0xdbff , 0x4300 , 0x2800 , 0x1e1c , 0x1e23 , 0x2819 , 0x2123 , 0x2d23 ,
0x282b , 0x3c30 , 0x4164 , 0x373c , 0x3c37 , 0x587b , 0x495d , 0x9164 ,
0x9980 , 0x8f96 , 0x8c80 , 0xa08a , 0xe6b4 , 0xa0c3 , 0xdaaa , 0x8aad ,
0xc88c , 0xcbff , 0xeeda , 0xfff5 , 0xffff , 0xc19b , 0xffff , 0xfaff ,
0xe6ff , 0xfffd , 0xfff8 ,
0xdbff , 0x4300 , 0x2b01 , 0x2d2d , 0x353c , 0x763c , 0x4141 , 0xf876 ,
0x8ca5 , 0xf8a5 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 ,
0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 ,
0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 , 0xf8f8 ,
0xf8f8 , 0xf8f8 , 0xfff8 ,
} ,
{
0xdbff , 0x4300 , 0x1b00 , 0x1412 , 0x1417 , 0x1b11 , 0x1617 , 0x1e17 ,
0x1b1c , 0x2820 , 0x2b42 , 0x2528 , 0x2825 , 0x3a51 , 0x303d , 0x6042 ,
0x6555 , 0x5f64 , 0x5d55 , 0x6a5b , 0x9978 , 0x6a81 , 0x9071 , 0x5b73 ,
0x855d , 0x86b5 , 0x9e90 , 0xaba3 , 0xabad , 0x8067 , 0xc9bc , 0xa6ba ,
0x99c7 , 0xaba8 , 0xffa4 ,
0xdbff , 0x4300 , 0x1c01 , 0x1e1e , 0x2328 , 0x4e28 , 0x2b2b , 0xa44e ,
0x5d6e , 0xa46e , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 ,
0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 ,
0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 , 0xa4a4 ,
0xa4a4 , 0xa4a4 , 0xffa4 ,
} ,
{
0xdbff , 0x4300 , 0x1400 , 0x0f0e , 0x0f12 , 0x140d , 0x1012 , 0x1712 ,
0x1415 , 0x1e18 , 0x2132 , 0x1c1e , 0x1e1c , 0x2c3d , 0x242e , 0x4932 ,
0x4c40 , 0x474b , 0x4640 , 0x5045 , 0x735a , 0x5062 , 0x6d55 , 0x4556 ,
0x6446 , 0x6588 , 0x776d , 0x817b , 0x8182 , 0x604e , 0x978d , 0x7d8c ,
0x7396 , 0x817e , 0xff7c ,
0xdbff , 0x4300 , 0x1501 , 0x1717 , 0x1a1e , 0x3b1e , 0x2121 , 0x7c3b ,
0x4653 , 0x7c53 , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c ,
0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c ,
0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c , 0x7c7c ,
0x7c7c , 0x7c7c , 0xff7c ,
} ,
{
0xdbff , 0x4300 , 0x1000 , 0x0c0b , 0x0c0e , 0x100a , 0x0d0e , 0x120e ,
0x1011 , 0x1813 , 0x1a28 , 0x1618 , 0x1816 , 0x2331 , 0x1d25 , 0x3a28 ,
0x3d33 , 0x393c , 0x3833 , 0x4037 , 0x5c48 , 0x404e , 0x5744 , 0x3745 ,
0x5038 , 0x516d , 0x5f57 , 0x6762 , 0x6768 , 0x4d3e , 0x7971 , 0x6470 ,
0x5c78 , 0x6765 , 0xff63 ,
0xdbff , 0x4300 , 0x1101 , 0x1212 , 0x1518 , 0x2f18 , 0x1a1a , 0x632f ,
0x3842 , 0x6342 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 ,
0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 ,
0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 , 0x6363 ,
0x6363 , 0x6363 , 0xff63 ,
} ,
{
0xdbff , 0x4300 , 0x0d00 , 0x0a09 , 0x0a0b , 0x0d08 , 0x0a0b , 0x0e0b ,
0x0d0e , 0x130f , 0x1520 , 0x1213 , 0x1312 , 0x1c27 , 0x171e , 0x2e20 ,
0x3129 , 0x2e30 , 0x2d29 , 0x332c , 0x4a3a , 0x333e , 0x4636 , 0x2c37 ,
0x402d , 0x4157 , 0x4c46 , 0x524e , 0x5253 , 0x3e32 , 0x615a , 0x505a ,
0x4a60 , 0x5251 , 0xff4f ,
0xdbff , 0x4300 , 0x0e01 , 0x0e0e , 0x1113 , 0x2613 , 0x1515 , 0x4f26 ,
0x2d35 , 0x4f35 , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f ,
0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f ,
0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f , 0x4f4f ,
0x4f4f , 0x4f4f , 0xff4f ,
} ,
{
0xdbff , 0x4300 , 0x0a00 , 0x0707 , 0x0708 , 0x0a06 , 0x0808 , 0x0b08 ,
0x0a0a , 0x0e0b , 0x1018 , 0x0d0e , 0x0e0d , 0x151d , 0x1116 , 0x2318 ,
0x251f , 0x2224 , 0x221f , 0x2621 , 0x372b , 0x262f , 0x3429 , 0x2129 ,
0x3022 , 0x3141 , 0x3934 , 0x3e3b , 0x3e3e , 0x2e25 , 0x4944 , 0x3c43 ,
0x3748 , 0x3e3d , 0xff3b ,
0xdbff , 0x4300 , 0x0a01 , 0x0b0b , 0x0d0e , 0x1c0e , 0x1010 , 0x3b1c ,
0x2228 , 0x3b28 , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b ,
0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b ,
0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b , 0x3b3b ,
0x3b3b , 0x3b3b , 0xff3b ,
} ,
{
0xdbff , 0x4300 , 0x0600 , 0x0504 , 0x0506 , 0x0604 , 0x0506 , 0x0706 ,
0x0607 , 0x0a08 , 0x0a10 , 0x090a , 0x0a09 , 0x0e14 , 0x0c0f , 0x1710 ,
0x1814 , 0x1718 , 0x1614 , 0x1a16 , 0x251d , 0x1a1f , 0x231b , 0x161c ,
0x2016 , 0x202c , 0x2623 , 0x2927 , 0x292a , 0x1f19 , 0x302d , 0x282d ,
0x2530 , 0x2928 , 0xff28 ,
0xdbff , 0x4300 , 0x0701 , 0x0707 , 0x080a , 0x130a , 0x0a0a , 0x2813 ,
0x161a , 0x281a , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 ,
0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 ,
0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 , 0x2828 ,
0x2828 , 0x2828 , 0xff28 ,
} ,
{
0xdbff , 0x4300 , 0x0300 , 0x0202 , 0x0203 , 0x0302 , 0x0303 , 0x0403 ,
0x0303 , 0x0504 , 0x0508 , 0x0405 , 0x0504 , 0x070a , 0x0607 , 0x0c08 ,
0x0c0a , 0x0b0c , 0x0b0a , 0x0d0b , 0x120e , 0x0d10 , 0x110e , 0x0b0e ,
0x100b , 0x1016 , 0x1311 , 0x1514 , 0x1515 , 0x0f0c , 0x1817 , 0x1416 ,
0x1218 , 0x1514 , 0xff14 ,
0xdbff , 0x4300 , 0x0301 , 0x0404 , 0x0405 , 0x0905 , 0x0505 , 0x1409 ,
0x0b0d , 0x140d , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 ,
0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 ,
0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 , 0x1414 ,
0x1414 , 0x1414 , 0xff14 ,
} ,
{
0xdbff , 0x4300 , 0x0100 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0xff01 ,
0xdbff , 0x4300 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0101 , 0x0101 , 0xff01 ,
} } ;
if ( V_21 < 0 || V_21 > 10 ) {
F_17 ( V_23
L_1 , V_21 ) ;
V_21 = 8 ;
}
* V_20 = F_18 ( V_22 [ V_21 ] ) ;
return V_22 [ V_21 ] ;
}
static T_4 * F_19 ( int * V_20 )
{
static T_4 V_24 [] = {
0xC4FF , 0xB500 , 0x0010 , 0x0102 , 0x0303 , 0x0402 , 0x0503 , 0x0405 ,
0x0004 , 0x0100 , 0x017D , 0x0302 , 0x0400 , 0x0511 , 0x2112 , 0x4131 ,
0x1306 , 0x6151 , 0x2207 , 0x1471 , 0x8132 , 0xA191 , 0x2308 , 0xB142 ,
0x15C1 , 0xD152 , 0x24F0 , 0x6233 , 0x8272 , 0x0A09 , 0x1716 , 0x1918 ,
0x251A , 0x2726 , 0x2928 , 0x342A , 0x3635 , 0x3837 , 0x3A39 , 0x4443 ,
0x4645 , 0x4847 , 0x4A49 , 0x5453 , 0x5655 , 0x5857 , 0x5A59 , 0x6463 ,
0x6665 , 0x6867 , 0x6A69 , 0x7473 , 0x7675 , 0x7877 , 0x7A79 , 0x8483 ,
0x8685 , 0x8887 , 0x8A89 , 0x9392 , 0x9594 , 0x9796 , 0x9998 , 0xA29A ,
0xA4A3 , 0xA6A5 , 0xA8A7 , 0xAAA9 , 0xB3B2 , 0xB5B4 , 0xB7B6 , 0xB9B8 ,
0xC2BA , 0xC4C3 , 0xC6C5 , 0xC8C7 , 0xCAC9 , 0xD3D2 , 0xD5D4 , 0xD7D6 ,
0xD9D8 , 0xE1DA , 0xE3E2 , 0xE5E4 , 0xE7E6 , 0xE9E8 , 0xF1EA , 0xF3F2 ,
0xF5F4 , 0xF7F6 , 0xF9F8 , 0xFFFA ,
0xC4FF , 0xB500 , 0x0011 , 0x0102 , 0x0402 , 0x0304 , 0x0704 , 0x0405 ,
0x0004 , 0x0201 , 0x0077 , 0x0201 , 0x1103 , 0x0504 , 0x3121 , 0x1206 ,
0x5141 , 0x6107 , 0x1371 , 0x3222 , 0x0881 , 0x4214 , 0xA191 , 0xC1B1 ,
0x2309 , 0x5233 , 0x15F0 , 0x7262 , 0x0AD1 , 0x2416 , 0xE134 , 0xF125 ,
0x1817 , 0x1A19 , 0x2726 , 0x2928 , 0x352A , 0x3736 , 0x3938 , 0x433A ,
0x4544 , 0x4746 , 0x4948 , 0x534A , 0x5554 , 0x5756 , 0x5958 , 0x635A ,
0x6564 , 0x6766 , 0x6968 , 0x736A , 0x7574 , 0x7776 , 0x7978 , 0x827A ,
0x8483 , 0x8685 , 0x8887 , 0x8A89 , 0x9392 , 0x9594 , 0x9796 , 0x9998 ,
0xA29A , 0xA4A3 , 0xA6A5 , 0xA8A7 , 0xAAA9 , 0xB3B2 , 0xB5B4 , 0xB7B6 ,
0xB9B8 , 0xC2BA , 0xC4C3 , 0xC6C5 , 0xC8C7 , 0xCAC9 , 0xD3D2 , 0xD5D4 ,
0xD7D6 , 0xD9D8 , 0xE2DA , 0xE4E3 , 0xE6E5 , 0xE8E7 , 0xEAE9 , 0xF3F2 ,
0xF5F4 , 0xF7F6 , 0xF9F8 , 0xFFFA ,
0xC4FF , 0x1F00 , 0x0000 , 0x0501 , 0x0101 , 0x0101 , 0x0101 , 0x0000 ,
0x0000 , 0x0000 , 0x0000 , 0x0201 , 0x0403 , 0x0605 , 0x0807 , 0x0A09 ,
0xFF0B ,
0xC4FF , 0x1F00 , 0x0001 , 0x0103 , 0x0101 , 0x0101 , 0x0101 , 0x0101 ,
0x0000 , 0x0000 , 0x0000 , 0x0201 , 0x0403 , 0x0605 , 0x0807 , 0x0A09 ,
0xFF0B
} ;
* V_20 = F_18 ( V_24 ) ;
return V_24 ;
}
static inline int F_20 ( void )
{
return V_7 . V_25 . V_26 ? 320 : 640 ;
}
static inline int F_21 ( void )
{
return V_7 . V_25 . V_26 ? 240 : 480 ;
}
static void F_22 ( int V_27 )
{
T_1 V_28 ;
int V_6 ;
if ( V_27 == V_29 ) {
for ( V_6 = 0 ; V_6 < V_30 ; V_6 ++ ) {
V_28 = F_23 ( V_7 . V_31 +
V_32 ) ;
if ( ! ( V_28 & V_33 ) ) {
F_17 ( V_23 L_2 ) ;
return;
}
if ( V_28 & V_34 )
return;
F_24 ( 1 ) ;
}
} else if ( V_27 > 0x80 ) {
T_1 V_35 = ( V_27 < 0x100 ) ? V_36
: V_37 ;
for ( V_6 = 0 ; V_6 < V_30 ; V_6 ++ ) {
V_28 = F_23 ( V_7 . V_31 + V_38 ) ;
if ( V_28 & V_35 )
return;
F_24 ( 1 ) ;
}
} else
return;
F_17 ( V_23
L_3 ,
V_27 , V_28 ) ;
}
static inline void F_25 ( int V_27 , T_1 V_39 )
{
F_22 ( V_27 ) ;
F_26 ( V_39 , V_7 . V_31 + V_27 ) ;
}
static inline T_1 F_27 ( int V_27 )
{
F_22 ( V_27 ) ;
return F_23 ( V_7 . V_31 + V_27 ) ;
}
static inline int F_28 ( T_1 V_27 , T_1 V_39 )
{
int V_40 = 10 ;
while ( -- V_40 && F_27 ( V_27 ) != V_39 )
F_24 ( 1 ) ;
return V_40 ;
}
static void F_29 ( void )
{
F_25 ( V_41 , V_7 . V_25 . V_26 ) ;
F_25 ( V_42 , F_20 () ) ;
F_25 ( V_43 , F_21 () ) ;
F_25 ( V_44 , F_20 () ) ;
F_25 ( V_45 , F_21 () ) ;
F_28 ( V_38 , V_46 ) ;
}
static void F_30 ( void )
{
F_25 ( V_47 , V_7 . V_25 . V_48 ) ;
}
static void F_31 ( void )
{
int V_6 ;
int V_20 ;
T_4 * V_24 ;
V_24 = F_19 ( & V_20 ) ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ )
F_26 ( V_24 [ V_6 ] , V_7 . V_31 + V_49 ) ;
V_24 = F_16 ( & V_20 , V_7 . V_25 . V_21 ) ;
for ( V_6 = 0 ; V_6 < V_20 ; V_6 ++ )
F_26 ( V_24 [ V_6 ] , V_7 . V_31 + V_49 ) ;
}
static void F_32 ( T_3 V_50 )
{
F_25 ( V_51 , 5 ) ;
F_25 ( V_52 , 0x1f ) ;
F_25 ( V_53 , 1 ) ;
F_25 ( V_54 , 0xa0 ) ;
F_25 ( V_55 , V_50 ) ;
F_25 ( V_56 , F_21 () ) ;
F_25 ( V_57 , F_20 () ) ;
F_25 ( V_58 , 0x1b ) ;
F_25 ( V_59 , 0xFFFF ) ;
F_25 ( V_60 , 0xFFFF ) ;
F_25 ( V_61 , 0xC ) ;
F_25 ( V_62 , 0 ) ;
F_25 ( V_63 , 0x601 ) ;
F_25 ( V_64 , 0x1502 ) ;
F_25 ( V_65 , 0x1503 ) ;
F_25 ( V_66 , 0x1596 ) ;
F_25 ( V_67 , 0x0ed0 ) ;
F_31 () ;
}
static void F_33 ( T_2 V_68 )
{
int V_6 ;
F_25 ( V_69 , ( T_1 ) V_68 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
F_25 ( F_34 ( V_6 ) , 0 ) ;
V_7 . V_70 = 0 ;
}
static int F_35 ( void )
{
if ( ! V_7 . V_12 )
if ( F_9 () )
return - 1 ;
return 0 ;
}
static void F_36 ( void )
{
if ( V_7 . V_12 ) {
F_33 ( 0 ) ;
F_14 () ;
}
}
static void F_37 ( void )
{
int V_6 , V_16 ;
V_7 . V_71 = V_72 ;
if ( ! ( F_27 ( V_38 ) & V_73 ) )
return;
for ( V_6 = 0 ; V_6 < 20 ; ++ V_6 ) {
F_25 ( V_74 , V_75 ) ;
F_28 ( V_74 , 0 ) ;
for ( V_16 = 0 ; V_16 < 100 ; ++ V_16 ) {
if ( F_28 ( V_38 ,
V_46 ) )
return;
F_38 ( 1 ) ;
}
F_17 ( V_76 L_4 ) ;
F_25 ( V_77 , V_78 ) ;
F_38 ( 250 ) ;
}
F_17 ( V_76 L_5 ) ;
}
static T_1 F_39 ( void )
{
T_1 V_39 ;
V_39 = F_27 ( F_34 ( V_7 . V_70 ) ) ;
return V_39 ;
}
static void F_40 ( void )
{
F_25 ( F_34 ( V_7 . V_70 ) , 0 ) ;
V_7 . V_70 ++ ;
V_7 . V_70 %= 4 ;
}
static void F_41 ( T_1 V_39 , T_3 * V_17 , int V_1 )
{
int V_79 ;
V_79 = ( V_39 >> 17 ) & 0x3FF ;
F_15 ( V_17 , V_79 , V_1 , V_14 ) ;
}
static int F_42 ( T_1 V_39 , T_3 * V_17 , int V_1 )
{
int V_80 , V_81 , V_82 ;
int V_83 ;
int V_6 ;
V_80 = ( V_39 >> 19 ) & 0xFF ;
V_81 = ( V_39 >> 11 ) & 0xFF ;
V_82 = ( V_39 >> 1 ) & 0x3FF ;
if ( V_81 < V_80 )
V_83 = ( V_84 - V_80 ) * V_4 +
V_81 * V_4 + V_82 * 4 ;
else
V_83 = ( V_81 - V_80 ) * V_4 + V_82 * 4 ;
if ( V_83 > V_1 ) {
F_17 ( V_23 L_6 ,
V_83 ) ;
return - 1 ;
}
F_15 ( V_17 , V_80 , V_83 , V_84 ) ;
#ifdef F_43
for ( V_6 = V_83 - 1 ; V_6 > 0 && V_17 [ V_6 ] == 0xff ; V_6 -- ) ;
if ( V_6 < 2 || V_17 [ V_6 - 1 ] != 0xff || V_17 [ V_6 ] != 0xd9 )
return - 1 ;
#endif
return V_83 ;
}
static void F_44 ( void )
{
int V_6 ;
F_37 () ;
F_29 () ;
F_33 ( V_7 . V_12 ) ;
F_25 ( V_85 , V_86 ) ;
F_25 ( V_74 , V_87 ) ;
F_28 ( V_74 , 0 ) ;
for ( V_6 = 0 ; V_6 < 100 ; ++ V_6 ) {
if ( F_28 ( V_38 , V_46 ) )
break;
F_38 ( 1 ) ;
}
}
static void F_45 ( T_3 * V_17 , int V_88 )
{
T_1 V_39 ;
int V_6 ;
F_25 ( V_85 , V_89 ) ;
F_25 ( V_74 , V_87 ) ;
F_28 ( V_74 , 0 ) ;
for ( V_6 = 0 ; V_6 < 100 ; ++ V_6 ) {
if ( F_28 ( V_38 , V_46 ) )
break;
F_38 ( 1 ) ;
}
for ( V_6 = 0 ; V_6 < 4 ; ++ V_6 ) {
V_39 = F_39 () ;
if ( V_39 & V_90 ) {
F_41 ( V_39 , V_17 , V_88 ) ;
break;
}
F_40 () ;
}
}
static void F_46 ( void )
{
F_37 () ;
F_29 () ;
F_30 () ;
F_33 ( V_7 . V_12 ) ;
V_7 . V_71 = V_91 ;
F_25 ( V_85 , V_91 ) ;
F_25 ( V_74 , V_87 ) ;
F_28 ( V_74 , 0 ) ;
}
static int F_47 ( T_3 * V_17 , int V_88 )
{
T_1 V_39 ;
int V_92 = - 1 , V_6 ;
F_32 ( 0x3f ) ;
F_24 ( 50 ) ;
F_25 ( V_85 , V_93 ) ;
F_25 ( V_74 , V_87 ) ;
F_28 ( V_74 , 0 ) ;
for ( V_6 = 0 ; V_6 < 100 ; ++ V_6 ) {
if ( F_28 ( V_38 , V_46 ) )
break;
F_38 ( 1 ) ;
}
for ( V_6 = 0 ; V_6 < 4 ; ++ V_6 ) {
V_39 = F_39 () ;
if ( V_39 & V_90 ) {
V_92 = F_42 ( V_39 , V_17 , V_88 ) ;
break;
}
F_40 () ;
}
return V_92 ;
}
static void F_48 ( void )
{
F_37 () ;
F_32 ( 0x3f ) ;
F_29 () ;
F_30 () ;
F_33 ( V_7 . V_12 ) ;
V_7 . V_71 = V_94 ;
F_25 ( V_85 , V_94 ) ;
F_25 ( V_74 , V_87 ) ;
F_28 ( V_74 , 0 ) ;
}
static T_5 F_49 ( int V_95 , void * V_96 )
{
T_1 V_39 ;
int V_97 ;
static int V_98 ;
V_39 = F_27 ( V_99 ) ;
if ( V_7 . V_71 != V_91 &&
V_7 . V_71 != V_94 )
return V_100 ;
V_101:
V_39 = F_39 () ;
if ( ! ( V_39 & V_90 ) )
return V_102 ;
if ( V_7 . V_71 == V_91 ) {
if ( F_50 ( & V_7 . V_103 , ( unsigned char * ) & V_97 ,
sizeof( int ) , & V_7 . V_104 ) != sizeof( int ) ) {
F_40 () ;
return V_102 ;
}
F_41 ( V_39 , V_7 . V_105 + V_106 * V_97 ,
F_20 () * F_21 () * 2 ) ;
V_7 . V_107 [ V_97 ] . V_1 = F_20 () * F_21 () * 2 ;
V_7 . V_107 [ V_97 ] . V_108 = V_109 ;
F_51 ( & V_7 . V_107 [ V_97 ] . V_110 ) ;
V_7 . V_107 [ V_97 ] . V_98 = V_98 ++ ;
F_52 ( & V_7 . V_111 , ( unsigned char * ) & V_97 ,
sizeof( int ) , & V_7 . V_112 ) ;
F_53 ( & V_7 . V_113 ) ;
} else {
int V_1 ;
V_1 = F_42 ( V_39 , V_7 . V_114 , V_106 ) ;
if ( V_1 == - 1 ) {
F_40 () ;
goto V_101;
}
if ( F_50 ( & V_7 . V_103 , ( unsigned char * ) & V_97 ,
sizeof( int ) , & V_7 . V_104 ) != sizeof( int ) ) {
F_40 () ;
goto V_101;
}
memcpy ( V_7 . V_105 + V_106 * V_97 , V_7 . V_114 ,
V_1 ) ;
V_7 . V_107 [ V_97 ] . V_1 = V_1 ;
V_7 . V_107 [ V_97 ] . V_108 = V_109 ;
F_51 ( & V_7 . V_107 [ V_97 ] . V_110 ) ;
V_7 . V_107 [ V_97 ] . V_98 = V_98 ++ ;
F_52 ( & V_7 . V_111 , ( unsigned char * ) & V_97 ,
sizeof( int ) , & V_7 . V_112 ) ;
F_53 ( & V_7 . V_113 ) ;
}
F_40 () ;
goto V_101;
}
static int F_54 ( struct V_115 * V_115 )
{
int V_6 ;
if ( F_55 ( 0 , & V_7 . V_116 ) )
return - V_117 ;
F_37 () ;
if ( F_35 () ) {
F_17 ( V_76 L_7 ) ;
F_56 ( 0 , & V_7 . V_116 ) ;
return - V_118 ;
}
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ )
V_7 . V_107 [ V_6 ] . V_108 = V_120 ;
F_57 ( & V_7 . V_103 ) ;
F_57 ( & V_7 . V_111 ) ;
return F_58 ( V_115 ) ;
}
static int F_59 ( struct V_115 * V_115 )
{
F_37 () ;
F_36 () ;
F_56 ( 0 , & V_7 . V_116 ) ;
return F_60 ( V_115 ) ;
}
static int F_61 ( struct V_121 * V_122 )
{
* V_122 = V_7 . V_25 ;
return 0 ;
}
static int F_62 ( struct V_121 * V_123 )
{
if ( V_123 -> V_26 > 1 )
return - V_124 ;
if ( V_123 -> V_21 > 10 )
return - V_124 ;
if ( V_123 -> V_125 > 63 || V_123 -> V_126 > 63 || V_123 -> V_127 > 63 )
return - V_124 ;
if ( V_123 -> V_48 > 31 )
return - V_124 ;
F_63 ( & V_7 . V_128 ) ;
if ( V_7 . V_25 . V_26 != V_123 -> V_26 ||
V_7 . V_25 . V_21 != V_123 -> V_21 )
F_37 () ;
V_7 . V_25 = * V_123 ;
F_64 ( V_129 ,
V_7 . V_25 . V_125 ) ;
F_64 ( V_130 ,
V_7 . V_25 . V_126 ) ;
F_64 ( V_131 ,
V_7 . V_25 . V_127 ) ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_66 ( int * V_132 )
{
if ( ! V_7 . V_105 )
return - V_124 ;
if ( * V_132 >= V_133 )
return - V_124 ;
if ( * V_132 < 0 ) {
F_37 () ;
return 0 ;
}
if ( V_7 . V_107 [ * V_132 ] . V_108 != V_120 )
return - V_117 ;
F_63 ( & V_7 . V_128 ) ;
if ( V_7 . V_71 != V_94 )
F_48 () ;
V_7 . V_107 [ * V_132 ] . V_108 = V_134 ;
F_52 ( & V_7 . V_103 , ( unsigned char * ) V_132 , sizeof( int ) ,
& V_7 . V_104 ) ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_67 ( struct V_115 * V_115 , void * V_135 , int * V_6 )
{
int V_136 ;
if ( * V_6 < 0 || * V_6 >= V_133 )
return - V_124 ;
F_63 ( & V_7 . V_128 ) ;
switch ( V_7 . V_107 [ * V_6 ] . V_108 ) {
case V_120 :
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
case V_134 :
if ( V_115 -> V_137 & V_138 ) {
F_65 ( & V_7 . V_128 ) ;
return - V_139 ;
}
if ( F_68 ( V_7 . V_113 ,
( V_7 . V_107 [ * V_6 ] . V_108 != V_134 ) ) ) {
F_65 ( & V_7 . V_128 ) ;
return - V_140 ;
}
case V_109 :
V_7 . V_107 [ * V_6 ] . V_108 = V_120 ;
if ( F_50 ( & V_7 . V_111 , ( unsigned char * ) & V_136 ,
sizeof( int ) , & V_7 . V_112 ) != sizeof( int ) )
break;
}
* V_6 = V_7 . V_107 [ * V_6 ] . V_1 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_69 ( void )
{
if ( ! V_7 . V_105 )
return - V_124 ;
if ( V_7 . V_107 [ 0 ] . V_108 != V_120 )
return - V_117 ;
F_63 ( & V_7 . V_128 ) ;
V_7 . V_107 [ 0 ] . V_108 = V_134 ;
F_44 () ;
F_45 ( V_7 . V_105 ,
F_20 () * F_21 () * 2 ) ;
V_7 . V_107 [ 0 ] . V_108 = V_109 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_70 ( int * V_92 )
{
if ( ! V_7 . V_105 )
return - V_124 ;
if ( V_7 . V_107 [ 0 ] . V_108 != V_120 )
return - V_117 ;
F_63 ( & V_7 . V_128 ) ;
V_7 . V_107 [ 0 ] . V_108 = V_134 ;
* V_92 = - 1 ;
while ( * V_92 == - 1 ) {
F_44 () ;
* V_92 = F_47 ( V_7 . V_105 , V_106 ) ;
}
V_7 . V_107 [ 0 ] . V_108 = V_109 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_71 ( struct V_115 * V_115 , void * V_135 ,
struct V_141 * V_142 )
{
strcpy ( V_142 -> V_143 , L_8 ) ;
strcpy ( V_142 -> V_144 , L_8 ) ;
sprintf ( V_142 -> V_145 , L_9 , F_72 ( V_7 . V_9 ) ) ;
V_142 -> V_146 = ( V_147 << 8 ) +
V_148 ;
V_142 -> V_149 = V_150 |
V_151 ;
V_142 -> V_152 = V_142 -> V_149 | V_153 ;
return 0 ;
}
static int F_73 ( struct V_115 * V_115 , void * V_135 , struct V_154 * V_6 )
{
if ( V_6 -> V_155 != 0 )
return - V_124 ;
strcpy ( V_6 -> V_156 , L_10 ) ;
V_6 -> type = V_157 ;
return 0 ;
}
static int F_74 ( struct V_115 * V_115 , void * V_135 , unsigned int * V_6 )
{
* V_6 = 0 ;
return 0 ;
}
static int F_75 ( struct V_115 * V_115 , void * V_135 , unsigned int V_6 )
{
if ( V_6 != 0 )
return - V_124 ;
return 0 ;
}
static int F_76 ( struct V_158 * V_159 )
{
F_63 ( & V_7 . V_128 ) ;
switch ( V_159 -> V_160 ) {
case V_161 :
F_64 (
V_162 , V_159 -> V_163 ) ;
V_7 . V_164 = V_159 -> V_163 << 10 ;
break;
case V_165 :
F_64 (
V_166 , V_159 -> V_163 ) ;
V_7 . V_167 = V_159 -> V_163 << 10 ;
break;
case V_168 :
F_64 (
V_169 , V_159 -> V_163 ) ;
V_7 . V_170 = V_159 -> V_163 << 10 ;
break;
case V_171 :
F_64 (
V_172 , V_159 -> V_163 ) ;
V_7 . V_173 = V_159 -> V_163 << 10 ;
break;
case V_174 :
F_64 (
V_130 , V_159 -> V_163 ) ;
V_7 . V_25 . V_126 = V_159 -> V_163 ;
break;
case V_175 :
F_64 (
V_129 , V_159 -> V_163 ) ;
V_7 . V_25 . V_125 = V_159 -> V_163 ;
break;
case V_176 :
F_64 (
V_131 , V_159 -> V_163 ) ;
V_7 . V_25 . V_127 = V_159 -> V_163 ;
break;
case V_177 :
V_7 . V_25 . V_21 = V_159 -> V_163 ;
break;
case V_178 :
V_7 . V_25 . V_48 = V_159 -> V_163 ;
break;
default:
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
}
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_77 ( struct V_115 * V_115 , void * V_135 ,
struct V_179 * V_180 )
{
if ( V_180 -> V_155 > 1 )
return - V_124 ;
if ( V_180 -> V_155 == 0 ) {
V_180 -> V_181 = 0 ;
strcpy ( V_180 -> V_182 , L_11 ) ;
V_180 -> V_183 = V_184 ;
} else {
V_180 -> V_181 = V_185 ;
strcpy ( V_180 -> V_182 , L_12 ) ;
V_180 -> V_183 = V_186 ;
}
return 0 ;
}
static int F_78 ( struct V_115 * V_115 , void * V_135 ,
struct V_187 * V_180 )
{
if ( V_180 -> V_188 . V_189 . V_183 != V_184 &&
V_180 -> V_188 . V_189 . V_183 != V_186 )
return - V_124 ;
if ( V_180 -> V_188 . V_189 . V_190 != V_191 &&
V_180 -> V_188 . V_189 . V_190 != V_192 )
return - V_124 ;
V_180 -> V_188 . V_189 . V_190 = V_192 ;
if ( V_180 -> V_188 . V_189 . V_193 <= 320 ) {
V_180 -> V_188 . V_189 . V_193 = 320 ;
V_180 -> V_188 . V_189 . V_194 = 240 ;
} else {
V_180 -> V_188 . V_189 . V_193 = 640 ;
V_180 -> V_188 . V_189 . V_194 = 480 ;
}
V_180 -> V_188 . V_189 . V_195 = V_180 -> V_188 . V_189 . V_193 * 2 ;
V_180 -> V_188 . V_189 . V_196 = V_180 -> V_188 . V_189 . V_194 *
V_180 -> V_188 . V_189 . V_195 ;
V_180 -> V_188 . V_189 . V_197 = 0 ;
V_180 -> V_188 . V_189 . V_198 = 0 ;
return 0 ;
}
static int F_79 ( struct V_115 * V_115 , void * V_135 ,
struct V_187 * V_180 )
{
switch ( V_7 . V_71 ) {
case V_91 :
default:
V_180 -> V_188 . V_189 . V_183 = V_184 ;
break;
case V_94 :
V_180 -> V_188 . V_189 . V_183 = V_186 ;
break;
}
V_180 -> V_188 . V_189 . V_190 = V_192 ;
V_180 -> V_188 . V_189 . V_193 = F_20 () ;
V_180 -> V_188 . V_189 . V_194 = F_21 () ;
V_180 -> V_188 . V_189 . V_195 = V_180 -> V_188 . V_189 . V_193 * 2 ;
V_180 -> V_188 . V_189 . V_196 = V_180 -> V_188 . V_189 . V_194 *
V_180 -> V_188 . V_189 . V_195 ;
return 0 ;
}
static int F_80 ( struct V_115 * V_115 , void * V_135 ,
struct V_187 * V_180 )
{
if ( V_180 -> V_188 . V_189 . V_183 != V_184 &&
V_180 -> V_188 . V_189 . V_183 != V_186 )
return - V_124 ;
if ( V_180 -> V_188 . V_189 . V_190 != V_191 &&
V_180 -> V_188 . V_189 . V_190 != V_192 )
return - V_124 ;
V_180 -> V_188 . V_189 . V_190 = V_192 ;
F_63 ( & V_7 . V_128 ) ;
if ( V_180 -> V_188 . V_189 . V_193 <= 320 ) {
V_180 -> V_188 . V_189 . V_193 = 320 ;
V_180 -> V_188 . V_189 . V_194 = 240 ;
V_7 . V_25 . V_26 = 1 ;
} else {
V_180 -> V_188 . V_189 . V_193 = 640 ;
V_180 -> V_188 . V_189 . V_194 = 480 ;
V_7 . V_25 . V_26 = 0 ;
}
switch ( V_180 -> V_188 . V_189 . V_183 ) {
case V_184 :
V_7 . V_71 = V_91 ;
break;
case V_186 :
V_7 . V_71 = V_94 ;
break;
}
F_65 ( & V_7 . V_128 ) ;
V_180 -> V_188 . V_189 . V_195 = V_180 -> V_188 . V_189 . V_193 * 2 ;
V_180 -> V_188 . V_189 . V_196 = V_180 -> V_188 . V_189 . V_194 *
V_180 -> V_188 . V_189 . V_195 ;
V_180 -> V_188 . V_189 . V_197 = 0 ;
V_180 -> V_188 . V_189 . V_198 = 0 ;
return 0 ;
}
static int F_81 ( struct V_115 * V_115 , void * V_135 ,
struct V_199 * V_200 )
{
int V_6 ;
if ( V_200 -> V_201 != V_202 )
return - V_124 ;
if ( V_7 . V_105 && V_200 -> V_203 == V_133 ) {
return 0 ;
}
F_63 ( & V_7 . V_128 ) ;
if ( V_7 . V_105 ) {
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ )
if ( V_7 . V_204 [ V_6 ] ) {
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
}
F_6 ( V_7 . V_105 , V_133 * V_106 ) ;
V_7 . V_105 = NULL ;
}
V_133 = F_82 ( 2 , F_83 ( ( int ) V_200 -> V_203 , V_119 ) ) ;
V_200 -> V_203 = V_133 ;
V_7 . V_105 = F_1 ( V_133 * V_106 ) ;
if ( ! V_7 . V_105 ) {
F_17 ( V_76 L_13
L_14 ) ;
F_65 ( & V_7 . V_128 ) ;
return - V_205 ;
}
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ )
V_7 . V_204 [ V_6 ] = 0 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_84 ( struct V_115 * V_115 , void * V_135 , struct V_206 * V_17 )
{
unsigned int V_155 = V_17 -> V_155 ;
if ( V_155 >= V_133 )
return - V_124 ;
V_17 -> V_207 = V_7 . V_107 [ V_155 ] . V_1 ;
V_17 -> V_181 = V_208 | V_209 ;
if ( V_7 . V_107 [ V_155 ] . V_108 == V_134 )
V_17 -> V_181 |= V_210 ;
if ( V_7 . V_107 [ V_155 ] . V_108 == V_109 )
V_17 -> V_181 |= V_211 ;
V_17 -> V_190 = V_192 ;
V_17 -> V_110 = V_7 . V_107 [ V_155 ] . V_110 ;
V_17 -> V_98 = V_7 . V_107 [ V_155 ] . V_98 ;
V_17 -> V_201 = V_202 ;
V_17 -> V_212 . V_213 = V_155 * V_106 ;
V_17 -> V_20 = V_106 ;
return 0 ;
}
static int F_85 ( struct V_115 * V_115 , void * V_135 , struct V_206 * V_17 )
{
if ( V_17 -> V_201 != V_202 )
return - V_124 ;
if ( V_17 -> V_155 >= V_133 )
return - V_124 ;
if ( V_7 . V_107 [ V_17 -> V_155 ] . V_108 != V_120 )
return - V_124 ;
F_63 ( & V_7 . V_128 ) ;
V_17 -> V_181 |= V_210 ;
V_17 -> V_181 &= ~ V_211 ;
V_7 . V_107 [ V_17 -> V_155 ] . V_108 = V_134 ;
F_52 ( & V_7 . V_103 , ( unsigned char * ) & V_17 -> V_155 ,
sizeof( int ) , & V_7 . V_104 ) ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_86 ( struct V_115 * V_115 , void * V_135 , struct V_206 * V_17 )
{
int V_97 ;
if ( V_17 -> V_201 != V_202 )
return - V_124 ;
F_63 ( & V_7 . V_128 ) ;
if ( F_87 ( & V_7 . V_111 ) == 0 && V_115 -> V_137 & V_138 ) {
F_65 ( & V_7 . V_128 ) ;
return - V_139 ;
}
if ( F_68 ( V_7 . V_113 ,
F_87 ( & V_7 . V_111 ) != 0 ) < 0 ) {
F_65 ( & V_7 . V_128 ) ;
return - V_140 ;
}
if ( ! F_50 ( & V_7 . V_111 , ( unsigned char * ) & V_97 ,
sizeof( int ) , & V_7 . V_112 ) ) {
F_65 ( & V_7 . V_128 ) ;
return - V_117 ;
}
if ( V_7 . V_107 [ V_97 ] . V_108 != V_109 ) {
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
}
V_17 -> V_155 = V_97 ;
V_17 -> V_207 = V_7 . V_107 [ V_97 ] . V_1 ;
V_17 -> V_181 = V_208 | V_209 ;
V_17 -> V_190 = V_192 ;
V_17 -> V_110 = V_7 . V_107 [ V_97 ] . V_110 ;
V_17 -> V_98 = V_7 . V_107 [ V_97 ] . V_98 ;
V_17 -> V_201 = V_202 ;
V_17 -> V_212 . V_213 = V_97 * V_106 ;
V_17 -> V_20 = V_106 ;
V_7 . V_107 [ V_97 ] . V_108 = V_120 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_88 ( struct V_115 * V_115 , void * V_135 , enum V_214 V_6 )
{
F_63 ( & V_7 . V_128 ) ;
switch ( V_7 . V_71 ) {
case V_91 :
F_46 () ;
break;
case V_94 :
F_48 () ;
break;
default:
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
}
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_89 ( struct V_115 * V_115 , void * V_135 , enum V_214 V_6 )
{
F_63 ( & V_7 . V_128 ) ;
F_37 () ;
F_57 ( & V_7 . V_103 ) ;
F_57 ( & V_7 . V_111 ) ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ )
V_7 . V_107 [ V_6 ] . V_108 = V_120 ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static long F_90 ( struct V_115 * V_115 , void * V_135 , bool V_215 ,
unsigned int V_216 , void * V_217 )
{
switch ( V_216 ) {
case V_218 :
return F_61 ( (struct V_121 * ) V_217 ) ;
case V_219 :
return F_62 ( (struct V_121 * ) V_217 ) ;
case V_220 :
return F_66 ( ( int * ) V_217 ) ;
case V_221 :
return F_67 ( V_115 , V_135 , ( int * ) V_217 ) ;
case V_222 :
return F_69 () ;
case V_223 :
return F_70 ( ( int * ) V_217 ) ;
default:
return - V_224 ;
}
}
static unsigned int F_91 ( struct V_115 * V_115 , T_6 * V_225 )
{
unsigned int V_226 = F_92 ( V_115 , V_225 ) ;
F_63 ( & V_7 . V_128 ) ;
F_93 ( V_115 , & V_7 . V_113 , V_225 ) ;
if ( F_87 ( & V_7 . V_111 ) )
V_226 |= V_227 | V_228 ;
F_65 ( & V_7 . V_128 ) ;
return V_226 ;
}
static void F_94 ( struct V_229 * V_230 )
{
long V_231 = ( long ) V_230 -> V_232 ;
V_7 . V_204 [ V_231 ] ++ ;
}
static void F_95 ( struct V_229 * V_230 )
{
long V_231 = ( long ) V_230 -> V_232 ;
V_7 . V_204 [ V_231 ] -- ;
}
static int F_96 ( struct V_115 * V_115 , struct V_229 * V_230 )
{
unsigned long V_18 = V_230 -> V_233 ;
unsigned long V_1 = V_230 -> V_234 - V_230 -> V_233 ;
unsigned long V_213 = V_230 -> V_235 << V_236 ;
unsigned long V_237 , V_238 ;
F_63 ( & V_7 . V_128 ) ;
if ( V_1 > V_133 * V_106 ) {
F_65 ( & V_7 . V_128 ) ;
return - V_124 ;
}
if ( ! V_7 . V_105 ) {
int V_6 ;
V_7 . V_105 = F_1 ( V_133 * V_106 ) ;
if ( ! V_7 . V_105 ) {
F_17 ( V_76 L_15 ) ;
F_65 ( & V_7 . V_128 ) ;
return - V_205 ;
}
for ( V_6 = 0 ; V_6 < V_133 ; V_6 ++ )
V_7 . V_204 [ V_6 ] = 0 ;
}
V_238 = ( unsigned long ) V_7 . V_105 + V_213 ;
while ( V_1 > 0 ) {
V_237 = F_97 ( ( void * ) V_238 ) ;
if ( F_98 ( V_230 , V_18 , V_237 , V_4 , V_239 ) ) {
F_65 ( & V_7 . V_128 ) ;
return - V_139 ;
}
V_18 += V_4 ;
V_238 += V_4 ;
if ( V_1 > V_4 )
V_1 -= V_4 ;
else
V_1 = 0 ;
}
V_230 -> V_240 = & V_241 ;
V_230 -> V_242 &= ~ V_243 ;
V_230 -> V_242 |= V_244 | V_245 ;
V_230 -> V_232 = ( void * ) ( V_213 / V_106 ) ;
F_94 ( V_230 ) ;
F_65 ( & V_7 . V_128 ) ;
return 0 ;
}
static int F_99 ( struct V_246 * V_247 , T_7 V_108 )
{
F_100 ( V_247 ) ;
V_7 . V_248 = V_7 . V_71 ;
F_37 () ;
F_25 ( V_99 , 0x0 ) ;
return 0 ;
}
static int F_101 ( struct V_246 * V_247 )
{
F_102 ( V_247 ) ;
F_103 ( V_7 . V_9 , V_249 , 1 ) ;
F_28 ( V_74 , 0 ) ;
F_28 ( V_38 , V_46 ) ;
F_38 ( 1 ) ;
F_25 ( V_250 , 1 ) ;
F_38 ( 1 ) ;
F_25 ( V_251 , 5 ) ;
F_38 ( 1 ) ;
F_25 ( V_99 , V_252 ) ;
switch ( V_7 . V_248 ) {
case V_91 :
F_46 () ;
break;
case V_94 :
F_48 () ;
break;
}
return 0 ;
}
static int F_104 ( struct V_246 * V_253 , const struct V_254 * V_255 )
{
static const struct V_256 V_257 = {
. V_160 = V_174 ,
. type = V_258 ,
. V_259 = & V_260 ,
. V_156 = L_16 ,
. F_82 = 63 ,
. V_261 = 1 ,
. V_262 = 48 ,
. V_181 = V_263 ,
} ;
static const struct V_256 V_264 = {
. V_160 = V_176 ,
. type = V_258 ,
. V_259 = & V_260 ,
. V_156 = L_17 ,
. F_82 = 63 ,
. V_261 = 1 ,
} ;
static const struct V_256 V_265 = {
. V_160 = V_178 ,
. type = V_258 ,
. V_259 = & V_260 ,
. V_156 = L_18 ,
. F_82 = 31 ,
. V_261 = 1 ,
} ;
struct V_266 * V_267 = & V_7 . V_267 ;
int V_268 = - V_117 ;
unsigned long V_269 ;
if ( V_7 . V_9 != NULL ) {
F_17 ( V_76 L_19 ) ;
goto V_270;
}
V_268 = F_105 ( & V_253 -> V_10 , V_267 ) ;
if ( V_268 < 0 ) {
F_106 ( V_267 , L_20 ) ;
return V_268 ;
}
V_268 = - V_205 ;
V_7 . V_9 = V_253 ;
V_7 . V_271 = F_107 () ;
if ( ! V_7 . V_271 ) {
F_106 ( V_267 , L_21 ) ;
goto V_270;
}
V_7 . V_114 = F_108 ( V_84 * V_4 ) ;
if ( ! V_7 . V_114 ) {
F_106 ( V_267 , L_22 ) ;
goto V_272;
}
F_109 ( & V_7 . V_104 ) ;
if ( F_110 ( & V_7 . V_103 , sizeof( int ) * V_119 ,
V_13 ) ) {
F_106 ( V_267 , L_23 ) ;
goto V_273;
}
F_109 ( & V_7 . V_112 ) ;
if ( F_110 ( & V_7 . V_111 , sizeof( int ) * V_119 ,
V_13 ) ) {
F_106 ( V_267 , L_23 ) ;
goto V_274;
}
memcpy ( V_7 . V_271 , & V_275 , sizeof( V_275 ) ) ;
V_7 . V_271 -> V_267 = & V_7 . V_267 ;
V_268 = - V_276 ;
if ( ( V_268 = F_64 ( V_277 , 1 ) ) ) {
F_106 ( V_267 , L_24 ) ;
F_106 ( V_267 , L_25
L_26 ) ;
goto V_278;
}
if ( ( V_268 = F_111 ( V_7 . V_9 ) ) ) {
F_106 ( V_267 , L_27 ) ;
goto V_279;
}
V_269 = F_112 ( V_7 . V_9 , 0 ) ;
if ( ! V_269 ) {
F_106 ( V_267 , L_28 ) ;
goto V_280;
}
if ( ! F_113 ( F_112 ( V_7 . V_9 , 0 ) ,
F_114 ( V_7 . V_9 , 0 ) ,
L_8 ) ) {
F_106 ( V_267 , L_29 ) ;
goto V_280;
}
V_7 . V_31 = F_115 ( V_269 , V_281 ) ;
if ( ! V_7 . V_31 ) {
F_106 ( V_267 , L_30 ) ;
goto V_282;
}
V_7 . V_283 = V_253 -> V_95 ;
if ( F_116 ( V_7 . V_283 , F_49 ,
V_284 | V_285 , L_8 , F_49 ) ) {
F_106 ( V_267 , L_31 ) ;
goto V_286;
}
F_117 ( V_7 . V_9 , V_287 , 8 ) ;
F_117 ( V_7 . V_9 , V_288 , 64 ) ;
F_118 ( V_7 . V_9 ) ;
F_103 ( V_7 . V_9 , V_249 , 1 ) ;
F_28 ( V_74 , 0 ) ;
F_28 ( V_38 , V_46 ) ;
F_38 ( 1 ) ;
F_25 ( V_250 , 1 ) ;
F_38 ( 1 ) ;
F_25 ( V_251 , 5 ) ;
F_38 ( 1 ) ;
F_25 ( V_99 , V_252 ) ;
F_119 ( & V_7 . V_128 ) ;
F_120 ( & V_7 . V_113 ) ;
F_121 ( & V_7 . V_289 , 3 ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_161 , 0 , 63 , 1 , 32 ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_165 , 0 , 63 , 1 , 32 ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_168 , 0 , 63 , 1 , 32 ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_171 , 0 , 63 , 1 , 32 ) ;
F_123 ( & V_7 . V_289 , & V_257 , NULL ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_175 , 0 , 63 , 1 , 32 ) ;
F_123 ( & V_7 . V_289 , & V_264 , NULL ) ;
F_122 ( & V_7 . V_289 , & V_260 ,
V_177 , 0 , 10 , 1 , 8 ) ;
F_123 ( & V_7 . V_289 , & V_265 , NULL ) ;
if ( V_7 . V_289 . error ) {
F_106 ( V_267 , L_32 ) ;
goto V_290;
}
F_124 ( & V_7 . V_289 ) ;
V_7 . V_271 -> V_291 = & V_7 . V_289 ;
F_125 ( V_292 , & V_7 . V_271 -> V_181 ) ;
if ( F_126 ( V_7 . V_271 , V_293 ,
V_294 ) < 0 ) {
F_106 ( V_267 , L_33 ) ;
goto V_290;
}
F_127 ( V_267 , L_34 ,
V_295 ) ;
F_127 ( V_267 , L_35 ,
V_7 . V_9 -> V_296 , V_269 , V_7 . V_283 ) ;
return 0 ;
V_290:
F_128 ( & V_7 . V_289 ) ;
F_129 ( V_7 . V_283 , F_49 ) ;
V_286:
F_130 ( V_7 . V_31 ) ;
V_282:
F_131 ( F_112 ( V_7 . V_9 , 0 ) ,
F_114 ( V_7 . V_9 , 0 ) ) ;
V_280:
F_132 ( V_7 . V_9 ) ;
V_279:
F_64 ( V_277 , 0 ) ;
V_278:
F_133 ( & V_7 . V_111 ) ;
V_274:
F_133 ( & V_7 . V_103 ) ;
V_273:
F_8 ( V_7 . V_114 ) ;
V_272:
F_134 ( V_7 . V_271 ) ;
V_270:
return V_268 ;
}
static void F_135 ( struct V_246 * V_253 )
{
F_136 ( V_7 . V_271 ) ;
F_37 () ;
F_36 () ;
F_25 ( V_99 , 0x0 ) ;
F_129 ( V_7 . V_283 , F_49 ) ;
F_130 ( V_7 . V_31 ) ;
F_131 ( F_112 ( V_7 . V_9 , 0 ) ,
F_114 ( V_7 . V_9 , 0 ) ) ;
F_132 ( V_7 . V_9 ) ;
F_64 ( V_277 , 0 ) ;
F_133 ( & V_7 . V_111 ) ;
F_133 ( & V_7 . V_103 ) ;
F_8 ( V_7 . V_114 ) ;
if ( V_7 . V_105 ) {
F_6 ( V_7 . V_105 , V_133 * V_106 ) ;
V_7 . V_105 = NULL ;
}
F_17 ( V_297 L_36 ) ;
}
static int T_8 F_137 ( void )
{
V_133 = F_82 ( 2 , F_83 ( ( int ) V_133 , V_119 ) ) ;
if ( V_106 > V_298 )
V_106 = V_298 ;
V_106 = F_2 ( V_106 ) ;
F_17 ( V_297 L_37
L_38 ,
V_133 ,
V_106 / 1024 , V_133 * V_106 / 1024 ) ;
return F_138 ( & V_299 ) ;
}
static void T_9 F_139 ( void )
{
F_140 ( & V_299 ) ;
}
