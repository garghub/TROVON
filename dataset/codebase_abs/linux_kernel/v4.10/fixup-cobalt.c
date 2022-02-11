static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == F_2 ( 0 , 0 ) &&
( V_2 -> V_4 >> 8 ) == V_5 ) {
V_2 -> V_4 = ( V_6 << 8 ) | ( V_2 -> V_4 & 0xff ) ;
F_3 ( V_7 L_1 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned short V_8 ;
unsigned char V_9 ;
F_5 ( V_2 , V_10 , & V_8 ) ;
V_8 |= ( V_11 | V_12 ) ;
F_6 ( V_2 , V_10 , V_8 ) ;
F_7 ( V_2 , 0x40 , 0xb ) ;
F_8 ( V_2 , V_13 , & V_9 ) ;
if ( V_9 < 64 )
F_7 ( V_2 , V_13 , 64 ) ;
F_7 ( V_2 , V_14 , 8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != F_2 ( 0 , 0 ) )
return;
F_7 ( V_2 , V_13 , 64 ) ;
F_7 ( V_2 , V_14 , 8 ) ;
F_3 ( V_7 L_2 , V_2 -> V_15 ) ;
#if 0
if (dev->revision >= 0x10) {
GT_WRITE(GT_PCI0_TOR_OFS, 0x4020);
} else if (dev->revision == 0x1 || dev->revision == 0x2)
#endif
{
signed int V_16 ;
V_16 = F_10 ( V_17 ) ;
F_11 ( V_17 ,
( 0xff << 16 ) |
( 0xff << 8 ) |
0xff ) ;
F_11 ( V_18 , V_19 | F_10 ( V_18 ) ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_20 ;
int V_21 ;
V_21 = F_8 ( V_2 , V_22 , & V_20 ) ;
if ( V_21 ) {
F_13 ( L_3 ) ;
return;
}
V_23 = F_14 ( V_20 ) ;
F_3 ( V_7 L_4 , V_23 ) ;
}
int T_2 F_15 ( const struct V_1 * V_2 , T_1 V_24 , T_1 V_25 )
{
if ( V_23 <= V_26 )
return V_27 [ V_24 ] ;
if ( V_23 == V_28 )
return V_29 [ V_24 ] ;
return V_30 [ V_24 ] ;
}
int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
