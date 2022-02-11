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
F_14 ( V_13 -> V_38 [ V_4 -> V_19 ] , & V_2 -> V_9 ) ;
if ( F_15 ( V_4 , & V_2 -> V_9 ) ) {
F_13 ( L_7 ) ;
goto V_39;
}
return 0 ;
V_39:
F_16 ( V_16 ) ;
V_37:
F_16 ( V_15 ) ;
V_36:
return - V_40 ;
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
V_4 -> V_5 = V_41 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 , & V_2 -> V_42 -> V_43 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = V_2 -> V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_7 ( V_4 -> V_11 ) ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
unsigned long V_30 ;
F_3 ( L_1 ) ;
F_22 (p, &drm_dev->mode_config.plane_list, head) {
struct V_52 * V_53 = F_23 ( V_49 ) ;
switch ( V_53 -> V_5 ) {
case V_54 :
if ( V_49 -> V_42 -> V_2 != V_2 )
continue;
F_3 ( L_9 ,
F_24 ( V_53 ) ) ;
if ( F_25 ( V_4 , V_53 ) ) {
F_13 ( L_10 ,
F_24 ( V_53 ) ) ;
break;
}
if ( F_26 ( V_4 , V_53 , true ) ) {
F_13 ( L_11 ,
F_24 ( V_53 ) ) ;
break;
}
if ( V_53 -> V_55 == V_56 )
F_27 ( V_13 -> V_57 [ 0 ] , V_49 -> V_42 ) ;
V_53 -> V_5 = V_58 ;
break;
case V_59 :
F_3 ( L_12 ,
F_24 ( V_53 ) ) ;
if ( F_26 ( V_4 , V_53 , false ) ) {
F_13 ( L_13 ,
F_24 ( V_53 ) ) ;
continue;
}
if ( V_53 -> V_55 == V_60 )
V_53 -> V_5 = V_61 ;
else
V_53 -> V_5 = V_62 ;
if ( V_53 -> V_55 == V_56 )
F_28 ( V_13 -> V_57 [ 0 ] ) ;
break;
default:
break;
}
}
V_51 = V_2 -> V_42 -> V_51 ;
if ( V_51 ) {
V_2 -> V_42 -> V_51 = NULL ;
F_29 ( & V_2 -> V_11 -> V_63 , V_30 ) ;
if ( F_30 ( V_2 ) == 0 )
F_31 ( V_2 , V_51 ) ;
else
F_32 ( V_2 , V_51 ) ;
F_33 ( & V_2 -> V_11 -> V_63 , V_30 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_8 ( L_1 ) ;
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
T_1 V_66 )
{
F_8 ( L_1 ) ;
return 0 ;
}
int F_37 ( struct V_67 * V_68 ,
unsigned long V_51 , void * V_69 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 = V_69 ;
struct V_3 * V_4 ;
struct V_70 * V_71 ;
unsigned int V_72 ;
V_71 = V_2 -> V_11 -> V_73 ;
V_72 = F_38 ( V_2 ) ;
V_13 = F_39 ( V_68 , struct V_12 , V_74 [ V_72 ] ) ;
V_4 = V_13 -> V_4 [ V_72 ] ;
if ( ( V_51 != V_75 ) &&
( V_51 != V_76 ) ) {
F_13 ( L_14 , V_51 ) ;
return - V_40 ;
}
F_40 ( V_2 ) ;
if ( V_4 -> V_5 == V_7 ) {
struct V_48 * V_49 ;
F_22 (p, &crtc->dev->mode_config.plane_list,
head) {
struct V_52 * V_53 = F_23 ( V_49 ) ;
if ( ( V_53 -> V_55 & V_77 ) <= V_78 )
if ( V_53 -> V_5 != V_61 )
return 0 ;
}
F_17 ( V_2 ) ;
}
return 0 ;
}
int F_41 ( struct V_46 * V_11 , unsigned int V_72 )
{
struct V_70 * V_79 = V_11 -> V_73 ;
struct V_12 * V_13 = V_79 -> V_13 ;
struct V_67 * V_74 = & V_13 -> V_74 [ V_72 ] ;
struct V_1 * V_2 = & V_13 -> V_4 [ V_72 ] -> V_1 ;
struct V_80 * V_38 = V_13 -> V_38 [ V_72 ] ;
F_3 ( L_1 ) ;
if ( F_42 ( V_38 , V_74 , V_2 ) ) {
F_13 ( L_15 ) ;
return - V_40 ;
}
return 0 ;
}
void F_43 ( struct V_46 * V_47 , unsigned int V_72 )
{
struct V_70 * V_71 = V_47 -> V_73 ;
struct V_12 * V_13 = V_71 -> V_13 ;
struct V_67 * V_74 = & V_13 -> V_74 [ V_72 ] ;
struct V_80 * V_38 = V_13 -> V_38 [ V_72 ] ;
F_3 ( L_1 ) ;
if ( F_44 ( V_38 , V_74 ) )
F_3 ( L_16 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_7 ( V_4 -> V_11 ) ;
if ( F_38 ( V_2 ) == 0 )
return F_46 ( V_13 , V_2 -> V_11 -> V_81 ) ;
return 0 ;
}
bool F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_19 == V_31 )
return true ;
return false ;
}
int F_48 ( struct V_46 * V_47 , struct V_3 * V_4 ,
struct V_48 * V_81 , struct V_48 * V_82 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
int V_83 ;
V_83 = F_49 ( V_47 , V_2 , V_81 , V_82 ,
& V_84 , NULL ) ;
if ( V_83 ) {
F_13 ( L_17 ) ;
return - V_40 ;
}
F_50 ( V_2 , & V_85 ) ;
F_3 ( L_18 ,
V_2 -> V_18 . V_19 , F_9 ( V_4 ) ) ;
return 0 ;
}
