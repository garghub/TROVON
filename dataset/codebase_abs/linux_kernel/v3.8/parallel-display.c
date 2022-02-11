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
int V_8 = 0 ;
if ( V_7 -> V_9 ) {
F_5 ( V_3 , V_7 -> V_9 ) ;
V_8 = F_6 ( V_3 , V_7 -> V_9 ) ;
}
if ( V_7 -> V_10 ) {
struct V_11 * V_12 = F_7 ( V_3 -> V_13 ) ;
F_8 ( V_12 , & V_7 -> V_12 ) ;
V_12 -> type |= V_14 | V_15 ,
F_9 ( V_3 , V_12 ) ;
V_8 ++ ;
}
return V_8 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
return 0 ;
}
static struct V_16 * F_11 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return & V_7 -> V_17 ;
}
static void F_12 ( struct V_16 * V_17 , int V_12 )
{
}
static bool F_13 ( struct V_16 * V_17 ,
const struct V_11 * V_12 ,
struct V_11 * V_18 )
{
return true ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_15 ( V_17 ) ;
F_16 ( V_17 -> V_19 , V_20 ,
V_7 -> V_21 ) ;
}
static void F_17 ( struct V_16 * V_17 )
{
}
static void F_18 ( struct V_16 * V_17 ,
struct V_11 * V_12 ,
struct V_11 * V_18 )
{
}
static void F_19 ( struct V_16 * V_17 )
{
}
static void F_20 ( struct V_16 * V_17 )
{
}
static int F_21 ( struct V_6 * V_7 )
{
int V_22 ;
F_22 ( & V_7 -> V_3 , & V_7 -> V_17 ) ;
V_7 -> V_3 . V_23 = & V_24 ;
V_7 -> V_17 . V_23 = & V_25 ;
V_7 -> V_17 . V_26 = V_20 ;
V_7 -> V_3 . V_27 = V_28 ;
F_23 ( & V_7 -> V_17 , & V_29 ) ;
V_22 = F_24 ( & V_7 -> V_17 , & V_7 -> V_30 ,
V_31 ) ;
if ( V_22 ) {
F_25 ( V_7 -> V_13 , L_1 , V_22 ) ;
return V_22 ;
}
F_26 ( & V_7 -> V_3 ,
& V_32 ) ;
V_22 = F_27 ( & V_7 -> V_3 ,
& V_7 -> V_33 , V_31 ) ;
if ( V_22 ) {
F_28 ( V_7 -> V_30 ) ;
F_25 ( V_7 -> V_13 , L_2 , V_22 ) ;
return V_22 ;
}
V_7 -> V_3 . V_17 = & V_7 -> V_17 ;
return 0 ;
}
static int F_29 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_13 . V_38 ;
const T_1 * V_39 ;
struct V_6 * V_7 ;
int V_22 ;
const char * V_40 ;
struct V_41 * V_41 ;
V_7 = F_30 ( & V_35 -> V_13 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return - V_43 ;
V_41 = F_31 ( & V_35 -> V_13 ) ;
if ( F_32 ( V_41 ) ) {
V_22 = F_33 ( V_41 ) ;
F_34 ( & V_35 -> V_13 , L_3 ,
V_22 ) ;
return V_22 ;
}
V_39 = F_35 ( V_37 , L_4 , & V_7 -> V_44 ) ;
if ( V_39 )
V_7 -> V_9 = F_36 ( V_39 , V_7 -> V_44 , V_42 ) ;
V_22 = F_37 ( V_37 , L_5 , & V_40 ) ;
if ( ! V_22 ) {
if ( ! strcmp ( V_40 , L_6 ) )
V_7 -> V_21 = V_45 ;
else if ( ! strcmp ( V_40 , L_7 ) )
V_7 -> V_21 = V_46 ;
}
V_7 -> V_13 = & V_35 -> V_13 ;
V_22 = F_21 ( V_7 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_38 ( V_7 -> V_30 , V_37 ) ;
F_39 ( V_35 , V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_41 ( V_35 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
F_42 ( V_3 , V_17 ) ;
F_43 ( V_7 -> V_33 ) ;
F_28 ( V_7 -> V_30 ) ;
return 0 ;
}
