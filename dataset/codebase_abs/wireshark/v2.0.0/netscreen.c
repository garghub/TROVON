static T_1 F_1 ( const T_2 * line )
{
int V_1 = V_2 ;
while ( V_1 -- > 0 ) {
if ( F_2 ( * line ) ) {
line ++ ;
continue;
} else {
return FALSE ;
}
}
return TRUE ;
}
static T_3 F_3 ( T_4 * V_3 , int * V_4 , T_2 * * V_5 ,
char * V_6 )
{
T_3 V_7 ;
char V_8 [ V_9 ] ;
while ( 1 ) {
V_7 = F_4 ( V_3 -> V_10 ) ;
if ( V_7 == - 1 ) {
* V_4 = F_5 ( V_3 -> V_10 , V_5 ) ;
return - 1 ;
}
if ( F_6 ( V_8 , sizeof( V_8 ) , V_3 -> V_10 ) == NULL ) {
* V_4 = F_5 ( V_3 -> V_10 , V_5 ) ;
break;
}
if ( strstr ( V_8 , V_11 ) ||
strstr ( V_8 , V_12 ) ) {
F_7 ( V_6 , V_8 , V_9 ) ;
return V_7 ;
}
}
return - 1 ;
}
static T_1 F_8 ( T_4 * V_3 , int * V_4 , T_2 * * V_5 )
{
char V_8 [ V_9 ] ;
T_5 V_13 , line ;
V_8 [ V_9 - 1 ] = '\0' ;
for ( line = 0 ; line < V_14 ; line ++ ) {
if ( F_6 ( V_8 , V_9 , V_3 -> V_10 ) == NULL ) {
* V_4 = F_5 ( V_3 -> V_10 , V_5 ) ;
return FALSE ;
}
V_13 = ( T_5 ) strlen ( V_8 ) ;
if ( V_13 < strlen ( V_15 ) ||
V_13 < strlen ( V_16 ) ) {
continue;
}
if ( strstr ( V_8 , V_15 ) ||
strstr ( V_8 , V_16 ) ) {
return TRUE ;
}
}
* V_4 = 0 ;
return FALSE ;
}
T_6 F_9 ( T_4 * V_3 , int * V_4 , T_2 * * V_5 )
{
if ( ! F_8 ( V_3 , V_4 , V_5 ) ) {
if ( * V_4 != 0 && * V_4 != V_17 )
return V_18 ;
return V_19 ;
}
if ( F_10 ( V_3 -> V_10 , 0L , V_20 , V_4 ) == - 1 )
return V_18 ;
V_3 -> V_21 = V_22 ;
V_3 -> V_23 = V_24 ;
V_3 -> V_25 = 0 ;
V_3 -> V_26 = V_27 ;
V_3 -> V_28 = V_29 ;
V_3 -> V_30 = V_31 ;
return V_32 ;
}
static T_1 V_27 ( T_4 * V_3 , int * V_4 , T_2 * * V_5 ,
T_3 * V_33 )
{
T_3 V_34 ;
int V_35 ;
char line [ V_9 ] ;
char V_36 [ V_37 ] ;
T_1 V_38 ;
char V_39 [ 13 ] ;
V_34 = F_3 ( V_3 , V_4 , V_5 , line ) ;
if ( V_34 < 0 )
return FALSE ;
V_35 = F_11 ( & V_3 -> V_40 , line , V_36 , & V_38 ,
V_39 , V_4 , V_5 ) ;
if ( V_35 == - 1 )
return FALSE ;
if ( ! F_12 ( V_3 -> V_10 , V_35 , V_36 ,
V_39 , & V_3 -> V_40 , V_3 -> V_41 , V_4 , V_5 ) )
return FALSE ;
if ( V_3 -> V_21 == V_22 )
V_3 -> V_21 = V_3 -> V_40 . V_42 ;
else {
if ( V_3 -> V_21 != V_3 -> V_40 . V_42 )
V_3 -> V_21 = V_43 ;
}
* V_33 = V_34 ;
return TRUE ;
}
static T_1
V_29 ( T_4 * V_3 , T_3 V_44 ,
struct V_45 * V_40 , T_7 * V_8 ,
int * V_4 , T_2 * * V_5 )
{
int V_35 ;
char line [ V_9 ] ;
char V_36 [ V_37 ] ;
T_1 V_38 ;
char V_39 [ 13 ] ;
if ( F_10 ( V_3 -> V_46 , V_44 , V_20 , V_4 ) == - 1 ) {
return FALSE ;
}
if ( F_6 ( line , V_9 , V_3 -> V_46 ) == NULL ) {
* V_4 = F_5 ( V_3 -> V_46 , V_5 ) ;
if ( * V_4 == 0 ) {
* V_4 = V_17 ;
}
return FALSE ;
}
V_35 = F_11 ( V_40 , line , V_36 , & V_38 ,
V_39 , V_4 , V_5 ) ;
if ( V_35 == - 1 )
return FALSE ;
if ( ! F_12 ( V_3 -> V_46 , V_35 , V_36 ,
V_39 , V_40 , V_8 , V_4 , V_5 ) )
return FALSE ;
return TRUE ;
}
static int
F_11 ( struct V_45 * V_40 , const char * line , char * V_36 ,
T_1 * V_38 , char * V_39 , int * V_4 , T_2 * * V_5 )
{
int V_47 ;
int V_48 , V_35 ;
char V_49 [ 2 ] ;
char V_50 [ 13 ] ;
V_40 -> V_51 = V_52 ;
V_40 -> V_53 = V_54 | V_55 ;
if ( sscanf ( line , L_1 ,
& V_47 , & V_48 , V_36 , V_49 , & V_35 , V_50 , V_39 ) < 5 ) {
* V_4 = V_56 ;
* V_5 = F_13 ( L_2 ) ;
return - 1 ;
}
* V_38 = ( V_49 [ 0 ] == 'o' ? V_57 : V_58 ) ;
V_40 -> V_59 . V_60 = V_47 ;
V_40 -> V_59 . V_61 = V_48 * 100000000 ;
V_40 -> V_62 = V_35 ;
return V_35 ;
}
static T_1
F_12 ( T_8 V_10 , int V_35 , const char * V_36 ,
const char * V_39 , struct V_45 * V_40 , T_7 * V_8 ,
int * V_4 , T_2 * * V_5 )
{
T_9 * V_63 ;
T_2 line [ V_9 ] ;
T_2 * V_64 ;
int V_65 , V_1 = 0 , V_34 = 0 ;
T_2 V_66 [ 13 ] ;
F_14 ( V_8 , V_67 ) ;
V_63 = F_15 ( V_8 ) ;
while( 1 ) {
if ( F_6 ( line , V_9 , V_10 ) == NULL ) {
break;
}
for ( V_64 = & line [ 0 ] ; F_2 ( * V_64 ) ; V_64 ++ )
;
if ( * V_64 == '\0' ) {
break;
}
V_65 = F_16 ( V_64 , V_63 , V_34 ) ;
if ( V_34 == 0 && V_65 < 6 ) {
if ( F_1 ( line ) ) {
if ( ++ V_1 <= V_68 ) {
continue;
}
} else {
* V_4 = V_56 ;
* V_5 = F_13 ( L_3 ) ;
return FALSE ;
}
}
if( V_65 == - 1 ) {
* V_4 = V_56 ;
* V_5 = F_13 ( L_3 ) ;
return FALSE ;
}
V_34 += V_65 ;
if( V_34 > V_35 ) {
* V_4 = V_56 ;
* V_5 = F_13 ( L_4 ) ;
return FALSE ;
}
}
if ( strncmp ( V_36 , L_5 , 4 ) == 0 ) {
F_17 ( V_66 , 13 , L_6 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] , V_63 [ 4 ] , V_63 [ 5 ] ) ;
if ( strncmp ( V_66 , V_39 , 12 ) == 0 )
V_40 -> V_42 = V_69 ;
else
V_40 -> V_42 = V_70 ;
}
else if ( strncmp ( V_36 , L_7 , 4 ) == 0 )
V_40 -> V_42 = V_70 ;
else
V_40 -> V_42 = V_69 ;
V_40 -> V_71 = V_34 ;
return TRUE ;
}
static int
F_16 ( char * V_72 , T_9 * V_8 , T_5 V_73 )
{
int V_74 ;
T_9 V_75 ;
T_9 V_76 ;
for ( V_74 = 0 ; V_74 < 16 ; V_74 ++ ) {
V_75 = * V_72 ++ ;
if ( V_75 >= '0' && V_75 <= '9' )
V_76 = V_75 - '0' + 0 ;
else if ( V_75 >= 'A' && V_75 <= 'F' )
V_76 = V_75 - 'A' + 0xA ;
else if ( V_75 >= 'a' && V_75 <= 'f' )
V_76 = V_75 - 'a' + 0xa ;
else if ( V_75 == ' ' || V_75 == '\r' || V_75 == '\n' || V_75 == '\0' ) {
break;
} else
return - 1 ;
V_76 <<= 4 ;
V_75 = * V_72 ++ & 0xFF ;
if ( V_75 >= '0' && V_75 <= '9' )
V_76 += V_75 - '0' + 0 ;
else if ( V_75 >= 'A' && V_75 <= 'F' )
V_76 += V_75 - 'A' + 0xA ;
else if ( V_75 >= 'a' && V_75 <= 'f' )
V_76 += V_75 - 'a' + 0xa ;
else
return - 1 ;
V_8 [ V_73 + V_74 ] = V_76 ;
V_75 = * V_72 ++ & 0xFF ;
if ( V_75 == '\0' || V_75 == '\r' || V_75 == '\n' ) {
break;
} else if ( V_75 != ' ' ) {
return - 1 ;
}
}
if ( V_74 == 0 )
return - 1 ;
return V_74 ;
}
