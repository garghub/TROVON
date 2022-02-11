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
V_2 -> V_15 = V_12 ;
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
F_8 ( 100 ) ;
F_4 ( V_2 ) ;
if ( ( V_2 -> V_11 & 0x40 ) == 0 ) {
V_2 -> V_16 = V_17 [ V_2 -> V_5 ] [ V_14 ] ;
goto V_18;
}
}
V_2 -> V_16 = 0 ;
V_18:
F_2 ( 3 , V_2 -> V_6 ) ;
F_2 ( F_3 ( V_2 -> V_6 + 1 ) & 0x7f , V_2 -> V_6 + 1 ) ;
}
static void F_9 ( unsigned long V_19 )
{
struct V_1 * V_2 = ( void * ) V_19 ;
if ( F_10 ( & V_2 -> V_20 ) ) {
F_2 ( 0x3 , V_2 -> V_6 ) ;
if ( ( F_3 ( V_2 -> V_6 + 1 ) & 0x20 ) != 0 )
F_11 ( V_21 L_1 ) ;
F_2 ( 0x80 , V_2 -> V_6 ) ;
while ( ( F_3 ( V_2 -> V_6 ) & 0x80 ) != 0 ) {
V_2 -> V_22 [ V_2 -> V_23 ] = F_3 ( V_2 -> V_6 + 1 ) ;
if ( V_2 -> V_23 + 1 == V_2 -> V_24 )
F_11 ( V_25 L_2 ) ;
else
V_2 -> V_23 ++ ;
}
F_12 ( & V_2 -> V_20 ) ;
}
if ( V_2 -> V_23 != V_2 -> V_24 )
F_13 ( & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_28 = F_9 ;
V_2 -> V_27 . V_19 = V_19 ;
V_2 -> V_27 . V_29 = V_30 + F_15 ( 50 ) ;
F_16 ( & V_2 -> V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 1 ;
F_2 ( 0x80 , V_2 -> V_6 ) ;
F_14 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_28 = F_9 ;
V_2 -> V_27 . V_19 = ( unsigned long ) V_2 ;
V_2 -> V_27 . V_29 = V_30 + F_15 ( 50 ) ;
F_16 ( & V_2 -> V_27 ) ;
}
static T_1 F_18 ( struct V_32 * V_32 , char T_2 * V_19 , T_3 V_33 , T_4 * V_34 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
unsigned char V_35 [ V_36 ] ;
int V_9 = 0 ;
F_20 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_31 == 0 )
F_17 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_24 ) {
if ( V_32 -> V_37 & V_38 ) {
V_9 = - V_39 ;
goto V_40;
}
F_12 ( & V_2 -> V_20 ) ;
F_21 ( & V_2 -> V_26 ) ;
F_20 ( & V_2 -> V_20 ) ;
}
while ( V_9 < V_33 && V_2 -> V_23 != V_2 -> V_24 )
V_35 [ V_9 ++ ] = V_2 -> V_22 [ V_2 -> V_24 ++ ] ;
if ( V_9 && F_22 ( V_19 , V_35 , V_9 ) )
V_9 = - V_41 ;
V_40:
F_12 ( & V_2 -> V_20 ) ;
return V_9 ;
}
static int F_23 ( struct V_32 * V_32 , void * V_42 ,
struct V_43 * V_44 )
{
F_24 ( V_44 -> V_45 , L_3 , sizeof( V_44 -> V_45 ) ) ;
F_24 ( V_44 -> V_46 , L_3 , sizeof( V_44 -> V_46 ) ) ;
F_24 ( V_44 -> V_47 , L_4 , sizeof( V_44 -> V_47 ) ) ;
V_44 -> V_48 = V_49 | V_50 |
V_51 | V_52 ;
V_44 -> V_53 = V_44 -> V_48 | V_54 ;
return 0 ;
}
static int F_25 ( struct V_32 * V_32 , void * V_42 ,
struct V_55 * V_44 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
if ( V_44 -> V_56 )
return - V_57 ;
V_44 -> type = V_58 ;
F_24 ( V_44 -> V_59 , L_5 , sizeof( V_44 -> V_59 ) ) ;
V_44 -> V_60 = V_61 [ 0 ] . V_60 | V_61 [ 1 ] . V_60 ;
V_44 -> V_62 = V_61 [ 0 ] . V_62 ;
V_44 -> V_63 = V_61 [ 1 ] . V_63 ;
if ( V_2 -> V_5 ) {
V_44 -> V_64 = F_1 ( V_2 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
F_2 ( F_3 ( V_2 -> V_6 + 1 ) & 0x7f , V_2 -> V_6 + 1 ) ;
F_26 ( 100 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_6 + 1 ) & 0x80 )
V_44 -> V_64 |= V_65 ;
} else {
V_44 -> V_62 = 8320 ;
V_44 -> V_63 = 26400 ;
V_44 -> V_64 = V_4 ;
}
V_44 -> V_66 = V_67 ;
V_44 -> signal = V_2 -> V_16 ;
return 0 ;
}
static int F_27 ( struct V_32 * V_32 , void * V_42 ,
struct V_55 * V_44 )
{
return V_44 -> V_56 ? - V_57 : 0 ;
}
static int F_28 ( struct V_32 * V_32 , void * V_42 ,
struct V_68 * V_69 )
{
if ( V_69 -> V_70 )
return - V_57 ;
if ( V_69 -> V_56 >= F_29 ( V_61 ) )
return - V_57 ;
* V_69 = V_61 [ V_69 -> V_56 ] ;
return 0 ;
}
static int F_30 ( struct V_32 * V_32 , void * V_42 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
if ( V_72 -> V_70 )
return - V_57 ;
V_72 -> type = V_58 ;
V_72 -> V_73 = V_2 -> V_15 ;
return 0 ;
}
static int F_31 ( struct V_32 * V_32 , void * V_42 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
if ( V_72 -> V_70 )
return - V_57 ;
V_2 -> V_5 =
V_72 -> V_73 >= ( V_61 [ 0 ] . V_63 + V_61 [ 1 ] . V_62 ) / 2 ;
F_32 ( V_72 -> V_73 , V_61 [ V_2 -> V_5 ] . V_62 ,
V_61 [ V_2 -> V_5 ] . V_63 ) ;
F_7 ( V_2 , V_72 -> V_73 ) ;
return 0 ;
}
static int F_33 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_34 ( V_75 -> V_76 , struct V_1 , V_77 ) ;
switch ( V_75 -> V_78 ) {
case V_79 :
F_2 ( 7 , V_2 -> V_6 ) ;
if ( V_75 -> V_80 )
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
else
F_2 ( 0x20 , V_2 -> V_6 + 1 ) ;
return 0 ;
}
return - V_57 ;
}
static int F_35 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_81 ;
F_20 ( & V_2 -> V_20 ) ;
V_81 = F_36 ( V_32 ) ;
if ( V_81 )
goto V_82;
if ( F_37 ( V_32 ) )
F_38 ( & V_2 -> V_26 ) ;
V_82:
F_12 ( & V_2 -> V_20 ) ;
return V_81 ;
}
static int F_39 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
F_20 ( & V_2 -> V_20 ) ;
if ( F_37 ( V_32 ) && V_2 -> V_31 ) {
F_40 ( & V_2 -> V_27 ) ;
V_2 -> V_31 = 0 ;
}
F_41 ( V_32 ) ;
F_12 ( & V_2 -> V_20 ) ;
return 0 ;
}
static unsigned int F_42 ( struct V_32 * V_32 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
unsigned long V_85 = F_43 ( V_84 ) ;
unsigned int V_86 = F_44 ( V_32 , V_84 ) ;
F_45 ( V_32 , & V_2 -> V_26 , V_84 ) ;
if ( V_2 -> V_31 == 0 && ( V_85 & ( V_87 | V_88 ) ) ) {
F_20 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_31 == 0 )
F_17 ( V_2 ) ;
F_12 ( & V_2 -> V_20 ) ;
}
if ( V_2 -> V_23 != V_2 -> V_24 )
V_86 |= V_87 | V_88 ;
return V_86 ;
}
static int F_46 ( struct V_89 * V_2 , const struct V_90 * V_91 )
{
if ( ! V_2 )
return - V_92 ;
if ( V_6 > 0 )
return - V_93 ;
if ( ! F_47 ( V_2 , 0 ) )
return - V_92 ;
V_6 = F_48 ( V_2 , 0 ) ;
F_11 ( V_94 L_6 , V_6 ) ;
return V_6 ;
}
static void F_49 ( struct V_1 * V_2 )
{
static int V_95 [ 8 ] = { 0x330 , 0x332 , 0x334 , 0x336 , 0x338 , 0x33a , 0x33c , 0x33e } ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_2 -> V_6 = V_95 [ V_9 ] ;
if ( F_50 ( V_2 -> V_6 , 2 , L_7 ) ) {
F_7 ( V_2 , V_61 [ 1 ] . V_62 ) ;
if ( F_5 ( V_2 ) == V_61 [ 1 ] . V_62 ) {
F_51 ( V_2 -> V_6 , 2 ) ;
return;
}
F_51 ( V_2 -> V_6 , 2 ) ;
}
}
V_2 -> V_6 = - 1 ;
}
static int T_5 F_52 ( void )
{
struct V_1 * V_2 = & V_96 ;
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_99 * V_100 ;
int V_86 = - V_92 ;
F_24 ( V_98 -> V_59 , L_8 , sizeof( V_98 -> V_59 ) ) ;
F_53 ( & V_2 -> V_20 ) ;
if ( V_6 < 0 )
F_54 ( & V_101 ) ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 < 0 )
F_49 ( V_2 ) ;
if ( V_2 -> V_6 < 0 ) {
#ifdef F_55
F_56 ( V_98 , L_9 ) ;
F_56 ( V_98 , L_10 ) ;
#endif
goto V_82;
}
if ( ! F_50 ( V_2 -> V_6 , 2 , L_8 ) )
goto V_82;
V_86 = F_57 ( NULL , V_98 ) ;
if ( V_86 < 0 ) {
F_51 ( V_2 -> V_6 , 2 ) ;
F_56 ( V_98 , L_11 ) ;
goto V_82;
}
V_100 = & V_2 -> V_77 ;
F_58 ( V_100 , 2 ) ;
F_59 ( V_100 , & V_102 ,
V_79 , 0 , 1 , 1 , 1 ) ;
V_98 -> V_77 = V_100 ;
if ( V_100 -> error ) {
V_86 = V_100 -> error ;
F_56 ( V_98 , L_12 ) ;
goto V_103;
}
V_2 -> V_5 = true ;
V_2 -> V_15 = V_61 [ V_2 -> V_5 ] . V_62 ;
F_7 ( V_2 , V_2 -> V_15 ) ;
F_24 ( V_2 -> V_104 . V_59 , V_98 -> V_59 , sizeof( V_2 -> V_104 . V_59 ) ) ;
V_2 -> V_104 . V_98 = V_98 ;
V_2 -> V_104 . V_105 = & V_106 ;
V_2 -> V_104 . V_107 = & V_108 ;
V_2 -> V_104 . V_109 = V_110 ;
V_2 -> V_104 . V_20 = & V_2 -> V_20 ;
F_60 ( V_111 , & V_2 -> V_104 . V_112 ) ;
F_61 ( & V_2 -> V_104 , V_2 ) ;
if ( F_62 ( & V_2 -> V_104 , V_113 , V_114 ) < 0 )
goto V_103;
F_63 ( V_98 , L_13 , V_2 -> V_6 ) ;
return 0 ;
V_103:
F_64 ( V_100 ) ;
F_65 ( V_98 ) ;
F_51 ( V_2 -> V_6 , 2 ) ;
V_82:
F_66 ( & V_101 ) ;
return V_86 ;
}
static void T_6 F_67 ( void )
{
struct V_1 * V_2 = & V_96 ;
F_68 ( & V_2 -> V_104 ) ;
F_64 ( & V_2 -> V_77 ) ;
F_65 ( & V_2 -> V_98 ) ;
F_2 ( 7 , V_2 -> V_6 ) ;
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
F_51 ( V_2 -> V_6 , 2 ) ;
F_66 ( & V_101 ) ;
}
