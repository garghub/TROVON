static int F_1 ( T_1 * V_1 )
{
T_2 V_2 [ V_3 ] ;
char V_4 [ V_3 * 2 + 1 ] ;
if ( F_2 ( L_1 , V_2 ,
sizeof( V_2 ) ) != 0 )
return - 1 ;
F_3 ( V_2 , sizeof( V_2 ) ,
V_4 ) ;
fprintf ( V_1 , L_2 , V_4 ) ;
return 0 ;
}
static int F_4 ( const char * V_5 , T_1 * V_1 )
{
T_2 V_6 [ V_3 ] ;
char V_4 [ V_3 * 2 + 1 ] ;
if ( F_5 ( V_5 , V_6 ,
sizeof( V_6 ) ) != sizeof( V_6 ) )
return 0 ;
F_3 ( V_6 , sizeof( V_6 ) , V_4 ) ;
return fprintf ( V_1 , L_2 , V_4 ) ;
}
static bool F_6 ( struct V_7 * V_7 , int V_8 )
{
return V_8 && ! V_7 -> V_9 ;
}
static int F_7 ( bool V_10 , bool V_8 )
{
struct V_11 * V_12 ;
struct V_13 V_14 = {
. V_15 = V_16 ,
. V_17 = V_18 ,
. V_10 = V_10 ,
} ;
F_8 () ;
if ( F_4 ( V_16 , stdout ) )
goto V_19;
V_12 = F_9 ( & V_14 , false , & V_20 ) ;
if ( V_12 == NULL )
return - 1 ;
if ( ! F_10 ( & V_14 ) &&
F_11 ( & V_12 -> V_21 , V_22 ) )
V_8 = false ;
if ( V_8 || F_10 ( & V_14 ) )
F_12 ( V_12 ) ;
F_13 ( V_12 , stdout , F_6 , V_8 ) ;
F_14 ( V_12 ) ;
V_19:
return 0 ;
}
int F_15 ( int V_23 , const char * * V_24 ,
const char * T_3 V_25 )
{
bool V_26 = false ;
bool V_8 = false ;
bool V_10 = false ;
const struct V_27 V_28 [] = {
F_16 ( 'H' , L_3 , & V_8 , L_4 ) ,
F_17 ( 'i' , L_5 , & V_16 , L_6 , L_7 ) ,
F_16 ( 'f' , L_8 , & V_10 , L_9 ) ,
F_16 ( 'k' , L_10 , & V_26 , L_11 ) ,
F_18 ( 'v' , L_12 , & V_29 , L_13 ) ,
F_19 ()
} ;
const char * const V_30 [] = {
L_14 ,
NULL
} ;
V_23 = F_20 ( V_23 , V_24 , V_28 , V_30 , 0 ) ;
F_21 () ;
if ( V_26 )
return F_1 ( stdout ) ;
return F_7 ( V_10 , V_8 ) ;
}
