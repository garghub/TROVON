static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_5 )
{
return F_5 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
T_2 V_10 , V_11 ;
V_11 = V_10 =
F_3 ( F_2 ( V_2 , V_12 ) ) ;
V_11 &= ~ V_13 ;
V_11 |= V_14 ;
if ( V_7 && V_7 -> V_15 == 1 )
V_11 &= ~ V_16 ;
else if ( V_7 && V_7 -> V_15 == 2 )
V_11 |= V_16 ;
else
V_11 &= ~ V_14 ;
V_11 |= V_17 | V_18 ;
if ( V_10 != V_11 )
F_5 ( V_2 , V_12 ,
F_3 ( V_11 ) ) ;
F_7 ( V_2 , V_19 ) ;
}
static struct V_20 * F_8 ( struct V_21 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_20 * V_22 = F_10 ( V_2 ) ;
struct V_20 * V_4 = V_22 ;
F_11 ( & V_22 -> V_23 ) ;
if ( F_12 ( V_24 , V_22 -> V_25 + V_26 + V_26 / 2 )
|| ! V_22 -> V_27 ) {
int V_28 ;
int V_29 ;
F_13 ( & V_2 -> V_8 , L_1 ) ;
for ( V_28 = 0 ; V_28 < F_14 ( V_22 -> V_30 ) ; V_28 ++ ) {
V_29 = F_1 ( V_2 ,
V_31 [ V_28 ] ) ;
if ( V_29 < 0 ) {
V_4 = F_15 ( V_29 ) ;
goto abort;
}
V_22 -> V_30 [ V_28 ] = V_29 ;
}
V_22 -> V_25 = V_24 ;
V_22 -> V_27 = 1 ;
}
abort:
F_16 ( & V_22 -> V_23 ) ;
return V_4 ;
}
static T_3 F_17 ( struct V_21 * V_8 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_35 * V_36 = F_18 ( V_33 ) ;
struct V_20 * V_22 = F_8 ( V_8 ) ;
if ( F_19 ( V_22 ) )
return F_20 ( V_22 ) ;
return sprintf ( V_34 , L_2 , ( ( V_22 -> V_30 [ V_36 -> V_37 ] / 8 ) * 625 ) / 10 ) ;
}
static T_3 F_21 ( struct V_21 * V_8 , struct V_32 * V_33 ,
const char * V_34 , T_4 V_38 )
{
int V_29 ;
long V_39 ;
struct V_35 * V_36 = F_18 ( V_33 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_20 * V_22 = F_10 ( V_2 ) ;
V_29 = F_22 ( V_34 , 10 , & V_39 ) ;
if ( V_29 )
return V_29 ;
V_39 = ( V_39 * 10 / 625 ) * 8 ;
F_11 ( & V_22 -> V_23 ) ;
V_22 -> V_30 [ V_36 -> V_37 ] = V_39 ;
F_4 ( V_2 , V_31 [ V_36 -> V_37 ] ,
V_22 -> V_30 [ V_36 -> V_37 ] ) ;
F_16 ( & V_22 -> V_23 ) ;
return V_38 ;
}
static T_3 F_23 ( struct V_21 * V_8 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_35 * V_36 = F_18 ( V_33 ) ;
struct V_20 * V_22 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
T_2 V_10 , V_11 ;
int V_29 ;
if ( F_19 ( V_22 ) )
return F_20 ( V_22 ) ;
V_29 = F_2 ( V_2 , V_12 ) ;
if ( V_29 < 0 )
return V_29 ;
V_10 = F_3 ( V_29 ) ;
V_11 = V_10 ;
V_11 &= ~ V_36 -> V_37 ;
if ( V_10 != V_11 ) {
V_29 = F_5 ( V_2 , V_12 ,
F_3 ( V_11 ) ) ;
if ( V_29 < 0 )
return V_29 ;
}
return sprintf ( V_34 , L_2 , ! ! ( V_10 & V_36 -> V_37 ) ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_20 * V_22 ;
int V_42 ;
V_22 = F_25 ( sizeof( struct V_20 ) , V_43 ) ;
if ( ! V_22 ) {
V_42 = - V_44 ;
goto exit;
}
F_26 ( V_2 , V_22 ) ;
F_27 ( & V_22 -> V_23 ) ;
F_6 ( V_2 ) ;
V_42 = F_28 ( & V_2 -> V_8 . V_45 , & V_46 ) ;
if ( V_42 )
goto V_47;
V_22 -> V_48 = F_29 ( & V_2 -> V_8 ) ;
if ( F_19 ( V_22 -> V_48 ) ) {
V_42 = F_20 ( V_22 -> V_48 ) ;
goto V_49;
}
F_30 ( & V_2 -> V_8 , L_3 ) ;
return 0 ;
V_49:
F_31 ( & V_2 -> V_8 . V_45 , & V_46 ) ;
V_47:
F_32 ( V_22 ) ;
exit:
return V_42 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_22 = F_10 ( V_2 ) ;
F_34 ( V_22 -> V_48 ) ;
F_31 ( & V_2 -> V_8 . V_45 , & V_46 ) ;
F_32 ( V_22 ) ;
return 0 ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_50 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_50 ) ;
}
