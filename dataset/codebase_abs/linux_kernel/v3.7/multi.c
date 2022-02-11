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
V_3 = F_4 ( V_2 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_2 -> V_4 , V_2 , & V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_6 ( struct V_12 * V_4 )
{
static struct V_1 V_13 = {
. V_14 = V_15 ,
. V_8 = V_16 ,
} ;
V_13 . V_17 = V_18 [ V_19 ] . V_20 ;
V_13 . V_21 = V_18 [ V_19 ] . V_22 ;
return F_7 ( V_4 , & V_13 , F_1 ) ;
}
static int F_6 ( struct V_12 * V_4 )
{
return 0 ;
}
static T_1 int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_3 = F_9 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_2 -> V_4 , V_2 , & V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_4 )
{
static struct V_1 V_13 = {
. V_14 = V_23 ,
. V_8 = V_16 ,
} ;
V_13 . V_17 = V_18 [ V_24 ] . V_20 ;
V_13 . V_21 = V_18 [ V_24 ] . V_22 ;
return F_7 ( V_4 , & V_13 , F_8 ) ;
}
static int F_10 ( struct V_12 * V_4 )
{
return 0 ;
}
static int T_2 F_11 ( struct V_12 * V_4 )
{
struct V_25 * V_5 = V_4 -> V_5 ;
int V_26 ;
if ( ! F_12 ( V_4 -> V_5 ) ) {
F_13 ( & V_5 -> V_27 , L_1 ,
V_5 -> V_28 ) ;
return - V_29 ;
}
V_26 = F_14 ( V_4 -> V_5 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_15 ( V_4 -> V_5 , 1 ) ;
if ( V_26 < 0 )
goto V_30;
{
void * V_31 ;
V_31 = F_16 ( & V_11 , V_4 , & V_32 ) ;
if ( F_17 ( V_31 ) ) {
V_26 = F_18 ( V_31 ) ;
goto V_33;
}
}
V_26 = F_19 ( V_4 , V_18 ) ;
if ( F_20 ( V_26 < 0 ) )
goto V_34;
V_35 . V_36 = V_18 [ V_37 ] . V_22 ;
V_26 = F_6 ( V_4 ) ;
if ( F_20 ( V_26 < 0 ) )
goto V_34;
V_26 = F_10 ( V_4 ) ;
if ( F_20 ( V_26 < 0 ) )
goto V_34;
F_21 ( V_4 , & V_38 ) ;
F_22 ( & V_5 -> V_27 , V_39 L_2 ) ;
F_23 ( & V_11 ) ;
return 0 ;
V_34:
F_23 ( & V_11 ) ;
V_33:
F_24 () ;
V_30:
F_25 () ;
return V_26 ;
}
static int T_3 F_26 ( struct V_12 * V_4 )
{
F_24 () ;
F_25 () ;
return 0 ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_40 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_40 ) ;
}
