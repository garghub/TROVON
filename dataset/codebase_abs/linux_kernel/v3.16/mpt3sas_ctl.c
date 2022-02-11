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
#ifdef F_15
F_3 ( V_3 , V_8 , L_24 , V_10 ) ;
#endif
V_3 -> V_64 . V_65 &= ~ V_74 ;
F_16 ( & V_3 -> V_64 . V_75 ) ;
return 1 ;
}
static int
F_17 ( struct V_2 * V_3 , T_1 V_76 )
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
F_18 ( struct V_2 * V_3 ,
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
if ( F_17 ( V_3 , V_76 ) ) {
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
F_19 ( & V_94 ) ;
if ( V_95 )
F_20 ( & V_95 , V_96 , V_97 ) ;
}
}
T_6
F_21 ( struct V_2 * V_3 , T_6 V_59 ,
T_7 V_60 )
{
T_8 * V_10 ;
V_10 = F_12 ( V_3 , V_60 ) ;
F_18 ( V_3 , V_10 ) ;
return 1 ;
}
static int
F_22 ( int V_98 , struct V_2 * * V_99 )
{
struct V_2 * V_3 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_100 != V_98 )
continue;
* V_99 = V_3 ;
return V_98 ;
}
* V_99 = NULL ;
return - 1 ;
}
void
F_23 ( struct V_2 * V_3 , int V_101 )
{
int V_77 ;
T_6 V_102 ;
switch ( V_101 ) {
case V_103 :
F_24 ( V_3 , F_6 ( V_45
L_25 , V_3 -> V_46 , V_104 ) ) ;
for ( V_77 = 0 ; V_77 < V_105 ; V_77 ++ ) {
if ( ! ( V_3 -> V_106 [ V_77 ] &
V_107 ) )
continue;
if ( ( V_3 -> V_106 [ V_77 ] &
V_108 ) )
continue;
F_25 ( V_3 , V_77 , & V_102 ) ;
}
break;
case V_109 :
F_24 ( V_3 , F_6 ( V_45
L_26 , V_3 -> V_46 , V_104 ) ) ;
if ( V_3 -> V_64 . V_65 & V_74 ) {
V_3 -> V_64 . V_65 |= V_110 ;
F_26 ( V_3 , V_3 -> V_64 . V_8 ) ;
F_16 ( & V_3 -> V_64 . V_75 ) ;
}
break;
case V_111 :
F_24 ( V_3 , F_6 ( V_45
L_27 , V_3 -> V_46 , V_104 ) ) ;
for ( V_77 = 0 ; V_77 < V_105 ; V_77 ++ ) {
if ( ! ( V_3 -> V_106 [ V_77 ] &
V_107 ) )
continue;
if ( ( V_3 -> V_106 [ V_77 ] &
V_108 ) )
continue;
V_3 -> V_106 [ V_77 ] |=
V_112 ;
}
break;
}
}
static int
F_27 ( int V_113 , struct V_114 * V_115 , int V_116 )
{
return F_28 ( V_113 , V_115 , V_116 , & V_95 ) ;
}
static unsigned int
F_29 ( struct V_114 * V_115 , T_9 * V_117 )
{
struct V_2 * V_3 ;
F_30 ( V_115 , & V_94 , V_117 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_93 )
return V_118 | V_119 ;
}
return 0 ;
}
static int
F_31 ( struct V_2 * V_3 , struct V_120 * V_121 ,
T_10 * V_122 )
{
T_6 V_123 = 0 ;
T_1 V_77 ;
T_1 V_4 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
unsigned long V_50 ;
T_11 * V_128 ;
T_7 V_63 ;
T_7 V_129 ;
char * V_12 = NULL ;
if ( V_122 -> V_130 == V_131 )
V_12 = L_28 ;
else if ( V_122 -> V_130 == V_132 )
V_12 = L_29 ;
else
return 0 ;
V_129 = F_32 ( (struct V_133 * ) V_122 -> V_134 ) ;
V_4 = F_5 ( V_122 -> V_52 ) ;
F_8 ( & V_3 -> V_135 , V_50 ) ;
for ( V_77 = V_3 -> V_136 ; V_77 && ! V_123 ; V_77 -- ) {
V_125 = V_3 -> V_137 [ V_77 - 1 ] . V_125 ;
if ( V_125 == NULL || V_125 -> V_138 == NULL ||
V_125 -> V_138 -> V_139 == NULL )
continue;
if ( V_129 != V_125 -> V_138 -> V_129 )
continue;
V_127 = V_125 -> V_138 -> V_139 ;
if ( V_127 -> V_140 == NULL )
continue;
if ( V_127 -> V_140 -> V_4 != V_4 )
continue;
V_122 -> V_141 = F_33 ( V_3 -> V_137 [ V_77 - 1 ] . V_8 ) ;
V_123 = 1 ;
}
F_10 ( & V_3 -> V_135 , V_50 ) ;
if ( ! V_123 ) {
F_34 ( V_3 , F_6 ( V_45
L_30 ,
V_3 -> V_46 ,
V_12 , F_5 ( V_122 -> V_52 ) , V_129 ) ) ;
V_128 = V_3 -> V_64 . V_60 ;
V_128 -> V_52 = V_122 -> V_52 ;
V_128 -> V_15 = V_23 ;
V_128 -> V_130 = V_122 -> V_130 ;
V_128 -> V_68 = sizeof( T_11 ) / 4 ;
V_128 -> V_142 = V_122 -> V_142 ;
V_128 -> V_143 = V_122 -> V_143 ;
V_63 = F_13 ( T_7 , V_121 -> V_144 , V_3 -> V_145 ) ;
if ( F_35 ( V_121 -> V_146 , V_3 -> V_64 . V_60 ,
V_63 ) )
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
return 1 ;
}
F_34 ( V_3 , F_6 ( V_45
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_122 -> V_52 ) , V_129 ,
F_5 ( V_122 -> V_141 ) ) ) ;
return 0 ;
}
static long
F_37 ( struct V_2 * V_3 , struct V_120 V_121 ,
void T_12 * V_147 )
{
T_13 * V_11 = NULL , * V_148 ;
T_2 * V_10 ;
T_7 V_149 ;
T_1 V_150 ;
T_1 V_8 ;
unsigned long V_151 , V_152 ;
T_6 V_102 ;
T_7 V_63 ;
void * V_153 ;
void * V_154 = NULL ;
T_14 V_155 = 0 ;
T_15 V_156 = 0 ;
void * V_157 = NULL ;
T_14 V_158 = 0 ;
T_15 V_159 = 0 ;
long V_160 ;
T_1 V_161 ;
V_102 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_36 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_160 = - V_162 ;
goto V_7;
}
V_161 = 0 ;
V_149 = F_38 ( V_3 , 1 ) ;
while ( V_149 != V_163 ) {
if ( V_161 ++ == 10 ) {
F_36 ( V_45
L_34 ,
V_3 -> V_46 , V_104 ) ;
V_160 = - V_164 ;
goto V_7;
}
F_39 ( 1 ) ;
V_149 = F_38 ( V_3 , 1 ) ;
F_6 ( V_45
L_35 ,
V_3 -> V_46 ,
V_104 , V_161 ) ;
}
if ( V_161 )
F_6 ( V_45 L_36 ,
V_3 -> V_46 , V_104 ) ;
V_11 = F_40 ( V_3 -> V_165 , V_166 ) ;
if ( ! V_11 ) {
F_36 ( V_45
L_37 ,
V_3 -> V_46 , V_104 ) ;
V_160 = - V_167 ;
goto V_7;
}
if ( V_121 . V_168 * 4 > V_3 -> V_165 ||
V_121 . V_168 > ( V_169 / 4 ) ) {
V_160 = - V_170 ;
goto V_7;
}
if ( F_41 ( V_11 , V_147 , V_121 . V_168 * 4 ) ) {
F_36 ( L_31 , __FILE__ , __LINE__ ,
V_104 ) ;
V_160 = - V_164 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_42 ( V_3 , V_3 -> V_171 ) ;
if ( ! V_8 ) {
F_36 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_160 = - V_162 ;
goto V_7;
}
} else {
V_8 = F_43 ( V_3 , V_3 -> V_171 , NULL ) ;
if ( ! V_8 ) {
F_36 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_160 = - V_162 ;
goto V_7;
}
}
V_160 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_145 ) ;
V_148 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_148 , V_11 , V_121 . V_168 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_156 = V_121 . V_172 ;
V_159 = V_121 . V_173 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_174 ) ||
F_5 ( V_11 -> V_174 ) >
V_3 -> V_175 . V_176 ) {
V_160 = - V_170 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_156 ) {
V_154 = F_44 ( V_3 -> V_177 , V_156 ,
& V_155 ) ;
if ( ! V_154 ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_167 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_41 ( V_154 , V_121 . V_178 ,
V_156 ) ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_164 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_159 ) {
V_157 = F_44 ( V_3 -> V_177 , V_159 ,
& V_158 ) ;
if ( ! V_157 ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_167 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_153 = ( void * ) V_148 + ( V_121 . V_168 * 4 ) ;
#ifdef F_15
F_3 ( V_3 , V_8 , L_39 , NULL ) ;
#endif
F_45 ( & V_3 -> V_64 . V_75 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_179 =
( T_4 * ) V_148 ;
V_179 -> V_180 = V_71 ;
V_179 -> V_181 =
F_46 ( V_3 , V_8 ) ;
memset ( V_3 -> V_64 . V_73 , 0 , V_71 ) ;
V_3 -> V_182 ( V_3 , V_153 , V_155 , V_156 ,
V_158 , V_159 ) ;
if ( V_11 -> V_15 == V_16 )
F_47 ( V_3 , V_8 ,
F_5 ( V_11 -> V_174 ) ) ;
else
F_48 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_122 =
( T_10 * ) V_148 ;
F_24 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 ,
F_5 ( V_122 -> V_52 ) , V_122 -> V_130 ) ) ;
if ( V_122 -> V_130 ==
V_131 ||
V_122 -> V_130 ==
V_132 ) {
if ( F_31 ( V_3 , & V_121 , V_122 ) ) {
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_49 ( V_3 , F_5 (
V_122 -> V_52 ) ) ;
V_3 -> V_183 ( V_3 , V_153 , V_155 , V_156 ,
V_158 , V_159 ) ;
F_50 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_184 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_184 -> V_185 = 0xFF ;
if ( V_184 -> V_186 &
V_187 )
V_90 = ( T_6 * ) & V_184 -> V_188 ;
else {
if ( F_51 ( V_154 == NULL ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
F_26 ( V_3 , V_8 ) ;
V_160 = - V_170 ;
goto V_7;
}
V_90 = V_154 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_189 = 1 ;
V_3 -> V_190 = 1 ;
}
V_3 -> V_182 ( V_3 , V_153 , V_155 , V_156 , V_158 ,
V_159 ) ;
F_48 ( V_3 , V_8 ) ;
break;
}
case V_41 :
case V_36 :
case V_37 :
{
V_3 -> V_182 ( V_3 , V_153 , V_155 , V_156 , V_158 ,
V_159 ) ;
F_48 ( V_3 , V_8 ) ;
break;
}
case V_191 :
{
T_17 * V_192 =
( T_17 * ) V_11 ;
if ( V_192 -> V_193 == V_194 ) {
V_3 -> V_182 ( V_3 , V_153 , V_155 , V_156 ,
V_158 , V_159 ) ;
} else {
V_3 -> V_183 ( V_3 , V_153 , V_155 , V_156 ,
V_158 , V_159 ) ;
}
F_48 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_195 =
( T_18 * ) V_11 ;
if ( V_195 -> V_196 == V_197
|| V_195 -> V_196 ==
V_198 ) {
V_3 -> V_189 = 1 ;
V_3 -> V_190 = 1 ;
}
}
default:
V_3 -> V_183 ( V_3 , V_153 , V_155 , V_156 ,
V_158 , V_159 ) ;
F_48 ( V_3 , V_8 ) ;
break;
}
if ( V_121 . V_151 < V_199 )
V_151 = V_199 ;
else
V_151 = V_121 . V_151 ;
V_152 = F_52 ( & V_3 -> V_64 . V_75 ,
V_151 * V_200 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_122 =
( T_10 * ) V_11 ;
F_53 ( V_3 , F_5 (
V_122 -> V_52 ) ) ;
F_54 ( V_3 , V_201 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_189 ) {
V_3 -> V_189 = 0 ;
V_3 -> V_190 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_36 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_55 ( V_11 , V_121 . V_168 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_202;
}
V_10 = V_3 -> V_64 . V_60 ;
V_150 = F_5 ( V_10 -> V_47 ) & V_203 ;
#ifdef F_15
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_204 ) ) {
T_11 * V_128 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_42 \
L_43
L_44 , V_3 -> V_46 ,
F_5 ( V_128 -> V_47 ) ,
F_7 ( V_128 -> V_48 ) ,
F_7 ( V_128 -> V_205 ) ) ;
}
#endif
if ( V_159 ) {
if ( F_35 ( V_121 . V_206 , V_157 ,
V_159 ) ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_207 ;
goto V_7;
}
}
if ( V_121 . V_144 ) {
V_63 = F_13 ( T_7 , V_121 . V_144 , V_3 -> V_145 ) ;
if ( F_35 ( V_121 . V_146 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_207 ;
goto V_7;
}
}
if ( V_121 . V_208 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_121 . V_208 , V_71 ) ;
if ( F_35 ( V_121 . V_209 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_36 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_160 = - V_207 ;
goto V_7;
}
}
V_202:
if ( V_102 ) {
V_160 = - V_207 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_45 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_174 ) ) ;
F_56 ( V_3 ) ;
F_57 ( V_3 ,
F_5 ( V_11 -> V_174 ) , 0 , 0 ,
0 , V_210 , 0 , 30 ,
V_211 ) ;
} else
F_58 ( V_3 , V_212 ,
V_213 ) ;
}
V_7:
if ( V_157 )
F_59 ( V_3 -> V_177 , V_159 , V_157 ,
V_158 ) ;
if ( V_154 )
F_59 ( V_3 -> V_177 , V_156 , V_154 ,
V_155 ) ;
F_60 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_160 ;
}
static long
F_61 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_215 V_121 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_216 = V_217 ;
if ( V_3 -> V_218 )
V_121 . V_219 = V_3 -> V_218 [ 0 ] . V_220 ;
V_121 . V_221 = V_3 -> V_177 -> V_222 ;
V_121 . V_223 = V_3 -> V_177 -> V_138 ;
V_121 . V_224 = V_3 -> V_177 -> V_224 ;
V_121 . V_225 = V_3 -> V_177 -> V_225 ;
V_121 . V_226 . V_227 . V_228 . V_229 = V_3 -> V_177 -> V_229 -> V_230 ;
V_121 . V_226 . V_227 . V_228 . V_138 = F_62 ( V_3 -> V_177 -> V_231 ) ;
V_121 . V_226 . V_227 . V_228 . V_232 = F_63 ( V_3 -> V_177 -> V_231 ) ;
V_121 . V_226 . V_233 = F_64 ( V_3 -> V_177 -> V_229 ) ;
V_121 . V_234 = V_3 -> V_175 . V_235 . V_236 ;
strcpy ( V_121 . V_237 , V_238 ) ;
strcat ( V_121 . V_237 , L_47 ) ;
strcat ( V_121 . V_237 , V_239 ) ;
V_121 . V_240 = F_7 ( V_3 -> V_241 . V_242 ) ;
if ( F_35 ( V_214 , & V_121 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
return 0 ;
}
static long
F_65 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_243 V_121 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_121 . V_244 = V_86 ;
memcpy ( V_121 . V_245 , V_3 -> V_80 ,
V_246 * sizeof( T_7 ) ) ;
if ( F_35 ( V_214 , & V_121 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_247 V_121 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
memcpy ( V_3 -> V_80 , V_121 . V_245 ,
V_246 * sizeof( T_7 ) ) ;
F_67 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_68 ( V_86 ,
sizeof( struct V_81 ) , V_166 ) ;
if ( ! V_3 -> V_79 ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_167 ;
}
return 0 ;
}
static long
F_69 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_248 V_121 ;
T_7 V_249 , V_250 , V_251 ;
struct V_248 T_12 * V_252 = V_214 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_249 = V_121 . V_253 . V_254 -
sizeof( struct V_255 ) ;
V_250 = V_249 / sizeof( struct V_81 ) ;
V_251 = F_13 ( T_7 , V_86 , V_250 ) ;
if ( ! V_251 || ! V_3 -> V_79 )
return - V_207 ;
V_249 = V_251 * sizeof( struct V_81 ) ;
if ( F_35 ( V_252 -> V_256 , V_3 -> V_79 , V_249 ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_257 V_121 ;
int V_258 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
if ( V_3 -> V_259 || V_3 -> V_260 ||
V_3 -> V_261 )
return - V_162 ;
F_34 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_258 = F_58 ( V_3 , V_212 ,
V_213 ) ;
F_6 ( V_45 L_48 ,
V_3 -> V_46 , ( ( ! V_258 ) ? L_49 : L_50 ) ) ;
return 0 ;
}
static int
F_71 ( struct V_2 * V_3 ,
struct V_262 * V_263 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_264 = 0 ;
if ( F_72 ( & V_3 -> V_265 ) )
return V_264 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_263 -> V_229 == 0xFFFFFFFF && V_263 -> V_100 == 0xFFFFFFFF &&
V_263 -> V_4 == V_5 -> V_4 ) {
V_263 -> V_229 = V_5 -> V_266 ;
V_263 -> V_100 = V_5 -> V_100 ;
V_264 = 1 ;
goto V_7;
} else if ( V_263 -> V_229 == V_5 -> V_266 && V_263 -> V_100 ==
V_5 -> V_100 && V_263 -> V_4 == 0xFFFF ) {
V_263 -> V_4 = V_5 -> V_4 ;
V_264 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_264 ;
}
static int
F_73 ( struct V_2 * V_3 ,
struct V_262 * V_263 )
{
struct V_267 * V_268 ;
unsigned long V_50 ;
int V_264 = 0 ;
if ( F_72 ( & V_3 -> V_269 ) )
return V_264 ;
F_8 ( & V_3 -> V_270 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_263 -> V_229 == 0xFFFFFFFF && V_263 -> V_100 == 0xFFFFFFFF &&
V_263 -> V_4 == V_268 -> V_4 ) {
V_263 -> V_229 = V_268 -> V_266 ;
V_263 -> V_100 = V_268 -> V_100 ;
V_264 = 1 ;
goto V_7;
} else if ( V_263 -> V_229 == V_268 -> V_266 && V_263 -> V_100 ==
V_268 -> V_100 && V_263 -> V_4 == 0xFFFF ) {
V_263 -> V_4 = V_268 -> V_4 ;
V_264 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_270 , V_50 ) ;
return V_264 ;
}
static long
F_74 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_262 V_121 ;
int V_264 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_264 = F_71 ( V_3 , & V_121 ) ;
if ( ! V_264 )
F_73 ( V_3 , & V_121 ) ;
if ( F_35 ( V_214 , & V_121 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
return 0 ;
}
static T_6
F_75 ( struct V_2 * V_3 , T_6 V_271 )
{
T_6 V_264 = 0 ;
switch ( V_271 ) {
case V_272 :
if ( V_3 -> V_175 . V_273 &
V_274 )
V_264 = 1 ;
break;
case V_275 :
if ( V_3 -> V_175 . V_273 &
V_276 )
V_264 = 1 ;
break;
case V_277 :
if ( V_3 -> V_175 . V_273 &
V_278 )
V_264 = 1 ;
}
return V_264 ;
}
static long
F_76 ( struct V_2 * V_3 ,
struct V_279 * V_280 )
{
int V_264 , V_77 ;
void * V_281 = NULL ;
T_14 V_282 ;
T_7 V_283 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_271 ;
unsigned long V_152 ;
T_1 V_8 ;
T_1 V_150 ;
T_7 V_149 ;
T_6 V_102 = 0 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_149 = F_38 ( V_3 , 1 ) ;
if ( V_149 != V_163 ) {
F_36 ( V_45
L_34 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_36 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_271 = V_280 -> V_271 ;
if ( ! F_75 ( V_3 , V_271 ) ) {
F_36 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_284 ;
}
if ( V_3 -> V_106 [ V_271 ] &
V_107 ) {
F_36 ( V_45
L_53 ,
V_3 -> V_46 , V_104 ,
V_271 ) ;
return - V_170 ;
}
if ( V_280 -> V_285 % 4 ) {
F_36 ( V_45
L_54 ,
V_3 -> V_46 , V_104 ) ;
return - V_170 ;
}
V_8 = F_77 ( V_3 , V_3 -> V_171 ) ;
if ( ! V_8 ) {
F_36 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_264 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_145 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_281 = V_3 -> V_286 [ V_271 ] ;
V_283 = V_280 -> V_285 ;
V_3 -> V_287 [ V_271 ] = V_280 -> V_287 ;
V_3 -> V_106 [ V_271 ] = 0 ;
memcpy ( V_3 -> V_288 [ V_271 ] ,
V_280 -> V_288 , V_289 ) ;
V_3 -> V_290 [ V_271 ] = V_280 -> V_290 ;
if ( V_281 ) {
V_282 = V_3 -> V_291 [ V_271 ] ;
if ( V_283 != V_3 -> V_292 [ V_271 ] ) {
F_59 ( V_3 -> V_177 ,
V_3 -> V_292 [ V_271 ] ,
V_281 , V_282 ) ;
V_281 = NULL ;
}
}
if ( V_281 == NULL ) {
V_3 -> V_292 [ V_271 ] = 0 ;
V_3 -> V_291 [ V_271 ] = 0 ;
V_281 = F_44 (
V_3 -> V_177 , V_283 , & V_282 ) ;
if ( V_281 == NULL ) {
F_36 ( V_45 L_55 \
L_56 ,
V_3 -> V_46 , V_104 , V_283 ) ;
F_26 ( V_3 , V_8 ) ;
return - V_167 ;
}
V_3 -> V_286 [ V_271 ] = V_281 ;
V_3 -> V_292 [ V_271 ] = V_283 ;
V_3 -> V_291 [ V_271 ] = V_282 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_293 = V_280 -> V_271 ;
V_11 -> V_294 = F_78 ( V_280 -> V_290 ) ;
V_11 -> V_295 = F_79 ( V_282 ) ;
V_11 -> V_296 = F_78 ( V_283 ) ;
V_11 -> V_143 = 0 ;
V_11 -> V_142 = 0 ;
F_34 ( V_3 , F_6 ( V_45
L_57 ,
V_3 -> V_46 , V_104 , V_281 ,
( unsigned long long ) V_282 ,
F_7 ( V_11 -> V_296 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_289 ; V_77 ++ )
V_11 -> V_297 [ V_77 ] =
F_78 ( V_3 -> V_288 [ V_271 ] [ V_77 ] ) ;
F_45 ( & V_3 -> V_64 . V_75 ) ;
F_48 ( V_3 , V_8 ) ;
V_152 = F_52 ( & V_3 -> V_64 . V_75 ,
V_199 * V_200 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_36 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_55 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_202;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_36 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_164 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_150 = F_5 ( V_10 -> V_47 ) & V_203 ;
if ( V_150 == V_298 ) {
V_3 -> V_106 [ V_271 ] |=
V_107 ;
F_34 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_150 , F_7 ( V_10 -> V_48 ) ) ;
V_264 = - V_164 ;
}
V_202:
if ( V_102 )
F_58 ( V_3 , V_212 ,
V_213 ) ;
V_7:
if ( V_264 && V_281 )
F_59 ( V_3 -> V_177 , V_283 ,
V_281 , V_282 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_264 ;
}
void
F_80 ( struct V_2 * V_3 , T_6 V_299 )
{
struct V_279 V_280 ;
memset ( & V_280 , 0 , sizeof( struct V_279 ) ) ;
if ( V_299 & 1 ) {
F_6 ( V_45 L_61 ,
V_3 -> V_46 ) ;
V_3 -> V_300 . V_301 =
( V_302 + V_303 ) ;
V_280 . V_271 = V_272 ;
V_280 . V_285 = 2 * ( 1024 * 1024 ) ;
V_280 . V_287 = 0x7075900 ;
F_76 ( V_3 , & V_280 ) ;
}
if ( V_299 & 2 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_280 . V_271 = V_275 ;
V_280 . V_285 = 2 * ( 1024 * 1024 ) ;
V_280 . V_287 = 0x7075901 ;
F_76 ( V_3 , & V_280 ) ;
}
if ( V_299 & 4 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_280 . V_271 = V_277 ;
V_280 . V_285 = 2 * ( 1024 * 1024 ) ;
V_280 . V_287 = 0x7075901 ;
F_76 ( V_3 , & V_280 ) ;
}
}
static long
F_81 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_279 V_121 ;
long V_264 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
V_264 = F_76 ( V_3 , & V_121 ) ;
return V_264 ;
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_304 V_121 ;
void * V_281 ;
T_14 V_282 ;
T_7 V_283 ;
T_6 V_271 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_271 = V_121 . V_287 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_271 ) ) {
F_36 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_284 ;
}
if ( ( V_3 -> V_106 [ V_271 ] &
V_107 ) == 0 ) {
F_36 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_170 ;
}
if ( ( V_3 -> V_106 [ V_271 ] &
V_108 ) == 0 ) {
F_36 ( V_45
L_65 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_170 ;
}
if ( V_121 . V_287 != V_3 -> V_287 [ V_271 ] ) {
F_36 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_121 . V_287 ) ;
return - V_170 ;
}
V_281 = V_3 -> V_286 [ V_271 ] ;
if ( ! V_281 ) {
F_36 ( V_45
L_67 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_167 ;
}
V_283 = V_3 -> V_292 [ V_271 ] ;
V_282 = V_3 -> V_291 [ V_271 ] ;
F_59 ( V_3 -> V_177 , V_283 ,
V_281 , V_282 ) ;
V_3 -> V_286 [ V_271 ] = NULL ;
V_3 -> V_106 [ V_271 ] = 0 ;
return 0 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_305 V_121 ;
void * V_281 ;
int V_77 ;
T_6 V_271 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_121 . V_306 = 0 ;
V_271 = V_121 . V_271 ;
if ( ! F_75 ( V_3 , V_271 ) ) {
F_36 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_284 ;
}
if ( ( V_3 -> V_106 [ V_271 ] &
V_107 ) == 0 ) {
F_36 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_170 ;
}
if ( V_121 . V_287 & 0xffffff00 ) {
if ( V_121 . V_287 != V_3 -> V_287 [ V_271 ] ) {
F_36 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_121 . V_287 ) ;
return - V_170 ;
}
}
V_281 = V_3 -> V_286 [ V_271 ] ;
if ( ! V_281 ) {
F_36 ( V_45
L_68 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_167 ;
}
if ( V_3 -> V_106 [ V_271 ] & V_108 )
V_121 . V_306 = ( V_307 |
V_308 ) ;
else
V_121 . V_306 = ( V_307 |
V_308 |
V_309 ) ;
for ( V_77 = 0 ; V_77 < V_289 ; V_77 ++ )
V_121 . V_288 [ V_77 ] =
V_3 -> V_288 [ V_271 ] [ V_77 ] ;
V_121 . V_310 = V_3 -> V_292 [ V_271 ] ;
V_121 . V_311 = 0 ;
V_121 . V_287 = V_3 -> V_287 [ V_271 ] ;
V_121 . V_290 = V_3 -> V_290 [ V_271 ] ;
if ( F_35 ( V_214 , & V_121 , sizeof( struct V_305 ) ) ) {
F_36 ( V_45
L_69 ,
V_3 -> V_46 , V_104 , V_214 ) ;
return - V_164 ;
}
return 0 ;
}
int
F_25 ( struct V_2 * V_3 , T_6 V_271 ,
T_6 * V_102 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_150 ;
T_7 V_149 ;
int V_264 ;
unsigned long V_152 ;
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_264 = 0 ;
* V_102 = 0 ;
V_149 = F_38 ( V_3 , 1 ) ;
if ( V_149 != V_163 ) {
if ( V_3 -> V_106 [ V_271 ] &
V_107 )
V_3 -> V_106 [ V_271 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45
L_70 , V_3 -> V_46 ,
V_104 ) ) ;
V_264 = - V_162 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_36 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_8 = F_77 ( V_3 , V_3 -> V_171 ) ;
if ( ! V_8 ) {
F_36 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_145 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_293 = V_271 ;
V_11 -> V_143 = 0 ;
V_11 -> V_142 = 0 ;
F_45 ( & V_3 -> V_64 . V_75 ) ;
F_48 ( V_3 , V_8 ) ;
V_152 = F_52 ( & V_3 -> V_64 . V_75 ,
V_199 * V_200 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_36 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_55 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
* V_102 = 1 ;
V_264 = - V_164 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_36 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_164 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_150 = F_5 ( V_10 -> V_47 ) & V_203 ;
if ( V_150 == V_298 ) {
V_3 -> V_106 [ V_271 ] |=
V_108 ;
F_34 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_150 , F_7 ( V_10 -> V_48 ) ) ;
V_264 = - V_164 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_264 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_312 V_121 ;
void * V_281 ;
int V_264 ;
T_6 V_271 ;
T_6 V_102 = 0 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_271 = V_121 . V_287 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_271 ) ) {
F_36 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_284 ;
}
if ( ( V_3 -> V_106 [ V_271 ] &
V_107 ) == 0 ) {
F_36 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_170 ;
}
if ( V_121 . V_287 != V_3 -> V_287 [ V_271 ] ) {
F_36 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_121 . V_287 ) ;
return - V_170 ;
}
if ( V_3 -> V_106 [ V_271 ] &
V_108 ) {
F_36 ( V_45
L_71 ,
V_3 -> V_46 , V_104 ,
V_271 ) ;
return 0 ;
}
V_281 = V_3 -> V_286 [ V_271 ] ;
if ( ! V_281 ) {
F_36 ( V_45
L_67 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_167 ;
}
if ( ( V_3 -> V_106 [ V_271 ] &
V_112 ) ) {
V_3 -> V_106 [ V_271 ] |=
V_108 ;
V_3 -> V_106 [ V_271 ] &=
~ V_112 ;
F_36 ( V_45
L_72 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return 0 ;
}
V_264 = F_25 ( V_3 , V_271 , & V_102 ) ;
if ( V_102 )
F_58 ( V_3 , V_212 ,
V_213 ) ;
return V_264 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_214 )
{
struct V_313 V_121 ;
struct V_313 T_12 * V_252 = V_214 ;
void * V_281 , * V_314 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_264 , V_77 ;
T_6 V_271 ;
unsigned long V_152 , V_315 , V_316 ;
T_1 V_8 ;
T_1 V_150 ;
T_6 V_102 = 0 ;
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
F_34 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_271 = V_121 . V_287 & 0x000000ff ;
if ( ! F_75 ( V_3 , V_271 ) ) {
F_36 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_284 ;
}
if ( V_121 . V_287 != V_3 -> V_287 [ V_271 ] ) {
F_36 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_121 . V_287 ) ;
return - V_170 ;
}
V_281 = V_3 -> V_286 [ V_271 ] ;
if ( ! V_281 ) {
F_36 ( V_45
L_68 ,
V_3 -> V_46 , V_104 , V_271 ) ;
return - V_167 ;
}
V_315 = V_3 -> V_292 [ V_271 ] ;
if ( ( V_121 . V_317 % 4 ) || ( V_121 . V_318 % 4 ) ) {
F_36 ( V_45 L_73 \
L_74 , V_3 -> V_46 ,
V_104 ) ;
return - V_170 ;
}
if ( V_121 . V_317 > V_315 )
return - V_170 ;
V_314 = ( void * ) ( V_281 + V_121 . V_317 ) ;
F_34 ( V_3 , F_6 ( V_45
L_75 ,
V_3 -> V_46 , V_104 ,
V_314 , V_121 . V_317 , V_121 . V_318 ) ) ;
if ( ( V_314 + V_121 . V_318 < V_314 ) ||
( V_314 + V_121 . V_318 > V_281 + V_315 ) )
V_316 = V_315 - V_121 . V_317 ;
else
V_316 = V_121 . V_318 ;
if ( F_35 ( ( void T_12 * ) V_252 -> V_319 ,
V_314 , V_316 ) ) {
F_36 ( V_45
L_76 ,
V_3 -> V_46 , V_104 , V_314 ) ;
return - V_164 ;
}
if ( ( V_121 . V_50 & V_320 ) == 0 )
return 0 ;
F_34 ( V_3 , F_6 ( V_45
L_77 ,
V_3 -> V_46 , V_104 , V_271 ) ) ;
if ( ( V_3 -> V_106 [ V_271 ] &
V_108 ) == 0 ) {
F_34 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_104 , V_271 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_36 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_8 = F_77 ( V_3 , V_3 -> V_171 ) ;
if ( ! V_8 ) {
F_36 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_162 ;
goto V_7;
}
V_264 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_145 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_293 = V_271 ;
V_11 -> V_296 =
F_78 ( V_3 -> V_292 [ V_271 ] ) ;
V_11 -> V_295 =
F_79 ( V_3 -> V_291 [ V_271 ] ) ;
for ( V_77 = 0 ; V_77 < V_289 ; V_77 ++ )
V_11 -> V_297 [ V_77 ] =
F_78 ( V_3 -> V_288 [ V_271 ] [ V_77 ] ) ;
V_11 -> V_143 = 0 ;
V_11 -> V_142 = 0 ;
F_45 ( & V_3 -> V_64 . V_75 ) ;
F_48 ( V_3 , V_8 ) ;
V_152 = F_52 ( & V_3 -> V_64 . V_75 ,
V_199 * V_200 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_36 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_55 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_202;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_36 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_264 = - V_164 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_150 = F_5 ( V_10 -> V_47 ) & V_203 ;
if ( V_150 == V_298 ) {
V_3 -> V_106 [ V_271 ] |=
V_107 ;
F_34 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_150 , F_7 ( V_10 -> V_48 ) ) ;
V_264 = - V_164 ;
}
V_202:
if ( V_102 )
F_58 ( V_3 , V_212 ,
V_213 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_264 ;
}
static long
F_86 ( struct V_2 * V_3 , unsigned V_321 ,
void T_12 * V_214 )
{
struct V_322 V_323 ;
struct V_322 T_12 * V_252 ;
struct V_120 V_121 ;
if ( F_87 ( V_321 ) != sizeof( struct V_322 ) )
return - V_170 ;
V_252 = (struct V_322 T_12 * ) V_214 ;
if ( F_41 ( & V_323 , ( char T_12 * ) V_214 , sizeof( V_323 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
memset ( & V_121 , 0 , sizeof( struct V_120 ) ) ;
V_121 . V_253 . V_98 = V_323 . V_253 . V_98 ;
V_121 . V_253 . V_219 = V_323 . V_253 . V_219 ;
V_121 . V_253 . V_254 = V_323 . V_253 . V_254 ;
V_121 . V_151 = V_323 . V_151 ;
V_121 . V_144 = V_323 . V_144 ;
V_121 . V_173 = V_323 . V_173 ;
V_121 . V_172 = V_323 . V_172 ;
V_121 . V_208 = V_323 . V_208 ;
V_121 . V_168 = V_323 . V_168 ;
V_121 . V_146 = F_88 ( V_323 . V_146 ) ;
V_121 . V_206 = F_88 ( V_323 . V_206 ) ;
V_121 . V_178 = F_88 ( V_323 . V_178 ) ;
V_121 . V_209 = F_88 ( V_323 . V_209 ) ;
return F_37 ( V_3 , V_121 , & V_252 -> V_147 ) ;
}
static long
F_89 ( struct V_114 * V_114 , unsigned int V_321 , void T_12 * V_214 ,
T_6 V_324 )
{
struct V_2 * V_3 ;
struct V_255 V_325 ;
enum V_326 V_327 ;
long V_160 = - V_170 ;
if ( F_41 ( & V_325 , ( char T_12 * ) V_214 ,
sizeof( struct V_255 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_164 ;
}
if ( F_22 ( V_325 . V_98 , & V_3 ) == - 1 || ! V_3 )
return - V_328 ;
if ( V_3 -> V_259 || V_3 -> V_260 ||
V_3 -> V_261 )
return - V_162 ;
V_327 = ( V_114 -> V_329 & V_330 ) ? V_331 : V_332 ;
if ( V_327 == V_331 ) {
if ( ! F_90 ( & V_3 -> V_64 . V_333 ) )
return - V_162 ;
} else if ( F_91 ( & V_3 -> V_64 . V_333 ) )
return - V_334 ;
switch ( V_321 ) {
case V_335 :
if ( F_87 ( V_321 ) == sizeof( struct V_215 ) )
V_160 = F_61 ( V_3 , V_214 ) ;
break;
#ifdef F_92
case V_336 :
#endif
case V_337 :
{
struct V_120 T_12 * V_252 ;
struct V_120 V_121 ;
#ifdef F_92
if ( V_324 ) {
V_160 = F_86 ( V_3 , V_321 , V_214 ) ;
break;
}
#endif
if ( F_41 ( & V_121 , V_214 , sizeof( V_121 ) ) ) {
F_36 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
V_160 = - V_164 ;
break;
}
if ( F_87 ( V_321 ) == sizeof( struct V_120 ) ) {
V_252 = V_214 ;
V_160 = F_37 ( V_3 , V_121 , & V_252 -> V_147 ) ;
}
break;
}
case V_338 :
if ( F_87 ( V_321 ) == sizeof( struct V_243 ) )
V_160 = F_65 ( V_3 , V_214 ) ;
break;
case V_339 :
if ( F_87 ( V_321 ) == sizeof( struct V_247 ) )
V_160 = F_66 ( V_3 , V_214 ) ;
break;
case V_340 :
V_160 = F_69 ( V_3 , V_214 ) ;
break;
case V_341 :
if ( F_87 ( V_321 ) == sizeof( struct V_257 ) )
V_160 = F_70 ( V_3 , V_214 ) ;
break;
case V_342 :
if ( F_87 ( V_321 ) == sizeof( struct V_262 ) )
V_160 = F_74 ( V_3 , V_214 ) ;
break;
case V_343 :
if ( F_87 ( V_321 ) == sizeof( struct V_279 ) )
V_160 = F_81 ( V_3 , V_214 ) ;
break;
case V_344 :
if ( F_87 ( V_321 ) == sizeof( struct V_304 ) )
V_160 = F_82 ( V_3 , V_214 ) ;
break;
case V_345 :
if ( F_87 ( V_321 ) == sizeof( struct V_305 ) )
V_160 = F_83 ( V_3 , V_214 ) ;
break;
case V_346 :
if ( F_87 ( V_321 ) == sizeof( struct V_312 ) )
V_160 = F_84 ( V_3 , V_214 ) ;
break;
case V_347 :
if ( F_87 ( V_321 ) == sizeof( struct V_313 ) )
V_160 = F_85 ( V_3 , V_214 ) ;
break;
default:
F_34 ( V_3 , F_6 ( V_45
L_79 , V_3 -> V_46 , V_321 ) ) ;
break;
}
F_93 ( & V_3 -> V_64 . V_333 ) ;
return V_160 ;
}
static long
F_94 ( struct V_114 * V_114 , unsigned int V_321 , unsigned long V_214 )
{
long V_160 ;
V_160 = F_89 ( V_114 , V_321 , ( void T_12 * ) V_214 , 0 ) ;
return V_160 ;
}
static long
F_95 ( struct V_114 * V_114 , unsigned V_321 , unsigned long V_214 )
{
long V_160 ;
V_160 = F_89 ( V_114 , V_321 , ( void T_12 * ) V_214 , 1 ) ;
return V_160 ;
}
static T_23
F_96 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_80 ,
( V_3 -> V_175 . V_235 . V_236 & 0xFF000000 ) >> 24 ,
( V_3 -> V_175 . V_235 . V_236 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_175 . V_235 . V_236 & 0x0000FF00 ) >> 8 ,
V_3 -> V_175 . V_235 . V_236 & 0x000000FF ) ;
}
static T_23
F_99 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
T_7 V_355 = F_7 ( V_3 -> V_241 . V_242 ) ;
return snprintf ( V_351 , V_354 , L_80 ,
( V_355 & 0xFF000000 ) >> 24 ,
( V_355 & 0x00FF0000 ) >> 16 ,
( V_355 & 0x0000FF00 ) >> 8 ,
V_355 & 0x000000FF ) ;
}
static T_23
F_100 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_81 ,
V_3 -> V_175 . V_356 , V_3 -> V_175 . V_357 >> 8 ) ;
}
static T_23
F_101 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , 16 , L_51 , V_3 -> V_358 . V_359 ) ;
}
static T_23
F_102 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_82 ,
F_7 ( V_3 -> V_360 . V_361 . V_236 ) ) ;
}
static T_23
F_103 ( struct V_138 * V_348 , struct V_349
* V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_82 ,
F_7 ( V_3 -> V_360 . V_362 . V_236 ) ) ;
}
static T_23
F_104 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , 16 , L_51 , V_3 -> V_358 . V_363 ) ;
}
static T_23
F_105 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , 16 , L_51 , V_3 -> V_358 . V_364 ) ;
}
static T_23
F_106 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , 16 , L_51 , V_3 -> V_358 . V_365 ) ;
}
static T_23
F_107 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_83 , V_3 -> V_366 ) ;
}
static T_23
F_108 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_83 , V_3 -> V_367 ) ;
}
static T_23
F_109 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_83 , V_3 -> V_175 . V_368 ) ;
}
static T_23
F_110 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_84 ,
( unsigned long long ) V_3 -> V_369 . V_53 ) ;
}
static T_23
F_111 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_82 , V_3 -> V_13 ) ;
}
static T_23
F_112 ( struct V_138 * V_348 , struct V_349 * V_350 ,
const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
int V_371 = 0 ;
if ( sscanf ( V_351 , L_85 , & V_371 ) != 1 )
return - V_170 ;
V_3 -> V_13 = V_371 ;
F_6 ( V_45 L_86 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_351 ) ;
}
static T_23
F_113 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_87 , V_3 -> V_372 ) ;
}
static T_23
F_114 ( struct V_138 * V_348 , struct V_349 * V_350 ,
const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
int V_371 = 0 ;
if ( sscanf ( V_351 , L_88 , & V_371 ) != 1 )
return - V_170 ;
V_3 -> V_372 = V_371 ;
F_6 ( V_45 L_89 , V_3 -> V_46 ,
V_3 -> V_372 ) ;
return strlen ( V_351 ) ;
}
static T_23
F_115 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
return snprintf ( V_351 , V_354 , L_87 , V_3 -> V_373 ) ;
}
static T_23
F_116 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
T_6 V_374 ;
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
if ( ( V_3 -> V_175 . V_273 &
V_375 ) && V_3 -> V_376 )
V_374 = V_3 -> V_374 ;
else
V_374 = 1 ;
return snprintf ( V_351 , V_354 , L_87 , V_374 ) ;
}
static T_23
F_117 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
T_7 V_377 = 0 ;
struct V_378 * V_281 ;
if ( ! V_3 -> V_286 [ V_272 ] ) {
F_36 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) {
F_36 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
V_281 = (struct V_378 * )
V_3 -> V_286 [ V_272 ] ;
if ( ( F_7 ( V_281 -> V_379 ) == 0x00000000 ||
F_7 ( V_281 -> V_379 ) == 0x01000000 ||
F_7 ( V_281 -> V_379 ) == 0x01010000 ) &&
F_7 ( V_281 -> V_380 ) == 0x4742444c )
V_377 = F_7 ( V_281 -> V_381 ) ;
V_3 -> V_382 = V_377 ;
return snprintf ( V_351 , V_354 , L_87 , V_377 ) ;
}
static T_23
F_118 ( struct V_138 * V_348 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
void * V_281 ;
T_7 V_377 ;
if ( ! V_3 -> V_286 [ V_272 ] ) {
F_36 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) {
F_36 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( V_3 -> V_383 > V_3 -> V_382 )
return 0 ;
V_377 = V_3 -> V_382 - V_3 -> V_383 ;
V_377 = ( V_377 >= V_354 ) ? ( V_354 - 1 ) : V_377 ;
V_281 = V_3 -> V_286 [ 0 ] + V_3 -> V_383 ;
memcpy ( V_351 , V_281 , V_377 ) ;
return V_377 ;
}
static T_23
F_119 ( struct V_138 * V_348 , struct V_349 * V_350 ,
const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
int V_371 = 0 ;
if ( sscanf ( V_351 , L_88 , & V_371 ) != 1 )
return - V_170 ;
V_3 -> V_383 = V_371 ;
return strlen ( V_351 ) ;
}
static T_23
F_120 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
if ( ( ! V_3 -> V_286 [ V_272 ] ) ||
( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) )
return snprintf ( V_351 , V_354 , L_91 ) ;
else if ( ( V_3 -> V_106 [ V_272 ] &
V_108 ) )
return snprintf ( V_351 , V_354 , L_92 ) ;
else
return snprintf ( V_351 , V_354 , L_93 ) ;
}
static T_23
F_121 ( struct V_138 * V_348 ,
struct V_349 * V_350 , const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
char V_384 [ 10 ] = L_94 ;
struct V_279 V_280 ;
T_6 V_102 = 0 ;
if ( V_3 -> V_259 || V_3 -> V_385 ||
V_3 -> V_260 || V_3 -> V_261 )
return - V_386 ;
if ( sscanf ( V_351 , L_95 , V_384 ) != 1 )
return - V_170 ;
if ( ! strcmp ( V_384 , L_96 ) ) {
if ( ( V_3 -> V_286 [ V_272 ] ) &&
( V_3 -> V_106 [ V_272 ] &
V_107 ) &&
( ( V_3 -> V_106 [ V_272 ] &
V_108 ) == 0 ) )
goto V_7;
memset ( & V_280 , 0 , sizeof( struct V_279 ) ) ;
F_6 ( V_45 L_97 ,
V_3 -> V_46 ) ;
V_280 . V_271 = V_272 ;
V_280 . V_285 = ( 1024 * 1024 ) ;
V_280 . V_287 = 0x7075900 ;
V_3 -> V_106 [ V_272 ] = 0 ;
F_76 ( V_3 , & V_280 ) ;
} else if ( ! strcmp ( V_384 , L_98 ) ) {
if ( ! V_3 -> V_286 [ V_272 ] )
goto V_7;
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 )
goto V_7;
if ( ( V_3 -> V_106 [ V_272 ] &
V_108 ) )
goto V_7;
F_6 ( V_45 L_99 ,
V_3 -> V_46 ) ;
F_25 ( V_3 , V_272 ,
& V_102 ) ;
}
V_7:
return strlen ( V_351 ) ;
}
static T_23
F_122 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_264 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_264 = sizeof( struct V_388 ) ;
memcpy ( V_351 , & V_3 -> V_300 , V_264 ) ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_264 ;
}
static T_23
F_123 ( struct V_138 * V_348 ,
struct V_349 * V_350 , const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_264 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_264 = F_124 ( sizeof( struct V_388 ) , V_370 ) ;
memset ( & V_3 -> V_300 , 0 ,
sizeof( struct V_388 ) ) ;
memcpy ( & V_3 -> V_300 , V_351 , V_264 ) ;
V_3 -> V_300 . V_301 |=
( V_302 + V_303 ) ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_264 ;
}
static T_23
F_125 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_264 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_264 = sizeof( struct V_389 ) ;
memcpy ( V_351 , & V_3 -> V_390 , V_264 ) ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_264 ;
}
static T_23
F_126 ( struct V_138 * V_348 ,
struct V_349 * V_350 , const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_63 = F_124 ( sizeof( struct V_389 ) , V_370 ) ;
memset ( & V_3 -> V_390 , 0 ,
sizeof( struct V_389 ) ) ;
memcpy ( & V_3 -> V_390 , V_351 , V_63 ) ;
if ( V_3 -> V_390 . V_391 > V_392 )
V_3 -> V_390 . V_391 = V_392 ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_63 ;
}
static T_23
F_127 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_264 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_264 = sizeof( struct V_393 ) ;
memcpy ( V_351 , & V_3 -> V_394 , V_264 ) ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_264 ;
}
static T_23
F_128 ( struct V_138 * V_348 ,
struct V_349 * V_350 , const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_63 = F_124 ( sizeof( struct V_393 ) , V_370 ) ;
memset ( & V_3 -> V_394 , 0 ,
sizeof( struct V_389 ) ) ;
memcpy ( & V_3 -> V_394 , V_351 , V_63 ) ;
if ( V_3 -> V_394 . V_391 > V_392 )
V_3 -> V_394 . V_391 = V_392 ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_63 ;
}
static T_23
F_129 ( struct V_138 * V_348 ,
struct V_349 * V_350 , char * V_351 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_264 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_264 = sizeof( struct V_395 ) ;
memcpy ( V_351 , & V_3 -> V_396 , V_264 ) ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_264 ;
}
static T_23
F_130 ( struct V_138 * V_348 ,
struct V_349 * V_350 , const char * V_351 , T_15 V_370 )
{
struct V_352 * V_353 = F_97 ( V_348 ) ;
struct V_2 * V_3 = F_98 ( V_353 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_387 , V_50 ) ;
V_63 = F_124 ( sizeof( struct V_395 ) , V_370 ) ;
memset ( & V_3 -> V_396 , 0 ,
sizeof( V_3 -> V_396 ) ) ;
memcpy ( & V_3 -> V_396 , V_351 , V_63 ) ;
if ( V_3 -> V_396 . V_391 > V_392 )
V_3 -> V_396 . V_391 = V_392 ;
F_10 ( & V_3 -> V_387 , V_50 ) ;
return V_63 ;
}
static T_23
F_131 ( struct V_138 * V_397 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_398 * V_399 = F_132 ( V_397 ) ;
struct V_126 * V_400 = V_399 -> V_139 ;
return snprintf ( V_351 , V_354 , L_84 ,
( unsigned long long ) V_400 -> V_140 -> V_53 ) ;
}
static T_23
F_133 ( struct V_138 * V_397 , struct V_349 * V_350 ,
char * V_351 )
{
struct V_398 * V_399 = F_132 ( V_397 ) ;
struct V_126 * V_400 = V_399 -> V_139 ;
return snprintf ( V_351 , V_354 , L_100 ,
V_400 -> V_140 -> V_4 ) ;
}
void
F_134 ( void )
{
V_95 = NULL ;
if ( F_135 ( & V_401 ) < 0 )
F_36 ( L_101 ,
V_238 , V_402 ) ;
F_136 ( & V_94 ) ;
}
void
F_137 ( void )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_105 ; V_77 ++ ) {
if ( ! V_3 -> V_286 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_106 [ V_77 ] &
V_107 ) )
continue;
if ( ( V_3 -> V_106 [ V_77 ] &
V_108 ) )
continue;
F_59 ( V_3 -> V_177 , V_3 -> V_292 [ V_77 ] ,
V_3 -> V_286 [ V_77 ] , V_3 -> V_291 [ V_77 ] ) ;
V_3 -> V_286 [ V_77 ] = NULL ;
V_3 -> V_106 [ V_77 ] = 0 ;
}
F_60 ( V_3 -> V_79 ) ;
}
F_138 ( & V_401 ) ;
}
