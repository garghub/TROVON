static void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , F_3 ( * V_5 ) , V_2 ) ;
struct V_6 * V_7 = V_6 ( V_5 ) ;
const int V_8 = F_4 ( V_7 , 0x02243c ) ;
int V_9 ;
F_5 ( V_2 , 0x10f910 , 0xbc0e0000 , V_3 ) ;
F_5 ( V_2 , 0x10f914 , 0xbc0e0000 , V_3 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
const T_1 V_10 = 0x110974 + ( V_9 * 0x1000 ) ;
F_6 ( V_2 , V_10 , 0x0000000f , 0x00000000 , 500000 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , F_3 ( * V_5 ) , V_2 ) ;
const T_1 V_11 = ( ( -- V_5 -> V_12 << 28 ) | ( V_5 -> V_13 << 8 ) | V_5 -> V_14 ) ;
const T_1 V_15 = ( ( V_5 -> V_16 << 16 ) | ( V_5 -> V_17 << 8 ) | V_5 -> V_18 ) ;
const T_1 V_19 = V_5 -> V_20 << 16 ;
const T_1 V_21 = V_5 -> V_20 ;
if ( V_5 -> V_22 == 2 ) {
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00001100 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00000010 ) ;
} else {
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00010010 ) ;
}
F_5 ( V_2 , 0x1373f4 , 0x00000003 , 0x00000000 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000010 , 0x00000000 ) ;
if ( ( F_8 ( V_2 , 0x132024 ) & 0xffffffff ) != V_15 ||
( F_8 ( V_2 , 0x132034 ) & 0x0000ffff ) != V_21 ) {
F_5 ( V_2 , 0x132000 , 0x00000001 , 0x00000000 ) ;
F_5 ( V_2 , 0x132020 , 0x00000001 , 0x00000000 ) ;
F_9 ( V_2 , 0x137320 , 0x00000000 ) ;
F_5 ( V_2 , 0x132030 , 0xffff0000 , V_19 ) ;
F_5 ( V_2 , 0x132034 , 0x0000ffff , V_21 ) ;
F_9 ( V_2 , 0x132024 , V_15 ) ;
F_5 ( V_2 , 0x132028 , 0x00080000 , 0x00080000 ) ;
F_5 ( V_2 , 0x132020 , 0x00000001 , 0x00000001 ) ;
F_6 ( V_2 , 0x137390 , 0x00020000 , 0x00020000 , 64000 ) ;
F_5 ( V_2 , 0x132028 , 0x00080000 , 0x00000000 ) ;
}
if ( V_5 -> V_23 == 2 ) {
F_5 ( V_2 , 0x1373f4 , 0x00010000 , 0x00000000 ) ;
F_5 ( V_2 , 0x132000 , 0x00000001 , 0x00000000 ) ;
F_5 ( V_2 , 0x132004 , 0x103fffff , V_11 ) ;
F_5 ( V_2 , 0x132000 , 0x00000001 , 0x00000001 ) ;
F_6 ( V_2 , 0x137390 , 0x00000002 , 0x00000002 , 64000 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00001100 ) ;
} else {
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00010100 ) ;
}
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00000010 ) ;
}
static void
F_10 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 , F_3 ( * V_5 ) , V_2 ) ;
struct V_25 * V_26 = V_25 ( V_5 ) ;
T_2 V_27 = ( F_11 ( V_26 , V_24 + 0x03 ) & 0xc0 ) >> 6 ;
T_2 V_28 = ( F_11 ( V_26 , V_24 + 0x03 ) & 0x30 ) >> 4 ;
T_1 V_29 ;
V_29 = F_8 ( V_2 , 0x1373ec ) & ~ 0x00030000 ;
F_9 ( V_2 , 0x1373ec , V_29 | ( V_28 << 16 ) ) ;
F_5 ( V_2 , 0x1373f0 , ( ~ V_5 -> V_23 & 3 ) , 0x00000000 ) ;
if ( V_5 -> V_23 == 2 ) {
F_5 ( V_2 , 0x1373f4 , 0x00000003 , 0x000000002 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00001100 , 0x000000000 ) ;
} else {
F_5 ( V_2 , 0x1373f4 , 0x00000003 , 0x000000001 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00010000 , 0x000000000 ) ;
}
F_5 ( V_2 , 0x10f800 , 0x00000030 , ( V_27 ^ V_28 ) << 4 ) ;
}
static int
F_12 ( struct V_6 * V_7 , T_1 V_30 )
{
struct V_25 * V_26 = V_25 ( V_7 ) ;
struct V_4 * V_5 = ( void * ) V_7 -> V_5 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
const T_1 V_31 = V_5 -> V_32 . V_31 . V_33 ;
const T_1 V_24 = V_5 -> V_32 . V_24 . V_33 ;
const T_1 V_34 = V_5 -> V_32 . V_34 . V_33 ;
int V_35 = ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x08 ) ;
int V_36 = 1 ;
T_1 V_37 , V_33 ;
F_5 ( V_2 , 0x10f808 , 0x40000000 , 0x40000000 ) ;
F_9 ( V_2 , 0x62c000 , 0x0f0f0000 ) ;
if ( ( V_5 -> V_32 . V_38 [ 1 ] & 0x03c ) != 0x030 )
F_5 ( V_2 , V_38 [ 1 ] , 0x03c , V_5 -> V_32 . V_38 [ 1 ] & 0x03c ) ;
if ( V_35 == 1 && F_13 ( V_2 , V_39 ) ) {
T_1 V_40 = F_5 ( V_2 , V_39 , 0x3000 , V_2 -> V_41 [ 1 ] ) ;
if ( V_40 != F_8 ( V_2 , V_39 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 20000 ) ;
}
}
F_5 ( V_2 , 0x10f200 , 0x00000800 , 0x00000000 ) ;
F_5 ( V_2 , 0x10f914 , 0x01020000 , 0x000c0000 ) ;
F_5 ( V_2 , 0x10f910 , 0x01020000 , 0x000c0000 ) ;
F_9 ( V_2 , 0x10f210 , 0x00000000 ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f310 , 0x00000001 ) ;
F_14 ( V_2 , 1000 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x80000000 ) ;
F_9 ( V_2 , 0x10f314 , 0x00000001 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x00000000 ) ;
F_9 ( V_2 , 0x10f090 , 0x00000061 ) ;
F_9 ( V_2 , 0x10f090 , 0xc000007f ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f698 , 0x00000000 ) ;
F_9 ( V_2 , 0x10f69c , 0x00000000 ) ;
V_37 = 0x800f07e0 ;
V_33 = 0x00030000 ;
if ( F_8 ( V_2 , 0x10f978 ) & 0x00800000 )
V_33 |= 0x00040000 ;
if ( 1 ) {
V_33 |= 0x800807e0 ;
switch ( F_11 ( V_26 , V_24 + 0x03 ) & 0xc0 ) {
case 0xc0 : V_33 &= ~ 0x00000040 ; break;
case 0x80 : V_33 &= ~ 0x00000100 ; break;
case 0x40 : V_33 &= ~ 0x80000000 ; break;
case 0x00 : V_33 &= ~ 0x00000400 ; break;
}
switch ( F_11 ( V_26 , V_24 + 0x03 ) & 0x30 ) {
case 0x30 : V_33 &= ~ 0x00000020 ; break;
case 0x20 : V_33 &= ~ 0x00000080 ; break;
case 0x10 : V_33 &= ~ 0x00080000 ; break;
case 0x00 : V_33 &= ~ 0x00000200 ; break;
}
}
if ( F_11 ( V_26 , V_24 + 0x02 ) & 0x80 )
V_37 |= 0x03000000 ;
if ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 )
V_37 |= 0x00002000 ;
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 )
V_37 |= 0x00004000 ;
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 )
V_37 |= 0x00000003 ;
else {
V_37 |= 0x34000000 ;
if ( F_8 ( V_2 , 0x10f978 ) & 0x00800000 )
V_37 |= 0x40000000 ;
}
F_5 ( V_2 , 0x10f824 , V_37 , V_33 ) ;
F_5 ( V_2 , 0x132040 , 0x00010000 , 0x00000000 ) ;
if ( V_5 -> V_22 == 2 && V_5 -> V_23 != 2 ) {
F_5 ( V_2 , 0x10f808 , 0x00080000 , 0x00000000 ) ;
F_5 ( V_2 , 0x10f200 , 0x00008000 , 0x00008000 ) ;
F_5 ( V_2 , 0x10f800 , 0x00000000 , 0x00000004 ) ;
F_5 ( V_2 , 0x10f830 , 0x00008000 , 0x01040010 ) ;
F_5 ( V_2 , 0x10f830 , 0x01000000 , 0x00000000 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 , 0x1373f0 , 0x00000002 , 0x00000001 ) ;
F_10 ( V_2 , V_24 ) ;
F_5 ( V_2 , 0x10f830 , 0x00c00000 , 0x00240001 ) ;
} else
if ( V_5 -> V_22 != 2 && V_5 -> V_23 != 2 ) {
F_7 ( V_2 ) ;
F_10 ( V_2 , V_24 ) ;
}
if ( F_13 ( V_2 , V_43 ) ) {
T_1 V_40 = F_5 ( V_2 , V_43 , 0x3000 , V_2 -> V_44 [ V_36 ] ) ;
if ( V_40 != F_8 ( V_2 , V_43 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 64000 ) ;
}
}
if ( ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 ) ||
( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 ) ) {
F_5 ( V_2 , 0x132040 , 0x00010000 , 0x00010000 ) ;
F_14 ( V_2 , 20000 ) ;
}
if ( V_5 -> V_22 != 2 && V_5 -> V_23 == 2 ) {
F_5 ( V_2 , 0x10f800 , 0x00000004 , 0x00000000 ) ;
F_5 ( V_2 , 0x1373f0 , 0x00000000 , 0x00000002 ) ;
F_5 ( V_2 , 0x10f830 , 0x00800001 , 0x00408010 ) ;
F_7 ( V_2 ) ;
F_10 ( V_2 , V_24 ) ;
F_5 ( V_2 , 0x10f808 , 0x00000000 , 0x00080000 ) ;
F_5 ( V_2 , 0x10f200 , 0x00808000 , 0x00800000 ) ;
} else
if ( V_5 -> V_22 == 2 && V_5 -> V_23 == 2 ) {
F_5 ( V_2 , 0x10f800 , 0x00000004 , 0x00000000 ) ;
F_7 ( V_2 ) ;
F_10 ( V_2 , V_24 ) ;
}
if ( V_5 -> V_23 != 2 ) {
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x40 )
F_5 ( V_2 , 0x10f670 , 0x80000000 , 0x80000000 ) ;
}
V_33 = ( F_11 ( V_26 , V_31 + 0x11 ) & 0x0c ) >> 2 ;
F_9 ( V_2 , 0x10f65c , 0x00000011 * V_33 ) ;
F_9 ( V_2 , 0x10f6b8 , 0x01010101 * F_11 ( V_26 , V_24 + 0x09 ) ) ;
F_9 ( V_2 , 0x10f6bc , 0x01010101 * F_11 ( V_26 , V_24 + 0x09 ) ) ;
V_33 = F_11 ( V_26 , V_24 + 0x04 ) ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 ) ) {
F_9 ( V_2 , 0x10f698 , 0x01010101 * V_33 ) ;
F_9 ( V_2 , 0x10f69c , 0x01010101 * V_33 ) ;
}
if ( V_5 -> V_23 != 2 ) {
T_1 V_40 = F_8 ( V_2 , 0x10f694 ) & ~ 0xff00ff00 ;
F_9 ( V_2 , 0x10f694 , V_40 | ( 0x01000100 * V_33 ) ) ;
}
if ( V_5 -> V_23 == 2 && ( F_11 ( V_26 , V_24 + 0x08 ) & 0x10 ) )
V_33 = 0x00000080 ;
else
V_33 = 0x00000000 ;
F_5 ( V_2 , 0x10f60c , 0x00000080 , V_33 ) ;
V_37 = 0x00070000 ;
V_33 = 0x00000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x80 ) )
V_33 |= 0x03000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 ) )
V_33 |= 0x00002000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 ) )
V_33 |= 0x00004000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 ) )
V_33 |= 0x00000003 ;
else
V_33 |= 0x74000000 ;
F_5 ( V_2 , 0x10f824 , V_37 , V_33 ) ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x08 )
V_33 = 0x00000000 ;
else
V_33 = 0x00001000 ;
F_5 ( V_2 , 0x10f200 , 0x00001000 , V_33 ) ;
if ( F_8 ( V_2 , 0x10f670 ) & 0x80000000 ) {
F_14 ( V_2 , 10000 ) ;
F_5 ( V_2 , 0x10f670 , 0x80000000 , 0x00000000 ) ;
}
if ( F_11 ( V_26 , V_24 + 0x08 ) & 0x01 )
V_33 = 0x00100000 ;
else
V_33 = 0x00000000 ;
F_5 ( V_2 , 0x10f82c , 0x00100000 , V_33 ) ;
V_33 = 0x00000000 ;
if ( F_11 ( V_26 , V_24 + 0x08 ) & 0x08 )
V_33 |= 0x00002000 ;
if ( F_11 ( V_26 , V_24 + 0x08 ) & 0x04 )
V_33 |= 0x00001000 ;
if ( F_11 ( V_26 , V_24 + 0x08 ) & 0x02 )
V_33 |= 0x00004000 ;
F_5 ( V_2 , 0x10f830 , 0x00007000 , V_33 ) ;
F_5 ( V_2 , 0x10f248 , 0xffffffff , F_15 ( V_26 , V_34 + 0x28 ) ) ;
F_5 ( V_2 , 0x10f290 , 0xffffffff , F_15 ( V_26 , V_34 + 0x00 ) ) ;
F_5 ( V_2 , 0x10f294 , 0xffffffff , F_15 ( V_26 , V_34 + 0x04 ) ) ;
F_5 ( V_2 , 0x10f298 , 0xffffffff , F_15 ( V_26 , V_34 + 0x08 ) ) ;
F_5 ( V_2 , 0x10f29c , 0xffffffff , F_15 ( V_26 , V_34 + 0x0c ) ) ;
F_5 ( V_2 , 0x10f2a0 , 0xffffffff , F_15 ( V_26 , V_34 + 0x10 ) ) ;
F_5 ( V_2 , 0x10f2a4 , 0xffffffff , F_15 ( V_26 , V_34 + 0x14 ) ) ;
F_5 ( V_2 , 0x10f2a8 , 0xffffffff , F_15 ( V_26 , V_34 + 0x18 ) ) ;
F_5 ( V_2 , 0x10f2ac , 0xffffffff , F_15 ( V_26 , V_34 + 0x1c ) ) ;
F_5 ( V_2 , 0x10f2cc , 0xffffffff , F_15 ( V_26 , V_34 + 0x20 ) ) ;
F_5 ( V_2 , 0x10f2e8 , 0xffffffff , F_15 ( V_26 , V_34 + 0x24 ) ) ;
V_33 = ( F_11 ( V_26 , V_24 + 0x02 ) & 0x03 ) << 8 ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x10 )
V_33 |= 0x70000000 ;
F_5 ( V_2 , 0x10f604 , 0x70000300 , V_33 ) ;
V_33 = ( F_11 ( V_26 , V_34 + 0x30 ) & 0x07 ) << 28 ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x01 )
V_33 |= 0x00000100 ;
F_5 ( V_2 , 0x10f614 , 0x70000000 , V_33 ) ;
V_33 = ( F_11 ( V_26 , V_34 + 0x30 ) & 0x07 ) << 28 ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x02 )
V_33 |= 0x00000100 ;
F_5 ( V_2 , 0x10f610 , 0x70000000 , V_33 ) ;
V_37 = 0x33f00000 ;
V_33 = 0x00000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x01 ) & 0x04 ) )
V_33 |= 0x20200000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x80 ) )
V_33 |= 0x12800000 ;
if ( ( F_11 ( V_26 , V_24 + 0x03 ) & 0xf0 ) ) {
if ( F_11 ( V_26 , V_31 + 0x08 ) & 0x0c ) {
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x80 ) )
V_37 |= 0x00000020 ;
else
V_33 |= 0x00000020 ;
V_37 |= 0x00000004 ;
}
} else {
V_37 |= 0x40000020 ;
V_33 |= 0x00000004 ;
}
F_5 ( V_2 , 0x10f808 , V_37 , V_33 ) ;
V_33 = F_11 ( V_26 , V_24 + 0x03 ) & 0x0f ;
F_9 ( V_2 , 0x10f870 , 0x11111111 * V_33 ) ;
V_33 = F_11 ( V_26 , V_24 + 0x02 ) & 0x03 ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x10 )
V_33 |= 0x00000004 ;
if ( ( F_4 ( V_26 , 0x100770 ) & 0x00000004 ) != ( V_33 & 0x00000004 ) ) {
F_9 ( V_2 , 0x10f750 , 0x04000009 ) ;
F_9 ( V_2 , 0x100710 , 0x00000000 ) ;
F_6 ( V_2 , 0x100710 , 0x80000000 , 0x80000000 , 200000 ) ;
}
F_5 ( V_2 , 0x100770 , 0x00000007 , V_33 ) ;
V_33 = ( F_11 ( V_26 , V_34 + 0x30 ) & 0x07 ) << 8 ;
if ( F_11 ( V_26 , V_24 + 0x01 ) & 0x01 )
V_33 |= 0x80000000 ;
F_5 ( V_2 , 0x100778 , 0x00000700 , V_33 ) ;
V_33 = F_16 ( V_26 , V_34 + 0x2c ) ;
F_5 ( V_2 , 0x10f250 , 0x000003f0 , ( V_33 & 0x003f ) << 4 ) ;
F_5 ( V_2 , 0x10f24c , 0x7f000000 , ( V_33 & 0x1fc0 ) << 18 ) ;
V_33 = F_11 ( V_26 , V_34 + 0x30 ) ;
F_5 ( V_2 , 0x10f224 , 0x001f0000 , ( V_33 & 0xf8 ) << 13 ) ;
V_33 = F_16 ( V_26 , V_34 + 0x31 ) ;
F_5 ( V_2 , 0x10fec4 , 0x041e0f07 , ( V_33 & 0x0800 ) << 15 |
( V_33 & 0x0780 ) << 10 |
( V_33 & 0x0078 ) << 5 |
( V_33 & 0x0007 ) ) ;
F_5 ( V_2 , 0x10fec8 , 0x00000027 , ( V_33 & 0x8000 ) >> 10 |
( V_33 & 0x7000 ) >> 12 ) ;
F_9 ( V_2 , 0x10f090 , 0x4000007e ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f314 , 0x00000001 ) ;
F_9 ( V_2 , 0x10f310 , 0x00000001 ) ;
F_14 ( V_2 , 2000 ) ;
F_9 ( V_2 , 0x10f210 , 0x80000000 ) ;
if ( ( F_11 ( V_26 , V_24 + 0x08 ) & 0x10 ) && ( V_5 -> V_23 == 2 ) ) {
T_1 V_40 = F_5 ( V_2 , 0x10f294 , 0xff000000 , 0x24000000 ) ;
F_1 ( V_2 , 0xa4010000 ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f294 , V_40 ) ;
}
F_5 ( V_2 , V_38 [ 3 ] , 0xfff , V_5 -> V_32 . V_38 [ 3 ] ) ;
F_9 ( V_2 , V_38 [ 0 ] , V_5 -> V_32 . V_38 [ 0 ] ) ;
F_5 ( V_2 , V_38 [ 8 ] , 0xfff , V_5 -> V_32 . V_38 [ 8 ] ) ;
F_14 ( V_2 , 1000 ) ;
F_5 ( V_2 , V_38 [ 1 ] , 0xfff , V_5 -> V_32 . V_38 [ 1 ] ) ;
F_5 ( V_2 , V_38 [ 5 ] , 0xfff , V_5 -> V_32 . V_38 [ 5 ] ) ;
F_5 ( V_2 , V_38 [ 6 ] , 0xfff , V_5 -> V_32 . V_38 [ 6 ] ) ;
F_5 ( V_2 , V_38 [ 7 ] , 0xfff , V_5 -> V_32 . V_38 [ 7 ] ) ;
if ( V_35 == 0 && F_13 ( V_2 , V_39 ) ) {
T_1 V_40 = F_5 ( V_2 , V_39 , 0x3000 , V_2 -> V_41 [ 0 ] ) ;
if ( V_40 != F_8 ( V_2 , V_39 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 20000 ) ;
}
}
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x80000000 ) ;
F_9 ( V_2 , 0x10f318 , 0x00000001 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x00000000 ) ;
F_14 ( V_2 , 1000 ) ;
V_33 = F_8 ( V_2 , 0x10f978 ) ;
V_33 &= ~ 0x00046144 ;
V_33 |= 0x0000000b ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 ) ) {
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x04 ) )
V_33 |= 0x0000200c ;
else
V_33 |= 0x00000000 ;
} else {
V_33 |= 0x00040044 ;
}
F_9 ( V_2 , 0x10f978 , V_33 ) ;
if ( V_5 -> V_23 == 1 ) {
V_33 = F_8 ( V_2 , 0x10f830 ) | 0x00000001 ;
F_9 ( V_2 , 0x10f830 , V_33 ) ;
}
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 ) ) {
V_33 = 0x88020000 ;
if ( ( F_11 ( V_26 , V_24 + 0x07 ) & 0x04 ) )
V_33 |= 0x10000000 ;
if ( ! ( F_11 ( V_26 , V_31 + 0x08 ) & 0x10 ) )
V_33 |= 0x00080000 ;
} else {
V_33 = 0xa40e0000 ;
}
F_1 ( V_2 , V_33 ) ;
F_14 ( V_2 , 1000 ) ;
if ( V_5 -> V_23 == 2 ) {
F_5 ( V_2 , 0x10f800 , 0x00000004 , 0x00000004 ) ;
}
F_5 ( V_2 , V_38 [ 5 ] , 0x00000004 , 0x00000000 ) ;
if ( V_5 -> V_23 != 2 ) {
F_5 ( V_2 , 0x10f830 , 0x01000000 , 0x01000000 ) ;
F_5 ( V_2 , 0x10f830 , 0x01000000 , 0x00000000 ) ;
}
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x02 ) {
F_5 ( V_2 , 0x10f910 , 0x80020000 , 0x01000000 ) ;
F_5 ( V_2 , 0x10f914 , 0x80020000 , 0x01000000 ) ;
}
F_9 ( V_2 , 0x62c000 , 0x0f0f0f00 ) ;
if ( F_11 ( V_26 , V_31 + 0x08 ) & 0x01 )
V_33 = 0x00000800 ;
else
V_33 = 0x00000000 ;
F_5 ( V_2 , 0x10f200 , 0x00000800 , V_33 ) ;
return 0 ;
}
static int
F_17 ( struct V_6 * V_7 , T_1 V_30 )
{
struct V_25 * V_26 = V_25 ( V_7 ) ;
struct V_4 * V_5 = ( void * ) V_7 -> V_5 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
const T_1 V_15 = ( ( V_5 -> V_16 << 16 ) | ( V_5 -> V_17 << 8 ) | V_5 -> V_18 ) ;
const T_1 V_19 = V_5 -> V_20 << 16 ;
const T_1 V_21 = V_5 -> V_20 ;
const T_1 V_31 = V_5 -> V_32 . V_31 . V_33 ;
const T_1 V_24 = V_5 -> V_32 . V_24 . V_33 ;
const T_1 V_34 = V_5 -> V_32 . V_34 . V_33 ;
int V_35 = ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x08 ) ;
int V_36 = 1 ;
T_1 V_37 , V_33 ;
F_5 ( V_2 , 0x10f808 , 0x40000000 , 0x40000000 ) ;
F_9 ( V_2 , 0x62c000 , 0x0f0f0000 ) ;
if ( V_35 == 1 && F_13 ( V_2 , V_39 ) ) {
T_1 V_40 = F_5 ( V_2 , V_39 , 0x3000 , V_2 -> V_41 [ 1 ] ) ;
if ( V_40 != F_8 ( V_2 , V_39 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 20000 ) ;
}
}
F_5 ( V_2 , 0x10f200 , 0x00000800 , 0x00000000 ) ;
if ( ( F_11 ( V_26 , V_24 + 0x03 ) & 0xf0 ) )
F_5 ( V_2 , 0x10f808 , 0x04000000 , 0x04000000 ) ;
F_9 ( V_2 , 0x10f314 , 0x00000001 ) ;
F_9 ( V_2 , 0x10f210 , 0x00000000 ) ;
F_9 ( V_2 , 0x10f310 , 0x00000001 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x80000000 ) ;
F_9 ( V_2 , 0x10f310 , 0x00000001 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x00000000 ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f090 , 0x00000060 ) ;
F_9 ( V_2 , 0x10f090 , 0xc000007e ) ;
V_37 = 0x00010000 ;
V_33 = 0x00010000 ;
if ( 1 ) {
V_37 |= 0x800807e0 ;
V_33 |= 0x800807e0 ;
switch ( F_11 ( V_26 , V_24 + 0x03 ) & 0xc0 ) {
case 0xc0 : V_33 &= ~ 0x00000040 ; break;
case 0x80 : V_33 &= ~ 0x00000100 ; break;
case 0x40 : V_33 &= ~ 0x80000000 ; break;
case 0x00 : V_33 &= ~ 0x00000400 ; break;
}
switch ( F_11 ( V_26 , V_24 + 0x03 ) & 0x30 ) {
case 0x30 : V_33 &= ~ 0x00000020 ; break;
case 0x20 : V_33 &= ~ 0x00000080 ; break;
case 0x10 : V_33 &= ~ 0x00080000 ; break;
case 0x00 : V_33 &= ~ 0x00000200 ; break;
}
}
if ( F_11 ( V_26 , V_24 + 0x02 ) & 0x80 )
V_37 |= 0x03000000 ;
if ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 )
V_37 |= 0x00002000 ;
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 )
V_37 |= 0x00004000 ;
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 )
V_37 |= 0x00000003 ;
else
V_37 |= 0x14000000 ;
F_5 ( V_2 , 0x10f824 , V_37 , V_33 ) ;
F_5 ( V_2 , 0x132040 , 0x00010000 , 0x00000000 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000000 , 0x00010010 ) ;
V_33 = F_8 ( V_2 , 0x1373ec ) & ~ 0x00030000 ;
V_33 |= ( F_11 ( V_26 , V_24 + 0x03 ) & 0x30 ) << 12 ;
F_9 ( V_2 , 0x1373ec , V_33 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000003 , 0x00000000 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000010 , 0x00000000 ) ;
if ( ( F_8 ( V_2 , 0x132024 ) & 0xffffffff ) != V_15 ||
( F_8 ( V_2 , 0x132034 ) & 0x0000ffff ) != V_21 ) {
F_5 ( V_2 , 0x132000 , 0x00000001 , 0x00000000 ) ;
F_5 ( V_2 , 0x132020 , 0x00000001 , 0x00000000 ) ;
F_9 ( V_2 , 0x137320 , 0x00000000 ) ;
F_5 ( V_2 , 0x132030 , 0xffff0000 , V_19 ) ;
F_5 ( V_2 , 0x132034 , 0x0000ffff , V_21 ) ;
F_9 ( V_2 , 0x132024 , V_15 ) ;
F_5 ( V_2 , 0x132028 , 0x00080000 , 0x00080000 ) ;
F_5 ( V_2 , 0x132020 , 0x00000001 , 0x00000001 ) ;
F_6 ( V_2 , 0x137390 , 0x00020000 , 0x00020000 , 64000 ) ;
F_5 ( V_2 , 0x132028 , 0x00080000 , 0x00000000 ) ;
}
F_5 ( V_2 , 0x1373f4 , 0x00000010 , 0x00000010 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00000003 , 0x00000001 ) ;
F_5 ( V_2 , 0x1373f4 , 0x00010000 , 0x00000000 ) ;
if ( F_13 ( V_2 , V_43 ) ) {
T_1 V_40 = F_5 ( V_2 , V_43 , 0x3000 , V_2 -> V_44 [ V_36 ] ) ;
if ( V_40 != F_8 ( V_2 , V_43 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 64000 ) ;
}
}
if ( ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 ) ||
( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 ) ) {
F_5 ( V_2 , 0x132040 , 0x00010000 , 0x00010000 ) ;
F_14 ( V_2 , 20000 ) ;
}
if ( V_5 -> V_23 != 2 ) {
if ( F_11 ( V_26 , V_24 + 0x07 ) & 0x40 )
F_5 ( V_2 , 0x10f670 , 0x80000000 , 0x80000000 ) ;
}
V_33 = ( F_11 ( V_26 , V_31 + 0x11 ) & 0x0c ) >> 2 ;
F_9 ( V_2 , 0x10f65c , 0x00000011 * V_33 ) ;
F_9 ( V_2 , 0x10f6b8 , 0x01010101 * F_11 ( V_26 , V_24 + 0x09 ) ) ;
F_9 ( V_2 , 0x10f6bc , 0x01010101 * F_11 ( V_26 , V_24 + 0x09 ) ) ;
V_37 = 0x00010000 ;
V_33 = 0x00000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x80 ) )
V_33 |= 0x03000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x02 ) & 0x40 ) )
V_33 |= 0x00002000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x10 ) )
V_33 |= 0x00004000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x08 ) )
V_33 |= 0x00000003 ;
else
V_33 |= 0x14000000 ;
F_5 ( V_2 , 0x10f824 , V_37 , V_33 ) ;
F_14 ( V_2 , 1000 ) ;
if ( F_11 ( V_26 , V_24 + 0x08 ) & 0x01 )
V_33 = 0x00100000 ;
else
V_33 = 0x00000000 ;
F_5 ( V_2 , 0x10f82c , 0x00100000 , V_33 ) ;
F_5 ( V_2 , 0x10f248 , 0xffffffff , F_15 ( V_26 , V_34 + 0x28 ) ) ;
F_5 ( V_2 , 0x10f290 , 0xffffffff , F_15 ( V_26 , V_34 + 0x00 ) ) ;
F_5 ( V_2 , 0x10f294 , 0xffffffff , F_15 ( V_26 , V_34 + 0x04 ) ) ;
F_5 ( V_2 , 0x10f298 , 0xffffffff , F_15 ( V_26 , V_34 + 0x08 ) ) ;
F_5 ( V_2 , 0x10f29c , 0xffffffff , F_15 ( V_26 , V_34 + 0x0c ) ) ;
F_5 ( V_2 , 0x10f2a0 , 0xffffffff , F_15 ( V_26 , V_34 + 0x10 ) ) ;
F_5 ( V_2 , 0x10f2a4 , 0xffffffff , F_15 ( V_26 , V_34 + 0x14 ) ) ;
F_5 ( V_2 , 0x10f2a8 , 0xffffffff , F_15 ( V_26 , V_34 + 0x18 ) ) ;
F_5 ( V_2 , 0x10f2ac , 0xffffffff , F_15 ( V_26 , V_34 + 0x1c ) ) ;
F_5 ( V_2 , 0x10f2cc , 0xffffffff , F_15 ( V_26 , V_34 + 0x20 ) ) ;
F_5 ( V_2 , 0x10f2e8 , 0xffffffff , F_15 ( V_26 , V_34 + 0x24 ) ) ;
V_37 = 0x33f00000 ;
V_33 = 0x00000000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x01 ) & 0x04 ) )
V_33 |= 0x20200000 ;
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x80 ) )
V_33 |= 0x12800000 ;
if ( ( F_11 ( V_26 , V_24 + 0x03 ) & 0xf0 ) ) {
if ( F_11 ( V_26 , V_31 + 0x08 ) & 0x0c ) {
if ( ! ( F_11 ( V_26 , V_24 + 0x07 ) & 0x80 ) )
V_37 |= 0x00000020 ;
else
V_33 |= 0x00000020 ;
V_37 |= 0x08000004 ;
}
V_33 |= 0x04000000 ;
} else {
V_37 |= 0x44000020 ;
V_33 |= 0x08000004 ;
}
F_5 ( V_2 , 0x10f808 , V_37 , V_33 ) ;
V_33 = F_11 ( V_26 , V_24 + 0x03 ) & 0x0f ;
F_9 ( V_2 , 0x10f870 , 0x11111111 * V_33 ) ;
V_33 = F_16 ( V_26 , V_34 + 0x2c ) ;
F_5 ( V_2 , 0x10f250 , 0x000003f0 , ( V_33 & 0x003f ) << 4 ) ;
if ( ( ( F_15 ( V_26 , V_34 + 0x2c ) & 0x00001fc0 ) >> 6 ) >
( ( F_15 ( V_26 , V_34 + 0x28 ) & 0x7f000000 ) >> 24 ) )
V_33 = ( F_15 ( V_26 , V_34 + 0x2c ) & 0x00001fc0 ) >> 6 ;
else
V_33 = ( F_15 ( V_26 , V_34 + 0x28 ) & 0x1f000000 ) >> 24 ;
F_5 ( V_2 , 0x10f24c , 0x7f000000 , V_33 << 24 ) ;
V_33 = F_11 ( V_26 , V_34 + 0x30 ) ;
F_5 ( V_2 , 0x10f224 , 0x001f0000 , ( V_33 & 0xf8 ) << 13 ) ;
F_9 ( V_2 , 0x10f090 , 0x4000007f ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x10f314 , 0x00000001 ) ;
F_9 ( V_2 , 0x10f310 , 0x00000001 ) ;
F_9 ( V_2 , 0x10f210 , 0x80000000 ) ;
F_14 ( V_2 , 1000 ) ;
F_18 ( V_2 , V_38 [ 0 ] ) ;
F_5 ( V_2 , V_38 [ 0 ] , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_38 [ 0 ] , 0x100 , 0x000 ) ;
F_5 ( V_2 , V_38 [ 2 ] , 0xfff , V_5 -> V_32 . V_38 [ 2 ] ) ;
F_9 ( V_2 , V_38 [ 0 ] , V_5 -> V_32 . V_38 [ 0 ] ) ;
F_14 ( V_2 , 1000 ) ;
F_18 ( V_2 , V_38 [ 0 ] ) ;
F_5 ( V_2 , V_38 [ 0 ] , 0x100 , 0x100 ) ;
F_5 ( V_2 , V_38 [ 0 ] , 0x100 , 0x000 ) ;
if ( V_35 == 0 && F_13 ( V_2 , V_39 ) ) {
T_1 V_40 = F_5 ( V_2 , V_39 , 0x3000 , V_2 -> V_41 [ 0 ] ) ;
if ( V_40 != F_8 ( V_2 , V_39 ) ) {
F_9 ( V_2 , V_42 , 1 ) ;
F_14 ( V_2 , 20000 ) ;
}
}
if ( V_5 -> V_23 != 2 ) {
F_5 ( V_2 , 0x10f830 , 0x01000000 , 0x01000000 ) ;
F_5 ( V_2 , 0x10f830 , 0x01000000 , 0x00000000 ) ;
}
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x80000000 ) ;
F_9 ( V_2 , 0x10f318 , 0x00000001 ) ;
F_5 ( V_2 , 0x10f200 , 0x80000000 , 0x00000000 ) ;
F_14 ( V_2 , 1000 ) ;
F_9 ( V_2 , 0x62c000 , 0x0f0f0f00 ) ;
if ( F_11 ( V_26 , V_31 + 0x08 ) & 0x01 )
V_33 = 0x00000800 ;
else
V_33 = 0x00000000 ;
F_5 ( V_2 , 0x10f200 , 0x00000800 , V_33 ) ;
return 0 ;
}
static int
F_19 ( struct V_6 * V_7 , T_1 V_30 )
{
struct V_25 * V_26 = V_25 ( V_7 ) ;
struct V_4 * V_5 = ( void * ) V_7 -> V_5 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_45 V_46 ;
int V_47 , V_48 , V_49 , V_9 ;
T_1 V_33 ;
T_2 V_50 ;
V_5 -> V_32 . V_31 . V_33 = F_20 ( V_26 , V_30 / 1000 ,
& V_5 -> V_32 . V_31 . V_51 ,
& V_5 -> V_32 . V_31 . V_52 , & V_50 ,
& V_5 -> V_32 . V_24 . V_52 ) ;
if ( ! V_5 -> V_32 . V_31 . V_33 || V_5 -> V_32 . V_31 . V_51 != 0x11 ||
V_5 -> V_32 . V_31 . V_52 < 0x09 ) {
F_21 ( V_7 , L_1 ) ;
return - V_53 ;
}
if ( V_45 ( V_26 , 'M' , & V_46 ) || V_46 . V_51 != 2 || V_46 . V_54 < 3 ) {
F_21 ( V_7 , L_2 ) ;
return - V_53 ;
}
V_49 = ( F_4 ( V_7 , 0x101000 ) & 0x0000003c ) >> 2 ;
V_33 = F_16 ( V_26 , V_46 . V_55 + 1 ) ;
if ( V_33 )
V_49 = F_11 ( V_26 , V_33 + V_49 ) ;
if ( V_49 >= V_50 ) {
F_21 ( V_7 , L_3 ) ;
return - V_53 ;
}
V_5 -> V_32 . V_24 . V_51 = V_5 -> V_32 . V_31 . V_51 ;
V_5 -> V_32 . V_24 . V_33 = V_5 -> V_32 . V_31 . V_33 + V_5 -> V_32 . V_31 . V_52 +
( V_5 -> V_32 . V_24 . V_52 * V_49 ) ;
if ( ! V_5 -> V_32 . V_24 . V_33 || V_5 -> V_32 . V_24 . V_51 != 0x11 ||
V_5 -> V_32 . V_24 . V_52 < 0x08 ) {
F_21 ( V_7 , L_4 ) ;
return - V_53 ;
}
V_49 = F_11 ( V_26 , V_5 -> V_32 . V_24 . V_33 + 0x00 ) ;
if ( V_49 != 0xff ) {
V_5 -> V_32 . V_34 . V_33 =
F_22 ( V_26 , V_49 ,
& V_5 -> V_32 . V_34 . V_51 ,
& V_5 -> V_32 . V_34 . V_52 ) ;
if ( ! V_5 -> V_32 . V_34 . V_33 ||
V_5 -> V_32 . V_34 . V_51 != 0x20 ||
V_5 -> V_32 . V_34 . V_52 < 0x33 ) {
F_21 ( V_7 , L_5 ) ;
return - V_53 ;
}
} else {
V_5 -> V_32 . V_34 . V_33 = 0 ;
}
V_47 = F_23 ( V_2 , V_7 ) ;
if ( V_47 )
return V_47 ;
V_5 -> V_23 = ( V_30 > V_2 -> V_56 . V_57 . V_58 ) ? 2 : 1 ;
V_5 -> V_22 = F_8 ( V_2 , 0x1373f4 ) & 0x0000000f ;
V_48 = V_30 ;
if ( V_5 -> V_23 == 2 )
V_48 = V_2 -> V_59 . V_48 ;
V_47 = F_24 ( F_25 ( V_7 ) , & V_2 -> V_56 , V_48 , & V_5 -> V_17 ,
& V_5 -> V_20 , & V_5 -> V_18 , & V_5 -> V_16 ) ;
V_2 -> V_59 . V_48 = V_47 ;
if ( V_47 <= 0 ) {
F_21 ( V_7 , L_6 ) ;
return - V_53 ;
}
if ( V_5 -> V_23 == 2 ) {
V_2 -> V_59 . V_60 = 1 ;
V_2 -> V_59 . V_61 = 2 ;
V_47 = F_24 ( F_25 ( V_7 ) , & V_2 -> V_59 , V_30 ,
& V_5 -> V_13 , NULL , & V_5 -> V_14 , & V_5 -> V_12 ) ;
if ( V_47 <= 0 ) {
F_21 ( V_7 , L_7 ) ;
return - V_53 ;
}
}
for ( V_9 = 0 ; V_9 < F_26 ( V_2 -> V_62 ) ; V_9 ++ ) {
if ( F_13 ( V_2 , V_38 [ V_9 ] ) )
V_5 -> V_32 . V_38 [ V_9 ] = F_8 ( V_2 , V_38 [ V_9 ] ) ;
}
switch ( V_5 -> V_32 . type ) {
case V_63 :
V_47 = F_27 ( & V_5 -> V_32 ) ;
if ( V_47 == 0 )
V_47 = F_17 ( V_7 , V_30 ) ;
break;
case V_64 :
V_47 = F_28 ( & V_5 -> V_32 ) ;
if ( V_47 == 0 )
V_47 = F_12 ( V_7 , V_30 ) ;
break;
default:
V_47 = - V_65 ;
break;
}
return V_47 ;
}
static int
F_29 ( struct V_6 * V_7 )
{
struct V_66 * V_67 = F_30 ( V_7 ) ;
struct V_4 * V_5 = ( void * ) V_7 -> V_5 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
F_31 ( V_2 , F_32 ( V_67 -> V_68 , L_8 , false ) ) ;
return 0 ;
}
static void
F_33 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = ( void * ) V_7 -> V_5 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
F_31 ( V_2 , false ) ;
}
static int
F_34 ( struct V_69 * V_70 )
{
struct V_6 * V_7 = ( void * ) V_70 -> V_71 ;
struct V_4 * V_5 = ( void * ) V_70 ;
struct V_25 * V_26 = V_25 ( V_7 ) ;
static const T_2 V_72 [] = {
0x00 , 0xff , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0xff , 0xff , 0x00 , 0xff , 0x00 ,
} ;
static const T_1 V_73 [] = {
0x00000000 , 0xffffffff ,
0x55555555 , 0xaaaaaaaa ,
0x33333333 , 0xcccccccc ,
0xf0f0f0f0 , 0x0f0f0f0f ,
0x00ff00ff , 0xff00ff00 ,
0x0000ffff , 0xffff0000 ,
} ;
T_2 V_74 , V_75 , V_50 , V_76 , V_77 , V_78 ;
T_1 V_33 , V_79 ;
int V_47 , V_9 ;
V_47 = F_35 ( & V_5 -> V_32 ) ;
if ( V_47 )
return V_47 ;
V_33 = F_36 ( V_26 , & V_74 , & V_75 , & V_50 , & V_76 , & V_77 , & V_78 ) ;
if ( ! V_33 || V_75 < 0x15 )
return - V_53 ;
V_50 = F_11 ( V_26 , V_33 + 0x14 ) ;
V_33 = F_15 ( V_26 , V_33 + 0x10 ) ;
V_79 = F_4 ( V_7 , 0x10f65c ) ;
for ( V_9 = 0 ; V_9 < V_50 ; V_9 ++ ) {
F_37 ( V_7 , 0x10f65c , 0x000000f0 , V_9 << 4 ) ;
F_38 (&(struct nvbios_init) {
.subdev = nv_subdev(pfb),
.bios = bios,
.offset = nv_ro32(bios, data),
.execute = 1 ,
}) ;
V_33 += 4 ;
}
F_39 ( V_7 , 0x10f65c , V_79 ) ;
switch ( V_5 -> V_32 . type ) {
case V_64 :
for ( V_9 = 0 ; V_9 < 0x30 ; V_9 ++ ) {
F_39 ( V_7 , 0x10f968 , 0x00000000 | ( V_9 << 8 ) ) ;
F_39 ( V_7 , 0x10f920 , 0x00000000 | V_72 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f918 , V_73 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f920 , 0x00000100 | V_72 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f918 , V_73 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f96c , 0x00000000 | ( V_9 << 8 ) ) ;
F_39 ( V_7 , 0x10f924 , 0x00000000 | V_72 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f91c , V_73 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f924 , 0x00000100 | V_72 [ V_9 % 12 ] ) ;
F_39 ( V_7 , 0x10f91c , V_73 [ V_9 % 12 ] ) ;
}
for ( V_9 = 0 ; V_9 < 0x100 ; V_9 ++ ) {
F_39 ( V_7 , 0x10f968 , V_9 ) ;
F_39 ( V_7 , 0x10f900 , V_73 [ 2 + ( V_9 & 1 ) ] ) ;
}
for ( V_9 = 0 ; V_9 < 0x100 ; V_9 ++ ) {
F_39 ( V_7 , 0x10f96c , V_9 ) ;
F_39 ( V_7 , 0x10f900 , V_73 [ 2 + ( V_9 & 1 ) ] ) ;
}
break;
default:
break;
}
return 0 ;
}
static int
F_40 ( struct V_69 * V_71 , struct V_69 * V_80 ,
struct V_81 * V_82 , void * V_33 , T_1 V_52 ,
struct V_69 * * V_83 )
{
struct V_6 * V_7 = V_6 ( V_71 ) ;
struct V_25 * V_26 = V_25 ( V_7 ) ;
struct V_84 * V_85 = V_84 ( V_7 ) ;
struct V_86 V_87 ;
struct V_4 * V_5 ;
int V_47 ;
V_47 = F_41 ( V_71 , V_80 , V_82 , & V_5 ) ;
* V_83 = F_42 ( V_5 ) ;
if ( V_47 )
return V_47 ;
switch ( V_5 -> V_32 . type ) {
case V_63 :
case V_64 :
V_5 -> V_32 . V_88 = F_19 ;
V_5 -> V_32 . V_89 = F_29 ;
V_5 -> V_32 . V_90 = F_33 ;
break;
default:
F_43 ( V_7 , L_9 ) ;
break;
}
V_47 = F_44 ( V_26 , 0x0c , & V_5 -> V_2 . V_56 ) ;
if ( V_47 ) {
F_21 ( V_7 , L_10 ) ;
return V_47 ;
}
V_47 = F_44 ( V_26 , 0x04 , & V_5 -> V_2 . V_59 ) ;
if ( V_47 ) {
F_21 ( V_7 , L_11 ) ;
return V_47 ;
}
V_47 = V_85 -> V_91 ( V_85 , 0 , 0x18 , V_92 , & V_87 ) ;
if ( V_47 == 0 ) {
V_5 -> V_2 . V_93 = F_45 ( 0x00d610 + ( V_87 . line * 0x04 ) ) ;
V_5 -> V_2 . V_44 [ 0 ] = ( V_87 . log [ 0 ] ^ 2 ) << 12 ;
V_5 -> V_2 . V_44 [ 1 ] = ( V_87 . log [ 1 ] ^ 2 ) << 12 ;
}
V_47 = V_85 -> V_91 ( V_85 , 0 , 0x2e , V_92 , & V_87 ) ;
if ( V_47 == 0 ) {
V_5 -> V_2 . V_94 = F_45 ( 0x00d610 + ( V_87 . line * 0x04 ) ) ;
V_5 -> V_2 . V_41 [ 0 ] = ( V_87 . log [ 0 ] ^ 2 ) << 12 ;
V_5 -> V_2 . V_41 [ 1 ] = ( V_87 . log [ 1 ] ^ 2 ) << 12 ;
}
V_5 -> V_2 . V_95 = F_45 ( 0x00d604 ) ;
V_5 -> V_2 . V_96 = F_45 ( 0x132020 ) ;
V_5 -> V_2 . V_97 = F_45 ( 0x132028 ) ;
V_5 -> V_2 . V_98 = F_45 ( 0x132024 ) ;
V_5 -> V_2 . V_99 = F_45 ( 0x132030 ) ;
V_5 -> V_2 . V_100 = F_45 ( 0x132034 ) ;
V_5 -> V_2 . V_101 = F_45 ( 0x132000 ) ;
V_5 -> V_2 . V_102 = F_45 ( 0x132004 ) ;
V_5 -> V_2 . V_103 = F_45 ( 0x132040 ) ;
V_5 -> V_2 . V_104 = F_45 ( 0x10f248 ) ;
V_5 -> V_2 . V_105 = F_45 ( 0x10f290 ) ;
V_5 -> V_2 . V_106 = F_45 ( 0x10f294 ) ;
V_5 -> V_2 . V_107 = F_45 ( 0x10f298 ) ;
V_5 -> V_2 . V_108 = F_45 ( 0x10f29c ) ;
V_5 -> V_2 . V_109 = F_45 ( 0x10f2a0 ) ;
V_5 -> V_2 . V_110 = F_45 ( 0x10f2a4 ) ;
V_5 -> V_2 . V_111 = F_45 ( 0x10f2a8 ) ;
V_5 -> V_2 . V_112 = F_45 ( 0x10f2ac ) ;
V_5 -> V_2 . V_113 = F_45 ( 0x10f2cc ) ;
V_5 -> V_2 . V_114 = F_45 ( 0x10f2e8 ) ;
V_5 -> V_2 . V_115 = F_45 ( 0x10f250 ) ;
V_5 -> V_2 . V_116 = F_45 ( 0x10f24c ) ;
V_5 -> V_2 . V_117 = F_45 ( 0x10fec4 ) ;
V_5 -> V_2 . V_118 = F_45 ( 0x10fec8 ) ;
V_5 -> V_2 . V_119 = F_45 ( 0x10f604 ) ;
V_5 -> V_2 . V_120 = F_45 ( 0x10f614 ) ;
V_5 -> V_2 . V_121 = F_45 ( 0x10f610 ) ;
V_5 -> V_2 . V_122 = F_45 ( 0x100770 ) ;
V_5 -> V_2 . V_123 = F_45 ( 0x100778 ) ;
V_5 -> V_2 . V_124 = F_45 ( 0x10f224 ) ;
V_5 -> V_2 . V_125 = F_45 ( 0x10f870 ) ;
V_5 -> V_2 . V_126 = F_45 ( 0x10f698 ) ;
V_5 -> V_2 . V_127 = F_45 ( 0x10f694 ) ;
V_5 -> V_2 . V_128 = F_45 ( 0x10f6b8 ) ;
V_5 -> V_2 . V_129 = F_45 ( 0x10f808 ) ;
V_5 -> V_2 . V_130 = F_45 ( 0x10f670 ) ;
V_5 -> V_2 . V_131 = F_45 ( 0x10f60c ) ;
V_5 -> V_2 . V_132 = F_45 ( 0x10f830 ) ;
V_5 -> V_2 . V_133 = F_45 ( 0x1373ec ) ;
V_5 -> V_2 . V_134 = F_45 ( 0x10f800 ) ;
V_5 -> V_2 . V_135 = F_45 ( 0x10f82c ) ;
V_5 -> V_2 . V_136 = F_45 ( 0x10f978 ) ;
V_5 -> V_2 . V_137 = F_45 ( 0x10f910 ) ;
V_5 -> V_2 . V_138 = F_45 ( 0x10f914 ) ;
switch ( V_5 -> V_32 . type ) {
case V_64 :
V_5 -> V_2 . V_62 [ 0 ] = F_45 ( 0x10f300 ) ;
V_5 -> V_2 . V_62 [ 1 ] = F_45 ( 0x10f330 ) ;
V_5 -> V_2 . V_62 [ 2 ] = F_45 ( 0x10f334 ) ;
V_5 -> V_2 . V_62 [ 3 ] = F_45 ( 0x10f338 ) ;
V_5 -> V_2 . V_62 [ 4 ] = F_45 ( 0x10f33c ) ;
V_5 -> V_2 . V_62 [ 5 ] = F_45 ( 0x10f340 ) ;
V_5 -> V_2 . V_62 [ 6 ] = F_45 ( 0x10f344 ) ;
V_5 -> V_2 . V_62 [ 7 ] = F_45 ( 0x10f348 ) ;
V_5 -> V_2 . V_62 [ 8 ] = F_45 ( 0x10f354 ) ;
V_5 -> V_2 . V_62 [ 15 ] = F_45 ( 0x10f34c ) ;
break;
case V_63 :
V_5 -> V_2 . V_62 [ 0 ] = F_45 ( 0x10f300 ) ;
V_5 -> V_2 . V_62 [ 2 ] = F_45 ( 0x10f320 ) ;
break;
default:
break;
}
V_5 -> V_2 . V_139 = F_45 ( 0x62c000 ) ;
V_5 -> V_2 . V_140 = F_45 ( 0x10f200 ) ;
V_5 -> V_2 . V_141 = F_45 ( 0x10f210 ) ;
V_5 -> V_2 . V_142 = F_45 ( 0x10f310 ) ;
V_5 -> V_2 . V_143 = F_45 ( 0x10f314 ) ;
V_5 -> V_2 . V_144 = F_45 ( 0x10f318 ) ;
V_5 -> V_2 . V_145 = F_45 ( 0x10f090 ) ;
V_5 -> V_2 . V_146 = F_45 ( 0x10f69c ) ;
V_5 -> V_2 . V_147 = F_45 ( 0x10f824 ) ;
V_5 -> V_2 . V_148 = F_45 ( 0x1373f0 ) ;
V_5 -> V_2 . V_149 = F_45 ( 0x1373f4 ) ;
V_5 -> V_2 . V_150 = F_45 ( 0x137320 ) ;
V_5 -> V_2 . V_151 = F_45 ( 0x10f65c ) ;
V_5 -> V_2 . V_152 = F_45 ( 0x10f6bc ) ;
V_5 -> V_2 . V_153 = F_45 ( 0x100710 ) ;
V_5 -> V_2 . V_154 = F_45 ( 0x10f750 ) ;
return 0 ;
}
