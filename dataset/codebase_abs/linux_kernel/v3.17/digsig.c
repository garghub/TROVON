int F_1 ( const unsigned int V_1 , const char * V_2 , int V_3 ,
const char * V_4 , int V_5 )
{
if ( V_1 >= V_6 )
return - V_7 ;
if ( ! V_8 [ V_1 ] ) {
V_8 [ V_1 ] =
F_2 ( & V_9 , V_10 [ V_1 ] , NULL ) ;
if ( F_3 ( V_8 [ V_1 ] ) ) {
int V_11 = F_4 ( V_8 [ V_1 ] ) ;
F_5 ( L_1 , V_10 [ V_1 ] , V_11 ) ;
V_8 [ V_1 ] = NULL ;
return V_11 ;
}
}
switch ( V_2 [ 1 ] ) {
case 1 :
return F_6 ( V_8 [ V_1 ] , V_2 + 1 , V_3 - 1 ,
V_4 , V_5 ) ;
case 2 :
return F_7 ( V_8 [ V_1 ] , V_2 , V_3 ,
V_4 , V_5 ) ;
}
return - V_12 ;
}
int F_8 ( const unsigned int V_1 )
{
const struct V_13 * V_13 = F_9 () ;
int V_11 = 0 ;
V_8 [ V_1 ] = F_10 ( V_10 [ V_1 ] , F_11 ( 0 ) ,
F_12 ( 0 ) , V_13 ,
( ( V_14 & ~ V_15 ) |
V_16 | V_17 |
V_18 | V_19 ) ,
V_20 , NULL ) ;
if ( ! F_3 ( V_8 [ V_1 ] ) )
F_13 ( V_21 , & V_8 [ V_1 ] -> V_22 ) ;
else {
V_11 = F_4 ( V_8 [ V_1 ] ) ;
F_14 ( L_2 ,
V_10 [ V_1 ] , V_11 ) ;
V_8 [ V_1 ] = NULL ;
}
return V_11 ;
}
