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
static int F_3 ( const char * V_3 , const char * V_4 )
{
char * V_5 ;
int V_6 , V_7 = - 1 ;
T_6 V_8 = strlen ( V_4 ) ;
V_5 = F_4 ( V_3 ) ;
if ( ! V_5 ) {
F_5 ( L_1 , V_3 ) ;
return - 1 ;
}
V_6 = F_6 ( V_5 , V_9 ) ;
if ( V_6 < 0 ) {
F_5 ( L_2 , V_3 ) ;
goto V_10;
}
if ( F_7 ( V_6 , V_4 , V_8 ) == V_8 )
V_7 = 0 ;
else
F_5 ( L_3 , V_4 , V_3 ) ;
F_8 ( V_6 ) ;
V_10:
F_9 ( V_5 ) ;
return V_7 ;
}
static int F_10 ( struct V_11 * T_7 V_1 )
{
if ( F_3 ( L_4 , L_5 ) < 0 )
return - 1 ;
if ( F_3 ( L_6 , L_7 ) < 0 )
return - 1 ;
if ( F_3 ( L_8 , L_9 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_11 ( struct V_11 * T_7 , int V_12 , const char * * V_13 )
{
char * V_14 ;
int V_15 ;
char * V_16 ;
char V_17 [ 4096 ] ;
struct V_18 V_18 = {
. V_19 = V_20 ,
} ;
if ( F_12 () != 0 ) {
F_13 ( L_10 ) ;
return - 1 ;
}
if ( V_12 < 1 )
return - 1 ;
signal ( V_21 , F_1 ) ;
signal ( V_22 , F_1 ) ;
signal ( V_23 , F_1 ) ;
F_10 ( T_7 ) ;
if ( F_3 ( L_11 , L_5 ) < 0 )
goto V_10;
if ( F_14 ( T_7 -> V_24 , & T_7 -> V_25 ,
V_13 , false , F_2 ) < 0 )
goto V_10;
if ( F_3 ( L_6 , T_7 -> V_26 ) < 0 ) {
F_13 ( L_12 , T_7 -> V_26 ) ;
goto V_10;
}
if ( F_15 ( & V_16 , L_13 , F_16 ( T_7 -> V_24 -> V_27 , 0 ) ) < 0 ) {
F_13 ( L_14 ) ;
goto V_10;
}
if ( F_3 ( L_8 , V_16 ) < 0 ) {
F_13 ( L_15 , V_16 ) ;
goto V_28;
}
V_14 = F_4 ( L_16 ) ;
if ( ! V_14 ) {
F_13 ( L_17 ) ;
goto V_28;
}
V_15 = F_6 ( V_14 , V_29 ) ;
F_9 ( V_14 ) ;
if ( V_15 < 0 ) {
F_13 ( L_17 ) ;
goto V_28;
}
F_17 ( V_15 , V_30 , V_31 ) ;
V_18 . V_6 = V_15 ;
if ( F_3 ( L_4 , L_18 ) < 0 ) {
F_13 ( L_19 ) ;
goto V_32;
}
F_18 ( T_7 -> V_24 ) ;
while ( ! V_2 ) {
if ( F_19 ( & V_18 , 1 , - 1 ) < 0 )
break;
if ( V_18 . V_33 & V_20 ) {
int V_34 = F_20 ( V_15 , V_17 , sizeof( V_17 ) ) ;
if ( V_34 < 0 )
break;
if ( fwrite ( V_17 , V_34 , 1 , stdout ) != 1 )
break;
}
}
F_3 ( L_4 , L_5 ) ;
while ( true ) {
int V_34 = F_20 ( V_15 , V_17 , sizeof( V_17 ) ) ;
if ( V_34 <= 0 )
break;
if ( fwrite ( V_17 , V_34 , 1 , stdout ) != 1 )
break;
}
V_32:
F_8 ( V_15 ) ;
V_28:
free ( V_16 ) ;
V_10:
F_10 ( T_7 ) ;
return V_2 ? 0 : - 1 ;
}
static int F_21 ( const char * V_35 , const char * V_36 , void * V_37 )
{
struct V_11 * T_7 = V_37 ;
if ( F_22 ( V_35 , L_20 ) )
return 0 ;
if ( strcmp ( V_35 , L_21 ) )
return - 1 ;
if ( ! strcmp ( V_36 , L_22 ) ||
! strcmp ( V_36 , L_23 ) ) {
T_7 -> V_26 = V_36 ;
return 0 ;
}
F_13 ( L_24 ) ;
return - 1 ;
}
int F_23 ( int V_12 , const char * * V_13 , const char * T_8 V_1 )
{
int V_7 ;
struct V_11 T_7 = {
. V_26 = V_38 ,
. V_25 = { . V_39 = V_40 , } ,
} ;
const char * const V_41 [] = {
L_25 ,
L_26 ,
NULL
} ;
const struct V_42 V_43 [] = {
F_24 ( 't' , L_27 , & T_7 . V_26 , L_27 ,
L_28 ) ,
F_25 ( 'v' , L_29 , & V_44 ,
L_30 ) ,
F_26 ()
} ;
V_7 = F_27 ( F_21 , & T_7 ) ;
if ( V_7 < 0 )
return - 1 ;
V_12 = F_28 ( V_12 , V_13 , V_43 , V_41 ,
V_45 ) ;
if ( ! V_12 )
F_29 ( V_41 , V_43 ) ;
T_7 . V_24 = F_30 () ;
if ( T_7 . V_24 == NULL )
return - V_46 ;
V_7 = F_31 ( T_7 . V_24 , & T_7 . V_25 ) ;
if ( V_7 < 0 )
goto V_47;
V_7 = F_11 ( & T_7 , V_12 , V_13 ) ;
V_47:
F_32 ( T_7 . V_24 ) ;
return V_7 ;
}
