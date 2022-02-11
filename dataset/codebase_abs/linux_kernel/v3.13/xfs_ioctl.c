int
F_1 (
unsigned int V_1 ,
T_1 * V_2 )
{
int V_3 ;
T_2 V_4 ;
struct V_5 * V_5 ;
struct V_6 V_7 = { NULL } ;
struct V_8 V_8 ;
int error ;
struct V_9 * V_10 ;
if ( V_1 == V_11 ) {
V_7 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_7 . V_12 )
return - V_13 ;
V_5 = F_3 ( V_7 . V_12 ) ;
} else {
error = F_4 ( ( const char V_14 * ) V_2 -> V_8 , & V_8 ) ;
if ( error )
return error ;
V_5 = V_8 . V_15 -> V_16 ;
}
V_10 = F_5 ( V_5 ) ;
error = - V_17 ;
if ( V_5 -> V_18 -> V_19 != V_20 )
goto V_21;
error = - V_13 ;
if ( ! F_6 ( V_5 -> V_22 ) &&
! F_7 ( V_5 -> V_22 ) &&
! F_8 ( V_5 -> V_22 ) )
goto V_21;
memcpy ( & V_4 . V_23 , V_10 -> V_24 -> V_25 , sizeof( V_26 ) ) ;
if ( V_1 == V_27 ) {
memset ( & V_4 . V_28 , 0 , sizeof( V_4 . V_28 ) ) ;
V_3 = sizeof( V_26 ) ;
} else {
int V_29 ;
V_29 = F_9 ( V_10 ) ;
V_4 . V_28 . V_30 = sizeof( V_31 ) -
sizeof( V_4 . V_28 . V_30 ) ;
V_4 . V_28 . V_32 = 0 ;
V_4 . V_28 . V_33 = V_10 -> V_34 . V_35 ;
V_4 . V_28 . V_36 = V_10 -> V_37 ;
F_10 ( V_10 , V_29 ) ;
V_3 = F_11 ( V_4 ) ;
}
error = - V_38 ;
if ( F_12 ( V_2 -> V_39 , & V_4 , V_3 ) ||
F_12 ( V_2 -> V_40 , & V_3 , sizeof( V_41 ) ) )
goto V_21;
error = 0 ;
V_21:
if ( V_1 == V_11 )
F_13 ( V_7 ) ;
else
F_14 ( & V_8 ) ;
return error ;
}
STATIC int
F_15 (
void * V_42 ,
struct V_15 * V_15 )
{
return 1 ;
}
struct V_15 *
F_16 (
struct V_12 * V_43 ,
void V_14 * V_44 ,
T_3 V_45 )
{
T_2 V_4 ;
struct V_46 V_47 ;
if ( ! F_7 ( F_3 ( V_43 ) -> V_22 ) )
return F_17 ( - V_48 ) ;
if ( V_45 != sizeof( T_2 ) )
return F_17 ( - V_17 ) ;
if ( F_18 ( & V_4 , V_44 , V_45 ) )
return F_17 ( - V_38 ) ;
if ( V_4 . V_28 . V_30 !=
sizeof( V_4 . V_28 ) - sizeof( V_4 . V_28 . V_30 ) )
return F_17 ( - V_17 ) ;
memset ( & V_47 , 0 , sizeof( struct V_47 ) ) ;
V_47 . V_49 = V_4 . V_28 . V_36 ;
V_47 . V_50 = V_4 . V_28 . V_33 ;
return F_19 ( V_43 -> V_51 . V_52 , (struct V_47 * ) & V_47 , 3 ,
V_53 | V_54 ,
F_15 , NULL ) ;
}
STATIC struct V_15 *
F_20 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
return F_16 ( V_43 , V_2 -> V_55 , V_2 -> V_56 ) ;
}
int
F_21 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
const struct V_57 * V_57 = F_22 () ;
int error ;
int V_6 ;
int V_58 ;
struct V_12 * V_59 ;
struct V_5 * V_5 ;
struct V_15 * V_15 ;
T_4 V_60 ;
struct V_8 V_8 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
V_15 = F_20 ( V_43 , V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
V_5 = V_15 -> V_16 ;
if ( ! ( F_6 ( V_5 -> V_22 ) || F_7 ( V_5 -> V_22 ) ) ) {
error = - F_24 ( V_62 ) ;
goto V_63;
}
#if V_64 != 32
V_2 -> V_65 |= V_66 ;
#endif
V_58 = V_2 -> V_65 ;
V_60 = F_27 ( V_58 ) ;
if ( ( ! ( V_58 & V_67 ) || ( V_58 & V_68 ) ) &&
( V_60 & V_69 ) && F_28 ( V_5 ) ) {
error = - F_24 ( V_62 ) ;
goto V_63;
}
if ( ( V_60 & V_69 ) && F_29 ( V_5 ) ) {
error = - F_24 ( V_70 ) ;
goto V_63;
}
if ( F_7 ( V_5 -> V_22 ) && ( V_60 & V_69 ) ) {
error = - F_24 ( V_71 ) ;
goto V_63;
}
V_6 = F_30 ( 0 ) ;
if ( V_6 < 0 ) {
error = V_6 ;
goto V_63;
}
V_8 . V_52 = V_43 -> V_51 . V_52 ;
V_8 . V_15 = V_15 ;
V_59 = F_31 ( & V_8 , V_2 -> V_65 , V_57 ) ;
F_32 ( V_15 ) ;
if ( F_25 ( V_59 ) ) {
F_33 ( V_6 ) ;
return F_26 ( V_59 ) ;
}
if ( F_6 ( V_5 -> V_22 ) ) {
V_59 -> V_72 |= V_73 ;
V_59 -> V_74 |= V_75 ;
}
F_34 ( V_6 , V_59 ) ;
return V_6 ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
STATIC int
F_35 (
char V_14 * V_76 ,
int V_77 ,
const char * V_78 )
{
int V_79 ;
V_79 = F_26 ( V_78 ) ;
if ( F_25 ( V_78 ) )
goto V_80;
V_79 = strlen ( V_78 ) ;
if ( V_79 > ( unsigned ) V_77 )
V_79 = V_77 ;
if ( F_12 ( V_76 , V_78 , V_79 ) )
V_79 = - V_38 ;
V_80:
return V_79 ;
}
int
F_36 (
struct V_12 * V_43 ,
T_1 * V_2 )
{
struct V_15 * V_15 ;
T_5 V_81 ;
void * V_78 ;
int error ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
V_15 = F_20 ( V_43 , V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
if ( ! F_8 ( V_15 -> V_16 -> V_22 ) ) {
error = - F_24 ( V_17 ) ;
goto V_63;
}
if ( F_18 ( & V_81 , V_2 -> V_40 , sizeof( T_5 ) ) ) {
error = - F_24 ( V_38 ) ;
goto V_63;
}
V_78 = F_37 ( V_82 + 1 , V_83 ) ;
if ( ! V_78 ) {
error = - F_24 ( V_84 ) ;
goto V_63;
}
error = - F_38 ( F_5 ( V_15 -> V_16 ) , V_78 ) ;
if ( error )
goto V_85;
error = F_35 ( V_2 -> V_39 , V_81 , V_78 ) ;
if ( error )
goto V_85;
V_85:
F_39 ( V_78 ) ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
int
F_40 (
T_6 * V_10 ,
T_7 V_86 ,
T_8 V_87 )
{
T_9 * V_88 = V_10 -> V_24 ;
T_10 * V_89 ;
int error ;
if ( ! F_23 ( V_61 ) )
return F_24 ( V_62 ) ;
if ( F_41 ( V_88 ) )
return F_24 ( V_90 ) ;
V_89 = F_42 ( V_88 , V_91 ) ;
error = F_43 ( V_89 , & F_44 ( V_88 ) -> V_92 , 0 , 0 ) ;
if ( error ) {
F_45 ( V_89 , 0 ) ;
return error ;
}
F_46 ( V_10 , V_93 ) ;
F_47 ( V_89 , V_10 , V_93 ) ;
V_10 -> V_34 . V_94 = V_86 ;
V_10 -> V_34 . V_95 = V_87 ;
F_48 ( V_89 , V_10 , V_96 ) ;
error = F_49 ( V_89 , 0 ) ;
return error ;
}
STATIC int
F_50 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error ;
struct V_98 V_99 ;
T_11 V_100 ;
struct V_15 * V_15 ;
if ( ! F_23 ( V_101 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_100 , V_97 , sizeof( T_11 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_43 ) ;
if ( error )
return error ;
V_15 = F_20 ( V_43 , & V_100 . V_2 ) ;
if ( F_25 ( V_15 ) ) {
F_52 ( V_43 ) ;
return F_26 ( V_15 ) ;
}
if ( F_29 ( V_15 -> V_16 ) || F_28 ( V_15 -> V_16 ) ) {
error = - F_24 ( V_62 ) ;
goto V_80;
}
if ( F_18 ( & V_99 , V_100 . V_102 , sizeof( V_99 ) ) ) {
error = - F_24 ( V_38 ) ;
goto V_80;
}
error = - F_40 ( F_5 ( V_15 -> V_16 ) , V_99 . V_103 ,
V_99 . V_104 ) ;
V_80:
F_52 ( V_43 ) ;
F_32 ( V_15 ) ;
return error ;
}
STATIC int
F_53 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error = - V_84 ;
T_12 * V_105 ;
T_13 V_106 ;
struct V_15 * V_15 ;
char * V_107 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_106 , V_97 , sizeof( T_13 ) ) )
return - F_24 ( V_38 ) ;
if ( V_106 . V_77 < sizeof( struct V_108 ) ||
V_106 . V_77 > V_109 )
return - F_24 ( V_17 ) ;
if ( V_106 . V_110 & ~ ( V_111 | V_112 ) )
return - F_24 ( V_17 ) ;
V_15 = F_20 ( V_43 , & V_106 . V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
V_107 = F_54 ( V_106 . V_77 , V_113 ) ;
if ( ! V_107 )
goto V_63;
V_105 = ( T_12 * ) & V_106 . V_114 ;
error = - F_55 ( F_5 ( V_15 -> V_16 ) , V_107 , V_106 . V_77 ,
V_106 . V_110 , V_105 ) ;
if ( error )
goto V_85;
if ( F_12 ( V_106 . V_76 , V_107 , V_106 . V_77 ) )
error = - V_38 ;
V_85:
F_56 ( V_107 ) ;
V_63:
F_32 ( V_15 ) ;
return error ;
}
int
F_57 (
struct V_5 * V_5 ,
unsigned char * V_115 ,
unsigned char V_14 * V_116 ,
T_14 * V_79 ,
T_14 V_110 )
{
unsigned char * V_107 ;
int error = V_38 ;
if ( * V_79 > V_117 )
return V_17 ;
V_107 = F_54 ( * V_79 , V_113 ) ;
if ( ! V_107 )
return V_84 ;
error = F_58 ( F_5 ( V_5 ) , V_115 , V_107 , ( int * ) V_79 , V_110 ) ;
if ( error )
goto V_85;
if ( F_12 ( V_116 , V_107 , * V_79 ) )
error = V_38 ;
V_85:
F_56 ( V_107 ) ;
return error ;
}
int
F_59 (
struct V_5 * V_5 ,
unsigned char * V_115 ,
const unsigned char V_14 * V_116 ,
T_14 V_79 ,
T_14 V_110 )
{
unsigned char * V_107 ;
int error = V_38 ;
if ( F_29 ( V_5 ) || F_28 ( V_5 ) )
return V_62 ;
if ( V_79 > V_117 )
return V_17 ;
V_107 = F_60 ( V_116 , V_79 ) ;
if ( F_25 ( V_107 ) )
return F_26 ( V_107 ) ;
error = F_61 ( F_5 ( V_5 ) , V_115 , V_107 , V_79 , V_110 ) ;
return error ;
}
int
F_62 (
struct V_5 * V_5 ,
unsigned char * V_115 ,
T_14 V_110 )
{
if ( F_29 ( V_5 ) || F_28 ( V_5 ) )
return V_62 ;
return F_63 ( F_5 ( V_5 ) , V_115 , V_110 ) ;
}
STATIC int
F_64 (
struct V_12 * V_43 ,
void V_14 * V_97 )
{
int error ;
T_15 * V_118 ;
T_16 V_119 ;
struct V_15 * V_15 ;
unsigned int V_120 , V_121 ;
unsigned char * V_122 ;
if ( ! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( F_18 ( & V_119 , V_97 , sizeof( T_16 ) ) )
return - F_24 ( V_38 ) ;
if ( V_119 . V_123 >= V_124 / sizeof( T_15 ) )
return - V_125 ;
V_15 = F_20 ( V_43 , & V_119 . V_2 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
error = V_125 ;
V_121 = V_119 . V_123 * sizeof( T_15 ) ;
if ( ! V_121 || V_121 > 16 * V_126 )
goto V_63;
V_118 = F_60 ( V_119 . V_118 , V_121 ) ;
if ( F_25 ( V_118 ) ) {
error = F_26 ( V_118 ) ;
goto V_63;
}
V_122 = F_37 ( V_127 , V_83 ) ;
if ( ! V_122 )
goto V_128;
error = 0 ;
for ( V_120 = 0 ; V_120 < V_119 . V_123 ; V_120 ++ ) {
V_118 [ V_120 ] . V_129 = F_65 ( ( char * ) V_122 ,
V_118 [ V_120 ] . V_130 , V_127 ) ;
if ( V_118 [ V_120 ] . V_129 == 0 || V_118 [ V_120 ] . V_129 == V_127 )
error = - V_131 ;
if ( V_118 [ V_120 ] . V_129 < 0 )
break;
switch ( V_118 [ V_120 ] . V_132 ) {
case V_133 :
V_118 [ V_120 ] . V_129 = F_57 (
V_15 -> V_16 , V_122 ,
V_118 [ V_120 ] . V_134 , & V_118 [ V_120 ] . V_135 ,
V_118 [ V_120 ] . V_136 ) ;
break;
case V_137 :
V_118 [ V_120 ] . V_129 = F_51 ( V_43 ) ;
if ( V_118 [ V_120 ] . V_129 )
break;
V_118 [ V_120 ] . V_129 = F_59 (
V_15 -> V_16 , V_122 ,
V_118 [ V_120 ] . V_134 , V_118 [ V_120 ] . V_135 ,
V_118 [ V_120 ] . V_136 ) ;
F_52 ( V_43 ) ;
break;
case V_138 :
V_118 [ V_120 ] . V_129 = F_51 ( V_43 ) ;
if ( V_118 [ V_120 ] . V_129 )
break;
V_118 [ V_120 ] . V_129 = F_62 (
V_15 -> V_16 , V_122 ,
V_118 [ V_120 ] . V_136 ) ;
F_52 ( V_43 ) ;
break;
default:
V_118 [ V_120 ] . V_129 = V_17 ;
}
}
if ( F_12 ( V_119 . V_118 , V_118 , V_121 ) )
error = F_24 ( V_38 ) ;
F_39 ( V_122 ) ;
V_128:
F_39 ( V_118 ) ;
V_63:
F_32 ( V_15 ) ;
return - error ;
}
int
F_66 (
struct V_9 * V_10 ,
struct V_5 * V_5 ,
struct V_12 * V_59 ,
int V_139 ,
unsigned int V_1 ,
T_17 * V_140 )
{
struct V_141 * V_88 = V_10 -> V_24 ;
struct V_142 * V_89 ;
struct V_143 V_143 ;
bool V_144 = false ;
bool V_145 = false ;
int error ;
if ( ! F_67 ( & V_10 -> V_24 -> V_146 ) &&
! F_23 ( V_61 ) )
return - F_24 ( V_62 ) ;
if ( V_5 -> V_147 & ( V_148 | V_149 ) )
return - F_24 ( V_62 ) ;
if ( ! ( V_59 -> V_74 & V_69 ) )
return - F_24 ( V_13 ) ;
if ( ! F_6 ( V_5 -> V_22 ) )
return - F_24 ( V_17 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
F_46 ( V_10 , V_150 ) ;
switch ( V_140 -> V_151 ) {
case 0 :
break;
case 1 :
V_140 -> V_152 += V_59 -> V_153 ;
break;
case 2 :
V_140 -> V_152 += F_68 ( V_10 ) ;
break;
default:
error = F_24 ( V_17 ) ;
goto V_154;
}
switch ( V_1 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
if ( V_140 -> V_160 <= 0 ) {
error = F_24 ( V_17 ) ;
goto V_154;
}
break;
default:
V_140 -> V_160 = 0 ;
break;
}
if ( V_140 -> V_152 < 0 ||
V_140 -> V_152 > V_88 -> V_161 -> V_162 ||
V_140 -> V_152 + V_140 -> V_160 < 0 ||
V_140 -> V_152 + V_140 -> V_160 >= V_88 -> V_161 -> V_162 ) {
error = F_24 ( V_17 ) ;
goto V_154;
}
switch ( V_1 ) {
case V_155 :
error = F_69 ( V_10 , V_140 -> V_152 , V_140 -> V_160 ) ;
if ( ! error )
V_144 = true ;
break;
case V_156 :
case V_157 :
error = F_70 ( V_10 , V_140 -> V_152 , V_140 -> V_160 ,
V_163 ) ;
if ( ! error )
V_144 = true ;
break;
case V_158 :
case V_159 :
error = F_71 ( V_10 , V_140 -> V_152 , V_140 -> V_160 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
if ( V_140 -> V_152 > F_68 ( V_10 ) ) {
error = F_70 ( V_10 , F_68 ( V_10 ) ,
V_140 -> V_152 - F_68 ( V_10 ) , 0 ) ;
if ( error )
goto V_154;
}
V_143 . V_168 = V_169 ;
V_143 . V_170 = V_140 -> V_152 ;
error = F_72 ( V_10 , & V_143 ) ;
if ( ! error )
V_145 = true ;
break;
default:
ASSERT ( 0 ) ;
error = F_24 ( V_17 ) ;
}
if ( error )
goto V_154;
V_89 = F_42 ( V_88 , V_171 ) ;
error = F_43 ( V_89 , & F_44 ( V_88 ) -> V_172 , 0 , 0 ) ;
if ( error ) {
F_45 ( V_89 , 0 ) ;
goto V_154;
}
F_46 ( V_10 , V_93 ) ;
F_47 ( V_89 , V_10 , V_93 ) ;
if ( ! ( V_139 & V_173 ) ) {
V_10 -> V_34 . V_174 &= ~ V_175 ;
if ( V_10 -> V_34 . V_174 & V_176 )
V_10 -> V_34 . V_174 &= ~ V_177 ;
F_73 ( V_89 , V_10 , V_178 | V_179 ) ;
}
if ( V_144 )
V_10 -> V_34 . V_180 |= V_181 ;
else if ( V_145 )
V_10 -> V_34 . V_180 &= ~ V_181 ;
F_48 ( V_89 , V_10 , V_96 ) ;
if ( V_59 -> V_72 & V_182 )
F_74 ( V_89 ) ;
error = F_49 ( V_89 , 0 ) ;
V_154:
F_75 ( V_10 , V_150 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_76 (
T_9 * V_88 ,
unsigned int V_1 ,
void V_14 * V_97 )
{
T_18 V_183 ;
int V_184 ;
T_19 V_185 ;
int V_186 ;
int error ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_41 ( V_88 ) )
return - F_24 ( V_90 ) ;
if ( F_18 ( & V_183 , V_97 , sizeof( T_18 ) ) )
return - F_24 ( V_38 ) ;
if ( F_18 ( & V_185 , V_183 . V_187 , sizeof( V_188 ) ) )
return - F_24 ( V_38 ) ;
if ( ( V_184 = V_183 . V_189 ) <= 0 )
return - F_24 ( V_17 ) ;
if ( V_183 . V_190 == NULL )
return - F_24 ( V_17 ) ;
if ( V_1 == V_191 )
error = F_77 ( V_88 , & V_185 , & V_184 ,
V_183 . V_190 , V_192 ) ;
else if ( V_1 == V_193 )
error = F_78 ( V_88 , & V_185 ,
V_183 . V_190 , & V_186 ) ;
else
error = F_79 ( V_88 , & V_185 , & V_184 , V_194 ,
sizeof( V_195 ) , V_183 . V_190 ,
& V_186 ) ;
if ( error )
return - error ;
if ( V_183 . V_196 != NULL ) {
if ( F_12 ( V_183 . V_187 , & V_185 ,
sizeof( T_19 ) ) )
return - F_24 ( V_38 ) ;
if ( F_12 ( V_183 . V_196 , & V_184 , sizeof( V_184 ) ) )
return - F_24 ( V_38 ) ;
}
return 0 ;
}
STATIC int
F_80 (
T_9 * V_88 ,
void V_14 * V_97 )
{
T_20 V_197 ;
int error ;
error = F_81 ( V_88 , & V_197 , 3 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_197 , sizeof( V_198 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC int
F_82 (
T_9 * V_88 ,
void V_14 * V_97 )
{
T_20 V_197 ;
int error ;
error = F_81 ( V_88 , & V_197 , 4 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_197 , sizeof( V_197 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC unsigned int
F_83 (
unsigned int V_110 ,
unsigned int V_199 )
{
unsigned int V_200 = V_199 ;
if ( V_110 & V_201 )
V_200 |= V_202 ;
else
V_200 &= ~ V_202 ;
if ( V_110 & V_203 )
V_200 |= V_204 ;
else
V_200 &= ~ V_204 ;
if ( V_110 & V_205 )
V_200 |= V_206 ;
else
V_200 &= ~ V_206 ;
if ( V_110 & V_207 )
V_200 |= V_208 ;
else
V_200 &= ~ V_208 ;
if ( V_110 & V_209 )
V_200 |= V_210 ;
else
V_200 &= ~ V_210 ;
return V_200 ;
}
STATIC unsigned int
F_84 (
T_21 V_180 )
{
unsigned int V_110 = 0 ;
if ( V_180 & V_211 )
V_110 |= V_201 ;
if ( V_180 & V_212 )
V_110 |= V_203 ;
if ( V_180 & V_213 )
V_110 |= V_205 ;
if ( V_180 & V_214 )
V_110 |= V_207 ;
if ( V_180 & V_215 )
V_110 |= V_209 ;
return V_110 ;
}
STATIC int
F_85 (
T_6 * V_10 ,
int V_216 ,
void V_14 * V_97 )
{
struct V_217 V_218 ;
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
F_46 ( V_10 , V_219 ) ;
V_218 . V_220 = F_86 ( V_10 ) ;
V_218 . V_221 = V_10 -> V_34 . V_222 << V_10 -> V_24 -> V_146 . V_223 ;
V_218 . V_224 = F_87 ( V_10 ) ;
if ( V_216 ) {
if ( V_10 -> V_225 ) {
if ( V_10 -> V_225 -> V_226 & V_227 )
V_218 . V_228 = V_10 -> V_225 -> V_229 /
sizeof( V_230 ) ;
else
V_218 . V_228 = V_10 -> V_34 . V_231 ;
} else
V_218 . V_228 = 0 ;
} else {
if ( V_10 -> V_232 . V_226 & V_227 )
V_218 . V_228 = V_10 -> V_232 . V_229 /
sizeof( V_230 ) ;
else
V_218 . V_228 = V_10 -> V_34 . V_233 ;
}
F_75 ( V_10 , V_219 ) ;
if ( F_12 ( V_97 , & V_218 , sizeof( V_218 ) ) )
return - V_38 ;
return 0 ;
}
STATIC void
F_88 (
struct V_9 * V_10 ,
unsigned int V_200 )
{
unsigned int V_180 ;
V_180 = ( V_10 -> V_34 . V_180 & V_181 ) ;
if ( V_200 & V_202 )
V_180 |= V_211 ;
if ( V_200 & V_204 )
V_180 |= V_212 ;
if ( V_200 & V_206 )
V_180 |= V_213 ;
if ( V_200 & V_208 )
V_180 |= V_214 ;
if ( V_200 & V_210 )
V_180 |= V_215 ;
if ( V_200 & V_234 )
V_180 |= V_235 ;
if ( V_200 & V_236 )
V_180 |= V_237 ;
if ( V_200 & V_238 )
V_180 |= V_239 ;
if ( F_7 ( V_10 -> V_34 . V_174 ) ) {
if ( V_200 & V_240 )
V_180 |= V_241 ;
if ( V_200 & V_242 )
V_180 |= V_243 ;
if ( V_200 & V_244 )
V_180 |= V_245 ;
} else if ( F_6 ( V_10 -> V_34 . V_174 ) ) {
if ( V_200 & V_246 )
V_180 |= V_247 ;
if ( V_200 & V_248 )
V_180 |= V_249 ;
}
V_10 -> V_34 . V_180 = V_180 ;
}
STATIC void
F_89 (
struct V_9 * V_10 )
{
struct V_5 * V_5 = F_90 ( V_10 ) ;
unsigned int V_200 = F_86 ( V_10 ) ;
if ( V_200 & V_202 )
V_5 -> V_147 |= V_148 ;
else
V_5 -> V_147 &= ~ V_148 ;
if ( V_200 & V_204 )
V_5 -> V_147 |= V_149 ;
else
V_5 -> V_147 &= ~ V_149 ;
if ( V_200 & V_206 )
V_5 -> V_147 |= V_250 ;
else
V_5 -> V_147 &= ~ V_250 ;
if ( V_200 & V_208 )
V_5 -> V_147 |= V_251 ;
else
V_5 -> V_147 &= ~ V_251 ;
}
STATIC int
F_91 (
T_6 * V_10 ,
struct V_217 * V_218 ,
int V_252 )
{
struct V_141 * V_88 = V_10 -> V_24 ;
struct V_142 * V_89 ;
unsigned int V_253 = 0 ;
struct V_254 * V_255 = NULL ;
struct V_254 * V_256 = NULL ;
struct V_254 * V_257 = NULL ;
int V_258 ;
F_92 ( V_10 ) ;
if ( V_88 -> V_259 & V_260 )
return F_24 ( V_261 ) ;
if ( F_41 ( V_88 ) )
return F_24 ( V_90 ) ;
if ( ( V_252 & V_262 ) && ( V_218 -> V_224 > ( T_21 ) - 1 ) &&
! F_93 ( & V_10 -> V_24 -> V_146 ) )
return F_24 ( V_17 ) ;
if ( F_94 ( V_88 ) && ( V_252 & V_262 ) ) {
V_258 = F_95 ( V_10 , V_10 -> V_34 . V_263 ,
V_10 -> V_34 . V_264 , V_218 -> V_224 ,
V_265 , & V_255 , NULL , & V_256 ) ;
if ( V_258 )
return V_258 ;
}
V_89 = F_42 ( V_88 , V_266 ) ;
V_258 = F_43 ( V_89 , & F_44 ( V_88 ) -> V_92 , 0 , 0 ) ;
if ( V_258 )
goto V_267;
V_253 = V_93 ;
F_46 ( V_10 , V_253 ) ;
if ( ! F_96 ( F_90 ( V_10 ) ) ) {
V_258 = F_24 ( V_62 ) ;
goto V_267;
}
if ( V_252 & V_262 ) {
if ( F_97 () != & V_268 ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
if ( F_98 ( V_88 ) &&
F_99 ( V_88 ) &&
F_87 ( V_10 ) != V_218 -> V_224 ) {
ASSERT ( V_89 ) ;
V_258 = F_100 ( V_89 , V_10 , V_255 , NULL ,
V_256 , F_23 ( V_269 ) ?
V_270 : 0 ) ;
if ( V_258 )
goto V_267;
}
}
if ( V_252 & V_271 ) {
if ( V_10 -> V_34 . V_233 &&
( ( V_10 -> V_34 . V_222 << V_88 -> V_146 . V_223 ) !=
V_218 -> V_221 ) ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
if ( V_218 -> V_221 != 0 ) {
T_22 V_121 ;
T_23 V_272 ;
V_272 = F_101 ( V_88 , V_218 -> V_221 ) ;
if ( V_272 > V_273 ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
if ( F_102 ( V_10 ) ||
( ( V_252 & V_274 ) &&
( V_218 -> V_220 & V_246 ) ) ) {
V_121 = V_88 -> V_146 . V_275 <<
V_88 -> V_146 . V_223 ;
} else {
V_121 = V_88 -> V_146 . V_276 ;
if ( V_272 > V_88 -> V_146 . V_277 / 2 ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
}
if ( V_218 -> V_221 % V_121 ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
}
}
if ( V_252 & V_274 ) {
if ( ( V_10 -> V_34 . V_233 || V_10 -> V_278 ) &&
( F_102 ( V_10 ) ) !=
( V_218 -> V_220 & V_246 ) ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
if ( ( V_218 -> V_220 & V_246 ) ) {
if ( ( V_88 -> V_146 . V_279 == 0 ) ||
( V_88 -> V_146 . V_275 == 0 ) ||
( V_10 -> V_34 . V_222 % V_88 -> V_146 . V_275 ) ) {
V_258 = F_24 ( V_17 ) ;
goto V_267;
}
}
if ( ( V_10 -> V_34 . V_180 &
( V_211 | V_212 ) ||
( V_218 -> V_220 &
( V_202 | V_204 ) ) ) &&
! F_23 ( V_280 ) ) {
V_258 = F_24 ( V_62 ) ;
goto V_267;
}
}
F_47 ( V_89 , V_10 , 0 ) ;
if ( V_252 & V_262 ) {
if ( ( V_10 -> V_34 . V_174 & ( V_175 | V_177 ) ) &&
! F_103 ( F_90 ( V_10 ) , V_281 ) )
V_10 -> V_34 . V_174 &= ~ ( V_175 | V_177 ) ;
if ( F_87 ( V_10 ) != V_218 -> V_224 ) {
if ( F_98 ( V_88 ) && F_99 ( V_88 ) ) {
V_257 = F_104 ( V_89 , V_10 ,
& V_10 -> V_282 , V_256 ) ;
}
F_105 ( V_10 , V_218 -> V_224 ) ;
if ( V_10 -> V_34 . V_283 == 1 )
F_106 ( V_89 , V_10 ) ;
}
}
if ( V_252 & V_271 )
V_10 -> V_34 . V_222 = V_218 -> V_221 >> V_88 -> V_146 . V_223 ;
if ( V_252 & V_274 ) {
F_88 ( V_10 , V_218 -> V_220 ) ;
F_89 ( V_10 ) ;
}
F_73 ( V_89 , V_10 , V_179 ) ;
F_48 ( V_89 , V_10 , V_96 ) ;
F_107 ( V_284 ) ;
if ( V_88 -> V_259 & V_285 )
F_74 ( V_89 ) ;
V_258 = F_49 ( V_89 , 0 ) ;
F_75 ( V_10 , V_253 ) ;
F_108 ( V_257 ) ;
F_108 ( V_255 ) ;
F_108 ( V_256 ) ;
return V_258 ;
V_267:
F_108 ( V_255 ) ;
F_108 ( V_256 ) ;
F_45 ( V_89 , 0 ) ;
if ( V_253 )
F_75 ( V_10 , V_253 ) ;
return V_258 ;
}
STATIC int
F_109 (
T_6 * V_10 ,
struct V_12 * V_59 ,
void V_14 * V_97 )
{
struct V_217 V_218 ;
unsigned int V_252 ;
int error ;
if ( F_18 ( & V_218 , V_97 , sizeof( V_218 ) ) )
return - V_38 ;
V_252 = V_274 | V_271 | V_262 ;
if ( V_59 -> V_72 & ( V_286 | V_287 ) )
V_252 |= V_288 ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_91 ( V_10 , & V_218 , V_252 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_110 (
T_6 * V_10 ,
void V_14 * V_97 )
{
unsigned int V_110 ;
V_110 = F_84 ( V_10 -> V_34 . V_180 ) ;
if ( F_12 ( V_97 , & V_110 , sizeof( V_110 ) ) )
return - V_38 ;
return 0 ;
}
STATIC int
F_111 (
T_6 * V_10 ,
struct V_12 * V_59 ,
void V_14 * V_97 )
{
struct V_217 V_218 ;
unsigned int V_110 ;
unsigned int V_252 ;
int error ;
if ( F_18 ( & V_110 , V_97 , sizeof( V_110 ) ) )
return - V_38 ;
if ( V_110 & ~ ( V_201 | V_203 | \
V_207 | V_209 | \
V_205 ) )
return - V_289 ;
V_252 = V_274 ;
if ( V_59 -> V_72 & ( V_286 | V_287 ) )
V_252 |= V_288 ;
V_218 . V_220 = F_83 ( V_110 , F_86 ( V_10 ) ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_91 ( V_10 , & V_218 , V_252 ) ;
F_52 ( V_59 ) ;
return - error ;
}
STATIC int
F_112 ( void * * V_290 , struct V_291 * V_292 , int * V_293 )
{
struct V_294 V_14 * V_295 = * V_290 ;
if ( F_12 ( V_295 , V_292 , sizeof( struct V_294 ) ) )
return F_24 ( V_38 ) ;
* V_290 += sizeof( struct V_294 ) ;
return 0 ;
}
STATIC int
F_113 (
struct V_9 * V_10 ,
int V_139 ,
unsigned int V_1 ,
void V_14 * V_97 )
{
struct V_291 V_296 ;
int error ;
if ( F_18 ( & V_296 , V_97 , sizeof( struct V_291 ) ) )
return - F_24 ( V_38 ) ;
if ( V_296 . V_297 < 2 )
return - F_24 ( V_17 ) ;
V_296 . V_298 = ( V_1 == V_299 ? V_300 : 0 ) ;
if ( V_139 & V_173 )
V_296 . V_298 |= V_301 ;
error = F_114 ( V_10 , & V_296 , F_112 ,
(struct V_294 * ) V_97 + 1 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_296 , sizeof( struct V_294 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
STATIC int
F_115 ( void * * V_290 , struct V_291 * V_292 , int * V_293 )
{
struct V_291 V_14 * V_295 = * V_290 ;
if ( F_12 ( V_295 , V_292 , sizeof( struct V_291 ) ) )
return F_24 ( V_38 ) ;
* V_290 += sizeof( struct V_291 ) ;
return 0 ;
}
STATIC int
F_116 (
struct V_9 * V_10 ,
void V_14 * V_97 )
{
struct V_291 V_296 ;
int error ;
if ( F_18 ( & V_296 , V_97 , sizeof( V_296 ) ) )
return - F_24 ( V_38 ) ;
if ( V_296 . V_297 < 2 )
return - F_24 ( V_17 ) ;
if ( V_296 . V_298 & ( ~ V_302 ) )
return - F_24 ( V_17 ) ;
error = F_114 ( V_10 , & V_296 , F_115 ,
(struct V_291 * ) V_97 + 1 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_296 , sizeof( struct V_291 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
int
F_117 (
T_24 * V_303 )
{
T_6 * V_10 , * V_304 ;
struct V_6 V_7 , V_305 ;
int error = 0 ;
V_7 = F_2 ( ( int ) V_303 -> V_306 ) ;
if ( ! V_7 . V_12 ) {
error = F_24 ( V_17 ) ;
goto V_80;
}
if ( ! ( V_7 . V_12 -> V_74 & V_69 ) ||
! ( V_7 . V_12 -> V_74 & V_307 ) ||
( V_7 . V_12 -> V_72 & V_67 ) ) {
error = F_24 ( V_13 ) ;
goto V_308;
}
V_305 = F_2 ( ( int ) V_303 -> V_309 ) ;
if ( ! V_305 . V_12 ) {
error = F_24 ( V_17 ) ;
goto V_308;
}
if ( ! ( V_305 . V_12 -> V_74 & V_69 ) ||
! ( V_305 . V_12 -> V_74 & V_307 ) ||
( V_305 . V_12 -> V_72 & V_67 ) ) {
error = F_24 ( V_13 ) ;
goto V_310;
}
if ( F_118 ( F_3 ( V_7 . V_12 ) ) ||
F_118 ( F_3 ( V_305 . V_12 ) ) ) {
error = F_24 ( V_17 ) ;
goto V_310;
}
V_10 = F_5 ( F_3 ( V_7 . V_12 ) ) ;
V_304 = F_5 ( F_3 ( V_305 . V_12 ) ) ;
if ( V_10 -> V_24 != V_304 -> V_24 ) {
error = F_24 ( V_17 ) ;
goto V_310;
}
if ( V_10 -> V_37 == V_304 -> V_37 ) {
error = F_24 ( V_17 ) ;
goto V_310;
}
if ( F_41 ( V_10 -> V_24 ) ) {
error = F_24 ( V_90 ) ;
goto V_310;
}
error = F_119 ( V_10 , V_304 , V_303 ) ;
V_310:
F_13 ( V_305 ) ;
V_308:
F_13 ( V_7 ) ;
V_80:
return error ;
}
long
F_120 (
struct V_12 * V_59 ,
unsigned int V_1 ,
unsigned long V_311 )
{
struct V_5 * V_5 = F_3 ( V_59 ) ;
struct V_9 * V_10 = F_5 ( V_5 ) ;
struct V_141 * V_88 = V_10 -> V_24 ;
void V_14 * V_97 = ( void V_14 * ) V_311 ;
int V_139 = 0 ;
int error ;
if ( V_59 -> V_74 & V_75 )
V_139 |= V_173 ;
F_121 ( V_10 ) ;
switch ( V_1 ) {
case V_312 :
return F_122 ( V_88 , V_97 ) ;
case V_164 :
case V_166 :
case V_156 :
case V_158 :
case V_165 :
case V_167 :
case V_157 :
case V_159 :
case V_155 : {
T_17 V_140 ;
if ( F_18 ( & V_140 , V_97 , sizeof( V_140 ) ) )
return - F_24 ( V_38 ) ;
return F_66 ( V_10 , V_5 , V_59 , V_139 , V_1 , & V_140 ) ;
}
case V_313 : {
struct V_314 V_315 ;
T_25 * V_316 =
F_102 ( V_10 ) ?
V_88 -> V_317 : V_88 -> V_318 ;
V_315 . V_319 = V_315 . V_320 = 1 << V_316 -> V_321 ;
V_315 . V_322 = V_124 & ~ ( V_315 . V_320 - 1 ) ;
if ( F_12 ( V_97 , & V_315 , sizeof( V_315 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_193 :
case V_323 :
case V_191 :
return F_76 ( V_88 , V_1 , V_97 ) ;
case V_324 :
return F_80 ( V_88 , V_97 ) ;
case V_325 :
return F_82 ( V_88 , V_97 ) ;
case V_326 :
return F_123 ( V_5 -> V_327 , ( int V_14 * ) V_97 ) ;
case V_328 :
return F_85 ( V_10 , 0 , V_97 ) ;
case V_329 :
return F_85 ( V_10 , 1 , V_97 ) ;
case V_330 :
return F_109 ( V_10 , V_59 , V_97 ) ;
case V_331 :
return F_110 ( V_10 , V_97 ) ;
case V_332 :
return F_111 ( V_10 , V_59 , V_97 ) ;
case V_333 : {
struct V_98 V_334 ;
if ( F_18 ( & V_334 , V_97 , sizeof( V_334 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_40 ( V_10 , V_334 . V_103 ,
V_334 . V_104 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_335 :
case V_299 :
return F_113 ( V_10 , V_139 , V_1 , V_97 ) ;
case V_336 :
return F_116 ( V_10 , V_97 ) ;
case V_11 :
case V_337 :
case V_27 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( V_2 ) ) )
return - F_24 ( V_38 ) ;
return F_1 ( V_1 , & V_2 ) ;
}
case V_338 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( T_1 ) ) )
return - F_24 ( V_38 ) ;
return F_21 ( V_59 , & V_2 ) ;
}
case V_339 :
return F_50 ( V_59 , V_97 ) ;
case V_340 : {
T_1 V_2 ;
if ( F_18 ( & V_2 , V_97 , sizeof( T_1 ) ) )
return - F_24 ( V_38 ) ;
return F_36 ( V_59 , & V_2 ) ;
}
case V_341 :
return F_53 ( V_59 , V_97 ) ;
case V_342 :
return F_64 ( V_59 , V_97 ) ;
case V_343 : {
struct V_344 V_303 ;
if ( F_18 ( & V_303 , V_97 , sizeof( T_24 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_117 ( & V_303 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_345 : {
T_26 V_80 ;
error = F_124 ( V_88 , & V_80 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_80 , sizeof( V_80 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_346 : {
T_27 V_347 ;
T_28 V_348 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( V_88 -> V_259 & V_260 )
return - F_24 ( V_261 ) ;
if ( F_18 ( & V_347 , V_97 , sizeof( V_347 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
V_348 = V_347 . V_349 ;
error = F_125 ( V_88 , & V_348 , & V_347 ) ;
F_52 ( V_59 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_347 , sizeof( V_347 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_350 : {
T_27 V_80 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
error = F_125 ( V_88 , NULL , & V_80 ) ;
if ( error )
return - error ;
if ( F_12 ( V_97 , & V_80 , sizeof( V_80 ) ) )
return - F_24 ( V_38 ) ;
return 0 ;
}
case V_351 : {
T_29 V_348 ;
if ( F_18 ( & V_348 , V_97 , sizeof( V_348 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_126 ( V_88 , & V_348 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_352 : {
T_30 V_348 ;
if ( F_18 ( & V_348 , V_97 , sizeof( V_348 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_127 ( V_88 , & V_348 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_353 : {
T_31 V_348 ;
if ( F_18 ( & V_348 , V_97 , sizeof( V_348 ) ) )
return - F_24 ( V_38 ) ;
error = F_51 ( V_59 ) ;
if ( error )
return error ;
error = F_128 ( V_88 , & V_348 ) ;
F_52 ( V_59 ) ;
return - error ;
}
case V_354 : {
T_14 V_348 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_129 ( V_348 , ( T_14 V_14 * ) V_97 ) )
return - F_24 ( V_38 ) ;
error = F_130 ( V_88 , V_348 ) ;
return - error ;
}
case V_355 : {
T_32 V_348 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( F_18 ( & V_348 , V_97 , sizeof( V_348 ) ) )
return - F_24 ( V_38 ) ;
error = F_131 ( V_348 . V_356 , V_88 ) ;
return - error ;
}
case V_357 :
if ( ! F_23 ( V_61 ) )
return - V_62 ;
error = F_132 ( V_88 , 1 ) ;
return - error ;
case V_358 : {
struct V_359 V_360 ;
struct V_361 V_362 ;
if ( ! F_23 ( V_61 ) )
return - V_62 ;
if ( V_88 -> V_259 & V_260 )
return - F_24 ( V_261 ) ;
if ( F_18 ( & V_360 , V_97 , sizeof( V_360 ) ) )
return - F_24 ( V_38 ) ;
error = F_133 ( & V_360 , & V_362 ) ;
if ( error )
return - error ;
return - F_134 ( V_88 , & V_362 ) ;
}
default:
return - V_363 ;
}
}
