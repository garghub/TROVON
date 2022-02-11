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
static int
F_29 ( struct V_117 * V_117 , struct V_114 * V_115 )
{
return F_28 ( - 1 , V_115 , 0 , & V_95 ) ;
}
static unsigned int
F_30 ( struct V_114 * V_115 , T_9 * V_118 )
{
struct V_2 * V_3 ;
F_31 ( V_115 , & V_94 , V_118 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_93 )
return V_119 | V_120 ;
}
return 0 ;
}
static int
F_32 ( struct V_2 * V_3 , struct V_121 * V_122 ,
T_10 * V_123 )
{
T_6 V_124 = 0 ;
T_1 V_77 ;
T_1 V_4 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
unsigned long V_50 ;
T_11 * V_129 ;
T_7 V_63 ;
T_7 V_130 ;
char * V_12 = NULL ;
if ( V_123 -> V_131 == V_132 )
V_12 = L_28 ;
else if ( V_123 -> V_131 == V_133 )
V_12 = L_29 ;
else
return 0 ;
V_130 = F_33 ( (struct V_134 * ) V_123 -> V_135 ) ;
V_4 = F_5 ( V_123 -> V_52 ) ;
F_8 ( & V_3 -> V_136 , V_50 ) ;
for ( V_77 = V_3 -> V_137 ; V_77 && ! V_124 ; V_77 -- ) {
V_126 = V_3 -> V_138 [ V_77 - 1 ] . V_126 ;
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
V_123 -> V_142 = F_34 ( V_3 -> V_138 [ V_77 - 1 ] . V_8 ) ;
V_124 = 1 ;
}
F_10 ( & V_3 -> V_136 , V_50 ) ;
if ( ! V_124 ) {
F_35 ( V_3 , F_6 ( V_45
L_30 ,
V_3 -> V_46 ,
V_12 , F_5 ( V_123 -> V_52 ) , V_130 ) ) ;
V_129 = V_3 -> V_64 . V_60 ;
V_129 -> V_52 = V_123 -> V_52 ;
V_129 -> V_15 = V_23 ;
V_129 -> V_131 = V_123 -> V_131 ;
V_129 -> V_68 = sizeof( T_11 ) / 4 ;
V_129 -> V_143 = V_123 -> V_143 ;
V_129 -> V_144 = V_123 -> V_144 ;
V_63 = F_13 ( T_7 , V_122 -> V_145 , V_3 -> V_146 ) ;
if ( F_36 ( V_122 -> V_147 , V_3 -> V_64 . V_60 ,
V_63 ) )
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
return 1 ;
}
F_35 ( V_3 , F_6 ( V_45
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_123 -> V_52 ) , V_130 ,
F_5 ( V_123 -> V_142 ) ) ) ;
return 0 ;
}
static long
F_38 ( struct V_2 * V_3 , struct V_121 V_122 ,
void T_12 * V_148 )
{
T_13 * V_11 = NULL , * V_149 ;
T_2 * V_10 ;
T_7 V_150 ;
T_1 V_151 ;
T_1 V_8 ;
unsigned long V_152 , V_153 ;
T_6 V_102 ;
T_7 V_63 ;
void * V_154 ;
void * V_155 = NULL ;
T_14 V_156 = 0 ;
T_15 V_157 = 0 ;
void * V_158 = NULL ;
T_14 V_159 = 0 ;
T_15 V_160 = 0 ;
long V_161 ;
T_1 V_162 ;
V_102 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_161 = - V_163 ;
goto V_7;
}
V_162 = 0 ;
V_150 = F_39 ( V_3 , 1 ) ;
while ( V_150 != V_164 ) {
if ( V_162 ++ == 10 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_104 ) ;
V_161 = - V_165 ;
goto V_7;
}
F_40 ( 1 ) ;
V_150 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45
L_35 ,
V_3 -> V_46 ,
V_104 , V_162 ) ;
}
if ( V_162 )
F_6 ( V_45 L_36 ,
V_3 -> V_46 , V_104 ) ;
V_11 = F_41 ( V_3 -> V_166 , V_167 ) ;
if ( ! V_11 ) {
F_37 ( V_45
L_37 ,
V_3 -> V_46 , V_104 ) ;
V_161 = - V_168 ;
goto V_7;
}
if ( V_122 . V_169 * 4 > V_3 -> V_166 ||
V_122 . V_169 > ( V_170 / 4 ) ) {
V_161 = - V_171 ;
goto V_7;
}
if ( F_42 ( V_11 , V_148 , V_122 . V_169 * 4 ) ) {
F_37 ( L_31 , __FILE__ , __LINE__ ,
V_104 ) ;
V_161 = - V_165 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_172 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_161 = - V_163 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_172 , NULL ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_161 = - V_163 ;
goto V_7;
}
}
V_161 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_146 ) ;
V_149 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_149 , V_11 , V_122 . V_169 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_157 = V_122 . V_173 ;
V_160 = V_122 . V_174 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_175 ) ||
F_5 ( V_11 -> V_175 ) >
V_3 -> V_176 . V_177 ) {
V_161 = - V_171 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_157 ) {
V_155 = F_45 ( V_3 -> V_178 , V_157 ,
& V_156 ) ;
if ( ! V_155 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_168 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_155 , V_122 . V_179 ,
V_157 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_165 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_160 ) {
V_158 = F_45 ( V_3 -> V_178 , V_160 ,
& V_159 ) ;
if ( ! V_158 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_168 ;
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_154 = ( void * ) V_149 + ( V_122 . V_169 * 4 ) ;
#ifdef F_15
F_3 ( V_3 , V_8 , L_39 , NULL ) ;
#endif
F_46 ( & V_3 -> V_64 . V_75 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_180 =
( T_4 * ) V_149 ;
V_180 -> V_181 = V_71 ;
V_180 -> V_182 =
F_47 ( V_3 , V_8 ) ;
memset ( V_3 -> V_64 . V_73 , 0 , V_71 ) ;
V_3 -> V_183 ( V_3 , V_154 , V_156 , V_157 ,
V_159 , V_160 ) ;
if ( V_11 -> V_15 == V_16 )
F_48 ( V_3 , V_8 ,
F_5 ( V_11 -> V_175 ) ) ;
else
F_49 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_123 =
( T_10 * ) V_149 ;
F_24 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 ,
F_5 ( V_123 -> V_52 ) , V_123 -> V_131 ) ) ;
if ( V_123 -> V_131 ==
V_132 ||
V_123 -> V_131 ==
V_133 ) {
if ( F_32 ( V_3 , & V_122 , V_123 ) ) {
F_26 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_50 ( V_3 , F_5 (
V_123 -> V_52 ) ) ;
V_3 -> V_184 ( V_3 , V_154 , V_156 , V_157 ,
V_159 , V_160 ) ;
F_51 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_185 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_185 -> V_186 = 0xFF ;
if ( V_185 -> V_187 &
V_188 )
V_90 = ( T_6 * ) & V_185 -> V_189 ;
else {
if ( F_52 ( V_155 == NULL ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
F_26 ( V_3 , V_8 ) ;
V_161 = - V_171 ;
goto V_7;
}
V_90 = V_155 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_190 = 1 ;
V_3 -> V_191 = 1 ;
}
V_3 -> V_183 ( V_3 , V_154 , V_156 , V_157 , V_159 ,
V_160 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_41 :
case V_36 :
case V_37 :
{
V_3 -> V_183 ( V_3 , V_154 , V_156 , V_157 , V_159 ,
V_160 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_192 :
{
T_17 * V_193 =
( T_17 * ) V_11 ;
if ( V_193 -> V_194 == V_195 ) {
V_3 -> V_183 ( V_3 , V_154 , V_156 , V_157 ,
V_159 , V_160 ) ;
} else {
V_3 -> V_184 ( V_3 , V_154 , V_156 , V_157 ,
V_159 , V_160 ) ;
}
F_49 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_196 =
( T_18 * ) V_11 ;
if ( V_196 -> V_197 == V_198
|| V_196 -> V_197 ==
V_199 ) {
V_3 -> V_190 = 1 ;
V_3 -> V_191 = 1 ;
}
}
default:
V_3 -> V_184 ( V_3 , V_154 , V_156 , V_157 ,
V_159 , V_160 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
if ( V_122 . V_152 < V_200 )
V_152 = V_200 ;
else
V_152 = V_122 . V_152 ;
V_153 = F_53 ( & V_3 -> V_64 . V_75 ,
V_152 * V_201 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_123 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_123 -> V_52 ) ) ;
F_55 ( V_3 , V_202 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_190 ) {
V_3 -> V_190 = 0 ;
V_3 -> V_191 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_56 ( V_11 , V_122 . V_169 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_203;
}
V_10 = V_3 -> V_64 . V_60 ;
V_151 = F_5 ( V_10 -> V_47 ) & V_204 ;
#ifdef F_15
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_205 ) ) {
T_11 * V_129 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_42 \
L_43
L_44 , V_3 -> V_46 ,
F_5 ( V_129 -> V_47 ) ,
F_7 ( V_129 -> V_48 ) ,
F_7 ( V_129 -> V_206 ) ) ;
}
#endif
if ( V_160 ) {
if ( F_36 ( V_122 . V_207 , V_158 ,
V_160 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_208 ;
goto V_7;
}
}
if ( V_122 . V_145 ) {
V_63 = F_13 ( T_7 , V_122 . V_145 , V_3 -> V_146 ) ;
if ( F_36 ( V_122 . V_147 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_208 ;
goto V_7;
}
}
if ( V_122 . V_209 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_122 . V_209 , V_71 ) ;
if ( F_36 ( V_122 . V_210 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_104 ) ;
V_161 = - V_208 ;
goto V_7;
}
}
V_203:
if ( V_102 ) {
V_161 = - V_208 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_45 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_175 ) ) ;
F_57 ( V_3 ) ;
F_58 ( V_3 ,
F_5 ( V_11 -> V_175 ) , 0 , 0 ,
0 , V_211 , 0 , 30 ,
0 , V_212 ) ;
} else
F_59 ( V_3 , V_213 ,
V_214 ) ;
}
V_7:
if ( V_158 )
F_60 ( V_3 -> V_178 , V_160 , V_158 ,
V_159 ) ;
if ( V_155 )
F_60 ( V_3 -> V_178 , V_157 , V_155 ,
V_156 ) ;
F_61 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_161 ;
}
static long
F_62 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_216 V_122 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_217 = V_218 ;
if ( V_3 -> V_219 )
V_122 . V_220 = V_3 -> V_219 [ 0 ] . V_221 ;
V_122 . V_222 = V_3 -> V_178 -> V_223 ;
V_122 . V_224 = V_3 -> V_178 -> V_139 ;
V_122 . V_225 = V_3 -> V_178 -> V_225 ;
V_122 . V_226 = V_3 -> V_178 -> V_226 ;
V_122 . V_227 . V_228 . V_229 . V_230 = V_3 -> V_178 -> V_230 -> V_231 ;
V_122 . V_227 . V_228 . V_229 . V_139 = F_63 ( V_3 -> V_178 -> V_232 ) ;
V_122 . V_227 . V_228 . V_229 . V_233 = F_64 ( V_3 -> V_178 -> V_232 ) ;
V_122 . V_227 . V_234 = F_65 ( V_3 -> V_178 -> V_230 ) ;
V_122 . V_235 = V_3 -> V_176 . V_236 . V_237 ;
strcpy ( V_122 . V_238 , V_239 ) ;
strcat ( V_122 . V_238 , L_47 ) ;
strcat ( V_122 . V_238 , V_240 ) ;
V_122 . V_241 = F_7 ( V_3 -> V_242 . V_243 ) ;
if ( F_36 ( V_215 , & V_122 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_244 V_122 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_122 . V_245 = V_86 ;
memcpy ( V_122 . V_246 , V_3 -> V_80 ,
V_247 * sizeof( T_7 ) ) ;
if ( F_36 ( V_215 , & V_122 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
return 0 ;
}
static long
F_67 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_248 V_122 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
memcpy ( V_3 -> V_80 , V_122 . V_246 ,
V_247 * sizeof( T_7 ) ) ;
F_68 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_69 ( V_86 ,
sizeof( struct V_81 ) , V_167 ) ;
if ( ! V_3 -> V_79 ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_168 ;
}
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_249 V_122 ;
T_7 V_250 , V_251 , V_252 ;
struct V_249 T_12 * V_253 = V_215 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_250 = V_122 . V_254 . V_255 -
sizeof( struct V_256 ) ;
V_251 = V_250 / sizeof( struct V_81 ) ;
V_252 = F_13 ( T_7 , V_86 , V_251 ) ;
if ( ! V_252 || ! V_3 -> V_79 )
return - V_208 ;
V_250 = V_252 * sizeof( struct V_81 ) ;
if ( F_36 ( V_253 -> V_257 , V_3 -> V_79 , V_250 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_71 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_258 V_122 ;
int V_259 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
if ( V_3 -> V_260 || V_3 -> V_261 ||
V_3 -> V_262 )
return - V_163 ;
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_104 ) ) ;
V_259 = F_59 ( V_3 , V_213 ,
V_214 ) ;
F_6 ( V_45 L_48 ,
V_3 -> V_46 , ( ( ! V_259 ) ? L_49 : L_50 ) ) ;
return 0 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_263 * V_264 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_265 = 0 ;
if ( F_73 ( & V_3 -> V_266 ) )
return V_265 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_264 -> V_230 == 0xFFFFFFFF && V_264 -> V_100 == 0xFFFFFFFF &&
V_264 -> V_4 == V_5 -> V_4 ) {
V_264 -> V_230 = V_5 -> V_267 ;
V_264 -> V_100 = V_5 -> V_100 ;
V_265 = 1 ;
goto V_7;
} else if ( V_264 -> V_230 == V_5 -> V_267 && V_264 -> V_100 ==
V_5 -> V_100 && V_264 -> V_4 == 0xFFFF ) {
V_264 -> V_4 = V_5 -> V_4 ;
V_265 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_265 ;
}
static int
F_74 ( struct V_2 * V_3 ,
struct V_263 * V_264 )
{
struct V_268 * V_269 ;
unsigned long V_50 ;
int V_265 = 0 ;
if ( F_73 ( & V_3 -> V_270 ) )
return V_265 ;
F_8 ( & V_3 -> V_271 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_264 -> V_230 == 0xFFFFFFFF && V_264 -> V_100 == 0xFFFFFFFF &&
V_264 -> V_4 == V_269 -> V_4 ) {
V_264 -> V_230 = V_269 -> V_267 ;
V_264 -> V_100 = V_269 -> V_100 ;
V_265 = 1 ;
goto V_7;
} else if ( V_264 -> V_230 == V_269 -> V_267 && V_264 -> V_100 ==
V_269 -> V_100 && V_264 -> V_4 == 0xFFFF ) {
V_264 -> V_4 = V_269 -> V_4 ;
V_265 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_271 , V_50 ) ;
return V_265 ;
}
static long
F_75 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_263 V_122 ;
int V_265 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_265 = F_72 ( V_3 , & V_122 ) ;
if ( ! V_265 )
F_74 ( V_3 , & V_122 ) ;
if ( F_36 ( V_215 , & V_122 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
return 0 ;
}
static T_6
F_76 ( struct V_2 * V_3 , T_6 V_272 )
{
T_6 V_265 = 0 ;
switch ( V_272 ) {
case V_273 :
if ( V_3 -> V_176 . V_274 &
V_275 )
V_265 = 1 ;
break;
case V_276 :
if ( V_3 -> V_176 . V_274 &
V_277 )
V_265 = 1 ;
break;
case V_278 :
if ( V_3 -> V_176 . V_274 &
V_279 )
V_265 = 1 ;
}
return V_265 ;
}
static long
F_77 ( struct V_2 * V_3 ,
struct V_280 * V_281 )
{
int V_265 , V_77 ;
void * V_282 = NULL ;
T_14 V_283 ;
T_7 V_284 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_272 ;
unsigned long V_153 ;
T_1 V_8 ;
T_1 V_151 ;
T_7 V_150 ;
T_6 V_102 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_150 = F_39 ( V_3 , 1 ) ;
if ( V_150 != V_164 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_272 = V_281 -> V_272 ;
if ( ! F_76 ( V_3 , V_272 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_285 ;
}
if ( V_3 -> V_106 [ V_272 ] &
V_107 ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_104 ,
V_272 ) ;
return - V_171 ;
}
if ( V_281 -> V_286 % 4 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_104 ) ;
return - V_171 ;
}
V_8 = F_78 ( V_3 , V_3 -> V_172 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_265 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_282 = V_3 -> V_287 [ V_272 ] ;
V_284 = V_281 -> V_286 ;
V_3 -> V_288 [ V_272 ] = V_281 -> V_288 ;
V_3 -> V_106 [ V_272 ] = 0 ;
memcpy ( V_3 -> V_289 [ V_272 ] ,
V_281 -> V_289 , V_290 ) ;
V_3 -> V_291 [ V_272 ] = V_281 -> V_291 ;
if ( V_282 ) {
V_283 = V_3 -> V_292 [ V_272 ] ;
if ( V_284 != V_3 -> V_293 [ V_272 ] ) {
F_60 ( V_3 -> V_178 ,
V_3 -> V_293 [ V_272 ] ,
V_282 , V_283 ) ;
V_282 = NULL ;
}
}
if ( V_282 == NULL ) {
V_3 -> V_293 [ V_272 ] = 0 ;
V_3 -> V_292 [ V_272 ] = 0 ;
V_282 = F_45 (
V_3 -> V_178 , V_284 , & V_283 ) ;
if ( V_282 == NULL ) {
F_37 ( V_45 L_55 \
L_56 ,
V_3 -> V_46 , V_104 , V_284 ) ;
F_26 ( V_3 , V_8 ) ;
return - V_168 ;
}
V_3 -> V_287 [ V_272 ] = V_282 ;
V_3 -> V_293 [ V_272 ] = V_284 ;
V_3 -> V_292 [ V_272 ] = V_283 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_294 = V_281 -> V_272 ;
V_11 -> V_295 = F_79 ( V_281 -> V_291 ) ;
V_11 -> V_296 = F_80 ( V_283 ) ;
V_11 -> V_297 = F_79 ( V_284 ) ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_57 ,
V_3 -> V_46 , V_104 , V_282 ,
( unsigned long long ) V_283 ,
F_7 ( V_11 -> V_297 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_290 ; V_77 ++ )
V_11 -> V_298 [ V_77 ] =
F_79 ( V_3 -> V_289 [ V_272 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_153 = F_53 ( & V_3 -> V_64 . V_75 ,
V_200 * V_201 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_203;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_165 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_151 = F_5 ( V_10 -> V_47 ) & V_204 ;
if ( V_151 == V_299 ) {
V_3 -> V_106 [ V_272 ] |=
V_107 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_151 , F_7 ( V_10 -> V_48 ) ) ;
V_265 = - V_165 ;
}
V_203:
if ( V_102 )
F_59 ( V_3 , V_213 ,
V_214 ) ;
V_7:
if ( V_265 && V_282 )
F_60 ( V_3 -> V_178 , V_284 ,
V_282 , V_283 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_265 ;
}
void
F_81 ( struct V_2 * V_3 , T_6 V_300 )
{
struct V_280 V_281 ;
memset ( & V_281 , 0 , sizeof( struct V_280 ) ) ;
if ( V_300 & 1 ) {
F_6 ( V_45 L_61 ,
V_3 -> V_46 ) ;
V_3 -> V_301 . V_302 =
( V_303 + V_304 ) ;
V_281 . V_272 = V_273 ;
V_281 . V_286 = 2 * ( 1024 * 1024 ) ;
V_281 . V_288 = 0x7075900 ;
F_77 ( V_3 , & V_281 ) ;
}
if ( V_300 & 2 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_281 . V_272 = V_276 ;
V_281 . V_286 = 2 * ( 1024 * 1024 ) ;
V_281 . V_288 = 0x7075901 ;
F_77 ( V_3 , & V_281 ) ;
}
if ( V_300 & 4 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_281 . V_272 = V_278 ;
V_281 . V_286 = 2 * ( 1024 * 1024 ) ;
V_281 . V_288 = 0x7075901 ;
F_77 ( V_3 , & V_281 ) ;
}
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_280 V_122 ;
long V_265 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
V_265 = F_77 ( V_3 , & V_122 ) ;
return V_265 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_305 V_122 ;
void * V_282 ;
T_14 V_283 ;
T_7 V_284 ;
T_6 V_272 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_272 = V_122 . V_288 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_272 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_285 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_171 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_108 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_171 ;
}
if ( V_122 . V_288 != V_3 -> V_288 [ V_272 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_122 . V_288 ) ;
return - V_171 ;
}
V_282 = V_3 -> V_287 [ V_272 ] ;
if ( ! V_282 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_168 ;
}
V_284 = V_3 -> V_293 [ V_272 ] ;
V_283 = V_3 -> V_292 [ V_272 ] ;
F_60 ( V_3 -> V_178 , V_284 ,
V_282 , V_283 ) ;
V_3 -> V_287 [ V_272 ] = NULL ;
V_3 -> V_106 [ V_272 ] = 0 ;
return 0 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_306 V_122 ;
void * V_282 ;
int V_77 ;
T_6 V_272 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_122 . V_307 = 0 ;
V_272 = V_122 . V_272 ;
if ( ! F_76 ( V_3 , V_272 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_285 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_171 ;
}
if ( V_122 . V_288 & 0xffffff00 ) {
if ( V_122 . V_288 != V_3 -> V_288 [ V_272 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_122 . V_288 ) ;
return - V_171 ;
}
}
V_282 = V_3 -> V_287 [ V_272 ] ;
if ( ! V_282 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_168 ;
}
if ( V_3 -> V_106 [ V_272 ] & V_108 )
V_122 . V_307 = ( V_308 |
V_309 ) ;
else
V_122 . V_307 = ( V_308 |
V_309 |
V_310 ) ;
for ( V_77 = 0 ; V_77 < V_290 ; V_77 ++ )
V_122 . V_289 [ V_77 ] =
V_3 -> V_289 [ V_272 ] [ V_77 ] ;
V_122 . V_311 = V_3 -> V_293 [ V_272 ] ;
V_122 . V_312 = 0 ;
V_122 . V_288 = V_3 -> V_288 [ V_272 ] ;
V_122 . V_291 = V_3 -> V_291 [ V_272 ] ;
if ( F_36 ( V_215 , & V_122 , sizeof( struct V_306 ) ) ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_104 , V_215 ) ;
return - V_165 ;
}
return 0 ;
}
int
F_25 ( struct V_2 * V_3 , T_6 V_272 ,
T_6 * V_102 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_151 ;
T_7 V_150 ;
int V_265 ;
unsigned long V_153 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_265 = 0 ;
* V_102 = 0 ;
V_150 = F_39 ( V_3 , 1 ) ;
if ( V_150 != V_164 ) {
if ( V_3 -> V_106 [ V_272 ] &
V_107 )
V_3 -> V_106 [ V_272 ] |=
V_108 ;
F_35 ( V_3 , F_6 ( V_45
L_70 , V_3 -> V_46 ,
V_104 ) ) ;
V_265 = - V_163 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_172 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_294 = V_272 ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_153 = F_53 ( & V_3 -> V_64 . V_75 ,
V_200 * V_201 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_56 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
* V_102 = 1 ;
V_265 = - V_165 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_165 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_151 = F_5 ( V_10 -> V_47 ) & V_204 ;
if ( V_151 == V_299 ) {
V_3 -> V_106 [ V_272 ] |=
V_108 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_151 , F_7 ( V_10 -> V_48 ) ) ;
V_265 = - V_165 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_265 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_313 V_122 ;
void * V_282 ;
int V_265 ;
T_6 V_272 ;
T_6 V_102 = 0 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_272 = V_122 . V_288 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_272 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_285 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_107 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_171 ;
}
if ( V_122 . V_288 != V_3 -> V_288 [ V_272 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_122 . V_288 ) ;
return - V_171 ;
}
if ( V_3 -> V_106 [ V_272 ] &
V_108 ) {
F_37 ( V_45
L_71 ,
V_3 -> V_46 , V_104 ,
V_272 ) ;
return 0 ;
}
V_282 = V_3 -> V_287 [ V_272 ] ;
if ( ! V_282 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_168 ;
}
if ( ( V_3 -> V_106 [ V_272 ] &
V_112 ) ) {
V_3 -> V_106 [ V_272 ] |=
V_108 ;
V_3 -> V_106 [ V_272 ] &=
~ V_112 ;
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return 0 ;
}
V_265 = F_25 ( V_3 , V_272 , & V_102 ) ;
if ( V_102 )
F_59 ( V_3 , V_213 ,
V_214 ) ;
return V_265 ;
}
static long
F_86 ( struct V_2 * V_3 , void T_12 * V_215 )
{
struct V_314 V_122 ;
struct V_314 T_12 * V_253 = V_215 ;
void * V_282 , * V_315 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_265 , V_77 ;
T_6 V_272 ;
unsigned long V_153 , V_316 , V_317 ;
T_1 V_8 ;
T_1 V_151 ;
T_6 V_102 = 0 ;
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_104 ) ) ;
V_272 = V_122 . V_288 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_272 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_285 ;
}
if ( V_122 . V_288 != V_3 -> V_288 [ V_272 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_104 , V_122 . V_288 ) ;
return - V_171 ;
}
V_282 = V_3 -> V_287 [ V_272 ] ;
if ( ! V_282 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_104 , V_272 ) ;
return - V_168 ;
}
V_316 = V_3 -> V_293 [ V_272 ] ;
if ( ( V_122 . V_318 % 4 ) || ( V_122 . V_319 % 4 ) ) {
F_37 ( V_45 L_73 \
L_74 , V_3 -> V_46 ,
V_104 ) ;
return - V_171 ;
}
if ( V_122 . V_318 > V_316 )
return - V_171 ;
V_315 = ( void * ) ( V_282 + V_122 . V_318 ) ;
F_35 ( V_3 , F_6 ( V_45
L_75 ,
V_3 -> V_46 , V_104 ,
V_315 , V_122 . V_318 , V_122 . V_319 ) ) ;
if ( ( V_315 + V_122 . V_319 < V_315 ) ||
( V_315 + V_122 . V_319 > V_282 + V_316 ) )
V_317 = V_316 - V_122 . V_318 ;
else
V_317 = V_122 . V_319 ;
if ( F_36 ( ( void T_12 * ) V_253 -> V_320 ,
V_315 , V_317 ) ) {
F_37 ( V_45
L_76 ,
V_3 -> V_46 , V_104 , V_315 ) ;
return - V_165 ;
}
if ( ( V_122 . V_50 & V_321 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_77 ,
V_3 -> V_46 , V_104 , V_272 ) ) ;
if ( ( V_3 -> V_106 [ V_272 ] &
V_108 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_104 , V_272 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_172 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_163 ;
goto V_7;
}
V_265 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_146 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_294 = V_272 ;
V_11 -> V_297 =
F_79 ( V_3 -> V_293 [ V_272 ] ) ;
V_11 -> V_296 =
F_80 ( V_3 -> V_292 [ V_272 ] ) ;
for ( V_77 = 0 ; V_77 < V_290 ; V_77 ++ )
V_11 -> V_298 [ V_77 ] =
F_79 ( V_3 -> V_289 [ V_272 ] [ V_77 ] ) ;
V_11 -> V_144 = 0 ;
V_11 -> V_143 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_153 = F_53 ( & V_3 -> V_64 . V_75 ,
V_200 * V_201 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_104 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_110 ) )
V_102 = 1 ;
goto V_203;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_104 ) ;
V_265 = - V_165 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_151 = F_5 ( V_10 -> V_47 ) & V_204 ;
if ( V_151 == V_299 ) {
V_3 -> V_106 [ V_272 ] |=
V_107 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_104 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_104 ,
V_151 , F_7 ( V_10 -> V_48 ) ) ;
V_265 = - V_165 ;
}
V_203:
if ( V_102 )
F_59 ( V_3 , V_213 ,
V_214 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_265 ;
}
static long
F_87 ( struct V_2 * V_3 , unsigned V_322 ,
void T_12 * V_215 )
{
struct V_323 V_324 ;
struct V_323 T_12 * V_253 ;
struct V_121 V_122 ;
if ( F_88 ( V_322 ) != sizeof( struct V_323 ) )
return - V_171 ;
V_253 = (struct V_323 T_12 * ) V_215 ;
if ( F_42 ( & V_324 , ( char T_12 * ) V_215 , sizeof( V_324 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
memset ( & V_122 , 0 , sizeof( struct V_121 ) ) ;
V_122 . V_254 . V_98 = V_324 . V_254 . V_98 ;
V_122 . V_254 . V_220 = V_324 . V_254 . V_220 ;
V_122 . V_254 . V_255 = V_324 . V_254 . V_255 ;
V_122 . V_152 = V_324 . V_152 ;
V_122 . V_145 = V_324 . V_145 ;
V_122 . V_174 = V_324 . V_174 ;
V_122 . V_173 = V_324 . V_173 ;
V_122 . V_209 = V_324 . V_209 ;
V_122 . V_169 = V_324 . V_169 ;
V_122 . V_147 = F_89 ( V_324 . V_147 ) ;
V_122 . V_207 = F_89 ( V_324 . V_207 ) ;
V_122 . V_179 = F_89 ( V_324 . V_179 ) ;
V_122 . V_210 = F_89 ( V_324 . V_210 ) ;
return F_38 ( V_3 , V_122 , & V_253 -> V_148 ) ;
}
static long
F_90 ( struct V_114 * V_114 , unsigned int V_322 , void T_12 * V_215 ,
T_6 V_325 )
{
struct V_2 * V_3 ;
struct V_256 V_326 ;
enum V_327 V_328 ;
long V_161 = - V_171 ;
if ( F_42 ( & V_326 , ( char T_12 * ) V_215 ,
sizeof( struct V_256 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
return - V_165 ;
}
if ( F_22 ( V_326 . V_98 , & V_3 ) == - 1 || ! V_3 )
return - V_329 ;
if ( V_3 -> V_260 || V_3 -> V_261 ||
V_3 -> V_262 )
return - V_163 ;
V_328 = ( V_114 -> V_330 & V_331 ) ? V_332 : V_333 ;
if ( V_328 == V_332 ) {
if ( ! F_91 ( & V_3 -> V_64 . V_334 ) )
return - V_163 ;
} else if ( F_92 ( & V_3 -> V_64 . V_334 ) )
return - V_335 ;
switch ( V_322 ) {
case V_336 :
if ( F_88 ( V_322 ) == sizeof( struct V_216 ) )
V_161 = F_62 ( V_3 , V_215 ) ;
break;
#ifdef F_93
case V_337 :
#endif
case V_338 :
{
struct V_121 T_12 * V_253 ;
struct V_121 V_122 ;
#ifdef F_93
if ( V_325 ) {
V_161 = F_87 ( V_3 , V_322 , V_215 ) ;
break;
}
#endif
if ( F_42 ( & V_122 , V_215 , sizeof( V_122 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_104 ) ;
V_161 = - V_165 ;
break;
}
if ( F_88 ( V_322 ) == sizeof( struct V_121 ) ) {
V_253 = V_215 ;
V_161 = F_38 ( V_3 , V_122 , & V_253 -> V_148 ) ;
}
break;
}
case V_339 :
if ( F_88 ( V_322 ) == sizeof( struct V_244 ) )
V_161 = F_66 ( V_3 , V_215 ) ;
break;
case V_340 :
if ( F_88 ( V_322 ) == sizeof( struct V_248 ) )
V_161 = F_67 ( V_3 , V_215 ) ;
break;
case V_341 :
V_161 = F_70 ( V_3 , V_215 ) ;
break;
case V_342 :
if ( F_88 ( V_322 ) == sizeof( struct V_258 ) )
V_161 = F_71 ( V_3 , V_215 ) ;
break;
case V_343 :
if ( F_88 ( V_322 ) == sizeof( struct V_263 ) )
V_161 = F_75 ( V_3 , V_215 ) ;
break;
case V_344 :
if ( F_88 ( V_322 ) == sizeof( struct V_280 ) )
V_161 = F_82 ( V_3 , V_215 ) ;
break;
case V_345 :
if ( F_88 ( V_322 ) == sizeof( struct V_305 ) )
V_161 = F_83 ( V_3 , V_215 ) ;
break;
case V_346 :
if ( F_88 ( V_322 ) == sizeof( struct V_306 ) )
V_161 = F_84 ( V_3 , V_215 ) ;
break;
case V_347 :
if ( F_88 ( V_322 ) == sizeof( struct V_313 ) )
V_161 = F_85 ( V_3 , V_215 ) ;
break;
case V_348 :
if ( F_88 ( V_322 ) == sizeof( struct V_314 ) )
V_161 = F_86 ( V_3 , V_215 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_79 , V_3 -> V_46 , V_322 ) ) ;
break;
}
F_94 ( & V_3 -> V_64 . V_334 ) ;
return V_161 ;
}
static long
F_95 ( struct V_114 * V_114 , unsigned int V_322 , unsigned long V_215 )
{
long V_161 ;
V_161 = F_90 ( V_114 , V_322 , ( void T_12 * ) V_215 , 0 ) ;
return V_161 ;
}
static long
F_96 ( struct V_114 * V_114 , unsigned V_322 , unsigned long V_215 )
{
long V_161 ;
V_161 = F_90 ( V_114 , V_322 , ( void T_12 * ) V_215 , 1 ) ;
return V_161 ;
}
static T_23
F_97 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_80 ,
( V_3 -> V_176 . V_236 . V_237 & 0xFF000000 ) >> 24 ,
( V_3 -> V_176 . V_236 . V_237 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_176 . V_236 . V_237 & 0x0000FF00 ) >> 8 ,
V_3 -> V_176 . V_236 . V_237 & 0x000000FF ) ;
}
static T_23
F_100 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
T_7 V_356 = F_7 ( V_3 -> V_242 . V_243 ) ;
return snprintf ( V_352 , V_355 , L_80 ,
( V_356 & 0xFF000000 ) >> 24 ,
( V_356 & 0x00FF0000 ) >> 16 ,
( V_356 & 0x0000FF00 ) >> 8 ,
V_356 & 0x000000FF ) ;
}
static T_23
F_101 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_81 ,
V_3 -> V_176 . V_357 , V_3 -> V_176 . V_358 >> 8 ) ;
}
static T_23
F_102 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , 16 , L_51 , V_3 -> V_359 . V_360 ) ;
}
static T_23
F_103 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_82 ,
F_7 ( V_3 -> V_361 . V_362 . V_237 ) ) ;
}
static T_23
F_104 ( struct V_139 * V_349 , struct V_350
* V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_82 ,
F_7 ( V_3 -> V_361 . V_363 . V_237 ) ) ;
}
static T_23
F_105 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , 16 , L_51 , V_3 -> V_359 . V_364 ) ;
}
static T_23
F_106 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , 16 , L_51 , V_3 -> V_359 . V_365 ) ;
}
static T_23
F_107 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , 16 , L_51 , V_3 -> V_359 . V_366 ) ;
}
static T_23
F_108 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_83 , V_3 -> V_367 ) ;
}
static T_23
F_109 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_83 , V_3 -> V_368 ) ;
}
static T_23
F_110 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_83 , V_3 -> V_176 . V_369 ) ;
}
static T_23
F_111 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_84 ,
( unsigned long long ) V_3 -> V_370 . V_53 ) ;
}
static T_23
F_112 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_82 , V_3 -> V_13 ) ;
}
static T_23
F_113 ( struct V_139 * V_349 , struct V_350 * V_351 ,
const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
int V_372 = 0 ;
if ( sscanf ( V_352 , L_85 , & V_372 ) != 1 )
return - V_171 ;
V_3 -> V_13 = V_372 ;
F_6 ( V_45 L_86 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_352 ) ;
}
static T_23
F_114 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_87 , V_3 -> V_373 ) ;
}
static T_23
F_115 ( struct V_139 * V_349 , struct V_350 * V_351 ,
const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
int V_372 = 0 ;
if ( sscanf ( V_352 , L_88 , & V_372 ) != 1 )
return - V_171 ;
V_3 -> V_373 = V_372 ;
F_6 ( V_45 L_89 , V_3 -> V_46 ,
V_3 -> V_373 ) ;
return strlen ( V_352 ) ;
}
static T_23
F_116 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
return snprintf ( V_352 , V_355 , L_87 , V_3 -> V_374 ) ;
}
static T_23
F_117 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
T_6 V_375 ;
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
if ( ( V_3 -> V_176 . V_274 &
V_376 ) && V_3 -> V_377 )
V_375 = V_3 -> V_375 ;
else
V_375 = 1 ;
return snprintf ( V_352 , V_355 , L_87 , V_375 ) ;
}
static T_23
F_118 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
T_7 V_378 = 0 ;
struct V_379 * V_282 ;
if ( ! V_3 -> V_287 [ V_273 ] ) {
F_37 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( ( V_3 -> V_106 [ V_273 ] &
V_107 ) == 0 ) {
F_37 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
V_282 = (struct V_379 * )
V_3 -> V_287 [ V_273 ] ;
if ( ( F_7 ( V_282 -> V_380 ) == 0x00000000 ||
F_7 ( V_282 -> V_380 ) == 0x01000000 ||
F_7 ( V_282 -> V_380 ) == 0x01010000 ) &&
F_7 ( V_282 -> V_381 ) == 0x4742444c )
V_378 = F_7 ( V_282 -> V_382 ) ;
V_3 -> V_383 = V_378 ;
return snprintf ( V_352 , V_355 , L_87 , V_378 ) ;
}
static T_23
F_119 ( struct V_139 * V_349 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
void * V_282 ;
T_7 V_378 ;
if ( ! V_3 -> V_287 [ V_273 ] ) {
F_37 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( ( V_3 -> V_106 [ V_273 ] &
V_107 ) == 0 ) {
F_37 ( V_45
L_90 ,
V_3 -> V_46 , V_104 ) ;
return 0 ;
}
if ( V_3 -> V_384 > V_3 -> V_383 )
return 0 ;
V_378 = V_3 -> V_383 - V_3 -> V_384 ;
V_378 = ( V_378 >= V_355 ) ? ( V_355 - 1 ) : V_378 ;
V_282 = V_3 -> V_287 [ 0 ] + V_3 -> V_384 ;
memcpy ( V_352 , V_282 , V_378 ) ;
return V_378 ;
}
static T_23
F_120 ( struct V_139 * V_349 , struct V_350 * V_351 ,
const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
int V_372 = 0 ;
if ( sscanf ( V_352 , L_88 , & V_372 ) != 1 )
return - V_171 ;
V_3 -> V_384 = V_372 ;
return strlen ( V_352 ) ;
}
static T_23
F_121 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
if ( ( ! V_3 -> V_287 [ V_273 ] ) ||
( ( V_3 -> V_106 [ V_273 ] &
V_107 ) == 0 ) )
return snprintf ( V_352 , V_355 , L_91 ) ;
else if ( ( V_3 -> V_106 [ V_273 ] &
V_108 ) )
return snprintf ( V_352 , V_355 , L_92 ) ;
else
return snprintf ( V_352 , V_355 , L_93 ) ;
}
static T_23
F_122 ( struct V_139 * V_349 ,
struct V_350 * V_351 , const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
char V_385 [ 10 ] = L_94 ;
struct V_280 V_281 ;
T_6 V_102 = 0 ;
if ( V_3 -> V_260 || V_3 -> V_386 ||
V_3 -> V_261 || V_3 -> V_262 )
return - V_387 ;
if ( sscanf ( V_352 , L_95 , V_385 ) != 1 )
return - V_171 ;
if ( ! strcmp ( V_385 , L_96 ) ) {
if ( ( V_3 -> V_287 [ V_273 ] ) &&
( V_3 -> V_106 [ V_273 ] &
V_107 ) &&
( ( V_3 -> V_106 [ V_273 ] &
V_108 ) == 0 ) )
goto V_7;
memset ( & V_281 , 0 , sizeof( struct V_280 ) ) ;
F_6 ( V_45 L_97 ,
V_3 -> V_46 ) ;
V_281 . V_272 = V_273 ;
V_281 . V_286 = ( 1024 * 1024 ) ;
V_281 . V_288 = 0x7075900 ;
V_3 -> V_106 [ V_273 ] = 0 ;
F_77 ( V_3 , & V_281 ) ;
} else if ( ! strcmp ( V_385 , L_98 ) ) {
if ( ! V_3 -> V_287 [ V_273 ] )
goto V_7;
if ( ( V_3 -> V_106 [ V_273 ] &
V_107 ) == 0 )
goto V_7;
if ( ( V_3 -> V_106 [ V_273 ] &
V_108 ) )
goto V_7;
F_6 ( V_45 L_99 ,
V_3 -> V_46 ) ;
F_25 ( V_3 , V_273 ,
& V_102 ) ;
}
V_7:
return strlen ( V_352 ) ;
}
static T_23
F_123 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_265 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_265 = sizeof( struct V_389 ) ;
memcpy ( V_352 , & V_3 -> V_301 , V_265 ) ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_265 ;
}
static T_23
F_124 ( struct V_139 * V_349 ,
struct V_350 * V_351 , const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_265 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_265 = F_125 ( sizeof( struct V_389 ) , V_371 ) ;
memset ( & V_3 -> V_301 , 0 ,
sizeof( struct V_389 ) ) ;
memcpy ( & V_3 -> V_301 , V_352 , V_265 ) ;
V_3 -> V_301 . V_302 |=
( V_303 + V_304 ) ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_265 ;
}
static T_23
F_126 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_265 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_265 = sizeof( struct V_390 ) ;
memcpy ( V_352 , & V_3 -> V_391 , V_265 ) ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_265 ;
}
static T_23
F_127 ( struct V_139 * V_349 ,
struct V_350 * V_351 , const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_63 = F_125 ( sizeof( struct V_390 ) , V_371 ) ;
memset ( & V_3 -> V_391 , 0 ,
sizeof( struct V_390 ) ) ;
memcpy ( & V_3 -> V_391 , V_352 , V_63 ) ;
if ( V_3 -> V_391 . V_392 > V_393 )
V_3 -> V_391 . V_392 = V_393 ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_63 ;
}
static T_23
F_128 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_265 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_265 = sizeof( struct V_394 ) ;
memcpy ( V_352 , & V_3 -> V_395 , V_265 ) ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_265 ;
}
static T_23
F_129 ( struct V_139 * V_349 ,
struct V_350 * V_351 , const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_63 = F_125 ( sizeof( struct V_394 ) , V_371 ) ;
memset ( & V_3 -> V_395 , 0 ,
sizeof( struct V_390 ) ) ;
memcpy ( & V_3 -> V_395 , V_352 , V_63 ) ;
if ( V_3 -> V_395 . V_392 > V_393 )
V_3 -> V_395 . V_392 = V_393 ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_63 ;
}
static T_23
F_130 ( struct V_139 * V_349 ,
struct V_350 * V_351 , char * V_352 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_265 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_265 = sizeof( struct V_396 ) ;
memcpy ( V_352 , & V_3 -> V_397 , V_265 ) ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_265 ;
}
static T_23
F_131 ( struct V_139 * V_349 ,
struct V_350 * V_351 , const char * V_352 , T_15 V_371 )
{
struct V_353 * V_354 = F_98 ( V_349 ) ;
struct V_2 * V_3 = F_99 ( V_354 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_388 , V_50 ) ;
V_63 = F_125 ( sizeof( struct V_396 ) , V_371 ) ;
memset ( & V_3 -> V_397 , 0 ,
sizeof( struct V_390 ) ) ;
memcpy ( & V_3 -> V_397 , V_352 , V_63 ) ;
if ( V_3 -> V_397 . V_392 > V_393 )
V_3 -> V_397 . V_392 = V_393 ;
F_10 ( & V_3 -> V_388 , V_50 ) ;
return V_63 ;
}
static T_23
F_132 ( struct V_139 * V_398 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_399 * V_400 = F_133 ( V_398 ) ;
struct V_127 * V_401 = V_400 -> V_140 ;
return snprintf ( V_352 , V_355 , L_84 ,
( unsigned long long ) V_401 -> V_141 -> V_53 ) ;
}
static T_23
F_134 ( struct V_139 * V_398 , struct V_350 * V_351 ,
char * V_352 )
{
struct V_399 * V_400 = F_133 ( V_398 ) ;
struct V_127 * V_401 = V_400 -> V_140 ;
return snprintf ( V_352 , V_355 , L_100 ,
V_401 -> V_141 -> V_4 ) ;
}
void
F_135 ( void )
{
V_95 = NULL ;
if ( F_136 ( & V_402 ) < 0 )
F_37 ( L_101 ,
V_239 , V_403 ) ;
F_137 ( & V_94 ) ;
}
void
F_138 ( void )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_105 ; V_77 ++ ) {
if ( ! V_3 -> V_287 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_106 [ V_77 ] &
V_107 ) )
continue;
if ( ( V_3 -> V_106 [ V_77 ] &
V_108 ) )
continue;
F_60 ( V_3 -> V_178 , V_3 -> V_293 [ V_77 ] ,
V_3 -> V_287 [ V_77 ] , V_3 -> V_292 [ V_77 ] ) ;
V_3 -> V_287 [ V_77 ] = NULL ;
V_3 -> V_106 [ V_77 ] = 0 ;
}
F_61 ( V_3 -> V_79 ) ;
}
F_139 ( & V_402 ) ;
}
