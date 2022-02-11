static long F_1 ( T_1 * V_1 , int * V_2 )
{
long V_3 ;
char V_4 [ V_5 ] ;
while ( 1 ) {
V_3 = F_2 ( V_1 -> V_6 ) ;
if ( V_3 == - 1 ) {
* V_2 = F_3 ( V_1 -> V_6 , V_7 ) ;
V_8 = NULL ;
return - 1 ;
}
if ( F_4 ( V_4 , sizeof( V_4 ) , V_1 -> V_6 ) != NULL ) {
if ( strstr ( V_4 , V_9 ) ||
strstr ( V_4 , V_10 ) ||
strstr ( V_4 , V_10 ) ) {
F_5 ( V_8 , V_4 , V_5 ) ;
return V_3 ;
}
} else {
if ( F_6 ( V_1 -> V_6 ) ) {
* V_2 = 0 ;
} else {
* V_2 = F_3 ( V_1 -> V_6 , V_7 ) ;
}
break;
}
}
V_8 = NULL ;
return - 1 ;
}
static T_2 F_7 ( T_1 * V_1 , int * V_2 , T_3 * * V_7 )
{
char V_4 [ V_5 ] ;
T_4 V_11 , line ;
T_5 V_12 ;
V_4 [ V_5 - 1 ] = '\0' ;
for ( line = 0 ; line < V_13 ; line ++ ) {
V_12 = F_2 ( V_1 -> V_6 ) ;
if ( V_12 == - 1 ) {
* V_2 = F_3 ( V_1 -> V_6 , V_7 ) ;
return FALSE ;
}
if ( F_4 ( V_4 , V_5 , V_1 -> V_6 ) != NULL ) {
V_11 = ( T_4 ) strlen ( V_4 ) ;
if ( V_11 < strlen ( V_14 ) ||
V_11 < strlen ( V_15 ) ||
V_11 < strlen ( V_16 ) ) {
continue;
}
if ( strstr ( V_4 , V_14 ) ||
strstr ( V_4 , V_15 ) ||
strstr ( V_4 , V_16 ) ) {
if ( F_8 ( V_1 -> V_6 , V_12 , V_17 , V_2 ) == - 1 ) {
return FALSE ;
}
return TRUE ;
}
} else {
if ( F_6 ( V_1 -> V_6 ) )
* V_2 = 0 ;
else
* V_2 = F_3 ( V_1 -> V_6 , V_7 ) ;
return FALSE ;
}
}
* V_2 = 0 ;
return FALSE ;
}
int F_9 ( T_1 * V_1 , int * V_2 , T_3 * * V_7 )
{
if ( ! F_7 ( V_1 , V_2 , V_7 ) ) {
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_2 V_24 ( T_1 * V_1 , int * V_2 , T_3 * * V_7 ,
T_5 * V_29 )
{
T_5 V_30 = 0 ;
T_6 * V_4 ;
int V_31 ;
#ifdef F_10
V_30 = F_1 ( V_1 , V_2 ) ;
#else
V_30 = F_2 ( V_1 -> V_6 ) ;
#endif
if ( V_30 < 1 ) {
* V_2 = F_3 ( V_1 -> V_6 , V_7 ) ;
return FALSE ;
}
V_31 = F_11 ( V_1 , V_1 -> V_6 , V_2 , V_7 ) ;
if ( V_31 == - 1 )
return FALSE ;
F_12 ( V_1 -> V_32 , V_31 ) ;
V_4 = F_13 ( V_1 -> V_32 ) ;
if ( ! F_14 ( V_1 -> V_6 , V_31 , V_4 , V_2 , V_7 ) )
return FALSE ;
* V_29 = V_30 ;
return TRUE ;
}
static T_2
V_26 ( T_1 * V_1 , T_5 V_33 ,
union V_34 * T_7 V_35 ,
T_6 * V_36 , int V_37 , int * V_2 , T_3 * * V_7 )
{
int V_31 ;
if ( F_8 ( V_1 -> V_38 , V_33 - 1 , V_17 , V_2 ) == - 1 )
return FALSE ;
V_31 = F_11 ( NULL , V_1 -> V_38 , V_2 , V_7 ) ;
if ( V_31 != V_37 ) {
if ( V_31 != - 1 ) {
* V_2 = V_39 ;
* V_7 = F_15 ( L_1 ,
V_37 , V_31 ) ;
}
return FALSE ;
}
return F_14 ( V_1 -> V_38 , V_31 , V_36 , V_2 , V_7 ) ;
}
static int
F_16 ( T_3 * line )
{
int V_40 , V_41 ;
while ( * line && ! isalnum ( ( V_42 ) * line ) )
line ++ ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ , line ++ )
if ( ! isxdigit ( ( V_42 ) * line ) )
return FALSE ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ , line ++ )
if ( * line != ' ' )
return FALSE ;
}
return isspace ( ( V_42 ) * line ) ;
}
static int
F_11 ( T_1 * V_1 , T_8 V_6 , int * V_2 , T_3 * * V_7 )
{
char line [ V_5 + 1 ] ;
int V_43 ;
int V_31 = 0 ;
int V_44 ;
int V_45 = 101 ;
struct V_46 V_46 ;
char V_47 [ 4 ] = { 'J' , 'A' , 'N' , 0 } ;
T_3 * V_48 ;
static const T_3 V_49 [] = L_2 ;
V_46 . V_50 = 1970 ;
V_46 . V_51 = 0 ;
V_46 . V_52 = 1 ;
V_46 . V_53 = 1 ;
V_46 . V_54 = 1 ;
V_46 . V_55 = 1 ;
do {
if ( F_4 ( line , V_5 , V_6 ) == NULL ) {
* V_2 = F_3 ( V_6 , V_7 ) ;
if ( ( * V_2 == 0 ) && ( V_45 != 101 ) ) {
* V_2 = V_56 ;
}
return - 1 ;
}
line [ V_5 ] = '\0' ;
if ( ( V_45 == 101 ) && ( V_48 = strstr ( line , L_3 ) ) != NULL
&& ( ! strstr ( line , L_4 ) ) ) {
V_43 = sscanf ( V_48 ,
L_5 ,
& V_44 , & V_46 . V_52 , V_47 ,
& V_46 . V_50 , & V_46 . V_53 ,
& V_46 . V_54 , & V_46 . V_55 , & V_45 ) ;
if ( V_43 != 8 ) {
V_43 = sscanf ( V_48 ,
L_6 ,
& V_44 , & V_46 . V_52 , V_47 ,
& V_46 . V_50 , & V_46 . V_53 ,
& V_46 . V_54 , & V_46 . V_55 , & V_45 ) ;
}
if ( V_43 != 8 ) {
* V_2 = V_39 ;
* V_7 = F_15 ( L_7 ) ;
return - 1 ;
}
}
if ( ( ! V_31 ) && ( V_48 = strstr ( line , L_8 ) ) ) {
V_48 += sizeof( L_9 ) ;
while ( * V_48 && ! isdigit ( ( V_42 ) * V_48 ) )
V_48 ++ ;
if ( ! * V_48 ) {
* V_2 = V_39 ;
* V_7 = F_15 ( L_10 ) ;
return - 1 ;
}
V_31 = atoi ( V_48 ) ;
break;
}
} while ( ! F_16 ( line ) );
if ( V_1 ) {
V_48 = strstr ( V_49 , V_47 ) ;
if ( V_48 )
V_46 . V_51 = ( int ) ( V_48 - V_49 ) / 3 ;
V_46 . V_50 -= 1900 ;
V_46 . V_57 = - 1 ;
V_1 -> V_58 . V_59 = V_60 ;
V_1 -> V_58 . V_61 . V_62 = mktime ( & V_46 ) ;
V_1 -> V_58 . V_61 . V_63 = V_45 * 10000000 ;
V_1 -> V_58 . V_64 = V_31 ;
V_1 -> V_58 . V_37 = V_31 ;
}
return V_31 ;
}
static T_2
F_14 ( T_8 V_6 , int V_31 , T_6 * V_4 , int * V_2 ,
T_3 * * V_7 )
{
T_3 line [ V_5 + 1 ] ;
int V_40 ;
int V_30 = 0 ;
for ( V_40 = 0 ; V_40 < V_31 ; V_40 += 16 ) {
if ( F_4 ( line , V_5 , V_6 ) == NULL ) {
* V_2 = F_3 ( V_6 , V_7 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_56 ;
}
return FALSE ;
}
line [ V_5 ] = '\0' ;
if ( V_40 == 0 ) {
while ( ! F_16 ( line ) ) {
if ( F_4 ( line , V_5 , V_6 ) == NULL ) {
* V_2 = F_3 ( V_6 , V_7 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_56 ;
}
return FALSE ;
}
line [ V_5 ] = '\0' ;
}
while ( line [ V_30 ] && ! isxdigit ( ( V_42 ) line [ V_30 ] ) )
V_30 ++ ;
}
if ( ! F_17 ( line , V_4 , V_40 ,
V_30 , V_31 - V_40 ) ) {
* V_2 = V_39 ;
* V_7 = F_15 ( L_11 ) ;
return FALSE ;
}
}
if ( ! F_4 ( line , V_5 , V_6 ) ) {
* V_2 = F_3 ( V_6 , V_7 ) ;
if ( * V_2 == 0 ) {
return TRUE ;
}
return FALSE ;
}
return TRUE ;
}
static T_2
F_17 ( char * V_65 , T_6 * V_4 , long V_66 ,
int V_67 , int V_68 ) {
int V_40 ;
char * V_69 ;
int V_70 ;
static const int V_71 [ 16 ] = { 39 , 37 , 35 , 33 , 28 , 26 , 24 , 22 , 17 , 15 , 13 , 11 , 6 , 4 , 2 , 0 } ;
char V_72 [ 3 ] = { 0 , 0 , 0 } ;
V_69 = V_65 ;
V_70 = ( int ) strtoul ( V_69 + 45 + V_67 , NULL , 16 ) ;
if ( V_70 != V_66 ) {
return FALSE ;
}
if ( V_68 > 16 )
V_68 = 16 ;
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ ) {
V_72 [ 0 ] = V_65 [ V_71 [ V_40 ] + V_67 ] ;
V_72 [ 1 ] = V_65 [ V_71 [ V_40 ] + 1 + V_67 ] ;
V_4 [ V_66 + V_40 ] = ( T_6 ) strtoul ( V_72 , NULL , 16 ) ;
}
return TRUE ;
}
