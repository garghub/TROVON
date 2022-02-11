static T_1 F_1 ( const T_2 * line )
{
int V_1 = V_2 ;
while ( V_1 -- > 0 ) {
if ( isspace ( ( V_3 ) * line ) ) {
line ++ ;
continue;
} else {
return FALSE ;
}
}
return TRUE ;
}
static T_3 F_2 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 ,
char * V_7 )
{
T_3 V_8 ;
char V_9 [ V_10 ] ;
while ( 1 ) {
V_8 = F_3 ( V_4 -> V_11 ) ;
if ( V_8 == - 1 ) {
* V_5 = F_4 ( V_4 -> V_11 , V_6 ) ;
return - 1 ;
}
if ( F_5 ( V_9 , sizeof( V_9 ) , V_4 -> V_11 ) == NULL ) {
* V_5 = F_4 ( V_4 -> V_11 , V_6 ) ;
break;
}
if ( strstr ( V_9 , V_12 ) ||
strstr ( V_9 , V_13 ) ) {
F_6 ( V_7 , V_9 , V_10 ) ;
return V_8 ;
}
}
return - 1 ;
}
static T_1 F_7 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 )
{
char V_9 [ V_10 ] ;
T_5 V_14 , line ;
V_9 [ V_10 - 1 ] = '\0' ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_5 ( V_9 , V_10 , V_4 -> V_11 ) == NULL ) {
* V_5 = F_4 ( V_4 -> V_11 , V_6 ) ;
return FALSE ;
}
V_14 = ( T_5 ) strlen ( V_9 ) ;
if ( V_14 < strlen ( V_16 ) ||
V_14 < strlen ( V_17 ) ) {
continue;
}
if ( strstr ( V_9 , V_16 ) ||
strstr ( V_9 , V_17 ) ) {
return TRUE ;
}
}
* V_5 = 0 ;
return FALSE ;
}
int F_8 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 )
{
if ( ! F_7 ( V_4 , V_5 , V_6 ) ) {
if ( * V_5 != 0 && * V_5 != V_18 )
return - 1 ;
return 0 ;
}
if ( F_9 ( V_4 -> V_11 , 0L , V_19 , V_5 ) == - 1 )
return - 1 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = V_28 ;
V_4 -> V_29 = V_30 ;
return 1 ;
}
static T_1 V_26 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 ,
T_3 * V_31 )
{
T_3 V_32 ;
T_6 * V_9 ;
int V_33 , V_34 ;
char line [ V_10 ] ;
char V_35 [ V_36 ] ;
T_1 V_37 ;
char V_38 [ 13 ] ;
T_2 V_39 [ 13 ] ;
V_32 = F_2 ( V_4 , V_5 , V_6 , line ) ;
if ( V_32 < 0 )
return FALSE ;
V_33 = F_10 ( & V_4 -> V_40 , line , V_35 , & V_37 , V_38 ,
V_5 , V_6 ) ;
if ( V_33 == - 1 )
return FALSE ;
F_11 ( V_4 -> V_41 , V_42 ) ;
V_9 = F_12 ( V_4 -> V_41 ) ;
if ( ( V_34 = F_13 ( V_4 -> V_11 , V_33 , V_9 , V_5 ,
V_6 ) ) == - 1 ) {
return FALSE ;
}
if ( strncmp ( V_35 , L_1 , 4 ) == 0 ) {
F_14 ( V_39 , 13 , L_2 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
if ( strncmp ( V_39 , V_38 , 12 ) == 0 )
V_4 -> V_40 . V_43 = V_44 ;
else
V_4 -> V_40 . V_43 = V_45 ;
}
else if ( strncmp ( V_35 , L_3 , 4 ) == 0 )
V_4 -> V_40 . V_43 = V_45 ;
else
V_4 -> V_40 . V_43 = V_44 ;
if ( V_4 -> V_20 == V_21 )
V_4 -> V_20 = V_4 -> V_40 . V_43 ;
else {
if ( V_4 -> V_20 != V_4 -> V_40 . V_43 )
V_4 -> V_20 = V_46 ;
}
V_4 -> V_40 . V_34 = V_34 ;
* V_31 = V_32 ;
return TRUE ;
}
static T_1
V_28 ( T_4 * V_4 , T_3 V_47 ,
struct V_48 * V_40 , T_6 * V_49 , int V_50 ,
int * V_5 , T_2 * * V_6 )
{
char line [ V_10 ] ;
char V_35 [ V_36 ] ;
T_1 V_37 ;
char V_38 [ 13 ] ;
int V_34 ;
if ( F_9 ( V_4 -> V_51 , V_47 , V_19 , V_5 ) == - 1 ) {
return FALSE ;
}
if ( F_5 ( line , V_10 , V_4 -> V_51 ) == NULL ) {
* V_5 = F_4 ( V_4 -> V_51 , V_6 ) ;
if ( * V_5 == 0 ) {
* V_5 = V_18 ;
}
return FALSE ;
}
if ( F_10 ( V_40 , line , V_35 , & V_37 , V_38 ,
V_5 , V_6 ) == - 1 ) {
return FALSE ;
}
V_34 = F_13 ( V_4 -> V_51 , V_50 , V_49 , V_5 , V_6 ) ;
if ( V_34 == - 1 )
return FALSE ;
V_40 -> V_34 = V_34 ;
return TRUE ;
}
static int
F_10 ( struct V_48 * V_40 , const char * line , char * V_35 ,
T_1 * V_37 , char * V_38 , int * V_5 , T_2 * * V_6 )
{
int V_52 ;
int V_53 , V_33 ;
char V_54 [ 2 ] ;
char V_55 [ 13 ] ;
V_40 -> V_56 = V_57 | V_58 ;
if ( sscanf ( line , L_4 ,
& V_52 , & V_53 , V_35 , V_54 , & V_33 , V_55 , V_38 ) < 5 ) {
* V_5 = V_59 ;
* V_6 = F_15 ( L_5 ) ;
return - 1 ;
}
* V_37 = ( V_54 [ 0 ] == 'o' ? V_60 : V_61 ) ;
V_40 -> V_62 . V_63 = V_52 ;
V_40 -> V_62 . V_64 = V_53 * 100000000 ;
V_40 -> V_50 = V_33 ;
return V_33 ;
}
static int
F_13 ( T_7 V_11 , int V_33 , T_6 * V_9 , int * V_5 , T_2 * * V_6 )
{
T_2 line [ V_10 ] ;
T_2 * V_65 ;
int V_66 , V_1 = 0 , V_32 = 0 ;
while( 1 ) {
if ( F_5 ( line , V_10 , V_11 ) == NULL ) {
break;
}
for ( V_65 = & line [ 0 ] ; isspace ( ( V_3 ) * V_65 ) ; V_65 ++ )
;
if ( * V_65 == '\0' ) {
break;
}
V_66 = F_16 ( V_65 , V_9 , V_32 ) ;
if ( V_32 == 0 && V_66 < 6 ) {
if ( F_1 ( line ) ) {
if ( ++ V_1 <= V_67 ) {
continue;
}
} else {
* V_5 = V_59 ;
* V_6 = F_15 ( L_6 ) ;
return - 1 ;
}
}
if( V_66 == - 1 ) {
* V_5 = V_59 ;
* V_6 = F_15 ( L_6 ) ;
return - 1 ;
}
V_32 += V_66 ;
if( V_32 > V_33 ) {
* V_5 = V_59 ;
* V_6 = F_15 ( L_7 ) ;
return - 1 ;
}
}
return V_32 ;
}
static int
F_16 ( char * V_68 , T_6 * V_9 , T_5 V_69 )
{
int V_70 ;
T_6 V_71 ;
T_6 V_72 ;
for ( V_70 = 0 ; V_70 < 16 ; V_70 ++ ) {
V_71 = * V_68 ++ ;
if ( V_71 >= '0' && V_71 <= '9' )
V_72 = V_71 - '0' + 0 ;
else if ( V_71 >= 'A' && V_71 <= 'F' )
V_72 = V_71 - 'A' + 0xA ;
else if ( V_71 >= 'a' && V_71 <= 'f' )
V_72 = V_71 - 'a' + 0xa ;
else if ( V_71 == ' ' || V_71 == '\r' || V_71 == '\n' || V_71 == '\0' ) {
break;
} else
return - 1 ;
V_72 <<= 4 ;
V_71 = * V_68 ++ & 0xFF ;
if ( V_71 >= '0' && V_71 <= '9' )
V_72 += V_71 - '0' + 0 ;
else if ( V_71 >= 'A' && V_71 <= 'F' )
V_72 += V_71 - 'A' + 0xA ;
else if ( V_71 >= 'a' && V_71 <= 'f' )
V_72 += V_71 - 'a' + 0xa ;
else
return - 1 ;
V_9 [ V_69 + V_70 ] = V_72 ;
V_71 = * V_68 ++ & 0xFF ;
if ( V_71 == '\0' || V_71 == '\r' || V_71 == '\n' ) {
break;
} else if ( V_71 != ' ' ) {
return - 1 ;
}
}
if ( V_70 == 0 )
return - 1 ;
return V_70 ;
}
