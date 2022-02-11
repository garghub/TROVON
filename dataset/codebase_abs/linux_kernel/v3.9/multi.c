static T_1 int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_3 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_11 = F_4 ( V_12 ) ;
if ( F_5 ( V_11 ) )
goto V_13;
V_3 = F_6 ( V_2 , V_11 ) ;
if ( V_3 )
goto V_14;
V_3 = F_7 ( V_2 -> V_4 , V_2 , & V_15 ) ;
if ( V_3 < 0 )
goto V_16;
return 0 ;
V_16:
F_8 ( V_2 , V_11 ) ;
V_14:
F_9 ( V_11 ) ;
V_13:
return V_3 ;
}
static int F_10 ( struct V_17 * V_4 )
{
static struct V_1 V_18 = {
. V_19 = V_20 ,
. V_8 = V_21 ,
} ;
V_18 . V_22 = V_23 [ V_24 ] . V_25 ;
V_18 . V_26 = V_23 [ V_24 ] . V_27 ;
return F_11 ( V_4 , & V_18 , F_1 ) ;
}
static int F_10 ( struct V_17 * V_4 )
{
return 0 ;
}
static T_1 int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_13 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_28 = F_4 ( V_12 ) ;
if ( F_5 ( V_28 ) )
goto V_13;
V_3 = F_6 ( V_2 , V_28 ) ;
if ( V_3 )
goto V_14;
V_3 = F_7 ( V_2 -> V_4 , V_2 , & V_15 ) ;
if ( V_3 < 0 )
goto V_16;
return 0 ;
V_16:
F_8 ( V_2 , V_28 ) ;
V_14:
F_9 ( V_28 ) ;
V_13:
return V_3 ;
}
static int F_14 ( struct V_17 * V_4 )
{
static struct V_1 V_18 = {
. V_19 = V_29 ,
. V_8 = V_21 ,
} ;
V_18 . V_22 = V_23 [ V_30 ] . V_25 ;
V_18 . V_26 = V_23 [ V_30 ] . V_27 ;
return F_11 ( V_4 , & V_18 , F_12 ) ;
}
static int F_14 ( struct V_17 * V_4 )
{
return 0 ;
}
static int T_2 F_15 ( struct V_17 * V_4 )
{
struct V_31 * V_5 = V_4 -> V_5 ;
struct V_32 * V_33 ;
int V_34 ;
if ( ! F_16 ( V_4 -> V_5 ) ) {
F_17 ( & V_5 -> V_35 , L_1 ,
V_5 -> V_36 ) ;
return - V_37 ;
}
V_34 = F_18 ( V_4 -> V_5 , V_10 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_19 ( & V_38 ) ;
if ( V_34 < 0 )
goto V_39;
V_12 = F_20 ( L_2 ) ;
if ( F_5 ( V_12 ) ) {
V_34 = F_21 ( V_12 ) ;
goto V_40;
}
V_33 = F_22 ( V_12 , struct V_32 , V_41 ) ;
V_33 -> V_42 = V_38 ;
{
void * V_43 ;
V_43 = F_23 ( & V_15 , V_4 , & V_44 ) ;
if ( F_5 ( V_43 ) ) {
V_34 = F_21 ( V_43 ) ;
goto V_45;
}
}
V_34 = F_24 ( V_4 , V_23 ) ;
if ( F_25 ( V_34 < 0 ) )
goto V_46;
V_47 . V_48 = V_23 [ V_49 ] . V_27 ;
V_34 = F_10 ( V_4 ) ;
if ( F_25 ( V_34 < 0 ) )
goto V_46;
V_34 = F_14 ( V_4 ) ;
if ( F_25 ( V_34 < 0 ) )
goto V_46;
F_26 ( V_4 , & V_50 ) ;
F_27 ( & V_5 -> V_35 , V_51 L_3 ) ;
F_28 ( & V_15 ) ;
return 0 ;
V_46:
F_28 ( & V_15 ) ;
V_45:
F_29 ( V_12 ) ;
V_40:
F_30 ( V_38 ) ;
V_39:
F_31 () ;
return V_34 ;
}
static int T_3 F_32 ( struct V_17 * V_4 )
{
#ifdef F_33
F_9 ( V_28 ) ;
#endif
#ifdef F_34
F_9 ( V_11 ) ;
#endif
F_29 ( V_12 ) ;
F_30 ( V_38 ) ;
F_31 () ;
return 0 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_52 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_52 ) ;
}
