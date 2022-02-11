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
V_33 = F_10 ( & V_4 -> V_38 , line , V_34 , & V_36 ,
V_37 , V_5 , V_6 ) ;
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
struct V_43 * V_38 , T_6 * V_9 ,
int * V_5 , T_2 * * V_6 )
{
int V_33 ;
char line [ V_10 ] ;
char V_34 [ V_35 ] ;
T_1 V_36 ;
char V_37 [ 13 ] ;
if ( F_9 ( V_4 -> V_44 , V_42 , V_19 , V_5 ) == - 1 ) {
return FALSE ;
}
if ( F_5 ( line , V_10 , V_4 -> V_44 ) == NULL ) {
* V_5 = F_4 ( V_4 -> V_44 , V_6 ) ;
if ( * V_5 == 0 ) {
* V_5 = V_18 ;
}
return FALSE ;
}
V_33 = F_10 ( V_38 , line , V_34 , & V_36 ,
V_37 , V_5 , V_6 ) ;
if ( V_33 == - 1 )
return FALSE ;
if ( ! F_11 ( V_4 -> V_44 , V_33 , V_34 ,
V_37 , V_38 , V_9 , V_5 , V_6 ) )
return FALSE ;
return TRUE ;
}
static int
F_10 ( struct V_43 * V_38 , const char * line , char * V_34 ,
T_1 * V_36 , char * V_37 , int * V_5 , T_2 * * V_6 )
{
int V_45 ;
int V_46 , V_33 ;
char V_47 [ 2 ] ;
char V_48 [ 13 ] ;
V_38 -> V_49 = V_50 ;
V_38 -> V_51 = V_52 | V_53 ;
if ( sscanf ( line , L_1 ,
& V_45 , & V_46 , V_34 , V_47 , & V_33 , V_48 , V_37 ) < 5 ) {
* V_5 = V_54 ;
* V_6 = F_12 ( L_2 ) ;
return - 1 ;
}
* V_36 = ( V_47 [ 0 ] == 'o' ? V_55 : V_56 ) ;
V_38 -> V_57 . V_58 = V_45 ;
V_38 -> V_57 . V_59 = V_46 * 100000000 ;
V_38 -> V_60 = V_33 ;
return V_33 ;
}
static T_1
F_11 ( T_7 V_11 , int V_33 , const char * V_34 ,
const char * V_37 , struct V_43 * V_38 , T_6 * V_9 ,
int * V_5 , T_2 * * V_6 )
{
T_8 * V_61 ;
T_2 line [ V_10 ] ;
T_2 * V_62 ;
int V_63 , V_1 = 0 , V_32 = 0 ;
T_2 V_64 [ 13 ] ;
F_13 ( V_9 , V_65 ) ;
V_61 = F_14 ( V_9 ) ;
while( 1 ) {
if ( F_5 ( line , V_10 , V_11 ) == NULL ) {
break;
}
for ( V_62 = & line [ 0 ] ; isspace ( ( V_3 ) * V_62 ) ; V_62 ++ )
;
if ( * V_62 == '\0' ) {
break;
}
V_63 = F_15 ( V_62 , V_61 , V_32 ) ;
if ( V_32 == 0 && V_63 < 6 ) {
if ( F_1 ( line ) ) {
if ( ++ V_1 <= V_66 ) {
continue;
}
} else {
* V_5 = V_54 ;
* V_6 = F_12 ( L_3 ) ;
return FALSE ;
}
}
if( V_63 == - 1 ) {
* V_5 = V_54 ;
* V_6 = F_12 ( L_3 ) ;
return FALSE ;
}
V_32 += V_63 ;
if( V_32 > V_33 ) {
* V_5 = V_54 ;
* V_6 = F_12 ( L_4 ) ;
return FALSE ;
}
}
if ( strncmp ( V_34 , L_5 , 4 ) == 0 ) {
F_16 ( V_64 , 13 , L_6 ,
V_61 [ 0 ] , V_61 [ 1 ] , V_61 [ 2 ] , V_61 [ 3 ] , V_61 [ 4 ] , V_61 [ 5 ] ) ;
if ( strncmp ( V_64 , V_37 , 12 ) == 0 )
V_38 -> V_40 = V_67 ;
else
V_38 -> V_40 = V_68 ;
}
else if ( strncmp ( V_34 , L_7 , 4 ) == 0 )
V_38 -> V_40 = V_68 ;
else
V_38 -> V_40 = V_67 ;
V_38 -> V_69 = V_32 ;
return TRUE ;
}
static int
F_15 ( char * V_70 , T_8 * V_9 , T_5 V_71 )
{
int V_72 ;
T_8 V_73 ;
T_8 V_74 ;
for ( V_72 = 0 ; V_72 < 16 ; V_72 ++ ) {
V_73 = * V_70 ++ ;
if ( V_73 >= '0' && V_73 <= '9' )
V_74 = V_73 - '0' + 0 ;
else if ( V_73 >= 'A' && V_73 <= 'F' )
V_74 = V_73 - 'A' + 0xA ;
else if ( V_73 >= 'a' && V_73 <= 'f' )
V_74 = V_73 - 'a' + 0xa ;
else if ( V_73 == ' ' || V_73 == '\r' || V_73 == '\n' || V_73 == '\0' ) {
break;
} else
return - 1 ;
V_74 <<= 4 ;
V_73 = * V_70 ++ & 0xFF ;
if ( V_73 >= '0' && V_73 <= '9' )
V_74 += V_73 - '0' + 0 ;
else if ( V_73 >= 'A' && V_73 <= 'F' )
V_74 += V_73 - 'A' + 0xA ;
else if ( V_73 >= 'a' && V_73 <= 'f' )
V_74 += V_73 - 'a' + 0xa ;
else
return - 1 ;
V_9 [ V_71 + V_72 ] = V_74 ;
V_73 = * V_70 ++ & 0xFF ;
if ( V_73 == '\0' || V_73 == '\r' || V_73 == '\n' ) {
break;
} else if ( V_73 != ' ' ) {
return - 1 ;
}
}
if ( V_72 == 0 )
return - 1 ;
return V_72 ;
}
