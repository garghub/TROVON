static void * F_1 ( int V_1 , int V_2 )
{
union V_3 * V_4 ;
F_2 ( V_4 , union V_3 * , V_2 ) ;
if ( ! V_4 )
return F_3 ( - V_5 ) ;
V_4 -> V_6 . V_1 = V_1 ;
V_4 -> V_6 . V_7 = V_8 -> V_7 ;
V_4 -> V_6 . V_9 = F_4 ( V_8 ) ;
V_4 -> V_6 . V_10 = F_5 () ;
return ( void * ) V_4 ;
}
int F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_19 ) ;
F_8 ( V_20 ) ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error )
* V_14 = V_16 -> V_21 . V_22 ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_12 ( struct V_11 * V_12 , struct V_13 * V_23 ,
struct V_24 * V_25 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_26 ) ;
F_8 ( V_27 ) ;
V_4 -> V_28 . V_22 = * V_23 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error )
* V_25 = V_16 -> V_28 . V_25 ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_13 ( struct V_11 * V_12 , struct V_13 * V_23 ,
struct V_24 * V_29 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_30 ) ;
F_8 ( V_31 ) ;
V_4 -> V_32 . V_22 = * V_23 ;
V_4 -> V_32 . V_25 = * V_29 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_14 ( struct V_11 * V_12 , struct V_13 * V_23 ,
const char * V_33 , int V_34 , int * type ,
struct V_13 * V_35 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 ;
V_36 = F_15 ( V_37 ) ;
V_17 = F_16 (unsigned int, offset + length +1 , OUTSIZE(lookup)) ;
F_8 ( V_38 ) ;
V_4 -> V_39 . V_22 = * V_23 ;
V_4 -> V_39 . V_33 = V_36 ;
V_4 -> V_39 . V_40 = V_41 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_34 ) ;
* ( ( char * ) V_4 + V_36 + V_34 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error ) {
* V_35 = V_16 -> V_39 . V_22 ;
* type = V_16 -> V_39 . V_42 ;
}
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_17 ( struct V_11 * V_12 , struct V_13 * V_23 , int V_40 ,
T_1 V_10 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_43 ) ;
F_8 ( V_44 ) ;
V_4 -> V_6 . V_10 = V_10 ;
V_4 -> V_45 . V_22 = * V_23 ;
V_4 -> V_45 . V_40 = V_40 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_18 ( struct V_11 * V_12 , struct V_13 * V_23 ,
int V_40 , struct V_46 * * V_47 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_48 ) ;
F_8 ( V_49 ) ;
V_4 -> V_50 . V_22 = * V_23 ;
V_4 -> V_50 . V_40 = V_40 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error )
* V_47 = V_16 -> V_50 . V_47 ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_19 ( struct V_11 * V_12 , struct V_13 * V_51 ,
const char * V_33 , int V_34 ,
struct V_13 * V_52 , struct V_24 * V_53 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 ;
V_36 = F_15 ( V_54 ) ;
V_17 = F_16 (unsigned int, offset + length + 1 , OUTSIZE(mkdir)) ;
F_8 ( V_55 ) ;
V_4 -> V_56 . V_22 = * V_51 ;
V_4 -> V_56 . V_25 = * V_53 ;
V_4 -> V_56 . V_33 = V_36 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_34 ) ;
* ( ( char * ) V_4 + V_36 + V_34 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error ) {
* V_53 = V_16 -> V_56 . V_25 ;
* V_52 = V_16 -> V_56 . V_22 ;
}
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_20 ( struct V_11 * V_12 , struct V_13 * V_57 ,
struct V_13 * V_58 , T_2 V_59 ,
T_2 V_60 , const char * V_61 ,
const char * V_62 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 , V_63 ;
V_36 = F_15 ( rename ) ;
V_17 = F_16 (unsigned int, offset + new_length + old_length + 8 ,
OUTSIZE(rename)) ;
F_8 ( V_64 ) ;
V_4 -> V_65 . V_66 = * V_57 ;
V_4 -> V_65 . V_67 = * V_58 ;
V_4 -> V_65 . V_68 = V_36 ;
V_63 = ( V_59 & ~ 0x3 ) + 4 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_61 , V_59 ) ;
* ( ( char * ) V_4 + V_36 + V_59 ) = '\0' ;
V_36 += V_63 ;
V_4 -> V_65 . V_69 = V_36 ;
V_63 = ( V_60 & ~ 0x3 ) + 4 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_62 , V_60 ) ;
* ( ( char * ) V_4 + V_36 + V_60 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_21 ( struct V_11 * V_12 , struct V_13 * V_51 ,
const char * V_33 , int V_34 , int V_70 , int V_71 ,
struct V_13 * V_52 , struct V_24 * V_53 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 ;
V_36 = F_15 ( V_72 ) ;
V_17 = F_16 (unsigned int, offset + length + 1 , OUTSIZE(create)) ;
F_8 ( V_73 ) ;
V_4 -> V_74 . V_22 = * V_51 ;
V_4 -> V_74 . V_25 . V_75 = V_71 ;
V_4 -> V_74 . V_70 = V_70 ;
V_4 -> V_74 . V_71 = V_71 ;
V_4 -> V_74 . V_33 = V_36 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_34 ) ;
* ( ( char * ) V_4 + V_36 + V_34 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error ) {
* V_53 = V_16 -> V_74 . V_25 ;
* V_52 = V_16 -> V_74 . V_22 ;
}
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_22 ( struct V_11 * V_12 , struct V_13 * V_51 ,
const char * V_33 , int V_34 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 ;
V_36 = F_15 ( V_76 ) ;
V_17 = F_16 (unsigned int, offset + length + 1 , OUTSIZE(rmdir)) ;
F_8 ( V_77 ) ;
V_4 -> V_78 . V_22 = * V_51 ;
V_4 -> V_78 . V_33 = V_36 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_34 ) ;
* ( ( char * ) V_4 + V_36 + V_34 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_23 ( struct V_11 * V_12 , struct V_13 * V_51 ,
const char * V_33 , int V_34 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int error = 0 , V_17 , V_18 , V_36 ;
V_36 = F_15 ( remove ) ;
V_17 = F_16 (unsigned int, offset + length + 1 , OUTSIZE(remove)) ;
F_8 ( V_79 ) ;
V_4 -> V_80 . V_22 = * V_51 ;
V_4 -> V_80 . V_33 = V_36 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_34 ) ;
* ( ( char * ) V_4 + V_36 + V_34 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_24 ( struct V_11 * V_12 , struct V_13 * V_23 ,
char * V_81 , int * V_34 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_82 ;
char * V_83 ;
V_17 = F_16 (unsigned int,
INSIZE(readlink), OUTSIZE(readlink)+ *length + 1 ) ;
F_8 ( V_84 ) ;
V_4 -> V_85 . V_22 = * V_23 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error ) {
V_82 = V_16 -> V_85 . V_86 ;
if ( V_82 > * V_34 )
V_82 = * V_34 ;
* V_34 = V_82 ;
V_83 = ( char * ) V_16 + ( long ) V_16 -> V_85 . V_87 ;
memcpy ( V_81 , V_83 , V_82 ) ;
* ( V_81 + V_82 ) = '\0' ;
}
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_25 ( struct V_11 * V_12 , struct V_13 * V_23 ,
struct V_13 * V_51 , const char * V_33 , int V_88 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 ;
V_36 = F_15 ( V_89 ) ;
V_17 = F_16 (unsigned int, offset + len + 1 , OUTSIZE(link)) ;
F_8 ( V_90 ) ;
V_4 -> V_91 . V_66 = * V_23 ;
V_4 -> V_91 . V_67 = * V_51 ;
V_4 -> V_91 . V_92 = V_36 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_88 ) ;
* ( ( char * ) V_4 + V_36 + V_88 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_26 ( struct V_11 * V_12 , struct V_13 * V_23 ,
const char * V_33 , int V_88 ,
const char * V_93 , int V_94 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_36 , V_63 ;
V_36 = F_15 ( V_95 ) ;
V_17 = F_16 (unsigned int, offset + len + symlen + 8 , OUTSIZE(symlink)) ;
F_8 ( V_96 ) ;
V_4 -> V_97 . V_22 = * V_23 ;
V_4 -> V_97 . V_68 = V_36 ;
V_63 = ( V_94 & ~ 0x3 ) + 4 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_93 , V_94 ) ;
* ( ( char * ) V_4 + V_36 + V_94 ) = '\0' ;
V_36 += V_63 ;
V_4 -> V_97 . V_92 = V_36 ;
V_63 = ( V_88 & ~ 0x3 ) + 4 ;
memcpy ( ( char * ) ( V_4 ) + V_36 , V_33 , V_88 ) ;
* ( ( char * ) V_4 + V_36 + V_88 ) = '\0' ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_27 ( struct V_11 * V_12 , struct V_13 * V_23 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_98 ) ;
F_8 ( V_99 ) ;
V_4 -> V_100 . V_22 = * V_23 ;
error = F_9 ( F_10 ( V_12 ) , sizeof( union V_3 ) ,
& V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_28 ( struct V_11 * V_12 , struct V_13 * V_23 , int V_101 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_7 ( V_102 ) ;
F_8 ( V_103 ) ;
V_4 -> V_104 . V_22 = * V_23 ;
V_4 -> V_104 . V_40 = V_101 ;
error = F_9 ( F_10 ( V_12 ) , V_17 , & V_18 , V_4 ) ;
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_29 ( struct V_11 * V_12 , struct V_13 * V_23 ,
unsigned int V_105 , struct V_106 * V_87 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
int V_107 ;
V_17 = V_108 ;
F_8 ( V_109 ) ;
if ( V_87 -> V_110 . V_111 > V_112 ) {
error = - V_113 ;
goto exit;
}
if ( V_87 -> V_110 . V_114 > V_112 ) {
error = - V_113 ;
goto exit;
}
V_4 -> V_115 . V_22 = * V_23 ;
V_4 -> V_115 . V_105 = ( V_105 & ~ ( V_116 << 16 ) ) ;
V_107 = ( ( V_105 >> 16 ) & V_116 ) - sizeof( char * ) - sizeof( int ) ;
V_4 -> V_115 . V_105 |= ( V_107 & V_116 ) << 16 ;
V_4 -> V_115 . V_88 = V_87 -> V_110 . V_111 ;
V_4 -> V_115 . V_87 = ( char * ) ( F_15 ( V_117 ) ) ;
if ( F_30 ( ( char * ) V_4 + ( long ) V_4 -> V_115 . V_87 ,
V_87 -> V_110 . V_118 , V_87 -> V_110 . V_111 ) ) {
error = - V_113 ;
goto exit;
}
error = F_9 ( F_10 ( V_12 ) , F_7 ( V_117 ) + V_87 -> V_110 . V_111 ,
& V_18 , V_4 ) ;
if ( error ) {
F_31 ( L_1 ,
error , F_32 ( V_23 ) ) ;
goto exit;
}
if ( V_18 < ( long ) V_16 -> V_115 . V_87 + V_16 -> V_115 . V_88 ) {
error = - V_113 ;
goto exit;
}
if ( V_16 -> V_115 . V_88 > V_87 -> V_110 . V_114 ) {
error = - V_113 ;
goto exit;
}
if ( F_33 ( V_87 -> V_110 . V_119 ,
( char * ) V_16 + ( long ) V_16 -> V_115 . V_87 ,
V_16 -> V_115 . V_88 ) ) {
error = - V_120 ;
goto exit;
}
exit:
F_11 ( V_4 , V_17 ) ;
return error ;
}
int F_34 ( struct V_121 * V_121 , struct V_122 * V_123 )
{
union V_3 * V_4 ;
union V_15 * V_16 ;
int V_17 , V_18 , error ;
V_17 = F_16 (unsigned int, INSIZE(statfs), OUTSIZE(statfs)) ;
F_8 ( V_124 ) ;
error = F_9 ( F_10 ( V_121 -> V_125 ) , V_17 , & V_18 , V_4 ) ;
if ( ! error ) {
V_123 -> V_126 = V_16 -> V_127 . V_128 . V_126 ;
V_123 -> V_129 = V_16 -> V_127 . V_128 . V_129 ;
V_123 -> V_130 = V_16 -> V_127 . V_128 . V_130 ;
V_123 -> V_131 = V_16 -> V_127 . V_128 . V_131 ;
V_123 -> V_132 = V_16 -> V_127 . V_128 . V_132 ;
}
F_11 ( V_4 , V_17 ) ;
return error ;
}
static void F_35 ( T_3 * V_133 )
{
F_36 ( & V_8 -> V_134 -> V_135 ) ;
* V_133 = V_8 -> V_136 ;
F_37 ( & V_8 -> V_136 ) ;
F_38 ( & V_8 -> V_136 , V_137 ) ;
F_38 ( & V_8 -> V_136 , V_138 ) ;
F_38 ( & V_8 -> V_136 , V_139 ) ;
F_39 () ;
F_40 ( & V_8 -> V_134 -> V_135 ) ;
}
static void F_41 ( T_3 * V_133 )
{
F_36 ( & V_8 -> V_134 -> V_135 ) ;
V_8 -> V_136 = * V_133 ;
F_39 () ;
F_40 ( & V_8 -> V_134 -> V_135 ) ;
}
static inline void F_42 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
F_43 ( V_144 , V_8 ) ;
unsigned long V_145 = V_146 + V_147 * V_148 ;
T_3 V_133 ;
int V_136 ;
F_35 ( & V_133 ) ;
V_136 = 1 ;
F_44 ( & V_143 -> V_149 , & V_144 ) ;
for (; ; ) {
if ( F_45 ( V_143 ) )
F_46 ( V_150 ) ;
else
F_46 ( V_151 ) ;
if ( V_143 -> V_152 & ( V_153 | V_154 ) )
break;
if ( V_136 && F_47 ( V_146 , V_145 ) &&
F_45 ( V_143 ) )
{
F_41 ( & V_133 ) ;
V_136 = 0 ;
}
if ( F_48 ( V_8 ) ) {
F_49 ( & V_143 -> V_155 ) ;
break;
}
F_50 ( & V_141 -> V_156 ) ;
if ( V_136 )
F_51 ( V_148 ) ;
else
F_52 () ;
F_53 ( & V_141 -> V_156 ) ;
}
if ( V_136 )
F_41 ( & V_133 ) ;
F_54 ( & V_143 -> V_149 , & V_144 ) ;
F_46 ( V_157 ) ;
}
static int F_9 ( struct V_140 * V_141 ,
int V_158 , int * V_159 ,
union V_3 * V_81 )
{
union V_15 * V_119 ;
union V_3 * V_160 ;
struct V_142 * V_143 = NULL , * V_161 ;
int error ;
F_53 ( & V_141 -> V_156 ) ;
if ( ! V_141 -> V_162 ) {
F_31 ( V_163 L_2 ) ;
error = - V_164 ;
goto exit;
}
V_143 = F_55 ( sizeof( struct V_142 ) , V_165 ) ;
if ( ! V_143 ) {
error = - V_5 ;
goto exit;
}
V_143 -> V_166 = ( void * ) V_81 ;
V_143 -> V_152 = 0 ;
V_143 -> V_167 = V_158 ;
V_143 -> V_168 = * V_159 ? * V_159 : V_158 ;
V_143 -> V_169 = ( (union V_3 * ) V_81 ) -> V_6 . V_1 ;
V_143 -> V_170 = ++ V_141 -> V_171 ;
F_56 ( & V_143 -> V_149 ) ;
( (union V_3 * ) V_81 ) -> V_6 . V_172 = V_143 -> V_170 ;
F_57 ( & V_143 -> V_155 , & V_141 -> V_173 ) ;
F_58 ( & V_141 -> V_174 ) ;
F_42 ( V_141 , V_143 ) ;
if ( V_143 -> V_152 & V_153 ) {
V_119 = (union V_15 * ) V_143 -> V_166 ;
error = - V_119 -> V_175 . V_83 ;
* V_159 = V_143 -> V_168 ;
goto exit;
}
error = - V_176 ;
if ( ( V_143 -> V_152 & V_154 ) || ! F_48 ( V_8 ) ) {
F_31 ( V_177 L_3 ) ;
goto exit;
}
if ( ! ( V_143 -> V_152 & V_178 ) )
goto exit;
if ( ! V_141 -> V_162 ) {
F_31 ( V_179 L_4 ) ;
goto exit;
}
error = - V_5 ;
V_161 = F_55 ( sizeof( struct V_142 ) , V_165 ) ;
if ( ! V_161 ) goto exit;
F_2 ( ( V_161 -> V_166 ) , char * , sizeof( struct V_180 ) ) ;
if ( ! V_161 -> V_166 ) {
F_59 ( V_161 ) ;
goto exit;
}
error = - V_176 ;
V_160 = (union V_3 * ) V_161 -> V_166 ;
V_160 -> V_6 . V_1 = V_181 ;
V_160 -> V_6 . V_172 = V_143 -> V_170 ;
V_161 -> V_152 = V_182 ;
V_161 -> V_169 = V_160 -> V_6 . V_1 ;
V_161 -> V_170 = V_160 -> V_6 . V_172 ;
V_161 -> V_167 = sizeof( struct V_180 ) ;
V_161 -> V_168 = sizeof( struct V_180 ) ;
F_60 ( & ( V_161 -> V_155 ) , & V_141 -> V_173 ) ;
F_58 ( & V_141 -> V_174 ) ;
exit:
F_59 ( V_143 ) ;
F_50 ( & V_141 -> V_156 ) ;
return error ;
}
int F_61 ( struct V_140 * V_141 , int V_1 , union V_15 * V_119 )
{
struct V_183 * V_183 = NULL ;
struct V_13 * V_23 = NULL , * V_52 ;
struct V_11 * V_12 ;
F_53 ( & V_141 -> V_156 ) ;
V_12 = V_141 -> V_184 ;
if ( ! V_12 || ! V_12 -> V_185 )
goto V_186;
switch ( V_1 ) {
case V_187 :
F_62 ( V_12 ) ;
F_63 ( V_12 ) ;
if ( V_12 -> V_185 -> V_188 )
F_64 ( V_12 -> V_185 -> V_188 , V_189 ) ;
break;
case V_190 :
F_62 ( V_12 ) ;
break;
case V_191 :
V_23 = & V_119 -> V_192 . V_13 ;
break;
case V_193 :
V_23 = & V_119 -> V_194 . V_13 ;
break;
case V_195 :
V_23 = & V_119 -> V_196 . V_13 ;
break;
case V_197 :
V_23 = & V_119 -> V_198 . V_199 ;
break;
}
if ( V_23 )
V_183 = F_65 ( V_23 , V_12 ) ;
V_186:
F_50 ( & V_141 -> V_156 ) ;
if ( ! V_183 )
return 0 ;
switch ( V_1 ) {
case V_191 :
F_66 ( V_183 , V_200 ) ;
F_64 ( V_183 , V_201 ) ;
break;
case V_193 :
F_64 ( V_183 , V_201 ) ;
break;
case V_195 :
F_66 ( V_183 , V_200 ) ;
F_64 ( V_183 , V_200 ) ;
F_67 ( V_183 ) ;
break;
case V_197 :
V_52 = & V_119 -> V_198 . V_202 ;
F_68 ( V_183 , V_23 , V_52 ) ;
break;
}
F_69 ( V_183 ) ;
return 0 ;
}
