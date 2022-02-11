static int F_1 ( const char * V_1 , struct V_2 * V_3 , int V_4 )
{
bool V_5 = strncmp ( V_1 , L_1 , 6 ) == 0 ;
bool V_6 = strncmp ( V_1 , L_2 , 7 ) == 0 ;
bool V_7 = strncmp ( V_1 , L_3 , 10 ) == 0 ;
enum V_8 V_9 ;
char V_10 [ 256 ] ;
int V_11 , V_12 , V_13 , V_14 ;
struct V_15 V_16 = {} ;
V_16 . type = V_17 ;
V_16 . V_18 = V_19 ;
V_16 . V_20 = 1 ;
V_16 . V_21 = 1 ;
if ( V_5 ) {
V_9 = V_22 ;
} else if ( V_6 || V_7 ) {
V_9 = V_23 ;
} else {
printf ( L_4 , V_1 ) ;
return - 1 ;
}
if ( V_6 || V_7 ) {
if ( V_6 )
V_1 += 7 ;
else
V_1 += 10 ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_5 ,
V_6 ? 'p' : 'r' , V_1 , V_1 ) ;
V_13 = system ( V_10 ) ;
if ( V_13 < 0 ) {
printf ( L_6 ,
V_1 , strerror ( V_24 ) ) ;
return - 1 ;
}
}
V_11 = F_2 ( V_9 , V_3 , V_4 , V_25 , V_26 ) ;
if ( V_11 < 0 ) {
printf ( L_7 , V_24 , V_27 ) ;
return - 1 ;
}
V_28 [ V_29 ++ ] = V_11 ;
if ( V_5 )
return 0 ;
strcpy ( V_10 , V_30 ) ;
strcat ( V_10 , L_8 ) ;
strcat ( V_10 , V_1 ) ;
strcat ( V_10 , L_9 ) ;
V_12 = F_3 ( V_10 , V_31 , 0 ) ;
if ( V_12 < 0 ) {
printf ( L_10 , V_1 ) ;
return - 1 ;
}
V_13 = F_4 ( V_12 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 || V_13 >= sizeof( V_10 ) ) {
printf ( L_11 , V_1 , strerror ( V_24 ) ) ;
return - 1 ;
}
F_5 ( V_12 ) ;
V_10 [ V_13 ] = 0 ;
V_14 = atoi ( V_10 ) ;
V_16 . V_32 = V_14 ;
V_12 = F_6 ( & V_16 , - 1 , 0 , - 1 , 0 ) ;
if ( V_12 < 0 ) {
printf ( L_12 , V_14 , V_12 , strerror ( V_24 ) ) ;
return - 1 ;
}
V_33 [ V_29 - 1 ] = V_12 ;
F_7 ( V_12 , V_34 , 0 ) ;
F_7 ( V_12 , V_35 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_36 * V_37 , int V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_38 / sizeof( struct V_36 ) ; V_39 ++ ) {
V_40 [ V_39 ] = F_9 ( V_37 [ V_39 ] . type ,
V_37 [ V_39 ] . V_41 ,
V_37 [ V_39 ] . V_42 ,
V_37 [ V_39 ] . V_43 ) ;
if ( V_40 [ V_39 ] < 0 )
return 1 ;
}
return 0 ;
}
static int F_10 ( T_1 * V_44 , int V_39 , T_2 * V_45 , char * * V_46 ,
T_3 * V_47 , T_4 * * V_48 )
{
T_5 * V_49 ;
V_49 = F_11 ( V_44 , V_39 ) ;
if ( ! V_49 )
return 1 ;
if ( F_12 ( V_49 , V_47 ) != V_47 )
return 2 ;
* V_46 = F_13 ( V_44 , V_45 -> V_50 , V_47 -> V_51 ) ;
if ( ! * V_46 || ! V_47 -> V_52 )
return 3 ;
* V_48 = F_14 ( V_49 , 0 ) ;
if ( ! * V_48 || F_14 ( V_49 , * V_48 ) != NULL )
return 4 ;
return 0 ;
}
static int F_15 ( T_4 * V_48 , T_4 * V_53 ,
T_3 * V_47 , struct V_2 * V_54 )
{
int V_39 , V_55 ;
V_55 = V_47 -> V_52 / V_47 -> V_56 ;
for ( V_39 = 0 ; V_39 < V_55 ; V_39 ++ ) {
T_6 V_57 ;
T_7 V_58 ;
unsigned int V_59 ;
F_16 ( V_48 , V_39 , & V_58 ) ;
V_59 = V_58 . V_60 / sizeof( struct V_2 ) ;
F_17 ( V_53 , F_18 ( V_58 . V_61 ) , & V_57 ) ;
if ( V_54 [ V_59 ] . V_62 != ( V_63 | V_64 | V_65 ) ) {
printf ( L_13 ,
V_59 , V_54 [ V_59 ] . V_62 ) ;
return 1 ;
}
V_54 [ V_59 ] . V_66 = V_67 ;
V_54 [ V_59 ] . V_68 = V_40 [ V_57 . V_69 / sizeof( struct V_36 ) ] ;
}
return 0 ;
}
int F_19 ( char * V_70 )
{
int V_11 , V_39 ;
T_1 * V_44 ;
T_2 V_45 ;
T_3 V_47 , V_71 ;
T_4 * V_48 , * V_72 , * V_53 = NULL ;
char * V_46 , * V_73 ;
if ( F_20 ( V_74 ) == V_75 )
return 1 ;
V_11 = F_3 ( V_70 , V_31 , 0 ) ;
if ( V_11 < 0 )
return 1 ;
V_44 = F_21 ( V_11 , V_76 , NULL ) ;
if ( ! V_44 )
return 1 ;
if ( F_22 ( V_44 , & V_45 ) != & V_45 )
return 1 ;
V_39 = system ( L_14 ) ;
for ( V_39 = 1 ; V_39 < V_45 . V_77 ; V_39 ++ ) {
if ( F_10 ( V_44 , V_39 , & V_45 , & V_46 , & V_47 , & V_48 ) )
continue;
if ( 0 )
printf ( L_15 ,
V_39 , V_46 , V_48 -> V_78 , V_48 -> V_79 ,
V_47 . V_80 , ( int ) V_47 . V_81 ) ;
if ( strcmp ( V_46 , L_16 ) == 0 ) {
V_82 [ V_39 ] = true ;
memcpy ( V_25 , V_48 -> V_78 , V_48 -> V_79 ) ;
} else if ( strcmp ( V_46 , L_17 ) == 0 ) {
V_82 [ V_39 ] = true ;
if ( V_48 -> V_79 != sizeof( int ) ) {
printf ( L_18 ,
V_48 -> V_79 ) ;
return 1 ;
}
memcpy ( & V_26 , V_48 -> V_78 , sizeof( int ) ) ;
} else if ( strcmp ( V_46 , L_19 ) == 0 ) {
V_82 [ V_39 ] = true ;
if ( F_8 ( V_48 -> V_78 , V_48 -> V_79 ) )
return 1 ;
} else if ( V_47 . V_83 == V_84 ) {
V_53 = V_48 ;
}
}
for ( V_39 = 1 ; V_39 < V_45 . V_77 ; V_39 ++ ) {
if ( F_10 ( V_44 , V_39 , & V_45 , & V_46 , & V_47 , & V_48 ) )
continue;
if ( V_47 . V_83 == V_85 ) {
struct V_2 * V_86 ;
if ( F_10 ( V_44 , V_47 . V_87 , & V_45 , & V_73 ,
& V_71 , & V_72 ) )
continue;
V_86 = (struct V_2 * ) V_72 -> V_78 ;
V_82 [ V_47 . V_87 ] = true ;
V_82 [ V_39 ] = true ;
if ( F_15 ( V_48 , V_53 , & V_47 , V_86 ) )
continue;
if ( memcmp ( V_73 , L_2 , 7 ) == 0 ||
memcmp ( V_73 , L_3 , 10 ) == 0 ||
memcmp ( V_73 , L_1 , 6 ) == 0 )
F_1 ( V_73 , V_86 , V_72 -> V_79 ) ;
}
}
for ( V_39 = 1 ; V_39 < V_45 . V_77 ; V_39 ++ ) {
if ( V_82 [ V_39 ] )
continue;
if ( F_10 ( V_44 , V_39 , & V_45 , & V_46 , & V_47 , & V_48 ) )
continue;
if ( memcmp ( V_46 , L_2 , 7 ) == 0 ||
memcmp ( V_46 , L_3 , 10 ) == 0 ||
memcmp ( V_46 , L_1 , 6 ) == 0 )
F_1 ( V_46 , V_48 -> V_78 , V_48 -> V_79 ) ;
}
F_5 ( V_11 ) ;
return 0 ;
}
void F_23 ( void )
{
int V_88 ;
V_88 = F_3 ( V_30 L_20 , V_31 , 0 ) ;
if ( V_88 < 0 )
return;
while ( 1 ) {
static char V_10 [ 4096 ] ;
T_8 V_89 ;
V_89 = F_4 ( V_88 , V_10 , sizeof( V_10 ) ) ;
if ( V_89 > 0 ) {
V_10 [ V_89 ] = 0 ;
puts ( V_10 ) ;
}
}
}
