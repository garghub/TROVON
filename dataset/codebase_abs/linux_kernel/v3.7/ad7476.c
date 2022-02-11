static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_2 V_9 ;
int V_10 ;
V_10 = F_3 ( V_8 -> V_11 , & V_8 -> V_12 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 = F_4 () ;
if ( V_6 -> V_14 )
( ( T_2 * ) V_8 -> V_15 ) [ 1 ] = V_9 ;
F_5 ( V_6 -> V_16 , V_8 -> V_15 ) ;
V_13:
F_6 ( V_6 -> V_17 ) ;
return V_18 ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_8 ( V_8 -> V_11 , V_8 -> V_15 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
int V_19 ;
V_19 = F_3 ( V_8 -> V_11 , & V_8 -> V_12 ) ;
if ( V_19 )
return V_19 ;
return F_10 ( ( V_20 * ) V_8 -> V_15 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_21 const * V_22 ,
int * V_23 ,
int * V_24 ,
long V_25 )
{
int V_19 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_26 ;
switch ( V_25 ) {
case V_27 :
F_12 ( & V_6 -> V_28 ) ;
if ( F_13 ( V_6 ) )
V_19 = - V_29 ;
else
V_19 = F_9 ( V_8 ) ;
F_14 ( & V_6 -> V_28 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_23 = ( V_19 >> V_8 -> V_30 -> V_31 [ 0 ] . V_32 . V_33 ) &
F_15 ( V_8 -> V_30 -> V_31 [ 0 ] . V_32 . V_34 ) ;
return V_35 ;
case V_36 :
if ( ! V_8 -> V_30 -> V_37 ) {
V_26 = F_16 ( V_8 -> V_38 ) ;
if ( V_26 < 0 )
return V_26 ;
} else {
V_26 = V_8 -> V_30 -> V_37 ;
}
V_26 >>= V_22 -> V_32 . V_34 ;
* V_23 = V_26 / 1000 ;
* V_24 = ( V_26 % 1000 ) * 1000 ;
return V_39 ;
}
return - V_40 ;
}
static int T_3 F_17 ( struct V_41 * V_11 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
int V_19 ;
V_6 = F_18 ( sizeof( * V_8 ) ) ;
if ( V_6 == NULL ) {
V_19 = - V_42 ;
goto V_43;
}
V_8 = F_2 ( V_6 ) ;
V_8 -> V_30 =
& V_44 [ F_19 ( V_11 ) -> V_45 ] ;
V_8 -> V_38 = F_20 ( & V_11 -> V_46 , L_1 ) ;
if ( F_21 ( V_8 -> V_38 ) ) {
V_19 = F_22 ( V_8 -> V_38 ) ;
goto V_47;
}
V_19 = F_23 ( V_8 -> V_38 ) ;
if ( V_19 )
goto V_48;
F_24 ( V_11 , V_6 ) ;
V_8 -> V_11 = V_11 ;
V_6 -> V_46 . V_49 = & V_11 -> V_46 ;
V_6 -> V_50 = F_19 ( V_11 ) -> V_50 ;
V_6 -> V_51 = V_52 ;
V_6 -> V_53 = V_8 -> V_30 -> V_31 ;
V_6 -> V_54 = 2 ;
V_6 -> V_55 = & V_56 ;
V_8 -> V_57 . V_58 = & V_8 -> V_15 ;
V_8 -> V_57 . V_59 = V_8 -> V_30 -> V_31 [ 0 ] . V_32 . V_60 / 8 ;
F_25 ( & V_8 -> V_12 ) ;
F_26 ( & V_8 -> V_57 , & V_8 -> V_12 ) ;
V_19 = F_27 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_19 )
goto V_61;
if ( V_8 -> V_30 -> V_62 )
V_8 -> V_30 -> V_62 ( V_8 ) ;
V_19 = F_28 ( V_6 ) ;
if ( V_19 )
goto V_63;
return 0 ;
V_63:
F_29 ( V_6 ) ;
V_61:
F_30 ( V_8 -> V_38 ) ;
V_48:
F_31 ( V_8 -> V_38 ) ;
V_47:
F_32 ( V_6 ) ;
V_43:
return V_19 ;
}
static int T_4 F_33 ( struct V_41 * V_11 )
{
struct V_5 * V_6 = F_34 ( V_11 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_35 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_8 -> V_38 ) ;
F_31 ( V_8 -> V_38 ) ;
F_32 ( V_6 ) ;
return 0 ;
}
