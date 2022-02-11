static inline int F_1 ( void )
{
return F_2 ( V_1 , V_2 + V_3 ,
V_4 , V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned long V_8 , void * V_9 )
{
F_1 () ;
F_2 ( V_1 , V_2 + V_3 ,
V_10 , 0 ) ;
return V_11 ;
}
static int F_4 ( struct V_12 * V_13 )
{
int V_14 ;
int V_15 ;
T_1 V_16 ;
unsigned int V_17 ;
T_1 V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = & V_13 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_25 ;
if ( ! V_24 )
return - V_26 ;
V_1 = F_5 ( V_24 , L_1 ) ;
if ( F_6 ( V_1 ) )
return F_7 ( V_1 ) ;
V_20 = F_5 ( V_24 , L_2 ) ;
if ( F_6 ( V_20 ) )
return F_7 ( V_20 ) ;
V_15 = F_8 ( V_24 , L_1 , 1 , & V_2 ) ;
if ( V_15 ) {
F_9 ( V_22 , L_3 ) ;
return - V_27 ;
}
V_15 = F_8 ( V_24 , L_2 , 1 , & V_18 ) ;
if ( V_15 ) {
F_9 ( V_22 , L_4 ) ;
return - V_27 ;
}
V_16 = F_10 ( V_24 , L_5 ) ;
V_16 = V_16 ? V_28 : V_29 ;
V_15 = F_1 () ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( V_1 , V_2 + V_30 , V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( V_1 , V_2 + V_31 , 0 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_32 ; V_14 ++ ) {
V_15 = F_8 ( V_24 , L_6 , V_14 , & V_16 ) ;
if ( V_15 == - V_33 && ! V_14 ) {
F_9 ( V_22 , L_7
L_8 ) ;
return - V_27 ;
} else if ( V_15 ) {
break;
}
if ( V_16 >= V_32 ) {
F_9 ( V_22 , L_9
L_10 ) ;
return - V_27 ;
}
V_17 = V_18 + V_16 * 4 ;
V_15 = F_2 ( V_20 , V_17 , V_34 ,
V_35 |
V_36 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_12 ( & V_37 ) ;
if ( V_15 )
F_9 ( V_22 , L_11 , V_15 ) ;
return V_15 ;
}
