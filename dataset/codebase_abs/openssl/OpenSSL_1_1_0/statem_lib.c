int F_1 ( T_1 * V_1 , int type )
{
int V_2 ;
V_2 = F_2 ( V_1 , type , & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_1 -> V_6 ) ;
if ( V_2 < 0 )
return ( - 1 ) ;
if ( type == V_7 )
if ( ! F_3 ( V_1 ,
( unsigned char * ) & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_2 ) )
return - 1 ;
if ( V_2 == V_1 -> V_6 ) {
if ( V_1 -> V_8 )
V_1 -> V_8 ( 1 , V_1 -> V_9 , type , V_1 -> V_3 -> V_4 ,
( V_10 ) ( V_1 -> V_5 + V_1 -> V_6 ) , V_1 ,
V_1 -> V_11 ) ;
return ( 1 ) ;
}
V_1 -> V_5 += V_2 ;
V_1 -> V_6 -= V_2 ;
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , const char * V_12 , int V_13 )
{
unsigned char * V_14 ;
int V_15 ;
unsigned long V_16 ;
V_14 = F_5 ( V_1 ) ;
V_15 = V_1 -> V_17 -> V_18 -> V_19 ( V_1 ,
V_12 , V_13 ,
V_1 -> V_20 -> V_21 . V_22 ) ;
if ( V_15 <= 0 )
return 0 ;
V_1 -> V_20 -> V_21 . V_23 = V_15 ;
memcpy ( V_14 , V_1 -> V_20 -> V_21 . V_22 , V_15 ) ;
V_16 = V_15 ;
if ( ! V_1 -> V_24 ) {
F_6 ( V_15 <= V_25 ) ;
memcpy ( V_1 -> V_20 -> V_26 , V_1 -> V_20 -> V_21 . V_22 , V_15 ) ;
V_1 -> V_20 -> V_27 = V_15 ;
} else {
F_6 ( V_15 <= V_25 ) ;
memcpy ( V_1 -> V_20 -> V_28 , V_1 -> V_20 -> V_21 . V_22 , V_15 ) ;
V_1 -> V_20 -> V_29 = V_15 ;
}
if ( ! F_7 ( V_1 , V_30 , V_16 ) ) {
F_8 ( V_31 , V_32 ) ;
return 0 ;
}
return 1 ;
}
static void F_9 ( T_1 * V_1 )
{
const char * V_12 ;
int V_13 ;
if ( V_1 -> V_20 -> V_21 . V_33 == NULL )
return;
if ( ! V_1 -> V_24 ) {
V_12 = V_1 -> V_17 -> V_18 -> V_34 ;
V_13 = V_1 -> V_17 -> V_18 -> V_35 ;
} else {
V_12 = V_1 -> V_17 -> V_18 -> V_36 ;
V_13 = V_1 -> V_17 -> V_18 -> V_37 ;
}
V_1 -> V_20 -> V_21 . V_38 = V_1 -> V_17 -> V_18 -> V_19 ( V_1 ,
V_12 ,
V_13 ,
V_1 -> V_20 -> V_21 . V_39 ) ;
}
T_2 F_10 ( T_1 * V_1 , T_3 * V_40 )
{
int V_41 ;
long V_42 ;
V_42 = F_11 ( V_40 ) ;
if ( F_12 ( V_1 ) ) {
if ( ( V_1 -> V_9 == V_43
&& V_42 != V_44 + 1 )
|| ( V_1 -> V_9 != V_43
&& V_42 != V_44 - 1 ) ) {
V_41 = V_45 ;
F_8 ( V_46 ,
V_47 ) ;
goto V_48;
}
} else {
if ( V_42 != 0 ) {
V_41 = V_45 ;
F_8 ( V_46 ,
V_47 ) ;
goto V_48;
}
}
if ( V_1 -> V_20 -> V_21 . V_33 == NULL ) {
V_41 = V_49 ;
F_8 ( V_46 , V_50 ) ;
goto V_48;
}
V_1 -> V_20 -> V_51 = 1 ;
if ( ! F_13 ( V_1 ) ) {
V_41 = V_52 ;
F_8 ( V_46 , V_32 ) ;
goto V_48;
}
if ( F_12 ( V_1 ) ) {
F_14 ( V_1 , V_53 ) ;
if ( V_1 -> V_9 == V_43 )
V_1 -> V_54 -> V_55 ++ ;
#ifndef F_15
F_16 ( F_17 ( V_1 ) , V_56 , 1 , NULL ) ;
#endif
}
return V_57 ;
V_48:
F_18 ( V_1 , V_58 , V_41 ) ;
F_19 ( V_1 ) ;
return V_59 ;
}
T_2 F_20 ( T_1 * V_1 , T_3 * V_40 )
{
int V_41 , V_15 ;
if ( ! V_1 -> V_20 -> V_51 ) {
V_41 = V_49 ;
F_8 ( V_60 , V_61 ) ;
goto V_48;
}
V_1 -> V_20 -> V_51 = 0 ;
V_15 = V_1 -> V_20 -> V_21 . V_38 ;
if ( ( unsigned long ) V_15 != F_11 ( V_40 ) ) {
V_41 = V_62 ;
F_8 ( V_60 , V_63 ) ;
goto V_48;
}
if ( F_21 ( F_22 ( V_40 ) , V_1 -> V_20 -> V_21 . V_39 , V_15 ) != 0 ) {
V_41 = V_64 ;
F_8 ( V_60 , V_65 ) ;
goto V_48;
}
if ( V_1 -> V_24 ) {
F_6 ( V_15 <= V_25 ) ;
memcpy ( V_1 -> V_20 -> V_26 , V_1 -> V_20 -> V_21 . V_39 , V_15 ) ;
V_1 -> V_20 -> V_27 = V_15 ;
} else {
F_6 ( V_15 <= V_25 ) ;
memcpy ( V_1 -> V_20 -> V_28 , V_1 -> V_20 -> V_21 . V_39 , V_15 ) ;
V_1 -> V_20 -> V_29 = V_15 ;
}
return V_66 ;
V_48:
F_18 ( V_1 , V_58 , V_41 ) ;
F_19 ( V_1 ) ;
return V_59 ;
}
int F_23 ( T_1 * V_1 )
{
unsigned char * V_14 ;
V_14 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_14 = V_67 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
return 1 ;
}
unsigned long F_24 ( T_1 * V_1 , T_4 * V_68 )
{
unsigned char * V_14 ;
unsigned long V_16 = 3 + F_25 ( V_1 ) ;
if ( ! F_26 ( V_1 , V_68 , & V_16 ) )
return 0 ;
V_16 -= 3 + F_25 ( V_1 ) ;
V_14 = F_5 ( V_1 ) ;
F_27 ( V_16 , V_14 ) ;
V_16 += 3 ;
if ( ! F_7 ( V_1 , V_69 , V_16 ) ) {
F_8 ( V_70 , V_32 ) ;
return 0 ;
}
return V_16 + F_25 ( V_1 ) ;
}
T_5 F_28 ( T_1 * V_1 , T_5 V_71 )
{
void (* F_29) ( const T_1 * V_72 , int type , int V_73 ) = NULL ;
#ifndef F_15
if ( F_12 ( V_1 ) && F_30 ( F_17 ( V_1 ) ) ) {
T_5 V_2 ;
V_2 = F_31 ( V_1 ) ;
if ( V_2 != V_74 )
return V_2 ;
}
#endif
F_32 ( V_1 ) ;
if ( ! F_12 ( V_1 ) ) {
F_33 ( V_1 -> V_3 ) ;
V_1 -> V_3 = NULL ;
}
F_34 ( V_1 ) ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_24 || V_1 -> V_75 == 2 ) {
V_1 -> V_75 = 0 ;
V_1 -> V_76 = 0 ;
if ( V_1 -> V_24 ) {
F_35 ( V_1 , V_77 ) ;
V_1 -> V_78 -> V_79 . V_80 ++ ;
V_1 -> V_81 = V_82 ;
} else {
F_35 ( V_1 , V_83 ) ;
if ( V_1 -> V_84 )
V_1 -> V_78 -> V_79 . V_85 ++ ;
V_1 -> V_81 = V_86 ;
V_1 -> V_78 -> V_79 . V_87 ++ ;
}
if ( V_1 -> V_88 != NULL )
F_29 = V_1 -> V_88 ;
else if ( V_1 -> V_78 -> V_88 != NULL )
F_29 = V_1 -> V_78 -> V_88 ;
if ( F_29 != NULL )
F_29 ( V_1 , V_89 , 1 ) ;
if ( F_12 ( V_1 ) ) {
V_1 -> V_54 -> V_55 = 0 ;
V_1 -> V_54 -> V_90 = 0 ;
V_1 -> V_54 -> V_91 = 0 ;
F_36 ( V_1 ) ;
}
}
return V_92 ;
}
int F_37 ( T_1 * V_1 , int * V_93 )
{
int V_94 , V_15 , V_95 , V_41 ;
unsigned char * V_14 ;
unsigned long V_16 ;
V_14 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
do {
while ( V_1 -> V_6 < V_96 ) {
V_15 = V_1 -> V_17 -> V_97 ( V_1 , V_7 , & V_95 ,
& V_14 [ V_1 -> V_6 ] ,
V_96 - V_1 -> V_6 ,
0 ) ;
if ( V_15 <= 0 ) {
V_1 -> V_98 = V_99 ;
return 0 ;
}
if ( V_95 == V_100 ) {
if ( V_1 -> V_6 != 0 || V_15 != 1 || V_14 [ 0 ] != V_67 ) {
V_41 = V_49 ;
F_8 ( V_101 ,
V_47 ) ;
goto V_48;
}
V_1 -> V_20 -> V_21 . V_102 = * V_93 = V_103 ;
V_1 -> V_6 = V_15 - 1 ;
V_1 -> V_20 -> V_21 . V_104 = V_15 ;
return 1 ;
} else if ( V_95 != V_7 ) {
V_41 = V_49 ;
F_8 ( V_101 , V_50 ) ;
goto V_48;
}
V_1 -> V_6 += V_15 ;
}
V_94 = 0 ;
if ( ! V_1 -> V_24 )
if ( V_14 [ 0 ] == V_105 )
if ( V_14 [ 1 ] == 0 && V_14 [ 2 ] == 0 && V_14 [ 3 ] == 0 ) {
V_1 -> V_6 = 0 ;
V_94 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 ,
V_14 , V_96 , V_1 ,
V_1 -> V_11 ) ;
}
} while ( V_94 );
* V_93 = * V_14 ;
V_1 -> V_20 -> V_21 . V_102 = * ( V_14 ++ ) ;
if ( F_38 ( & V_1 -> V_106 ) ) {
V_16 = F_39 ( & V_1 -> V_106 )
+ V_96 ;
if ( V_16 && ! F_40 ( V_1 -> V_3 , ( int ) V_16 ) ) {
F_8 ( V_101 , V_107 ) ;
goto V_108;
}
V_1 -> V_20 -> V_21 . V_104 = V_16 ;
V_1 -> V_109 = V_1 -> V_3 -> V_4 ;
V_1 -> V_6 = V_96 ;
} else {
F_41 ( V_14 , V_16 ) ;
if ( V_16 > ( V_110 - V_96 ) ) {
V_41 = V_45 ;
F_8 ( V_101 , V_111 ) ;
goto V_48;
}
if ( V_16 && ! F_40 ( V_1 -> V_3 ,
( int ) V_16 + V_96 ) ) {
F_8 ( V_101 , V_107 ) ;
goto V_108;
}
V_1 -> V_20 -> V_21 . V_104 = V_16 ;
V_1 -> V_109 = V_1 -> V_3 -> V_4 + V_96 ;
V_1 -> V_6 = 0 ;
}
return 1 ;
V_48:
F_18 ( V_1 , V_58 , V_41 ) ;
V_108:
return 0 ;
}
int F_42 ( T_1 * V_1 , unsigned long * V_112 )
{
long V_113 ;
unsigned char * V_14 ;
int V_15 ;
if ( V_1 -> V_20 -> V_21 . V_102 == V_103 ) {
* V_112 = ( unsigned long ) V_1 -> V_6 ;
return 1 ;
}
V_14 = V_1 -> V_109 ;
V_113 = V_1 -> V_20 -> V_21 . V_104 - V_1 -> V_6 ;
while ( V_113 > 0 ) {
V_15 = V_1 -> V_17 -> V_97 ( V_1 , V_7 , NULL ,
& V_14 [ V_1 -> V_6 ] , V_113 , 0 ) ;
if ( V_15 <= 0 ) {
V_1 -> V_98 = V_99 ;
* V_112 = 0 ;
return 0 ;
}
V_1 -> V_6 += V_15 ;
V_113 -= V_15 ;
}
#ifndef F_43
if ( * V_1 -> V_3 -> V_4 == V_30 )
F_9 ( V_1 ) ;
#endif
if ( F_38 ( & V_1 -> V_106 ) ) {
if ( ! F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 ,
V_1 -> V_6 ) ) {
F_8 ( V_114 , V_115 ) ;
F_18 ( V_1 , V_58 , V_52 ) ;
* V_112 = 0 ;
return 0 ;
}
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_116 , 0 , V_1 -> V_3 -> V_4 ,
( V_10 ) V_1 -> V_6 , V_1 , V_1 -> V_11 ) ;
} else {
if ( ! F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 ,
V_1 -> V_6 + V_96 ) ) {
F_8 ( V_114 , V_115 ) ;
F_18 ( V_1 , V_58 , V_52 ) ;
* V_112 = 0 ;
return 0 ;
}
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_1 -> V_3 -> V_4 ,
( V_10 ) V_1 -> V_6 + V_96 , V_1 ,
V_1 -> V_11 ) ;
}
if ( V_1 -> V_6 < 0 ) {
F_8 ( V_114 , V_32 ) ;
F_18 ( V_1 , V_58 , V_52 ) ;
* V_112 = 0 ;
return 0 ;
}
* V_112 = ( unsigned long ) V_1 -> V_6 ;
return 1 ;
}
int F_44 ( const T_6 * V_117 , const T_7 * V_118 )
{
if ( V_118 == NULL && ( V_118 = F_45 ( V_117 ) ) == NULL )
return - 1 ;
switch ( F_46 ( V_118 ) ) {
default:
return - 1 ;
case V_119 :
return V_120 ;
case V_121 :
return V_122 ;
#ifndef F_47
case V_123 :
return V_124 ;
#endif
#ifndef F_48
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
#endif
}
}
int F_49 ( long type )
{
int V_41 ;
switch ( type ) {
case V_131 :
case V_132 :
case V_133 :
V_41 = V_134 ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_41 = V_153 ;
break;
case V_154 :
case V_155 :
V_41 = V_64 ;
break;
case V_156 :
case V_157 :
V_41 = V_158 ;
break;
case V_159 :
V_41 = V_160 ;
break;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_41 = V_52 ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_41 = V_134 ;
break;
case V_172 :
V_41 = V_173 ;
break;
case V_174 :
V_41 = V_175 ;
break;
default:
V_41 = V_176 ;
break;
}
return ( V_41 ) ;
}
int F_50 ( T_1 * V_1 )
{
if ( V_1 -> V_177 & V_178 )
return 0 ;
return F_51 ( V_1 , V_179 , 0 , 0 , NULL ) ;
}
static int F_52 ( const T_1 * V_1 , int V_180 , int V_181 )
{
int V_182 = F_12 ( V_1 ) ;
if ( V_180 == V_181 )
return 0 ;
if ( ! V_182 )
return V_180 < V_181 ? - 1 : 1 ;
return F_53 ( V_180 , V_181 ) ? - 1 : 1 ;
}
static int F_54 ( const T_1 * V_1 , const T_8 * V_17 )
{
int V_9 = V_17 -> V_9 ;
if ( ( V_1 -> V_183 != 0 &&
F_52 ( V_1 , V_9 , V_1 -> V_183 ) < 0 ) ||
F_51 ( V_1 , V_184 , 0 , V_9 , NULL ) == 0 )
return V_185 ;
if ( V_1 -> V_186 != 0 &&
F_52 ( V_1 , V_9 , V_1 -> V_186 ) > 0 )
return V_187 ;
if ( ( V_1 -> V_177 & V_17 -> V_188 ) != 0 )
return V_189 ;
if ( ( V_17 -> V_190 & V_191 ) != 0 && F_55 ( V_1 ) )
return V_192 ;
else if ( ( V_17 -> V_190 & V_193 ) != 0 && F_56 () )
return V_194 ;
return 0 ;
}
int F_57 ( const T_1 * V_1 , int V_9 )
{
const T_9 * V_195 ;
const T_9 * V_196 ;
switch ( V_1 -> V_17 -> V_9 ) {
default:
return F_52 ( V_1 , V_9 , V_1 -> V_9 ) == 0 ;
case V_197 :
V_196 = V_198 ;
break;
case V_199 :
V_196 = V_200 ;
break;
}
for ( V_195 = V_196 ;
V_195 -> V_9 != 0 && F_52 ( V_1 , V_9 , V_195 -> V_9 ) <= 0 ;
++ V_195 ) {
if ( V_195 -> V_201 != NULL &&
F_52 ( V_1 , V_9 , V_195 -> V_9 ) == 0 &&
F_54 ( V_1 , V_195 -> V_201 () ) == 0 ) {
return 1 ;
}
}
return 0 ;
}
int F_58 ( T_1 * V_1 )
{
const T_9 * V_195 ;
const T_9 * V_196 ;
if ( V_1 -> V_9 == V_1 -> V_78 -> V_17 -> V_9 )
return 1 ;
if ( V_1 -> V_78 -> V_17 -> V_9 == F_59 () -> V_9 )
V_196 = V_198 ;
else if ( V_1 -> V_78 -> V_17 -> V_9 == F_60 () -> V_9 )
V_196 = V_200 ;
else {
return 0 ;
}
for ( V_195 = V_196 ; V_195 -> V_9 != 0 ; ++ V_195 ) {
if ( V_195 -> V_202 != NULL && F_54 ( V_1 , V_195 -> V_202 () ) == 0 )
return V_1 -> V_9 == V_195 -> V_9 ;
}
return 0 ;
}
int F_61 ( int V_203 , int V_9 , int * V_204 )
{
if ( V_9 == 0 ) {
* V_204 = V_9 ;
return 1 ;
}
switch ( V_203 ) {
default:
return 0 ;
case V_197 :
if ( V_9 < V_205 || V_9 > V_206 )
return 0 ;
break;
case V_199 :
if ( F_62 ( V_9 , V_207 ) ||
F_53 ( V_9 , V_43 ) )
return 0 ;
break;
}
* V_204 = V_9 ;
return 1 ;
}
int F_63 ( T_1 * V_1 )
{
int V_208 = V_1 -> V_17 -> V_9 ;
int V_209 = V_1 -> V_209 ;
const T_9 * V_195 ;
const T_9 * V_196 ;
int V_210 = 0 ;
switch ( V_208 ) {
default:
if ( F_52 ( V_1 , V_209 , V_1 -> V_9 ) < 0 )
return V_211 ;
return 0 ;
case V_197 :
V_196 = V_198 ;
break;
case V_199 :
V_196 = V_200 ;
break;
}
for ( V_195 = V_196 ; V_195 -> V_9 != 0 ; ++ V_195 ) {
const T_8 * V_17 ;
if ( V_195 -> V_202 == NULL ||
F_52 ( V_1 , V_209 , V_195 -> V_9 ) < 0 )
continue;
V_17 = V_195 -> V_202 () ;
if ( F_54 ( V_1 , V_17 ) == 0 ) {
V_1 -> V_9 = V_195 -> V_9 ;
V_1 -> V_17 = V_17 ;
return 0 ;
}
V_210 = 1 ;
}
return V_210 ? V_189 : V_185 ;
}
int F_64 ( T_1 * V_1 , int V_9 )
{
const T_9 * V_195 ;
const T_9 * V_196 ;
switch ( V_1 -> V_17 -> V_9 ) {
default:
if ( V_9 != V_1 -> V_9 )
return V_211 ;
return 0 ;
case V_197 :
V_196 = V_198 ;
break;
case V_199 :
V_196 = V_200 ;
break;
}
for ( V_195 = V_196 ; V_195 -> V_9 != 0 ; ++ V_195 ) {
const T_8 * V_17 ;
int V_108 ;
if ( V_9 != V_195 -> V_9 )
continue;
if ( V_195 -> V_201 == NULL )
break;
V_17 = V_195 -> V_201 () ;
V_108 = F_54 ( V_1 , V_17 ) ;
if ( V_108 != 0 )
return V_108 ;
V_1 -> V_17 = V_17 ;
V_1 -> V_9 = V_9 ;
return 0 ;
}
return V_189 ;
}
int F_65 ( const T_1 * V_1 , int * V_212 ,
int * V_213 )
{
int V_9 ;
int V_214 ;
const T_8 * V_215 = NULL ;
const T_8 * V_17 ;
const T_9 * V_196 ;
const T_9 * V_195 ;
switch ( V_1 -> V_17 -> V_9 ) {
default:
* V_212 = * V_213 = V_1 -> V_9 ;
return 0 ;
case V_197 :
V_196 = V_198 ;
break;
case V_199 :
V_196 = V_200 ;
break;
}
* V_212 = V_9 = 0 ;
V_214 = 1 ;
for ( V_195 = V_196 ; V_195 -> V_9 != 0 ; ++ V_195 ) {
if ( V_195 -> V_201 == NULL ) {
V_214 = 1 ;
continue;
}
V_17 = V_195 -> V_201 () ;
if ( F_54 ( V_1 , V_17 ) != 0 ) {
V_214 = 1 ;
} else if ( ! V_214 ) {
V_215 = NULL ;
* V_212 = V_17 -> V_9 ;
} else {
V_9 = ( V_215 = V_17 ) -> V_9 ;
* V_212 = V_9 ;
V_214 = 0 ;
}
}
* V_213 = V_9 ;
if ( V_9 == 0 )
return V_216 ;
return 0 ;
}
int F_66 ( T_1 * V_1 )
{
int V_217 , V_218 , V_2 ;
V_2 = F_65 ( V_1 , & V_217 , & V_218 ) ;
if ( V_2 != 0 )
return V_2 ;
V_1 -> V_209 = V_1 -> V_9 = V_218 ;
return 0 ;
}
