int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * * V_3 = NULL ;
unsigned int V_4 ;
V_1 = F_2 ( V_5 ) ;
if ( V_1 < 0 )
return V_1 ;
V_4 = F_3 () ;
if ( V_4 == V_6 || V_4 == V_7 ||
V_4 == V_8 || V_4 == V_9 ||
V_4 == V_10 || V_4 == V_11 ) {
V_3 = V_12 ;
} else if ( V_4 == V_13 || V_4 == V_14 ) {
V_3 = V_15 ;
} else if ( V_4 == V_16 || V_4 == V_17 ||
V_4 == V_18 ) {
V_3 = V_19 ;
} else {
F_4 ( 1 , L_1 ) ;
return - V_20 ;
} ;
V_1 = F_2 ( V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
V_3 = NULL ;
if ( V_4 == V_6 ) {
V_3 = V_21 ;
} else if ( V_4 == V_7 || V_4 == V_8 ||
V_4 == V_9 || V_4 == V_10 ||
V_4 == V_11 ) {
V_3 = V_22 ;
} ;
if ( V_3 )
V_1 = F_2 ( V_3 ) ;
return V_1 ;
}
