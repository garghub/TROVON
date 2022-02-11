static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> clock = V_4 -> V_5 ;
V_2 -> V_6 = V_4 -> V_7 ;
V_2 -> V_8 = V_2 -> V_6 + V_4 -> V_9 ;
V_2 -> V_10 = V_2 -> V_8 + V_4 -> V_11 ;
V_2 -> V_12 = V_2 -> V_10 + V_4 -> V_13 ;
V_2 -> V_14 = V_4 -> V_15 ;
V_2 -> V_16 = V_2 -> V_14 + V_4 -> V_17 ;
V_2 -> V_18 = V_2 -> V_16 + V_4 -> V_19 ;
V_2 -> V_20 = V_2 -> V_18 + V_4 -> V_21 ;
}
static inline void F_2 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
V_4 -> V_5 = V_2 -> clock ;
V_4 -> V_7 = V_2 -> V_6 ;
V_4 -> V_9 = V_2 -> V_8 - V_2 -> V_6 ;
V_4 -> V_11 = V_2 -> V_10 - V_2 -> V_8 ;
V_4 -> V_13 = V_2 -> V_12 - V_2 -> V_10 ;
V_4 -> V_15 = V_2 -> V_14 ;
V_4 -> V_17 = V_2 -> V_16 - V_2 -> V_14 ;
V_4 -> V_19 = V_2 -> V_18 - V_2 -> V_16 ;
V_4 -> V_21 = V_2 -> V_20 - V_2 -> V_18 ;
}
static void F_3 ( struct V_22 * V_23 , int V_2 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
int V_27 ;
F_5 ( L_1 , V_26 -> V_28 , V_2 ) ;
V_27 = V_23 -> V_29 ;
if ( V_2 < V_27 )
F_6 ( V_23 , V_2 ) ;
if ( V_2 == V_30 ) {
switch ( V_26 -> V_31 ) {
case V_32 :
V_26 -> V_33 = true ;
break;
case V_34 : {
int V_35 = V_26 -> V_36 -> V_37 ( V_26 ) ;
if ( V_35 ) {
F_5 ( L_2 ,
V_26 -> V_28 , V_35 ) ;
V_26 -> V_36 -> V_38 ( V_26 ) ;
}
break;
}
default:
break;
}
} else {
}
if ( V_2 > V_27 )
F_6 ( V_23 , V_2 ) ;
}
enum V_39 F_7 (
struct V_22 * V_23 , bool V_40 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = V_26 -> V_36 ;
enum V_39 V_35 ;
if ( V_42 -> V_43 ) {
if ( V_42 -> V_43 ( V_26 ) ) {
V_35 = V_44 ;
} else {
V_35 = V_45 ;
}
} else {
V_35 = V_46 ;
}
F_8 ( L_3 , V_24 -> V_26 -> V_28 , V_35 , V_40 ) ;
return V_35 ;
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
V_26 -> V_36 -> V_38 ( V_26 ) ;
F_5 ( L_4 , V_24 -> V_26 -> V_28 ) ;
F_10 ( V_23 ) ;
F_11 ( V_23 ) ;
F_12 ( V_24 ) ;
F_13 ( V_26 ) ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = V_26 -> V_36 ;
struct V_47 * V_48 = V_23 -> V_48 ;
int V_49 = 0 ;
F_5 ( L_4 , V_24 -> V_26 -> V_28 ) ;
if ( V_42 -> V_50 ) {
void * V_51 = F_15 ( V_52 , V_53 ) ;
if ( ( V_42 -> V_50 ( V_26 , V_51 , V_52 ) > 0 ) &&
F_16 ( V_51 ) ) {
F_17 (
V_23 , V_51 ) ;
V_49 = F_18 ( V_23 , V_51 ) ;
F_12 ( V_23 -> V_54 . V_55 ) ;
V_23 -> V_54 . V_55 = V_51 ;
} else {
F_17 (
V_23 , NULL ) ;
V_23 -> V_54 . V_55 = NULL ;
F_12 ( V_51 ) ;
}
} else {
struct V_1 * V_2 = F_19 ( V_48 ) ;
struct V_3 V_4 ;
V_42 -> V_56 ( V_26 , & V_4 ) ;
F_1 ( V_2 , & V_4 ) ;
V_2 -> type = V_57 | V_58 ;
F_20 ( V_2 ) ;
F_21 ( V_23 , V_2 ) ;
V_49 = 1 ;
}
return V_49 ;
}
static int F_22 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = V_26 -> V_36 ;
struct V_3 V_4 = { 0 } ;
struct V_47 * V_48 = V_23 -> V_48 ;
struct V_1 * V_59 ;
int V_35 = V_60 ;
F_2 ( & V_4 , V_2 ) ;
V_2 -> V_61 = F_23 ( V_2 ) ;
if ( ! V_42 -> V_62 ( V_26 , & V_4 ) ) {
V_59 = F_24 ( V_48 , V_2 ) ;
V_59 -> clock = V_4 . V_5 ;
V_59 -> V_61 = 0 ;
if ( V_2 -> V_61 == F_23 ( V_59 ) )
V_35 = V_63 ;
F_25 ( V_48 , V_59 ) ;
}
F_5 ( L_5
L_6 ,
( V_35 == V_63 ) ? L_7 : L_8 ,
V_2 -> V_64 . V_65 , V_2 -> V_28 , V_2 -> V_61 , V_2 -> clock ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_16 ,
V_2 -> V_18 , V_2 -> V_20 , V_2 -> type , V_2 -> V_66 ) ;
return V_35 ;
}
struct V_67 * F_26 (
struct V_22 * V_23 )
{
int V_68 ;
struct V_24 * V_24 = F_4 ( V_23 ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
struct V_70 * V_71 ;
if ( V_23 -> V_72 [ V_68 ] == 0 )
break;
V_71 = F_27 ( V_23 -> V_48 ,
V_23 -> V_72 [ V_68 ] ,
V_73 ) ;
if ( V_71 ) {
struct V_67 * V_74 = F_28 ( V_71 ) ;
struct V_75 * V_76 =
F_29 ( V_74 ) ;
F_5 ( L_9 , V_24 -> V_26 -> V_28 ,
V_76 -> V_28 ) ;
return V_74 ;
}
}
F_5 ( L_10 , V_24 -> V_26 -> V_28 ) ;
return NULL ;
}
void F_30 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_23 -> V_48 ;
struct V_24 * V_24 = F_4 ( V_23 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = V_26 -> V_36 ;
struct V_3 V_4 ;
F_2 ( & V_4 , V_2 ) ;
F_5 ( L_11 ,
V_24 -> V_26 -> V_28 ,
V_2 -> V_64 . V_65 , V_2 -> V_28 , V_2 -> V_61 , V_2 -> clock ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_16 ,
V_2 -> V_18 , V_2 -> V_20 , V_2 -> type , V_2 -> V_66 ) ;
if ( V_42 -> V_62 ( V_26 , & V_4 ) ) {
F_31 ( V_48 -> V_48 , L_12 ) ;
return;
}
V_42 -> V_77 ( V_26 , & V_4 ) ;
}
void F_32 ( struct V_22 * V_23 ,
int V_78 , int V_79 , int V_80 , int V_81 )
{
struct V_24 * V_24 = F_4 ( V_23 ) ;
F_8 ( L_13 , V_24 -> V_26 -> V_28 , V_78 , V_79 , V_80 , V_81 ) ;
}
struct V_22 * F_33 ( struct V_47 * V_48 ,
int V_82 , struct V_25 * V_26 )
{
struct V_22 * V_23 = NULL ;
struct V_24 * V_24 ;
F_5 ( L_4 , V_26 -> V_28 ) ;
F_34 ( V_26 ) ;
V_24 = F_15 ( sizeof( struct V_24 ) , V_53 ) ;
if ( ! V_24 ) {
F_31 ( V_48 -> V_48 , L_14 ) ;
goto V_83;
}
V_24 -> V_26 = V_26 ;
V_23 = & V_24 -> V_64 ;
F_35 ( V_48 , V_23 , & V_84 ,
V_82 ) ;
F_36 ( V_23 , & V_85 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_23 -> V_86 = V_87 |
V_88 ;
V_23 -> V_89 = 1 ;
V_23 -> V_90 = 0 ;
F_37 ( V_23 ) ;
return V_23 ;
V_83:
if ( V_23 ) {
F_9 ( V_23 ) ;
}
return NULL ;
}
