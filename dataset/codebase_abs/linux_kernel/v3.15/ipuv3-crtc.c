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
V_7 -> V_27 -> V_16 = V_16 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_28 * V_8 ,
int V_30 , int V_31 ,
struct V_15 * V_32 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
int V_20 ;
struct V_33 V_34 = {} ;
T_2 V_35 ;
F_11 ( V_1 -> V_9 , L_3 , V_10 ,
V_8 -> V_36 ) ;
F_11 ( V_1 -> V_9 , L_4 , V_10 ,
V_8 -> V_37 ) ;
V_35 = V_1 -> V_38 ;
if ( V_8 -> V_39 & V_40 )
V_34 . V_41 = 1 ;
if ( V_8 -> V_39 & V_42 )
V_34 . V_43 = 1 ;
if ( V_8 -> V_39 & V_44 )
V_34 . V_45 = 1 ;
V_34 . V_46 = 1 ;
V_34 . V_47 = 1 ;
V_34 . V_48 = V_8 -> V_36 ;
V_34 . V_49 = V_8 -> V_37 ;
V_34 . V_50 = V_35 ;
V_34 . V_51 = V_8 -> V_52 - V_8 -> V_53 ;
V_34 . V_54 = V_8 -> V_53 - V_8 -> V_55 ;
V_34 . V_56 = V_8 -> V_55 - V_8 -> V_36 ;
V_34 . V_57 = V_8 -> V_58 - V_8 -> V_59 ;
V_34 . V_60 = V_8 -> V_59 - V_8 -> V_61 ;
V_34 . V_62 = V_8 -> V_61 - V_8 -> V_37 ;
V_34 . V_63 = V_8 -> clock * 1000 ;
V_34 . V_64 = V_1 -> V_65 ;
V_34 . V_66 = 0 ;
V_34 . V_67 = V_1 -> V_68 ;
V_34 . V_69 = V_1 -> V_70 ;
V_20 = F_16 ( V_1 -> V_4 , V_1 -> V_3 , V_34 . V_41 ,
V_35 , V_8 -> V_36 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 ,
L_5 ,
V_20 ) ;
return V_20 ;
}
V_20 = F_18 ( V_1 -> V_3 , & V_34 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 ,
L_6 , V_20 ) ;
return V_20 ;
}
return F_19 ( V_1 -> V_5 [ 0 ] , V_7 , V_8 , V_7 -> V_27 -> V_16 ,
0 , 0 , V_8 -> V_36 , V_8 -> V_37 ,
V_30 , V_31 , V_8 -> V_36 , V_8 -> V_37 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
unsigned long V_39 ;
struct V_71 * V_72 = V_1 -> V_24 . V_9 ;
F_21 ( & V_72 -> V_73 , V_39 ) ;
if ( V_1 -> V_26 )
F_22 ( V_72 , - 1 , V_1 -> V_26 ) ;
V_1 -> V_26 = NULL ;
F_23 ( V_1 -> V_23 ) ;
F_24 ( & V_72 -> V_73 , V_39 ) ;
}
static T_3 F_25 ( int V_74 , void * V_75 )
{
struct V_1 * V_1 = V_75 ;
F_26 ( V_1 -> V_23 ) ;
if ( V_1 -> V_21 ) {
V_1 -> V_21 = NULL ;
F_27 ( V_1 -> V_5 [ 0 ] , V_1 -> V_24 . V_27 -> V_16 ,
V_1 -> V_5 [ 0 ] -> V_30 , V_1 -> V_5 [ 0 ] -> V_31 ) ;
F_20 ( V_1 ) ;
}
return V_76 ;
}
static bool F_28 ( struct V_6 * V_7 ,
const struct V_28 * V_8 ,
struct V_28 * V_77 )
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
static int F_33 ( struct V_6 * V_7 , T_2 V_78 ,
T_2 V_79 , int V_67 , int V_69 )
{
struct V_1 * V_1 = F_10 ( V_7 ) ;
V_1 -> V_38 = V_79 ;
V_1 -> V_68 = V_67 ;
V_1 -> V_70 = V_69 ;
switch ( V_78 ) {
case V_80 :
case V_81 :
case V_82 :
V_1 -> V_65 = V_83 |
V_84 ;
break;
case V_85 :
case V_86 :
V_1 -> V_65 = 0 ;
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
struct V_87 * V_88 )
{
struct V_89 * V_90 = F_39 ( V_1 -> V_9 -> V_91 ) ;
int V_20 ;
V_1 -> V_4 = F_40 ( V_90 , V_88 -> V_4 ) ;
if ( F_41 ( V_1 -> V_4 ) ) {
V_20 = F_42 ( V_1 -> V_4 ) ;
goto V_92;
}
V_1 -> V_3 = F_43 ( V_90 , V_88 -> V_3 ) ;
if ( F_41 ( V_1 -> V_3 ) ) {
V_20 = F_42 ( V_1 -> V_3 ) ;
goto V_92;
}
return 0 ;
V_92:
F_34 ( V_1 ) ;
return V_20 ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_87 * V_88 , struct V_71 * V_72 )
{
struct V_89 * V_90 = F_39 ( V_1 -> V_9 -> V_91 ) ;
int V_93 = - V_94 ;
int V_20 ;
int V_95 ;
V_20 = F_38 ( V_1 , V_88 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_7 ,
V_20 ) ;
return V_20 ;
}
V_20 = F_45 ( V_72 , & V_1 -> V_24 , & V_1 -> V_23 ,
& V_96 , V_1 -> V_9 -> V_97 ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_8 , V_20 ) ;
goto V_98;
}
if ( V_88 -> V_93 >= 0 )
V_93 = V_99 ;
V_95 = F_46 ( V_1 -> V_23 ) ;
V_1 -> V_5 [ 0 ] = F_47 ( V_1 -> V_24 . V_9 , V_90 ,
V_88 -> V_100 [ 0 ] , V_93 , F_48 ( V_95 ) , true ) ;
V_20 = F_49 ( V_1 -> V_5 [ 0 ] ) ;
if ( V_20 ) {
F_17 ( V_1 -> V_9 , L_9 ,
V_20 ) ;
goto V_101;
}
if ( V_88 -> V_93 >= 0 && V_88 -> V_100 [ 1 ] > 0 ) {
V_1 -> V_5 [ 1 ] = F_47 ( V_1 -> V_24 . V_9 , V_90 ,
V_88 -> V_100 [ 1 ] ,
V_102 ,
F_48 ( V_95 ) , false ) ;
if ( F_41 ( V_1 -> V_5 [ 1 ] ) )
V_1 -> V_5 [ 1 ] = NULL ;
}
V_1 -> V_74 = F_50 ( V_1 -> V_5 [ 0 ] ) ;
V_20 = F_51 ( V_1 -> V_9 , V_1 -> V_74 , F_25 , 0 ,
L_10 , V_1 ) ;
if ( V_20 < 0 ) {
F_17 ( V_1 -> V_9 , L_11 , V_20 ) ;
goto V_103;
}
return 0 ;
V_103:
F_52 ( V_1 -> V_5 [ 0 ] ) ;
V_101:
F_53 ( V_1 -> V_23 ) ;
V_98:
F_34 ( V_1 ) ;
return V_20 ;
}
static struct V_104 * F_54 ( struct V_104 * V_91 ,
int V_105 )
{
struct V_104 * V_106 ;
int V_95 , V_20 ;
V_106 = F_55 ( V_91 , L_12 ) ;
while ( V_106 ) {
V_20 = F_56 ( V_106 , L_13 , & V_95 ) ;
if ( ! V_20 && V_95 == V_105 )
return V_106 ;
do {
V_106 = F_57 ( V_91 , V_106 ) ;
if ( ! V_106 )
return NULL ;
} while ( F_58 ( V_106 -> V_107 , L_12 ) );
}
return NULL ;
}
static int F_59 ( struct V_108 * V_9 , struct V_108 * V_109 , void * V_110 )
{
struct V_87 * V_88 = V_9 -> V_111 ;
struct V_71 * V_72 = V_110 ;
struct V_1 * V_1 ;
int V_20 ;
V_1 = F_60 ( V_9 , sizeof( * V_1 ) , V_112 ) ;
if ( ! V_1 )
return - V_113 ;
V_1 -> V_9 = V_9 ;
V_20 = F_44 ( V_1 , V_88 , V_72 ) ;
if ( V_20 )
return V_20 ;
F_61 ( V_9 , V_1 ) ;
return 0 ;
}
static void F_62 ( struct V_108 * V_9 , struct V_108 * V_109 ,
void * V_110 )
{
struct V_1 * V_1 = F_39 ( V_9 ) ;
F_53 ( V_1 -> V_23 ) ;
F_52 ( V_1 -> V_5 [ 0 ] ) ;
F_34 ( V_1 ) ;
}
static int F_63 ( struct V_114 * V_115 )
{
struct V_108 * V_9 = & V_115 -> V_9 ;
struct V_87 * V_88 = V_9 -> V_111 ;
int V_20 ;
if ( ! V_9 -> V_111 )
return - V_94 ;
if ( ! V_9 -> V_97 ) {
V_9 -> V_97 = F_54 ( V_9 -> V_91 -> V_97 ,
V_88 -> V_3 + 2 ) ;
if ( ! V_9 -> V_97 ) {
F_17 ( V_9 , L_14 ,
V_88 -> V_3 + 2 , V_9 -> V_91 -> V_97 -> V_116 ) ;
return - V_117 ;
}
}
V_20 = F_64 ( V_9 , F_65 ( 32 ) ) ;
if ( V_20 )
return V_20 ;
return F_66 ( V_9 , & V_118 ) ;
}
static int F_67 ( struct V_114 * V_115 )
{
F_68 ( & V_115 -> V_9 , & V_118 ) ;
return 0 ;
}
