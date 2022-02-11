static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
}
static void F_6 ( struct V_5 * V_6 )
{
}
static void F_7 ( struct V_5 * V_6 ,
T_1 * V_7 , T_1 * V_8 , T_1 * V_9 ,
T_2 V_10 , T_2 V_11 )
{
}
static void F_8 ( struct V_5 * V_6 )
{
F_1 ( F_9 ( V_6 ) ) ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_1 * V_17 ;
struct V_18 * V_19 = NULL ;
struct V_5 * V_6 = NULL ;
int V_20 = 0 ;
if ( ! ( V_13 -> V_21 & V_22 ) ) {
int V_23 = 0 , V_24 = 0 ;
F_11 (entry, &lds->active, active) {
V_6 = & V_17 -> V_4 . V_6 ;
V_23 = F_12 ( V_23 , V_6 -> V_25 + V_6 -> V_26 . V_27 ) ;
V_24 = F_12 ( V_24 , V_6 -> V_28 + V_6 -> V_26 . V_29 ) ;
V_20 ++ ;
}
if ( V_6 == NULL )
return 0 ;
V_19 = V_17 -> V_4 . V_6 . V_19 ;
F_13 ( V_13 , V_23 , V_24 , V_19 -> V_30 ,
V_19 -> V_31 , V_19 -> V_32 ) ;
return 0 ;
}
if ( ! F_14 ( & V_15 -> V_3 ) ) {
V_17 = F_15 ( V_15 -> V_3 . V_33 , F_16 ( * V_17 ) , V_3 ) ;
V_19 = V_17 -> V_4 . V_6 . V_19 ;
F_13 ( V_13 , V_19 -> V_34 , V_19 -> V_35 , V_19 -> V_30 ,
V_19 -> V_31 , V_19 -> V_32 ) ;
}
F_17 ( V_13 , V_36 ,
V_15 -> V_37 ? V_15 -> V_37 : 1 ) ;
V_20 = 0 ;
F_11 (entry, &lds->active, active) {
V_6 = & V_17 -> V_4 . V_6 ;
F_17 ( V_13 , V_38 , V_20 ) ;
F_17 ( V_13 , V_39 , ! V_20 ) ;
F_17 ( V_13 , V_40 , V_6 -> V_25 ) ;
F_17 ( V_13 , V_41 , V_6 -> V_28 ) ;
F_17 ( V_13 , V_42 , V_6 -> V_26 . V_27 ) ;
F_17 ( V_13 , V_43 , V_6 -> V_26 . V_29 ) ;
F_17 ( V_13 , V_38 , V_44 ) ;
V_20 ++ ;
}
F_18 ( V_20 != V_15 -> V_37 ) ;
V_15 -> V_45 = V_15 -> V_37 ;
return 0 ;
}
static int F_19 ( struct V_12 * V_46 ,
struct V_1 * V_2 )
{
struct V_14 * V_47 = V_46 -> V_16 ;
if ( F_14 ( & V_2 -> V_3 ) )
return 0 ;
F_2 ( & V_2 -> V_3 ) ;
if ( -- ( V_47 -> V_37 ) == 0 ) {
F_18 ( ! V_47 -> V_19 ) ;
if ( V_47 -> V_19 -> V_48 )
V_47 -> V_19 -> V_48 ( V_47 -> V_19 ) ;
V_47 -> V_19 = NULL ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_46 ,
struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_14 * V_47 = V_46 -> V_16 ;
struct V_1 * V_17 ;
struct V_51 * V_52 ;
F_18 ( ! V_47 -> V_37 && V_47 -> V_19 ) ;
if ( V_50 != V_47 -> V_19 ) {
if ( V_47 -> V_19 && V_47 -> V_19 -> V_48 )
V_47 -> V_19 -> V_48 ( V_47 -> V_19 ) ;
if ( V_50 -> V_53 )
V_50 -> V_53 ( V_50 ) ;
V_47 -> V_19 = V_50 ;
}
if ( ! F_14 ( & V_2 -> V_3 ) )
return 0 ;
V_52 = & V_47 -> V_3 ;
F_11 (entry, &ld->active, active) {
if ( V_17 -> V_4 . V_54 > V_2 -> V_4 . V_54 )
break;
V_52 = & V_17 -> V_3 ;
}
F_21 ( & V_2 -> V_3 , V_52 ) ;
V_47 -> V_37 ++ ;
return 0 ;
}
static int F_22 ( struct V_55 * V_56 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_59 * V_26 ;
struct V_60 * V_61 ;
struct V_49 * V_50 ;
struct V_18 * V_19 ;
struct V_5 * V_6 ;
if ( ! V_56 )
return - V_62 ;
if ( ! V_56 -> V_6 )
return - V_62 ;
V_6 = V_56 -> V_6 ;
V_2 = F_9 ( V_6 ) ;
V_50 = V_56 -> V_19 ? F_23 ( V_56 -> V_19 ) : NULL ;
V_13 = V_46 ( V_6 -> V_63 ) ;
if ( V_56 -> V_64 > 1 ) {
F_24 ( L_1 ) ;
return - V_62 ;
}
if ( V_56 -> V_64 == 1 &&
V_56 -> V_65 [ 0 ] != & V_2 -> V_4 . V_58 ) {
F_24 ( L_2 ,
V_56 -> V_65 [ 0 ] , & V_2 -> V_4 . V_58 ) ;
return - V_62 ;
}
if ( V_13 -> V_16 -> V_19 && V_50 &&
! ( V_13 -> V_16 -> V_37 == 1 &&
! F_14 ( & V_2 -> V_3 ) ) &&
V_13 -> V_16 -> V_19 != V_50 ) {
F_24 ( L_3 ) ;
return - V_62 ;
}
V_58 = & V_2 -> V_4 . V_58 ;
V_61 = & V_2 -> V_4 . V_61 ;
if ( V_56 -> V_64 == 0 || ! V_56 -> V_26 || ! V_56 -> V_19 ) {
V_58 -> V_61 = NULL ;
V_61 -> V_6 = NULL ;
V_6 -> V_19 = NULL ;
F_19 ( V_13 , V_2 ) ;
F_10 ( V_13 ) ;
return 0 ;
}
V_26 = V_56 -> V_26 ;
V_19 = V_56 -> V_19 ;
if ( V_56 -> V_25 + V_26 -> V_27 > V_19 -> V_34 ||
V_56 -> V_28 + V_26 -> V_29 > V_19 -> V_35 ) {
F_24 ( L_4 ) ;
return - V_62 ;
}
F_25 ( V_13 ) ;
V_6 -> V_19 = V_19 ;
V_61 -> V_6 = V_6 ;
V_58 -> V_61 = V_61 ;
V_6 -> V_25 = V_56 -> V_25 ;
V_6 -> V_28 = V_56 -> V_28 ;
V_6 -> V_26 = * V_26 ;
F_20 ( V_13 , V_2 , V_50 ) ;
F_10 ( V_13 ) ;
return 0 ;
}
static void F_26 ( struct V_60 * V_61 )
{
F_1 ( F_27 ( V_61 ) ) ;
}
static void F_28 ( struct V_57 * V_58 , int V_26 )
{
}
static void F_29 ( struct V_57 * V_58 )
{
}
static void F_30 ( struct V_57 * V_58 )
{
}
static enum V_66
F_31 ( struct V_57 * V_58 ,
bool V_67 )
{
if ( F_32 ( V_58 ) -> V_68 )
return V_69 ;
return V_70 ;
}
static int F_33 ( struct V_57 * V_58 ,
T_2 V_71 , T_2 V_72 )
{
struct V_1 * V_2 = F_32 ( V_58 ) ;
struct V_73 * V_63 = V_58 -> V_63 ;
struct V_12 * V_13 = V_46 ( V_63 ) ;
struct V_59 * V_26 = NULL ;
struct V_59 V_74 = { F_34 ( L_5 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_20 ;
{
V_26 = F_35 ( V_63 , & V_74 ) ;
if ( ! V_26 )
return 0 ;
V_26 -> V_27 = V_2 -> V_75 ;
V_26 -> V_29 = V_2 -> V_76 ;
V_26 -> V_77 = F_36 ( V_26 ) ;
if ( F_37 ( V_13 , V_26 -> V_27 * 2 ,
V_26 -> V_29 ) ) {
F_38 ( V_58 , V_26 ) ;
if ( V_2 -> V_78 ) {
F_2 ( & V_2 -> V_78 -> V_79 ) ;
F_39 ( V_63 , V_2 -> V_78 ) ;
}
V_2 -> V_78 = V_26 ;
}
}
for ( V_20 = 0 ; V_80 [ V_20 ] . type != 0 ; V_20 ++ ) {
const struct V_59 * V_81 ;
V_81 = & V_80 [ V_20 ] ;
if ( V_81 -> V_27 > V_71 ||
V_81 -> V_29 > V_72 )
continue;
if ( ! F_37 ( V_13 , V_81 -> V_27 * 2 ,
V_81 -> V_29 ) )
continue;
V_26 = F_35 ( V_63 , V_81 ) ;
if ( ! V_26 )
return 0 ;
V_26 -> V_77 = F_36 ( V_26 ) ;
F_38 ( V_58 , V_26 ) ;
}
F_40 ( V_58 ) ;
return 1 ;
}
static int F_41 ( struct V_57 * V_58 ,
struct V_82 * V_83 ,
T_3 V_84 )
{
return 0 ;
}
static void F_42 ( struct V_57 * V_58 )
{
F_1 ( F_32 ( V_58 ) ) ;
}
static int F_43 ( struct V_12 * V_13 , unsigned V_54 )
{
struct V_1 * V_2 ;
struct V_73 * V_63 = V_13 -> V_63 ;
struct V_57 * V_58 ;
struct V_60 * V_61 ;
struct V_5 * V_6 ;
V_2 = F_44 ( sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_2 -> V_4 . V_54 = V_54 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_61 = & V_2 -> V_4 . V_61 ;
V_58 = & V_2 -> V_4 . V_58 ;
F_45 ( & V_2 -> V_3 ) ;
V_2 -> V_68 = ( V_54 == 0 ) ;
V_2 -> V_75 = 800 ;
V_2 -> V_76 = 600 ;
V_2 -> V_78 = NULL ;
F_46 ( V_63 , V_58 , & V_87 ,
V_88 ) ;
V_58 -> V_89 = F_31 ( V_58 , true ) ;
F_47 ( V_63 , V_61 , & V_90 ,
V_91 ) ;
F_48 ( V_58 , V_61 ) ;
V_61 -> V_92 = ( 1 << V_54 ) ;
V_61 -> V_93 = 0 ;
F_49 ( V_63 , V_6 , & V_94 ) ;
F_50 ( V_58 ,
V_63 -> V_95 . V_96 ,
1 ) ;
return 0 ;
}
int F_51 ( struct V_12 * V_13 )
{
struct V_73 * V_63 = V_13 -> V_63 ;
int V_20 ;
int V_97 ;
if ( V_13 -> V_16 ) {
F_52 ( L_6 ) ;
return - V_62 ;
}
V_13 -> V_16 = F_53 ( sizeof( * V_13 -> V_16 ) , V_85 ) ;
if ( ! V_13 -> V_16 )
return - V_86 ;
F_45 ( & V_13 -> V_16 -> V_3 ) ;
V_13 -> V_16 -> V_37 = 0 ;
V_13 -> V_16 -> V_45 = 0 ;
V_13 -> V_16 -> V_19 = NULL ;
F_54 ( V_13 -> V_63 ) ;
if ( V_13 -> V_21 & V_98 ) {
for ( V_20 = 0 ; V_20 < V_99 ; ++ V_20 )
F_43 ( V_13 , V_20 ) ;
V_97 = F_55 ( V_63 , V_99 ) ;
} else {
F_43 ( V_13 , 0 ) ;
V_97 = F_55 ( V_63 , 1 ) ;
}
return V_97 ;
}
int F_56 ( struct V_12 * V_13 )
{
struct V_73 * V_63 = V_13 -> V_63 ;
F_57 ( V_63 ) ;
if ( ! V_13 -> V_16 )
return - V_100 ;
F_18 ( ! F_14 ( & V_13 -> V_16 -> V_3 ) ) ;
F_4 ( V_13 -> V_16 ) ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 , unsigned V_101 ,
struct V_102 * V_103 )
{
struct V_73 * V_63 = V_13 -> V_63 ;
struct V_1 * V_2 ;
struct V_57 * V_104 ;
int V_20 ;
F_59 ( & V_63 -> V_95 . V_105 ) ;
#if 0
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < (int)num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
#else
( void ) V_20 ;
#endif
F_11 (con, &dev->mode_config.connector_list, head) {
V_2 = F_32 ( V_104 ) ;
if ( V_101 > V_2 -> V_4 . V_54 ) {
V_2 -> V_75 = V_103 [ V_2 -> V_4 . V_54 ] . V_23 ;
V_2 -> V_76 = V_103 [ V_2 -> V_4 . V_54 ] . V_24 ;
V_2 -> V_68 = true ;
} else {
V_2 -> V_75 = 800 ;
V_2 -> V_76 = 600 ;
V_2 -> V_68 = false ;
}
V_104 -> V_89 = F_31 ( V_104 , true ) ;
}
F_60 ( & V_63 -> V_95 . V_105 ) ;
return 0 ;
}
