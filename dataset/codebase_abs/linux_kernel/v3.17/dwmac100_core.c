static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
F_3 ( ( V_6 | V_8 ) , V_4 + V_7 ) ;
#ifdef F_4
F_3 ( V_9 , V_4 + V_10 ) ;
#endif
}
static void F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_6 ( L_1
L_2
L_1 , V_4 ) ;
F_6 ( L_3 , V_7 ,
F_2 ( V_4 + V_7 ) ) ;
F_6 ( L_4 , V_11 ,
F_2 ( V_4 + V_11 ) ) ;
F_6 ( L_5 , V_12 ,
F_2 ( V_4 + V_12 ) ) ;
F_6 ( L_6 ,
V_13 , F_2 ( V_4 + V_13 ) ) ;
F_6 ( L_7 ,
V_14 , F_2 ( V_4 + V_14 ) ) ;
F_6 ( L_8 ,
V_15 , F_2 ( V_4 + V_15 ) ) ;
F_6 ( L_9 , V_10 ,
F_2 ( V_4 + V_10 ) ) ;
F_6 ( L_10 , V_16 ,
F_2 ( V_4 + V_16 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned char * V_19 ,
unsigned int V_20 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_10 ( V_4 , V_19 , V_11 , V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char * V_19 ,
unsigned int V_20 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_12 ( V_4 , V_19 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
void T_1 * V_4 = ( void T_1 * ) V_22 -> V_23 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_22 -> V_24 & V_25 ) {
V_6 |= V_26 ;
V_6 &= ~ ( V_27 | V_28 | V_29 |
V_30 ) ;
} else if ( ( F_14 ( V_22 ) > V_31 )
|| ( V_22 -> V_24 & V_32 ) ) {
V_6 |= V_27 ;
V_6 &= ~ ( V_26 | V_28 | V_29 ) ;
F_3 ( 0xffffffff , V_4 + V_13 ) ;
F_3 ( 0xffffffff , V_4 + V_14 ) ;
} else if ( F_15 ( V_22 ) ) {
V_6 &= ~ ( V_27 | V_26 | V_28 |
V_29 | V_30 ) ;
} else {
T_2 V_33 [ 2 ] ;
struct V_34 * V_35 ;
V_6 |= V_30 ;
V_6 &= ~ ( V_27 | V_26 |
V_28 | V_29 ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
F_16 (ha, dev) {
int V_36 = F_17 ( V_37 , V_35 -> V_19 ) >> 26 ;
V_33 [ V_36 >> 5 ] |= 1 << ( V_36 & 31 ) ;
}
F_3 ( V_33 [ 0 ] , V_4 + V_14 ) ;
F_3 ( V_33 [ 1 ] , V_4 + V_13 ) ;
}
F_3 ( V_6 , V_4 + V_7 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_38 ,
unsigned int V_39 , unsigned int V_40 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_41 = V_42 ;
if ( V_38 )
V_41 |= ( V_40 << V_43 ) ;
F_3 ( V_41 , V_4 + V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned long V_44 )
{
return;
}
struct V_1 * F_20 ( void T_1 * V_4 )
{
struct V_1 * V_45 ;
V_45 = F_21 ( sizeof( const struct V_1 ) , V_46 ) ;
if ( ! V_45 )
return NULL ;
F_6 ( L_11 ) ;
V_45 -> V_5 = V_4 ;
V_45 -> V_45 = & V_47 ;
V_45 -> V_48 = & V_49 ;
V_45 -> V_50 . V_51 = V_52 ;
V_45 -> V_50 . V_38 = V_53 ;
V_45 -> V_50 . V_54 = 0 ;
V_45 -> V_55 . V_19 = V_56 ;
V_45 -> V_55 . V_57 = V_58 ;
V_45 -> V_59 = 0 ;
return V_45 ;
}
