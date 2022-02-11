static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 , V_11 ;
int V_12 ;
if ( V_13 ) {
V_10 = V_14 ;
V_11 = 38400000 ;
} else {
V_10 = V_15 ;
V_11 = 32768 ;
}
V_12 = F_2 ( V_9 , V_10 , V_11 ,
V_16 ) ;
if ( V_12 ) {
F_3 ( V_17 L_1 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_4 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
V_21 -> V_22 . integer . V_22 [ 0 ] = V_13 ;
return 0 ;
}
static int F_5 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
if ( V_13 == V_21 -> V_22 . integer . V_22 [ 0 ] )
return 0 ;
V_13 = V_21 -> V_22 . integer . V_22 [ 0 ] ;
return 1 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = V_6 -> V_24 ;
struct V_25 * V_26 = & V_24 -> V_26 ;
int V_12 ;
V_12 = F_7 ( V_24 , V_27 ,
F_8 ( V_27 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_26 , V_28 ,
F_8 ( V_28 ) ) ;
if ( V_12 )
return V_12 ;
F_10 ( V_26 , V_29 , F_8 ( V_29 ) ) ;
F_11 ( V_26 , L_2 ) ;
F_11 ( V_26 , L_3 ) ;
F_11 ( V_26 , L_4 ) ;
F_11 ( V_26 , L_5 ) ;
F_11 ( V_26 , L_6 ) ;
F_11 ( V_26 , L_7 ) ;
V_12 = F_12 ( V_26 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_13 ( V_24 , L_8 ,
V_30 , & V_31 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_14 ( & V_31 , F_8 ( V_32 ) ,
V_32 ) ;
if ( F_15 () )
F_16 ( V_24 , & V_31 , V_30 ) ;
else
F_17 ( & V_31 , V_30 , V_30 ) ;
return V_12 ;
}
static int T_1 F_18 ( void )
{
int V_12 ;
if ( ! F_15 () )
return - V_33 ;
F_3 ( V_34 L_9 ) ;
V_35 = F_19 ( L_10 , - 1 ) ;
if ( ! V_35 ) {
F_3 ( V_17 L_11 ) ;
return - V_36 ;
}
F_20 ( V_35 , & V_37 ) ;
V_12 = F_21 ( V_35 ) ;
if ( V_12 )
goto V_38;
V_13 = 1 ;
return 0 ;
V_38:
F_3 ( V_17 L_12 ) ;
F_22 ( V_35 ) ;
return V_12 ;
}
static void T_2 F_23 ( void )
{
F_24 ( V_35 ) ;
}
