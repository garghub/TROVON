static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 * V_4 )
{
if ( V_3 > V_5 )
return - V_6 ;
* V_4 = F_2 ( V_2 -> V_7 -> V_8 . V_9 + ( 4 * V_3 ) ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
if ( V_3 > V_5 )
return - V_6 ;
F_4 ( V_4 , V_2 -> V_7 -> V_8 . V_9 + ( 4 * V_3 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_10 , T_1 * V_4 )
{
static const T_2 V_11 [] = { 1 , 2 , 6 , 0 } ;
struct V_12 * V_13 = F_6 ( V_2 -> V_7 -> V_14 -> V_15 ) ;
int V_16 = 2 * V_2 -> V_7 -> V_17 + V_2 -> V_18 ;
T_1 V_19 = 0 ;
T_2 V_20 ;
switch ( V_10 ) {
case V_21 :
F_7 ( V_13 , 0xA0 + V_16 , & V_20 ) ;
V_19 |= V_20 & 0x03 ;
if ( V_20 & ( 1 << 4 ) )
V_19 |= 0x02 << 4 ;
else
V_19 |= 0x01 << 4 ;
V_19 |= V_11 [ ( V_20 >> 2 ) & 0x3 ] ;
break;
case V_22 :
F_8 ( V_13 -> V_23 != 0x5287 ) ;
F_9 ( V_13 , 0xB0 + V_16 * 4 , & V_19 ) ;
break;
case V_5 :
F_7 ( V_13 , 0xA4 + V_16 , & V_20 ) ;
V_19 |= ( ( V_20 & 0x02 ) << 1 ) | ( V_20 & 0x01 ) ;
V_19 |= ( ( V_20 >> 2 ) & 0x03 ) << 8 ;
break;
default:
return - V_6 ;
}
* V_4 = V_19 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_10 , T_1 V_4 )
{
struct V_12 * V_13 = F_6 ( V_2 -> V_7 -> V_14 -> V_15 ) ;
int V_16 = 2 * V_2 -> V_7 -> V_17 + V_2 -> V_18 ;
T_1 V_19 = 0 ;
switch ( V_10 ) {
case V_22 :
F_8 ( V_13 -> V_23 != 0x5287 ) ;
F_11 ( V_13 , 0xB0 + V_16 * 4 , V_4 ) ;
return 0 ;
case V_5 :
V_19 |= ( ( V_4 & 0x4 ) >> 1 ) | ( V_4 & 0x1 ) ;
V_19 |= ( ( V_4 >> 8 ) & 0x3 ) << 2 ;
F_12 ( V_13 , 0xA4 + V_16 , V_19 ) ;
return 0 ;
default:
return - V_6 ;
}
}
static void F_13 ( struct V_24 * V_7 , const struct V_25 * V_26 )
{
struct V_25 V_27 ;
if ( V_26 -> V_28 != V_7 -> V_29 ) {
V_27 = * V_26 ;
V_27 . V_30 |= V_31 ;
V_26 = & V_27 ;
}
F_14 ( V_7 , V_26 ) ;
}
static void F_15 ( struct V_24 * V_7 )
{
V_7 -> V_32 -> V_33 ( V_7 ) ;
F_16 ( V_7 ) ;
}
static int F_17 ( struct V_1 * V_2 , unsigned long V_34 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_35 * V_36 = & V_7 -> V_2 . V_37 ;
unsigned long V_38 = V_39 + ( V_40 * 5 ) ;
T_1 V_41 , V_42 ;
int V_43 ;
if ( ! ( V_7 -> V_44 & V_45 ) )
goto V_46;
F_3 ( V_2 , V_5 , 0x300 ) ;
F_1 ( V_2 , V_5 , & V_42 ) ;
do {
F_18 ( V_2 -> V_7 , 200 ) ;
F_1 ( V_2 , V_21 , & V_41 ) ;
if ( ( V_41 & 0xf ) != 1 )
break;
} while ( F_19 ( V_39 , V_38 ) );
F_1 ( V_2 , V_21 , & V_41 ) ;
F_1 ( V_2 , V_5 , & V_42 ) ;
V_43 = ( V_41 & 0xf ) == 0x3 ;
F_20 ( V_7 , V_47 ,
L_1 ,
V_43 ? L_2 : L_3 , V_41 , V_42 ) ;
F_1 ( V_2 , V_21 , & V_41 ) ;
if ( ! V_43 ) {
V_36 -> V_48 . V_49 &= ~ V_50 ;
return 0 ;
}
V_46:
F_21 ( V_2 , V_34 ) ;
return 0 ;
}
static void F_22 ( struct V_51 * V_52 )
{
struct V_24 * V_7 = V_52 -> V_7 ;
if ( ( V_52 -> V_26 . V_53 == V_54 ) &&
( V_52 -> V_55 -> V_56 == V_57 ) ) {
F_23 ( V_7 ) ;
}
F_24 ( V_52 ) ;
}
static int F_25 ( struct V_24 * V_7 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
T_2 V_58 ;
F_7 ( V_13 , V_59 , & V_58 ) ;
if ( V_58 & 0x10 )
return V_60 ;
return V_61 ;
}
static void F_26 ( struct V_24 * V_7 , struct V_62 * V_63 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
static const T_2 V_64 [] = { 0xA8 , 0x65 , 0x65 , 0x31 , 0x20 } ;
F_12 ( V_13 , V_65 - V_63 -> V_66 ,
V_64 [ V_63 -> V_67 - V_68 ] ) ;
}
static void F_27 ( struct V_24 * V_7 , struct V_62 * V_63 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
static const T_2 V_69 [] = { 0xEE , 0xE8 , 0xE6 , 0xE4 , 0xE2 , 0xE1 , 0xE0 , 0xE0 } ;
F_12 ( V_13 , V_59 - V_63 -> V_66 ,
V_69 [ V_63 -> V_70 - V_71 ] ) ;
}
static void T_3 * F_28 ( void T_3 * V_72 , unsigned int V_73 )
{
return V_72 + ( V_73 * 128 ) ;
}
static void T_3 * F_29 ( void T_3 * V_72 , unsigned int V_73 )
{
return V_72 + ( V_73 * 64 ) ;
}
static void F_30 ( struct V_24 * V_7 )
{
void T_3 * const * V_74 = V_7 -> V_14 -> V_74 ;
void T_3 * V_75 = V_74 [ V_7 -> V_17 ] ;
void T_3 * V_76 = V_74 [ 4 ] + ( V_7 -> V_17 * 8 ) ;
struct V_77 * V_8 = & V_7 -> V_8 ;
V_8 -> V_78 = V_75 ;
V_8 -> V_79 =
V_8 -> V_80 = ( void T_3 * )
( ( unsigned long ) ( V_75 + 8 ) | V_81 ) ;
V_8 -> V_76 = V_76 ;
V_8 -> V_9 = F_29 ( V_74 [ 5 ] , V_7 -> V_17 ) ;
F_31 ( V_8 ) ;
F_32 ( V_7 , V_7 -> V_17 , - 1 , L_4 ) ;
F_32 ( V_7 , 4 , V_7 -> V_17 * 8 , L_5 ) ;
}
static int F_33 ( struct V_12 * V_13 , struct V_82 * * V_83 )
{
const struct V_84 * V_85 [] = { & V_86 , NULL } ;
struct V_82 * V_14 ;
int V_87 ;
V_87 = F_34 ( V_13 , V_85 , & V_14 ) ;
if ( V_87 )
return V_87 ;
* V_83 = V_14 ;
V_87 = F_35 ( V_13 , 1 << 5 , V_88 ) ;
if ( V_87 ) {
F_36 ( V_89 , & V_13 -> V_15 , L_6 ) ;
return V_87 ;
}
V_14 -> V_90 [ 0 ] -> V_8 . V_9 = F_28 ( V_14 -> V_74 [ 5 ] , 0 ) ;
V_14 -> V_90 [ 1 ] -> V_8 . V_9 = F_28 ( V_14 -> V_74 [ 5 ] , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_82 * * V_83 )
{
const struct V_84 * V_85 [] =
{ & V_91 , & V_91 , & V_92 } ;
struct V_82 * V_14 ;
int V_48 , V_87 ;
* V_83 = V_14 = F_38 ( & V_13 -> V_15 , V_85 , F_39 ( V_85 ) ) ;
if ( ! V_14 ) {
F_36 ( V_89 , & V_13 -> V_15 , L_7 ) ;
return - V_93 ;
}
V_87 = F_35 ( V_13 , 0x3f , V_88 ) ;
if ( V_87 ) {
F_36 ( V_89 , & V_13 -> V_15 , L_8
L_9 , V_87 ) ;
return V_87 ;
}
V_14 -> V_74 = F_40 ( V_13 ) ;
for ( V_48 = 0 ; V_48 < V_14 -> V_94 ; V_48 ++ )
F_30 ( V_14 -> V_90 [ V_48 ] ) ;
V_87 = F_41 ( V_13 , V_95 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_42 ( V_13 , V_95 ) ;
if ( V_87 )
return V_87 ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 , struct V_82 * * V_83 )
{
const struct V_84 * V_85 [] = { & V_96 , NULL } ;
struct V_82 * V_14 ;
int V_48 , V_87 ;
V_87 = F_34 ( V_13 , V_85 , & V_14 ) ;
if ( V_87 )
return V_87 ;
* V_83 = V_14 ;
V_87 = F_35 ( V_13 , 1 << 5 , V_88 ) ;
if ( V_87 ) {
F_36 ( V_89 , & V_13 -> V_15 , L_6 ) ;
return V_87 ;
}
for ( V_48 = 0 ; V_48 < V_14 -> V_94 ; V_48 ++ )
F_44 ( V_14 -> V_90 [ V_48 ] ) ;
return 0 ;
}
static void F_45 ( struct V_12 * V_13 , int V_97 )
{
T_2 V_98 ;
F_7 ( V_13 , V_99 , & V_98 ) ;
F_36 ( V_47 , & V_13 -> V_15 , L_10 ,
( int ) ( V_98 & 0xf0 ) == 0xf0 ? 0 : V_98 & 0x0f ) ;
F_7 ( V_13 , V_100 , & V_98 ) ;
if ( ( V_98 & V_101 ) != V_101 ) {
F_36 ( V_102 , & V_13 -> V_15 ,
L_11 ,
( int ) V_98 ) ;
V_98 |= V_101 ;
F_12 ( V_13 , V_100 , V_98 ) ;
}
F_7 ( V_13 , V_103 , & V_98 ) ;
if ( ( V_98 & V_101 ) != V_101 ) {
F_36 ( V_102 , & V_13 -> V_15 ,
L_12 ,
( int ) V_98 ) ;
V_98 |= V_101 ;
F_12 ( V_13 , V_103 , V_98 ) ;
}
F_7 ( V_13 , V_104 , & V_98 ) ;
if ( ( V_98 & V_105 ) != V_105 ) {
F_36 ( V_102 , & V_13 -> V_15 ,
L_13 ,
( int ) V_98 ) ;
V_98 |= V_105 ;
F_12 ( V_13 , V_104 , V_98 ) ;
}
if ( V_97 == V_106 || V_97 == V_107 ) {
F_7 ( V_13 , 0x52 , & V_98 ) ;
V_98 |= 1 << 2 ;
F_12 ( V_13 , 0x52 , V_98 ) ;
}
}
static int F_46 ( struct V_12 * V_13 , const struct V_108 * V_109 )
{
static int V_110 ;
unsigned int V_48 ;
int V_87 ;
struct V_82 * V_14 = NULL ;
int V_97 = ( int ) V_109 -> V_111 ;
const unsigned * V_112 ;
if ( ! V_110 ++ )
F_36 ( V_102 , & V_13 -> V_15 , L_14 V_113 L_15 ) ;
V_87 = F_47 ( V_13 ) ;
if ( V_87 )
return V_87 ;
if ( V_97 == V_107 )
V_112 = & V_114 [ 0 ] ;
else
V_112 = & V_115 [ 0 ] ;
for ( V_48 = 0 ; V_48 < F_39 ( V_115 ) ; V_48 ++ )
if ( ( F_48 ( V_13 , V_48 ) == 0 ) ||
( F_49 ( V_13 , V_48 ) < V_112 [ V_48 ] ) ) {
F_36 ( V_89 , & V_13 -> V_15 ,
L_16 ,
V_48 ,
( unsigned long long ) F_48 ( V_13 , V_48 ) ,
( unsigned long long ) F_49 ( V_13 , V_48 ) ) ;
return - V_116 ;
}
switch ( V_97 ) {
case V_106 :
V_87 = F_33 ( V_13 , & V_14 ) ;
break;
case V_107 :
V_87 = F_37 ( V_13 , & V_14 ) ;
break;
case V_117 :
V_87 = F_43 ( V_13 , & V_14 ) ;
break;
default:
V_87 = - V_6 ;
}
if ( V_87 )
return V_87 ;
F_45 ( V_13 , V_97 ) ;
F_50 ( V_13 ) ;
return F_51 ( V_14 , V_13 -> V_118 , V_119 ,
V_120 , & V_121 ) ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_122 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_122 ) ;
}
