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
V_21 = F_8 ( & V_19 -> V_19 , true , false , false , NULL ) ;
if ( V_21 ) {
F_9 ( L_1 ) ;
} else {
F_10 ( V_19 ) ;
F_11 ( & V_19 -> V_19 ) ;
}
}
if ( F_12 ( V_2 -> V_23 -> V_24 == NULL ) )
return - V_25 ;
V_17 = F_6 ( V_2 -> V_23 -> V_24 ) ;
V_19 = F_7 ( V_17 -> V_22 ) ;
V_21 = F_8 ( & V_19 -> V_19 , true , false , false , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_13 ( V_19 , V_26 , & V_20 ) ;
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
static void F_19 ( struct V_1 * V_2 , T_2 * V_27 , T_2 * V_28 ,
T_2 * V_29 , T_3 V_30 , T_3 V_31 )
{
}
static void F_20 ( struct V_32 * V_33 )
{
struct V_14 * V_15 = V_33 -> V_34 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_21 ( V_33 , V_2 , & V_35 ) ;
F_22 ( V_2 , 256 ) ;
F_23 ( V_2 , & V_36 ) ;
}
static bool F_24 ( struct V_37 * V_38 ,
const struct V_8 * V_3 ,
struct V_8 * V_9 )
{
return true ;
}
static void F_25 ( struct V_37 * V_38 ,
struct V_8 * V_3 ,
struct V_8 * V_9 )
{
}
static void F_26 ( struct V_37 * V_38 , int V_39 )
{
}
static void F_27 ( struct V_37 * V_38 )
{
}
static void F_28 ( struct V_37 * V_38 )
{
}
static void F_29 ( struct V_32 * V_33 )
{
struct V_14 * V_15 = V_33 -> V_34 ;
struct V_37 * V_38 = & V_15 -> V_38 ;
V_38 -> V_40 = 0x1 ;
F_30 ( V_33 , V_38 , & V_41 ,
V_42 ) ;
F_31 ( V_38 , & V_43 ) ;
}
int F_32 ( struct V_44 * V_45 )
{
int V_46 ;
V_46 = F_33 ( V_45 , 8192 , 8192 ) ;
F_34 ( V_45 , V_47 , V_48 ) ;
return V_46 ;
}
static int F_35 ( struct V_44 * V_45 ,
struct V_8 * V_3 )
{
struct V_14 * V_15 =
F_5 ( V_45 , struct V_14 , V_45 ) ;
unsigned long V_31 = V_3 -> V_49 * V_3 -> V_50 * 4 ;
if ( V_31 * 2 > V_15 -> V_51 )
return V_52 ;
return V_53 ;
}
static struct V_37 *
F_36 ( struct V_44 * V_45 )
{
int V_54 = V_45 -> V_55 [ 0 ] ;
if ( V_54 )
return F_37 ( V_45 -> V_33 , V_54 ) ;
return NULL ;
}
static enum V_56 F_38 ( struct V_44
* V_45 , bool V_57 )
{
return V_58 ;
}
static void F_39 ( struct V_32 * V_33 )
{
struct V_14 * V_15 = V_33 -> V_34 ;
struct V_44 * V_45 = & V_15 -> V_45 ;
F_40 ( V_33 , V_45 , & V_59 ,
V_60 ) ;
F_41 ( V_45 ,
& V_61 ) ;
F_42 ( V_45 ) ;
}
int F_43 ( struct V_14 * V_15 )
{
F_44 ( V_15 -> V_33 ) ;
V_15 -> V_62 = true ;
V_15 -> V_33 -> V_63 . V_64 = 8192 ;
V_15 -> V_33 -> V_63 . V_65 = 8192 ;
V_15 -> V_33 -> V_63 . V_66 = V_15 -> V_66 ;
V_15 -> V_33 -> V_63 . V_67 = 24 ;
V_15 -> V_33 -> V_63 . V_68 = 0 ;
V_15 -> V_33 -> V_63 . V_69 = ( void * ) & V_70 ;
F_20 ( V_15 -> V_33 ) ;
F_29 ( V_15 -> V_33 ) ;
F_39 ( V_15 -> V_33 ) ;
F_45 ( & V_15 -> V_45 ,
& V_15 -> V_38 ) ;
return 0 ;
}
void F_46 ( struct V_14 * V_15 )
{
if ( V_15 -> V_62 ) {
F_47 ( V_15 -> V_33 ) ;
V_15 -> V_62 = false ;
}
}
