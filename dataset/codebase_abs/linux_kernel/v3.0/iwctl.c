struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
long V_5 ;
V_4 -> V_6 . V_7 = V_4 -> V_8 ;
#ifdef F_3
#if 0
if(pDevice->byBBType == BB_TYPE_11B) {
if(pDevice->byCurrSQ > 120)
pDevice->scStatistic.LinkQuality = 100;
else
pDevice->scStatistic.LinkQuality = pDevice->byCurrSQ*100/120;
}
else if(pDevice->byBBType == BB_TYPE_11G) {
if(pDevice->byCurrSQ < 20)
pDevice->scStatistic.LinkQuality = 100;
else if(pDevice->byCurrSQ >96)
pDevice->scStatistic.LinkQuality = 0;
else
pDevice->scStatistic.LinkQuality = (96-pDevice->byCurrSQ)*100/76;
}
if(pDevice->bLinkPass !=true)
pDevice->scStatistic.LinkQuality = 0;
#endif
if( V_4 -> V_9 . V_10 > 100 )
V_4 -> V_9 . V_10 = 100 ;
V_4 -> V_6 . V_11 . V_11 = ( unsigned char ) V_4 -> V_9 . V_10 ;
#else
V_4 -> V_6 . V_11 . V_11 = V_4 -> V_12 ;
#endif
F_4 ( V_4 , ( unsigned char ) ( V_4 -> V_13 ) , & V_5 ) ;
V_4 -> V_6 . V_11 . V_14 = V_5 ;
V_4 -> V_6 . V_11 . V_15 = 0 ;
V_4 -> V_6 . V_11 . V_16 = 1 ;
V_4 -> V_6 . V_17 . V_18 = 0 ;
V_4 -> V_6 . V_17 . V_19 = 0 ;
V_4 -> V_6 . V_17 . V_20 = 0 ;
V_4 -> V_6 . V_17 . V_21 = ( unsigned long ) V_4 -> V_9 . V_22 ;
V_4 -> V_6 . V_17 . V_23 = 0 ;
V_4 -> V_6 . V_24 . V_25 = 0 ;
return & V_4 -> V_6 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
void * V_28 ,
char * V_29 )
{
F_6 ( V_30 , V_31 L_1 ) ;
return 0 ;
}
int F_7 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
char * V_28 ,
char * V_29 )
{
strcpy ( V_28 , L_2 ) ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
return - V_33 ;
}
int F_9 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
struct V_37 * V_38 = (struct V_37 * ) V_29 ;
unsigned char V_39 [ V_40 + V_41 + 1 ] ;
T_3 V_42 = NULL ;
F_6 ( V_30 , V_31 L_3 ) ;
if( V_4 -> V_43 > 0 ) {
union V_44 V_45 ;
F_10 ( L_4 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_11 ( V_4 -> V_3 , V_46 , & V_45 , NULL ) ;
return 0 ;
}
F_12 ( & V_4 -> V_47 ) ;
F_13 ( ( void * ) V_4 , V_4 -> V_48 ) ;
if( V_28 -> V_49 == sizeof( struct V_37 ) ) {
if ( V_28 -> V_50 & V_51 ) {
memset ( V_39 , 0 , V_40 + V_41 + 1 ) ;
V_42 = ( T_3 ) V_39 ;
V_42 -> V_52 = V_53 ;
memcpy ( V_42 -> V_54 , V_38 -> V_55 , ( int ) V_38 -> V_56 ) ;
if ( V_42 -> V_54 [ V_38 -> V_56 - 1 ] == '\0' ) {
if( V_38 -> V_56 > 0 )
V_42 -> V_57 = V_38 -> V_56 - 1 ;
}
else
V_42 -> V_57 = V_38 -> V_56 ;
V_35 -> V_58 = V_59 ;
F_10 ( L_5 , ( ( T_3 ) V_39 ) -> V_54 ,
( ( T_3 ) V_39 ) -> V_57 ) ;
F_14 ( ( void * ) V_4 , V_60 , V_39 ) ;
F_15 ( & V_4 -> V_47 ) ;
return 0 ;
}
else if( V_38 -> V_61 == V_62 ) {
V_35 -> V_58 = V_59 ;
}
}
else {
V_35 -> V_58 = V_63 ;
}
V_35 -> V_58 = V_59 ;
F_14 ( ( void * ) V_4 , V_60 , NULL ) ;
F_15 ( & V_4 -> V_47 ) ;
return 0 ;
}
int F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
int V_64 , V_65 , V_66 ;
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
T_4 V_67 ;
T_3 V_42 ;
T_5 V_68 , V_69 ;
char * V_70 = V_29 ;
char * V_71 = V_29 + V_72 ;
char * V_73 = NULL ;
struct V_74 V_75 ;
long V_5 ;
char V_76 [ V_77 * 2 + 30 ] ;
F_6 ( V_30 , V_31 L_6 ) ;
if ( V_35 -> V_78 == V_79 ) {
return - V_80 ;
}
V_67 = & ( V_35 -> V_81 [ 0 ] ) ;
for ( V_64 = 0 , V_65 = 0 ; V_65 < V_82 ; V_65 ++ ) {
if ( V_70 >= V_71 )
break;
V_67 = & ( V_35 -> V_81 [ V_65 ] ) ;
if ( V_67 -> V_83 ) {
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_85 ;
V_75 . V_86 . V_87 . V_88 = V_89 ;
memcpy ( V_75 . V_86 . V_87 . V_90 , V_67 -> V_91 , V_92 ) ;
V_70 = F_17 ( V_27 , V_70 , V_71 , & V_75 , V_93 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_94 ;
V_42 = ( T_3 ) V_67 -> V_54 ;
V_75 . V_86 . V_95 . V_49 = V_42 -> V_57 ;
V_75 . V_86 . V_95 . V_50 = 1 ;
V_70 = F_18 ( V_27 , V_70 , V_71 , & V_75 , V_42 -> V_54 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_96 ;
if ( F_19 ( V_67 -> V_97 ) ) {
V_75 . V_86 . V_98 = V_99 ;
}
else {
V_75 . V_86 . V_98 = V_100 ;
}
V_75 . V_57 = V_101 ;
V_70 = F_17 ( V_27 , V_70 , V_71 , & V_75 , V_101 ) ;
V_68 = ( T_5 ) V_67 -> V_102 ;
V_69 = ( T_5 ) V_67 -> V_103 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_104 ;
V_75 . V_86 . V_105 . V_106 = V_67 -> V_107 ;
V_75 . V_86 . V_105 . V_108 = 0 ;
V_75 . V_86 . V_105 . V_109 = 0 ;
V_70 = F_17 ( V_27 , V_70 , V_71 , & V_75 , V_110 ) ;
{
int V_111 = ( int ) V_67 -> V_107 - 1 ;
if( V_111 < 0 ) V_111 = 0 ;
V_75 . V_86 . V_105 . V_106 = V_112 [ V_111 ] * 100000 ;
V_75 . V_86 . V_105 . V_108 = 1 ;
}
V_70 = F_17 ( V_27 , V_70 , V_71 , & V_75 , V_110 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_113 ;
F_4 ( V_4 , ( unsigned char ) ( V_67 -> V_114 ) , & V_5 ) ;
V_75 . V_86 . V_11 . V_14 = V_5 ;
V_75 . V_86 . V_11 . V_15 = 0 ;
if( - V_5 < 50 ) {
V_75 . V_86 . V_11 . V_11 = 100 ;
} else if( - V_5 > 90 ) {
V_75 . V_86 . V_11 . V_11 = 0 ;
} else {
V_75 . V_86 . V_11 . V_11 = ( 40 - ( - V_5 - 50 ) ) * 100 / 40 ;
}
V_75 . V_86 . V_11 . V_16 = 7 ;
V_70 = F_17 ( V_27 , V_70 , V_71 , & V_75 , V_115 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_116 ;
V_75 . V_86 . V_95 . V_49 = 0 ;
if ( F_20 ( V_67 -> V_97 ) ) {
V_75 . V_86 . V_95 . V_50 = V_117 | V_118 ;
} else {
V_75 . V_86 . V_95 . V_50 = V_119 ;
}
V_70 = F_18 ( V_27 , V_70 , V_71 , & V_75 , V_42 -> V_54 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_120 ;
V_75 . V_86 . V_121 . V_122 = V_75 . V_86 . V_121 . V_123 = 0 ;
V_73 = V_70 + V_124 ;
for ( V_66 = 0 ; V_66 < 12 ; V_66 ++ ) {
if ( V_68 -> V_125 [ V_66 ] == 0 )
break;
V_75 . V_86 . V_121 . V_126 = ( ( V_68 -> V_125 [ V_66 ] & 0x7f ) * 500000 ) ;
V_73 = F_21 ( V_27 , V_70 , V_73 , V_71 , & V_75 , V_127 ) ;
}
for ( V_66 = 0 ; V_66 < 8 ; V_66 ++ ) {
if ( V_69 -> V_125 [ V_66 ] == 0 )
break;
V_75 . V_86 . V_121 . V_126 = ( ( V_69 -> V_125 [ V_66 ] & 0x7f ) * 500000 ) ;
V_73 = F_21 ( V_27 , V_70 , V_73 , V_71 , & V_75 , V_127 ) ;
}
if( ( V_73 - V_70 ) > V_124 )
V_70 = V_73 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_128 ;
sprintf ( V_76 , L_7 , V_67 -> V_129 ) ;
V_75 . V_86 . V_95 . V_49 = strlen ( V_76 ) ;
V_70 = F_18 ( V_27 , V_70 , V_71 , & V_75 , V_76 ) ;
if ( ( V_67 -> V_130 > 0 ) && ( V_67 -> V_130 <= V_77 ) ) {
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_131 ;
V_75 . V_86 . V_95 . V_49 = V_67 -> V_130 ;
V_70 = F_18 ( V_27 , V_70 , V_71 , & V_75 , V_67 -> V_132 ) ;
}
if ( ( V_67 -> V_133 > 0 ) && ( V_67 -> V_133 <= V_77 ) ) {
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_84 = V_131 ;
V_75 . V_86 . V_95 . V_49 = V_67 -> V_133 ;
V_70 = F_18 ( V_27 , V_70 , V_71 , & V_75 , V_67 -> V_134 ) ;
}
}
}
V_28 -> V_49 = V_70 - V_29 ;
return 0 ;
}
int F_22 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_135 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_136 = 0 ;
F_6 ( V_30 , V_31 L_8 ) ;
if( ( V_28 -> V_108 == 1 ) &&
( V_28 -> V_106 >= ( int ) 2.412e8 ) &&
( V_28 -> V_106 <= ( int ) 2.487e8 ) ) {
int V_111 = V_28 -> V_106 / 100000 ;
int V_137 = 0 ;
while( ( V_137 < 14 ) && ( V_111 != V_112 [ V_137 ] ) )
V_137 ++ ;
V_28 -> V_108 = 0 ;
V_28 -> V_106 = V_137 + 1 ;
}
if( ( V_28 -> V_106 > 14 ) || ( V_28 -> V_108 > 0 ) )
V_136 = - V_33 ;
else {
int V_138 = V_28 -> V_106 ;
if( ( V_138 < 1 ) || ( V_138 > 14 ) ) {
F_6 ( V_30 , V_31 L_9 , V_3 -> V_139 , V_28 -> V_106 ) ;
V_136 = - V_140 ;
} else {
F_6 ( V_30 , V_31 L_10 , V_138 ) ;
V_4 -> V_107 = V_138 ;
V_4 -> V_141 = true ;
}
}
return V_136 ;
}
int F_23 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_135 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
F_6 ( V_30 , V_31 L_11 ) ;
#ifdef F_24
V_28 -> V_106 = ( int ) V_35 -> V_142 ;
V_28 -> V_108 = 0 ;
#else
{
int V_111 = ( int ) V_35 -> V_142 - 1 ;
if( V_111 < 0 )
V_111 = 0 ;
V_28 -> V_106 = V_112 [ V_111 ] * 100000 ;
V_28 -> V_108 = 1 ;
}
#endif
return 0 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
T_6 * V_143 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_136 = 0 ;
F_6 ( V_30 , V_31 L_12 ) ;
if ( V_35 -> V_144 == V_145 && V_4 -> V_146 ) {
F_6 ( V_30 , V_31 L_13 ) ;
return V_136 ;
}
switch( * V_143 ) {
case V_100 :
if ( V_35 -> V_147 != V_148 ) {
V_35 -> V_147 = V_148 ;
if ( V_4 -> V_50 & V_149 ) {
V_4 -> V_141 = true ;
}
}
F_6 ( V_30 , V_31 L_14 ) ;
break;
case V_150 :
case V_99 :
if ( V_35 -> V_147 != V_151 ) {
V_35 -> V_147 = V_151 ;
if ( V_4 -> V_50 & V_149 ) {
V_4 -> V_141 = true ;
}
}
F_6 ( V_30 , V_31 L_15 ) ;
break;
case V_152 :
V_35 -> V_147 = V_151 ;
V_136 = - V_33 ;
break;
if ( V_35 -> V_147 != V_153 ) {
V_35 -> V_147 = V_153 ;
if ( V_4 -> V_50 & V_149 ) {
V_4 -> V_141 = true ;
}
}
F_6 ( V_30 , V_31 L_16 ) ;
break;
case V_154 :
V_35 -> V_147 = V_151 ;
V_136 = - V_33 ;
break;
default:
V_136 = - V_140 ;
}
return V_136 ;
}
int F_26 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
T_6 * V_143 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
F_6 ( V_30 , V_31 L_17 ) ;
switch ( V_35 -> V_147 ) {
case V_151 :
* V_143 = V_99 ;
break;
case V_148 :
* V_143 = V_100 ;
break;
case V_155 :
* V_143 = V_99 ;
break;
case V_153 :
* V_143 = V_152 ;
break;
default:
* V_143 = V_100 ;
}
return 0 ;
}
int F_27 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
struct V_156 * V_157 = (struct V_156 * ) V_29 ;
int V_109 , V_158 ;
unsigned char V_159 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( V_30 , V_31 L_18 ) ;
if ( V_28 -> V_160 ) {
V_28 -> V_49 = sizeof( struct V_156 ) ;
memset ( V_157 , 0 , sizeof( struct V_156 ) ) ;
V_157 -> V_161 = 0x0000 ;
V_157 -> V_162 = 0x0000 ;
V_157 -> V_163 = 14 ;
V_158 = 0 ;
for( V_109 = 0 ; V_109 < 14 ; V_109 ++ ) {
V_157 -> V_105 [ V_158 ] . V_109 = V_109 + 1 ;
V_157 -> V_105 [ V_158 ] . V_106 = V_112 [ V_109 ] * 100000 ;
V_157 -> V_105 [ V_158 ++ ] . V_108 = 1 ;
}
V_157 -> V_164 = V_158 ;
#ifdef F_3
V_157 -> V_165 . V_11 = 100 ;
#else
V_157 -> V_165 . V_11 = 255 ;
#endif
V_157 -> V_165 . V_14 = 0 ;
V_157 -> V_165 . V_15 = 0 ;
V_157 -> V_166 = 255 ;
for( V_109 = 0 ; V_109 < 13 ; V_109 ++ ) {
V_157 -> V_121 [ V_109 ] = V_159 [ V_109 ] * 500000 ;
if( V_157 -> V_121 [ V_109 ] == 0 )
break;
}
V_157 -> V_167 = V_109 ;
if( V_109 > 2 )
V_157 -> V_168 = 5 * 1000 * 1000 ;
else
V_157 -> V_168 = 1.5 * 1000 * 1000 ;
V_157 -> V_169 = 0 ;
V_157 -> V_170 = 2312 ;
V_157 -> V_171 = 256 ;
V_157 -> V_172 = 2312 ;
V_157 -> V_173 = 3 ;
V_157 -> V_174 [ 0 ] = 5 ;
V_157 -> V_174 [ 1 ] = 13 ;
V_157 -> V_174 [ 2 ] = 32 ;
V_157 -> V_175 = 4 ;
V_157 -> V_176 = V_177 | V_178 |
V_179 | V_180 ;
V_157 -> V_181 = 0 ;
V_157 -> V_182 = 1000000 ;
V_157 -> V_183 = 0 ;
V_157 -> V_184 = 1000000 ;
V_157 -> V_185 = V_186 ;
V_157 -> V_187 = V_188 ;
V_157 -> V_189 = V_186 | V_188 | V_190 ;
V_157 -> V_191 [ 0 ] = 100 ;
V_157 -> V_192 = 1 ;
V_157 -> V_193 = V_194 ;
V_157 -> V_195 = V_196 ;
V_157 -> V_197 = V_198 ;
V_157 -> V_199 = V_200 | V_201 ;
V_157 -> V_202 = V_200 ;
V_157 -> V_203 = V_201 ;
V_157 -> V_204 = 1 ;
V_157 -> V_205 = 65535 ;
V_157 -> V_206 = 1024 ;
V_157 -> V_207 = 65535 * 1024 ;
V_157 -> V_208 . V_11 = 6 ;
V_157 -> V_208 . V_14 = 176 ;
V_157 -> V_208 . V_15 = 0 ;
}
return 0 ;
}
int F_28 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_209 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_136 = 0 ;
unsigned char V_210 [ V_92 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_6 ( V_30 , V_31 L_19 ) ;
if ( V_35 -> V_78 == V_79 ) {
F_29 ( L_20 ) ;
}
if ( V_28 -> V_88 != V_89 )
V_136 = - V_140 ;
else {
memcpy ( V_35 -> V_211 , V_28 -> V_90 , 6 ) ;
if( ( V_4 -> V_48 == true ) &&
( memcmp ( V_35 -> V_211 , V_35 -> V_212 , 6 ) == 0 ) ) {
return V_136 ;
}
if ( ( F_30 ( V_35 -> V_211 ) ) ||
( memcmp ( V_35 -> V_211 , V_210 , 6 ) == 0 ) ) {
F_10 ( L_21 ) ;
return V_136 ;
}
{
unsigned int V_64 , V_213 = 0 ;
for ( V_64 = 0 ; V_64 < V_82 ; V_64 ++ ) {
if ( V_35 -> V_81 [ V_64 ] . V_83 &&
! F_31 ( V_35 -> V_81 [ V_64 ] . V_91 , V_35 -> V_211 ) ) {
V_213 ++ ;
}
}
if( V_213 >= 2 ) {
F_10 ( L_22 ) ;
return V_136 ;
}
}
if ( V_4 -> V_50 & V_149 ) {
V_4 -> V_141 = true ;
}
}
return V_136 ;
}
int F_32 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_209 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
F_6 ( V_30 , V_31 L_23 ) ;
memcpy ( V_28 -> V_90 , V_35 -> V_212 , 6 ) ;
if ( ( V_4 -> V_48 == false ) && ( V_35 -> V_144 != V_145 ) )
memset ( V_28 -> V_90 , 0 , 6 ) ;
if ( V_35 -> V_144 == V_145 ) {
memcpy ( V_28 -> V_90 , V_35 -> V_212 , 6 ) ;
}
V_28 -> V_88 = V_89 ;
return 0 ;
}
int F_33 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
int V_64 , V_65 , V_136 = 0 ;
struct V_209 V_214 [ V_215 ] ;
struct V_216 V_11 [ V_215 ] ;
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
F_6 ( V_30 , V_31 L_24 ) ;
if ( ! F_34 ( V_217 ) ) {
V_136 = - V_218 ;
return V_136 ;
}
if ( V_28 -> V_160 ) {
T_4 V_67 = & ( V_35 -> V_81 [ 0 ] ) ;
for ( V_64 = 0 , V_65 = 0 ; V_64 < V_82 ; V_64 ++ ) {
V_67 = & ( V_35 -> V_81 [ V_64 ] ) ;
if ( ! V_67 -> V_83 )
continue;
if ( V_65 >= V_215 )
break;
memcpy ( V_214 [ V_65 ] . V_90 , V_67 -> V_91 , 6 ) ;
V_214 [ V_65 ] . V_88 = V_89 ;
V_11 [ V_65 ] . V_14 = V_67 -> V_114 ;
V_11 [ V_65 ] . V_11 = V_11 [ V_65 ] . V_15 = 0 ;
V_11 [ V_65 ] . V_16 = 2 ;
V_65 ++ ;
}
V_28 -> V_50 = 1 ;
V_28 -> V_49 = V_65 ;
memcpy ( V_29 , V_214 , sizeof( struct V_209 ) * V_65 ) ;
memcpy ( V_29 + sizeof( struct V_209 ) * V_65 , V_11 , sizeof( struct V_216 ) * V_65 ) ;
}
return V_136 ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
T_3 V_42 ;
unsigned char V_57 ;
F_6 ( V_30 , V_31 L_25 ) ;
V_4 -> V_219 = false ;
if ( V_35 -> V_78 == V_79 ) {
F_29 ( L_26 ) ;
}
if( V_28 -> V_50 == 0 ) {
memset ( V_35 -> V_220 , 0 , V_40 + V_41 + 1 ) ;
memset ( V_35 -> V_211 , 0xFF , 6 ) ;
F_10 ( L_27 ) ;
#ifdef F_36
return 0 ;
#endif
} else {
memset ( V_35 -> V_220 , 0 , V_40 + V_41 + 1 ) ;
V_42 = ( T_3 ) V_35 -> V_220 ;
V_42 -> V_52 = V_53 ;
memcpy ( V_42 -> V_54 , V_29 , V_28 -> V_49 ) ;
if ( V_42 -> V_54 [ V_28 -> V_49 - 1 ] == '\0' ) {
if( V_28 -> V_49 > 0 )
V_42 -> V_57 = V_28 -> V_49 - 1 ;
}
else
V_42 -> V_57 = V_28 -> V_49 ;
F_29 ( L_28 , V_42 -> V_54 ) ;
V_57 = ( V_42 -> V_57 > ( ( T_3 ) V_35 -> V_221 ) -> V_57 ) ? V_42 -> V_57 : ( ( T_3 ) V_35 -> V_221 ) -> V_57 ;
if( ( V_4 -> V_48 == true ) &&
( memcmp ( V_42 -> V_54 , ( ( T_3 ) V_35 -> V_221 ) -> V_54 , V_57 ) == 0 ) )
return 0 ;
if( V_42 -> V_57 == 0 ) {
memset ( V_35 -> V_211 , 0xFF , 6 ) ;
return 0 ;
}
#ifdef F_36
if( V_4 -> V_222 == true ) {
{
T_4 V_223 = NULL ;
unsigned char V_224 [ V_40 + V_41 + 1 ] ;
unsigned int V_64 , V_213 = 0 ;
memcpy ( V_224 , V_35 -> V_220 , sizeof( V_224 ) ) ;
V_223 = F_37 ( V_4 ,
NULL ,
V_224 ,
V_35 -> V_225
) ;
if ( V_223 == NULL ) {
F_10 ( L_29 ) ;
F_38 ( ( void * ) V_4 ) ;
V_35 -> V_58 = V_63 ;
F_14 ( ( void * ) V_4 , V_60 , V_35 -> V_220 ) ;
F_14 ( ( void * ) V_4 , V_226 , V_35 -> V_220 ) ;
}
else {
for ( V_64 = 0 ; V_64 < V_82 ; V_64 ++ ) {
if ( V_35 -> V_81 [ V_64 ] . V_83 &&
! F_31 ( V_35 -> V_81 [ V_64 ] . V_91 , V_223 -> V_91 ) ) {
V_213 ++ ;
}
}
if( V_213 >= 2 ) {
F_29 ( L_30 ) ;
F_38 ( ( void * ) V_4 ) ;
V_35 -> V_58 = V_59 ;
F_14 ( ( void * ) V_4 , V_60 , V_35 -> V_220 ) ;
F_14 ( ( void * ) V_4 , V_226 , V_35 -> V_220 ) ;
}
}
}
return 0 ;
}
#endif
F_6 ( V_30 , V_31 L_31 , V_42 -> V_54 ) ;
}
if ( V_4 -> V_50 & V_149 ) {
V_4 -> V_141 = true ;
}
return 0 ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
T_3 V_42 ;
F_6 ( V_30 , V_31 L_32 ) ;
V_42 = ( T_3 ) V_35 -> V_221 ;
memcpy ( V_29 , V_42 -> V_54 , V_42 -> V_57 ) ;
V_29 [ V_42 -> V_57 ] = '\0' ;
V_28 -> V_49 = V_42 -> V_57 + 1 ;
V_28 -> V_49 = V_42 -> V_57 ;
V_28 -> V_50 = 1 ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_136 = 0 ;
T_7 V_227 = 0 ;
int V_109 ;
unsigned char V_159 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
F_6 ( V_30 , V_31 L_33 ) ;
if ( ! ( V_4 -> V_50 & V_149 ) ) {
V_136 = - V_140 ;
return V_136 ;
}
if( ( V_28 -> V_126 < 13 ) &&
( V_28 -> V_126 >= 0 ) ) {
V_227 = V_28 -> V_126 ;
} else {
T_7 V_228 = ( T_7 ) ( V_28 -> V_126 / 500000 ) ;
for( V_109 = 0 ; V_109 < 13 ; V_109 ++ ) {
if( V_228 == V_159 [ V_109 ] ) {
V_227 = V_109 ;
break;
}
}
}
if( V_28 -> V_126 == - 1 ) {
for( V_109 = 0 ; V_109 < 13 ; V_109 ++ ) {
if( V_159 [ V_109 ] == 0 )
break;
}
if( V_109 != 0 )
V_227 = V_109 - 1 ;
}
if( V_227 > 13 ) {
V_136 = - V_140 ;
return V_136 ;
}
if( V_28 -> V_122 != 0 ) {
F_29 ( L_34 ) ;
V_4 -> V_229 = true ;
if ( ( V_4 -> V_230 == V_231 ) && ( V_227 > 3 ) ) {
V_4 -> V_232 = 3 ;
}
else {
V_4 -> V_232 = V_227 ;
F_6 ( V_30 , V_31 L_35 , V_4 -> V_232 ) ;
}
}
else {
V_4 -> V_229 = false ;
V_4 -> V_232 = 13 ;
F_29 ( L_36 ) ;
}
return V_136 ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_37 ) ;
{
unsigned char V_159 [ 13 ] = { 0x02 , 0x04 , 0x0B , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C , 0x90 } ;
int V_227 = 0 ;
if( V_4 -> V_48 ) {
if( V_4 -> V_229 == true ) {
if ( V_4 -> V_232 < 13 ) {
V_227 = V_159 [ V_4 -> V_232 ] ;
} else {
if ( V_4 -> V_230 == V_231 )
V_227 = 0x16 ;
if ( V_4 -> V_230 == V_233 )
V_227 = 0x6C ;
if ( V_4 -> V_230 == V_234 )
V_227 = 0x6C ;
}
}
else
{
V_227 = V_159 [ V_235 ] ;
}
}
else V_227 = 0 ;
V_28 -> V_126 = V_227 * 500000 ;
if ( V_4 -> V_229 == true )
V_28 -> V_122 = true ;
}
return 0 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_136 = 0 ;
F_6 ( V_30 , V_31 L_38 ) ;
{
int V_236 = V_28 -> V_126 ;
if( V_28 -> V_123 )
V_236 = 2312 ;
if( ( V_236 < 0 ) || ( V_236 > 2312 ) ) {
V_136 = - V_140 ;
} else {
V_4 -> V_237 = V_236 ;
}
}
return 0 ;
}
int F_43 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_39 ) ;
V_28 -> V_126 = V_4 -> V_237 ;
V_28 -> V_123 = ( V_28 -> V_126 >= 2312 ) ;
V_28 -> V_122 = 1 ;
return 0 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_136 = 0 ;
int V_238 = V_28 -> V_126 ;
F_6 ( V_30 , V_31 L_40 ) ;
if ( V_28 -> V_123 )
V_238 = 2312 ;
if( ( V_238 < 256 ) || ( V_238 > 2312 ) ) {
V_136 = - V_140 ;
} else {
V_238 &= ~ 0x1 ;
V_4 -> V_239 = ( V_240 ) V_238 ;
}
return V_136 ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_41 ) ;
V_28 -> V_126 = V_4 -> V_239 ;
V_28 -> V_123 = ( V_28 -> V_126 >= 2312 ) ;
V_28 -> V_122 = 1 ;
return 0 ;
}
int F_46 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
int V_136 = 0 ;
F_6 ( V_30 , V_31 L_42 ) ;
if ( V_28 -> V_123 ) {
V_136 = - V_140 ;
return V_136 ;
}
if ( V_28 -> V_50 & V_200 ) {
if( V_28 -> V_50 & V_241 )
V_4 -> V_242 = V_28 -> V_126 ;
else if ( V_28 -> V_50 & V_243 )
V_4 -> V_244 = V_28 -> V_126 ;
else {
V_4 -> V_244 = V_28 -> V_126 ;
V_4 -> V_242 = V_28 -> V_126 ;
}
}
if ( V_28 -> V_50 & V_201 ) {
V_4 -> V_245 = V_28 -> V_126 ;
}
return V_136 ;
}
int F_47 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
F_6 ( V_30 , V_31 L_43 ) ;
V_28 -> V_123 = 0 ;
if( ( V_28 -> V_50 & V_246 ) == V_201 ) {
V_28 -> V_50 = V_201 ;
V_28 -> V_126 = ( int ) V_4 -> V_245 ;
} else if( ( V_28 -> V_50 & V_241 ) ) {
V_28 -> V_50 = V_200 | V_241 ;
V_28 -> V_126 = ( int ) V_4 -> V_242 ;
} else {
V_28 -> V_50 = V_200 ;
V_28 -> V_126 = ( int ) V_4 -> V_244 ;
if( ( int ) V_4 -> V_244 != ( int ) V_4 -> V_242 )
V_28 -> V_50 |= V_243 ;
}
return 0 ;
}
int F_48 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
unsigned long V_247 = ( unsigned long ) ( V_28 -> V_50 & V_248 ) ;
int V_64 , V_249 , V_136 = 0 ;
int V_250 = ( V_28 -> V_50 & V_248 ) ;
T_8 V_251 ;
F_6 ( V_30 , V_31 L_44 ) ;
if( ( V_28 -> V_50 & V_119 ) == 0 ) {
if ( V_247 > V_252 ) {
V_136 = - V_140 ;
return V_136 ;
}
if( V_247 < 1 && ( ( V_28 -> V_50 & V_118 ) == 0 ) ) {
if( V_4 -> V_253 < V_252 ) {
V_247 = V_4 -> V_253 ;
}
else V_247 = 0 ;
} else V_247 -- ;
if ( V_28 -> V_49 > V_254 ) {
V_136 = - V_140 ;
return V_136 ;
}
if( V_28 -> V_49 > 0 ) {
if ( V_28 -> V_49 == V_254 ) {
F_6 ( V_30 , V_31 L_45 ) ;
}
else if ( V_28 -> V_49 == V_255 ) {
F_6 ( V_30 , V_31 L_46 ) ;
}
else if ( V_28 -> V_49 == V_256 ) {
F_6 ( V_30 , V_31 L_47 , ( int ) V_247 ) ;
} else {
V_136 = - V_140 ;
return V_136 ;
}
memset ( V_4 -> V_257 , 0 , V_254 ) ;
memcpy ( V_4 -> V_257 , V_29 , V_28 -> V_49 ) ;
F_6 ( V_30 , V_31 L_48 ) ;
for ( V_64 = 0 ; V_64 < V_28 -> V_49 ; V_64 ++ ) {
F_6 ( V_30 , V_31 L_49 , V_4 -> V_257 [ V_64 ] ) ;
}
if ( V_4 -> V_50 & V_149 ) {
F_12 ( & V_4 -> V_47 ) ;
F_49 ( & ( V_4 -> V_258 ) ,
( unsigned long ) ( V_247 | ( 1 << 31 ) ) ,
V_28 -> V_49 ,
NULL ,
V_4 -> V_257 ,
V_259 ,
V_4 -> V_260 ,
V_4 -> V_261
) ;
F_15 ( & V_4 -> V_47 ) ;
}
V_4 -> V_253 = ( unsigned char ) V_247 ;
V_4 -> V_262 = V_28 -> V_49 ;
V_4 -> V_263 = true ;
V_4 -> V_264 = true ;
V_4 -> V_265 = V_266 ;
} else if( V_250 > 0 ) {
if( V_4 -> V_264 == false )
{
V_136 = - V_140 ;
return V_136 ;
}
F_6 ( V_30 , V_31 L_50 ) ;
V_251 = & ( V_4 -> V_258 . V_267 [ V_268 - 1 ] ) ;
if( V_251 -> V_269 [ ( unsigned char ) V_247 ] . V_262 == 0 ) {
F_6 ( V_30 , V_31 L_51 ) ;
V_136 = - V_140 ;
return V_136 ;
}
V_4 -> V_253 = ( unsigned char ) V_247 ;
V_251 -> V_270 = V_247 | ( 1 << 31 ) ;
V_251 -> V_269 [ ( unsigned char ) V_247 ] . V_247 = V_247 | ( 1 << 31 ) ;
}
} else {
F_6 ( V_30 , V_31 L_52 ) ;
if( V_4 -> V_264 == false )
return 0 ;
V_35 -> V_271 = false ;
V_4 -> V_264 = false ;
V_4 -> V_265 = V_272 ;
if ( V_4 -> V_50 & V_149 ) {
F_12 ( & V_4 -> V_47 ) ;
for( V_249 = 0 ; V_249 < V_268 ; V_249 ++ )
F_50 ( V_4 -> V_260 , V_249 ) ;
F_15 ( & V_4 -> V_47 ) ;
}
}
if( V_28 -> V_50 & V_273 ) {
F_6 ( V_30 , V_31 L_53 ) ;
V_35 -> V_271 = true ;
}
if( V_28 -> V_50 & V_274 ) {
F_6 ( V_30 , V_31 L_54 ) ;
V_35 -> V_271 = false ;
}
return V_136 ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
char V_257 [ V_254 ] ;
unsigned int V_250 = ( unsigned int ) ( V_28 -> V_50 & V_248 ) ;
T_9 V_275 = NULL ;
F_6 ( V_30 , V_31 L_55 ) ;
if ( V_250 > V_252 ) {
return - V_140 ;
}
if( V_250 < 1 ) {
if( V_4 -> V_253 < V_252 ) {
V_250 = V_4 -> V_253 ;
} else
V_250 = 0 ;
} else
V_250 -- ;
memset ( V_257 , 0 , V_254 ) ;
V_28 -> V_50 = V_118 ;
if ( V_4 -> V_264 )
V_28 -> V_50 |= V_117 ;
else
V_28 -> V_50 |= V_119 ;
if ( V_35 -> V_271 )
V_28 -> V_50 |= V_273 ;
else
V_28 -> V_50 |= V_274 ;
V_28 -> V_49 = 0 ;
if( ( V_250 == 0 ) && ( V_4 -> V_265 == V_276 ||
V_4 -> V_265 == V_277 ) ) {
if ( F_52 ( & ( V_4 -> V_258 ) , V_35 -> V_212 , 0xffffffff , & V_275 ) ) {
V_28 -> V_49 = V_275 -> V_262 ;
memcpy ( V_257 , V_275 -> V_257 , V_275 -> V_262 ) ;
memcpy ( V_29 , V_257 , V_254 ) ;
}
} else if ( F_52 ( & ( V_4 -> V_258 ) , V_4 -> V_278 , ( unsigned char ) V_250 , & V_275 ) ) {
V_28 -> V_49 = V_275 -> V_262 ;
memcpy ( V_257 , V_275 -> V_257 , V_275 -> V_262 ) ;
memcpy ( V_29 , V_257 , V_254 ) ;
}
V_28 -> V_50 |= V_250 + 1 ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_136 = 0 ;
F_6 ( V_30 , V_31 L_56 ) ;
if ( ! ( V_4 -> V_50 & V_149 ) ) {
V_136 = - V_140 ;
return V_136 ;
}
if ( V_28 -> V_123 ) {
V_4 -> V_279 = V_280 ;
F_54 ( V_4 ) ;
return V_136 ;
}
if ( ( V_28 -> V_50 & V_281 ) == V_188 ) {
V_4 -> V_279 = V_282 ;
F_55 ( ( void * ) V_4 , V_35 -> V_283 ) ;
} else if ( ( V_28 -> V_50 & V_281 ) == V_186 ) {
V_4 -> V_279 = V_282 ;
F_55 ( ( void * ) V_4 , V_35 -> V_283 ) ;
}
switch ( V_28 -> V_50 & V_284 ) {
case V_285 :
F_6 ( V_30 , V_31 L_57 ) ;
V_136 = - V_140 ;
break;
case V_190 :
F_6 ( V_30 , V_31 L_58 ) ;
V_136 = - V_140 ;
case V_286 :
F_6 ( V_30 , V_31 L_59 ) ;
break;
default:
V_136 = - V_140 ;
}
return V_136 ;
}
int F_56 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_98 = V_4 -> V_279 ;
F_6 ( V_30 , V_31 L_60 ) ;
V_28 -> V_123 = ( V_98 == V_280 ) ;
if ( V_28 -> V_123 )
return 0 ;
if ( ( V_28 -> V_50 & V_281 ) == V_188 ) {
V_28 -> V_126 = ( int ) ( ( V_35 -> V_283 * V_35 -> V_287 ) << 10 ) ;
V_28 -> V_50 = V_188 ;
} else {
V_28 -> V_126 = ( int ) ( ( V_35 -> V_283 * V_35 -> V_287 ) << 10 ) ;
V_28 -> V_50 = V_186 ;
}
V_28 -> V_50 |= V_190 ;
return 0 ;
}
int F_57 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
long V_5 ;
F_6 ( V_30 , V_31 L_61 ) ;
if ( V_4 -> V_48 == true ) {
F_4 ( V_4 , ( unsigned char ) ( V_4 -> V_13 ) , & V_5 ) ;
V_28 -> V_126 = V_5 ;
}
else {
V_28 -> V_126 = 0 ;
} ;
V_28 -> V_123 = ( V_28 -> V_126 == 0 ) ;
V_28 -> V_122 = 1 ;
return 0 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_288 = 0 ;
static int V_289 = 0 ;
static int V_290 = 0 ;
F_6 ( V_30 , V_31 L_62 ) ;
switch ( V_28 -> V_50 & V_291 ) {
case V_292 :
V_289 = V_28 -> V_126 ;
if( V_28 -> V_126 == V_293 ) {
F_10 ( L_63 ) ;
}
else if( V_28 -> V_126 == V_294 ) {
F_10 ( L_64 ) ;
}
else {
F_10 ( L_65 ) ;
}
break;
case V_295 :
V_290 = V_28 -> V_126 ;
if( V_290 == V_296 ) {
V_4 -> V_265 = V_277 ;
} else if( V_290 == V_297 ) {
V_4 -> V_265 = V_276 ;
} else if( V_290 == V_298 || V_290 == V_299 ) {
V_4 -> V_265 = V_266 ;
} else if( V_290 == V_300 ) {
} else V_4 -> V_265 = V_272 ;
break;
case V_301 :
if( V_289 == V_293 )
break;
if( V_290 == V_300 ) {
if( V_28 -> V_126 == V_296 ) {
V_4 -> V_265 = V_277 ;
} else {
V_4 -> V_265 = V_276 ;
}
}
break;
case V_302 :
if( V_289 == V_303 ) {
if( V_28 -> V_126 == V_304 )
V_35 -> V_305 = V_306 ;
else V_35 -> V_305 = V_307 ;
} else if( V_289 == V_294 ) {
if( V_28 -> V_126 == 0 ) {
V_35 -> V_305 = V_308 ;
} else if( V_28 -> V_126 == V_304 )
V_35 -> V_305 = V_309 ;
else V_35 -> V_305 = V_310 ;
}
break;
case V_311 :
break;
case V_312 :
break;
case V_313 :
if( V_28 -> V_126 == V_314 ) {
V_35 -> V_271 = false ;
} else if( V_28 -> V_126 == V_315 ) {
V_35 -> V_271 = true ;
}
break;
case V_316 :
break;
case V_317 :
break;
case V_318 :
V_288 = - V_33 ;
break;
case V_319 :
V_4 -> V_264 = ! ! V_28 -> V_126 ;
if( V_4 -> V_264 == false ) {
V_289 = 0 ;
V_290 = 0 ;
V_4 -> V_265 = V_272 ;
V_35 -> V_271 = false ;
V_35 -> V_305 = false ;
}
break;
default:
V_288 = - V_33 ;
break;
}
return V_288 ;
}
int F_59 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_32 * V_28 ,
char * V_29 )
{
return - V_33 ;
}
int F_60 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_288 = 0 ;
if( V_28 -> V_49 ) {
if ( ( V_28 -> V_49 < 2 ) || ( V_29 [ 1 ] + 2 != V_28 -> V_49 ) ) {
V_288 = - V_140 ;
goto V_320;
}
if( V_28 -> V_49 > V_77 ) {
V_288 = - V_321 ;
goto V_320;
}
memset ( V_35 -> V_322 , 0 , V_77 ) ;
if( F_61 ( V_35 -> V_322 , V_29 , V_28 -> V_49 ) ) {
V_288 = - V_323 ;
goto V_320;
}
V_35 -> V_324 = V_28 -> V_49 ;
} else {
memset ( V_35 -> V_322 , 0 , V_77 ) ;
V_35 -> V_324 = 0 ;
}
V_320:
return V_288 ;
}
int F_62 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
int V_288 = 0 ;
int V_325 = V_28 -> V_49 ;
V_28 -> V_49 = 0 ;
if( V_35 -> V_324 > 0 ) {
V_28 -> V_49 = V_35 -> V_324 ;
if( V_35 -> V_324 <= V_325 ) {
if( F_63 ( V_29 , V_35 -> V_322 , V_35 -> V_324 ) ) {
V_288 = - V_323 ;
}
} else
V_288 = - V_326 ;
}
return V_288 ;
}
int F_64 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
struct V_327 * V_328 = (struct V_327 * ) V_29 ;
struct V_329 * V_330 = NULL ;
T_10 V_331 ;
T_7 V_332 [ 6 ] ;
int V_333 , V_334 = 0 ;
T_7 V_335 [ V_336 ] ;
T_7 V_337 [ 64 ] ;
T_11 V_338 = 0 , V_339 = 0 ;
T_7 * V_76 ;
T_11 V_340 ;
T_7 V_341 [ 64 ] ;
int V_288 = 0 ;
F_10 ( L_66 ) ;
V_340 = sizeof( * V_330 ) ;
V_76 = F_65 ( ( int ) V_340 , ( int ) V_342 ) ;
if ( V_76 == NULL )
return - V_321 ;
memset ( V_76 , 0 , V_340 ) ;
V_330 = (struct V_329 * ) V_76 ;
switch ( V_328 -> V_343 ) {
case V_344 :
V_331 = V_345 ;
break;
case V_346 :
V_331 = V_347 ;
break;
case V_348 :
V_331 = V_349 ;
break;
case V_350 :
V_331 = V_351 ;
break;
default:
F_10 ( L_67 , V_328 -> V_343 ) ;
V_288 = - V_321 ;
goto error;
}
memcpy ( V_332 , V_328 -> V_332 . V_90 , V_352 ) ;
V_333 = ( V_28 -> V_50 & V_248 ) - 1 ;
if( V_328 -> V_353 & V_354 )
V_334 = 1 ;
if( V_328 -> V_353 & V_355 ) {
V_338 = V_336 ;
memcpy ( V_335 , V_328 -> V_356 , V_338 ) ;
}
if( V_328 -> V_339 ) {
V_339 = V_328 -> V_339 ;
memcpy ( V_337 , & V_328 -> V_337 [ 0 ] , V_339 ) ;
}
memset ( V_341 , 0 , 64 ) ;
if ( V_339 > 0 ) {
memcpy ( V_341 , V_337 , V_339 ) ;
if ( V_339 == 32 ) {
memcpy ( & V_341 [ 16 ] , & V_337 [ 24 ] , 8 ) ;
memcpy ( & V_341 [ 24 ] , & V_337 [ 16 ] , 8 ) ;
}
}
memcpy ( V_330 -> V_332 , V_332 , V_352 ) ;
V_330 -> V_86 . V_357 . V_331 = ( int ) V_331 ;
V_330 -> V_86 . V_357 . V_334 = V_334 ;
V_330 -> V_86 . V_357 . V_358 = V_333 ;
V_330 -> V_86 . V_357 . V_339 = V_339 ;
V_330 -> V_86 . V_357 . V_337 = ( T_7 * ) V_341 ;
V_330 -> V_86 . V_357 . V_335 = ( T_7 * ) V_335 ;
V_330 -> V_86 . V_357 . V_338 = V_338 ;
#if 0
printk("param->u.wpa_key.alg_name =%d\n",param->u.wpa_key.alg_name);
printk(KERN_DEBUG "param->addr=%pM\n", param->addr);
printk("param->u.wpa_key.set_tx =%d\n",param->u.wpa_key.set_tx);
printk("param->u.wpa_key.key_index =%d\n",param->u.wpa_key.key_index);
printk("param->u.wpa_key.key_len =%d\n",param->u.wpa_key.key_len);
printk("param->u.wpa_key.key =");
for(ii=0;ii<param->u.wpa_key.key_len;ii++)
printk("%02x:",param->u.wpa_key.key[ii]);
printk("\n");
printk("param->u.wpa_key.seq_len =%d\n",param->u.wpa_key.seq_len);
printk("param->u.wpa_key.seq =");
for(ii=0;ii<param->u.wpa_key.seq_len;ii++)
printk("%02x:",param->u.wpa_key.seq[ii]);
printk("\n");
printk("...........\n");
#endif
if( V_330 -> V_86 . V_357 . V_331 == V_345 ) {
if( V_330 -> V_86 . V_357 . V_358 == 0 ) {
V_4 -> V_359 ++ ;
}
if( ( V_4 -> V_359 == 1 ) && ( V_330 -> V_86 . V_357 . V_358 == 1 ) ) {
V_4 -> V_359 ++ ;
}
if( ( V_4 -> V_359 == 2 ) && ( V_330 -> V_86 . V_357 . V_358 == 2 ) ) {
V_4 -> V_359 ++ ;
}
if( ( V_4 -> V_359 == 3 ) && ( V_330 -> V_86 . V_357 . V_358 == 3 ) ) {
V_4 -> V_359 ++ ;
}
}
if( V_4 -> V_359 == 4 ) {
F_29 ( L_68 ) ;
V_4 -> V_359 = 0 ;
V_4 -> V_222 = true ;
}
F_12 ( & V_4 -> V_47 ) ;
V_288 = F_66 ( V_4 , V_330 , true ) ;
F_15 ( & V_4 -> V_47 ) ;
error:
F_67 ( V_330 ) ;
return V_288 ;
}
int F_68 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
return - V_33 ;
}
int F_69 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_34 * V_28 ,
char * V_29 )
{
T_1 V_4 = ( T_1 ) F_2 ( V_3 ) ;
T_2 V_35 = & ( V_4 -> V_36 ) ;
struct V_360 * V_361 = (struct V_360 * ) V_29 ;
int V_288 = 0 ;
if( memcmp ( V_35 -> V_212 , V_361 -> V_332 . V_90 , V_352 ) ) {
V_288 = - V_140 ;
return V_288 ;
}
switch( V_361 -> V_84 ) {
case V_362 :
break;
case V_363 :
if( V_4 -> V_48 == true ) {
F_29 ( L_69 ) ;
memset ( V_35 -> V_211 , 0xFF , 6 ) ;
F_70 ( & V_4 -> V_258 , V_4 -> V_260 ) ;
F_14 ( ( void * ) V_4 , V_364 , NULL ) ;
}
break;
default:
V_288 = - V_33 ;
}
return V_288 ;
}
