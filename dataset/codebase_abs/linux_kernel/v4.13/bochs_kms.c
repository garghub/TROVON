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
T_2 V_29 ,
struct V_30 * V_31 )
{
struct V_12 * V_13 =
F_3 ( V_2 , struct V_12 , V_2 ) ;
struct V_10 * V_11 = V_2 -> V_21 -> V_22 ;
unsigned long V_32 ;
V_2 -> V_21 -> V_22 = V_22 ;
F_2 ( V_2 , 0 , 0 , V_11 ) ;
if ( V_28 ) {
F_18 ( & V_13 -> V_33 -> V_34 , V_32 ) ;
F_19 ( V_2 , V_28 ) ;
F_20 ( & V_13 -> V_33 -> V_34 , V_32 ) ;
}
return 0 ;
}
static void F_21 ( struct V_35 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_36 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
F_22 ( V_33 , V_2 , & V_37 ) ;
F_23 ( V_2 , & V_38 ) ;
}
static void F_24 ( struct V_39 * V_40 ,
struct V_25 * V_3 ,
struct V_25 * V_26 )
{
}
static void F_25 ( struct V_39 * V_40 , int V_41 )
{
}
static void F_26 ( struct V_39 * V_40 )
{
}
static void F_27 ( struct V_39 * V_40 )
{
}
static void F_28 ( struct V_35 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_36 ;
struct V_39 * V_40 = & V_13 -> V_40 ;
V_40 -> V_42 = 0x1 ;
F_29 ( V_33 , V_40 , & V_43 ,
V_44 , NULL ) ;
F_30 ( V_40 , & V_45 ) ;
}
static int F_31 ( struct V_46 * V_47 )
{
int V_48 ;
V_48 = F_32 ( V_47 , 8192 , 8192 ) ;
F_33 ( V_47 , V_49 , V_50 ) ;
return V_48 ;
}
static int F_34 ( struct V_46 * V_47 ,
struct V_25 * V_3 )
{
struct V_12 * V_13 =
F_3 ( V_47 , struct V_12 , V_47 ) ;
unsigned long V_51 = V_3 -> V_52 * V_3 -> V_53 * 4 ;
if ( V_51 * 2 > V_13 -> V_54 )
return V_55 ;
return V_56 ;
}
static struct V_39 *
F_35 ( struct V_46 * V_47 )
{
int V_57 = V_47 -> V_58 [ 0 ] ;
if ( V_57 )
return F_36 ( V_47 -> V_33 , V_57 ) ;
return NULL ;
}
static void F_37 ( struct V_35 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_36 ;
struct V_46 * V_47 = & V_13 -> V_47 ;
F_38 ( V_33 , V_47 , & V_59 ,
V_60 ) ;
F_39 ( V_47 ,
& V_61 ) ;
F_40 ( V_47 ) ;
}
int F_41 ( struct V_12 * V_13 )
{
F_42 ( V_13 -> V_33 ) ;
V_13 -> V_62 = true ;
V_13 -> V_33 -> V_63 . V_64 = 8192 ;
V_13 -> V_33 -> V_63 . V_65 = 8192 ;
V_13 -> V_33 -> V_63 . V_66 = V_13 -> V_66 ;
V_13 -> V_33 -> V_63 . V_67 = 24 ;
V_13 -> V_33 -> V_63 . V_68 = 0 ;
V_13 -> V_33 -> V_63 . V_69 = & V_70 ;
F_21 ( V_13 -> V_33 ) ;
F_28 ( V_13 -> V_33 ) ;
F_37 ( V_13 -> V_33 ) ;
F_43 ( & V_13 -> V_47 ,
& V_13 -> V_40 ) ;
return 0 ;
}
void F_44 ( struct V_12 * V_13 )
{
if ( V_13 -> V_62 ) {
F_45 ( V_13 -> V_33 ) ;
V_13 -> V_62 = false ;
}
}
