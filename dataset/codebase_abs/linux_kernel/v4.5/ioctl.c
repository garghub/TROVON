static int F_1 ( struct V_1 * V_1 , int T_1 * V_2 )
{
struct V_3 * V_3 = V_1 -> V_4 . V_3 ;
struct V_5 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 -> V_8 ) ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_9 * V_12 = V_7 -> V_13 ;
T_2 V_14 = ( unsigned long ) V_3 -> V_15 ;
if ( ! F_4 ( V_16 ) )
return - V_17 ;
F_5 ( & V_7 -> V_18 ) ;
V_10 -> V_19 [ 0 ] = V_12 -> V_19 [ 0 ] =
F_6 ( F_7 ( V_3 ) ) ;
V_10 -> V_19 [ 1 ] = V_12 -> V_19 [ 1 ] = F_6 ( V_14 ) ;
V_10 -> V_19 [ 5 ] = V_12 -> V_19 [ 5 ] =
F_6 ( F_7 ( V_3 ) ) ;
F_8 ( & V_7 -> V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , int T_1 * V_2 )
{
struct V_5 * V_5 = F_10 ( V_1 ) ;
struct V_20 * V_21 = F_11 ( V_5 ) ;
unsigned int V_22 = 0 ;
if ( V_5 -> V_23 & V_24 )
V_22 |= V_25 ;
if ( V_5 -> V_23 & V_26 )
V_22 |= V_27 ;
if ( V_21 -> V_28 & V_29 )
V_22 |= V_30 ;
return F_12 ( V_22 , V_2 ) ;
}
static int F_13 ( struct V_1 * V_1 , int T_1 * V_2 )
{
struct V_5 * V_5 = F_10 ( V_1 ) ;
struct V_20 * V_21 = F_11 ( V_5 ) ;
unsigned int V_22 , V_31 = 0 ;
int V_32 = 0 ;
V_32 = F_14 ( V_1 ) ;
if ( V_32 )
goto V_33;
if ( ! F_15 ( V_5 ) ) {
V_32 = - V_34 ;
goto V_35;
}
if ( F_16 ( V_22 , V_2 ) ) {
V_32 = - V_36 ;
goto V_35;
}
F_17 ( V_5 ) ;
if ( ( V_22 & ( V_25 | V_27 ) ) ||
V_5 -> V_23 & ( V_24 | V_26 ) ) {
if ( ! F_4 ( V_37 ) ) {
V_32 = - V_17 ;
goto V_38;
}
}
if ( V_22 & ~ ( V_25 | V_27 | V_30 ) ) {
V_32 = - V_39 ;
goto V_38;
}
if ( V_22 & V_25 )
V_31 |= V_24 ;
if ( V_22 & V_27 )
V_31 |= V_26 ;
F_18 ( V_5 , V_31 , V_24 | V_26 ) ;
if ( V_22 & V_30 )
V_21 -> V_28 |= V_29 ;
else
V_21 -> V_28 &= ~ V_29 ;
V_5 -> V_40 = V_41 ;
F_19 ( V_5 ) ;
V_38:
F_20 ( V_5 ) ;
V_35:
F_21 ( V_1 ) ;
V_33:
return V_32 ;
}
long F_22 ( struct V_1 * V_1 , unsigned int V_42 , unsigned long V_43 )
{
void T_1 * V_44 = ( void T_1 * ) V_43 ;
switch ( V_42 ) {
case V_45 :
return F_9 ( V_1 , V_44 ) ;
case V_46 :
return F_13 ( V_1 , V_44 ) ;
case V_47 :
return F_1 ( V_1 , V_44 ) ;
default:
return - V_48 ;
}
}
