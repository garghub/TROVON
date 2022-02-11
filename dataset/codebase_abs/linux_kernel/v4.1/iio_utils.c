int F_1 ( const char * V_1 ,
char * * V_2 )
{
char * V_3 ;
char * V_4 , * V_5 ;
char * V_6 , * V_7 = L_1 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < sizeof( V_9 ) / sizeof( V_9 [ 0 ] ) ; V_8 ++ )
if ( ! strncmp ( V_1 , V_9 [ V_8 ] ,
strlen ( V_9 [ V_8 ] ) ) ) {
V_7 = V_9 [ V_8 ] ;
break;
}
V_3 = F_2 ( V_1 + strlen ( V_7 ) + 1 ) ;
V_6 = strtok ( V_3 , L_2 ) ;
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
F_3 ( V_2 , L_3 , V_7 , V_6 ) ;
free ( V_3 ) ;
return 0 ;
}
int F_4 ( unsigned * V_10 ,
unsigned * V_11 ,
unsigned * V_12 ,
unsigned * V_13 ,
T_1 * V_14 ,
unsigned * V_15 ,
const char * V_16 ,
const char * V_17 ,
const char * V_2 )
{
T_2 * V_18 ;
int V_19 ;
T_3 * V_20 ;
char * V_21 , * V_22 , * V_23 , * V_24 = 0 ;
char V_25 , V_26 ;
unsigned V_27 ;
const struct V_28 * V_29 ;
V_19 = F_3 ( & V_21 , V_30 , V_16 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_32;
}
V_19 = F_3 ( & V_22 , V_33 , V_17 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_34;
}
V_19 = F_3 ( & V_23 , V_33 , V_2 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_35;
}
V_20 = F_5 ( V_21 ) ;
if ( V_20 == NULL ) {
V_19 = - V_36 ;
goto V_37;
}
while ( V_29 = F_6 ( V_20 ) , V_29 != NULL )
if ( ( strcmp ( V_22 , V_29 -> V_38 ) == 0 ) ||
( strcmp ( V_23 , V_29 -> V_38 ) == 0 ) ) {
V_19 = F_3 ( & V_24 ,
L_4 , V_21 , V_29 -> V_38 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_39;
}
V_18 = fopen ( V_24 , L_5 ) ;
if ( V_18 == NULL ) {
printf ( L_6 , V_24 ) ;
V_19 = - V_36 ;
goto V_40;
}
V_19 = fscanf ( V_18 ,
L_7 ,
& V_26 ,
& V_25 ,
V_12 ,
& V_27 , V_13 ) ;
if ( V_19 < 0 ) {
printf ( L_8 ) ;
V_19 = - V_36 ;
goto V_41;
}
* V_15 = ( V_26 == 'b' ) ;
* V_11 = V_27 / 8 ;
if ( * V_12 == 64 )
* V_14 = ~ 0 ;
else
* V_14 = ( 1 << * V_12 ) - 1 ;
if ( V_25 == 's' )
* V_10 = 1 ;
else
* V_10 = 0 ;
fclose ( V_18 ) ;
free ( V_24 ) ;
V_24 = 0 ;
V_18 = 0 ;
}
V_41:
if ( V_18 )
fclose ( V_18 ) ;
V_40:
if ( V_24 )
free ( V_24 ) ;
V_39:
F_7 ( V_20 ) ;
V_37:
free ( V_23 ) ;
V_35:
free ( V_22 ) ;
V_34:
free ( V_21 ) ;
V_32:
return V_19 ;
}
int F_8 ( float * V_42 ,
const char * V_43 ,
const char * V_16 ,
const char * V_17 ,
const char * V_2 )
{
T_2 * V_18 ;
int V_19 ;
T_3 * V_20 ;
char * V_22 , * V_23 ;
char * V_24 = NULL ;
const struct V_28 * V_29 ;
V_19 = F_3 ( & V_22 , L_3 , V_17 , V_43 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_32;
}
V_19 = F_3 ( & V_23 ,
L_3 , V_2 , V_43 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_35;
}
V_20 = F_5 ( V_16 ) ;
if ( V_20 == NULL ) {
V_19 = - V_36 ;
goto V_37;
}
while ( V_29 = F_6 ( V_20 ) , V_29 != NULL )
if ( ( strcmp ( V_22 , V_29 -> V_38 ) == 0 ) ||
( strcmp ( V_23 , V_29 -> V_38 ) == 0 ) ) {
V_19 = F_3 ( & V_24 ,
L_4 , V_16 , V_29 -> V_38 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_39;
}
V_18 = fopen ( V_24 , L_5 ) ;
if ( ! V_18 ) {
V_19 = - V_36 ;
goto V_40;
}
fscanf ( V_18 , L_9 , V_42 ) ;
break;
}
V_40:
if ( V_24 )
free ( V_24 ) ;
V_39:
F_7 ( V_20 ) ;
V_37:
free ( V_23 ) ;
V_35:
free ( V_22 ) ;
V_32:
return V_19 ;
}
void F_9 ( struct V_44 * * V_45 ,
int V_46 )
{
struct V_44 V_47 ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ )
for ( V_49 = 0 ; V_49 < ( V_46 - 1 ) ; V_49 ++ )
if ( ( * V_45 ) [ V_49 ] . V_50 > ( * V_45 ) [ V_49 + 1 ] . V_50 ) {
V_47 = ( * V_45 ) [ V_49 + 1 ] ;
( * V_45 ) [ V_49 + 1 ] = ( * V_45 ) [ V_49 ] ;
( * V_45 ) [ V_49 ] = V_47 ;
}
}
int F_10 ( const char * V_16 ,
struct V_44 * * V_45 ,
int * V_51 )
{
T_3 * V_20 ;
T_2 * V_18 ;
int V_52 , V_8 ;
struct V_44 * V_3 ;
int V_19 ;
const struct V_28 * V_29 ;
char * V_21 ;
char * V_24 ;
* V_51 = 0 ;
V_19 = F_3 ( & V_21 , V_30 , V_16 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_32;
}
V_20 = F_5 ( V_21 ) ;
if ( V_20 == NULL ) {
V_19 = - V_36 ;
goto V_53;
}
while ( V_29 = F_6 ( V_20 ) , V_29 != NULL )
if ( strcmp ( V_29 -> V_38 + strlen ( V_29 -> V_38 ) - strlen ( L_10 ) ,
L_10 ) == 0 ) {
V_19 = F_3 ( & V_24 ,
L_4 , V_21 , V_29 -> V_38 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
goto V_54;
}
V_18 = fopen ( V_24 , L_5 ) ;
if ( V_18 == NULL ) {
V_19 = - V_36 ;
free ( V_24 ) ;
goto V_54;
}
fscanf ( V_18 , L_11 , & V_19 ) ;
if ( V_19 == 1 )
( * V_51 ) ++ ;
fclose ( V_18 ) ;
free ( V_24 ) ;
}
* V_45 = malloc ( sizeof( * * V_45 ) * ( * V_51 ) ) ;
if ( * V_45 == NULL ) {
V_19 = - V_31 ;
goto V_54;
}
F_11 ( V_20 , 0 ) ;
V_52 = 0 ;
while ( V_29 = F_6 ( V_20 ) , V_29 != NULL ) {
if ( strcmp ( V_29 -> V_38 + strlen ( V_29 -> V_38 ) - strlen ( L_10 ) ,
L_10 ) == 0 ) {
int V_55 = 0 ;
V_3 = & ( * V_45 ) [ V_52 ++ ] ;
V_19 = F_3 ( & V_24 ,
L_4 , V_21 , V_29 -> V_38 ) ;
if ( V_19 < 0 ) {
V_19 = - V_31 ;
V_52 -- ;
goto V_56;
}
V_18 = fopen ( V_24 , L_5 ) ;
if ( V_18 == NULL ) {
free ( V_24 ) ;
V_19 = - V_36 ;
goto V_56;
}
fscanf ( V_18 , L_11 , & V_55 ) ;
fclose ( V_18 ) ;
if ( ! V_55 ) {
free ( V_24 ) ;
V_52 -- ;
continue;
}
V_3 -> V_57 = 1.0 ;
V_3 -> V_58 = 0 ;
V_3 -> V_17 = F_12 ( V_29 -> V_38 ,
strlen ( V_29 -> V_38 ) -
strlen ( L_10 ) ) ;
if ( V_3 -> V_17 == NULL ) {
free ( V_24 ) ;
V_19 = - V_31 ;
goto V_56;
}
V_19 = F_1 ( V_3 -> V_17 ,
& V_3 -> V_2 ) ;
if ( V_19 ) {
free ( V_24 ) ;
goto V_56;
}
V_19 = F_3 ( & V_24 ,
L_12 ,
V_21 ,
V_3 -> V_17 ) ;
if ( V_19 < 0 ) {
free ( V_24 ) ;
V_19 = - V_31 ;
goto V_56;
}
V_18 = fopen ( V_24 , L_5 ) ;
fscanf ( V_18 , L_13 , & V_3 -> V_50 ) ;
fclose ( V_18 ) ;
free ( V_24 ) ;
V_19 = F_8 ( & V_3 -> V_57 ,
L_14 ,
V_16 ,
V_3 -> V_17 ,
V_3 -> V_2 ) ;
if ( V_19 < 0 )
goto V_56;
V_19 = F_8 ( & V_3 -> V_58 ,
L_15 ,
V_16 ,
V_3 -> V_17 ,
V_3 -> V_2 ) ;
if ( V_19 < 0 )
goto V_56;
V_19 = F_4 ( & V_3 -> V_10 ,
& V_3 -> V_11 ,
& V_3 -> V_12 ,
& V_3 -> V_13 ,
& V_3 -> V_14 ,
& V_3 -> V_15 ,
V_16 ,
V_3 -> V_17 ,
V_3 -> V_2 ) ;
}
}
F_7 ( V_20 ) ;
F_9 ( V_45 , * V_51 ) ;
return 0 ;
V_56:
for ( V_8 = V_52 - 1 ; V_8 >= 0 ; V_8 -- )
free ( ( * V_45 ) [ V_8 ] . V_17 ) ;
free ( * V_45 ) ;
V_54:
F_7 ( V_20 ) ;
V_53:
free ( V_21 ) ;
V_32:
return V_19 ;
}
int F_13 ( const char * V_17 , const char * type )
{
const struct V_28 * V_29 ;
int V_59 , V_60 ;
T_2 * V_61 ;
T_3 * V_20 ;
char V_62 [ V_63 ] ;
char * V_24 ;
V_20 = F_5 ( V_64 ) ;
if ( V_20 == NULL ) {
printf ( L_16 ) ;
return - V_65 ;
}
while ( V_29 = F_6 ( V_20 ) , V_29 != NULL ) {
if ( strcmp ( V_29 -> V_38 , L_17 ) != 0 &&
strcmp ( V_29 -> V_38 , L_18 ) != 0 &&
strlen ( V_29 -> V_38 ) > strlen ( type ) &&
strncmp ( V_29 -> V_38 , type , strlen ( type ) ) == 0 ) {
V_60 = sscanf ( V_29 -> V_38 + strlen ( type ) ,
L_19 ,
& V_59 ) ;
if ( strncmp ( V_29 -> V_38 + strlen ( type ) + V_60 ,
L_20 ,
1 ) != 0 ) {
V_24 = malloc ( strlen ( V_64 )
+ strlen ( type )
+ V_60
+ 6 ) ;
if ( V_24 == NULL ) {
F_7 ( V_20 ) ;
return - V_31 ;
}
sprintf ( V_24 , L_21 ,
V_64 ,
type ,
V_59 ) ;
V_61 = fopen ( V_24 , L_5 ) ;
if ( ! V_61 ) {
free ( V_24 ) ;
continue;
}
free ( V_24 ) ;
fscanf ( V_61 , L_22 , V_62 ) ;
fclose ( V_61 ) ;
if ( strcmp ( V_17 , V_62 ) == 0 ) {
F_7 ( V_20 ) ;
return V_59 ;
}
}
}
}
F_7 ( V_20 ) ;
return - V_65 ;
}
int F_14 ( char * V_24 , char * V_66 , int V_67 , int V_68 )
{
int V_19 = 0 ;
T_2 * V_18 ;
int V_69 ;
char * V_47 = malloc ( strlen ( V_66 ) + strlen ( V_24 ) + 2 ) ;
if ( V_47 == NULL )
return - V_31 ;
sprintf ( V_47 , L_4 , V_66 , V_24 ) ;
V_18 = fopen ( V_47 , L_23 ) ;
if ( V_18 == NULL ) {
printf ( L_6 , V_47 ) ;
V_19 = - V_36 ;
goto V_70;
}
fprintf ( V_18 , L_19 , V_67 ) ;
fclose ( V_18 ) ;
if ( V_68 ) {
V_18 = fopen ( V_47 , L_5 ) ;
if ( V_18 == NULL ) {
printf ( L_6 , V_47 ) ;
V_19 = - V_36 ;
goto V_70;
}
fscanf ( V_18 , L_19 , & V_69 ) ;
fclose ( V_18 ) ;
if ( V_69 != V_67 ) {
printf ( L_24 ,
V_67 ,
V_66 ,
V_24 ) ;
V_19 = - 1 ;
}
}
V_70:
free ( V_47 ) ;
return V_19 ;
}
int F_15 ( char * V_24 , char * V_66 , int V_67 )
{
return F_14 ( V_24 , V_66 , V_67 , 0 ) ;
}
int F_16 ( char * V_24 , char * V_66 , int V_67 )
{
return F_14 ( V_24 , V_66 , V_67 , 1 ) ;
}
int F_17 ( char * V_24 , char * V_66 , char * V_67 , int V_68 )
{
int V_19 = 0 ;
T_2 * V_18 ;
char * V_47 = malloc ( strlen ( V_66 ) + strlen ( V_24 ) + 2 ) ;
if ( V_47 == NULL ) {
printf ( L_25 ) ;
return - V_31 ;
}
sprintf ( V_47 , L_4 , V_66 , V_24 ) ;
V_18 = fopen ( V_47 , L_23 ) ;
if ( V_18 == NULL ) {
printf ( L_26 , V_47 ) ;
V_19 = - V_36 ;
goto V_70;
}
fprintf ( V_18 , L_22 , V_67 ) ;
fclose ( V_18 ) ;
if ( V_68 ) {
V_18 = fopen ( V_47 , L_5 ) ;
if ( V_18 == NULL ) {
printf ( L_27 ) ;
V_19 = - V_36 ;
goto V_70;
}
fscanf ( V_18 , L_22 , V_47 ) ;
fclose ( V_18 ) ;
if ( strcmp ( V_47 , V_67 ) != 0 ) {
printf ( L_28
L_29
L_30 ,
V_47 ,
V_67 ,
V_66 ,
V_24 ) ;
V_19 = - 1 ;
}
}
V_70:
free ( V_47 ) ;
return V_19 ;
}
int F_18 ( char * V_24 , char * V_66 , char * V_67 )
{
return F_17 ( V_24 , V_66 , V_67 , 1 ) ;
}
int F_19 ( char * V_24 , char * V_66 , char * V_67 )
{
return F_17 ( V_24 , V_66 , V_67 , 0 ) ;
}
int F_20 ( char * V_24 , char * V_66 )
{
int V_19 ;
T_2 * V_18 ;
char * V_47 = malloc ( strlen ( V_66 ) + strlen ( V_24 ) + 2 ) ;
if ( V_47 == NULL ) {
printf ( L_31 ) ;
return - V_31 ;
}
sprintf ( V_47 , L_4 , V_66 , V_24 ) ;
V_18 = fopen ( V_47 , L_5 ) ;
if ( V_18 == NULL ) {
V_19 = - V_36 ;
goto V_70;
}
fscanf ( V_18 , L_32 , & V_19 ) ;
fclose ( V_18 ) ;
V_70:
free ( V_47 ) ;
return V_19 ;
}
int F_21 ( char * V_24 , char * V_66 , float * V_67 )
{
int V_19 = 0 ;
T_2 * V_18 ;
char * V_47 = malloc ( strlen ( V_66 ) + strlen ( V_24 ) + 2 ) ;
if ( V_47 == NULL ) {
printf ( L_31 ) ;
return - V_31 ;
}
sprintf ( V_47 , L_4 , V_66 , V_24 ) ;
V_18 = fopen ( V_47 , L_5 ) ;
if ( V_18 == NULL ) {
V_19 = - V_36 ;
goto V_70;
}
fscanf ( V_18 , L_33 , V_67 ) ;
fclose ( V_18 ) ;
V_70:
free ( V_47 ) ;
return V_19 ;
}
int F_22 ( const char * V_24 , const char * V_66 , char * V_71 )
{
int V_19 = 0 ;
T_2 * V_18 ;
char * V_47 = malloc ( strlen ( V_66 ) + strlen ( V_24 ) + 2 ) ;
if ( V_47 == NULL ) {
printf ( L_31 ) ;
return - V_31 ;
}
sprintf ( V_47 , L_4 , V_66 , V_24 ) ;
V_18 = fopen ( V_47 , L_5 ) ;
if ( V_18 == NULL ) {
V_19 = - V_36 ;
goto V_70;
}
fscanf ( V_18 , L_34 , V_71 ) ;
fclose ( V_18 ) ;
V_70:
free ( V_47 ) ;
return V_19 ;
}
