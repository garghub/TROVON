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
V_6 -> V_16 = V_17 ;
F_7 ( & V_6 -> V_18 , V_19 ,
V_20 , 0 ,
& V_6 -> V_21 , V_22 ,
V_23 , 0 , 0 ) ;
}
static struct V_5 * F_8 (
struct V_1 * V_24 , struct V_10 * V_11 ,
T_1 V_25 , enum V_26 V_27 )
{
if ( V_27 == V_28 )
return V_11 ? F_9 ( V_11 , V_25 ) : NULL ;
return & V_24 -> V_29 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_30 * V_15 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
F_6 ( & V_15 -> V_29 ) ;
V_6 = F_8 ( V_24 , V_11 , V_15 -> V_25 , V_15 -> V_27 ) ;
if ( V_6 ) {
F_11 ( & V_24 -> V_31 ) ;
if ( V_15 -> V_27 == V_32 )
* V_6 = V_15 -> V_29 ;
F_12 ( & V_24 -> V_31 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_30 * V_15 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = F_8 ( V_24 , V_11 , V_15 -> V_25 , V_15 -> V_27 ) ;
F_11 ( & V_24 -> V_31 ) ;
V_15 -> V_29 = * V_6 ;
F_12 ( & V_24 -> V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_5 * V_29 = F_9 ( V_11 , 0 ) ;
* V_29 = V_8 [ 0 ] ;
V_29 -> V_18 = V_33 ;
V_29 -> V_21 = V_34 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_24 )
{
int V_7 = V_35 ;
int V_36 ;
V_36 = F_16 ( V_24 -> clock , V_24 -> V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_17 ( V_24 -> V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_18 ( V_24 -> V_39 [ V_7 ] . V_40 ) ;
if ( V_36 < 0 )
goto V_41;
V_36 = F_19 ( V_24 -> clock ) ;
if ( V_36 < 0 )
goto V_42;
for ( V_7 ++ ; V_7 < V_43 ; V_7 ++ ) {
V_36 = F_18 ( V_24 -> V_39 [ V_7 ] . V_40 ) ;
if ( V_36 < 0 )
goto V_42;
}
F_20 ( V_24 -> V_44 , 1 ) ;
F_21 ( 600 , 800 ) ;
F_20 ( V_24 -> V_44 , 0 ) ;
F_21 ( 600 , 800 ) ;
F_20 ( V_24 -> V_44 , 1 ) ;
F_22 ( 20 ) ;
return 0 ;
V_42:
for ( -- V_7 ; V_7 >= 0 ; -- V_7 )
F_23 ( V_24 -> V_39 [ V_7 ] . V_40 ) ;
V_41:
F_24 ( V_24 -> V_38 ) ;
return V_36 ;
}
static int F_25 ( struct V_1 * V_24 )
{
int V_7 ;
F_20 ( V_24 -> V_44 , 0 ) ;
for ( V_7 = V_43 - 1 ; V_7 >= 0 ; V_7 -- )
F_23 ( V_24 -> V_39 [ V_7 ] . V_40 ) ;
F_26 ( V_24 -> clock ) ;
F_24 ( V_24 -> V_38 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , int V_45 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
int V_36 = 0 ;
F_11 ( & V_24 -> V_31 ) ;
if ( V_24 -> V_46 == ! V_45 ) {
if ( V_45 )
V_36 = F_15 ( V_24 ) ;
else
V_36 = F_25 ( V_24 ) ;
if ( V_36 == 0 )
V_24 -> V_46 += V_45 ? 1 : - 1 ;
}
F_12 ( & V_24 -> V_31 ) ;
return V_36 ;
}
static int F_28 ( struct V_47 * V_48 ,
const struct V_49 * V_50 )
{
struct V_51 * V_38 = & V_48 -> V_38 ;
struct V_1 * V_24 ;
struct V_2 * V_3 ;
int V_52 , V_7 , V_36 ;
V_24 = F_29 ( V_38 , sizeof( * V_24 ) , V_53 ) ;
if ( ! V_24 )
return - V_54 ;
F_30 ( & V_24 -> V_31 ) ;
V_24 -> V_44 = - V_14 ;
V_24 -> clock = F_31 ( - V_14 ) ;
V_24 -> V_38 = V_38 ;
V_24 -> clock = F_32 ( V_24 -> V_38 , V_55 ) ;
if ( F_33 ( V_24 -> clock ) )
return F_34 ( V_24 -> clock ) ;
V_52 = F_35 ( V_38 -> V_56 , 0 , NULL ) ;
if ( ! F_36 ( V_52 ) )
return V_52 ;
V_36 = F_37 ( V_38 , V_52 , V_57 ,
V_58 ) ;
if ( V_36 < 0 )
return V_36 ;
V_24 -> V_44 = V_52 ;
if ( F_38 ( V_38 -> V_56 , L_1 ,
& V_24 -> V_37 ) ) {
V_24 -> V_37 = V_59 ;
F_39 ( V_38 , L_2 ,
V_24 -> V_37 ) ;
}
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ )
V_24 -> V_39 [ V_7 ] . V_60 = V_61 [ V_7 ] ;
V_36 = F_40 ( & V_48 -> V_38 , V_43 ,
V_24 -> V_39 ) ;
if ( V_36 < 0 )
return V_36 ;
V_3 = & V_24 -> V_4 ;
F_41 ( V_3 , V_48 , & V_62 ) ;
V_24 -> V_4 . V_63 |= V_64 ;
V_3 -> V_65 = & V_66 ;
V_24 -> V_29 . V_9 = V_8 [ 0 ] . V_9 ;
V_24 -> V_29 . V_18 = V_33 ;
V_24 -> V_29 . V_21 = V_34 ;
V_24 -> V_25 . V_63 = V_67 ;
V_36 = F_42 ( & V_3 -> V_68 , 1 , & V_24 -> V_25 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
F_43 ( V_38 ) ;
F_44 ( V_38 ) ;
V_36 = F_45 ( V_3 ) ;
if ( V_36 < 0 ) {
F_46 ( & V_48 -> V_38 ) ;
F_47 ( & V_3 -> V_68 ) ;
}
return V_36 ;
}
static int F_48 ( struct V_47 * V_48 )
{
struct V_2 * V_3 = F_49 ( V_48 ) ;
F_46 ( & V_48 -> V_38 ) ;
F_50 ( V_3 ) ;
F_47 ( & V_3 -> V_68 ) ;
return 0 ;
}
