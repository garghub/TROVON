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
if ( V_9 ) {
struct V_23 * V_24 = F_6 ( V_3 -> V_10 ) ;
if ( ! V_24 )
return - V_25 ;
F_7 ( V_9 , & V_7 -> V_24 , V_26 ) ;
F_8 ( V_24 , & V_7 -> V_24 ) ;
V_24 -> type |= V_27 | V_28 ,
F_9 ( V_3 , V_24 ) ;
V_12 ++ ;
}
return V_12 ;
}
static struct V_29 * F_10 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return & V_7 -> V_30 ;
}
static void F_11 ( struct V_29 * V_30 , int V_24 )
{
struct V_6 * V_7 = F_12 ( V_30 ) ;
if ( V_24 != V_31 )
F_13 ( V_7 -> V_13 ) ;
else
F_14 ( V_7 -> V_13 ) ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_12 ( V_30 ) ;
F_16 ( V_30 , V_7 -> V_19 , 2 , 3 ,
V_7 -> V_3 . V_18 . V_32 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_12 ( V_30 ) ;
F_18 ( V_7 -> V_13 ) ;
F_14 ( V_7 -> V_13 ) ;
}
static void F_19 ( struct V_29 * V_30 ,
struct V_23 * V_33 ,
struct V_23 * V_24 )
{
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_12 ( V_30 ) ;
F_13 ( V_7 -> V_13 ) ;
F_21 ( V_7 -> V_13 ) ;
}
static int F_22 ( struct V_34 * V_35 ,
struct V_6 * V_7 )
{
int V_36 ;
V_36 = F_23 ( V_35 , & V_7 -> V_30 ,
V_7 -> V_10 -> V_11 ) ;
if ( V_36 )
return V_36 ;
V_7 -> V_3 . V_37 = V_38 ;
F_24 ( & V_7 -> V_30 , & V_39 ) ;
F_25 ( V_35 , & V_7 -> V_30 , & V_40 ,
V_41 , NULL ) ;
F_26 ( & V_7 -> V_3 ,
& V_42 ) ;
F_27 ( V_35 , & V_7 -> V_3 , & V_43 ,
V_44 ) ;
if ( V_7 -> V_13 )
F_28 ( V_7 -> V_13 , & V_7 -> V_3 ) ;
F_29 ( & V_7 -> V_3 , & V_7 -> V_30 ) ;
return 0 ;
}
static int F_30 ( struct V_45 * V_10 , struct V_45 * V_46 , void * V_47 )
{
struct V_34 * V_35 = V_47 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_8 * V_48 ;
const T_1 * V_49 ;
struct V_6 * V_7 ;
int V_36 ;
const char * V_50 ;
V_7 = F_31 ( V_10 , sizeof( * V_7 ) , V_51 ) ;
if ( ! V_7 )
return - V_52 ;
V_49 = F_32 ( V_9 , L_1 , & V_7 -> V_53 ) ;
if ( V_49 )
V_7 -> V_22 = F_33 ( V_49 , V_7 -> V_53 , V_51 ) ;
V_36 = F_34 ( V_9 , L_2 , & V_50 ) ;
if ( ! V_36 ) {
if ( ! strcmp ( V_50 , L_3 ) )
V_7 -> V_19 = V_54 ;
else if ( ! strcmp ( V_50 , L_4 ) )
V_7 -> V_19 = V_55 ;
else if ( ! strcmp ( V_50 , L_5 ) )
V_7 -> V_19 = V_56 ;
else if ( ! strcmp ( V_50 , L_6 ) )
V_7 -> V_19 = V_57 ;
}
V_48 = F_35 ( V_9 , 1 , - 1 ) ;
if ( V_48 ) {
struct V_8 * V_58 ;
V_58 = F_36 ( V_48 ) ;
F_37 ( V_48 ) ;
if ( V_58 ) {
V_7 -> V_13 = F_38 ( V_58 ) ;
F_37 ( V_58 ) ;
}
if ( ! V_7 -> V_13 )
return - V_59 ;
}
V_7 -> V_10 = V_10 ;
V_36 = F_22 ( V_35 , V_7 ) ;
if ( V_36 )
return V_36 ;
F_39 ( V_10 , V_7 ) ;
return 0 ;
}
static void F_40 ( struct V_45 * V_10 , struct V_45 * V_46 ,
void * V_47 )
{
struct V_6 * V_7 = F_41 ( V_10 ) ;
V_7 -> V_30 . V_14 -> V_60 ( & V_7 -> V_30 ) ;
V_7 -> V_3 . V_14 -> V_60 ( & V_7 -> V_3 ) ;
F_42 ( V_7 -> V_22 ) ;
}
static int F_43 ( struct V_61 * V_62 )
{
return F_44 ( & V_62 -> V_10 , & V_63 ) ;
}
static int F_45 ( struct V_61 * V_62 )
{
F_46 ( & V_62 -> V_10 , & V_63 ) ;
return 0 ;
}
