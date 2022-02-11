int F_1 ( const unsigned int V_1 , const char * V_2 , int V_3 ,
const char * V_4 , int V_5 )
{
if ( V_1 >= V_6 || V_3 < 2 )
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
int T_1 F_8 ( const unsigned int V_1 )
{
const struct V_13 * V_13 = F_9 () ;
int V_11 = 0 ;
if ( ! V_14 )
return 0 ;
V_8 [ V_1 ] = F_10 ( V_10 [ V_1 ] , F_11 ( 0 ) ,
F_12 ( 0 ) , V_13 ,
( ( V_15 & ~ V_16 ) |
V_17 | V_18 |
V_19 | V_20 ) ,
V_21 ,
V_22 , NULL ) ;
if ( F_3 ( V_8 [ V_1 ] ) ) {
V_11 = F_4 ( V_8 [ V_1 ] ) ;
F_13 ( L_2 ,
V_10 [ V_1 ] , V_11 ) ;
V_8 [ V_1 ] = NULL ;
}
return V_11 ;
}
int T_1 F_14 ( const unsigned int V_1 , const char * V_23 )
{
T_2 V_24 ;
char * V_25 ;
int V_26 ;
if ( ! V_8 [ V_1 ] )
return - V_7 ;
V_26 = F_15 ( V_23 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
V_24 = F_16 ( F_17 ( V_8 [ V_1 ] , 1 ) ,
L_3 ,
NULL ,
V_25 ,
V_26 ,
( ( V_15 & ~ V_16 ) |
V_17 | V_18 ) ,
V_21 ) ;
if ( F_3 ( V_24 ) ) {
V_26 = F_4 ( V_24 ) ;
F_5 ( L_4 ,
V_26 , V_23 ) ;
} else {
F_18 ( L_5 ,
F_19 ( V_24 ) -> V_27 , V_23 ) ;
F_20 ( V_24 ) ;
}
F_21 ( V_25 ) ;
return 0 ;
}
