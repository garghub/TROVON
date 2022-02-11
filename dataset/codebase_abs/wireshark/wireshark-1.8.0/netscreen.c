static T_1 F_1 ( const T_2 * line )
{
while ( * line ) {
if ( isspace ( ( V_1 ) * line ) ) {
line ++ ;
continue;
} else {
break;
}
}
if ( * line == '\0' )
return TRUE ;
else
return FALSE ;
}
static T_1 F_2 ( const T_2 * line )
{
int V_2 = V_3 ;
while ( V_2 -- > 0 ) {
if ( isspace ( ( V_1 ) * line ) ) {
line ++ ;
continue;
} else {
return FALSE ;
}
}
return TRUE ;
}
static T_3 F_3 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 ,
char * V_7 )
{
T_3 V_8 ;
char V_9 [ V_10 ] ;
while ( 1 ) {
V_8 = F_4 ( V_4 -> V_11 ) ;
if ( V_8 == - 1 ) {
* V_5 = F_5 ( V_4 -> V_11 , V_6 ) ;
V_7 = NULL ;
return - 1 ;
}
if ( F_6 ( V_9 , sizeof( V_9 ) , V_4 -> V_11 ) != NULL ) {
if ( strstr ( V_9 , V_12 ) ||
strstr ( V_9 , V_13 ) ) {
F_7 ( V_7 , V_9 , V_10 ) ;
return V_8 ;
}
} else {
if ( F_8 ( V_4 -> V_11 ) ) {
* V_5 = 0 ;
} else {
* V_5 = F_5 ( V_4 -> V_11 , V_6 ) ;
}
break;
}
}
V_7 = NULL ;
return - 1 ;
}
static T_1 F_9 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 )
{
char V_9 [ V_10 ] ;
T_5 V_14 , line ;
V_9 [ V_10 - 1 ] = '\0' ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_6 ( V_9 , V_10 , V_4 -> V_11 ) != NULL ) {
V_14 = ( T_5 ) strlen ( V_9 ) ;
if ( V_14 < strlen ( V_16 ) ||
V_14 < strlen ( V_17 ) ) {
continue;
}
if ( strstr ( V_9 , V_16 ) ||
strstr ( V_9 , V_17 ) ) {
return TRUE ;
}
} else {
if ( F_8 ( V_4 -> V_11 ) )
* V_5 = 0 ;
else
* V_5 = F_5 ( V_4 -> V_11 , V_6 ) ;
return FALSE ;
}
}
* V_5 = 0 ;
return FALSE ;
}
int F_10 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 )
{
if ( ! F_9 ( V_4 , V_5 , V_6 ) ) {
if ( * V_5 == 0 )
return 0 ;
else
return - 1 ;
}
if ( F_11 ( V_4 -> V_11 , 0L , V_18 , V_5 ) == - 1 )
return - 1 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = V_29 ;
return 1 ;
}
static T_1 V_25 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 ,
T_3 * V_30 )
{
T_3 V_31 ;
T_6 * V_9 ;
int V_32 , V_33 ;
char line [ V_10 ] ;
char V_34 [ V_35 ] ;
T_1 V_36 ;
char V_37 [ 13 ] ;
T_2 V_38 [ 13 ] ;
V_31 = F_3 ( V_4 , V_5 , V_6 , line ) ;
if ( V_31 < 0 )
return FALSE ;
V_4 -> V_39 . V_40 = V_41 | V_42 ;
V_32 = F_12 ( V_4 , line , V_34 , & V_36 , V_37 ,
& V_4 -> V_43 , V_5 , V_6 ) ;
if ( V_32 == - 1 )
return FALSE ;
F_13 ( V_4 -> V_44 , V_45 ) ;
V_9 = F_14 ( V_4 -> V_44 ) ;
if ( ( V_33 = F_15 ( V_4 -> V_11 , V_32 , V_9 , V_5 ,
V_6 ) ) == - 1 ) {
return FALSE ;
}
if ( strncmp ( V_34 , L_1 , 4 ) == 0 ) {
F_16 ( V_38 , 13 , L_2 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
if ( strncmp ( V_38 , V_37 , 12 ) == 0 )
V_4 -> V_39 . V_46 = V_47 ;
else
V_4 -> V_39 . V_46 = V_48 ;
}
else if ( strncmp ( V_34 , L_3 , 4 ) == 0 )
V_4 -> V_39 . V_46 = V_48 ;
else
V_4 -> V_39 . V_46 = V_47 ;
if ( V_4 -> V_19 == V_20 )
V_4 -> V_19 = V_4 -> V_39 . V_46 ;
else {
if ( V_4 -> V_19 != V_4 -> V_39 . V_46 )
V_4 -> V_19 = V_49 ;
}
V_4 -> V_39 . V_33 = V_33 ;
* V_30 = V_31 ;
return TRUE ;
}
static T_1
V_27 ( T_4 * V_4 , T_3 V_50 ,
union V_51 * V_43 , T_6 * V_52 , int V_53 ,
int * V_5 , T_2 * * V_6 )
{
char line [ V_10 ] ;
char V_34 [ V_35 ] ;
T_1 V_36 ;
char V_37 [ 13 ] ;
if ( F_11 ( V_4 -> V_54 , V_50 , V_18 , V_5 ) == - 1 ) {
return FALSE ;
}
if ( F_6 ( line , V_10 , V_4 -> V_54 ) == NULL ) {
* V_5 = F_5 ( V_4 -> V_54 , V_6 ) ;
if ( * V_5 == 0 ) {
* V_5 = V_55 ;
}
return FALSE ;
}
if ( F_12 ( NULL , line , V_34 , & V_36 , V_37 ,
V_43 , V_5 , V_6 ) == - 1 ) {
return FALSE ;
}
if ( F_15 ( V_4 -> V_54 , V_53 , V_52 , V_5 , V_6 )
== - 1 ) {
return FALSE ;
}
return TRUE ;
}
static int
F_12 ( T_4 * V_4 , const char * line , char * V_34 ,
T_1 * V_36 , char * V_37 , union V_51 * V_43 V_56 ,
int * V_5 , T_2 * * V_6 )
{
int V_57 ;
int V_58 , V_32 ;
char V_59 [ 2 ] ;
char V_60 [ 13 ] ;
if ( sscanf ( line , L_4 ,
& V_57 , & V_58 , V_34 , V_59 , & V_32 , V_60 , V_37 ) < 5 ) {
* V_5 = V_61 ;
* V_6 = F_17 ( L_5 ) ;
return - 1 ;
}
* V_36 = ( V_59 [ 0 ] == 'o' ? V_62 : V_63 ) ;
if ( V_4 ) {
V_4 -> V_39 . V_64 . V_65 = V_57 ;
V_4 -> V_39 . V_64 . V_66 = V_58 * 100000000 ;
V_4 -> V_39 . V_53 = V_32 ;
}
return V_32 ;
}
static int
F_15 ( T_7 V_11 , int V_32 , T_6 * V_9 , int * V_5 , T_2 * * V_6 )
{
T_2 line [ V_10 ] ;
int V_67 , V_2 = 0 , V_31 = 0 ;
while( 1 ) {
if ( F_6 ( line , V_10 , V_11 ) == NULL ) {
break;
}
if ( F_1 ( line ) ) {
break;
}
if( strlen ( line ) != 98 )
line [ 62 ] = '\0' ;
else
line [ 76 ] = '\0' ;
V_67 = F_18 ( line , V_9 , V_31 ) ;
if ( V_31 == 0 && V_67 < 6 ) {
if ( F_2 ( line ) ) {
if ( ++ V_2 <= V_68 ) {
continue;
}
} else {
* V_5 = V_61 ;
* V_6 = F_17 ( L_6 ) ;
return - 1 ;
}
}
if( V_67 == - 1 ) {
* V_5 = V_61 ;
* V_6 = F_17 ( L_6 ) ;
return - 1 ;
}
V_31 += V_67 ;
if( V_31 > V_32 ) {
* V_5 = V_61 ;
* V_6 = F_17 ( L_7 ) ;
return - 1 ;
}
}
return V_31 ;
}
static int
F_18 ( char * V_69 , T_6 * V_9 , T_5 V_70 )
{
int V_71 , V_2 ;
unsigned int V_72 [ 16 ] ;
V_71 = sscanf ( V_69 , L_8 ,
& V_72 [ 0 ] , & V_72 [ 1 ] , & V_72 [ 2 ] , & V_72 [ 3 ] ,
& V_72 [ 4 ] , & V_72 [ 5 ] , & V_72 [ 6 ] , & V_72 [ 7 ] ,
& V_72 [ 8 ] , & V_72 [ 9 ] , & V_72 [ 10 ] , & V_72 [ 11 ] ,
& V_72 [ 12 ] , & V_72 [ 13 ] , & V_72 [ 14 ] , & V_72 [ 15 ] ) ;
if ( V_71 == 0 )
return - 1 ;
if ( V_71 > 16 )
V_71 = 16 ;
for ( V_2 = 0 ; V_2 < V_71 ; V_2 ++ ) {
V_9 [ V_70 + V_2 ] = ( T_6 ) V_72 [ V_2 ] ;
}
return V_71 ;
}
