int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
F_2 ( & ( V_2 -> V_5 ) , 0 ) ;
F_2 ( & ( V_2 -> V_6 ) , 0 ) ;
F_3 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_8 = 1 ;
V_2 -> V_9 = F_4 ( V_10 + V_11 ) ;
if ( V_2 -> V_9 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_2 -> V_13 = V_2 -> V_9 + V_11 - ( ( V_14 ) ( V_2 -> V_9 ) & ( V_11 - 1 ) ) ;
V_2 -> V_15 = F_4 ( V_16 + 4 ) ;
if ( V_2 -> V_15 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_2 -> V_17 = V_2 -> V_15 + 4 - ( ( V_14 ) ( V_2 -> V_15 ) & 3 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
exit:
return V_3 ;
}
int F_5 ( struct V_21 * V_22 )
{
int V_3 = V_4 ;
F_6 ( & V_22 -> V_23 , 0 ) ;
V_22 -> V_24 = 0 ;
F_7 ( & V_22 -> V_25 , V_26 ) ;
V_22 -> V_27 = false ;
V_22 -> V_28 = F_8 ( V_29 + 1 ) ;
return V_3 ;
}
void F_9 ( struct V_21 * V_22 )
{
F_10 ( V_30 , V_31 , ( L_1 ) ) ;
F_11 ( & V_22 -> V_25 ) ;
while ( V_22 -> V_27 )
F_12 ( 10 ) ;
while ( ! F_13 ( V_22 -> V_28 ) ) {
void * V_32 = F_14 ( V_22 -> V_28 ) ;
if ( V_32 != NULL && V_32 != ( void * ) V_22 )
F_15 ( V_32 ) ;
}
F_10 ( V_30 , V_31 , ( L_2 ) ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_15 ( V_2 -> V_9 ) ;
F_15 ( V_2 -> V_15 ) ;
}
}
int F_17 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
unsigned long V_37 ;
if ( V_36 == NULL )
goto exit;
F_18 ( & V_34 -> V_38 , V_37 ) ;
F_19 ( & V_36 -> V_39 , & V_34 -> V_34 ) ;
F_20 ( & V_34 -> V_38 , V_37 ) ;
exit:
return V_4 ;
}
struct V_35 * F_21 ( struct V_33 * V_34 )
{
unsigned long V_37 ;
struct V_35 * V_36 ;
F_18 ( & V_34 -> V_38 , V_37 ) ;
if ( F_22 ( & ( V_34 -> V_34 ) ) ) {
V_36 = NULL ;
} else {
V_36 = F_23 ( ( & V_34 -> V_34 ) -> V_40 , struct V_35 , V_39 ) ;
F_24 ( & V_36 -> V_39 ) ;
}
F_20 ( & V_34 -> V_38 , V_37 ) ;
return V_36 ;
}
T_1 F_25 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
T_1 F_26 ( struct V_21 * V_22 )
{
int V_3 ;
V_3 = F_5 ( V_22 ) ;
return V_3 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_10 ( V_30 , V_31 , ( L_3 ) ) ;
F_16 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
T_2 V_41 = false ;
if ( ( V_2 -> V_42 -> V_43 . V_44 ) &&
( ! V_2 -> V_42 -> V_45 . V_46 ) ) {
if ( V_35 -> V_47 == F_29 ( V_48 ) ) {
struct V_49 * V_50 = (struct V_49 * ) V_35 -> V_51 ;
if ( V_50 -> V_52 == V_53 )
V_41 = true ;
}
}
if ( V_35 -> V_47 == F_29 ( V_54 ) )
V_41 = true ;
if ( ( ! V_2 -> V_42 -> V_55 && ! V_41 ) ||
! V_2 -> V_56 )
return V_12 ;
return V_4 ;
}
T_1 F_30 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
int V_3 = V_12 ;
struct V_57 * V_42 = V_2 -> V_42 ;
if ( V_35 == NULL )
goto exit;
V_35 -> V_42 = V_42 ;
V_3 = F_28 ( V_2 , V_35 ) ;
if ( V_12 == V_3 ) {
F_31 ( V_35 ) ;
goto exit;
}
V_3 = F_17 ( & V_2 -> V_7 , V_35 ) ;
if ( V_3 == V_4 )
F_32 ( & V_2 -> V_5 ) ;
exit:
return V_3 ;
}
struct V_35 * F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
V_35 = F_21 ( & V_2 -> V_7 ) ;
return V_35 ;
}
void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_19 ++ ;
}
void F_31 ( struct V_35 * V_58 )
{
if ( ( V_58 -> V_47 != V_59 ) && ( V_58 -> V_47 != V_60 ) ) {
F_15 ( V_58 -> V_51 ) ;
}
if ( V_58 -> V_61 != NULL ) {
if ( V_58 -> V_62 != 0 ) {
F_15 ( V_58 -> V_61 ) ;
}
}
F_15 ( V_58 ) ;
}
int F_35 ( void * V_63 )
{
T_2 V_64 ;
struct V_35 * V_58 ;
T_2 * V_65 ;
T_2 (* F_36)( struct V_57 * V_42 , T_2 * V_66 );
void (* F_37)( struct V_57 * V_67 , struct V_35 * V_58 );
struct V_57 * V_42 = (struct V_57 * ) V_63 ;
struct V_1 * V_2 = & ( V_42 -> V_68 ) ;
F_38 ( L_4 ) ;
V_65 = V_2 -> V_13 ;
V_2 -> V_56 = true ;
F_32 ( & V_2 -> V_6 ) ;
F_10 ( V_30 , V_31 , ( L_5 ) ) ;
while ( 1 ) {
if ( F_39 ( & V_2 -> V_5 ) == V_12 )
break;
if ( V_42 -> V_69 ||
V_42 -> V_70 ) {
F_40 ( L_6 ,
V_71 , V_42 -> V_69 , V_42 -> V_70 , __LINE__ ) ;
break;
}
V_72:
if ( V_42 -> V_69 ||
V_42 -> V_70 ) {
F_40 ( L_6 ,
V_71 , V_42 -> V_69 , V_42 -> V_70 , __LINE__ ) ;
break;
}
V_58 = F_33 ( V_2 ) ;
if ( ! V_58 )
continue;
if ( V_12 == F_28 ( V_2 , V_58 ) ) {
V_58 -> V_3 = V_73 ;
goto V_74;
}
V_2 -> V_18 ++ ;
V_58 -> V_75 = F_41 ( ( V_58 -> V_75 ) ) ;
memcpy ( V_65 , V_58 -> V_51 , V_58 -> V_75 ) ;
if ( V_58 -> V_47 < F_42 ( V_76 ) ) {
F_36 = V_76 [ V_58 -> V_47 ] . V_77 ;
if ( F_36 ) {
V_64 = F_36 ( V_58 -> V_42 , V_65 ) ;
V_58 -> V_3 = V_64 ;
}
V_2 -> V_8 ++ ;
} else {
V_58 -> V_3 = V_78 ;
}
F_36 = NULL ;
V_74:
if ( V_58 -> V_47 < F_42 ( V_79 ) ) {
F_37 = V_79 [ V_58 -> V_47 ] . V_80 ;
if ( F_37 == NULL ) {
F_10 ( V_30 , V_31 , ( L_7 , F_37 , V_58 -> V_47 ) ) ;
F_31 ( V_58 ) ;
} else {
F_37 ( V_58 -> V_42 , V_58 ) ;
}
} else {
F_10 ( V_30 , V_81 , ( L_8 , V_71 , V_58 -> V_47 ) ) ;
F_31 ( V_58 ) ;
}
F_43 () ;
goto V_72;
}
V_2 -> V_56 = false ;
do {
V_58 = F_33 ( V_2 ) ;
if ( V_58 == NULL )
break;
F_31 ( V_58 ) ;
} while ( 1 );
F_32 ( & V_2 -> V_6 ) ;
F_44 ( NULL , 0 ) ;
}
T_2 F_45 ( struct V_57 * V_42 , T_3 V_82 )
{
struct V_35 * V_83 ;
struct V_84 * V_85 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_64 = V_4 ;
V_83 = F_46 ( sizeof( struct V_35 ) , V_86 ) ;
if ( V_83 == NULL ) {
V_64 = V_12 ;
goto exit;
}
V_85 = F_46 ( sizeof( struct V_84 ) , V_86 ) ;
if ( V_85 == NULL ) {
F_15 ( V_83 ) ;
V_64 = V_12 ;
goto exit;
}
V_85 -> V_82 = V_82 ;
F_47 ( V_83 , V_85 , F_29 ( V_87 ) ) ;
V_64 = F_30 ( V_2 , V_83 ) ;
exit:
return V_64 ;
}
T_2 F_48 ( struct V_57 * V_42 , struct V_88 * V_89 , int V_90 ,
struct V_91 * V_92 , int V_93 )
{
T_2 V_3 = V_12 ;
struct V_35 * V_83 ;
struct V_94 * V_95 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_96 * V_97 = & V_42 -> V_98 ;
if ( F_49 ( V_97 , V_99 ) == true )
F_50 ( V_42 , V_100 , 1 ) ;
if ( F_49 ( V_97 , V_99 ) == true )
F_51 ( V_42 , V_101 , 1 ) ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL )
return V_12 ;
V_95 = (struct V_94 * ) F_4 ( sizeof( struct V_94 ) ) ;
if ( V_95 == NULL ) {
F_15 ( V_83 ) ;
return V_12 ;
}
F_52 ( V_42 , false ) ;
F_10 ( V_30 , V_31 , ( L_9 , V_71 ) ) ;
F_47 ( V_83 , V_95 , F_29 ( V_102 ) ) ;
V_95 -> V_103 = V_97 -> V_103 ;
if ( V_89 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_90 && V_104 < V_105 ; V_104 ++ ) {
if ( V_89 [ V_104 ] . V_106 ) {
memcpy ( & V_95 -> V_89 [ V_104 ] , & V_89 [ V_104 ] , sizeof( struct V_88 ) ) ;
V_95 -> V_90 ++ ;
}
}
}
if ( V_92 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_93 && V_104 < V_107 ; V_104 ++ ) {
if ( V_92 [ V_104 ] . V_108 && ! ( V_92 [ V_104 ] . V_109 & V_110 ) ) {
memcpy ( & V_95 -> V_92 [ V_104 ] , & V_92 [ V_104 ] , sizeof( struct V_91 ) ) ;
V_95 -> V_93 ++ ;
}
}
}
F_53 ( V_97 , V_111 ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
if ( V_3 == V_4 ) {
V_97 -> V_112 = V_113 ;
F_54 ( & V_97 -> V_114 , V_115 ) ;
F_55 ( V_42 , V_116 ) ;
V_97 -> V_117 = V_118 ;
} else {
F_56 ( V_97 , V_111 ) ;
}
return V_3 ;
}
T_2 F_57 ( struct V_57 * V_42 , T_2 * V_119 )
{
struct V_35 * V_83 ;
struct V_120 * V_121 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_121 = (struct V_120 * ) F_4 ( sizeof( struct V_120 ) ) ;
if ( V_121 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_121 , F_29 ( V_122 ) ) ;
V_121 -> V_123 = 5 ;
memcpy ( V_121 -> V_124 , V_119 , V_125 ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_58 ( struct V_57 * V_42 , T_2 * V_119 )
{
struct V_35 * V_83 ;
struct V_126 * V_127 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_127 = (struct V_126 * ) F_4 ( sizeof( struct V_126 ) ) ;
if ( V_127 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_127 , V_128 ) ;
memcpy ( V_127 -> V_129 , V_119 , V_125 ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_59 ( struct V_57 * V_42 , T_2 V_130 , T_2 V_92 )
{
struct V_35 * V_83 ;
struct V_131 * V_132 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_132 = (struct V_131 * ) F_4 ( sizeof( struct V_131 ) ) ;
if ( V_132 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_132 , V_133 ) ;
F_10 ( V_30 , V_31 , ( L_10 , V_92 , V_130 ) ) ;
V_132 -> V_130 = V_130 ;
V_132 -> V_134 = V_92 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_60 ( struct V_57 * V_42 , T_2 V_135 , T_2 V_136 )
{
struct V_35 * V_83 ;
struct V_137 * V_138 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_138 = (struct V_137 * ) F_4 ( sizeof( struct V_137 ) ) ;
if ( V_138 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_138 , F_29 ( V_139 ) ) ;
V_138 -> V_135 = V_135 ;
V_138 -> V_140 = V_136 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_61 ( struct V_57 * V_42 , T_2 V_135 , T_2 * V_141 )
{
struct V_35 * V_83 ;
struct V_142 * V_143 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_143 = (struct V_142 * ) F_4 ( sizeof( struct V_142 ) ) ;
if ( V_143 == NULL ) {
F_15 ( V_83 ) ;
return V_12 ;
}
F_62 ( & V_83 -> V_39 ) ;
V_83 -> V_47 = F_29 ( V_144 ) ;
V_83 -> V_51 = ( unsigned char * ) V_143 ;
V_83 -> V_75 = sizeof( struct V_142 ) ;
V_83 -> V_61 = V_141 ;
V_83 -> V_62 = sizeof( struct V_145 ) ;
V_143 -> V_135 = V_135 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_63 ( struct V_57 * V_42 , T_2 V_135 , T_1 V_136 )
{
struct V_35 * V_83 ;
struct V_146 * V_147 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_147 = (struct V_146 * ) F_4 ( sizeof( struct V_146 ) ) ;
if ( V_147 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_147 , F_29 ( V_148 ) ) ;
V_147 -> V_135 = V_135 ;
V_147 -> V_140 = V_136 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_64 ( struct V_57 * V_42 , T_2 V_135 , T_2 * V_141 )
{
struct V_35 * V_83 ;
struct V_149 * V_150 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_150 = (struct V_149 * ) F_4 ( sizeof( struct V_149 ) ) ;
if ( V_150 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_62 ( & V_83 -> V_39 ) ;
V_83 -> V_47 = F_29 ( V_151 ) ;
V_83 -> V_51 = ( unsigned char * ) V_150 ;
V_83 -> V_75 = sizeof( struct V_149 ) ;
V_83 -> V_61 = V_141 ;
V_83 -> V_62 = sizeof( struct V_152 ) ;
V_150 -> V_135 = V_135 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
void F_65 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
F_15 ( V_58 -> V_51 ) ;
F_15 ( V_58 ) ;
if ( V_42 -> V_45 . V_153 == 1 )
V_42 -> V_154 . V_155 . V_156 = true ;
}
void F_66 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
F_15 ( V_58 -> V_51 ) ;
F_15 ( V_58 ) ;
if ( V_42 -> V_45 . V_153 == 1 )
V_42 -> V_154 . V_155 . V_156 = true ;
}
T_2 F_67 ( struct V_57 * V_42 )
{
struct V_35 * V_58 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_96 * V_97 = & V_42 -> V_98 ;
struct V_157 * V_158 = & V_42 -> V_45 . V_159 ;
T_2 V_3 = V_4 ;
F_55 ( V_42 , V_160 ) ;
if ( V_97 -> V_161 . V_106 == 0 )
F_10 ( V_30 , V_31 , ( L_11 , V_97 -> V_161 . V_162 ) ) ;
else
F_10 ( V_30 , V_31 , ( L_12 , V_97 -> V_161 . V_162 ) ) ;
V_58 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_58 == NULL ) {
V_3 = V_12 ;
goto exit;
}
F_62 ( & V_58 -> V_39 ) ;
V_58 -> V_47 = V_60 ;
V_58 -> V_51 = ( unsigned char * ) V_158 ;
V_58 -> V_75 = F_68 ( (struct V_157 * ) V_158 ) ;
V_58 -> V_61 = NULL ;
V_58 -> V_62 = 0 ;
V_158 -> V_163 = V_58 -> V_75 ;
V_3 = F_30 ( V_2 , V_58 ) ;
exit:
return V_3 ;
}
T_2 F_69 ( struct V_57 * V_42 , unsigned char * V_164 , unsigned int V_165 )
{
struct V_35 * V_58 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_58 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_58 == NULL ) {
V_3 = V_12 ;
goto exit;
}
F_62 ( & V_58 -> V_39 ) ;
V_58 -> V_47 = F_29 ( V_166 ) ;
V_58 -> V_51 = V_164 ;
V_58 -> V_75 = V_165 ;
V_58 -> V_61 = NULL ;
V_58 -> V_62 = 0 ;
V_3 = F_30 ( V_2 , V_58 ) ;
exit:
return V_3 ;
}
T_2 F_70 ( struct V_57 * V_42 , struct V_167 * V_168 )
{
T_2 V_3 = V_4 ;
T_3 V_169 = 0 ;
struct V_157 * V_170 ;
struct V_35 * V_58 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_96 * V_97 = & V_42 -> V_98 ;
struct V_171 * V_172 = & V_97 -> V_173 ;
struct V_174 * V_175 = & V_42 -> V_176 ;
struct V_177 * V_178 = & V_42 -> V_45 ;
struct V_179 * V_180 = & V_97 -> V_181 ;
enum V_182 V_183 = V_168 -> V_184 . V_185 ;
struct V_186 * V_187 = & V_42 -> V_188 ;
struct V_189 * V_190 = & ( V_187 -> V_191 ) ;
F_55 ( V_42 , V_160 ) ;
if ( V_97 -> V_161 . V_106 == 0 )
F_10 ( V_30 , V_31 , ( L_13 ) ) ;
else
F_10 ( V_30 , V_192 , ( L_14 , V_97 -> V_161 . V_162 ) ) ;
V_58 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_58 == NULL ) {
V_3 = V_12 ;
F_10 ( V_30 , V_81 , ( L_15 ) ) ;
goto exit;
}
V_169 = sizeof( struct V_157 ) ;
if ( ! F_49 ( V_97 , V_193 | V_194 ) ) {
switch ( V_183 ) {
case V_195 :
F_53 ( V_97 , V_194 ) ;
break;
case V_196 :
F_53 ( V_97 , V_193 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
break;
}
}
V_170 = (struct V_157 * ) & V_175 -> V_200 ;
if ( V_170 == NULL ) {
if ( V_58 != NULL )
F_15 ( V_58 ) ;
V_3 = V_12 ;
F_10 ( V_30 , V_81 , ( L_16 ) ) ;
goto exit;
}
F_71 ( V_170 , 0 , V_169 ) ;
memcpy ( V_170 , & V_168 -> V_184 , F_68 ( & V_168 -> V_184 ) ) ;
V_175 -> V_201 [ 0 ] = ( unsigned char ) V_170 -> V_202 ;
if ( ( V_170 -> V_202 - 12 ) < ( 256 - 1 ) )
memcpy ( & V_175 -> V_201 [ 1 ] , & V_170 -> V_203 [ 12 ] , V_170 -> V_202 - 12 ) ;
else
memcpy ( & V_175 -> V_201 [ 1 ] , & V_170 -> V_203 [ 12 ] , ( 256 - 1 ) ) ;
V_170 -> V_202 = 0 ;
if ( ! V_97 -> V_204 )
memcpy ( & V_97 -> V_205 [ 0 ] , & V_168 -> V_184 . V_206 [ 0 ] , V_207 ) ;
V_170 -> V_202 = F_72 ( V_42 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] , V_168 -> V_184 . V_202 ) ;
V_172 -> V_208 = 0 ;
if ( V_178 -> V_209 ) {
T_1 V_210 ;
V_210 = F_73 ( V_42 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] , V_168 -> V_184 . V_202 , V_170 -> V_202 ) ;
if ( V_170 -> V_202 != V_210 ) {
V_170 -> V_202 = V_210 ;
V_172 -> V_208 = 1 ;
} else {
V_172 -> V_208 = 0 ;
}
}
V_180 -> V_211 = false ;
if ( V_178 -> V_212 ) {
if ( ( V_42 -> V_176 . V_213 != V_214 ) &&
( V_42 -> V_176 . V_213 != V_215 ) &&
( V_42 -> V_176 . V_213 != V_216 ) ) {
F_74 ( V_42 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] ,
V_168 -> V_184 . V_202 , & V_170 -> V_202 ) ;
}
}
V_190 -> V_217 = F_75 ( V_168 -> V_184 . V_203 , V_168 -> V_184 . V_202 ) ;
if ( V_190 -> V_217 == V_218 )
V_42 -> V_43 . V_219 = 0 ;
else
V_42 -> V_43 . V_219 = V_42 -> V_45 . V_219 ;
F_40 ( L_17 , V_71 , V_42 -> V_43 . V_219 ) ;
V_58 -> V_75 = F_68 ( V_170 ) ;
F_62 ( & V_58 -> V_39 ) ;
V_58 -> V_47 = V_59 ;
V_58 -> V_51 = ( unsigned char * ) V_170 ;
V_58 -> V_61 = NULL ;
V_58 -> V_62 = 0 ;
V_3 = F_30 ( V_2 , V_58 ) ;
exit:
return V_3 ;
}
T_2 F_76 ( struct V_57 * V_42 , T_1 V_220 , bool V_221 )
{
struct V_35 * V_222 = NULL ;
struct V_223 * V_224 = NULL ;
struct V_1 * V_68 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
F_10 ( V_30 , V_192 , ( L_18 ) ) ;
V_224 = (struct V_223 * ) F_4 ( sizeof( * V_224 ) ) ;
if ( V_224 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_224 -> V_220 = V_220 ;
if ( V_221 ) {
V_222 = (struct V_35 * ) F_4 ( sizeof( * V_222 ) ) ;
if ( V_222 == NULL ) {
V_3 = V_12 ;
F_15 ( V_224 ) ;
goto exit;
}
F_47 ( V_222 , V_224 , V_225 ) ;
V_3 = F_30 ( V_68 , V_222 ) ;
} else {
if ( V_226 != F_77 ( V_42 , ( T_2 * ) V_224 ) )
V_3 = V_12 ;
F_15 ( V_224 ) ;
}
exit:
return V_3 ;
}
T_2 F_78 ( struct V_57 * V_42 , enum V_182 V_227 )
{
struct V_35 * V_83 ;
struct V_228 * V_229 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = false ;
goto exit;
}
V_229 = (struct V_228 * ) F_4 ( sizeof( struct V_228 ) ) ;
if ( V_229 == NULL ) {
F_15 ( V_83 ) ;
V_3 = false ;
goto exit;
}
F_47 ( V_83 , V_229 , V_230 ) ;
V_229 -> V_231 = ( T_2 ) V_227 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_79 ( struct V_57 * V_42 , T_2 * V_232 , T_2 V_233 )
{
struct V_35 * V_83 ;
struct V_234 * V_235 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_236 * V_237 = NULL ;
struct V_96 * V_97 = & V_42 -> V_98 ;
struct V_174 * V_175 = & V_42 -> V_176 ;
struct V_238 * V_239 = (struct V_238 * ) V_232 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_235 = (struct V_234 * ) F_4 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_237 = (struct V_236 * ) F_4 ( sizeof( struct V_236 ) ) ;
if ( V_237 == NULL ) {
F_15 ( V_83 ) ;
F_15 ( V_235 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_235 , V_240 ) ;
V_83 -> V_61 = ( T_2 * ) V_237 ;
V_83 -> V_62 = sizeof( struct V_236 ) ;
F_80 ( V_235 -> V_241 , V_239 -> V_242 ) ;
if ( F_49 ( V_97 , V_193 ) )
V_235 -> V_243 = ( unsigned char ) V_175 -> V_213 ;
else
F_81 ( V_175 , V_239 , V_235 -> V_243 , false ) ;
if ( V_233 )
memcpy ( & V_235 -> V_244 , & V_239 -> V_245 , 16 ) ;
else
memcpy ( & V_235 -> V_244 , & V_175 -> V_246 [ V_175 -> V_247 ] . V_248 , 16 ) ;
V_42 -> V_176 . V_249 = true ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_82 ( struct V_57 * V_42 , T_2 * V_232 , T_2 V_250 , T_2 V_221 )
{
struct V_35 * V_83 ;
struct V_234 * V_235 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_236 * V_237 = NULL ;
struct V_238 * V_239 = (struct V_238 * ) V_232 ;
T_2 V_3 = V_4 ;
if ( ! V_221 ) {
F_83 ( V_42 , V_250 ) ;
} else {
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_235 = (struct V_234 * ) F_4 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_237 = (struct V_236 * ) F_4 ( sizeof( struct V_236 ) ) ;
if ( V_237 == NULL ) {
F_15 ( V_83 ) ;
F_15 ( V_235 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_235 , V_240 ) ;
V_83 -> V_61 = ( T_2 * ) V_237 ;
V_83 -> V_62 = sizeof( struct V_236 ) ;
F_80 ( V_235 -> V_241 , V_239 -> V_242 ) ;
V_235 -> V_243 = V_251 ;
V_235 -> V_252 = V_250 ;
V_3 = F_30 ( V_2 , V_83 ) ;
}
exit:
return V_3 ;
}
T_2 F_84 ( struct V_57 * V_42 , struct V_253 * V_254 )
{
struct V_35 * V_83 ;
struct V_253 * V_255 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_255 = (struct V_253 * ) F_4 ( sizeof( struct V_253 ) ) ;
if ( V_255 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_83 , V_255 , F_29 ( V_256 ) ) ;
memcpy ( V_255 , V_254 , sizeof( struct V_253 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_85 ( struct V_57 * V_42 , struct V_257 * V_141 )
{
struct V_35 * V_83 ;
struct V_258 * V_259 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_259 = (struct V_258 * ) F_4 ( sizeof( struct V_258 ) ) ;
if ( V_259 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
F_62 ( & V_83 -> V_39 ) ;
V_83 -> V_47 = F_29 ( V_260 ) ;
V_83 -> V_51 = ( unsigned char * ) V_259 ;
V_83 -> V_75 = sizeof( struct V_258 ) ;
V_83 -> V_61 = ( T_2 * ) V_141 ;
V_83 -> V_62 = sizeof( struct V_257 ) ;
V_259 -> V_261 = 0x0 ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_86 ( struct V_57 * V_42 , T_2 * V_262 )
{
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_35 * V_83 ;
struct V_263 * V_264 ;
struct V_236 * V_265 = NULL ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_264 = (struct V_263 * ) F_4 ( sizeof( struct V_263 ) ) ;
if ( V_264 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_265 = (struct V_236 * ) F_4 ( sizeof( struct V_266 ) ) ;
if ( V_265 == NULL ) {
F_15 ( V_83 ) ;
F_15 ( V_264 ) ;
return V_12 ;
}
F_47 ( V_83 , V_264 , V_267 ) ;
V_83 -> V_61 = ( T_2 * ) V_265 ;
V_83 -> V_62 = sizeof( struct V_266 ) ;
F_80 ( V_264 -> V_241 , V_262 ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_87 ( struct V_57 * V_42 , T_2 V_268 , T_2 * V_241 )
{
struct V_1 * V_2 = & V_42 -> V_68 ;
struct V_35 * V_83 ;
struct V_269 * V_270 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_270 = (struct V_269 * ) F_4 ( sizeof( struct V_269 ) ) ;
if ( V_270 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_270 -> V_268 = V_268 ;
memcpy ( V_270 -> V_241 , V_241 , V_207 ) ;
F_47 ( V_83 , V_270 , F_29 ( V_271 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_88 ( struct V_57 * V_42 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_272 ;
V_50 -> V_273 = 0 ;
V_50 -> V_66 = ( T_2 * ) V_42 ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_89 ( struct V_57 * V_42 , T_2 V_92 , T_2 V_274 , T_2 V_275 , T_2 V_221 )
{
struct V_35 * V_276 ;
struct V_277 * V_277 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
F_40 ( V_278 L_19 ,
F_90 ( V_42 -> V_279 ) , V_92 , V_274 , V_275 ) ;
V_277 = (struct V_277 * ) F_4 ( sizeof( * V_277 ) ) ;
if ( V_277 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_277 -> V_92 = V_92 ;
V_277 -> V_274 = V_274 ;
V_277 -> V_275 = V_275 ;
if ( V_221 ) {
V_276 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_276 == NULL ) {
F_15 ( V_277 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_276 , V_277 , F_29 ( V_280 ) ) ;
V_3 = F_30 ( V_2 , V_276 ) ;
} else {
if ( V_226 != F_91 ( V_42 , ( T_2 * ) V_277 ) )
V_3 = V_12 ;
F_15 ( V_277 ) ;
}
exit:
F_40 ( V_278 L_20 , F_90 ( V_42 -> V_279 ) , V_3 ) ;
return V_3 ;
}
T_2 F_92 ( struct V_57 * V_42 , T_2 V_281 , T_2 V_221 )
{
struct V_35 * V_276 ;
struct V_282 * V_283 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
F_10 ( V_30 , V_192 , ( L_21 ) ) ;
if ( ! F_93 ( V_281 ) ) {
V_3 = V_12 ;
goto exit;
}
V_283 = (struct V_282 * ) F_4 ( sizeof( struct V_282 ) ) ;
if ( V_283 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_283 -> V_284 = V_281 ;
if ( V_221 ) {
V_276 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_276 == NULL ) {
F_15 ( V_283 ) ;
V_3 = V_12 ;
goto exit;
}
F_47 ( V_276 , V_283 , F_29 ( V_54 ) ) ;
V_3 = F_30 ( V_2 , V_276 ) ;
} else {
if ( V_226 != F_94 ( V_42 , ( unsigned char * ) V_283 ) )
V_3 = V_12 ;
F_15 ( V_283 ) ;
}
if ( V_3 == V_4 )
V_42 -> V_98 . V_285 = V_281 ;
exit:
return V_3 ;
}
T_2 F_95 ( struct V_57 * V_42 , struct V_286 * V_287 )
{
struct V_35 * V_276 ;
struct V_288 * V_289 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
F_10 ( V_30 , V_192 , ( L_22 ) ) ;
V_276 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_276 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_289 = (struct V_288 * ) F_4 ( sizeof( struct V_288 ) ) ;
if ( V_289 == NULL ) {
F_15 ( V_276 ) ;
V_3 = V_12 ;
goto exit;
}
V_289 -> V_287 = V_287 ;
F_47 ( V_276 , V_289 , F_29 ( V_290 ) ) ;
V_3 = F_30 ( V_2 , V_276 ) ;
exit:
return V_3 ;
}
T_2 F_96 ( struct V_57 * V_42 , T_2 V_291 )
{
struct V_35 * V_276 ;
struct V_292 * V_293 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
F_10 ( V_30 , V_192 , ( L_23 ) ) ;
V_276 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_276 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_293 = (struct V_292 * ) F_4 ( sizeof( struct V_292 ) ) ;
if ( V_293 == NULL ) {
F_15 ( V_276 ) ;
V_3 = V_12 ;
goto exit;
}
V_293 -> V_291 = V_291 ;
F_47 ( V_276 , V_293 , F_29 ( V_294 ) ) ;
V_3 = F_30 ( V_2 , V_276 ) ;
exit:
return V_3 ;
}
T_2 F_97 ( struct V_57 * V_42 , T_2 * V_241 , T_2 V_295 )
{
return V_4 ;
}
static void F_98 ( struct V_57 * V_42 )
{
T_2 V_296 ;
T_2 V_297 = false , V_298 = false , V_299 = false ;
T_2 V_300 = false , V_301 = false , V_302 = false ;
struct V_96 * V_97 = & ( V_42 -> V_98 ) ;
if ( F_49 ( V_97 , V_99 ) ) {
if ( V_97 -> V_303 . V_304 > 100 ||
V_97 -> V_303 . V_305 > 100 ) {
V_297 = true ;
if ( V_97 -> V_303 . V_304 > V_97 -> V_303 . V_305 )
V_299 = true ;
else
V_298 = true ;
}
if ( V_97 -> V_303 . V_304 > 4000 ||
V_97 -> V_303 . V_305 > 4000 ) {
V_300 = true ;
if ( V_97 -> V_303 . V_304 > V_97 -> V_303 . V_305 )
V_301 = true ;
else
V_302 = true ;
}
if ( ( ( V_97 -> V_303 . V_306 + V_97 -> V_303 . V_305 ) > 8 ) ||
( V_97 -> V_303 . V_306 > 2 ) )
V_296 = false ;
else
V_296 = true ;
if ( V_296 )
F_99 ( V_42 ) ;
else
F_100 ( V_42 ) ;
} else {
F_100 ( V_42 ) ;
}
V_97 -> V_303 . V_304 = 0 ;
V_97 -> V_303 . V_305 = 0 ;
V_97 -> V_303 . V_306 = 0 ;
V_97 -> V_303 . V_297 = V_297 ;
V_97 -> V_303 . V_298 = V_298 ;
V_97 -> V_303 . V_299 = V_299 ;
V_97 -> V_303 . V_300 = V_300 ;
V_97 -> V_303 . V_301 = V_301 ;
V_97 -> V_303 . V_302 = V_302 ;
}
static void F_101 ( struct V_57 * V_42 , T_2 * V_66 , int V_165 )
{
struct V_96 * V_97 ;
V_42 = (struct V_57 * ) V_66 ;
V_97 = & ( V_42 -> V_98 ) ;
#ifdef F_102
if ( F_49 ( V_97 , V_307 ) == true )
F_103 ( V_42 ) ;
#endif
F_104 ( V_42 ) ;
F_105 ( V_42 ) ;
F_98 ( V_42 ) ;
F_106 ( V_42 ) ;
}
static void F_107 ( struct V_57 * V_42 , T_2 V_308 )
{
struct V_309 * V_310 = & V_42 -> V_43 ;
struct V_96 * V_97 = & ( V_42 -> V_98 ) ;
T_2 V_311 ;
if ( ( F_49 ( V_97 , V_312 ) == true ) ||
( F_49 ( V_97 , V_194 ) == true ) )
return;
switch ( V_308 ) {
case V_100 :
if ( F_49 ( V_97 , V_99 ) == true ) {
F_100 ( V_42 ) ;
}
break;
case V_313 :
F_100 ( V_42 ) ;
break;
case V_314 :
V_311 = 1 ;
V_42 -> V_43 . V_315 = 0 ;
F_108 ( V_42 , V_316 , ( T_2 * ) ( & V_311 ) ) ;
break;
case V_317 :
V_311 = 0 ;
F_100 ( V_42 ) ;
F_108 ( V_42 , V_316 , ( T_2 * ) ( & V_311 ) ) ;
break;
case V_318 :
V_310 -> V_319 = V_113 ;
F_100 ( V_42 ) ;
break;
case V_320 :
F_100 ( V_42 ) ;
break;
default:
break;
}
}
T_2 F_50 ( struct V_57 * V_42 , T_2 V_308 , T_2 V_221 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
if ( V_221 ) {
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_321 ;
V_50 -> V_273 = V_308 ;
V_50 -> V_66 = NULL ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
} else {
F_107 ( V_42 , V_308 ) ;
}
exit:
return V_3 ;
}
static void F_109 ( struct V_57 * V_42 , T_4 V_322 )
{
F_108 ( V_42 , V_323 , ( T_2 * ) ( & V_322 ) ) ;
}
T_2 F_110 ( struct V_57 * V_42 , T_4 V_322 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_324 ;
V_50 -> V_273 = V_322 ;
V_50 -> V_66 = NULL ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
static void F_111 ( struct V_57 * V_42 , T_2 V_325 )
{
F_108 ( V_42 , V_326 , ( T_2 * ) ( & V_325 ) ) ;
}
T_2 F_112 ( struct V_57 * V_42 , T_2 V_325 , T_2 V_221 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_327 ;
T_2 V_3 = V_4 ;
F_113 ( V_42 , V_328 , & V_327 ) ;
if ( ! V_327 )
return V_3 ;
if ( V_221 ) {
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_329 ;
V_50 -> V_273 = V_325 ;
V_50 -> V_66 = NULL ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
} else {
F_111 ( V_42 , V_325 ) ;
}
exit:
return V_3 ;
}
static void F_114 ( struct V_57 * V_42 , T_2 * V_66 , int V_165 )
{
F_115 ( V_42 ) ;
}
T_2 F_116 ( struct V_57 * V_42 , int V_330 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_331 * V_332 = & ( V_42 -> V_333 ) ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
if ( F_117 ( V_332 , V_334 ) )
return V_3 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_335 ;
V_50 -> V_273 = V_330 ;
V_50 -> V_66 = NULL ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_118 ( struct V_57 * V_42 )
{
struct V_35 * V_336 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_336 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_336 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_336 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_53 ;
V_50 -> V_66 = NULL ;
F_47 ( V_336 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_336 ) ;
exit:
return V_3 ;
}
static void F_119 ( struct V_57 * V_42 )
{
int V_337 = 0 ;
struct V_238 * V_338 ;
struct V_339 * V_340 = & V_42 -> V_341 ;
V_338 = F_120 ( V_42 ) ;
if ( ! V_338 )
return;
if ( V_338 -> V_342 == 0 ) {
T_2 V_136 = 0 ;
F_121 ( V_42 , V_343 , & V_136 ) ;
while ( ! V_136 ) {
F_12 ( 100 ) ;
V_337 ++ ;
if ( V_337 > 10 )
break;
F_121 ( V_42 , V_343 , & V_136 ) ;
}
if ( V_337 <= 10 ) {
V_340 -> V_344 &= ~ F_122 ( 0 ) ;
V_340 -> V_345 &= ~ F_122 ( 0 ) ;
F_123 ( V_42 , V_346 , NULL , false ) ;
} else {
F_124 ( V_42 ) ;
}
}
}
T_2 F_124 ( struct V_57 * V_42 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_347 ;
V_50 -> V_273 = 0 ;
V_50 -> V_66 = NULL ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
T_2 F_125 ( struct V_57 * V_42 , T_2 * V_348 )
{
struct V_35 * V_83 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = & V_42 -> V_68 ;
T_2 V_3 = V_4 ;
V_83 = (struct V_35 * ) F_4 ( sizeof( struct V_35 ) ) ;
if ( V_83 == NULL ) {
V_3 = V_12 ;
goto exit;
}
V_50 = (struct V_49 * ) F_4 ( sizeof( struct V_49 ) ) ;
if ( V_50 == NULL ) {
F_15 ( V_83 ) ;
V_3 = V_12 ;
goto exit;
}
V_50 -> V_52 = V_349 ;
V_50 -> V_273 = V_348 ? 16 : 0 ;
V_50 -> V_66 = V_348 ;
F_47 ( V_83 , V_50 , F_29 ( V_48 ) ) ;
V_3 = F_30 ( V_2 , V_83 ) ;
exit:
return V_3 ;
}
static T_5 F_126 ( struct V_57 * V_57 , struct V_350 * V_348 , T_6 V_351 )
{
T_5 V_64 = V_12 ;
T_2 V_352 [ 16 ] ;
if ( ! V_348 ) {
if ( F_127 ( V_57 , V_352 ) == V_4 ) {
V_348 = (struct V_350 * ) V_352 ;
if ( V_351 && V_351 ( V_348 -> V_252 ) == false )
goto exit;
V_64 = F_128 ( V_57 , V_348 ) ;
}
} else {
if ( V_351 && V_351 ( V_348 -> V_252 ) == false )
goto exit;
V_64 = F_128 ( V_57 , V_348 ) ;
}
exit:
return V_64 ;
}
static void V_26 ( struct V_353 * V_354 )
{
struct V_21 * V_355 = F_23 ( V_354 , struct V_21 , V_25 ) ;
struct V_57 * V_57 = F_23 ( V_355 , struct V_57 , V_355 ) ;
struct V_350 * V_348 ;
T_6 V_356 = F_129 ( V_57 ) ;
V_355 -> V_27 = true ;
while ( ! F_13 ( V_355 -> V_28 ) ) {
V_348 = (struct V_350 * )
F_14 ( V_355 -> V_28 ) ;
if ( V_348 != NULL )
F_130 ( V_57 ) ;
else {
V_348 = (struct V_350 * ) F_131 ( 16 ) ;
if ( V_348 != NULL &&
F_127 ( V_57 , ( T_2 * ) V_348 ) != V_4 )
continue;
}
if ( ( void * ) V_348 == ( void * ) V_355 )
continue;
if ( ! F_132 ( V_348 ) ) {
F_15 ( V_348 ) ;
continue;
}
if ( V_356 ( V_348 -> V_252 ) == true ) {
F_128 ( V_57 , V_348 ) ;
F_15 ( V_348 ) ;
} else {
#ifdef F_133
F_125 ( V_57 , ( T_2 * ) V_348 ) ;
#endif
}
}
V_355 -> V_27 = false ;
}
T_2 F_134 ( struct V_57 * V_42 , unsigned char * V_66 )
{
struct V_49 * V_357 ;
if ( ! V_66 )
return V_78 ;
V_357 = (struct V_49 * ) V_66 ;
switch ( V_357 -> V_52 ) {
case V_272 :
F_101 ( V_42 , V_357 -> V_66 , V_357 -> V_273 ) ;
break;
case V_53 :
F_114 ( V_42 , V_357 -> V_66 , V_357 -> V_273 ) ;
break;
case V_321 :
F_107 ( V_42 , ( T_2 ) V_357 -> V_273 ) ;
break;
case V_324 :
F_109 ( V_42 , V_357 -> V_273 ) ;
break;
case V_329 :
F_111 ( V_42 , V_357 -> V_273 ) ;
break;
#ifdef F_133
case V_358 :
F_135 ( V_42 , V_357 -> V_273 ) ;
break;
case V_335 :
F_136 ( V_42 , V_357 -> V_273 ) ;
break;
#endif
#ifdef F_102
case V_347 :
F_119 ( V_42 ) ;
break;
#endif
case V_349 :
F_126 ( V_42 , (struct V_350 * ) V_357 -> V_66 , NULL ) ;
break;
default:
break;
}
if ( V_357 -> V_66 && V_357 -> V_273 > 0 )
F_15 ( V_357 -> V_66 ) ;
return V_226 ;
}
void F_137 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
struct V_96 * V_97 = & V_42 -> V_98 ;
if ( V_58 -> V_3 == V_73 ) {
F_54 ( & V_97 -> V_114 , 1 ) ;
} else if ( V_58 -> V_3 != V_226 ) {
F_54 ( & V_97 -> V_114 , 1 ) ;
F_10 ( V_30 , V_81 , ( L_24 ) ) ;
}
F_31 ( V_58 ) ;
}
void F_138 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
struct V_96 * V_97 = & V_42 -> V_98 ;
if ( V_58 -> V_3 != V_226 ) {
F_139 ( & V_97 -> V_38 ) ;
F_53 ( V_97 , V_99 ) ;
F_140 ( & V_97 -> V_38 ) ;
F_10 ( V_30 , V_81 , ( L_25 ) ) ;
return;
} else
F_141 ( V_42 ) ;
F_31 ( V_58 ) ;
}
void F_142 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
struct V_96 * V_97 = & V_42 -> V_98 ;
if ( V_58 -> V_3 == V_73 ) {
F_54 ( & V_97 -> V_359 , 1 ) ;
} else if ( V_58 -> V_3 != V_226 ) {
F_10 ( V_30 , V_81 , ( L_26 ) ) ;
F_54 ( & V_97 -> V_359 , 1 ) ;
}
F_31 ( V_58 ) ;
}
void F_143 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
T_2 V_360 ;
struct V_238 * V_232 = NULL ;
struct V_167 * V_361 = NULL ;
struct V_96 * V_97 = & V_42 -> V_98 ;
struct V_157 * V_168 = (struct V_157 * ) V_58 -> V_51 ;
struct V_167 * V_362 = & ( V_97 -> V_363 ) ;
if ( V_58 -> V_3 != V_226 ) {
F_10 ( V_30 , V_81 , ( L_27 ) ) ;
F_54 ( & V_97 -> V_359 , 1 ) ;
}
F_144 ( & V_97 -> V_359 , & V_360 ) ;
F_139 ( & V_97 -> V_38 ) ;
if ( F_49 ( V_97 , V_307 ) ) {
V_232 = F_145 ( & V_42 -> V_341 , V_168 -> V_206 ) ;
if ( ! V_232 ) {
V_232 = F_146 ( & V_42 -> V_341 , V_168 -> V_206 ) ;
if ( V_232 == NULL ) {
F_10 ( V_30 , V_81 , ( L_28 ) ) ;
goto V_364;
}
}
F_147 ( V_42 ) ;
} else {
V_361 = F_148 ( V_97 ) ;
F_139 ( & ( V_97 -> V_365 . V_38 ) ) ;
if ( V_361 == NULL ) {
V_361 = F_149 ( & V_97 -> V_365 ) ;
if ( V_361 == NULL ) {
F_10 ( V_30 , V_81 , ( L_29 ) ) ;
F_140 ( & V_97 -> V_365 . V_38 ) ;
goto V_364;
}
V_361 -> V_366 = V_113 ;
} else {
F_19 ( & ( V_361 -> V_39 ) , & V_97 -> V_365 . V_34 ) ;
}
V_168 -> V_163 = F_68 ( V_168 ) ;
memcpy ( & ( V_361 -> V_184 ) , V_168 , V_168 -> V_163 ) ;
memcpy ( & V_362 -> V_184 , V_168 , ( F_68 ( V_168 ) ) ) ;
F_56 ( V_97 , V_367 ) ;
F_140 ( & V_97 -> V_365 . V_38 ) ;
}
V_364:
F_140 ( & V_97 -> V_38 ) ;
F_31 ( V_58 ) ;
}
void F_150 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
struct V_339 * V_340 = & V_42 -> V_341 ;
struct V_236 * V_237 = (struct V_236 * ) ( V_58 -> V_61 ) ;
struct V_238 * V_232 = F_145 ( V_340 , V_237 -> V_241 ) ;
if ( V_232 == NULL ) {
F_10 ( V_30 , V_81 , ( L_30 ) ) ;
goto exit;
}
exit:
F_31 ( V_58 ) ;
}
void F_151 ( struct V_57 * V_42 , struct V_35 * V_58 )
{
struct V_339 * V_340 = & V_42 -> V_341 ;
struct V_96 * V_97 = & V_42 -> V_98 ;
struct V_263 * V_368 = (struct V_263 * ) ( V_58 -> V_51 ) ;
struct V_266 * V_369 = (struct V_266 * ) ( V_58 -> V_61 ) ;
struct V_238 * V_232 = F_145 ( V_340 , V_368 -> V_241 ) ;
if ( V_232 == NULL ) {
F_10 ( V_30 , V_81 , ( L_31 ) ) ;
goto exit;
}
V_232 -> V_370 = V_369 -> V_371 ;
V_232 -> V_123 = V_369 -> V_371 ;
F_139 ( & V_97 -> V_38 ) ;
if ( ( F_49 ( V_97 , V_372 ) == true ) && ( F_49 ( V_97 , V_367 ) == true ) )
F_56 ( V_97 , V_367 ) ;
F_53 ( V_97 , V_99 ) ;
F_140 ( & V_97 -> V_38 ) ;
exit:
F_31 ( V_58 ) ;
}
