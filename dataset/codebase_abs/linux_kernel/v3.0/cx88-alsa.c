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
static int T_6 F_48 ( T_1 * V_1 , int V_90 , const char * V_33 )
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
struct V_110 V_111 ;
int V_112 = V_102 -> V_102 . integer . V_102 [ 0 ] ;
int V_113 = V_102 -> V_102 . integer . V_102 [ 1 ] ;
int V_114 , V_115 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
if ( V_112 >= V_113 ) {
V_114 = V_112 << 10 ;
V_115 = V_112 ? ( 0x8000 * V_113 ) / V_112 : 0x8000 ;
} else {
V_114 = V_113 << 10 ;
V_115 = V_113 ? 0xffff - ( 0x8000 * V_112 ) / V_113 : 0x8000 ;
}
V_111 . V_102 = V_114 ;
V_111 . V_116 = V_117 ;
F_55 ( V_5 , V_118 , V_5 , V_119 , & V_111 ) ;
V_111 . V_102 = V_115 ;
V_111 . V_116 = V_120 ;
F_55 ( V_5 , V_118 , V_5 , V_119 , & V_111 ) ;
}
static int F_56 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_112 , V_113 , V_114 , V_115 ;
int V_121 = 0 ;
T_2 V_122 ;
if ( V_5 -> V_123 . V_124 == V_125 )
F_54 ( V_98 , V_102 ) ;
V_112 = V_102 -> V_102 . integer . V_102 [ 0 ] & 0x3f ;
V_113 = V_102 -> V_102 . integer . V_102 [ 1 ] & 0x3f ;
V_115 = V_113 - V_112 ;
if ( V_115 < 0 ) {
V_114 = 0x3f - V_112 ;
V_115 = ( - V_115 ) | 0x40 ;
} else {
V_114 = 0x3f - V_113 ;
}
F_57 ( & V_1 -> V_82 ) ;
V_122 = F_7 ( V_107 ) ;
if ( V_114 != ( V_122 & 0x3f ) ) {
F_58 ( V_126 , V_107 , ( V_122 & ~ 0x3f ) | V_114 ) ;
V_121 = 1 ;
}
if ( ( F_7 ( V_109 ) & 0x7f ) != V_115 ) {
F_4 ( V_109 , V_115 ) ;
V_121 = 1 ;
}
F_59 ( & V_1 -> V_82 ) ;
return V_121 ;
}
static int F_60 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_127 = V_98 -> V_128 ;
V_102 -> V_102 . integer . V_102 [ 0 ] = ! ( F_7 ( V_107 ) & V_127 ) ;
return 0 ;
}
static int F_61 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_127 = V_98 -> V_128 ;
int V_66 = 0 ;
T_2 V_106 ;
F_57 ( & V_1 -> V_82 ) ;
V_106 = F_7 ( V_107 ) ;
if ( V_102 -> V_102 . integer . V_102 [ 0 ] != ! ( V_106 & V_127 ) ) {
V_106 ^= V_127 ;
F_58 ( V_126 , V_107 , V_106 ) ;
if ( ( V_5 -> V_123 . V_124 == V_125 ) &&
( ( 1 << 6 ) == V_127 ) ) {
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_102 = 0 != ( V_106 & V_127 ) ;
V_111 . V_116 = V_129 ;
F_55 ( V_5 , V_118 , V_5 , V_119 , & V_111 ) ;
}
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
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_116 = V_130 ;
F_55 ( V_5 , V_118 , V_5 , V_131 , & V_111 ) ;
V_102 -> V_102 . integer . V_102 [ 0 ] = V_111 . V_102 ? 1 : 0 ;
return 0 ;
}
static int F_63 ( struct V_97 * V_98 ,
struct V_105 * V_102 )
{
T_1 * V_1 = F_53 ( V_98 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_102 = 0 != V_102 -> V_102 . integer . V_102 [ 0 ] ;
V_111 . V_116 = V_130 ;
F_55 ( V_5 , V_118 , V_5 , V_119 , & V_111 ) ;
return 0 ;
}
static int F_64 ( T_1 * V_1 )
{
if ( V_1 -> V_38 >= 0 )
F_65 ( V_1 -> V_38 , V_1 ) ;
F_66 ( V_1 -> V_5 , V_1 -> V_47 ) ;
F_67 ( V_1 -> V_47 ) ;
return 0 ;
}
static void F_68 ( struct V_132 * V_93 )
{
T_1 * V_1 = V_93 -> V_94 ;
F_64 ( V_1 ) ;
}
static int T_6 F_69 ( struct V_132 * V_93 ,
struct V_133 * V_47 ,
T_1 * * V_134 ,
struct V_4 * * V_135 )
{
T_1 * V_1 ;
struct V_4 * V_5 ;
int V_53 ;
unsigned char V_136 ;
* V_134 = NULL ;
V_53 = F_70 ( V_47 ) ;
if ( V_53 < 0 )
return V_53 ;
F_71 ( V_47 ) ;
V_1 = V_93 -> V_94 ;
V_5 = F_72 ( V_47 ) ;
if ( NULL == V_5 ) {
V_53 = - V_85 ;
return V_53 ;
}
if ( ! F_73 ( V_47 , F_74 ( 32 ) ) ) {
F_6 ( 0 , L_13 , V_5 -> V_33 ) ;
V_53 = - V_137 ;
F_66 ( V_5 , V_47 ) ;
return V_53 ;
}
V_1 -> V_93 = V_93 ;
V_1 -> V_47 = V_47 ;
V_1 -> V_38 = - 1 ;
F_75 ( & V_1 -> V_82 ) ;
V_1 -> V_5 = V_5 ;
V_53 = F_76 ( V_1 -> V_47 -> V_38 , F_16 ,
V_138 | V_139 , V_1 -> V_5 -> V_33 , V_1 ) ;
if ( V_53 < 0 ) {
F_6 ( 0 , L_14 ,
V_1 -> V_5 -> V_33 , V_1 -> V_47 -> V_38 ) ;
return V_53 ;
}
F_77 ( V_47 , V_140 , & V_136 ) ;
F_6 ( 1 , L_15
L_16 , V_5 -> V_33 , V_141 ,
F_78 ( V_47 ) , V_47 -> V_142 , V_47 -> V_38 ,
V_136 , ( unsigned long long ) F_79 ( V_47 , 0 ) ) ;
V_1 -> V_38 = V_47 -> V_38 ;
F_80 ( V_1 -> V_38 ) ;
F_81 ( V_93 , & V_47 -> V_48 ) ;
* V_134 = V_1 ;
* V_135 = V_5 ;
return 0 ;
}
static int T_6 F_82 ( struct V_133 * V_47 ,
const struct V_143 * V_144 )
{
struct V_132 * V_93 ;
T_1 * V_1 ;
struct V_4 * V_5 = NULL ;
int V_53 ;
if ( V_141 >= V_145 )
return ( - V_54 ) ;
if ( ! V_146 [ V_141 ] ) {
++ V_141 ;
return ( - V_147 ) ;
}
V_53 = F_83 ( V_148 [ V_141 ] , V_116 [ V_141 ] , V_149 ,
sizeof( T_1 ) , & V_93 ) ;
if ( V_53 < 0 )
return V_53 ;
V_93 -> V_150 = F_68 ;
V_53 = F_69 ( V_93 , V_47 , & V_1 , & V_5 ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_48 ( V_1 , 0 , L_17 ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_84 ( V_93 , F_85 ( & V_151 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_84 ( V_93 , F_85 ( & V_152 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
V_53 = F_84 ( V_93 , F_85 ( & V_153 , V_1 ) ) ;
if ( V_53 < 0 )
goto error;
if ( V_5 -> V_123 . V_124 == V_125 )
F_84 ( V_93 , F_85 ( & V_154 , V_1 ) ) ;
strcpy ( V_93 -> V_155 , L_18 ) ;
sprintf ( V_93 -> V_156 , L_19 , V_47 -> V_90 ) ;
sprintf ( V_93 -> V_157 , L_20 ,
V_93 -> V_156 , ( unsigned long long ) F_79 ( V_47 , 0 ) ) ;
strcpy ( V_93 -> V_158 , L_21 ) ;
F_6 ( 0 , L_22 ,
V_93 -> V_155 , V_141 ) ;
V_53 = F_86 ( V_93 ) ;
if ( V_53 < 0 )
goto error;
F_87 ( V_47 , V_93 ) ;
V_141 ++ ;
return 0 ;
error:
F_88 ( V_93 ) ;
return V_53 ;
}
static void T_7 F_89 ( struct V_133 * V_47 )
{
struct V_159 * V_93 = F_90 ( V_47 ) ;
F_88 ( ( void * ) V_93 ) ;
F_87 ( V_47 , NULL ) ;
V_141 -- ;
}
static int T_8 F_91 ( void )
{
F_14 ( V_160 L_23 ,
( V_161 >> 16 ) & 0xff ,
( V_161 >> 8 ) & 0xff ,
V_161 & 0xff ) ;
#ifdef F_92
F_14 ( V_160 L_24 ,
F_92 / 10000 , ( F_92 / 100 ) % 100 , F_92 % 100 ) ;
#endif
return F_93 ( & V_162 ) ;
}
static void T_9 F_94 ( void )
{
F_95 ( & V_162 ) ;
}
