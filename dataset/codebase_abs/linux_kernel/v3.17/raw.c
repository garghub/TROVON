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
static int F_64 ( struct V_76 * V_77 , struct V_113 * V_114 )
{
struct V_115 * V_116 ;
T_4 T_6 * type = NULL ;
T_4 T_6 * V_46 = NULL ;
int V_117 = 0 ;
unsigned int V_118 ;
if ( ! V_114 -> V_119 )
return 0 ;
for ( V_118 = 0 ; V_118 < V_114 -> V_120 ; V_118 ++ ) {
V_116 = & V_114 -> V_119 [ V_118 ] ;
if ( ! V_116 )
continue;
switch ( V_77 -> V_121 ) {
case V_42 :
if ( V_116 -> V_122 && V_116 -> V_123 < 1 )
break;
if ( ! type ) {
type = V_116 -> V_122 ;
if ( V_116 -> V_123 > 1 )
V_46 = type + 1 ;
} else if ( ! V_46 )
V_46 = V_116 -> V_122 ;
if ( type && V_46 ) {
if ( F_65 ( V_77 -> V_124 , type ) ||
F_65 ( V_77 -> V_125 , V_46 ) )
return - V_102 ;
V_117 = 1 ;
}
break;
default:
V_117 = 1 ;
break;
}
if ( V_117 )
break;
}
return 0 ;
}
static int F_66 ( struct V_126 * V_127 , struct V_1 * V_2 , struct V_113 * V_114 ,
T_5 V_128 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_129 V_130 ;
struct V_80 * V_84 = NULL ;
struct V_76 V_77 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_4 V_131 ;
int V_47 ;
struct V_132 V_133 ;
V_47 = - V_66 ;
if ( V_128 > 0xFFFF )
goto V_36;
V_47 = - V_134 ;
if ( V_114 -> V_135 & V_136 )
goto V_36;
if ( V_114 -> V_137 ) {
F_67 ( struct V_138 * , V_139 , V_114 -> V_140 ) ;
V_47 = - V_104 ;
if ( V_114 -> V_137 < sizeof( * V_139 ) )
goto V_36;
if ( V_139 -> V_141 != V_142 ) {
F_68 ( L_1 ,
V_143 , V_144 -> V_145 ) ;
V_47 = - V_146 ;
if ( V_139 -> V_141 )
goto V_36;
}
V_40 = V_139 -> V_147 . V_148 ;
} else {
V_47 = - V_149 ;
if ( V_2 -> V_53 != V_54 )
goto V_36;
V_40 = V_19 -> V_20 ;
}
V_130 . V_150 = V_19 -> V_151 ;
V_130 . V_152 = NULL ;
V_130 . V_99 = 0 ;
V_130 . V_153 = 0 ;
V_130 . V_131 = - 1 ;
V_130 . V_154 = V_2 -> V_22 ;
if ( V_114 -> V_155 ) {
V_47 = F_69 ( F_6 ( V_2 ) , V_114 , & V_130 , false ) ;
if ( V_47 )
goto V_36;
if ( V_130 . V_152 )
free = 1 ;
}
V_39 = V_130 . V_150 ;
V_130 . V_150 = V_40 ;
if ( ! V_130 . V_152 ) {
struct V_156 * V_157 ;
F_70 () ;
V_157 = F_71 ( V_19 -> V_157 ) ;
if ( V_157 ) {
memcpy ( & V_133 , V_157 ,
sizeof( * V_157 ) + V_157 -> V_152 . V_158 ) ;
V_130 . V_152 = & V_133 . V_152 ;
}
F_72 () ;
}
if ( V_130 . V_152 ) {
V_47 = - V_104 ;
if ( V_19 -> V_69 )
goto V_159;
if ( V_130 . V_152 -> V_152 . V_160 ) {
if ( ! V_40 )
goto V_159;
V_40 = V_130 . V_152 -> V_152 . V_161 ;
}
}
V_131 = F_73 ( & V_130 , V_2 ) ;
if ( V_114 -> V_135 & V_162 )
V_131 |= V_163 ;
if ( F_74 ( V_40 ) ) {
if ( ! V_130 . V_154 )
V_130 . V_154 = V_19 -> V_164 ;
if ( ! V_39 )
V_39 = V_19 -> V_165 ;
} else if ( ! V_130 . V_154 )
V_130 . V_154 = V_19 -> V_166 ;
F_75 ( & V_77 , V_130 . V_154 , V_2 -> V_96 , V_131 ,
V_167 ,
V_19 -> V_69 ? V_168 : V_2 -> V_169 ,
F_76 ( V_2 ) |
( V_19 -> V_69 ? V_170 : 0 ) ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_19 -> V_69 ) {
V_47 = F_64 ( & V_77 , V_114 ) ;
if ( V_47 )
goto V_159;
}
F_77 ( V_2 , F_78 ( & V_77 ) ) ;
V_84 = F_79 ( F_6 ( V_2 ) , & V_77 , V_2 ) ;
if ( F_80 ( V_84 ) ) {
V_47 = F_81 ( V_84 ) ;
V_84 = NULL ;
goto V_159;
}
V_47 = - V_171 ;
if ( V_84 -> V_172 & V_173 && ! F_82 ( V_2 , V_174 ) )
goto V_159;
if ( V_114 -> V_135 & V_175 )
goto V_176;
V_177:
if ( V_19 -> V_69 )
V_47 = F_45 ( V_2 , & V_77 , V_114 -> V_119 , V_128 ,
& V_84 , V_114 -> V_135 ) ;
else {
F_53 ( V_2 , & V_130 . V_99 ) ;
if ( ! V_130 . V_150 )
V_130 . V_150 = V_77 . V_40 ;
F_83 ( V_2 ) ;
V_47 = F_84 ( V_2 , & V_77 , V_178 ,
V_114 -> V_119 , V_128 , 0 ,
& V_130 , & V_84 , V_114 -> V_135 ) ;
if ( V_47 )
F_85 ( V_2 ) ;
else if ( ! ( V_114 -> V_135 & V_179 ) ) {
V_47 = F_86 ( V_2 , & V_77 ) ;
if ( V_47 == - V_112 && ! V_19 -> V_52 )
V_47 = 0 ;
}
F_87 ( V_2 ) ;
}
V_159:
if ( free )
F_88 ( V_130 . V_152 ) ;
F_89 ( V_84 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_128 ;
V_176:
F_90 ( & V_84 -> V_87 ) ;
if ( ! ( V_114 -> V_135 & V_90 ) || V_128 )
goto V_177;
V_47 = 0 ;
goto V_159;
}
static void F_91 ( struct V_1 * V_2 , long V_180 )
{
F_92 ( V_2 , 0 , NULL ) ;
F_93 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_85 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static int F_95 ( struct V_1 * V_2 , struct V_181 * V_182 , int V_183 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_138 * V_150 = (struct V_138 * ) V_182 ;
int V_184 = - V_104 ;
int V_185 ;
if ( V_2 -> V_53 != V_186 || V_183 < sizeof( struct V_138 ) )
goto V_36;
V_185 = F_96 ( F_6 ( V_2 ) , V_150 -> V_147 . V_148 ) ;
V_184 = - V_187 ;
if ( V_150 -> V_147 . V_148 && V_185 != V_188 &&
V_185 != V_189 && V_185 != V_190 )
goto V_36;
V_19 -> V_21 = V_19 -> V_151 = V_150 -> V_147 . V_148 ;
if ( V_185 == V_189 || V_185 == V_190 )
V_19 -> V_151 = 0 ;
F_97 ( V_2 ) ;
V_184 = 0 ;
V_36: return V_184 ;
}
static int F_98 ( struct V_126 * V_127 , struct V_1 * V_2 , struct V_113 * V_114 ,
T_5 V_128 , int V_191 , int V_82 , int * V_183 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_5 V_192 = 0 ;
int V_47 = - V_134 ;
F_67 ( struct V_138 * , sin , V_114 -> V_140 ) ;
struct V_24 * V_25 ;
if ( V_82 & V_136 )
goto V_36;
if ( V_82 & V_193 ) {
V_47 = F_99 ( V_2 , V_114 , V_128 , V_183 ) ;
goto V_36;
}
V_25 = F_100 ( V_2 , V_82 , V_191 , & V_47 ) ;
if ( ! V_25 )
goto V_36;
V_192 = V_25 -> V_128 ;
if ( V_128 < V_192 ) {
V_114 -> V_135 |= V_194 ;
V_192 = V_128 ;
}
V_47 = F_101 ( V_25 , 0 , V_114 -> V_119 , V_192 ) ;
if ( V_47 )
goto V_159;
F_102 ( V_114 , V_2 , V_25 ) ;
if ( sin ) {
sin -> V_141 = V_142 ;
sin -> V_147 . V_148 = F_29 ( V_25 ) -> V_39 ;
sin -> V_195 = 0 ;
memset ( & sin -> V_196 , 0 , sizeof( sin -> V_196 ) ) ;
* V_183 = sizeof( * sin ) ;
}
if ( V_19 -> V_197 )
F_103 ( V_114 , V_25 ) ;
if ( V_82 & V_194 )
V_192 = V_25 -> V_128 ;
V_159:
F_104 ( V_2 , V_25 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_192 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_198 * V_199 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_199 -> V_30 , 0 , sizeof( V_199 -> V_30 ) ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , char T_6 * V_200 , int V_158 )
{
if ( V_158 > sizeof( struct F_13 ) )
V_158 = sizeof( struct F_13 ) ;
if ( F_107 ( & F_16 ( V_2 ) -> V_30 , V_200 , V_158 ) )
return - V_102 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , char T_6 * V_200 , int T_6 * V_158 )
{
int V_128 , V_184 = - V_102 ;
if ( F_65 ( V_128 , V_158 ) )
goto V_36;
V_184 = - V_104 ;
if ( V_128 < 0 )
goto V_36;
if ( V_128 > sizeof( struct F_13 ) )
V_128 = sizeof( struct F_13 ) ;
V_184 = - V_102 ;
if ( F_109 ( V_128 , V_158 ) ||
F_110 ( V_200 , & F_16 ( V_2 ) -> V_30 , V_128 ) )
goto V_36;
V_184 = 0 ;
V_36: return V_184 ;
}
static int F_111 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , unsigned int V_158 )
{
if ( V_202 == V_203 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_134 ;
else
return F_106 ( V_2 , V_200 , V_158 ) ;
}
return - V_204 ;
}
static int F_112 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , unsigned int V_158 )
{
if ( V_201 != V_205 )
return F_113 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
return F_111 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
}
static int F_114 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , unsigned int V_158 )
{
if ( V_201 != V_205 )
return F_115 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
return F_111 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
}
static int F_116 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , int T_6 * V_158 )
{
if ( V_202 == V_203 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_134 ;
else
return F_108 ( V_2 , V_200 , V_158 ) ;
}
return - V_204 ;
}
static int F_117 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , int T_6 * V_158 )
{
if ( V_201 != V_205 )
return F_118 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
return F_116 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
}
static int F_119 ( struct V_1 * V_2 , int V_201 , int V_202 ,
char T_6 * V_200 , int T_6 * V_158 )
{
if ( V_201 != V_205 )
return F_120 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
return F_116 ( V_2 , V_201 , V_202 , V_200 , V_158 ) ;
}
static int F_121 ( struct V_1 * V_2 , int V_206 , unsigned long V_207 )
{
switch ( V_206 ) {
case V_208 : {
int V_209 = F_122 ( V_2 ) ;
return F_109 ( V_209 , ( int T_6 * ) V_207 ) ;
}
case V_210 : {
struct V_24 * V_25 ;
int V_209 = 0 ;
F_123 ( & V_2 -> V_211 . V_12 ) ;
V_25 = F_124 ( & V_2 -> V_211 ) ;
if ( V_25 != NULL )
V_209 = V_25 -> V_128 ;
F_125 ( & V_2 -> V_211 . V_12 ) ;
return F_109 ( V_209 , ( int T_6 * ) V_207 ) ;
}
default:
#ifdef F_126
return F_127 ( V_2 , V_206 , ( void T_6 * ) V_207 ) ;
#else
return - V_212 ;
#endif
}
}
static int F_128 ( struct V_1 * V_2 , unsigned int V_206 , unsigned long V_207 )
{
switch ( V_206 ) {
case V_208 :
case V_210 :
return - V_212 ;
default:
#ifdef F_126
return F_129 ( V_2 , V_206 , F_130 ( V_207 ) ) ;
#else
return - V_212 ;
#endif
}
}
static struct V_1 * F_131 ( struct V_213 * V_214 )
{
struct V_1 * V_2 ;
struct V_215 * V_216 = F_132 ( V_214 ) ;
for ( V_216 -> V_217 = 0 ; V_216 -> V_217 < V_11 ;
++ V_216 -> V_217 ) {
F_133 (sk, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_134 ( V_214 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static struct V_1 * F_135 ( struct V_213 * V_214 , struct V_1 * V_2 )
{
struct V_215 * V_216 = F_132 ( V_214 ) ;
do {
V_2 = F_25 ( V_2 ) ;
V_218:
;
} while ( V_2 && F_6 ( V_2 ) != F_134 ( V_214 ) );
if ( ! V_2 && ++ V_216 -> V_217 < V_11 ) {
V_2 = F_28 ( & V_216 -> V_4 -> V_9 [ V_216 -> V_217 ] ) ;
goto V_218;
}
return V_2 ;
}
static struct V_1 * F_136 ( struct V_213 * V_214 , T_7 V_219 )
{
struct V_1 * V_2 = F_131 ( V_214 ) ;
if ( V_2 )
while ( V_219 && ( V_2 = F_135 ( V_214 , V_2 ) ) != NULL )
-- V_219 ;
return V_219 ? NULL : V_2 ;
}
void * F_137 ( struct V_213 * V_214 , T_7 * V_219 )
{
struct V_215 * V_216 = F_132 ( V_214 ) ;
F_18 ( & V_216 -> V_4 -> V_12 ) ;
return * V_219 ? F_136 ( V_214 , * V_219 - 1 ) : V_220 ;
}
void * F_138 ( struct V_213 * V_214 , void * V_221 , T_7 * V_219 )
{
struct V_1 * V_2 ;
if ( V_221 == V_220 )
V_2 = F_131 ( V_214 ) ;
else
V_2 = F_135 ( V_214 , V_221 ) ;
++ * V_219 ;
return V_2 ;
}
void F_139 ( struct V_213 * V_214 , void * V_221 )
{
struct V_215 * V_216 = F_132 ( V_214 ) ;
F_26 ( & V_216 -> V_4 -> V_12 ) ;
}
static void F_140 ( struct V_213 * V_214 , struct V_1 * V_222 , int V_118 )
{
struct V_18 * V_19 = F_2 ( V_222 ) ;
T_1 V_223 = V_19 -> V_20 ,
V_224 = V_19 -> V_21 ;
T_8 V_225 = 0 ,
V_226 = V_19 -> V_10 ;
F_141 ( V_214 , L_2
L_3 ,
V_118 , V_224 , V_226 , V_223 , V_225 , V_222 -> V_53 ,
F_122 ( V_222 ) ,
F_142 ( V_222 ) ,
0 , 0L , 0 ,
F_143 ( F_144 ( V_214 ) , F_145 ( V_222 ) ) ,
0 , F_146 ( V_222 ) ,
F_147 ( & V_222 -> V_227 ) , V_222 , F_147 ( & V_222 -> V_75 ) ) ;
}
static int F_148 ( struct V_213 * V_214 , void * V_221 )
{
if ( V_221 == V_220 )
F_141 ( V_214 , L_4
L_5
L_6 ) ;
else
F_140 ( V_214 , V_221 , F_132 ( V_214 ) -> V_217 ) ;
return 0 ;
}
int F_149 ( struct V_228 * V_229 , struct V_230 * V_230 ,
struct V_3 * V_4 , const struct V_231 * V_232 )
{
int V_47 ;
struct V_215 * V_118 ;
V_47 = F_150 ( V_229 , V_230 , V_232 , sizeof( struct V_215 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_118 = F_132 ( (struct V_213 * ) V_230 -> V_233 ) ;
V_118 -> V_4 = V_4 ;
return 0 ;
}
static int F_151 ( struct V_228 * V_228 , struct V_230 * V_230 )
{
return F_149 ( V_228 , V_230 , & V_35 , & V_234 ) ;
}
static T_9 int F_152 ( struct V_13 * V_13 )
{
if ( ! F_153 ( L_7 , V_235 , V_13 -> V_236 , & V_237 ) )
return - V_238 ;
return 0 ;
}
static T_10 void F_154 ( struct V_13 * V_13 )
{
F_155 ( L_7 , V_13 -> V_236 ) ;
}
int T_11 F_156 ( void )
{
return F_157 ( & V_239 ) ;
}
void T_11 F_158 ( void )
{
F_159 ( & V_239 ) ;
}
