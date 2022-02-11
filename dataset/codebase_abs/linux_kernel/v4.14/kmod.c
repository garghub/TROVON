static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 [ 3 ] ) ;
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( char * V_4 , int V_5 )
{
struct V_1 * V_2 ;
static char * V_6 [] = {
L_1 ,
L_2 ,
L_3 ,
NULL
} ;
char * * V_3 = F_4 ( sizeof( char * [ 5 ] ) , V_7 ) ;
if ( ! V_3 )
goto V_8;
V_4 = F_5 ( V_4 , V_7 ) ;
if ( ! V_4 )
goto V_9;
V_3 [ 0 ] = V_10 ;
V_3 [ 1 ] = L_4 ;
V_3 [ 2 ] = L_5 ;
V_3 [ 3 ] = V_4 ;
V_3 [ 4 ] = NULL ;
V_2 = F_6 ( V_10 , V_3 , V_6 , V_7 ,
NULL , F_1 , NULL ) ;
if ( ! V_2 )
goto V_11;
return F_7 ( V_2 , V_5 | V_12 ) ;
V_11:
F_2 ( V_4 ) ;
V_9:
F_2 ( V_3 ) ;
V_8:
return - V_13 ;
}
int F_8 ( bool V_5 , const char * V_14 , ... )
{
T_1 args ;
char V_4 [ V_15 ] ;
int V_16 ;
F_9 ( V_5 && F_10 () ) ;
if ( ! V_10 [ 0 ] )
return 0 ;
va_start ( args , V_14 ) ;
V_16 = vsnprintf ( V_4 , V_15 , V_14 , args ) ;
va_end ( args ) ;
if ( V_16 >= V_15 )
return - V_17 ;
V_16 = F_11 ( V_4 ) ;
if ( V_16 )
return V_16 ;
if ( F_12 ( & V_18 ) < 0 ) {
F_13 ( L_6 ,
F_14 ( & V_18 ) ,
V_19 , V_4 ) ;
V_16 = F_15 ( V_20 ,
F_12 ( & V_18 ) >= 0 ,
V_21 * V_22 ) ;
if ( ! V_16 ) {
F_13 ( L_7 ,
V_4 , V_19 , V_21 ) ;
return - V_23 ;
} else if ( V_16 == - V_24 ) {
F_13 ( L_8 , V_4 ) ;
return V_16 ;
}
}
F_16 ( V_4 , V_5 , V_25 ) ;
V_16 = F_3 ( V_4 , V_5 ? V_26 : V_27 ) ;
F_17 ( & V_18 ) ;
F_18 ( & V_20 ) ;
return V_16 ;
}
