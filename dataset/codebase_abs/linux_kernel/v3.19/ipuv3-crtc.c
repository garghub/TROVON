static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( V_1 -> V_6 )
return;
F_3 ( V_3 ) ;
F_4 ( V_1 -> V_7 [ 0 ] ) ;
F_5 ( V_1 -> V_8 ) ;
F_6 ( V_1 -> V_9 ) ;
V_1 -> V_6 = 1 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( ! V_1 -> V_6 )
return;
F_8 ( V_1 -> V_8 ) ;
F_9 ( V_1 -> V_9 ) ;
F_10 ( V_1 -> V_7 [ 0 ] ) ;
F_11 ( V_3 ) ;
V_1 -> V_6 = 0 ;
}
static void F_12 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_14 ( V_1 -> V_4 , L_1 , V_13 , V_12 ) ;
switch ( V_12 ) {
case V_14 :
F_1 ( V_1 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
F_7 ( V_1 ) ;
break;
}
}
static int F_15 ( struct V_10 * V_11 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
T_1 V_22 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
int V_23 ;
if ( V_1 -> V_24 )
return - V_25 ;
V_23 = F_16 ( V_1 -> V_26 ) ;
if ( V_23 ) {
F_14 ( V_1 -> V_4 , L_2 ) ;
F_17 ( & V_21 -> V_27 . V_28 ) ;
return V_23 ;
}
V_1 -> V_24 = V_19 ;
V_1 -> V_29 = V_21 ;
V_11 -> V_30 -> V_19 = V_19 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_31 * V_32 ,
struct V_31 * V_12 ,
int V_33 , int V_34 ,
struct V_18 * V_35 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
int V_23 ;
struct V_36 V_37 = {} ;
T_2 V_38 ;
F_14 ( V_1 -> V_4 , L_3 , V_13 ,
V_12 -> V_39 ) ;
F_14 ( V_1 -> V_4 , L_4 , V_13 ,
V_12 -> V_40 ) ;
V_38 = V_1 -> V_41 ;
if ( V_12 -> V_42 & V_43 )
V_37 . V_44 = 1 ;
if ( V_12 -> V_42 & V_45 )
V_37 . V_46 = 1 ;
if ( V_12 -> V_42 & V_47 )
V_37 . V_48 = 1 ;
V_37 . V_49 = 1 ;
V_37 . V_50 = 0 ;
V_37 . V_51 = V_12 -> V_39 ;
V_37 . V_52 = V_12 -> V_40 ;
V_37 . V_53 = V_38 ;
V_37 . V_54 = V_12 -> V_55 - V_12 -> V_56 ;
V_37 . V_57 = V_12 -> V_56 - V_12 -> V_58 ;
V_37 . V_59 = V_12 -> V_58 - V_12 -> V_39 ;
V_37 . V_60 = V_12 -> V_61 - V_12 -> V_62 ;
V_37 . V_63 = V_12 -> V_62 - V_12 -> V_64 ;
V_37 . V_65 = V_12 -> V_64 - V_12 -> V_40 ;
V_37 . V_66 = V_12 -> clock * 1000 ;
V_37 . V_67 = V_1 -> V_68 ;
V_37 . V_69 = 0 ;
V_37 . V_70 = V_1 -> V_71 ;
V_37 . V_72 = V_1 -> V_73 ;
V_23 = F_19 ( V_1 -> V_8 , V_1 -> V_9 , V_37 . V_44 ,
V_38 , V_12 -> V_39 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 ,
L_5 ,
V_23 ) ;
return V_23 ;
}
V_23 = F_21 ( V_1 -> V_9 , & V_37 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 ,
L_6 , V_23 ) ;
return V_23 ;
}
return F_22 ( V_1 -> V_7 [ 0 ] , V_11 , V_12 ,
V_11 -> V_30 -> V_19 ,
0 , 0 , V_12 -> V_39 , V_12 -> V_40 ,
V_33 , V_34 , V_12 -> V_39 , V_12 -> V_40 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
unsigned long V_42 ;
struct V_74 * V_75 = V_1 -> V_27 . V_4 ;
F_24 ( & V_75 -> V_76 , V_42 ) ;
if ( V_1 -> V_29 )
F_25 ( V_75 , - 1 , V_1 -> V_29 ) ;
V_1 -> V_29 = NULL ;
F_26 ( V_1 -> V_26 ) ;
F_27 ( & V_75 -> V_76 , V_42 ) ;
}
static T_3 F_28 ( int V_77 , void * V_78 )
{
struct V_1 * V_1 = V_78 ;
F_29 ( V_1 -> V_26 ) ;
if ( V_1 -> V_24 ) {
struct V_79 * V_7 = V_1 -> V_7 [ 0 ] ;
V_1 -> V_24 = NULL ;
F_30 ( V_7 , V_1 -> V_27 . V_30 -> V_19 ,
V_7 -> V_33 , V_7 -> V_34 ) ;
F_23 ( V_1 ) ;
}
return V_80 ;
}
static bool F_31 ( struct V_10 * V_11 ,
const struct V_31 * V_12 ,
struct V_31 * V_81 )
{
return true ;
}
static void F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_7 ( V_1 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
F_1 ( V_1 ) ;
}
static int F_34 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
V_1 -> V_29 = NULL ;
V_1 -> V_24 = NULL ;
}
static int F_36 ( struct V_10 * V_11 , T_2 V_82 ,
T_2 V_83 , int V_70 , int V_72 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
V_1 -> V_41 = V_83 ;
V_1 -> V_71 = V_70 ;
V_1 -> V_73 = V_72 ;
switch ( V_82 ) {
case V_84 :
case V_85 :
case V_86 :
V_1 -> V_68 = V_87 |
V_88 ;
break;
case V_89 :
case V_90 :
V_1 -> V_68 = 0 ;
break;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_1 )
{
if ( ! F_38 ( V_1 -> V_8 ) )
F_39 ( V_1 -> V_8 ) ;
if ( ! F_38 ( V_1 -> V_9 ) )
F_40 ( V_1 -> V_9 ) ;
}
static int F_41 ( struct V_1 * V_1 ,
struct V_91 * V_92 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_23 ;
V_1 -> V_8 = F_42 ( V_3 , V_92 -> V_8 ) ;
if ( F_43 ( V_1 -> V_8 ) ) {
V_23 = F_44 ( V_1 -> V_8 ) ;
goto V_93;
}
V_1 -> V_9 = F_45 ( V_3 , V_92 -> V_9 ) ;
if ( F_43 ( V_1 -> V_9 ) ) {
V_23 = F_44 ( V_1 -> V_9 ) ;
goto V_93;
}
return 0 ;
V_93:
F_37 ( V_1 ) ;
return V_23 ;
}
static int F_46 ( struct V_1 * V_1 ,
struct V_91 * V_92 , struct V_74 * V_75 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_94 = - V_95 ;
int V_23 ;
int V_96 ;
V_23 = F_41 ( V_1 , V_92 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_7 ,
V_23 ) ;
return V_23 ;
}
V_23 = F_47 ( V_75 , & V_1 -> V_27 , & V_1 -> V_26 ,
& V_97 , V_1 -> V_4 -> V_98 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_8 , V_23 ) ;
goto V_99;
}
if ( V_92 -> V_94 >= 0 )
V_94 = V_100 ;
V_96 = F_48 ( V_1 -> V_26 ) ;
V_1 -> V_7 [ 0 ] = F_49 ( V_1 -> V_27 . V_4 , V_3 ,
V_92 -> V_101 [ 0 ] , V_94 , F_50 ( V_96 ) , true ) ;
V_23 = F_51 ( V_1 -> V_7 [ 0 ] ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_9 ,
V_23 ) ;
goto V_102;
}
if ( V_92 -> V_94 >= 0 && V_92 -> V_101 [ 1 ] > 0 ) {
V_1 -> V_7 [ 1 ] = F_49 ( V_1 -> V_27 . V_4 , V_3 ,
V_92 -> V_101 [ 1 ] ,
V_103 ,
F_50 ( V_96 ) , false ) ;
if ( F_43 ( V_1 -> V_7 [ 1 ] ) )
V_1 -> V_7 [ 1 ] = NULL ;
}
V_1 -> V_77 = F_52 ( V_1 -> V_7 [ 0 ] ) ;
V_23 = F_53 ( V_1 -> V_4 , V_1 -> V_77 , F_28 , 0 ,
L_10 , V_1 ) ;
if ( V_23 < 0 ) {
F_20 ( V_1 -> V_4 , L_11 , V_23 ) ;
goto V_104;
}
return 0 ;
V_104:
F_54 ( V_1 -> V_7 [ 0 ] ) ;
V_102:
F_55 ( V_1 -> V_26 ) ;
V_99:
F_37 ( V_1 ) ;
return V_23 ;
}
static struct V_105 * F_56 ( struct V_105 * V_5 ,
int V_106 )
{
struct V_105 * V_107 ;
int V_96 , V_23 ;
V_107 = F_57 ( V_5 , L_12 ) ;
while ( V_107 ) {
V_23 = F_58 ( V_107 , L_13 , & V_96 ) ;
if ( ! V_23 && V_96 == V_106 )
return V_107 ;
do {
V_107 = F_59 ( V_5 , V_107 ) ;
if ( ! V_107 )
return NULL ;
} while ( F_60 ( V_107 -> V_108 , L_12 ) );
}
return NULL ;
}
static int F_61 ( struct V_109 * V_4 , struct V_109 * V_110 , void * V_111 )
{
struct V_91 * V_92 = V_4 -> V_112 ;
struct V_74 * V_75 = V_111 ;
struct V_1 * V_1 ;
int V_23 ;
V_1 = F_62 ( V_4 , sizeof( * V_1 ) , V_113 ) ;
if ( ! V_1 )
return - V_114 ;
V_1 -> V_4 = V_4 ;
V_23 = F_46 ( V_1 , V_92 , V_75 ) ;
if ( V_23 )
return V_23 ;
F_63 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_64 ( struct V_109 * V_4 , struct V_109 * V_110 ,
void * V_111 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_55 ( V_1 -> V_26 ) ;
F_54 ( V_1 -> V_7 [ 0 ] ) ;
F_37 ( V_1 ) ;
}
static int F_65 ( struct V_115 * V_116 )
{
struct V_109 * V_4 = & V_116 -> V_4 ;
struct V_91 * V_92 = V_4 -> V_112 ;
int V_23 ;
if ( ! V_4 -> V_112 )
return - V_95 ;
if ( ! V_4 -> V_98 ) {
V_4 -> V_98 = F_56 ( V_4 -> V_5 -> V_98 ,
V_92 -> V_9 + 2 ) ;
if ( ! V_4 -> V_98 ) {
F_20 ( V_4 , L_14 ,
V_92 -> V_9 + 2 , V_4 -> V_5 -> V_98 -> V_117 ) ;
return - V_118 ;
}
}
V_23 = F_66 ( V_4 , F_67 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
return F_68 ( V_4 , & V_119 ) ;
}
static int F_69 ( struct V_115 * V_116 )
{
F_70 ( & V_116 -> V_4 , & V_119 ) ;
return 0 ;
}
