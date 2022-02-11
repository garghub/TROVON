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
enum V_13 V_14 ;
char V_15 [ 256 ] ;
int V_16 , V_17 , V_4 , V_18 ;
struct V_19 V_20 = {} ;
V_20 . type = V_21 ;
V_20 . V_22 = V_23 ;
V_20 . V_24 = 1 ;
V_20 . V_25 = 1 ;
if ( V_10 ) {
V_14 = V_26 ;
} else if ( V_11 || V_12 ) {
V_14 = V_27 ;
} else {
printf ( L_5 , V_1 ) ;
return - 1 ;
}
V_16 = F_4 ( V_14 , V_8 , V_9 , V_28 , V_29 ) ;
if ( V_16 < 0 ) {
printf ( L_6 , V_30 , V_31 ) ;
return - 1 ;
}
V_2 [ V_32 ++ ] = V_16 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_7 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_16 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_8 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_16 ) ;
snprintf ( V_15 , sizeof( V_15 ) ,
L_9 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_15 ) ;
if ( V_4 < 0 ) {
printf ( L_10 ,
V_1 , strerror ( V_30 ) ) ;
return - 1 ;
}
}
strcpy ( V_15 , V_33 ) ;
strcat ( V_15 , L_11 ) ;
strcat ( V_15 , V_1 ) ;
strcat ( V_15 , L_12 ) ;
V_17 = F_5 ( V_15 , V_34 , 0 ) ;
if ( V_17 < 0 ) {
printf ( L_13 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_17 , V_15 , sizeof( V_15 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_15 ) ) {
printf ( L_14 , V_1 , strerror ( V_30 ) ) ;
return - 1 ;
}
F_7 ( V_17 ) ;
V_15 [ V_4 ] = 0 ;
V_18 = atoi ( V_15 ) ;
V_20 . V_35 = V_18 ;
V_17 = F_8 ( & V_20 , - 1 , 0 , - 1 , 0 ) ;
if ( V_17 < 0 ) {
printf ( L_15 , V_18 , V_17 , strerror ( V_30 ) ) ;
return - 1 ;
}
V_36 [ V_32 - 1 ] = V_17 ;
F_9 ( V_17 , V_37 , 0 ) ;
F_9 ( V_17 , V_38 , V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_39 * V_40 , int V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 / sizeof( struct V_39 ) ; V_42 ++ ) {
V_43 [ V_42 ] = F_11 ( V_40 [ V_42 ] . type ,
V_40 [ V_42 ] . V_44 ,
V_40 [ V_42 ] . V_45 ,
V_40 [ V_42 ] . V_46 ,
V_40 [ V_42 ] . V_47 ) ;
if ( V_43 [ V_42 ] < 0 ) {
printf ( L_16 ,
V_30 , strerror ( V_30 ) ) ;
return 1 ;
}
if ( V_40 [ V_42 ] . type == V_48 )
V_5 = V_43 [ V_42 ] ;
}
return 0 ;
}
static int F_12 ( T_1 * V_49 , int V_42 , T_2 * V_50 , char * * V_51 ,
T_3 * V_52 , T_4 * * V_53 )
{
T_5 * V_54 ;
V_54 = F_13 ( V_49 , V_42 ) ;
if ( ! V_54 )
return 1 ;
if ( F_14 ( V_54 , V_52 ) != V_52 )
return 2 ;
* V_51 = F_15 ( V_49 , V_50 -> V_55 , V_52 -> V_56 ) ;
if ( ! * V_51 || ! V_52 -> V_57 )
return 3 ;
* V_53 = F_16 ( V_54 , 0 ) ;
if ( ! * V_53 || F_16 ( V_54 , * V_53 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_4 * V_53 , T_4 * V_58 ,
T_3 * V_52 , struct V_7 * V_59 )
{
int V_42 , V_60 ;
V_60 = V_52 -> V_57 / V_52 -> V_61 ;
for ( V_42 = 0 ; V_42 < V_60 ; V_42 ++ ) {
T_6 V_62 ;
T_7 V_63 ;
unsigned int V_64 ;
F_18 ( V_53 , V_42 , & V_63 ) ;
V_64 = V_63 . V_65 / sizeof( struct V_7 ) ;
F_19 ( V_58 , F_20 ( V_63 . V_66 ) , & V_62 ) ;
if ( V_59 [ V_64 ] . V_67 != ( V_68 | V_69 | V_70 ) ) {
printf ( L_17 ,
V_64 , V_59 [ V_64 ] . V_67 ) ;
return 1 ;
}
V_59 [ V_64 ] . V_71 = V_72 ;
V_59 [ V_64 ] . V_73 = V_43 [ V_62 . V_74 / sizeof( struct V_39 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_75 )
{
int V_16 , V_42 ;
T_1 * V_49 ;
T_2 V_50 ;
T_3 V_52 , V_76 ;
T_4 * V_53 , * V_77 , * V_58 = NULL ;
char * V_51 , * V_78 ;
if ( F_22 ( V_79 ) == V_80 )
return 1 ;
V_16 = F_5 ( V_75 , V_34 , 0 ) ;
if ( V_16 < 0 )
return 1 ;
V_49 = F_23 ( V_16 , V_81 , NULL ) ;
if ( ! V_49 )
return 1 ;
if ( F_24 ( V_49 , & V_50 ) != & V_50 )
return 1 ;
V_42 = system ( L_18 ) ;
for ( V_42 = 1 ; V_42 < V_50 . V_82 ; V_42 ++ ) {
if ( F_12 ( V_49 , V_42 , & V_50 , & V_51 , & V_52 , & V_53 ) )
continue;
if ( 0 )
printf ( L_19 ,
V_42 , V_51 , V_53 -> V_83 , V_53 -> V_84 ,
V_52 . V_85 , ( int ) V_52 . V_86 ) ;
if ( strcmp ( V_51 , L_20 ) == 0 ) {
V_87 [ V_42 ] = true ;
memcpy ( V_28 , V_53 -> V_83 , V_53 -> V_84 ) ;
} else if ( strcmp ( V_51 , L_21 ) == 0 ) {
V_87 [ V_42 ] = true ;
if ( V_53 -> V_84 != sizeof( int ) ) {
printf ( L_22 ,
V_53 -> V_84 ) ;
return 1 ;
}
memcpy ( & V_29 , V_53 -> V_83 , sizeof( int ) ) ;
} else if ( strcmp ( V_51 , L_23 ) == 0 ) {
V_87 [ V_42 ] = true ;
if ( F_10 ( V_53 -> V_83 , V_53 -> V_84 ) )
return 1 ;
} else if ( V_52 . V_88 == V_89 ) {
V_58 = V_53 ;
}
}
for ( V_42 = 1 ; V_42 < V_50 . V_82 ; V_42 ++ ) {
if ( F_12 ( V_49 , V_42 , & V_50 , & V_51 , & V_52 , & V_53 ) )
continue;
if ( V_52 . V_88 == V_90 ) {
struct V_7 * V_91 ;
if ( F_12 ( V_49 , V_52 . V_92 , & V_50 , & V_78 ,
& V_76 , & V_77 ) )
continue;
V_91 = (struct V_7 * ) V_77 -> V_83 ;
V_87 [ V_52 . V_92 ] = true ;
V_87 [ V_42 ] = true ;
if ( F_17 ( V_53 , V_58 , & V_52 , V_91 ) )
continue;
if ( memcmp ( V_78 , L_3 , 7 ) == 0 ||
memcmp ( V_78 , L_4 , 10 ) == 0 ||
memcmp ( V_78 , L_2 , 6 ) == 0 )
F_3 ( V_78 , V_91 , V_77 -> V_84 ) ;
}
}
for ( V_42 = 1 ; V_42 < V_50 . V_82 ; V_42 ++ ) {
if ( V_87 [ V_42 ] )
continue;
if ( F_12 ( V_49 , V_42 , & V_50 , & V_51 , & V_52 , & V_53 ) )
continue;
if ( memcmp ( V_51 , L_3 , 7 ) == 0 ||
memcmp ( V_51 , L_4 , 10 ) == 0 ||
memcmp ( V_51 , L_2 , 6 ) == 0 )
F_3 ( V_51 , V_53 -> V_83 , V_53 -> V_84 ) ;
}
F_7 ( V_16 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_93 ;
V_93 = F_5 ( V_33 L_24 , V_34 , 0 ) ;
if ( V_93 < 0 )
return;
while ( 1 ) {
static char V_15 [ 4096 ] ;
T_8 V_94 ;
V_94 = F_6 ( V_93 , V_15 , sizeof( V_15 ) ) ;
if ( V_94 > 0 ) {
V_15 [ V_94 ] = 0 ;
puts ( V_15 ) ;
}
}
}
static int F_26 ( const void * V_95 , const void * V_96 )
{
return ( (struct V_97 * ) V_95 ) -> V_98 - ( (struct V_97 * ) V_96 ) -> V_98 ;
}
int F_27 ( void )
{
T_9 * V_99 = fopen ( L_25 , L_26 ) ;
char V_100 [ 256 ] , V_15 [ 256 ] ;
char V_101 ;
void * V_98 ;
int V_42 = 0 ;
if ( ! V_99 )
return - V_102 ;
while ( ! feof ( V_99 ) ) {
if ( ! fgets ( V_15 , sizeof( V_15 ) , V_99 ) )
break;
if ( sscanf ( V_15 , L_27 , & V_98 , & V_101 , V_100 ) != 3 )
break;
if ( ! V_98 )
continue;
V_103 [ V_42 ] . V_98 = ( long ) V_98 ;
V_103 [ V_42 ] . V_104 = F_28 ( V_100 ) ;
V_42 ++ ;
}
V_105 = V_42 ;
qsort ( V_103 , V_105 , sizeof( struct V_97 ) , F_26 ) ;
return 0 ;
}
struct V_97 * F_29 ( long V_106 )
{
int V_107 = 0 , V_108 = V_105 ;
int V_109 ;
while ( V_107 < V_108 ) {
T_10 V_110 = V_107 + ( V_108 - V_107 ) / 2 ;
V_109 = V_106 - V_103 [ V_110 ] . V_98 ;
if ( V_109 < 0 )
V_108 = V_110 ;
else if ( V_109 > 0 )
V_107 = V_110 + 1 ;
else
return & V_103 [ V_110 ] ;
}
if ( V_107 >= 1 && V_103 [ V_107 - 1 ] . V_98 < V_106 &&
V_106 < V_103 [ V_107 ] . V_98 )
return & V_103 [ V_107 - 1 ] ;
return & V_103 [ 0 ] ;
}
