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
return F_22 ( V_1 -> V_7 [ 0 ] , V_11 , V_12 , V_11 -> V_30 -> V_19 ,
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
V_1 -> V_24 = NULL ;
F_30 ( V_1 -> V_7 [ 0 ] , V_1 -> V_27 . V_30 -> V_19 ,
V_1 -> V_7 [ 0 ] -> V_33 , V_1 -> V_7 [ 0 ] -> V_34 ) ;
F_23 ( V_1 ) ;
}
return V_79 ;
}
static bool F_31 ( struct V_10 * V_11 ,
const struct V_31 * V_12 ,
struct V_31 * V_80 )
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
static int F_36 ( struct V_10 * V_11 , T_2 V_81 ,
T_2 V_82 , int V_70 , int V_72 )
{
struct V_1 * V_1 = F_13 ( V_11 ) ;
V_1 -> V_41 = V_82 ;
V_1 -> V_71 = V_70 ;
V_1 -> V_73 = V_72 ;
switch ( V_81 ) {
case V_83 :
case V_84 :
case V_85 :
V_1 -> V_68 = V_86 |
V_87 ;
break;
case V_88 :
case V_89 :
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
struct V_90 * V_91 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_23 ;
V_1 -> V_8 = F_42 ( V_3 , V_91 -> V_8 ) ;
if ( F_43 ( V_1 -> V_8 ) ) {
V_23 = F_44 ( V_1 -> V_8 ) ;
goto V_92;
}
V_1 -> V_9 = F_45 ( V_3 , V_91 -> V_9 ) ;
if ( F_43 ( V_1 -> V_9 ) ) {
V_23 = F_44 ( V_1 -> V_9 ) ;
goto V_92;
}
return 0 ;
V_92:
F_37 ( V_1 ) ;
return V_23 ;
}
static int F_46 ( struct V_1 * V_1 ,
struct V_90 * V_91 , struct V_74 * V_75 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_93 = - V_94 ;
int V_23 ;
int V_95 ;
V_23 = F_41 ( V_1 , V_91 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_7 ,
V_23 ) ;
return V_23 ;
}
V_23 = F_47 ( V_75 , & V_1 -> V_27 , & V_1 -> V_26 ,
& V_96 , V_1 -> V_4 -> V_97 ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_8 , V_23 ) ;
goto V_98;
}
if ( V_91 -> V_93 >= 0 )
V_93 = V_99 ;
V_95 = F_48 ( V_1 -> V_26 ) ;
V_1 -> V_7 [ 0 ] = F_49 ( V_1 -> V_27 . V_4 , V_3 ,
V_91 -> V_100 [ 0 ] , V_93 , F_50 ( V_95 ) , true ) ;
V_23 = F_51 ( V_1 -> V_7 [ 0 ] ) ;
if ( V_23 ) {
F_20 ( V_1 -> V_4 , L_9 ,
V_23 ) ;
goto V_101;
}
if ( V_91 -> V_93 >= 0 && V_91 -> V_100 [ 1 ] > 0 ) {
V_1 -> V_7 [ 1 ] = F_49 ( V_1 -> V_27 . V_4 , V_3 ,
V_91 -> V_100 [ 1 ] ,
V_102 ,
F_50 ( V_95 ) , false ) ;
if ( F_43 ( V_1 -> V_7 [ 1 ] ) )
V_1 -> V_7 [ 1 ] = NULL ;
}
V_1 -> V_77 = F_52 ( V_1 -> V_7 [ 0 ] ) ;
V_23 = F_53 ( V_1 -> V_4 , V_1 -> V_77 , F_28 , 0 ,
L_10 , V_1 ) ;
if ( V_23 < 0 ) {
F_20 ( V_1 -> V_4 , L_11 , V_23 ) ;
goto V_103;
}
return 0 ;
V_103:
F_54 ( V_1 -> V_7 [ 0 ] ) ;
V_101:
F_55 ( V_1 -> V_26 ) ;
V_98:
F_37 ( V_1 ) ;
return V_23 ;
}
static struct V_104 * F_56 ( struct V_104 * V_5 ,
int V_105 )
{
struct V_104 * V_106 ;
int V_95 , V_23 ;
V_106 = F_57 ( V_5 , L_12 ) ;
while ( V_106 ) {
V_23 = F_58 ( V_106 , L_13 , & V_95 ) ;
if ( ! V_23 && V_95 == V_105 )
return V_106 ;
do {
V_106 = F_59 ( V_5 , V_106 ) ;
if ( ! V_106 )
return NULL ;
} while ( F_60 ( V_106 -> V_107 , L_12 ) );
}
return NULL ;
}
static int F_61 ( struct V_108 * V_4 , struct V_108 * V_109 , void * V_110 )
{
struct V_90 * V_91 = V_4 -> V_111 ;
struct V_74 * V_75 = V_110 ;
struct V_1 * V_1 ;
int V_23 ;
V_1 = F_62 ( V_4 , sizeof( * V_1 ) , V_112 ) ;
if ( ! V_1 )
return - V_113 ;
V_1 -> V_4 = V_4 ;
V_23 = F_46 ( V_1 , V_91 , V_75 ) ;
if ( V_23 )
return V_23 ;
F_63 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_64 ( struct V_108 * V_4 , struct V_108 * V_109 ,
void * V_110 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_55 ( V_1 -> V_26 ) ;
F_54 ( V_1 -> V_7 [ 0 ] ) ;
F_37 ( V_1 ) ;
}
static int F_65 ( struct V_114 * V_115 )
{
struct V_108 * V_4 = & V_115 -> V_4 ;
struct V_90 * V_91 = V_4 -> V_111 ;
int V_23 ;
if ( ! V_4 -> V_111 )
return - V_94 ;
if ( ! V_4 -> V_97 ) {
V_4 -> V_97 = F_56 ( V_4 -> V_5 -> V_97 ,
V_91 -> V_9 + 2 ) ;
if ( ! V_4 -> V_97 ) {
F_20 ( V_4 , L_14 ,
V_91 -> V_9 + 2 , V_4 -> V_5 -> V_97 -> V_116 ) ;
return - V_117 ;
}
}
V_23 = F_66 ( V_4 , F_67 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
return F_68 ( V_4 , & V_118 ) ;
}
static int F_69 ( struct V_114 * V_115 )
{
F_70 ( & V_115 -> V_4 , & V_118 ) ;
return 0 ;
}
