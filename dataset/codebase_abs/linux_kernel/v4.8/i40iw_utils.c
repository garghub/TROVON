int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
bool V_4 ,
T_2 * V_5 ,
T_1 V_6 )
{
int V_7 ;
int V_8 ;
T_1 V_9 [ 4 ] ;
if ( V_4 ) {
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] = * V_3 ;
} else {
memcpy ( V_9 , V_3 , sizeof( V_9 ) ) ;
}
for ( V_7 = 0 ; ( T_1 ) V_7 < V_2 -> V_10 ; V_7 ++ )
if ( memcmp ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) == 0 )
break;
switch ( V_6 ) {
case V_12 :
if ( V_7 != V_2 -> V_10 )
return - 1 ;
V_7 = 0 ;
V_8 = F_2 ( V_2 , V_2 -> V_13 ,
V_2 -> V_10 ,
( T_1 * ) & V_7 ,
& V_2 -> V_14 ) ;
if ( V_8 )
return V_8 ;
memcpy ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) ;
F_3 ( V_2 -> V_11 [ V_7 ] . V_5 , V_5 ) ;
break;
case V_15 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
break;
case V_16 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
memset ( V_2 -> V_11 [ V_7 ] . V_3 , 0 ,
sizeof( V_2 -> V_11 [ V_7 ] . V_3 ) ) ;
F_4 ( V_2 -> V_11 [ V_7 ] . V_5 ) ;
F_5 ( V_2 , V_2 -> V_13 , V_7 ) ;
break;
default:
return - 1 ;
}
return V_7 ;
}
inline void F_6 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_20 )
{
F_7 ( V_20 , V_18 -> V_21 + V_19 ) ;
}
inline T_1 F_8 ( struct V_17 * V_18 , T_1 V_19 )
{
return F_9 ( V_18 -> V_21 + V_19 ) ;
}
int F_10 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_28 * V_29 = V_27 -> V_30 -> V_31 ;
struct V_28 * V_32 ;
struct V_28 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_36 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( V_32 != V_29 )
return V_37 ;
switch ( V_24 ) {
case V_40 :
if ( V_33 )
V_36 = F_13 (
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ) ;
else
V_36 = F_13 ( V_27 -> V_44 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_16 ) ;
return V_46 ;
case V_47 :
if ( V_33 )
V_36 = F_13 (
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ) ;
else
V_36 = F_13 ( V_27 -> V_44 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_12 ) ;
break;
case V_48 :
if ( V_33 )
V_36 = F_13 (
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ) ;
else
V_36 = F_13 ( V_27 -> V_44 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_12 ) ;
break;
default:
break;
}
return V_37 ;
}
int F_15 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_49 * V_27 = (struct V_49 * ) V_25 ;
struct V_28 * V_29 = V_27 -> V_50 -> V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_51 [ 4 ] ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
if ( V_32 != V_29 )
return V_37 ;
switch ( V_24 ) {
case V_40 :
F_16 ( V_51 , V_27 -> V_52 . V_53 . V_54 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
V_51 ,
false ,
V_16 ) ;
return V_46 ;
case V_47 :
case V_48 :
F_16 ( V_51 , V_27 -> V_52 . V_53 . V_54 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
V_51 ,
false ,
V_12 ) ;
break;
default:
break;
}
return V_37 ;
}
int F_17 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_55 * V_56 = V_25 ;
struct V_1 * V_2 ;
struct V_34 * V_57 ;
T_3 * V_58 ;
T_1 V_36 [ 4 ] ;
switch ( V_24 ) {
case V_59 :
V_57 = F_11 ( (struct V_28 * ) V_56 -> V_31 ) ;
if ( ! V_57 )
return V_37 ;
V_2 = & V_57 -> V_38 ;
V_58 = ( T_3 * ) V_56 -> V_60 ;
F_16 ( V_36 , V_58 ) ;
if ( V_56 -> V_61 & V_62 ) {
F_14 ( V_2 ,
V_56 -> V_63 ,
V_36 ,
false ,
V_12 ) ;
} else {
F_14 ( V_2 ,
V_56 -> V_63 ,
V_36 ,
false ,
V_16 ) ;
}
break;
default:
break;
}
return V_37 ;
}
struct V_64 * F_18 ( struct V_65 * V_66 , bool V_67 )
{
struct V_64 * V_68 = NULL ;
unsigned long V_69 ;
F_19 ( & V_66 -> V_70 , V_69 ) ;
if ( ! F_20 ( & V_66 -> V_71 ) ) {
V_68 = F_21 ( V_66 -> V_71 . V_72 ,
struct V_64 , V_73 ) ;
F_22 ( & V_68 -> V_73 ) ;
}
F_23 ( & V_66 -> V_70 , V_69 ) ;
if ( ! V_68 ) {
V_68 = F_24 ( sizeof( * V_68 ) , V_74 ) ;
if ( V_68 ) {
V_68 -> V_75 = true ;
F_25 ( & V_68 -> V_73 ) ;
F_26 ( & V_68 -> V_76 ) ;
}
}
if ( ! V_68 ) {
F_27 ( L_1 ) ;
return NULL ;
}
if ( V_67 ) {
F_28 ( & V_68 -> V_77 , 2 ) ;
V_68 -> V_78 = true ;
} else {
F_28 ( & V_68 -> V_77 , 1 ) ;
}
return V_68 ;
}
void F_29 ( struct V_65 * V_66 , struct V_64 * V_68 )
{
unsigned long V_69 ;
if ( V_68 -> V_75 ) {
F_30 ( V_68 ) ;
} else {
V_68 -> V_79 = false ;
V_68 -> V_80 = NULL ;
V_68 -> V_78 = false ;
F_19 ( & V_66 -> V_70 , V_69 ) ;
F_31 ( & V_68 -> V_73 , & V_66 -> V_71 ) ;
F_23 ( & V_66 -> V_70 , V_69 ) ;
}
}
void F_32 ( struct V_65 * V_66 ,
struct V_64 * V_68 )
{
if ( F_33 ( & V_68 -> V_77 ) )
F_29 ( V_66 , V_68 ) ;
}
static void F_34 ( struct V_64 * V_68 , T_1 V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_68 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) V_83 -> V_87 ;
struct V_1 * V_2 ;
T_1 V_88 = V_86 -> V_89 . V_88 ;
V_2 = V_86 -> V_2 ;
F_35 ( V_86 -> V_90 , V_2 ) ;
F_36 ( V_2 , V_86 , V_88 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_64 * V_68 )
{
struct V_91 * V_92 = & V_68 -> V_92 ;
struct V_65 * V_93 = & V_2 -> V_66 ;
bool V_94 = false ;
int V_95 = 0 ;
int V_96 = 0 ;
V_96 = F_38 ( V_68 -> V_76 ,
V_68 -> V_79 ,
V_97 ) ;
if ( ! V_96 ) {
F_27 ( L_2 ,
V_92 -> V_98 , V_96 ) ;
V_95 = - V_99 ;
F_39 ( V_2 ) ;
goto V_100;
}
V_94 = V_68 -> V_101 . error ;
if ( V_94 ) {
F_27 ( L_3 ,
V_92 -> V_98 , V_68 -> V_101 . V_102 ,
V_68 -> V_101 . V_103 ) ;
V_95 = - V_104 ;
goto V_100;
}
V_100:
F_32 ( V_93 , V_68 ) ;
return V_95 ;
}
enum V_105 F_40 ( struct V_1 * V_2 ,
struct V_64
* V_68 )
{
struct V_106 * V_31 = & V_2 -> V_107 ;
enum V_105 V_108 ;
struct V_91 * V_92 = & V_68 -> V_92 ;
int V_95 = 0 ;
V_108 = F_41 ( V_31 , V_92 ) ;
if ( V_108 ) {
F_27 ( L_4 , V_92 -> V_98 ) ;
F_29 ( & V_2 -> V_66 , V_68 ) ;
return V_108 ;
}
if ( V_68 -> V_78 )
V_95 = F_37 ( V_2 , V_68 ) ;
if ( V_95 )
V_108 = V_109 ;
return V_108 ;
}
void F_42 ( struct V_110 * V_90 )
{
F_43 ( & V_90 -> V_111 ) ;
}
void F_35 ( struct V_110 * V_90 , struct V_1 * V_2 )
{
if ( ! F_33 ( & V_90 -> V_111 ) )
return;
F_5 ( V_2 , V_2 -> V_112 , V_90 -> V_113 . V_114 ) ;
F_30 ( V_90 ) ;
}
void F_44 ( struct V_115 * V_89 )
{
struct V_85 * V_86 = (struct V_85 * ) V_89 ;
F_43 ( & V_86 -> V_77 ) ;
}
void F_45 ( struct V_115 * V_89 )
{
struct V_85 * V_86 ;
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 ;
T_1 V_88 ;
unsigned long V_69 ;
V_86 = F_46 ( V_89 ) ;
V_2 = V_86 -> V_2 ;
F_19 ( & V_2 -> V_117 , V_69 ) ;
if ( ! F_33 ( & V_86 -> V_77 ) ) {
F_23 ( & V_2 -> V_117 , V_69 ) ;
return;
}
V_88 = V_86 -> V_89 . V_88 ;
V_2 -> V_118 [ V_88 ] = NULL ;
F_23 ( & V_2 -> V_117 , V_69 ) ;
V_68 = F_18 ( & V_2 -> V_66 , false ) ;
if ( ! V_68 )
return;
V_68 -> V_80 = F_34 ;
V_68 -> V_84 = ( void * ) & V_86 -> V_119 ;
V_116 = & V_68 -> V_92 ;
V_116 -> V_98 = V_120 ;
V_116 -> V_121 = 1 ;
V_116 -> V_122 . V_123 . V_124 . V_83 = & V_86 -> V_119 ;
V_116 -> V_122 . V_123 . V_124 . V_125 = ( V_126 ) V_68 ;
V_116 -> V_122 . V_123 . V_124 . V_127 = true ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_5 ) ;
}
struct V_115 * F_47 ( struct V_128 * V_38 , int V_129 )
{
struct V_1 * V_2 = F_48 ( V_38 ) ;
if ( ( V_129 < V_130 ) || ( V_129 >= V_2 -> V_131 ) )
return NULL ;
return & V_2 -> V_118 [ V_129 ] -> V_89 ;
}
void F_49 ( struct V_106 * V_31 ,
enum V_132 V_133 ,
char * V_134 ,
T_4 * V_135 ,
T_1 V_136 )
{
T_1 V_137 ;
if ( ! ( V_31 -> V_138 & V_133 ) )
return;
F_50 ( V_31 , V_133 , L_6 , V_134 ) ;
F_50 ( V_31 , V_133 , L_7 , V_135 ,
( unsigned long long ) F_51 ( V_135 ) ) ;
for ( V_137 = 0 ; V_137 < V_136 ; V_137 += 8 )
F_50 ( V_31 , V_133 , L_8 , V_137 , V_135 [ V_137 / 8 ] ) ;
}
T_2 T_5 * F_52 ( void * V_139 )
{
struct V_106 * V_31 = (struct V_106 * ) V_139 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_53 ( struct V_140 * V_73 )
{
struct V_140 * V_141 ;
if ( F_20 ( V_73 ) )
return NULL ;
V_141 = ( void * ) V_73 -> V_72 ;
F_54 ( V_141 ) ;
return ( void * ) V_141 ;
}
enum V_105 F_55 ( struct V_17 * V_18 ,
struct V_142 * V_143 ,
T_4 V_136 ,
T_1 V_144 )
{
struct V_145 * V_146 = (struct V_145 * ) V_18 -> V_147 ;
if ( ! V_143 )
return V_148 ;
V_143 -> V_136 = F_56 ( V_136 , V_144 ) ;
V_143 -> V_149 = F_57 ( & V_146 -> V_31 , V_143 -> V_136 ,
( V_150 * ) & V_143 -> V_151 , V_152 ) ;
if ( ! V_143 -> V_149 )
return V_153 ;
return 0 ;
}
void F_58 ( struct V_17 * V_18 , struct V_142 * V_143 )
{
struct V_145 * V_146 = (struct V_145 * ) V_18 -> V_147 ;
if ( ! V_143 || ! V_143 -> V_149 )
return;
F_59 ( & V_146 -> V_31 , V_143 -> V_136 ,
V_143 -> V_149 , ( V_150 ) V_143 -> V_151 ) ;
V_143 -> V_149 = NULL ;
}
enum V_105 F_60 ( struct V_17 * V_18 ,
struct V_154 * V_143 ,
T_1 V_136 )
{
if ( ! V_143 )
return V_148 ;
V_143 -> V_136 = V_136 ;
V_143 -> V_149 = F_24 ( V_136 , V_152 ) ;
if ( V_143 -> V_149 )
return 0 ;
else
return V_153 ;
}
enum V_105 F_61 ( struct V_17 * V_18 ,
struct V_154 * V_143 )
{
if ( ! V_143 )
return V_148 ;
F_30 ( V_143 -> V_149 ) ;
return 0 ;
}
enum V_105 F_62 ( struct V_106 * V_31 ,
struct V_155 * V_156 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_153 ;
V_116 = & V_68 -> V_92 ;
memcpy ( & V_116 -> V_122 . V_123 . V_158 . V_92 , V_156 ,
sizeof( V_116 -> V_122 . V_123 . V_158 . V_92 ) ) ;
V_116 -> V_98 = V_159 ;
V_116 -> V_121 = 1 ;
V_116 -> V_122 . V_123 . V_158 . V_31 = V_31 ;
V_116 -> V_122 . V_123 . V_158 . V_125 = ( V_126 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_9 ) ;
return V_108 ;
}
void F_63 ( struct V_82 * V_83 , T_2 V_160 , T_2 V_161 , T_2 V_162 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_64 ( V_86 , V_160 , 0 , V_161 , V_162 ) ;
}
void F_65 ( struct V_82 * V_83 , int V_163 )
{
struct V_85 * V_86 ;
T_1 V_164 = V_165 ;
T_2 V_166 = 0 ;
bool V_167 ;
unsigned long V_69 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_19 ( & V_86 -> V_168 , V_69 ) ;
if ( V_86 -> V_169 ) {
V_86 -> V_169 = 0 ;
V_166 = 1 ;
}
V_167 = ! ( V_83 -> V_170 & V_171 ) ;
V_83 -> V_170 |= V_171 ;
F_23 ( & V_86 -> V_168 , V_69 ) ;
if ( V_167 ) {
if ( ! V_163 )
F_66 ( V_83 ) ;
else
V_164 = V_172 ;
F_64 ( V_86 , V_164 , V_166 , 0 , 0 ) ;
F_67 ( V_86 ) ;
}
}
static void F_68 ( unsigned long V_173 )
{
struct V_85 * V_86 = (struct V_85 * ) V_173 ;
struct V_82 * V_83 = (struct V_82 * ) & V_86 -> V_119 ;
F_65 ( V_83 , 1 ) ;
}
void F_69 ( struct V_82 * V_83 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_70 ( & V_86 -> V_174 ) ;
V_86 -> V_174 . V_175 = F_68 ;
V_86 -> V_174 . V_176 = V_177 + V_178 ;
V_86 -> V_174 . V_179 = ( unsigned long ) V_86 ;
F_71 ( & V_86 -> V_174 ) ;
}
void F_66 ( struct V_82 * V_83 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_72 ( & V_86 -> V_174 ) ;
}
static void F_73 ( struct V_180 * V_181 )
{
struct V_182 * V_183 =
& ( (struct V_184 * ) V_181 ) -> V_183 ;
if ( V_183 -> V_185 )
V_183 -> V_80 ( V_183 -> V_185 ) ;
}
void F_74 ( struct V_106 * V_31 ,
struct V_182 * V_183 ,
T_1 V_186 )
{
struct V_184 * V_181 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
V_181 = & V_2 -> V_187 [ V_186 ] ;
memcpy ( & V_181 -> V_183 , V_183 , sizeof( * V_183 ) ) ;
F_75 ( & V_181 -> V_181 , F_73 ) ;
F_76 ( V_2 -> V_188 , & V_181 -> V_181 ) ;
}
static void F_77 ( struct V_180 * V_181 )
{
struct V_64 * V_68 =
( (struct V_184 * ) V_181 ) -> V_68 ;
struct V_189 V_190 ;
struct V_191 * V_192 =
& V_68 -> V_92 . V_122 . V_123 . V_193 . V_92 ;
struct V_1 * V_2 =
(struct V_1 * ) V_68 -> V_92 . V_122 . V_123 . V_193 . V_31 -> V_157 ;
V_190 . V_66 = NULL ;
V_190 . V_102 = V_68 -> V_101 . V_102 ;
V_190 . V_103 = V_68 -> V_101 . V_103 ;
V_190 . V_194 = V_68 -> V_101 . V_194 ;
V_190 . V_195 = V_68 -> V_101 . V_195 ;
V_190 . V_125 = 0 ;
V_190 . error = V_68 -> V_101 . error ;
V_192 -> V_80 ( V_68 -> V_92 . V_122 . V_123 . V_193 . V_31 ,
V_192 -> V_196 , & V_190 ) ;
F_32 ( & V_2 -> V_66 , V_68 ) ;
}
static void F_78 ( struct V_64 * V_68 ,
T_1 V_197 )
{
struct V_184 * V_181 ;
struct V_191 * V_192 =
& V_68 -> V_92 . V_122 . V_123 . V_193 . V_92 ;
struct V_1 * V_2 =
(struct V_1 * ) V_68 -> V_92 . V_122 . V_123 . V_193 . V_31 ->
V_157 ;
if ( V_192 && V_192 -> V_80 ) {
F_50 ( & V_2 -> V_107 , V_198 , L_10 , V_199 ) ;
F_43 ( & V_68 -> V_77 ) ;
V_181 = & V_2 -> V_187 [ V_192 -> V_186 ] ;
V_181 -> V_68 = V_68 ;
F_75 ( & V_181 -> V_181 , F_77 ) ;
F_76 ( V_2 -> V_188 , & V_181 -> V_181 ) ;
F_50 ( & V_2 -> V_107 , V_198 , L_11 , V_199 ) ;
} else {
F_50 ( & V_2 -> V_107 , V_198 , L_12 , V_199 ) ;
}
}
enum V_105 F_79 ( struct V_106 * V_31 ,
struct V_191 * V_192 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
F_50 ( & V_2 -> V_107 , V_198 , L_6 , V_199 ) ;
V_68 = F_18 ( & V_2 -> V_66 , false ) ;
if ( ! V_68 )
return V_153 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_80 = F_78 ;
V_68 -> V_84 = V_192 ;
memcpy ( & V_116 -> V_122 . V_123 . V_193 . V_92 , V_192 ,
sizeof( * V_192 ) ) ;
V_116 -> V_122 . V_123 . V_193 . V_31 = V_31 ;
V_116 -> V_98 = V_200 ;
V_116 -> V_121 = 1 ;
V_116 -> V_122 . V_123 . V_193 . V_125 = ( V_126 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_13 ) ;
return V_108 ;
}
enum V_105 F_80 ( struct V_106 * V_31 ,
struct V_142 * V_201 ,
T_2 V_202 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_153 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_84 = NULL ;
V_116 -> V_122 . V_123 . V_203 . V_66 = V_31 -> V_66 ;
V_116 -> V_122 . V_123 . V_203 . V_204 = V_201 -> V_151 ;
V_116 -> V_122 . V_123 . V_203 . V_205 = V_201 -> V_149 ;
V_116 -> V_122 . V_123 . V_203 . V_202 = V_202 ;
V_116 -> V_98 = V_206 ;
V_116 -> V_121 = 1 ;
V_116 -> V_122 . V_123 . V_203 . V_125 = ( V_126 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_14 ) ;
return V_108 ;
}
enum V_105 F_81 ( struct V_106 * V_31 ,
struct V_142 * V_201 ,
T_2 V_202 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_153 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_84 = NULL ;
V_116 -> V_122 . V_123 . V_207 . V_66 = V_31 -> V_66 ;
V_116 -> V_122 . V_123 . V_207 . V_204 = V_201 -> V_151 ;
V_116 -> V_122 . V_123 . V_207 . V_205 = V_201 -> V_149 ;
V_116 -> V_122 . V_123 . V_207 . V_202 = V_202 ;
V_116 -> V_98 = V_208 ;
V_116 -> V_121 = 1 ;
V_116 -> V_122 . V_123 . V_207 . V_125 = ( V_126 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_15 ) ;
return V_108 ;
}
enum V_105 F_82 ( struct V_106 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_157 ;
int V_96 ;
F_50 ( V_31 , V_209 , L_16 ,
V_199 , __LINE__ , V_31 , V_2 ) ;
F_28 ( & V_2 -> V_210 , 2 ) ;
V_96 = F_38 ( V_2 -> V_211 ,
( F_83 ( & V_2 -> V_210 ) == 1 ) ,
V_212 ) ;
F_84 ( & V_2 -> V_210 ) ;
if ( ! V_96 ) {
F_27 ( L_17 , V_96 ) ;
F_28 ( & V_2 -> V_210 , 0 ) ;
V_31 -> V_213 = false ;
return V_214 ;
}
F_85 ( & V_31 -> V_215 ) ;
return 0 ;
}
void F_86 ( struct V_106 * V_31 , struct V_82 * V_83 )
{
struct V_216 V_92 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
F_50 ( V_31 , V_217 , L_18 , V_199 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_218 = V_219 ;
V_92 . V_220 = true ;
V_92 . V_221 = 0x3 ;
( void ) F_87 ( V_2 , V_83 , & V_92 , false ) ;
}
enum V_105 F_88 ( struct V_222 * * V_134 )
{
struct V_223 * V_224 ;
struct V_222 * V_225 ;
V_224 = F_89 ( L_19 , 0 , 0 ) ;
if ( F_90 ( V_224 ) )
return V_226 ;
V_225 = F_24 ( sizeof( * V_225 ) + F_91 ( V_224 ) ,
V_152 ) ;
if ( ! V_225 ) {
F_92 ( V_224 ) ;
return V_226 ;
}
V_225 -> V_224 = V_224 ;
* V_134 = V_225 ;
return 0 ;
}
void F_93 ( struct V_222 * V_134 )
{
if ( V_134 ) {
F_92 ( V_134 -> V_224 ) ;
F_30 ( V_134 ) ;
}
}
enum V_105 F_94 ( struct V_106 * V_31 ,
struct V_142 * V_143 )
{
enum V_105 V_108 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
V_108 = F_95 ( V_2 , V_143 , V_227 ,
V_228 ) ;
return V_108 ;
}
enum V_105 F_96 ( struct V_222 * V_134 ,
void * V_52 ,
T_1 V_229 ,
T_1 V_20 )
{
T_1 V_230 = 0 ;
int V_231 ;
enum V_105 V_232 = 0 ;
F_97 ( V_134 ) ;
V_231 = F_98 ( V_134 , V_52 , V_229 ) ;
if ( ! V_231 )
F_99 ( V_134 , ( T_2 * ) & V_230 ) ;
if ( V_230 != V_20 ) {
F_27 ( L_20 ) ;
V_232 = V_226 ;
}
return V_232 ;
}
struct V_82 * F_100 ( struct V_106 * V_31 ,
struct V_233 * V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_157 ;
struct V_85 * V_86 ;
struct V_234 * V_235 ;
T_1 V_236 [ 4 ] , V_237 [ 4 ] ;
T_6 V_238 , V_239 ;
struct V_240 * V_241 ;
struct V_242 * V_243 = (struct V_242 * ) V_135 -> V_243 ;
struct V_244 * V_245 = (struct V_244 * ) V_135 -> V_245 ;
if ( V_243 -> V_246 == 4 ) {
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
V_236 [ 0 ] = F_13 ( V_243 -> V_247 ) ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
V_237 [ 0 ] = F_13 ( V_243 -> V_248 ) ;
} else {
V_241 = (struct V_240 * ) V_135 -> V_243 ;
F_16 ( V_236 , V_241 -> V_247 . V_53 . V_54 ) ;
F_16 ( V_237 , V_241 -> V_248 . V_53 . V_54 ) ;
}
V_238 = F_101 ( V_245 -> V_249 ) ;
V_239 = F_101 ( V_245 -> V_250 ) ;
V_235 = F_102 ( & V_2 -> V_251 , V_239 , V_237 , V_238 ,
V_236 , false ) ;
if ( ! V_235 )
return NULL ;
V_86 = V_235 -> V_86 ;
return & V_86 -> V_119 ;
}
void F_103 ( struct V_233 * V_135 , T_6 V_229 , T_1 V_252 )
{
struct V_244 * V_245 ;
struct V_242 * V_243 ;
T_6 V_253 ;
T_6 V_254 ;
T_2 * V_52 = ( T_2 * ) V_135 -> V_143 . V_149 ;
V_253 = ( V_135 -> V_4 ) ? 20 : 40 ;
V_243 = (struct V_242 * ) ( V_52 + V_135 -> V_255 ) ;
V_245 = (struct V_244 * ) ( V_52 + V_135 -> V_255 + V_253 ) ;
V_254 = V_229 + V_135 -> V_256 + V_253 ;
V_243 -> V_257 = F_104 ( V_254 ) ;
V_245 -> V_258 = F_105 ( V_252 ) ;
}
enum V_105 F_106 ( struct V_259 * V_92 ,
struct V_233 * V_135 )
{
struct V_242 * V_243 ;
struct V_240 * V_241 ;
struct V_244 * V_245 ;
T_6 V_253 ;
T_6 V_260 ;
T_2 * V_143 = ( T_2 * ) V_135 -> V_143 . V_149 ;
struct V_261 * V_262 = (struct V_261 * ) V_135 -> V_143 . V_149 ;
if ( V_262 -> V_263 == F_104 ( 0x8100 ) ) {
V_92 -> V_264 = true ;
V_135 -> V_265 = F_101 ( ( (struct V_266 * ) V_262 ) -> V_267 ) & V_268 ;
}
V_135 -> V_255 = ( V_92 -> V_264 ) ? 18 : 14 ;
V_253 = ( V_92 -> V_269 ) ? 40 : 20 ;
V_135 -> V_4 = ( V_92 -> V_269 ) ? false : true ;
V_135 -> V_243 = V_143 + V_135 -> V_255 ;
V_243 = (struct V_242 * ) V_135 -> V_243 ;
V_135 -> V_245 = V_135 -> V_243 + V_253 ;
V_245 = (struct V_244 * ) V_135 -> V_245 ;
if ( V_135 -> V_4 ) {
V_260 = F_101 ( V_243 -> V_257 ) ;
} else {
V_241 = (struct V_240 * ) V_135 -> V_243 ;
V_260 = F_101 ( V_241 -> V_270 ) + V_253 ;
}
V_135 -> V_271 = V_260 + V_135 -> V_255 ;
if ( V_92 -> V_270 < V_135 -> V_271 - 4 ) {
F_27 ( L_21 ,
V_92 -> V_270 , V_135 -> V_271 ) ;
return V_272 ;
}
V_135 -> V_256 = ( V_245 -> V_273 ) << 2 ;
V_135 -> V_274 = V_260 - V_253 - V_135 -> V_256 ;
V_135 -> V_179 = ( V_135 -> V_274 ) ? V_135 -> V_245 + V_135 -> V_256 : NULL ;
V_135 -> V_275 = V_135 -> V_255 + V_253 + V_135 -> V_256 ;
V_135 -> V_252 = F_13 ( V_245 -> V_258 ) ;
return 0 ;
}
static void F_107 ( unsigned long V_31 )
{
struct V_106 * V_276 = (struct V_106 * ) V_31 ;
struct V_277 * V_278 = & V_276 -> V_279 ;
struct V_277 * V_280 = NULL ;
T_6 V_186 ;
unsigned long V_69 ;
V_278 -> V_281 . V_282 ( V_278 , & V_278 -> V_283 ) ;
for ( V_186 = 0 ; V_186 < V_284 ; V_186 ++ ) {
F_19 ( & V_278 -> V_285 , V_69 ) ;
if ( V_276 -> V_286 [ V_186 ] ) {
if ( V_276 -> V_286 [ V_186 ] -> V_287 ) {
V_280 = & V_276 -> V_286 [ V_186 ] -> V_279 ;
V_280 -> V_281 . V_282 ( V_280 , & V_280 -> V_283 ) ;
}
}
F_23 ( & V_278 -> V_285 , V_69 ) ;
}
F_108 ( & V_278 -> V_288 ,
V_177 + F_109 ( V_289 ) ) ;
}
void F_110 ( struct V_106 * V_31 )
{
struct V_277 * V_290 = & V_31 -> V_279 ;
F_70 ( & V_290 -> V_288 ) ;
V_290 -> V_288 . V_175 = F_107 ;
V_290 -> V_288 . V_179 = ( unsigned long ) V_31 ;
F_108 ( & V_290 -> V_288 ,
V_177 + F_109 ( V_289 ) ) ;
}
void F_111 ( struct V_106 * V_31 )
{
struct V_277 * V_290 = & V_31 -> V_279 ;
F_112 ( & V_290 -> V_288 ) ;
}
