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
F_7 ( V_9 ) ;
error = F_8 ( V_4 -> V_10 , & V_8 , & V_12 ) ;
F_9 ( V_9 ) ;
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
long F_12 ( int V_30 , const char T_1 * V_31 , struct V_5 * V_6 ,
int V_32 )
{
int error = - V_33 ;
if ( V_6 && ( ! F_1 ( V_6 [ 0 ] . V_15 ) ||
! F_1 ( V_6 [ 1 ] . V_15 ) ) ) {
goto V_14;
}
if ( V_32 & ~ V_34 )
goto V_14;
if ( V_31 == NULL && V_30 != V_35 ) {
struct V_36 V_37 ;
if ( V_32 & V_34 )
goto V_14;
V_37 = F_13 ( V_30 ) ;
error = - V_38 ;
if ( ! V_37 . V_39 )
goto V_14;
error = F_2 ( & V_37 . V_39 -> V_40 , V_6 ) ;
F_14 ( V_37 ) ;
} else {
struct V_4 V_4 ;
int V_41 = 0 ;
if ( ! ( V_32 & V_34 ) )
V_41 |= V_42 ;
V_43:
error = F_15 ( V_30 , V_31 , V_41 , & V_4 ) ;
if ( error )
goto V_14;
error = F_2 ( & V_4 , V_6 ) ;
F_16 ( & V_4 ) ;
if ( F_17 ( error , V_41 ) ) {
V_41 |= V_44 ;
goto V_43;
}
}
V_14:
return error ;
}
