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
struct V_6 * V_7 = F_12 ( V_25 ) ;
F_19 ( V_7 -> V_13 ) ;
F_14 ( V_7 -> V_13 ) ;
}
static void F_20 ( struct V_24 * V_25 ,
struct V_18 * V_29 ,
struct V_18 * V_19 )
{
}
static void F_21 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_12 ( V_25 ) ;
F_13 ( V_7 -> V_13 ) ;
F_22 ( V_7 -> V_13 ) ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
int V_32 ;
V_32 = F_24 ( V_31 , & V_7 -> V_25 ,
V_7 -> V_10 -> V_11 ) ;
if ( V_32 )
return V_32 ;
V_7 -> V_3 . V_33 = V_34 ;
F_25 ( & V_7 -> V_25 , & V_35 ) ;
F_26 ( V_31 , & V_7 -> V_25 , & V_36 ,
V_37 ) ;
F_27 ( & V_7 -> V_3 ,
& V_38 ) ;
F_28 ( V_31 , & V_7 -> V_3 , & V_39 ,
V_40 ) ;
if ( V_7 -> V_13 )
F_29 ( V_7 -> V_13 , & V_7 -> V_3 ) ;
F_30 ( & V_7 -> V_3 , & V_7 -> V_25 ) ;
V_7 -> V_3 . V_25 = & V_7 -> V_25 ;
return 0 ;
}
static int F_31 ( struct V_41 * V_10 , struct V_41 * V_42 , void * V_43 )
{
struct V_30 * V_31 = V_43 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_8 * V_44 ;
const T_1 * V_45 ;
struct V_6 * V_7 ;
int V_32 ;
const char * V_46 ;
V_7 = F_32 ( V_10 , sizeof( * V_7 ) , V_47 ) ;
if ( ! V_7 )
return - V_48 ;
V_45 = F_33 ( V_9 , L_1 , & V_7 -> V_49 ) ;
if ( V_45 )
V_7 -> V_16 = F_34 ( V_45 , V_7 -> V_49 , V_47 ) ;
V_32 = F_35 ( V_9 , L_2 , & V_46 ) ;
if ( ! V_32 ) {
if ( ! strcmp ( V_46 , L_3 ) )
V_7 -> V_28 = V_50 ;
else if ( ! strcmp ( V_46 , L_4 ) )
V_7 -> V_28 = V_51 ;
else if ( ! strcmp ( V_46 , L_5 ) )
V_7 -> V_28 = V_52 ;
else if ( ! strcmp ( V_46 , L_6 ) )
V_7 -> V_28 =
F_36 ( 'L' , 'V' , 'D' , '6' ) ;
}
V_44 = F_37 ( V_9 , L_7 , 0 ) ;
if ( V_44 ) {
V_7 -> V_13 = F_38 ( V_44 ) ;
if ( ! V_7 -> V_13 )
return - V_53 ;
}
V_7 -> V_10 = V_10 ;
V_32 = F_23 ( V_31 , V_7 ) ;
if ( V_32 )
return V_32 ;
F_39 ( V_10 , V_7 ) ;
return 0 ;
}
static void F_40 ( struct V_41 * V_10 , struct V_41 * V_42 ,
void * V_43 )
{
struct V_6 * V_7 = F_41 ( V_10 ) ;
V_7 -> V_25 . V_14 -> V_54 ( & V_7 -> V_25 ) ;
V_7 -> V_3 . V_14 -> V_54 ( & V_7 -> V_3 ) ;
F_42 ( V_7 -> V_16 ) ;
}
static int F_43 ( struct V_55 * V_56 )
{
return F_44 ( & V_56 -> V_10 , & V_57 ) ;
}
static int F_45 ( struct V_55 * V_56 )
{
F_46 ( & V_56 -> V_10 , & V_57 ) ;
return 0 ;
}
