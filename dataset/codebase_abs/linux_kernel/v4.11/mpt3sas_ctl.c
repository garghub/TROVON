static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 , * V_6 ;
V_6 = NULL ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_5 -> V_4 != V_4 )
continue;
V_6 = V_5 ;
goto V_7;
}
V_7:
return V_6 ;
}
static void
F_3 ( struct V_2 * V_3 , T_1 V_8 ,
char * V_9 , T_2 * V_10 )
{
T_3 * V_11 ;
char * V_12 = NULL ;
if ( ! ( V_3 -> V_13 & V_14 ) )
return;
V_11 = F_4 ( V_3 , V_8 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
{
T_4 * V_17 =
( T_4 * ) V_11 ;
snprintf ( V_3 -> V_18 , V_19 ,
L_1 ,
V_17 -> V_20 . V_21 [ 0 ] ,
F_5 ( V_17 -> V_22 ) & 0xF ) ;
V_12 = V_3 -> V_18 ;
break;
}
case V_23 :
V_12 = L_2 ;
break;
case V_24 :
V_12 = L_3 ;
break;
case V_25 :
V_12 = L_4 ;
break;
case V_26 :
{
T_3 * V_27 =
( T_3 * ) V_11 ;
snprintf ( V_3 -> V_18 , V_19 ,
L_5 ,
( V_27 -> V_28 . V_29 &
V_30 ) , V_27 -> V_31 ,
V_27 -> V_28 . V_32 ) ;
V_12 = V_3 -> V_18 ;
break;
}
case V_33 :
V_12 = L_6 ;
break;
case V_34 :
V_12 = L_7 ;
break;
case V_35 :
V_12 = L_8 ;
break;
case V_36 :
V_12 = L_9 ;
break;
case V_37 :
V_12 = L_10 ;
break;
case V_38 :
V_12 = L_11 ;
break;
case V_39 :
{
T_4 * V_17 =
( T_4 * ) V_11 ;
snprintf ( V_3 -> V_18 , V_19 ,
L_12 ,
V_17 -> V_20 . V_21 [ 0 ] ,
F_5 ( V_17 -> V_22 ) & 0xF ) ;
V_12 = V_3 -> V_18 ;
break;
}
case V_40 :
V_12 = L_13 ;
break;
case V_41 :
V_12 = L_14 ;
break;
case V_42 :
V_12 = L_15 ;
break;
case V_43 :
V_12 = L_16 ;
break;
case V_44 :
V_12 = L_17 ;
break;
}
if ( ! V_12 )
return;
F_6 ( V_45 L_18 ,
V_3 -> V_46 , V_9 , V_12 , V_8 ) ;
if ( ! V_10 )
return;
if ( V_10 -> V_47 || V_10 -> V_48 )
F_6 ( V_45
L_19 ,
V_3 -> V_46 , F_5 ( V_10 -> V_47 ) ,
F_7 ( V_10 -> V_48 ) ) ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ) {
T_5 * V_49 =
( T_5 * ) V_10 ;
struct V_1 * V_5 = NULL ;
unsigned long V_50 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
V_5 = F_1 ( V_3 ,
F_5 ( V_49 -> V_52 ) ) ;
if ( V_5 ) {
F_9 ( V_45 L_20 ,
V_3 -> V_46 , ( unsigned long long )
V_5 -> V_53 , V_5 -> V_54 ) ;
F_9 ( V_45
L_21 ,
V_3 -> V_46 , ( unsigned long long )
V_5 -> V_55 , V_5 -> V_56 ) ;
}
F_10 ( & V_3 -> V_51 , V_50 ) ;
if ( V_49 -> V_57 || V_49 -> V_58 )
F_6 ( V_45
L_22
L_23 , V_3 -> V_46 ,
V_49 -> V_57 ,
V_49 -> V_58 ) ;
}
}
T_6
F_11 ( struct V_2 * V_3 , T_1 V_8 , T_6 V_59 ,
T_7 V_60 )
{
T_2 * V_10 ;
T_5 * V_61 ;
const void * V_62 ;
T_7 V_63 ;
if ( V_3 -> V_64 . V_65 == V_66 )
return 1 ;
if ( V_3 -> V_64 . V_8 != V_8 )
return 1 ;
V_3 -> V_64 . V_65 |= V_67 ;
V_10 = F_12 ( V_3 , V_60 ) ;
if ( V_10 ) {
memcpy ( V_3 -> V_64 . V_60 , V_10 , V_10 -> V_68 * 4 ) ;
V_3 -> V_64 . V_65 |= V_69 ;
if ( V_10 -> V_15 == V_16 ||
V_10 -> V_15 ==
V_39 ) {
V_61 = ( T_5 * ) V_10 ;
if ( V_61 -> V_57 &
V_70 ) {
V_63 = F_13 ( T_7 , V_71 ,
F_7 ( V_61 -> V_72 ) ) ;
V_62 = F_14 ( V_3 ,
V_8 ) ;
memcpy ( V_3 -> V_64 . V_73 , V_62 , V_63 ) ;
}
}
}
F_3 ( V_3 , V_8 , L_24 , V_10 ) ;
V_3 -> V_64 . V_65 &= ~ V_74 ;
F_15 ( & V_3 -> V_64 . V_75 ) ;
return 1 ;
}
static int
F_16 ( struct V_2 * V_3 , T_1 V_76 )
{
T_1 V_77 ;
T_7 V_78 ;
if ( V_76 >= 128 || ! V_76 || ! V_3 -> V_79 )
return 0 ;
V_78 = ( 1 << ( V_76 % 32 ) ) ;
if ( ! V_78 )
V_78 = 1 ;
V_77 = V_76 / 32 ;
return V_78 & V_3 -> V_80 [ V_77 ] ;
}
void
F_17 ( struct V_2 * V_3 ,
T_8 * V_10 )
{
struct V_81 * V_79 ;
T_1 V_76 ;
int V_77 ;
T_7 V_63 , V_82 ;
T_6 V_83 = 0 ;
if ( ! V_3 -> V_79 )
return;
V_76 = F_5 ( V_10 -> V_84 ) ;
if ( F_16 ( V_3 , V_76 ) ) {
V_77 = V_3 -> V_85 % V_86 ;
V_79 = V_3 -> V_79 ;
V_79 [ V_77 ] . V_76 = V_76 ;
V_79 [ V_77 ] . V_87 = V_3 -> V_85 ++ ;
V_82 = F_5 ( V_10 -> V_88 ) * 4 ;
V_63 = F_13 ( T_7 , V_82 , V_89 ) ;
memset ( V_79 [ V_77 ] . V_90 , 0 , V_89 ) ;
memcpy ( V_79 [ V_77 ] . V_90 , V_10 -> V_91 , V_63 ) ;
V_83 = 1 ;
}
if ( V_76 == V_92 ||
( V_83 && ! V_3 -> V_93 ) ) {
V_3 -> V_93 = 1 ;
F_18 ( & V_94 ) ;
if ( V_95 )
F_19 ( & V_95 , V_96 , V_97 ) ;
}
}
T_6
F_20 ( struct V_2 * V_3 , T_6 V_59 ,
T_7 V_60 )
{
T_8 * V_10 ;
V_10 = F_12 ( V_3 , V_60 ) ;
if ( V_10 )
F_17 ( V_3 , V_10 ) ;
return 1 ;
}
static int
F_21 ( int V_98 , struct V_2 * * V_99 ,
int V_100 )
{
struct V_2 * V_3 ;
int V_101 = 0 ;
F_22 ( & V_102 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_103 != V_98 )
continue;
V_101 = V_3 -> V_104 ;
if ( V_100 == ( V_105 | V_106 ) ) {
if ( ( V_101 == V_105 ) ||
( V_101 == V_106 ) )
goto V_7;
else
continue;
} else {
if ( V_101 != V_100 )
continue;
}
V_7:
F_23 ( & V_102 ) ;
* V_99 = V_3 ;
return V_98 ;
}
F_23 ( & V_102 ) ;
* V_99 = NULL ;
return - 1 ;
}
void
F_24 ( struct V_2 * V_3 , int V_107 )
{
int V_77 ;
T_6 V_108 ;
switch ( V_107 ) {
case V_109 :
F_25 ( V_3 , F_6 ( V_45
L_25 , V_3 -> V_46 , V_110 ) ) ;
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
F_26 ( V_3 , V_77 , & V_108 ) ;
}
break;
case V_115 :
F_25 ( V_3 , F_6 ( V_45
L_26 , V_3 -> V_46 , V_110 ) ) ;
if ( V_3 -> V_64 . V_65 & V_74 ) {
V_3 -> V_64 . V_65 |= V_116 ;
F_27 ( V_3 , V_3 -> V_64 . V_8 ) ;
F_15 ( & V_3 -> V_64 . V_75 ) ;
}
break;
case V_117 :
F_25 ( V_3 , F_6 ( V_45
L_27 , V_3 -> V_46 , V_110 ) ) ;
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
V_3 -> V_112 [ V_77 ] |=
V_118 ;
}
break;
}
}
static int
F_28 ( int V_119 , struct V_120 * V_121 , int V_122 )
{
return F_29 ( V_119 , V_121 , V_122 , & V_95 ) ;
}
static unsigned int
F_30 ( struct V_120 * V_121 , T_9 * V_123 )
{
struct V_2 * V_3 ;
F_31 ( V_121 , & V_94 , V_123 ) ;
F_22 ( & V_102 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_93 ) {
F_23 ( & V_102 ) ;
return V_124 | V_125 ;
}
}
F_23 ( & V_102 ) ;
return 0 ;
}
static int
F_32 ( struct V_2 * V_3 , struct V_126 * V_127 ,
T_10 * V_128 )
{
T_6 V_129 = 0 ;
T_1 V_77 ;
T_1 V_4 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned long V_50 ;
T_11 * V_134 ;
T_7 V_63 ;
T_7 V_135 ;
char * V_12 = NULL ;
if ( V_128 -> V_136 == V_137 )
V_12 = L_28 ;
else if ( V_128 -> V_136 == V_138 )
V_12 = L_29 ;
else
return 0 ;
V_135 = F_33 ( (struct V_139 * ) V_128 -> V_140 ) ;
V_4 = F_5 ( V_128 -> V_52 ) ;
F_8 ( & V_3 -> V_141 , V_50 ) ;
for ( V_77 = V_3 -> V_142 ; V_77 && ! V_129 ; V_77 -- ) {
V_131 = V_3 -> V_143 [ V_77 - 1 ] . V_131 ;
if ( V_131 == NULL || V_131 -> V_144 == NULL ||
V_131 -> V_144 -> V_145 == NULL )
continue;
if ( V_135 != V_131 -> V_144 -> V_135 )
continue;
V_133 = V_131 -> V_144 -> V_145 ;
if ( V_133 -> V_146 == NULL )
continue;
if ( V_133 -> V_146 -> V_4 != V_4 )
continue;
V_128 -> V_147 = F_34 ( V_3 -> V_143 [ V_77 - 1 ] . V_8 ) ;
V_129 = 1 ;
}
F_10 ( & V_3 -> V_141 , V_50 ) ;
if ( ! V_129 ) {
F_35 ( V_3 , F_6 ( V_45
L_30 ,
V_3 -> V_46 ,
V_12 , F_5 ( V_128 -> V_52 ) , V_135 ) ) ;
V_134 = V_3 -> V_64 . V_60 ;
V_134 -> V_52 = V_128 -> V_52 ;
V_134 -> V_15 = V_23 ;
V_134 -> V_136 = V_128 -> V_136 ;
V_134 -> V_68 = sizeof( T_11 ) / 4 ;
V_134 -> V_148 = V_128 -> V_148 ;
V_134 -> V_149 = V_128 -> V_149 ;
V_63 = F_13 ( T_7 , V_127 -> V_150 , V_3 -> V_151 ) ;
if ( F_36 ( V_127 -> V_152 , V_3 -> V_64 . V_60 ,
V_63 ) )
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
return 1 ;
}
F_35 ( V_3 , F_6 ( V_45
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_128 -> V_52 ) , V_135 ,
F_5 ( V_128 -> V_147 ) ) ) ;
return 0 ;
}
static long
F_38 ( struct V_2 * V_3 , struct V_126 V_127 ,
void T_12 * V_153 )
{
T_13 * V_11 = NULL , * V_154 ;
T_2 * V_10 ;
T_7 V_155 ;
T_1 V_8 ;
unsigned long V_156 ;
T_6 V_108 ;
T_7 V_63 ;
void * V_157 ;
void * V_158 = NULL ;
T_14 V_159 = 0 ;
T_15 V_160 = 0 ;
void * V_161 = NULL ;
T_14 V_162 = 0 ;
T_15 V_163 = 0 ;
long V_164 ;
T_1 V_165 ;
T_1 V_166 = V_167 ;
V_108 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_168 ;
goto V_7;
}
V_165 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
while ( V_155 != V_169 ) {
if ( V_165 ++ == 10 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_170 ;
goto V_7;
}
F_40 ( 1 ) ;
V_155 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45
L_35 ,
V_3 -> V_46 ,
V_110 , V_165 ) ;
}
if ( V_165 )
F_6 ( V_45 L_36 ,
V_3 -> V_46 , V_110 ) ;
V_11 = F_41 ( V_3 -> V_171 , V_172 ) ;
if ( ! V_11 ) {
F_37 ( V_45
L_37 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_173 ;
goto V_7;
}
if ( V_127 . V_174 * 4 > V_3 -> V_171 ||
V_127 . V_174 > ( V_175 / 4 ) ) {
V_164 = - V_176 ;
goto V_7;
}
if ( F_42 ( V_11 , V_153 , V_127 . V_174 * 4 ) ) {
F_37 ( L_31 , __FILE__ , __LINE__ ,
V_110 ) ;
V_164 = - V_170 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_168 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_177 , NULL ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_168 ;
goto V_7;
}
}
V_164 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_154 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_154 , V_11 , V_127 . V_174 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_160 = V_127 . V_178 ;
V_163 = V_127 . V_179 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ||
V_11 -> V_15 == V_23 ||
V_11 -> V_15 == V_41 ) {
V_166 = F_5 ( V_11 -> V_180 ) ;
if ( ! V_166 || ( V_166 >
V_3 -> V_181 . V_182 ) ) {
V_164 = - V_176 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_160 ) {
V_158 = F_45 ( V_3 -> V_183 , V_160 ,
& V_159 ) ;
if ( ! V_158 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_173 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_158 , V_127 . V_184 ,
V_160 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_170 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_163 ) {
V_161 = F_45 ( V_3 -> V_183 , V_163 ,
& V_162 ) ;
if ( ! V_161 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_173 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_157 = ( void * ) V_154 + ( V_127 . V_174 * 4 ) ;
F_3 ( V_3 , V_8 , L_39 , NULL ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_185 =
( T_4 * ) V_154 ;
V_185 -> V_186 = V_71 ;
V_185 -> V_187 =
F_47 ( V_3 , V_8 ) ;
memset ( V_3 -> V_64 . V_73 , 0 , V_71 ) ;
if ( F_48 ( V_166 , V_3 -> V_188 ) ) {
F_25 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 , V_166 ) ) ;
F_27 ( V_3 , V_8 ) ;
V_164 = - V_176 ;
goto V_7;
}
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
if ( V_11 -> V_15 == V_16 )
V_3 -> V_190 ( V_3 , V_8 , V_166 ) ;
else
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_128 =
( T_10 * ) V_154 ;
F_25 ( V_3 , F_6 ( V_45
L_41 ,
V_3 -> V_46 ,
F_5 ( V_128 -> V_52 ) , V_128 -> V_136 ) ) ;
V_3 -> V_192 = 1 ;
if ( V_128 -> V_136 ==
V_137 ||
V_128 -> V_136 ==
V_138 ) {
if ( F_32 ( V_3 , & V_127 , V_128 ) ) {
F_27 ( V_3 , V_8 ) ;
V_3 -> V_192 = 0 ;
goto V_7;
}
}
V_3 -> V_192 = 0 ;
if ( F_48 ( V_166 , V_3 -> V_188 ) ) {
F_25 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 , V_166 ) ) ;
F_27 ( V_3 , V_8 ) ;
V_164 = - V_176 ;
goto V_7;
}
F_49 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
V_3 -> V_193 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
V_3 -> V_194 ( V_3 , V_8 , 0 ) ;
break;
}
case V_44 :
{
T_16 * V_195 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_195 -> V_196 = 0xFF ;
if ( V_195 -> V_197 &
V_198 )
V_90 = ( T_6 * ) & V_195 -> V_199 ;
else {
if ( F_50 ( V_158 == NULL ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
F_27 ( V_3 , V_8 ) ;
V_164 = - V_176 ;
goto V_7;
}
V_90 = V_158 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_200 = 1 ;
V_3 -> V_201 = 1 ;
}
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 , V_162 ,
V_163 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_41 :
{
if ( F_48 ( V_166 , V_3 -> V_188 ) ) {
F_25 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 , V_166 ) ) ;
F_27 ( V_3 , V_8 ) ;
V_164 = - V_176 ;
goto V_7;
}
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 , V_162 ,
V_163 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_36 :
case V_37 :
{
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 , V_162 ,
V_163 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_202 :
{
T_17 * V_203 =
( T_17 * ) V_11 ;
if ( V_203 -> V_204 == V_205 ) {
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
} else {
V_3 -> V_193 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
}
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_206 =
( T_18 * ) V_11 ;
if ( V_206 -> V_207 == V_208
|| V_206 -> V_207 ==
V_209 ) {
V_3 -> V_200 = 1 ;
V_3 -> V_201 = 1 ;
}
}
default:
V_3 -> V_193 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
if ( V_127 . V_156 < V_210 )
V_156 = V_210 ;
else
V_156 = V_127 . V_156 ;
F_51 ( & V_3 -> V_64 . V_75 , V_156 * V_211 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_128 =
( T_10 * ) V_11 ;
F_52 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
F_53 ( V_3 , V_212 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_200 ) {
V_3 -> V_200 = 0 ;
V_3 -> V_201 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 , V_127 . V_174 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_213;
}
V_10 = V_3 -> V_64 . V_60 ;
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_214 ) ) {
T_11 * V_134 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_43 \
L_44
L_45 , V_3 -> V_46 ,
F_5 ( V_134 -> V_47 ) ,
F_7 ( V_134 -> V_48 ) ,
F_7 ( V_134 -> V_215 ) ) ;
}
if ( V_163 ) {
if ( F_36 ( V_127 . V_216 , V_161 ,
V_163 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_217 ;
goto V_7;
}
}
if ( V_127 . V_150 ) {
V_63 = F_13 ( T_7 , V_127 . V_150 , V_3 -> V_151 ) ;
if ( F_36 ( V_127 . V_152 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_217 ;
goto V_7;
}
}
if ( V_127 . V_218 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_127 . V_218 , V_71 ) ;
if ( F_36 ( V_127 . V_219 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_217 ;
goto V_7;
}
}
V_213:
if ( V_108 ) {
V_164 = - V_217 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_46 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_180 ) ) ;
F_55 ( V_3 ) ;
F_56 ( V_3 ,
F_5 ( V_11 -> V_180 ) , 0 , 0 ,
0 , V_220 , 0 , 30 ) ;
} else
F_57 ( V_3 , V_221 ) ;
}
V_7:
if ( V_161 )
F_58 ( V_3 -> V_183 , V_163 , V_161 ,
V_162 ) ;
if ( V_158 )
F_58 ( V_3 -> V_183 , V_160 , V_158 ,
V_159 ) ;
F_59 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_164 ;
}
static long
F_60 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_223 V_127 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( V_3 -> V_224 )
V_127 . V_225 = V_3 -> V_224 [ 0 ] . V_226 ;
V_127 . V_227 = V_3 -> V_183 -> V_228 ;
V_127 . V_229 = V_3 -> V_183 -> V_144 ;
V_127 . V_230 = V_3 -> V_183 -> V_230 ;
V_127 . V_231 = V_3 -> V_183 -> V_231 ;
V_127 . V_232 . V_233 . V_234 . V_235 = V_3 -> V_183 -> V_235 -> V_236 ;
V_127 . V_232 . V_233 . V_234 . V_144 = F_61 ( V_3 -> V_183 -> V_237 ) ;
V_127 . V_232 . V_233 . V_234 . V_238 = F_62 ( V_3 -> V_183 -> V_237 ) ;
V_127 . V_232 . V_239 = F_63 ( V_3 -> V_183 -> V_235 ) ;
V_127 . V_240 = V_3 -> V_181 . V_241 . V_242 ;
strcpy ( V_127 . V_243 , V_3 -> V_244 ) ;
strcat ( V_127 . V_243 , L_48 ) ;
switch ( V_3 -> V_104 ) {
case V_245 :
if ( V_3 -> V_246 )
V_127 . V_247 = V_248 ;
else
V_127 . V_247 = V_249 ;
strcat ( V_127 . V_243 , V_250 ) ;
break;
case V_105 :
case V_106 :
if ( V_3 -> V_251 )
V_127 . V_247 = V_252 ;
else
V_127 . V_247 = V_253 ;
strcat ( V_127 . V_243 , V_254 ) ;
break;
}
V_127 . V_255 = F_7 ( V_3 -> V_256 . V_257 ) ;
if ( F_36 ( V_222 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_64 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_258 V_127 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_259 = V_86 ;
memcpy ( V_127 . V_260 , V_3 -> V_80 ,
V_261 * sizeof( T_7 ) ) ;
if ( F_36 ( V_222 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_65 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_262 V_127 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
memcpy ( V_3 -> V_80 , V_127 . V_260 ,
V_261 * sizeof( T_7 ) ) ;
F_66 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_67 ( V_86 ,
sizeof( struct V_81 ) , V_172 ) ;
if ( ! V_3 -> V_79 ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_173 ;
}
return 0 ;
}
static long
F_68 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_263 V_127 ;
T_7 V_264 , V_265 , V_266 ;
struct V_263 T_12 * V_267 = V_222 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_264 = V_127 . V_268 . V_269 -
sizeof( struct V_270 ) ;
V_265 = V_264 / sizeof( struct V_81 ) ;
V_266 = F_13 ( T_7 , V_86 , V_265 ) ;
if ( ! V_266 || ! V_3 -> V_79 )
return - V_217 ;
V_264 = V_266 * sizeof( struct V_81 ) ;
if ( F_36 ( V_267 -> V_271 , V_3 -> V_79 , V_264 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_69 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_272 V_127 ;
int V_273 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( V_3 -> V_274 || V_3 -> V_275 ||
V_3 -> V_276 )
return - V_168 ;
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_273 = F_57 ( V_3 , V_221 ) ;
F_6 ( V_45 L_49 ,
V_3 -> V_46 , ( ( ! V_273 ) ? L_50 : L_51 ) ) ;
return 0 ;
}
static int
F_70 ( struct V_2 * V_3 ,
struct V_277 * V_278 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_279 = 0 ;
if ( F_71 ( & V_3 -> V_280 ) )
return V_279 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_278 -> V_235 == 0xFFFFFFFF && V_278 -> V_103 == 0xFFFFFFFF &&
V_278 -> V_4 == V_5 -> V_4 ) {
V_278 -> V_235 = V_5 -> V_281 ;
V_278 -> V_103 = V_5 -> V_103 ;
V_279 = 1 ;
goto V_7;
} else if ( V_278 -> V_235 == V_5 -> V_281 && V_278 -> V_103 ==
V_5 -> V_103 && V_278 -> V_4 == 0xFFFF ) {
V_278 -> V_4 = V_5 -> V_4 ;
V_279 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_279 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_277 * V_278 )
{
struct V_282 * V_283 ;
unsigned long V_50 ;
int V_279 = 0 ;
if ( F_71 ( & V_3 -> V_284 ) )
return V_279 ;
F_8 ( & V_3 -> V_285 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_278 -> V_235 == 0xFFFFFFFF && V_278 -> V_103 == 0xFFFFFFFF &&
V_278 -> V_4 == V_283 -> V_4 ) {
V_278 -> V_235 = V_283 -> V_281 ;
V_278 -> V_103 = V_283 -> V_103 ;
V_279 = 1 ;
goto V_7;
} else if ( V_278 -> V_235 == V_283 -> V_281 && V_278 -> V_103 ==
V_283 -> V_103 && V_278 -> V_4 == 0xFFFF ) {
V_278 -> V_4 = V_283 -> V_4 ;
V_279 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_285 , V_50 ) ;
return V_279 ;
}
static long
F_73 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_277 V_127 ;
int V_279 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_279 = F_70 ( V_3 , & V_127 ) ;
if ( ! V_279 )
F_72 ( V_3 , & V_127 ) ;
if ( F_36 ( V_222 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static T_6
F_74 ( struct V_2 * V_3 , T_6 V_286 )
{
T_6 V_279 = 0 ;
switch ( V_286 ) {
case V_287 :
if ( V_3 -> V_181 . V_288 &
V_289 )
V_279 = 1 ;
break;
case V_290 :
if ( V_3 -> V_181 . V_288 &
V_291 )
V_279 = 1 ;
break;
case V_292 :
if ( V_3 -> V_181 . V_288 &
V_293 )
V_279 = 1 ;
}
return V_279 ;
}
static long
F_75 ( struct V_2 * V_3 ,
struct V_294 * V_295 )
{
int V_279 , V_77 ;
void * V_296 = NULL ;
T_14 V_297 ;
T_7 V_298 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_286 ;
T_1 V_8 ;
T_1 V_299 ;
T_7 V_155 ;
T_6 V_108 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_286 = V_295 -> V_286 ;
if ( ! F_74 ( V_3 , V_286 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_300 ;
}
if ( V_3 -> V_112 [ V_286 ] &
V_113 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_110 ,
V_286 ) ;
return - V_176 ;
}
if ( V_295 -> V_301 % 4 ) {
F_37 ( V_45
L_55 ,
V_3 -> V_46 , V_110 ) ;
return - V_176 ;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_279 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_296 = V_3 -> V_302 [ V_286 ] ;
V_298 = V_295 -> V_301 ;
V_3 -> V_303 [ V_286 ] = V_295 -> V_303 ;
V_3 -> V_112 [ V_286 ] = 0 ;
memcpy ( V_3 -> V_304 [ V_286 ] ,
V_295 -> V_304 , V_305 ) ;
V_3 -> V_306 [ V_286 ] = V_295 -> V_306 ;
if ( V_296 ) {
V_297 = V_3 -> V_307 [ V_286 ] ;
if ( V_298 != V_3 -> V_308 [ V_286 ] ) {
F_58 ( V_3 -> V_183 ,
V_3 -> V_308 [ V_286 ] ,
V_296 , V_297 ) ;
V_296 = NULL ;
}
}
if ( V_296 == NULL ) {
V_3 -> V_308 [ V_286 ] = 0 ;
V_3 -> V_307 [ V_286 ] = 0 ;
V_296 = F_45 (
V_3 -> V_183 , V_298 , & V_297 ) ;
if ( V_296 == NULL ) {
F_37 ( V_45 L_56 \
L_57 ,
V_3 -> V_46 , V_110 , V_298 ) ;
F_27 ( V_3 , V_8 ) ;
return - V_173 ;
}
V_3 -> V_302 [ V_286 ] = V_296 ;
V_3 -> V_308 [ V_286 ] = V_298 ;
V_3 -> V_307 [ V_286 ] = V_297 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_309 = V_295 -> V_286 ;
V_11 -> V_310 = F_77 ( V_295 -> V_306 ) ;
V_11 -> V_311 = F_78 ( V_297 ) ;
V_11 -> V_312 = F_77 ( V_298 ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_58 ,
V_3 -> V_46 , V_110 , V_296 ,
( unsigned long long ) V_297 ,
F_7 ( V_11 -> V_312 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_305 ; V_77 ++ )
V_11 -> V_313 [ V_77 ] =
F_77 ( V_3 -> V_304 [ V_286 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_210 * V_211 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_213;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_299 = F_5 ( V_10 -> V_47 ) & V_314 ;
if ( V_299 == V_315 ) {
V_3 -> V_112 [ V_286 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_299 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_170 ;
}
V_213:
if ( V_108 )
F_57 ( V_3 , V_221 ) ;
V_7:
if ( V_279 && V_296 )
F_58 ( V_3 -> V_183 , V_298 ,
V_296 , V_297 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_279 ;
}
void
F_79 ( struct V_2 * V_3 , T_6 V_316 )
{
struct V_294 V_295 ;
memset ( & V_295 , 0 , sizeof( struct V_294 ) ) ;
if ( V_316 & 1 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_3 -> V_317 . V_318 =
( V_319 + V_320 ) ;
V_295 . V_286 = V_287 ;
V_295 . V_301 = 2 * ( 1024 * 1024 ) ;
V_295 . V_303 = 0x7075900 ;
F_75 ( V_3 , & V_295 ) ;
}
if ( V_316 & 2 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_290 ;
V_295 . V_301 = 2 * ( 1024 * 1024 ) ;
V_295 . V_303 = 0x7075901 ;
F_75 ( V_3 , & V_295 ) ;
}
if ( V_316 & 4 ) {
F_6 ( V_45 L_64 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_292 ;
V_295 . V_301 = 2 * ( 1024 * 1024 ) ;
V_295 . V_303 = 0x7075901 ;
F_75 ( V_3 , & V_295 ) ;
}
}
static long
F_80 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_294 V_127 ;
long V_279 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_279 = F_75 ( V_3 , & V_127 ) ;
return V_279 ;
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_321 V_127 ;
void * V_296 ;
T_14 V_297 ;
T_7 V_298 ;
T_6 V_286 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_286 = V_127 . V_303 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_286 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_300 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_176 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_114 ) == 0 ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_176 ;
}
if ( V_127 . V_303 != V_3 -> V_303 [ V_286 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_303 ) ;
return - V_176 ;
}
V_296 = V_3 -> V_302 [ V_286 ] ;
if ( ! V_296 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_173 ;
}
V_298 = V_3 -> V_308 [ V_286 ] ;
V_297 = V_3 -> V_307 [ V_286 ] ;
F_58 ( V_3 -> V_183 , V_298 ,
V_296 , V_297 ) ;
V_3 -> V_302 [ V_286 ] = NULL ;
V_3 -> V_112 [ V_286 ] = 0 ;
return 0 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_322 V_127 ;
void * V_296 ;
int V_77 ;
T_6 V_286 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_323 = 0 ;
V_286 = V_127 . V_286 ;
if ( ! F_74 ( V_3 , V_286 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_300 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_176 ;
}
if ( V_127 . V_303 & 0xffffff00 ) {
if ( V_127 . V_303 != V_3 -> V_303 [ V_286 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_303 ) ;
return - V_176 ;
}
}
V_296 = V_3 -> V_302 [ V_286 ] ;
if ( ! V_296 ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_173 ;
}
if ( V_3 -> V_112 [ V_286 ] & V_114 )
V_127 . V_323 = ( V_324 |
V_325 ) ;
else
V_127 . V_323 = ( V_324 |
V_325 |
V_326 ) ;
for ( V_77 = 0 ; V_77 < V_305 ; V_77 ++ )
V_127 . V_304 [ V_77 ] =
V_3 -> V_304 [ V_286 ] [ V_77 ] ;
V_127 . V_327 = V_3 -> V_308 [ V_286 ] ;
V_127 . V_328 = 0 ;
V_127 . V_303 = V_3 -> V_303 [ V_286 ] ;
V_127 . V_306 = V_3 -> V_306 [ V_286 ] ;
if ( F_36 ( V_222 , & V_127 , sizeof( struct V_322 ) ) ) {
F_37 ( V_45
L_70 ,
V_3 -> V_46 , V_110 , V_222 ) ;
return - V_170 ;
}
return 0 ;
}
int
F_26 ( struct V_2 * V_3 , T_6 V_286 ,
T_6 * V_108 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_299 ;
T_7 V_155 ;
int V_279 ;
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_279 = 0 ;
* V_108 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
if ( V_3 -> V_112 [ V_286 ] &
V_113 )
V_3 -> V_112 [ V_286 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45
L_71 , V_3 -> V_46 ,
V_110 ) ) ;
V_279 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_309 = V_286 ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_210 * V_211 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
* V_108 = 1 ;
V_279 = - V_170 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_299 = F_5 ( V_10 -> V_47 ) & V_314 ;
if ( V_299 == V_315 ) {
V_3 -> V_112 [ V_286 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_299 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_170 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_279 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_329 V_127 ;
void * V_296 ;
int V_279 ;
T_6 V_286 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_286 = V_127 . V_303 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_286 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_300 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_176 ;
}
if ( V_127 . V_303 != V_3 -> V_303 [ V_286 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_303 ) ;
return - V_176 ;
}
if ( V_3 -> V_112 [ V_286 ] &
V_114 ) {
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_110 ,
V_286 ) ;
return 0 ;
}
V_296 = V_3 -> V_302 [ V_286 ] ;
if ( ! V_296 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_173 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_118 ) ) {
V_3 -> V_112 [ V_286 ] |=
V_114 ;
V_3 -> V_112 [ V_286 ] &=
~ V_118 ;
F_37 ( V_45
L_73 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return 0 ;
}
V_279 = F_26 ( V_3 , V_286 , & V_108 ) ;
if ( V_108 )
F_57 ( V_3 , V_221 ) ;
return V_279 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_222 )
{
struct V_330 V_127 ;
struct V_330 T_12 * V_267 = V_222 ;
void * V_296 , * V_331 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_279 , V_77 ;
T_6 V_286 ;
unsigned long V_332 , V_333 ;
T_1 V_8 ;
T_1 V_299 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_286 = V_127 . V_303 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_286 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_300 ;
}
if ( V_127 . V_303 != V_3 -> V_303 [ V_286 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_303 ) ;
return - V_176 ;
}
V_296 = V_3 -> V_302 [ V_286 ] ;
if ( ! V_296 ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_286 ) ;
return - V_173 ;
}
V_332 = V_3 -> V_308 [ V_286 ] ;
if ( ( V_127 . V_334 % 4 ) || ( V_127 . V_335 % 4 ) ) {
F_37 ( V_45 L_74 \
L_75 , V_3 -> V_46 ,
V_110 ) ;
return - V_176 ;
}
if ( V_127 . V_334 > V_332 )
return - V_176 ;
V_331 = ( void * ) ( V_296 + V_127 . V_334 ) ;
F_35 ( V_3 , F_6 ( V_45
L_76 ,
V_3 -> V_46 , V_110 ,
V_331 , V_127 . V_334 , V_127 . V_335 ) ) ;
if ( ( V_331 + V_127 . V_335 < V_331 ) ||
( V_331 + V_127 . V_335 > V_296 + V_332 ) )
V_333 = V_332 - V_127 . V_334 ;
else
V_333 = V_127 . V_335 ;
if ( F_36 ( ( void T_12 * ) V_267 -> V_336 ,
V_331 , V_333 ) ) {
F_37 ( V_45
L_77 ,
V_3 -> V_46 , V_110 , V_331 ) ;
return - V_170 ;
}
if ( ( V_127 . V_50 & V_337 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_110 , V_286 ) ) ;
if ( ( V_3 -> V_112 [ V_286 ] &
V_114 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_79 ,
V_3 -> V_46 , V_110 , V_286 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_168 ;
goto V_7;
}
V_279 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_309 = V_286 ;
V_11 -> V_312 =
F_77 ( V_3 -> V_308 [ V_286 ] ) ;
V_11 -> V_311 =
F_78 ( V_3 -> V_307 [ V_286 ] ) ;
for ( V_77 = 0 ; V_77 < V_305 ; V_77 ++ )
V_11 -> V_313 [ V_77 ] =
F_77 ( V_3 -> V_304 [ V_286 ] [ V_77 ] ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_210 * V_211 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_213;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_299 = F_5 ( V_10 -> V_47 ) & V_314 ;
if ( V_299 == V_315 ) {
V_3 -> V_112 [ V_286 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_299 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_170 ;
}
V_213:
if ( V_108 )
F_57 ( V_3 , V_221 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_279 ;
}
static long
F_85 ( struct V_2 * V_3 , unsigned V_338 ,
void T_12 * V_222 )
{
struct V_339 V_340 ;
struct V_339 T_12 * V_267 ;
struct V_126 V_127 ;
if ( F_86 ( V_338 ) != sizeof( struct V_339 ) )
return - V_176 ;
V_267 = (struct V_339 T_12 * ) V_222 ;
if ( F_42 ( & V_340 , ( char T_12 * ) V_222 , sizeof( V_340 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 . V_268 . V_98 = V_340 . V_268 . V_98 ;
V_127 . V_268 . V_225 = V_340 . V_268 . V_225 ;
V_127 . V_268 . V_269 = V_340 . V_268 . V_269 ;
V_127 . V_156 = V_340 . V_156 ;
V_127 . V_150 = V_340 . V_150 ;
V_127 . V_179 = V_340 . V_179 ;
V_127 . V_178 = V_340 . V_178 ;
V_127 . V_218 = V_340 . V_218 ;
V_127 . V_174 = V_340 . V_174 ;
V_127 . V_152 = F_87 ( V_340 . V_152 ) ;
V_127 . V_216 = F_87 ( V_340 . V_216 ) ;
V_127 . V_184 = F_87 ( V_340 . V_184 ) ;
V_127 . V_219 = F_87 ( V_340 . V_219 ) ;
return F_38 ( V_3 , V_127 , & V_267 -> V_153 ) ;
}
static long
F_88 ( struct V_120 * V_120 , unsigned int V_338 , void T_12 * V_222 ,
T_6 V_341 , T_1 V_100 )
{
struct V_2 * V_3 ;
struct V_270 V_342 ;
enum V_343 V_344 ;
long V_164 = - V_176 ;
if ( F_42 ( & V_342 , ( char T_12 * ) V_222 ,
sizeof( struct V_270 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( F_21 ( V_342 . V_98 ,
& V_3 , V_100 ) == - 1 || ! V_3 )
return - V_345 ;
F_89 ( & V_3 -> V_346 ) ;
if ( V_3 -> V_274 || V_3 -> V_275 ||
V_3 -> V_276 || V_3 -> V_347 ) {
V_164 = - V_168 ;
goto V_348;
}
V_344 = ( V_120 -> V_349 & V_350 ) ? V_351 : V_352 ;
if ( V_344 == V_351 ) {
if ( ! F_90 ( & V_3 -> V_64 . V_353 ) ) {
V_164 = - V_168 ;
goto V_348;
}
} else if ( F_91 ( & V_3 -> V_64 . V_353 ) ) {
V_164 = - V_354 ;
goto V_348;
}
switch ( V_338 ) {
case V_355 :
if ( F_86 ( V_338 ) == sizeof( struct V_223 ) )
V_164 = F_60 ( V_3 , V_222 ) ;
break;
#ifdef F_92
case V_356 :
#endif
case V_357 :
{
struct V_126 T_12 * V_267 ;
struct V_126 V_127 ;
#ifdef F_92
if ( V_341 ) {
V_164 = F_85 ( V_3 , V_338 , V_222 ) ;
break;
}
#endif
if ( F_42 ( & V_127 , V_222 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
V_164 = - V_170 ;
break;
}
if ( F_86 ( V_338 ) == sizeof( struct V_126 ) ) {
V_267 = V_222 ;
V_164 = F_38 ( V_3 , V_127 , & V_267 -> V_153 ) ;
}
break;
}
case V_358 :
if ( F_86 ( V_338 ) == sizeof( struct V_258 ) )
V_164 = F_64 ( V_3 , V_222 ) ;
break;
case V_359 :
if ( F_86 ( V_338 ) == sizeof( struct V_262 ) )
V_164 = F_65 ( V_3 , V_222 ) ;
break;
case V_360 :
V_164 = F_68 ( V_3 , V_222 ) ;
break;
case V_361 :
if ( F_86 ( V_338 ) == sizeof( struct V_272 ) )
V_164 = F_69 ( V_3 , V_222 ) ;
break;
case V_362 :
if ( F_86 ( V_338 ) == sizeof( struct V_277 ) )
V_164 = F_73 ( V_3 , V_222 ) ;
break;
case V_363 :
if ( F_86 ( V_338 ) == sizeof( struct V_294 ) )
V_164 = F_80 ( V_3 , V_222 ) ;
break;
case V_364 :
if ( F_86 ( V_338 ) == sizeof( struct V_321 ) )
V_164 = F_81 ( V_3 , V_222 ) ;
break;
case V_365 :
if ( F_86 ( V_338 ) == sizeof( struct V_322 ) )
V_164 = F_82 ( V_3 , V_222 ) ;
break;
case V_366 :
if ( F_86 ( V_338 ) == sizeof( struct V_329 ) )
V_164 = F_83 ( V_3 , V_222 ) ;
break;
case V_367 :
if ( F_86 ( V_338 ) == sizeof( struct V_330 ) )
V_164 = F_84 ( V_3 , V_222 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_80 , V_3 -> V_46 , V_338 ) ) ;
break;
}
F_93 ( & V_3 -> V_64 . V_353 ) ;
V_348:
F_93 ( & V_3 -> V_346 ) ;
return V_164 ;
}
static long
F_94 ( struct V_120 * V_120 , unsigned int V_338 , unsigned long V_222 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_338 , ( void T_12 * ) V_222 , 0 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_95 ( struct V_120 * V_120 , unsigned int V_338 , unsigned long V_222 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_338 , ( void T_12 * ) V_222 , 0 , V_245 ) ;
return V_164 ;
}
static long
F_96 ( struct V_120 * V_120 , unsigned V_338 , unsigned long V_222 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_338 , ( void T_12 * ) V_222 , 1 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_97 ( struct V_120 * V_120 , unsigned V_338 , unsigned long V_222 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_338 , ( void T_12 * ) V_222 , 1 , V_245 ) ;
return V_164 ;
}
static T_23
F_98 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_81 ,
( V_3 -> V_181 . V_241 . V_242 & 0xFF000000 ) >> 24 ,
( V_3 -> V_181 . V_241 . V_242 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_181 . V_241 . V_242 & 0x0000FF00 ) >> 8 ,
V_3 -> V_181 . V_241 . V_242 & 0x000000FF ) ;
}
static T_23
F_101 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
T_7 V_101 = F_7 ( V_3 -> V_256 . V_257 ) ;
return snprintf ( V_371 , V_374 , L_81 ,
( V_101 & 0xFF000000 ) >> 24 ,
( V_101 & 0x00FF0000 ) >> 16 ,
( V_101 & 0x0000FF00 ) >> 8 ,
V_101 & 0x000000FF ) ;
}
static T_23
F_102 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_82 ,
V_3 -> V_181 . V_375 , V_3 -> V_181 . V_376 >> 8 ) ;
}
static T_23
F_103 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , 16 , L_52 , V_3 -> V_377 . V_378 ) ;
}
static T_23
F_104 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_83 ,
F_7 ( V_3 -> V_379 . V_380 . V_242 ) ) ;
}
static T_23
F_105 ( struct V_144 * V_368 , struct V_369
* V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_83 ,
F_7 ( V_3 -> V_379 . V_381 . V_242 ) ) ;
}
static T_23
F_106 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , 16 , L_52 , V_3 -> V_377 . V_382 ) ;
}
static T_23
F_107 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , 16 , L_52 , V_3 -> V_377 . V_383 ) ;
}
static T_23
F_108 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , 16 , L_52 , V_3 -> V_377 . V_384 ) ;
}
static T_23
F_109 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_84 , V_3 -> V_385 ) ;
}
static T_23
F_110 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_84 , V_3 -> V_386 ) ;
}
static T_23
F_111 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_84 , V_3 -> V_181 . V_387 ) ;
}
static T_23
F_112 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_85 ,
( unsigned long long ) V_3 -> V_388 . V_53 ) ;
}
static T_23
F_113 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_83 , V_3 -> V_13 ) ;
}
static T_23
F_114 ( struct V_144 * V_368 , struct V_369 * V_370 ,
const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
int V_390 = 0 ;
if ( sscanf ( V_371 , L_86 , & V_390 ) != 1 )
return - V_176 ;
V_3 -> V_13 = V_390 ;
F_6 ( V_45 L_87 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_371 ) ;
}
static T_23
F_115 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_88 , V_3 -> V_391 ) ;
}
static T_23
F_116 ( struct V_144 * V_368 , struct V_369 * V_370 ,
const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
int V_390 = 0 ;
if ( sscanf ( V_371 , L_89 , & V_390 ) != 1 )
return - V_176 ;
V_3 -> V_391 = V_390 ;
F_6 ( V_45 L_90 , V_3 -> V_46 ,
V_3 -> V_391 ) ;
return strlen ( V_371 ) ;
}
static T_23
F_117 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
return snprintf ( V_371 , V_374 , L_88 , V_3 -> V_392 ) ;
}
static T_23
F_118 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
T_6 V_393 ;
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
if ( ( V_3 -> V_181 . V_288 &
V_394 ) && V_3 -> V_395 )
V_393 = V_3 -> V_393 ;
else
V_393 = 1 ;
return snprintf ( V_371 , V_374 , L_88 , V_393 ) ;
}
static T_23
F_119 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
T_24 * V_396 = NULL ;
T_25 V_10 ;
T_1 V_397 = 0 ;
T_1 V_299 ;
int V_63 ;
T_23 V_279 = 0 ;
if ( ! V_3 -> V_246 ) {
F_37 ( V_45 L_91
L_92 , V_3 -> V_46 , V_110 ) ;
goto V_7;
}
F_89 ( & V_3 -> V_346 ) ;
if ( V_3 -> V_275 || V_3 -> V_347 ) {
F_93 ( & V_3 -> V_346 ) ;
return 0 ;
}
V_63 = F_120 ( T_24 , V_398 ) + ( sizeof( T_1 ) * 36 ) ;
V_396 = F_41 ( V_63 , V_172 ) ;
if ( ! V_396 ) {
F_37 ( V_45 L_93
L_94 , V_3 -> V_46 , V_110 , V_63 ) ;
goto V_7;
}
if ( F_121 ( V_3 , & V_10 , V_396 , V_63 ) !=
0 ) {
F_37 ( V_45
L_95 , V_3 -> V_46 ,
V_110 ) ;
goto V_7;
}
V_299 = F_5 ( V_10 . V_47 ) & V_314 ;
if ( V_299 != V_315 ) {
F_37 ( V_45 L_96
L_97 , V_3 -> V_46 , V_110 , V_299 ) ;
goto V_7;
}
if ( V_396 -> V_399 < 25 ) {
F_37 ( V_45 L_98
L_99 , V_3 -> V_46 , V_110 ,
V_396 -> V_399 ) ;
goto V_7;
}
V_397 = F_5 ( V_396 -> V_398 [ 24 ] ) ;
V_279 = snprintf ( V_371 , V_374 , L_88 , ( V_397 & 1 ) ) ;
V_7:
F_59 ( V_396 ) ;
F_93 ( & V_3 -> V_346 ) ;
return V_279 ;
}
static T_23
F_122 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
T_7 V_400 = 0 ;
struct V_401 * V_296 ;
if ( ! V_3 -> V_302 [ V_287 ] ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_287 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
V_296 = (struct V_401 * )
V_3 -> V_302 [ V_287 ] ;
if ( ( F_7 ( V_296 -> V_402 ) == 0x00000000 ||
F_7 ( V_296 -> V_402 ) == 0x01000000 ||
F_7 ( V_296 -> V_402 ) == 0x01010000 ) &&
F_7 ( V_296 -> V_403 ) == 0x4742444c )
V_400 = F_7 ( V_296 -> V_404 ) ;
V_3 -> V_405 = V_400 ;
return snprintf ( V_371 , V_374 , L_88 , V_400 ) ;
}
static T_23
F_123 ( struct V_144 * V_368 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
void * V_296 ;
T_7 V_400 ;
if ( ! V_3 -> V_302 [ V_287 ] ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_287 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( V_3 -> V_406 > V_3 -> V_405 )
return 0 ;
V_400 = V_3 -> V_405 - V_3 -> V_406 ;
V_400 = ( V_400 >= V_374 ) ? ( V_374 - 1 ) : V_400 ;
V_296 = V_3 -> V_302 [ 0 ] + V_3 -> V_406 ;
memcpy ( V_371 , V_296 , V_400 ) ;
return V_400 ;
}
static T_23
F_124 ( struct V_144 * V_368 , struct V_369 * V_370 ,
const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
int V_390 = 0 ;
if ( sscanf ( V_371 , L_89 , & V_390 ) != 1 )
return - V_176 ;
V_3 -> V_406 = V_390 ;
return strlen ( V_371 ) ;
}
static T_23
F_125 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
if ( ( ! V_3 -> V_302 [ V_287 ] ) ||
( ( V_3 -> V_112 [ V_287 ] &
V_113 ) == 0 ) )
return snprintf ( V_371 , V_374 , L_101 ) ;
else if ( ( V_3 -> V_112 [ V_287 ] &
V_114 ) )
return snprintf ( V_371 , V_374 , L_102 ) ;
else
return snprintf ( V_371 , V_374 , L_103 ) ;
}
static T_23
F_126 ( struct V_144 * V_368 ,
struct V_369 * V_370 , const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
char V_407 [ 10 ] = L_104 ;
struct V_294 V_295 ;
T_6 V_108 = 0 ;
if ( V_3 -> V_274 || V_3 -> V_347 ||
V_3 -> V_275 || V_3 -> V_276 )
return - V_408 ;
if ( sscanf ( V_371 , L_105 , V_407 ) != 1 )
return - V_176 ;
if ( ! strcmp ( V_407 , L_106 ) ) {
if ( ( V_3 -> V_302 [ V_287 ] ) &&
( V_3 -> V_112 [ V_287 ] &
V_113 ) &&
( ( V_3 -> V_112 [ V_287 ] &
V_114 ) == 0 ) )
goto V_7;
memset ( & V_295 , 0 , sizeof( struct V_294 ) ) ;
F_6 ( V_45 L_107 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_287 ;
V_295 . V_301 = ( 1024 * 1024 ) ;
V_295 . V_303 = 0x7075900 ;
V_3 -> V_112 [ V_287 ] = 0 ;
F_75 ( V_3 , & V_295 ) ;
} else if ( ! strcmp ( V_407 , L_108 ) ) {
if ( ! V_3 -> V_302 [ V_287 ] )
goto V_7;
if ( ( V_3 -> V_112 [ V_287 ] &
V_113 ) == 0 )
goto V_7;
if ( ( V_3 -> V_112 [ V_287 ] &
V_114 ) )
goto V_7;
F_6 ( V_45 L_109 ,
V_3 -> V_46 ) ;
F_26 ( V_3 , V_287 ,
& V_108 ) ;
}
V_7:
return strlen ( V_371 ) ;
}
static T_23
F_127 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_279 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_279 = sizeof( struct V_410 ) ;
memcpy ( V_371 , & V_3 -> V_317 , V_279 ) ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_279 ;
}
static T_23
F_128 ( struct V_144 * V_368 ,
struct V_369 * V_370 , const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_279 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_279 = F_129 ( sizeof( struct V_410 ) , V_389 ) ;
memset ( & V_3 -> V_317 , 0 ,
sizeof( struct V_410 ) ) ;
memcpy ( & V_3 -> V_317 , V_371 , V_279 ) ;
V_3 -> V_317 . V_318 |=
( V_319 + V_320 ) ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_279 ;
}
static T_23
F_130 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_279 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_279 = sizeof( struct V_411 ) ;
memcpy ( V_371 , & V_3 -> V_412 , V_279 ) ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_279 ;
}
static T_23
F_131 ( struct V_144 * V_368 ,
struct V_369 * V_370 , const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_411 ) , V_389 ) ;
memset ( & V_3 -> V_412 , 0 ,
sizeof( struct V_411 ) ) ;
memcpy ( & V_3 -> V_412 , V_371 , V_63 ) ;
if ( V_3 -> V_412 . V_413 > V_414 )
V_3 -> V_412 . V_413 = V_414 ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_63 ;
}
static T_23
F_132 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_279 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_279 = sizeof( struct V_415 ) ;
memcpy ( V_371 , & V_3 -> V_416 , V_279 ) ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_279 ;
}
static T_23
F_133 ( struct V_144 * V_368 ,
struct V_369 * V_370 , const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_415 ) , V_389 ) ;
memset ( & V_3 -> V_416 , 0 ,
sizeof( struct V_411 ) ) ;
memcpy ( & V_3 -> V_416 , V_371 , V_63 ) ;
if ( V_3 -> V_416 . V_413 > V_414 )
V_3 -> V_416 . V_413 = V_414 ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_63 ;
}
static T_23
F_134 ( struct V_144 * V_368 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_279 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_279 = sizeof( struct V_417 ) ;
memcpy ( V_371 , & V_3 -> V_418 , V_279 ) ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_279 ;
}
static T_23
F_135 ( struct V_144 * V_368 ,
struct V_369 * V_370 , const char * V_371 , T_15 V_389 )
{
struct V_372 * V_373 = F_99 ( V_368 ) ;
struct V_2 * V_3 = F_100 ( V_373 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_409 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_417 ) , V_389 ) ;
memset ( & V_3 -> V_418 , 0 ,
sizeof( V_3 -> V_418 ) ) ;
memcpy ( & V_3 -> V_418 , V_371 , V_63 ) ;
if ( V_3 -> V_418 . V_413 > V_414 )
V_3 -> V_418 . V_413 = V_414 ;
F_10 ( & V_3 -> V_409 , V_50 ) ;
return V_63 ;
}
static T_23
F_136 ( struct V_144 * V_419 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_420 * V_421 = F_137 ( V_419 ) ;
struct V_132 * V_422 = V_421 -> V_145 ;
return snprintf ( V_371 , V_374 , L_85 ,
( unsigned long long ) V_422 -> V_146 -> V_53 ) ;
}
static T_23
F_138 ( struct V_144 * V_419 , struct V_369 * V_370 ,
char * V_371 )
{
struct V_420 * V_421 = F_137 ( V_419 ) ;
struct V_132 * V_422 = V_421 -> V_145 ;
return snprintf ( V_371 , V_374 , L_110 ,
V_422 -> V_146 -> V_4 ) ;
}
static T_23
F_139 ( struct V_144 * V_419 ,
struct V_369 * V_370 , char * V_371 )
{
struct V_420 * V_421 = F_137 ( V_419 ) ;
struct V_132 * V_422 = V_421 -> V_145 ;
return snprintf ( V_371 , V_374 , L_88 ,
V_422 -> V_423 ) ;
}
static T_23
F_140 ( struct V_144 * V_419 ,
struct V_369 * V_370 ,
const char * V_371 , T_15 V_389 )
{
struct V_420 * V_421 = F_137 ( V_419 ) ;
struct V_132 * V_422 = V_421 -> V_145 ;
bool V_423 = 0 ;
if ( F_141 ( V_371 , & V_423 ) )
return - V_176 ;
if ( ! F_142 ( V_421 ) )
return - V_176 ;
V_422 -> V_423 = V_423 ;
return strlen ( V_371 ) ;
}
void
F_143 ( T_26 V_424 )
{
V_95 = NULL ;
if ( V_424 != 1 )
if ( F_144 ( & V_425 ) < 0 )
F_37 ( L_111 ,
V_426 , V_427 ) ;
if ( V_424 != 2 )
if ( F_144 ( & V_428 ) < 0 )
F_37 ( L_111 ,
V_429 , V_430 ) ;
F_145 ( & V_94 ) ;
}
void
F_146 ( T_26 V_424 )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! V_3 -> V_302 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
F_58 ( V_3 -> V_183 , V_3 -> V_308 [ V_77 ] ,
V_3 -> V_302 [ V_77 ] , V_3 -> V_307 [ V_77 ] ) ;
V_3 -> V_302 [ V_77 ] = NULL ;
V_3 -> V_112 [ V_77 ] = 0 ;
}
F_59 ( V_3 -> V_79 ) ;
}
if ( V_424 != 1 )
F_147 ( & V_425 ) ;
if ( V_424 != 2 )
F_147 ( & V_428 ) ;
}
