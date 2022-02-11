static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
F_3 ( ( V_2 | V_4 ) , V_1 + V_3 ) ;
#ifdef F_4
F_3 ( V_5 , V_1 + V_6 ) ;
#endif
}
static void F_5 ( void T_1 * V_1 )
{
F_6 ( L_1
L_2
L_1 , V_1 ) ;
F_6 ( L_3 , V_3 ,
F_2 ( V_1 + V_3 ) ) ;
F_6 ( L_4 , V_7 ,
F_2 ( V_1 + V_7 ) ) ;
F_6 ( L_5 , V_8 ,
F_2 ( V_1 + V_8 ) ) ;
F_6 ( L_6 ,
V_9 , F_2 ( V_1 + V_9 ) ) ;
F_6 ( L_7 ,
V_10 , F_2 ( V_1 + V_10 ) ) ;
F_6 ( L_8 ,
V_11 , F_2 ( V_1 + V_11 ) ) ;
F_6 ( L_9 , V_6 ,
F_2 ( V_1 + V_6 ) ) ;
F_6 ( L_10 , V_12 ,
F_2 ( V_1 + V_12 ) ) ;
}
static int F_7 ( void T_1 * V_1 )
{
return 0 ;
}
static int F_8 ( void T_1 * V_1 ,
struct V_13 * V_14 )
{
return 0 ;
}
static void F_9 ( void T_1 * V_1 , unsigned char * V_15 ,
unsigned int V_16 )
{
F_10 ( V_1 , V_15 , V_7 , V_8 ) ;
}
static void F_11 ( void T_1 * V_1 , unsigned char * V_15 ,
unsigned int V_16 )
{
F_12 ( V_1 , V_15 , V_7 , V_8 ) ;
}
static void F_13 ( struct V_17 * V_18 , int V_19 )
{
void T_1 * V_1 = ( void T_1 * ) V_18 -> V_20 ;
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
if ( V_18 -> V_21 & V_22 ) {
V_2 |= V_23 ;
V_2 &= ~ ( V_24 | V_25 | V_26 |
V_27 ) ;
} else if ( ( F_14 ( V_18 ) > V_28 )
|| ( V_18 -> V_21 & V_29 ) ) {
V_2 |= V_24 ;
V_2 &= ~ ( V_23 | V_25 | V_26 ) ;
F_3 ( 0xffffffff , V_1 + V_9 ) ;
F_3 ( 0xffffffff , V_1 + V_10 ) ;
} else if ( F_15 ( V_18 ) ) {
V_2 &= ~ ( V_24 | V_23 | V_25 |
V_26 | V_27 ) ;
} else {
T_2 V_30 [ 2 ] ;
struct V_31 * V_32 ;
V_2 |= V_27 ;
V_2 &= ~ ( V_24 | V_23 |
V_25 | V_26 ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
F_16 (ha, dev) {
int V_33 = F_17 ( V_34 , V_32 -> V_15 ) >> 26 ;
V_30 [ V_33 >> 5 ] |= 1 << ( V_33 & 31 ) ;
}
F_3 ( V_30 [ 0 ] , V_1 + V_10 ) ;
F_3 ( V_30 [ 1 ] , V_1 + V_9 ) ;
}
F_3 ( V_2 , V_1 + V_3 ) ;
}
static void F_18 ( void T_1 * V_1 , unsigned int V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
unsigned int V_38 = V_39 ;
if ( V_35 )
V_38 |= ( V_37 << V_40 ) ;
F_3 ( V_38 , V_1 + V_11 ) ;
}
static void F_19 ( void T_1 * V_1 , unsigned long V_41 )
{
return;
}
struct V_42 * F_20 ( void T_1 * V_1 )
{
struct V_42 * V_43 ;
V_43 = F_21 ( sizeof( const struct V_42 ) , V_44 ) ;
if ( ! V_43 )
return NULL ;
F_6 ( L_11 ) ;
V_43 -> V_43 = & V_45 ;
V_43 -> V_46 = & V_47 ;
V_43 -> V_48 . V_49 = V_50 ;
V_43 -> V_48 . V_35 = V_51 ;
V_43 -> V_48 . V_52 = 0 ;
V_43 -> V_53 . V_15 = V_54 ;
V_43 -> V_53 . V_55 = V_56 ;
V_43 -> V_57 = 0 ;
return V_43 ;
}
