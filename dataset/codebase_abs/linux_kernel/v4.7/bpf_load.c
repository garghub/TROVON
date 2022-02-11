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
enum V_14 V_15 ;
char V_16 [ 256 ] ;
int V_17 , V_18 , V_4 , V_19 ;
struct V_20 V_21 = {} ;
V_21 . type = V_22 ;
V_21 . V_23 = V_24 ;
V_21 . V_25 = 1 ;
V_21 . V_26 = 1 ;
if ( V_10 ) {
V_15 = V_27 ;
} else if ( V_11 || V_12 ) {
V_15 = V_28 ;
} else if ( V_13 ) {
V_15 = V_29 ;
} else {
printf ( L_6 , V_1 ) ;
return - 1 ;
}
V_17 = F_4 ( V_15 , V_8 , V_9 , V_30 , V_31 ) ;
if ( V_17 < 0 ) {
printf ( L_7 , V_32 , V_33 ) ;
return - 1 ;
}
V_2 [ V_34 ++ ] = V_17 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_8 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_17 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_9 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_17 ) ;
snprintf ( V_16 , sizeof( V_16 ) ,
L_10 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_16 ) ;
if ( V_4 < 0 ) {
printf ( L_11 ,
V_1 , strerror ( V_32 ) ) ;
return - 1 ;
}
strcpy ( V_16 , V_35 ) ;
strcat ( V_16 , L_12 ) ;
strcat ( V_16 , V_1 ) ;
strcat ( V_16 , L_13 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_9 ) ;
return - 1 ;
}
strcpy ( V_16 , V_35 ) ;
strcat ( V_16 , L_14 ) ;
strcat ( V_16 , V_1 ) ;
strcat ( V_16 , L_13 ) ;
}
V_18 = F_5 ( V_16 , V_36 , 0 ) ;
if ( V_18 < 0 ) {
printf ( L_15 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_18 , V_16 , sizeof( V_16 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_16 ) ) {
printf ( L_16 , V_1 , strerror ( V_32 ) ) ;
return - 1 ;
}
F_7 ( V_18 ) ;
V_16 [ V_4 ] = 0 ;
V_19 = atoi ( V_16 ) ;
V_21 . V_37 = V_19 ;
V_18 = F_8 ( & V_21 , - 1 , 0 , - 1 , 0 ) ;
if ( V_18 < 0 ) {
printf ( L_17 , V_19 , V_18 , strerror ( V_32 ) ) ;
return - 1 ;
}
V_38 [ V_34 - 1 ] = V_18 ;
F_9 ( V_18 , V_39 , 0 ) ;
F_9 ( V_18 , V_40 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_41 * V_42 , int V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 / sizeof( struct V_41 ) ; V_44 ++ ) {
V_45 [ V_44 ] = F_11 ( V_42 [ V_44 ] . type ,
V_42 [ V_44 ] . V_46 ,
V_42 [ V_44 ] . V_47 ,
V_42 [ V_44 ] . V_48 ,
V_42 [ V_44 ] . V_49 ) ;
if ( V_45 [ V_44 ] < 0 ) {
printf ( L_18 ,
V_32 , strerror ( V_32 ) ) ;
return 1 ;
}
if ( V_42 [ V_44 ] . type == V_50 )
V_5 = V_45 [ V_44 ] ;
}
return 0 ;
}
static int F_12 ( T_1 * V_51 , int V_44 , T_2 * V_52 , char * * V_53 ,
T_3 * V_54 , T_4 * * V_55 )
{
T_5 * V_56 ;
V_56 = F_13 ( V_51 , V_44 ) ;
if ( ! V_56 )
return 1 ;
if ( F_14 ( V_56 , V_54 ) != V_54 )
return 2 ;
* V_53 = F_15 ( V_51 , V_52 -> V_57 , V_54 -> V_58 ) ;
if ( ! * V_53 || ! V_54 -> V_59 )
return 3 ;
* V_55 = F_16 ( V_56 , 0 ) ;
if ( ! * V_55 || F_16 ( V_56 , * V_55 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_4 * V_55 , T_4 * V_60 ,
T_3 * V_54 , struct V_7 * V_61 )
{
int V_44 , V_62 ;
V_62 = V_54 -> V_59 / V_54 -> V_63 ;
for ( V_44 = 0 ; V_44 < V_62 ; V_44 ++ ) {
T_6 V_64 ;
T_7 V_65 ;
unsigned int V_66 ;
F_18 ( V_55 , V_44 , & V_65 ) ;
V_66 = V_65 . V_67 / sizeof( struct V_7 ) ;
F_19 ( V_60 , F_20 ( V_65 . V_68 ) , & V_64 ) ;
if ( V_61 [ V_66 ] . V_69 != ( V_70 | V_71 | V_72 ) ) {
printf ( L_19 ,
V_66 , V_61 [ V_66 ] . V_69 ) ;
return 1 ;
}
V_61 [ V_66 ] . V_73 = V_74 ;
V_61 [ V_66 ] . V_75 = V_45 [ V_64 . V_76 / sizeof( struct V_41 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_77 )
{
int V_17 , V_44 ;
T_1 * V_51 ;
T_2 V_52 ;
T_3 V_54 , V_78 ;
T_4 * V_55 , * V_79 , * V_60 = NULL ;
char * V_53 , * V_80 ;
if ( F_22 ( V_81 ) == V_82 )
return 1 ;
V_17 = F_5 ( V_77 , V_36 , 0 ) ;
if ( V_17 < 0 )
return 1 ;
V_51 = F_23 ( V_17 , V_83 , NULL ) ;
if ( ! V_51 )
return 1 ;
if ( F_24 ( V_51 , & V_52 ) != & V_52 )
return 1 ;
V_44 = system ( L_20 ) ;
for ( V_44 = 1 ; V_44 < V_52 . V_84 ; V_44 ++ ) {
if ( F_12 ( V_51 , V_44 , & V_52 , & V_53 , & V_54 , & V_55 ) )
continue;
if ( 0 )
printf ( L_21 ,
V_44 , V_53 , V_55 -> V_85 , V_55 -> V_86 ,
V_54 . V_87 , ( int ) V_54 . V_88 ) ;
if ( strcmp ( V_53 , L_22 ) == 0 ) {
V_89 [ V_44 ] = true ;
memcpy ( V_30 , V_55 -> V_85 , V_55 -> V_86 ) ;
} else if ( strcmp ( V_53 , L_23 ) == 0 ) {
V_89 [ V_44 ] = true ;
if ( V_55 -> V_86 != sizeof( int ) ) {
printf ( L_24 ,
V_55 -> V_86 ) ;
return 1 ;
}
memcpy ( & V_31 , V_55 -> V_85 , sizeof( int ) ) ;
} else if ( strcmp ( V_53 , L_25 ) == 0 ) {
V_89 [ V_44 ] = true ;
if ( F_10 ( V_55 -> V_85 , V_55 -> V_86 ) )
return 1 ;
} else if ( V_54 . V_90 == V_91 ) {
V_60 = V_55 ;
}
}
for ( V_44 = 1 ; V_44 < V_52 . V_84 ; V_44 ++ ) {
if ( F_12 ( V_51 , V_44 , & V_52 , & V_53 , & V_54 , & V_55 ) )
continue;
if ( V_54 . V_90 == V_92 ) {
struct V_7 * V_93 ;
if ( F_12 ( V_51 , V_54 . V_94 , & V_52 , & V_80 ,
& V_78 , & V_79 ) )
continue;
V_93 = (struct V_7 * ) V_79 -> V_85 ;
V_89 [ V_54 . V_94 ] = true ;
V_89 [ V_44 ] = true ;
if ( F_17 ( V_55 , V_60 , & V_54 , V_93 ) )
continue;
if ( memcmp ( V_80 , L_3 , 7 ) == 0 ||
memcmp ( V_80 , L_4 , 10 ) == 0 ||
memcmp ( V_80 , L_5 , 11 ) == 0 ||
memcmp ( V_80 , L_2 , 6 ) == 0 )
F_3 ( V_80 , V_93 , V_79 -> V_86 ) ;
}
}
for ( V_44 = 1 ; V_44 < V_52 . V_84 ; V_44 ++ ) {
if ( V_89 [ V_44 ] )
continue;
if ( F_12 ( V_51 , V_44 , & V_52 , & V_53 , & V_54 , & V_55 ) )
continue;
if ( memcmp ( V_53 , L_3 , 7 ) == 0 ||
memcmp ( V_53 , L_4 , 10 ) == 0 ||
memcmp ( V_53 , L_5 , 11 ) == 0 ||
memcmp ( V_53 , L_2 , 6 ) == 0 )
F_3 ( V_53 , V_55 -> V_85 , V_55 -> V_86 ) ;
}
F_7 ( V_17 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_95 ;
V_95 = F_5 ( V_35 L_26 , V_36 , 0 ) ;
if ( V_95 < 0 )
return;
while ( 1 ) {
static char V_16 [ 4096 ] ;
T_8 V_96 ;
V_96 = F_6 ( V_95 , V_16 , sizeof( V_16 ) ) ;
if ( V_96 > 0 ) {
V_16 [ V_96 ] = 0 ;
puts ( V_16 ) ;
}
}
}
static int F_26 ( const void * V_97 , const void * V_98 )
{
return ( (struct V_99 * ) V_97 ) -> V_100 - ( (struct V_99 * ) V_98 ) -> V_100 ;
}
int F_27 ( void )
{
T_9 * V_101 = fopen ( L_27 , L_28 ) ;
char V_102 [ 256 ] , V_16 [ 256 ] ;
char V_103 ;
void * V_100 ;
int V_44 = 0 ;
if ( ! V_101 )
return - V_104 ;
while ( ! feof ( V_101 ) ) {
if ( ! fgets ( V_16 , sizeof( V_16 ) , V_101 ) )
break;
if ( sscanf ( V_16 , L_29 , & V_100 , & V_103 , V_102 ) != 3 )
break;
if ( ! V_100 )
continue;
V_105 [ V_44 ] . V_100 = ( long ) V_100 ;
V_105 [ V_44 ] . V_106 = F_28 ( V_102 ) ;
V_44 ++ ;
}
V_107 = V_44 ;
qsort ( V_105 , V_107 , sizeof( struct V_99 ) , F_26 ) ;
return 0 ;
}
struct V_99 * F_29 ( long V_108 )
{
int V_109 = 0 , V_110 = V_107 ;
int V_111 ;
while ( V_109 < V_110 ) {
T_10 V_112 = V_109 + ( V_110 - V_109 ) / 2 ;
V_111 = V_108 - V_105 [ V_112 ] . V_100 ;
if ( V_111 < 0 )
V_110 = V_112 ;
else if ( V_111 > 0 )
V_109 = V_112 + 1 ;
else
return & V_105 [ V_112 ] ;
}
if ( V_109 >= 1 && V_105 [ V_109 - 1 ] . V_100 < V_108 &&
V_108 < V_105 [ V_109 ] . V_100 )
return & V_105 [ V_109 - 1 ] ;
return & V_105 [ 0 ] ;
}
