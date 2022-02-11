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
V_2 -> V_22 = 0 ;
if ( V_4 -> V_23 )
V_2 -> V_22 |= V_24 ;
if ( V_4 -> V_25 == V_26 )
V_2 -> V_22 |= V_27 ;
else
V_2 -> V_22 |= V_28 ;
if ( V_4 -> V_29 == V_26 )
V_2 -> V_22 |= V_30 ;
else
V_2 -> V_22 |= V_31 ;
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
V_4 -> V_23 = ! ! ( V_2 -> V_22 & V_24 ) ;
if ( V_2 -> V_22 & V_27 )
V_4 -> V_25 = V_26 ;
else
V_4 -> V_25 = V_32 ;
if ( V_2 -> V_22 & V_30 )
V_4 -> V_29 = V_26 ;
else
V_4 -> V_29 = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 = V_26 ;
V_4 -> V_36 = V_37 ;
}
static void F_3 ( struct V_38 * V_39 , int V_2 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
int V_43 ;
F_5 ( L_1 , V_42 -> V_44 , V_2 ) ;
V_43 = V_39 -> V_45 ;
if ( V_2 < V_43 )
F_6 ( V_39 , V_2 ) ;
if ( V_2 == V_46 ) {
switch ( V_42 -> V_47 ) {
case V_48 :
V_42 -> V_49 = true ;
break;
case V_50 : {
int V_51 = V_42 -> V_52 -> V_53 ( V_42 ) ;
if ( V_51 ) {
F_5 ( L_2 ,
V_42 -> V_44 , V_51 ) ;
V_42 -> V_52 -> V_54 ( V_42 ) ;
}
break;
}
default:
break;
}
} else {
}
if ( V_2 > V_43 )
F_6 ( V_39 , V_2 ) ;
}
enum V_55 F_7 (
struct V_38 * V_39 , bool V_56 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_57 * V_58 = V_42 -> V_52 ;
enum V_55 V_51 ;
if ( V_58 -> V_59 ) {
if ( V_58 -> V_59 ( V_42 ) ) {
V_51 = V_60 ;
} else {
V_51 = V_61 ;
}
} else {
V_51 = V_62 ;
}
F_8 ( L_3 , V_40 -> V_42 -> V_44 , V_51 , V_56 ) ;
return V_51 ;
}
static void F_9 ( struct V_38 * V_39 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
V_42 -> V_52 -> V_54 ( V_42 ) ;
F_5 ( L_4 , V_40 -> V_42 -> V_44 ) ;
F_10 ( V_39 ) ;
F_11 ( V_39 ) ;
F_12 ( V_40 ) ;
F_13 ( V_42 ) ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_57 * V_58 = V_42 -> V_52 ;
struct V_63 * V_64 = V_39 -> V_64 ;
int V_65 = 0 ;
F_5 ( L_4 , V_40 -> V_42 -> V_44 ) ;
if ( V_58 -> V_66 ) {
void * V_67 = F_15 ( V_68 , V_69 ) ;
if ( ( V_58 -> V_66 ( V_42 , V_67 , V_68 ) > 0 ) &&
F_16 ( V_67 ) ) {
F_17 (
V_39 , V_67 ) ;
V_65 = F_18 ( V_39 , V_67 ) ;
} else {
F_17 (
V_39 , NULL ) ;
}
F_12 ( V_67 ) ;
} else {
struct V_1 * V_2 = F_19 ( V_64 ) ;
struct V_3 V_4 = { 0 } ;
V_58 -> V_70 ( V_42 , & V_4 ) ;
F_1 ( V_2 , & V_4 ) ;
V_2 -> type = V_71 | V_72 ;
F_20 ( V_2 ) ;
F_21 ( V_39 , V_2 ) ;
V_65 = 1 ;
}
return V_65 ;
}
static int F_22 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_57 * V_58 = V_42 -> V_52 ;
struct V_3 V_4 = { 0 } ;
struct V_63 * V_64 = V_39 -> V_64 ;
struct V_1 * V_73 ;
int V_51 = V_74 ;
F_2 ( & V_4 , V_2 ) ;
V_2 -> V_75 = F_23 ( V_2 ) ;
if ( ! V_58 -> V_76 ( V_42 , & V_4 ) ) {
V_73 = F_24 ( V_64 , V_2 ) ;
V_73 -> clock = V_4 . V_5 ;
V_73 -> V_75 = 0 ;
if ( V_2 -> V_75 == F_23 ( V_73 ) )
V_51 = V_77 ;
F_25 ( V_64 , V_73 ) ;
}
F_5 ( L_5
L_6 ,
( V_51 == V_77 ) ? L_7 : L_8 ,
V_2 -> V_78 . V_79 , V_2 -> V_44 , V_2 -> V_75 , V_2 -> clock ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_16 ,
V_2 -> V_18 , V_2 -> V_20 , V_2 -> type , V_2 -> V_22 ) ;
return V_51 ;
}
struct V_80 * F_26 (
struct V_38 * V_39 )
{
int V_81 ;
struct V_40 * V_40 = F_4 ( V_39 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
struct V_83 * V_84 ;
if ( V_39 -> V_85 [ V_81 ] == 0 )
break;
V_84 = F_27 ( V_39 -> V_64 ,
V_39 -> V_85 [ V_81 ] ,
V_86 ) ;
if ( V_84 ) {
struct V_80 * V_87 = F_28 ( V_84 ) ;
struct V_88 * V_89 =
F_29 ( V_87 ) ;
F_5 ( L_9 , V_40 -> V_42 -> V_44 ,
V_89 -> V_44 ) ;
return V_87 ;
}
}
F_5 ( L_10 , V_40 -> V_42 -> V_44 ) ;
return NULL ;
}
void F_30 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
struct V_63 * V_64 = V_39 -> V_64 ;
struct V_40 * V_40 = F_4 ( V_39 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_57 * V_58 = V_42 -> V_52 ;
struct V_3 V_4 = { 0 } ;
F_2 ( & V_4 , V_2 ) ;
F_5 ( L_11 ,
V_40 -> V_42 -> V_44 ,
V_2 -> V_78 . V_79 , V_2 -> V_44 , V_2 -> V_75 , V_2 -> clock ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_16 ,
V_2 -> V_18 , V_2 -> V_20 , V_2 -> type , V_2 -> V_22 ) ;
if ( V_58 -> V_76 ( V_42 , & V_4 ) ) {
F_31 ( V_64 -> V_64 , L_12 ) ;
return;
}
V_58 -> V_90 ( V_42 , & V_4 ) ;
}
void F_32 ( struct V_38 * V_39 ,
int V_91 , int V_92 , int V_93 , int V_94 )
{
struct V_40 * V_40 = F_4 ( V_39 ) ;
F_8 ( L_13 , V_40 -> V_42 -> V_44 , V_91 , V_92 , V_93 , V_94 ) ;
}
struct V_38 * F_33 ( struct V_63 * V_64 ,
int V_95 , struct V_41 * V_42 )
{
struct V_38 * V_39 = NULL ;
struct V_40 * V_40 ;
F_5 ( L_4 , V_42 -> V_44 ) ;
F_34 ( V_42 ) ;
V_40 = F_15 ( sizeof( struct V_40 ) , V_69 ) ;
if ( ! V_40 ) {
F_31 ( V_64 -> V_64 , L_14 ) ;
goto V_96;
}
V_40 -> V_42 = V_42 ;
V_39 = & V_40 -> V_78 ;
F_35 ( V_64 , V_39 , & V_97 ,
V_95 ) ;
F_36 ( V_39 , & V_98 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_39 -> V_99 = V_100 |
V_101 ;
V_39 -> V_102 = 1 ;
V_39 -> V_103 = 0 ;
F_37 ( V_39 ) ;
return V_39 ;
V_96:
if ( V_39 ) {
F_9 ( V_39 ) ;
}
return NULL ;
}
