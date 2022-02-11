static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_4 ( L_1 ) ;
V_4 -> V_9 = V_10 ;
if ( V_4 -> V_11 == V_12 ) {
if ( F_5 ( V_8 -> V_13 ) )
F_6 ( L_2 ) ;
} else {
if ( F_5 ( V_8 -> V_14 ) )
F_6 ( L_3 ) ;
}
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( L_1 ) ;
V_4 -> V_9 = V_15 ;
}
static bool F_9 ( struct V_1 * V_2 ,
const struct V_16 * V_17 ,
struct V_16 * V_18 )
{
F_10 ( V_18 , V_19 ) ;
return true ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_20 * V_20 ;
int V_21 = V_17 -> clock * 1000 ;
int V_22 ;
F_12 ( L_4 ,
V_2 -> V_23 . V_11 , F_13 ( V_4 ) ,
V_17 -> V_23 . V_11 , V_17 -> V_24 ) ;
F_12 ( L_5 ,
V_17 -> V_25 , V_17 -> clock ,
V_17 -> V_26 ,
V_17 -> V_27 , V_17 -> V_28 ,
V_17 -> V_29 ,
V_17 -> V_30 ,
V_17 -> V_31 , V_17 -> V_32 ,
V_17 -> V_33 , V_17 -> type , V_17 -> V_34 ) ;
if ( V_4 -> V_11 == V_12 )
V_20 = V_8 -> V_35 ;
else
V_20 = V_8 -> V_36 ;
V_22 = F_14 ( V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_15 ( L_6 , V_21 ) ;
return - V_37 ;
}
if ( F_5 ( V_20 ) ) {
F_15 ( L_7 ) ;
return - V_37 ;
}
F_16 ( V_4 -> V_11 == V_12 ?
V_8 -> V_38 : V_8 -> V_39 , & V_2 -> V_17 ) ;
V_22 = F_17 ( V_4 , & V_2 -> V_17 ) ;
if ( V_22 ) {
F_15 ( L_8 ) ;
return - V_37 ;
}
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_12 ( L_9 , V_2 -> V_23 . V_11 , F_13 ( V_4 ) ) ;
F_19 ( V_4 , false ) ;
F_20 ( V_2 ) ;
if ( V_4 -> V_11 == V_12 ) {
F_21 ( V_8 -> V_35 ) ;
F_21 ( V_8 -> V_13 ) ;
} else {
F_21 ( V_8 -> V_36 ) ;
F_21 ( V_8 -> V_14 ) ;
}
V_4 -> V_9 = V_40 ;
}
static void
F_22 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_2 , & V_2 -> V_41 -> V_18 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_41 -> V_44 ) {
V_2 -> V_41 -> V_44 -> V_45 = F_24 ( V_2 ) ;
F_25 ( F_26 ( V_2 ) != 0 ) ;
V_4 -> V_46 = V_2 -> V_41 -> V_44 ;
V_2 -> V_41 -> V_44 = NULL ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_47 * V_48 = V_2 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 -> V_6 ) ;
struct V_49 * V_50 ;
F_4 ( L_1 ) ;
F_28 (p, &drm_dev->mode_config.plane_list, head) {
struct V_51 * V_52 = F_29 ( V_50 ) ;
switch ( V_52 -> V_9 ) {
case V_53 :
F_4 ( L_10 ,
F_30 ( V_52 ) ) ;
if ( F_31 ( V_4 , V_52 ) ) {
F_15 ( L_11 ,
F_30 ( V_52 ) ) ;
break;
}
if ( F_32 ( V_4 , V_52 , true ) ) {
F_15 ( L_12 ,
F_30 ( V_52 ) ) ;
break;
}
if ( V_52 -> V_54 == V_55 )
F_33 ( V_8 -> V_56 [ 0 ] , V_50 -> V_41 ) ;
V_52 -> V_9 = V_57 ;
break;
case V_58 :
F_4 ( L_13 ,
F_30 ( V_52 ) ) ;
if ( F_32 ( V_4 , V_52 , false ) ) {
F_15 ( L_14 ,
F_30 ( V_52 ) ) ;
continue;
}
if ( V_52 -> V_54 == V_59 )
V_52 -> V_9 = V_60 ;
else
V_52 -> V_9 = V_61 ;
if ( V_52 -> V_54 == V_55 )
F_34 ( V_8 -> V_56 [ 0 ] ) ;
break;
default:
break;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
F_12 ( L_1 ) ;
F_36 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
T_1 V_64 )
{
F_12 ( L_1 ) ;
return 0 ;
}
int F_38 ( struct V_65 * V_66 ,
unsigned long V_44 , void * V_67 )
{
struct V_7 * V_8 =
F_39 ( V_66 , struct V_7 , V_68 ) ;
struct V_1 * V_2 = V_67 ;
struct V_3 * V_4 ;
unsigned long V_34 ;
struct V_69 * V_70 ;
unsigned int V_45 ;
V_70 = V_2 -> V_6 -> V_71 ;
V_45 = F_24 ( V_2 ) ;
V_4 = V_8 -> V_4 [ V_45 ] ;
if ( ( V_44 != V_72 ) &&
( V_44 != V_73 ) ) {
F_15 ( L_15 , V_44 ) ;
return - V_37 ;
}
F_40 ( V_2 ) ;
F_41 ( & V_2 -> V_6 -> V_74 , V_34 ) ;
if ( V_4 -> V_46 ) {
F_42 ( V_2 , V_4 -> V_46 ) ;
F_43 ( V_2 ) ;
V_4 -> V_46 = NULL ;
}
F_44 ( & V_2 -> V_6 -> V_74 , V_34 ) ;
if ( V_4 -> V_9 == V_15 ) {
struct V_49 * V_50 ;
F_28 (p, &crtc->dev->mode_config.plane_list,
head) {
struct V_51 * V_52 = F_29 ( V_50 ) ;
if ( ( V_52 -> V_54 & V_75 ) <= V_76 )
if ( V_52 -> V_9 != V_60 )
return 0 ;
}
F_18 ( V_2 ) ;
}
return 0 ;
}
int F_45 ( struct V_47 * V_6 , unsigned int V_45 )
{
struct V_69 * V_77 = V_6 -> V_71 ;
struct V_7 * V_8 = V_77 -> V_8 ;
struct V_65 * V_68 = & V_8 -> V_68 ;
struct V_1 * V_2 = & V_8 -> V_4 [ V_45 ] -> V_1 ;
F_4 ( L_1 ) ;
if ( F_46 ( V_45 == V_12 ?
V_8 -> V_38 : V_8 -> V_39 ,
V_68 , V_2 ) ) {
F_15 ( L_16 ) ;
return - V_37 ;
}
return 0 ;
}
void F_47 ( struct V_47 * V_48 , unsigned int V_45 )
{
struct V_69 * V_70 = V_48 -> V_71 ;
struct V_7 * V_8 = V_70 -> V_8 ;
struct V_65 * V_68 = & V_8 -> V_68 ;
struct V_1 * V_2 = & V_8 -> V_4 [ V_45 ] -> V_1 ;
F_4 ( L_1 ) ;
if ( F_48 ( V_45 == V_12 ?
V_8 -> V_38 : V_8 -> V_39 , V_68 ) )
F_4 ( L_17 ) ;
if ( V_8 -> V_4 [ V_45 ] -> V_46 ) {
F_43 ( V_2 ) ;
V_8 -> V_4 [ V_45 ] -> V_46 = NULL ;
}
}
bool F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_11 == V_12 )
return true ;
return false ;
}
int F_50 ( struct V_47 * V_48 , struct V_3 * V_4 ,
struct V_49 * V_78 , struct V_49 * V_79 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
int V_22 ;
V_22 = F_51 ( V_48 , V_2 , V_78 , V_79 ,
& V_80 , NULL ) ;
if ( V_22 ) {
F_15 ( L_18 ) ;
return - V_37 ;
}
F_52 ( V_2 , & V_81 ) ;
F_4 ( L_19 ,
V_2 -> V_23 . V_11 , F_13 ( V_4 ) ) ;
return 0 ;
}
