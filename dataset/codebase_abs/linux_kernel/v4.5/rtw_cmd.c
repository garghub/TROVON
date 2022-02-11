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
if ( F_9 ( & ( V_8 -> V_8 ) ) ) {
V_10 = NULL ;
} else {
V_10 = F_10 ( ( & V_8 -> V_8 ) -> V_14 , struct V_9 , V_13 ) ;
F_11 ( & V_10 -> V_13 ) ;
}
F_7 ( & V_8 -> V_12 , V_11 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
T_1 V_15 = false ;
if ( ( V_2 -> V_16 -> V_17 . V_18 ) &&
( ! V_2 -> V_16 -> V_19 . V_20 ) ) {
if ( V_9 -> V_21 == F_13 ( V_22 ) ) {
struct V_23 * V_24 = (struct V_23 * ) V_9 -> V_25 ;
if ( V_24 -> V_26 == V_27 )
V_15 = true ;
}
}
if ( V_9 -> V_21 == F_13 ( V_28 ) )
V_15 = true ;
if ( ( ! V_2 -> V_16 -> V_29 && ! V_15 ) ||
! V_2 -> V_30 )
return V_31 ;
return V_6 ;
}
T_2 F_14 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_32 = V_31 ;
struct V_33 * V_16 = V_2 -> V_16 ;
if ( V_9 == NULL )
goto exit;
V_9 -> V_16 = V_16 ;
V_32 = F_12 ( V_2 , V_9 ) ;
if ( V_32 == V_31 ) {
F_15 ( V_9 ) ;
goto exit;
}
V_32 = F_4 ( & V_2 -> V_5 , V_9 ) ;
if ( V_32 == V_6 )
F_16 ( & V_2 -> V_3 ) ;
exit:
return V_32 ;
}
void F_15 ( struct V_9 * V_34 )
{
if ( ( V_34 -> V_21 != V_35 ) && ( V_34 -> V_21 != V_36 ) ) {
F_17 ( V_34 -> V_25 ) ;
}
if ( V_34 -> V_37 != NULL ) {
if ( V_34 -> V_38 != 0 ) {
F_17 ( V_34 -> V_37 ) ;
}
}
F_17 ( V_34 ) ;
}
int F_18 ( void * V_39 )
{
T_1 V_40 ;
struct V_9 * V_34 ;
T_1 (* F_19)( struct V_33 * V_16 , T_1 * V_41 );
void (* F_20)( struct V_33 * V_42 , struct V_9 * V_34 );
struct V_33 * V_16 = V_39 ;
struct V_1 * V_2 = & ( V_16 -> V_43 ) ;
F_21 ( V_44 ) ;
V_2 -> V_30 = true ;
F_16 ( & V_2 -> V_4 ) ;
F_22 ( V_45 , V_46 , ( L_1 ) ) ;
while ( 1 ) {
if ( F_23 ( & V_2 -> V_3 ) == V_31 )
break;
if ( V_16 -> V_47 ||
V_16 -> V_48 ) {
F_24 ( L_2 ,
V_49 , V_16 -> V_47 , V_16 -> V_48 , __LINE__ ) ;
break;
}
V_50:
if ( V_16 -> V_47 ||
V_16 -> V_48 ) {
F_24 ( L_2 ,
V_49 , V_16 -> V_47 , V_16 -> V_48 , __LINE__ ) ;
break;
}
V_34 = F_8 ( & V_2 -> V_5 ) ;
if ( ! V_34 )
continue;
if ( F_12 ( V_2 , V_34 ) == V_31 ) {
V_34 -> V_32 = V_51 ;
} else {
if ( V_34 -> V_21 < F_25 ( V_52 ) ) {
F_19 = V_52 [ V_34 -> V_21 ] . V_53 ;
if ( F_19 ) {
V_40 = F_19 ( V_34 -> V_16 , V_34 -> V_25 ) ;
V_34 -> V_32 = V_40 ;
}
} else {
V_34 -> V_32 = V_54 ;
}
F_19 = NULL ;
}
if ( V_34 -> V_21 < F_25 ( V_55 ) ) {
F_20 = V_55 [ V_34 -> V_21 ] . V_56 ;
if ( F_20 == NULL ) {
F_22 ( V_45 , V_46 , ( L_3 , F_20 , V_34 -> V_21 ) ) ;
F_15 ( V_34 ) ;
} else {
F_20 ( V_34 -> V_16 , V_34 ) ;
}
} else {
F_22 ( V_45 , V_57 , ( L_4 , V_49 , V_34 -> V_21 ) ) ;
F_15 ( V_34 ) ;
}
if ( F_26 ( V_58 ) )
F_27 ( V_58 ) ;
goto V_50;
}
V_2 -> V_30 = false ;
while ( ( V_34 = F_8 ( & V_2 -> V_5 ) ) ) {
F_15 ( V_34 ) ;
}
F_16 ( & V_2 -> V_4 ) ;
F_28 ( NULL , 0 ) ;
}
T_1 F_29 ( struct V_33 * V_16 , struct V_59 * V_60 , int V_61 ,
struct V_62 * V_63 , int V_64 )
{
T_1 V_32 = V_31 ;
struct V_9 * V_65 ;
struct V_66 * V_67 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_68 * V_69 = & V_16 -> V_70 ;
if ( F_30 ( V_69 , V_71 ) == true )
F_31 ( V_16 , V_72 , 1 ) ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_65 == NULL )
return V_31 ;
V_67 = F_32 ( sizeof( struct V_66 ) , V_73 ) ;
if ( V_67 == NULL ) {
F_17 ( V_65 ) ;
return V_31 ;
}
F_33 ( V_16 , false ) ;
F_22 ( V_45 , V_46 , ( L_5 , V_49 ) ) ;
F_34 ( V_65 , V_67 , F_13 ( V_74 ) ) ;
V_67 -> V_75 = V_69 -> V_75 ;
if ( V_60 ) {
int V_76 ;
for ( V_76 = 0 ; V_76 < V_61 && V_76 < V_77 ; V_76 ++ ) {
if ( V_60 [ V_76 ] . V_78 ) {
memcpy ( & V_67 -> V_60 [ V_76 ] , & V_60 [ V_76 ] , sizeof( struct V_59 ) ) ;
V_67 -> V_61 ++ ;
}
}
}
if ( V_63 ) {
int V_76 ;
for ( V_76 = 0 ; V_76 < V_64 && V_76 < V_79 ; V_76 ++ ) {
if ( V_63 [ V_76 ] . V_80 && ! ( V_63 [ V_76 ] . V_81 & V_82 ) ) {
memcpy ( & V_67 -> V_63 [ V_76 ] , & V_63 [ V_76 ] , sizeof( struct V_62 ) ) ;
V_67 -> V_64 ++ ;
}
}
}
F_35 ( V_69 , V_83 ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
if ( V_32 == V_6 ) {
V_69 -> V_84 = V_85 ;
F_36 ( & V_69 -> V_86 ,
V_85 + F_37 ( V_87 ) ) ;
F_38 ( V_16 , V_88 ) ;
V_69 -> V_89 = V_90 ;
} else {
F_39 ( V_69 , V_83 ) ;
}
return V_32 ;
}
void F_40 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
F_17 ( V_34 -> V_25 ) ;
F_17 ( V_34 ) ;
}
T_1 F_41 ( struct V_33 * V_16 )
{
struct V_9 * V_34 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_68 * V_69 = & V_16 -> V_70 ;
struct V_91 * V_92 = & V_16 -> V_19 . V_93 ;
T_1 V_32 = V_6 ;
F_38 ( V_16 , V_94 ) ;
if ( V_69 -> V_95 . V_78 == 0 )
F_22 ( V_45 , V_46 , ( L_6 , V_69 -> V_95 . V_96 ) ) ;
else
F_22 ( V_45 , V_46 , ( L_7 , V_69 -> V_95 . V_96 ) ) ;
V_34 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_34 == NULL ) {
V_32 = V_31 ;
goto exit;
}
F_42 ( & V_34 -> V_13 ) ;
V_34 -> V_21 = V_36 ;
V_34 -> V_25 = ( unsigned char * ) V_92 ;
V_34 -> V_98 = F_43 ( (struct V_91 * ) V_92 ) ;
V_34 -> V_37 = NULL ;
V_34 -> V_38 = 0 ;
V_92 -> V_99 = V_34 -> V_98 ;
V_32 = F_14 ( V_2 , V_34 ) ;
exit:
return V_32 ;
}
T_1 F_44 ( struct V_33 * V_16 , struct V_100 * V_101 )
{
T_1 V_32 = V_6 ;
T_3 V_102 = 0 ;
struct V_91 * V_103 ;
struct V_9 * V_34 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_68 * V_69 = & V_16 -> V_70 ;
struct V_104 * V_105 = & V_69 -> V_106 ;
struct V_107 * V_108 = & V_16 -> V_109 ;
struct V_110 * V_111 = & V_16 -> V_19 ;
struct V_112 * V_113 = & V_69 -> V_114 ;
enum V_115 V_116 = V_101 -> V_117 . V_118 ;
struct V_119 * V_120 = & V_16 -> V_121 ;
struct V_122 * V_123 = & ( V_120 -> V_124 ) ;
F_38 ( V_16 , V_94 ) ;
if ( V_69 -> V_95 . V_78 == 0 )
F_22 ( V_45 , V_46 , ( L_8 ) ) ;
else
F_22 ( V_45 , V_125 , ( L_9 , V_69 -> V_95 . V_96 ) ) ;
V_34 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_34 == NULL ) {
V_32 = V_31 ;
F_22 ( V_45 , V_57 , ( L_10 ) ) ;
goto exit;
}
V_102 = sizeof( struct V_91 ) ;
if ( ! F_30 ( V_69 , V_126 | V_127 ) ) {
switch ( V_116 ) {
case V_128 :
F_35 ( V_69 , V_127 ) ;
break;
case V_129 :
F_35 ( V_69 , V_126 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
break;
}
}
V_103 = (struct V_91 * ) & V_108 -> V_133 ;
if ( V_103 == NULL ) {
F_17 ( V_34 ) ;
V_32 = V_31 ;
F_22 ( V_45 , V_57 , ( L_11 ) ) ;
goto exit;
}
memset ( V_103 , 0 , V_102 ) ;
memcpy ( V_103 , & V_101 -> V_117 , F_43 ( & V_101 -> V_117 ) ) ;
V_108 -> V_134 [ 0 ] = ( unsigned char ) V_103 -> V_135 ;
if ( ( V_103 -> V_135 - 12 ) < ( 256 - 1 ) )
memcpy ( & V_108 -> V_134 [ 1 ] , & V_103 -> V_136 [ 12 ] , V_103 -> V_135 - 12 ) ;
else
memcpy ( & V_108 -> V_134 [ 1 ] , & V_103 -> V_136 [ 12 ] , ( 256 - 1 ) ) ;
V_103 -> V_135 = 0 ;
if ( ! V_69 -> V_137 )
memcpy ( & V_69 -> V_138 [ 0 ] , & V_101 -> V_117 . V_139 [ 0 ] , V_140 ) ;
V_103 -> V_135 = F_45 ( V_16 , & V_101 -> V_117 . V_136 [ 0 ] , & V_103 -> V_136 [ 0 ] , V_101 -> V_117 . V_135 ) ;
V_105 -> V_141 = 0 ;
if ( V_111 -> V_142 ) {
T_2 V_143 ;
V_143 = F_46 ( V_16 , & V_101 -> V_117 . V_136 [ 0 ] , & V_103 -> V_136 [ 0 ] , V_101 -> V_117 . V_135 , V_103 -> V_135 ) ;
if ( V_103 -> V_135 != V_143 ) {
V_103 -> V_135 = V_143 ;
V_105 -> V_141 = 1 ;
} else {
V_105 -> V_141 = 0 ;
}
}
V_113 -> V_144 = false ;
if ( V_111 -> V_145 ) {
if ( ( V_16 -> V_109 . V_146 != V_147 ) &&
( V_16 -> V_109 . V_146 != V_148 ) &&
( V_16 -> V_109 . V_146 != V_149 ) ) {
F_47 ( V_16 , & V_101 -> V_117 . V_136 [ 0 ] , & V_103 -> V_136 [ 0 ] ,
V_101 -> V_117 . V_135 , & V_103 -> V_135 ) ;
}
}
V_123 -> V_150 = F_48 ( V_101 -> V_117 . V_136 , V_101 -> V_117 . V_135 ) ;
if ( V_123 -> V_150 == V_151 )
V_16 -> V_17 . V_152 = 0 ;
else
V_16 -> V_17 . V_152 = V_16 -> V_19 . V_152 ;
F_24 ( L_12 , V_49 , V_16 -> V_17 . V_152 ) ;
V_34 -> V_98 = F_43 ( V_103 ) ;
F_42 ( & V_34 -> V_13 ) ;
V_34 -> V_21 = V_35 ;
V_34 -> V_25 = ( unsigned char * ) V_103 ;
V_34 -> V_37 = NULL ;
V_34 -> V_38 = 0 ;
V_32 = F_14 ( V_2 , V_34 ) ;
exit:
return V_32 ;
}
T_1 F_49 ( struct V_33 * V_16 , T_2 V_153 , bool V_154 )
{
struct V_9 * V_155 = NULL ;
struct V_156 * V_157 = NULL ;
struct V_1 * V_43 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
F_22 ( V_45 , V_125 , ( L_13 ) ) ;
V_157 = F_32 ( sizeof( * V_157 ) , V_97 ) ;
if ( V_157 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_157 -> V_153 = V_153 ;
if ( V_154 ) {
V_155 = F_32 ( sizeof( * V_155 ) , V_97 ) ;
if ( V_155 == NULL ) {
V_32 = V_31 ;
F_17 ( V_157 ) ;
goto exit;
}
F_34 ( V_155 , V_157 , V_158 ) ;
V_32 = F_14 ( V_43 , V_155 ) ;
} else {
if ( F_50 ( V_16 , ( T_1 * ) V_157 ) != V_159 )
V_32 = V_31 ;
F_17 ( V_157 ) ;
}
exit:
return V_32 ;
}
T_1 F_51 ( struct V_33 * V_16 , enum V_115 V_160 )
{
struct V_9 * V_65 ;
struct V_161 * V_162 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
V_162 = F_32 ( sizeof( struct V_161 ) , V_97 ) ;
if ( ! V_65 || ! V_162 ) {
F_17 ( V_65 ) ;
F_17 ( V_162 ) ;
return false ;
}
F_34 ( V_65 , V_162 , V_163 ) ;
V_162 -> V_164 = ( T_1 ) V_160 ;
return F_14 ( V_2 , V_65 ) ;
}
T_1 F_52 ( struct V_33 * V_16 , T_1 * V_165 , T_1 V_166 )
{
struct V_9 * V_65 ;
struct V_167 * V_168 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_169 * V_170 = NULL ;
struct V_68 * V_69 = & V_16 -> V_70 ;
struct V_107 * V_108 = & V_16 -> V_109 ;
struct V_171 * V_172 = (struct V_171 * ) V_165 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
V_168 = F_32 ( sizeof( struct V_167 ) , V_97 ) ;
V_170 = F_32 ( sizeof( struct V_169 ) , V_97 ) ;
if ( ! V_65 || ! V_168 || ! V_170 ) {
F_17 ( V_65 ) ;
F_17 ( V_168 ) ;
F_17 ( V_170 ) ;
return V_31 ;
}
F_34 ( V_65 , V_168 , V_173 ) ;
V_65 -> V_37 = ( T_1 * ) V_170 ;
V_65 -> V_38 = sizeof( struct V_169 ) ;
F_53 ( V_168 -> V_174 , V_172 -> V_175 ) ;
if ( F_30 ( V_69 , V_126 ) )
V_168 -> V_176 = ( unsigned char ) V_108 -> V_146 ;
else
F_54 ( V_108 , V_172 , V_168 -> V_176 , false ) ;
if ( V_166 )
memcpy ( & V_168 -> V_177 , & V_172 -> V_178 , 16 ) ;
else
memcpy ( & V_168 -> V_177 , & V_108 -> V_179 [ V_108 -> V_180 ] . V_181 , 16 ) ;
V_16 -> V_109 . V_182 = true ;
return F_14 ( V_2 , V_65 ) ;
}
T_1 F_55 ( struct V_33 * V_16 , T_1 * V_165 , T_1 V_183 , T_1 V_154 )
{
struct V_9 * V_65 ;
struct V_167 * V_168 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_169 * V_170 = NULL ;
struct V_171 * V_172 = (struct V_171 * ) V_165 ;
T_1 V_32 = V_6 ;
if ( ! V_154 ) {
F_56 ( V_16 , V_183 ) ;
} else {
V_65 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_168 = F_32 ( sizeof( struct V_167 ) , V_73 ) ;
if ( V_168 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_170 = F_32 ( sizeof( struct V_169 ) , V_73 ) ;
if ( V_170 == NULL ) {
F_17 ( V_65 ) ;
F_17 ( V_168 ) ;
V_32 = V_31 ;
goto exit;
}
F_34 ( V_65 , V_168 , V_173 ) ;
V_65 -> V_37 = ( T_1 * ) V_170 ;
V_65 -> V_38 = sizeof( struct V_169 ) ;
F_53 ( V_168 -> V_174 , V_172 -> V_175 ) ;
V_168 -> V_176 = V_184 ;
V_168 -> V_185 = V_183 ;
V_32 = F_14 ( V_2 , V_65 ) ;
}
exit:
return V_32 ;
}
T_1 F_57 ( struct V_33 * V_16 , T_1 V_186 , T_1 * V_174 )
{
struct V_1 * V_2 = & V_16 -> V_43 ;
struct V_9 * V_65 ;
struct V_187 * V_188 ;
T_1 V_32 = V_6 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_188 = F_32 ( sizeof( struct V_187 ) , V_97 ) ;
if ( V_188 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_188 -> V_186 = V_186 ;
memcpy ( V_188 -> V_174 , V_174 , V_140 ) ;
F_34 ( V_65 , V_188 , F_13 ( V_189 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
exit:
return V_32 ;
}
T_1 F_58 ( struct V_33 * V_16 )
{
struct V_9 * V_65 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_24 = F_32 ( sizeof( struct V_23 ) , V_73 ) ;
if ( V_24 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_24 -> V_26 = V_190 ;
V_24 -> V_191 = 0 ;
V_24 -> V_41 = ( T_1 * ) V_16 ;
F_34 ( V_65 , V_24 , F_13 ( V_22 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
exit:
return V_32 ;
}
T_1 F_59 ( struct V_33 * V_16 , T_1 V_192 , T_1 V_154 )
{
struct V_9 * V_193 ;
struct V_194 * V_195 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
F_22 ( V_45 , V_125 , ( L_14 ) ) ;
if ( ! F_60 ( V_192 ) ) {
V_32 = V_31 ;
goto exit;
}
V_195 = F_32 ( sizeof( struct V_194 ) , V_97 ) ;
if ( V_195 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_195 -> V_196 = V_192 ;
if ( V_154 ) {
V_193 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_193 == NULL ) {
F_17 ( V_195 ) ;
V_32 = V_31 ;
goto exit;
}
F_34 ( V_193 , V_195 , F_13 ( V_28 ) ) ;
V_32 = F_14 ( V_2 , V_193 ) ;
} else {
if ( F_61 ( V_16 , ( unsigned char * ) V_195 ) != V_159 )
V_32 = V_31 ;
F_17 ( V_195 ) ;
}
if ( V_32 == V_6 )
V_16 -> V_70 . V_197 = V_192 ;
exit:
return V_32 ;
}
static void F_62 ( struct V_33 * V_16 )
{
T_1 V_198 ;
T_1 V_199 = false , V_200 = false , V_201 = false ;
T_1 V_202 = false , V_203 = false , V_204 = false ;
struct V_68 * V_69 = & ( V_16 -> V_70 ) ;
if ( F_30 ( V_69 , V_71 ) ) {
if ( V_69 -> V_205 . V_206 > 100 ||
V_69 -> V_205 . V_207 > 100 ) {
V_199 = true ;
if ( V_69 -> V_205 . V_206 > V_69 -> V_205 . V_207 )
V_201 = true ;
else
V_200 = true ;
}
if ( V_69 -> V_205 . V_206 > 4000 ||
V_69 -> V_205 . V_207 > 4000 ) {
V_202 = true ;
if ( V_69 -> V_205 . V_206 > V_69 -> V_205 . V_207 )
V_203 = true ;
else
V_204 = true ;
}
if ( ( ( V_69 -> V_205 . V_208 + V_69 -> V_205 . V_207 ) > 8 ) ||
( V_69 -> V_205 . V_208 > 2 ) )
V_198 = false ;
else
V_198 = true ;
if ( V_198 )
F_63 ( V_16 ) ;
else
F_64 ( V_16 ) ;
} else {
F_64 ( V_16 ) ;
}
V_69 -> V_205 . V_206 = 0 ;
V_69 -> V_205 . V_207 = 0 ;
V_69 -> V_205 . V_208 = 0 ;
V_69 -> V_205 . V_199 = V_199 ;
V_69 -> V_205 . V_200 = V_200 ;
V_69 -> V_205 . V_201 = V_201 ;
V_69 -> V_205 . V_202 = V_202 ;
V_69 -> V_205 . V_203 = V_203 ;
V_69 -> V_205 . V_204 = V_204 ;
}
static void F_65 ( struct V_33 * V_16 , T_1 * V_41 , int V_209 )
{
struct V_68 * V_69 ;
V_16 = (struct V_33 * ) V_41 ;
V_69 = & ( V_16 -> V_70 ) ;
#ifdef F_66
if ( F_30 ( V_69 , V_210 ) == true )
F_67 ( V_16 ) ;
#endif
F_68 ( V_16 ) ;
F_62 ( V_16 ) ;
F_69 ( V_16 ) ;
}
static void F_70 ( struct V_33 * V_16 , T_1 V_211 )
{
struct V_212 * V_213 = & V_16 -> V_17 ;
struct V_68 * V_69 = & ( V_16 -> V_70 ) ;
T_1 V_214 ;
if ( ( F_30 ( V_69 , V_215 ) == true ) ||
( F_30 ( V_69 , V_127 ) == true ) )
return;
switch ( V_211 ) {
case V_72 :
if ( F_30 ( V_69 , V_71 ) == true ) {
F_64 ( V_16 ) ;
}
break;
case V_216 :
F_64 ( V_16 ) ;
break;
case V_217 :
V_214 = 1 ;
V_16 -> V_17 . V_218 = 0 ;
F_71 ( V_16 , V_219 , ( T_1 * ) ( & V_214 ) ) ;
break;
case V_220 :
V_214 = 0 ;
F_64 ( V_16 ) ;
F_71 ( V_16 , V_219 , ( T_1 * ) ( & V_214 ) ) ;
break;
case V_221 :
V_213 -> V_222 = V_85 ;
F_64 ( V_16 ) ;
break;
case V_223 :
F_64 ( V_16 ) ;
break;
default:
break;
}
}
T_1 F_31 ( struct V_33 * V_16 , T_1 V_211 , T_1 V_154 )
{
struct V_9 * V_65 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
if ( V_154 ) {
V_65 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_24 = F_32 ( sizeof( struct V_23 ) , V_73 ) ;
if ( V_24 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_24 -> V_26 = V_224 ;
V_24 -> V_191 = V_211 ;
V_24 -> V_41 = NULL ;
F_34 ( V_65 , V_24 , F_13 ( V_22 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
} else {
F_70 ( V_16 , V_211 ) ;
}
exit:
return V_32 ;
}
static void F_72 ( struct V_33 * V_16 , T_4 V_225 )
{
F_71 ( V_16 , V_226 , ( T_1 * ) ( & V_225 ) ) ;
}
T_1 F_73 ( struct V_33 * V_16 , T_4 V_225 )
{
struct V_9 * V_65 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_24 = F_32 ( sizeof( struct V_23 ) , V_73 ) ;
if ( V_24 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_24 -> V_26 = V_227 ;
V_24 -> V_191 = V_225 ;
V_24 -> V_41 = NULL ;
F_34 ( V_65 , V_24 , F_13 ( V_22 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
exit:
return V_32 ;
}
static void F_74 ( struct V_33 * V_16 , T_1 V_228 )
{
F_71 ( V_16 , V_229 , ( T_1 * ) ( & V_228 ) ) ;
}
T_1 F_75 ( struct V_33 * V_16 , T_1 V_228 , T_1 V_154 )
{
struct V_9 * V_65 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_230 ;
T_1 V_32 = V_6 ;
F_76 ( V_16 , V_231 , & V_230 ) ;
if ( ! V_230 )
return V_32 ;
if ( V_154 ) {
V_65 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_24 = F_32 ( sizeof( struct V_23 ) , V_97 ) ;
if ( V_24 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_24 -> V_26 = V_232 ;
V_24 -> V_191 = V_228 ;
V_24 -> V_41 = NULL ;
F_34 ( V_65 , V_24 , F_13 ( V_22 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
} else {
F_74 ( V_16 , V_228 ) ;
}
exit:
return V_32 ;
}
T_1 F_77 ( struct V_33 * V_16 )
{
struct V_9 * V_233 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
V_233 = F_32 ( sizeof( struct V_9 ) , V_73 ) ;
V_24 = F_32 ( sizeof( struct V_23 ) , V_73 ) ;
if ( ! V_233 || ! V_24 ) {
F_17 ( V_233 ) ;
F_17 ( V_24 ) ;
return V_31 ;
}
V_24 -> V_26 = V_27 ;
V_24 -> V_41 = NULL ;
F_34 ( V_233 , V_24 , F_13 ( V_22 ) ) ;
return F_14 ( V_2 , V_233 ) ;
}
static void F_78 ( struct V_33 * V_16 )
{
int V_234 = 0 ;
struct V_171 * V_235 ;
struct V_236 * V_237 = & V_16 -> V_238 ;
V_235 = F_79 ( V_16 ) ;
if ( ! V_235 )
return;
if ( V_235 -> V_239 == 0 ) {
T_1 V_240 = 0 ;
F_80 ( V_16 , V_241 , & V_240 ) ;
while ( ! V_240 ) {
F_81 ( 100 ) ;
V_234 ++ ;
if ( V_234 > 10 )
break;
F_80 ( V_16 , V_241 , & V_240 ) ;
}
if ( V_234 <= 10 ) {
V_237 -> V_242 &= ~ F_82 ( 0 ) ;
V_237 -> V_243 &= ~ F_82 ( 0 ) ;
F_83 ( V_16 , V_244 , NULL , false ) ;
} else {
F_84 ( V_16 ) ;
}
}
}
T_1 F_84 ( struct V_33 * V_16 )
{
struct V_9 * V_65 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = & V_16 -> V_43 ;
T_1 V_32 = V_6 ;
V_65 = F_32 ( sizeof( struct V_9 ) , V_97 ) ;
if ( V_65 == NULL ) {
V_32 = V_31 ;
goto exit;
}
V_24 = F_32 ( sizeof( struct V_23 ) , V_97 ) ;
if ( V_24 == NULL ) {
F_17 ( V_65 ) ;
V_32 = V_31 ;
goto exit;
}
V_24 -> V_26 = V_245 ;
V_24 -> V_191 = 0 ;
V_24 -> V_41 = NULL ;
F_34 ( V_65 , V_24 , F_13 ( V_22 ) ) ;
V_32 = F_14 ( V_2 , V_65 ) ;
exit:
return V_32 ;
}
T_1 F_85 ( struct V_33 * V_16 , unsigned char * V_41 )
{
struct V_23 * V_246 ;
if ( ! V_41 )
return V_54 ;
V_246 = (struct V_23 * ) V_41 ;
switch ( V_246 -> V_26 ) {
case V_190 :
F_65 ( V_16 , V_246 -> V_41 , V_246 -> V_191 ) ;
break;
case V_27 :
F_86 ( V_16 ) ;
break;
case V_224 :
F_70 ( V_16 , ( T_1 ) V_246 -> V_191 ) ;
break;
case V_227 :
F_72 ( V_16 , V_246 -> V_191 ) ;
break;
case V_232 :
F_74 ( V_16 , V_246 -> V_191 ) ;
break;
#ifdef F_66
case V_245 :
F_78 ( V_16 ) ;
break;
#endif
default:
break;
}
if ( V_246 -> V_41 && V_246 -> V_191 > 0 )
F_17 ( V_246 -> V_41 ) ;
return V_159 ;
}
void F_87 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_68 * V_69 = & V_16 -> V_70 ;
if ( V_34 -> V_32 == V_51 ) {
F_36 ( & V_69 -> V_86 ,
V_85 + F_37 ( 1 ) ) ;
} else if ( V_34 -> V_32 != V_159 ) {
F_36 ( & V_69 -> V_86 ,
V_85 + F_37 ( 1 ) ) ;
F_22 ( V_45 , V_57 , ( L_15 ) ) ;
}
F_15 ( V_34 ) ;
}
void F_88 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_68 * V_69 = & V_16 -> V_70 ;
if ( V_34 -> V_32 != V_159 ) {
F_89 ( & V_69 -> V_12 ) ;
F_35 ( V_69 , V_71 ) ;
F_90 ( & V_69 -> V_12 ) ;
F_22 ( V_45 , V_57 , ( L_16 ) ) ;
return;
}
F_15 ( V_34 ) ;
}
void F_91 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_68 * V_69 = & V_16 -> V_70 ;
if ( V_34 -> V_32 == V_51 ) {
F_36 ( & V_69 -> V_247 ,
V_85 + F_37 ( 1 ) ) ;
} else if ( V_34 -> V_32 != V_159 ) {
F_22 ( V_45 , V_57 , ( L_17 ) ) ;
F_36 ( & V_69 -> V_247 ,
V_85 + F_37 ( 1 ) ) ;
}
F_15 ( V_34 ) ;
}
void F_92 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_171 * V_165 = NULL ;
struct V_100 * V_248 = NULL ;
struct V_68 * V_69 = & V_16 -> V_70 ;
struct V_91 * V_101 = (struct V_91 * ) V_34 -> V_25 ;
struct V_100 * V_249 = & ( V_69 -> V_250 ) ;
if ( V_34 -> V_32 != V_159 ) {
F_22 ( V_45 , V_57 , ( L_18 ) ) ;
F_36 ( & V_69 -> V_247 ,
V_85 + F_37 ( 1 ) ) ;
}
F_93 ( & V_69 -> V_247 ) ;
F_89 ( & V_69 -> V_12 ) ;
if ( F_30 ( V_69 , V_210 ) ) {
V_165 = F_94 ( & V_16 -> V_238 , V_101 -> V_139 ) ;
if ( ! V_165 ) {
V_165 = F_95 ( & V_16 -> V_238 , V_101 -> V_139 ) ;
if ( V_165 == NULL ) {
F_22 ( V_45 , V_57 , ( L_19 ) ) ;
goto V_251;
}
}
F_96 ( V_16 ) ;
} else {
V_248 = F_97 ( V_69 ) ;
F_89 ( & ( V_69 -> V_252 . V_12 ) ) ;
if ( V_248 == NULL ) {
V_248 = F_98 ( & V_69 -> V_252 ) ;
if ( V_248 == NULL ) {
F_22 ( V_45 , V_57 , ( L_20 ) ) ;
F_90 ( & V_69 -> V_252 . V_12 ) ;
goto V_251;
}
V_248 -> V_253 = V_85 ;
} else {
F_6 ( & ( V_248 -> V_13 ) , & V_69 -> V_252 . V_8 ) ;
}
V_101 -> V_99 = F_43 ( V_101 ) ;
memcpy ( & ( V_248 -> V_117 ) , V_101 , V_101 -> V_99 ) ;
memcpy ( & V_249 -> V_117 , V_101 , ( F_43 ( V_101 ) ) ) ;
F_39 ( V_69 , V_254 ) ;
F_90 ( & V_69 -> V_252 . V_12 ) ;
}
V_251:
F_90 ( & V_69 -> V_12 ) ;
F_15 ( V_34 ) ;
}
void F_99 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_236 * V_237 = & V_16 -> V_238 ;
struct V_169 * V_170 = (struct V_169 * ) ( V_34 -> V_37 ) ;
struct V_171 * V_165 = F_94 ( V_237 , V_170 -> V_174 ) ;
if ( V_165 == NULL ) {
F_22 ( V_45 , V_57 , ( L_21 ) ) ;
goto exit;
}
exit:
F_15 ( V_34 ) ;
}
void F_100 ( struct V_33 * V_16 , struct V_9 * V_34 )
{
struct V_236 * V_237 = & V_16 -> V_238 ;
struct V_68 * V_69 = & V_16 -> V_70 ;
struct V_255 * V_256 = (struct V_255 * ) ( V_34 -> V_25 ) ;
struct V_257 * V_258 = (struct V_257 * ) ( V_34 -> V_37 ) ;
struct V_171 * V_165 = F_94 ( V_237 , V_256 -> V_174 ) ;
if ( V_165 == NULL ) {
F_22 ( V_45 , V_57 , ( L_22 ) ) ;
goto exit;
}
V_165 -> V_259 = V_258 -> V_260 ;
V_165 -> V_261 = V_258 -> V_260 ;
F_89 ( & V_69 -> V_12 ) ;
if ( ( F_30 ( V_69 , V_262 ) == true ) && ( F_30 ( V_69 , V_254 ) == true ) )
F_39 ( V_69 , V_254 ) ;
F_35 ( V_69 , V_71 ) ;
F_90 ( & V_69 -> V_12 ) ;
exit:
F_15 ( V_34 ) ;
}
