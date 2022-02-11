static int F_1 ( T_1 * V_1 )
{
char V_2 [ V_3 ] ;
int V_4 ;
V_4 = F_2 ( L_1 , V_2 ) ;
if ( V_4 != sizeof( V_2 ) )
return V_4 < 0 ? V_4 : - V_5 ;
return fprintf ( V_1 , L_2 , V_2 ) ;
}
static int F_3 ( const char * V_6 , T_1 * V_1 )
{
char V_2 [ V_3 ] ;
int V_4 ;
V_4 = F_4 ( V_6 , V_2 ) ;
if ( V_4 != sizeof( V_2 ) )
return V_4 < 0 ? V_4 : - V_5 ;
return fprintf ( V_1 , L_2 , V_2 ) ;
}
static bool F_5 ( struct V_7 * V_7 , int V_8 )
{
return V_8 && ! V_7 -> V_9 ;
}
static int F_6 ( bool V_10 , bool V_8 )
{
struct V_11 * V_12 ;
struct V_13 V_14 = {
. V_15 = V_16 ,
. V_17 = V_18 ,
. V_10 = V_10 ,
} ;
F_7 () ;
if ( F_3 ( V_16 , stdout ) > 0 )
goto V_19;
V_12 = F_8 ( & V_14 , false , & V_20 ) ;
if ( V_12 == NULL )
return - 1 ;
if ( ! F_9 ( & V_14 ) &&
F_10 ( & V_12 -> V_21 , V_22 ) )
V_8 = false ;
if ( V_8 || F_9 ( & V_14 ) )
F_11 ( V_12 ) ;
F_12 ( V_12 , stdout , F_5 , V_8 ) ;
F_13 ( V_12 ) ;
V_19:
return 0 ;
}
int F_14 ( int V_23 , const char * * V_24 )
{
bool V_25 = false ;
bool V_8 = false ;
bool V_10 = false ;
const struct V_26 V_27 [] = {
F_15 ( 'H' , L_3 , & V_8 , L_4 ) ,
F_16 ( 'i' , L_5 , & V_16 , L_6 , L_7 ) ,
F_15 ( 'f' , L_8 , & V_10 , L_9 ) ,
F_15 ( 'k' , L_10 , & V_25 , L_11 ) ,
F_17 ( 'v' , L_12 , & V_28 , L_13 ) ,
F_18 ()
} ;
const char * const V_29 [] = {
L_14 ,
NULL
} ;
V_23 = F_19 ( V_23 , V_24 , V_27 , V_29 , 0 ) ;
F_20 () ;
if ( V_25 )
return ! ( F_1 ( stdout ) > 0 ) ;
return F_6 ( V_10 , V_8 ) ;
}
