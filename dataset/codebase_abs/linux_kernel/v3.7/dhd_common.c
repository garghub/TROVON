T_1
F_1 ( char * V_1 , char * V_2 , T_1 V_3 , char * V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = strlen ( V_1 ) + 1 ;
if ( ( V_6 + V_3 ) > V_5 )
return 0 ;
strncpy ( V_4 , V_1 , V_5 ) ;
if ( V_2 && V_3 ) {
memcpy ( & V_4 [ V_6 ] , V_2 , V_3 ) ;
V_6 += V_3 ;
}
return V_6 ;
}
T_1
F_2 ( char * V_1 , char * V_2 , T_1 V_3 ,
char * V_4 , T_1 V_5 , T_2 V_7 )
{
const T_3 * V_8 = L_1 ;
T_3 * V_9 ;
T_4 V_10 ;
T_4 V_11 ;
T_4 V_12 ;
T_5 V_13 ;
if ( V_7 == 0 )
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
V_10 = ( T_4 ) strlen ( V_8 ) ;
V_11 = ( T_4 ) strlen ( V_1 ) + 1 ;
V_12 = V_10 + V_11 + sizeof( V_13 ) + V_3 ;
if ( V_5 < 0 || V_12 > ( T_4 ) V_5 ) {
F_3 ( ERROR , L_2 ) ;
return 0 ;
}
V_9 = V_4 ;
memcpy ( V_9 , V_8 , V_10 ) ;
V_9 += V_10 ;
memcpy ( V_9 , V_1 , V_11 ) ;
V_9 += V_11 ;
V_13 = F_4 ( V_7 ) ;
memcpy ( V_9 , & V_13 , sizeof( V_13 ) ) ;
V_9 += sizeof( V_13 ) ;
if ( V_3 )
memcpy ( V_9 , V_2 , V_3 ) ;
return V_12 ;
}
bool F_5 ( struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 , int V_20 )
{
struct V_18 * V_9 ;
int V_21 = - 1 ;
bool V_22 ;
struct V_23 * V_24 = F_6 ( V_15 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
if ( ! F_7 ( V_17 , V_20 ) && ! F_8 ( V_17 ) ) {
F_9 ( V_17 , V_20 , V_19 ) ;
return true ;
}
if ( F_7 ( V_17 , V_20 ) )
V_21 = V_20 ;
else if ( F_8 ( V_17 ) ) {
V_9 = F_10 ( V_17 , & V_21 ) ;
if ( V_21 > V_20 )
return false ;
}
if ( V_21 >= 0 ) {
V_22 = F_11 ( V_26 -> V_27 , V_21 ) ;
if ( V_21 == V_20 && ! V_22 )
return false ;
V_9 = V_22 ? F_12 ( V_17 , V_21 ) :
F_13 ( V_17 , V_21 ) ;
if ( V_9 == NULL )
F_3 ( ERROR , L_3 ,
V_22 ) ;
F_14 ( V_9 ) ;
}
V_9 = F_9 ( V_17 , V_20 , V_19 ) ;
if ( V_9 == NULL )
F_3 ( ERROR , L_4 ) ;
return V_9 != NULL ;
}
static void
F_15 ( struct V_28 * V_29 , void * V_30 )
{
T_1 V_31 , V_32 , V_33 ;
bool V_34 = false , V_35 = false , V_36 = false ;
char * V_37 , * V_38 ;
unsigned char * V_4 ;
char V_39 [ 256 ] , V_40 [ V_41 ] ;
static struct {
T_1 V_29 ;
char * V_38 ;
} V_42 [] = {
{
V_43 , L_5 } , {
V_44 , L_6 } , {
V_45 , L_7 } , {
V_46 , L_8 } , {
V_47 , L_9 } , {
V_48 , L_10 } , {
V_49 , L_11 } , {
V_50 , L_12 } , {
V_51 , L_13 } , {
V_52 , L_14 } , {
V_53 , L_15 } , {
V_54 , L_16 } , {
V_55 , L_17 } , {
V_56 , L_18 } , {
V_57 , L_19 } , {
V_58 , L_20 } , {
V_59 , L_21 } , {
V_60 , L_22 } , {
V_61 , L_23 } , {
V_62 , L_24 } , {
V_63 , L_25 } , {
V_64 , L_26 } , {
V_65 , L_27 } , {
V_66 , L_28 } , {
V_67 , L_29 } , {
V_68 , L_30 } , {
V_69 , L_31 } , {
V_70 , L_32 } , {
V_71 , L_33 } , {
V_72 , L_34 } , {
V_73 , L_35 } , {
V_74 , L_36 } , {
V_75 , L_37 } , {
V_76 , L_38 } , {
V_77 , L_39 } , {
V_78 , L_40 } , {
V_79 , L_41 } , {
V_80 , L_42 } , {
V_81 , L_43 } , {
V_82 , L_44 } , {
V_83 , L_45 } , {
V_84 , L_46 } , {
V_85 , L_47 } , {
V_86 , L_48 } , {
V_87 , L_49 } , {
V_88 , L_50 } , {
V_89 , L_51 } , {
V_90 , L_52 } , {
V_91 , L_53 } , {
V_92 , L_54 } , {
V_93 , L_55 } , {
V_94 , L_56 } , {
V_95 , L_57 } , {
V_96 , L_58 } , {
V_97 , L_59 } , {
V_98 , L_31 } , {
V_99 , L_60 }
} ;
T_1 V_100 , V_101 , V_102 , V_3 ;
static T_4 V_103 ;
struct V_104 V_105 ;
T_4 V_106 ;
char * V_107 , * V_9 ;
V_100 = F_16 ( V_29 -> V_100 ) ;
V_101 = F_17 ( V_29 -> V_101 ) ;
V_32 = F_16 ( V_29 -> V_32 ) ;
V_33 = F_16 ( V_29 -> V_33 ) ;
V_102 = F_16 ( V_29 -> V_102 ) ;
V_3 = F_16 ( V_29 -> V_3 ) ;
sprintf ( V_40 , L_61 , V_29 -> V_108 ) ;
V_38 = L_62 ;
for ( V_31 = 0 ; V_31 < F_18 ( V_42 ) ; V_31 ++ ) {
if ( V_42 [ V_31 ] . V_29 == V_100 )
V_38 = V_42 [ V_31 ] . V_38 ;
}
F_3 ( V_109 , L_63 , V_38 , V_100 ) ;
F_3 ( V_109 , L_64 ,
V_101 , V_32 , V_33 , V_102 , V_40 ) ;
if ( V_101 & V_110 )
V_36 = true ;
if ( V_101 & V_111 )
V_34 = true ;
if ( V_101 & V_112 )
V_35 = true ;
switch ( V_100 ) {
case V_45 :
case V_48 :
case V_54 :
F_3 ( V_109 , L_65 , V_38 , V_40 ) ;
break;
case V_51 :
case V_53 :
F_3 ( V_109 , L_65 , V_38 , V_40 ) ;
break;
case V_50 :
case V_52 :
if ( V_32 == V_113 )
F_3 ( V_109 , L_66 ,
V_38 , V_40 ) ;
else if ( V_32 == V_114 )
F_3 ( V_109 , L_67 ,
V_38 , V_40 ) ;
else if ( V_32 == V_115 )
F_3 ( V_109 , L_68 ,
V_38 , V_40 , ( int ) V_33 ) ;
else
F_3 ( V_109 , L_69 ,
V_38 , V_40 , ( int ) V_32 ) ;
break;
case V_49 :
case V_55 :
F_3 ( V_109 , L_70 ,
V_38 , V_40 , ( int ) V_33 ) ;
break;
case V_46 :
case V_47 :
if ( V_102 == V_116 )
V_37 = L_71 ;
else if ( V_102 == V_117 )
V_37 = L_72 ;
else {
sprintf ( V_39 , L_73 , ( int ) V_102 ) ;
V_37 = V_39 ;
}
if ( V_100 == V_47 )
F_3 ( V_109 , L_74 ,
V_38 , V_40 , V_37 ) ;
else if ( V_32 == V_113 )
F_3 ( V_109 , L_75 ,
V_38 , V_40 , V_37 ) ;
else if ( V_32 == V_114 )
F_3 ( V_109 , L_76 ,
V_38 , V_40 , V_37 ) ;
else if ( V_32 == V_115 ) {
F_3 ( V_109 , L_77 ,
V_38 , V_40 , V_37 , ( int ) V_33 ) ;
}
break;
case V_44 :
case V_62 :
case V_43 :
if ( V_32 == V_113 )
F_3 ( V_109 , L_65 ,
V_38 , V_40 ) ;
else if ( V_32 == V_115 )
F_3 ( V_109 , L_78 , V_38 ) ;
else if ( V_32 == V_118 )
F_3 ( V_109 , L_79 ,
V_38 ) ;
else
F_3 ( V_109 , L_80 ,
V_38 , ( int ) V_32 ) ;
break;
case V_58 :
if ( V_32 == V_113 )
F_3 ( V_109 , L_81 , V_38 ) ;
else if ( V_32 == V_115 )
F_3 ( V_109 , L_82 , V_38 ) ;
else
F_3 ( V_109 , L_83 ,
V_38 , V_32 ) ;
break;
case V_59 :
F_3 ( V_109 , L_84 ,
V_38 , V_36 ? L_85 : L_86 ) ;
break;
case V_60 :
F_3 ( V_109 , L_87 ,
V_38 , V_40 , V_34 , V_35 ) ;
break;
case V_90 :
case V_91 :
case V_92 :
F_3 ( V_109 , L_65 , V_38 , V_40 ) ;
break;
case V_63 :
F_3 ( V_109 , L_88 , V_38 , V_40 ) ;
break;
case V_69 :
case V_64 :
F_3 ( V_109 , L_89 , V_38 ) ;
break;
case V_99 :
F_3 ( V_109 , L_89 , V_38 ) ;
V_3 = 0 ;
break;
case V_76 :
case V_77 :
case V_98 :
F_3 ( V_109 , L_90 , V_38 ) ;
break;
case V_87 :
case V_66 :
F_3 ( V_109 , L_91 ,
V_38 , ( int ) V_32 , ( int ) V_33 ) ;
break;
case V_93 :
V_4 = ( unsigned char * ) V_30 ;
memcpy ( & V_105 , V_4 , sizeof( struct V_104 ) ) ;
if ( V_105 . V_119 != V_120 ) {
F_3 ( ERROR ,
L_92
L_93 ,
V_38 , V_120 , V_105 . V_119 ) ;
V_3 = 0 ;
break;
}
* ( V_4 + sizeof( struct V_104 )
+ F_17 ( V_105 . V_6 ) ) = '\0' ;
if ( F_16 ( V_105 . V_121 )
|| F_16 ( V_105 . V_122 ) )
F_3 ( ERROR ,
L_94
L_95 ,
F_16 ( V_105 . V_121 ) ,
F_16 ( V_105 . V_122 ) ) ;
V_106 = F_16 ( V_105 . V_123 ) - V_103 - 1 ;
if ( V_106 > 0 )
F_3 ( ERROR , L_96
L_97 , F_16 ( V_105 . V_123 ) ,
V_106 ) ;
V_103 = F_16 ( V_105 . V_123 ) ;
V_9 = ( char * ) & V_4 [ sizeof( struct V_104 ) ] ;
while ( ( V_107 = strstr ( V_9 , L_98 ) ) != NULL ) {
* V_107 = '\0' ;
F_19 ( L_99 , V_9 ) ;
V_9 = V_107 + 1 ;
}
F_19 ( L_99 , V_9 ) ;
V_3 = 0 ;
break;
case V_97 :
F_3 ( V_109 , L_100 ,
V_38 , F_16 ( * ( ( V_124 * ) V_30 ) ) ) ;
break;
default:
F_3 ( V_109 ,
L_101
L_102 , V_38 , V_100 , V_40 ,
( int ) V_32 , ( int ) V_33 , ( int ) V_102 ) ;
break;
}
F_20 ( V_3 , V_30 , V_3 , L_103 ) ;
}
int
F_21 ( struct V_25 * V_26 , int * V_125 , void * V_126 ,
struct V_28 * V_29 , void * * V_127 )
{
struct V_128 * V_129 = (struct V_128 * ) V_126 ;
struct V_130 * V_131 ;
char * V_30 ;
T_4 type , V_32 ;
T_6 V_101 ;
int V_132 ;
if ( memcmp ( V_133 , & V_129 -> V_105 . V_134 [ 0 ] , V_135 ) ) {
F_3 ( ERROR , L_104 ) ;
return - V_136 ;
}
if ( F_22 ( & V_129 -> V_105 . V_137 ) !=
V_138 ) {
F_3 ( ERROR , L_105 ) ;
return - V_136 ;
}
* V_127 = & V_129 [ 1 ] ;
V_30 = * V_127 ;
memcpy ( V_29 , & V_129 -> V_139 , sizeof( struct V_28 ) ) ;
type = F_23 ( & V_29 -> V_100 ) ;
V_101 = F_22 ( & V_29 -> V_101 ) ;
V_32 = F_23 ( & V_29 -> V_32 ) ;
V_132 = F_23 ( & V_29 -> V_3 ) +
sizeof( struct V_128 ) ;
switch ( type ) {
case V_96 :
V_131 = (struct V_130 * ) V_30 ;
F_3 ( V_140 , L_106 ) ;
if ( V_131 -> V_125 > 0 && V_131 -> V_125 < V_141 ) {
if ( V_131 -> V_142 == V_143 )
F_24 ( V_26 -> V_15 , V_131 -> V_125 ,
V_29 -> V_144 ,
V_129 -> V_145 . V_146 ) ;
else
F_25 ( V_26 , V_131 -> V_125 ) ;
} else {
F_3 ( ERROR , L_107 ,
V_131 -> V_125 , V_29 -> V_144 ) ;
}
* V_125 = F_26 ( V_26 , V_29 -> V_144 ) ;
break;
case V_59 :
case V_51 :
case V_53 :
case V_55 :
case V_60 :
default:
* V_125 = F_26 ( V_26 , V_29 -> V_144 ) ;
F_3 ( V_140 , L_108 ,
type , V_101 , V_32 ) ;
if ( type == V_61 ) {
T_4 V_147 ;
V_124 V_148 ;
V_147 = F_23 ( & V_29 -> V_100 ) ;
F_3 ( V_140 , L_109 ,
V_147 ) ;
V_148 = F_27 ( V_61 ) ;
memcpy ( ( void * ) ( & V_129 -> V_139 . V_100 ) , & V_148 ,
sizeof( V_129 -> V_139 . V_100 ) ) ;
}
break;
}
#ifdef F_28
if ( F_29 () )
F_15 ( V_29 , V_30 ) ;
#endif
return 0 ;
}
static int F_30 ( char * V_149 , char * V_150 )
{
int V_31 ;
if ( strncmp ( V_149 , L_110 , 2 ) != 0 && strncmp ( V_149 , L_111 , 2 ) != 0 ) {
F_3 ( ERROR , L_112 ) ;
return - V_151 ;
}
V_149 = V_149 + 2 ;
if ( strlen ( V_149 ) % 2 != 0 ) {
F_3 ( ERROR , L_113 ) ;
return - V_151 ;
}
for ( V_31 = 0 ; * V_149 != '\0' ; V_31 ++ ) {
unsigned long V_152 ;
char V_153 [ 3 ] ;
strncpy ( V_153 , V_149 , 2 ) ;
V_153 [ 2 ] = '\0' ;
if ( F_31 ( V_153 , 16 , & V_152 ) )
return - V_151 ;
V_150 [ V_31 ] = ( V_154 ) V_152 ;
V_149 += 2 ;
}
return V_31 ;
}
void
F_32 ( struct V_25 * V_26 , char * V_155 , int V_156 ,
int V_157 )
{
unsigned long V_152 ;
char * V_158 [ 8 ] ;
int V_31 = 0 ;
const char * V_159 ;
int V_160 ;
int V_161 ;
char * V_162 = NULL , * V_163 = NULL ;
int V_164 ;
char V_4 [ 128 ] ;
struct V_165 V_166 ;
struct V_165 * V_167 ;
T_5 V_168 ;
V_162 = F_33 ( strlen ( V_155 ) + 1 , V_169 ) ;
if ( ! V_162 )
goto V_170;
V_163 = V_162 ;
memcpy ( V_162 , V_155 , strlen ( V_155 ) + 1 ) ;
V_158 [ V_31 ] = F_34 ( & V_162 , L_114 ) ;
V_31 = 0 ;
if ( NULL == V_158 [ V_31 ] ) {
F_3 ( ERROR , L_115 ) ;
goto V_170;
}
V_159 = L_116 ;
V_161 = strlen ( V_159 ) ;
strncpy ( V_4 , V_159 , V_161 ) ;
V_4 [ V_161 ] = '\0' ;
V_160 = V_161 + 1 ;
V_167 = (struct V_165 * ) ( V_4 + V_161 + 1 ) ;
V_166 . V_171 = 0 ;
if ( ! F_31 ( V_158 [ V_31 ] , 0 , & V_152 ) )
V_166 . V_171 = F_4 ( ( T_4 ) V_152 ) ;
V_166 . V_156 = F_4 ( V_156 ) ;
V_160 += sizeof( V_166 ) ;
memcpy ( ( char * ) V_167 , & V_166 , sizeof( V_166 ) ) ;
V_164 = F_35 ( V_26 , 0 , V_172 , V_4 , V_160 ) ;
V_164 = V_164 >= 0 ? 0 : V_164 ;
if ( V_164 )
F_3 ( V_140 , L_117 ,
V_155 , V_164 ) ;
else
F_3 ( V_140 , L_118 , V_155 ) ;
V_168 = F_4 ( V_157 ) ;
F_1 ( L_119 , ( char * ) & V_168 , 4 , V_4 ,
sizeof( V_4 ) ) ;
V_164 = F_35 ( V_26 , 0 , V_172 , V_4 ,
sizeof( V_4 ) ) ;
V_164 = V_164 >= 0 ? 0 : V_164 ;
if ( V_164 )
F_3 ( V_140 , L_117 ,
V_155 , V_164 ) ;
V_170:
F_36 ( V_163 ) ;
}
void F_37 ( struct V_25 * V_26 , char * V_155 )
{
const char * V_159 ;
struct V_173 V_174 ;
struct V_173 * V_167 ;
unsigned long V_152 ;
int V_160 ;
int V_161 ;
int V_164 ;
T_4 V_175 ;
T_4 V_176 ;
char * V_158 [ 8 ] , * V_4 = NULL ;
int V_31 = 0 ;
char * V_162 = NULL , * V_163 = NULL ;
V_162 = F_38 ( V_155 , V_169 ) ;
if ( ! V_162 )
goto V_170;
V_163 = V_162 ;
V_4 = F_33 ( V_177 , V_169 ) ;
if ( ! V_4 )
goto V_170;
V_158 [ V_31 ] = F_34 ( & V_162 , L_114 ) ;
while ( V_158 [ V_31 ++ ] )
V_158 [ V_31 ] = F_34 ( & V_162 , L_114 ) ;
V_31 = 0 ;
if ( NULL == V_158 [ V_31 ] ) {
F_3 ( ERROR , L_115 ) ;
goto V_170;
}
V_159 = L_120 ;
strcpy ( V_4 , V_159 ) ;
V_161 = strlen ( V_159 ) ;
V_160 = V_161 + 1 ;
V_167 = (struct V_173 * ) ( V_4 + V_161 + 1 ) ;
V_174 . V_171 = 0 ;
if ( ! F_31 ( V_158 [ V_31 ] , 0 , & V_152 ) )
V_174 . V_171 = F_4 ( ( T_4 ) V_152 ) ;
if ( NULL == V_158 [ ++ V_31 ] ) {
F_3 ( ERROR , L_121 ) ;
goto V_170;
}
V_174 . V_178 = 0 ;
if ( ! F_31 ( V_158 [ V_31 ] , 0 , & V_152 ) )
V_174 . V_178 = F_4 ( ( T_4 ) V_152 ) ;
if ( NULL == V_158 [ ++ V_31 ] ) {
F_3 ( ERROR , L_122 ) ;
goto V_170;
}
V_174 . type = 0 ;
if ( ! F_31 ( V_158 [ V_31 ] , 0 , & V_152 ) )
V_174 . type = F_4 ( ( T_4 ) V_152 ) ;
if ( NULL == V_158 [ ++ V_31 ] ) {
F_3 ( ERROR , L_123 ) ;
goto V_170;
}
V_174 . V_179 . V_180 . V_181 = 0 ;
if ( ! F_31 ( V_158 [ V_31 ] , 0 , & V_152 ) )
V_174 . V_179 . V_180 . V_181 = F_4 ( ( T_4 ) V_152 ) ;
if ( NULL == V_158 [ ++ V_31 ] ) {
F_3 ( ERROR , L_124 ) ;
goto V_170;
}
V_175 =
F_30
( V_158 [ V_31 ] , ( char * ) V_167 -> V_179 . V_180 . V_182 ) ;
if ( NULL == V_158 [ ++ V_31 ] ) {
F_3 ( ERROR , L_125 ) ;
goto V_170;
}
V_176 =
F_30 ( V_158 [ V_31 ] ,
( char * ) & V_167 -> V_179 . V_180 .
V_182 [ V_175 ] ) ;
if ( V_175 != V_176 ) {
F_3 ( ERROR , L_126 ) ;
goto V_170;
}
V_174 . V_179 . V_180 . V_183 = F_4 ( V_175 ) ;
V_160 += V_184 ;
V_160 += ( V_185 + 2 * V_175 ) ;
memcpy ( ( char * ) V_167 ,
& V_174 ,
V_184 + V_185 ) ;
V_164 = F_35 ( V_26 , 0 , V_172 , V_4 , V_160 ) ;
V_164 = V_164 >= 0 ? 0 : V_164 ;
if ( V_164 )
F_3 ( V_140 , L_117 ,
V_155 , V_164 ) ;
else
F_3 ( V_140 , L_118 , V_155 ) ;
V_170:
F_36 ( V_163 ) ;
F_36 ( V_4 ) ;
}
static void F_39 ( struct V_25 * V_26 , int V_186 )
{
char V_187 [ 32 ] ;
int V_188 ;
T_5 V_189 ;
V_189 = F_4 ( V_186 ) ;
F_1 ( L_127 , ( char * ) & V_189 , 4 , V_187 ,
sizeof( V_187 ) ) ;
V_188 = F_35 ( V_26 , 0 , V_172 ,
V_187 , sizeof( V_187 ) ) ;
V_188 = V_188 >= 0 ? 0 : V_188 ;
if ( V_188 )
F_3 ( V_140 , L_128 ,
V_186 , V_188 ) ;
else
F_3 ( V_140 , L_129 ,
V_186 ) ;
}
static void F_40 ( struct V_25 * V_26 , int V_190 )
{
char V_187 [ 32 ] ;
int V_188 ;
T_5 V_191 ;
V_191 = F_4 ( V_190 ) ;
F_1 ( L_130 , ( char * ) & V_191 , 4 ,
V_187 , sizeof( V_187 ) ) ;
V_188 = F_35 ( V_26 , 0 , V_172 ,
V_187 , sizeof( V_187 ) ) ;
V_188 = V_188 >= 0 ? 0 : V_188 ;
if ( V_188 )
F_3 ( V_140 , L_131 ,
V_190 , V_188 ) ;
else
F_3 ( V_140 , L_132 ,
V_190 ) ;
}
int F_41 ( struct V_25 * V_26 )
{
char V_187 [ V_192 + 12 ] ;
char V_4 [ 128 ] , * V_193 ;
T_5 V_194 = F_4 ( 1 ) ;
T_5 V_195 = F_4 ( 3 ) ;
T_5 V_196 = F_4 ( 40 ) ;
T_5 V_197 = F_4 ( 40 ) ;
int V_31 ;
struct V_198 * V_199 ;
struct V_200 * V_201 , * V_17 ;
F_42 ( & V_26 -> V_202 ) ;
if ( V_26 -> V_203 [ 0 ] != 0 ) {
if ( F_35 ( V_26 , 0 , V_204 ,
V_26 -> V_203 ,
sizeof( V_26 -> V_203 ) ) < 0 )
F_3 ( ERROR , L_133 ) ;
}
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
V_193 = V_4 ;
F_1 ( L_134 , NULL , 0 , V_4 , sizeof( V_4 ) ) ;
F_43 ( V_26 , 0 , V_205 , V_4 , sizeof( V_4 ) ) ;
F_34 ( & V_193 , L_98 ) ;
F_3 ( ERROR , L_135 , V_4 ) ;
F_1 ( L_136 , ( char * ) & V_195 , 4 , V_187 ,
sizeof( V_187 ) ) ;
F_35 ( V_26 , 0 , V_172 , V_187 ,
sizeof( V_187 ) ) ;
F_1 ( L_137 , ( char * ) & V_194 , 4 ,
V_187 , sizeof( V_187 ) ) ;
F_35 ( V_26 , 0 , V_172 , V_187 ,
sizeof( V_187 ) ) ;
F_1 ( L_138 , V_26 -> V_206 , V_192 ,
V_187 , sizeof( V_187 ) ) ;
F_35 ( V_26 , 0 , V_172 , V_187 ,
sizeof( V_187 ) ) ;
F_35 ( V_26 , 0 , V_207 ,
( char * ) & V_196 , sizeof( V_196 ) ) ;
F_35 ( V_26 , 0 , V_208 ,
( char * ) & V_197 , sizeof( V_197 ) ) ;
F_39 ( V_26 , V_209 ) ;
F_40 ( V_26 , true ) ;
for ( V_31 = 0 ; V_31 < V_26 -> V_210 ; V_31 ++ ) {
F_37 ( V_26 , V_26 -> V_211 [ V_31 ] ) ;
F_32 ( V_26 , V_26 -> V_211 [ V_31 ] ,
0 , true ) ;
}
F_44 (cur, q, &drvr->bus_if->dcmd_list) {
V_199 = F_45 ( V_201 , struct V_198 , V_212 ) ;
if ( V_199 -> V_1 && V_199 -> V_213 && V_199 -> V_214 ) {
F_1 ( V_199 -> V_1 , V_199 -> V_213 ,
V_199 -> V_214 , V_187 ,
sizeof( V_187 ) ) ;
F_35 ( V_26 , 0 , V_172 ,
V_187 , sizeof( V_187 ) ) ;
}
F_46 ( V_201 ) ;
F_36 ( V_199 ) ;
}
F_47 ( & V_26 -> V_202 ) ;
return 0 ;
}
