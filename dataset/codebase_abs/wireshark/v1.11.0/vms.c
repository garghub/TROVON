static long F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
long V_4 ;
char V_5 [ V_6 ] ;
while ( 1 ) {
V_4 = F_2 ( V_1 -> V_7 ) ;
if ( V_4 == - 1 ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
if ( F_4 ( V_5 , sizeof( V_5 ) , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
break;
}
if ( strstr ( V_5 , V_8 ) ||
strstr ( V_5 , V_9 ) ||
strstr ( V_5 , V_9 ) ) {
F_5 ( V_10 , V_5 , V_6 ) ;
return V_4 ;
}
}
return - 1 ;
}
static T_3 F_6 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_5 [ V_6 ] ;
T_4 V_11 , line ;
T_5 V_12 ;
V_5 [ V_6 - 1 ] = '\0' ;
for ( line = 0 ; line < V_13 ; line ++ ) {
V_12 = F_2 ( V_1 -> V_7 ) ;
if ( V_12 == - 1 ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
if ( F_4 ( V_5 , V_6 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
V_11 = ( T_4 ) strlen ( V_5 ) ;
if ( V_11 < strlen ( V_14 ) ||
V_11 < strlen ( V_15 ) ||
V_11 < strlen ( V_16 ) ) {
continue;
}
if ( strstr ( V_5 , V_14 ) ||
strstr ( V_5 , V_15 ) ||
strstr ( V_5 , V_16 ) ) {
if ( F_7 ( V_1 -> V_7 , V_12 , V_17 , V_2 ) == - 1 ) {
return FALSE ;
}
return TRUE ;
}
}
* V_2 = 0 ;
return FALSE ;
}
int F_8 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
if ( ! F_6 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return - 1 ;
return 0 ;
}
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
return 1 ;
}
static T_3 V_25 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_30 )
{
T_5 V_31 = 0 ;
#ifdef F_9
V_31 = F_1 ( V_1 , V_2 , V_3 ) ;
#else
V_31 = F_2 ( V_1 -> V_7 ) ;
#endif
if ( V_31 < 1 ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
* V_30 = V_31 ;
return F_10 ( V_1 -> V_7 , & V_1 -> V_32 , V_1 -> V_33 , V_2 , V_3 ) ;
}
static T_3
V_27 ( T_1 * V_1 , T_5 V_34 , struct V_35 * V_32 ,
T_6 * V_5 , int T_7 V_36 , int * V_2 , T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_37 , V_34 - 1 , V_17 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 -> V_37 , V_32 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static int
F_11 ( T_2 * line )
{
int V_38 , V_39 ;
while ( * line && ! isalnum ( ( V_40 ) * line ) )
line ++ ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ , line ++ )
if ( ! isxdigit ( ( V_40 ) * line ) )
return FALSE ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ , line ++ )
if ( * line != ' ' )
return FALSE ;
}
return isspace ( ( V_40 ) * line ) ;
}
static T_3
F_10 ( T_8 V_7 , struct V_35 * V_32 , T_6 * V_5 , int * V_2 , T_2 * * V_3 )
{
char line [ V_6 + 1 ] ;
int V_41 ;
int V_42 = 0 ;
int V_43 ;
int V_44 = 101 ;
struct V_45 V_45 ;
char V_46 [ 4 ] = { 'J' , 'A' , 'N' , 0 } ;
T_2 * V_47 ;
static const T_2 V_48 [] = L_1 ;
int V_38 ;
int V_31 = 0 ;
T_9 * V_49 ;
V_45 . V_50 = 1970 ;
V_45 . V_51 = 0 ;
V_45 . V_52 = 1 ;
V_45 . V_53 = 1 ;
V_45 . V_54 = 1 ;
V_45 . V_55 = 1 ;
do {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( ( * V_2 == 0 ) && ( V_44 != 101 ) ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( ( V_44 == 101 ) && ( V_47 = strstr ( line , L_2 ) ) != NULL
&& ( ! strstr ( line , L_3 ) ) ) {
V_41 = sscanf ( V_47 ,
L_4 ,
& V_43 , & V_45 . V_52 , V_46 ,
& V_45 . V_50 , & V_45 . V_53 ,
& V_45 . V_54 , & V_45 . V_55 , & V_44 ) ;
if ( V_41 != 8 ) {
V_41 = sscanf ( V_47 ,
L_5 ,
& V_43 , & V_45 . V_52 , V_46 ,
& V_45 . V_50 , & V_45 . V_53 ,
& V_45 . V_54 , & V_45 . V_55 , & V_44 ) ;
}
if ( V_41 != 8 ) {
* V_2 = V_56 ;
* V_3 = F_12 ( L_6 ) ;
return FALSE ;
}
}
if ( ( ! V_42 ) && ( V_47 = strstr ( line , L_7 ) ) ) {
V_47 += sizeof( L_8 ) ;
while ( * V_47 && ! isdigit ( ( V_40 ) * V_47 ) )
V_47 ++ ;
if ( ! * V_47 ) {
* V_2 = V_56 ;
* V_3 = F_12 ( L_9 ) ;
return FALSE ;
}
V_42 = atoi ( V_47 ) ;
break;
}
} while ( ! F_11 ( line ) );
V_47 = strstr ( V_48 , V_46 ) ;
if ( V_47 )
V_45 . V_51 = ( int ) ( V_47 - V_48 ) / 3 ;
V_45 . V_50 -= 1900 ;
V_45 . V_57 = - 1 ;
V_32 -> V_58 = V_59 ;
V_32 -> V_60 . V_61 = mktime ( & V_45 ) ;
V_32 -> V_60 . V_62 = V_44 * 10000000 ;
V_32 -> V_63 = V_42 ;
V_32 -> T_7 = V_42 ;
F_13 ( V_5 , V_42 ) ;
V_49 = F_14 ( V_5 ) ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 += 16 ) {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( V_38 == 0 ) {
while ( ! F_11 ( line ) ) {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
}
while ( line [ V_31 ] && ! isxdigit ( ( V_40 ) line [ V_31 ] ) )
V_31 ++ ;
}
if ( ! F_15 ( line , V_49 , V_38 ,
V_31 , V_42 - V_38 ) ) {
* V_2 = V_56 ;
* V_3 = F_12 ( L_10 ) ;
return FALSE ;
}
}
if ( ! F_4 ( line , V_6 , V_7 ) ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
return TRUE ;
}
return FALSE ;
}
return TRUE ;
}
static T_3
F_15 ( char * V_64 , T_9 * V_5 , long V_65 ,
int V_66 , int V_67 ) {
int V_38 ;
char * V_68 ;
int V_69 ;
static const int V_70 [ 16 ] = { 39 , 37 , 35 , 33 , 28 , 26 , 24 , 22 , 17 , 15 , 13 , 11 , 6 , 4 , 2 , 0 } ;
char V_71 [ 3 ] = { 0 , 0 , 0 } ;
V_68 = V_64 ;
V_69 = ( int ) strtoul ( V_68 + 45 + V_66 , NULL , 16 ) ;
if ( V_69 != V_65 ) {
return FALSE ;
}
if ( V_67 > 16 )
V_67 = 16 ;
for ( V_38 = 0 ; V_38 < V_67 ; V_38 ++ ) {
V_71 [ 0 ] = V_64 [ V_70 [ V_38 ] + V_66 ] ;
V_71 [ 1 ] = V_64 [ V_70 [ V_38 ] + 1 + V_66 ] ;
V_5 [ V_65 + V_38 ] = ( T_9 ) strtoul ( V_71 , NULL , 16 ) ;
}
return TRUE ;
}
