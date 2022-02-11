static void F_1 ( int T_1 V_1 )
{
V_2 = true ;
}
static void F_2 ( int T_2 V_1 ,
T_3 * T_4 V_1 ,
void * T_5 V_1 )
{
V_2 = true ;
}
static int F_3 ( const char * V_3 , const char * V_4 , bool V_5 )
{
char * V_6 ;
int V_7 , V_8 = - 1 ;
T_6 V_9 = strlen ( V_4 ) ;
int V_10 = V_11 ;
V_6 = F_4 ( V_3 ) ;
if ( ! V_6 ) {
F_5 ( L_1 , V_3 ) ;
return - 1 ;
}
if ( V_5 )
V_10 |= V_12 ;
else
V_10 |= V_13 ;
V_7 = F_6 ( V_6 , V_10 ) ;
if ( V_7 < 0 ) {
F_5 ( L_2 , V_3 ) ;
goto V_14;
}
if ( F_7 ( V_7 , V_4 , V_9 ) == V_9 )
V_8 = 0 ;
else
F_5 ( L_3 , V_4 , V_3 ) ;
F_8 ( V_7 ) ;
V_14:
F_9 ( V_6 ) ;
return V_8 ;
}
static int F_10 ( const char * V_3 , const char * V_4 )
{
return F_3 ( V_3 , V_4 , false ) ;
}
static int F_11 ( const char * V_3 , const char * V_4 )
{
return F_3 ( V_3 , V_4 , true ) ;
}
static int F_12 ( struct V_15 * T_7 V_1 )
{
if ( F_10 ( L_4 , L_5 ) < 0 )
return - 1 ;
if ( F_10 ( L_6 , L_7 ) < 0 )
return - 1 ;
if ( F_10 ( L_8 , L_9 ) < 0 )
return - 1 ;
if ( F_13 () < 0 )
return - 1 ;
return 0 ;
}
static int F_14 ( struct V_15 * T_7 )
{
int V_16 ;
char V_17 [ 16 ] ;
if ( F_15 ( & T_7 -> V_18 ) )
return 0 ;
for ( V_16 = 0 ; V_16 < F_16 ( T_7 -> V_19 -> V_20 ) ; V_16 ++ ) {
F_17 ( V_17 , sizeof( V_17 ) , L_10 ,
T_7 -> V_19 -> V_20 -> V_21 [ V_16 ] ) ;
if ( F_11 ( L_8 , V_17 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
char * V_24 ;
T_8 V_25 ;
int V_8 ;
int V_26 ;
V_26 = F_19 ( V_23 , V_23 -> V_27 - 1 ) ;
V_25 = ( V_26 + 3 ) / 4 + 1 ;
V_25 += V_26 / 32 ;
V_24 = malloc ( V_25 ) ;
if ( V_24 == NULL ) {
F_5 ( L_11 ) ;
return - 1 ;
}
F_20 ( V_23 , V_24 , V_25 ) ;
V_8 = F_10 ( L_12 , V_24 ) ;
free ( V_24 ) ;
return V_8 ;
}
static int F_21 ( struct V_15 * T_7 )
{
struct V_22 * V_23 = T_7 -> V_19 -> V_28 ;
if ( ! F_15 ( & T_7 -> V_18 ) )
return 0 ;
return F_18 ( V_23 ) ;
}
static int F_13 ( void )
{
struct V_22 * V_23 = F_22 ( NULL ) ;
int V_8 ;
V_8 = F_18 ( V_23 ) ;
F_23 ( V_23 ) ;
return V_8 ;
}
static int F_24 ( struct V_15 * T_7 , int V_29 , const char * * V_30 )
{
char * V_31 ;
int V_32 ;
char V_17 [ 4096 ] ;
struct V_33 V_33 = {
. V_34 = V_35 ,
} ;
if ( F_25 () != 0 ) {
F_26 ( L_13 ) ;
return - 1 ;
}
signal ( V_36 , F_1 ) ;
signal ( V_37 , F_1 ) ;
signal ( V_38 , F_1 ) ;
signal ( V_39 , F_1 ) ;
if ( F_12 ( T_7 ) < 0 )
goto V_14;
if ( F_10 ( L_14 , L_5 ) < 0 )
goto V_14;
if ( V_29 && F_27 ( T_7 -> V_19 ,
& T_7 -> V_18 , V_30 , false ,
F_2 ) < 0 ) {
goto V_14;
}
if ( F_14 ( T_7 ) < 0 ) {
F_26 ( L_15 ) ;
goto V_40;
}
if ( F_21 ( T_7 ) < 0 ) {
F_26 ( L_16 ) ;
goto V_40;
}
if ( F_10 ( L_6 , T_7 -> V_41 ) < 0 ) {
F_26 ( L_17 , T_7 -> V_41 ) ;
goto V_40;
}
V_31 = F_4 ( L_18 ) ;
if ( ! V_31 ) {
F_26 ( L_19 ) ;
goto V_40;
}
V_32 = F_6 ( V_31 , V_42 ) ;
F_9 ( V_31 ) ;
if ( V_32 < 0 ) {
F_26 ( L_19 ) ;
goto V_40;
}
F_28 ( V_32 , V_43 , V_44 ) ;
V_33 . V_7 = V_32 ;
if ( F_10 ( L_4 , L_20 ) < 0 ) {
F_26 ( L_21 ) ;
goto V_45;
}
F_29 () ;
F_30 ( T_7 -> V_19 ) ;
while ( ! V_2 ) {
if ( F_31 ( & V_33 , 1 , - 1 ) < 0 )
break;
if ( V_33 . V_46 & V_35 ) {
int V_47 = F_32 ( V_32 , V_17 , sizeof( V_17 ) ) ;
if ( V_47 < 0 )
break;
if ( fwrite ( V_17 , V_47 , 1 , stdout ) != 1 )
break;
}
}
F_10 ( L_4 , L_5 ) ;
while ( true ) {
int V_47 = F_32 ( V_32 , V_17 , sizeof( V_17 ) ) ;
if ( V_47 <= 0 )
break;
if ( fwrite ( V_17 , V_47 , 1 , stdout ) != 1 )
break;
}
V_45:
F_8 ( V_32 ) ;
V_40:
F_12 ( T_7 ) ;
V_14:
return V_2 ? 0 : - 1 ;
}
static int F_33 ( const char * V_48 , const char * V_49 , void * V_50 )
{
struct V_15 * T_7 = V_50 ;
if ( F_34 ( V_48 , L_22 ) )
return 0 ;
if ( strcmp ( V_48 , L_23 ) )
return - 1 ;
if ( ! strcmp ( V_49 , L_24 ) ||
! strcmp ( V_49 , L_25 ) ) {
T_7 -> V_41 = V_49 ;
return 0 ;
}
F_26 ( L_26 ) ;
return - 1 ;
}
int F_35 ( int V_29 , const char * * V_30 )
{
int V_8 ;
struct V_15 T_7 = {
. V_41 = V_51 ,
. V_18 = { . V_52 = V_53 , } ,
} ;
const char * const V_54 [] = {
L_27 ,
L_28 ,
NULL
} ;
const struct V_55 V_56 [] = {
F_36 ( 't' , L_29 , & T_7 . V_41 , L_29 ,
L_30 ) ,
F_36 ( 'p' , L_31 , & T_7 . V_18 . V_57 , L_31 ,
L_32 ) ,
F_37 ( 'v' , L_33 , & V_58 ,
L_34 ) ,
F_38 ( 'a' , L_35 , & T_7 . V_18 . V_59 ,
L_36 ) ,
F_36 ( 'C' , L_37 , & T_7 . V_18 . V_60 , L_37 ,
L_38 ) ,
F_39 ()
} ;
V_8 = F_40 ( F_33 , & T_7 ) ;
if ( V_8 < 0 )
return - 1 ;
V_29 = F_41 ( V_29 , V_30 , V_56 , V_54 ,
V_61 ) ;
if ( ! V_29 && F_42 ( & T_7 . V_18 ) )
F_43 ( V_54 , V_56 ) ;
V_8 = F_44 ( & T_7 . V_18 ) ;
if ( V_8 ) {
char V_62 [ 512 ] ;
F_45 ( & T_7 . V_18 , V_8 , V_62 , 512 ) ;
F_26 ( L_39 , V_62 ) ;
return - V_63 ;
}
T_7 . V_19 = F_46 () ;
if ( T_7 . V_19 == NULL )
return - V_64 ;
V_8 = F_47 ( T_7 . V_19 , & T_7 . V_18 ) ;
if ( V_8 < 0 )
goto V_65;
V_8 = F_24 ( & T_7 , V_29 , V_30 ) ;
V_65:
F_48 ( T_7 . V_19 ) ;
return V_8 ;
}
