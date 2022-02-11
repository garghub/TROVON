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
int V_23 ;
F_15 ( V_2 , & V_24 ) ;
V_11 = F_2 ( V_8 -> V_17 , V_2 ) ;
if ( V_8 -> V_17 -> V_25 -> V_26 ) {
struct V_14 * V_15 ;
V_15 = F_16 ( V_8 -> V_17 -> V_25 ,
V_11 -> V_27 ) ;
V_23 = F_17 ( V_2 , V_15 ) ;
} else {
V_23 = F_18 ( V_2 ,
V_28 ,
V_11 -> V_27 ) ;
}
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_20 ( V_2 -> V_31 -> V_32 -> V_25 , V_30 ,
V_6 -> V_33 ,
V_6 -> V_34 ,
V_6 -> V_19 ) ;
}
static int F_21 ( struct V_35 * V_31 ,
int V_36 )
{
struct V_1 * V_2 = V_31 -> V_37 [ V_36 ] . V_2 ;
struct V_38 * V_39 = & V_2 -> V_18 ;
T_2 V_40 = V_24 . V_41 ;
V_39 -> V_25 . type = V_42 ;
V_39 -> V_25 . V_25 = V_31 -> V_32 -> V_25 ;
V_39 -> V_9 = NULL ;
V_39 -> V_43 = F_22 ( V_31 -> V_32 -> V_25 , V_40 ,
& V_39 -> V_44 , V_45 ) ;
if ( ! V_39 -> V_43 )
return - V_46 ;
V_39 -> V_47 = V_40 ;
return 0 ;
}
static void F_23 ( struct V_35 * V_31 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_2 = V_31 -> V_37 [ V_36 ] . V_2 ;
if ( ! V_2 )
continue;
V_39 = & V_2 -> V_18 ;
if ( ! V_39 -> V_43 )
continue;
F_24 ( V_31 -> V_32 -> V_25 , V_39 -> V_47 ,
V_39 -> V_43 , V_39 -> V_44 ) ;
V_39 -> V_43 = NULL ;
}
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_48 * V_32 = V_8 -> V_32 -> V_48 ;
struct V_35 * V_31 = V_8 -> V_31 ;
int V_23 = 0 ;
if ( ! V_32 -> V_25 -> V_49 )
V_32 -> V_25 -> V_49 = & V_50 ;
if ( ! V_32 -> V_25 -> V_51 )
V_32 -> V_25 -> V_51 = F_26 ( 64 ) ;
if ( V_31 -> V_37 [ V_52 ] . V_2 ) {
V_23 = F_21 ( V_31 ,
V_52 ) ;
if ( V_23 )
goto V_53;
}
if ( V_31 -> V_37 [ V_54 ] . V_2 ) {
V_23 = F_21 ( V_31 ,
V_54 ) ;
if ( V_23 )
goto V_53;
}
V_53:
if ( V_23 )
F_23 ( V_31 ) ;
return V_23 ;
}
static int F_27 ( struct V_55 * V_56 )
{
return F_28 ( & V_56 -> V_25 ,
& V_57 ) ;
}
static int F_29 ( struct V_55 * V_56 )
{
F_30 ( & V_56 -> V_25 ) ;
return 0 ;
}
