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
T_6 F_8 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
if ( ! F_6 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return V_19 ;
return V_20 ;
}
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = 0 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
return V_32 ;
}
static T_3 V_27 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_33 )
{
T_5 V_34 = 0 ;
#ifdef F_9
V_34 = F_1 ( V_1 , V_2 , V_3 ) ;
#else
V_34 = F_2 ( V_1 -> V_7 ) ;
#endif
if ( V_34 < 1 ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
* V_33 = V_34 ;
return F_10 ( V_1 -> V_7 , & V_1 -> V_35 , V_1 -> V_36 , V_2 , V_3 ) ;
}
static T_3
V_29 ( T_1 * V_1 , T_5 V_37 , struct V_38 * V_35 ,
T_7 * V_5 , int * V_2 , T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_39 , V_37 - 1 , V_17 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 -> V_39 , V_35 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static int
F_11 ( T_2 * line )
{
int V_40 , V_41 ;
while ( * line && ! F_12 ( * line ) )
line ++ ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ , line ++ )
if ( ! F_13 ( * line ) )
return FALSE ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ , line ++ )
if ( * line != ' ' )
return FALSE ;
}
return F_14 ( * line ) ;
}
static T_3
F_10 ( T_8 V_7 , struct V_38 * V_35 , T_7 * V_5 , int * V_2 , T_2 * * V_3 )
{
char line [ V_6 + 1 ] ;
int V_42 ;
int V_43 = 0 ;
int V_44 ;
int V_45 = 101 ;
struct V_46 V_46 ;
char V_47 [ 4 ] = { 'J' , 'A' , 'N' , 0 } ;
T_2 * V_48 ;
static const T_2 V_49 [] = L_1 ;
int V_40 ;
int V_34 = 0 ;
T_9 * V_50 ;
V_46 . V_51 = 1970 ;
V_46 . V_52 = 0 ;
V_46 . V_53 = 1 ;
V_46 . V_54 = 1 ;
V_46 . V_55 = 1 ;
V_46 . V_56 = 1 ;
do {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( ( * V_2 == 0 ) && ( V_45 != 101 ) ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( ( V_45 == 101 ) && ( V_48 = strstr ( line , L_2 ) ) != NULL
&& ( ! strstr ( line , L_3 ) ) ) {
V_42 = sscanf ( V_48 ,
L_4 ,
& V_44 , & V_46 . V_53 , V_47 ,
& V_46 . V_51 , & V_46 . V_54 ,
& V_46 . V_55 , & V_46 . V_56 , & V_45 ) ;
if ( V_42 != 8 ) {
V_42 = sscanf ( V_48 ,
L_5 ,
& V_44 , & V_46 . V_53 , V_47 ,
& V_46 . V_51 , & V_46 . V_54 ,
& V_46 . V_55 , & V_46 . V_56 , & V_45 ) ;
}
if ( V_42 != 8 ) {
* V_2 = V_57 ;
* V_3 = F_15 ( L_6 ) ;
return FALSE ;
}
}
if ( ( ! V_43 ) && ( V_48 = strstr ( line , L_7 ) ) ) {
V_48 += sizeof( L_8 ) ;
while ( * V_48 && ! F_16 ( * V_48 ) )
V_48 ++ ;
if ( ! * V_48 ) {
* V_2 = V_57 ;
* V_3 = F_15 ( L_9 ) ;
return FALSE ;
}
V_43 = atoi ( V_48 ) ;
break;
}
} while ( ! F_11 ( line ) );
V_48 = strstr ( V_49 , V_47 ) ;
if ( V_48 )
V_46 . V_52 = ( int ) ( V_48 - V_49 ) / 3 ;
V_46 . V_51 -= 1900 ;
V_46 . V_58 = - 1 ;
V_35 -> V_59 = V_60 ;
V_35 -> V_61 = V_62 ;
V_35 -> V_63 . V_64 = mktime ( & V_46 ) ;
V_35 -> V_63 . V_65 = V_45 * 10000000 ;
V_35 -> V_66 = V_43 ;
V_35 -> V_67 = V_43 ;
F_17 ( V_5 , V_43 ) ;
V_50 = F_18 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_43 ; V_40 += 16 ) {
if ( F_4 ( line , V_6 , V_7 ) == NULL ) {
* V_2 = F_3 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
line [ V_6 ] = '\0' ;
if ( V_40 == 0 ) {
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
while ( line [ V_34 ] && ! F_13 ( line [ V_34 ] ) )
V_34 ++ ;
}
if ( ! F_19 ( line , V_50 , V_40 ,
V_34 , V_43 - V_40 ) ) {
* V_2 = V_57 ;
* V_3 = F_15 ( L_10 ) ;
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
F_19 ( char * V_68 , T_9 * V_5 , long V_69 ,
int V_70 , int V_71 ) {
int V_40 ;
char * V_72 ;
int V_73 ;
static const int V_74 [ 16 ] = { 39 , 37 , 35 , 33 , 28 , 26 , 24 , 22 , 17 , 15 , 13 , 11 , 6 , 4 , 2 , 0 } ;
char V_75 [ 3 ] = { 0 , 0 , 0 } ;
V_72 = V_68 ;
V_73 = ( int ) strtoul ( V_72 + 45 + V_70 , NULL , 16 ) ;
if ( V_73 != V_69 ) {
return FALSE ;
}
if ( V_71 > 16 )
V_71 = 16 ;
for ( V_40 = 0 ; V_40 < V_71 ; V_40 ++ ) {
V_75 [ 0 ] = V_68 [ V_74 [ V_40 ] + V_70 ] ;
V_75 [ 1 ] = V_68 [ V_74 [ V_40 ] + 1 + V_70 ] ;
V_5 [ V_69 + V_40 ] = ( T_9 ) strtoul ( V_75 , NULL , 16 ) ;
}
return TRUE ;
}
