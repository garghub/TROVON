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
V_21 = F_6 ( V_29 , V_30 ) ;
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
static T_2 F_17 ( int V_32 , void * V_33 )
{
T_2 V_34 ;
struct V_5 * V_6 = V_33 ;
V_34 = F_18 ( V_6 ) ;
return V_34 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_3 V_37 , int * V_38 )
{
int V_39 , V_40 , V_41 , V_42 , V_43 ;
unsigned char * V_44 ;
V_44 = F_20 ( V_36 ) ;
if ( V_44 ) {
V_39 = F_21 ( V_44 , V_37 , & V_38 [ 2 ] , & V_38 [ 0 ] , & V_38 [ 1 ] ) ;
F_22 ( V_44 ) ;
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
static T_4 F_23 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( & V_46 -> V_48 ) &
V_49 ) {
F_13 ( V_49 ,
& V_46 -> V_48 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_25 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( V_46 -> V_52 )
& V_53 ) {
F_13 ( V_54 ,
V_46 -> V_52 ) ;
F_13 ( V_55 ,
V_46 -> V_56 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static T_4 F_26 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_59 = V_57 -> V_24 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( & V_59 -> V_25 )
& V_26 ) {
F_13 ( V_27 ,
& V_59 -> V_28 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static bool F_27 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 2000 ; V_47 ++ ) {
if ( F_12 ( V_46 -> V_25 )
& V_62 ) {
F_13 ( V_62 ,
V_46 -> V_25 ) ;
return true ;
}
F_24 ( 10 ) ;
}
return false ;
}
static void F_28 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
int V_63 = 30 ;
F_13 ( V_64 , & V_46 -> V_65 ) ;
do {
if ( F_23 ( V_6 ) )
break;
else {
V_63 -- ;
F_9 ( V_18 L_3 , V_6 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
int V_63 = 30 ;
F_13 ( V_66 , V_46 -> V_56 ) ;
do {
if ( F_25 ( V_6 ) )
break;
else {
V_63 -- ;
F_9 ( V_18 L_4 , V_6 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
}
static void F_30 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
int V_63 = 30 ;
F_13 ( V_64 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
do {
if ( F_26 ( V_57 ) ) {
break;
} else {
V_63 -- ;
F_9 ( V_18 L_4 , V_57 -> V_19 -> V_20 , V_63 ) ;
}
} while ( V_63 != 0 );
return;
}
static void F_31 ( struct V_5 * V_57 )
{
int V_63 = 15 ;
struct V_60 * V_46 = V_57 -> V_61 ;
F_13 ( V_64 , V_46 -> V_65 ) ;
do {
if ( F_27 ( V_57 ) )
break;
V_63 -- ;
F_15 ( L_5
L_6 ,
V_57 -> V_19 -> V_20 , V_63 ) ;
} while ( V_63 != 0 );
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
void * V_69 ;
T_5 V_70 ;
struct V_71 * V_72 ;
int V_47 = 0 , V_73 = 0 ;
T_5 V_74 ;
unsigned long V_12 ;
unsigned long V_75 ;
unsigned long V_76 ;
T_6 V_77 ;
for ( V_47 = 0 ; V_47 < V_78 ; V_47 ++ )
for ( V_73 = 0 ; V_73 < V_79 ; V_73 ++ )
V_6 -> V_80 [ V_47 ] [ V_73 ] = V_81 ;
V_75 = V_82 ;
V_76 = V_83 ;
V_77 = V_6 -> V_84 ;
if( ( V_77 & 0xFF ) >= 3 ) {
V_75 = ( V_85 << ( ( V_77 >> 8 ) & 0xFF ) ) * 1024 ;
V_76 = ( V_75 / 4096 ) ;
}
V_6 -> V_19 -> V_86 = V_75 / 512 ;
V_6 -> V_19 -> V_87 = V_76 ;
V_12 = F_34 ( sizeof( struct V_71 ) + ( V_76 - 1 ) * sizeof( struct V_88 ) , 32 ) ;
V_6 -> V_89 = V_12 * V_90 ;
V_69 = F_35 ( & V_10 -> V_11 , V_6 -> V_89 , & V_70 , V_91 ) ;
if( ! V_69 ) {
F_9 ( V_18 L_7 , V_6 -> V_19 -> V_20 ) ;
return - V_92 ;
}
V_6 -> V_69 = V_69 ;
V_6 -> V_70 = V_70 ;
memset ( V_69 , 0 , V_6 -> V_89 ) ;
V_72 = V_69 ;
V_6 -> V_93 = ( unsigned long ) V_69 - ( unsigned long ) V_70 ;
for( V_47 = 0 ; V_47 < V_90 ; V_47 ++ ) {
V_74 = V_70 + F_36 ( struct V_71 , V_94 ) ;
switch ( V_6 -> V_7 ) {
case V_16 :
case V_8 :
V_72 -> V_74 = V_74 >> 5 ;
break;
case V_23 :
case V_9 :
V_72 -> V_74 = V_74 ;
break;
}
V_6 -> V_95 [ V_47 ] = V_72 ;
V_72 -> V_6 = V_6 ;
F_37 ( & V_72 -> V_96 ) ;
F_38 ( & V_72 -> V_96 , & V_6 -> V_97 ) ;
V_72 = (struct V_71 * ) ( ( unsigned long ) V_72 + V_12 ) ;
V_70 = V_70 + V_12 ;
}
return 0 ;
}
static void F_39 ( struct V_98 * V_99 )
{
struct V_5 * V_6 = F_40 ( V_99 ,
struct V_5 , V_100 ) ;
char * V_101 = ( char * ) V_6 -> V_102 ;
T_6 T_1 * V_103 = NULL ;
char T_1 * V_104 = NULL ;
int V_105 , V_106 ;
struct V_1 * V_107 ;
char V_108 , V_109 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_103 = ( T_6 T_1 * ) ( & V_46 -> V_110 [ 0 ] ) ;
V_104 = ( char T_1 * ) ( & V_46 -> V_110 [ 21 ] ) ;
break;
}
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_103 = ( T_6 T_1 * ) ( & V_46 -> V_110 [ 0 ] ) ;
V_104 = ( char T_1 * ) ( & V_46 -> V_110 [ 21 ] ) ;
break;
}
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_103 = ( T_6 T_1 * ) ( & V_46 -> V_111 [ 0 ] ) ;
V_104 = ( char T_1 * ) ( & V_46 -> V_111 [ 21 ] ) ;
break;
}
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_103 = ( T_6 T_1 * ) ( & V_46 -> V_111 [ 0 ] ) ;
V_104 = ( char T_1 * ) ( & V_46 -> V_111 [ 21 ] ) ;
break;
}
}
F_41 ( & V_6 -> V_112 ) ;
if ( F_12 ( V_103 ) != V_113 )
return;
for ( V_105 = 0 ; V_105 < V_78 - 1 ;
V_105 ++ ) {
V_109 = F_42 ( V_104 ) ;
V_108 = ( * V_101 ) ^ V_109 ;
if ( V_108 != 0 ) {
* V_101 = V_109 ;
for ( V_106 = 0 ; V_106 < V_79 ;
V_106 ++ ) {
if ( ( V_108 & 0x01 ) == 1 &&
( V_109 & 0x01 ) == 1 ) {
F_43 ( V_6 -> V_19 ,
0 , V_105 , V_106 ) ;
} else if ( ( V_108 & 0x01 ) == 1
&& ( V_109 & 0x01 ) == 0 ) {
V_107 = F_44 ( V_6 -> V_19 ,
0 , V_105 , V_106 ) ;
if ( V_107 != NULL ) {
F_45 ( V_107 ) ;
F_46 ( V_107 ) ;
}
}
V_109 >>= 1 ;
V_108 >>= 1 ;
}
}
V_104 ++ ;
V_101 ++ ;
}
}
static int
F_47 ( struct V_15 * V_10 , struct V_5 * V_6 )
{
int V_47 , V_73 , V_114 ;
struct V_115 V_116 [ V_117 ] ;
for ( V_47 = 0 ; V_47 < V_117 ; V_47 ++ )
V_116 [ V_47 ] . V_118 = V_47 ;
V_114 = F_48 ( V_10 , V_116 , 1 , V_117 ) ;
if ( V_114 < 0 )
goto V_119;
V_6 -> V_120 = V_114 ;
for ( V_47 = 0 ; V_47 < V_114 ; V_47 ++ ) {
if ( F_49 ( V_116 [ V_47 ] . V_121 ,
F_17 , 0 , L_8 , V_6 ) ) {
F_50 ( L_9 ,
V_6 -> V_19 -> V_20 , V_116 [ V_47 ] . V_121 ) ;
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ )
F_51 ( V_116 [ V_73 ] . V_121 , V_6 ) ;
F_52 ( V_10 ) ;
goto V_119;
}
V_6 -> V_116 [ V_47 ] = V_116 [ V_47 ] ;
}
V_6 -> V_122 |= V_123 ;
F_53 ( L_10 , V_6 -> V_19 -> V_20 ) ;
return V_124 ;
V_119:
if ( F_54 ( V_10 , 1 ) < 0 )
goto V_125;
if ( F_49 ( V_10 -> V_32 , F_17 ,
V_126 , L_8 , V_6 ) ) {
F_50 ( L_9 ,
V_6 -> V_19 -> V_20 , V_10 -> V_32 ) ;
F_55 ( V_10 ) ;
goto V_125;
}
V_6 -> V_122 |= V_127 ;
F_53 ( L_11 , V_6 -> V_19 -> V_20 ) ;
return V_124 ;
V_125:
if ( F_49 ( V_10 -> V_32 , F_17 ,
V_126 , L_8 , V_6 ) ) {
F_50 ( L_12 ,
V_6 -> V_19 -> V_20 , V_10 -> V_32 ) ;
return V_128 ;
}
return V_124 ;
}
static int F_56 ( struct V_15 * V_10 , const struct V_129 * V_130 )
{
struct V_131 * V_19 ;
struct V_5 * V_6 ;
T_4 V_132 , V_133 ;
int error ;
error = F_57 ( V_10 ) ;
if( error ) {
return - V_134 ;
}
V_19 = F_58 ( & V_135 , sizeof( struct V_5 ) ) ;
if( ! V_19 ) {
goto V_136;
}
error = F_59 ( V_10 , F_60 ( 64 ) ) ;
if( error ) {
error = F_59 ( V_10 , F_60 ( 32 ) ) ;
if( error ) {
F_9 ( V_137
L_13 ,
V_19 -> V_20 ) ;
goto V_138;
}
}
F_61 ( & V_139 ) ;
V_132 = V_10 -> V_132 -> V_140 ;
V_133 = V_10 -> V_141 ;
V_6 = (struct V_5 * ) V_19 -> V_142 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_19 = V_19 ;
V_19 -> V_143 = V_79 ;
V_19 -> V_144 = V_78 ;
V_19 -> V_145 = 16 ;
V_19 -> V_146 = V_147 ;
V_19 -> V_148 = V_4 ;
V_19 -> V_149 = V_150 ;
V_19 -> V_151 = ( V_132 << 8 ) | V_133 ;
F_62 ( V_10 , V_19 ) ;
F_63 ( V_10 ) ;
error = F_64 ( V_10 , L_8 ) ;
if( error ) {
goto V_138;
}
F_65 ( & V_6 -> V_152 ) ;
F_65 ( & V_6 -> V_153 ) ;
F_65 ( & V_6 -> V_154 ) ;
F_65 ( & V_6 -> V_155 ) ;
F_65 ( & V_6 -> V_156 ) ;
F_65 ( & V_6 -> V_157 ) ;
V_6 -> V_122 |= ( V_158 |
V_159 |
V_160 ) ;
V_6 -> V_122 &= ~ V_161 ;
F_37 ( & V_6 -> V_97 ) ;
V_6 -> V_7 = V_130 -> V_162 ;
error = F_5 ( V_6 ) ;
if( ! error ) {
goto V_163;
}
error = F_66 ( V_6 ) ;
if( ! error ) {
goto V_164;
}
error = F_33 ( V_6 ) ;
if( error ) {
goto V_165;
}
error = F_67 ( V_19 , & V_10 -> V_11 ) ;
if( error ) {
goto V_166;
}
if ( F_47 ( V_10 , V_6 ) == V_128 )
goto V_167;
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_100 , F_39 ) ;
F_70 ( & V_6 -> V_112 , 16 ) ;
F_70 ( & V_6 -> V_168 , 16 ) ;
V_6 -> V_169 = V_170 ;
F_71 ( & V_6 -> V_171 ) ;
V_6 -> V_171 . V_172 = V_173 + F_72 ( 6 * V_174 ) ;
V_6 -> V_171 . V_175 = ( unsigned long ) V_6 ;
V_6 -> V_171 . V_176 = & V_177 ;
F_73 ( & V_6 -> V_171 ) ;
if( F_74 ( V_6 ) )
goto V_178;
F_75 ( V_19 ) ;
return 0 ;
V_178:
F_76 ( & V_6 -> V_171 ) ;
F_77 ( & V_6 -> V_100 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
V_167:
F_80 ( V_19 ) ;
V_166:
F_81 ( V_6 ) ;
V_165:
F_3 ( V_6 ) ;
V_164:
F_16 ( V_6 ) ;
V_163:
F_82 ( V_10 ) ;
V_138:
F_83 ( V_19 ) ;
V_136:
F_84 ( V_10 ) ;
return - V_134 ;
}
static void F_79 ( struct V_15 * V_10 ,
struct V_5 * V_6 )
{
int V_47 ;
if ( V_6 -> V_122 & V_127 ) {
F_51 ( V_10 -> V_32 , V_6 ) ;
F_55 ( V_10 ) ;
} else if ( V_6 -> V_122 & V_123 ) {
for ( V_47 = 0 ; V_47 < V_6 -> V_120 ; V_47 ++ )
F_51 ( V_6 -> V_116 [ V_47 ] . V_121 , V_6 ) ;
F_52 ( V_10 ) ;
} else
F_51 ( V_10 -> V_32 , V_6 ) ;
}
static int F_85 ( struct V_15 * V_10 , T_7 V_179 )
{
T_6 V_180 ;
struct V_131 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_142 ;
V_180 = F_87 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
F_76 ( & V_6 -> V_171 ) ;
F_77 ( & V_6 -> V_100 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_62 ( V_10 , V_19 ) ;
F_88 ( V_10 ) ;
F_84 ( V_10 ) ;
F_89 ( V_10 , F_90 ( V_10 , V_179 ) ) ;
return 0 ;
}
static int F_91 ( struct V_15 * V_10 )
{
int error ;
struct V_131 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_142 ;
F_89 ( V_10 , V_181 ) ;
F_92 ( V_10 , V_181 , 0 ) ;
F_93 ( V_10 ) ;
if ( F_57 ( V_10 ) ) {
F_50 ( L_14 , V_182 ) ;
return - V_134 ;
}
error = F_59 ( V_10 , F_60 ( 64 ) ) ;
if ( error ) {
error = F_59 ( V_10 , F_60 ( 32 ) ) ;
if ( error ) {
F_50 ( L_13 ,
V_19 -> V_20 ) ;
goto V_183;
}
}
F_63 ( V_10 ) ;
if ( F_47 ( V_10 , V_6 ) == V_128 )
goto V_184;
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_100 , F_39 ) ;
F_70 ( & V_6 -> V_112 , 16 ) ;
F_70 ( & V_6 -> V_168 , 16 ) ;
V_6 -> V_169 = V_170 ;
F_71 ( & V_6 -> V_171 ) ;
V_6 -> V_171 . V_172 = V_173 + F_72 ( 6 * V_174 ) ;
V_6 -> V_171 . V_175 = ( unsigned long ) V_6 ;
V_6 -> V_171 . V_176 = & V_177 ;
F_73 ( & V_6 -> V_171 ) ;
return 0 ;
V_184:
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
V_183:
F_80 ( V_19 ) ;
F_81 ( V_6 ) ;
F_16 ( V_6 ) ;
F_82 ( V_10 ) ;
F_83 ( V_19 ) ;
F_84 ( V_10 ) ;
return - V_134 ;
}
static T_4 F_94 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_185 , & V_46 -> V_65 ) ;
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
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_186 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_15
, V_6 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_96 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
F_13 ( V_185 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_15
, V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_97 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
F_13 ( V_185 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) ) {
F_15 ( L_16
L_17 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
return true ;
}
static T_4 F_98 ( struct V_5 * V_6 )
{
T_4 V_187 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_187 = F_94 ( V_6 ) ;
}
break;
case V_8 : {
V_187 = F_95 ( V_6 ) ;
}
break;
case V_23 : {
V_187 = F_96 ( V_6 ) ;
}
break;
case V_9 :
V_187 = F_97 ( V_6 ) ;
break;
}
return V_187 ;
}
static void F_99 ( struct V_71 * V_188 )
{
struct V_189 * V_190 = V_188 -> V_190 ;
F_100 ( V_190 ) ;
}
static void F_101 ( struct V_71 * V_188 )
{
struct V_5 * V_6 = V_188 -> V_6 ;
struct V_189 * V_190 = V_188 -> V_190 ;
unsigned long V_31 ;
F_102 ( & V_6 -> V_191 ) ;
F_99 ( V_188 ) ;
V_188 -> V_192 = V_193 ;
F_103 ( & V_6 -> V_153 , V_31 ) ;
F_38 ( & V_188 -> V_96 , & V_6 -> V_97 ) ;
F_104 ( & V_6 -> V_153 , V_31 ) ;
V_190 -> V_194 ( V_190 ) ;
}
static void F_105 ( struct V_71 * V_188 )
{
struct V_189 * V_190 = V_188 -> V_190 ;
struct V_195 * V_196 = (struct V_195 * ) V_190 -> V_197 ;
V_190 -> V_198 = V_199 << 16 ;
if ( V_196 ) {
int V_200 =
sizeof( struct V_195 ) < V_201
? sizeof( struct V_195 ) : V_201 ;
memset ( V_196 , 0 , V_201 ) ;
memcpy ( V_196 , V_188 -> V_94 . V_202 , V_200 ) ;
V_196 -> V_203 = V_204 ;
V_196 -> V_205 = 1 ;
}
}
static T_8 F_87 ( struct V_5 * V_6 )
{
T_8 V_206 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_206 = F_12 ( & V_46 -> V_207 ) ;
F_13 ( V_206 | V_208 , \
& V_46 -> V_207 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_206 = F_12 ( V_46 -> V_209 ) ;
F_13 ( 0 , V_46 -> V_209 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_206 = F_12 ( & V_46 -> V_210 ) ;
F_13 ( V_206 | V_211 , & V_46 -> V_210 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_212 , V_46 -> V_213 ) ;
}
break;
}
return V_206 ;
}
static void F_106 ( struct V_5 * V_6 ,
struct V_71 * V_188 , bool error )
{
T_4 V_130 , V_106 ;
V_130 = V_188 -> V_190 -> V_214 -> V_130 ;
V_106 = V_188 -> V_190 -> V_214 -> V_106 ;
if ( ! error ) {
if ( V_6 -> V_80 [ V_130 ] [ V_106 ] == V_81 )
V_6 -> V_80 [ V_130 ] [ V_106 ] = V_215 ;
V_188 -> V_190 -> V_198 = V_199 << 16 ;
F_101 ( V_188 ) ;
} else{
switch ( V_188 -> V_94 . V_216 ) {
case V_217 : {
V_6 -> V_80 [ V_130 ] [ V_106 ] = V_81 ;
V_188 -> V_190 -> V_198 = V_218 << 16 ;
F_101 ( V_188 ) ;
}
break;
case V_219 :
case V_220 : {
V_6 -> V_80 [ V_130 ] [ V_106 ] = V_81 ;
V_188 -> V_190 -> V_198 = V_221 << 16 ;
F_101 ( V_188 ) ;
}
break;
case V_222 : {
V_6 -> V_80 [ V_130 ] [ V_106 ] = V_215 ;
F_105 ( V_188 ) ;
F_101 ( V_188 ) ;
}
break;
default:
F_9 ( V_18
L_18
, V_6 -> V_19 -> V_20
, V_130
, V_106
, V_188 -> V_94 . V_216 ) ;
V_6 -> V_80 [ V_130 ] [ V_106 ] = V_81 ;
V_188 -> V_190 -> V_198 = V_218 << 16 ;
F_101 ( V_188 ) ;
break;
}
}
}
static void F_107 ( struct V_5 * V_6 , struct V_71 * V_223 , bool error )
{
int V_130 , V_106 ;
if ( ( V_223 -> V_6 != V_6 ) || ( V_223 -> V_192 != V_224 ) ) {
if ( V_223 -> V_192 == V_225 ) {
struct V_189 * V_226 = V_223 -> V_190 ;
if ( V_226 ) {
V_130 = V_226 -> V_214 -> V_130 ;
V_106 = V_226 -> V_214 -> V_106 ;
V_226 -> V_198 |= V_227 << 16 ;
F_101 ( V_223 ) ;
F_9 ( V_18 L_19 ,
V_6 -> V_19 -> V_20 , V_223 ) ;
}
return;
}
F_9 ( V_18 L_20
L_21
L_22
, V_6 -> V_19 -> V_20
, V_6
, V_223
, V_223 -> V_6
, V_223 -> V_192
, F_108 ( & V_6 -> V_191 ) ) ;
return;
}
F_106 ( V_6 , V_223 , error ) ;
}
static void F_109 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
T_6 V_228 , V_229 ;
struct V_230 * V_231 ;
bool error ;
struct V_71 * V_223 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
T_6 V_48 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_232 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while( ( ( V_228 = F_12 ( & V_46 -> V_233 ) ) != 0xFFFFFFFF )
&& ( V_47 ++ < V_147 ) ) {
V_231 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_223 = F_40 ( V_231 , struct V_71 , V_94 ) ;
error = ( V_228 & V_234 ) ? true : false ;
F_107 ( V_6 , V_223 , error ) ;
}
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_235 , V_46 -> V_52 ) ;
for ( V_47 = 0 ; V_47 < V_236 ; V_47 ++ ) {
V_228 = V_46 -> V_237 [ V_47 ] ;
if ( V_228 != 0 ) {
V_46 -> V_237 [ V_47 ] = 0 ;
V_231 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_223 = F_40 ( V_231 , struct V_71 , V_94 ) ;
error = ( V_228 & V_234 ) ? true : false ;
F_107 ( V_6 , V_223 , error ) ;
}
V_46 -> V_238 [ V_47 ] = 0 ;
}
V_46 -> V_239 = 0 ;
V_46 -> V_240 = 0 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
while ( ( F_12 ( & V_46 -> V_241 ) & V_242 ) && ( V_47 ++ < V_147 ) ) {
V_228 = F_12 ( & V_46 -> V_243 ) ;
V_229 = ( V_228 & 0xFFFFFFF0 ) ;
V_231 = (struct V_230 * ) ( V_6 -> V_93 + V_229 ) ;
V_223 = F_40 ( V_231 , struct V_71 , V_94 ) ;
error = ( V_228 & V_244 ) ? true : false ;
F_107 ( V_6 , V_223 , error ) ;
}
}
break;
case V_9 : {
struct V_60 * V_245 = V_6 -> V_61 ;
T_6 V_246 ;
T_6 V_239 , V_247 , V_248 , V_249 , V_250 ;
unsigned long V_31 ;
V_249 = F_108 ( & V_6 -> V_191 ) ;
for ( V_47 = 0 ; V_47 < V_249 ; V_47 ++ ) {
F_103 ( & V_6 -> V_155 , V_31 ) ;
V_246 =
V_245 -> V_237 [ 0 ] . V_248 + 1 ;
V_239 = V_245 -> V_239 ;
if ( ( V_239 & 0xFFF ) !=
( V_246 & 0xFFF ) ) {
V_250 = V_239 & 0x4000 ;
V_247 = ( V_239 & 0xFFF ) + 1 ;
V_247 %= V_251 ;
V_245 -> V_239 = V_247 ? ( V_247 | V_250 ) :
( ( V_250 ^ 0x4000 ) + 1 ) ;
V_239 = V_245 -> V_239 ;
F_104 ( & V_6 -> V_155 , V_31 ) ;
V_248 = V_245 -> V_237 [ V_239 &
0xFFF ] . V_248 ;
V_229 = ( V_248 & 0xFFFFFFF0 ) ;
V_231 = (struct V_230 * )
( V_6 -> V_93 + V_229 ) ;
V_223 = F_40 ( V_231 ,
struct V_71 , V_94 ) ;
error = ( V_248 &
V_244 ) ?
true : false ;
F_107 ( V_6 , V_223 , error ) ;
F_13 ( V_239 ,
V_245 -> V_252 ) ;
} else {
F_104 ( & V_6 -> V_155 , V_31 ) ;
F_110 ( 10 ) ;
}
}
V_245 -> V_240 = 0 ;
V_245 -> V_239 = 0x40FF ;
}
break;
}
}
static void F_111 ( struct V_15 * V_10 )
{
struct V_131 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_142 ;
int V_253 = 0 ;
F_112 ( V_6 ) ;
F_80 ( V_19 ) ;
F_77 ( & V_6 -> V_100 ) ;
F_76 ( & V_6 -> V_171 ) ;
F_87 ( V_6 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
V_6 -> V_122 |= V_161 ;
V_6 -> V_122 &= ~ V_254 ;
for ( V_253 = 0 ; V_253 < V_147 ; V_253 ++ ) {
if ( ! F_108 ( & V_6 -> V_191 ) )
break;
F_18 ( V_6 ) ;
F_24 ( 25 ) ;
}
if ( F_108 ( & V_6 -> V_191 ) ) {
int V_47 ;
F_98 ( V_6 ) ;
F_109 ( V_6 ) ;
for ( V_47 = 0 ; V_47 < V_90 ; V_47 ++ ) {
struct V_71 * V_188 = V_6 -> V_95 [ V_47 ] ;
if ( V_188 -> V_192 == V_224 ) {
V_188 -> V_192 = V_225 ;
V_188 -> V_190 -> V_198 = V_227 << 16 ;
F_101 ( V_188 ) ;
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
struct V_131 * V_19 = F_86 ( V_10 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_19 -> V_142 ;
F_76 ( & V_6 -> V_171 ) ;
F_87 ( V_6 ) ;
F_79 ( V_10 , V_6 ) ;
F_77 ( & V_6 -> V_100 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static int F_114 ( void )
{
int error = 0 ;
error = F_115 ( & V_255 ) ;
return error ;
}
static void F_116 ( void )
{
F_117 ( & V_255 ) ;
}
static void F_118 ( struct V_5 * V_6 ,
T_8 V_180 )
{
T_8 V_256 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_256 = V_180 & ~ ( V_257 |
V_258 |
V_259 ) ;
F_13 ( V_256 , & V_46 -> V_207 ) ;
V_6 -> V_232 = ~ ( V_180 & V_256 ) & 0x000000ff ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_256 = V_180 | ( V_260 |
V_261 |
V_262 |
V_53 ) ;
F_13 ( V_256 , V_46 -> V_209 ) ;
V_6 -> V_232 = ( V_180 | V_256 ) & 0x0000000f ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_256 = ~ ( V_263 | V_264 | V_265 ) ;
F_13 ( V_180 & V_256 , & V_46 -> V_210 ) ;
V_6 -> V_232 = ~ ( V_180 & V_256 ) & 0x0000000f ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_256 = V_266 ;
F_13 ( V_180 | V_256 , V_46 -> V_213 ) ;
break;
}
}
}
static int F_119 ( struct V_5 * V_6 ,
struct V_71 * V_188 , struct V_189 * V_190 )
{
struct V_230 * V_94 = (struct V_230 * ) & V_188 -> V_94 ;
T_9 * V_267 = ( T_9 * ) & V_94 -> V_268 ;
T_10 V_269 , V_270 ;
int V_271 = 0x30 ;
T_10 V_272 = 0 ;
int V_47 ;
struct V_273 * V_274 ;
int V_275 ;
V_188 -> V_190 = V_190 ;
memset ( V_94 , 0 , sizeof( struct V_230 ) ) ;
V_94 -> V_276 = V_190 -> V_214 -> V_130 ;
V_94 -> V_277 = V_190 -> V_214 -> V_106 ;
V_94 -> V_278 = 1 ;
V_94 -> V_279 = 0 ;
memcpy ( V_94 -> V_280 , V_190 -> V_281 , V_190 -> V_282 ) ;
V_275 = F_120 ( V_190 ) ;
if ( F_121 ( V_275 > V_6 -> V_19 -> V_87 || V_275 < 0 ) )
return V_128 ;
F_122 (pcmd, sg, nseg, i) {
V_272 = F_123 ( F_124 ( V_274 ) ) ;
V_269 = F_123 ( F_125 ( F_126 ( V_274 ) ) ) ;
V_270 = F_123 ( F_127 ( F_126 ( V_274 ) ) ) ;
if ( V_270 == 0 ) {
struct V_283 * V_284 = (struct V_283 * ) V_267 ;
V_284 -> V_285 = V_269 ;
V_284 -> V_272 = V_272 ;
V_267 += sizeof ( struct V_283 ) ;
V_271 += sizeof ( struct V_283 ) ;
} else {
struct V_88 * V_284 = (struct V_88 * ) V_267 ;
V_284 -> V_286 = V_270 ;
V_284 -> V_285 = V_269 ;
V_284 -> V_272 = V_272 | F_123 ( V_287 ) ;
V_267 += sizeof ( struct V_88 ) ;
V_271 += sizeof ( struct V_88 ) ;
}
}
V_94 -> V_288 = ( T_4 ) V_275 ;
V_94 -> V_289 = F_128 ( V_190 ) ;
V_94 -> V_290 = V_271 / 0x100 + ( V_271 % 0x100 ? 1 : 0 ) ;
if ( V_271 > 256 )
V_94 -> V_291 |= V_292 ;
if ( V_190 -> V_293 == V_294 )
V_94 -> V_291 |= V_295 ;
V_188 -> V_296 = V_271 ;
return V_124 ;
}
static void F_129 ( struct V_5 * V_6 , struct V_71 * V_188 )
{
T_6 V_74 = V_188 -> V_74 ;
struct V_230 * V_94 = (struct V_230 * ) & V_188 -> V_94 ;
F_41 ( & V_6 -> V_191 ) ;
V_188 -> V_192 = V_224 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
if ( V_94 -> V_291 & V_292 )
F_13 ( V_74 | V_297 ,
& V_46 -> V_298 ) ;
else
F_13 ( V_74 , & V_46 -> V_298 ) ;
break;
}
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
T_6 V_299 , V_300 = V_46 -> V_240 ;
V_299 = ( ( V_300 + 1 ) % V_236 ) ;
V_46 -> V_238 [ V_299 ] = 0 ;
if ( V_94 -> V_291 & V_292 ) {
V_46 -> V_238 [ V_300 ] =
V_74 | V_297 ;
} else {
V_46 -> V_238 [ V_300 ] = V_74 ;
}
V_300 ++ ;
V_300 %= V_236 ;
V_46 -> V_240 = V_300 ;
F_13 ( V_301 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
T_6 V_302 , V_296 ;
V_296 = ( V_188 -> V_296 > 0x300 ) ? 0x300 : V_188 -> V_296 ;
V_302 = ( V_74 | ( ( V_296 - 1 ) >> 6 ) | 1 ) ;
if ( V_6 -> V_303 ) {
F_13 ( V_6 -> V_303 , & V_59 -> V_304 ) ;
F_13 ( V_302 , & V_59 -> V_305 ) ;
} else {
F_13 ( V_302 , & V_59 -> V_305 ) ;
}
}
break;
case V_9 : {
struct V_60 * V_245 = V_6 -> V_61 ;
T_11 V_247 ;
T_11 V_240 , V_250 ;
unsigned long V_31 ;
struct V_306 * V_307 ;
F_103 ( & V_6 -> V_154 , V_31 ) ;
V_240 = V_245 -> V_240 ;
V_307 = (struct V_306 * ) & ( V_245 -> V_238 [ V_240 & 0xFF ] ) ;
V_307 -> V_308 = F_127 ( V_74 ) ;
V_307 -> V_248 = F_125 ( V_74 ) ;
V_307 -> V_272 = V_188 -> V_296 >> 2 ;
V_94 -> V_279 = F_125 ( V_74 ) ;
V_250 = V_240 & 0x4000 ;
V_247 = V_240 + 1 ;
V_247 &= ( V_309 - 1 ) ;
V_245 -> V_240 = V_247 ? ( V_247 | V_250 ) :
( V_250 ^ 0x4000 ) ;
F_13 ( V_240 , V_245 -> V_310 ) ;
F_104 ( & V_6 -> V_154 , V_31 ) ;
break;
}
}
}
static void F_130 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_6 -> V_122 &= ~ V_311 ;
F_13 ( V_312 , & V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_18
L_23
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_131 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
V_6 -> V_122 &= ~ V_311 ;
F_13 ( V_313 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18
L_23
, V_6 -> V_19 -> V_20 ) ;
}
}
static void F_132 ( struct V_5 * V_57 )
{
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_57 -> V_122 &= ~ V_311 ;
F_13 ( V_312 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
if ( ! F_26 ( V_57 ) ) {
F_9 ( V_18
L_23
, V_57 -> V_19 -> V_20 ) ;
}
return;
}
static void F_133 ( struct V_5 * V_57 )
{
struct V_60 * V_46 = V_57 -> V_61 ;
V_57 -> V_122 &= ~ V_311 ;
F_13 ( V_312 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_57 ) )
F_15 ( L_24
L_25 , V_57 -> V_19 -> V_20 ) ;
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
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_89 , V_6 -> V_69 , V_6 -> V_70 ) ;
}
static void F_134 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_314 , & V_46 -> V_68 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_315 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_316 , & V_46 -> V_68 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_317 ,
V_46 -> V_68 ) ;
}
break;
}
}
static void F_135 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_318 , & V_46 -> V_68 ) ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_319 , V_46 -> V_56 ) ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_320 , & V_46 -> V_68 ) ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_321 ,
V_46 -> V_68 ) ;
}
break;
}
}
struct V_322 T_1 * F_136 ( struct V_5 * V_6 )
{
struct V_322 T_1 * V_323 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_323 = (struct V_322 T_1 * ) & V_46 -> V_324 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_323 = (struct V_322 T_1 * ) V_46 -> V_324 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_59 = V_6 -> V_24 ;
V_323 = (struct V_322 T_1 * ) & V_59 -> V_324 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_323 = (struct V_322 T_1 * ) V_46 -> V_324 ;
}
break;
}
return V_323 ;
}
static struct V_322 T_1 * F_137 ( struct V_5 * V_6 )
{
struct V_322 T_1 * V_325 = NULL ;
switch ( V_6 -> V_7 ) {
case V_16 : {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_325 = (struct V_322 T_1 * ) & V_46 -> V_326 ;
}
break;
case V_8 : {
struct V_50 * V_46 = V_6 -> V_51 ;
V_325 = (struct V_322 T_1 * ) V_46 -> V_326 ;
}
break;
case V_23 : {
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
V_325 = (struct V_322 T_1 * ) & V_46 -> V_326 ;
}
break;
case V_9 : {
struct V_60 * V_46 = V_6 -> V_61 ;
V_325 = (struct V_322 T_1 * ) V_46 -> V_326 ;
}
break;
}
return V_325 ;
}
static T_6
F_138 ( struct V_5 * V_6 ,
struct V_322 T_1 * V_327 )
{
T_4 * V_328 ;
T_4 * V_329 = NULL ;
T_6 T_1 * V_330 ;
T_6 V_331 , V_332 , * V_333 = NULL ;
V_330 = ( T_6 T_1 * ) V_327 -> V_175 ;
V_331 = F_12 ( & V_327 -> V_332 ) ;
if ( V_331 > 0 ) {
V_329 = F_139 ( 128 , V_334 ) ;
V_333 = ( T_6 * ) V_329 ;
if ( V_329 == NULL )
return 0 ;
V_332 = V_331 ;
while ( V_332 >= 4 ) {
* V_333 ++ = F_12 ( V_330 ) ;
V_330 ++ ;
V_332 -= 4 ;
}
if ( V_332 )
* V_333 = F_12 ( V_330 ) ;
V_333 = ( T_6 * ) V_329 ;
}
while ( V_331 > 0 ) {
V_328 = & V_6 -> V_335 [ V_6 -> V_336 ] ;
* V_328 = * V_329 ;
V_6 -> V_336 ++ ;
V_6 -> V_336 %= V_337 ;
V_329 ++ ;
V_331 -- ;
}
F_22 ( V_333 ) ;
F_134 ( V_6 ) ;
return 1 ;
}
T_6
F_140 ( struct V_5 * V_6 ,
struct V_322 T_1 * V_327 ) {
T_4 * V_328 ;
T_4 T_1 * V_330 ;
T_6 V_331 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) )
return F_138 ( V_6 , V_327 ) ;
V_330 = ( T_4 T_1 * ) V_327 -> V_175 ;
V_331 = F_12 ( & V_327 -> V_332 ) ;
while ( V_331 > 0 ) {
V_328 = & V_6 -> V_335 [ V_6 -> V_336 ] ;
* V_328 = F_42 ( V_330 ) ;
V_6 -> V_336 ++ ;
V_6 -> V_336 %= V_337 ;
V_330 ++ ;
V_331 -- ;
}
F_134 ( V_6 ) ;
return 1 ;
}
static void F_141 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
struct V_322 T_1 * V_327 ;
T_12 V_338 ;
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_327 = F_136 ( V_6 ) ;
V_338 = ( V_6 -> V_336 - V_6 -> V_339 - 1 ) &
( V_337 - 1 ) ;
if ( V_338 >= F_12 ( & V_327 -> V_332 ) ) {
if ( F_140 ( V_6 , V_327 ) == 0 )
V_6 -> V_122 |= V_340 ;
} else
V_6 -> V_122 |= V_340 ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
}
static void F_142 ( struct V_5 * V_6 )
{
T_4 * V_328 ;
struct V_322 T_1 * V_341 ;
T_4 * V_329 = NULL ;
T_6 T_1 * V_330 ;
T_6 V_342 = 0 , V_332 , * V_333 = NULL , V_175 ;
if ( V_6 -> V_122 & V_160 ) {
V_329 = F_139 ( 128 , V_334 ) ;
V_333 = ( T_6 * ) V_329 ;
if ( V_329 == NULL )
return;
V_6 -> V_122 &= ( ~ V_160 ) ;
V_341 = F_137 ( V_6 ) ;
V_330 = ( T_6 T_1 * ) V_341 -> V_175 ;
while ( ( V_6 -> V_343 != V_6 -> V_344 )
&& ( V_342 < 124 ) ) {
V_328 = & V_6 -> V_345 [ V_6 -> V_343 ] ;
* V_329 = * V_328 ;
V_6 -> V_343 ++ ;
V_6 -> V_343 %= V_337 ;
V_329 ++ ;
V_342 ++ ;
}
V_332 = V_342 ;
V_329 = ( T_4 * ) V_333 ;
while ( V_332 >= 4 ) {
V_175 = * V_333 ++ ;
F_13 ( V_175 , V_330 ) ;
V_330 ++ ;
V_332 -= 4 ;
}
if ( V_332 ) {
V_175 = * V_333 ;
F_13 ( V_175 , V_330 ) ;
}
F_13 ( V_342 , & V_341 -> V_332 ) ;
F_22 ( V_329 ) ;
F_135 ( V_6 ) ;
}
}
void
F_143 ( struct V_5 * V_6 )
{
T_4 * V_328 ;
struct V_322 T_1 * V_341 ;
T_4 T_1 * V_330 ;
T_12 V_342 = 0 ;
if ( V_6 -> V_7 & ( V_23 | V_9 ) ) {
F_142 ( V_6 ) ;
return;
}
if ( V_6 -> V_122 & V_160 ) {
V_6 -> V_122 &= ( ~ V_160 ) ;
V_341 = F_137 ( V_6 ) ;
V_330 = ( T_4 T_1 * ) V_341 -> V_175 ;
while ( ( V_6 -> V_343 != V_6 -> V_344 )
&& ( V_342 < 124 ) ) {
V_328 = & V_6 -> V_345 [ V_6 -> V_343 ] ;
F_144 ( * V_328 , V_330 ) ;
V_6 -> V_343 ++ ;
V_6 -> V_343 %= V_337 ;
V_330 ++ ;
V_342 ++ ;
}
F_13 ( V_342 , & V_341 -> V_332 ) ;
F_135 ( V_6 ) ;
}
}
static void F_145 ( struct V_5 * V_6 )
{
unsigned long V_31 ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_6 -> V_122 |= V_160 ;
if ( V_6 -> V_343 != V_6 -> V_344 )
F_143 ( V_6 ) ;
if ( V_6 -> V_343 == V_6 -> V_344 )
V_6 -> V_122 |= V_158 ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
}
static void F_146 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_25 ) ;
if ( V_25 & V_346 )
F_141 ( V_6 ) ;
if ( V_25 & V_347 )
F_145 ( V_6 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_346
| V_347 ) );
}
static void F_147 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
do {
F_13 ( V_25 , & V_46 -> V_28 ) ;
F_12 ( & V_46 -> V_28 ) ;
if ( V_25 & V_348 )
F_141 ( V_57 ) ;
if ( V_25 & V_349 )
F_145 ( V_57 ) ;
if ( V_25 & V_26 )
F_148 ( V_57 ) ;
V_25 = F_12 ( & V_46 -> V_25 ) ;
} while ( V_25 & ( V_348
| V_349
| V_26 ) );
}
static void F_149 ( struct V_5 * V_57 )
{
T_6 V_25 ;
struct V_60 * V_245 = V_57 -> V_61 ;
V_25 = F_12 ( V_245 -> V_25 ) ;
do {
F_13 ( V_25 , V_245 -> V_25 ) ;
if ( V_25 & V_62 )
F_150 ( V_57 ) ;
if ( V_25 & V_350 )
F_141 ( V_57 ) ;
if ( V_25 & V_351 )
F_145 ( V_57 ) ;
V_25 = F_12 ( V_245 -> V_25 ) ;
} while ( V_25 & ( V_350
| V_351
| V_62 ) );
}
static void F_151 ( struct V_5 * V_6 )
{
T_6 V_228 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_230 * V_231 ;
struct V_71 * V_223 ;
bool error ;
while ( ( V_228 = F_12 ( & V_46 -> V_233 ) ) != 0xFFFFFFFF ) {
V_231 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_223 = F_40 ( V_231 , struct V_71 , V_94 ) ;
error = ( V_228 & V_234 ) ? true : false ;
F_107 ( V_6 , V_223 , error ) ;
}
}
static void F_152 ( struct V_5 * V_6 )
{
T_6 V_300 ;
T_6 V_228 ;
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_230 * V_231 ;
struct V_71 * V_223 ;
bool error ;
V_300 = V_46 -> V_239 ;
while ( ( V_228 = V_46 -> V_237 [ V_300 ] ) != 0 ) {
V_46 -> V_237 [ V_300 ] = 0 ;
V_231 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_223 = F_40 ( V_231 , struct V_71 , V_94 ) ;
error = ( V_228 & V_234 ) ? true : false ;
F_107 ( V_6 , V_223 , error ) ;
V_300 ++ ;
V_300 %= V_236 ;
V_46 -> V_239 = V_300 ;
}
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_59 ;
struct V_230 * V_94 ;
struct V_71 * V_188 ;
T_6 V_228 , V_229 , V_352 = 0 ;
int error ;
V_59 = V_6 -> V_24 ;
while ( ( V_228 = F_12 ( & V_59 -> V_243 ) ) !=
0xFFFFFFFF ) {
V_229 = ( V_228 & 0xFFFFFFF0 ) ;
V_94 = (struct V_230 * ) ( V_6 -> V_93
+ V_229 ) ;
V_188 = F_40 ( V_94 , struct V_71 ,
V_94 ) ;
error = ( V_228 & V_244 )
? true : false ;
F_107 ( V_6 , V_188 , error ) ;
V_352 ++ ;
if ( V_352 == V_353 ) {
F_13 ( V_354 ,
& V_59 -> V_68 ) ;
V_352 = 0 ;
}
}
}
static void F_154 ( struct V_5 * V_6 )
{
T_8 V_246 , V_239 , V_247 , V_250 ;
T_6 V_248 , V_229 ;
int error ;
struct V_60 * V_245 ;
struct V_230 * V_94 ;
struct V_71 * V_188 ;
unsigned long V_31 ;
F_103 ( & V_6 -> V_155 , V_31 ) ;
V_245 = V_6 -> V_61 ;
V_246 = V_245 -> V_237 [ 0 ] . V_248 + 1 ;
V_239 = V_245 -> V_239 ;
if ( ( V_239 & 0xFFF ) != ( V_246 & 0xFFF ) ) {
do {
V_250 = V_239 & 0x4000 ;
V_247 = ( V_239 & 0xFFF ) + 1 ;
V_247 %= V_251 ;
V_245 -> V_239 = V_247 ? ( V_247 | V_250 ) :
( ( V_250 ^ 0x4000 ) + 1 ) ;
V_239 = V_245 -> V_239 ;
V_248 = V_245 -> V_237 [ V_239 &
0xFFF ] . V_248 ;
V_229 = ( V_248 & 0xFFFFFFF0 ) ;
V_94 = (struct V_230 * ) ( V_6 -> V_93
+ V_229 ) ;
V_188 = F_40 ( V_94 ,
struct V_71 , V_94 ) ;
error = ( V_248 & V_244 )
? true : false ;
F_107 ( V_6 , V_188 , error ) ;
F_13 ( V_239 , V_245 -> V_252 ) ;
} while ( ( V_239 & 0xFFF ) !=
( V_246 & 0xFFF ) );
}
F_13 ( V_355 ,
V_245 -> V_356 ) ;
F_12 ( V_245 -> V_356 ) ;
F_104 ( & V_6 -> V_155 , V_31 ) ;
}
static void F_155 ( struct V_5 * V_6 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_49 , & V_46 -> V_48 ) ;
F_156 ( & V_6 -> V_100 ) ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
F_13 ( V_54 , V_46 -> V_52 ) ;
F_156 ( & V_6 -> V_100 ) ;
}
static void F_148 ( struct V_5 * V_6 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
F_13 ( V_27 , & V_46 -> V_28 ) ;
F_156 ( & V_6 -> V_100 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_60 * V_46 = V_6 -> V_61 ;
F_13 ( V_62 , V_46 -> V_25 ) ;
F_12 ( V_46 -> V_25 ) ;
F_156 ( & V_6 -> V_100 ) ;
}
static int F_158 ( struct V_5 * V_6 )
{
T_6 V_48 ;
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_232 ;
if ( ! ( V_48 & V_357 ) )
return V_358 ;
do {
F_13 ( V_48 , & V_46 -> V_48 ) ;
if ( V_48 & V_359 )
F_146 ( V_6 ) ;
if ( V_48 & V_360 )
F_151 ( V_6 ) ;
if ( V_48 & V_49 )
F_155 ( V_6 ) ;
V_48 = F_12 ( & V_46 -> V_48 ) &
V_6 -> V_232 ;
} while ( V_48 & ( V_359
| V_360
| V_49 ) );
return V_361 ;
}
static int F_159 ( struct V_5 * V_6 )
{
T_6 V_25 ;
struct V_50 * V_46 = V_6 -> V_51 ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_232 ;
if ( ! V_25 )
return V_358 ;
do {
F_13 ( ~ V_25 , V_46 -> V_52 ) ;
F_13 ( V_55 , V_46 -> V_56 ) ;
if ( V_25 & V_260 )
F_141 ( V_6 ) ;
if ( V_25 & V_261 )
F_145 ( V_6 ) ;
if ( V_25 & V_262 )
F_152 ( V_6 ) ;
if ( V_25 & V_53 )
F_157 ( V_6 ) ;
V_25 = F_12 ( V_46 -> V_52 ) &
V_6 -> V_232 ;
} while ( V_25 & ( V_260
| V_261
| V_262
| V_53 ) );
return V_361 ;
}
static int F_160 ( struct V_5 * V_57 )
{
T_6 V_362 ;
struct V_58 T_1 * V_59 = V_57 -> V_24 ;
V_362 = F_12 ( & V_59 -> V_241 ) &
( V_242 |
V_363 ) ;
if ( ! V_362 )
return V_358 ;
do {
if ( V_362 & V_363 )
F_147 ( V_57 ) ;
if ( V_362 & V_242 )
F_153 ( V_57 ) ;
V_362 = F_12 ( & V_59 -> V_241 ) ;
} while ( V_362 & ( V_242 |
V_363 ) );
return V_361 ;
}
static T_2 F_161 ( struct V_5 * V_57 )
{
T_8 V_362 ;
struct V_60 * V_245 = V_57 -> V_61 ;
V_362 = F_12 ( V_245 -> V_241 ) &
( V_364 |
V_365 ) ;
if ( ! V_362 )
return V_358 ;
do {
if ( V_362 &
V_364 )
F_154 ( V_57 ) ;
if ( V_362 &
V_365 )
F_149 ( V_57 ) ;
V_362 = F_12 ( V_245 -> V_241 ) ;
} while ( V_362 &
( V_364 |
V_365 ) );
return V_361 ;
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
return V_358 ;
}
}
static void F_162 ( struct V_5 * V_6 )
{
if ( V_6 ) {
if ( V_6 -> V_122 & V_311 ) {
T_6 V_180 ;
V_6 -> V_122 &= ~ V_311 ;
V_180 = F_87 ( V_6 ) ;
F_78 ( V_6 ) ;
F_32 ( V_6 ) ;
F_118 ( V_6 , V_180 ) ;
}
}
}
void F_163 ( struct V_5 * V_6 )
{
T_6 V_47 ;
if ( V_6 -> V_122 & V_340 ) {
for ( V_47 = 0 ; V_47 < 15 ; V_47 ++ ) {
if ( V_6 -> V_122 & V_340 ) {
V_6 -> V_122 &= ~ V_340 ;
V_6 -> V_339 = 0 ;
V_6 -> V_336 = 0 ;
F_134 ( V_6 ) ;
F_110 ( 30 ) ;
} else if ( V_6 -> V_339 !=
V_6 -> V_336 ) {
V_6 -> V_339 = 0 ;
V_6 -> V_336 = 0 ;
F_110 ( 30 ) ;
} else
break;
}
}
}
static int F_164 ( struct V_5 * V_6 ,
struct V_189 * V_366 )
{
char * V_44 ;
unsigned short V_367 ;
int V_368 = 0 , V_369 = 0 ;
unsigned long V_31 ;
struct V_370 * V_371 ;
T_6 V_372 = ( T_6 ) V_366 -> V_281 [ 5 ] << 24 |
( T_6 ) V_366 -> V_281 [ 6 ] << 16 |
( T_6 ) V_366 -> V_281 [ 7 ] << 8 |
( T_6 ) V_366 -> V_281 [ 8 ] ;
struct V_273 * V_274 ;
V_367 = F_165 ( V_366 ) ;
V_274 = F_166 ( V_366 ) ;
V_44 = F_167 ( F_168 ( V_274 ) ) + V_274 -> V_373 ;
if ( V_367 > 1 ) {
V_368 = V_374 ;
goto V_375;
}
V_369 += V_274 -> V_272 ;
if ( V_369 > sizeof( struct V_370 ) ) {
V_368 = V_374 ;
F_53 ( L_26 , V_182 ) ;
goto V_375;
}
V_371 = (struct V_370 * ) V_44 ;
switch ( V_372 ) {
case V_376 : {
unsigned char * V_377 ;
T_4 * V_378 ;
T_6 V_342 = 0 ;
V_377 = F_139 ( V_379 , V_334 ) ;
if ( ! V_377 ) {
V_368 = V_374 ;
F_53 ( L_27 , V_182 ) ;
goto V_375;
}
V_378 = V_377 ;
F_103 ( & V_6 -> V_156 , V_31 ) ;
if ( V_6 -> V_339 != V_6 -> V_336 ) {
unsigned int V_380 = V_6 -> V_339 ;
unsigned int V_381 = V_6 -> V_336 ;
unsigned int V_382 = F_169 ( V_381 , V_380 , V_337 ) ;
V_342 = F_170 ( V_381 , V_380 , V_337 ) ;
if ( V_342 > V_379 )
V_342 = V_379 ;
if ( V_342 <= V_382 )
memcpy ( V_378 , V_6 -> V_335 + V_380 , V_342 ) ;
else {
memcpy ( V_378 , V_6 -> V_335 + V_380 , V_382 ) ;
memcpy ( V_378 + V_382 , V_6 -> V_335 , V_342 - V_382 ) ;
}
V_6 -> V_339 = ( V_6 -> V_339 + V_342 ) % V_337 ;
}
memcpy ( V_371 -> V_383 , V_377 ,
V_342 ) ;
if ( V_6 -> V_122 & V_340 ) {
struct V_322 T_1 * V_327 ;
V_6 -> V_122 &= ~ V_340 ;
V_327 = F_136 ( V_6 ) ;
if ( F_140 ( V_6 , V_327 ) == 0 )
V_6 -> V_122 |= V_340 ;
}
F_104 ( & V_6 -> V_156 , V_31 ) ;
F_22 ( V_377 ) ;
V_371 -> V_384 . V_385 = V_342 ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
break;
}
case V_390 : {
unsigned char * V_377 ;
T_12 V_391 , V_392 ;
T_4 * V_328 , * V_393 ;
V_377 = F_139 ( V_379 , V_334 ) ;
if ( ! V_377 ) {
V_368 = V_374 ;
goto V_375;
}
V_393 = V_377 ;
V_391 = V_371 -> V_384 . V_385 ;
memcpy ( V_393 ,
V_371 -> V_383 , V_391 ) ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
if ( V_6 -> V_344 != V_6 -> V_343 ) {
struct V_195 * V_196 =
(struct V_195 * ) V_366 -> V_197 ;
F_143 ( V_6 ) ;
V_196 -> V_203 = V_204 ;
V_196 -> V_394 = V_395 ;
V_196 -> V_396 = 0x0A ;
V_196 -> V_397 = 0x20 ;
V_196 -> V_205 = 1 ;
V_368 = V_374 ;
} else {
V_328 = & V_6 -> V_345 [ V_6 -> V_344 ] ;
V_392 = V_337 - V_6 -> V_344 ;
if ( V_391 > V_392 ) {
memcpy ( V_328 , V_393 , V_392 ) ;
V_393 += V_392 ;
V_391 -= V_392 ;
V_6 -> V_344 = 0 ;
V_328 = V_6 -> V_345 ;
}
memcpy ( V_328 , V_393 , V_391 ) ;
V_6 -> V_344 += V_391 ;
V_6 -> V_344 %= V_337 ;
if ( V_6 -> V_122 & V_158 ) {
V_6 -> V_122 &=
~ V_158 ;
F_143 ( V_6 ) ;
}
}
F_104 ( & V_6 -> V_157 , V_31 ) ;
F_22 ( V_377 ) ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
break;
}
case V_398 : {
T_4 * V_328 = V_6 -> V_335 ;
F_163 ( V_6 ) ;
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_6 -> V_122 |= V_159 ;
V_6 -> V_339 = 0 ;
V_6 -> V_336 = 0 ;
memset ( V_328 , 0 , V_337 ) ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
break;
}
case V_399 : {
T_4 * V_328 = V_6 -> V_345 ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_6 -> V_122 |= ( V_158 |
V_160 ) ;
V_6 -> V_343 = 0 ;
V_6 -> V_344 = 0 ;
memset ( V_328 , 0 , V_337 ) ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
break;
}
case V_400 : {
T_4 * V_328 ;
F_163 ( V_6 ) ;
F_103 ( & V_6 -> V_156 , V_31 ) ;
V_6 -> V_122 |= V_159 ;
V_6 -> V_339 = 0 ;
V_6 -> V_336 = 0 ;
V_328 = V_6 -> V_335 ;
memset ( V_328 , 0 , sizeof( struct V_322 ) ) ;
F_104 ( & V_6 -> V_156 , V_31 ) ;
F_103 ( & V_6 -> V_157 , V_31 ) ;
V_6 -> V_122 |= ( V_158 |
V_160 ) ;
V_6 -> V_343 = 0 ;
V_6 -> V_344 = 0 ;
V_328 = V_6 -> V_345 ;
memset ( V_328 , 0 , sizeof( struct V_322 ) ) ;
F_104 ( & V_6 -> V_157 , V_31 ) ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
break;
}
case V_401 : {
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_402 ;
break;
}
case V_403 : {
T_9 * V_404 = L_28 ;
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
memcpy ( V_371 -> V_383 ,
V_404 , ( V_405 ) strlen ( V_404 ) ) ;
break;
}
case V_406 : {
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
F_162 ( V_6 ) ;
break;
}
case V_407 : {
if ( V_6 -> V_169 == V_386 )
V_371 -> V_384 . V_387 =
V_388 ;
else
V_371 -> V_384 . V_387 =
V_389 ;
F_32 ( V_6 ) ;
break;
}
default:
V_368 = V_374 ;
F_53 ( L_29 , V_182 ) ;
}
V_375:
if ( V_367 ) {
struct V_273 * V_274 = F_166 ( V_366 ) ;
F_171 ( V_44 - V_274 -> V_373 ) ;
}
return V_368 ;
}
static struct V_71 * F_172 ( struct V_5 * V_6 )
{
struct V_408 * V_381 = & V_6 -> V_97 ;
struct V_71 * V_188 = NULL ;
unsigned long V_31 ;
F_103 ( & V_6 -> V_153 , V_31 ) ;
if ( ! F_173 ( V_381 ) ) {
V_188 = F_174 ( V_381 -> V_409 , struct V_71 , V_96 ) ;
F_175 ( & V_188 -> V_96 ) ;
} else{
F_104 ( & V_6 -> V_153 , V_31 ) ;
return NULL ;
}
F_104 ( & V_6 -> V_153 , V_31 ) ;
return V_188 ;
}
static void F_176 ( struct V_5 * V_6 ,
struct V_189 * V_366 )
{
switch ( V_366 -> V_281 [ 0 ] ) {
case V_410 : {
unsigned char V_411 [ 36 ] ;
char * V_44 ;
struct V_273 * V_274 ;
if ( V_366 -> V_214 -> V_106 ) {
V_366 -> V_198 = ( V_412 << 16 ) ;
V_366 -> V_194 ( V_366 ) ;
return;
}
V_411 [ 0 ] = V_413 ;
V_411 [ 1 ] = 0 ;
V_411 [ 2 ] = 0 ;
V_411 [ 4 ] = 31 ;
strncpy ( & V_411 [ 8 ] , L_30 , 8 ) ;
strncpy ( & V_411 [ 16 ] , L_31 , 16 ) ;
strncpy ( & V_411 [ 32 ] , L_32 , 4 ) ;
V_274 = F_166 ( V_366 ) ;
V_44 = F_167 ( F_168 ( V_274 ) ) + V_274 -> V_373 ;
memcpy ( V_44 , V_411 , sizeof( V_411 ) ) ;
V_274 = F_166 ( V_366 ) ;
F_171 ( V_44 - V_274 -> V_373 ) ;
V_366 -> V_194 ( V_366 ) ;
}
break;
case V_414 :
case V_415 : {
if ( F_164 ( V_6 , V_366 ) )
V_366 -> V_198 = ( V_416 << 16 ) ;
V_366 -> V_194 ( V_366 ) ;
}
break;
default:
V_366 -> V_194 ( V_366 ) ;
}
}
static int F_177 ( struct V_189 * V_366 ,
void (* F_178)( struct V_189 * ) )
{
struct V_131 * V_19 = V_366 -> V_214 -> V_19 ;
struct V_5 * V_6 = (struct V_5 * ) V_19 -> V_142 ;
struct V_71 * V_188 ;
int V_105 = V_366 -> V_214 -> V_130 ;
int V_106 = V_366 -> V_214 -> V_106 ;
T_4 V_417 = V_366 -> V_281 [ 0 ] ;
V_366 -> V_194 = F_178 ;
V_366 -> V_418 = NULL ;
V_366 -> V_198 = 0 ;
if ( ( V_417 == V_419 ) || ( V_417 == V_420 ) ) {
if( V_6 -> V_80 [ V_105 ] [ V_106 ] == V_81 ) {
V_366 -> V_198 = ( V_218 << 16 ) ;
}
V_366 -> V_194 ( V_366 ) ;
return 0 ;
}
if ( V_105 == 16 ) {
F_176 ( V_6 , V_366 ) ;
return 0 ;
}
V_188 = F_172 ( V_6 ) ;
if ( ! V_188 )
return V_421 ;
if ( F_119 ( V_6 , V_188 , V_366 ) == V_128 ) {
V_366 -> V_198 = ( V_416 << 16 ) | ( V_422 << 1 ) ;
V_366 -> V_194 ( V_366 ) ;
return 0 ;
}
F_129 ( V_6 , V_188 ) ;
return 0 ;
}
bool F_179 ( struct V_5 * V_6 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_15 * V_10 = V_6 -> V_10 ;
void * V_69 ;
T_5 V_70 ;
char * V_423 = V_6 -> V_424 ;
char * V_425 = V_6 -> V_426 ;
char * V_427 = V_6 -> V_102 ;
char T_1 * V_428 ;
char T_1 * V_429 ;
char T_1 * V_430 ;
int V_431 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_50 ) , 32 ) ;
V_69 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_70 , V_91 ) ;
if ( ! V_69 ) {
F_9 ( V_18
L_33 ,
V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_6 -> V_14 = V_70 ;
V_6 -> V_13 = V_69 ;
V_46 = (struct V_50 * ) V_69 ;
V_6 -> V_51 = V_46 ;
V_46 -> V_56 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_432 ) ;
V_46 -> V_433 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_434 ) ;
V_46 -> V_52 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_435 ) ;
V_46 -> V_209 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_21 + V_436 ) ;
V_46 -> V_326 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_437 ) ;
V_46 -> V_324 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_438 ) ;
V_46 -> V_110 = ( T_6 T_1 * ) ( ( unsigned long ) V_6 -> V_22 + V_439 ) ;
V_428 = ( char T_1 * ) ( & V_46 -> V_110 [ 15 ] ) ;
V_429 = ( char T_1 * ) ( & V_46 -> V_110 [ 17 ] ) ;
V_430 = ( char T_1 * ) ( & V_46 -> V_110 [ 21 ] ) ;
F_13 ( V_440 , V_46 -> V_56 ) ;
if ( ! F_25 ( V_6 ) ) {
F_9 ( V_18 L_34 , V_6 -> V_19 -> V_20 ) ;
return false ;
}
V_431 = 8 ;
while ( V_431 ) {
* V_423 = F_42 ( V_428 ) ;
V_423 ++ ;
V_428 ++ ;
V_431 -- ;
}
V_431 = 16 ;
while ( V_431 ) {
* V_425 = F_42 ( V_429 ) ;
V_425 ++ ;
V_429 ++ ;
V_431 -- ;
}
V_431 = 16 ;
while( V_431 ) {
* V_427 = F_42 ( V_430 ) ;
V_427 ++ ;
V_430 ++ ;
V_431 -- ;
}
F_15 ( L_35 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_424 ,
V_6 -> V_426 ) ;
V_6 -> V_103 = F_12 ( & V_46 -> V_110 [ 1 ] ) ;
V_6 -> V_441 = F_12 ( & V_46 -> V_110 [ 2 ] ) ;
V_6 -> V_442 = F_12 ( & V_46 -> V_110 [ 3 ] ) ;
V_6 -> V_443 = F_12 ( & V_46 -> V_110 [ 4 ] ) ;
V_6 -> V_444 = F_12 ( & V_46 -> V_110 [ 5 ] ) ;
V_6 -> V_84 = F_12 ( & V_46 -> V_110 [ 25 ] ) ;
return true ;
}
static bool F_180 ( struct V_5 * V_57 )
{
T_6 V_180 , V_445 , V_446 = 0 ;
struct V_58 T_1 * V_46 = V_57 -> V_24 ;
char * V_423 = V_57 -> V_424 ;
char * V_425 = V_57 -> V_426 ;
char T_1 * V_428 = ( char T_1 * ) ( & V_46 -> V_111 [ 15 ] ) ;
char T_1 * V_429 = ( char T_1 * ) ( & V_46 -> V_111 [ 17 ] ) ;
int V_431 ;
V_180 = F_12 ( & V_46 -> V_210 ) ;
F_13 ( V_180 | V_211 , & V_46 -> V_210 ) ;
do {
V_446 = F_12 ( & V_46 -> V_447 ) ;
} while ( ( V_446 & V_448 ) == 0 );
F_13 ( V_449 , & V_46 -> V_65 ) ;
F_13 ( V_67 , & V_46 -> V_68 ) ;
for ( V_445 = 0 ; V_445 < 2000 ; V_445 ++ ) {
if ( F_12 ( & V_46 -> V_25 ) & V_26 ) {
F_13 ( V_27 , & V_46 -> V_28 ) ;
break;
}
F_181 ( 10 ) ;
}
if ( V_445 >= 2000 ) {
F_9 ( V_18 L_34 , V_57 -> V_19 -> V_20 ) ;
return false ;
}
V_431 = 8 ;
while ( V_431 ) {
* V_423 = F_42 ( V_428 ) ;
V_423 ++ ;
V_428 ++ ;
V_431 -- ;
}
V_431 = 16 ;
while ( V_431 ) {
* V_425 = F_42 ( V_429 ) ;
V_425 ++ ;
V_429 ++ ;
V_431 -- ;
}
F_15 ( L_35 ,
V_57 -> V_19 -> V_20 ,
V_57 -> V_424 ,
V_57 -> V_426 ) ;
V_57 -> V_441 = F_12 ( & V_46 -> V_111 [ 1 ] ) ;
V_57 -> V_442 = F_12 ( & V_46 -> V_111 [ 2 ] ) ;
V_57 -> V_443 = F_12 ( & V_46 -> V_111 [ 3 ] ) ;
V_57 -> V_444 = F_12 ( & V_46 -> V_111 [ 4 ] ) ;
V_57 -> V_84 = F_12 ( & V_46 -> V_111 [ 25 ] ) ;
return true ;
}
static bool F_182 ( struct V_5 * V_6 )
{
char * V_423 = V_6 -> V_424 ;
char * V_425 = V_6 -> V_426 ;
char * V_427 = V_6 -> V_102 ;
char T_1 * V_428 ;
char T_1 * V_429 ;
char T_1 * V_430 ;
T_8 V_431 ;
struct V_60 * V_46 ;
void * V_13 ;
T_5 V_14 ;
struct V_15 * V_10 = V_6 -> V_10 ;
V_6 -> V_12 = F_34 ( sizeof( struct V_60 ) , 32 ) ;
V_13 = F_35 ( & V_10 -> V_11 , V_6 -> V_12 ,
& V_14 , V_91 ) ;
if ( ! V_13 ) {
F_15 ( L_36 ) ;
return false ;
}
memset ( V_13 , 0 , V_6 -> V_12 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_13 = V_13 ;
V_46 = (struct V_60 * ) V_13 ;
V_6 -> V_61 = V_46 ;
V_46 -> V_450 = V_6 -> V_21 + V_451 ;
V_46 -> V_452 = V_6 -> V_21 +
V_453 ;
V_46 -> V_454 = V_6 -> V_21 +
V_455 ;
V_46 -> V_456 = V_6 -> V_21 + V_457 ;
V_46 -> V_458 = V_6 -> V_21 + V_459 ;
V_46 -> V_241 = V_6 -> V_21 +
V_460 ;
V_46 -> V_213 = V_6 -> V_21 +
V_461 ;
V_46 -> V_65 = V_6 -> V_21 +
V_462 ;
V_46 -> V_463 = V_6 -> V_21 +
V_464 ;
V_46 -> V_465 = V_6 -> V_21 +
V_466 ;
V_46 -> V_447 = V_6 -> V_21 +
V_467 ;
V_46 -> V_68 = V_6 -> V_21 +
V_468 ;
V_46 -> V_25 = V_6 -> V_21 +
V_469 ;
V_46 -> V_470 = V_6 -> V_21 +
V_471 ;
V_46 -> V_472 = V_6 -> V_21 +
V_473 ;
V_46 -> V_474 = V_6 -> V_21 +
V_475 ;
V_46 -> V_310 = V_6 -> V_21 +
V_476 ;
V_46 -> V_477 = V_6 -> V_21 +
V_478 ;
V_46 -> V_479 = V_6 -> V_21 +
V_480 ;
V_46 -> V_481 = V_6 -> V_21 +
V_482 ;
V_46 -> V_252 = V_6 -> V_21 +
V_483 ;
V_46 -> V_356 = V_6 -> V_21 +
V_484 ;
V_46 -> V_485 = V_6 -> V_21 +
V_486 ;
V_46 -> V_326 = V_6 -> V_21 + V_487 ;
V_46 -> V_324 = V_6 -> V_21 + V_488 ;
V_46 -> V_111 = V_6 -> V_21 +
V_489 ;
V_428 = ( char T_1 * ) ( & V_46 -> V_111 [ 15 ] ) ;
V_429 = ( char T_1 * ) ( & V_46 -> V_111 [ 17 ] ) ;
V_430 = ( char T_1 * ) ( & V_46 -> V_111 [ 21 ] ) ;
if ( F_12 ( V_6 -> V_61 -> V_25 ) &
V_62 ) {
F_13 ( V_62 ,
V_6 -> V_61 -> V_25 ) ;
}
F_13 ( V_449 , V_46 -> V_65 ) ;
if ( ! F_27 ( V_6 ) ) {
F_15 ( L_37
L_38 , V_6 -> V_19 -> V_20 ) ;
F_4 ( & V_6 -> V_10 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 , V_6 -> V_14 ) ;
return false ;
}
V_431 = 8 ;
while ( V_431 ) {
* V_423 = F_42 ( V_428 ) ;
V_423 ++ ;
V_428 ++ ;
V_431 -- ;
}
V_431 = 16 ;
while ( V_431 ) {
* V_425 = F_42 ( V_429 ) ;
V_425 ++ ;
V_429 ++ ;
V_431 -- ;
}
V_431 = 16 ;
while ( V_431 ) {
* V_427 = F_42 ( V_430 ) ;
V_427 ++ ;
V_430 ++ ;
V_431 -- ;
}
V_6 -> V_103 = F_12 ( & V_46 -> V_111 [ 1 ] ) ;
V_6 -> V_441 = F_12 ( & V_46 -> V_111 [ 2 ] ) ;
V_6 -> V_442 = F_12 ( & V_46 -> V_111 [ 3 ] ) ;
V_6 -> V_443 = F_12 ( & V_46 -> V_111 [ 4 ] ) ;
V_6 -> V_444 = F_12 ( & V_46 -> V_111 [ 5 ] ) ;
V_6 -> V_84 = F_12 ( & V_46 -> V_111 [ 25 ] ) ;
F_15 ( L_35 ,
V_6 -> V_19 -> V_20 ,
V_6 -> V_424 ,
V_6 -> V_426 ) ;
return true ;
}
static bool F_66 ( struct V_5 * V_6 )
{
bool V_490 = false ;
switch ( V_6 -> V_7 ) {
case V_16 :
V_490 = F_183 ( V_6 ) ;
break;
case V_8 :
V_490 = F_179 ( V_6 ) ;
break;
case V_23 :
V_490 = F_180 ( V_6 ) ;
break;
case V_9 :
V_490 = F_182 ( V_6 ) ;
break;
default:
break;
}
if ( V_6 -> V_442 > V_147 )
V_6 -> V_491 = V_147 ;
else
V_6 -> V_491 = V_6 -> V_442 - 1 ;
V_6 -> V_19 -> V_146 = V_6 -> V_491 ;
return V_490 ;
}
static int F_184 ( struct V_5 * V_6 ,
struct V_71 * V_492 )
{
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
struct V_71 * V_188 ;
struct V_230 * V_94 ;
T_6 V_228 , V_48 , V_493 = 0 , V_253 = 0 ;
int V_490 ;
bool error ;
V_494:
V_253 ++ ;
V_48 = F_12 ( & V_46 -> V_48 ) & V_6 -> V_232 ;
F_13 ( V_48 , & V_46 -> V_48 ) ;
while ( 1 ) {
if ( ( V_228 = F_12 ( & V_46 -> V_233 ) ) == 0xFFFFFFFF ) {
if ( V_493 ) {
V_490 = V_124 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_253 > 100 ) {
V_490 = V_128 ;
break;
}
goto V_494;
}
}
V_94 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_188 = F_40 ( V_94 , struct V_71 , V_94 ) ;
V_493 |= ( V_188 == V_492 ) ? 1 : 0 ;
if ( ( V_188 -> V_6 != V_6 ) || ( V_188 -> V_192 != V_224 ) ) {
if ( ( V_188 -> V_192 == V_225 ) || ( V_188 == V_492 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_188 -> V_190 -> V_214 -> V_130
, ( T_8 ) V_188 -> V_190 -> V_214 -> V_106
, V_188 ) ;
V_188 -> V_190 -> V_198 = V_227 << 16 ;
F_101 ( V_188 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_188
, F_108 ( & V_6 -> V_191 ) ) ;
continue;
}
error = ( V_228 & V_234 ) ? true : false ;
F_106 ( V_6 , V_188 , error ) ;
}
return V_490 ;
}
static int F_185 ( struct V_5 * V_6 ,
struct V_71 * V_492 )
{
struct V_50 * V_46 = V_6 -> V_51 ;
struct V_230 * V_94 ;
struct V_71 * V_188 ;
T_6 V_228 , V_493 = 0 , V_253 = 0 ;
int V_300 , V_490 ;
bool error ;
V_495:
V_253 ++ ;
F_13 ( V_235 , V_46 -> V_52 ) ;
while( 1 ) {
V_300 = V_46 -> V_239 ;
V_228 = V_46 -> V_237 [ V_300 ] ;
if ( V_228 == 0 ) {
if ( V_493 ) {
V_490 = V_124 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_253 > 100 ) {
V_490 = V_128 ;
break;
}
goto V_495;
}
}
V_46 -> V_237 [ V_300 ] = 0 ;
V_300 ++ ;
V_300 %= V_236 ;
V_46 -> V_239 = V_300 ;
V_94 = (struct V_230 * ) ( V_6 -> V_93 + ( V_228 << 5 ) ) ;
V_188 = F_40 ( V_94 , struct V_71 , V_94 ) ;
V_493 |= ( V_188 == V_492 ) ? 1 : 0 ;
if ( ( V_188 -> V_6 != V_6 ) || ( V_188 -> V_192 != V_224 ) ) {
if ( ( V_188 -> V_192 == V_225 ) || ( V_188 == V_492 ) ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_188 -> V_190 -> V_214 -> V_130
, ( T_8 ) V_188 -> V_190 -> V_214 -> V_106
, V_188 ) ;
V_188 -> V_190 -> V_198 = V_227 << 16 ;
F_101 ( V_188 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_188
, F_108 ( & V_6 -> V_191 ) ) ;
continue;
}
error = ( V_228 & V_234 ) ? true : false ;
F_106 ( V_6 , V_188 , error ) ;
}
return V_490 ;
}
static int F_186 ( struct V_5 * V_6 ,
struct V_71 * V_492 )
{
struct V_58 T_1 * V_46 = V_6 -> V_24 ;
T_6 V_228 , V_229 ;
struct V_230 * V_94 ;
bool error ;
struct V_71 * V_223 ;
T_6 V_493 = 0 , V_253 = 0 ;
int V_490 ;
V_496:
V_253 ++ ;
while ( 1 ) {
if ( ( F_12 ( & V_46 -> V_241 ) & V_242 ) == 0 ) {
if ( V_493 ) {
V_490 = V_124 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_253 > 100 ) {
V_490 = V_128 ;
break;
}
goto V_496;
}
}
V_228 = F_12 ( & V_46 -> V_243 ) ;
V_229 = ( V_228 & 0xFFFFFFF0 ) ;
V_94 = (struct V_230 * ) ( V_6 -> V_93 + V_229 ) ;
V_223 = F_40 ( V_94 , struct V_71 , V_94 ) ;
V_493 |= ( V_223 == V_492 ) ? 1 : 0 ;
if ( ( V_223 -> V_6 != V_6 ) || ( V_223 -> V_192 != V_224 ) ) {
if ( V_223 -> V_192 == V_225 ) {
F_9 ( V_18 L_39
L_40
, V_6 -> V_19 -> V_20
, V_223 -> V_190 -> V_214 -> V_130
, ( T_8 ) V_223 -> V_190 -> V_214 -> V_106
, V_223 ) ;
V_223 -> V_190 -> V_198 = V_227 << 16 ;
F_101 ( V_223 ) ;
continue;
}
F_9 ( V_18 L_41
L_42
L_43
, V_6 -> V_19 -> V_20
, V_223
, F_108 ( & V_6 -> V_191 ) ) ;
continue;
}
error = ( V_228 & V_244 ) ? true : false ;
F_106 ( V_6 , V_223 , error ) ;
}
return V_490 ;
}
static int F_187 ( struct V_5 * V_6 ,
struct V_71 * V_492 )
{
bool error ;
T_6 V_493 = 0 , V_253 = 0 , V_228 , V_229 ;
int V_490 , V_239 , V_247 , V_246 , V_250 ;
unsigned long V_31 ;
struct V_230 * V_94 ;
struct V_71 * V_223 ;
struct V_60 * V_245 = V_6 -> V_61 ;
V_497:
V_253 ++ ;
while ( 1 ) {
F_103 ( & V_6 -> V_155 , V_31 ) ;
V_246 = V_245 -> V_237 [ 0 ] . V_248 + 1 ;
V_239 = V_245 -> V_239 ;
if ( ( V_246 & 0xFFF ) == ( V_239 & 0xFFF ) ) {
F_104 ( & V_6 -> V_155 , V_31 ) ;
if ( V_493 ) {
V_490 = V_124 ;
break;
} else {
F_24 ( 25 ) ;
if ( V_253 > 40 ) {
V_490 = V_128 ;
break;
}
goto V_497;
}
}
V_250 = V_239 & 0x4000 ;
V_247 = ( V_239 & 0xFFF ) + 1 ;
V_247 %= V_251 ;
V_245 -> V_239 = V_247 ? ( V_247 | V_250 ) :
( ( V_250 ^ 0x4000 ) + 1 ) ;
V_239 = V_245 -> V_239 ;
F_104 ( & V_6 -> V_155 , V_31 ) ;
V_228 = V_245 -> V_237 [ V_239 & 0xFFF ] . V_248 ;
V_229 = ( V_228 & 0xFFFFFFF0 ) ;
V_94 = (struct V_230 * ) ( V_6 -> V_93 +
V_229 ) ;
V_223 = F_40 ( V_94 , struct V_71 ,
V_94 ) ;
V_493 |= ( V_223 == V_492 ) ? 1 : 0 ;
if ( ( V_223 -> V_6 != V_6 ) ||
( V_223 -> V_192 != V_224 ) ) {
if ( V_223 -> V_192 == V_225 ) {
F_15 ( L_44
L_45
L_46
, V_6 -> V_19 -> V_20
, V_223 -> V_190 -> V_214 -> V_130
, ( T_8 ) V_223 -> V_190 -> V_214 -> V_106
, V_223 ) ;
V_223 -> V_190 -> V_198 = V_227 << 16 ;
F_101 ( V_223 ) ;
continue;
}
F_15 ( L_47
L_48
L_49
, V_6 -> V_19 -> V_20
, V_223
, F_108 ( & V_6 -> V_191 ) ) ;
continue;
}
error = ( V_228 & V_244 )
? true : false ;
F_106 ( V_6 , V_223 , error ) ;
}
return V_490 ;
}
static int F_188 ( struct V_5 * V_6 ,
struct V_71 * V_492 )
{
int V_490 = 0 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
V_490 = F_184 ( V_6 , V_492 ) ;
}
break;
case V_8 : {
V_490 = F_185 ( V_6 , V_492 ) ;
}
break;
case V_23 : {
V_490 = F_186 ( V_6 , V_492 ) ;
}
break;
case V_9 :
V_490 = F_187 ( V_6 , V_492 ) ;
break;
}
return V_490 ;
}
static int F_189 ( struct V_5 * V_6 )
{
T_6 V_74 , V_303 ;
T_5 V_70 ;
switch ( V_6 -> V_7 ) {
case V_8 :
case V_9 :
V_70 = V_6 -> V_14 ;
break;
default:
V_70 = V_6 -> V_70 ;
break;
}
V_74 = F_190 ( V_70 ) ;
V_303 = F_191 ( V_70 ) ;
V_6 -> V_303 = V_303 ;
switch ( V_6 -> V_7 ) {
case V_16 : {
if ( V_303 != 0 ) {
struct V_45 T_1 * V_46 = V_6 -> V_17 ;
F_13 ( V_498 , \
& V_46 -> V_110 [ 0 ] ) ;
F_13 ( V_303 , & V_46 -> V_110 [ 1 ] ) ;
F_13 ( V_499 , \
& V_46 -> V_65 ) ;
if ( ! F_23 ( V_6 ) ) {
F_9 (KERN_NOTICE L_50set ccb high \
part physical address timeout\nL_51arcmsr%d: cannot set driver mode\nL_52set configL_53arcmsr%d: 'set command Q window' \
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
