static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof *V_6 , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_4 = V_4 ;
F_3 ( & V_2 -> V_9 ) ;
F_4 ( & V_6 -> V_10 , & V_2 -> V_11 ) ;
F_5 ( & V_2 -> V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_3 ( & V_2 -> V_9 ) ;
F_7 (i_cm_id, &rds_iwdev->cm_id_list, list) {
if ( V_6 -> V_4 == V_4 ) {
F_8 ( & V_6 -> V_10 ) ;
F_9 ( V_6 ) ;
break;
}
}
F_5 ( & V_2 -> V_9 ) ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_12 * V_13 , * V_14 ;
struct V_1 * V_15 ;
struct V_3 * V_16 ;
int V_17 ;
V_13 = (struct V_12 * ) & V_4 -> V_18 . V_19 . V_13 ;
V_14 = (struct V_12 * ) & V_4 -> V_18 . V_19 . V_14 ;
V_17 = F_11 ( V_13 , V_14 , & V_15 , & V_16 ) ;
if ( V_17 )
F_6 ( V_2 , V_4 ) ;
return F_1 ( V_2 , V_4 ) ;
}
void F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
F_3 ( & V_25 ) ;
F_13 ( F_14 ( & V_26 ) ) ;
F_13 ( F_14 ( & V_23 -> V_27 ) ) ;
F_8 ( & V_23 -> V_27 ) ;
F_15 ( & V_2 -> V_9 ) ;
F_4 ( & V_23 -> V_27 , & V_2 -> V_28 ) ;
F_16 ( & V_2 -> V_9 ) ;
F_5 ( & V_25 ) ;
V_23 -> V_2 = V_2 ;
}
void F_17 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
F_15 ( & V_25 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_13 ( F_14 ( & V_23 -> V_27 ) ) ;
F_8 ( & V_23 -> V_27 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_4 ( & V_23 -> V_27 , & V_26 ) ;
F_16 ( & V_25 ) ;
F_6 ( V_23 -> V_2 , V_23 -> V_6 ) ;
V_23 -> V_2 = NULL ;
}
void F_18 ( struct V_29 * V_10 , T_1 * V_30 )
{
struct V_22 * V_23 , * V_31 ;
F_19 ( V_32 ) ;
F_3 ( V_30 ) ;
F_20 ( V_10 , & V_32 ) ;
F_21 ( V_10 ) ;
F_5 ( V_30 ) ;
F_22 (ic, _ic, &tmp_list, iw_node)
F_23 ( V_23 -> V_21 ) ;
}
static void F_24 ( struct V_33 * V_34 ,
struct V_35 * V_10 , unsigned int V_36 )
{
V_34 -> V_10 = V_10 ;
V_34 -> V_37 = V_36 ;
V_34 -> V_38 = 0 ;
V_34 -> V_39 = 0 ;
V_34 -> V_40 = 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
int V_43 , V_44 ;
F_26 ( V_34 -> V_38 ) ;
V_34 -> V_38 = F_27 ( V_42 , V_34 -> V_10 , V_34 -> V_37 , V_45 ) ;
if ( F_28 ( ! V_34 -> V_38 ) ) {
F_29 ( V_46 L_1 ) ;
return - V_47 ;
}
V_34 -> V_40 = 0 ;
V_34 -> V_39 = 0 ;
V_44 = - V_48 ;
for ( V_43 = 0 ; V_43 < V_34 -> V_38 ; ++ V_43 ) {
unsigned int V_38 = F_30 ( V_42 , & V_34 -> V_10 [ V_43 ] ) ;
T_2 V_49 = F_31 ( V_42 , & V_34 -> V_10 [ V_43 ] ) ;
T_2 V_50 ;
V_34 -> V_40 += V_38 ;
V_50 = V_49 + V_38 ;
if ( V_49 & V_51 ) {
if ( V_43 > 0 )
goto V_52;
V_49 &= ~ V_51 ;
}
if ( V_50 & V_51 ) {
if ( V_43 < V_34 -> V_38 - 1 )
goto V_52;
V_50 = ( V_50 + V_51 ) & ~ V_51 ;
}
V_34 -> V_39 += ( V_50 - V_49 ) >> V_53 ;
}
if ( V_34 -> V_39 > V_54 )
goto V_52;
return 0 ;
V_52:
F_32 ( V_2 -> V_42 , V_34 -> V_10 , V_34 -> V_37 , V_45 ) ;
V_34 -> V_38 = 0 ;
return V_44 ;
}
struct V_55 * F_33 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
V_56 = F_34 ( sizeof( * V_56 ) , V_7 ) ;
if ( ! V_56 ) {
F_29 ( V_46 L_2 ) ;
return F_35 ( - V_8 ) ;
}
V_56 -> V_57 = V_2 ;
F_21 ( & V_56 -> V_58 ) ;
F_21 ( & V_56 -> V_59 ) ;
F_36 ( & V_56 -> V_60 ) ;
F_37 ( & V_56 -> V_30 ) ;
F_38 ( & V_56 -> V_61 , V_62 ) ;
V_56 -> V_63 = V_54 ;
V_56 -> V_64 = V_65 ;
V_56 -> V_66 = V_56 -> V_64 * V_56 -> V_63 / 4 ;
V_56 -> V_67 = V_54 ;
V_56 -> V_68 = V_56 -> V_64 * 3 / 4 ;
return V_56 ;
}
void F_39 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_55 * V_56 = V_2 -> V_71 ;
V_70 -> V_72 = V_56 -> V_64 ;
V_70 -> V_73 = V_56 -> V_67 ;
}
void F_40 ( struct V_55 * V_56 )
{
F_41 ( V_74 ) ;
F_42 ( V_56 , 1 ) ;
F_13 ( F_43 ( & V_56 -> V_75 ) ) ;
F_13 ( F_43 ( & V_56 -> V_76 ) ) ;
F_9 ( V_56 ) ;
}
static inline struct V_77 * F_44 ( struct V_55 * V_56 )
{
struct V_77 * V_78 = NULL ;
unsigned long V_79 ;
F_45 ( & V_56 -> V_30 , V_79 ) ;
if ( ! F_14 ( & V_56 -> V_59 ) ) {
V_78 = F_46 ( V_56 -> V_59 . V_80 , struct V_77 , V_81 . V_82 ) ;
F_47 ( & V_78 -> V_81 . V_82 ) ;
}
F_48 ( & V_56 -> V_30 , V_79 ) ;
return V_78 ;
}
static struct V_77 * F_49 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_71 ;
struct V_77 * V_78 = NULL ;
int V_83 = 0 , V_84 = 0 ;
while ( 1 ) {
V_78 = F_44 ( V_56 ) ;
if ( V_78 )
return V_78 ;
if ( F_50 ( & V_56 -> V_75 ) <= V_56 -> V_64 )
break;
F_51 ( & V_56 -> V_75 ) ;
if ( ++ V_84 > 2 ) {
F_52 ( V_85 ) ;
return F_35 ( - V_86 ) ;
}
F_52 ( V_87 ) ;
F_42 ( V_56 , 0 ) ;
}
V_78 = F_34 ( sizeof( * V_78 ) , V_7 ) ;
if ( ! V_78 ) {
V_83 = - V_8 ;
goto V_88;
}
F_37 ( & V_78 -> V_81 . V_89 ) ;
F_21 ( & V_78 -> V_81 . V_82 ) ;
V_78 -> V_81 . V_90 = V_78 ;
V_83 = F_53 ( V_56 , V_78 ) ;
if ( V_83 )
goto V_88;
F_52 ( V_91 ) ;
return V_78 ;
V_88:
if ( V_78 ) {
F_54 ( V_56 , V_78 ) ;
F_9 ( V_78 ) ;
}
F_51 ( & V_56 -> V_75 ) ;
return F_35 ( V_83 ) ;
}
void F_55 ( void * V_92 , int V_93 )
{
struct V_77 * V_78 = V_92 ;
struct V_1 * V_2 = V_78 -> V_57 ;
switch ( V_93 ) {
case V_94 :
F_56 ( V_2 -> V_42 , V_78 -> V_81 . V_95 . V_10 ,
V_78 -> V_81 . V_95 . V_38 , V_45 ) ;
break;
case V_96 :
F_57 ( V_2 -> V_42 , V_78 -> V_81 . V_95 . V_10 ,
V_78 -> V_81 . V_95 . V_38 , V_45 ) ;
break;
}
}
static void F_42 ( struct V_55 * V_56 , int V_97 )
{
struct V_77 * V_78 , * V_80 ;
F_19 ( V_98 ) ;
F_19 ( V_99 ) ;
unsigned long V_79 ;
unsigned int V_100 = 0 , V_101 = 0 , V_102 = 0 ;
F_52 ( V_103 ) ;
F_58 ( & V_56 -> V_60 ) ;
F_45 ( & V_56 -> V_30 , V_79 ) ;
F_59 ( & V_56 -> V_58 , & V_98 ) ;
if ( V_97 )
F_59 ( & V_56 -> V_59 , & V_99 ) ;
F_48 ( & V_56 -> V_30 , V_79 ) ;
if ( ! F_14 ( & V_98 ) ) {
V_101 = F_60 ( V_56 , & V_98 ,
& V_99 , & V_102 ) ;
if ( V_97 )
F_59 ( & V_98 , & V_99 ) ;
}
F_22 (ibmr, next, &kill_list, mapping.m_list) {
F_52 ( V_104 ) ;
F_8 ( & V_78 -> V_81 . V_82 ) ;
F_54 ( V_56 , V_78 ) ;
F_9 ( V_78 ) ;
V_100 ++ ;
}
if ( ! F_14 ( & V_98 ) ) {
F_45 ( & V_56 -> V_30 , V_79 ) ;
F_20 ( & V_98 , & V_56 -> V_59 ) ;
F_48 ( & V_56 -> V_30 , V_79 ) ;
}
F_61 ( V_102 , & V_56 -> V_76 ) ;
F_61 ( V_101 , & V_56 -> V_105 ) ;
F_61 ( V_100 , & V_56 -> V_75 ) ;
F_62 ( & V_56 -> V_60 ) ;
}
static void V_62 ( struct V_106 * V_107 )
{
struct V_55 * V_56 = F_63 ( V_107 , struct V_55 , V_61 ) ;
F_42 ( V_56 , 0 ) ;
}
void F_64 ( void * V_92 , int V_108 )
{
struct V_77 * V_78 = V_92 ;
struct V_55 * V_56 = V_78 -> V_57 -> V_71 ;
F_65 ( L_3 , V_78 -> V_81 . V_95 . V_37 ) ;
if ( ! V_56 )
return;
F_66 ( V_56 , V_78 ) ;
if ( F_43 ( & V_56 -> V_76 ) >= V_56 -> V_66 ||
F_43 ( & V_56 -> V_105 ) >= V_56 -> V_64 / 10 )
F_67 ( V_74 , & V_56 -> V_61 ) ;
if ( V_108 ) {
if ( F_68 ( ! F_69 () ) ) {
F_42 ( V_56 , 0 ) ;
} else {
F_67 ( V_74 , & V_56 -> V_61 ) ;
}
}
}
void F_70 ( void )
{
struct V_1 * V_2 ;
F_7 (rds_iwdev, &rds_iw_devices, list) {
struct V_55 * V_56 = V_2 -> V_71 ;
if ( V_56 )
F_42 ( V_56 , 0 ) ;
}
}
void * F_71 ( struct V_35 * V_34 , unsigned long V_109 ,
struct V_110 * V_111 , T_3 * V_112 )
{
struct V_1 * V_2 ;
struct V_77 * V_78 = NULL ;
struct V_3 * V_4 ;
struct V_12 V_113 = {
. V_114 . V_115 = V_111 -> V_116 ,
. V_117 = V_111 -> V_118 ,
} ;
struct V_12 V_119 = {
. V_114 . V_115 = V_111 -> V_120 ,
. V_117 = V_111 -> V_121 ,
} ;
int V_44 ;
V_44 = F_11 ( & V_113 , & V_119 , & V_2 , & V_4 ) ;
if ( V_44 || ! V_4 ) {
V_44 = - V_122 ;
goto V_123;
}
if ( ! V_2 -> V_71 ) {
V_44 = - V_122 ;
goto V_123;
}
V_78 = F_49 ( V_2 ) ;
if ( F_72 ( V_78 ) )
return V_78 ;
V_78 -> V_4 = V_4 ;
V_78 -> V_57 = V_2 ;
V_44 = F_73 ( V_2 -> V_71 , V_78 , V_34 , V_109 ) ;
if ( V_44 == 0 )
* V_112 = V_78 -> V_124 -> V_125 ;
else
F_29 ( V_46 L_4 , V_44 ) ;
V_123:
if ( V_44 ) {
if ( V_78 )
F_64 ( V_78 , 0 ) ;
V_78 = F_35 ( V_44 ) ;
}
return V_78 ;
}
static int F_53 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_126 * V_124 ;
int V_83 ;
V_124 = F_74 ( V_2 -> V_127 , V_128 ,
V_56 -> V_63 ) ;
if ( F_72 ( V_124 ) ) {
V_83 = F_75 ( V_124 ) ;
F_29 ( V_46 L_5 , V_83 ) ;
return V_83 ;
}
V_78 -> V_124 = V_124 ;
return 0 ;
}
static int F_76 ( struct V_129 * V_81 )
{
struct V_77 * V_78 = V_81 -> V_90 ;
struct V_33 * V_95 = & V_81 -> V_95 ;
struct V_130 V_131 ;
struct V_132 * V_133 ;
int V_44 , V_134 ;
V_134 = F_77 ( V_78 -> V_124 , V_95 -> V_10 , V_95 -> V_37 , V_135 ) ;
if ( F_28 ( V_134 != V_95 -> V_37 ) )
return V_134 < 0 ? V_134 : - V_48 ;
V_131 . V_136 . V_80 = NULL ;
V_131 . V_136 . V_137 = V_138 ;
V_131 . V_136 . V_139 = V_140 ;
V_131 . V_136 . V_141 = 0 ;
V_131 . V_124 = V_78 -> V_124 ;
V_131 . V_142 = V_81 -> V_143 ;
V_131 . V_144 = V_145 |
V_146 |
V_147 ;
F_78 ( V_78 -> V_124 , V_78 -> V_148 ++ ) ;
V_81 -> V_143 = V_78 -> V_124 -> V_125 ;
V_133 = & V_131 . V_136 ;
V_44 = F_79 ( V_78 -> V_4 -> V_149 , & V_131 . V_136 , & V_133 ) ;
F_13 ( V_133 != & V_131 . V_136 ) ;
if ( V_44 )
F_80 ( V_46 L_6 ,
V_150 , __LINE__ , V_44 ) ;
return V_44 ;
}
static int F_81 ( struct V_77 * V_78 )
{
struct V_132 V_151 , * V_133 ;
int V_44 = 0 ;
if ( ! V_78 -> V_4 -> V_149 || ! V_78 -> V_124 )
goto V_123;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_139 = V_152 ;
V_151 . V_137 = V_153 ;
V_151 . V_154 . V_155 = V_78 -> V_124 -> V_125 ;
V_151 . V_156 = V_157 ;
V_133 = & V_151 ;
V_44 = F_79 ( V_78 -> V_4 -> V_149 , & V_151 , & V_133 ) ;
if ( V_44 ) {
F_80 ( V_46 L_6 ,
V_150 , __LINE__ , V_44 ) ;
goto V_123;
}
V_123:
return V_44 ;
}
static int F_73 ( struct V_55 * V_56 ,
struct V_77 * V_78 ,
struct V_35 * V_34 ,
unsigned int V_36 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_129 * V_81 = & V_78 -> V_81 ;
T_2 * V_158 ;
int V_44 = 0 ;
F_24 ( & V_81 -> V_95 , V_34 , V_36 ) ;
V_44 = F_25 ( V_2 , & V_81 -> V_95 ) ;
if ( V_44 ) {
V_158 = NULL ;
goto V_123;
}
if ( V_81 -> V_95 . V_38 > V_56 -> V_63 ) {
V_44 = - V_159 ;
goto V_123;
}
V_44 = F_76 ( V_81 ) ;
if ( V_44 )
goto V_123;
F_52 ( V_160 ) ;
V_123:
F_9 ( V_158 ) ;
return V_44 ;
}
static void F_66 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
unsigned long V_79 ;
int V_44 ;
if ( ! V_78 -> V_81 . V_95 . V_38 )
return;
V_44 = F_81 ( V_78 ) ;
if ( V_44 )
return;
F_45 ( & V_56 -> V_30 , V_79 ) ;
F_4 ( & V_78 -> V_81 . V_82 , & V_56 -> V_58 ) ;
F_82 ( V_78 -> V_81 . V_95 . V_37 , & V_56 -> V_76 ) ;
F_83 ( & V_56 -> V_105 ) ;
F_48 ( & V_56 -> V_30 , V_79 ) ;
}
static unsigned int F_60 ( struct V_55 * V_56 ,
struct V_29 * V_98 ,
struct V_29 * V_99 ,
int * V_102 )
{
struct V_129 * V_81 , * V_80 ;
unsigned int V_101 = 0 ;
F_19 ( V_161 ) ;
while ( ! F_14 ( V_98 ) ) {
unsigned long V_79 ;
F_45 ( & V_56 -> V_30 , V_79 ) ;
F_22 (mapping, next, unmap_list, m_list) {
* V_102 += V_81 -> V_95 . V_37 ;
F_84 ( & V_81 -> V_82 , & V_161 ) ;
V_101 ++ ;
}
F_48 ( & V_56 -> V_30 , V_79 ) ;
}
F_59 ( & V_161 , V_98 ) ;
return V_101 ;
}
static void F_54 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_124 )
F_85 ( V_78 -> V_124 ) ;
}
