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
static int F_19 ( struct V_46 * V_1 , int V_47 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_48 * V_49 ;
int V_50 ;
V_3 -> V_51 = F_20 ( V_47 << V_52 ) ;
if ( NULL == V_3 -> V_51 ) {
F_6 ( 1 , L_9 , V_47 ) ;
return - V_53 ;
}
F_6 ( 1 , L_10 ,
( unsigned long ) V_3 -> V_51 ,
V_47 << V_52 ) ;
memset ( V_3 -> V_51 , 0 , V_47 << V_52 ) ;
V_3 -> V_47 = V_47 ;
V_3 -> V_54 = F_21 ( V_3 -> V_47 * sizeof( * V_3 -> V_54 ) ) ;
if ( NULL == V_3 -> V_54 )
goto V_55;
F_22 ( V_3 -> V_54 , V_3 -> V_47 ) ;
for ( V_50 = 0 ; V_50 < V_3 -> V_47 ; V_50 ++ ) {
V_49 = F_23 ( V_3 -> V_51 + V_50 * V_56 ) ;
if ( NULL == V_49 )
goto V_57;
F_24 ( & V_3 -> V_54 [ V_50 ] , V_49 , V_56 , 0 ) ;
}
return 0 ;
V_57:
F_25 ( V_3 -> V_54 ) ;
V_3 -> V_54 = NULL ;
V_55:
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
return - V_53 ;
}
static int F_26 ( struct V_46 * V_58 )
{
struct V_2 * V_3 = V_58 -> V_3 ;
V_3 -> V_59 = F_27 ( & V_58 -> V_60 -> V_58 , V_3 -> V_54 ,
V_3 -> V_47 , V_61 ) ;
if ( 0 == V_3 -> V_59 ) {
F_28 ( L_11 , V_62 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_29 ( struct V_46 * V_58 )
{
struct V_2 * V_3 = V_58 -> V_3 ;
if ( ! V_3 -> V_59 )
return 0 ;
F_30 ( & V_58 -> V_60 -> V_58 , V_3 -> V_54 , V_3 -> V_59 , V_61 ) ;
V_3 -> V_59 = 0 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
F_25 ( V_3 -> V_54 ) ;
V_3 -> V_54 = NULL ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
return 0 ;
}
static int F_32 ( T_1 * V_1 )
{
struct V_63 * V_12 = & V_1 -> V_3 -> V_12 ;
F_33 ( ! V_1 -> V_64 ) ;
F_6 ( 2 , L_12 ) ;
F_29 ( V_1 ) ;
F_31 ( V_1 -> V_3 ) ;
if ( V_12 -> V_65 )
F_34 ( V_1 -> V_60 , V_12 -> V_66 , V_12 -> V_65 , V_12 -> V_13 ) ;
F_35 ( V_1 -> V_3 ) ;
V_1 -> V_3 = NULL ;
return 0 ;
}
static int F_36 ( struct V_67 * V_37 )
{
T_1 * V_1 = F_37 ( V_37 ) ;
struct V_68 * V_69 = V_37 -> V_69 ;
int V_70 ;
if ( ! V_1 ) {
F_14 ( V_45 L_13
L_14 ) ;
return - V_71 ;
}
V_70 = F_38 ( V_69 , 0 , V_72 ) ;
if ( V_70 < 0 )
goto V_73;
V_1 -> V_37 = V_37 ;
V_69 -> V_74 = V_75 ;
if ( V_8 [ V_9 ] . V_76 != V_77 ) {
unsigned int V_11 = V_8 [ V_9 ] . V_76 / 4 ;
V_11 &= ~ 7 ;
V_69 -> V_74 . V_78 = V_11 ;
V_69 -> V_74 . V_79 = V_11 ;
}
return 0 ;
V_73:
F_6 ( 1 , L_15 ) ;
return V_70 ;
}
static int F_39 ( struct V_67 * V_37 )
{
return 0 ;
}
static int F_40 ( struct V_67 * V_37 ,
struct V_80 * V_81 )
{
T_1 * V_1 = F_37 ( V_37 ) ;
struct V_2 * V_3 ;
int V_82 ;
if ( V_37 -> V_69 -> V_83 ) {
F_32 ( V_1 ) ;
V_37 -> V_69 -> V_83 = NULL ;
}
V_1 -> V_84 = F_41 ( V_81 ) ;
V_1 -> V_19 = F_42 ( V_81 ) ;
V_1 -> V_64 = V_1 -> V_84 * F_42 ( V_81 ) ;
F_33 ( ! V_1 -> V_64 ) ;
F_33 ( V_1 -> V_19 & ( V_1 -> V_19 - 1 ) ) ;
V_3 = F_43 ( sizeof( * V_3 ) , V_85 ) ;
if ( NULL == V_3 )
return - V_53 ;
V_1 -> V_3 = V_3 ;
V_3 -> V_11 = V_1 -> V_84 ;
V_82 = F_19 ( V_1 ,
( F_44 ( V_1 -> V_64 ) >> V_52 ) ) ;
if ( V_82 < 0 )
goto error;
V_82 = F_26 ( V_1 ) ;
if ( V_82 < 0 )
goto error;
V_82 = F_45 ( V_1 -> V_60 , & V_3 -> V_12 , V_3 -> V_54 ,
V_1 -> V_84 , V_1 -> V_19 , 1 ) ;
if ( V_82 < 0 )
goto error;
V_3 -> V_12 . V_86 [ 0 ] = F_46 ( V_87 | V_88 | V_89 ) ;
V_3 -> V_12 . V_86 [ 1 ] = F_46 ( V_3 -> V_12 . V_13 ) ;
V_37 -> V_69 -> V_83 = V_1 -> V_3 -> V_51 ;
V_37 -> V_69 -> V_90 = V_1 -> V_64 ;
V_37 -> V_69 -> V_91 = 0 ;
return 0 ;
error:
F_35 ( V_3 ) ;
return V_82 ;
}
static int F_47 ( struct V_67 * V_37 )
{
T_1 * V_1 = F_37 ( V_37 ) ;
if ( V_37 -> V_69 -> V_83 ) {
F_32 ( V_1 ) ;
V_37 -> V_69 -> V_83 = NULL ;
}
return 0 ;
}
static int F_48 ( struct V_67 * V_37 )
{
return 0 ;
}
static int F_49 ( struct V_67 * V_37 , int V_92 )
{
T_1 * V_1 = F_37 ( V_37 ) ;
int V_70 ;
F_50 ( & V_1 -> V_93 ) ;
switch ( V_92 ) {
case V_94 :
V_70 = F_1 ( V_1 ) ;
break;
case V_95 :
V_70 = F_10 ( V_1 ) ;
break;
default:
V_70 = - V_96 ;
break;
}
F_51 ( & V_1 -> V_93 ) ;
return V_70 ;
}
static T_4 F_52 ( struct V_67 * V_37 )
{
T_1 * V_1 = F_37 ( V_37 ) ;
struct V_68 * V_69 = V_37 -> V_69 ;
T_5 V_17 ;
V_17 = F_53 ( & V_1 -> V_17 ) ;
return V_69 -> V_84 * ( V_17 & ( V_69 -> V_97 - 1 ) ) ;
}
static struct V_48 * F_54 ( struct V_67 * V_37 ,
unsigned long V_98 )
{
void * V_99 = V_37 -> V_69 -> V_83 + V_98 ;
return F_23 ( V_99 ) ;
}
static int F_55 ( T_1 * V_1 , int V_100 , const char * V_33 )
{
int V_70 ;
struct V_101 * V_102 ;
V_70 = F_56 ( V_1 -> V_103 , V_33 , V_100 , 0 , 1 , & V_102 ) ;
if ( V_70 < 0 )
return V_70 ;
V_102 -> V_104 = V_1 ;
strcpy ( V_102 -> V_33 , V_33 ) ;
F_57 ( V_102 , V_105 , & V_106 ) ;
return 0 ;
}
static int F_58 ( struct V_107 * V_108 ,
struct V_109 * V_110 )
{
V_110 -> type = V_111 ;
V_110 -> V_17 = 2 ;
V_110 -> V_112 . integer . V_113 = 0 ;
V_110 -> V_112 . integer . V_114 = 0x3f ;
return 0 ;
}
static int F_59 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_116 = 0x3f - ( F_7 ( V_117 ) & 0x3f ) ,
V_118 = F_7 ( V_119 ) ;
V_112 -> V_112 . integer . V_112 [ ( V_118 & 0x40 ) ? 0 : 1 ] = V_116 ;
V_116 -= ( V_118 & 0x3f ) ;
V_112 -> V_112 . integer . V_112 [ ( V_118 & 0x40 ) ? 1 : 0 ] = V_116 < 0 ? 0 : V_116 ;
return 0 ;
}
static void F_61 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_120 = V_112 -> V_112 . integer . V_112 [ 0 ] ;
int V_121 = V_112 -> V_112 . integer . V_112 [ 1 ] ;
int V_122 , V_123 ;
if ( V_120 >= V_121 ) {
V_122 = V_120 << 10 ;
V_123 = V_120 ? ( 0x8000 * V_121 ) / V_120 : 0x8000 ;
} else {
V_122 = V_121 << 10 ;
V_123 = V_121 ? 0xffff - ( 0x8000 * V_120 ) / V_121 : 0x8000 ;
}
F_62 ( V_5 , V_124 , V_122 ) ;
F_62 ( V_5 , V_125 , V_123 ) ;
}
static int F_63 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_120 , V_121 , V_122 , V_123 ;
int V_126 = 0 ;
T_2 V_127 ;
if ( V_5 -> V_128 )
F_61 ( V_108 , V_112 ) ;
V_120 = V_112 -> V_112 . integer . V_112 [ 0 ] & 0x3f ;
V_121 = V_112 -> V_112 . integer . V_112 [ 1 ] & 0x3f ;
V_123 = V_121 - V_120 ;
if ( V_123 < 0 ) {
V_122 = 0x3f - V_120 ;
V_123 = ( - V_123 ) | 0x40 ;
} else {
V_122 = 0x3f - V_121 ;
}
F_64 ( & V_1 -> V_93 ) ;
V_127 = F_7 ( V_117 ) ;
if ( V_122 != ( V_127 & 0x3f ) ) {
F_65 ( V_129 , V_117 , ( V_127 & ~ 0x3f ) | V_122 ) ;
V_126 = 1 ;
}
if ( ( F_7 ( V_119 ) & 0x7f ) != V_123 ) {
F_4 ( V_119 , V_123 ) ;
V_126 = 1 ;
}
F_66 ( & V_1 -> V_93 ) ;
return V_126 ;
}
static int F_67 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_130 = V_108 -> V_131 ;
V_112 -> V_112 . integer . V_112 [ 0 ] = ! ( F_7 ( V_117 ) & V_130 ) ;
return 0 ;
}
static int F_68 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_2 V_130 = V_108 -> V_131 ;
int V_82 = 0 ;
T_2 V_116 ;
F_64 ( & V_1 -> V_93 ) ;
V_116 = F_7 ( V_117 ) ;
if ( V_112 -> V_112 . integer . V_112 [ 0 ] != ! ( V_116 & V_130 ) ) {
V_116 ^= V_130 ;
F_65 ( V_129 , V_117 , V_116 ) ;
if ( V_5 -> V_128 && ( ( 1 << 6 ) == V_130 ) )
F_62 ( V_5 , V_132 , 0 != ( V_116 & V_130 ) ) ;
V_82 = 1 ;
}
F_66 ( & V_1 -> V_93 ) ;
return V_82 ;
}
static int F_69 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
T_6 V_133 ;
V_133 = F_70 ( V_5 , V_134 ) ;
V_112 -> V_112 . integer . V_112 [ 0 ] = V_133 ? 1 : 0 ;
return 0 ;
}
static int F_71 ( struct V_107 * V_108 ,
struct V_115 * V_112 )
{
T_1 * V_1 = F_60 ( V_108 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
F_62 ( V_5 , V_134 ,
V_112 -> V_112 . integer . V_112 [ 0 ] != 0 ) ;
return 0 ;
}
static int F_72 ( T_1 * V_1 )
{
if ( V_1 -> V_38 >= 0 )
F_73 ( V_1 -> V_38 , V_1 ) ;
F_74 ( V_1 -> V_5 , V_1 -> V_60 ) ;
F_75 ( V_1 -> V_60 ) ;
return 0 ;
}
static void F_76 ( struct V_135 * V_103 )
{
T_1 * V_1 = V_103 -> V_104 ;
F_72 ( V_1 ) ;
}
static int F_77 ( struct V_135 * V_103 , struct V_136 * V_60 ,
T_1 * * V_137 ,
struct V_4 * * V_138 )
{
T_1 * V_1 ;
struct V_4 * V_5 ;
int V_70 ;
unsigned char V_139 ;
* V_137 = NULL ;
V_70 = F_78 ( V_60 ) ;
if ( V_70 < 0 )
return V_70 ;
F_79 ( V_60 ) ;
V_1 = V_103 -> V_104 ;
V_5 = F_80 ( V_60 ) ;
if ( NULL == V_5 ) {
V_70 = - V_96 ;
return V_70 ;
}
V_70 = F_81 ( V_60 , F_82 ( 32 ) ) ;
if ( V_70 ) {
F_6 ( 0 , L_16 , V_5 -> V_33 ) ;
F_74 ( V_5 , V_60 ) ;
return V_70 ;
}
V_1 -> V_103 = V_103 ;
V_1 -> V_60 = V_60 ;
V_1 -> V_38 = - 1 ;
F_83 ( & V_1 -> V_93 ) ;
V_1 -> V_5 = V_5 ;
V_70 = F_84 ( V_1 -> V_60 -> V_38 , F_16 ,
V_140 , V_1 -> V_5 -> V_33 , V_1 ) ;
if ( V_70 < 0 ) {
F_6 ( 0 , L_17 ,
V_1 -> V_5 -> V_33 , V_1 -> V_60 -> V_38 ) ;
return V_70 ;
}
F_85 ( V_60 , V_141 , & V_139 ) ;
F_6 ( 1 , L_18
L_19 , V_5 -> V_33 , V_142 ,
F_86 ( V_60 ) , V_60 -> V_143 , V_60 -> V_38 ,
V_139 , ( unsigned long long ) F_87 ( V_60 , 0 ) ) ;
V_1 -> V_38 = V_60 -> V_38 ;
F_88 ( V_1 -> V_38 ) ;
* V_137 = V_1 ;
* V_138 = V_5 ;
return 0 ;
}
static int F_89 ( struct V_136 * V_60 ,
const struct V_144 * V_145 )
{
struct V_135 * V_103 ;
T_1 * V_1 ;
struct V_4 * V_5 = NULL ;
int V_70 ;
if ( V_142 >= V_146 )
return ( - V_71 ) ;
if ( ! V_147 [ V_142 ] ) {
++ V_142 ;
return ( - V_148 ) ;
}
V_70 = F_90 ( & V_60 -> V_58 , V_149 [ V_142 ] , V_150 [ V_142 ] , V_151 ,
sizeof( T_1 ) , & V_103 ) ;
if ( V_70 < 0 )
return V_70 ;
V_103 -> V_152 = F_76 ;
V_70 = F_77 ( V_103 , V_60 , & V_1 , & V_5 ) ;
if ( V_70 < 0 )
goto error;
V_70 = F_55 ( V_1 , 0 , L_20 ) ;
if ( V_70 < 0 )
goto error;
V_70 = F_91 ( V_103 , F_92 ( & V_153 , V_1 ) ) ;
if ( V_70 < 0 )
goto error;
V_70 = F_91 ( V_103 , F_92 ( & V_154 , V_1 ) ) ;
if ( V_70 < 0 )
goto error;
V_70 = F_91 ( V_103 , F_92 ( & V_155 , V_1 ) ) ;
if ( V_70 < 0 )
goto error;
if ( V_5 -> V_128 )
F_91 ( V_103 , F_92 ( & V_156 , V_1 ) ) ;
strcpy ( V_103 -> V_157 , L_21 ) ;
sprintf ( V_103 -> V_158 , L_22 , V_60 -> V_100 ) ;
sprintf ( V_103 -> V_159 , L_23 ,
V_103 -> V_158 , ( unsigned long long ) F_87 ( V_60 , 0 ) ) ;
strcpy ( V_103 -> V_160 , L_24 ) ;
F_6 ( 0 , L_25 ,
V_103 -> V_157 , V_142 ) ;
V_70 = F_93 ( V_103 ) ;
if ( V_70 < 0 )
goto error;
F_94 ( V_60 , V_103 ) ;
V_142 ++ ;
return 0 ;
error:
F_95 ( V_103 ) ;
return V_70 ;
}
static void F_96 ( struct V_136 * V_60 )
{
struct V_135 * V_103 = F_97 ( V_60 ) ;
F_95 ( V_103 ) ;
V_142 -- ;
}
