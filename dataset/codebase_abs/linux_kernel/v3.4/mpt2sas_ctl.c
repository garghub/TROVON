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
T_6
F_20 ( struct V_2 * V_3 , T_6 V_60 ,
T_7 V_61 )
{
T_8 * V_10 ;
V_10 = F_11 ( V_3 , V_61 ) ;
F_17 ( V_3 , V_10 ) ;
return 1 ;
}
static int
F_21 ( int V_99 , struct V_2 * * V_100 )
{
struct V_2 * V_3 ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
if ( V_3 -> V_101 != V_99 )
continue;
* V_100 = V_3 ;
return V_99 ;
}
* V_100 = NULL ;
return - 1 ;
}
void
F_22 ( struct V_2 * V_3 , int V_102 )
{
int V_78 ;
T_6 V_103 ;
switch ( V_102 ) {
case V_104 :
F_23 ( V_3 , F_6 ( V_45 L_26
L_27 , V_3 -> V_46 , V_105 ) ) ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ! ( V_3 -> V_107 [ V_78 ] &
V_108 ) )
continue;
if ( ( V_3 -> V_107 [ V_78 ] &
V_109 ) )
continue;
F_24 ( V_3 , V_78 , & V_103 ) ;
}
break;
case V_110 :
F_23 ( V_3 , F_6 ( V_45 L_26
L_28 , V_3 -> V_46 , V_105 ) ) ;
if ( V_3 -> V_65 . V_66 & V_75 ) {
V_3 -> V_65 . V_66 |= V_111 ;
F_25 ( V_3 , V_3 -> V_65 . V_8 ) ;
F_15 ( & V_3 -> V_65 . V_76 ) ;
}
break;
case V_112 :
F_23 ( V_3 , F_6 ( V_45 L_26
L_29 , V_3 -> V_46 , V_105 ) ) ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ! ( V_3 -> V_107 [ V_78 ] &
V_108 ) )
continue;
if ( ( V_3 -> V_107 [ V_78 ] &
V_109 ) )
continue;
V_3 -> V_107 [ V_78 ] |=
V_113 ;
}
break;
}
}
static int
F_26 ( int V_114 , struct V_115 * V_116 , int V_117 )
{
return F_27 ( V_114 , V_116 , V_117 , & V_96 ) ;
}
static int
F_28 ( struct V_118 * V_118 , struct V_115 * V_116 )
{
return F_27 ( - 1 , V_116 , 0 , & V_96 ) ;
}
static unsigned int
F_29 ( struct V_115 * V_116 , T_9 * V_119 )
{
struct V_2 * V_3 ;
F_30 ( V_116 , & V_95 , V_119 ) ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
if ( V_3 -> V_94 )
return V_120 | V_121 ;
}
return 0 ;
}
static int
F_31 ( struct V_2 * V_3 , struct V_122 * V_123 ,
T_10 * V_124 )
{
T_6 V_125 = 0 ;
T_1 V_78 ;
T_1 V_4 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
unsigned long V_50 ;
T_11 * V_130 ;
T_7 V_64 ;
T_7 V_131 ;
char * V_12 = NULL ;
if ( V_124 -> V_132 == V_133 )
V_12 = L_30 ;
else if ( V_124 -> V_132 == V_134 )
V_12 = L_31 ;
else
return 0 ;
V_131 = F_32 ( (struct V_135 * ) V_124 -> V_136 ) ;
V_4 = F_5 ( V_124 -> V_52 ) ;
F_8 ( & V_3 -> V_137 , V_50 ) ;
for ( V_78 = V_3 -> V_138 ; V_78 && ! V_125 ; V_78 -- ) {
V_127 = V_3 -> V_139 [ V_78 - 1 ] . V_127 ;
if ( V_127 == NULL || V_127 -> V_140 == NULL ||
V_127 -> V_140 -> V_141 == NULL )
continue;
if ( V_131 != V_127 -> V_140 -> V_131 )
continue;
V_129 = V_127 -> V_140 -> V_141 ;
if ( V_129 -> V_142 == NULL )
continue;
if ( V_129 -> V_142 -> V_4 != V_4 )
continue;
V_124 -> V_143 = F_33 ( V_3 -> V_139 [ V_78 - 1 ] . V_8 ) ;
V_125 = 1 ;
}
F_9 ( & V_3 -> V_137 , V_50 ) ;
if ( ! V_125 ) {
F_34 ( V_3 , F_6 ( V_45 L_26
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_124 -> V_52 ) , V_131 ) ) ;
V_130 = V_3 -> V_65 . V_61 ;
V_130 -> V_52 = V_124 -> V_52 ;
V_130 -> V_15 = V_23 ;
V_130 -> V_132 = V_124 -> V_132 ;
V_130 -> V_69 = sizeof( T_11 ) / 4 ;
V_130 -> V_144 = V_124 -> V_144 ;
V_130 -> V_145 = V_124 -> V_145 ;
V_64 = F_12 ( T_7 , V_123 -> V_146 , V_3 -> V_147 ) ;
if ( F_35 ( V_123 -> V_148 , V_3 -> V_65 . V_61 ,
V_64 ) )
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
return 1 ;
}
F_34 ( V_3 , F_6 ( V_45 L_26
L_34 , V_3 -> V_46 ,
V_12 , F_5 ( V_124 -> V_52 ) , V_131 ,
F_5 ( V_124 -> V_143 ) ) ) ;
return 0 ;
}
static long
F_36 ( struct V_2 * V_3 ,
struct V_122 V_123 , void T_12 * V_150 , enum V_151 V_152 )
{
T_13 * V_11 = NULL , * V_153 ;
T_2 * V_10 ;
T_7 V_154 ;
T_1 V_155 ;
T_1 V_8 ;
unsigned long V_156 , V_157 ;
T_6 V_103 ;
T_7 V_64 ;
void * V_158 ;
void * V_159 = NULL ;
T_14 V_160 ;
T_15 V_161 = 0 ;
void * V_162 = NULL ;
T_14 V_163 ;
T_15 V_164 = 0 ;
T_7 V_165 ;
long V_166 ;
T_1 V_167 ;
V_103 = 0 ;
if ( V_152 == V_168 && ! F_37 ( & V_3 -> V_65 . V_169 ) )
return - V_170 ;
else if ( F_38 ( & V_3 -> V_65 . V_169 ) )
return - V_171 ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_172 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_166 = - V_170 ;
goto V_7;
}
V_167 = 0 ;
V_154 = F_39 ( V_3 , 1 ) ;
while ( V_154 != V_173 ) {
if ( V_167 ++ == 10 ) {
F_6 ( V_172
L_36 ,
V_3 -> V_46 , V_105 ) ;
V_166 = - V_174 ;
goto V_7;
}
F_40 ( 1 ) ;
V_154 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45 L_37
L_38 , V_3 -> V_46 ,
V_105 , V_167 ) ;
}
if ( V_167 )
F_6 ( V_45 L_39 ,
V_3 -> V_46 , V_105 ) ;
V_11 = F_41 ( V_3 -> V_175 , V_176 ) ;
if ( ! V_11 ) {
F_6 ( V_172 L_40
L_41 , V_3 -> V_46 , V_105 ) ;
V_166 = - V_177 ;
goto V_7;
}
if ( V_123 . V_178 * 4 > V_3 -> V_175 ||
V_123 . V_178 > ( V_179 / 4 ) ) {
V_166 = - V_180 ;
goto V_7;
}
if ( F_42 ( V_11 , V_150 , V_123 . V_178 * 4 ) ) {
F_6 ( V_149 L_33 , __FILE__ , __LINE__ ,
V_105 ) ;
V_166 = - V_174 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_181 ) ;
if ( ! V_8 ) {
F_6 ( V_172 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_166 = - V_170 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_181 , NULL ) ;
if ( ! V_8 ) {
F_6 ( V_172 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_166 = - V_170 ;
goto V_7;
}
}
V_166 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_153 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_153 , V_11 , V_123 . V_178 * 4 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_161 = V_123 . V_182 ;
V_164 = V_123 . V_183 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_184 ) ||
F_5 ( V_11 -> V_184 ) >
V_3 -> V_185 . V_186 ) {
V_166 = - V_180 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_161 ) {
V_159 = F_45 ( V_3 -> V_187 , V_161 ,
& V_160 ) ;
if ( ! V_159 ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_177 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_159 , V_123 . V_188 ,
V_161 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_174 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_164 ) {
V_162 = F_45 ( V_3 -> V_187 , V_164 ,
& V_163 ) ;
if ( ! V_162 ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_177 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_158 = ( void * ) V_153 + ( V_123 . V_178 * 4 ) ;
if ( ! V_161 && ! V_164 ) {
F_46 ( V_3 , V_158 ) ;
} else if ( V_161 && V_164 ) {
V_165 = ( V_189 |
V_190 | V_191 ) ;
V_165 = V_165 << V_192 ;
V_3 -> V_193 ( V_158 , V_165 |
V_161 , V_160 ) ;
V_158 += V_3 -> V_194 ;
V_165 = ( V_189 |
V_195 | V_190 |
V_196 ) ;
V_165 = V_165 << V_192 ;
V_3 -> V_193 ( V_158 , V_165 |
V_164 , V_163 ) ;
} else if ( V_161 ) {
V_165 = ( V_189 |
V_195 | V_190 |
V_196 | V_191 ) ;
V_165 = V_165 << V_192 ;
V_3 -> V_193 ( V_158 , V_165 |
V_161 , V_160 ) ;
} else if ( V_164 ) {
V_165 = ( V_189 |
V_195 | V_190 |
V_196 ) ;
V_165 = V_165 << V_192 ;
V_3 -> V_193 ( V_158 , V_165 |
V_164 , V_163 ) ;
}
#ifdef F_14
F_3 ( V_3 , V_8 , L_43 , NULL ) ;
#endif
F_47 ( & V_3 -> V_65 . V_76 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_197 =
( T_4 * ) V_153 ;
V_197 -> V_198 = V_72 ;
V_197 -> V_199 =
F_48 ( V_3 , V_8 ) ;
memset ( V_3 -> V_65 . V_74 , 0 , V_72 ) ;
if ( V_11 -> V_15 == V_16 )
F_49 ( V_3 , V_8 ,
F_5 ( V_11 -> V_184 ) ) ;
else
F_50 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_124 =
( T_10 * ) V_153 ;
F_23 ( V_3 , F_6 ( V_45 L_44
L_45 , V_3 -> V_46 ,
F_5 ( V_124 -> V_52 ) , V_124 -> V_132 ) ) ;
if ( V_124 -> V_132 ==
V_133 ||
V_124 -> V_132 ==
V_134 ) {
if ( F_31 ( V_3 , & V_123 , V_124 ) ) {
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_51 ( V_3 , F_5 (
V_124 -> V_52 ) ) ;
F_52 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_200 =
( T_16 * ) V_11 ;
T_6 * V_91 ;
V_200 -> V_201 = 0xFF ;
if ( V_200 -> V_202 &
V_203 )
V_91 = ( T_6 * ) & V_200 -> V_204 ;
else
V_91 = V_159 ;
if ( V_91 [ 1 ] == 0x91 && ( V_91 [ 10 ] == 1 || V_91 [ 10 ] == 2 ) ) {
V_3 -> V_205 = 1 ;
V_3 -> V_206 = 1 ;
}
F_50 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_17 * V_207 =
( T_17 * ) V_11 ;
if ( V_207 -> V_208 == V_209
|| V_207 -> V_208 ==
V_210 ) {
V_3 -> V_205 = 1 ;
V_3 -> V_206 = 1 ;
}
F_50 ( V_3 , V_8 ) ;
break;
}
default:
F_50 ( V_3 , V_8 ) ;
break;
}
if ( V_123 . V_156 < V_211 )
V_156 = V_211 ;
else
V_156 = V_123 . V_156 ;
V_157 = F_53 ( & V_3 -> V_65 . V_76 ,
V_156 * V_212 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_124 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_124 -> V_52 ) ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_205 ) {
V_3 -> V_205 = 0 ;
V_3 -> V_206 = 0 ;
}
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_172 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_55 ( V_11 , V_123 . V_178 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_213;
}
V_10 = V_3 -> V_65 . V_61 ;
V_155 = F_5 ( V_10 -> V_47 ) & V_214 ;
#ifdef F_14
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_215 ) ) {
T_11 * V_130 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_44
L_47
L_48 , V_3 -> V_46 ,
F_5 ( V_130 -> V_47 ) ,
F_7 ( V_130 -> V_48 ) ,
F_7 ( V_130 -> V_216 ) ) ;
}
#endif
if ( V_164 ) {
if ( F_35 ( V_123 . V_217 , V_162 ,
V_164 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_218 ;
goto V_7;
}
}
if ( V_123 . V_146 ) {
V_64 = F_12 ( T_7 , V_123 . V_146 , V_3 -> V_147 ) ;
if ( F_35 ( V_123 . V_148 , V_3 -> V_65 . V_61 ,
V_64 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_218 ;
goto V_7;
}
}
if ( V_123 . V_219 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_64 = F_12 ( T_7 , V_123 . V_219 , V_72 ) ;
if ( F_35 ( V_123 . V_220 ,
V_3 -> V_65 . V_74 , V_64 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_166 = - V_218 ;
goto V_7;
}
}
V_213:
if ( V_103 ) {
V_166 = - V_218 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ) ) {
F_6 ( V_45 L_49
L_50 , V_3 -> V_46 ,
F_5 ( V_11 -> V_184 ) ) ;
F_56 ( V_3 ) ;
F_57 ( V_3 ,
F_5 ( V_11 -> V_184 ) , 0 , 0 ,
0 , V_221 , 0 , 10 ,
0 , V_222 ) ;
V_3 -> V_223 . V_66 = V_67 ;
} else
F_58 ( V_3 , V_224 ,
V_225 ) ;
}
V_7:
if ( V_162 )
F_59 ( V_3 -> V_187 , V_164 , V_162 ,
V_163 ) ;
if ( V_159 )
F_59 ( V_3 -> V_187 , V_161 , V_159 ,
V_160 ) ;
F_60 ( V_11 ) ;
V_3 -> V_65 . V_66 = V_67 ;
F_61 ( & V_3 -> V_65 . V_169 ) ;
return V_166 ;
}
static long
F_62 ( void T_12 * V_226 )
{
struct V_227 V_123 ;
struct V_2 * V_3 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
if ( V_3 -> V_230 )
V_123 . V_231 = V_232 ;
else
V_123 . V_231 = V_233 ;
if ( V_3 -> V_234 )
V_123 . V_235 = V_3 -> V_234 [ 0 ] . V_236 ;
V_123 . V_237 = V_3 -> V_187 -> V_238 ;
V_123 . V_239 = V_3 -> V_187 -> V_140 ;
V_123 . V_240 = V_3 -> V_187 -> V_240 ;
V_123 . V_241 = V_3 -> V_187 -> V_241 ;
V_123 . V_242 . V_243 . V_244 . V_245 = V_3 -> V_187 -> V_245 -> V_246 ;
V_123 . V_242 . V_243 . V_244 . V_140 = F_63 ( V_3 -> V_187 -> V_247 ) ;
V_123 . V_242 . V_243 . V_244 . V_248 = F_64 ( V_3 -> V_187 -> V_247 ) ;
V_123 . V_242 . V_249 = F_65 ( V_3 -> V_187 -> V_245 ) ;
V_123 . V_250 = V_3 -> V_185 . V_251 . V_252 ;
strcpy ( V_123 . V_253 , V_254 ) ;
strcat ( V_123 . V_253 , L_52 ) ;
strcat ( V_123 . V_253 , V_255 ) ;
V_123 . V_256 = F_7 ( V_3 -> V_257 . V_258 ) ;
if ( F_35 ( V_226 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
return 0 ;
}
static long
F_66 ( void T_12 * V_226 )
{
struct V_259 V_123 ;
struct V_2 * V_3 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_123 . V_260 = V_87 ;
memcpy ( V_123 . V_261 , V_3 -> V_81 ,
V_262 * sizeof( T_7 ) ) ;
if ( F_35 ( V_226 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
return 0 ;
}
static long
F_67 ( void T_12 * V_226 )
{
struct V_263 V_123 ;
struct V_2 * V_3 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_80 )
return 0 ;
memcpy ( V_3 -> V_81 , V_123 . V_261 ,
V_262 * sizeof( T_7 ) ) ;
F_68 ( V_3 , V_3 -> V_81 ) ;
V_3 -> V_86 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_80 = F_69 ( V_87 ,
sizeof( struct V_82 ) , V_176 ) ;
if ( ! V_3 -> V_80 ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_177 ;
}
return 0 ;
}
static long
F_70 ( void T_12 * V_226 )
{
struct V_264 V_123 ;
struct V_2 * V_3 ;
T_7 V_265 , V_266 , V_267 ;
struct V_264 T_12 * V_268 = V_226 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_265 = V_123 . V_228 . V_269 -
sizeof( struct V_270 ) ;
V_266 = V_265 / sizeof( struct V_82 ) ;
V_267 = F_12 ( T_7 , V_87 , V_266 ) ;
if ( ! V_267 || ! V_3 -> V_80 )
return - V_218 ;
V_265 = V_267 * sizeof( struct V_82 ) ;
if ( F_35 ( V_268 -> V_271 , V_3 -> V_80 , V_265 ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
V_3 -> V_94 = 0 ;
return 0 ;
}
static long
F_71 ( void T_12 * V_226 )
{
struct V_272 V_123 ;
struct V_2 * V_3 ;
int V_273 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
if ( V_3 -> V_274 || V_3 -> V_275 ||
V_3 -> V_276 )
return - V_170 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_273 = F_58 ( V_3 , V_224 ,
V_225 ) ;
F_6 ( V_45 L_53 ,
V_3 -> V_46 , ( ( ! V_273 ) ? L_54 : L_55 ) ) ;
return 0 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_277 * V_278 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_279 = 0 ;
if ( F_73 ( & V_3 -> V_280 ) )
return V_279 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_278 -> V_245 == 0xFFFFFFFF && V_278 -> V_101 == 0xFFFFFFFF &&
V_278 -> V_4 == V_5 -> V_4 ) {
V_278 -> V_245 = V_5 -> V_281 ;
V_278 -> V_101 = V_5 -> V_101 ;
V_279 = 1 ;
goto V_7;
} else if ( V_278 -> V_245 == V_5 -> V_281 && V_278 -> V_101 ==
V_5 -> V_101 && V_278 -> V_4 == 0xFFFF ) {
V_278 -> V_4 = V_5 -> V_4 ;
V_279 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_51 , V_50 ) ;
return V_279 ;
}
static int
F_74 ( struct V_2 * V_3 ,
struct V_277 * V_278 )
{
struct V_282 * V_283 ;
unsigned long V_50 ;
int V_279 = 0 ;
if ( F_73 ( & V_3 -> V_284 ) )
return V_279 ;
F_8 ( & V_3 -> V_285 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_278 -> V_245 == 0xFFFFFFFF && V_278 -> V_101 == 0xFFFFFFFF &&
V_278 -> V_4 == V_283 -> V_4 ) {
V_278 -> V_245 = V_283 -> V_281 ;
V_278 -> V_101 = V_283 -> V_101 ;
V_279 = 1 ;
goto V_7;
} else if ( V_278 -> V_245 == V_283 -> V_281 && V_278 -> V_101 ==
V_283 -> V_101 && V_278 -> V_4 == 0xFFFF ) {
V_278 -> V_4 = V_283 -> V_4 ;
V_279 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_285 , V_50 ) ;
return V_279 ;
}
static long
F_75 ( void T_12 * V_226 )
{
struct V_277 V_123 ;
struct V_2 * V_3 ;
int V_279 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = F_72 ( V_3 , & V_123 ) ;
if ( ! V_279 )
F_74 ( V_3 , & V_123 ) ;
if ( F_35 ( V_226 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
return 0 ;
}
static T_6
F_76 ( struct V_2 * V_3 , T_6 V_286 )
{
T_6 V_279 = 0 ;
switch ( V_286 ) {
case V_287 :
if ( V_3 -> V_185 . V_288 &
V_289 )
V_279 = 1 ;
break;
case V_290 :
if ( V_3 -> V_185 . V_288 &
V_291 )
V_279 = 1 ;
break;
case V_292 :
if ( V_3 -> V_185 . V_288 &
V_293 )
V_279 = 1 ;
}
return V_279 ;
}
static long
F_77 ( struct V_2 * V_3 ,
struct V_294 * V_295 )
{
int V_279 , V_78 ;
void * V_296 = NULL ;
T_14 V_297 ;
T_7 V_298 = 0 ;
T_18 * V_11 ;
T_19 * V_10 ;
T_6 V_286 ;
unsigned long V_157 ;
T_1 V_8 ;
T_1 V_155 ;
T_6 V_103 = 0 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_172 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_286 = V_295 -> V_286 ;
if ( ! F_76 ( V_3 , V_286 ) ) {
F_6 ( V_172 L_57
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_299 ;
}
if ( V_3 -> V_107 [ V_286 ] &
V_108 ) {
F_6 ( V_172 L_59
L_60 , V_3 -> V_46 , V_105 ,
V_286 ) ;
return - V_180 ;
}
if ( V_295 -> V_300 % 4 ) {
F_6 ( V_172 L_61
L_62 , V_3 -> V_46 , V_105 ) ;
return - V_180 ;
}
V_8 = F_78 ( V_3 , V_3 -> V_181 ) ;
if ( ! V_8 ) {
F_6 ( V_172 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_279 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_296 = V_3 -> V_301 [ V_286 ] ;
V_298 = V_295 -> V_300 ;
V_3 -> V_302 [ V_286 ] = V_295 -> V_302 ;
V_3 -> V_107 [ V_286 ] = 0 ;
memcpy ( V_3 -> V_303 [ V_286 ] ,
V_295 -> V_303 , V_304 ) ;
V_3 -> V_305 [ V_286 ] = V_295 -> V_305 ;
if ( V_296 ) {
V_297 = V_3 -> V_306 [ V_286 ] ;
if ( V_298 != V_3 -> V_307 [ V_286 ] ) {
F_59 ( V_3 -> V_187 ,
V_3 -> V_307 [ V_286 ] ,
V_296 , V_297 ) ;
V_296 = NULL ;
}
}
if ( V_296 == NULL ) {
V_3 -> V_307 [ V_286 ] = 0 ;
V_3 -> V_306 [ V_286 ] = 0 ;
V_296 = F_45 (
V_3 -> V_187 , V_298 , & V_297 ) ;
if ( V_296 == NULL ) {
F_6 ( V_172 L_63
L_64 ,
V_3 -> V_46 , V_105 , V_298 ) ;
F_25 ( V_3 , V_8 ) ;
return - V_177 ;
}
V_3 -> V_301 [ V_286 ] = V_296 ;
V_3 -> V_307 [ V_286 ] = V_298 ;
V_3 -> V_306 [ V_286 ] = V_297 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_308 = V_295 -> V_286 ;
V_11 -> V_309 = F_79 ( V_295 -> V_305 ) ;
V_11 -> V_310 = F_80 ( V_297 ) ;
V_11 -> V_311 = F_79 ( V_298 ) ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_34 ( V_3 , F_6 ( V_45 L_65
L_66 , V_3 -> V_46 , V_105 , V_296 ,
( unsigned long long ) V_297 ,
F_7 ( V_11 -> V_311 ) ) ) ;
for ( V_78 = 0 ; V_78 < V_304 ; V_78 ++ )
V_11 -> V_312 [ V_78 ] =
F_79 ( V_3 -> V_303 [ V_286 ] [ V_78 ] ) ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_157 = F_53 ( & V_3 -> V_65 . V_76 ,
V_211 * V_212 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_172 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_55 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_213;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_172 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_174 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_155 = F_5 ( V_10 -> V_47 ) & V_214 ;
if ( V_155 == V_313 ) {
V_3 -> V_107 [ V_286 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_155 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_174 ;
}
V_213:
if ( V_103 )
F_58 ( V_3 , V_224 ,
V_225 ) ;
V_7:
if ( V_279 && V_296 )
F_59 ( V_3 -> V_187 , V_298 ,
V_296 , V_297 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_279 ;
}
void
F_81 ( struct V_2 * V_3 , T_6 V_314 )
{
struct V_294 V_295 ;
memset ( & V_295 , 0 , sizeof( struct V_294 ) ) ;
if ( V_314 & 1 ) {
F_6 ( V_45 L_71 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_287 ;
V_295 . V_300 = ( 1024 * 1024 ) ;
V_295 . V_302 = 0x7075900 ;
F_77 ( V_3 , & V_295 ) ;
}
if ( V_314 & 2 ) {
F_6 ( V_45 L_72 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_290 ;
V_295 . V_300 = 2 * ( 1024 * 1024 ) ;
V_295 . V_302 = 0x7075901 ;
F_77 ( V_3 , & V_295 ) ;
}
if ( V_314 & 4 ) {
F_6 ( V_45 L_73 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_292 ;
V_295 . V_300 = 2 * ( 1024 * 1024 ) ;
V_295 . V_302 = 0x7075901 ;
F_77 ( V_3 , & V_295 ) ;
}
}
static long
F_82 ( void T_12 * V_226 , enum V_151 V_152 )
{
struct V_294 V_123 ;
struct V_2 * V_3 ;
long V_279 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
if ( V_152 == V_168 && ! F_37 ( & V_3 -> V_65 . V_169 ) )
return - V_170 ;
else if ( F_38 ( & V_3 -> V_65 . V_169 ) )
return - V_171 ;
V_279 = F_77 ( V_3 , & V_123 ) ;
F_61 ( & V_3 -> V_65 . V_169 ) ;
return V_279 ;
}
static long
F_83 ( void T_12 * V_226 )
{
struct V_315 V_123 ;
struct V_2 * V_3 ;
void * V_296 ;
T_14 V_297 ;
T_7 V_298 ;
T_6 V_286 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_286 = V_123 . V_302 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_286 ) ) {
F_6 ( V_172 L_57
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_107 [ V_286 ] &
V_108 ) == 0 ) {
F_6 ( V_172 L_74
L_75 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_180 ;
}
if ( ( V_3 -> V_107 [ V_286 ] &
V_109 ) == 0 ) {
F_6 ( V_172 L_76
L_77 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_180 ;
}
if ( V_123 . V_302 != V_3 -> V_302 [ V_286 ] ) {
F_6 ( V_172 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_302 ) ;
return - V_180 ;
}
V_296 = V_3 -> V_301 [ V_286 ] ;
if ( ! V_296 ) {
F_6 ( V_172 L_79
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_177 ;
}
V_298 = V_3 -> V_307 [ V_286 ] ;
V_297 = V_3 -> V_306 [ V_286 ] ;
F_59 ( V_3 -> V_187 , V_298 ,
V_296 , V_297 ) ;
V_3 -> V_301 [ V_286 ] = NULL ;
V_3 -> V_107 [ V_286 ] = 0 ;
return 0 ;
}
static long
F_84 ( void T_12 * V_226 )
{
struct V_316 V_123 ;
struct V_2 * V_3 ;
void * V_296 ;
int V_78 ;
T_6 V_286 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_123 . V_317 = 0 ;
V_286 = V_123 . V_286 ;
if ( ! F_76 ( V_3 , V_286 ) ) {
F_6 ( V_172 L_57
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_107 [ V_286 ] &
V_108 ) == 0 ) {
F_6 ( V_172 L_74
L_75 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_180 ;
}
if ( V_123 . V_302 & 0xffffff00 ) {
if ( V_123 . V_302 != V_3 -> V_302 [ V_286 ] ) {
F_6 ( V_172 L_78
L_75 , V_3 -> V_46 , V_105 ,
V_123 . V_302 ) ;
return - V_180 ;
}
}
V_296 = V_3 -> V_301 [ V_286 ] ;
if ( ! V_296 ) {
F_6 ( V_172 L_80
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_177 ;
}
if ( V_3 -> V_107 [ V_286 ] & V_109 )
V_123 . V_317 = ( V_318 |
V_319 ) ;
else
V_123 . V_317 = ( V_318 |
V_319 |
V_320 ) ;
for ( V_78 = 0 ; V_78 < V_304 ; V_78 ++ )
V_123 . V_303 [ V_78 ] =
V_3 -> V_303 [ V_286 ] [ V_78 ] ;
V_123 . V_321 = V_3 -> V_307 [ V_286 ] ;
V_123 . V_322 = 0 ;
V_123 . V_302 = V_3 -> V_302 [ V_286 ] ;
V_123 . V_305 = V_3 -> V_305 [ V_286 ] ;
if ( F_35 ( V_226 , & V_123 , sizeof( struct V_316 ) ) ) {
F_6 ( V_172 L_81
L_82 , V_3 -> V_46 , V_105 , V_226 ) ;
return - V_174 ;
}
return 0 ;
}
static int
F_24 ( struct V_2 * V_3 , T_6 V_286 , T_6 * V_103 )
{
T_20 * V_11 ;
T_21 * V_10 ;
T_1 V_8 ;
T_1 V_155 ;
T_7 V_154 ;
int V_279 ;
unsigned long V_157 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = 0 ;
* V_103 = 0 ;
V_154 = F_39 ( V_3 , 1 ) ;
if ( V_154 != V_173 ) {
F_34 ( V_3 , F_6 ( V_45 L_26
L_83 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = - V_170 ;
goto V_7;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_172 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_181 ) ;
if ( ! V_8 ) {
F_6 ( V_172 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_308 = V_286 ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_157 = F_53 ( & V_3 -> V_65 . V_76 ,
V_211 * V_212 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_172 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_55 ( V_11 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
* V_103 = 1 ;
V_279 = - V_174 ;
goto V_7;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_172 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_174 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_155 = F_5 ( V_10 -> V_47 ) & V_214 ;
if ( V_155 == V_313 ) {
V_3 -> V_107 [ V_286 ] |=
V_109 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_155 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_174 ;
}
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_279 ;
}
static long
F_85 ( void T_12 * V_226 , enum V_151 V_152 )
{
struct V_323 V_123 ;
struct V_2 * V_3 ;
void * V_296 ;
int V_279 ;
T_6 V_286 ;
T_6 V_103 = 0 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_286 = V_123 . V_302 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_286 ) ) {
F_6 ( V_172 L_57
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_299 ;
}
if ( ( V_3 -> V_107 [ V_286 ] &
V_108 ) == 0 ) {
F_6 ( V_172 L_74
L_75 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_180 ;
}
if ( V_123 . V_302 != V_3 -> V_302 [ V_286 ] ) {
F_6 ( V_172 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_302 ) ;
return - V_180 ;
}
if ( V_3 -> V_107 [ V_286 ] &
V_109 ) {
F_6 ( V_172 L_84
L_85 , V_3 -> V_46 , V_105 ,
V_286 ) ;
return 0 ;
}
V_296 = V_3 -> V_301 [ V_286 ] ;
if ( ! V_296 ) {
F_6 ( V_172 L_79
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_177 ;
}
if ( ( V_3 -> V_107 [ V_286 ] &
V_113 ) ) {
V_3 -> V_107 [ V_286 ] |=
V_109 ;
V_3 -> V_107 [ V_286 ] &=
~ V_113 ;
F_6 ( V_172 L_84
L_86 , V_3 -> V_46 , V_105 ,
V_286 ) ;
return 0 ;
}
if ( V_152 == V_168 && ! F_37 ( & V_3 -> V_65 . V_169 ) )
return - V_170 ;
else if ( F_38 ( & V_3 -> V_65 . V_169 ) )
return - V_171 ;
V_279 = F_24 ( V_3 , V_286 , & V_103 ) ;
if ( V_103 )
F_58 ( V_3 , V_224 ,
V_225 ) ;
F_61 ( & V_3 -> V_65 . V_169 ) ;
return V_279 ;
}
static long
F_86 ( void T_12 * V_226 , enum V_151 V_152 )
{
struct V_324 V_123 ;
struct V_324 T_12 * V_268 = V_226 ;
struct V_2 * V_3 ;
void * V_296 , * V_325 ;
T_18 * V_11 ;
T_19 * V_10 ;
int V_279 , V_78 ;
T_6 V_286 ;
unsigned long V_157 , V_326 , V_327 ;
T_1 V_8 ;
T_1 V_155 ;
T_6 V_103 = 0 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_286 = V_123 . V_302 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_286 ) ) {
F_6 ( V_172 L_57
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_299 ;
}
if ( V_123 . V_302 != V_3 -> V_302 [ V_286 ] ) {
F_6 ( V_172 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_302 ) ;
return - V_180 ;
}
V_296 = V_3 -> V_301 [ V_286 ] ;
if ( ! V_296 ) {
F_6 ( V_172 L_80
L_58 , V_3 -> V_46 , V_105 , V_286 ) ;
return - V_177 ;
}
V_326 = V_3 -> V_307 [ V_286 ] ;
if ( ( V_123 . V_328 % 4 ) || ( V_123 . V_329 % 4 ) ) {
F_6 ( V_172 L_87
L_88 , V_3 -> V_46 ,
V_105 ) ;
return - V_180 ;
}
if ( V_123 . V_328 > V_326 )
return - V_180 ;
V_325 = ( void * ) ( V_296 + V_123 . V_328 ) ;
F_34 ( V_3 , F_6 ( V_45 L_89
L_90 , V_3 -> V_46 , V_105 ,
V_325 , V_123 . V_328 , V_123 . V_329 ) ) ;
if ( ( V_325 + V_123 . V_329 < V_325 ) ||
( V_325 + V_123 . V_329 > V_296 + V_326 ) )
V_327 = V_326 - V_123 . V_328 ;
else
V_327 = V_123 . V_329 ;
if ( F_35 ( ( void T_12 * ) V_268 -> V_330 ,
V_325 , V_327 ) ) {
F_6 ( V_172 L_91
L_92 , V_3 -> V_46 ,
V_105 , V_325 ) ;
return - V_174 ;
}
if ( ( V_123 . V_50 & V_331 ) == 0 )
return 0 ;
F_34 ( V_3 , F_6 ( V_45 L_93
L_58 , V_3 -> V_46 , V_105 , V_286 ) ) ;
if ( ( V_3 -> V_107 [ V_286 ] &
V_109 ) == 0 ) {
F_34 ( V_3 , F_6 ( V_45 L_26
L_94 , V_3 -> V_46 ,
V_105 , V_286 ) ) ;
return 0 ;
}
if ( V_152 == V_168 && ! F_37 ( & V_3 -> V_65 . V_169 ) )
return - V_170 ;
else if ( F_38 ( & V_3 -> V_65 . V_169 ) )
return - V_171 ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_172 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_181 ) ;
if ( ! V_8 ) {
F_6 ( V_172 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_170 ;
goto V_7;
}
V_279 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_308 = V_286 ;
V_11 -> V_311 =
F_79 ( V_3 -> V_307 [ V_286 ] ) ;
V_11 -> V_310 =
F_80 ( V_3 -> V_306 [ V_286 ] ) ;
for ( V_78 = 0 ; V_78 < V_304 ; V_78 ++ )
V_11 -> V_312 [ V_78 ] =
F_79 ( V_3 -> V_303 [ V_286 ] [ V_78 ] ) ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_47 ( & V_3 -> V_65 . V_76 ) ;
F_50 ( V_3 , V_8 ) ;
V_157 = F_53 ( & V_3 -> V_65 . V_76 ,
V_211 * V_212 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_172 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_55 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_213;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_172 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_279 = - V_174 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_155 = F_5 ( V_10 -> V_47 ) & V_214 ;
if ( V_155 == V_313 ) {
V_3 -> V_107 [ V_286 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_155 , F_7 ( V_10 -> V_48 ) ) ;
V_279 = - V_174 ;
}
V_213:
if ( V_103 )
F_58 ( V_3 , V_224 ,
V_225 ) ;
V_7:
V_3 -> V_65 . V_66 = V_67 ;
F_61 ( & V_3 -> V_65 . V_169 ) ;
return V_279 ;
}
static long
F_87 ( struct V_115 * V_115 , unsigned int V_332 , void T_12 * V_226 )
{
enum V_151 V_152 ;
long V_166 = - V_180 ;
V_152 = ( V_115 -> V_333 & V_334 ) ? V_168 :
V_335 ;
switch ( V_332 ) {
case V_336 :
if ( F_88 ( V_332 ) == sizeof( struct V_227 ) )
V_166 = F_62 ( V_226 ) ;
break;
case V_337 :
{
struct V_122 V_123 ;
struct V_122 T_12 * V_268 ;
struct V_2 * V_3 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 ||
! V_3 )
return - V_229 ;
if ( V_3 -> V_274 || V_3 -> V_275 ||
V_3 -> V_276 )
return - V_170 ;
if ( F_88 ( V_332 ) == sizeof( struct V_122 ) ) {
V_268 = V_226 ;
V_166 = F_36 ( V_3 , V_123 , & V_268 -> V_150 , V_152 ) ;
}
break;
}
case V_338 :
if ( F_88 ( V_332 ) == sizeof( struct V_259 ) )
V_166 = F_66 ( V_226 ) ;
break;
case V_339 :
if ( F_88 ( V_332 ) == sizeof( struct V_263 ) )
V_166 = F_67 ( V_226 ) ;
break;
case V_340 :
V_166 = F_70 ( V_226 ) ;
break;
case V_341 :
if ( F_88 ( V_332 ) == sizeof( struct V_272 ) )
V_166 = F_71 ( V_226 ) ;
break;
case V_342 :
if ( F_88 ( V_332 ) == sizeof( struct V_277 ) )
V_166 = F_75 ( V_226 ) ;
break;
case V_343 :
if ( F_88 ( V_332 ) == sizeof( struct V_294 ) )
V_166 = F_82 ( V_226 , V_152 ) ;
break;
case V_344 :
if ( F_88 ( V_332 ) == sizeof( struct V_315 ) )
V_166 = F_83 ( V_226 ) ;
break;
case V_345 :
if ( F_88 ( V_332 ) == sizeof( struct V_316 ) )
V_166 = F_84 ( V_226 ) ;
break;
case V_346 :
if ( F_88 ( V_332 ) == sizeof( struct V_323 ) )
V_166 = F_85 ( V_226 , V_152 ) ;
break;
case V_347 :
if ( F_88 ( V_332 ) == sizeof( struct V_324 ) )
V_166 = F_86 ( V_226 , V_152 ) ;
break;
default:
{
struct V_122 V_123 ;
struct V_2 * V_3 ;
if ( F_42 ( & V_123 , V_226 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_123 . V_228 . V_99 , & V_3 ) == - 1 ||
! V_3 )
return - V_229 ;
F_34 ( V_3 , F_6 ( V_45
L_95 , V_3 -> V_46 , V_332 ) ) ;
break;
}
}
return V_166 ;
}
static long
F_89 ( struct V_115 * V_115 , unsigned int V_332 , unsigned long V_226 )
{
long V_166 ;
F_90 ( & V_348 ) ;
V_166 = F_87 ( V_115 , V_332 , ( void T_12 * ) V_226 ) ;
F_61 ( & V_348 ) ;
return V_166 ;
}
static long
F_91 ( struct V_115 * V_115 , unsigned V_332 , unsigned long V_226 )
{
struct V_349 V_350 ;
struct V_349 T_12 * V_268 ;
struct V_122 V_123 ;
struct V_2 * V_3 ;
enum V_151 V_152 ;
if ( F_88 ( V_332 ) != sizeof( struct V_349 ) )
return - V_180 ;
V_268 = (struct V_349 T_12 * ) V_226 ;
if ( F_42 ( & V_350 , ( char T_12 * ) V_226 , sizeof( V_350 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_174 ;
}
if ( F_21 ( V_350 . V_228 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_229 ;
if ( V_3 -> V_274 || V_3 -> V_275 ||
V_3 -> V_276 )
return - V_170 ;
memset ( & V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 . V_228 . V_99 = V_350 . V_228 . V_99 ;
V_123 . V_228 . V_235 = V_350 . V_228 . V_235 ;
V_123 . V_228 . V_269 = V_350 . V_228 . V_269 ;
V_123 . V_156 = V_350 . V_156 ;
V_123 . V_146 = V_350 . V_146 ;
V_123 . V_183 = V_350 . V_183 ;
V_123 . V_182 = V_350 . V_182 ;
V_123 . V_219 = V_350 . V_219 ;
V_123 . V_178 = V_350 . V_178 ;
V_123 . V_148 = F_92 ( V_350 . V_148 ) ;
V_123 . V_217 = F_92 ( V_350 . V_217 ) ;
V_123 . V_188 = F_92 ( V_350 . V_188 ) ;
V_123 . V_220 = F_92 ( V_350 . V_220 ) ;
V_152 = ( V_115 -> V_333 & V_334 ) ? V_168 : V_335 ;
return F_36 ( V_3 , V_123 , & V_268 -> V_150 , V_152 ) ;
}
static long
F_93 ( struct V_115 * V_115 , unsigned V_332 , unsigned long V_226 )
{
long V_166 ;
F_90 ( & V_348 ) ;
if ( V_332 == V_351 )
V_166 = F_91 ( V_115 , V_332 , V_226 ) ;
else
V_166 = F_87 ( V_115 , V_332 , ( void T_12 * ) V_226 ) ;
F_61 ( & V_348 ) ;
return V_166 ;
}
static T_22
F_94 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_96 ,
( V_3 -> V_185 . V_251 . V_252 & 0xFF000000 ) >> 24 ,
( V_3 -> V_185 . V_251 . V_252 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_185 . V_251 . V_252 & 0x0000FF00 ) >> 8 ,
V_3 -> V_185 . V_251 . V_252 & 0x000000FF ) ;
}
static T_22
F_97 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
T_7 V_359 = F_7 ( V_3 -> V_257 . V_258 ) ;
return snprintf ( V_355 , V_358 , L_96 ,
( V_359 & 0xFF000000 ) >> 24 ,
( V_359 & 0x00FF0000 ) >> 16 ,
( V_359 & 0x0000FF00 ) >> 8 ,
V_359 & 0x000000FF ) ;
}
static T_22
F_98 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_97 ,
V_3 -> V_185 . V_360 , V_3 -> V_185 . V_361 >> 8 ) ;
}
static T_22
F_99 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_363 ) ;
}
static T_22
F_100 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 ,
F_7 ( V_3 -> V_364 . V_365 . V_252 ) ) ;
}
static T_22
F_101 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 ,
F_7 ( V_3 -> V_364 . V_366 . V_252 ) ) ;
}
static T_22
F_102 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_367 ) ;
}
static T_22
F_103 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_368 ) ;
}
static T_22
F_104 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_369 ) ;
}
static T_22
F_105 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_370 ) ;
}
static T_22
F_106 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_371 ) ;
}
static T_22
F_107 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_185 . V_372 ) ;
}
static T_22
F_108 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_100 ,
( unsigned long long ) V_3 -> V_373 . V_54 ) ;
}
static T_22
F_109 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 , V_3 -> V_13 ) ;
}
static T_22
F_110 ( struct V_140 * V_352 , struct V_353 * V_354 ,
const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_101 , & V_375 ) != 1 )
return - V_180 ;
V_3 -> V_13 = V_375 ;
F_6 ( V_45 L_102 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_355 ) ;
}
static T_22
F_111 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_103 , V_3 -> V_376 ) ;
}
static T_22
F_112 ( struct V_140 * V_352 ,
struct V_353 * V_354 , const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_104 , & V_375 ) != 1 )
return - V_180 ;
V_3 -> V_376 = V_375 ;
F_6 ( V_45 L_105 , V_3 -> V_46 ,
V_3 -> V_376 ) ;
return strlen ( V_355 ) ;
}
static T_22
F_113 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_106 , V_3 -> V_377 ) ;
}
static T_22
F_114 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
T_6 V_378 ;
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
if ( ( V_3 -> V_185 . V_288 &
V_379 ) && V_3 -> V_380 )
V_378 = V_3 -> V_378 ;
else
V_378 = 1 ;
return snprintf ( V_355 , V_358 , L_103 , V_378 ) ;
}
static T_22
F_115 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
T_7 V_381 = 0 ;
struct V_382 * V_296 ;
if ( ! V_3 -> V_301 [ V_287 ] ) {
F_6 ( V_172 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_287 ] &
V_108 ) == 0 ) {
F_6 ( V_172 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
V_296 = (struct V_382 * )
V_3 -> V_301 [ V_287 ] ;
if ( ( F_7 ( V_296 -> V_383 ) == 0x00000000 ||
F_7 ( V_296 -> V_383 ) == 0x01000000 ) &&
F_7 ( V_296 -> V_384 ) == 0x4742444c )
V_381 = F_7 ( V_296 -> V_385 ) ;
V_3 -> V_386 = V_381 ;
return snprintf ( V_355 , V_358 , L_103 , V_381 ) ;
}
static T_22
F_116 ( struct V_140 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
void * V_296 ;
T_7 V_381 ;
if ( ! V_3 -> V_301 [ V_287 ] ) {
F_6 ( V_172 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_287 ] &
V_108 ) == 0 ) {
F_6 ( V_172 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( V_3 -> V_387 > V_3 -> V_386 )
return 0 ;
V_381 = V_3 -> V_386 - V_3 -> V_387 ;
V_381 = ( V_381 > V_358 ) ? V_358 : V_381 ;
V_296 = V_3 -> V_301 [ 0 ] + V_3 -> V_387 ;
memcpy ( V_355 , V_296 , V_381 ) ;
return V_381 ;
}
static T_22
F_117 ( struct V_140 * V_352 , struct V_353 * V_354 ,
const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_104 , & V_375 ) != 1 )
return - V_180 ;
V_3 -> V_387 = V_375 ;
return strlen ( V_355 ) ;
}
static T_22
F_118 ( struct V_140 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
if ( ( ! V_3 -> V_301 [ V_287 ] ) ||
( ( V_3 -> V_107 [ V_287 ] &
V_108 ) == 0 ) )
return snprintf ( V_355 , V_358 , L_108 ) ;
else if ( ( V_3 -> V_107 [ V_287 ] &
V_109 ) )
return snprintf ( V_355 , V_358 , L_109 ) ;
else
return snprintf ( V_355 , V_358 , L_110 ) ;
}
static T_22
F_119 ( struct V_140 * V_352 ,
struct V_353 * V_354 , const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
char V_388 [ 10 ] = L_111 ;
struct V_294 V_295 ;
T_6 V_103 = 0 ;
if ( sscanf ( V_355 , L_112 , V_388 ) != 1 )
return - V_180 ;
if ( ! strcmp ( V_388 , L_113 ) ) {
if ( ( V_3 -> V_301 [ V_287 ] ) &&
( V_3 -> V_107 [ V_287 ] &
V_108 ) &&
( ( V_3 -> V_107 [ V_287 ] &
V_109 ) == 0 ) )
goto V_7;
memset ( & V_295 , 0 , sizeof( struct V_294 ) ) ;
F_6 ( V_45 L_114 ,
V_3 -> V_46 ) ;
V_295 . V_286 = V_287 ;
V_295 . V_300 = ( 1024 * 1024 ) ;
V_295 . V_302 = 0x7075900 ;
V_3 -> V_107 [ V_287 ] = 0 ;
F_77 ( V_3 , & V_295 ) ;
} else if ( ! strcmp ( V_388 , L_115 ) ) {
if ( ! V_3 -> V_301 [ V_287 ] )
goto V_7;
if ( ( V_3 -> V_107 [ V_287 ] &
V_108 ) == 0 )
goto V_7;
if ( ( V_3 -> V_107 [ V_287 ] &
V_109 ) )
goto V_7;
F_6 ( V_45 L_116 ,
V_3 -> V_46 ) ;
F_24 ( V_3 , V_287 , & V_103 ) ;
}
V_7:
return strlen ( V_355 ) ;
}
static T_22
F_120 ( struct V_140 * V_389 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_390 * V_391 = F_121 ( V_389 ) ;
struct V_128 * V_392 = V_391 -> V_141 ;
return snprintf ( V_355 , V_358 , L_100 ,
( unsigned long long ) V_392 -> V_142 -> V_54 ) ;
}
static T_22
F_122 ( struct V_140 * V_389 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_390 * V_391 = F_121 ( V_389 ) ;
struct V_128 * V_392 = V_391 -> V_141 ;
return snprintf ( V_355 , V_358 , L_117 ,
V_392 -> V_142 -> V_4 ) ;
}
void
F_123 ( void )
{
V_96 = NULL ;
if ( F_124 ( & V_393 ) < 0 )
F_6 ( V_149 L_118 ,
V_254 , V_394 ) ;
F_125 ( & V_95 ) ;
}
void
F_126 ( void )
{
struct V_2 * V_3 ;
int V_78 ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ! V_3 -> V_301 [ V_78 ] )
continue;
F_59 ( V_3 -> V_187 , V_3 -> V_307 [ V_78 ] ,
V_3 -> V_301 [ V_78 ] , V_3 -> V_306 [ V_78 ] ) ;
V_3 -> V_301 [ V_78 ] = NULL ;
V_3 -> V_107 [ V_78 ] = 0 ;
}
F_60 ( V_3 -> V_80 ) ;
}
F_127 ( & V_393 ) ;
}
