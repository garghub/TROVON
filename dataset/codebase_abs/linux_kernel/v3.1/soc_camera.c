static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_5 ) {
V_6 = F_2 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 , L_1 ) ;
return V_6 ;
}
if ( V_4 -> V_10 )
V_6 = V_4 -> V_10 ( V_2 -> V_9 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 ,
L_2 ) ;
F_4 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
return V_6 ;
}
} else {
V_6 = 0 ;
if ( V_4 -> V_10 )
V_6 = V_4 -> V_10 ( V_2 -> V_9 , 0 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 ,
L_3 ) ;
return V_6 ;
}
V_6 = F_4 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 , L_4 ) ;
return V_6 ;
}
}
return 0 ;
}
const struct V_11 * F_5 (
struct V_1 * V_2 , unsigned int V_12 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ )
if ( V_2 -> V_15 [ V_13 ] . V_16 -> V_12 == V_12 )
return V_2 -> V_15 + V_13 ;
return NULL ;
}
unsigned long F_6 ( struct V_3 * V_4 ,
unsigned long V_17 )
{
unsigned long V_18 ;
if ( V_4 -> V_17 & V_19 ) {
V_18 = V_17 & ( V_20 | V_21 ) ;
if ( V_18 == V_20 || V_18 == V_21 )
V_17 ^= V_20 | V_21 ;
}
if ( V_4 -> V_17 & V_22 ) {
V_18 = V_17 & ( V_23 | V_24 ) ;
if ( V_18 == V_23 || V_18 == V_24 )
V_17 ^= V_23 | V_24 ;
}
if ( V_4 -> V_17 & V_25 ) {
V_18 = V_17 & ( V_26 | V_27 ) ;
if ( V_18 == V_26 || V_18 == V_27 )
V_17 ^= V_26 | V_27 ;
}
return V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_28 * V_18 )
{
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_32 * V_33 = & V_18 -> V_34 . V_33 ;
int V_6 ;
F_9 ( V_2 -> V_9 , L_5 ,
F_10 ( V_33 -> V_35 ) , V_33 -> V_36 , V_33 -> V_37 ) ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_6 = V_30 -> V_40 -> V_41 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_33 -> V_39 ) {
if ( ! V_33 -> V_38 ) {
const struct V_11 * V_42 ;
V_42 = F_5 ( V_2 , V_33 -> V_35 ) ;
if ( ! V_42 )
return - V_43 ;
V_6 = F_11 ( V_33 -> V_36 ,
V_42 -> V_16 ) ;
if ( V_6 > 0 )
V_33 -> V_38 = V_6 ;
}
if ( V_33 -> V_38 )
V_33 -> V_39 = V_33 -> V_38 * V_33 -> V_37 ;
}
return 0 ;
}
static int F_12 ( struct V_44 * V_44 , void * V_45 ,
struct V_28 * V_18 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_18 -> type != V_47 )
return - V_43 ;
return F_7 ( V_2 , V_18 ) ;
}
static int F_14 ( struct V_44 * V_44 , void * V_45 ,
struct V_48 * V_49 )
{
if ( V_49 -> V_50 != 0 )
return - V_43 ;
V_49 -> type = V_51 ;
V_49 -> V_52 = V_53 ;
strcpy ( V_49 -> V_54 , L_6 ) ;
return 0 ;
}
static int F_15 ( struct V_44 * V_44 , void * V_45 , unsigned int * V_13 )
{
* V_13 = 0 ;
return 0 ;
}
static int F_16 ( struct V_44 * V_44 , void * V_45 , unsigned int V_13 )
{
if ( V_13 > 0 )
return - V_43 ;
return 0 ;
}
static int F_17 ( struct V_44 * V_44 , void * V_45 , T_1 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_58 , V_59 , * V_55 ) ;
}
static int F_20 ( struct V_44 * V_44 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
return V_30 -> V_40 -> V_63 ( V_2 , V_62 ) ;
}
static int F_21 ( struct V_44 * V_44 , void * V_45 ,
struct V_64 * V_65 )
{
int V_6 ;
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_2 -> V_66 && V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 ) {
V_6 = F_22 ( & V_2 -> V_69 , V_65 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = V_30 -> V_40 -> V_70 ( V_2 , V_65 ) ;
} else {
V_6 = F_23 ( & V_2 -> V_71 , V_65 ) ;
}
if ( ! V_6 && ! V_2 -> V_66 )
V_2 -> V_66 = V_44 ;
return V_6 ;
}
static int F_24 ( struct V_44 * V_44 , void * V_45 ,
struct V_72 * V_65 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_30 -> V_40 -> V_68 )
return F_25 ( & V_2 -> V_69 , V_65 ) ;
else
return F_26 ( & V_2 -> V_71 , V_65 ) ;
}
static int F_27 ( struct V_44 * V_44 , void * V_45 ,
struct V_72 * V_65 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 )
return F_28 ( & V_2 -> V_69 , V_65 ) ;
else
return F_29 ( & V_2 -> V_71 , V_65 ) ;
}
static int F_30 ( struct V_44 * V_44 , void * V_45 ,
struct V_72 * V_65 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 )
return F_31 ( & V_2 -> V_69 , V_65 , V_44 -> V_73 & V_74 ) ;
else
return F_32 ( & V_2 -> V_71 , V_65 , V_44 -> V_73 & V_74 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
unsigned int V_13 , V_75 = 0 , V_76 = 0 ;
int V_6 ;
enum V_77 V_78 ;
while ( ! F_19 ( V_57 , V_79 , V_80 , V_76 , & V_78 ) )
V_76 ++ ;
if ( ! V_30 -> V_40 -> V_81 )
V_75 = V_76 ;
else
for ( V_13 = 0 ; V_13 < V_76 ; V_13 ++ ) {
V_6 = V_30 -> V_40 -> V_81 ( V_2 , V_13 , NULL ) ;
if ( V_6 < 0 )
return V_6 ;
V_75 += V_6 ;
}
if ( ! V_75 )
return - V_82 ;
V_2 -> V_15 =
F_34 ( V_75 * sizeof( struct V_11 ) ) ;
if ( ! V_2 -> V_15 )
return - V_83 ;
F_9 ( V_2 -> V_9 , L_7 , V_75 ) ;
V_75 = 0 ;
for ( V_13 = 0 ; V_13 < V_76 ; V_13 ++ )
if ( ! V_30 -> V_40 -> V_81 ) {
F_19 ( V_57 , V_79 , V_80 , V_13 , & V_78 ) ;
V_2 -> V_15 [ V_75 ] . V_16 =
F_35 ( V_78 ) ;
if ( V_2 -> V_15 [ V_75 ] . V_16 )
V_2 -> V_15 [ V_75 ++ ] . V_78 = V_78 ;
} else {
V_6 = V_30 -> V_40 -> V_81 ( V_2 , V_13 ,
& V_2 -> V_15 [ V_75 ] ) ;
if ( V_6 < 0 )
goto V_84;
V_75 += V_6 ;
}
V_2 -> V_14 = V_75 ;
V_2 -> V_85 = & V_2 -> V_15 [ 0 ] ;
return 0 ;
V_84:
F_36 ( V_2 -> V_15 ) ;
return V_6 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
if ( V_30 -> V_40 -> V_86 )
V_30 -> V_40 -> V_86 ( V_2 ) ;
V_2 -> V_85 = NULL ;
V_2 -> V_14 = 0 ;
F_36 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_28 * V_18 )
{
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_32 * V_33 = & V_18 -> V_34 . V_33 ;
int V_6 ;
F_9 ( V_2 -> V_9 , L_8 ,
F_10 ( V_33 -> V_35 ) , V_33 -> V_36 , V_33 -> V_37 ) ;
V_6 = F_7 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = V_30 -> V_40 -> V_87 ( V_2 , V_18 ) ;
if ( V_6 < 0 ) {
return V_6 ;
} else if ( ! V_2 -> V_85 ||
V_2 -> V_85 -> V_16 -> V_12 != V_33 -> V_35 ) {
F_3 ( V_2 -> V_9 ,
L_9 ) ;
return - V_43 ;
}
V_2 -> V_88 = V_33 -> V_36 ;
V_2 -> V_89 = V_33 -> V_37 ;
V_2 -> V_38 = V_33 -> V_38 ;
V_2 -> V_39 = V_33 -> V_39 ;
V_2 -> V_90 = V_33 -> V_90 ;
V_2 -> V_91 = V_33 -> V_91 ;
if ( V_30 -> V_40 -> V_68 )
V_2 -> V_69 . V_91 = V_33 -> V_91 ;
F_9 ( V_2 -> V_9 , L_10 ,
V_2 -> V_88 , V_2 -> V_89 ) ;
return V_30 -> V_40 -> V_92 ( V_2 , V_33 -> V_35 ) ;
}
static int F_39 ( struct V_44 * V_44 )
{
struct V_93 * V_94 = F_40 ( V_44 ) ;
struct V_1 * V_2 = F_41 ( V_94 -> V_31 ) ;
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_29 * V_30 ;
int V_6 ;
if ( ! V_2 -> V_40 )
return - V_95 ;
V_30 = F_8 ( V_2 -> V_31 ) ;
if ( ! F_43 ( V_30 -> V_40 -> V_96 ) ) {
F_3 ( V_2 -> V_9 , L_11 ) ;
return - V_43 ;
}
V_2 -> V_97 ++ ;
if ( V_2 -> V_97 == 1 ) {
struct V_28 V_18 = {
. type = V_47 ,
. V_34 . V_33 = {
. V_36 = V_2 -> V_88 ,
. V_37 = V_2 -> V_89 ,
. V_91 = V_2 -> V_91 ,
. V_90 = V_2 -> V_90 ,
. V_35 =
V_2 -> V_85 -> V_16 -> V_12 ,
} ,
} ;
V_6 = F_1 ( V_2 , V_4 , 1 ) ;
if ( V_6 < 0 )
goto V_98;
if ( V_4 -> V_99 )
V_4 -> V_99 ( V_2 -> V_9 ) ;
V_6 = V_30 -> V_40 -> V_100 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 , L_12 , V_6 ) ;
goto V_101;
}
F_44 ( & V_2 -> V_94 -> V_102 ) ;
V_6 = F_45 ( & V_2 -> V_94 -> V_102 ) ;
if ( V_6 < 0 && V_6 != - V_103 )
goto V_104;
V_6 = F_38 ( V_2 , & V_18 ) ;
if ( V_6 < 0 )
goto V_105;
if ( V_30 -> V_40 -> V_68 ) {
V_30 -> V_40 -> V_68 ( & V_2 -> V_69 , V_2 ) ;
} else {
V_6 = V_30 -> V_40 -> V_106 ( & V_2 -> V_71 , V_2 ) ;
if ( V_6 < 0 )
goto V_107;
}
}
V_44 -> V_46 = V_2 ;
F_9 ( V_2 -> V_9 , L_13 ) ;
return 0 ;
V_107:
V_105:
F_46 ( & V_2 -> V_94 -> V_102 ) ;
V_104:
V_30 -> V_40 -> remove ( V_2 ) ;
V_101:
F_1 ( V_2 , V_4 , 0 ) ;
V_98:
V_2 -> V_97 -- ;
F_47 ( V_30 -> V_40 -> V_96 ) ;
return V_6 ;
}
static int F_48 ( struct V_44 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
V_2 -> V_97 -- ;
if ( ! V_2 -> V_97 ) {
struct V_3 * V_4 = F_42 ( V_2 ) ;
F_49 ( & V_2 -> V_94 -> V_102 ) ;
F_46 ( & V_2 -> V_94 -> V_102 ) ;
V_30 -> V_40 -> remove ( V_2 ) ;
if ( V_30 -> V_40 -> V_106 )
F_50 ( & V_2 -> V_71 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
}
if ( V_2 -> V_66 == V_44 )
V_2 -> V_66 = NULL ;
F_47 ( V_30 -> V_40 -> V_96 ) ;
F_9 ( V_2 -> V_9 , L_14 ) ;
return 0 ;
}
static T_2 F_51 ( struct V_44 * V_44 , char T_3 * V_108 ,
T_4 V_109 , T_5 * V_110 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
int V_111 = - V_43 ;
F_3 ( V_2 -> V_9 , L_15 ) ;
return V_111 ;
}
static int F_52 ( struct V_44 * V_44 , struct V_112 * V_113 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
int V_111 ;
F_9 ( V_2 -> V_9 , L_16 , ( unsigned long ) V_113 ) ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 )
V_111 = F_53 ( & V_2 -> V_69 , V_113 ) ;
else
V_111 = F_54 ( & V_2 -> V_71 , V_113 ) ;
F_9 ( V_2 -> V_9 , L_17 ,
( unsigned long ) V_113 -> V_114 ,
( unsigned long ) V_113 -> V_115 - ( unsigned long ) V_113 -> V_114 ,
V_111 ) ;
return V_111 ;
}
static unsigned int F_55 ( struct V_44 * V_44 , T_6 * V_116 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 && F_56 ( & V_2 -> V_69 . V_117 ) ) {
F_3 ( V_2 -> V_9 , L_18 ) ;
return V_118 ;
}
return V_30 -> V_40 -> V_119 ( V_44 , V_116 ) ;
}
void F_57 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_58 ( V_121 ) ;
F_59 ( & V_2 -> V_122 ) ;
}
void F_60 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_58 ( V_121 ) ;
F_61 ( & V_2 -> V_122 ) ;
}
static int F_62 ( struct V_44 * V_44 , void * V_45 ,
struct V_28 * V_18 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
int V_6 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_18 -> type != V_47 ) {
F_63 ( V_2 -> V_9 , L_19 , V_18 -> type ) ;
return - V_43 ;
}
if ( V_2 -> V_66 && V_2 -> V_66 != V_44 )
return - V_67 ;
if ( F_64 ( F_8 ( V_2 -> V_31 ) , V_2 ) ) {
F_3 ( V_2 -> V_9 , L_20 ) ;
return - V_67 ;
}
V_6 = F_38 ( V_2 , V_18 ) ;
if ( ! V_6 && ! V_2 -> V_66 )
V_2 -> V_66 = V_44 ;
return V_6 ;
}
static int F_65 ( struct V_44 * V_44 , void * V_45 ,
struct V_123 * V_18 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
const struct V_124 * V_125 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_18 -> V_50 >= V_2 -> V_14 )
return - V_43 ;
V_125 = V_2 -> V_15 [ V_18 -> V_50 ] . V_16 ;
if ( V_125 -> V_54 )
F_66 ( V_18 -> V_126 , V_125 -> V_54 , sizeof( V_18 -> V_126 ) ) ;
V_18 -> V_35 = V_125 -> V_12 ;
return 0 ;
}
static int F_67 ( struct V_44 * V_44 , void * V_45 ,
struct V_28 * V_18 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_33 = & V_18 -> V_34 . V_33 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_18 -> type != V_47 )
return - V_43 ;
V_33 -> V_36 = V_2 -> V_88 ;
V_33 -> V_37 = V_2 -> V_89 ;
V_33 -> V_38 = V_2 -> V_38 ;
V_33 -> V_39 = V_2 -> V_39 ;
V_33 -> V_91 = V_2 -> V_91 ;
V_33 -> V_35 = V_2 -> V_85 -> V_16 -> V_12 ;
V_33 -> V_90 = V_2 -> V_90 ;
F_9 ( V_2 -> V_9 , L_21 ,
V_2 -> V_85 -> V_16 -> V_12 ) ;
return 0 ;
}
static int F_68 ( struct V_44 * V_44 , void * V_45 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
F_66 ( V_128 -> V_129 , V_30 -> V_130 , sizeof( V_128 -> V_129 ) ) ;
return V_30 -> V_40 -> V_131 ( V_30 , V_128 ) ;
}
static int F_69 ( struct V_44 * V_44 , void * V_45 ,
enum V_132 V_13 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_13 != V_47 )
return - V_43 ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 )
V_6 = F_70 ( & V_2 -> V_69 ) ;
else
V_6 = F_71 ( & V_2 -> V_71 , V_13 ) ;
if ( ! V_6 )
F_19 ( V_57 , V_79 , V_133 , 1 ) ;
return V_6 ;
}
static int F_72 ( struct V_44 * V_44 , void * V_45 ,
enum V_132 V_13 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_13 != V_47 )
return - V_43 ;
if ( V_2 -> V_66 != V_44 )
return - V_67 ;
if ( V_30 -> V_40 -> V_68 )
F_73 ( & V_2 -> V_69 ) ;
else
F_74 ( & V_2 -> V_71 , V_13 ) ;
F_19 ( V_57 , V_79 , V_133 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_44 * V_44 , void * V_45 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
int V_13 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( ! V_135 -> V_136 )
return - V_43 ;
for ( V_13 = 0 ; V_13 < V_30 -> V_40 -> V_137 ; V_13 ++ )
if ( V_135 -> V_136 == V_30 -> V_40 -> V_138 [ V_13 ] . V_136 ) {
memcpy ( V_135 , & ( V_30 -> V_40 -> V_138 [ V_13 ] ) ,
sizeof( * V_135 ) ) ;
return 0 ;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_40 -> V_137 ; V_13 ++ )
if ( V_135 -> V_136 == V_2 -> V_40 -> V_138 [ V_13 ] . V_136 ) {
memcpy ( V_135 , & ( V_2 -> V_40 -> V_138 [ V_13 ] ) ,
sizeof( * V_135 ) ) ;
return 0 ;
}
return - V_43 ;
}
static int F_76 ( struct V_44 * V_44 , void * V_45 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_30 -> V_40 -> V_141 ) {
V_6 = V_30 -> V_40 -> V_141 ( V_2 , V_140 ) ;
if ( V_6 != - V_142 )
return V_6 ;
}
return F_19 ( V_57 , V_58 , V_143 , V_140 ) ;
}
static int F_77 ( struct V_44 * V_44 , void * V_45 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_45 != V_44 -> V_46 ) ;
if ( V_30 -> V_40 -> V_144 ) {
V_6 = V_30 -> V_40 -> V_144 ( V_2 , V_140 ) ;
if ( V_6 != - V_142 )
return V_6 ;
}
return F_19 ( V_57 , V_58 , V_145 , V_140 ) ;
}
static int F_78 ( struct V_44 * V_44 , void * V_60 ,
struct V_146 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
return V_30 -> V_40 -> V_147 ( V_2 , V_55 ) ;
}
static int F_79 ( struct V_44 * V_44 , void * V_60 ,
struct V_148 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
int V_6 ;
V_6 = V_30 -> V_40 -> V_149 ( V_2 , V_55 ) ;
return V_6 ;
}
static int F_80 ( struct V_44 * V_44 , void * V_60 ,
struct V_148 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_150 * V_151 = & V_55 -> V_152 ;
struct V_148 V_153 ;
int V_6 ;
if ( V_55 -> type != V_47 )
return - V_43 ;
F_9 ( V_2 -> V_9 , L_22 ,
V_151 -> V_36 , V_151 -> V_37 , V_151 -> V_154 , V_151 -> V_155 ) ;
V_6 = V_30 -> V_40 -> V_149 ( V_2 , & V_153 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 ,
L_23 ) ;
} else if ( ( V_55 -> V_152 . V_36 == V_153 . V_152 . V_36 &&
V_55 -> V_152 . V_37 == V_153 . V_152 . V_37 ) ||
! F_64 ( V_30 , V_2 ) ) {
V_6 = V_30 -> V_40 -> V_156 ( V_2 , V_55 ) ;
} else if ( V_30 -> V_40 -> V_157 ) {
V_6 = V_30 -> V_40 -> V_157 ( V_2 , V_55 ) ;
} else {
F_3 ( V_2 -> V_9 ,
L_24 ) ;
V_6 = - V_67 ;
}
return V_6 ;
}
static int F_81 ( struct V_44 * V_44 , void * V_60 ,
struct V_158 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
if ( V_30 -> V_40 -> V_159 )
return V_30 -> V_40 -> V_159 ( V_2 , V_55 ) ;
return - V_142 ;
}
static int F_82 ( struct V_44 * V_44 , void * V_60 ,
struct V_158 * V_55 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
if ( V_30 -> V_40 -> V_160 )
return V_30 -> V_40 -> V_160 ( V_2 , V_55 ) ;
return - V_142 ;
}
static int F_83 ( struct V_44 * V_44 , void * V_60 ,
struct V_161 * V_136 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_58 , V_162 , V_136 ) ;
}
static int F_84 ( struct V_44 * V_44 , void * V_60 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_58 , V_165 , V_164 ) ;
}
static int F_85 ( struct V_44 * V_44 , void * V_60 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_58 , V_166 , V_164 ) ;
}
static void F_86 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
F_59 ( & V_167 ) ;
F_87 (icd, &devices, list) {
if ( V_2 -> V_168 == V_30 -> V_169 ) {
int V_6 ;
V_2 -> V_31 = V_30 -> V_170 . V_102 ;
V_6 = F_88 ( V_2 ) ;
}
}
F_61 ( & V_167 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_171 * V_172 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_173 * V_174 = F_90 ( V_4 -> V_175 ) ;
struct V_56 * V_176 ;
if ( ! V_174 ) {
F_3 ( V_2 -> V_9 , L_25 ,
V_4 -> V_175 ) ;
goto V_177;
}
V_4 -> V_178 -> V_179 = V_2 ;
V_176 = F_91 ( & V_30 -> V_170 , V_174 ,
V_4 -> V_178 , NULL ) ;
if ( ! V_176 )
goto V_180;
V_172 = F_92 ( V_176 ) ;
V_2 -> V_181 = & V_172 -> V_102 ;
return 0 ;
V_180:
F_93 ( V_174 ) ;
V_177:
return - V_95 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_171 * V_172 =
F_95 ( F_96 ( V_2 ) ) ;
struct V_173 * V_174 = V_172 -> V_182 ;
V_2 -> V_181 = NULL ;
F_97 ( F_98 ( V_172 ) ) ;
F_99 ( V_172 ) ;
F_93 ( V_174 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_183 * V_181 = NULL ;
struct V_56 * V_57 ;
struct V_184 V_185 ;
int V_6 ;
F_100 ( V_2 -> V_9 , L_26 , F_101 ( V_2 -> V_9 ) ) ;
V_6 = F_102 ( V_2 -> V_9 , V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 )
goto V_186;
V_6 = F_1 ( V_2 , V_4 , 1 ) ;
if ( V_6 < 0 )
goto V_98;
if ( V_4 -> V_99 )
V_4 -> V_99 ( V_2 -> V_9 ) ;
V_6 = V_30 -> V_40 -> V_100 ( V_2 ) ;
if ( V_6 < 0 )
goto V_187;
V_6 = F_103 ( V_2 ) ;
if ( V_6 < 0 )
goto V_188;
if ( V_4 -> V_178 ) {
V_6 = F_89 ( V_2 , V_4 ) ;
if ( V_6 < 0 )
goto V_189;
} else if ( ! V_4 -> V_190 || ! V_4 -> V_191 ) {
V_6 = - V_43 ;
goto V_189;
} else {
if ( V_4 -> V_192 )
V_6 = F_104 ( V_4 -> V_192 ) ;
V_6 = V_4 -> V_190 ( V_2 ) ;
if ( V_6 < 0 )
goto V_189;
V_181 = F_96 ( V_2 ) ;
if ( ! V_181 || ! V_181 -> V_129 || ! F_41 ( V_181 ) ||
! F_43 ( V_181 -> V_129 -> V_96 ) ) {
V_4 -> V_191 ( V_2 ) ;
goto V_193;
}
}
V_57 = F_18 ( V_2 ) ;
V_57 -> V_194 = ( long ) V_2 ;
V_6 = F_33 ( V_2 ) ;
if ( V_6 < 0 )
goto V_195;
V_2 -> V_91 = V_196 ;
F_59 ( & V_2 -> V_122 ) ;
V_6 = F_105 ( V_2 ) ;
if ( V_6 < 0 )
goto V_197;
if ( ! F_19 ( V_57 , V_79 , V_198 , & V_185 ) ) {
V_2 -> V_88 = V_185 . V_36 ;
V_2 -> V_89 = V_185 . V_37 ;
V_2 -> V_90 = V_185 . V_90 ;
V_2 -> V_91 = V_185 . V_91 ;
}
V_30 -> V_40 -> remove ( V_2 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_61 ( & V_2 -> V_122 ) ;
return 0 ;
V_197:
F_61 ( & V_2 -> V_122 ) ;
F_37 ( V_2 ) ;
V_195:
if ( V_4 -> V_178 ) {
F_94 ( V_2 ) ;
} else {
V_4 -> V_191 ( V_2 ) ;
F_47 ( V_181 -> V_129 -> V_96 ) ;
}
V_193:
V_189:
F_106 ( V_2 -> V_94 ) ;
V_188:
V_30 -> V_40 -> remove ( V_2 ) ;
V_187:
F_1 ( V_2 , V_4 , 0 ) ;
V_98:
F_107 ( V_4 -> V_7 , V_4 -> V_8 ) ;
V_186:
return V_6 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_93 * V_94 = V_2 -> V_94 ;
F_109 ( ! V_2 -> V_31 ) ;
if ( V_94 ) {
F_110 ( V_94 ) ;
V_2 -> V_94 = NULL ;
}
if ( V_4 -> V_178 ) {
F_94 ( V_2 ) ;
} else {
struct V_199 * V_200 = F_96 ( V_2 ) -> V_129 ;
if ( V_200 ) {
V_4 -> V_191 ( V_2 ) ;
F_47 ( V_200 -> V_96 ) ;
}
}
F_37 ( V_2 ) ;
F_107 ( V_4 -> V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_146 * V_55 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_79 , V_147 , V_55 ) ;
}
static int F_112 ( struct V_1 * V_2 , struct V_148 * V_55 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_79 , V_201 , V_55 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_148 * V_55 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_79 , V_202 , V_55 ) ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_158 * V_203 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_79 , V_204 , V_203 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_158 * V_203 )
{
struct V_56 * V_57 = F_18 ( V_2 ) ;
return F_19 ( V_57 , V_79 , V_205 , V_203 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
int V_6 ;
struct V_56 * V_57 = F_18 ( V_2 ) ;
const struct V_11 * V_42 ;
T_7 V_206 = V_62 -> V_207 ;
struct V_61 V_208 = * V_62 ;
V_42 = F_5 ( V_2 , V_206 ) ;
if ( ! V_42 )
return - V_43 ;
V_208 . V_207 = V_42 -> V_78 ;
V_6 = F_19 ( V_57 , V_79 , V_209 , & V_208 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_62 = V_208 ;
V_62 -> V_207 = V_206 ;
return 0 ;
}
int F_117 ( struct V_29 * V_30 )
{
struct V_29 * V_210 ;
int V_6 ;
if ( ! V_30 || ! V_30 -> V_40 ||
! V_30 -> V_40 -> V_41 ||
! V_30 -> V_40 -> V_87 ||
! V_30 -> V_40 -> V_92 ||
! V_30 -> V_40 -> V_131 ||
( ( ! V_30 -> V_40 -> V_68 ||
! V_30 -> V_40 -> V_70 ) &&
! V_30 -> V_40 -> V_106 ) ||
! V_30 -> V_40 -> V_100 ||
! V_30 -> V_40 -> remove ||
! V_30 -> V_40 -> V_119 ||
! V_30 -> V_170 . V_102 )
return - V_43 ;
if ( ! V_30 -> V_40 -> V_156 )
V_30 -> V_40 -> V_156 = F_113 ;
if ( ! V_30 -> V_40 -> V_149 )
V_30 -> V_40 -> V_149 = F_112 ;
if ( ! V_30 -> V_40 -> V_147 )
V_30 -> V_40 -> V_147 = F_111 ;
if ( ! V_30 -> V_40 -> V_160 )
V_30 -> V_40 -> V_160 = F_115 ;
if ( ! V_30 -> V_40 -> V_159 )
V_30 -> V_40 -> V_159 = F_114 ;
if ( ! V_30 -> V_40 -> V_63 )
V_30 -> V_40 -> V_63 = F_116 ;
F_59 ( & V_167 ) ;
F_87 (ix, &hosts, list) {
if ( V_210 -> V_169 == V_30 -> V_169 ) {
V_6 = - V_67 ;
goto V_211;
}
}
V_6 = F_118 ( V_30 -> V_170 . V_102 , & V_30 -> V_170 ) ;
if ( V_6 < 0 )
goto V_211;
F_119 ( & V_30 -> V_212 , & V_213 ) ;
F_61 ( & V_167 ) ;
F_86 ( V_30 ) ;
return 0 ;
V_211:
F_61 ( & V_167 ) ;
return V_6 ;
}
void F_120 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
F_59 ( & V_167 ) ;
F_121 ( & V_30 -> V_212 ) ;
F_87 (icd, &devices, list)
if ( V_2 -> V_168 == V_30 -> V_169 && F_96 ( V_2 ) )
F_108 ( V_2 ) ;
F_61 ( & V_167 ) ;
F_122 ( & V_30 -> V_170 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_1 * V_210 ;
int V_214 = - 1 , V_13 ;
for ( V_13 = 0 ; V_13 < 256 && V_214 < 0 ; V_13 ++ ) {
V_214 = V_13 ;
F_87 (ix, &devices, list) {
if ( V_210 -> V_168 == V_2 -> V_168 && V_210 -> V_215 == V_13 ) {
V_214 = - 1 ;
break;
}
}
}
if ( V_214 < 0 )
return - V_83 ;
V_2 -> V_215 = V_214 ;
V_2 -> V_97 = 0 ;
V_2 -> V_216 = NULL ;
F_124 ( & V_2 -> V_122 ) ;
F_119 ( & V_2 -> V_212 , & V_217 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 -> V_31 ) ;
struct V_93 * V_94 = F_125 () ;
if ( ! V_94 )
return - V_83 ;
F_66 ( V_94 -> V_54 , V_30 -> V_130 , sizeof( V_94 -> V_54 ) ) ;
V_94 -> V_31 = V_2 -> V_9 ;
V_94 -> V_218 = V_53 ;
V_94 -> V_219 = & V_220 ;
V_94 -> V_221 = & V_222 ;
V_94 -> V_223 = F_106 ;
V_94 -> V_224 = V_53 ;
V_94 -> V_225 = & V_2 -> V_122 ;
V_2 -> V_94 = V_94 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
const struct V_226 * type = V_2 -> V_94 -> V_102 . type ;
int V_6 ;
if ( ! V_2 -> V_31 )
return - V_95 ;
if ( ! V_2 -> V_40 ||
! V_2 -> V_40 -> V_227 ||
! V_2 -> V_40 -> V_92 )
return - V_43 ;
V_6 = F_126 ( V_2 -> V_94 , V_228 , - 1 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_9 , L_27 , V_6 ) ;
return V_6 ;
}
V_2 -> V_94 -> V_102 . type = type ;
return 0 ;
}
static int T_8 F_127 ( struct V_229 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_102 . V_179 ;
struct V_1 * V_2 ;
int V_6 ;
if ( ! V_4 )
return - V_43 ;
V_2 = F_128 ( sizeof( * V_2 ) , V_230 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_168 = V_4 -> V_231 ;
V_2 -> V_232 = V_4 ;
V_2 -> V_9 = & V_9 -> V_102 ;
F_129 ( V_9 , V_2 ) ;
V_6 = F_123 ( V_2 ) ;
if ( V_6 < 0 )
goto V_233;
V_2 -> V_88 = V_234 ;
V_2 -> V_89 = V_235 ;
return 0 ;
V_233:
F_130 ( V_2 ) ;
return V_6 ;
}
static int T_9 F_131 ( struct V_229 * V_9 )
{
struct V_1 * V_2 = F_132 ( V_9 ) ;
if ( ! V_2 )
return - V_43 ;
F_121 ( & V_2 -> V_212 ) ;
F_130 ( V_2 ) ;
return 0 ;
}
static int T_10 F_133 ( void )
{
return F_134 ( & V_236 , F_127 ) ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_236 ) ;
}
