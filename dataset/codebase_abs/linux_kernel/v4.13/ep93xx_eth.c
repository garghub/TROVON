static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
int V_8 ;
F_3 ( V_6 , V_9 , V_10 | ( V_3 << 5 ) | V_4 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_11 ) & V_12 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 ) {
F_6 ( L_1 ) ;
V_7 = 0xffff ;
} else {
V_7 = F_4 ( V_6 , V_13 ) ;
}
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_7 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_6 , V_13 , V_7 ) ;
F_3 ( V_6 , V_9 , V_14 | ( V_3 << 5 ) | V_4 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_11 ) & V_12 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 )
F_6 ( L_2 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 = 0 ;
while ( V_16 < V_15 ) {
int V_17 ;
struct V_18 * V_19 ;
T_1 V_20 ;
T_1 V_21 ;
int V_22 ;
struct V_23 * V_24 ;
V_17 = V_6 -> V_25 ;
V_19 = V_6 -> V_26 -> V_19 + V_17 ;
V_20 = V_19 -> V_20 ;
V_21 = V_19 -> V_21 ;
if ( ! ( V_20 & V_27 ) || ! ( V_21 & V_28 ) )
break;
V_19 -> V_20 = 0 ;
V_19 -> V_21 = 0 ;
if ( ! ( V_20 & V_29 ) )
F_9 ( L_3 , V_20 , V_21 ) ;
if ( ! ( V_20 & V_30 ) )
F_9 ( L_4 , V_20 , V_21 ) ;
if ( ( V_21 & V_31 ) >> 16 != V_17 )
F_9 ( L_5 , V_20 , V_21 ) ;
if ( ! ( V_20 & V_32 ) ) {
V_2 -> V_33 . V_34 ++ ;
if ( V_20 & V_35 )
V_2 -> V_33 . V_36 ++ ;
if ( V_20 & V_37 )
V_2 -> V_33 . V_38 ++ ;
if ( V_20 & ( V_39 | V_40 ) )
V_2 -> V_33 . V_41 ++ ;
if ( V_20 & V_42 )
V_2 -> V_33 . V_43 ++ ;
goto V_44;
}
V_22 = V_21 & V_45 ;
if ( V_22 > V_46 ) {
F_10 ( L_6 , V_20 , V_21 ) ;
goto V_44;
}
if ( V_20 & V_47 )
V_22 -= 4 ;
V_24 = F_11 ( V_2 , V_22 + 2 ) ;
if ( F_12 ( V_24 != NULL ) ) {
struct V_48 * V_49 = & V_6 -> V_26 -> V_50 [ V_17 ] ;
F_13 ( V_24 , 2 ) ;
F_14 ( V_2 -> V_2 . V_51 , V_49 -> V_52 ,
V_22 , V_53 ) ;
F_15 ( V_24 , V_6 -> V_54 [ V_17 ] , V_22 ) ;
F_16 ( V_2 -> V_2 . V_51 ,
V_49 -> V_52 , V_22 ,
V_53 ) ;
F_17 ( V_24 , V_22 ) ;
V_24 -> V_55 = F_18 ( V_24 , V_2 ) ;
F_19 ( & V_6 -> V_56 , V_24 ) ;
V_2 -> V_33 . V_57 ++ ;
V_2 -> V_33 . V_58 += V_22 ;
} else {
V_2 -> V_33 . V_59 ++ ;
}
V_44:
V_6 -> V_25 = ( V_17 + 1 ) & ( V_60 - 1 ) ;
V_16 ++ ;
}
return V_16 ;
}
static int F_20 ( struct V_61 * V_56 , int V_15 )
{
struct V_5 * V_6 = F_21 ( V_56 , struct V_5 , V_56 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_62 ;
V_62 = F_8 ( V_2 , V_15 ) ;
if ( V_62 < V_15 && F_22 ( V_56 , V_62 ) ) {
F_23 ( & V_6 -> V_63 ) ;
F_3 ( V_6 , V_64 , V_65 | V_66 ) ;
F_24 ( & V_6 -> V_63 ) ;
}
if ( V_62 ) {
F_25 ( V_6 , V_67 , V_62 ) ;
F_25 ( V_6 , V_68 , V_62 ) ;
}
return V_62 ;
}
static int F_26 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_69 * V_70 ;
int V_17 ;
if ( F_27 ( V_24 -> V_71 > V_46 ) ) {
V_2 -> V_33 . V_72 ++ ;
F_28 ( V_24 ) ;
return V_73 ;
}
V_17 = V_6 -> V_74 ;
V_6 -> V_74 = ( V_6 -> V_74 + 1 ) & ( V_75 - 1 ) ;
V_70 = & V_6 -> V_26 -> V_76 [ V_17 ] ;
V_70 -> V_77 = V_78 | ( V_17 << 16 ) | ( V_24 -> V_71 & 0xfff ) ;
F_14 ( V_2 -> V_2 . V_51 , V_70 -> V_52 , V_24 -> V_71 ,
V_79 ) ;
F_29 ( V_24 , V_6 -> V_80 [ V_17 ] ) ;
F_16 ( V_2 -> V_2 . V_51 , V_70 -> V_52 , V_24 -> V_71 ,
V_79 ) ;
F_28 ( V_24 ) ;
F_23 ( & V_6 -> V_81 ) ;
V_6 -> V_82 ++ ;
if ( V_6 -> V_82 == V_75 )
F_30 ( V_2 ) ;
F_24 ( & V_6 -> V_81 ) ;
F_3 ( V_6 , V_83 , 1 ) ;
return V_73 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 ;
V_84 = 0 ;
F_32 ( & V_6 -> V_81 ) ;
while ( 1 ) {
int V_17 ;
struct V_85 * V_86 ;
T_1 V_87 ;
V_17 = V_6 -> V_88 ;
V_86 = V_6 -> V_26 -> V_86 + V_17 ;
V_87 = V_86 -> V_87 ;
if ( ! ( V_87 & V_89 ) )
break;
V_86 -> V_87 = 0 ;
if ( V_87 & V_90 )
F_9 ( L_7 , V_87 ) ;
if ( ( V_87 & V_91 ) != V_17 )
F_9 ( L_8 , V_87 ) ;
if ( V_87 & V_92 ) {
int V_22 = V_6 -> V_26 -> V_76 [ V_17 ] . V_77 & 0xfff ;
V_2 -> V_33 . V_93 ++ ;
V_2 -> V_33 . V_94 += V_22 ;
} else {
V_2 -> V_33 . V_95 ++ ;
}
if ( V_87 & V_96 )
V_2 -> V_33 . V_97 ++ ;
if ( V_87 & V_98 )
V_2 -> V_33 . V_99 ++ ;
V_2 -> V_33 . V_100 += ( V_87 >> 16 ) & 0x1f ;
V_6 -> V_88 = ( V_17 + 1 ) & ( V_75 - 1 ) ;
if ( V_6 -> V_82 == V_75 )
V_84 = 1 ;
V_6 -> V_82 -- ;
}
F_33 ( & V_6 -> V_81 ) ;
if ( V_84 )
F_34 ( V_2 ) ;
}
static T_2 F_35 ( int V_101 , void * V_102 )
{
struct V_1 * V_2 = V_102 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_103 ;
V_103 = F_4 ( V_6 , V_104 ) ;
if ( V_103 == 0 )
return V_105 ;
if ( V_103 & V_106 ) {
F_32 ( & V_6 -> V_63 ) ;
if ( F_12 ( F_36 ( & V_6 -> V_56 ) ) ) {
F_3 ( V_6 , V_64 , V_65 ) ;
F_37 ( & V_6 -> V_56 ) ;
}
F_33 ( & V_6 -> V_63 ) ;
}
if ( V_103 & V_107 )
F_31 ( V_2 ) ;
return V_108 ;
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_109 * V_2 = V_6 -> V_2 -> V_2 . V_51 ;
int V_8 ;
if ( ! V_6 -> V_26 )
return;
for ( V_8 = 0 ; V_8 < V_60 ; V_8 ++ ) {
T_3 V_110 ;
V_110 = V_6 -> V_26 -> V_50 [ V_8 ] . V_52 ;
if ( V_110 )
F_39 ( V_2 , V_110 , V_111 , V_53 ) ;
F_40 ( V_6 -> V_54 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_75 ; V_8 ++ ) {
T_3 V_110 ;
V_110 = V_6 -> V_26 -> V_76 [ V_8 ] . V_52 ;
if ( V_110 )
F_39 ( V_2 , V_110 , V_111 , V_79 ) ;
F_40 ( V_6 -> V_80 [ V_8 ] ) ;
}
F_41 ( V_2 , sizeof( struct V_112 ) , V_6 -> V_26 ,
V_6 -> V_113 ) ;
V_6 -> V_26 = NULL ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_109 * V_2 = V_6 -> V_2 -> V_2 . V_51 ;
int V_8 ;
V_6 -> V_26 = F_43 ( V_2 , sizeof( struct V_112 ) ,
& V_6 -> V_113 , V_114 ) ;
if ( V_6 -> V_26 == NULL )
return 1 ;
for ( V_8 = 0 ; V_8 < V_60 ; V_8 ++ ) {
void * V_115 ;
T_3 V_110 ;
V_115 = F_44 ( V_111 , V_114 ) ;
if ( V_115 == NULL )
goto V_44;
V_110 = F_45 ( V_2 , V_115 , V_111 , V_53 ) ;
if ( F_46 ( V_2 , V_110 ) ) {
F_40 ( V_115 ) ;
goto V_44;
}
V_6 -> V_54 [ V_8 ] = V_115 ;
V_6 -> V_26 -> V_50 [ V_8 ] . V_52 = V_110 ;
V_6 -> V_26 -> V_50 [ V_8 ] . V_116 = ( V_8 << 16 ) | V_111 ;
}
for ( V_8 = 0 ; V_8 < V_75 ; V_8 ++ ) {
void * V_115 ;
T_3 V_110 ;
V_115 = F_44 ( V_111 , V_114 ) ;
if ( V_115 == NULL )
goto V_44;
V_110 = F_45 ( V_2 , V_115 , V_111 , V_79 ) ;
if ( F_46 ( V_2 , V_110 ) ) {
F_40 ( V_115 ) ;
goto V_44;
}
V_6 -> V_80 [ V_8 ] = V_115 ;
V_6 -> V_26 -> V_76 [ V_8 ] . V_52 = V_110 ;
}
return 0 ;
V_44:
F_38 ( V_6 ) ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_117 ;
int V_8 ;
F_3 ( V_6 , V_118 , V_119 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_118 ) & V_119 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 ) {
F_9 ( L_9 ) ;
return 1 ;
}
F_3 ( V_6 , V_118 , ( ( V_6 -> V_120 - 1 ) << 9 ) ) ;
if ( ( F_1 ( V_2 , V_6 -> V_121 . V_3 , V_122 ) & 0x0040 ) != 0 )
F_3 ( V_6 , V_118 , ( ( V_6 -> V_120 - 1 ) << 9 ) | ( 1 << 8 ) ) ;
V_117 = V_6 -> V_113 + F_48 ( struct V_112 , V_50 ) ;
F_3 ( V_6 , V_123 , V_117 ) ;
F_3 ( V_6 , V_124 , V_117 ) ;
F_25 ( V_6 , V_125 , V_60 * sizeof( struct V_48 ) ) ;
V_117 = V_6 -> V_113 + F_48 ( struct V_112 , V_19 ) ;
F_3 ( V_6 , V_126 , V_117 ) ;
F_3 ( V_6 , V_127 , V_117 ) ;
F_25 ( V_6 , V_128 , V_60 * sizeof( struct V_18 ) ) ;
V_117 = V_6 -> V_113 + F_48 ( struct V_112 , V_76 ) ;
F_3 ( V_6 , V_129 , V_117 ) ;
F_3 ( V_6 , V_130 , V_117 ) ;
F_25 ( V_6 , V_131 , V_75 * sizeof( struct V_69 ) ) ;
V_117 = V_6 -> V_113 + F_48 ( struct V_112 , V_86 ) ;
F_3 ( V_6 , V_132 , V_117 ) ;
F_3 ( V_6 , V_133 , V_117 ) ;
F_25 ( V_6 , V_134 , V_75 * sizeof( struct V_85 ) ) ;
F_3 ( V_6 , V_135 , V_136 | V_137 ) ;
F_3 ( V_6 , V_64 , V_65 | V_66 ) ;
F_3 ( V_6 , V_138 , 0 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_139 ) & V_140 ) != 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 ) {
F_9 ( L_10 ) ;
return 1 ;
}
F_3 ( V_6 , V_67 , V_60 ) ;
F_3 ( V_6 , V_68 , V_60 ) ;
F_49 ( V_6 , V_141 , V_2 -> V_142 [ 0 ] ) ;
F_49 ( V_6 , V_143 , V_2 -> V_142 [ 1 ] ) ;
F_49 ( V_6 , V_144 , V_2 -> V_142 [ 2 ] ) ;
F_49 ( V_6 , V_145 , V_2 -> V_142 [ 3 ] ) ;
F_49 ( V_6 , V_146 , V_2 -> V_142 [ 4 ] ) ;
F_49 ( V_6 , V_147 , V_2 -> V_142 [ 5 ] ) ;
F_3 ( V_6 , V_148 , 0 ) ;
F_3 ( V_6 , V_149 , ( V_46 << 16 ) | V_46 ) ;
F_3 ( V_6 , V_150 , V_151 ) ;
F_3 ( V_6 , V_152 , V_153 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_6 , V_118 , V_119 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_118 ) & V_119 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 )
F_9 ( L_9 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_44 ;
if ( F_42 ( V_6 ) )
return - V_154 ;
F_52 ( & V_6 -> V_56 ) ;
if ( F_47 ( V_2 ) ) {
F_53 ( & V_6 -> V_56 ) ;
F_38 ( V_6 ) ;
return - V_155 ;
}
F_54 ( & V_6 -> V_63 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_88 = 0 ;
V_6 -> V_74 = 0 ;
F_54 ( & V_6 -> V_81 ) ;
V_6 -> V_82 = 0 ;
V_44 = F_55 ( V_6 -> V_101 , F_35 , V_156 , V_2 -> V_157 , V_2 ) ;
if ( V_44 ) {
F_53 ( & V_6 -> V_56 ) ;
F_50 ( V_2 ) ;
F_38 ( V_6 ) ;
return V_44 ;
}
F_3 ( V_6 , V_138 , V_158 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_53 ( & V_6 -> V_56 ) ;
F_30 ( V_2 ) ;
F_3 ( V_6 , V_138 , 0 ) ;
F_58 ( V_6 -> V_101 , V_2 ) ;
F_50 ( V_2 ) ;
F_38 ( V_6 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_159 * V_160 , int V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_162 * V_7 = F_60 ( V_160 ) ;
return F_61 ( & V_6 -> V_121 , V_7 , V_161 , NULL ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
F_63 ( V_164 -> V_165 , V_166 , sizeof( V_164 -> V_165 ) ) ;
F_63 ( V_164 -> V_167 , V_168 , sizeof( V_164 -> V_167 ) ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_169 * V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_65 ( & V_6 -> V_121 , V_161 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_169 * V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_67 ( & V_6 -> V_121 , V_161 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_69 ( & V_6 -> V_121 ) ;
}
static T_1 F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_71 ( & V_6 -> V_121 ) ;
}
static struct V_1 * F_72 ( struct V_170 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( sizeof( struct V_5 ) ) ;
if ( V_2 == NULL )
return NULL ;
memcpy ( V_2 -> V_142 , V_7 -> V_142 , V_171 ) ;
V_2 -> V_172 = & V_173 ;
V_2 -> V_174 = & V_175 ;
V_2 -> V_176 |= V_177 | V_178 ;
return V_2 ;
}
static int F_74 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_75 ( V_180 ) ;
if ( V_2 == NULL )
return 0 ;
V_6 = F_2 ( V_2 ) ;
F_76 ( V_2 ) ;
F_38 ( V_6 ) ;
if ( V_6 -> V_181 != NULL )
F_77 ( V_6 -> V_181 ) ;
if ( V_6 -> V_182 != NULL ) {
F_78 ( V_6 -> V_182 ) ;
F_40 ( V_6 -> V_182 ) ;
}
F_79 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_179 * V_180 )
{
struct V_170 * V_7 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_183 * V_184 ;
int V_101 ;
int V_44 ;
if ( V_180 == NULL )
return - V_185 ;
V_7 = F_81 ( & V_180 -> V_2 ) ;
V_184 = F_82 ( V_180 , V_186 , 0 ) ;
V_101 = F_83 ( V_180 , 0 ) ;
if ( ! V_184 || V_101 < 0 )
return - V_187 ;
V_2 = F_72 ( V_7 ) ;
if ( V_2 == NULL ) {
V_44 = - V_154 ;
goto V_188;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
F_84 ( V_2 , & V_180 -> V_2 ) ;
F_85 ( V_2 , & V_6 -> V_56 , F_20 , 64 ) ;
F_86 ( V_180 , V_2 ) ;
V_6 -> V_182 = F_87 ( V_184 -> V_189 , F_88 ( V_184 ) ,
F_89 ( & V_180 -> V_2 ) ) ;
if ( V_6 -> V_182 == NULL ) {
F_90 ( & V_180 -> V_2 , L_11 ) ;
V_44 = - V_154 ;
goto V_188;
}
V_6 -> V_181 = F_91 ( V_184 -> V_189 , F_88 ( V_184 ) ) ;
if ( V_6 -> V_181 == NULL ) {
F_90 ( & V_180 -> V_2 , L_12 ) ;
V_44 = - V_155 ;
goto V_188;
}
V_6 -> V_101 = V_101 ;
V_6 -> V_121 . V_3 = V_7 -> V_3 ;
V_6 -> V_121 . V_190 = 0x1f ;
V_6 -> V_121 . V_191 = 0x1f ;
V_6 -> V_121 . V_2 = V_2 ;
V_6 -> V_121 . V_192 = F_1 ;
V_6 -> V_121 . V_193 = F_7 ;
V_6 -> V_120 = 40 ;
if ( F_92 ( V_2 -> V_142 ) )
F_93 ( V_2 ) ;
V_44 = F_94 ( V_2 ) ;
if ( V_44 ) {
F_90 ( & V_180 -> V_2 , L_13 ) ;
goto V_188;
}
F_95 ( V_194 L_14 ,
V_2 -> V_157 , V_6 -> V_101 , V_2 -> V_142 ) ;
return 0 ;
V_188:
F_74 ( V_180 ) ;
return V_44 ;
}
