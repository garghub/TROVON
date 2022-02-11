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
static int F_24 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_66 = V_67 ;
if ( F_12 ( V_2 ) )
F_25 ( V_6 ) ;
else
F_15 ( V_6 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
return ( V_2 -> V_68 & V_69 ) != 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_28 < V_29 ) {
if ( ! V_67 )
return - V_52 ;
return 0 ;
}
if ( V_67 )
V_2 -> V_68 |= V_69 ;
else
V_2 -> V_68 &= ~ V_69 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( ( V_8 -> V_28 < V_70 ) ||
( V_8 -> V_28 == V_71 ) )
return V_67 ? - V_52 : 0 ;
if ( V_67 )
V_2 -> V_68 |= V_72 ;
else
V_2 -> V_68 &= ~ V_72 ;
V_2 -> V_68 &= ~ V_73 ;
F_29 ( V_74 , L_1 , V_67 ? L_2 : L_3 ) ;
V_6 -> V_75 = true ;
return 0 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_76 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_76 = V_67 ;
}
static int F_32 ( struct V_1 * V_2 )
{
#define F_33 32
return F_33 * sizeof( T_1 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_77 * V_78 ,
void * V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_80 = V_79 ;
T_2 V_81 ;
memset ( V_79 , 0 , F_33 * sizeof( T_1 ) ) ;
V_78 -> V_82 = ( 1 << 24 ) | ( V_8 -> V_83 << 16 ) | V_8 -> V_84 ;
V_80 [ 0 ] = F_3 ( V_85 ) ;
V_80 [ 1 ] = F_3 ( V_38 ) ;
V_80 [ 2 ] = F_3 ( V_86 ) ;
V_80 [ 3 ] = F_3 ( V_87 ) ;
V_80 [ 4 ] = F_3 ( V_88 ) ;
V_80 [ 5 ] = F_3 ( V_89 ) ;
V_80 [ 6 ] = F_3 ( V_90 ) ;
V_80 [ 7 ] = F_3 ( V_91 ) ;
V_80 [ 8 ] = F_3 ( V_92 ) ;
V_80 [ 9 ] = F_3 ( V_93 ) ;
V_80 [ 10 ] = F_3 ( V_94 ) ;
V_80 [ 11 ] = F_3 ( V_95 ) ;
V_80 [ 12 ] = V_8 -> V_96 ;
if ( V_8 -> V_96 == V_97 ) {
F_35 ( V_8 , V_98 ,
V_99 ) ;
F_36 ( V_8 , V_99 &
V_98 , & V_81 ) ;
V_80 [ 13 ] = ( T_1 ) V_81 ;
F_35 ( V_8 , V_98 ,
V_100 ) ;
F_36 ( V_8 , V_100 &
V_98 , & V_81 ) ;
V_80 [ 14 ] = ( T_1 ) V_81 ;
F_35 ( V_8 , V_98 ,
V_101 ) ;
F_36 ( V_8 , V_101 &
V_98 , & V_81 ) ;
V_80 [ 15 ] = ( T_1 ) V_81 ;
F_35 ( V_8 , V_98 ,
V_102 ) ;
F_36 ( V_8 , V_102 &
V_98 , & V_81 ) ;
V_80 [ 16 ] = ( T_1 ) V_81 ;
V_80 [ 17 ] = 0 ;
F_35 ( V_8 , V_98 , 0x0 ) ;
F_36 ( V_8 , V_103 &
V_98 , & V_81 ) ;
V_80 [ 18 ] = ( T_1 ) V_81 ;
F_35 ( V_8 , V_98 ,
V_104 ) ;
F_36 ( V_8 , V_104 &
V_98 , & V_81 ) ;
V_80 [ 19 ] = ( T_1 ) V_81 ;
V_80 [ 20 ] = 0 ;
V_80 [ 22 ] = 0 ;
V_80 [ 23 ] = V_80 [ 18 ] ;
F_35 ( V_8 , V_98 , 0x0 ) ;
} else {
F_36 ( V_8 , V_105 , & V_81 ) ;
V_80 [ 13 ] = ( T_1 ) V_81 ;
V_80 [ 14 ] = 0 ;
V_80 [ 15 ] = 0 ;
V_80 [ 16 ] = 0 ;
F_36 ( V_8 , V_106 , & V_81 ) ;
V_80 [ 17 ] = ( T_1 ) V_81 ;
V_80 [ 18 ] = V_80 [ 13 ] ;
V_80 [ 19 ] = 0 ;
V_80 [ 20 ] = V_80 [ 17 ] ;
V_80 [ 22 ] = V_6 -> V_107 . V_108 ;
V_80 [ 23 ] = V_80 [ 13 ] ;
}
V_80 [ 21 ] = V_6 -> V_107 . V_109 ;
F_36 ( V_8 , V_110 , & V_81 ) ;
V_80 [ 24 ] = ( T_1 ) V_81 ;
V_80 [ 25 ] = V_80 [ 24 ] ;
if ( V_8 -> V_28 >= V_111 &&
V_8 -> V_9 == V_10 ) {
V_80 [ 26 ] = F_3 ( V_112 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
return V_8 -> V_113 . V_114 * 2 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_115 * V_113 , T_3 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_117 ;
int V_118 , V_119 ;
int V_120 = 0 ;
T_2 V_121 ;
if ( V_113 -> V_122 == 0 )
return - V_52 ;
V_113 -> V_123 = V_8 -> V_124 | ( V_8 -> V_84 << 16 ) ;
V_118 = V_113 -> V_125 >> 1 ;
V_119 = ( V_113 -> V_125 + V_113 -> V_122 - 1 ) >> 1 ;
V_117 = F_39 ( sizeof( T_2 ) *
( V_119 - V_118 + 1 ) , V_126 ) ;
if ( ! V_117 )
return - V_127 ;
if ( V_8 -> V_113 . type == V_128 )
V_120 = F_40 ( V_8 , V_118 ,
V_119 - V_118 + 1 ,
V_117 ) ;
else {
for ( V_121 = 0 ; V_121 < V_119 - V_118 + 1 ; V_121 ++ ) {
V_120 = F_40 ( V_8 , V_118 + V_121 , 1 ,
& V_117 [ V_121 ] ) ;
if ( V_120 )
break;
}
}
for ( V_121 = 0 ; V_121 < V_119 - V_118 + 1 ; V_121 ++ )
F_41 ( & V_117 [ V_121 ] ) ;
memcpy ( V_116 , ( T_3 * ) V_117 + ( V_113 -> V_125 & 1 ) ,
V_113 -> V_122 ) ;
F_42 ( V_117 ) ;
return V_120 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_115 * V_113 , T_3 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_117 ;
void * V_129 ;
int V_130 , V_118 , V_119 , V_120 = 0 ;
T_2 V_121 ;
if ( V_113 -> V_122 == 0 )
return - V_131 ;
if ( V_113 -> V_123 != ( V_8 -> V_124 | ( V_8 -> V_84 << 16 ) ) )
return - V_132 ;
V_130 = V_8 -> V_113 . V_114 * 2 ;
V_118 = V_113 -> V_125 >> 1 ;
V_119 = ( V_113 -> V_125 + V_113 -> V_122 - 1 ) >> 1 ;
V_117 = F_39 ( V_130 , V_126 ) ;
if ( ! V_117 )
return - V_127 ;
V_129 = ( void * ) V_117 ;
if ( V_113 -> V_125 & 1 ) {
V_120 = F_40 ( V_8 , V_118 , 1 ,
& V_117 [ 0 ] ) ;
V_129 ++ ;
}
if ( ( ( V_113 -> V_125 + V_113 -> V_122 ) & 1 ) && ( V_120 == 0 ) ) {
V_120 = F_40 ( V_8 , V_119 , 1 ,
& V_117 [ V_119 - V_118 ] ) ;
}
for ( V_121 = 0 ; V_121 < V_119 - V_118 + 1 ; V_121 ++ )
F_41 ( & V_117 [ V_121 ] ) ;
memcpy ( V_129 , V_116 , V_113 -> V_122 ) ;
for ( V_121 = 0 ; V_121 < V_119 - V_118 + 1 ; V_121 ++ )
V_117 [ V_121 ] = F_44 ( V_117 [ V_121 ] ) ;
V_120 = F_45 ( V_8 , V_118 ,
V_119 - V_118 + 1 , V_117 ) ;
if ( ( V_120 == 0 ) && ( V_118 <= V_133 ) )
F_46 ( V_8 ) ;
F_42 ( V_117 ) ;
return V_120 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_136 [ 32 ] ;
strncpy ( V_135 -> V_137 , V_138 , 32 ) ;
strncpy ( V_135 -> V_82 , V_139 , 32 ) ;
sprintf ( V_136 , L_4 ) ;
strncpy ( V_135 -> V_140 , V_136 , 32 ) ;
strncpy ( V_135 -> V_141 , F_48 ( V_6 -> V_142 ) , 32 ) ;
V_135 -> V_143 = F_32 ( V_2 ) ;
V_135 -> V_144 = F_37 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_147 * V_148 = V_6 -> V_149 ;
struct V_150 * V_151 = V_6 -> V_152 ;
V_146 -> V_153 = ( V_28 < V_70 ) ? V_154 :
V_155 ;
V_146 -> V_156 = ( V_28 < V_70 ) ? V_157 :
V_158 ;
V_146 -> V_159 = 0 ;
V_146 -> V_160 = 0 ;
V_146 -> V_161 = V_151 -> V_162 ;
V_146 -> V_163 = V_148 -> V_162 ;
V_146 -> V_164 = 0 ;
V_146 -> V_165 = 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_147 * V_148 , * V_166 ;
struct V_150 * V_151 , * V_167 ;
int V_121 , V_168 ;
if ( ( V_146 -> V_164 ) || ( V_146 -> V_165 ) )
return - V_52 ;
while ( F_7 ( V_49 , & V_6 -> V_50 ) )
F_8 ( 1 ) ;
if ( F_12 ( V_6 -> V_2 ) )
F_13 ( V_6 ) ;
V_166 = V_6 -> V_149 ;
V_167 = V_6 -> V_152 ;
V_168 = - V_127 ;
V_148 = F_51 ( V_6 -> V_169 , sizeof( struct V_147 ) , V_126 ) ;
if ( ! V_148 )
goto V_170;
V_151 = F_51 ( V_6 -> V_171 , sizeof( struct V_150 ) , V_126 ) ;
if ( ! V_151 )
goto V_172;
V_6 -> V_149 = V_148 ;
V_6 -> V_152 = V_151 ;
V_151 -> V_162 = F_52 ( V_146 -> V_161 , ( T_1 ) V_173 ) ;
V_151 -> V_162 = F_53 ( V_151 -> V_162 , ( T_1 ) ( V_28 < V_70 ?
V_154 : V_155 ) ) ;
V_151 -> V_162 = F_54 ( V_151 -> V_162 , V_174 ) ;
V_148 -> V_162 = F_52 ( V_146 -> V_163 , ( T_1 ) V_175 ) ;
V_148 -> V_162 = F_53 ( V_148 -> V_162 , ( T_1 ) ( V_28 < V_70 ?
V_157 : V_158 ) ) ;
V_148 -> V_162 = F_54 ( V_148 -> V_162 , V_176 ) ;
for ( V_121 = 0 ; V_121 < V_6 -> V_169 ; V_121 ++ )
V_148 [ V_121 ] . V_162 = V_148 -> V_162 ;
for ( V_121 = 0 ; V_121 < V_6 -> V_171 ; V_121 ++ )
V_151 [ V_121 ] . V_162 = V_151 -> V_162 ;
if ( F_12 ( V_6 -> V_2 ) ) {
V_168 = F_55 ( V_6 ) ;
if ( V_168 )
goto V_177;
V_168 = F_56 ( V_6 ) ;
if ( V_168 )
goto V_178;
V_6 -> V_152 = V_167 ;
V_6 -> V_149 = V_166 ;
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
F_42 ( V_166 ) ;
F_42 ( V_167 ) ;
V_6 -> V_152 = V_151 ;
V_6 -> V_149 = V_148 ;
V_168 = F_14 ( V_6 ) ;
if ( V_168 )
goto V_179;
}
F_11 ( V_49 , & V_6 -> V_50 ) ;
return 0 ;
V_178:
F_57 ( V_6 ) ;
V_177:
V_6 -> V_152 = V_167 ;
V_6 -> V_149 = V_166 ;
F_42 ( V_151 ) ;
V_172:
F_42 ( V_148 ) ;
V_170:
F_14 ( V_6 ) ;
V_179:
F_11 ( V_49 , & V_6 -> V_50 ) ;
return V_168 ;
}
static bool F_59 ( struct V_5 * V_6 , T_5 * V_67 , int V_180 ,
T_1 V_181 , T_1 V_182 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
static const T_1 V_183 [] =
{ 0x5A5A5A5A , 0xA5A5A5A5 , 0x00000000 , 0xFFFFFFFF } ;
T_3 T_6 * V_184 = V_8 -> V_185 + V_180 ;
T_1 V_186 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < F_60 ( V_183 ) ; V_121 ++ ) {
F_61 ( V_182 & V_183 [ V_121 ] , V_184 ) ;
V_186 = F_62 ( V_184 ) ;
if ( V_186 != ( V_182 & V_183 [ V_121 ] & V_181 ) ) {
F_63 ( V_187 , L_5
L_6 ,
V_180 , V_186 , ( V_182 & V_183 [ V_121 ] & V_181 ) ) ;
* V_67 = V_180 ;
return true ;
}
}
return false ;
}
static bool F_64 ( struct V_5 * V_6 , T_5 * V_67 , int V_180 ,
T_1 V_181 , T_1 V_182 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_3 T_6 * V_184 = V_8 -> V_185 + V_180 ;
T_1 V_186 ;
F_61 ( V_182 & V_181 , V_184 ) ;
V_186 = F_62 ( V_184 ) ;
if ( ( V_186 & V_181 ) != ( V_182 & V_181 ) ) {
F_63 ( V_187 , L_7
L_6 ,
V_180 , ( V_186 & V_181 ) , ( V_182 & V_181 ) ) ;
* V_67 = V_180 ;
return true ;
}
return false ;
}
static int F_65 ( struct V_5 * V_6 , T_5 * V_67 )
{
T_1 V_188 , V_189 , V_190 ;
T_1 V_121 , V_191 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_191 = 0xFFFFF833 ;
V_189 = F_3 ( V_38 ) ;
V_188 = ( F_3 ( V_38 ) & V_191 ) ;
F_66 ( V_38 , V_191 ) ;
V_190 = F_3 ( V_38 ) & V_191 ;
if ( V_188 != V_190 ) {
F_63 ( V_187 , L_8
L_9 , V_190 , V_188 ) ;
* V_67 = 1 ;
return 1 ;
}
F_66 ( V_38 , V_189 ) ;
F_67 ( V_192 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_67 ( V_193 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_67 ( V_194 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_67 ( V_195 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_67 ( V_90 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_67 ( V_196 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_67 ( V_87 , 0x000FFF80 , 0x000FFFFF ) ;
F_67 ( V_88 , 0x0000FFFF , 0x0000FFFF ) ;
F_67 ( V_89 , 0x0000FFFF , 0x0000FFFF ) ;
F_67 ( V_197 , 0x0000FFF8 , 0x0000FFF8 ) ;
F_67 ( V_198 , 0x0000FFFF , 0x0000FFFF ) ;
F_67 ( V_199 , 0x3FFFFFFF , 0x3FFFFFFF ) ;
F_67 ( V_200 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_67 ( V_92 , 0x000FFF80 , 0x000FFFFF ) ;
F_68 ( V_86 , 0xFFFFFFFF , 0x00000000 ) ;
V_189 = 0x06DFB3FE ;
F_68 ( V_86 , V_189 , 0x003FFFFB ) ;
F_68 ( V_91 , 0xFFFFFFFF , 0x00000000 ) ;
if ( V_8 -> V_28 >= V_29 ) {
F_68 ( V_86 , V_189 , 0xFFFFFFFF ) ;
F_67 ( V_201 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_67 ( V_202 , 0xC000FFFF , 0x0000FFFF ) ;
F_67 ( V_203 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_67 ( V_95 , 0x0000FFFF , 0x0000FFFF ) ;
V_188 = V_204 ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
F_67 ( V_205 + ( ( ( V_121 << 1 ) + 1 ) << 2 ) , 0x8003FFFF ,
0xFFFFFFFF ) ;
}
} else {
F_68 ( V_86 , 0xFFFFFFFF , 0x01FFFFFF ) ;
F_67 ( V_201 , 0xFFFFF000 , 0xFFFFFFFF ) ;
F_67 ( V_202 , 0x0000FFFF , 0x0000FFFF ) ;
F_67 ( V_203 , 0xFFFFF000 , 0xFFFFFFFF ) ;
}
V_188 = V_206 ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ )
F_67 ( V_207 + ( V_121 << 2 ) , 0xFFFFFFFF , 0xFFFFFFFF ) ;
* V_67 = 0 ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_208 ;
T_2 V_209 = 0 ;
T_2 V_121 ;
* V_67 = 0 ;
for ( V_121 = 0 ; V_121 < ( V_133 + 1 ) ; V_121 ++ ) {
if ( ( F_40 ( V_8 , V_121 , 1 , & V_208 ) ) < 0 ) {
* V_67 = 1 ;
break;
}
V_209 += V_208 ;
}
if ( ( V_209 != ( T_2 ) V_210 ) && ! ( * V_67 ) )
* V_67 = 2 ;
return * V_67 ;
}
static T_7 F_70 ( int V_211 , void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_6 -> V_212 |= F_3 ( V_213 ) ;
return V_214 ;
}
static int F_71 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 V_181 , V_121 = 0 ;
bool V_215 = true ;
T_1 V_211 = V_6 -> V_142 -> V_211 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_67 = 0 ;
if ( ! F_72 ( V_211 , F_70 , V_216 , V_2 -> V_217 ,
V_2 ) )
V_215 = false ;
else if ( F_72 ( V_211 , F_70 , V_218 ,
V_2 -> V_217 , V_2 ) ) {
* V_67 = 1 ;
return - 1 ;
}
F_29 ( V_8 , L_10 , ( V_215 ?
L_11 : L_12 ) ) ;
F_66 ( V_219 , 0xFFFFFFFF ) ;
F_8 ( 10 ) ;
for (; V_121 < 10 ; V_121 ++ ) {
V_181 = 1 << V_121 ;
if ( ! V_215 ) {
V_6 -> V_212 = 0 ;
F_66 ( V_219 , V_181 ) ;
F_66 ( V_220 , V_181 ) ;
F_8 ( 10 ) ;
if ( V_6 -> V_212 & V_181 ) {
* V_67 = 3 ;
break;
}
}
V_6 -> V_212 = 0 ;
F_66 ( V_221 , V_181 ) ;
F_66 ( V_220 , V_181 ) ;
F_8 ( 10 ) ;
if ( ! ( V_6 -> V_212 & V_181 ) ) {
* V_67 = 4 ;
break;
}
if ( ! V_215 ) {
V_6 -> V_212 = 0 ;
F_66 ( V_219 , ~ V_181 & 0x00007FFF ) ;
F_66 ( V_220 , ~ V_181 & 0x00007FFF ) ;
F_8 ( 10 ) ;
if ( V_6 -> V_212 ) {
* V_67 = 5 ;
break;
}
}
}
F_66 ( V_219 , 0xFFFFFFFF ) ;
F_8 ( 10 ) ;
F_73 ( V_211 , V_2 ) ;
return * V_67 ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_147 * V_148 = & V_6 -> V_222 ;
struct V_150 * V_151 = & V_6 -> V_223 ;
struct V_224 * V_142 = V_6 -> V_142 ;
int V_121 ;
if ( V_148 -> V_225 && V_148 -> V_226 ) {
for ( V_121 = 0 ; V_121 < V_148 -> V_162 ; V_121 ++ ) {
if ( V_148 -> V_226 [ V_121 ] . V_227 )
F_75 ( & V_142 -> V_228 ,
V_148 -> V_226 [ V_121 ] . V_227 ,
V_148 -> V_226 [ V_121 ] . V_229 ,
V_230 ) ;
if ( V_148 -> V_226 [ V_121 ] . V_231 )
F_76 ( V_148 -> V_226 [ V_121 ] . V_231 ) ;
}
}
if ( V_151 -> V_225 && V_151 -> V_226 ) {
for ( V_121 = 0 ; V_121 < V_151 -> V_162 ; V_121 ++ ) {
if ( V_151 -> V_226 [ V_121 ] . V_227 )
F_75 ( & V_142 -> V_228 ,
V_151 -> V_226 [ V_121 ] . V_227 ,
V_151 -> V_226 [ V_121 ] . V_229 ,
V_232 ) ;
if ( V_151 -> V_226 [ V_121 ] . V_231 )
F_76 ( V_151 -> V_226 [ V_121 ] . V_231 ) ;
}
}
if ( V_148 -> V_225 ) {
F_77 ( & V_142 -> V_228 , V_148 -> V_233 , V_148 -> V_225 ,
V_148 -> V_227 ) ;
V_148 -> V_225 = NULL ;
}
if ( V_151 -> V_225 ) {
F_77 ( & V_142 -> V_228 , V_151 -> V_233 , V_151 -> V_225 ,
V_151 -> V_227 ) ;
V_151 -> V_225 = NULL ;
}
F_42 ( V_148 -> V_226 ) ;
V_148 -> V_226 = NULL ;
F_42 ( V_151 -> V_226 ) ;
V_151 -> V_226 = NULL ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_147 * V_148 = & V_6 -> V_222 ;
struct V_150 * V_151 = & V_6 -> V_223 ;
struct V_224 * V_142 = V_6 -> V_142 ;
T_1 V_234 ;
int V_121 , V_120 ;
if ( ! V_148 -> V_162 )
V_148 -> V_162 = V_235 ;
V_148 -> V_226 = F_51 ( V_148 -> V_162 , sizeof( struct V_236 ) ,
V_126 ) ;
if ( ! V_148 -> V_226 ) {
V_120 = 1 ;
goto V_237;
}
V_148 -> V_233 = V_148 -> V_162 * sizeof( struct V_238 ) ;
V_148 -> V_233 = F_54 ( V_148 -> V_233 , 4096 ) ;
V_148 -> V_225 = F_79 ( & V_142 -> V_228 , V_148 -> V_233 , & V_148 -> V_227 ,
V_126 ) ;
if ( ! V_148 -> V_225 ) {
V_120 = 2 ;
goto V_237;
}
memset ( V_148 -> V_225 , 0 , V_148 -> V_233 ) ;
V_148 -> V_239 = V_148 -> V_240 = 0 ;
F_66 ( V_203 , ( ( T_5 ) V_148 -> V_227 & 0x00000000FFFFFFFF ) ) ;
F_66 ( V_200 , ( ( T_5 ) V_148 -> V_227 >> 32 ) ) ;
F_66 ( V_92 , V_148 -> V_162 * sizeof( struct V_238 ) ) ;
F_66 ( V_93 , 0 ) ;
F_66 ( V_94 , 0 ) ;
F_66 ( V_91 , V_241 | V_242 |
V_243 << V_244 |
V_245 << V_246 ) ;
for ( V_121 = 0 ; V_121 < V_148 -> V_162 ; V_121 ++ ) {
struct V_238 * V_247 = F_80 ( * V_148 , V_121 ) ;
struct V_248 * V_231 ;
unsigned int V_233 = 1024 ;
V_231 = F_81 ( V_233 , V_126 ) ;
if ( ! V_231 ) {
V_120 = 3 ;
goto V_237;
}
F_82 ( V_231 , V_233 ) ;
V_148 -> V_226 [ V_121 ] . V_231 = V_231 ;
V_148 -> V_226 [ V_121 ] . V_229 = V_231 -> V_122 ;
V_148 -> V_226 [ V_121 ] . V_227 =
F_83 ( & V_142 -> V_228 , V_231 -> V_67 , V_231 -> V_122 ,
V_230 ) ;
V_247 -> V_249 = F_84 ( V_148 -> V_226 [ V_121 ] . V_227 ) ;
V_247 -> V_250 . V_67 = F_85 ( V_231 -> V_122 ) ;
V_247 -> V_250 . V_67 |= F_85 ( V_251 |
V_252 |
V_253 ) ;
V_247 -> V_254 . V_67 = 0 ;
}
if ( ! V_151 -> V_162 )
V_151 -> V_162 = V_255 ;
V_151 -> V_226 = F_51 ( V_151 -> V_162 , sizeof( struct V_236 ) ,
V_126 ) ;
if ( ! V_151 -> V_226 ) {
V_120 = 4 ;
goto V_237;
}
V_151 -> V_233 = V_151 -> V_162 * sizeof( struct V_256 ) ;
V_151 -> V_225 = F_79 ( & V_142 -> V_228 , V_151 -> V_233 , & V_151 -> V_227 ,
V_126 ) ;
if ( ! V_151 -> V_225 ) {
V_120 = 5 ;
goto V_237;
}
memset ( V_151 -> V_225 , 0 , V_151 -> V_233 ) ;
V_151 -> V_239 = V_151 -> V_240 = 0 ;
V_234 = F_3 ( V_86 ) ;
F_66 ( V_86 , V_234 & ~ V_257 ) ;
F_66 ( V_201 , ( ( T_5 ) V_151 -> V_227 & 0xFFFFFFFF ) ) ;
F_66 ( V_196 , ( ( T_5 ) V_151 -> V_227 >> 32 ) ) ;
F_66 ( V_87 , V_151 -> V_233 ) ;
F_66 ( V_88 , 0 ) ;
F_66 ( V_89 , 0 ) ;
V_234 = V_257 | V_258 | V_259 |
V_260 | V_261 |
( V_8 -> V_262 << V_263 ) ;
F_66 ( V_86 , V_234 ) ;
for ( V_121 = 0 ; V_121 < V_151 -> V_162 ; V_121 ++ ) {
struct V_256 * V_264 = F_86 ( * V_151 , V_121 ) ;
struct V_248 * V_231 ;
V_231 = F_81 ( V_265 + V_266 , V_126 ) ;
if ( ! V_231 ) {
V_120 = 6 ;
goto V_237;
}
F_87 ( V_231 , V_266 ) ;
V_151 -> V_226 [ V_121 ] . V_231 = V_231 ;
V_151 -> V_226 [ V_121 ] . V_229 = V_265 ;
V_151 -> V_226 [ V_121 ] . V_227 =
F_83 ( & V_142 -> V_228 , V_231 -> V_67 ,
V_265 , V_232 ) ;
V_264 -> V_249 = F_84 ( V_151 -> V_226 [ V_121 ] . V_227 ) ;
memset ( V_231 -> V_67 , 0x00 , V_231 -> V_122 ) ;
}
return 0 ;
V_237:
F_74 ( V_6 ) ;
return V_120 ;
}
static void F_88 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
F_35 ( V_8 , 29 , 0x001F ) ;
F_35 ( V_8 , 30 , 0x8FFC ) ;
F_35 ( V_8 , 29 , 0x001A ) ;
F_35 ( V_8 , 30 , 0x8FF0 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_267 ;
F_36 ( V_8 , V_268 , & V_267 ) ;
V_267 |= V_269 ;
F_35 ( V_8 ,
V_268 , V_267 ) ;
F_36 ( V_8 , V_106 , & V_267 ) ;
V_267 |= V_270 ;
F_35 ( V_8 ,
V_106 , V_267 ) ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_271 ;
T_2 V_267 ;
V_271 = F_3 ( V_85 ) ;
V_271 |= ( V_272 |
V_273 |
V_274 |
V_275 |
V_276 ) ;
F_66 ( V_85 , V_271 ) ;
F_36 ( V_8 , V_106 , & V_267 ) ;
V_267 &= ~ V_277 ;
F_35 ( V_8 , V_106 , V_267 ) ;
F_91 ( V_8 ) ;
F_89 ( V_6 ) ;
F_35 ( V_8 , V_278 , 0x8100 ) ;
F_92 ( 500 ) ;
F_89 ( V_6 ) ;
F_88 ( V_6 ) ;
F_36 ( V_8 , V_278 , & V_267 ) ;
V_267 |= V_279 ;
F_35 ( V_8 , V_278 , V_267 ) ;
F_89 ( V_6 ) ;
F_36 ( V_8 , V_278 , & V_267 ) ;
if ( V_267 != 0x4100 )
return 9 ;
F_36 ( V_8 , V_268 , & V_267 ) ;
if ( V_267 != 0x0070 )
return 10 ;
F_36 ( V_8 , 29 , & V_267 ) ;
if ( V_267 != 0x001A )
return 11 ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_271 = 0 ;
T_1 V_280 = 0 ;
V_8 -> V_21 = false ;
if ( V_8 -> V_96 == V_281 ) {
F_35 ( V_8 ,
V_106 , 0x0808 ) ;
F_35 ( V_8 , V_278 , 0x9140 ) ;
F_35 ( V_8 , V_278 , 0x8140 ) ;
}
V_271 = F_3 ( V_85 ) ;
F_35 ( V_8 , V_278 , 0x4140 ) ;
V_271 = F_3 ( V_85 ) ;
V_271 &= ~ V_282 ;
V_271 |= ( V_273 |
V_274 |
V_275 |
V_276 ) ;
if ( V_8 -> V_9 == V_10 &&
V_8 -> V_96 == V_281 )
V_271 |= V_272 ;
else {
V_280 = F_3 ( V_38 ) ;
if ( ( V_280 & V_283 ) == 0 )
V_271 |= ( V_272 | V_284 ) ;
}
F_66 ( V_85 , V_271 ) ;
if ( V_8 -> V_96 == V_281 )
F_88 ( V_6 ) ;
F_92 ( 500 ) ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_267 = 0 ;
T_2 V_162 = 0 ;
switch ( V_8 -> V_28 ) {
case V_29 :
if ( V_8 -> V_9 == V_10 ) {
while ( F_90 ( V_6 ) &&
V_162 ++ < 10 ) ;
if ( V_162 < 11 )
return 0 ;
}
break;
case V_70 :
case V_111 :
case V_37 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_71 :
case V_290 :
return F_93 ( V_6 ) ;
break;
default:
F_36 ( V_8 , V_278 , & V_267 ) ;
V_267 |= V_279 ;
F_35 ( V_8 , V_278 , V_267 ) ;
return 0 ;
break;
}
return 8 ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_234 ;
if ( V_8 -> V_9 == V_46 ||
V_8 -> V_9 == V_291 ) {
switch ( V_8 -> V_28 ) {
case V_37 :
case V_286 :
case V_285 :
case V_287 :
return F_94 ( V_6 ) ;
break;
default:
V_234 = F_3 ( V_86 ) ;
V_234 |= V_292 ;
F_66 ( V_86 , V_234 ) ;
return 0 ;
}
} else if ( V_8 -> V_9 == V_10 )
return F_94 ( V_6 ) ;
return 7 ;
}
static void F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_234 ;
T_2 V_267 ;
V_234 = F_3 ( V_86 ) ;
V_234 &= ~ ( V_292 | V_293 ) ;
F_66 ( V_86 , V_234 ) ;
switch ( V_8 -> V_28 ) {
case V_37 :
case V_286 :
case V_285 :
case V_287 :
default:
V_8 -> V_21 = true ;
F_36 ( V_8 , V_278 , & V_267 ) ;
if ( V_267 & V_279 ) {
V_267 &= ~ V_279 ;
F_35 ( V_8 , V_278 , V_267 ) ;
F_91 ( V_8 ) ;
}
break;
}
}
static void F_97 ( struct V_248 * V_231 ,
unsigned int V_294 )
{
memset ( V_231 -> V_67 , 0xFF , V_294 ) ;
V_294 &= ~ 1 ;
memset ( & V_231 -> V_67 [ V_294 / 2 ] , 0xAA , V_294 / 2 - 1 ) ;
memset ( & V_231 -> V_67 [ V_294 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_231 -> V_67 [ V_294 / 2 + 12 ] , 0xAF , 1 ) ;
}
static int F_98 ( struct V_248 * V_231 ,
unsigned int V_294 )
{
V_294 &= ~ 1 ;
if ( * ( V_231 -> V_67 + 3 ) == 0xFF ) {
if ( ( * ( V_231 -> V_67 + V_294 / 2 + 10 ) == 0xBE ) &&
( * ( V_231 -> V_67 + V_294 / 2 + 12 ) == 0xAF ) ) {
return 0 ;
}
}
return 13 ;
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_147 * V_148 = & V_6 -> V_222 ;
struct V_150 * V_151 = & V_6 -> V_223 ;
struct V_224 * V_142 = V_6 -> V_142 ;
int V_121 , V_295 , V_296 , V_297 , V_298 , V_299 , V_120 = 0 ;
unsigned long time ;
F_66 ( V_89 , V_151 -> V_162 - 1 ) ;
if ( V_151 -> V_162 <= V_148 -> V_162 )
V_298 = ( ( V_148 -> V_162 / 64 ) * 2 ) + 1 ;
else
V_298 = ( ( V_151 -> V_162 / 64 ) * 2 ) + 1 ;
V_296 = V_297 = 0 ;
for ( V_295 = 0 ; V_295 <= V_298 ; V_295 ++ ) {
for ( V_121 = 0 ; V_121 < 64 ; V_121 ++ ) {
F_97 ( V_148 -> V_226 [ V_121 ] . V_231 ,
1024 ) ;
F_100 ( & V_142 -> V_228 ,
V_148 -> V_226 [ V_296 ] . V_227 ,
V_148 -> V_226 [ V_296 ] . V_229 ,
V_230 ) ;
if ( F_101 ( ++ V_296 == V_148 -> V_162 ) ) V_296 = 0 ;
}
F_66 ( V_94 , V_296 ) ;
F_8 ( 200 ) ;
time = V_300 ;
V_299 = 0 ;
do {
F_102 ( & V_142 -> V_228 ,
V_151 -> V_226 [ V_297 ] . V_227 ,
V_151 -> V_226 [ V_297 ] . V_229 ,
V_232 ) ;
V_120 = F_98 (
V_151 -> V_226 [ V_297 ] . V_231 ,
1024 ) ;
if ( ! V_120 )
V_299 ++ ;
if ( F_101 ( ++ V_297 == V_151 -> V_162 ) ) V_297 = 0 ;
} while ( V_299 < 64 && V_300 < ( time + 20 ) );
if ( V_299 != 64 ) {
V_120 = 13 ;
break;
}
if ( V_300 >= ( time + 2 ) ) {
V_120 = 14 ;
break;
}
}
return V_120 ;
}
static int F_103 ( struct V_5 * V_6 , T_5 * V_67 )
{
* V_67 = F_78 ( V_6 ) ;
if ( * V_67 )
goto V_301;
* V_67 = F_95 ( V_6 ) ;
if ( * V_67 )
goto V_302;
* V_67 = F_99 ( V_6 ) ;
F_96 ( V_6 ) ;
V_302:
F_74 ( V_6 ) ;
V_301:
return * V_67 ;
}
static int F_104 ( struct V_5 * V_6 , T_5 * V_67 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_67 = 0 ;
if ( V_8 -> V_9 == V_291 ) {
int V_121 = 0 ;
V_8 -> V_303 = false ;
do {
F_105 ( V_8 ) ;
if ( V_8 -> V_303 )
return * V_67 ;
F_8 ( 20 ) ;
} while ( V_121 ++ < 3750 );
* V_67 = 1 ;
} else {
F_105 ( V_8 ) ;
if ( V_8 -> V_21 )
F_8 ( 4000 ) ;
if ( ! ( F_3 ( V_38 ) & V_39 ) ) {
* V_67 = 1 ;
}
}
return * V_67 ;
}
static int F_106 ( struct V_1 * V_2 , int V_304 )
{
switch ( V_304 ) {
case V_305 :
return V_306 ;
case V_307 :
return V_308 ;
default:
return - V_131 ;
}
}
static void F_107 ( struct V_1 * V_2 ,
struct V_309 * V_310 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
bool V_311 = F_12 ( V_2 ) ;
F_108 ( V_312 , & V_6 -> V_50 ) ;
if ( V_310 -> V_50 == V_313 ) {
T_2 V_23 = V_8 -> V_23 ;
T_3 V_314 = V_8 -> V_314 ;
T_3 V_21 = V_8 -> V_21 ;
F_29 ( V_8 , L_13 ) ;
if ( F_104 ( V_6 , & V_67 [ 4 ] ) )
V_310 -> V_50 |= V_315 ;
if ( V_311 )
F_109 ( V_2 ) ;
else
F_15 ( V_6 ) ;
if ( F_65 ( V_6 , & V_67 [ 0 ] ) )
V_310 -> V_50 |= V_315 ;
F_15 ( V_6 ) ;
if ( F_69 ( V_6 , & V_67 [ 1 ] ) )
V_310 -> V_50 |= V_315 ;
F_15 ( V_6 ) ;
if ( F_71 ( V_6 , & V_67 [ 2 ] ) )
V_310 -> V_50 |= V_315 ;
F_15 ( V_6 ) ;
F_110 ( V_6 ) ;
if ( F_103 ( V_6 , & V_67 [ 3 ] ) )
V_310 -> V_50 |= V_315 ;
V_8 -> V_23 = V_23 ;
V_8 -> V_314 = V_314 ;
V_8 -> V_21 = V_21 ;
F_15 ( V_6 ) ;
F_11 ( V_312 , & V_6 -> V_50 ) ;
if ( V_311 )
F_111 ( V_2 ) ;
} else {
F_29 ( V_8 , L_14 ) ;
if ( F_104 ( V_6 , & V_67 [ 4 ] ) )
V_310 -> V_50 |= V_315 ;
V_67 [ 0 ] = 0 ;
V_67 [ 1 ] = 0 ;
V_67 [ 2 ] = 0 ;
V_67 [ 3 ] = 0 ;
F_11 ( V_312 , & V_6 -> V_50 ) ;
}
F_112 ( 4 * 1000 ) ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_316 * V_317 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
int V_63 = 1 ;
switch ( V_8 -> V_84 ) {
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
V_317 -> V_11 = 0 ;
break;
case V_327 :
case V_328 :
if ( F_3 ( V_38 ) & V_329 ) {
V_317 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
break;
case V_330 :
if ( ! V_6 -> V_331 ) {
V_317 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
break;
default:
if ( F_3 ( V_38 ) & V_329 &&
! V_6 -> V_332 ) {
V_317 -> V_11 = 0 ;
break;
}
V_63 = 0 ;
}
return V_63 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_316 * V_317 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_317 -> V_11 = V_333 | V_334 |
V_335 | V_336 ;
V_317 -> V_337 = 0 ;
if ( F_113 ( V_6 , V_317 ) ||
! F_115 ( & V_6 -> V_142 -> V_228 ) )
return;
switch ( V_8 -> V_84 ) {
case V_330 :
V_317 -> V_11 &= ~ V_333 ;
if ( V_6 -> V_317 & V_338 )
F_63 ( V_187 , L_15
L_16 ) ;
break;
default:
break;
}
if ( V_6 -> V_317 & V_338 )
V_317 -> V_337 |= V_333 ;
if ( V_6 -> V_317 & V_339 )
V_317 -> V_337 |= V_334 ;
if ( V_6 -> V_317 & V_340 )
V_317 -> V_337 |= V_335 ;
if ( V_6 -> V_317 & V_341 )
V_317 -> V_337 |= V_336 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_316 * V_317 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_317 -> V_337 & ( V_342 | V_343 | V_344 ) )
return - V_131 ;
if ( F_113 ( V_6 , V_317 ) ||
! F_115 ( & V_6 -> V_142 -> V_228 ) )
return V_317 -> V_337 ? - V_131 : 0 ;
switch ( V_8 -> V_84 ) {
case V_330 :
if ( V_317 -> V_337 & V_333 ) {
F_63 ( V_187 , L_15
L_16 ) ;
return - V_131 ;
}
break;
default:
break;
}
V_6 -> V_317 = 0 ;
if ( V_317 -> V_337 & V_333 )
V_6 -> V_317 |= V_338 ;
if ( V_317 -> V_337 & V_334 )
V_6 -> V_317 |= V_339 ;
if ( V_317 -> V_337 & V_335 )
V_6 -> V_317 |= V_340 ;
if ( V_317 -> V_337 & V_336 )
V_6 -> V_317 |= V_341 ;
F_117 ( & V_6 -> V_142 -> V_228 , V_6 -> V_317 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
enum V_345 V_346 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
switch ( V_346 ) {
case V_347 :
F_119 ( V_8 ) ;
return 2 ;
case V_348 :
F_120 ( V_8 ) ;
break;
case V_349 :
F_121 ( V_8 ) ;
break;
case V_350 :
F_122 ( V_8 ) ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_28 < V_37 )
return - V_131 ;
if ( V_6 -> V_353 <= 4 )
V_352 -> V_354 = V_6 -> V_353 ;
else
V_352 -> V_354 = 1000000 / V_6 -> V_353 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_28 < V_37 )
return - V_131 ;
if ( ( V_352 -> V_354 > V_355 ) ||
( ( V_352 -> V_354 > 4 ) &&
( V_352 -> V_354 < V_356 ) ) ||
( V_352 -> V_354 == 2 ) )
return - V_52 ;
if ( V_352 -> V_354 == 4 ) {
V_6 -> V_357 = V_6 -> V_353 = 4 ;
} else if ( V_352 -> V_354 <= 3 ) {
V_6 -> V_357 = 20000 ;
V_6 -> V_353 = V_352 -> V_354 ;
} else {
V_6 -> V_357 = ( 1000000 / V_352 -> V_354 ) ;
V_6 -> V_353 = V_6 -> V_357 & ~ 3 ;
}
if ( V_6 -> V_353 != 0 )
F_66 ( V_358 , 1000000000 / ( V_6 -> V_357 * 256 ) ) ;
else
F_66 ( V_358 , 0 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_12 ( V_2 ) )
F_25 ( V_6 ) ;
return 0 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_359 * V_360 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_121 ;
char * V_79 = NULL ;
F_127 ( V_6 ) ;
for ( V_121 = 0 ; V_121 < V_361 ; V_121 ++ ) {
switch ( V_362 [ V_121 ] . type ) {
case V_363 :
V_79 = ( char * ) V_2 +
V_362 [ V_121 ] . V_364 ;
break;
case V_365 :
V_79 = ( char * ) V_6 +
V_362 [ V_121 ] . V_364 ;
break;
}
V_67 [ V_121 ] = ( V_362 [ V_121 ] . V_366 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_79 : * ( T_1 * ) V_79 ;
}
}
static void F_128 ( struct V_1 * V_2 , T_1 V_367 ,
T_3 * V_67 )
{
T_3 * V_79 = V_67 ;
int V_121 ;
switch ( V_367 ) {
case V_305 :
memcpy ( V_67 , * V_368 ,
sizeof( V_368 ) ) ;
break;
case V_307 :
for ( V_121 = 0 ; V_121 < V_361 ; V_121 ++ ) {
memcpy ( V_79 , V_362 [ V_121 ] . V_369 ,
V_370 ) ;
V_79 += V_370 ;
}
break;
}
}
void F_129 ( struct V_1 * V_2 )
{
F_130 ( V_2 , & V_371 ) ;
}
