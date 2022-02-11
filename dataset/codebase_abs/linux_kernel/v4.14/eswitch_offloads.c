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
V_5 = F_22 ( sizeof( * V_5 ) , V_81 ) ;
if ( ! V_5 ) {
V_80 = F_2 ( - V_82 ) ;
goto V_64;
}
V_15 = F_6 ( V_32 , V_5 -> V_33 , V_34 ) ;
F_7 ( V_35 , V_15 , V_83 , V_79 ) ;
F_7 ( V_35 , V_15 , V_36 , 0x0 ) ;
V_15 = F_6 ( V_32 , V_5 -> V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_83 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
V_5 -> V_39 = V_41 ;
V_9 . type = V_24 ;
V_9 . V_25 = V_27 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_50 . V_53 . V_51 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) )
F_23 ( V_3 -> V_29 , L_4 , F_24 ( V_80 ) ) ;
V_64:
F_25 ( V_5 ) ;
return V_80 ;
}
void F_26 ( struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_84 * V_85 , * V_86 ;
if ( V_3 -> V_17 != V_18 )
return;
F_27 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_13 ( V_85 -> V_87 ) ;
F_28 ( & V_85 -> V_88 ) ;
F_29 ( V_85 ) ;
}
}
int F_30 ( struct V_2 * V_3 ,
struct V_56 * V_57 ,
T_3 * V_89 , int V_90 )
{
struct V_1 * V_80 ;
struct V_84 * V_85 ;
int V_59 ;
int V_16 ;
if ( V_3 -> V_17 != V_18 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_90 ; V_16 ++ ) {
V_85 = F_31 ( sizeof( * V_85 ) , V_81 ) ;
if ( ! V_85 ) {
V_59 = - V_82 ;
goto V_91;
}
V_80 = F_21 ( V_3 ,
V_57 -> V_27 ,
V_89 [ V_16 ] ) ;
if ( F_4 ( V_80 ) ) {
V_59 = F_24 ( V_80 ) ;
F_29 ( V_85 ) ;
goto V_91;
}
V_85 -> V_87 = V_80 ;
F_32 ( & V_85 -> V_88 , & V_57 -> V_92 ) ;
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
V_5 = F_22 ( sizeof( * V_5 ) , V_81 ) ;
if ( ! V_5 ) {
V_59 = - V_82 ;
goto V_64;
}
V_9 . type = V_24 ;
V_9 . V_25 = 0 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_50 . V_53 . V_51 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) ) {
V_59 = F_24 ( V_80 ) ;
F_23 ( V_3 -> V_29 , L_5 , V_59 ) ;
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
T_2 V_99 = ( F_35 ( V_29 , V_100 ) << 16 ) |
F_35 ( V_29 , V_101 ) ;
V_96 = F_36 ( V_29 , V_102 ) ;
if ( ! V_96 ) {
F_23 ( V_29 , L_6 ) ;
V_59 = - V_19 ;
goto V_64;
}
F_15 ( V_29 , L_7 ,
F_37 ( V_29 , V_103 ) ,
V_99 , V_104 ) ;
V_97 = F_38 ( int , V_99 * V_104 ,
1 << F_37 ( V_29 , V_103 ) ) ;
if ( V_3 -> V_53 . V_105 != V_106 )
V_98 |= V_107 ;
V_51 = F_39 ( V_96 , V_108 ,
V_97 ,
V_104 , 0 ,
V_98 ) ;
if ( F_4 ( V_51 ) ) {
V_59 = F_24 ( V_51 ) ;
F_23 ( V_29 , L_8 , V_59 ) ;
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
static int F_42 ( struct V_2 * V_3 , int V_109 )
{
int V_110 = F_43 ( V_111 ) ;
struct V_112 V_113 = {} ;
struct V_94 * V_29 = V_3 -> V_29 ;
struct V_95 * V_96 ;
struct V_49 * V_51 = NULL ;
int V_114 , V_115 , V_59 = 0 ;
struct V_116 * V_117 ;
void * V_38 ;
T_2 * V_118 ;
F_15 ( V_3 -> V_29 , L_9 ) ;
V_118 = F_22 ( V_110 , V_81 ) ;
if ( ! V_118 )
return - V_82 ;
V_96 = F_36 ( V_29 , V_102 ) ;
if ( ! V_96 ) {
F_23 ( V_29 , L_6 ) ;
V_59 = - V_19 ;
goto V_119;
}
V_59 = F_34 ( V_3 ) ;
if ( V_59 )
goto V_120;
V_114 = V_109 + V_121 + 1 ;
V_113 . V_122 = V_114 ;
V_113 . V_123 = V_124 ;
V_51 = F_44 ( V_96 , & V_113 ) ;
if ( F_4 ( V_51 ) ) {
V_59 = F_24 ( V_51 ) ;
F_23 ( V_29 , L_10 , V_59 ) ;
goto V_125;
}
V_3 -> V_50 . V_53 . V_51 = V_51 ;
memset ( V_118 , 0 , V_110 ) ;
F_7 ( V_111 , V_118 , V_39 ,
V_41 ) ;
V_38 = F_6 ( V_111 , V_118 , V_38 ) ;
F_8 ( V_32 , V_38 , V_34 . V_83 ) ;
F_8 ( V_32 , V_38 , V_34 . V_36 ) ;
V_115 = V_109 + V_121 ;
F_7 ( V_111 , V_118 , V_126 , 0 ) ;
F_7 ( V_111 , V_118 , V_127 , V_115 - 1 ) ;
V_117 = F_45 ( V_51 , V_118 ) ;
if ( F_4 ( V_117 ) ) {
V_59 = F_24 ( V_117 ) ;
F_23 ( V_29 , L_11 , V_59 ) ;
goto V_128;
}
V_3 -> V_50 . V_53 . V_129 = V_117 ;
memset ( V_118 , 0 , V_110 ) ;
F_7 ( V_111 , V_118 , V_39 , 0 ) ;
F_7 ( V_111 , V_118 , V_126 , V_115 ) ;
F_7 ( V_111 , V_118 , V_127 , V_115 + 1 ) ;
V_117 = F_45 ( V_51 , V_118 ) ;
if ( F_4 ( V_117 ) ) {
V_59 = F_24 ( V_117 ) ;
F_23 ( V_29 , L_12 , V_59 ) ;
goto V_130;
}
V_3 -> V_50 . V_53 . V_131 = V_117 ;
V_59 = F_33 ( V_3 ) ;
if ( V_59 )
goto V_132;
return 0 ;
V_132:
F_46 ( V_3 -> V_50 . V_53 . V_131 ) ;
V_130:
F_46 ( V_3 -> V_50 . V_53 . V_129 ) ;
V_128:
F_41 ( V_3 -> V_50 . V_53 . V_51 ) ;
V_125:
F_41 ( V_3 -> V_50 . V_51 ) ;
V_120:
V_119:
F_25 ( V_118 ) ;
return V_59 ;
}
static void F_47 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_50 . V_51 )
return;
F_15 ( V_3 -> V_29 , L_13 ) ;
F_13 ( V_3 -> V_50 . V_53 . V_93 ) ;
F_46 ( V_3 -> V_50 . V_53 . V_129 ) ;
F_46 ( V_3 -> V_50 . V_53 . V_131 ) ;
F_41 ( V_3 -> V_50 . V_53 . V_51 ) ;
F_40 ( V_3 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_112 V_113 = {} ;
struct V_94 * V_29 = V_3 -> V_29 ;
struct V_49 * V_133 ;
struct V_95 * V_134 ;
int V_59 = 0 ;
V_134 = F_36 ( V_29 , V_135 ) ;
if ( ! V_134 ) {
F_23 ( V_3 -> V_29 , L_14 ) ;
return - V_19 ;
}
V_113 . V_122 = V_29 -> V_136 . V_137 . V_138 + 2 ;
V_133 = F_44 ( V_134 , & V_113 ) ;
if ( F_4 ( V_133 ) ) {
V_59 = F_24 ( V_133 ) ;
F_23 ( V_3 -> V_29 , L_15 , V_59 ) ;
return V_59 ;
}
V_3 -> V_53 . V_133 = V_133 ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_139 * V_53 = & V_3 -> V_53 ;
F_41 ( V_53 -> V_133 ) ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_110 = F_43 ( V_111 ) ;
struct V_116 * V_117 ;
struct V_140 * V_136 = & V_3 -> V_29 -> V_136 ;
T_2 * V_118 ;
void * V_38 , * V_15 ;
int V_59 = 0 ;
int V_109 = V_136 -> V_137 . V_138 + 2 ;
V_118 = F_22 ( V_110 , V_81 ) ;
if ( ! V_118 )
return - V_82 ;
memset ( V_118 , 0 , V_110 ) ;
F_7 ( V_111 , V_118 , V_39 ,
V_41 ) ;
V_38 = F_6 ( V_111 , V_118 , V_38 ) ;
V_15 = F_6 ( V_32 , V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
F_7 ( V_111 , V_118 , V_126 , 0 ) ;
F_7 ( V_111 , V_118 , V_127 , V_109 - 1 ) ;
V_117 = F_45 ( V_3 -> V_53 . V_133 , V_118 ) ;
if ( F_4 ( V_117 ) ) {
V_59 = F_24 ( V_117 ) ;
F_51 ( V_3 -> V_29 , L_16 , V_59 ) ;
goto V_64;
}
V_3 -> V_53 . V_141 = V_117 ;
V_64:
F_29 ( V_118 ) ;
return V_59 ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_46 ( V_3 -> V_53 . V_141 ) ;
}
struct V_1 *
F_53 ( struct V_2 * V_3 , int V_27 , T_2 V_142 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_80 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_22 ( sizeof( * V_5 ) , V_81 ) ;
if ( ! V_5 ) {
V_80 = F_2 ( - V_82 ) ;
goto V_64;
}
V_15 = F_6 ( V_32 , V_5 -> V_33 , V_34 ) ;
F_7 ( V_35 , V_15 , V_36 , V_27 ) ;
V_15 = F_6 ( V_32 , V_5 -> V_38 , V_34 ) ;
F_8 ( V_35 , V_15 , V_36 ) ;
V_5 -> V_39 = V_41 ;
V_9 . type = V_143 ;
V_9 . V_144 = V_142 ;
V_11 . V_20 = V_23 ;
V_80 = F_9 ( V_3 -> V_53 . V_133 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_80 ) ) {
F_23 ( V_3 -> V_29 , L_17 , F_24 ( V_80 ) ) ;
goto V_64;
}
V_64:
F_25 ( V_5 ) ;
return V_80 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_59 , V_145 , V_138 = V_3 -> V_29 -> V_136 . V_137 . V_138 ;
if ( V_3 -> V_17 != V_146 ) {
F_23 ( V_3 -> V_29 , L_18 ) ;
return - V_147 ;
}
F_55 ( V_3 ) ;
V_59 = F_56 ( V_3 , V_138 , V_18 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_19 , V_59 ) ;
V_145 = F_56 ( V_3 , V_138 , V_146 ) ;
if ( V_145 )
F_23 ( V_3 -> V_29 , L_20 , V_145 ) ;
}
if ( V_3 -> V_53 . V_148 == V_149 ) {
if ( F_57 ( V_3 ,
V_138 ,
& V_3 -> V_53 . V_148 ) ) {
V_3 -> V_53 . V_148 = V_150 ;
F_23 ( V_3 -> V_29 , L_21 ) ;
}
}
return V_59 ;
}
int F_58 ( struct V_2 * V_3 , int V_109 )
{
struct V_56 * V_57 ;
int V_27 ;
int V_59 ;
F_59 () ;
F_60 ( V_3 -> V_29 , V_151 ) ;
F_61 () ;
V_59 = F_42 ( V_3 , V_109 ) ;
if ( V_59 )
goto V_152;
V_59 = F_48 ( V_3 ) ;
if ( V_59 )
goto V_153;
V_59 = F_50 ( V_3 ) ;
if ( V_59 )
goto V_154;
for ( V_27 = 0 ; V_27 < V_109 ; V_27 ++ ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_59 = V_57 -> V_155 ( V_3 , V_57 ) ;
if ( V_59 )
goto V_156;
}
return 0 ;
V_156:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_57 -> V_157 ( V_3 , V_57 ) ;
}
F_52 ( V_3 ) ;
V_154:
F_49 ( V_3 ) ;
V_153:
F_47 ( V_3 ) ;
V_152:
F_59 () ;
F_62 ( V_3 -> V_29 , V_151 ) ;
F_61 () ;
return V_59 ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_59 , V_145 , V_138 = V_3 -> V_29 -> V_136 . V_137 . V_138 ;
F_55 ( V_3 ) ;
V_59 = F_56 ( V_3 , V_138 , V_146 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_22 , V_59 ) ;
V_145 = F_56 ( V_3 , V_138 , V_18 ) ;
if ( V_145 )
F_23 ( V_3 -> V_29 , L_23 , V_59 ) ;
}
F_59 () ;
F_62 ( V_3 -> V_29 , V_151 ) ;
F_61 () ;
return V_59 ;
}
void F_64 ( struct V_2 * V_3 , int V_109 )
{
struct V_56 * V_57 ;
int V_27 ;
for ( V_27 = V_109 - 1 ; V_27 >= 0 ; V_27 -- ) {
V_57 = & V_3 -> V_53 . V_62 [ V_27 ] ;
if ( ! V_57 -> V_63 )
continue;
V_57 -> V_157 ( V_3 , V_57 ) ;
}
F_52 ( V_3 ) ;
F_49 ( V_3 ) ;
F_47 ( V_3 ) ;
}
static int F_65 ( T_3 V_17 , T_3 * V_158 )
{
switch ( V_17 ) {
case V_159 :
* V_158 = V_146 ;
break;
case V_160 :
* V_158 = V_18 ;
break;
default:
return - V_147 ;
}
return 0 ;
}
static int F_66 ( T_3 V_158 , T_3 * V_17 )
{
switch ( V_158 ) {
case V_146 :
* V_17 = V_159 ;
break;
case V_18 :
* V_17 = V_160 ;
break;
default:
return - V_147 ;
}
return 0 ;
}
static int F_67 ( T_1 V_17 , T_1 * V_158 )
{
switch ( V_17 ) {
case V_161 :
* V_158 = V_149 ;
break;
case V_162 :
* V_158 = V_150 ;
break;
case V_163 :
* V_158 = V_164 ;
break;
case V_165 :
* V_158 = V_166 ;
break;
default:
return - V_147 ;
}
return 0 ;
}
static int F_68 ( T_1 V_158 , T_1 * V_17 )
{
switch ( V_158 ) {
case V_149 :
* V_17 = V_161 ;
break;
case V_150 :
* V_17 = V_162 ;
break;
case V_164 :
* V_17 = V_163 ;
break;
case V_166 :
* V_17 = V_165 ;
break;
default:
return - V_147 ;
}
return 0 ;
}
static int F_69 ( struct V_167 * V_167 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
if ( F_35 ( V_29 , V_168 ) != V_169 )
return - V_19 ;
if ( ! F_35 ( V_29 , V_170 ) )
return - V_19 ;
if ( V_29 -> V_136 . V_171 -> V_17 == V_172 )
return - V_19 ;
return 0 ;
}
int F_71 ( struct V_167 * V_167 , T_3 V_17 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
T_3 V_173 , V_158 = 0 ;
int V_59 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
V_173 = V_29 -> V_136 . V_171 -> V_17 ;
if ( F_65 ( V_17 , & V_158 ) )
return - V_147 ;
if ( V_173 == V_158 )
return 0 ;
if ( V_17 == V_160 )
return F_54 ( V_29 -> V_136 . V_171 ) ;
else if ( V_17 == V_159 )
return F_63 ( V_29 -> V_136 . V_171 ) ;
else
return - V_147 ;
}
int F_72 ( struct V_167 * V_167 , T_3 * V_17 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
int V_59 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
return F_66 ( V_29 -> V_136 . V_171 -> V_17 , V_17 ) ;
}
int F_73 ( struct V_167 * V_167 , T_1 V_17 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
struct V_2 * V_3 = V_29 -> V_136 . V_171 ;
int V_59 , V_27 ;
T_1 V_158 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
switch ( F_74 ( V_29 , V_174 ) ) {
case V_175 :
if ( V_17 == V_161 )
return 0 ;
case V_176 :
F_23 ( V_29 , L_24 ) ;
return - V_19 ;
case V_177 :
break;
}
if ( V_3 -> V_53 . V_54 > 0 ) {
F_23 ( V_29 , L_25 ) ;
return - V_19 ;
}
V_59 = F_67 ( V_17 , & V_158 ) ;
if ( V_59 )
goto V_64;
for ( V_27 = 1 ; V_27 < V_3 -> V_61 ; V_27 ++ ) {
V_59 = F_75 ( V_29 , V_27 , V_158 ) ;
if ( V_59 ) {
F_23 ( V_29 , L_26 ,
V_27 ) ;
goto V_178;
}
}
V_3 -> V_53 . V_148 = V_158 ;
return 0 ;
V_178:
while ( -- V_27 > 0 )
F_75 ( V_29 ,
V_27 ,
V_3 -> V_53 . V_148 ) ;
V_64:
return V_59 ;
}
int F_76 ( struct V_167 * V_167 , T_1 * V_17 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
struct V_2 * V_3 = V_29 -> V_136 . V_171 ;
int V_59 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
return F_68 ( V_3 -> V_53 . V_148 , V_17 ) ;
}
int F_57 ( struct V_2 * V_3 , int V_179 , T_1 * V_17 )
{
T_1 V_180 , V_158 = V_150 ;
struct V_94 * V_29 = V_3 -> V_29 ;
int V_27 ;
if ( ! F_35 ( V_29 , V_170 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_172 )
return - V_19 ;
switch ( F_74 ( V_29 , V_174 ) ) {
case V_175 :
V_158 = V_149 ;
goto V_64;
case V_176 :
V_158 = V_150 ;
goto V_64;
case V_177 :
goto V_181;
}
V_181:
for ( V_27 = 1 ; V_27 <= V_179 ; V_27 ++ ) {
F_77 ( V_29 , V_27 , & V_158 ) ;
if ( V_27 > 1 && V_180 != V_158 )
return - V_147 ;
V_180 = V_158 ;
}
V_64:
* V_17 = V_158 ;
return 0 ;
}
int F_78 ( struct V_167 * V_167 , T_1 V_105 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
struct V_2 * V_3 = V_29 -> V_136 . V_171 ;
int V_59 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
if ( V_105 != V_106 &&
( ! F_37 ( V_29 , V_105 ) ||
! F_37 ( V_29 , V_182 ) ) )
return - V_19 ;
if ( V_105 && V_105 != V_183 )
return - V_19 ;
if ( V_3 -> V_17 == V_146 ) {
V_3 -> V_53 . V_105 = V_105 ;
return 0 ;
}
if ( V_3 -> V_53 . V_105 == V_105 )
return 0 ;
if ( V_3 -> V_53 . V_54 > 0 ) {
F_23 ( V_29 , L_27 ) ;
return - V_19 ;
}
F_40 ( V_3 ) ;
V_3 -> V_53 . V_105 = V_105 ;
V_59 = F_34 ( V_3 ) ;
if ( V_59 ) {
F_23 ( V_3 -> V_29 , L_28 , V_59 ) ;
V_3 -> V_53 . V_105 = ! V_105 ;
( void ) F_34 ( V_3 ) ;
}
return V_59 ;
}
int F_79 ( struct V_167 * V_167 , T_1 * V_105 )
{
struct V_94 * V_29 = F_70 ( V_167 ) ;
struct V_2 * V_3 = V_29 -> V_136 . V_171 ;
int V_59 ;
V_59 = F_69 ( V_167 ) ;
if ( V_59 )
return V_59 ;
* V_105 = V_3 -> V_53 . V_105 ;
return 0 ;
}
void F_80 ( struct V_2 * V_3 ,
int V_184 ,
struct V_56 * V_185 )
{
struct V_139 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ V_184 ] ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_155 = V_185 -> V_155 ;
V_57 -> V_157 = V_185 -> V_157 ;
V_57 -> V_27 = V_185 -> V_27 ;
V_57 -> V_186 = V_185 -> V_186 ;
F_81 ( V_57 -> V_187 , V_185 -> V_187 ) ;
F_82 ( & V_57 -> V_92 ) ;
V_57 -> V_63 = true ;
}
void F_83 ( struct V_2 * V_3 ,
int V_184 )
{
struct V_139 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ V_184 ] ;
if ( V_3 -> V_17 == V_18 && V_3 -> V_188 [ V_184 ] . V_189 )
V_57 -> V_157 ( V_3 , V_57 ) ;
V_57 -> V_63 = false ;
}
struct V_190 * F_84 ( struct V_2 * V_3 )
{
#define F_85 0
struct V_139 * V_53 = & V_3 -> V_53 ;
struct V_56 * V_57 ;
V_57 = & V_53 -> V_62 [ F_85 ] ;
return V_57 -> V_186 ;
}
