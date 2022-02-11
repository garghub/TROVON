static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
V_6 -> V_7 = V_8 ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
V_6 -> V_7 = V_9 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_16 * V_17 , * V_18 ;
int V_19 = V_11 -> clock * 1000 ;
F_8 ( L_2 ,
V_2 -> V_20 . V_21 , F_9 ( V_6 ) ,
V_11 -> V_20 . V_21 , V_11 -> V_22 ) ;
F_8 ( L_3 ,
V_11 -> V_23 , V_11 -> clock ,
V_11 -> V_24 ,
V_11 -> V_25 , V_11 -> V_26 ,
V_11 -> V_27 ,
V_11 -> V_28 ,
V_11 -> V_29 , V_11 -> V_30 ,
V_11 -> V_31 , V_11 -> type , V_11 -> V_32 ) ;
if ( V_6 -> V_21 == V_33 ) {
V_17 = V_15 -> V_34 ;
V_18 = V_15 -> V_35 ;
} else {
V_17 = V_15 -> V_36 ;
V_18 = V_15 -> V_37 ;
}
if ( F_10 ( V_17 ) ) {
F_11 ( L_4 ) ;
goto V_38;
}
if ( F_12 ( V_18 , V_19 ) < 0 ) {
F_13 ( L_5 , V_19 ) ;
goto V_39;
}
if ( F_10 ( V_18 ) ) {
F_13 ( L_6 ) ;
goto V_39;
}
F_14 ( V_15 -> V_40 [ V_6 -> V_21 ] , & V_2 -> V_11 ) ;
if ( F_15 ( V_6 , & V_2 -> V_11 ) ) {
F_13 ( L_7 ) ;
goto V_41;
}
return 0 ;
V_41:
F_16 ( V_18 ) ;
V_39:
F_16 ( V_17 ) ;
V_38:
return - V_42 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
F_8 ( L_8 , V_2 -> V_20 . V_21 , F_9 ( V_6 ) ) ;
F_18 ( V_6 , false ) ;
F_19 ( V_2 ) ;
if ( V_6 -> V_21 == V_33 ) {
F_16 ( V_15 -> V_35 ) ;
F_16 ( V_15 -> V_34 ) ;
} else {
F_16 ( V_15 -> V_37 ) ;
F_16 ( V_15 -> V_36 ) ;
}
V_6 -> V_7 = V_43 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 , & V_2 -> V_44 -> V_45 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_46 )
{
struct V_47 * V_48 = V_2 -> V_13 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_6 -> V_13 ) ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
unsigned long V_32 ;
F_3 ( L_1 ) ;
F_22 (p, &drm_dev->mode_config.plane_list, head) {
struct V_53 * V_54 = F_23 ( V_50 ) ;
switch ( V_54 -> V_7 ) {
case V_55 :
if ( V_50 -> V_44 -> V_2 != V_2 )
continue;
F_3 ( L_9 ,
F_24 ( V_54 ) ) ;
if ( F_25 ( V_6 , V_54 ) ) {
F_13 ( L_10 ,
F_24 ( V_54 ) ) ;
break;
}
if ( F_26 ( V_6 , V_54 , true ) ) {
F_13 ( L_11 ,
F_24 ( V_54 ) ) ;
break;
}
if ( V_54 -> V_56 == V_57 )
F_27 ( V_15 -> V_58 [ 0 ] , V_50 -> V_44 ) ;
V_54 -> V_7 = V_59 ;
break;
case V_60 :
F_3 ( L_12 ,
F_24 ( V_54 ) ) ;
if ( F_26 ( V_6 , V_54 , false ) ) {
F_13 ( L_13 ,
F_24 ( V_54 ) ) ;
continue;
}
if ( V_54 -> V_56 == V_61 )
V_54 -> V_7 = V_62 ;
else
V_54 -> V_7 = V_63 ;
if ( V_54 -> V_56 == V_57 )
F_28 ( V_15 -> V_58 [ 0 ] ) ;
break;
default:
break;
}
}
V_52 = V_2 -> V_44 -> V_52 ;
if ( V_52 ) {
V_2 -> V_44 -> V_52 = NULL ;
F_29 ( & V_2 -> V_13 -> V_64 , V_32 ) ;
if ( F_30 ( V_2 ) == 0 )
F_31 ( V_2 , V_52 ) ;
else
F_32 ( V_2 , V_52 ) ;
F_33 ( & V_2 -> V_13 -> V_64 , V_32 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_8 ( L_1 ) ;
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
T_1 V_67 )
{
F_8 ( L_1 ) ;
return 0 ;
}
int F_37 ( struct V_68 * V_69 ,
unsigned long V_52 , void * V_70 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 = V_70 ;
struct V_5 * V_6 ;
struct V_71 * V_72 ;
unsigned int V_73 ;
V_72 = V_2 -> V_13 -> V_74 ;
V_73 = F_38 ( V_2 ) ;
V_15 = F_39 ( V_69 , struct V_14 , V_75 [ V_73 ] ) ;
V_6 = V_15 -> V_6 [ V_73 ] ;
if ( ( V_52 != V_76 ) &&
( V_52 != V_77 ) ) {
F_13 ( L_14 , V_52 ) ;
return - V_42 ;
}
F_40 ( V_2 ) ;
if ( V_6 -> V_7 == V_9 ) {
struct V_49 * V_50 ;
F_22 (p, &crtc->dev->mode_config.plane_list,
head) {
struct V_53 * V_54 = F_23 ( V_50 ) ;
if ( ( V_54 -> V_56 & V_78 ) <= V_79 )
if ( V_54 -> V_7 != V_62 )
return 0 ;
}
F_17 ( V_2 ) ;
}
return 0 ;
}
int F_41 ( struct V_47 * V_13 , unsigned int V_73 )
{
struct V_71 * V_80 = V_13 -> V_74 ;
struct V_14 * V_15 = V_80 -> V_15 ;
struct V_68 * V_75 = & V_15 -> V_75 [ V_73 ] ;
struct V_1 * V_2 = & V_15 -> V_6 [ V_73 ] -> V_1 ;
struct V_81 * V_40 = V_15 -> V_40 [ V_73 ] ;
F_3 ( L_1 ) ;
if ( F_42 ( V_40 , V_75 , V_2 ) ) {
F_13 ( L_15 ) ;
return - V_42 ;
}
return 0 ;
}
void F_43 ( struct V_47 * V_48 , unsigned int V_73 )
{
struct V_71 * V_72 = V_48 -> V_74 ;
struct V_14 * V_15 = V_72 -> V_15 ;
struct V_68 * V_75 = & V_15 -> V_75 [ V_73 ] ;
struct V_81 * V_40 = V_15 -> V_40 [ V_73 ] ;
F_3 ( L_1 ) ;
if ( F_44 ( V_40 , V_75 ) )
F_3 ( L_16 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_6 -> V_13 ) ;
if ( F_38 ( V_2 ) == 0 )
return F_46 ( V_15 , V_2 -> V_13 -> V_82 ) ;
return 0 ;
}
bool F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_21 == V_33 )
return true ;
return false ;
}
int F_48 ( struct V_47 * V_48 , struct V_5 * V_6 ,
struct V_49 * V_82 , struct V_49 * V_83 )
{
struct V_1 * V_2 = & V_6 -> V_1 ;
int V_84 ;
V_84 = F_49 ( V_48 , V_2 , V_82 , V_83 ,
& V_85 , NULL ) ;
if ( V_84 ) {
F_13 ( L_17 ) ;
return - V_42 ;
}
F_50 ( V_2 , & V_86 ) ;
F_3 ( L_18 ,
V_2 -> V_20 . V_21 , F_9 ( V_6 ) ) ;
return 0 ;
}
