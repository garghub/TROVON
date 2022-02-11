static void F_1 ( void )
{
struct V_1 * V_2 ;
printf ( L_1 ) ;
printf ( L_2 , V_3 [ 0 ] ) ;
printf ( L_3 ) ;
F_2 (cmd) {
printf ( L_4 , V_2 -> V_4 , V_2 -> V_5 ) ;
}
printf ( L_5 ) ;
}
static int F_3 ( int V_6 , const char * * V_7 ,
const char * T_1 V_8 )
{
const char * V_9 = NULL ;
struct V_10 V_11 = {
. V_12 = false ,
. V_13 = false ,
} ;
const struct V_14 V_15 [] = {
F_4 ( 'v' , L_6 , & V_16 , L_7 ) ,
F_5 ( 'i' , L_8 , & V_17 , L_9 , L_10 ) ,
#ifdef F_6
F_5 ( 0 , L_11 , & V_9 , NULL , L_12 ) ,
#endif
F_7 ( 'f' , L_13 , & V_11 . V_12 , L_14 ) ,
F_7 ( 0 , L_15 , & V_11 . V_13 , L_16 ) ,
F_8 ()
} ;
#ifndef F_6
F_9 ( L_17 ) ;
return - 1 ;
#endif
V_6 = F_10 ( V_6 , V_7 , V_15 ,
V_18 , 0 ) ;
if ( V_6 ) {
F_11 ( V_18 , V_15 ) ;
return - 1 ;
}
if ( V_9 ) {
#ifdef F_6
return F_12 ( V_17 , V_9 , & V_11 ) ;
#else
F_9 ( L_18 ) ;
return - 1 ;
#endif
}
return 0 ;
}
int F_13 ( int V_6 , const char * * V_7 , const char * T_1 )
{
struct V_1 * V_2 ;
const char * V_19 ;
if ( V_6 < 2 )
goto V_20;
V_6 = F_14 ( V_6 , V_7 , V_21 , V_22 , V_3 ,
V_23 ) ;
if ( V_6 < 1 )
goto V_20;
V_19 = V_7 [ 0 ] ;
F_2 (cmd) {
if ( strcmp ( V_2 -> V_4 , V_19 ) )
continue;
return V_2 -> V_24 ( V_6 , V_7 , T_1 ) ;
}
F_9 ( L_19 , V_19 ) ;
V_20:
F_1 () ;
return - 1 ;
}
