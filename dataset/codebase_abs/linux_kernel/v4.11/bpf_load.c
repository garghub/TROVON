static int F_1 ( const char * V_1 , int V_2 )
{
int V_3 = atoi ( V_1 ) , V_4 ;
V_4 = F_2 ( V_5 , & V_3 , & V_2 , V_6 ) ;
if ( V_4 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_3 ( const char * V_1 , struct V_7 * V_8 , int V_9 )
{
bool V_10 = strncmp ( V_1 , L_2 , 6 ) == 0 ;
bool V_11 = strncmp ( V_1 , L_3 , 7 ) == 0 ;
bool V_12 = strncmp ( V_1 , L_4 , 10 ) == 0 ;
bool V_13 = strncmp ( V_1 , L_5 , 11 ) == 0 ;
bool V_14 = strncmp ( V_1 , L_6 , 3 ) == 0 ;
bool V_15 = strncmp ( V_1 , L_7 , 10 ) == 0 ;
bool V_16 = strncmp ( V_1 , L_8 , 10 ) == 0 ;
bool V_17 = strncmp ( V_1 , L_9 , 11 ) == 0 ;
T_1 V_18 = V_9 / sizeof( struct V_7 ) ;
enum V_19 V_20 ;
char V_21 [ 256 ] ;
int V_22 , V_23 , V_4 , V_24 ;
struct V_25 V_26 = {} ;
V_26 . type = V_27 ;
V_26 . V_28 = V_29 ;
V_26 . V_30 = 1 ;
V_26 . V_31 = 1 ;
if ( V_10 ) {
V_20 = V_32 ;
} else if ( V_11 || V_12 ) {
V_20 = V_33 ;
} else if ( V_13 ) {
V_20 = V_34 ;
} else if ( V_14 ) {
V_20 = V_35 ;
} else if ( V_15 ) {
V_20 = V_36 ;
} else if ( V_16 ) {
V_20 = V_37 ;
} else if ( V_17 ) {
V_20 = V_38 ;
} else {
printf ( L_10 , V_1 ) ;
return - 1 ;
}
V_22 = F_4 ( V_20 , V_8 , V_18 , V_39 , V_40 ,
V_41 , V_42 ) ;
if ( V_22 < 0 ) {
printf ( L_11 , V_43 , V_41 ) ;
return - 1 ;
}
V_2 [ V_44 ++ ] = V_22 ;
if ( V_14 || V_15 || V_16 || V_17 )
return 0 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_12 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_22 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_13 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_22 ) ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_14 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_21 ) ;
if ( V_4 < 0 ) {
printf ( L_15 ,
V_1 , strerror ( V_43 ) ) ;
return - 1 ;
}
strcpy ( V_21 , V_45 ) ;
strcat ( V_21 , L_16 ) ;
strcat ( V_21 , V_1 ) ;
strcat ( V_21 , L_17 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_13 ) ;
return - 1 ;
}
strcpy ( V_21 , V_45 ) ;
strcat ( V_21 , L_18 ) ;
strcat ( V_21 , V_1 ) ;
strcat ( V_21 , L_17 ) ;
}
V_23 = F_5 ( V_21 , V_46 , 0 ) ;
if ( V_23 < 0 ) {
printf ( L_19 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_23 , V_21 , sizeof( V_21 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_21 ) ) {
printf ( L_20 , V_1 , strerror ( V_43 ) ) ;
return - 1 ;
}
F_7 ( V_23 ) ;
V_21 [ V_4 ] = 0 ;
V_24 = atoi ( V_21 ) ;
V_26 . V_47 = V_24 ;
V_23 = F_8 ( & V_26 , - 1 , 0 , - 1 , 0 ) ;
if ( V_23 < 0 ) {
printf ( L_21 , V_24 , V_23 , strerror ( V_43 ) ) ;
return - 1 ;
}
V_48 [ V_44 - 1 ] = V_23 ;
F_9 ( V_23 , V_49 , 0 ) ;
F_9 ( V_23 , V_50 , V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_51 * V_52 , int V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 / sizeof( struct V_51 ) ; V_54 ++ ) {
V_55 [ V_54 ] = F_11 ( V_52 [ V_54 ] . type ,
V_52 [ V_54 ] . V_56 ,
V_52 [ V_54 ] . V_57 ,
V_52 [ V_54 ] . V_58 ,
V_52 [ V_54 ] . V_59 ) ;
if ( V_55 [ V_54 ] < 0 ) {
printf ( L_22 ,
V_43 , strerror ( V_43 ) ) ;
return 1 ;
}
if ( V_52 [ V_54 ] . type == V_60 )
V_5 = V_55 [ V_54 ] ;
}
return 0 ;
}
static int F_12 ( T_2 * V_61 , int V_54 , T_3 * V_62 , char * * V_63 ,
T_4 * V_64 , T_5 * * V_65 )
{
T_6 * V_66 ;
V_66 = F_13 ( V_61 , V_54 ) ;
if ( ! V_66 )
return 1 ;
if ( F_14 ( V_66 , V_64 ) != V_64 )
return 2 ;
* V_63 = F_15 ( V_61 , V_62 -> V_67 , V_64 -> V_68 ) ;
if ( ! * V_63 || ! V_64 -> V_69 )
return 3 ;
* V_65 = F_16 ( V_66 , 0 ) ;
if ( ! * V_65 || F_16 ( V_66 , * V_65 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_5 * V_65 , T_5 * V_70 ,
T_4 * V_64 , struct V_7 * V_71 )
{
int V_54 , V_72 ;
V_72 = V_64 -> V_69 / V_64 -> V_73 ;
for ( V_54 = 0 ; V_54 < V_72 ; V_54 ++ ) {
T_7 V_74 ;
T_8 V_75 ;
unsigned int V_76 ;
F_18 ( V_65 , V_54 , & V_75 ) ;
V_76 = V_75 . V_77 / sizeof( struct V_7 ) ;
F_19 ( V_70 , F_20 ( V_75 . V_78 ) , & V_74 ) ;
if ( V_71 [ V_76 ] . V_79 != ( V_80 | V_81 | V_82 ) ) {
printf ( L_23 ,
V_76 , V_71 [ V_76 ] . V_79 ) ;
return 1 ;
}
V_71 [ V_76 ] . V_83 = V_84 ;
V_71 [ V_76 ] . V_85 = V_55 [ V_74 . V_86 / sizeof( struct V_51 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_87 )
{
int V_22 , V_54 ;
T_2 * V_61 ;
T_3 V_62 ;
T_4 V_64 , V_88 ;
T_5 * V_65 , * V_89 , * V_70 = NULL ;
char * V_63 , * V_90 ;
V_40 = 0 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
if ( F_22 ( V_92 ) == V_93 )
return 1 ;
V_22 = F_5 ( V_87 , V_46 , 0 ) ;
if ( V_22 < 0 )
return 1 ;
V_61 = F_23 ( V_22 , V_94 , NULL ) ;
if ( ! V_61 )
return 1 ;
if ( F_24 ( V_61 , & V_62 ) != & V_62 )
return 1 ;
V_54 = system ( L_24 ) ;
for ( V_54 = 1 ; V_54 < V_62 . V_95 ; V_54 ++ ) {
if ( F_12 ( V_61 , V_54 , & V_62 , & V_63 , & V_64 , & V_65 ) )
continue;
if ( 0 )
printf ( L_25 ,
V_54 , V_63 , V_65 -> V_96 , V_65 -> V_97 ,
V_64 . V_98 , ( int ) V_64 . V_99 ) ;
if ( strcmp ( V_63 , L_26 ) == 0 ) {
V_91 [ V_54 ] = true ;
memcpy ( V_39 , V_65 -> V_96 , V_65 -> V_97 ) ;
} else if ( strcmp ( V_63 , L_27 ) == 0 ) {
V_91 [ V_54 ] = true ;
if ( V_65 -> V_97 != sizeof( int ) ) {
printf ( L_28 ,
V_65 -> V_97 ) ;
return 1 ;
}
memcpy ( & V_40 , V_65 -> V_96 , sizeof( int ) ) ;
} else if ( strcmp ( V_63 , L_29 ) == 0 ) {
V_91 [ V_54 ] = true ;
if ( F_10 ( V_65 -> V_96 , V_65 -> V_97 ) )
return 1 ;
} else if ( V_64 . V_100 == V_101 ) {
V_70 = V_65 ;
}
}
for ( V_54 = 1 ; V_54 < V_62 . V_95 ; V_54 ++ ) {
if ( V_91 [ V_54 ] )
continue;
if ( F_12 ( V_61 , V_54 , & V_62 , & V_63 , & V_64 , & V_65 ) )
continue;
if ( V_64 . V_100 == V_102 ) {
struct V_7 * V_103 ;
if ( F_12 ( V_61 , V_64 . V_104 , & V_62 , & V_90 ,
& V_88 , & V_89 ) )
continue;
if ( V_88 . V_100 != V_105 ||
! ( V_88 . V_99 & V_106 ) )
continue;
V_103 = (struct V_7 * ) V_89 -> V_96 ;
V_91 [ V_64 . V_104 ] = true ;
V_91 [ V_54 ] = true ;
if ( F_17 ( V_65 , V_70 , & V_64 , V_103 ) )
continue;
if ( memcmp ( V_90 , L_3 , 7 ) == 0 ||
memcmp ( V_90 , L_4 , 10 ) == 0 ||
memcmp ( V_90 , L_5 , 11 ) == 0 ||
memcmp ( V_90 , L_6 , 3 ) == 0 ||
memcmp ( V_90 , L_7 , 10 ) == 0 ||
memcmp ( V_90 , L_2 , 6 ) == 0 ||
memcmp ( V_90 , L_30 , 7 ) == 0 )
F_3 ( V_90 , V_103 , V_89 -> V_97 ) ;
}
}
for ( V_54 = 1 ; V_54 < V_62 . V_95 ; V_54 ++ ) {
if ( V_91 [ V_54 ] )
continue;
if ( F_12 ( V_61 , V_54 , & V_62 , & V_63 , & V_64 , & V_65 ) )
continue;
if ( memcmp ( V_63 , L_3 , 7 ) == 0 ||
memcmp ( V_63 , L_4 , 10 ) == 0 ||
memcmp ( V_63 , L_5 , 11 ) == 0 ||
memcmp ( V_63 , L_6 , 3 ) == 0 ||
memcmp ( V_63 , L_7 , 10 ) == 0 ||
memcmp ( V_63 , L_2 , 6 ) == 0 ||
memcmp ( V_63 , L_30 , 7 ) == 0 )
F_3 ( V_63 , V_65 -> V_96 , V_65 -> V_97 ) ;
}
F_7 ( V_22 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_107 ;
V_107 = F_5 ( V_45 L_31 , V_46 , 0 ) ;
if ( V_107 < 0 )
return;
while ( 1 ) {
static char V_21 [ 4096 ] ;
T_9 V_108 ;
V_108 = F_6 ( V_107 , V_21 , sizeof( V_21 ) ) ;
if ( V_108 > 0 ) {
V_21 [ V_108 ] = 0 ;
puts ( V_21 ) ;
}
}
}
static int F_26 ( const void * V_109 , const void * V_110 )
{
return ( (struct V_111 * ) V_109 ) -> V_112 - ( (struct V_111 * ) V_110 ) -> V_112 ;
}
int F_27 ( void )
{
T_10 * V_113 = fopen ( L_32 , L_33 ) ;
char V_114 [ 256 ] , V_21 [ 256 ] ;
char V_115 ;
void * V_112 ;
int V_54 = 0 ;
if ( ! V_113 )
return - V_116 ;
while ( ! feof ( V_113 ) ) {
if ( ! fgets ( V_21 , sizeof( V_21 ) , V_113 ) )
break;
if ( sscanf ( V_21 , L_34 , & V_112 , & V_115 , V_114 ) != 3 )
break;
if ( ! V_112 )
continue;
V_117 [ V_54 ] . V_112 = ( long ) V_112 ;
V_117 [ V_54 ] . V_118 = F_28 ( V_114 ) ;
V_54 ++ ;
}
V_119 = V_54 ;
qsort ( V_117 , V_119 , sizeof( struct V_111 ) , F_26 ) ;
return 0 ;
}
struct V_111 * F_29 ( long V_120 )
{
int V_121 = 0 , V_122 = V_119 ;
int V_123 ;
while ( V_121 < V_122 ) {
T_1 V_124 = V_121 + ( V_122 - V_121 ) / 2 ;
V_123 = V_120 - V_117 [ V_124 ] . V_112 ;
if ( V_123 < 0 )
V_122 = V_124 ;
else if ( V_123 > 0 )
V_121 = V_124 + 1 ;
else
return & V_117 [ V_124 ] ;
}
if ( V_121 >= 1 && V_117 [ V_121 - 1 ] . V_112 < V_120 &&
V_120 < V_117 [ V_121 ] . V_112 )
return & V_117 [ V_121 - 1 ] ;
return & V_117 [ 0 ] ;
}
int F_30 ( int V_125 , int V_22 )
{
struct V_126 V_127 ;
int V_128 , V_129 = 0 , V_53 , V_130 = - 1 ;
char V_21 [ 4096 ] ;
struct V_131 * V_132 , * V_133 ;
struct {
struct V_134 V_135 ;
struct V_136 V_137 ;
char V_138 [ 64 ] ;
} V_139 ;
struct V_134 * V_135 ;
struct V_140 * V_4 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_141 = V_142 ;
V_128 = F_31 ( V_142 , V_143 , V_144 ) ;
if ( V_128 < 0 ) {
printf ( L_35 , strerror ( V_43 ) ) ;
return - 1 ;
}
if ( F_32 ( V_128 , (struct V_145 * ) & V_127 , sizeof( V_127 ) ) < 0 ) {
printf ( L_36 , strerror ( V_43 ) ) ;
goto V_146;
}
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_135 . V_147 = F_33 ( sizeof( struct V_136 ) ) ;
V_139 . V_135 . V_148 = V_149 | V_150 ;
V_139 . V_135 . V_151 = V_152 ;
V_139 . V_135 . V_153 = 0 ;
V_139 . V_135 . V_154 = ++ V_129 ;
V_139 . V_137 . V_155 = V_156 ;
V_139 . V_137 . V_157 = V_125 ;
V_132 = (struct V_131 * ) ( ( ( char * ) & V_139 )
+ F_34 ( V_139 . V_135 . V_147 ) ) ;
V_132 -> V_158 = V_159 | 43 ;
V_133 = (struct V_131 * ) ( ( char * ) V_132 + V_160 ) ;
V_133 -> V_158 = 1 ;
V_133 -> V_161 = V_160 + sizeof( int ) ;
memcpy ( ( char * ) V_133 + V_160 , & V_22 , sizeof( V_22 ) ) ;
V_132 -> V_161 = V_160 + V_133 -> V_161 ;
V_139 . V_135 . V_147 += F_35 ( V_132 -> V_161 ) ;
if ( F_36 ( V_128 , & V_139 , V_139 . V_135 . V_147 , 0 ) < 0 ) {
printf ( L_37 , strerror ( V_43 ) ) ;
goto V_146;
}
V_53 = F_37 ( V_128 , V_21 , sizeof( V_21 ) , 0 ) ;
if ( V_53 < 0 ) {
printf ( L_38 , strerror ( V_43 ) ) ;
goto V_146;
}
for ( V_135 = (struct V_134 * ) V_21 ; F_38 ( V_135 , V_53 ) ;
V_135 = F_39 ( V_135 , V_53 ) ) {
if ( V_135 -> V_153 != F_40 () ) {
printf ( L_39 ,
V_135 -> V_153 , F_40 () ) ;
goto V_146;
}
if ( V_135 -> V_154 != V_129 ) {
printf ( L_40 ,
V_135 -> V_154 , V_129 ) ;
goto V_146;
}
switch ( V_135 -> V_151 ) {
case V_162 :
V_4 = (struct V_140 * ) F_41 ( V_135 ) ;
if ( ! V_4 -> error )
continue;
printf ( L_41 , strerror ( - V_4 -> error ) ) ;
goto V_146;
case V_163 :
break;
}
}
V_130 = 0 ;
V_146:
F_7 ( V_128 ) ;
return V_130 ;
}
