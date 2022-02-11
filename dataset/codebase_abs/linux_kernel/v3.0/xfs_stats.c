static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
static const struct V_11 {
char * V_12 ;
int V_13 ;
} V_14 [] = {
{ L_1 , V_15 } ,
{ L_2 , V_16 } ,
{ L_3 , V_17 } ,
{ L_4 , V_18 } ,
{ L_5 , V_19 } ,
{ L_6 , V_20 } ,
{ L_7 , V_21 } ,
{ L_8 , V_22 } ,
{ L_9 , V_23 } ,
{ L_10 , V_24 } ,
{ L_11 , V_25 } ,
{ L_12 , V_26 } ,
{ L_13 , V_27 } ,
{ L_14 , V_28 } ,
{ L_15 , V_29 } ,
{ L_16 , V_30 } ,
{ L_17 , V_31 } ,
{ L_18 , V_32 } ,
{ L_19 , V_33 } ,
} ;
for ( V_5 = V_6 = 0 ; V_5 < F_2 ( V_14 ) ; V_5 ++ ) {
F_3 ( V_2 , L_20 , V_14 [ V_5 ] . V_12 ) ;
while ( V_6 < V_14 [ V_5 ] . V_13 ) {
V_7 = 0 ;
F_4 (c)
V_7 += * ( ( ( V_34 * ) & F_5 ( V_35 , V_4 ) + V_6 ) ) ;
F_3 ( V_2 , L_21 , V_7 ) ;
V_6 ++ ;
}
F_6 ( V_2 , '\n' ) ;
}
F_4 (i) {
V_8 += F_5 ( V_35 , V_5 ) . V_8 ;
V_9 += F_5 ( V_35 , V_5 ) . V_9 ;
V_10 += F_5 ( V_35 , V_5 ) . V_10 ;
}
F_3 ( V_2 , L_22 ,
V_8 , V_9 , V_10 ) ;
F_3 ( V_2 , L_23 ,
#if F_7 ( V_36 )
1 ) ;
#else
0 ) ;
int F_8 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
return F_9 ( V_38 , F_1 , NULL ) ;
}
int
F_10 ( void )
{
if ( ! F_11 ( L_24 , NULL ) )
goto V_39;
if ( ! F_12 ( L_25 , 0 , NULL ,
& V_40 ) )
goto V_41;
return 0 ;
V_41:
F_13 ( L_24 , NULL ) ;
V_39:
return - V_42 ;
}
void
F_14 ( void )
{
F_13 ( L_25 , NULL ) ;
F_13 ( L_24 , NULL ) ;
}
