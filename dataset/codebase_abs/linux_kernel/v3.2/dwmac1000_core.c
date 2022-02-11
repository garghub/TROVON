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
static void F_14 ( struct V_12 * V_13 )
{
void T_1 * V_1 = ( void T_1 * ) V_13 -> V_14 ;
unsigned int V_2 = 0 ;
F_15 ( V_15 L_3 ,
V_16 , F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
if ( V_13 -> V_17 & V_18 )
V_2 = V_19 ;
else if ( ( F_16 ( V_13 ) > V_20 )
|| ( V_13 -> V_17 & V_21 ) ) {
V_2 = V_22 ;
F_3 ( 0xffffffff , V_1 + V_23 ) ;
F_3 ( 0xffffffff , V_1 + V_24 ) ;
} else if ( ! F_18 ( V_13 ) ) {
T_2 V_25 [ 2 ] ;
struct V_26 * V_27 ;
V_2 = V_28 ;
memset ( V_25 , 0 , sizeof( V_25 ) ) ;
F_19 (ha, dev) {
int V_29 =
F_20 ( ~ F_21 ( ~ 0 , V_27 -> V_10 , 6 ) ) >> 26 ;
V_25 [ V_29 >> 5 ] |= 1 << ( V_29 & 31 ) ;
}
F_3 ( V_25 [ 0 ] , V_1 + V_24 ) ;
F_3 ( V_25 [ 1 ] , V_1 + V_23 ) ;
}
if ( F_17 ( V_13 ) > V_30 )
V_2 |= V_19 ;
else {
int V_31 = 1 ;
struct V_26 * V_27 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_27 -> V_10 , V_31 ) ;
V_31 ++ ;
}
}
#ifdef F_23
V_2 |= V_32 ;
#endif
F_3 ( V_2 , V_1 + V_33 ) ;
F_15 ( V_15 L_4
L_5 , F_2 ( V_1 + V_33 ) ,
F_2 ( V_1 + V_23 ) , F_2 ( V_1 + V_24 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_34 ,
unsigned int V_35 , unsigned int V_36 )
{
unsigned int V_37 = 0 ;
F_15 ( V_38 L_6 ) ;
if ( V_35 & V_39 ) {
F_15 ( V_38 L_7 ) ;
V_37 |= V_40 ;
}
if ( V_35 & V_41 ) {
F_15 ( V_38 L_8 ) ;
V_37 |= V_42 ;
}
if ( V_34 ) {
F_15 ( V_38 L_9 , V_36 ) ;
V_37 |= ( V_36 << V_43 ) ;
}
F_3 ( V_37 , V_1 + V_44 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_45 )
{
unsigned int V_46 = 0 ;
if ( V_45 & V_47 ) {
F_15 ( V_38 L_10 ) ;
V_46 |= V_48 | V_49 ;
}
if ( V_45 & V_50 ) {
F_15 ( V_38 L_11 ) ;
V_46 |= V_51 ;
}
F_3 ( V_46 , V_1 + V_52 ) ;
}
static void F_26 ( void T_1 * V_1 )
{
T_2 V_53 = F_2 ( V_1 + V_54 ) ;
if ( ( V_53 & V_55 ) )
F_15 ( V_38 L_12 ,
F_2 ( V_1 + V_56 ) ) ;
if ( F_27 ( V_53 & V_57 ) )
F_15 ( V_38 L_13 ,
F_2 ( V_1 + V_58 ) ) ;
if ( F_27 ( V_53 & V_59 ) )
F_15 ( V_38 L_14 ,
F_2 ( V_1 + V_60 ) ) ;
if ( F_27 ( V_53 & V_61 ) ) {
F_15 ( V_38 L_15 ) ;
F_2 ( V_1 + V_52 ) ;
}
}
struct V_62 * F_28 ( void T_1 * V_1 )
{
struct V_62 * V_63 ;
T_2 V_64 = F_2 ( V_1 + V_65 ) ;
V_63 = F_29 ( sizeof( const struct V_62 ) , V_66 ) ;
if ( ! V_63 )
return NULL ;
V_63 -> V_63 = & V_67 ;
V_63 -> V_68 = & V_69 ;
V_63 -> V_70 . V_71 = V_72 ;
V_63 -> V_70 . V_34 = V_73 ;
V_63 -> V_70 . V_74 = V_75 ;
V_63 -> V_76 . V_10 = V_77 ;
V_63 -> V_76 . V_78 = V_79 ;
V_63 -> V_80 = V_64 ;
return V_63 ;
}
