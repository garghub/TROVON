static void F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
default:
return;
}
}
static bool F_2 ( struct V_1 * V_2 ,
const struct V_8 * V_3 ,
struct V_8 * V_9 )
{
return true ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 , int V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_4 ( V_2 , struct V_14 , V_2 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
T_1 V_20 = 0 ;
int V_21 ;
if ( V_13 ) {
V_17 = F_5 ( V_13 ) ;
V_19 = F_6 ( V_17 -> V_22 ) ;
V_21 = F_7 ( & V_19 -> V_19 , true , false , false , NULL ) ;
if ( V_21 ) {
F_8 ( L_1 ) ;
} else {
F_9 ( V_19 ) ;
F_10 ( & V_19 -> V_19 ) ;
}
}
if ( F_11 ( V_2 -> V_23 -> V_24 == NULL ) )
return - V_25 ;
V_17 = F_5 ( V_2 -> V_23 -> V_24 ) ;
V_19 = F_6 ( V_17 -> V_22 ) ;
V_21 = F_7 ( & V_19 -> V_19 , true , false , false , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_19 , V_26 , & V_20 ) ;
if ( V_21 ) {
F_10 ( & V_19 -> V_19 ) ;
return V_21 ;
}
F_10 ( & V_19 -> V_19 ) ;
F_13 ( V_15 , V_10 , V_11 , V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_8 * V_3 ,
struct V_8 * V_9 ,
int V_10 , int V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_4 ( V_2 , struct V_14 , V_2 ) ;
F_15 ( V_15 , V_3 ) ;
F_3 ( V_2 , V_10 , V_11 , V_13 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static void F_17 ( struct V_1 * V_2 )
{
}
static void F_18 ( struct V_1 * V_2 , T_2 * V_27 , T_2 * V_28 ,
T_2 * V_29 , T_3 V_30 , T_3 V_31 )
{
}
static int F_19 ( struct V_1 * V_2 ,
struct V_12 * V_24 ,
struct V_32 * V_33 ,
T_3 V_34 )
{
struct V_14 * V_15 =
F_4 ( V_2 , struct V_14 , V_2 ) ;
struct V_12 * V_13 = V_2 -> V_23 -> V_24 ;
unsigned long V_35 ;
V_2 -> V_23 -> V_24 = V_24 ;
F_3 ( V_2 , 0 , 0 , V_13 ) ;
if ( V_33 ) {
F_20 ( & V_15 -> V_36 -> V_37 , V_35 ) ;
F_21 ( V_2 , V_33 ) ;
F_22 ( & V_15 -> V_36 -> V_37 , V_35 ) ;
}
return 0 ;
}
static void F_23 ( struct V_38 * V_36 )
{
struct V_14 * V_15 = V_36 -> V_39 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_24 ( V_36 , V_2 , & V_40 ) ;
F_25 ( V_2 , 256 ) ;
F_26 ( V_2 , & V_41 ) ;
}
static bool F_27 ( struct V_42 * V_43 ,
const struct V_8 * V_3 ,
struct V_8 * V_9 )
{
return true ;
}
static void F_28 ( struct V_42 * V_43 ,
struct V_8 * V_3 ,
struct V_8 * V_9 )
{
}
static void F_29 ( struct V_42 * V_43 , int V_44 )
{
}
static void F_30 ( struct V_42 * V_43 )
{
}
static void F_31 ( struct V_42 * V_43 )
{
}
static void F_32 ( struct V_38 * V_36 )
{
struct V_14 * V_15 = V_36 -> V_39 ;
struct V_42 * V_43 = & V_15 -> V_43 ;
V_43 -> V_45 = 0x1 ;
F_33 ( V_36 , V_43 , & V_46 ,
V_47 , NULL ) ;
F_34 ( V_43 , & V_48 ) ;
}
int F_35 ( struct V_49 * V_50 )
{
int V_51 ;
V_51 = F_36 ( V_50 , 8192 , 8192 ) ;
F_37 ( V_50 , V_52 , V_53 ) ;
return V_51 ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_8 * V_3 )
{
struct V_14 * V_15 =
F_4 ( V_50 , struct V_14 , V_50 ) ;
unsigned long V_31 = V_3 -> V_54 * V_3 -> V_55 * 4 ;
if ( V_31 * 2 > V_15 -> V_56 )
return V_57 ;
return V_58 ;
}
static struct V_42 *
F_39 ( struct V_49 * V_50 )
{
int V_59 = V_50 -> V_60 [ 0 ] ;
if ( V_59 )
return F_40 ( V_50 -> V_36 , V_59 ) ;
return NULL ;
}
static enum V_61 F_41 ( struct V_49
* V_50 , bool V_62 )
{
return V_63 ;
}
static void F_42 ( struct V_38 * V_36 )
{
struct V_14 * V_15 = V_36 -> V_39 ;
struct V_49 * V_50 = & V_15 -> V_50 ;
F_43 ( V_36 , V_50 , & V_64 ,
V_65 ) ;
F_44 ( V_50 ,
& V_66 ) ;
F_45 ( V_50 ) ;
}
int F_46 ( struct V_14 * V_15 )
{
F_47 ( V_15 -> V_36 ) ;
V_15 -> V_67 = true ;
V_15 -> V_36 -> V_68 . V_69 = 8192 ;
V_15 -> V_36 -> V_68 . V_70 = 8192 ;
V_15 -> V_36 -> V_68 . V_71 = V_15 -> V_71 ;
V_15 -> V_36 -> V_68 . V_72 = 24 ;
V_15 -> V_36 -> V_68 . V_73 = 0 ;
V_15 -> V_36 -> V_68 . V_74 = & V_75 ;
F_23 ( V_15 -> V_36 ) ;
F_32 ( V_15 -> V_36 ) ;
F_42 ( V_15 -> V_36 ) ;
F_48 ( & V_15 -> V_50 ,
& V_15 -> V_43 ) ;
return 0 ;
}
void F_49 ( struct V_14 * V_15 )
{
if ( V_15 -> V_67 ) {
F_50 ( V_15 -> V_36 ) ;
V_15 -> V_67 = false ;
}
}
