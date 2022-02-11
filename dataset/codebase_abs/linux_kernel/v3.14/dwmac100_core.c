static void F_1 ( void T_1 * V_1 , int V_2 )
{
T_2 V_3 = F_2 ( V_1 + V_4 ) ;
F_3 ( ( V_3 | V_5 ) , V_1 + V_4 ) ;
#ifdef F_4
F_3 ( V_6 , V_1 + V_7 ) ;
#endif
}
static void F_5 ( void T_1 * V_1 )
{
F_6 ( L_1
L_2
L_1 , V_1 ) ;
F_6 ( L_3 , V_4 ,
F_2 ( V_1 + V_4 ) ) ;
F_6 ( L_4 , V_8 ,
F_2 ( V_1 + V_8 ) ) ;
F_6 ( L_5 , V_9 ,
F_2 ( V_1 + V_9 ) ) ;
F_6 ( L_6 ,
V_10 , F_2 ( V_1 + V_10 ) ) ;
F_6 ( L_7 ,
V_11 , F_2 ( V_1 + V_11 ) ) ;
F_6 ( L_8 ,
V_12 , F_2 ( V_1 + V_12 ) ) ;
F_6 ( L_9 , V_7 ,
F_2 ( V_1 + V_7 ) ) ;
F_6 ( L_10 , V_13 ,
F_2 ( V_1 + V_13 ) ) ;
}
static int F_7 ( void T_1 * V_1 )
{
return 0 ;
}
static int F_8 ( void T_1 * V_1 ,
struct V_14 * V_15 )
{
return 0 ;
}
static void F_9 ( void T_1 * V_1 , unsigned char * V_16 ,
unsigned int V_17 )
{
F_10 ( V_1 , V_16 , V_8 , V_9 ) ;
}
static void F_11 ( void T_1 * V_1 , unsigned char * V_16 ,
unsigned int V_17 )
{
F_12 ( V_1 , V_16 , V_8 , V_9 ) ;
}
static void F_13 ( struct V_18 * V_19 , int V_20 )
{
void T_1 * V_1 = ( void T_1 * ) V_19 -> V_21 ;
T_2 V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_19 -> V_22 & V_23 ) {
V_3 |= V_24 ;
V_3 &= ~ ( V_25 | V_26 | V_27 |
V_28 ) ;
} else if ( ( F_14 ( V_19 ) > V_29 )
|| ( V_19 -> V_22 & V_30 ) ) {
V_3 |= V_25 ;
V_3 &= ~ ( V_24 | V_26 | V_27 ) ;
F_3 ( 0xffffffff , V_1 + V_10 ) ;
F_3 ( 0xffffffff , V_1 + V_11 ) ;
} else if ( F_15 ( V_19 ) ) {
V_3 &= ~ ( V_25 | V_24 | V_26 |
V_27 | V_28 ) ;
} else {
T_2 V_31 [ 2 ] ;
struct V_32 * V_33 ;
V_3 |= V_28 ;
V_3 &= ~ ( V_25 | V_24 |
V_26 | V_27 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_16 (ha, dev) {
int V_34 = F_17 ( V_35 , V_33 -> V_16 ) >> 26 ;
V_31 [ V_34 >> 5 ] |= 1 << ( V_34 & 31 ) ;
}
F_3 ( V_31 [ 0 ] , V_1 + V_11 ) ;
F_3 ( V_31 [ 1 ] , V_1 + V_10 ) ;
}
F_3 ( V_3 , V_1 + V_4 ) ;
}
static void F_18 ( void T_1 * V_1 , unsigned int V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
unsigned int V_39 = V_40 ;
if ( V_36 )
V_39 |= ( V_38 << V_41 ) ;
F_3 ( V_39 , V_1 + V_12 ) ;
}
static void F_19 ( void T_1 * V_1 , unsigned long V_42 )
{
return;
}
struct V_43 * F_20 ( void T_1 * V_1 )
{
struct V_43 * V_44 ;
V_44 = F_21 ( sizeof( const struct V_43 ) , V_45 ) ;
if ( ! V_44 )
return NULL ;
F_6 ( L_11 ) ;
V_44 -> V_44 = & V_46 ;
V_44 -> V_47 = & V_48 ;
V_44 -> V_49 . V_50 = V_51 ;
V_44 -> V_49 . V_36 = V_52 ;
V_44 -> V_49 . V_53 = 0 ;
V_44 -> V_54 . V_16 = V_55 ;
V_44 -> V_54 . V_56 = V_57 ;
V_44 -> V_58 = 0 ;
return V_44 ;
}
