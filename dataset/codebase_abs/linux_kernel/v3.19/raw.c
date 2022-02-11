void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
struct V_7 * V_8 ;
V_8 = & V_4 -> V_9 [ F_2 ( V_2 ) -> V_10 & ( V_11 - 1 ) ] ;
F_3 ( & V_4 -> V_12 ) ;
F_4 ( V_2 , V_8 ) ;
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
F_3 ( & V_4 -> V_12 ) ;
if ( F_9 ( V_2 ) )
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , - 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
static struct V_1 * F_10 ( struct V_13 * V_13 , struct V_1 * V_2 ,
unsigned short V_14 , T_1 V_15 , T_1 V_16 , int V_17 )
{
F_11 (sk) {
struct V_18 * V_19 = F_2 ( V_2 ) ;
if ( F_12 ( F_6 ( V_2 ) , V_13 ) && V_19 -> V_10 == V_14 &&
! ( V_19 -> V_20 && V_19 -> V_20 != V_15 ) &&
! ( V_19 -> V_21 && V_19 -> V_21 != V_16 ) &&
! ( V_2 -> V_22 && V_2 -> V_22 != V_17 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static int F_13 ( const struct V_1 * V_2 , const struct V_24 * V_25 )
{
struct V_26 V_27 ;
const struct V_26 * V_28 ;
V_28 = F_14 ( V_25 , F_15 ( V_25 ) ,
sizeof( V_27 ) , & V_27 ) ;
if ( ! V_28 )
return 1 ;
if ( V_28 -> type < 32 ) {
T_2 V_29 = F_16 ( V_2 ) -> V_30 . V_29 ;
return ( ( 1U << V_28 -> type ) & V_29 ) != 0 ;
}
return 0 ;
}
static int F_17 ( struct V_24 * V_25 , const struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_34 = 0 ;
struct V_13 * V_13 ;
F_18 ( & V_35 . V_12 ) ;
V_8 = & V_35 . V_9 [ V_33 ] ;
if ( F_19 ( V_8 ) )
goto V_36;
V_13 = F_20 ( V_25 -> V_37 ) ;
V_2 = F_10 ( V_13 , F_21 ( V_8 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_25 -> V_37 -> V_41 ) ;
while ( V_2 ) {
V_34 = 1 ;
if ( ( V_32 -> V_38 != V_42 || ! F_13 ( V_2 , V_25 ) ) &&
F_22 ( V_2 , V_32 -> V_40 , V_32 -> V_39 ,
V_25 -> V_37 -> V_41 ) ) {
struct V_24 * V_43 = F_23 ( V_25 , V_44 ) ;
if ( V_43 )
F_24 ( V_2 , V_43 ) ;
}
V_2 = F_10 ( V_13 , F_25 ( V_2 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_25 -> V_37 -> V_41 ) ;
}
V_36:
F_26 ( & V_35 . V_12 ) ;
return V_34 ;
}
int F_27 ( struct V_24 * V_25 , int V_38 )
{
int V_33 ;
struct V_1 * F_16 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_16 = F_28 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 && ! F_17 ( V_25 , F_29 ( V_25 ) , V_33 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_30 ( struct V_1 * V_2 , struct V_24 * V_25 , T_3 V_45 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
const int type = F_31 ( V_25 ) -> type ;
const int V_46 = F_31 ( V_25 ) -> V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( type == V_49 && V_46 == V_50 )
F_32 ( V_25 , V_2 , V_45 ) ;
else if ( type == V_51 ) {
F_33 ( V_25 , V_2 ) ;
return;
}
if ( ! V_19 -> V_52 && V_2 -> V_53 != V_54 )
return;
switch ( type ) {
default:
case V_55 :
V_47 = V_56 ;
break;
case V_57 :
return;
case V_58 :
V_47 = V_59 ;
V_48 = 1 ;
break;
case V_49 :
V_47 = V_56 ;
if ( V_46 > V_60 )
break;
V_47 = V_61 [ V_46 ] . V_62 ;
V_48 = V_61 [ V_46 ] . V_63 ;
if ( V_46 == V_50 ) {
V_48 = V_19 -> V_64 != V_65 ;
V_47 = V_66 ;
}
}
if ( V_19 -> V_52 ) {
const struct V_31 * V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
T_4 * V_67 = V_25 -> V_29 + ( V_32 -> V_68 << 2 ) ;
if ( V_19 -> V_69 )
V_67 = V_25 -> V_29 ;
F_34 ( V_2 , V_25 , V_47 , 0 , V_45 , V_67 ) ;
}
if ( V_19 -> V_52 || V_48 ) {
V_2 -> V_70 = V_47 ;
V_2 -> V_71 ( V_2 ) ;
}
}
void F_35 ( struct V_24 * V_25 , int V_38 , T_3 V_45 )
{
int V_33 ;
struct V_1 * F_16 ;
const struct V_31 * V_32 ;
struct V_13 * V_13 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_18 ( & V_35 . V_12 ) ;
F_16 = F_28 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 != NULL ) {
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
V_13 = F_20 ( V_25 -> V_37 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_38 ,
V_32 -> V_40 , V_32 -> V_39 ,
V_25 -> V_37 -> V_41 ) ) != NULL ) {
F_30 ( F_16 , V_25 , V_45 ) ;
F_16 = F_25 ( F_16 ) ;
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
}
}
F_26 ( & V_35 . V_12 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_37 ( V_2 , V_25 ) ;
if ( F_38 ( V_2 , V_25 ) < 0 ) {
F_39 ( V_25 ) ;
return V_72 ;
}
return V_73 ;
}
int F_24 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( ! F_40 ( V_2 , V_74 , V_25 ) ) {
F_41 ( & V_2 -> V_75 ) ;
F_39 ( V_25 ) ;
return V_72 ;
}
F_42 ( V_25 ) ;
F_43 ( V_25 , V_25 -> V_29 - F_44 ( V_25 ) ) ;
F_36 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_76 * V_77 ,
void * V_78 , T_5 V_79 ,
struct V_80 * * V_81 ,
unsigned int V_82 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_24 * V_25 ;
unsigned int V_83 ;
int V_47 ;
struct V_80 * V_84 = * V_81 ;
int V_85 , V_86 ;
if ( V_79 > V_84 -> V_87 . V_37 -> V_88 ) {
F_46 ( V_2 , V_66 , V_77 -> V_40 , V_19 -> V_89 ,
V_84 -> V_87 . V_37 -> V_88 ) ;
return - V_66 ;
}
if ( V_82 & V_90 )
goto V_36;
V_85 = F_47 ( V_84 -> V_87 . V_37 ) ;
V_86 = V_84 -> V_87 . V_37 -> V_91 ;
V_25 = F_48 ( V_2 ,
V_79 + V_85 + V_86 + 15 ,
V_82 & V_92 , & V_47 ) ;
if ( V_25 == NULL )
goto error;
F_49 ( V_25 , V_85 ) ;
V_25 -> V_93 = V_2 -> V_94 ;
V_25 -> V_95 = V_2 -> V_96 ;
F_50 ( V_25 , & V_84 -> V_87 ) ;
* V_81 = NULL ;
F_51 ( V_25 ) ;
V_32 = F_29 ( V_25 ) ;
F_52 ( V_25 , V_79 ) ;
V_25 -> V_97 = V_98 ;
F_53 ( V_2 , & F_54 ( V_25 ) -> V_99 ) ;
V_25 -> V_100 = V_25 -> V_101 ;
V_47 = - V_102 ;
if ( F_55 ( ( void * ) V_32 , V_78 , 0 , V_79 ) )
goto V_103;
V_83 = V_32 -> V_68 * 4 ;
V_47 = - V_104 ;
if ( V_83 > V_79 )
goto V_103;
if ( V_83 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_77 -> V_39 ;
V_32 -> V_105 = 0 ;
V_32 -> V_106 = F_56 ( V_79 ) ;
if ( ! V_32 -> V_107 )
F_57 ( V_25 , NULL ) ;
V_32 -> V_105 = F_58 ( ( unsigned char * ) V_32 , V_32 -> V_68 ) ;
}
if ( V_32 -> V_38 == V_42 )
F_59 ( V_13 , ( (struct V_26 * )
F_60 ( V_25 ) ) -> type ) ;
V_47 = F_61 ( V_108 , V_109 , V_25 , NULL ,
V_84 -> V_87 . V_37 , V_110 ) ;
if ( V_47 > 0 )
V_47 = F_62 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_103:
F_39 ( V_25 ) ;
error:
F_63 ( V_13 , V_111 ) ;
if ( V_47 == - V_112 && ! V_19 -> V_52 )
V_47 = 0 ;
return V_47 ;
}
static int F_64 ( struct V_113 * V_114 , struct V_76 * V_77 )
{
int V_47 ;
if ( V_77 -> V_115 != V_42 )
return 0 ;
V_114 -> V_85 = 2 ;
V_47 = F_65 ( V_114 -> V_28 . V_116 , V_114 -> V_117 , V_114 -> V_85 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_118 = V_114 -> V_28 . V_119 . type ;
V_77 -> V_120 = V_114 -> V_28 . V_119 . V_46 ;
return 0 ;
}
static int F_66 ( void * V_78 , char * V_121 , int V_122 , int V_123 , int V_124 ,
struct V_24 * V_25 )
{
struct V_113 * V_114 = V_78 ;
if ( V_122 < V_114 -> V_85 ) {
int V_125 = F_67 ( V_114 -> V_85 - V_122 , V_123 ) ;
if ( V_25 -> V_97 == V_126 )
memcpy ( V_121 , V_114 -> V_28 . V_116 + V_122 , V_125 ) ;
else
V_25 -> V_127 = F_68 (
V_25 -> V_127 ,
F_69 ( V_114 -> V_28 . V_116 + V_122 ,
V_121 , V_125 , 0 ) ,
V_124 ) ;
V_124 = 0 ;
V_122 += V_125 ;
V_121 += V_125 ;
V_123 -= V_125 ;
if ( ! V_123 )
return 0 ;
}
V_122 -= V_114 -> V_85 ;
return F_70 ( V_114 -> V_117 , V_121 , V_122 , V_123 , V_124 , V_25 ) ;
}
static int F_71 ( struct V_128 * V_129 , struct V_1 * V_2 , struct V_130 * V_117 ,
T_5 V_123 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_131 V_132 ;
struct V_80 * V_84 = NULL ;
struct V_76 V_77 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_4 V_133 ;
int V_47 ;
struct V_134 V_135 ;
struct V_113 V_114 ;
V_47 = - V_66 ;
if ( V_123 > 0xFFFF )
goto V_36;
V_47 = - V_136 ;
if ( V_117 -> V_137 & V_138 )
goto V_36;
if ( V_117 -> V_139 ) {
F_72 ( struct V_140 * , V_141 , V_117 -> V_142 ) ;
V_47 = - V_104 ;
if ( V_117 -> V_139 < sizeof( * V_141 ) )
goto V_36;
if ( V_141 -> V_143 != V_144 ) {
F_73 ( L_1 ,
V_145 , V_146 -> V_147 ) ;
V_47 = - V_148 ;
if ( V_141 -> V_143 )
goto V_36;
}
V_40 = V_141 -> V_149 . V_150 ;
} else {
V_47 = - V_151 ;
if ( V_2 -> V_53 != V_54 )
goto V_36;
V_40 = V_19 -> V_20 ;
}
V_132 . V_152 = V_19 -> V_153 ;
V_132 . V_154 = NULL ;
V_132 . V_99 = 0 ;
V_132 . V_155 = 0 ;
V_132 . V_133 = - 1 ;
V_132 . V_156 = V_2 -> V_22 ;
if ( V_117 -> V_157 ) {
V_47 = F_74 ( F_6 ( V_2 ) , V_117 , & V_132 , false ) ;
if ( V_47 )
goto V_36;
if ( V_132 . V_154 )
free = 1 ;
}
V_39 = V_132 . V_152 ;
V_132 . V_152 = V_40 ;
if ( ! V_132 . V_154 ) {
struct V_158 * V_159 ;
F_75 () ;
V_159 = F_76 ( V_19 -> V_159 ) ;
if ( V_159 ) {
memcpy ( & V_135 , V_159 ,
sizeof( * V_159 ) + V_159 -> V_154 . V_160 ) ;
V_132 . V_154 = & V_135 . V_154 ;
}
F_77 () ;
}
if ( V_132 . V_154 ) {
V_47 = - V_104 ;
if ( V_19 -> V_69 )
goto V_161;
if ( V_132 . V_154 -> V_154 . V_162 ) {
if ( ! V_40 )
goto V_161;
V_40 = V_132 . V_154 -> V_154 . V_163 ;
}
}
V_133 = F_78 ( & V_132 , V_2 ) ;
if ( V_117 -> V_137 & V_164 )
V_133 |= V_165 ;
if ( F_79 ( V_40 ) ) {
if ( ! V_132 . V_156 )
V_132 . V_156 = V_19 -> V_166 ;
if ( ! V_39 )
V_39 = V_19 -> V_167 ;
} else if ( ! V_132 . V_156 )
V_132 . V_156 = V_19 -> V_168 ;
F_80 ( & V_77 , V_132 . V_156 , V_2 -> V_96 , V_133 ,
V_169 ,
V_19 -> V_69 ? V_170 : V_2 -> V_171 ,
F_81 ( V_2 ) |
( V_19 -> V_69 ? V_172 : 0 ) ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_19 -> V_69 ) {
V_114 . V_117 = V_117 ;
V_114 . V_85 = 0 ;
V_47 = F_64 ( & V_114 , & V_77 ) ;
if ( V_47 )
goto V_161;
}
F_82 ( V_2 , F_83 ( & V_77 ) ) ;
V_84 = F_84 ( F_6 ( V_2 ) , & V_77 , V_2 ) ;
if ( F_85 ( V_84 ) ) {
V_47 = F_86 ( V_84 ) ;
V_84 = NULL ;
goto V_161;
}
V_47 = - V_173 ;
if ( V_84 -> V_174 & V_175 && ! F_87 ( V_2 , V_176 ) )
goto V_161;
if ( V_117 -> V_137 & V_177 )
goto V_178;
V_179:
if ( V_19 -> V_69 )
V_47 = F_45 ( V_2 , & V_77 , (struct V_180 * ) V_117 -> V_181 . V_182 , V_123 ,
& V_84 , V_117 -> V_137 ) ;
else {
F_53 ( V_2 , & V_132 . V_99 ) ;
if ( ! V_132 . V_152 )
V_132 . V_152 = V_77 . V_40 ;
F_88 ( V_2 ) ;
V_47 = F_89 ( V_2 , & V_77 , F_66 ,
& V_114 , V_123 , 0 ,
& V_132 , & V_84 , V_117 -> V_137 ) ;
if ( V_47 )
F_90 ( V_2 ) ;
else if ( ! ( V_117 -> V_137 & V_183 ) ) {
V_47 = F_91 ( V_2 , & V_77 ) ;
if ( V_47 == - V_112 && ! V_19 -> V_52 )
V_47 = 0 ;
}
F_92 ( V_2 ) ;
}
V_161:
if ( free )
F_93 ( V_132 . V_154 ) ;
F_94 ( V_84 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_123 ;
V_178:
F_95 ( & V_84 -> V_87 ) ;
if ( ! ( V_117 -> V_137 & V_90 ) || V_123 )
goto V_179;
V_47 = 0 ;
goto V_161;
}
static void F_96 ( struct V_1 * V_2 , long V_184 )
{
F_97 ( V_2 , 0 , NULL ) ;
F_98 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_88 ( V_2 ) ;
F_90 ( V_2 ) ;
F_92 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 , struct V_185 * V_186 , int V_187 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_140 * V_152 = (struct V_140 * ) V_186 ;
int V_188 = - V_104 ;
int V_189 ;
if ( V_2 -> V_53 != V_190 || V_187 < sizeof( struct V_140 ) )
goto V_36;
V_189 = F_101 ( F_6 ( V_2 ) , V_152 -> V_149 . V_150 ) ;
V_188 = - V_191 ;
if ( V_152 -> V_149 . V_150 && V_189 != V_192 &&
V_189 != V_193 && V_189 != V_194 )
goto V_36;
V_19 -> V_21 = V_19 -> V_153 = V_152 -> V_149 . V_150 ;
if ( V_189 == V_193 || V_189 == V_194 )
V_19 -> V_153 = 0 ;
F_102 ( V_2 ) ;
V_188 = 0 ;
V_36: return V_188 ;
}
static int F_103 ( struct V_128 * V_129 , struct V_1 * V_2 , struct V_130 * V_117 ,
T_5 V_123 , int V_195 , int V_82 , int * V_187 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_5 V_196 = 0 ;
int V_47 = - V_136 ;
F_72 ( struct V_140 * , sin , V_117 -> V_142 ) ;
struct V_24 * V_25 ;
if ( V_82 & V_138 )
goto V_36;
if ( V_82 & V_197 ) {
V_47 = F_104 ( V_2 , V_117 , V_123 , V_187 ) ;
goto V_36;
}
V_25 = F_105 ( V_2 , V_82 , V_195 , & V_47 ) ;
if ( ! V_25 )
goto V_36;
V_196 = V_25 -> V_123 ;
if ( V_123 < V_196 ) {
V_117 -> V_137 |= V_198 ;
V_196 = V_123 ;
}
V_47 = F_106 ( V_25 , 0 , V_117 , V_196 ) ;
if ( V_47 )
goto V_161;
F_107 ( V_117 , V_2 , V_25 ) ;
if ( sin ) {
sin -> V_143 = V_144 ;
sin -> V_149 . V_150 = F_29 ( V_25 ) -> V_39 ;
sin -> V_199 = 0 ;
memset ( & sin -> V_200 , 0 , sizeof( sin -> V_200 ) ) ;
* V_187 = sizeof( * sin ) ;
}
if ( V_19 -> V_201 )
F_108 ( V_117 , V_25 ) ;
if ( V_82 & V_198 )
V_196 = V_25 -> V_123 ;
V_161:
F_109 ( V_2 , V_25 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_196 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_202 * V_203 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_203 -> V_30 , 0 , sizeof( V_203 -> V_30 ) ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , char T_6 * V_204 , int V_160 )
{
if ( V_160 > sizeof( struct F_13 ) )
V_160 = sizeof( struct F_13 ) ;
if ( F_112 ( & F_16 ( V_2 ) -> V_30 , V_204 , V_160 ) )
return - V_102 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , char T_6 * V_204 , int T_6 * V_160 )
{
int V_123 , V_188 = - V_102 ;
if ( F_114 ( V_123 , V_160 ) )
goto V_36;
V_188 = - V_104 ;
if ( V_123 < 0 )
goto V_36;
if ( V_123 > sizeof( struct F_13 ) )
V_123 = sizeof( struct F_13 ) ;
V_188 = - V_102 ;
if ( F_115 ( V_123 , V_160 ) ||
F_116 ( V_204 , & F_16 ( V_2 ) -> V_30 , V_123 ) )
goto V_36;
V_188 = 0 ;
V_36: return V_188 ;
}
static int F_117 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , unsigned int V_160 )
{
if ( V_206 == V_207 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_136 ;
else
return F_111 ( V_2 , V_204 , V_160 ) ;
}
return - V_208 ;
}
static int F_118 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , unsigned int V_160 )
{
if ( V_205 != V_209 )
return F_119 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
return F_117 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
}
static int F_120 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , unsigned int V_160 )
{
if ( V_205 != V_209 )
return F_121 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
return F_117 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
}
static int F_122 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , int T_6 * V_160 )
{
if ( V_206 == V_207 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_136 ;
else
return F_113 ( V_2 , V_204 , V_160 ) ;
}
return - V_208 ;
}
static int F_123 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , int T_6 * V_160 )
{
if ( V_205 != V_209 )
return F_124 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
return F_122 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
}
static int F_125 ( struct V_1 * V_2 , int V_205 , int V_206 ,
char T_6 * V_204 , int T_6 * V_160 )
{
if ( V_205 != V_209 )
return F_126 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
return F_122 ( V_2 , V_205 , V_206 , V_204 , V_160 ) ;
}
static int F_127 ( struct V_1 * V_2 , int V_210 , unsigned long V_211 )
{
switch ( V_210 ) {
case V_212 : {
int V_213 = F_128 ( V_2 ) ;
return F_115 ( V_213 , ( int T_6 * ) V_211 ) ;
}
case V_214 : {
struct V_24 * V_25 ;
int V_213 = 0 ;
F_129 ( & V_2 -> V_215 . V_12 ) ;
V_25 = F_130 ( & V_2 -> V_215 ) ;
if ( V_25 != NULL )
V_213 = V_25 -> V_123 ;
F_131 ( & V_2 -> V_215 . V_12 ) ;
return F_115 ( V_213 , ( int T_6 * ) V_211 ) ;
}
default:
#ifdef F_132
return F_133 ( V_2 , V_210 , ( void T_6 * ) V_211 ) ;
#else
return - V_216 ;
#endif
}
}
static int F_134 ( struct V_1 * V_2 , unsigned int V_210 , unsigned long V_211 )
{
switch ( V_210 ) {
case V_212 :
case V_214 :
return - V_216 ;
default:
#ifdef F_132
return F_135 ( V_2 , V_210 , F_136 ( V_211 ) ) ;
#else
return - V_216 ;
#endif
}
}
static struct V_1 * F_137 ( struct V_217 * V_218 )
{
struct V_1 * V_2 ;
struct V_219 * V_220 = F_138 ( V_218 ) ;
for ( V_220 -> V_221 = 0 ; V_220 -> V_221 < V_11 ;
++ V_220 -> V_221 ) {
F_139 (sk, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_140 ( V_218 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static struct V_1 * F_141 ( struct V_217 * V_218 , struct V_1 * V_2 )
{
struct V_219 * V_220 = F_138 ( V_218 ) ;
do {
V_2 = F_25 ( V_2 ) ;
V_222:
;
} while ( V_2 && F_6 ( V_2 ) != F_140 ( V_218 ) );
if ( ! V_2 && ++ V_220 -> V_221 < V_11 ) {
V_2 = F_28 ( & V_220 -> V_4 -> V_9 [ V_220 -> V_221 ] ) ;
goto V_222;
}
return V_2 ;
}
static struct V_1 * F_142 ( struct V_217 * V_218 , T_7 V_223 )
{
struct V_1 * V_2 = F_137 ( V_218 ) ;
if ( V_2 )
while ( V_223 && ( V_2 = F_141 ( V_218 , V_2 ) ) != NULL )
-- V_223 ;
return V_223 ? NULL : V_2 ;
}
void * F_143 ( struct V_217 * V_218 , T_7 * V_223 )
{
struct V_219 * V_220 = F_138 ( V_218 ) ;
F_18 ( & V_220 -> V_4 -> V_12 ) ;
return * V_223 ? F_142 ( V_218 , * V_223 - 1 ) : V_224 ;
}
void * F_144 ( struct V_217 * V_218 , void * V_225 , T_7 * V_223 )
{
struct V_1 * V_2 ;
if ( V_225 == V_224 )
V_2 = F_137 ( V_218 ) ;
else
V_2 = F_141 ( V_218 , V_225 ) ;
++ * V_223 ;
return V_2 ;
}
void F_145 ( struct V_217 * V_218 , void * V_225 )
{
struct V_219 * V_220 = F_138 ( V_218 ) ;
F_26 ( & V_220 -> V_4 -> V_12 ) ;
}
static void F_146 ( struct V_217 * V_218 , struct V_1 * V_226 , int V_227 )
{
struct V_18 * V_19 = F_2 ( V_226 ) ;
T_1 V_228 = V_19 -> V_20 ,
V_229 = V_19 -> V_21 ;
T_8 V_230 = 0 ,
V_231 = V_19 -> V_10 ;
F_147 ( V_218 , L_2
L_3 ,
V_227 , V_229 , V_231 , V_228 , V_230 , V_226 -> V_53 ,
F_128 ( V_226 ) ,
F_148 ( V_226 ) ,
0 , 0L , 0 ,
F_149 ( F_150 ( V_218 ) , F_151 ( V_226 ) ) ,
0 , F_152 ( V_226 ) ,
F_153 ( & V_226 -> V_232 ) , V_226 , F_153 ( & V_226 -> V_75 ) ) ;
}
static int F_154 ( struct V_217 * V_218 , void * V_225 )
{
if ( V_225 == V_224 )
F_147 ( V_218 , L_4
L_5
L_6 ) ;
else
F_146 ( V_218 , V_225 , F_138 ( V_218 ) -> V_221 ) ;
return 0 ;
}
int F_155 ( struct V_233 * V_234 , struct V_235 * V_235 ,
struct V_3 * V_4 , const struct V_236 * V_237 )
{
int V_47 ;
struct V_219 * V_227 ;
V_47 = F_156 ( V_234 , V_235 , V_237 , sizeof( struct V_219 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_227 = F_138 ( (struct V_217 * ) V_235 -> V_238 ) ;
V_227 -> V_4 = V_4 ;
return 0 ;
}
static int F_157 ( struct V_233 * V_233 , struct V_235 * V_235 )
{
return F_155 ( V_233 , V_235 , & V_35 , & V_239 ) ;
}
static T_9 int F_158 ( struct V_13 * V_13 )
{
if ( ! F_159 ( L_7 , V_240 , V_13 -> V_241 , & V_242 ) )
return - V_243 ;
return 0 ;
}
static T_10 void F_160 ( struct V_13 * V_13 )
{
F_161 ( L_7 , V_13 -> V_241 ) ;
}
int T_11 F_162 ( void )
{
return F_163 ( & V_244 ) ;
}
void T_11 F_164 ( void )
{
F_165 ( & V_244 ) ;
}
