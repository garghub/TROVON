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
static unsigned int
F_28 ( struct V_115 * V_116 , T_9 * V_118 )
{
struct V_2 * V_3 ;
F_29 ( V_116 , & V_95 , V_118 ) ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
if ( V_3 -> V_94 )
return V_119 | V_120 ;
}
return 0 ;
}
static int
F_30 ( struct V_2 * V_3 , struct V_121 * V_122 ,
T_10 * V_123 )
{
T_6 V_124 = 0 ;
T_1 V_78 ;
T_1 V_4 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
unsigned long V_50 ;
T_11 * V_129 ;
T_7 V_64 ;
T_7 V_130 ;
char * V_12 = NULL ;
if ( V_123 -> V_131 == V_132 )
V_12 = L_30 ;
else if ( V_123 -> V_131 == V_133 )
V_12 = L_31 ;
else
return 0 ;
V_130 = F_31 ( (struct V_134 * ) V_123 -> V_135 ) ;
V_4 = F_5 ( V_123 -> V_52 ) ;
F_8 ( & V_3 -> V_136 , V_50 ) ;
for ( V_78 = V_3 -> V_137 ; V_78 && ! V_124 ; V_78 -- ) {
V_126 = V_3 -> V_138 [ V_78 - 1 ] . V_126 ;
if ( V_126 == NULL || V_126 -> V_139 == NULL ||
V_126 -> V_139 -> V_140 == NULL )
continue;
if ( V_130 != V_126 -> V_139 -> V_130 )
continue;
V_128 = V_126 -> V_139 -> V_140 ;
if ( V_128 -> V_141 == NULL )
continue;
if ( V_128 -> V_141 -> V_4 != V_4 )
continue;
V_123 -> V_142 = F_32 ( V_3 -> V_138 [ V_78 - 1 ] . V_8 ) ;
V_124 = 1 ;
}
F_9 ( & V_3 -> V_136 , V_50 ) ;
if ( ! V_124 ) {
F_33 ( V_3 , F_6 ( V_45 L_26
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_123 -> V_52 ) , V_130 ) ) ;
V_129 = V_3 -> V_65 . V_61 ;
V_129 -> V_52 = V_123 -> V_52 ;
V_129 -> V_15 = V_23 ;
V_129 -> V_131 = V_123 -> V_131 ;
V_129 -> V_69 = sizeof( T_11 ) / 4 ;
V_129 -> V_143 = V_123 -> V_143 ;
V_129 -> V_144 = V_123 -> V_144 ;
V_64 = F_12 ( T_7 , V_122 -> V_145 , V_3 -> V_146 ) ;
if ( F_34 ( V_122 -> V_147 , V_3 -> V_65 . V_61 ,
V_64 ) )
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
return 1 ;
}
F_33 ( V_3 , F_6 ( V_45 L_26
L_34 , V_3 -> V_46 ,
V_12 , F_5 ( V_123 -> V_52 ) , V_130 ,
F_5 ( V_123 -> V_142 ) ) ) ;
return 0 ;
}
static long
F_35 ( struct V_2 * V_3 , struct V_121 V_122 ,
void T_12 * V_149 )
{
T_13 * V_11 = NULL , * V_150 ;
T_2 * V_10 ;
T_7 V_151 ;
T_1 V_152 ;
T_1 V_8 ;
unsigned long V_153 , V_154 ;
T_6 V_103 ;
T_7 V_64 ;
void * V_155 ;
void * V_156 = NULL ;
T_14 V_157 ;
T_15 V_158 = 0 ;
void * V_159 = NULL ;
T_14 V_160 ;
T_15 V_161 = 0 ;
T_7 V_162 ;
long V_163 ;
T_1 V_164 ;
V_103 = 0 ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_165 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_163 = - V_166 ;
goto V_7;
}
V_164 = 0 ;
V_151 = F_36 ( V_3 , 1 ) ;
while ( V_151 != V_167 ) {
if ( V_164 ++ == 10 ) {
F_6 ( V_165
L_36 ,
V_3 -> V_46 , V_105 ) ;
V_163 = - V_168 ;
goto V_7;
}
F_37 ( 1 ) ;
V_151 = F_36 ( V_3 , 1 ) ;
F_6 ( V_45 L_37
L_38 , V_3 -> V_46 ,
V_105 , V_164 ) ;
}
if ( V_164 )
F_6 ( V_45 L_39 ,
V_3 -> V_46 , V_105 ) ;
V_11 = F_38 ( V_3 -> V_169 , V_170 ) ;
if ( ! V_11 ) {
F_6 ( V_165 L_40
L_41 , V_3 -> V_46 , V_105 ) ;
V_163 = - V_171 ;
goto V_7;
}
if ( V_122 . V_172 * 4 > V_3 -> V_169 ||
V_122 . V_172 > ( V_173 / 4 ) ) {
V_163 = - V_174 ;
goto V_7;
}
if ( F_39 ( V_11 , V_149 , V_122 . V_172 * 4 ) ) {
F_6 ( V_148 L_33 , __FILE__ , __LINE__ ,
V_105 ) ;
V_163 = - V_168 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_40 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_6 ( V_165 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_163 = - V_166 ;
goto V_7;
}
} else {
V_8 = F_41 ( V_3 , V_3 -> V_175 , NULL ) ;
if ( ! V_8 ) {
F_6 ( V_165 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_163 = - V_166 ;
goto V_7;
}
}
V_163 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_146 ) ;
V_150 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_150 , V_11 , V_122 . V_172 * 4 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_158 = V_122 . V_176 ;
V_161 = V_122 . V_177 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_178 ) ||
F_5 ( V_11 -> V_178 ) >
V_3 -> V_179 . V_180 ) {
V_163 = - V_174 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_158 ) {
V_156 = F_42 ( V_3 -> V_181 , V_158 ,
& V_157 ) ;
if ( ! V_156 ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_171 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_39 ( V_156 , V_122 . V_182 ,
V_158 ) ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_168 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_161 ) {
V_159 = F_42 ( V_3 -> V_181 , V_161 ,
& V_160 ) ;
if ( ! V_159 ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_171 ;
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_155 = ( void * ) V_150 + ( V_122 . V_172 * 4 ) ;
if ( ! V_158 && ! V_161 ) {
F_43 ( V_3 , V_155 ) ;
} else if ( V_158 && V_161 ) {
V_162 = ( V_183 |
V_184 | V_185 ) ;
V_162 = V_162 << V_186 ;
V_3 -> V_187 ( V_155 , V_162 |
V_158 , V_157 ) ;
V_155 += V_3 -> V_188 ;
V_162 = ( V_183 |
V_189 | V_184 |
V_190 ) ;
V_162 = V_162 << V_186 ;
V_3 -> V_187 ( V_155 , V_162 |
V_161 , V_160 ) ;
} else if ( V_158 ) {
V_162 = ( V_183 |
V_189 | V_184 |
V_190 | V_185 ) ;
V_162 = V_162 << V_186 ;
V_3 -> V_187 ( V_155 , V_162 |
V_158 , V_157 ) ;
} else if ( V_161 ) {
V_162 = ( V_183 |
V_189 | V_184 |
V_190 ) ;
V_162 = V_162 << V_186 ;
V_3 -> V_187 ( V_155 , V_162 |
V_161 , V_160 ) ;
}
#ifdef F_14
F_3 ( V_3 , V_8 , L_43 , NULL ) ;
#endif
F_44 ( & V_3 -> V_65 . V_76 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_191 =
( T_4 * ) V_150 ;
V_191 -> V_192 = V_72 ;
V_191 -> V_193 =
F_45 ( V_3 , V_8 ) ;
memset ( V_3 -> V_65 . V_74 , 0 , V_72 ) ;
if ( V_11 -> V_15 == V_16 )
F_46 ( V_3 , V_8 ,
F_5 ( V_11 -> V_178 ) ) ;
else
F_47 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_123 =
( T_10 * ) V_150 ;
F_23 ( V_3 , F_6 ( V_45 L_44
L_45 , V_3 -> V_46 ,
F_5 ( V_123 -> V_52 ) , V_123 -> V_131 ) ) ;
if ( V_123 -> V_131 ==
V_132 ||
V_123 -> V_131 ==
V_133 ) {
if ( F_30 ( V_3 , & V_122 , V_123 ) ) {
F_25 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_48 ( V_3 , F_5 (
V_123 -> V_52 ) ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_194 =
( T_16 * ) V_11 ;
T_6 * V_91 ;
V_194 -> V_195 = 0xFF ;
if ( V_194 -> V_196 &
V_197 )
V_91 = ( T_6 * ) & V_194 -> V_198 ;
else {
if ( F_50 ( V_156 == NULL ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
F_25 ( V_3 , V_8 ) ;
V_163 = - V_174 ;
goto V_7;
}
V_91 = V_156 ;
}
if ( V_91 [ 1 ] == 0x91 && ( V_91 [ 10 ] == 1 || V_91 [ 10 ] == 2 ) ) {
V_3 -> V_199 = 1 ;
V_3 -> V_200 = 1 ;
}
F_47 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_17 * V_201 =
( T_17 * ) V_11 ;
if ( V_201 -> V_202 == V_203
|| V_201 -> V_202 ==
V_204 ) {
V_3 -> V_199 = 1 ;
V_3 -> V_200 = 1 ;
}
F_47 ( V_3 , V_8 ) ;
break;
}
default:
F_47 ( V_3 , V_8 ) ;
break;
}
if ( V_122 . V_153 < V_205 )
V_153 = V_205 ;
else
V_153 = V_122 . V_153 ;
V_154 = F_51 ( & V_3 -> V_65 . V_76 ,
V_153 * V_206 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_123 =
( T_10 * ) V_11 ;
F_52 ( V_3 , F_5 (
V_123 -> V_52 ) ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_199 ) {
V_3 -> V_199 = 0 ;
V_3 -> V_200 = 0 ;
}
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_165 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_53 ( V_11 , V_122 . V_172 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_207;
}
V_10 = V_3 -> V_65 . V_61 ;
V_152 = F_5 ( V_10 -> V_47 ) & V_208 ;
#ifdef F_14
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_209 ) ) {
T_11 * V_129 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_44
L_47
L_48 , V_3 -> V_46 ,
F_5 ( V_129 -> V_47 ) ,
F_7 ( V_129 -> V_48 ) ,
F_7 ( V_129 -> V_210 ) ) ;
}
#endif
if ( V_161 ) {
if ( F_34 ( V_122 . V_211 , V_159 ,
V_161 ) ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_212 ;
goto V_7;
}
}
if ( V_122 . V_145 ) {
V_64 = F_12 ( T_7 , V_122 . V_145 , V_3 -> V_146 ) ;
if ( F_34 ( V_122 . V_147 , V_3 -> V_65 . V_61 ,
V_64 ) ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_212 ;
goto V_7;
}
}
if ( V_122 . V_213 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_64 = F_12 ( T_7 , V_122 . V_213 , V_72 ) ;
if ( F_34 ( V_122 . V_214 ,
V_3 -> V_65 . V_74 , V_64 ) ) {
F_6 ( V_148 L_33 , __FILE__ ,
__LINE__ , V_105 ) ;
V_163 = - V_212 ;
goto V_7;
}
}
V_207:
if ( V_103 ) {
V_163 = - V_212 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_49
L_50 , V_3 -> V_46 ,
F_5 ( V_11 -> V_178 ) ) ;
F_54 ( V_3 ) ;
F_55 ( V_3 ,
F_5 ( V_11 -> V_178 ) , 0 , 0 ,
0 , V_215 , 0 , 10 ,
0 , V_216 ) ;
V_3 -> V_217 . V_66 = V_67 ;
} else
F_56 ( V_3 , V_218 ,
V_219 ) ;
}
V_7:
if ( V_159 )
F_57 ( V_3 -> V_181 , V_161 , V_159 ,
V_160 ) ;
if ( V_156 )
F_57 ( V_3 -> V_181 , V_158 , V_156 ,
V_157 ) ;
F_58 ( V_11 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_163 ;
}
static long
F_59 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_221 V_122 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
if ( V_3 -> V_222 )
V_122 . V_223 = V_224 ;
else
V_122 . V_223 = V_225 ;
if ( V_3 -> V_226 )
V_122 . V_227 = V_3 -> V_226 [ 0 ] . V_228 ;
V_122 . V_229 = V_3 -> V_181 -> V_230 ;
V_122 . V_231 = V_3 -> V_181 -> V_139 ;
V_122 . V_232 = V_3 -> V_181 -> V_232 ;
V_122 . V_233 = V_3 -> V_181 -> V_233 ;
V_122 . V_234 . V_235 . V_236 . V_237 = V_3 -> V_181 -> V_237 -> V_238 ;
V_122 . V_234 . V_235 . V_236 . V_139 = F_60 ( V_3 -> V_181 -> V_239 ) ;
V_122 . V_234 . V_235 . V_236 . V_240 = F_61 ( V_3 -> V_181 -> V_239 ) ;
V_122 . V_234 . V_241 = F_62 ( V_3 -> V_181 -> V_237 ) ;
V_122 . V_242 = V_3 -> V_179 . V_243 . V_244 ;
strcpy ( V_122 . V_245 , V_246 ) ;
strcat ( V_122 . V_245 , L_52 ) ;
strcat ( V_122 . V_245 , V_247 ) ;
V_122 . V_248 = F_7 ( V_3 -> V_249 . V_250 ) ;
if ( F_34 ( V_220 , & V_122 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
return 0 ;
}
static long
F_63 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_251 V_122 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_122 . V_252 = V_87 ;
memcpy ( V_122 . V_253 , V_3 -> V_81 ,
V_254 * sizeof( T_7 ) ) ;
if ( F_34 ( V_220 , & V_122 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
return 0 ;
}
static long
F_64 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_255 V_122 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_80 )
return 0 ;
memcpy ( V_3 -> V_81 , V_122 . V_253 ,
V_254 * sizeof( T_7 ) ) ;
F_65 ( V_3 , V_3 -> V_81 ) ;
V_3 -> V_86 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_80 = F_66 ( V_87 ,
sizeof( struct V_82 ) , V_170 ) ;
if ( ! V_3 -> V_80 ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_171 ;
}
return 0 ;
}
static long
F_67 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_256 V_122 ;
T_7 V_257 , V_258 , V_259 ;
struct V_256 T_12 * V_260 = V_220 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_257 = V_122 . V_261 . V_262 -
sizeof( struct V_263 ) ;
V_258 = V_257 / sizeof( struct V_82 ) ;
V_259 = F_12 ( T_7 , V_87 , V_258 ) ;
if ( ! V_259 || ! V_3 -> V_80 )
return - V_212 ;
V_257 = V_259 * sizeof( struct V_82 ) ;
if ( F_34 ( V_260 -> V_264 , V_3 -> V_80 , V_257 ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
V_3 -> V_94 = 0 ;
return 0 ;
}
static long
F_68 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_265 V_122 ;
int V_266 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
if ( V_3 -> V_267 || V_3 -> V_268 ||
V_3 -> V_269 )
return - V_166 ;
F_33 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_105 ) ) ;
V_266 = F_56 ( V_3 , V_218 ,
V_219 ) ;
F_6 ( V_45 L_53 ,
V_3 -> V_46 , ( ( ! V_266 ) ? L_54 : L_55 ) ) ;
return 0 ;
}
static int
F_69 ( struct V_2 * V_3 ,
struct V_270 * V_271 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_272 = 0 ;
if ( F_70 ( & V_3 -> V_273 ) )
return V_272 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_271 -> V_237 == 0xFFFFFFFF && V_271 -> V_101 == 0xFFFFFFFF &&
V_271 -> V_4 == V_5 -> V_4 ) {
V_271 -> V_237 = V_5 -> V_274 ;
V_271 -> V_101 = V_5 -> V_101 ;
V_272 = 1 ;
goto V_7;
} else if ( V_271 -> V_237 == V_5 -> V_274 && V_271 -> V_101 ==
V_5 -> V_101 && V_271 -> V_4 == 0xFFFF ) {
V_271 -> V_4 = V_5 -> V_4 ;
V_272 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_51 , V_50 ) ;
return V_272 ;
}
static int
F_71 ( struct V_2 * V_3 ,
struct V_270 * V_271 )
{
struct V_275 * V_276 ;
unsigned long V_50 ;
int V_272 = 0 ;
if ( F_70 ( & V_3 -> V_277 ) )
return V_272 ;
F_8 ( & V_3 -> V_278 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_271 -> V_237 == 0xFFFFFFFF && V_271 -> V_101 == 0xFFFFFFFF &&
V_271 -> V_4 == V_276 -> V_4 ) {
V_271 -> V_237 = V_276 -> V_274 ;
V_271 -> V_101 = V_276 -> V_101 ;
V_272 = 1 ;
goto V_7;
} else if ( V_271 -> V_237 == V_276 -> V_274 && V_271 -> V_101 ==
V_276 -> V_101 && V_271 -> V_4 == 0xFFFF ) {
V_271 -> V_4 = V_276 -> V_4 ;
V_272 = 1 ;
goto V_7;
}
}
V_7:
F_9 ( & V_3 -> V_278 , V_50 ) ;
return V_272 ;
}
static long
F_72 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_270 V_122 ;
int V_272 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_272 = F_69 ( V_3 , & V_122 ) ;
if ( ! V_272 )
F_71 ( V_3 , & V_122 ) ;
if ( F_34 ( V_220 , & V_122 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
return 0 ;
}
static T_6
F_73 ( struct V_2 * V_3 , T_6 V_279 )
{
T_6 V_272 = 0 ;
switch ( V_279 ) {
case V_280 :
if ( V_3 -> V_179 . V_281 &
V_282 )
V_272 = 1 ;
break;
case V_283 :
if ( V_3 -> V_179 . V_281 &
V_284 )
V_272 = 1 ;
break;
case V_285 :
if ( V_3 -> V_179 . V_281 &
V_286 )
V_272 = 1 ;
}
return V_272 ;
}
static long
F_74 ( struct V_2 * V_3 ,
struct V_287 * V_288 )
{
int V_272 , V_78 ;
void * V_289 = NULL ;
T_14 V_290 ;
T_7 V_291 = 0 ;
T_18 * V_11 ;
T_19 * V_10 ;
T_6 V_279 ;
unsigned long V_154 ;
T_1 V_8 ;
T_1 V_152 ;
T_6 V_103 = 0 ;
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_165 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_279 = V_288 -> V_279 ;
if ( ! F_73 ( V_3 , V_279 ) ) {
F_6 ( V_165 L_57
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_292 ;
}
if ( V_3 -> V_107 [ V_279 ] &
V_108 ) {
F_6 ( V_165 L_59
L_60 , V_3 -> V_46 , V_105 ,
V_279 ) ;
return - V_174 ;
}
if ( V_288 -> V_293 % 4 ) {
F_6 ( V_165 L_61
L_62 , V_3 -> V_46 , V_105 ) ;
return - V_174 ;
}
V_8 = F_75 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_6 ( V_165 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_272 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_289 = V_3 -> V_294 [ V_279 ] ;
V_291 = V_288 -> V_293 ;
V_3 -> V_295 [ V_279 ] = V_288 -> V_295 ;
V_3 -> V_107 [ V_279 ] = 0 ;
memcpy ( V_3 -> V_296 [ V_279 ] ,
V_288 -> V_296 , V_297 ) ;
V_3 -> V_298 [ V_279 ] = V_288 -> V_298 ;
if ( V_289 ) {
V_290 = V_3 -> V_299 [ V_279 ] ;
if ( V_291 != V_3 -> V_300 [ V_279 ] ) {
F_57 ( V_3 -> V_181 ,
V_3 -> V_300 [ V_279 ] ,
V_289 , V_290 ) ;
V_289 = NULL ;
}
}
if ( V_289 == NULL ) {
V_3 -> V_300 [ V_279 ] = 0 ;
V_3 -> V_299 [ V_279 ] = 0 ;
V_289 = F_42 (
V_3 -> V_181 , V_291 , & V_290 ) ;
if ( V_289 == NULL ) {
F_6 ( V_165 L_63
L_64 ,
V_3 -> V_46 , V_105 , V_291 ) ;
F_25 ( V_3 , V_8 ) ;
return - V_171 ;
}
V_3 -> V_294 [ V_279 ] = V_289 ;
V_3 -> V_300 [ V_279 ] = V_291 ;
V_3 -> V_299 [ V_279 ] = V_290 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_301 = V_288 -> V_279 ;
V_11 -> V_302 = F_76 ( V_288 -> V_298 ) ;
V_11 -> V_303 = F_77 ( V_290 ) ;
V_11 -> V_304 = F_76 ( V_291 ) ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_33 ( V_3 , F_6 ( V_45 L_65
L_66 , V_3 -> V_46 , V_105 , V_289 ,
( unsigned long long ) V_290 ,
F_7 ( V_11 -> V_304 ) ) ) ;
for ( V_78 = 0 ; V_78 < V_297 ; V_78 ++ )
V_11 -> V_305 [ V_78 ] =
F_76 ( V_3 -> V_296 [ V_279 ] [ V_78 ] ) ;
F_44 ( & V_3 -> V_65 . V_76 ) ;
F_47 ( V_3 , V_8 ) ;
V_154 = F_51 ( & V_3 -> V_65 . V_76 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_165 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_53 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_207;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_165 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_152 = F_5 ( V_10 -> V_47 ) & V_208 ;
if ( V_152 == V_306 ) {
V_3 -> V_107 [ V_279 ] |=
V_108 ;
F_33 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_152 , F_7 ( V_10 -> V_48 ) ) ;
V_272 = - V_168 ;
}
V_207:
if ( V_103 )
F_56 ( V_3 , V_218 ,
V_219 ) ;
V_7:
if ( V_272 && V_289 )
F_57 ( V_3 -> V_181 , V_291 ,
V_289 , V_290 ) ;
V_3 -> V_65 . V_66 = V_67 ;
return V_272 ;
}
void
F_78 ( struct V_2 * V_3 , T_6 V_307 )
{
struct V_287 V_288 ;
memset ( & V_288 , 0 , sizeof( struct V_287 ) ) ;
if ( V_307 & 1 ) {
F_6 ( V_45 L_71 ,
V_3 -> V_46 ) ;
V_288 . V_279 = V_280 ;
V_288 . V_293 = ( 1024 * 1024 ) ;
V_288 . V_295 = 0x7075900 ;
F_74 ( V_3 , & V_288 ) ;
}
if ( V_307 & 2 ) {
F_6 ( V_45 L_72 ,
V_3 -> V_46 ) ;
V_288 . V_279 = V_283 ;
V_288 . V_293 = 2 * ( 1024 * 1024 ) ;
V_288 . V_295 = 0x7075901 ;
F_74 ( V_3 , & V_288 ) ;
}
if ( V_307 & 4 ) {
F_6 ( V_45 L_73 ,
V_3 -> V_46 ) ;
V_288 . V_279 = V_285 ;
V_288 . V_293 = 2 * ( 1024 * 1024 ) ;
V_288 . V_295 = 0x7075901 ;
F_74 ( V_3 , & V_288 ) ;
}
}
static long
F_79 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_287 V_122 ;
long V_272 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
V_272 = F_74 ( V_3 , & V_122 ) ;
return V_272 ;
}
static long
F_80 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_308 V_122 ;
void * V_289 ;
T_14 V_290 ;
T_7 V_291 ;
T_6 V_279 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = V_122 . V_295 & 0x000000ff ;
if ( ! F_73 ( V_3 , V_279 ) ) {
F_6 ( V_165 L_57
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_292 ;
}
if ( ( V_3 -> V_107 [ V_279 ] &
V_108 ) == 0 ) {
F_6 ( V_165 L_74
L_75 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_174 ;
}
if ( ( V_3 -> V_107 [ V_279 ] &
V_109 ) == 0 ) {
F_6 ( V_165 L_76
L_77 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_174 ;
}
if ( V_122 . V_295 != V_3 -> V_295 [ V_279 ] ) {
F_6 ( V_165 L_78
L_75 , V_3 -> V_46 , V_105 , V_122 . V_295 ) ;
return - V_174 ;
}
V_289 = V_3 -> V_294 [ V_279 ] ;
if ( ! V_289 ) {
F_6 ( V_165 L_79
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_171 ;
}
V_291 = V_3 -> V_300 [ V_279 ] ;
V_290 = V_3 -> V_299 [ V_279 ] ;
F_57 ( V_3 -> V_181 , V_291 ,
V_289 , V_290 ) ;
V_3 -> V_294 [ V_279 ] = NULL ;
V_3 -> V_107 [ V_279 ] = 0 ;
return 0 ;
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_309 V_122 ;
void * V_289 ;
int V_78 ;
T_6 V_279 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_122 . V_310 = 0 ;
V_279 = V_122 . V_279 ;
if ( ! F_73 ( V_3 , V_279 ) ) {
F_6 ( V_165 L_57
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_292 ;
}
if ( ( V_3 -> V_107 [ V_279 ] &
V_108 ) == 0 ) {
F_6 ( V_165 L_74
L_75 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_174 ;
}
if ( V_122 . V_295 & 0xffffff00 ) {
if ( V_122 . V_295 != V_3 -> V_295 [ V_279 ] ) {
F_6 ( V_165 L_78
L_75 , V_3 -> V_46 , V_105 ,
V_122 . V_295 ) ;
return - V_174 ;
}
}
V_289 = V_3 -> V_294 [ V_279 ] ;
if ( ! V_289 ) {
F_6 ( V_165 L_80
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_171 ;
}
if ( V_3 -> V_107 [ V_279 ] & V_109 )
V_122 . V_310 = ( V_311 |
V_312 ) ;
else
V_122 . V_310 = ( V_311 |
V_312 |
V_313 ) ;
for ( V_78 = 0 ; V_78 < V_297 ; V_78 ++ )
V_122 . V_296 [ V_78 ] =
V_3 -> V_296 [ V_279 ] [ V_78 ] ;
V_122 . V_314 = V_3 -> V_300 [ V_279 ] ;
V_122 . V_315 = 0 ;
V_122 . V_295 = V_3 -> V_295 [ V_279 ] ;
V_122 . V_298 = V_3 -> V_298 [ V_279 ] ;
if ( F_34 ( V_220 , & V_122 , sizeof( struct V_309 ) ) ) {
F_6 ( V_165 L_81
L_82 , V_3 -> V_46 , V_105 , V_220 ) ;
return - V_168 ;
}
return 0 ;
}
static int
F_24 ( struct V_2 * V_3 , T_6 V_279 , T_6 * V_103 )
{
T_20 * V_11 ;
T_21 * V_10 ;
T_1 V_8 ;
T_1 V_152 ;
T_7 V_151 ;
int V_272 ;
unsigned long V_154 ;
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_272 = 0 ;
* V_103 = 0 ;
V_151 = F_36 ( V_3 , 1 ) ;
if ( V_151 != V_167 ) {
F_33 ( V_3 , F_6 ( V_45 L_26
L_83 , V_3 -> V_46 ,
V_105 ) ) ;
V_272 = - V_166 ;
goto V_7;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_165 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_8 = F_75 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_6 ( V_165 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_301 = V_279 ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_44 ( & V_3 -> V_65 . V_76 ) ;
F_47 ( V_3 , V_8 ) ;
V_154 = F_51 ( & V_3 -> V_65 . V_76 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_165 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_53 ( V_11 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
* V_103 = 1 ;
V_272 = - V_168 ;
goto V_7;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_165 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_152 = F_5 ( V_10 -> V_47 ) & V_208 ;
if ( V_152 == V_306 ) {
V_3 -> V_107 [ V_279 ] |=
V_109 ;
F_33 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_152 , F_7 ( V_10 -> V_48 ) ) ;
V_272 = - V_168 ;
}
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_272 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_316 V_122 ;
void * V_289 ;
int V_272 ;
T_6 V_279 ;
T_6 V_103 = 0 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = V_122 . V_295 & 0x000000ff ;
if ( ! F_73 ( V_3 , V_279 ) ) {
F_6 ( V_165 L_57
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_292 ;
}
if ( ( V_3 -> V_107 [ V_279 ] &
V_108 ) == 0 ) {
F_6 ( V_165 L_74
L_75 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_174 ;
}
if ( V_122 . V_295 != V_3 -> V_295 [ V_279 ] ) {
F_6 ( V_165 L_78
L_75 , V_3 -> V_46 , V_105 , V_122 . V_295 ) ;
return - V_174 ;
}
if ( V_3 -> V_107 [ V_279 ] &
V_109 ) {
F_6 ( V_165 L_84
L_85 , V_3 -> V_46 , V_105 ,
V_279 ) ;
return 0 ;
}
V_289 = V_3 -> V_294 [ V_279 ] ;
if ( ! V_289 ) {
F_6 ( V_165 L_79
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_171 ;
}
if ( ( V_3 -> V_107 [ V_279 ] &
V_113 ) ) {
V_3 -> V_107 [ V_279 ] |=
V_109 ;
V_3 -> V_107 [ V_279 ] &=
~ V_113 ;
F_6 ( V_165 L_84
L_86 , V_3 -> V_46 , V_105 ,
V_279 ) ;
return 0 ;
}
V_272 = F_24 ( V_3 , V_279 , & V_103 ) ;
if ( V_103 )
F_56 ( V_3 , V_218 ,
V_219 ) ;
return V_272 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_220 )
{
struct V_317 V_122 ;
struct V_317 T_12 * V_260 = V_220 ;
void * V_289 , * V_318 ;
T_18 * V_11 ;
T_19 * V_10 ;
int V_272 , V_78 ;
T_6 V_279 ;
unsigned long V_154 , V_319 , V_320 ;
T_1 V_8 ;
T_1 V_152 ;
T_6 V_103 = 0 ;
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
F_33 ( V_3 , F_6 ( V_45 L_56 , V_3 -> V_46 ,
V_105 ) ) ;
V_279 = V_122 . V_295 & 0x000000ff ;
if ( ! F_73 ( V_3 , V_279 ) ) {
F_6 ( V_165 L_57
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_292 ;
}
if ( V_122 . V_295 != V_3 -> V_295 [ V_279 ] ) {
F_6 ( V_165 L_78
L_75 , V_3 -> V_46 , V_105 , V_122 . V_295 ) ;
return - V_174 ;
}
V_289 = V_3 -> V_294 [ V_279 ] ;
if ( ! V_289 ) {
F_6 ( V_165 L_80
L_58 , V_3 -> V_46 , V_105 , V_279 ) ;
return - V_171 ;
}
V_319 = V_3 -> V_300 [ V_279 ] ;
if ( ( V_122 . V_321 % 4 ) || ( V_122 . V_322 % 4 ) ) {
F_6 ( V_165 L_87
L_88 , V_3 -> V_46 ,
V_105 ) ;
return - V_174 ;
}
if ( V_122 . V_321 > V_319 )
return - V_174 ;
V_318 = ( void * ) ( V_289 + V_122 . V_321 ) ;
F_33 ( V_3 , F_6 ( V_45 L_89
L_90 , V_3 -> V_46 , V_105 ,
V_318 , V_122 . V_321 , V_122 . V_322 ) ) ;
if ( ( V_318 + V_122 . V_322 < V_318 ) ||
( V_318 + V_122 . V_322 > V_289 + V_319 ) )
V_320 = V_319 - V_122 . V_321 ;
else
V_320 = V_122 . V_322 ;
if ( F_34 ( ( void T_12 * ) V_260 -> V_323 ,
V_318 , V_320 ) ) {
F_6 ( V_165 L_91
L_92 , V_3 -> V_46 ,
V_105 , V_318 ) ;
return - V_168 ;
}
if ( ( V_122 . V_50 & V_324 ) == 0 )
return 0 ;
F_33 ( V_3 , F_6 ( V_45 L_93
L_58 , V_3 -> V_46 , V_105 , V_279 ) ) ;
if ( ( V_3 -> V_107 [ V_279 ] &
V_109 ) == 0 ) {
F_33 ( V_3 , F_6 ( V_45 L_26
L_94 , V_3 -> V_46 ,
V_105 , V_279 ) ) ;
return 0 ;
}
if ( V_3 -> V_65 . V_66 != V_67 ) {
F_6 ( V_165 L_35 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_8 = F_75 ( V_3 , V_3 -> V_175 ) ;
if ( ! V_8 ) {
F_6 ( V_165 L_42 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_166 ;
goto V_7;
}
V_272 = 0 ;
V_3 -> V_65 . V_66 = V_75 ;
memset ( V_3 -> V_65 . V_61 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_65 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_301 = V_279 ;
V_11 -> V_304 =
F_76 ( V_3 -> V_300 [ V_279 ] ) ;
V_11 -> V_303 =
F_77 ( V_3 -> V_299 [ V_279 ] ) ;
for ( V_78 = 0 ; V_78 < V_297 ; V_78 ++ )
V_11 -> V_305 [ V_78 ] =
F_76 ( V_3 -> V_296 [ V_279 ] [ V_78 ] ) ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_44 ( & V_3 -> V_65 . V_76 ) ;
F_47 ( V_3 , V_8 ) ;
V_154 = F_51 ( & V_3 -> V_65 . V_76 ,
V_205 * V_206 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_68 ) ) {
F_6 ( V_165 L_46 , V_3 -> V_46 ,
V_105 ) ;
F_53 ( V_11 ,
sizeof( T_18 ) / 4 ) ;
if ( ! ( V_3 -> V_65 . V_66 & V_111 ) )
V_103 = 1 ;
goto V_207;
}
if ( ( V_3 -> V_65 . V_66 & V_70 ) == 0 ) {
F_6 ( V_165 L_67 ,
V_3 -> V_46 , V_105 ) ;
V_272 = - V_168 ;
goto V_7;
}
V_10 = V_3 -> V_65 . V_61 ;
V_152 = F_5 ( V_10 -> V_47 ) & V_208 ;
if ( V_152 == V_306 ) {
V_3 -> V_107 [ V_279 ] |=
V_108 ;
F_33 ( V_3 , F_6 ( V_45 L_68 ,
V_3 -> V_46 , V_105 ) ) ;
} else {
F_6 ( V_45 L_69
L_70 , V_3 -> V_46 , V_105 ,
V_152 , F_7 ( V_10 -> V_48 ) ) ;
V_272 = - V_168 ;
}
V_207:
if ( V_103 )
F_56 ( V_3 , V_218 ,
V_219 ) ;
V_7:
V_3 -> V_65 . V_66 = V_67 ;
return V_272 ;
}
static long
F_84 ( struct V_2 * V_3 , unsigned V_325 ,
void T_12 * V_220 )
{
struct V_326 V_327 ;
struct V_326 T_12 * V_260 ;
struct V_121 V_122 ;
if ( F_85 ( V_325 ) != sizeof( struct V_326 ) )
return - V_174 ;
V_260 = (struct V_326 T_12 * ) V_220 ;
if ( F_39 ( & V_327 , ( char T_12 * ) V_220 , sizeof( V_327 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
memset ( & V_122 , 0 , sizeof( struct V_121 ) ) ;
V_122 . V_261 . V_99 = V_327 . V_261 . V_99 ;
V_122 . V_261 . V_227 = V_327 . V_261 . V_227 ;
V_122 . V_261 . V_262 = V_327 . V_261 . V_262 ;
V_122 . V_153 = V_327 . V_153 ;
V_122 . V_145 = V_327 . V_145 ;
V_122 . V_177 = V_327 . V_177 ;
V_122 . V_176 = V_327 . V_176 ;
V_122 . V_213 = V_327 . V_213 ;
V_122 . V_172 = V_327 . V_172 ;
V_122 . V_147 = F_86 ( V_327 . V_147 ) ;
V_122 . V_211 = F_86 ( V_327 . V_211 ) ;
V_122 . V_182 = F_86 ( V_327 . V_182 ) ;
V_122 . V_214 = F_86 ( V_327 . V_214 ) ;
return F_35 ( V_3 , V_122 , & V_260 -> V_149 ) ;
}
static long
F_87 ( struct V_115 * V_115 , unsigned int V_325 , void T_12 * V_220 ,
T_6 V_328 )
{
struct V_2 * V_3 ;
struct V_263 V_329 ;
enum V_330 V_331 ;
long V_163 = - V_174 ;
if ( F_39 ( & V_329 , ( char T_12 * ) V_220 ,
sizeof( struct V_263 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
return - V_168 ;
}
if ( F_21 ( V_329 . V_99 , & V_3 ) == - 1 || ! V_3 )
return - V_332 ;
if ( V_3 -> V_267 || V_3 -> V_268 ||
V_3 -> V_269 )
return - V_166 ;
V_331 = ( V_115 -> V_333 & V_334 ) ? V_335 : V_336 ;
if ( V_331 == V_335 ) {
if ( ! F_88 ( & V_3 -> V_65 . V_337 ) )
return - V_166 ;
} else if ( F_89 ( & V_3 -> V_65 . V_337 ) ) {
return - V_338 ;
}
switch ( V_325 ) {
case V_339 :
if ( F_85 ( V_325 ) == sizeof( struct V_221 ) )
V_163 = F_59 ( V_3 , V_220 ) ;
break;
#ifdef F_90
case V_340 :
#endif
case V_341 :
{
struct V_121 T_12 * V_260 ;
struct V_121 V_122 ;
#ifdef F_90
if ( V_328 ) {
V_163 = F_84 ( V_3 , V_325 , V_220 ) ;
break;
}
#endif
if ( F_39 ( & V_122 , V_220 , sizeof( V_122 ) ) ) {
F_6 ( V_148 L_33 ,
__FILE__ , __LINE__ , V_105 ) ;
V_163 = - V_168 ;
break;
}
if ( F_85 ( V_325 ) == sizeof( struct V_121 ) ) {
V_260 = V_220 ;
V_163 = F_35 ( V_3 , V_122 , & V_260 -> V_149 ) ;
}
break;
}
case V_342 :
if ( F_85 ( V_325 ) == sizeof( struct V_251 ) )
V_163 = F_63 ( V_3 , V_220 ) ;
break;
case V_343 :
if ( F_85 ( V_325 ) == sizeof( struct V_255 ) )
V_163 = F_64 ( V_3 , V_220 ) ;
break;
case V_344 :
V_163 = F_67 ( V_3 , V_220 ) ;
break;
case V_345 :
if ( F_85 ( V_325 ) == sizeof( struct V_265 ) )
V_163 = F_68 ( V_3 , V_220 ) ;
break;
case V_346 :
if ( F_85 ( V_325 ) == sizeof( struct V_270 ) )
V_163 = F_72 ( V_3 , V_220 ) ;
break;
case V_347 :
if ( F_85 ( V_325 ) == sizeof( struct V_287 ) )
V_163 = F_79 ( V_3 , V_220 ) ;
break;
case V_348 :
if ( F_85 ( V_325 ) == sizeof( struct V_308 ) )
V_163 = F_80 ( V_3 , V_220 ) ;
break;
case V_349 :
if ( F_85 ( V_325 ) == sizeof( struct V_309 ) )
V_163 = F_81 ( V_3 , V_220 ) ;
break;
case V_350 :
if ( F_85 ( V_325 ) == sizeof( struct V_316 ) )
V_163 = F_82 ( V_3 , V_220 ) ;
break;
case V_351 :
if ( F_85 ( V_325 ) == sizeof( struct V_317 ) )
V_163 = F_83 ( V_3 , V_220 ) ;
break;
default:
F_33 ( V_3 , F_6 ( V_45
L_95 , V_3 -> V_46 , V_325 ) ) ;
break;
}
F_91 ( & V_3 -> V_65 . V_337 ) ;
return V_163 ;
}
static long
F_92 ( struct V_115 * V_115 , unsigned int V_325 , unsigned long V_220 )
{
long V_163 ;
V_163 = F_87 ( V_115 , V_325 , ( void T_12 * ) V_220 , 0 ) ;
return V_163 ;
}
static long
F_93 ( struct V_115 * V_115 , unsigned V_325 , unsigned long V_220 )
{
long V_163 ;
V_163 = F_87 ( V_115 , V_325 , ( void T_12 * ) V_220 , 1 ) ;
return V_163 ;
}
static T_22
F_94 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_96 ,
( V_3 -> V_179 . V_243 . V_244 & 0xFF000000 ) >> 24 ,
( V_3 -> V_179 . V_243 . V_244 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_179 . V_243 . V_244 & 0x0000FF00 ) >> 8 ,
V_3 -> V_179 . V_243 . V_244 & 0x000000FF ) ;
}
static T_22
F_97 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
T_7 V_359 = F_7 ( V_3 -> V_249 . V_250 ) ;
return snprintf ( V_355 , V_358 , L_96 ,
( V_359 & 0xFF000000 ) >> 24 ,
( V_359 & 0x00FF0000 ) >> 16 ,
( V_359 & 0x0000FF00 ) >> 8 ,
V_359 & 0x000000FF ) ;
}
static T_22
F_98 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_97 ,
V_3 -> V_179 . V_360 , V_3 -> V_179 . V_361 >> 8 ) ;
}
static T_22
F_99 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_363 ) ;
}
static T_22
F_100 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 ,
F_7 ( V_3 -> V_364 . V_365 . V_244 ) ) ;
}
static T_22
F_101 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 ,
F_7 ( V_3 -> V_364 . V_366 . V_244 ) ) ;
}
static T_22
F_102 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_367 ) ;
}
static T_22
F_103 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_368 ) ;
}
static T_22
F_104 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , 16 , L_56 , V_3 -> V_362 . V_369 ) ;
}
static T_22
F_105 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_370 ) ;
}
static T_22
F_106 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_371 ) ;
}
static T_22
F_107 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_99 , V_3 -> V_179 . V_372 ) ;
}
static T_22
F_108 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_100 ,
( unsigned long long ) V_3 -> V_373 . V_54 ) ;
}
static T_22
F_109 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_98 , V_3 -> V_13 ) ;
}
static T_22
F_110 ( struct V_139 * V_352 , struct V_353 * V_354 ,
const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_101 , & V_375 ) != 1 )
return - V_174 ;
V_3 -> V_13 = V_375 ;
F_6 ( V_45 L_102 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_355 ) ;
}
static T_22
F_111 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_103 , V_3 -> V_376 ) ;
}
static T_22
F_112 ( struct V_139 * V_352 ,
struct V_353 * V_354 , const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_104 , & V_375 ) != 1 )
return - V_174 ;
V_3 -> V_376 = V_375 ;
F_6 ( V_45 L_105 , V_3 -> V_46 ,
V_3 -> V_376 ) ;
return strlen ( V_355 ) ;
}
static T_22
F_113 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
return snprintf ( V_355 , V_358 , L_106 , V_3 -> V_377 ) ;
}
static T_22
F_114 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
T_6 V_378 ;
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
if ( ( V_3 -> V_179 . V_281 &
V_379 ) && V_3 -> V_380 )
V_378 = V_3 -> V_378 ;
else
V_378 = 1 ;
return snprintf ( V_355 , V_358 , L_103 , V_378 ) ;
}
static T_22
F_115 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
T_23 * V_381 = NULL ;
T_24 V_10 ;
T_1 V_382 = 0 ;
T_1 V_152 ;
int V_64 ;
T_22 V_272 = 0 ;
if ( ! V_3 -> V_222 ) {
F_6 ( V_165 L_107\
L_108 , V_3 -> V_46 , V_105 ) ;
goto V_7;
}
V_64 = F_116 ( T_23 , V_383 ) + ( sizeof( T_1 ) * 36 ) ;
V_381 = F_38 ( V_64 , V_170 ) ;
if ( ! V_381 ) {
F_6 ( V_165 L_63\
L_109 , V_3 -> V_46 , V_105 , V_64 ) ;
goto V_7;
}
if ( F_117 ( V_3 , & V_10 , V_381 , V_64 ) !=
0 ) {
F_6 ( V_165
L_110 , V_3 -> V_46 ,
V_105 ) ;
goto V_7;
}
V_152 = F_5 ( V_10 . V_47 ) & V_208 ;
if ( V_152 != V_306 ) {
F_6 ( V_165 L_111\
L_112 , V_3 -> V_46 , V_105 , V_152 ) ;
goto V_7;
}
if ( V_381 -> V_384 < 25 ) {
F_6 ( V_165 L_113\
L_114 , V_3 -> V_46 , V_105 ,
V_381 -> V_384 ) ;
goto V_7;
}
V_382 = F_5 ( V_381 -> V_383 [ 24 ] ) ;
V_272 = snprintf ( V_355 , V_358 , L_103 , ( V_382 & 1 ) ) ;
V_7:
F_58 ( V_381 ) ;
return V_272 ;
}
static T_22
F_118 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
T_7 V_385 = 0 ;
struct V_386 * V_289 ;
if ( ! V_3 -> V_294 [ V_280 ] ) {
F_6 ( V_165 L_115
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) {
F_6 ( V_165 L_115
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
V_289 = (struct V_386 * )
V_3 -> V_294 [ V_280 ] ;
if ( ( F_7 ( V_289 -> V_387 ) == 0x00000000 ||
F_7 ( V_289 -> V_387 ) == 0x01000000 ) &&
F_7 ( V_289 -> V_388 ) == 0x4742444c )
V_385 = F_7 ( V_289 -> V_389 ) ;
V_3 -> V_390 = V_385 ;
return snprintf ( V_355 , V_358 , L_103 , V_385 ) ;
}
static T_22
F_119 ( struct V_139 * V_352 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
void * V_289 ;
T_7 V_385 ;
if ( ! V_3 -> V_294 [ V_280 ] ) {
F_6 ( V_165 L_115
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) {
F_6 ( V_165 L_115
L_75 , V_3 -> V_46 , V_105 ) ;
return 0 ;
}
if ( V_3 -> V_391 > V_3 -> V_390 )
return 0 ;
V_385 = V_3 -> V_390 - V_3 -> V_391 ;
V_385 = ( V_385 > V_358 ) ? V_358 : V_385 ;
V_289 = V_3 -> V_294 [ 0 ] + V_3 -> V_391 ;
memcpy ( V_355 , V_289 , V_385 ) ;
return V_385 ;
}
static T_22
F_120 ( struct V_139 * V_352 , struct V_353 * V_354 ,
const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
int V_375 = 0 ;
if ( sscanf ( V_355 , L_104 , & V_375 ) != 1 )
return - V_174 ;
V_3 -> V_391 = V_375 ;
return strlen ( V_355 ) ;
}
static T_22
F_121 ( struct V_139 * V_352 ,
struct V_353 * V_354 , char * V_355 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
if ( ( ! V_3 -> V_294 [ V_280 ] ) ||
( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 ) )
return snprintf ( V_355 , V_358 , L_116 ) ;
else if ( ( V_3 -> V_107 [ V_280 ] &
V_109 ) )
return snprintf ( V_355 , V_358 , L_117 ) ;
else
return snprintf ( V_355 , V_358 , L_118 ) ;
}
static T_22
F_122 ( struct V_139 * V_352 ,
struct V_353 * V_354 , const char * V_355 , T_15 V_374 )
{
struct V_356 * V_357 = F_95 ( V_352 ) ;
struct V_2 * V_3 = F_96 ( V_357 ) ;
char V_392 [ 10 ] = L_119 ;
struct V_287 V_288 ;
T_6 V_103 = 0 ;
if ( sscanf ( V_355 , L_120 , V_392 ) != 1 )
return - V_174 ;
if ( ! strcmp ( V_392 , L_121 ) ) {
if ( ( V_3 -> V_294 [ V_280 ] ) &&
( V_3 -> V_107 [ V_280 ] &
V_108 ) &&
( ( V_3 -> V_107 [ V_280 ] &
V_109 ) == 0 ) )
goto V_7;
memset ( & V_288 , 0 , sizeof( struct V_287 ) ) ;
F_6 ( V_45 L_122 ,
V_3 -> V_46 ) ;
V_288 . V_279 = V_280 ;
V_288 . V_293 = ( 1024 * 1024 ) ;
V_288 . V_295 = 0x7075900 ;
V_3 -> V_107 [ V_280 ] = 0 ;
F_74 ( V_3 , & V_288 ) ;
} else if ( ! strcmp ( V_392 , L_123 ) ) {
if ( ! V_3 -> V_294 [ V_280 ] )
goto V_7;
if ( ( V_3 -> V_107 [ V_280 ] &
V_108 ) == 0 )
goto V_7;
if ( ( V_3 -> V_107 [ V_280 ] &
V_109 ) )
goto V_7;
F_6 ( V_45 L_124 ,
V_3 -> V_46 ) ;
F_24 ( V_3 , V_280 , & V_103 ) ;
}
V_7:
return strlen ( V_355 ) ;
}
static T_22
F_123 ( struct V_139 * V_393 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_394 * V_395 = F_124 ( V_393 ) ;
struct V_127 * V_396 = V_395 -> V_140 ;
return snprintf ( V_355 , V_358 , L_100 ,
( unsigned long long ) V_396 -> V_141 -> V_54 ) ;
}
static T_22
F_125 ( struct V_139 * V_393 , struct V_353 * V_354 ,
char * V_355 )
{
struct V_394 * V_395 = F_124 ( V_393 ) ;
struct V_127 * V_396 = V_395 -> V_140 ;
return snprintf ( V_355 , V_358 , L_125 ,
V_396 -> V_141 -> V_4 ) ;
}
void
F_126 ( void )
{
V_96 = NULL ;
if ( F_127 ( & V_397 ) < 0 )
F_6 ( V_148 L_126 ,
V_246 , V_398 ) ;
F_128 ( & V_95 ) ;
}
void
F_129 ( void )
{
struct V_2 * V_3 ;
int V_78 ;
F_2 (ioc, &mpt2sas_ioc_list, list) {
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ! V_3 -> V_294 [ V_78 ] )
continue;
F_57 ( V_3 -> V_181 , V_3 -> V_300 [ V_78 ] ,
V_3 -> V_294 [ V_78 ] , V_3 -> V_299 [ V_78 ] ) ;
V_3 -> V_294 [ V_78 ] = NULL ;
V_3 -> V_107 [ V_78 ] = 0 ;
}
F_58 ( V_3 -> V_80 ) ;
}
F_130 ( & V_397 ) ;
}
