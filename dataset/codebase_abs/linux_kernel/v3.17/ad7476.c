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
F_5 () ) ;
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
F_12 ( & V_6 -> V_25 ) ;
if ( F_13 ( V_6 ) )
V_16 = - V_26 ;
else
V_16 = F_9 ( V_8 ) ;
F_14 ( & V_6 -> V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_20 = ( V_16 >> V_8 -> V_27 -> V_28 [ 0 ] . V_29 . V_30 ) &
F_15 ( V_8 -> V_27 -> V_28 [ 0 ] . V_29 . V_31 - 1 , 0 ) ;
return V_32 ;
case V_33 :
if ( ! V_8 -> V_27 -> V_34 ) {
V_23 = F_16 ( V_8 -> V_35 ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
V_23 = V_8 -> V_27 -> V_34 ;
}
* V_20 = V_23 / 1000 ;
* V_21 = V_19 -> V_29 . V_31 ;
return V_36 ;
}
return - V_37 ;
}
static int F_17 ( struct V_38 * V_10 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
int V_16 ;
V_6 = F_18 ( & V_10 -> V_39 , sizeof( * V_8 ) ) ;
if ( ! V_6 )
return - V_40 ;
V_8 = F_2 ( V_6 ) ;
V_8 -> V_27 =
& V_41 [ F_19 ( V_10 ) -> V_42 ] ;
V_8 -> V_35 = F_20 ( & V_10 -> V_39 , L_1 ) ;
if ( F_21 ( V_8 -> V_35 ) )
return F_22 ( V_8 -> V_35 ) ;
V_16 = F_23 ( V_8 -> V_35 ) ;
if ( V_16 )
return V_16 ;
F_24 ( V_10 , V_6 ) ;
V_8 -> V_10 = V_10 ;
V_6 -> V_39 . V_43 = & V_10 -> V_39 ;
V_6 -> V_44 = F_19 ( V_10 ) -> V_44 ;
V_6 -> V_45 = V_46 ;
V_6 -> V_47 = V_8 -> V_27 -> V_28 ;
V_6 -> V_48 = 2 ;
V_6 -> V_49 = & V_50 ;
V_8 -> V_51 . V_52 = & V_8 -> V_13 ;
V_8 -> V_51 . V_53 = V_8 -> V_27 -> V_28 [ 0 ] . V_29 . V_54 / 8 ;
F_25 ( & V_8 -> V_11 ) ;
F_26 ( & V_8 -> V_51 , & V_8 -> V_11 ) ;
V_16 = F_27 ( V_6 , NULL ,
& F_1 , NULL ) ;
if ( V_16 )
goto V_55;
if ( V_8 -> V_27 -> V_56 )
V_8 -> V_27 -> V_56 ( V_8 ) ;
V_16 = F_28 ( V_6 ) ;
if ( V_16 )
goto V_57;
return 0 ;
V_57:
F_29 ( V_6 ) ;
V_55:
F_30 ( V_8 -> V_35 ) ;
return V_16 ;
}
static int F_31 ( struct V_38 * V_10 )
{
struct V_5 * V_6 = F_32 ( V_10 ) ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_33 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_8 -> V_35 ) ;
return 0 ;
}
