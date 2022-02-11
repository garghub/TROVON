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
static int F_5 ( struct V_3 * V_4 , struct V_17 * V_18 [] ,
struct V_17 * V_19 [] ,
struct V_20 * V_21 )
{
T_1 V_22 , V_23 ;
int V_24 = 0 ;
if ( V_19 [ V_13 ] ) {
V_22 = F_6 ( V_19 [ V_13 ] ) ;
if ( V_22 == V_25 )
V_24 = F_7 ( V_4 , L_1 ) ;
else if ( V_22 == V_26 )
V_24 = F_7 ( V_4 , L_2 ) ;
else
V_24 = - V_27 ;
if ( V_24 < 0 )
goto V_28;
}
if ( V_19 [ V_15 ] ) {
V_23 = F_6 ( V_19 [ V_15 ] ) ;
F_8 ( V_4 , V_23 ) ;
}
V_28:
return V_24 ;
}
static int F_9 ( struct V_29 * V_30 , struct V_3 * V_4 ,
struct V_17 * V_18 [] , struct V_17 * V_19 [] ,
struct V_20 * V_21 )
{
struct V_3 * V_31 ;
struct V_5 * V_32 ;
T_1 V_33 ;
int V_34 ;
if ( ! V_18 [ V_35 ] )
return - V_27 ;
V_31 = F_10 ( V_30 , F_11 ( V_18 [ V_35 ] ) ) ;
if ( ! V_31 || V_31 -> type != V_36 )
return - V_37 ;
V_32 = F_2 ( V_31 ) ;
if ( F_4 ( V_38 , & V_32 -> V_12 ) ) {
F_12 ( V_32 , L_3 ) ;
return - V_27 ;
}
if ( ! V_19 || ! V_19 [ V_8 ] ) {
F_13 ( V_32 , L_4 ) ;
V_33 = V_32 -> V_9 ;
} else
V_33 = F_6 ( V_19 [ V_8 ] ) ;
if ( V_33 == 0 || V_33 == 0x8000 )
return - V_27 ;
V_33 |= 0x8000 ;
V_34 = F_14 ( V_32 , F_2 ( V_4 ) ,
V_33 , V_39 ) ;
if ( ! V_34 && V_19 )
V_34 = F_5 ( V_4 , V_18 , V_19 , V_21 ) ;
return V_34 ;
}
static void F_15 ( struct V_3 * V_4 , struct V_40 * V_41 )
{
struct V_5 * V_6 , * V_32 ;
V_6 = F_2 ( V_4 ) ;
V_32 = F_2 ( V_6 -> V_42 ) ;
F_16 ( & V_32 -> V_43 ) ;
F_17 ( V_4 , V_41 ) ;
F_18 ( & V_6 -> V_44 ) ;
F_19 ( & V_32 -> V_43 ) ;
}
static T_2 F_20 ( const struct V_3 * V_4 )
{
return F_21 ( 2 ) +
F_21 ( 2 ) +
F_21 ( 2 ) ;
}
int T_3 F_22 ( void )
{
return F_23 ( & V_45 ) ;
}
void T_4 F_24 ( void )
{
F_25 ( & V_45 ) ;
}
