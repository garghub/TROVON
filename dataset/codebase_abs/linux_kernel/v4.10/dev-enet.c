static T_1 void F_1 ( void )
{
if ( F_2 () )
V_1 = V_2 ;
else
V_1 = V_3 ;
}
static int T_1 F_3 ( void )
{
int V_4 , V_5 ;
if ( V_6 )
return 0 ;
F_1 () ;
V_7 [ 0 ] . V_8 = F_4 ( V_9 ) ;
V_7 [ 0 ] . V_10 = V_7 [ 0 ] . V_8 ;
if ( F_2 () )
V_7 [ 0 ] . V_10 += ( V_11 ) - 1 ;
else
V_7 [ 0 ] . V_10 += ( V_12 ) - 1 ;
if ( F_5 () || F_6 () || F_7 () )
V_5 = 32 ;
else if ( F_2 () )
V_5 = 8 ;
else
V_5 = 16 ;
V_7 [ 1 ] . V_8 = F_4 ( V_13 ) ;
V_7 [ 1 ] . V_10 = V_7 [ 1 ] . V_8 ;
V_7 [ 1 ] . V_10 += F_8 ( V_5 ) - 1 ;
V_7 [ 2 ] . V_8 = F_4 ( V_14 ) ;
V_7 [ 2 ] . V_10 = V_7 [ 2 ] . V_8 ;
V_7 [ 2 ] . V_10 += F_9 ( V_5 ) - 1 ;
V_4 = F_10 ( & V_15 ) ;
if ( V_4 )
return V_4 ;
V_6 = 1 ;
return 0 ;
}
int T_1 F_11 ( int V_16 ,
const struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_17 * V_21 ;
int V_4 ;
if ( V_16 > 1 )
return - V_22 ;
if ( V_16 == 1 && ( F_12 () || F_2 () ) )
return - V_22 ;
V_4 = F_3 () ;
if ( V_4 )
return V_4 ;
if ( V_16 == 0 ) {
V_23 [ 0 ] . V_8 = F_4 ( V_24 ) ;
V_23 [ 0 ] . V_10 = V_23 [ 0 ] . V_8 ;
V_23 [ 0 ] . V_10 += V_25 - 1 ;
V_23 [ 1 ] . V_8 = F_13 ( V_26 ) ;
V_23 [ 2 ] . V_8 = F_13 ( V_27 ) ;
V_23 [ 3 ] . V_8 = F_13 ( V_28 ) ;
V_20 = & V_29 ;
} else {
V_30 [ 0 ] . V_8 = F_4 ( V_31 ) ;
V_30 [ 0 ] . V_10 = V_30 [ 0 ] . V_8 ;
V_30 [ 0 ] . V_10 += V_25 - 1 ;
V_30 [ 1 ] . V_8 = F_13 ( V_32 ) ;
V_30 [ 2 ] . V_8 = F_13 ( V_33 ) ;
V_30 [ 3 ] . V_8 = F_13 ( V_34 ) ;
V_20 = & V_35 ;
}
V_21 = V_20 -> V_36 . V_37 ;
memcpy ( V_21 , V_18 , sizeof( * V_18 ) ) ;
if ( V_21 -> V_38 ) {
if ( V_16 == 1 )
return - V_22 ;
V_21 -> V_39 = 1 ;
V_21 -> V_40 = 1 ;
V_21 -> V_41 = F_13 ( V_42 ) ;
}
V_21 -> V_43 = V_44 ;
V_21 -> V_45 = V_46 ;
if ( F_2 () ) {
V_21 -> V_43 |= V_47 ;
V_21 -> V_43 |= V_48 ;
V_21 -> V_43 |= V_49 ;
V_21 -> V_45 |= V_50 ;
V_21 -> V_45 |= V_51 ;
V_21 -> V_52 = V_53 ;
V_21 -> V_54 = V_55 ;
} else {
V_21 -> V_56 = true ;
V_21 -> V_52 = V_57 ;
}
V_4 = F_10 ( V_20 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
int T_1
F_14 ( const struct V_58 * V_18 )
{
int V_4 ;
if ( ! F_5 () && ! F_6 () && ! F_7 () )
return - V_22 ;
V_4 = F_3 () ;
if ( V_4 )
return V_4 ;
V_59 [ 0 ] . V_8 = F_4 ( V_60 ) ;
V_59 [ 0 ] . V_10 = V_59 [ 0 ] . V_8 ;
V_59 [ 0 ] . V_10 += V_61 - 1 ;
V_59 [ 1 ] . V_8 = F_13 ( V_62 ) ;
V_59 [ 2 ] . V_8 = F_13 ( V_63 ) ;
if ( ! V_59 [ 2 ] . V_8 )
V_59 [ 2 ] . V_8 = - 1 ;
memcpy ( V_64 . V_36 . V_37 , V_18 , sizeof( * V_18 ) ) ;
if ( F_5 () )
V_65 . V_66 = V_67 ;
else if ( F_6 () || F_7 () )
V_65 . V_66 = V_68 ;
V_65 . V_56 = true ;
V_65 . V_52 = V_57 ;
V_65 . V_43 = V_44 ;
V_65 . V_45 = V_46 ;
V_4 = F_10 ( & V_64 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
