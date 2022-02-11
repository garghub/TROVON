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
enum V_15 V_16 ;
char V_17 [ 256 ] ;
int V_18 , V_19 , V_4 , V_20 ;
struct V_21 V_22 = {} ;
V_22 . type = V_23 ;
V_22 . V_24 = V_25 ;
V_22 . V_26 = 1 ;
V_22 . V_27 = 1 ;
if ( V_10 ) {
V_16 = V_28 ;
} else if ( V_11 || V_12 ) {
V_16 = V_29 ;
} else if ( V_13 ) {
V_16 = V_30 ;
} else if ( V_14 ) {
V_16 = V_31 ;
} else {
printf ( L_7 , V_1 ) ;
return - 1 ;
}
V_18 = F_4 ( V_16 , V_8 , V_9 , V_32 , V_33 ) ;
if ( V_18 < 0 ) {
printf ( L_8 , V_34 , V_35 ) ;
return - 1 ;
}
V_2 [ V_36 ++ ] = V_18 ;
if ( V_14 )
return 0 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_9 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_18 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_10 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_18 ) ;
snprintf ( V_17 , sizeof( V_17 ) ,
L_11 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_17 ) ;
if ( V_4 < 0 ) {
printf ( L_12 ,
V_1 , strerror ( V_34 ) ) ;
return - 1 ;
}
strcpy ( V_17 , V_37 ) ;
strcat ( V_17 , L_13 ) ;
strcat ( V_17 , V_1 ) ;
strcat ( V_17 , L_14 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_10 ) ;
return - 1 ;
}
strcpy ( V_17 , V_37 ) ;
strcat ( V_17 , L_15 ) ;
strcat ( V_17 , V_1 ) ;
strcat ( V_17 , L_14 ) ;
}
V_19 = F_5 ( V_17 , V_38 , 0 ) ;
if ( V_19 < 0 ) {
printf ( L_16 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_19 , V_17 , sizeof( V_17 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_17 ) ) {
printf ( L_17 , V_1 , strerror ( V_34 ) ) ;
return - 1 ;
}
F_7 ( V_19 ) ;
V_17 [ V_4 ] = 0 ;
V_20 = atoi ( V_17 ) ;
V_22 . V_39 = V_20 ;
V_19 = F_8 ( & V_22 , - 1 , 0 , - 1 , 0 ) ;
if ( V_19 < 0 ) {
printf ( L_18 , V_20 , V_19 , strerror ( V_34 ) ) ;
return - 1 ;
}
V_40 [ V_36 - 1 ] = V_19 ;
F_9 ( V_19 , V_41 , 0 ) ;
F_9 ( V_19 , V_42 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_43 * V_44 , int V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_45 / sizeof( struct V_43 ) ; V_46 ++ ) {
V_47 [ V_46 ] = F_11 ( V_44 [ V_46 ] . type ,
V_44 [ V_46 ] . V_48 ,
V_44 [ V_46 ] . V_49 ,
V_44 [ V_46 ] . V_50 ,
V_44 [ V_46 ] . V_51 ) ;
if ( V_47 [ V_46 ] < 0 ) {
printf ( L_19 ,
V_34 , strerror ( V_34 ) ) ;
return 1 ;
}
if ( V_44 [ V_46 ] . type == V_52 )
V_5 = V_47 [ V_46 ] ;
}
return 0 ;
}
static int F_12 ( T_1 * V_53 , int V_46 , T_2 * V_54 , char * * V_55 ,
T_3 * V_56 , T_4 * * V_57 )
{
T_5 * V_58 ;
V_58 = F_13 ( V_53 , V_46 ) ;
if ( ! V_58 )
return 1 ;
if ( F_14 ( V_58 , V_56 ) != V_56 )
return 2 ;
* V_55 = F_15 ( V_53 , V_54 -> V_59 , V_56 -> V_60 ) ;
if ( ! * V_55 || ! V_56 -> V_61 )
return 3 ;
* V_57 = F_16 ( V_58 , 0 ) ;
if ( ! * V_57 || F_16 ( V_58 , * V_57 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_4 * V_57 , T_4 * V_62 ,
T_3 * V_56 , struct V_7 * V_63 )
{
int V_46 , V_64 ;
V_64 = V_56 -> V_61 / V_56 -> V_65 ;
for ( V_46 = 0 ; V_46 < V_64 ; V_46 ++ ) {
T_6 V_66 ;
T_7 V_67 ;
unsigned int V_68 ;
F_18 ( V_57 , V_46 , & V_67 ) ;
V_68 = V_67 . V_69 / sizeof( struct V_7 ) ;
F_19 ( V_62 , F_20 ( V_67 . V_70 ) , & V_66 ) ;
if ( V_63 [ V_68 ] . V_71 != ( V_72 | V_73 | V_74 ) ) {
printf ( L_20 ,
V_68 , V_63 [ V_68 ] . V_71 ) ;
return 1 ;
}
V_63 [ V_68 ] . V_75 = V_76 ;
V_63 [ V_68 ] . V_77 = V_47 [ V_66 . V_78 / sizeof( struct V_43 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_79 )
{
int V_18 , V_46 ;
T_1 * V_53 ;
T_2 V_54 ;
T_3 V_56 , V_80 ;
T_4 * V_57 , * V_81 , * V_62 = NULL ;
char * V_55 , * V_82 ;
if ( F_22 ( V_83 ) == V_84 )
return 1 ;
V_18 = F_5 ( V_79 , V_38 , 0 ) ;
if ( V_18 < 0 )
return 1 ;
V_53 = F_23 ( V_18 , V_85 , NULL ) ;
if ( ! V_53 )
return 1 ;
if ( F_24 ( V_53 , & V_54 ) != & V_54 )
return 1 ;
V_46 = system ( L_21 ) ;
for ( V_46 = 1 ; V_46 < V_54 . V_86 ; V_46 ++ ) {
if ( F_12 ( V_53 , V_46 , & V_54 , & V_55 , & V_56 , & V_57 ) )
continue;
if ( 0 )
printf ( L_22 ,
V_46 , V_55 , V_57 -> V_87 , V_57 -> V_88 ,
V_56 . V_89 , ( int ) V_56 . V_90 ) ;
if ( strcmp ( V_55 , L_23 ) == 0 ) {
V_91 [ V_46 ] = true ;
memcpy ( V_32 , V_57 -> V_87 , V_57 -> V_88 ) ;
} else if ( strcmp ( V_55 , L_24 ) == 0 ) {
V_91 [ V_46 ] = true ;
if ( V_57 -> V_88 != sizeof( int ) ) {
printf ( L_25 ,
V_57 -> V_88 ) ;
return 1 ;
}
memcpy ( & V_33 , V_57 -> V_87 , sizeof( int ) ) ;
} else if ( strcmp ( V_55 , L_26 ) == 0 ) {
V_91 [ V_46 ] = true ;
if ( F_10 ( V_57 -> V_87 , V_57 -> V_88 ) )
return 1 ;
} else if ( V_56 . V_92 == V_93 ) {
V_62 = V_57 ;
}
}
for ( V_46 = 1 ; V_46 < V_54 . V_86 ; V_46 ++ ) {
if ( F_12 ( V_53 , V_46 , & V_54 , & V_55 , & V_56 , & V_57 ) )
continue;
if ( V_56 . V_92 == V_94 ) {
struct V_7 * V_95 ;
if ( F_12 ( V_53 , V_56 . V_96 , & V_54 , & V_82 ,
& V_80 , & V_81 ) )
continue;
V_95 = (struct V_7 * ) V_81 -> V_87 ;
V_91 [ V_56 . V_96 ] = true ;
V_91 [ V_46 ] = true ;
if ( F_17 ( V_57 , V_62 , & V_56 , V_95 ) )
continue;
if ( memcmp ( V_82 , L_3 , 7 ) == 0 ||
memcmp ( V_82 , L_4 , 10 ) == 0 ||
memcmp ( V_82 , L_5 , 11 ) == 0 ||
memcmp ( V_82 , L_6 , 3 ) == 0 ||
memcmp ( V_82 , L_2 , 6 ) == 0 )
F_3 ( V_82 , V_95 , V_81 -> V_88 ) ;
}
}
for ( V_46 = 1 ; V_46 < V_54 . V_86 ; V_46 ++ ) {
if ( V_91 [ V_46 ] )
continue;
if ( F_12 ( V_53 , V_46 , & V_54 , & V_55 , & V_56 , & V_57 ) )
continue;
if ( memcmp ( V_55 , L_3 , 7 ) == 0 ||
memcmp ( V_55 , L_4 , 10 ) == 0 ||
memcmp ( V_55 , L_5 , 11 ) == 0 ||
memcmp ( V_55 , L_6 , 3 ) == 0 ||
memcmp ( V_55 , L_2 , 6 ) == 0 )
F_3 ( V_55 , V_57 -> V_87 , V_57 -> V_88 ) ;
}
F_7 ( V_18 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_97 ;
V_97 = F_5 ( V_37 L_27 , V_38 , 0 ) ;
if ( V_97 < 0 )
return;
while ( 1 ) {
static char V_17 [ 4096 ] ;
T_8 V_98 ;
V_98 = F_6 ( V_97 , V_17 , sizeof( V_17 ) ) ;
if ( V_98 > 0 ) {
V_17 [ V_98 ] = 0 ;
puts ( V_17 ) ;
}
}
}
static int F_26 ( const void * V_99 , const void * V_100 )
{
return ( (struct V_101 * ) V_99 ) -> V_102 - ( (struct V_101 * ) V_100 ) -> V_102 ;
}
int F_27 ( void )
{
T_9 * V_103 = fopen ( L_28 , L_29 ) ;
char V_104 [ 256 ] , V_17 [ 256 ] ;
char V_105 ;
void * V_102 ;
int V_46 = 0 ;
if ( ! V_103 )
return - V_106 ;
while ( ! feof ( V_103 ) ) {
if ( ! fgets ( V_17 , sizeof( V_17 ) , V_103 ) )
break;
if ( sscanf ( V_17 , L_30 , & V_102 , & V_105 , V_104 ) != 3 )
break;
if ( ! V_102 )
continue;
V_107 [ V_46 ] . V_102 = ( long ) V_102 ;
V_107 [ V_46 ] . V_108 = F_28 ( V_104 ) ;
V_46 ++ ;
}
V_109 = V_46 ;
qsort ( V_107 , V_109 , sizeof( struct V_101 ) , F_26 ) ;
return 0 ;
}
struct V_101 * F_29 ( long V_110 )
{
int V_111 = 0 , V_112 = V_109 ;
int V_113 ;
while ( V_111 < V_112 ) {
T_10 V_114 = V_111 + ( V_112 - V_111 ) / 2 ;
V_113 = V_110 - V_107 [ V_114 ] . V_102 ;
if ( V_113 < 0 )
V_112 = V_114 ;
else if ( V_113 > 0 )
V_111 = V_114 + 1 ;
else
return & V_107 [ V_114 ] ;
}
if ( V_111 >= 1 && V_107 [ V_111 - 1 ] . V_102 < V_110 &&
V_110 < V_107 [ V_111 ] . V_102 )
return & V_107 [ V_111 - 1 ] ;
return & V_107 [ 0 ] ;
}
