static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 == F_2 ( V_2 ) ) {
V_2 -> V_7 = V_5 ;
return true ;
}
return false ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_15 * V_16 ;
struct V_4 * V_17 ;
int V_18 ;
F_4 ( V_9 , & V_19 ) ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
V_16 = F_6 ( V_14 , V_9 ) ;
V_17 -> V_22 = V_16 -> V_23 ;
V_17 -> V_24 = V_16 -> V_24 ;
V_17 -> V_6 = F_7 ( V_9 ) ;
V_18 = F_8 ( V_9 , F_1 , V_17 ) ;
if ( V_18 ) {
F_9 ( V_17 ) ;
return V_18 ;
}
F_10 ( V_9 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_17 * V_17 = F_12 ( V_9 ) ;
F_13 ( V_9 ) ;
F_9 ( V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_25 * V_26 )
{
F_15 ( V_9 , & V_9 -> V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 )
{
F_15 ( V_9 , NULL ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_9 -> V_31 ;
return F_18 ( V_9 -> V_32 -> V_33 -> V_34 , V_29 ,
V_31 -> V_35 ,
V_31 -> V_36 ,
V_31 -> V_37 ) ;
}
static int F_19 ( struct V_38 * V_32 , int V_39 )
{
struct V_8 * V_9 = V_32 -> V_40 [ V_39 ] . V_9 ;
struct V_41 * V_42 = & V_9 -> V_27 ;
T_1 V_43 = V_19 . V_44 ;
V_42 -> V_34 . type = V_45 ;
V_42 -> V_34 . V_34 = V_32 -> V_33 -> V_34 ;
V_42 -> V_12 = NULL ;
V_42 -> V_46 = F_20 ( V_32 -> V_33 -> V_34 , V_43 ,
& V_42 -> V_47 , V_20 ) ;
V_42 -> V_48 = V_43 ;
return ( V_42 -> V_46 == NULL ) ? - V_21 : 0 ;
}
static void F_21 ( struct V_38 * V_32 )
{
struct V_8 * V_9 ;
struct V_41 * V_42 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 2 ; V_39 ++ ) {
V_9 = V_32 -> V_40 [ V_39 ] . V_9 ;
if ( ! V_9 )
continue;
V_42 = & V_9 -> V_27 ;
if ( ! V_42 -> V_46 )
continue;
F_22 ( V_32 -> V_33 -> V_34 , V_42 -> V_48 , V_42 -> V_46 ,
V_42 -> V_47 ) ;
V_42 -> V_46 = NULL ;
}
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_49 * V_33 = V_11 -> V_33 -> V_49 ;
struct V_38 * V_32 = V_11 -> V_32 ;
int V_18 = 0 ;
if ( ! V_33 -> V_34 -> V_50 )
V_33 -> V_34 -> V_50 = & V_51 ;
if ( ! V_33 -> V_34 -> V_52 )
V_33 -> V_34 -> V_52 = F_24 ( 32 ) ;
if ( V_32 -> V_40 [ V_53 ] . V_9 ) {
V_18 = F_19 ( V_32 ,
V_53 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_32 -> V_40 [ V_54 ] . V_9 ) {
V_18 = F_19 ( V_32 ,
V_54 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_55 * V_56 )
{
return F_26 ( & V_56 -> V_34 , & V_57 ) ;
}
static int T_3 F_27 ( struct V_55 * V_56 )
{
F_28 ( & V_56 -> V_34 ) ;
return 0 ;
}
