static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_1 + V_3 ) ;
F_3 ( 0x207 , V_1 + V_5 ) ;
#ifdef F_4
F_3 ( 0x0 , V_1 + V_6 ) ;
#endif
}
static int F_5 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_7 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_3 ) ;
return ! ! ( V_2 & V_7 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_8 ;
F_7 ( L_1 , V_1 ) ;
for ( V_8 = 0 ; V_8 < 55 ; V_8 ++ ) {
int V_9 = V_8 * 4 ;
F_7 ( L_2 , V_8 ,
V_9 , F_2 ( V_1 + V_9 ) ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char * V_10 ,
unsigned int V_11 )
{
F_9 ( V_1 , V_10 , F_10 ( V_11 ) ,
F_11 ( V_11 ) ) ;
}
static void F_12 ( void T_1 * V_1 , unsigned char * V_10 ,
unsigned int V_11 )
{
F_13 ( V_1 , V_10 , F_10 ( V_11 ) ,
F_11 ( V_11 ) ) ;
}
static void F_14 ( struct V_12 * V_13 , int V_14 )
{
void T_1 * V_1 = ( void T_1 * ) V_13 -> V_15 ;
unsigned int V_2 = 0 ;
unsigned int V_16 ;
F_15 ( V_17 L_3 ,
V_18 , F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
if ( V_13 -> V_19 & V_20 )
V_2 = V_21 ;
else if ( ( F_16 ( V_13 ) > V_22 )
|| ( V_13 -> V_19 & V_23 ) ) {
V_2 = V_24 ;
F_3 ( 0xffffffff , V_1 + V_25 ) ;
F_3 ( 0xffffffff , V_1 + V_26 ) ;
} else if ( ! F_18 ( V_13 ) ) {
T_2 V_27 [ 2 ] ;
struct V_28 * V_29 ;
V_2 = V_30 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
F_19 (ha, dev) {
int V_31 =
F_20 ( ~ F_21 ( ~ 0 , V_29 -> V_10 , 6 ) ) >> 26 ;
V_27 [ V_31 >> 5 ] |= 1 << ( V_31 & 31 ) ;
}
F_3 ( V_27 [ 0 ] , V_1 + V_26 ) ;
F_3 ( V_27 [ 1 ] , V_1 + V_25 ) ;
}
if ( V_14 > V_32 )
V_16 = V_33 ;
else
V_16 = V_33 / 2 ;
if ( F_17 ( V_13 ) > V_16 )
V_2 |= V_21 ;
else {
int V_34 = 1 ;
struct V_28 * V_29 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_29 -> V_10 , V_34 ) ;
V_34 ++ ;
}
}
#ifdef F_23
V_2 |= V_35 ;
#endif
F_3 ( V_2 , V_1 + V_36 ) ;
F_15 ( V_17 L_4
L_5 , F_2 ( V_1 + V_36 ) ,
F_2 ( V_1 + V_25 ) , F_2 ( V_1 + V_26 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_37 ,
unsigned int V_38 , unsigned int V_39 )
{
unsigned int V_40 = 0 ;
F_15 ( V_41 L_6 ) ;
if ( V_38 & V_42 ) {
F_15 ( V_41 L_7 ) ;
V_40 |= V_43 ;
}
if ( V_38 & V_44 ) {
F_15 ( V_41 L_8 ) ;
V_40 |= V_45 ;
}
if ( V_37 ) {
F_15 ( V_41 L_9 , V_39 ) ;
V_40 |= ( V_39 << V_46 ) ;
}
F_3 ( V_40 , V_1 + V_47 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_48 )
{
unsigned int V_49 = 0 ;
if ( V_48 & V_50 ) {
F_15 ( V_41 L_10 ) ;
V_49 |= V_51 | V_52 ;
}
if ( V_48 & V_53 ) {
F_15 ( V_41 L_11 ) ;
V_49 |= V_54 ;
}
F_3 ( V_49 , V_1 + V_55 ) ;
}
static void F_26 ( void T_1 * V_1 )
{
T_2 V_56 = F_2 ( V_1 + V_57 ) ;
if ( ( V_56 & V_58 ) )
F_15 ( V_41 L_12 ,
F_2 ( V_1 + V_59 ) ) ;
if ( F_27 ( V_56 & V_60 ) )
F_15 ( V_41 L_13 ,
F_2 ( V_1 + V_61 ) ) ;
if ( F_27 ( V_56 & V_62 ) )
F_15 ( V_41 L_14 ,
F_2 ( V_1 + V_63 ) ) ;
if ( F_27 ( V_56 & V_64 ) ) {
F_15 ( V_41 L_15 ) ;
F_2 ( V_1 + V_55 ) ;
}
}
struct V_65 * F_28 ( void T_1 * V_1 )
{
struct V_65 * V_66 ;
T_2 V_67 = F_2 ( V_1 + V_68 ) ;
V_66 = F_29 ( sizeof( const struct V_65 ) , V_69 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_66 = & V_70 ;
V_66 -> V_71 = & V_72 ;
V_66 -> V_73 . V_74 = V_75 ;
V_66 -> V_73 . V_37 = V_76 ;
V_66 -> V_73 . V_77 = V_78 ;
V_66 -> V_79 . V_10 = V_80 ;
V_66 -> V_79 . V_81 = V_82 ;
V_66 -> V_83 = V_67 ;
return V_66 ;
}
