static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
T_1 V_6 , V_7 ;
V_7 = V_6 =
F_3 ( V_2 , V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= V_10 ;
if ( V_4 && V_4 -> V_11 == 1 )
V_7 &= ~ V_12 ;
else if ( V_4 && V_4 -> V_11 == 2 )
V_7 |= V_12 ;
else
V_7 &= ~ V_10 ;
V_7 |= V_13 | V_14 ;
if ( V_6 != V_7 )
F_4 ( V_2 , V_8 , V_7 ) ;
F_5 ( V_2 , V_15 ) ;
}
static struct V_16 * F_6 ( struct V_17 * V_5 )
{
struct V_16 * V_18 = F_7 ( V_5 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_16 * V_19 = V_18 ;
F_8 ( & V_18 -> V_20 ) ;
if ( F_9 ( V_21 , V_18 -> V_22 + V_23 + V_23 / 2 )
|| ! V_18 -> V_24 ) {
int V_25 ;
int V_26 ;
F_10 ( & V_2 -> V_5 , L_1 ) ;
for ( V_25 = 0 ; V_25 < F_11 ( V_18 -> V_27 ) ; V_25 ++ ) {
V_26 = F_3 ( V_2 ,
V_28 [ V_25 ] ) ;
if ( V_26 < 0 ) {
V_19 = F_12 ( V_26 ) ;
goto abort;
}
V_18 -> V_27 [ V_25 ] = V_26 ;
}
V_18 -> V_22 = V_21 ;
V_18 -> V_24 = 1 ;
}
abort:
F_13 ( & V_18 -> V_20 ) ;
return V_19 ;
}
static T_2 F_14 ( struct V_17 * V_5 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_32 * V_33 = F_15 ( V_30 ) ;
struct V_16 * V_18 = F_6 ( V_5 ) ;
if ( F_16 ( V_18 ) )
return F_17 ( V_18 ) ;
return sprintf ( V_31 , L_2 , ( ( V_18 -> V_27 [ V_33 -> V_34 ] / 8 ) * 625 ) / 10 ) ;
}
static T_2 F_18 ( struct V_17 * V_5 , struct V_29 * V_30 ,
const char * V_31 , T_3 V_35 )
{
int V_26 ;
long V_36 ;
struct V_32 * V_33 = F_15 ( V_30 ) ;
struct V_16 * V_18 = F_7 ( V_5 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
V_26 = F_19 ( V_31 , 10 , & V_36 ) ;
if ( V_26 )
return V_26 ;
V_36 = ( V_36 * 10 / 625 ) * 8 ;
F_8 ( & V_18 -> V_20 ) ;
V_18 -> V_27 [ V_33 -> V_34 ] = V_36 ;
F_4 ( V_2 , V_28 [ V_33 -> V_34 ] ,
V_18 -> V_27 [ V_33 -> V_34 ] ) ;
F_13 ( & V_18 -> V_20 ) ;
return V_35 ;
}
static T_2 F_20 ( struct V_17 * V_5 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_32 * V_33 = F_15 ( V_30 ) ;
struct V_16 * V_18 = F_6 ( V_5 ) ;
struct V_1 * V_2 ;
T_1 V_6 , V_7 ;
int V_26 ;
if ( F_16 ( V_18 ) )
return F_17 ( V_18 ) ;
V_2 = V_18 -> V_2 ;
V_26 = F_3 ( V_2 , V_8 ) ;
if ( V_26 < 0 )
return V_26 ;
V_7 = V_6 = V_26 ;
V_7 &= ~ V_33 -> V_34 ;
if ( V_6 != V_7 ) {
V_26 = F_4 ( V_2 , V_8 ,
V_7 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return sprintf ( V_31 , L_2 , ! ! ( V_6 & V_33 -> V_34 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_17 * V_5 = & V_2 -> V_5 ;
struct V_17 * V_39 ;
struct V_16 * V_18 ;
V_18 = F_22 ( V_5 , sizeof( struct V_16 ) , V_40 ) ;
if ( ! V_18 )
return - V_41 ;
V_18 -> V_2 = V_2 ;
F_23 ( & V_18 -> V_20 ) ;
F_1 ( V_2 ) ;
V_39 = F_24 ( V_5 , V_2 -> V_42 ,
V_18 , V_43 ) ;
return F_25 ( V_39 ) ;
}
