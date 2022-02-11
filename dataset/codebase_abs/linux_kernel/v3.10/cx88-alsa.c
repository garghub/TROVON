static int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = V_1 -> V_5 ;
const struct V_6 * V_7 = & V_8 [ V_9 ] ;
F_2 ( V_10 , 0x11 ) ;
F_3 ( V_1 -> V_5 , V_7 , V_3 -> V_11 , V_3 -> V_12 . V_13 ) ;
F_4 ( V_14 , V_3 -> V_11 ) ;
F_4 ( V_15 , V_16 ) ;
F_5 ( & V_1 -> V_17 , 0 ) ;
F_6 ( 1 , L_1
L_2 , V_3 -> V_11 , F_7 ( V_7 -> V_18 + 8 ) >> 1 ,
V_1 -> V_19 , V_3 -> V_11 * V_1 -> V_19 ) ;
F_4 ( V_20 , V_21 | V_22 |
V_23 | V_24 ) ;
F_4 ( V_25 , ~ 0 ) ;
F_8 ( V_26 , V_1 -> V_5 -> V_27 | V_28 ) ;
F_8 ( V_29 , ( 1 << 5 ) ) ;
F_8 ( V_10 , 0x11 ) ;
if ( V_30 )
F_9 ( V_1 -> V_5 , V_7 ) ;
return 0 ;
}
static int F_10 ( T_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_6 ( 1 , L_3 ) ;
F_2 ( V_10 , 0x11 ) ;
F_2 ( V_26 , V_28 ) ;
F_2 ( V_20 , V_21 | V_22 |
V_23 | V_24 ) ;
if ( V_30 )
F_9 ( V_1 -> V_5 , & V_8 [ V_9 ] ) ;
return 0 ;
}
static void F_11 ( T_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_31 , V_32 ;
V_31 = F_7 ( V_25 ) ;
V_32 = F_7 ( V_20 ) ;
if ( 0 == ( V_31 & V_32 ) )
return;
F_4 ( V_25 , V_31 ) ;
if ( V_30 > 1 || ( V_31 & V_32 & ~ 0xff ) )
F_12 ( V_5 -> V_33 , L_4 ,
V_34 , F_13 ( V_34 ) ,
V_31 , V_32 ) ;
if ( V_31 & V_21 ) {
F_14 ( V_35 L_5 , V_5 -> V_33 ) ;
F_2 ( V_10 , 0x11 ) ;
F_9 ( V_5 , & V_8 [ V_9 ] ) ;
}
if ( V_31 & V_22 ) {
F_6 ( 1 , L_6 ) ;
F_4 ( V_15 , V_16 ) ;
return;
}
if ( V_31 & V_24 ) {
F_5 ( & V_1 -> V_17 , F_7 ( V_36 ) ) ;
F_15 ( V_1 -> V_37 ) ;
}
}
static T_3 F_16 ( int V_38 , void * V_39 )
{
T_1 * V_1 = V_39 ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_31 ;
int V_40 , V_41 = 0 ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ ) {
V_31 = F_7 ( V_43 ) &
( V_5 -> V_27 | V_28 ) ;
if ( 0 == V_31 )
goto V_44;
F_6 ( 3 , L_7 ,
V_40 , V_42 , V_31 ) ;
V_41 = 1 ;
F_4 ( V_43 , V_31 ) ;
if ( V_31 & V_5 -> V_27 )
F_17 ( V_5 , V_31 ) ;
if ( V_31 & V_28 )
F_11 ( V_1 ) ;
}
if ( V_42 == V_40 ) {
F_14 ( V_45
L_8 ,
V_5 -> V_33 ) ;
F_2 ( V_26 , V_28 ) ;
}
V_44:
return F_18 ( V_41 ) ;
}
static int F_19 ( T_1 * V_1 )
{
F_20 ( ! V_1 -> V_46 ) ;
F_6 ( 2 , L_9 ) ;
F_21 ( & V_1 -> V_47 -> V_48 , V_1 -> V_49 ) ;
F_22 ( V_1 -> V_49 ) ;
F_23 ( V_1 -> V_47 , & V_1 -> V_3 -> V_12 ) ;
F_24 ( V_1 -> V_3 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_46 = 0 ;
return 0 ;
}
static int F_25 ( struct V_50 * V_37 )
{
T_1 * V_1 = F_26 ( V_37 ) ;
struct V_51 * V_52 = V_37 -> V_52 ;
int V_53 ;
if ( ! V_1 ) {
F_14 ( V_45 L_10
L_11 ) ;
return - V_54 ;
}
V_53 = F_27 ( V_52 , 0 , V_55 ) ;
if ( V_53 < 0 )
goto V_56;
V_1 -> V_37 = V_37 ;
V_52 -> V_57 = V_58 ;
if ( V_8 [ V_9 ] . V_59 != V_60 ) {
unsigned int V_11 = V_8 [ V_9 ] . V_59 / 4 ;
V_11 &= ~ 7 ;
V_52 -> V_57 . V_61 = V_11 ;
V_52 -> V_57 . V_62 = V_11 ;
}
return 0 ;
V_56:
F_6 ( 1 , L_12 ) ;
return V_53 ;
}
static int F_28 ( struct V_50 * V_37 )
{
return 0 ;
}
static int F_29 ( struct V_50 * V_37 ,
struct V_63 * V_64 )
{
T_1 * V_1 = F_26 ( V_37 ) ;
struct V_65 * V_13 ;
struct V_2 * V_3 ;
int V_66 ;
if ( V_37 -> V_52 -> V_67 ) {
F_19 ( V_1 ) ;
V_37 -> V_52 -> V_67 = NULL ;
}
V_1 -> V_68 = F_30 ( V_64 ) ;
V_1 -> V_19 = F_31 ( V_64 ) ;
V_1 -> V_46 = V_1 -> V_68 * F_31 ( V_64 ) ;
F_20 ( ! V_1 -> V_46 ) ;
F_20 ( V_1 -> V_19 & ( V_1 -> V_19 - 1 ) ) ;
V_3 = F_32 ( sizeof( * V_3 ) , V_69 ) ;
if ( NULL == V_3 )
return - V_70 ;
V_3 -> V_11 = V_1 -> V_68 ;
V_13 = & V_3 -> V_13 ;
F_33 ( V_13 ) ;
V_66 = F_34 ( V_13 , V_71 ,
( F_35 ( V_1 -> V_46 ) >> V_72 ) ) ;
if ( V_66 < 0 )
goto error;
V_66 = F_36 ( & V_1 -> V_47 -> V_48 , V_13 ) ;
if ( V_66 < 0 )
goto error;
V_66 = F_37 ( V_1 -> V_47 , & V_3 -> V_12 , V_13 -> V_73 ,
V_1 -> V_68 , V_1 -> V_19 , 1 ) ;
if ( V_66 < 0 )
goto error;
V_3 -> V_12 . V_74 [ 0 ] = F_38 ( V_75 | V_76 | V_77 ) ;
V_3 -> V_12 . V_74 [ 1 ] = F_38 ( V_3 -> V_12 . V_13 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_49 = V_13 ;
V_37 -> V_52 -> V_67 = V_1 -> V_49 -> V_78 ;
V_37 -> V_52 -> V_79 = V_1 -> V_46 ;
V_37 -> V_52 -> V_80 = 0 ;
return 0 ;
error:
F_24 ( V_3 ) ;
return V_66 ;
}
static int F_39 ( struct V_50 * V_37 )
{
T_1 * V_1 = F_26 ( V_37 ) ;
if ( V_37 -> V_52 -> V_67 ) {
F_19 ( V_1 ) ;
V_37 -> V_52 -> V_67 = NULL ;
}
return 0 ;
}
static int F_40 ( struct V_50 * V_37 )
{
return 0 ;
}
static int F_41 ( struct V_50 * V_37 , int V_81 )
{
T_1 * V_1 = F_26 ( V_37 ) ;
int V_53 ;
F_42 ( & V_1 -> V_82 ) ;
switch ( V_81 ) {
case V_83 :
V_53 = F_1 ( V_1 ) ;
break;
case V_84 :
V_53 = F_10 ( V_1 ) ;
break;
default:
V_53 = - V_85 ;
break;
}
F_43 ( & V_1 -> V_82 ) ;
return V_53 ;
}
static T_4 F_44 ( struct V_50 * V_37 )
{
T_1 * V_1 = F_26 ( V_37 ) ;
struct V_51 * V_52 = V_37 -> V_52 ;
T_5 V_17 ;
V_17 = F_45 ( & V_1 -> V_17 ) ;
return V_52 -> V_68 * ( V_17 & ( V_52 -> V_86 - 1 ) ) ;
}
static struct V_87 * F_46 ( struct V_50 * V_37 ,
unsigned long V_88 )
{
void * V_89 = V_37 -> V_52 -> V_67 + V_88 ;
return F_47 ( V_89 ) ;
}
static int F_48 ( T_1 * V_1 , int V_90 , const char * V_33 )
{
int V_53 ;
struct V_91 * V_92 ;
V_53 = F_49 ( V_1 -> V_93 , V_33 , V_90 , 0 , 1 , & V_92 ) ;
if ( V_53 < 0 )
return V_53 ;
V_92 -> V_94 = V_1 ;
strcpy ( V_92 -> V_33 , V_33 ) ;
F_50 ( V_92 , V_95 , & V_96 ) ;
return 0 ;
}
static int F_51 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
V_100 -> type = V_101 ;
V_100 -> V_17 = 2 ;
V_100 -> V_102 . integer . V_103 = 0 ;
V_100 -> V_102 . integer . V_104 = 0x3f ;
return 0 ;
}
static int F_52 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_106 = 0x3f - ( F_7 ( V_107 ) & 0x3f ) ,
V_108 = F_7 ( V_109 ) ;
V_102 -> V_102 . integer . V_102 [ ( V_108 & 0x40 ) ? 0 : 1 ] = V_106 ;
V_106 -= ( V_108 & 0x3f ) ;
V_102 -> V_102 . integer . V_102 [ ( V_108 & 0x40 ) ? 1 : 0 ] = V_106 < 0 ? 0 : V_106 ;
return 0 ;
}
static void F_54 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_110 = V_102 -> V_102 . integer . V_102 [ 0 ] ;
int V_111 = V_102 -> V_102 . integer . V_102 [ 1 ] ;
int V_112 , V_113 ;
if ( V_110 >= V_111 ) {
V_112 = V_110 << 10 ;
V_113 = V_110 ? ( 0x8000 * V_111 ) / V_110 : 0x8000 ;
} else {
V_112 = V_111 << 10 ;
V_113 = V_111 ? 0xffff - ( 0x8000 * V_110 ) / V_111 : 0x8000 ;
}
F_55 ( V_5 , V_114 , V_112 ) ;
F_55 ( V_5 , V_115 , V_113 ) ;
}
static int F_56 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_110 , V_111 , V_112 , V_113 ;
int V_116 = 0 ;
T_2 V_117 ;
if ( V_5 -> V_118 )
F_54 ( V_98 , V_102 ) ;
V_110 = V_102 -> V_102 . integer . V_102 [ 0 ] & 0x3f ;
V_111 = V_102 -> V_102 . integer . V_102 [ 1 ] & 0x3f ;
V_113 = V_111 - V_110 ;
if ( V_113 < 0 ) {
V_112 = 0x3f - V_110 ;
V_113 = ( - V_113 ) | 0x40 ;
} else {
V_112 = 0x3f - V_111 ;
}
F_57 ( & V_1 -> V_82 ) ;
V_117 = F_7 ( V_107 ) ;
if ( V_112 != ( V_117 & 0x3f ) ) {
F_58 ( V_119 , V_107 , ( V_117 & ~ 0x3f ) | V_112 ) ;
V_116 = 1 ;
}
if ( ( F_7 ( V_109 ) & 0x7f ) != V_113 ) {
F_4 ( V_109 , V_113 ) ;
V_116 = 1 ;
}
F_59 ( & V_1 -> V_82 ) ;
return V_116 ;
}
static int F_60 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_120 = V_98 -> V_121 ;
V_102 -> V_102 . integer . V_102 [ 0 ] = ! ( F_7 ( V_107 ) & V_120 ) ;
return 0 ;
}
static int F_61 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_120 = V_98 -> V_121 ;
int V_66 = 0 ;
T_2 V_106 ;
F_57 ( & V_1 -> V_82 ) ;
V_106 = F_7 ( V_107 ) ;
if ( V_102 -> V_102 . integer . V_102 [ 0 ] != ! ( V_106 & V_120 ) ) {
V_106 ^= V_120 ;
F_58 ( V_119 , V_107 , V_106 ) ;
if ( V_5 -> V_118 && ( ( 1 << 6 ) == V_120 ) )
F_55 ( V_5 , V_122 , 0 != ( V_106 & V_120 ) ) ;
V_66 = 1 ;
}
F_59 ( & V_1 -> V_82 ) ;
return V_66 ;
}
static int F_62 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_6 V_123 ;
V_123 = F_63 ( V_5 , V_124 ) ;
V_102 -> V_102 . integer . V_102 [ 0 ] = V_123 ? 1 : 0 ;
return 0 ;
}
static int F_64 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_125 V_126 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_102 = 0 != V_102 -> V_102 . integer . V_102 [ 0 ] ;
V_126 . V_127 = V_124 ;
F_65 ( V_5 , V_128 , V_5 , V_129 , & V_126 ) ;
return 0 ;
}
static int F_66 ( T_1 * V_1 )
{
if ( V_1 -> V_38 >= 0 )
F_67 ( V_1 -> V_38 , V_1 ) ;
F_68 ( V_1 -> V_5 , V_1 -> V_47 ) ;
F_69 ( V_1 -> V_47 ) ;
return 0 ;
}
static void F_70 ( struct V_130 * V_93 )
{
T_1 * V_1 = V_93 -> V_94 ;
F_66 ( V_1 ) ;
}
static int F_71 ( struct V_130 * V_93 , struct V_131 * V_47 ,
T_1 * * V_132 ,
struct V_4 * * V_133 )
{
T_1 * V_1 ;
struct V_4 * V_5 ;
int V_53 ;
unsigned char V_134 ;
* V_132 = NULL ;
V_53 = F_72 ( V_47 ) ;
if ( V_53 < 0 )
return V_53 ;
F_73 ( V_47 ) ;
V_1 = V_93 -> V_94 ;
V_5 = F_74 ( V_47 ) ;
if ( NULL == V_5 ) {
V_53 = - V_85 ;
return V_53 ;
}
if ( ! F_75 ( V_47 , F_76 ( 32 ) ) ) {
F_6 ( 0 , L_13 , V_5 -> V_33 ) ;
V_53 = - V_135 ;
F_68 ( V_5 , V_47 ) ;
return V_53 ;
}
V_1 -> V_93 = V_93 ;
V_1 -> V_47 = V_47 ;
V_1 -> V_38 = - 1 ;
F_77 ( & V_1 -> V_82 ) ;
V_1 -> V_5 = V_5 ;
V_53 = F_78 ( V_1 -> V_47 -> V_38 , F_16 ,
V_136 | V_137 , V_1 -> V_5 -> V_33 , V_1 ) ;
if ( V_53 < 0 ) {
F_6 ( 0 , L_14 ,
V_1 -> V_5 -> V_33 , V_1 -> V_47 -> V_38 ) ;
return V_53 ;
}
F_79 ( V_47 , V_138 , & V_134 ) ;
F_6 ( 1 , L_15
L_16 , V_5 -> V_33 , V_139 ,
F_80 ( V_47 ) , V_47 -> V_140 , V_47 -> V_38 ,
V_134 , ( unsigned long long ) F_81 ( V_47 , 0 ) ) ;
V_1 -> V_38 = V_47 -> V_38 ;
F_82 ( V_1 -> V_38 ) ;
F_83 ( V_93 , & V_47 -> V_48 ) ;
* V_132 = V_1 ;
* V_133 = V_5 ;
return 0 ;
}
static int F_84 ( struct V_131 * V_47 ,
const struct V_141 * V_142 )
{
struct V_130 * V_93 ;
T_1 * V_1 ;
struct V_4 * V_5 = NULL ;
int V_53 ;
if ( V_139 >= V_143 )
return ( - V_54 ) ;
if ( ! V_144 [ V_139 ] ) {
++ V_139 ;
return ( - V_145 ) ;
}
V_53 = F_85 ( V_146 [ V_139 ] , V_127 [ V_139 ] , V_147 ,
sizeof( T_1 ) , & V_93 ) ;
if ( V_53 < 0 )
return V_53 ;
V_93 -> V_148 = F_70 ;
V_53 = F_71 ( V_93 , V_47 , & V_1 , & V_5 ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_48 ( V_1 , 0 , L_17 ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_86 ( V_93 , F_87 ( & V_149 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_86 ( V_93 , F_87 ( & V_150 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_86 ( V_93 , F_87 ( & V_151 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
if ( V_5 -> V_118 )
F_86 ( V_93 , F_87 ( & V_152 , V_1 ) ) ;
strcpy ( V_93 -> V_153 , L_18 ) ;
sprintf ( V_93 -> V_154 , L_19 , V_47 -> V_90 ) ;
sprintf ( V_93 -> V_155 , L_20 ,
V_93 -> V_154 , ( unsigned long long ) F_81 ( V_47 , 0 ) ) ;
strcpy ( V_93 -> V_156 , L_21 ) ;
F_6 ( 0 , L_22 ,
V_93 -> V_153 , V_139 ) ;
V_53 = F_88 ( V_93 ) ;
if ( V_53 < 0 )
goto error;
F_89 ( V_47 , V_93 ) ;
V_139 ++ ;
return 0 ;
error:
F_90 ( V_93 ) ;
return V_53 ;
}
static void F_91 ( struct V_131 * V_47 )
{
struct V_157 * V_93 = F_92 ( V_47 ) ;
F_90 ( ( void * ) V_93 ) ;
F_89 ( V_47 , NULL ) ;
V_139 -- ;
}
static int T_7 F_93 ( void )
{
F_14 ( V_158 L_23 ,
V_159 ) ;
return F_94 ( & V_160 ) ;
}
static void T_8 F_95 ( void )
{
F_96 ( & V_160 ) ;
}
