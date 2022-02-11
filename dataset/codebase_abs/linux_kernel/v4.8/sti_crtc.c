static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
V_4 -> V_5 = V_6 ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
V_4 -> V_5 = V_7 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_14 * V_15 , * V_16 ;
int V_17 = V_9 -> clock * 1000 ;
F_8 ( L_2 ,
V_2 -> V_18 . V_19 , F_9 ( V_4 ) ,
V_9 -> V_18 . V_19 , V_9 -> V_20 ) ;
F_8 ( L_3 ,
V_9 -> V_21 , V_9 -> clock ,
V_9 -> V_22 ,
V_9 -> V_23 , V_9 -> V_24 ,
V_9 -> V_25 ,
V_9 -> V_26 ,
V_9 -> V_27 , V_9 -> V_28 ,
V_9 -> V_29 , V_9 -> type , V_9 -> V_30 ) ;
if ( V_4 -> V_19 == V_31 ) {
V_15 = V_13 -> V_32 ;
V_16 = V_13 -> V_33 ;
} else {
V_15 = V_13 -> V_34 ;
V_16 = V_13 -> V_35 ;
}
if ( F_10 ( V_15 ) ) {
F_11 ( L_4 ) ;
goto V_36;
}
if ( F_12 ( V_16 , V_17 ) < 0 ) {
F_13 ( L_5 , V_17 ) ;
goto V_37;
}
if ( F_10 ( V_16 ) ) {
F_13 ( L_6 ) ;
goto V_37;
}
F_14 ( V_4 -> V_19 == V_31 ?
V_13 -> V_38 : V_13 -> V_39 , & V_2 -> V_9 ) ;
if ( F_15 ( V_4 , & V_2 -> V_9 ) ) {
F_13 ( L_7 ) ;
goto V_40;
}
return 0 ;
V_40:
F_16 ( V_16 ) ;
V_37:
F_16 ( V_15 ) ;
V_36:
return - V_41 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
F_8 ( L_8 , V_2 -> V_18 . V_19 , F_9 ( V_4 ) ) ;
F_18 ( V_4 , false ) ;
F_19 ( V_2 ) ;
if ( V_4 -> V_19 == V_31 ) {
F_16 ( V_13 -> V_33 ) ;
F_16 ( V_13 -> V_32 ) ;
} else {
F_16 ( V_13 -> V_35 ) ;
F_16 ( V_13 -> V_34 ) ;
}
V_4 -> V_5 = V_42 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 , & V_2 -> V_43 -> V_44 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_43 -> V_47 ) {
V_2 -> V_43 -> V_47 -> V_48 = F_22 ( V_2 ) ;
F_23 ( F_24 ( V_2 ) != 0 ) ;
V_4 -> V_49 = V_2 -> V_43 -> V_47 ;
V_2 -> V_43 -> V_47 = NULL ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_50 * V_51 = V_2 -> V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_7 ( V_4 -> V_11 ) ;
struct V_52 * V_53 ;
F_3 ( L_1 ) ;
F_26 (p, &drm_dev->mode_config.plane_list, head) {
struct V_54 * V_55 = F_27 ( V_53 ) ;
switch ( V_55 -> V_5 ) {
case V_56 :
F_3 ( L_9 ,
F_28 ( V_55 ) ) ;
if ( F_29 ( V_4 , V_55 ) ) {
F_13 ( L_10 ,
F_28 ( V_55 ) ) ;
break;
}
if ( F_30 ( V_4 , V_55 , true ) ) {
F_13 ( L_11 ,
F_28 ( V_55 ) ) ;
break;
}
if ( V_55 -> V_57 == V_58 )
F_31 ( V_13 -> V_59 [ 0 ] , V_53 -> V_43 ) ;
V_55 -> V_5 = V_60 ;
break;
case V_61 :
F_3 ( L_12 ,
F_28 ( V_55 ) ) ;
if ( F_30 ( V_4 , V_55 , false ) ) {
F_13 ( L_13 ,
F_28 ( V_55 ) ) ;
continue;
}
if ( V_55 -> V_57 == V_62 )
V_55 -> V_5 = V_63 ;
else
V_55 -> V_5 = V_64 ;
if ( V_55 -> V_57 == V_58 )
F_32 ( V_13 -> V_59 [ 0 ] ) ;
break;
default:
break;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
F_8 ( L_1 ) ;
F_34 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
T_1 V_67 )
{
F_8 ( L_1 ) ;
return 0 ;
}
int F_36 ( struct V_68 * V_69 ,
unsigned long V_47 , void * V_70 )
{
struct V_12 * V_13 =
F_37 ( V_69 , struct V_12 , V_71 ) ;
struct V_1 * V_2 = V_70 ;
struct V_3 * V_4 ;
unsigned long V_30 ;
struct V_72 * V_73 ;
unsigned int V_48 ;
V_73 = V_2 -> V_11 -> V_74 ;
V_48 = F_22 ( V_2 ) ;
V_4 = V_13 -> V_4 [ V_48 ] ;
if ( ( V_47 != V_75 ) &&
( V_47 != V_76 ) ) {
F_13 ( L_14 , V_47 ) ;
return - V_41 ;
}
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_11 -> V_77 , V_30 ) ;
if ( V_4 -> V_49 ) {
F_40 ( V_2 , V_4 -> V_49 ) ;
F_41 ( V_2 ) ;
V_4 -> V_49 = NULL ;
}
F_42 ( & V_2 -> V_11 -> V_77 , V_30 ) ;
if ( V_4 -> V_5 == V_7 ) {
struct V_52 * V_53 ;
F_26 (p, &crtc->dev->mode_config.plane_list,
head) {
struct V_54 * V_55 = F_27 ( V_53 ) ;
if ( ( V_55 -> V_57 & V_78 ) <= V_79 )
if ( V_55 -> V_5 != V_63 )
return 0 ;
}
F_17 ( V_2 ) ;
}
return 0 ;
}
int F_43 ( struct V_50 * V_11 , unsigned int V_48 )
{
struct V_72 * V_80 = V_11 -> V_74 ;
struct V_12 * V_13 = V_80 -> V_13 ;
struct V_68 * V_71 = & V_13 -> V_71 ;
struct V_1 * V_2 = & V_13 -> V_4 [ V_48 ] -> V_1 ;
F_3 ( L_1 ) ;
if ( F_44 ( V_48 == V_31 ?
V_13 -> V_38 : V_13 -> V_39 ,
V_71 , V_2 ) ) {
F_13 ( L_15 ) ;
return - V_41 ;
}
return 0 ;
}
void F_45 ( struct V_50 * V_51 , unsigned int V_48 )
{
struct V_72 * V_73 = V_51 -> V_74 ;
struct V_12 * V_13 = V_73 -> V_13 ;
struct V_68 * V_71 = & V_13 -> V_71 ;
struct V_1 * V_2 = & V_13 -> V_4 [ V_48 ] -> V_1 ;
F_3 ( L_1 ) ;
if ( F_46 ( V_48 == V_31 ?
V_13 -> V_38 : V_13 -> V_39 , V_71 ) )
F_3 ( L_16 ) ;
if ( V_13 -> V_4 [ V_48 ] -> V_49 ) {
F_41 ( V_2 ) ;
V_13 -> V_4 [ V_48 ] -> V_49 = NULL ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_7 ( V_4 -> V_11 ) ;
if ( F_22 ( V_2 ) == 0 )
return F_48 ( V_13 , V_2 -> V_11 -> V_81 ) ;
return 0 ;
}
bool F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_19 == V_31 )
return true ;
return false ;
}
int F_50 ( struct V_50 * V_51 , struct V_3 * V_4 ,
struct V_52 * V_81 , struct V_52 * V_82 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
int V_83 ;
V_83 = F_51 ( V_51 , V_2 , V_81 , V_82 ,
& V_84 , NULL ) ;
if ( V_83 ) {
F_13 ( L_17 ) ;
return - V_41 ;
}
F_52 ( V_2 , & V_85 ) ;
F_3 ( L_18 ,
V_2 -> V_18 . V_19 , F_9 ( V_4 ) ) ;
return 0 ;
}
