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
if ( V_32 -> V_38 != V_42 || ! F_13 ( V_2 , V_25 ) ) {
struct V_24 * V_43 = F_22 ( V_25 , V_44 ) ;
if ( V_43 )
F_23 ( V_2 , V_43 ) ;
}
V_2 = F_10 ( V_13 , F_24 ( V_2 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_25 -> V_37 -> V_41 ) ;
}
V_36:
F_25 ( & V_35 . V_12 ) ;
return V_34 ;
}
int F_26 ( struct V_24 * V_25 , int V_38 )
{
int V_33 ;
struct V_1 * F_16 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 && ! F_17 ( V_25 , F_28 ( V_25 ) , V_33 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_29 ( struct V_1 * V_2 , struct V_24 * V_25 , T_3 V_45 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
const int type = F_30 ( V_25 ) -> type ;
const int V_46 = F_30 ( V_25 ) -> V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( type == V_49 && V_46 == V_50 )
F_31 ( V_25 , V_2 , V_45 ) ;
else if ( type == V_51 ) {
F_32 ( V_25 , V_2 ) ;
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
F_33 ( V_2 , V_25 , V_47 , 0 , V_45 , V_67 ) ;
}
if ( V_19 -> V_52 || V_48 ) {
V_2 -> V_70 = V_47 ;
V_2 -> V_71 ( V_2 ) ;
}
}
void F_34 ( struct V_24 * V_25 , int V_38 , T_3 V_45 )
{
int V_33 ;
struct V_1 * F_16 ;
const struct V_31 * V_32 ;
struct V_13 * V_13 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_18 ( & V_35 . V_12 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 != NULL ) {
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
V_13 = F_20 ( V_25 -> V_37 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_38 ,
V_32 -> V_40 , V_32 -> V_39 ,
V_25 -> V_37 -> V_41 ) ) != NULL ) {
F_29 ( F_16 , V_25 , V_45 ) ;
F_16 = F_24 ( F_16 ) ;
V_32 = ( const struct V_31 * ) V_25 -> V_29 ;
}
}
F_25 ( & V_35 . V_12 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_36 ( V_2 , V_25 ) ;
if ( F_37 ( V_2 , V_25 ) < 0 ) {
F_38 ( V_25 ) ;
return V_72 ;
}
return V_73 ;
}
int F_23 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( ! F_39 ( V_2 , V_74 , V_25 ) ) {
F_40 ( & V_2 -> V_75 ) ;
F_38 ( V_25 ) ;
return V_72 ;
}
F_41 ( V_25 ) ;
F_42 ( V_25 , V_25 -> V_29 - F_43 ( V_25 ) ) ;
F_35 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_76 * V_77 ,
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
F_45 ( V_2 , V_66 , V_77 -> V_40 , V_19 -> V_89 ,
V_84 -> V_87 . V_37 -> V_88 ) ;
return - V_66 ;
}
if ( V_82 & V_90 )
goto V_36;
V_85 = F_46 ( V_84 -> V_87 . V_37 ) ;
V_86 = V_84 -> V_87 . V_37 -> V_91 ;
V_25 = F_47 ( V_2 ,
V_79 + V_85 + V_86 + 15 ,
V_82 & V_92 , & V_47 ) ;
if ( V_25 == NULL )
goto error;
F_48 ( V_25 , V_85 ) ;
V_25 -> V_93 = V_2 -> V_94 ;
V_25 -> V_95 = V_2 -> V_96 ;
F_49 ( V_25 , & V_84 -> V_87 ) ;
* V_81 = NULL ;
F_50 ( V_25 ) ;
V_32 = F_28 ( V_25 ) ;
F_51 ( V_25 , V_79 ) ;
V_25 -> V_97 = V_98 ;
V_25 -> V_99 = V_25 -> V_100 ;
V_47 = - V_101 ;
if ( F_52 ( ( void * ) V_32 , V_78 , 0 , V_79 ) )
goto V_102;
V_83 = V_32 -> V_68 * 4 ;
V_47 = - V_103 ;
if ( V_83 > V_79 )
goto V_102;
if ( V_83 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_77 -> V_39 ;
V_32 -> V_104 = 0 ;
V_32 -> V_105 = F_53 ( V_79 ) ;
if ( ! V_32 -> V_106 )
F_54 ( V_25 , & V_84 -> V_87 , NULL ) ;
V_32 -> V_104 = F_55 ( ( unsigned char * ) V_32 , V_32 -> V_68 ) ;
}
if ( V_32 -> V_38 == V_42 )
F_56 ( V_13 , ( (struct V_26 * )
F_57 ( V_25 ) ) -> type ) ;
V_47 = F_58 ( V_107 , V_108 , V_25 , NULL ,
V_84 -> V_87 . V_37 , V_109 ) ;
if ( V_47 > 0 )
V_47 = F_59 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_102:
F_38 ( V_25 ) ;
error:
F_60 ( V_13 , V_110 ) ;
if ( V_47 == - V_111 && ! V_19 -> V_52 )
V_47 = 0 ;
return V_47 ;
}
static int F_61 ( struct V_76 * V_77 , struct V_112 * V_113 )
{
struct V_114 * V_115 ;
T_4 T_6 * type = NULL ;
T_4 T_6 * V_46 = NULL ;
int V_116 = 0 ;
unsigned int V_117 ;
if ( ! V_113 -> V_118 )
return 0 ;
for ( V_117 = 0 ; V_117 < V_113 -> V_119 ; V_117 ++ ) {
V_115 = & V_113 -> V_118 [ V_117 ] ;
if ( ! V_115 )
continue;
switch ( V_77 -> V_120 ) {
case V_42 :
if ( V_115 -> V_121 && V_115 -> V_122 < 1 )
break;
if ( ! type ) {
type = V_115 -> V_121 ;
if ( V_115 -> V_122 > 1 )
V_46 = type + 1 ;
} else if ( ! V_46 )
V_46 = V_115 -> V_121 ;
if ( type && V_46 ) {
if ( F_62 ( V_77 -> V_123 , type ) ||
F_62 ( V_77 -> V_124 , V_46 ) )
return - V_101 ;
V_116 = 1 ;
}
break;
default:
V_116 = 1 ;
break;
}
if ( V_116 )
break;
}
return 0 ;
}
static int F_63 ( struct V_125 * V_126 , struct V_1 * V_2 , struct V_112 * V_113 ,
T_5 V_127 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_128 V_129 ;
struct V_80 * V_84 = NULL ;
struct V_76 V_77 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_4 V_130 ;
int V_47 ;
struct V_131 V_132 ;
V_47 = - V_66 ;
if ( V_127 > 0xFFFF )
goto V_36;
V_47 = - V_133 ;
if ( V_113 -> V_134 & V_135 )
goto V_36;
if ( V_113 -> V_136 ) {
struct V_137 * V_138 = (struct V_137 * ) V_113 -> V_139 ;
V_47 = - V_103 ;
if ( V_113 -> V_136 < sizeof( * V_138 ) )
goto V_36;
if ( V_138 -> V_140 != V_141 ) {
F_64 ( L_1 ,
V_142 , V_143 -> V_144 ) ;
V_47 = - V_145 ;
if ( V_138 -> V_140 )
goto V_36;
}
V_40 = V_138 -> V_146 . V_147 ;
} else {
V_47 = - V_148 ;
if ( V_2 -> V_53 != V_54 )
goto V_36;
V_40 = V_19 -> V_20 ;
}
V_129 . V_149 = V_19 -> V_150 ;
V_129 . V_151 = NULL ;
V_129 . V_152 = 0 ;
V_129 . V_153 = 0 ;
V_129 . V_130 = - 1 ;
V_129 . V_154 = V_2 -> V_22 ;
if ( V_113 -> V_155 ) {
V_47 = F_65 ( F_6 ( V_2 ) , V_113 , & V_129 ) ;
if ( V_47 )
goto V_36;
if ( V_129 . V_151 )
free = 1 ;
}
V_39 = V_129 . V_149 ;
V_129 . V_149 = V_40 ;
if ( ! V_129 . V_151 ) {
struct V_156 * V_157 ;
F_66 () ;
V_157 = F_67 ( V_19 -> V_157 ) ;
if ( V_157 ) {
memcpy ( & V_132 , V_157 ,
sizeof( * V_157 ) + V_157 -> V_151 . V_158 ) ;
V_129 . V_151 = & V_132 . V_151 ;
}
F_68 () ;
}
if ( V_129 . V_151 ) {
V_47 = - V_103 ;
if ( V_19 -> V_69 )
goto V_159;
if ( V_129 . V_151 -> V_151 . V_160 ) {
if ( ! V_40 )
goto V_159;
V_40 = V_129 . V_151 -> V_151 . V_161 ;
}
}
V_130 = F_69 ( & V_129 , V_2 ) ;
if ( V_113 -> V_134 & V_162 )
V_130 |= V_163 ;
if ( F_70 ( V_40 ) ) {
if ( ! V_129 . V_154 )
V_129 . V_154 = V_19 -> V_164 ;
if ( ! V_39 )
V_39 = V_19 -> V_165 ;
} else if ( ! V_129 . V_154 )
V_129 . V_154 = V_19 -> V_166 ;
F_71 ( & V_77 , V_129 . V_154 , V_2 -> V_96 , V_130 ,
V_167 ,
V_19 -> V_69 ? V_168 : V_2 -> V_169 ,
F_72 ( V_2 ) | V_170 |
( V_19 -> V_69 ? V_171 : 0 ) ,
V_40 , V_39 , 0 , 0 ) ;
if ( ! V_19 -> V_69 ) {
V_47 = F_61 ( & V_77 , V_113 ) ;
if ( V_47 )
goto V_159;
}
F_73 ( V_2 , F_74 ( & V_77 ) ) ;
V_84 = F_75 ( F_6 ( V_2 ) , & V_77 , V_2 ) ;
if ( F_76 ( V_84 ) ) {
V_47 = F_77 ( V_84 ) ;
V_84 = NULL ;
goto V_159;
}
V_47 = - V_172 ;
if ( V_84 -> V_173 & V_174 && ! F_78 ( V_2 , V_175 ) )
goto V_159;
if ( V_113 -> V_134 & V_176 )
goto V_177;
V_178:
if ( V_19 -> V_69 )
V_47 = F_44 ( V_2 , & V_77 , V_113 -> V_118 , V_127 ,
& V_84 , V_113 -> V_134 ) ;
else {
if ( ! V_129 . V_149 )
V_129 . V_149 = V_77 . V_40 ;
F_79 ( V_2 ) ;
V_47 = F_80 ( V_2 , & V_77 , V_179 ,
V_113 -> V_118 , V_127 , 0 ,
& V_129 , & V_84 , V_113 -> V_134 ) ;
if ( V_47 )
F_81 ( V_2 ) ;
else if ( ! ( V_113 -> V_134 & V_180 ) ) {
V_47 = F_82 ( V_2 , & V_77 ) ;
if ( V_47 == - V_111 && ! V_19 -> V_52 )
V_47 = 0 ;
}
F_83 ( V_2 ) ;
}
V_159:
if ( free )
F_84 ( V_129 . V_151 ) ;
F_85 ( V_84 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_127 ;
V_177:
F_86 ( & V_84 -> V_87 ) ;
if ( ! ( V_113 -> V_134 & V_90 ) || V_127 )
goto V_178;
V_47 = 0 ;
goto V_159;
}
static void F_87 ( struct V_1 * V_2 , long V_181 )
{
F_88 ( V_2 , 0 , NULL ) ;
F_89 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
F_81 ( V_2 ) ;
F_83 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_182 * V_183 , int V_184 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
struct V_137 * V_149 = (struct V_137 * ) V_183 ;
int V_185 = - V_103 ;
int V_186 ;
if ( V_2 -> V_53 != V_187 || V_184 < sizeof( struct V_137 ) )
goto V_36;
V_186 = F_92 ( F_6 ( V_2 ) , V_149 -> V_146 . V_147 ) ;
V_185 = - V_188 ;
if ( V_149 -> V_146 . V_147 && V_186 != V_189 &&
V_186 != V_190 && V_186 != V_191 )
goto V_36;
V_19 -> V_21 = V_19 -> V_150 = V_149 -> V_146 . V_147 ;
if ( V_186 == V_190 || V_186 == V_191 )
V_19 -> V_150 = 0 ;
F_93 ( V_2 ) ;
V_185 = 0 ;
V_36: return V_185 ;
}
static int F_94 ( struct V_125 * V_126 , struct V_1 * V_2 , struct V_112 * V_113 ,
T_5 V_127 , int V_192 , int V_82 , int * V_184 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_5 V_193 = 0 ;
int V_47 = - V_133 ;
struct V_137 * sin = (struct V_137 * ) V_113 -> V_139 ;
struct V_24 * V_25 ;
if ( V_82 & V_135 )
goto V_36;
if ( V_82 & V_194 ) {
V_47 = F_95 ( V_2 , V_113 , V_127 , V_184 ) ;
goto V_36;
}
V_25 = F_96 ( V_2 , V_82 , V_192 , & V_47 ) ;
if ( ! V_25 )
goto V_36;
V_193 = V_25 -> V_127 ;
if ( V_127 < V_193 ) {
V_113 -> V_134 |= V_195 ;
V_193 = V_127 ;
}
V_47 = F_97 ( V_25 , 0 , V_113 -> V_118 , V_193 ) ;
if ( V_47 )
goto V_159;
F_98 ( V_113 , V_2 , V_25 ) ;
if ( sin ) {
sin -> V_140 = V_141 ;
sin -> V_146 . V_147 = F_28 ( V_25 ) -> V_39 ;
sin -> V_196 = 0 ;
memset ( & sin -> V_197 , 0 , sizeof( sin -> V_197 ) ) ;
* V_184 = sizeof( * sin ) ;
}
if ( V_19 -> V_198 )
F_99 ( V_113 , V_25 ) ;
if ( V_82 & V_195 )
V_193 = V_25 -> V_127 ;
V_159:
F_100 ( V_2 , V_25 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_193 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_200 -> V_30 , 0 , sizeof( V_200 -> V_30 ) ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , char T_6 * V_201 , int V_158 )
{
if ( V_158 > sizeof( struct F_13 ) )
V_158 = sizeof( struct F_13 ) ;
if ( F_103 ( & F_16 ( V_2 ) -> V_30 , V_201 , V_158 ) )
return - V_101 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , char T_6 * V_201 , int T_6 * V_158 )
{
int V_127 , V_185 = - V_101 ;
if ( F_62 ( V_127 , V_158 ) )
goto V_36;
V_185 = - V_103 ;
if ( V_127 < 0 )
goto V_36;
if ( V_127 > sizeof( struct F_13 ) )
V_127 = sizeof( struct F_13 ) ;
V_185 = - V_101 ;
if ( F_105 ( V_127 , V_158 ) ||
F_106 ( V_201 , & F_16 ( V_2 ) -> V_30 , V_127 ) )
goto V_36;
V_185 = 0 ;
V_36: return V_185 ;
}
static int F_107 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_158 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_133 ;
else
return F_102 ( V_2 , V_201 , V_158 ) ;
}
return - V_205 ;
}
static int F_108 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_158 )
{
if ( V_202 != V_206 )
return F_109 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
return F_107 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
}
static int F_110 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , unsigned int V_158 )
{
if ( V_202 != V_206 )
return F_111 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
return F_107 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
}
static int F_112 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_158 )
{
if ( V_203 == V_204 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_133 ;
else
return F_104 ( V_2 , V_201 , V_158 ) ;
}
return - V_205 ;
}
static int F_113 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_158 )
{
if ( V_202 != V_206 )
return F_114 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
return F_112 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
}
static int F_115 ( struct V_1 * V_2 , int V_202 , int V_203 ,
char T_6 * V_201 , int T_6 * V_158 )
{
if ( V_202 != V_206 )
return F_116 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
return F_112 ( V_2 , V_202 , V_203 , V_201 , V_158 ) ;
}
static int F_117 ( struct V_1 * V_2 , int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 : {
int V_210 = F_118 ( V_2 ) ;
return F_105 ( V_210 , ( int T_6 * ) V_208 ) ;
}
case V_211 : {
struct V_24 * V_25 ;
int V_210 = 0 ;
F_119 ( & V_2 -> V_212 . V_12 ) ;
V_25 = F_120 ( & V_2 -> V_212 ) ;
if ( V_25 != NULL )
V_210 = V_25 -> V_127 ;
F_121 ( & V_2 -> V_212 . V_12 ) ;
return F_105 ( V_210 , ( int T_6 * ) V_208 ) ;
}
default:
#ifdef F_122
return F_123 ( V_2 , V_207 , ( void T_6 * ) V_208 ) ;
#else
return - V_213 ;
#endif
}
}
static int F_124 ( struct V_1 * V_2 , unsigned int V_207 , unsigned long V_208 )
{
switch ( V_207 ) {
case V_209 :
case V_211 :
return - V_213 ;
default:
#ifdef F_122
return F_125 ( V_2 , V_207 , F_126 ( V_208 ) ) ;
#else
return - V_213 ;
#endif
}
}
static struct V_1 * F_127 ( struct V_214 * V_215 )
{
struct V_1 * V_2 ;
struct V_216 * V_217 = F_128 ( V_215 ) ;
for ( V_217 -> V_218 = 0 ; V_217 -> V_218 < V_11 ;
++ V_217 -> V_218 ) {
F_129 (sk, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_130 ( V_215 ) )
goto V_23;
}
V_2 = NULL ;
V_23:
return V_2 ;
}
static struct V_1 * F_131 ( struct V_214 * V_215 , struct V_1 * V_2 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
do {
V_2 = F_24 ( V_2 ) ;
V_219:
;
} while ( V_2 && F_6 ( V_2 ) != F_130 ( V_215 ) );
if ( ! V_2 && ++ V_217 -> V_218 < V_11 ) {
V_2 = F_27 ( & V_217 -> V_4 -> V_9 [ V_217 -> V_218 ] ) ;
goto V_219;
}
return V_2 ;
}
static struct V_1 * F_132 ( struct V_214 * V_215 , T_7 V_220 )
{
struct V_1 * V_2 = F_127 ( V_215 ) ;
if ( V_2 )
while ( V_220 && ( V_2 = F_131 ( V_215 , V_2 ) ) != NULL )
-- V_220 ;
return V_220 ? NULL : V_2 ;
}
void * F_133 ( struct V_214 * V_215 , T_7 * V_220 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
F_18 ( & V_217 -> V_4 -> V_12 ) ;
return * V_220 ? F_132 ( V_215 , * V_220 - 1 ) : V_221 ;
}
void * F_134 ( struct V_214 * V_215 , void * V_222 , T_7 * V_220 )
{
struct V_1 * V_2 ;
if ( V_222 == V_221 )
V_2 = F_127 ( V_215 ) ;
else
V_2 = F_131 ( V_215 , V_222 ) ;
++ * V_220 ;
return V_2 ;
}
void F_135 ( struct V_214 * V_215 , void * V_222 )
{
struct V_216 * V_217 = F_128 ( V_215 ) ;
F_25 ( & V_217 -> V_4 -> V_12 ) ;
}
static void F_136 ( struct V_214 * V_215 , struct V_1 * V_223 , int V_117 )
{
struct V_18 * V_19 = F_2 ( V_223 ) ;
T_1 V_224 = V_19 -> V_20 ,
V_225 = V_19 -> V_21 ;
T_8 V_226 = 0 ,
V_227 = V_19 -> V_10 ;
F_137 ( V_215 , L_2
L_3 ,
V_117 , V_225 , V_227 , V_224 , V_226 , V_223 -> V_53 ,
F_118 ( V_223 ) ,
F_138 ( V_223 ) ,
0 , 0L , 0 ,
F_139 ( F_140 ( V_215 ) , F_141 ( V_223 ) ) ,
0 , F_142 ( V_223 ) ,
F_143 ( & V_223 -> V_228 ) , V_223 , F_143 ( & V_223 -> V_75 ) ) ;
}
static int F_144 ( struct V_214 * V_215 , void * V_222 )
{
if ( V_222 == V_221 )
F_137 ( V_215 , L_4
L_5
L_6 ) ;
else
F_136 ( V_215 , V_222 , F_128 ( V_215 ) -> V_218 ) ;
return 0 ;
}
int F_145 ( struct V_229 * V_230 , struct V_231 * V_231 ,
struct V_3 * V_4 , const struct V_232 * V_233 )
{
int V_47 ;
struct V_216 * V_117 ;
V_47 = F_146 ( V_230 , V_231 , V_233 , sizeof( struct V_216 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_117 = F_128 ( (struct V_214 * ) V_231 -> V_234 ) ;
V_117 -> V_4 = V_4 ;
return 0 ;
}
static int F_147 ( struct V_229 * V_229 , struct V_231 * V_231 )
{
return F_145 ( V_229 , V_231 , & V_35 , & V_235 ) ;
}
static T_9 int F_148 ( struct V_13 * V_13 )
{
if ( ! F_149 ( L_7 , V_236 , V_13 -> V_237 , & V_238 ) )
return - V_239 ;
return 0 ;
}
static T_10 void F_150 ( struct V_13 * V_13 )
{
F_151 ( L_7 , V_13 -> V_237 ) ;
}
int T_11 F_152 ( void )
{
return F_153 ( & V_240 ) ;
}
void T_11 F_154 ( void )
{
F_155 ( & V_240 ) ;
}
