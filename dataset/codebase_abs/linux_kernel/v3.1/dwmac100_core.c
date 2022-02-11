static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
F_3 ( ( V_2 | V_4 ) , V_1 + V_3 ) ;
#ifdef F_4
F_3 ( V_5 , V_1 + V_6 ) ;
#endif
}
static int F_5 ( void T_1 * V_1 )
{
return 0 ;
}
static void F_6 ( void T_1 * V_1 )
{
F_7 ( L_1
L_2
L_1 ,
V_1 ) ;
F_7 ( L_3 , V_3 ,
F_2 ( V_1 + V_3 ) ) ;
F_7 ( L_4 , V_7 ,
F_2 ( V_1 + V_7 ) ) ;
F_7 ( L_5 , V_8 ,
F_2 ( V_1 + V_8 ) ) ;
F_7 ( L_6 ,
V_9 , F_2 ( V_1 + V_9 ) ) ;
F_7 ( L_7 ,
V_10 , F_2 ( V_1 + V_10 ) ) ;
F_7 ( L_8 ,
V_11 , F_2 ( V_1 + V_11 ) ) ;
F_7 ( L_9 , V_6 ,
F_2 ( V_1 + V_6 ) ) ;
F_7 ( L_10 , V_12 ,
F_2 ( V_1 + V_12 ) ) ;
F_7 ( L_11 ) ;
F_7 ( L_12 ,
V_13 , F_2 ( V_1 + V_13 ) ) ;
F_7 ( L_13 ,
V_14 , F_2 ( V_1 + V_14 ) ) ;
F_7 ( L_14 ,
V_15 , F_2 ( V_1 + V_15 ) ) ;
F_7 ( L_15 ,
V_16 , F_2 ( V_1 + V_16 ) ) ;
F_7 ( L_16 ,
V_17 , F_2 ( V_1 + V_17 ) ) ;
}
static void F_8 ( void T_1 * V_1 )
{
return;
}
static void F_9 ( void T_1 * V_1 , unsigned char * V_18 ,
unsigned int V_19 )
{
F_10 ( V_1 , V_18 , V_7 , V_8 ) ;
}
static void F_11 ( void T_1 * V_1 , unsigned char * V_18 ,
unsigned int V_19 )
{
F_12 ( V_1 , V_18 , V_7 , V_8 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
void T_1 * V_1 = ( void T_1 * ) V_21 -> V_22 ;
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
if ( V_21 -> V_23 & V_24 ) {
V_2 |= V_25 ;
V_2 &= ~ ( V_26 | V_27 | V_28 |
V_29 ) ;
} else if ( ( F_14 ( V_21 ) > V_30 )
|| ( V_21 -> V_23 & V_31 ) ) {
V_2 |= V_26 ;
V_2 &= ~ ( V_25 | V_27 | V_28 ) ;
F_3 ( 0xffffffff , V_1 + V_9 ) ;
F_3 ( 0xffffffff , V_1 + V_10 ) ;
} else if ( F_15 ( V_21 ) ) {
V_2 &= ~ ( V_26 | V_25 | V_27 |
V_28 | V_29 ) ;
} else {
T_2 V_32 [ 2 ] ;
struct V_33 * V_34 ;
V_2 |= V_29 ;
V_2 &= ~ ( V_26 | V_25 |
V_27 | V_28 ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
F_16 (ha, dev) {
int V_35 =
F_17 ( V_36 , V_34 -> V_18 ) >> 26 ;
V_32 [ V_35 >> 5 ] |= 1 << ( V_35 & 31 ) ;
}
F_3 ( V_32 [ 0 ] , V_1 + V_10 ) ;
F_3 ( V_32 [ 1 ] , V_1 + V_9 ) ;
}
F_3 ( V_2 , V_1 + V_3 ) ;
F_18 ( V_37 L_17
L_18 ,
V_38 , F_2 ( V_1 + V_3 ) ,
F_2 ( V_1 + V_9 ) , F_2 ( V_1 + V_10 ) ) ;
}
static void F_19 ( void T_1 * V_1 , unsigned int V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = V_43 ;
if ( V_39 )
V_42 |= ( V_41 << V_44 ) ;
F_3 ( V_42 , V_1 + V_11 ) ;
}
static void F_20 ( void T_1 * V_1 , unsigned long V_45 )
{
return;
}
struct V_46 * F_21 ( void T_1 * V_1 )
{
struct V_46 * V_47 ;
V_47 = F_22 ( sizeof( const struct V_46 ) , V_48 ) ;
if ( ! V_47 )
return NULL ;
F_7 ( L_19 ) ;
V_47 -> V_47 = & V_49 ;
V_47 -> V_50 = & V_51 ;
V_47 -> V_52 . V_53 = V_54 ;
V_47 -> V_52 . V_39 = V_55 ;
V_47 -> V_52 . V_56 = 0 ;
V_47 -> V_57 . V_18 = V_58 ;
V_47 -> V_57 . V_59 = V_60 ;
return V_47 ;
}
