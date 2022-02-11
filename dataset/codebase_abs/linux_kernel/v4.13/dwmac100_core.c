static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
F_3 ( ( V_6 | V_8 ) , V_4 + V_7 ) ;
#ifdef F_4
F_3 ( V_9 , V_4 + V_10 ) ;
#endif
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_11 )
{
void T_1 * V_4 = V_2 -> V_5 ;
V_11 [ V_7 / 4 ] = F_2 ( V_4 + V_7 ) ;
V_11 [ V_12 / 4 ] = F_2 ( V_4 + V_12 ) ;
V_11 [ V_13 / 4 ] = F_2 ( V_4 + V_13 ) ;
V_11 [ V_14 / 4 ] = F_2 ( V_4 + V_14 ) ;
V_11 [ V_15 / 4 ] = F_2 ( V_4 + V_15 ) ;
V_11 [ V_16 / 4 ] = F_2 ( V_4 + V_16 ) ;
V_11 [ V_10 / 4 ] = F_2 ( V_4 + V_10 ) ;
V_11 [ V_17 / 4 ] = F_2 ( V_4 + V_17 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_20 ,
unsigned int V_21 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_20 , V_12 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned char * V_20 ,
unsigned int V_21 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_11 ( V_4 , V_20 , V_12 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
void T_1 * V_4 = ( void T_1 * ) V_23 -> V_24 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_23 -> V_25 & V_26 ) {
V_6 |= V_27 ;
V_6 &= ~ ( V_28 | V_29 | V_30 |
V_31 ) ;
} else if ( ( F_13 ( V_23 ) > V_32 )
|| ( V_23 -> V_25 & V_33 ) ) {
V_6 |= V_28 ;
V_6 &= ~ ( V_27 | V_29 | V_30 ) ;
F_3 ( 0xffffffff , V_4 + V_14 ) ;
F_3 ( 0xffffffff , V_4 + V_15 ) ;
} else if ( F_14 ( V_23 ) ) {
V_6 &= ~ ( V_28 | V_27 | V_29 |
V_30 | V_31 ) ;
} else {
T_2 V_34 [ 2 ] ;
struct V_35 * V_36 ;
V_6 |= V_31 ;
V_6 &= ~ ( V_28 | V_27 |
V_29 | V_30 ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
F_15 (ha, dev) {
int V_37 = F_16 ( V_38 , V_36 -> V_20 ) >> 26 ;
V_34 [ V_37 >> 5 ] |= 1 << ( V_37 & 31 ) ;
}
F_3 ( V_34 [ 0 ] , V_4 + V_15 ) ;
F_3 ( V_34 [ 1 ] , V_4 + V_14 ) ;
}
F_3 ( V_6 , V_4 + V_7 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_39 ,
unsigned int V_40 , unsigned int V_41 ,
T_2 V_42 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_43 = V_44 ;
if ( V_39 )
V_43 |= ( V_41 << V_45 ) ;
F_3 ( V_43 , V_4 + V_16 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned long V_46 )
{
return;
}
struct V_1 * F_19 ( void T_1 * V_4 , int * V_47 )
{
struct V_1 * V_48 ;
V_48 = F_20 ( sizeof( const struct V_1 ) , V_49 ) ;
if ( ! V_48 )
return NULL ;
F_21 ( L_1 ) ;
V_48 -> V_5 = V_4 ;
V_48 -> V_48 = & V_50 ;
V_48 -> V_51 = & V_52 ;
V_48 -> V_53 . V_39 = V_54 ;
V_48 -> V_53 . V_55 = 0 ;
V_48 -> V_53 . V_56 = 0 ;
V_48 -> V_53 . V_57 = 0 ;
V_48 -> V_53 . V_58 = V_59 ;
V_48 -> V_60 . V_20 = V_61 ;
V_48 -> V_60 . V_62 = V_63 ;
V_48 -> V_60 . V_64 = 11 ;
V_48 -> V_60 . V_65 = 0x0000F800 ;
V_48 -> V_60 . V_66 = 6 ;
V_48 -> V_60 . V_67 = 0x000007C0 ;
V_48 -> V_60 . V_68 = 2 ;
V_48 -> V_60 . V_69 = F_22 ( 5 , 2 ) ;
* V_47 = 0 ;
return V_48 ;
}
