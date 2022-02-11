int F_1 ( struct V_1 * V_2 )
{
F_2 ( & ( V_2 -> V_3 ) , 0 ) ;
F_2 ( & ( V_2 -> V_4 ) , 0 ) ;
F_3 ( & ( V_2 -> V_5 ) ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned long V_11 ;
if ( V_10 == NULL )
goto exit;
F_5 ( & V_8 -> V_12 , V_11 ) ;
F_6 ( & V_10 -> V_13 , & V_8 -> V_8 ) ;
F_7 ( & V_8 -> V_12 , V_11 ) ;
exit:
return V_6 ;
}
struct V_9 * F_8 ( struct V_7 * V_8 )
{
unsigned long V_11 ;
struct V_9 * V_10 ;
F_5 ( & V_8 -> V_12 , V_11 ) ;
V_10 = F_9 ( & V_8 -> V_8 , struct V_9 , V_13 ) ;
if ( V_10 )
F_10 ( & V_10 -> V_13 ) ;
F_7 ( & V_8 -> V_12 , V_11 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
T_1 V_14 = false ;
if ( ( V_2 -> V_15 -> V_16 . V_17 ) &&
( ! V_2 -> V_15 -> V_18 . V_19 ) ) {
if ( V_9 -> V_20 == F_12 ( V_21 ) ) {
struct V_22 * V_23 = (struct V_22 * ) V_9 -> V_24 ;
if ( V_23 -> V_25 == V_26 )
V_14 = true ;
}
}
if ( V_9 -> V_20 == F_12 ( V_27 ) )
V_14 = true ;
if ( ( ! V_2 -> V_15 -> V_28 && ! V_14 ) ||
! V_2 -> V_29 )
return V_30 ;
return V_6 ;
}
T_2 F_13 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_31 = V_30 ;
struct V_32 * V_15 = V_2 -> V_15 ;
if ( V_9 == NULL )
goto exit;
V_9 -> V_15 = V_15 ;
V_31 = F_11 ( V_2 , V_9 ) ;
if ( V_31 == V_30 ) {
F_14 ( V_9 ) ;
goto exit;
}
V_31 = F_4 ( & V_2 -> V_5 , V_9 ) ;
if ( V_31 == V_6 )
F_15 ( & V_2 -> V_3 ) ;
exit:
return V_31 ;
}
void F_14 ( struct V_9 * V_33 )
{
if ( ( V_33 -> V_20 != V_34 ) && ( V_33 -> V_20 != V_35 ) ) {
F_16 ( V_33 -> V_24 ) ;
}
if ( V_33 -> V_36 != NULL ) {
if ( V_33 -> V_37 != 0 ) {
F_16 ( V_33 -> V_36 ) ;
}
}
F_16 ( V_33 ) ;
}
int F_17 ( void * V_38 )
{
T_1 V_39 ;
struct V_9 * V_33 ;
T_1 (* F_18)( struct V_32 * V_15 , T_1 * V_40 );
void (* F_19)( struct V_32 * V_41 , struct V_9 * V_33 );
struct V_32 * V_15 = V_38 ;
struct V_1 * V_2 = & ( V_15 -> V_42 ) ;
F_20 ( V_43 ) ;
V_2 -> V_29 = true ;
F_15 ( & V_2 -> V_4 ) ;
F_21 ( V_44 , V_45 , ( L_1 ) ) ;
while ( 1 ) {
if ( F_22 ( & V_2 -> V_3 ) == V_30 )
break;
if ( V_15 -> V_46 ||
V_15 -> V_47 ) {
F_23 ( L_2 ,
V_48 , V_15 -> V_46 , V_15 -> V_47 , __LINE__ ) ;
break;
}
V_49:
if ( V_15 -> V_46 ||
V_15 -> V_47 ) {
F_23 ( L_2 ,
V_48 , V_15 -> V_46 , V_15 -> V_47 , __LINE__ ) ;
break;
}
V_33 = F_8 ( & V_2 -> V_5 ) ;
if ( ! V_33 )
continue;
if ( F_11 ( V_2 , V_33 ) == V_30 ) {
V_33 -> V_31 = V_50 ;
} else {
if ( V_33 -> V_20 < F_24 ( V_51 ) ) {
F_18 = V_51 [ V_33 -> V_20 ] . V_52 ;
if ( F_18 ) {
V_39 = F_18 ( V_33 -> V_15 , V_33 -> V_24 ) ;
V_33 -> V_31 = V_39 ;
}
} else {
V_33 -> V_31 = V_53 ;
}
F_18 = NULL ;
}
if ( V_33 -> V_20 < F_24 ( V_54 ) ) {
F_19 = V_54 [ V_33 -> V_20 ] . V_55 ;
if ( F_19 == NULL ) {
F_21 ( V_44 , V_45 , ( L_3 , F_19 , V_33 -> V_20 ) ) ;
F_14 ( V_33 ) ;
} else {
F_19 ( V_33 -> V_15 , V_33 ) ;
}
} else {
F_21 ( V_44 , V_56 , ( L_4 , V_48 , V_33 -> V_20 ) ) ;
F_14 ( V_33 ) ;
}
if ( F_25 ( V_57 ) )
F_26 ( V_57 ) ;
goto V_49;
}
V_2 -> V_29 = false ;
while ( ( V_33 = F_8 ( & V_2 -> V_5 ) ) ) {
F_14 ( V_33 ) ;
}
F_15 ( & V_2 -> V_4 ) ;
F_27 ( NULL , 0 ) ;
}
T_1 F_28 ( struct V_32 * V_15 , struct V_58 * V_59 , int V_60 ,
struct V_61 * V_62 , int V_63 )
{
T_1 V_31 = V_30 ;
struct V_9 * V_64 ;
struct V_65 * V_66 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_67 * V_68 = & V_15 -> V_69 ;
if ( F_29 ( V_68 , V_70 ) == true )
F_30 ( V_15 , V_71 , 1 ) ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( V_64 == NULL )
return V_30 ;
V_66 = F_31 ( sizeof( struct V_65 ) , V_72 ) ;
if ( V_66 == NULL ) {
F_16 ( V_64 ) ;
return V_30 ;
}
F_32 ( V_15 , false ) ;
F_21 ( V_44 , V_45 , ( L_5 , V_48 ) ) ;
F_33 ( V_64 , V_66 , F_12 ( V_73 ) ) ;
V_66 -> V_74 = V_68 -> V_74 ;
if ( V_59 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_60 && V_75 < V_76 ; V_75 ++ ) {
if ( V_59 [ V_75 ] . V_77 ) {
memcpy ( & V_66 -> V_59 [ V_75 ] , & V_59 [ V_75 ] , sizeof( struct V_58 ) ) ;
V_66 -> V_60 ++ ;
}
}
}
if ( V_62 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_63 && V_75 < V_78 ; V_75 ++ ) {
if ( V_62 [ V_75 ] . V_79 && ! ( V_62 [ V_75 ] . V_80 & V_81 ) ) {
memcpy ( & V_66 -> V_62 [ V_75 ] , & V_62 [ V_75 ] , sizeof( struct V_61 ) ) ;
V_66 -> V_63 ++ ;
}
}
}
F_34 ( V_68 , V_82 ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
if ( V_31 == V_6 ) {
V_68 -> V_83 = V_84 ;
F_35 ( & V_68 -> V_85 ,
V_84 + F_36 ( V_86 ) ) ;
F_37 ( V_15 , V_87 ) ;
V_68 -> V_88 = V_89 ;
} else {
F_38 ( V_68 , V_82 ) ;
}
return V_31 ;
}
void F_39 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
F_16 ( V_33 -> V_24 ) ;
F_16 ( V_33 ) ;
}
T_1 F_40 ( struct V_32 * V_15 )
{
struct V_9 * V_33 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_90 * V_91 = & V_15 -> V_18 . V_92 ;
T_1 V_31 = V_6 ;
F_37 ( V_15 , V_93 ) ;
if ( V_68 -> V_94 . V_77 == 0 )
F_21 ( V_44 , V_45 , ( L_6 , V_68 -> V_94 . V_95 ) ) ;
else
F_21 ( V_44 , V_45 , ( L_7 , V_68 -> V_94 . V_95 ) ) ;
V_33 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
if ( V_33 == NULL ) {
V_31 = V_30 ;
goto exit;
}
F_41 ( & V_33 -> V_13 ) ;
V_33 -> V_20 = V_35 ;
V_33 -> V_24 = ( unsigned char * ) V_91 ;
V_33 -> V_97 = F_42 ( (struct V_90 * ) V_91 ) ;
V_33 -> V_36 = NULL ;
V_33 -> V_37 = 0 ;
V_91 -> V_98 = V_33 -> V_97 ;
V_31 = F_13 ( V_2 , V_33 ) ;
exit:
return V_31 ;
}
T_1 F_43 ( struct V_32 * V_15 , struct V_99 * V_100 )
{
T_1 V_31 = V_6 ;
T_3 V_101 = 0 ;
struct V_90 * V_102 ;
struct V_9 * V_33 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_103 * V_104 = & V_68 -> V_105 ;
struct V_106 * V_107 = & V_15 -> V_108 ;
struct V_109 * V_110 = & V_15 -> V_18 ;
struct V_111 * V_112 = & V_68 -> V_113 ;
enum V_114 V_115 = V_100 -> V_116 . V_117 ;
struct V_118 * V_119 = & V_15 -> V_120 ;
struct V_121 * V_122 = & ( V_119 -> V_123 ) ;
F_37 ( V_15 , V_93 ) ;
if ( V_68 -> V_94 . V_77 == 0 )
F_21 ( V_44 , V_45 , ( L_8 ) ) ;
else
F_21 ( V_44 , V_124 , ( L_9 , V_68 -> V_94 . V_95 ) ) ;
V_33 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( ! V_33 ) {
V_31 = V_30 ;
goto exit;
}
V_101 = sizeof( struct V_90 ) ;
if ( ! F_29 ( V_68 , V_125 | V_126 ) ) {
switch ( V_115 ) {
case V_127 :
F_34 ( V_68 , V_126 ) ;
break;
case V_128 :
F_34 ( V_68 , V_125 ) ;
break;
case V_129 :
case V_130 :
case V_131 :
break;
}
}
V_102 = (struct V_90 * ) & V_107 -> V_132 ;
if ( V_102 == NULL ) {
F_16 ( V_33 ) ;
V_31 = V_30 ;
F_21 ( V_44 , V_56 , ( L_10 ) ) ;
goto exit;
}
memset ( V_102 , 0 , V_101 ) ;
memcpy ( V_102 , & V_100 -> V_116 , F_42 ( & V_100 -> V_116 ) ) ;
V_107 -> V_133 [ 0 ] = ( unsigned char ) V_102 -> V_134 ;
if ( ( V_102 -> V_134 - 12 ) < ( 256 - 1 ) )
memcpy ( & V_107 -> V_133 [ 1 ] , & V_102 -> V_135 [ 12 ] , V_102 -> V_134 - 12 ) ;
else
memcpy ( & V_107 -> V_133 [ 1 ] , & V_102 -> V_135 [ 12 ] , ( 256 - 1 ) ) ;
V_102 -> V_134 = 0 ;
if ( ! V_68 -> V_136 )
memcpy ( & V_68 -> V_137 [ 0 ] , & V_100 -> V_116 . V_138 [ 0 ] , V_139 ) ;
V_102 -> V_134 = F_44 ( V_15 , & V_100 -> V_116 . V_135 [ 0 ] , & V_102 -> V_135 [ 0 ] , V_100 -> V_116 . V_134 ) ;
V_104 -> V_140 = 0 ;
if ( V_110 -> V_141 ) {
T_2 V_142 ;
V_142 = F_45 ( V_15 , & V_100 -> V_116 . V_135 [ 0 ] , & V_102 -> V_135 [ 0 ] , V_100 -> V_116 . V_134 , V_102 -> V_134 ) ;
if ( V_102 -> V_134 != V_142 ) {
V_102 -> V_134 = V_142 ;
V_104 -> V_140 = 1 ;
} else {
V_104 -> V_140 = 0 ;
}
}
V_112 -> V_143 = false ;
if ( V_110 -> V_144 ) {
if ( ( V_15 -> V_108 . V_145 != V_146 ) &&
( V_15 -> V_108 . V_145 != V_147 ) &&
( V_15 -> V_108 . V_145 != V_148 ) ) {
F_46 ( V_15 , & V_100 -> V_116 . V_135 [ 0 ] , & V_102 -> V_135 [ 0 ] ,
V_100 -> V_116 . V_134 , & V_102 -> V_134 ) ;
}
}
V_122 -> V_149 = F_47 ( V_100 -> V_116 . V_135 , V_100 -> V_116 . V_134 ) ;
if ( V_122 -> V_149 == V_150 )
V_15 -> V_16 . V_151 = 0 ;
else
V_15 -> V_16 . V_151 = V_15 -> V_18 . V_151 ;
F_23 ( L_11 , V_48 , V_15 -> V_16 . V_151 ) ;
V_33 -> V_97 = F_42 ( V_102 ) ;
F_41 ( & V_33 -> V_13 ) ;
V_33 -> V_20 = V_34 ;
V_33 -> V_24 = ( unsigned char * ) V_102 ;
V_33 -> V_36 = NULL ;
V_33 -> V_37 = 0 ;
V_31 = F_13 ( V_2 , V_33 ) ;
exit:
return V_31 ;
}
T_1 F_48 ( struct V_32 * V_15 , T_2 V_152 , bool V_153 )
{
struct V_9 * V_154 = NULL ;
struct V_155 * V_156 = NULL ;
struct V_1 * V_42 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
F_21 ( V_44 , V_124 , ( L_12 ) ) ;
V_156 = F_31 ( sizeof( * V_156 ) , V_96 ) ;
if ( V_156 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_156 -> V_152 = V_152 ;
if ( V_153 ) {
V_154 = F_31 ( sizeof( * V_154 ) , V_96 ) ;
if ( V_154 == NULL ) {
V_31 = V_30 ;
F_16 ( V_156 ) ;
goto exit;
}
F_33 ( V_154 , V_156 , V_157 ) ;
V_31 = F_13 ( V_42 , V_154 ) ;
} else {
if ( F_49 ( V_15 , ( T_1 * ) V_156 ) != V_158 )
V_31 = V_30 ;
F_16 ( V_156 ) ;
}
exit:
return V_31 ;
}
T_1 F_50 ( struct V_32 * V_15 , enum V_114 V_159 )
{
struct V_9 * V_64 ;
struct V_160 * V_161 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
V_161 = F_31 ( sizeof( struct V_160 ) , V_96 ) ;
if ( ! V_64 || ! V_161 ) {
F_16 ( V_64 ) ;
F_16 ( V_161 ) ;
return false ;
}
F_33 ( V_64 , V_161 , V_162 ) ;
V_161 -> V_163 = ( T_1 ) V_159 ;
return F_13 ( V_2 , V_64 ) ;
}
T_1 F_51 ( struct V_32 * V_15 , T_1 * V_164 , T_1 V_165 )
{
struct V_9 * V_64 ;
struct V_166 * V_167 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_168 * V_169 = NULL ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_106 * V_107 = & V_15 -> V_108 ;
struct V_170 * V_171 = (struct V_170 * ) V_164 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
V_167 = F_31 ( sizeof( struct V_166 ) , V_96 ) ;
V_169 = F_31 ( sizeof( struct V_168 ) , V_96 ) ;
if ( ! V_64 || ! V_167 || ! V_169 ) {
F_16 ( V_64 ) ;
F_16 ( V_167 ) ;
F_16 ( V_169 ) ;
return V_30 ;
}
F_33 ( V_64 , V_167 , V_172 ) ;
V_64 -> V_36 = ( T_1 * ) V_169 ;
V_64 -> V_37 = sizeof( struct V_168 ) ;
F_52 ( V_167 -> V_173 , V_171 -> V_174 ) ;
if ( F_29 ( V_68 , V_125 ) )
V_167 -> V_175 = ( unsigned char ) V_107 -> V_145 ;
else
F_53 ( V_107 , V_171 , V_167 -> V_175 , false ) ;
if ( V_165 )
memcpy ( & V_167 -> V_176 , & V_171 -> V_177 , 16 ) ;
else
memcpy ( & V_167 -> V_176 , & V_107 -> V_178 [ V_107 -> V_179 ] . V_180 , 16 ) ;
V_15 -> V_108 . V_181 = true ;
return F_13 ( V_2 , V_64 ) ;
}
T_1 F_54 ( struct V_32 * V_15 , T_1 * V_164 , T_1 V_182 , T_1 V_153 )
{
struct V_9 * V_64 ;
struct V_166 * V_167 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_168 * V_169 = NULL ;
struct V_170 * V_171 = (struct V_170 * ) V_164 ;
T_1 V_31 = V_6 ;
if ( ! V_153 ) {
F_55 ( V_15 , V_182 ) ;
} else {
V_64 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_167 = F_31 ( sizeof( struct V_166 ) , V_72 ) ;
if ( V_167 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_169 = F_31 ( sizeof( struct V_168 ) , V_72 ) ;
if ( V_169 == NULL ) {
F_16 ( V_64 ) ;
F_16 ( V_167 ) ;
V_31 = V_30 ;
goto exit;
}
F_33 ( V_64 , V_167 , V_172 ) ;
V_64 -> V_36 = ( T_1 * ) V_169 ;
V_64 -> V_37 = sizeof( struct V_168 ) ;
F_52 ( V_167 -> V_173 , V_171 -> V_174 ) ;
V_167 -> V_175 = V_183 ;
V_167 -> V_184 = V_182 ;
V_31 = F_13 ( V_2 , V_64 ) ;
}
exit:
return V_31 ;
}
T_1 F_56 ( struct V_32 * V_15 , T_1 V_185 , T_1 * V_173 )
{
struct V_1 * V_2 = & V_15 -> V_42 ;
struct V_9 * V_64 ;
struct V_186 * V_187 ;
T_1 V_31 = V_6 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_187 = F_31 ( sizeof( struct V_186 ) , V_96 ) ;
if ( V_187 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_187 -> V_185 = V_185 ;
memcpy ( V_187 -> V_173 , V_173 , V_139 ) ;
F_33 ( V_64 , V_187 , F_12 ( V_188 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
exit:
return V_31 ;
}
T_1 F_57 ( struct V_32 * V_15 )
{
struct V_9 * V_64 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_72 ) ;
if ( V_23 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_23 -> V_25 = V_189 ;
V_23 -> V_190 = 0 ;
V_23 -> V_40 = ( T_1 * ) V_15 ;
F_33 ( V_64 , V_23 , F_12 ( V_21 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
exit:
return V_31 ;
}
T_1 F_58 ( struct V_32 * V_15 , T_1 V_191 , T_1 V_153 )
{
struct V_9 * V_192 ;
struct V_193 * V_194 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
F_21 ( V_44 , V_124 , ( L_13 ) ) ;
if ( ! F_59 ( V_191 ) ) {
V_31 = V_30 ;
goto exit;
}
V_194 = F_31 ( sizeof( struct V_193 ) , V_96 ) ;
if ( V_194 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_194 -> V_195 = V_191 ;
if ( V_153 ) {
V_192 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
if ( V_192 == NULL ) {
F_16 ( V_194 ) ;
V_31 = V_30 ;
goto exit;
}
F_33 ( V_192 , V_194 , F_12 ( V_27 ) ) ;
V_31 = F_13 ( V_2 , V_192 ) ;
} else {
if ( F_60 ( V_15 , ( unsigned char * ) V_194 ) != V_158 )
V_31 = V_30 ;
F_16 ( V_194 ) ;
}
if ( V_31 == V_6 )
V_15 -> V_69 . V_196 = V_191 ;
exit:
return V_31 ;
}
static void F_61 ( struct V_32 * V_15 )
{
T_1 V_197 ;
T_1 V_198 = false , V_199 = false , V_200 = false ;
T_1 V_201 = false , V_202 = false , V_203 = false ;
struct V_67 * V_68 = & ( V_15 -> V_69 ) ;
if ( F_29 ( V_68 , V_70 ) ) {
if ( V_68 -> V_204 . V_205 > 100 ||
V_68 -> V_204 . V_206 > 100 ) {
V_198 = true ;
if ( V_68 -> V_204 . V_205 > V_68 -> V_204 . V_206 )
V_200 = true ;
else
V_199 = true ;
}
if ( V_68 -> V_204 . V_205 > 4000 ||
V_68 -> V_204 . V_206 > 4000 ) {
V_201 = true ;
if ( V_68 -> V_204 . V_205 > V_68 -> V_204 . V_206 )
V_202 = true ;
else
V_203 = true ;
}
if ( ( ( V_68 -> V_204 . V_207 + V_68 -> V_204 . V_206 ) > 8 ) ||
( V_68 -> V_204 . V_207 > 2 ) )
V_197 = false ;
else
V_197 = true ;
if ( V_197 )
F_62 ( V_15 ) ;
else
F_63 ( V_15 ) ;
} else {
F_63 ( V_15 ) ;
}
V_68 -> V_204 . V_205 = 0 ;
V_68 -> V_204 . V_206 = 0 ;
V_68 -> V_204 . V_207 = 0 ;
V_68 -> V_204 . V_198 = V_198 ;
V_68 -> V_204 . V_199 = V_199 ;
V_68 -> V_204 . V_200 = V_200 ;
V_68 -> V_204 . V_201 = V_201 ;
V_68 -> V_204 . V_202 = V_202 ;
V_68 -> V_204 . V_203 = V_203 ;
}
static void F_64 ( struct V_32 * V_15 , T_1 * V_40 , int V_208 )
{
struct V_67 * V_68 ;
V_15 = (struct V_32 * ) V_40 ;
V_68 = & ( V_15 -> V_69 ) ;
#ifdef F_65
if ( F_29 ( V_68 , V_209 ) == true )
F_66 ( V_15 ) ;
#endif
F_67 ( V_15 ) ;
F_61 ( V_15 ) ;
F_68 ( V_15 ) ;
}
static void F_69 ( struct V_32 * V_15 , T_1 V_210 )
{
struct V_211 * V_212 = & V_15 -> V_16 ;
struct V_67 * V_68 = & ( V_15 -> V_69 ) ;
T_1 V_213 ;
if ( ( F_29 ( V_68 , V_214 ) == true ) ||
( F_29 ( V_68 , V_126 ) == true ) )
return;
switch ( V_210 ) {
case V_71 :
if ( F_29 ( V_68 , V_70 ) == true ) {
F_63 ( V_15 ) ;
}
break;
case V_215 :
F_63 ( V_15 ) ;
break;
case V_216 :
V_213 = 1 ;
V_15 -> V_16 . V_217 = 0 ;
F_70 ( V_15 , V_218 , ( T_1 * ) ( & V_213 ) ) ;
break;
case V_219 :
V_213 = 0 ;
F_63 ( V_15 ) ;
F_70 ( V_15 , V_218 , ( T_1 * ) ( & V_213 ) ) ;
break;
case V_220 :
V_212 -> V_221 = V_84 ;
F_63 ( V_15 ) ;
break;
case V_222 :
F_63 ( V_15 ) ;
break;
default:
break;
}
}
T_1 F_30 ( struct V_32 * V_15 , T_1 V_210 , T_1 V_153 )
{
struct V_9 * V_64 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
if ( V_153 ) {
V_64 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_72 ) ;
if ( V_23 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_23 -> V_25 = V_223 ;
V_23 -> V_190 = V_210 ;
V_23 -> V_40 = NULL ;
F_33 ( V_64 , V_23 , F_12 ( V_21 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
} else {
F_69 ( V_15 , V_210 ) ;
}
exit:
return V_31 ;
}
static void F_71 ( struct V_32 * V_15 , T_4 V_224 )
{
F_70 ( V_15 , V_225 , ( T_1 * ) ( & V_224 ) ) ;
}
T_1 F_72 ( struct V_32 * V_15 , T_4 V_224 )
{
struct V_9 * V_64 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_72 ) ;
if ( V_23 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_23 -> V_25 = V_226 ;
V_23 -> V_190 = V_224 ;
V_23 -> V_40 = NULL ;
F_33 ( V_64 , V_23 , F_12 ( V_21 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
exit:
return V_31 ;
}
static void F_73 ( struct V_32 * V_15 , T_1 V_227 )
{
F_70 ( V_15 , V_228 , ( T_1 * ) ( & V_227 ) ) ;
}
T_1 F_74 ( struct V_32 * V_15 , T_1 V_227 , T_1 V_153 )
{
struct V_9 * V_64 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_229 ;
T_1 V_31 = V_6 ;
F_75 ( V_15 , V_230 , & V_229 ) ;
if ( ! V_229 )
return V_31 ;
if ( V_153 ) {
V_64 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_96 ) ;
if ( V_23 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_23 -> V_25 = V_231 ;
V_23 -> V_190 = V_227 ;
V_23 -> V_40 = NULL ;
F_33 ( V_64 , V_23 , F_12 ( V_21 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
} else {
F_73 ( V_15 , V_227 ) ;
}
exit:
return V_31 ;
}
T_1 F_76 ( struct V_32 * V_15 )
{
struct V_9 * V_232 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
V_232 = F_31 ( sizeof( struct V_9 ) , V_72 ) ;
V_23 = F_31 ( sizeof( struct V_22 ) , V_72 ) ;
if ( ! V_232 || ! V_23 ) {
F_16 ( V_232 ) ;
F_16 ( V_23 ) ;
return V_30 ;
}
V_23 -> V_25 = V_26 ;
V_23 -> V_40 = NULL ;
F_33 ( V_232 , V_23 , F_12 ( V_21 ) ) ;
return F_13 ( V_2 , V_232 ) ;
}
static void F_77 ( struct V_32 * V_15 )
{
int V_233 = 0 ;
struct V_170 * V_234 ;
struct V_235 * V_236 = & V_15 -> V_237 ;
V_234 = F_78 ( V_15 ) ;
if ( ! V_234 )
return;
if ( V_234 -> V_238 == 0 ) {
T_1 V_239 = 0 ;
F_79 ( V_15 , V_240 , & V_239 ) ;
while ( ! V_239 ) {
F_80 ( 100 ) ;
V_233 ++ ;
if ( V_233 > 10 )
break;
F_79 ( V_15 , V_240 , & V_239 ) ;
}
if ( V_233 <= 10 ) {
V_236 -> V_241 &= ~ F_81 ( 0 ) ;
V_236 -> V_242 &= ~ F_81 ( 0 ) ;
F_82 ( V_15 , V_243 , NULL , false ) ;
} else {
F_83 ( V_15 ) ;
}
}
}
T_1 F_83 ( struct V_32 * V_15 )
{
struct V_9 * V_64 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = & V_15 -> V_42 ;
T_1 V_31 = V_6 ;
V_64 = F_31 ( sizeof( struct V_9 ) , V_96 ) ;
if ( V_64 == NULL ) {
V_31 = V_30 ;
goto exit;
}
V_23 = F_31 ( sizeof( struct V_22 ) , V_96 ) ;
if ( V_23 == NULL ) {
F_16 ( V_64 ) ;
V_31 = V_30 ;
goto exit;
}
V_23 -> V_25 = V_244 ;
V_23 -> V_190 = 0 ;
V_23 -> V_40 = NULL ;
F_33 ( V_64 , V_23 , F_12 ( V_21 ) ) ;
V_31 = F_13 ( V_2 , V_64 ) ;
exit:
return V_31 ;
}
T_1 F_84 ( struct V_32 * V_15 , unsigned char * V_40 )
{
struct V_22 * V_245 ;
if ( ! V_40 )
return V_53 ;
V_245 = (struct V_22 * ) V_40 ;
switch ( V_245 -> V_25 ) {
case V_189 :
F_64 ( V_15 , V_245 -> V_40 , V_245 -> V_190 ) ;
break;
case V_26 :
F_85 ( V_15 ) ;
break;
case V_223 :
F_69 ( V_15 , ( T_1 ) V_245 -> V_190 ) ;
break;
case V_226 :
F_71 ( V_15 , V_245 -> V_190 ) ;
break;
case V_231 :
F_73 ( V_15 , V_245 -> V_190 ) ;
break;
#ifdef F_65
case V_244 :
F_77 ( V_15 ) ;
break;
#endif
default:
break;
}
if ( V_245 -> V_40 && V_245 -> V_190 > 0 )
F_16 ( V_245 -> V_40 ) ;
return V_158 ;
}
void F_86 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_67 * V_68 = & V_15 -> V_69 ;
if ( V_33 -> V_31 == V_50 ) {
F_35 ( & V_68 -> V_85 ,
V_84 + F_36 ( 1 ) ) ;
} else if ( V_33 -> V_31 != V_158 ) {
F_35 ( & V_68 -> V_85 ,
V_84 + F_36 ( 1 ) ) ;
F_21 ( V_44 , V_56 , ( L_14 ) ) ;
}
F_14 ( V_33 ) ;
}
void F_87 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_67 * V_68 = & V_15 -> V_69 ;
if ( V_33 -> V_31 != V_158 ) {
F_88 ( & V_68 -> V_12 ) ;
F_34 ( V_68 , V_70 ) ;
F_89 ( & V_68 -> V_12 ) ;
F_21 ( V_44 , V_56 , ( L_15 ) ) ;
return;
}
F_14 ( V_33 ) ;
}
void F_90 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_67 * V_68 = & V_15 -> V_69 ;
if ( V_33 -> V_31 == V_50 ) {
F_35 ( & V_68 -> V_246 ,
V_84 + F_36 ( 1 ) ) ;
} else if ( V_33 -> V_31 != V_158 ) {
F_21 ( V_44 , V_56 , ( L_16 ) ) ;
F_35 ( & V_68 -> V_246 ,
V_84 + F_36 ( 1 ) ) ;
}
F_14 ( V_33 ) ;
}
void F_91 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_170 * V_164 = NULL ;
struct V_99 * V_247 = NULL ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_90 * V_100 = (struct V_90 * ) V_33 -> V_24 ;
struct V_99 * V_248 = & ( V_68 -> V_249 ) ;
if ( V_33 -> V_31 != V_158 ) {
F_21 ( V_44 , V_56 , ( L_17 ) ) ;
F_35 ( & V_68 -> V_246 ,
V_84 + F_36 ( 1 ) ) ;
}
F_92 ( & V_68 -> V_246 ) ;
F_88 ( & V_68 -> V_12 ) ;
if ( F_29 ( V_68 , V_209 ) ) {
V_164 = F_93 ( & V_15 -> V_237 , V_100 -> V_138 ) ;
if ( ! V_164 ) {
V_164 = F_94 ( & V_15 -> V_237 , V_100 -> V_138 ) ;
if ( V_164 == NULL ) {
F_21 ( V_44 , V_56 , ( L_18 ) ) ;
goto V_250;
}
}
F_95 ( V_15 ) ;
} else {
V_247 = F_96 ( V_68 ) ;
F_88 ( & ( V_68 -> V_251 . V_12 ) ) ;
if ( V_247 == NULL ) {
V_247 = F_97 ( & V_68 -> V_251 ) ;
if ( V_247 == NULL ) {
F_21 ( V_44 , V_56 , ( L_19 ) ) ;
F_89 ( & V_68 -> V_251 . V_12 ) ;
goto V_250;
}
V_247 -> V_252 = V_84 ;
} else {
F_6 ( & ( V_247 -> V_13 ) , & V_68 -> V_251 . V_8 ) ;
}
V_100 -> V_98 = F_42 ( V_100 ) ;
memcpy ( & ( V_247 -> V_116 ) , V_100 , V_100 -> V_98 ) ;
memcpy ( & V_248 -> V_116 , V_100 , ( F_42 ( V_100 ) ) ) ;
F_38 ( V_68 , V_253 ) ;
F_89 ( & V_68 -> V_251 . V_12 ) ;
}
V_250:
F_89 ( & V_68 -> V_12 ) ;
F_14 ( V_33 ) ;
}
void F_98 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_235 * V_236 = & V_15 -> V_237 ;
struct V_168 * V_169 = (struct V_168 * ) ( V_33 -> V_36 ) ;
struct V_170 * V_164 = F_93 ( V_236 , V_169 -> V_173 ) ;
if ( V_164 == NULL ) {
F_21 ( V_44 , V_56 , ( L_20 ) ) ;
goto exit;
}
exit:
F_14 ( V_33 ) ;
}
void F_99 ( struct V_32 * V_15 , struct V_9 * V_33 )
{
struct V_235 * V_236 = & V_15 -> V_237 ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_254 * V_255 = (struct V_254 * ) ( V_33 -> V_24 ) ;
struct V_256 * V_257 = (struct V_256 * ) ( V_33 -> V_36 ) ;
struct V_170 * V_164 = F_93 ( V_236 , V_255 -> V_173 ) ;
if ( V_164 == NULL ) {
F_21 ( V_44 , V_56 , ( L_21 ) ) ;
goto exit;
}
V_164 -> V_258 = V_257 -> V_259 ;
V_164 -> V_260 = V_257 -> V_259 ;
F_88 ( & V_68 -> V_12 ) ;
if ( ( F_29 ( V_68 , V_261 ) == true ) && ( F_29 ( V_68 , V_253 ) == true ) )
F_38 ( V_68 , V_253 ) ;
F_34 ( V_68 , V_70 ) ;
F_89 ( & V_68 -> V_12 ) ;
exit:
F_14 ( V_33 ) ;
}
