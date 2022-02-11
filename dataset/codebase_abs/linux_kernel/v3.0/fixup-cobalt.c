static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == F_2 ( 0 , 0 ) &&
( V_2 -> V_4 >> 8 ) == V_5 ) {
V_2 -> V_4 = ( V_6 << 8 ) | ( V_2 -> V_4 & 0xff ) ;
F_3 ( V_7 L_1 ) ;
}
}
static void T_1 F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
unsigned long V_13 = V_11 -> V_14 ;
struct V_8 V_15 = * V_9 ;
if ( ! ( V_9 -> V_16 & V_17 ) ||
! ( V_9 -> V_16 & V_18 ) )
return;
V_9 -> V_19 -= V_13 ;
V_9 -> V_20 -= V_13 ;
F_5 ( V_21 , & V_2 -> V_2 , L_2 ,
& V_15 , V_9 ) ;
}
static void T_1 F_6 ( struct V_1 * V_2 )
{
T_2 V_4 ;
T_3 V_22 ;
V_4 = V_2 -> V_4 >> 8 ;
if ( V_4 != V_23 )
return;
F_7 ( V_2 , V_24 , & V_22 ) ;
if ( ( V_22 & 1 ) == 0 ) {
F_4 ( V_2 , & V_2 -> V_8 [ 0 ] ) ;
F_4 ( V_2 , & V_2 -> V_8 [ 1 ] ) ;
}
if ( ( V_22 & 4 ) == 0 ) {
F_4 ( V_2 , & V_2 -> V_8 [ 2 ] ) ;
F_4 ( V_2 , & V_2 -> V_8 [ 3 ] ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned short V_25 ;
unsigned char V_26 ;
F_9 ( V_2 , V_27 , & V_25 ) ;
V_25 |= ( V_28 | V_29 ) ;
F_10 ( V_2 , V_27 , V_25 ) ;
F_11 ( V_2 , 0x40 , 0xb ) ;
F_7 ( V_2 , V_30 , & V_26 ) ;
if ( V_26 < 64 )
F_11 ( V_2 , V_30 , 64 ) ;
F_11 ( V_2 , V_31 , 8 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != F_2 ( 0 , 0 ) )
return;
F_11 ( V_2 , V_30 , 64 ) ;
F_11 ( V_2 , V_31 , 8 ) ;
F_3 ( V_7 L_3 , V_2 -> V_32 ) ;
#if 0
if (dev->revision >= 0x10) {
GT_WRITE(GT_PCI0_TOR_OFS, 0x4020);
} else if (dev->revision == 0x1 || dev->revision == 0x2)
#endif
{
signed int V_33 ;
V_33 = F_13 ( V_34 ) ;
F_14 ( V_34 ,
( 0xff << 16 ) |
( 0xff << 8 ) |
0xff ) ;
F_14 ( V_35 , V_36 | F_13 ( V_35 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
T_3 V_37 ;
int V_38 ;
V_38 = F_7 ( V_2 , V_39 , & V_37 ) ;
if ( V_38 ) {
F_16 ( L_4 ) ;
return;
}
V_40 = F_17 ( V_37 ) ;
F_3 ( V_7 L_5 , V_40 ) ;
}
int T_4 F_18 ( const struct V_1 * V_2 , T_3 V_41 , T_3 V_42 )
{
if ( V_40 <= V_43 )
return V_44 [ V_41 ] ;
if ( V_40 == V_45 )
return V_46 [ V_41 ] ;
return V_47 [ V_41 ] ;
}
int F_19 ( struct V_1 * V_2 )
{
return 0 ;
}
