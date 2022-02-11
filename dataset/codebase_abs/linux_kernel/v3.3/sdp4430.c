static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 , V_11 ;
int V_12 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
if ( V_10 == V_14 )
V_11 = 38400000 ;
else if ( V_10 == V_15 )
V_11 = 32768 ;
else
return - V_16 ;
V_12 = F_3 ( V_9 , V_10 , V_11 ,
V_17 ) ;
if ( V_12 ) {
F_4 ( V_18 L_1 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_19 = V_6 -> V_19 ;
int V_12 = 0 ;
V_12 = F_3 ( V_19 , V_20 ,
19200000 , V_17 ) ;
if ( V_12 < 0 ) {
F_4 ( V_18 L_2 ) ;
return V_12 ;
}
V_12 = F_3 ( V_19 , V_21 , 2400000 ,
V_22 ) ;
if ( V_12 < 0 ) {
F_4 ( V_18 L_3 ) ;
return V_12 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_23 * V_13 = V_6 -> V_13 ;
int V_12 , V_24 ;
V_24 = F_7 ( V_13 , V_25 ) ;
F_8 ( V_6 , F_9 ( V_24 ) ,
F_10 ( V_24 ) ) ;
V_12 = F_11 ( V_13 , L_4 ,
V_26 , & V_27 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( & V_27 , F_13 ( V_28 ) ,
V_28 ) ;
if ( F_14 () )
F_15 ( V_13 , & V_27 , V_26 ) ;
else
F_16 ( & V_27 , V_26 , V_26 ) ;
return V_12 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_23 * V_13 = V_6 -> V_13 ;
struct V_29 * V_30 = & V_13 -> V_30 ;
int V_12 ;
V_12 = F_18 ( V_30 , V_31 ,
F_13 ( V_31 ) ) ;
if ( V_12 )
return V_12 ;
return F_19 ( V_30 , V_32 ,
F_13 ( V_32 ) ) ;
}
static int T_1 F_20 ( void )
{
int V_12 ;
if ( ! F_14 () )
return - V_33 ;
F_4 ( V_34 L_5 ) ;
V_35 = F_21 ( L_6 , - 1 ) ;
if ( ! V_35 ) {
F_4 ( V_18 L_7 ) ;
return - V_36 ;
}
F_22 ( V_35 , & V_37 ) ;
V_12 = F_23 ( V_35 ) ;
if ( V_12 )
goto V_38;
return 0 ;
V_38:
F_4 ( V_18 L_8 ) ;
F_24 ( V_35 ) ;
return V_12 ;
}
static void T_2 F_25 ( void )
{
F_26 ( V_35 ) ;
}
