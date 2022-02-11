void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
int V_5 = 0 ;
struct V_6 * V_7 ;
V_4 = F_2 ( & V_6 [ 0 ] . V_8 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
int V_8 = F_2 ( & V_6 [ V_3 ] . V_8 ) ;
if ( V_8 < V_4 ) {
V_5 = V_3 ;
V_4 = V_8 ;
}
}
V_7 = & V_6 [ V_5 ] ;
V_2 -> V_7 = V_7 ;
F_3 ( & V_7 -> V_8 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_2 -> V_7 = NULL ;
F_5 ( & V_7 -> V_8 ) ;
}
static inline unsigned long F_6 ( struct V_6 * V_7 ,
T_1 V_10 )
{
return F_7 ( V_7 -> V_11 [ V_10 ] ) ;
}
static inline unsigned long F_8 ( struct V_6 * V_7 ,
T_1 V_10 )
{
return ( unsigned long ) F_9 ( F_6 ( V_7 , V_10 ) ) ;
}
static inline void F_10 ( struct V_12 * V_13 , struct V_6 * V_7 ,
unsigned int V_10 )
{
unsigned int V_14 = V_7 - V_6 ;
union V_15 V_16 = { . V_17 = { . V_14 = V_14 + 1 , . V_10 = V_10 } } ;
F_11 ( sizeof( V_16 ) > sizeof( V_16 . V_18 ) ) ;
V_13 -> V_18 = V_16 . V_18 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned int * V_19 , unsigned int * V_20 )
{
union V_15 V_16 = { . V_18 = V_13 -> V_18 } ;
struct V_6 * V_7 ;
unsigned int V_14 , V_10 ;
V_14 = V_16 . V_17 . V_14 - 1 ;
if ( V_14 < 0 || V_14 >= V_9 )
return 0 ;
V_7 = & V_6 [ V_14 ] ;
V_10 = V_16 . V_17 . V_10 ;
if ( ( V_10 < 0 ) || ( V_10 >= V_21 ) )
return 0 ;
if ( V_7 -> V_11 [ V_10 ] != V_13 )
return 0 ;
* V_19 = V_14 ;
* V_20 = V_10 ;
return 1 ;
}
static T_1 F_13 ( T_2 * V_22 )
{
return ( T_1 ) V_22 -> V_23 ;
}
static void F_14 ( T_2 * V_22 , T_1 V_24 )
{
V_22 -> V_23 = V_24 ;
}
static inline T_3 F_15 ( unsigned V_3 )
{
return V_3 & ( V_21 - 1 ) ;
}
static inline T_3 F_16 ( struct V_6 * V_7 )
{
return V_21 -
V_7 -> V_25 + V_7 -> V_26 ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_18 ( & V_7 -> V_27 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_28 = F_20 ( V_2 -> V_29 -> V_30 , V_31 ) ;
if ( V_2 -> V_32 || V_2 -> V_33 || V_2 -> V_34 )
V_28 += V_35 + 1 ;
return V_28 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_4 V_36 = V_2 -> V_37 ;
T_4 V_38 = F_19 ( V_2 ) ;
return ( ( V_2 -> V_39 . V_40 -> V_41 - V_36 ) < V_38 ) ||
( ( V_2 -> V_39 . V_42 + V_43 - V_36 ) < V_38 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
if ( ! F_21 ( V_2 ) )
return 0 ;
V_2 -> V_39 . V_40 -> V_44 = V_2 -> V_37 +
F_19 ( V_2 ) ;
F_23 () ;
return F_21 ( V_2 ) ;
}
static bool F_24 ( int V_45 , unsigned long V_46 , int V_47 )
{
if ( V_45 == V_48 )
return true ;
if ( ( V_45 + V_46 > V_48 ) &&
( V_46 <= V_48 ) && V_45 && ! V_47 )
return true ;
return false ;
}
unsigned int F_25 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
unsigned int V_51 ;
int V_3 , V_52 ;
V_51 = F_20 ( F_26 ( V_50 ) , V_31 ) ;
V_52 = F_26 ( V_50 ) % V_31 ;
if ( F_27 ( V_50 ) -> V_53 )
V_51 ++ ;
for ( V_3 = 0 ; V_3 < F_27 ( V_50 ) -> V_54 ; V_3 ++ ) {
unsigned long V_46 = F_28 ( & F_27 ( V_50 ) -> V_55 [ V_3 ] ) ;
unsigned long V_45 = F_27 ( V_50 ) -> V_55 [ V_3 ] . V_23 ;
unsigned long V_56 ;
V_45 &= ~ V_57 ;
while ( V_46 > 0 ) {
F_29 ( V_45 >= V_31 ) ;
F_29 ( V_52 > V_48 ) ;
V_56 = V_31 - V_45 ;
if ( V_56 > V_46 )
V_56 = V_46 ;
if ( F_24 ( V_52 , V_56 , 0 ) ) {
V_51 ++ ;
V_52 = 0 ;
}
if ( V_52 + V_56 > V_48 )
V_56 = V_48 - V_52 ;
V_52 += V_56 ;
V_45 += V_56 ;
V_46 -= V_56 ;
if ( V_45 == V_31 )
V_45 = 0 ;
}
}
return V_51 ;
}
static struct V_58 * F_30 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_58 * V_61 ;
struct V_62 * V_63 ;
V_63 = F_31 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
V_61 -> V_53 = 0 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
V_60 -> V_52 = 0 ;
V_60 -> V_67 = V_63 -> V_68 ;
return V_61 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_59 * V_60 ,
struct V_12 * V_12 , unsigned long V_46 ,
unsigned long V_45 , int * V_47 )
{
struct V_69 * V_70 ;
struct V_58 * V_61 ;
unsigned int V_71 ( V_14 ) , V_71 ( V_10 ) ;
int V_72 = F_12 ( V_12 , & V_14 , & V_10 ) ;
unsigned long V_56 ;
F_29 ( V_46 + V_45 > V_31 << F_33 ( V_12 ) ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 - 1 ;
V_12 += V_45 >> V_73 ;
V_45 &= ~ V_57 ;
while ( V_46 > 0 ) {
F_29 ( V_45 >= V_31 ) ;
F_29 ( V_60 -> V_52 > V_48 ) ;
V_56 = V_31 - V_45 ;
if ( V_56 > V_46 )
V_56 = V_46 ;
if ( F_24 ( V_60 -> V_52 , V_56 , * V_47 ) ) {
F_29 ( * V_47 ) ;
V_61 = F_30 ( V_2 , V_60 ) ;
}
if ( V_60 -> V_52 + V_56 > V_48 )
V_56 = V_48 - V_60 -> V_52 ;
V_70 = V_60 -> V_74 + V_60 -> V_75 ++ ;
V_70 -> V_76 = V_77 ;
if ( V_72 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
struct V_78 * V_79 ;
V_79 = & V_7 -> V_78 [ V_10 ] ;
V_70 -> V_80 . V_81 = V_79 -> V_2 -> V_81 ;
V_70 -> V_80 . V_82 . V_83 = V_79 -> V_63 . V_68 ;
V_70 -> V_76 |= V_84 ;
} else {
void * V_85 = F_34 ( V_12 ) ;
V_70 -> V_80 . V_81 = V_86 ;
V_70 -> V_80 . V_82 . V_87 = F_35 ( V_85 ) ;
}
V_70 -> V_80 . V_45 = V_45 ;
V_70 -> V_88 . V_81 = V_2 -> V_81 ;
V_70 -> V_88 . V_45 = V_60 -> V_52 ;
V_70 -> V_88 . V_82 . V_83 = V_60 -> V_67 ;
V_70 -> V_89 = V_56 ;
V_60 -> V_52 += V_56 ;
V_61 -> V_46 += V_56 ;
V_45 += V_56 ;
V_46 -= V_56 ;
if ( V_45 == V_31 && V_46 ) {
F_29 ( ! F_36 ( V_12 ) ) ;
V_12 ++ ;
V_45 = 0 ;
}
if ( * V_47 && F_27 ( V_50 ) -> V_53 && ! V_2 -> V_34 )
V_2 -> V_39 . V_64 ++ ;
* V_47 = 0 ;
}
}
static int F_37 ( struct V_49 * V_50 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_38 ( V_50 -> V_29 ) ;
int V_54 = F_27 ( V_50 ) -> V_54 ;
int V_3 ;
struct V_62 * V_63 ;
struct V_58 * V_61 ;
unsigned char * V_90 ;
int V_47 = 1 ;
int V_91 ;
V_91 = V_60 -> V_65 ;
if ( F_27 ( V_50 ) -> V_53 && V_2 -> V_34 ) {
V_63 = F_31 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
V_61 -> V_53 = F_27 ( V_50 ) -> V_53 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
}
V_63 = F_31 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
if ( ! V_2 -> V_34 )
V_61 -> V_53 = F_27 ( V_50 ) -> V_53 ;
else
V_61 -> V_53 = 0 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
V_60 -> V_52 = 0 ;
V_60 -> V_67 = V_63 -> V_68 ;
V_90 = V_50 -> V_90 ;
while ( V_90 < F_39 ( V_50 ) ) {
unsigned int V_45 = F_40 ( V_90 ) ;
unsigned int V_89 = V_31 - V_45 ;
if ( V_90 + V_89 > F_39 ( V_50 ) )
V_89 = F_39 ( V_50 ) - V_90 ;
F_32 ( V_2 , V_50 , V_60 ,
F_41 ( V_90 ) , V_89 , V_45 , & V_47 ) ;
V_90 += V_89 ;
}
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
F_32 ( V_2 , V_50 , V_60 ,
F_42 ( & F_27 ( V_50 ) -> V_55 [ V_3 ] ) ,
F_28 ( & F_27 ( V_50 ) -> V_55 [ V_3 ] ) ,
F_27 ( V_50 ) -> V_55 [ V_3 ] . V_23 ,
& V_47 ) ;
}
return V_60 -> V_65 - V_91 ;
}
static int F_43 ( struct V_1 * V_2 , int V_92 ,
struct V_59 * V_60 )
{
struct V_69 * V_93 ;
int V_94 = V_95 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_92 ; V_3 ++ ) {
V_93 = V_60 -> V_74 + V_60 -> V_96 ++ ;
if ( V_93 -> V_94 != V_97 ) {
F_44 ( V_2 -> V_29 ,
L_1 ,
V_93 -> V_94 , V_2 -> V_81 ) ;
V_94 = V_98 ;
}
}
return V_94 ;
}
static void F_45 ( struct V_1 * V_2 , int V_94 ,
struct V_58 * V_61 ,
int V_92 )
{
int V_3 ;
unsigned long V_45 ;
if ( V_92 <= 1 )
return;
V_92 -- ;
for ( V_3 = 0 ; V_3 < V_92 ; V_3 ++ ) {
int V_76 ;
if ( V_3 == V_92 - 1 )
V_76 = 0 ;
else
V_76 = V_99 ;
V_45 = 0 ;
F_46 ( V_2 , V_61 [ V_3 ] . V_66 , V_94 , V_45 ,
V_61 [ V_3 ] . V_46 , V_76 ) ;
}
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL , * V_100 ;
T_5 V_94 ;
T_1 V_101 , V_76 ;
struct V_102 * V_103 ;
struct V_104 V_105 ;
struct V_49 * V_50 ;
F_48 ( V_106 ) ;
int V_107 ;
int V_54 ;
int V_51 ;
unsigned long V_45 ;
struct V_108 * V_109 ;
struct V_59 V_60 = {
. V_74 = V_7 -> V_110 ,
. V_61 = V_7 -> V_61 ,
} ;
F_49 ( & V_105 ) ;
V_51 = 0 ;
while ( ( V_50 = F_50 ( & V_7 -> V_111 ) ) != NULL ) {
V_2 = F_38 ( V_50 -> V_29 ) ;
V_54 = F_27 ( V_50 ) -> V_54 ;
V_109 = (struct V_108 * ) V_50 -> V_112 ;
V_109 -> V_113 = F_37 ( V_50 , & V_60 ) ;
V_51 += V_54 + 1 ;
F_51 ( & V_105 , V_50 ) ;
if ( V_51 + V_35 >= V_43 )
break;
}
F_29 ( V_60 . V_65 > F_52 ( V_7 -> V_61 ) ) ;
if ( ! V_60 . V_75 )
return;
F_29 ( V_60 . V_75 > F_52 ( V_7 -> V_110 ) ) ;
F_53 ( V_7 -> V_110 , V_60 . V_75 ) ;
while ( ( V_50 = F_54 ( & V_105 ) ) != NULL ) {
V_109 = (struct V_108 * ) V_50 -> V_112 ;
V_2 = F_38 ( V_50 -> V_29 ) ;
if ( V_7 -> V_61 [ V_60 . V_114 ] . V_53 && V_2 -> V_34 ) {
V_103 = F_55 ( & V_2 -> V_39 ,
V_2 -> V_39 . V_42 ++ ) ;
V_103 -> V_76 = V_115 | V_99 ;
V_103 -> V_45 = V_7 -> V_61 [ V_60 . V_114 ] . V_53 ;
V_103 -> V_66 = V_7 -> V_61 [ V_60 . V_114 ] . V_66 ;
V_103 -> V_94 = V_109 -> V_113 ;
V_60 . V_114 ++ ;
V_109 -> V_113 -- ;
}
V_2 -> V_29 -> V_116 . V_117 += V_50 -> V_89 ;
V_2 -> V_29 -> V_116 . V_118 ++ ;
V_94 = F_43 ( V_2 , V_109 -> V_113 , & V_60 ) ;
if ( V_109 -> V_113 == 1 )
V_76 = 0 ;
else
V_76 = V_99 ;
if ( V_50 -> V_119 == V_120 )
V_76 |= V_121 | V_122 ;
else if ( V_50 -> V_119 == V_123 )
V_76 |= V_122 ;
V_45 = 0 ;
V_103 = F_46 ( V_2 , V_7 -> V_61 [ V_60 . V_114 ] . V_66 ,
V_94 , V_45 ,
V_7 -> V_61 [ V_60 . V_114 ] . V_46 ,
V_76 ) ;
if ( V_7 -> V_61 [ V_60 . V_114 ] . V_53 && ! V_2 -> V_34 ) {
struct V_124 * V_33 =
(struct V_124 * )
F_55 ( & V_2 -> V_39 ,
V_2 -> V_39 . V_42 ++ ) ;
V_103 -> V_76 |= V_125 ;
V_33 -> V_82 . V_33 . V_46 = V_7 -> V_61 [ V_60 . V_114 ] . V_53 ;
V_33 -> V_82 . V_33 . type = V_126 ;
V_33 -> V_82 . V_33 . V_127 = 0 ;
V_33 -> V_82 . V_33 . V_128 = 0 ;
V_33 -> type = V_129 ;
V_33 -> V_76 = 0 ;
}
F_45 ( V_2 , V_94 ,
V_7 -> V_61 + V_60 . V_114 + 1 ,
V_109 -> V_113 ) ;
F_56 ( & V_2 -> V_39 , V_107 ) ;
V_101 = V_2 -> V_101 ;
if ( V_107 && F_57 ( & V_2 -> V_130 ) )
F_58 ( & V_2 -> V_130 , & V_106 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_60 . V_114 += V_109 -> V_113 ;
F_61 ( V_50 ) ;
}
F_62 (vif, tmp, &notify, notify_list) {
F_63 ( V_2 -> V_101 ) ;
F_64 ( & V_2 -> V_130 ) ;
}
if ( ! F_65 ( & V_7 -> V_111 ) &&
! F_66 ( & V_7 -> V_131 ) )
F_17 ( V_7 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_68 ( & V_7 -> V_111 , V_50 ) ;
F_17 ( V_7 ) ;
}
static void F_69 ( unsigned long V_90 )
{
struct V_6 * V_7 = (struct V_6 * ) V_90 ;
F_17 ( V_7 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
return ! F_57 ( & V_2 -> V_132 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( F_72 ( F_70 ( V_2 ) ) ) {
F_64 ( & V_2 -> V_132 ) ;
F_60 ( V_2 ) ;
}
}
static struct V_1 * F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL ;
F_74 ( & V_7 -> V_133 ) ;
if ( F_57 ( & V_7 -> V_134 ) )
goto V_135;
V_2 = F_75 ( & V_7 -> V_134 ,
struct V_1 , V_132 ) ;
if ( ! V_2 )
goto V_135;
F_76 ( V_2 ) ;
F_71 ( V_2 ) ;
V_135:
F_77 ( & V_7 -> V_133 ) ;
return V_2 ;
}
void F_78 ( struct V_1 * V_2 )
{
unsigned long V_76 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( F_70 ( V_2 ) )
goto V_136;
F_79 ( & V_7 -> V_133 , V_76 ) ;
if ( ! F_70 ( V_2 ) &&
F_72 ( F_80 ( V_2 ) ) ) {
F_58 ( & V_2 -> V_132 , & V_7 -> V_134 ) ;
F_76 ( V_2 ) ;
}
F_81 ( & V_7 -> V_133 , V_76 ) ;
V_136:
F_82 () ;
if ( ( F_16 ( V_7 ) < ( V_21 / 2 ) ) &&
! F_57 ( & V_7 -> V_134 ) )
F_17 ( V_7 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_74 ( & V_7 -> V_133 ) ;
F_71 ( V_2 ) ;
F_77 ( & V_7 -> V_133 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
int V_137 ;
F_85 ( & V_2 -> V_138 , V_137 ) ;
if ( V_137 )
F_78 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned long V_139 , V_140 ;
V_139 = F_31 ( & V_2 -> V_138 , V_2 -> V_138 . V_64 ) -> V_46 ;
V_139 = F_87 ( V_139 , 131072UL ) ;
V_139 = V_28 ( V_139 , V_2 -> V_141 ) ;
V_140 = V_2 -> V_142 + V_2 -> V_141 ;
if ( V_140 < V_2 -> V_142 )
V_140 = V_143 ;
V_2 -> V_142 = F_87 ( V_140 , V_139 ) ;
}
static void F_88 ( unsigned long V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
F_86 ( V_2 ) ;
F_84 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_144 * V_145 , T_4 V_146 )
{
T_4 V_147 = V_2 -> V_138 . V_64 ;
do {
F_90 ( V_2 , V_145 , V_98 ) ;
if ( V_147 == V_146 )
break;
V_145 = F_31 ( & V_2 -> V_138 , V_147 ++ ) ;
} while ( 1 );
V_2 -> V_138 . V_64 = V_147 ;
F_84 ( V_2 ) ;
F_60 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_29 , L_2 ) ;
F_93 ( V_2 ) ;
F_60 ( V_2 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_144 * V_148 ,
struct V_144 * V_145 ,
int V_149 )
{
T_4 V_147 = V_2 -> V_138 . V_64 ;
int V_55 = 0 ;
if ( ! ( V_148 -> V_76 & V_150 ) )
return 0 ;
do {
if ( V_55 >= V_149 ) {
F_92 ( V_2 -> V_29 , L_3 ) ;
F_91 ( V_2 ) ;
return - V_55 ;
}
if ( F_95 ( V_55 >= V_35 ) ) {
F_92 ( V_2 -> V_29 , L_4 ) ;
F_91 ( V_2 ) ;
return - V_55 ;
}
memcpy ( V_145 , F_31 ( & V_2 -> V_138 , V_147 + V_55 ) ,
sizeof( * V_145 ) ) ;
if ( V_145 -> V_46 > V_148 -> V_46 ) {
F_92 ( V_2 -> V_29 , L_5 ) ;
F_91 ( V_2 ) ;
return - V_55 ;
}
V_148 -> V_46 -= V_145 -> V_46 ;
V_55 ++ ;
if ( F_95 ( ( V_145 -> V_45 + V_145 -> V_46 ) > V_31 ) ) {
F_92 ( V_2 -> V_29 , L_6 ,
V_145 -> V_45 , V_145 -> V_46 ) ;
F_91 ( V_2 ) ;
return - V_55 ;
}
} while ( ( V_145 ++ ) -> V_76 & V_150 );
return V_55 ;
}
static struct V_12 * F_96 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
T_1 V_24 )
{
struct V_12 * V_12 ;
V_12 = F_97 ( V_151 | V_152 ) ;
if ( ! V_12 )
return NULL ;
F_10 ( V_12 , V_7 , V_24 ) ;
V_7 -> V_11 [ V_24 ] = V_12 ;
return V_12 ;
}
static struct V_69 * F_98 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_144 * V_145 ,
struct V_69 * V_153 )
{
struct V_154 * V_155 = F_27 ( V_50 ) ;
T_2 * V_55 = V_155 -> V_55 ;
T_1 V_24 = * ( ( T_1 * ) V_50 -> V_90 ) ;
int V_3 , V_156 ;
V_156 = ( F_13 ( & V_155 -> V_55 [ 0 ] ) == V_24 ) ;
for ( V_3 = V_156 ; V_3 < V_155 -> V_54 ; V_3 ++ , V_145 ++ ) {
struct V_12 * V_12 ;
T_3 V_157 ;
struct V_78 * V_78 =
V_7 -> V_78 ;
V_157 = F_15 ( V_7 -> V_26 ++ ) ;
V_24 = V_7 -> V_158 [ V_157 ] ;
V_12 = F_96 ( V_7 , V_50 , V_24 ) ;
if ( ! V_12 )
goto V_159;
V_153 -> V_80 . V_82 . V_83 = V_145 -> V_68 ;
V_153 -> V_80 . V_81 = V_2 -> V_81 ;
V_153 -> V_80 . V_45 = V_145 -> V_45 ;
V_153 -> V_88 . V_82 . V_87 = F_35 ( F_34 ( V_12 ) ) ;
V_153 -> V_88 . V_81 = V_86 ;
V_153 -> V_88 . V_45 = V_145 -> V_45 ;
V_153 -> V_89 = V_145 -> V_46 ;
V_153 -> V_76 = V_84 ;
V_153 ++ ;
memcpy ( & V_78 [ V_24 ] . V_63 , V_145 , sizeof( * V_145 ) ) ;
F_76 ( V_2 ) ;
V_78 [ V_24 ] . V_2 = V_2 ;
F_14 ( & V_55 [ V_3 ] , V_24 ) ;
}
return V_153 ;
V_159:
while ( V_3 -- > V_156 ) {
F_99 ( V_7 , F_13 ( & V_55 [ V_3 ] ) ,
V_98 ) ;
}
if ( V_156 )
F_99 ( V_7 , V_24 , V_98 ) ;
return NULL ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
struct V_69 * * V_160 )
{
struct V_69 * V_153 = * V_160 ;
T_1 V_24 = * ( ( T_1 * ) V_50 -> V_90 ) ;
struct V_154 * V_155 = F_27 ( V_50 ) ;
int V_54 = V_155 -> V_54 ;
int V_3 , V_159 , V_156 ;
V_159 = V_153 -> V_94 ;
if ( F_95 ( V_159 ) )
F_99 ( V_7 , V_24 , V_98 ) ;
V_156 = ( F_13 ( & V_155 -> V_55 [ 0 ] ) == V_24 ) ;
for ( V_3 = V_156 ; V_3 < V_54 ; V_3 ++ ) {
int V_161 , V_162 ;
V_24 = F_13 ( & V_155 -> V_55 [ V_3 ] ) ;
V_162 = ( ++ V_153 ) -> V_94 ;
if ( F_72 ( ! V_162 ) ) {
if ( F_95 ( V_159 ) )
F_99 ( V_7 , V_24 , V_95 ) ;
continue;
}
F_99 ( V_7 , V_24 , V_98 ) ;
if ( V_159 )
continue;
V_24 = * ( ( T_1 * ) V_50 -> V_90 ) ;
F_99 ( V_7 , V_24 , V_95 ) ;
for ( V_161 = V_156 ; V_161 < V_3 ; V_161 ++ ) {
V_24 = F_13 ( & V_155 -> V_55 [ V_161 ] ) ;
F_99 ( V_7 , V_24 , V_95 ) ;
}
V_159 = V_162 ;
}
* V_160 = V_153 + 1 ;
return V_159 ;
}
static void F_101 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
struct V_154 * V_155 = F_27 ( V_50 ) ;
int V_54 = V_155 -> V_54 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
T_2 * V_22 = V_155 -> V_55 + V_3 ;
struct V_144 * V_145 ;
struct V_12 * V_12 ;
T_1 V_24 ;
V_24 = F_13 ( V_22 ) ;
V_145 = & V_7 -> V_78 [ V_24 ] . V_63 ;
V_12 = F_41 ( F_8 ( V_7 , V_24 ) ) ;
F_102 ( V_50 , V_3 , V_12 , V_145 -> V_45 , V_145 -> V_46 ) ;
V_50 -> V_89 += V_145 -> V_46 ;
V_50 -> V_163 += V_145 -> V_46 ;
V_50 -> V_164 += V_145 -> V_46 ;
F_103 ( V_7 -> V_11 [ V_24 ] ) ;
F_99 ( V_7 , V_24 , V_95 ) ;
}
}
static int F_104 ( struct V_1 * V_2 ,
struct V_124 * V_165 ,
int V_149 )
{
struct V_124 V_166 ;
T_4 V_147 = V_2 -> V_138 . V_64 ;
do {
if ( F_95 ( V_149 -- <= 0 ) ) {
F_92 ( V_2 -> V_29 , L_7 ) ;
F_91 ( V_2 ) ;
return - V_167 ;
}
memcpy ( & V_166 , F_31 ( & V_2 -> V_138 , V_147 ) ,
sizeof( V_166 ) ) ;
if ( F_95 ( ! V_166 . type ||
V_166 . type >= V_168 ) ) {
V_2 -> V_138 . V_64 = ++ V_147 ;
F_92 ( V_2 -> V_29 ,
L_8 , V_166 . type ) ;
F_91 ( V_2 ) ;
return - V_169 ;
}
memcpy ( & V_165 [ V_166 . type - 1 ] , & V_166 , sizeof( V_166 ) ) ;
V_2 -> V_138 . V_64 = ++ V_147 ;
} while ( V_166 . V_76 & V_170 );
return V_149 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_124 * V_33 )
{
if ( ! V_33 -> V_82 . V_33 . V_46 ) {
F_92 ( V_2 -> V_29 , L_9 ) ;
F_91 ( V_2 ) ;
return - V_169 ;
}
if ( V_33 -> V_82 . V_33 . type != V_126 ) {
F_92 ( V_2 -> V_29 , L_10 , V_33 -> V_82 . V_33 . type ) ;
F_91 ( V_2 ) ;
return - V_169 ;
}
F_27 ( V_50 ) -> V_53 = V_33 -> V_82 . V_33 . V_46 ;
F_27 ( V_50 ) -> V_171 = V_172 ;
F_27 ( V_50 ) -> V_171 |= V_173 ;
F_27 ( V_50 ) -> V_174 = 0 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_175 * V_176 ;
unsigned char * V_177 ;
int V_159 = - V_178 ;
int V_179 = 0 ;
if ( V_50 -> V_119 != V_120 && F_107 ( V_50 ) ) {
V_2 -> V_180 ++ ;
V_50 -> V_119 = V_120 ;
V_179 = 1 ;
}
if ( V_50 -> V_119 != V_120 )
return 0 ;
if ( V_50 -> V_181 != F_108 ( V_182 ) )
goto V_135;
V_176 = ( void * ) V_50 -> V_90 ;
V_177 = V_50 -> V_90 + 4 * V_176 -> V_183 ;
if ( V_177 >= F_39 ( V_50 ) )
goto V_135;
V_50 -> V_184 = V_177 - V_50 -> V_47 ;
switch ( V_176 -> V_181 ) {
case V_185 :
V_50 -> V_186 = F_109 ( struct V_187 , V_188 ) ;
if ( V_179 ) {
struct V_187 * V_189 = (struct V_187 * ) V_177 ;
V_189 -> V_188 = ~ F_110 ( V_176 -> V_190 , V_176 -> V_191 ,
V_50 -> V_89 - V_176 -> V_183 * 4 ,
V_185 , 0 ) ;
}
break;
case V_192 :
V_50 -> V_186 = F_109 ( struct V_193 , V_188 ) ;
if ( V_179 ) {
struct V_193 * V_194 = (struct V_193 * ) V_177 ;
V_194 -> V_188 = ~ F_110 ( V_176 -> V_190 , V_176 -> V_191 ,
V_50 -> V_89 - V_176 -> V_183 * 4 ,
V_192 , 0 ) ;
}
break;
default:
if ( F_111 () )
F_92 ( V_2 -> V_29 ,
L_11 ,
V_176 -> V_181 ) ;
goto V_135;
}
if ( ( V_177 + V_50 -> V_186 + 2 ) > F_39 ( V_50 ) )
goto V_135;
V_159 = 0 ;
V_135:
return V_159 ;
}
static bool F_112 ( struct V_1 * V_2 , unsigned V_46 )
{
unsigned long V_195 = V_196 ;
unsigned long V_197 =
V_2 -> V_198 . V_199 +
F_113 ( V_2 -> V_200 / 1000 ) ;
if ( F_66 ( & V_2 -> V_198 ) )
return true ;
if ( F_114 ( V_195 , V_197 ) ) {
V_2 -> V_198 . V_199 = V_195 ;
F_86 ( V_2 ) ;
}
if ( V_46 > V_2 -> V_142 ) {
V_2 -> V_198 . V_90 =
( unsigned long ) V_2 ;
V_2 -> V_198 . V_201 =
F_88 ;
F_115 ( & V_2 -> V_198 ,
V_197 ) ;
return true ;
}
return false ;
}
static unsigned F_116 ( struct V_6 * V_7 )
{
struct V_69 * V_153 = V_7 -> V_202 , * V_203 ;
struct V_49 * V_50 ;
int V_107 ;
while ( ( ( F_16 ( V_7 ) + V_35 ) < V_21 ) &&
! F_57 ( & V_7 -> V_134 ) ) {
struct V_1 * V_2 ;
struct V_144 V_204 ;
struct V_144 V_205 [ V_35 ] ;
struct V_12 * V_12 ;
struct V_124 V_165 [ V_168 - 1 ] ;
T_1 V_24 ;
T_4 V_10 ;
int V_149 ;
unsigned int V_163 ;
T_3 V_157 ;
V_2 = F_73 ( V_7 ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_138 . V_40 -> V_41 - V_2 -> V_138 . V_64 >
V_206 ) {
F_92 ( V_2 -> V_29 ,
L_12
L_13 ,
V_2 -> V_138 . V_40 -> V_41 , V_2 -> V_138 . V_64 ,
V_206 ) ;
F_91 ( V_2 ) ;
continue;
}
F_85 ( & V_2 -> V_138 , V_149 ) ;
if ( ! V_149 ) {
F_60 ( V_2 ) ;
continue;
}
V_10 = V_2 -> V_138 . V_64 ;
F_117 () ;
memcpy ( & V_204 , F_31 ( & V_2 -> V_138 , V_10 ) , sizeof( V_204 ) ) ;
if ( V_204 . V_46 > V_2 -> V_142 &&
F_112 ( V_2 , V_204 . V_46 ) ) {
F_60 ( V_2 ) ;
continue;
}
V_2 -> V_142 -= V_204 . V_46 ;
V_149 -- ;
V_2 -> V_138 . V_64 = ++ V_10 ;
memset ( V_165 , 0 , sizeof( V_165 ) ) ;
if ( V_204 . V_76 & V_207 ) {
V_149 = F_104 ( V_2 , V_165 ,
V_149 ) ;
V_10 = V_2 -> V_138 . V_64 ;
if ( F_95 ( V_149 < 0 ) )
continue;
}
V_107 = F_94 ( V_2 , & V_204 , V_205 , V_149 ) ;
if ( F_95 ( V_107 < 0 ) )
continue;
V_10 += V_107 ;
if ( F_95 ( V_204 . V_46 < V_208 ) ) {
F_44 ( V_2 -> V_29 ,
L_14 , V_204 . V_46 ) ;
F_89 ( V_2 , & V_204 , V_10 ) ;
continue;
}
if ( F_95 ( ( V_204 . V_45 + V_204 . V_46 ) > V_31 ) ) {
F_92 ( V_2 -> V_29 ,
L_15 ,
V_204 . V_45 , V_204 . V_46 ,
( V_204 . V_45 & ~ V_57 ) + V_204 . V_46 ) ;
F_91 ( V_2 ) ;
continue;
}
V_157 = F_15 ( V_7 -> V_26 ) ;
V_24 = V_7 -> V_158 [ V_157 ] ;
V_163 = ( V_204 . V_46 > V_209 &&
V_107 < V_35 ) ?
V_209 : V_204 . V_46 ;
V_50 = F_118 ( V_163 + V_210 + V_211 ,
V_212 | V_213 ) ;
if ( F_95 ( V_50 == NULL ) ) {
F_44 ( V_2 -> V_29 ,
L_16 ) ;
F_89 ( V_2 , & V_204 , V_10 ) ;
break;
}
F_119 ( V_50 , V_210 + V_211 ) ;
if ( V_165 [ V_129 - 1 ] . type ) {
struct V_124 * V_33 ;
V_33 = & V_165 [ V_129 - 1 ] ;
if ( F_105 ( V_2 , V_50 , V_33 ) ) {
F_120 ( V_50 ) ;
continue;
}
}
V_12 = F_96 ( V_7 , V_50 , V_24 ) ;
if ( ! V_12 ) {
F_120 ( V_50 ) ;
F_89 ( V_2 , & V_204 , V_10 ) ;
continue;
}
V_153 -> V_80 . V_82 . V_83 = V_204 . V_68 ;
V_153 -> V_80 . V_81 = V_2 -> V_81 ;
V_153 -> V_80 . V_45 = V_204 . V_45 ;
V_153 -> V_88 . V_82 . V_87 = F_35 ( F_34 ( V_12 ) ) ;
V_153 -> V_88 . V_81 = V_86 ;
V_153 -> V_88 . V_45 = V_204 . V_45 ;
V_153 -> V_89 = V_204 . V_46 ;
V_153 -> V_76 = V_84 ;
V_153 ++ ;
memcpy ( & V_7 -> V_78 [ V_24 ] . V_63 ,
& V_204 , sizeof( V_204 ) ) ;
V_7 -> V_78 [ V_24 ] . V_2 = V_2 ;
* ( ( T_1 * ) V_50 -> V_90 ) = V_24 ;
F_121 ( V_50 , V_163 ) ;
F_27 ( V_50 ) -> V_54 = V_107 ;
if ( V_163 < V_204 . V_46 ) {
F_27 ( V_50 ) -> V_54 ++ ;
F_14 ( & F_27 ( V_50 ) -> V_55 [ 0 ] ,
V_24 ) ;
} else {
F_14 ( & F_27 ( V_50 ) -> V_55 [ 0 ] ,
V_214 ) ;
}
V_7 -> V_26 ++ ;
V_203 = F_98 ( V_7 , V_2 ,
V_50 , V_205 , V_153 ) ;
if ( V_203 == NULL ) {
F_120 ( V_50 ) ;
F_89 ( V_2 , & V_204 , V_10 ) ;
continue;
}
V_153 = V_203 ;
F_51 ( & V_7 -> V_215 , V_50 ) ;
V_2 -> V_138 . V_64 = V_10 ;
F_84 ( V_2 ) ;
if ( ( V_153 - V_7 -> V_202 ) >= F_52 ( V_7 -> V_202 ) )
break;
}
return V_153 - V_7 -> V_202 ;
}
static void F_122 ( struct V_6 * V_7 )
{
struct V_69 * V_153 = V_7 -> V_202 ;
struct V_49 * V_50 ;
while ( ( V_50 = F_54 ( & V_7 -> V_215 ) ) != NULL ) {
struct V_144 * V_145 ;
struct V_1 * V_2 ;
T_1 V_24 ;
unsigned V_163 ;
V_24 = * ( ( T_1 * ) V_50 -> V_90 ) ;
V_2 = V_7 -> V_78 [ V_24 ] . V_2 ;
V_145 = & V_7 -> V_78 [ V_24 ] . V_63 ;
if ( F_95 ( F_100 ( V_7 , V_50 , & V_153 ) ) ) {
F_44 ( V_2 -> V_29 , L_17 ) ;
F_27 ( V_50 ) -> V_54 = 0 ;
F_120 ( V_50 ) ;
continue;
}
V_163 = V_50 -> V_89 ;
memcpy ( V_50 -> V_90 ,
( void * ) ( F_8 ( V_7 , V_24 ) | V_145 -> V_45 ) ,
V_163 ) ;
if ( V_163 < V_145 -> V_46 ) {
V_145 -> V_45 += V_163 ;
V_145 -> V_46 -= V_163 ;
} else {
F_99 ( V_7 , V_24 , V_95 ) ;
}
if ( V_145 -> V_76 & V_216 )
V_50 -> V_119 = V_120 ;
else if ( V_145 -> V_76 & V_217 )
V_50 -> V_119 = V_123 ;
F_101 ( V_7 , V_50 ) ;
if ( F_26 ( V_50 ) < V_209 && F_123 ( V_50 ) ) {
int V_218 = F_124 ( int , V_50 -> V_89 , V_209 ) ;
F_125 ( V_50 , V_218 - F_26 ( V_50 ) ) ;
}
V_50 -> V_29 = V_2 -> V_29 ;
V_50 -> V_181 = F_126 ( V_50 , V_50 -> V_29 ) ;
if ( F_106 ( V_2 , V_50 ) ) {
F_44 ( V_2 -> V_29 ,
L_18 ) ;
F_120 ( V_50 ) ;
continue;
}
V_2 -> V_29 -> V_116 . V_219 += V_50 -> V_89 ;
V_2 -> V_29 -> V_116 . V_220 ++ ;
F_127 ( V_2 , V_50 ) ;
}
}
static void F_128 ( struct V_6 * V_7 )
{
unsigned V_221 ;
V_221 = F_116 ( V_7 ) ;
if ( V_221 == 0 )
return;
F_53 ( V_7 -> V_202 , V_221 ) ;
F_122 ( V_7 ) ;
}
static void F_99 ( struct V_6 * V_7 , T_1 V_24 ,
T_6 V_94 )
{
struct V_1 * V_2 ;
struct V_78 * V_78 ;
T_3 V_157 ;
if ( V_7 -> V_11 [ V_24 ] == NULL )
return;
V_78 = & V_7 -> V_78 [ V_24 ] ;
V_2 = V_78 -> V_2 ;
F_90 ( V_2 , & V_78 -> V_63 , V_94 ) ;
V_157 = F_15 ( V_7 -> V_25 ++ ) ;
V_7 -> V_158 [ V_157 ] = V_24 ;
F_60 ( V_2 ) ;
V_7 -> V_11 [ V_24 ] -> V_18 = 0 ;
F_129 ( V_7 -> V_11 [ V_24 ] ) ;
V_7 -> V_11 [ V_24 ] = NULL ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_144 * V_145 ,
T_5 V_222 )
{
T_4 V_3 = V_2 -> V_138 . V_42 ;
struct V_223 * V_103 ;
int V_106 ;
V_103 = F_55 ( & V_2 -> V_138 , V_3 ) ;
V_103 -> V_66 = V_145 -> V_66 ;
V_103 -> V_94 = V_222 ;
if ( V_145 -> V_76 & V_207 )
F_55 ( & V_2 -> V_138 , ++ V_3 ) -> V_94 = V_224 ;
V_2 -> V_138 . V_42 = ++ V_3 ;
F_56 ( & V_2 -> V_138 , V_106 ) ;
if ( V_106 )
F_63 ( V_2 -> V_101 ) ;
}
static struct V_102 * F_46 ( struct V_1 * V_2 ,
T_1 V_66 ,
T_5 V_222 ,
T_1 V_45 ,
T_1 V_46 ,
T_1 V_76 )
{
T_4 V_3 = V_2 -> V_39 . V_42 ;
struct V_102 * V_103 ;
V_103 = F_55 ( & V_2 -> V_39 , V_3 ) ;
V_103 -> V_45 = V_45 ;
V_103 -> V_76 = V_76 ;
V_103 -> V_66 = V_66 ;
V_103 -> V_94 = ( V_225 ) V_46 ;
if ( V_222 < 0 )
V_103 -> V_94 = ( V_225 ) V_222 ;
V_2 -> V_39 . V_42 = ++ V_3 ;
return V_103 ;
}
static inline int F_130 ( struct V_6 * V_7 )
{
return ! F_65 ( & V_7 -> V_111 ) ;
}
static inline int F_131 ( struct V_6 * V_7 )
{
if ( ( ( F_16 ( V_7 ) + V_35 ) < V_21 ) &&
! F_57 ( & V_7 -> V_134 ) )
return 1 ;
return 0 ;
}
static int F_132 ( void * V_90 )
{
struct V_6 * V_7 = V_90 ;
while ( ! F_133 () ) {
F_134 ( V_7 -> V_27 ,
F_130 ( V_7 ) ||
F_131 ( V_7 ) ||
F_133 () ) ;
F_135 () ;
if ( F_133 () )
break;
if ( F_130 ( V_7 ) )
F_47 ( V_7 ) ;
if ( F_131 ( V_7 ) )
F_128 ( V_7 ) ;
}
return 0 ;
}
void F_136 ( struct V_1 * V_2 )
{
if ( V_2 -> V_138 . V_40 )
F_137 ( F_138 ( V_2 ) ,
V_2 -> V_138 . V_40 ) ;
if ( V_2 -> V_39 . V_40 )
F_137 ( F_138 ( V_2 ) ,
V_2 -> V_39 . V_40 ) ;
}
int F_139 ( struct V_1 * V_2 ,
T_7 V_226 ,
T_7 V_227 )
{
void * V_228 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
int V_159 = - V_233 ;
V_159 = F_140 ( F_138 ( V_2 ) ,
V_226 , & V_228 ) ;
if ( V_159 )
goto V_159;
V_230 = (struct V_229 * ) V_228 ;
F_141 ( & V_2 -> V_138 , V_230 , V_31 ) ;
V_159 = F_140 ( F_138 ( V_2 ) ,
V_227 , & V_228 ) ;
if ( V_159 )
goto V_159;
V_232 = (struct V_231 * ) V_228 ;
F_141 ( & V_2 -> V_39 , V_232 , V_31 ) ;
V_2 -> V_37 = 0 ;
return 0 ;
V_159:
F_136 ( V_2 ) ;
return V_159 ;
}
static int T_8 F_142 ( void )
{
int V_3 ;
int V_234 = 0 ;
int V_14 ;
if ( ! F_143 () )
return - V_235 ;
V_9 = F_144 () ;
V_6 = F_145 ( sizeof( struct V_6 ) * V_9 ) ;
if ( ! V_6 )
return - V_233 ;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
F_49 ( & V_7 -> V_111 ) ;
F_49 ( & V_7 -> V_215 ) ;
F_146 ( & V_7 -> V_131 ) ;
V_7 -> V_131 . V_90 = ( unsigned long ) V_7 ;
V_7 -> V_131 . V_201 = F_69 ;
V_7 -> V_26 = 0 ;
V_7 -> V_25 = V_21 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ )
V_7 -> V_158 [ V_3 ] = V_3 ;
F_147 ( & V_7 -> V_27 ) ;
V_7 -> V_236 = F_148 ( F_132 ,
( void * ) V_7 ,
L_19 , V_14 ) ;
if ( F_149 ( V_7 -> V_236 ) ) {
F_150 ( V_237 L_20 ) ;
F_151 ( & V_7 -> V_131 ) ;
V_234 = F_152 ( V_7 -> V_236 ) ;
goto V_238;
}
F_153 ( V_7 -> V_236 , V_14 ) ;
F_154 ( & V_7 -> V_134 ) ;
F_155 ( & V_7 -> V_133 ) ;
F_156 ( & V_7 -> V_8 , 0 ) ;
F_157 ( V_7 -> V_236 ) ;
}
V_234 = F_158 () ;
if ( V_234 )
goto V_238;
return 0 ;
V_238:
while ( -- V_14 >= 0 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
if ( V_7 -> V_11 [ V_3 ] )
F_159 ( V_7 -> V_11 [ V_3 ] ) ;
}
F_151 ( & V_7 -> V_131 ) ;
F_160 ( V_7 -> V_236 ) ;
}
F_161 ( V_6 ) ;
return V_234 ;
}
