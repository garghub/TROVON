static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
if ( V_2 -> V_5 != 0 )
return V_4 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
if ( ( F_4 ( V_2 -> V_7 + 1 ) & 0x40 ) == 0 )
V_3 = V_8 ;
F_5 ( & V_2 -> V_6 ) ;
return V_3 ;
}
static unsigned F_6 ( struct V_1 * V_2 )
{
int V_9 , V_10 ;
unsigned V_11 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
V_9 = F_4 ( V_2 -> V_7 + 1 ) ;
F_3 ( 0x00 , V_2 -> V_7 + 1 ) ;
V_2 -> V_12 = 0xffff ;
for ( V_10 = 0 ; V_10 < 25 ; V_10 ++ ) {
V_11 = ( V_11 << 1 ) | ( ( F_4 ( V_2 -> V_7 + 1 ) >> 7 ) & 0x01 ) ;
if ( V_10 < 24 ) {
F_3 ( 0x01 , V_2 -> V_7 + 1 ) ;
V_2 -> V_12 &= F_4 ( V_2 -> V_7 + 1 ) ;
F_3 ( 0x00 , V_2 -> V_7 + 1 ) ;
}
}
F_3 ( V_9 , V_2 -> V_7 + 1 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_11 ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned V_13 = 0 , V_14 , V_11 = 0 ;
V_11 = F_6 ( V_2 ) ;
if ( V_2 -> V_5 == 0 ) {
V_14 = 12500 ;
for ( V_10 = 0 ; V_10 < 14 ; V_10 ++ ) {
if ( ( V_11 & 0x01 ) != 0 )
V_13 += V_14 ;
V_14 = V_14 << 1 ;
V_11 = V_11 >> 1 ;
}
V_13 -= 10700000 ;
V_13 = ( V_13 * 16 ) / 1000000 ;
}
if ( V_2 -> V_5 == 1 )
V_13 = ( ( V_11 & 0x7fff ) - 2010 ) * 16 ;
return V_13 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_11 )
{
int V_10 ;
unsigned V_14 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
V_14 = 0 ;
V_14 = ( V_11 >> 23 ) & 0x02 ;
V_14 |= 0x1c ;
F_3 ( 7 , V_2 -> V_7 ) ;
F_3 ( V_14 , V_2 -> V_7 + 1 ) ;
for ( V_10 = 0 ; V_10 < 25 ; V_10 ++ ) {
V_14 |= 0x01 ;
F_3 ( V_14 , V_2 -> V_7 + 1 ) ;
V_14 &= 0xfe ;
F_3 ( V_14 , V_2 -> V_7 + 1 ) ;
V_11 = V_11 << 1 ;
V_14 = 0x1c | ( ( V_11 >> 23 ) & 0x02 ) ;
F_3 ( V_14 , V_2 -> V_7 + 1 ) ;
}
F_5 ( & V_2 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_13 )
{
unsigned V_11 ;
int V_10 , V_15 , V_14 ;
int V_9 ;
V_11 = 0 ;
if ( V_2 -> V_5 == 0 ) {
V_14 = 102400 ;
V_13 = ( V_13 * 1000 ) / 16 ;
V_13 += 10700 ;
for ( V_10 = 0 ; V_10 < 14 ; V_10 ++ ) {
V_11 = V_11 << 1 ;
if ( V_13 >= V_14 ) {
V_11 |= 0x01 ;
V_13 -= V_14 ;
}
V_14 = V_14 >> 1 ;
}
}
if ( V_2 -> V_5 == 1 ) {
V_11 = ( V_13 / 16 ) + 2010 ;
V_11 |= 0x100000 ;
}
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
V_9 = F_4 ( V_2 -> V_7 + 1 ) ;
F_5 ( & V_2 -> V_6 ) ;
for ( V_15 = 3 ; V_15 > - 1 ; V_15 -- ) {
F_8 ( V_2 , V_11 | ( V_15 << 16 ) ) ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
F_3 ( V_9 , V_2 -> V_7 + 1 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_10 ( 100 ) ;
F_6 ( V_2 ) ;
if ( ( V_2 -> V_12 & 0x40 ) == 0 ) {
V_2 -> V_16 = V_17 [ V_2 -> V_5 ] [ V_15 ] ;
return;
}
}
V_2 -> V_16 = 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
if ( ( F_4 ( V_2 -> V_7 + 1 ) & 0x20 ) != 0 )
V_3 = 0xffff ;
F_5 ( & V_2 -> V_6 ) ;
return V_3 ;
}
static void F_12 ( struct V_1 * V_2 , int V_18 )
{
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 7 , V_2 -> V_7 ) ;
if ( V_18 > 0 )
F_3 ( 0x20 , V_2 -> V_7 + 1 ) ;
else
F_3 ( 0x00 , V_2 -> V_7 + 1 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static void F_13 ( unsigned long V_19 )
{
struct V_1 * V_2 = ( void * ) V_19 ;
if ( F_14 ( & V_2 -> V_6 ) ) {
F_3 ( 0x3 , V_2 -> V_7 ) ;
if ( ( F_4 ( V_2 -> V_7 + 1 ) & 0x20 ) != 0 )
F_15 ( V_20 L_1 ) ;
F_3 ( 0x80 , V_2 -> V_7 ) ;
while ( ( F_4 ( V_2 -> V_7 ) & 0x80 ) != 0 ) {
V_2 -> V_21 [ V_2 -> V_22 ] = F_4 ( V_2 -> V_7 + 1 ) ;
if ( V_2 -> V_22 == V_2 -> V_23 )
F_15 ( V_24 L_2 ) ;
else
V_2 -> V_22 ++ ;
}
F_5 ( & V_2 -> V_6 ) ;
}
if ( V_2 -> V_22 != V_2 -> V_23 )
F_16 ( & V_2 -> V_25 ) ;
F_17 ( & V_2 -> V_26 ) ;
V_2 -> V_26 . V_27 = F_13 ;
V_2 -> V_26 . V_19 = ( unsigned long ) 0 ;
V_2 -> V_26 . V_28 = V_29 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_26 ) ;
}
static T_1 F_20 ( struct V_30 * V_30 , char T_2 * V_19 , T_3 V_31 , T_4 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
unsigned char V_33 [ V_34 ] ;
int V_10 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_35 == 0 ) {
V_2 -> V_35 = 1 ;
F_3 ( 0x80 , V_2 -> V_7 ) ;
F_17 ( & V_2 -> V_26 ) ;
V_2 -> V_26 . V_27 = F_13 ;
V_2 -> V_26 . V_19 = ( unsigned long ) V_2 ;
V_2 -> V_26 . V_28 = V_29 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_26 ) ;
}
if ( V_2 -> V_22 == V_2 -> V_23 ) {
F_5 ( & V_2 -> V_6 ) ;
if ( V_30 -> V_36 & V_37 )
return - V_38 ;
F_22 ( & V_2 -> V_25 ) ;
F_2 ( & V_2 -> V_6 ) ;
}
while ( V_10 < V_31 && V_2 -> V_22 != V_2 -> V_23 )
V_33 [ V_10 ++ ] = V_2 -> V_21 [ V_2 -> V_23 ++ ] ;
F_5 ( & V_2 -> V_6 ) ;
if ( F_23 ( V_19 , V_33 , V_10 ) )
return - V_39 ;
return V_10 ;
}
static int F_24 ( struct V_30 * V_30 , void * V_40 ,
struct V_41 * V_42 )
{
F_25 ( V_42 -> V_43 , L_3 , sizeof( V_42 -> V_43 ) ) ;
F_25 ( V_42 -> V_44 , L_3 , sizeof( V_42 -> V_44 ) ) ;
F_25 ( V_42 -> V_45 , L_4 , sizeof( V_42 -> V_45 ) ) ;
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = V_49 | V_50 |
V_51 | V_52 ;
return 0 ;
}
static int F_26 ( struct V_30 * V_30 , void * V_40 ,
struct V_53 * V_42 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
V_42 -> type = V_54 ;
switch ( V_42 -> V_55 ) {
case 0 :
F_25 ( V_42 -> V_56 , L_5 , sizeof( V_42 -> V_56 ) ) ;
V_42 -> V_57 = V_58 | V_59 |
V_60 ;
V_42 -> V_61 = 1400 ;
V_42 -> V_62 = 1728 ;
V_42 -> V_63 = F_1 ( V_2 ) ;
switch ( V_42 -> V_63 ) {
case V_4 :
V_42 -> V_64 = V_65 ;
break;
case V_8 :
V_42 -> V_64 = V_66 ;
break;
default:
break;
}
V_42 -> V_63 |= V_67 ;
break;
case 1 :
F_25 ( V_42 -> V_56 , L_6 , sizeof( V_42 -> V_56 ) ) ;
V_42 -> V_57 = V_68 ;
V_42 -> V_61 = 8320 ;
V_42 -> V_62 = 26400 ;
V_42 -> V_63 = V_4 ;
V_42 -> V_64 = V_65 ;
break;
default:
return - V_69 ;
}
V_42 -> signal = V_2 -> V_16 ;
return 0 ;
}
static int F_27 ( struct V_30 * V_30 , void * V_40 ,
struct V_53 * V_42 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
if ( V_42 -> V_55 != 0 && V_42 -> V_55 != 1 )
return - V_69 ;
V_2 -> V_5 = V_42 -> V_55 ;
return 0 ;
}
static int F_28 ( struct V_30 * V_30 , void * V_40 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
V_71 -> V_72 = V_2 -> V_5 ;
V_71 -> type = V_54 ;
V_71 -> V_73 = F_7 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_30 , void * V_40 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
if ( V_71 -> type != V_54 )
return - V_69 ;
if ( V_2 -> V_5 == 0 && ( V_71 -> V_73 < 1400 || V_71 -> V_73 > 1728 ) )
return - V_69 ;
if ( V_2 -> V_5 == 1 && ( V_71 -> V_73 < 8320 || V_71 -> V_73 > 26400 ) )
return - V_69 ;
F_9 ( V_2 , V_71 -> V_73 ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_30 , void * V_40 ,
struct V_74 * V_75 )
{
switch ( V_75 -> V_76 ) {
case V_77 :
return F_31 ( V_75 , 0 , 1 , 1 , 1 ) ;
case V_78 :
return F_31 ( V_75 , 0 , 0xff , 1 , 0xff ) ;
}
return - V_69 ;
}
static int F_32 ( struct V_30 * V_30 , void * V_40 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
switch ( V_80 -> V_76 ) {
case V_77 :
V_80 -> V_81 = ( F_11 ( V_2 ) == 0 ) ;
break;
case V_78 :
V_80 -> V_81 = F_11 ( V_2 ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_33 ( struct V_30 * V_30 , void * V_40 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
switch ( V_80 -> V_76 ) {
case V_77 :
if ( V_80 -> V_81 )
F_12 ( V_2 , 0 ) ;
else
F_12 ( V_2 , 0xffff ) ;
break;
case V_78 :
F_12 ( V_2 , V_80 -> V_81 ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_34 ( struct V_30 * V_82 , void * V_40 , unsigned int * V_10 )
{
* V_10 = 0 ;
return 0 ;
}
static int F_35 ( struct V_30 * V_82 , void * V_40 , unsigned int V_10 )
{
return V_10 ? - V_69 : 0 ;
}
static int F_36 ( struct V_30 * V_30 , void * V_40 ,
struct V_83 * V_84 )
{
V_84 -> V_55 = 0 ;
F_25 ( V_84 -> V_56 , L_7 , sizeof( V_84 -> V_56 ) ) ;
V_84 -> V_57 = V_85 ;
return 0 ;
}
static int F_37 ( struct V_30 * V_30 , void * V_40 ,
struct V_83 * V_84 )
{
return V_84 -> V_55 ? - V_69 : 0 ;
}
static int F_38 ( struct V_30 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_86 ++ ;
if ( 1 == V_2 -> V_86 )
F_39 ( & V_2 -> V_25 ) ;
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_30 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_86 -- ;
if ( 0 == V_2 -> V_86 ) {
F_41 ( & V_2 -> V_26 ) ;
V_2 -> V_35 = 0 ;
}
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
static unsigned int F_42 ( struct V_30 * V_30 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
F_43 ( V_30 , & V_2 -> V_25 , V_88 ) ;
if ( V_2 -> V_22 != V_2 -> V_23 )
return V_89 | V_90 ;
return 0 ;
}
static int F_44 ( struct V_91 * V_2 , const struct V_92 * V_93 )
{
if ( ! V_2 )
return - V_94 ;
if ( V_7 > 0 )
return - V_95 ;
if ( ! F_45 ( V_2 , 0 ) )
return - V_94 ;
V_7 = F_46 ( V_2 , 0 ) ;
F_15 ( V_96 L_8 , V_7 ) ;
return V_7 ;
}
static void F_47 ( struct V_1 * V_2 )
{
static int V_97 [ 8 ] = { 0x330 , 0x332 , 0x334 , 0x336 , 0x338 , 0x33a , 0x33c , 0x33e } ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_2 -> V_7 = V_97 [ V_10 ] ;
if ( F_48 ( V_2 -> V_7 , 2 , L_9 ) ) {
F_9 ( V_2 , 1410 ) ;
if ( F_7 ( V_2 ) == 1410 ) {
F_49 ( V_2 -> V_7 , 2 ) ;
return;
}
F_49 ( V_2 -> V_7 , 2 ) ;
}
}
V_2 -> V_7 = - 1 ;
}
static int T_5 F_50 ( void )
{
struct V_1 * V_2 = & V_98 ;
struct V_99 * V_100 = & V_2 -> V_100 ;
int V_101 ;
F_25 ( V_100 -> V_56 , L_10 , sizeof( V_100 -> V_56 ) ) ;
F_51 ( & V_2 -> V_6 ) ;
if ( V_7 < 0 )
F_52 ( & V_102 ) ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_7 < 0 )
F_47 ( V_2 ) ;
if ( V_2 -> V_7 < 0 ) {
#ifdef F_53
F_54 ( V_100 , L_11 ) ;
F_54 ( V_100 , L_12 ) ;
#endif
goto V_103;
}
if ( ! F_48 ( V_2 -> V_7 , 2 , L_10 ) )
goto V_103;
V_101 = F_55 ( NULL , V_100 ) ;
if ( V_101 < 0 ) {
F_49 ( V_2 -> V_7 , 2 ) ;
F_54 ( V_100 , L_13 ) ;
goto V_103;
}
F_25 ( V_2 -> V_104 . V_56 , V_100 -> V_56 , sizeof( V_2 -> V_104 . V_56 ) ) ;
V_2 -> V_104 . V_100 = V_100 ;
V_2 -> V_104 . V_105 = & V_106 ;
V_2 -> V_104 . V_107 = & V_108 ;
V_2 -> V_104 . V_109 = V_110 ;
F_56 ( & V_2 -> V_104 , V_2 ) ;
if ( F_57 ( & V_2 -> V_104 , V_111 , V_112 ) < 0 ) {
F_58 ( V_100 ) ;
F_49 ( V_2 -> V_7 , 2 ) ;
goto V_103;
}
F_59 ( V_100 , L_14 , V_2 -> V_7 ) ;
return 0 ;
V_103:
F_60 ( & V_102 ) ;
return - V_94 ;
}
static void T_6 F_61 ( void )
{
struct V_1 * V_2 = & V_98 ;
F_62 ( & V_2 -> V_104 ) ;
F_58 ( & V_2 -> V_100 ) ;
F_49 ( V_2 -> V_7 , 2 ) ;
F_60 ( & V_102 ) ;
}
