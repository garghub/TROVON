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
struct V_16 * V_17 = & V_3 -> V_18 ;
V_12 = V_7 -> V_13 -> V_14 -> V_15 ( V_7 -> V_13 ) ;
if ( ! V_7 -> V_19 && V_17 -> V_20 )
V_7 -> V_19 = V_17 -> V_21 [ 0 ] ;
if ( V_12 > 0 )
return V_12 ;
}
if ( V_7 -> V_22 ) {
F_4 ( V_3 , V_7 -> V_22 ) ;
V_12 = F_5 ( V_3 , V_7 -> V_22 ) ;
}
if ( V_7 -> V_23 ) {
struct V_24 * V_25 = F_6 ( V_3 -> V_10 ) ;
if ( ! V_25 )
return - V_26 ;
F_7 ( V_25 , & V_7 -> V_25 ) ;
V_25 -> type |= V_27 | V_28 ,
F_8 ( V_3 , V_25 ) ;
V_12 ++ ;
}
if ( V_9 ) {
struct V_24 * V_25 = F_6 ( V_3 -> V_10 ) ;
if ( ! V_25 )
return - V_26 ;
F_9 ( V_9 , & V_7 -> V_25 , V_29 ) ;
F_7 ( V_25 , & V_7 -> V_25 ) ;
V_25 -> type |= V_27 | V_28 ,
F_8 ( V_3 , V_25 ) ;
V_12 ++ ;
}
return V_12 ;
}
static struct V_30 * F_10 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return & V_7 -> V_31 ;
}
static void F_11 ( struct V_30 * V_31 , int V_25 )
{
struct V_6 * V_7 = F_12 ( V_31 ) ;
if ( V_25 != V_32 )
F_13 ( V_7 -> V_13 ) ;
else
F_14 ( V_7 -> V_13 ) ;
}
static bool F_15 ( struct V_30 * V_31 ,
const struct V_24 * V_25 ,
struct V_24 * V_33 )
{
return true ;
}
static void F_16 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_12 ( V_31 ) ;
F_17 ( V_31 , V_7 -> V_19 ) ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_12 ( V_31 ) ;
F_19 ( V_7 -> V_13 ) ;
F_14 ( V_7 -> V_13 ) ;
}
static void F_20 ( struct V_30 * V_31 ,
struct V_24 * V_34 ,
struct V_24 * V_25 )
{
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_12 ( V_31 ) ;
F_13 ( V_7 -> V_13 ) ;
F_22 ( V_7 -> V_13 ) ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_6 * V_7 )
{
int V_37 ;
V_37 = F_24 ( V_36 , & V_7 -> V_31 ,
V_7 -> V_10 -> V_11 ) ;
if ( V_37 )
return V_37 ;
V_7 -> V_3 . V_38 = V_39 ;
F_25 ( & V_7 -> V_31 , & V_40 ) ;
F_26 ( V_36 , & V_7 -> V_31 , & V_41 ,
V_42 , NULL ) ;
F_27 ( & V_7 -> V_3 ,
& V_43 ) ;
F_28 ( V_36 , & V_7 -> V_3 , & V_44 ,
V_45 ) ;
if ( V_7 -> V_13 )
F_29 ( V_7 -> V_13 , & V_7 -> V_3 ) ;
F_30 ( & V_7 -> V_3 , & V_7 -> V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_46 * V_10 , struct V_46 * V_47 , void * V_48 )
{
struct V_35 * V_36 = V_48 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_8 * V_49 ;
const T_1 * V_50 ;
struct V_6 * V_7 ;
int V_37 ;
const char * V_51 ;
V_7 = F_32 ( V_10 , sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 )
return - V_53 ;
V_50 = F_33 ( V_9 , L_1 , & V_7 -> V_54 ) ;
if ( V_50 )
V_7 -> V_22 = F_34 ( V_50 , V_7 -> V_54 , V_52 ) ;
V_37 = F_35 ( V_9 , L_2 , & V_51 ) ;
if ( ! V_37 ) {
if ( ! strcmp ( V_51 , L_3 ) )
V_7 -> V_19 = V_55 ;
else if ( ! strcmp ( V_51 , L_4 ) )
V_7 -> V_19 = V_56 ;
else if ( ! strcmp ( V_51 , L_5 ) )
V_7 -> V_19 = V_57 ;
else if ( ! strcmp ( V_51 , L_6 ) )
V_7 -> V_19 = V_58 ;
}
V_49 = F_36 ( V_9 , 1 ) ;
if ( V_49 ) {
struct V_8 * V_59 , * V_60 ;
V_59 = F_37 ( V_49 , L_7 ) ;
if ( V_59 ) {
V_60 = F_38 ( V_59 ) ;
if ( V_60 )
V_7 -> V_13 = F_39 ( V_60 ) ;
if ( ! V_7 -> V_13 )
return - V_61 ;
}
}
V_7 -> V_10 = V_10 ;
V_37 = F_23 ( V_36 , V_7 ) ;
if ( V_37 )
return V_37 ;
F_40 ( V_10 , V_7 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_10 , struct V_46 * V_47 ,
void * V_48 )
{
struct V_6 * V_7 = F_42 ( V_10 ) ;
V_7 -> V_31 . V_14 -> V_62 ( & V_7 -> V_31 ) ;
V_7 -> V_3 . V_14 -> V_62 ( & V_7 -> V_3 ) ;
F_43 ( V_7 -> V_22 ) ;
}
static int F_44 ( struct V_63 * V_64 )
{
return F_45 ( & V_64 -> V_10 , & V_65 ) ;
}
static int F_46 ( struct V_63 * V_64 )
{
F_47 ( & V_64 -> V_10 , & V_65 ) ;
return 0 ;
}
