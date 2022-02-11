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
V_108 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_166 ;
goto V_7;
}
V_165 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
while ( V_155 != V_167 ) {
if ( V_165 ++ == 10 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_168 ;
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
V_11 = F_41 ( V_3 -> V_169 , V_170 ) ;
if ( ! V_11 ) {
F_37 ( V_45
L_37 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_171 ;
goto V_7;
}
if ( V_127 . V_172 * 4 > V_3 -> V_169 ||
V_127 . V_172 > ( V_173 / 4 ) ) {
V_164 = - V_174 ;
goto V_7;
}
if ( F_42 ( V_11 , V_153 , V_127 . V_172 * 4 ) ) {
F_37 ( L_31 , __FILE__ , __LINE__ ,
V_110 ) ;
V_164 = - V_168 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_166 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_175 , NULL ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_164 = - V_166 ;
goto V_7;
}
}
V_164 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_154 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_154 , V_11 , V_127 . V_172 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_160 = V_127 . V_176 ;
V_163 = V_127 . V_177 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_178 ) ||
F_5 ( V_11 -> V_178 ) >
V_3 -> V_179 . V_180 ) {
V_164 = - V_174 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_160 ) {
V_158 = F_45 ( V_3 -> V_181 , V_160 ,
& V_159 ) ;
if ( ! V_158 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_171 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_158 , V_127 . V_182 ,
V_160 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_168 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_163 ) {
V_161 = F_45 ( V_3 -> V_181 , V_163 ,
& V_162 ) ;
if ( ! V_161 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_171 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_157 = ( void * ) V_154 + ( V_127 . V_172 * 4 ) ;
F_3 ( V_3 , V_8 , L_39 , NULL ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_183 =
( T_4 * ) V_154 ;
V_183 -> V_184 = V_71 ;
V_183 -> V_185 =
F_47 ( V_3 , V_8 ) ;
memset ( V_3 -> V_64 . V_73 , 0 , V_71 ) ;
V_3 -> V_186 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
if ( V_11 -> V_15 == V_16 )
F_48 ( V_3 , V_8 ,
F_5 ( V_11 -> V_178 ) ) ;
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
V_3 -> V_187 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
F_51 ( V_3 , V_8 , 0 ) ;
break;
}
case V_44 :
{
T_16 * V_188 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_188 -> V_189 = 0xFF ;
if ( V_188 -> V_190 &
V_191 )
V_90 = ( T_6 * ) & V_188 -> V_192 ;
else {
if ( F_52 ( V_158 == NULL ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
F_27 ( V_3 , V_8 ) ;
V_164 = - V_174 ;
goto V_7;
}
V_90 = V_158 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_193 = 1 ;
V_3 -> V_194 = 1 ;
}
V_3 -> V_186 ( V_3 , V_157 , V_159 , V_160 , V_162 ,
V_163 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_41 :
case V_36 :
case V_37 :
{
V_3 -> V_186 ( V_3 , V_157 , V_159 , V_160 , V_162 ,
V_163 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_195 :
{
T_17 * V_196 =
( T_17 * ) V_11 ;
if ( V_196 -> V_197 == V_198 ) {
V_3 -> V_186 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
} else {
V_3 -> V_187 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
}
F_49 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_199 =
( T_18 * ) V_11 ;
if ( V_199 -> V_200 == V_201
|| V_199 -> V_200 ==
V_202 ) {
V_3 -> V_193 = 1 ;
V_3 -> V_194 = 1 ;
}
}
default:
V_3 -> V_187 ( V_3 , V_157 , V_159 , V_160 ,
V_162 , V_163 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
if ( V_127 . V_156 < V_203 )
V_156 = V_203 ;
else
V_156 = V_127 . V_156 ;
F_53 ( & V_3 -> V_64 . V_75 , V_156 * V_204 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_128 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_128 -> V_52 ) ) ;
F_55 ( V_3 , V_205 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_193 ) {
V_3 -> V_193 = 0 ;
V_3 -> V_194 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 , V_127 . V_172 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_206;
}
V_10 = V_3 -> V_64 . V_60 ;
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_207 ) ) {
T_11 * V_134 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_42 \
L_43
L_44 , V_3 -> V_46 ,
F_5 ( V_134 -> V_47 ) ,
F_7 ( V_134 -> V_48 ) ,
F_7 ( V_134 -> V_208 ) ) ;
}
if ( V_163 ) {
if ( F_36 ( V_127 . V_209 , V_161 ,
V_163 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_210 ;
goto V_7;
}
}
if ( V_127 . V_150 ) {
V_63 = F_13 ( T_7 , V_127 . V_150 , V_3 -> V_151 ) ;
if ( F_36 ( V_127 . V_152 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_210 ;
goto V_7;
}
}
if ( V_127 . V_211 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_127 . V_211 , V_71 ) ;
if ( F_36 ( V_127 . V_212 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_110 ) ;
V_164 = - V_210 ;
goto V_7;
}
}
V_206:
if ( V_108 ) {
V_164 = - V_210 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_45 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_178 ) ) ;
F_57 ( V_3 ) ;
F_58 ( V_3 ,
F_5 ( V_11 -> V_178 ) , 0 , 0 ,
0 , V_213 , 0 , 30 ) ;
} else
F_59 ( V_3 , V_214 ) ;
}
V_7:
if ( V_161 )
F_60 ( V_3 -> V_181 , V_163 , V_161 ,
V_162 ) ;
if ( V_158 )
F_60 ( V_3 -> V_181 , V_160 , V_158 ,
V_159 ) ;
F_61 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_164 ;
}
static long
F_62 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_216 V_127 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( V_3 -> V_217 )
V_127 . V_218 = V_3 -> V_217 [ 0 ] . V_219 ;
V_127 . V_220 = V_3 -> V_181 -> V_221 ;
V_127 . V_222 = V_3 -> V_181 -> V_144 ;
V_127 . V_223 = V_3 -> V_181 -> V_223 ;
V_127 . V_224 = V_3 -> V_181 -> V_224 ;
V_127 . V_225 . V_226 . V_227 . V_228 = V_3 -> V_181 -> V_228 -> V_229 ;
V_127 . V_225 . V_226 . V_227 . V_144 = F_63 ( V_3 -> V_181 -> V_230 ) ;
V_127 . V_225 . V_226 . V_227 . V_231 = F_64 ( V_3 -> V_181 -> V_230 ) ;
V_127 . V_225 . V_232 = F_65 ( V_3 -> V_181 -> V_228 ) ;
V_127 . V_233 = V_3 -> V_179 . V_234 . V_235 ;
strcpy ( V_127 . V_236 , V_3 -> V_237 ) ;
strcat ( V_127 . V_236 , L_47 ) ;
switch ( V_3 -> V_104 ) {
case V_238 :
if ( V_3 -> V_239 )
V_127 . V_240 = V_241 ;
else
V_127 . V_240 = V_242 ;
strcat ( V_127 . V_236 , V_243 ) ;
break;
case V_105 :
case V_106 :
V_127 . V_240 = V_244 ;
strcat ( V_127 . V_236 , V_245 ) ;
break;
}
V_127 . V_246 = F_7 ( V_3 -> V_247 . V_248 ) ;
if ( F_36 ( V_215 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_249 V_127 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_250 = V_86 ;
memcpy ( V_127 . V_251 , V_3 -> V_80 ,
V_252 * sizeof( T_7 ) ) ;
if ( F_36 ( V_215 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
return 0 ;
}
static long
F_67 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_253 V_127 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
memcpy ( V_3 -> V_80 , V_127 . V_251 ,
V_252 * sizeof( T_7 ) ) ;
F_68 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_69 ( V_86 ,
sizeof( struct V_81 ) , V_170 ) ;
if ( ! V_3 -> V_79 ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_171 ;
}
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_254 V_127 ;
T_7 V_255 , V_256 , V_257 ;
struct V_254 T_12 * V_258 = V_215 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_255 = V_127 . V_259 . V_260 -
sizeof( struct V_261 ) ;
V_256 = V_255 / sizeof( struct V_81 ) ;
V_257 = F_13 ( T_7 , V_86 , V_256 ) ;
if ( ! V_257 || ! V_3 -> V_79 )
return - V_210 ;
V_255 = V_257 * sizeof( struct V_81 ) ;
if ( F_36 ( V_258 -> V_262 , V_3 -> V_79 , V_255 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_71 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_263 V_127 ;
int V_264 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
if ( V_3 -> V_265 || V_3 -> V_266 ||
V_3 -> V_267 )
return - V_166 ;
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_110 ) ) ;
V_264 = F_59 ( V_3 , V_214 ) ;
F_6 ( V_45 L_48 ,
V_3 -> V_46 , ( ( ! V_264 ) ? L_49 : L_50 ) ) ;
return 0 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_268 * V_269 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_270 = 0 ;
if ( F_73 ( & V_3 -> V_271 ) )
return V_270 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_269 -> V_228 == 0xFFFFFFFF && V_269 -> V_103 == 0xFFFFFFFF &&
V_269 -> V_4 == V_5 -> V_4 ) {
V_269 -> V_228 = V_5 -> V_272 ;
V_269 -> V_103 = V_5 -> V_103 ;
V_270 = 1 ;
goto V_7;
} else if ( V_269 -> V_228 == V_5 -> V_272 && V_269 -> V_103 ==
V_5 -> V_103 && V_269 -> V_4 == 0xFFFF ) {
V_269 -> V_4 = V_5 -> V_4 ;
V_270 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_270 ;
}
static int
F_74 ( struct V_2 * V_3 ,
struct V_268 * V_269 )
{
struct V_273 * V_274 ;
unsigned long V_50 ;
int V_270 = 0 ;
if ( F_73 ( & V_3 -> V_275 ) )
return V_270 ;
F_8 ( & V_3 -> V_276 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_269 -> V_228 == 0xFFFFFFFF && V_269 -> V_103 == 0xFFFFFFFF &&
V_269 -> V_4 == V_274 -> V_4 ) {
V_269 -> V_228 = V_274 -> V_272 ;
V_269 -> V_103 = V_274 -> V_103 ;
V_270 = 1 ;
goto V_7;
} else if ( V_269 -> V_228 == V_274 -> V_272 && V_269 -> V_103 ==
V_274 -> V_103 && V_269 -> V_4 == 0xFFFF ) {
V_269 -> V_4 = V_274 -> V_4 ;
V_270 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_276 , V_50 ) ;
return V_270 ;
}
static long
F_75 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_268 V_127 ;
int V_270 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_270 = F_72 ( V_3 , & V_127 ) ;
if ( ! V_270 )
F_74 ( V_3 , & V_127 ) ;
if ( F_36 ( V_215 , & V_127 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
return 0 ;
}
static T_6
F_76 ( struct V_2 * V_3 , T_6 V_277 )
{
T_6 V_270 = 0 ;
switch ( V_277 ) {
case V_278 :
if ( V_3 -> V_179 . V_279 &
V_280 )
V_270 = 1 ;
break;
case V_281 :
if ( V_3 -> V_179 . V_279 &
V_282 )
V_270 = 1 ;
break;
case V_283 :
if ( V_3 -> V_179 . V_279 &
V_284 )
V_270 = 1 ;
}
return V_270 ;
}
static long
F_77 ( struct V_2 * V_3 ,
struct V_285 * V_286 )
{
int V_270 , V_77 ;
void * V_287 = NULL ;
T_14 V_288 ;
T_7 V_289 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_277 ;
T_1 V_8 ;
T_1 V_290 ;
T_7 V_155 ;
T_6 V_108 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_167 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_277 = V_286 -> V_277 ;
if ( ! F_76 ( V_3 , V_277 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_291 ;
}
if ( V_3 -> V_112 [ V_277 ] &
V_113 ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_110 ,
V_277 ) ;
return - V_174 ;
}
if ( V_286 -> V_292 % 4 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_110 ) ;
return - V_174 ;
}
V_8 = F_78 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_270 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_287 = V_3 -> V_293 [ V_277 ] ;
V_289 = V_286 -> V_292 ;
V_3 -> V_294 [ V_277 ] = V_286 -> V_294 ;
V_3 -> V_112 [ V_277 ] = 0 ;
memcpy ( V_3 -> V_295 [ V_277 ] ,
V_286 -> V_295 , V_296 ) ;
V_3 -> V_297 [ V_277 ] = V_286 -> V_297 ;
if ( V_287 ) {
V_288 = V_3 -> V_298 [ V_277 ] ;
if ( V_289 != V_3 -> V_299 [ V_277 ] ) {
F_60 ( V_3 -> V_181 ,
V_3 -> V_299 [ V_277 ] ,
V_287 , V_288 ) ;
V_287 = NULL ;
}
}
if ( V_287 == NULL ) {
V_3 -> V_299 [ V_277 ] = 0 ;
V_3 -> V_298 [ V_277 ] = 0 ;
V_287 = F_45 (
V_3 -> V_181 , V_289 , & V_288 ) ;
if ( V_287 == NULL ) {
F_37 ( V_45 L_55 \
L_56 ,
V_3 -> V_46 , V_110 , V_289 ) ;
F_27 ( V_3 , V_8 ) ;
return - V_171 ;
}
V_3 -> V_293 [ V_277 ] = V_287 ;
V_3 -> V_299 [ V_277 ] = V_289 ;
V_3 -> V_298 [ V_277 ] = V_288 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_300 = V_286 -> V_277 ;
V_11 -> V_301 = F_79 ( V_286 -> V_297 ) ;
V_11 -> V_302 = F_80 ( V_288 ) ;
V_11 -> V_303 = F_79 ( V_289 ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_57 ,
V_3 -> V_46 , V_110 , V_287 ,
( unsigned long long ) V_288 ,
F_7 ( V_11 -> V_303 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_296 ; V_77 ++ )
V_11 -> V_304 [ V_77 ] =
F_79 ( V_3 -> V_295 [ V_277 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
F_53 ( & V_3 -> V_64 . V_75 ,
V_203 * V_204 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_206;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_290 = F_5 ( V_10 -> V_47 ) & V_305 ;
if ( V_290 == V_306 ) {
V_3 -> V_112 [ V_277 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_290 , F_7 ( V_10 -> V_48 ) ) ;
V_270 = - V_168 ;
}
V_206:
if ( V_108 )
F_59 ( V_3 , V_214 ) ;
V_7:
if ( V_270 && V_287 )
F_60 ( V_3 -> V_181 , V_289 ,
V_287 , V_288 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_270 ;
}
void
F_81 ( struct V_2 * V_3 , T_6 V_307 )
{
struct V_285 V_286 ;
memset ( & V_286 , 0 , sizeof( struct V_285 ) ) ;
if ( V_307 & 1 ) {
F_6 ( V_45 L_61 ,
V_3 -> V_46 ) ;
V_3 -> V_308 . V_309 =
( V_310 + V_311 ) ;
V_286 . V_277 = V_278 ;
V_286 . V_292 = 2 * ( 1024 * 1024 ) ;
V_286 . V_294 = 0x7075900 ;
F_77 ( V_3 , & V_286 ) ;
}
if ( V_307 & 2 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_286 . V_277 = V_281 ;
V_286 . V_292 = 2 * ( 1024 * 1024 ) ;
V_286 . V_294 = 0x7075901 ;
F_77 ( V_3 , & V_286 ) ;
}
if ( V_307 & 4 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_286 . V_277 = V_283 ;
V_286 . V_292 = 2 * ( 1024 * 1024 ) ;
V_286 . V_294 = 0x7075901 ;
F_77 ( V_3 , & V_286 ) ;
}
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_285 V_127 ;
long V_270 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
V_270 = F_77 ( V_3 , & V_127 ) ;
return V_270 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_312 V_127 ;
void * V_287 ;
T_14 V_288 ;
T_7 V_289 ;
T_6 V_277 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_277 = V_127 . V_294 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_277 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_291 ;
}
if ( ( V_3 -> V_112 [ V_277 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_174 ;
}
if ( ( V_3 -> V_112 [ V_277 ] &
V_114 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_174 ;
}
if ( V_127 . V_294 != V_3 -> V_294 [ V_277 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_294 ) ;
return - V_174 ;
}
V_287 = V_3 -> V_293 [ V_277 ] ;
if ( ! V_287 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_171 ;
}
V_289 = V_3 -> V_299 [ V_277 ] ;
V_288 = V_3 -> V_298 [ V_277 ] ;
F_60 ( V_3 -> V_181 , V_289 ,
V_287 , V_288 ) ;
V_3 -> V_293 [ V_277 ] = NULL ;
V_3 -> V_112 [ V_277 ] = 0 ;
return 0 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_313 V_127 ;
void * V_287 ;
int V_77 ;
T_6 V_277 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_127 . V_314 = 0 ;
V_277 = V_127 . V_277 ;
if ( ! F_76 ( V_3 , V_277 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_291 ;
}
if ( ( V_3 -> V_112 [ V_277 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_174 ;
}
if ( V_127 . V_294 & 0xffffff00 ) {
if ( V_127 . V_294 != V_3 -> V_294 [ V_277 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_294 ) ;
return - V_174 ;
}
}
V_287 = V_3 -> V_293 [ V_277 ] ;
if ( ! V_287 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_171 ;
}
if ( V_3 -> V_112 [ V_277 ] & V_114 )
V_127 . V_314 = ( V_315 |
V_316 ) ;
else
V_127 . V_314 = ( V_315 |
V_316 |
V_317 ) ;
for ( V_77 = 0 ; V_77 < V_296 ; V_77 ++ )
V_127 . V_295 [ V_77 ] =
V_3 -> V_295 [ V_277 ] [ V_77 ] ;
V_127 . V_318 = V_3 -> V_299 [ V_277 ] ;
V_127 . V_319 = 0 ;
V_127 . V_294 = V_3 -> V_294 [ V_277 ] ;
V_127 . V_297 = V_3 -> V_297 [ V_277 ] ;
if ( F_36 ( V_215 , & V_127 , sizeof( struct V_313 ) ) ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_110 , V_215 ) ;
return - V_168 ;
}
return 0 ;
}
int
F_26 ( struct V_2 * V_3 , T_6 V_277 ,
T_6 * V_108 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_290 ;
T_7 V_155 ;
int V_270 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_270 = 0 ;
* V_108 = 0 ;
V_155 = F_39 ( V_3 , 1 ) ;
if ( V_155 != V_167 ) {
if ( V_3 -> V_112 [ V_277 ] &
V_113 )
V_3 -> V_112 [ V_277 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45
L_70 , V_3 -> V_46 ,
V_110 ) ) ;
V_270 = - V_166 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_300 = V_277 ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
F_53 ( & V_3 -> V_64 . V_75 ,
V_203 * V_204 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
* V_108 = 1 ;
V_270 = - V_168 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_290 = F_5 ( V_10 -> V_47 ) & V_305 ;
if ( V_290 == V_306 ) {
V_3 -> V_112 [ V_277 ] |=
V_114 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_290 , F_7 ( V_10 -> V_48 ) ) ;
V_270 = - V_168 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_270 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_320 V_127 ;
void * V_287 ;
int V_270 ;
T_6 V_277 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_277 = V_127 . V_294 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_277 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_291 ;
}
if ( ( V_3 -> V_112 [ V_277 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_174 ;
}
if ( V_127 . V_294 != V_3 -> V_294 [ V_277 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_294 ) ;
return - V_174 ;
}
if ( V_3 -> V_112 [ V_277 ] &
V_114 ) {
F_37 ( V_45
L_71 ,
V_3 -> V_46 , V_110 ,
V_277 ) ;
return 0 ;
}
V_287 = V_3 -> V_293 [ V_277 ] ;
if ( ! V_287 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_171 ;
}
if ( ( V_3 -> V_112 [ V_277 ] &
V_118 ) ) {
V_3 -> V_112 [ V_277 ] |=
V_114 ;
V_3 -> V_112 [ V_277 ] &=
~ V_118 ;
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return 0 ;
}
V_270 = F_26 ( V_3 , V_277 , & V_108 ) ;
if ( V_108 )
F_59 ( V_3 , V_214 ) ;
return V_270 ;
}
static long
F_86 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_321 V_127 ;
struct V_321 T_12 * V_258 = V_215 ;
void * V_287 , * V_322 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_270 , V_77 ;
T_6 V_277 ;
unsigned long V_323 , V_324 ;
T_1 V_8 ;
T_1 V_290 ;
T_6 V_108 = 0 ;
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_110 ) ) ;
V_277 = V_127 . V_294 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_277 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_291 ;
}
if ( V_127 . V_294 != V_3 -> V_294 [ V_277 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_110 , V_127 . V_294 ) ;
return - V_174 ;
}
V_287 = V_3 -> V_293 [ V_277 ] ;
if ( ! V_287 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_110 , V_277 ) ;
return - V_171 ;
}
V_323 = V_3 -> V_299 [ V_277 ] ;
if ( ( V_127 . V_325 % 4 ) || ( V_127 . V_326 % 4 ) ) {
F_37 ( V_45 L_73 \
L_74 , V_3 -> V_46 ,
V_110 ) ;
return - V_174 ;
}
if ( V_127 . V_325 > V_323 )
return - V_174 ;
V_322 = ( void * ) ( V_287 + V_127 . V_325 ) ;
F_35 ( V_3 , F_6 ( V_45
L_75 ,
V_3 -> V_46 , V_110 ,
V_322 , V_127 . V_325 , V_127 . V_326 ) ) ;
if ( ( V_322 + V_127 . V_326 < V_322 ) ||
( V_322 + V_127 . V_326 > V_287 + V_323 ) )
V_324 = V_323 - V_127 . V_325 ;
else
V_324 = V_127 . V_326 ;
if ( F_36 ( ( void T_12 * ) V_258 -> V_327 ,
V_322 , V_324 ) ) {
F_37 ( V_45
L_76 ,
V_3 -> V_46 , V_110 , V_322 ) ;
return - V_168 ;
}
if ( ( V_127 . V_50 & V_328 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_77 ,
V_3 -> V_46 , V_110 , V_277 ) ) ;
if ( ( V_3 -> V_112 [ V_277 ] &
V_114 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_110 , V_277 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_166 ;
goto V_7;
}
V_270 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_151 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_300 = V_277 ;
V_11 -> V_303 =
F_79 ( V_3 -> V_299 [ V_277 ] ) ;
V_11 -> V_302 =
F_80 ( V_3 -> V_298 [ V_277 ] ) ;
for ( V_77 = 0 ; V_77 < V_296 ; V_77 ++ )
V_11 -> V_304 [ V_77 ] =
F_79 ( V_3 -> V_295 [ V_277 ] [ V_77 ] ) ;
V_11 -> V_149 = 0 ;
V_11 -> V_148 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
F_53 ( & V_3 -> V_64 . V_75 ,
V_203 * V_204 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_110 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_116 ) )
V_108 = 1 ;
goto V_206;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_110 ) ;
V_270 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_290 = F_5 ( V_10 -> V_47 ) & V_305 ;
if ( V_290 == V_306 ) {
V_3 -> V_112 [ V_277 ] |=
V_113 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_110 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_110 ,
V_290 , F_7 ( V_10 -> V_48 ) ) ;
V_270 = - V_168 ;
}
V_206:
if ( V_108 )
F_59 ( V_3 , V_214 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_270 ;
}
static long
F_87 ( struct V_2 * V_3 , unsigned V_329 ,
void T_12 * V_215 )
{
struct V_330 V_331 ;
struct V_330 T_12 * V_258 ;
struct V_126 V_127 ;
if ( F_88 ( V_329 ) != sizeof( struct V_330 ) )
return - V_174 ;
V_258 = (struct V_330 T_12 * ) V_215 ;
if ( F_42 ( & V_331 , ( char T_12 * ) V_215 , sizeof( V_331 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 . V_259 . V_98 = V_331 . V_259 . V_98 ;
V_127 . V_259 . V_218 = V_331 . V_259 . V_218 ;
V_127 . V_259 . V_260 = V_331 . V_259 . V_260 ;
V_127 . V_156 = V_331 . V_156 ;
V_127 . V_150 = V_331 . V_150 ;
V_127 . V_177 = V_331 . V_177 ;
V_127 . V_176 = V_331 . V_176 ;
V_127 . V_211 = V_331 . V_211 ;
V_127 . V_172 = V_331 . V_172 ;
V_127 . V_152 = F_89 ( V_331 . V_152 ) ;
V_127 . V_209 = F_89 ( V_331 . V_209 ) ;
V_127 . V_182 = F_89 ( V_331 . V_182 ) ;
V_127 . V_212 = F_89 ( V_331 . V_212 ) ;
return F_38 ( V_3 , V_127 , & V_258 -> V_153 ) ;
}
static long
F_90 ( struct V_120 * V_120 , unsigned int V_329 , void T_12 * V_215 ,
T_6 V_332 , T_1 V_100 )
{
struct V_2 * V_3 ;
struct V_261 V_333 ;
enum V_334 V_335 ;
long V_164 = - V_174 ;
if ( F_42 ( & V_333 , ( char T_12 * ) V_215 ,
sizeof( struct V_261 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
return - V_168 ;
}
if ( F_21 ( V_333 . V_98 ,
& V_3 , V_100 ) == - 1 || ! V_3 )
return - V_336 ;
F_91 ( & V_3 -> V_337 ) ;
if ( V_3 -> V_265 || V_3 -> V_266 ||
V_3 -> V_267 || V_3 -> V_338 ) {
V_164 = - V_166 ;
goto V_339;
}
V_335 = ( V_120 -> V_340 & V_341 ) ? V_342 : V_343 ;
if ( V_335 == V_342 ) {
if ( ! F_92 ( & V_3 -> V_64 . V_344 ) ) {
V_164 = - V_166 ;
goto V_339;
}
} else if ( F_93 ( & V_3 -> V_64 . V_344 ) ) {
V_164 = - V_345 ;
goto V_339;
}
switch ( V_329 ) {
case V_346 :
if ( F_88 ( V_329 ) == sizeof( struct V_216 ) )
V_164 = F_62 ( V_3 , V_215 ) ;
break;
#ifdef F_94
case V_347 :
#endif
case V_348 :
{
struct V_126 T_12 * V_258 ;
struct V_126 V_127 ;
#ifdef F_94
if ( V_332 ) {
V_164 = F_87 ( V_3 , V_329 , V_215 ) ;
break;
}
#endif
if ( F_42 ( & V_127 , V_215 , sizeof( V_127 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_110 ) ;
V_164 = - V_168 ;
break;
}
if ( F_88 ( V_329 ) == sizeof( struct V_126 ) ) {
V_258 = V_215 ;
V_164 = F_38 ( V_3 , V_127 , & V_258 -> V_153 ) ;
}
break;
}
case V_349 :
if ( F_88 ( V_329 ) == sizeof( struct V_249 ) )
V_164 = F_66 ( V_3 , V_215 ) ;
break;
case V_350 :
if ( F_88 ( V_329 ) == sizeof( struct V_253 ) )
V_164 = F_67 ( V_3 , V_215 ) ;
break;
case V_351 :
V_164 = F_70 ( V_3 , V_215 ) ;
break;
case V_352 :
if ( F_88 ( V_329 ) == sizeof( struct V_263 ) )
V_164 = F_71 ( V_3 , V_215 ) ;
break;
case V_353 :
if ( F_88 ( V_329 ) == sizeof( struct V_268 ) )
V_164 = F_75 ( V_3 , V_215 ) ;
break;
case V_354 :
if ( F_88 ( V_329 ) == sizeof( struct V_285 ) )
V_164 = F_82 ( V_3 , V_215 ) ;
break;
case V_355 :
if ( F_88 ( V_329 ) == sizeof( struct V_312 ) )
V_164 = F_83 ( V_3 , V_215 ) ;
break;
case V_356 :
if ( F_88 ( V_329 ) == sizeof( struct V_313 ) )
V_164 = F_84 ( V_3 , V_215 ) ;
break;
case V_357 :
if ( F_88 ( V_329 ) == sizeof( struct V_320 ) )
V_164 = F_85 ( V_3 , V_215 ) ;
break;
case V_358 :
if ( F_88 ( V_329 ) == sizeof( struct V_321 ) )
V_164 = F_86 ( V_3 , V_215 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_79 , V_3 -> V_46 , V_329 ) ) ;
break;
}
F_95 ( & V_3 -> V_64 . V_344 ) ;
V_339:
F_95 ( & V_3 -> V_337 ) ;
return V_164 ;
}
static long
F_96 ( struct V_120 * V_120 , unsigned int V_329 , unsigned long V_215 )
{
long V_164 ;
V_164 = F_90 ( V_120 , V_329 , ( void T_12 * ) V_215 , 0 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_97 ( struct V_120 * V_120 , unsigned int V_329 , unsigned long V_215 )
{
long V_164 ;
V_164 = F_90 ( V_120 , V_329 , ( void T_12 * ) V_215 , 0 , V_238 ) ;
return V_164 ;
}
static long
F_98 ( struct V_120 * V_120 , unsigned V_329 , unsigned long V_215 )
{
long V_164 ;
V_164 = F_90 ( V_120 , V_329 , ( void T_12 * ) V_215 , 1 ,
V_105 | V_106 ) ;
return V_164 ;
}
static long
F_99 ( struct V_120 * V_120 , unsigned V_329 , unsigned long V_215 )
{
long V_164 ;
V_164 = F_90 ( V_120 , V_329 , ( void T_12 * ) V_215 , 1 , V_238 ) ;
return V_164 ;
}
static T_23
F_100 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_80 ,
( V_3 -> V_179 . V_234 . V_235 & 0xFF000000 ) >> 24 ,
( V_3 -> V_179 . V_234 . V_235 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_179 . V_234 . V_235 & 0x0000FF00 ) >> 8 ,
V_3 -> V_179 . V_234 . V_235 & 0x000000FF ) ;
}
static T_23
F_103 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
T_7 V_101 = F_7 ( V_3 -> V_247 . V_248 ) ;
return snprintf ( V_362 , V_365 , L_80 ,
( V_101 & 0xFF000000 ) >> 24 ,
( V_101 & 0x00FF0000 ) >> 16 ,
( V_101 & 0x0000FF00 ) >> 8 ,
V_101 & 0x000000FF ) ;
}
static T_23
F_104 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_81 ,
V_3 -> V_179 . V_366 , V_3 -> V_179 . V_367 >> 8 ) ;
}
static T_23
F_105 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , 16 , L_51 , V_3 -> V_368 . V_369 ) ;
}
static T_23
F_106 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_82 ,
F_7 ( V_3 -> V_370 . V_371 . V_235 ) ) ;
}
static T_23
F_107 ( struct V_144 * V_359 , struct V_360
* V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_82 ,
F_7 ( V_3 -> V_370 . V_372 . V_235 ) ) ;
}
static T_23
F_108 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , 16 , L_51 , V_3 -> V_368 . V_373 ) ;
}
static T_23
F_109 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , 16 , L_51 , V_3 -> V_368 . V_374 ) ;
}
static T_23
F_110 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , 16 , L_51 , V_3 -> V_368 . V_375 ) ;
}
static T_23
F_111 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_83 , V_3 -> V_376 ) ;
}
static T_23
F_112 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_83 , V_3 -> V_377 ) ;
}
static T_23
F_113 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_83 , V_3 -> V_179 . V_378 ) ;
}
static T_23
F_114 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_84 ,
( unsigned long long ) V_3 -> V_379 . V_53 ) ;
}
static T_23
F_115 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_82 , V_3 -> V_13 ) ;
}
static T_23
F_116 ( struct V_144 * V_359 , struct V_360 * V_361 ,
const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
int V_381 = 0 ;
if ( sscanf ( V_362 , L_85 , & V_381 ) != 1 )
return - V_174 ;
V_3 -> V_13 = V_381 ;
F_6 ( V_45 L_86 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_362 ) ;
}
static T_23
F_117 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_87 , V_3 -> V_382 ) ;
}
static T_23
F_118 ( struct V_144 * V_359 , struct V_360 * V_361 ,
const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
int V_381 = 0 ;
if ( sscanf ( V_362 , L_88 , & V_381 ) != 1 )
return - V_174 ;
V_3 -> V_382 = V_381 ;
F_6 ( V_45 L_89 , V_3 -> V_46 ,
V_3 -> V_382 ) ;
return strlen ( V_362 ) ;
}
static T_23
F_119 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
return snprintf ( V_362 , V_365 , L_87 , V_3 -> V_383 ) ;
}
static T_23
F_120 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
T_6 V_384 ;
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
if ( ( V_3 -> V_179 . V_279 &
V_385 ) && V_3 -> V_386 )
V_384 = V_3 -> V_384 ;
else
V_384 = 1 ;
return snprintf ( V_362 , V_365 , L_87 , V_384 ) ;
}
static T_23
F_121 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
T_24 * V_387 = NULL ;
T_25 V_10 ;
T_1 V_388 = 0 ;
T_1 V_290 ;
int V_63 ;
T_23 V_270 = 0 ;
if ( ! V_3 -> V_239 ) {
F_37 ( V_45 L_90
L_91 , V_3 -> V_46 , V_110 ) ;
goto V_7;
}
F_91 ( & V_3 -> V_337 ) ;
if ( V_3 -> V_266 || V_3 -> V_338 ) {
F_95 ( & V_3 -> V_337 ) ;
return 0 ;
}
V_63 = F_122 ( T_24 , V_389 ) + ( sizeof( T_1 ) * 36 ) ;
V_387 = F_41 ( V_63 , V_170 ) ;
if ( ! V_387 ) {
F_37 ( V_45 L_92
L_93 , V_3 -> V_46 , V_110 , V_63 ) ;
goto V_7;
}
if ( F_123 ( V_3 , & V_10 , V_387 , V_63 ) !=
0 ) {
F_37 ( V_45
L_94 , V_3 -> V_46 ,
V_110 ) ;
goto V_7;
}
V_290 = F_5 ( V_10 . V_47 ) & V_305 ;
if ( V_290 != V_306 ) {
F_37 ( V_45 L_95
L_96 , V_3 -> V_46 , V_110 , V_290 ) ;
goto V_7;
}
if ( V_387 -> V_390 < 25 ) {
F_37 ( V_45 L_97
L_98 , V_3 -> V_46 , V_110 ,
V_387 -> V_390 ) ;
goto V_7;
}
V_388 = F_5 ( V_387 -> V_389 [ 24 ] ) ;
V_270 = snprintf ( V_362 , V_365 , L_87 , ( V_388 & 1 ) ) ;
V_7:
F_61 ( V_387 ) ;
F_95 ( & V_3 -> V_337 ) ;
return V_270 ;
}
static T_23
F_124 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
T_7 V_391 = 0 ;
struct V_392 * V_287 ;
if ( ! V_3 -> V_293 [ V_278 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_278 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
V_287 = (struct V_392 * )
V_3 -> V_293 [ V_278 ] ;
if ( ( F_7 ( V_287 -> V_393 ) == 0x00000000 ||
F_7 ( V_287 -> V_393 ) == 0x01000000 ||
F_7 ( V_287 -> V_393 ) == 0x01010000 ) &&
F_7 ( V_287 -> V_394 ) == 0x4742444c )
V_391 = F_7 ( V_287 -> V_395 ) ;
V_3 -> V_396 = V_391 ;
return snprintf ( V_362 , V_365 , L_87 , V_391 ) ;
}
static T_23
F_125 ( struct V_144 * V_359 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
void * V_287 ;
T_7 V_391 ;
if ( ! V_3 -> V_293 [ V_278 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( ( V_3 -> V_112 [ V_278 ] &
V_113 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_110 ) ;
return 0 ;
}
if ( V_3 -> V_397 > V_3 -> V_396 )
return 0 ;
V_391 = V_3 -> V_396 - V_3 -> V_397 ;
V_391 = ( V_391 >= V_365 ) ? ( V_365 - 1 ) : V_391 ;
V_287 = V_3 -> V_293 [ 0 ] + V_3 -> V_397 ;
memcpy ( V_362 , V_287 , V_391 ) ;
return V_391 ;
}
static T_23
F_126 ( struct V_144 * V_359 , struct V_360 * V_361 ,
const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
int V_381 = 0 ;
if ( sscanf ( V_362 , L_88 , & V_381 ) != 1 )
return - V_174 ;
V_3 -> V_397 = V_381 ;
return strlen ( V_362 ) ;
}
static T_23
F_127 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
if ( ( ! V_3 -> V_293 [ V_278 ] ) ||
( ( V_3 -> V_112 [ V_278 ] &
V_113 ) == 0 ) )
return snprintf ( V_362 , V_365 , L_100 ) ;
else if ( ( V_3 -> V_112 [ V_278 ] &
V_114 ) )
return snprintf ( V_362 , V_365 , L_101 ) ;
else
return snprintf ( V_362 , V_365 , L_102 ) ;
}
static T_23
F_128 ( struct V_144 * V_359 ,
struct V_360 * V_361 , const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
char V_398 [ 10 ] = L_103 ;
struct V_285 V_286 ;
T_6 V_108 = 0 ;
if ( V_3 -> V_265 || V_3 -> V_338 ||
V_3 -> V_266 || V_3 -> V_267 )
return - V_399 ;
if ( sscanf ( V_362 , L_104 , V_398 ) != 1 )
return - V_174 ;
if ( ! strcmp ( V_398 , L_105 ) ) {
if ( ( V_3 -> V_293 [ V_278 ] ) &&
( V_3 -> V_112 [ V_278 ] &
V_113 ) &&
( ( V_3 -> V_112 [ V_278 ] &
V_114 ) == 0 ) )
goto V_7;
memset ( & V_286 , 0 , sizeof( struct V_285 ) ) ;
F_6 ( V_45 L_106 ,
V_3 -> V_46 ) ;
V_286 . V_277 = V_278 ;
V_286 . V_292 = ( 1024 * 1024 ) ;
V_286 . V_294 = 0x7075900 ;
V_3 -> V_112 [ V_278 ] = 0 ;
F_77 ( V_3 , & V_286 ) ;
} else if ( ! strcmp ( V_398 , L_107 ) ) {
if ( ! V_3 -> V_293 [ V_278 ] )
goto V_7;
if ( ( V_3 -> V_112 [ V_278 ] &
V_113 ) == 0 )
goto V_7;
if ( ( V_3 -> V_112 [ V_278 ] &
V_114 ) )
goto V_7;
F_6 ( V_45 L_108 ,
V_3 -> V_46 ) ;
F_26 ( V_3 , V_278 ,
& V_108 ) ;
}
V_7:
return strlen ( V_362 ) ;
}
static T_23
F_129 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_270 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_270 = sizeof( struct V_401 ) ;
memcpy ( V_362 , & V_3 -> V_308 , V_270 ) ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_270 ;
}
static T_23
F_130 ( struct V_144 * V_359 ,
struct V_360 * V_361 , const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_270 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_270 = F_131 ( sizeof( struct V_401 ) , V_380 ) ;
memset ( & V_3 -> V_308 , 0 ,
sizeof( struct V_401 ) ) ;
memcpy ( & V_3 -> V_308 , V_362 , V_270 ) ;
V_3 -> V_308 . V_309 |=
( V_310 + V_311 ) ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_270 ;
}
static T_23
F_132 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_270 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_270 = sizeof( struct V_402 ) ;
memcpy ( V_362 , & V_3 -> V_403 , V_270 ) ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_270 ;
}
static T_23
F_133 ( struct V_144 * V_359 ,
struct V_360 * V_361 , const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_402 ) , V_380 ) ;
memset ( & V_3 -> V_403 , 0 ,
sizeof( struct V_402 ) ) ;
memcpy ( & V_3 -> V_403 , V_362 , V_63 ) ;
if ( V_3 -> V_403 . V_404 > V_405 )
V_3 -> V_403 . V_404 = V_405 ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_63 ;
}
static T_23
F_134 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_270 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_270 = sizeof( struct V_406 ) ;
memcpy ( V_362 , & V_3 -> V_407 , V_270 ) ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_270 ;
}
static T_23
F_135 ( struct V_144 * V_359 ,
struct V_360 * V_361 , const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_406 ) , V_380 ) ;
memset ( & V_3 -> V_407 , 0 ,
sizeof( struct V_402 ) ) ;
memcpy ( & V_3 -> V_407 , V_362 , V_63 ) ;
if ( V_3 -> V_407 . V_404 > V_405 )
V_3 -> V_407 . V_404 = V_405 ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_63 ;
}
static T_23
F_136 ( struct V_144 * V_359 ,
struct V_360 * V_361 , char * V_362 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_270 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_270 = sizeof( struct V_408 ) ;
memcpy ( V_362 , & V_3 -> V_409 , V_270 ) ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_270 ;
}
static T_23
F_137 ( struct V_144 * V_359 ,
struct V_360 * V_361 , const char * V_362 , T_15 V_380 )
{
struct V_363 * V_364 = F_101 ( V_359 ) ;
struct V_2 * V_3 = F_102 ( V_364 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_400 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_408 ) , V_380 ) ;
memset ( & V_3 -> V_409 , 0 ,
sizeof( V_3 -> V_409 ) ) ;
memcpy ( & V_3 -> V_409 , V_362 , V_63 ) ;
if ( V_3 -> V_409 . V_404 > V_405 )
V_3 -> V_409 . V_404 = V_405 ;
F_10 ( & V_3 -> V_400 , V_50 ) ;
return V_63 ;
}
static T_23
F_138 ( struct V_144 * V_410 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_411 * V_412 = F_139 ( V_410 ) ;
struct V_132 * V_413 = V_412 -> V_145 ;
return snprintf ( V_362 , V_365 , L_84 ,
( unsigned long long ) V_413 -> V_146 -> V_53 ) ;
}
static T_23
F_140 ( struct V_144 * V_410 , struct V_360 * V_361 ,
char * V_362 )
{
struct V_411 * V_412 = F_139 ( V_410 ) ;
struct V_132 * V_413 = V_412 -> V_145 ;
return snprintf ( V_362 , V_365 , L_109 ,
V_413 -> V_146 -> V_4 ) ;
}
void
F_141 ( T_26 V_414 )
{
V_95 = NULL ;
if ( V_414 != 1 )
if ( F_142 ( & V_415 ) < 0 )
F_37 ( L_110 ,
V_416 , V_417 ) ;
if ( V_414 != 2 )
if ( F_142 ( & V_418 ) < 0 )
F_37 ( L_110 ,
V_419 , V_420 ) ;
F_143 ( & V_94 ) ;
}
void
F_144 ( T_26 V_414 )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_111 ; V_77 ++ ) {
if ( ! V_3 -> V_293 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_112 [ V_77 ] &
V_113 ) )
continue;
if ( ( V_3 -> V_112 [ V_77 ] &
V_114 ) )
continue;
F_60 ( V_3 -> V_181 , V_3 -> V_299 [ V_77 ] ,
V_3 -> V_293 [ V_77 ] , V_3 -> V_298 [ V_77 ] ) ;
V_3 -> V_293 [ V_77 ] = NULL ;
V_3 -> V_112 [ V_77 ] = 0 ;
}
F_61 ( V_3 -> V_79 ) ;
}
if ( V_414 != 1 )
F_145 ( & V_415 ) ;
if ( V_414 != 2 )
F_145 ( & V_418 ) ;
}
