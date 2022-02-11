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
static T_2 * F_25 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_2 * V_43 = NULL ;
int V_44 , V_45 , V_46 ;
F_26 ( V_34 -> V_38 ) ;
V_34 -> V_38 = F_27 ( V_42 , V_34 -> V_10 , V_34 -> V_37 , V_47 ) ;
if ( F_28 ( ! V_34 -> V_38 ) ) {
F_29 ( V_48 L_1 ) ;
return F_30 ( - V_49 ) ;
}
V_34 -> V_40 = 0 ;
V_34 -> V_39 = 0 ;
V_46 = - V_50 ;
for ( V_44 = 0 ; V_44 < V_34 -> V_38 ; ++ V_44 ) {
unsigned int V_38 = F_31 ( V_42 , & V_34 -> V_10 [ V_44 ] ) ;
T_2 V_51 = F_32 ( V_42 , & V_34 -> V_10 [ V_44 ] ) ;
T_2 V_52 ;
V_34 -> V_40 += V_38 ;
V_52 = V_51 + V_38 ;
if ( V_51 & V_53 ) {
if ( V_44 > 0 )
goto V_54;
V_51 &= ~ V_53 ;
}
if ( V_52 & V_53 ) {
if ( V_44 < V_34 -> V_38 - 1 )
goto V_54;
V_52 = ( V_52 + V_53 ) & ~ V_53 ;
}
V_34 -> V_39 += ( V_52 - V_51 ) >> V_55 ;
}
if ( V_34 -> V_39 > V_56 )
goto V_54;
V_43 = F_2 ( sizeof( T_2 ) * V_34 -> V_39 , V_57 ) ;
if ( ! V_43 ) {
V_46 = - V_8 ;
goto V_54;
}
for ( V_44 = V_45 = 0 ; V_44 < V_34 -> V_38 ; ++ V_44 ) {
unsigned int V_38 = F_31 ( V_42 , & V_34 -> V_10 [ V_44 ] ) ;
T_2 V_51 = F_32 ( V_42 , & V_34 -> V_10 [ V_44 ] ) ;
T_2 V_52 ;
V_52 = V_51 + V_38 ;
V_51 &= ~ V_53 ;
for (; V_51 < V_52 ; V_51 += V_58 )
V_43 [ V_45 ++ ] = V_51 ;
F_13 ( V_45 > V_34 -> V_39 ) ;
}
return V_43 ;
V_54:
F_33 ( V_2 -> V_42 , V_34 -> V_10 , V_34 -> V_37 , V_47 ) ;
V_34 -> V_38 = 0 ;
F_9 ( V_43 ) ;
return F_30 ( V_46 ) ;
}
struct V_59 * F_34 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
V_60 = F_35 ( sizeof( * V_60 ) , V_7 ) ;
if ( ! V_60 ) {
F_29 ( V_48 L_2 ) ;
return F_30 ( - V_8 ) ;
}
V_60 -> V_61 = V_2 ;
F_21 ( & V_60 -> V_62 ) ;
F_21 ( & V_60 -> V_63 ) ;
F_36 ( & V_60 -> V_64 ) ;
F_37 ( & V_60 -> V_30 ) ;
F_38 ( & V_60 -> V_65 , V_66 ) ;
V_60 -> V_67 = V_56 ;
V_60 -> V_68 = V_69 ;
V_60 -> V_70 = V_60 -> V_68 * V_60 -> V_67 / 4 ;
V_60 -> V_71 = V_56 ;
V_60 -> V_72 = V_60 -> V_68 * 3 / 4 ;
return V_60 ;
}
void F_39 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_59 * V_60 = V_2 -> V_75 ;
V_74 -> V_76 = V_60 -> V_68 ;
V_74 -> V_77 = V_60 -> V_71 ;
}
void F_40 ( struct V_59 * V_60 )
{
F_41 ( V_78 ) ;
F_42 ( V_60 , 1 ) ;
F_13 ( F_43 ( & V_60 -> V_79 ) ) ;
F_13 ( F_43 ( & V_60 -> V_80 ) ) ;
F_9 ( V_60 ) ;
}
static inline struct V_81 * F_44 ( struct V_59 * V_60 )
{
struct V_81 * V_82 = NULL ;
unsigned long V_83 ;
F_45 ( & V_60 -> V_30 , V_83 ) ;
if ( ! F_14 ( & V_60 -> V_63 ) ) {
V_82 = F_46 ( V_60 -> V_63 . V_84 , struct V_81 , V_85 . V_86 ) ;
F_47 ( & V_82 -> V_85 . V_86 ) ;
}
F_48 ( & V_60 -> V_30 , V_83 ) ;
return V_82 ;
}
static struct V_81 * F_49 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_75 ;
struct V_81 * V_82 = NULL ;
int V_87 = 0 , V_88 = 0 ;
while ( 1 ) {
V_82 = F_44 ( V_60 ) ;
if ( V_82 )
return V_82 ;
if ( F_50 ( & V_60 -> V_79 ) <= V_60 -> V_68 )
break;
F_51 ( & V_60 -> V_79 ) ;
if ( ++ V_88 > 2 ) {
F_52 ( V_89 ) ;
return F_30 ( - V_90 ) ;
}
F_52 ( V_91 ) ;
F_42 ( V_60 , 0 ) ;
}
V_82 = F_35 ( sizeof( * V_82 ) , V_7 ) ;
if ( ! V_82 ) {
V_87 = - V_8 ;
goto V_92;
}
F_37 ( & V_82 -> V_85 . V_93 ) ;
F_21 ( & V_82 -> V_85 . V_86 ) ;
V_82 -> V_85 . V_94 = V_82 ;
V_87 = F_53 ( V_60 , V_82 ) ;
if ( V_87 )
goto V_92;
F_52 ( V_95 ) ;
return V_82 ;
V_92:
if ( V_82 ) {
F_54 ( V_60 , V_82 ) ;
F_9 ( V_82 ) ;
}
F_51 ( & V_60 -> V_79 ) ;
return F_30 ( V_87 ) ;
}
void F_55 ( void * V_96 , int V_97 )
{
struct V_81 * V_82 = V_96 ;
struct V_1 * V_2 = V_82 -> V_61 ;
switch ( V_97 ) {
case V_98 :
F_56 ( V_2 -> V_42 , V_82 -> V_85 . V_99 . V_10 ,
V_82 -> V_85 . V_99 . V_38 , V_47 ) ;
break;
case V_100 :
F_57 ( V_2 -> V_42 , V_82 -> V_85 . V_99 . V_10 ,
V_82 -> V_85 . V_99 . V_38 , V_47 ) ;
break;
}
}
static int F_42 ( struct V_59 * V_60 , int V_101 )
{
struct V_81 * V_82 , * V_84 ;
F_19 ( V_102 ) ;
F_19 ( V_103 ) ;
unsigned long V_83 ;
unsigned int V_104 = 0 , V_105 = 0 , V_106 = 0 ;
int V_46 = 0 ;
F_52 ( V_107 ) ;
F_58 ( & V_60 -> V_64 ) ;
F_45 ( & V_60 -> V_30 , V_83 ) ;
F_59 ( & V_60 -> V_62 , & V_102 ) ;
if ( V_101 )
F_59 ( & V_60 -> V_63 , & V_103 ) ;
F_48 ( & V_60 -> V_30 , V_83 ) ;
if ( ! F_14 ( & V_102 ) ) {
V_105 = F_60 ( V_60 , & V_102 ,
& V_103 , & V_106 ) ;
if ( V_101 )
F_59 ( & V_102 , & V_103 ) ;
}
F_22 (ibmr, next, &kill_list, mapping.m_list) {
F_52 ( V_108 ) ;
F_8 ( & V_82 -> V_85 . V_86 ) ;
F_54 ( V_60 , V_82 ) ;
F_9 ( V_82 ) ;
V_104 ++ ;
}
if ( ! F_14 ( & V_102 ) ) {
F_45 ( & V_60 -> V_30 , V_83 ) ;
F_20 ( & V_102 , & V_60 -> V_63 ) ;
F_48 ( & V_60 -> V_30 , V_83 ) ;
}
F_61 ( V_106 , & V_60 -> V_80 ) ;
F_61 ( V_105 , & V_60 -> V_109 ) ;
F_61 ( V_104 , & V_60 -> V_79 ) ;
F_62 ( & V_60 -> V_64 ) ;
return V_46 ;
}
static void V_66 ( struct V_110 * V_111 )
{
struct V_59 * V_60 = F_63 ( V_111 , struct V_59 , V_65 ) ;
F_42 ( V_60 , 0 ) ;
}
void F_64 ( void * V_96 , int V_112 )
{
struct V_81 * V_82 = V_96 ;
struct V_59 * V_60 = V_82 -> V_61 -> V_75 ;
F_65 ( L_3 , V_82 -> V_85 . V_99 . V_37 ) ;
if ( ! V_60 )
return;
F_66 ( V_60 , V_82 ) ;
if ( F_43 ( & V_60 -> V_80 ) >= V_60 -> V_70 ||
F_43 ( & V_60 -> V_109 ) >= V_60 -> V_68 / 10 )
F_67 ( V_78 , & V_60 -> V_65 ) ;
if ( V_112 ) {
if ( F_68 ( ! F_69 () ) ) {
F_42 ( V_60 , 0 ) ;
} else {
F_67 ( V_78 , & V_60 -> V_65 ) ;
}
}
}
void F_70 ( void )
{
struct V_1 * V_2 ;
F_7 (rds_iwdev, &rds_iw_devices, list) {
struct V_59 * V_60 = V_2 -> V_75 ;
if ( V_60 )
F_42 ( V_60 , 0 ) ;
}
}
void * F_71 ( struct V_35 * V_34 , unsigned long V_113 ,
struct V_114 * V_115 , T_3 * V_116 )
{
struct V_1 * V_2 ;
struct V_81 * V_82 = NULL ;
struct V_3 * V_4 ;
struct V_12 V_117 = {
. V_118 . V_119 = V_115 -> V_120 ,
. V_121 = V_115 -> V_122 ,
} ;
struct V_12 V_123 = {
. V_118 . V_119 = V_115 -> V_124 ,
. V_121 = V_115 -> V_125 ,
} ;
int V_46 ;
V_46 = F_11 ( & V_117 , & V_123 , & V_2 , & V_4 ) ;
if ( V_46 || ! V_4 ) {
V_46 = - V_126 ;
goto V_127;
}
if ( ! V_2 -> V_75 ) {
V_46 = - V_126 ;
goto V_127;
}
V_82 = F_49 ( V_2 ) ;
if ( F_72 ( V_82 ) )
return V_82 ;
V_82 -> V_4 = V_4 ;
V_82 -> V_61 = V_2 ;
V_46 = F_73 ( V_2 -> V_75 , V_82 , V_34 , V_113 ) ;
if ( V_46 == 0 )
* V_116 = V_82 -> V_128 -> V_129 ;
else
F_29 ( V_48 L_4 , V_46 ) ;
V_127:
if ( V_46 ) {
if ( V_82 )
F_64 ( V_82 , 0 ) ;
V_82 = F_30 ( V_46 ) ;
}
return V_82 ;
}
static int F_53 ( struct V_59 * V_60 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_130 * V_131 = NULL ;
struct V_132 * V_128 ;
int V_87 ;
V_128 = F_74 ( V_2 -> V_133 , V_60 -> V_67 ) ;
if ( F_72 ( V_128 ) ) {
V_87 = F_75 ( V_128 ) ;
F_29 ( V_48 L_5 , V_87 ) ;
return V_87 ;
}
V_131 = F_76 ( V_2 -> V_42 , V_60 -> V_67 ) ;
if ( F_72 ( V_131 ) ) {
V_87 = F_75 ( V_131 ) ;
F_29 ( V_48 L_6 , V_87 ) ;
F_77 ( V_128 ) ;
return V_87 ;
}
V_82 -> V_131 = V_131 ;
V_82 -> V_128 = V_128 ;
return 0 ;
}
static int F_78 ( struct V_134 * V_85 )
{
struct V_81 * V_82 = V_85 -> V_94 ;
struct V_135 V_136 , * V_137 ;
int V_46 ;
F_79 ( V_82 -> V_128 , V_82 -> V_138 ++ ) ;
V_85 -> V_139 = V_82 -> V_128 -> V_129 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 = V_141 ;
V_136 . V_142 = V_143 ;
V_136 . V_144 . V_145 . V_146 = V_85 -> V_99 . V_40 ;
V_136 . V_144 . V_145 . V_129 = V_85 -> V_139 ;
V_136 . V_144 . V_145 . V_131 = V_82 -> V_131 ;
V_136 . V_144 . V_145 . V_147 = V_85 -> V_99 . V_38 ;
V_136 . V_144 . V_145 . V_148 = V_55 ;
V_136 . V_144 . V_145 . V_149 = V_150 |
V_151 |
V_152 ;
V_136 . V_144 . V_145 . V_153 = 0 ;
V_136 . V_154 = V_155 ;
V_137 = & V_136 ;
V_46 = F_80 ( V_82 -> V_4 -> V_156 , & V_136 , & V_137 ) ;
F_13 ( V_137 != & V_136 ) ;
if ( V_46 )
F_81 ( V_48 L_7 ,
V_157 , __LINE__ , V_46 ) ;
return V_46 ;
}
static int F_82 ( struct V_81 * V_82 )
{
struct V_135 V_158 , * V_137 ;
int V_46 = 0 ;
if ( ! V_82 -> V_4 -> V_156 || ! V_82 -> V_128 )
goto V_127;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_140 = V_159 ;
V_158 . V_142 = V_160 ;
V_158 . V_161 . V_162 = V_82 -> V_128 -> V_129 ;
V_158 . V_154 = V_155 ;
V_137 = & V_158 ;
V_46 = F_80 ( V_82 -> V_4 -> V_156 , & V_158 , & V_137 ) ;
if ( V_46 ) {
F_81 ( V_48 L_7 ,
V_157 , __LINE__ , V_46 ) ;
goto V_127;
}
V_127:
return V_46 ;
}
static int F_73 ( struct V_59 * V_60 ,
struct V_81 * V_82 ,
struct V_35 * V_34 ,
unsigned int V_36 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_134 * V_85 = & V_82 -> V_85 ;
T_2 * V_43 ;
int V_44 , V_46 = 0 ;
F_24 ( & V_85 -> V_99 , V_34 , V_36 ) ;
V_43 = F_25 ( V_2 , & V_85 -> V_99 ) ;
if ( F_72 ( V_43 ) ) {
V_46 = F_75 ( V_43 ) ;
V_43 = NULL ;
goto V_127;
}
if ( V_85 -> V_99 . V_38 > V_60 -> V_67 ) {
V_46 = - V_163 ;
goto V_127;
}
for ( V_44 = 0 ; V_44 < V_85 -> V_99 . V_39 ; ++ V_44 )
V_82 -> V_131 -> V_131 [ V_44 ] = V_43 [ V_44 ] ;
V_46 = F_78 ( V_85 ) ;
if ( V_46 )
goto V_127;
F_52 ( V_164 ) ;
V_127:
F_9 ( V_43 ) ;
return V_46 ;
}
static void F_66 ( struct V_59 * V_60 ,
struct V_81 * V_82 )
{
unsigned long V_83 ;
int V_46 ;
if ( ! V_82 -> V_85 . V_99 . V_38 )
return;
V_46 = F_82 ( V_82 ) ;
if ( V_46 )
return;
F_45 ( & V_60 -> V_30 , V_83 ) ;
F_4 ( & V_82 -> V_85 . V_86 , & V_60 -> V_62 ) ;
F_83 ( V_82 -> V_85 . V_99 . V_37 , & V_60 -> V_80 ) ;
F_84 ( & V_60 -> V_109 ) ;
F_48 ( & V_60 -> V_30 , V_83 ) ;
}
static unsigned int F_60 ( struct V_59 * V_60 ,
struct V_29 * V_102 ,
struct V_29 * V_103 ,
int * V_106 )
{
struct V_134 * V_85 , * V_84 ;
unsigned int V_105 = 0 ;
F_19 ( V_165 ) ;
while ( ! F_14 ( V_102 ) ) {
unsigned long V_83 ;
F_45 ( & V_60 -> V_30 , V_83 ) ;
F_22 (mapping, next, unmap_list, m_list) {
* V_106 += V_85 -> V_99 . V_37 ;
F_85 ( & V_85 -> V_86 , & V_165 ) ;
V_105 ++ ;
}
F_48 ( & V_60 -> V_30 , V_83 ) ;
}
F_59 ( & V_165 , V_102 ) ;
return V_105 ;
}
static void F_54 ( struct V_59 * V_60 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_131 )
F_86 ( V_82 -> V_131 ) ;
if ( V_82 -> V_128 )
F_77 ( V_82 -> V_128 ) ;
}
