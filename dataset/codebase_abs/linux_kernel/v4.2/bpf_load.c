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
V_40 [ V_42 ] . V_46 ) ;
if ( V_43 [ V_42 ] < 0 )
return 1 ;
if ( V_40 [ V_42 ] . type == V_47 )
V_5 = V_43 [ V_42 ] ;
}
return 0 ;
}
static int F_12 ( T_1 * V_48 , int V_42 , T_2 * V_49 , char * * V_50 ,
T_3 * V_51 , T_4 * * V_52 )
{
T_5 * V_53 ;
V_53 = F_13 ( V_48 , V_42 ) ;
if ( ! V_53 )
return 1 ;
if ( F_14 ( V_53 , V_51 ) != V_51 )
return 2 ;
* V_50 = F_15 ( V_48 , V_49 -> V_54 , V_51 -> V_55 ) ;
if ( ! * V_50 || ! V_51 -> V_56 )
return 3 ;
* V_52 = F_16 ( V_53 , 0 ) ;
if ( ! * V_52 || F_16 ( V_53 , * V_52 ) != NULL )
return 4 ;
return 0 ;
}
static int F_17 ( T_4 * V_52 , T_4 * V_57 ,
T_3 * V_51 , struct V_7 * V_58 )
{
int V_42 , V_59 ;
V_59 = V_51 -> V_56 / V_51 -> V_60 ;
for ( V_42 = 0 ; V_42 < V_59 ; V_42 ++ ) {
T_6 V_61 ;
T_7 V_62 ;
unsigned int V_63 ;
F_18 ( V_52 , V_42 , & V_62 ) ;
V_63 = V_62 . V_64 / sizeof( struct V_7 ) ;
F_19 ( V_57 , F_20 ( V_62 . V_65 ) , & V_61 ) ;
if ( V_58 [ V_63 ] . V_66 != ( V_67 | V_68 | V_69 ) ) {
printf ( L_16 ,
V_63 , V_58 [ V_63 ] . V_66 ) ;
return 1 ;
}
V_58 [ V_63 ] . V_70 = V_71 ;
V_58 [ V_63 ] . V_72 = V_43 [ V_61 . V_73 / sizeof( struct V_39 ) ] ;
}
return 0 ;
}
int F_21 ( char * V_74 )
{
int V_16 , V_42 ;
T_1 * V_48 ;
T_2 V_49 ;
T_3 V_51 , V_75 ;
T_4 * V_52 , * V_76 , * V_57 = NULL ;
char * V_50 , * V_77 ;
if ( F_22 ( V_78 ) == V_79 )
return 1 ;
V_16 = F_5 ( V_74 , V_34 , 0 ) ;
if ( V_16 < 0 )
return 1 ;
V_48 = F_23 ( V_16 , V_80 , NULL ) ;
if ( ! V_48 )
return 1 ;
if ( F_24 ( V_48 , & V_49 ) != & V_49 )
return 1 ;
V_42 = system ( L_17 ) ;
for ( V_42 = 1 ; V_42 < V_49 . V_81 ; V_42 ++ ) {
if ( F_12 ( V_48 , V_42 , & V_49 , & V_50 , & V_51 , & V_52 ) )
continue;
if ( 0 )
printf ( L_18 ,
V_42 , V_50 , V_52 -> V_82 , V_52 -> V_83 ,
V_51 . V_84 , ( int ) V_51 . V_85 ) ;
if ( strcmp ( V_50 , L_19 ) == 0 ) {
V_86 [ V_42 ] = true ;
memcpy ( V_28 , V_52 -> V_82 , V_52 -> V_83 ) ;
} else if ( strcmp ( V_50 , L_20 ) == 0 ) {
V_86 [ V_42 ] = true ;
if ( V_52 -> V_83 != sizeof( int ) ) {
printf ( L_21 ,
V_52 -> V_83 ) ;
return 1 ;
}
memcpy ( & V_29 , V_52 -> V_82 , sizeof( int ) ) ;
} else if ( strcmp ( V_50 , L_22 ) == 0 ) {
V_86 [ V_42 ] = true ;
if ( F_10 ( V_52 -> V_82 , V_52 -> V_83 ) )
return 1 ;
} else if ( V_51 . V_87 == V_88 ) {
V_57 = V_52 ;
}
}
for ( V_42 = 1 ; V_42 < V_49 . V_81 ; V_42 ++ ) {
if ( F_12 ( V_48 , V_42 , & V_49 , & V_50 , & V_51 , & V_52 ) )
continue;
if ( V_51 . V_87 == V_89 ) {
struct V_7 * V_90 ;
if ( F_12 ( V_48 , V_51 . V_91 , & V_49 , & V_77 ,
& V_75 , & V_76 ) )
continue;
V_90 = (struct V_7 * ) V_76 -> V_82 ;
V_86 [ V_51 . V_91 ] = true ;
V_86 [ V_42 ] = true ;
if ( F_17 ( V_52 , V_57 , & V_51 , V_90 ) )
continue;
if ( memcmp ( V_77 , L_3 , 7 ) == 0 ||
memcmp ( V_77 , L_4 , 10 ) == 0 ||
memcmp ( V_77 , L_2 , 6 ) == 0 )
F_3 ( V_77 , V_90 , V_76 -> V_83 ) ;
}
}
for ( V_42 = 1 ; V_42 < V_49 . V_81 ; V_42 ++ ) {
if ( V_86 [ V_42 ] )
continue;
if ( F_12 ( V_48 , V_42 , & V_49 , & V_50 , & V_51 , & V_52 ) )
continue;
if ( memcmp ( V_50 , L_3 , 7 ) == 0 ||
memcmp ( V_50 , L_4 , 10 ) == 0 ||
memcmp ( V_50 , L_2 , 6 ) == 0 )
F_3 ( V_50 , V_52 -> V_82 , V_52 -> V_83 ) ;
}
F_7 ( V_16 ) ;
return 0 ;
}
void F_25 ( void )
{
int V_92 ;
V_92 = F_5 ( V_33 L_23 , V_34 , 0 ) ;
if ( V_92 < 0 )
return;
while ( 1 ) {
static char V_15 [ 4096 ] ;
T_8 V_93 ;
V_93 = F_6 ( V_92 , V_15 , sizeof( V_15 ) ) ;
if ( V_93 > 0 ) {
V_15 [ V_93 ] = 0 ;
puts ( V_15 ) ;
}
}
}
