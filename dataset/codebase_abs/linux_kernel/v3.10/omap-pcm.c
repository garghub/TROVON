static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
int V_16 = 0 ;
V_11 = F_2 ( V_8 -> V_17 , V_2 ) ;
if ( ! V_11 )
return 0 ;
F_3 ( V_2 , & V_2 -> V_18 ) ;
V_6 -> V_19 = F_4 ( V_4 ) ;
V_15 = F_5 ( V_2 ) ;
if ( ! V_15 )
return - V_20 ;
V_16 = F_6 ( V_2 , V_4 , & V_13 ) ;
if ( V_16 )
return V_16 ;
F_7 ( V_2 ,
F_2 ( V_8 -> V_17 , V_2 ) ,
& V_13 ) ;
return F_8 ( V_15 , & V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_3 ( V_2 , NULL ) ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_21 ;
if ( F_11 () )
V_21 = F_12 ( V_2 ) ;
else
V_21 = F_13 ( V_2 ) ;
return V_21 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_22 * V_11 ;
F_15 ( V_2 , & V_23 ) ;
V_11 = F_2 ( V_8 -> V_17 , V_2 ) ;
return F_16 ( V_2 ,
V_24 ,
V_11 -> V_25 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_18 ( V_2 -> V_28 -> V_29 -> V_30 , V_27 ,
V_6 -> V_31 ,
V_6 -> V_32 ,
V_6 -> V_19 ) ;
}
static int F_19 ( struct V_33 * V_28 ,
int V_34 )
{
struct V_1 * V_2 = V_28 -> V_35 [ V_34 ] . V_2 ;
struct V_36 * V_37 = & V_2 -> V_18 ;
T_2 V_38 = V_23 . V_39 ;
V_37 -> V_30 . type = V_40 ;
V_37 -> V_30 . V_30 = V_28 -> V_29 -> V_30 ;
V_37 -> V_9 = NULL ;
V_37 -> V_41 = F_20 ( V_28 -> V_29 -> V_30 , V_38 ,
& V_37 -> V_42 , V_43 ) ;
if ( ! V_37 -> V_41 )
return - V_44 ;
V_37 -> V_45 = V_38 ;
return 0 ;
}
static void F_21 ( struct V_33 * V_28 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_2 = V_28 -> V_35 [ V_34 ] . V_2 ;
if ( ! V_2 )
continue;
V_37 = & V_2 -> V_18 ;
if ( ! V_37 -> V_41 )
continue;
F_22 ( V_28 -> V_29 -> V_30 , V_37 -> V_45 ,
V_37 -> V_41 , V_37 -> V_42 ) ;
V_37 -> V_41 = NULL ;
}
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_46 * V_29 = V_8 -> V_29 -> V_46 ;
struct V_33 * V_28 = V_8 -> V_28 ;
int V_47 = 0 ;
if ( ! V_29 -> V_30 -> V_48 )
V_29 -> V_30 -> V_48 = & V_49 ;
if ( ! V_29 -> V_30 -> V_50 )
V_29 -> V_30 -> V_50 = F_24 ( 64 ) ;
if ( V_28 -> V_35 [ V_51 ] . V_2 ) {
V_47 = F_19 ( V_28 ,
V_51 ) ;
if ( V_47 )
goto V_52;
}
if ( V_28 -> V_35 [ V_53 ] . V_2 ) {
V_47 = F_19 ( V_28 ,
V_53 ) ;
if ( V_47 )
goto V_52;
}
V_52:
if ( V_47 )
F_21 ( V_28 ) ;
return V_47 ;
}
static int F_25 ( struct V_54 * V_55 )
{
return F_26 ( & V_55 -> V_30 ,
& V_56 ) ;
}
static int F_27 ( struct V_54 * V_55 )
{
F_28 ( & V_55 -> V_30 ) ;
return 0 ;
}
