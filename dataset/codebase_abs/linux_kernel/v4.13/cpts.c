static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 >> V_6 ) & V_7 ;
}
static int F_4 ( struct V_8 * V_8 , T_1 * V_5 , T_1 * V_9 )
{
T_1 V_10 = F_5 ( V_8 , V_11 ) ;
if ( V_10 & V_12 ) {
* V_5 = F_5 ( V_8 , V_13 ) ;
* V_9 = F_5 ( V_8 , V_14 ) ;
F_6 ( V_8 , V_15 , V_16 ) ;
return 0 ;
}
return - 1 ;
}
static int F_7 ( struct V_8 * V_8 )
{
struct V_17 * V_18 , * V_19 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
F_8 (this, next, &cpts->events) {
V_2 = F_9 ( V_18 , struct V_1 , V_21 ) ;
if ( F_1 ( V_2 ) ) {
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
++ V_20 ;
}
}
if ( V_20 )
F_12 ( L_1 , V_20 ) ;
return V_20 ? 0 : - 1 ;
}
static bool F_13 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_25 ;
T_2 V_26 ;
T_3 V_27 ;
bool V_28 = false ;
V_27 = ( V_2 -> V_5 >> V_29 ) & V_30 ;
V_26 = ( V_2 -> V_5 >> V_31 ) & V_32 ;
F_14 (&cpts->txq, skb, tmp) {
struct V_33 V_34 ;
unsigned int V_35 = F_15 ( V_24 ) ;
struct V_36 * V_37 =
(struct V_36 * ) V_24 -> V_38 ;
if ( F_16 ( V_24 , V_35 , V_26 , V_27 ) ) {
T_4 V_39 = F_17 ( & V_8 -> V_40 , V_2 -> V_9 ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_41 = F_18 ( V_39 ) ;
F_19 ( V_24 , & V_34 ) ;
V_28 = true ;
F_20 ( V_24 , & V_8 -> V_42 ) ;
F_21 ( V_24 ) ;
F_22 ( V_8 -> V_43 , L_2 ,
V_27 , V_26 ) ;
} else if ( F_2 ( V_3 , V_37 -> V_4 ) ) {
F_22 ( V_8 -> V_43 ,
L_3 ,
V_27 , V_26 ) ;
F_20 ( V_24 , & V_8 -> V_42 ) ;
F_21 ( V_24 ) ;
}
}
return V_28 ;
}
static int F_23 ( struct V_8 * V_8 , int V_44 )
{
int V_45 , type = - 1 ;
T_1 V_46 , V_47 ;
struct V_1 * V_2 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
if ( F_4 ( V_8 , & V_46 , & V_47 ) )
break;
if ( F_24 ( & V_8 -> V_22 ) && F_7 ( V_8 ) ) {
F_25 ( L_4 ) ;
return - 1 ;
}
V_2 = F_26 ( & V_8 -> V_22 , struct V_1 , V_21 ) ;
V_2 -> V_4 = V_3 + 2 ;
V_2 -> V_5 = V_46 ;
V_2 -> V_9 = V_47 ;
type = F_3 ( V_2 ) ;
switch ( type ) {
case V_49 :
if ( F_13 ( V_8 , V_2 ) ) {
break;
}
case V_50 :
case V_51 :
F_10 ( & V_2 -> V_21 ) ;
F_27 ( & V_2 -> V_21 , & V_8 -> V_52 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
break;
default:
F_25 ( L_5 ) ;
break;
}
if ( type == V_44 )
break;
}
return type == V_44 ? 0 : - 1 ;
}
static T_4 F_28 ( const struct V_56 * V_57 )
{
T_4 V_58 = 0 ;
struct V_1 * V_2 ;
struct V_17 * V_18 , * V_19 ;
struct V_8 * V_8 = F_29 ( V_57 , struct V_8 , V_57 ) ;
F_6 ( V_8 , V_59 , V_60 ) ;
if ( F_23 ( V_8 , V_50 ) )
F_25 ( L_6 ) ;
F_8 (this, next, &cpts->events) {
V_2 = F_9 ( V_18 , struct V_1 , V_21 ) ;
if ( F_3 ( V_2 ) == V_50 ) {
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
V_58 = V_2 -> V_9 ;
break;
}
}
return V_58 ;
}
static int F_30 ( struct V_61 * V_62 , T_5 V_63 )
{
T_4 V_64 ;
T_1 V_65 , V_66 ;
int V_67 = 0 ;
unsigned long V_68 ;
struct V_8 * V_8 = F_29 ( V_62 , struct V_8 , V_69 ) ;
if ( V_63 < 0 ) {
V_67 = 1 ;
V_63 = - V_63 ;
}
V_66 = V_8 -> V_70 ;
V_64 = V_66 ;
V_64 *= V_63 ;
V_65 = F_31 ( V_64 , 1000000000ULL ) ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
F_33 ( & V_8 -> V_40 ) ;
V_8 -> V_57 . V_66 = V_67 ? V_66 - V_65 : V_66 + V_65 ;
F_34 ( & V_8 -> V_71 , V_68 ) ;
return 0 ;
}
static int F_35 ( struct V_61 * V_62 , T_6 V_72 )
{
unsigned long V_68 ;
struct V_8 * V_8 = F_29 ( V_62 , struct V_8 , V_69 ) ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
F_36 ( & V_8 -> V_40 , V_72 ) ;
F_34 ( & V_8 -> V_71 , V_68 ) ;
return 0 ;
}
static int F_37 ( struct V_61 * V_62 , struct V_73 * V_74 )
{
T_4 V_39 ;
unsigned long V_68 ;
struct V_8 * V_8 = F_29 ( V_62 , struct V_8 , V_69 ) ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
V_39 = F_33 ( & V_8 -> V_40 ) ;
F_34 ( & V_8 -> V_71 , V_68 ) ;
* V_74 = F_38 ( V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_61 * V_62 ,
const struct V_73 * V_74 )
{
T_4 V_39 ;
unsigned long V_68 ;
struct V_8 * V_8 = F_29 ( V_62 , struct V_8 , V_69 ) ;
V_39 = F_40 ( V_74 ) ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
F_41 ( & V_8 -> V_40 , & V_8 -> V_57 , V_39 ) ;
F_34 ( & V_8 -> V_71 , V_68 ) ;
return 0 ;
}
static int F_42 ( struct V_61 * V_62 ,
struct V_75 * V_76 , int V_77 )
{
return - V_78 ;
}
static long F_43 ( struct V_61 * V_62 )
{
struct V_8 * V_8 = F_29 ( V_62 , struct V_8 , V_69 ) ;
unsigned long V_79 = V_8 -> V_80 ;
struct V_73 V_74 ;
unsigned long V_68 ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
V_74 = F_38 ( F_33 ( & V_8 -> V_40 ) ) ;
if ( ! F_44 ( & V_8 -> V_42 ) )
V_79 = V_81 ;
F_34 ( & V_8 -> V_71 , V_68 ) ;
F_12 ( L_7 , V_74 . V_82 , V_74 . V_83 ) ;
return ( long ) V_79 ;
}
static int F_16 ( struct V_23 * V_24 , unsigned int V_84 ,
T_2 V_85 , T_3 V_86 )
{
T_2 * V_26 ;
unsigned int V_87 = 0 ;
T_3 * V_88 , * V_89 = V_24 -> V_89 ;
if ( V_84 & V_90 )
V_87 += V_91 ;
switch ( V_84 & V_92 ) {
case V_93 :
V_87 += V_94 + F_45 ( V_89 + V_87 ) + V_95 ;
break;
case V_96 :
V_87 += V_94 + V_97 + V_95 ;
break;
case V_98 :
V_87 += V_94 ;
break;
default:
return 0 ;
}
if ( V_24 -> V_99 + V_94 < V_87 + V_100 + sizeof( * V_26 ) )
return 0 ;
if ( F_46 ( V_84 & V_101 ) )
V_88 = V_89 + V_87 + V_102 ;
else
V_88 = V_89 + V_87 ;
V_26 = ( T_2 * ) ( V_89 + V_87 + V_100 ) ;
return ( V_86 == ( * V_88 & 0xf ) && V_85 == F_47 ( * V_26 ) ) ;
}
static T_4 F_48 ( struct V_8 * V_8 , struct V_23 * V_24 , int V_103 )
{
T_4 V_39 = 0 ;
struct V_1 * V_2 ;
struct V_17 * V_18 , * V_19 ;
unsigned int V_35 = F_15 ( V_24 ) ;
unsigned long V_68 ;
T_2 V_26 ;
T_3 V_27 ;
if ( V_35 == V_104 )
return 0 ;
F_32 ( & V_8 -> V_71 , V_68 ) ;
F_23 ( V_8 , - 1 ) ;
F_8 (this, next, &cpts->events) {
V_2 = F_9 ( V_18 , struct V_1 , V_21 ) ;
if ( F_1 ( V_2 ) ) {
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
continue;
}
V_27 = ( V_2 -> V_5 >> V_29 ) & V_30 ;
V_26 = ( V_2 -> V_5 >> V_31 ) & V_32 ;
if ( V_103 == F_3 ( V_2 ) &&
F_16 ( V_24 , V_35 , V_26 , V_27 ) ) {
V_39 = F_17 ( & V_8 -> V_40 , V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
break;
}
}
if ( V_103 == V_49 && ! V_39 ) {
struct V_36 * V_37 =
(struct V_36 * ) V_24 -> V_38 ;
F_49 ( V_24 ) ;
V_37 -> V_4 = V_3 + F_50 ( 100 ) ;
F_51 ( & V_8 -> V_42 , V_24 ) ;
F_52 ( V_8 -> clock , 0 ) ;
}
F_34 ( & V_8 -> V_71 , V_68 ) ;
return V_39 ;
}
void F_53 ( struct V_8 * V_8 , struct V_23 * V_24 )
{
T_4 V_39 ;
struct V_33 * V_34 ;
if ( ! V_8 -> V_105 )
return;
V_39 = F_48 ( V_8 , V_24 , V_51 ) ;
if ( ! V_39 )
return;
V_34 = F_54 ( V_24 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_41 = F_18 ( V_39 ) ;
}
void F_55 ( struct V_8 * V_8 , struct V_23 * V_24 )
{
T_4 V_39 ;
struct V_33 V_34 ;
if ( ! ( F_56 ( V_24 ) -> V_106 & V_107 ) )
return;
V_39 = F_48 ( V_8 , V_24 , V_49 ) ;
if ( ! V_39 )
return;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_41 = F_18 ( V_39 ) ;
F_19 ( V_24 , & V_34 ) ;
}
int F_57 ( struct V_8 * V_8 )
{
int V_108 , V_45 ;
F_58 ( & V_8 -> V_42 ) ;
F_59 ( & V_8 -> V_52 ) ;
F_59 ( & V_8 -> V_22 ) ;
for ( V_45 = 0 ; V_45 < V_109 ; V_45 ++ )
F_11 ( & V_8 -> V_110 [ V_45 ] . V_21 , & V_8 -> V_22 ) ;
F_60 ( V_8 -> V_111 ) ;
F_6 ( V_8 , V_112 , V_113 ) ;
F_6 ( V_8 , V_114 , V_115 ) ;
F_41 ( & V_8 -> V_40 , & V_8 -> V_57 , F_61 ( F_62 () ) ) ;
V_8 -> clock = F_63 ( & V_8 -> V_69 , V_8 -> V_43 ) ;
if ( F_64 ( V_8 -> clock ) ) {
V_108 = F_65 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
goto V_116;
}
V_8 -> V_117 = F_66 ( V_8 -> clock ) ;
F_52 ( V_8 -> clock , V_8 -> V_80 ) ;
return 0 ;
V_116:
F_67 ( V_8 -> V_111 ) ;
return V_108 ;
}
void F_68 ( struct V_8 * V_8 )
{
if ( F_69 ( ! V_8 -> clock ) )
return;
F_70 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
F_6 ( V_8 , 0 , V_115 ) ;
F_6 ( V_8 , 0 , V_113 ) ;
F_71 ( & V_8 -> V_42 ) ;
F_67 ( V_8 -> V_111 ) ;
}
static void F_72 ( struct V_8 * V_8 )
{
T_4 V_118 , V_119 , V_39 ;
T_1 V_120 ;
V_120 = F_73 ( V_8 -> V_111 ) ;
V_119 = V_8 -> V_57 . V_121 ;
F_74 ( V_119 , V_120 ) ;
if ( V_119 > 10 )
V_119 = 10 ;
V_8 -> V_80 = ( V_122 * V_119 ) / 2 ;
F_75 ( V_8 -> V_43 , L_8 ,
V_8 -> V_80 ) ;
if ( V_8 -> V_57 . V_66 || V_8 -> V_57 . V_123 )
return;
F_76 ( & V_8 -> V_57 . V_66 , & V_8 -> V_57 . V_123 ,
V_120 , V_124 , V_119 ) ;
V_118 = 0 ;
V_39 = F_77 ( & V_8 -> V_57 , V_120 , V_8 -> V_57 . V_121 , & V_118 ) ;
F_75 ( V_8 -> V_43 ,
L_9 ,
V_120 , V_8 -> V_57 . V_66 , V_8 -> V_57 . V_123 , ( V_39 - V_124 ) ) ;
}
static int F_78 ( struct V_8 * V_8 , struct V_125 * V_126 )
{
int V_127 = - V_128 ;
T_1 V_129 ;
if ( ! F_79 ( V_126 , L_10 , & V_129 ) )
V_8 -> V_57 . V_66 = V_129 ;
if ( ! F_79 ( V_126 , L_11 , & V_129 ) )
V_8 -> V_57 . V_123 = V_129 ;
if ( ( V_8 -> V_57 . V_66 && ! V_8 -> V_57 . V_123 ) ||
( ! V_8 -> V_57 . V_66 && V_8 -> V_57 . V_123 ) )
goto V_130;
return 0 ;
V_130:
F_80 ( V_8 -> V_43 , L_12 ) ;
return V_127 ;
}
struct V_8 * F_81 ( struct V_131 * V_43 , void T_7 * V_132 ,
struct V_125 * V_126 )
{
struct V_8 * V_8 ;
int V_127 ;
V_8 = F_82 ( V_43 , sizeof( * V_8 ) , V_133 ) ;
if ( ! V_8 )
return F_83 ( - V_134 ) ;
V_8 -> V_43 = V_43 ;
V_8 -> V_135 = (struct V_136 T_7 * ) V_132 ;
F_84 ( & V_8 -> V_71 ) ;
V_127 = F_78 ( V_8 , V_126 ) ;
if ( V_127 )
return F_83 ( V_127 ) ;
V_8 -> V_111 = F_85 ( V_43 , L_13 ) ;
if ( F_64 ( V_8 -> V_111 ) ) {
F_80 ( V_43 , L_14 ) ;
return F_83 ( F_65 ( V_8 -> V_111 ) ) ;
}
F_86 ( V_8 -> V_111 ) ;
V_8 -> V_57 . V_137 = F_28 ;
V_8 -> V_57 . V_121 = F_87 ( 32 ) ;
V_8 -> V_69 = V_138 ;
F_72 ( V_8 ) ;
V_8 -> V_70 = V_8 -> V_57 . V_66 ;
return V_8 ;
}
void F_88 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return;
if ( F_69 ( ! V_8 -> V_111 ) )
return;
F_89 ( V_8 -> V_111 ) ;
}
