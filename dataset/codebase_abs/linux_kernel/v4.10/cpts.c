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
static int F_13 ( struct V_8 * V_8 , int V_23 )
{
int V_24 , type = - 1 ;
T_1 V_25 , V_26 ;
struct V_1 * V_2 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
if ( F_4 ( V_8 , & V_25 , & V_26 ) )
break;
if ( F_14 ( & V_8 -> V_22 ) && F_7 ( V_8 ) ) {
F_15 ( L_2 ) ;
return - 1 ;
}
V_2 = F_16 ( & V_8 -> V_22 , struct V_1 , V_21 ) ;
V_2 -> V_4 = V_3 + 2 ;
V_2 -> V_5 = V_25 ;
V_2 -> V_9 = V_26 ;
type = F_3 ( V_2 ) ;
switch ( type ) {
case V_28 :
case V_29 :
case V_30 :
F_10 ( & V_2 -> V_21 ) ;
F_17 ( & V_2 -> V_21 , & V_8 -> V_31 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
break;
default:
F_15 ( L_3 ) ;
break;
}
if ( type == V_23 )
break;
}
return type == V_23 ? 0 : - 1 ;
}
static T_2 F_18 ( const struct V_35 * V_36 )
{
T_2 V_37 = 0 ;
struct V_1 * V_2 ;
struct V_17 * V_18 , * V_19 ;
struct V_8 * V_8 = F_19 ( V_36 , struct V_8 , V_36 ) ;
F_6 ( V_8 , V_38 , V_39 ) ;
if ( F_13 ( V_8 , V_28 ) )
F_15 ( L_4 ) ;
F_8 (this, next, &cpts->events) {
V_2 = F_9 ( V_18 , struct V_1 , V_21 ) ;
if ( F_3 ( V_2 ) == V_28 ) {
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
V_37 = V_2 -> V_9 ;
break;
}
}
return V_37 ;
}
static int F_20 ( struct V_40 * V_41 , T_3 V_42 )
{
T_2 V_43 ;
T_1 V_44 , V_45 ;
int V_46 = 0 ;
unsigned long V_47 ;
struct V_8 * V_8 = F_19 ( V_41 , struct V_8 , V_48 ) ;
if ( V_42 < 0 ) {
V_46 = 1 ;
V_42 = - V_42 ;
}
V_45 = V_8 -> V_49 ;
V_43 = V_45 ;
V_43 *= V_42 ;
V_44 = F_21 ( V_43 , 1000000000ULL ) ;
F_22 ( & V_8 -> V_50 , V_47 ) ;
F_23 ( & V_8 -> V_51 ) ;
V_8 -> V_36 . V_45 = V_46 ? V_45 - V_44 : V_45 + V_44 ;
F_24 ( & V_8 -> V_50 , V_47 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 , T_4 V_52 )
{
unsigned long V_47 ;
struct V_8 * V_8 = F_19 ( V_41 , struct V_8 , V_48 ) ;
F_22 ( & V_8 -> V_50 , V_47 ) ;
F_26 ( & V_8 -> V_51 , V_52 ) ;
F_24 ( & V_8 -> V_50 , V_47 ) ;
return 0 ;
}
static int F_27 ( struct V_40 * V_41 , struct V_53 * V_54 )
{
T_2 V_55 ;
unsigned long V_47 ;
struct V_8 * V_8 = F_19 ( V_41 , struct V_8 , V_48 ) ;
F_22 ( & V_8 -> V_50 , V_47 ) ;
V_55 = F_23 ( & V_8 -> V_51 ) ;
F_24 ( & V_8 -> V_50 , V_47 ) ;
* V_54 = F_28 ( V_55 ) ;
return 0 ;
}
static int F_29 ( struct V_40 * V_41 ,
const struct V_53 * V_54 )
{
T_2 V_55 ;
unsigned long V_47 ;
struct V_8 * V_8 = F_19 ( V_41 , struct V_8 , V_48 ) ;
V_55 = F_30 ( V_54 ) ;
F_22 ( & V_8 -> V_50 , V_47 ) ;
F_31 ( & V_8 -> V_51 , & V_8 -> V_36 , V_55 ) ;
F_24 ( & V_8 -> V_50 , V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_40 * V_41 ,
struct V_56 * V_57 , int V_58 )
{
return - V_59 ;
}
static void F_33 ( struct V_60 * V_61 )
{
struct V_53 V_54 ;
struct V_8 * V_8 = F_19 ( V_61 , struct V_8 , V_62 . V_61 ) ;
F_27 ( & V_8 -> V_48 , & V_54 ) ;
F_12 ( L_5 , V_54 . V_63 , V_54 . V_64 ) ;
F_34 ( & V_8 -> V_62 , V_8 -> V_65 ) ;
}
static int F_35 ( struct V_66 * V_67 , unsigned int V_68 ,
T_5 V_69 , T_6 V_70 )
{
T_5 * V_71 ;
unsigned int V_72 = 0 ;
T_6 * V_73 , * V_74 = V_67 -> V_74 ;
if ( V_68 & V_75 )
V_72 += V_76 ;
switch ( V_68 & V_77 ) {
case V_78 :
V_72 += V_79 + F_36 ( V_74 + V_72 ) + V_80 ;
break;
case V_81 :
V_72 += V_79 + V_82 + V_80 ;
break;
case V_83 :
V_72 += V_79 ;
break;
default:
return 0 ;
}
if ( V_67 -> V_84 + V_79 < V_72 + V_85 + sizeof( * V_71 ) )
return 0 ;
if ( F_37 ( V_68 & V_86 ) )
V_73 = V_74 + V_72 + V_87 ;
else
V_73 = V_74 + V_72 ;
V_71 = ( T_5 * ) ( V_74 + V_72 + V_85 ) ;
return ( V_70 == ( * V_73 & 0xf ) && V_69 == F_38 ( * V_71 ) ) ;
}
static T_2 F_39 ( struct V_8 * V_8 , struct V_66 * V_67 , int V_88 )
{
T_2 V_55 = 0 ;
struct V_1 * V_2 ;
struct V_17 * V_18 , * V_19 ;
unsigned int V_89 = F_40 ( V_67 ) ;
unsigned long V_47 ;
T_5 V_71 ;
T_6 V_90 ;
if ( V_89 == V_91 )
return 0 ;
F_22 ( & V_8 -> V_50 , V_47 ) ;
F_13 ( V_8 , V_28 ) ;
F_8 (this, next, &cpts->events) {
V_2 = F_9 ( V_18 , struct V_1 , V_21 ) ;
if ( F_1 ( V_2 ) ) {
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
continue;
}
V_90 = ( V_2 -> V_5 >> V_92 ) & V_93 ;
V_71 = ( V_2 -> V_5 >> V_94 ) & V_95 ;
if ( V_88 == F_3 ( V_2 ) &&
F_35 ( V_67 , V_89 , V_71 , V_90 ) ) {
V_55 = F_41 ( & V_8 -> V_51 , V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_21 , & V_8 -> V_22 ) ;
break;
}
}
F_24 ( & V_8 -> V_50 , V_47 ) ;
return V_55 ;
}
void F_42 ( struct V_8 * V_8 , struct V_66 * V_67 )
{
T_2 V_55 ;
struct V_96 * V_97 ;
if ( ! V_8 -> V_98 )
return;
V_55 = F_39 ( V_8 , V_67 , V_29 ) ;
if ( ! V_55 )
return;
V_97 = F_43 ( V_67 ) ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_97 -> V_99 = F_44 ( V_55 ) ;
}
void F_45 ( struct V_8 * V_8 , struct V_66 * V_67 )
{
T_2 V_55 ;
struct V_96 V_97 ;
if ( ! ( F_46 ( V_67 ) -> V_100 & V_101 ) )
return;
V_55 = F_39 ( V_8 , V_67 , V_30 ) ;
if ( ! V_55 )
return;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_99 = F_44 ( V_55 ) ;
F_47 ( V_67 , & V_97 ) ;
}
int F_48 ( struct V_8 * V_8 )
{
int V_102 , V_24 ;
F_49 ( & V_8 -> V_31 ) ;
F_49 ( & V_8 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_103 ; V_24 ++ )
F_11 ( & V_8 -> V_104 [ V_24 ] . V_21 , & V_8 -> V_22 ) ;
F_50 ( V_8 -> V_105 ) ;
F_6 ( V_8 , V_106 , V_107 ) ;
F_6 ( V_8 , V_108 , V_109 ) ;
F_31 ( & V_8 -> V_51 , & V_8 -> V_36 , F_51 ( F_52 () ) ) ;
V_8 -> clock = F_53 ( & V_8 -> V_48 , V_8 -> V_110 ) ;
if ( F_54 ( V_8 -> clock ) ) {
V_102 = F_55 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
goto V_111;
}
V_8 -> V_112 = F_56 ( V_8 -> clock ) ;
F_34 ( & V_8 -> V_62 , V_8 -> V_65 ) ;
return 0 ;
V_111:
F_57 ( V_8 -> V_105 ) ;
return V_102 ;
}
void F_58 ( struct V_8 * V_8 )
{
if ( F_59 ( ! V_8 -> clock ) )
return;
F_60 ( & V_8 -> V_62 ) ;
F_61 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
F_6 ( V_8 , 0 , V_109 ) ;
F_6 ( V_8 , 0 , V_107 ) ;
F_57 ( V_8 -> V_105 ) ;
}
static void F_62 ( struct V_8 * V_8 )
{
T_2 V_113 , V_114 , V_55 ;
T_1 V_115 ;
V_115 = F_63 ( V_8 -> V_105 ) ;
V_114 = V_8 -> V_36 . V_116 ;
F_64 ( V_114 , V_115 ) ;
if ( V_114 > 10 )
V_114 = 10 ;
V_8 -> V_65 = ( V_117 * V_114 ) / 2 ;
F_65 ( V_8 -> V_110 , L_6 ,
V_8 -> V_65 ) ;
if ( V_8 -> V_36 . V_45 || V_8 -> V_36 . V_118 )
return;
F_66 ( & V_8 -> V_36 . V_45 , & V_8 -> V_36 . V_118 ,
V_115 , V_119 , V_114 ) ;
V_113 = 0 ;
V_55 = F_67 ( & V_8 -> V_36 , V_115 , V_8 -> V_36 . V_116 , & V_113 ) ;
F_65 ( V_8 -> V_110 ,
L_7 ,
V_115 , V_8 -> V_36 . V_45 , V_8 -> V_36 . V_118 , ( V_55 - V_119 ) ) ;
}
static int F_68 ( struct V_8 * V_8 , struct V_120 * V_121 )
{
int V_122 = - V_123 ;
T_1 V_124 ;
if ( ! F_69 ( V_121 , L_8 , & V_124 ) )
V_8 -> V_36 . V_45 = V_124 ;
if ( ! F_69 ( V_121 , L_9 , & V_124 ) )
V_8 -> V_36 . V_118 = V_124 ;
if ( ( V_8 -> V_36 . V_45 && ! V_8 -> V_36 . V_118 ) ||
( ! V_8 -> V_36 . V_45 && V_8 -> V_36 . V_118 ) )
goto V_125;
return 0 ;
V_125:
F_70 ( V_8 -> V_110 , L_10 ) ;
return V_122 ;
}
struct V_8 * F_71 ( struct V_126 * V_110 , void T_7 * V_127 ,
struct V_120 * V_121 )
{
struct V_8 * V_8 ;
int V_122 ;
V_8 = F_72 ( V_110 , sizeof( * V_8 ) , V_128 ) ;
if ( ! V_8 )
return F_73 ( - V_129 ) ;
V_8 -> V_110 = V_110 ;
V_8 -> V_130 = (struct V_131 T_7 * ) V_127 ;
F_74 ( & V_8 -> V_50 ) ;
F_75 ( & V_8 -> V_62 , F_33 ) ;
V_122 = F_68 ( V_8 , V_121 ) ;
if ( V_122 )
return F_73 ( V_122 ) ;
V_8 -> V_105 = F_76 ( V_110 , L_11 ) ;
if ( F_54 ( V_8 -> V_105 ) ) {
F_70 ( V_110 , L_12 ) ;
return F_73 ( F_55 ( V_8 -> V_105 ) ) ;
}
F_77 ( V_8 -> V_105 ) ;
V_8 -> V_36 . V_132 = F_18 ;
V_8 -> V_36 . V_116 = F_78 ( 32 ) ;
V_8 -> V_48 = V_133 ;
F_62 ( V_8 ) ;
V_8 -> V_49 = V_8 -> V_36 . V_45 ;
return V_8 ;
}
void F_79 ( struct V_8 * V_8 )
{
if ( ! V_8 )
return;
if ( F_59 ( ! V_8 -> V_105 ) )
return;
F_80 ( V_8 -> V_105 ) ;
}
