static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
T_3 V_3 = F_2 ( V_1 + V_4 ) ;
V_3 = V_2 ? ( V_3 & ~ V_5 ) : ( V_3 | V_5 ) ;
F_3 ( V_3 , V_1 + V_4 ) ;
}
static void F_4 ( void T_1 * V_6 )
{
F_3 ( F_2 ( V_6 + V_7 ) | V_8 ,
V_6 + V_7 ) ;
}
static unsigned long
F_5 ( struct V_9 * V_10 , const struct V_11 * V_12 )
{
int V_13 = V_12 -> V_14 ;
int V_15 = V_12 -> V_16 ;
int V_17 = V_12 -> V_18 ;
T_4 V_19 ;
V_19 = ( ( V_17 & 0xff ) << 12 ) | ( ( V_15 & 0xff ) << 4 ) | ( V_13 & 0xf ) ;
return V_19 ;
}
static void F_6 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_9 * V_10 = V_21 -> V_24 -> V_25 ;
struct V_11 V_26 ;
int V_27 ;
T_4 V_28 = F_2 ( V_10 -> V_29 + V_4 ) ;
T_4 V_19 ;
if ( F_7 ( V_23 ) )
V_28 |= V_30 ;
else
V_28 &= ~ V_30 ;
V_27 = ( int ) ( 1000000000UL / F_8 ( V_10 -> V_31 ) ) ;
F_9 ( V_23 , V_23 -> V_32 , & V_26 ,
V_27 * 1000 , 0 ) ;
V_19 = F_5 ( V_10 , & V_26 ) ;
F_3 ( V_28 , V_10 -> V_29 + V_4 ) ;
F_3 ( V_19 , V_10 -> V_29 + V_33 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
T_4 V_34 ;
void T_1 * V_35 = V_10 -> V_29 + V_10 -> V_36 ;
V_34 = V_37 + F_11 ( 20 ) ;
while ( F_12 ( V_37 , V_34 ) ) {
if ( ( F_2 ( V_35 ) >> 28 ) == 0 )
return 0 ;
}
return - V_38 ;
}
static void F_13 ( struct V_39 * V_24 , T_2 V_40 , void T_1 * V_3 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
F_10 ( V_10 ) ;
F_14 ( V_40 , V_3 ) ;
}
static T_2 F_15 ( struct V_39 * V_24 , void T_1 * V_3 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
T_2 V_41 ;
F_10 ( V_10 ) ;
( void ) F_16 ( V_3 ) ;
F_10 ( V_10 ) ;
V_41 = F_16 ( V_10 -> V_29 + V_42 ) ;
return V_41 ;
}
static void F_17 ( struct V_20 * V_21 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_21 -> V_46 ;
unsigned int V_47 = V_44 -> V_48 & V_49 ;
if ( V_44 -> V_50 != V_21 -> V_51 ) {
F_13 ( V_21 -> V_24 , V_44 -> V_50 , V_46 -> V_52 ) ;
V_21 -> V_51 = V_44 -> V_50 ;
F_18 ( V_21 ) ;
}
if ( V_47 && ( V_44 -> V_48 & V_53 ) ) {
F_13 ( V_21 -> V_24 , V_44 -> V_54 , V_46 -> V_55 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_56 , V_46 -> V_57 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_58 , V_46 -> V_59 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_60 , V_46 -> V_61 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_62 , V_46 -> V_63 ) ;
}
if ( V_47 ) {
F_13 ( V_21 -> V_24 , V_44 -> V_64 , V_46 -> V_55 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_65 , V_46 -> V_57 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_66 , V_46 -> V_59 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_67 , V_46 -> V_61 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_68 , V_46 -> V_63 ) ;
}
if ( V_44 -> V_48 & V_69 )
F_13 ( V_21 -> V_24 , V_44 -> V_70 , V_46 -> V_71 ) ;
F_18 ( V_21 ) ;
}
static void F_19 ( struct V_20 * V_21 , struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_21 -> V_46 ;
V_44 -> V_64 = F_15 ( V_21 -> V_24 , V_46 -> V_72 ) ;
V_44 -> V_65 = F_15 ( V_21 -> V_24 , V_46 -> V_57 ) ;
V_44 -> V_66 = F_15 ( V_21 -> V_24 , V_46 -> V_59 ) ;
V_44 -> V_67 = F_15 ( V_21 -> V_24 , V_46 -> V_61 ) ;
V_44 -> V_68 = F_15 ( V_21 -> V_24 , V_46 -> V_63 ) ;
V_44 -> V_70 = F_15 ( V_21 -> V_24 , V_46 -> V_71 ) ;
if ( V_44 -> V_48 & V_53 ) {
F_13 ( V_21 -> V_24 , V_44 -> V_50 | V_73 , V_46 -> V_52 ) ;
V_44 -> V_54 = F_15 ( V_21 -> V_24 , V_46 -> V_72 ) ;
V_44 -> V_56 = F_15 ( V_21 -> V_24 , V_46 -> V_57 ) ;
V_44 -> V_58 = F_15 ( V_21 -> V_24 , V_46 -> V_59 ) ;
V_44 -> V_60 = F_15 ( V_21 -> V_24 , V_46 -> V_61 ) ;
V_44 -> V_62 = F_15 ( V_21 -> V_24 , V_46 -> V_63 ) ;
F_13 ( V_21 -> V_24 , V_44 -> V_50 , V_46 -> V_52 ) ;
V_21 -> V_51 = V_44 -> V_50 ;
}
}
static void F_20 ( struct V_20 * V_21 ,
const struct V_43 * V_44 )
{
F_13 ( V_21 -> V_24 , V_44 -> V_74 , V_21 -> V_46 . V_75 ) ;
F_21 ( V_21 ) ;
}
static T_2 F_22 ( struct V_20 * V_21 )
{
return F_15 ( V_21 -> V_24 , V_21 -> V_46 . V_76 ) ;
}
static T_2 F_23 ( struct V_20 * V_21 )
{
return F_15 ( V_21 -> V_24 , V_21 -> V_46 . V_77 ) ;
}
static unsigned int F_24 ( struct V_22 * V_78 ,
unsigned char * V_79 , unsigned int V_80 , int V_81 )
{
struct V_20 * V_21 = V_78 -> V_82 -> V_21 ;
struct V_9 * V_10 = V_21 -> V_24 -> V_25 ;
void T_1 * V_83 = V_21 -> V_46 . V_83 ;
unsigned int V_84 = V_80 >> 1 , V_85 ;
T_5 * V_86 = ( T_5 * ) V_79 ;
if ( V_81 == V_87 )
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ , V_86 ++ ) {
F_10 ( V_10 ) ;
( void ) F_25 ( V_83 ) ;
F_10 ( V_10 ) ;
* V_86 = F_25 ( V_10 -> V_29
+ V_42 ) ;
}
else
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ , V_86 ++ ) {
F_10 ( V_10 ) ;
F_26 ( * V_86 , V_83 ) ;
}
if ( V_80 & 0x01 )
F_27 ( V_21 -> V_78 , L_1 ) ;
return V_84 << 1 ;
}
static void F_28 ( struct V_20 * V_21 , unsigned int V_70 )
{
T_2 V_88 = V_89 ;
if ( V_70 != 0 )
V_88 |= V_90 ;
F_13 ( V_21 -> V_24 , V_88 , V_21 -> V_46 . V_71 ) ;
F_21 ( V_21 ) ;
}
static unsigned int F_29 ( struct V_20 * V_21 ,
unsigned int V_70 )
{
struct V_45 * V_46 = & V_21 -> V_46 ;
T_2 V_65 , V_66 ;
F_28 ( V_21 , V_70 ) ;
F_13 ( V_21 -> V_24 , 0x55 , V_46 -> V_57 ) ;
F_13 ( V_21 -> V_24 , 0xaa , V_46 -> V_59 ) ;
F_13 ( V_21 -> V_24 , 0xaa , V_46 -> V_57 ) ;
F_13 ( V_21 -> V_24 , 0x55 , V_46 -> V_59 ) ;
F_13 ( V_21 -> V_24 , 0x55 , V_46 -> V_57 ) ;
F_13 ( V_21 -> V_24 , 0xaa , V_46 -> V_59 ) ;
V_65 = F_15 ( V_21 -> V_24 , V_46 -> V_57 ) ;
V_66 = F_15 ( V_21 -> V_24 , V_46 -> V_59 ) ;
if ( ( V_65 == 0x55 ) && ( V_66 == 0xaa ) )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_91 * V_82 ,
unsigned long V_92 )
{
int V_93 ;
F_31 ( V_82 -> V_21 , V_94 ) ;
V_93 = F_32 ( V_82 , V_92 ) ;
if ( V_93 )
return V_93 ;
return 0 ;
}
static int F_33 ( struct V_20 * V_21 ,
unsigned long V_92 )
{
struct V_45 * V_46 = & V_21 -> V_46 ;
F_13 ( V_21 -> V_24 , V_21 -> V_50 , V_46 -> V_52 ) ;
F_34 ( 20 ) ;
F_13 ( V_21 -> V_24 , V_21 -> V_50 | V_95 , V_46 -> V_52 ) ;
F_34 ( 20 ) ;
F_13 ( V_21 -> V_24 , V_21 -> V_50 , V_46 -> V_52 ) ;
V_21 -> V_51 = V_21 -> V_50 ;
return F_30 ( & V_21 -> V_82 , V_92 ) ;
}
static int F_35 ( struct V_91 * V_82 , unsigned int * V_96 ,
unsigned long V_92 )
{
struct V_20 * V_21 = V_82 -> V_21 ;
unsigned int V_97 = 0 ;
int V_93 ;
T_2 V_98 ;
if ( F_29 ( V_21 , 0 ) )
V_97 |= ( 1 << 0 ) ;
F_28 ( V_21 , 0 ) ;
V_93 = F_33 ( V_21 , V_92 ) ;
if ( V_93 && V_93 != - V_99 ) {
F_36 ( V_82 , L_2 , V_93 ) ;
return V_93 ;
}
V_96 [ 0 ] = F_37 ( & V_21 -> V_82 . V_70 [ 0 ] ,
V_97 & ( 1 << 0 ) , & V_98 ) ;
return 0 ;
}
static void F_38 ( struct V_20 * V_21 , T_2 V_50 )
{
F_13 ( V_21 -> V_24 , V_50 , V_21 -> V_46 . V_52 ) ;
}
static void F_39 ( void T_1 * V_1 , bool V_100 )
{
T_3 V_41 = F_2 ( V_1 + V_101 ) ;
V_41 = V_100 ? ( V_41 | 1 ) : ( V_41 & ~ 1 ) ;
F_3 ( V_41 , V_1 + V_101 ) ;
}
static T_6 F_40 ( int V_102 , void * V_103 )
{
struct V_39 * V_24 = V_103 ;
struct V_9 * V_10 = V_24 -> V_25 ;
T_3 V_3 ;
V_3 = F_2 ( V_10 -> V_29 + V_104 ) ;
F_3 ( V_3 , V_10 -> V_29 + V_104 ) ;
return F_41 ( V_102 , V_103 ) ;
}
static void F_42 ( struct V_9 * V_10 ,
struct V_105 * V_106 )
{
switch ( V_10 -> V_107 ) {
case V_108 :
F_4 ( V_10 -> V_109 ) ;
F_1 ( V_10 -> V_29 , 1 ) ;
F_39 ( V_10 -> V_29 , true ) ;
F_43 ( 100 ) ;
F_3 ( 0x1f , V_10 -> V_29 + V_104 ) ;
F_3 ( 0x1b , V_10 -> V_29 + V_110 ) ;
break;
case V_111 :
F_1 ( V_10 -> V_29 , 0 ) ;
F_39 ( V_10 -> V_29 , true ) ;
F_43 ( 100 ) ;
F_3 ( 0x3f , V_10 -> V_29 + V_104 ) ;
F_3 ( 0x3f , V_10 -> V_29 + V_110 ) ;
break;
default:
F_44 () ;
}
}
static int T_7 F_45 ( struct V_112 * V_113 )
{
struct V_105 * V_106 = F_46 ( & V_113 -> V_78 ) ;
struct V_70 * V_78 = & V_113 -> V_78 ;
struct V_9 * V_10 ;
struct V_114 * V_115 ;
struct V_20 * V_21 ;
struct V_39 * V_24 ;
enum V_116 V_107 ;
int V_117 ;
V_107 = F_47 ( V_113 ) -> V_118 ;
V_10 = F_48 ( V_78 , sizeof( * V_10 ) , V_119 ) ;
if ( ! V_10 ) {
F_27 ( V_78 , L_3 ) ;
return - V_120 ;
}
V_10 -> V_102 = F_49 ( V_113 , 0 ) ;
V_115 = F_50 ( V_113 , V_121 , 0 ) ;
V_10 -> V_29 = F_51 ( V_78 , V_115 ) ;
if ( F_52 ( V_10 -> V_29 ) )
return F_53 ( V_10 -> V_29 ) ;
V_10 -> V_31 = F_54 ( & V_113 -> V_78 , L_4 ) ;
if ( F_52 ( V_10 -> V_31 ) ) {
F_27 ( V_78 , L_5 ) ;
V_117 = F_53 ( V_10 -> V_31 ) ;
V_10 -> V_31 = NULL ;
return V_117 ;
}
F_55 ( V_10 -> V_31 ) ;
V_24 = F_56 ( V_78 , 1 ) ;
if ( ! V_24 ) {
F_27 ( V_78 , L_6 ) ;
V_117 = - V_120 ;
goto V_122;
}
V_21 = V_24 -> V_123 [ 0 ] ;
V_21 -> V_124 = V_125 ;
if ( V_107 == V_108 ) {
V_21 -> V_126 = & V_127 ;
V_10 -> V_109 = V_10 -> V_29 + 0x1800 ;
V_10 -> V_29 += 0x1900 ;
V_10 -> V_36 = 0x94 ;
} else {
V_21 -> V_126 = & V_128 ;
V_10 -> V_36 = 0x84 ;
}
V_10 -> V_107 = V_107 ;
if ( V_10 -> V_102 <= 0 ) {
V_21 -> V_48 |= V_129 ;
V_10 -> V_102 = 0 ;
F_57 ( V_21 , L_7 ) ;
}
V_21 -> V_46 . V_130 = V_10 -> V_29 + V_131 ;
V_21 -> V_46 . V_83 = V_10 -> V_29 + V_132 ;
V_21 -> V_46 . V_72 = V_10 -> V_29 + V_133 ;
V_21 -> V_46 . V_55 = V_10 -> V_29 + V_133 ;
V_21 -> V_46 . V_57 = V_10 -> V_29 + V_134 ;
V_21 -> V_46 . V_59 = V_10 -> V_29 + V_135 ;
V_21 -> V_46 . V_61 = V_10 -> V_29 + V_136 ;
V_21 -> V_46 . V_63 = V_10 -> V_29 + V_137 ;
V_21 -> V_46 . V_71 = V_10 -> V_29 + V_138 ;
V_21 -> V_46 . V_76 = V_10 -> V_29 + V_139 ;
V_21 -> V_46 . V_75 = V_10 -> V_29 + V_139 ;
V_21 -> V_46 . V_77 = V_10 -> V_29 + V_140 ;
V_21 -> V_46 . V_52 = V_10 -> V_29 + V_140 ;
F_57 ( V_21 , L_8 ,
( unsigned long long ) V_115 -> V_141 ) ;
V_24 -> V_25 = V_10 ;
if ( V_106 && V_106 -> V_142 )
V_106 -> V_142 () ;
F_42 ( V_10 , V_106 ) ;
F_58 ( V_113 , V_24 ) ;
V_117 = F_59 ( V_24 , V_10 -> V_102 ,
V_10 -> V_102 ? F_40 : NULL ,
0 , & V_143 ) ;
if ( V_117 )
goto V_122;
return 0 ;
V_122:
F_60 ( V_10 -> V_31 ) ;
return V_117 ;
}
static int T_8 F_61 ( struct V_112 * V_113 )
{
struct V_39 * V_24 = F_62 ( V_113 ) ;
struct V_9 * V_10 = V_24 -> V_25 ;
F_63 ( V_24 ) ;
F_60 ( V_10 -> V_31 ) ;
return 0 ;
}
static int F_64 ( struct V_70 * V_78 )
{
struct V_112 * V_113 = F_65 ( V_78 ) ;
struct V_39 * V_24 = F_62 ( V_113 ) ;
return F_66 ( V_24 , V_144 ) ;
}
static int F_67 ( struct V_70 * V_78 )
{
struct V_112 * V_113 = F_65 ( V_78 ) ;
struct V_39 * V_24 = F_62 ( V_113 ) ;
struct V_105 * V_106 = F_46 ( & V_113 -> V_78 ) ;
struct V_9 * V_10 = V_24 -> V_25 ;
F_42 ( V_10 , V_106 ) ;
F_68 ( V_24 ) ;
return 0 ;
}
