int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return - V_3 ;
if ( ! F_3 ( V_2 -> V_2 -> V_4 -> V_5 ) )
return - V_6 ;
F_4 ( & V_7 ) ;
if ( V_8 ) {
F_5 ( L_1 , V_8 -> V_9 ) ;
F_6 ( V_2 -> V_2 -> V_4 -> V_5 ) ;
F_7 ( & V_7 ) ;
return - V_10 ;
}
F_8 ( L_2 , V_2 -> V_9 ) ;
V_8 = V_2 ;
F_7 ( & V_7 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return - V_3 ;
if ( V_2 != V_8 )
return - V_3 ;
F_4 ( & V_7 ) ;
if ( ! V_8 ) {
F_7 ( & V_7 ) ;
return - V_11 ;
}
F_6 ( V_8 -> V_2 -> V_4 -> V_5 ) ;
F_8 ( L_3 , V_8 -> V_9 ) ;
V_8 = NULL ;
F_7 ( & V_7 ) ;
return 0 ;
}
void F_10 ( struct V_12 * V_13 ,
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
V_21 -> V_22 = ( V_23 ) V_19 -> V_24 -> V_25 ;
V_21 -> V_26 = V_19 -> V_24 -> V_27 ;
V_21 -> V_28 = 0 ;
V_21 -> V_29 = V_19 -> V_24 -> V_30 ;
V_21 -> V_31 = F_15 ( V_19 ) ;
V_21 -> V_32 = V_19 -> V_24 -> V_33 ;
V_21 -> V_34 = F_16 ( V_19 -> V_35 . V_36 ) ;
F_8 ( L_4 , V_21 -> V_32 ) ;
F_8 ( L_5 , V_21 -> V_29 , V_21 -> V_26 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_12 * V_13 =
V_19 -> V_24 -> V_37 ;
struct V_20 V_21 = { 0 } ;
struct V_38 V_39 = { 0 } ;
int V_40 ;
F_14 ( V_19 , & V_21 ) ;
V_19 -> V_24 -> V_41 = V_19 -> V_35 . V_36 ;
V_39 . V_42 = V_21 ;
V_39 . V_43 = V_21 . V_43 ;
if ( V_19 -> V_13 == V_44 ) {
V_39 . V_45 = V_46 ;
V_39 . V_47 = V_19 -> V_48 -> V_49 + 1 ;
F_8 ( L_6 ,
V_19 -> V_48 -> V_49 ) ;
} else {
V_39 . V_45 = V_50 ;
V_39 . V_47 = V_51 ;
F_8 ( L_7 ,
V_19 -> V_48 -> V_49 ) ;
}
V_40 = V_13 -> V_45 -> V_52 ( & V_39 ) ;
F_8 ( L_8 , V_40 ) ;
if ( V_40 < 0 )
return V_40 ;
V_13 -> V_53 . V_54 = V_40 ;
F_8 ( L_9 , V_13 -> V_53 . V_54 ) ;
return V_40 ;
}
static void F_18 ( void * V_55 )
{
struct V_18 * V_19 = V_55 ;
struct V_12 * V_13 ;
int V_56 ;
if ( ! V_19 || ! V_19 -> V_24 )
return;
V_13 = V_19 -> V_24 -> V_37 ;
if ( ! V_13 )
return;
V_56 = F_13 ( V_13 ) ;
if ( V_56 != V_57 )
return;
F_19 ( V_19 ) ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_12 * V_13 =
V_19 -> V_24 -> V_37 ;
int V_40 ;
F_8 ( L_10 ) ;
F_10 ( V_13 , V_58 ) ;
V_13 -> V_53 . V_59 = F_18 ;
V_13 -> V_53 . V_55 = V_19 ;
V_13 -> V_53 . V_60 = 0 ;
V_13 -> V_53 . V_29 = V_19 -> V_24 -> V_30 ;
V_40 = V_13 -> V_45 -> V_61 (
V_62 , & V_13 -> V_53 ) ;
if ( V_40 )
F_5 ( L_11 , V_40 ) ;
return V_40 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_63 * V_24 = V_19 -> V_24 ;
struct V_12 * V_13 ;
int V_40 ;
F_8 ( L_12 ) ;
F_22 ( V_19 , & V_64 ) ;
V_40 = F_23 ( V_24 ,
V_65 ) ;
if ( V_40 < 0 )
return V_40 ;
V_13 = F_24 ( sizeof( * V_13 ) , V_66 ) ;
if ( ! V_13 )
return - V_67 ;
F_25 ( & V_13 -> V_16 ) ;
F_4 ( & V_7 ) ;
if ( ! V_8 ) {
F_5 ( L_13 ) ;
F_7 ( & V_7 ) ;
F_26 ( V_13 ) ;
return - V_6 ;
}
if ( ! F_3 ( V_8 -> V_2 -> V_4 -> V_5 ) ) {
F_7 ( & V_7 ) ;
F_26 ( V_13 ) ;
return - V_6 ;
}
V_13 -> V_45 = V_8 -> V_45 ;
F_7 ( & V_7 ) ;
V_13 -> V_53 . V_54 = 0 ;
F_10 ( V_13 , V_58 ) ;
V_13 -> V_53 . V_55 = V_19 ;
V_24 -> V_37 = V_13 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_40 = 0 , V_54 ;
F_8 ( L_14 ) ;
V_13 = V_19 -> V_24 -> V_37 ;
V_54 = V_13 -> V_53 . V_54 ;
if ( V_54 )
V_40 = V_13 -> V_45 -> V_68 ( V_54 ) ;
F_6 ( V_8 -> V_2 -> V_4 -> V_5 ) ;
F_26 ( V_13 ) ;
return V_40 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_40 = 0 , V_54 ;
F_8 ( L_15 ) ;
V_13 = V_19 -> V_24 -> V_37 ;
V_54 = V_13 -> V_53 . V_54 ;
if ( V_13 -> V_53 . V_54 ) {
V_40 = V_13 -> V_45 -> V_61 (
V_69 , & V_54 ) ;
return V_40 ;
}
V_40 = F_17 ( V_19 ) ;
if ( V_40 < 0 )
return V_40 ;
snprintf ( V_19 -> V_48 -> V_70 , sizeof( V_19 -> V_48 -> V_70 ) ,
L_16 , V_13 -> V_53 . V_54 ) ;
V_40 = F_20 ( V_19 ) ;
if ( V_40 )
return V_40 ;
V_19 -> V_24 -> V_71 . V_72 = V_73 ;
return V_40 ;
}
static int F_29 ( struct V_18 * V_19 ,
int V_74 )
{
int V_40 = 0 , V_54 ;
struct V_12 * V_13 ;
int V_75 , V_56 ;
F_8 ( L_17 ) ;
V_13 = V_19 -> V_24 -> V_37 ;
V_54 = V_13 -> V_53 . V_54 ;
switch ( V_74 ) {
case V_76 :
F_8 ( L_18 ) ;
V_75 = V_77 ;
V_56 = V_57 ;
V_13 -> V_53 . V_55 = V_19 ;
break;
case V_78 :
F_8 ( L_19 ) ;
V_75 = V_69 ;
V_56 = V_79 ;
break;
case V_80 :
F_8 ( L_20 ) ;
V_75 = V_81 ;
V_56 = V_82 ;
break;
case V_83 :
F_8 ( L_21 ) ;
V_75 = V_84 ;
V_56 = V_57 ;
break;
default:
return - V_3 ;
}
V_40 = V_13 -> V_45 -> V_61 ( V_75 , & V_54 ) ;
if ( ! V_40 )
F_10 ( V_13 , V_56 ) ;
return V_40 ;
}
static T_1 F_30
( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_40 , V_56 ;
struct V_85 * V_86 ;
V_13 = V_19 -> V_24 -> V_37 ;
V_56 = F_13 ( V_13 ) ;
if ( V_56 == V_58 )
return 0 ;
V_86 = & V_13 -> V_53 ;
V_40 = V_13 -> V_45 -> V_61 (
V_87 , V_86 ) ;
if ( V_40 ) {
F_5 ( L_22 , V_40 ) ;
return V_40 ;
}
return V_13 -> V_53 . V_60 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_88 * V_89 )
{
F_32 ( V_19 , F_33 ( V_89 ) ) ;
memset ( V_19 -> V_24 -> V_41 , 0 , F_33 ( V_89 ) ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 )
{
return F_35 ( V_19 ) ;
}
static void F_36 ( struct V_90 * V_48 )
{
F_8 ( L_23 ) ;
F_37 ( V_48 ) ;
}
static int F_38 ( struct V_91 * V_92 )
{
struct V_90 * V_48 = V_92 -> V_48 ;
int V_93 = 0 ;
F_8 ( L_24 ) ;
if ( V_48 -> V_94 [ V_44 ] . V_19 ||
V_48 -> V_94 [ V_95 ] . V_19 ) {
V_93 = F_39 ( V_48 ,
V_96 ,
F_40 ( V_66 ) ,
V_97 , V_98 ) ;
if ( V_93 ) {
F_5 ( L_25 ) ;
return V_93 ;
}
}
return V_93 ;
}
static int F_41 ( struct V_99 * V_100 )
{
int V_101 ;
F_8 ( L_26 ) ;
V_8 = NULL ;
V_101 = F_42 ( & V_100 -> V_2 , & V_102 ) ;
if ( V_101 ) {
F_5 ( L_27 ) ;
return V_101 ;
}
V_101 = F_43 ( & V_100 -> V_2 , & V_103 ,
V_104 , F_44 ( V_104 ) ) ;
if ( V_101 ) {
F_5 ( L_28 ) ;
F_45 ( & V_100 -> V_2 ) ;
}
return V_101 ;
}
static int F_46 ( struct V_99 * V_100 )
{
F_47 ( & V_100 -> V_2 ) ;
F_45 ( & V_100 -> V_2 ) ;
F_8 ( L_29 ) ;
return 0 ;
}
