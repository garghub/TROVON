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
F_17 ( V_3 , V_10 ) ;
return 1 ;
}
static int
F_21 ( int V_98 , struct V_2 * * V_99 ,
int V_100 )
{
struct V_2 * V_3 ;
F_22 ( & V_101 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_102 != V_98 )
continue;
if ( V_3 -> V_103 != V_100 )
continue;
F_23 ( & V_101 ) ;
* V_99 = V_3 ;
return V_98 ;
}
F_23 ( & V_101 ) ;
* V_99 = NULL ;
return - 1 ;
}
void
F_24 ( struct V_2 * V_3 , int V_104 )
{
int V_77 ;
T_6 V_105 ;
switch ( V_104 ) {
case V_106 :
F_25 ( V_3 , F_6 ( V_45
L_25 , V_3 -> V_46 , V_107 ) ) ;
for ( V_77 = 0 ; V_77 < V_108 ; V_77 ++ ) {
if ( ! ( V_3 -> V_109 [ V_77 ] &
V_110 ) )
continue;
if ( ( V_3 -> V_109 [ V_77 ] &
V_111 ) )
continue;
F_26 ( V_3 , V_77 , & V_105 ) ;
}
break;
case V_112 :
F_25 ( V_3 , F_6 ( V_45
L_26 , V_3 -> V_46 , V_107 ) ) ;
if ( V_3 -> V_64 . V_65 & V_74 ) {
V_3 -> V_64 . V_65 |= V_113 ;
F_27 ( V_3 , V_3 -> V_64 . V_8 ) ;
F_15 ( & V_3 -> V_64 . V_75 ) ;
}
break;
case V_114 :
F_25 ( V_3 , F_6 ( V_45
L_27 , V_3 -> V_46 , V_107 ) ) ;
for ( V_77 = 0 ; V_77 < V_108 ; V_77 ++ ) {
if ( ! ( V_3 -> V_109 [ V_77 ] &
V_110 ) )
continue;
if ( ( V_3 -> V_109 [ V_77 ] &
V_111 ) )
continue;
V_3 -> V_109 [ V_77 ] |=
V_115 ;
}
break;
}
}
int
F_28 ( int V_116 , struct V_117 * V_118 , int V_119 )
{
return F_29 ( V_116 , V_118 , V_119 , & V_95 ) ;
}
unsigned int
F_30 ( struct V_117 * V_118 , T_9 * V_120 )
{
struct V_2 * V_3 ;
F_31 ( V_118 , & V_94 , V_120 ) ;
F_22 ( & V_101 ) ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
if ( V_3 -> V_93 ) {
F_23 ( & V_101 ) ;
return V_121 | V_122 ;
}
}
F_23 ( & V_101 ) ;
return 0 ;
}
static int
F_32 ( struct V_2 * V_3 , struct V_123 * V_124 ,
T_10 * V_125 )
{
T_6 V_126 = 0 ;
T_1 V_77 ;
T_1 V_4 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
unsigned long V_50 ;
T_11 * V_131 ;
T_7 V_63 ;
T_7 V_132 ;
char * V_12 = NULL ;
if ( V_125 -> V_133 == V_134 )
V_12 = L_28 ;
else if ( V_125 -> V_133 == V_135 )
V_12 = L_29 ;
else
return 0 ;
V_132 = F_33 ( (struct V_136 * ) V_125 -> V_137 ) ;
V_4 = F_5 ( V_125 -> V_52 ) ;
F_8 ( & V_3 -> V_138 , V_50 ) ;
for ( V_77 = V_3 -> V_139 ; V_77 && ! V_126 ; V_77 -- ) {
V_128 = V_3 -> V_140 [ V_77 - 1 ] . V_128 ;
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
V_125 -> V_144 = F_34 ( V_3 -> V_140 [ V_77 - 1 ] . V_8 ) ;
V_126 = 1 ;
}
F_10 ( & V_3 -> V_138 , V_50 ) ;
if ( ! V_126 ) {
F_35 ( V_3 , F_6 ( V_45
L_30 ,
V_3 -> V_46 ,
V_12 , F_5 ( V_125 -> V_52 ) , V_132 ) ) ;
V_131 = V_3 -> V_64 . V_60 ;
V_131 -> V_52 = V_125 -> V_52 ;
V_131 -> V_15 = V_23 ;
V_131 -> V_133 = V_125 -> V_133 ;
V_131 -> V_68 = sizeof( T_11 ) / 4 ;
V_131 -> V_145 = V_125 -> V_145 ;
V_131 -> V_146 = V_125 -> V_146 ;
V_63 = F_13 ( T_7 , V_124 -> V_147 , V_3 -> V_148 ) ;
if ( F_36 ( V_124 -> V_149 , V_3 -> V_64 . V_60 ,
V_63 ) )
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
return 1 ;
}
F_35 ( V_3 , F_6 ( V_45
L_32 , V_3 -> V_46 ,
V_12 , F_5 ( V_125 -> V_52 ) , V_132 ,
F_5 ( V_125 -> V_144 ) ) ) ;
return 0 ;
}
static long
F_38 ( struct V_2 * V_3 , struct V_123 V_124 ,
void T_12 * V_150 )
{
T_13 * V_11 = NULL , * V_151 ;
T_2 * V_10 ;
T_7 V_152 ;
T_1 V_153 ;
T_1 V_8 ;
unsigned long V_154 , V_155 ;
T_6 V_105 ;
T_7 V_63 ;
void * V_156 ;
void * V_157 = NULL ;
T_14 V_158 = 0 ;
T_15 V_159 = 0 ;
void * V_160 = NULL ;
T_14 V_161 = 0 ;
T_15 V_162 = 0 ;
long V_163 ;
T_1 V_164 ;
V_105 = 0 ;
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_107 ) ;
V_163 = - V_165 ;
goto V_7;
}
V_164 = 0 ;
V_152 = F_39 ( V_3 , 1 ) ;
while ( V_152 != V_166 ) {
if ( V_164 ++ == 10 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_107 ) ;
V_163 = - V_167 ;
goto V_7;
}
F_40 ( 1 ) ;
V_152 = F_39 ( V_3 , 1 ) ;
F_6 ( V_45
L_35 ,
V_3 -> V_46 ,
V_107 , V_164 ) ;
}
if ( V_164 )
F_6 ( V_45 L_36 ,
V_3 -> V_46 , V_107 ) ;
V_11 = F_41 ( V_3 -> V_168 , V_169 ) ;
if ( ! V_11 ) {
F_37 ( V_45
L_37 ,
V_3 -> V_46 , V_107 ) ;
V_163 = - V_170 ;
goto V_7;
}
if ( V_124 . V_171 * 4 > V_3 -> V_168 ||
V_124 . V_171 > ( V_172 / 4 ) ) {
V_163 = - V_173 ;
goto V_7;
}
if ( F_42 ( V_11 , V_150 , V_124 . V_171 * 4 ) ) {
F_37 ( L_31 , __FILE__ , __LINE__ ,
V_107 ) ;
V_163 = - V_167 ;
goto V_7;
}
if ( V_11 -> V_15 == V_23 ) {
V_8 = F_43 ( V_3 , V_3 -> V_174 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_107 ) ;
V_163 = - V_165 ;
goto V_7;
}
} else {
V_8 = F_44 ( V_3 , V_3 -> V_174 , NULL ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_107 ) ;
V_163 = - V_165 ;
goto V_7;
}
}
V_163 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_148 ) ;
V_151 = F_4 ( V_3 , V_8 ) ;
memcpy ( V_151 , V_11 , V_124 . V_171 * 4 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_159 = V_124 . V_175 ;
V_162 = V_124 . V_176 ;
if ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 == V_39 ) {
if ( ! F_5 ( V_11 -> V_177 ) ||
F_5 ( V_11 -> V_177 ) >
V_3 -> V_178 . V_179 ) {
V_163 = - V_173 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_159 ) {
V_157 = F_45 ( V_3 -> V_180 , V_159 ,
& V_158 ) ;
if ( ! V_157 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_170 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
if ( F_42 ( V_157 , V_124 . V_181 ,
V_159 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_167 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
if ( V_162 ) {
V_160 = F_45 ( V_3 -> V_180 , V_162 ,
& V_161 ) ;
if ( ! V_160 ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_170 ;
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
V_156 = ( void * ) V_151 + ( V_124 . V_171 * 4 ) ;
F_3 ( V_3 , V_8 , L_39 , NULL ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
switch ( V_11 -> V_15 ) {
case V_16 :
case V_39 :
{
T_4 * V_182 =
( T_4 * ) V_151 ;
V_182 -> V_183 = V_71 ;
V_182 -> V_184 =
F_47 ( V_3 , V_8 ) ;
memset ( V_3 -> V_64 . V_73 , 0 , V_71 ) ;
V_3 -> V_185 ( V_3 , V_156 , V_158 , V_159 ,
V_161 , V_162 ) ;
if ( V_11 -> V_15 == V_16 )
F_48 ( V_3 , V_8 ,
F_5 ( V_11 -> V_177 ) ) ;
else
F_49 ( V_3 , V_8 ) ;
break;
}
case V_23 :
{
T_10 * V_125 =
( T_10 * ) V_151 ;
F_25 ( V_3 , F_6 ( V_45
L_40 ,
V_3 -> V_46 ,
F_5 ( V_125 -> V_52 ) , V_125 -> V_133 ) ) ;
if ( V_125 -> V_133 ==
V_134 ||
V_125 -> V_133 ==
V_135 ) {
if ( F_32 ( V_3 , & V_124 , V_125 ) ) {
F_27 ( V_3 , V_8 ) ;
goto V_7;
}
}
F_50 ( V_3 , F_5 (
V_125 -> V_52 ) ) ;
V_3 -> V_186 ( V_3 , V_156 , V_158 , V_159 ,
V_161 , V_162 ) ;
F_51 ( V_3 , V_8 ) ;
break;
}
case V_44 :
{
T_16 * V_187 =
( T_16 * ) V_11 ;
T_6 * V_90 ;
V_187 -> V_188 = 0xFF ;
if ( V_187 -> V_189 &
V_190 )
V_90 = ( T_6 * ) & V_187 -> V_191 ;
else {
if ( F_52 ( V_157 == NULL ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
F_27 ( V_3 , V_8 ) ;
V_163 = - V_173 ;
goto V_7;
}
V_90 = V_157 ;
}
if ( V_90 [ 1 ] == 0x91 && ( V_90 [ 10 ] == 1 || V_90 [ 10 ] == 2 ) ) {
V_3 -> V_192 = 1 ;
V_3 -> V_193 = 1 ;
}
V_3 -> V_185 ( V_3 , V_156 , V_158 , V_159 , V_161 ,
V_162 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_41 :
case V_36 :
case V_37 :
{
V_3 -> V_185 ( V_3 , V_156 , V_158 , V_159 , V_161 ,
V_162 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
case V_194 :
{
T_17 * V_195 =
( T_17 * ) V_11 ;
if ( V_195 -> V_196 == V_197 ) {
V_3 -> V_185 ( V_3 , V_156 , V_158 , V_159 ,
V_161 , V_162 ) ;
} else {
V_3 -> V_186 ( V_3 , V_156 , V_158 , V_159 ,
V_161 , V_162 ) ;
}
F_49 ( V_3 , V_8 ) ;
break;
}
case V_40 :
{
T_18 * V_198 =
( T_18 * ) V_11 ;
if ( V_198 -> V_199 == V_200
|| V_198 -> V_199 ==
V_201 ) {
V_3 -> V_192 = 1 ;
V_3 -> V_193 = 1 ;
}
}
default:
V_3 -> V_186 ( V_3 , V_156 , V_158 , V_159 ,
V_161 , V_162 ) ;
F_49 ( V_3 , V_8 ) ;
break;
}
if ( V_124 . V_154 < V_202 )
V_154 = V_202 ;
else
V_154 = V_124 . V_154 ;
V_155 = F_53 ( & V_3 -> V_64 . V_75 ,
V_154 * V_203 ) ;
if ( V_11 -> V_15 == V_23 ) {
T_10 * V_125 =
( T_10 * ) V_11 ;
F_54 ( V_3 , F_5 (
V_125 -> V_52 ) ) ;
F_55 ( V_3 , V_204 ) ;
} else if ( ( V_11 -> V_15 == V_44 ||
V_11 -> V_15 == V_40 ) &&
V_3 -> V_192 ) {
V_3 -> V_192 = 0 ;
V_3 -> V_193 = 0 ;
}
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_107 ) ;
F_56 ( V_11 , V_124 . V_171 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_113 ) )
V_105 = 1 ;
goto V_205;
}
V_10 = V_3 -> V_64 . V_60 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_206 ;
if ( V_10 -> V_15 == V_23 &&
( V_3 -> V_13 & V_207 ) ) {
T_11 * V_131 =
( T_11 * ) V_10 ;
F_6 ( V_45 L_42 \
L_43
L_44 , V_3 -> V_46 ,
F_5 ( V_131 -> V_47 ) ,
F_7 ( V_131 -> V_48 ) ,
F_7 ( V_131 -> V_208 ) ) ;
}
if ( V_162 ) {
if ( F_36 ( V_124 . V_209 , V_160 ,
V_162 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_210 ;
goto V_7;
}
}
if ( V_124 . V_147 ) {
V_63 = F_13 ( T_7 , V_124 . V_147 , V_3 -> V_148 ) ;
if ( F_36 ( V_124 . V_149 , V_3 -> V_64 . V_60 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_210 ;
goto V_7;
}
}
if ( V_124 . V_211 && ( V_11 -> V_15 ==
V_16 || V_11 -> V_15 ==
V_39 ) ) {
V_63 = F_13 ( T_7 , V_124 . V_211 , V_71 ) ;
if ( F_36 ( V_124 . V_212 , V_3 -> V_64 . V_73 ,
V_63 ) ) {
F_37 ( L_31 , __FILE__ ,
__LINE__ , V_107 ) ;
V_163 = - V_210 ;
goto V_7;
}
}
V_205:
if ( V_105 ) {
V_163 = - V_210 ;
if ( ( V_11 -> V_15 == V_16 ||
V_11 -> V_15 ==
V_39 ||
V_11 -> V_15 == V_41 ) ) {
F_6 ( V_45 L_45 ,
V_3 -> V_46 ,
F_5 ( V_11 -> V_177 ) ) ;
F_57 ( V_3 ) ;
F_58 ( V_3 ,
F_5 ( V_11 -> V_177 ) , 0 , 0 ,
0 , V_213 , 0 , 30 ,
V_214 ) ;
} else
F_59 ( V_3 , V_215 ,
V_216 ) ;
}
V_7:
if ( V_160 )
F_60 ( V_3 -> V_180 , V_162 , V_160 ,
V_161 ) ;
if ( V_157 )
F_60 ( V_3 -> V_180 , V_159 , V_157 ,
V_158 ) ;
F_61 ( V_11 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_163 ;
}
static long
F_62 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_218 V_124 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_107 ) ) ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
if ( V_3 -> V_219 )
V_124 . V_220 = V_3 -> V_219 [ 0 ] . V_221 ;
V_124 . V_222 = V_3 -> V_180 -> V_223 ;
V_124 . V_224 = V_3 -> V_180 -> V_141 ;
V_124 . V_225 = V_3 -> V_180 -> V_225 ;
V_124 . V_226 = V_3 -> V_180 -> V_226 ;
V_124 . V_227 . V_228 . V_229 . V_230 = V_3 -> V_180 -> V_230 -> V_231 ;
V_124 . V_227 . V_228 . V_229 . V_141 = F_63 ( V_3 -> V_180 -> V_232 ) ;
V_124 . V_227 . V_228 . V_229 . V_233 = F_64 ( V_3 -> V_180 -> V_232 ) ;
V_124 . V_227 . V_234 = F_65 ( V_3 -> V_180 -> V_230 ) ;
V_124 . V_235 = V_3 -> V_178 . V_236 . V_237 ;
strcpy ( V_124 . V_238 , V_3 -> V_239 ) ;
strcat ( V_124 . V_238 , L_47 ) ;
switch ( V_3 -> V_103 ) {
case V_240 :
if ( V_3 -> V_241 )
V_124 . V_242 = V_243 ;
else
V_124 . V_242 = V_244 ;
strcat ( V_124 . V_238 , V_245 ) ;
break;
case V_246 :
V_124 . V_242 = V_247 ;
strcat ( V_124 . V_238 , V_248 ) ;
break;
}
V_124 . V_249 = F_7 ( V_3 -> V_250 . V_251 ) ;
if ( F_36 ( V_217 , & V_124 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
return 0 ;
}
static long
F_66 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_252 V_124 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_107 ) ) ;
V_124 . V_253 = V_86 ;
memcpy ( V_124 . V_254 , V_3 -> V_80 ,
V_255 * sizeof( T_7 ) ) ;
if ( F_36 ( V_217 , & V_124 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
return 0 ;
}
static long
F_67 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_256 V_124 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_107 ) ) ;
memcpy ( V_3 -> V_80 , V_124 . V_254 ,
V_255 * sizeof( T_7 ) ) ;
F_68 ( V_3 , V_3 -> V_80 ) ;
if ( V_3 -> V_79 )
return 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_79 = F_69 ( V_86 ,
sizeof( struct V_81 ) , V_169 ) ;
if ( ! V_3 -> V_79 ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_170 ;
}
return 0 ;
}
static long
F_70 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_257 V_124 ;
T_7 V_258 , V_259 , V_260 ;
struct V_257 T_12 * V_261 = V_217 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_107 ) ) ;
V_258 = V_124 . V_262 . V_263 -
sizeof( struct V_264 ) ;
V_259 = V_258 / sizeof( struct V_81 ) ;
V_260 = F_13 ( T_7 , V_86 , V_259 ) ;
if ( ! V_260 || ! V_3 -> V_79 )
return - V_210 ;
V_258 = V_260 * sizeof( struct V_81 ) ;
if ( F_36 ( V_261 -> V_265 , V_3 -> V_79 , V_258 ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
V_3 -> V_93 = 0 ;
return 0 ;
}
static long
F_71 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_266 V_124 ;
int V_267 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 )
return - V_165 ;
F_35 ( V_3 , F_6 ( V_45 L_46 , V_3 -> V_46 ,
V_107 ) ) ;
V_267 = F_59 ( V_3 , V_215 ,
V_216 ) ;
F_6 ( V_45 L_48 ,
V_3 -> V_46 , ( ( ! V_267 ) ? L_49 : L_50 ) ) ;
return 0 ;
}
static int
F_72 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_1 * V_5 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_73 ( & V_3 -> V_274 ) )
return V_273 ;
F_8 ( & V_3 -> V_51 , V_50 ) ;
F_2 (sas_device, &ioc->sas_device_list, list) {
if ( V_272 -> V_230 == 0xFFFFFFFF && V_272 -> V_102 == 0xFFFFFFFF &&
V_272 -> V_4 == V_5 -> V_4 ) {
V_272 -> V_230 = V_5 -> V_275 ;
V_272 -> V_102 = V_5 -> V_102 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_230 == V_5 -> V_275 && V_272 -> V_102 ==
V_5 -> V_102 && V_272 -> V_4 == 0xFFFF ) {
V_272 -> V_4 = V_5 -> V_4 ;
V_273 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_51 , V_50 ) ;
return V_273 ;
}
static int
F_74 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_276 * V_277 ;
unsigned long V_50 ;
int V_273 = 0 ;
if ( F_73 ( & V_3 -> V_278 ) )
return V_273 ;
F_8 ( & V_3 -> V_279 , V_50 ) ;
F_2 (raid_device, &ioc->raid_device_list, list) {
if ( V_272 -> V_230 == 0xFFFFFFFF && V_272 -> V_102 == 0xFFFFFFFF &&
V_272 -> V_4 == V_277 -> V_4 ) {
V_272 -> V_230 = V_277 -> V_275 ;
V_272 -> V_102 = V_277 -> V_102 ;
V_273 = 1 ;
goto V_7;
} else if ( V_272 -> V_230 == V_277 -> V_275 && V_272 -> V_102 ==
V_277 -> V_102 && V_272 -> V_4 == 0xFFFF ) {
V_272 -> V_4 = V_277 -> V_4 ;
V_273 = 1 ;
goto V_7;
}
}
V_7:
F_10 ( & V_3 -> V_279 , V_50 ) ;
return V_273 ;
}
static long
F_75 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_271 V_124 ;
int V_273 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_273 = F_72 ( V_3 , & V_124 ) ;
if ( ! V_273 )
F_74 ( V_3 , & V_124 ) ;
if ( F_36 ( V_217 , & V_124 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
return 0 ;
}
static T_6
F_76 ( struct V_2 * V_3 , T_6 V_280 )
{
T_6 V_273 = 0 ;
switch ( V_280 ) {
case V_281 :
if ( V_3 -> V_178 . V_282 &
V_283 )
V_273 = 1 ;
break;
case V_284 :
if ( V_3 -> V_178 . V_282 &
V_285 )
V_273 = 1 ;
break;
case V_286 :
if ( V_3 -> V_178 . V_282 &
V_287 )
V_273 = 1 ;
}
return V_273 ;
}
static long
F_77 ( struct V_2 * V_3 ,
struct V_288 * V_289 )
{
int V_273 , V_77 ;
void * V_290 = NULL ;
T_14 V_291 ;
T_7 V_292 = 0 ;
T_19 * V_11 ;
T_20 * V_10 ;
T_6 V_280 ;
unsigned long V_155 ;
T_1 V_8 ;
T_1 V_153 ;
T_7 V_152 ;
T_6 V_105 = 0 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_152 = F_39 ( V_3 , 1 ) ;
if ( V_152 != V_166 ) {
F_37 ( V_45
L_34 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_280 = V_289 -> V_280 ;
if ( ! F_76 ( V_3 , V_280 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_293 ;
}
if ( V_3 -> V_109 [ V_280 ] &
V_110 ) {
F_37 ( V_45
L_53 ,
V_3 -> V_46 , V_107 ,
V_280 ) ;
return - V_173 ;
}
if ( V_289 -> V_294 % 4 ) {
F_37 ( V_45
L_54 ,
V_3 -> V_46 , V_107 ) ;
return - V_173 ;
}
V_8 = F_78 ( V_3 , V_3 -> V_174 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
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
F_60 ( V_3 -> V_180 ,
V_3 -> V_301 [ V_280 ] ,
V_290 , V_291 ) ;
V_290 = NULL ;
}
}
if ( V_290 == NULL ) {
V_3 -> V_301 [ V_280 ] = 0 ;
V_3 -> V_300 [ V_280 ] = 0 ;
V_290 = F_45 (
V_3 -> V_180 , V_292 , & V_291 ) ;
if ( V_290 == NULL ) {
F_37 ( V_45 L_55 \
L_56 ,
V_3 -> V_46 , V_107 , V_292 ) ;
F_27 ( V_3 , V_8 ) ;
return - V_170 ;
}
V_3 -> V_295 [ V_280 ] = V_290 ;
V_3 -> V_301 [ V_280 ] = V_292 ;
V_3 -> V_300 [ V_280 ] = V_291 ;
}
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_289 -> V_280 ;
V_11 -> V_303 = F_79 ( V_289 -> V_299 ) ;
V_11 -> V_304 = F_80 ( V_291 ) ;
V_11 -> V_305 = F_79 ( V_292 ) ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_35 ( V_3 , F_6 ( V_45
L_57 ,
V_3 -> V_46 , V_107 , V_290 ,
( unsigned long long ) V_291 ,
F_7 ( V_11 -> V_305 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_298 ; V_77 ++ )
V_11 -> V_306 [ V_77 ] =
F_79 ( V_3 -> V_297 [ V_280 ] [ V_77 ] ) ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_155 = F_53 ( & V_3 -> V_64 . V_75 ,
V_202 * V_203 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_107 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_113 ) )
V_105 = 1 ;
goto V_205;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_206 ;
if ( V_153 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_110 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_107 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_107 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_167 ;
}
V_205:
if ( V_105 )
F_59 ( V_3 , V_215 ,
V_216 ) ;
V_7:
if ( V_273 && V_290 )
F_60 ( V_3 -> V_180 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_64 . V_65 = V_66 ;
return V_273 ;
}
void
F_81 ( struct V_2 * V_3 , T_6 V_308 )
{
struct V_288 V_289 ;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
if ( V_308 & 1 ) {
F_6 ( V_45 L_61 ,
V_3 -> V_46 ) ;
V_3 -> V_309 . V_310 =
( V_311 + V_312 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
F_77 ( V_3 , & V_289 ) ;
}
if ( V_308 & 2 ) {
F_6 ( V_45 L_62 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_284 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_77 ( V_3 , & V_289 ) ;
}
if ( V_308 & 4 ) {
F_6 ( V_45 L_63 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_286 ;
V_289 . V_294 = 2 * ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075901 ;
F_77 ( V_3 , & V_289 ) ;
}
}
static long
F_82 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_288 V_124 ;
long V_273 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
V_273 = F_77 ( V_3 , & V_124 ) ;
return V_273 ;
}
static long
F_83 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_313 V_124 ;
void * V_290 ;
T_14 V_291 ;
T_7 V_292 ;
T_6 V_280 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_280 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_173 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_111 ) == 0 ) {
F_37 ( V_45
L_65 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_173 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_107 , V_124 . V_296 ) ;
return - V_173 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_170 ;
}
V_292 = V_3 -> V_301 [ V_280 ] ;
V_291 = V_3 -> V_300 [ V_280 ] ;
F_60 ( V_3 -> V_180 , V_292 ,
V_290 , V_291 ) ;
V_3 -> V_295 [ V_280 ] = NULL ;
V_3 -> V_109 [ V_280 ] = 0 ;
return 0 ;
}
static long
F_84 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_314 V_124 ;
void * V_290 ;
int V_77 ;
T_6 V_280 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_124 . V_315 = 0 ;
V_280 = V_124 . V_280 ;
if ( ! F_76 ( V_3 , V_280 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_173 ;
}
if ( V_124 . V_296 & 0xffffff00 ) {
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_107 , V_124 . V_296 ) ;
return - V_173 ;
}
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_170 ;
}
if ( V_3 -> V_109 [ V_280 ] & V_111 )
V_124 . V_315 = ( V_316 |
V_317 ) ;
else
V_124 . V_315 = ( V_316 |
V_317 |
V_318 ) ;
for ( V_77 = 0 ; V_77 < V_298 ; V_77 ++ )
V_124 . V_297 [ V_77 ] =
V_3 -> V_297 [ V_280 ] [ V_77 ] ;
V_124 . V_319 = V_3 -> V_301 [ V_280 ] ;
V_124 . V_320 = 0 ;
V_124 . V_296 = V_3 -> V_296 [ V_280 ] ;
V_124 . V_299 = V_3 -> V_299 [ V_280 ] ;
if ( F_36 ( V_217 , & V_124 , sizeof( struct V_314 ) ) ) {
F_37 ( V_45
L_69 ,
V_3 -> V_46 , V_107 , V_217 ) ;
return - V_167 ;
}
return 0 ;
}
int
F_26 ( struct V_2 * V_3 , T_6 V_280 ,
T_6 * V_105 )
{
T_21 * V_11 ;
T_22 * V_10 ;
T_1 V_8 ;
T_1 V_153 ;
T_7 V_152 ;
int V_273 ;
unsigned long V_155 ;
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_273 = 0 ;
* V_105 = 0 ;
V_152 = F_39 ( V_3 , 1 ) ;
if ( V_152 != V_166 ) {
if ( V_3 -> V_109 [ V_280 ] &
V_110 )
V_3 -> V_109 [ V_280 ] |=
V_111 ;
F_35 ( V_3 , F_6 ( V_45
L_70 , V_3 -> V_46 ,
V_107 ) ) ;
V_273 = - V_165 ;
goto V_7;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_174 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_43 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_155 = F_53 ( & V_3 -> V_64 . V_75 ,
V_202 * V_203 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_107 ) ;
F_56 ( V_11 ,
sizeof( T_21 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_113 ) )
* V_105 = 1 ;
V_273 = - V_167 ;
goto V_7;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_206 ;
if ( V_153 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_111 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_107 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_107 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_167 ;
}
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_273 ;
}
static long
F_85 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_321 V_124 ;
void * V_290 ;
int V_273 ;
T_6 V_280 ;
T_6 V_105 = 0 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_280 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_293 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_110 ) == 0 ) {
F_37 ( V_45
L_64 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_173 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_107 , V_124 . V_296 ) ;
return - V_173 ;
}
if ( V_3 -> V_109 [ V_280 ] &
V_111 ) {
F_37 ( V_45
L_71 ,
V_3 -> V_46 , V_107 ,
V_280 ) ;
return 0 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_37 ( V_45
L_67 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_170 ;
}
if ( ( V_3 -> V_109 [ V_280 ] &
V_115 ) ) {
V_3 -> V_109 [ V_280 ] |=
V_111 ;
V_3 -> V_109 [ V_280 ] &=
~ V_115 ;
F_37 ( V_45
L_72 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return 0 ;
}
V_273 = F_26 ( V_3 , V_280 , & V_105 ) ;
if ( V_105 )
F_59 ( V_3 , V_215 ,
V_216 ) ;
return V_273 ;
}
static long
F_86 ( struct V_2 * V_3 , void T_12 * V_217 )
{
struct V_322 V_124 ;
struct V_322 T_12 * V_261 = V_217 ;
void * V_290 , * V_323 ;
T_19 * V_11 ;
T_20 * V_10 ;
int V_273 , V_77 ;
T_6 V_280 ;
unsigned long V_155 , V_324 , V_325 ;
T_1 V_8 ;
T_1 V_153 ;
T_6 V_105 = 0 ;
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
F_35 ( V_3 , F_6 ( V_45 L_51 , V_3 -> V_46 ,
V_107 ) ) ;
V_280 = V_124 . V_296 & 0x000000ff ;
if ( ! F_76 ( V_3 , V_280 ) ) {
F_37 ( V_45
L_52 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_293 ;
}
if ( V_124 . V_296 != V_3 -> V_296 [ V_280 ] ) {
F_37 ( V_45
L_66 ,
V_3 -> V_46 , V_107 , V_124 . V_296 ) ;
return - V_173 ;
}
V_290 = V_3 -> V_295 [ V_280 ] ;
if ( ! V_290 ) {
F_37 ( V_45
L_68 ,
V_3 -> V_46 , V_107 , V_280 ) ;
return - V_170 ;
}
V_324 = V_3 -> V_301 [ V_280 ] ;
if ( ( V_124 . V_326 % 4 ) || ( V_124 . V_327 % 4 ) ) {
F_37 ( V_45 L_73 \
L_74 , V_3 -> V_46 ,
V_107 ) ;
return - V_173 ;
}
if ( V_124 . V_326 > V_324 )
return - V_173 ;
V_323 = ( void * ) ( V_290 + V_124 . V_326 ) ;
F_35 ( V_3 , F_6 ( V_45
L_75 ,
V_3 -> V_46 , V_107 ,
V_323 , V_124 . V_326 , V_124 . V_327 ) ) ;
if ( ( V_323 + V_124 . V_327 < V_323 ) ||
( V_323 + V_124 . V_327 > V_290 + V_324 ) )
V_325 = V_324 - V_124 . V_326 ;
else
V_325 = V_124 . V_327 ;
if ( F_36 ( ( void T_12 * ) V_261 -> V_328 ,
V_323 , V_325 ) ) {
F_37 ( V_45
L_76 ,
V_3 -> V_46 , V_107 , V_323 ) ;
return - V_167 ;
}
if ( ( V_124 . V_50 & V_329 ) == 0 )
return 0 ;
F_35 ( V_3 , F_6 ( V_45
L_77 ,
V_3 -> V_46 , V_107 , V_280 ) ) ;
if ( ( V_3 -> V_109 [ V_280 ] &
V_111 ) == 0 ) {
F_35 ( V_3 , F_6 ( V_45
L_78 ,
V_3 -> V_46 , V_107 , V_280 ) ) ;
return 0 ;
}
if ( V_3 -> V_64 . V_65 != V_66 ) {
F_37 ( V_45 L_33 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_8 = F_78 ( V_3 , V_3 -> V_174 ) ;
if ( ! V_8 ) {
F_37 ( V_45 L_38 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_165 ;
goto V_7;
}
V_273 = 0 ;
V_3 -> V_64 . V_65 = V_74 ;
memset ( V_3 -> V_64 . V_60 , 0 , V_3 -> V_148 ) ;
V_11 = F_4 ( V_3 , V_8 ) ;
V_3 -> V_64 . V_8 = V_8 ;
V_11 -> V_15 = V_42 ;
V_11 -> V_302 = V_280 ;
V_11 -> V_305 =
F_79 ( V_3 -> V_301 [ V_280 ] ) ;
V_11 -> V_304 =
F_80 ( V_3 -> V_300 [ V_280 ] ) ;
for ( V_77 = 0 ; V_77 < V_298 ; V_77 ++ )
V_11 -> V_306 [ V_77 ] =
F_79 ( V_3 -> V_297 [ V_280 ] [ V_77 ] ) ;
V_11 -> V_146 = 0 ;
V_11 -> V_145 = 0 ;
F_46 ( & V_3 -> V_64 . V_75 ) ;
F_49 ( V_3 , V_8 ) ;
V_155 = F_53 ( & V_3 -> V_64 . V_75 ,
V_202 * V_203 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_67 ) ) {
F_37 ( V_45 L_41 , V_3 -> V_46 ,
V_107 ) ;
F_56 ( V_11 ,
sizeof( T_19 ) / 4 ) ;
if ( ! ( V_3 -> V_64 . V_65 & V_113 ) )
V_105 = 1 ;
goto V_205;
}
if ( ( V_3 -> V_64 . V_65 & V_69 ) == 0 ) {
F_37 ( V_45 L_58 ,
V_3 -> V_46 , V_107 ) ;
V_273 = - V_167 ;
goto V_7;
}
V_10 = V_3 -> V_64 . V_60 ;
V_153 = F_5 ( V_10 -> V_47 ) & V_206 ;
if ( V_153 == V_307 ) {
V_3 -> V_109 [ V_280 ] |=
V_110 ;
F_35 ( V_3 , F_6 ( V_45 L_59 ,
V_3 -> V_46 , V_107 ) ) ;
} else {
F_6 ( V_45
L_60 ,
V_3 -> V_46 , V_107 ,
V_153 , F_7 ( V_10 -> V_48 ) ) ;
V_273 = - V_167 ;
}
V_205:
if ( V_105 )
F_59 ( V_3 , V_215 ,
V_216 ) ;
V_7:
V_3 -> V_64 . V_65 = V_66 ;
return V_273 ;
}
static long
F_87 ( struct V_2 * V_3 , unsigned V_330 ,
void T_12 * V_217 )
{
struct V_331 V_332 ;
struct V_331 T_12 * V_261 ;
struct V_123 V_124 ;
if ( F_88 ( V_330 ) != sizeof( struct V_331 ) )
return - V_173 ;
V_261 = (struct V_331 T_12 * ) V_217 ;
if ( F_42 ( & V_332 , ( char T_12 * ) V_217 , sizeof( V_332 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_262 . V_98 = V_332 . V_262 . V_98 ;
V_124 . V_262 . V_220 = V_332 . V_262 . V_220 ;
V_124 . V_262 . V_263 = V_332 . V_262 . V_263 ;
V_124 . V_154 = V_332 . V_154 ;
V_124 . V_147 = V_332 . V_147 ;
V_124 . V_176 = V_332 . V_176 ;
V_124 . V_175 = V_332 . V_175 ;
V_124 . V_211 = V_332 . V_211 ;
V_124 . V_171 = V_332 . V_171 ;
V_124 . V_149 = F_89 ( V_332 . V_149 ) ;
V_124 . V_209 = F_89 ( V_332 . V_209 ) ;
V_124 . V_181 = F_89 ( V_332 . V_181 ) ;
V_124 . V_212 = F_89 ( V_332 . V_212 ) ;
return F_38 ( V_3 , V_124 , & V_261 -> V_150 ) ;
}
static long
F_90 ( struct V_117 * V_117 , unsigned int V_330 , void T_12 * V_217 ,
T_6 V_333 , T_1 V_100 )
{
struct V_2 * V_3 ;
struct V_264 V_334 ;
enum V_335 V_336 ;
long V_163 = - V_173 ;
if ( F_42 ( & V_334 , ( char T_12 * ) V_217 ,
sizeof( struct V_264 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
return - V_167 ;
}
if ( F_21 ( V_334 . V_98 ,
& V_3 , V_100 ) == - 1 || ! V_3 )
return - V_337 ;
F_91 ( & V_3 -> V_338 ) ;
if ( V_3 -> V_268 || V_3 -> V_269 ||
V_3 -> V_270 || V_3 -> V_339 ) {
V_163 = - V_165 ;
goto V_340;
}
V_336 = ( V_117 -> V_341 & V_342 ) ? V_343 : V_344 ;
if ( V_336 == V_343 ) {
if ( ! F_92 ( & V_3 -> V_64 . V_345 ) ) {
V_163 = - V_165 ;
goto V_340;
}
} else if ( F_93 ( & V_3 -> V_64 . V_345 ) ) {
V_163 = - V_346 ;
goto V_340;
}
switch ( V_330 ) {
case V_347 :
if ( F_88 ( V_330 ) == sizeof( struct V_218 ) )
V_163 = F_62 ( V_3 , V_217 ) ;
break;
#ifdef F_94
case V_348 :
#endif
case V_349 :
{
struct V_123 T_12 * V_261 ;
struct V_123 V_124 ;
#ifdef F_94
if ( V_333 ) {
V_163 = F_87 ( V_3 , V_330 , V_217 ) ;
break;
}
#endif
if ( F_42 ( & V_124 , V_217 , sizeof( V_124 ) ) ) {
F_37 ( L_31 ,
__FILE__ , __LINE__ , V_107 ) ;
V_163 = - V_167 ;
break;
}
if ( F_88 ( V_330 ) == sizeof( struct V_123 ) ) {
V_261 = V_217 ;
V_163 = F_38 ( V_3 , V_124 , & V_261 -> V_150 ) ;
}
break;
}
case V_350 :
if ( F_88 ( V_330 ) == sizeof( struct V_252 ) )
V_163 = F_66 ( V_3 , V_217 ) ;
break;
case V_351 :
if ( F_88 ( V_330 ) == sizeof( struct V_256 ) )
V_163 = F_67 ( V_3 , V_217 ) ;
break;
case V_352 :
V_163 = F_70 ( V_3 , V_217 ) ;
break;
case V_353 :
if ( F_88 ( V_330 ) == sizeof( struct V_266 ) )
V_163 = F_71 ( V_3 , V_217 ) ;
break;
case V_354 :
if ( F_88 ( V_330 ) == sizeof( struct V_271 ) )
V_163 = F_75 ( V_3 , V_217 ) ;
break;
case V_355 :
if ( F_88 ( V_330 ) == sizeof( struct V_288 ) )
V_163 = F_82 ( V_3 , V_217 ) ;
break;
case V_356 :
if ( F_88 ( V_330 ) == sizeof( struct V_313 ) )
V_163 = F_83 ( V_3 , V_217 ) ;
break;
case V_357 :
if ( F_88 ( V_330 ) == sizeof( struct V_314 ) )
V_163 = F_84 ( V_3 , V_217 ) ;
break;
case V_358 :
if ( F_88 ( V_330 ) == sizeof( struct V_321 ) )
V_163 = F_85 ( V_3 , V_217 ) ;
break;
case V_359 :
if ( F_88 ( V_330 ) == sizeof( struct V_322 ) )
V_163 = F_86 ( V_3 , V_217 ) ;
break;
default:
F_35 ( V_3 , F_6 ( V_45
L_79 , V_3 -> V_46 , V_330 ) ) ;
break;
}
F_95 ( & V_3 -> V_64 . V_345 ) ;
V_340:
F_95 ( & V_3 -> V_338 ) ;
return V_163 ;
}
long
F_96 ( struct V_117 * V_117 , unsigned int V_330 , unsigned long V_217 )
{
long V_163 ;
V_163 = F_90 ( V_117 , V_330 , ( void T_12 * ) V_217 , 0 , V_246 ) ;
return V_163 ;
}
long
F_97 ( struct V_117 * V_117 , unsigned int V_330 , unsigned long V_217 )
{
long V_163 ;
V_163 = F_90 ( V_117 , V_330 , ( void T_12 * ) V_217 , 0 , V_240 ) ;
return V_163 ;
}
long
F_98 ( struct V_117 * V_117 , unsigned V_330 , unsigned long V_217 )
{
long V_163 ;
V_163 = F_90 ( V_117 , V_330 , ( void T_12 * ) V_217 , 1 , V_246 ) ;
return V_163 ;
}
long
F_99 ( struct V_117 * V_117 , unsigned V_330 , unsigned long V_217 )
{
long V_163 ;
V_163 = F_90 ( V_117 , V_330 , ( void T_12 * ) V_217 , 1 , V_240 ) ;
return V_163 ;
}
static T_23
F_100 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_80 ,
( V_3 -> V_178 . V_236 . V_237 & 0xFF000000 ) >> 24 ,
( V_3 -> V_178 . V_236 . V_237 & 0x00FF0000 ) >> 16 ,
( V_3 -> V_178 . V_236 . V_237 & 0x0000FF00 ) >> 8 ,
V_3 -> V_178 . V_236 . V_237 & 0x000000FF ) ;
}
static T_23
F_103 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
T_7 V_367 = F_7 ( V_3 -> V_250 . V_251 ) ;
return snprintf ( V_363 , V_366 , L_80 ,
( V_367 & 0xFF000000 ) >> 24 ,
( V_367 & 0x00FF0000 ) >> 16 ,
( V_367 & 0x0000FF00 ) >> 8 ,
V_367 & 0x000000FF ) ;
}
static T_23
F_104 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_81 ,
V_3 -> V_178 . V_368 , V_3 -> V_178 . V_369 >> 8 ) ;
}
static T_23
F_105 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , 16 , L_51 , V_3 -> V_370 . V_371 ) ;
}
static T_23
F_106 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_82 ,
F_7 ( V_3 -> V_372 . V_373 . V_237 ) ) ;
}
static T_23
F_107 ( struct V_141 * V_360 , struct V_361
* V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_82 ,
F_7 ( V_3 -> V_372 . V_374 . V_237 ) ) ;
}
static T_23
F_108 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , 16 , L_51 , V_3 -> V_370 . V_375 ) ;
}
static T_23
F_109 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , 16 , L_51 , V_3 -> V_370 . V_376 ) ;
}
static T_23
F_110 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , 16 , L_51 , V_3 -> V_370 . V_377 ) ;
}
static T_23
F_111 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_83 , V_3 -> V_378 ) ;
}
static T_23
F_112 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_83 , V_3 -> V_379 ) ;
}
static T_23
F_113 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_83 , V_3 -> V_178 . V_380 ) ;
}
static T_23
F_114 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_84 ,
( unsigned long long ) V_3 -> V_381 . V_53 ) ;
}
static T_23
F_115 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_82 , V_3 -> V_13 ) ;
}
static T_23
F_116 ( struct V_141 * V_360 , struct V_361 * V_362 ,
const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
int V_383 = 0 ;
if ( sscanf ( V_363 , L_85 , & V_383 ) != 1 )
return - V_173 ;
V_3 -> V_13 = V_383 ;
F_6 ( V_45 L_86 , V_3 -> V_46 ,
V_3 -> V_13 ) ;
return strlen ( V_363 ) ;
}
static T_23
F_117 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_87 , V_3 -> V_384 ) ;
}
static T_23
F_118 ( struct V_141 * V_360 , struct V_361 * V_362 ,
const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
int V_383 = 0 ;
if ( sscanf ( V_363 , L_88 , & V_383 ) != 1 )
return - V_173 ;
V_3 -> V_384 = V_383 ;
F_6 ( V_45 L_89 , V_3 -> V_46 ,
V_3 -> V_384 ) ;
return strlen ( V_363 ) ;
}
static T_23
F_119 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
return snprintf ( V_363 , V_366 , L_87 , V_3 -> V_385 ) ;
}
static T_23
F_120 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
T_6 V_386 ;
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
if ( ( V_3 -> V_178 . V_282 &
V_387 ) && V_3 -> V_388 )
V_386 = V_3 -> V_386 ;
else
V_386 = 1 ;
return snprintf ( V_363 , V_366 , L_87 , V_386 ) ;
}
static T_23
F_121 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
T_24 * V_389 = NULL ;
T_25 V_10 ;
T_1 V_390 = 0 ;
T_1 V_153 ;
int V_63 ;
T_23 V_273 = 0 ;
if ( ! V_3 -> V_241 ) {
F_37 ( V_45 L_90
L_91 , V_3 -> V_46 , V_107 ) ;
goto V_7;
}
F_91 ( & V_3 -> V_338 ) ;
if ( V_3 -> V_269 || V_3 -> V_339 ) {
F_95 ( & V_3 -> V_338 ) ;
return 0 ;
}
V_63 = F_122 ( T_24 , V_391 ) + ( sizeof( T_1 ) * 36 ) ;
V_389 = F_41 ( V_63 , V_169 ) ;
if ( ! V_389 ) {
F_37 ( V_45 L_92
L_93 , V_3 -> V_46 , V_107 , V_63 ) ;
goto V_7;
}
if ( F_123 ( V_3 , & V_10 , V_389 , V_63 ) !=
0 ) {
F_37 ( V_45
L_94 , V_3 -> V_46 ,
V_107 ) ;
goto V_7;
}
V_153 = F_5 ( V_10 . V_47 ) & V_206 ;
if ( V_153 != V_307 ) {
F_37 ( V_45 L_95
L_96 , V_3 -> V_46 , V_107 , V_153 ) ;
goto V_7;
}
if ( V_389 -> V_392 < 25 ) {
F_37 ( V_45 L_97
L_98 , V_3 -> V_46 , V_107 ,
V_389 -> V_392 ) ;
goto V_7;
}
V_390 = F_5 ( V_389 -> V_391 [ 24 ] ) ;
V_273 = snprintf ( V_363 , V_366 , L_87 , ( V_390 & 1 ) ) ;
V_7:
F_61 ( V_389 ) ;
F_95 ( & V_3 -> V_338 ) ;
return V_273 ;
}
static T_23
F_124 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
T_7 V_393 = 0 ;
struct V_394 * V_290 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_107 ) ;
return 0 ;
}
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_107 ) ;
return 0 ;
}
V_290 = (struct V_394 * )
V_3 -> V_295 [ V_281 ] ;
if ( ( F_7 ( V_290 -> V_395 ) == 0x00000000 ||
F_7 ( V_290 -> V_395 ) == 0x01000000 ||
F_7 ( V_290 -> V_395 ) == 0x01010000 ) &&
F_7 ( V_290 -> V_396 ) == 0x4742444c )
V_393 = F_7 ( V_290 -> V_397 ) ;
V_3 -> V_398 = V_393 ;
return snprintf ( V_363 , V_366 , L_87 , V_393 ) ;
}
static T_23
F_125 ( struct V_141 * V_360 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
void * V_290 ;
T_7 V_393 ;
if ( ! V_3 -> V_295 [ V_281 ] ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_107 ) ;
return 0 ;
}
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) {
F_37 ( V_45
L_99 ,
V_3 -> V_46 , V_107 ) ;
return 0 ;
}
if ( V_3 -> V_399 > V_3 -> V_398 )
return 0 ;
V_393 = V_3 -> V_398 - V_3 -> V_399 ;
V_393 = ( V_393 >= V_366 ) ? ( V_366 - 1 ) : V_393 ;
V_290 = V_3 -> V_295 [ 0 ] + V_3 -> V_399 ;
memcpy ( V_363 , V_290 , V_393 ) ;
return V_393 ;
}
static T_23
F_126 ( struct V_141 * V_360 , struct V_361 * V_362 ,
const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
int V_383 = 0 ;
if ( sscanf ( V_363 , L_88 , & V_383 ) != 1 )
return - V_173 ;
V_3 -> V_399 = V_383 ;
return strlen ( V_363 ) ;
}
static T_23
F_127 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
if ( ( ! V_3 -> V_295 [ V_281 ] ) ||
( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 ) )
return snprintf ( V_363 , V_366 , L_100 ) ;
else if ( ( V_3 -> V_109 [ V_281 ] &
V_111 ) )
return snprintf ( V_363 , V_366 , L_101 ) ;
else
return snprintf ( V_363 , V_366 , L_102 ) ;
}
static T_23
F_128 ( struct V_141 * V_360 ,
struct V_361 * V_362 , const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
char V_400 [ 10 ] = L_103 ;
struct V_288 V_289 ;
T_6 V_105 = 0 ;
if ( V_3 -> V_268 || V_3 -> V_339 ||
V_3 -> V_269 || V_3 -> V_270 )
return - V_401 ;
if ( sscanf ( V_363 , L_104 , V_400 ) != 1 )
return - V_173 ;
if ( ! strcmp ( V_400 , L_105 ) ) {
if ( ( V_3 -> V_295 [ V_281 ] ) &&
( V_3 -> V_109 [ V_281 ] &
V_110 ) &&
( ( V_3 -> V_109 [ V_281 ] &
V_111 ) == 0 ) )
goto V_7;
memset ( & V_289 , 0 , sizeof( struct V_288 ) ) ;
F_6 ( V_45 L_106 ,
V_3 -> V_46 ) ;
V_289 . V_280 = V_281 ;
V_289 . V_294 = ( 1024 * 1024 ) ;
V_289 . V_296 = 0x7075900 ;
V_3 -> V_109 [ V_281 ] = 0 ;
F_77 ( V_3 , & V_289 ) ;
} else if ( ! strcmp ( V_400 , L_107 ) ) {
if ( ! V_3 -> V_295 [ V_281 ] )
goto V_7;
if ( ( V_3 -> V_109 [ V_281 ] &
V_110 ) == 0 )
goto V_7;
if ( ( V_3 -> V_109 [ V_281 ] &
V_111 ) )
goto V_7;
F_6 ( V_45 L_108 ,
V_3 -> V_46 ) ;
F_26 ( V_3 , V_281 ,
& V_105 ) ;
}
V_7:
return strlen ( V_363 ) ;
}
static T_23
F_129 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_273 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_273 = sizeof( struct V_403 ) ;
memcpy ( V_363 , & V_3 -> V_309 , V_273 ) ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_273 ;
}
static T_23
F_130 ( struct V_141 * V_360 ,
struct V_361 * V_362 , const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_273 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_273 = F_131 ( sizeof( struct V_403 ) , V_382 ) ;
memset ( & V_3 -> V_309 , 0 ,
sizeof( struct V_403 ) ) ;
memcpy ( & V_3 -> V_309 , V_363 , V_273 ) ;
V_3 -> V_309 . V_310 |=
( V_311 + V_312 ) ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_273 ;
}
static T_23
F_132 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_273 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_273 = sizeof( struct V_404 ) ;
memcpy ( V_363 , & V_3 -> V_405 , V_273 ) ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_273 ;
}
static T_23
F_133 ( struct V_141 * V_360 ,
struct V_361 * V_362 , const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_404 ) , V_382 ) ;
memset ( & V_3 -> V_405 , 0 ,
sizeof( struct V_404 ) ) ;
memcpy ( & V_3 -> V_405 , V_363 , V_63 ) ;
if ( V_3 -> V_405 . V_406 > V_407 )
V_3 -> V_405 . V_406 = V_407 ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_63 ;
}
static T_23
F_134 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_273 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_273 = sizeof( struct V_408 ) ;
memcpy ( V_363 , & V_3 -> V_409 , V_273 ) ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_273 ;
}
static T_23
F_135 ( struct V_141 * V_360 ,
struct V_361 * V_362 , const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_408 ) , V_382 ) ;
memset ( & V_3 -> V_409 , 0 ,
sizeof( struct V_404 ) ) ;
memcpy ( & V_3 -> V_409 , V_363 , V_63 ) ;
if ( V_3 -> V_409 . V_406 > V_407 )
V_3 -> V_409 . V_406 = V_407 ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_63 ;
}
static T_23
F_136 ( struct V_141 * V_360 ,
struct V_361 * V_362 , char * V_363 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_273 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_273 = sizeof( struct V_410 ) ;
memcpy ( V_363 , & V_3 -> V_411 , V_273 ) ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_273 ;
}
static T_23
F_137 ( struct V_141 * V_360 ,
struct V_361 * V_362 , const char * V_363 , T_15 V_382 )
{
struct V_364 * V_365 = F_101 ( V_360 ) ;
struct V_2 * V_3 = F_102 ( V_365 ) ;
unsigned long V_50 ;
T_23 V_63 ;
F_8 ( & V_3 -> V_402 , V_50 ) ;
V_63 = F_131 ( sizeof( struct V_410 ) , V_382 ) ;
memset ( & V_3 -> V_411 , 0 ,
sizeof( V_3 -> V_411 ) ) ;
memcpy ( & V_3 -> V_411 , V_363 , V_63 ) ;
if ( V_3 -> V_411 . V_406 > V_407 )
V_3 -> V_411 . V_406 = V_407 ;
F_10 ( & V_3 -> V_402 , V_50 ) ;
return V_63 ;
}
static T_23
F_138 ( struct V_141 * V_412 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_413 * V_414 = F_139 ( V_412 ) ;
struct V_129 * V_415 = V_414 -> V_142 ;
return snprintf ( V_363 , V_366 , L_84 ,
( unsigned long long ) V_415 -> V_143 -> V_53 ) ;
}
static T_23
F_140 ( struct V_141 * V_412 , struct V_361 * V_362 ,
char * V_363 )
{
struct V_413 * V_414 = F_139 ( V_412 ) ;
struct V_129 * V_415 = V_414 -> V_142 ;
return snprintf ( V_363 , V_366 , L_109 ,
V_415 -> V_143 -> V_4 ) ;
}
void
F_141 ( T_26 V_416 )
{
V_95 = NULL ;
if ( V_416 != 1 )
if ( F_142 ( & V_417 ) < 0 )
F_37 ( L_110 ,
V_418 , V_419 ) ;
if ( V_416 != 2 )
if ( F_142 ( & V_420 ) < 0 )
F_37 ( L_110 ,
V_421 , V_422 ) ;
F_143 ( & V_94 ) ;
}
void
F_144 ( T_26 V_416 )
{
struct V_2 * V_3 ;
int V_77 ;
F_2 (ioc, &mpt3sas_ioc_list, list) {
for ( V_77 = 0 ; V_77 < V_108 ; V_77 ++ ) {
if ( ! V_3 -> V_295 [ V_77 ] )
continue;
if ( ! ( V_3 -> V_109 [ V_77 ] &
V_110 ) )
continue;
if ( ( V_3 -> V_109 [ V_77 ] &
V_111 ) )
continue;
F_60 ( V_3 -> V_180 , V_3 -> V_301 [ V_77 ] ,
V_3 -> V_295 [ V_77 ] , V_3 -> V_300 [ V_77 ] ) ;
V_3 -> V_295 [ V_77 ] = NULL ;
V_3 -> V_109 [ V_77 ] = 0 ;
}
F_61 ( V_3 -> V_79 ) ;
}
if ( V_416 != 1 )
F_145 ( & V_417 ) ;
if ( V_416 != 2 )
F_145 ( & V_420 ) ;
}
