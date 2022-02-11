static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 )
return;
F_2 ( V_1 -> V_3 ) ;
F_3 ( V_1 -> V_4 ) ;
F_4 ( V_1 -> V_5 [ 0 ] ) ;
V_1 -> V_2 = 1 ;
}
static void F_5 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_2 )
return;
F_6 ( V_1 -> V_5 [ 0 ] ) ;
F_7 ( V_1 -> V_4 ) ;
F_8 ( V_1 -> V_3 ) ;
V_1 -> V_2 = 0 ;
}
static void F_9 ( struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
F_11 ( V_1 -> V_9 , L_1 , V_10 , V_8 ) ;
switch ( V_8 ) {
case V_11 :
F_1 ( V_1 ) ;
break;
case V_12 :
case V_13 :
case V_14 :
F_5 ( V_1 ) ;
break;
}
}
static int F_12 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_1 V_19 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
int V_20 ;
if ( V_1 -> V_21 )
return - V_22 ;
V_20 = F_13 ( V_1 -> V_23 ) ;
if ( V_20 ) {
F_11 ( V_1 -> V_9 , L_2 ) ;
F_14 ( & V_18 -> V_24 . V_25 ) ;
return V_20 ;
}
V_1 -> V_21 = V_16 ;
V_1 -> V_26 = V_18 ;
V_7 -> V_16 = V_16 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_27 * V_8 ,
int V_29 , int V_30 ,
struct V_15 * V_31 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
int V_20 ;
struct V_32 V_33 = {} ;
T_2 V_34 ;
F_11 ( V_1 -> V_9 , L_3 , V_10 ,
V_8 -> V_35 ) ;
F_11 ( V_1 -> V_9 , L_4 , V_10 ,
V_8 -> V_36 ) ;
V_34 = V_1 -> V_37 ;
if ( V_8 -> V_38 & V_39 )
V_33 . V_40 = 1 ;
if ( V_8 -> V_38 & V_41 )
V_33 . V_42 = 1 ;
if ( V_8 -> V_38 & V_43 )
V_33 . V_44 = 1 ;
V_33 . V_45 = 1 ;
V_33 . V_46 = 1 ;
V_33 . V_47 = V_8 -> V_35 ;
V_33 . V_48 = V_8 -> V_36 ;
V_33 . V_49 = V_34 ;
V_33 . V_50 = V_8 -> V_51 - V_8 -> V_52 ;
V_33 . V_53 = V_8 -> V_52 - V_8 -> V_54 ;
V_33 . V_55 = V_8 -> V_54 - V_8 -> V_35 ;
V_33 . V_56 = V_8 -> V_57 - V_8 -> V_58 ;
V_33 . V_59 = V_8 -> V_58 - V_8 -> V_60 ;
V_33 . V_61 = V_8 -> V_60 - V_8 -> V_36 ;
V_33 . V_62 = V_8 -> clock * 1000 ;
V_33 . V_63 = V_1 -> V_64 ;
V_33 . V_65 = 0 ;
V_33 . V_66 = V_1 -> V_67 ;
V_33 . V_68 = V_1 -> V_69 ;
V_20 = F_16 ( V_1 -> V_4 , V_1 -> V_3 , V_33 . V_40 ,
V_34 , V_8 -> V_35 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 ,
L_5 ,
V_20 ) ;
return V_20 ;
}
V_20 = F_18 ( V_1 -> V_3 , & V_33 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 ,
L_6 , V_20 ) ;
return V_20 ;
}
return F_19 ( V_1 -> V_5 [ 0 ] , V_7 , V_8 , V_7 -> V_16 ,
0 , 0 , V_8 -> V_35 , V_8 -> V_36 ,
V_29 , V_30 , V_8 -> V_35 , V_8 -> V_36 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
unsigned long V_38 ;
struct V_70 * V_71 = V_1 -> V_24 . V_9 ;
F_21 ( & V_71 -> V_72 , V_38 ) ;
if ( V_1 -> V_26 )
F_22 ( V_71 , - 1 , V_1 -> V_26 ) ;
V_1 -> V_26 = NULL ;
F_23 ( V_1 -> V_23 ) ;
F_24 ( & V_71 -> V_72 , V_38 ) ;
}
static T_3 F_25 ( int V_73 , void * V_74 )
{
struct V_1 * V_1 = V_74 ;
F_26 ( V_1 -> V_23 ) ;
if ( V_1 -> V_21 ) {
V_1 -> V_21 = NULL ;
F_27 ( V_1 -> V_5 [ 0 ] , V_1 -> V_24 . V_16 ,
V_1 -> V_5 [ 0 ] -> V_29 , V_1 -> V_5 [ 0 ] -> V_30 ) ;
F_20 ( V_1 ) ;
}
return V_75 ;
}
static bool F_28 ( struct V_6 * V_7 ,
const struct V_27 * V_8 ,
struct V_27 * V_76 )
{
return true ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
F_5 ( V_1 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
F_1 ( V_1 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
V_1 -> V_26 = NULL ;
V_1 -> V_21 = NULL ;
}
static int F_33 ( struct V_6 * V_7 , T_2 V_77 ,
T_2 V_78 , int V_66 , int V_68 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
V_1 -> V_37 = V_78 ;
V_1 -> V_67 = V_66 ;
V_1 -> V_69 = V_68 ;
switch ( V_77 ) {
case V_79 :
case V_80 :
case V_81 :
V_1 -> V_64 = V_82 |
V_83 ;
break;
case V_84 :
V_1 -> V_64 = 0 ;
break;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_1 )
{
if ( ! F_35 ( V_1 -> V_4 ) )
F_36 ( V_1 -> V_4 ) ;
if ( ! F_35 ( V_1 -> V_3 ) )
F_37 ( V_1 -> V_3 ) ;
}
static int F_38 ( struct V_1 * V_1 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 = F_39 ( V_1 -> V_9 -> V_89 ) ;
int V_20 ;
V_1 -> V_4 = F_40 ( V_88 , V_86 -> V_4 ) ;
if ( F_41 ( V_1 -> V_4 ) ) {
V_20 = F_42 ( V_1 -> V_4 ) ;
goto V_90;
}
V_1 -> V_3 = F_43 ( V_88 , V_86 -> V_3 ) ;
if ( F_41 ( V_1 -> V_3 ) ) {
V_20 = F_42 ( V_1 -> V_3 ) ;
goto V_90;
}
return 0 ;
V_90:
F_34 ( V_1 ) ;
return V_20 ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 = F_39 ( V_1 -> V_9 -> V_89 ) ;
int V_91 = - V_92 ;
int V_20 ;
int V_93 ;
V_20 = F_38 ( V_1 , V_86 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_7 ,
V_20 ) ;
return V_20 ;
}
V_20 = F_45 ( & V_1 -> V_24 ,
& V_1 -> V_23 ,
& V_94 , V_95 ,
V_1 -> V_9 -> V_89 -> V_96 , V_86 -> V_3 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_8 , V_20 ) ;
goto V_97;
}
if ( V_86 -> V_91 >= 0 )
V_91 = V_98 ;
V_93 = F_46 ( V_1 -> V_23 ) ;
V_1 -> V_5 [ 0 ] = F_47 ( V_1 -> V_24 . V_9 , V_88 ,
V_86 -> V_99 [ 0 ] , V_91 , F_48 ( V_93 ) , true ) ;
V_20 = F_49 ( V_1 -> V_5 [ 0 ] ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_9 ,
V_20 ) ;
goto V_100;
}
if ( V_86 -> V_91 >= 0 && V_86 -> V_99 [ 1 ] > 0 ) {
V_1 -> V_5 [ 1 ] = F_47 ( V_1 -> V_24 . V_9 , V_88 ,
V_86 -> V_99 [ 1 ] ,
V_101 ,
F_48 ( V_93 ) , false ) ;
if ( F_41 ( V_1 -> V_5 [ 1 ] ) )
V_1 -> V_5 [ 1 ] = NULL ;
}
V_1 -> V_73 = F_50 ( V_1 -> V_5 [ 0 ] ) ;
V_20 = F_51 ( V_1 -> V_9 , V_1 -> V_73 , F_25 , 0 ,
L_10 , V_1 ) ;
if ( V_20 < 0 ) {
F_17 ( V_1 -> V_9 , L_11 , V_20 ) ;
goto V_102;
}
return 0 ;
V_102:
F_52 ( V_1 -> V_5 [ 0 ] ) ;
V_100:
F_53 ( V_1 -> V_23 ) ;
V_97:
F_34 ( V_1 ) ;
return V_20 ;
}
static int F_54 ( struct V_103 * V_104 )
{
struct V_85 * V_86 = V_104 -> V_9 . V_105 ;
struct V_1 * V_1 ;
int V_20 ;
if ( ! V_86 )
return - V_92 ;
V_20 = F_55 ( & V_104 -> V_9 , F_56 ( 32 ) ) ;
if ( V_20 )
return V_20 ;
V_1 = F_57 ( & V_104 -> V_9 , sizeof( * V_1 ) , V_106 ) ;
if ( ! V_1 )
return - V_107 ;
V_1 -> V_9 = & V_104 -> V_9 ;
V_20 = F_44 ( V_1 , V_86 ) ;
if ( V_20 )
return V_20 ;
F_58 ( V_104 , V_1 ) ;
return 0 ;
}
static int F_59 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_60 ( V_104 ) ;
F_53 ( V_1 -> V_23 ) ;
F_52 ( V_1 -> V_5 [ 0 ] ) ;
F_34 ( V_1 ) ;
return 0 ;
}
