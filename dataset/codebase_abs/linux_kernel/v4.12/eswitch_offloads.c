struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 V_9 [ 2 ] = {} ;
struct V_10 V_11 = { 0 } ;
struct V_12 * V_13 = NULL ;
struct V_1 * V_14 ;
void * V_15 ;
int V_16 = 0 ;
if ( V_3 -> V_17 != V_18 )
return F_2 ( - V_19 ) ;
V_11 . V_20 = V_7 -> V_20 & ~ ( V_21 | V_22 ) ;
if ( V_11 . V_20 & V_23 ) {
V_9 [ V_16 ] . type = V_24 ;
V_9 [ V_16 ] . V_25 = V_7 -> V_26 -> V_27 ;
V_16 ++ ;
}
if ( V_11 . V_20 & V_28 ) {
V_13 = F_3 ( V_3 -> V_29 , true ) ;
if ( F_4 ( V_13 ) ) {
V_14 = F_5 ( V_13 ) ;
goto V_30;
}
V_9 [ V_16 ] . type = V_31 ;
V_9 [ V_16 ] . V_13 = V_13 ;
V_16 ++ ;
}
V_15 = F_6 ( V_32 , V_5 -> V_33 , V_34 ) ;
F_7 ( V_35 , V_15 , V_36 , V_7 -> V_37 -> V_27 ) ;
V_15 = F_6 ( V_32 , V_5 -> V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
V_5 -> V_39 = V_40 |
V_41 ;
if ( V_11 . V_20 & V_42 )
V_5 -> V_39 |= V_43 ;
if ( V_7 -> V_20 & V_44 )
V_11 . V_45 = V_7 -> V_46 ;
if ( V_7 -> V_20 & V_47 )
V_11 . V_48 = V_7 -> V_48 ;
V_14 = F_9 ( (struct V_49 * ) V_3 -> V_50 . V_51 ,
V_5 , & V_11 , V_9 , V_16 ) ;
if ( F_4 ( V_14 ) )
goto V_52;
else
V_3 -> V_53 . V_54 ++ ;
return V_14 ;
V_52:
F_10 ( V_3 -> V_29 , V_13 ) ;
V_30:
return V_14 ;
}
void
F_11 ( struct V_2 * V_3 ,
struct V_1 * V_14 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
V_13 = F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
F_10 ( V_3 -> V_29 , V_13 ) ;
V_3 -> V_53 . V_54 -- ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_55 )
{
struct V_56 * V_57 ;
int V_58 , V_59 = 0 ;
F_15 ( V_3 -> V_29 , L_1 , V_60 , V_55 ? L_2 : L_3 ) ;
for ( V_58 = 1 ; V_58 < V_3 -> V_61 ; V_58 ++ ) {
V_57 = & V_3 -> V_53 . V_62 [ V_58 ] ;
if ( ! V_57 -> V_63 )
continue;
V_59 = F_16 ( V_3 , V_57 -> V_27 , 0 , 0 , V_55 ) ;
if ( V_59 )
goto V_64;
}
V_64:
return V_59 ;
}
static struct V_56 *
F_17 ( struct V_6 * V_7 , bool V_65 , bool V_66 )
{
struct V_56 * V_37 , * V_26 , * V_27 = NULL ;
V_37 = V_7 -> V_37 ;
V_26 = V_7 -> V_26 ;
if ( V_65 )
V_27 = V_37 ;
else if ( V_66 )
V_27 = V_26 ;
else
V_27 = V_37 ;
return V_27 ;
}
static int F_18 ( struct V_6 * V_7 ,
bool V_65 , bool V_66 , bool V_67 )
{
struct V_56 * V_37 , * V_26 ;
if ( ( V_65 || V_66 ) && ! V_67 )
goto V_68;
V_37 = V_7 -> V_37 ;
V_26 = V_7 -> V_26 ;
if ( V_65 && V_37 -> V_27 == V_69 )
goto V_68;
if ( V_66 && V_26 -> V_27 == V_69 )
goto V_68;
if ( ! V_65 && ! V_66 && V_67 )
if ( V_37 -> V_70 && V_26 -> V_27 == V_69 )
goto V_68;
if ( V_65 && V_37 -> V_71 && ( V_37 -> V_70 != V_7 -> V_70 ) )
goto V_68;
return 0 ;
V_68:
return - V_19 ;
}
int F_19 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_72 * V_53 = & V_3 -> V_50 . V_53 ;
struct V_56 * V_27 = NULL ;
bool V_65 , V_66 , V_67 ;
int V_59 = 0 ;
V_65 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_66 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_67 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_59 = F_18 ( V_7 , V_65 , V_66 , V_67 ) ;
if ( V_59 )
return V_59 ;
V_7 -> V_73 = false ;
V_27 = F_17 ( V_7 , V_65 , V_66 ) ;
if ( ! V_65 && ! V_66 && V_67 ) {
if ( V_7 -> V_26 -> V_27 == V_69 ) {
V_27 -> V_71 ++ ;
V_7 -> V_73 = true ;
}
return 0 ;
}
if ( ! V_65 && ! V_66 )
return 0 ;
if ( ! ( V_53 -> V_74 ) ) {
V_59 = F_14 ( V_3 , V_75 ) ;
if ( V_59 )
goto V_64;
}
V_53 -> V_74 ++ ;
if ( V_65 ) {
if ( V_27 -> V_71 )
goto V_76;
V_59 = F_16 ( V_3 , V_27 -> V_27 , V_7 -> V_70 , 0 ,
V_77 | V_75 ) ;
if ( V_59 )
goto V_64;
V_27 -> V_70 = V_7 -> V_70 ;
V_76:
V_27 -> V_71 ++ ;
}
V_64:
if ( ! V_59 )
V_7 -> V_73 = true ;
return V_59 ;
}
int F_20 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_72 * V_53 = & V_3 -> V_50 . V_53 ;
struct V_56 * V_27 = NULL ;
bool V_65 , V_66 , V_67 ;
int V_59 = 0 ;
if ( ! V_7 -> V_73 )
return 0 ;
V_65 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_66 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_67 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_27 = F_17 ( V_7 , V_65 , V_66 ) ;
if ( ! V_65 && ! V_66 && V_67 ) {
if ( V_7 -> V_26 -> V_27 == V_69 )
V_27 -> V_71 -- ;
return 0 ;
}
if ( V_65 ) {
V_27 -> V_71 -- ;
if ( V_27 -> V_71 )
goto V_78;
V_27 -> V_70 = 0 ;
V_59 = F_16 ( V_3 , V_27 -> V_27 ,
0 , 0 , V_75 ) ;
if ( V_59 )
goto V_64;
}
V_78:
V_53 -> V_74 -- ;
if ( V_53 -> V_74 )
return 0 ;
V_59 = F_14 ( V_3 , 0 ) ;
V_64:
return V_59 ;
}
static struct V_1 *
F_21 ( struct V_2 * V_3 , int V_27 , T_2 V_79 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_80 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_4 ) ;
V_80 = F_2 ( - V_81 ) ;
goto V_64;
}
V_15 = F_6 ( V_32 , V_5 -> V_33 , V_34 ) ;
F_7 ( V_35 , V_15 , V_82 , V_79 ) ;
F_7 ( V_35 , V_15 , V_36 , 0x0 ) ;
V_15 = F_6 ( V_32 , V_5 -> V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_82 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
V_5 -> V_39 = V_41 ;
V_9 . type = V_24 ;
V_9 . V_25 = V_27 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_50 . V_53 . V_51 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) )
F_23 ( V_3 -> V_29 , L_5 , F_24 ( V_80 ) ) ;
V_64:
F_25 ( V_5 ) ;
return V_80 ;
}
void F_26 ( struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_83 * V_84 , * V_85 ;
if ( V_3 -> V_17 != V_18 )
return;
F_27 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_13 ( V_84 -> V_86 ) ;
F_28 ( & V_84 -> V_87 ) ;
F_29 ( V_84 ) ;
}
}
int F_30 ( struct V_2 * V_3 ,
struct V_56 * V_57 ,
T_3 * V_88 , int V_89 )
{
struct V_1 * V_80 ;
struct V_83 * V_84 ;
int V_59 ;
int V_16 ;
if ( V_3 -> V_17 != V_18 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_89 ; V_16 ++ ) {
V_84 = F_31 ( sizeof( * V_84 ) , V_90 ) ;
if ( ! V_84 ) {
V_59 = - V_81 ;
goto V_91;
}
V_80 = F_21 ( V_3 ,
V_57 -> V_27 ,
V_88 [ V_16 ] ) ;
if ( F_4 ( V_80 ) ) {
V_59 = F_24 ( V_80 ) ;
F_29 ( V_84 ) ;
goto V_91;
}
V_84 -> V_86 = V_80 ;
F_32 ( & V_84 -> V_87 , & V_57 -> V_92 ) ;
}
return 0 ;
V_91:
F_26 ( V_3 , V_57 ) ;
return V_59 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_80 = NULL ;
struct V_4 * V_5 ;
int V_59 = 0 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_4 ) ;
V_59 = - V_81 ;
goto V_64;
}
V_9 . type = V_24 ;
V_9 . V_25 = 0 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_50 . V_53 . V_51 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) ) {
V_59 = F_24 ( V_80 ) ;
F_23 ( V_3 -> V_29 , L_6 , V_59 ) ;
goto V_64;
}
V_3 -> V_50 . V_53 . V_93 = V_80 ;
V_64:
F_25 ( V_5 ) ;
return V_59 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_94 * V_29 = V_3 -> V_29 ;
struct V_95 * V_96 ;
struct V_49 * V_51 = NULL ;
int V_97 , V_59 = 0 ;
T_2 V_98 = 0 ;
V_96 = F_35 ( V_29 , V_99 ) ;
if ( ! V_96 ) {
F_23 ( V_29 , L_7 ) ;
V_59 = - V_19 ;
goto V_64;
}
F_15 ( V_29 , L_8 ,
F_36 ( V_29 , V_100 ) ,
F_37 ( V_29 , V_101 ) , V_102 ) ;
V_97 = F_38 ( int , F_37 ( V_29 , V_101 ) * V_102 ,
1 << F_36 ( V_29 , V_100 ) ) ;
if ( V_3 -> V_53 . V_103 != V_104 )
V_98 |= V_105 ;
V_51 = F_39 ( V_96 , V_106 ,
V_97 ,
V_102 , 0 ,
V_98 ) ;
if ( F_4 ( V_51 ) ) {
V_59 = F_24 ( V_51 ) ;
F_23 ( V_29 , L_9 , V_59 ) ;
goto V_64;
}
V_3 -> V_50 . V_51 = V_51 ;
V_64:
return V_59 ;
}
static void F_40 ( struct V_2 * V_3 )
{
F_41 ( V_3 -> V_50 . V_51 ) ;
}
static int F_42 ( struct V_2 * V_3 , int V_107 )
{
int V_108 = F_43 ( V_109 ) ;
struct V_110 V_111 = {} ;
struct V_94 * V_29 = V_3 -> V_29 ;
struct V_95 * V_96 ;
struct V_49 * V_51 = NULL ;
int V_112 , V_113 , V_59 = 0 ;
struct V_114 * V_115 ;
void * V_38 ;
T_2 * V_116 ;
F_15 ( V_3 -> V_29 , L_10 ) ;
V_116 = F_22 ( V_108 ) ;
if ( ! V_116 )
return - V_81 ;
V_96 = F_35 ( V_29 , V_99 ) ;
if ( ! V_96 ) {
F_23 ( V_29 , L_7 ) ;
V_59 = - V_19 ;
goto V_117;
}
V_59 = F_34 ( V_3 ) ;
if ( V_59 )
goto V_118;
V_112 = V_107 + V_119 + 1 ;
V_111 . V_120 = V_112 ;
V_111 . V_121 = V_122 ;
V_51 = F_44 ( V_96 , & V_111 ) ;
if ( F_4 ( V_51 ) ) {
V_59 = F_24 ( V_51 ) ;
F_23 ( V_29 , L_11 , V_59 ) ;
goto V_123;
}
V_3 -> V_50 . V_53 . V_51 = V_51 ;
memset ( V_116 , 0 , V_108 ) ;
F_7 ( V_109 , V_116 , V_39 ,
V_41 ) ;
V_38 = F_6 ( V_109 , V_116 , V_38 ) ;
F_8 ( V_32 , V_38 , V_34 . V_82 ) ;
F_8 ( V_32 , V_38 , V_34 . V_36 ) ;
V_113 = V_107 + V_119 ;
F_7 ( V_109 , V_116 , V_124 , 0 ) ;
F_7 ( V_109 , V_116 , V_125 , V_113 - 1 ) ;
V_115 = F_45 ( V_51 , V_116 ) ;
if ( F_4 ( V_115 ) ) {
V_59 = F_24 ( V_115 ) ;
F_23 ( V_29 , L_12 , V_59 ) ;
goto V_126;
}
V_3 -> V_50 . V_53 . V_127 = V_115 ;
memset ( V_116 , 0 , V_108 ) ;
F_7 ( V_109 , V_116 , V_39 , 0 ) ;
F_7 ( V_109 , V_116 , V_124 , V_113 ) ;
F_7 ( V_109 , V_116 , V_125 , V_113 + 1 ) ;
V_115 = F_45 ( V_51 , V_116 ) ;
if ( F_4 ( V_115 ) ) {
V_59 = F_24 ( V_115 ) ;
F_23 ( V_29 , L_13 , V_59 ) ;
goto V_128;
}
V_3 -> V_50 . V_53 . V_129 = V_115 ;
V_59 = F_33 ( V_3 ) ;
if ( V_59 )
goto V_130;
return 0 ;
V_130:
F_46 ( V_3 -> V_50 . V_53 . V_129 ) ;
V_128:
F_46 ( V_3 -> V_50 . V_53 . V_127 ) ;
V_126:
F_41 ( V_3 -> V_50 . V_53 . V_51 ) ;
V_123:
F_41 ( V_3 -> V_50 . V_51 ) ;
V_118:
V_117:
F_25 ( V_116 ) ;
return V_59 ;
}
static void F_47 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_50 . V_51 )
return;
F_15 ( V_3 -> V_29 , L_14 ) ;
F_13 ( V_3 -> V_50 . V_53 . V_93 ) ;
F_46 ( V_3 -> V_50 . V_53 . V_127 ) ;
F_46 ( V_3 -> V_50 . V_53 . V_129 ) ;
F_41 ( V_3 -> V_50 . V_53 . V_51 ) ;
F_40 ( V_3 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_110 V_111 = {} ;
struct V_94 * V_29 = V_3 -> V_29 ;
struct V_49 * V_131 ;
struct V_95 * V_132 ;
int V_59 = 0 ;
V_132 = F_35 ( V_29 , V_133 ) ;
if ( ! V_132 ) {
F_23 ( V_3 -> V_29 , L_15 ) ;
return - V_19 ;
}
V_111 . V_120 = V_29 -> V_134 . V_135 . V_136 + 2 ;
V_131 = F_44 ( V_132 , & V_111 ) ;
if ( F_4 ( V_131 ) ) {
V_59 = F_24 ( V_131 ) ;
F_23 ( V_3 -> V_29 , L_16 , V_59 ) ;
return V_59 ;
}
V_3 -> V_53 . V_131 = V_131 ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_137 * V_53 = & V_3 -> V_53 ;
F_41 ( V_53 -> V_131 ) ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_108 = F_43 ( V_109 ) ;
struct V_114 * V_115 ;
struct V_138 * V_134 = & V_3 -> V_29 -> V_134 ;
T_2 * V_116 ;
void * V_38 , * V_15 ;
int V_59 = 0 ;
int V_107 = V_134 -> V_135 . V_136 + 2 ;
V_116 = F_22 ( V_108 ) ;
if ( ! V_116 )
return - V_81 ;
memset ( V_116 , 0 , V_108 ) ;
F_7 ( V_109 , V_116 , V_39 ,
V_41 ) ;
V_38 = F_6 ( V_109 , V_116 , V_38 ) ;
V_15 = F_6 ( V_32 , V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
F_7 ( V_109 , V_116 , V_124 , 0 ) ;
F_7 ( V_109 , V_116 , V_125 , V_107 - 1 ) ;
V_115 = F_45 ( V_3 -> V_53 . V_131 , V_116 ) ;
if ( F_4 ( V_115 ) ) {
V_59 = F_24 ( V_115 ) ;
F_51 ( V_3 -> V_29 , L_17 , V_59 ) ;
goto V_64;
}
V_3 -> V_53 . V_139 = V_115 ;
V_64:
F_29 ( V_116 ) ;
return V_59 ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_46 ( V_3 -> V_53 . V_139 ) ;
}
struct V_1 *
F_53 ( struct V_2 * V_3 , int V_27 , T_2 V_140 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_80 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_18 ) ;
V_80 = F_2 ( - V_81 ) ;
goto V_64;
}
V_15 = F_6 ( V_32 , V_5 -> V_33 , V_34 ) ;
F_7 ( V_35 , V_15 , V_36 , V_27 ) ;
V_15 = F_6 ( V_32 , V_5 -> V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
V_5 -> V_39 = V_41 ;
V_9 . type = V_141 ;
V_9 . V_142 = V_140 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_53 . V_131 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) ) {
F_23 ( V_3 -> V_29 , L_19 , F_24 ( V_80 ) ) ;
goto V_64;
}
V_64:
F_25 ( V_5 ) ;
return V_80 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_59 , V_143 , V_136 = V_3 -> V_29 -> V_134 . V_135 . V_136 ;
if ( V_3 -> V_17 != V_144 ) {
F_23 ( V_3 -> V_29 , L_20 ) ;
return - V_145 ;
}
F_55 ( V_3 ) ;
V_59 = F_56 ( V_3 , V_136 , V_18 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_21 , V_59 ) ;
V_143 = F_56 ( V_3 , V_136 , V_144 ) ;
if ( V_143 )
F_23 ( V_3 -> V_29 , L_22 , V_143 ) ;
}
if ( V_3 -> V_53 . V_146 == V_147 ) {
if ( F_57 ( V_3 ,
V_136 ,
& V_3 -> V_53 . V_146 ) ) {
V_3 -> V_53 . V_146 = V_148 ;
F_23 ( V_3 -> V_29 , L_23 ) ;
}
}
return V_59 ;
}
int F_58 ( struct V_2 * V_3 , int V_107 )
{
struct V_56 * V_57 ;
int V_27 ;
int V_59 ;
F_59 () ;
F_60 ( V_3 -> V_29 , V_149 ) ;
F_61 () ;
V_59 = F_42 ( V_3 , V_107 ) ;
if ( V_59 )
goto V_150;
V_59 = F_48 ( V_3 ) ;
if ( V_59 )
goto V_151;
V_59 = F_50 ( V_3 ) ;
if ( V_59 )
goto V_152;
for ( V_27 = 0 ; V_27 < V_107 ; V_27 ++ ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_59 = V_57 -> V_153 ( V_3 , V_57 ) ;
if ( V_59 )
goto V_154;
}
return 0 ;
V_154:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_57 -> V_155 ( V_3 , V_57 ) ;
}
F_52 ( V_3 ) ;
V_152:
F_49 ( V_3 ) ;
V_151:
F_47 ( V_3 ) ;
V_150:
F_59 () ;
F_62 ( V_3 -> V_29 , V_149 ) ;
F_61 () ;
return V_59 ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_59 , V_143 , V_136 = V_3 -> V_29 -> V_134 . V_135 . V_136 ;
F_55 ( V_3 ) ;
V_59 = F_56 ( V_3 , V_136 , V_144 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_24 , V_59 ) ;
V_143 = F_56 ( V_3 , V_136 , V_18 ) ;
if ( V_143 )
F_23 ( V_3 -> V_29 , L_25 , V_59 ) ;
}
F_59 () ;
F_62 ( V_3 -> V_29 , V_149 ) ;
F_61 () ;
return V_59 ;
}
void F_64 ( struct V_2 * V_3 , int V_107 )
{
struct V_56 * V_57 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_107 ; V_27 ++ ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_57 -> V_155 ( V_3 , V_57 ) ;
}
F_52 ( V_3 ) ;
F_49 ( V_3 ) ;
F_47 ( V_3 ) ;
}
static int F_65 ( T_3 V_17 , T_3 * V_156 )
{
switch ( V_17 ) {
case V_157 :
* V_156 = V_144 ;
break;
case V_158 :
* V_156 = V_18 ;
break;
default:
return - V_145 ;
}
return 0 ;
}
static int F_66 ( T_3 V_156 , T_3 * V_17 )
{
switch ( V_156 ) {
case V_144 :
* V_17 = V_157 ;
break;
case V_18 :
* V_17 = V_158 ;
break;
default:
return - V_145 ;
}
return 0 ;
}
static int F_67 ( T_1 V_17 , T_1 * V_156 )
{
switch ( V_17 ) {
case V_159 :
* V_156 = V_147 ;
break;
case V_160 :
* V_156 = V_148 ;
break;
case V_161 :
* V_156 = V_162 ;
break;
case V_163 :
* V_156 = V_164 ;
break;
default:
return - V_145 ;
}
return 0 ;
}
static int F_68 ( T_1 V_156 , T_1 * V_17 )
{
switch ( V_156 ) {
case V_147 :
* V_17 = V_159 ;
break;
case V_148 :
* V_17 = V_160 ;
break;
case V_162 :
* V_17 = V_161 ;
break;
case V_164 :
* V_17 = V_163 ;
break;
default:
return - V_145 ;
}
return 0 ;
}
static int F_69 ( struct V_165 * V_165 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
if ( F_37 ( V_29 , V_166 ) != V_167 )
return - V_19 ;
if ( ! F_37 ( V_29 , V_168 ) )
return - V_19 ;
if ( V_29 -> V_134 . V_169 -> V_17 == V_170 )
return - V_19 ;
return 0 ;
}
int F_71 ( struct V_165 * V_165 , T_3 V_17 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
T_3 V_171 , V_156 = 0 ;
int V_59 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
V_171 = V_29 -> V_134 . V_169 -> V_17 ;
if ( F_65 ( V_17 , & V_156 ) )
return - V_145 ;
if ( V_171 == V_156 )
return 0 ;
if ( V_17 == V_158 )
return F_54 ( V_29 -> V_134 . V_169 ) ;
else if ( V_17 == V_157 )
return F_63 ( V_29 -> V_134 . V_169 ) ;
else
return - V_145 ;
}
int F_72 ( struct V_165 * V_165 , T_3 * V_17 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
int V_59 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
return F_66 ( V_29 -> V_134 . V_169 -> V_17 , V_17 ) ;
}
int F_73 ( struct V_165 * V_165 , T_1 V_17 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
struct V_2 * V_3 = V_29 -> V_134 . V_169 ;
int V_59 , V_27 ;
T_1 V_156 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
switch ( F_74 ( V_29 , V_172 ) ) {
case V_173 :
if ( V_17 == V_159 )
return 0 ;
case V_174 :
F_23 ( V_29 , L_26 ) ;
return - V_19 ;
case V_175 :
break;
}
if ( V_3 -> V_53 . V_54 > 0 ) {
F_23 ( V_29 , L_27 ) ;
return - V_19 ;
}
V_59 = F_67 ( V_17 , & V_156 ) ;
if ( V_59 )
goto V_64;
for ( V_27 = 1 ; V_27 < V_3 -> V_61 ; V_27 ++ ) {
V_59 = F_75 ( V_29 , V_27 , V_156 ) ;
if ( V_59 ) {
F_23 ( V_29 , L_28 ,
V_27 ) ;
goto V_176;
}
}
V_3 -> V_53 . V_146 = V_156 ;
return 0 ;
V_176:
while ( -- V_27 > 0 )
F_75 ( V_29 ,
V_27 ,
V_3 -> V_53 . V_146 ) ;
V_64:
return V_59 ;
}
int F_76 ( struct V_165 * V_165 , T_1 * V_17 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
struct V_2 * V_3 = V_29 -> V_134 . V_169 ;
int V_59 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
return F_68 ( V_3 -> V_53 . V_146 , V_17 ) ;
}
int F_57 ( struct V_2 * V_3 , int V_177 , T_1 * V_17 )
{
T_1 V_178 , V_156 = V_148 ;
struct V_94 * V_29 = V_3 -> V_29 ;
int V_27 ;
if ( ! F_37 ( V_29 , V_168 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_170 )
return - V_19 ;
switch ( F_74 ( V_29 , V_172 ) ) {
case V_173 :
V_156 = V_147 ;
goto V_64;
case V_174 :
V_156 = V_148 ;
goto V_64;
case V_175 :
goto V_179;
}
V_179:
for ( V_27 = 1 ; V_27 <= V_177 ; V_27 ++ ) {
F_77 ( V_29 , V_27 , & V_156 ) ;
if ( V_27 > 1 && V_178 != V_156 )
return - V_145 ;
V_178 = V_156 ;
}
V_64:
* V_17 = V_156 ;
return 0 ;
}
int F_78 ( struct V_165 * V_165 , T_1 V_103 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
struct V_2 * V_3 = V_29 -> V_134 . V_169 ;
int V_59 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
if ( V_103 != V_104 &&
( ! F_36 ( V_29 , V_103 ) ||
! F_36 ( V_29 , V_180 ) ) )
return - V_19 ;
if ( V_103 && V_103 != V_181 )
return - V_19 ;
if ( V_3 -> V_17 == V_144 ) {
V_3 -> V_53 . V_103 = V_103 ;
return 0 ;
}
if ( V_3 -> V_53 . V_103 == V_103 )
return 0 ;
if ( V_3 -> V_53 . V_54 > 0 ) {
F_23 ( V_29 , L_29 ) ;
return - V_19 ;
}
F_40 ( V_3 ) ;
V_3 -> V_53 . V_103 = V_103 ;
V_59 = F_34 ( V_3 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_30 , V_59 ) ;
V_3 -> V_53 . V_103 = ! V_103 ;
( void ) F_34 ( V_3 ) ;
}
return V_59 ;
}
int F_79 ( struct V_165 * V_165 , T_1 * V_103 )
{
struct V_94 * V_29 = F_70 ( V_165 ) ;
struct V_2 * V_3 = V_29 -> V_134 . V_169 ;
int V_59 ;
V_59 = F_69 ( V_165 ) ;
if ( V_59 )
return V_59 ;
* V_103 = V_3 -> V_53 . V_103 ;
return 0 ;
}
void F_80 ( struct V_2 * V_3 ,
int V_182 ,
struct V_56 * V_183 )
{
struct V_137 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ V_182 ] ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_153 = V_183 -> V_153 ;
V_57 -> V_155 = V_183 -> V_155 ;
V_57 -> V_27 = V_183 -> V_27 ;
V_57 -> V_184 = V_183 -> V_184 ;
F_81 ( V_57 -> V_185 , V_183 -> V_185 ) ;
F_82 ( & V_57 -> V_92 ) ;
V_57 -> V_63 = true ;
}
void F_83 ( struct V_2 * V_3 ,
int V_182 )
{
struct V_137 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ V_182 ] ;
if ( V_3 -> V_17 == V_18 && V_3 -> V_186 [ V_182 ] . V_187 )
V_57 -> V_155 ( V_3 , V_57 ) ;
V_57 -> V_63 = false ;
}
struct V_188 * F_84 ( struct V_2 * V_3 )
{
#define F_85 0
struct V_137 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ F_85 ] ;
return V_57 -> V_184 ;
}
