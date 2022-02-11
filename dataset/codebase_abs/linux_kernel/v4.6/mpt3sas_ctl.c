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
int
F_28 ( int V_119 , struct V_120 * V_121 , int V_122 )
{
return F_29 ( V_119 , V_121 , V_122 , & V_95 ) ;
}
unsigned int
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
T_1 V_156 ;
T_1 V_8 ;
unsigned long V_157 , V_158 ;
T_6 V_108 ;
T_7 V_63 ;
void * V_159 ;
void * V_160 = NULL ;
T_14 V_161 = 0 ;
T_15 V_162 = 0 ;
void * V_163 = NULL ;
T_14 V_164 = 0 ;
T_15 V_165 = 0 ;
long V_166 ;
T_1 V_167 ;
V_108 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_166 = - V_168 ;
goto V_7;
}
V_167 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
while ( V_155 != V_169 ) {
if ( V_167 ++ == 10 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_166 = - V_170 ;
goto V_7;
}
F_40 ( 1 ) ;
V_155 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45
L_35 ,
V_3 -> V_46 ,
V_110 , V_167 ) ;
}
if ( V_167 )
F_6 ( V_45 L_36 ,
V_3 -> V_46 , V_110 ) ;
V_11 = F_41 ( V_3 -> V_171 , V_172 ) ;
if ( ! V_11 ) {
F_37 ( V_45
L_37 ,
V_3 -> V_46 , V_110 ) ;
V_166 = - V_173 ;
goto V_7;
}
if ( V_127 . V_174 * 4 > V_3 -> V_171 ||
V_127 . V_174 > ( V_175 / 4 ) ) {
V_166 = - V_176 ;
goto V_7;
}
if ( F_42 ( V_11 , V_153 , V_127 . V_174 * 4 ) ) {
F_37 ( L_31 , __FILE__ , __LINE__ ,
V_110 ) ;
V_166 = - V_170 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_166 = - V_168 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_177 , NULL ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_166 = - V_168 ;
goto V_7;
}
}
V_166 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_154 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_154 , V_11 , V_127 . V_174 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_162 = V_127 . V_178 ;
V_165 = V_127 . V_179 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_180 ) ||
F_5 ( V_11 -> V_180 ) >
V_3 -> V_181 . V_182 ) {
V_166 = - V_176 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_162 ) {
V_160 = F_45 ( V_3 -> V_183 , V_162 ,
& V_161 ) ;
if ( ! V_160 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_173 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_160 , V_127 . V_184 ,
V_162 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_170 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_165 ) {
V_163 = F_45 ( V_3 -> V_183 , V_165 ,
& V_164 ) ;
if ( ! V_163 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_173 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_159 = ( void * ) V_154 + ( V_127 . V_174 * 4 ) ;
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
V_3 -> V_188 ( V_3 , V_159 , V_161 , V_162 ,
V_164 , V_165 ) ;
if ( V_11 -> V_15 == V_16 )
F_48 ( V_3 , V_8 ,
F_5 ( V_11 -> V_180 ) ) ;
else
F_49 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_128 =
( T_10 * ) V_154 ;
F_25 ( V_3 , F_6 ( V_45
L_40 ,
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
F_50 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
V_3 -> V_189 ( V_3 , V_159 , V_161 , V_162 ,
V_164 , V_165 ) ;
F_51 ( V_3 , V_8 , 0 ) ;
break;
}
case V_44 :
{
T_16 * V_190 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_190 -> V_191 = 0xFF ;
if ( V_190 -> V_192 &
V_193 )
V_90 = ( T_6 * ) & V_190 -> V_194 ;
else {
if ( F_52 ( V_160 == NULL ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
F_27 ( V_3 , V_8 ) ;
V_166 = - V_176 ;
goto V_7;
}
V_90 = V_160 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_195 = 1 ;
V_3 -> V_196 = 1 ;
}
V_3 -> V_188 ( V_3 , V_159 , V_161 , V_162 , V_164 ,
V_165 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_41 :
case V_36 :
case V_37 :
{
V_3 -> V_188 ( V_3 , V_159 , V_161 , V_162 , V_164 ,
V_165 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_197 :
{
T_17 * V_198 =
( T_17 * ) V_11 ;
if ( V_198 -> V_199 == V_200 ) {
V_3 -> V_188 ( V_3 , V_159 , V_161 , V_162 ,
V_164 , V_165 ) ;
} else {
V_3 -> V_189 ( V_3 , V_159 , V_161 , V_162 ,
V_164 , V_165 ) ;
}
F_49 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_201 =
( T_18 * ) V_11 ;
if ( V_201 -> V_202 == V_203
|| V_201 -> V_202 ==
V_204 ) {
V_3 -> V_195 = 1 ;
V_3 -> V_196 = 1 ;
}
}
default:
V_3 -> V_189 ( V_3 , V_159 , V_161 , V_162 ,
V_164 , V_165 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
if ( V_127 . V_157 < V_205 )
V_157 = V_205 ;
else
V_157 = V_127 . V_157 ;
V_158 = F_53 ( & V_3 -> V_64 . V_75 ,
V_157 * V_206 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_128 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
F_55 ( V_3 , V_207 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_195 ) {
V_3 -> V_195 = 0 ;
V_3 -> V_196 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 , V_127 . V_174 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_208;
}
V_10 = V_3 -> V_64 . V_60 ;
V_156 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_210 ) ) {
T_11 * V_134 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_42 \
L_43
L_44 , V_3 -> V_46 ,
F_5 ( V_134 -> V_47 ) ,
F_7 ( V_134 -> V_48 ) ,
F_7 ( V_134 -> V_211 ) ) ;
}
if ( V_165 ) {
if ( F_36 ( V_127 . V_212 , V_163 ,
V_165 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_213 ;
goto V_7;
}
}
if ( V_127 . V_150 ) {
V_63 = F_13 ( T_7 , V_127 . V_150 , V_3 -> V_151 ) ;
if ( F_36 ( V_127 . V_152 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_213 ;
goto V_7;
}
}
if ( V_127 . V_214 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_127 . V_214 , V_71 ) ;
if ( F_36 ( V_127 . V_215 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_166 = - V_213 ;
goto V_7;
}
}
V_208:
if ( V_108 ) {
V_166 = - V_213 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_45 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_180 ) ) ;
F_57 ( V_3 ) ;
F_58 ( V_3 ,
F_5 ( V_11 -> V_180 ) , 0 , 0 ,
0 , V_216 , 0 , 30 ,
V_217 ) ;
} else
F_59 ( V_3 , V_218 ,
V_219 ) ;
}
V_7:
if ( V_163 )
F_60 ( V_3 -> V_183 , V_165 , V_163 ,
V_164 ) ;
if ( V_160 )
F_60 ( V_3 -> V_183 , V_162 , V_160 ,
V_161 ) ;
F_61 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_166 ;
}
static long
F_62 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_221 V_127 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( V_3 -> V_222 )
V_127 . V_223 = V_3 -> V_222 [ 0 ] . V_224 ;
V_127 . V_225 = V_3 -> V_183 -> V_226 ;
V_127 . V_227 = V_3 -> V_183 -> V_144 ;
V_127 . V_228 = V_3 -> V_183 -> V_228 ;
V_127 . V_229 = V_3 -> V_183 -> V_229 ;
V_127 . V_230 . V_231 . V_232 . V_233 = V_3 -> V_183 -> V_233 -> V_234 ;
V_127 . V_230 . V_231 . V_232 . V_144 = F_63 ( V_3 -> V_183 -> V_235 ) ;
V_127 . V_230 . V_231 . V_232 . V_236 = F_64 ( V_3 -> V_183 -> V_235 ) ;
V_127 . V_230 . V_237 = F_65 ( V_3 -> V_183 -> V_233 ) ;
V_127 . V_238 = V_3 -> V_181 . V_239 . V_240 ;
strcpy ( V_127 . V_241 , V_3 -> V_242 ) ;
strcat ( V_127 . V_241 , L_47 ) ;
switch ( V_3 -> V_104 ) {
case V_243 :
if ( V_3 -> V_244 )
V_127 . V_245 = V_246 ;
else
V_127 . V_245 = V_247 ;
strcat ( V_127 . V_241 , V_248 ) ;
break;
case V_105 :
case V_106 :
V_127 . V_245 = V_249 ;
strcat ( V_127 . V_241 , V_250 ) ;
break;
}
V_127 . V_251 = F_7 ( V_3 -> V_252 . V_253 ) ;
if ( F_36 ( V_220 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_254 V_127 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_255 = V_86 ;
memcpy ( V_127 . V_256 , V_3 -> V_80 ,
V_257 * sizeof( T_7 ) ) ;
if ( F_36 ( V_220 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_67 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_258 V_127 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
memcpy ( V_3 -> V_80 , V_127 . V_256 ,
V_257 * sizeof( T_7 ) ) ;
F_68 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_69 ( V_86 ,
sizeof( struct V_81 ) , V_172 ) ;
if ( ! V_3 -> V_79 ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_173 ;
}
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_259 V_127 ;
T_7 V_260 , V_261 , V_262 ;
struct V_259 T_12 * V_263 = V_220 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_260 = V_127 . V_264 . V_265 -
sizeof( struct V_266 ) ;
V_261 = V_260 / sizeof( struct V_81 ) ;
V_262 = F_13 ( T_7 , V_86 , V_261 ) ;
if ( ! V_262 || ! V_3 -> V_79 )
return - V_213 ;
V_260 = V_262 * sizeof( struct V_81 ) ;
if ( F_36 ( V_263 -> V_267 , V_3 -> V_79 , V_260 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_71 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_268 V_127 ;
int V_269 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( V_3 -> V_270 || V_3 -> V_271 ||
V_3 -> V_272 )
return - V_168 ;
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_269 = F_59 ( V_3 , V_218 ,
V_219 ) ;
F_6 ( V_45 L_48 ,
V_3 -> V_46 , ( ( ! V_269 ) ? L_49 : L_50 ) ) ;
return 0 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_273 * V_274 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_275 = 0 ;
if ( F_73 ( & V_3 -> V_276 ) )
return V_275 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_274 -> V_233 == 0xFFFFFFFF && V_274 -> V_103 == 0xFFFFFFFF &&
V_274 -> V_4 == V_5 -> V_4 ) {
V_274 -> V_233 = V_5 -> V_277 ;
V_274 -> V_103 = V_5 -> V_103 ;
V_275 = 1 ;
goto V_7;
} else if ( V_274 -> V_233 == V_5 -> V_277 && V_274 -> V_103 ==
V_5 -> V_103 && V_274 -> V_4 == 0xFFFF ) {
V_274 -> V_4 = V_5 -> V_4 ;
V_275 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_275 ;
}
static int
F_74 ( struct V_2 * V_3 ,
struct V_273 * V_274 )
{
struct V_278 * V_279 ;
unsigned long V_50 ;
int V_275 = 0 ;
if ( F_73 ( & V_3 -> V_280 ) )
return V_275 ;
F_8 ( & V_3 -> V_281 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_274 -> V_233 == 0xFFFFFFFF && V_274 -> V_103 == 0xFFFFFFFF &&
V_274 -> V_4 == V_279 -> V_4 ) {
V_274 -> V_233 = V_279 -> V_277 ;
V_274 -> V_103 = V_279 -> V_103 ;
V_275 = 1 ;
goto V_7;
} else if ( V_274 -> V_233 == V_279 -> V_277 && V_274 -> V_103 ==
V_279 -> V_103 && V_274 -> V_4 == 0xFFFF ) {
V_274 -> V_4 = V_279 -> V_4 ;
V_275 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_281 , V_50 ) ;
return V_275 ;
}
static long
F_75 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_273 V_127 ;
int V_275 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_275 = F_72 ( V_3 , & V_127 ) ;
if ( ! V_275 )
F_74 ( V_3 , & V_127 ) ;
if ( F_36 ( V_220 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
return 0 ;
}
static T_6
F_76 ( struct V_2 * V_3 , T_6 V_282 )
{
T_6 V_275 = 0 ;
switch ( V_282 ) {
case V_283 :
if ( V_3 -> V_181 . V_284 &
V_285 )
V_275 = 1 ;
break;
case V_286 :
if ( V_3 -> V_181 . V_284 &
V_287 )
V_275 = 1 ;
break;
case V_288 :
if ( V_3 -> V_181 . V_284 &
V_289 )
V_275 = 1 ;
}
return V_275 ;
}
static long
F_77 ( struct V_2 * V_3 ,
struct V_290 * V_291 )
{
int V_275 , V_77 ;
void * V_292 = NULL ;
T_14 V_293 ;
T_7 V_294 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_282 ;
unsigned long V_158 ;
T_1 V_8 ;
T_1 V_156 ;
T_7 V_155 ;
T_6 V_108 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_282 = V_291 -> V_282 ;
if ( ! F_76 ( V_3 , V_282 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_295 ;
}
if ( V_3 -> V_112 [ V_282 ] &
V_113 ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 ,
V_282 ) ;
return - V_176 ;
}
if ( V_291 -> V_296 % 4 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_110 ) ;
return - V_176 ;
}
V_8 = F_78 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_275 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_292 = V_3 -> V_297 [ V_282 ] ;
V_294 = V_291 -> V_296 ;
V_3 -> V_298 [ V_282 ] = V_291 -> V_298 ;
V_3 -> V_112 [ V_282 ] = 0 ;
memcpy ( V_3 -> V_299 [ V_282 ] ,
V_291 -> V_299 , V_300 ) ;
V_3 -> V_301 [ V_282 ] = V_291 -> V_301 ;
if ( V_292 ) {
V_293 = V_3 -> V_302 [ V_282 ] ;
if ( V_294 != V_3 -> V_303 [ V_282 ] ) {
F_60 ( V_3 -> V_183 ,
V_3 -> V_303 [ V_282 ] ,
V_292 , V_293 ) ;
V_292 = NULL ;
}
}
if ( V_292 == NULL ) {
V_3 -> V_303 [ V_282 ] = 0 ;
V_3 -> V_302 [ V_282 ] = 0 ;
V_292 = F_45 (
V_3 -> V_183 , V_294 , & V_293 ) ;
if ( V_292 == NULL ) {
F_37 ( V_45 L_55 \
L_56 ,
V_3 -> V_46 , V_110 , V_294 ) ;
F_27 ( V_3 , V_8 ) ;
return - V_173 ;
}
V_3 -> V_297 [ V_282 ] = V_292 ;
V_3 -> V_303 [ V_282 ] = V_294 ;
V_3 -> V_302 [ V_282 ] = V_293 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_304 = V_291 -> V_282 ;
V_11 -> V_305 = F_79 ( V_291 -> V_301 ) ;
V_11 -> V_306 = F_80 ( V_293 ) ;
V_11 -> V_307 = F_79 ( V_294 ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_57 ,
V_3 -> V_46 , V_110 , V_292 ,
( unsigned long long ) V_293 ,
F_7 ( V_11 -> V_307 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_300 ; V_77 ++ )
V_11 -> V_308 [ V_77 ] =
F_79 ( V_3 -> V_299 [ V_282 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_158 = F_53 ( & V_3 -> V_64 . V_75 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_156 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_156 == V_309 ) {
V_3 -> V_112 [ V_282 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_156 , F_7 ( V_10 -> V_48 ) ) ;
V_275 = - V_170 ;
}
V_208:
if ( V_108 )
F_59 ( V_3 , V_218 ,
V_219 ) ;
V_7:
if ( V_275 && V_292 )
F_60 ( V_3 -> V_183 , V_294 ,
V_292 , V_293 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_275 ;
}
void
F_81 ( struct V_2 * V_3 , T_6 V_310 )
{
struct V_290 V_291 ;
memset ( & V_291 , 0 , sizeof( struct V_290 ) ) ;
if ( V_310 & 1 ) {
F_6 ( V_45 L_61 ,
V_3 -> V_46 ) ;
V_3 -> V_311 . V_312 =
( V_313 + V_314 ) ;
V_291 . V_282 = V_283 ;
V_291 . V_296 = 2 * ( 1024 * 1024 ) ;
V_291 . V_298 = 0x7075900 ;
F_77 ( V_3 , & V_291 ) ;
}
if ( V_310 & 2 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_291 . V_282 = V_286 ;
V_291 . V_296 = 2 * ( 1024 * 1024 ) ;
V_291 . V_298 = 0x7075901 ;
F_77 ( V_3 , & V_291 ) ;
}
if ( V_310 & 4 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_291 . V_282 = V_288 ;
V_291 . V_296 = 2 * ( 1024 * 1024 ) ;
V_291 . V_298 = 0x7075901 ;
F_77 ( V_3 , & V_291 ) ;
}
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_290 V_127 ;
long V_275 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
V_275 = F_77 ( V_3 , & V_127 ) ;
return V_275 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_315 V_127 ;
void * V_292 ;
T_14 V_293 ;
T_7 V_294 ;
T_6 V_282 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_282 = V_127 . V_298 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_282 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_295 ;
}
if ( ( V_3 -> V_112 [ V_282 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_176 ;
}
if ( ( V_3 -> V_112 [ V_282 ] &
V_114 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_176 ;
}
if ( V_127 . V_298 != V_3 -> V_298 [ V_282 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_298 ) ;
return - V_176 ;
}
V_292 = V_3 -> V_297 [ V_282 ] ;
if ( ! V_292 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_173 ;
}
V_294 = V_3 -> V_303 [ V_282 ] ;
V_293 = V_3 -> V_302 [ V_282 ] ;
F_60 ( V_3 -> V_183 , V_294 ,
V_292 , V_293 ) ;
V_3 -> V_297 [ V_282 ] = NULL ;
V_3 -> V_112 [ V_282 ] = 0 ;
return 0 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_316 V_127 ;
void * V_292 ;
int V_77 ;
T_6 V_282 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_317 = 0 ;
V_282 = V_127 . V_282 ;
if ( ! F_76 ( V_3 , V_282 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_295 ;
}
if ( ( V_3 -> V_112 [ V_282 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_176 ;
}
if ( V_127 . V_298 & 0xffffff00 ) {
if ( V_127 . V_298 != V_3 -> V_298 [ V_282 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_298 ) ;
return - V_176 ;
}
}
V_292 = V_3 -> V_297 [ V_282 ] ;
if ( ! V_292 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_173 ;
}
if ( V_3 -> V_112 [ V_282 ] & V_114 )
V_127 . V_317 = ( V_318 |
V_319 ) ;
else
V_127 . V_317 = ( V_318 |
V_319 |
V_320 ) ;
for ( V_77 = 0 ; V_77 < V_300 ; V_77 ++ )
V_127 . V_299 [ V_77 ] =
V_3 -> V_299 [ V_282 ] [ V_77 ] ;
V_127 . V_321 = V_3 -> V_303 [ V_282 ] ;
V_127 . V_322 = 0 ;
V_127 . V_298 = V_3 -> V_298 [ V_282 ] ;
V_127 . V_301 = V_3 -> V_301 [ V_282 ] ;
if ( F_36 ( V_220 , & V_127 , sizeof( struct V_316 ) ) ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_220 ) ;
return - V_170 ;
}
return 0 ;
}
int
F_26 ( struct V_2 * V_3 , T_6 V_282 ,
T_6 * V_108 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_156 ;
T_7 V_155 ;
int V_275 ;
unsigned long V_158 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_275 = 0 ;
* V_108 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_169 ) {
if ( V_3 -> V_112 [ V_282 ] &
V_113 )
V_3 -> V_112 [ V_282 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45
L_70 , V_3 -> V_46 ,
V_110 ) ) ;
V_275 = - V_168 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_304 = V_282 ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_158 = F_53 ( & V_3 -> V_64 . V_75 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
* V_108 = 1 ;
V_275 = - V_170 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_156 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_156 == V_309 ) {
V_3 -> V_112 [ V_282 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_156 , F_7 ( V_10 -> V_48 ) ) ;
V_275 = - V_170 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_275 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_323 V_127 ;
void * V_292 ;
int V_275 ;
T_6 V_282 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_282 = V_127 . V_298 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_282 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_295 ;
}
if ( ( V_3 -> V_112 [ V_282 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_176 ;
}
if ( V_127 . V_298 != V_3 -> V_298 [ V_282 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_298 ) ;
return - V_176 ;
}
if ( V_3 -> V_112 [ V_282 ] &
V_114 ) {
F_37 ( V_45
L_71 ,
V_3 -> V_46 , V_110 ,
V_282 ) ;
return 0 ;
}
V_292 = V_3 -> V_297 [ V_282 ] ;
if ( ! V_292 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_173 ;
}
if ( ( V_3 -> V_112 [ V_282 ] &
V_118 ) ) {
V_3 -> V_112 [ V_282 ] |=
V_114 ;
V_3 -> V_112 [ V_282 ] &=
~ V_118 ;
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return 0 ;
}
V_275 = F_26 ( V_3 , V_282 , & V_108 ) ;
if ( V_108 )
F_59 ( V_3 , V_218 ,
V_219 ) ;
return V_275 ;
}
static long
F_86 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_324 V_127 ;
struct V_324 T_12 * V_263 = V_220 ;
void * V_292 , * V_325 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_275 , V_77 ;
T_6 V_282 ;
unsigned long V_158 , V_326 , V_327 ;
T_1 V_8 ;
T_1 V_156 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_282 = V_127 . V_298 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_282 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_295 ;
}
if ( V_127 . V_298 != V_3 -> V_298 [ V_282 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_298 ) ;
return - V_176 ;
}
V_292 = V_3 -> V_297 [ V_282 ] ;
if ( ! V_292 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_282 ) ;
return - V_173 ;
}
V_326 = V_3 -> V_303 [ V_282 ] ;
if ( ( V_127 . V_328 % 4 ) || ( V_127 . V_329 % 4 ) ) {
F_37 ( V_45 L_73 \
L_74 , V_3 -> V_46 ,
V_110 ) ;
return - V_176 ;
}
if ( V_127 . V_328 > V_326 )
return - V_176 ;
V_325 = ( void * ) ( V_292 + V_127 . V_328 ) ;
F_35 ( V_3 , F_6 ( V_45
L_75 ,
V_3 -> V_46 , V_110 ,
V_325 , V_127 . V_328 , V_127 . V_329 ) ) ;
if ( ( V_325 + V_127 . V_329 < V_325 ) ||
( V_325 + V_127 . V_329 > V_292 + V_326 ) )
V_327 = V_326 - V_127 . V_328 ;
else
V_327 = V_127 . V_329 ;
if ( F_36 ( ( void T_12 * ) V_263 -> V_330 ,
V_325 , V_327 ) ) {
F_37 ( V_45
L_76 ,
V_3 -> V_46 , V_110 , V_325 ) ;
return - V_170 ;
}
if ( ( V_127 . V_50 & V_331 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_77 ,
V_3 -> V_46 , V_110 , V_282 ) ) ;
if ( ( V_3 -> V_112 [ V_282 ] &
V_114 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_110 , V_282 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_177 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_168 ;
goto V_7;
}
V_275 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_304 = V_282 ;
V_11 -> V_307 =
F_79 ( V_3 -> V_303 [ V_282 ] ) ;
V_11 -> V_306 =
F_80 ( V_3 -> V_302 [ V_282 ] ) ;
for ( V_77 = 0 ; V_77 < V_300 ; V_77 ++ )
V_11 -> V_308 [ V_77 ] =
F_79 ( V_3 -> V_299 [ V_282 ] [ V_77 ] ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_158 = F_53 ( & V_3 -> V_64 . V_75 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_275 = - V_170 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_156 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_156 == V_309 ) {
V_3 -> V_112 [ V_282 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_156 , F_7 ( V_10 -> V_48 ) ) ;
V_275 = - V_170 ;
}
V_208:
if ( V_108 )
F_59 ( V_3 , V_218 ,
V_219 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_275 ;
}
static long
F_87 ( struct V_2 * V_3 , unsigned V_332 ,
void T_12 * V_220 )
{
struct V_333 V_334 ;
struct V_333 T_12 * V_263 ;
struct V_126 V_127 ;
if ( F_88 ( V_332 ) != sizeof( struct V_333 ) )
return - V_176 ;
V_263 = (struct V_333 T_12 * ) V_220 ;
if ( F_42 ( & V_334 , ( char T_12 * ) V_220 , sizeof( V_334 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 . V_264 . V_98 = V_334 . V_264 . V_98 ;
V_127 . V_264 . V_223 = V_334 . V_264 . V_223 ;
V_127 . V_264 . V_265 = V_334 . V_264 . V_265 ;
V_127 . V_157 = V_334 . V_157 ;
V_127 . V_150 = V_334 . V_150 ;
V_127 . V_179 = V_334 . V_179 ;
V_127 . V_178 = V_334 . V_178 ;
V_127 . V_214 = V_334 . V_214 ;
V_127 . V_174 = V_334 . V_174 ;
V_127 . V_152 = F_89 ( V_334 . V_152 ) ;
V_127 . V_212 = F_89 ( V_334 . V_212 ) ;
V_127 . V_184 = F_89 ( V_334 . V_184 ) ;
V_127 . V_215 = F_89 ( V_334 . V_215 ) ;
return F_38 ( V_3 , V_127 , & V_263 -> V_153 ) ;
}
static long
F_90 ( struct V_120 * V_120 , unsigned int V_332 , void T_12 * V_220 ,
T_6 V_335 , T_1 V_100 )
{
struct V_2 * V_3 ;
struct V_266 V_336 ;
enum V_337 V_338 ;
long V_166 = - V_176 ;
if ( F_42 ( & V_336 , ( char T_12 * ) V_220 ,
sizeof( struct V_266 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_170 ;
}
if ( F_21 ( V_336 . V_98 ,
& V_3 , V_100 ) == - 1 || ! V_3 )
return - V_339 ;
F_91 ( & V_3 -> V_340 ) ;
if ( V_3 -> V_270 || V_3 -> V_271 ||
V_3 -> V_272 || V_3 -> V_341 ) {
V_166 = - V_168 ;
goto V_342;
}
V_338 = ( V_120 -> V_343 & V_344 ) ? V_345 : V_346 ;
if ( V_338 == V_345 ) {
if ( ! F_92 ( & V_3 -> V_64 . V_347 ) ) {
V_166 = - V_168 ;
goto V_342;
}
} else if ( F_93 ( & V_3 -> V_64 . V_347 ) ) {
V_166 = - V_348 ;
goto V_342;
}
switch ( V_332 ) {
case V_349 :
if ( F_88 ( V_332 ) == sizeof( struct V_221 ) )
V_166 = F_62 ( V_3 , V_220 ) ;
break;
#ifdef F_94
case V_350 :
#endif
case V_351 :
{
struct V_126 T_12 * V_263 ;
struct V_126 V_127 ;
#ifdef F_94
if ( V_335 ) {
V_166 = F_87 ( V_3 , V_332 , V_220 ) ;
break;
}
#endif
if ( F_42 ( & V_127 , V_220 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
V_166 = - V_170 ;
break;
}
if ( F_88 ( V_332 ) == sizeof( struct V_126 ) ) {
V_263 = V_220 ;
V_166 = F_38 ( V_3 , V_127 , & V_263 -> V_153 ) ;
}
break;
}
case V_352 :
if ( F_88 ( V_332 ) == sizeof( struct V_254 ) )
V_166 = F_66 ( V_3 , V_220 ) ;
break;
case V_353 :
if ( F_88 ( V_332 ) == sizeof( struct V_258 ) )
V_166 = F_67 ( V_3 , V_220 ) ;
break;
case V_354 :
V_166 = F_70 ( V_3 , V_220 ) ;
break;
case V_355 :
if ( F_88 ( V_332 ) == sizeof( struct V_268 ) )
V_166 = F_71 ( V_3 , V_220 ) ;
break;
case V_356 :
if ( F_88 ( V_332 ) == sizeof( struct V_273 ) )
V_166 = F_75 ( V_3 , V_220 ) ;
break;
case V_357 :
if ( F_88 ( V_332 ) == sizeof( struct V_290 ) )
V_166 = F_82 ( V_3 , V_220 ) ;
break;
case V_358 :
if ( F_88 ( V_332 ) == sizeof( struct V_315 ) )
V_166 = F_83 ( V_3 , V_220 ) ;
break;
case V_359 :
if ( F_88 ( V_332 ) == sizeof( struct V_316 ) )
V_166 = F_84 ( V_3 , V_220 ) ;
break;
case V_360 :
if ( F_88 ( V_332 ) == sizeof( struct V_323 ) )
V_166 = F_85 ( V_3 , V_220 ) ;
break;
case V_361 :
if ( F_88 ( V_332 ) == sizeof( struct V_324 ) )
V_166 = F_86 ( V_3 , V_220 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_79 , V_3 -> V_46 , V_332 ) ) ;
break;
}
F_95 ( & V_3 -> V_64 . V_347 ) ;
V_342:
F_95 ( & V_3 -> V_340 ) ;
return V_166 ;
}
long
F_96 ( struct V_120 * V_120 , unsigned int V_332 , unsigned long V_220 )
{
long V_166 ;
V_166 = F_90 ( V_120 , V_332 , ( void T_12 * ) V_220 , 0 ,
V_105 | V_106 ) ;
return V_166 ;
}
long
F_97 ( struct V_120 * V_120 , unsigned int V_332 , unsigned long V_220 )
{
long V_166 ;
V_166 = F_90 ( V_120 , V_332 , ( void T_12 * ) V_220 , 0 , V_243 ) ;
return V_166 ;
}
long
F_98 ( struct V_120 * V_120 , unsigned V_332 , unsigned long V_220 )
{
long V_166 ;
V_166 = F_90 ( V_120 , V_332 , ( void T_12 * ) V_220 , 1 ,
V_105 | V_106 ) ;
return V_166 ;
}
long
F_99 ( struct V_120 * V_120 , unsigned V_332 , unsigned long V_220 )
{
long V_166 ;
V_166 = F_90 ( V_120 , V_332 , ( void T_12 * ) V_220 , 1 , V_243 ) ;
return V_166 ;
}
static T_23
F_100 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_80 ,
( V_3 -> V_181 . V_239 . V_240 & 0xFF000000 ) >> 24 ,
( V_3 -> V_181 . V_239 . V_240 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_181 . V_239 . V_240 & 0x0000FF00 ) >> 8 ,
V_3 -> V_181 . V_239 . V_240 & 0x000000FF ) ;
}
static T_23
F_103 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
T_7 V_101 = F_7 ( V_3 -> V_252 . V_253 ) ;
return snprintf ( V_365 , V_368 , L_80 ,
( V_101 & 0xFF000000 ) >> 24 ,
( V_101 & 0x00FF0000 ) >> 16 ,
( V_101 & 0x0000FF00 ) >> 8 ,
V_101 & 0x000000FF ) ;
}
static T_23
F_104 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_81 ,
V_3 -> V_181 . V_369 , V_3 -> V_181 . V_370 >> 8 ) ;
}
static T_23
F_105 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , 16 , L_51 , V_3 -> V_371 . V_372 ) ;
}
static T_23
F_106 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_82 ,
F_7 ( V_3 -> V_373 . V_374 . V_240 ) ) ;
}
static T_23
F_107 ( struct V_144 * V_362 , struct V_363
* V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_82 ,
F_7 ( V_3 -> V_373 . V_375 . V_240 ) ) ;
}
static T_23
F_108 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , 16 , L_51 , V_3 -> V_371 . V_376 ) ;
}
static T_23
F_109 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , 16 , L_51 , V_3 -> V_371 . V_377 ) ;
}
static T_23
F_110 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , 16 , L_51 , V_3 -> V_371 . V_378 ) ;
}
static T_23
F_111 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_83 , V_3 -> V_379 ) ;
}
static T_23
F_112 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_83 , V_3 -> V_380 ) ;
}
static T_23
F_113 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_83 , V_3 -> V_181 . V_381 ) ;
}
static T_23
F_114 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_84 ,
( unsigned long long ) V_3 -> V_382 . V_53 ) ;
}
static T_23
F_115 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_82 , V_3 -> V_13 ) ;
}
static T_23
F_116 ( struct V_144 * V_362 , struct V_363 * V_364 ,
const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
int V_384 = 0 ;
if ( sscanf ( V_365 , L_85 , & V_384 ) != 1 )
return - V_176 ;
V_3 -> V_13 = V_384 ;
F_6 ( V_45 L_86 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_365 ) ;
}
static T_23
F_117 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_87 , V_3 -> V_385 ) ;
}
static T_23
F_118 ( struct V_144 * V_362 , struct V_363 * V_364 ,
const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
int V_384 = 0 ;
if ( sscanf ( V_365 , L_88 , & V_384 ) != 1 )
return - V_176 ;
V_3 -> V_385 = V_384 ;
F_6 ( V_45 L_89 , V_3 -> V_46 ,
V_3 -> V_385 ) ;
return strlen ( V_365 ) ;
}
static T_23
F_119 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
return snprintf ( V_365 , V_368 , L_87 , V_3 -> V_386 ) ;
}
static T_23
F_120 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
T_6 V_387 ;
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
if ( ( V_3 -> V_181 . V_284 &
V_388 ) && V_3 -> V_389 )
V_387 = V_3 -> V_387 ;
else
V_387 = 1 ;
return snprintf ( V_365 , V_368 , L_87 , V_387 ) ;
}
static T_23
F_121 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
T_24 * V_390 = NULL ;
T_25 V_10 ;
T_1 V_391 = 0 ;
T_1 V_156 ;
int V_63 ;
T_23 V_275 = 0 ;
if ( ! V_3 -> V_244 ) {
F_37 ( V_45 L_90
L_91 , V_3 -> V_46 , V_110 ) ;
goto V_7;
}
F_91 ( & V_3 -> V_340 ) ;
if ( V_3 -> V_271 || V_3 -> V_341 ) {
F_95 ( & V_3 -> V_340 ) ;
return 0 ;
}
V_63 = F_122 ( T_24 , V_392 ) + ( sizeof( T_1 ) * 36 ) ;
V_390 = F_41 ( V_63 , V_172 ) ;
if ( ! V_390 ) {
F_37 ( V_45 L_92
L_93 , V_3 -> V_46 , V_110 , V_63 ) ;
goto V_7;
}
if ( F_123 ( V_3 , & V_10 , V_390 , V_63 ) !=
0 ) {
F_37 ( V_45
L_94 , V_3 -> V_46 ,
V_110 ) ;
goto V_7;
}
V_156 = F_5 ( V_10 . V_47 ) & V_209 ;
if ( V_156 != V_309 ) {
F_37 ( V_45 L_95
L_96 , V_3 -> V_46 , V_110 , V_156 ) ;
goto V_7;
}
if ( V_390 -> V_393 < 25 ) {
F_37 ( V_45 L_97
L_98 , V_3 -> V_46 , V_110 ,
V_390 -> V_393 ) ;
goto V_7;
}
V_391 = F_5 ( V_390 -> V_392 [ 24 ] ) ;
V_275 = snprintf ( V_365 , V_368 , L_87 , ( V_391 & 1 ) ) ;
V_7:
F_61 ( V_390 ) ;
F_95 ( & V_3 -> V_340 ) ;
return V_275 ;
}
static T_23
F_124 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
T_7 V_394 = 0 ;
struct V_395 * V_292 ;
if ( ! V_3 -> V_297 [ V_283 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_283 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
V_292 = (struct V_395 * )
V_3 -> V_297 [ V_283 ] ;
if ( ( F_7 ( V_292 -> V_396 ) == 0x00000000 ||
F_7 ( V_292 -> V_396 ) == 0x01000000 ||
F_7 ( V_292 -> V_396 ) == 0x01010000 ) &&
F_7 ( V_292 -> V_397 ) == 0x4742444c )
V_394 = F_7 ( V_292 -> V_398 ) ;
V_3 -> V_399 = V_394 ;
return snprintf ( V_365 , V_368 , L_87 , V_394 ) ;
}
static T_23
F_125 ( struct V_144 * V_362 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
void * V_292 ;
T_7 V_394 ;
if ( ! V_3 -> V_297 [ V_283 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_283 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( V_3 -> V_400 > V_3 -> V_399 )
return 0 ;
V_394 = V_3 -> V_399 - V_3 -> V_400 ;
V_394 = ( V_394 >= V_368 ) ? ( V_368 - 1 ) : V_394 ;
V_292 = V_3 -> V_297 [ 0 ] + V_3 -> V_400 ;
memcpy ( V_365 , V_292 , V_394 ) ;
return V_394 ;
}
static T_23
F_126 ( struct V_144 * V_362 , struct V_363 * V_364 ,
const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
int V_384 = 0 ;
if ( sscanf ( V_365 , L_88 , & V_384 ) != 1 )
return - V_176 ;
V_3 -> V_400 = V_384 ;
return strlen ( V_365 ) ;
}
static T_23
F_127 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
if ( ( ! V_3 -> V_297 [ V_283 ] ) ||
( ( V_3 -> V_112 [ V_283 ] &
V_113 ) == 0 ) )
return snprintf ( V_365 , V_368 , L_100 ) ;
else if ( ( V_3 -> V_112 [ V_283 ] &
V_114 ) )
return snprintf ( V_365 , V_368 , L_101 ) ;
else
return snprintf ( V_365 , V_368 , L_102 ) ;
}
static T_23
F_128 ( struct V_144 * V_362 ,
struct V_363 * V_364 , const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
char V_401 [ 10 ] = L_103 ;
struct V_290 V_291 ;
T_6 V_108 = 0 ;
if ( V_3 -> V_270 || V_3 -> V_341 ||
V_3 -> V_271 || V_3 -> V_272 )
return - V_402 ;
if ( sscanf ( V_365 , L_104 , V_401 ) != 1 )
return - V_176 ;
if ( ! strcmp ( V_401 , L_105 ) ) {
if ( ( V_3 -> V_297 [ V_283 ] ) &&
( V_3 -> V_112 [ V_283 ] &
V_113 ) &&
( ( V_3 -> V_112 [ V_283 ] &
V_114 ) == 0 ) )
goto V_7;
memset ( & V_291 , 0 , sizeof( struct V_290 ) ) ;
F_6 ( V_45 L_106 ,
V_3 -> V_46 ) ;
V_291 . V_282 = V_283 ;
V_291 . V_296 = ( 1024 * 1024 ) ;
V_291 . V_298 = 0x7075900 ;
V_3 -> V_112 [ V_283 ] = 0 ;
F_77 ( V_3 , & V_291 ) ;
} else if ( ! strcmp ( V_401 , L_107 ) ) {
if ( ! V_3 -> V_297 [ V_283 ] )
goto V_7;
if ( ( V_3 -> V_112 [ V_283 ] &
V_113 ) == 0 )
goto V_7;
if ( ( V_3 -> V_112 [ V_283 ] &
V_114 ) )
goto V_7;
F_6 ( V_45 L_108 ,
V_3 -> V_46 ) ;
F_26 ( V_3 , V_283 ,
& V_108 ) ;
}
V_7:
return strlen ( V_365 ) ;
}
static T_23
F_129 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_275 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_275 = sizeof( struct V_404 ) ;
memcpy ( V_365 , & V_3 -> V_311 , V_275 ) ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_275 ;
}
static T_23
F_130 ( struct V_144 * V_362 ,
struct V_363 * V_364 , const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_275 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_275 = F_131 ( sizeof( struct V_404 ) , V_383 ) ;
memset ( & V_3 -> V_311 , 0 ,
sizeof( struct V_404 ) ) ;
memcpy ( & V_3 -> V_311 , V_365 , V_275 ) ;
V_3 -> V_311 . V_312 |=
( V_313 + V_314 ) ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_275 ;
}
static T_23
F_132 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_275 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_275 = sizeof( struct V_405 ) ;
memcpy ( V_365 , & V_3 -> V_406 , V_275 ) ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_275 ;
}
static T_23
F_133 ( struct V_144 * V_362 ,
struct V_363 * V_364 , const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_405 ) , V_383 ) ;
memset ( & V_3 -> V_406 , 0 ,
sizeof( struct V_405 ) ) ;
memcpy ( & V_3 -> V_406 , V_365 , V_63 ) ;
if ( V_3 -> V_406 . V_407 > V_408 )
V_3 -> V_406 . V_407 = V_408 ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_63 ;
}
static T_23
F_134 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_275 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_275 = sizeof( struct V_409 ) ;
memcpy ( V_365 , & V_3 -> V_410 , V_275 ) ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_275 ;
}
static T_23
F_135 ( struct V_144 * V_362 ,
struct V_363 * V_364 , const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_409 ) , V_383 ) ;
memset ( & V_3 -> V_410 , 0 ,
sizeof( struct V_405 ) ) ;
memcpy ( & V_3 -> V_410 , V_365 , V_63 ) ;
if ( V_3 -> V_410 . V_407 > V_408 )
V_3 -> V_410 . V_407 = V_408 ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_63 ;
}
static T_23
F_136 ( struct V_144 * V_362 ,
struct V_363 * V_364 , char * V_365 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_275 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_275 = sizeof( struct V_411 ) ;
memcpy ( V_365 , & V_3 -> V_412 , V_275 ) ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_275 ;
}
static T_23
F_137 ( struct V_144 * V_362 ,
struct V_363 * V_364 , const char * V_365 , T_15 V_383 )
{
struct V_366 * V_367 = F_101 ( V_362 ) ;
struct V_2 * V_3 = F_102 ( V_367 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_403 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_411 ) , V_383 ) ;
memset ( & V_3 -> V_412 , 0 ,
sizeof( V_3 -> V_412 ) ) ;
memcpy ( & V_3 -> V_412 , V_365 , V_63 ) ;
if ( V_3 -> V_412 . V_407 > V_408 )
V_3 -> V_412 . V_407 = V_408 ;
F_10 ( & V_3 -> V_403 , V_50 ) ;
return V_63 ;
}
static T_23
F_138 ( struct V_144 * V_413 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_414 * V_415 = F_139 ( V_413 ) ;
struct V_132 * V_416 = V_415 -> V_145 ;
return snprintf ( V_365 , V_368 , L_84 ,
( unsigned long long ) V_416 -> V_146 -> V_53 ) ;
}
static T_23
F_140 ( struct V_144 * V_413 , struct V_363 * V_364 ,
char * V_365 )
{
struct V_414 * V_415 = F_139 ( V_413 ) ;
struct V_132 * V_416 = V_415 -> V_145 ;
return snprintf ( V_365 , V_368 , L_109 ,
V_416 -> V_146 -> V_4 ) ;
}
void
F_141 ( T_26 V_417 )
{
V_95 = NULL ;
if ( V_417 != 1 )
if ( F_142 ( & V_418 ) < 0 )
F_37 ( L_110 ,
V_419 , V_420 ) ;
if ( V_417 != 2 )
if ( F_142 ( & V_421 ) < 0 )
F_37 ( L_110 ,
V_422 , V_423 ) ;
F_143 ( & V_94 ) ;
}
void
F_144 ( T_26 V_417 )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! V_3 -> V_297 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
F_60 ( V_3 -> V_183 , V_3 -> V_303 [ V_77 ] ,
V_3 -> V_297 [ V_77 ] , V_3 -> V_302 [ V_77 ] ) ;
V_3 -> V_297 [ V_77 ] = NULL ;
V_3 -> V_112 [ V_77 ] = 0 ;
}
F_61 ( V_3 -> V_79 ) ;
}
if ( V_417 != 1 )
F_145 ( & V_418 ) ;
if ( V_417 != 2 )
F_145 ( & V_421 ) ;
}
