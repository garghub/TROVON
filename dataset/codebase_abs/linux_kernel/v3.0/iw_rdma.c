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
struct V_16 V_17 ;
struct V_3 * V_18 ;
int V_19 ;
V_13 = (struct V_12 * ) & V_4 -> V_20 . V_21 . V_13 ;
V_14 = (struct V_12 * ) & V_4 -> V_20 . V_21 . V_14 ;
V_17 . V_22 = V_13 -> V_23 . V_24 ;
V_17 . V_25 = V_13 -> V_26 ;
V_17 . V_27 = V_14 -> V_23 . V_24 ;
V_17 . V_28 = V_14 -> V_26 ;
V_19 = F_11 ( & V_17 , & V_15 , & V_18 ) ;
if ( V_19 )
F_6 ( V_2 , V_4 ) ;
return F_1 ( V_2 , V_4 ) ;
}
void F_12 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
F_3 ( & V_34 ) ;
F_13 ( F_14 ( & V_35 ) ) ;
F_13 ( F_14 ( & V_32 -> V_36 ) ) ;
F_8 ( & V_32 -> V_36 ) ;
F_15 ( & V_2 -> V_9 ) ;
F_4 ( & V_32 -> V_36 , & V_2 -> V_37 ) ;
F_16 ( & V_2 -> V_9 ) ;
F_5 ( & V_34 ) ;
V_32 -> V_2 = V_2 ;
}
void F_17 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
F_15 ( & V_34 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_13 ( F_14 ( & V_32 -> V_36 ) ) ;
F_8 ( & V_32 -> V_36 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_4 ( & V_32 -> V_36 , & V_35 ) ;
F_16 ( & V_34 ) ;
F_6 ( V_32 -> V_2 , V_32 -> V_6 ) ;
V_32 -> V_2 = NULL ;
}
void F_18 ( struct V_38 * V_10 , T_1 * V_39 )
{
struct V_31 * V_32 , * V_40 ;
F_19 ( V_41 ) ;
F_3 ( V_39 ) ;
F_20 ( V_10 , & V_41 ) ;
F_21 ( V_10 ) ;
F_5 ( V_39 ) ;
F_22 (ic, _ic, &tmp_list, iw_node)
F_23 ( V_32 -> V_30 ) ;
}
static void F_24 ( struct V_42 * V_43 ,
struct V_44 * V_10 , unsigned int V_45 )
{
V_43 -> V_10 = V_10 ;
V_43 -> V_46 = V_45 ;
V_43 -> V_47 = 0 ;
V_43 -> V_48 = 0 ;
V_43 -> V_49 = 0 ;
}
static T_2 * F_25 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
T_2 * V_52 = NULL ;
int V_53 , V_54 , V_55 ;
F_26 ( V_43 -> V_47 ) ;
V_43 -> V_47 = F_27 ( V_51 , V_43 -> V_10 , V_43 -> V_46 , V_56 ) ;
if ( F_28 ( ! V_43 -> V_47 ) ) {
F_29 ( V_57 L_1 ) ;
return F_30 ( - V_58 ) ;
}
V_43 -> V_49 = 0 ;
V_43 -> V_48 = 0 ;
V_55 = - V_59 ;
for ( V_53 = 0 ; V_53 < V_43 -> V_47 ; ++ V_53 ) {
unsigned int V_47 = F_31 ( V_51 , & V_43 -> V_10 [ V_53 ] ) ;
T_2 V_60 = F_32 ( V_51 , & V_43 -> V_10 [ V_53 ] ) ;
T_2 V_61 ;
V_43 -> V_49 += V_47 ;
V_61 = V_60 + V_47 ;
if ( V_60 & V_62 ) {
if ( V_53 > 0 )
goto V_63;
V_60 &= ~ V_62 ;
}
if ( V_61 & V_62 ) {
if ( V_53 < V_43 -> V_47 - 1 )
goto V_63;
V_61 = ( V_61 + V_62 ) & ~ V_62 ;
}
V_43 -> V_48 += ( V_61 - V_60 ) >> V_64 ;
}
if ( V_43 -> V_48 > V_65 )
goto V_63;
V_52 = F_2 ( sizeof( T_2 ) * V_43 -> V_48 , V_66 ) ;
if ( ! V_52 ) {
V_55 = - V_8 ;
goto V_63;
}
for ( V_53 = V_54 = 0 ; V_53 < V_43 -> V_47 ; ++ V_53 ) {
unsigned int V_47 = F_31 ( V_51 , & V_43 -> V_10 [ V_53 ] ) ;
T_2 V_60 = F_32 ( V_51 , & V_43 -> V_10 [ V_53 ] ) ;
T_2 V_61 ;
V_61 = V_60 + V_47 ;
V_60 &= ~ V_62 ;
for (; V_60 < V_61 ; V_60 += V_67 )
V_52 [ V_54 ++ ] = V_60 ;
F_13 ( V_54 > V_43 -> V_48 ) ;
}
return V_52 ;
V_63:
F_33 ( V_2 -> V_51 , V_43 -> V_10 , V_43 -> V_46 , V_56 ) ;
V_43 -> V_47 = 0 ;
F_9 ( V_52 ) ;
return F_30 ( V_55 ) ;
}
struct V_68 * F_34 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
V_69 = F_35 ( sizeof( * V_69 ) , V_7 ) ;
if ( ! V_69 ) {
F_29 ( V_57 L_2 ) ;
return F_30 ( - V_8 ) ;
}
V_69 -> V_70 = V_2 ;
F_21 ( & V_69 -> V_71 ) ;
F_21 ( & V_69 -> V_72 ) ;
F_36 ( & V_69 -> V_73 ) ;
F_37 ( & V_69 -> V_39 ) ;
F_38 ( & V_69 -> V_74 , V_75 ) ;
V_69 -> V_76 = V_65 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_79 = V_69 -> V_77 * V_69 -> V_76 / 4 ;
V_69 -> V_80 = V_65 ;
V_69 -> V_81 = V_69 -> V_77 * 3 / 4 ;
return V_69 ;
}
void F_39 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_68 * V_69 = V_2 -> V_84 ;
V_83 -> V_85 = V_69 -> V_77 ;
V_83 -> V_86 = V_69 -> V_80 ;
}
void F_40 ( struct V_68 * V_69 )
{
F_41 ( V_87 ) ;
F_42 ( V_69 , 1 ) ;
F_13 ( F_43 ( & V_69 -> V_88 ) ) ;
F_13 ( F_43 ( & V_69 -> V_89 ) ) ;
F_9 ( V_69 ) ;
}
static inline struct V_90 * F_44 ( struct V_68 * V_69 )
{
struct V_90 * V_91 = NULL ;
unsigned long V_92 ;
F_45 ( & V_69 -> V_39 , V_92 ) ;
if ( ! F_14 ( & V_69 -> V_72 ) ) {
V_91 = F_46 ( V_69 -> V_72 . V_93 , struct V_90 , V_94 . V_95 ) ;
F_47 ( & V_91 -> V_94 . V_95 ) ;
}
F_48 ( & V_69 -> V_39 , V_92 ) ;
return V_91 ;
}
static struct V_90 * F_49 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_84 ;
struct V_90 * V_91 = NULL ;
int V_96 = 0 , V_97 = 0 ;
while ( 1 ) {
V_91 = F_44 ( V_69 ) ;
if ( V_91 )
return V_91 ;
if ( F_50 ( & V_69 -> V_88 ) <= V_69 -> V_77 )
break;
F_51 ( & V_69 -> V_88 ) ;
if ( ++ V_97 > 2 ) {
F_52 ( V_98 ) ;
return F_30 ( - V_99 ) ;
}
F_52 ( V_100 ) ;
F_42 ( V_69 , 0 ) ;
}
V_91 = F_35 ( sizeof( * V_91 ) , V_7 ) ;
if ( ! V_91 ) {
V_96 = - V_8 ;
goto V_101;
}
F_37 ( & V_91 -> V_94 . V_102 ) ;
F_21 ( & V_91 -> V_94 . V_95 ) ;
V_91 -> V_94 . V_103 = V_91 ;
V_96 = F_53 ( V_69 , V_91 ) ;
if ( V_96 )
goto V_101;
F_52 ( V_104 ) ;
return V_91 ;
V_101:
if ( V_91 ) {
F_54 ( V_69 , V_91 ) ;
F_9 ( V_91 ) ;
}
F_51 ( & V_69 -> V_88 ) ;
return F_30 ( V_96 ) ;
}
void F_55 ( void * V_105 , int V_106 )
{
struct V_90 * V_91 = V_105 ;
struct V_1 * V_2 = V_91 -> V_70 ;
switch ( V_106 ) {
case V_107 :
F_56 ( V_2 -> V_51 , V_91 -> V_94 . V_108 . V_10 ,
V_91 -> V_94 . V_108 . V_47 , V_56 ) ;
break;
case V_109 :
F_57 ( V_2 -> V_51 , V_91 -> V_94 . V_108 . V_10 ,
V_91 -> V_94 . V_108 . V_47 , V_56 ) ;
break;
}
}
static inline unsigned int F_58 ( struct V_68 * V_69 , int V_110 )
{
unsigned int V_88 ;
V_88 = F_43 ( & V_69 -> V_88 ) ;
if ( V_110 )
return V_88 ;
return 0 ;
}
static int F_42 ( struct V_68 * V_69 , int V_110 )
{
struct V_90 * V_91 , * V_93 ;
F_19 ( V_111 ) ;
F_19 ( V_112 ) ;
unsigned long V_92 ;
unsigned int V_113 = 0 , V_114 = 0 , V_115 ;
int V_55 = 0 ;
F_52 ( V_116 ) ;
F_59 ( & V_69 -> V_73 ) ;
F_45 ( & V_69 -> V_39 , V_92 ) ;
F_60 ( & V_69 -> V_71 , & V_111 ) ;
if ( V_110 )
F_60 ( & V_69 -> V_72 , & V_112 ) ;
F_48 ( & V_69 -> V_39 , V_92 ) ;
V_115 = F_58 ( V_69 , V_110 ) ;
if ( ! F_14 ( & V_111 ) ) {
V_114 = F_61 ( V_69 , & V_111 , & V_112 ) ;
if ( V_110 )
F_60 ( & V_111 , & V_112 ) ;
}
F_22 (ibmr, next, &kill_list, mapping.m_list) {
F_52 ( V_117 ) ;
F_8 ( & V_91 -> V_94 . V_95 ) ;
F_54 ( V_69 , V_91 ) ;
F_9 ( V_91 ) ;
V_113 ++ ;
}
if ( ! F_14 ( & V_111 ) ) {
F_45 ( & V_69 -> V_39 , V_92 ) ;
F_20 ( & V_111 , & V_69 -> V_72 ) ;
F_48 ( & V_69 -> V_39 , V_92 ) ;
}
F_62 ( V_114 , & V_69 -> V_118 ) ;
F_62 ( V_113 , & V_69 -> V_88 ) ;
F_63 ( & V_69 -> V_73 ) ;
return V_55 ;
}
static void V_75 ( struct V_119 * V_120 )
{
struct V_68 * V_69 = F_64 ( V_120 , struct V_68 , V_74 ) ;
F_42 ( V_69 , 0 ) ;
}
void F_65 ( void * V_105 , int V_121 )
{
struct V_90 * V_91 = V_105 ;
struct V_68 * V_69 = V_91 -> V_70 -> V_84 ;
F_66 ( L_3 , V_91 -> V_94 . V_108 . V_46 ) ;
if ( ! V_69 )
return;
F_67 ( V_69 , V_91 ) ;
if ( F_43 ( & V_69 -> V_89 ) >= V_69 -> V_79 ||
F_43 ( & V_69 -> V_118 ) >= V_69 -> V_77 / 10 )
F_68 ( V_87 , & V_69 -> V_74 ) ;
if ( V_121 ) {
if ( F_69 ( ! F_70 () ) ) {
F_42 ( V_69 , 0 ) ;
} else {
F_68 ( V_87 , & V_69 -> V_74 ) ;
}
}
}
void F_71 ( void )
{
struct V_1 * V_2 ;
F_7 (rds_iwdev, &rds_iw_devices, list) {
struct V_68 * V_69 = V_2 -> V_84 ;
if ( V_69 )
F_42 ( V_69 , 0 ) ;
}
}
void * F_72 ( struct V_44 * V_43 , unsigned long V_122 ,
struct V_16 * V_17 , T_3 * V_123 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 = NULL ;
struct V_3 * V_4 ;
int V_55 ;
V_55 = F_11 ( V_17 , & V_2 , & V_4 ) ;
if ( V_55 || ! V_4 ) {
V_55 = - V_124 ;
goto V_125;
}
if ( ! V_2 -> V_84 ) {
V_55 = - V_124 ;
goto V_125;
}
V_91 = F_49 ( V_2 ) ;
if ( F_73 ( V_91 ) )
return V_91 ;
V_91 -> V_4 = V_4 ;
V_91 -> V_70 = V_2 ;
V_55 = F_74 ( V_2 -> V_84 , V_91 , V_43 , V_122 ) ;
if ( V_55 == 0 )
* V_123 = V_91 -> V_126 -> V_127 ;
else
F_29 ( V_57 L_4 , V_55 ) ;
V_125:
if ( V_55 ) {
if ( V_91 )
F_65 ( V_91 , 0 ) ;
V_91 = F_30 ( V_55 ) ;
}
return V_91 ;
}
static int F_53 ( struct V_68 * V_69 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
struct V_128 * V_129 = NULL ;
struct V_130 * V_126 ;
int V_96 ;
V_126 = F_75 ( V_2 -> V_131 , V_69 -> V_76 ) ;
if ( F_73 ( V_126 ) ) {
V_96 = F_76 ( V_126 ) ;
F_29 ( V_57 L_5 , V_96 ) ;
return V_96 ;
}
V_129 = F_77 ( V_2 -> V_51 , V_69 -> V_76 ) ;
if ( F_73 ( V_129 ) ) {
V_96 = F_76 ( V_129 ) ;
F_29 ( V_57 L_6 , V_96 ) ;
F_78 ( V_126 ) ;
return V_96 ;
}
V_91 -> V_129 = V_129 ;
V_91 -> V_126 = V_126 ;
return 0 ;
}
static int F_79 ( struct V_132 * V_94 )
{
struct V_90 * V_91 = V_94 -> V_103 ;
struct V_133 V_134 , * V_135 ;
int V_55 ;
F_80 ( V_91 -> V_126 , V_91 -> V_136 ++ ) ;
V_94 -> V_137 = V_91 -> V_126 -> V_127 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_138 = V_139 ;
V_134 . V_140 = V_141 ;
V_134 . V_142 . V_143 . V_144 = V_94 -> V_108 . V_49 ;
V_134 . V_142 . V_143 . V_127 = V_94 -> V_137 ;
V_134 . V_142 . V_143 . V_129 = V_91 -> V_129 ;
V_134 . V_142 . V_143 . V_145 = V_94 -> V_108 . V_47 ;
V_134 . V_142 . V_143 . V_146 = V_64 ;
V_134 . V_142 . V_143 . V_147 = V_148 |
V_149 |
V_150 ;
V_134 . V_142 . V_143 . V_151 = 0 ;
V_134 . V_152 = V_153 ;
V_135 = & V_134 ;
V_55 = F_81 ( V_91 -> V_4 -> V_154 , & V_134 , & V_135 ) ;
F_13 ( V_135 != & V_134 ) ;
if ( V_55 && F_82 () )
F_29 ( V_57 L_7 ,
V_155 , __LINE__ , V_55 ) ;
return V_55 ;
}
static int F_83 ( struct V_90 * V_91 )
{
struct V_133 V_156 , * V_135 ;
int V_55 = 0 ;
if ( ! V_91 -> V_4 -> V_154 || ! V_91 -> V_126 )
goto V_125;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_138 = V_157 ;
V_156 . V_140 = V_158 ;
V_156 . V_159 . V_160 = V_91 -> V_126 -> V_127 ;
V_156 . V_152 = V_153 ;
V_135 = & V_156 ;
V_55 = F_81 ( V_91 -> V_4 -> V_154 , & V_156 , & V_135 ) ;
if ( V_55 && F_82 () ) {
F_29 ( V_57 L_7 ,
V_155 , __LINE__ , V_55 ) ;
goto V_125;
}
V_125:
return V_55 ;
}
static int F_74 ( struct V_68 * V_69 ,
struct V_90 * V_91 ,
struct V_44 * V_43 ,
unsigned int V_45 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
struct V_132 * V_94 = & V_91 -> V_94 ;
T_2 * V_52 ;
int V_53 , V_55 = 0 ;
F_24 ( & V_94 -> V_108 , V_43 , V_45 ) ;
V_52 = F_25 ( V_2 , & V_94 -> V_108 ) ;
if ( F_73 ( V_52 ) ) {
V_55 = F_76 ( V_52 ) ;
V_52 = NULL ;
goto V_125;
}
if ( V_94 -> V_108 . V_47 > V_69 -> V_76 ) {
V_55 = - V_161 ;
goto V_125;
}
for ( V_53 = 0 ; V_53 < V_94 -> V_108 . V_48 ; ++ V_53 )
V_91 -> V_129 -> V_129 [ V_53 ] = V_52 [ V_53 ] ;
V_55 = F_79 ( V_94 ) ;
if ( V_55 )
goto V_125;
F_52 ( V_162 ) ;
V_125:
F_9 ( V_52 ) ;
return V_55 ;
}
static void F_67 ( struct V_68 * V_69 ,
struct V_90 * V_91 )
{
unsigned long V_92 ;
int V_55 ;
if ( ! V_91 -> V_94 . V_108 . V_47 )
return;
V_55 = F_83 ( V_91 ) ;
if ( V_55 )
return;
F_45 ( & V_69 -> V_39 , V_92 ) ;
F_4 ( & V_91 -> V_94 . V_95 , & V_69 -> V_71 ) ;
F_84 ( V_91 -> V_94 . V_108 . V_46 , & V_69 -> V_89 ) ;
F_85 ( & V_69 -> V_118 ) ;
F_48 ( & V_69 -> V_39 , V_92 ) ;
}
static unsigned int F_61 ( struct V_68 * V_69 ,
struct V_38 * V_111 ,
struct V_38 * V_112 )
{
struct V_132 * V_94 , * V_93 ;
unsigned int V_114 = 0 ;
F_19 ( V_163 ) ;
while ( ! F_14 ( V_111 ) ) {
unsigned long V_92 ;
F_45 ( & V_69 -> V_39 , V_92 ) ;
F_22 (mapping, next, unmap_list, m_list) {
F_86 ( & V_94 -> V_95 , & V_163 ) ;
V_114 ++ ;
}
F_48 ( & V_69 -> V_39 , V_92 ) ;
}
F_60 ( & V_163 , V_111 ) ;
return V_114 ;
}
static void F_54 ( struct V_68 * V_69 ,
struct V_90 * V_91 )
{
if ( V_91 -> V_129 )
F_87 ( V_91 -> V_129 ) ;
if ( V_91 -> V_126 )
F_78 ( V_91 -> V_126 ) ;
}
