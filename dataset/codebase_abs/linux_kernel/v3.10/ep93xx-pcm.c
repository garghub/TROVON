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
F_4 ( V_9 , & V_13 ) ;
return F_5 ( V_9 ,
F_1 ,
F_6 ( V_11 -> V_14 , V_9 ) ) ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_15 * V_16 )
{
F_8 ( V_9 , & V_9 -> V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_8 ( V_9 , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = V_9 -> V_21 ;
return F_11 ( V_9 -> V_22 -> V_23 -> V_24 , V_19 ,
V_21 -> V_25 ,
V_21 -> V_26 ,
V_21 -> V_27 ) ;
}
static int F_12 ( struct V_28 * V_22 , int V_29 )
{
struct V_8 * V_9 = V_22 -> V_30 [ V_29 ] . V_9 ;
struct V_31 * V_32 = & V_9 -> V_17 ;
T_1 V_33 = V_13 . V_34 ;
V_32 -> V_24 . type = V_35 ;
V_32 -> V_24 . V_24 = V_22 -> V_23 -> V_24 ;
V_32 -> V_12 = NULL ;
V_32 -> V_36 = F_13 ( V_22 -> V_23 -> V_24 , V_33 ,
& V_32 -> V_37 , V_38 ) ;
V_32 -> V_39 = V_33 ;
return ( V_32 -> V_36 == NULL ) ? - V_40 : 0 ;
}
static void F_14 ( struct V_28 * V_22 )
{
struct V_8 * V_9 ;
struct V_31 * V_32 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_9 = V_22 -> V_30 [ V_29 ] . V_9 ;
if ( ! V_9 )
continue;
V_32 = & V_9 -> V_17 ;
if ( ! V_32 -> V_36 )
continue;
F_15 ( V_22 -> V_23 -> V_24 , V_32 -> V_39 , V_32 -> V_36 ,
V_32 -> V_37 ) ;
V_32 -> V_36 = NULL ;
}
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_41 * V_23 = V_11 -> V_23 -> V_41 ;
struct V_28 * V_22 = V_11 -> V_22 ;
int V_42 = 0 ;
if ( ! V_23 -> V_24 -> V_43 )
V_23 -> V_24 -> V_43 = & V_44 ;
if ( ! V_23 -> V_24 -> V_45 )
V_23 -> V_24 -> V_45 = F_17 ( 32 ) ;
if ( V_22 -> V_30 [ V_46 ] . V_9 ) {
V_42 = F_12 ( V_22 ,
V_46 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_22 -> V_30 [ V_47 ] . V_9 ) {
V_42 = F_12 ( V_22 ,
V_47 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static int F_18 ( struct V_48 * V_49 )
{
return F_19 ( & V_49 -> V_24 , & V_50 ) ;
}
static int F_20 ( struct V_48 * V_49 )
{
F_21 ( & V_49 -> V_24 ) ;
return 0 ;
}
