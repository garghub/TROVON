int F_1 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
if ( ! F_3 ( V_2 -> V_2 -> V_3 -> V_4 ) )
return - V_5 ;
F_4 ( & V_6 ) ;
if ( V_7 ) {
F_5 ( L_1 , V_7 -> V_8 ) ;
F_6 ( V_2 -> V_2 -> V_3 -> V_4 ) ;
F_7 ( & V_6 ) ;
return - V_9 ;
}
F_8 ( L_2 , V_2 -> V_8 ) ;
V_7 = V_2 ;
F_7 ( & V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
if ( V_2 != V_7 )
return - V_10 ;
F_4 ( & V_6 ) ;
if ( ! V_7 ) {
F_7 ( & V_6 ) ;
return - V_11 ;
}
F_6 ( V_7 -> V_2 -> V_3 -> V_4 ) ;
F_8 ( L_3 , V_7 -> V_8 ) ;
V_7 = NULL ;
F_7 ( & V_6 ) ;
return 0 ;
}
static inline void F_10 ( struct V_12 * V_13 ,
int V_14 )
{
unsigned long V_15 ;
F_11 ( & V_13 -> V_16 , V_15 ) ;
V_13 -> V_17 = V_14 ;
F_12 ( & V_13 -> V_16 , V_15 ) ;
}
static inline int F_13 ( struct V_12 * V_13 )
{
int V_14 ;
unsigned long V_15 ;
F_11 ( & V_13 -> V_16 , V_15 ) ;
V_14 = V_13 -> V_17 ;
F_12 ( & V_13 -> V_16 , V_15 ) ;
return V_14 ;
}
static void F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
V_21 -> V_22 = V_23 ;
V_21 -> V_24 = ( V_25 ) V_19 -> V_26 -> V_27 ;
V_21 -> V_28 = V_19 -> V_26 -> V_29 ;
V_21 -> V_30 = 0 ;
V_21 -> V_31 = V_19 -> V_26 -> V_32 ;
V_21 -> V_33 = F_15 ( V_19 ) ;
V_21 -> V_34 = V_19 -> V_26 -> V_35 ;
V_21 -> V_36 = F_16 ( V_19 -> V_37 . V_38 ) ;
F_8 ( L_4 , V_21 -> V_34 ) ;
F_8 ( L_5 , V_21 -> V_31 , V_21 -> V_28 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_12 * V_13 =
V_19 -> V_26 -> V_39 ;
struct V_20 V_21 = { 0 } ;
struct V_40 V_41 = { 0 } ;
int V_42 ;
F_14 ( V_19 , & V_21 ) ;
V_19 -> V_26 -> V_43 = V_19 -> V_37 . V_38 ;
V_41 . V_44 = V_21 ;
V_41 . V_22 = V_21 . V_22 ;
if ( V_19 -> V_13 == V_45 ) {
V_41 . V_46 = V_47 ;
V_41 . V_48 = V_19 -> V_49 -> V_50 + 1 ;
F_8 ( L_6 ,
V_19 -> V_49 -> V_50 ) ;
} else {
V_41 . V_46 = V_51 ;
V_41 . V_48 = V_52 ;
F_8 ( L_7 ,
V_19 -> V_49 -> V_50 ) ;
}
V_42 = V_13 -> V_46 -> V_53 ( & V_41 ) ;
F_8 ( L_8 , V_42 ) ;
if ( V_42 < 0 )
return V_42 ;
V_13 -> V_54 . V_55 = V_42 ;
F_8 ( L_9 , V_13 -> V_54 . V_55 ) ;
return V_42 ;
}
static void F_18 ( void * V_56 )
{
struct V_18 * V_19 = V_56 ;
struct V_12 * V_13 ;
int V_57 ;
if ( ! V_19 || ! V_19 -> V_26 )
return;
V_13 = V_19 -> V_26 -> V_39 ;
if ( ! V_13 )
return;
V_57 = F_13 ( V_13 ) ;
if ( V_57 != V_58 )
return;
F_19 ( V_19 ) ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_12 * V_13 =
V_19 -> V_26 -> V_39 ;
int V_42 ;
F_8 ( L_10 ) ;
F_10 ( V_13 , V_59 ) ;
V_13 -> V_54 . V_60 = F_18 ;
V_13 -> V_54 . V_56 = V_19 ;
V_13 -> V_54 . V_61 = 0 ;
V_13 -> V_54 . V_31 = V_19 -> V_26 -> V_32 ;
V_42 = V_13 -> V_46 -> V_62 (
V_63 , & V_13 -> V_54 ) ;
if ( V_42 )
F_5 ( L_11 , V_42 ) ;
return V_42 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_64 * V_26 = V_19 -> V_26 ;
struct V_12 * V_13 ;
int V_42 ;
F_8 ( L_12 ) ;
F_22 ( V_19 , & V_65 ) ;
V_42 = F_23 ( V_26 ,
V_66 ) ;
if ( V_42 < 0 )
return V_42 ;
V_13 = F_24 ( sizeof( * V_13 ) , V_67 ) ;
if ( ! V_13 )
return - V_68 ;
F_25 ( & V_13 -> V_16 ) ;
F_4 ( & V_6 ) ;
if ( ! V_7 ) {
F_5 ( L_13 ) ;
F_7 ( & V_6 ) ;
F_26 ( V_13 ) ;
return - V_5 ;
}
if ( ! F_3 ( V_7 -> V_2 -> V_3 -> V_4 ) ) {
F_7 ( & V_6 ) ;
F_26 ( V_13 ) ;
return - V_5 ;
}
V_13 -> V_46 = V_7 -> V_46 ;
F_7 ( & V_6 ) ;
V_13 -> V_54 . V_55 = 0 ;
F_10 ( V_13 , V_59 ) ;
V_13 -> V_54 . V_56 = V_19 ;
V_26 -> V_39 = V_13 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_42 = 0 , V_55 ;
F_8 ( L_14 ) ;
V_13 = V_19 -> V_26 -> V_39 ;
V_55 = V_13 -> V_54 . V_55 ;
if ( V_55 )
V_42 = V_13 -> V_46 -> V_69 ( V_55 ) ;
F_6 ( V_7 -> V_2 -> V_3 -> V_4 ) ;
F_26 ( V_13 ) ;
return V_42 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_42 = 0 , V_55 ;
F_8 ( L_15 ) ;
V_13 = V_19 -> V_26 -> V_39 ;
V_55 = V_13 -> V_54 . V_55 ;
if ( V_13 -> V_54 . V_55 ) {
V_42 = V_13 -> V_46 -> V_62 (
V_70 , & V_55 ) ;
return V_42 ;
}
V_42 = F_17 ( V_19 ) ;
if ( V_42 < 0 )
return V_42 ;
snprintf ( V_19 -> V_49 -> V_71 , sizeof( V_19 -> V_49 -> V_71 ) ,
L_16 , V_13 -> V_54 . V_55 ) ;
V_42 = F_20 ( V_19 ) ;
if ( V_42 )
return V_42 ;
V_19 -> V_26 -> V_72 . V_73 = V_74 ;
return V_42 ;
}
static int F_29 ( struct V_18 * V_19 ,
int V_75 )
{
int V_42 = 0 , V_55 ;
struct V_12 * V_13 ;
int V_76 , V_57 ;
F_8 ( L_17 ) ;
V_13 = V_19 -> V_26 -> V_39 ;
V_55 = V_13 -> V_54 . V_55 ;
switch ( V_75 ) {
case V_77 :
F_8 ( L_18 ) ;
V_76 = V_78 ;
V_57 = V_58 ;
V_13 -> V_54 . V_56 = V_19 ;
break;
case V_79 :
F_8 ( L_19 ) ;
V_76 = V_70 ;
V_57 = V_80 ;
break;
case V_81 :
F_8 ( L_20 ) ;
V_76 = V_82 ;
V_57 = V_83 ;
break;
case V_84 :
F_8 ( L_21 ) ;
V_76 = V_85 ;
V_57 = V_58 ;
break;
default:
return - V_10 ;
}
V_42 = V_13 -> V_46 -> V_62 ( V_76 , & V_55 ) ;
if ( ! V_42 )
F_10 ( V_13 , V_57 ) ;
return V_42 ;
}
static T_1 F_30
( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_42 , V_57 ;
struct V_86 * V_87 ;
V_13 = V_19 -> V_26 -> V_39 ;
V_57 = F_13 ( V_13 ) ;
if ( V_57 == V_59 )
return 0 ;
V_87 = & V_13 -> V_54 ;
V_42 = V_13 -> V_46 -> V_62 (
V_88 , V_87 ) ;
if ( V_42 ) {
F_5 ( L_22 , V_42 ) ;
return V_42 ;
}
return V_13 -> V_54 . V_61 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
F_32 ( V_19 , F_33 ( V_90 ) ) ;
memset ( V_19 -> V_26 -> V_43 , 0 , F_33 ( V_90 ) ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 )
{
return F_35 ( V_19 ) ;
}
static void F_36 ( struct V_91 * V_49 )
{
F_8 ( L_23 ) ;
F_37 ( V_49 ) ;
}
static int F_38 ( struct V_92 * V_93 )
{
struct V_91 * V_49 = V_93 -> V_49 ;
int V_94 = 0 ;
F_8 ( L_24 ) ;
if ( V_49 -> V_95 [ V_45 ] . V_19 ||
V_49 -> V_95 [ V_96 ] . V_19 ) {
V_94 = F_39 ( V_49 ,
V_97 ,
F_40 ( V_67 ) ,
V_98 , V_99 ) ;
if ( V_94 ) {
F_5 ( L_25 ) ;
return V_94 ;
}
}
return V_94 ;
}
static int F_41 ( struct V_100 * V_101 )
{
int V_102 ;
F_8 ( L_26 ) ;
V_7 = NULL ;
V_102 = F_42 ( & V_101 -> V_2 , & V_103 ) ;
if ( V_102 ) {
F_5 ( L_27 ) ;
return V_102 ;
}
V_102 = F_43 ( & V_101 -> V_2 ,
V_104 , F_44 ( V_104 ) ) ;
if ( V_102 ) {
F_5 ( L_28 ) ;
F_45 ( & V_101 -> V_2 ) ;
}
return V_102 ;
}
static int F_46 ( struct V_100 * V_101 )
{
F_47 ( & V_101 -> V_2 , F_44 ( V_104 ) ) ;
F_45 ( & V_101 -> V_2 ) ;
F_8 ( L_29 ) ;
return 0 ;
}
