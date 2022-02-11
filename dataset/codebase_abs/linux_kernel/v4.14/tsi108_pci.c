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
L_13 , V_34 ) ;
}
V_9 = F_20 ( V_34 ) ;
if ( ! V_9 ) {
F_5 ( L_14 ) ;
return - V_45 ;
}
V_9 -> V_46 = V_39 ? V_39 [ 0 ] : 0 ;
V_9 -> V_47 = V_39 ? V_39 [ 1 ] : 0xff ;
( V_9 ) -> V_48 = & V_49 ;
F_5 ( V_50 L_15
L_16 ,
V_38 . V_51 , V_9 -> V_46 , V_9 -> V_47 ) ;
F_21 ( V_9 , V_34 , V_36 ) ;
return 0 ;
}
static void F_22 ( T_3 V_52 )
{
T_3 V_53 ;
int V_54 = ( V_52 - V_55 ) ;
V_53 = F_10 ( V_28 + V_56 ) ;
F_23 () ;
V_53 |= ( 1 << V_54 ) ;
V_53 &= ~ ( 3 << ( 8 + ( V_54 * 2 ) ) ) ;
F_11 ( V_28 + V_56 , V_53 ) ;
F_23 () ;
V_53 = F_10 ( V_28 + V_56 ) ;
}
static void F_24 ( T_3 V_52 )
{
T_3 V_53 ;
int V_54 = ( V_52 - V_55 ) ;
V_53 = F_10 ( V_28 + V_56 ) ;
F_23 () ;
V_53 &= ~ ( 1 << V_54 ) ;
V_53 |= ( 3 << ( 8 + ( V_54 * 2 ) ) ) ;
F_11 ( V_28 + V_56 , V_53 ) ;
F_23 () ;
}
static void F_25 ( void )
{
F_11 ( V_28 + V_56 ,
0x0000ff00 ) ;
F_11 ( V_28 + V_57 ,
V_58 ) ;
F_23 () ;
}
static inline unsigned int F_26 ( void )
{
T_3 V_31 = 0 ;
int V_52 = - 1 ;
int V_59 ;
T_3 V_60 ;
static int V_61 = 0 ;
V_60 = F_10 ( V_28 + V_62 ) ;
F_23 () ;
if ( V_60 & V_63 ) {
V_31 =
F_10 ( V_28 +
V_64 ) & 0xf ;
F_23 () ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ , V_61 ++ ) {
if ( V_31 & ( 1 << V_61 % 4 ) ) {
V_52 = V_65 + V_61 % 4 ;
V_61 ++ ;
break;
}
}
V_31 = F_10 ( V_28 + V_57 ) ;
F_11 ( V_28 + V_57 ,
V_31 & ~ V_58 ) ;
F_23 () ;
( void ) F_10 ( V_28 + V_57 ) ;
F_23 () ;
}
#ifdef F_4
else {
F_5 ( L_17 ) ;
V_60 =
F_10 ( V_28 + V_62 ) ;
V_31 =
F_10 ( V_28 + V_64 ) ;
F_23 () ;
F_5 ( L_18 , V_60 , V_31 ) ;
V_31 =
F_10 ( V_28 + V_56 ) ;
F_23 () ;
F_5 ( L_19 , V_31 ) ;
V_31 =
F_10 ( V_28 + V_57 ) ;
F_23 () ;
F_5 ( L_20 , V_31 ) ;
}
#endif
return V_52 ;
}
static void F_27 ( struct V_66 * V_67 )
{
F_24 ( V_67 -> V_52 ) ;
F_11 ( V_28 + V_57 ,
F_10 ( V_28 +
V_57 ) |
V_58 ) ;
F_23 () ;
}
static void F_28 ( struct V_66 * V_67 )
{
F_22 ( V_67 -> V_52 ) ;
}
static void F_29 ( struct V_66 * V_67 )
{
F_22 ( V_67 -> V_52 ) ;
}
static int F_30 ( struct V_68 * V_69 , struct V_33 * V_70 ,
const T_1 * V_71 , unsigned int V_72 ,
T_4 * V_73 , unsigned int * V_74 )
{
* V_73 = V_71 [ 0 ] ;
* V_74 = V_75 ;
return 0 ;
}
static int F_31 ( struct V_68 * V_69 , unsigned int V_76 ,
T_4 V_77 )
{ unsigned int V_52 ;
F_17 ( L_21 , V_43 , V_76 , V_77 ) ;
if ( ( V_76 >= 1 ) && ( V_76 <= 4 ) ) {
V_52 = V_76 + V_55 - 1 ;
F_32 ( V_52 , V_78 ) ;
F_33 ( V_52 , & V_79 ) ;
}
return 0 ;
}
void T_2 F_34 ( struct V_33 * V_80 )
{
F_17 ( L_22 ) ;
V_81 = F_35 ( V_80 , & V_82 , NULL ) ;
if ( V_81 == NULL ) {
F_5 ( V_83 L_23 ) ;
return;
}
F_25 () ;
}
void F_36 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_37 ( V_85 ) ;
unsigned int V_88 = F_26 () ;
if ( V_88 )
F_38 ( V_88 ) ;
V_87 -> V_89 ( & V_85 -> V_66 ) ;
}
