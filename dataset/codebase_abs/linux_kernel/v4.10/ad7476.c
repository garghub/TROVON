static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 ;
V_9 = F_3 ( V_8 -> V_10 , & V_8 -> V_11 ) ;
if ( V_9 < 0 )
goto V_12;
F_4 ( V_6 , V_8 -> V_13 ,
F_5 ( V_6 ) ) ;
V_12:
F_6 ( V_6 -> V_14 ) ;
return V_15 ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_8 ( V_8 -> V_10 , V_8 -> V_13 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
int V_16 ;
V_16 = F_3 ( V_8 -> V_10 , & V_8 -> V_11 ) ;
if ( V_16 )
return V_16 ;
return F_10 ( ( V_17 * ) V_8 -> V_13 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_18 const * V_19 ,
int * V_20 ,
int * V_21 ,
long V_22 )
{
int V_16 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_23 ;
switch ( V_22 ) {
case V_24 :
V_16 = F_12 ( V_6 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_9 ( V_8 ) ;
F_13 ( V_6 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_20 = ( V_16 >> V_8 -> V_25 -> V_26 [ 0 ] . V_27 . V_28 ) &
F_14 ( V_8 -> V_25 -> V_26 [ 0 ] . V_27 . V_29 - 1 , 0 ) ;
return V_30 ;
case V_31 :
if ( ! V_8 -> V_25 -> V_32 ) {
V_23 = F_15 ( V_8 -> V_33 ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
V_23 = V_8 -> V_25 -> V_32 ;
}
* V_20 = V_23 / 1000 ;
* V_21 = V_19 -> V_27 . V_29 ;
return V_34 ;
}
return - V_35 ;
}
static int F_16 ( struct V_36 * V_10 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
int V_16 ;
V_6 = F_17 ( & V_10 -> V_37 , sizeof( * V_8 ) ) ;
if ( ! V_6 )
return - V_38 ;
V_8 = F_2 ( V_6 ) ;
V_8 -> V_25 =
& V_39 [ F_18 ( V_10 ) -> V_40 ] ;
V_8 -> V_33 = F_19 ( & V_10 -> V_37 , L_1 ) ;
if ( F_20 ( V_8 -> V_33 ) )
return F_21 ( V_8 -> V_33 ) ;
V_16 = F_22 ( V_8 -> V_33 ) ;
if ( V_16 )
return V_16 ;
F_23 ( V_10 , V_6 ) ;
V_8 -> V_10 = V_10 ;
V_6 -> V_37 . V_41 = & V_10 -> V_37 ;
V_6 -> V_37 . V_42 = V_10 -> V_37 . V_42 ;
V_6 -> V_43 = F_18 ( V_10 ) -> V_43 ;
V_6 -> V_44 = V_45 ;
V_6 -> V_46 = V_8 -> V_25 -> V_26 ;
V_6 -> V_47 = 2 ;
V_6 -> V_48 = & V_49 ;
V_8 -> V_50 . V_51 = & V_8 -> V_13 ;
V_8 -> V_50 . V_52 = V_8 -> V_25 -> V_26 [ 0 ] . V_27 . V_53 / 8 ;
F_24 ( & V_8 -> V_11 ) ;
F_25 ( & V_8 -> V_50 , & V_8 -> V_11 ) ;
V_16 = F_26 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_16 )
goto V_54;
if ( V_8 -> V_25 -> V_55 )
V_8 -> V_25 -> V_55 ( V_8 ) ;
V_16 = F_27 ( V_6 ) ;
if ( V_16 )
goto V_56;
return 0 ;
V_56:
F_28 ( V_6 ) ;
V_54:
F_29 ( V_8 -> V_33 ) ;
return V_16 ;
}
static int F_30 ( struct V_36 * V_10 )
{
struct V_5 * V_6 = F_31 ( V_10 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_32 ( V_6 ) ;
F_28 ( V_6 ) ;
F_29 ( V_8 -> V_33 ) ;
return 0 ;
}
