static int T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! V_2 )
return ( F_2 () == V_4 ) ? 1 : 0 ;
if ( F_3 ( F_4 ( V_2 , V_3 ) ) )
return 1 ;
return 0 ;
}
int T_1 F_5 ( void )
{
int V_5 ;
struct V_6 * * V_7 = NULL , * * V_8 = NULL , * * V_9 = NULL ;
struct V_6 * * V_10 = NULL ;
struct V_1 * V_2 = NULL ;
unsigned int V_11 ;
F_6 () ;
V_5 = F_7 ( V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_11 = F_8 () ;
if ( V_11 == V_13 || V_11 == V_14 ||
V_11 == V_15 || V_11 == V_16 ||
V_11 == V_17 || V_11 == V_18 ) {
V_7 = V_19 ;
V_8 = V_20 ;
V_9 = V_21 ;
V_10 = V_22 ;
} else if ( V_11 == V_23 || V_11 == V_24 ) {
V_7 = V_25 ;
V_8 = V_26 ;
V_9 = V_27 ;
V_10 = V_28 ;
} else if ( V_11 == V_29 || V_11 == V_30 ||
V_11 == V_31 ) {
V_7 = V_32 ;
V_8 = V_33 ;
V_9 = V_34 ;
V_10 = V_35 ;
} else {
F_9 ( 1 , L_1 ) ;
return - V_36 ;
}
V_5 = F_7 ( V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_8 && F_2 () == V_4 ) {
V_5 = F_7 ( V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( F_10 () )
V_2 = F_4 ( NULL , L_2 ) ;
if ( V_9 && F_1 ( V_2 , L_3 ) ) {
V_5 = F_7 ( V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_10 && F_1 ( V_2 , L_4 ) ) {
V_5 = F_7 ( V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_7 = NULL ;
if ( V_11 == V_13 ) {
V_7 = V_37 ;
} else if ( V_11 == V_14 || V_11 == V_15 ||
V_11 == V_16 || V_11 == V_17 ||
V_11 == V_18 ) {
V_7 = V_38 ;
}
if ( V_7 ) {
V_5 = F_7 ( V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_7 = NULL ;
if ( V_11 == V_13 || V_11 == V_14 ||
V_11 == V_15 ) {
V_7 = V_39 ;
} else if ( V_11 == V_16 || V_11 == V_17 ||
V_11 == V_18 ) {
V_7 = V_40 ;
}
if ( V_7 )
V_5 = F_7 ( V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_41 ) ;
return V_5 ;
}
