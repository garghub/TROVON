static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_1 + V_3 ) ;
F_3 ( 0x8 , V_1 + V_5 ) ;
F_3 ( 0x207 , V_1 + V_6 ) ;
#ifdef F_4
F_3 ( 0x0 , V_1 + V_7 ) ;
#endif
}
static int F_5 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_8 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_3 ) ;
return ! ! ( V_2 & V_8 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_9 ;
F_7 ( L_1 , V_1 ) ;
for ( V_9 = 0 ; V_9 < 55 ; V_9 ++ ) {
int V_10 = V_9 * 4 ;
F_7 ( L_2 , V_9 ,
V_10 , F_2 ( V_1 + V_10 ) ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char * V_11 ,
unsigned int V_12 )
{
F_9 ( V_1 , V_11 , F_10 ( V_12 ) ,
F_11 ( V_12 ) ) ;
}
static void F_12 ( void T_1 * V_1 , unsigned char * V_11 ,
unsigned int V_12 )
{
F_13 ( V_1 , V_11 , F_10 ( V_12 ) ,
F_11 ( V_12 ) ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
void T_1 * V_1 = ( void T_1 * ) V_14 -> V_15 ;
unsigned int V_2 = 0 ;
F_15 ( V_16 L_3 ,
V_17 , F_16 ( V_14 ) , F_17 ( V_14 ) ) ;
if ( V_14 -> V_18 & V_19 )
V_2 = V_20 ;
else if ( ( F_16 ( V_14 ) > V_21 )
|| ( V_14 -> V_18 & V_22 ) ) {
V_2 = V_23 ;
F_3 ( 0xffffffff , V_1 + V_24 ) ;
F_3 ( 0xffffffff , V_1 + V_25 ) ;
} else if ( ! F_18 ( V_14 ) ) {
T_2 V_26 [ 2 ] ;
struct V_27 * V_28 ;
V_2 = V_29 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
F_19 (ha, dev) {
int V_30 =
F_20 ( ~ F_21 ( ~ 0 , V_28 -> V_11 , 6 ) ) >> 26 ;
V_26 [ V_30 >> 5 ] |= 1 << ( V_30 & 31 ) ;
}
F_3 ( V_26 [ 0 ] , V_1 + V_25 ) ;
F_3 ( V_26 [ 1 ] , V_1 + V_24 ) ;
}
if ( F_17 ( V_14 ) > V_31 )
V_2 |= V_20 ;
else {
int V_32 = 1 ;
struct V_27 * V_28 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_28 -> V_11 , V_32 ) ;
V_32 ++ ;
}
}
#ifdef F_23
V_2 |= V_33 ;
#endif
F_3 ( V_2 , V_1 + V_34 ) ;
F_15 ( V_16 L_4
L_5 , F_2 ( V_1 + V_34 ) ,
F_2 ( V_1 + V_24 ) , F_2 ( V_1 + V_25 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
unsigned int V_38 = 0 ;
F_15 ( V_39 L_6 ) ;
if ( V_36 & V_40 ) {
F_15 ( V_39 L_7 ) ;
V_38 |= V_41 ;
}
if ( V_36 & V_42 ) {
F_15 ( V_39 L_8 ) ;
V_38 |= V_43 ;
}
if ( V_35 ) {
F_15 ( V_39 L_9 , V_37 ) ;
V_38 |= ( V_37 << V_44 ) ;
}
F_3 ( V_38 , V_1 + V_45 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_46 )
{
unsigned int V_47 = 0 ;
if ( V_46 & V_48 ) {
F_15 ( V_39 L_10 ) ;
V_47 |= V_49 | V_50 ;
}
if ( V_46 & V_51 ) {
F_15 ( V_39 L_11 ) ;
V_47 |= V_52 ;
}
F_3 ( V_47 , V_1 + V_53 ) ;
}
static void F_26 ( void T_1 * V_1 )
{
T_2 V_54 = F_2 ( V_1 + V_55 ) ;
if ( ( V_54 & V_56 ) )
F_15 ( V_39 L_12 ,
F_2 ( V_1 + V_57 ) ) ;
if ( F_27 ( V_54 & V_58 ) )
F_15 ( V_39 L_13 ,
F_2 ( V_1 + V_59 ) ) ;
if ( F_27 ( V_54 & V_60 ) )
F_15 ( V_39 L_14 ,
F_2 ( V_1 + V_61 ) ) ;
if ( F_27 ( V_54 & V_62 ) ) {
F_15 ( V_39 L_15 ) ;
F_2 ( V_1 + V_53 ) ;
}
}
struct V_63 * F_28 ( void T_1 * V_1 )
{
struct V_63 * V_64 ;
T_2 V_65 = F_2 ( V_1 + V_66 ) ;
F_7 ( L_16 ,
( ( V_65 & 0x0000ff00 ) >> 8 ) , ( V_65 & 0x000000ff ) ) ;
V_64 = F_29 ( sizeof( const struct V_63 ) , V_67 ) ;
if ( ! V_64 )
return NULL ;
V_64 -> V_64 = & V_68 ;
V_64 -> V_69 = & V_70 ;
V_64 -> V_71 . V_72 = V_73 ;
V_64 -> V_71 . V_35 = V_74 ;
V_64 -> V_71 . V_75 = V_76 ;
V_64 -> V_77 . V_11 = V_78 ;
V_64 -> V_77 . V_79 = V_80 ;
return V_64 ;
}
