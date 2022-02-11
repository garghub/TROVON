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
}
static void F_8 ( void T_1 * V_1 )
{
return;
}
static void F_9 ( void T_1 * V_1 , unsigned char * V_13 ,
unsigned int V_14 )
{
F_10 ( V_1 , V_13 , V_7 , V_8 ) ;
}
static void F_11 ( void T_1 * V_1 , unsigned char * V_13 ,
unsigned int V_14 )
{
F_12 ( V_1 , V_13 , V_7 , V_8 ) ;
}
static void F_13 ( struct V_15 * V_16 )
{
void T_1 * V_1 = ( void T_1 * ) V_16 -> V_17 ;
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
if ( V_16 -> V_18 & V_19 ) {
V_2 |= V_20 ;
V_2 &= ~ ( V_21 | V_22 | V_23 |
V_24 ) ;
} else if ( ( F_14 ( V_16 ) > V_25 )
|| ( V_16 -> V_18 & V_26 ) ) {
V_2 |= V_21 ;
V_2 &= ~ ( V_20 | V_22 | V_23 ) ;
F_3 ( 0xffffffff , V_1 + V_9 ) ;
F_3 ( 0xffffffff , V_1 + V_10 ) ;
} else if ( F_15 ( V_16 ) ) {
V_2 &= ~ ( V_21 | V_20 | V_22 |
V_23 | V_24 ) ;
} else {
T_2 V_27 [ 2 ] ;
struct V_28 * V_29 ;
V_2 |= V_24 ;
V_2 &= ~ ( V_21 | V_20 |
V_22 | V_23 ) ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
F_16 (ha, dev) {
int V_30 =
F_17 ( V_31 , V_29 -> V_13 ) >> 26 ;
V_27 [ V_30 >> 5 ] |= 1 << ( V_30 & 31 ) ;
}
F_3 ( V_27 [ 0 ] , V_1 + V_10 ) ;
F_3 ( V_27 [ 1 ] , V_1 + V_9 ) ;
}
F_3 ( V_2 , V_1 + V_3 ) ;
F_18 ( V_32 L_11
L_12 ,
V_33 , F_2 ( V_1 + V_3 ) ,
F_2 ( V_1 + V_9 ) , F_2 ( V_1 + V_10 ) ) ;
}
static void F_19 ( void T_1 * V_1 , unsigned int V_34 ,
unsigned int V_35 , unsigned int V_36 )
{
unsigned int V_37 = V_38 ;
if ( V_34 )
V_37 |= ( V_36 << V_39 ) ;
F_3 ( V_37 , V_1 + V_11 ) ;
}
static void F_20 ( void T_1 * V_1 , unsigned long V_40 )
{
return;
}
struct V_41 * F_21 ( void T_1 * V_1 )
{
struct V_41 * V_42 ;
V_42 = F_22 ( sizeof( const struct V_41 ) , V_43 ) ;
if ( ! V_42 )
return NULL ;
F_7 ( L_13 ) ;
V_42 -> V_42 = & V_44 ;
V_42 -> V_45 = & V_46 ;
V_42 -> V_47 . V_48 = V_49 ;
V_42 -> V_47 . V_34 = V_50 ;
V_42 -> V_47 . V_51 = 0 ;
V_42 -> V_52 . V_13 = V_53 ;
V_42 -> V_52 . V_54 = V_55 ;
V_42 -> V_56 = 0 ;
return V_42 ;
}
