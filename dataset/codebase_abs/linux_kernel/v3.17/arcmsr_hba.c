static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( V_4 != V_5 )
return - V_6 ;
if ( V_3 > V_7 )
V_3 = V_7 ;
F_2 ( V_2 , V_8 , V_3 ) ;
return V_3 ;
}
static void F_3 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 :
case V_13 :
break;
case V_14 : {
F_4 ( & V_10 -> V_15 -> V_16 ,
sizeof( struct V_17 ) ,
V_10 -> V_18 , V_10 -> V_19 ) ;
}
}
}
static bool F_5 ( struct V_9 * V_10 )
{
struct V_20 * V_15 = V_10 -> V_15 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
V_10 -> V_21 = F_6 ( F_7 ( V_15 , 0 ) , F_8 ( V_15 , 0 ) ) ;
if ( ! V_10 -> V_21 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
break;
}
case V_14 : {
void T_1 * V_25 , * V_26 ;
V_25 = F_6 ( F_7 ( V_15 , 0 ) , F_8 ( V_15 , 0 ) ) ;
if ( ! V_25 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_26 = F_6 ( F_7 ( V_15 , 2 ) , F_8 ( V_15 , 2 ) ) ;
if ( ! V_26 ) {
F_10 ( V_25 ) ;
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_10 -> V_25 = V_25 ;
V_10 -> V_26 = V_26 ;
break;
}
case V_13 : {
V_10 -> V_27 = F_11 ( F_7 ( V_15 , 1 ) , F_8 ( V_15 , 1 ) ) ;
if ( ! V_10 -> V_27 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
if ( F_12 ( & V_10 -> V_27 -> V_28 ) & V_29 ) {
F_13 ( V_30 , & V_10 -> V_27 -> V_31 ) ;
return true ;
}
break;
}
}
return true ;
}
static void F_14 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
F_10 ( V_10 -> V_21 ) ;
}
break;
case V_14 : {
F_10 ( V_10 -> V_25 ) ;
F_10 ( V_10 -> V_26 ) ;
}
break;
case V_13 : {
F_10 ( V_10 -> V_27 ) ;
}
}
}
static T_2 F_15 ( int V_32 , void * V_33 )
{
T_2 V_34 ;
struct V_9 * V_10 = V_33 ;
V_34 = F_16 ( V_10 ) ;
return V_34 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_3 V_37 , int * V_38 )
{
int V_39 , V_40 , V_41 , V_42 , V_43 ;
unsigned char * V_44 ;
V_44 = F_18 ( V_36 ) ;
if ( V_44 ) {
V_39 = F_19 ( V_44 , V_37 , & V_38 [ 2 ] , & V_38 [ 0 ] , & V_38 [ 1 ] ) ;
F_20 ( V_44 ) ;
if ( V_39 != - 1 )
return V_39 ;
}
V_43 = V_37 ;
V_40 = 64 ;
V_41 = 32 ;
V_42 = V_43 / ( V_40 * V_41 ) ;
if ( V_42 > 1024 ) {
V_40 = 255 ;
V_41 = 63 ;
V_42 = V_43 / ( V_40 * V_41 ) ;
}
V_38 [ 0 ] = V_40 ;
V_38 [ 1 ] = V_41 ;
V_38 [ 2 ] = V_42 ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_20 * V_15 = V_10 -> V_15 ;
T_4 V_33 ;
F_22 ( V_15 , V_45 , & V_33 ) ;
V_10 -> V_33 = V_33 ;
switch ( V_33 ) {
case 0x1880 : {
V_10 -> V_11 = V_13 ;
}
break;
case 0x1201 : {
V_10 -> V_11 = V_14 ;
}
break;
default: V_10 -> V_11 = V_12 ;
}
}
static T_5 F_23 ( struct V_9 * V_10 )
{
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( & V_47 -> V_49 ) &
V_50 ) {
F_13 ( V_50 ,
& V_47 -> V_49 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_5 F_25 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( V_47 -> V_51 )
& V_52 ) {
F_13 ( V_53 ,
V_47 -> V_51 ) ;
F_13 ( V_54 ,
V_47 -> V_55 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_5 F_26 ( struct V_9 * V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_56 -> V_27 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( & V_58 -> V_28 )
& V_29 ) {
F_13 ( V_30 ,
& V_58 -> V_31 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
int V_59 = 30 ;
F_13 ( V_60 , & V_47 -> V_61 ) ;
do {
if ( F_23 ( V_10 ) )
break;
else {
V_59 -- ;
F_9 ( V_22 L_2 , V_10 -> V_23 -> V_24 , V_59 ) ;
}
} while ( V_59 != 0 );
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
int V_59 = 30 ;
F_13 ( V_62 , V_47 -> V_55 ) ;
do {
if ( F_25 ( V_10 ) )
break;
else {
V_59 -- ;
F_9 ( V_22 L_3 , V_10 -> V_23 -> V_24 , V_59 ) ;
}
} while ( V_59 != 0 );
}
static void F_29 ( struct V_9 * V_56 )
{
struct V_57 * V_47 = (struct V_57 * ) V_56 -> V_27 ;
int V_59 = 30 ;
F_13 ( V_60 , & V_47 -> V_61 ) ;
F_13 ( V_63 , & V_47 -> V_64 ) ;
do {
if ( F_26 ( V_56 ) ) {
break;
} else {
V_59 -- ;
F_9 ( V_22 L_3 , V_56 -> V_23 -> V_24 , V_59 ) ;
}
} while ( V_59 != 0 );
return;
}
static void F_30 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
F_27 ( V_10 ) ;
}
break;
case V_14 : {
F_28 ( V_10 ) ;
}
break;
case V_13 : {
F_29 ( V_10 ) ;
}
}
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_20 * V_15 = V_10 -> V_15 ;
void * V_65 ;
T_6 V_66 ;
struct V_67 * V_68 ;
int V_48 = 0 , V_69 = 0 ;
T_6 V_70 ;
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
T_7 V_74 ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ )
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ )
V_10 -> V_77 [ V_48 ] [ V_69 ] = V_78 ;
V_72 = V_79 ;
V_73 = V_80 ;
V_74 = V_10 -> V_81 ;
if( ( V_74 & 0xFF ) >= 3 ) {
V_72 = ( V_82 << ( ( V_74 >> 8 ) & 0xFF ) ) * 1024 ;
V_73 = ( V_72 / 4096 ) ;
}
V_10 -> V_23 -> V_83 = V_72 / 512 ;
V_10 -> V_23 -> V_84 = V_73 ;
V_71 = F_32 ( sizeof( struct V_67 ) + ( V_73 - 1 ) * sizeof( struct V_85 ) , 32 ) ;
V_10 -> V_86 = V_71 * V_87 ;
V_65 = F_33 ( & V_15 -> V_16 , V_10 -> V_86 , & V_66 , V_88 ) ;
if( ! V_65 ) {
F_9 ( V_22 L_4 , V_10 -> V_23 -> V_24 ) ;
return - V_89 ;
}
V_10 -> V_65 = V_65 ;
V_10 -> V_66 = V_66 ;
memset ( V_65 , 0 , V_10 -> V_86 ) ;
V_68 = V_65 ;
V_10 -> V_90 = ( unsigned long ) V_65 - ( unsigned long ) V_66 ;
for( V_48 = 0 ; V_48 < V_87 ; V_48 ++ ) {
V_70 = V_66 + F_34 ( struct V_67 , V_91 ) ;
V_68 -> V_92 = ( ( V_10 -> V_11 == V_13 ) ? V_70 : ( V_70 >> 5 ) ) ;
V_10 -> V_93 [ V_48 ] = V_68 ;
V_68 -> V_10 = V_10 ;
F_35 ( & V_68 -> V_94 ) ;
F_36 ( & V_68 -> V_94 , & V_10 -> V_95 ) ;
V_68 = (struct V_67 * ) ( ( unsigned long ) V_68 + V_71 ) ;
V_66 = V_66 + V_71 ;
}
return 0 ;
}
static void F_37 ( struct V_96 * V_97 )
{
struct V_9 * V_10 = F_38 ( V_97 , struct V_9 , V_98 ) ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
char * V_99 = ( char * ) V_10 -> V_100 ;
T_7 T_1 * V_101 = ( T_7 T_1 * ) ( & V_47 -> V_102 [ 0 ] ) ;
char T_1 * V_103 = ( char T_1 * ) ( & V_47 -> V_102 [ 21 ] ) ;
int V_104 , V_105 ;
struct V_1 * V_106 ;
char V_107 ;
F_39 ( & V_10 -> V_108 ) ;
if ( F_12 ( V_101 ) == V_109 ) {
for( V_104 = 0 ; V_104 < V_75 - 1 ; V_104 ++ ) {
V_107 = ( * V_99 ) ^ F_40 ( V_103 ) ;
if ( V_107 != 0 ) {
char V_110 ;
* V_99 = F_40 ( V_103 ) ;
V_110 = * V_99 ;
for( V_105 = 0 ; V_105 < V_76 ; V_105 ++ ) {
if( ( V_110 & 0x01 ) == 1 && ( V_107 & 0x01 ) == 1 ) {
F_41 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
} else if( ( V_110 & 0x01 ) == 0 && ( V_107 & 0x01 ) == 1 ) {
V_106 = F_42 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
if ( V_106 != NULL ) {
F_43 ( V_106 ) ;
F_44 ( V_106 ) ;
}
}
V_110 >>= 1 ;
V_107 >>= 1 ;
}
}
V_103 ++ ;
V_99 ++ ;
}
}
break;
}
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
char * V_99 = ( char * ) V_10 -> V_100 ;
T_7 T_1 * V_101 = ( T_7 T_1 * ) ( & V_47 -> V_102 [ 0 ] ) ;
char T_1 * V_103 = ( char T_1 * ) ( & V_47 -> V_102 [ 21 ] ) ;
int V_104 , V_105 ;
struct V_1 * V_106 ;
char V_107 ;
F_39 ( & V_10 -> V_108 ) ;
if ( F_12 ( V_101 ) == V_109 ) {
for( V_104 = 0 ; V_104 < V_75 - 1 ; V_104 ++ ) {
V_107 = ( * V_99 ) ^ F_40 ( V_103 ) ;
if ( V_107 != 0 ) {
char V_110 ;
* V_99 = F_40 ( V_103 ) ;
V_110 = * V_99 ;
for( V_105 = 0 ; V_105 < V_76 ; V_105 ++ ) {
if( ( V_110 & 0x01 ) == 1 && ( V_107 & 0x01 ) == 1 ) {
F_41 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
} else if( ( V_110 & 0x01 ) == 0 && ( V_107 & 0x01 ) == 1 ) {
V_106 = F_42 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
if ( V_106 != NULL ) {
F_43 ( V_106 ) ;
F_44 ( V_106 ) ;
}
}
V_110 >>= 1 ;
V_107 >>= 1 ;
}
}
V_103 ++ ;
V_99 ++ ;
}
}
}
break;
case V_13 : {
struct V_57 * V_47 = V_10 -> V_27 ;
char * V_99 = ( char * ) V_10 -> V_100 ;
T_7 T_1 * V_101 = ( T_7 T_1 * ) ( & V_47 -> V_111 [ 0 ] ) ;
char T_1 * V_103 = ( char T_1 * ) ( & V_47 -> V_111 [ 21 ] ) ;
int V_104 , V_105 ;
struct V_1 * V_106 ;
char V_107 ;
F_39 ( & V_10 -> V_108 ) ;
if ( F_12 ( V_101 ) == V_109 ) {
for ( V_104 = 0 ; V_104 < V_75 - 1 ; V_104 ++ ) {
V_107 = ( * V_99 ) ^ F_40 ( V_103 ) ;
if ( V_107 != 0 ) {
char V_110 ;
* V_99 = F_40 ( V_103 ) ;
V_110 = * V_99 ;
for ( V_105 = 0 ; V_105 < V_76 ; V_105 ++ ) {
if ( ( V_110 & 0x01 ) == 1 && ( V_107 & 0x01 ) == 1 ) {
F_41 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
} else if ( ( V_110 & 0x01 ) == 0 && ( V_107 & 0x01 ) == 1 ) {
V_106 = F_42 ( V_10 -> V_23 , 0 , V_104 , V_105 ) ;
if ( V_106 != NULL ) {
F_43 ( V_106 ) ;
F_44 ( V_106 ) ;
}
}
V_110 >>= 1 ;
V_107 >>= 1 ;
}
}
V_103 ++ ;
V_99 ++ ;
}
}
}
}
}
static int F_45 ( struct V_20 * V_15 , const struct V_112 * V_113 )
{
struct V_114 * V_23 ;
struct V_9 * V_10 ;
T_5 V_115 , V_116 ;
int error ;
error = F_46 ( V_15 ) ;
if( error ) {
return - V_117 ;
}
V_23 = F_47 ( & V_118 , sizeof( struct V_9 ) ) ;
if( ! V_23 ) {
goto V_119;
}
error = F_48 ( V_15 , F_49 ( 64 ) ) ;
if( error ) {
error = F_48 ( V_15 , F_49 ( 32 ) ) ;
if( error ) {
F_9 ( V_120
L_5 ,
V_23 -> V_24 ) ;
goto V_121;
}
}
F_50 ( & V_122 ) ;
V_115 = V_15 -> V_115 -> V_123 ;
V_116 = V_15 -> V_124 ;
V_10 = (struct V_9 * ) V_23 -> V_125 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_15 = V_15 ;
V_10 -> V_23 = V_23 ;
V_23 -> V_126 = V_76 ;
V_23 -> V_127 = V_75 ;
V_23 -> V_128 = 16 ;
V_23 -> V_129 = V_87 ;
V_23 -> V_130 = V_7 ;
V_23 -> V_131 = V_132 ;
V_23 -> V_133 = ( V_115 << 8 ) | V_116 ;
F_51 ( V_15 , V_23 ) ;
F_52 ( V_15 ) ;
error = F_53 ( V_15 , L_6 ) ;
if( error ) {
goto V_121;
}
F_54 ( & V_10 -> V_134 ) ;
F_54 ( & V_10 -> V_135 ) ;
V_10 -> V_136 |= ( V_137 |
V_138 |
V_139 ) ;
V_10 -> V_136 &= ~ V_140 ;
F_35 ( & V_10 -> V_95 ) ;
F_21 ( V_10 ) ;
error = F_5 ( V_10 ) ;
if( ! error ) {
goto V_141;
}
error = F_55 ( V_10 ) ;
if( ! error ) {
goto V_142;
}
error = F_31 ( V_10 ) ;
if( error ) {
goto V_143;
}
F_56 ( V_10 ) ;
error = F_57 ( V_23 , & V_15 -> V_16 ) ;
if( error ) {
goto V_144;
}
error = F_58 ( V_15 -> V_32 , F_15 , V_145 , L_6 , V_10 ) ;
if( error ) {
goto V_146;
}
V_23 -> V_32 = V_15 -> V_32 ;
F_59 ( V_23 ) ;
F_60 ( & V_10 -> V_98 , F_37 ) ;
F_61 ( & V_10 -> V_108 , 16 ) ;
F_61 ( & V_10 -> V_147 , 16 ) ;
V_10 -> V_148 = V_149 ;
F_62 ( & V_10 -> V_150 ) ;
V_10 -> V_150 . V_151 = V_152 + F_63 ( 6 * V_153 ) ;
V_10 -> V_150 . V_154 = ( unsigned long ) V_10 ;
V_10 -> V_150 . V_155 = & V_156 ;
F_64 ( & V_10 -> V_150 ) ;
if( F_65 ( V_10 ) )
goto V_157;
return 0 ;
V_157:
V_146:
F_66 ( V_23 ) ;
V_144:
F_67 ( V_10 ) ;
F_30 ( V_10 ) ;
F_68 ( V_10 ) ;
V_143:
F_3 ( V_10 ) ;
V_142:
F_14 ( V_10 ) ;
V_141:
F_69 ( V_15 ) ;
V_121:
F_70 ( V_23 ) ;
V_119:
F_71 ( V_15 ) ;
return - V_117 ;
}
static T_5 F_72 ( struct V_9 * V_10 )
{
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
F_13 ( V_158 , & V_47 -> V_61 ) ;
if ( ! F_23 ( V_10 ) ) {
F_9 ( V_22
L_7
, V_10 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_5 F_73 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
F_13 ( V_159 , V_47 -> V_55 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22
L_7
, V_10 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_5 F_74 ( struct V_9 * V_56 )
{
struct V_57 * V_47 = (struct V_57 * ) V_56 -> V_27 ;
F_13 ( V_158 , & V_47 -> V_61 ) ;
F_13 ( V_63 , & V_47 -> V_64 ) ;
if ( ! F_26 ( V_56 ) ) {
F_9 ( V_22
L_7
, V_56 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_5 F_75 ( struct V_9 * V_10 )
{
T_5 V_160 = 0 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
V_160 = F_72 ( V_10 ) ;
}
break;
case V_14 : {
V_160 = F_73 ( V_10 ) ;
}
break;
case V_13 : {
V_160 = F_74 ( V_10 ) ;
}
}
return V_160 ;
}
static bool F_76 ( struct V_9 * V_161 )
{
struct V_17 * V_47 = V_161 -> V_18 ;
F_13 ( V_162 , V_47 -> V_55 ) ;
if ( ! F_25 ( V_161 ) ) {
F_9 ( V_163 L_8 , V_161 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static void F_77 ( struct V_67 * V_164 )
{
struct V_165 * V_166 = V_164 -> V_166 ;
F_78 ( V_166 ) ;
}
static void F_79 ( struct V_67 * V_164 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_165 * V_166 = V_164 -> V_166 ;
unsigned long V_167 ;
F_80 ( & V_10 -> V_168 ) ;
F_77 ( V_164 ) ;
V_164 -> V_169 = V_170 ;
F_81 ( & V_10 -> V_135 , V_167 ) ;
F_36 ( & V_164 -> V_94 , & V_10 -> V_95 ) ;
F_82 ( & V_10 -> V_135 , V_167 ) ;
V_166 -> V_171 ( V_166 ) ;
}
static void F_83 ( struct V_67 * V_164 )
{
struct V_165 * V_166 = V_164 -> V_166 ;
struct V_172 * V_173 = (struct V_172 * ) V_166 -> V_174 ;
V_166 -> V_175 = V_176 << 16 ;
if ( V_173 ) {
int V_177 =
sizeof( struct V_172 ) < V_178
? sizeof( struct V_172 ) : V_178 ;
memset ( V_173 , 0 , V_178 ) ;
memcpy ( V_173 , V_164 -> V_91 . V_179 , V_177 ) ;
V_173 -> V_180 = V_181 ;
V_173 -> V_182 = 1 ;
}
}
static T_8 F_84 ( struct V_9 * V_10 )
{
T_8 V_183 = 0 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_183 = F_12 ( & V_47 -> V_184 ) ;
F_13 ( V_183 | V_185 , \
& V_47 -> V_184 ) ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
V_183 = F_12 ( V_47 -> V_186 ) ;
F_13 ( 0 , V_47 -> V_186 ) ;
}
break;
case V_13 : {
struct V_57 * V_47 = (struct V_57 * ) V_10 -> V_27 ;
V_183 = F_12 ( & V_47 -> V_187 ) ;
F_13 ( V_183 | V_188 , & V_47 -> V_187 ) ;
}
break;
}
return V_183 ;
}
static void F_85 ( struct V_9 * V_10 ,
struct V_67 * V_164 , bool error )
{
T_5 V_113 , V_105 ;
V_113 = V_164 -> V_166 -> V_189 -> V_113 ;
V_105 = V_164 -> V_166 -> V_189 -> V_105 ;
if ( ! error ) {
if ( V_10 -> V_77 [ V_113 ] [ V_105 ] == V_78 )
V_10 -> V_77 [ V_113 ] [ V_105 ] = V_190 ;
V_164 -> V_166 -> V_175 = V_176 << 16 ;
F_79 ( V_164 ) ;
} else{
switch ( V_164 -> V_91 . V_191 ) {
case V_192 : {
V_10 -> V_77 [ V_113 ] [ V_105 ] = V_78 ;
V_164 -> V_166 -> V_175 = V_193 << 16 ;
F_79 ( V_164 ) ;
}
break;
case V_194 :
case V_195 : {
V_10 -> V_77 [ V_113 ] [ V_105 ] = V_78 ;
V_164 -> V_166 -> V_175 = V_196 << 16 ;
F_79 ( V_164 ) ;
}
break;
case V_197 : {
V_10 -> V_77 [ V_113 ] [ V_105 ] = V_190 ;
F_83 ( V_164 ) ;
F_79 ( V_164 ) ;
}
break;
default:
F_9 ( V_22
L_9
, V_10 -> V_23 -> V_24
, V_113
, V_105
, V_164 -> V_91 . V_191 ) ;
V_10 -> V_77 [ V_113 ] [ V_105 ] = V_78 ;
V_164 -> V_166 -> V_175 = V_193 << 16 ;
F_79 ( V_164 ) ;
break;
}
}
}
static void F_86 ( struct V_9 * V_10 , struct V_67 * V_198 , bool error )
{
int V_113 , V_105 ;
if ( ( V_198 -> V_10 != V_10 ) || ( V_198 -> V_169 != V_199 ) ) {
if ( V_198 -> V_169 == V_200 ) {
struct V_165 * V_201 = V_198 -> V_166 ;
if ( V_201 ) {
V_113 = V_201 -> V_189 -> V_113 ;
V_105 = V_201 -> V_189 -> V_105 ;
V_201 -> V_175 |= V_202 << 16 ;
F_79 ( V_198 ) ;
F_9 ( V_22 L_10 ,
V_10 -> V_23 -> V_24 , V_198 ) ;
}
return;
}
F_9 ( V_22 L_11
L_12
L_13
, V_10 -> V_23 -> V_24
, V_10
, V_198
, V_198 -> V_10
, V_198 -> V_169
, F_87 ( & V_10 -> V_168 ) ) ;
return;
}
F_85 ( V_10 , V_198 , error ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
int V_48 = 0 ;
T_7 V_203 ;
struct V_204 * V_205 ;
bool error ;
struct V_67 * V_198 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
T_7 V_49 ;
V_49 = F_12 ( & V_47 -> V_49 ) &
V_10 -> V_206 ;
F_13 ( V_49 , & V_47 -> V_49 ) ;
while( ( ( V_203 = F_12 ( & V_47 -> V_207 ) ) != 0xFFFFFFFF )
&& ( V_48 ++ < V_208 ) ) {
V_205 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_198 = F_38 ( V_205 , struct V_67 , V_91 ) ;
error = ( V_203 & V_209 ) ? true : false ;
F_86 ( V_10 , V_198 , error ) ;
}
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
F_13 ( V_210 , V_47 -> V_51 ) ;
for ( V_48 = 0 ; V_48 < V_211 ; V_48 ++ ) {
if ( ( V_203 = F_12 ( & V_47 -> V_212 [ V_48 ] ) ) != 0 ) {
F_13 ( 0 , & V_47 -> V_212 [ V_48 ] ) ;
V_205 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_198 = F_38 ( V_205 , struct V_67 , V_91 ) ;
error = ( V_203 & V_209 ) ? true : false ;
F_86 ( V_10 , V_198 , error ) ;
}
V_47 -> V_213 [ V_48 ] = 0 ;
}
V_47 -> V_214 = 0 ;
V_47 -> V_215 = 0 ;
}
break;
case V_13 : {
struct V_57 * V_47 = V_10 -> V_27 ;
struct V_204 * V_205 ;
T_7 V_203 , V_216 ;
bool error ;
struct V_67 * V_198 ;
while ( ( F_12 ( & V_47 -> V_217 ) & V_218 ) && ( V_48 ++ < V_208 ) ) {
V_203 = F_12 ( & V_47 -> V_219 ) ;
V_216 = ( V_203 & 0xFFFFFFF0 ) ;
V_205 = (struct V_204 * ) ( V_10 -> V_90 + V_216 ) ;
V_198 = F_38 ( V_205 , struct V_67 , V_91 ) ;
error = ( V_203 & V_220 ) ? true : false ;
F_86 ( V_10 , V_198 , error ) ;
}
}
}
}
static void F_89 ( struct V_20 * V_15 )
{
struct V_114 * V_23 = F_90 ( V_15 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_125 ;
int V_221 = 0 ;
F_91 ( V_10 ) ;
F_66 ( V_23 ) ;
F_92 ( & V_10 -> V_98 ) ;
F_93 ( & V_10 -> V_150 ) ;
F_84 ( V_10 ) ;
F_67 ( V_10 ) ;
F_30 ( V_10 ) ;
V_10 -> V_136 |= V_140 ;
V_10 -> V_136 &= ~ V_222 ;
for ( V_221 = 0 ; V_221 < V_208 ; V_221 ++ ) {
if ( ! F_87 ( & V_10 -> V_168 ) )
break;
F_16 ( V_10 ) ;
F_24 ( 25 ) ;
}
if ( F_87 ( & V_10 -> V_168 ) ) {
int V_48 ;
F_75 ( V_10 ) ;
F_88 ( V_10 ) ;
for ( V_48 = 0 ; V_48 < V_87 ; V_48 ++ ) {
struct V_67 * V_164 = V_10 -> V_93 [ V_48 ] ;
if ( V_164 -> V_169 == V_199 ) {
V_164 -> V_169 = V_200 ;
V_164 -> V_166 -> V_175 = V_202 << 16 ;
F_79 ( V_164 ) ;
}
}
}
F_94 ( V_15 -> V_32 , V_10 ) ;
F_68 ( V_10 ) ;
F_3 ( V_10 ) ;
F_14 ( V_10 ) ;
F_69 ( V_15 ) ;
F_70 ( V_23 ) ;
F_71 ( V_15 ) ;
}
static void F_95 ( struct V_20 * V_15 )
{
struct V_114 * V_23 = F_90 ( V_15 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_125 ;
F_93 ( & V_10 -> V_150 ) ;
F_84 ( V_10 ) ;
F_92 ( & V_10 -> V_98 ) ;
F_67 ( V_10 ) ;
F_30 ( V_10 ) ;
}
static int F_96 ( void )
{
int error = 0 ;
error = F_97 ( & V_223 ) ;
return error ;
}
static void F_98 ( void )
{
F_99 ( & V_223 ) ;
}
static void F_100 ( struct V_9 * V_10 ,
T_8 V_224 )
{
T_8 V_225 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_225 = V_224 & ~ ( V_226 |
V_227 |
V_228 ) ;
F_13 ( V_225 , & V_47 -> V_184 ) ;
V_10 -> V_206 = ~ ( V_224 & V_225 ) & 0x000000ff ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
V_225 = V_224 | ( V_229 |
V_230 |
V_231 |
V_52 ) ;
F_13 ( V_225 , V_47 -> V_186 ) ;
V_10 -> V_206 = ( V_224 | V_225 ) & 0x0000000f ;
}
break;
case V_13 : {
struct V_57 * V_47 = V_10 -> V_27 ;
V_225 = ~ ( V_232 | V_233 | V_234 ) ;
F_13 ( V_224 & V_225 , & V_47 -> V_187 ) ;
V_10 -> V_206 = ~ ( V_224 & V_225 ) & 0x0000000f ;
}
}
}
static int F_101 ( struct V_9 * V_10 ,
struct V_67 * V_164 , struct V_165 * V_166 )
{
struct V_204 * V_91 = (struct V_204 * ) & V_164 -> V_91 ;
T_9 * V_235 = ( T_9 * ) & V_91 -> V_236 ;
T_10 V_237 , V_238 ;
int V_239 = 0x30 ;
T_10 V_240 = 0 ;
int V_48 ;
struct V_241 * V_242 ;
int V_243 ;
V_164 -> V_166 = V_166 ;
memset ( V_91 , 0 , sizeof( struct V_204 ) ) ;
V_91 -> V_244 = V_166 -> V_189 -> V_113 ;
V_91 -> V_245 = V_166 -> V_189 -> V_105 ;
V_91 -> V_246 = 1 ;
V_91 -> V_247 = 0 ;
memcpy ( V_91 -> V_248 , V_166 -> V_249 , V_166 -> V_250 ) ;
V_243 = F_102 ( V_166 ) ;
if ( F_103 ( V_243 > V_10 -> V_23 -> V_84 || V_243 < 0 ) )
return V_251 ;
F_104 (pcmd, sg, nseg, i) {
V_240 = F_105 ( F_106 ( V_242 ) ) ;
V_237 = F_105 ( F_107 ( F_108 ( V_242 ) ) ) ;
V_238 = F_105 ( F_109 ( F_108 ( V_242 ) ) ) ;
if ( V_238 == 0 ) {
struct V_252 * V_253 = (struct V_252 * ) V_235 ;
V_253 -> V_254 = V_237 ;
V_253 -> V_240 = V_240 ;
V_235 += sizeof ( struct V_252 ) ;
V_239 += sizeof ( struct V_252 ) ;
} else {
struct V_85 * V_253 = (struct V_85 * ) V_235 ;
V_253 -> V_255 = V_238 ;
V_253 -> V_254 = V_237 ;
V_253 -> V_240 = V_240 | F_105 ( V_256 ) ;
V_235 += sizeof ( struct V_85 ) ;
V_239 += sizeof ( struct V_85 ) ;
}
}
V_91 -> V_257 = ( T_5 ) V_243 ;
V_91 -> V_258 = F_110 ( V_166 ) ;
V_91 -> V_259 = V_239 / 0x100 + ( V_239 % 0x100 ? 1 : 0 ) ;
if ( V_239 > 256 )
V_91 -> V_260 |= V_261 ;
if ( V_166 -> V_262 == V_263 )
V_91 -> V_260 |= V_264 ;
V_164 -> V_265 = V_239 ;
return V_266 ;
}
static void F_111 ( struct V_9 * V_10 , struct V_67 * V_164 )
{
T_7 V_92 = V_164 -> V_92 ;
struct V_204 * V_91 = (struct V_204 * ) & V_164 -> V_91 ;
F_39 ( & V_10 -> V_168 ) ;
V_164 -> V_169 = V_199 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
if ( V_91 -> V_260 & V_261 )
F_13 ( V_92 | V_267 ,
& V_47 -> V_268 ) ;
else {
F_13 ( V_92 , & V_47 -> V_268 ) ;
}
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
T_7 V_269 , V_270 = V_47 -> V_215 ;
V_269 = ( ( V_270 + 1 ) % V_211 ) ;
F_13 ( 0 , & V_47 -> V_213 [ V_269 ] ) ;
if ( V_91 -> V_260 & V_261 ) {
F_13 ( V_92 | V_267 ,\
& V_47 -> V_213 [ V_270 ] ) ;
} else {
F_13 ( V_92 , & V_47 -> V_213 [ V_270 ] ) ;
}
V_270 ++ ;
V_270 %= V_211 ;
V_47 -> V_215 = V_270 ;
F_13 ( V_271 , V_47 -> V_55 ) ;
}
break;
case V_13 : {
struct V_57 * V_58 = (struct V_57 * ) V_10 -> V_27 ;
T_7 V_272 , V_265 ;
V_265 = ( V_164 -> V_265 > 0x300 ) ? 0x300 : V_164 -> V_265 ;
V_272 = ( V_92 | ( ( V_265 - 1 ) >> 6 ) | 1 ) ;
if ( V_10 -> V_273 ) {
F_13 ( V_10 -> V_273 , & V_58 -> V_274 ) ;
F_13 ( V_272 , & V_58 -> V_275 ) ;
} else {
F_13 ( V_272 , & V_58 -> V_275 ) ;
}
}
}
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_10 -> V_136 &= ~ V_276 ;
F_13 ( V_277 , & V_47 -> V_61 ) ;
if ( ! F_23 ( V_10 ) ) {
F_9 ( V_22
L_14
, V_10 -> V_23 -> V_24 ) ;
}
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
V_10 -> V_136 &= ~ V_276 ;
F_13 ( V_278 , V_47 -> V_55 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22
L_14
, V_10 -> V_23 -> V_24 ) ;
}
}
static void F_114 ( struct V_9 * V_56 )
{
struct V_57 * V_47 = (struct V_57 * ) V_56 -> V_27 ;
V_56 -> V_136 &= ~ V_276 ;
F_13 ( V_277 , & V_47 -> V_61 ) ;
F_13 ( V_63 , & V_47 -> V_64 ) ;
if ( ! F_26 ( V_56 ) ) {
F_9 ( V_22
L_14
, V_56 -> V_23 -> V_24 ) ;
}
return;
}
static void F_67 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
F_112 ( V_10 ) ;
}
break;
case V_14 : {
F_113 ( V_10 ) ;
}
break;
case V_13 : {
F_114 ( V_10 ) ;
}
}
}
static void F_68 ( struct V_9 * V_10 )
{
F_4 ( & V_10 -> V_15 -> V_16 , V_10 -> V_86 , V_10 -> V_65 , V_10 -> V_66 ) ;
}
void F_115 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
F_13 ( V_279 , & V_47 -> V_64 ) ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
F_13 ( V_280 , V_47 -> V_55 ) ;
}
break;
case V_13 : {
struct V_57 T_1 * V_47 = V_10 -> V_27 ;
F_13 ( V_281 , & V_47 -> V_64 ) ;
}
}
}
static void F_116 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
F_13 ( V_282 , & V_47 -> V_64 ) ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
F_13 ( V_283 , V_47 -> V_55 ) ;
}
break;
case V_13 : {
struct V_57 T_1 * V_47 = V_10 -> V_27 ;
F_13 ( V_284 , & V_47 -> V_64 ) ;
}
break;
}
}
struct V_285 T_1 * F_117 ( struct V_9 * V_10 )
{
struct V_285 T_1 * V_286 = NULL ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_286 = (struct V_285 T_1 * ) & V_47 -> V_287 ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
V_286 = (struct V_285 T_1 * ) V_47 -> V_287 ;
}
break;
case V_13 : {
struct V_57 * V_58 = (struct V_57 * ) V_10 -> V_27 ;
V_286 = (struct V_285 T_1 * ) & V_58 -> V_287 ;
}
}
return V_286 ;
}
static struct V_285 T_1 * F_118 ( struct V_9 * V_10 )
{
struct V_285 T_1 * V_288 = NULL ;
switch ( V_10 -> V_11 ) {
case V_12 : {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_288 = (struct V_285 T_1 * ) & V_47 -> V_289 ;
}
break;
case V_14 : {
struct V_17 * V_47 = V_10 -> V_18 ;
V_288 = (struct V_285 T_1 * ) V_47 -> V_289 ;
}
break;
case V_13 : {
struct V_57 * V_47 = (struct V_57 * ) V_10 -> V_27 ;
V_288 = (struct V_285 T_1 * ) & V_47 -> V_289 ;
}
}
return V_288 ;
}
static void F_119 ( struct V_9 * V_10 )
{
struct V_285 T_1 * V_290 ;
struct V_285 * V_291 ;
T_5 T_1 * V_292 ;
T_11 V_293 , V_294 , V_295 , V_296 ;
V_296 = V_10 -> V_296 ;
V_295 = V_10 -> V_295 ;
V_290 = F_117 ( V_10 ) ;
V_292 = ( T_5 T_1 * ) V_290 -> V_154 ;
V_294 = V_290 -> V_297 ;
V_293 = ( V_295 - V_296 - 1 ) & ( V_298 - 1 ) ;
if ( V_293 >= V_294 )
{
while ( V_294 > 0 ) {
V_291 = (struct V_285 * ) & V_10 -> V_299 [ V_296 ] ;
memcpy ( V_291 , V_292 , 1 ) ;
V_296 ++ ;
V_296 %= V_298 ;
V_292 ++ ;
V_294 -- ;
}
V_10 -> V_296 = V_296 ;
F_115 ( V_10 ) ;
}
else {
V_10 -> V_136 |= V_300 ;
}
}
static void F_120 ( struct V_9 * V_10 )
{
V_10 -> V_136 |= V_139 ;
if ( V_10 -> V_301 != V_10 -> V_302 ) {
T_5 * V_291 ;
struct V_285 T_1 * V_303 ;
T_5 T_1 * V_292 ;
T_11 V_304 = 0 ;
V_10 -> V_136 &= ( ~ V_139 ) ;
V_303 = F_118 ( V_10 ) ;
V_292 = ( T_5 T_1 * ) V_303 -> V_154 ;
while ( ( V_10 -> V_301 != V_10 -> V_302 ) && \
( V_304 < 124 ) ) {
V_291 = & V_10 -> V_305 [ V_10 -> V_301 ] ;
memcpy ( V_292 , V_291 , 1 ) ;
V_10 -> V_301 ++ ;
V_10 -> V_301 %= V_298 ;
V_292 ++ ;
V_304 ++ ;
}
V_303 -> V_297 = V_304 ;
F_116 ( V_10 ) ;
}
if ( V_10 -> V_301 == V_10 -> V_302 ) {
V_10 -> V_136 |= V_137 ;
}
}
static void F_121 ( struct V_9 * V_10 )
{
T_7 V_28 ;
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_28 = F_12 ( & V_47 -> V_28 ) ;
F_13 ( V_28 , & V_47 -> V_28 ) ;
if ( V_28 & V_306 ) {
F_119 ( V_10 ) ;
}
if ( V_28 & V_307 ) {
F_120 ( V_10 ) ;
}
}
static void F_122 ( struct V_9 * V_56 )
{
T_7 V_28 ;
struct V_57 * V_47 = (struct V_57 * ) V_56 -> V_27 ;
V_28 = F_12 ( & V_47 -> V_28 ) ;
F_13 ( V_28 , & V_47 -> V_31 ) ;
if ( V_28 & V_308 ) {
F_119 ( V_56 ) ;
}
if ( V_28 & V_309 ) {
F_120 ( V_56 ) ;
}
if ( V_28 & V_29 ) {
F_123 ( V_56 ) ;
}
return;
}
static void F_124 ( struct V_9 * V_10 )
{
T_7 V_203 ;
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
struct V_204 * V_205 ;
struct V_67 * V_198 ;
bool error ;
while ( ( V_203 = F_12 ( & V_47 -> V_207 ) ) != 0xFFFFFFFF ) {
V_205 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_198 = F_38 ( V_205 , struct V_67 , V_91 ) ;
error = ( V_203 & V_209 ) ? true : false ;
F_86 ( V_10 , V_198 , error ) ;
}
}
static void F_125 ( struct V_9 * V_10 )
{
T_7 V_270 ;
T_7 V_203 ;
struct V_17 * V_47 = V_10 -> V_18 ;
struct V_204 * V_205 ;
struct V_67 * V_198 ;
bool error ;
V_270 = V_47 -> V_214 ;
while ( ( V_203 = F_12 ( & V_47 -> V_212 [ V_270 ] ) ) != 0 ) {
F_13 ( 0 , & V_47 -> V_212 [ V_270 ] ) ;
V_205 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_198 = F_38 ( V_205 , struct V_67 , V_91 ) ;
error = ( V_203 & V_209 ) ? true : false ;
F_86 ( V_10 , V_198 , error ) ;
V_270 ++ ;
V_270 %= V_211 ;
V_47 -> V_214 = V_270 ;
}
}
static void F_126 ( struct V_9 * V_10 )
{
struct V_57 * V_58 ;
struct V_204 * V_91 ;
struct V_67 * V_164 ;
T_7 V_203 , V_216 , V_310 = 0 ;
int error ;
V_58 = (struct V_57 * ) V_10 -> V_27 ;
while ( F_12 ( & V_58 -> V_217 ) &
V_218 ) {
V_203 = F_12 ( & V_58 -> V_219 ) ;
V_216 = ( V_203 & 0xFFFFFFF0 ) ;
V_91 = (struct V_204 * ) ( V_10 -> V_90 + V_216 ) ;
V_164 = F_38 ( V_91 , struct V_67 , V_91 ) ;
error = ( V_203 & V_220 ) ? true : false ;
F_86 ( V_10 , V_164 , error ) ;
if ( V_310 == V_311 ) {
F_13 ( V_312 , & V_58 -> V_64 ) ;
break;
}
V_310 ++ ;
}
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_46 * V_47 = V_10 -> V_21 ;
F_13 ( V_50 , & V_47 -> V_49 ) ;
F_128 ( & V_10 -> V_98 ) ;
}
static void F_129 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
F_13 ( V_53 , V_47 -> V_51 ) ;
F_128 ( & V_10 -> V_98 ) ;
}
static void F_123 ( struct V_9 * V_10 )
{
struct V_57 * V_47 = V_10 -> V_27 ;
F_13 ( V_30 , & V_47 -> V_31 ) ;
F_128 ( & V_10 -> V_98 ) ;
}
static int F_130 ( struct V_9 * V_10 )
{
T_7 V_49 ;
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
V_49 = F_12 ( & V_47 -> V_49 ) &
V_10 -> V_206 ;
if ( ! ( V_49 & V_313 ) ) {
return 1 ;
}
F_13 ( V_49 , & V_47 -> V_49 ) ;
if ( V_49 & V_314 ) {
F_121 ( V_10 ) ;
}
if ( V_49 & V_315 ) {
F_124 ( V_10 ) ;
}
if( V_49 & V_50 ) {
F_127 ( V_10 ) ;
}
return 0 ;
}
static int F_131 ( struct V_9 * V_10 )
{
T_7 V_28 ;
struct V_17 * V_47 = V_10 -> V_18 ;
V_28 = F_12 ( V_47 -> V_51 ) &
V_10 -> V_206 ;
if ( ! V_28 )
return 1 ;
F_13 ( ~ V_28 , V_47 -> V_51 ) ;
F_12 ( V_47 -> V_51 ) ;
F_13 ( V_54 , V_47 -> V_55 ) ;
if ( V_28 & V_229 ) {
F_119 ( V_10 ) ;
}
if ( V_28 & V_230 ) {
F_120 ( V_10 ) ;
}
if ( V_28 & V_231 ) {
F_125 ( V_10 ) ;
}
if( V_28 & V_52 ) {
F_129 ( V_10 ) ;
}
return 0 ;
}
static int F_132 ( struct V_9 * V_56 )
{
T_7 V_316 ;
struct V_57 * V_58 = (struct V_57 * ) V_56 -> V_27 ;
V_316 = F_12 ( & V_58 -> V_217 ) ;
if ( ! V_316 ) {
return 1 ;
}
if ( V_316 & V_317 ) {
F_122 ( V_56 ) ;
}
if ( V_316 & V_218 ) {
F_126 ( V_56 ) ;
}
return 0 ;
}
static T_2 F_16 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_12 : {
if ( F_130 ( V_10 ) ) {
return V_318 ;
}
}
break;
case V_14 : {
if ( F_131 ( V_10 ) ) {
return V_318 ;
}
}
break;
case V_13 : {
if ( F_132 ( V_10 ) ) {
return V_318 ;
}
}
}
return V_319 ;
}
static void F_133 ( struct V_9 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_136 & V_276 ) {
T_7 V_224 ;
V_10 -> V_136 &= ~ V_276 ;
V_224 = F_84 ( V_10 ) ;
F_67 ( V_10 ) ;
F_30 ( V_10 ) ;
F_100 ( V_10 , V_224 ) ;
}
}
}
void F_134 ( struct V_9 * V_10 )
{
T_11 V_301 , V_302 ;
T_5 * V_291 ;
struct V_285 T_1 * V_303 ;
T_5 T_1 * V_292 ;
T_11 V_304 = 0 ;
V_303 = F_118 ( V_10 ) ;
V_292 = ( T_5 T_1 * ) V_303 -> V_154 ;
if ( V_10 -> V_136 & V_139 ) {
V_10 -> V_136 &= ( ~ V_139 ) ;
V_301 = V_10 -> V_301 ;
V_302 = V_10 -> V_302 ;
while ( ( V_301 != V_302 ) && ( V_304 < 124 ) ) {
V_291 = & V_10 -> V_305 [ V_301 ] ;
memcpy ( V_292 , V_291 , 1 ) ;
V_301 ++ ;
V_301 %= V_298 ;
V_292 ++ ;
V_304 ++ ;
}
V_10 -> V_301 = V_301 ;
V_303 -> V_297 = V_304 ;
F_116 ( V_10 ) ;
}
}
static int F_135 ( struct V_9 * V_10 ,
struct V_165 * V_320 )
{
struct V_321 * V_322 ;
int V_323 = 0 , V_324 = 0 ;
char * V_44 ;
struct V_241 * V_242 ;
T_7 V_325 = ( T_7 ) V_320 -> V_249 [ 5 ] << 24 |
( T_7 ) V_320 -> V_249 [ 6 ] << 16 |
( T_7 ) V_320 -> V_249 [ 7 ] << 8 |
( T_7 ) V_320 -> V_249 [ 8 ] ;
V_242 = F_136 ( V_320 ) ;
V_44 = F_137 ( F_138 ( V_242 ) ) + V_242 -> V_326 ;
if ( F_139 ( V_320 ) > 1 ) {
V_323 = V_327 ;
goto V_328;
}
V_324 += V_242 -> V_240 ;
if ( V_324 > sizeof( struct V_321 ) ) {
V_323 = V_327 ;
goto V_328;
}
V_322 = (struct V_321 * ) V_44 ;
switch( V_325 ) {
case V_329 : {
unsigned char * V_330 ;
T_5 * V_291 , * V_331 ;
T_11 V_304 = 0 ;
V_330 = F_140 ( 1032 , V_332 ) ;
if ( ! V_330 ) {
V_323 = V_327 ;
goto V_328;
}
V_331 = V_330 ;
while ( ( V_10 -> V_295 != V_10 -> V_296 )
&& ( V_304 < 1031 ) ) {
V_291 = & V_10 -> V_299 [ V_10 -> V_295 ] ;
memcpy ( V_331 , V_291 , 1 ) ;
V_10 -> V_295 ++ ;
V_10 -> V_295 %= V_298 ;
V_331 ++ ;
V_304 ++ ;
}
if ( V_10 -> V_136 & V_300 ) {
struct V_285 T_1 * V_290 ;
T_5 T_1 * V_292 ;
T_11 V_294 ;
V_10 -> V_136 &= ~ V_300 ;
V_290 = F_117 ( V_10 ) ;
V_292 = V_290 -> V_154 ;
V_294 = F_12 ( & V_290 -> V_297 ) ;
while ( V_294 > 0 ) {
V_10 -> V_299 [ V_10 -> V_296 ] = F_40 ( V_292 ) ;
V_10 -> V_296 ++ ;
V_10 -> V_296 %= V_298 ;
V_292 ++ ;
V_294 -- ;
}
F_115 ( V_10 ) ;
}
memcpy ( V_322 -> V_333 , V_330 , V_304 ) ;
V_322 -> V_334 . V_335 = V_304 ;
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 = V_338 ;
} else{
V_322 -> V_334 . V_337 = V_339 ;
}
F_20 ( V_330 ) ;
}
break;
case V_340 : {
unsigned char * V_330 ;
T_11 V_293 , V_341 , V_301 , V_302 ;
T_5 * V_291 , * V_342 ;
V_330 = F_140 ( 1032 , V_332 ) ;
if ( ! V_330 ) {
V_323 = V_327 ;
goto V_328;
}
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_339 ;
}
V_342 = V_330 ;
V_341 = V_322 -> V_334 . V_335 ;
memcpy ( V_342 , V_322 -> V_333 , V_341 ) ;
V_302 = V_10 -> V_302 ;
V_301 = V_10 -> V_301 ;
if ( V_302 != V_301 ) {
struct V_172 * V_173 =
(struct V_172 * ) V_320 -> V_174 ;
F_134 ( V_10 ) ;
V_173 -> V_180 = 0x70 ;
V_173 -> V_343 = V_344 ;
V_173 -> V_345 = 0x0A ;
V_173 -> V_346 = 0x20 ;
V_173 -> V_182 = 1 ;
V_323 = V_327 ;
} else {
V_293 = ( V_301 - V_302 - 1 )
& ( V_298 - 1 ) ;
if ( V_293 >= V_341 ) {
while ( V_341 > 0 ) {
V_291 =
& V_10 -> V_305 [ V_10 -> V_302 ] ;
memcpy ( V_291 , V_342 , 1 ) ;
V_10 -> V_302 ++ ;
V_10 -> V_302 %= V_298 ;
V_342 ++ ;
V_341 -- ;
}
if ( V_10 -> V_136 & V_137 ) {
V_10 -> V_136 &=
~ V_137 ;
F_134 ( V_10 ) ;
}
} else {
struct V_172 * V_173 =
(struct V_172 * ) V_320 -> V_174 ;
V_173 -> V_180 = 0x70 ;
V_173 -> V_343 = V_344 ;
V_173 -> V_345 = 0x0A ;
V_173 -> V_346 = 0x20 ;
V_173 -> V_182 = 1 ;
V_323 = V_327 ;
}
}
F_20 ( V_330 ) ;
}
break;
case V_347 : {
T_5 * V_291 = V_10 -> V_299 ;
if ( V_10 -> V_136 & V_300 ) {
V_10 -> V_136 &= ~ V_300 ;
F_115 ( V_10 ) ;
}
V_10 -> V_136 |= V_138 ;
V_10 -> V_295 = 0 ;
V_10 -> V_296 = 0 ;
memset ( V_291 , 0 , V_298 ) ;
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_339 ;
}
}
break;
case V_348 : {
T_5 * V_291 = V_10 -> V_305 ;
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_339 ;
}
if ( V_10 -> V_136 & V_300 ) {
V_10 -> V_136 &= ~ V_300 ;
F_115 ( V_10 ) ;
}
V_10 -> V_136 |=
( V_137 |
V_139 ) ;
V_10 -> V_301 = 0 ;
V_10 -> V_302 = 0 ;
memset ( V_291 , 0 , V_298 ) ;
}
break;
case V_349 : {
T_5 * V_291 ;
if ( V_10 -> V_136 & V_300 ) {
V_10 -> V_136 &= ~ V_300 ;
F_115 ( V_10 ) ;
}
V_10 -> V_136 |=
( V_137
| V_138
| V_139 ) ;
V_10 -> V_295 = 0 ;
V_10 -> V_296 = 0 ;
V_10 -> V_301 = 0 ;
V_10 -> V_302 = 0 ;
V_291 = V_10 -> V_299 ;
memset ( V_291 , 0 , sizeof( struct V_285 ) ) ;
V_291 = V_10 -> V_305 ;
memset ( V_291 , 0 , sizeof( struct V_285 ) ) ;
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_339 ;
}
}
break;
case V_350 : {
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_351 ;
}
break;
}
case V_352 : {
T_9 * V_353 = L_15 ;
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
} else{
V_322 -> V_334 . V_337 =
V_339 ;
}
memcpy ( V_322 -> V_333 , V_353
, ( V_354 ) strlen ( V_353 ) ) ;
}
break;
case V_355 :
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
}
F_133 ( V_10 ) ;
break;
case V_356 :
if( V_10 -> V_148 == V_336 ) {
V_322 -> V_334 . V_337 =
V_338 ;
}
F_30 ( V_10 ) ;
break;
default:
V_323 = V_327 ;
}
V_328:
V_242 = F_136 ( V_320 ) ;
F_141 ( V_44 - V_242 -> V_326 ) ;
return V_323 ;
}
static struct V_67 * F_142 ( struct V_9 * V_10 )
{
struct V_357 * V_358 = & V_10 -> V_95 ;
struct V_67 * V_164 = NULL ;
unsigned long V_167 ;
F_81 ( & V_10 -> V_135 , V_167 ) ;
if ( ! F_143 ( V_358 ) ) {
V_164 = F_144 ( V_358 -> V_359 , struct V_67 , V_94 ) ;
F_145 ( & V_164 -> V_94 ) ;
} else{
F_82 ( & V_10 -> V_135 , V_167 ) ;
return 0 ;
}
F_82 ( & V_10 -> V_135 , V_167 ) ;
return V_164 ;
}
static void F_146 ( struct V_9 * V_10 ,
struct V_165 * V_320 )
{
switch ( V_320 -> V_249 [ 0 ] ) {
case V_360 : {
unsigned char V_361 [ 36 ] ;
char * V_44 ;
struct V_241 * V_242 ;
if ( V_320 -> V_189 -> V_105 ) {
V_320 -> V_175 = ( V_362 << 16 ) ;
V_320 -> V_171 ( V_320 ) ;
return;
}
V_361 [ 0 ] = V_363 ;
V_361 [ 1 ] = 0 ;
V_361 [ 2 ] = 0 ;
V_361 [ 4 ] = 31 ;
strncpy ( & V_361 [ 8 ] , L_16 , 8 ) ;
strncpy ( & V_361 [ 16 ] , L_17 , 16 ) ;
strncpy ( & V_361 [ 32 ] , L_18 , 4 ) ;
V_242 = F_136 ( V_320 ) ;
V_44 = F_137 ( F_138 ( V_242 ) ) + V_242 -> V_326 ;
memcpy ( V_44 , V_361 , sizeof( V_361 ) ) ;
V_242 = F_136 ( V_320 ) ;
F_141 ( V_44 - V_242 -> V_326 ) ;
V_320 -> V_171 ( V_320 ) ;
}
break;
case V_364 :
case V_365 : {
if ( F_135 ( V_10 , V_320 ) )
V_320 -> V_175 = ( V_366 << 16 ) ;
V_320 -> V_171 ( V_320 ) ;
}
break;
default:
V_320 -> V_171 ( V_320 ) ;
}
}
static int F_147 ( struct V_165 * V_320 ,
void (* F_148)( struct V_165 * ) )
{
struct V_114 * V_23 = V_320 -> V_189 -> V_23 ;
struct V_9 * V_10 = (struct V_9 * ) V_23 -> V_125 ;
struct V_67 * V_164 ;
int V_104 = V_320 -> V_189 -> V_113 ;
int V_105 = V_320 -> V_189 -> V_105 ;
T_5 V_367 = V_320 -> V_249 [ 0 ] ;
V_320 -> V_171 = F_148 ;
V_320 -> V_368 = NULL ;
V_320 -> V_175 = 0 ;
if ( ( V_367 == V_369 ) || ( V_367 == V_370 ) ) {
if( V_10 -> V_77 [ V_104 ] [ V_105 ] == V_78 ) {
V_320 -> V_175 = ( V_193 << 16 ) ;
}
V_320 -> V_171 ( V_320 ) ;
return 0 ;
}
if ( V_104 == 16 ) {
F_146 ( V_10 , V_320 ) ;
return 0 ;
}
if ( F_87 ( & V_10 -> V_168 ) >=
V_208 )
return V_371 ;
V_164 = F_142 ( V_10 ) ;
if ( ! V_164 )
return V_371 ;
if ( F_101 ( V_10 , V_164 , V_320 ) == V_251 ) {
V_320 -> V_175 = ( V_366 << 16 ) | ( V_372 << 1 ) ;
V_320 -> V_171 ( V_320 ) ;
return 0 ;
}
F_111 ( V_10 , V_164 ) ;
return 0 ;
}
bool F_149 ( struct V_9 * V_10 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
struct V_20 * V_15 = V_10 -> V_15 ;
void * V_65 ;
T_6 V_66 ;
char * V_373 = V_10 -> V_374 ;
char * V_375 = V_10 -> V_376 ;
char * V_377 = V_10 -> V_100 ;
char T_1 * V_378 ;
char T_1 * V_379 ;
char T_1 * V_380 ;
int V_381 ;
V_65 = F_33 ( & V_15 -> V_16 , sizeof( struct V_17 ) , & V_66 , V_88 ) ;
if ( ! V_65 ) {
F_9 ( V_22 L_19 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_10 -> V_19 = V_66 ;
V_47 = (struct V_17 * ) V_65 ;
V_10 -> V_18 = V_47 ;
V_47 -> V_55 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_382 ) ;
V_47 -> V_383 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_384 ) ;
V_47 -> V_51 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_385 ) ;
V_47 -> V_186 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_386 ) ;
V_47 -> V_289 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_387 ) ;
V_47 -> V_287 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_388 ) ;
V_47 -> V_102 = ( T_7 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_389 ) ;
V_378 = ( char T_1 * ) ( & V_47 -> V_102 [ 15 ] ) ;
V_379 = ( char T_1 * ) ( & V_47 -> V_102 [ 17 ] ) ;
V_380 = ( char T_1 * ) ( & V_47 -> V_102 [ 21 ] ) ;
F_13 ( V_390 , V_47 -> V_55 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22 L_20 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_381 = 8 ;
while ( V_381 ) {
* V_373 = F_40 ( V_378 ) ;
V_373 ++ ;
V_378 ++ ;
V_381 -- ;
}
V_381 = 16 ;
while ( V_381 ) {
* V_375 = F_40 ( V_379 ) ;
V_375 ++ ;
V_379 ++ ;
V_381 -- ;
}
V_381 = 16 ;
while( V_381 ) {
* V_377 = F_40 ( V_380 ) ;
V_377 ++ ;
V_380 ++ ;
V_381 -- ;
}
F_9 ( V_22 L_21 ,
V_10 -> V_23 -> V_24 ,
V_10 -> V_376 ,
V_10 -> V_374 ) ;
V_10 -> V_101 = F_12 ( & V_47 -> V_102 [ 1 ] ) ;
V_10 -> V_391 = F_12 ( & V_47 -> V_102 [ 2 ] ) ;
V_10 -> V_392 = F_12 ( & V_47 -> V_102 [ 3 ] ) ;
V_10 -> V_393 = F_12 ( & V_47 -> V_102 [ 4 ] ) ;
V_10 -> V_394 = F_12 ( & V_47 -> V_102 [ 5 ] ) ;
V_10 -> V_81 = F_12 ( & V_47 -> V_102 [ 25 ] ) ;
return true ;
}
static bool F_150 ( struct V_9 * V_56 )
{
T_7 V_224 , V_395 , V_396 = 0 ;
struct V_57 * V_47 = V_56 -> V_27 ;
char * V_373 = V_56 -> V_374 ;
char * V_375 = V_56 -> V_376 ;
char * V_378 = ( char * ) ( & V_47 -> V_111 [ 15 ] ) ;
char * V_379 = ( char * ) ( & V_47 -> V_111 [ 17 ] ) ;
int V_381 ;
V_224 = F_12 ( & V_47 -> V_187 ) ;
F_13 ( V_224 | V_188 , & V_47 -> V_187 ) ;
do {
V_396 = F_12 ( & V_47 -> V_397 ) ;
} while ( ( V_396 & V_398 ) == 0 );
F_13 ( V_399 , & V_47 -> V_61 ) ;
F_13 ( V_63 , & V_47 -> V_64 ) ;
for ( V_395 = 0 ; V_395 < 2000 ; V_395 ++ ) {
if ( F_12 ( & V_47 -> V_28 ) & V_29 ) {
F_13 ( V_30 , & V_47 -> V_31 ) ;
break;
}
F_151 ( 10 ) ;
}
if ( V_395 >= 2000 ) {
F_9 ( V_22 L_20 , V_56 -> V_23 -> V_24 ) ;
return false ;
}
V_381 = 8 ;
while ( V_381 ) {
* V_373 = F_40 ( V_378 ) ;
V_373 ++ ;
V_378 ++ ;
V_381 -- ;
}
V_381 = 16 ;
while ( V_381 ) {
* V_375 = F_40 ( V_379 ) ;
V_375 ++ ;
V_379 ++ ;
V_381 -- ;
}
F_9 ( V_22 L_21 ,
V_56 -> V_23 -> V_24 ,
V_56 -> V_376 ,
V_56 -> V_374 ) ;
V_56 -> V_391 = F_12 ( & V_47 -> V_111 [ 1 ] ) ;
V_56 -> V_392 = F_12 ( & V_47 -> V_111 [ 2 ] ) ;
V_56 -> V_393 = F_12 ( & V_47 -> V_111 [ 3 ] ) ;
V_56 -> V_394 = F_12 ( & V_47 -> V_111 [ 4 ] ) ;
V_56 -> V_81 = F_12 ( & V_47 -> V_111 [ 25 ] ) ;
return true ;
}
static bool F_55 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 == V_12 )
return F_152 ( V_10 ) ;
else if ( V_10 -> V_11 == V_14 )
return F_149 ( V_10 ) ;
else
return F_150 ( V_10 ) ;
}
static int F_153 ( struct V_9 * V_10 ,
struct V_67 * V_400 )
{
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
struct V_67 * V_164 ;
struct V_204 * V_91 ;
T_7 V_203 , V_49 , V_401 = 0 , V_221 = 0 ;
int V_402 ;
bool error ;
V_403:
V_221 ++ ;
V_49 = F_12 ( & V_47 -> V_49 ) & V_10 -> V_206 ;
F_13 ( V_49 , & V_47 -> V_49 ) ;
while ( 1 ) {
if ( ( V_203 = F_12 ( & V_47 -> V_207 ) ) == 0xFFFFFFFF ) {
if ( V_401 ) {
V_402 = V_266 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_221 > 100 ) {
V_402 = V_251 ;
break;
}
goto V_403;
}
}
V_91 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_164 = F_38 ( V_91 , struct V_67 , V_91 ) ;
V_401 = ( V_164 == V_400 ) ? 1 : 0 ;
if ( ( V_164 -> V_10 != V_10 ) || ( V_164 -> V_169 != V_199 ) ) {
if ( ( V_164 -> V_169 == V_200 ) || ( V_164 == V_400 ) ) {
F_9 ( V_22 L_22
L_23
, V_10 -> V_23 -> V_24
, V_164 -> V_166 -> V_189 -> V_113
, ( T_8 ) V_164 -> V_166 -> V_189 -> V_105
, V_164 ) ;
V_164 -> V_166 -> V_175 = V_202 << 16 ;
F_79 ( V_164 ) ;
continue;
}
F_9 ( V_22 L_24
L_25
L_26
, V_10 -> V_23 -> V_24
, V_164
, F_87 ( & V_10 -> V_168 ) ) ;
continue;
}
error = ( V_203 & V_209 ) ? true : false ;
F_85 ( V_10 , V_164 , error ) ;
}
return V_402 ;
}
static int F_154 ( struct V_9 * V_10 ,
struct V_67 * V_400 )
{
struct V_17 * V_47 = V_10 -> V_18 ;
struct V_204 * V_91 ;
struct V_67 * V_164 ;
T_7 V_203 , V_401 = 0 , V_221 = 0 ;
int V_270 , V_402 ;
bool error ;
V_404:
V_221 ++ ;
F_13 ( V_210 , V_47 -> V_51 ) ;
while( 1 ) {
V_270 = V_47 -> V_214 ;
if ( ( V_203 = F_12 ( & V_47 -> V_212 [ V_270 ] ) ) == 0 ) {
if ( V_401 ) {
V_402 = V_266 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_221 > 100 ) {
V_402 = V_251 ;
break;
}
goto V_404;
}
}
F_13 ( 0 , & V_47 -> V_212 [ V_270 ] ) ;
V_270 ++ ;
V_270 %= V_211 ;
V_47 -> V_214 = V_270 ;
V_91 = (struct V_204 * ) ( V_10 -> V_90 + ( V_203 << 5 ) ) ;
V_164 = F_38 ( V_91 , struct V_67 , V_91 ) ;
V_401 = ( V_164 == V_400 ) ? 1 : 0 ;
if ( ( V_164 -> V_10 != V_10 ) || ( V_164 -> V_169 != V_199 ) ) {
if ( ( V_164 -> V_169 == V_200 ) || ( V_164 == V_400 ) ) {
F_9 ( V_22 L_22
L_23
, V_10 -> V_23 -> V_24
, V_164 -> V_166 -> V_189 -> V_113
, ( T_8 ) V_164 -> V_166 -> V_189 -> V_105
, V_164 ) ;
V_164 -> V_166 -> V_175 = V_202 << 16 ;
F_79 ( V_164 ) ;
continue;
}
F_9 ( V_22 L_24
L_25
L_26
, V_10 -> V_23 -> V_24
, V_164
, F_87 ( & V_10 -> V_168 ) ) ;
continue;
}
error = ( V_203 & V_209 ) ? true : false ;
F_85 ( V_10 , V_164 , error ) ;
}
return V_402 ;
}
static int F_155 ( struct V_9 * V_10 , struct V_67 * V_400 )
{
struct V_57 * V_47 = (struct V_57 * ) V_10 -> V_27 ;
T_7 V_203 , V_216 ;
struct V_204 * V_91 ;
bool error ;
struct V_67 * V_198 ;
T_7 V_401 = 0 , V_221 = 0 ;
int V_402 ;
V_405:
V_221 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_47 -> V_217 ) & V_218 ) == 0 ) {
if ( V_401 ) {
V_402 = V_266 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_221 > 100 ) {
V_402 = V_251 ;
break;
}
goto V_405;
}
}
V_203 = F_12 ( & V_47 -> V_219 ) ;
V_216 = ( V_203 & 0xFFFFFFF0 ) ;
V_91 = (struct V_204 * ) ( V_10 -> V_90 + V_216 ) ;
V_198 = F_38 ( V_91 , struct V_67 , V_91 ) ;
V_401 = ( V_198 == V_400 ) ? 1 : 0 ;
if ( ( V_198 -> V_10 != V_10 ) || ( V_198 -> V_169 != V_199 ) ) {
if ( V_198 -> V_169 == V_200 ) {
F_9 ( V_22 L_22
L_23
, V_10 -> V_23 -> V_24
, V_198 -> V_166 -> V_189 -> V_113
, ( T_8 ) V_198 -> V_166 -> V_189 -> V_105
, V_198 ) ;
V_198 -> V_166 -> V_175 = V_202 << 16 ;
F_79 ( V_198 ) ;
continue;
}
F_9 ( V_22 L_24
L_25
L_26
, V_10 -> V_23 -> V_24
, V_198
, F_87 ( & V_10 -> V_168 ) ) ;
continue;
}
error = ( V_203 & V_220 ) ? true : false ;
F_85 ( V_10 , V_198 , error ) ;
}
return V_402 ;
}
static int F_156 ( struct V_9 * V_10 ,
struct V_67 * V_400 )
{
int V_402 = 0 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
V_402 = F_153 ( V_10 , V_400 ) ;
}
break;
case V_14 : {
V_402 = F_154 ( V_10 , V_400 ) ;
}
break;
case V_13 : {
V_402 = F_155 ( V_10 , V_400 ) ;
}
}
return V_402 ;
}
static int F_157 ( struct V_9 * V_10 )
{
T_7 V_70 , V_273 ;
V_70 = F_158 ( V_10 -> V_66 ) ;
V_273 = F_159 ( V_10 -> V_66 ) ;
V_10 -> V_273 = V_273 ;
switch ( V_10 -> V_11 ) {
case V_12 : {
if ( V_273 != 0 ) {
struct V_46 T_1 * V_47 = V_10 -> V_21 ;
T_7 V_224 ;
V_224 = F_84 ( V_10 ) ;
F_13 ( V_406 , \
& V_47 -> V_102 [ 0 ] ) ;
F_13 ( V_273 , & V_47 -> V_102 [ 1 ] ) ;
F_13 ( V_407 , \
& V_47 -> V_61 ) ;
if ( ! F_23 ( V_10 ) ) {
F_9 (KERN_NOTICE L_27set ccb high \
part physical address timeout\nL_28arcmsr%d:can not set diver mode\nL_29set configL_30arcmsr%d: 'set command Q window' \
timeout \nL_31arcmsr%d: cdb_phyaddr_hi32=0x%x\nL_32arcmsr%d: 'set command Q window' \
timeout \nL_33arcmsr%d: wait 'start adapter background \
rebulid' timeout \nL_34arcmsr%d: wait 'start adapter background \
rebulid' timeout \nL_35arcmsr%d: wait 'start adapter background \
rebulid' timeout \nL_36ARCMSR IOP enables EOI_MODE TIMEOUTL_37arcmsr%d: executing hw bus reset .....\nL_38arcmsr: executing bus reset eh.....num_resets = %d, num_aborts = %d \nL_39arcmsr: there is an bus reset eh proceeding.......\nL_40arcmsr%d: waiting for hw bus reset return, retry=%d\nL_41arcmsr%d: waiting for hw bus reset return, RETRY TERMINATED!!\nL_42arcmsr: scsi bus reset eh returns with success\nL_43arcmsr: there is an bus reset eh proceeding.......\nL_44arcmsr%d: waiting for hw bus reset return, retry=%d\nL_41arcmsr%d: waiting for hw bus reset return, RETRY TERMINATED!!\nL_45arcmsr: scsi bus reset eh returns with success\nL_46arcmsr%d: abort device command of scsi id = %d lun = %d \nL_47SATAL_48SASL_49X-TYPEL_50Areca %s Host Adapter RAID Controller%s\n %sL_51( RAID6 capable)L_52 ,
ARCMSR_DRIVER_VERSION) ;
return V_408 ;
}
