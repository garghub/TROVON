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
char line [ V_9 ] ;
V_34 = F_3 ( V_3 , V_4 , V_5 , line ) ;
if ( V_34 < 0 )
return FALSE ;
if ( ! F_11 ( V_3 -> V_10 , & V_3 -> V_35 ,
V_3 -> V_36 , line , V_4 , V_5 ) )
return FALSE ;
if ( V_3 -> V_21 == V_22 )
V_3 -> V_21 = V_3 -> V_35 . V_37 ;
else {
if ( V_3 -> V_21 != V_3 -> V_35 . V_37 )
V_3 -> V_21 = V_38 ;
}
* V_33 = V_34 ;
return TRUE ;
}
static T_1
V_29 ( T_4 * V_3 , T_3 V_39 ,
struct V_40 * V_35 , T_7 * V_8 ,
int * V_4 , T_2 * * V_5 )
{
char line [ V_9 ] ;
if ( F_10 ( V_3 -> V_41 , V_39 , V_20 , V_4 ) == - 1 ) {
return FALSE ;
}
if ( F_6 ( line , V_9 , V_3 -> V_41 ) == NULL ) {
* V_4 = F_5 ( V_3 -> V_41 , V_5 ) ;
if ( * V_4 == 0 ) {
* V_4 = V_17 ;
}
return FALSE ;
}
return F_11 ( V_3 -> V_41 , V_35 , V_8 , line ,
V_4 , V_5 ) ;
}
static T_1
F_11 ( T_8 V_10 , struct V_40 * V_35 , T_7 * V_8 ,
char * line , int * V_4 , T_2 * * V_5 )
{
int V_42 ;
int V_43 ;
int V_44 ;
char V_45 [ V_46 ] ;
char V_47 [ 2 ] ;
char V_48 [ 13 ] ;
char V_49 [ 13 ] ;
T_9 * V_50 ;
T_2 * V_51 ;
int V_52 , V_1 = 0 ;
int V_34 = 0 ;
T_2 V_53 [ 13 ] ;
V_35 -> V_54 = V_55 ;
V_35 -> V_56 = V_57 | V_58 ;
if ( sscanf ( line , L_1 ,
& V_43 , & V_44 , V_45 , V_47 , & V_42 , V_48 , V_49 ) < 5 ) {
* V_4 = V_59 ;
* V_5 = F_12 ( L_2 ) ;
return - 1 ;
}
if ( V_42 < 0 ) {
* V_4 = V_59 ;
* V_5 = F_12 ( L_3 ) ;
return FALSE ;
}
if ( V_42 > V_60 ) {
* V_4 = V_59 ;
* V_5 = F_13 ( L_4 ,
V_42 , V_60 ) ;
return FALSE ;
}
V_35 -> V_61 . V_62 = V_43 ;
V_35 -> V_61 . V_63 = V_44 * 100000000 ;
V_35 -> V_64 = V_42 ;
F_14 ( V_8 , V_42 ) ;
V_50 = F_15 ( V_8 ) ;
while( 1 ) {
if ( F_6 ( line , V_9 , V_10 ) == NULL ) {
break;
}
for ( V_51 = & line [ 0 ] ; F_2 ( * V_51 ) ; V_51 ++ )
;
if ( * V_51 == '\0' ) {
break;
}
V_52 = F_16 ( V_51 , V_50 , V_34 ) ;
if ( V_34 == 0 && V_52 < 6 ) {
if ( F_1 ( line ) ) {
if ( ++ V_1 <= V_65 ) {
continue;
}
} else {
* V_4 = V_59 ;
* V_5 = F_12 ( L_5 ) ;
return FALSE ;
}
}
if ( V_52 == - 1 ) {
* V_4 = V_59 ;
* V_5 = F_12 ( L_5 ) ;
return FALSE ;
}
V_34 += V_52 ;
if ( V_34 > V_42 ) {
* V_4 = V_59 ;
* V_5 = F_12 ( L_6 ) ;
return FALSE ;
}
}
if ( strncmp ( V_45 , L_7 , 4 ) == 0 ) {
F_17 ( V_53 , 13 , L_8 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] , V_50 [ 4 ] , V_50 [ 5 ] ) ;
if ( strncmp ( V_53 , V_49 , 12 ) == 0 )
V_35 -> V_37 = V_66 ;
else
V_35 -> V_37 = V_67 ;
}
else if ( strncmp ( V_45 , L_9 , 4 ) == 0 )
V_35 -> V_37 = V_67 ;
else
V_35 -> V_37 = V_66 ;
V_35 -> V_68 = V_34 ;
return TRUE ;
}
static int
F_16 ( char * V_69 , T_9 * V_8 , T_5 V_70 )
{
int V_71 ;
T_9 V_72 ;
T_9 V_73 ;
for ( V_71 = 0 ; V_71 < 16 ; V_71 ++ ) {
V_72 = * V_69 ++ ;
if ( V_72 >= '0' && V_72 <= '9' )
V_73 = V_72 - '0' + 0 ;
else if ( V_72 >= 'A' && V_72 <= 'F' )
V_73 = V_72 - 'A' + 0xA ;
else if ( V_72 >= 'a' && V_72 <= 'f' )
V_73 = V_72 - 'a' + 0xa ;
else if ( V_72 == ' ' || V_72 == '\r' || V_72 == '\n' || V_72 == '\0' ) {
break;
} else
return - 1 ;
V_73 <<= 4 ;
V_72 = * V_69 ++ & 0xFF ;
if ( V_72 >= '0' && V_72 <= '9' )
V_73 += V_72 - '0' + 0 ;
else if ( V_72 >= 'A' && V_72 <= 'F' )
V_73 += V_72 - 'A' + 0xA ;
else if ( V_72 >= 'a' && V_72 <= 'f' )
V_73 += V_72 - 'a' + 0xa ;
else
return - 1 ;
V_8 [ V_70 + V_71 ] = V_73 ;
V_72 = * V_69 ++ & 0xFF ;
if ( V_72 == '\0' || V_72 == '\r' || V_72 == '\n' ) {
break;
} else if ( V_72 != ' ' ) {
return - 1 ;
}
}
if ( V_71 == 0 )
return - 1 ;
return V_71 ;
}
