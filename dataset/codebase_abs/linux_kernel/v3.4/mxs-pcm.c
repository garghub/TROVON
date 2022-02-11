static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_2 -> V_8 != V_7 -> V_9 )
return false ;
V_2 -> V_10 = & V_5 -> V_11 ;
return true ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
F_4 ( V_13 , & V_13 -> V_16 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_4 * V_5 ;
int V_20 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_21 ) ;
if ( V_5 == NULL )
return - V_22 ;
V_5 -> V_7 = F_7 ( V_18 -> V_23 , V_13 ) ;
V_5 -> V_11 . V_24 = V_5 -> V_7 -> V_24 ;
V_20 = F_8 ( V_13 , F_1 , V_5 ) ;
if ( V_20 ) {
F_9 ( V_5 ) ;
return V_20 ;
}
F_10 ( V_13 , & V_25 ) ;
F_11 ( V_13 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_13 ( V_13 ) ;
F_14 ( V_13 ) ;
F_9 ( V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_13 -> V_29 ;
return F_16 ( V_13 -> V_30 -> V_31 -> V_32 , V_27 ,
V_29 -> V_33 ,
V_29 -> V_34 ,
V_29 -> V_35 ) ;
}
static int F_17 ( struct V_36 * V_30 , int V_37 )
{
struct V_12 * V_13 = V_30 -> V_38 [ V_37 ] . V_13 ;
struct V_39 * V_40 = & V_13 -> V_16 ;
T_1 V_41 = V_25 . V_42 ;
V_40 -> V_32 . type = V_43 ;
V_40 -> V_32 . V_32 = V_30 -> V_31 -> V_32 ;
V_40 -> V_19 = NULL ;
V_40 -> V_44 = F_18 ( V_30 -> V_31 -> V_32 , V_41 ,
& V_40 -> V_45 , V_21 ) ;
if ( ! V_40 -> V_44 )
return - V_22 ;
V_40 -> V_46 = V_41 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 )
{
struct V_47 * V_31 = V_18 -> V_31 -> V_47 ;
struct V_36 * V_30 = V_18 -> V_30 ;
int V_20 = 0 ;
if ( ! V_31 -> V_32 -> V_48 )
V_31 -> V_32 -> V_48 = & V_49 ;
if ( ! V_31 -> V_32 -> V_50 )
V_31 -> V_32 -> V_50 = F_20 ( 32 ) ;
if ( V_30 -> V_38 [ V_51 ] . V_13 ) {
V_20 = F_17 ( V_30 ,
V_51 ) ;
if ( V_20 )
goto V_52;
}
if ( V_30 -> V_38 [ V_53 ] . V_13 ) {
V_20 = F_17 ( V_30 ,
V_53 ) ;
if ( V_20 )
goto V_52;
}
V_52:
return V_20 ;
}
static void F_21 ( struct V_36 * V_30 )
{
struct V_12 * V_13 ;
struct V_39 * V_40 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
V_13 = V_30 -> V_38 [ V_37 ] . V_13 ;
if ( ! V_13 )
continue;
V_40 = & V_13 -> V_16 ;
if ( ! V_40 -> V_44 )
continue;
F_22 ( V_30 -> V_31 -> V_32 , V_40 -> V_46 ,
V_40 -> V_44 , V_40 -> V_45 ) ;
V_40 -> V_44 = NULL ;
}
}
static int T_2 F_23 ( struct V_54 * V_55 )
{
return F_24 ( & V_55 -> V_32 , & V_56 ) ;
}
static int T_3 F_25 ( struct V_54 * V_55 )
{
F_26 ( & V_55 -> V_32 ) ;
return 0 ;
}
