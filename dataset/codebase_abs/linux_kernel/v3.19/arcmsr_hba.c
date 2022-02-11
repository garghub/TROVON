static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 > V_4 )
V_3 = V_4 ;
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_8 :
case V_9 : {
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 , V_6 -> V_14 ) ;
break;
}
}
}
static bool F_5 ( struct V_5 * V_6 )
{
struct V_15 * V_10 = V_6 -> V_10 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_6 -> V_17 = F_6 ( F_7 ( V_10 , 0 ) , F_8 ( V_10 , 0 ) ) ;
if ( ! V_6 -> V_17 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
break;
}
case V_8 : {
void T_1 * V_21 , * V_22 ;
V_21 = F_6 ( F_7 ( V_10 , 0 ) , F_8 ( V_10 , 0 ) ) ;
if ( ! V_21 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_22 = F_6 ( F_7 ( V_10 , 2 ) , F_8 ( V_10 , 2 ) ) ;
if ( ! V_22 ) {
F_10 ( V_21 ) ;
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_21 = V_21 ;
V_6 -> V_22 = V_22 ;
break;
}
case V_23 : {
V_6 -> V_24 = F_11 ( F_7 ( V_10 , 1 ) , F_8 ( V_10 , 1 ) ) ;
if ( ! V_6 -> V_24 ) {
F_9 ( V_18 L_1 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
if ( F_12 ( & V_6 -> V_24 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_6 -> V_24 -> V_28 ) ;
return true ;
}
break;
}
case V_9 : {
void T_1 * V_21 ;
unsigned long V_29 , V_30 , V_31 ;
V_29 = ( unsigned long ) F_7 ( V_10 , 0 ) ;
V_30 = F_8 ( V_10 , 0 ) ;
V_31 = F_14 ( V_10 , 0 ) ;
if ( V_31 & V_32 )
V_21 = F_6 ( V_29 , V_30 ) ;
else
V_21 = F_11 ( V_29 , V_30 ) ;
if ( ! V_21 ) {
F_15 ( L_2 ,
V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_21 = V_21 ;
break;
}
}
return true ;
}
static void F_16 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_10 ( V_6 -> V_17 ) ;
}
break;
case V_8 : {
F_10 ( V_6 -> V_21 ) ;
F_10 ( V_6 -> V_22 ) ;
}
break;
case V_23 : {
F_10 ( V_6 -> V_24 ) ;
}
break;
case V_9 :
F_10 ( V_6 -> V_21 ) ;
break;
}
}
static T_2 F_17 ( int V_33 , void * V_34 )
{
T_2 V_35 ;
struct V_5 * V_6 = V_34 ;
V_35 = F_18 ( V_6 ) ;
return V_35 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_3 V_38 , int * V_39 )
{
int V_40 , V_41 , V_42 , V_43 , V_44 ;
unsigned char * V_45 ;
V_45 = F_20 ( V_37 ) ;
if ( V_45 ) {
V_40 = F_21 ( V_45 , V_38 , & V_39 [ 2 ] , & V_39 [ 0 ] , & V_39 [ 1 ] ) ;
F_22 ( V_45 ) ;
if ( V_40 != - 1 )
return V_40 ;
}
V_44 = V_38 ;
V_41 = 64 ;
V_42 = 32 ;
V_43 = V_44 / ( V_41 * V_42 ) ;
if ( V_43 > 1024 ) {
V_41 = 255 ;
V_42 = 63 ;
V_43 = V_44 / ( V_41 * V_42 ) ;
}
V_39 [ 0 ] = V_41 ;
V_39 [ 1 ] = V_42 ;
V_39 [ 2 ] = V_43 ;
return 0 ;
}
static T_4 F_23 ( struct V_5 * V_6 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
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
static T_4 F_25 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( V_47 -> V_53 )
& V_54 ) {
F_13 ( V_55 ,
V_47 -> V_53 ) ;
F_13 ( V_56 ,
V_47 -> V_57 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_26 ( struct V_5 * V_58 )
{
struct V_59 T_1 * V_60 = V_58 -> V_24 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( & V_60 -> V_25 )
& V_26 ) {
F_13 ( V_27 ,
& V_60 -> V_28 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static bool F_27 ( struct V_5 * V_58 )
{
struct V_61 * V_47 = V_58 -> V_62 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2000 ; V_48 ++ ) {
if ( F_12 ( V_47 -> V_25 )
& V_63 ) {
F_13 ( V_63 ,
V_47 -> V_25 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
int V_64 = 30 ;
F_13 ( V_65 , & V_47 -> V_66 ) ;
do {
if ( F_23 ( V_6 ) )
break;
else {
V_64 -- ;
F_9 ( V_18 L_3 , V_6 -> V_19 -> V_20 , V_64 ) ;
}
} while ( V_64 != 0 );
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
int V_64 = 30 ;
F_13 ( V_67 , V_47 -> V_57 ) ;
do {
if ( F_25 ( V_6 ) )
break;
else {
V_64 -- ;
F_9 ( V_18 L_4 , V_6 -> V_19 -> V_20 , V_64 ) ;
}
} while ( V_64 != 0 );
}
static void F_30 ( struct V_5 * V_58 )
{
struct V_59 T_1 * V_47 = V_58 -> V_24 ;
int V_64 = 30 ;
F_13 ( V_65 , & V_47 -> V_66 ) ;
F_13 ( V_68 , & V_47 -> V_69 ) ;
do {
if ( F_26 ( V_58 ) ) {
break;
} else {
V_64 -- ;
F_9 ( V_18 L_4 , V_58 -> V_19 -> V_20 , V_64 ) ;
}
} while ( V_64 != 0 );
return;
}
static void F_31 ( struct V_5 * V_58 )
{
int V_64 = 15 ;
struct V_61 * V_47 = V_58 -> V_62 ;
F_13 ( V_65 , V_47 -> V_66 ) ;
do {
if ( F_27 ( V_58 ) )
break;
V_64 -- ;
F_15 ( L_5
L_6 ,
V_58 -> V_19 -> V_20 , V_64 ) ;
} while ( V_64 != 0 );
}
static void F_32 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_28 ( V_6 ) ;
}
break;
case V_8 : {
F_29 ( V_6 ) ;
}
break;
case V_23 : {
F_30 ( V_6 ) ;
}
break;
case V_9 :
F_31 ( V_6 ) ;
break;
}
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_15 * V_10 = V_6 -> V_10 ;
void * V_70 ;
T_5 V_71 ;
struct V_72 * V_73 ;
int V_48 = 0 , V_74 = 0 ;
T_5 V_75 ;
unsigned long V_12 ;
unsigned long V_76 ;
unsigned long V_77 ;
T_6 V_78 ;
for ( V_48 = 0 ; V_48 < V_79 ; V_48 ++ )
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ )
V_6 -> V_81 [ V_48 ] [ V_74 ] = V_82 ;
V_76 = V_83 ;
V_77 = V_84 ;
V_78 = V_6 -> V_85 ;
if( ( V_78 & 0xFF ) >= 3 ) {
V_76 = ( V_86 << ( ( V_78 >> 8 ) & 0xFF ) ) * 1024 ;
V_77 = ( V_76 / 4096 ) ;
}
V_6 -> V_19 -> V_87 = V_76 / 512 ;
V_6 -> V_19 -> V_88 = V_77 ;
V_12 = F_34 ( sizeof( struct V_72 ) + ( V_77 - 1 ) * sizeof( struct V_89 ) , 32 ) ;
V_6 -> V_90 = V_12 * V_91 ;
V_70 = F_35 ( & V_10 -> V_11 , V_6 -> V_90 , & V_71 , V_92 ) ;
if( ! V_70 ) {
F_9 ( V_18 L_7 , V_6 -> V_19 -> V_20 ) ;
return - V_93 ;
}
V_6 -> V_70 = V_70 ;
V_6 -> V_71 = V_71 ;
memset ( V_70 , 0 , V_6 -> V_90 ) ;
V_73 = V_70 ;
V_6 -> V_94 = ( unsigned long ) V_70 - ( unsigned long ) V_71 ;
for( V_48 = 0 ; V_48 < V_91 ; V_48 ++ ) {
V_75 = V_71 + F_36 ( struct V_72 , V_95 ) ;
switch ( V_6 -> V_7 ) {
case V_16 :
case V_8 :
V_73 -> V_75 = V_75 >> 5 ;
break;
case V_23 :
case V_9 :
V_73 -> V_75 = V_75 ;
break;
}
V_6 -> V_96 [ V_48 ] = V_73 ;
V_73 -> V_6 = V_6 ;
F_37 ( & V_73 -> V_97 ) ;
F_38 ( & V_73 -> V_97 , & V_6 -> V_98 ) ;
V_73 = (struct V_72 * ) ( ( unsigned long ) V_73 + V_12 ) ;
V_71 = V_71 + V_12 ;
}
return 0 ;
}
static void F_39 ( struct V_99 * V_100 )
{
struct V_5 * V_6 = F_40 ( V_100 ,
struct V_5 , V_101 ) ;
char * V_102 = ( char * ) V_6 -> V_103 ;
T_6 T_1 * V_104 = NULL ;
char T_1 * V_105 = NULL ;
int V_106 , V_107 ;
struct V_1 * V_108 ;
char V_109 , V_110 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_104 = ( T_6 T_1 * ) ( & V_47 -> V_111 [ 0 ] ) ;
V_105 = ( char T_1 * ) ( & V_47 -> V_111 [ 21 ] ) ;
break;
}
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
V_104 = ( T_6 T_1 * ) ( & V_47 -> V_111 [ 0 ] ) ;
V_105 = ( char T_1 * ) ( & V_47 -> V_111 [ 21 ] ) ;
break;
}
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
V_104 = ( T_6 T_1 * ) ( & V_47 -> V_112 [ 0 ] ) ;
V_105 = ( char T_1 * ) ( & V_47 -> V_112 [ 21 ] ) ;
break;
}
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
V_104 = ( T_6 T_1 * ) ( & V_47 -> V_112 [ 0 ] ) ;
V_105 = ( char T_1 * ) ( & V_47 -> V_112 [ 21 ] ) ;
break;
}
}
F_41 ( & V_6 -> V_113 ) ;
if ( F_12 ( V_104 ) != V_114 )
return;
for ( V_106 = 0 ; V_106 < V_79 - 1 ;
V_106 ++ ) {
V_110 = F_42 ( V_105 ) ;
V_109 = ( * V_102 ) ^ V_110 ;
if ( V_109 != 0 ) {
* V_102 = V_110 ;
for ( V_107 = 0 ; V_107 < V_80 ;
V_107 ++ ) {
if ( ( V_109 & 0x01 ) == 1 &&
( V_110 & 0x01 ) == 1 ) {
F_43 ( V_6 -> V_19 ,
0 , V_106 , V_107 ) ;
} else if ( ( V_109 & 0x01 ) == 1
&& ( V_110 & 0x01 ) == 0 ) {
V_108 = F_44 ( V_6 -> V_19 ,
0 , V_106 , V_107 ) ;
if ( V_108 != NULL ) {
F_45 ( V_108 ) ;
F_46 ( V_108 ) ;
}
}
V_110 >>= 1 ;
V_109 >>= 1 ;
}
}
V_105 ++ ;
V_102 ++ ;
}
}
static int
F_47 ( struct V_15 * V_10 , struct V_5 * V_6 )
{
int V_48 , V_74 , V_115 ;
struct V_116 V_117 [ V_118 ] ;
for ( V_48 = 0 ; V_48 < V_118 ; V_48 ++ )
V_117 [ V_48 ] . V_119 = V_48 ;
V_115 = F_48 ( V_10 , V_117 , 1 , V_118 ) ;
if ( V_115 < 0 )
goto V_120;
V_6 -> V_121 = V_115 ;
for ( V_48 = 0 ; V_48 < V_115 ; V_48 ++ ) {
if ( F_49 ( V_117 [ V_48 ] . V_122 ,
F_17 , 0 , L_8 , V_6 ) ) {
F_50 ( L_9 ,
V_6 -> V_19 -> V_20 , V_117 [ V_48 ] . V_122 ) ;
for ( V_74 = 0 ; V_74 < V_48 ; V_74 ++ )
F_51 ( V_117 [ V_74 ] . V_122 , V_6 ) ;
F_52 ( V_10 ) ;
goto V_120;
}
V_6 -> V_117 [ V_48 ] = V_117 [ V_48 ] ;
}
V_6 -> V_123 |= V_124 ;
F_53 ( L_10 , V_6 -> V_19 -> V_20 ) ;
return V_125 ;
V_120:
if ( F_54 ( V_10 , 1 ) < 0 )
goto V_126;
if ( F_49 ( V_10 -> V_33 , F_17 ,
V_127 , L_8 , V_6 ) ) {
F_50 ( L_9 ,
V_6 -> V_19 -> V_20 , V_10 -> V_33 ) ;
F_55 ( V_10 ) ;
goto V_126;
}
V_6 -> V_123 |= V_128 ;
F_53 ( L_11 , V_6 -> V_19 -> V_20 ) ;
return V_125 ;
V_126:
if ( F_49 ( V_10 -> V_33 , F_17 ,
V_127 , L_8 , V_6 ) ) {
F_50 ( L_12 ,
V_6 -> V_19 -> V_20 , V_10 -> V_33 ) ;
return V_129 ;
}
return V_125 ;
}
static int F_56 ( struct V_15 * V_10 , const struct V_130 * V_131 )
{
struct V_132 * V_19 ;
struct V_5 * V_6 ;
T_4 V_133 , V_134 ;
int error ;
error = F_57 ( V_10 ) ;
if( error ) {
return - V_135 ;
}
V_19 = F_58 ( & V_136 , sizeof( struct V_5 ) ) ;
if( ! V_19 ) {
goto V_137;
}
error = F_59 ( V_10 , F_60 ( 64 ) ) ;
if( error ) {
error = F_59 ( V_10 , F_60 ( 32 ) ) ;
if( error ) {
F_9 ( V_138
L_13 ,
V_19 -> V_20 ) ;
goto V_139;
}
}
F_61 ( & V_140 ) ;
V_133 = V_10 -> V_133 -> V_141 ;
V_134 = V_10 -> V_142 ;
V_6 = (struct V_5 * ) V_19 -> V_143 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_19 = V_19 ;
V_19 -> V_144 = V_80 ;
V_19 -> V_145 = V_79 ;
V_19 -> V_146 = 16 ;
V_19 -> V_147 = V_148 ;
V_19 -> V_149 = V_4 ;
V_19 -> V_150 = V_151 ;
V_19 -> V_152 = ( V_133 << 8 ) | V_134 ;
F_62 ( V_10 , V_19 ) ;
F_63 ( V_10 ) ;
error = F_64 ( V_10 , L_8 ) ;
if( error ) {
goto V_139;
}
F_65 ( & V_6 -> V_153 ) ;
F_65 ( & V_6 -> V_154 ) ;
F_65 ( & V_6 -> V_155 ) ;
F_65 ( & V_6 -> V_156 ) ;
F_65 ( & V_6 -> V_157 ) ;
F_65 ( & V_6 -> V_158 ) ;
V_6 -> V_123 |= ( V_159 |
V_160 |
V_161 ) ;
V_6 -> V_123 &= ~ V_162 ;
F_37 ( & V_6 -> V_98 ) ;
V_6 -> V_7 = V_131 -> V_163 ;
error = F_5 ( V_6 ) ;
if( ! error ) {
goto V_164;
}
error = F_66 ( V_6 ) ;
if( ! error ) {
goto V_165;
}
error = F_33 ( V_6 ) ;
if( error ) {
goto V_166;
}
error = F_67 ( V_19 , & V_10 -> V_11 ) ;
if( error ) {
goto V_167;
}
if ( F_47 ( V_10 , V_6 ) == V_129 )
goto V_168;
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_101 , F_39 ) ;
F_70 ( & V_6 -> V_113 , 16 ) ;
F_70 ( & V_6 -> V_169 , 16 ) ;
V_6 -> V_170 = V_171 ;
F_71 ( & V_6 -> V_172 ) ;
V_6 -> V_172 . V_173 = V_174 + F_72 ( 6 * V_175 ) ;
V_6 -> V_172 . V_176 = ( unsigned long ) V_6 ;
V_6 -> V_172 . V_177 = & V_178 ;
F_73 ( & V_6 -> V_172 ) ;
if( F_74 ( V_6 ) )
goto V_179;
F_75 ( V_19 ) ;
return 0 ;
V_179:
F_76 ( & V_6 -> V_172 ) ;
F_77 ( & V_6 -> V_101 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
V_168:
F_80 ( V_19 ) ;
V_167:
F_81 ( V_6 ) ;
V_166:
F_3 ( V_6 ) ;
V_165:
F_16 ( V_6 ) ;
V_164:
F_82 ( V_10 ) ;
V_139:
F_83 ( V_19 ) ;
V_137:
F_84 ( V_10 ) ;
return - V_135 ;
}
static void F_79 ( struct V_15 * V_10 ,
struct V_5 * V_6 )
{
int V_48 ;
if ( V_6 -> V_123 & V_128 ) {
F_51 ( V_10 -> V_33 , V_6 ) ;
F_55 ( V_10 ) ;
} else if ( V_6 -> V_123 & V_124 ) {
for ( V_48 = 0 ; V_48 < V_6 -> V_121 ; V_48 ++ )
F_51 ( V_6 -> V_117 [ V_48 ] . V_122 , V_6 ) ;
F_52 ( V_10 ) ;
} else
F_51 ( V_10 -> V_33 , V_6 ) ;
}
static int F_85 ( struct V_15 * V_10 , T_7 V_180 )
{
T_6 V_181 ;
struct V_132 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_143 ;
V_181 = F_87 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
F_76 ( & V_6 -> V_172 ) ;
F_77 ( & V_6 -> V_101 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_62 ( V_10 , V_19 ) ;
F_88 ( V_10 ) ;
F_84 ( V_10 ) ;
F_89 ( V_10 , F_90 ( V_10 , V_180 ) ) ;
return 0 ;
}
static int F_91 ( struct V_15 * V_10 )
{
int error ;
struct V_132 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_143 ;
F_89 ( V_10 , V_182 ) ;
F_92 ( V_10 , V_182 , 0 ) ;
F_93 ( V_10 ) ;
if ( F_57 ( V_10 ) ) {
F_50 ( L_14 , V_183 ) ;
return - V_135 ;
}
error = F_59 ( V_10 , F_60 ( 64 ) ) ;
if ( error ) {
error = F_59 ( V_10 , F_60 ( 32 ) ) ;
if ( error ) {
F_50 ( L_13 ,
V_19 -> V_20 ) ;
goto V_184;
}
}
F_63 ( V_10 ) ;
if ( F_47 ( V_10 , V_6 ) == V_129 )
goto V_185;
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_101 , F_39 ) ;
F_70 ( & V_6 -> V_113 , 16 ) ;
F_70 ( & V_6 -> V_169 , 16 ) ;
V_6 -> V_170 = V_171 ;
F_71 ( & V_6 -> V_172 ) ;
V_6 -> V_172 . V_173 = V_174 + F_72 ( 6 * V_175 ) ;
V_6 -> V_172 . V_176 = ( unsigned long ) V_6 ;
V_6 -> V_172 . V_177 = & V_178 ;
F_73 ( & V_6 -> V_172 ) ;
return 0 ;
V_185:
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
V_184:
F_80 ( V_19 ) ;
F_81 ( V_6 ) ;
F_16 ( V_6 ) ;
F_82 ( V_10 ) ;
F_83 ( V_19 ) ;
F_84 ( V_10 ) ;
return - V_135 ;
}
static T_4 F_94 ( struct V_5 * V_6 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
F_13 ( V_186 , & V_47 -> V_66 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_15
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_95 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
F_13 ( V_187 , V_47 -> V_57 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_15
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_96 ( struct V_5 * V_58 )
{
struct V_59 T_1 * V_47 = V_58 -> V_24 ;
F_13 ( V_186 , & V_47 -> V_66 ) ;
F_13 ( V_68 , & V_47 -> V_69 ) ;
if ( ! F_26 ( V_58 ) ) {
F_9 ( V_18
L_15
, V_58 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_97 ( struct V_5 * V_58 )
{
struct V_61 * V_47 = V_58 -> V_62 ;
F_13 ( V_186 , V_47 -> V_66 ) ;
if ( ! F_27 ( V_58 ) ) {
F_15 ( L_16
L_17 , V_58 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_98 ( struct V_5 * V_6 )
{
T_4 V_188 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_188 = F_94 ( V_6 ) ;
}
break;
case V_8 : {
V_188 = F_95 ( V_6 ) ;
}
break;
case V_23 : {
V_188 = F_96 ( V_6 ) ;
}
break;
case V_9 :
V_188 = F_97 ( V_6 ) ;
break;
}
return V_188 ;
}
static void F_99 ( struct V_72 * V_189 )
{
struct V_190 * V_191 = V_189 -> V_191 ;
F_100 ( V_191 ) ;
}
static void F_101 ( struct V_72 * V_189 )
{
struct V_5 * V_6 = V_189 -> V_6 ;
struct V_190 * V_191 = V_189 -> V_191 ;
unsigned long V_31 ;
F_102 ( & V_6 -> V_192 ) ;
F_99 ( V_189 ) ;
V_189 -> V_193 = V_194 ;
F_103 ( & V_6 -> V_154 , V_31 ) ;
F_38 ( & V_189 -> V_97 , & V_6 -> V_98 ) ;
F_104 ( & V_6 -> V_154 , V_31 ) ;
V_191 -> V_195 ( V_191 ) ;
}
static void F_105 ( struct V_72 * V_189 )
{
struct V_190 * V_191 = V_189 -> V_191 ;
struct V_196 * V_197 = (struct V_196 * ) V_191 -> V_198 ;
V_191 -> V_199 = V_200 << 16 ;
if ( V_197 ) {
int V_201 =
sizeof( struct V_196 ) < V_202
? sizeof( struct V_196 ) : V_202 ;
memset ( V_197 , 0 , V_202 ) ;
memcpy ( V_197 , V_189 -> V_95 . V_203 , V_201 ) ;
V_197 -> V_204 = V_205 ;
V_197 -> V_206 = 1 ;
}
}
static T_8 F_87 ( struct V_5 * V_6 )
{
T_8 V_207 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_207 = F_12 ( & V_47 -> V_208 ) ;
F_13 ( V_207 | V_209 , \
& V_47 -> V_208 ) ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
V_207 = F_12 ( V_47 -> V_210 ) ;
F_13 ( 0 , V_47 -> V_210 ) ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
V_207 = F_12 ( & V_47 -> V_211 ) ;
F_13 ( V_207 | V_212 , & V_47 -> V_211 ) ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
F_13 ( V_213 , V_47 -> V_214 ) ;
}
break;
}
return V_207 ;
}
static void F_106 ( struct V_5 * V_6 ,
struct V_72 * V_189 , bool error )
{
T_4 V_131 , V_107 ;
V_131 = V_189 -> V_191 -> V_215 -> V_131 ;
V_107 = V_189 -> V_191 -> V_215 -> V_107 ;
if ( ! error ) {
if ( V_6 -> V_81 [ V_131 ] [ V_107 ] == V_82 )
V_6 -> V_81 [ V_131 ] [ V_107 ] = V_216 ;
V_189 -> V_191 -> V_199 = V_200 << 16 ;
F_101 ( V_189 ) ;
} else{
switch ( V_189 -> V_95 . V_217 ) {
case V_218 : {
V_6 -> V_81 [ V_131 ] [ V_107 ] = V_82 ;
V_189 -> V_191 -> V_199 = V_219 << 16 ;
F_101 ( V_189 ) ;
}
break;
case V_220 :
case V_221 : {
V_6 -> V_81 [ V_131 ] [ V_107 ] = V_82 ;
V_189 -> V_191 -> V_199 = V_222 << 16 ;
F_101 ( V_189 ) ;
}
break;
case V_223 : {
V_6 -> V_81 [ V_131 ] [ V_107 ] = V_216 ;
F_105 ( V_189 ) ;
F_101 ( V_189 ) ;
}
break;
default:
F_9 ( V_18
L_18
, V_6 -> V_19 -> V_20
, V_131
, V_107
, V_189 -> V_95 . V_217 ) ;
V_6 -> V_81 [ V_131 ] [ V_107 ] = V_82 ;
V_189 -> V_191 -> V_199 = V_219 << 16 ;
F_101 ( V_189 ) ;
break;
}
}
}
static void F_107 ( struct V_5 * V_6 , struct V_72 * V_224 , bool error )
{
int V_131 , V_107 ;
if ( ( V_224 -> V_6 != V_6 ) || ( V_224 -> V_193 != V_225 ) ) {
if ( V_224 -> V_193 == V_226 ) {
struct V_190 * V_227 = V_224 -> V_191 ;
if ( V_227 ) {
V_131 = V_227 -> V_215 -> V_131 ;
V_107 = V_227 -> V_215 -> V_107 ;
V_227 -> V_199 |= V_228 << 16 ;
F_101 ( V_224 ) ;
F_9 ( V_18 L_19 ,
V_6 -> V_19 -> V_20 , V_224 ) ;
}
return;
}
F_9 ( V_18 L_20
L_21
L_22
, V_6 -> V_19 -> V_20
, V_6
, V_224
, V_224 -> V_6
, V_224 -> V_193
, F_108 ( & V_6 -> V_192 ) ) ;
return;
}
F_106 ( V_6 , V_224 , error ) ;
}
static void F_109 ( struct V_5 * V_6 )
{
int V_48 = 0 ;
T_6 V_229 , V_230 ;
struct V_231 * V_232 ;
bool error ;
struct V_72 * V_224 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
T_6 V_49 ;
V_49 = F_12 ( & V_47 -> V_49 ) &
V_6 -> V_233 ;
F_13 ( V_49 , & V_47 -> V_49 ) ;
while( ( ( V_229 = F_12 ( & V_47 -> V_234 ) ) != 0xFFFFFFFF )
&& ( V_48 ++ < V_148 ) ) {
V_232 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_224 = F_40 ( V_232 , struct V_72 , V_95 ) ;
error = ( V_229 & V_235 ) ? true : false ;
F_107 ( V_6 , V_224 , error ) ;
}
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
F_13 ( V_236 , V_47 -> V_53 ) ;
for ( V_48 = 0 ; V_48 < V_237 ; V_48 ++ ) {
V_229 = V_47 -> V_238 [ V_48 ] ;
if ( V_229 != 0 ) {
V_47 -> V_238 [ V_48 ] = 0 ;
V_232 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_224 = F_40 ( V_232 , struct V_72 , V_95 ) ;
error = ( V_229 & V_235 ) ? true : false ;
F_107 ( V_6 , V_224 , error ) ;
}
V_47 -> V_239 [ V_48 ] = 0 ;
}
V_47 -> V_240 = 0 ;
V_47 -> V_241 = 0 ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
while ( ( F_12 ( & V_47 -> V_242 ) & V_243 ) && ( V_48 ++ < V_148 ) ) {
V_229 = F_12 ( & V_47 -> V_244 ) ;
V_230 = ( V_229 & 0xFFFFFFF0 ) ;
V_232 = (struct V_231 * ) ( V_6 -> V_94 + V_230 ) ;
V_224 = F_40 ( V_232 , struct V_72 , V_95 ) ;
error = ( V_229 & V_245 ) ? true : false ;
F_107 ( V_6 , V_224 , error ) ;
}
}
break;
case V_9 : {
struct V_61 * V_246 = V_6 -> V_62 ;
T_6 V_247 ;
T_6 V_240 , V_248 , V_249 , V_250 , V_251 ;
unsigned long V_31 ;
V_250 = F_108 ( & V_6 -> V_192 ) ;
for ( V_48 = 0 ; V_48 < V_250 ; V_48 ++ ) {
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_247 =
V_246 -> V_238 [ 0 ] . V_249 + 1 ;
V_240 = V_246 -> V_240 ;
if ( ( V_240 & 0xFFF ) !=
( V_247 & 0xFFF ) ) {
V_251 = V_240 & 0x4000 ;
V_248 = ( V_240 & 0xFFF ) + 1 ;
V_248 %= V_252 ;
V_246 -> V_240 = V_248 ? ( V_248 | V_251 ) :
( ( V_251 ^ 0x4000 ) + 1 ) ;
V_240 = V_246 -> V_240 ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
V_249 = V_246 -> V_238 [ V_240 &
0xFFF ] . V_249 ;
V_230 = ( V_249 & 0xFFFFFFF0 ) ;
V_232 = (struct V_231 * )
( V_6 -> V_94 + V_230 ) ;
V_224 = F_40 ( V_232 ,
struct V_72 , V_95 ) ;
error = ( V_249 &
V_245 ) ?
true : false ;
F_107 ( V_6 , V_224 , error ) ;
F_13 ( V_240 ,
V_246 -> V_253 ) ;
} else {
F_104 ( & V_6 -> V_156 , V_31 ) ;
F_110 ( 10 ) ;
}
}
V_246 -> V_241 = 0 ;
V_246 -> V_240 = 0x40FF ;
}
break;
}
}
static void F_111 ( struct V_15 * V_10 )
{
struct V_132 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_143 ;
int V_254 = 0 ;
F_112 ( V_6 ) ;
F_80 ( V_19 ) ;
F_77 ( & V_6 -> V_101 ) ;
F_76 ( & V_6 -> V_172 ) ;
F_87 ( V_6 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
V_6 -> V_123 |= V_162 ;
V_6 -> V_123 &= ~ V_255 ;
for ( V_254 = 0 ; V_254 < V_148 ; V_254 ++ ) {
if ( ! F_108 ( & V_6 -> V_192 ) )
break;
F_18 ( V_6 ) ;
F_24 ( 25 ) ;
}
if ( F_108 ( & V_6 -> V_192 ) ) {
int V_48 ;
F_98 ( V_6 ) ;
F_109 ( V_6 ) ;
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ ) {
struct V_72 * V_189 = V_6 -> V_96 [ V_48 ] ;
if ( V_189 -> V_193 == V_225 ) {
V_189 -> V_193 = V_226 ;
V_189 -> V_191 -> V_199 = V_228 << 16 ;
F_101 ( V_189 ) ;
}
}
}
F_79 ( V_10 , V_6 ) ;
F_81 ( V_6 ) ;
F_3 ( V_6 ) ;
F_16 ( V_6 ) ;
F_82 ( V_10 ) ;
F_83 ( V_19 ) ;
F_84 ( V_10 ) ;
}
static void F_113 ( struct V_15 * V_10 )
{
struct V_132 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_143 ;
F_76 ( & V_6 -> V_172 ) ;
F_87 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
F_77 ( & V_6 -> V_101 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static int F_114 ( void )
{
int error = 0 ;
error = F_115 ( & V_256 ) ;
return error ;
}
static void F_116 ( void )
{
F_117 ( & V_256 ) ;
}
static void F_118 ( struct V_5 * V_6 ,
T_8 V_181 )
{
T_8 V_257 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_257 = V_181 & ~ ( V_258 |
V_259 |
V_260 ) ;
F_13 ( V_257 , & V_47 -> V_208 ) ;
V_6 -> V_233 = ~ ( V_181 & V_257 ) & 0x000000ff ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
V_257 = V_181 | ( V_261 |
V_262 |
V_263 |
V_54 ) ;
F_13 ( V_257 , V_47 -> V_210 ) ;
V_6 -> V_233 = ( V_181 | V_257 ) & 0x0000000f ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
V_257 = ~ ( V_264 | V_265 | V_266 ) ;
F_13 ( V_181 & V_257 , & V_47 -> V_211 ) ;
V_6 -> V_233 = ~ ( V_181 & V_257 ) & 0x0000000f ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
V_257 = V_267 ;
F_13 ( V_181 | V_257 , V_47 -> V_214 ) ;
break;
}
}
}
static int F_119 ( struct V_5 * V_6 ,
struct V_72 * V_189 , struct V_190 * V_191 )
{
struct V_231 * V_95 = (struct V_231 * ) & V_189 -> V_95 ;
T_9 * V_268 = ( T_9 * ) & V_95 -> V_269 ;
T_10 V_270 , V_271 ;
int V_272 = 0x30 ;
T_10 V_273 = 0 ;
int V_48 ;
struct V_274 * V_275 ;
int V_276 ;
V_189 -> V_191 = V_191 ;
memset ( V_95 , 0 , sizeof( struct V_231 ) ) ;
V_95 -> V_277 = V_191 -> V_215 -> V_131 ;
V_95 -> V_278 = V_191 -> V_215 -> V_107 ;
V_95 -> V_279 = 1 ;
V_95 -> V_280 = 0 ;
memcpy ( V_95 -> V_281 , V_191 -> V_282 , V_191 -> V_283 ) ;
V_276 = F_120 ( V_191 ) ;
if ( F_121 ( V_276 > V_6 -> V_19 -> V_88 || V_276 < 0 ) )
return V_129 ;
F_122 (pcmd, sg, nseg, i) {
V_273 = F_123 ( F_124 ( V_275 ) ) ;
V_270 = F_123 ( F_125 ( F_126 ( V_275 ) ) ) ;
V_271 = F_123 ( F_127 ( F_126 ( V_275 ) ) ) ;
if ( V_271 == 0 ) {
struct V_284 * V_285 = (struct V_284 * ) V_268 ;
V_285 -> V_286 = V_270 ;
V_285 -> V_273 = V_273 ;
V_268 += sizeof ( struct V_284 ) ;
V_272 += sizeof ( struct V_284 ) ;
} else {
struct V_89 * V_285 = (struct V_89 * ) V_268 ;
V_285 -> V_287 = V_271 ;
V_285 -> V_286 = V_270 ;
V_285 -> V_273 = V_273 | F_123 ( V_288 ) ;
V_268 += sizeof ( struct V_89 ) ;
V_272 += sizeof ( struct V_89 ) ;
}
}
V_95 -> V_289 = ( T_4 ) V_276 ;
V_95 -> V_290 = F_128 ( V_191 ) ;
V_95 -> V_291 = V_272 / 0x100 + ( V_272 % 0x100 ? 1 : 0 ) ;
if ( V_272 > 256 )
V_95 -> V_292 |= V_293 ;
if ( V_191 -> V_294 == V_295 )
V_95 -> V_292 |= V_296 ;
V_189 -> V_297 = V_272 ;
return V_125 ;
}
static void F_129 ( struct V_5 * V_6 , struct V_72 * V_189 )
{
T_6 V_75 = V_189 -> V_75 ;
struct V_231 * V_95 = (struct V_231 * ) & V_189 -> V_95 ;
F_41 ( & V_6 -> V_192 ) ;
V_189 -> V_193 = V_225 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
if ( V_95 -> V_292 & V_293 )
F_13 ( V_75 | V_298 ,
& V_47 -> V_299 ) ;
else
F_13 ( V_75 , & V_47 -> V_299 ) ;
break;
}
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
T_6 V_300 , V_301 = V_47 -> V_241 ;
V_300 = ( ( V_301 + 1 ) % V_237 ) ;
V_47 -> V_239 [ V_300 ] = 0 ;
if ( V_95 -> V_292 & V_293 ) {
V_47 -> V_239 [ V_301 ] =
V_75 | V_298 ;
} else {
V_47 -> V_239 [ V_301 ] = V_75 ;
}
V_301 ++ ;
V_301 %= V_237 ;
V_47 -> V_241 = V_301 ;
F_13 ( V_302 , V_47 -> V_57 ) ;
}
break;
case V_23 : {
struct V_59 T_1 * V_60 = V_6 -> V_24 ;
T_6 V_303 , V_297 ;
V_297 = ( V_189 -> V_297 > 0x300 ) ? 0x300 : V_189 -> V_297 ;
V_303 = ( V_75 | ( ( V_297 - 1 ) >> 6 ) | 1 ) ;
if ( V_6 -> V_304 ) {
F_13 ( V_6 -> V_304 , & V_60 -> V_305 ) ;
F_13 ( V_303 , & V_60 -> V_306 ) ;
} else {
F_13 ( V_303 , & V_60 -> V_306 ) ;
}
}
break;
case V_9 : {
struct V_61 * V_246 = V_6 -> V_62 ;
T_11 V_248 ;
T_11 V_241 , V_251 ;
unsigned long V_31 ;
struct V_307 * V_308 ;
F_103 ( & V_6 -> V_155 , V_31 ) ;
V_241 = V_246 -> V_241 ;
V_308 = (struct V_307 * ) & ( V_246 -> V_239 [ V_241 & 0xFF ] ) ;
V_308 -> V_309 = F_127 ( V_75 ) ;
V_308 -> V_249 = F_125 ( V_75 ) ;
V_308 -> V_273 = V_189 -> V_297 >> 2 ;
V_95 -> V_280 = F_125 ( V_75 ) ;
V_251 = V_241 & 0x4000 ;
V_248 = V_241 + 1 ;
V_248 &= ( V_310 - 1 ) ;
V_246 -> V_241 = V_248 ? ( V_248 | V_251 ) :
( V_251 ^ 0x4000 ) ;
F_13 ( V_241 , V_246 -> V_311 ) ;
F_104 ( & V_6 -> V_155 , V_31 ) ;
break;
}
}
}
static void F_130 ( struct V_5 * V_6 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_6 -> V_123 &= ~ V_312 ;
F_13 ( V_313 , & V_47 -> V_66 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_23
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_131 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
V_6 -> V_123 &= ~ V_312 ;
F_13 ( V_314 , V_47 -> V_57 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_23
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_132 ( struct V_5 * V_58 )
{
struct V_59 T_1 * V_47 = V_58 -> V_24 ;
V_58 -> V_123 &= ~ V_312 ;
F_13 ( V_313 , & V_47 -> V_66 ) ;
F_13 ( V_68 , & V_47 -> V_69 ) ;
if ( ! F_26 ( V_58 ) ) {
F_9 ( V_18
L_23
, V_58 -> V_19 -> V_20 ) ;
}
return;
}
static void F_133 ( struct V_5 * V_58 )
{
struct V_61 * V_47 = V_58 -> V_62 ;
V_58 -> V_123 &= ~ V_312 ;
F_13 ( V_313 , V_47 -> V_66 ) ;
if ( ! F_27 ( V_58 ) )
F_15 ( L_24
L_25 , V_58 -> V_19 -> V_20 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
F_130 ( V_6 ) ;
}
break;
case V_8 : {
F_131 ( V_6 ) ;
}
break;
case V_23 : {
F_132 ( V_6 ) ;
}
break;
case V_9 :
F_133 ( V_6 ) ;
break;
}
}
static void F_81 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_90 , V_6 -> V_70 , V_6 -> V_71 ) ;
}
static void F_134 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
F_13 ( V_315 , & V_47 -> V_69 ) ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
F_13 ( V_316 , V_47 -> V_57 ) ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
F_13 ( V_317 , & V_47 -> V_69 ) ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
F_13 ( V_318 ,
V_47 -> V_69 ) ;
}
break;
}
}
static void F_135 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
F_13 ( V_319 , & V_47 -> V_69 ) ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
F_13 ( V_320 , V_47 -> V_57 ) ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
F_13 ( V_321 , & V_47 -> V_69 ) ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
F_13 ( V_322 ,
V_47 -> V_69 ) ;
}
break;
}
}
struct V_323 T_1 * F_136 ( struct V_5 * V_6 )
{
struct V_323 T_1 * V_324 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_324 = (struct V_323 T_1 * ) & V_47 -> V_325 ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
V_324 = (struct V_323 T_1 * ) V_47 -> V_325 ;
}
break;
case V_23 : {
struct V_59 T_1 * V_60 = V_6 -> V_24 ;
V_324 = (struct V_323 T_1 * ) & V_60 -> V_325 ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
V_324 = (struct V_323 T_1 * ) V_47 -> V_325 ;
}
break;
}
return V_324 ;
}
static struct V_323 T_1 * F_137 ( struct V_5 * V_6 )
{
struct V_323 T_1 * V_326 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_326 = (struct V_323 T_1 * ) & V_47 -> V_327 ;
}
break;
case V_8 : {
struct V_51 * V_47 = V_6 -> V_52 ;
V_326 = (struct V_323 T_1 * ) V_47 -> V_327 ;
}
break;
case V_23 : {
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
V_326 = (struct V_323 T_1 * ) & V_47 -> V_327 ;
}
break;
case V_9 : {
struct V_61 * V_47 = V_6 -> V_62 ;
V_326 = (struct V_323 T_1 * ) V_47 -> V_327 ;
}
break;
}
return V_326 ;
}
static T_6
F_138 ( struct V_5 * V_6 ,
struct V_323 T_1 * V_328 )
{
T_4 * V_329 ;
T_4 * V_330 = NULL ;
T_6 T_1 * V_331 ;
T_6 V_332 , V_333 , * V_334 = NULL ;
V_331 = ( T_6 T_1 * ) V_328 -> V_176 ;
V_332 = F_12 ( & V_328 -> V_333 ) ;
if ( V_332 > 0 ) {
V_330 = F_139 ( 128 , V_335 ) ;
V_334 = ( T_6 * ) V_330 ;
if ( V_330 == NULL )
return 0 ;
V_333 = V_332 ;
while ( V_333 >= 4 ) {
* V_334 ++ = F_12 ( V_331 ) ;
V_331 ++ ;
V_333 -= 4 ;
}
if ( V_333 )
* V_334 = F_12 ( V_331 ) ;
V_334 = ( T_6 * ) V_330 ;
}
while ( V_332 > 0 ) {
V_329 = & V_6 -> V_336 [ V_6 -> V_337 ] ;
* V_329 = * V_330 ;
V_6 -> V_337 ++ ;
V_6 -> V_337 %= V_338 ;
V_330 ++ ;
V_332 -- ;
}
F_22 ( V_334 ) ;
F_134 ( V_6 ) ;
return 1 ;
}
T_6
F_140 ( struct V_5 * V_6 ,
struct V_323 T_1 * V_328 ) {
T_4 * V_329 ;
T_4 T_1 * V_331 ;
T_6 V_332 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) )
return F_138 ( V_6 , V_328 ) ;
V_331 = ( T_4 T_1 * ) V_328 -> V_176 ;
V_332 = F_12 ( & V_328 -> V_333 ) ;
while ( V_332 > 0 ) {
V_329 = & V_6 -> V_336 [ V_6 -> V_337 ] ;
* V_329 = F_42 ( V_331 ) ;
V_6 -> V_337 ++ ;
V_6 -> V_337 %= V_338 ;
V_331 ++ ;
V_332 -- ;
}
F_134 ( V_6 ) ;
return 1 ;
}
static void F_141 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
struct V_323 T_1 * V_328 ;
T_12 V_339 ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_328 = F_136 ( V_6 ) ;
V_339 = ( V_6 -> V_337 - V_6 -> V_340 - 1 ) &
( V_338 - 1 ) ;
if ( V_339 >= F_12 ( & V_328 -> V_333 ) ) {
if ( F_140 ( V_6 , V_328 ) == 0 )
V_6 -> V_123 |= V_341 ;
} else
V_6 -> V_123 |= V_341 ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
}
static void F_142 ( struct V_5 * V_6 )
{
T_4 * V_329 ;
struct V_323 T_1 * V_342 ;
T_4 * V_330 = NULL ;
T_6 T_1 * V_331 ;
T_6 V_343 = 0 , V_333 , * V_334 = NULL , V_176 ;
if ( V_6 -> V_123 & V_161 ) {
V_330 = F_139 ( 128 , V_335 ) ;
V_334 = ( T_6 * ) V_330 ;
if ( V_330 == NULL )
return;
V_6 -> V_123 &= ( ~ V_161 ) ;
V_342 = F_137 ( V_6 ) ;
V_331 = ( T_6 T_1 * ) V_342 -> V_176 ;
while ( ( V_6 -> V_344 != V_6 -> V_345 )
&& ( V_343 < 124 ) ) {
V_329 = & V_6 -> V_346 [ V_6 -> V_344 ] ;
* V_330 = * V_329 ;
V_6 -> V_344 ++ ;
V_6 -> V_344 %= V_338 ;
V_330 ++ ;
V_343 ++ ;
}
V_333 = V_343 ;
V_330 = ( T_4 * ) V_334 ;
while ( V_333 >= 4 ) {
V_176 = * V_334 ++ ;
F_13 ( V_176 , V_331 ) ;
V_331 ++ ;
V_333 -= 4 ;
}
if ( V_333 ) {
V_176 = * V_334 ;
F_13 ( V_176 , V_331 ) ;
}
F_13 ( V_343 , & V_342 -> V_333 ) ;
F_22 ( V_330 ) ;
F_135 ( V_6 ) ;
}
}
void
F_143 ( struct V_5 * V_6 )
{
T_4 * V_329 ;
struct V_323 T_1 * V_342 ;
T_4 T_1 * V_331 ;
T_12 V_343 = 0 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) ) {
F_142 ( V_6 ) ;
return;
}
if ( V_6 -> V_123 & V_161 ) {
V_6 -> V_123 &= ( ~ V_161 ) ;
V_342 = F_137 ( V_6 ) ;
V_331 = ( T_4 T_1 * ) V_342 -> V_176 ;
while ( ( V_6 -> V_344 != V_6 -> V_345 )
&& ( V_343 < 124 ) ) {
V_329 = & V_6 -> V_346 [ V_6 -> V_344 ] ;
F_144 ( * V_329 , V_331 ) ;
V_6 -> V_344 ++ ;
V_6 -> V_344 %= V_338 ;
V_331 ++ ;
V_343 ++ ;
}
F_13 ( V_343 , & V_342 -> V_333 ) ;
F_135 ( V_6 ) ;
}
}
static void F_145 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
F_103 ( & V_6 -> V_158 , V_31 ) ;
V_6 -> V_123 |= V_161 ;
if ( V_6 -> V_344 != V_6 -> V_345 )
F_143 ( V_6 ) ;
if ( V_6 -> V_344 == V_6 -> V_345 )
V_6 -> V_123 |= V_159 ;
F_104 ( & V_6 -> V_158 , V_31 ) ;
}
static void F_146 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_25 = F_12 ( & V_47 -> V_25 ) ;
do {
F_13 ( V_25 , & V_47 -> V_25 ) ;
if ( V_25 & V_347 )
F_141 ( V_6 ) ;
if ( V_25 & V_348 )
F_145 ( V_6 ) ;
V_25 = F_12 ( & V_47 -> V_25 ) ;
} while ( V_25 & ( V_347
| V_348 ) );
}
static void F_147 ( struct V_5 * V_58 )
{
T_6 V_25 ;
struct V_59 T_1 * V_47 = V_58 -> V_24 ;
V_25 = F_12 ( & V_47 -> V_25 ) ;
do {
F_13 ( V_25 , & V_47 -> V_28 ) ;
F_12 ( & V_47 -> V_28 ) ;
if ( V_25 & V_349 )
F_141 ( V_58 ) ;
if ( V_25 & V_350 )
F_145 ( V_58 ) ;
if ( V_25 & V_26 )
F_148 ( V_58 ) ;
V_25 = F_12 ( & V_47 -> V_25 ) ;
} while ( V_25 & ( V_349
| V_350
| V_26 ) );
}
static void F_149 ( struct V_5 * V_58 )
{
T_6 V_25 ;
struct V_61 * V_246 = V_58 -> V_62 ;
V_25 = F_12 ( V_246 -> V_25 ) ;
do {
F_13 ( V_25 , V_246 -> V_25 ) ;
if ( V_25 & V_63 )
F_150 ( V_58 ) ;
if ( V_25 & V_351 )
F_141 ( V_58 ) ;
if ( V_25 & V_352 )
F_145 ( V_58 ) ;
V_25 = F_12 ( V_246 -> V_25 ) ;
} while ( V_25 & ( V_351
| V_352
| V_63 ) );
}
static void F_151 ( struct V_5 * V_6 )
{
T_6 V_229 ;
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
struct V_231 * V_232 ;
struct V_72 * V_224 ;
bool error ;
while ( ( V_229 = F_12 ( & V_47 -> V_234 ) ) != 0xFFFFFFFF ) {
V_232 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_224 = F_40 ( V_232 , struct V_72 , V_95 ) ;
error = ( V_229 & V_235 ) ? true : false ;
F_107 ( V_6 , V_224 , error ) ;
}
}
static void F_152 ( struct V_5 * V_6 )
{
T_6 V_301 ;
T_6 V_229 ;
struct V_51 * V_47 = V_6 -> V_52 ;
struct V_231 * V_232 ;
struct V_72 * V_224 ;
bool error ;
V_301 = V_47 -> V_240 ;
while ( ( V_229 = V_47 -> V_238 [ V_301 ] ) != 0 ) {
V_47 -> V_238 [ V_301 ] = 0 ;
V_232 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_224 = F_40 ( V_232 , struct V_72 , V_95 ) ;
error = ( V_229 & V_235 ) ? true : false ;
F_107 ( V_6 , V_224 , error ) ;
V_301 ++ ;
V_301 %= V_237 ;
V_47 -> V_240 = V_301 ;
}
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_59 T_1 * V_60 ;
struct V_231 * V_95 ;
struct V_72 * V_189 ;
T_6 V_229 , V_230 , V_353 = 0 ;
int error ;
V_60 = V_6 -> V_24 ;
while ( ( V_229 = F_12 ( & V_60 -> V_244 ) ) !=
0xFFFFFFFF ) {
V_230 = ( V_229 & 0xFFFFFFF0 ) ;
V_95 = (struct V_231 * ) ( V_6 -> V_94
+ V_230 ) ;
V_189 = F_40 ( V_95 , struct V_72 ,
V_95 ) ;
error = ( V_229 & V_245 )
? true : false ;
F_107 ( V_6 , V_189 , error ) ;
V_353 ++ ;
if ( V_353 == V_354 ) {
F_13 ( V_355 ,
& V_60 -> V_69 ) ;
V_353 = 0 ;
}
}
}
static void F_154 ( struct V_5 * V_6 )
{
T_8 V_247 , V_240 , V_248 , V_251 ;
T_6 V_249 , V_230 ;
int error ;
struct V_61 * V_246 ;
struct V_231 * V_95 ;
struct V_72 * V_189 ;
unsigned long V_31 ;
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_246 = V_6 -> V_62 ;
V_247 = V_246 -> V_238 [ 0 ] . V_249 + 1 ;
V_240 = V_246 -> V_240 ;
if ( ( V_240 & 0xFFF ) != ( V_247 & 0xFFF ) ) {
do {
V_251 = V_240 & 0x4000 ;
V_248 = ( V_240 & 0xFFF ) + 1 ;
V_248 %= V_252 ;
V_246 -> V_240 = V_248 ? ( V_248 | V_251 ) :
( ( V_251 ^ 0x4000 ) + 1 ) ;
V_240 = V_246 -> V_240 ;
V_249 = V_246 -> V_238 [ V_240 &
0xFFF ] . V_249 ;
V_230 = ( V_249 & 0xFFFFFFF0 ) ;
V_95 = (struct V_231 * ) ( V_6 -> V_94
+ V_230 ) ;
V_189 = F_40 ( V_95 ,
struct V_72 , V_95 ) ;
error = ( V_249 & V_245 )
? true : false ;
F_107 ( V_6 , V_189 , error ) ;
F_13 ( V_240 , V_246 -> V_253 ) ;
} while ( ( V_240 & 0xFFF ) !=
( V_247 & 0xFFF ) );
}
F_13 ( V_356 ,
V_246 -> V_357 ) ;
F_12 ( V_246 -> V_357 ) ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
}
static void F_155 ( struct V_5 * V_6 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
F_13 ( V_50 , & V_47 -> V_49 ) ;
F_156 ( & V_6 -> V_101 ) ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
F_13 ( V_55 , V_47 -> V_53 ) ;
F_156 ( & V_6 -> V_101 ) ;
}
static void F_148 ( struct V_5 * V_6 )
{
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
F_13 ( V_27 , & V_47 -> V_28 ) ;
F_156 ( & V_6 -> V_101 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_61 * V_47 = V_6 -> V_62 ;
F_13 ( V_63 , V_47 -> V_25 ) ;
F_12 ( V_47 -> V_25 ) ;
F_156 ( & V_6 -> V_101 ) ;
}
static int F_158 ( struct V_5 * V_6 )
{
T_6 V_49 ;
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
V_49 = F_12 ( & V_47 -> V_49 ) &
V_6 -> V_233 ;
if ( ! ( V_49 & V_358 ) )
return V_359 ;
do {
F_13 ( V_49 , & V_47 -> V_49 ) ;
if ( V_49 & V_360 )
F_146 ( V_6 ) ;
if ( V_49 & V_361 )
F_151 ( V_6 ) ;
if ( V_49 & V_50 )
F_155 ( V_6 ) ;
V_49 = F_12 ( & V_47 -> V_49 ) &
V_6 -> V_233 ;
} while ( V_49 & ( V_360
| V_361
| V_50 ) );
return V_362 ;
}
static int F_159 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_51 * V_47 = V_6 -> V_52 ;
V_25 = F_12 ( V_47 -> V_53 ) &
V_6 -> V_233 ;
if ( ! V_25 )
return V_359 ;
do {
F_13 ( ~ V_25 , V_47 -> V_53 ) ;
F_13 ( V_56 , V_47 -> V_57 ) ;
if ( V_25 & V_261 )
F_141 ( V_6 ) ;
if ( V_25 & V_262 )
F_145 ( V_6 ) ;
if ( V_25 & V_263 )
F_152 ( V_6 ) ;
if ( V_25 & V_54 )
F_157 ( V_6 ) ;
V_25 = F_12 ( V_47 -> V_53 ) &
V_6 -> V_233 ;
} while ( V_25 & ( V_261
| V_262
| V_263
| V_54 ) );
return V_362 ;
}
static int F_160 ( struct V_5 * V_58 )
{
T_6 V_363 ;
struct V_59 T_1 * V_60 = V_58 -> V_24 ;
V_363 = F_12 ( & V_60 -> V_242 ) &
( V_243 |
V_364 ) ;
if ( ! V_363 )
return V_359 ;
do {
if ( V_363 & V_364 )
F_147 ( V_58 ) ;
if ( V_363 & V_243 )
F_153 ( V_58 ) ;
V_363 = F_12 ( & V_60 -> V_242 ) ;
} while ( V_363 & ( V_243 |
V_364 ) );
return V_362 ;
}
static T_2 F_161 ( struct V_5 * V_58 )
{
T_8 V_363 ;
struct V_61 * V_246 = V_58 -> V_62 ;
V_363 = F_12 ( V_246 -> V_242 ) &
( V_365 |
V_366 ) ;
if ( ! V_363 )
return V_359 ;
do {
if ( V_363 &
V_365 )
F_154 ( V_58 ) ;
if ( V_363 &
V_366 )
F_149 ( V_58 ) ;
V_363 = F_12 ( V_246 -> V_242 ) ;
} while ( V_363 &
( V_365 |
V_366 ) );
return V_362 ;
}
static T_2 F_18 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 :
return F_158 ( V_6 ) ;
break;
case V_8 :
return F_159 ( V_6 ) ;
break;
case V_23 :
return F_160 ( V_6 ) ;
case V_9 :
return F_161 ( V_6 ) ;
default:
return V_359 ;
}
}
static void F_162 ( struct V_5 * V_6 )
{
if ( V_6 ) {
if ( V_6 -> V_123 & V_312 ) {
T_6 V_181 ;
V_6 -> V_123 &= ~ V_312 ;
V_181 = F_87 ( V_6 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_118 ( V_6 , V_181 ) ;
}
}
}
void F_163 ( struct V_5 * V_6 )
{
T_6 V_48 ;
if ( V_6 -> V_123 & V_341 ) {
for ( V_48 = 0 ; V_48 < 15 ; V_48 ++ ) {
if ( V_6 -> V_123 & V_341 ) {
V_6 -> V_123 &= ~ V_341 ;
V_6 -> V_340 = 0 ;
V_6 -> V_337 = 0 ;
F_134 ( V_6 ) ;
F_110 ( 30 ) ;
} else if ( V_6 -> V_340 !=
V_6 -> V_337 ) {
V_6 -> V_340 = 0 ;
V_6 -> V_337 = 0 ;
F_110 ( 30 ) ;
} else
break;
}
}
}
static int F_164 ( struct V_5 * V_6 ,
struct V_190 * V_367 )
{
char * V_45 ;
unsigned short V_368 ;
int V_369 = 0 , V_370 = 0 ;
unsigned long V_31 ;
struct V_371 * V_372 ;
T_6 V_373 = ( T_6 ) V_367 -> V_282 [ 5 ] << 24 |
( T_6 ) V_367 -> V_282 [ 6 ] << 16 |
( T_6 ) V_367 -> V_282 [ 7 ] << 8 |
( T_6 ) V_367 -> V_282 [ 8 ] ;
struct V_274 * V_275 ;
V_368 = F_165 ( V_367 ) ;
V_275 = F_166 ( V_367 ) ;
V_45 = F_167 ( F_168 ( V_275 ) ) + V_275 -> V_374 ;
if ( V_368 > 1 ) {
V_369 = V_375 ;
goto V_376;
}
V_370 += V_275 -> V_273 ;
if ( V_370 > sizeof( struct V_371 ) ) {
V_369 = V_375 ;
F_53 ( L_26 , V_183 ) ;
goto V_376;
}
V_372 = (struct V_371 * ) V_45 ;
switch ( V_373 ) {
case V_377 : {
unsigned char * V_378 ;
T_4 * V_379 ;
T_6 V_343 = 0 ;
V_378 = F_139 ( V_380 , V_335 ) ;
if ( ! V_378 ) {
V_369 = V_375 ;
F_53 ( L_27 , V_183 ) ;
goto V_376;
}
V_379 = V_378 ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
if ( V_6 -> V_340 != V_6 -> V_337 ) {
unsigned int V_381 = V_6 -> V_340 ;
unsigned int V_382 = V_6 -> V_337 ;
unsigned int V_383 = F_169 ( V_382 , V_381 , V_338 ) ;
V_343 = F_170 ( V_382 , V_381 , V_338 ) ;
if ( V_343 > V_380 )
V_343 = V_380 ;
if ( V_343 <= V_383 )
memcpy ( V_379 , V_6 -> V_336 + V_381 , V_343 ) ;
else {
memcpy ( V_379 , V_6 -> V_336 + V_381 , V_383 ) ;
memcpy ( V_379 + V_383 , V_6 -> V_336 , V_343 - V_383 ) ;
}
V_6 -> V_340 = ( V_6 -> V_340 + V_343 ) % V_338 ;
}
memcpy ( V_372 -> V_384 , V_378 ,
V_343 ) ;
if ( V_6 -> V_123 & V_341 ) {
struct V_323 T_1 * V_328 ;
V_6 -> V_123 &= ~ V_341 ;
V_328 = F_136 ( V_6 ) ;
if ( F_140 ( V_6 , V_328 ) == 0 )
V_6 -> V_123 |= V_341 ;
}
F_104 ( & V_6 -> V_157 , V_31 ) ;
F_22 ( V_378 ) ;
V_372 -> V_385 . V_386 = V_343 ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
break;
}
case V_391 : {
unsigned char * V_378 ;
T_12 V_392 , V_393 ;
T_4 * V_329 , * V_394 ;
V_378 = F_139 ( V_380 , V_335 ) ;
if ( ! V_378 ) {
V_369 = V_375 ;
goto V_376;
}
V_394 = V_378 ;
V_392 = V_372 -> V_385 . V_386 ;
memcpy ( V_394 ,
V_372 -> V_384 , V_392 ) ;
F_103 ( & V_6 -> V_158 , V_31 ) ;
if ( V_6 -> V_345 != V_6 -> V_344 ) {
struct V_196 * V_197 =
(struct V_196 * ) V_367 -> V_198 ;
F_143 ( V_6 ) ;
V_197 -> V_204 = V_205 ;
V_197 -> V_395 = V_396 ;
V_197 -> V_397 = 0x0A ;
V_197 -> V_398 = 0x20 ;
V_197 -> V_206 = 1 ;
V_369 = V_375 ;
} else {
V_329 = & V_6 -> V_346 [ V_6 -> V_345 ] ;
V_393 = V_338 - V_6 -> V_345 ;
if ( V_392 > V_393 ) {
memcpy ( V_329 , V_394 , V_393 ) ;
V_394 += V_393 ;
V_392 -= V_393 ;
V_6 -> V_345 = 0 ;
V_329 = V_6 -> V_346 ;
}
memcpy ( V_329 , V_394 , V_392 ) ;
V_6 -> V_345 += V_392 ;
V_6 -> V_345 %= V_338 ;
if ( V_6 -> V_123 & V_159 ) {
V_6 -> V_123 &=
~ V_159 ;
F_143 ( V_6 ) ;
}
}
F_104 ( & V_6 -> V_158 , V_31 ) ;
F_22 ( V_378 ) ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
break;
}
case V_399 : {
T_4 * V_329 = V_6 -> V_336 ;
F_163 ( V_6 ) ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_6 -> V_123 |= V_160 ;
V_6 -> V_340 = 0 ;
V_6 -> V_337 = 0 ;
memset ( V_329 , 0 , V_338 ) ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
break;
}
case V_400 : {
T_4 * V_329 = V_6 -> V_346 ;
F_103 ( & V_6 -> V_158 , V_31 ) ;
V_6 -> V_123 |= ( V_159 |
V_161 ) ;
V_6 -> V_344 = 0 ;
V_6 -> V_345 = 0 ;
memset ( V_329 , 0 , V_338 ) ;
F_104 ( & V_6 -> V_158 , V_31 ) ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
break;
}
case V_401 : {
T_4 * V_329 ;
F_163 ( V_6 ) ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_6 -> V_123 |= V_160 ;
V_6 -> V_340 = 0 ;
V_6 -> V_337 = 0 ;
V_329 = V_6 -> V_336 ;
memset ( V_329 , 0 , sizeof( struct V_323 ) ) ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
F_103 ( & V_6 -> V_158 , V_31 ) ;
V_6 -> V_123 |= ( V_159 |
V_161 ) ;
V_6 -> V_344 = 0 ;
V_6 -> V_345 = 0 ;
V_329 = V_6 -> V_346 ;
memset ( V_329 , 0 , sizeof( struct V_323 ) ) ;
F_104 ( & V_6 -> V_158 , V_31 ) ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
break;
}
case V_402 : {
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_403 ;
break;
}
case V_404 : {
T_9 * V_405 = L_28 ;
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
memcpy ( V_372 -> V_384 ,
V_405 , ( V_406 ) strlen ( V_405 ) ) ;
break;
}
case V_407 : {
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
F_162 ( V_6 ) ;
break;
}
case V_408 : {
if ( V_6 -> V_170 == V_387 )
V_372 -> V_385 . V_388 =
V_389 ;
else
V_372 -> V_385 . V_388 =
V_390 ;
F_32 ( V_6 ) ;
break;
}
default:
V_369 = V_375 ;
F_53 ( L_29 , V_183 ) ;
}
V_376:
if ( V_368 ) {
struct V_274 * V_275 = F_166 ( V_367 ) ;
F_171 ( V_45 - V_275 -> V_374 ) ;
}
return V_369 ;
}
static struct V_72 * F_172 ( struct V_5 * V_6 )
{
struct V_409 * V_382 = & V_6 -> V_98 ;
struct V_72 * V_189 = NULL ;
unsigned long V_31 ;
F_103 ( & V_6 -> V_154 , V_31 ) ;
if ( ! F_173 ( V_382 ) ) {
V_189 = F_174 ( V_382 -> V_410 , struct V_72 , V_97 ) ;
F_175 ( & V_189 -> V_97 ) ;
} else{
F_104 ( & V_6 -> V_154 , V_31 ) ;
return NULL ;
}
F_104 ( & V_6 -> V_154 , V_31 ) ;
return V_189 ;
}
static void F_176 ( struct V_5 * V_6 ,
struct V_190 * V_367 )
{
switch ( V_367 -> V_282 [ 0 ] ) {
case V_411 : {
unsigned char V_412 [ 36 ] ;
char * V_45 ;
struct V_274 * V_275 ;
if ( V_367 -> V_215 -> V_107 ) {
V_367 -> V_199 = ( V_413 << 16 ) ;
V_367 -> V_195 ( V_367 ) ;
return;
}
V_412 [ 0 ] = V_414 ;
V_412 [ 1 ] = 0 ;
V_412 [ 2 ] = 0 ;
V_412 [ 4 ] = 31 ;
strncpy ( & V_412 [ 8 ] , L_30 , 8 ) ;
strncpy ( & V_412 [ 16 ] , L_31 , 16 ) ;
strncpy ( & V_412 [ 32 ] , L_32 , 4 ) ;
V_275 = F_166 ( V_367 ) ;
V_45 = F_167 ( F_168 ( V_275 ) ) + V_275 -> V_374 ;
memcpy ( V_45 , V_412 , sizeof( V_412 ) ) ;
V_275 = F_166 ( V_367 ) ;
F_171 ( V_45 - V_275 -> V_374 ) ;
V_367 -> V_195 ( V_367 ) ;
}
break;
case V_415 :
case V_416 : {
if ( F_164 ( V_6 , V_367 ) )
V_367 -> V_199 = ( V_417 << 16 ) ;
V_367 -> V_195 ( V_367 ) ;
}
break;
default:
V_367 -> V_195 ( V_367 ) ;
}
}
static int F_177 ( struct V_190 * V_367 ,
void (* F_178)( struct V_190 * ) )
{
struct V_132 * V_19 = V_367 -> V_215 -> V_19 ;
struct V_5 * V_6 = (struct V_5 * ) V_19 -> V_143 ;
struct V_72 * V_189 ;
int V_106 = V_367 -> V_215 -> V_131 ;
int V_107 = V_367 -> V_215 -> V_107 ;
T_4 V_418 = V_367 -> V_282 [ 0 ] ;
V_367 -> V_195 = F_178 ;
V_367 -> V_419 = NULL ;
V_367 -> V_199 = 0 ;
if ( ( V_418 == V_420 ) || ( V_418 == V_421 ) ) {
if( V_6 -> V_81 [ V_106 ] [ V_107 ] == V_82 ) {
V_367 -> V_199 = ( V_219 << 16 ) ;
}
V_367 -> V_195 ( V_367 ) ;
return 0 ;
}
if ( V_106 == 16 ) {
F_176 ( V_6 , V_367 ) ;
return 0 ;
}
V_189 = F_172 ( V_6 ) ;
if ( ! V_189 )
return V_422 ;
if ( F_119 ( V_6 , V_189 , V_367 ) == V_129 ) {
V_367 -> V_199 = ( V_417 << 16 ) | ( V_423 << 1 ) ;
V_367 -> V_195 ( V_367 ) ;
return 0 ;
}
F_129 ( V_6 , V_189 ) ;
return 0 ;
}
bool F_179 ( struct V_5 * V_6 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
struct V_15 * V_10 = V_6 -> V_10 ;
void * V_70 ;
T_5 V_71 ;
char * V_424 = V_6 -> V_425 ;
char * V_426 = V_6 -> V_427 ;
char * V_428 = V_6 -> V_103 ;
char T_1 * V_429 ;
char T_1 * V_430 ;
char T_1 * V_431 ;
int V_432 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_51 ) , 32 ) ;
V_70 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_71 , V_92 ) ;
if ( ! V_70 ) {
F_9 ( V_18
L_33 ,
V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_14 = V_71 ;
V_6 -> V_13 = V_70 ;
V_47 = (struct V_51 * ) V_70 ;
V_6 -> V_52 = V_47 ;
V_47 -> V_57 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_433 ) ;
V_47 -> V_434 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_435 ) ;
V_47 -> V_53 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_436 ) ;
V_47 -> V_210 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_437 ) ;
V_47 -> V_327 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_438 ) ;
V_47 -> V_325 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_439 ) ;
V_47 -> V_111 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_440 ) ;
V_429 = ( char T_1 * ) ( & V_47 -> V_111 [ 15 ] ) ;
V_430 = ( char T_1 * ) ( & V_47 -> V_111 [ 17 ] ) ;
V_431 = ( char T_1 * ) ( & V_47 -> V_111 [ 21 ] ) ;
F_13 ( V_441 , V_47 -> V_57 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18 L_34 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_432 = 8 ;
while ( V_432 ) {
* V_424 = F_42 ( V_429 ) ;
V_424 ++ ;
V_429 ++ ;
V_432 -- ;
}
V_432 = 16 ;
while ( V_432 ) {
* V_426 = F_42 ( V_430 ) ;
V_426 ++ ;
V_430 ++ ;
V_432 -- ;
}
V_432 = 16 ;
while( V_432 ) {
* V_428 = F_42 ( V_431 ) ;
V_428 ++ ;
V_431 ++ ;
V_432 -- ;
}
F_15 ( L_35 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_425 ,
V_6 -> V_427 ) ;
V_6 -> V_104 = F_12 ( & V_47 -> V_111 [ 1 ] ) ;
V_6 -> V_442 = F_12 ( & V_47 -> V_111 [ 2 ] ) ;
V_6 -> V_443 = F_12 ( & V_47 -> V_111 [ 3 ] ) ;
V_6 -> V_444 = F_12 ( & V_47 -> V_111 [ 4 ] ) ;
V_6 -> V_445 = F_12 ( & V_47 -> V_111 [ 5 ] ) ;
V_6 -> V_85 = F_12 ( & V_47 -> V_111 [ 25 ] ) ;
return true ;
}
static bool F_180 ( struct V_5 * V_58 )
{
T_6 V_181 , V_446 , V_447 = 0 ;
struct V_59 T_1 * V_47 = V_58 -> V_24 ;
char * V_424 = V_58 -> V_425 ;
char * V_426 = V_58 -> V_427 ;
char T_1 * V_429 = ( char T_1 * ) ( & V_47 -> V_112 [ 15 ] ) ;
char T_1 * V_430 = ( char T_1 * ) ( & V_47 -> V_112 [ 17 ] ) ;
int V_432 ;
V_181 = F_12 ( & V_47 -> V_211 ) ;
F_13 ( V_181 | V_212 , & V_47 -> V_211 ) ;
do {
V_447 = F_12 ( & V_47 -> V_448 ) ;
} while ( ( V_447 & V_449 ) == 0 );
F_13 ( V_450 , & V_47 -> V_66 ) ;
F_13 ( V_68 , & V_47 -> V_69 ) ;
for ( V_446 = 0 ; V_446 < 2000 ; V_446 ++ ) {
if ( F_12 ( & V_47 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_47 -> V_28 ) ;
break;
}
F_181 ( 10 ) ;
}
if ( V_446 >= 2000 ) {
F_9 ( V_18 L_34 , V_58 -> V_19 -> V_20 ) ;
return false ;
}
V_432 = 8 ;
while ( V_432 ) {
* V_424 = F_42 ( V_429 ) ;
V_424 ++ ;
V_429 ++ ;
V_432 -- ;
}
V_432 = 16 ;
while ( V_432 ) {
* V_426 = F_42 ( V_430 ) ;
V_426 ++ ;
V_430 ++ ;
V_432 -- ;
}
F_15 ( L_35 ,
V_58 -> V_19 -> V_20 ,
V_58 -> V_425 ,
V_58 -> V_427 ) ;
V_58 -> V_442 = F_12 ( & V_47 -> V_112 [ 1 ] ) ;
V_58 -> V_443 = F_12 ( & V_47 -> V_112 [ 2 ] ) ;
V_58 -> V_444 = F_12 ( & V_47 -> V_112 [ 3 ] ) ;
V_58 -> V_445 = F_12 ( & V_47 -> V_112 [ 4 ] ) ;
V_58 -> V_85 = F_12 ( & V_47 -> V_112 [ 25 ] ) ;
return true ;
}
static bool F_182 ( struct V_5 * V_6 )
{
char * V_424 = V_6 -> V_425 ;
char * V_426 = V_6 -> V_427 ;
char * V_428 = V_6 -> V_103 ;
char T_1 * V_429 ;
char T_1 * V_430 ;
char T_1 * V_431 ;
T_8 V_432 ;
struct V_61 * V_47 ;
void * V_13 ;
T_5 V_14 ;
struct V_15 * V_10 = V_6 -> V_10 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_61 ) , 32 ) ;
V_13 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_14 , V_92 ) ;
if ( ! V_13 ) {
F_15 ( L_36 ) ;
return false ;
}
memset ( V_13 , 0 , V_6 -> V_12 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_13 = V_13 ;
V_47 = (struct V_61 * ) V_13 ;
V_6 -> V_62 = V_47 ;
V_47 -> V_451 = V_6 -> V_21 + V_452 ;
V_47 -> V_453 = V_6 -> V_21 +
V_454 ;
V_47 -> V_455 = V_6 -> V_21 +
V_456 ;
V_47 -> V_457 = V_6 -> V_21 + V_458 ;
V_47 -> V_459 = V_6 -> V_21 + V_460 ;
V_47 -> V_242 = V_6 -> V_21 +
V_461 ;
V_47 -> V_214 = V_6 -> V_21 +
V_462 ;
V_47 -> V_66 = V_6 -> V_21 +
V_463 ;
V_47 -> V_464 = V_6 -> V_21 +
V_465 ;
V_47 -> V_466 = V_6 -> V_21 +
V_467 ;
V_47 -> V_448 = V_6 -> V_21 +
V_468 ;
V_47 -> V_69 = V_6 -> V_21 +
V_469 ;
V_47 -> V_25 = V_6 -> V_21 +
V_470 ;
V_47 -> V_471 = V_6 -> V_21 +
V_472 ;
V_47 -> V_473 = V_6 -> V_21 +
V_474 ;
V_47 -> V_475 = V_6 -> V_21 +
V_476 ;
V_47 -> V_311 = V_6 -> V_21 +
V_477 ;
V_47 -> V_478 = V_6 -> V_21 +
V_479 ;
V_47 -> V_480 = V_6 -> V_21 +
V_481 ;
V_47 -> V_482 = V_6 -> V_21 +
V_483 ;
V_47 -> V_253 = V_6 -> V_21 +
V_484 ;
V_47 -> V_357 = V_6 -> V_21 +
V_485 ;
V_47 -> V_486 = V_6 -> V_21 +
V_487 ;
V_47 -> V_327 = V_6 -> V_21 + V_488 ;
V_47 -> V_325 = V_6 -> V_21 + V_489 ;
V_47 -> V_112 = V_6 -> V_21 +
V_490 ;
V_429 = ( char T_1 * ) ( & V_47 -> V_112 [ 15 ] ) ;
V_430 = ( char T_1 * ) ( & V_47 -> V_112 [ 17 ] ) ;
V_431 = ( char T_1 * ) ( & V_47 -> V_112 [ 21 ] ) ;
if ( F_12 ( V_6 -> V_62 -> V_25 ) &
V_63 ) {
F_13 ( V_63 ,
V_6 -> V_62 -> V_25 ) ;
}
F_13 ( V_450 , V_47 -> V_66 ) ;
if ( ! F_27 ( V_6 ) ) {
F_15 ( L_37
L_38 , V_6 -> V_19 -> V_20 ) ;
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 , V_6 -> V_14 ) ;
return false ;
}
V_432 = 8 ;
while ( V_432 ) {
* V_424 = F_42 ( V_429 ) ;
V_424 ++ ;
V_429 ++ ;
V_432 -- ;
}
V_432 = 16 ;
while ( V_432 ) {
* V_426 = F_42 ( V_430 ) ;
V_426 ++ ;
V_430 ++ ;
V_432 -- ;
}
V_432 = 16 ;
while ( V_432 ) {
* V_428 = F_42 ( V_431 ) ;
V_428 ++ ;
V_431 ++ ;
V_432 -- ;
}
V_6 -> V_104 = F_12 ( & V_47 -> V_112 [ 1 ] ) ;
V_6 -> V_442 = F_12 ( & V_47 -> V_112 [ 2 ] ) ;
V_6 -> V_443 = F_12 ( & V_47 -> V_112 [ 3 ] ) ;
V_6 -> V_444 = F_12 ( & V_47 -> V_112 [ 4 ] ) ;
V_6 -> V_445 = F_12 ( & V_47 -> V_112 [ 5 ] ) ;
V_6 -> V_85 = F_12 ( & V_47 -> V_112 [ 25 ] ) ;
F_15 ( L_35 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_425 ,
V_6 -> V_427 ) ;
return true ;
}
static bool F_66 ( struct V_5 * V_6 )
{
bool V_491 = false ;
switch ( V_6 -> V_7 ) {
case V_16 :
V_491 = F_183 ( V_6 ) ;
break;
case V_8 :
V_491 = F_179 ( V_6 ) ;
break;
case V_23 :
V_491 = F_180 ( V_6 ) ;
break;
case V_9 :
V_491 = F_182 ( V_6 ) ;
break;
default:
break;
}
if ( V_6 -> V_443 > V_148 )
V_6 -> V_492 = V_148 ;
else
V_6 -> V_492 = V_6 -> V_443 - 1 ;
V_6 -> V_19 -> V_147 = V_6 -> V_492 ;
return V_491 ;
}
static int F_184 ( struct V_5 * V_6 ,
struct V_72 * V_493 )
{
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
struct V_72 * V_189 ;
struct V_231 * V_95 ;
T_6 V_229 , V_49 , V_494 = 0 , V_254 = 0 ;
int V_491 ;
bool error ;
V_495:
V_254 ++ ;
V_49 = F_12 ( & V_47 -> V_49 ) & V_6 -> V_233 ;
F_13 ( V_49 , & V_47 -> V_49 ) ;
while ( 1 ) {
if ( ( V_229 = F_12 ( & V_47 -> V_234 ) ) == 0xFFFFFFFF ) {
if ( V_494 ) {
V_491 = V_125 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_254 > 100 ) {
V_491 = V_129 ;
break;
}
goto V_495;
}
}
V_95 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_189 = F_40 ( V_95 , struct V_72 , V_95 ) ;
V_494 |= ( V_189 == V_493 ) ? 1 : 0 ;
if ( ( V_189 -> V_6 != V_6 ) || ( V_189 -> V_193 != V_225 ) ) {
if ( ( V_189 -> V_193 == V_226 ) || ( V_189 == V_493 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_189 -> V_191 -> V_215 -> V_131
, ( T_8 ) V_189 -> V_191 -> V_215 -> V_107
, V_189 ) ;
V_189 -> V_191 -> V_199 = V_228 << 16 ;
F_101 ( V_189 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_189
, F_108 ( & V_6 -> V_192 ) ) ;
continue;
}
error = ( V_229 & V_235 ) ? true : false ;
F_106 ( V_6 , V_189 , error ) ;
}
return V_491 ;
}
static int F_185 ( struct V_5 * V_6 ,
struct V_72 * V_493 )
{
struct V_51 * V_47 = V_6 -> V_52 ;
struct V_231 * V_95 ;
struct V_72 * V_189 ;
T_6 V_229 , V_494 = 0 , V_254 = 0 ;
int V_301 , V_491 ;
bool error ;
V_496:
V_254 ++ ;
F_13 ( V_236 , V_47 -> V_53 ) ;
while( 1 ) {
V_301 = V_47 -> V_240 ;
V_229 = V_47 -> V_238 [ V_301 ] ;
if ( V_229 == 0 ) {
if ( V_494 ) {
V_491 = V_125 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_254 > 100 ) {
V_491 = V_129 ;
break;
}
goto V_496;
}
}
V_47 -> V_238 [ V_301 ] = 0 ;
V_301 ++ ;
V_301 %= V_237 ;
V_47 -> V_240 = V_301 ;
V_95 = (struct V_231 * ) ( V_6 -> V_94 + ( V_229 << 5 ) ) ;
V_189 = F_40 ( V_95 , struct V_72 , V_95 ) ;
V_494 |= ( V_189 == V_493 ) ? 1 : 0 ;
if ( ( V_189 -> V_6 != V_6 ) || ( V_189 -> V_193 != V_225 ) ) {
if ( ( V_189 -> V_193 == V_226 ) || ( V_189 == V_493 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_189 -> V_191 -> V_215 -> V_131
, ( T_8 ) V_189 -> V_191 -> V_215 -> V_107
, V_189 ) ;
V_189 -> V_191 -> V_199 = V_228 << 16 ;
F_101 ( V_189 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_189
, F_108 ( & V_6 -> V_192 ) ) ;
continue;
}
error = ( V_229 & V_235 ) ? true : false ;
F_106 ( V_6 , V_189 , error ) ;
}
return V_491 ;
}
static int F_186 ( struct V_5 * V_6 ,
struct V_72 * V_493 )
{
struct V_59 T_1 * V_47 = V_6 -> V_24 ;
T_6 V_229 , V_230 ;
struct V_231 * V_95 ;
bool error ;
struct V_72 * V_224 ;
T_6 V_494 = 0 , V_254 = 0 ;
int V_491 ;
V_497:
V_254 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_47 -> V_242 ) & V_243 ) == 0 ) {
if ( V_494 ) {
V_491 = V_125 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_254 > 100 ) {
V_491 = V_129 ;
break;
}
goto V_497;
}
}
V_229 = F_12 ( & V_47 -> V_244 ) ;
V_230 = ( V_229 & 0xFFFFFFF0 ) ;
V_95 = (struct V_231 * ) ( V_6 -> V_94 + V_230 ) ;
V_224 = F_40 ( V_95 , struct V_72 , V_95 ) ;
V_494 |= ( V_224 == V_493 ) ? 1 : 0 ;
if ( ( V_224 -> V_6 != V_6 ) || ( V_224 -> V_193 != V_225 ) ) {
if ( V_224 -> V_193 == V_226 ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_224 -> V_191 -> V_215 -> V_131
, ( T_8 ) V_224 -> V_191 -> V_215 -> V_107
, V_224 ) ;
V_224 -> V_191 -> V_199 = V_228 << 16 ;
F_101 ( V_224 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_224
, F_108 ( & V_6 -> V_192 ) ) ;
continue;
}
error = ( V_229 & V_245 ) ? true : false ;
F_106 ( V_6 , V_224 , error ) ;
}
return V_491 ;
}
static int F_187 ( struct V_5 * V_6 ,
struct V_72 * V_493 )
{
bool error ;
T_6 V_494 = 0 , V_254 = 0 , V_229 , V_230 ;
int V_491 , V_240 , V_248 , V_247 , V_251 ;
unsigned long V_31 ;
struct V_231 * V_95 ;
struct V_72 * V_224 ;
struct V_61 * V_246 = V_6 -> V_62 ;
V_498:
V_254 ++ ;
while ( 1 ) {
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_247 = V_246 -> V_238 [ 0 ] . V_249 + 1 ;
V_240 = V_246 -> V_240 ;
if ( ( V_247 & 0xFFF ) == ( V_240 & 0xFFF ) ) {
F_104 ( & V_6 -> V_156 , V_31 ) ;
if ( V_494 ) {
V_491 = V_125 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_254 > 40 ) {
V_491 = V_129 ;
break;
}
goto V_498;
}
}
V_251 = V_240 & 0x4000 ;
V_248 = ( V_240 & 0xFFF ) + 1 ;
V_248 %= V_252 ;
V_246 -> V_240 = V_248 ? ( V_248 | V_251 ) :
( ( V_251 ^ 0x4000 ) + 1 ) ;
V_240 = V_246 -> V_240 ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
V_229 = V_246 -> V_238 [ V_240 & 0xFFF ] . V_249 ;
V_230 = ( V_229 & 0xFFFFFFF0 ) ;
V_95 = (struct V_231 * ) ( V_6 -> V_94 +
V_230 ) ;
V_224 = F_40 ( V_95 , struct V_72 ,
V_95 ) ;
V_494 |= ( V_224 == V_493 ) ? 1 : 0 ;
if ( ( V_224 -> V_6 != V_6 ) ||
( V_224 -> V_193 != V_225 ) ) {
if ( V_224 -> V_193 == V_226 ) {
F_15 ( L_44
L_45
L_46
, V_6 -> V_19 -> V_20
, V_224 -> V_191 -> V_215 -> V_131
, ( T_8 ) V_224 -> V_191 -> V_215 -> V_107
, V_224 ) ;
V_224 -> V_191 -> V_199 = V_228 << 16 ;
F_101 ( V_224 ) ;
continue;
}
F_15 ( L_47
L_48
L_49
, V_6 -> V_19 -> V_20
, V_224
, F_108 ( & V_6 -> V_192 ) ) ;
continue;
}
error = ( V_229 & V_245 )
? true : false ;
F_106 ( V_6 , V_224 , error ) ;
}
return V_491 ;
}
static int F_188 ( struct V_5 * V_6 ,
struct V_72 * V_493 )
{
int V_491 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_491 = F_184 ( V_6 , V_493 ) ;
}
break;
case V_8 : {
V_491 = F_185 ( V_6 , V_493 ) ;
}
break;
case V_23 : {
V_491 = F_186 ( V_6 , V_493 ) ;
}
break;
case V_9 :
V_491 = F_187 ( V_6 , V_493 ) ;
break;
}
return V_491 ;
}
static int F_189 ( struct V_5 * V_6 )
{
T_6 V_75 , V_304 ;
T_5 V_71 ;
switch ( V_6 -> V_7 ) {
case V_8 :
case V_9 :
V_71 = V_6 -> V_14 ;
break;
default:
V_71 = V_6 -> V_71 ;
break;
}
V_75 = F_190 ( V_71 ) ;
V_304 = F_191 ( V_71 ) ;
V_6 -> V_304 = V_304 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
if ( V_304 != 0 ) {
struct V_46 T_1 * V_47 = V_6 -> V_17 ;
F_13 ( V_499 , \
& V_47 -> V_111 [ 0 ] ) ;
F_13 ( V_304 , & V_47 -> V_111 [ 1 ] ) ;
F_13 ( V_500 , \
& V_47 -> V_66 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 (KERN_NOTICE L_50set ccb high \
part physical address timeout\nL_51arcmsr%d:can not set diver mode\nL_52set configL_53arcmsr%d: 'set command Q window' \
timeout \nL_54arcmsr%d: can't set driver mode.\n",
acb->host->host_no);
return 1;
}
}
break;
case ACB_ADAPTER_TYPE_C: {
if (cdb_phyaddr_hi32 != 0) {
struct MessageUnit_C __iomem *reg = acb->pmuC;
printk(KERN_NOTICE "arcmsr%d: cdb_phyaddr_hi32=0x%x\n",
acb->adapter_index, cdb_phyaddr_hi32);
writel(ARCMSR_SIGNATURE_SET_CONFIG, &reg->msgcode_rwbuffer[0]);
writel(cdb_phyaddr_hi32, &reg->msgcode_rwbuffer[1]);
writel(ARCMSR_INBOUND_MESG0_SET_CONFIG, &reg->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &reg->inbound_doorbell);
if (!arcmsr_hbaC_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: 'set command Q window' \
timeout \n", acb->host->host_no);
return 1;
}
}
}
break;
case ACB_ADAPTER_TYPE_D: {
uint32_t __iomem *rwbuffer;
struct MessageUnit_D *reg = acb->pmuD;
reg->postq_index = 0;
reg->doneq_index = 0;
rwbuffer = reg->msgcode_rwbuffer;
writel(ARCMSR_SIGNATURE_SET_CONFIG, rwbuffer++);
writel(cdb_phyaddr_hi32, rwbuffer++);
writel(cdb_phyaddr, rwbuffer++);
writel(cdb_phyaddr + (ARCMSR_MAX_ARC1214_POSTQUEUE *
sizeof(struct InBound_SRB)), rwbuffer++);
writel(0x100, rwbuffer);
writel(ARCMSR_INBOUND_MESG0_SET_CONFIG, reg->inbound_msgaddr0);
if (!arcmsr_hbaD_wait_msgint_ready(acb)) {
pr_notice("arcmsr%d: 'set command Q window' timeout\n",
acb->host->host_no);
return 1;
}
}
break;
}
return 0;
}
static void arcmsr_wait_firmware_ready(struct AdapterControlBlock *acb)
{
uint32_t firmware_state = 0;
switch (acb->adapter_type) {
case ACB_ADAPTER_TYPE_A: {
struct MessageUnit_A __iomem *reg = acb->pmuA;
do {
firmware_state = readl(&reg->outbound_msgaddr1);
} while ((firmware_state & ARCMSR_OUTBOUND_MESG1_FIRMWARE_OK) == 0);
}
break;
case ACB_ADAPTER_TYPE_B: {
struct MessageUnit_B *reg = acb->pmuB;
do {
firmware_state = readl(reg->iop2drv_doorbell);
} while ((firmware_state & ARCMSR_MESSAGE_FIRMWARE_OK) == 0);
writel(ARCMSR_DRV2IOP_END_OF_INTERRUPT, reg->drv2iop_doorbell);
}
break;
case ACB_ADAPTER_TYPE_C: {
struct MessageUnit_C __iomem *reg = acb->pmuC;
do {
firmware_state = readl(&reg->outbound_msgaddr1);
} while ((firmware_state & ARCMSR_HBCMU_MESSAGE_FIRMWARE_OK) == 0);
}
break;
case ACB_ADAPTER_TYPE_D: {
struct MessageUnit_D *reg = acb->pmuD;
do {
firmware_state = readl(reg->outbound_msgaddr1);
} while ((firmware_state &
ARCMSR_ARC1214_MESSAGE_FIRMWARE_OK) == 0);
}
break;
}
}
static void arcmsr_hbaA_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_A __iomem *reg = acb->pmuA;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0 ) || ((acb->acb_flags & ACB_F_ABORT) != 0 )){
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)){
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG, &reg->inbound_msgaddr0);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaB_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_B *reg = acb->pmuB;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0 ) || ((acb->acb_flags & ACB_F_ABORT) != 0 )){
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_MESSAGE_GET_CONFIG, reg->drv2iop_doorbell);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaC_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_C __iomem *reg = acb->pmuC;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) || ((acb->acb_flags & ACB_F_BUS_RESET) != 0) || ((acb->acb_flags & ACB_F_ABORT) != 0)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) == atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value, atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG, &reg->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &reg->inbound_doorbell);
mod_timer(&acb->eternal_timer, jiffies + msecs_to_jiffies(6 * HZ));
}
return;
}
static void arcmsr_hbaD_request_device_map(struct AdapterControlBlock *acb)
{
struct MessageUnit_D *reg = acb->pmuD;
if (unlikely(atomic_read(&acb->rq_map_token) == 0) ||
((acb->acb_flags & ACB_F_BUS_RESET) != 0) ||
((acb->acb_flags & ACB_F_ABORT) != 0)) {
mod_timer(&acb->eternal_timer,
jiffies + msecs_to_jiffies(6 * HZ));
} else {
acb->fw_flag = FW_NORMAL;
if (atomic_read(&acb->ante_token_value) ==
atomic_read(&acb->rq_map_token)) {
atomic_set(&acb->rq_map_token, 16);
}
atomic_set(&acb->ante_token_value,
atomic_read(&acb->rq_map_token));
if (atomic_dec_and_test(&acb->rq_map_token)) {
mod_timer(&acb->eternal_timer, jiffies +
msecs_to_jiffies(6 * HZ));
return;
}
writel(ARCMSR_INBOUND_MESG0_GET_CONFIG,
reg->inbound_msgaddr0);
mod_timer(&acb->eternal_timer, jiffies +
msecs_to_jiffies(6 * HZ));
}
}
static void arcmsr_request_device_map(unsigned long pacb)
{
struct AdapterControlBlock *acb = (struct AdapterControlBlock *)pacb;
switch (acb->adapter_type) {
case ACB_ADAPTER_TYPE_A: {
arcmsr_hbaA_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_B: {
arcmsr_hbaB_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_C: {
arcmsr_hbaC_request_device_map(acb);
}
break;
case ACB_ADAPTER_TYPE_D:
arcmsr_hbaD_request_device_map(acb);
break;
}
}
static void arcmsr_hbaA_start_bgrb(struct AdapterControlBlock *acb)
{
struct MessageUnit_A __iomem *reg = acb->pmuA;
acb->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, &reg->inbound_msgaddr0);
if (!arcmsr_hbaA_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n", acb->host->host_no);
}
}
static void arcmsr_hbaB_start_bgrb(struct AdapterControlBlock *acb)
{
struct MessageUnit_B *reg = acb->pmuB;
acb->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_MESSAGE_START_BGRB, reg->drv2iop_doorbell);
if (!arcmsr_hbaB_wait_msgint_ready(acb)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n",acb->host->host_no);
}
}
static void arcmsr_hbaC_start_bgrb(struct AdapterControlBlock *pACB)
{
struct MessageUnit_C __iomem *phbcmu = pACB->pmuC;
pACB->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, &phbcmu->inbound_msgaddr0);
writel(ARCMSR_HBCMU_DRV2IOP_MESSAGE_CMD_DONE, &phbcmu->inbound_doorbell);
if (!arcmsr_hbaC_wait_msgint_ready(pACB)) {
printk(KERN_NOTICE "arcmsr%d: wait 'start adapter background \
rebulid' timeout \n", pACB->host->host_no);
}
return;
}
static void arcmsr_hbaD_start_bgrb(struct AdapterControlBlock *pACB)
{
struct MessageUnit_D *pmu = pACB->pmuD;
pACB->acb_flags |= ACB_F_MSG_START_BGRB;
writel(ARCMSR_INBOUND_MESG0_START_BGRB, pmu->inbound_msgaddr0);
if (!arcmsr_hbaD_wait_msgint_ready(pACB)) {
pr_notice("arcmsr%d: wait 'start adapter L_55background rebulid'
