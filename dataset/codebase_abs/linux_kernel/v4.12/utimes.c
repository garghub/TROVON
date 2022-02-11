static bool F_1 ( long V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return true ;
return V_1 >= 0 && V_1 <= 999999999 ;
}
static int F_2 ( const struct V_4 * V_4 , struct V_5 * V_6 )
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
V_8 . V_16 |= V_26 ;
}
V_27:
F_4 ( V_9 ) ;
error = F_5 ( V_4 -> V_10 , & V_8 , & V_12 ) ;
F_6 ( V_9 ) ;
if ( V_12 ) {
error = F_7 ( & V_12 ) ;
if ( ! error )
goto V_27;
}
F_8 ( V_4 -> V_13 ) ;
V_14:
return error ;
}
long F_9 ( int V_28 , const char T_1 * V_29 , struct V_5 * V_6 ,
int V_30 )
{
int error = - V_31 ;
if ( V_6 && ( ! F_1 ( V_6 [ 0 ] . V_15 ) ||
! F_1 ( V_6 [ 1 ] . V_15 ) ) ) {
goto V_14;
}
if ( V_30 & ~ V_32 )
goto V_14;
if ( V_29 == NULL && V_28 != V_33 ) {
struct V_34 V_35 ;
if ( V_30 & V_32 )
goto V_14;
V_35 = F_10 ( V_28 ) ;
error = - V_36 ;
if ( ! V_35 . V_37 )
goto V_14;
error = F_2 ( & V_35 . V_37 -> V_38 , V_6 ) ;
F_11 ( V_35 ) ;
} else {
struct V_4 V_4 ;
int V_39 = 0 ;
if ( ! ( V_30 & V_32 ) )
V_39 |= V_40 ;
V_41:
error = F_12 ( V_28 , V_29 , V_39 , & V_4 ) ;
if ( error )
goto V_14;
error = F_2 ( & V_4 , V_6 ) ;
F_13 ( & V_4 ) ;
if ( F_14 ( error , V_39 ) ) {
V_39 |= V_42 ;
goto V_41;
}
}
V_14:
return error ;
}
