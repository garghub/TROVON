int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( ! V_10 . V_11 && F_2 ( V_2 -> V_12 ) )
return 0 ;
if ( V_10 . V_11 )
V_5 = & V_4 [ 0 ] ;
else
V_5 = V_2 -> V_12 ;
V_7 = V_5 -> V_7 ;
if ( ! V_7 -> V_13 )
return - V_14 ;
V_9 = V_7 -> V_15 [ V_5 -> V_16 ] ;
V_5 -> V_16 = ( V_5 -> V_16 + 1 ) % V_7 -> V_13 ;
F_3 ( & V_2 -> V_17 . V_18 ) ;
V_2 -> V_17 . V_8 = V_9 ;
F_4 ( & V_2 -> V_17 . V_18 ) ;
return V_3 ;
}
static
void F_5 ( struct V_19 * V_20 ,
T_1 V_21 , T_1 V_22 )
{
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
T_1 V_28 , V_29 ;
T_1 V_30 = V_21 + V_22 ;
if ( V_30 <= V_21 )
return;
F_6 (item, tmp, &mmn->tc_reg_list) {
V_27 = F_7 ( V_24 , struct V_26 , V_31 ) ;
if ( ! V_22 )
break;
V_28 = V_27 -> V_32 ;
V_29 = V_28 + ( V_27 -> V_33 << V_34 ) ;
if ( V_21 < V_28 && V_30 <= V_28 )
break;
if ( V_21 >= V_29 )
continue;
F_8 ( V_27 ) ;
}
}
static void F_9 ( struct V_19 * V_20 , T_1 V_21 , T_1 V_22 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
F_10 ( & V_2 -> V_17 . V_35 ) ;
F_5 ( V_20 , V_21 , V_22 ) ;
F_11 ( & V_2 -> V_17 . V_35 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_25 ;
struct V_19 * V_20 ;
F_6 (item, tmp, &ep->rma_info.mmn_list) {
V_20 = F_7 ( V_24 , struct V_19 , V_31 ) ;
F_9 ( V_20 , 0 , V_36 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_25 ;
struct V_19 * V_20 ;
F_10 ( & V_2 -> V_17 . V_35 ) ;
F_6 (item, tmp, &ep->rma_info.mmn_list) {
V_20 = F_7 ( V_24 , struct V_19 , V_31 ) ;
F_5 ( V_20 , 0 , V_36 ) ;
}
F_11 ( & V_2 -> V_17 . V_35 ) ;
}
static bool F_14 ( struct V_1 * V_2 , T_2 V_37 )
{
if ( ( V_37 >> V_34 ) > V_10 . V_38 )
return false ;
if ( ( F_15 ( & V_2 -> V_17 . V_39 )
+ ( V_37 >> V_34 ) ) >
V_10 . V_38 ) {
F_16 ( V_10 . V_40 . V_41 ,
L_1 ,
V_42 , __LINE__ ,
F_15 ( & V_2 -> V_17 . V_39 ) ,
( 1 + ( V_37 >> V_34 ) ) ) ;
F_17 () ;
F_13 ( V_2 ) ;
}
return true ;
}
static void F_18 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_19 * V_20 ;
V_20 = F_19 ( V_44 , struct V_19 , V_47 ) ;
F_9 ( V_20 , 0 , V_36 ) ;
F_20 ( & V_10 . V_48 ) ;
}
static void F_21 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_21 ,
unsigned long V_30 )
{
struct V_19 * V_20 ;
V_20 = F_19 ( V_44 , struct V_19 , V_47 ) ;
F_9 ( V_20 , V_21 , V_30 - V_21 ) ;
}
static void F_22 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_21 ,
unsigned long V_30 )
{
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_17 ;
struct V_19 * V_20 = NULL ;
struct V_23 * V_24 , * V_25 ;
F_3 ( & V_2 -> V_17 . V_51 ) ;
F_6 (item, tmp, &rma->mmn_list) {
V_20 = F_7 ( V_24 , struct V_19 , V_31 ) ;
F_24 ( & V_20 -> V_47 , V_20 -> V_46 ) ;
F_25 ( V_24 ) ;
F_26 ( V_20 ) ;
}
F_4 ( & V_2 -> V_17 . V_51 ) ;
}
static void F_27 ( struct V_19 * V_20 ,
struct V_45 * V_46 , struct V_1 * V_2 )
{
V_20 -> V_2 = V_2 ;
V_20 -> V_46 = V_46 ;
V_20 -> V_47 . V_52 = & V_53 ;
F_28 ( & V_20 -> V_31 ) ;
F_28 ( & V_20 -> V_54 ) ;
}
static struct V_19 *
F_29 ( struct V_45 * V_46 , struct V_49 * V_50 )
{
struct V_19 * V_20 ;
F_30 (mmn, &rma->mmn_list, list)
if ( V_20 -> V_46 == V_46 )
return V_20 ;
return NULL ;
}
static struct V_19 *
F_31 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_19 * V_20
= F_32 ( sizeof( * V_20 ) , V_55 ) ;
if ( ! V_20 )
return F_33 ( - V_56 ) ;
F_27 ( V_20 , V_57 -> V_46 , V_2 ) ;
if ( F_34 ( & V_20 -> V_47 , V_57 -> V_46 ) ) {
F_26 ( V_20 ) ;
return F_33 ( - V_58 ) ;
}
F_35 ( & V_20 -> V_31 , & V_2 -> V_17 . V_59 ) ;
return V_20 ;
}
void F_36 ( struct V_60 * V_61 )
{
struct V_23 * V_62 , * V_63 ;
struct V_1 * V_2 ;
V_64:
F_17 () ;
F_10 ( & V_10 . V_65 ) ;
F_6 (pos, tmpq, &scif_info.mmu_notif_cleanup) {
V_2 = F_7 ( V_62 , struct V_1 , V_66 ) ;
F_25 ( & V_2 -> V_66 ) ;
F_11 ( & V_10 . V_65 ) ;
F_12 ( V_2 ) ;
F_23 ( V_2 ) ;
goto V_64;
}
F_11 ( & V_10 . V_65 ) ;
}
static bool F_37 ( int V_67 )
{
return ! ! ( V_67 & V_68 ) ;
}
static struct V_19 *
F_29 ( struct V_45 * V_46 ,
struct V_49 * V_50 )
{
return NULL ;
}
static struct V_19 *
F_31 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
return NULL ;
}
void F_36 ( struct V_60 * V_61 )
{
}
static bool F_37 ( int V_67 )
{
return false ;
}
static bool F_14 ( struct V_1 * V_2 , T_2 V_37 )
{
return false ;
}
static int
F_38 ( T_3 V_69 , unsigned long V_70 , T_2 V_22 , int V_71 ,
T_4 * V_72 , struct V_26 * * V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
int V_3 ;
T_5 V_74 ;
T_2 V_75 ;
V_75 = F_39 ( V_22 , V_76 ) ;
V_3 = F_40 ( ( void * ) ( V_70 & V_77 ) ,
V_75 , & V_71 , 0 , & V_74 ) ;
if ( V_3 )
return V_3 ;
V_74 -> V_71 = V_71 ;
V_3 = F_41 ( V_2 , 0 , 0 ,
V_75 >> V_34 ,
( V_78 * ) V_72 ) ;
if ( V_3 )
goto V_79;
* V_73 = F_42 ( V_2 , V_75 >> V_34 ,
* V_72 , true ) ;
if ( ! * V_73 ) {
F_43 ( V_2 , NULL , * V_72 ) ;
V_3 = - V_56 ;
goto V_79;
}
( * V_73 ) -> V_74 = V_74 ;
( * V_73 ) -> V_33 = V_74 -> V_33 ;
( * V_73 ) -> V_71 = V_74 -> V_71 ;
( * V_73 ) -> V_32 = V_70 & V_77 ;
V_3 = F_44 ( V_2 -> V_12 , * V_73 ) ;
if ( V_3 ) {
F_45 ( V_2 , * V_73 ) ;
* V_73 = NULL ;
} else {
* V_72 |= ( V_70 - ( * V_73 ) -> V_32 ) ;
}
return V_3 ;
V_79:
if ( V_3 )
F_46 ( & V_2 -> V_12 -> V_7 -> V_80 ,
L_2 , V_42 , __LINE__ , V_3 ) ;
F_47 ( V_74 ) ;
return V_3 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_8 * V_9 ,
bool V_81 )
{
int V_3 = 0 ;
struct V_82 * V_83 = NULL ;
enum V_84 V_67 = V_85 ;
T_6 V_86 ;
struct V_87 * V_88 ;
if ( ! V_9 ) {
V_3 = - V_89 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
return V_3 ;
}
V_88 = V_9 -> V_90 ;
V_83 = V_88 -> V_91 ( V_9 , 0 , 0 , 0 , V_67 ) ;
if ( ! V_83 ) {
V_3 = - V_56 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_3 = - V_56 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
if ( ! V_81 ) {
F_50 ( V_9 ) ;
} else {
if ( F_51 ( V_9 , V_86 ) == V_94 ) {
V_3 = 0 ;
} else {
V_3 = - V_89 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
}
}
V_92:
return V_3 ;
}
static void F_52 ( void * V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
F_53 ( V_97 ) ;
}
static int F_54 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_3 = 0 ;
struct V_87 * V_88 ;
struct V_82 * V_83 = NULL ;
enum V_84 V_67 = V_98 | V_85 ;
F_55 ( V_99 ) ;
T_6 V_86 ;
enum V_100 V_101 ;
if ( ! V_9 ) {
V_3 = - V_89 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
return V_3 ;
}
V_88 = V_9 -> V_90 ;
V_83 = V_88 -> V_91 ( V_9 , 0 , 0 , 0 , V_67 ) ;
if ( ! V_83 ) {
V_3 = - V_56 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
F_56 ( & V_99 ) ;
V_83 -> V_102 = F_52 ;
V_83 -> V_103 = & V_99 ;
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_3 = - V_56 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
F_50 ( V_9 ) ;
V_3 = F_57 ( & V_99 , V_104 ) ;
if ( ! V_3 ) {
V_3 = - V_89 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
V_3 = 0 ;
V_101 = F_58 ( V_9 , V_86 , NULL , NULL ) ;
if ( V_101 != V_94 ) {
V_3 = - V_89 ;
F_46 ( & V_7 -> V_80 , L_2 ,
V_42 , __LINE__ , V_3 ) ;
goto V_92;
}
V_92:
return V_3 ;
}
static int F_59 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_105 ;
return F_48 ( V_7 , V_9 , V_106 ) ;
}
int F_60 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_105 ;
return F_54 ( V_7 , V_9 ) ;
}
void F_61 ( void )
{
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
F_62 () ;
V_64:
F_10 ( & V_10 . V_65 ) ;
F_6 (item, tmp, &scif_info.rma) {
V_27 = F_7 ( V_24 , struct V_26 ,
V_31 ) ;
V_2 = (struct V_1 * ) V_27 -> V_2 ;
V_9 = V_2 -> V_17 . V_8 ;
F_63 ( & V_27 -> V_31 ) ;
F_11 ( & V_10 . V_65 ) ;
if ( ! V_9 || ! F_64 ( V_2 ) ||
! F_60 ( V_2 -> V_12 -> V_7 ,
V_2 -> V_17 . V_8 ) )
V_27 -> V_107 = V_108 ;
else
F_65 ( & V_2 -> V_12 -> V_7 -> V_80 ,
L_3 ) ;
if ( V_27 -> V_107 == V_108 ) {
if ( V_27 -> type == V_109 )
F_45 ( V_2 , V_27 ) ;
else
F_66 ( V_27 ) ;
F_67 ( & V_2 -> V_17 . V_110 ) ;
}
goto V_64;
}
F_11 ( & V_10 . V_65 ) ;
}
void F_17 ( void )
{
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
F_62 () ;
V_64:
F_10 ( & V_10 . V_65 ) ;
F_6 (item, tmp, &scif_info.rma_tc) {
V_27 = F_7 ( V_24 , struct V_26 , V_31 ) ;
V_2 = (struct V_1 * ) V_27 -> V_2 ;
V_9 = V_2 -> V_17 . V_8 ;
F_63 ( & V_27 -> V_31 ) ;
F_11 ( & V_10 . V_65 ) ;
F_3 ( & V_2 -> V_17 . V_18 ) ;
if ( ! V_9 || ! F_64 ( V_2 ) ||
! F_60 ( V_2 -> V_12 -> V_7 ,
V_2 -> V_17 . V_8 ) ) {
F_68 ( V_27 -> V_33 ,
& V_2 -> V_17 . V_39 ) ;
F_45 ( V_2 , V_27 ) ;
F_67 ( & V_2 -> V_17 . V_111 ) ;
} else {
F_65 ( & V_2 -> V_12 -> V_7 -> V_80 ,
L_3 ) ;
}
F_4 ( & V_2 -> V_17 . V_18 ) ;
goto V_64;
}
F_11 ( & V_10 . V_65 ) ;
}
static inline
void * F_69 ( T_4 V_112 , struct V_26 * V_27 , T_2 V_22 )
{
int V_113 = ( V_112 - V_27 -> V_114 ) >> V_34 ;
T_4 V_115 = V_112 & ~ V_77 ;
void * V_116 = NULL ;
if ( V_27 -> type == V_109 ) {
struct V_117 * * V_118 = V_27 -> V_74 -> V_118 ;
V_116 = F_70 ( V_118 [ V_113 ] ) + V_115 ;
}
return V_116 ;
}
static inline
void * F_71 ( T_4 V_112 , struct V_26 * V_27 ,
T_2 V_22 , struct V_4 * V_80 ,
struct V_119 * V_120 )
{
T_7 V_121 = F_72 ( V_27 , V_112 , NULL , V_120 ) ;
if ( ! F_2 ( V_80 ) && V_27 -> type == V_122 &&
V_80 -> V_7 -> V_123 && ! V_80 -> V_7 -> V_124 )
V_121 = V_121 - V_80 -> V_7 -> V_123 -> V_125 ;
return F_73 ( V_121 , V_22 , V_80 ) ;
}
static inline void
F_74 ( void * V_126 , T_2 V_127 , struct V_128 * V_61 )
{
F_75 ( V_126 , V_127 , V_61 -> V_12 ) ;
}
static inline void
F_76 ( char * V_129 , const char * V_130 , T_2 V_131 )
{
if ( ! V_131 )
return;
F_77 ( ( void V_132 V_133 * ) V_129 , V_130 , -- V_131 ) ;
F_78 () ;
* ( V_129 + V_131 ) = * ( V_130 + V_131 ) ;
}
static inline void F_79 ( char * V_129 , const char * V_130 ,
T_2 V_131 , bool V_134 )
{
if ( V_134 )
F_76 ( V_129 , V_130 , V_131 ) ;
else
F_77 ( ( void V_132 V_133 * ) V_129 , V_130 , V_131 ) ;
}
static inline
void F_80 ( char * V_129 , const char * V_130 , T_2 V_131 )
{
if ( ! V_131 )
return;
F_81 ( V_129 , ( void V_132 V_133 * ) V_130 , -- V_131 ) ;
F_82 () ;
* ( V_129 + V_131 ) = * ( V_130 + V_131 ) ;
}
static inline void F_83 ( char * V_129 , const char * V_130 ,
T_2 V_131 , bool V_134 )
{
if ( V_134 )
F_80 ( V_129 , V_130 , V_131 ) ;
else
F_81 ( V_129 , ( void V_132 V_133 * ) V_130 , V_131 ) ;
}
T_7 F_72 ( struct V_26 * V_27 , V_78 V_112 ,
T_2 * V_135 , struct V_119 * V_120 )
{
int V_136 , V_113 ;
V_78 V_21 , V_30 ;
T_4 V_115 ;
if ( V_27 -> V_33 == V_27 -> V_137 ) {
V_113 = ( V_112 - V_27 -> V_114 ) >> V_34 ;
V_115 = V_112 & ~ V_77 ;
if ( V_135 )
* V_135 = V_76 - V_115 ;
return V_27 -> V_138 [ V_113 ] | V_115 ;
}
if ( V_120 ) {
V_136 = V_120 -> V_139 ;
V_21 = V_120 -> V_114 ;
} else {
V_136 = 0 ;
V_21 = V_27 -> V_114 ;
}
for (; V_136 < V_27 -> V_137 ; V_136 ++ ) {
V_30 = V_21 + ( V_27 -> V_140 [ V_136 ] << V_34 ) ;
if ( V_112 >= V_21 && V_112 < V_30 ) {
if ( V_120 ) {
V_120 -> V_139 = V_136 ;
V_120 -> V_114 = V_21 ;
}
if ( V_135 )
* V_135 = V_30 - V_112 ;
return ( V_27 -> V_138 [ V_136 ] + ( V_112 - V_21 ) ) ;
}
V_21 += ( V_27 -> V_140 [ V_136 ] << V_34 ) ;
}
F_46 ( V_10 . V_40 . V_41 ,
L_4 ,
V_42 , __LINE__ , V_27 , V_112 ) ;
return V_141 ;
}
static void F_84 ( V_78 V_114 , struct V_26 * V_27 ,
T_8 * V_142 , T_2 V_143 , bool V_144 )
{
void * V_145 ;
T_2 V_146 ;
int V_147 ;
V_78 V_148 ;
V_147 = V_114 & ~ V_77 ;
V_146 = V_76 - V_147 ;
if ( V_143 < V_146 )
V_146 = V_143 ;
V_145 = F_69 ( V_114 , V_27 , V_146 ) ;
if ( ! V_145 )
return;
if ( V_144 )
memcpy ( V_142 , V_145 , V_146 ) ;
else
memcpy ( V_145 , V_142 , V_146 ) ;
V_114 += V_146 ;
V_142 += V_146 ;
V_143 -= V_146 ;
V_148 = V_27 -> V_114 +
( V_27 -> V_33 << V_34 ) ;
while ( V_143 ) {
if ( V_114 == V_148 ) {
V_27 = F_85 ( V_27 , V_31 ) ;
V_148 = V_27 -> V_114 +
( V_27 -> V_33 << V_34 ) ;
}
V_146 = F_86 ( V_76 , V_143 ) ;
V_145 = F_69 ( V_114 , V_27 , V_146 ) ;
if ( ! V_145 )
return;
if ( V_144 )
memcpy ( V_142 , V_145 , V_146 ) ;
else
memcpy ( V_145 , V_142 , V_146 ) ;
V_114 += V_146 ;
V_142 += V_146 ;
V_143 -= V_146 ;
}
}
static void F_87 ( void * V_149 )
{
struct V_150 * V_151 = V_149 ;
if ( V_151 -> V_152 )
F_84 ( V_151 -> V_153 ,
V_151 -> V_152 ,
V_151 -> V_154 +
V_151 -> V_155 ,
V_151 -> V_22 , false ) ;
F_88 ( V_151 -> V_156 , V_151 -> V_7 ,
V_157 ) ;
if ( V_151 -> V_158 )
F_89 ( V_159 ,
V_151 -> V_160 ) ;
else
F_26 ( V_151 -> V_160 ) ;
}
static int
F_90 ( struct V_128 * V_61 ,
T_8 * V_142 , struct V_8 * V_9 ,
bool V_161 )
{
struct V_150 * V_151 = V_61 -> V_151 ;
T_7 V_162 , V_163 ;
T_7 V_156 = V_151 -> V_156 ;
T_2 V_146 , V_164 = 0 , V_165 = V_61 -> V_22 ;
int V_166 , V_167 = 0 ;
V_78 V_148 , V_114 ;
struct V_26 * V_27 ;
void * V_168 ;
T_2 V_169 ;
struct V_82 * V_83 ;
struct V_87 * V_80 = V_9 -> V_90 ;
T_6 V_86 ;
if ( V_161 ) {
V_114 = V_61 -> V_153 ;
V_27 = V_61 -> V_152 ;
} else {
V_114 = V_61 -> V_170 ;
V_27 = V_61 -> V_171 ;
}
V_166 = V_114 & ( V_172 - 1 ) ;
if ( V_166 ) {
V_146 = V_172 - V_166 ;
V_146 = F_86 ( V_146 , V_165 ) ;
V_168 = F_71 ( V_114 , V_27 ,
V_146 ,
V_61 -> V_12 ,
NULL ) ;
if ( ! V_168 )
return - V_56 ;
if ( V_161 )
F_79 ( V_168 , V_142 ,
V_146 ,
V_61 -> V_134 &&
! ( V_165 - V_146 ) ) ;
else
F_83 ( V_142 , V_168 ,
V_146 , V_61 -> V_134 &&
! ( V_165 - V_146 ) ) ;
F_74 ( V_168 , V_146 , V_61 ) ;
V_114 += V_146 ;
V_142 += V_146 ;
V_156 += V_146 ;
V_165 -= V_146 ;
}
V_166 = V_114 & ~ V_77 ;
V_148 = V_27 -> V_114 +
( V_27 -> V_33 << V_34 ) ;
V_169 = V_165 & ( V_172 - 1 ) ;
V_165 -= V_169 ;
while ( V_165 ) {
if ( V_114 == V_148 ) {
V_27 = F_85 ( V_27 , V_31 ) ;
V_148 = V_27 -> V_114 +
( V_27 -> V_33 << V_34 ) ;
}
if ( F_91 () )
V_163 = V_156 ;
else
V_163 = ( T_7 ) F_92 ( V_142 ) ;
V_162 = F_72 ( V_27 , V_114 ,
& V_164 ,
NULL ) ;
V_146 = F_86 ( V_164 , V_165 ) ;
if ( V_161 ) {
if ( V_61 -> V_134 && ! V_169 &&
! ( V_165 - V_146 ) &&
V_146 != V_172 ) {
V_83 =
V_80 -> V_91 ( V_9 ,
V_162 ,
V_163 ,
V_146 -
V_172 ,
V_85 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
V_114 += ( V_146 - V_172 ) ;
V_163 += ( V_146 - V_172 ) ;
V_162 += ( V_146 - V_172 ) ;
V_165 -= ( V_146 - V_172 ) ;
V_146 = V_165 ;
V_83 =
V_80 -> V_91 ( V_9 ,
V_162 ,
V_163 ,
V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
} else {
V_83 =
V_80 -> V_91 ( V_9 ,
V_162 ,
V_163 ,
V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
}
} else {
V_83 = V_80 -> V_91 ( V_9 , V_163 ,
V_162 , V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
}
if ( V_167 < 0 )
goto V_3;
V_114 += V_146 ;
V_142 += V_146 ;
V_156 += V_146 ;
V_165 -= V_146 ;
V_166 = 0 ;
}
if ( V_169 ) {
if ( V_114 == V_148 ) {
V_27 = F_85 ( V_27 , V_31 ) ;
V_148 = V_27 -> V_114 +
( V_27 -> V_33 << V_34 ) ;
}
V_168 = F_71 ( V_114 , V_27 , V_169 ,
V_61 -> V_12 ,
NULL ) ;
if ( ! V_168 )
return - V_56 ;
if ( V_61 -> V_134 ) {
struct V_4 * V_173 = V_61 -> V_12 ;
V_167 = F_60 ( V_173 -> V_7 , V_9 ) ;
if ( V_167 )
return V_167 ;
}
if ( V_161 )
F_79 ( V_168 , V_142 ,
V_169 , V_61 -> V_134 ) ;
else
F_83 ( V_142 , V_168 ,
V_169 , V_61 -> V_134 ) ;
F_74 ( V_168 , V_169 , V_61 ) ;
}
V_83 = V_80 -> V_91 ( V_9 , 0 , 0 , 0 , V_98 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
return V_167 ;
}
V_83 -> V_102 = & F_87 ;
V_83 -> V_103 = V_151 ;
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
return V_167 ;
}
F_50 ( V_9 ) ;
return 0 ;
V_3:
F_46 ( V_10 . V_40 . V_41 ,
L_5 ,
V_42 , __LINE__ , V_167 ) ;
return V_167 ;
}
static int F_93 ( struct V_128 * V_61 ,
struct V_8 * V_9 )
{
T_7 V_174 , V_175 ;
T_2 V_146 , V_165 , V_176 = 0 ;
T_2 V_177 = 0 ;
struct V_119 V_178 ;
struct V_119 V_179 ;
V_78 V_180 , V_181 ;
struct V_26 * V_171 = V_61 -> V_171 ;
struct V_26 * V_152 = V_61 -> V_152 ;
V_78 V_170 = V_61 -> V_170 , V_153 = V_61 -> V_153 ;
int V_167 = 0 ;
struct V_82 * V_83 ;
struct V_87 * V_80 = V_9 -> V_90 ;
T_6 V_86 ;
V_165 = V_61 -> V_22 ;
F_94 ( V_171 , & V_178 ) ;
F_94 ( V_152 , & V_179 ) ;
V_180 = V_171 -> V_114 +
( V_171 -> V_33 << V_34 ) ;
V_181 = V_152 -> V_114 +
( V_152 -> V_33 << V_34 ) ;
while ( V_165 ) {
if ( V_170 == V_180 ) {
V_171 = F_85 ( V_171 , V_31 ) ;
V_180 = V_171 -> V_114 +
( V_171 -> V_33 << V_34 ) ;
F_94 ( V_171 , & V_178 ) ;
}
if ( V_153 == V_181 ) {
V_152 = F_85 ( V_152 , V_31 ) ;
V_181 = V_152 -> V_114 +
( V_152 -> V_33 << V_34 ) ;
F_94 ( V_152 , & V_179 ) ;
}
V_174 = F_72 ( V_171 , V_170 ,
& V_176 ,
& V_178 ) ;
V_175 = F_72 ( V_152 , V_153 ,
& V_177 ,
& V_179 ) ;
V_146 = F_86 ( V_176 , V_177 ) ;
V_146 = F_86 ( V_146 , V_165 ) ;
if ( V_61 -> V_134 && ! ( V_165 - V_146 ) ) {
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 ,
V_146 - 1 ,
V_85 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
V_170 += ( V_146 - 1 ) ;
V_153 += ( V_146 - 1 ) ;
V_174 += ( V_146 - 1 ) ;
V_175 += ( V_146 - 1 ) ;
V_165 -= ( V_146 - 1 ) ;
V_146 = V_165 ;
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 , V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
} else {
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 , V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
}
V_170 += V_146 ;
V_153 += V_146 ;
V_165 -= V_146 ;
}
return V_167 ;
V_3:
F_46 ( V_10 . V_40 . V_41 ,
L_5 ,
V_42 , __LINE__ , V_167 ) ;
return V_167 ;
}
static int F_95 ( struct V_128 * V_61 ,
struct V_8 * V_9 )
{
T_7 V_174 , V_175 ;
T_2 V_146 , V_165 , V_169 , V_176 = 0 ;
T_2 V_177 = 0 ;
int V_182 ;
V_78 V_180 , V_181 ;
struct V_119 V_178 ;
struct V_119 V_179 ;
void * V_183 , * V_184 ;
struct V_26 * V_171 = V_61 -> V_171 ;
struct V_26 * V_152 = V_61 -> V_152 ;
V_78 V_170 = V_61 -> V_170 , V_153 = V_61 -> V_153 ;
int V_167 = 0 ;
struct V_82 * V_83 ;
struct V_87 * V_80 = V_9 -> V_90 ;
T_6 V_86 ;
V_165 = V_61 -> V_22 ;
F_94 ( V_171 , & V_178 ) ;
F_94 ( V_152 , & V_179 ) ;
V_182 = V_170 & ( V_172 - 1 ) ;
if ( V_182 != 0 ) {
V_146 = V_172 - V_182 ;
V_146 = F_86 ( V_146 , V_165 ) ;
V_174 = F_96 ( V_171 , V_170 ) ;
V_175 = F_96 ( V_152 , V_153 ) ;
if ( V_171 -> type == V_109 )
V_183 = F_69 ( V_170 , V_171 ,
V_146 ) ;
else
V_183 = F_71 ( V_170 , V_171 ,
V_146 ,
V_61 -> V_12 , NULL ) ;
if ( ! V_183 )
return - V_56 ;
if ( V_152 -> type == V_109 )
V_184 = F_69 ( V_153 , V_152 ,
V_146 ) ;
else
V_184 = F_71 ( V_153 , V_152 ,
V_146 ,
V_61 -> V_12 , NULL ) ;
if ( ! V_184 ) {
if ( V_171 -> type != V_109 )
F_74 ( V_183 , V_146 , V_61 ) ;
return - V_56 ;
}
if ( V_171 -> type == V_109 )
F_79 ( V_184 , V_183 , V_146 ,
V_165 == V_146 ?
V_61 -> V_134 : false ) ;
else
F_83 ( V_184 , V_183 , V_146 ,
V_165 == V_146 ?
V_61 -> V_134 : false ) ;
if ( V_171 -> type != V_109 )
F_74 ( V_183 , V_146 , V_61 ) ;
if ( V_152 -> type != V_109 )
F_74 ( V_184 , V_146 , V_61 ) ;
V_170 += V_146 ;
V_153 += V_146 ;
V_165 -= V_146 ;
}
V_180 = V_171 -> V_114 +
( V_171 -> V_33 << V_34 ) ;
V_181 = V_152 -> V_114 +
( V_152 -> V_33 << V_34 ) ;
V_169 = V_165 & ( V_172 - 1 ) ;
V_165 -= V_169 ;
while ( V_165 ) {
if ( V_170 == V_180 ) {
V_171 = F_85 ( V_171 , V_31 ) ;
V_180 = V_171 -> V_114 +
( V_171 -> V_33 << V_34 ) ;
F_94 ( V_171 , & V_178 ) ;
}
if ( V_153 == V_181 ) {
V_152 = F_85 ( V_152 , V_31 ) ;
V_181 = V_152 -> V_114 +
( V_152 -> V_33 << V_34 ) ;
F_94 ( V_152 , & V_179 ) ;
}
V_174 = F_72 ( V_171 , V_170 ,
& V_176 ,
& V_178 ) ;
V_175 = F_72 ( V_152 , V_153 ,
& V_177 ,
& V_179 ) ;
V_146 = F_86 ( V_176 , V_177 ) ;
V_146 = F_86 ( V_146 , V_165 ) ;
if ( V_61 -> V_134 && ! V_169 &&
! ( V_165 - V_146 ) ) {
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 ,
V_146 -
V_172 ,
V_85 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
V_170 += ( V_146 - V_172 ) ;
V_153 += ( V_146 - V_172 ) ;
V_174 += ( V_146 - V_172 ) ;
V_175 += ( V_146 - V_172 ) ;
V_165 -= ( V_146 - V_172 ) ;
V_146 = V_165 ;
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 ,
V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
} else {
V_83 = V_80 -> V_91 ( V_9 , V_175 ,
V_174 ,
V_146 , 0 ) ;
if ( ! V_83 ) {
V_167 = - V_56 ;
goto V_3;
}
V_86 = V_83 -> V_93 ( V_83 ) ;
if ( F_49 ( V_86 ) ) {
V_167 = - V_56 ;
goto V_3;
}
F_50 ( V_9 ) ;
}
V_170 += V_146 ;
V_153 += V_146 ;
V_165 -= V_146 ;
}
V_165 = V_169 ;
if ( V_165 ) {
V_146 = V_165 ;
if ( V_170 == V_180 )
V_171 = F_85 ( V_171 , V_31 ) ;
if ( V_153 == V_181 )
V_152 = F_85 ( V_152 , V_31 ) ;
V_174 = F_96 ( V_171 , V_170 ) ;
V_175 = F_96 ( V_152 , V_153 ) ;
if ( V_61 -> V_134 ) {
struct V_4 * V_173 = V_61 -> V_12 ;
V_167 = F_59 ( V_173 -> V_7 , V_9 ) ;
if ( V_167 )
return V_167 ;
}
if ( V_171 -> type == V_109 )
V_183 = F_69 ( V_170 , V_171 ,
V_146 ) ;
else
V_183 = F_71 ( V_170 , V_171 ,
V_146 ,
V_61 -> V_12 , NULL ) ;
if ( ! V_183 )
return - V_56 ;
if ( V_152 -> type == V_109 )
V_184 = F_69 ( V_153 , V_152 ,
V_146 ) ;
else
V_184 = F_71 ( V_153 , V_152 ,
V_146 ,
V_61 -> V_12 , NULL ) ;
if ( ! V_184 ) {
if ( V_171 -> type != V_109 )
F_74 ( V_183 , V_146 , V_61 ) ;
return - V_56 ;
}
if ( V_171 -> type == V_109 )
F_79 ( V_184 , V_183 , V_146 ,
V_61 -> V_134 ) ;
else
F_83 ( V_184 , V_183 ,
V_146 , V_61 -> V_134 ) ;
if ( V_171 -> type != V_109 )
F_74 ( V_183 , V_146 , V_61 ) ;
if ( V_152 -> type != V_109 )
F_74 ( V_184 , V_146 , V_61 ) ;
V_165 -= V_146 ;
}
return V_167 ;
V_3:
F_46 ( V_10 . V_40 . V_41 ,
L_5 ,
V_42 , __LINE__ , V_167 ) ;
return V_167 ;
}
static int F_97 ( struct V_128 * V_61 )
{
void * V_183 , * V_184 ;
T_2 V_146 , V_165 ;
int V_185 , V_186 ;
V_78 V_170 = V_61 -> V_170 , V_153 = V_61 -> V_153 ;
struct V_26 * V_171 = V_61 -> V_171 ;
struct V_26 * V_152 = V_61 -> V_152 ;
V_78 V_180 , V_181 ;
int V_167 = 0 ;
struct V_119 V_178 ;
struct V_119 V_179 ;
V_165 = V_61 -> V_22 ;
F_94 ( V_171 , & V_178 ) ;
F_94 ( V_152 , & V_179 ) ;
while ( V_165 ) {
V_185 = V_170 & ~ V_77 ;
V_186 = V_153 & ~ V_77 ;
V_146 = F_86 ( V_76 -
F_98 ( V_185 , V_186 ) ,
V_165 ) ;
if ( V_171 -> type == V_109 )
V_183 = F_69 ( V_170 , V_171 ,
V_146 ) ;
else
V_183 = F_71 ( V_170 , V_171 ,
V_146 ,
V_61 -> V_12 ,
& V_178 ) ;
if ( ! V_183 ) {
V_167 = - V_56 ;
goto error;
}
if ( V_152 -> type == V_109 )
V_184 = F_69 ( V_153 , V_152 ,
V_146 ) ;
else
V_184 = F_71 ( V_153 , V_152 ,
V_146 ,
V_61 -> V_12 ,
& V_179 ) ;
if ( ! V_184 ) {
if ( V_171 -> type == V_122 )
F_74 ( V_183 , V_146 , V_61 ) ;
V_167 = - V_56 ;
goto error;
}
if ( V_61 -> V_187 ) {
memcpy ( V_184 , V_183 , V_146 ) ;
} else {
if ( V_171 -> type == V_109 )
F_77 ( ( void V_132 V_133 * ) V_184 ,
V_183 , V_146 ) ;
else
F_81 ( V_184 ,
( void V_132 V_133 * ) V_183 ,
V_146 ) ;
}
if ( V_171 -> type == V_122 )
F_74 ( V_183 , V_146 , V_61 ) ;
if ( V_152 -> type == V_122 )
F_74 ( V_184 , V_146 , V_61 ) ;
V_170 += V_146 ;
V_153 += V_146 ;
V_165 -= V_146 ;
if ( V_165 ) {
V_180 = V_171 -> V_114 +
( V_171 -> V_33 << V_34 ) ;
V_181 = V_152 -> V_114 +
( V_152 -> V_33 << V_34 ) ;
if ( V_170 == V_180 ) {
V_171 = F_85 ( V_171 , V_31 ) ;
F_94 ( V_171 ,
& V_178 ) ;
}
if ( V_153 == V_181 ) {
V_152 = F_85 ( V_152 , V_31 ) ;
F_94 ( V_152 ,
& V_179 ) ;
}
}
}
error:
return V_167 ;
}
static int F_99 ( struct V_1 * V_69 ,
struct V_128 * V_61 ,
struct V_8 * V_9 , T_4 V_188 )
{
int V_182 , V_189 ;
V_78 V_170 = V_61 -> V_170 , V_153 = V_61 -> V_153 ;
T_8 * V_142 = NULL ;
bool V_161 = true , V_190 = false ;
struct V_150 * V_151 ;
T_7 V_174 , V_175 ;
int V_3 ;
if ( F_100 ( V_9 -> V_90 , 1 , 1 , 1 ) )
return F_93 ( V_61 , V_9 ) ;
V_182 = V_170 & ( V_172 - 1 ) ;
V_189 = V_153 & ( V_172 - 1 ) ;
if ( V_189 == V_182 )
return F_95 ( V_61 , V_9 ) ;
if ( V_61 -> V_187 )
return F_97 ( V_61 ) ;
V_174 = F_96 ( V_61 -> V_171 , V_170 ) ;
V_175 = F_96 ( V_61 -> V_152 , V_153 ) ;
V_161 = V_61 -> V_171 -> type == V_109 ;
V_190 = V_61 -> V_152 -> type == V_109 ;
V_190 = V_190 ;
V_151 = F_32 ( sizeof( * V_151 ) , V_55 ) ;
if ( ! V_151 )
goto error;
V_61 -> V_151 = V_151 ;
V_151 -> V_191 = V_151 ;
V_151 -> V_192 = & F_87 ;
if ( V_61 -> V_22 + ( V_172 << 1 ) < V_157 ) {
V_151 -> V_158 = false ;
V_142 = F_101 ( V_61 -> V_22 + ( V_172 << 1 ) ,
V_55 ) ;
if ( ! V_142 )
goto V_193;
V_151 -> V_160 = V_142 ;
if ( ! F_102 ( ( T_1 ) V_142 , V_172 ) )
V_142 = F_103 ( V_142 , V_172 ) ;
} else {
V_151 -> V_158 = true ;
V_142 = F_104 ( V_159 , V_55 ) ;
if ( ! V_142 )
goto V_193;
V_151 -> V_160 = V_142 ;
}
if ( V_161 ) {
V_142 += V_189 ;
F_84 ( V_61 -> V_170 , V_61 -> V_171 ,
V_142 , V_61 -> V_22 , true ) ;
} else {
V_151 -> V_152 = V_61 -> V_152 ;
V_151 -> V_153 = V_61 -> V_153 ;
V_61 -> V_170 = V_61 -> V_170 - V_182 ;
V_151 -> V_22 = V_61 -> V_22 ;
V_61 -> V_22 = F_39 ( V_61 -> V_22 + V_182 , V_172 ) ;
V_151 -> V_155 = V_182 ;
}
V_151 -> V_154 = V_142 ;
V_3 = F_105 ( & V_151 -> V_156 , V_142 ,
V_61 -> V_12 , V_157 ) ;
if ( V_3 )
goto V_194;
V_151 -> V_7 = V_61 -> V_12 ;
if ( F_90 ( V_61 , V_142 , V_9 , V_161 ) < 0 )
goto V_194;
if ( ! V_161 )
V_61 -> V_195 = V_196 ;
return 0 ;
V_194:
if ( V_151 -> V_158 )
F_89 ( V_159 , V_151 -> V_160 ) ;
else
F_26 ( V_151 -> V_160 ) ;
V_193:
F_26 ( V_151 ) ;
error:
return - V_56 ;
}
static int F_106 ( T_3 V_69 , T_4 V_188 , unsigned long V_70 ,
T_2 V_22 , T_4 V_197 , int V_67 ,
enum V_198 V_199 , bool V_200 )
{
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
struct V_201 V_202 ;
struct V_201 V_203 ;
struct V_26 * V_204 = NULL ;
struct V_26 * V_205 = NULL ;
struct V_128 V_206 ;
bool V_187 ;
int V_3 = 0 ;
struct V_8 * V_9 ;
struct V_19 * V_20 = NULL ;
bool V_207 = false ;
struct V_90 * V_208 ;
V_3 = F_107 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_67 && ! ( V_67 & ( V_209 | V_68 |
V_210 | V_211 ) ) )
return - V_105 ;
V_187 = F_2 ( V_2 -> V_12 ) ? true : false ;
V_206 . V_195 = ( ( V_67 & V_210 ) && V_200 ) ?
V_212 : 0 ;
V_206 . V_134 = ! ! ( ( V_67 & V_211 ) && V_200 ) ;
if ( V_187 && F_91 () ) {
V_67 |= V_209 ;
V_206 . V_195 = 0x0 ;
}
V_207 = F_37 ( V_67 ) ;
V_202 . V_73 = & V_205 ;
V_202 . V_114 = V_197 ;
V_202 . V_135 = V_22 ;
V_202 . V_71 = V_199 == V_213 ? V_214 : V_215 ;
V_202 . type = V_216 ;
V_202 . V_217 = & V_2 -> V_17 . V_218 ;
V_208 = F_108 ( V_2 -> V_12 ) ;
if ( F_109 ( V_208 ) ) {
V_3 = F_110 ( V_208 ) ;
return V_3 ;
}
if ( V_70 && V_207 ) {
F_3 ( & V_2 -> V_17 . V_51 ) ;
V_20 = F_29 ( V_57 -> V_46 , & V_2 -> V_17 ) ;
if ( ! V_20 )
V_20 = F_31 ( V_57 -> V_46 , V_2 ) ;
F_4 ( & V_2 -> V_17 . V_51 ) ;
if ( F_109 ( V_20 ) ) {
F_111 ( V_208 ) ;
return F_110 ( V_20 ) ;
}
V_207 = V_207 && ! F_14 ( V_2 , V_22 ) ;
}
F_3 ( & V_2 -> V_17 . V_18 ) ;
if ( V_70 ) {
V_203 . V_73 = & V_204 ;
V_203 . V_135 = F_39 ( V_22 + ( V_70 & ~ V_77 ) ,
V_76 ) ;
V_203 . V_32 = V_70 & V_77 ;
V_203 . V_71 = ( V_199 == V_213 ?
V_215 : V_214 | V_215 ) ;
if ( V_20 ) {
F_10 ( & V_2 -> V_17 . V_35 ) ;
V_203 . V_217 = & V_20 -> V_54 ;
V_3 = F_112 ( V_2 , & V_203 ) ;
F_11 ( & V_2 -> V_17 . V_35 ) ;
}
if ( ! V_20 || V_3 ) {
V_3 = F_38 ( V_69 , V_203 . V_32 ,
V_203 . V_135 , V_203 . V_71 ,
& V_188 , & V_204 ) ;
if ( V_3 ) {
F_4 ( & V_2 -> V_17 . V_18 ) ;
goto error;
}
if ( ! V_207 )
goto V_219;
F_113 ( & V_2 -> V_17 . V_111 ) ;
F_114 ( V_204 -> V_33 ,
& V_2 -> V_17 . V_39 ) ;
if ( V_20 ) {
F_10 ( & V_2 -> V_17 . V_35 ) ;
F_115 ( V_204 ,
& V_20 -> V_54 ) ;
F_11 ( & V_2 -> V_17 . V_35 ) ;
}
}
V_219:
V_188 = V_204 -> V_114 +
( V_70 - V_204 -> V_32 ) ;
} else {
V_203 . V_73 = & V_204 ;
V_203 . V_114 = V_188 ;
V_203 . V_71 = V_199 == V_213 ? V_215 : V_214 ;
V_203 . V_135 = V_22 ;
V_203 . type = V_216 ;
V_203 . V_217 = & V_2 -> V_17 . V_220 ;
V_3 = F_116 ( & V_203 ) ;
if ( V_3 ) {
F_4 ( & V_2 -> V_17 . V_18 ) ;
goto error;
}
}
V_3 = F_116 ( & V_202 ) ;
if ( V_3 ) {
F_4 ( & V_2 -> V_17 . V_18 ) ;
goto error;
}
V_206 . V_22 = V_22 ;
V_206 . V_187 = V_187 ;
V_206 . V_12 = V_2 -> V_12 ;
if ( V_199 == V_213 ) {
V_206 . V_170 = V_188 ;
V_206 . V_171 = V_204 ;
V_206 . V_153 = V_197 ;
V_206 . V_152 = V_205 ;
} else {
V_206 . V_170 = V_197 ;
V_206 . V_171 = V_205 ;
V_206 . V_153 = V_188 ;
V_206 . V_152 = V_204 ;
}
if ( V_67 & V_209 ) {
F_97 ( & V_206 ) ;
} else {
V_9 = V_2 -> V_17 . V_8 ;
V_3 = F_99 ( V_69 , & V_206 ,
V_9 , V_188 ) ;
}
if ( V_70 && ! V_207 )
F_113 ( & V_2 -> V_17 . V_110 ) ;
F_4 ( & V_2 -> V_17 . V_18 ) ;
if ( V_200 ) {
struct V_4 * V_173 = V_2 -> V_12 ;
if ( V_206 . V_195 == V_212 )
V_3 = F_59 ( V_173 -> V_7 ,
V_2 -> V_17 . V_8 ) ;
else if ( V_206 . V_195 == V_196 )
V_3 = F_60 ( V_173 -> V_7 ,
V_2 -> V_17 . V_8 ) ;
}
if ( V_70 && ! V_207 )
F_117 ( V_204 , & V_10 . V_50 ) ;
F_111 ( V_208 ) ;
return V_3 ;
error:
if ( V_3 ) {
if ( V_70 && V_204 && ! V_207 )
F_45 ( V_2 , V_204 ) ;
F_46 ( V_10 . V_40 . V_41 ,
L_6 ,
V_42 , __LINE__ , V_3 , V_22 ) ;
}
F_111 ( V_208 ) ;
return V_3 ;
}
int F_118 ( T_3 V_69 , T_4 V_188 , T_2 V_22 ,
T_4 V_197 , int V_67 )
{
int V_3 ;
F_119 ( V_10 . V_40 . V_41 ,
L_7 ,
V_69 , V_188 , V_22 , V_197 , V_67 ) ;
if ( F_120 ( V_188 , V_197 ) ) {
while ( V_22 > V_221 ) {
V_3 = F_106 ( V_69 , V_188 , 0x0 ,
V_221 ,
V_197 , V_67 ,
V_222 , false ) ;
if ( V_3 )
goto V_223;
V_188 += V_221 ;
V_197 += V_221 ;
V_22 -= V_221 ;
}
}
V_3 = F_106 ( V_69 , V_188 , 0x0 , V_22 ,
V_197 , V_67 , V_222 , true ) ;
V_223:
return V_3 ;
}
int F_121 ( T_3 V_69 , T_4 V_188 , T_2 V_22 ,
T_4 V_197 , int V_67 )
{
int V_3 ;
F_119 ( V_10 . V_40 . V_41 ,
L_8 ,
V_69 , V_188 , V_22 , V_197 , V_67 ) ;
if ( F_120 ( V_188 , V_197 ) ) {
while ( V_22 > V_221 ) {
V_3 = F_106 ( V_69 , V_188 , 0x0 ,
V_221 ,
V_197 , V_67 ,
V_213 , false ) ;
if ( V_3 )
goto V_224;
V_188 += V_221 ;
V_197 += V_221 ;
V_22 -= V_221 ;
}
}
V_3 = F_106 ( V_69 , V_188 , 0x0 , V_22 ,
V_197 , V_67 , V_213 , true ) ;
V_224:
return V_3 ;
}
int F_122 ( T_3 V_69 , void * V_70 , T_2 V_22 ,
T_4 V_197 , int V_67 )
{
int V_3 ;
F_119 ( V_10 . V_40 . V_41 ,
L_9 ,
V_69 , V_70 , V_22 , V_197 , V_67 ) ;
if ( F_120 ( ( T_4 V_133 ) V_70 , V_197 ) ) {
if ( V_22 > V_221 )
V_67 &= ~ V_68 ;
while ( V_22 > V_221 ) {
V_3 = F_106 ( V_69 , 0 , ( T_1 ) V_70 ,
V_221 ,
V_197 , V_67 ,
V_222 , false ) ;
if ( V_3 )
goto V_225;
V_70 += V_221 ;
V_197 += V_221 ;
V_22 -= V_221 ;
}
}
V_3 = F_106 ( V_69 , 0 , ( T_1 ) V_70 , V_22 ,
V_197 , V_67 , V_222 , true ) ;
V_225:
return V_3 ;
}
int F_123 ( T_3 V_69 , void * V_70 , T_2 V_22 ,
T_4 V_197 , int V_67 )
{
int V_3 ;
F_119 ( V_10 . V_40 . V_41 ,
L_10 ,
V_69 , V_70 , V_22 , V_197 , V_67 ) ;
if ( F_120 ( ( T_4 V_133 ) V_70 , V_197 ) ) {
if ( V_22 > V_221 )
V_67 &= ~ V_68 ;
while ( V_22 > V_221 ) {
V_3 = F_106 ( V_69 , 0 , ( T_1 ) V_70 ,
V_221 ,
V_197 , V_67 ,
V_213 , false ) ;
if ( V_3 )
goto V_226;
V_70 += V_221 ;
V_197 += V_221 ;
V_22 -= V_221 ;
}
}
V_3 = F_106 ( V_69 , 0 , ( T_1 ) V_70 , V_22 ,
V_197 , V_67 , V_213 , true ) ;
V_226:
return V_3 ;
}
