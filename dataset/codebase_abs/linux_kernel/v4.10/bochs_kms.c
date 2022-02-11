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
static int F_2 ( struct V_1 * V_2 , int V_8 , int V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 =
F_3 ( V_2 , struct V_12 , V_2 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
int V_19 ;
if ( V_11 ) {
V_15 = F_4 ( V_11 ) ;
V_17 = F_5 ( V_15 -> V_20 ) ;
V_19 = F_6 ( & V_17 -> V_17 , true , false , NULL ) ;
if ( V_19 ) {
F_7 ( L_1 ) ;
} else {
F_8 ( V_17 ) ;
F_9 ( & V_17 -> V_17 ) ;
}
}
if ( F_10 ( V_2 -> V_21 -> V_22 == NULL ) )
return - V_23 ;
V_15 = F_4 ( V_2 -> V_21 -> V_22 ) ;
V_17 = F_5 ( V_15 -> V_20 ) ;
V_19 = F_6 ( & V_17 -> V_17 , true , false , NULL ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_17 , V_24 , & V_18 ) ;
if ( V_19 ) {
F_9 ( & V_17 -> V_17 ) ;
return V_19 ;
}
F_9 ( & V_17 -> V_17 ) ;
F_12 ( V_13 , V_8 , V_9 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_25 * V_3 ,
struct V_25 * V_26 ,
int V_8 , int V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 =
F_3 ( V_2 , struct V_12 , V_2 ) ;
F_14 ( V_13 , V_3 ) ;
F_2 ( V_2 , V_8 , V_9 , V_11 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
}
static void F_16 ( struct V_1 * V_2 )
{
}
static int F_17 ( struct V_1 * V_2 ,
struct V_10 * V_22 ,
struct V_27 * V_28 ,
T_2 V_29 )
{
struct V_12 * V_13 =
F_3 ( V_2 , struct V_12 , V_2 ) ;
struct V_10 * V_11 = V_2 -> V_21 -> V_22 ;
unsigned long V_30 ;
V_2 -> V_21 -> V_22 = V_22 ;
F_2 ( V_2 , 0 , 0 , V_11 ) ;
if ( V_28 ) {
F_18 ( & V_13 -> V_31 -> V_32 , V_30 ) ;
F_19 ( V_2 , V_28 ) ;
F_20 ( & V_13 -> V_31 -> V_32 , V_30 ) ;
}
return 0 ;
}
static void F_21 ( struct V_33 * V_31 )
{
struct V_12 * V_13 = V_31 -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
F_22 ( V_31 , V_2 , & V_35 ) ;
F_23 ( V_2 , & V_36 ) ;
}
static void F_24 ( struct V_37 * V_38 ,
struct V_25 * V_3 ,
struct V_25 * V_26 )
{
}
static void F_25 ( struct V_37 * V_38 , int V_39 )
{
}
static void F_26 ( struct V_37 * V_38 )
{
}
static void F_27 ( struct V_37 * V_38 )
{
}
static void F_28 ( struct V_33 * V_31 )
{
struct V_12 * V_13 = V_31 -> V_34 ;
struct V_37 * V_38 = & V_13 -> V_38 ;
V_38 -> V_40 = 0x1 ;
F_29 ( V_31 , V_38 , & V_41 ,
V_42 , NULL ) ;
F_30 ( V_38 , & V_43 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
int V_46 ;
V_46 = F_32 ( V_45 , 8192 , 8192 ) ;
F_33 ( V_45 , V_47 , V_48 ) ;
return V_46 ;
}
static int F_34 ( struct V_44 * V_45 ,
struct V_25 * V_3 )
{
struct V_12 * V_13 =
F_3 ( V_45 , struct V_12 , V_45 ) ;
unsigned long V_49 = V_3 -> V_50 * V_3 -> V_51 * 4 ;
if ( V_49 * 2 > V_13 -> V_52 )
return V_53 ;
return V_54 ;
}
static struct V_37 *
F_35 ( struct V_44 * V_45 )
{
int V_55 = V_45 -> V_56 [ 0 ] ;
if ( V_55 )
return F_36 ( V_45 -> V_31 , V_55 ) ;
return NULL ;
}
static void F_37 ( struct V_33 * V_31 )
{
struct V_12 * V_13 = V_31 -> V_34 ;
struct V_44 * V_45 = & V_13 -> V_45 ;
F_38 ( V_31 , V_45 , & V_57 ,
V_58 ) ;
F_39 ( V_45 ,
& V_59 ) ;
F_40 ( V_45 ) ;
}
int F_41 ( struct V_12 * V_13 )
{
F_42 ( V_13 -> V_31 ) ;
V_13 -> V_60 = true ;
V_13 -> V_31 -> V_61 . V_62 = 8192 ;
V_13 -> V_31 -> V_61 . V_63 = 8192 ;
V_13 -> V_31 -> V_61 . V_64 = V_13 -> V_64 ;
V_13 -> V_31 -> V_61 . V_65 = 24 ;
V_13 -> V_31 -> V_61 . V_66 = 0 ;
V_13 -> V_31 -> V_61 . V_67 = & V_68 ;
F_21 ( V_13 -> V_31 ) ;
F_28 ( V_13 -> V_31 ) ;
F_37 ( V_13 -> V_31 ) ;
F_43 ( & V_13 -> V_45 ,
& V_13 -> V_38 ) ;
return 0 ;
}
void F_44 ( struct V_12 * V_13 )
{
if ( V_13 -> V_60 ) {
F_45 ( V_13 -> V_31 ) ;
V_13 -> V_60 = false ;
}
}
