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
static int F_6 ( const char * V_7 ,
bool V_8 , bool V_9 )
{
struct V_10 * V_11 ;
F_7 () ;
V_11 = F_8 ( V_7 , V_12 , V_8 , false ,
& V_13 ) ;
if ( V_11 == NULL )
return - 1 ;
if ( F_4 ( V_11 -> V_14 , stdout ) )
goto V_15;
if ( V_9 || V_11 -> V_16 )
F_9 ( V_11 , & V_13 ) ;
F_10 ( V_11 , stdout , V_9 ) ;
V_15:
F_11 ( V_11 ) ;
return 0 ;
}
int F_12 ( int V_17 , const char * * V_18 ,
const char * T_3 V_19 )
{
bool V_20 = false ;
bool V_9 = false ;
bool V_8 = false ;
const char * V_7 = NULL ;
const struct V_21 V_22 [] = {
F_13 ( 'H' , L_3 , & V_9 , L_4 ) ,
F_14 ( 'i' , L_5 , & V_7 , L_6 , L_7 ) ,
F_13 ( 'f' , L_8 , & V_8 , L_9 ) ,
F_13 ( 'k' , L_10 , & V_20 , L_11 ) ,
F_15 ( 'v' , L_12 , & V_23 , L_13 ) ,
F_16 ()
} ;
const char * const V_24 [] = {
L_14 ,
NULL
} ;
V_17 = F_17 ( V_17 , V_18 , V_22 , V_24 , 0 ) ;
F_18 () ;
if ( V_20 )
return F_1 ( stdout ) ;
return F_6 ( V_7 , V_8 , V_9 ) ;
}
