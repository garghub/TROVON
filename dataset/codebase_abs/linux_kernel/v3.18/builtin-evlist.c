static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 = {
. V_10 = V_1 ,
. V_11 = V_12 ,
} ;
V_5 = F_2 ( & V_9 , 0 , NULL ) ;
if ( V_5 == NULL )
return - 1 ;
F_3 (session->evlist, pos)
F_4 ( V_7 , V_3 , stdout ) ;
F_5 ( V_5 ) ;
return 0 ;
}
int F_6 ( int V_13 , const char * * V_14 , const char * T_1 V_15 )
{
struct V_2 V_3 = { . V_16 = false , } ;
const struct V_17 V_18 [] = {
F_7 ( 'i' , L_1 , & V_19 , L_2 , L_3 ) ,
F_8 ( 'F' , L_4 , & V_3 . V_20 , L_5 ) ,
F_8 ( 'v' , L_6 , & V_3 . V_16 ,
L_7 ) ,
F_8 ( 'g' , L_8 , & V_3 . V_21 ,
L_9 ) ,
F_9 ()
} ;
const char * const V_22 [] = {
L_10 ,
NULL
} ;
V_13 = F_10 ( V_13 , V_14 , V_18 , V_22 , 0 ) ;
if ( V_13 )
F_11 ( V_22 , V_18 ) ;
if ( V_3 . V_21 && ( V_3 . V_16 || V_3 . V_20 ) ) {
F_12 ( L_11 ) ;
F_11 ( V_22 , V_18 ) ;
}
return F_1 ( V_19 , & V_3 ) ;
}
