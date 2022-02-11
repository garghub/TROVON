static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 T_1 * V_5 ;
int V_6 = V_2 -> V_7 ;
if ( V_6 - V_3 < 0 ) {
V_5 = V_2 -> V_5 ;
do {
V_6 = ( F_2 ( & V_5 -> V_8 ) & V_9 ) ;
V_6 -= 8 ;
} while ( V_6 - V_3 < 0 );
}
V_2 -> V_7 = V_6 - V_3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_4 T_1 * V_5 ;
int V_10 = 10000 ;
V_5 = V_2 -> V_5 ;
do {
if ( ( F_2 ( & V_5 -> V_8 ) & V_11 ) == 0 )
break;
if ( ( F_2 ( & V_5 -> V_8 ) & V_12 ) != 0 ) {
F_4 ( V_12 , & V_5 -> V_8 ) ;
}
F_5 ( 10 ) ;
} while ( -- V_10 > 0 );
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_2 ;
F_3 ( V_2 ) ;
return 0 ;
}
static T_2 void F_7 ( struct V_1 * V_2 , T_3 V_15 )
{
if ( V_2 -> V_16 != V_15 ) {
F_1 ( V_2 , 1 ) ;
F_4 ( V_15 , & V_2 -> V_5 -> V_15 ) ;
V_2 -> V_16 = V_15 ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 T_1 * V_5 = V_2 -> V_5 ;
struct V_17 T_1 * V_18 = V_2 -> V_18 ;
unsigned long V_19 ;
F_9 ( & V_2 -> V_20 , V_19 ) ;
F_3 ( V_2 ) ;
V_2 -> V_7 = 0 ;
F_1 ( V_2 , 7 ) ;
F_4 ( V_21 | V_22 |
V_23 | V_24 ,
& V_5 -> V_25 ) ;
F_4 ( 0x2000707f , & V_5 -> V_5 ) ;
F_4 ( V_2 -> V_16 , & V_5 -> V_15 ) ;
F_4 ( 0xffffffff , & V_5 -> V_26 ) ;
F_4 ( ( 1 << 16 ) | ( 0 << 0 ) , & V_5 -> V_27 ) ;
F_4 ( V_2 -> V_28 , & V_5 -> V_29 ) ;
F_4 ( V_2 -> V_30 , & V_5 -> V_31 ) ;
F_3 ( V_2 ) ;
F_4 ( V_32 , & V_18 -> V_33 ) ;
if ( V_2 -> V_19 & V_34 )
F_4 ( 0 , & V_18 -> V_35 ) ;
else
F_4 ( ( V_36 |
V_37 ) , & V_18 -> V_35 ) ;
F_10 ( & V_2 -> V_20 , V_19 ) ;
}
static int F_11 ( struct V_38 * V_39 , struct V_13 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
F_8 ( V_2 ) ;
if ( V_39 -> V_41 || V_39 -> V_42 || V_39 -> V_43 )
return - V_44 ;
return 0 ;
}
static void F_12 ( struct V_13 * V_40 , const struct V_45 * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
struct V_4 T_1 * V_5 = V_2 -> V_5 ;
unsigned long V_19 ;
T_3 V_29 ;
F_13 ( V_46 -> V_15 != V_47 && V_46 -> V_15 != V_48 ) ;
V_29 = ( ( T_3 * ) V_40 -> V_49 ) [ V_46 -> V_50 ] ;
F_9 ( & V_2 -> V_20 , V_19 ) ;
if ( V_29 != V_2 -> V_28 ) {
F_1 ( V_2 , 1 ) ;
F_4 ( V_29 , & V_5 -> V_29 ) ;
V_2 -> V_28 = V_29 ;
}
F_7 ( V_2 , V_46 -> V_15 == V_47 ?
V_51 :
V_52 ) ;
F_1 ( V_2 , 5 ) ;
F_4 ( V_53 , & V_5 -> V_54 ) ;
F_4 ( V_46 -> V_55 , & V_5 -> V_56 ) ;
F_4 ( V_46 -> V_57 , & V_5 -> V_58 ) ;
F_4 ( V_46 -> V_59 , & V_5 -> V_60 ) ;
F_4 ( V_46 -> V_61 , & V_5 -> V_62 ) ;
F_10 ( & V_2 -> V_20 , V_19 ) ;
}
static void F_14 ( struct V_13 * V_40 , const struct V_63 * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
struct V_4 T_1 * V_5 = V_2 -> V_5 ;
unsigned long V_19 ;
if ( V_64 -> V_57 != V_64 -> V_65 ||
V_64 -> V_55 == V_64 -> V_66 ) {
F_15 ( V_40 , V_64 ) ;
return;
}
F_9 ( & V_2 -> V_20 , V_19 ) ;
F_7 ( V_2 , V_67 ) ;
F_1 ( V_2 , 7 ) ;
F_4 ( V_68 , & V_5 -> V_54 ) ;
F_4 ( V_64 -> V_66 , & V_5 -> V_56 ) ;
F_4 ( V_64 -> V_65 , & V_5 -> V_58 ) ;
F_4 ( V_64 -> V_55 , & V_5 -> V_55 ) ;
F_4 ( V_64 -> V_57 , & V_5 -> V_57 ) ;
F_4 ( V_64 -> V_59 , & V_5 -> V_60 ) ;
F_4 ( V_64 -> V_61 , & V_5 -> V_62 ) ;
F_10 ( & V_2 -> V_20 , V_19 ) ;
}
static void F_16 ( struct V_13 * V_40 , const struct V_69 * V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
struct V_4 T_1 * V_5 = V_2 -> V_5 ;
const T_4 * V_71 = V_70 -> V_71 ;
unsigned long V_19 ;
T_3 V_29 , V_31 , V_72 ;
T_5 V_73 ;
int V_74 , V_61 , V_75 ;
if ( V_70 -> V_76 > 1 ) {
F_17 ( V_40 , V_70 ) ;
return;
}
V_29 = ( ( T_3 * ) V_40 -> V_49 ) [ V_70 -> V_77 ] ;
V_31 = ( ( T_3 * ) V_40 -> V_49 ) [ V_70 -> V_78 ] ;
V_73 = ( ( T_5 ) V_29 << 32 ) | ( T_5 ) V_31 ;
V_72 = ( V_70 -> V_55 << 16 ) | V_70 -> V_57 ;
V_61 = V_70 -> V_61 ;
V_75 = ( ( V_61 + 7 ) >> 3 ) ;
F_9 ( & V_2 -> V_20 , V_19 ) ;
if ( V_73 != * ( T_5 * ) & V_2 -> V_28 ) {
F_1 ( V_2 , 2 ) ;
F_18 ( V_73 , & V_5 -> V_29 ) ;
* ( T_5 * ) & V_2 -> V_28 = V_73 ;
}
if ( V_61 >= 32 ) {
F_1 ( V_2 , 1 ) ;
F_4 ( 32 , & V_5 -> V_79 ) ;
}
while ( V_61 >= 32 ) {
const T_4 * V_80 = V_71 + 4 ;
F_1 ( V_2 , 1 ) ;
F_4 ( V_72 , & V_5 -> V_81 ) ;
V_72 += ( 32 << 0 ) ;
for ( V_74 = 0 ; V_74 < V_70 -> V_59 ; V_74 ++ ) {
T_3 V_82 = ( ( ( T_3 ) V_71 [ 0 ] << 24 ) |
( ( T_3 ) V_71 [ 1 ] << 16 ) |
( ( T_3 ) V_71 [ 2 ] << 8 ) |
( ( T_3 ) V_71 [ 3 ] << 0 ) ) ;
F_1 ( V_2 , 1 ) ;
F_4 ( V_82 , & V_5 -> V_83 ) ;
V_71 += V_75 ;
}
V_71 = V_80 ;
V_61 -= 32 ;
}
if ( V_61 ) {
F_1 ( V_2 , 2 ) ;
F_4 ( V_61 , & V_5 -> V_79 ) ;
F_4 ( V_72 , & V_5 -> V_81 ) ;
for ( V_74 = 0 ; V_74 < V_70 -> V_59 ; V_74 ++ ) {
T_3 V_82 = ( ( ( T_3 ) V_71 [ 0 ] << 24 ) |
( ( T_3 ) V_71 [ 1 ] << 16 ) |
( ( T_3 ) V_71 [ 2 ] << 8 ) |
( ( T_3 ) V_71 [ 3 ] << 0 ) ) ;
F_1 ( V_2 , 1 ) ;
F_4 ( V_82 , & V_5 -> V_83 ) ;
V_71 += V_75 ;
}
}
F_10 ( & V_2 -> V_20 , V_19 ) ;
}
static void F_19 ( struct V_38 * V_39 )
{
V_39 -> V_84 . V_85 = 0 ;
V_39 -> V_84 . V_86 = 8 ;
V_39 -> V_87 . V_85 = 8 ;
V_39 -> V_87 . V_86 = 8 ;
V_39 -> V_88 . V_85 = 16 ;
V_39 -> V_88 . V_86 = 8 ;
V_39 -> V_89 . V_85 = 0 ;
V_39 -> V_89 . V_86 = 0 ;
}
static int F_20 ( unsigned V_90 ,
unsigned V_84 , unsigned V_87 , unsigned V_88 ,
unsigned V_89 , struct V_13 * V_40 )
{
T_3 V_91 ;
if ( V_90 >= 16 )
return 1 ;
V_84 >>= 8 ;
V_87 >>= 8 ;
V_88 >>= 8 ;
V_91 = ( V_88 << 16 ) | ( V_87 << 8 ) | V_84 ;
( ( T_3 * ) V_40 -> V_49 ) [ V_90 ] = V_91 ;
return 0 ;
}
static int F_21 ( int V_92 , struct V_13 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
struct V_17 T_1 * V_18 = V_2 -> V_18 ;
unsigned long V_19 ;
T_3 V_82 ;
int V_74 ;
F_9 ( & V_2 -> V_20 , V_19 ) ;
F_3 ( V_2 ) ;
F_4 ( V_93 , & V_18 -> type ) ;
V_82 = F_2 ( & V_18 -> V_91 ) ;
switch ( V_92 ) {
case V_94 :
V_82 |= V_95 ;
V_2 -> V_19 &= ~ V_96 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_82 &= ~ V_95 ;
V_2 -> V_19 |= V_96 ;
break;
}
F_4 ( V_93 , & V_18 -> type ) ;
F_4 ( V_82 , & V_18 -> V_91 ) ;
for ( V_74 = 0 ; V_74 < 10 ; V_74 ++ ) {
F_4 ( V_93 , & V_18 -> type ) ;
F_2 ( & V_18 -> V_91 ) ;
}
F_10 ( & V_2 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_40 , struct V_101 * V_102 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
return F_23 ( V_103 ,
V_2 -> V_104 , V_2 -> V_105 ,
0 , V_102 ) ;
}
static int F_24 ( struct V_13 * V_40 , unsigned int V_106 , unsigned long V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
return F_25 ( V_106 , V_107 , V_40 ,
V_108 , 24 , V_2 -> V_105 ) ;
}
static void F_26 ( struct V_13 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_2 ;
const char * V_109 ;
if ( ! ( V_2 -> V_19 & V_110 ) ) {
if ( ( V_2 -> V_111 & 0x7 ) == 0x3 )
V_109 = L_1 ;
else
V_109 = L_2 ;
} else
V_109 = L_3 ;
F_27 ( V_40 -> V_112 . V_113 , V_109 , sizeof( V_40 -> V_112 . V_113 ) ) ;
V_40 -> V_112 . type = V_114 ;
V_40 -> V_112 . V_115 = V_116 ;
V_40 -> V_112 . V_117 = 8192 ;
V_40 -> V_112 . V_118 = V_119 ;
}
static int F_28 ( struct V_120 * V_121 )
{
struct V_122 * V_123 = V_121 -> V_124 . V_125 ;
struct V_4 T_1 * V_5 ;
struct V_17 T_1 * V_18 ;
struct V_13 * V_40 ;
struct V_1 * V_2 ;
T_3 V_126 , V_127 , V_128 ;
int V_129 ;
V_40 = F_29 ( sizeof( struct V_1 ) , & V_121 -> V_124 ) ;
V_129 = - V_130 ;
if ( ! V_40 )
goto V_131;
V_2 = V_40 -> V_2 ;
F_30 ( & V_2 -> V_20 ) ;
V_2 -> V_5 = F_31 ( & V_121 -> V_132 [ 2 ] , 0 ,
sizeof( struct V_4 ) , L_4 ) ;
if ( ! V_2 -> V_5 )
goto V_133;
V_2 -> V_18 = F_31 ( & V_121 -> V_132 [ 1 ] , 0 ,
sizeof( struct V_17 ) , L_5 ) ;
if ( ! V_2 -> V_18 )
goto V_134;
V_2 -> V_16 = V_51 ;
V_2 -> V_104 = V_121 -> V_132 [ 0 ] . V_135 ;
V_40 -> V_19 = ( V_136 |
V_137 |
V_138 ) ;
V_40 -> V_139 = & V_140 ;
V_40 -> V_141 = ( char * ) V_2 -> V_104 + V_142 ;
V_40 -> V_49 = V_2 -> V_49 ;
F_32 ( & V_40 -> V_39 , V_123 , 32 ) ;
V_2 -> V_105 = F_33 ( V_40 -> V_39 . V_143 * V_40 -> V_39 . V_144 * 4 ) ;
F_19 ( & V_40 -> V_39 ) ;
V_40 -> V_39 . V_145 = V_146 ;
if ( ! strcmp ( V_123 -> V_147 , L_6 ) )
V_2 -> V_19 |= V_110 ;
V_2 -> V_111 = F_34 ( V_123 , L_7 , 0 ) ;
V_5 = V_2 -> V_5 ;
if ( ( F_2 ( & V_5 -> V_8 ) & V_12 ) != 0 )
F_4 ( V_12 , & V_5 -> V_8 ) ;
V_18 = V_2 -> V_18 ;
F_4 ( V_148 , & V_18 -> type ) ;
V_126 = F_2 ( & V_18 -> V_91 ) ;
V_127 = ( V_126 & V_149 ) >> V_150 ;
V_126 = ( V_126 & V_151 ) >> V_152 ;
F_4 ( V_153 , & V_18 -> type ) ;
V_128 = F_2 ( & V_18 -> V_91 ) ;
V_128 = ( V_128 & V_154 ) >>
V_155 ;
if ( ( V_2 -> V_19 & V_110 ) || V_126 == 0x236e ) {
V_2 -> V_19 &= ~ V_34 ;
} else {
if ( V_128 < 3 )
V_2 -> V_19 |= V_34 ;
}
F_8 ( V_2 ) ;
F_21 ( V_94 , V_40 ) ;
if ( F_35 ( & V_40 -> V_156 , 256 , 0 ) )
goto V_157;
F_26 ( V_40 ) ;
V_129 = F_36 ( V_40 ) ;
if ( V_129 < 0 )
goto V_158;
F_37 ( & V_121 -> V_124 , V_40 ) ;
F_38 ( V_159 L_8
L_9 ,
V_123 ,
( ( V_2 -> V_19 & V_110 ) ? L_10 : L_11 ) ,
V_2 -> V_104 , V_2 -> V_111 ,
V_126 , V_127 , V_128 ) ;
return 0 ;
V_158:
F_39 ( & V_40 -> V_156 ) ;
V_157:
F_40 ( & V_121 -> V_132 [ 1 ] , V_2 -> V_18 , sizeof( struct V_17 ) ) ;
V_134:
F_40 ( & V_121 -> V_132 [ 2 ] , V_2 -> V_5 , sizeof( struct V_4 ) ) ;
V_133:
F_41 ( V_40 ) ;
V_131:
return V_129 ;
}
static int F_42 ( struct V_120 * V_121 )
{
struct V_13 * V_40 = F_43 ( & V_121 -> V_124 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
F_44 ( V_40 ) ;
F_39 ( & V_40 -> V_156 ) ;
F_40 ( & V_121 -> V_132 [ 2 ] , V_2 -> V_5 , sizeof( struct V_4 ) ) ;
F_40 ( & V_121 -> V_132 [ 1 ] , V_2 -> V_18 , sizeof( struct V_17 ) ) ;
F_41 ( V_40 ) ;
return 0 ;
}
static int T_6 F_45 ( void )
{
if ( F_46 ( L_12 , NULL ) )
return - V_160 ;
return F_47 ( & V_161 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_161 ) ;
}
