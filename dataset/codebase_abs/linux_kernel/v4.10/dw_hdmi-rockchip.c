static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_2 -> V_7 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_2 -> V_7 ) ) {
F_4 ( V_2 -> V_5 , L_2 ) ;
return F_5 ( V_2 -> V_7 ) ;
}
return 0 ;
}
static enum V_8
F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_15 ;
int V_16 = V_12 -> clock * 1000 ;
bool V_17 = false ;
int V_18 ;
for ( V_18 = 0 ; V_14 [ V_18 ] . V_19 != ( ~ 0UL ) ; V_18 ++ ) {
if ( V_16 == V_14 [ V_18 ] . V_19 ) {
V_17 = true ;
break;
}
}
return ( V_17 ) ? V_20 : V_21 ;
}
static void F_7 ( struct V_22 * V_23 )
{
}
static bool
F_8 ( struct V_22 * V_23 ,
const struct V_11 * V_12 ,
struct V_11 * V_24 )
{
return true ;
}
static void F_9 ( struct V_22 * V_23 ,
struct V_11 * V_12 ,
struct V_11 * V_24 )
{
}
static void F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
T_1 V_25 ;
int V_26 ;
V_26 = F_12 ( V_2 -> V_5 -> V_6 , V_23 ) ;
if ( V_26 )
V_25 = V_27 | ( V_27 << 16 ) ;
else
V_25 = V_27 << 16 ;
F_13 ( V_2 -> V_7 , V_28 , V_25 ) ;
F_14 ( V_2 -> V_5 , L_3 ,
( V_26 ) ? L_4 : L_5 ) ;
}
static int
F_15 ( struct V_22 * V_23 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = F_16 ( V_30 ) ;
V_34 -> V_35 = V_36 ;
V_34 -> V_37 = V_38 ;
return 0 ;
}
static int F_17 ( struct V_39 * V_5 , struct V_39 * V_40 ,
void * V_41 )
{
struct V_42 * V_43 = F_18 ( V_5 ) ;
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
struct V_48 * V_49 = V_41 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_52 ;
int V_53 ;
if ( ! V_43 -> V_5 . V_6 )
return - V_54 ;
V_2 = F_19 ( & V_43 -> V_5 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_47 = F_20 ( V_57 , V_43 -> V_5 . V_6 ) ;
V_45 = V_47 -> V_41 ;
V_2 -> V_5 = & V_43 -> V_5 ;
V_23 = & V_2 -> V_23 ;
V_52 = F_21 ( V_43 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
V_51 = F_22 ( V_43 , V_58 , 0 ) ;
if ( ! V_51 )
return - V_59 ;
V_23 -> V_60 = F_23 ( V_49 , V_5 -> V_6 ) ;
if ( V_23 -> V_60 == 0 )
return - V_61 ;
V_53 = F_1 ( V_2 ) ;
if ( V_53 ) {
F_4 ( V_2 -> V_5 , L_6 ) ;
return V_53 ;
}
F_24 ( V_23 , & V_62 ) ;
F_25 ( V_49 , V_23 , & V_63 ,
V_64 , NULL ) ;
V_53 = F_26 ( V_5 , V_40 , V_41 , V_23 , V_51 , V_52 , V_45 ) ;
if ( V_53 )
F_27 ( V_23 ) ;
return V_53 ;
}
static void F_28 ( struct V_39 * V_5 , struct V_39 * V_40 ,
void * V_41 )
{
return F_29 ( V_5 , V_40 , V_41 ) ;
}
static int F_30 ( struct V_42 * V_43 )
{
return F_31 ( & V_43 -> V_5 , & V_65 ) ;
}
static int F_32 ( struct V_42 * V_43 )
{
F_33 ( & V_43 -> V_5 , & V_65 ) ;
return 0 ;
}
