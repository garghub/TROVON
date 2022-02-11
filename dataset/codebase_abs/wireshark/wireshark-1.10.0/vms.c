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
T_6 * V_5 ;
#ifdef F_9
V_31 = F_1 ( V_1 , V_2 , V_3 ) ;
#else
V_31 = F_2 ( V_1 -> V_7 ) ;
#endif
if ( V_31 < 1 ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
if ( ! F_10 ( V_1 -> V_7 , & V_1 -> V_32 , V_2 , V_3 ) )
return FALSE ;
F_11 ( V_1 -> V_33 , V_1 -> V_32 . V_34 ) ;
V_5 = F_12 ( V_1 -> V_33 ) ;
if ( ! F_13 ( V_1 -> V_7 , V_1 -> V_32 . V_34 , V_5 , V_2 , V_3 ) )
return FALSE ;
* V_30 = V_31 ;
return TRUE ;
}
static T_3
V_27 ( T_1 * V_1 , T_5 V_35 , struct V_36 * V_32 ,
T_6 * V_37 , int V_38 , int * V_2 , T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_39 , V_35 - 1 , V_17 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 -> V_39 , V_32 , V_2 , V_3 ) )
return FALSE ;
if ( V_32 -> V_34 != ( V_40 ) V_38 ) {
* V_2 = V_41 ;
* V_3 = F_14 ( L_1 ,
V_38 , V_32 -> V_34 ) ;
return FALSE ;
}
return F_13 ( V_1 -> V_39 , V_32 -> V_34 , V_37 , V_2 , V_3 ) ;
}
static int
F_15 ( T_2 * line )
{
int V_42 , V_43 ;
while ( * line && ! isalnum ( ( V_44 ) * line ) )
line ++ ;
for ( V_43 = 0 ; V_43 < 4 ; V_43 ++ ) {
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ , line ++ )
if ( ! isxdigit ( ( V_44 ) * line ) )
return FALSE ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ , line ++ )
if ( * line != ' ' )
return FALSE ;
}
return isspace ( ( V_44 ) * line ) ;
}
static T_3
F_10 ( T_7 V_7 , struct V_36 * V_32 , int * V_2 , T_2 * * V_3 )
{
char line [ V_6 + 1 ] ;
int V_45 ;
int V_46 = 0 ;
int V_47 ;
int V_48 = 101 ;
struct V_49 V_49 ;
char V_50 [ 4 ] = { 'J' , 'A' , 'N' , 0 } ;
T_2 * V_51 ;
static const T_2 V_52 [] = L_2 ;
V_49 . V_53 = 1970 ;
V_49 . V_54 = 0 ;
V_49 . V_55 = 1 ;
V_49 . V_56 = 1 ;
V_49 . V_57 = 1 ;
V_49 . V_58 = 1 ;
do {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( ( * V_2 == 0 ) && ( V_48 != 101 ) ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( ( V_48 == 101 ) && ( V_51 = strstr ( line , L_3 ) ) != NULL
&& ( ! strstr ( line , L_4 ) ) ) {
V_45 = sscanf ( V_51 ,
L_5 ,
& V_47 , & V_49 . V_55 , V_50 ,
& V_49 . V_53 , & V_49 . V_56 ,
& V_49 . V_57 , & V_49 . V_58 , & V_48 ) ;
if ( V_45 != 8 ) {
V_45 = sscanf ( V_51 ,
L_6 ,
& V_47 , & V_49 . V_55 , V_50 ,
& V_49 . V_53 , & V_49 . V_56 ,
& V_49 . V_57 , & V_49 . V_58 , & V_48 ) ;
}
if ( V_45 != 8 ) {
* V_2 = V_41 ;
* V_3 = F_14 ( L_7 ) ;
return FALSE ;
}
}
if ( ( ! V_46 ) && ( V_51 = strstr ( line , L_8 ) ) ) {
V_51 += sizeof( L_9 ) ;
while ( * V_51 && ! isdigit ( ( V_44 ) * V_51 ) )
V_51 ++ ;
if ( ! * V_51 ) {
* V_2 = V_41 ;
* V_3 = F_14 ( L_10 ) ;
return FALSE ;
}
V_46 = atoi ( V_51 ) ;
break;
}
} while ( ! F_15 ( line ) );
V_51 = strstr ( V_52 , V_50 ) ;
if ( V_51 )
V_49 . V_54 = ( int ) ( V_51 - V_52 ) / 3 ;
V_49 . V_53 -= 1900 ;
V_49 . V_59 = - 1 ;
V_32 -> V_60 = V_61 ;
V_32 -> V_62 . V_63 = mktime ( & V_49 ) ;
V_32 -> V_62 . V_64 = V_48 * 10000000 ;
V_32 -> V_34 = V_46 ;
V_32 -> V_38 = V_46 ;
return TRUE ;
}
static T_3
F_13 ( T_7 V_7 , int V_46 , T_6 * V_5 , int * V_2 ,
T_2 * * V_3 )
{
T_2 line [ V_6 + 1 ] ;
int V_42 ;
int V_31 = 0 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 += 16 ) {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( V_42 == 0 ) {
while ( ! F_15 ( line ) ) {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
}
while ( line [ V_31 ] && ! isxdigit ( ( V_44 ) line [ V_31 ] ) )
V_31 ++ ;
}
if ( ! F_16 ( line , V_5 , V_42 ,
V_31 , V_46 - V_42 ) ) {
* V_2 = V_41 ;
* V_3 = F_14 ( L_11 ) ;
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
F_16 ( char * V_65 , T_6 * V_5 , long V_66 ,
int V_67 , int V_68 ) {
int V_42 ;
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
for ( V_42 = 0 ; V_42 < V_68 ; V_42 ++ ) {
V_72 [ 0 ] = V_65 [ V_71 [ V_42 ] + V_67 ] ;
V_72 [ 1 ] = V_65 [ V_71 [ V_42 ] + 1 + V_67 ] ;
V_5 [ V_66 + V_42 ] = ( T_6 ) strtoul ( V_72 , NULL , 16 ) ;
}
return TRUE ;
}
