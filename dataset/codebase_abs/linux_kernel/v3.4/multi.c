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
int V_26 , V_27 ;
if ( ! F_12 ( V_4 -> V_5 ) ) {
F_13 ( & V_5 -> V_28 , L_1 ,
V_5 -> V_29 ) ;
return - V_30 ;
}
V_26 = F_14 ( V_4 -> V_5 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_15 ( V_4 -> V_5 , 1 ) ;
if ( V_26 < 0 )
goto V_31;
{
void * V_32 ;
V_32 = F_16 ( & V_11 , V_4 , & V_33 ) ;
if ( F_17 ( V_32 ) ) {
V_26 = F_18 ( V_32 ) ;
goto V_34;
}
}
V_27 = F_19 ( V_5 ) ;
if ( V_27 >= 0 ) {
V_35 . V_36 = F_20 ( 0x0300 | V_27 ) ;
} else {
F_21 ( V_4 , L_2 , V_5 -> V_29 ) ;
V_35 . V_36 = F_20 ( 0x0300 | 0x0099 ) ;
}
V_26 = F_22 ( V_4 , V_18 ) ;
if ( F_23 ( V_26 < 0 ) )
goto V_37;
V_26 = F_6 ( V_4 ) ;
if ( F_23 ( V_26 < 0 ) )
goto V_37;
V_26 = F_10 ( V_4 ) ;
if ( F_23 ( V_26 < 0 ) )
goto V_37;
F_24 ( & V_5 -> V_28 , V_38 L_3 ) ;
F_25 ( & V_11 ) ;
return 0 ;
V_37:
F_25 ( & V_11 ) ;
V_34:
F_26 () ;
V_31:
F_27 () ;
return V_26 ;
}
static int T_3 F_28 ( struct V_12 * V_4 )
{
F_26 () ;
F_27 () ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_39 , F_11 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_39 ) ;
}
