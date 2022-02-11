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
static int F_8 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_15 < V_16 ) {
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
F_19 ( V_24 ) ;
V_2 -> V_33 . V_56 ++ ;
V_2 -> V_33 . V_57 += V_22 ;
} else {
V_2 -> V_33 . V_58 ++ ;
}
V_44:
V_6 -> V_25 = ( V_17 + 1 ) & ( V_59 - 1 ) ;
V_15 ++ ;
}
return V_15 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_26 -> V_19 + V_6 -> V_25 ;
return ! ! ( ( V_19 -> V_20 & V_27 ) && ( V_19 -> V_21 & V_28 ) ) ;
}
static int F_21 ( struct V_60 * V_61 , int V_16 )
{
struct V_5 * V_6 = F_22 ( V_61 , struct V_5 , V_61 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_62 = 0 ;
V_63:
V_62 = F_8 ( V_2 , V_62 , V_16 ) ;
if ( V_62 < V_16 ) {
int V_64 = 0 ;
F_23 ( & V_6 -> V_65 ) ;
F_24 ( V_61 ) ;
F_3 ( V_6 , V_66 , V_67 | V_68 ) ;
if ( F_20 ( V_6 ) ) {
F_3 ( V_6 , V_66 , V_67 ) ;
F_3 ( V_6 , V_69 , V_70 ) ;
V_64 = 1 ;
}
F_25 ( & V_6 -> V_65 ) ;
if ( V_64 && F_26 ( V_61 ) )
goto V_63;
}
if ( V_62 ) {
F_27 ( V_6 , V_71 , V_62 ) ;
F_27 ( V_6 , V_72 , V_62 ) ;
}
return V_62 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_73 * V_74 ;
int V_17 ;
if ( F_29 ( V_24 -> V_75 > V_46 ) ) {
V_2 -> V_33 . V_76 ++ ;
F_30 ( V_24 ) ;
return V_77 ;
}
V_17 = V_6 -> V_78 ;
V_6 -> V_78 = ( V_6 -> V_78 + 1 ) & ( V_79 - 1 ) ;
V_74 = & V_6 -> V_26 -> V_80 [ V_17 ] ;
V_74 -> V_81 = V_82 | ( V_17 << 16 ) | ( V_24 -> V_75 & 0xfff ) ;
F_14 ( V_2 -> V_2 . V_51 , V_74 -> V_52 , V_24 -> V_75 ,
V_83 ) ;
F_31 ( V_24 , V_6 -> V_84 [ V_17 ] ) ;
F_16 ( V_2 -> V_2 . V_51 , V_74 -> V_52 , V_24 -> V_75 ,
V_83 ) ;
F_30 ( V_24 ) ;
F_23 ( & V_6 -> V_85 ) ;
V_6 -> V_86 ++ ;
if ( V_6 -> V_86 == V_79 )
F_32 ( V_2 ) ;
F_25 ( & V_6 -> V_85 ) ;
F_3 ( V_6 , V_87 , 1 ) ;
return V_77 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_88 ;
V_88 = 0 ;
F_34 ( & V_6 -> V_85 ) ;
while ( 1 ) {
int V_17 ;
struct V_89 * V_90 ;
T_1 V_91 ;
V_17 = V_6 -> V_92 ;
V_90 = V_6 -> V_26 -> V_90 + V_17 ;
V_91 = V_90 -> V_91 ;
if ( ! ( V_91 & V_93 ) )
break;
V_90 -> V_91 = 0 ;
if ( V_91 & V_94 )
F_9 ( L_7 , V_91 ) ;
if ( ( V_91 & V_95 ) != V_17 )
F_9 ( L_8 , V_91 ) ;
if ( V_91 & V_96 ) {
int V_22 = V_6 -> V_26 -> V_80 [ V_17 ] . V_81 & 0xfff ;
V_2 -> V_33 . V_97 ++ ;
V_2 -> V_33 . V_98 += V_22 ;
} else {
V_2 -> V_33 . V_99 ++ ;
}
if ( V_91 & V_100 )
V_2 -> V_33 . V_101 ++ ;
if ( V_91 & V_102 )
V_2 -> V_33 . V_103 ++ ;
V_2 -> V_33 . V_104 += ( V_91 >> 16 ) & 0x1f ;
V_6 -> V_92 = ( V_17 + 1 ) & ( V_79 - 1 ) ;
if ( V_6 -> V_86 == V_79 )
V_88 = 1 ;
V_6 -> V_86 -- ;
}
F_35 ( & V_6 -> V_85 ) ;
if ( V_88 )
F_36 ( V_2 ) ;
}
static T_2 F_37 ( int V_105 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_107 ;
V_107 = F_4 ( V_6 , V_108 ) ;
if ( V_107 == 0 )
return V_109 ;
if ( V_107 & V_70 ) {
F_34 ( & V_6 -> V_65 ) ;
if ( F_12 ( F_38 ( & V_6 -> V_61 ) ) ) {
F_3 ( V_6 , V_66 , V_67 ) ;
F_39 ( & V_6 -> V_61 ) ;
}
F_35 ( & V_6 -> V_65 ) ;
}
if ( V_107 & V_110 )
F_33 ( V_2 ) ;
return V_111 ;
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_112 * V_2 = V_6 -> V_2 -> V_2 . V_51 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_59 ; V_8 ++ ) {
T_3 V_113 ;
V_113 = V_6 -> V_26 -> V_50 [ V_8 ] . V_52 ;
if ( V_113 )
F_41 ( V_2 , V_113 , V_114 , V_53 ) ;
if ( V_6 -> V_54 [ V_8 ] != NULL )
F_42 ( V_6 -> V_54 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
T_3 V_113 ;
V_113 = V_6 -> V_26 -> V_80 [ V_8 ] . V_52 ;
if ( V_113 )
F_41 ( V_2 , V_113 , V_114 , V_83 ) ;
if ( V_6 -> V_84 [ V_8 ] != NULL )
F_42 ( V_6 -> V_84 [ V_8 ] ) ;
}
F_43 ( V_2 , sizeof( struct V_115 ) , V_6 -> V_26 ,
V_6 -> V_116 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_112 * V_2 = V_6 -> V_2 -> V_2 . V_51 ;
int V_8 ;
V_6 -> V_26 = F_45 ( V_2 , sizeof( struct V_115 ) ,
& V_6 -> V_116 , V_117 ) ;
if ( V_6 -> V_26 == NULL )
return 1 ;
for ( V_8 = 0 ; V_8 < V_59 ; V_8 ++ ) {
void * V_118 ;
T_3 V_113 ;
V_118 = F_46 ( V_114 , V_117 ) ;
if ( V_118 == NULL )
goto V_44;
V_113 = F_47 ( V_2 , V_118 , V_114 , V_53 ) ;
if ( F_48 ( V_2 , V_113 ) ) {
F_42 ( V_118 ) ;
goto V_44;
}
V_6 -> V_54 [ V_8 ] = V_118 ;
V_6 -> V_26 -> V_50 [ V_8 ] . V_52 = V_113 ;
V_6 -> V_26 -> V_50 [ V_8 ] . V_119 = ( V_8 << 16 ) | V_114 ;
}
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
void * V_118 ;
T_3 V_113 ;
V_118 = F_46 ( V_114 , V_117 ) ;
if ( V_118 == NULL )
goto V_44;
V_113 = F_47 ( V_2 , V_118 , V_114 , V_83 ) ;
if ( F_48 ( V_2 , V_113 ) ) {
F_42 ( V_118 ) ;
goto V_44;
}
V_6 -> V_84 [ V_8 ] = V_118 ;
V_6 -> V_26 -> V_80 [ V_8 ] . V_52 = V_113 ;
}
return 0 ;
V_44:
F_40 ( V_6 ) ;
return 1 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_120 ;
int V_8 ;
F_3 ( V_6 , V_121 , V_122 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_121 ) & V_122 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 ) {
F_9 ( L_9 ) ;
return 1 ;
}
F_3 ( V_6 , V_121 , ( ( V_6 -> V_123 - 1 ) << 9 ) ) ;
if ( ( F_1 ( V_2 , V_6 -> V_124 . V_3 , V_125 ) & 0x0040 ) != 0 )
F_3 ( V_6 , V_121 , ( ( V_6 -> V_123 - 1 ) << 9 ) | ( 1 << 8 ) ) ;
V_120 = V_6 -> V_116 + F_50 ( struct V_115 , V_50 ) ;
F_3 ( V_6 , V_126 , V_120 ) ;
F_3 ( V_6 , V_127 , V_120 ) ;
F_27 ( V_6 , V_128 , V_59 * sizeof( struct V_48 ) ) ;
V_120 = V_6 -> V_116 + F_50 ( struct V_115 , V_19 ) ;
F_3 ( V_6 , V_129 , V_120 ) ;
F_3 ( V_6 , V_130 , V_120 ) ;
F_27 ( V_6 , V_131 , V_59 * sizeof( struct V_18 ) ) ;
V_120 = V_6 -> V_116 + F_50 ( struct V_115 , V_80 ) ;
F_3 ( V_6 , V_132 , V_120 ) ;
F_3 ( V_6 , V_133 , V_120 ) ;
F_27 ( V_6 , V_134 , V_79 * sizeof( struct V_73 ) ) ;
V_120 = V_6 -> V_116 + F_50 ( struct V_115 , V_90 ) ;
F_3 ( V_6 , V_135 , V_120 ) ;
F_3 ( V_6 , V_136 , V_120 ) ;
F_27 ( V_6 , V_137 , V_79 * sizeof( struct V_89 ) ) ;
F_3 ( V_6 , V_138 , V_139 | V_140 ) ;
F_3 ( V_6 , V_66 , V_67 | V_68 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_142 ) & V_143 ) != 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 ) {
F_9 ( L_10 ) ;
return 1 ;
}
F_3 ( V_6 , V_71 , V_59 ) ;
F_3 ( V_6 , V_72 , V_59 ) ;
F_51 ( V_6 , V_144 , V_2 -> V_145 [ 0 ] ) ;
F_51 ( V_6 , V_146 , V_2 -> V_145 [ 1 ] ) ;
F_51 ( V_6 , V_147 , V_2 -> V_145 [ 2 ] ) ;
F_51 ( V_6 , V_148 , V_2 -> V_145 [ 3 ] ) ;
F_51 ( V_6 , V_149 , V_2 -> V_145 [ 4 ] ) ;
F_51 ( V_6 , V_150 , V_2 -> V_145 [ 5 ] ) ;
F_3 ( V_6 , V_151 , 0 ) ;
F_3 ( V_6 , V_152 , ( V_46 << 16 ) | V_46 ) ;
F_3 ( V_6 , V_153 , V_154 ) ;
F_3 ( V_6 , V_155 , V_156 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_6 , V_121 , V_122 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ ) {
if ( ( F_4 ( V_6 , V_121 ) & V_122 ) == 0 )
break;
F_5 ( 1 ) ;
}
if ( V_8 == 10 )
F_9 ( L_9 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_44 ;
if ( F_44 ( V_6 ) )
return - V_157 ;
F_54 ( & V_6 -> V_61 ) ;
if ( F_49 ( V_2 ) ) {
F_55 ( & V_6 -> V_61 ) ;
F_40 ( V_6 ) ;
return - V_158 ;
}
F_56 ( & V_6 -> V_65 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_92 = 0 ;
V_6 -> V_78 = 0 ;
F_56 ( & V_6 -> V_85 ) ;
V_6 -> V_86 = 0 ;
V_44 = F_57 ( V_6 -> V_105 , F_37 , V_159 , V_2 -> V_160 , V_2 ) ;
if ( V_44 ) {
F_55 ( & V_6 -> V_61 ) ;
F_52 ( V_2 ) ;
F_40 ( V_6 ) ;
return V_44 ;
}
F_3 ( V_6 , V_141 , V_161 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_55 ( & V_6 -> V_61 ) ;
F_32 ( V_2 ) ;
F_3 ( V_6 , V_141 , 0 ) ;
F_60 ( V_6 -> V_105 , V_2 ) ;
F_52 ( V_2 ) ;
F_40 ( V_6 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_162 * V_163 , int V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_165 * V_7 = F_62 ( V_163 ) ;
return F_63 ( & V_6 -> V_124 , V_7 , V_164 , NULL ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
F_65 ( V_167 -> V_168 , V_169 , sizeof( V_167 -> V_168 ) ) ;
F_65 ( V_167 -> V_170 , V_171 , sizeof( V_167 -> V_170 ) ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_172 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_67 ( & V_6 -> V_124 , V_164 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_172 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_69 ( & V_6 -> V_124 , V_164 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_71 ( & V_6 -> V_124 ) ;
}
static T_1 F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_73 ( & V_6 -> V_124 ) ;
}
static struct V_1 * F_74 ( struct V_173 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_75 ( sizeof( struct V_5 ) ) ;
if ( V_2 == NULL )
return NULL ;
memcpy ( V_2 -> V_145 , V_7 -> V_145 , V_174 ) ;
V_2 -> V_175 = & V_176 ;
V_2 -> V_177 = & V_178 ;
V_2 -> V_179 |= V_180 | V_181 ;
return V_2 ;
}
static int F_76 ( struct V_182 * V_183 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_77 ( V_183 ) ;
if ( V_2 == NULL )
return 0 ;
F_78 ( V_183 , NULL ) ;
V_6 = F_2 ( V_2 ) ;
F_79 ( V_2 ) ;
F_40 ( V_6 ) ;
if ( V_6 -> V_184 != NULL )
F_80 ( V_6 -> V_184 ) ;
if ( V_6 -> V_185 != NULL ) {
F_81 ( V_6 -> V_185 ) ;
F_42 ( V_6 -> V_185 ) ;
}
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_182 * V_183 )
{
struct V_173 * V_7 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_186 * V_187 ;
int V_105 ;
int V_44 ;
if ( V_183 == NULL )
return - V_188 ;
V_7 = V_183 -> V_2 . V_189 ;
V_187 = F_84 ( V_183 , V_190 , 0 ) ;
V_105 = F_85 ( V_183 , 0 ) ;
if ( ! V_187 || V_105 < 0 )
return - V_191 ;
V_2 = F_74 ( V_7 ) ;
if ( V_2 == NULL ) {
V_44 = - V_157 ;
goto V_192;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
F_86 ( V_2 , & V_183 -> V_2 ) ;
F_87 ( V_2 , & V_6 -> V_61 , F_21 , 64 ) ;
F_78 ( V_183 , V_2 ) ;
V_6 -> V_185 = F_88 ( V_187 -> V_193 , F_89 ( V_187 ) ,
F_90 ( & V_183 -> V_2 ) ) ;
if ( V_6 -> V_185 == NULL ) {
F_91 ( & V_183 -> V_2 , L_11 ) ;
V_44 = - V_157 ;
goto V_192;
}
V_6 -> V_184 = F_92 ( V_187 -> V_193 , F_89 ( V_187 ) ) ;
if ( V_6 -> V_184 == NULL ) {
F_91 ( & V_183 -> V_2 , L_12 ) ;
V_44 = - V_158 ;
goto V_192;
}
V_6 -> V_105 = V_105 ;
V_6 -> V_124 . V_3 = V_7 -> V_3 ;
V_6 -> V_124 . V_194 = 0x1f ;
V_6 -> V_124 . V_195 = 0x1f ;
V_6 -> V_124 . V_2 = V_2 ;
V_6 -> V_124 . V_196 = F_1 ;
V_6 -> V_124 . V_197 = F_7 ;
V_6 -> V_123 = 40 ;
if ( F_93 ( V_2 -> V_145 ) )
F_94 ( V_2 ) ;
V_44 = F_95 ( V_2 ) ;
if ( V_44 ) {
F_91 ( & V_183 -> V_2 , L_13 ) ;
goto V_192;
}
F_96 ( V_198 L_14 ,
V_2 -> V_160 , V_6 -> V_105 , V_2 -> V_145 ) ;
return 0 ;
V_192:
F_76 ( V_183 ) ;
return V_44 ;
}
