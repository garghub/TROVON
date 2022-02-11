static T_1 int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_3 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_12 = F_4 ( V_13 ) ;
if ( F_5 ( V_12 ) ) {
V_3 = F_6 ( V_12 ) ;
goto V_14;
}
V_3 = F_7 ( V_2 , V_12 ) ;
if ( V_3 )
goto V_15;
V_3 = F_8 ( V_2 -> V_4 , V_2 , & V_16 ) ;
if ( V_3 < 0 )
goto V_17;
return 0 ;
V_17:
F_9 ( V_2 , V_12 ) ;
V_15:
F_10 ( V_12 ) ;
V_14:
return V_3 ;
}
static int F_11 ( struct V_18 * V_4 )
{
static struct V_1 V_19 = {
. V_20 = V_21 ,
. V_8 = V_22 ,
} ;
V_19 . V_23 = V_24 [ V_25 ] . V_26 ;
V_19 . V_27 = V_24 [ V_25 ] . V_28 ;
return F_12 ( V_4 , & V_19 , F_1 ) ;
}
static int F_11 ( struct V_18 * V_4 )
{
return 0 ;
}
static T_1 int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_14 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_29 = F_4 ( V_13 ) ;
if ( F_5 ( V_29 ) )
goto V_14;
V_3 = F_7 ( V_2 , V_29 ) ;
if ( V_3 )
goto V_15;
V_3 = F_8 ( V_2 -> V_4 , V_2 , & V_16 ) ;
if ( V_3 < 0 )
goto V_17;
return 0 ;
V_17:
F_9 ( V_2 , V_29 ) ;
V_15:
F_10 ( V_29 ) ;
V_14:
return V_3 ;
}
static int F_15 ( struct V_18 * V_4 )
{
static struct V_1 V_19 = {
. V_20 = V_30 ,
. V_8 = V_22 ,
} ;
V_19 . V_23 = V_24 [ V_31 ] . V_26 ;
V_19 . V_27 = V_24 [ V_31 ] . V_28 ;
return F_12 ( V_4 , & V_19 , F_13 ) ;
}
static int F_15 ( struct V_18 * V_4 )
{
return 0 ;
}
static int T_2 F_16 ( struct V_18 * V_4 )
{
struct V_32 * V_5 = V_4 -> V_5 ;
int V_33 ;
if ( ! F_17 ( V_4 -> V_5 ) ) {
F_18 ( & V_5 -> V_34 , L_1 ,
V_5 -> V_35 ) ;
return - V_36 ;
}
V_11 = F_19 ( V_4 -> V_5 , V_10 ) ;
if ( F_5 ( V_11 ) )
return F_6 ( V_11 ) ;
V_13 = F_20 ( L_2 ) ;
if ( F_5 ( V_13 ) ) {
V_33 = F_6 ( V_13 ) ;
goto V_37;
}
{
void * V_38 ;
V_38 = F_21 ( & V_16 , V_4 , & V_39 ) ;
if ( F_5 ( V_38 ) ) {
V_33 = F_6 ( V_38 ) ;
goto V_40;
}
}
V_33 = F_22 ( V_4 , V_24 ) ;
if ( F_23 ( V_33 < 0 ) )
goto V_41;
V_42 . V_43 = V_24 [ V_44 ] . V_28 ;
V_33 = F_11 ( V_4 ) ;
if ( F_23 ( V_33 < 0 ) )
goto V_41;
V_33 = F_15 ( V_4 ) ;
if ( F_23 ( V_33 < 0 ) )
goto V_41;
F_24 ( V_4 , & V_45 ) ;
F_25 ( & V_5 -> V_34 , V_46 L_3 ) ;
F_26 ( & V_16 ) ;
return 0 ;
V_41:
F_26 ( & V_16 ) ;
V_40:
F_27 ( V_13 ) ;
V_37:
F_28 ( V_11 ) ;
return V_33 ;
}
static int T_3 F_29 ( struct V_18 * V_4 )
{
#ifdef F_30
F_10 ( V_29 ) ;
#endif
#ifdef F_31
F_10 ( V_12 ) ;
#endif
F_27 ( V_13 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_47 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_47 ) ;
}
