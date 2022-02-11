static inline int F_1 ( void )
{
return F_2 ( V_1 , V_2 + V_3 ,
V_4 , V_5 ) ;
}
static void F_3 ( enum V_6 V_7 , const char * V_8 )
{
F_1 () ;
F_2 ( V_1 , V_2 + V_3 ,
V_9 , 0 ) ;
}
static int F_4 ( struct V_10 * V_11 )
{
int V_12 ;
int V_13 ;
T_1 V_14 ;
unsigned int V_15 ;
T_1 V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = & V_11 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
if ( ! V_22 )
return - V_24 ;
V_1 = F_5 ( V_22 , L_1 ) ;
if ( F_6 ( V_1 ) )
return F_7 ( V_1 ) ;
V_18 = F_5 ( V_22 , L_2 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_13 = F_8 ( V_22 , L_1 , 1 , & V_2 ) ;
if ( V_13 ) {
F_9 ( V_20 , L_3 ) ;
return - V_25 ;
}
V_13 = F_8 ( V_22 , L_2 , 1 , & V_16 ) ;
if ( V_13 ) {
F_9 ( V_20 , L_4 ) ;
return - V_25 ;
}
V_14 = F_10 ( V_22 , L_5 ) ;
V_14 = V_14 ? V_26 : V_27 ;
V_13 = F_1 () ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_1 , V_2 + V_28 , V_14 ) ;
if ( V_13 )
return V_13 ;
V_29 = F_3 ;
V_13 = F_11 ( V_1 , V_2 + V_30 , 0 ) ;
if ( V_13 )
return V_13 ;
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
V_13 = F_8 ( V_22 , L_6 , V_12 , & V_14 ) ;
if ( V_13 == - V_32 && ! V_12 ) {
F_9 ( V_20 , L_7
L_8 ) ;
return - V_25 ;
} else if ( V_13 ) {
break;
}
if ( V_14 >= V_31 ) {
F_9 ( V_20 , L_9
L_10 ) ;
return - V_25 ;
}
V_15 = V_16 + V_14 * 4 ;
V_13 = F_2 ( V_18 , V_15 , V_33 ,
V_34 |
V_35 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
