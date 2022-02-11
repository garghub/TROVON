static inline void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 = V_3 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_3 = V_2 -> V_6 ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
return V_3 ;
}
static void F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
V_10 -> V_11 . V_12 . V_13 = V_14 ;
V_10 -> V_11 . V_12 . V_15 = ( V_16 ) V_8 -> V_17 -> V_18 ;
V_10 -> V_11 . V_12 . V_19 = V_8 -> V_17 -> V_20 ;
V_10 -> V_11 . V_12 . V_21 = 0 ;
V_10 -> V_11 . V_12 . V_22 = V_8 -> V_17 -> V_23 ;
V_10 -> V_11 . V_12 . V_24 =
F_6 ( V_8 ) ;
V_10 -> V_11 . V_12 . V_25 = V_8 -> V_17 -> V_26 ;
V_10 -> V_11 . V_12 . V_27 =
F_7 ( V_8 -> V_28 . V_29 ) ;
F_8 ( L_1 , V_10 -> V_11 . V_12 . V_25 ) ;
F_8 ( L_2 ,
V_10 -> V_11 . V_12 . V_22 , V_10 -> V_11 . V_12 . V_19 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
V_8 -> V_17 -> V_30 ;
struct V_9 V_10 = { { { 0 ,} ,} ,} ;
struct V_31 V_32 = { 0 } ;
int V_33 ;
F_5 ( V_8 , & V_10 ) ;
V_8 -> V_17 -> V_34 = V_8 -> V_28 . V_29 ;
V_32 . V_35 = V_10 ;
V_32 . V_13 = V_10 . V_11 . V_12 . V_13 ;
if ( V_8 -> V_2 == V_36 ) {
V_32 . V_37 = V_38 ;
V_32 . V_39 = V_8 -> V_40 -> V_41 + 1 ;
F_8 ( L_3 ,
V_8 -> V_40 -> V_41 ) ;
} else {
V_32 . V_37 = V_42 ;
V_32 . V_39 = V_43 ;
F_8 ( L_4 ,
V_8 -> V_40 -> V_41 ) ;
}
V_33 = V_2 -> V_44 -> V_45 -> V_46 ( & V_32 ) ;
F_8 ( L_5 , V_33 ) ;
if ( V_33 < 0 )
return V_33 ;
V_2 -> V_47 . V_48 = V_33 ;
F_8 ( L_6 , V_2 -> V_47 . V_48 ) ;
return V_33 ;
}
static void F_10 ( void * V_49 )
{
struct V_7 * V_8 = V_49 ;
struct V_1 * V_2 ;
int V_50 ;
if ( ! V_8 || ! V_8 -> V_17 )
return;
V_2 = V_8 -> V_17 -> V_30 ;
if ( ! V_2 )
return;
V_50 = F_4 ( V_2 ) ;
if ( V_50 != V_51 )
return;
F_11 ( V_8 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
V_8 -> V_17 -> V_30 ;
int V_33 ;
F_8 ( L_7 ) ;
F_1 ( V_2 , V_52 ) ;
V_2 -> V_47 . V_53 = F_10 ;
V_2 -> V_47 . V_49 = V_8 ;
V_2 -> V_47 . V_54 = 0 ;
V_2 -> V_47 . V_22 = V_8 -> V_17 -> V_23 ;
V_33 = V_2 -> V_44 -> V_45 -> V_55 (
V_56 , & V_2 -> V_47 ) ;
if ( V_33 )
F_13 ( L_8 , V_33 ) ;
return V_33 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_57 * V_17 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
F_8 ( L_9 ) ;
V_17 = V_8 -> V_17 ;
V_17 -> V_58 = V_59 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
F_16 ( & V_2 -> V_5 ) ;
V_2 -> V_47 . V_48 = 0 ;
F_1 ( V_2 , V_52 ) ;
V_2 -> V_47 . V_49 = V_8 ;
V_2 -> V_44 = F_15 ( sizeof( * V_2 -> V_44 ) ,
V_60 ) ;
if ( ! V_2 -> V_44 ) {
F_13 ( L_10 ) ;
F_17 ( V_2 ) ;
return - V_61 ;
}
V_2 -> V_44 -> V_62 = V_63 ;
V_2 -> V_44 -> V_64 = V_65 ;
V_33 = F_18 ( V_2 -> V_44 ) ;
if ( V_33 ) {
F_13 ( L_11 ) ;
F_17 ( V_2 -> V_44 ) ;
F_17 ( V_2 ) ;
return V_33 ;
}
V_17 -> V_30 = V_2 ;
return F_19 ( V_17 ,
V_66 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_33 = 0 , V_48 ;
F_8 ( L_12 ) ;
V_2 = V_8 -> V_17 -> V_30 ;
V_48 = V_2 -> V_47 . V_48 ;
if ( V_48 )
V_33 = V_2 -> V_44 -> V_45 -> V_67 ( V_48 ) ;
F_21 ( V_2 -> V_44 ) ;
F_17 ( V_2 -> V_44 ) ;
F_17 ( V_2 ) ;
return V_33 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_33 = 0 , V_48 ;
F_8 ( L_13 ) ;
V_2 = V_8 -> V_17 -> V_30 ;
V_48 = V_2 -> V_47 . V_48 ;
if ( V_2 -> V_47 . V_48 ) {
V_33 = V_2 -> V_44 -> V_45 -> V_55 (
V_68 , & V_48 ) ;
return V_33 ;
}
V_33 = F_9 ( V_8 ) ;
if ( V_33 < 0 )
return V_33 ;
snprintf ( V_8 -> V_40 -> V_69 , sizeof( V_8 -> V_40 -> V_69 ) ,
L_14 , V_2 -> V_47 . V_48 ) ;
V_33 = F_12 ( V_8 ) ;
if ( V_33 )
return V_33 ;
V_8 -> V_17 -> V_58 . V_70 = V_71 ;
return V_33 ;
}
static int F_23 ( struct V_7 * V_8 ,
int V_72 )
{
int V_33 = 0 , V_48 ;
struct V_1 * V_2 ;
int V_73 , V_50 ;
F_8 ( L_15 ) ;
V_2 = V_8 -> V_17 -> V_30 ;
V_48 = V_2 -> V_47 . V_48 ;
switch ( V_72 ) {
case V_74 :
F_8 ( L_16 ) ;
V_73 = V_75 ;
V_50 = V_51 ;
V_2 -> V_47 . V_49 = V_8 ;
break;
case V_76 :
F_8 ( L_17 ) ;
V_73 = V_68 ;
V_50 = V_77 ;
break;
case V_78 :
F_8 ( L_18 ) ;
V_73 = V_79 ;
V_50 = V_80 ;
break;
case V_81 :
F_8 ( L_19 ) ;
V_73 = V_82 ;
V_50 = V_51 ;
break;
default:
return - V_83 ;
}
V_33 = V_2 -> V_44 -> V_45 -> V_55 ( V_73 ,
& V_48 ) ;
if ( ! V_33 )
F_1 ( V_2 , V_50 ) ;
return V_33 ;
}
static T_1 F_24
( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_33 , V_50 ;
struct V_84 * V_85 ;
V_2 = V_8 -> V_17 -> V_30 ;
V_50 = F_4 ( V_2 ) ;
if ( V_50 == V_52 )
return 0 ;
V_85 = & V_2 -> V_47 ;
V_33 = V_2 -> V_44 -> V_45 -> V_55 (
V_86 , V_85 ) ;
if ( V_33 ) {
F_13 ( L_20 , V_33 ) ;
return V_33 ;
}
return V_2 -> V_47 . V_54 ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_87 * V_88 )
{
F_26 ( V_8 , F_27 ( V_88 ) ) ;
memset ( V_8 -> V_17 -> V_34 , 0 , F_27 ( V_88 ) ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
return F_29 ( V_8 ) ;
}
static void F_30 ( struct V_89 * V_40 )
{
F_8 ( L_21 ) ;
F_31 ( V_40 ) ;
}
int F_32 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_89 * V_40 = V_91 -> V_40 ;
int V_95 = 0 ;
F_8 ( L_22 ) ;
if ( V_93 -> V_96 -> V_97 . V_98 ||
V_93 -> V_96 -> V_99 . V_98 ) {
V_95 = F_33 ( V_40 ,
V_100 ,
F_34 ( V_60 ) ,
V_101 , V_102 ) ;
if ( V_95 ) {
F_13 ( L_23 ) ;
return V_95 ;
}
}
return V_95 ;
}
static int F_35 ( struct V_103 * V_104 )
{
int V_105 ;
F_8 ( L_24 ) ;
V_105 = F_36 ( & V_104 -> V_106 , & V_107 ) ;
if ( V_105 ) {
F_13 ( L_25 ) ;
return V_105 ;
}
V_105 = F_37 ( & V_104 -> V_106 ,
V_108 , F_38 ( V_108 ) ) ;
if ( V_105 ) {
F_13 ( L_26 ) ;
F_39 ( & V_104 -> V_106 ) ;
}
return V_105 ;
}
static int F_40 ( struct V_103 * V_104 )
{
F_41 ( & V_104 -> V_106 , F_38 ( V_108 ) ) ;
F_39 ( & V_104 -> V_106 ) ;
F_8 ( L_27 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
F_8 ( L_28 ) ;
return F_43 ( & V_109 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_109 ) ;
F_8 ( L_29 ) ;
}
