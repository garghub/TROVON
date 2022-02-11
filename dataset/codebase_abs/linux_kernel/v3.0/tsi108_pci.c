int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
volatile unsigned char * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_10 . V_11 )
if ( V_10 . V_11 ( V_9 , V_2 -> V_12 , V_3 ) )
return V_13 ;
V_7 = ( unsigned char * ) ( F_3 ( V_2 -> V_12 ,
V_3 , V_4 ) |
( V_4 & 0x03 ) ) ;
#ifdef F_4
F_5 ( L_1 ) ;
F_5 ( L_2 , V_2 -> V_12 , V_3 , V_4 ) ;
F_5 ( L_3 , V_5 , ( V_14 ) V_7 ) ;
F_5 ( L_4 , V_6 ) ;
#endif
switch ( V_5 ) {
case 1 :
F_6 ( ( V_15 * ) V_7 , V_6 ) ;
break;
case 2 :
F_7 ( ( V_16 * ) V_7 , V_6 ) ;
break;
default:
F_8 ( ( T_1 * ) V_7 , V_6 ) ;
break;
}
return V_17 ;
}
void F_9 ( T_1 V_18 )
{
T_1 V_19 , V_20 , V_21 ;
V_19 = F_10 ( V_22 + V_23 ) ;
V_20 = F_10 ( V_22 + V_24 ) ;
if ( V_19 & V_25 ) {
F_11 ( V_22 + V_23 ,
V_25 ) ;
F_11 ( V_22 + V_26 ,
V_27 ) ;
if ( ( V_20 & 0xFF000000 ) == V_18 ) {
V_21 =
F_10 ( V_28 + V_29 ) ;
F_11 ( V_28 + V_29 ,
V_21 ) ;
}
}
return;
}
int
F_12 ( struct V_1 * V_2 , unsigned int V_30 , int V_4 ,
int V_5 , T_1 * V_6 )
{
volatile unsigned char * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_31 ;
if ( V_10 . V_11 )
if ( V_10 . V_11 ( V_9 , V_2 -> V_12 , V_30 ) )
return V_13 ;
V_7 = ( unsigned char * ) ( F_3 ( V_2 -> V_12 ,
V_30 ,
V_4 ) | ( V_4 &
0x03 ) ) ;
switch ( V_5 ) {
case 1 :
F_13 ( V_31 , V_7 , L_5 ) ;
break;
case 2 :
F_13 ( V_31 , V_7 , L_6 ) ;
break;
default:
F_13 ( V_31 , V_7 , L_7 ) ;
break;
}
* V_6 = V_31 ;
#ifdef F_4
if ( ( 0xFFFFFFFF != V_31 ) && ( 0xFFFF != V_31 ) && ( 0xFF != V_31 ) ) {
F_5 ( L_8 ) ;
F_5 ( L_2 , V_2 -> V_12 , V_30 , V_4 ) ;
F_5 ( L_3 , V_5 , ( V_14 ) V_7 ) ;
F_5 ( L_9 , * V_6 ) ;
}
#endif
return V_17 ;
}
void F_14 ( void )
{
F_9 ( V_32 ) ;
}
int T_2 F_15 ( struct V_33 * V_34 , T_1 V_35 , int V_36 )
{
int V_5 ;
struct V_8 * V_9 ;
struct V_37 V_38 ;
const int * V_39 ;
int V_40 = 0 ;
V_41 = ( T_1 ) F_16 ( V_35 , V_42 ) ;
V_32 = V_35 ;
F_17 ( L_10 , V_43 ,
V_41 ) ;
V_40 = ( F_18 ( V_34 , 0 , & V_38 ) == 0 ) ;
V_39 = F_19 ( V_34 , L_11 , & V_5 ) ;
if ( V_39 == NULL || V_5 < 2 * sizeof( int ) ) {
F_5 ( V_44 L_12
L_13 , V_34 -> V_45 ) ;
}
V_9 = F_20 ( V_34 ) ;
if ( ! V_9 ) {
F_5 ( L_14 ) ;
return - V_46 ;
}
V_9 -> V_47 = V_39 ? V_39 [ 0 ] : 0 ;
V_9 -> V_48 = V_39 ? V_39 [ 1 ] : 0xff ;
( V_9 ) -> V_49 = & V_50 ;
F_5 ( V_51 L_15
L_16 ,
V_38 . V_52 , V_9 -> V_47 , V_9 -> V_48 ) ;
F_21 ( V_9 , V_34 , V_36 ) ;
return 0 ;
}
static void F_22 ( T_3 V_53 )
{
T_3 V_54 ;
int V_55 = ( V_53 - V_56 ) ;
V_54 = F_10 ( V_28 + V_57 ) ;
F_23 () ;
V_54 |= ( 1 << V_55 ) ;
V_54 &= ~ ( 3 << ( 8 + ( V_55 * 2 ) ) ) ;
F_11 ( V_28 + V_57 , V_54 ) ;
F_23 () ;
V_54 = F_10 ( V_28 + V_57 ) ;
}
static void F_24 ( T_3 V_53 )
{
T_3 V_54 ;
int V_55 = ( V_53 - V_56 ) ;
V_54 = F_10 ( V_28 + V_57 ) ;
F_23 () ;
V_54 &= ~ ( 1 << V_55 ) ;
V_54 |= ( 3 << ( 8 + ( V_55 * 2 ) ) ) ;
F_11 ( V_28 + V_57 , V_54 ) ;
F_23 () ;
}
static void F_25 ( void )
{
F_11 ( V_28 + V_57 ,
0x0000ff00 ) ;
F_11 ( V_28 + V_58 ,
V_59 ) ;
F_23 () ;
}
static inline unsigned int F_26 ( void )
{
T_3 V_31 = 0 ;
int V_53 = - 1 ;
int V_60 ;
T_3 V_61 ;
static int V_62 = 0 ;
V_61 = F_10 ( V_28 + V_63 ) ;
F_23 () ;
if ( V_61 & V_64 ) {
V_31 =
F_10 ( V_28 +
V_65 ) & 0xf ;
F_23 () ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ , V_62 ++ ) {
if ( V_31 & ( 1 << V_62 % 4 ) ) {
V_53 = V_66 + V_62 % 4 ;
V_62 ++ ;
break;
}
}
V_31 = F_10 ( V_28 + V_58 ) ;
F_11 ( V_28 + V_58 ,
V_31 & ~ V_59 ) ;
F_23 () ;
( void ) F_10 ( V_28 + V_58 ) ;
F_23 () ;
}
#ifdef F_4
else {
F_5 ( L_17 ) ;
V_61 =
F_10 ( V_28 + V_63 ) ;
V_31 =
F_10 ( V_28 + V_65 ) ;
F_23 () ;
F_5 ( L_18 , V_61 , V_31 ) ;
V_31 =
F_10 ( V_28 + V_57 ) ;
F_23 () ;
F_5 ( L_19 , V_31 ) ;
V_31 =
F_10 ( V_28 + V_58 ) ;
F_23 () ;
F_5 ( L_20 , V_31 ) ;
}
#endif
return V_53 ;
}
static void F_27 ( struct V_67 * V_68 )
{
F_24 ( V_68 -> V_53 ) ;
F_11 ( V_28 + V_58 ,
F_10 ( V_28 +
V_58 ) |
V_59 ) ;
F_23 () ;
}
static void F_28 ( struct V_67 * V_68 )
{
F_22 ( V_68 -> V_53 ) ;
}
static void F_29 ( struct V_67 * V_68 )
{
F_22 ( V_68 -> V_53 ) ;
}
static int F_30 ( struct V_69 * V_70 , struct V_33 * V_71 ,
const T_1 * V_72 , unsigned int V_73 ,
T_4 * V_74 , unsigned int * V_75 )
{
* V_74 = V_72 [ 0 ] ;
* V_75 = V_76 ;
return 0 ;
}
static int F_31 ( struct V_69 * V_70 , unsigned int V_77 ,
T_4 V_78 )
{ unsigned int V_53 ;
F_17 ( L_21 , V_43 , V_77 , V_78 ) ;
if ( ( V_77 >= 1 ) && ( V_77 <= 4 ) ) {
V_53 = V_77 + V_56 - 1 ;
F_32 ( V_53 , V_79 ) ;
F_33 ( V_53 , & V_80 ) ;
}
return 0 ;
}
void T_2 F_34 ( struct V_33 * V_81 )
{
F_17 ( L_22 ) ;
V_82 = F_35 ( V_81 , V_83 ,
0 , & V_84 , 0 ) ;
if ( V_82 == NULL ) {
F_5 ( V_85 L_23 ) ;
return;
}
F_25 () ;
}
void F_36 ( unsigned int V_53 , struct V_86 * V_87 )
{
struct V_88 * V_89 = F_37 ( V_87 ) ;
unsigned int V_90 = F_26 () ;
if ( V_90 != V_91 )
F_38 ( V_90 ) ;
V_89 -> V_92 ( & V_87 -> V_67 ) ;
}
