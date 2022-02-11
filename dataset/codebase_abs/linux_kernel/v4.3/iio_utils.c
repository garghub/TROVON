int F_1 ( const char * V_1 , char * * V_2 )
{
char * V_3 ;
char * V_4 , * V_5 ;
char * V_6 , * V_7 = L_1 ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; V_8 ++ )
if ( ! strncmp ( V_1 , V_10 [ V_8 ] ,
strlen ( V_10 [ V_8 ] ) ) ) {
V_7 = V_10 [ V_8 ] ;
break;
}
V_3 = F_3 ( V_1 + strlen ( V_7 ) + 1 ) ;
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
V_9 = F_4 ( V_2 , L_3 , V_7 , V_6 ) ;
free ( V_3 ) ;
return ( V_9 == - 1 ) ? - V_11 : 0 ;
}
int F_5 ( unsigned * V_13 , unsigned * V_14 , unsigned * V_15 ,
unsigned * V_16 , T_1 * V_17 , unsigned * V_18 ,
const char * V_19 , const char * V_20 ,
const char * V_2 )
{
T_2 * V_21 ;
int V_9 ;
T_3 * V_22 ;
char * V_23 , * V_24 , * V_25 , * V_26 = 0 ;
char V_27 , V_28 ;
unsigned V_29 ;
const struct V_30 * V_31 ;
V_9 = F_4 ( & V_23 , V_32 , V_19 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_9 = F_4 ( & V_24 , V_33 , V_20 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_34;
}
V_9 = F_4 ( & V_25 , V_33 , V_2 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_35;
}
V_22 = F_6 ( V_23 ) ;
if ( ! V_22 ) {
V_9 = - V_36 ;
goto V_37;
}
V_9 = - V_38 ;
while ( V_31 = F_7 ( V_22 ) , V_31 )
if ( ( strcmp ( V_24 , V_31 -> V_39 ) == 0 ) ||
( strcmp ( V_25 , V_31 -> V_39 ) == 0 ) ) {
V_9 = F_4 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_40;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_6 ,
V_26 ) ;
goto V_42;
}
V_9 = fscanf ( V_21 ,
L_7 ,
& V_28 ,
& V_27 ,
V_15 ,
& V_29 , V_16 ) ;
if ( V_9 < 0 ) {
V_9 = - V_36 ;
fprintf ( V_41 ,
L_8 ) ;
goto V_43;
} else if ( V_9 != 5 ) {
V_9 = - V_44 ;
fprintf ( V_41 ,
L_9 ) ;
goto V_43;
}
* V_18 = ( V_28 == 'b' ) ;
* V_14 = V_29 / 8 ;
if ( * V_15 == 64 )
* V_17 = ~ 0 ;
else
* V_17 = ( 1ULL << * V_15 ) - 1 ;
* V_13 = ( V_27 == 's' ) ;
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_10 ,
V_26 ) ;
goto V_42;
}
V_21 = 0 ;
free ( V_26 ) ;
V_26 = 0 ;
}
V_43:
if ( V_21 )
if ( fclose ( V_21 ) )
perror ( L_11 ) ;
V_42:
if ( V_26 )
free ( V_26 ) ;
V_40:
if ( F_8 ( V_22 ) == - 1 )
perror ( L_12 ) ;
V_37:
free ( V_25 ) ;
V_35:
free ( V_24 ) ;
V_34:
free ( V_23 ) ;
return V_9 ;
}
int F_9 ( float * V_45 , const char * V_46 ,
const char * V_19 , const char * V_20 ,
const char * V_2 )
{
T_2 * V_21 ;
int V_9 ;
T_3 * V_22 ;
char * V_24 , * V_25 ;
char * V_26 = NULL ;
const struct V_30 * V_31 ;
V_9 = F_4 ( & V_24 , L_3 , V_20 , V_46 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_9 = F_4 ( & V_25 ,
L_3 , V_2 , V_46 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_35;
}
V_22 = F_6 ( V_19 ) ;
if ( ! V_22 ) {
V_9 = - V_36 ;
goto V_37;
}
V_9 = - V_38 ;
while ( V_31 = F_7 ( V_22 ) , V_31 )
if ( ( strcmp ( V_24 , V_31 -> V_39 ) == 0 ) ||
( strcmp ( V_25 , V_31 -> V_39 ) == 0 ) ) {
V_9 = F_4 ( & V_26 ,
L_4 , V_19 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_40;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
goto V_42;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_13 , V_45 ) != 1 )
V_9 = V_36 ? - V_36 : - V_47 ;
break;
}
V_42:
if ( V_26 )
free ( V_26 ) ;
V_40:
if ( F_8 ( V_22 ) == - 1 )
perror ( L_14 ) ;
V_37:
free ( V_25 ) ;
V_35:
free ( V_24 ) ;
return V_9 ;
}
void F_10 ( struct V_48 * V_49 , int V_50 )
{
struct V_48 V_51 ;
int V_52 , V_53 ;
for ( V_52 = 0 ; V_52 < V_50 ; V_52 ++ )
for ( V_53 = 0 ; V_53 < ( V_50 - 1 ) ; V_53 ++ )
if ( V_49 [ V_53 ] . V_54 > V_49 [ V_53 + 1 ] . V_54 ) {
V_51 = V_49 [ V_53 + 1 ] ;
V_49 [ V_53 + 1 ] = V_49 [ V_53 ] ;
V_49 [ V_53 ] = V_51 ;
}
}
int F_11 ( const char * V_19 ,
struct V_48 * * V_49 , int * V_55 )
{
T_3 * V_22 ;
T_2 * V_21 ;
int V_56 = 0 , V_8 ;
struct V_48 * V_3 ;
int V_9 ;
const struct V_30 * V_31 ;
char * V_23 ;
char * V_26 ;
* V_55 = 0 ;
V_9 = F_4 ( & V_23 , V_32 , V_19 ) ;
if ( V_9 < 0 )
return - V_11 ;
V_22 = F_6 ( V_23 ) ;
if ( ! V_22 ) {
V_9 = - V_36 ;
goto V_57;
}
while ( V_31 = F_7 ( V_22 ) , V_31 )
if ( strcmp ( V_31 -> V_39 + strlen ( V_31 -> V_39 ) - strlen ( L_15 ) ,
L_15 ) == 0 ) {
V_9 = F_4 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
goto V_58;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_58;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_16 , & V_9 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_17 ) ;
free ( V_26 ) ;
goto V_58;
}
if ( V_9 == 1 )
( * V_55 ) ++ ;
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_58;
}
free ( V_26 ) ;
}
* V_49 = malloc ( sizeof( * * V_49 ) * ( * V_55 ) ) ;
if ( ! * V_49 ) {
V_9 = - V_11 ;
goto V_58;
}
F_12 ( V_22 , 0 ) ;
while ( V_31 = F_7 ( V_22 ) , V_31 ) {
if ( strcmp ( V_31 -> V_39 + strlen ( V_31 -> V_39 ) - strlen ( L_15 ) ,
L_15 ) == 0 ) {
int V_59 = 0 ;
V_3 = & ( * V_49 ) [ V_56 ++ ] ;
V_9 = F_4 ( & V_26 ,
L_4 , V_23 , V_31 -> V_39 ) ;
if ( V_9 < 0 ) {
V_9 = - V_11 ;
V_56 -- ;
goto V_60;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
free ( V_26 ) ;
V_56 -- ;
goto V_60;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_16 , & V_59 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
free ( V_26 ) ;
V_56 -- ;
goto V_60;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
V_56 -- ;
goto V_60;
}
if ( ! V_59 ) {
free ( V_26 ) ;
V_56 -- ;
continue;
}
V_3 -> V_61 = 1.0 ;
V_3 -> V_62 = 0 ;
V_3 -> V_20 = F_13 ( V_31 -> V_39 ,
strlen ( V_31 -> V_39 ) -
strlen ( L_15 ) ) ;
if ( ! V_3 -> V_20 ) {
free ( V_26 ) ;
V_9 = - V_11 ;
V_56 -- ;
goto V_60;
}
V_9 = F_1 ( V_3 -> V_20 ,
& V_3 -> V_2 ) ;
if ( V_9 ) {
free ( V_26 ) ;
free ( V_3 -> V_20 ) ;
V_56 -- ;
goto V_60;
}
V_9 = F_4 ( & V_26 ,
L_18 ,
V_23 ,
V_3 -> V_20 ) ;
if ( V_9 < 0 ) {
free ( V_26 ) ;
V_9 = - V_11 ;
goto V_60;
}
V_21 = fopen ( V_26 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_6 ,
V_26 ) ;
free ( V_26 ) ;
goto V_60;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_19 , & V_3 -> V_54 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_17 ) ;
free ( V_26 ) ;
goto V_60;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
free ( V_26 ) ;
goto V_60;
}
free ( V_26 ) ;
V_9 = F_9 ( & V_3 -> V_61 ,
L_20 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( ( V_9 < 0 ) && ( V_9 != - V_38 ) )
goto V_60;
V_9 = F_9 ( & V_3 -> V_62 ,
L_21 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( ( V_9 < 0 ) && ( V_9 != - V_38 ) )
goto V_60;
V_9 = F_5 ( & V_3 -> V_13 ,
& V_3 -> V_14 ,
& V_3 -> V_15 ,
& V_3 -> V_16 ,
& V_3 -> V_17 ,
& V_3 -> V_18 ,
V_19 ,
V_3 -> V_20 ,
V_3 -> V_2 ) ;
if ( V_9 < 0 )
goto V_60;
}
}
if ( F_8 ( V_22 ) == - 1 ) {
V_9 = - V_36 ;
goto V_60;
}
free ( V_23 ) ;
F_10 ( * V_49 , * V_55 ) ;
return 0 ;
V_60:
for ( V_8 = V_56 - 1 ; V_8 >= 0 ; V_8 -- ) {
free ( ( * V_49 ) [ V_8 ] . V_20 ) ;
free ( ( * V_49 ) [ V_8 ] . V_2 ) ;
}
free ( * V_49 ) ;
* V_49 = NULL ;
* V_55 = 0 ;
V_58:
if ( V_22 )
if ( F_8 ( V_22 ) == - 1 )
perror ( L_22 ) ;
V_57:
free ( V_23 ) ;
return V_9 ;
}
static int F_14 ( int V_63 )
{
int V_56 = 0 ;
while ( V_63 != 0 ) {
V_63 /= 10 ;
V_56 ++ ;
}
return V_56 ;
}
int F_15 ( const char * V_20 , const char * type )
{
const struct V_30 * V_31 ;
int V_64 , V_65 , V_9 ;
T_2 * V_66 ;
T_3 * V_22 ;
char V_67 [ V_68 ] ;
char * V_26 ;
V_22 = F_6 ( V_69 ) ;
if ( ! V_22 ) {
fprintf ( V_41 , L_23 ) ;
return - V_70 ;
}
while ( V_31 = F_7 ( V_22 ) , V_31 ) {
if ( strcmp ( V_31 -> V_39 , L_24 ) != 0 &&
strcmp ( V_31 -> V_39 , L_25 ) != 0 &&
strlen ( V_31 -> V_39 ) > strlen ( type ) &&
strncmp ( V_31 -> V_39 , type , strlen ( type ) ) == 0 ) {
V_36 = 0 ;
V_9 = sscanf ( V_31 -> V_39 + strlen ( type ) , L_26 , & V_64 ) ;
if ( V_9 < 0 ) {
V_9 = - V_36 ;
fprintf ( V_41 ,
L_27 ) ;
goto V_58;
} else if ( V_9 != 1 ) {
V_9 = - V_44 ;
fprintf ( V_41 ,
L_28 ) ;
goto V_58;
}
V_65 = F_14 ( V_64 ) ;
if ( strncmp ( V_31 -> V_39 + strlen ( type ) + V_65 ,
L_29 , 1 ) != 0 ) {
V_26 = malloc ( strlen ( V_69 ) + strlen ( type )
+ V_65 + 6 ) ;
if ( ! V_26 ) {
V_9 = - V_11 ;
goto V_58;
}
V_9 = sprintf ( V_26 , L_30 , V_69 ,
type , V_64 ) ;
if ( V_9 < 0 ) {
free ( V_26 ) ;
goto V_58;
}
V_66 = fopen ( V_26 , L_5 ) ;
if ( ! V_66 ) {
free ( V_26 ) ;
continue;
}
free ( V_26 ) ;
V_36 = 0 ;
if ( fscanf ( V_66 , L_31 , V_67 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
goto V_58;
}
if ( fclose ( V_66 ) ) {
V_9 = - V_36 ;
goto V_58;
}
if ( strcmp ( V_20 , V_67 ) == 0 ) {
if ( F_8 ( V_22 ) == - 1 )
return - V_36 ;
return V_64 ;
}
}
}
}
if ( F_8 ( V_22 ) == - 1 )
return - V_36 ;
return - V_70 ;
V_58:
if ( F_8 ( V_22 ) == - 1 )
perror ( L_32 ) ;
return V_9 ;
}
static int F_16 ( const char * V_26 , const char * V_71 , int V_72 ,
int V_73 )
{
int V_9 = 0 ;
T_2 * V_21 ;
int V_74 ;
char * V_51 = malloc ( strlen ( V_71 ) + strlen ( V_26 ) + 2 ) ;
if ( ! V_51 )
return - V_11 ;
V_9 = sprintf ( V_51 , L_4 , V_71 , V_26 ) ;
if ( V_9 < 0 )
goto V_75;
V_21 = fopen ( V_51 , L_33 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_6 , V_51 ) ;
goto V_75;
}
V_9 = fprintf ( V_21 , L_26 , V_72 ) ;
if ( V_9 < 0 ) {
if ( fclose ( V_21 ) )
perror ( L_34 ) ;
goto V_75;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_75;
}
if ( V_73 ) {
V_21 = fopen ( V_51 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_6 , V_51 ) ;
goto V_75;
}
if ( fscanf ( V_21 , L_26 , & V_74 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_34 ) ;
goto V_75;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_75;
}
if ( V_74 != V_72 ) {
fprintf ( V_41 ,
L_35 ,
V_72 , V_71 , V_26 ) ;
V_9 = - 1 ;
}
}
V_75:
free ( V_51 ) ;
return V_9 ;
}
int F_17 ( const char * V_26 , const char * V_71 , int V_72 )
{
return F_16 ( V_26 , V_71 , V_72 , 0 ) ;
}
int F_18 ( const char * V_26 , const char * V_71 ,
int V_72 )
{
return F_16 ( V_26 , V_71 , V_72 , 1 ) ;
}
static int F_19 ( const char * V_26 , const char * V_71 ,
const char * V_72 , int V_73 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_51 = malloc ( strlen ( V_71 ) + strlen ( V_26 ) + 2 ) ;
if ( ! V_51 ) {
fprintf ( V_41 , L_36 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_51 , L_4 , V_71 , V_26 ) ;
if ( V_9 < 0 )
goto V_75;
V_21 = fopen ( V_51 , L_33 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_37 , V_51 ) ;
goto V_75;
}
V_9 = fprintf ( V_21 , L_31 , V_72 ) ;
if ( V_9 < 0 ) {
if ( fclose ( V_21 ) )
perror ( L_38 ) ;
goto V_75;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_75;
}
if ( V_73 ) {
V_21 = fopen ( V_51 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
fprintf ( V_41 , L_39 ) ;
goto V_75;
}
if ( fscanf ( V_21 , L_31 , V_51 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_38 ) ;
goto V_75;
}
if ( fclose ( V_21 ) ) {
V_9 = - V_36 ;
goto V_75;
}
if ( strcmp ( V_51 , V_72 ) != 0 ) {
fprintf ( V_41 ,
L_40
L_41 , V_51 , V_72 ,
V_71 , V_26 ) ;
V_9 = - 1 ;
}
}
V_75:
free ( V_51 ) ;
return V_9 ;
}
int F_20 ( const char * V_26 , const char * V_71 ,
const char * V_72 )
{
return F_19 ( V_26 , V_71 , V_72 , 1 ) ;
}
int F_21 ( const char * V_26 , const char * V_71 ,
const char * V_72 )
{
return F_19 ( V_26 , V_71 , V_72 , 0 ) ;
}
int F_22 ( const char * V_26 , const char * V_71 )
{
int V_9 ;
T_2 * V_21 ;
char * V_51 = malloc ( strlen ( V_71 ) + strlen ( V_26 ) + 2 ) ;
if ( ! V_51 ) {
fprintf ( V_41 , L_42 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_51 , L_4 , V_71 , V_26 ) ;
if ( V_9 < 0 )
goto V_75;
V_21 = fopen ( V_51 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
goto V_75;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_43 , & V_9 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_44 ) ;
goto V_75;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_75:
free ( V_51 ) ;
return V_9 ;
}
int F_23 ( const char * V_26 , const char * V_71 , float * V_72 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_51 = malloc ( strlen ( V_71 ) + strlen ( V_26 ) + 2 ) ;
if ( ! V_51 ) {
fprintf ( V_41 , L_42 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_51 , L_4 , V_71 , V_26 ) ;
if ( V_9 < 0 )
goto V_75;
V_21 = fopen ( V_51 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
goto V_75;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_45 , V_72 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_46 ) ;
goto V_75;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_75:
free ( V_51 ) ;
return V_9 ;
}
int F_24 ( const char * V_26 , const char * V_71 , char * V_76 )
{
int V_9 = 0 ;
T_2 * V_21 ;
char * V_51 = malloc ( strlen ( V_71 ) + strlen ( V_26 ) + 2 ) ;
if ( ! V_51 ) {
fprintf ( V_41 , L_42 ) ;
return - V_11 ;
}
V_9 = sprintf ( V_51 , L_4 , V_71 , V_26 ) ;
if ( V_9 < 0 )
goto V_75;
V_21 = fopen ( V_51 , L_5 ) ;
if ( ! V_21 ) {
V_9 = - V_36 ;
goto V_75;
}
V_36 = 0 ;
if ( fscanf ( V_21 , L_47 , V_76 ) != 1 ) {
V_9 = V_36 ? - V_36 : - V_47 ;
if ( fclose ( V_21 ) )
perror ( L_48 ) ;
goto V_75;
}
if ( fclose ( V_21 ) )
V_9 = - V_36 ;
V_75:
free ( V_51 ) ;
return V_9 ;
}
