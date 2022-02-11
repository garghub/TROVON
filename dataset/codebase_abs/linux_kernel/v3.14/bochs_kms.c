static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 , int V_3 )
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
static bool F_3 ( struct V_1 * V_2 ,
const struct V_8 * V_3 ,
struct V_8 * V_9 )
{
return true ;
}
static int F_4 ( struct V_1 * V_2 , int V_10 , int V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_5 ( V_2 , struct V_14 , V_2 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
T_1 V_20 = 0 ;
int V_21 ;
if ( V_13 ) {
V_17 = F_6 ( V_13 ) ;
V_19 = F_7 ( V_17 -> V_22 ) ;
V_21 = F_8 ( & V_19 -> V_19 , true , false , false , 0 ) ;
if ( V_21 ) {
F_9 ( L_1 ) ;
} else {
F_10 ( V_19 ) ;
F_11 ( & V_19 -> V_19 ) ;
}
}
if ( F_12 ( V_2 -> V_23 == NULL ) )
return - V_24 ;
V_17 = F_6 ( V_2 -> V_23 ) ;
V_19 = F_7 ( V_17 -> V_22 ) ;
V_21 = F_8 ( & V_19 -> V_19 , true , false , false , 0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_13 ( V_19 , V_25 , & V_20 ) ;
if ( V_21 ) {
F_11 ( & V_19 -> V_19 ) ;
return V_21 ;
}
F_11 ( & V_19 -> V_19 ) ;
F_14 ( V_15 , V_10 , V_11 , V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_8 * V_3 ,
struct V_8 * V_9 ,
int V_10 , int V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_5 ( V_2 , struct V_14 , V_2 ) ;
F_16 ( V_15 , V_3 ) ;
F_4 ( V_2 , V_10 , V_11 , V_13 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
}
static void F_18 ( struct V_1 * V_2 )
{
}
static void F_19 ( struct V_1 * V_2 , T_2 * V_26 , T_2 * V_27 ,
T_2 * V_28 , T_3 V_29 , T_3 V_30 )
{
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_14 * V_15 = V_32 -> V_33 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_21 ( V_32 , V_2 , & V_34 ) ;
F_22 ( V_2 , 256 ) ;
F_23 ( V_2 , & V_35 ) ;
}
static bool F_24 ( struct V_36 * V_37 ,
const struct V_8 * V_3 ,
struct V_8 * V_9 )
{
return true ;
}
static void F_25 ( struct V_36 * V_37 ,
struct V_8 * V_3 ,
struct V_8 * V_9 )
{
}
static void F_26 ( struct V_36 * V_37 , int V_38 )
{
}
static void F_27 ( struct V_36 * V_37 )
{
}
static void F_28 ( struct V_36 * V_37 )
{
}
static void F_29 ( struct V_31 * V_32 )
{
struct V_14 * V_15 = V_32 -> V_33 ;
struct V_36 * V_37 = & V_15 -> V_37 ;
V_37 -> V_39 = 0x1 ;
F_30 ( V_32 , V_37 , & V_40 ,
V_41 ) ;
F_31 ( V_37 , & V_42 ) ;
}
int F_32 ( struct V_43 * V_44 )
{
int V_45 ;
V_45 = F_33 ( V_44 , 8192 , 8192 ) ;
F_34 ( V_44 , V_46 , V_47 ) ;
return V_45 ;
}
static int F_35 ( struct V_43 * V_44 ,
struct V_8 * V_3 )
{
struct V_14 * V_15 =
F_5 ( V_44 , struct V_14 , V_44 ) ;
unsigned long V_30 = V_3 -> V_48 * V_3 -> V_49 * 4 ;
if ( V_30 * 2 > V_15 -> V_50 )
return V_51 ;
return V_52 ;
}
static struct V_36 *
F_36 ( struct V_43 * V_44 )
{
int V_53 = V_44 -> V_54 [ 0 ] ;
struct V_55 * V_22 ;
struct V_36 * V_37 ;
if ( V_53 ) {
V_22 = F_37 ( V_44 -> V_32 , V_53 ,
V_56 ) ;
if ( ! V_22 )
return NULL ;
V_37 = F_38 ( V_22 ) ;
return V_37 ;
}
return NULL ;
}
static enum V_57 F_39 ( struct V_43
* V_44 , bool V_58 )
{
return V_59 ;
}
static void F_40 ( struct V_31 * V_32 )
{
struct V_14 * V_15 = V_32 -> V_33 ;
struct V_43 * V_44 = & V_15 -> V_44 ;
F_41 ( V_32 , V_44 , & V_60 ,
V_61 ) ;
F_42 ( V_44 ,
& V_62 ) ;
}
int F_43 ( struct V_14 * V_15 )
{
F_44 ( V_15 -> V_32 ) ;
V_15 -> V_63 = true ;
V_15 -> V_32 -> V_64 . V_65 = 8192 ;
V_15 -> V_32 -> V_64 . V_66 = 8192 ;
V_15 -> V_32 -> V_64 . V_67 = V_15 -> V_67 ;
V_15 -> V_32 -> V_64 . V_68 = 24 ;
V_15 -> V_32 -> V_64 . V_69 = 0 ;
V_15 -> V_32 -> V_64 . V_70 = ( void * ) & V_71 ;
F_20 ( V_15 -> V_32 ) ;
F_29 ( V_15 -> V_32 ) ;
F_40 ( V_15 -> V_32 ) ;
F_45 ( & V_15 -> V_44 ,
& V_15 -> V_37 ) ;
return 0 ;
}
void F_46 ( struct V_14 * V_15 )
{
if ( V_15 -> V_63 ) {
F_47 ( V_15 -> V_32 ) ;
V_15 -> V_63 = false ;
}
}
