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
struct V_14 * V_15 ;
int V_11 = 0 ;
if ( ! V_16 )
return 0 ;
V_15 = F_10 ( sizeof( struct V_14 ) , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_15 -> V_19 = V_20 ;
V_8 [ V_1 ] = F_11 ( V_10 [ V_1 ] , F_12 ( 0 ) ,
F_13 ( 0 ) , V_13 ,
( ( V_21 & ~ V_22 ) |
V_23 | V_24 |
V_25 | V_26 ) ,
V_27 ,
V_15 , NULL ) ;
if ( F_3 ( V_8 [ V_1 ] ) ) {
V_11 = F_4 ( V_8 [ V_1 ] ) ;
F_14 ( L_2 ,
V_10 [ V_1 ] , V_11 ) ;
V_8 [ V_1 ] = NULL ;
}
return V_11 ;
}
int T_1 F_15 ( const unsigned int V_1 , const char * V_28 )
{
T_2 V_29 ;
char * V_30 ;
int V_31 ;
if ( ! V_8 [ V_1 ] )
return - V_7 ;
V_31 = F_16 ( V_28 , & V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
V_29 = F_17 ( F_18 ( V_8 [ V_1 ] , 1 ) ,
L_3 ,
NULL ,
V_30 ,
V_31 ,
( ( V_21 & ~ V_22 ) |
V_23 | V_24 ) ,
V_27 ) ;
if ( F_3 ( V_29 ) ) {
V_31 = F_4 ( V_29 ) ;
F_5 ( L_4 ,
V_31 , V_28 ) ;
} else {
F_19 ( L_5 ,
F_20 ( V_29 ) -> V_32 , V_28 ) ;
F_21 ( V_29 ) ;
}
F_22 ( V_30 ) ;
return 0 ;
}
