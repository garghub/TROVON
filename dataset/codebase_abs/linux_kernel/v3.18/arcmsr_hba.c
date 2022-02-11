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
case V_13 : {
F_4 ( & V_10 -> V_14 -> V_15 , V_10 -> V_16 ,
V_10 -> V_17 , V_10 -> V_18 ) ;
break;
}
}
}
static bool F_5 ( struct V_9 * V_10 )
{
struct V_19 * V_14 = V_10 -> V_14 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
V_10 -> V_21 = F_6 ( F_7 ( V_14 , 0 ) , F_8 ( V_14 , 0 ) ) ;
if ( ! V_10 -> V_21 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
break;
}
case V_12 : {
void T_1 * V_25 , * V_26 ;
V_25 = F_6 ( F_7 ( V_14 , 0 ) , F_8 ( V_14 , 0 ) ) ;
if ( ! V_25 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_26 = F_6 ( F_7 ( V_14 , 2 ) , F_8 ( V_14 , 2 ) ) ;
if ( ! V_26 ) {
F_10 ( V_25 ) ;
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_10 -> V_25 = V_25 ;
V_10 -> V_26 = V_26 ;
break;
}
case V_27 : {
V_10 -> V_28 = F_11 ( F_7 ( V_14 , 1 ) , F_8 ( V_14 , 1 ) ) ;
if ( ! V_10 -> V_28 ) {
F_9 ( V_22 L_1 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
if ( F_12 ( & V_10 -> V_28 -> V_29 ) & V_30 ) {
F_13 ( V_31 , & V_10 -> V_28 -> V_32 ) ;
return true ;
}
break;
}
case V_13 : {
void T_1 * V_25 ;
unsigned long V_33 , V_34 , V_35 ;
V_33 = ( unsigned long ) F_7 ( V_14 , 0 ) ;
V_34 = F_8 ( V_14 , 0 ) ;
V_35 = F_14 ( V_14 , 0 ) ;
if ( V_35 & V_36 )
V_25 = F_6 ( V_33 , V_34 ) ;
else
V_25 = F_11 ( V_33 , V_34 ) ;
if ( ! V_25 ) {
F_15 ( L_2 ,
V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_10 -> V_25 = V_25 ;
break;
}
}
return true ;
}
static void F_16 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 : {
F_10 ( V_10 -> V_21 ) ;
}
break;
case V_12 : {
F_10 ( V_10 -> V_25 ) ;
F_10 ( V_10 -> V_26 ) ;
}
break;
case V_27 : {
F_10 ( V_10 -> V_28 ) ;
}
break;
case V_13 :
F_10 ( V_10 -> V_25 ) ;
break;
}
}
static T_2 F_17 ( int V_37 , void * V_38 )
{
T_2 V_39 ;
struct V_9 * V_10 = V_38 ;
V_39 = F_18 ( V_10 ) ;
return V_39 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_3 V_42 , int * V_43 )
{
int V_44 , V_45 , V_46 , V_47 , V_48 ;
unsigned char * V_49 ;
V_49 = F_20 ( V_41 ) ;
if ( V_49 ) {
V_44 = F_21 ( V_49 , V_42 , & V_43 [ 2 ] , & V_43 [ 0 ] , & V_43 [ 1 ] ) ;
F_22 ( V_49 ) ;
if ( V_44 != - 1 )
return V_44 ;
}
V_48 = V_42 ;
V_45 = 64 ;
V_46 = 32 ;
V_47 = V_48 / ( V_45 * V_46 ) ;
if ( V_47 > 1024 ) {
V_45 = 255 ;
V_46 = 63 ;
V_47 = V_48 / ( V_45 * V_46 ) ;
}
V_43 [ 0 ] = V_45 ;
V_43 [ 1 ] = V_46 ;
V_43 [ 2 ] = V_47 ;
return 0 ;
}
static T_4 F_23 ( struct V_9 * V_10 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2000 ; V_52 ++ ) {
if ( F_12 ( & V_51 -> V_53 ) &
V_54 ) {
F_13 ( V_54 ,
& V_51 -> V_53 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_25 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2000 ; V_52 ++ ) {
if ( F_12 ( V_51 -> V_57 )
& V_58 ) {
F_13 ( V_59 ,
V_51 -> V_57 ) ;
F_13 ( V_60 ,
V_51 -> V_61 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_26 ( struct V_9 * V_62 )
{
struct V_63 T_1 * V_64 = V_62 -> V_28 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2000 ; V_52 ++ ) {
if ( F_12 ( & V_64 -> V_29 )
& V_30 ) {
F_13 ( V_31 ,
& V_64 -> V_32 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static bool F_27 ( struct V_9 * V_62 )
{
struct V_65 * V_51 = V_62 -> V_66 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2000 ; V_52 ++ ) {
if ( F_12 ( V_51 -> V_29 )
& V_67 ) {
F_13 ( V_67 ,
V_51 -> V_29 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
int V_68 = 30 ;
F_13 ( V_69 , & V_51 -> V_70 ) ;
do {
if ( F_23 ( V_10 ) )
break;
else {
V_68 -- ;
F_9 ( V_22 L_3 , V_10 -> V_23 -> V_24 , V_68 ) ;
}
} while ( V_68 != 0 );
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
int V_68 = 30 ;
F_13 ( V_71 , V_51 -> V_61 ) ;
do {
if ( F_25 ( V_10 ) )
break;
else {
V_68 -- ;
F_9 ( V_22 L_4 , V_10 -> V_23 -> V_24 , V_68 ) ;
}
} while ( V_68 != 0 );
}
static void F_30 ( struct V_9 * V_62 )
{
struct V_63 T_1 * V_51 = V_62 -> V_28 ;
int V_68 = 30 ;
F_13 ( V_69 , & V_51 -> V_70 ) ;
F_13 ( V_72 , & V_51 -> V_73 ) ;
do {
if ( F_26 ( V_62 ) ) {
break;
} else {
V_68 -- ;
F_9 ( V_22 L_4 , V_62 -> V_23 -> V_24 , V_68 ) ;
}
} while ( V_68 != 0 );
return;
}
static void F_31 ( struct V_9 * V_62 )
{
int V_68 = 15 ;
struct V_65 * V_51 = V_62 -> V_66 ;
F_13 ( V_69 , V_51 -> V_70 ) ;
do {
if ( F_27 ( V_62 ) )
break;
V_68 -- ;
F_15 ( L_5
L_6 ,
V_62 -> V_23 -> V_24 , V_68 ) ;
} while ( V_68 != 0 );
}
static void F_32 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 : {
F_28 ( V_10 ) ;
}
break;
case V_12 : {
F_29 ( V_10 ) ;
}
break;
case V_27 : {
F_30 ( V_10 ) ;
}
break;
case V_13 :
F_31 ( V_10 ) ;
break;
}
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_19 * V_14 = V_10 -> V_14 ;
void * V_74 ;
T_5 V_75 ;
struct V_76 * V_77 ;
int V_52 = 0 , V_78 = 0 ;
T_5 V_79 ;
unsigned long V_16 ;
unsigned long V_80 ;
unsigned long V_81 ;
T_6 V_82 ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ )
for ( V_78 = 0 ; V_78 < V_84 ; V_78 ++ )
V_10 -> V_85 [ V_52 ] [ V_78 ] = V_86 ;
V_80 = V_87 ;
V_81 = V_88 ;
V_82 = V_10 -> V_89 ;
if( ( V_82 & 0xFF ) >= 3 ) {
V_80 = ( V_90 << ( ( V_82 >> 8 ) & 0xFF ) ) * 1024 ;
V_81 = ( V_80 / 4096 ) ;
}
V_10 -> V_23 -> V_91 = V_80 / 512 ;
V_10 -> V_23 -> V_92 = V_81 ;
V_16 = F_34 ( sizeof( struct V_76 ) + ( V_81 - 1 ) * sizeof( struct V_93 ) , 32 ) ;
V_10 -> V_94 = V_16 * V_95 ;
V_74 = F_35 ( & V_14 -> V_15 , V_10 -> V_94 , & V_75 , V_96 ) ;
if( ! V_74 ) {
F_9 ( V_22 L_7 , V_10 -> V_23 -> V_24 ) ;
return - V_97 ;
}
V_10 -> V_74 = V_74 ;
V_10 -> V_75 = V_75 ;
memset ( V_74 , 0 , V_10 -> V_94 ) ;
V_77 = V_74 ;
V_10 -> V_98 = ( unsigned long ) V_74 - ( unsigned long ) V_75 ;
for( V_52 = 0 ; V_52 < V_95 ; V_52 ++ ) {
V_79 = V_75 + F_36 ( struct V_76 , V_99 ) ;
switch ( V_10 -> V_11 ) {
case V_20 :
case V_12 :
V_77 -> V_79 = V_79 >> 5 ;
break;
case V_27 :
case V_13 :
V_77 -> V_79 = V_79 ;
break;
}
V_10 -> V_100 [ V_52 ] = V_77 ;
V_77 -> V_10 = V_10 ;
F_37 ( & V_77 -> V_101 ) ;
F_38 ( & V_77 -> V_101 , & V_10 -> V_102 ) ;
V_77 = (struct V_76 * ) ( ( unsigned long ) V_77 + V_16 ) ;
V_75 = V_75 + V_16 ;
}
return 0 ;
}
static void F_39 ( struct V_103 * V_104 )
{
struct V_9 * V_10 = F_40 ( V_104 ,
struct V_9 , V_105 ) ;
char * V_106 = ( char * ) V_10 -> V_107 ;
T_6 T_1 * V_108 = NULL ;
char T_1 * V_109 = NULL ;
int V_110 , V_111 ;
struct V_1 * V_112 ;
char V_113 , V_114 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_108 = ( T_6 T_1 * ) ( & V_51 -> V_115 [ 0 ] ) ;
V_109 = ( char T_1 * ) ( & V_51 -> V_115 [ 21 ] ) ;
break;
}
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
V_108 = ( T_6 T_1 * ) ( & V_51 -> V_115 [ 0 ] ) ;
V_109 = ( char T_1 * ) ( & V_51 -> V_115 [ 21 ] ) ;
break;
}
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
V_108 = ( T_6 T_1 * ) ( & V_51 -> V_116 [ 0 ] ) ;
V_109 = ( char T_1 * ) ( & V_51 -> V_116 [ 21 ] ) ;
break;
}
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
V_108 = ( T_6 T_1 * ) ( & V_51 -> V_116 [ 0 ] ) ;
V_109 = ( char T_1 * ) ( & V_51 -> V_116 [ 21 ] ) ;
break;
}
}
F_41 ( & V_10 -> V_117 ) ;
if ( F_12 ( V_108 ) != V_118 )
return;
for ( V_110 = 0 ; V_110 < V_83 - 1 ;
V_110 ++ ) {
V_114 = F_42 ( V_109 ) ;
V_113 = ( * V_106 ) ^ V_114 ;
if ( V_113 != 0 ) {
* V_106 = V_114 ;
for ( V_111 = 0 ; V_111 < V_84 ;
V_111 ++ ) {
if ( ( V_113 & 0x01 ) == 1 &&
( V_114 & 0x01 ) == 1 ) {
F_43 ( V_10 -> V_23 ,
0 , V_110 , V_111 ) ;
} else if ( ( V_113 & 0x01 ) == 1
&& ( V_114 & 0x01 ) == 0 ) {
V_112 = F_44 ( V_10 -> V_23 ,
0 , V_110 , V_111 ) ;
if ( V_112 != NULL ) {
F_45 ( V_112 ) ;
F_46 ( V_112 ) ;
}
}
V_114 >>= 1 ;
V_113 >>= 1 ;
}
}
V_109 ++ ;
V_106 ++ ;
}
}
static int
F_47 ( struct V_19 * V_14 , struct V_9 * V_10 )
{
int V_52 , V_78 , V_119 ;
struct V_120 V_121 [ V_122 ] ;
for ( V_52 = 0 ; V_52 < V_122 ; V_52 ++ )
V_121 [ V_52 ] . V_123 = V_52 ;
V_119 = F_48 ( V_14 , V_121 , 1 , V_122 ) ;
if ( V_119 < 0 )
goto V_124;
V_10 -> V_125 = V_119 ;
for ( V_52 = 0 ; V_52 < V_119 ; V_52 ++ ) {
if ( F_49 ( V_121 [ V_52 ] . V_126 ,
F_17 , 0 , L_8 , V_10 ) ) {
F_50 ( L_9 ,
V_10 -> V_23 -> V_24 , V_121 [ V_52 ] . V_126 ) ;
for ( V_78 = 0 ; V_78 < V_52 ; V_78 ++ )
F_51 ( V_121 [ V_78 ] . V_126 , V_10 ) ;
F_52 ( V_14 ) ;
goto V_124;
}
V_10 -> V_121 [ V_52 ] = V_121 [ V_52 ] ;
}
V_10 -> V_127 |= V_128 ;
F_53 ( L_10 , V_10 -> V_23 -> V_24 ) ;
return V_129 ;
V_124:
if ( F_54 ( V_14 , 1 ) < 0 )
goto V_130;
if ( F_49 ( V_14 -> V_37 , F_17 ,
V_131 , L_8 , V_10 ) ) {
F_50 ( L_9 ,
V_10 -> V_23 -> V_24 , V_14 -> V_37 ) ;
F_55 ( V_14 ) ;
goto V_130;
}
V_10 -> V_127 |= V_132 ;
F_53 ( L_11 , V_10 -> V_23 -> V_24 ) ;
return V_129 ;
V_130:
if ( F_49 ( V_14 -> V_37 , F_17 ,
V_131 , L_8 , V_10 ) ) {
F_50 ( L_12 ,
V_10 -> V_23 -> V_24 , V_14 -> V_37 ) ;
return V_133 ;
}
return V_129 ;
}
static int F_56 ( struct V_19 * V_14 , const struct V_134 * V_135 )
{
struct V_136 * V_23 ;
struct V_9 * V_10 ;
T_4 V_137 , V_138 ;
int error ;
error = F_57 ( V_14 ) ;
if( error ) {
return - V_139 ;
}
V_23 = F_58 ( & V_140 , sizeof( struct V_9 ) ) ;
if( ! V_23 ) {
goto V_141;
}
error = F_59 ( V_14 , F_60 ( 64 ) ) ;
if( error ) {
error = F_59 ( V_14 , F_60 ( 32 ) ) ;
if( error ) {
F_9 ( V_142
L_13 ,
V_23 -> V_24 ) ;
goto V_143;
}
}
F_61 ( & V_144 ) ;
V_137 = V_14 -> V_137 -> V_145 ;
V_138 = V_14 -> V_146 ;
V_10 = (struct V_9 * ) V_23 -> V_147 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_23 = V_23 ;
V_23 -> V_148 = V_84 ;
V_23 -> V_149 = V_83 ;
V_23 -> V_150 = 16 ;
V_23 -> V_151 = V_152 ;
V_23 -> V_153 = V_7 ;
V_23 -> V_154 = V_155 ;
V_23 -> V_156 = ( V_137 << 8 ) | V_138 ;
F_62 ( V_14 , V_23 ) ;
F_63 ( V_14 ) ;
error = F_64 ( V_14 , L_8 ) ;
if( error ) {
goto V_143;
}
F_65 ( & V_10 -> V_157 ) ;
F_65 ( & V_10 -> V_158 ) ;
F_65 ( & V_10 -> V_159 ) ;
F_65 ( & V_10 -> V_160 ) ;
F_65 ( & V_10 -> V_161 ) ;
F_65 ( & V_10 -> V_162 ) ;
V_10 -> V_127 |= ( V_163 |
V_164 |
V_165 ) ;
V_10 -> V_127 &= ~ V_166 ;
F_37 ( & V_10 -> V_102 ) ;
V_10 -> V_11 = V_135 -> V_167 ;
error = F_5 ( V_10 ) ;
if( ! error ) {
goto V_168;
}
error = F_66 ( V_10 ) ;
if( ! error ) {
goto V_169;
}
error = F_33 ( V_10 ) ;
if( error ) {
goto V_170;
}
error = F_67 ( V_23 , & V_14 -> V_15 ) ;
if( error ) {
goto V_171;
}
if ( F_47 ( V_14 , V_10 ) == V_133 )
goto V_172;
F_68 ( V_10 ) ;
F_69 ( & V_10 -> V_105 , F_39 ) ;
F_70 ( & V_10 -> V_117 , 16 ) ;
F_70 ( & V_10 -> V_173 , 16 ) ;
V_10 -> V_174 = V_175 ;
F_71 ( & V_10 -> V_176 ) ;
V_10 -> V_176 . V_177 = V_178 + F_72 ( 6 * V_179 ) ;
V_10 -> V_176 . V_180 = ( unsigned long ) V_10 ;
V_10 -> V_176 . V_181 = & V_182 ;
F_73 ( & V_10 -> V_176 ) ;
if( F_74 ( V_10 ) )
goto V_183;
F_75 ( V_23 ) ;
return 0 ;
V_183:
F_76 ( & V_10 -> V_176 ) ;
F_77 ( & V_10 -> V_105 ) ;
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
F_79 ( V_14 , V_10 ) ;
V_172:
F_80 ( V_23 ) ;
V_171:
F_81 ( V_10 ) ;
V_170:
F_3 ( V_10 ) ;
V_169:
F_16 ( V_10 ) ;
V_168:
F_82 ( V_14 ) ;
V_143:
F_83 ( V_23 ) ;
V_141:
F_84 ( V_14 ) ;
return - V_139 ;
}
static void F_79 ( struct V_19 * V_14 ,
struct V_9 * V_10 )
{
int V_52 ;
if ( V_10 -> V_127 & V_132 ) {
F_51 ( V_14 -> V_37 , V_10 ) ;
F_55 ( V_14 ) ;
} else if ( V_10 -> V_127 & V_128 ) {
for ( V_52 = 0 ; V_52 < V_10 -> V_125 ; V_52 ++ )
F_51 ( V_10 -> V_121 [ V_52 ] . V_126 , V_10 ) ;
F_52 ( V_14 ) ;
} else
F_51 ( V_14 -> V_37 , V_10 ) ;
}
static int F_85 ( struct V_19 * V_14 , T_7 V_184 )
{
T_6 V_185 ;
struct V_136 * V_23 = F_86 ( V_14 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_147 ;
V_185 = F_87 ( V_10 ) ;
F_79 ( V_14 , V_10 ) ;
F_76 ( & V_10 -> V_176 ) ;
F_77 ( & V_10 -> V_105 ) ;
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
F_62 ( V_14 , V_23 ) ;
F_88 ( V_14 ) ;
F_84 ( V_14 ) ;
F_89 ( V_14 , F_90 ( V_14 , V_184 ) ) ;
return 0 ;
}
static int F_91 ( struct V_19 * V_14 )
{
int error ;
struct V_136 * V_23 = F_86 ( V_14 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_147 ;
F_89 ( V_14 , V_186 ) ;
F_92 ( V_14 , V_186 , 0 ) ;
F_93 ( V_14 ) ;
if ( F_57 ( V_14 ) ) {
F_50 ( L_14 , V_187 ) ;
return - V_139 ;
}
error = F_59 ( V_14 , F_60 ( 64 ) ) ;
if ( error ) {
error = F_59 ( V_14 , F_60 ( 32 ) ) ;
if ( error ) {
F_50 ( L_13 ,
V_23 -> V_24 ) ;
goto V_188;
}
}
F_63 ( V_14 ) ;
if ( F_47 ( V_14 , V_10 ) == V_133 )
goto V_189;
F_68 ( V_10 ) ;
F_69 ( & V_10 -> V_105 , F_39 ) ;
F_70 ( & V_10 -> V_117 , 16 ) ;
F_70 ( & V_10 -> V_173 , 16 ) ;
V_10 -> V_174 = V_175 ;
F_71 ( & V_10 -> V_176 ) ;
V_10 -> V_176 . V_177 = V_178 + F_72 ( 6 * V_179 ) ;
V_10 -> V_176 . V_180 = ( unsigned long ) V_10 ;
V_10 -> V_176 . V_181 = & V_182 ;
F_73 ( & V_10 -> V_176 ) ;
return 0 ;
V_189:
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
V_188:
F_80 ( V_23 ) ;
F_81 ( V_10 ) ;
F_16 ( V_10 ) ;
F_82 ( V_14 ) ;
F_83 ( V_23 ) ;
F_84 ( V_14 ) ;
return - V_139 ;
}
static T_4 F_94 ( struct V_9 * V_10 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
F_13 ( V_190 , & V_51 -> V_70 ) ;
if ( ! F_23 ( V_10 ) ) {
F_9 ( V_22
L_15
, V_10 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_4 F_95 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
F_13 ( V_191 , V_51 -> V_61 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22
L_15
, V_10 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_4 F_96 ( struct V_9 * V_62 )
{
struct V_63 T_1 * V_51 = V_62 -> V_28 ;
F_13 ( V_190 , & V_51 -> V_70 ) ;
F_13 ( V_72 , & V_51 -> V_73 ) ;
if ( ! F_26 ( V_62 ) ) {
F_9 ( V_22
L_15
, V_62 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_4 F_97 ( struct V_9 * V_62 )
{
struct V_65 * V_51 = V_62 -> V_66 ;
F_13 ( V_190 , V_51 -> V_70 ) ;
if ( ! F_27 ( V_62 ) ) {
F_15 ( L_16
L_17 , V_62 -> V_23 -> V_24 ) ;
return false ;
}
return true ;
}
static T_4 F_98 ( struct V_9 * V_10 )
{
T_4 V_192 = 0 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
V_192 = F_94 ( V_10 ) ;
}
break;
case V_12 : {
V_192 = F_95 ( V_10 ) ;
}
break;
case V_27 : {
V_192 = F_96 ( V_10 ) ;
}
break;
case V_13 :
V_192 = F_97 ( V_10 ) ;
break;
}
return V_192 ;
}
static void F_99 ( struct V_76 * V_193 )
{
struct V_194 * V_195 = V_193 -> V_195 ;
F_100 ( V_195 ) ;
}
static void F_101 ( struct V_76 * V_193 )
{
struct V_9 * V_10 = V_193 -> V_10 ;
struct V_194 * V_195 = V_193 -> V_195 ;
unsigned long V_35 ;
F_102 ( & V_10 -> V_196 ) ;
F_99 ( V_193 ) ;
V_193 -> V_197 = V_198 ;
F_103 ( & V_10 -> V_158 , V_35 ) ;
F_38 ( & V_193 -> V_101 , & V_10 -> V_102 ) ;
F_104 ( & V_10 -> V_158 , V_35 ) ;
V_195 -> V_199 ( V_195 ) ;
}
static void F_105 ( struct V_76 * V_193 )
{
struct V_194 * V_195 = V_193 -> V_195 ;
struct V_200 * V_201 = (struct V_200 * ) V_195 -> V_202 ;
V_195 -> V_203 = V_204 << 16 ;
if ( V_201 ) {
int V_205 =
sizeof( struct V_200 ) < V_206
? sizeof( struct V_200 ) : V_206 ;
memset ( V_201 , 0 , V_206 ) ;
memcpy ( V_201 , V_193 -> V_99 . V_207 , V_205 ) ;
V_201 -> V_208 = V_209 ;
V_201 -> V_210 = 1 ;
}
}
static T_8 F_87 ( struct V_9 * V_10 )
{
T_8 V_211 = 0 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_211 = F_12 ( & V_51 -> V_212 ) ;
F_13 ( V_211 | V_213 , \
& V_51 -> V_212 ) ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
V_211 = F_12 ( V_51 -> V_214 ) ;
F_13 ( 0 , V_51 -> V_214 ) ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
V_211 = F_12 ( & V_51 -> V_215 ) ;
F_13 ( V_211 | V_216 , & V_51 -> V_215 ) ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
F_13 ( V_217 , V_51 -> V_218 ) ;
}
break;
}
return V_211 ;
}
static void F_106 ( struct V_9 * V_10 ,
struct V_76 * V_193 , bool error )
{
T_4 V_135 , V_111 ;
V_135 = V_193 -> V_195 -> V_219 -> V_135 ;
V_111 = V_193 -> V_195 -> V_219 -> V_111 ;
if ( ! error ) {
if ( V_10 -> V_85 [ V_135 ] [ V_111 ] == V_86 )
V_10 -> V_85 [ V_135 ] [ V_111 ] = V_220 ;
V_193 -> V_195 -> V_203 = V_204 << 16 ;
F_101 ( V_193 ) ;
} else{
switch ( V_193 -> V_99 . V_221 ) {
case V_222 : {
V_10 -> V_85 [ V_135 ] [ V_111 ] = V_86 ;
V_193 -> V_195 -> V_203 = V_223 << 16 ;
F_101 ( V_193 ) ;
}
break;
case V_224 :
case V_225 : {
V_10 -> V_85 [ V_135 ] [ V_111 ] = V_86 ;
V_193 -> V_195 -> V_203 = V_226 << 16 ;
F_101 ( V_193 ) ;
}
break;
case V_227 : {
V_10 -> V_85 [ V_135 ] [ V_111 ] = V_220 ;
F_105 ( V_193 ) ;
F_101 ( V_193 ) ;
}
break;
default:
F_9 ( V_22
L_18
, V_10 -> V_23 -> V_24
, V_135
, V_111
, V_193 -> V_99 . V_221 ) ;
V_10 -> V_85 [ V_135 ] [ V_111 ] = V_86 ;
V_193 -> V_195 -> V_203 = V_223 << 16 ;
F_101 ( V_193 ) ;
break;
}
}
}
static void F_107 ( struct V_9 * V_10 , struct V_76 * V_228 , bool error )
{
int V_135 , V_111 ;
if ( ( V_228 -> V_10 != V_10 ) || ( V_228 -> V_197 != V_229 ) ) {
if ( V_228 -> V_197 == V_230 ) {
struct V_194 * V_231 = V_228 -> V_195 ;
if ( V_231 ) {
V_135 = V_231 -> V_219 -> V_135 ;
V_111 = V_231 -> V_219 -> V_111 ;
V_231 -> V_203 |= V_232 << 16 ;
F_101 ( V_228 ) ;
F_9 ( V_22 L_19 ,
V_10 -> V_23 -> V_24 , V_228 ) ;
}
return;
}
F_9 ( V_22 L_20
L_21
L_22
, V_10 -> V_23 -> V_24
, V_10
, V_228
, V_228 -> V_10
, V_228 -> V_197
, F_108 ( & V_10 -> V_196 ) ) ;
return;
}
F_106 ( V_10 , V_228 , error ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
int V_52 = 0 ;
T_6 V_233 , V_234 ;
struct V_235 * V_236 ;
bool error ;
struct V_76 * V_228 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
T_6 V_53 ;
V_53 = F_12 ( & V_51 -> V_53 ) &
V_10 -> V_237 ;
F_13 ( V_53 , & V_51 -> V_53 ) ;
while( ( ( V_233 = F_12 ( & V_51 -> V_238 ) ) != 0xFFFFFFFF )
&& ( V_52 ++ < V_152 ) ) {
V_236 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_228 = F_40 ( V_236 , struct V_76 , V_99 ) ;
error = ( V_233 & V_239 ) ? true : false ;
F_107 ( V_10 , V_228 , error ) ;
}
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
F_13 ( V_240 , V_51 -> V_57 ) ;
for ( V_52 = 0 ; V_52 < V_241 ; V_52 ++ ) {
V_233 = V_51 -> V_242 [ V_52 ] ;
if ( V_233 != 0 ) {
V_51 -> V_242 [ V_52 ] = 0 ;
V_236 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_228 = F_40 ( V_236 , struct V_76 , V_99 ) ;
error = ( V_233 & V_239 ) ? true : false ;
F_107 ( V_10 , V_228 , error ) ;
}
V_51 -> V_243 [ V_52 ] = 0 ;
}
V_51 -> V_244 = 0 ;
V_51 -> V_245 = 0 ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
while ( ( F_12 ( & V_51 -> V_246 ) & V_247 ) && ( V_52 ++ < V_152 ) ) {
V_233 = F_12 ( & V_51 -> V_248 ) ;
V_234 = ( V_233 & 0xFFFFFFF0 ) ;
V_236 = (struct V_235 * ) ( V_10 -> V_98 + V_234 ) ;
V_228 = F_40 ( V_236 , struct V_76 , V_99 ) ;
error = ( V_233 & V_249 ) ? true : false ;
F_107 ( V_10 , V_228 , error ) ;
}
}
break;
case V_13 : {
struct V_65 * V_250 = V_10 -> V_66 ;
T_6 V_251 ;
T_6 V_244 , V_252 , V_253 , V_254 , V_255 ;
unsigned long V_35 ;
V_254 = F_108 ( & V_10 -> V_196 ) ;
for ( V_52 = 0 ; V_52 < V_254 ; V_52 ++ ) {
F_103 ( & V_10 -> V_160 , V_35 ) ;
V_251 =
V_250 -> V_242 [ 0 ] . V_253 + 1 ;
V_244 = V_250 -> V_244 ;
if ( ( V_244 & 0xFFF ) !=
( V_251 & 0xFFF ) ) {
V_255 = V_244 & 0x4000 ;
V_252 = ( V_244 & 0xFFF ) + 1 ;
V_252 %= V_256 ;
V_250 -> V_244 = V_252 ? ( V_252 | V_255 ) :
( ( V_255 ^ 0x4000 ) + 1 ) ;
V_244 = V_250 -> V_244 ;
F_104 ( & V_10 -> V_160 , V_35 ) ;
V_253 = V_250 -> V_242 [ V_244 &
0xFFF ] . V_253 ;
V_234 = ( V_253 & 0xFFFFFFF0 ) ;
V_236 = (struct V_235 * )
( V_10 -> V_98 + V_234 ) ;
V_228 = F_40 ( V_236 ,
struct V_76 , V_99 ) ;
error = ( V_253 &
V_249 ) ?
true : false ;
F_107 ( V_10 , V_228 , error ) ;
F_13 ( V_244 ,
V_250 -> V_257 ) ;
} else {
F_104 ( & V_10 -> V_160 , V_35 ) ;
F_110 ( 10 ) ;
}
}
V_250 -> V_245 = 0 ;
V_250 -> V_244 = 0x40FF ;
}
break;
}
}
static void F_111 ( struct V_19 * V_14 )
{
struct V_136 * V_23 = F_86 ( V_14 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_147 ;
int V_258 = 0 ;
F_112 ( V_10 ) ;
F_80 ( V_23 ) ;
F_77 ( & V_10 -> V_105 ) ;
F_76 ( & V_10 -> V_176 ) ;
F_87 ( V_10 ) ;
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
V_10 -> V_127 |= V_166 ;
V_10 -> V_127 &= ~ V_259 ;
for ( V_258 = 0 ; V_258 < V_152 ; V_258 ++ ) {
if ( ! F_108 ( & V_10 -> V_196 ) )
break;
F_18 ( V_10 ) ;
F_24 ( 25 ) ;
}
if ( F_108 ( & V_10 -> V_196 ) ) {
int V_52 ;
F_98 ( V_10 ) ;
F_109 ( V_10 ) ;
for ( V_52 = 0 ; V_52 < V_95 ; V_52 ++ ) {
struct V_76 * V_193 = V_10 -> V_100 [ V_52 ] ;
if ( V_193 -> V_197 == V_229 ) {
V_193 -> V_197 = V_230 ;
V_193 -> V_195 -> V_203 = V_232 << 16 ;
F_101 ( V_193 ) ;
}
}
}
F_79 ( V_14 , V_10 ) ;
F_81 ( V_10 ) ;
F_3 ( V_10 ) ;
F_16 ( V_10 ) ;
F_82 ( V_14 ) ;
F_83 ( V_23 ) ;
F_84 ( V_14 ) ;
}
static void F_113 ( struct V_19 * V_14 )
{
struct V_136 * V_23 = F_86 ( V_14 ) ;
struct V_9 * V_10 =
(struct V_9 * ) V_23 -> V_147 ;
F_76 ( & V_10 -> V_176 ) ;
F_87 ( V_10 ) ;
F_79 ( V_14 , V_10 ) ;
F_77 ( & V_10 -> V_105 ) ;
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
}
static int F_114 ( void )
{
int error = 0 ;
error = F_115 ( & V_260 ) ;
return error ;
}
static void F_116 ( void )
{
F_117 ( & V_260 ) ;
}
static void F_118 ( struct V_9 * V_10 ,
T_8 V_185 )
{
T_8 V_261 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_261 = V_185 & ~ ( V_262 |
V_263 |
V_264 ) ;
F_13 ( V_261 , & V_51 -> V_212 ) ;
V_10 -> V_237 = ~ ( V_185 & V_261 ) & 0x000000ff ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
V_261 = V_185 | ( V_265 |
V_266 |
V_267 |
V_58 ) ;
F_13 ( V_261 , V_51 -> V_214 ) ;
V_10 -> V_237 = ( V_185 | V_261 ) & 0x0000000f ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
V_261 = ~ ( V_268 | V_269 | V_270 ) ;
F_13 ( V_185 & V_261 , & V_51 -> V_215 ) ;
V_10 -> V_237 = ~ ( V_185 & V_261 ) & 0x0000000f ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
V_261 = V_271 ;
F_13 ( V_185 | V_261 , V_51 -> V_218 ) ;
break;
}
}
}
static int F_119 ( struct V_9 * V_10 ,
struct V_76 * V_193 , struct V_194 * V_195 )
{
struct V_235 * V_99 = (struct V_235 * ) & V_193 -> V_99 ;
T_9 * V_272 = ( T_9 * ) & V_99 -> V_273 ;
T_10 V_274 , V_275 ;
int V_276 = 0x30 ;
T_10 V_277 = 0 ;
int V_52 ;
struct V_278 * V_279 ;
int V_280 ;
V_193 -> V_195 = V_195 ;
memset ( V_99 , 0 , sizeof( struct V_235 ) ) ;
V_99 -> V_281 = V_195 -> V_219 -> V_135 ;
V_99 -> V_282 = V_195 -> V_219 -> V_111 ;
V_99 -> V_283 = 1 ;
V_99 -> V_284 = 0 ;
memcpy ( V_99 -> V_285 , V_195 -> V_286 , V_195 -> V_287 ) ;
V_280 = F_120 ( V_195 ) ;
if ( F_121 ( V_280 > V_10 -> V_23 -> V_92 || V_280 < 0 ) )
return V_133 ;
F_122 (pcmd, sg, nseg, i) {
V_277 = F_123 ( F_124 ( V_279 ) ) ;
V_274 = F_123 ( F_125 ( F_126 ( V_279 ) ) ) ;
V_275 = F_123 ( F_127 ( F_126 ( V_279 ) ) ) ;
if ( V_275 == 0 ) {
struct V_288 * V_289 = (struct V_288 * ) V_272 ;
V_289 -> V_290 = V_274 ;
V_289 -> V_277 = V_277 ;
V_272 += sizeof ( struct V_288 ) ;
V_276 += sizeof ( struct V_288 ) ;
} else {
struct V_93 * V_289 = (struct V_93 * ) V_272 ;
V_289 -> V_291 = V_275 ;
V_289 -> V_290 = V_274 ;
V_289 -> V_277 = V_277 | F_123 ( V_292 ) ;
V_272 += sizeof ( struct V_93 ) ;
V_276 += sizeof ( struct V_93 ) ;
}
}
V_99 -> V_293 = ( T_4 ) V_280 ;
V_99 -> V_294 = F_128 ( V_195 ) ;
V_99 -> V_295 = V_276 / 0x100 + ( V_276 % 0x100 ? 1 : 0 ) ;
if ( V_276 > 256 )
V_99 -> V_296 |= V_297 ;
if ( V_195 -> V_298 == V_299 )
V_99 -> V_296 |= V_300 ;
V_193 -> V_301 = V_276 ;
return V_129 ;
}
static void F_129 ( struct V_9 * V_10 , struct V_76 * V_193 )
{
T_6 V_79 = V_193 -> V_79 ;
struct V_235 * V_99 = (struct V_235 * ) & V_193 -> V_99 ;
F_41 ( & V_10 -> V_196 ) ;
V_193 -> V_197 = V_229 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
if ( V_99 -> V_296 & V_297 )
F_13 ( V_79 | V_302 ,
& V_51 -> V_303 ) ;
else
F_13 ( V_79 , & V_51 -> V_303 ) ;
break;
}
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
T_6 V_304 , V_305 = V_51 -> V_245 ;
V_304 = ( ( V_305 + 1 ) % V_241 ) ;
V_51 -> V_243 [ V_304 ] = 0 ;
if ( V_99 -> V_296 & V_297 ) {
V_51 -> V_243 [ V_305 ] =
V_79 | V_302 ;
} else {
V_51 -> V_243 [ V_305 ] = V_79 ;
}
V_305 ++ ;
V_305 %= V_241 ;
V_51 -> V_245 = V_305 ;
F_13 ( V_306 , V_51 -> V_61 ) ;
}
break;
case V_27 : {
struct V_63 T_1 * V_64 = V_10 -> V_28 ;
T_6 V_307 , V_301 ;
V_301 = ( V_193 -> V_301 > 0x300 ) ? 0x300 : V_193 -> V_301 ;
V_307 = ( V_79 | ( ( V_301 - 1 ) >> 6 ) | 1 ) ;
if ( V_10 -> V_308 ) {
F_13 ( V_10 -> V_308 , & V_64 -> V_309 ) ;
F_13 ( V_307 , & V_64 -> V_310 ) ;
} else {
F_13 ( V_307 , & V_64 -> V_310 ) ;
}
}
break;
case V_13 : {
struct V_65 * V_250 = V_10 -> V_66 ;
T_11 V_252 ;
T_11 V_245 , V_255 ;
unsigned long V_35 ;
struct V_311 * V_312 ;
F_103 ( & V_10 -> V_159 , V_35 ) ;
V_245 = V_250 -> V_245 ;
V_312 = (struct V_311 * ) & ( V_250 -> V_243 [ V_245 & 0xFF ] ) ;
V_312 -> V_313 = F_127 ( V_79 ) ;
V_312 -> V_253 = F_125 ( V_79 ) ;
V_312 -> V_277 = V_193 -> V_301 >> 2 ;
V_99 -> V_284 = F_125 ( V_79 ) ;
V_255 = V_245 & 0x4000 ;
V_252 = V_245 + 1 ;
V_252 &= ( V_314 - 1 ) ;
V_250 -> V_245 = V_252 ? ( V_252 | V_255 ) :
( V_255 ^ 0x4000 ) ;
F_13 ( V_245 , V_250 -> V_315 ) ;
F_104 ( & V_10 -> V_159 , V_35 ) ;
break;
}
}
}
static void F_130 ( struct V_9 * V_10 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_10 -> V_127 &= ~ V_316 ;
F_13 ( V_317 , & V_51 -> V_70 ) ;
if ( ! F_23 ( V_10 ) ) {
F_9 ( V_22
L_23
, V_10 -> V_23 -> V_24 ) ;
}
}
static void F_131 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
V_10 -> V_127 &= ~ V_316 ;
F_13 ( V_318 , V_51 -> V_61 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22
L_23
, V_10 -> V_23 -> V_24 ) ;
}
}
static void F_132 ( struct V_9 * V_62 )
{
struct V_63 T_1 * V_51 = V_62 -> V_28 ;
V_62 -> V_127 &= ~ V_316 ;
F_13 ( V_317 , & V_51 -> V_70 ) ;
F_13 ( V_72 , & V_51 -> V_73 ) ;
if ( ! F_26 ( V_62 ) ) {
F_9 ( V_22
L_23
, V_62 -> V_23 -> V_24 ) ;
}
return;
}
static void F_133 ( struct V_9 * V_62 )
{
struct V_65 * V_51 = V_62 -> V_66 ;
V_62 -> V_127 &= ~ V_316 ;
F_13 ( V_317 , V_51 -> V_70 ) ;
if ( ! F_27 ( V_62 ) )
F_15 ( L_24
L_25 , V_62 -> V_23 -> V_24 ) ;
}
static void F_78 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 : {
F_130 ( V_10 ) ;
}
break;
case V_12 : {
F_131 ( V_10 ) ;
}
break;
case V_27 : {
F_132 ( V_10 ) ;
}
break;
case V_13 :
F_133 ( V_10 ) ;
break;
}
}
static void F_81 ( struct V_9 * V_10 )
{
F_4 ( & V_10 -> V_14 -> V_15 , V_10 -> V_94 , V_10 -> V_74 , V_10 -> V_75 ) ;
}
static void F_134 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
F_13 ( V_319 , & V_51 -> V_73 ) ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
F_13 ( V_320 , V_51 -> V_61 ) ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
F_13 ( V_321 , & V_51 -> V_73 ) ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
F_13 ( V_322 ,
V_51 -> V_73 ) ;
}
break;
}
}
static void F_135 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
F_13 ( V_323 , & V_51 -> V_73 ) ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
F_13 ( V_324 , V_51 -> V_61 ) ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
F_13 ( V_325 , & V_51 -> V_73 ) ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
F_13 ( V_326 ,
V_51 -> V_73 ) ;
}
break;
}
}
struct V_327 T_1 * F_136 ( struct V_9 * V_10 )
{
struct V_327 T_1 * V_328 = NULL ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_328 = (struct V_327 T_1 * ) & V_51 -> V_329 ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
V_328 = (struct V_327 T_1 * ) V_51 -> V_329 ;
}
break;
case V_27 : {
struct V_63 T_1 * V_64 = V_10 -> V_28 ;
V_328 = (struct V_327 T_1 * ) & V_64 -> V_329 ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
V_328 = (struct V_327 T_1 * ) V_51 -> V_329 ;
}
break;
}
return V_328 ;
}
static struct V_327 T_1 * F_137 ( struct V_9 * V_10 )
{
struct V_327 T_1 * V_330 = NULL ;
switch ( V_10 -> V_11 ) {
case V_20 : {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_330 = (struct V_327 T_1 * ) & V_51 -> V_331 ;
}
break;
case V_12 : {
struct V_55 * V_51 = V_10 -> V_56 ;
V_330 = (struct V_327 T_1 * ) V_51 -> V_331 ;
}
break;
case V_27 : {
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
V_330 = (struct V_327 T_1 * ) & V_51 -> V_331 ;
}
break;
case V_13 : {
struct V_65 * V_51 = V_10 -> V_66 ;
V_330 = (struct V_327 T_1 * ) V_51 -> V_331 ;
}
break;
}
return V_330 ;
}
static T_6
F_138 ( struct V_9 * V_10 ,
struct V_327 T_1 * V_332 )
{
T_4 * V_333 ;
T_4 * V_334 = NULL ;
T_6 T_1 * V_335 ;
T_6 V_336 , V_337 , * V_338 = NULL ;
V_335 = ( T_6 T_1 * ) V_332 -> V_180 ;
V_336 = F_12 ( & V_332 -> V_337 ) ;
if ( V_336 > 0 ) {
V_334 = F_139 ( 128 , V_339 ) ;
V_338 = ( T_6 * ) V_334 ;
if ( V_334 == NULL )
return 0 ;
V_337 = V_336 ;
while ( V_337 >= 4 ) {
* V_338 ++ = F_12 ( V_335 ) ;
V_335 ++ ;
V_337 -= 4 ;
}
if ( V_337 )
* V_338 = F_12 ( V_335 ) ;
V_338 = ( T_6 * ) V_334 ;
}
while ( V_336 > 0 ) {
V_333 = & V_10 -> V_340 [ V_10 -> V_341 ] ;
* V_333 = * V_334 ;
V_10 -> V_341 ++ ;
V_10 -> V_341 %= V_342 ;
V_334 ++ ;
V_336 -- ;
}
F_22 ( V_338 ) ;
F_134 ( V_10 ) ;
return 1 ;
}
T_6
F_140 ( struct V_9 * V_10 ,
struct V_327 T_1 * V_332 ) {
T_4 * V_333 ;
T_4 T_1 * V_335 ;
T_6 V_336 ;
if ( V_10 -> V_11 & ( V_27 | V_13 ) )
return F_138 ( V_10 , V_332 ) ;
V_335 = ( T_4 T_1 * ) V_332 -> V_180 ;
V_336 = F_12 ( & V_332 -> V_337 ) ;
while ( V_336 > 0 ) {
V_333 = & V_10 -> V_340 [ V_10 -> V_341 ] ;
* V_333 = F_42 ( V_335 ) ;
V_10 -> V_341 ++ ;
V_10 -> V_341 %= V_342 ;
V_335 ++ ;
V_336 -- ;
}
F_134 ( V_10 ) ;
return 1 ;
}
static void F_141 ( struct V_9 * V_10 )
{
unsigned long V_35 ;
struct V_327 T_1 * V_332 ;
T_12 V_343 ;
F_103 ( & V_10 -> V_161 , V_35 ) ;
V_332 = F_136 ( V_10 ) ;
V_343 = ( V_10 -> V_341 - V_10 -> V_344 - 1 ) &
( V_342 - 1 ) ;
if ( V_343 >= F_12 ( & V_332 -> V_337 ) ) {
if ( F_140 ( V_10 , V_332 ) == 0 )
V_10 -> V_127 |= V_345 ;
} else
V_10 -> V_127 |= V_345 ;
F_104 ( & V_10 -> V_161 , V_35 ) ;
}
static void F_142 ( struct V_9 * V_10 )
{
T_4 * V_333 ;
struct V_327 T_1 * V_346 ;
T_4 * V_334 = NULL ;
T_6 T_1 * V_335 ;
T_6 V_347 = 0 , V_337 , * V_338 = NULL , V_180 ;
if ( V_10 -> V_127 & V_165 ) {
V_334 = F_139 ( 128 , V_339 ) ;
V_338 = ( T_6 * ) V_334 ;
if ( V_334 == NULL )
return;
V_10 -> V_127 &= ( ~ V_165 ) ;
V_346 = F_137 ( V_10 ) ;
V_335 = ( T_6 T_1 * ) V_346 -> V_180 ;
while ( ( V_10 -> V_348 != V_10 -> V_349 )
&& ( V_347 < 124 ) ) {
V_333 = & V_10 -> V_350 [ V_10 -> V_348 ] ;
* V_334 = * V_333 ;
V_10 -> V_348 ++ ;
V_10 -> V_348 %= V_342 ;
V_334 ++ ;
V_347 ++ ;
}
V_337 = V_347 ;
V_334 = ( T_4 * ) V_338 ;
while ( V_337 >= 4 ) {
V_180 = * V_338 ++ ;
F_13 ( V_180 , V_335 ) ;
V_335 ++ ;
V_337 -= 4 ;
}
if ( V_337 ) {
V_180 = * V_338 ;
F_13 ( V_180 , V_335 ) ;
}
F_13 ( V_347 , & V_346 -> V_337 ) ;
F_22 ( V_334 ) ;
F_135 ( V_10 ) ;
}
}
void
F_143 ( struct V_9 * V_10 )
{
T_4 * V_333 ;
struct V_327 T_1 * V_346 ;
T_4 T_1 * V_335 ;
T_12 V_347 = 0 ;
if ( V_10 -> V_11 & ( V_27 | V_13 ) ) {
F_142 ( V_10 ) ;
return;
}
if ( V_10 -> V_127 & V_165 ) {
V_10 -> V_127 &= ( ~ V_165 ) ;
V_346 = F_137 ( V_10 ) ;
V_335 = ( T_4 T_1 * ) V_346 -> V_180 ;
while ( ( V_10 -> V_348 != V_10 -> V_349 )
&& ( V_347 < 124 ) ) {
V_333 = & V_10 -> V_350 [ V_10 -> V_348 ] ;
F_144 ( * V_333 , V_335 ) ;
V_10 -> V_348 ++ ;
V_10 -> V_348 %= V_342 ;
V_335 ++ ;
V_347 ++ ;
}
F_13 ( V_347 , & V_346 -> V_337 ) ;
F_135 ( V_10 ) ;
}
}
static void F_145 ( struct V_9 * V_10 )
{
unsigned long V_35 ;
F_103 ( & V_10 -> V_162 , V_35 ) ;
V_10 -> V_127 |= V_165 ;
if ( V_10 -> V_348 != V_10 -> V_349 )
F_143 ( V_10 ) ;
if ( V_10 -> V_348 == V_10 -> V_349 )
V_10 -> V_127 |= V_163 ;
F_104 ( & V_10 -> V_162 , V_35 ) ;
}
static void F_146 ( struct V_9 * V_10 )
{
T_6 V_29 ;
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_29 = F_12 ( & V_51 -> V_29 ) ;
do {
F_13 ( V_29 , & V_51 -> V_29 ) ;
if ( V_29 & V_351 )
F_141 ( V_10 ) ;
if ( V_29 & V_352 )
F_145 ( V_10 ) ;
V_29 = F_12 ( & V_51 -> V_29 ) ;
} while ( V_29 & ( V_351
| V_352 ) );
}
static void F_147 ( struct V_9 * V_62 )
{
T_6 V_29 ;
struct V_63 T_1 * V_51 = V_62 -> V_28 ;
V_29 = F_12 ( & V_51 -> V_29 ) ;
do {
F_13 ( V_29 , & V_51 -> V_32 ) ;
F_12 ( & V_51 -> V_32 ) ;
if ( V_29 & V_353 )
F_141 ( V_62 ) ;
if ( V_29 & V_354 )
F_145 ( V_62 ) ;
if ( V_29 & V_30 )
F_148 ( V_62 ) ;
V_29 = F_12 ( & V_51 -> V_29 ) ;
} while ( V_29 & ( V_353
| V_354
| V_30 ) );
}
static void F_149 ( struct V_9 * V_62 )
{
T_6 V_29 ;
struct V_65 * V_250 = V_62 -> V_66 ;
V_29 = F_12 ( V_250 -> V_29 ) ;
do {
F_13 ( V_29 , V_250 -> V_29 ) ;
if ( V_29 & V_67 )
F_150 ( V_62 ) ;
if ( V_29 & V_355 )
F_141 ( V_62 ) ;
if ( V_29 & V_356 )
F_145 ( V_62 ) ;
V_29 = F_12 ( V_250 -> V_29 ) ;
} while ( V_29 & ( V_355
| V_356
| V_67 ) );
}
static void F_151 ( struct V_9 * V_10 )
{
T_6 V_233 ;
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
struct V_235 * V_236 ;
struct V_76 * V_228 ;
bool error ;
while ( ( V_233 = F_12 ( & V_51 -> V_238 ) ) != 0xFFFFFFFF ) {
V_236 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_228 = F_40 ( V_236 , struct V_76 , V_99 ) ;
error = ( V_233 & V_239 ) ? true : false ;
F_107 ( V_10 , V_228 , error ) ;
}
}
static void F_152 ( struct V_9 * V_10 )
{
T_6 V_305 ;
T_6 V_233 ;
struct V_55 * V_51 = V_10 -> V_56 ;
struct V_235 * V_236 ;
struct V_76 * V_228 ;
bool error ;
V_305 = V_51 -> V_244 ;
while ( ( V_233 = V_51 -> V_242 [ V_305 ] ) != 0 ) {
V_51 -> V_242 [ V_305 ] = 0 ;
V_236 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_228 = F_40 ( V_236 , struct V_76 , V_99 ) ;
error = ( V_233 & V_239 ) ? true : false ;
F_107 ( V_10 , V_228 , error ) ;
V_305 ++ ;
V_305 %= V_241 ;
V_51 -> V_244 = V_305 ;
}
}
static void F_153 ( struct V_9 * V_10 )
{
struct V_63 T_1 * V_64 ;
struct V_235 * V_99 ;
struct V_76 * V_193 ;
T_6 V_233 , V_234 , V_357 = 0 ;
int error ;
V_64 = V_10 -> V_28 ;
while ( ( V_233 = F_12 ( & V_64 -> V_248 ) ) !=
0xFFFFFFFF ) {
V_234 = ( V_233 & 0xFFFFFFF0 ) ;
V_99 = (struct V_235 * ) ( V_10 -> V_98
+ V_234 ) ;
V_193 = F_40 ( V_99 , struct V_76 ,
V_99 ) ;
error = ( V_233 & V_249 )
? true : false ;
F_107 ( V_10 , V_193 , error ) ;
V_357 ++ ;
if ( V_357 == V_358 ) {
F_13 ( V_359 ,
& V_64 -> V_73 ) ;
V_357 = 0 ;
}
}
}
static void F_154 ( struct V_9 * V_10 )
{
T_8 V_251 , V_244 , V_252 , V_255 ;
T_6 V_253 , V_234 ;
int error ;
struct V_65 * V_250 ;
struct V_235 * V_99 ;
struct V_76 * V_193 ;
unsigned long V_35 ;
F_103 ( & V_10 -> V_160 , V_35 ) ;
V_250 = V_10 -> V_66 ;
V_251 = V_250 -> V_242 [ 0 ] . V_253 + 1 ;
V_244 = V_250 -> V_244 ;
if ( ( V_244 & 0xFFF ) != ( V_251 & 0xFFF ) ) {
do {
V_255 = V_244 & 0x4000 ;
V_252 = ( V_244 & 0xFFF ) + 1 ;
V_252 %= V_256 ;
V_250 -> V_244 = V_252 ? ( V_252 | V_255 ) :
( ( V_255 ^ 0x4000 ) + 1 ) ;
V_244 = V_250 -> V_244 ;
V_253 = V_250 -> V_242 [ V_244 &
0xFFF ] . V_253 ;
V_234 = ( V_253 & 0xFFFFFFF0 ) ;
V_99 = (struct V_235 * ) ( V_10 -> V_98
+ V_234 ) ;
V_193 = F_40 ( V_99 ,
struct V_76 , V_99 ) ;
error = ( V_253 & V_249 )
? true : false ;
F_107 ( V_10 , V_193 , error ) ;
F_13 ( V_244 , V_250 -> V_257 ) ;
} while ( ( V_244 & 0xFFF ) !=
( V_251 & 0xFFF ) );
}
F_13 ( V_360 ,
V_250 -> V_361 ) ;
F_12 ( V_250 -> V_361 ) ;
F_104 ( & V_10 -> V_160 , V_35 ) ;
}
static void F_155 ( struct V_9 * V_10 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
F_13 ( V_54 , & V_51 -> V_53 ) ;
F_156 ( & V_10 -> V_105 ) ;
}
static void F_157 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
F_13 ( V_59 , V_51 -> V_57 ) ;
F_156 ( & V_10 -> V_105 ) ;
}
static void F_148 ( struct V_9 * V_10 )
{
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
F_13 ( V_31 , & V_51 -> V_32 ) ;
F_156 ( & V_10 -> V_105 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_65 * V_51 = V_10 -> V_66 ;
F_13 ( V_67 , V_51 -> V_29 ) ;
F_12 ( V_51 -> V_29 ) ;
F_156 ( & V_10 -> V_105 ) ;
}
static int F_158 ( struct V_9 * V_10 )
{
T_6 V_53 ;
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
V_53 = F_12 ( & V_51 -> V_53 ) &
V_10 -> V_237 ;
if ( ! ( V_53 & V_362 ) )
return V_363 ;
do {
F_13 ( V_53 , & V_51 -> V_53 ) ;
if ( V_53 & V_364 )
F_146 ( V_10 ) ;
if ( V_53 & V_365 )
F_151 ( V_10 ) ;
if ( V_53 & V_54 )
F_155 ( V_10 ) ;
V_53 = F_12 ( & V_51 -> V_53 ) &
V_10 -> V_237 ;
} while ( V_53 & ( V_364
| V_365
| V_54 ) );
return V_366 ;
}
static int F_159 ( struct V_9 * V_10 )
{
T_6 V_29 ;
struct V_55 * V_51 = V_10 -> V_56 ;
V_29 = F_12 ( V_51 -> V_57 ) &
V_10 -> V_237 ;
if ( ! V_29 )
return V_363 ;
do {
F_13 ( ~ V_29 , V_51 -> V_57 ) ;
F_13 ( V_60 , V_51 -> V_61 ) ;
if ( V_29 & V_265 )
F_141 ( V_10 ) ;
if ( V_29 & V_266 )
F_145 ( V_10 ) ;
if ( V_29 & V_267 )
F_152 ( V_10 ) ;
if ( V_29 & V_58 )
F_157 ( V_10 ) ;
V_29 = F_12 ( V_51 -> V_57 ) &
V_10 -> V_237 ;
} while ( V_29 & ( V_265
| V_266
| V_267
| V_58 ) );
return V_366 ;
}
static int F_160 ( struct V_9 * V_62 )
{
T_6 V_367 ;
struct V_63 T_1 * V_64 = V_62 -> V_28 ;
V_367 = F_12 ( & V_64 -> V_246 ) &
( V_247 |
V_368 ) ;
if ( ! V_367 )
return V_363 ;
do {
if ( V_367 & V_368 )
F_147 ( V_62 ) ;
if ( V_367 & V_247 )
F_153 ( V_62 ) ;
V_367 = F_12 ( & V_64 -> V_246 ) ;
} while ( V_367 & ( V_247 |
V_368 ) );
return V_366 ;
}
static T_2 F_161 ( struct V_9 * V_62 )
{
T_8 V_367 ;
struct V_65 * V_250 = V_62 -> V_66 ;
V_367 = F_12 ( V_250 -> V_246 ) &
( V_369 |
V_370 ) ;
if ( ! V_367 )
return V_363 ;
do {
if ( V_367 &
V_369 )
F_154 ( V_62 ) ;
if ( V_367 &
V_370 )
F_149 ( V_62 ) ;
V_367 = F_12 ( V_250 -> V_246 ) ;
} while ( V_367 &
( V_369 |
V_370 ) );
return V_366 ;
}
static T_2 F_18 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 ) {
case V_20 :
return F_158 ( V_10 ) ;
break;
case V_12 :
return F_159 ( V_10 ) ;
break;
case V_27 :
return F_160 ( V_10 ) ;
case V_13 :
return F_161 ( V_10 ) ;
default:
return V_363 ;
}
}
static void F_162 ( struct V_9 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_127 & V_316 ) {
T_6 V_185 ;
V_10 -> V_127 &= ~ V_316 ;
V_185 = F_87 ( V_10 ) ;
F_78 ( V_10 ) ;
F_32 ( V_10 ) ;
F_118 ( V_10 , V_185 ) ;
}
}
}
void F_163 ( struct V_9 * V_10 )
{
T_6 V_52 ;
if ( V_10 -> V_127 & V_345 ) {
for ( V_52 = 0 ; V_52 < 15 ; V_52 ++ ) {
if ( V_10 -> V_127 & V_345 ) {
V_10 -> V_127 &= ~ V_345 ;
V_10 -> V_344 = 0 ;
V_10 -> V_341 = 0 ;
F_134 ( V_10 ) ;
F_110 ( 30 ) ;
} else if ( V_10 -> V_344 !=
V_10 -> V_341 ) {
V_10 -> V_344 = 0 ;
V_10 -> V_341 = 0 ;
F_110 ( 30 ) ;
} else
break;
}
}
}
static int F_164 ( struct V_9 * V_10 ,
struct V_194 * V_371 )
{
char * V_49 ;
unsigned short V_372 ;
int V_373 = 0 , V_374 = 0 ;
unsigned long V_35 ;
struct V_375 * V_376 ;
T_6 V_377 = ( T_6 ) V_371 -> V_286 [ 5 ] << 24 |
( T_6 ) V_371 -> V_286 [ 6 ] << 16 |
( T_6 ) V_371 -> V_286 [ 7 ] << 8 |
( T_6 ) V_371 -> V_286 [ 8 ] ;
struct V_278 * V_279 ;
V_372 = F_165 ( V_371 ) ;
V_279 = F_166 ( V_371 ) ;
V_49 = F_167 ( F_168 ( V_279 ) ) + V_279 -> V_378 ;
if ( V_372 > 1 ) {
V_373 = V_379 ;
goto V_380;
}
V_374 += V_279 -> V_277 ;
if ( V_374 > sizeof( struct V_375 ) ) {
V_373 = V_379 ;
F_53 ( L_26 , V_187 ) ;
goto V_380;
}
V_376 = (struct V_375 * ) V_49 ;
switch ( V_377 ) {
case V_381 : {
unsigned char * V_382 ;
T_4 * V_383 ;
T_6 V_347 = 0 ;
V_382 = F_139 ( V_384 , V_339 ) ;
if ( ! V_382 ) {
V_373 = V_379 ;
F_53 ( L_27 , V_187 ) ;
goto V_380;
}
V_383 = V_382 ;
F_103 ( & V_10 -> V_161 , V_35 ) ;
if ( V_10 -> V_344 != V_10 -> V_341 ) {
unsigned int V_385 = V_10 -> V_344 ;
unsigned int V_386 = V_10 -> V_341 ;
unsigned int V_387 = F_169 ( V_386 , V_385 , V_342 ) ;
V_347 = F_170 ( V_386 , V_385 , V_342 ) ;
if ( V_347 > V_384 )
V_347 = V_384 ;
if ( V_347 <= V_387 )
memcpy ( V_383 , V_10 -> V_340 + V_385 , V_347 ) ;
else {
memcpy ( V_383 , V_10 -> V_340 + V_385 , V_387 ) ;
memcpy ( V_383 + V_387 , V_10 -> V_340 , V_347 - V_387 ) ;
}
V_10 -> V_344 = ( V_10 -> V_344 + V_347 ) % V_342 ;
}
memcpy ( V_376 -> V_388 , V_382 ,
V_347 ) ;
if ( V_10 -> V_127 & V_345 ) {
struct V_327 T_1 * V_332 ;
V_10 -> V_127 &= ~ V_345 ;
V_332 = F_136 ( V_10 ) ;
if ( F_140 ( V_10 , V_332 ) == 0 )
V_10 -> V_127 |= V_345 ;
}
F_104 ( & V_10 -> V_161 , V_35 ) ;
F_22 ( V_382 ) ;
V_376 -> V_389 . V_390 = V_347 ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
break;
}
case V_395 : {
unsigned char * V_382 ;
T_12 V_396 , V_397 ;
T_4 * V_333 , * V_398 ;
V_382 = F_139 ( V_384 , V_339 ) ;
if ( ! V_382 ) {
V_373 = V_379 ;
goto V_380;
}
V_398 = V_382 ;
V_396 = V_376 -> V_389 . V_390 ;
memcpy ( V_398 ,
V_376 -> V_388 , V_396 ) ;
F_103 ( & V_10 -> V_162 , V_35 ) ;
if ( V_10 -> V_349 != V_10 -> V_348 ) {
struct V_200 * V_201 =
(struct V_200 * ) V_371 -> V_202 ;
F_143 ( V_10 ) ;
V_201 -> V_208 = V_209 ;
V_201 -> V_399 = V_400 ;
V_201 -> V_401 = 0x0A ;
V_201 -> V_402 = 0x20 ;
V_201 -> V_210 = 1 ;
V_373 = V_379 ;
} else {
V_333 = & V_10 -> V_350 [ V_10 -> V_349 ] ;
V_397 = V_342 - V_10 -> V_349 ;
if ( V_396 > V_397 ) {
memcpy ( V_333 , V_398 , V_397 ) ;
V_398 += V_397 ;
V_396 -= V_397 ;
V_10 -> V_349 = 0 ;
V_333 = V_10 -> V_350 ;
}
memcpy ( V_333 , V_398 , V_396 ) ;
V_10 -> V_349 += V_396 ;
V_10 -> V_349 %= V_342 ;
if ( V_10 -> V_127 & V_163 ) {
V_10 -> V_127 &=
~ V_163 ;
F_143 ( V_10 ) ;
}
}
F_104 ( & V_10 -> V_162 , V_35 ) ;
F_22 ( V_382 ) ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
break;
}
case V_403 : {
T_4 * V_333 = V_10 -> V_340 ;
F_163 ( V_10 ) ;
F_103 ( & V_10 -> V_161 , V_35 ) ;
V_10 -> V_127 |= V_164 ;
V_10 -> V_344 = 0 ;
V_10 -> V_341 = 0 ;
memset ( V_333 , 0 , V_342 ) ;
F_104 ( & V_10 -> V_161 , V_35 ) ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
break;
}
case V_404 : {
T_4 * V_333 = V_10 -> V_350 ;
F_103 ( & V_10 -> V_162 , V_35 ) ;
V_10 -> V_127 |= ( V_163 |
V_165 ) ;
V_10 -> V_348 = 0 ;
V_10 -> V_349 = 0 ;
memset ( V_333 , 0 , V_342 ) ;
F_104 ( & V_10 -> V_162 , V_35 ) ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
break;
}
case V_405 : {
T_4 * V_333 ;
F_163 ( V_10 ) ;
F_103 ( & V_10 -> V_161 , V_35 ) ;
V_10 -> V_127 |= V_164 ;
V_10 -> V_344 = 0 ;
V_10 -> V_341 = 0 ;
V_333 = V_10 -> V_340 ;
memset ( V_333 , 0 , sizeof( struct V_327 ) ) ;
F_104 ( & V_10 -> V_161 , V_35 ) ;
F_103 ( & V_10 -> V_162 , V_35 ) ;
V_10 -> V_127 |= ( V_163 |
V_165 ) ;
V_10 -> V_348 = 0 ;
V_10 -> V_349 = 0 ;
V_333 = V_10 -> V_350 ;
memset ( V_333 , 0 , sizeof( struct V_327 ) ) ;
F_104 ( & V_10 -> V_162 , V_35 ) ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
break;
}
case V_406 : {
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_407 ;
break;
}
case V_408 : {
T_9 * V_409 = L_28 ;
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
memcpy ( V_376 -> V_388 ,
V_409 , ( V_410 ) strlen ( V_409 ) ) ;
break;
}
case V_411 : {
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
F_162 ( V_10 ) ;
break;
}
case V_412 : {
if ( V_10 -> V_174 == V_391 )
V_376 -> V_389 . V_392 =
V_393 ;
else
V_376 -> V_389 . V_392 =
V_394 ;
F_32 ( V_10 ) ;
break;
}
default:
V_373 = V_379 ;
F_53 ( L_29 , V_187 ) ;
}
V_380:
if ( V_372 ) {
struct V_278 * V_279 = F_166 ( V_371 ) ;
F_171 ( V_49 - V_279 -> V_378 ) ;
}
return V_373 ;
}
static struct V_76 * F_172 ( struct V_9 * V_10 )
{
struct V_413 * V_386 = & V_10 -> V_102 ;
struct V_76 * V_193 = NULL ;
unsigned long V_35 ;
F_103 ( & V_10 -> V_158 , V_35 ) ;
if ( ! F_173 ( V_386 ) ) {
V_193 = F_174 ( V_386 -> V_414 , struct V_76 , V_101 ) ;
F_175 ( & V_193 -> V_101 ) ;
} else{
F_104 ( & V_10 -> V_158 , V_35 ) ;
return NULL ;
}
F_104 ( & V_10 -> V_158 , V_35 ) ;
return V_193 ;
}
static void F_176 ( struct V_9 * V_10 ,
struct V_194 * V_371 )
{
switch ( V_371 -> V_286 [ 0 ] ) {
case V_415 : {
unsigned char V_416 [ 36 ] ;
char * V_49 ;
struct V_278 * V_279 ;
if ( V_371 -> V_219 -> V_111 ) {
V_371 -> V_203 = ( V_417 << 16 ) ;
V_371 -> V_199 ( V_371 ) ;
return;
}
V_416 [ 0 ] = V_418 ;
V_416 [ 1 ] = 0 ;
V_416 [ 2 ] = 0 ;
V_416 [ 4 ] = 31 ;
strncpy ( & V_416 [ 8 ] , L_30 , 8 ) ;
strncpy ( & V_416 [ 16 ] , L_31 , 16 ) ;
strncpy ( & V_416 [ 32 ] , L_32 , 4 ) ;
V_279 = F_166 ( V_371 ) ;
V_49 = F_167 ( F_168 ( V_279 ) ) + V_279 -> V_378 ;
memcpy ( V_49 , V_416 , sizeof( V_416 ) ) ;
V_279 = F_166 ( V_371 ) ;
F_171 ( V_49 - V_279 -> V_378 ) ;
V_371 -> V_199 ( V_371 ) ;
}
break;
case V_419 :
case V_420 : {
if ( F_164 ( V_10 , V_371 ) )
V_371 -> V_203 = ( V_421 << 16 ) ;
V_371 -> V_199 ( V_371 ) ;
}
break;
default:
V_371 -> V_199 ( V_371 ) ;
}
}
static int F_177 ( struct V_194 * V_371 ,
void (* F_178)( struct V_194 * ) )
{
struct V_136 * V_23 = V_371 -> V_219 -> V_23 ;
struct V_9 * V_10 = (struct V_9 * ) V_23 -> V_147 ;
struct V_76 * V_193 ;
int V_110 = V_371 -> V_219 -> V_135 ;
int V_111 = V_371 -> V_219 -> V_111 ;
T_4 V_422 = V_371 -> V_286 [ 0 ] ;
V_371 -> V_199 = F_178 ;
V_371 -> V_423 = NULL ;
V_371 -> V_203 = 0 ;
if ( ( V_422 == V_424 ) || ( V_422 == V_425 ) ) {
if( V_10 -> V_85 [ V_110 ] [ V_111 ] == V_86 ) {
V_371 -> V_203 = ( V_223 << 16 ) ;
}
V_371 -> V_199 ( V_371 ) ;
return 0 ;
}
if ( V_110 == 16 ) {
F_176 ( V_10 , V_371 ) ;
return 0 ;
}
V_193 = F_172 ( V_10 ) ;
if ( ! V_193 )
return V_426 ;
if ( F_119 ( V_10 , V_193 , V_371 ) == V_133 ) {
V_371 -> V_203 = ( V_421 << 16 ) | ( V_427 << 1 ) ;
V_371 -> V_199 ( V_371 ) ;
return 0 ;
}
F_129 ( V_10 , V_193 ) ;
return 0 ;
}
bool F_179 ( struct V_9 * V_10 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
struct V_19 * V_14 = V_10 -> V_14 ;
void * V_74 ;
T_5 V_75 ;
char * V_428 = V_10 -> V_429 ;
char * V_430 = V_10 -> V_431 ;
char * V_432 = V_10 -> V_107 ;
char T_1 * V_433 ;
char T_1 * V_434 ;
char T_1 * V_435 ;
int V_436 ;
V_10 -> V_16 = F_34 ( sizeof( struct V_55 ) , 32 ) ;
V_74 = F_35 ( & V_14 -> V_15 , V_10 -> V_16 ,
& V_75 , V_96 ) ;
if ( ! V_74 ) {
F_9 ( V_22
L_33 ,
V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_10 -> V_18 = V_75 ;
V_10 -> V_17 = V_74 ;
V_51 = (struct V_55 * ) V_74 ;
V_10 -> V_56 = V_51 ;
V_51 -> V_61 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_437 ) ;
V_51 -> V_438 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_439 ) ;
V_51 -> V_57 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_440 ) ;
V_51 -> V_214 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_25 + V_441 ) ;
V_51 -> V_331 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_442 ) ;
V_51 -> V_329 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_443 ) ;
V_51 -> V_115 = ( T_6 T_1 * ) ( ( unsigned long ) V_10 -> V_26 + V_444 ) ;
V_433 = ( char T_1 * ) ( & V_51 -> V_115 [ 15 ] ) ;
V_434 = ( char T_1 * ) ( & V_51 -> V_115 [ 17 ] ) ;
V_435 = ( char T_1 * ) ( & V_51 -> V_115 [ 21 ] ) ;
F_13 ( V_445 , V_51 -> V_61 ) ;
if ( ! F_25 ( V_10 ) ) {
F_9 ( V_22 L_34 , V_10 -> V_23 -> V_24 ) ;
return false ;
}
V_436 = 8 ;
while ( V_436 ) {
* V_428 = F_42 ( V_433 ) ;
V_428 ++ ;
V_433 ++ ;
V_436 -- ;
}
V_436 = 16 ;
while ( V_436 ) {
* V_430 = F_42 ( V_434 ) ;
V_430 ++ ;
V_434 ++ ;
V_436 -- ;
}
V_436 = 16 ;
while( V_436 ) {
* V_432 = F_42 ( V_435 ) ;
V_432 ++ ;
V_435 ++ ;
V_436 -- ;
}
F_15 ( L_35 ,
V_10 -> V_23 -> V_24 ,
V_10 -> V_429 ,
V_10 -> V_431 ) ;
V_10 -> V_108 = F_12 ( & V_51 -> V_115 [ 1 ] ) ;
V_10 -> V_446 = F_12 ( & V_51 -> V_115 [ 2 ] ) ;
V_10 -> V_447 = F_12 ( & V_51 -> V_115 [ 3 ] ) ;
V_10 -> V_448 = F_12 ( & V_51 -> V_115 [ 4 ] ) ;
V_10 -> V_449 = F_12 ( & V_51 -> V_115 [ 5 ] ) ;
V_10 -> V_89 = F_12 ( & V_51 -> V_115 [ 25 ] ) ;
return true ;
}
static bool F_180 ( struct V_9 * V_62 )
{
T_6 V_185 , V_450 , V_451 = 0 ;
struct V_63 T_1 * V_51 = V_62 -> V_28 ;
char * V_428 = V_62 -> V_429 ;
char * V_430 = V_62 -> V_431 ;
char T_1 * V_433 = ( char T_1 * ) ( & V_51 -> V_116 [ 15 ] ) ;
char T_1 * V_434 = ( char T_1 * ) ( & V_51 -> V_116 [ 17 ] ) ;
int V_436 ;
V_185 = F_12 ( & V_51 -> V_215 ) ;
F_13 ( V_185 | V_216 , & V_51 -> V_215 ) ;
do {
V_451 = F_12 ( & V_51 -> V_452 ) ;
} while ( ( V_451 & V_453 ) == 0 );
F_13 ( V_454 , & V_51 -> V_70 ) ;
F_13 ( V_72 , & V_51 -> V_73 ) ;
for ( V_450 = 0 ; V_450 < 2000 ; V_450 ++ ) {
if ( F_12 ( & V_51 -> V_29 ) & V_30 ) {
F_13 ( V_31 , & V_51 -> V_32 ) ;
break;
}
F_181 ( 10 ) ;
}
if ( V_450 >= 2000 ) {
F_9 ( V_22 L_34 , V_62 -> V_23 -> V_24 ) ;
return false ;
}
V_436 = 8 ;
while ( V_436 ) {
* V_428 = F_42 ( V_433 ) ;
V_428 ++ ;
V_433 ++ ;
V_436 -- ;
}
V_436 = 16 ;
while ( V_436 ) {
* V_430 = F_42 ( V_434 ) ;
V_430 ++ ;
V_434 ++ ;
V_436 -- ;
}
F_15 ( L_35 ,
V_62 -> V_23 -> V_24 ,
V_62 -> V_429 ,
V_62 -> V_431 ) ;
V_62 -> V_446 = F_12 ( & V_51 -> V_116 [ 1 ] ) ;
V_62 -> V_447 = F_12 ( & V_51 -> V_116 [ 2 ] ) ;
V_62 -> V_448 = F_12 ( & V_51 -> V_116 [ 3 ] ) ;
V_62 -> V_449 = F_12 ( & V_51 -> V_116 [ 4 ] ) ;
V_62 -> V_89 = F_12 ( & V_51 -> V_116 [ 25 ] ) ;
return true ;
}
static bool F_182 ( struct V_9 * V_10 )
{
char * V_428 = V_10 -> V_429 ;
char * V_430 = V_10 -> V_431 ;
char * V_432 = V_10 -> V_107 ;
char T_1 * V_433 ;
char T_1 * V_434 ;
char T_1 * V_435 ;
T_8 V_436 ;
struct V_65 * V_51 ;
void * V_17 ;
T_5 V_18 ;
struct V_19 * V_14 = V_10 -> V_14 ;
V_10 -> V_16 = F_34 ( sizeof( struct V_65 ) , 32 ) ;
V_17 = F_35 ( & V_14 -> V_15 , V_10 -> V_16 ,
& V_18 , V_96 ) ;
if ( ! V_17 ) {
F_15 ( L_36 ) ;
return false ;
}
memset ( V_17 , 0 , V_10 -> V_16 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_17 = V_17 ;
V_51 = (struct V_65 * ) V_17 ;
V_10 -> V_66 = V_51 ;
V_51 -> V_455 = V_10 -> V_25 + V_456 ;
V_51 -> V_457 = V_10 -> V_25 +
V_458 ;
V_51 -> V_459 = V_10 -> V_25 +
V_460 ;
V_51 -> V_461 = V_10 -> V_25 + V_462 ;
V_51 -> V_463 = V_10 -> V_25 + V_464 ;
V_51 -> V_246 = V_10 -> V_25 +
V_465 ;
V_51 -> V_218 = V_10 -> V_25 +
V_466 ;
V_51 -> V_70 = V_10 -> V_25 +
V_467 ;
V_51 -> V_468 = V_10 -> V_25 +
V_469 ;
V_51 -> V_470 = V_10 -> V_25 +
V_471 ;
V_51 -> V_452 = V_10 -> V_25 +
V_472 ;
V_51 -> V_73 = V_10 -> V_25 +
V_473 ;
V_51 -> V_29 = V_10 -> V_25 +
V_474 ;
V_51 -> V_475 = V_10 -> V_25 +
V_476 ;
V_51 -> V_477 = V_10 -> V_25 +
V_478 ;
V_51 -> V_479 = V_10 -> V_25 +
V_480 ;
V_51 -> V_315 = V_10 -> V_25 +
V_481 ;
V_51 -> V_482 = V_10 -> V_25 +
V_483 ;
V_51 -> V_484 = V_10 -> V_25 +
V_485 ;
V_51 -> V_486 = V_10 -> V_25 +
V_487 ;
V_51 -> V_257 = V_10 -> V_25 +
V_488 ;
V_51 -> V_361 = V_10 -> V_25 +
V_489 ;
V_51 -> V_490 = V_10 -> V_25 +
V_491 ;
V_51 -> V_331 = V_10 -> V_25 + V_492 ;
V_51 -> V_329 = V_10 -> V_25 + V_493 ;
V_51 -> V_116 = V_10 -> V_25 +
V_494 ;
V_433 = ( char T_1 * ) ( & V_51 -> V_116 [ 15 ] ) ;
V_434 = ( char T_1 * ) ( & V_51 -> V_116 [ 17 ] ) ;
V_435 = ( char T_1 * ) ( & V_51 -> V_116 [ 21 ] ) ;
if ( F_12 ( V_10 -> V_66 -> V_29 ) &
V_67 ) {
F_13 ( V_67 ,
V_10 -> V_66 -> V_29 ) ;
}
F_13 ( V_454 , V_51 -> V_70 ) ;
if ( ! F_27 ( V_10 ) ) {
F_15 ( L_37
L_38 , V_10 -> V_23 -> V_24 ) ;
F_4 ( & V_10 -> V_14 -> V_15 , V_10 -> V_16 ,
V_10 -> V_17 , V_10 -> V_18 ) ;
return false ;
}
V_436 = 8 ;
while ( V_436 ) {
* V_428 = F_42 ( V_433 ) ;
V_428 ++ ;
V_433 ++ ;
V_436 -- ;
}
V_436 = 16 ;
while ( V_436 ) {
* V_430 = F_42 ( V_434 ) ;
V_430 ++ ;
V_434 ++ ;
V_436 -- ;
}
V_436 = 16 ;
while ( V_436 ) {
* V_432 = F_42 ( V_435 ) ;
V_432 ++ ;
V_435 ++ ;
V_436 -- ;
}
V_10 -> V_108 = F_12 ( & V_51 -> V_116 [ 1 ] ) ;
V_10 -> V_446 = F_12 ( & V_51 -> V_116 [ 2 ] ) ;
V_10 -> V_447 = F_12 ( & V_51 -> V_116 [ 3 ] ) ;
V_10 -> V_448 = F_12 ( & V_51 -> V_116 [ 4 ] ) ;
V_10 -> V_449 = F_12 ( & V_51 -> V_116 [ 5 ] ) ;
V_10 -> V_89 = F_12 ( & V_51 -> V_116 [ 25 ] ) ;
F_15 ( L_35 ,
V_10 -> V_23 -> V_24 ,
V_10 -> V_429 ,
V_10 -> V_431 ) ;
return true ;
}
static bool F_66 ( struct V_9 * V_10 )
{
bool V_495 = false ;
switch ( V_10 -> V_11 ) {
case V_20 :
V_495 = F_183 ( V_10 ) ;
break;
case V_12 :
V_495 = F_179 ( V_10 ) ;
break;
case V_27 :
V_495 = F_180 ( V_10 ) ;
break;
case V_13 :
V_495 = F_182 ( V_10 ) ;
break;
default:
break;
}
if ( V_10 -> V_447 > V_152 )
V_10 -> V_496 = V_152 ;
else
V_10 -> V_496 = V_10 -> V_447 - 1 ;
V_10 -> V_23 -> V_151 = V_10 -> V_496 ;
return V_495 ;
}
static int F_184 ( struct V_9 * V_10 ,
struct V_76 * V_497 )
{
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
struct V_76 * V_193 ;
struct V_235 * V_99 ;
T_6 V_233 , V_53 , V_498 = 0 , V_258 = 0 ;
int V_495 ;
bool error ;
V_499:
V_258 ++ ;
V_53 = F_12 ( & V_51 -> V_53 ) & V_10 -> V_237 ;
F_13 ( V_53 , & V_51 -> V_53 ) ;
while ( 1 ) {
if ( ( V_233 = F_12 ( & V_51 -> V_238 ) ) == 0xFFFFFFFF ) {
if ( V_498 ) {
V_495 = V_129 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_258 > 100 ) {
V_495 = V_133 ;
break;
}
goto V_499;
}
}
V_99 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_193 = F_40 ( V_99 , struct V_76 , V_99 ) ;
V_498 |= ( V_193 == V_497 ) ? 1 : 0 ;
if ( ( V_193 -> V_10 != V_10 ) || ( V_193 -> V_197 != V_229 ) ) {
if ( ( V_193 -> V_197 == V_230 ) || ( V_193 == V_497 ) ) {
F_9 ( V_22 L_39
L_40
, V_10 -> V_23 -> V_24
, V_193 -> V_195 -> V_219 -> V_135
, ( T_8 ) V_193 -> V_195 -> V_219 -> V_111
, V_193 ) ;
V_193 -> V_195 -> V_203 = V_232 << 16 ;
F_101 ( V_193 ) ;
continue;
}
F_9 ( V_22 L_41
L_42
L_43
, V_10 -> V_23 -> V_24
, V_193
, F_108 ( & V_10 -> V_196 ) ) ;
continue;
}
error = ( V_233 & V_239 ) ? true : false ;
F_106 ( V_10 , V_193 , error ) ;
}
return V_495 ;
}
static int F_185 ( struct V_9 * V_10 ,
struct V_76 * V_497 )
{
struct V_55 * V_51 = V_10 -> V_56 ;
struct V_235 * V_99 ;
struct V_76 * V_193 ;
T_6 V_233 , V_498 = 0 , V_258 = 0 ;
int V_305 , V_495 ;
bool error ;
V_500:
V_258 ++ ;
F_13 ( V_240 , V_51 -> V_57 ) ;
while( 1 ) {
V_305 = V_51 -> V_244 ;
V_233 = V_51 -> V_242 [ V_305 ] ;
if ( V_233 == 0 ) {
if ( V_498 ) {
V_495 = V_129 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_258 > 100 ) {
V_495 = V_133 ;
break;
}
goto V_500;
}
}
V_51 -> V_242 [ V_305 ] = 0 ;
V_305 ++ ;
V_305 %= V_241 ;
V_51 -> V_244 = V_305 ;
V_99 = (struct V_235 * ) ( V_10 -> V_98 + ( V_233 << 5 ) ) ;
V_193 = F_40 ( V_99 , struct V_76 , V_99 ) ;
V_498 |= ( V_193 == V_497 ) ? 1 : 0 ;
if ( ( V_193 -> V_10 != V_10 ) || ( V_193 -> V_197 != V_229 ) ) {
if ( ( V_193 -> V_197 == V_230 ) || ( V_193 == V_497 ) ) {
F_9 ( V_22 L_39
L_40
, V_10 -> V_23 -> V_24
, V_193 -> V_195 -> V_219 -> V_135
, ( T_8 ) V_193 -> V_195 -> V_219 -> V_111
, V_193 ) ;
V_193 -> V_195 -> V_203 = V_232 << 16 ;
F_101 ( V_193 ) ;
continue;
}
F_9 ( V_22 L_41
L_42
L_43
, V_10 -> V_23 -> V_24
, V_193
, F_108 ( & V_10 -> V_196 ) ) ;
continue;
}
error = ( V_233 & V_239 ) ? true : false ;
F_106 ( V_10 , V_193 , error ) ;
}
return V_495 ;
}
static int F_186 ( struct V_9 * V_10 ,
struct V_76 * V_497 )
{
struct V_63 T_1 * V_51 = V_10 -> V_28 ;
T_6 V_233 , V_234 ;
struct V_235 * V_99 ;
bool error ;
struct V_76 * V_228 ;
T_6 V_498 = 0 , V_258 = 0 ;
int V_495 ;
V_501:
V_258 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_51 -> V_246 ) & V_247 ) == 0 ) {
if ( V_498 ) {
V_495 = V_129 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_258 > 100 ) {
V_495 = V_133 ;
break;
}
goto V_501;
}
}
V_233 = F_12 ( & V_51 -> V_248 ) ;
V_234 = ( V_233 & 0xFFFFFFF0 ) ;
V_99 = (struct V_235 * ) ( V_10 -> V_98 + V_234 ) ;
V_228 = F_40 ( V_99 , struct V_76 , V_99 ) ;
V_498 |= ( V_228 == V_497 ) ? 1 : 0 ;
if ( ( V_228 -> V_10 != V_10 ) || ( V_228 -> V_197 != V_229 ) ) {
if ( V_228 -> V_197 == V_230 ) {
F_9 ( V_22 L_39
L_40
, V_10 -> V_23 -> V_24
, V_228 -> V_195 -> V_219 -> V_135
, ( T_8 ) V_228 -> V_195 -> V_219 -> V_111
, V_228 ) ;
V_228 -> V_195 -> V_203 = V_232 << 16 ;
F_101 ( V_228 ) ;
continue;
}
F_9 ( V_22 L_41
L_42
L_43
, V_10 -> V_23 -> V_24
, V_228
, F_108 ( & V_10 -> V_196 ) ) ;
continue;
}
error = ( V_233 & V_249 ) ? true : false ;
F_106 ( V_10 , V_228 , error ) ;
}
return V_495 ;
}
static int F_187 ( struct V_9 * V_10 ,
struct V_76 * V_497 )
{
bool error ;
T_6 V_498 = 0 , V_258 = 0 , V_233 , V_234 ;
int V_495 , V_244 , V_252 , V_251 , V_255 ;
unsigned long V_35 ;
struct V_235 * V_99 ;
struct V_76 * V_228 ;
struct V_65 * V_250 = V_10 -> V_66 ;
V_502:
V_258 ++ ;
while ( 1 ) {
F_103 ( & V_10 -> V_160 , V_35 ) ;
V_251 = V_250 -> V_242 [ 0 ] . V_253 + 1 ;
V_244 = V_250 -> V_244 ;
if ( ( V_251 & 0xFFF ) == ( V_244 & 0xFFF ) ) {
F_104 ( & V_10 -> V_160 , V_35 ) ;
if ( V_498 ) {
V_495 = V_129 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_258 > 40 ) {
V_495 = V_133 ;
break;
}
goto V_502;
}
}
V_255 = V_244 & 0x4000 ;
V_252 = ( V_244 & 0xFFF ) + 1 ;
V_252 %= V_256 ;
V_250 -> V_244 = V_252 ? ( V_252 | V_255 ) :
( ( V_255 ^ 0x4000 ) + 1 ) ;
V_244 = V_250 -> V_244 ;
F_104 ( & V_10 -> V_160 , V_35 ) ;
V_233 = V_250 -> V_242 [ V_244 & 0xFFF ] . V_253 ;
V_234 = ( V_233 & 0xFFFFFFF0 ) ;
V_99 = (struct V_235 * ) ( V_10 -> V_98 +
V_234 ) ;
V_228 = F_40 ( V_99 , struct V_76 ,
V_99 ) ;
V_498 |= ( V_228 == V_497 ) ? 1 : 0 ;
if ( ( V_228 -> V_10 != V_10 ) ||
( V_228 -> V_197 != V_229 ) ) {
if ( V_228 -> V_197 == V_230 ) {
F_15 ( L_44
L_45
L_46
, V_10 -> V_23 -> V_24
, V_228 -> V_195 -> V_219 -> V_135
, ( T_8 ) V_228 -> V_195 -> V_219 -> V_111
, V_228 ) ;
V_228 -> V_195 -> V_203 = V_232 << 16 ;
F_101 ( V_228 ) ;
continue;
}
F_15 ( L_47
L_48
L_49
, V_10 -> V_23 -> V_24
, V_228
, F_108 ( & V_10 -> V_196 ) ) ;
continue;
}
error = ( V_233 & V_249 )
? true : false ;
F_106 ( V_10 , V_228 , error ) ;
}
return V_495 ;
}
static int F_188 ( struct V_9 * V_10 ,
struct V_76 * V_497 )
{
int V_495 = 0 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
V_495 = F_184 ( V_10 , V_497 ) ;
}
break;
case V_12 : {
V_495 = F_185 ( V_10 , V_497 ) ;
}
break;
case V_27 : {
V_495 = F_186 ( V_10 , V_497 ) ;
}
break;
case V_13 :
V_495 = F_187 ( V_10 , V_497 ) ;
break;
}
return V_495 ;
}
static int F_189 ( struct V_9 * V_10 )
{
T_6 V_79 , V_308 ;
T_5 V_75 ;
switch ( V_10 -> V_11 ) {
case V_12 :
case V_13 :
V_75 = V_10 -> V_18 ;
break;
default:
V_75 = V_10 -> V_75 ;
break;
}
V_79 = F_190 ( V_75 ) ;
V_308 = F_191 ( V_75 ) ;
V_10 -> V_308 = V_308 ;
switch ( V_10 -> V_11 ) {
case V_20 : {
if ( V_308 != 0 ) {
struct V_50 T_1 * V_51 = V_10 -> V_21 ;
F_13 ( V_503 , \
& V_51 -> V_115 [ 0 ] ) ;
F_13 ( V_308 , & V_51 -> V_115 [ 1 ] ) ;
F_13 ( V_504 , \
& V_51 -> V_70 ) ;
if ( ! F_23 ( V_10 ) ) {
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
