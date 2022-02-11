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
static int
F_9 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_18 * V_18 ;
int V_19 = V_17 -> clock * 1000 ;
int V_20 ;
F_10 ( L_4 ,
V_2 -> V_21 . V_11 , F_11 ( V_4 ) ,
V_17 -> V_21 . V_11 , V_17 -> V_22 ) ;
F_10 ( L_5 ,
V_17 -> V_23 , V_17 -> clock ,
V_17 -> V_24 ,
V_17 -> V_25 , V_17 -> V_26 ,
V_17 -> V_27 ,
V_17 -> V_28 ,
V_17 -> V_29 , V_17 -> V_30 ,
V_17 -> V_31 , V_17 -> type , V_17 -> V_32 ) ;
if ( V_4 -> V_11 == V_12 )
V_18 = V_8 -> V_33 ;
else
V_18 = V_8 -> V_34 ;
V_20 = F_12 ( V_18 , V_19 ) ;
if ( V_20 < 0 ) {
F_13 ( L_6 , V_19 ) ;
return - V_35 ;
}
if ( F_5 ( V_18 ) ) {
F_13 ( L_7 ) ;
return - V_35 ;
}
F_14 ( V_4 -> V_11 == V_12 ?
V_8 -> V_36 : V_8 -> V_37 , & V_2 -> V_17 ) ;
V_20 = F_15 ( V_4 , & V_2 -> V_17 ) ;
if ( V_20 ) {
F_13 ( L_8 ) ;
return - V_35 ;
}
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_10 ( L_9 , V_2 -> V_21 . V_11 , F_11 ( V_4 ) ) ;
F_17 ( V_4 , false ) ;
F_18 ( V_2 ) ;
if ( V_4 -> V_11 == V_12 ) {
F_19 ( V_8 -> V_33 ) ;
F_19 ( V_8 -> V_13 ) ;
} else {
F_19 ( V_8 -> V_34 ) ;
F_19 ( V_8 -> V_14 ) ;
}
V_4 -> V_9 = V_38 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_9 ( V_2 , & V_2 -> V_39 -> V_40 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_39 -> V_43 ) {
V_2 -> V_39 -> V_43 -> V_44 = F_22 ( V_2 ) ;
F_23 ( F_24 ( V_2 ) != 0 ) ;
V_4 -> V_45 = V_2 -> V_39 -> V_43 ;
V_2 -> V_39 -> V_43 = NULL ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_46 * V_47 = V_2 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 -> V_6 ) ;
struct V_48 * V_49 ;
F_4 ( L_1 ) ;
F_26 (p, &drm_dev->mode_config.plane_list, head) {
struct V_50 * V_51 = F_27 ( V_49 ) ;
switch ( V_51 -> V_9 ) {
case V_52 :
F_4 ( L_10 ,
F_28 ( V_51 ) ) ;
if ( F_29 ( V_4 , V_51 ) ) {
F_13 ( L_11 ,
F_28 ( V_51 ) ) ;
break;
}
if ( F_30 ( V_4 , V_51 , true ) ) {
F_13 ( L_12 ,
F_28 ( V_51 ) ) ;
break;
}
if ( V_51 -> V_53 == V_54 )
F_31 ( V_8 -> V_55 [ 0 ] , V_49 -> V_39 ) ;
V_51 -> V_9 = V_56 ;
break;
case V_57 :
F_4 ( L_13 ,
F_28 ( V_51 ) ) ;
if ( F_30 ( V_4 , V_51 , false ) ) {
F_13 ( L_14 ,
F_28 ( V_51 ) ) ;
continue;
}
if ( V_51 -> V_53 == V_58 )
V_51 -> V_9 = V_59 ;
else
V_51 -> V_9 = V_60 ;
if ( V_51 -> V_53 == V_54 )
F_32 ( V_8 -> V_55 [ 0 ] ) ;
break;
default:
break;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
F_10 ( L_1 ) ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
T_1 V_63 )
{
F_10 ( L_1 ) ;
return 0 ;
}
int F_36 ( struct V_64 * V_65 ,
unsigned long V_43 , void * V_66 )
{
struct V_7 * V_8 =
F_37 ( V_65 , struct V_7 , V_67 ) ;
struct V_1 * V_2 = V_66 ;
struct V_3 * V_4 ;
unsigned long V_32 ;
struct V_68 * V_69 ;
unsigned int V_44 ;
V_69 = V_2 -> V_6 -> V_70 ;
V_44 = F_22 ( V_2 ) ;
V_4 = V_8 -> V_4 [ V_44 ] ;
if ( ( V_43 != V_71 ) &&
( V_43 != V_72 ) ) {
F_13 ( L_15 , V_43 ) ;
return - V_35 ;
}
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_6 -> V_73 , V_32 ) ;
if ( V_4 -> V_45 ) {
F_40 ( V_2 , V_4 -> V_45 ) ;
F_41 ( V_2 ) ;
V_4 -> V_45 = NULL ;
}
F_42 ( & V_2 -> V_6 -> V_73 , V_32 ) ;
if ( V_4 -> V_9 == V_15 ) {
struct V_48 * V_49 ;
F_26 (p, &crtc->dev->mode_config.plane_list,
head) {
struct V_50 * V_51 = F_27 ( V_49 ) ;
if ( ( V_51 -> V_53 & V_74 ) <= V_75 )
if ( V_51 -> V_9 != V_59 )
return 0 ;
}
F_16 ( V_2 ) ;
}
return 0 ;
}
int F_43 ( struct V_46 * V_6 , unsigned int V_44 )
{
struct V_68 * V_76 = V_6 -> V_70 ;
struct V_7 * V_8 = V_76 -> V_8 ;
struct V_64 * V_67 = & V_8 -> V_67 ;
struct V_1 * V_2 = & V_8 -> V_4 [ V_44 ] -> V_1 ;
F_4 ( L_1 ) ;
if ( F_44 ( V_44 == V_12 ?
V_8 -> V_36 : V_8 -> V_37 ,
V_67 , V_2 ) ) {
F_13 ( L_16 ) ;
return - V_35 ;
}
return 0 ;
}
void F_45 ( struct V_46 * V_47 , unsigned int V_44 )
{
struct V_68 * V_69 = V_47 -> V_70 ;
struct V_7 * V_8 = V_69 -> V_8 ;
struct V_64 * V_67 = & V_8 -> V_67 ;
struct V_1 * V_2 = & V_8 -> V_4 [ V_44 ] -> V_1 ;
F_4 ( L_1 ) ;
if ( F_46 ( V_44 == V_12 ?
V_8 -> V_36 : V_8 -> V_37 , V_67 ) )
F_4 ( L_17 ) ;
if ( V_8 -> V_4 [ V_44 ] -> V_45 ) {
F_41 ( V_2 ) ;
V_8 -> V_4 [ V_44 ] -> V_45 = NULL ;
}
}
bool F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_11 == V_12 )
return true ;
return false ;
}
int F_48 ( struct V_46 * V_47 , struct V_3 * V_4 ,
struct V_48 * V_77 , struct V_48 * V_78 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
int V_20 ;
V_20 = F_49 ( V_47 , V_2 , V_77 , V_78 ,
& V_79 , NULL ) ;
if ( V_20 ) {
F_13 ( L_18 ) ;
return - V_35 ;
}
F_50 ( V_2 , & V_80 ) ;
F_4 ( L_19 ,
V_2 -> V_21 . V_11 , F_11 ( V_4 ) ) ;
return 0 ;
}
