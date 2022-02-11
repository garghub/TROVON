static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_1 , V_8 , 0 , false , NULL ) ;
if ( V_5 == NULL )
return - V_9 ;
F_3 (pos, &session->evlist->entries, node)
F_4 ( V_7 , V_3 , stdout ) ;
F_5 ( V_5 ) ;
return 0 ;
}
int F_6 ( int V_10 , const char * * V_11 , const char * T_1 V_12 )
{
struct V_2 V_3 = { . V_13 = false , } ;
const struct V_14 V_15 [] = {
F_7 ( 'i' , L_1 , & V_16 , L_2 , L_3 ) ,
F_8 ( 'F' , L_4 , & V_3 . V_17 , L_5 ) ,
F_8 ( 'v' , L_6 , & V_3 . V_13 ,
L_7 ) ,
F_8 ( 'g' , L_8 , & V_3 . V_18 ,
L_9 ) ,
F_9 ()
} ;
const char * const V_19 [] = {
L_10 ,
NULL
} ;
V_10 = F_10 ( V_10 , V_11 , V_15 , V_19 , 0 ) ;
if ( V_10 )
F_11 ( V_19 , V_15 ) ;
if ( V_3 . V_18 && ( V_3 . V_13 || V_3 . V_17 ) ) {
F_12 ( L_11 ) ;
F_11 ( V_19 , V_15 ) ;
}
return F_1 ( V_16 , & V_3 ) ;
}
