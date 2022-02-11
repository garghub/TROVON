int F_1 ( const char * V_1 , const char * V_2 )
{
if ( F_2 ( V_1 , L_1 ) )
return 0 ;
V_1 += sizeof( L_1 ) - 1 ;
if ( ! strcmp ( V_1 , L_2 ) )
V_3 . V_4 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_3 ) )
V_3 . V_5 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_4 ) )
V_3 . V_6 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_5 ) )
V_3 . V_7 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_6 ) )
V_3 . V_8 = F_3 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_7 ) )
V_3 . V_9 = ! ! F_4 ( V_1 , V_2 ) ;
else
return - 1 ;
V_3 . V_10 = true ;
return 0 ;
}
static int
F_5 ( const char * V_11 , const char * V_12 ,
char * V_13 )
{
char * V_14 , * V_15 , * V_16 = NULL ;
char V_17 [ V_18 ] ;
int V_19 ;
V_13 [ 0 ] = '\0' ;
if ( V_11 && V_11 [ 0 ] != '\0' ) {
if ( V_11 [ 0 ] == '/' ) {
if ( F_6 ( V_11 , V_20 ) == 0 ) {
F_7 ( V_13 , V_11 , V_18 ) ;
return 0 ;
}
} else if ( V_11 [ 0 ] != '\0' )
V_12 = V_11 ;
}
V_14 = getenv ( L_8 ) ;
if ( ! V_14 )
return - 1 ;
V_14 = F_3 ( V_14 ) ;
if ( ! V_14 )
return - 1 ;
V_19 = - V_21 ;
V_15 = strtok_r ( V_14 , L_9 , & V_16 ) ;
while ( V_15 ) {
F_8 ( V_17 , sizeof( V_17 ) , L_10 , V_15 , V_12 ) ;
if ( F_6 ( V_17 , V_20 ) == 0 ) {
F_7 ( V_13 , V_17 , V_18 ) ;
V_19 = 0 ;
break;
}
V_15 = strtok_r ( NULL , L_9 , & V_16 ) ;
}
free ( V_14 ) ;
return V_19 ;
}
static int
F_9 ( const char * V_22 , void * * V_23 , T_1 * V_24 )
{
int V_25 = 0 ;
void * V_17 = NULL ;
T_2 * V_26 = NULL ;
T_1 V_27 = 0 , V_28 = 0 ;
char V_29 [ V_30 ] ;
V_26 = F_10 ( V_22 , L_11 ) ;
if ( ! V_26 ) {
F_11 ( L_12 ,
F_12 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
return - V_32 ;
}
while ( ! feof ( V_26 ) && ! ferror ( V_26 ) ) {
if ( V_28 - V_27 < V_33 + 1 ) {
void * V_34 ;
V_28 = V_27 + V_33 + 1 ;
V_34 = realloc ( V_17 , V_28 ) ;
if ( ! V_34 ) {
F_11 ( L_13 ) ;
V_25 = - V_35 ;
goto V_36;
}
V_17 = V_34 ;
}
V_27 += fread ( V_17 + V_27 , 1 , V_33 , V_26 ) ;
}
if ( V_28 - V_27 < 1 ) {
F_11 ( L_14 ) ;
V_25 = - V_32 ;
goto V_36;
}
if ( ferror ( V_26 ) ) {
F_11 ( L_15 ,
F_12 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
V_25 = - V_37 ;
goto V_36;
}
V_25 = F_13 ( F_14 ( V_26 ) ) ;
V_26 = NULL ;
if ( V_25 ) {
V_25 = - V_32 ;
goto V_36;
}
( ( char * ) V_17 ) [ V_27 ] = '\0' ;
if ( ! V_23 )
free ( V_17 ) ;
else
* V_23 = V_17 ;
if ( V_24 )
* V_24 = V_27 ;
return 0 ;
V_36:
if ( V_26 )
F_14 ( V_26 ) ;
free ( V_17 ) ;
if ( V_23 )
* V_23 = NULL ;
if ( V_24 )
* V_24 = 0 ;
return V_25 ;
}
static inline void
F_15 ( const char * V_1 , const char * V_2 )
{
if ( V_2 ) {
F_16 ( V_1 , V_2 , 1 ) ;
F_17 ( L_16 , V_1 , V_2 ) ;
} else {
F_18 ( V_1 ) ;
F_17 ( L_17 , V_1 ) ;
}
}
static void
F_19 ( void )
{
F_11 (
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
) ;
}
static int F_20 ( char * * V_7 )
{
const char * V_38 = V_3 . V_7 ;
const char * V_39 = L_32 ;
const char * V_40 = L_32 ;
char * V_41 ;
int V_25 ;
if ( ! V_38 ) {
char V_42 [ 128 ] ;
V_25 = F_21 ( NULL , V_42 ,
sizeof( V_42 ) ) ;
if ( V_25 )
return - V_32 ;
V_38 = V_42 ;
V_39 = L_33 ;
V_40 = L_34 ;
}
V_25 = F_22 ( & V_41 , L_35 ,
V_39 , V_38 , V_40 ) ;
if ( V_25 < 0 )
return - V_35 ;
if ( F_6 ( V_41 , V_43 ) == 0 ) {
free ( V_41 ) ;
V_25 = F_22 ( V_7 , L_36 , V_39 , V_38 ,
V_40 ) ;
if ( V_25 < 0 )
return - V_35 ;
return 0 ;
}
free ( V_41 ) ;
return - V_21 ;
}
static inline void
F_23 ( char * * V_7 , char * * V_44 )
{
int V_25 ;
if ( ! V_7 || ! V_44 )
return;
* V_7 = NULL ;
* V_44 = NULL ;
if ( V_3 . V_7 && ! V_3 . V_7 [ 0 ] ) {
F_17 ( L_37 ) ;
F_17 ( L_38 ) ;
return;
}
V_25 = F_20 ( V_7 ) ;
if ( V_25 ) {
F_24 (
L_39
L_40
L_41
L_42 ) ;
return;
}
F_17 ( L_43 , * V_7 ) ;
F_15 ( L_44 , * V_7 ) ;
F_15 ( L_45 , V_3 . V_8 ) ;
V_25 = F_9 ( V_45 ,
( void * * ) V_44 ,
NULL ) ;
if ( V_25 ) {
F_24 (
L_46
L_47
L_48
L_49 ,
* V_7 ) ;
free ( * V_7 ) ;
* V_7 = NULL ;
return;
}
F_17 ( L_50 , * V_44 ) ;
}
static void
V_9 ( const char * V_15 , void * V_46 , T_1 V_47 )
{
char * V_48 = F_3 ( V_15 ) ;
T_2 * V_49 ;
char * V_50 ;
if ( ! V_48 ) {
F_24 ( L_51 ) ;
return;
}
V_50 = strrchr ( V_48 , '.' ) ;
if ( ! V_50 || ( strcmp ( V_50 , L_52 ) != 0 ) ) {
F_24 ( L_53 ,
V_48 ) ;
goto V_51;
}
V_50 [ 1 ] = 'o' ;
V_49 = fopen ( V_48 , L_54 ) ;
if ( ! V_49 ) {
F_24 ( L_55 ,
V_48 , strerror ( V_31 ) ) ;
goto V_51;
}
F_25 ( L_56 , V_48 ) ;
if ( fwrite ( V_46 , V_47 , 1 , V_49 ) != 1 )
F_24 ( L_57 ,
V_48 , strerror ( V_31 ) ) ;
fclose ( V_49 ) ;
V_51:
free ( V_48 ) ;
}
int F_26 ( const char * V_15 , void * * V_52 ,
T_1 * V_53 )
{
T_1 V_54 ;
void * V_46 = NULL ;
int V_25 , V_55 ;
unsigned int V_56 ;
char V_57 [ 64 ] ;
const char * V_6 = V_3 . V_6 ;
char V_4 [ V_18 ] , V_58 [ V_18 ] , V_59 [ 64 ] ;
char V_29 [ V_30 ] ;
char * V_7 = NULL , * V_44 = NULL ;
const char * V_60 = V_3 . V_5 ;
if ( V_15 [ 0 ] != '-' && F_27 ( V_15 , V_58 ) == NULL ) {
V_25 = V_31 ;
F_11 ( L_58 ,
V_15 , F_12 ( V_25 , V_29 , sizeof( V_29 ) ) ) ;
return - V_25 ;
}
if ( ! V_60 )
V_60 = V_61 ;
V_25 = F_5 ( V_3 . V_4 ,
L_59 , V_4 ) ;
if ( V_25 ) {
F_11 (
L_60
L_61
L_62 ) ;
F_19 () ;
return - V_21 ;
}
F_23 ( & V_7 , & V_44 ) ;
V_55 = F_28 ( V_62 ) ;
if ( V_55 <= 0 ) {
F_11 (
L_63
L_64 , F_12 ( V_31 , V_29 , sizeof( V_29 ) ) ) ;
V_55 = 128 ;
}
snprintf ( V_59 , sizeof( V_59 ) , L_65 ,
V_55 ) ;
if ( F_21 ( & V_56 , NULL , 0 ) )
V_56 = 0 ;
snprintf ( V_57 , sizeof( V_57 ) ,
L_66 , V_56 ) ;
F_15 ( L_67 , V_59 ) ;
F_15 ( L_68 , V_57 ) ;
F_15 ( L_69 , V_4 ) ;
F_15 ( L_70 , V_6 ) ;
F_15 ( L_71 , V_44 ) ;
F_15 ( L_72 , V_7 ? : L_73 ) ;
F_15 ( L_74 ,
( V_15 [ 0 ] == '-' ) ? V_15 : V_58 ) ;
F_17 ( L_75 , V_60 ) ;
V_25 = F_9 ( V_60 , & V_46 , & V_54 ) ;
if ( V_25 ) {
F_11 ( L_76 , V_15 ) ;
F_11 ( L_77 ) ;
F_11 ( L_78 ) ;
F_11 ( L_79 , V_15 ) ;
F_11 ( L_80 ) ;
goto V_36;
}
free ( V_7 ) ;
free ( V_44 ) ;
if ( V_3 . V_9 )
V_9 ( V_15 , V_46 , V_54 ) ;
if ( ! V_52 )
free ( V_46 ) ;
else
* V_52 = V_46 ;
if ( V_53 )
* V_53 = V_54 ;
return 0 ;
V_36:
free ( V_7 ) ;
free ( V_44 ) ;
free ( V_46 ) ;
if ( V_52 )
* V_52 = NULL ;
if ( V_53 )
* V_53 = 0 ;
return V_25 ;
}
int F_29 ( void )
{
char V_4 [ V_18 ] ;
return F_5 ( V_3 . V_4 , L_59 , V_4 ) ;
}
