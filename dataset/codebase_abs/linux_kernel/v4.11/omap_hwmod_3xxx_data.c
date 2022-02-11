static bool T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_1 * V_4 ;
bool V_5 ;
if ( ! V_2 )
return F_2 () == V_6 ;
V_4 = F_3 ( V_2 , V_3 ) ;
V_5 = F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
return V_5 ;
}
int T_1 F_6 ( void )
{
int V_7 ;
struct V_8 * * V_9 = NULL , * * V_10 = NULL , * * V_11 = NULL ;
struct V_8 * * V_12 = NULL ;
struct V_1 * V_2 = NULL ;
unsigned int V_13 ;
F_7 () ;
V_7 = F_8 ( V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_13 = F_9 () ;
if ( V_13 == V_15 || V_13 == V_16 ||
V_13 == V_17 || V_13 == V_18 ||
V_13 == V_19 || V_13 == V_20 ) {
V_9 = V_21 ;
V_10 = V_22 ;
V_11 = V_23 ;
V_12 = V_24 ;
} else if ( V_13 == V_25 || V_13 == V_26 ) {
V_9 = V_27 ;
V_10 = V_28 ;
V_11 = V_29 ;
V_12 = V_30 ;
} else if ( V_13 == V_31 || V_13 == V_32 ||
V_13 == V_33 ) {
V_9 = V_34 ;
V_10 = V_35 ;
V_11 = V_36 ;
V_12 = V_37 ;
} else {
F_10 ( 1 , L_1 ) ;
return - V_38 ;
}
V_7 = F_8 ( V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_10 && F_2 () == V_6 ) {
V_7 = F_8 ( V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( F_11 () )
V_2 = F_12 ( NULL , L_2 ) ;
if ( V_11 && F_1 ( V_2 , L_3 ) ) {
V_7 = F_8 ( V_11 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 ) ;
return V_7 ;
}
}
if ( V_12 && F_1 ( V_2 , L_4 ) ) {
V_7 = F_8 ( V_12 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 ) ;
return V_7 ;
}
}
F_5 ( V_2 ) ;
V_9 = NULL ;
if ( V_13 == V_15 ) {
V_9 = V_39 ;
} else if ( V_13 == V_16 || V_13 == V_17 ||
V_13 == V_18 || V_13 == V_19 ||
V_13 == V_20 ) {
V_9 = V_40 ;
}
if ( V_9 ) {
V_7 = F_8 ( V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_9 = NULL ;
if ( V_13 == V_15 || V_13 == V_16 ||
V_13 == V_17 ) {
V_9 = V_41 ;
} else if ( V_13 == V_18 || V_13 == V_19 ||
V_13 == V_20 ) {
V_9 = V_42 ;
}
if ( V_9 )
V_7 = F_8 ( V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_8 ( V_43 ) ;
return V_7 ;
}
