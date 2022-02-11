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
if ( V_8 || F_10 ( & V_14 ) )
F_11 ( V_12 , & V_20 ) ;
F_12 ( V_12 , stdout , F_6 , V_8 ) ;
F_13 ( V_12 ) ;
V_19:
return 0 ;
}
int F_14 ( int V_21 , const char * * V_22 ,
const char * T_3 V_23 )
{
bool V_24 = false ;
bool V_8 = false ;
bool V_10 = false ;
const struct V_25 V_26 [] = {
F_15 ( 'H' , L_3 , & V_8 , L_4 ) ,
F_16 ( 'i' , L_5 , & V_16 , L_6 , L_7 ) ,
F_15 ( 'f' , L_8 , & V_10 , L_9 ) ,
F_15 ( 'k' , L_10 , & V_24 , L_11 ) ,
F_17 ( 'v' , L_12 , & V_27 , L_13 ) ,
F_18 ()
} ;
const char * const V_28 [] = {
L_14 ,
NULL
} ;
V_21 = F_19 ( V_21 , V_22 , V_26 , V_28 , 0 ) ;
F_20 () ;
if ( V_24 )
return F_1 ( stdout ) ;
return F_7 ( V_10 , V_8 ) ;
}
