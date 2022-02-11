static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 = {
. V_10 = V_1 ,
. V_11 = V_12 ,
. V_13 = V_3 -> V_13 ,
} ;
bool V_14 = false ;
V_5 = F_2 ( & V_9 , 0 , NULL ) ;
if ( V_5 == NULL )
return - 1 ;
F_3 (session->evlist, pos) {
F_4 ( V_7 , V_3 , stdout ) ;
if ( V_7 -> V_15 . type == V_16 )
V_14 = true ;
}
if ( V_14 && ! V_3 -> V_17 )
printf ( L_1 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
int F_6 ( int V_18 , const char * * V_19 )
{
struct V_2 V_3 = { . V_20 = false , } ;
const struct V_21 V_22 [] = {
F_7 ( 'i' , L_2 , & V_23 , L_3 , L_4 ) ,
F_8 ( 'F' , L_5 , & V_3 . V_24 , L_6 ) ,
F_8 ( 'v' , L_7 , & V_3 . V_20 ,
L_8 ) ,
F_8 ( 'g' , L_9 , & V_3 . V_25 ,
L_10 ) ,
F_8 ( 'f' , L_11 , & V_3 . V_13 , L_12 ) ,
F_8 ( 0 , L_13 , & V_3 . V_17 , L_14 ) ,
F_9 ()
} ;
const char * const V_26 [] = {
L_15 ,
NULL
} ;
V_18 = F_10 ( V_18 , V_19 , V_22 , V_26 , 0 ) ;
if ( V_18 )
F_11 ( V_26 , V_22 ) ;
if ( V_3 . V_25 && ( V_3 . V_20 || V_3 . V_24 ) ) {
F_12 ( V_26 , V_22 ,
L_16 ) ;
}
return F_1 ( V_23 , & V_3 ) ;
}
