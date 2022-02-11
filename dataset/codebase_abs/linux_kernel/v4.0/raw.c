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
struct V_78 * V_79 , T_5 V_80 ,
struct V_81 * * V_82 ,
unsigned int V_83 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_24 * V_25 ;
unsigned int V_84 ;
int V_47 ;
struct V_81 * V_85 = * V_82 ;
int V_86 , V_87 ;
if ( V_80 > V_85 -> V_88 . V_37 -> V_89 ) {
F_46 ( V_2 , V_66 , V_77 -> V_40 , V_19 -> V_90 ,
V_85 -> V_88 . V_37 -> V_89 ) ;
return - V_66 ;
}
if ( V_83 & V_91 )
goto V_36;
V_86 = F_47 ( V_85 -> V_88 . V_37 ) ;
V_87 = V_85 -> V_88 . V_37 -> V_92 ;
V_25 = F_48 ( V_2 ,
V_80 + V_86 + V_87 + 15 ,
V_83 & V_93 , & V_47 ) ;
if ( V_25 == NULL )
goto error;
F_49 ( V_25 , V_86 ) ;
V_25 -> V_94 = V_2 -> V_95 ;
V_25 -> V_96 = V_2 -> V_97 ;
F_50 ( V_25 , & V_85 -> V_88 ) ;
* V_82 = NULL ;
F_51 ( V_25 ) ;
V_32 = F_29 ( V_25 ) ;
F_52 ( V_25 , V_80 ) ;
V_25 -> V_98 = V_99 ;
F_53 ( V_2 , & F_54 ( V_25 ) -> V_100 ) ;
V_25 -> V_101 = V_25 -> V_102 ;
V_47 = - V_103 ;
if ( F_55 ( V_32 , V_79 , V_80 ) )
goto V_104;
V_84 = V_32 -> V_68 * 4 ;
V_47 = - V_105 ;
if ( V_84 > V_80 )
goto V_104;
if ( V_84 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_77 -> V_39 ;
V_32 -> V_106 = 0 ;
V_32 -> V_107 = F_56 ( V_80 ) ;
if ( ! V_32 -> V_108 )
F_57 ( V_25 , NULL ) ;
V_32 -> V_106 = F_58 ( ( unsigned char * ) V_32 , V_32 -> V_68 ) ;
}
if ( V_32 -> V_38 == V_42 )
F_59 ( V_13 , ( (struct V_26 * )
F_60 ( V_25 ) ) -> type ) ;
V_47 = F_61 ( V_109 , V_110 , V_25 , NULL ,
V_85 -> V_88 . V_37 , V_111 ) ;
if ( V_47 > 0 )
V_47 = F_62 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_104:
F_39 ( V_25 ) ;
error:
F_63 ( V_13 , V_112 ) ;
if ( V_47 == - V_113 && ! V_19 -> V_52 )
V_47 = 0 ;
return V_47 ;
}
static int F_64 ( struct V_114 * V_115 , struct V_76 * V_77 )
{
int V_47 ;
if ( V_77 -> V_116 != V_42 )
return 0 ;
V_115 -> V_86 = 2 ;
V_47 = F_55 ( V_115 -> V_28 . V_117 , V_115 -> V_79 , V_115 -> V_86 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_118 = V_115 -> V_28 . V_119 . type ;
V_77 -> V_120 = V_115 -> V_28 . V_119 . V_46 ;
return 0 ;
}
static int F_65 ( void * V_121 , char * V_122 , int V_123 , int V_124 , int V_125 ,
struct V_24 * V_25 )
{
struct V_114 * V_115 = V_121 ;
if ( V_123 < V_115 -> V_86 ) {
int V_126 = F_66 ( V_115 -> V_86 - V_123 , V_124 ) ;
if ( V_25 -> V_98 == V_127 )
memcpy ( V_122 , V_115 -> V_28 . V_117 + V_123 , V_126 ) ;
else
V_25 -> V_128 = F_67 (
V_25 -> V_128 ,
F_68 ( V_115 -> V_28 . V_117 + V_123 ,
V_122 , V_126 , 0 ) ,
V_125 ) ;
V_125 = 0 ;
V_123 += V_126 ;
V_122 += V_126 ;
V_124 -= V_126 ;
if ( ! V_124 )
return 0 ;
}
V_123 -= V_115 -> V_86 ;
return F_69 ( V_115 -> V_79 , V_122 , V_123 , V_124 , V_125 , V_25 ) ;
}
static int F_70 ( struct V_129 * V_130 , struct V_1 * V_2 , struct V_78 * V_79 ,
T_5 V_124 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_131 V_132 ;
struct V_81 * V_85 = NULL ;
struct V_76 V_77 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_4 V_133 ;
int V_47 ;
struct V_134 V_135 ;
struct V_114 V_115 ;
V_47 = - V_66 ;
if ( V_124 > 0xFFFF )
goto V_36;
V_47 = - V_136 ;
if ( V_79 -> V_137 & V_138 )
goto V_36;
if ( V_79 -> V_139 ) {
F_71 ( struct V_140 * , V_141 , V_79 -> V_142 ) ;
V_47 = - V_105 ;
if ( V_79 -> V_139 < sizeof( * V_141 ) )
goto V_36;
if ( V_141 -> V_143 != V_144 ) {
F_72 ( L_1 ,
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
V_132 . V_100 = 0 ;
V_132 . V_155 = 0 ;
V_132 . V_133 = - 1 ;
V_132 . V_156 = V_2 -> V_22 ;
if ( V_79 -> V_157 ) {
V_47 = F_73 ( F_6 ( V_2 ) , V_79 , & V_132 , false ) ;
if ( V_47 )
goto V_36;
if ( V_132 . V_154 )
free = 1 ;
}
V_39 = V_132 . V_152 ;
V_132 . V_152 = V_40 ;
if ( ! V_132 . V_154 ) {
struct V_158 * V_159 ;
F_74 () ;
V_159 = F_75 ( V_19 -> V_159 ) ;
if ( V_159 ) {
memcpy ( & V_135 , V_159 ,
sizeof( * V_159 ) + V_159 -> V_154 . V_160 ) ;
V_132 . V_154 = & V_135 . V_154 ;
}
F_76 () ;
}
if ( V_132 . V_154 ) {
V_47 = - V_105 ;
if ( V_19 -> V_69 )
goto V_161;
if ( V_132 . V_154 -> V_154 . V_162 ) {
if ( ! V_40 )
goto V_161;
V_40 = V_132 . V_154 -> V_154 . V_163 ;
}
}
V_133 = F_77 ( & V_132 , V_2 ) ;
if ( V_79 -> V_137 & V_164 )
V_133 |= V_165 ;
if ( F_78 ( V_40 ) ) {
if ( ! V_132 . V_156 )
V_132 . V_156 = V_19 -> V_166 ;
if ( ! V_39 )
V_39 = V_19 -> V_167 ;
} else if ( ! V_132 . V_156 )
V_132 . V_156 = V_19 -> V_168 ;
F_79 ( & V_77 , V_132 . V_156 , V_2 -> V_97 , V_133 ,
V_169 ,
V_19 -> V_69 ? V_170 : V_2 -> V_171 ,
F_80 ( V_2 ) |
( V_19 -> V_69 ? V_172 : 0 ) ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_19 -> V_69 ) {
V_115 . V_79 = V_79 ;
V_115 . V_86 = 0 ;
V_47 = F_64 ( & V_115 , & V_77 ) ;
if ( V_47 )
goto V_161;
}
F_81 ( V_2 , F_82 ( & V_77 ) ) ;
V_85 = F_83 ( F_6 ( V_2 ) , & V_77 , V_2 ) ;
if ( F_84 ( V_85 ) ) {
V_47 = F_85 ( V_85 ) ;
V_85 = NULL ;
goto V_161;
}
V_47 = - V_173 ;
if ( V_85 -> V_174 & V_175 && ! F_86 ( V_2 , V_176 ) )
goto V_161;
if ( V_79 -> V_137 & V_177 )
goto V_178;
V_179:
if ( V_19 -> V_69 )
V_47 = F_45 ( V_2 , & V_77 , V_79 , V_124 ,
& V_85 , V_79 -> V_137 ) ;
else {
F_53 ( V_2 , & V_132 . V_100 ) ;
if ( ! V_132 . V_152 )
V_132 . V_152 = V_77 . V_40 ;
F_87 ( V_2 ) ;
V_47 = F_88 ( V_2 , & V_77 , F_65 ,
& V_115 , V_124 , 0 ,
& V_132 , & V_85 , V_79 -> V_137 ) ;
if ( V_47 )
F_89 ( V_2 ) ;
else if ( ! ( V_79 -> V_137 & V_180 ) ) {
V_47 = F_90 ( V_2 , & V_77 ) ;
if ( V_47 == - V_113 && ! V_19 -> V_52 )
V_47 = 0 ;
}
F_91 ( V_2 ) ;
}
V_161:
if ( free )
F_92 ( V_132 . V_154 ) ;
F_93 ( V_85 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_124 ;
V_178:
F_94 ( & V_85 -> V_88 ) ;
if ( ! ( V_79 -> V_137 & V_91 ) || V_124 )
goto V_179;
V_47 = 0 ;
goto V_161;
}
static void F_95 ( struct V_1 * V_2 , long V_181 )
{
F_96 ( V_2 , 0 , NULL ) ;
F_97 ( V_2 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_87 ( V_2 ) ;
F_89 ( V_2 ) ;
F_91 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 , struct V_182 * V_183 , int V_184 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_140 * V_152 = (struct V_140 * ) V_183 ;
int V_185 = - V_105 ;
int V_186 ;
if ( V_2 -> V_53 != V_187 || V_184 < sizeof( struct V_140 ) )
goto V_36;
V_186 = F_100 ( F_6 ( V_2 ) , V_152 -> V_149 . V_150 ) ;
V_185 = - V_188 ;
if ( V_152 -> V_149 . V_150 && V_186 != V_189 &&
V_186 != V_190 && V_186 != V_191 )
goto V_36;
V_19 -> V_21 = V_19 -> V_153 = V_152 -> V_149 . V_150 ;
if ( V_186 == V_190 || V_186 == V_191 )
V_19 -> V_153 = 0 ;
F_101 ( V_2 ) ;
V_185 = 0 ;
V_36: return V_185 ;
}
static int F_102 ( struct V_129 * V_130 , struct V_1 * V_2 , struct V_78 * V_79 ,
T_5 V_124 , int V_192 , int V_83 , int * V_184 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_5 V_193 = 0 ;
int V_47 = - V_136 ;
F_71 ( struct V_140 * , sin , V_79 -> V_142 ) ;
struct V_24 * V_25 ;
if ( V_83 & V_138 )
goto V_36;
if ( V_83 & V_194 ) {
V_47 = F_103 ( V_2 , V_79 , V_124 , V_184 ) ;
goto V_36;
}
V_25 = F_104 ( V_2 , V_83 , V_192 , & V_47 ) ;
if ( ! V_25 )
goto V_36;
V_193 = V_25 -> V_124 ;
if ( V_124 < V_193 ) {
V_79 -> V_137 |= V_195 ;
V_193 = V_124 ;
}
V_47 = F_105 ( V_25 , 0 , V_79 , V_193 ) ;
if ( V_47 )
goto V_161;
F_106 ( V_79 , V_2 , V_25 ) ;
if ( sin ) {
sin -> V_143 = V_144 ;
sin -> V_149 . V_150 = F_29 ( V_25 ) -> V_39 ;
sin -> V_196 = 0 ;
memset ( & sin -> V_197 , 0 , sizeof( sin -> V_197 ) ) ;
* V_184 = sizeof( * sin ) ;
}
if ( V_19 -> V_198 )
F_107 ( V_79 , V_25 ) ;
if ( V_83 & V_195 )
V_193 = V_25 -> V_124 ;
V_161:
F_108 ( V_2 , V_25 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_193 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_200 -> V_30 , 0 , sizeof( V_200 -> V_30 ) ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , char T_6 * V_201 , int V_160 )
{
if ( V_160 > sizeof( struct F_13 ) )
V_160 = sizeof( struct F_13 ) ;
if ( F_111 ( & F_16 ( V_2 ) -> V_30 , V_201 , V_160 ) )
return - V_103 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , char T_6 * V_201 , int T_6 * V_160 )
{
int V_124 , V_185 = - V_103 ;
if ( F_113 ( V_124 , V_160 ) )
goto V_36;
V_185 = - V_105 ;
if ( V_124 < 0 )
goto V_36;
if ( V_124 > sizeof( struct F_13 ) )
V_124 = sizeof( struct F_13 ) ;
V_185 = - V_103 ;
if ( F_114 ( V_124 , V_160 ) ||
F_115 ( V_201 , & F_16 ( V_2 ) -> V_30 , V_124 ) )
goto V_36;
V_185 = 0 ;
V_36: return V_185 ;
}
static int F_116 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_160 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_136 ;
else
return F_110 ( V_2 , V_201 , V_160 ) ;
}
return - V_205 ;
}
static int F_117 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_160 )
{
if ( V_202 != V_206 )
return F_118 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
return F_116 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
}
static int F_119 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_160 )
{
if ( V_202 != V_206 )
return F_120 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
return F_116 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
}
static int F_121 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_160 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_136 ;
else
return F_112 ( V_2 , V_201 , V_160 ) ;
}
return - V_205 ;
}
static int F_122 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_160 )
{
if ( V_202 != V_206 )
return F_123 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
return F_121 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
}
static int F_124 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_160 )
{
if ( V_202 != V_206 )
return F_125 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
return F_121 ( V_2 , V_202 , V_203 , V_201 , V_160 ) ;
}
static int F_126 ( struct V_1 * V_2 , int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 : {
int V_210 = F_127 ( V_2 ) ;
return F_114 ( V_210 , ( int T_6 * ) V_208 ) ;
}
case V_211 : {
struct V_24 * V_25 ;
int V_210 = 0 ;
F_128 ( & V_2 -> V_212 . V_12 ) ;
V_25 = F_129 ( & V_2 -> V_212 ) ;
if ( V_25 != NULL )
V_210 = V_25 -> V_124 ;
F_130 ( & V_2 -> V_212 . V_12 ) ;
return F_114 ( V_210 , ( int T_6 * ) V_208 ) ;
}
default:
#ifdef F_131
return F_132 ( V_2 , V_207 , ( void T_6 * ) V_208 ) ;
#else
return - V_213 ;
#endif
}
}
static int F_133 ( struct V_1 * V_2 , unsigned int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 :
case V_211 :
return - V_213 ;
default:
#ifdef F_131
return F_134 ( V_2 , V_207 , F_135 ( V_208 ) ) ;
#else
return - V_213 ;
#endif
}
}
static struct V_1 * F_136 ( struct V_214 * V_215 )
{
struct V_1 * V_2 ;
struct V_216 * V_217 = F_137 ( V_215 ) ;
for ( V_217 -> V_218 = 0 ; V_217 -> V_218 < V_11 ;
++ V_217 -> V_218 ) {
F_138 (sk, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_139 ( V_215 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static struct V_1 * F_140 ( struct V_214 * V_215 , struct V_1 * V_2 )
{
struct V_216 * V_217 = F_137 ( V_215 ) ;
do {
V_2 = F_25 ( V_2 ) ;
V_219:
;
} while ( V_2 && F_6 ( V_2 ) != F_139 ( V_215 ) );
if ( ! V_2 && ++ V_217 -> V_218 < V_11 ) {
V_2 = F_28 ( & V_217 -> V_4 -> V_9 [ V_217 -> V_218 ] ) ;
goto V_219;
}
return V_2 ;
}
static struct V_1 * F_141 ( struct V_214 * V_215 , T_7 V_220 )
{
struct V_1 * V_2 = F_136 ( V_215 ) ;
if ( V_2 )
while ( V_220 && ( V_2 = F_140 ( V_215 , V_2 ) ) != NULL )
-- V_220 ;
return V_220 ? NULL : V_2 ;
}
void * F_142 ( struct V_214 * V_215 , T_7 * V_220 )
{
struct V_216 * V_217 = F_137 ( V_215 ) ;
F_18 ( & V_217 -> V_4 -> V_12 ) ;
return * V_220 ? F_141 ( V_215 , * V_220 - 1 ) : V_221 ;
}
void * F_143 ( struct V_214 * V_215 , void * V_222 , T_7 * V_220 )
{
struct V_1 * V_2 ;
if ( V_222 == V_221 )
V_2 = F_136 ( V_215 ) ;
else
V_2 = F_140 ( V_215 , V_222 ) ;
++ * V_220 ;
return V_2 ;
}
void F_144 ( struct V_214 * V_215 , void * V_222 )
{
struct V_216 * V_217 = F_137 ( V_215 ) ;
F_26 ( & V_217 -> V_4 -> V_12 ) ;
}
static void F_145 ( struct V_214 * V_215 , struct V_1 * V_223 , int V_224 )
{
struct V_18 * V_19 = F_2 ( V_223 ) ;
T_1 V_225 = V_19 -> V_20 ,
V_226 = V_19 -> V_21 ;
T_8 V_227 = 0 ,
V_228 = V_19 -> V_10 ;
F_146 ( V_215 , L_2
L_3 ,
V_224 , V_226 , V_228 , V_225 , V_227 , V_223 -> V_53 ,
F_127 ( V_223 ) ,
F_147 ( V_223 ) ,
0 , 0L , 0 ,
F_148 ( F_149 ( V_215 ) , F_150 ( V_223 ) ) ,
0 , F_151 ( V_223 ) ,
F_152 ( & V_223 -> V_229 ) , V_223 , F_152 ( & V_223 -> V_75 ) ) ;
}
static int F_153 ( struct V_214 * V_215 , void * V_222 )
{
if ( V_222 == V_221 )
F_146 ( V_215 , L_4
L_5
L_6 ) ;
else
F_145 ( V_215 , V_222 , F_137 ( V_215 ) -> V_218 ) ;
return 0 ;
}
int F_154 ( struct V_230 * V_231 , struct V_232 * V_232 ,
struct V_3 * V_4 , const struct V_233 * V_234 )
{
int V_47 ;
struct V_216 * V_224 ;
V_47 = F_155 ( V_231 , V_232 , V_234 , sizeof( struct V_216 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_224 = F_137 ( (struct V_214 * ) V_232 -> V_235 ) ;
V_224 -> V_4 = V_4 ;
return 0 ;
}
static int F_156 ( struct V_230 * V_230 , struct V_232 * V_232 )
{
return F_154 ( V_230 , V_232 , & V_35 , & V_236 ) ;
}
static T_9 int F_157 ( struct V_13 * V_13 )
{
if ( ! F_158 ( L_7 , V_237 , V_13 -> V_238 , & V_239 ) )
return - V_240 ;
return 0 ;
}
static T_10 void F_159 ( struct V_13 * V_13 )
{
F_160 ( L_7 , V_13 -> V_238 ) ;
}
int T_11 F_161 ( void )
{
return F_162 ( & V_241 ) ;
}
void T_11 F_163 ( void )
{
F_164 ( & V_241 ) ;
}
