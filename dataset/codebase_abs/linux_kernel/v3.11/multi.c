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
if ( F_5 ( V_12 ) )
return F_6 ( V_12 ) ;
V_3 = F_7 ( V_2 , V_12 ) ;
if ( V_3 )
goto V_14;
V_3 = F_8 ( V_2 -> V_4 , V_2 , & V_15 ) ;
if ( V_3 < 0 )
goto V_16;
return 0 ;
V_16:
F_9 ( V_2 , V_12 ) ;
V_14:
F_10 ( V_12 ) ;
return V_3 ;
}
static int F_11 ( struct V_17 * V_4 )
{
static struct V_1 V_18 = {
. V_19 = V_20 ,
. V_8 = V_21 ,
} ;
V_18 . V_22 = V_23 [ V_24 ] . V_25 ;
V_18 . V_26 = V_23 [ V_24 ] . V_27 ;
return F_12 ( V_4 , & V_18 , F_1 ) ;
}
static int F_11 ( struct V_17 * V_4 )
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
V_28 = F_4 ( V_13 ) ;
if ( F_5 ( V_28 ) )
return F_6 ( V_28 ) ;
V_3 = F_7 ( V_2 , V_28 ) ;
if ( V_3 )
goto V_14;
V_3 = F_8 ( V_2 -> V_4 , V_2 , & V_15 ) ;
if ( V_3 < 0 )
goto V_16;
return 0 ;
V_16:
F_9 ( V_2 , V_28 ) ;
V_14:
F_10 ( V_28 ) ;
return V_3 ;
}
static int F_15 ( struct V_17 * V_4 )
{
static struct V_1 V_18 = {
. V_19 = V_29 ,
. V_8 = V_21 ,
} ;
V_18 . V_22 = V_23 [ V_30 ] . V_25 ;
V_18 . V_26 = V_23 [ V_30 ] . V_27 ;
return F_12 ( V_4 , & V_18 , F_13 ) ;
}
static int F_15 ( struct V_17 * V_4 )
{
return 0 ;
}
static int T_2 F_16 ( struct V_17 * V_4 )
{
struct V_31 * V_5 = V_4 -> V_5 ;
int V_32 ;
if ( ! F_17 ( V_4 -> V_5 ) ) {
F_18 ( & V_5 -> V_33 , L_1 ,
V_5 -> V_34 ) ;
return - V_35 ;
}
V_11 = F_19 ( V_4 -> V_5 , V_36 , V_37 , V_10 ,
V_38 ) ;
if ( F_5 ( V_11 ) )
return F_6 ( V_11 ) ;
V_13 = F_20 ( L_2 ) ;
if ( F_5 ( V_13 ) ) {
V_32 = F_6 ( V_13 ) ;
goto V_39;
}
{
void * V_40 ;
V_40 = F_21 ( & V_15 , V_4 , & V_41 ) ;
if ( F_5 ( V_40 ) ) {
V_32 = F_6 ( V_40 ) ;
goto V_42;
}
}
V_32 = F_22 ( V_4 , V_23 ) ;
if ( F_23 ( V_32 < 0 ) )
goto V_43;
V_44 . V_45 = V_23 [ V_46 ] . V_27 ;
V_32 = F_11 ( V_4 ) ;
if ( F_23 ( V_32 < 0 ) )
goto V_43;
V_32 = F_15 ( V_4 ) ;
if ( F_23 ( V_32 < 0 ) )
goto V_43;
F_24 ( V_4 , & V_47 ) ;
F_25 ( & V_5 -> V_33 , V_48 L_3 ) ;
F_26 ( & V_15 ) ;
return 0 ;
V_43:
F_26 ( & V_15 ) ;
V_42:
F_27 ( V_13 ) ;
V_39:
F_28 ( V_11 ) ;
return V_32 ;
}
static int T_3 F_29 ( struct V_17 * V_4 )
{
#ifdef F_30
F_10 ( V_28 ) ;
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
return F_33 ( & V_49 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_49 ) ;
}
