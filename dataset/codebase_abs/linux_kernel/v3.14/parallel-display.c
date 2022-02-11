static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
return V_5 ;
}
static void F_2 ( struct V_2 * V_3 )
{
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
int V_12 = 0 ;
if ( V_7 -> V_13 ) {
F_5 ( V_3 , V_7 -> V_13 ) ;
V_12 = F_6 ( V_3 , V_7 -> V_13 ) ;
}
if ( V_7 -> V_14 ) {
struct V_15 * V_16 = F_7 ( V_3 -> V_10 ) ;
F_8 ( V_16 , & V_7 -> V_16 ) ;
V_16 -> type |= V_17 | V_18 ,
F_9 ( V_3 , V_16 ) ;
V_12 ++ ;
}
if ( V_9 ) {
struct V_15 * V_16 = F_7 ( V_3 -> V_10 ) ;
F_10 ( V_9 , & V_7 -> V_16 , V_19 ) ;
F_8 ( V_16 , & V_7 -> V_16 ) ;
V_16 -> type |= V_17 | V_18 ,
F_9 ( V_3 , V_16 ) ;
V_12 ++ ;
}
return V_12 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
return 0 ;
}
static struct V_20 * F_12 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return & V_7 -> V_21 ;
}
static void F_13 ( struct V_20 * V_21 , int V_16 )
{
}
static bool F_14 ( struct V_20 * V_21 ,
const struct V_15 * V_16 ,
struct V_15 * V_22 )
{
return true ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = F_16 ( V_21 ) ;
F_17 ( V_21 -> V_23 , V_24 ,
V_7 -> V_25 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
}
static void F_19 ( struct V_20 * V_21 ,
struct V_15 * V_16 ,
struct V_15 * V_22 )
{
}
static void F_20 ( struct V_20 * V_21 )
{
}
static void F_21 ( struct V_20 * V_21 )
{
}
static int F_22 ( struct V_6 * V_7 )
{
int V_26 ;
F_23 ( & V_7 -> V_3 , & V_7 -> V_21 ) ;
V_7 -> V_3 . V_27 = & V_28 ;
V_7 -> V_21 . V_27 = & V_29 ;
V_7 -> V_21 . V_30 = V_24 ;
V_7 -> V_3 . V_31 = V_32 ;
F_24 ( & V_7 -> V_21 , & V_33 ) ;
V_26 = F_25 ( & V_7 -> V_21 , & V_7 -> V_34 ,
V_35 ) ;
if ( V_26 ) {
F_26 ( V_7 -> V_10 , L_1 , V_26 ) ;
return V_26 ;
}
F_27 ( & V_7 -> V_3 ,
& V_36 ) ;
V_26 = F_28 ( & V_7 -> V_3 ,
& V_7 -> V_37 , V_35 ) ;
if ( V_26 ) {
F_29 ( V_7 -> V_34 ) ;
F_26 ( V_7 -> V_10 , L_2 , V_26 ) ;
return V_26 ;
}
V_7 -> V_3 . V_21 = & V_7 -> V_21 ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_10 . V_11 ;
const T_1 * V_40 ;
struct V_6 * V_7 ;
int V_26 ;
const char * V_41 ;
V_7 = F_31 ( & V_39 -> V_10 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return - V_43 ;
V_40 = F_32 ( V_9 , L_3 , & V_7 -> V_44 ) ;
if ( V_40 )
V_7 -> V_13 = F_33 ( V_40 , V_7 -> V_44 , V_42 ) ;
V_26 = F_34 ( V_9 , L_4 , & V_41 ) ;
if ( ! V_26 ) {
if ( ! strcmp ( V_41 , L_5 ) )
V_7 -> V_25 = V_45 ;
else if ( ! strcmp ( V_41 , L_6 ) )
V_7 -> V_25 = V_46 ;
else if ( ! strcmp ( V_41 , L_7 ) )
V_7 -> V_25 = V_47 ;
}
V_7 -> V_10 = & V_39 -> V_10 ;
V_26 = F_22 ( V_7 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_35 ( V_7 -> V_34 , V_9 ) ;
F_36 ( V_39 , V_7 ) ;
return 0 ;
}
static int F_37 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_38 ( V_39 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_20 * V_21 = & V_7 -> V_21 ;
F_39 ( V_3 , V_21 ) ;
F_40 ( V_7 -> V_37 ) ;
F_29 ( V_7 -> V_34 ) ;
return 0 ;
}
