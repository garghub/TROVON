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
unsigned int V_10 )
{
return F_7 ( V_7 -> V_11 [ V_10 ] ) ;
}
static inline unsigned long F_8 ( struct V_6 * V_7 ,
unsigned int V_10 )
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
static inline T_1 F_13 ( unsigned V_3 )
{
return V_3 & ( V_21 - 1 ) ;
}
static inline T_1 F_14 ( struct V_6 * V_7 )
{
return V_21 -
V_7 -> V_22 + V_7 -> V_23 ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_16 ( & V_7 -> V_24 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_25 = F_18 ( V_2 -> V_26 -> V_27 , V_28 ) ;
if ( V_2 -> V_29 || V_2 -> V_30 || V_2 -> V_31 )
V_25 += V_32 + 1 ;
return V_25 ;
}
int F_19 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_34 ;
T_2 V_35 = F_17 ( V_2 ) ;
return ( ( V_2 -> V_36 . V_37 -> V_38 - V_33 ) < V_35 ) ||
( ( V_2 -> V_36 . V_39 + V_40 - V_33 ) < V_35 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
if ( ! F_19 ( V_2 ) )
return 0 ;
V_2 -> V_36 . V_37 -> V_41 = V_2 -> V_34 +
F_17 ( V_2 ) ;
F_21 () ;
return F_19 ( V_2 ) ;
}
static bool F_22 ( int V_42 , unsigned long V_43 , int V_44 )
{
if ( V_42 == V_45 )
return true ;
if ( ( V_42 + V_43 > V_45 ) &&
( V_43 <= V_45 ) && V_42 && ! V_44 )
return true ;
return false ;
}
unsigned int F_23 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
unsigned int V_48 ;
int V_3 , V_49 ;
V_48 = F_18 (
F_24 ( V_47 -> V_50 ) + F_25 ( V_47 ) , V_28 ) ;
V_49 = F_25 ( V_47 ) % V_28 ;
if ( F_26 ( V_47 ) -> V_51 )
V_48 ++ ;
for ( V_3 = 0 ; V_3 < F_26 ( V_47 ) -> V_52 ; V_3 ++ ) {
unsigned long V_43 = F_26 ( V_47 ) -> V_53 [ V_3 ] . V_43 ;
unsigned long V_54 ;
while ( V_43 > 0 ) {
F_27 ( V_49 > V_45 ) ;
if ( F_22 ( V_49 , V_43 , 0 ) ) {
V_48 ++ ;
V_49 = 0 ;
}
V_54 = V_43 ;
if ( V_49 + V_54 > V_45 )
V_54 = V_45 - V_49 ;
V_49 += V_54 ;
V_43 -= V_54 ;
}
}
return V_48 ;
}
static struct V_55 * F_28 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_55 * V_58 ;
struct V_59 * V_60 ;
V_60 = F_29 ( & V_2 -> V_36 , V_2 -> V_36 . V_61 ++ ) ;
V_58 = V_57 -> V_58 + V_57 -> V_62 ++ ;
V_58 -> V_51 = 0 ;
V_58 -> V_43 = 0 ;
V_58 -> V_63 = V_60 -> V_63 ;
V_57 -> V_49 = 0 ;
V_57 -> V_64 = V_60 -> V_65 ;
return V_58 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_56 * V_57 ,
struct V_12 * V_12 , unsigned long V_43 ,
unsigned long V_42 , int * V_44 )
{
struct V_66 * V_67 ;
struct V_55 * V_58 ;
unsigned int V_68 ( V_14 ) , V_68 ( V_10 ) ;
int V_69 = F_12 ( V_12 , & V_14 , & V_10 ) ;
unsigned long V_54 ;
F_27 ( V_43 + V_42 > V_28 ) ;
V_58 = V_57 -> V_58 + V_57 -> V_62 - 1 ;
while ( V_43 > 0 ) {
F_27 ( V_57 -> V_49 > V_45 ) ;
if ( F_22 ( V_57 -> V_49 , V_43 , * V_44 ) ) {
F_27 ( * V_44 ) ;
V_58 = F_28 ( V_2 , V_57 ) ;
}
V_54 = V_43 ;
if ( V_57 -> V_49 + V_54 > V_45 )
V_54 = V_45 - V_57 -> V_49 ;
V_67 = V_57 -> V_70 + V_57 -> V_71 ++ ;
V_67 -> V_72 = V_73 ;
if ( V_69 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
struct V_74 * V_75 ;
V_75 = & V_7 -> V_74 [ V_10 ] ;
V_67 -> V_76 . V_77 = V_75 -> V_2 -> V_77 ;
V_67 -> V_76 . V_78 . V_79 = V_75 -> V_60 . V_65 ;
V_67 -> V_72 |= V_80 ;
} else {
void * V_81 = F_31 ( V_12 ) ;
V_67 -> V_76 . V_77 = V_82 ;
V_67 -> V_76 . V_78 . V_83 = F_32 ( V_81 ) ;
}
V_67 -> V_76 . V_42 = V_42 ;
V_67 -> V_84 . V_77 = V_2 -> V_77 ;
V_67 -> V_84 . V_42 = V_57 -> V_49 ;
V_67 -> V_84 . V_78 . V_79 = V_57 -> V_64 ;
V_67 -> V_85 = V_54 ;
V_57 -> V_49 += V_54 ;
V_58 -> V_43 += V_54 ;
V_42 += V_54 ;
V_43 -= V_54 ;
if ( * V_44 && F_26 ( V_47 ) -> V_51 && ! V_2 -> V_31 )
V_2 -> V_36 . V_61 ++ ;
* V_44 = 0 ;
}
}
static int F_33 ( struct V_46 * V_47 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_34 ( V_47 -> V_26 ) ;
int V_52 = F_26 ( V_47 ) -> V_52 ;
int V_3 ;
struct V_59 * V_60 ;
struct V_55 * V_58 ;
unsigned char * V_50 ;
int V_44 = 1 ;
int V_86 ;
V_86 = V_57 -> V_62 ;
if ( F_26 ( V_47 ) -> V_51 && V_2 -> V_31 ) {
V_60 = F_29 ( & V_2 -> V_36 , V_2 -> V_36 . V_61 ++ ) ;
V_58 = V_57 -> V_58 + V_57 -> V_62 ++ ;
V_58 -> V_51 = F_26 ( V_47 ) -> V_51 ;
V_58 -> V_43 = 0 ;
V_58 -> V_63 = V_60 -> V_63 ;
}
V_60 = F_29 ( & V_2 -> V_36 , V_2 -> V_36 . V_61 ++ ) ;
V_58 = V_57 -> V_58 + V_57 -> V_62 ++ ;
if ( ! V_2 -> V_31 )
V_58 -> V_51 = F_26 ( V_47 ) -> V_51 ;
else
V_58 -> V_51 = 0 ;
V_58 -> V_43 = 0 ;
V_58 -> V_63 = V_60 -> V_63 ;
V_57 -> V_49 = 0 ;
V_57 -> V_64 = V_60 -> V_65 ;
V_50 = V_47 -> V_50 ;
while ( V_50 < F_35 ( V_47 ) ) {
unsigned int V_42 = F_24 ( V_50 ) ;
unsigned int V_85 = V_28 - V_42 ;
if ( V_50 + V_85 > F_35 ( V_47 ) )
V_85 = F_35 ( V_47 ) - V_50 ;
F_30 ( V_2 , V_47 , V_57 ,
F_36 ( V_50 ) , V_85 , V_42 , & V_44 ) ;
V_50 += V_85 ;
}
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
F_30 ( V_2 , V_47 , V_57 ,
F_26 ( V_47 ) -> V_53 [ V_3 ] . V_12 ,
F_26 ( V_47 ) -> V_53 [ V_3 ] . V_43 ,
F_26 ( V_47 ) -> V_53 [ V_3 ] . V_87 ,
& V_44 ) ;
}
return V_57 -> V_62 - V_86 ;
}
static int F_37 ( struct V_1 * V_2 , int V_88 ,
struct V_56 * V_57 )
{
struct V_66 * V_89 ;
int V_90 = V_91 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
V_89 = V_57 -> V_70 + V_57 -> V_92 ++ ;
if ( V_89 -> V_90 != V_93 ) {
F_38 ( V_2 -> V_26 ,
L_1 ,
V_89 -> V_90 , V_2 -> V_77 ) ;
V_90 = V_94 ;
}
}
return V_90 ;
}
static void F_39 ( struct V_1 * V_2 , int V_90 ,
struct V_55 * V_58 ,
int V_88 )
{
int V_3 ;
unsigned long V_42 ;
if ( V_88 <= 1 )
return;
V_88 -- ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
int V_72 ;
if ( V_3 == V_88 - 1 )
V_72 = 0 ;
else
V_72 = V_95 ;
V_42 = 0 ;
F_40 ( V_2 , V_58 [ V_3 ] . V_63 , V_90 , V_42 ,
V_58 [ V_3 ] . V_43 , V_72 ) ;
}
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL , * V_96 ;
T_3 V_90 ;
T_4 V_97 , V_72 ;
struct V_98 * V_99 ;
struct V_100 V_101 ;
struct V_46 * V_47 ;
F_42 ( V_102 ) ;
int V_103 ;
int V_52 ;
int V_48 ;
unsigned long V_42 ;
struct V_104 * V_105 ;
struct V_56 V_57 = {
. V_70 = V_7 -> V_106 ,
. V_58 = V_7 -> V_58 ,
} ;
F_43 ( & V_101 ) ;
V_48 = 0 ;
while ( ( V_47 = F_44 ( & V_7 -> V_107 ) ) != NULL ) {
V_2 = F_34 ( V_47 -> V_26 ) ;
V_52 = F_26 ( V_47 ) -> V_52 ;
V_105 = (struct V_104 * ) V_47 -> V_108 ;
V_105 -> V_109 = F_33 ( V_47 , & V_57 ) ;
V_48 += V_52 + 1 ;
F_45 ( & V_101 , V_47 ) ;
if ( V_48 + V_32 >= V_40 )
break;
}
F_27 ( V_57 . V_62 > F_46 ( V_7 -> V_58 ) ) ;
if ( ! V_57 . V_71 )
return;
F_27 ( V_57 . V_71 > F_46 ( V_7 -> V_106 ) ) ;
V_103 = F_47 ( V_110 , & V_7 -> V_106 ,
V_57 . V_71 ) ;
F_27 ( V_103 != 0 ) ;
while ( ( V_47 = F_48 ( & V_101 ) ) != NULL ) {
V_105 = (struct V_104 * ) V_47 -> V_108 ;
V_2 = F_34 ( V_47 -> V_26 ) ;
if ( V_7 -> V_58 [ V_57 . V_111 ] . V_51 && V_2 -> V_31 ) {
V_99 = F_49 ( & V_2 -> V_36 ,
V_2 -> V_36 . V_39 ++ ) ;
V_99 -> V_72 = V_112 | V_95 ;
V_99 -> V_42 = V_7 -> V_58 [ V_57 . V_111 ] . V_51 ;
V_99 -> V_63 = V_7 -> V_58 [ V_57 . V_111 ] . V_63 ;
V_99 -> V_90 = V_105 -> V_109 ;
V_57 . V_111 ++ ;
V_105 -> V_109 -- ;
}
V_2 -> V_26 -> V_113 . V_114 += V_47 -> V_85 ;
V_2 -> V_26 -> V_113 . V_115 ++ ;
V_90 = F_37 ( V_2 , V_105 -> V_109 , & V_57 ) ;
if ( V_105 -> V_109 == 1 )
V_72 = 0 ;
else
V_72 = V_95 ;
if ( V_47 -> V_116 == V_117 )
V_72 |= V_118 | V_119 ;
else if ( V_47 -> V_116 == V_120 )
V_72 |= V_119 ;
V_42 = 0 ;
V_99 = F_40 ( V_2 , V_7 -> V_58 [ V_57 . V_111 ] . V_63 ,
V_90 , V_42 ,
V_7 -> V_58 [ V_57 . V_111 ] . V_43 ,
V_72 ) ;
if ( V_7 -> V_58 [ V_57 . V_111 ] . V_51 && ! V_2 -> V_31 ) {
struct V_121 * V_30 =
(struct V_121 * )
F_49 ( & V_2 -> V_36 ,
V_2 -> V_36 . V_39 ++ ) ;
V_99 -> V_72 |= V_122 ;
V_30 -> V_78 . V_30 . V_43 = V_7 -> V_58 [ V_57 . V_111 ] . V_51 ;
V_30 -> V_78 . V_30 . type = V_123 ;
V_30 -> V_78 . V_30 . V_124 = 0 ;
V_30 -> V_78 . V_30 . V_125 = 0 ;
V_30 -> type = V_126 ;
V_30 -> V_72 = 0 ;
}
F_39 ( V_2 , V_90 ,
V_7 -> V_58 + V_57 . V_111 + 1 ,
V_105 -> V_109 ) ;
F_50 ( & V_2 -> V_36 , V_103 ) ;
V_97 = V_2 -> V_97 ;
if ( V_103 && F_51 ( & V_2 -> V_127 ) )
F_52 ( & V_2 -> V_127 , & V_102 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
V_57 . V_111 += V_105 -> V_109 ;
F_55 ( V_47 ) ;
}
F_56 (vif, tmp, &notify, notify_list) {
F_57 ( V_2 -> V_97 ) ;
F_58 ( & V_2 -> V_127 ) ;
}
if ( ! F_59 ( & V_7 -> V_107 ) &&
! F_60 ( & V_7 -> V_128 ) )
F_15 ( V_7 ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_62 ( & V_7 -> V_107 , V_47 ) ;
F_15 ( V_7 ) ;
}
static void F_63 ( unsigned long V_50 )
{
struct V_6 * V_7 = (struct V_6 * ) V_50 ;
F_15 ( V_7 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
return ! F_51 ( & V_2 -> V_129 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( F_66 ( F_64 ( V_2 ) ) ) {
F_58 ( & V_2 -> V_129 ) ;
F_54 ( V_2 ) ;
}
}
static struct V_1 * F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL ;
F_68 ( & V_7 -> V_130 ) ;
if ( F_51 ( & V_7 -> V_131 ) )
goto V_132;
V_2 = F_69 ( & V_7 -> V_131 ,
struct V_1 , V_129 ) ;
if ( ! V_2 )
goto V_132;
F_70 ( V_2 ) ;
F_65 ( V_2 ) ;
V_132:
F_71 ( & V_7 -> V_130 ) ;
return V_2 ;
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_72 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( F_64 ( V_2 ) )
goto V_133;
F_73 ( & V_7 -> V_130 , V_72 ) ;
if ( ! F_64 ( V_2 ) &&
F_66 ( F_74 ( V_2 ) ) ) {
F_52 ( & V_2 -> V_129 , & V_7 -> V_131 ) ;
F_70 ( V_2 ) ;
}
F_75 ( & V_7 -> V_130 , V_72 ) ;
V_133:
F_76 () ;
if ( ( F_14 ( V_7 ) < ( V_21 / 2 ) ) &&
! F_51 ( & V_7 -> V_131 ) )
F_15 ( V_7 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_68 ( & V_7 -> V_130 ) ;
F_65 ( V_2 ) ;
F_71 ( & V_7 -> V_130 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
int V_134 ;
F_79 ( & V_2 -> V_135 , V_134 ) ;
if ( V_134 )
F_72 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
unsigned long V_136 , V_137 ;
V_136 = F_29 ( & V_2 -> V_135 , V_2 -> V_135 . V_61 ) -> V_43 ;
V_136 = F_81 ( V_136 , 131072UL ) ;
V_136 = V_25 ( V_136 , V_2 -> V_138 ) ;
V_137 = V_2 -> V_139 + V_2 -> V_138 ;
if ( V_137 < V_2 -> V_139 )
V_137 = V_140 ;
V_2 -> V_139 = F_81 ( V_137 , V_136 ) ;
}
static void F_82 ( unsigned long V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
F_80 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_141 * V_142 , T_2 V_143 )
{
T_2 V_144 = V_2 -> V_135 . V_61 ;
do {
F_84 ( V_2 , V_142 , V_94 ) ;
if ( V_144 >= V_143 )
break;
V_142 = F_29 ( & V_2 -> V_135 , V_144 ++ ) ;
} while ( 1 );
V_2 -> V_135 . V_61 = V_144 ;
F_78 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_141 * V_145 ,
struct V_141 * V_142 ,
int V_146 )
{
T_2 V_144 = V_2 -> V_135 . V_61 ;
int V_53 = 0 ;
if ( ! ( V_145 -> V_72 & V_147 ) )
return 0 ;
do {
if ( V_53 >= V_146 ) {
F_38 ( V_2 -> V_26 , L_2 ) ;
return - V_53 ;
}
if ( F_86 ( V_53 >= V_32 ) ) {
F_38 ( V_2 -> V_26 , L_3 ) ;
return - V_53 ;
}
memcpy ( V_142 , F_29 ( & V_2 -> V_135 , V_144 + V_53 ) ,
sizeof( * V_142 ) ) ;
if ( V_142 -> V_43 > V_145 -> V_43 ) {
F_38 ( V_2 -> V_26 , L_4 ) ;
return - V_53 ;
}
V_145 -> V_43 -= V_142 -> V_43 ;
V_53 ++ ;
if ( F_86 ( ( V_142 -> V_42 + V_142 -> V_43 ) > V_28 ) ) {
F_38 ( V_2 -> V_26 , L_5 ,
V_142 -> V_42 , V_142 -> V_43 ) ;
return - V_53 ;
}
} while ( ( V_142 ++ ) -> V_72 & V_147 );
return V_53 ;
}
static struct V_12 * F_87 ( struct V_6 * V_7 ,
struct V_46 * V_47 ,
unsigned long V_148 )
{
struct V_12 * V_12 ;
V_12 = F_88 ( V_149 | V_150 ) ;
if ( ! V_12 )
return NULL ;
F_10 ( V_12 , V_7 , V_148 ) ;
V_7 -> V_11 [ V_148 ] = V_12 ;
return V_12 ;
}
static struct V_66 * F_89 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_141 * V_142 ,
struct V_66 * V_151 )
{
struct V_152 * V_153 = F_26 ( V_47 ) ;
T_5 * V_53 = V_153 -> V_53 ;
unsigned long V_148 = * ( ( T_4 * ) V_47 -> V_50 ) ;
int V_3 , V_154 ;
V_154 = ( ( unsigned long ) V_153 -> V_53 [ 0 ] . V_12 == V_148 ) ;
for ( V_3 = V_154 ; V_3 < V_153 -> V_52 ; V_3 ++ , V_142 ++ ) {
struct V_12 * V_12 ;
T_1 V_155 ;
struct V_74 * V_74 =
V_7 -> V_74 ;
V_155 = F_13 ( V_7 -> V_23 ++ ) ;
V_148 = V_7 -> V_156 [ V_155 ] ;
V_12 = F_87 ( V_7 , V_47 , V_148 ) ;
if ( ! V_12 )
return NULL ;
V_7 -> V_11 [ V_148 ] = V_12 ;
V_151 -> V_76 . V_78 . V_79 = V_142 -> V_65 ;
V_151 -> V_76 . V_77 = V_2 -> V_77 ;
V_151 -> V_76 . V_42 = V_142 -> V_42 ;
V_151 -> V_84 . V_78 . V_83 = F_32 ( F_31 ( V_12 ) ) ;
V_151 -> V_84 . V_77 = V_82 ;
V_151 -> V_84 . V_42 = V_142 -> V_42 ;
V_151 -> V_85 = V_142 -> V_43 ;
V_151 -> V_72 = V_80 ;
V_151 ++ ;
memcpy ( & V_74 [ V_148 ] . V_60 , V_142 , sizeof( * V_142 ) ) ;
F_70 ( V_2 ) ;
V_74 [ V_148 ] . V_2 = V_2 ;
V_53 [ V_3 ] . V_12 = ( void * ) V_148 ;
}
return V_151 ;
}
static int F_90 ( struct V_6 * V_7 ,
struct V_46 * V_47 ,
struct V_66 * * V_157 )
{
struct V_66 * V_151 = * V_157 ;
int V_148 = * ( ( T_4 * ) V_47 -> V_50 ) ;
struct V_74 * V_74 = V_7 -> V_74 ;
struct V_1 * V_2 = V_74 [ V_148 ] . V_2 ;
struct V_141 * V_142 ;
struct V_152 * V_153 = F_26 ( V_47 ) ;
int V_52 = V_153 -> V_52 ;
int V_3 , V_158 , V_154 ;
V_158 = V_151 -> V_90 ;
if ( F_86 ( V_158 ) ) {
T_1 V_155 ;
V_155 = F_13 ( V_7 -> V_22 ++ ) ;
V_142 = & V_74 [ V_148 ] . V_60 ;
F_84 ( V_2 , V_142 , V_94 ) ;
V_7 -> V_156 [ V_155 ] = V_148 ;
F_54 ( V_2 ) ;
}
V_154 = ( ( unsigned long ) V_153 -> V_53 [ 0 ] . V_12 == V_148 ) ;
for ( V_3 = V_154 ; V_3 < V_52 ; V_3 ++ ) {
int V_159 , V_160 ;
T_1 V_155 ;
V_148 = ( unsigned long ) V_153 -> V_53 [ V_3 ] . V_12 ;
V_160 = ( ++ V_151 ) -> V_90 ;
if ( F_66 ( ! V_160 ) ) {
if ( F_86 ( V_158 ) )
F_91 ( V_7 , V_148 ) ;
continue;
}
V_142 = & V_7 -> V_74 [ V_148 ] . V_60 ;
F_84 ( V_2 , V_142 , V_94 ) ;
V_155 = F_13 ( V_7 -> V_22 ++ ) ;
V_7 -> V_156 [ V_155 ] = V_148 ;
F_54 ( V_2 ) ;
if ( V_158 )
continue;
V_148 = * ( ( T_4 * ) V_47 -> V_50 ) ;
F_91 ( V_7 , V_148 ) ;
for ( V_159 = V_154 ; V_159 < V_3 ; V_159 ++ ) {
V_148 = ( unsigned long ) V_153 -> V_53 [ V_3 ] . V_12 ;
F_91 ( V_7 , V_148 ) ;
}
V_158 = V_160 ;
}
* V_157 = V_151 + 1 ;
return V_158 ;
}
static void F_92 ( struct V_6 * V_7 , struct V_46 * V_47 )
{
struct V_152 * V_153 = F_26 ( V_47 ) ;
int V_52 = V_153 -> V_52 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
T_5 * V_161 = V_153 -> V_53 + V_3 ;
struct V_141 * V_142 ;
unsigned long V_148 ;
V_148 = ( unsigned long ) V_161 -> V_12 ;
V_142 = & V_7 -> V_74 [ V_148 ] . V_60 ;
V_161 -> V_12 = F_36 ( F_8 ( V_7 , V_148 ) ) ;
V_161 -> V_43 = V_142 -> V_43 ;
V_161 -> V_87 = V_142 -> V_42 ;
V_47 -> V_85 += V_142 -> V_43 ;
V_47 -> V_162 += V_142 -> V_43 ;
V_47 -> V_163 += V_142 -> V_43 ;
F_93 ( V_7 -> V_11 [ V_148 ] ) ;
F_91 ( V_7 , V_148 ) ;
}
}
static int F_94 ( struct V_1 * V_2 ,
struct V_121 * V_164 ,
int V_146 )
{
struct V_121 V_165 ;
T_2 V_144 = V_2 -> V_135 . V_61 ;
do {
if ( F_86 ( V_146 -- <= 0 ) ) {
F_38 ( V_2 -> V_26 , L_6 ) ;
return - V_166 ;
}
memcpy ( & V_165 , F_29 ( & V_2 -> V_135 , V_144 ) ,
sizeof( V_165 ) ) ;
if ( F_86 ( ! V_165 . type ||
V_165 . type >= V_167 ) ) {
V_2 -> V_135 . V_61 = ++ V_144 ;
F_38 ( V_2 -> V_26 ,
L_7 , V_165 . type ) ;
return - V_168 ;
}
memcpy ( & V_164 [ V_165 . type - 1 ] , & V_165 , sizeof( V_165 ) ) ;
V_2 -> V_135 . V_61 = ++ V_144 ;
} while ( V_165 . V_72 & V_169 );
return V_146 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_121 * V_30 )
{
if ( ! V_30 -> V_78 . V_30 . V_43 ) {
F_38 ( V_2 -> V_26 , L_8 ) ;
return - V_168 ;
}
if ( V_30 -> V_78 . V_30 . type != V_123 ) {
F_38 ( V_2 -> V_26 , L_9 , V_30 -> V_78 . V_30 . type ) ;
return - V_168 ;
}
F_26 ( V_47 ) -> V_51 = V_30 -> V_78 . V_30 . V_43 ;
F_26 ( V_47 ) -> V_170 = V_171 ;
F_26 ( V_47 ) -> V_170 |= V_172 ;
F_26 ( V_47 ) -> V_173 = 0 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_174 * V_175 ;
unsigned char * V_176 ;
int V_158 = - V_177 ;
int V_178 = 0 ;
if ( V_47 -> V_116 != V_117 && F_97 ( V_47 ) ) {
V_2 -> V_179 ++ ;
V_47 -> V_116 = V_117 ;
V_178 = 1 ;
}
if ( V_47 -> V_116 != V_117 )
return 0 ;
if ( V_47 -> V_180 != F_98 ( V_181 ) )
goto V_132;
V_175 = ( void * ) V_47 -> V_50 ;
V_176 = V_47 -> V_50 + 4 * V_175 -> V_182 ;
if ( V_176 >= F_35 ( V_47 ) )
goto V_132;
V_47 -> V_183 = V_176 - V_47 -> V_44 ;
switch ( V_175 -> V_180 ) {
case V_184 :
V_47 -> V_185 = F_99 ( struct V_186 , V_187 ) ;
if ( V_178 ) {
struct V_186 * V_188 = (struct V_186 * ) V_176 ;
V_188 -> V_187 = ~ F_100 ( V_175 -> V_189 , V_175 -> V_190 ,
V_47 -> V_85 - V_175 -> V_182 * 4 ,
V_184 , 0 ) ;
}
break;
case V_191 :
V_47 -> V_185 = F_99 ( struct V_192 , V_187 ) ;
if ( V_178 ) {
struct V_192 * V_193 = (struct V_192 * ) V_176 ;
V_193 -> V_187 = ~ F_100 ( V_175 -> V_189 , V_175 -> V_190 ,
V_47 -> V_85 - V_175 -> V_182 * 4 ,
V_191 , 0 ) ;
}
break;
default:
if ( F_101 () )
F_102 ( V_2 -> V_26 ,
L_10 ,
V_175 -> V_180 ) ;
goto V_132;
}
if ( ( V_176 + V_47 -> V_185 + 2 ) > F_35 ( V_47 ) )
goto V_132;
V_158 = 0 ;
V_132:
return V_158 ;
}
static bool F_103 ( struct V_1 * V_2 , unsigned V_43 )
{
unsigned long V_194 = V_195 ;
unsigned long V_196 =
V_2 -> V_197 . V_198 +
F_104 ( V_2 -> V_199 / 1000 ) ;
if ( F_60 ( & V_2 -> V_197 ) )
return true ;
if ( F_105 ( V_194 , V_196 ) ) {
V_2 -> V_197 . V_198 = V_194 ;
F_80 ( V_2 ) ;
}
if ( V_43 > V_2 -> V_139 ) {
V_2 -> V_197 . V_50 =
( unsigned long ) V_2 ;
V_2 -> V_197 . V_200 =
F_82 ;
F_106 ( & V_2 -> V_197 ,
V_196 ) ;
return true ;
}
return false ;
}
static unsigned F_107 ( struct V_6 * V_7 )
{
struct V_66 * V_151 = V_7 -> V_201 , * V_202 ;
struct V_46 * V_47 ;
int V_103 ;
while ( ( ( F_14 ( V_7 ) + V_32 ) < V_21 ) &&
! F_51 ( & V_7 -> V_131 ) ) {
struct V_1 * V_2 ;
struct V_141 V_203 ;
struct V_141 V_204 [ V_32 ] ;
struct V_12 * V_12 ;
struct V_121 V_164 [ V_167 - 1 ] ;
T_4 V_148 ;
T_2 V_10 ;
int V_146 ;
unsigned int V_162 ;
T_1 V_155 ;
V_2 = F_67 ( V_7 ) ;
if ( ! V_2 )
continue;
F_79 ( & V_2 -> V_135 , V_146 ) ;
if ( ! V_146 ) {
F_54 ( V_2 ) ;
continue;
}
V_10 = V_2 -> V_135 . V_61 ;
F_108 () ;
memcpy ( & V_203 , F_29 ( & V_2 -> V_135 , V_10 ) , sizeof( V_203 ) ) ;
if ( V_203 . V_43 > V_2 -> V_139 &&
F_103 ( V_2 , V_203 . V_43 ) ) {
F_54 ( V_2 ) ;
continue;
}
V_2 -> V_139 -= V_203 . V_43 ;
V_146 -- ;
V_2 -> V_135 . V_61 = ++ V_10 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
if ( V_203 . V_72 & V_205 ) {
V_146 = F_94 ( V_2 , V_164 ,
V_146 ) ;
V_10 = V_2 -> V_135 . V_61 ;
if ( F_86 ( V_146 < 0 ) ) {
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
}
V_103 = F_85 ( V_2 , & V_203 , V_204 , V_146 ) ;
if ( F_86 ( V_103 < 0 ) ) {
F_83 ( V_2 , & V_203 , V_10 - V_103 ) ;
continue;
}
V_10 += V_103 ;
if ( F_86 ( V_203 . V_43 < V_206 ) ) {
F_38 ( V_2 -> V_26 ,
L_11 , V_203 . V_43 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
if ( F_86 ( ( V_203 . V_42 + V_203 . V_43 ) > V_28 ) ) {
F_38 ( V_2 -> V_26 ,
L_12 ,
V_203 . V_42 , V_203 . V_43 ,
( V_203 . V_42 & ~ V_207 ) + V_203 . V_43 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_155 = F_13 ( V_7 -> V_23 ) ;
V_148 = V_7 -> V_156 [ V_155 ] ;
V_162 = ( V_203 . V_43 > V_208 &&
V_103 < V_32 ) ?
V_208 : V_203 . V_43 ;
V_47 = F_109 ( V_162 + V_209 + V_210 ,
V_211 | V_212 ) ;
if ( F_86 ( V_47 == NULL ) ) {
F_38 ( V_2 -> V_26 ,
L_13 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
break;
}
F_110 ( V_47 , V_209 + V_210 ) ;
if ( V_164 [ V_126 - 1 ] . type ) {
struct V_121 * V_30 ;
V_30 = & V_164 [ V_126 - 1 ] ;
if ( F_95 ( V_2 , V_47 , V_30 ) ) {
F_111 ( V_47 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
}
V_12 = F_87 ( V_7 , V_47 , V_148 ) ;
if ( ! V_12 ) {
F_111 ( V_47 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_7 -> V_11 [ V_148 ] = V_12 ;
V_151 -> V_76 . V_78 . V_79 = V_203 . V_65 ;
V_151 -> V_76 . V_77 = V_2 -> V_77 ;
V_151 -> V_76 . V_42 = V_203 . V_42 ;
V_151 -> V_84 . V_78 . V_83 = F_32 ( F_31 ( V_12 ) ) ;
V_151 -> V_84 . V_77 = V_82 ;
V_151 -> V_84 . V_42 = V_203 . V_42 ;
V_151 -> V_85 = V_203 . V_43 ;
V_151 -> V_72 = V_80 ;
V_151 ++ ;
memcpy ( & V_7 -> V_74 [ V_148 ] . V_60 ,
& V_203 , sizeof( V_203 ) ) ;
V_7 -> V_74 [ V_148 ] . V_2 = V_2 ;
* ( ( T_4 * ) V_47 -> V_50 ) = V_148 ;
F_112 ( V_47 , V_162 ) ;
F_26 ( V_47 ) -> V_52 = V_103 ;
if ( V_162 < V_203 . V_43 ) {
F_26 ( V_47 ) -> V_52 ++ ;
F_26 ( V_47 ) -> V_53 [ 0 ] . V_12 =
( void * ) ( unsigned long ) V_148 ;
} else {
F_26 ( V_47 ) -> V_53 [ 0 ] . V_12 = ( void * ) ~ 0UL ;
}
F_45 ( & V_7 -> V_213 , V_47 ) ;
V_7 -> V_23 ++ ;
V_202 = F_89 ( V_7 , V_2 ,
V_47 , V_204 , V_151 ) ;
if ( V_202 == NULL ) {
F_111 ( V_47 ) ;
F_83 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_151 = V_202 ;
V_2 -> V_135 . V_61 = V_10 ;
F_78 ( V_2 ) ;
if ( ( V_151 - V_7 -> V_201 ) >= F_46 ( V_7 -> V_201 ) )
break;
}
return V_151 - V_7 -> V_201 ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_66 * V_151 = V_7 -> V_201 ;
struct V_46 * V_47 ;
while ( ( V_47 = F_48 ( & V_7 -> V_213 ) ) != NULL ) {
struct V_141 * V_142 ;
struct V_1 * V_2 ;
T_4 V_148 ;
unsigned V_162 ;
V_148 = * ( ( T_4 * ) V_47 -> V_50 ) ;
V_2 = V_7 -> V_74 [ V_148 ] . V_2 ;
V_142 = & V_7 -> V_74 [ V_148 ] . V_60 ;
if ( F_86 ( F_90 ( V_7 , V_47 , & V_151 ) ) ) {
F_38 ( V_2 -> V_26 , L_14 ) ;
F_26 ( V_47 ) -> V_52 = 0 ;
F_111 ( V_47 ) ;
continue;
}
V_162 = V_47 -> V_85 ;
memcpy ( V_47 -> V_50 ,
( void * ) ( F_8 ( V_7 , V_148 ) | V_142 -> V_42 ) ,
V_162 ) ;
if ( V_162 < V_142 -> V_43 ) {
V_142 -> V_42 += V_162 ;
V_142 -> V_43 -= V_162 ;
} else {
F_91 ( V_7 , V_148 ) ;
}
if ( V_142 -> V_72 & V_214 )
V_47 -> V_116 = V_117 ;
else if ( V_142 -> V_72 & V_215 )
V_47 -> V_116 = V_120 ;
F_92 ( V_7 , V_47 ) ;
if ( F_25 ( V_47 ) < V_208 && F_114 ( V_47 ) ) {
int V_216 = F_115 ( int , V_47 -> V_85 , V_208 ) ;
F_116 ( V_47 , V_216 - F_25 ( V_47 ) ) ;
}
V_47 -> V_26 = V_2 -> V_26 ;
V_47 -> V_180 = F_117 ( V_47 , V_47 -> V_26 ) ;
if ( F_96 ( V_2 , V_47 ) ) {
F_38 ( V_2 -> V_26 ,
L_15 ) ;
F_111 ( V_47 ) ;
continue;
}
V_2 -> V_26 -> V_113 . V_217 += V_47 -> V_85 ;
V_2 -> V_26 -> V_113 . V_218 ++ ;
F_118 ( V_2 , V_47 ) ;
}
}
static void F_119 ( struct V_6 * V_7 )
{
unsigned V_219 ;
int V_103 ;
V_219 = F_107 ( V_7 ) ;
if ( V_219 == 0 )
return;
V_103 = F_47 ( V_110 ,
V_7 -> V_201 , V_219 ) ;
F_27 ( V_103 ) ;
F_113 ( V_7 ) ;
}
static void F_91 ( struct V_6 * V_7 , T_4 V_148 )
{
struct V_1 * V_2 ;
struct V_74 * V_74 ;
T_1 V_155 ;
if ( V_7 -> V_11 [ V_148 ] == NULL )
return;
V_74 = & V_7 -> V_74 [ V_148 ] ;
V_2 = V_74 -> V_2 ;
F_84 ( V_2 , & V_74 -> V_60 , V_91 ) ;
V_155 = F_13 ( V_7 -> V_22 ++ ) ;
V_7 -> V_156 [ V_155 ] = V_148 ;
F_54 ( V_2 ) ;
V_7 -> V_11 [ V_148 ] -> V_18 = 0 ;
F_120 ( V_7 -> V_11 [ V_148 ] ) ;
V_7 -> V_11 [ V_148 ] = NULL ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
T_3 V_220 )
{
T_2 V_3 = V_2 -> V_135 . V_39 ;
struct V_221 * V_99 ;
int V_102 ;
V_99 = F_49 ( & V_2 -> V_135 , V_3 ) ;
V_99 -> V_63 = V_142 -> V_63 ;
V_99 -> V_90 = V_220 ;
if ( V_142 -> V_72 & V_205 )
F_49 ( & V_2 -> V_135 , ++ V_3 ) -> V_90 = V_222 ;
V_2 -> V_135 . V_39 = ++ V_3 ;
F_50 ( & V_2 -> V_135 , V_102 ) ;
if ( V_102 )
F_57 ( V_2 -> V_97 ) ;
}
static struct V_98 * F_40 ( struct V_1 * V_2 ,
T_4 V_63 ,
T_3 V_220 ,
T_4 V_42 ,
T_4 V_43 ,
T_4 V_72 )
{
T_2 V_3 = V_2 -> V_36 . V_39 ;
struct V_98 * V_99 ;
V_99 = F_49 ( & V_2 -> V_36 , V_3 ) ;
V_99 -> V_42 = V_42 ;
V_99 -> V_72 = V_72 ;
V_99 -> V_63 = V_63 ;
V_99 -> V_90 = ( V_223 ) V_43 ;
if ( V_220 < 0 )
V_99 -> V_90 = ( V_223 ) V_220 ;
V_2 -> V_36 . V_39 = ++ V_3 ;
return V_99 ;
}
static inline int F_121 ( struct V_6 * V_7 )
{
return ! F_59 ( & V_7 -> V_107 ) ;
}
static inline int F_122 ( struct V_6 * V_7 )
{
if ( ( ( F_14 ( V_7 ) + V_32 ) < V_21 ) &&
! F_51 ( & V_7 -> V_131 ) )
return 1 ;
return 0 ;
}
static int F_123 ( void * V_50 )
{
struct V_6 * V_7 = V_50 ;
while ( ! F_124 () ) {
F_125 ( V_7 -> V_24 ,
F_121 ( V_7 ) ||
F_122 ( V_7 ) ||
F_124 () ) ;
F_126 () ;
if ( F_124 () )
break;
if ( F_121 ( V_7 ) )
F_41 ( V_7 ) ;
if ( F_122 ( V_7 ) )
F_119 ( V_7 ) ;
}
return 0 ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_224 V_225 ;
if ( V_2 -> V_135 . V_37 ) {
F_128 ( & V_225 , ( unsigned long ) V_2 -> V_226 -> V_227 ,
V_228 , V_2 -> V_229 ) ;
if ( F_47 ( V_230 , & V_225 , 1 ) )
F_129 () ;
}
if ( V_2 -> V_36 . V_37 ) {
F_128 ( & V_225 , ( unsigned long ) V_2 -> V_231 -> V_227 ,
V_228 , V_2 -> V_232 ) ;
if ( F_47 ( V_230 , & V_225 , 1 ) )
F_129 () ;
}
if ( V_2 -> V_231 )
F_130 ( V_2 -> V_231 ) ;
if ( V_2 -> V_226 )
F_130 ( V_2 -> V_226 ) ;
}
int F_131 ( struct V_1 * V_2 ,
T_6 V_233 ,
T_6 V_234 )
{
struct V_235 V_225 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
int V_158 = - V_240 ;
V_2 -> V_226 = F_132 ( V_28 ) ;
if ( V_2 -> V_226 == NULL )
goto V_158;
V_2 -> V_231 = F_132 ( V_28 ) ;
if ( V_2 -> V_231 == NULL )
goto V_158;
F_133 ( & V_225 , ( unsigned long ) V_2 -> V_226 -> V_227 ,
V_228 , V_233 , V_2 -> V_77 ) ;
if ( F_47 ( V_241 , & V_225 , 1 ) )
F_129 () ;
if ( V_225 . V_90 ) {
F_134 ( V_2 -> V_26 ,
L_16 ,
V_158 , V_225 . V_90 ) ;
V_158 = V_225 . V_90 ;
goto V_158;
}
V_2 -> V_242 = V_233 ;
V_2 -> V_229 = V_225 . V_243 ;
V_237 = (struct V_236 * ) V_2 -> V_226 -> V_227 ;
F_135 ( & V_2 -> V_135 , V_237 , V_28 ) ;
F_133 ( & V_225 , ( unsigned long ) V_2 -> V_231 -> V_227 ,
V_228 , V_234 , V_2 -> V_77 ) ;
if ( F_47 ( V_241 , & V_225 , 1 ) )
F_129 () ;
if ( V_225 . V_90 ) {
F_134 ( V_2 -> V_26 ,
L_17 ,
V_158 , V_225 . V_90 ) ;
V_158 = V_225 . V_90 ;
goto V_158;
}
V_2 -> V_244 = V_234 ;
V_2 -> V_232 = V_225 . V_243 ;
V_2 -> V_34 = 0 ;
V_239 = (struct V_238 * ) V_2 -> V_231 -> V_227 ;
F_135 ( & V_2 -> V_36 , V_239 , V_28 ) ;
return 0 ;
V_158:
F_127 ( V_2 ) ;
return V_158 ;
}
static int T_7 F_136 ( void )
{
int V_3 ;
int V_245 = 0 ;
int V_14 ;
if ( ! F_137 () )
return - V_246 ;
V_9 = F_138 () ;
V_6 = F_139 ( sizeof( struct V_6 ) * V_9 ) ;
if ( ! V_6 ) {
F_140 ( V_247 L_18 , V_248 ) ;
return - V_240 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
F_43 ( & V_7 -> V_107 ) ;
F_43 ( & V_7 -> V_213 ) ;
F_141 ( & V_7 -> V_128 ) ;
V_7 -> V_128 . V_50 = ( unsigned long ) V_7 ;
V_7 -> V_128 . V_200 = F_63 ;
V_7 -> V_23 = 0 ;
V_7 -> V_22 = V_21 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ )
V_7 -> V_156 [ V_3 ] = V_3 ;
F_142 ( & V_7 -> V_24 ) ;
V_7 -> V_249 = F_143 ( F_123 ,
( void * ) V_7 ,
L_19 , V_14 ) ;
if ( F_144 ( V_7 -> V_249 ) ) {
F_140 ( V_247 L_20 ) ;
F_145 ( & V_7 -> V_128 ) ;
V_245 = F_146 ( V_7 -> V_249 ) ;
goto V_250;
}
F_147 ( V_7 -> V_249 , V_14 ) ;
F_148 ( & V_7 -> V_131 ) ;
F_149 ( & V_7 -> V_130 ) ;
F_150 ( & V_7 -> V_8 , 0 ) ;
F_151 ( V_7 -> V_249 ) ;
}
V_245 = F_152 () ;
if ( V_245 )
goto V_250;
return 0 ;
V_250:
while ( -- V_14 >= 0 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
if ( V_7 -> V_11 [ V_3 ] )
F_153 ( V_7 -> V_11 [ V_3 ] ) ;
}
F_145 ( & V_7 -> V_128 ) ;
F_154 ( V_7 -> V_249 ) ;
}
F_155 ( V_6 ) ;
return V_245 ;
}
