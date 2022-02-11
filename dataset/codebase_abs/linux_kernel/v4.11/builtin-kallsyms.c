static int F_1 ( int V_1 , const char * * V_2 )
{
int V_3 ;
struct V_4 * V_4 = F_2 () ;
if ( V_4 == NULL ) {
F_3 ( L_1 ) ;
return - 1 ;
}
for ( V_3 = 0 ; V_3 < V_1 ; ++ V_3 ) {
struct V_5 * V_5 ;
struct V_6 * V_6 = F_4 ( V_4 , V_2 [ V_3 ] , & V_5 ) ;
if ( V_6 == NULL ) {
printf ( L_2 , V_2 [ V_3 ] ) ;
continue;
}
printf ( L_3 V_7 L_4 V_7 L_5 V_7 L_4 V_7 L_6 ,
V_6 -> V_8 , V_5 -> V_9 -> V_10 , V_5 -> V_9 -> V_11 ,
V_5 -> V_12 ( V_5 , V_6 -> V_13 ) , V_5 -> V_12 ( V_5 , V_6 -> V_14 ) ,
V_6 -> V_13 , V_6 -> V_14 ) ;
}
F_5 ( V_4 ) ;
return 0 ;
}
int F_6 ( int V_1 , const char * * V_2 , const char * T_1 V_15 )
{
const struct V_16 V_17 [] = {
F_7 ( 'v' , L_7 , & V_18 , L_8 ) ,
F_8 ()
} ;
const char * const V_19 [] = {
L_9 ,
NULL
} ;
V_1 = F_9 ( V_1 , V_2 , V_17 , V_19 , 0 ) ;
if ( V_1 < 1 )
F_10 ( V_19 , V_17 ) ;
V_20 . V_21 = true ;
V_20 . V_22 = ( V_20 . V_23 == NULL ) ;
if ( F_11 ( NULL ) < 0 )
return - 1 ;
return F_1 ( V_1 , V_2 ) ;
}
