static void F_1 ( int V_1 )
{
struct V_2 V_3 = { V_4 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_9 , & V_3 ) == - 1 ) {
F_4 ( V_10 , L_1 , V_1 ) ;
exit ( - 1 ) ;
}
}
static void F_5 ( int V_1 )
{
struct V_2 V_3 = { V_11 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_12 , & V_3 ) == - 1 ) {
perror ( L_2 ) ;
F_4 ( V_10 , L_3 , V_1 ) ;
exit ( - 1 ) ;
}
}
static void F_6 ( int V_1 )
{
T_1 * V_13 ;
T_2 V_14 ;
F_1 ( V_1 ) ;
V_13 = fopen ( V_7 [ V_1 ] . V_15 , L_4 ) ;
if ( ! V_13 ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_5 , V_1 ) ;
exit ( - 1 ) ;
}
V_14 = fwrite ( V_7 [ V_1 ] . V_16 ,
sizeof( struct V_17 ) ,
V_7 [ V_1 ] . V_18 , V_13 ) ;
fflush ( V_13 ) ;
F_5 ( V_1 ) ;
}
static void F_7 ( int V_1 )
{
T_1 * V_13 ;
T_2 V_19 = 0 ;
struct V_17 * V_20 = V_7 [ V_1 ] . V_16 ;
struct V_17 * V_21 ;
int V_22 = V_7 [ V_1 ] . V_22 ;
int V_23 = sizeof( struct V_17 ) * V_24 ;
F_1 ( V_1 ) ;
V_13 = fopen ( V_7 [ V_1 ] . V_15 , L_6 ) ;
if ( ! V_13 ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_5 , V_1 ) ;
exit ( - 1 ) ;
}
while ( ! feof ( V_13 ) ) {
V_21 = & V_20 [ V_19 ] ;
V_19 += fread ( V_21 , sizeof( struct V_17 ) ,
V_24 * V_22 ,
V_13 ) ;
if ( ! feof ( V_13 ) ) {
V_22 ++ ;
V_20 = realloc ( V_20 , V_23 * V_22 ) ;
if ( V_20 == NULL ) {
F_4 ( V_10 , L_7 ) ;
exit ( - 1 ) ;
}
continue;
}
break;
}
V_7 [ V_1 ] . V_22 = V_22 ;
V_7 [ V_1 ] . V_16 = V_20 ;
V_7 [ V_1 ] . V_18 = V_19 ;
F_5 ( V_1 ) ;
}
static int F_8 ( void )
{
int V_25 , V_8 ;
T_1 * V_13 ;
T_2 V_19 ;
T_3 * V_15 ;
struct V_17 * V_20 ;
struct V_17 * V_21 ;
int V_22 ;
int V_26 ;
int V_23 = sizeof( struct V_17 ) * V_24 ;
if ( F_9 ( L_8 , V_27 ) ) {
if ( F_10 ( L_8 , V_28 | V_29 | V_30 ) ) {
F_4 ( V_10 , L_9 ) ;
exit ( - 1 ) ;
}
}
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ ) {
V_15 = V_7 [ V_26 ] . V_15 ;
V_19 = 0 ;
V_22 = 1 ;
sprintf ( V_15 , L_10 , V_26 ) ;
V_8 = F_11 ( V_15 , V_32 | V_33 , V_28 | V_29 | V_30 ) ;
if ( V_8 == - 1 )
return 1 ;
V_13 = fopen ( V_15 , L_6 ) ;
if ( ! V_13 )
return 1 ;
V_20 = malloc ( V_23 * V_22 ) ;
if ( V_20 == NULL ) {
fclose ( V_13 ) ;
return 1 ;
}
while ( ! feof ( V_13 ) ) {
V_21 = & V_20 [ V_19 ] ;
V_19 += fread ( V_21 , sizeof( struct V_17 ) ,
V_24 ,
V_13 ) ;
if ( ! feof ( V_13 ) ) {
V_22 ++ ;
V_20 = realloc ( V_20 , V_23 *
V_22 ) ;
if ( V_20 == NULL ) {
fclose ( V_13 ) ;
return 1 ;
}
continue;
}
break;
}
V_7 [ V_26 ] . V_8 = V_8 ;
V_7 [ V_26 ] . V_22 = V_22 ;
V_7 [ V_26 ] . V_16 = V_20 ;
V_7 [ V_26 ] . V_18 = V_19 ;
fclose ( V_13 ) ;
}
return 0 ;
}
static int F_12 ( int V_1 , T_3 * V_34 , int V_35 )
{
int V_26 ;
int V_36 , V_37 ;
int V_18 ;
struct V_17 * V_20 ;
F_7 ( V_1 ) ;
V_18 = V_7 [ V_1 ] . V_18 ;
V_20 = V_7 [ V_1 ] . V_16 ;
for ( V_26 = 0 ; V_26 < V_18 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_20 [ V_26 ] . V_34 , V_35 ) )
continue;
if ( V_26 == V_18 ) {
V_7 [ V_1 ] . V_18 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
V_36 = V_26 ;
V_37 = V_36 + 1 ;
for (; V_37 < V_18 ; V_37 ++ ) {
strcpy ( V_20 [ V_36 ] . V_34 , V_20 [ V_37 ] . V_34 ) ;
strcpy ( V_20 [ V_36 ] . V_38 , V_20 [ V_37 ] . V_38 ) ;
V_36 ++ ;
}
V_7 [ V_1 ] . V_18 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
return 1 ;
}
static int F_13 ( int V_1 , T_3 * V_34 , int V_35 , T_3 * V_38 ,
int V_39 )
{
int V_26 ;
int V_36 , V_37 ;
int V_18 ;
struct V_17 * V_20 ;
int V_22 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_18 = V_7 [ V_1 ] . V_18 ;
V_20 = V_7 [ V_1 ] . V_16 ;
V_22 = V_7 [ V_1 ] . V_22 ;
for ( V_26 = 0 ; V_26 < V_18 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_20 [ V_26 ] . V_34 , V_35 ) )
continue;
memcpy ( V_20 [ V_26 ] . V_38 , V_38 , V_39 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
if ( V_18 == ( V_24 * V_22 ) ) {
V_20 = realloc ( V_20 , sizeof( struct V_17 ) *
V_24 * ( V_22 + 1 ) ) ;
if ( V_20 == NULL )
return 1 ;
V_7 [ V_1 ] . V_22 ++ ;
}
memcpy ( V_20 [ V_26 ] . V_38 , V_38 , V_39 ) ;
memcpy ( V_20 [ V_26 ] . V_34 , V_34 , V_35 ) ;
V_7 [ V_1 ] . V_16 = V_20 ;
V_7 [ V_1 ] . V_18 ++ ;
F_6 ( V_1 ) ;
return 0 ;
}
static int F_14 ( int V_1 , T_3 * V_34 , int V_35 , T_3 * V_38 ,
int V_39 )
{
int V_26 ;
int V_18 ;
struct V_17 * V_20 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_18 = V_7 [ V_1 ] . V_18 ;
V_20 = V_7 [ V_1 ] . V_16 ;
for ( V_26 = 0 ; V_26 < V_18 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_20 [ V_26 ] . V_34 , V_35 ) )
continue;
memcpy ( V_38 , V_20 [ V_26 ] . V_38 , V_39 ) ;
return 0 ;
}
return 1 ;
}
static void F_15 ( int V_1 , int V_42 , T_3 * V_34 , int V_35 ,
T_3 * V_38 , int V_39 )
{
struct V_17 * V_20 ;
F_7 ( V_1 ) ;
V_20 = V_7 [ V_1 ] . V_16 ;
if ( V_42 >= V_7 [ V_1 ] . V_18 ) {
strcpy ( V_38 , L_11 ) ;
return;
}
memcpy ( V_34 , V_20 [ V_42 ] . V_34 , V_35 ) ;
memcpy ( V_38 , V_20 [ V_42 ] . V_38 , V_39 ) ;
}
void F_16 ( void )
{
T_1 * V_43 ;
char * V_44 , V_45 [ 512 ] ;
F_17 ( & V_46 ) ;
V_47 = V_46 . V_48 ;
V_49 = V_46 . V_50 ;
V_44 = strchr ( V_47 , '-' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_43 = fopen ( L_12 , L_6 ) ;
if ( V_43 != NULL )
goto V_51;
V_43 = fopen ( L_13 , L_6 ) ;
if ( V_43 != NULL )
goto V_51;
V_52 = V_46 . V_53 ;
return;
V_51:
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_54;
V_52 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_54;
V_55 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( V_44 )
V_56 = V_44 ;
}
}
}
V_54:
fclose ( V_43 ) ;
return;
}
static int
F_19 ( int V_57 , char * V_58 , int V_59 )
{
struct V_60 * V_61 ;
struct V_60 * V_62 ;
int V_63 = strlen ( L_14 ) + 1 ;
int V_64 = strlen ( L_15 ) + 1 ;
int V_65 = 0 ;
const char * V_66 ;
char V_67 [ 50 ] ;
int error = 0 ;
if ( F_20 ( & V_61 ) ) {
strcpy ( V_58 , L_16 ) ;
return 1 ;
}
V_62 = V_61 ;
while ( V_62 != NULL ) {
if ( ( V_62 -> V_68 != NULL ) &&
( V_62 -> V_68 -> V_69 == V_57 ) ) {
if ( V_57 == V_70 ) {
struct V_71 * V_72 =
(struct V_71 * ) V_62 -> V_68 ;
V_66 = F_21 ( V_57 , & V_72 -> V_73 ,
V_67 , 50 ) ;
if ( V_66 == NULL ) {
strcpy ( V_58 , L_17 ) ;
error = 1 ;
goto V_74;
}
if ( V_65 == 0 )
strcpy ( V_58 , V_67 ) ;
else
strcat ( V_58 , V_67 ) ;
strcat ( V_58 , L_18 ) ;
V_65 += strlen ( V_66 ) + 1 ;
if ( ( V_59 - V_65 ) < ( V_63 + 1 ) )
goto V_74;
} else {
struct V_75 * V_72 =
(struct V_75 * ) V_62 -> V_68 ;
V_66 = F_21 ( V_57 ,
& V_72 -> V_76 . V_77 ,
V_67 , 50 ) ;
if ( V_66 == NULL ) {
strcpy ( V_58 , L_17 ) ;
error = 1 ;
goto V_74;
}
if ( V_65 == 0 )
strcpy ( V_58 , V_67 ) ;
else
strcat ( V_58 , V_67 ) ;
strcat ( V_58 , L_18 ) ;
V_65 += strlen ( V_66 ) + 1 ;
if ( ( V_59 - V_65 ) < ( V_64 + 1 ) )
goto V_74;
}
}
V_62 = V_62 -> V_78 ;
}
V_74:
F_22 ( V_61 ) ;
return error ;
}
static int
F_23 ( char * V_58 , int V_59 )
{
struct V_79 V_80 , * V_81 ;
int error = 0 ;
F_24 ( V_58 , V_59 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_82 = V_70 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
error = F_25 ( V_58 , NULL , & V_80 , & V_81 ) ;
if ( error != 0 ) {
strcpy ( V_58 , L_19 ) ;
return error ;
}
strcpy ( V_58 , V_81 -> V_87 ) ;
F_26 ( V_81 ) ;
return error ;
}
static int
F_27 ( int V_8 , struct V_88 * V_89 )
{
struct V_90 * V_91 ;
unsigned int V_92 ;
struct V_93 V_94 ;
char V_58 [ 64 ] ;
struct V_95 V_96 [ 2 ] ;
V_92 = F_28 ( sizeof( struct V_88 ) + V_89 -> V_97 ) ;
V_91 = (struct V_90 * ) V_58 ;
V_91 -> V_98 = 0 ;
V_91 -> V_99 = F_2 () ;
V_91 -> V_100 = V_101 ;
V_91 -> V_102 = F_29 ( V_92 - sizeof( * V_91 ) ) ;
V_91 -> V_103 = 0 ;
V_96 [ 0 ] . V_104 = V_91 ;
V_96 [ 0 ] . V_105 = sizeof( * V_91 ) ;
V_96 [ 1 ] . V_104 = V_89 ;
V_96 [ 1 ] . V_105 = V_92 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_106 = & V_72 ;
V_94 . V_107 = sizeof( V_72 ) ;
V_94 . V_108 = V_96 ;
V_94 . V_109 = 2 ;
return F_30 ( V_8 , & V_94 , 0 ) ;
}
int main ( void )
{
int V_8 , V_97 , V_110 ;
int error ;
struct V_88 * V_94 ;
struct V_111 V_112 ;
struct V_90 * V_113 ;
struct V_88 * V_114 ;
struct V_115 * V_116 ;
char * V_44 ;
char * V_117 ;
char * V_118 ;
F_31 ( 1 , 0 ) ;
F_32 ( L_20 , 0 , V_119 ) ;
F_4 ( V_120 , L_21 , F_2 () ) ;
F_16 () ;
if ( F_8 () ) {
F_4 ( V_10 , L_22 ) ;
exit ( - 1 ) ;
}
V_8 = F_33 ( V_121 , V_122 , V_123 ) ;
if ( V_8 < 0 ) {
F_4 ( V_10 , L_23 , V_8 ) ;
exit ( - 1 ) ;
}
V_72 . V_124 = V_121 ;
V_72 . V_125 = 0 ;
V_72 . V_126 = 0 ;
V_72 . V_127 = V_128 ;
error = F_34 ( V_8 , (struct V_129 * ) & V_72 , sizeof( V_72 ) ) ;
if ( error < 0 ) {
F_4 ( V_10 , L_24 , error ) ;
F_35 ( V_8 ) ;
exit ( - 1 ) ;
}
V_110 = V_72 . V_127 ;
F_36 ( V_8 , 270 , 1 , & V_110 , sizeof( V_110 ) ) ;
V_94 = (struct V_88 * ) V_130 ;
V_94 -> V_131 . V_132 = V_128 ;
V_94 -> V_131 . V_133 = V_134 ;
V_116 = (struct V_115 * ) V_94 -> V_135 ;
V_116 -> V_136 . V_137 = V_138 ;
V_94 -> V_139 = 0 ;
V_94 -> V_97 = sizeof( struct V_115 ) ;
V_97 = F_27 ( V_8 , V_94 ) ;
if ( V_97 < 0 ) {
F_4 ( V_10 , L_25 , V_97 ) ;
F_35 ( V_8 ) ;
exit ( - 1 ) ;
}
V_112 . V_8 = V_8 ;
while ( 1 ) {
struct V_129 * V_140 = (struct V_129 * ) & V_72 ;
T_4 V_141 = sizeof( V_72 ) ;
V_112 . V_142 = V_143 ;
V_112 . V_144 = 0 ;
F_37 ( & V_112 , 1 , - 1 ) ;
V_97 = F_38 ( V_8 , V_145 , sizeof( V_145 ) , 0 ,
V_140 , & V_141 ) ;
if ( V_97 < 0 || V_72 . V_126 ) {
F_4 ( V_10 , L_26 ,
V_72 . V_126 , V_146 , strerror ( V_146 ) ) ;
F_35 ( V_8 ) ;
return - 1 ;
}
V_113 = (struct V_90 * ) V_145 ;
V_114 = (struct V_88 * ) F_39 ( V_113 ) ;
V_116 = (struct V_115 * ) V_114 -> V_135 ;
switch ( V_116 -> V_136 . V_137 ) {
case V_138 :
V_44 = ( char * ) V_116 -> V_147 . V_148 . V_149 ;
V_150 = malloc ( strlen ( V_44 ) + 1 ) ;
if ( V_150 ) {
strcpy ( V_150 , V_44 ) ;
F_4 ( V_120 , L_27 ,
V_150 ) ;
} else {
F_4 ( V_10 , L_7 ) ;
}
continue;
case V_151 :
if ( F_13 ( V_116 -> V_136 . V_1 ,
V_116 -> V_147 . V_152 . V_135 . V_34 ,
V_116 -> V_147 . V_152 . V_135 . V_35 ,
V_116 -> V_147 . V_152 . V_135 . V_38 ,
V_116 -> V_147 . V_152 . V_135 . V_39 ) )
strcpy ( V_116 -> V_147 . V_152 . V_135 . V_34 , L_11 ) ;
break;
case V_153 :
if ( F_14 ( V_116 -> V_136 . V_1 ,
V_116 -> V_147 . V_152 . V_135 . V_34 ,
V_116 -> V_147 . V_152 . V_135 . V_35 ,
V_116 -> V_147 . V_152 . V_135 . V_38 ,
V_116 -> V_147 . V_152 . V_135 . V_39 ) )
strcpy ( V_116 -> V_147 . V_152 . V_135 . V_34 , L_11 ) ;
break;
case V_154 :
if ( F_12 ( V_116 -> V_136 . V_1 ,
V_116 -> V_147 . V_155 . V_34 ,
V_116 -> V_147 . V_155 . V_35 ) )
strcpy ( V_116 -> V_147 . V_155 . V_34 , L_11 ) ;
break;
default:
break;
}
if ( V_116 -> V_136 . V_137 != V_156 )
goto V_157;
if ( V_116 -> V_136 . V_1 != V_158 ) {
F_15 ( V_116 -> V_136 . V_1 ,
V_116 -> V_147 . V_159 . V_42 ,
V_116 -> V_147 . V_159 . V_135 . V_34 ,
V_40 ,
V_116 -> V_147 . V_159 . V_135 . V_38 ,
V_41 ) ;
goto V_157;
}
V_116 = (struct V_115 * ) V_114 -> V_135 ;
V_118 = ( char * ) V_116 -> V_147 . V_159 . V_135 . V_34 ;
V_117 = ( char * ) V_116 -> V_147 . V_159 . V_135 . V_38 ;
switch ( V_116 -> V_147 . V_159 . V_42 ) {
case V_160 :
F_23 ( V_117 ,
V_41 ) ;
strcpy ( V_118 , L_28 ) ;
break;
case V_161 :
strcpy ( V_118 , L_29 ) ;
strcpy ( V_117 , V_150 ) ;
break;
case V_162 :
F_19 ( V_70 , V_117 ,
V_41 ) ;
strcpy ( V_118 , L_30 ) ;
break;
case V_163 :
F_19 ( V_164 , V_117 ,
V_41 ) ;
strcpy ( V_118 , L_31 ) ;
break;
case V_165 :
strcpy ( V_117 , V_47 ) ;
strcpy ( V_118 , L_32 ) ;
break;
case V_166 :
strcpy ( V_117 , V_52 ) ;
strcpy ( V_118 , L_33 ) ;
break;
case V_167 :
strcpy ( V_117 , V_55 ) ;
strcpy ( V_118 , L_34 ) ;
break;
case V_168 :
strcpy ( V_117 , V_56 ) ;
strcpy ( V_118 , L_35 ) ;
break;
case V_169 :
strcpy ( V_117 , V_47 ) ;
strcpy ( V_118 , L_36 ) ;
break;
case V_170 :
strcpy ( V_117 , V_49 ) ;
strcpy ( V_118 , L_37 ) ;
break;
default:
strcpy ( V_117 , L_38 ) ;
strcpy ( V_118 , L_11 ) ;
break;
}
V_157:
V_114 -> V_131 . V_132 = V_128 ;
V_114 -> V_131 . V_133 = V_134 ;
V_114 -> V_139 = 0 ;
V_114 -> V_97 = sizeof( struct V_115 ) ;
V_97 = F_27 ( V_8 , V_114 ) ;
if ( V_97 < 0 ) {
F_4 ( V_10 , L_39 , V_97 ) ;
exit ( - 1 ) ;
}
}
}
