static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_7 ;
if ( F_3 ( V_2 , V_8 , V_6 -> V_9 ) )
goto V_10;
V_7 = F_4 ( V_11 , & V_6 -> V_12 ) ;
if ( F_3 ( V_2 , V_13 , V_7 ) )
goto V_10;
V_7 = F_4 ( V_14 , & V_6 -> V_12 ) ;
if ( F_3 ( V_2 , V_15 , V_7 ) )
goto V_10;
return 0 ;
V_10:
return - V_16 ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_17 * V_18 [] , struct V_17 * V_19 [] )
{
T_1 V_20 , V_21 ;
int V_22 = 0 ;
if ( V_19 [ V_13 ] ) {
V_20 = F_6 ( V_19 [ V_13 ] ) ;
if ( V_20 == V_23 )
V_22 = F_7 ( V_4 , L_1 ) ;
else if ( V_20 == V_24 )
V_22 = F_7 ( V_4 , L_2 ) ;
else
V_22 = - V_25 ;
if ( V_22 < 0 )
goto V_26;
}
if ( V_19 [ V_15 ] ) {
V_21 = F_6 ( V_19 [ V_15 ] ) ;
F_8 ( V_4 , V_21 ) ;
}
V_26:
return V_22 ;
}
static int F_9 ( struct V_27 * V_28 , struct V_3 * V_4 ,
struct V_17 * V_18 [] , struct V_17 * V_19 [] )
{
struct V_3 * V_29 ;
struct V_5 * V_30 ;
T_1 V_31 ;
int V_32 ;
if ( ! V_18 [ V_33 ] )
return - V_25 ;
V_29 = F_10 ( V_28 , F_11 ( V_18 [ V_33 ] ) ) ;
if ( ! V_29 )
return - V_34 ;
V_30 = F_2 ( V_29 ) ;
if ( F_4 ( V_35 , & V_30 -> V_12 ) ) {
F_12 ( V_30 , L_3 ) ;
return - V_25 ;
}
if ( ! V_19 || ! V_19 [ V_8 ] ) {
F_13 ( V_30 , L_4 ) ;
V_31 = V_30 -> V_9 ;
} else
V_31 = F_6 ( V_19 [ V_8 ] ) ;
if ( V_31 == 0 || V_31 == 0x8000 )
return - V_25 ;
V_31 |= 0x8000 ;
V_32 = F_14 ( V_30 , F_2 ( V_4 ) , V_31 , V_36 ) ;
if ( ! V_32 && V_19 )
V_32 = F_5 ( V_4 , V_18 , V_19 ) ;
return V_32 ;
}
static void F_15 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
struct V_5 * V_6 , * V_30 ;
V_6 = F_2 ( V_4 ) ;
V_30 = F_2 ( V_6 -> V_39 ) ;
F_16 ( & V_30 -> V_40 ) ;
F_17 ( V_4 , V_38 ) ;
F_18 ( & V_6 -> V_41 ) ;
F_19 ( & V_30 -> V_40 ) ;
}
static T_2 F_20 ( const struct V_3 * V_4 )
{
return F_21 ( 2 ) +
F_21 ( 2 ) +
F_21 ( 2 ) ;
}
int T_3 F_22 ( void )
{
return F_23 ( & V_42 ) ;
}
void T_4 F_24 ( void )
{
F_25 ( & V_42 ) ;
}
