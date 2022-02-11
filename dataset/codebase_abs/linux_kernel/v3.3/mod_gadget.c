static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
F_5 ( V_11 , L_1 , F_6 ( V_9 ) ) ;
V_4 -> V_12 . V_5 = V_5 ;
V_4 -> V_12 . V_13 ( & V_2 -> V_14 , & V_4 -> V_12 ) ;
}
static void F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_3 * V_4 = F_9 ( V_18 ) ;
V_4 -> V_12 . V_19 = V_18 -> V_19 ;
F_1 ( V_2 , V_4 , 0 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_17 * V_18 = F_11 ( V_4 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
V_12 -> V_19 = 0 ;
V_12 -> V_5 = - V_21 ;
F_12 ( V_9 , V_18 , F_7 ,
V_12 -> V_22 , V_12 -> V_23 , V_12 -> V_24 , - 1 ) ;
F_13 ( V_9 ) ;
F_5 ( V_11 , L_2 ,
F_6 ( V_9 ) ,
V_12 -> V_23 ) ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_17 * V_18 ,
enum V_25 V_26 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
if ( V_18 -> V_27 != V_28 ) {
F_15 ( V_11 , L_3 ) ;
return - V_29 ;
}
if ( V_12 -> V_27 == V_28 ) {
V_18 -> V_27 = F_16 ( V_11 , V_18 -> V_22 , V_18 -> V_23 , V_26 ) ;
} else {
F_17 ( V_11 , V_12 -> V_27 , V_12 -> V_23 , V_26 ) ;
V_18 -> V_27 = V_12 -> V_27 ;
}
if ( F_18 ( V_11 , V_18 -> V_27 ) ) {
F_15 ( V_11 , L_4 , ( V_30 ) V_18 -> V_27 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_19 ( struct V_10 * V_11 ,
struct V_17 * V_18 ,
enum V_25 V_26 )
{
struct V_3 * V_4 = F_9 ( V_18 ) ;
struct V_20 * V_12 = & V_4 -> V_12 ;
if ( V_18 -> V_27 == V_28 ) {
F_15 ( V_11 , L_5 ) ;
return - V_29 ;
}
if ( V_12 -> V_27 == V_28 )
F_20 ( V_11 , V_18 -> V_27 , V_18 -> V_23 , V_26 ) ;
else
F_21 ( V_11 , V_12 -> V_27 , V_12 -> V_23 , V_26 ) ;
V_18 -> V_27 = V_28 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , int V_31 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
enum V_25 V_26 ;
V_26 = F_23 ( V_9 ) ? V_32 : V_33 ;
if ( V_31 )
return F_14 ( V_11 , V_18 , V_26 ) ;
else
return F_19 ( V_11 , V_18 , V_26 ) ;
}
static int F_24 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_36 = F_26 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_36 ) ;
F_27 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ! F_29 ( V_7 , V_37 ) ) {
F_30 ( V_9 ) ;
F_31 ( V_9 ) ;
F_32 ( V_9 ) ;
}
F_24 ( V_16 , V_2 , V_35 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
switch ( F_34 ( V_35 -> V_38 ) ) {
case V_39 :
F_24 ( V_16 , V_2 , V_35 ) ;
F_35 ( 100 ) ;
F_36 ( V_16 , F_34 ( V_35 -> V_40 >> 8 ) ) ;
break;
default:
F_24 ( V_16 , V_2 , V_35 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_38 ( V_9 ) ;
F_24 ( V_16 , V_2 , V_35 ) ;
return 0 ;
}
static void F_39 ( struct V_41 * V_14 ,
struct V_20 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
F_41 ( V_4 -> V_18 . V_22 ) ;
F_42 ( V_14 , V_12 ) ;
}
static void F_43 ( struct V_6 * V_7 ,
unsigned short V_5 )
{
struct V_1 * V_36 = F_26 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_36 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_20 * V_12 ;
unsigned short * V_22 ;
V_12 = F_44 ( & V_36 -> V_14 , V_42 ) ;
if ( ! V_12 ) {
F_15 ( V_11 , L_6 ) ;
return;
}
V_22 = F_45 ( sizeof( * V_22 ) , V_42 ) ;
if ( ! V_22 ) {
F_42 ( & V_36 -> V_14 , V_12 ) ;
F_15 ( V_11 , L_7 ) ;
return;
}
* V_22 = F_46 ( V_5 ) ;
V_12 -> V_13 = F_39 ;
V_12 -> V_22 = V_22 ;
V_12 -> V_23 = sizeof( * V_22 ) ;
V_12 -> V_24 = 0 ;
V_9 -> V_43 = & V_44 ;
F_10 ( V_36 , F_40 ( V_12 ) ) ;
}
static int F_47 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 1 << V_45 ;
F_43 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_48 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned short V_5 = 0 ;
F_43 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_49 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned short V_5 = 0 ;
if ( F_50 ( V_9 ) )
V_5 = 1 << V_46 ;
F_43 ( V_7 , V_5 ) ;
return 0 ;
}
static int F_51 ( struct V_15 * V_16 ,
struct V_47 * V_43 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_48 = V_35 -> V_49 & V_50 ;
int V_51 = F_34 ( V_35 -> V_40 ) & V_52 ;
int V_53 = 0 ;
int (* F_52)( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_34 * V_35 );
char * V_54 ;
V_2 = F_53 ( V_7 , V_51 ) ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 ) {
F_15 ( V_11 , L_8 ) ;
return - V_55 ;
}
switch ( V_48 ) {
case V_56 :
V_54 = L_9 ;
F_52 = V_43 -> V_10 ;
break;
case V_57 :
V_54 = L_10 ;
F_52 = V_43 -> V_58 ;
break;
case V_59 :
V_54 = L_11 ;
F_52 = V_43 -> V_60 ;
break;
default:
F_54 ( V_11 , L_12 , V_48 ) ;
F_52 = NULL ;
V_53 = - V_55 ;
}
if ( F_52 ) {
F_5 ( V_11 , L_13 , V_43 -> V_61 , V_51 , V_54 ) ;
V_53 = F_52 ( V_16 , V_2 , V_35 ) ;
}
return V_53 ;
}
static int F_55 ( struct V_15 * V_16 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
V_7 -> V_64 . V_65 = F_56 ( V_16 ) ;
F_5 ( V_11 , L_14 ,
F_57 ( V_63 ) ,
V_7 -> V_64 . V_65 ) ;
return 0 ;
}
static int F_58 ( struct V_15 * V_16 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_36 = F_26 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_36 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_34 V_35 ;
struct V_47 * V_66 = NULL ;
int V_67 = F_59 ( V_63 ) ;
int V_53 = 0 ;
F_5 ( V_11 , L_15 , V_67 ) ;
switch ( V_67 ) {
case V_68 :
V_9 -> V_43 = & V_44 ;
break;
case V_69 :
V_9 -> V_43 = & V_70 ;
break;
case V_71 :
V_9 -> V_43 = & V_72 ;
break;
default:
return V_53 ;
}
F_60 ( V_16 , & V_35 ) ;
switch ( V_35 . V_49 & V_73 ) {
case V_74 :
switch ( V_35 . V_75 ) {
case V_76 :
V_66 = & V_77 ;
break;
case V_78 :
V_66 = & V_79 ;
break;
case V_80 :
V_66 = & V_81 ;
break;
}
}
if ( V_66 )
V_53 = F_51 ( V_16 , V_66 , & V_35 ) ;
else
V_53 = V_7 -> V_82 -> V_83 ( & V_7 -> V_64 , & V_35 ) ;
if ( V_53 < 0 )
F_38 ( V_9 ) ;
return V_53 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_17 * V_18 ;
while ( 1 ) {
V_18 = F_62 ( V_9 , NULL ) ;
if ( ! V_18 )
break;
F_1 ( V_2 , F_9 ( V_18 ) , - V_84 ) ;
}
F_30 ( V_9 ) ;
return 0 ;
}
static void F_63 ( struct V_6 * V_7 )
{
int V_85 ;
struct V_1 * V_2 ;
F_64 (uep, gpriv, i)
V_2 -> V_9 = NULL ;
}
static int F_65 ( struct V_41 * V_14 ,
const struct V_86 * V_87 )
{
struct V_1 * V_2 = F_66 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_67 ( V_7 ) ;
struct V_8 * V_9 ;
int V_53 = - V_29 ;
if ( V_2 -> V_9 ) {
F_68 ( V_2 -> V_9 ) ;
F_31 ( V_2 -> V_9 ) ;
return 0 ;
}
V_9 = F_69 ( V_16 ,
F_70 ( V_87 ) ,
F_71 ( V_87 ) ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_9 -> V_88 = V_2 ;
F_72 ( V_9 , 0 ,
F_73 ( V_87 ) ,
F_74 ( V_87 ) ) ;
if ( F_71 ( V_87 ) )
V_9 -> V_43 = & V_89 ;
else
V_9 -> V_43 = & V_90 ;
V_53 = 0 ;
}
return V_53 ;
}
static int F_75 ( struct V_41 * V_14 )
{
struct V_1 * V_2 = F_66 ( V_14 ) ;
return F_61 ( V_2 ) ;
}
static struct V_20 * F_76 ( struct V_41 * V_14 ,
T_1 V_91 )
{
struct V_3 * V_4 ;
V_4 = F_77 ( sizeof *V_4 , V_91 ) ;
if ( ! V_4 )
return NULL ;
F_78 ( F_11 ( V_4 ) ) ;
V_4 -> V_12 . V_27 = V_28 ;
return & V_4 -> V_12 ;
}
static void F_79 ( struct V_41 * V_14 ,
struct V_20 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
F_80 ( ! F_81 ( & V_4 -> V_18 . V_92 ) ) ;
F_41 ( V_4 ) ;
}
static int F_82 ( struct V_41 * V_14 , struct V_20 * V_12 ,
T_1 V_91 )
{
struct V_1 * V_2 = F_66 ( V_14 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_40 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( F_83 ( V_7 ) ||
F_84 ( ! V_7 -> V_82 ) ||
F_84 ( ! V_9 ) )
return - V_93 ;
F_10 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_85 ( struct V_41 * V_14 , struct V_20 * V_12 )
{
struct V_1 * V_2 = F_66 ( V_14 ) ;
struct V_3 * V_4 = F_40 ( V_12 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_62 ( V_9 , F_11 ( V_4 ) ) ;
F_1 ( V_2 , V_4 , - V_84 ) ;
return 0 ;
}
static int F_86 ( struct V_41 * V_14 , int V_94 , int V_95 )
{
struct V_1 * V_2 = F_66 ( V_14 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_67 ( V_7 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_96 ;
F_61 ( V_2 ) ;
F_5 ( V_11 , L_16 ,
V_94 , F_6 ( V_9 ) ) ;
F_87 ( V_16 , V_96 ) ;
if ( V_94 )
F_38 ( V_9 ) ;
else
F_30 ( V_9 ) ;
if ( V_94 && V_95 )
F_88 ( V_7 , V_37 ) ;
else
F_89 ( V_7 , V_37 ) ;
F_90 ( V_16 , V_96 ) ;
return 0 ;
}
static int F_91 ( struct V_41 * V_14 , int V_97 )
{
return F_86 ( V_14 , V_97 , 0 ) ;
}
static int F_92 ( struct V_41 * V_14 )
{
return F_86 ( V_14 , 1 , 1 ) ;
}
static int F_93 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_1 * V_36 = F_26 ( V_7 ) ;
struct V_98 * V_99 = F_94 ( V_16 ) ;
struct V_10 * V_11 = F_95 ( V_16 ) ;
unsigned long V_96 ;
int V_53 = 0 ;
F_87 ( V_16 , V_96 ) ;
F_88 ( V_7 , V_5 ) ;
if ( ! ( F_29 ( V_7 , V_100 ) &&
F_29 ( V_7 , V_101 ) ) )
V_53 = - 1 ;
F_90 ( V_16 , V_96 ) ;
if ( V_53 < 0 )
return 0 ;
F_5 ( V_11 , L_17 ) ;
F_96 ( V_16 ,
F_22 ) ;
F_97 ( V_16 ) ;
F_63 ( V_7 ) ;
V_36 -> V_9 = F_98 ( V_16 ) ;
V_36 -> V_9 -> V_88 = V_36 ;
F_72 ( V_36 -> V_9 , 0 , 0 , 64 ) ;
F_99 ( V_16 , 1 ) ;
V_99 -> V_102 = F_55 ;
V_99 -> V_103 = F_58 ;
F_100 ( V_16 , V_99 ) ;
return 0 ;
}
static int F_101 ( struct V_15 * V_16 , T_2 V_5 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
struct V_98 * V_99 = F_94 ( V_16 ) ;
struct V_1 * V_36 = F_26 ( V_7 ) ;
struct V_10 * V_11 = F_95 ( V_16 ) ;
unsigned long V_96 ;
int V_53 = 0 ;
F_87 ( V_16 , V_96 ) ;
F_89 ( V_7 , V_5 ) ;
if ( ! F_29 ( V_7 , V_100 ) &&
! F_29 ( V_7 , V_101 ) )
V_53 = - 1 ;
F_90 ( V_16 , V_96 ) ;
if ( V_53 < 0 )
return 0 ;
F_102 ( V_16 ) ;
V_99 -> V_102 = NULL ;
V_99 -> V_103 = NULL ;
F_100 ( V_16 , V_99 ) ;
V_7 -> V_64 . V_65 = V_104 ;
F_36 ( V_16 , 0 ) ;
F_99 ( V_16 , 0 ) ;
F_61 ( V_36 ) ;
F_5 ( V_11 , L_18 ) ;
return 0 ;
}
static int F_103 ( struct V_105 * V_64 ,
struct V_106 * V_82 )
{
struct V_6 * V_7 = F_104 ( V_64 ) ;
struct V_15 * V_16 = F_67 ( V_7 ) ;
if ( ! V_82 ||
! V_82 -> V_83 ||
V_82 -> V_107 < V_108 )
return - V_55 ;
V_7 -> V_82 = V_82 ;
V_7 -> V_64 . V_11 . V_82 = & V_82 -> V_82 ;
return F_93 ( V_16 , V_101 ) ;
}
static int F_105 ( struct V_105 * V_64 ,
struct V_106 * V_82 )
{
struct V_6 * V_7 = F_104 ( V_64 ) ;
struct V_15 * V_16 = F_67 ( V_7 ) ;
if ( ! V_82 ||
! V_82 -> V_109 )
return - V_55 ;
F_101 ( V_16 , V_101 ) ;
V_7 -> V_64 . V_11 . V_82 = NULL ;
V_7 -> V_82 = NULL ;
return 0 ;
}
static int F_106 ( struct V_105 * V_64 )
{
struct V_6 * V_7 = F_104 ( V_64 ) ;
struct V_15 * V_16 = F_67 ( V_7 ) ;
return F_107 ( V_16 ) ;
}
static int F_108 ( struct V_15 * V_16 )
{
return F_93 ( V_16 , V_100 ) ;
}
static int F_109 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
if ( V_7 -> V_82 &&
V_7 -> V_82 -> V_110 )
V_7 -> V_82 -> V_110 ( & V_7 -> V_64 ) ;
return F_101 ( V_16 , V_100 ) ;
}
int F_110 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = F_95 ( V_16 ) ;
int V_111 = F_111 ( V_16 , V_111 ) ;
int V_85 ;
int V_53 ;
V_7 = F_77 ( sizeof( struct V_6 ) , V_112 ) ;
if ( ! V_7 ) {
F_15 ( V_11 , L_19 ) ;
return - V_113 ;
}
V_2 = F_77 ( sizeof( struct V_1 ) * V_111 , V_112 ) ;
if ( ! V_2 ) {
F_15 ( V_11 , L_20 ) ;
V_53 = - V_113 ;
goto V_114;
}
F_112 ( V_16 , & V_7 -> V_99 , V_115 ) ;
V_7 -> V_99 . V_61 = L_21 ;
V_7 -> V_99 . V_116 = F_108 ;
V_7 -> V_99 . V_117 = F_109 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_118 = V_111 ;
F_113 ( V_7 ) ;
F_114 ( & V_7 -> V_64 . V_11 , L_21 ) ;
V_7 -> V_64 . V_11 . V_119 = V_11 ;
V_7 -> V_64 . V_61 = L_22 ;
V_7 -> V_64 . V_120 = & V_121 ;
V_7 -> V_64 . V_107 = V_122 ;
V_53 = F_115 ( & V_7 -> V_64 . V_11 ) ;
if ( V_53 < 0 )
goto V_123;
F_116 ( & V_7 -> V_64 . V_124 ) ;
F_64 (uep, gpriv, i) {
V_2 -> V_7 = V_7 ;
snprintf ( V_2 -> V_125 , V_126 , L_23 , V_85 ) ;
V_2 -> V_14 . V_61 = V_2 -> V_125 ;
V_2 -> V_14 . V_120 = & V_127 ;
F_116 ( & V_2 -> V_14 . V_124 ) ;
if ( F_117 ( V_2 ) ) {
V_7 -> V_64 . V_128 = & V_2 -> V_14 ;
V_2 -> V_14 . V_129 = 64 ;
}
else {
V_2 -> V_14 . V_129 = 512 ;
F_118 ( & V_2 -> V_14 . V_124 , & V_7 -> V_64 . V_124 ) ;
}
}
V_53 = F_119 ( V_11 , & V_7 -> V_64 ) ;
if ( V_53 )
goto V_130;
F_120 ( V_11 , L_24 ) ;
return 0 ;
V_130:
F_121 ( & V_7 -> V_64 . V_11 ) ;
V_123:
F_41 ( V_7 -> V_2 ) ;
V_114:
F_41 ( V_7 ) ;
return V_53 ;
}
void F_122 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = F_25 ( V_16 ) ;
F_123 ( & V_7 -> V_64 ) ;
F_121 ( & V_7 -> V_64 . V_11 ) ;
F_41 ( V_7 -> V_2 ) ;
F_41 ( V_7 ) ;
}
