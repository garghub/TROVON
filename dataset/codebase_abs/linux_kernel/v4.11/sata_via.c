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
F_20 ( V_7 ,
L_1 ,
V_43 ? L_2 : L_3 , V_41 , V_42 ) ;
F_1 ( V_2 , V_21 , & V_41 ) ;
if ( ! V_43 ) {
V_36 -> V_47 . V_48 &= ~ V_49 ;
return 0 ;
}
V_46:
F_21 ( V_2 , V_34 ) ;
return 0 ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_24 * V_7 = V_51 -> V_7 ;
if ( ( V_51 -> V_26 . V_52 == V_53 ) &&
( V_51 -> V_54 -> V_55 == V_56 ) ) {
F_23 ( V_7 ) ;
}
F_24 ( V_51 ) ;
}
static int F_25 ( struct V_24 * V_7 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
T_2 V_57 ;
F_7 ( V_13 , V_58 , & V_57 ) ;
if ( V_57 & 0x10 )
return V_59 ;
return V_60 ;
}
static void F_26 ( struct V_24 * V_7 , struct V_61 * V_62 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
static const T_2 V_63 [] = { 0xA8 , 0x65 , 0x65 , 0x31 , 0x20 } ;
F_12 ( V_13 , V_64 - V_62 -> V_65 ,
V_63 [ V_62 -> V_66 - V_67 ] ) ;
}
static void F_27 ( struct V_24 * V_7 , struct V_61 * V_62 )
{
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
static const T_2 V_68 [] = { 0xEE , 0xE8 , 0xE6 , 0xE4 , 0xE2 , 0xE1 , 0xE0 , 0xE0 } ;
F_12 ( V_13 , V_58 - V_62 -> V_65 ,
V_68 [ V_62 -> V_69 - V_70 ] ) ;
}
static void T_3 * F_28 ( void T_3 * V_71 , unsigned int V_72 )
{
return V_71 + ( V_72 * 128 ) ;
}
static void T_3 * F_29 ( void T_3 * V_71 , unsigned int V_72 )
{
return V_71 + ( V_72 * 64 ) ;
}
static void F_30 ( struct V_24 * V_7 )
{
void T_3 * const * V_73 = V_7 -> V_14 -> V_73 ;
void T_3 * V_74 = V_73 [ V_7 -> V_17 ] ;
void T_3 * V_75 = V_73 [ 4 ] + ( V_7 -> V_17 * 8 ) ;
struct V_76 * V_8 = & V_7 -> V_8 ;
V_8 -> V_77 = V_74 ;
V_8 -> V_78 =
V_8 -> V_79 = ( void T_3 * )
( ( unsigned long ) ( V_74 + 8 ) | V_80 ) ;
V_8 -> V_75 = V_75 ;
V_8 -> V_9 = F_29 ( V_73 [ 5 ] , V_7 -> V_17 ) ;
F_31 ( V_8 ) ;
F_32 ( V_7 , V_7 -> V_17 , - 1 , L_4 ) ;
F_32 ( V_7 , 4 , V_7 -> V_17 * 8 , L_5 ) ;
}
static int F_33 ( struct V_12 * V_13 , struct V_81 * * V_82 )
{
const struct F_20 * V_83 [] = { & V_84 , NULL } ;
struct V_81 * V_14 ;
int V_85 ;
V_85 = F_34 ( V_13 , V_83 , & V_14 ) ;
if ( V_85 )
return V_85 ;
* V_82 = V_14 ;
V_85 = F_35 ( V_13 , 1 << 5 , V_86 ) ;
if ( V_85 ) {
F_36 ( & V_13 -> V_15 , L_6 ) ;
return V_85 ;
}
V_14 -> V_87 [ 0 ] -> V_8 . V_9 = F_28 ( V_14 -> V_73 [ 5 ] , 0 ) ;
V_14 -> V_87 [ 1 ] -> V_8 . V_9 = F_28 ( V_14 -> V_73 [ 5 ] , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_81 * * V_82 )
{
const struct F_20 * V_83 [] =
{ & V_88 , & V_88 , & V_89 } ;
struct V_81 * V_14 ;
int V_47 , V_85 ;
* V_82 = V_14 = F_38 ( & V_13 -> V_15 , V_83 , F_39 ( V_83 ) ) ;
if ( ! V_14 ) {
F_36 ( & V_13 -> V_15 , L_7 ) ;
return - V_90 ;
}
V_85 = F_35 ( V_13 , 0x3f , V_86 ) ;
if ( V_85 ) {
F_36 ( & V_13 -> V_15 , L_8 ,
V_85 ) ;
return V_85 ;
}
V_14 -> V_73 = F_40 ( V_13 ) ;
for ( V_47 = 0 ; V_47 < V_14 -> V_91 ; V_47 ++ )
F_30 ( V_14 -> V_87 [ V_47 ] ) ;
V_85 = F_41 ( & V_13 -> V_15 , V_92 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_42 ( & V_13 -> V_15 , V_92 ) ;
if ( V_85 )
return V_85 ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 , struct V_81 * * V_82 )
{
const struct F_20 * V_83 [] = { & V_93 , NULL } ;
struct V_81 * V_14 ;
int V_47 , V_85 ;
V_85 = F_34 ( V_13 , V_83 , & V_14 ) ;
if ( V_85 )
return V_85 ;
* V_82 = V_14 ;
V_85 = F_35 ( V_13 , 1 << 5 , V_86 ) ;
if ( V_85 ) {
F_36 ( & V_13 -> V_15 , L_6 ) ;
return V_85 ;
}
for ( V_47 = 0 ; V_47 < V_14 -> V_91 ; V_47 ++ )
F_44 ( V_14 -> V_87 [ V_47 ] ) ;
return 0 ;
}
static void F_45 ( struct V_12 * V_13 )
{
T_2 V_94 ;
F_7 ( V_13 , 0x52 , & V_94 ) ;
F_12 ( V_13 , 0x52 , V_94 | F_46 ( 2 ) ) ;
}
static T_4 F_47 ( int V_95 , void * V_96 )
{
struct V_81 * V_14 = V_96 ;
T_4 V_85 = F_48 ( V_95 , V_96 ) ;
if ( V_85 != V_97 ) {
T_1 V_98 ;
unsigned long V_30 ;
F_49 ( & V_14 -> V_99 , V_30 ) ;
F_1 ( & V_14 -> V_87 [ 0 ] -> V_2 , V_22 , & V_98 ) ;
if ( V_98 & V_100 ) {
F_50 ( & V_14 -> V_87 [ 0 ] -> V_2 . V_101 ) ;
F_51 ( V_14 -> V_87 [ 0 ] ) ;
V_85 = V_97 ;
}
F_1 ( & V_14 -> V_87 [ 1 ] -> V_2 , V_22 , & V_98 ) ;
if ( V_98 & V_100 ) {
F_50 ( & V_14 -> V_87 [ 1 ] -> V_2 . V_101 ) ;
F_51 ( V_14 -> V_87 [ 1 ] ) ;
V_85 = V_97 ;
}
F_52 ( & V_14 -> V_99 , V_30 ) ;
}
return V_85 ;
}
static void F_53 ( struct V_24 * V_7 )
{
struct V_102 * V_103 = V_7 -> V_14 -> V_104 ;
struct V_12 * V_13 = F_6 ( V_7 -> V_14 -> V_15 ) ;
T_1 V_98 ;
if ( ! V_103 -> V_105 ) {
F_1 ( & V_7 -> V_2 , V_22 , & V_98 ) ;
if ( V_98 == 0x1000500 ) {
F_54 ( V_7 , L_9 ) ;
F_45 ( V_13 ) ;
V_103 -> V_105 = true ;
V_7 -> V_2 . V_37 . V_47 . V_30 |= V_106 ;
}
}
F_55 ( V_7 ) ;
}
static void F_56 ( struct V_12 * V_13 , int V_107 ,
struct V_102 * V_103 )
{
T_2 V_94 ;
F_7 ( V_13 , V_108 , & V_94 ) ;
F_57 ( & V_13 -> V_15 , L_10 ,
( int ) ( V_94 & 0xf0 ) == 0xf0 ? 0 : V_94 & 0x0f ) ;
F_7 ( V_13 , V_109 , & V_94 ) ;
if ( ( V_94 & V_110 ) != V_110 ) {
F_58 ( & V_13 -> V_15 , L_11 ,
( int ) V_94 ) ;
V_94 |= V_110 ;
F_12 ( V_13 , V_109 , V_94 ) ;
}
F_7 ( V_13 , V_111 , & V_94 ) ;
if ( ( V_94 & V_110 ) != V_110 ) {
F_58 ( & V_13 -> V_15 , L_12 ,
( int ) V_94 ) ;
V_94 |= V_110 ;
F_12 ( V_13 , V_111 , V_94 ) ;
}
F_7 ( V_13 , V_112 , & V_94 ) ;
if ( ( V_94 & V_113 ) != V_113 ) {
F_58 ( & V_13 -> V_15 ,
L_13 ,
( int ) V_94 ) ;
V_94 |= V_113 ;
F_12 ( V_13 , V_112 , V_94 ) ;
}
if ( V_107 == V_114 ) {
F_7 ( V_13 , V_115 , & V_94 ) ;
if ( ( V_94 & V_116 ) != V_116 ) {
F_58 ( & V_13 -> V_15 ,
L_14 ,
( int ) V_94 ) ;
V_94 |= V_116 ;
F_12 ( V_13 , V_115 , V_94 ) ;
}
}
if ( V_107 == V_117 ) {
F_45 ( V_13 ) ;
V_103 -> V_105 = true ;
}
}
static int F_59 ( struct V_12 * V_13 , const struct V_118 * V_119 )
{
unsigned int V_47 ;
int V_85 ;
struct V_81 * V_14 = NULL ;
int V_107 = ( int ) V_119 -> V_120 ;
const unsigned * V_121 ;
struct V_102 * V_103 ;
F_60 ( & V_13 -> V_15 , V_122 ) ;
V_85 = F_61 ( V_13 ) ;
if ( V_85 )
return V_85 ;
if ( V_107 == V_114 )
V_121 = & V_123 [ 0 ] ;
else
V_121 = & V_124 [ 0 ] ;
for ( V_47 = 0 ; V_47 < F_39 ( V_124 ) ; V_47 ++ )
if ( ( F_62 ( V_13 , V_47 ) == 0 ) ||
( F_63 ( V_13 , V_47 ) < V_121 [ V_47 ] ) ) {
F_36 ( & V_13 -> V_15 ,
L_15 ,
V_47 ,
( unsigned long long ) F_62 ( V_13 , V_47 ) ,
( unsigned long long ) F_63 ( V_13 , V_47 ) ) ;
return - V_125 ;
}
switch ( V_107 ) {
case V_117 :
V_85 = F_33 ( V_13 , & V_14 ) ;
break;
case V_114 :
V_85 = F_37 ( V_13 , & V_14 ) ;
break;
case V_126 :
V_85 = F_43 ( V_13 , & V_14 ) ;
break;
default:
V_85 = - V_6 ;
}
if ( V_85 )
return V_85 ;
V_103 = F_64 ( & V_13 -> V_15 , sizeof( * V_103 ) , V_127 ) ;
if ( ! V_103 )
return - V_90 ;
V_14 -> V_104 = V_103 ;
F_56 ( V_13 , V_107 , V_103 ) ;
F_65 ( V_13 ) ;
if ( V_107 == V_114 )
return F_66 ( V_14 , V_13 -> V_95 , F_47 ,
V_128 , & V_129 ) ;
else
return F_66 ( V_14 , V_13 -> V_95 , F_48 ,
V_128 , & V_129 ) ;
}
static int F_67 ( struct V_12 * V_13 )
{
struct V_81 * V_14 = F_68 ( V_13 ) ;
struct V_102 * V_103 = V_14 -> V_104 ;
int V_85 ;
V_85 = F_69 ( V_13 ) ;
if ( V_85 )
return V_85 ;
if ( V_103 -> V_105 )
F_45 ( V_13 ) ;
F_70 ( V_14 ) ;
return 0 ;
}
