int F_1 ( const char * V_1 ,
char * * V_2 )
{
char * V_3 ;
char * V_4 , * V_5 ;
char * V_6 , * V_7 = L_1 ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < sizeof( V_10 ) / sizeof( V_10 [ 0 ] ) ; V_8 ++ )
if ( ! strncmp ( V_1 , V_10 [ V_8 ] ,
strlen ( V_10 [ V_8 ] ) ) ) {
V_7 = V_10 [ V_8 ] ;
break;
}
V_3 = F_2 ( V_1 + strlen ( V_7 ) + 1 ) ;
if ( ! V_3 )
return - V_11 ;
V_6 = strtok ( V_3 , L_2 ) ;
if ( ! V_6 ) {
free ( V_3 ) ;
return - V_12 ;
}
V_4 = V_6 ;
V_5 = V_6 ;
while ( * V_5 != '\0' ) {
if ( ! isdigit ( * V_5 ) ) {
* V_4 = * V_5 ;
V_4 ++ ;
}
V_5 ++ ;
}
* V_4 = '\0' ;
V_9 = F_3 ( V_2 , L_3 , V_7 , V_6 ) ;
free ( V_3 ) ;
return ( V_9 == - 1 ) ? - V_11 : 0 ;
}
int F_4 ( unsigned * V_13 ,
unsigned * V_14 ,
unsigned * V_15 ,
unsigned * V_16 ,
T_1 * V_17 ,
unsigned * V_18 ,
const char * V_19 ,
const char * V_20 ,
const char * V_2 )
{
T_2 * V_21 ;
int V_9 ;
T_3 * V_22 ;
char * V_23 , * V_24 , * V_25 , * V_26 = 0 ;
char V_27 , V_28 ;
unsigned V_29 ;
const struct V_30 * V_31 ;
V_9 = F_3 ( & V_23 , V_32 , V_19 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_9 = F_3 ( & V_24 , V_33 , V_20 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_34;
}
V_9 = F_3 ( & V_25 , V_33 , V_2 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_35;
}
V_22 = F_5 ( V_23 ) ;
if ( V_22 == NULL ) {
V_9 = - V_36 ;
goto V_37;
}
V_9 = - V_38 ;
while ( V_31 = F_6 ( V_22 ) , V_31 != NULL )
if ( ( strcmp ( V_24 , V_31 -> V_39 ) == 0 ) ||
( strcmp ( V_25 , V_31 -> V_39 ) == 0 ) ) {
V_9 = F_3 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_40;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_6 , V_26 ) ;
goto V_41;
}
V_9 = fscanf ( V_21 ,
L_7 ,
& V_28 ,
& V_27 ,
V_15 ,
& V_29 , V_16 ) ;
if ( V_9 < 0 ) {
V_9 = - V_36 ;
printf ( L_8 ) ;
goto V_42;
} else if ( V_9 != 5 ) {
V_9 = - V_43 ;
printf ( L_9 ) ;
goto V_42;
}
* V_18 = ( V_28 == 'b' ) ;
* V_14 = V_29 / 8 ;
if ( * V_15 == 64 )
* V_17 = ~ 0 ;
else
* V_17 = ( 1 << * V_15 ) - 1 ;
* V_13 = ( V_27 == 's' ) ;
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
printf ( L_10 , V_26 ) ;
goto V_41;
}
V_21 = 0 ;
free ( V_26 ) ;
V_26 = 0 ;
}
V_42:
if ( V_21 )
if ( fclose ( V_21 ) )
perror ( L_11 ) ;
V_41:
if ( V_26 )
free ( V_26 ) ;
V_40:
if ( F_7 ( V_22 ) == - 1 )
perror ( L_12 ) ;
V_37:
free ( V_25 ) ;
V_35:
free ( V_24 ) ;
V_34:
free ( V_23 ) ;
return V_9 ;
}
int F_8 ( float * V_44 ,
const char * V_45 ,
const char * V_19 ,
const char * V_20 ,
const char * V_2 )
{
T_2 * V_21 ;
int V_9 ;
T_3 * V_22 ;
char * V_24 , * V_25 ;
char * V_26 = NULL ;
const struct V_30 * V_31 ;
V_9 = F_3 ( & V_24 , L_3 , V_20 , V_45 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_9 = F_3 ( & V_25 ,
L_3 , V_2 , V_45 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_35;
}
V_22 = F_5 ( V_19 ) ;
if ( V_22 == NULL ) {
V_9 = - V_36 ;
goto V_37;
}
V_9 = - V_38 ;
while ( V_31 = F_6 ( V_22 ) , V_31 != NULL )
if ( ( strcmp ( V_24 , V_31 -> V_39 ) == 0 ) ||
( strcmp ( V_25 , V_31 -> V_39 ) == 0 ) ) {
V_9 = F_3 ( & V_26 ,
L_4 , V_19 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_40;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
goto V_41;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_13 , V_44 ) != 1 )
V_9 = V_36 ? - V_36 : - V_46 ;
break;
}
V_41:
if ( V_26 )
free ( V_26 ) ;
V_40:
if ( F_7 ( V_22 ) == - 1 )
perror ( L_14 ) ;
V_37:
free ( V_25 ) ;
V_35:
free ( V_24 ) ;
return V_9 ;
}
void F_9 ( struct V_47 * * V_48 ,
int V_49 )
{
struct V_47 V_50 ;
int V_51 , V_52 ;
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ )
for ( V_52 = 0 ; V_52 < ( V_49 - 1 ) ; V_52 ++ )
if ( ( * V_48 ) [ V_52 ] . V_53 > ( * V_48 ) [ V_52 + 1 ] . V_53 ) {
V_50 = ( * V_48 ) [ V_52 + 1 ] ;
( * V_48 ) [ V_52 + 1 ] = ( * V_48 ) [ V_52 ] ;
( * V_48 ) [ V_52 ] = V_50 ;
}
}
int F_10 ( const char * V_19 ,
struct V_47 * * V_48 ,
int * V_54 )
{
T_3 * V_22 ;
T_2 * V_21 ;
int V_55 = 0 , V_8 ;
struct V_47 * V_3 ;
int V_9 ;
const struct V_30 * V_31 ;
char * V_23 ;
char * V_26 ;
* V_54 = 0 ;
V_9 = F_3 ( & V_23 , V_32 , V_19 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_22 = F_5 ( V_23 ) ;
if ( V_22 == NULL ) {
V_9 = - V_36 ;
goto V_56;
}
while ( V_31 = F_6 ( V_22 ) , V_31 != NULL )
if ( strcmp ( V_31 -> V_39 + strlen ( V_31 -> V_39 ) - strlen ( L_15 ) ,
L_15 ) == 0 ) {
V_9 = F_3 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_57;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_57;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_16 , & V_9 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_17 ) ;
free ( V_26 ) ;
goto V_57;
}
if ( V_9 == 1 )
( * V_54 ) ++ ;
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_57;
}
free ( V_26 ) ;
}
* V_48 = malloc ( sizeof( * * V_48 ) * ( * V_54 ) ) ;
if ( * V_48 == NULL ) {
V_9 = - V_11 ;
goto V_57;
}
F_11 ( V_22 , 0 ) ;
while ( V_31 = F_6 ( V_22 ) , V_31 != NULL ) {
if ( strcmp ( V_31 -> V_39 + strlen ( V_31 -> V_39 ) - strlen ( L_15 ) ,
L_15 ) == 0 ) {
int V_58 = 0 ;
V_3 = & ( * V_48 ) [ V_55 ++ ] ;
V_9 = F_3 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
V_55 -- ;
goto V_59;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
free ( V_26 ) ;
V_55 -- ;
goto V_59;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_16 , & V_58 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
free ( V_26 ) ;
V_55 -- ;
goto V_59;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
V_55 -- ;
goto V_59;
}
if ( ! V_58 ) {
free ( V_26 ) ;
V_55 -- ;
continue;
}
V_3 -> V_60 = 1.0 ;
V_3 -> V_61 = 0 ;
V_3 -> V_20 = F_12 ( V_31 -> V_39 ,
strlen ( V_31 -> V_39 ) -
strlen ( L_15 ) ) ;
if ( V_3 -> V_20 == NULL ) {
free ( V_26 ) ;
V_9 = - V_11 ;
V_55 -- ;
goto V_59;
}
V_9 = F_1 ( V_3 -> V_20 ,
& V_3 -> V_2 ) ;
if ( V_9 ) {
free ( V_26 ) ;
free ( V_3 -> V_20 ) ;
V_55 -- ;
goto V_59;
}
V_9 = F_3 ( & V_26 ,
L_18 ,
V_23 ,
V_3 -> V_20 ) ;
if ( V_9 < 0 ) {
free ( V_26 ) ;
V_9 = - V_11 ;
goto V_59;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_6 , V_26 ) ;
free ( V_26 ) ;
goto V_59;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_19 , & V_3 -> V_53 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_17 ) ;
free ( V_26 ) ;
goto V_59;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_59;
}
free ( V_26 ) ;
V_9 = F_8 ( & V_3 -> V_60 ,
L_20 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( V_9 < 0 )
goto V_59;
V_9 = F_8 ( & V_3 -> V_61 ,
L_21 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( V_9 < 0 )
goto V_59;
V_9 = F_4 ( & V_3 -> V_13 ,
& V_3 -> V_14 ,
& V_3 -> V_15 ,
& V_3 -> V_16 ,
& V_3 -> V_17 ,
& V_3 -> V_18 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( V_9 < 0 )
goto V_59;
}
}
if ( F_7 ( V_22 ) == - 1 ) {
V_9 = - V_36 ;
goto V_59;
}
free ( V_23 ) ;
F_9 ( V_48 , * V_54 ) ;
return 0 ;
V_59:
for ( V_8 = V_55 - 1 ; V_8 >= 0 ; V_8 -- ) {
free ( ( * V_48 ) [ V_8 ] . V_20 ) ;
free ( ( * V_48 ) [ V_8 ] . V_2 ) ;
}
free ( * V_48 ) ;
V_57:
if ( V_22 )
if ( F_7 ( V_22 ) == - 1 )
perror ( L_22 ) ;
V_56:
free ( V_23 ) ;
return V_9 ;
}
int F_13 ( int V_62 )
{
int V_55 = 0 ;
while ( V_62 != 0 ) {
V_62 /= 10 ;
V_55 ++ ;
}
return V_55 ;
}
int F_14 ( const char * V_20 , const char * type )
{
const struct V_30 * V_31 ;
int V_63 , V_64 , V_9 ;
T_2 * V_65 ;
T_3 * V_22 ;
char V_66 [ V_67 ] ;
char * V_26 ;
V_22 = F_5 ( V_68 ) ;
if ( V_22 == NULL ) {
printf ( L_23 ) ;
return - V_69 ;
}
while ( V_31 = F_6 ( V_22 ) , V_31 != NULL ) {
if ( strcmp ( V_31 -> V_39 , L_24 ) != 0 &&
strcmp ( V_31 -> V_39 , L_25 ) != 0 &&
strlen ( V_31 -> V_39 ) > strlen ( type ) &&
strncmp ( V_31 -> V_39 , type , strlen ( type ) ) == 0 ) {
V_36 = 0 ;
V_9 = sscanf ( V_31 -> V_39 + strlen ( type ) , L_26 , & V_63 ) ;
if ( V_9 < 0 ) {
V_9 = - V_36 ;
printf ( L_27 ) ;
goto V_57;
} else if ( V_9 != 1 ) {
V_9 = - V_43 ;
printf ( L_28 ) ;
goto V_57;
}
V_64 = F_13 ( V_63 ) ;
if ( strncmp ( V_31 -> V_39 + strlen ( type ) + V_64 ,
L_29 ,
1 ) != 0 ) {
V_26 = malloc ( strlen ( V_68 )
+ strlen ( type )
+ V_64
+ 6 ) ;
if ( V_26 == NULL ) {
V_9 = - V_11 ;
goto V_57;
}
V_9 = sprintf ( V_26 , L_30 , V_68 ,
type , V_63 ) ;
if ( V_9 < 0 ) {
free ( V_26 ) ;
goto V_57;
}
V_65 = fopen ( V_26 , L_5 ) ;
if ( ! V_65 ) {
free ( V_26 ) ;
continue;
}
free ( V_26 ) ;
V_36 = 0 ;
if ( fscanf ( V_65 , L_31 , V_66 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
goto V_57;
}
if ( fclose ( V_65 ) ) {
V_9 = - V_36 ;
goto V_57;
}
if ( strcmp ( V_20 , V_66 ) == 0 ) {
if ( F_7 ( V_22 ) == - 1 )
return - V_36 ;
return V_63 ;
}
}
}
}
if ( F_7 ( V_22 ) == - 1 )
return - V_36 ;
return - V_69 ;
V_57:
if ( F_7 ( V_22 ) == - 1 )
perror ( L_32 ) ;
return V_9 ;
}
static int F_15 ( const char * V_26 , const char * V_70 , int V_71 ,
int V_72 )
{
int V_9 = 0 ;
T_2 * V_21 ;
int V_73 ;
char * V_50 = malloc ( strlen ( V_70 ) + strlen ( V_26 ) + 2 ) ;
if ( V_50 == NULL )
return - V_11 ;
V_9 = sprintf ( V_50 , L_4 , V_70 , V_26 ) ;
if ( V_9 < 0 )
goto V_74;
V_21 = fopen ( V_50 , L_33 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_6 , V_50 ) ;
goto V_74;
}
V_9 = fprintf ( V_21 , L_26 , V_71 ) ;
if ( V_9 < 0 ) {
if ( fclose ( V_21 ) )
perror ( L_34 ) ;
goto V_74;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_74;
}
if ( V_72 ) {
V_21 = fopen ( V_50 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_6 , V_50 ) ;
goto V_74;
}
if ( fscanf ( V_21 , L_26 , & V_73 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_34 ) ;
goto V_74;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_74;
}
if ( V_73 != V_71 ) {
printf ( L_35 ,
V_71 ,
V_70 ,
V_26 ) ;
V_9 = - 1 ;
}
}
V_74:
free ( V_50 ) ;
return V_9 ;
}
int F_16 ( const char * V_26 , const char * V_70 , int V_71 )
{
return F_15 ( V_26 , V_70 , V_71 , 0 ) ;
}
int F_17 ( const char * V_26 , const char * V_70 ,
int V_71 )
{
return F_15 ( V_26 , V_70 , V_71 , 1 ) ;
}
static int F_18 ( const char * V_26 , const char * V_70 ,
const char * V_71 , int V_72 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_50 = malloc ( strlen ( V_70 ) + strlen ( V_26 ) + 2 ) ;
if ( V_50 == NULL ) {
printf ( L_36 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_50 , L_4 , V_70 , V_26 ) ;
if ( V_9 < 0 )
goto V_74;
V_21 = fopen ( V_50 , L_33 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_37 , V_50 ) ;
goto V_74;
}
V_9 = fprintf ( V_21 , L_31 , V_71 ) ;
if ( V_9 < 0 ) {
if ( fclose ( V_21 ) )
perror ( L_38 ) ;
goto V_74;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_74;
}
if ( V_72 ) {
V_21 = fopen ( V_50 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
printf ( L_39 ) ;
goto V_74;
}
if ( fscanf ( V_21 , L_31 , V_50 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_38 ) ;
goto V_74;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_74;
}
if ( strcmp ( V_50 , V_71 ) != 0 ) {
printf ( L_40
L_41
L_42 ,
V_50 ,
V_71 ,
V_70 ,
V_26 ) ;
V_9 = - 1 ;
}
}
V_74:
free ( V_50 ) ;
return V_9 ;
}
int F_19 ( const char * V_26 , const char * V_70 ,
const char * V_71 )
{
return F_18 ( V_26 , V_70 , V_71 , 1 ) ;
}
int F_20 ( const char * V_26 , const char * V_70 ,
const char * V_71 )
{
return F_18 ( V_26 , V_70 , V_71 , 0 ) ;
}
int F_21 ( const char * V_26 , const char * V_70 )
{
int V_9 ;
T_2 * V_21 ;
char * V_50 = malloc ( strlen ( V_70 ) + strlen ( V_26 ) + 2 ) ;
if ( V_50 == NULL ) {
printf ( L_43 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_50 , L_4 , V_70 , V_26 ) ;
if ( V_9 < 0 )
goto V_74;
V_21 = fopen ( V_50 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
goto V_74;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_44 , & V_9 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_45 ) ;
goto V_74;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_74:
free ( V_50 ) ;
return V_9 ;
}
int F_22 ( const char * V_26 , const char * V_70 , float * V_71 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_50 = malloc ( strlen ( V_70 ) + strlen ( V_26 ) + 2 ) ;
if ( V_50 == NULL ) {
printf ( L_43 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_50 , L_4 , V_70 , V_26 ) ;
if ( V_9 < 0 )
goto V_74;
V_21 = fopen ( V_50 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
goto V_74;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_46 , V_71 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_47 ) ;
goto V_74;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_74:
free ( V_50 ) ;
return V_9 ;
}
int F_23 ( const char * V_26 , const char * V_70 , char * V_75 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_50 = malloc ( strlen ( V_70 ) + strlen ( V_26 ) + 2 ) ;
if ( V_50 == NULL ) {
printf ( L_43 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_50 , L_4 , V_70 , V_26 ) ;
if ( V_9 < 0 )
goto V_74;
V_21 = fopen ( V_50 , L_5 ) ;
if ( V_21 == NULL ) {
V_9 = - V_36 ;
goto V_74;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_48 , V_75 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_46 ;
if ( fclose ( V_21 ) )
perror ( L_49 ) ;
goto V_74;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_74:
free ( V_50 ) ;
return V_9 ;
}
