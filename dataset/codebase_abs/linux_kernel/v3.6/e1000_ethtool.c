static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_9 == V_10 ) {
V_4 -> V_11 = ( V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 ) ;
V_4 -> V_19 = V_20 ;
if ( V_8 -> V_21 == 1 ) {
V_4 -> V_19 |= V_22 ;
V_4 -> V_19 |= V_8 -> V_23 ;
}
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = V_8 -> V_27 ;
if ( V_8 -> V_28 == V_29 )
V_4 -> V_30 = V_31 ;
else
V_4 -> V_30 = V_32 ;
} else {
V_4 -> V_11 = ( V_16 |
V_33 |
V_17 ) ;
V_4 -> V_19 = ( V_34 |
V_35 |
V_22 ) ;
V_4 -> V_24 = V_36 ;
if ( V_8 -> V_28 >= V_37 )
V_4 -> V_30 = V_32 ;
else
V_4 -> V_30 = V_31 ;
}
if ( F_3 ( V_38 ) & V_39 ) {
F_4 ( V_8 , & V_6 -> V_40 ,
& V_6 -> V_41 ) ;
F_5 ( V_4 , V_6 -> V_40 ) ;
if ( V_6 -> V_41 == V_42 )
V_4 -> V_43 = V_44 ;
else
V_4 -> V_43 = V_45 ;
} else {
F_5 ( V_4 , - 1 ) ;
V_4 -> V_43 = - 1 ;
}
V_4 -> V_21 = ( ( V_8 -> V_9 == V_46 ) ||
V_8 -> V_21 ) ? V_47 : V_48 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
while ( F_7 ( V_49 , & V_6 -> V_50 ) )
F_8 ( 1 ) ;
if ( V_4 -> V_21 == V_47 ) {
V_8 -> V_21 = 1 ;
if ( V_8 -> V_9 == V_46 )
V_8 -> V_23 = V_34 |
V_35 |
V_22 ;
else
V_8 -> V_23 = V_4 -> V_19 |
V_20 |
V_22 ;
V_4 -> V_19 = V_8 -> V_23 ;
} else {
T_1 V_51 = F_9 ( V_4 ) ;
if ( F_10 ( V_6 , V_51 , V_4 -> V_43 ) ) {
F_11 ( V_49 , & V_6 -> V_50 ) ;
return - V_52 ;
}
}
if ( F_12 ( V_6 -> V_2 ) ) {
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
} else
F_15 ( V_6 ) ;
F_11 ( V_49 , & V_6 -> V_50 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_17 ( V_2 ) )
V_6 -> V_8 . V_53 = 1 ;
return F_18 ( V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_55 -> V_21 =
( V_6 -> V_56 ? V_47 : V_48 ) ;
if ( V_8 -> V_57 == V_58 )
V_55 -> V_59 = 1 ;
else if ( V_8 -> V_57 == V_60 )
V_55 -> V_61 = 1 ;
else if ( V_8 -> V_57 == V_62 ) {
V_55 -> V_59 = 1 ;
V_55 -> V_61 = 1 ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
int V_63 = 0 ;
V_6 -> V_56 = V_55 -> V_21 ;
while ( F_7 ( V_49 , & V_6 -> V_50 ) )
F_8 ( 1 ) ;
if ( V_55 -> V_59 && V_55 -> V_61 )
V_8 -> V_57 = V_62 ;
else if ( V_55 -> V_59 && ! V_55 -> V_61 )
V_8 -> V_57 = V_58 ;
else if ( ! V_55 -> V_59 && V_55 -> V_61 )
V_8 -> V_57 = V_60 ;
else if ( ! V_55 -> V_59 && ! V_55 -> V_61 )
V_8 -> V_57 = V_64 ;
V_8 -> V_65 = V_8 -> V_57 ;
if ( V_6 -> V_56 == V_47 ) {
if ( F_12 ( V_6 -> V_2 ) ) {
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
} else
F_15 ( V_6 ) ;
} else
V_63 = ( ( V_8 -> V_9 == V_46 ) ?
F_21 ( V_8 ) : F_22 ( V_8 ) ) ;
F_11 ( V_49 , & V_6 -> V_50 ) ;
return V_63 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_66 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_66 = V_67 ;
}
static int F_25 ( struct V_1 * V_2 )
{
#define F_26 32
return F_26 * sizeof( T_1 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_68 * V_69 ,
void * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_71 = V_70 ;
T_2 V_72 ;
memset ( V_70 , 0 , F_26 * sizeof( T_1 ) ) ;
V_69 -> V_73 = ( 1 << 24 ) | ( V_8 -> V_74 << 16 ) | V_8 -> V_75 ;
V_71 [ 0 ] = F_3 ( V_76 ) ;
V_71 [ 1 ] = F_3 ( V_38 ) ;
V_71 [ 2 ] = F_3 ( V_77 ) ;
V_71 [ 3 ] = F_3 ( V_78 ) ;
V_71 [ 4 ] = F_3 ( V_79 ) ;
V_71 [ 5 ] = F_3 ( V_80 ) ;
V_71 [ 6 ] = F_3 ( V_81 ) ;
V_71 [ 7 ] = F_3 ( V_82 ) ;
V_71 [ 8 ] = F_3 ( V_83 ) ;
V_71 [ 9 ] = F_3 ( V_84 ) ;
V_71 [ 10 ] = F_3 ( V_85 ) ;
V_71 [ 11 ] = F_3 ( V_86 ) ;
V_71 [ 12 ] = V_8 -> V_87 ;
if ( V_8 -> V_87 == V_88 ) {
F_28 ( V_8 , V_89 ,
V_90 ) ;
F_29 ( V_8 , V_90 &
V_89 , & V_72 ) ;
V_71 [ 13 ] = ( T_1 ) V_72 ;
F_28 ( V_8 , V_89 ,
V_91 ) ;
F_29 ( V_8 , V_91 &
V_89 , & V_72 ) ;
V_71 [ 14 ] = ( T_1 ) V_72 ;
F_28 ( V_8 , V_89 ,
V_92 ) ;
F_29 ( V_8 , V_92 &
V_89 , & V_72 ) ;
V_71 [ 15 ] = ( T_1 ) V_72 ;
F_28 ( V_8 , V_89 ,
V_93 ) ;
F_29 ( V_8 , V_93 &
V_89 , & V_72 ) ;
V_71 [ 16 ] = ( T_1 ) V_72 ;
V_71 [ 17 ] = 0 ;
F_28 ( V_8 , V_89 , 0x0 ) ;
F_29 ( V_8 , V_94 &
V_89 , & V_72 ) ;
V_71 [ 18 ] = ( T_1 ) V_72 ;
F_28 ( V_8 , V_89 ,
V_95 ) ;
F_29 ( V_8 , V_95 &
V_89 , & V_72 ) ;
V_71 [ 19 ] = ( T_1 ) V_72 ;
V_71 [ 20 ] = 0 ;
V_71 [ 22 ] = 0 ;
V_71 [ 23 ] = V_71 [ 18 ] ;
F_28 ( V_8 , V_89 , 0x0 ) ;
} else {
F_29 ( V_8 , V_96 , & V_72 ) ;
V_71 [ 13 ] = ( T_1 ) V_72 ;
V_71 [ 14 ] = 0 ;
V_71 [ 15 ] = 0 ;
V_71 [ 16 ] = 0 ;
F_29 ( V_8 , V_97 , & V_72 ) ;
V_71 [ 17 ] = ( T_1 ) V_72 ;
V_71 [ 18 ] = V_71 [ 13 ] ;
V_71 [ 19 ] = 0 ;
V_71 [ 20 ] = V_71 [ 17 ] ;
V_71 [ 22 ] = V_6 -> V_98 . V_99 ;
V_71 [ 23 ] = V_71 [ 13 ] ;
}
V_71 [ 21 ] = V_6 -> V_98 . V_100 ;
F_29 ( V_8 , V_101 , & V_72 ) ;
V_71 [ 24 ] = ( T_1 ) V_72 ;
V_71 [ 25 ] = V_71 [ 24 ] ;
if ( V_8 -> V_28 >= V_102 &&
V_8 -> V_9 == V_10 ) {
V_71 [ 26 ] = F_3 ( V_103 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
return V_8 -> V_104 . V_105 * 2 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_106 * V_104 , T_3 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_108 ;
int V_109 , V_110 ;
int V_111 = 0 ;
T_2 V_112 ;
if ( V_104 -> V_113 == 0 )
return - V_52 ;
V_104 -> V_114 = V_8 -> V_115 | ( V_8 -> V_75 << 16 ) ;
V_109 = V_104 -> V_116 >> 1 ;
V_110 = ( V_104 -> V_116 + V_104 -> V_113 - 1 ) >> 1 ;
V_108 = F_32 ( sizeof( T_2 ) *
( V_110 - V_109 + 1 ) , V_117 ) ;
if ( ! V_108 )
return - V_118 ;
if ( V_8 -> V_104 . type == V_119 )
V_111 = F_33 ( V_8 , V_109 ,
V_110 - V_109 + 1 ,
V_108 ) ;
else {
for ( V_112 = 0 ; V_112 < V_110 - V_109 + 1 ; V_112 ++ ) {
V_111 = F_33 ( V_8 , V_109 + V_112 , 1 ,
& V_108 [ V_112 ] ) ;
if ( V_111 )
break;
}
}
for ( V_112 = 0 ; V_112 < V_110 - V_109 + 1 ; V_112 ++ )
F_34 ( & V_108 [ V_112 ] ) ;
memcpy ( V_107 , ( T_3 * ) V_108 + ( V_104 -> V_116 & 1 ) ,
V_104 -> V_113 ) ;
F_35 ( V_108 ) ;
return V_111 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_106 * V_104 , T_3 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_108 ;
void * V_120 ;
int V_121 , V_109 , V_110 , V_111 = 0 ;
T_2 V_112 ;
if ( V_104 -> V_113 == 0 )
return - V_122 ;
if ( V_104 -> V_114 != ( V_8 -> V_115 | ( V_8 -> V_75 << 16 ) ) )
return - V_123 ;
V_121 = V_8 -> V_104 . V_105 * 2 ;
V_109 = V_104 -> V_116 >> 1 ;
V_110 = ( V_104 -> V_116 + V_104 -> V_113 - 1 ) >> 1 ;
V_108 = F_32 ( V_121 , V_117 ) ;
if ( ! V_108 )
return - V_118 ;
V_120 = ( void * ) V_108 ;
if ( V_104 -> V_116 & 1 ) {
V_111 = F_33 ( V_8 , V_109 , 1 ,
& V_108 [ 0 ] ) ;
V_120 ++ ;
}
if ( ( ( V_104 -> V_116 + V_104 -> V_113 ) & 1 ) && ( V_111 == 0 ) ) {
V_111 = F_33 ( V_8 , V_110 , 1 ,
& V_108 [ V_110 - V_109 ] ) ;
}
for ( V_112 = 0 ; V_112 < V_110 - V_109 + 1 ; V_112 ++ )
F_34 ( & V_108 [ V_112 ] ) ;
memcpy ( V_120 , V_107 , V_104 -> V_113 ) ;
for ( V_112 = 0 ; V_112 < V_110 - V_109 + 1 ; V_112 ++ )
V_108 [ V_112 ] = F_37 ( V_108 [ V_112 ] ) ;
V_111 = F_38 ( V_8 , V_109 ,
V_110 - V_109 + 1 , V_108 ) ;
if ( ( V_111 == 0 ) && ( V_109 <= V_124 ) )
F_39 ( V_8 ) ;
F_35 ( V_108 ) ;
return V_111 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_41 ( V_126 -> V_127 , V_128 ,
sizeof( V_126 -> V_127 ) ) ;
F_41 ( V_126 -> V_73 , V_129 ,
sizeof( V_126 -> V_73 ) ) ;
F_41 ( V_126 -> V_130 , F_42 ( V_6 -> V_131 ) ,
sizeof( V_126 -> V_130 ) ) ;
V_126 -> V_132 = F_25 ( V_2 ) ;
V_126 -> V_133 = F_30 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_136 * V_137 = V_6 -> V_138 ;
struct V_139 * V_140 = V_6 -> V_141 ;
V_135 -> V_142 = ( V_28 < V_143 ) ? V_144 :
V_145 ;
V_135 -> V_146 = ( V_28 < V_143 ) ? V_147 :
V_148 ;
V_135 -> V_149 = V_140 -> V_150 ;
V_135 -> V_151 = V_137 -> V_150 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_136 * V_137 , * V_152 ;
struct V_139 * V_140 , * V_153 ;
int V_112 , V_154 ;
if ( ( V_135 -> V_155 ) || ( V_135 -> V_156 ) )
return - V_52 ;
while ( F_7 ( V_49 , & V_6 -> V_50 ) )
F_8 ( 1 ) ;
if ( F_12 ( V_6 -> V_2 ) )
F_13 ( V_6 ) ;
V_152 = V_6 -> V_138 ;
V_153 = V_6 -> V_141 ;
V_154 = - V_118 ;
V_137 = F_45 ( V_6 -> V_157 , sizeof( struct V_136 ) , V_117 ) ;
if ( ! V_137 )
goto V_158;
V_140 = F_45 ( V_6 -> V_159 , sizeof( struct V_139 ) , V_117 ) ;
if ( ! V_140 )
goto V_160;
V_6 -> V_138 = V_137 ;
V_6 -> V_141 = V_140 ;
V_140 -> V_150 = F_46 ( V_135 -> V_149 , ( T_1 ) V_161 ) ;
V_140 -> V_150 = F_47 ( V_140 -> V_150 , ( T_1 ) ( V_28 < V_143 ?
V_144 : V_145 ) ) ;
V_140 -> V_150 = F_48 ( V_140 -> V_150 , V_162 ) ;
V_137 -> V_150 = F_46 ( V_135 -> V_151 , ( T_1 ) V_163 ) ;
V_137 -> V_150 = F_47 ( V_137 -> V_150 , ( T_1 ) ( V_28 < V_143 ?
V_147 : V_148 ) ) ;
V_137 -> V_150 = F_48 ( V_137 -> V_150 , V_164 ) ;
for ( V_112 = 0 ; V_112 < V_6 -> V_157 ; V_112 ++ )
V_137 [ V_112 ] . V_150 = V_137 -> V_150 ;
for ( V_112 = 0 ; V_112 < V_6 -> V_159 ; V_112 ++ )
V_140 [ V_112 ] . V_150 = V_140 -> V_150 ;
if ( F_12 ( V_6 -> V_2 ) ) {
V_154 = F_49 ( V_6 ) ;
if ( V_154 )
goto V_165;
V_154 = F_50 ( V_6 ) ;
if ( V_154 )
goto V_166;
V_6 -> V_141 = V_153 ;
V_6 -> V_138 = V_152 ;
F_51 ( V_6 ) ;
F_52 ( V_6 ) ;
F_35 ( V_152 ) ;
F_35 ( V_153 ) ;
V_6 -> V_141 = V_140 ;
V_6 -> V_138 = V_137 ;
V_154 = F_14 ( V_6 ) ;
if ( V_154 )
goto V_167;
}
F_11 ( V_49 , & V_6 -> V_50 ) ;
return 0 ;
V_166:
F_51 ( V_6 ) ;
V_165:
V_6 -> V_141 = V_153 ;
V_6 -> V_138 = V_152 ;
F_35 ( V_140 ) ;
V_160:
F_35 ( V_137 ) ;
V_158:
F_14 ( V_6 ) ;
V_167:
F_11 ( V_49 , & V_6 -> V_50 ) ;
return V_154 ;
}
static bool F_53 ( struct V_5 * V_6 , T_5 * V_67 , int V_168 ,
T_1 V_169 , T_1 V_170 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
static const T_1 V_171 [] =
{ 0x5A5A5A5A , 0xA5A5A5A5 , 0x00000000 , 0xFFFFFFFF } ;
T_3 T_6 * V_172 = V_8 -> V_173 + V_168 ;
T_1 V_174 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < F_54 ( V_171 ) ; V_112 ++ ) {
F_55 ( V_170 & V_171 [ V_112 ] , V_172 ) ;
V_174 = F_56 ( V_172 ) ;
if ( V_174 != ( V_170 & V_171 [ V_112 ] & V_169 ) ) {
F_57 ( V_175 , L_1
L_2 ,
V_168 , V_174 , ( V_170 & V_171 [ V_112 ] & V_169 ) ) ;
* V_67 = V_168 ;
return true ;
}
}
return false ;
}
static bool F_58 ( struct V_5 * V_6 , T_5 * V_67 , int V_168 ,
T_1 V_169 , T_1 V_170 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_3 T_6 * V_172 = V_8 -> V_173 + V_168 ;
T_1 V_174 ;
F_55 ( V_170 & V_169 , V_172 ) ;
V_174 = F_56 ( V_172 ) ;
if ( ( V_174 & V_169 ) != ( V_170 & V_169 ) ) {
F_57 ( V_175 , L_3
L_2 ,
V_168 , ( V_174 & V_169 ) , ( V_170 & V_169 ) ) ;
* V_67 = V_168 ;
return true ;
}
return false ;
}
static int F_59 ( struct V_5 * V_6 , T_5 * V_67 )
{
T_1 V_176 , V_177 , V_178 ;
T_1 V_112 , V_179 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_179 = 0xFFFFF833 ;
V_177 = F_3 ( V_38 ) ;
V_176 = ( F_3 ( V_38 ) & V_179 ) ;
F_60 ( V_38 , V_179 ) ;
V_178 = F_3 ( V_38 ) & V_179 ;
if ( V_176 != V_178 ) {
F_57 ( V_175 , L_4
L_5 , V_178 , V_176 ) ;
* V_67 = 1 ;
return 1 ;
}
F_60 ( V_38 , V_177 ) ;
F_61 ( V_180 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_181 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_182 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_183 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_81 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_184 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_78 , 0x000FFF80 , 0x000FFFFF ) ;
F_61 ( V_79 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_80 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_185 , 0x0000FFF8 , 0x0000FFF8 ) ;
F_61 ( V_186 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_187 , 0x3FFFFFFF , 0x3FFFFFFF ) ;
F_61 ( V_188 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_83 , 0x000FFF80 , 0x000FFFFF ) ;
F_62 ( V_77 , 0xFFFFFFFF , 0x00000000 ) ;
V_177 = 0x06DFB3FE ;
F_62 ( V_77 , V_177 , 0x003FFFFB ) ;
F_62 ( V_82 , 0xFFFFFFFF , 0x00000000 ) ;
if ( V_8 -> V_28 >= V_29 ) {
F_62 ( V_77 , V_177 , 0xFFFFFFFF ) ;
F_61 ( V_189 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_61 ( V_190 , 0xC000FFFF , 0x0000FFFF ) ;
F_61 ( V_191 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_61 ( V_86 , 0x0000FFFF , 0x0000FFFF ) ;
V_176 = V_192 ;
for ( V_112 = 0 ; V_112 < V_176 ; V_112 ++ ) {
F_61 ( V_193 + ( ( ( V_112 << 1 ) + 1 ) << 2 ) , 0x8003FFFF ,
0xFFFFFFFF ) ;
}
} else {
F_62 ( V_77 , 0xFFFFFFFF , 0x01FFFFFF ) ;
F_61 ( V_189 , 0xFFFFF000 , 0xFFFFFFFF ) ;
F_61 ( V_190 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_191 , 0xFFFFF000 , 0xFFFFFFFF ) ;
}
V_176 = V_194 ;
for ( V_112 = 0 ; V_112 < V_176 ; V_112 ++ )
F_61 ( V_195 + ( V_112 << 2 ) , 0xFFFFFFFF , 0xFFFFFFFF ) ;
* V_67 = 0 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_196 ;
T_2 V_197 = 0 ;
T_2 V_112 ;
* V_67 = 0 ;
for ( V_112 = 0 ; V_112 < ( V_124 + 1 ) ; V_112 ++ ) {
if ( ( F_33 ( V_8 , V_112 , 1 , & V_196 ) ) < 0 ) {
* V_67 = 1 ;
break;
}
V_197 += V_196 ;
}
if ( ( V_197 != ( T_2 ) V_198 ) && ! ( * V_67 ) )
* V_67 = 2 ;
return * V_67 ;
}
static T_7 F_64 ( int V_199 , void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_6 -> V_200 |= F_3 ( V_201 ) ;
return V_202 ;
}
static int F_65 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 V_169 , V_112 = 0 ;
bool V_203 = true ;
T_1 V_199 = V_6 -> V_131 -> V_199 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_67 = 0 ;
if ( ! F_66 ( V_199 , F_64 , V_204 , V_2 -> V_205 ,
V_2 ) )
V_203 = false ;
else if ( F_66 ( V_199 , F_64 , V_206 ,
V_2 -> V_205 , V_2 ) ) {
* V_67 = 1 ;
return - 1 ;
}
F_67 ( V_8 , L_6 , ( V_203 ?
L_7 : L_8 ) ) ;
F_60 ( V_207 , 0xFFFFFFFF ) ;
F_68 () ;
F_8 ( 10 ) ;
for (; V_112 < 10 ; V_112 ++ ) {
V_169 = 1 << V_112 ;
if ( ! V_203 ) {
V_6 -> V_200 = 0 ;
F_60 ( V_207 , V_169 ) ;
F_60 ( V_208 , V_169 ) ;
F_68 () ;
F_8 ( 10 ) ;
if ( V_6 -> V_200 & V_169 ) {
* V_67 = 3 ;
break;
}
}
V_6 -> V_200 = 0 ;
F_60 ( V_209 , V_169 ) ;
F_60 ( V_208 , V_169 ) ;
F_68 () ;
F_8 ( 10 ) ;
if ( ! ( V_6 -> V_200 & V_169 ) ) {
* V_67 = 4 ;
break;
}
if ( ! V_203 ) {
V_6 -> V_200 = 0 ;
F_60 ( V_207 , ~ V_169 & 0x00007FFF ) ;
F_60 ( V_208 , ~ V_169 & 0x00007FFF ) ;
F_68 () ;
F_8 ( 10 ) ;
if ( V_6 -> V_200 ) {
* V_67 = 5 ;
break;
}
}
}
F_60 ( V_207 , 0xFFFFFFFF ) ;
F_68 () ;
F_8 ( 10 ) ;
F_69 ( V_199 , V_2 ) ;
return * V_67 ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_136 * V_137 = & V_6 -> V_210 ;
struct V_139 * V_140 = & V_6 -> V_211 ;
struct V_212 * V_131 = V_6 -> V_131 ;
int V_112 ;
if ( V_137 -> V_213 && V_137 -> V_214 ) {
for ( V_112 = 0 ; V_112 < V_137 -> V_150 ; V_112 ++ ) {
if ( V_137 -> V_214 [ V_112 ] . V_215 )
F_71 ( & V_131 -> V_216 ,
V_137 -> V_214 [ V_112 ] . V_215 ,
V_137 -> V_214 [ V_112 ] . V_217 ,
V_218 ) ;
if ( V_137 -> V_214 [ V_112 ] . V_219 )
F_72 ( V_137 -> V_214 [ V_112 ] . V_219 ) ;
}
}
if ( V_140 -> V_213 && V_140 -> V_214 ) {
for ( V_112 = 0 ; V_112 < V_140 -> V_150 ; V_112 ++ ) {
if ( V_140 -> V_214 [ V_112 ] . V_215 )
F_71 ( & V_131 -> V_216 ,
V_140 -> V_214 [ V_112 ] . V_215 ,
V_140 -> V_214 [ V_112 ] . V_217 ,
V_220 ) ;
if ( V_140 -> V_214 [ V_112 ] . V_219 )
F_72 ( V_140 -> V_214 [ V_112 ] . V_219 ) ;
}
}
if ( V_137 -> V_213 ) {
F_73 ( & V_131 -> V_216 , V_137 -> V_221 , V_137 -> V_213 ,
V_137 -> V_215 ) ;
V_137 -> V_213 = NULL ;
}
if ( V_140 -> V_213 ) {
F_73 ( & V_131 -> V_216 , V_140 -> V_221 , V_140 -> V_213 ,
V_140 -> V_215 ) ;
V_140 -> V_213 = NULL ;
}
F_35 ( V_137 -> V_214 ) ;
V_137 -> V_214 = NULL ;
F_35 ( V_140 -> V_214 ) ;
V_140 -> V_214 = NULL ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_136 * V_137 = & V_6 -> V_210 ;
struct V_139 * V_140 = & V_6 -> V_211 ;
struct V_212 * V_131 = V_6 -> V_131 ;
T_1 V_222 ;
int V_112 , V_111 ;
if ( ! V_137 -> V_150 )
V_137 -> V_150 = V_223 ;
V_137 -> V_214 = F_45 ( V_137 -> V_150 , sizeof( struct V_224 ) ,
V_117 ) ;
if ( ! V_137 -> V_214 ) {
V_111 = 1 ;
goto V_225;
}
V_137 -> V_221 = V_137 -> V_150 * sizeof( struct V_226 ) ;
V_137 -> V_221 = F_48 ( V_137 -> V_221 , 4096 ) ;
V_137 -> V_213 = F_75 ( & V_131 -> V_216 , V_137 -> V_221 , & V_137 -> V_215 ,
V_117 ) ;
if ( ! V_137 -> V_213 ) {
V_111 = 2 ;
goto V_225;
}
memset ( V_137 -> V_213 , 0 , V_137 -> V_221 ) ;
V_137 -> V_227 = V_137 -> V_228 = 0 ;
F_60 ( V_191 , ( ( T_5 ) V_137 -> V_215 & 0x00000000FFFFFFFF ) ) ;
F_60 ( V_188 , ( ( T_5 ) V_137 -> V_215 >> 32 ) ) ;
F_60 ( V_83 , V_137 -> V_150 * sizeof( struct V_226 ) ) ;
F_60 ( V_84 , 0 ) ;
F_60 ( V_85 , 0 ) ;
F_60 ( V_82 , V_229 | V_230 |
V_231 << V_232 |
V_233 << V_234 ) ;
for ( V_112 = 0 ; V_112 < V_137 -> V_150 ; V_112 ++ ) {
struct V_226 * V_235 = F_76 ( * V_137 , V_112 ) ;
struct V_236 * V_219 ;
unsigned int V_221 = 1024 ;
V_219 = F_77 ( V_221 , V_117 ) ;
if ( ! V_219 ) {
V_111 = 3 ;
goto V_225;
}
F_78 ( V_219 , V_221 ) ;
V_137 -> V_214 [ V_112 ] . V_219 = V_219 ;
V_137 -> V_214 [ V_112 ] . V_217 = V_219 -> V_113 ;
V_137 -> V_214 [ V_112 ] . V_215 =
F_79 ( & V_131 -> V_216 , V_219 -> V_67 , V_219 -> V_113 ,
V_218 ) ;
V_235 -> V_237 = F_80 ( V_137 -> V_214 [ V_112 ] . V_215 ) ;
V_235 -> V_238 . V_67 = F_81 ( V_219 -> V_113 ) ;
V_235 -> V_238 . V_67 |= F_81 ( V_239 |
V_240 |
V_241 ) ;
V_235 -> V_242 . V_67 = 0 ;
}
if ( ! V_140 -> V_150 )
V_140 -> V_150 = V_243 ;
V_140 -> V_214 = F_45 ( V_140 -> V_150 , sizeof( struct V_224 ) ,
V_117 ) ;
if ( ! V_140 -> V_214 ) {
V_111 = 4 ;
goto V_225;
}
V_140 -> V_221 = V_140 -> V_150 * sizeof( struct V_244 ) ;
V_140 -> V_213 = F_75 ( & V_131 -> V_216 , V_140 -> V_221 , & V_140 -> V_215 ,
V_117 ) ;
if ( ! V_140 -> V_213 ) {
V_111 = 5 ;
goto V_225;
}
memset ( V_140 -> V_213 , 0 , V_140 -> V_221 ) ;
V_140 -> V_227 = V_140 -> V_228 = 0 ;
V_222 = F_3 ( V_77 ) ;
F_60 ( V_77 , V_222 & ~ V_245 ) ;
F_60 ( V_189 , ( ( T_5 ) V_140 -> V_215 & 0xFFFFFFFF ) ) ;
F_60 ( V_184 , ( ( T_5 ) V_140 -> V_215 >> 32 ) ) ;
F_60 ( V_78 , V_140 -> V_221 ) ;
F_60 ( V_79 , 0 ) ;
F_60 ( V_80 , 0 ) ;
V_222 = V_245 | V_246 | V_247 |
V_248 | V_249 |
( V_8 -> V_250 << V_251 ) ;
F_60 ( V_77 , V_222 ) ;
for ( V_112 = 0 ; V_112 < V_140 -> V_150 ; V_112 ++ ) {
struct V_244 * V_252 = F_82 ( * V_140 , V_112 ) ;
struct V_236 * V_219 ;
V_219 = F_77 ( V_253 + V_254 , V_117 ) ;
if ( ! V_219 ) {
V_111 = 6 ;
goto V_225;
}
F_83 ( V_219 , V_254 ) ;
V_140 -> V_214 [ V_112 ] . V_219 = V_219 ;
V_140 -> V_214 [ V_112 ] . V_217 = V_253 ;
V_140 -> V_214 [ V_112 ] . V_215 =
F_79 ( & V_131 -> V_216 , V_219 -> V_67 ,
V_253 , V_220 ) ;
V_252 -> V_237 = F_80 ( V_140 -> V_214 [ V_112 ] . V_215 ) ;
memset ( V_219 -> V_67 , 0x00 , V_219 -> V_113 ) ;
}
return 0 ;
V_225:
F_70 ( V_6 ) ;
return V_111 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
F_28 ( V_8 , 29 , 0x001F ) ;
F_28 ( V_8 , 30 , 0x8FFC ) ;
F_28 ( V_8 , 29 , 0x001A ) ;
F_28 ( V_8 , 30 , 0x8FF0 ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_255 ;
F_29 ( V_8 , V_256 , & V_255 ) ;
V_255 |= V_257 ;
F_28 ( V_8 ,
V_256 , V_255 ) ;
F_29 ( V_8 , V_97 , & V_255 ) ;
V_255 |= V_258 ;
F_28 ( V_8 ,
V_97 , V_255 ) ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_259 ;
T_2 V_255 ;
V_259 = F_3 ( V_76 ) ;
V_259 |= ( V_260 |
V_261 |
V_262 |
V_263 |
V_264 ) ;
F_60 ( V_76 , V_259 ) ;
F_29 ( V_8 , V_97 , & V_255 ) ;
V_255 &= ~ V_265 ;
F_28 ( V_8 , V_97 , V_255 ) ;
F_87 ( V_8 ) ;
F_85 ( V_6 ) ;
F_28 ( V_8 , V_266 , 0x8100 ) ;
F_88 ( 500 ) ;
F_85 ( V_6 ) ;
F_84 ( V_6 ) ;
F_29 ( V_8 , V_266 , & V_255 ) ;
V_255 |= V_267 ;
F_28 ( V_8 , V_266 , V_255 ) ;
F_85 ( V_6 ) ;
F_29 ( V_8 , V_266 , & V_255 ) ;
if ( V_255 != 0x4100 )
return 9 ;
F_29 ( V_8 , V_256 , & V_255 ) ;
if ( V_255 != 0x0070 )
return 10 ;
F_29 ( V_8 , 29 , & V_255 ) ;
if ( V_255 != 0x001A )
return 11 ;
return 0 ;
}
static int F_89 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_259 = 0 ;
T_1 V_268 = 0 ;
V_8 -> V_21 = false ;
if ( V_8 -> V_87 == V_269 ) {
F_28 ( V_8 ,
V_97 , 0x0808 ) ;
F_28 ( V_8 , V_266 , 0x9140 ) ;
F_28 ( V_8 , V_266 , 0x8140 ) ;
}
V_259 = F_3 ( V_76 ) ;
F_28 ( V_8 , V_266 , 0x4140 ) ;
V_259 = F_3 ( V_76 ) ;
V_259 &= ~ V_270 ;
V_259 |= ( V_261 |
V_262 |
V_263 |
V_264 ) ;
if ( V_8 -> V_9 == V_10 &&
V_8 -> V_87 == V_269 )
V_259 |= V_260 ;
else {
V_268 = F_3 ( V_38 ) ;
if ( ( V_268 & V_271 ) == 0 )
V_259 |= ( V_260 | V_272 ) ;
}
F_60 ( V_76 , V_259 ) ;
if ( V_8 -> V_87 == V_269 )
F_84 ( V_6 ) ;
F_88 ( 500 ) ;
return 0 ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_255 = 0 ;
T_2 V_150 = 0 ;
switch ( V_8 -> V_28 ) {
case V_29 :
if ( V_8 -> V_9 == V_10 ) {
while ( F_86 ( V_6 ) &&
V_150 ++ < 10 ) ;
if ( V_150 < 11 )
return 0 ;
}
break;
case V_143 :
case V_102 :
case V_37 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
return F_89 ( V_6 ) ;
break;
default:
F_29 ( V_8 , V_266 , & V_255 ) ;
V_255 |= V_267 ;
F_28 ( V_8 , V_266 , V_255 ) ;
return 0 ;
break;
}
return 8 ;
}
static int F_91 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_222 ;
if ( V_8 -> V_9 == V_46 ||
V_8 -> V_9 == V_280 ) {
switch ( V_8 -> V_28 ) {
case V_37 :
case V_274 :
case V_273 :
case V_275 :
return F_90 ( V_6 ) ;
break;
default:
V_222 = F_3 ( V_77 ) ;
V_222 |= V_281 ;
F_60 ( V_77 , V_222 ) ;
return 0 ;
}
} else if ( V_8 -> V_9 == V_10 )
return F_90 ( V_6 ) ;
return 7 ;
}
static void F_92 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_222 ;
T_2 V_255 ;
V_222 = F_3 ( V_77 ) ;
V_222 &= ~ ( V_281 | V_282 ) ;
F_60 ( V_77 , V_222 ) ;
switch ( V_8 -> V_28 ) {
case V_37 :
case V_274 :
case V_273 :
case V_275 :
default:
V_8 -> V_21 = true ;
F_29 ( V_8 , V_266 , & V_255 ) ;
if ( V_255 & V_267 ) {
V_255 &= ~ V_267 ;
F_28 ( V_8 , V_266 , V_255 ) ;
F_87 ( V_8 ) ;
}
break;
}
}
static void F_93 ( struct V_236 * V_219 ,
unsigned int V_283 )
{
memset ( V_219 -> V_67 , 0xFF , V_283 ) ;
V_283 &= ~ 1 ;
memset ( & V_219 -> V_67 [ V_283 / 2 ] , 0xAA , V_283 / 2 - 1 ) ;
memset ( & V_219 -> V_67 [ V_283 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_219 -> V_67 [ V_283 / 2 + 12 ] , 0xAF , 1 ) ;
}
static int F_94 ( struct V_236 * V_219 ,
unsigned int V_283 )
{
V_283 &= ~ 1 ;
if ( * ( V_219 -> V_67 + 3 ) == 0xFF ) {
if ( ( * ( V_219 -> V_67 + V_283 / 2 + 10 ) == 0xBE ) &&
( * ( V_219 -> V_67 + V_283 / 2 + 12 ) == 0xAF ) ) {
return 0 ;
}
}
return 13 ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_136 * V_137 = & V_6 -> V_210 ;
struct V_139 * V_140 = & V_6 -> V_211 ;
struct V_212 * V_131 = V_6 -> V_131 ;
int V_112 , V_284 , V_285 , V_286 , V_287 , V_288 , V_111 = 0 ;
unsigned long time ;
F_60 ( V_80 , V_140 -> V_150 - 1 ) ;
if ( V_140 -> V_150 <= V_137 -> V_150 )
V_287 = ( ( V_137 -> V_150 / 64 ) * 2 ) + 1 ;
else
V_287 = ( ( V_140 -> V_150 / 64 ) * 2 ) + 1 ;
V_285 = V_286 = 0 ;
for ( V_284 = 0 ; V_284 <= V_287 ; V_284 ++ ) {
for ( V_112 = 0 ; V_112 < 64 ; V_112 ++ ) {
F_93 ( V_137 -> V_214 [ V_112 ] . V_219 ,
1024 ) ;
F_96 ( & V_131 -> V_216 ,
V_137 -> V_214 [ V_285 ] . V_215 ,
V_137 -> V_214 [ V_285 ] . V_217 ,
V_218 ) ;
if ( F_97 ( ++ V_285 == V_137 -> V_150 ) ) V_285 = 0 ;
}
F_60 ( V_85 , V_285 ) ;
F_68 () ;
F_8 ( 200 ) ;
time = V_289 ;
V_288 = 0 ;
do {
F_98 ( & V_131 -> V_216 ,
V_140 -> V_214 [ V_286 ] . V_215 ,
V_140 -> V_214 [ V_286 ] . V_217 ,
V_220 ) ;
V_111 = F_94 (
V_140 -> V_214 [ V_286 ] . V_219 ,
1024 ) ;
if ( ! V_111 )
V_288 ++ ;
if ( F_97 ( ++ V_286 == V_140 -> V_150 ) ) V_286 = 0 ;
} while ( V_288 < 64 && V_289 < ( time + 20 ) );
if ( V_288 != 64 ) {
V_111 = 13 ;
break;
}
if ( V_289 >= ( time + 2 ) ) {
V_111 = 14 ;
break;
}
}
return V_111 ;
}
static int F_99 ( struct V_5 * V_6 , T_5 * V_67 )
{
* V_67 = F_74 ( V_6 ) ;
if ( * V_67 )
goto V_290;
* V_67 = F_91 ( V_6 ) ;
if ( * V_67 )
goto V_291;
* V_67 = F_95 ( V_6 ) ;
F_92 ( V_6 ) ;
V_291:
F_70 ( V_6 ) ;
V_290:
return * V_67 ;
}
static int F_100 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_67 = 0 ;
if ( V_8 -> V_9 == V_280 ) {
int V_112 = 0 ;
V_8 -> V_292 = false ;
do {
F_101 ( V_8 ) ;
if ( V_8 -> V_292 )
return * V_67 ;
F_8 ( 20 ) ;
} while ( V_112 ++ < 3750 );
* V_67 = 1 ;
} else {
F_101 ( V_8 ) ;
if ( V_8 -> V_21 )
F_8 ( 4000 ) ;
if ( ! ( F_3 ( V_38 ) & V_39 ) ) {
* V_67 = 1 ;
}
}
return * V_67 ;
}
static int F_102 ( struct V_1 * V_2 , int V_293 )
{
switch ( V_293 ) {
case V_294 :
return V_295 ;
case V_296 :
return V_297 ;
default:
return - V_122 ;
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_298 * V_299 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
bool V_300 = F_12 ( V_2 ) ;
F_104 ( V_301 , & V_6 -> V_50 ) ;
if ( V_299 -> V_50 == V_302 ) {
T_2 V_23 = V_8 -> V_23 ;
T_3 V_303 = V_8 -> V_303 ;
T_3 V_21 = V_8 -> V_21 ;
F_67 ( V_8 , L_9 ) ;
if ( F_100 ( V_6 , & V_67 [ 4 ] ) )
V_299 -> V_50 |= V_304 ;
if ( V_300 )
F_105 ( V_2 ) ;
else
F_15 ( V_6 ) ;
if ( F_59 ( V_6 , & V_67 [ 0 ] ) )
V_299 -> V_50 |= V_304 ;
F_15 ( V_6 ) ;
if ( F_63 ( V_6 , & V_67 [ 1 ] ) )
V_299 -> V_50 |= V_304 ;
F_15 ( V_6 ) ;
if ( F_65 ( V_6 , & V_67 [ 2 ] ) )
V_299 -> V_50 |= V_304 ;
F_15 ( V_6 ) ;
F_106 ( V_6 ) ;
if ( F_99 ( V_6 , & V_67 [ 3 ] ) )
V_299 -> V_50 |= V_304 ;
V_8 -> V_23 = V_23 ;
V_8 -> V_303 = V_303 ;
V_8 -> V_21 = V_21 ;
F_15 ( V_6 ) ;
F_11 ( V_301 , & V_6 -> V_50 ) ;
if ( V_300 )
F_107 ( V_2 ) ;
} else {
F_67 ( V_8 , L_10 ) ;
if ( F_100 ( V_6 , & V_67 [ 4 ] ) )
V_299 -> V_50 |= V_304 ;
V_67 [ 0 ] = 0 ;
V_67 [ 1 ] = 0 ;
V_67 [ 2 ] = 0 ;
V_67 [ 3 ] = 0 ;
F_11 ( V_301 , & V_6 -> V_50 ) ;
}
F_108 ( 4 * 1000 ) ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_305 * V_306 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
int V_63 = 1 ;
switch ( V_8 -> V_75 ) {
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
V_306 -> V_11 = 0 ;
break;
case V_316 :
case V_317 :
if ( F_3 ( V_38 ) & V_318 ) {
V_306 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
break;
case V_319 :
if ( ! V_6 -> V_320 ) {
V_306 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
break;
default:
if ( F_3 ( V_38 ) & V_318 &&
! V_6 -> V_321 ) {
V_306 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
}
return V_63 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_305 * V_306 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_306 -> V_11 = V_322 | V_323 |
V_324 | V_325 ;
V_306 -> V_326 = 0 ;
if ( F_109 ( V_6 , V_306 ) ||
! F_111 ( & V_6 -> V_131 -> V_216 ) )
return;
switch ( V_8 -> V_75 ) {
case V_319 :
V_306 -> V_11 &= ~ V_322 ;
if ( V_6 -> V_306 & V_327 )
F_57 ( V_175 , L_11
L_12 ) ;
break;
default:
break;
}
if ( V_6 -> V_306 & V_327 )
V_306 -> V_326 |= V_322 ;
if ( V_6 -> V_306 & V_328 )
V_306 -> V_326 |= V_323 ;
if ( V_6 -> V_306 & V_329 )
V_306 -> V_326 |= V_324 ;
if ( V_6 -> V_306 & V_330 )
V_306 -> V_326 |= V_325 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_305 * V_306 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_306 -> V_326 & ( V_331 | V_332 | V_333 ) )
return - V_122 ;
if ( F_109 ( V_6 , V_306 ) ||
! F_111 ( & V_6 -> V_131 -> V_216 ) )
return V_306 -> V_326 ? - V_122 : 0 ;
switch ( V_8 -> V_75 ) {
case V_319 :
if ( V_306 -> V_326 & V_322 ) {
F_57 ( V_175 , L_11
L_12 ) ;
return - V_122 ;
}
break;
default:
break;
}
V_6 -> V_306 = 0 ;
if ( V_306 -> V_326 & V_322 )
V_6 -> V_306 |= V_327 ;
if ( V_306 -> V_326 & V_323 )
V_6 -> V_306 |= V_328 ;
if ( V_306 -> V_326 & V_324 )
V_6 -> V_306 |= V_329 ;
if ( V_306 -> V_326 & V_325 )
V_6 -> V_306 |= V_330 ;
F_113 ( & V_6 -> V_131 -> V_216 , V_6 -> V_306 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
enum V_334 V_335 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
switch ( V_335 ) {
case V_336 :
F_115 ( V_8 ) ;
return 2 ;
case V_337 :
F_116 ( V_8 ) ;
break;
case V_338 :
F_117 ( V_8 ) ;
break;
case V_339 :
F_118 ( V_8 ) ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_340 * V_341 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_28 < V_37 )
return - V_122 ;
if ( V_6 -> V_342 <= 4 )
V_341 -> V_343 = V_6 -> V_342 ;
else
V_341 -> V_343 = 1000000 / V_6 -> V_342 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_340 * V_341 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_28 < V_37 )
return - V_122 ;
if ( ( V_341 -> V_343 > V_344 ) ||
( ( V_341 -> V_343 > 4 ) &&
( V_341 -> V_343 < V_345 ) ) ||
( V_341 -> V_343 == 2 ) )
return - V_52 ;
if ( V_341 -> V_343 == 4 ) {
V_6 -> V_346 = V_6 -> V_342 = 4 ;
} else if ( V_341 -> V_343 <= 3 ) {
V_6 -> V_346 = 20000 ;
V_6 -> V_342 = V_341 -> V_343 ;
} else {
V_6 -> V_346 = ( 1000000 / V_341 -> V_343 ) ;
V_6 -> V_342 = V_6 -> V_346 & ~ 3 ;
}
if ( V_6 -> V_342 != 0 )
F_60 ( V_347 , 1000000000 / ( V_6 -> V_346 * 256 ) ) ;
else
F_60 ( V_347 , 0 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_12 ( V_2 ) )
F_122 ( V_6 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_348 * V_349 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_112 ;
char * V_70 = NULL ;
F_124 ( V_6 ) ;
for ( V_112 = 0 ; V_112 < V_350 ; V_112 ++ ) {
switch ( V_351 [ V_112 ] . type ) {
case V_352 :
V_70 = ( char * ) V_2 +
V_351 [ V_112 ] . V_353 ;
break;
case V_354 :
V_70 = ( char * ) V_6 +
V_351 [ V_112 ] . V_353 ;
break;
}
V_67 [ V_112 ] = ( V_351 [ V_112 ] . V_355 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_70 : * ( T_1 * ) V_70 ;
}
}
static void F_125 ( struct V_1 * V_2 , T_1 V_356 ,
T_3 * V_67 )
{
T_3 * V_70 = V_67 ;
int V_112 ;
switch ( V_356 ) {
case V_294 :
memcpy ( V_67 , * V_357 ,
sizeof( V_357 ) ) ;
break;
case V_296 :
for ( V_112 = 0 ; V_112 < V_350 ; V_112 ++ ) {
memcpy ( V_70 , V_351 [ V_112 ] . V_358 ,
V_359 ) ;
V_70 += V_359 ;
}
break;
}
}
void F_126 ( struct V_1 * V_2 )
{
F_127 ( V_2 , & V_360 ) ;
}
