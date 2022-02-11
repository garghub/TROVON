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
error = F_3 ( V_4 -> V_12 ) ;
if ( error )
goto V_13;
if ( V_6 && V_6 [ 0 ] . V_14 == V_3 &&
V_6 [ 1 ] . V_14 == V_3 )
V_6 = NULL ;
V_8 . V_15 = V_16 | V_17 | V_18 ;
if ( V_6 ) {
if ( V_6 [ 0 ] . V_14 == V_2 )
V_8 . V_15 &= ~ V_18 ;
else if ( V_6 [ 0 ] . V_14 != V_3 ) {
V_8 . V_19 . V_20 = V_6 [ 0 ] . V_20 ;
V_8 . V_19 . V_14 = V_6 [ 0 ] . V_14 ;
V_8 . V_15 |= V_21 ;
}
if ( V_6 [ 1 ] . V_14 == V_2 )
V_8 . V_15 &= ~ V_17 ;
else if ( V_6 [ 1 ] . V_14 != V_3 ) {
V_8 . V_22 . V_20 = V_6 [ 1 ] . V_20 ;
V_8 . V_22 . V_14 = V_6 [ 1 ] . V_14 ;
V_8 . V_15 |= V_23 ;
}
V_8 . V_15 |= V_24 ;
} else {
error = - V_25 ;
if ( F_4 ( V_9 ) )
goto V_26;
if ( ! F_5 ( V_9 ) ) {
error = F_6 ( V_9 , V_27 ) ;
if ( error )
goto V_26;
}
}
F_7 ( & V_9 -> V_28 ) ;
error = F_8 ( V_4 -> V_10 , & V_8 ) ;
F_9 ( & V_9 -> V_28 ) ;
V_26:
F_10 ( V_4 -> V_12 ) ;
V_13:
return error ;
}
long F_11 ( int V_29 , const char T_1 * V_30 , struct V_5 * V_6 ,
int V_31 )
{
int error = - V_32 ;
if ( V_6 && ( ! F_1 ( V_6 [ 0 ] . V_14 ) ||
! F_1 ( V_6 [ 1 ] . V_14 ) ) ) {
goto V_13;
}
if ( V_31 & ~ V_33 )
goto V_13;
if ( V_30 == NULL && V_29 != V_34 ) {
struct V_35 V_36 ;
if ( V_31 & V_33 )
goto V_13;
V_36 = F_12 ( V_29 ) ;
error = - V_37 ;
if ( ! V_36 . V_38 )
goto V_13;
error = F_2 ( & V_36 . V_38 -> V_39 , V_6 ) ;
F_13 ( V_36 ) ;
} else {
struct V_4 V_4 ;
int V_40 = 0 ;
if ( ! ( V_31 & V_33 ) )
V_40 |= V_41 ;
error = F_14 ( V_29 , V_30 , V_40 , & V_4 ) ;
if ( error )
goto V_13;
error = F_2 ( & V_4 , V_6 ) ;
F_15 ( & V_4 ) ;
}
V_13:
return error ;
}
