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
else
return - 1 ;
V_3 . V_9 = true ;
return 0 ;
}
static int
F_4 ( const char * V_10 , const char * V_11 ,
char * V_12 )
{
char * V_13 , * V_14 , * V_15 = NULL ;
char V_16 [ V_17 ] ;
int V_18 ;
V_12 [ 0 ] = '\0' ;
if ( V_10 && V_10 [ 0 ] != '\0' ) {
if ( V_10 [ 0 ] == '/' ) {
if ( F_5 ( V_10 , V_19 ) == 0 ) {
F_6 ( V_12 , V_10 , V_17 ) ;
return 0 ;
}
} else if ( V_10 [ 0 ] != '\0' )
V_11 = V_10 ;
}
V_13 = getenv ( L_7 ) ;
if ( ! V_13 )
return - 1 ;
V_13 = F_3 ( V_13 ) ;
if ( ! V_13 )
return - 1 ;
V_18 = - V_20 ;
V_14 = strtok_r ( V_13 , L_8 , & V_15 ) ;
while ( V_14 ) {
F_7 ( V_16 , sizeof( V_16 ) , L_9 , V_14 , V_11 ) ;
if ( F_5 ( V_16 , V_19 ) == 0 ) {
F_6 ( V_12 , V_16 , V_17 ) ;
V_18 = 0 ;
break;
}
V_14 = strtok_r ( NULL , L_8 , & V_15 ) ;
}
free ( V_13 ) ;
return V_18 ;
}
static int
F_8 ( const char * V_21 , void * * V_22 , T_1 * V_23 )
{
int V_24 = 0 ;
void * V_16 = NULL ;
T_2 * V_25 = NULL ;
T_1 V_26 = 0 , V_27 = 0 ;
V_25 = F_9 ( V_21 , L_10 ) ;
if ( ! V_25 ) {
F_10 ( L_11 ,
strerror ( V_28 ) ) ;
return - V_29 ;
}
while ( ! feof ( V_25 ) && ! ferror ( V_25 ) ) {
if ( V_27 - V_26 < V_30 + 1 ) {
void * V_31 ;
V_27 = V_26 + V_30 + 1 ;
V_31 = realloc ( V_16 , V_27 ) ;
if ( ! V_31 ) {
F_10 ( L_12 ) ;
V_24 = - V_32 ;
goto V_33;
}
V_16 = V_31 ;
}
V_26 += fread ( V_16 + V_26 , 1 , V_30 , V_25 ) ;
}
if ( V_27 - V_26 < 1 ) {
F_10 ( L_13 ) ;
V_24 = - V_29 ;
goto V_33;
}
if ( ferror ( V_25 ) ) {
F_10 ( L_14 ,
strerror ( V_28 ) ) ;
V_24 = - V_34 ;
goto V_33;
}
V_24 = F_11 ( F_12 ( V_25 ) ) ;
V_25 = NULL ;
if ( V_24 ) {
V_24 = - V_29 ;
goto V_33;
}
( ( char * ) V_16 ) [ V_26 ] = '\0' ;
if ( ! V_22 )
free ( V_16 ) ;
else
* V_22 = V_16 ;
if ( V_23 )
* V_23 = V_26 ;
return 0 ;
V_33:
if ( V_25 )
F_12 ( V_25 ) ;
free ( V_16 ) ;
if ( V_22 )
* V_22 = NULL ;
if ( V_23 )
* V_23 = 0 ;
return V_24 ;
}
static inline void
F_13 ( const char * V_1 , const char * V_2 )
{
if ( V_2 ) {
F_14 ( V_1 , V_2 , 1 ) ;
F_15 ( L_15 , V_1 , V_2 ) ;
} else {
F_16 ( V_1 ) ;
F_15 ( L_16 , V_1 ) ;
}
}
static void
F_17 ( void )
{
F_10 (
L_17
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
) ;
}
static int F_18 ( char * * V_7 )
{
const char * V_35 = V_3 . V_7 ;
const char * V_36 = L_31 ;
const char * V_37 = L_31 ;
char * V_38 ;
struct V_39 V_39 ;
int V_24 ;
if ( ! V_35 ) {
V_24 = F_19 ( & V_39 ) ;
if ( V_24 ) {
F_20 ( L_32 , strerror ( V_28 ) ) ;
return - V_29 ;
}
V_35 = V_39 . V_40 ;
V_36 = L_33 ;
V_37 = L_34 ;
}
V_24 = F_21 ( & V_38 , L_35 ,
V_36 , V_35 , V_37 ) ;
if ( V_24 < 0 )
return - V_32 ;
if ( F_5 ( V_38 , V_41 ) == 0 ) {
free ( V_38 ) ;
V_24 = F_21 ( V_7 , L_36 , V_36 , V_35 ,
V_37 ) ;
if ( V_24 < 0 )
return - V_32 ;
return 0 ;
}
free ( V_38 ) ;
return - V_20 ;
}
static inline void
F_22 ( char * * V_7 , char * * V_42 )
{
int V_24 ;
if ( ! V_7 || ! V_42 )
return;
* V_7 = NULL ;
* V_42 = NULL ;
if ( V_3 . V_7 && ! V_3 . V_7 [ 0 ] ) {
F_15 ( L_37 ) ;
F_15 ( L_38 ) ;
return;
}
V_24 = F_18 ( V_7 ) ;
if ( V_24 ) {
F_20 (
L_39
L_40
L_41
L_42 ) ;
return;
}
F_15 ( L_43 , * V_7 ) ;
F_13 ( L_44 , * V_7 ) ;
F_13 ( L_45 , V_3 . V_8 ) ;
V_24 = F_8 ( V_43 ,
( void * * ) V_42 ,
NULL ) ;
if ( V_24 ) {
F_20 (
L_46
L_47
L_48
L_49 ,
* V_7 ) ;
free ( * V_7 ) ;
* V_7 = NULL ;
return;
}
F_15 ( L_50 , * V_42 ) ;
}
int F_23 ( const char * V_14 , void * * V_44 ,
T_1 * V_45 )
{
int V_24 ;
char V_4 [ V_17 ] ;
const char * V_6 = V_3 . V_6 ;
const char * V_46 = V_3 . V_5 ;
char * V_7 = NULL , * V_42 = NULL ;
void * V_47 = NULL ;
T_1 V_48 ;
if ( ! V_46 )
V_46 = V_49 ;
V_24 = F_4 ( V_3 . V_4 ,
L_51 , V_4 ) ;
if ( V_24 ) {
F_10 (
L_52
L_53
L_54 ) ;
F_17 () ;
return - V_20 ;
}
F_22 ( & V_7 , & V_42 ) ;
F_13 ( L_55 , V_4 ) ;
F_13 ( L_56 , V_6 ) ;
F_13 ( L_57 , V_42 ) ;
F_13 ( L_58 , V_7 ? : L_59 ) ;
F_13 ( L_60 ,
( V_14 [ 0 ] == '-' ) ? V_14 :
F_24 ( V_14 ) ) ;
F_15 ( L_61 , V_46 ) ;
V_24 = F_8 ( V_46 , & V_47 , & V_48 ) ;
if ( V_24 ) {
F_10 ( L_62 , V_14 ) ;
F_10 ( L_63 ) ;
F_10 ( L_64 ) ;
F_10 ( L_65 , V_14 ) ;
F_10 ( L_66 ) ;
goto V_33;
}
free ( V_7 ) ;
free ( V_42 ) ;
if ( ! V_44 )
free ( V_47 ) ;
else
* V_44 = V_47 ;
if ( V_45 )
* V_45 = V_48 ;
return 0 ;
V_33:
free ( V_7 ) ;
free ( V_42 ) ;
free ( V_47 ) ;
if ( V_44 )
* V_44 = NULL ;
if ( V_45 )
* V_45 = 0 ;
return V_24 ;
}
int F_25 ( void )
{
char V_4 [ V_17 ] ;
return F_4 ( V_3 . V_4 , L_51 , V_4 ) ;
}
