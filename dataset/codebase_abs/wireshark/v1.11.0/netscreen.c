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
int V_33 ;
char line [ V_10 ] ;
char V_34 [ V_35 ] ;
T_1 V_36 ;
char V_37 [ 13 ] ;
V_32 = F_2 ( V_4 , V_5 , V_6 , line ) ;
if ( V_32 < 0 )
return FALSE ;
V_33 = F_10 ( & V_4 -> V_38 , line , V_34 , & V_36 , V_37 ,
V_5 , V_6 ) ;
if ( V_33 == - 1 )
return FALSE ;
if ( ! F_11 ( V_4 -> V_11 , V_33 , V_34 ,
V_37 , & V_4 -> V_38 , V_4 -> V_39 , V_5 , V_6 ) )
return FALSE ;
if ( V_4 -> V_20 == V_21 )
V_4 -> V_20 = V_4 -> V_38 . V_40 ;
else {
if ( V_4 -> V_20 != V_4 -> V_38 . V_40 )
V_4 -> V_20 = V_41 ;
}
* V_31 = V_32 ;
return TRUE ;
}
static T_1
V_28 ( T_4 * V_4 , T_3 V_42 ,
struct V_43 * V_38 , T_6 * V_9 , int V_44 ,
int * V_5 , T_2 * * V_6 )
{
char line [ V_10 ] ;
char V_34 [ V_35 ] ;
T_1 V_36 ;
char V_37 [ 13 ] ;
if ( F_9 ( V_4 -> V_45 , V_42 , V_19 , V_5 ) == - 1 ) {
return FALSE ;
}
if ( F_5 ( line , V_10 , V_4 -> V_45 ) == NULL ) {
* V_5 = F_4 ( V_4 -> V_45 , V_6 ) ;
if ( * V_5 == 0 ) {
* V_5 = V_18 ;
}
return FALSE ;
}
if ( F_10 ( V_38 , line , V_34 , & V_36 , V_37 ,
V_5 , V_6 ) == - 1 ) {
return FALSE ;
}
if ( ! F_11 ( V_4 -> V_45 , V_44 , V_34 , V_37 ,
V_38 , V_9 , V_5 , V_6 ) )
return FALSE ;
return TRUE ;
}
static int
F_10 ( struct V_43 * V_38 , const char * line , char * V_34 ,
T_1 * V_36 , char * V_37 , int * V_5 , T_2 * * V_6 )
{
int V_46 ;
int V_47 , V_33 ;
char V_48 [ 2 ] ;
char V_49 [ 13 ] ;
V_38 -> V_50 = V_51 | V_52 ;
if ( sscanf ( line , L_1 ,
& V_46 , & V_47 , V_34 , V_48 , & V_33 , V_49 , V_37 ) < 5 ) {
* V_5 = V_53 ;
* V_6 = F_12 ( L_2 ) ;
return - 1 ;
}
* V_36 = ( V_48 [ 0 ] == 'o' ? V_54 : V_55 ) ;
V_38 -> V_56 . V_57 = V_46 ;
V_38 -> V_56 . V_58 = V_47 * 100000000 ;
V_38 -> V_44 = V_33 ;
return V_33 ;
}
static T_1
F_11 ( T_7 V_11 , int V_33 , const char * V_34 ,
const char * V_37 , struct V_43 * V_38 , T_6 * V_9 ,
int * V_5 , T_2 * * V_6 )
{
T_8 * V_59 ;
T_2 line [ V_10 ] ;
T_2 * V_60 ;
int V_61 , V_1 = 0 , V_32 = 0 ;
T_2 V_62 [ 13 ] ;
F_13 ( V_9 , V_63 ) ;
V_59 = F_14 ( V_9 ) ;
while( 1 ) {
if ( F_5 ( line , V_10 , V_11 ) == NULL ) {
break;
}
for ( V_60 = & line [ 0 ] ; isspace ( ( V_3 ) * V_60 ) ; V_60 ++ )
;
if ( * V_60 == '\0' ) {
break;
}
V_61 = F_15 ( V_60 , V_59 , V_32 ) ;
if ( V_32 == 0 && V_61 < 6 ) {
if ( F_1 ( line ) ) {
if ( ++ V_1 <= V_64 ) {
continue;
}
} else {
* V_5 = V_53 ;
* V_6 = F_12 ( L_3 ) ;
return FALSE ;
}
}
if( V_61 == - 1 ) {
* V_5 = V_53 ;
* V_6 = F_12 ( L_3 ) ;
return FALSE ;
}
V_32 += V_61 ;
if( V_32 > V_33 ) {
* V_5 = V_53 ;
* V_6 = F_12 ( L_4 ) ;
return FALSE ;
}
}
if ( strncmp ( V_34 , L_5 , 4 ) == 0 ) {
F_16 ( V_62 , 13 , L_6 ,
V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] , V_59 [ 4 ] , V_59 [ 5 ] ) ;
if ( strncmp ( V_62 , V_37 , 12 ) == 0 )
V_38 -> V_40 = V_65 ;
else
V_38 -> V_40 = V_66 ;
}
else if ( strncmp ( V_34 , L_7 , 4 ) == 0 )
V_38 -> V_40 = V_66 ;
else
V_38 -> V_40 = V_65 ;
V_38 -> V_67 = V_32 ;
return TRUE ;
}
static int
F_15 ( char * V_68 , T_8 * V_9 , T_5 V_69 )
{
int V_70 ;
T_8 V_71 ;
T_8 V_72 ;
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
