static bool F_1 ( long V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return true ;
return V_1 >= 0 && V_1 <= 999999999 ;
}
static int F_2 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
int error ;
struct V_7 V_8 ;
struct V_9 * V_9 = V_4 -> V_10 -> V_11 ;
struct V_9 * V_12 = NULL ;
error = F_3 ( V_4 -> V_13 ) ;
if ( error )
goto V_14;
if ( V_6 && V_6 [ 0 ] . V_15 == V_3 &&
V_6 [ 1 ] . V_15 == V_3 )
V_6 = NULL ;
V_8 . V_16 = V_17 | V_18 | V_19 ;
if ( V_6 ) {
if ( V_6 [ 0 ] . V_15 == V_2 )
V_8 . V_16 &= ~ V_19 ;
else if ( V_6 [ 0 ] . V_15 != V_3 ) {
V_8 . V_20 . V_21 = V_6 [ 0 ] . V_21 ;
V_8 . V_20 . V_15 = V_6 [ 0 ] . V_15 ;
V_8 . V_16 |= V_22 ;
}
if ( V_6 [ 1 ] . V_15 == V_2 )
V_8 . V_16 &= ~ V_18 ;
else if ( V_6 [ 1 ] . V_15 != V_3 ) {
V_8 . V_23 . V_21 = V_6 [ 1 ] . V_21 ;
V_8 . V_23 . V_15 = V_6 [ 1 ] . V_15 ;
V_8 . V_16 |= V_24 ;
}
V_8 . V_16 |= V_25 ;
} else {
error = - V_26 ;
if ( F_4 ( V_9 ) )
goto V_27;
if ( ! F_5 ( V_9 ) ) {
error = F_6 ( V_9 , V_28 ) ;
if ( error )
goto V_27;
}
}
V_29:
F_7 ( & V_9 -> V_30 ) ;
error = F_8 ( V_4 -> V_10 , & V_8 , & V_12 ) ;
F_9 ( & V_9 -> V_30 ) ;
if ( V_12 ) {
error = F_10 ( & V_12 ) ;
if ( ! error )
goto V_29;
}
V_27:
F_11 ( V_4 -> V_13 ) ;
V_14:
return error ;
}
long F_12 ( int V_31 , const char T_1 * V_32 , struct V_5 * V_6 ,
int V_33 )
{
int error = - V_34 ;
if ( V_6 && ( ! F_1 ( V_6 [ 0 ] . V_15 ) ||
! F_1 ( V_6 [ 1 ] . V_15 ) ) ) {
goto V_14;
}
if ( V_33 & ~ V_35 )
goto V_14;
if ( V_32 == NULL && V_31 != V_36 ) {
struct V_37 V_38 ;
if ( V_33 & V_35 )
goto V_14;
V_38 = F_13 ( V_31 ) ;
error = - V_39 ;
if ( ! V_38 . V_40 )
goto V_14;
error = F_2 ( & V_38 . V_40 -> V_41 , V_6 ) ;
F_14 ( V_38 ) ;
} else {
struct V_4 V_4 ;
int V_42 = 0 ;
if ( ! ( V_33 & V_35 ) )
V_42 |= V_43 ;
V_44:
error = F_15 ( V_31 , V_32 , V_42 , & V_4 ) ;
if ( error )
goto V_14;
error = F_2 ( & V_4 , V_6 ) ;
F_16 ( & V_4 ) ;
if ( F_17 ( error , V_42 ) ) {
V_42 |= V_45 ;
goto V_44;
}
}
V_14:
return error ;
}
