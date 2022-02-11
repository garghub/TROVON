static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 , V_3 , V_4 , div ;
V_4 = 0 ;
if ( ! V_1 )
return V_4 ;
V_3 = F_2 ( V_5 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 % V_5 [ V_2 ] . V_1 )
continue;
div = V_1 / V_5 [ V_2 ] . V_1 ;
if ( ( div & ( div - 1 ) ) == 0 ) {
V_4 = V_5 [ V_2 ] . V_4 ;
break;
}
}
return V_4 ;
}
static inline struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 ) ;
}
static void F_5 ( struct V_6 * V_9 , int V_10 )
{
if ( V_10 ) {
F_6 ( V_9 -> V_11 , V_12 ,
V_13 , V_14 ) ;
F_6 ( V_9 -> V_11 , V_15 ,
V_16 , V_17 ) ;
} else {
F_6 ( V_9 -> V_11 , V_12 ,
V_13 , V_18 ) ;
F_6 ( V_9 -> V_11 , V_15 ,
V_16 | V_19 ,
V_20 | V_21 ) ;
}
}
static int F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
unsigned int V_26 = 0 ;
unsigned int V_27 , V_28 , V_29 ;
int V_30 ;
V_29 = F_8 ( V_25 ) ;
V_27 = F_1 ( V_29 ) ;
if ( ! V_27 )
return - V_31 ;
V_30 = F_9 ( V_9 -> V_4 , V_27 ) ;
if ( V_30 )
return - V_31 ;
V_28 = F_10 ( V_27 , V_29 ) ;
switch ( V_28 ) {
case 320 :
V_26 = V_32 ;
break;
case 640 :
V_26 = V_33 ;
break;
case 1280 :
V_26 = V_34 ;
break;
case 2560 :
V_26 = V_35 ;
break;
case 5120 :
V_26 = V_36 ;
break;
default:
F_11 ( V_9 -> V_37 , L_1 , V_28 ) ;
return - V_31 ;
}
F_6 ( V_9 -> V_11 , V_38 , V_39 , V_26 ) ;
F_6 ( V_9 -> V_11 , V_40 ,
V_41 , V_42 ) ;
F_6 ( V_9 -> V_11 , V_40 ,
V_43 | V_44 , V_43 | V_44 ) ;
F_6 ( V_9 -> V_11 , V_38 , V_45 , V_45 ) ;
V_26 = 0 ;
switch ( F_12 ( V_25 ) ) {
case V_46 :
V_26 |= F_13 ( 8 ) ;
break;
case V_47 :
V_26 |= F_13 ( 16 ) ;
break;
case V_48 :
V_26 |= F_13 ( 20 ) ;
break;
case V_49 :
V_26 |= F_13 ( 24 ) ;
break;
case V_50 :
V_26 |= F_13 ( 32 ) ;
break;
default:
return - V_31 ;
}
switch ( F_14 ( V_25 ) ) {
case 8 :
V_26 |= V_51 ;
case 6 :
V_26 |= V_52 ;
case 4 :
V_26 |= V_53 ;
case 2 :
V_26 |= V_54 ;
break;
default:
F_11 ( V_9 -> V_37 , L_2 ,
F_14 ( V_25 ) ) ;
return - V_31 ;
}
if ( V_23 -> V_55 == V_56 ) {
F_6 ( V_9 -> V_11 , V_57 ,
V_58 | V_59 ,
V_26 ) ;
F_6 ( V_9 -> V_11 , V_12 , V_60 ,
F_15 ( 16 ) ) ;
F_6 ( V_9 -> V_11 , V_15 ,
V_16 | V_19 ,
V_20 | V_21 ) ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_61 ,
unsigned int V_62 )
{
struct V_6 * V_9 = F_3 ( V_61 ) ;
unsigned int V_63 = 0 , V_26 = 0 ;
V_63 = V_64 ;
switch ( V_62 & V_65 ) {
case V_66 :
V_26 = V_67 ;
break;
case V_68 :
V_26 = V_69 ;
break;
default:
return - V_31 ;
}
F_6 ( V_9 -> V_11 , V_38 , V_63 , V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , int V_70 ,
struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
int V_30 = 0 ;
switch ( V_70 ) {
case V_71 :
case V_72 :
case V_73 :
if ( V_23 -> V_55 == V_56 )
F_5 ( V_9 , 1 ) ;
break;
case V_74 :
case V_75 :
case V_76 :
if ( V_23 -> V_55 == V_56 )
F_5 ( V_9 , 0 ) ;
break;
default:
V_30 = - V_31 ;
break;
}
return V_30 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
V_8 -> V_77 = & V_9 -> V_77 ;
return 0 ;
}
static int F_19 ( struct V_78 * V_37 )
{
struct V_6 * V_9 = F_20 ( V_37 ) ;
F_21 ( V_9 -> V_4 ) ;
F_21 ( V_9 -> V_79 ) ;
return 0 ;
}
static int F_22 ( struct V_78 * V_37 )
{
struct V_6 * V_9 = F_20 ( V_37 ) ;
int V_30 ;
V_30 = F_23 ( V_9 -> V_4 ) ;
if ( V_30 ) {
F_11 ( V_9 -> V_37 , L_3 , V_30 ) ;
return V_30 ;
}
V_30 = F_23 ( V_9 -> V_79 ) ;
if ( V_30 ) {
F_11 ( V_9 -> V_37 , L_4 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static bool F_24 ( struct V_78 * V_37 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_15 :
case V_57 :
case V_81 :
case V_38 :
case V_40 :
case V_82 :
case V_12 :
case V_83 :
case V_84 :
case V_85 :
return true ;
default:
return false ;
}
}
static bool F_25 ( struct V_78 * V_37 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_15 :
case V_57 :
case V_81 :
case V_38 :
case V_40 :
case V_82 :
case V_12 :
case V_83 :
case V_84 :
case V_86 :
case V_85 :
case V_87 :
return true ;
default:
return false ;
}
}
static bool F_26 ( struct V_78 * V_37 , unsigned int V_80 )
{
switch ( V_80 ) {
case V_15 :
case V_84 :
case V_86 :
return true ;
default:
return false ;
}
}
static int F_27 ( struct V_88 * V_89 )
{
struct V_6 * V_9 ;
struct V_90 * V_91 ;
void T_1 * V_92 ;
int V_30 ;
V_9 = F_28 ( & V_89 -> V_37 , sizeof( * V_9 ) , V_93 ) ;
if ( ! V_9 )
return - V_94 ;
V_91 = F_29 ( V_89 , V_95 , 0 ) ;
V_92 = F_30 ( & V_89 -> V_37 , V_91 ) ;
if ( F_31 ( V_92 ) )
return F_32 ( V_92 ) ;
V_9 -> V_11 = F_33 ( & V_89 -> V_37 , V_92 ,
& V_96 ) ;
if ( F_31 ( V_9 -> V_11 ) )
return F_32 ( V_9 -> V_11 ) ;
V_9 -> V_77 . V_97 = V_91 -> V_98 + V_99 ;
V_9 -> V_77 . V_100 = V_101 ;
V_9 -> V_77 . V_102 = V_103 ;
V_9 -> V_37 = & V_89 -> V_37 ;
F_34 ( & V_89 -> V_37 , V_9 ) ;
V_9 -> V_4 = F_35 ( & V_89 -> V_37 , L_5 ) ;
if ( F_31 ( V_9 -> V_4 ) )
return F_32 ( V_9 -> V_4 ) ;
V_9 -> V_79 = F_35 ( & V_89 -> V_37 , L_6 ) ;
if ( F_31 ( V_9 -> V_79 ) )
return F_32 ( V_9 -> V_79 ) ;
V_30 = F_23 ( V_9 -> V_79 ) ;
if ( V_30 )
return V_30 ;
F_36 ( & V_89 -> V_37 ) ;
if ( ! F_37 ( & V_89 -> V_37 ) ) {
V_30 = F_22 ( & V_89 -> V_37 ) ;
if ( V_30 )
goto V_104;
}
V_30 = F_38 ( & V_89 -> V_37 ,
& V_105 ,
& V_106 , 1 ) ;
if ( V_30 ) {
F_11 ( & V_89 -> V_37 , L_7 , V_30 ) ;
goto V_107;
}
V_30 = F_39 ( & V_89 -> V_37 , NULL , 0 ) ;
if ( V_30 ) {
F_11 ( & V_89 -> V_37 , L_8 , V_30 ) ;
goto V_107;
}
return 0 ;
V_107:
if ( ! F_40 ( & V_89 -> V_37 ) )
F_19 ( & V_89 -> V_37 ) ;
V_104:
F_41 ( & V_89 -> V_37 ) ;
F_21 ( V_9 -> V_79 ) ;
return V_30 ;
}
static int F_42 ( struct V_88 * V_89 )
{
struct V_6 * V_9 = F_20 ( & V_89 -> V_37 ) ;
F_41 ( & V_89 -> V_37 ) ;
if ( ! F_40 ( & V_89 -> V_37 ) )
F_19 ( & V_89 -> V_37 ) ;
F_21 ( V_9 -> V_4 ) ;
F_21 ( V_9 -> V_79 ) ;
return 0 ;
}
static int F_43 ( struct V_78 * V_37 )
{
struct V_6 * V_9 = F_20 ( V_37 ) ;
F_44 ( V_9 -> V_11 ) ;
return 0 ;
}
static int F_45 ( struct V_78 * V_37 )
{
struct V_6 * V_9 = F_20 ( V_37 ) ;
int V_30 ;
V_30 = F_46 ( V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_47 ( V_9 -> V_11 ) ;
F_48 ( V_37 ) ;
return V_30 ;
}
