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
F_5 ( V_6 , V_8 -> V_15 ) ;
V_13:
F_6 ( V_6 -> V_16 ) ;
return V_17 ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_8 ( V_8 -> V_11 , V_8 -> V_15 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
int V_18 ;
V_18 = F_3 ( V_8 -> V_11 , & V_8 -> V_12 ) ;
if ( V_18 )
return V_18 ;
return F_10 ( ( V_19 * ) V_8 -> V_15 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_20 const * V_21 ,
int * V_22 ,
int * V_23 ,
long V_24 )
{
int V_18 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_25 ;
switch ( V_24 ) {
case V_26 :
F_12 ( & V_6 -> V_27 ) ;
if ( F_13 ( V_6 ) )
V_18 = - V_28 ;
else
V_18 = F_9 ( V_8 ) ;
F_14 ( & V_6 -> V_27 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_22 = ( V_18 >> V_8 -> V_29 -> V_30 [ 0 ] . V_31 . V_32 ) &
F_15 ( V_8 -> V_29 -> V_30 [ 0 ] . V_31 . V_33 ) ;
return V_34 ;
case V_35 :
if ( ! V_8 -> V_29 -> V_36 ) {
V_25 = F_16 ( V_8 -> V_37 ) ;
if ( V_25 < 0 )
return V_25 ;
} else {
V_25 = V_8 -> V_29 -> V_36 ;
}
V_25 >>= V_21 -> V_31 . V_33 ;
* V_22 = V_25 / 1000 ;
* V_23 = ( V_25 % 1000 ) * 1000 ;
return V_38 ;
}
return - V_39 ;
}
static int F_17 ( struct V_40 * V_11 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
int V_18 ;
V_6 = F_18 ( sizeof( * V_8 ) ) ;
if ( V_6 == NULL ) {
V_18 = - V_41 ;
goto V_42;
}
V_8 = F_2 ( V_6 ) ;
V_8 -> V_29 =
& V_43 [ F_19 ( V_11 ) -> V_44 ] ;
V_8 -> V_37 = F_20 ( & V_11 -> V_45 , L_1 ) ;
if ( F_21 ( V_8 -> V_37 ) ) {
V_18 = F_22 ( V_8 -> V_37 ) ;
goto V_46;
}
V_18 = F_23 ( V_8 -> V_37 ) ;
if ( V_18 )
goto V_47;
F_24 ( V_11 , V_6 ) ;
V_8 -> V_11 = V_11 ;
V_6 -> V_45 . V_48 = & V_11 -> V_45 ;
V_6 -> V_49 = F_19 ( V_11 ) -> V_49 ;
V_6 -> V_50 = V_51 ;
V_6 -> V_52 = V_8 -> V_29 -> V_30 ;
V_6 -> V_53 = 2 ;
V_6 -> V_54 = & V_55 ;
V_8 -> V_56 . V_57 = & V_8 -> V_15 ;
V_8 -> V_56 . V_58 = V_8 -> V_29 -> V_30 [ 0 ] . V_31 . V_59 / 8 ;
F_25 ( & V_8 -> V_12 ) ;
F_26 ( & V_8 -> V_56 , & V_8 -> V_12 ) ;
V_18 = F_27 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_18 )
goto V_60;
if ( V_8 -> V_29 -> V_61 )
V_8 -> V_29 -> V_61 ( V_8 ) ;
V_18 = F_28 ( V_6 ) ;
if ( V_18 )
goto V_62;
return 0 ;
V_62:
F_29 ( V_6 ) ;
V_60:
F_30 ( V_8 -> V_37 ) ;
V_47:
F_31 ( V_8 -> V_37 ) ;
V_46:
F_32 ( V_6 ) ;
V_42:
return V_18 ;
}
static int F_33 ( struct V_40 * V_11 )
{
struct V_5 * V_6 = F_34 ( V_11 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_35 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_8 -> V_37 ) ;
F_31 ( V_8 -> V_37 ) ;
F_32 ( V_6 ) ;
return 0 ;
}
