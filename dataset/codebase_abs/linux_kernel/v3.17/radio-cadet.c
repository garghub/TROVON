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
F_17 ( & V_2 -> V_29 ) ;
V_2 -> V_29 . V_30 = F_13 ;
V_2 -> V_29 . V_26 = V_26 ;
V_2 -> V_29 . V_31 = V_32 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_29 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_33 = 1 ;
F_2 ( 0x80 , V_2 -> V_6 ) ;
F_17 ( & V_2 -> V_29 ) ;
V_2 -> V_29 . V_30 = F_13 ;
V_2 -> V_29 . V_26 = ( unsigned long ) V_2 ;
V_2 -> V_29 . V_31 = V_32 + F_18 ( 50 ) ;
F_19 ( & V_2 -> V_29 ) ;
}
static T_1 F_21 ( struct V_34 * V_34 , char T_2 * V_26 , T_3 V_35 , T_4 * V_36 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
unsigned char V_37 [ V_38 ] ;
int V_9 = 0 ;
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_33 == 0 )
F_20 ( V_2 ) ;
F_12 ( & V_2 -> V_23 ) ;
if ( ! F_10 ( V_2 ) && ( V_34 -> V_39 & V_40 ) )
return - V_41 ;
V_9 = F_23 ( V_2 -> V_28 , F_10 ( V_2 ) ) ;
if ( V_9 )
return V_9 ;
F_11 ( & V_2 -> V_23 ) ;
while ( V_9 < V_35 && V_2 -> V_24 != V_2 -> V_25 )
V_37 [ V_9 ++ ] = V_2 -> V_27 [ V_2 -> V_25 ++ ] ;
F_12 ( & V_2 -> V_23 ) ;
if ( V_9 && F_24 ( V_26 , V_37 , V_9 ) )
return - V_42 ;
return V_9 ;
}
static int F_25 ( struct V_34 * V_34 , void * V_43 ,
struct V_44 * V_45 )
{
F_26 ( V_45 -> V_46 , L_2 , sizeof( V_45 -> V_46 ) ) ;
F_26 ( V_45 -> V_47 , L_2 , sizeof( V_45 -> V_47 ) ) ;
F_26 ( V_45 -> V_48 , L_3 , sizeof( V_45 -> V_48 ) ) ;
V_45 -> V_49 = V_50 | V_51 |
V_52 | V_53 ;
V_45 -> V_54 = V_45 -> V_49 | V_55 ;
return 0 ;
}
static int F_27 ( struct V_34 * V_34 , void * V_43 ,
struct V_56 * V_45 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
if ( V_45 -> V_57 )
return - V_58 ;
V_45 -> type = V_59 ;
F_26 ( V_45 -> V_60 , L_4 , sizeof( V_45 -> V_60 ) ) ;
V_45 -> V_61 = V_15 [ 0 ] . V_61 | V_15 [ 1 ] . V_61 ;
V_45 -> V_16 = V_15 [ 0 ] . V_16 ;
V_45 -> V_17 = V_15 [ 1 ] . V_17 ;
if ( V_2 -> V_5 ) {
V_45 -> V_62 = F_1 ( V_2 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
F_2 ( F_3 ( V_2 -> V_6 + 1 ) & 0x7f , V_2 -> V_6 + 1 ) ;
F_28 ( 100 ) ;
F_2 ( 3 , V_2 -> V_6 ) ;
if ( F_3 ( V_2 -> V_6 + 1 ) & 0x80 )
V_45 -> V_62 |= V_63 ;
} else {
V_45 -> V_16 = 8320 ;
V_45 -> V_17 = 26400 ;
V_45 -> V_62 = V_4 ;
}
V_45 -> V_64 = V_65 ;
V_45 -> signal = V_2 -> V_19 ;
return 0 ;
}
static int F_29 ( struct V_34 * V_34 , void * V_43 ,
const struct V_56 * V_45 )
{
return V_45 -> V_57 ? - V_58 : 0 ;
}
static int F_30 ( struct V_34 * V_34 , void * V_43 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_68 )
return - V_58 ;
if ( V_67 -> V_57 >= F_31 ( V_15 ) )
return - V_58 ;
* V_67 = V_15 [ V_67 -> V_57 ] ;
return 0 ;
}
static int F_32 ( struct V_34 * V_34 , void * V_43 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
if ( V_70 -> V_68 )
return - V_58 ;
V_70 -> type = V_59 ;
V_70 -> V_71 = V_2 -> V_18 ;
return 0 ;
}
static int F_33 ( struct V_34 * V_34 , void * V_43 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
if ( V_70 -> V_68 )
return - V_58 ;
V_2 -> V_5 =
V_70 -> V_71 >= ( V_15 [ 0 ] . V_17 + V_15 [ 1 ] . V_16 ) / 2 ;
F_7 ( V_2 , V_70 -> V_71 ) ;
return 0 ;
}
static int F_34 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_35 ( V_73 -> V_74 , struct V_1 , V_75 ) ;
switch ( V_73 -> V_76 ) {
case V_77 :
F_2 ( 7 , V_2 -> V_6 ) ;
if ( V_73 -> V_78 )
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
else
F_2 ( 0x20 , V_2 -> V_6 + 1 ) ;
return 0 ;
}
return - V_58 ;
}
static int F_36 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
int V_79 ;
F_11 ( & V_2 -> V_23 ) ;
V_79 = F_37 ( V_34 ) ;
if ( V_79 )
goto V_80;
if ( F_38 ( V_34 ) )
F_39 ( & V_2 -> V_28 ) ;
V_80:
F_12 ( & V_2 -> V_23 ) ;
return V_79 ;
}
static int F_40 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
F_11 ( & V_2 -> V_23 ) ;
if ( F_38 ( V_34 ) && V_2 -> V_33 ) {
F_41 ( & V_2 -> V_29 ) ;
V_2 -> V_33 = 0 ;
}
F_42 ( V_34 ) ;
F_12 ( & V_2 -> V_23 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_34 * V_34 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
unsigned long V_83 = F_44 ( V_82 ) ;
unsigned int V_84 = F_45 ( V_34 , V_82 ) ;
F_46 ( V_34 , & V_2 -> V_28 , V_82 ) ;
if ( V_2 -> V_33 == 0 && ( V_83 & ( V_85 | V_86 ) ) ) {
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_33 == 0 )
F_20 ( V_2 ) ;
F_12 ( & V_2 -> V_23 ) ;
}
if ( F_10 ( V_2 ) )
V_84 |= V_85 | V_86 ;
return V_84 ;
}
static int F_47 ( struct V_87 * V_2 , const struct V_88 * V_89 )
{
if ( ! V_2 )
return - V_90 ;
if ( V_6 > 0 )
return - V_91 ;
if ( ! F_48 ( V_2 , 0 ) )
return - V_90 ;
V_6 = F_49 ( V_2 , 0 ) ;
F_50 ( V_92 L_5 , V_6 ) ;
return V_6 ;
}
static void F_51 ( struct V_1 * V_2 )
{
static int V_93 [ 8 ] = { 0x330 , 0x332 , 0x334 , 0x336 , 0x338 , 0x33a , 0x33c , 0x33e } ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_2 -> V_6 = V_93 [ V_9 ] ;
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
struct V_1 * V_2 = & V_94 ;
struct V_95 * V_96 = & V_2 -> V_96 ;
struct V_97 * V_98 ;
int V_84 = - V_90 ;
F_26 ( V_96 -> V_60 , L_7 , sizeof( V_96 -> V_60 ) ) ;
F_55 ( & V_2 -> V_23 ) ;
if ( V_6 < 0 )
F_56 ( & V_99 ) ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 < 0 )
F_51 ( V_2 ) ;
if ( V_2 -> V_6 < 0 ) {
#ifdef F_57
F_58 ( V_96 , L_8 ) ;
F_58 ( V_96 , L_9 ) ;
#endif
goto V_80;
}
if ( ! F_52 ( V_2 -> V_6 , 2 , L_7 ) )
goto V_80;
V_84 = F_59 ( NULL , V_96 ) ;
if ( V_84 < 0 ) {
F_53 ( V_2 -> V_6 , 2 ) ;
F_58 ( V_96 , L_10 ) ;
goto V_80;
}
V_98 = & V_2 -> V_75 ;
F_60 ( V_98 , 2 ) ;
F_61 ( V_98 , & V_100 ,
V_77 , 0 , 1 , 1 , 1 ) ;
V_96 -> V_75 = V_98 ;
if ( V_98 -> error ) {
V_84 = V_98 -> error ;
F_58 ( V_96 , L_11 ) ;
goto V_101;
}
V_2 -> V_5 = true ;
V_2 -> V_18 = V_15 [ V_2 -> V_5 ] . V_16 ;
F_7 ( V_2 , V_2 -> V_18 ) ;
F_26 ( V_2 -> V_102 . V_60 , V_96 -> V_60 , sizeof( V_2 -> V_102 . V_60 ) ) ;
V_2 -> V_102 . V_96 = V_96 ;
V_2 -> V_102 . V_103 = & V_104 ;
V_2 -> V_102 . V_105 = & V_106 ;
V_2 -> V_102 . V_107 = V_108 ;
V_2 -> V_102 . V_23 = & V_2 -> V_23 ;
F_62 ( & V_2 -> V_102 , V_2 ) ;
V_84 = F_63 ( & V_2 -> V_102 , V_109 , V_110 ) ;
if ( V_84 < 0 )
goto V_101;
F_64 ( V_96 , L_12 , V_2 -> V_6 ) ;
return 0 ;
V_101:
F_65 ( V_98 ) ;
F_66 ( V_96 ) ;
F_53 ( V_2 -> V_6 , 2 ) ;
V_80:
F_67 ( & V_99 ) ;
return V_84 ;
}
static void T_6 F_68 ( void )
{
struct V_1 * V_2 = & V_94 ;
F_69 ( & V_2 -> V_102 ) ;
F_65 ( & V_2 -> V_75 ) ;
F_66 ( & V_2 -> V_96 ) ;
F_2 ( 7 , V_2 -> V_6 ) ;
F_2 ( 0x00 , V_2 -> V_6 + 1 ) ;
F_53 ( V_2 -> V_6 , 2 ) ;
F_67 ( & V_99 ) ;
}
