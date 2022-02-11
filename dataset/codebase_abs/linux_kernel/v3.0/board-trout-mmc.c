static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
unsigned V_4 ;
for( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_4 = V_1 [ V_3 ] ;
F_2 ( V_5 , & V_4 , 0 ) ;
}
}
static int T_2 F_3 ( char * V_6 )
{
int V_7 = F_4 ( V_6 , NULL , 0 ) ;
V_8 = V_7 ;
return 1 ;
}
static T_1 F_5 ( struct V_9 * V_10 , unsigned int V_11 )
{
int V_12 , V_13 ;
F_6 ( ! V_14 ) ;
if ( V_11 == V_15 )
return 0 ;
V_15 = V_11 ;
if ( V_11 == 0 ) {
#if V_16
F_7 ( L_1 , V_17 ) ;
#endif
F_1 ( V_18 ,
F_8 ( V_18 ) ) ;
F_9 ( V_14 ) ;
V_19 = 0 ;
return 0 ;
}
if ( ! V_19 ) {
V_13 = F_10 ( V_14 ) ;
if ( V_13 ) {
F_7 ( V_20 L_2 ,
V_17 , V_13 ) ;
}
F_1 ( V_21 ,
F_8 ( V_21 ) ) ;
V_19 = 1 ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_22 ) ; V_12 ++ ) {
if ( V_22 [ V_12 ] . V_23 == ( 1 << V_11 ) ) {
#if V_16
F_7 ( L_3 ,
V_17 , V_22 [ V_12 ] . V_24 ) ;
#endif
V_13 = F_11 ( V_14 ,
V_22 [ V_12 ] . V_24 ) ;
if ( V_13 ) {
F_7 ( V_20
L_4 ,
V_17 , V_13 ) ;
}
return 0 ;
}
}
F_7 ( V_20 L_5 , V_17 , V_11 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_9 * V_10 )
{
unsigned int V_25 ;
V_25 = ( unsigned int ) F_13 ( V_26 ) ;
return ( ! V_25 ) ;
}
int T_2 F_14 ( unsigned int V_27 )
{
V_19 = 0 ;
V_14 = F_15 ( 0 , L_6 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_18 ( F_19 ( V_26 ) , 1 ) ;
if ( ! V_8 )
F_20 ( 2 , & V_28 ,
F_19 ( V_26 ) , 0 ) ;
else
F_7 ( V_29 L_7 ) ;
return 0 ;
}
