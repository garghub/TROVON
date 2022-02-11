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
enum V_16 V_17 ;
char V_18 [ 256 ] ;
int V_19 , V_20 , V_4 , V_21 ;
struct V_22 V_23 = {} ;
V_23 . type = V_24 ;
V_23 . V_25 = V_26 ;
V_23 . V_27 = 1 ;
V_23 . V_28 = 1 ;
if ( V_10 ) {
V_17 = V_29 ;
} else if ( V_11 || V_12 ) {
V_17 = V_30 ;
} else if ( V_13 ) {
V_17 = V_31 ;
} else if ( V_14 ) {
V_17 = V_32 ;
} else if ( V_15 ) {
V_17 = V_33 ;
} else {
printf ( L_8 , V_1 ) ;
return - 1 ;
}
V_19 = F_4 ( V_17 , V_8 , V_9 , V_34 , V_35 ) ;
if ( V_19 < 0 ) {
printf ( L_9 , V_36 , V_37 ) ;
return - 1 ;
}
V_2 [ V_38 ++ ] = V_19 ;
if ( V_14 || V_15 )
return 0 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_10 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_19 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_11 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_19 ) ;
snprintf ( V_18 , sizeof( V_18 ) ,
L_12 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_18 ) ;
if ( V_4 < 0 ) {
printf ( L_13 ,
V_1 , strerror ( V_36 ) ) ;
return - 1 ;
}
strcpy ( V_18 , V_39 ) ;
strcat ( V_18 , L_14 ) ;
strcat ( V_18 , V_1 ) ;
strcat ( V_18 , L_15 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_11 ) ;
return - 1 ;
}
strcpy ( V_18 , V_39 ) ;
strcat ( V_18 , L_16 ) ;
strcat ( V_18 , V_1 ) ;
strcat ( V_18 , L_15 ) ;
}
V_20 = F_5 ( V_18 , V_40 , 0 ) ;
if ( V_20 < 0 ) {
printf ( L_17 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_20 , V_18 , sizeof( V_18 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_18 ) ) {
printf ( L_18 , V_1 , strerror ( V_36 ) ) ;
return - 1 ;
}
F_7 ( V_20 ) ;
V_18 [ V_4 ] = 0 ;
V_21 = atoi ( V_18 ) ;
V_23 . V_41 = V_21 ;
V_20 = F_8 ( & V_23 , - 1 , 0 , - 1 , 0 ) ;
if ( V_20 < 0 ) {
printf ( L_19 , V_21 , V_20 , strerror ( V_36 ) ) ;
return - 1 ;
}
V_42 [ V_38 - 1 ] = V_20 ;
F_9 ( V_20 , V_43 , 0 ) ;
F_9 ( V_20 , V_44 , V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_45 * V_46 , int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_47 / sizeof( struct V_45 ) ; V_48 ++ ) {
V_49 [ V_48 ] = F_11 ( V_46 [ V_48 ] . type ,
V_46 [ V_48 ] . V_50 ,
V_46 [ V_48 ] . V_51 ,
V_46 [ V_48 ] . V_52 ,
V_46 [ V_48 ] . V_53 ) ;
if ( V_49 [ V_48 ] < 0 ) {
printf ( L_20 ,
V_36 , strerror ( V_36 ) ) ;
return 1 ;
}
if ( V_46 [ V_48 ] . type == V_54 )
V_5 = V_49 [ V_48 ] ;
}
return 0 ;
}
static int F_12 ( T_1 * V_55 , int V_48 , T_2 * V_56 , char * * V_57 ,
T_3 * V_58 , T_4 * * V_59 )
{
T_5 * V_60 ;
V_60 = F_13 ( V_55 , V_48 ) ;
if ( ! V_60 )
return 1 ;
if ( F_14 ( V_60 , V_58 ) != V_58 )
return 2 ;
* V_57 = F_15 ( V_55 , V_56 -> V_61 , V_58 -> V_62 ) ;
if ( ! * V_57 || ! V_58 -> V_63 )
return 3 ;
* V_59 = F_16 ( V_60 , 0 ) ;
if ( ! * V_59 || F_16 ( V_60 , * V_59 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_4 * V_59 , T_4 * V_64 ,
T_3 * V_58 , struct V_7 * V_65 )
{
int V_48 , V_66 ;
V_66 = V_58 -> V_63 / V_58 -> V_67 ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
T_6 V_68 ;
T_7 V_69 ;
unsigned int V_70 ;
F_18 ( V_59 , V_48 , & V_69 ) ;
V_70 = V_69 . V_71 / sizeof( struct V_7 ) ;
F_19 ( V_64 , F_20 ( V_69 . V_72 ) , & V_68 ) ;
if ( V_65 [ V_70 ] . V_73 != ( V_74 | V_75 | V_76 ) ) {
printf ( L_21 ,
V_70 , V_65 [ V_70 ] . V_73 ) ;
return 1 ;
}
V_65 [ V_70 ] . V_77 = V_78 ;
V_65 [ V_70 ] . V_79 = V_49 [ V_68 . V_80 / sizeof( struct V_45 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_81 )
{
int V_19 , V_48 ;
T_1 * V_55 ;
T_2 V_56 ;
T_3 V_58 , V_82 ;
T_4 * V_59 , * V_83 , * V_64 = NULL ;
char * V_57 , * V_84 ;
if ( F_22 ( V_85 ) == V_86 )
return 1 ;
V_19 = F_5 ( V_81 , V_40 , 0 ) ;
if ( V_19 < 0 )
return 1 ;
V_55 = F_23 ( V_19 , V_87 , NULL ) ;
if ( ! V_55 )
return 1 ;
if ( F_24 ( V_55 , & V_56 ) != & V_56 )
return 1 ;
V_48 = system ( L_22 ) ;
for ( V_48 = 1 ; V_48 < V_56 . V_88 ; V_48 ++ ) {
if ( F_12 ( V_55 , V_48 , & V_56 , & V_57 , & V_58 , & V_59 ) )
continue;
if ( 0 )
printf ( L_23 ,
V_48 , V_57 , V_59 -> V_89 , V_59 -> V_90 ,
V_58 . V_91 , ( int ) V_58 . V_92 ) ;
if ( strcmp ( V_57 , L_24 ) == 0 ) {
V_93 [ V_48 ] = true ;
memcpy ( V_34 , V_59 -> V_89 , V_59 -> V_90 ) ;
} else if ( strcmp ( V_57 , L_25 ) == 0 ) {
V_93 [ V_48 ] = true ;
if ( V_59 -> V_90 != sizeof( int ) ) {
printf ( L_26 ,
V_59 -> V_90 ) ;
return 1 ;
}
memcpy ( & V_35 , V_59 -> V_89 , sizeof( int ) ) ;
} else if ( strcmp ( V_57 , L_27 ) == 0 ) {
V_93 [ V_48 ] = true ;
if ( F_10 ( V_59 -> V_89 , V_59 -> V_90 ) )
return 1 ;
} else if ( V_58 . V_94 == V_95 ) {
V_64 = V_59 ;
}
}
for ( V_48 = 1 ; V_48 < V_56 . V_88 ; V_48 ++ ) {
if ( F_12 ( V_55 , V_48 , & V_56 , & V_57 , & V_58 , & V_59 ) )
continue;
if ( V_58 . V_94 == V_96 ) {
struct V_7 * V_97 ;
if ( F_12 ( V_55 , V_58 . V_98 , & V_56 , & V_84 ,
& V_82 , & V_83 ) )
continue;
V_97 = (struct V_7 * ) V_83 -> V_89 ;
V_93 [ V_58 . V_98 ] = true ;
V_93 [ V_48 ] = true ;
if ( F_17 ( V_59 , V_64 , & V_58 , V_97 ) )
continue;
if ( memcmp ( V_84 , L_3 , 7 ) == 0 ||
memcmp ( V_84 , L_4 , 10 ) == 0 ||
memcmp ( V_84 , L_5 , 11 ) == 0 ||
memcmp ( V_84 , L_6 , 3 ) == 0 ||
memcmp ( V_84 , L_7 , 10 ) == 0 ||
memcmp ( V_84 , L_2 , 6 ) == 0 )
F_3 ( V_84 , V_97 , V_83 -> V_90 ) ;
}
}
for ( V_48 = 1 ; V_48 < V_56 . V_88 ; V_48 ++ ) {
if ( V_93 [ V_48 ] )
continue;
if ( F_12 ( V_55 , V_48 , & V_56 , & V_57 , & V_58 , & V_59 ) )
continue;
if ( memcmp ( V_57 , L_3 , 7 ) == 0 ||
memcmp ( V_57 , L_4 , 10 ) == 0 ||
memcmp ( V_57 , L_5 , 11 ) == 0 ||
memcmp ( V_57 , L_6 , 3 ) == 0 ||
memcmp ( V_57 , L_7 , 10 ) == 0 ||
memcmp ( V_57 , L_2 , 6 ) == 0 )
F_3 ( V_57 , V_59 -> V_89 , V_59 -> V_90 ) ;
}
F_7 ( V_19 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_99 ;
V_99 = F_5 ( V_39 L_28 , V_40 , 0 ) ;
if ( V_99 < 0 )
return;
while ( 1 ) {
static char V_18 [ 4096 ] ;
T_8 V_100 ;
V_100 = F_6 ( V_99 , V_18 , sizeof( V_18 ) ) ;
if ( V_100 > 0 ) {
V_18 [ V_100 ] = 0 ;
puts ( V_18 ) ;
}
}
}
static int F_26 ( const void * V_101 , const void * V_102 )
{
return ( (struct V_103 * ) V_101 ) -> V_104 - ( (struct V_103 * ) V_102 ) -> V_104 ;
}
int F_27 ( void )
{
T_9 * V_105 = fopen ( L_29 , L_30 ) ;
char V_106 [ 256 ] , V_18 [ 256 ] ;
char V_107 ;
void * V_104 ;
int V_48 = 0 ;
if ( ! V_105 )
return - V_108 ;
while ( ! feof ( V_105 ) ) {
if ( ! fgets ( V_18 , sizeof( V_18 ) , V_105 ) )
break;
if ( sscanf ( V_18 , L_31 , & V_104 , & V_107 , V_106 ) != 3 )
break;
if ( ! V_104 )
continue;
V_109 [ V_48 ] . V_104 = ( long ) V_104 ;
V_109 [ V_48 ] . V_110 = F_28 ( V_106 ) ;
V_48 ++ ;
}
V_111 = V_48 ;
qsort ( V_109 , V_111 , sizeof( struct V_103 ) , F_26 ) ;
return 0 ;
}
struct V_103 * F_29 ( long V_112 )
{
int V_113 = 0 , V_114 = V_111 ;
int V_115 ;
while ( V_113 < V_114 ) {
T_10 V_116 = V_113 + ( V_114 - V_113 ) / 2 ;
V_115 = V_112 - V_109 [ V_116 ] . V_104 ;
if ( V_115 < 0 )
V_114 = V_116 ;
else if ( V_115 > 0 )
V_113 = V_116 + 1 ;
else
return & V_109 [ V_116 ] ;
}
if ( V_113 >= 1 && V_109 [ V_113 - 1 ] . V_104 < V_112 &&
V_112 < V_109 [ V_113 ] . V_104 )
return & V_109 [ V_113 - 1 ] ;
return & V_109 [ 0 ] ;
}
