static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
if ( ! V_2 -> V_5 )
return V_4 ;
F_2 ( 7 , V_2 -> V_6 ) ;
if ( ( F_3 ( V_2 -> V_6 + 1 ) & 0x40 ) == 0 )
V_3 = V_7 ;
return V_3 ;
}
static unsigned F_4 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
unsigned V_10 = 0 ;
F_2 ( 7 , V_2 -> V_6 ) ;
V_8 = F_3 ( V_2 -> V_6 + 1 ) ;
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
V_2 -> V_11 = 0xffff ;
for ( V_9 = 0 ; V_9 < 25 ; V_9 ++ ) {
V_10 = ( V_10 << 1 ) | ( ( F_3 ( V_2 -> V_6 + 1 ) >> 7 ) & 0x01 ) ;
if ( V_9 < 24 ) {
F_2 ( 0x01 , V_2 -> V_6 + 1 ) ;
V_2 -> V_11 &= F_3 ( V_2 -> V_6 + 1 ) ;
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
}
}
F_2 ( V_8 , V_2 -> V_6 + 1 ) ;
return V_10 ;
}
static unsigned F_5 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned V_12 = 0 , V_13 , V_10 = 0 ;
V_10 = F_4 ( V_2 ) ;
if ( ! V_2 -> V_5 )
return ( ( V_10 & 0x7fff ) - 450 ) * 16 ;
V_13 = 12500 ;
for ( V_9 = 0 ; V_9 < 14 ; V_9 ++ ) {
if ( ( V_10 & 0x01 ) != 0 )
V_12 += V_13 ;
V_13 = V_13 << 1 ;
V_10 = V_10 >> 1 ;
}
V_12 -= 10700000 ;
V_12 = ( V_12 * 16 ) / 1000 ;
return V_12 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_10 )
{
int V_9 ;
unsigned V_13 ;
F_2 ( 7 , V_2 -> V_6 ) ;
V_13 = 0 ;
V_13 = ( V_10 >> 23 ) & 0x02 ;
V_13 |= 0x1c ;
F_2 ( 7 , V_2 -> V_6 ) ;
F_2 ( V_13 , V_2 -> V_6 + 1 ) ;
for ( V_9 = 0 ; V_9 < 25 ; V_9 ++ ) {
V_13 |= 0x01 ;
F_2 ( V_13 , V_2 -> V_6 + 1 ) ;
V_13 &= 0xfe ;
F_2 ( V_13 , V_2 -> V_6 + 1 ) ;
V_10 = V_10 << 1 ;
V_13 = 0x1c | ( ( V_10 >> 23 ) & 0x02 ) ;
F_2 ( V_13 , V_2 -> V_6 + 1 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , unsigned V_12 )
{
unsigned V_10 ;
int V_9 , V_14 , V_13 ;
int V_8 ;
V_12 = F_8 ( V_12 , V_15 [ V_2 -> V_5 ] . V_16 ,
V_15 [ V_2 -> V_5 ] . V_17 ) ;
V_2 -> V_18 = V_12 ;
V_10 = 0 ;
if ( V_2 -> V_5 ) {
V_13 = 102400 ;
V_12 = V_12 / 16 ;
V_12 += 10700 ;
for ( V_9 = 0 ; V_9 < 14 ; V_9 ++ ) {
V_10 = V_10 << 1 ;
if ( V_12 >= V_13 ) {
V_10 |= 0x01 ;
V_12 -= V_13 ;
}
V_13 = V_13 >> 1 ;
}
} else {
V_10 = ( V_12 / 16 ) + 450 ;
V_10 |= 0x100000 ;
}
F_2 ( 7 , V_2 -> V_6 ) ;
V_8 = F_3 ( V_2 -> V_6 + 1 ) ;
for ( V_14 = 3 ; V_14 > - 1 ; V_14 -- ) {
F_6 ( V_2 , V_10 | ( V_14 << 16 ) ) ;
F_2 ( 7 , V_2 -> V_6 ) ;
F_2 ( V_8 , V_2 -> V_6 + 1 ) ;
F_9 ( 100 ) ;
F_4 ( V_2 ) ;
if ( ( V_2 -> V_11 & 0x40 ) == 0 ) {
V_2 -> V_19 = V_20 [ V_2 -> V_5 ] [ V_14 ] ;
goto V_21;
}
}
V_2 -> V_19 = 0 ;
V_21:
F_2 ( 3 , V_2 -> V_6 ) ;
F_2 ( F_3 ( V_2 -> V_6 + 1 ) & 0x7f , V_2 -> V_6 + 1 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
bool V_22 ;
F_11 ( & V_2 -> V_23 ) ;
V_22 = V_2 -> V_24 != V_2 -> V_25 ;
F_12 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static void F_13 ( unsigned long V_26 )
{
struct V_1 * V_2 = ( void * ) V_26 ;
if ( F_14 ( & V_2 -> V_23 ) ) {
F_2 ( 0x3 , V_2 -> V_6 ) ;
if ( ( F_3 ( V_2 -> V_6 + 1 ) & 0x20 ) != 0 )
F_15 ( L_1 ) ;
F_2 ( 0x80 , V_2 -> V_6 ) ;
while ( ( F_3 ( V_2 -> V_6 ) & 0x80 ) != 0 ) {
V_2 -> V_27 [ V_2 -> V_24 ] = F_3 ( V_2 -> V_6 + 1 ) ;
if ( V_2 -> V_24 + 1 != V_2 -> V_25 )
V_2 -> V_24 ++ ;
}
F_12 ( & V_2 -> V_23 ) ;
}
if ( F_10 ( V_2 ) )
F_16 ( & V_2 -> V_28 ) ;
F_17 ( & V_2 -> V_29 , F_13 , V_26 ) ;
V_2 -> V_29 . V_30 = V_31 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_29 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_32 = 1 ;
F_2 ( 0x80 , V_2 -> V_6 ) ;
F_17 ( & V_2 -> V_29 , F_13 , ( unsigned long ) V_2 ) ;
V_2 -> V_29 . V_30 = V_31 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_29 ) ;
}
static T_1 F_21 ( struct V_33 * V_33 , char T_2 * V_26 , T_3 V_34 , T_4 * V_35 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
unsigned char V_36 [ V_37 ] ;
int V_9 = 0 ;
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_32 == 0 )
F_20 ( V_2 ) ;
F_12 ( & V_2 -> V_23 ) ;
if ( ! F_10 ( V_2 ) && ( V_33 -> V_38 & V_39 ) )
return - V_40 ;
V_9 = F_23 ( V_2 -> V_28 , F_10 ( V_2 ) ) ;
if ( V_9 )
return V_9 ;
F_11 ( & V_2 -> V_23 ) ;
while ( V_9 < V_34 && V_2 -> V_24 != V_2 -> V_25 )
V_36 [ V_9 ++ ] = V_2 -> V_27 [ V_2 -> V_25 ++ ] ;
F_12 ( & V_2 -> V_23 ) ;
if ( V_9 && F_24 ( V_26 , V_36 , V_9 ) )
return - V_41 ;
return V_9 ;
}
static int F_25 ( struct V_33 * V_33 , void * V_42 ,
struct V_43 * V_44 )
{
F_26 ( V_44 -> V_45 , L_2 , sizeof( V_44 -> V_45 ) ) ;
F_26 ( V_44 -> V_46 , L_2 , sizeof( V_44 -> V_46 ) ) ;
F_26 ( V_44 -> V_47 , L_3 , sizeof( V_44 -> V_47 ) ) ;
V_44 -> V_48 = V_49 | V_50 |
V_51 | V_52 ;
V_44 -> V_53 = V_44 -> V_48 | V_54 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_33 , void * V_42 ,
struct V_55 * V_44 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
if ( V_44 -> V_56 )
return - V_57 ;
V_44 -> type = V_58 ;
F_26 ( V_44 -> V_59 , L_4 , sizeof( V_44 -> V_59 ) ) ;
V_44 -> V_60 = V_15 [ 0 ] . V_60 | V_15 [ 1 ] . V_60 ;
V_44 -> V_16 = V_15 [ 0 ] . V_16 ;
V_44 -> V_17 = V_15 [ 1 ] . V_17 ;
if ( V_2 -> V_5 ) {
V_44 -> V_61 = F_1 ( V_2 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
F_2 ( F_3 ( V_2 -> V_6 + 1 ) & 0x7f , V_2 -> V_6 + 1 ) ;
F_28 ( 100 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_6 + 1 ) & 0x80 )
V_44 -> V_61 |= V_62 ;
} else {
V_44 -> V_16 = 8320 ;
V_44 -> V_17 = 26400 ;
V_44 -> V_61 = V_4 ;
}
V_44 -> V_63 = V_64 ;
V_44 -> signal = V_2 -> V_19 ;
return 0 ;
}
static int F_29 ( struct V_33 * V_33 , void * V_42 ,
const struct V_55 * V_44 )
{
return V_44 -> V_56 ? - V_57 : 0 ;
}
static int F_30 ( struct V_33 * V_33 , void * V_42 ,
struct V_65 * V_66 )
{
if ( V_66 -> V_67 )
return - V_57 ;
if ( V_66 -> V_56 >= F_31 ( V_15 ) )
return - V_57 ;
* V_66 = V_15 [ V_66 -> V_56 ] ;
return 0 ;
}
static int F_32 ( struct V_33 * V_33 , void * V_42 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
if ( V_69 -> V_67 )
return - V_57 ;
V_69 -> type = V_58 ;
V_69 -> V_70 = V_2 -> V_18 ;
return 0 ;
}
static int F_33 ( struct V_33 * V_33 , void * V_42 ,
const struct V_68 * V_69 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
if ( V_69 -> V_67 )
return - V_57 ;
V_2 -> V_5 =
V_69 -> V_70 >= ( V_15 [ 0 ] . V_17 + V_15 [ 1 ] . V_16 ) / 2 ;
F_7 ( V_2 , V_69 -> V_70 ) ;
return 0 ;
}
static int F_34 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_35 ( V_72 -> V_73 , struct V_1 , V_74 ) ;
switch ( V_72 -> V_75 ) {
case V_76 :
F_2 ( 7 , V_2 -> V_6 ) ;
if ( V_72 -> V_77 )
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
else
F_2 ( 0x20 , V_2 -> V_6 + 1 ) ;
return 0 ;
}
return - V_57 ;
}
static int F_36 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
int V_78 ;
F_11 ( & V_2 -> V_23 ) ;
V_78 = F_37 ( V_33 ) ;
if ( V_78 )
goto V_79;
if ( F_38 ( V_33 ) )
F_39 ( & V_2 -> V_28 ) ;
V_79:
F_12 ( & V_2 -> V_23 ) ;
return V_78 ;
}
static int F_40 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
F_11 ( & V_2 -> V_23 ) ;
if ( F_38 ( V_33 ) && V_2 -> V_32 ) {
F_41 ( & V_2 -> V_29 ) ;
V_2 -> V_32 = 0 ;
}
F_42 ( V_33 ) ;
F_12 ( & V_2 -> V_23 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_33 * V_33 , struct V_80 * V_81 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
unsigned long V_82 = F_44 ( V_81 ) ;
unsigned int V_83 = F_45 ( V_33 , V_81 ) ;
F_46 ( V_33 , & V_2 -> V_28 , V_81 ) ;
if ( V_2 -> V_32 == 0 && ( V_82 & ( V_84 | V_85 ) ) ) {
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_32 == 0 )
F_20 ( V_2 ) ;
F_12 ( & V_2 -> V_23 ) ;
}
if ( F_10 ( V_2 ) )
V_83 |= V_84 | V_85 ;
return V_83 ;
}
static int F_47 ( struct V_86 * V_2 , const struct V_87 * V_88 )
{
if ( ! V_2 )
return - V_89 ;
if ( V_6 > 0 )
return - V_90 ;
if ( ! F_48 ( V_2 , 0 ) )
return - V_89 ;
V_6 = F_49 ( V_2 , 0 ) ;
F_50 ( V_91 L_5 , V_6 ) ;
return V_6 ;
}
static void F_51 ( struct V_1 * V_2 )
{
static int V_92 [ 8 ] = { 0x330 , 0x332 , 0x334 , 0x336 , 0x338 , 0x33a , 0x33c , 0x33e } ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_2 -> V_6 = V_92 [ V_9 ] ;
if ( F_52 ( V_2 -> V_6 , 2 , L_6 ) ) {
F_7 ( V_2 , V_15 [ 1 ] . V_16 ) ;
if ( F_5 ( V_2 ) == V_15 [ 1 ] . V_16 ) {
F_53 ( V_2 -> V_6 , 2 ) ;
return;
}
F_53 ( V_2 -> V_6 , 2 ) ;
}
}
V_2 -> V_6 = - 1 ;
}
static int T_5 F_54 ( void )
{
struct V_1 * V_2 = & V_93 ;
struct V_94 * V_95 = & V_2 -> V_95 ;
struct V_96 * V_97 ;
int V_83 = - V_89 ;
F_26 ( V_95 -> V_59 , L_7 , sizeof( V_95 -> V_59 ) ) ;
F_55 ( & V_2 -> V_23 ) ;
if ( V_6 < 0 )
F_56 ( & V_98 ) ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 < 0 )
F_51 ( V_2 ) ;
if ( V_2 -> V_6 < 0 ) {
#ifdef F_57
F_58 ( V_95 , L_8 ) ;
F_58 ( V_95 , L_9 ) ;
#endif
goto V_79;
}
if ( ! F_52 ( V_2 -> V_6 , 2 , L_7 ) )
goto V_79;
V_83 = F_59 ( NULL , V_95 ) ;
if ( V_83 < 0 ) {
F_53 ( V_2 -> V_6 , 2 ) ;
F_58 ( V_95 , L_10 ) ;
goto V_79;
}
V_97 = & V_2 -> V_74 ;
F_60 ( V_97 , 2 ) ;
F_61 ( V_97 , & V_99 ,
V_76 , 0 , 1 , 1 , 1 ) ;
V_95 -> V_74 = V_97 ;
if ( V_97 -> error ) {
V_83 = V_97 -> error ;
F_58 ( V_95 , L_11 ) ;
goto V_100;
}
V_2 -> V_5 = true ;
V_2 -> V_18 = V_15 [ V_2 -> V_5 ] . V_16 ;
F_7 ( V_2 , V_2 -> V_18 ) ;
F_26 ( V_2 -> V_101 . V_59 , V_95 -> V_59 , sizeof( V_2 -> V_101 . V_59 ) ) ;
V_2 -> V_101 . V_95 = V_95 ;
V_2 -> V_101 . V_102 = & V_103 ;
V_2 -> V_101 . V_104 = & V_105 ;
V_2 -> V_101 . V_106 = V_107 ;
V_2 -> V_101 . V_23 = & V_2 -> V_23 ;
F_62 ( & V_2 -> V_101 , V_2 ) ;
V_83 = F_63 ( & V_2 -> V_101 , V_108 , V_109 ) ;
if ( V_83 < 0 )
goto V_100;
F_64 ( V_95 , L_12 , V_2 -> V_6 ) ;
return 0 ;
V_100:
F_65 ( V_97 ) ;
F_66 ( V_95 ) ;
F_53 ( V_2 -> V_6 , 2 ) ;
V_79:
F_67 ( & V_98 ) ;
return V_83 ;
}
static void T_6 F_68 ( void )
{
struct V_1 * V_2 = & V_93 ;
F_69 ( & V_2 -> V_101 ) ;
F_65 ( & V_2 -> V_74 ) ;
F_66 ( & V_2 -> V_95 ) ;
F_2 ( 7 , V_2 -> V_6 ) ;
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
F_53 ( V_2 -> V_6 , 2 ) ;
F_67 ( & V_98 ) ;
}
