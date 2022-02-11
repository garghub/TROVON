static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_2 -> V_8 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_2 -> V_8 ) ) {
F_4 ( V_2 -> V_5 , L_2 ) ;
return F_5 ( V_2 -> V_8 ) ;
}
V_2 -> V_9 = F_6 ( V_2 -> V_5 , L_3 ) ;
if ( F_5 ( V_2 -> V_9 ) == - V_10 ) {
V_2 -> V_9 = NULL ;
} else if ( F_5 ( V_2 -> V_9 ) == - V_11 ) {
return - V_11 ;
} else if ( F_3 ( V_2 -> V_9 ) ) {
F_4 ( V_2 -> V_5 , L_4 ) ;
return F_5 ( V_2 -> V_9 ) ;
}
V_2 -> V_12 = F_6 ( V_2 -> V_5 , L_5 ) ;
if ( F_5 ( V_2 -> V_12 ) == - V_10 ) {
V_2 -> V_12 = NULL ;
} else if ( F_5 ( V_2 -> V_12 ) == - V_11 ) {
return - V_11 ;
} else if ( F_3 ( V_2 -> V_12 ) ) {
F_4 ( V_2 -> V_5 , L_4 ) ;
return F_5 ( V_2 -> V_12 ) ;
}
V_7 = F_7 ( V_2 -> V_9 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_5 , L_6 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static enum V_13
F_8 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
const struct V_18 * V_19 = V_20 ;
int V_21 = V_17 -> clock * 1000 ;
bool V_22 = false ;
int V_23 ;
for ( V_23 = 0 ; V_19 [ V_23 ] . V_24 != ( ~ 0UL ) ; V_23 ++ ) {
if ( V_21 == V_19 [ V_23 ] . V_24 ) {
V_22 = true ;
break;
}
}
return ( V_22 ) ? V_25 : V_26 ;
}
static void F_9 ( struct V_27 * V_28 )
{
}
static bool
F_10 ( struct V_27 * V_28 ,
const struct V_16 * V_17 ,
struct V_16 * V_29 )
{
return true ;
}
static void F_11 ( struct V_27 * V_28 ,
struct V_16 * V_17 ,
struct V_16 * V_29 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
F_13 ( V_2 -> V_9 , V_29 -> clock * 1000 ) ;
}
static void F_14 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_12 ( V_28 ) ;
T_1 V_30 ;
int V_7 ;
V_7 = F_15 ( V_2 -> V_5 -> V_6 , V_28 ) ;
if ( V_7 )
V_30 = V_2 -> V_31 -> V_32 ;
else
V_30 = V_2 -> V_31 -> V_33 ;
V_7 = F_7 ( V_2 -> V_12 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_5 , L_7 , V_7 ) ;
return;
}
V_7 = F_16 ( V_2 -> V_8 , V_2 -> V_31 -> V_34 , V_30 ) ;
if ( V_7 != 0 )
F_4 ( V_2 -> V_5 , L_8 , V_7 ) ;
F_17 ( V_2 -> V_12 ) ;
F_18 ( V_2 -> V_5 , L_9 ,
V_7 ? L_10 : L_11 ) ;
}
static int
F_19 ( struct V_27 * V_28 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_20 ( V_36 ) ;
V_40 -> V_41 = V_42 ;
V_40 -> V_43 = V_44 ;
return 0 ;
}
static int F_21 ( struct V_45 * V_5 , struct V_45 * V_46 ,
void * V_47 )
{
struct V_48 * V_49 = F_22 ( V_5 ) ;
const struct V_50 * V_51 ;
const struct V_52 * V_53 ;
struct V_54 * V_55 = V_47 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_7 ;
if ( ! V_49 -> V_5 . V_6 )
return - V_56 ;
V_2 = F_23 ( & V_49 -> V_5 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
V_53 = F_24 ( V_59 , V_49 -> V_5 . V_6 ) ;
V_51 = V_53 -> V_47 ;
V_2 -> V_5 = & V_49 -> V_5 ;
V_2 -> V_31 = V_51 -> V_60 ;
V_28 = & V_2 -> V_28 ;
V_28 -> V_61 = F_25 ( V_55 , V_5 -> V_6 ) ;
if ( V_28 -> V_61 == 0 )
return - V_11 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_5 , L_12 ) ;
return V_7 ;
}
F_26 ( V_28 , & V_62 ) ;
F_27 ( V_55 , V_28 , & V_63 ,
V_64 , NULL ) ;
V_7 = F_28 ( V_49 , V_28 , V_51 ) ;
if ( V_7 )
F_29 ( V_28 ) ;
return V_7 ;
}
static void F_30 ( struct V_45 * V_5 , struct V_45 * V_46 ,
void * V_47 )
{
return F_31 ( V_5 ) ;
}
static int F_32 ( struct V_48 * V_49 )
{
return F_33 ( & V_49 -> V_5 , & V_65 ) ;
}
static int F_34 ( struct V_48 * V_49 )
{
F_35 ( & V_49 -> V_5 , & V_65 ) ;
return 0 ;
}
