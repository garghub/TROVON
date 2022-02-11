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
F_6 ( V_53 L_20
L_21 , V_3 -> V_46 , ( unsigned long long )
V_5 -> V_54 , V_5 -> V_55 ) ;
F_6 ( V_53
L_22 ,
V_3 -> V_46 , V_5 -> V_56 ,
V_5 -> V_57 ) ;
}
F_9 ( & V_3 -> V_51 , V_50 ) ;
if ( V_49 -> V_58 || V_49 -> V_59 )
F_6 ( V_45
L_23
L_24 , V_3 -> V_46 ,
V_49 -> V_58 ,
V_49 -> V_59 ) ;
}
}
T_6
F_10 ( struct V_2 * V_3 , T_1 V_8 , T_6 V_60 ,
T_7 V_61 )
{
T_2 * V_10 ;
T_5 * V_62 ;
const void * V_63 ;
T_7 V_64 ;
if ( V_3 -> V_65 . V_66 == V_67 )
return 1 ;
if ( V_3 -> V_65 . V_8 != V_8 )
return 1 ;
V_3 -> V_65 . V_66 |= V_68 ;
V_10 = F_11 ( V_3 , V_61 ) ;
if ( V_10 ) {
memcpy ( V_3 -> V_65 . V_61 , V_10 , V_10 -> V_69 * 4 ) ;
V_3 -> V_65 . V_66 |= V_70 ;
if ( V_10 -> V_15 == V_16 ||
V_10 -> V_15 ==
V_39 ) {
V_62 = ( T_5 * ) V_10 ;
if ( V_62 -> V_58 &
V_71 ) {
V_64 = F_12 ( T_7 , V_72 ,
F_7 ( V_62 -> V_73 ) ) ;
V_63 = F_13 ( V_3 ,
V_8 ) ;
memcpy ( V_3 -> V_65 . V_74 , V_63 , V_64 ) ;
}
}
}
#ifdef F_14
F_3 ( V_3 , V_8 , L_25 , V_10 ) ;
#endif
V_3 -> V_65 . V_66 &= ~ V_75 ;
F_15 ( & V_3 -> V_65 . V_76 ) ;
return 1 ;
}
static int
F_16 ( struct V_2 * V_3 , T_1 V_77 )
{
T_1 V_78 ;
T_7 V_79 ;
if ( V_77 >= 128 || ! V_77 || ! V_3 -> V_80 )
return 0 ;
V_79 = ( 1 << ( V_77 % 32 ) ) ;
if ( ! V_79 )
V_79 = 1 ;
V_78 = V_77 / 32 ;
return V_79 & V_3 -> V_81 [ V_78 ] ;
}
void
F_17 ( struct V_2 * V_3 ,
T_8 * V_10 )
{
struct V_82 * V_80 ;
T_1 V_77 ;
int V_78 ;
T_7 V_64 , V_83 ;
T_6 V_84 = 0 ;
if ( ! V_3 -> V_80 )
return;
V_77 = F_5 ( V_10 -> V_85 ) ;
if ( F_16 ( V_3 , V_77 ) ) {
V_78 = V_3 -> V_86 % V_87 ;
V_80 = V_3 -> V_80 ;
V_80 [ V_78 ] . V_77 = V_77 ;
V_80 [ V_78 ] . V_88 = V_3 -> V_86 ++ ;
V_83 = F_5 ( V_10 -> V_89 ) * 4 ;
V_64 = F_12 ( T_7 , V_83 , V_90 ) ;
memset ( V_80 [ V_78 ] . V_91 , 0 , V_90 ) ;
memcpy ( V_80 [ V_78 ] . V_91 , V_10 -> V_92 , V_64 ) ;
V_84 = 1 ;
}
if ( V_77 == V_93 ||
( V_84 && ! V_3 -> V_94 ) ) {
V_3 -> V_94 = 1 ;
F_18 ( & V_95 ) ;
if ( V_96 )
F_19 ( & V_96 , V_97 , V_98 ) ;
}
}
void
F_20 ( struct V_2 * V_3 , T_6 V_60 ,
T_7 V_61 )
{
T_8 * V_10 ;
V_10 = F_11 ( V_3 , V_61 ) ;
if ( F_21 ( ! V_10 ) ) {
F_6 ( V_99 L_26 ,
V_3 -> V_46 , __FILE__ , __LINE__ , V_100 ) ;
return;
}
F_17 ( V_3 , V_10 ) ;
return;
}
static int
F_22 ( int V_101 , struct V_2 * * V_102 )
{
struct V_2 * V_3 ;
F_23 ( & V_103 ) ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
if ( V_3 -> V_104 != V_101 )
continue;
F_24 ( & V_103 ) ;
* V_102 = V_3 ;
return V_101 ;
}
F_24 ( & V_103 ) ;
* V_102 = NULL ;
return - 1 ;
}
void
F_25 ( struct V_2 * V_3 , int V_105 )
{
int V_78 ;
T_6 V_106 ;
switch ( V_105 ) {
case V_107 :
F_26 ( V_3 , F_6 ( V_45 L_27
L_28 , V_3 -> V_46 , V_100 ) ) ;
for ( V_78 = 0 ; V_78 < V_108 ; V_78 ++ ) {
if ( ! ( V_3 -> V_109 [ V_78 ] &
V_110 ) )
continue;
if ( ( V_3 -> V_109 [ V_78 ] &
V_111 ) )
continue;
F_27 ( V_3 , V_78 , & V_106 ) ;
}
break;
case V_112 :
F_26 ( V_3 , F_6 ( V_45 L_27
L_29 , V_3 -> V_46 , V_100 ) ) ;
if ( V_3 -> V_65 . V_66 & V_75 ) {
V_3 -> V_65 . V_66 |= V_113 ;
F_28 ( V_3 , V_3 -> V_65 . V_8 ) ;
F_15 ( & V_3 -> V_65 . V_76 ) ;
}
break;
case V_114 :
F_26 ( V_3 , F_6 ( V_45 L_27
L_30 , V_3 -> V_46 , V_100 ) ) ;
for ( V_78 = 0 ; V_78 < V_108 ; V_78 ++ ) {
if ( ! ( V_3 -> V_109 [ V_78 ] &
V_110 ) )
continue;
if ( ( V_3 -> V_109 [ V_78 ] &
V_111 ) )
continue;
V_3 -> V_109 [ V_78 ] |=
V_115 ;
}
break;
}
}
static int
F_29 ( int V_116 , struct V_117 * V_118 , int V_119 )
{
return F_30 ( V_116 , V_118 , V_119 , & V_96 ) ;
}
static unsigned int
F_31 ( struct V_117 * V_118 , T_9 * V_120 )
{
struct V_2 * V_3 ;
F_32 ( V_118 , & V_95 , V_120 ) ;
F_23 ( & V_103 ) ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
if ( V_3 -> V_94 ) {
F_24 ( & V_103 ) ;
return V_121 | V_122 ;
}
}
F_24 ( & V_103 ) ;
return 0 ;
}
static int
F_33 ( struct V_2 * V_3 , struct V_123 * V_124 ,
T_10 * V_125 )
{
T_6 V_126 = 0 ;
T_1 V_78 ;
T_1 V_4 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
unsigned long V_50 ;
T_11 * V_131 ;
T_7 V_64 ;
T_7 V_132 ;
char * V_12 = NULL ;
if ( V_125 -> V_133 == V_134 )
V_12 = L_31 ;
else if ( V_125 -> V_133 == V_135 )
V_12 = L_32 ;
else
return 0 ;
V_132 = F_34 ( (struct V_136 * ) V_125 -> V_137 ) ;
V_4 = F_5 ( V_125 -> V_52 ) ;
F_8 ( & V_3 -> V_138 , V_50 ) ;
for ( V_78 = V_3 -> V_139 ; V_78 && ! V_126 ; V_78 -- ) {
V_128 = V_3 -> V_140 [ V_78 - 1 ] . V_128 ;
if ( V_128 == NULL || V_128 -> V_141 == NULL ||
V_128 -> V_141 -> V_142 == NULL )
continue;
if ( V_132 != V_128 -> V_141 -> V_132 )
continue;
V_130 = V_128 -> V_141 -> V_142 ;
if ( V_130 -> V_143 == NULL )
continue;
if ( V_130 -> V_143 -> V_4 != V_4 )
continue;
V_125 -> V_144 = F_35 ( V_3 -> V_140 [ V_78 - 1 ] . V_8 ) ;
V_126 = 1 ;
}
F_9 ( & V_3 -> V_138 , V_50 ) ;
if ( ! V_126 ) {
F_36 ( V_3 , F_6 ( V_45 L_27
L_33 , V_3 -> V_46 ,
V_12 , F_5 ( V_125 -> V_52 ) , V_132 ) ) ;
V_131 = V_3 -> V_65 . V_61 ;
V_131 -> V_52 = V_125 -> V_52 ;
V_131 -> V_15 = V_23 ;
V_131 -> V_133 = V_125 -> V_133 ;
V_131 -> V_69 = sizeof( T_11 ) / 4 ;
V_131 -> V_145 = V_125 -> V_145 ;
V_131 -> V_146 = V_125 -> V_146 ;
V_64 = F_12 ( T_7 , V_124 -> V_147 , V_3 -> V_148 ) ;
if ( F_37 ( V_124 -> V_149 , V_3 -> V_65 . V_61 ,
V_64 ) )
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
return 1 ;
}
F_36 ( V_3 , F_6 ( V_45 L_27
L_35 , V_3 -> V_46 ,
V_12 , F_5 ( V_125 -> V_52 ) , V_132 ,
F_5 ( V_125 -> V_144 ) ) ) ;
return 0 ;
}
static long
F_38 ( struct V_2 * V_3 , struct V_123 V_124 ,
void T_12 * V_151 )
{
T_13 * V_11 = NULL , * V_152 ;
T_2 * V_10 ;
T_7 V_153 ;
T_1 V_154 ;
T_1 V_8 ;
unsigned long V_155 , V_156 ;
T_6 V_106 ;
T_7 V_64 ;
void * V_157 ;
void * V_158 = NULL ;
T_14 V_159 ;
T_15 V_160 = 0 ;
void * V_161 = NULL ;
T_14 V_162 ;
T_15 V_163 = 0 ;
T_7 V_164 ;
long V_165 ;
T_1 V_166 ;
V_106 = 0 ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_99 L_36 ,
V_3 -> V_46 , V_100 ) ;
V_165 = - V_167 ;
goto V_7;
}
V_166 = 0 ;
V_153 = F_39 ( V_3 , 1 ) ;
while ( V_153 != V_168 ) {
if ( V_166 ++ == 10 ) {
F_6 ( V_99
L_37 ,
V_3 -> V_46 , V_100 ) ;
V_165 = - V_169 ;
goto V_7;
}
F_40 ( 1 ) ;
V_153 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45 L_38
L_39 , V_3 -> V_46 ,
V_100 , V_166 ) ;
}
if ( V_166 )
F_6 ( V_45 L_40 ,
V_3 -> V_46 , V_100 ) ;
V_11 = F_41 ( V_3 -> V_170 , V_171 ) ;
if ( ! V_11 ) {
F_6 ( V_99 L_41
L_42 , V_3 -> V_46 , V_100 ) ;
V_165 = - V_172 ;
goto V_7;
}
if ( V_124 . V_173 * 4 > V_3 -> V_170 ||
V_124 . V_173 > ( V_174 / 4 ) ) {
V_165 = - V_175 ;
goto V_7;
}
if ( F_42 ( V_11 , V_151 , V_124 . V_173 * 4 ) ) {
F_6 ( V_150 L_34 , __FILE__ , __LINE__ ,
V_100 ) ;
V_165 = - V_169 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_99 L_43 ,
V_3 -> V_46 , V_100 ) ;
V_165 = - V_167 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_176 , NULL ) ;
if ( ! V_8 ) {
F_6 ( V_99 L_43 ,
V_3 -> V_46 , V_100 ) ;
V_165 = - V_167 ;
goto V_7;
}
}
V_165 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_148 ) ;
V_152 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_152 , V_11 , V_124 . V_173 * 4 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_160 = V_124 . V_177 ;
V_163 = V_124 . V_178 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_179 ) ||
F_5 ( V_11 -> V_179 ) >
V_3 -> V_180 . V_181 ) {
V_165 = - V_175 ;
F_28 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_160 ) {
V_158 = F_45 ( V_3 -> V_182 , V_160 ,
& V_159 ) ;
if ( ! V_158 ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_172 ;
F_28 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_158 , V_124 . V_183 ,
V_160 ) ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_169 ;
F_28 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_163 ) {
V_161 = F_45 ( V_3 -> V_182 , V_163 ,
& V_162 ) ;
if ( ! V_161 ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_172 ;
F_28 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_157 = ( void * ) V_152 + ( V_124 . V_173 * 4 ) ;
if ( ! V_160 && ! V_163 ) {
F_46 ( V_3 , V_157 ) ;
} else if ( V_160 && V_163 ) {
V_164 = ( V_184 |
V_185 | V_186 ) ;
V_164 = V_164 << V_187 ;
V_3 -> V_188 ( V_157 , V_164 |
V_160 , V_159 ) ;
V_157 += V_3 -> V_189 ;
V_164 = ( V_184 |
V_190 | V_185 |
V_191 ) ;
V_164 = V_164 << V_187 ;
V_3 -> V_188 ( V_157 , V_164 |
V_163 , V_162 ) ;
} else if ( V_160 ) {
V_164 = ( V_184 |
V_190 | V_185 |
V_191 | V_186 ) ;
V_164 = V_164 << V_187 ;
V_3 -> V_188 ( V_157 , V_164 |
V_160 , V_159 ) ;
} else if ( V_163 ) {
V_164 = ( V_184 |
V_190 | V_185 |
V_191 ) ;
V_164 = V_164 << V_187 ;
V_3 -> V_188 ( V_157 , V_164 |
V_163 , V_162 ) ;
}
#ifdef F_14
F_3 ( V_3 , V_8 , L_44 , NULL ) ;
#endif
F_47 ( & V_3 -> V_65 . V_76 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_192 =
( T_4 * ) V_152 ;
V_192 -> V_193 = V_72 ;
V_192 -> V_194 =
F_48 ( V_3 , V_8 ) ;
memset ( V_3 -> V_65 . V_74 , 0 , V_72 ) ;
if ( V_11 -> V_15 == V_16 )
F_49 ( V_3 , V_8 ,
F_5 ( V_11 -> V_179 ) ) ;
else
F_50 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_125 =
( T_10 * ) V_152 ;
F_26 ( V_3 , F_6 ( V_45 L_45
L_46 , V_3 -> V_46 ,
F_5 ( V_125 -> V_52 ) , V_125 -> V_133 ) ) ;
if ( V_125 -> V_133 ==
V_134 ||
V_125 -> V_133 ==
V_135 ) {
if ( F_33 ( V_3 , & V_124 , V_125 ) ) {
F_28 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_51 ( V_3 , F_5 (
V_125 -> V_52 ) ) ;
F_52 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_195 =
( T_16 * ) V_11 ;
T_6 * V_91 ;
V_195 -> V_196 = 0xFF ;
if ( V_195 -> V_197 &
V_198 )
V_91 = ( T_6 * ) & V_195 -> V_199 ;
else {
if ( F_21 ( V_158 == NULL ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
F_28 ( V_3 , V_8 ) ;
V_165 = - V_175 ;
goto V_7;
}
V_91 = V_158 ;
}
if ( V_91 [ 1 ] == 0x91 && ( V_91 [ 10 ] == 1 || V_91 [ 10 ] == 2 ) ) {
V_3 -> V_200 = 1 ;
V_3 -> V_201 = 1 ;
}
F_50 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_17 * V_202 =
( T_17 * ) V_11 ;
if ( V_202 -> V_203 == V_204
|| V_202 -> V_203 ==
V_205 ) {
V_3 -> V_200 = 1 ;
V_3 -> V_201 = 1 ;
}
F_50 ( V_3 , V_8 ) ;
break;
}
default:
F_50 ( V_3 , V_8 ) ;
break;
}
if ( V_124 . V_155 < V_206 )
V_155 = V_206 ;
else
V_155 = V_124 . V_155 ;
V_156 = F_53 ( & V_3 -> V_65 . V_76 ,
V_155 * V_207 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_125 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_125 -> V_52 ) ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_200 ) {
V_3 -> V_200 = 0 ;
V_3 -> V_201 = 0 ;
}
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_99 L_47 , V_3 -> V_46 ,
V_100 ) ;
F_55 ( V_11 , V_124 . V_173 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_113 ) )
V_106 = 1 ;
goto V_208;
}
V_10 = V_3 -> V_65 . V_61 ;
V_154 = F_5 ( V_10 -> V_47 ) & V_209 ;
#ifdef F_14
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_210 ) ) {
T_11 * V_131 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_45
L_48
L_49 , V_3 -> V_46 ,
F_5 ( V_131 -> V_47 ) ,
F_7 ( V_131 -> V_48 ) ,
F_7 ( V_131 -> V_211 ) ) ;
}
#endif
if ( V_163 ) {
if ( F_37 ( V_124 . V_212 , V_161 ,
V_163 ) ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_213 ;
goto V_7;
}
}
if ( V_124 . V_147 ) {
V_64 = F_12 ( T_7 , V_124 . V_147 , V_3 -> V_148 ) ;
if ( F_37 ( V_124 . V_149 , V_3 -> V_65 . V_61 ,
V_64 ) ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_213 ;
goto V_7;
}
}
if ( V_124 . V_214 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_64 = F_12 ( T_7 , V_124 . V_214 , V_72 ) ;
if ( F_37 ( V_124 . V_215 ,
V_3 -> V_65 . V_74 , V_64 ) ) {
F_6 ( V_150 L_34 , __FILE__ ,
__LINE__ , V_100 ) ;
V_165 = - V_213 ;
goto V_7;
}
}
V_208:
if ( V_106 ) {
V_165 = - V_213 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_50
L_51 , V_3 -> V_46 ,
F_5 ( V_11 -> V_179 ) ) ;
F_56 ( V_3 ) ;
F_57 ( V_3 ,
F_5 ( V_11 -> V_179 ) , 0 , 0 ,
0 , V_216 , 0 , 10 ,
V_217 ) ;
V_3 -> V_218 . V_66 = V_67 ;
} else
F_58 ( V_3 , V_219 ,
V_220 ) ;
}
V_7:
if ( V_161 )
F_59 ( V_3 -> V_182 , V_163 , V_161 ,
V_162 ) ;
if ( V_158 )
F_59 ( V_3 -> V_182 , V_160 , V_158 ,
V_159 ) ;
F_60 ( V_11 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_165 ;
}
static long
F_61 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_222 V_124 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_100 ) ) ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
if ( V_3 -> V_223 )
V_124 . V_224 = V_225 ;
else
V_124 . V_224 = V_226 ;
if ( V_3 -> V_227 )
V_124 . V_228 = V_3 -> V_227 [ 0 ] . V_229 ;
V_124 . V_230 = V_3 -> V_182 -> V_231 ;
V_124 . V_232 = V_3 -> V_182 -> V_141 ;
V_124 . V_233 = V_3 -> V_182 -> V_233 ;
V_124 . V_234 = V_3 -> V_182 -> V_234 ;
V_124 . V_235 . V_236 . V_237 . V_238 = V_3 -> V_182 -> V_238 -> V_239 ;
V_124 . V_235 . V_236 . V_237 . V_141 = F_62 ( V_3 -> V_182 -> V_240 ) ;
V_124 . V_235 . V_236 . V_237 . V_241 = F_63 ( V_3 -> V_182 -> V_240 ) ;
V_124 . V_235 . V_242 = F_64 ( V_3 -> V_182 -> V_238 ) ;
V_124 . V_243 = V_3 -> V_180 . V_244 . V_245 ;
strcpy ( V_124 . V_246 , V_247 ) ;
strcat ( V_124 . V_246 , L_53 ) ;
strcat ( V_124 . V_246 , V_248 ) ;
V_124 . V_249 = F_7 ( V_3 -> V_250 . V_251 ) ;
if ( F_37 ( V_221 , & V_124 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
return 0 ;
}
static long
F_65 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_252 V_124 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_100 ) ) ;
V_124 . V_253 = V_87 ;
memcpy ( V_124 . V_254 , V_3 -> V_81 ,
V_255 * sizeof( T_7 ) ) ;
if ( F_37 ( V_221 , & V_124 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_256 V_124 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_100 ) ) ;
if ( V_3 -> V_80 )
return 0 ;
memcpy ( V_3 -> V_81 , V_124 . V_254 ,
V_255 * sizeof( T_7 ) ) ;
F_67 ( V_3 , V_3 -> V_81 ) ;
V_3 -> V_86 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_80 = F_68 ( V_87 ,
sizeof( struct V_82 ) , V_171 ) ;
if ( ! V_3 -> V_80 ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_172 ;
}
return 0 ;
}
static long
F_69 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_257 V_124 ;
T_7 V_258 , V_259 , V_260 ;
struct V_257 T_12 * V_261 = V_221 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_100 ) ) ;
V_258 = V_124 . V_262 . V_263 -
sizeof( struct V_264 ) ;
V_259 = V_258 / sizeof( struct V_82 ) ;
V_260 = F_12 ( T_7 , V_87 , V_259 ) ;
if ( ! V_260 || ! V_3 -> V_80 )
return - V_213 ;
V_258 = V_260 * sizeof( struct V_82 ) ;
if ( F_37 ( V_261 -> V_265 , V_3 -> V_80 , V_258 ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
V_3 -> V_94 = 0 ;
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_266 V_124 ;
int V_267 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 )
return - V_167 ;
F_36 ( V_3 , F_6 ( V_45 L_52 , V_3 -> V_46 ,
V_100 ) ) ;
V_267 = F_58 ( V_3 , V_219 ,
V_220 ) ;
F_6 ( V_45 L_54 ,
V_3 -> V_46 , ( ( ! V_267 ) ? L_55 : L_56 ) ) ;
return 0 ;
}
static int
F_71 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_72 ( & V_3 -> V_274 ) )
return V_273 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_272 -> V_238 == 0xFFFFFFFF && V_272 -> V_104 == 0xFFFFFFFF &&
V_272 -> V_4 == V_5 -> V_4 ) {
V_272 -> V_238 = V_5 -> V_275 ;
V_272 -> V_104 = V_5 -> V_104 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_238 == V_5 -> V_275 && V_272 -> V_104 ==
V_5 -> V_104 && V_272 -> V_4 == 0xFFFF ) {
V_272 -> V_4 = V_5 -> V_4 ;
V_273 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_51 , V_50 ) ;
return V_273 ;
}
static int
F_73 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_276 * V_277 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_72 ( & V_3 -> V_278 ) )
return V_273 ;
F_8 ( & V_3 -> V_279 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_272 -> V_238 == 0xFFFFFFFF && V_272 -> V_104 == 0xFFFFFFFF &&
V_272 -> V_4 == V_277 -> V_4 ) {
V_272 -> V_238 = V_277 -> V_275 ;
V_272 -> V_104 = V_277 -> V_104 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_238 == V_277 -> V_275 && V_272 -> V_104 ==
V_277 -> V_104 && V_272 -> V_4 == 0xFFFF ) {
V_272 -> V_4 = V_277 -> V_4 ;
V_273 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_279 , V_50 ) ;
return V_273 ;
}
static long
F_74 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_271 V_124 ;
int V_273 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_273 = F_71 ( V_3 , & V_124 ) ;
if ( ! V_273 )
F_73 ( V_3 , & V_124 ) ;
if ( F_37 ( V_221 , & V_124 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
return 0 ;
}
static T_6
F_75 ( struct V_2 * V_3 , T_6 V_280 )
{
T_6 V_273 = 0 ;
switch ( V_280 ) {
case V_281 :
if ( V_3 -> V_180 . V_282 &
V_283 )
V_273 = 1 ;
break;
case V_284 :
if ( V_3 -> V_180 . V_282 &
V_285 )
V_273 = 1 ;
break;
case V_286 :
if ( V_3 -> V_180 . V_282 &
V_287 )
V_273 = 1 ;
}
return V_273 ;
}
static long
F_76 ( struct V_2 * V_3 ,
struct V_288 * V_289 )
{
int V_273 , V_78 ;
void * V_290 = NULL ;
T_14 V_291 ;
T_7 V_292 = 0 ;
T_18 * V_11 ;
T_19 * V_10 ;
T_6 V_280 ;
unsigned long V_156 ;
T_1 V_8 ;
T_1 V_154 ;
T_6 V_106 = 0 ;
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_99 L_36 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_280 = V_289 -> V_280 ;
if ( ! F_75 ( V_3 , V_280 ) ) {
F_6 ( V_99 L_58
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_293 ;
}
if ( V_3 -> V_109 [ V_280 ] &
V_110 ) {
F_6 ( V_99 L_60
L_61 , V_3 -> V_46 , V_100 ,
V_280 ) ;
return - V_175 ;
}
if ( V_289 -> V_294 % 4 ) {
F_6 ( V_99 L_62
L_63 , V_3 -> V_46 , V_100 ) ;
return - V_175 ;
}
V_8 = F_77 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_99 L_43 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_290 = V_3 -> V_295 [ V_280 ] ;
V_292 = V_289 -> V_294 ;
V_3 -> V_296 [ V_280 ] = V_289 -> V_296 ;
V_3 -> V_109 [ V_280 ] = 0 ;
memcpy ( V_3 -> V_297 [ V_280 ] ,
V_289 -> V_297 , V_298 ) ;
V_3 -> V_299 [ V_280 ] = V_289 -> V_299 ;
if ( V_290 ) {
V_291 = V_3 -> V_300 [ V_280 ] ;
if ( V_292 != V_3 -> V_301 [ V_280 ] ) {
F_59 ( V_3 -> V_182 ,
V_3 -> V_301 [ V_280 ] ,
V_290 , V_291 ) ;
V_290 = NULL ;
}
}
if ( V_290 == NULL ) {
V_3 -> V_301 [ V_280 ] = 0 ;
V_3 -> V_300 [ V_280 ] = 0 ;
V_290 = F_45 (
V_3 -> V_182 , V_292 , & V_291 ) ;
if ( V_290 == NULL ) {
F_6 ( V_99 L_64
L_65 ,
V_3 -> V_46 , V_100 , V_292 ) ;
F_28 ( V_3 , V_8 ) ;
return - V_172 ;
}
V_3 -> V_295 [ V_280 ] = V_290 ;
V_3 -> V_301 [ V_280 ] = V_292 ;
V_3 -> V_300 [ V_280 ] = V_291 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_289 -> V_280 ;
V_11 -> V_303 = F_78 ( V_289 -> V_299 ) ;
V_11 -> V_304 = F_79 ( V_291 ) ;
V_11 -> V_305 = F_78 ( V_292 ) ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_36 ( V_3 , F_6 ( V_45 L_66
L_67 , V_3 -> V_46 , V_100 , V_290 ,
( unsigned long long ) V_291 ,
F_7 ( V_11 -> V_305 ) ) ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_11 -> V_306 [ V_78 ] =
F_78 ( V_3 -> V_297 [ V_280 ] [ V_78 ] ) ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_156 = F_53 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_99 L_47 , V_3 -> V_46 ,
V_100 ) ;
F_55 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_113 ) )
V_106 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_99 L_68 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_154 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_154 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_110 ;
F_36 ( V_3 , F_6 ( V_45 L_69 ,
V_3 -> V_46 , V_100 ) ) ;
} else {
F_6 ( V_45 L_70
L_71 , V_3 -> V_46 , V_100 ,
V_154 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_208:
if ( V_106 )
F_58 ( V_3 , V_219 ,
V_220 ) ;
V_7:
if ( V_273 && V_290 )
F_59 ( V_3 -> V_182 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
void
F_80 ( struct V_2 * V_3 , T_6 V_308 )
{
struct V_288 V_289 ;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
if ( V_308 & 1 ) {
F_6 ( V_45 L_72 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
F_76 ( V_3 , & V_289 ) ;
}
if ( V_308 & 2 ) {
F_6 ( V_45 L_73 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_284 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_76 ( V_3 , & V_289 ) ;
}
if ( V_308 & 4 ) {
F_6 ( V_45 L_74 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_286 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_76 ( V_3 , & V_289 ) ;
}
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_288 V_124 ;
long V_273 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
V_273 = F_76 ( V_3 , & V_124 ) ;
return V_273 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_309 V_124 ;
void * V_290 ;
T_14 V_291 ;
T_7 V_292 ;
T_6 V_280 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_280 ) ) {
F_6 ( V_99 L_58
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_6 ( V_99 L_75
L_76 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_175 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_111 ) == 0 ) {
F_6 ( V_99 L_77
L_78 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_175 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_99 L_79
L_76 , V_3 -> V_46 , V_100 , V_124 . V_296 ) ;
return - V_175 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_99 L_80
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_172 ;
}
V_292 = V_3 -> V_301 [ V_280 ] ;
V_291 = V_3 -> V_300 [ V_280 ] ;
F_59 ( V_3 -> V_182 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_295 [ V_280 ] = NULL ;
V_3 -> V_109 [ V_280 ] = 0 ;
return 0 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_310 V_124 ;
void * V_290 ;
int V_78 ;
T_6 V_280 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_124 . V_311 = 0 ;
V_280 = V_124 . V_280 ;
if ( ! F_75 ( V_3 , V_280 ) ) {
F_6 ( V_99 L_58
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_6 ( V_99 L_75
L_76 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_175 ;
}
if ( V_124 . V_296 & 0xffffff00 ) {
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_99 L_79
L_76 , V_3 -> V_46 , V_100 ,
V_124 . V_296 ) ;
return - V_175 ;
}
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_99 L_81
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_172 ;
}
if ( V_3 -> V_109 [ V_280 ] & V_111 )
V_124 . V_311 = ( V_312 |
V_313 ) ;
else
V_124 . V_311 = ( V_312 |
V_313 |
V_314 ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_124 . V_297 [ V_78 ] =
V_3 -> V_297 [ V_280 ] [ V_78 ] ;
V_124 . V_315 = V_3 -> V_301 [ V_280 ] ;
V_124 . V_316 = 0 ;
V_124 . V_296 = V_3 -> V_296 [ V_280 ] ;
V_124 . V_299 = V_3 -> V_299 [ V_280 ] ;
if ( F_37 ( V_221 , & V_124 , sizeof( struct V_310 ) ) ) {
F_6 ( V_99 L_82
L_83 , V_3 -> V_46 , V_100 , V_221 ) ;
return - V_169 ;
}
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 , T_6 V_280 , T_6 * V_106 )
{
T_20 * V_11 ;
T_21 * V_10 ;
T_1 V_8 ;
T_1 V_154 ;
T_7 V_153 ;
int V_273 ;
unsigned long V_156 ;
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_273 = 0 ;
* V_106 = 0 ;
V_153 = F_39 ( V_3 , 1 ) ;
if ( V_153 != V_168 ) {
F_36 ( V_3 , F_6 ( V_45 L_27
L_84 , V_3 -> V_46 ,
V_100 ) ) ;
V_273 = - V_167 ;
goto V_7;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_99 L_36 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_8 = F_77 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_99 L_43 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_156 = F_53 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_99 L_47 , V_3 -> V_46 ,
V_100 ) ;
F_55 ( V_11 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_113 ) )
* V_106 = 1 ;
V_273 = - V_169 ;
goto V_7;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_99 L_68 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_154 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_154 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_111 ;
F_36 ( V_3 , F_6 ( V_45 L_69 ,
V_3 -> V_46 , V_100 ) ) ;
} else {
F_6 ( V_45 L_70
L_71 , V_3 -> V_46 , V_100 ,
V_154 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_317 V_124 ;
void * V_290 ;
int V_273 ;
T_6 V_280 ;
T_6 V_106 = 0 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_280 ) ) {
F_6 ( V_99 L_58
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_6 ( V_99 L_75
L_76 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_175 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_99 L_79
L_76 , V_3 -> V_46 , V_100 , V_124 . V_296 ) ;
return - V_175 ;
}
if ( V_3 -> V_109 [ V_280 ] &
V_111 ) {
F_6 ( V_99 L_85
L_86 , V_3 -> V_46 , V_100 ,
V_280 ) ;
return 0 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_99 L_80
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_172 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_115 ) ) {
V_3 -> V_109 [ V_280 ] |=
V_111 ;
V_3 -> V_109 [ V_280 ] &=
~ V_115 ;
F_6 ( V_99 L_85
L_87 , V_3 -> V_46 , V_100 ,
V_280 ) ;
return 0 ;
}
V_273 = F_27 ( V_3 , V_280 , & V_106 ) ;
if ( V_106 )
F_58 ( V_3 , V_219 ,
V_220 ) ;
return V_273 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_318 V_124 ;
struct V_318 T_12 * V_261 = V_221 ;
void * V_290 , * V_319 ;
T_18 * V_11 ;
T_19 * V_10 ;
int V_273 , V_78 ;
T_6 V_280 ;
unsigned long V_156 , V_320 , V_321 ;
T_1 V_8 ;
T_1 V_154 ;
T_6 V_106 = 0 ;
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
F_36 ( V_3 , F_6 ( V_45 L_57 , V_3 -> V_46 ,
V_100 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_280 ) ) {
F_6 ( V_99 L_58
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_293 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_99 L_79
L_76 , V_3 -> V_46 , V_100 , V_124 . V_296 ) ;
return - V_175 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_99 L_81
L_59 , V_3 -> V_46 , V_100 , V_280 ) ;
return - V_172 ;
}
V_320 = V_3 -> V_301 [ V_280 ] ;
if ( ( V_124 . V_322 % 4 ) || ( V_124 . V_323 % 4 ) ) {
F_6 ( V_99 L_88
L_89 , V_3 -> V_46 ,
V_100 ) ;
return - V_175 ;
}
if ( V_124 . V_322 > V_320 )
return - V_175 ;
V_319 = ( void * ) ( V_290 + V_124 . V_322 ) ;
F_36 ( V_3 , F_6 ( V_45 L_90
L_91 , V_3 -> V_46 , V_100 ,
V_319 , V_124 . V_322 , V_124 . V_323 ) ) ;
if ( ( V_319 + V_124 . V_323 < V_319 ) ||
( V_319 + V_124 . V_323 > V_290 + V_320 ) )
V_321 = V_320 - V_124 . V_322 ;
else
V_321 = V_124 . V_323 ;
if ( F_37 ( ( void T_12 * ) V_261 -> V_324 ,
V_319 , V_321 ) ) {
F_6 ( V_99 L_92
L_93 , V_3 -> V_46 ,
V_100 , V_319 ) ;
return - V_169 ;
}
if ( ( V_124 . V_50 & V_325 ) == 0 )
return 0 ;
F_36 ( V_3 , F_6 ( V_45 L_94
L_59 , V_3 -> V_46 , V_100 , V_280 ) ) ;
if ( ( V_3 -> V_109 [ V_280 ] &
V_111 ) == 0 ) {
F_36 ( V_3 , F_6 ( V_45 L_27
L_95 , V_3 -> V_46 ,
V_100 , V_280 ) ) ;
return 0 ;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_99 L_36 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_8 = F_77 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_99 L_43 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_305 =
F_78 ( V_3 -> V_301 [ V_280 ] ) ;
V_11 -> V_304 =
F_79 ( V_3 -> V_300 [ V_280 ] ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_11 -> V_306 [ V_78 ] =
F_78 ( V_3 -> V_297 [ V_280 ] [ V_78 ] ) ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_156 = F_53 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_99 L_47 , V_3 -> V_46 ,
V_100 ) ;
F_55 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_113 ) )
V_106 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_99 L_68 ,
V_3 -> V_46 , V_100 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_154 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_154 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_110 ;
F_36 ( V_3 , F_6 ( V_45 L_69 ,
V_3 -> V_46 , V_100 ) ) ;
} else {
F_6 ( V_45 L_70
L_71 , V_3 -> V_46 , V_100 ,
V_154 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_208:
if ( V_106 )
F_58 ( V_3 , V_219 ,
V_220 ) ;
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
static long
F_86 ( struct V_2 * V_3 , unsigned V_326 ,
void T_12 * V_221 )
{
struct V_327 V_328 ;
struct V_327 T_12 * V_261 ;
struct V_123 V_124 ;
if ( F_87 ( V_326 ) != sizeof( struct V_327 ) )
return - V_175 ;
V_261 = (struct V_327 T_12 * ) V_221 ;
if ( F_42 ( & V_328 , ( char T_12 * ) V_221 , sizeof( V_328 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_262 . V_101 = V_328 . V_262 . V_101 ;
V_124 . V_262 . V_228 = V_328 . V_262 . V_228 ;
V_124 . V_262 . V_263 = V_328 . V_262 . V_263 ;
V_124 . V_155 = V_328 . V_155 ;
V_124 . V_147 = V_328 . V_147 ;
V_124 . V_178 = V_328 . V_178 ;
V_124 . V_177 = V_328 . V_177 ;
V_124 . V_214 = V_328 . V_214 ;
V_124 . V_173 = V_328 . V_173 ;
V_124 . V_149 = F_88 ( V_328 . V_149 ) ;
V_124 . V_212 = F_88 ( V_328 . V_212 ) ;
V_124 . V_183 = F_88 ( V_328 . V_183 ) ;
V_124 . V_215 = F_88 ( V_328 . V_215 ) ;
return F_38 ( V_3 , V_124 , & V_261 -> V_151 ) ;
}
static long
F_89 ( struct V_117 * V_117 , unsigned int V_326 , void T_12 * V_221 ,
T_6 V_329 )
{
struct V_2 * V_3 ;
struct V_264 V_330 ;
enum V_331 V_332 ;
long V_165 = - V_175 ;
if ( F_42 ( & V_330 , ( char T_12 * ) V_221 ,
sizeof( struct V_264 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
return - V_169 ;
}
if ( F_22 ( V_330 . V_101 , & V_3 ) == - 1 || ! V_3 )
return - V_333 ;
F_90 ( & V_3 -> V_334 ) ;
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 || V_3 -> V_335 ) {
V_165 = - V_167 ;
goto V_336;
}
V_332 = ( V_117 -> V_337 & V_338 ) ? V_339 : V_340 ;
if ( V_332 == V_339 ) {
if ( ! F_91 ( & V_3 -> V_65 . V_341 ) ) {
V_165 = - V_167 ;
goto V_336;
}
} else if ( F_92 ( & V_3 -> V_65 . V_341 ) ) {
V_165 = - V_342 ;
goto V_336;
}
switch ( V_326 ) {
case V_343 :
if ( F_87 ( V_326 ) == sizeof( struct V_222 ) )
V_165 = F_61 ( V_3 , V_221 ) ;
break;
#ifdef F_93
case V_344 :
#endif
case V_345 :
{
struct V_123 T_12 * V_261 ;
struct V_123 V_124 ;
#ifdef F_93
if ( V_329 ) {
V_165 = F_86 ( V_3 , V_326 , V_221 ) ;
break;
}
#endif
if ( F_42 ( & V_124 , V_221 , sizeof( V_124 ) ) ) {
F_6 ( V_150 L_34 ,
__FILE__ , __LINE__ , V_100 ) ;
V_165 = - V_169 ;
break;
}
if ( F_87 ( V_326 ) == sizeof( struct V_123 ) ) {
V_261 = V_221 ;
V_165 = F_38 ( V_3 , V_124 , & V_261 -> V_151 ) ;
}
break;
}
case V_346 :
if ( F_87 ( V_326 ) == sizeof( struct V_252 ) )
V_165 = F_65 ( V_3 , V_221 ) ;
break;
case V_347 :
if ( F_87 ( V_326 ) == sizeof( struct V_256 ) )
V_165 = F_66 ( V_3 , V_221 ) ;
break;
case V_348 :
V_165 = F_69 ( V_3 , V_221 ) ;
break;
case V_349 :
if ( F_87 ( V_326 ) == sizeof( struct V_266 ) )
V_165 = F_70 ( V_3 , V_221 ) ;
break;
case V_350 :
if ( F_87 ( V_326 ) == sizeof( struct V_271 ) )
V_165 = F_74 ( V_3 , V_221 ) ;
break;
case V_351 :
if ( F_87 ( V_326 ) == sizeof( struct V_288 ) )
V_165 = F_81 ( V_3 , V_221 ) ;
break;
case V_352 :
if ( F_87 ( V_326 ) == sizeof( struct V_309 ) )
V_165 = F_82 ( V_3 , V_221 ) ;
break;
case V_353 :
if ( F_87 ( V_326 ) == sizeof( struct V_310 ) )
V_165 = F_83 ( V_3 , V_221 ) ;
break;
case V_354 :
if ( F_87 ( V_326 ) == sizeof( struct V_317 ) )
V_165 = F_84 ( V_3 , V_221 ) ;
break;
case V_355 :
if ( F_87 ( V_326 ) == sizeof( struct V_318 ) )
V_165 = F_85 ( V_3 , V_221 ) ;
break;
default:
F_36 ( V_3 , F_6 ( V_45
L_96 , V_3 -> V_46 , V_326 ) ) ;
break;
}
F_94 ( & V_3 -> V_65 . V_341 ) ;
V_336:
F_94 ( & V_3 -> V_334 ) ;
return V_165 ;
}
static long
F_95 ( struct V_117 * V_117 , unsigned int V_326 , unsigned long V_221 )
{
long V_165 ;
V_165 = F_89 ( V_117 , V_326 , ( void T_12 * ) V_221 , 0 ) ;
return V_165 ;
}
static long
F_96 ( struct V_117 * V_117 , unsigned V_326 , unsigned long V_221 )
{
long V_165 ;
V_165 = F_89 ( V_117 , V_326 , ( void T_12 * ) V_221 , 1 ) ;
return V_165 ;
}
static T_22
F_97 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_97 ,
( V_3 -> V_180 . V_244 . V_245 & 0xFF000000 ) >> 24 ,
( V_3 -> V_180 . V_244 . V_245 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_180 . V_244 . V_245 & 0x0000FF00 ) >> 8 ,
V_3 -> V_180 . V_244 . V_245 & 0x000000FF ) ;
}
static T_22
F_100 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
T_7 V_363 = F_7 ( V_3 -> V_250 . V_251 ) ;
return snprintf ( V_359 , V_362 , L_97 ,
( V_363 & 0xFF000000 ) >> 24 ,
( V_363 & 0x00FF0000 ) >> 16 ,
( V_363 & 0x0000FF00 ) >> 8 ,
V_363 & 0x000000FF ) ;
}
static T_22
F_101 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_98 ,
V_3 -> V_180 . V_364 , V_3 -> V_180 . V_365 >> 8 ) ;
}
static T_22
F_102 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , 16 , L_57 , V_3 -> V_366 . V_367 ) ;
}
static T_22
F_103 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_99 ,
F_7 ( V_3 -> V_368 . V_369 . V_245 ) ) ;
}
static T_22
F_104 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_99 ,
F_7 ( V_3 -> V_368 . V_370 . V_245 ) ) ;
}
static T_22
F_105 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , 16 , L_57 , V_3 -> V_366 . V_371 ) ;
}
static T_22
F_106 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , 16 , L_57 , V_3 -> V_366 . V_372 ) ;
}
static T_22
F_107 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , 16 , L_57 , V_3 -> V_366 . V_373 ) ;
}
static T_22
F_108 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_100 , V_3 -> V_374 ) ;
}
static T_22
F_109 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_100 , V_3 -> V_375 ) ;
}
static T_22
F_110 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_100 , V_3 -> V_180 . V_376 ) ;
}
static T_22
F_111 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_101 ,
( unsigned long long ) V_3 -> V_377 . V_54 ) ;
}
static T_22
F_112 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_99 , V_3 -> V_13 ) ;
}
static T_22
F_113 ( struct V_141 * V_356 , struct V_357 * V_358 ,
const char * V_359 , T_15 V_378 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
int V_379 = 0 ;
if ( sscanf ( V_359 , L_102 , & V_379 ) != 1 )
return - V_175 ;
V_3 -> V_13 = V_379 ;
F_6 ( V_45 L_103 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_359 ) ;
}
static T_22
F_114 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_104 , V_3 -> V_380 ) ;
}
static T_22
F_115 ( struct V_141 * V_356 ,
struct V_357 * V_358 , const char * V_359 , T_15 V_378 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
int V_379 = 0 ;
if ( sscanf ( V_359 , L_105 , & V_379 ) != 1 )
return - V_175 ;
V_3 -> V_380 = V_379 ;
F_6 ( V_45 L_106 , V_3 -> V_46 ,
V_3 -> V_380 ) ;
return strlen ( V_359 ) ;
}
static T_22
F_116 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
return snprintf ( V_359 , V_362 , L_107 , V_3 -> V_381 ) ;
}
static T_22
F_117 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
T_6 V_382 ;
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
if ( ( V_3 -> V_180 . V_282 &
V_383 ) && V_3 -> V_384 )
V_382 = V_3 -> V_382 ;
else
V_382 = 1 ;
return snprintf ( V_359 , V_362 , L_104 , V_382 ) ;
}
static T_22
F_118 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
T_23 * V_385 = NULL ;
T_24 V_10 ;
T_1 V_386 = 0 ;
T_1 V_154 ;
int V_64 ;
T_22 V_273 = 0 ;
if ( ! V_3 -> V_223 ) {
F_6 ( V_99 L_108\
L_109 , V_3 -> V_46 , V_100 ) ;
goto V_7;
}
F_90 ( & V_3 -> V_334 ) ;
if ( V_3 -> V_269 || V_3 -> V_335 ) {
F_94 ( & V_3 -> V_334 ) ;
return 0 ;
}
V_64 = F_119 ( T_23 , V_387 ) + ( sizeof( T_1 ) * 36 ) ;
V_385 = F_41 ( V_64 , V_171 ) ;
if ( ! V_385 ) {
F_6 ( V_99 L_64\
L_110 , V_3 -> V_46 , V_100 , V_64 ) ;
goto V_7;
}
if ( F_120 ( V_3 , & V_10 , V_385 , V_64 ) !=
0 ) {
F_6 ( V_99
L_111 , V_3 -> V_46 ,
V_100 ) ;
goto V_7;
}
V_154 = F_5 ( V_10 . V_47 ) & V_209 ;
if ( V_154 != V_307 ) {
F_6 ( V_99 L_112\
L_113 , V_3 -> V_46 , V_100 , V_154 ) ;
goto V_7;
}
if ( V_385 -> V_388 < 25 ) {
F_6 ( V_99 L_114\
L_115 , V_3 -> V_46 , V_100 ,
V_385 -> V_388 ) ;
goto V_7;
}
V_386 = F_5 ( V_385 -> V_387 [ 24 ] ) ;
V_273 = snprintf ( V_359 , V_362 , L_104 , ( V_386 & 1 ) ) ;
V_7:
F_60 ( V_385 ) ;
F_94 ( & V_3 -> V_334 ) ;
return V_273 ;
}
static T_22
F_121 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
T_7 V_389 = 0 ;
struct V_390 * V_290 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_6 ( V_99 L_116
L_76 , V_3 -> V_46 , V_100 ) ;
return 0 ;
}
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) {
F_6 ( V_99 L_116
L_76 , V_3 -> V_46 , V_100 ) ;
return 0 ;
}
V_290 = (struct V_390 * )
V_3 -> V_295 [ V_281 ] ;
if ( ( F_7 ( V_290 -> V_391 ) == 0x00000000 ||
F_7 ( V_290 -> V_391 ) == 0x01000000 ) &&
F_7 ( V_290 -> V_392 ) == 0x4742444c )
V_389 = F_7 ( V_290 -> V_393 ) ;
V_3 -> V_394 = V_389 ;
return snprintf ( V_359 , V_362 , L_104 , V_389 ) ;
}
static T_22
F_122 ( struct V_141 * V_356 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
void * V_290 ;
T_7 V_389 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_6 ( V_99 L_116
L_76 , V_3 -> V_46 , V_100 ) ;
return 0 ;
}
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) {
F_6 ( V_99 L_116
L_76 , V_3 -> V_46 , V_100 ) ;
return 0 ;
}
if ( V_3 -> V_395 > V_3 -> V_394 )
return 0 ;
V_389 = V_3 -> V_394 - V_3 -> V_395 ;
V_389 = ( V_389 > V_362 ) ? V_362 : V_389 ;
V_290 = V_3 -> V_295 [ 0 ] + V_3 -> V_395 ;
memcpy ( V_359 , V_290 , V_389 ) ;
return V_389 ;
}
static T_22
F_123 ( struct V_141 * V_356 , struct V_357 * V_358 ,
const char * V_359 , T_15 V_378 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
int V_379 = 0 ;
if ( sscanf ( V_359 , L_105 , & V_379 ) != 1 )
return - V_175 ;
V_3 -> V_395 = V_379 ;
return strlen ( V_359 ) ;
}
static T_22
F_124 ( struct V_141 * V_356 ,
struct V_357 * V_358 , char * V_359 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
if ( ( ! V_3 -> V_295 [ V_281 ] ) ||
( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) )
return snprintf ( V_359 , V_362 , L_117 ) ;
else if ( ( V_3 -> V_109 [ V_281 ] &
V_111 ) )
return snprintf ( V_359 , V_362 , L_118 ) ;
else
return snprintf ( V_359 , V_362 , L_119 ) ;
}
static T_22
F_125 ( struct V_141 * V_356 ,
struct V_357 * V_358 , const char * V_359 , T_15 V_378 )
{
struct V_360 * V_361 = F_98 ( V_356 ) ;
struct V_2 * V_3 = F_99 ( V_361 ) ;
char V_396 [ 10 ] = L_120 ;
struct V_288 V_289 ;
T_6 V_106 = 0 ;
if ( sscanf ( V_359 , L_121 , V_396 ) != 1 )
return - V_175 ;
if ( ! strcmp ( V_396 , L_122 ) ) {
if ( ( V_3 -> V_295 [ V_281 ] ) &&
( V_3 -> V_109 [ V_281 ] &
V_110 ) &&
( ( V_3 -> V_109 [ V_281 ] &
V_111 ) == 0 ) )
goto V_7;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
F_6 ( V_45 L_123 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
V_3 -> V_109 [ V_281 ] = 0 ;
F_76 ( V_3 , & V_289 ) ;
} else if ( ! strcmp ( V_396 , L_124 ) ) {
if ( ! V_3 -> V_295 [ V_281 ] )
goto V_7;
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 )
goto V_7;
if ( ( V_3 -> V_109 [ V_281 ] &
V_111 ) )
goto V_7;
F_6 ( V_45 L_125 ,
V_3 -> V_46 ) ;
F_27 ( V_3 , V_281 , & V_106 ) ;
}
V_7:
return strlen ( V_359 ) ;
}
static T_22
F_126 ( struct V_141 * V_397 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_398 * V_399 = F_127 ( V_397 ) ;
struct V_129 * V_400 = V_399 -> V_142 ;
return snprintf ( V_359 , V_362 , L_101 ,
( unsigned long long ) V_400 -> V_143 -> V_54 ) ;
}
static T_22
F_128 ( struct V_141 * V_397 , struct V_357 * V_358 ,
char * V_359 )
{
struct V_398 * V_399 = F_127 ( V_397 ) ;
struct V_129 * V_400 = V_399 -> V_142 ;
return snprintf ( V_359 , V_362 , L_126 ,
V_400 -> V_143 -> V_4 ) ;
}
void
F_129 ( void )
{
V_96 = NULL ;
if ( F_130 ( & V_401 ) < 0 )
F_6 ( V_150 L_127 ,
V_247 , V_402 ) ;
F_131 ( & V_95 ) ;
}
void
F_132 ( void )
{
struct V_2 * V_3 ;
int V_78 ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
for ( V_78 = 0 ; V_78 < V_108 ; V_78 ++ ) {
if ( ! V_3 -> V_295 [ V_78 ] )
continue;
F_59 ( V_3 -> V_182 , V_3 -> V_301 [ V_78 ] ,
V_3 -> V_295 [ V_78 ] , V_3 -> V_300 [ V_78 ] ) ;
V_3 -> V_295 [ V_78 ] = NULL ;
V_3 -> V_109 [ V_78 ] = 0 ;
}
F_60 ( V_3 -> V_80 ) ;
}
F_133 ( & V_401 ) ;
}
