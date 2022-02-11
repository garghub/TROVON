static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static const struct V_5 * F_3 (
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ )
if ( V_6 -> V_9 == V_8 [ V_7 ] . V_9 )
return & V_8 [ V_7 ] ;
return & V_8 [ 0 ] ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_12 * V_9 )
{
if ( V_9 -> V_13 >= F_4 ( V_8 ) )
return - V_14 ;
V_9 -> V_9 = V_8 [ V_9 -> V_13 ] . V_9 ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
const struct V_5 * V_15 ;
V_15 = F_3 ( V_6 ) ;
V_6 -> V_9 = V_15 -> V_9 ;
F_7 ( & V_6 -> V_16 , V_17 ,
V_18 , 0 ,
& V_6 -> V_19 , V_20 ,
V_21 , 0 , 0 ) ;
}
static struct V_5 * F_8 (
struct V_1 * V_22 , struct V_10 * V_11 ,
T_1 V_23 , enum V_24 V_25 )
{
if ( V_25 == V_26 )
return V_11 ? F_9 ( V_11 , V_23 ) : NULL ;
return & V_22 -> V_27 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_28 * V_15 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
F_6 ( & V_15 -> V_27 ) ;
V_6 = F_8 ( V_22 , V_11 , V_15 -> V_23 , V_15 -> V_25 ) ;
if ( V_6 ) {
F_11 ( & V_22 -> V_29 ) ;
if ( V_15 -> V_25 == V_30 )
* V_6 = V_15 -> V_27 ;
F_12 ( & V_22 -> V_29 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_28 * V_15 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = F_8 ( V_22 , V_11 , V_15 -> V_23 , V_15 -> V_25 ) ;
F_11 ( & V_22 -> V_29 ) ;
V_15 -> V_27 = * V_6 ;
F_12 ( & V_22 -> V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_5 * V_27 = F_9 ( V_11 , 0 ) ;
* V_27 = V_8 [ 0 ] ;
V_27 -> V_16 = V_31 ;
V_27 -> V_19 = V_32 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_22 )
{
int V_7 = V_33 ;
int V_34 ;
V_34 = F_16 ( V_22 -> clock , V_22 -> V_35 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_17 ( V_22 -> V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_18 ( V_22 -> V_37 [ V_7 ] . V_38 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_19 ( V_22 -> clock ) ;
if ( V_34 < 0 )
goto V_40;
for ( V_7 ++ ; V_7 < V_41 ; V_7 ++ ) {
V_34 = F_18 ( V_22 -> V_37 [ V_7 ] . V_38 ) ;
if ( V_34 < 0 )
goto V_40;
}
F_20 ( V_22 -> V_42 , 1 ) ;
F_21 ( 600 , 800 ) ;
F_20 ( V_22 -> V_42 , 0 ) ;
F_21 ( 600 , 800 ) ;
F_20 ( V_22 -> V_42 , 1 ) ;
F_22 ( 20 ) ;
return 0 ;
V_40:
for ( -- V_7 ; V_7 >= 0 ; -- V_7 )
F_23 ( V_22 -> V_37 [ V_7 ] . V_38 ) ;
V_39:
F_24 ( V_22 -> V_36 ) ;
return V_34 ;
}
static int F_25 ( struct V_1 * V_22 )
{
int V_7 ;
F_20 ( V_22 -> V_42 , 0 ) ;
for ( V_7 = V_41 - 1 ; V_7 >= 0 ; V_7 -- )
F_23 ( V_22 -> V_37 [ V_7 ] . V_38 ) ;
F_26 ( V_22 -> clock ) ;
F_24 ( V_22 -> V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , int V_43 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_34 = 0 ;
F_11 ( & V_22 -> V_29 ) ;
if ( V_22 -> V_44 == ! V_43 ) {
if ( V_43 )
V_34 = F_15 ( V_22 ) ;
else
V_34 = F_25 ( V_22 ) ;
if ( V_34 == 0 )
V_22 -> V_44 += V_43 ? 1 : - 1 ;
}
F_12 ( & V_22 -> V_29 ) ;
return V_34 ;
}
static int F_28 ( struct V_45 * V_46 ,
const struct V_47 * V_48 )
{
struct V_49 * V_36 = & V_46 -> V_36 ;
struct V_1 * V_22 ;
struct V_2 * V_3 ;
int V_50 , V_7 , V_34 ;
V_22 = F_29 ( V_36 , sizeof( * V_22 ) , V_51 ) ;
if ( ! V_22 )
return - V_52 ;
F_30 ( & V_22 -> V_29 ) ;
V_22 -> V_42 = - V_14 ;
V_22 -> clock = F_31 ( - V_14 ) ;
V_22 -> V_36 = V_36 ;
V_22 -> clock = F_32 ( V_22 -> V_36 , V_53 ) ;
if ( F_33 ( V_22 -> clock ) )
return F_34 ( V_22 -> clock ) ;
V_50 = F_35 ( V_36 -> V_54 , 0 , NULL ) ;
if ( ! F_36 ( V_50 ) )
return V_50 ;
V_34 = F_37 ( V_36 , V_50 , V_55 ,
V_56 ) ;
if ( V_34 < 0 )
return V_34 ;
V_22 -> V_42 = V_50 ;
if ( F_38 ( V_36 -> V_54 , L_1 ,
& V_22 -> V_35 ) ) {
V_22 -> V_35 = V_57 ;
F_39 ( V_36 , L_2 ,
V_22 -> V_35 ) ;
}
for ( V_7 = 0 ; V_7 < V_41 ; V_7 ++ )
V_22 -> V_37 [ V_7 ] . V_58 = V_59 [ V_7 ] ;
V_34 = F_40 ( & V_46 -> V_36 , V_41 ,
V_22 -> V_37 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = & V_22 -> V_4 ;
F_41 ( V_3 , V_46 , & V_60 ) ;
V_22 -> V_4 . V_61 |= V_62 ;
V_3 -> V_63 = & V_64 ;
V_22 -> V_27 . V_9 = V_8 [ 0 ] . V_9 ;
V_22 -> V_27 . V_16 = V_31 ;
V_22 -> V_27 . V_19 = V_32 ;
V_22 -> V_23 . V_61 = V_65 ;
V_34 = F_42 ( & V_3 -> V_66 , 1 , & V_22 -> V_23 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
F_43 ( V_36 ) ;
F_44 ( V_36 ) ;
V_34 = F_45 ( V_3 ) ;
if ( V_34 < 0 ) {
F_46 ( & V_46 -> V_36 ) ;
F_47 ( & V_3 -> V_66 ) ;
}
return V_34 ;
}
static int F_48 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_49 ( V_46 ) ;
F_46 ( & V_46 -> V_36 ) ;
F_50 ( V_3 ) ;
F_47 ( & V_3 -> V_66 ) ;
return 0 ;
}
