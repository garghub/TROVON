int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * * V_3 = NULL , * * V_4 = NULL ;
unsigned int V_5 ;
F_2 () ;
V_1 = F_3 ( V_6 ) ;
if ( V_1 < 0 )
return V_1 ;
V_5 = F_4 () ;
if ( V_5 == V_7 || V_5 == V_8 ||
V_5 == V_9 || V_5 == V_10 ||
V_5 == V_11 || V_5 == V_12 ) {
V_3 = V_13 ;
V_4 = V_14 ;
} else if ( V_5 == V_15 || V_5 == V_16 ) {
V_3 = V_17 ;
V_4 = V_18 ;
} else if ( V_5 == V_19 || V_5 == V_20 ||
V_5 == V_21 ) {
V_3 = V_22 ;
V_4 = V_23 ;
} else {
F_5 ( 1 , L_1 ) ;
return - V_24 ;
}
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_4 && F_6 () == V_25 ) {
V_1 = F_3 ( V_4 ) ;
if ( V_1 < 0 )
return V_1 ;
}
V_3 = NULL ;
if ( V_5 == V_7 ) {
V_3 = V_26 ;
} else if ( V_5 == V_8 || V_5 == V_9 ||
V_5 == V_10 || V_5 == V_11 ||
V_5 == V_12 ) {
V_3 = V_27 ;
}
if ( V_3 ) {
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
}
V_3 = NULL ;
if ( V_5 == V_7 || V_5 == V_8 ||
V_5 == V_9 ) {
V_3 = V_28 ;
} else if ( V_5 == V_10 || V_5 == V_11 ||
V_5 == V_12 ) {
V_3 = V_29 ;
}
if ( V_3 )
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_3 ( V_30 ) ;
return V_1 ;
}
