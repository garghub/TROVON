static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
return V_5 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
int V_12 = 0 ;
if ( V_7 -> V_13 && V_7 -> V_13 -> V_14 &&
V_7 -> V_13 -> V_14 -> V_15 ) {
V_12 = V_7 -> V_13 -> V_14 -> V_15 ( V_7 -> V_13 ) ;
if ( V_12 > 0 )
return V_12 ;
}
if ( V_7 -> V_16 ) {
F_4 ( V_3 , V_7 -> V_16 ) ;
V_12 = F_5 ( V_3 , V_7 -> V_16 ) ;
}
if ( V_7 -> V_17 ) {
struct V_18 * V_19 = F_6 ( V_3 -> V_10 ) ;
if ( ! V_19 )
return - V_20 ;
F_7 ( V_19 , & V_7 -> V_19 ) ;
V_19 -> type |= V_21 | V_22 ,
F_8 ( V_3 , V_19 ) ;
V_12 ++ ;
}
if ( V_9 ) {
struct V_18 * V_19 = F_6 ( V_3 -> V_10 ) ;
if ( ! V_19 )
return - V_20 ;
F_9 ( V_9 , & V_7 -> V_19 , V_23 ) ;
F_7 ( V_19 , & V_7 -> V_19 ) ;
V_19 -> type |= V_21 | V_22 ,
F_8 ( V_3 , V_19 ) ;
V_12 ++ ;
}
return V_12 ;
}
static struct V_24 * F_10 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return & V_7 -> V_25 ;
}
static void F_11 ( struct V_24 * V_25 , int V_19 )
{
struct V_6 * V_7 = F_12 ( V_25 ) ;
if ( V_19 != V_26 )
F_13 ( V_7 -> V_13 ) ;
else
F_14 ( V_7 -> V_13 ) ;
}
static bool F_15 ( struct V_24 * V_25 ,
const struct V_18 * V_19 ,
struct V_18 * V_27 )
{
return true ;
}
static void F_16 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_12 ( V_25 ) ;
F_17 ( V_25 , V_7 -> V_28 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
}
static void F_19 ( struct V_24 * V_25 ,
struct V_18 * V_19 ,
struct V_18 * V_27 )
{
}
static void F_20 ( struct V_24 * V_25 )
{
}
static int F_21 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
int V_31 ;
V_31 = F_22 ( V_30 , & V_7 -> V_25 ,
V_7 -> V_10 -> V_11 ) ;
if ( V_31 )
return V_31 ;
F_23 ( & V_7 -> V_25 , & V_32 ) ;
F_24 ( V_30 , & V_7 -> V_25 , & V_33 ,
V_34 ) ;
F_25 ( & V_7 -> V_3 ,
& V_35 ) ;
F_26 ( V_30 , & V_7 -> V_3 , & V_36 ,
V_37 ) ;
if ( V_7 -> V_13 )
F_27 ( V_7 -> V_13 , & V_7 -> V_3 ) ;
F_28 ( & V_7 -> V_3 , & V_7 -> V_25 ) ;
V_7 -> V_3 . V_25 = & V_7 -> V_25 ;
return 0 ;
}
static int F_29 ( struct V_38 * V_10 , struct V_38 * V_39 , void * V_40 )
{
struct V_29 * V_30 = V_40 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_8 * V_41 ;
const T_1 * V_42 ;
struct V_6 * V_7 ;
int V_31 ;
const char * V_43 ;
V_7 = F_30 ( V_10 , sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return - V_45 ;
V_42 = F_31 ( V_9 , L_1 , & V_7 -> V_46 ) ;
if ( V_42 )
V_7 -> V_16 = F_32 ( V_42 , V_7 -> V_46 , V_44 ) ;
V_31 = F_33 ( V_9 , L_2 , & V_43 ) ;
if ( ! V_31 ) {
if ( ! strcmp ( V_43 , L_3 ) )
V_7 -> V_28 = V_47 ;
else if ( ! strcmp ( V_43 , L_4 ) )
V_7 -> V_28 = V_48 ;
else if ( ! strcmp ( V_43 , L_5 ) )
V_7 -> V_28 = V_49 ;
}
V_41 = F_34 ( V_9 , L_6 , 0 ) ;
if ( V_41 )
V_7 -> V_13 = F_35 ( V_41 ) ;
V_7 -> V_10 = V_10 ;
V_31 = F_21 ( V_30 , V_7 ) ;
if ( V_31 )
return V_31 ;
F_36 ( V_10 , V_7 ) ;
return 0 ;
}
static void F_37 ( struct V_38 * V_10 , struct V_38 * V_39 ,
void * V_40 )
{
struct V_6 * V_7 = F_38 ( V_10 ) ;
V_7 -> V_25 . V_14 -> V_50 ( & V_7 -> V_25 ) ;
V_7 -> V_3 . V_14 -> V_50 ( & V_7 -> V_3 ) ;
}
static int F_39 ( struct V_51 * V_52 )
{
return F_40 ( & V_52 -> V_10 , & V_53 ) ;
}
static int F_41 ( struct V_51 * V_52 )
{
F_42 ( & V_52 -> V_10 , & V_53 ) ;
return 0 ;
}
