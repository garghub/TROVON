static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_4 [ V_3 ] . V_5 != V_6 ;
}
void F_2 ( struct V_7 * V_8 )
{
int V_9 ;
int V_10 ;
int V_11 = 0 ;
struct V_1 * V_2 ;
V_10 = F_3 ( & V_1 [ 0 ] . V_12 ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
int V_12 = F_3 ( & V_1 [ V_9 ] . V_12 ) ;
if ( V_12 < V_10 ) {
V_11 = V_9 ;
V_10 = V_12 ;
}
}
V_2 = & V_1 [ V_11 ] ;
V_8 -> V_2 = V_2 ;
F_4 ( & V_2 -> V_12 ) ;
}
void F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_8 -> V_2 = NULL ;
F_6 ( & V_2 -> V_12 ) ;
}
static inline unsigned long F_7 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_8 ( V_2 -> V_14 [ V_3 ] ) ;
}
static inline unsigned long F_9 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return ( unsigned long ) F_10 ( F_7 ( V_2 , V_3 ) ) ;
}
static inline void F_11 ( struct V_15 * V_16 , struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_17 = V_2 - V_1 ;
union V_18 V_19 = { . V_20 = { . V_17 = V_17 + 1 , . V_3 = V_3 } } ;
F_12 ( sizeof( V_19 ) > sizeof( V_19 . V_21 ) ) ;
V_16 -> V_21 = V_19 . V_21 ;
}
static int F_13 ( struct V_15 * V_16 ,
unsigned int * V_22 , unsigned int * V_23 )
{
union V_18 V_19 = { . V_21 = V_16 -> V_21 } ;
struct V_1 * V_2 ;
unsigned int V_17 , V_3 ;
V_17 = V_19 . V_20 . V_17 - 1 ;
if ( V_17 < 0 || V_17 >= V_13 )
return 0 ;
V_2 = & V_1 [ V_17 ] ;
V_3 = V_19 . V_20 . V_3 ;
if ( ( V_3 < 0 ) || ( V_3 >= V_24 ) )
return 0 ;
if ( V_2 -> V_14 [ V_3 ] != V_16 )
return 0 ;
* V_22 = V_17 ;
* V_23 = V_3 ;
return 1 ;
}
static T_2 F_14 ( T_3 * V_25 )
{
return ( T_2 ) V_25 -> V_26 ;
}
static void F_15 ( T_3 * V_25 , T_2 V_27 )
{
V_25 -> V_26 = V_27 ;
}
static inline T_4 F_16 ( unsigned V_9 )
{
return V_9 & ( V_24 - 1 ) ;
}
static inline T_4 F_17 ( struct V_1 * V_2 )
{
return V_24 -
V_2 -> V_28 + V_2 -> V_29 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_30 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
int V_31 = F_21 ( V_8 -> V_32 -> V_33 , V_34 ) ;
if ( V_8 -> V_35 || V_8 -> V_36 || V_8 -> V_37 )
V_31 += V_38 + 1 ;
return V_31 ;
}
int F_22 ( struct V_7 * V_8 )
{
T_1 V_39 = V_8 -> V_40 ;
T_1 V_41 = F_20 ( V_8 ) ;
return ( ( V_8 -> V_42 . V_43 -> V_44 - V_39 ) < V_41 ) ||
( ( V_8 -> V_42 . V_45 + V_46 - V_39 ) < V_41 ) ;
}
int F_23 ( struct V_7 * V_8 )
{
if ( ! F_22 ( V_8 ) )
return 0 ;
V_8 -> V_42 . V_43 -> V_47 = V_8 -> V_40 +
F_20 ( V_8 ) ;
F_24 () ;
return F_22 ( V_8 ) ;
}
static bool F_25 ( int V_48 , unsigned long V_49 , int V_5 )
{
if ( V_48 == V_50 )
return true ;
if ( ( V_48 + V_49 > V_50 ) &&
( V_49 <= V_50 ) && V_48 && ! V_5 )
return true ;
return false ;
}
unsigned int F_26 ( struct V_7 * V_8 , struct V_51 * V_52 )
{
unsigned int V_53 ;
int V_9 , V_54 ;
V_53 = F_21 ( F_27 ( V_52 ) , V_34 ) ;
V_54 = F_27 ( V_52 ) % V_34 ;
if ( F_28 ( V_52 ) -> V_55 )
V_53 ++ ;
for ( V_9 = 0 ; V_9 < F_28 ( V_52 ) -> V_56 ; V_9 ++ ) {
unsigned long V_49 = F_29 ( & F_28 ( V_52 ) -> V_57 [ V_9 ] ) ;
unsigned long V_48 = F_28 ( V_52 ) -> V_57 [ V_9 ] . V_26 ;
unsigned long V_58 ;
V_48 &= ~ V_59 ;
while ( V_49 > 0 ) {
F_30 ( V_48 >= V_34 ) ;
F_30 ( V_54 > V_50 ) ;
V_58 = V_34 - V_48 ;
if ( V_58 > V_49 )
V_58 = V_49 ;
if ( F_25 ( V_54 , V_58 , 0 ) ) {
V_53 ++ ;
V_54 = 0 ;
}
if ( V_54 + V_58 > V_50 )
V_58 = V_50 - V_54 ;
V_54 += V_58 ;
V_48 += V_58 ;
V_49 -= V_58 ;
if ( V_48 == V_34 )
V_48 = 0 ;
}
}
return V_53 ;
}
static struct V_60 * F_31 ( struct V_7 * V_8 ,
struct V_61 * V_62 )
{
struct V_60 * V_63 ;
struct V_64 * V_65 ;
V_65 = F_32 ( & V_8 -> V_42 , V_8 -> V_42 . V_66 ++ ) ;
V_63 = V_62 -> V_63 + V_62 -> V_67 ++ ;
V_63 -> V_55 = 0 ;
V_63 -> V_49 = 0 ;
V_63 -> V_68 = V_65 -> V_68 ;
V_62 -> V_54 = 0 ;
V_62 -> V_69 = V_65 -> V_70 ;
return V_63 ;
}
static void F_33 ( struct V_7 * V_8 , struct V_51 * V_52 ,
struct V_61 * V_62 ,
struct V_15 * V_15 , unsigned long V_49 ,
unsigned long V_48 , int * V_5 )
{
struct V_71 * V_72 ;
struct V_60 * V_63 ;
unsigned int V_73 ( V_17 ) , V_73 ( V_3 ) ;
int V_74 = F_13 ( V_15 , & V_17 , & V_3 ) ;
unsigned long V_58 ;
F_30 ( V_49 + V_48 > V_34 << F_34 ( V_15 ) ) ;
V_63 = V_62 -> V_63 + V_62 -> V_67 - 1 ;
V_15 += V_48 >> V_75 ;
V_48 &= ~ V_59 ;
while ( V_49 > 0 ) {
F_30 ( V_48 >= V_34 ) ;
F_30 ( V_62 -> V_54 > V_50 ) ;
V_58 = V_34 - V_48 ;
if ( V_58 > V_49 )
V_58 = V_49 ;
if ( F_25 ( V_62 -> V_54 , V_58 , * V_5 ) ) {
F_30 ( * V_5 ) ;
V_63 = F_31 ( V_8 , V_62 ) ;
}
if ( V_62 -> V_54 + V_58 > V_50 )
V_58 = V_50 - V_62 -> V_54 ;
V_72 = V_62 -> V_76 + V_62 -> V_77 ++ ;
V_72 -> V_78 = V_79 ;
if ( V_74 ) {
struct V_1 * V_2 = & V_1 [ V_17 ] ;
struct V_4 * V_80 ;
V_80 = & V_2 -> V_4 [ V_3 ] ;
V_72 -> V_81 . V_82 = V_80 -> V_8 -> V_82 ;
V_72 -> V_81 . V_83 . V_84 = V_80 -> V_65 . V_70 ;
V_72 -> V_78 |= V_85 ;
} else {
void * V_86 = F_35 ( V_15 ) ;
V_72 -> V_81 . V_82 = V_87 ;
V_72 -> V_81 . V_83 . V_88 = F_36 ( V_86 ) ;
}
V_72 -> V_81 . V_48 = V_48 ;
V_72 -> V_89 . V_82 = V_8 -> V_82 ;
V_72 -> V_89 . V_48 = V_62 -> V_54 ;
V_72 -> V_89 . V_83 . V_84 = V_62 -> V_69 ;
V_72 -> V_90 = V_58 ;
V_62 -> V_54 += V_58 ;
V_63 -> V_49 += V_58 ;
V_48 += V_58 ;
V_49 -= V_58 ;
if ( V_48 == V_34 && V_49 ) {
F_30 ( ! F_37 ( V_15 ) ) ;
V_15 ++ ;
V_48 = 0 ;
}
if ( * V_5 && F_28 ( V_52 ) -> V_55 && ! V_8 -> V_37 )
V_8 -> V_42 . V_66 ++ ;
* V_5 = 0 ;
}
}
static int F_38 ( struct V_51 * V_52 ,
struct V_61 * V_62 )
{
struct V_7 * V_8 = F_39 ( V_52 -> V_32 ) ;
int V_56 = F_28 ( V_52 ) -> V_56 ;
int V_9 ;
struct V_64 * V_65 ;
struct V_60 * V_63 ;
unsigned char * V_91 ;
int V_5 = 1 ;
int V_92 ;
V_92 = V_62 -> V_67 ;
if ( F_28 ( V_52 ) -> V_55 && V_8 -> V_37 ) {
V_65 = F_32 ( & V_8 -> V_42 , V_8 -> V_42 . V_66 ++ ) ;
V_63 = V_62 -> V_63 + V_62 -> V_67 ++ ;
V_63 -> V_55 = F_28 ( V_52 ) -> V_55 ;
V_63 -> V_49 = 0 ;
V_63 -> V_68 = V_65 -> V_68 ;
}
V_65 = F_32 ( & V_8 -> V_42 , V_8 -> V_42 . V_66 ++ ) ;
V_63 = V_62 -> V_63 + V_62 -> V_67 ++ ;
if ( ! V_8 -> V_37 )
V_63 -> V_55 = F_28 ( V_52 ) -> V_55 ;
else
V_63 -> V_55 = 0 ;
V_63 -> V_49 = 0 ;
V_63 -> V_68 = V_65 -> V_68 ;
V_62 -> V_54 = 0 ;
V_62 -> V_69 = V_65 -> V_70 ;
V_91 = V_52 -> V_91 ;
while ( V_91 < F_40 ( V_52 ) ) {
unsigned int V_48 = F_41 ( V_91 ) ;
unsigned int V_90 = V_34 - V_48 ;
if ( V_91 + V_90 > F_40 ( V_52 ) )
V_90 = F_40 ( V_52 ) - V_91 ;
F_33 ( V_8 , V_52 , V_62 ,
F_42 ( V_91 ) , V_90 , V_48 , & V_5 ) ;
V_91 += V_90 ;
}
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
F_33 ( V_8 , V_52 , V_62 ,
F_43 ( & F_28 ( V_52 ) -> V_57 [ V_9 ] ) ,
F_29 ( & F_28 ( V_52 ) -> V_57 [ V_9 ] ) ,
F_28 ( V_52 ) -> V_57 [ V_9 ] . V_26 ,
& V_5 ) ;
}
return V_62 -> V_67 - V_92 ;
}
static int F_44 ( struct V_7 * V_8 , int V_93 ,
struct V_61 * V_62 )
{
struct V_71 * V_94 ;
int V_95 = V_96 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_93 ; V_9 ++ ) {
V_94 = V_62 -> V_76 + V_62 -> V_97 ++ ;
if ( V_94 -> V_95 != V_98 ) {
F_45 ( V_8 -> V_32 ,
L_1 ,
V_94 -> V_95 , V_8 -> V_82 ) ;
V_95 = V_99 ;
}
}
return V_95 ;
}
static void F_46 ( struct V_7 * V_8 , int V_95 ,
struct V_60 * V_63 ,
int V_93 )
{
int V_9 ;
unsigned long V_48 ;
if ( V_93 <= 1 )
return;
V_93 -- ;
for ( V_9 = 0 ; V_9 < V_93 ; V_9 ++ ) {
int V_78 ;
if ( V_9 == V_93 - 1 )
V_78 = 0 ;
else
V_78 = V_100 ;
V_48 = 0 ;
F_47 ( V_8 , V_63 [ V_9 ] . V_68 , V_95 , V_48 ,
V_63 [ V_9 ] . V_49 , V_78 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = NULL , * V_101 ;
T_5 V_95 ;
T_2 V_78 ;
struct V_102 * V_103 ;
struct V_104 V_105 ;
struct V_51 * V_52 ;
F_49 ( V_106 ) ;
int V_107 ;
int V_56 ;
int V_53 ;
unsigned long V_48 ;
struct V_108 * V_109 ;
struct V_61 V_62 = {
. V_76 = V_2 -> V_110 ,
. V_63 = V_2 -> V_63 ,
} ;
F_50 ( & V_105 ) ;
V_53 = 0 ;
while ( ( V_52 = F_51 ( & V_2 -> V_111 ) ) != NULL ) {
V_8 = F_39 ( V_52 -> V_32 ) ;
V_56 = F_28 ( V_52 ) -> V_56 ;
V_109 = (struct V_108 * ) V_52 -> V_112 ;
V_109 -> V_113 = F_38 ( V_52 , & V_62 ) ;
V_53 += V_56 + 1 ;
F_52 ( & V_105 , V_52 ) ;
if ( V_53 + V_38 >= V_46 )
break;
}
F_30 ( V_62 . V_67 > F_53 ( V_2 -> V_63 ) ) ;
if ( ! V_62 . V_77 )
return;
F_30 ( V_62 . V_77 > F_53 ( V_2 -> V_110 ) ) ;
F_54 ( V_2 -> V_110 , V_62 . V_77 ) ;
while ( ( V_52 = F_55 ( & V_105 ) ) != NULL ) {
V_109 = (struct V_108 * ) V_52 -> V_112 ;
V_8 = F_39 ( V_52 -> V_32 ) ;
if ( V_2 -> V_63 [ V_62 . V_114 ] . V_55 && V_8 -> V_37 ) {
V_103 = F_56 ( & V_8 -> V_42 ,
V_8 -> V_42 . V_45 ++ ) ;
V_103 -> V_78 = V_115 | V_100 ;
V_103 -> V_48 = V_2 -> V_63 [ V_62 . V_114 ] . V_55 ;
V_103 -> V_68 = V_2 -> V_63 [ V_62 . V_114 ] . V_68 ;
V_103 -> V_95 = V_109 -> V_113 ;
V_62 . V_114 ++ ;
V_109 -> V_113 -- ;
}
V_8 -> V_32 -> V_116 . V_117 += V_52 -> V_90 ;
V_8 -> V_32 -> V_116 . V_118 ++ ;
V_95 = F_44 ( V_8 , V_109 -> V_113 , & V_62 ) ;
if ( V_109 -> V_113 == 1 )
V_78 = 0 ;
else
V_78 = V_100 ;
if ( V_52 -> V_119 == V_120 )
V_78 |= V_121 | V_122 ;
else if ( V_52 -> V_119 == V_123 )
V_78 |= V_122 ;
V_48 = 0 ;
V_103 = F_47 ( V_8 , V_2 -> V_63 [ V_62 . V_114 ] . V_68 ,
V_95 , V_48 ,
V_2 -> V_63 [ V_62 . V_114 ] . V_49 ,
V_78 ) ;
if ( V_2 -> V_63 [ V_62 . V_114 ] . V_55 && ! V_8 -> V_37 ) {
struct V_124 * V_36 =
(struct V_124 * )
F_56 ( & V_8 -> V_42 ,
V_8 -> V_42 . V_45 ++ ) ;
V_103 -> V_78 |= V_125 ;
V_36 -> V_83 . V_36 . V_49 = V_2 -> V_63 [ V_62 . V_114 ] . V_55 ;
V_36 -> V_83 . V_36 . type = V_126 ;
V_36 -> V_83 . V_36 . V_127 = 0 ;
V_36 -> V_83 . V_36 . V_128 = 0 ;
V_36 -> type = V_129 ;
V_36 -> V_78 = 0 ;
}
F_46 ( V_8 , V_95 ,
V_2 -> V_63 + V_62 . V_114 + 1 ,
V_109 -> V_113 ) ;
F_57 ( & V_8 -> V_42 , V_107 ) ;
F_58 ( V_8 ) ;
if ( V_107 && F_59 ( & V_8 -> V_130 ) )
F_60 ( & V_8 -> V_130 , & V_106 ) ;
else
F_61 ( V_8 ) ;
V_62 . V_114 += V_109 -> V_113 ;
F_62 ( V_52 ) ;
}
F_63 (vif, tmp, &notify, notify_list) {
F_64 ( V_8 -> V_131 ) ;
F_65 ( & V_8 -> V_130 ) ;
F_61 ( V_8 ) ;
}
if ( ! F_66 ( & V_2 -> V_111 ) &&
! F_67 ( & V_2 -> V_132 ) )
F_18 ( V_2 ) ;
}
void F_68 ( struct V_7 * V_8 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_69 ( & V_2 -> V_111 , V_52 ) ;
F_18 ( V_2 ) ;
}
static void F_70 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
F_18 ( V_2 ) ;
}
static int F_71 ( struct V_7 * V_8 )
{
return ! F_59 ( & V_8 -> V_133 ) ;
}
static void F_72 ( struct V_7 * V_8 )
{
if ( F_73 ( F_71 ( V_8 ) ) ) {
F_65 ( & V_8 -> V_133 ) ;
F_61 ( V_8 ) ;
}
}
static struct V_7 * F_74 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = NULL ;
F_75 ( & V_2 -> V_134 ) ;
if ( F_59 ( & V_2 -> V_135 ) )
goto V_136;
V_8 = F_76 ( & V_2 -> V_135 ,
struct V_7 , V_133 ) ;
if ( ! V_8 )
goto V_136;
F_77 ( V_8 ) ;
F_72 ( V_8 ) ;
V_136:
F_78 ( & V_2 -> V_134 ) ;
return V_8 ;
}
void F_79 ( struct V_7 * V_8 )
{
unsigned long V_78 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_71 ( V_8 ) )
goto V_137;
F_80 ( & V_2 -> V_134 , V_78 ) ;
if ( ! F_71 ( V_8 ) &&
F_73 ( F_81 ( V_8 ) ) ) {
F_60 ( & V_8 -> V_133 , & V_2 -> V_135 ) ;
F_77 ( V_8 ) ;
}
F_82 ( & V_2 -> V_134 , V_78 ) ;
V_137:
F_83 () ;
if ( ( F_17 ( V_2 ) < ( V_24 / 2 ) ) &&
! F_59 ( & V_2 -> V_135 ) )
F_18 ( V_2 ) ;
}
void F_84 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_75 ( & V_2 -> V_134 ) ;
F_72 ( V_8 ) ;
F_78 ( & V_2 -> V_134 ) ;
}
void F_85 ( struct V_7 * V_8 )
{
int V_138 ;
F_86 ( & V_8 -> V_139 , V_138 ) ;
if ( V_138 )
F_79 ( V_8 ) ;
}
static void F_87 ( struct V_7 * V_8 )
{
unsigned long V_140 , V_141 ;
V_140 = F_32 ( & V_8 -> V_139 , V_8 -> V_139 . V_66 ) -> V_49 ;
V_140 = F_88 ( V_140 , 131072UL ) ;
V_140 = V_31 ( V_140 , V_8 -> V_142 ) ;
V_141 = V_8 -> V_143 + V_8 -> V_142 ;
if ( V_141 < V_8 -> V_143 )
V_141 = V_144 ;
V_8 -> V_143 = F_88 ( V_141 , V_140 ) ;
}
static void F_89 ( unsigned long V_91 )
{
struct V_7 * V_8 = (struct V_7 * ) V_91 ;
F_87 ( V_8 ) ;
F_85 ( V_8 ) ;
}
static void F_90 ( struct V_7 * V_8 ,
struct V_145 * V_146 , T_1 V_147 )
{
T_1 V_148 = V_8 -> V_139 . V_66 ;
do {
F_91 ( V_8 , V_146 , V_99 ) ;
if ( V_148 == V_147 )
break;
V_146 = F_32 ( & V_8 -> V_139 , V_148 ++ ) ;
} while ( 1 );
V_8 -> V_139 . V_66 = V_148 ;
F_85 ( V_8 ) ;
F_61 ( V_8 ) ;
}
static void F_92 ( struct V_7 * V_8 )
{
F_93 ( V_8 -> V_32 , L_2 ) ;
F_94 ( V_8 ) ;
F_61 ( V_8 ) ;
}
static int F_95 ( struct V_7 * V_8 ,
struct V_145 * V_149 ,
struct V_145 * V_146 ,
int V_150 )
{
T_1 V_148 = V_8 -> V_139 . V_66 ;
int V_151 = 0 ;
int V_152 = 0 ;
int V_153 ;
if ( ! ( V_149 -> V_78 & V_154 ) )
return 0 ;
do {
struct V_145 V_155 = { 0 } ;
if ( V_151 >= V_150 ) {
F_93 ( V_8 -> V_32 ,
L_3 ,
V_150 ) ;
F_92 ( V_8 ) ;
return - V_156 ;
}
if ( F_96 ( V_151 >= V_157 ) ) {
F_93 ( V_8 -> V_32 ,
L_4 ,
V_151 , V_157 ) ;
F_92 ( V_8 ) ;
return - V_158 ;
}
if ( ! V_152 && V_151 >= V_159 ) {
if ( F_97 () )
F_45 ( V_8 -> V_32 ,
L_5 ,
V_151 , V_159 ) ;
V_152 = - V_158 ;
}
if ( V_152 )
V_146 = & V_155 ;
memcpy ( V_146 , F_32 ( & V_8 -> V_139 , V_148 + V_151 ) ,
sizeof( * V_146 ) ) ;
if ( ! V_152 && V_146 -> V_49 > V_149 -> V_49 ) {
if ( F_97 () )
F_45 ( V_8 -> V_32 ,
L_6 ,
V_146 -> V_49 , V_149 -> V_49 ) ;
V_152 = - V_160 ;
}
V_149 -> V_49 -= V_146 -> V_49 ;
V_151 ++ ;
if ( F_96 ( ( V_146 -> V_48 + V_146 -> V_49 ) > V_34 ) ) {
F_93 ( V_8 -> V_32 , L_7 ,
V_146 -> V_48 , V_146 -> V_49 ) ;
F_92 ( V_8 ) ;
return - V_161 ;
}
V_153 = V_146 -> V_78 & V_154 ;
if ( ! V_152 )
V_146 ++ ;
} while ( V_153 );
if ( V_152 ) {
F_90 ( V_8 , V_149 , V_148 + V_151 ) ;
return V_152 ;
}
return V_151 ;
}
static struct V_15 * F_98 ( struct V_1 * V_2 ,
T_2 V_27 )
{
struct V_15 * V_15 ;
V_15 = F_99 ( V_162 | V_163 ) ;
if ( ! V_15 )
return NULL ;
F_11 ( V_15 , V_2 , V_27 ) ;
V_2 -> V_14 [ V_27 ] = V_15 ;
return V_15 ;
}
static struct V_71 * F_100 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_51 * V_52 ,
struct V_145 * V_146 ,
struct V_71 * V_164 )
{
struct V_165 * V_166 = F_28 ( V_52 ) ;
T_3 * V_57 = V_166 -> V_57 ;
T_2 V_27 = * ( ( T_2 * ) V_52 -> V_91 ) ;
T_2 V_167 = 0 ;
int V_168 , V_169 ;
struct V_15 * V_15 ;
T_4 V_170 , V_171 = 0 ;
T_6 V_172 ;
unsigned int V_173 ;
struct V_4 * V_149 = NULL ;
V_173 = V_166 -> V_56 ;
V_169 = ( F_14 ( & V_166 -> V_57 [ 0 ] ) == V_27 ) ;
for ( V_166 -> V_56 = V_168 = V_169 ; V_168 < V_173 ;
V_166 -> V_56 ++ ) {
struct V_4 * V_4 =
V_2 -> V_4 ;
V_15 = F_99 ( V_162 | V_163 ) ;
if ( ! V_15 )
goto V_174;
V_172 = 0 ;
V_149 = NULL ;
while ( V_172 < V_34 && V_168 < V_173 ) {
V_164 -> V_78 = V_85 ;
V_164 -> V_81 . V_83 . V_84 = V_146 -> V_70 ;
V_164 -> V_81 . V_82 = V_8 -> V_82 ;
V_164 -> V_81 . V_48 = V_146 -> V_48 ;
V_164 -> V_89 . V_82 = V_87 ;
V_164 -> V_89 . V_48 = V_172 ;
V_164 -> V_89 . V_83 . V_88 = F_36 ( F_35 ( V_15 ) ) ;
if ( V_172 + V_146 -> V_49 > V_34 ) {
V_164 -> V_90 = V_34 - V_172 ;
V_146 -> V_48 += V_164 -> V_90 ;
V_146 -> V_49 -= V_164 -> V_90 ;
V_172 += V_164 -> V_90 ;
} else {
V_164 -> V_90 = V_146 -> V_49 ;
V_172 += V_164 -> V_90 ;
V_170 = F_16 ( V_2 -> V_29 ++ ) ;
V_27 = V_2 -> V_175 [ V_170 ] ;
memcpy ( & V_4 [ V_27 ] . V_65 , V_146 ,
sizeof( * V_146 ) ) ;
F_77 ( V_8 ) ;
V_4 [ V_27 ] . V_8 = V_8 ;
V_2 -> V_14 [ V_27 ] = ( void * ) ( ~ 0UL ) ;
V_4 [ V_27 ] . V_5 =
V_6 ;
if ( ! V_149 ) {
V_149 = & V_4 [ V_27 ] ;
V_171 = V_170 ;
V_167 = V_27 ;
}
V_146 ++ ;
V_168 ++ ;
}
V_164 ++ ;
}
V_149 -> V_65 . V_48 = 0 ;
V_149 -> V_65 . V_49 = V_172 ;
V_149 -> V_5 = V_171 ;
F_11 ( V_15 , V_2 , V_167 ) ;
V_2 -> V_14 [ V_167 ] = V_15 ;
F_15 ( & V_57 [ V_166 -> V_56 ] , V_167 ) ;
}
F_30 ( V_166 -> V_56 > V_38 ) ;
return V_164 ;
V_174:
while ( V_166 -> V_56 -- > V_169 ) {
F_101 ( V_2 ,
F_14 ( & V_57 [ V_166 -> V_56 ] ) ,
V_99 ) ;
}
if ( V_169 )
F_101 ( V_2 , V_27 , V_99 ) ;
return NULL ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_71 * * V_176 )
{
struct V_71 * V_164 = * V_176 ;
T_2 V_27 = * ( ( T_2 * ) V_52 -> V_91 ) ;
struct V_165 * V_166 = F_28 ( V_52 ) ;
struct V_4 * V_177 ;
int V_56 = V_166 -> V_56 ;
int V_9 , V_174 , V_169 ;
T_2 V_39 ;
V_174 = V_164 -> V_95 ;
if ( F_96 ( V_174 ) )
F_101 ( V_2 , V_27 , V_99 ) ;
V_169 = ( F_14 ( & V_166 -> V_57 [ 0 ] ) == V_27 ) ;
for ( V_9 = V_169 ; V_9 < V_56 ; V_9 ++ ) {
int V_178 , V_179 ;
T_4 V_5 ;
V_27 = F_14 ( & V_166 -> V_57 [ V_9 ] ) ;
V_177 = & V_2 -> V_4 [ V_27 ] ;
V_5 = V_177 -> V_5 ;
do {
V_179 = ( ++ V_164 ) -> V_95 ;
if ( V_179 )
break;
V_39 = V_2 -> V_175 [ F_16 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_39 ) );
if ( F_73 ( ! V_179 ) ) {
if ( F_96 ( V_174 ) )
F_101 ( V_2 , V_27 , V_96 ) ;
continue;
}
F_101 ( V_2 , V_27 , V_99 ) ;
if ( V_174 )
continue;
V_27 = * ( ( T_2 * ) V_52 -> V_91 ) ;
F_101 ( V_2 , V_27 , V_96 ) ;
for ( V_178 = V_169 ; V_178 < V_9 ; V_178 ++ ) {
V_27 = F_14 ( & V_166 -> V_57 [ V_178 ] ) ;
F_101 ( V_2 , V_27 , V_96 ) ;
}
V_174 = V_179 ;
}
* V_176 = V_164 + 1 ;
return V_174 ;
}
static void F_103 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_165 * V_166 = F_28 ( V_52 ) ;
int V_56 = V_166 -> V_56 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
T_3 * V_25 = V_166 -> V_57 + V_9 ;
struct V_145 * V_146 ;
struct V_15 * V_15 ;
T_2 V_27 ;
V_27 = F_14 ( V_25 ) ;
V_146 = & V_2 -> V_4 [ V_27 ] . V_65 ;
V_15 = F_42 ( F_9 ( V_2 , V_27 ) ) ;
F_104 ( V_52 , V_9 , V_15 , V_146 -> V_48 , V_146 -> V_49 ) ;
V_52 -> V_90 += V_146 -> V_49 ;
V_52 -> V_180 += V_146 -> V_49 ;
V_52 -> V_181 += V_146 -> V_49 ;
F_105 ( V_2 -> V_14 [ V_27 ] ) ;
F_101 ( V_2 , V_27 , V_96 ) ;
}
}
static int F_106 ( struct V_7 * V_8 ,
struct V_124 * V_182 ,
int V_150 )
{
struct V_124 V_183 ;
T_1 V_148 = V_8 -> V_139 . V_66 ;
do {
if ( F_96 ( V_150 -- <= 0 ) ) {
F_93 ( V_8 -> V_32 , L_8 ) ;
F_92 ( V_8 ) ;
return - V_184 ;
}
memcpy ( & V_183 , F_32 ( & V_8 -> V_139 , V_148 ) ,
sizeof( V_183 ) ) ;
if ( F_96 ( ! V_183 . type ||
V_183 . type >= V_185 ) ) {
V_8 -> V_139 . V_66 = ++ V_148 ;
F_93 ( V_8 -> V_32 ,
L_9 , V_183 . type ) ;
F_92 ( V_8 ) ;
return - V_161 ;
}
memcpy ( & V_182 [ V_183 . type - 1 ] , & V_183 , sizeof( V_183 ) ) ;
V_8 -> V_139 . V_66 = ++ V_148 ;
} while ( V_183 . V_78 & V_186 );
return V_150 ;
}
static int F_107 ( struct V_7 * V_8 ,
struct V_51 * V_52 ,
struct V_124 * V_36 )
{
if ( ! V_36 -> V_83 . V_36 . V_49 ) {
F_93 ( V_8 -> V_32 , L_10 ) ;
F_92 ( V_8 ) ;
return - V_161 ;
}
if ( V_36 -> V_83 . V_36 . type != V_126 ) {
F_93 ( V_8 -> V_32 , L_11 , V_36 -> V_83 . V_36 . type ) ;
F_92 ( V_8 ) ;
return - V_161 ;
}
F_28 ( V_52 ) -> V_55 = V_36 -> V_83 . V_36 . V_49 ;
F_28 ( V_52 ) -> V_187 = V_188 ;
F_28 ( V_52 ) -> V_187 |= V_189 ;
F_28 ( V_52 ) -> V_190 = 0 ;
return 0 ;
}
static int F_108 ( struct V_7 * V_8 , struct V_51 * V_52 )
{
struct V_191 * V_192 ;
int V_174 = - V_193 ;
int V_194 = 0 ;
if ( V_52 -> V_119 != V_120 && F_109 ( V_52 ) ) {
V_8 -> V_195 ++ ;
V_52 -> V_119 = V_120 ;
V_194 = 1 ;
}
if ( V_52 -> V_119 != V_120 )
return 0 ;
if ( V_52 -> V_196 != F_110 ( V_197 ) )
goto V_136;
V_192 = ( void * ) V_52 -> V_91 ;
switch ( V_192 -> V_196 ) {
case V_198 :
if ( ! F_111 ( V_52 , 4 * V_192 -> V_199 ,
F_112 ( struct V_200 , V_201 ) ) )
goto V_136;
if ( V_194 ) {
struct V_200 * V_202 = F_113 ( V_52 ) ;
V_202 -> V_201 = ~ F_114 ( V_192 -> V_203 , V_192 -> V_204 ,
V_52 -> V_90 - V_192 -> V_199 * 4 ,
V_198 , 0 ) ;
}
break;
case V_205 :
if ( ! F_111 ( V_52 , 4 * V_192 -> V_199 ,
F_112 ( struct V_206 , V_201 ) ) )
goto V_136;
if ( V_194 ) {
struct V_206 * V_207 = F_115 ( V_52 ) ;
V_207 -> V_201 = ~ F_114 ( V_192 -> V_203 , V_192 -> V_204 ,
V_52 -> V_90 - V_192 -> V_199 * 4 ,
V_205 , 0 ) ;
}
break;
default:
if ( F_97 () )
F_93 ( V_8 -> V_32 ,
L_12 ,
V_192 -> V_196 ) ;
goto V_136;
}
V_174 = 0 ;
V_136:
return V_174 ;
}
static bool F_116 ( struct V_7 * V_8 , unsigned V_49 )
{
unsigned long V_208 = V_209 ;
unsigned long V_210 =
V_8 -> V_211 . V_212 +
F_117 ( V_8 -> V_213 / 1000 ) ;
if ( F_67 ( & V_8 -> V_211 ) )
return true ;
if ( F_118 ( V_208 , V_210 ) ) {
V_8 -> V_211 . V_212 = V_208 ;
F_87 ( V_8 ) ;
}
if ( V_49 > V_8 -> V_143 ) {
V_8 -> V_211 . V_91 =
( unsigned long ) V_8 ;
V_8 -> V_211 . V_214 =
F_89 ;
F_119 ( & V_8 -> V_211 ,
V_210 ) ;
return true ;
}
return false ;
}
static unsigned F_120 ( struct V_1 * V_2 )
{
struct V_71 * V_164 = V_2 -> V_215 , * V_216 ;
struct V_51 * V_52 ;
int V_107 ;
while ( ( F_17 ( V_2 ) + V_159
< V_24 ) &&
! F_59 ( & V_2 -> V_135 ) ) {
struct V_7 * V_8 ;
struct V_145 V_217 ;
struct V_145 V_218 [ V_159 ] ;
struct V_15 * V_15 ;
struct V_124 V_182 [ V_185 - 1 ] ;
T_2 V_27 ;
T_1 V_3 ;
int V_150 ;
unsigned int V_180 ;
T_4 V_170 ;
V_8 = F_74 ( V_2 ) ;
if ( ! V_8 )
continue;
if ( V_8 -> V_139 . V_43 -> V_44 - V_8 -> V_139 . V_66 >
V_219 ) {
F_93 ( V_8 -> V_32 ,
L_13
L_14 ,
V_8 -> V_139 . V_43 -> V_44 , V_8 -> V_139 . V_66 ,
V_219 ) ;
F_92 ( V_8 ) ;
continue;
}
F_86 ( & V_8 -> V_139 , V_150 ) ;
if ( ! V_150 ) {
F_61 ( V_8 ) ;
continue;
}
V_3 = V_8 -> V_139 . V_66 ;
F_121 () ;
memcpy ( & V_217 , F_32 ( & V_8 -> V_139 , V_3 ) , sizeof( V_217 ) ) ;
if ( V_217 . V_49 > V_8 -> V_143 &&
F_116 ( V_8 , V_217 . V_49 ) ) {
F_61 ( V_8 ) ;
continue;
}
V_8 -> V_143 -= V_217 . V_49 ;
V_150 -- ;
V_8 -> V_139 . V_66 = ++ V_3 ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
if ( V_217 . V_78 & V_220 ) {
V_150 = F_106 ( V_8 , V_182 ,
V_150 ) ;
V_3 = V_8 -> V_139 . V_66 ;
if ( F_96 ( V_150 < 0 ) )
continue;
}
V_107 = F_95 ( V_8 , & V_217 , V_218 , V_150 ) ;
if ( F_96 ( V_107 < 0 ) )
continue;
V_3 += V_107 ;
if ( F_96 ( V_217 . V_49 < V_221 ) ) {
F_45 ( V_8 -> V_32 ,
L_15 , V_217 . V_49 ) ;
F_90 ( V_8 , & V_217 , V_3 ) ;
continue;
}
if ( F_96 ( ( V_217 . V_48 + V_217 . V_49 ) > V_34 ) ) {
F_93 ( V_8 -> V_32 ,
L_16 ,
V_217 . V_48 , V_217 . V_49 ,
( V_217 . V_48 & ~ V_59 ) + V_217 . V_49 ) ;
F_92 ( V_8 ) ;
continue;
}
V_170 = F_16 ( V_2 -> V_29 ) ;
V_27 = V_2 -> V_175 [ V_170 ] ;
V_180 = ( V_217 . V_49 > V_222 &&
V_107 < V_159 ) ?
V_222 : V_217 . V_49 ;
V_52 = F_122 ( V_180 + V_223 + V_224 ,
V_225 | V_226 ) ;
if ( F_96 ( V_52 == NULL ) ) {
F_45 ( V_8 -> V_32 ,
L_17 ) ;
F_90 ( V_8 , & V_217 , V_3 ) ;
break;
}
F_123 ( V_52 , V_223 + V_224 ) ;
if ( V_182 [ V_129 - 1 ] . type ) {
struct V_124 * V_36 ;
V_36 = & V_182 [ V_129 - 1 ] ;
if ( F_107 ( V_8 , V_52 , V_36 ) ) {
F_124 ( V_52 ) ;
continue;
}
}
V_15 = F_98 ( V_2 , V_27 ) ;
if ( ! V_15 ) {
F_124 ( V_52 ) ;
F_90 ( V_8 , & V_217 , V_3 ) ;
continue;
}
V_164 -> V_81 . V_83 . V_84 = V_217 . V_70 ;
V_164 -> V_81 . V_82 = V_8 -> V_82 ;
V_164 -> V_81 . V_48 = V_217 . V_48 ;
V_164 -> V_89 . V_83 . V_88 = F_36 ( F_35 ( V_15 ) ) ;
V_164 -> V_89 . V_82 = V_87 ;
V_164 -> V_89 . V_48 = V_217 . V_48 ;
V_164 -> V_90 = V_217 . V_49 ;
V_164 -> V_78 = V_85 ;
V_164 ++ ;
memcpy ( & V_2 -> V_4 [ V_27 ] . V_65 ,
& V_217 , sizeof( V_217 ) ) ;
V_2 -> V_4 [ V_27 ] . V_8 = V_8 ;
V_2 -> V_4 [ V_27 ] . V_5 = V_170 ;
* ( ( T_2 * ) V_52 -> V_91 ) = V_27 ;
F_125 ( V_52 , V_180 ) ;
F_28 ( V_52 ) -> V_56 = V_107 ;
if ( V_180 < V_217 . V_49 ) {
F_28 ( V_52 ) -> V_56 ++ ;
F_15 ( & F_28 ( V_52 ) -> V_57 [ 0 ] ,
V_27 ) ;
} else {
F_15 ( & F_28 ( V_52 ) -> V_57 [ 0 ] ,
V_227 ) ;
}
V_2 -> V_29 ++ ;
V_216 = F_100 ( V_2 , V_8 ,
V_52 , V_218 , V_164 ) ;
if ( V_216 == NULL ) {
F_124 ( V_52 ) ;
F_90 ( V_8 , & V_217 , V_3 ) ;
continue;
}
V_164 = V_216 ;
F_52 ( & V_2 -> V_228 , V_52 ) ;
V_8 -> V_139 . V_66 = V_3 ;
F_85 ( V_8 ) ;
if ( ( V_164 - V_2 -> V_215 ) >= F_53 ( V_2 -> V_215 ) )
break;
}
return V_164 - V_2 -> V_215 ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_71 * V_164 = V_2 -> V_215 ;
struct V_51 * V_52 ;
while ( ( V_52 = F_55 ( & V_2 -> V_228 ) ) != NULL ) {
struct V_145 * V_146 ;
struct V_7 * V_8 ;
T_2 V_27 ;
unsigned V_180 ;
V_27 = * ( ( T_2 * ) V_52 -> V_91 ) ;
V_8 = V_2 -> V_4 [ V_27 ] . V_8 ;
V_146 = & V_2 -> V_4 [ V_27 ] . V_65 ;
if ( F_96 ( F_102 ( V_2 , V_52 , & V_164 ) ) ) {
F_45 ( V_8 -> V_32 , L_18 ) ;
F_28 ( V_52 ) -> V_56 = 0 ;
F_124 ( V_52 ) ;
continue;
}
V_180 = V_52 -> V_90 ;
memcpy ( V_52 -> V_91 ,
( void * ) ( F_9 ( V_2 , V_27 ) | V_146 -> V_48 ) ,
V_180 ) ;
if ( V_180 < V_146 -> V_49 ) {
V_146 -> V_48 += V_180 ;
V_146 -> V_49 -= V_180 ;
} else {
F_101 ( V_2 , V_27 , V_96 ) ;
}
if ( V_146 -> V_78 & V_229 )
V_52 -> V_119 = V_120 ;
else if ( V_146 -> V_78 & V_230 )
V_52 -> V_119 = V_123 ;
F_103 ( V_2 , V_52 ) ;
if ( F_27 ( V_52 ) < V_222 && F_127 ( V_52 ) ) {
int V_231 = F_128 ( int , V_52 -> V_90 , V_222 ) ;
F_129 ( V_52 , V_231 - F_27 ( V_52 ) ) ;
}
V_52 -> V_32 = V_8 -> V_32 ;
V_52 -> V_196 = F_130 ( V_52 , V_52 -> V_32 ) ;
F_131 ( V_52 ) ;
if ( F_108 ( V_8 , V_52 ) ) {
F_45 ( V_8 -> V_32 ,
L_19 ) ;
F_124 ( V_52 ) ;
continue;
}
F_132 ( V_52 , 0 ) ;
V_8 -> V_32 -> V_116 . V_232 += V_52 -> V_90 ;
V_8 -> V_32 -> V_116 . V_233 ++ ;
F_133 ( V_8 , V_52 ) ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
unsigned V_234 ;
V_234 = F_120 ( V_2 ) ;
if ( V_234 == 0 )
return;
F_54 ( V_2 -> V_215 , V_234 ) ;
F_126 ( V_2 ) ;
}
static void F_101 ( struct V_1 * V_2 , T_2 V_27 ,
T_7 V_95 )
{
struct V_7 * V_8 ;
struct V_4 * V_4 ;
T_4 V_5 ;
T_2 V_39 ;
F_30 ( V_2 -> V_14 [ V_27 ] == ( void * ) ( ~ 0UL ) ) ;
if ( V_2 -> V_14 [ V_27 ] == NULL )
return;
V_4 = & V_2 -> V_4 [ V_27 ] ;
V_8 = V_4 -> V_8 ;
V_5 = V_4 -> V_5 ;
F_30 ( ! F_1 ( V_2 , V_5 ) ) ;
F_30 ( V_2 -> V_175 [ F_16 ( V_5 ) ] != V_27 ) ;
do {
T_4 V_170 ;
T_4 V_3 = F_16 ( V_5 ) ;
T_2 V_235 = V_2 -> V_175 [ V_3 ] ;
V_4 = & V_2 -> V_4 [ V_235 ] ;
F_91 ( V_8 , & V_4 -> V_65 , V_95 ) ;
V_4 -> V_5 = 0 ;
V_170 = F_16 ( V_2 -> V_28 ++ ) ;
V_2 -> V_175 [ V_170 ] = V_2 -> V_175 [ V_235 ] ;
F_61 ( V_8 ) ;
V_39 = V_2 -> V_175 [ F_16 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_39 ) );
V_2 -> V_14 [ V_27 ] -> V_21 = 0 ;
F_135 ( V_2 -> V_14 [ V_27 ] ) ;
V_2 -> V_14 [ V_27 ] = NULL ;
}
static void F_91 ( struct V_7 * V_8 ,
struct V_145 * V_146 ,
T_5 V_236 )
{
T_1 V_9 = V_8 -> V_139 . V_45 ;
struct V_237 * V_103 ;
int V_106 ;
V_103 = F_56 ( & V_8 -> V_139 , V_9 ) ;
V_103 -> V_68 = V_146 -> V_68 ;
V_103 -> V_95 = V_236 ;
if ( V_146 -> V_78 & V_220 )
F_56 ( & V_8 -> V_139 , ++ V_9 ) -> V_95 = V_238 ;
V_8 -> V_139 . V_45 = ++ V_9 ;
F_57 ( & V_8 -> V_139 , V_106 ) ;
if ( V_106 )
F_64 ( V_8 -> V_239 ) ;
}
static struct V_102 * F_47 ( struct V_7 * V_8 ,
T_2 V_68 ,
T_5 V_236 ,
T_2 V_48 ,
T_2 V_49 ,
T_2 V_78 )
{
T_1 V_9 = V_8 -> V_42 . V_45 ;
struct V_102 * V_103 ;
V_103 = F_56 ( & V_8 -> V_42 , V_9 ) ;
V_103 -> V_48 = V_48 ;
V_103 -> V_78 = V_78 ;
V_103 -> V_68 = V_68 ;
V_103 -> V_95 = ( V_240 ) V_49 ;
if ( V_236 < 0 )
V_103 -> V_95 = ( V_240 ) V_236 ;
V_8 -> V_42 . V_45 = ++ V_9 ;
return V_103 ;
}
static inline int F_136 ( struct V_1 * V_2 )
{
return ! F_66 ( & V_2 -> V_111 ) ;
}
static inline int F_137 ( struct V_1 * V_2 )
{
if ( ( F_17 ( V_2 ) + V_159
< V_24 ) &&
! F_59 ( & V_2 -> V_135 ) )
return 1 ;
return 0 ;
}
static int F_138 ( void * V_91 )
{
struct V_1 * V_2 = V_91 ;
while ( ! F_139 () ) {
F_140 ( V_2 -> V_30 ,
F_136 ( V_2 ) ||
F_137 ( V_2 ) ||
F_139 () ) ;
F_141 () ;
if ( F_139 () )
break;
if ( F_136 ( V_2 ) )
F_48 ( V_2 ) ;
if ( F_137 ( V_2 ) )
F_134 ( V_2 ) ;
}
return 0 ;
}
void F_142 ( struct V_7 * V_8 )
{
if ( V_8 -> V_139 . V_43 )
F_143 ( F_144 ( V_8 ) ,
V_8 -> V_139 . V_43 ) ;
if ( V_8 -> V_42 . V_43 )
F_143 ( F_144 ( V_8 ) ,
V_8 -> V_42 . V_43 ) ;
}
int F_145 ( struct V_7 * V_8 ,
T_8 V_241 ,
T_8 V_242 )
{
void * V_243 ;
struct V_244 * V_245 ;
struct V_246 * V_247 ;
int V_174 = - V_248 ;
V_174 = F_146 ( F_144 ( V_8 ) ,
V_241 , & V_243 ) ;
if ( V_174 )
goto V_174;
V_245 = (struct V_244 * ) V_243 ;
F_147 ( & V_8 -> V_139 , V_245 , V_34 ) ;
V_174 = F_146 ( F_144 ( V_8 ) ,
V_242 , & V_243 ) ;
if ( V_174 )
goto V_174;
V_247 = (struct V_246 * ) V_243 ;
F_147 ( & V_8 -> V_42 , V_247 , V_34 ) ;
V_8 -> V_40 = 0 ;
return 0 ;
V_174:
F_142 ( V_8 ) ;
return V_174 ;
}
static int T_9 F_148 ( void )
{
int V_9 ;
int V_249 = 0 ;
int V_17 ;
if ( ! F_149 () )
return - V_250 ;
if ( V_157 < V_159 ) {
F_150 ( L_20 ,
V_157 , V_159 ) ;
V_157 = V_159 ;
}
V_13 = F_151 () ;
V_1 = F_152 ( sizeof( struct V_1 ) * V_13 ) ;
if ( ! V_1 )
return - V_248 ;
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
struct V_1 * V_2 = & V_1 [ V_17 ] ;
F_50 ( & V_2 -> V_111 ) ;
F_50 ( & V_2 -> V_228 ) ;
F_153 ( & V_2 -> V_132 ) ;
V_2 -> V_132 . V_91 = ( unsigned long ) V_2 ;
V_2 -> V_132 . V_214 = F_70 ;
V_2 -> V_29 = 0 ;
V_2 -> V_28 = V_24 ;
for ( V_9 = 0 ; V_9 < V_24 ; V_9 ++ )
V_2 -> V_175 [ V_9 ] = V_9 ;
F_154 ( & V_2 -> V_30 ) ;
V_2 -> V_251 = F_155 ( F_138 ,
( void * ) V_2 ,
L_21 , V_17 ) ;
if ( F_156 ( V_2 -> V_251 ) ) {
F_157 ( L_22 ) ;
F_158 ( & V_2 -> V_132 ) ;
V_249 = F_159 ( V_2 -> V_251 ) ;
goto V_252;
}
F_160 ( V_2 -> V_251 , V_17 ) ;
F_161 ( & V_2 -> V_135 ) ;
F_162 ( & V_2 -> V_134 ) ;
F_163 ( & V_2 -> V_12 , 0 ) ;
F_164 ( V_2 -> V_251 ) ;
}
V_249 = F_165 () ;
if ( V_249 )
goto V_252;
return 0 ;
V_252:
while ( -- V_17 >= 0 ) {
struct V_1 * V_2 = & V_1 [ V_17 ] ;
F_158 ( & V_2 -> V_132 ) ;
F_166 ( V_2 -> V_251 ) ;
}
F_167 ( V_1 ) ;
return V_249 ;
}
static void T_10 F_168 ( void )
{
int V_9 , V_178 ;
F_169 () ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
struct V_1 * V_2 = & V_1 [ V_9 ] ;
F_170 ( & V_2 -> V_132 ) ;
F_166 ( V_2 -> V_251 ) ;
for ( V_178 = 0 ; V_178 < V_24 ; V_178 ++ ) {
if ( V_2 -> V_14 [ V_178 ] )
F_171 ( V_2 -> V_14 [ V_178 ] ) ;
}
}
F_167 ( V_1 ) ;
}
