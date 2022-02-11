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
if ( V_128 -> V_136 ==
V_137 ||
V_128 -> V_136 ==
V_138 ) {
if ( F_32 ( V_3 , & V_127 , V_128 ) ) {
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
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
V_3 -> V_192 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
V_3 -> V_193 ( V_3 , V_8 , 0 ) ;
break;
}
case V_44 :
{
T_16 * V_194 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_194 -> V_195 = 0xFF ;
if ( V_194 -> V_196 &
V_197 )
V_90 = ( T_6 * ) & V_194 -> V_198 ;
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
V_3 -> V_199 = 1 ;
V_3 -> V_200 = 1 ;
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
case V_201 :
{
T_17 * V_202 =
( T_17 * ) V_11 ;
if ( V_202 -> V_203 == V_204 ) {
V_3 -> V_189 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
} else {
V_3 -> V_192 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
}
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_205 =
( T_18 * ) V_11 ;
if ( V_205 -> V_206 == V_207
|| V_205 -> V_206 ==
V_208 ) {
V_3 -> V_199 = 1 ;
V_3 -> V_200 = 1 ;
}
}
default:
V_3 -> V_192 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
break;
}
if ( V_127 . V_156 < V_209 )
V_156 = V_209 ;
else
V_156 = V_127 . V_156 ;
F_51 ( & V_3 -> V_64 . V_75 , V_156 * V_210 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_128 =
( T_10 * ) V_11 ;
F_52 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
F_53 ( V_3 , V_211 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_199 ) {
V_3 -> V_199 = 0 ;
V_3 -> V_200 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 , V_127 . V_174 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_212;
}
V_10 = V_3 -> V_64 . V_60 ;
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_213 ) ) {
T_11 * V_134 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_43 \
L_44
L_45 , V_3 -> V_46 ,
F_5 ( V_134 -> V_47 ) ,
F_7 ( V_134 -> V_48 ) ,
F_7 ( V_134 -> V_214 ) ) ;
}
if ( V_163 ) {
if ( F_36 ( V_127 . V_215 , V_161 ,
V_163 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_216 ;
goto V_7;
}
}
if ( V_127 . V_150 ) {
V_63 = F_13 ( T_7 , V_127 . V_150 , V_3 -> V_151 ) ;
if ( F_36 ( V_127 . V_152 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_216 ;
goto V_7;
}
}
if ( V_127 . V_217 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_127 . V_217 , V_71 ) ;
if ( F_36 ( V_127 . V_218 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_216 ;
goto V_7;
}
}
V_212:
if ( V_108 ) {
V_164 = - V_216 ;
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
0 , V_219 , 0 , 30 ) ;
} else
F_57 ( V_3 , V_220 ) ;
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
F_60 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_222 V_127 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( V_3 -> V_223 )
V_127 . V_224 = V_3 -> V_223 [ 0 ] . V_225 ;
V_127 . V_226 = V_3 -> V_183 -> V_227 ;
V_127 . V_228 = V_3 -> V_183 -> V_144 ;
V_127 . V_229 = V_3 -> V_183 -> V_229 ;
V_127 . V_230 = V_3 -> V_183 -> V_230 ;
V_127 . V_231 . V_232 . V_233 . V_234 = V_3 -> V_183 -> V_234 -> V_235 ;
V_127 . V_231 . V_232 . V_233 . V_144 = F_61 ( V_3 -> V_183 -> V_236 ) ;
V_127 . V_231 . V_232 . V_233 . V_237 = F_62 ( V_3 -> V_183 -> V_236 ) ;
V_127 . V_231 . V_238 = F_63 ( V_3 -> V_183 -> V_234 ) ;
V_127 . V_239 = V_3 -> V_181 . V_240 . V_241 ;
strcpy ( V_127 . V_242 , V_3 -> V_243 ) ;
strcat ( V_127 . V_242 , L_48 ) ;
switch ( V_3 -> V_104 ) {
case V_244 :
if ( V_3 -> V_245 )
V_127 . V_246 = V_247 ;
else
V_127 . V_246 = V_248 ;
strcat ( V_127 . V_242 , V_249 ) ;
break;
case V_105 :
case V_106 :
if ( V_3 -> V_250 )
V_127 . V_246 = V_251 ;
else
V_127 . V_246 = V_252 ;
strcat ( V_127 . V_242 , V_253 ) ;
break;
}
V_127 . V_254 = F_7 ( V_3 -> V_255 . V_256 ) ;
if ( F_36 ( V_221 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_64 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_257 V_127 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_258 = V_86 ;
memcpy ( V_127 . V_259 , V_3 -> V_80 ,
V_260 * sizeof( T_7 ) ) ;
if ( F_36 ( V_221 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_65 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_261 V_127 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
memcpy ( V_3 -> V_80 , V_127 . V_259 ,
V_260 * sizeof( T_7 ) ) ;
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
F_68 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_262 V_127 ;
T_7 V_263 , V_264 , V_265 ;
struct V_262 T_12 * V_266 = V_221 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_263 = V_127 . V_267 . V_268 -
sizeof( struct V_269 ) ;
V_264 = V_263 / sizeof( struct V_81 ) ;
V_265 = F_13 ( T_7 , V_86 , V_264 ) ;
if ( ! V_265 || ! V_3 -> V_79 )
return - V_216 ;
V_263 = V_265 * sizeof( struct V_81 ) ;
if ( F_36 ( V_266 -> V_270 , V_3 -> V_79 , V_263 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_69 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_271 V_127 ;
int V_272 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( V_3 -> V_273 || V_3 -> V_274 ||
V_3 -> V_275 )
return - V_168 ;
F_35 ( V_3 , F_6 ( V_45 L_47 , V_3 -> V_46 ,
V_110 ) ) ;
V_272 = F_57 ( V_3 , V_220 ) ;
F_6 ( V_45 L_49 ,
V_3 -> V_46 , ( ( ! V_272 ) ? L_50 : L_51 ) ) ;
return 0 ;
}
static int
F_70 ( struct V_2 * V_3 ,
struct V_276 * V_277 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_278 = 0 ;
if ( F_71 ( & V_3 -> V_279 ) )
return V_278 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_277 -> V_234 == 0xFFFFFFFF && V_277 -> V_103 == 0xFFFFFFFF &&
V_277 -> V_4 == V_5 -> V_4 ) {
V_277 -> V_234 = V_5 -> V_280 ;
V_277 -> V_103 = V_5 -> V_103 ;
V_278 = 1 ;
goto V_7;
} else if ( V_277 -> V_234 == V_5 -> V_280 && V_277 -> V_103 ==
V_5 -> V_103 && V_277 -> V_4 == 0xFFFF ) {
V_277 -> V_4 = V_5 -> V_4 ;
V_278 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_278 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_276 * V_277 )
{
struct V_281 * V_282 ;
unsigned long V_50 ;
int V_278 = 0 ;
if ( F_71 ( & V_3 -> V_283 ) )
return V_278 ;
F_8 ( & V_3 -> V_284 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_277 -> V_234 == 0xFFFFFFFF && V_277 -> V_103 == 0xFFFFFFFF &&
V_277 -> V_4 == V_282 -> V_4 ) {
V_277 -> V_234 = V_282 -> V_280 ;
V_277 -> V_103 = V_282 -> V_103 ;
V_278 = 1 ;
goto V_7;
} else if ( V_277 -> V_234 == V_282 -> V_280 && V_277 -> V_103 ==
V_282 -> V_103 && V_277 -> V_4 == 0xFFFF ) {
V_277 -> V_4 = V_282 -> V_4 ;
V_278 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_284 , V_50 ) ;
return V_278 ;
}
static long
F_73 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_276 V_127 ;
int V_278 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_278 = F_70 ( V_3 , & V_127 ) ;
if ( ! V_278 )
F_72 ( V_3 , & V_127 ) ;
if ( F_36 ( V_221 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static T_6
F_74 ( struct V_2 * V_3 , T_6 V_285 )
{
T_6 V_278 = 0 ;
switch ( V_285 ) {
case V_286 :
if ( V_3 -> V_181 . V_287 &
V_288 )
V_278 = 1 ;
break;
case V_289 :
if ( V_3 -> V_181 . V_287 &
V_290 )
V_278 = 1 ;
break;
case V_291 :
if ( V_3 -> V_181 . V_287 &
V_292 )
V_278 = 1 ;
}
return V_278 ;
}
static long
F_75 ( struct V_2 * V_3 ,
struct V_293 * V_294 )
{
int V_278 , V_77 ;
void * V_295 = NULL ;
T_14 V_296 ;
T_7 V_297 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_285 ;
T_1 V_8 ;
T_1 V_298 ;
T_7 V_155 ;
T_6 V_108 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_285 = V_294 -> V_285 ;
if ( ! F_74 ( V_3 , V_285 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_299 ;
}
if ( V_3 -> V_112 [ V_285 ] &
V_113 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_110 ,
V_285 ) ;
return - V_176 ;
}
if ( V_294 -> V_300 % 4 ) {
F_37 ( V_45
L_55 ,
V_3 -> V_46 , V_110 ) ;
return - V_176 ;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_278 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_295 = V_3 -> V_301 [ V_285 ] ;
V_297 = V_294 -> V_300 ;
V_3 -> V_302 [ V_285 ] = V_294 -> V_302 ;
V_3 -> V_112 [ V_285 ] = 0 ;
memcpy ( V_3 -> V_303 [ V_285 ] ,
V_294 -> V_303 , V_304 ) ;
V_3 -> V_305 [ V_285 ] = V_294 -> V_305 ;
if ( V_295 ) {
V_296 = V_3 -> V_306 [ V_285 ] ;
if ( V_297 != V_3 -> V_307 [ V_285 ] ) {
F_58 ( V_3 -> V_183 ,
V_3 -> V_307 [ V_285 ] ,
V_295 , V_296 ) ;
V_295 = NULL ;
}
}
if ( V_295 == NULL ) {
V_3 -> V_307 [ V_285 ] = 0 ;
V_3 -> V_306 [ V_285 ] = 0 ;
V_295 = F_45 (
V_3 -> V_183 , V_297 , & V_296 ) ;
if ( V_295 == NULL ) {
F_37 ( V_45 L_56 \
L_57 ,
V_3 -> V_46 , V_110 , V_297 ) ;
F_27 ( V_3 , V_8 ) ;
return - V_173 ;
}
V_3 -> V_301 [ V_285 ] = V_295 ;
V_3 -> V_307 [ V_285 ] = V_297 ;
V_3 -> V_306 [ V_285 ] = V_296 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_308 = V_294 -> V_285 ;
V_11 -> V_309 = F_77 ( V_294 -> V_305 ) ;
V_11 -> V_310 = F_78 ( V_296 ) ;
V_11 -> V_311 = F_77 ( V_297 ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_58 ,
V_3 -> V_46 , V_110 , V_295 ,
( unsigned long long ) V_296 ,
F_7 ( V_11 -> V_311 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_304 ; V_77 ++ )
V_11 -> V_312 [ V_77 ] =
F_77 ( V_3 -> V_303 [ V_285 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_209 * V_210 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_212;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_298 = F_5 ( V_10 -> V_47 ) & V_313 ;
if ( V_298 == V_314 ) {
V_3 -> V_112 [ V_285 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_298 , F_7 ( V_10 -> V_48 ) ) ;
V_278 = - V_170 ;
}
V_212:
if ( V_108 )
F_57 ( V_3 , V_220 ) ;
V_7:
if ( V_278 && V_295 )
F_58 ( V_3 -> V_183 , V_297 ,
V_295 , V_296 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_278 ;
}
void
F_79 ( struct V_2 * V_3 , T_6 V_315 )
{
struct V_293 V_294 ;
memset ( & V_294 , 0 , sizeof( struct V_293 ) ) ;
if ( V_315 & 1 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_3 -> V_316 . V_317 =
( V_318 + V_319 ) ;
V_294 . V_285 = V_286 ;
V_294 . V_300 = 2 * ( 1024 * 1024 ) ;
V_294 . V_302 = 0x7075900 ;
F_75 ( V_3 , & V_294 ) ;
}
if ( V_315 & 2 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_294 . V_285 = V_289 ;
V_294 . V_300 = 2 * ( 1024 * 1024 ) ;
V_294 . V_302 = 0x7075901 ;
F_75 ( V_3 , & V_294 ) ;
}
if ( V_315 & 4 ) {
F_6 ( V_45 L_64 ,
V_3 -> V_46 ) ;
V_294 . V_285 = V_291 ;
V_294 . V_300 = 2 * ( 1024 * 1024 ) ;
V_294 . V_302 = 0x7075901 ;
F_75 ( V_3 , & V_294 ) ;
}
}
static long
F_80 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_293 V_127 ;
long V_278 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_278 = F_75 ( V_3 , & V_127 ) ;
return V_278 ;
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_320 V_127 ;
void * V_295 ;
T_14 V_296 ;
T_7 V_297 ;
T_6 V_285 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_285 = V_127 . V_302 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_285 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_112 [ V_285 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_176 ;
}
if ( ( V_3 -> V_112 [ V_285 ] &
V_114 ) == 0 ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_176 ;
}
if ( V_127 . V_302 != V_3 -> V_302 [ V_285 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_302 ) ;
return - V_176 ;
}
V_295 = V_3 -> V_301 [ V_285 ] ;
if ( ! V_295 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_173 ;
}
V_297 = V_3 -> V_307 [ V_285 ] ;
V_296 = V_3 -> V_306 [ V_285 ] ;
F_58 ( V_3 -> V_183 , V_297 ,
V_295 , V_296 ) ;
V_3 -> V_301 [ V_285 ] = NULL ;
V_3 -> V_112 [ V_285 ] = 0 ;
return 0 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_321 V_127 ;
void * V_295 ;
int V_77 ;
T_6 V_285 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_322 = 0 ;
V_285 = V_127 . V_285 ;
if ( ! F_74 ( V_3 , V_285 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_112 [ V_285 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_176 ;
}
if ( V_127 . V_302 & 0xffffff00 ) {
if ( V_127 . V_302 != V_3 -> V_302 [ V_285 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_302 ) ;
return - V_176 ;
}
}
V_295 = V_3 -> V_301 [ V_285 ] ;
if ( ! V_295 ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_173 ;
}
if ( V_3 -> V_112 [ V_285 ] & V_114 )
V_127 . V_322 = ( V_323 |
V_324 ) ;
else
V_127 . V_322 = ( V_323 |
V_324 |
V_325 ) ;
for ( V_77 = 0 ; V_77 < V_304 ; V_77 ++ )
V_127 . V_303 [ V_77 ] =
V_3 -> V_303 [ V_285 ] [ V_77 ] ;
V_127 . V_326 = V_3 -> V_307 [ V_285 ] ;
V_127 . V_327 = 0 ;
V_127 . V_302 = V_3 -> V_302 [ V_285 ] ;
V_127 . V_305 = V_3 -> V_305 [ V_285 ] ;
if ( F_36 ( V_221 , & V_127 , sizeof( struct V_321 ) ) ) {
F_37 ( V_45
L_70 ,
V_3 -> V_46 , V_110 , V_221 ) ;
return - V_170 ;
}
return 0 ;
}
int
F_26 ( struct V_2 * V_3 , T_6 V_285 ,
T_6 * V_108 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_298 ;
T_7 V_155 ;
int V_278 ;
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_278 = 0 ;
* V_108 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
if ( V_3 -> V_112 [ V_285 ] &
V_113 )
V_3 -> V_112 [ V_285 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45
L_71 , V_3 -> V_46 ,
V_110 ) ) ;
V_278 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_308 = V_285 ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_209 * V_210 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
* V_108 = 1 ;
V_278 = - V_170 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_298 = F_5 ( V_10 -> V_47 ) & V_313 ;
if ( V_298 == V_314 ) {
V_3 -> V_112 [ V_285 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_298 , F_7 ( V_10 -> V_48 ) ) ;
V_278 = - V_170 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_278 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_328 V_127 ;
void * V_295 ;
int V_278 ;
T_6 V_285 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_285 = V_127 . V_302 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_285 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_112 [ V_285 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_176 ;
}
if ( V_127 . V_302 != V_3 -> V_302 [ V_285 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_302 ) ;
return - V_176 ;
}
if ( V_3 -> V_112 [ V_285 ] &
V_114 ) {
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_110 ,
V_285 ) ;
return 0 ;
}
V_295 = V_3 -> V_301 [ V_285 ] ;
if ( ! V_295 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_173 ;
}
if ( ( V_3 -> V_112 [ V_285 ] &
V_118 ) ) {
V_3 -> V_112 [ V_285 ] |=
V_114 ;
V_3 -> V_112 [ V_285 ] &=
~ V_118 ;
F_37 ( V_45
L_73 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return 0 ;
}
V_278 = F_26 ( V_3 , V_285 , & V_108 ) ;
if ( V_108 )
F_57 ( V_3 , V_220 ) ;
return V_278 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_329 V_127 ;
struct V_329 T_12 * V_266 = V_221 ;
void * V_295 , * V_330 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_278 , V_77 ;
T_6 V_285 ;
unsigned long V_331 , V_332 ;
T_1 V_8 ;
T_1 V_298 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_110 ) ) ;
V_285 = V_127 . V_302 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_285 ) ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_299 ;
}
if ( V_127 . V_302 != V_3 -> V_302 [ V_285 ] ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_127 . V_302 ) ;
return - V_176 ;
}
V_295 = V_3 -> V_301 [ V_285 ] ;
if ( ! V_295 ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_285 ) ;
return - V_173 ;
}
V_331 = V_3 -> V_307 [ V_285 ] ;
if ( ( V_127 . V_333 % 4 ) || ( V_127 . V_334 % 4 ) ) {
F_37 ( V_45 L_74 \
L_75 , V_3 -> V_46 ,
V_110 ) ;
return - V_176 ;
}
if ( V_127 . V_333 > V_331 )
return - V_176 ;
V_330 = ( void * ) ( V_295 + V_127 . V_333 ) ;
F_35 ( V_3 , F_6 ( V_45
L_76 ,
V_3 -> V_46 , V_110 ,
V_330 , V_127 . V_333 , V_127 . V_334 ) ) ;
if ( ( V_330 + V_127 . V_334 < V_330 ) ||
( V_330 + V_127 . V_334 > V_295 + V_331 ) )
V_332 = V_331 - V_127 . V_333 ;
else
V_332 = V_127 . V_334 ;
if ( F_36 ( ( void T_12 * ) V_266 -> V_335 ,
V_330 , V_332 ) ) {
F_37 ( V_45
L_77 ,
V_3 -> V_46 , V_110 , V_330 ) ;
return - V_170 ;
}
if ( ( V_127 . V_50 & V_336 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_110 , V_285 ) ) ;
if ( ( V_3 -> V_112 [ V_285 ] &
V_114 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_79 ,
V_3 -> V_46 , V_110 , V_285 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_168 ;
goto V_7;
}
V_278 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_308 = V_285 ;
V_11 -> V_311 =
F_77 ( V_3 -> V_307 [ V_285 ] ) ;
V_11 -> V_310 =
F_78 ( V_3 -> V_306 [ V_285 ] ) ;
for ( V_77 = 0 ; V_77 < V_304 ; V_77 ++ )
V_11 -> V_312 [ V_77 ] =
F_77 ( V_3 -> V_303 [ V_285 ] [ V_77 ] ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
V_3 -> V_191 ( V_3 , V_8 ) ;
F_51 ( & V_3 -> V_64 . V_75 ,
V_209 * V_210 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_42 , V_3 -> V_46 ,
V_110 ) ;
F_54 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_212;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ;
V_278 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_298 = F_5 ( V_10 -> V_47 ) & V_313 ;
if ( V_298 == V_314 ) {
V_3 -> V_112 [ V_285 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_60 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_61 ,
V_3 -> V_46 , V_110 ,
V_298 , F_7 ( V_10 -> V_48 ) ) ;
V_278 = - V_170 ;
}
V_212:
if ( V_108 )
F_57 ( V_3 , V_220 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_278 ;
}
static long
F_85 ( struct V_2 * V_3 , unsigned V_337 ,
void T_12 * V_221 )
{
struct V_338 V_339 ;
struct V_338 T_12 * V_266 ;
struct V_126 V_127 ;
if ( F_86 ( V_337 ) != sizeof( struct V_338 ) )
return - V_176 ;
V_266 = (struct V_338 T_12 * ) V_221 ;
if ( F_42 ( & V_339 , ( char T_12 * ) V_221 , sizeof( V_339 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 . V_267 . V_98 = V_339 . V_267 . V_98 ;
V_127 . V_267 . V_224 = V_339 . V_267 . V_224 ;
V_127 . V_267 . V_268 = V_339 . V_267 . V_268 ;
V_127 . V_156 = V_339 . V_156 ;
V_127 . V_150 = V_339 . V_150 ;
V_127 . V_179 = V_339 . V_179 ;
V_127 . V_178 = V_339 . V_178 ;
V_127 . V_217 = V_339 . V_217 ;
V_127 . V_174 = V_339 . V_174 ;
V_127 . V_152 = F_87 ( V_339 . V_152 ) ;
V_127 . V_215 = F_87 ( V_339 . V_215 ) ;
V_127 . V_184 = F_87 ( V_339 . V_184 ) ;
V_127 . V_218 = F_87 ( V_339 . V_218 ) ;
return F_38 ( V_3 , V_127 , & V_266 -> V_153 ) ;
}
static long
F_88 ( struct V_120 * V_120 , unsigned int V_337 , void T_12 * V_221 ,
T_6 V_340 , T_1 V_100 )
{
struct V_2 * V_3 ;
struct V_269 V_341 ;
enum V_342 V_343 ;
long V_164 = - V_176 ;
if ( F_42 ( & V_341 , ( char T_12 * ) V_221 ,
sizeof( struct V_269 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( F_21 ( V_341 . V_98 ,
& V_3 , V_100 ) == - 1 || ! V_3 )
return - V_344 ;
F_89 ( & V_3 -> V_345 ) ;
if ( V_3 -> V_273 || V_3 -> V_274 ||
V_3 -> V_275 || V_3 -> V_346 ) {
V_164 = - V_168 ;
goto V_347;
}
V_343 = ( V_120 -> V_348 & V_349 ) ? V_350 : V_351 ;
if ( V_343 == V_350 ) {
if ( ! F_90 ( & V_3 -> V_64 . V_352 ) ) {
V_164 = - V_168 ;
goto V_347;
}
} else if ( F_91 ( & V_3 -> V_64 . V_352 ) ) {
V_164 = - V_353 ;
goto V_347;
}
switch ( V_337 ) {
case V_354 :
if ( F_86 ( V_337 ) == sizeof( struct V_222 ) )
V_164 = F_60 ( V_3 , V_221 ) ;
break;
#ifdef F_92
case V_355 :
#endif
case V_356 :
{
struct V_126 T_12 * V_266 ;
struct V_126 V_127 ;
#ifdef F_92
if ( V_340 ) {
V_164 = F_85 ( V_3 , V_337 , V_221 ) ;
break;
}
#endif
if ( F_42 ( & V_127 , V_221 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
V_164 = - V_170 ;
break;
}
if ( F_86 ( V_337 ) == sizeof( struct V_126 ) ) {
V_266 = V_221 ;
V_164 = F_38 ( V_3 , V_127 , & V_266 -> V_153 ) ;
}
break;
}
case V_357 :
if ( F_86 ( V_337 ) == sizeof( struct V_257 ) )
V_164 = F_64 ( V_3 , V_221 ) ;
break;
case V_358 :
if ( F_86 ( V_337 ) == sizeof( struct V_261 ) )
V_164 = F_65 ( V_3 , V_221 ) ;
break;
case V_359 :
V_164 = F_68 ( V_3 , V_221 ) ;
break;
case V_360 :
if ( F_86 ( V_337 ) == sizeof( struct V_271 ) )
V_164 = F_69 ( V_3 , V_221 ) ;
break;
case V_361 :
if ( F_86 ( V_337 ) == sizeof( struct V_276 ) )
V_164 = F_73 ( V_3 , V_221 ) ;
break;
case V_362 :
if ( F_86 ( V_337 ) == sizeof( struct V_293 ) )
V_164 = F_80 ( V_3 , V_221 ) ;
break;
case V_363 :
if ( F_86 ( V_337 ) == sizeof( struct V_320 ) )
V_164 = F_81 ( V_3 , V_221 ) ;
break;
case V_364 :
if ( F_86 ( V_337 ) == sizeof( struct V_321 ) )
V_164 = F_82 ( V_3 , V_221 ) ;
break;
case V_365 :
if ( F_86 ( V_337 ) == sizeof( struct V_328 ) )
V_164 = F_83 ( V_3 , V_221 ) ;
break;
case V_366 :
if ( F_86 ( V_337 ) == sizeof( struct V_329 ) )
V_164 = F_84 ( V_3 , V_221 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_80 , V_3 -> V_46 , V_337 ) ) ;
break;
}
F_93 ( & V_3 -> V_64 . V_352 ) ;
V_347:
F_93 ( & V_3 -> V_345 ) ;
return V_164 ;
}
static long
F_94 ( struct V_120 * V_120 , unsigned int V_337 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_337 , ( void T_12 * ) V_221 , 0 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_95 ( struct V_120 * V_120 , unsigned int V_337 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_337 , ( void T_12 * ) V_221 , 0 , V_244 ) ;
return V_164 ;
}
static long
F_96 ( struct V_120 * V_120 , unsigned V_337 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_337 , ( void T_12 * ) V_221 , 1 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_97 ( struct V_120 * V_120 , unsigned V_337 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_120 , V_337 , ( void T_12 * ) V_221 , 1 , V_244 ) ;
return V_164 ;
}
static T_23
F_98 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_81 ,
( V_3 -> V_181 . V_240 . V_241 & 0xFF000000 ) >> 24 ,
( V_3 -> V_181 . V_240 . V_241 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_181 . V_240 . V_241 & 0x0000FF00 ) >> 8 ,
V_3 -> V_181 . V_240 . V_241 & 0x000000FF ) ;
}
static T_23
F_101 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
T_7 V_101 = F_7 ( V_3 -> V_255 . V_256 ) ;
return snprintf ( V_370 , V_373 , L_81 ,
( V_101 & 0xFF000000 ) >> 24 ,
( V_101 & 0x00FF0000 ) >> 16 ,
( V_101 & 0x0000FF00 ) >> 8 ,
V_101 & 0x000000FF ) ;
}
static T_23
F_102 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_82 ,
V_3 -> V_181 . V_374 , V_3 -> V_181 . V_375 >> 8 ) ;
}
static T_23
F_103 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , 16 , L_52 , V_3 -> V_376 . V_377 ) ;
}
static T_23
F_104 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_83 ,
F_7 ( V_3 -> V_378 . V_379 . V_241 ) ) ;
}
static T_23
F_105 ( struct V_144 * V_367 , struct V_368
* V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_83 ,
F_7 ( V_3 -> V_378 . V_380 . V_241 ) ) ;
}
static T_23
F_106 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , 16 , L_52 , V_3 -> V_376 . V_381 ) ;
}
static T_23
F_107 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , 16 , L_52 , V_3 -> V_376 . V_382 ) ;
}
static T_23
F_108 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , 16 , L_52 , V_3 -> V_376 . V_383 ) ;
}
static T_23
F_109 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_84 , V_3 -> V_384 ) ;
}
static T_23
F_110 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_84 , V_3 -> V_385 ) ;
}
static T_23
F_111 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_84 , V_3 -> V_181 . V_386 ) ;
}
static T_23
F_112 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_85 ,
( unsigned long long ) V_3 -> V_387 . V_53 ) ;
}
static T_23
F_113 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_83 , V_3 -> V_13 ) ;
}
static T_23
F_114 ( struct V_144 * V_367 , struct V_368 * V_369 ,
const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
int V_389 = 0 ;
if ( sscanf ( V_370 , L_86 , & V_389 ) != 1 )
return - V_176 ;
V_3 -> V_13 = V_389 ;
F_6 ( V_45 L_87 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_370 ) ;
}
static T_23
F_115 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_88 , V_3 -> V_390 ) ;
}
static T_23
F_116 ( struct V_144 * V_367 , struct V_368 * V_369 ,
const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
int V_389 = 0 ;
if ( sscanf ( V_370 , L_89 , & V_389 ) != 1 )
return - V_176 ;
V_3 -> V_390 = V_389 ;
F_6 ( V_45 L_90 , V_3 -> V_46 ,
V_3 -> V_390 ) ;
return strlen ( V_370 ) ;
}
static T_23
F_117 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
return snprintf ( V_370 , V_373 , L_88 , V_3 -> V_391 ) ;
}
static T_23
F_118 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
T_6 V_392 ;
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
if ( ( V_3 -> V_181 . V_287 &
V_393 ) && V_3 -> V_394 )
V_392 = V_3 -> V_392 ;
else
V_392 = 1 ;
return snprintf ( V_370 , V_373 , L_88 , V_392 ) ;
}
static T_23
F_119 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
T_24 * V_395 = NULL ;
T_25 V_10 ;
T_1 V_396 = 0 ;
T_1 V_298 ;
int V_63 ;
T_23 V_278 = 0 ;
if ( ! V_3 -> V_245 ) {
F_37 ( V_45 L_91
L_92 , V_3 -> V_46 , V_110 ) ;
goto V_7;
}
F_89 ( & V_3 -> V_345 ) ;
if ( V_3 -> V_274 || V_3 -> V_346 ) {
F_93 ( & V_3 -> V_345 ) ;
return 0 ;
}
V_63 = F_120 ( T_24 , V_397 ) + ( sizeof( T_1 ) * 36 ) ;
V_395 = F_41 ( V_63 , V_172 ) ;
if ( ! V_395 ) {
F_37 ( V_45 L_93
L_94 , V_3 -> V_46 , V_110 , V_63 ) ;
goto V_7;
}
if ( F_121 ( V_3 , & V_10 , V_395 , V_63 ) !=
0 ) {
F_37 ( V_45
L_95 , V_3 -> V_46 ,
V_110 ) ;
goto V_7;
}
V_298 = F_5 ( V_10 . V_47 ) & V_313 ;
if ( V_298 != V_314 ) {
F_37 ( V_45 L_96
L_97 , V_3 -> V_46 , V_110 , V_298 ) ;
goto V_7;
}
if ( V_395 -> V_398 < 25 ) {
F_37 ( V_45 L_98
L_99 , V_3 -> V_46 , V_110 ,
V_395 -> V_398 ) ;
goto V_7;
}
V_396 = F_5 ( V_395 -> V_397 [ 24 ] ) ;
V_278 = snprintf ( V_370 , V_373 , L_88 , ( V_396 & 1 ) ) ;
V_7:
F_59 ( V_395 ) ;
F_93 ( & V_3 -> V_345 ) ;
return V_278 ;
}
static T_23
F_122 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
T_7 V_399 = 0 ;
struct V_400 * V_295 ;
if ( ! V_3 -> V_301 [ V_286 ] ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
V_295 = (struct V_400 * )
V_3 -> V_301 [ V_286 ] ;
if ( ( F_7 ( V_295 -> V_401 ) == 0x00000000 ||
F_7 ( V_295 -> V_401 ) == 0x01000000 ||
F_7 ( V_295 -> V_401 ) == 0x01010000 ) &&
F_7 ( V_295 -> V_402 ) == 0x4742444c )
V_399 = F_7 ( V_295 -> V_403 ) ;
V_3 -> V_404 = V_399 ;
return snprintf ( V_370 , V_373 , L_88 , V_399 ) ;
}
static T_23
F_123 ( struct V_144 * V_367 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
void * V_295 ;
T_7 V_399 ;
if ( ! V_3 -> V_301 [ V_286 ] ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_100 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( V_3 -> V_405 > V_3 -> V_404 )
return 0 ;
V_399 = V_3 -> V_404 - V_3 -> V_405 ;
V_399 = ( V_399 >= V_373 ) ? ( V_373 - 1 ) : V_399 ;
V_295 = V_3 -> V_301 [ 0 ] + V_3 -> V_405 ;
memcpy ( V_370 , V_295 , V_399 ) ;
return V_399 ;
}
static T_23
F_124 ( struct V_144 * V_367 , struct V_368 * V_369 ,
const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
int V_389 = 0 ;
if ( sscanf ( V_370 , L_89 , & V_389 ) != 1 )
return - V_176 ;
V_3 -> V_405 = V_389 ;
return strlen ( V_370 ) ;
}
static T_23
F_125 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
if ( ( ! V_3 -> V_301 [ V_286 ] ) ||
( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 ) )
return snprintf ( V_370 , V_373 , L_101 ) ;
else if ( ( V_3 -> V_112 [ V_286 ] &
V_114 ) )
return snprintf ( V_370 , V_373 , L_102 ) ;
else
return snprintf ( V_370 , V_373 , L_103 ) ;
}
static T_23
F_126 ( struct V_144 * V_367 ,
struct V_368 * V_369 , const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
char V_406 [ 10 ] = L_104 ;
struct V_293 V_294 ;
T_6 V_108 = 0 ;
if ( V_3 -> V_273 || V_3 -> V_346 ||
V_3 -> V_274 || V_3 -> V_275 )
return - V_407 ;
if ( sscanf ( V_370 , L_105 , V_406 ) != 1 )
return - V_176 ;
if ( ! strcmp ( V_406 , L_106 ) ) {
if ( ( V_3 -> V_301 [ V_286 ] ) &&
( V_3 -> V_112 [ V_286 ] &
V_113 ) &&
( ( V_3 -> V_112 [ V_286 ] &
V_114 ) == 0 ) )
goto V_7;
memset ( & V_294 , 0 , sizeof( struct V_293 ) ) ;
F_6 ( V_45 L_107 ,
V_3 -> V_46 ) ;
V_294 . V_285 = V_286 ;
V_294 . V_300 = ( 1024 * 1024 ) ;
V_294 . V_302 = 0x7075900 ;
V_3 -> V_112 [ V_286 ] = 0 ;
F_75 ( V_3 , & V_294 ) ;
} else if ( ! strcmp ( V_406 , L_108 ) ) {
if ( ! V_3 -> V_301 [ V_286 ] )
goto V_7;
if ( ( V_3 -> V_112 [ V_286 ] &
V_113 ) == 0 )
goto V_7;
if ( ( V_3 -> V_112 [ V_286 ] &
V_114 ) )
goto V_7;
F_6 ( V_45 L_109 ,
V_3 -> V_46 ) ;
F_26 ( V_3 , V_286 ,
& V_108 ) ;
}
V_7:
return strlen ( V_370 ) ;
}
static T_23
F_127 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_278 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_278 = sizeof( struct V_409 ) ;
memcpy ( V_370 , & V_3 -> V_316 , V_278 ) ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_278 ;
}
static T_23
F_128 ( struct V_144 * V_367 ,
struct V_368 * V_369 , const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_278 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_278 = F_129 ( sizeof( struct V_409 ) , V_388 ) ;
memset ( & V_3 -> V_316 , 0 ,
sizeof( struct V_409 ) ) ;
memcpy ( & V_3 -> V_316 , V_370 , V_278 ) ;
V_3 -> V_316 . V_317 |=
( V_318 + V_319 ) ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_278 ;
}
static T_23
F_130 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_278 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_278 = sizeof( struct V_410 ) ;
memcpy ( V_370 , & V_3 -> V_411 , V_278 ) ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_278 ;
}
static T_23
F_131 ( struct V_144 * V_367 ,
struct V_368 * V_369 , const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_410 ) , V_388 ) ;
memset ( & V_3 -> V_411 , 0 ,
sizeof( struct V_410 ) ) ;
memcpy ( & V_3 -> V_411 , V_370 , V_63 ) ;
if ( V_3 -> V_411 . V_412 > V_413 )
V_3 -> V_411 . V_412 = V_413 ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_63 ;
}
static T_23
F_132 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_278 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_278 = sizeof( struct V_414 ) ;
memcpy ( V_370 , & V_3 -> V_415 , V_278 ) ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_278 ;
}
static T_23
F_133 ( struct V_144 * V_367 ,
struct V_368 * V_369 , const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_414 ) , V_388 ) ;
memset ( & V_3 -> V_415 , 0 ,
sizeof( struct V_410 ) ) ;
memcpy ( & V_3 -> V_415 , V_370 , V_63 ) ;
if ( V_3 -> V_415 . V_412 > V_413 )
V_3 -> V_415 . V_412 = V_413 ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_63 ;
}
static T_23
F_134 ( struct V_144 * V_367 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_278 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_278 = sizeof( struct V_416 ) ;
memcpy ( V_370 , & V_3 -> V_417 , V_278 ) ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_278 ;
}
static T_23
F_135 ( struct V_144 * V_367 ,
struct V_368 * V_369 , const char * V_370 , T_15 V_388 )
{
struct V_371 * V_372 = F_99 ( V_367 ) ;
struct V_2 * V_3 = F_100 ( V_372 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_408 , V_50 ) ;
V_63 = F_129 ( sizeof( struct V_416 ) , V_388 ) ;
memset ( & V_3 -> V_417 , 0 ,
sizeof( V_3 -> V_417 ) ) ;
memcpy ( & V_3 -> V_417 , V_370 , V_63 ) ;
if ( V_3 -> V_417 . V_412 > V_413 )
V_3 -> V_417 . V_412 = V_413 ;
F_10 ( & V_3 -> V_408 , V_50 ) ;
return V_63 ;
}
static T_23
F_136 ( struct V_144 * V_418 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_419 * V_420 = F_137 ( V_418 ) ;
struct V_132 * V_421 = V_420 -> V_145 ;
return snprintf ( V_370 , V_373 , L_85 ,
( unsigned long long ) V_421 -> V_146 -> V_53 ) ;
}
static T_23
F_138 ( struct V_144 * V_418 , struct V_368 * V_369 ,
char * V_370 )
{
struct V_419 * V_420 = F_137 ( V_418 ) ;
struct V_132 * V_421 = V_420 -> V_145 ;
return snprintf ( V_370 , V_373 , L_110 ,
V_421 -> V_146 -> V_4 ) ;
}
static T_23
F_139 ( struct V_144 * V_418 ,
struct V_368 * V_369 , char * V_370 )
{
struct V_419 * V_420 = F_137 ( V_418 ) ;
struct V_132 * V_421 = V_420 -> V_145 ;
return snprintf ( V_370 , V_373 , L_88 ,
V_421 -> V_422 ) ;
}
static T_23
F_140 ( struct V_144 * V_418 ,
struct V_368 * V_369 ,
const char * V_370 , T_15 V_388 )
{
struct V_419 * V_420 = F_137 ( V_418 ) ;
struct V_132 * V_421 = V_420 -> V_145 ;
bool V_422 = 0 ;
if ( F_141 ( V_370 , & V_422 ) )
return - V_176 ;
if ( ! F_142 ( V_420 ) )
return - V_176 ;
V_421 -> V_422 = V_422 ;
return strlen ( V_370 ) ;
}
void
F_143 ( T_26 V_423 )
{
V_95 = NULL ;
if ( V_423 != 1 )
if ( F_144 ( & V_424 ) < 0 )
F_37 ( L_111 ,
V_425 , V_426 ) ;
if ( V_423 != 2 )
if ( F_144 ( & V_427 ) < 0 )
F_37 ( L_111 ,
V_428 , V_429 ) ;
F_145 ( & V_94 ) ;
}
void
F_146 ( T_26 V_423 )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! V_3 -> V_301 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
F_58 ( V_3 -> V_183 , V_3 -> V_307 [ V_77 ] ,
V_3 -> V_301 [ V_77 ] , V_3 -> V_306 [ V_77 ] ) ;
V_3 -> V_301 [ V_77 ] = NULL ;
V_3 -> V_112 [ V_77 ] = 0 ;
}
F_59 ( V_3 -> V_79 ) ;
}
if ( V_423 != 1 )
F_147 ( & V_424 ) ;
if ( V_423 != 2 )
F_147 ( & V_427 ) ;
}
