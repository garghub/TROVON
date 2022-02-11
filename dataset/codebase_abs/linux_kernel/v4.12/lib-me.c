int
F_1 ( unsigned int V_1 ,
struct V_2 V_3 ,
T_1 V_4 , T_1 V_5 ,
enum V_6 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_2 ( V_18 . V_19 > 0 ) ;
if ( ( int ) V_1 >= V_18 . V_20 )
return - V_21 ;
V_13 = F_3 ( V_1 , V_3 ,
V_4 , V_5 , V_9 ) ;
if ( ! V_13 )
return - V_22 ;
V_15 = F_4 () ;
if ( ! V_15 )
return - V_23 ;
F_5 ( V_13 -> V_24 ) ;
V_15 -> V_25 = V_1 ;
V_15 -> V_26 = V_3 ;
V_15 -> V_27 = V_4 ;
V_15 -> V_28 = V_5 ;
V_15 -> V_29 = V_7 ;
V_15 -> V_30 = NULL ;
F_6 ( V_18 . V_31 [ V_13 -> V_24 ] ,
& V_15 -> V_32 ) ;
if ( V_5 )
V_17 = & V_13 -> V_33 [ V_34 ] ;
else
V_17 = F_7 ( V_13 , V_3 , V_4 ) ;
V_15 -> V_35 = V_17 - & V_13 -> V_33 [ 0 ] ;
if ( V_9 == V_36 || V_9 == V_37 )
F_8 ( & V_15 -> V_38 , V_17 ) ;
else
F_9 ( & V_15 -> V_38 , V_17 ) ;
F_10 ( V_11 , V_15 ) ;
F_11 ( V_13 -> V_24 ) ;
return 0 ;
}
int
F_12 ( struct V_10 V_39 ,
struct V_2 V_3 ,
T_1 V_4 , T_1 V_5 ,
enum V_6 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_14 * V_40 ;
struct V_14 * V_41 ;
struct V_42 * V_43 ;
int V_44 ;
F_2 ( V_18 . V_19 > 0 ) ;
if ( V_9 == V_37 )
return - V_22 ;
V_41 = F_4 () ;
if ( ! V_41 )
return - V_23 ;
V_44 = F_13 ( V_39 . V_45 ) ;
F_5 ( V_44 ) ;
V_40 = F_14 ( & V_39 ) ;
if ( ! V_40 ) {
F_15 ( V_41 ) ;
F_11 ( V_44 ) ;
return - V_46 ;
}
F_2 ( V_40 -> V_25 < V_18 . V_20 ) ;
V_43 = V_18 . V_47 [ V_40 -> V_25 ] ;
if ( F_16 ( V_43 ) ) {
F_15 ( V_41 ) ;
F_11 ( V_44 ) ;
return - V_22 ;
}
V_41 -> V_35 = V_40 -> V_35 ;
V_41 -> V_25 = V_40 -> V_25 ;
V_41 -> V_26 = V_3 ;
V_41 -> V_27 = V_4 ;
V_41 -> V_28 = V_5 ;
V_41 -> V_29 = V_7 ;
V_41 -> V_30 = NULL ;
F_6 ( V_18 . V_31 [ V_44 ] , & V_41 -> V_32 ) ;
if ( V_9 == V_36 )
F_9 ( & V_41 -> V_38 , & V_40 -> V_38 ) ;
else
F_8 ( & V_41 -> V_38 , & V_40 -> V_38 ) ;
F_10 ( V_11 , V_41 ) ;
F_11 ( V_44 ) ;
return 0 ;
}
int
F_17 ( struct V_10 V_48 )
{
struct V_14 * V_15 ;
struct V_49 * V_50 ;
struct V_51 V_52 ;
int V_44 ;
F_2 ( V_18 . V_19 > 0 ) ;
V_44 = F_13 ( V_48 . V_45 ) ;
F_5 ( V_44 ) ;
V_15 = F_14 ( & V_48 ) ;
if ( ! V_15 ) {
F_11 ( V_44 ) ;
return - V_46 ;
}
V_50 = V_15 -> V_30 ;
if ( V_50 ) {
V_50 -> V_53 |= V_54 ;
if ( V_50 -> V_55 && ! V_50 -> V_56 ) {
F_18 ( V_50 , & V_52 ) ;
F_19 ( V_50 -> V_55 , & V_52 ) ;
}
}
F_20 ( V_15 ) ;
F_11 ( V_44 ) ;
return 0 ;
}
void
F_20 ( struct V_14 * V_15 )
{
F_21 ( & V_15 -> V_38 ) ;
if ( V_15 -> V_30 ) {
struct V_49 * V_50 = V_15 -> V_30 ;
F_22 ( V_15 , V_50 ) ;
F_23 ( V_50 ) ;
}
F_24 ( & V_15 -> V_32 ) ;
F_15 ( V_15 ) ;
}
