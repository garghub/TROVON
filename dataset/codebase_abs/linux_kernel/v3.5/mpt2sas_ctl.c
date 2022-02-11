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
F_36 ( struct V_2 * V_3 , struct V_122 V_123 ,
void T_12 * V_150 )
{
T_13 * V_11 = NULL , * V_151 ;
T_2 * V_10 ;
T_7 V_152 ;
T_1 V_153 ;
T_1 V_8 ;
unsigned long V_154 , V_155 ;
T_6 V_103 ;
T_7 V_64 ;
void * V_156 ;
void * V_157 = NULL ;
T_14 V_158 ;
T_15 V_159 = 0 ;
void * V_160 = NULL ;
T_14 V_161 ;
T_15 V_162 = 0 ;
T_7 V_163 ;
long V_164 ;
T_1 V_165 ;
V_103 = 0 ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_166 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_164 = - V_167 ;
goto V_7;
}
V_165 = 0 ;
V_152 = F_37 ( V_3 , 1 ) ;
while ( V_152 != V_168 ) {
if ( V_165 ++ == 10 ) {
F_6 ( V_166
L_36 ,
V_3 -> V_46 , V_105 ) ;
V_164 = - V_169 ;
goto V_7;
}
F_38 ( 1 ) ;
V_152 = F_37 ( V_3 , 1 ) ;
F_6 ( V_45 L_37
L_38 , V_3 -> V_46 ,
V_105 , V_165 ) ;
}
if ( V_165 )
F_6 ( V_45 L_39 ,
V_3 -> V_46 , V_105 ) ;
V_11 = F_39 ( V_3 -> V_170 , V_171 ) ;
if ( ! V_11 ) {
F_6 ( V_166 L_40
L_41 , V_3 -> V_46 , V_105 ) ;
V_164 = - V_172 ;
goto V_7;
}
if ( V_123 . V_173 * 4 > V_3 -> V_170 ||
V_123 . V_173 > ( V_174 / 4 ) ) {
V_164 = - V_175 ;
goto V_7;
}
if ( F_40 ( V_11 , V_150 , V_123 . V_173 * 4 ) ) {
F_6 ( V_149 L_33 , __FILE__ , __LINE__ ,
V_105 ) ;
V_164 = - V_169 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_41 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_166 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_164 = - V_167 ;
goto V_7;
}
} else {
V_8 = F_42 ( V_3 , V_3 -> V_176 , NULL ) ;
if ( ! V_8 ) {
F_6 ( V_166 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_164 = - V_167 ;
goto V_7;
}
}
V_164 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_151 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_151 , V_11 , V_123 . V_173 * 4 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_159 = V_123 . V_177 ;
V_162 = V_123 . V_178 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_179 ) ||
F_5 ( V_11 -> V_179 ) >
V_3 -> V_180 . V_181 ) {
V_164 = - V_175 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_159 ) {
V_157 = F_43 ( V_3 -> V_182 , V_159 ,
& V_158 ) ;
if ( ! V_157 ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_172 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_40 ( V_157 , V_123 . V_183 ,
V_159 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_169 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_162 ) {
V_160 = F_43 ( V_3 -> V_182 , V_162 ,
& V_161 ) ;
if ( ! V_160 ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_172 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_156 = ( void * ) V_151 + ( V_123 . V_173 * 4 ) ;
if ( ! V_159 && ! V_162 ) {
F_44 ( V_3 , V_156 ) ;
} else if ( V_159 && V_162 ) {
V_163 = ( V_184 |
V_185 | V_186 ) ;
V_163 = V_163 << V_187 ;
V_3 -> V_188 ( V_156 , V_163 |
V_159 , V_158 ) ;
V_156 += V_3 -> V_189 ;
V_163 = ( V_184 |
V_190 | V_185 |
V_191 ) ;
V_163 = V_163 << V_187 ;
V_3 -> V_188 ( V_156 , V_163 |
V_162 , V_161 ) ;
} else if ( V_159 ) {
V_163 = ( V_184 |
V_190 | V_185 |
V_191 | V_186 ) ;
V_163 = V_163 << V_187 ;
V_3 -> V_188 ( V_156 , V_163 |
V_159 , V_158 ) ;
} else if ( V_162 ) {
V_163 = ( V_184 |
V_190 | V_185 |
V_191 ) ;
V_163 = V_163 << V_187 ;
V_3 -> V_188 ( V_156 , V_163 |
V_162 , V_161 ) ;
}
#ifdef F_14
F_3 ( V_3 , V_8 , L_43 , NULL ) ;
#endif
F_45 ( & V_3 -> V_65 . V_76 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_192 =
( T_4 * ) V_151 ;
V_192 -> V_193 = V_72 ;
V_192 -> V_194 =
F_46 ( V_3 , V_8 ) ;
memset ( V_3 -> V_65 . V_74 , 0 , V_72 ) ;
if ( V_11 -> V_15 == V_16 )
F_47 ( V_3 , V_8 ,
F_5 ( V_11 -> V_179 ) ) ;
else
F_48 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_124 =
( T_10 * ) V_151 ;
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
F_49 ( V_3 , F_5 (
V_124 -> V_52 ) ) ;
F_50 ( V_3 , V_8 ) ;
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
if ( F_51 ( V_157 == NULL ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
F_25 ( V_3 , V_8 ) ;
V_164 = - V_175 ;
goto V_7;
}
V_91 = V_157 ;
}
if ( V_91 [ 1 ] == 0x91 && ( V_91 [ 10 ] == 1 || V_91 [ 10 ] == 2 ) ) {
V_3 -> V_200 = 1 ;
V_3 -> V_201 = 1 ;
}
F_48 ( V_3 , V_8 ) ;
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
F_48 ( V_3 , V_8 ) ;
break;
}
default:
F_48 ( V_3 , V_8 ) ;
break;
}
if ( V_123 . V_154 < V_206 )
V_154 = V_206 ;
else
V_154 = V_123 . V_154 ;
V_155 = F_52 ( & V_3 -> V_65 . V_76 ,
V_154 * V_207 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_124 =
( T_10 * ) V_11 ;
F_53 ( V_3 , F_5 (
V_124 -> V_52 ) ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_200 ) {
V_3 -> V_200 = 0 ;
V_3 -> V_201 = 0 ;
}
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_166 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_54 ( V_11 , V_123 . V_173 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_208;
}
V_10 = V_3 -> V_65 . V_61 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_209 ;
#ifdef F_14
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_210 ) ) {
T_11 * V_130 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_44
L_47
L_48 , V_3 -> V_46 ,
F_5 ( V_130 -> V_47 ) ,
F_7 ( V_130 -> V_48 ) ,
F_7 ( V_130 -> V_211 ) ) ;
}
#endif
if ( V_162 ) {
if ( F_35 ( V_123 . V_212 , V_160 ,
V_162 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_213 ;
goto V_7;
}
}
if ( V_123 . V_146 ) {
V_64 = F_12 ( T_7 , V_123 . V_146 , V_3 -> V_147 ) ;
if ( F_35 ( V_123 . V_148 , V_3 -> V_65 . V_61 ,
V_64 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_213 ;
goto V_7;
}
}
if ( V_123 . V_214 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_64 = F_12 ( T_7 , V_123 . V_214 , V_72 ) ;
if ( F_35 ( V_123 . V_215 ,
V_3 -> V_65 . V_74 , V_64 ) ) {
F_6 ( V_149 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_164 = - V_213 ;
goto V_7;
}
}
V_208:
if ( V_103 ) {
V_164 = - V_213 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_49
L_50 , V_3 -> V_46 ,
F_5 ( V_11 -> V_179 ) ) ;
F_55 ( V_3 ) ;
F_56 ( V_3 ,
F_5 ( V_11 -> V_179 ) , 0 , 0 ,
0 , V_216 , 0 , 10 ,
0 , V_217 ) ;
V_3 -> V_218 . V_66 = V_67 ;
} else
F_57 ( V_3 , V_219 ,
V_220 ) ;
}
V_7:
if ( V_160 )
F_58 ( V_3 -> V_182 , V_162 , V_160 ,
V_161 ) ;
if ( V_157 )
F_58 ( V_3 -> V_182 , V_159 , V_157 ,
V_158 ) ;
F_59 ( V_11 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_164 ;
}
static long
F_60 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_222 V_123 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
if ( V_3 -> V_223 )
V_123 . V_224 = V_225 ;
else
V_123 . V_224 = V_226 ;
if ( V_3 -> V_227 )
V_123 . V_228 = V_3 -> V_227 [ 0 ] . V_229 ;
V_123 . V_230 = V_3 -> V_182 -> V_231 ;
V_123 . V_232 = V_3 -> V_182 -> V_140 ;
V_123 . V_233 = V_3 -> V_182 -> V_233 ;
V_123 . V_234 = V_3 -> V_182 -> V_234 ;
V_123 . V_235 . V_236 . V_237 . V_238 = V_3 -> V_182 -> V_238 -> V_239 ;
V_123 . V_235 . V_236 . V_237 . V_140 = F_61 ( V_3 -> V_182 -> V_240 ) ;
V_123 . V_235 . V_236 . V_237 . V_241 = F_62 ( V_3 -> V_182 -> V_240 ) ;
V_123 . V_235 . V_242 = F_63 ( V_3 -> V_182 -> V_238 ) ;
V_123 . V_243 = V_3 -> V_180 . V_244 . V_245 ;
strcpy ( V_123 . V_246 , V_247 ) ;
strcat ( V_123 . V_246 , L_52 ) ;
strcat ( V_123 . V_246 , V_248 ) ;
V_123 . V_249 = F_7 ( V_3 -> V_250 . V_251 ) ;
if ( F_35 ( V_221 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
return 0 ;
}
static long
F_64 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_252 V_123 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_123 . V_253 = V_87 ;
memcpy ( V_123 . V_254 , V_3 -> V_81 ,
V_255 * sizeof( T_7 ) ) ;
if ( F_35 ( V_221 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
return 0 ;
}
static long
F_65 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_256 V_123 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_80 )
return 0 ;
memcpy ( V_3 -> V_81 , V_123 . V_254 ,
V_255 * sizeof( T_7 ) ) ;
F_66 ( V_3 , V_3 -> V_81 ) ;
V_3 -> V_86 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_80 = F_67 ( V_87 ,
sizeof( struct V_82 ) , V_171 ) ;
if ( ! V_3 -> V_80 ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_172 ;
}
return 0 ;
}
static long
F_68 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_257 V_123 ;
T_7 V_258 , V_259 , V_260 ;
struct V_257 T_12 * V_261 = V_221 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_258 = V_123 . V_262 . V_263 -
sizeof( struct V_264 ) ;
V_259 = V_258 / sizeof( struct V_82 ) ;
V_260 = F_12 ( T_7 , V_87 , V_259 ) ;
if ( ! V_260 || ! V_3 -> V_80 )
return - V_213 ;
V_258 = V_260 * sizeof( struct V_82 ) ;
if ( F_35 ( V_261 -> V_265 , V_3 -> V_80 , V_258 ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
V_3 -> V_94 = 0 ;
return 0 ;
}
static long
F_69 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_266 V_123 ;
int V_267 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 )
return - V_167 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_267 = F_57 ( V_3 , V_219 ,
V_220 ) ;
F_6 ( V_45 L_53 ,
V_3 -> V_46 , ( ( ! V_267 ) ? L_54 : L_55 ) ) ;
return 0 ;
}
static int
F_70 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_71 ( & V_3 -> V_274 ) )
return V_273 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_272 -> V_238 == 0xFFFFFFFF && V_272 -> V_101 == 0xFFFFFFFF &&
V_272 -> V_4 == V_5 -> V_4 ) {
V_272 -> V_238 = V_5 -> V_275 ;
V_272 -> V_101 = V_5 -> V_101 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_238 == V_5 -> V_275 && V_272 -> V_101 ==
V_5 -> V_101 && V_272 -> V_4 == 0xFFFF ) {
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
F_72 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_276 * V_277 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_71 ( & V_3 -> V_278 ) )
return V_273 ;
F_8 ( & V_3 -> V_279 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_272 -> V_238 == 0xFFFFFFFF && V_272 -> V_101 == 0xFFFFFFFF &&
V_272 -> V_4 == V_277 -> V_4 ) {
V_272 -> V_238 = V_277 -> V_275 ;
V_272 -> V_101 = V_277 -> V_101 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_238 == V_277 -> V_275 && V_272 -> V_101 ==
V_277 -> V_101 && V_272 -> V_4 == 0xFFFF ) {
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
F_73 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_271 V_123 ;
int V_273 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_273 = F_70 ( V_3 , & V_123 ) ;
if ( ! V_273 )
F_72 ( V_3 , & V_123 ) ;
if ( F_35 ( V_221 , & V_123 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
return 0 ;
}
static T_6
F_74 ( struct V_2 * V_3 , T_6 V_280 )
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
F_75 ( struct V_2 * V_3 ,
struct V_288 * V_289 )
{
int V_273 , V_78 ;
void * V_290 = NULL ;
T_14 V_291 ;
T_7 V_292 = 0 ;
T_18 * V_11 ;
T_19 * V_10 ;
T_6 V_280 ;
unsigned long V_155 ;
T_1 V_8 ;
T_1 V_153 ;
T_6 V_103 = 0 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_166 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_280 = V_289 -> V_280 ;
if ( ! F_74 ( V_3 , V_280 ) ) {
F_6 ( V_166 L_57
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_293 ;
}
if ( V_3 -> V_107 [ V_280 ] &
V_108 ) {
F_6 ( V_166 L_59
L_60 , V_3 -> V_46 , V_105 ,
V_280 ) ;
return - V_175 ;
}
if ( V_289 -> V_294 % 4 ) {
F_6 ( V_166 L_61
L_62 , V_3 -> V_46 , V_105 ) ;
return - V_175 ;
}
V_8 = F_76 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_166 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_290 = V_3 -> V_295 [ V_280 ] ;
V_292 = V_289 -> V_294 ;
V_3 -> V_296 [ V_280 ] = V_289 -> V_296 ;
V_3 -> V_107 [ V_280 ] = 0 ;
memcpy ( V_3 -> V_297 [ V_280 ] ,
V_289 -> V_297 , V_298 ) ;
V_3 -> V_299 [ V_280 ] = V_289 -> V_299 ;
if ( V_290 ) {
V_291 = V_3 -> V_300 [ V_280 ] ;
if ( V_292 != V_3 -> V_301 [ V_280 ] ) {
F_58 ( V_3 -> V_182 ,
V_3 -> V_301 [ V_280 ] ,
V_290 , V_291 ) ;
V_290 = NULL ;
}
}
if ( V_290 == NULL ) {
V_3 -> V_301 [ V_280 ] = 0 ;
V_3 -> V_300 [ V_280 ] = 0 ;
V_290 = F_43 (
V_3 -> V_182 , V_292 , & V_291 ) ;
if ( V_290 == NULL ) {
F_6 ( V_166 L_63
L_64 ,
V_3 -> V_46 , V_105 , V_292 ) ;
F_25 ( V_3 , V_8 ) ;
return - V_172 ;
}
V_3 -> V_295 [ V_280 ] = V_290 ;
V_3 -> V_301 [ V_280 ] = V_292 ;
V_3 -> V_300 [ V_280 ] = V_291 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_289 -> V_280 ;
V_11 -> V_303 = F_77 ( V_289 -> V_299 ) ;
V_11 -> V_304 = F_78 ( V_291 ) ;
V_11 -> V_305 = F_77 ( V_292 ) ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_34 ( V_3 , F_6 ( V_45 L_65
L_66 , V_3 -> V_46 , V_105 , V_290 ,
( unsigned long long ) V_291 ,
F_7 ( V_11 -> V_305 ) ) ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_11 -> V_306 [ V_78 ] =
F_77 ( V_3 -> V_297 [ V_280 ] [ V_78 ] ) ;
F_45 ( & V_3 -> V_65 . V_76 ) ;
F_48 ( V_3 , V_8 ) ;
V_155 = F_52 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_166 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_54 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_166 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_153 == V_307 ) {
V_3 -> V_107 [ V_280 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_208:
if ( V_103 )
F_57 ( V_3 , V_219 ,
V_220 ) ;
V_7:
if ( V_273 && V_290 )
F_58 ( V_3 -> V_182 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
void
F_79 ( struct V_2 * V_3 , T_6 V_308 )
{
struct V_288 V_289 ;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
if ( V_308 & 1 ) {
F_6 ( V_45 L_71 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
F_75 ( V_3 , & V_289 ) ;
}
if ( V_308 & 2 ) {
F_6 ( V_45 L_72 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_284 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_75 ( V_3 , & V_289 ) ;
}
if ( V_308 & 4 ) {
F_6 ( V_45 L_73 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_286 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_75 ( V_3 , & V_289 ) ;
}
}
static long
F_80 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_288 V_123 ;
long V_273 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
V_273 = F_75 ( V_3 , & V_123 ) ;
return V_273 ;
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_309 V_123 ;
void * V_290 ;
T_14 V_291 ;
T_7 V_292 ;
T_6 V_280 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_280 = V_123 . V_296 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_280 ) ) {
F_6 ( V_166 L_57
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) {
F_6 ( V_166 L_74
L_75 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_175 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_109 ) == 0 ) {
F_6 ( V_166 L_76
L_77 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_175 ;
}
if ( V_123 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_166 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_296 ) ;
return - V_175 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_166 L_79
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_172 ;
}
V_292 = V_3 -> V_301 [ V_280 ] ;
V_291 = V_3 -> V_300 [ V_280 ] ;
F_58 ( V_3 -> V_182 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_295 [ V_280 ] = NULL ;
V_3 -> V_107 [ V_280 ] = 0 ;
return 0 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_310 V_123 ;
void * V_290 ;
int V_78 ;
T_6 V_280 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_123 . V_311 = 0 ;
V_280 = V_123 . V_280 ;
if ( ! F_74 ( V_3 , V_280 ) ) {
F_6 ( V_166 L_57
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) {
F_6 ( V_166 L_74
L_75 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_175 ;
}
if ( V_123 . V_296 & 0xffffff00 ) {
if ( V_123 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_166 L_78
L_75 , V_3 -> V_46 , V_105 ,
V_123 . V_296 ) ;
return - V_175 ;
}
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_166 L_80
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_172 ;
}
if ( V_3 -> V_107 [ V_280 ] & V_109 )
V_123 . V_311 = ( V_312 |
V_313 ) ;
else
V_123 . V_311 = ( V_312 |
V_313 |
V_314 ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_123 . V_297 [ V_78 ] =
V_3 -> V_297 [ V_280 ] [ V_78 ] ;
V_123 . V_315 = V_3 -> V_301 [ V_280 ] ;
V_123 . V_316 = 0 ;
V_123 . V_296 = V_3 -> V_296 [ V_280 ] ;
V_123 . V_299 = V_3 -> V_299 [ V_280 ] ;
if ( F_35 ( V_221 , & V_123 , sizeof( struct V_310 ) ) ) {
F_6 ( V_166 L_81
L_82 , V_3 -> V_46 , V_105 , V_221 ) ;
return - V_169 ;
}
return 0 ;
}
static int
F_24 ( struct V_2 * V_3 , T_6 V_280 , T_6 * V_103 )
{
T_20 * V_11 ;
T_21 * V_10 ;
T_1 V_8 ;
T_1 V_153 ;
T_7 V_152 ;
int V_273 ;
unsigned long V_155 ;
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_273 = 0 ;
* V_103 = 0 ;
V_152 = F_37 ( V_3 , 1 ) ;
if ( V_152 != V_168 ) {
F_34 ( V_3 , F_6 ( V_45 L_26
L_83 , V_3 -> V_46 ,
V_105 ) ) ;
V_273 = - V_167 ;
goto V_7;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_166 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_166 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_45 ( & V_3 -> V_65 . V_76 ) ;
F_48 ( V_3 , V_8 ) ;
V_155 = F_52 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_166 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_54 ( V_11 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
* V_103 = 1 ;
V_273 = - V_169 ;
goto V_7;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_166 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_153 == V_307 ) {
V_3 -> V_107 [ V_280 ] |=
V_109 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_317 V_123 ;
void * V_290 ;
int V_273 ;
T_6 V_280 ;
T_6 V_103 = 0 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_280 = V_123 . V_296 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_280 ) ) {
F_6 ( V_166 L_57
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) {
F_6 ( V_166 L_74
L_75 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_175 ;
}
if ( V_123 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_166 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_296 ) ;
return - V_175 ;
}
if ( V_3 -> V_107 [ V_280 ] &
V_109 ) {
F_6 ( V_166 L_84
L_85 , V_3 -> V_46 , V_105 ,
V_280 ) ;
return 0 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_166 L_79
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_172 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_113 ) ) {
V_3 -> V_107 [ V_280 ] |=
V_109 ;
V_3 -> V_107 [ V_280 ] &=
~ V_113 ;
F_6 ( V_166 L_84
L_86 , V_3 -> V_46 , V_105 ,
V_280 ) ;
return 0 ;
}
V_273 = F_24 ( V_3 , V_280 , & V_103 ) ;
if ( V_103 )
F_57 ( V_3 , V_219 ,
V_220 ) ;
return V_273 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_221 )
{
struct V_318 V_123 ;
struct V_318 T_12 * V_261 = V_221 ;
void * V_290 , * V_319 ;
T_18 * V_11 ;
T_19 * V_10 ;
int V_273 , V_78 ;
T_6 V_280 ;
unsigned long V_155 , V_320 , V_321 ;
T_1 V_8 ;
T_1 V_153 ;
T_6 V_103 = 0 ;
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
F_34 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_280 = V_123 . V_296 & 0x000000ff ;
if ( ! F_74 ( V_3 , V_280 ) ) {
F_6 ( V_166 L_57
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_293 ;
}
if ( V_123 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_6 ( V_166 L_78
L_75 , V_3 -> V_46 , V_105 , V_123 . V_296 ) ;
return - V_175 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_6 ( V_166 L_80
L_58 , V_3 -> V_46 , V_105 , V_280 ) ;
return - V_172 ;
}
V_320 = V_3 -> V_301 [ V_280 ] ;
if ( ( V_123 . V_322 % 4 ) || ( V_123 . V_323 % 4 ) ) {
F_6 ( V_166 L_87
L_88 , V_3 -> V_46 ,
V_105 ) ;
return - V_175 ;
}
if ( V_123 . V_322 > V_320 )
return - V_175 ;
V_319 = ( void * ) ( V_290 + V_123 . V_322 ) ;
F_34 ( V_3 , F_6 ( V_45 L_89
L_90 , V_3 -> V_46 , V_105 ,
V_319 , V_123 . V_322 , V_123 . V_323 ) ) ;
if ( ( V_319 + V_123 . V_323 < V_319 ) ||
( V_319 + V_123 . V_323 > V_290 + V_320 ) )
V_321 = V_320 - V_123 . V_322 ;
else
V_321 = V_123 . V_323 ;
if ( F_35 ( ( void T_12 * ) V_261 -> V_324 ,
V_319 , V_321 ) ) {
F_6 ( V_166 L_91
L_92 , V_3 -> V_46 ,
V_105 , V_319 ) ;
return - V_169 ;
}
if ( ( V_123 . V_50 & V_325 ) == 0 )
return 0 ;
F_34 ( V_3 , F_6 ( V_45 L_93
L_58 , V_3 -> V_46 , V_105 , V_280 ) ) ;
if ( ( V_3 -> V_107 [ V_280 ] &
V_109 ) == 0 ) {
F_34 ( V_3 , F_6 ( V_45 L_26
L_94 , V_3 -> V_46 ,
V_105 , V_280 ) ) ;
return 0 ;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_166 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_8 = F_76 ( V_3 , V_3 -> V_176 ) ;
if ( ! V_8 ) {
F_6 ( V_166 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_147 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_305 =
F_77 ( V_3 -> V_301 [ V_280 ] ) ;
V_11 -> V_304 =
F_78 ( V_3 -> V_300 [ V_280 ] ) ;
for ( V_78 = 0 ; V_78 < V_298 ; V_78 ++ )
V_11 -> V_306 [ V_78 ] =
F_77 ( V_3 -> V_297 [ V_280 ] [ V_78 ] ) ;
V_11 -> V_145 = 0 ;
V_11 -> V_144 = 0 ;
F_45 ( & V_3 -> V_65 . V_76 ) ;
F_48 ( V_3 , V_8 ) ;
V_155 = F_52 ( & V_3 -> V_65 . V_76 ,
V_206 * V_207 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_166 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_54 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_208;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_166 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_273 = - V_169 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_209 ;
if ( V_153 == V_307 ) {
V_3 -> V_107 [ V_280 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_169 ;
}
V_208:
if ( V_103 )
F_57 ( V_3 , V_219 ,
V_220 ) ;
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_273 ;
}
static long
F_85 ( struct V_2 * V_3 , unsigned V_326 ,
void T_12 * V_221 )
{
struct V_327 V_328 ;
struct V_327 T_12 * V_261 ;
struct V_122 V_123 ;
if ( F_86 ( V_326 ) != sizeof( struct V_327 ) )
return - V_175 ;
V_261 = (struct V_327 T_12 * ) V_221 ;
if ( F_40 ( & V_328 , ( char T_12 * ) V_221 , sizeof( V_328 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
memset ( & V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 . V_262 . V_99 = V_328 . V_262 . V_99 ;
V_123 . V_262 . V_228 = V_328 . V_262 . V_228 ;
V_123 . V_262 . V_263 = V_328 . V_262 . V_263 ;
V_123 . V_154 = V_328 . V_154 ;
V_123 . V_146 = V_328 . V_146 ;
V_123 . V_178 = V_328 . V_178 ;
V_123 . V_177 = V_328 . V_177 ;
V_123 . V_214 = V_328 . V_214 ;
V_123 . V_173 = V_328 . V_173 ;
V_123 . V_148 = F_87 ( V_328 . V_148 ) ;
V_123 . V_212 = F_87 ( V_328 . V_212 ) ;
V_123 . V_183 = F_87 ( V_328 . V_183 ) ;
V_123 . V_215 = F_87 ( V_328 . V_215 ) ;
return F_36 ( V_3 , V_123 , & V_261 -> V_150 ) ;
}
static long
F_88 ( struct V_115 * V_115 , unsigned int V_326 , void T_12 * V_221 ,
T_6 V_329 )
{
struct V_2 * V_3 ;
struct V_264 V_330 ;
enum V_331 V_332 ;
long V_164 = - V_175 ;
if ( F_40 ( & V_330 , ( char T_12 * ) V_221 ,
sizeof( struct V_264 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_169 ;
}
if ( F_21 ( V_330 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_333 ;
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 )
return - V_167 ;
V_332 = ( V_115 -> V_334 & V_335 ) ? V_336 : V_337 ;
if ( V_332 == V_336 && ! F_89 ( & V_3 -> V_65 . V_338 ) )
return - V_167 ;
else if ( F_90 ( & V_3 -> V_65 . V_338 ) )
return - V_339 ;
switch ( V_326 ) {
case V_340 :
if ( F_86 ( V_326 ) == sizeof( struct V_222 ) )
V_164 = F_60 ( V_3 , V_221 ) ;
break;
#ifdef F_91
case V_341 :
#endif
case V_342 :
{
struct V_122 T_12 * V_261 ;
struct V_122 V_123 ;
#ifdef F_91
if ( V_329 ) {
V_164 = F_85 ( V_3 , V_326 , V_221 ) ;
break;
}
#endif
if ( F_40 ( & V_123 , V_221 , sizeof( V_123 ) ) ) {
F_6 ( V_149 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
V_164 = - V_169 ;
break;
}
if ( F_86 ( V_326 ) == sizeof( struct V_122 ) ) {
V_261 = V_221 ;
V_164 = F_36 ( V_3 , V_123 , & V_261 -> V_150 ) ;
}
break;
}
case V_343 :
if ( F_86 ( V_326 ) == sizeof( struct V_252 ) )
V_164 = F_64 ( V_3 , V_221 ) ;
break;
case V_344 :
if ( F_86 ( V_326 ) == sizeof( struct V_256 ) )
V_164 = F_65 ( V_3 , V_221 ) ;
break;
case V_345 :
V_164 = F_68 ( V_3 , V_221 ) ;
break;
case V_346 :
if ( F_86 ( V_326 ) == sizeof( struct V_266 ) )
V_164 = F_69 ( V_3 , V_221 ) ;
break;
case V_347 :
if ( F_86 ( V_326 ) == sizeof( struct V_271 ) )
V_164 = F_73 ( V_3 , V_221 ) ;
break;
case V_348 :
if ( F_86 ( V_326 ) == sizeof( struct V_288 ) )
V_164 = F_80 ( V_3 , V_221 ) ;
break;
case V_349 :
if ( F_86 ( V_326 ) == sizeof( struct V_309 ) )
V_164 = F_81 ( V_3 , V_221 ) ;
break;
case V_350 :
if ( F_86 ( V_326 ) == sizeof( struct V_310 ) )
V_164 = F_82 ( V_3 , V_221 ) ;
break;
case V_351 :
if ( F_86 ( V_326 ) == sizeof( struct V_317 ) )
V_164 = F_83 ( V_3 , V_221 ) ;
break;
case V_352 :
if ( F_86 ( V_326 ) == sizeof( struct V_318 ) )
V_164 = F_84 ( V_3 , V_221 ) ;
break;
default:
F_34 ( V_3 , F_6 ( V_45
L_95 , V_3 -> V_46 , V_326 ) ) ;
break;
}
F_92 ( & V_3 -> V_65 . V_338 ) ;
return V_164 ;
}
static long
F_93 ( struct V_115 * V_115 , unsigned int V_326 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_115 , V_326 , ( void T_12 * ) V_221 , 0 ) ;
return V_164 ;
}
static long
F_94 ( struct V_115 * V_115 , unsigned V_326 , unsigned long V_221 )
{
long V_164 ;
V_164 = F_88 ( V_115 , V_326 , ( void T_12 * ) V_221 , 1 ) ;
return V_164 ;
}
static T_22
F_95 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_96 ,
( V_3 -> V_180 . V_244 . V_245 & 0xFF000000 ) >> 24 ,
( V_3 -> V_180 . V_244 . V_245 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_180 . V_244 . V_245 & 0x0000FF00 ) >> 8 ,
V_3 -> V_180 . V_244 . V_245 & 0x000000FF ) ;
}
static T_22
F_98 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
T_7 V_360 = F_7 ( V_3 -> V_250 . V_251 ) ;
return snprintf ( V_356 , V_359 , L_96 ,
( V_360 & 0xFF000000 ) >> 24 ,
( V_360 & 0x00FF0000 ) >> 16 ,
( V_360 & 0x0000FF00 ) >> 8 ,
V_360 & 0x000000FF ) ;
}
static T_22
F_99 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_97 ,
V_3 -> V_180 . V_361 , V_3 -> V_180 . V_362 >> 8 ) ;
}
static T_22
F_100 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , 16 , L_56 , V_3 -> V_363 . V_364 ) ;
}
static T_22
F_101 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_98 ,
F_7 ( V_3 -> V_365 . V_366 . V_245 ) ) ;
}
static T_22
F_102 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_98 ,
F_7 ( V_3 -> V_365 . V_367 . V_245 ) ) ;
}
static T_22
F_103 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , 16 , L_56 , V_3 -> V_363 . V_368 ) ;
}
static T_22
F_104 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , 16 , L_56 , V_3 -> V_363 . V_369 ) ;
}
static T_22
F_105 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , 16 , L_56 , V_3 -> V_363 . V_370 ) ;
}
static T_22
F_106 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_99 , V_3 -> V_371 ) ;
}
static T_22
F_107 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_99 , V_3 -> V_372 ) ;
}
static T_22
F_108 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_99 , V_3 -> V_180 . V_373 ) ;
}
static T_22
F_109 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_100 ,
( unsigned long long ) V_3 -> V_374 . V_54 ) ;
}
static T_22
F_110 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_98 , V_3 -> V_13 ) ;
}
static T_22
F_111 ( struct V_140 * V_353 , struct V_354 * V_355 ,
const char * V_356 , T_15 V_375 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
int V_376 = 0 ;
if ( sscanf ( V_356 , L_101 , & V_376 ) != 1 )
return - V_175 ;
V_3 -> V_13 = V_376 ;
F_6 ( V_45 L_102 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_356 ) ;
}
static T_22
F_112 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_103 , V_3 -> V_377 ) ;
}
static T_22
F_113 ( struct V_140 * V_353 ,
struct V_354 * V_355 , const char * V_356 , T_15 V_375 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
int V_376 = 0 ;
if ( sscanf ( V_356 , L_104 , & V_376 ) != 1 )
return - V_175 ;
V_3 -> V_377 = V_376 ;
F_6 ( V_45 L_105 , V_3 -> V_46 ,
V_3 -> V_377 ) ;
return strlen ( V_356 ) ;
}
static T_22
F_114 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
return snprintf ( V_356 , V_359 , L_106 , V_3 -> V_378 ) ;
}
static T_22
F_115 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
T_6 V_379 ;
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
if ( ( V_3 -> V_180 . V_282 &
V_380 ) && V_3 -> V_381 )
V_379 = V_3 -> V_379 ;
else
V_379 = 1 ;
return snprintf ( V_356 , V_359 , L_103 , V_379 ) ;
}
static T_22
F_116 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
T_7 V_382 = 0 ;
struct V_383 * V_290 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_6 ( V_166 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_281 ] &
V_108 ) == 0 ) {
F_6 ( V_166 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
V_290 = (struct V_383 * )
V_3 -> V_295 [ V_281 ] ;
if ( ( F_7 ( V_290 -> V_384 ) == 0x00000000 ||
F_7 ( V_290 -> V_384 ) == 0x01000000 ) &&
F_7 ( V_290 -> V_385 ) == 0x4742444c )
V_382 = F_7 ( V_290 -> V_386 ) ;
V_3 -> V_387 = V_382 ;
return snprintf ( V_356 , V_359 , L_103 , V_382 ) ;
}
static T_22
F_117 ( struct V_140 * V_353 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
void * V_290 ;
T_7 V_382 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_6 ( V_166 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_281 ] &
V_108 ) == 0 ) {
F_6 ( V_166 L_107
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( V_3 -> V_388 > V_3 -> V_387 )
return 0 ;
V_382 = V_3 -> V_387 - V_3 -> V_388 ;
V_382 = ( V_382 > V_359 ) ? V_359 : V_382 ;
V_290 = V_3 -> V_295 [ 0 ] + V_3 -> V_388 ;
memcpy ( V_356 , V_290 , V_382 ) ;
return V_382 ;
}
static T_22
F_118 ( struct V_140 * V_353 , struct V_354 * V_355 ,
const char * V_356 , T_15 V_375 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
int V_376 = 0 ;
if ( sscanf ( V_356 , L_104 , & V_376 ) != 1 )
return - V_175 ;
V_3 -> V_388 = V_376 ;
return strlen ( V_356 ) ;
}
static T_22
F_119 ( struct V_140 * V_353 ,
struct V_354 * V_355 , char * V_356 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
if ( ( ! V_3 -> V_295 [ V_281 ] ) ||
( ( V_3 -> V_107 [ V_281 ] &
V_108 ) == 0 ) )
return snprintf ( V_356 , V_359 , L_108 ) ;
else if ( ( V_3 -> V_107 [ V_281 ] &
V_109 ) )
return snprintf ( V_356 , V_359 , L_109 ) ;
else
return snprintf ( V_356 , V_359 , L_110 ) ;
}
static T_22
F_120 ( struct V_140 * V_353 ,
struct V_354 * V_355 , const char * V_356 , T_15 V_375 )
{
struct V_357 * V_358 = F_96 ( V_353 ) ;
struct V_2 * V_3 = F_97 ( V_358 ) ;
char V_389 [ 10 ] = L_111 ;
struct V_288 V_289 ;
T_6 V_103 = 0 ;
if ( sscanf ( V_356 , L_112 , V_389 ) != 1 )
return - V_175 ;
if ( ! strcmp ( V_389 , L_113 ) ) {
if ( ( V_3 -> V_295 [ V_281 ] ) &&
( V_3 -> V_107 [ V_281 ] &
V_108 ) &&
( ( V_3 -> V_107 [ V_281 ] &
V_109 ) == 0 ) )
goto V_7;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
F_6 ( V_45 L_114 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
V_3 -> V_107 [ V_281 ] = 0 ;
F_75 ( V_3 , & V_289 ) ;
} else if ( ! strcmp ( V_389 , L_115 ) ) {
if ( ! V_3 -> V_295 [ V_281 ] )
goto V_7;
if ( ( V_3 -> V_107 [ V_281 ] &
V_108 ) == 0 )
goto V_7;
if ( ( V_3 -> V_107 [ V_281 ] &
V_109 ) )
goto V_7;
F_6 ( V_45 L_116 ,
V_3 -> V_46 ) ;
F_24 ( V_3 , V_281 , & V_103 ) ;
}
V_7:
return strlen ( V_356 ) ;
}
static T_22
F_121 ( struct V_140 * V_390 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_391 * V_392 = F_122 ( V_390 ) ;
struct V_128 * V_393 = V_392 -> V_141 ;
return snprintf ( V_356 , V_359 , L_100 ,
( unsigned long long ) V_393 -> V_142 -> V_54 ) ;
}
static T_22
F_123 ( struct V_140 * V_390 , struct V_354 * V_355 ,
char * V_356 )
{
struct V_391 * V_392 = F_122 ( V_390 ) ;
struct V_128 * V_393 = V_392 -> V_141 ;
return snprintf ( V_356 , V_359 , L_117 ,
V_393 -> V_142 -> V_4 ) ;
}
void
F_124 ( void )
{
V_96 = NULL ;
if ( F_125 ( & V_394 ) < 0 )
F_6 ( V_149 L_118 ,
V_247 , V_395 ) ;
F_126 ( & V_95 ) ;
}
void
F_127 ( void )
{
struct V_2 * V_3 ;
int V_78 ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ! V_3 -> V_295 [ V_78 ] )
continue;
F_58 ( V_3 -> V_182 , V_3 -> V_301 [ V_78 ] ,
V_3 -> V_295 [ V_78 ] , V_3 -> V_300 [ V_78 ] ) ;
V_3 -> V_295 [ V_78 ] = NULL ;
V_3 -> V_107 [ V_78 ] = 0 ;
}
F_59 ( V_3 -> V_80 ) ;
}
F_128 ( & V_394 ) ;
}
