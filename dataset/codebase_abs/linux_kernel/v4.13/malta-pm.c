int F_1 ( unsigned V_1 )
{
int V_2 ;
T_1 V_3 ;
if ( ! V_4 || ! V_5 )
return - V_6 ;
while ( 1 ) {
V_3 = F_2 ( V_5 + V_7 ) ;
if ( ! ( V_3 & V_8 ) )
break;
F_3 ( V_3 , V_5 + V_7 ) ;
}
F_3 ( V_1 | V_9 ,
V_5 + V_10 ) ;
F_4 ( 10 ) ;
V_2 = F_5 ( 0 , F_6 ( 0x1f , 0x7 ) ) ;
F_7 ( V_4 , V_2 , 0 ,
V_11 ) ;
F_4 ( 1000 ) ;
return 0 ;
}
static int T_2 F_8 ( void )
{
struct V_12 * V_13 ;
int V_14 , V_15 = V_16 ;
V_4 = F_9 ( NULL ) ;
if ( ! V_4 ) {
F_10 ( L_1 ) ;
return - V_6 ;
}
V_13 = F_11 ( V_17 ,
V_18 , V_19 ,
V_19 , NULL ) ;
if ( ! V_13 ) {
F_10 ( L_2 ) ;
return - V_6 ;
}
V_14 = F_12 ( V_13 , V_15 , L_3 ) ;
if ( V_14 ) {
F_10 ( L_4 ,
V_14 ) ;
F_13 ( V_13 ) ;
return - V_6 ;
}
V_5 = F_14 ( V_13 , V_15 ) ;
F_13 ( V_13 ) ;
return 0 ;
}
