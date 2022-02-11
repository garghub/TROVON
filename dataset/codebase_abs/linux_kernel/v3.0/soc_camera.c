static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
if ( V_5 ) {
V_6 = F_2 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
return V_6 ;
}
if ( V_4 -> V_10 )
V_6 = V_4 -> V_10 ( V_2 -> V_11 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 ,
L_2 ) ;
F_4 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
return V_6 ;
}
} else {
V_6 = 0 ;
if ( V_4 -> V_10 )
V_6 = V_4 -> V_10 ( V_2 -> V_11 , 0 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 ,
L_3 ) ;
return V_6 ;
}
V_6 = F_4 ( V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_4 ) ;
return V_6 ;
}
}
return 0 ;
}
const struct V_12 * F_5 (
struct V_1 * V_2 , unsigned int V_13 )
{
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ )
if ( V_2 -> V_16 [ V_14 ] . V_17 -> V_13 == V_13 )
return V_2 -> V_16 + V_14 ;
return NULL ;
}
unsigned long F_6 ( struct V_3 * V_4 ,
unsigned long V_18 )
{
unsigned long V_19 ;
if ( V_4 -> V_18 & V_20 ) {
V_19 = V_18 & ( V_21 | V_22 ) ;
if ( V_19 == V_21 || V_19 == V_22 )
V_18 ^= V_21 | V_22 ;
}
if ( V_4 -> V_18 & V_23 ) {
V_19 = V_18 & ( V_24 | V_25 ) ;
if ( V_19 == V_24 || V_19 == V_25 )
V_18 ^= V_24 | V_25 ;
}
if ( V_4 -> V_18 & V_26 ) {
V_19 = V_18 & ( V_27 | V_28 ) ;
if ( V_19 == V_27 || V_19 == V_28 )
V_18 ^= V_27 | V_28 ;
}
return V_18 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_29 * V_19 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_33 * V_34 = & V_19 -> V_35 . V_34 ;
int V_6 ;
F_9 ( & V_2 -> V_9 , L_5 ,
F_10 ( V_34 -> V_36 ) , V_34 -> V_37 , V_34 -> V_38 ) ;
V_34 -> V_39 = 0 ;
V_34 -> V_40 = 0 ;
V_6 = V_31 -> V_41 -> V_42 ( V_2 , V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_34 -> V_40 ) {
if ( ! V_34 -> V_39 ) {
const struct V_12 * V_43 ;
V_43 = F_5 ( V_2 , V_34 -> V_36 ) ;
if ( ! V_43 )
return - V_44 ;
V_6 = F_11 ( V_34 -> V_37 ,
V_43 -> V_17 ) ;
if ( V_6 > 0 )
V_34 -> V_39 = V_6 ;
}
if ( V_34 -> V_39 )
V_34 -> V_40 = V_34 -> V_39 * V_34 -> V_38 ;
}
return 0 ;
}
static int F_12 ( struct V_45 * V_45 , void * V_46 ,
struct V_29 * V_19 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_19 -> type != V_48 )
return - V_44 ;
return F_7 ( V_2 , V_19 ) ;
}
static int F_14 ( struct V_45 * V_45 , void * V_46 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
int V_6 = 0 ;
if ( V_50 -> V_51 != 0 )
return - V_44 ;
if ( V_2 -> V_41 -> V_52 )
V_6 = V_2 -> V_41 -> V_52 ( V_2 , V_50 ) ;
else {
V_50 -> type = V_53 ;
V_50 -> V_54 = V_55 ;
strcpy ( V_50 -> V_56 , L_6 ) ;
}
return V_6 ;
}
static int F_15 ( struct V_45 * V_45 , void * V_46 , unsigned int * V_14 )
{
* V_14 = 0 ;
return 0 ;
}
static int F_16 ( struct V_45 * V_45 , void * V_46 , unsigned int V_14 )
{
if ( V_14 > 0 )
return - V_44 ;
return 0 ;
}
static int F_17 ( struct V_45 * V_45 , void * V_46 , T_1 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_60 , V_61 , * V_57 ) ;
}
static int F_20 ( struct V_45 * V_45 , void * V_62 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
return V_31 -> V_41 -> V_65 ( V_2 , V_64 ) ;
}
static int F_21 ( struct V_45 * V_45 , void * V_46 ,
struct V_66 * V_67 )
{
int V_6 ;
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_2 -> V_68 && V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 ) {
V_6 = F_22 ( & V_2 -> V_71 , V_67 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = V_31 -> V_41 -> V_72 ( V_2 , V_67 ) ;
} else {
V_6 = F_23 ( & V_2 -> V_73 , V_67 ) ;
}
if ( ! V_6 && ! V_2 -> V_68 )
V_2 -> V_68 = V_45 ;
return V_6 ;
}
static int F_24 ( struct V_45 * V_45 , void * V_46 ,
struct V_74 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_31 -> V_41 -> V_70 )
return F_25 ( & V_2 -> V_71 , V_67 ) ;
else
return F_26 ( & V_2 -> V_73 , V_67 ) ;
}
static int F_27 ( struct V_45 * V_45 , void * V_46 ,
struct V_74 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 )
return F_28 ( & V_2 -> V_71 , V_67 ) ;
else
return F_29 ( & V_2 -> V_73 , V_67 ) ;
}
static int F_30 ( struct V_45 * V_45 , void * V_46 ,
struct V_74 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 )
return F_31 ( & V_2 -> V_71 , V_67 , V_45 -> V_75 & V_76 ) ;
else
return F_32 ( & V_2 -> V_73 , V_67 , V_45 -> V_75 & V_76 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
unsigned int V_14 , V_77 = 0 , V_78 = 0 ;
int V_6 ;
enum V_79 V_80 ;
while ( ! F_19 ( V_59 , V_81 , V_82 , V_78 , & V_80 ) )
V_78 ++ ;
if ( ! V_31 -> V_41 -> V_83 )
V_77 = V_78 ;
else
for ( V_14 = 0 ; V_14 < V_78 ; V_14 ++ ) {
V_6 = V_31 -> V_41 -> V_83 ( V_2 , V_14 , NULL ) ;
if ( V_6 < 0 )
return V_6 ;
V_77 += V_6 ;
}
if ( ! V_77 )
return - V_84 ;
V_2 -> V_16 =
F_34 ( V_77 * sizeof( struct V_12 ) ) ;
if ( ! V_2 -> V_16 )
return - V_85 ;
F_9 ( & V_2 -> V_9 , L_7 , V_77 ) ;
V_77 = 0 ;
for ( V_14 = 0 ; V_14 < V_78 ; V_14 ++ )
if ( ! V_31 -> V_41 -> V_83 ) {
F_19 ( V_59 , V_81 , V_82 , V_14 , & V_80 ) ;
V_2 -> V_16 [ V_77 ] . V_17 =
F_35 ( V_80 ) ;
if ( V_2 -> V_16 [ V_77 ] . V_17 )
V_2 -> V_16 [ V_77 ++ ] . V_80 = V_80 ;
} else {
V_6 = V_31 -> V_41 -> V_83 ( V_2 , V_14 ,
& V_2 -> V_16 [ V_77 ] ) ;
if ( V_6 < 0 )
goto V_86;
V_77 += V_6 ;
}
V_2 -> V_15 = V_77 ;
V_2 -> V_87 = & V_2 -> V_16 [ 0 ] ;
return 0 ;
V_86:
F_36 ( V_2 -> V_16 ) ;
return V_6 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
if ( V_31 -> V_41 -> V_88 )
V_31 -> V_41 -> V_88 ( V_2 ) ;
V_2 -> V_87 = NULL ;
V_2 -> V_15 = 0 ;
F_36 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_29 * V_19 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_33 * V_34 = & V_19 -> V_35 . V_34 ;
int V_6 ;
F_9 ( & V_2 -> V_9 , L_8 ,
F_10 ( V_34 -> V_36 ) , V_34 -> V_37 , V_34 -> V_38 ) ;
V_6 = F_7 ( V_2 , V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = V_31 -> V_41 -> V_89 ( V_2 , V_19 ) ;
if ( V_6 < 0 ) {
return V_6 ;
} else if ( ! V_2 -> V_87 ||
V_2 -> V_87 -> V_17 -> V_13 != V_34 -> V_36 ) {
F_3 ( & V_2 -> V_9 ,
L_9 ) ;
return - V_44 ;
}
V_2 -> V_90 = V_34 -> V_37 ;
V_2 -> V_91 = V_34 -> V_38 ;
V_2 -> V_39 = V_34 -> V_39 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_92 = V_34 -> V_92 ;
V_2 -> V_93 = V_34 -> V_93 ;
if ( V_31 -> V_41 -> V_70 )
V_2 -> V_71 . V_93 = V_34 -> V_93 ;
F_9 ( & V_2 -> V_9 , L_10 ,
V_2 -> V_90 , V_2 -> V_91 ) ;
return V_31 -> V_41 -> V_94 ( V_2 , V_34 -> V_36 ) ;
}
static int F_39 ( struct V_45 * V_45 )
{
struct V_95 * V_96 = F_40 ( V_45 ) ;
struct V_1 * V_2 = F_41 ( V_96 -> V_32 ,
struct V_1 ,
V_9 ) ;
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_30 * V_31 ;
int V_6 ;
if ( ! V_2 -> V_41 )
return - V_97 ;
V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
if ( ! F_43 ( V_31 -> V_41 -> V_98 ) ) {
F_3 ( & V_2 -> V_9 , L_11 ) ;
return - V_44 ;
}
V_2 -> V_99 ++ ;
if ( V_2 -> V_99 == 1 ) {
struct V_29 V_19 = {
. type = V_48 ,
. V_35 . V_34 = {
. V_37 = V_2 -> V_90 ,
. V_38 = V_2 -> V_91 ,
. V_93 = V_2 -> V_93 ,
. V_92 = V_2 -> V_92 ,
. V_36 =
V_2 -> V_87 -> V_17 -> V_13 ,
} ,
} ;
V_6 = F_1 ( V_2 , V_4 , 1 ) ;
if ( V_6 < 0 )
goto V_100;
if ( V_4 -> V_101 )
V_4 -> V_101 ( V_2 -> V_11 ) ;
V_6 = V_31 -> V_41 -> V_102 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_12 , V_6 ) ;
goto V_103;
}
F_44 ( & V_2 -> V_96 -> V_9 ) ;
V_6 = F_45 ( & V_2 -> V_96 -> V_9 ) ;
if ( V_6 < 0 && V_6 != - V_104 )
goto V_105;
V_6 = F_38 ( V_2 , & V_19 ) ;
if ( V_6 < 0 )
goto V_106;
if ( V_31 -> V_41 -> V_70 ) {
V_31 -> V_41 -> V_70 ( & V_2 -> V_71 , V_2 ) ;
} else {
V_6 = V_31 -> V_41 -> V_107 ( & V_2 -> V_73 , V_2 ) ;
if ( V_6 < 0 )
goto V_108;
}
}
V_45 -> V_47 = V_2 ;
F_9 ( & V_2 -> V_9 , L_13 ) ;
return 0 ;
V_108:
V_106:
F_46 ( & V_2 -> V_96 -> V_9 ) ;
V_105:
V_31 -> V_41 -> remove ( V_2 ) ;
V_103:
F_1 ( V_2 , V_4 , 0 ) ;
V_100:
V_2 -> V_99 -- ;
F_47 ( V_31 -> V_41 -> V_98 ) ;
return V_6 ;
}
static int F_48 ( struct V_45 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
V_2 -> V_99 -- ;
if ( ! V_2 -> V_99 ) {
struct V_3 * V_4 = F_42 ( V_2 ) ;
F_49 ( & V_2 -> V_96 -> V_9 ) ;
F_46 ( & V_2 -> V_96 -> V_9 ) ;
V_31 -> V_41 -> remove ( V_2 ) ;
if ( V_31 -> V_41 -> V_107 )
F_50 ( & V_2 -> V_73 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
}
if ( V_2 -> V_68 == V_45 )
V_2 -> V_68 = NULL ;
F_47 ( V_31 -> V_41 -> V_98 ) ;
F_9 ( & V_2 -> V_9 , L_14 ) ;
return 0 ;
}
static T_2 F_51 ( struct V_45 * V_45 , char T_3 * V_109 ,
T_4 V_110 , T_5 * V_111 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
int V_112 = - V_44 ;
F_3 ( & V_2 -> V_9 , L_15 ) ;
return V_112 ;
}
static int F_52 ( struct V_45 * V_45 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
int V_112 ;
F_9 ( & V_2 -> V_9 , L_16 , ( unsigned long ) V_114 ) ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 )
V_112 = F_53 ( & V_2 -> V_71 , V_114 ) ;
else
V_112 = F_54 ( & V_2 -> V_73 , V_114 ) ;
F_9 ( & V_2 -> V_9 , L_17 ,
( unsigned long ) V_114 -> V_115 ,
( unsigned long ) V_114 -> V_116 - ( unsigned long ) V_114 -> V_115 ,
V_112 ) ;
return V_112 ;
}
static unsigned int F_55 ( struct V_45 * V_45 , T_6 * V_117 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 && F_56 ( & V_2 -> V_71 . V_118 ) ) {
F_3 ( & V_2 -> V_9 , L_18 ) ;
return V_119 ;
}
return V_31 -> V_41 -> V_120 ( V_45 , V_117 ) ;
}
void F_57 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_58 ( V_122 ) ;
F_59 ( & V_2 -> V_123 ) ;
}
void F_60 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_58 ( V_122 ) ;
F_61 ( & V_2 -> V_123 ) ;
}
static int F_62 ( struct V_45 * V_45 , void * V_46 ,
struct V_29 * V_19 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
int V_6 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_19 -> type != V_48 ) {
F_63 ( & V_2 -> V_9 , L_19 , V_19 -> type ) ;
return - V_44 ;
}
if ( V_2 -> V_68 && V_2 -> V_68 != V_45 )
return - V_69 ;
if ( F_64 ( F_8 ( V_2 -> V_9 . V_32 ) , V_2 ) ) {
F_3 ( & V_2 -> V_9 , L_20 ) ;
return - V_69 ;
}
V_6 = F_38 ( V_2 , V_19 ) ;
if ( ! V_6 && ! V_2 -> V_68 )
V_2 -> V_68 = V_45 ;
return V_6 ;
}
static int F_65 ( struct V_45 * V_45 , void * V_46 ,
struct V_124 * V_19 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
const struct V_125 * V_126 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_19 -> V_51 >= V_2 -> V_15 )
return - V_44 ;
V_126 = V_2 -> V_16 [ V_19 -> V_51 ] . V_17 ;
if ( V_126 -> V_56 )
F_66 ( V_19 -> V_127 , V_126 -> V_56 , sizeof( V_19 -> V_127 ) ) ;
V_19 -> V_36 = V_126 -> V_13 ;
return 0 ;
}
static int F_67 ( struct V_45 * V_45 , void * V_46 ,
struct V_29 * V_19 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_33 * V_34 = & V_19 -> V_35 . V_34 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_19 -> type != V_48 )
return - V_44 ;
V_34 -> V_37 = V_2 -> V_90 ;
V_34 -> V_38 = V_2 -> V_91 ;
V_34 -> V_39 = V_2 -> V_39 ;
V_34 -> V_40 = V_2 -> V_40 ;
V_34 -> V_93 = V_2 -> V_93 ;
V_34 -> V_36 = V_2 -> V_87 -> V_17 -> V_13 ;
V_34 -> V_92 = V_2 -> V_92 ;
F_9 ( & V_2 -> V_9 , L_21 ,
V_2 -> V_87 -> V_17 -> V_13 ) ;
return 0 ;
}
static int F_68 ( struct V_45 * V_45 , void * V_46 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
F_66 ( V_129 -> V_130 , V_31 -> V_131 , sizeof( V_129 -> V_130 ) ) ;
return V_31 -> V_41 -> V_132 ( V_31 , V_129 ) ;
}
static int F_69 ( struct V_45 * V_45 , void * V_46 ,
enum V_133 V_14 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_14 != V_48 )
return - V_44 ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 )
V_6 = F_70 ( & V_2 -> V_71 ) ;
else
V_6 = F_71 ( & V_2 -> V_73 , V_14 ) ;
if ( ! V_6 )
F_19 ( V_59 , V_81 , V_134 , 1 ) ;
return V_6 ;
}
static int F_72 ( struct V_45 * V_45 , void * V_46 ,
enum V_133 V_14 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_14 != V_48 )
return - V_44 ;
if ( V_2 -> V_68 != V_45 )
return - V_69 ;
if ( V_31 -> V_41 -> V_70 )
F_73 ( & V_2 -> V_71 ) ;
else
F_74 ( & V_2 -> V_73 , V_14 ) ;
F_19 ( V_59 , V_81 , V_134 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_45 * V_45 , void * V_46 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
int V_14 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( ! V_136 -> V_137 )
return - V_44 ;
for ( V_14 = 0 ; V_14 < V_31 -> V_41 -> V_138 ; V_14 ++ )
if ( V_136 -> V_137 == V_31 -> V_41 -> V_139 [ V_14 ] . V_137 ) {
memcpy ( V_136 , & ( V_31 -> V_41 -> V_139 [ V_14 ] ) ,
sizeof( * V_136 ) ) ;
return 0 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_41 -> V_138 ; V_14 ++ )
if ( V_136 -> V_137 == V_2 -> V_41 -> V_139 [ V_14 ] . V_137 ) {
memcpy ( V_136 , & ( V_2 -> V_41 -> V_139 [ V_14 ] ) ,
sizeof( * V_136 ) ) ;
return 0 ;
}
return - V_44 ;
}
static int F_76 ( struct V_45 * V_45 , void * V_46 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_31 -> V_41 -> V_142 ) {
V_6 = V_31 -> V_41 -> V_142 ( V_2 , V_141 ) ;
if ( V_6 != - V_143 )
return V_6 ;
}
return F_19 ( V_59 , V_60 , V_144 , V_141 ) ;
}
static int F_77 ( struct V_45 * V_45 , void * V_46 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
int V_6 ;
F_13 ( V_46 != V_45 -> V_47 ) ;
if ( V_31 -> V_41 -> V_145 ) {
V_6 = V_31 -> V_41 -> V_145 ( V_2 , V_141 ) ;
if ( V_6 != - V_143 )
return V_6 ;
}
return F_19 ( V_59 , V_60 , V_146 , V_141 ) ;
}
static int F_78 ( struct V_45 * V_45 , void * V_62 ,
struct V_147 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
return V_31 -> V_41 -> V_148 ( V_2 , V_57 ) ;
}
static int F_79 ( struct V_45 * V_45 , void * V_62 ,
struct V_149 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
int V_6 ;
V_6 = V_31 -> V_41 -> V_150 ( V_2 , V_57 ) ;
return V_6 ;
}
static int F_80 ( struct V_45 * V_45 , void * V_62 ,
struct V_149 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_151 * V_152 = & V_57 -> V_153 ;
struct V_149 V_154 ;
int V_6 ;
if ( V_57 -> type != V_48 )
return - V_44 ;
F_9 ( & V_2 -> V_9 , L_22 ,
V_152 -> V_37 , V_152 -> V_38 , V_152 -> V_155 , V_152 -> V_156 ) ;
V_6 = V_31 -> V_41 -> V_150 ( V_2 , & V_154 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 ,
L_23 ) ;
} else if ( ( V_57 -> V_153 . V_37 == V_154 . V_153 . V_37 &&
V_57 -> V_153 . V_38 == V_154 . V_153 . V_38 ) ||
! F_64 ( V_31 , V_2 ) ) {
V_6 = V_31 -> V_41 -> V_157 ( V_2 , V_57 ) ;
} else if ( V_31 -> V_41 -> V_158 ) {
V_6 = V_31 -> V_41 -> V_158 ( V_2 , V_57 ) ;
} else {
F_3 ( & V_2 -> V_9 ,
L_24 ) ;
V_6 = - V_69 ;
}
return V_6 ;
}
static int F_81 ( struct V_45 * V_45 , void * V_62 ,
struct V_159 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
if ( V_31 -> V_41 -> V_160 )
return V_31 -> V_41 -> V_160 ( V_2 , V_57 ) ;
return - V_143 ;
}
static int F_82 ( struct V_45 * V_45 , void * V_62 ,
struct V_159 * V_57 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
if ( V_31 -> V_41 -> V_161 )
return V_31 -> V_41 -> V_161 ( V_2 , V_57 ) ;
return - V_143 ;
}
static int F_83 ( struct V_45 * V_45 , void * V_62 ,
struct V_162 * V_137 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_60 , V_163 , V_137 ) ;
}
static int F_84 ( struct V_45 * V_45 , void * V_62 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_60 , V_166 , V_165 ) ;
}
static int F_85 ( struct V_45 * V_45 , void * V_62 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = V_45 -> V_47 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_60 , V_167 , V_165 ) ;
}
static void F_86 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
F_59 ( & V_168 ) ;
F_87 (icd, &devices, list) {
if ( V_2 -> V_169 == V_31 -> V_170 ) {
int V_6 ;
V_2 -> V_9 . V_32 = V_31 -> V_171 . V_9 ;
F_88 ( & V_2 -> V_9 , L_25 , V_2 -> V_169 ,
V_2 -> V_172 ) ;
V_6 = F_89 ( & V_2 -> V_9 ) ;
if ( V_6 < 0 ) {
V_2 -> V_9 . V_32 = NULL ;
F_3 ( & V_2 -> V_9 ,
L_26 , V_6 ) ;
}
}
}
F_61 ( & V_168 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_173 * V_174 ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_175 * V_176 = F_91 ( V_4 -> V_177 ) ;
struct V_58 * V_178 ;
if ( ! V_176 ) {
F_3 ( & V_2 -> V_9 , L_27 ,
V_4 -> V_177 ) ;
goto V_179;
}
V_4 -> V_180 -> V_181 = V_2 ;
V_178 = F_92 ( & V_31 -> V_171 , V_176 ,
V_4 -> V_180 , NULL ) ;
if ( ! V_178 )
goto V_182;
V_174 = F_93 ( V_178 ) ;
F_94 ( & V_2 -> V_9 , & V_174 -> V_9 ) ;
return 0 ;
V_182:
F_95 ( V_176 ) ;
V_179:
return - V_97 ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_173 * V_174 =
F_97 ( F_98 ( V_2 ) ) ;
struct V_175 * V_176 = V_174 -> V_183 ;
F_94 ( & V_2 -> V_9 , NULL ) ;
F_99 ( F_100 ( V_174 ) ) ;
F_101 ( V_174 ) ;
F_95 ( V_176 ) ;
}
static int F_102 ( struct V_184 * V_9 )
{
struct V_1 * V_2 = F_103 ( V_9 ) ;
struct V_30 * V_31 = F_8 ( V_9 -> V_32 ) ;
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_184 * V_185 = NULL ;
struct V_58 * V_59 ;
struct V_186 V_187 ;
int V_6 ;
F_104 ( V_9 , L_28 , F_105 ( V_9 ) ) ;
V_6 = F_106 ( V_2 -> V_11 , V_4 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 < 0 )
goto V_188;
V_6 = F_1 ( V_2 , V_4 , 1 ) ;
if ( V_6 < 0 )
goto V_100;
if ( V_4 -> V_101 )
V_4 -> V_101 ( V_2 -> V_11 ) ;
V_6 = V_31 -> V_41 -> V_102 ( V_2 ) ;
if ( V_6 < 0 )
goto V_189;
V_6 = F_107 ( V_2 ) ;
if ( V_6 < 0 )
goto V_190;
if ( V_4 -> V_180 ) {
V_6 = F_90 ( V_2 , V_4 ) ;
if ( V_6 < 0 )
goto V_191;
} else if ( ! V_4 -> V_192 || ! V_4 -> V_193 ) {
V_6 = - V_44 ;
goto V_191;
} else {
if ( V_4 -> V_194 )
V_6 = F_108 ( V_4 -> V_194 ) ;
V_6 = V_4 -> V_192 ( V_4 , & V_2 -> V_9 ) ;
if ( V_6 < 0 )
goto V_191;
V_185 = F_98 ( V_2 ) ;
if ( ! V_185 || ! V_185 -> V_130 || ! F_109 ( V_185 ) ||
! F_43 ( V_185 -> V_130 -> V_98 ) ) {
V_4 -> V_193 ( V_4 ) ;
goto V_195;
}
}
V_59 = F_18 ( V_2 ) ;
V_59 -> V_196 = ( long ) V_2 ;
V_6 = F_33 ( V_2 ) ;
if ( V_6 < 0 )
goto V_197;
V_2 -> V_93 = V_198 ;
V_2 -> V_96 -> V_199 = & V_2 -> V_123 ;
F_59 ( & V_2 -> V_123 ) ;
V_6 = F_110 ( V_2 ) ;
if ( V_6 < 0 )
goto V_200;
if ( ! F_19 ( V_59 , V_81 , V_201 , & V_187 ) ) {
V_2 -> V_90 = V_187 . V_37 ;
V_2 -> V_91 = V_187 . V_38 ;
V_2 -> V_92 = V_187 . V_92 ;
V_2 -> V_93 = V_187 . V_93 ;
}
if ( F_111 ( & V_2 -> V_9 . V_202 , & F_98 ( V_2 ) -> V_202 ,
L_29 ) )
F_63 ( & V_2 -> V_9 , L_30 ) ;
V_31 -> V_41 -> remove ( V_2 ) ;
F_1 ( V_2 , V_4 , 0 ) ;
F_61 ( & V_2 -> V_123 ) ;
return 0 ;
V_200:
F_61 ( & V_2 -> V_123 ) ;
F_37 ( V_2 ) ;
V_197:
if ( V_4 -> V_180 ) {
F_96 ( V_2 ) ;
} else {
V_4 -> V_193 ( V_4 ) ;
F_47 ( V_185 -> V_130 -> V_98 ) ;
}
V_195:
V_191:
F_112 ( V_2 -> V_96 ) ;
V_190:
V_31 -> V_41 -> remove ( V_2 ) ;
V_189:
F_1 ( V_2 , V_4 , 0 ) ;
V_100:
F_113 ( V_4 -> V_7 , V_4 -> V_8 ) ;
V_188:
return V_6 ;
}
static int F_114 ( struct V_184 * V_9 )
{
struct V_1 * V_2 = F_103 ( V_9 ) ;
struct V_3 * V_4 = F_42 ( V_2 ) ;
struct V_95 * V_96 = V_2 -> V_96 ;
F_115 ( ! V_9 -> V_32 ) ;
if ( V_96 ) {
F_116 ( V_96 ) ;
V_2 -> V_96 = NULL ;
}
if ( V_4 -> V_180 ) {
F_96 ( V_2 ) ;
} else {
struct V_203 * V_204 = F_98 ( V_2 ) ?
F_98 ( V_2 ) -> V_130 : NULL ;
if ( V_204 ) {
V_4 -> V_193 ( V_4 ) ;
F_47 ( V_204 -> V_98 ) ;
}
}
F_37 ( V_2 ) ;
F_113 ( V_4 -> V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static int F_117 ( struct V_184 * V_9 , T_7 V_205 )
{
struct V_1 * V_2 = F_103 ( V_9 ) ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
int V_6 = 0 ;
if ( V_31 -> V_41 -> V_206 )
V_6 = V_31 -> V_41 -> V_206 ( V_2 , V_205 ) ;
return V_6 ;
}
static int F_118 ( struct V_184 * V_9 )
{
struct V_1 * V_2 = F_103 ( V_9 ) ;
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
int V_6 = 0 ;
if ( V_31 -> V_41 -> V_207 )
V_6 = V_31 -> V_41 -> V_207 ( V_2 ) ;
return V_6 ;
}
static void F_119 ( struct V_184 * V_9 )
{
}
static int F_120 ( struct V_1 * V_2 ,
struct V_147 * V_57 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_81 , V_148 , V_57 ) ;
}
static int F_121 ( struct V_1 * V_2 , struct V_149 * V_57 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_81 , V_208 , V_57 ) ;
}
static int F_122 ( struct V_1 * V_2 , struct V_149 * V_57 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_81 , V_209 , V_57 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_159 * V_210 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_81 , V_211 , V_210 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_159 * V_210 )
{
struct V_58 * V_59 = F_18 ( V_2 ) ;
return F_19 ( V_59 , V_81 , V_212 , V_210 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
int V_6 ;
struct V_58 * V_59 = F_18 ( V_2 ) ;
const struct V_12 * V_43 ;
T_8 V_213 = V_64 -> V_214 ;
struct V_63 V_215 = * V_64 ;
V_43 = F_5 ( V_2 , V_213 ) ;
if ( ! V_43 )
return - V_44 ;
V_215 . V_214 = V_43 -> V_80 ;
V_6 = F_19 ( V_59 , V_81 , V_216 , & V_215 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_64 = V_215 ;
V_64 -> V_214 = V_213 ;
return 0 ;
}
static void F_126 ( struct V_184 * V_9 , void * V_217 )
{
V_9 -> V_181 = V_217 ;
V_9 -> V_218 = & V_219 ;
V_9 -> V_220 = F_119 ;
}
int F_127 ( struct V_30 * V_31 )
{
struct V_30 * V_221 ;
int V_6 ;
if ( ! V_31 || ! V_31 -> V_41 ||
! V_31 -> V_41 -> V_42 ||
! V_31 -> V_41 -> V_89 ||
! V_31 -> V_41 -> V_94 ||
! V_31 -> V_41 -> V_132 ||
( ( ! V_31 -> V_41 -> V_70 ||
! V_31 -> V_41 -> V_72 ) &&
! V_31 -> V_41 -> V_107 ) ||
! V_31 -> V_41 -> V_102 ||
! V_31 -> V_41 -> remove ||
! V_31 -> V_41 -> V_120 ||
! V_31 -> V_171 . V_9 )
return - V_44 ;
if ( ! V_31 -> V_41 -> V_157 )
V_31 -> V_41 -> V_157 = F_122 ;
if ( ! V_31 -> V_41 -> V_150 )
V_31 -> V_41 -> V_150 = F_121 ;
if ( ! V_31 -> V_41 -> V_148 )
V_31 -> V_41 -> V_148 = F_120 ;
if ( ! V_31 -> V_41 -> V_161 )
V_31 -> V_41 -> V_161 = F_124 ;
if ( ! V_31 -> V_41 -> V_160 )
V_31 -> V_41 -> V_160 = F_123 ;
if ( ! V_31 -> V_41 -> V_65 )
V_31 -> V_41 -> V_65 = F_125 ;
F_59 ( & V_168 ) ;
F_87 (ix, &hosts, list) {
if ( V_221 -> V_170 == V_31 -> V_170 ) {
V_6 = - V_69 ;
goto V_222;
}
}
V_6 = F_128 ( V_31 -> V_171 . V_9 , & V_31 -> V_171 ) ;
if ( V_6 < 0 )
goto V_222;
F_129 ( & V_31 -> V_223 , & V_224 ) ;
F_61 ( & V_168 ) ;
F_86 ( V_31 ) ;
return 0 ;
V_222:
F_61 ( & V_168 ) ;
return V_6 ;
}
void F_130 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
F_59 ( & V_168 ) ;
F_131 ( & V_31 -> V_223 ) ;
F_87 (icd, &devices, list) {
if ( V_2 -> V_169 == V_31 -> V_170 ) {
void * V_217 = V_2 -> V_9 . V_181 ;
F_132 ( & V_2 -> V_9 ) ;
memset ( & V_2 -> V_9 , 0 , sizeof( V_2 -> V_9 ) ) ;
F_126 ( & V_2 -> V_9 , V_217 ) ;
}
}
F_61 ( & V_168 ) ;
F_133 ( & V_31 -> V_171 ) ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_1 * V_221 ;
int V_225 = - 1 , V_14 ;
for ( V_14 = 0 ; V_14 < 256 && V_225 < 0 ; V_14 ++ ) {
V_225 = V_14 ;
F_87 (ix, &devices, list) {
if ( V_221 -> V_169 == V_2 -> V_169 && V_221 -> V_172 == V_14 ) {
V_225 = - 1 ;
break;
}
}
}
if ( V_225 < 0 )
return - V_85 ;
V_2 -> V_172 = V_225 ;
V_2 -> V_99 = 0 ;
V_2 -> V_226 = NULL ;
F_135 ( & V_2 -> V_123 ) ;
F_129 ( & V_2 -> V_223 , & V_227 ) ;
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_131 ( & V_2 -> V_223 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_8 ( V_2 -> V_9 . V_32 ) ;
struct V_95 * V_96 = F_137 () ;
if ( ! V_96 )
return - V_85 ;
F_66 ( V_96 -> V_56 , V_31 -> V_131 , sizeof( V_96 -> V_56 ) ) ;
V_96 -> V_32 = & V_2 -> V_9 ;
V_96 -> V_228 = V_55 ;
V_96 -> V_229 = & V_230 ;
V_96 -> V_231 = & V_232 ;
V_96 -> V_220 = F_112 ;
V_96 -> V_233 = V_55 ;
V_2 -> V_96 = V_96 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
const struct V_234 * type = V_2 -> V_96 -> V_9 . type ;
int V_6 ;
if ( ! V_2 -> V_9 . V_32 )
return - V_97 ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_235 ||
! V_2 -> V_41 -> V_94 )
return - V_44 ;
V_6 = F_138 ( V_2 -> V_96 , V_236 , - 1 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_31 , V_6 ) ;
return V_6 ;
}
V_2 -> V_96 -> V_9 . type = type ;
return 0 ;
}
static int T_9 F_139 ( struct V_237 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_9 . V_181 ;
struct V_1 * V_2 ;
int V_6 ;
if ( ! V_4 )
return - V_44 ;
V_2 = F_140 ( sizeof( * V_2 ) , V_238 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_169 = V_4 -> V_239 ;
V_2 -> V_11 = & V_11 -> V_9 ;
F_141 ( V_11 , V_2 ) ;
V_6 = F_134 ( V_2 ) ;
if ( V_6 < 0 )
goto V_240;
F_126 ( & V_2 -> V_9 , V_4 ) ;
V_2 -> V_90 = V_241 ;
V_2 -> V_91 = V_242 ;
return 0 ;
V_240:
F_142 ( V_2 ) ;
return V_6 ;
}
static int T_10 F_143 ( struct V_237 * V_11 )
{
struct V_1 * V_2 = F_144 ( V_11 ) ;
if ( ! V_2 )
return - V_44 ;
F_136 ( V_2 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
static int T_11 F_145 ( void )
{
int V_6 = F_146 ( & V_219 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_147 ( & V_243 ) ;
if ( V_6 )
goto V_244;
V_6 = F_148 ( & V_245 , F_139 ) ;
if ( V_6 )
goto V_246;
return 0 ;
V_246:
F_149 ( & V_243 ) ;
V_244:
F_150 ( & V_219 ) ;
return V_6 ;
}
static void T_12 F_151 ( void )
{
F_152 ( & V_245 ) ;
F_149 ( & V_243 ) ;
F_150 ( & V_219 ) ;
}
