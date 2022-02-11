int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * * V_3 = NULL ;
unsigned int V_4 ;
F_2 () ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( F_4 () == V_6 ) {
V_1 = F_3 ( V_7 ) ;
if ( V_1 < 0 )
return V_1 ;
}
V_4 = F_5 () ;
if ( V_4 == V_8 || V_4 == V_9 ||
V_4 == V_10 || V_4 == V_11 ||
V_4 == V_12 || V_4 == V_13 ) {
V_3 = V_14 ;
} else if ( V_4 == V_15 || V_4 == V_16 ) {
V_3 = V_17 ;
} else if ( V_4 == V_18 || V_4 == V_19 ||
V_4 == V_20 ) {
V_3 = V_21 ;
} else {
F_6 ( 1 , L_1 ) ;
return - V_22 ;
}
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
V_3 = NULL ;
if ( V_4 == V_8 ) {
V_3 = V_23 ;
} else if ( V_4 == V_9 || V_4 == V_10 ||
V_4 == V_11 || V_4 == V_12 ||
V_4 == V_13 ) {
V_3 = V_24 ;
}
if ( V_3 ) {
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
}
V_3 = NULL ;
if ( V_4 == V_8 || V_4 == V_9 ||
V_4 == V_10 ) {
V_3 = V_25 ;
} else if ( V_4 == V_11 || V_4 == V_12 ||
V_4 == V_13 ) {
V_3 = V_26 ;
}
if ( V_3 )
V_1 = F_3 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_3 ( V_27 ) ;
return V_1 ;
}
