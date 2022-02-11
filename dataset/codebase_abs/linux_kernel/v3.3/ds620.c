static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
T_1 V_7 , V_8 ;
V_8 = V_7 =
F_2 ( V_2 , V_9 ) ;
V_8 &= ~ V_10 ;
V_8 |= V_11 ;
if ( V_4 && V_4 -> V_12 == 1 )
V_8 &= ~ V_13 ;
else if ( V_4 && V_4 -> V_12 == 2 )
V_8 |= V_13 ;
else
V_8 &= ~ V_11 ;
V_8 |= V_14 | V_15 ;
if ( V_7 != V_8 )
F_3 ( V_2 , V_9 , V_8 ) ;
F_4 ( V_2 , V_16 ) ;
}
static struct V_17 * F_5 ( struct V_18 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
struct V_17 * V_19 = F_7 ( V_2 ) ;
struct V_17 * V_20 = V_19 ;
F_8 ( & V_19 -> V_21 ) ;
if ( F_9 ( V_22 , V_19 -> V_23 + V_24 + V_24 / 2 )
|| ! V_19 -> V_25 ) {
int V_26 ;
int V_27 ;
F_10 ( & V_2 -> V_5 , L_1 ) ;
for ( V_26 = 0 ; V_26 < F_11 ( V_19 -> V_28 ) ; V_26 ++ ) {
V_27 = F_2 ( V_2 ,
V_29 [ V_26 ] ) ;
if ( V_27 < 0 ) {
V_20 = F_12 ( V_27 ) ;
goto abort;
}
V_19 -> V_28 [ V_26 ] = V_27 ;
}
V_19 -> V_23 = V_22 ;
V_19 -> V_25 = 1 ;
}
abort:
F_13 ( & V_19 -> V_21 ) ;
return V_20 ;
}
static T_2 F_14 ( struct V_18 * V_5 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_33 * V_34 = F_15 ( V_31 ) ;
struct V_17 * V_19 = F_5 ( V_5 ) ;
if ( F_16 ( V_19 ) )
return F_17 ( V_19 ) ;
return sprintf ( V_32 , L_2 , ( ( V_19 -> V_28 [ V_34 -> V_35 ] / 8 ) * 625 ) / 10 ) ;
}
static T_2 F_18 ( struct V_18 * V_5 , struct V_30 * V_31 ,
const char * V_32 , T_3 V_36 )
{
int V_27 ;
long V_37 ;
struct V_33 * V_34 = F_15 ( V_31 ) ;
struct V_1 * V_2 = F_6 ( V_5 ) ;
struct V_17 * V_19 = F_7 ( V_2 ) ;
V_27 = F_19 ( V_32 , 10 , & V_37 ) ;
if ( V_27 )
return V_27 ;
V_37 = ( V_37 * 10 / 625 ) * 8 ;
F_8 ( & V_19 -> V_21 ) ;
V_19 -> V_28 [ V_34 -> V_35 ] = V_37 ;
F_3 ( V_2 , V_29 [ V_34 -> V_35 ] ,
V_19 -> V_28 [ V_34 -> V_35 ] ) ;
F_13 ( & V_19 -> V_21 ) ;
return V_36 ;
}
static T_2 F_20 ( struct V_18 * V_5 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_33 * V_34 = F_15 ( V_31 ) ;
struct V_17 * V_19 = F_5 ( V_5 ) ;
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_1 V_7 , V_8 ;
int V_27 ;
if ( F_16 ( V_19 ) )
return F_17 ( V_19 ) ;
V_27 = F_2 ( V_2 , V_9 ) ;
if ( V_27 < 0 )
return V_27 ;
V_8 = V_7 = V_27 ;
V_8 &= ~ V_34 -> V_35 ;
if ( V_7 != V_8 ) {
V_27 = F_3 ( V_2 , V_9 ,
V_8 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return sprintf ( V_32 , L_2 , ! ! ( V_7 & V_34 -> V_35 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
struct V_17 * V_19 ;
int V_40 ;
V_19 = F_22 ( sizeof( struct V_17 ) , V_41 ) ;
if ( ! V_19 ) {
V_40 = - V_42 ;
goto exit;
}
F_23 ( V_2 , V_19 ) ;
F_24 ( & V_19 -> V_21 ) ;
F_1 ( V_2 ) ;
V_40 = F_25 ( & V_2 -> V_5 . V_43 , & V_44 ) ;
if ( V_40 )
goto V_45;
V_19 -> V_46 = F_26 ( & V_2 -> V_5 ) ;
if ( F_16 ( V_19 -> V_46 ) ) {
V_40 = F_17 ( V_19 -> V_46 ) ;
goto V_47;
}
F_27 ( & V_2 -> V_5 , L_3 ) ;
return 0 ;
V_47:
F_28 ( & V_2 -> V_5 . V_43 , & V_44 ) ;
V_45:
F_29 ( V_19 ) ;
exit:
return V_40 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_17 * V_19 = F_7 ( V_2 ) ;
F_31 ( V_19 -> V_46 ) ;
F_28 ( & V_2 -> V_5 . V_43 , & V_44 ) ;
F_29 ( V_19 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_48 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_48 ) ;
}
