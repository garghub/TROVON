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
V_51 = F_20 (
F_26 ( V_50 -> V_53 ) + F_27 ( V_50 ) , V_31 ) ;
V_52 = F_27 ( V_50 ) % V_31 ;
if ( F_28 ( V_50 ) -> V_54 )
V_51 ++ ;
for ( V_3 = 0 ; V_3 < F_28 ( V_50 ) -> V_55 ; V_3 ++ ) {
unsigned long V_46 = F_29 ( & F_28 ( V_50 ) -> V_56 [ V_3 ] ) ;
unsigned long V_57 ;
while ( V_46 > 0 ) {
F_30 ( V_52 > V_48 ) ;
if ( F_24 ( V_52 , V_46 , 0 ) ) {
V_51 ++ ;
V_52 = 0 ;
}
V_57 = V_46 ;
if ( V_52 + V_57 > V_48 )
V_57 = V_48 - V_52 ;
V_52 += V_57 ;
V_46 -= V_57 ;
}
}
return V_51 ;
}
static struct V_58 * F_31 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_58 * V_61 ;
struct V_62 * V_63 ;
V_63 = F_32 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
V_61 -> V_54 = 0 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
V_60 -> V_52 = 0 ;
V_60 -> V_67 = V_63 -> V_68 ;
return V_61 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_59 * V_60 ,
struct V_12 * V_12 , unsigned long V_46 ,
unsigned long V_45 , int * V_47 )
{
struct V_69 * V_70 ;
struct V_58 * V_61 ;
unsigned int V_71 ( V_14 ) , V_71 ( V_10 ) ;
int V_72 = F_12 ( V_12 , & V_14 , & V_10 ) ;
unsigned long V_57 ;
F_30 ( V_46 + V_45 > V_31 ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 - 1 ;
while ( V_46 > 0 ) {
F_30 ( V_60 -> V_52 > V_48 ) ;
if ( F_24 ( V_60 -> V_52 , V_46 , * V_47 ) ) {
F_30 ( * V_47 ) ;
V_61 = F_31 ( V_2 , V_60 ) ;
}
V_57 = V_46 ;
if ( V_60 -> V_52 + V_57 > V_48 )
V_57 = V_48 - V_60 -> V_52 ;
V_70 = V_60 -> V_73 + V_60 -> V_74 ++ ;
V_70 -> V_75 = V_76 ;
if ( V_72 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
struct V_77 * V_78 ;
V_78 = & V_7 -> V_77 [ V_10 ] ;
V_70 -> V_79 . V_80 = V_78 -> V_2 -> V_80 ;
V_70 -> V_79 . V_81 . V_82 = V_78 -> V_63 . V_68 ;
V_70 -> V_75 |= V_83 ;
} else {
void * V_84 = F_34 ( V_12 ) ;
V_70 -> V_79 . V_80 = V_85 ;
V_70 -> V_79 . V_81 . V_86 = F_35 ( V_84 ) ;
}
V_70 -> V_79 . V_45 = V_45 ;
V_70 -> V_87 . V_80 = V_2 -> V_80 ;
V_70 -> V_87 . V_45 = V_60 -> V_52 ;
V_70 -> V_87 . V_81 . V_82 = V_60 -> V_67 ;
V_70 -> V_88 = V_57 ;
V_60 -> V_52 += V_57 ;
V_61 -> V_46 += V_57 ;
V_45 += V_57 ;
V_46 -= V_57 ;
if ( * V_47 && F_28 ( V_50 ) -> V_54 && ! V_2 -> V_34 )
V_2 -> V_39 . V_64 ++ ;
* V_47 = 0 ;
}
}
static int F_36 ( struct V_49 * V_50 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_37 ( V_50 -> V_29 ) ;
int V_55 = F_28 ( V_50 ) -> V_55 ;
int V_3 ;
struct V_62 * V_63 ;
struct V_58 * V_61 ;
unsigned char * V_53 ;
int V_47 = 1 ;
int V_89 ;
V_89 = V_60 -> V_65 ;
if ( F_28 ( V_50 ) -> V_54 && V_2 -> V_34 ) {
V_63 = F_32 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
V_61 -> V_54 = F_28 ( V_50 ) -> V_54 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
}
V_63 = F_32 ( & V_2 -> V_39 , V_2 -> V_39 . V_64 ++ ) ;
V_61 = V_60 -> V_61 + V_60 -> V_65 ++ ;
if ( ! V_2 -> V_34 )
V_61 -> V_54 = F_28 ( V_50 ) -> V_54 ;
else
V_61 -> V_54 = 0 ;
V_61 -> V_46 = 0 ;
V_61 -> V_66 = V_63 -> V_66 ;
V_60 -> V_52 = 0 ;
V_60 -> V_67 = V_63 -> V_68 ;
V_53 = V_50 -> V_53 ;
while ( V_53 < F_38 ( V_50 ) ) {
unsigned int V_45 = F_26 ( V_53 ) ;
unsigned int V_88 = V_31 - V_45 ;
if ( V_53 + V_88 > F_38 ( V_50 ) )
V_88 = F_38 ( V_50 ) - V_53 ;
F_33 ( V_2 , V_50 , V_60 ,
F_39 ( V_53 ) , V_88 , V_45 , & V_47 ) ;
V_53 += V_88 ;
}
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
F_33 ( V_2 , V_50 , V_60 ,
F_40 ( & F_28 ( V_50 ) -> V_56 [ V_3 ] ) ,
F_29 ( & F_28 ( V_50 ) -> V_56 [ V_3 ] ) ,
F_28 ( V_50 ) -> V_56 [ V_3 ] . V_23 ,
& V_47 ) ;
}
return V_60 -> V_65 - V_89 ;
}
static int F_41 ( struct V_1 * V_2 , int V_90 ,
struct V_59 * V_60 )
{
struct V_69 * V_91 ;
int V_92 = V_93 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_90 ; V_3 ++ ) {
V_91 = V_60 -> V_73 + V_60 -> V_94 ++ ;
if ( V_91 -> V_92 != V_95 ) {
F_42 ( V_2 -> V_29 ,
L_1 ,
V_91 -> V_92 , V_2 -> V_80 ) ;
V_92 = V_96 ;
}
}
return V_92 ;
}
static void F_43 ( struct V_1 * V_2 , int V_92 ,
struct V_58 * V_61 ,
int V_90 )
{
int V_3 ;
unsigned long V_45 ;
if ( V_90 <= 1 )
return;
V_90 -- ;
for ( V_3 = 0 ; V_3 < V_90 ; V_3 ++ ) {
int V_75 ;
if ( V_3 == V_90 - 1 )
V_75 = 0 ;
else
V_75 = V_97 ;
V_45 = 0 ;
F_44 ( V_2 , V_61 [ V_3 ] . V_66 , V_92 , V_45 ,
V_61 [ V_3 ] . V_46 , V_75 ) ;
}
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL , * V_98 ;
T_5 V_92 ;
T_1 V_99 , V_75 ;
struct V_100 * V_101 ;
struct V_102 V_103 ;
struct V_49 * V_50 ;
F_46 ( V_104 ) ;
int V_105 ;
int V_55 ;
int V_51 ;
unsigned long V_45 ;
struct V_106 * V_107 ;
struct V_59 V_60 = {
. V_73 = V_7 -> V_108 ,
. V_61 = V_7 -> V_61 ,
} ;
F_47 ( & V_103 ) ;
V_51 = 0 ;
while ( ( V_50 = F_48 ( & V_7 -> V_109 ) ) != NULL ) {
V_2 = F_37 ( V_50 -> V_29 ) ;
V_55 = F_28 ( V_50 ) -> V_55 ;
V_107 = (struct V_106 * ) V_50 -> V_110 ;
V_107 -> V_111 = F_36 ( V_50 , & V_60 ) ;
V_51 += V_55 + 1 ;
F_49 ( & V_103 , V_50 ) ;
if ( V_51 + V_35 >= V_43 )
break;
}
F_30 ( V_60 . V_65 > F_50 ( V_7 -> V_61 ) ) ;
if ( ! V_60 . V_74 )
return;
F_30 ( V_60 . V_74 > F_50 ( V_7 -> V_108 ) ) ;
V_105 = F_51 ( V_112 , & V_7 -> V_108 ,
V_60 . V_74 ) ;
F_30 ( V_105 != 0 ) ;
while ( ( V_50 = F_52 ( & V_103 ) ) != NULL ) {
V_107 = (struct V_106 * ) V_50 -> V_110 ;
V_2 = F_37 ( V_50 -> V_29 ) ;
if ( V_7 -> V_61 [ V_60 . V_113 ] . V_54 && V_2 -> V_34 ) {
V_101 = F_53 ( & V_2 -> V_39 ,
V_2 -> V_39 . V_42 ++ ) ;
V_101 -> V_75 = V_114 | V_97 ;
V_101 -> V_45 = V_7 -> V_61 [ V_60 . V_113 ] . V_54 ;
V_101 -> V_66 = V_7 -> V_61 [ V_60 . V_113 ] . V_66 ;
V_101 -> V_92 = V_107 -> V_111 ;
V_60 . V_113 ++ ;
V_107 -> V_111 -- ;
}
V_2 -> V_29 -> V_115 . V_116 += V_50 -> V_88 ;
V_2 -> V_29 -> V_115 . V_117 ++ ;
V_92 = F_41 ( V_2 , V_107 -> V_111 , & V_60 ) ;
if ( V_107 -> V_111 == 1 )
V_75 = 0 ;
else
V_75 = V_97 ;
if ( V_50 -> V_118 == V_119 )
V_75 |= V_120 | V_121 ;
else if ( V_50 -> V_118 == V_122 )
V_75 |= V_121 ;
V_45 = 0 ;
V_101 = F_44 ( V_2 , V_7 -> V_61 [ V_60 . V_113 ] . V_66 ,
V_92 , V_45 ,
V_7 -> V_61 [ V_60 . V_113 ] . V_46 ,
V_75 ) ;
if ( V_7 -> V_61 [ V_60 . V_113 ] . V_54 && ! V_2 -> V_34 ) {
struct V_123 * V_33 =
(struct V_123 * )
F_53 ( & V_2 -> V_39 ,
V_2 -> V_39 . V_42 ++ ) ;
V_101 -> V_75 |= V_124 ;
V_33 -> V_81 . V_33 . V_46 = V_7 -> V_61 [ V_60 . V_113 ] . V_54 ;
V_33 -> V_81 . V_33 . type = V_125 ;
V_33 -> V_81 . V_33 . V_126 = 0 ;
V_33 -> V_81 . V_33 . V_127 = 0 ;
V_33 -> type = V_128 ;
V_33 -> V_75 = 0 ;
}
F_43 ( V_2 , V_92 ,
V_7 -> V_61 + V_60 . V_113 + 1 ,
V_107 -> V_111 ) ;
F_54 ( & V_2 -> V_39 , V_105 ) ;
V_99 = V_2 -> V_99 ;
if ( V_105 && F_55 ( & V_2 -> V_129 ) )
F_56 ( & V_2 -> V_129 , & V_104 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_60 . V_113 += V_107 -> V_111 ;
F_59 ( V_50 ) ;
}
F_60 (vif, tmp, &notify, notify_list) {
F_61 ( V_2 -> V_99 ) ;
F_62 ( & V_2 -> V_129 ) ;
}
if ( ! F_63 ( & V_7 -> V_109 ) &&
! F_64 ( & V_7 -> V_130 ) )
F_17 ( V_7 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_66 ( & V_7 -> V_109 , V_50 ) ;
F_17 ( V_7 ) ;
}
static void F_67 ( unsigned long V_53 )
{
struct V_6 * V_7 = (struct V_6 * ) V_53 ;
F_17 ( V_7 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
return ! F_55 ( & V_2 -> V_131 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( F_70 ( F_68 ( V_2 ) ) ) {
F_62 ( & V_2 -> V_131 ) ;
F_58 ( V_2 ) ;
}
}
static struct V_1 * F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL ;
F_72 ( & V_7 -> V_132 ) ;
if ( F_55 ( & V_7 -> V_133 ) )
goto V_134;
V_2 = F_73 ( & V_7 -> V_133 ,
struct V_1 , V_131 ) ;
if ( ! V_2 )
goto V_134;
F_74 ( V_2 ) ;
F_69 ( V_2 ) ;
V_134:
F_75 ( & V_7 -> V_132 ) ;
return V_2 ;
}
void F_76 ( struct V_1 * V_2 )
{
unsigned long V_75 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( F_68 ( V_2 ) )
goto V_135;
F_77 ( & V_7 -> V_132 , V_75 ) ;
if ( ! F_68 ( V_2 ) &&
F_70 ( F_78 ( V_2 ) ) ) {
F_56 ( & V_2 -> V_131 , & V_7 -> V_133 ) ;
F_74 ( V_2 ) ;
}
F_79 ( & V_7 -> V_132 , V_75 ) ;
V_135:
F_80 () ;
if ( ( F_16 ( V_7 ) < ( V_21 / 2 ) ) &&
! F_55 ( & V_7 -> V_133 ) )
F_17 ( V_7 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_72 ( & V_7 -> V_132 ) ;
F_69 ( V_2 ) ;
F_75 ( & V_7 -> V_132 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
int V_136 ;
F_83 ( & V_2 -> V_137 , V_136 ) ;
if ( V_136 )
F_76 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_138 , V_139 ;
V_138 = F_32 ( & V_2 -> V_137 , V_2 -> V_137 . V_64 ) -> V_46 ;
V_138 = F_85 ( V_138 , 131072UL ) ;
V_138 = V_28 ( V_138 , V_2 -> V_140 ) ;
V_139 = V_2 -> V_141 + V_2 -> V_140 ;
if ( V_139 < V_2 -> V_141 )
V_139 = V_142 ;
V_2 -> V_141 = F_85 ( V_139 , V_138 ) ;
}
static void F_86 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_84 ( V_2 ) ;
F_82 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_143 * V_144 , T_4 V_145 )
{
T_4 V_146 = V_2 -> V_137 . V_64 ;
do {
F_88 ( V_2 , V_144 , V_96 ) ;
if ( V_146 >= V_145 )
break;
V_144 = F_32 ( & V_2 -> V_137 , V_146 ++ ) ;
} while ( 1 );
V_2 -> V_137 . V_64 = V_146 ;
F_82 ( V_2 ) ;
F_58 ( V_2 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_143 * V_147 ,
struct V_143 * V_144 ,
int V_148 )
{
T_4 V_146 = V_2 -> V_137 . V_64 ;
int V_56 = 0 ;
if ( ! ( V_147 -> V_75 & V_149 ) )
return 0 ;
do {
if ( V_56 >= V_148 ) {
F_42 ( V_2 -> V_29 , L_2 ) ;
return - V_56 ;
}
if ( F_90 ( V_56 >= V_35 ) ) {
F_42 ( V_2 -> V_29 , L_3 ) ;
return - V_56 ;
}
memcpy ( V_144 , F_32 ( & V_2 -> V_137 , V_146 + V_56 ) ,
sizeof( * V_144 ) ) ;
if ( V_144 -> V_46 > V_147 -> V_46 ) {
F_42 ( V_2 -> V_29 , L_4 ) ;
return - V_56 ;
}
V_147 -> V_46 -= V_144 -> V_46 ;
V_56 ++ ;
if ( F_90 ( ( V_144 -> V_45 + V_144 -> V_46 ) > V_31 ) ) {
F_42 ( V_2 -> V_29 , L_5 ,
V_144 -> V_45 , V_144 -> V_46 ) ;
return - V_56 ;
}
} while ( ( V_144 ++ ) -> V_75 & V_149 );
return V_56 ;
}
static struct V_12 * F_91 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
T_1 V_24 )
{
struct V_12 * V_12 ;
V_12 = F_92 ( V_150 | V_151 ) ;
if ( ! V_12 )
return NULL ;
F_10 ( V_12 , V_7 , V_24 ) ;
V_7 -> V_11 [ V_24 ] = V_12 ;
return V_12 ;
}
static struct V_69 * F_93 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_143 * V_144 ,
struct V_69 * V_152 )
{
struct V_153 * V_154 = F_28 ( V_50 ) ;
T_2 * V_56 = V_154 -> V_56 ;
T_1 V_24 = * ( ( T_1 * ) V_50 -> V_53 ) ;
int V_3 , V_155 ;
V_155 = ( F_13 ( & V_154 -> V_56 [ 0 ] ) == V_24 ) ;
for ( V_3 = V_155 ; V_3 < V_154 -> V_55 ; V_3 ++ , V_144 ++ ) {
struct V_12 * V_12 ;
T_3 V_156 ;
struct V_77 * V_77 =
V_7 -> V_77 ;
V_156 = F_15 ( V_7 -> V_26 ++ ) ;
V_24 = V_7 -> V_157 [ V_156 ] ;
V_12 = F_91 ( V_7 , V_50 , V_24 ) ;
if ( ! V_12 )
return NULL ;
V_152 -> V_79 . V_81 . V_82 = V_144 -> V_68 ;
V_152 -> V_79 . V_80 = V_2 -> V_80 ;
V_152 -> V_79 . V_45 = V_144 -> V_45 ;
V_152 -> V_87 . V_81 . V_86 = F_35 ( F_34 ( V_12 ) ) ;
V_152 -> V_87 . V_80 = V_85 ;
V_152 -> V_87 . V_45 = V_144 -> V_45 ;
V_152 -> V_88 = V_144 -> V_46 ;
V_152 -> V_75 = V_83 ;
V_152 ++ ;
memcpy ( & V_77 [ V_24 ] . V_63 , V_144 , sizeof( * V_144 ) ) ;
F_74 ( V_2 ) ;
V_77 [ V_24 ] . V_2 = V_2 ;
F_14 ( & V_56 [ V_3 ] , V_24 ) ;
}
return V_152 ;
}
static int F_94 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
struct V_69 * * V_158 )
{
struct V_69 * V_152 = * V_158 ;
T_1 V_24 = * ( ( T_1 * ) V_50 -> V_53 ) ;
struct V_77 * V_77 = V_7 -> V_77 ;
struct V_1 * V_2 = V_77 [ V_24 ] . V_2 ;
struct V_143 * V_144 ;
struct V_153 * V_154 = F_28 ( V_50 ) ;
int V_55 = V_154 -> V_55 ;
int V_3 , V_159 , V_155 ;
V_159 = V_152 -> V_92 ;
if ( F_90 ( V_159 ) ) {
T_3 V_156 ;
V_156 = F_15 ( V_7 -> V_25 ++ ) ;
V_144 = & V_77 [ V_24 ] . V_63 ;
F_88 ( V_2 , V_144 , V_96 ) ;
V_7 -> V_157 [ V_156 ] = V_24 ;
F_58 ( V_2 ) ;
}
V_155 = ( F_13 ( & V_154 -> V_56 [ 0 ] ) == V_24 ) ;
for ( V_3 = V_155 ; V_3 < V_55 ; V_3 ++ ) {
int V_160 , V_161 ;
T_3 V_156 ;
V_24 = F_13 ( & V_154 -> V_56 [ V_3 ] ) ;
V_161 = ( ++ V_152 ) -> V_92 ;
if ( F_70 ( ! V_161 ) ) {
if ( F_90 ( V_159 ) )
F_95 ( V_7 , V_24 ) ;
continue;
}
V_144 = & V_7 -> V_77 [ V_24 ] . V_63 ;
F_88 ( V_2 , V_144 , V_96 ) ;
V_156 = F_15 ( V_7 -> V_25 ++ ) ;
V_7 -> V_157 [ V_156 ] = V_24 ;
F_58 ( V_2 ) ;
if ( V_159 )
continue;
V_24 = * ( ( T_1 * ) V_50 -> V_53 ) ;
F_95 ( V_7 , V_24 ) ;
for ( V_160 = V_155 ; V_160 < V_3 ; V_160 ++ ) {
V_24 = F_13 ( & V_154 -> V_56 [ V_160 ] ) ;
F_95 ( V_7 , V_24 ) ;
}
V_159 = V_161 ;
}
* V_158 = V_152 + 1 ;
return V_159 ;
}
static void F_96 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
struct V_153 * V_154 = F_28 ( V_50 ) ;
int V_55 = V_154 -> V_55 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
T_2 * V_22 = V_154 -> V_56 + V_3 ;
struct V_143 * V_144 ;
struct V_12 * V_12 ;
T_1 V_24 ;
V_24 = F_13 ( V_22 ) ;
V_144 = & V_7 -> V_77 [ V_24 ] . V_63 ;
V_12 = F_39 ( F_8 ( V_7 , V_24 ) ) ;
F_97 ( V_50 , V_3 , V_12 , V_144 -> V_45 , V_144 -> V_46 ) ;
V_50 -> V_88 += V_144 -> V_46 ;
V_50 -> V_162 += V_144 -> V_46 ;
V_50 -> V_163 += V_144 -> V_46 ;
F_98 ( V_7 -> V_11 [ V_24 ] ) ;
F_95 ( V_7 , V_24 ) ;
}
}
static int F_99 ( struct V_1 * V_2 ,
struct V_123 * V_164 ,
int V_148 )
{
struct V_123 V_165 ;
T_4 V_146 = V_2 -> V_137 . V_64 ;
do {
if ( F_90 ( V_148 -- <= 0 ) ) {
F_42 ( V_2 -> V_29 , L_6 ) ;
return - V_166 ;
}
memcpy ( & V_165 , F_32 ( & V_2 -> V_137 , V_146 ) ,
sizeof( V_165 ) ) ;
if ( F_90 ( ! V_165 . type ||
V_165 . type >= V_167 ) ) {
V_2 -> V_137 . V_64 = ++ V_146 ;
F_42 ( V_2 -> V_29 ,
L_7 , V_165 . type ) ;
return - V_168 ;
}
memcpy ( & V_164 [ V_165 . type - 1 ] , & V_165 , sizeof( V_165 ) ) ;
V_2 -> V_137 . V_64 = ++ V_146 ;
} while ( V_165 . V_75 & V_169 );
return V_148 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_123 * V_33 )
{
if ( ! V_33 -> V_81 . V_33 . V_46 ) {
F_42 ( V_2 -> V_29 , L_8 ) ;
return - V_168 ;
}
if ( V_33 -> V_81 . V_33 . type != V_125 ) {
F_42 ( V_2 -> V_29 , L_9 , V_33 -> V_81 . V_33 . type ) ;
return - V_168 ;
}
F_28 ( V_50 ) -> V_54 = V_33 -> V_81 . V_33 . V_46 ;
F_28 ( V_50 ) -> V_170 = V_171 ;
F_28 ( V_50 ) -> V_170 |= V_172 ;
F_28 ( V_50 ) -> V_173 = 0 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_174 * V_175 ;
unsigned char * V_176 ;
int V_159 = - V_177 ;
int V_178 = 0 ;
if ( V_50 -> V_118 != V_119 && F_102 ( V_50 ) ) {
V_2 -> V_179 ++ ;
V_50 -> V_118 = V_119 ;
V_178 = 1 ;
}
if ( V_50 -> V_118 != V_119 )
return 0 ;
if ( V_50 -> V_180 != F_103 ( V_181 ) )
goto V_134;
V_175 = ( void * ) V_50 -> V_53 ;
V_176 = V_50 -> V_53 + 4 * V_175 -> V_182 ;
if ( V_176 >= F_38 ( V_50 ) )
goto V_134;
V_50 -> V_183 = V_176 - V_50 -> V_47 ;
switch ( V_175 -> V_180 ) {
case V_184 :
V_50 -> V_185 = F_104 ( struct V_186 , V_187 ) ;
if ( V_178 ) {
struct V_186 * V_188 = (struct V_186 * ) V_176 ;
V_188 -> V_187 = ~ F_105 ( V_175 -> V_189 , V_175 -> V_190 ,
V_50 -> V_88 - V_175 -> V_182 * 4 ,
V_184 , 0 ) ;
}
break;
case V_191 :
V_50 -> V_185 = F_104 ( struct V_192 , V_187 ) ;
if ( V_178 ) {
struct V_192 * V_193 = (struct V_192 * ) V_176 ;
V_193 -> V_187 = ~ F_105 ( V_175 -> V_189 , V_175 -> V_190 ,
V_50 -> V_88 - V_175 -> V_182 * 4 ,
V_191 , 0 ) ;
}
break;
default:
if ( F_106 () )
F_107 ( V_2 -> V_29 ,
L_10 ,
V_175 -> V_180 ) ;
goto V_134;
}
if ( ( V_176 + V_50 -> V_185 + 2 ) > F_38 ( V_50 ) )
goto V_134;
V_159 = 0 ;
V_134:
return V_159 ;
}
static bool F_108 ( struct V_1 * V_2 , unsigned V_46 )
{
unsigned long V_194 = V_195 ;
unsigned long V_196 =
V_2 -> V_197 . V_198 +
F_109 ( V_2 -> V_199 / 1000 ) ;
if ( F_64 ( & V_2 -> V_197 ) )
return true ;
if ( F_110 ( V_194 , V_196 ) ) {
V_2 -> V_197 . V_198 = V_194 ;
F_84 ( V_2 ) ;
}
if ( V_46 > V_2 -> V_141 ) {
V_2 -> V_197 . V_53 =
( unsigned long ) V_2 ;
V_2 -> V_197 . V_200 =
F_86 ;
F_111 ( & V_2 -> V_197 ,
V_196 ) ;
return true ;
}
return false ;
}
static unsigned F_112 ( struct V_6 * V_7 )
{
struct V_69 * V_152 = V_7 -> V_201 , * V_202 ;
struct V_49 * V_50 ;
int V_105 ;
while ( ( ( F_16 ( V_7 ) + V_35 ) < V_21 ) &&
! F_55 ( & V_7 -> V_133 ) ) {
struct V_1 * V_2 ;
struct V_143 V_203 ;
struct V_143 V_204 [ V_35 ] ;
struct V_12 * V_12 ;
struct V_123 V_164 [ V_167 - 1 ] ;
T_1 V_24 ;
T_4 V_10 ;
int V_148 ;
unsigned int V_162 ;
T_3 V_156 ;
V_2 = F_71 ( V_7 ) ;
if ( ! V_2 )
continue;
F_83 ( & V_2 -> V_137 , V_148 ) ;
if ( ! V_148 ) {
F_58 ( V_2 ) ;
continue;
}
V_10 = V_2 -> V_137 . V_64 ;
F_113 () ;
memcpy ( & V_203 , F_32 ( & V_2 -> V_137 , V_10 ) , sizeof( V_203 ) ) ;
if ( V_203 . V_46 > V_2 -> V_141 &&
F_108 ( V_2 , V_203 . V_46 ) ) {
F_58 ( V_2 ) ;
continue;
}
V_2 -> V_141 -= V_203 . V_46 ;
V_148 -- ;
V_2 -> V_137 . V_64 = ++ V_10 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
if ( V_203 . V_75 & V_205 ) {
V_148 = F_99 ( V_2 , V_164 ,
V_148 ) ;
V_10 = V_2 -> V_137 . V_64 ;
if ( F_90 ( V_148 < 0 ) ) {
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
}
V_105 = F_89 ( V_2 , & V_203 , V_204 , V_148 ) ;
if ( F_90 ( V_105 < 0 ) ) {
F_87 ( V_2 , & V_203 , V_10 - V_105 ) ;
continue;
}
V_10 += V_105 ;
if ( F_90 ( V_203 . V_46 < V_206 ) ) {
F_42 ( V_2 -> V_29 ,
L_11 , V_203 . V_46 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
if ( F_90 ( ( V_203 . V_45 + V_203 . V_46 ) > V_31 ) ) {
F_42 ( V_2 -> V_29 ,
L_12 ,
V_203 . V_45 , V_203 . V_46 ,
( V_203 . V_45 & ~ V_207 ) + V_203 . V_46 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_156 = F_15 ( V_7 -> V_26 ) ;
V_24 = V_7 -> V_157 [ V_156 ] ;
V_162 = ( V_203 . V_46 > V_208 &&
V_105 < V_35 ) ?
V_208 : V_203 . V_46 ;
V_50 = F_114 ( V_162 + V_209 + V_210 ,
V_211 | V_212 ) ;
if ( F_90 ( V_50 == NULL ) ) {
F_42 ( V_2 -> V_29 ,
L_13 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
break;
}
F_115 ( V_50 , V_209 + V_210 ) ;
if ( V_164 [ V_128 - 1 ] . type ) {
struct V_123 * V_33 ;
V_33 = & V_164 [ V_128 - 1 ] ;
if ( F_100 ( V_2 , V_50 , V_33 ) ) {
F_116 ( V_50 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
}
V_12 = F_91 ( V_7 , V_50 , V_24 ) ;
if ( ! V_12 ) {
F_116 ( V_50 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_152 -> V_79 . V_81 . V_82 = V_203 . V_68 ;
V_152 -> V_79 . V_80 = V_2 -> V_80 ;
V_152 -> V_79 . V_45 = V_203 . V_45 ;
V_152 -> V_87 . V_81 . V_86 = F_35 ( F_34 ( V_12 ) ) ;
V_152 -> V_87 . V_80 = V_85 ;
V_152 -> V_87 . V_45 = V_203 . V_45 ;
V_152 -> V_88 = V_203 . V_46 ;
V_152 -> V_75 = V_83 ;
V_152 ++ ;
memcpy ( & V_7 -> V_77 [ V_24 ] . V_63 ,
& V_203 , sizeof( V_203 ) ) ;
V_7 -> V_77 [ V_24 ] . V_2 = V_2 ;
* ( ( T_1 * ) V_50 -> V_53 ) = V_24 ;
F_117 ( V_50 , V_162 ) ;
F_28 ( V_50 ) -> V_55 = V_105 ;
if ( V_162 < V_203 . V_46 ) {
F_28 ( V_50 ) -> V_55 ++ ;
F_14 ( & F_28 ( V_50 ) -> V_56 [ 0 ] ,
V_24 ) ;
} else {
F_14 ( & F_28 ( V_50 ) -> V_56 [ 0 ] ,
V_213 ) ;
}
F_49 ( & V_7 -> V_214 , V_50 ) ;
V_7 -> V_26 ++ ;
V_202 = F_93 ( V_7 , V_2 ,
V_50 , V_204 , V_152 ) ;
if ( V_202 == NULL ) {
F_116 ( V_50 ) ;
F_87 ( V_2 , & V_203 , V_10 ) ;
continue;
}
V_152 = V_202 ;
V_2 -> V_137 . V_64 = V_10 ;
F_82 ( V_2 ) ;
if ( ( V_152 - V_7 -> V_201 ) >= F_50 ( V_7 -> V_201 ) )
break;
}
return V_152 - V_7 -> V_201 ;
}
static void F_118 ( struct V_6 * V_7 )
{
struct V_69 * V_152 = V_7 -> V_201 ;
struct V_49 * V_50 ;
while ( ( V_50 = F_52 ( & V_7 -> V_214 ) ) != NULL ) {
struct V_143 * V_144 ;
struct V_1 * V_2 ;
T_1 V_24 ;
unsigned V_162 ;
V_24 = * ( ( T_1 * ) V_50 -> V_53 ) ;
V_2 = V_7 -> V_77 [ V_24 ] . V_2 ;
V_144 = & V_7 -> V_77 [ V_24 ] . V_63 ;
if ( F_90 ( F_94 ( V_7 , V_50 , & V_152 ) ) ) {
F_42 ( V_2 -> V_29 , L_14 ) ;
F_28 ( V_50 ) -> V_55 = 0 ;
F_116 ( V_50 ) ;
continue;
}
V_162 = V_50 -> V_88 ;
memcpy ( V_50 -> V_53 ,
( void * ) ( F_8 ( V_7 , V_24 ) | V_144 -> V_45 ) ,
V_162 ) ;
if ( V_162 < V_144 -> V_46 ) {
V_144 -> V_45 += V_162 ;
V_144 -> V_46 -= V_162 ;
} else {
F_95 ( V_7 , V_24 ) ;
}
if ( V_144 -> V_75 & V_215 )
V_50 -> V_118 = V_119 ;
else if ( V_144 -> V_75 & V_216 )
V_50 -> V_118 = V_122 ;
F_96 ( V_7 , V_50 ) ;
if ( F_27 ( V_50 ) < V_208 && F_119 ( V_50 ) ) {
int V_217 = F_120 ( int , V_50 -> V_88 , V_208 ) ;
F_121 ( V_50 , V_217 - F_27 ( V_50 ) ) ;
}
V_50 -> V_29 = V_2 -> V_29 ;
V_50 -> V_180 = F_122 ( V_50 , V_50 -> V_29 ) ;
if ( F_101 ( V_2 , V_50 ) ) {
F_42 ( V_2 -> V_29 ,
L_15 ) ;
F_116 ( V_50 ) ;
continue;
}
V_2 -> V_29 -> V_115 . V_218 += V_50 -> V_88 ;
V_2 -> V_29 -> V_115 . V_219 ++ ;
F_123 ( V_2 , V_50 ) ;
}
}
static void F_124 ( struct V_6 * V_7 )
{
unsigned V_220 ;
int V_105 ;
V_220 = F_112 ( V_7 ) ;
if ( V_220 == 0 )
return;
V_105 = F_51 ( V_112 ,
V_7 -> V_201 , V_220 ) ;
F_30 ( V_105 ) ;
F_118 ( V_7 ) ;
}
static void F_95 ( struct V_6 * V_7 , T_1 V_24 )
{
struct V_1 * V_2 ;
struct V_77 * V_77 ;
T_3 V_156 ;
if ( V_7 -> V_11 [ V_24 ] == NULL )
return;
V_77 = & V_7 -> V_77 [ V_24 ] ;
V_2 = V_77 -> V_2 ;
F_88 ( V_2 , & V_77 -> V_63 , V_93 ) ;
V_156 = F_15 ( V_7 -> V_25 ++ ) ;
V_7 -> V_157 [ V_156 ] = V_24 ;
F_58 ( V_2 ) ;
V_7 -> V_11 [ V_24 ] -> V_18 = 0 ;
F_125 ( V_7 -> V_11 [ V_24 ] ) ;
V_7 -> V_11 [ V_24 ] = NULL ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_143 * V_144 ,
T_5 V_221 )
{
T_4 V_3 = V_2 -> V_137 . V_42 ;
struct V_222 * V_101 ;
int V_104 ;
V_101 = F_53 ( & V_2 -> V_137 , V_3 ) ;
V_101 -> V_66 = V_144 -> V_66 ;
V_101 -> V_92 = V_221 ;
if ( V_144 -> V_75 & V_205 )
F_53 ( & V_2 -> V_137 , ++ V_3 ) -> V_92 = V_223 ;
V_2 -> V_137 . V_42 = ++ V_3 ;
F_54 ( & V_2 -> V_137 , V_104 ) ;
if ( V_104 )
F_61 ( V_2 -> V_99 ) ;
}
static struct V_100 * F_44 ( struct V_1 * V_2 ,
T_1 V_66 ,
T_5 V_221 ,
T_1 V_45 ,
T_1 V_46 ,
T_1 V_75 )
{
T_4 V_3 = V_2 -> V_39 . V_42 ;
struct V_100 * V_101 ;
V_101 = F_53 ( & V_2 -> V_39 , V_3 ) ;
V_101 -> V_45 = V_45 ;
V_101 -> V_75 = V_75 ;
V_101 -> V_66 = V_66 ;
V_101 -> V_92 = ( V_224 ) V_46 ;
if ( V_221 < 0 )
V_101 -> V_92 = ( V_224 ) V_221 ;
V_2 -> V_39 . V_42 = ++ V_3 ;
return V_101 ;
}
static inline int F_126 ( struct V_6 * V_7 )
{
return ! F_63 ( & V_7 -> V_109 ) ;
}
static inline int F_127 ( struct V_6 * V_7 )
{
if ( ( ( F_16 ( V_7 ) + V_35 ) < V_21 ) &&
! F_55 ( & V_7 -> V_133 ) )
return 1 ;
return 0 ;
}
static int F_128 ( void * V_53 )
{
struct V_6 * V_7 = V_53 ;
while ( ! F_129 () ) {
F_130 ( V_7 -> V_27 ,
F_126 ( V_7 ) ||
F_127 ( V_7 ) ||
F_129 () ) ;
F_131 () ;
if ( F_129 () )
break;
if ( F_126 ( V_7 ) )
F_45 ( V_7 ) ;
if ( F_127 ( V_7 ) )
F_124 ( V_7 ) ;
}
return 0 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_137 . V_40 )
F_133 ( F_134 ( V_2 ) ,
V_2 -> V_137 . V_40 ) ;
if ( V_2 -> V_39 . V_40 )
F_133 ( F_134 ( V_2 ) ,
V_2 -> V_39 . V_40 ) ;
}
int F_135 ( struct V_1 * V_2 ,
T_6 V_225 ,
T_6 V_226 )
{
void * V_227 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
int V_159 = - V_232 ;
V_159 = F_136 ( F_134 ( V_2 ) ,
V_225 , & V_227 ) ;
if ( V_159 )
goto V_159;
V_229 = (struct V_228 * ) V_227 ;
F_137 ( & V_2 -> V_137 , V_229 , V_31 ) ;
V_159 = F_136 ( F_134 ( V_2 ) ,
V_226 , & V_227 ) ;
if ( V_159 )
goto V_159;
V_231 = (struct V_230 * ) V_227 ;
F_137 ( & V_2 -> V_39 , V_231 , V_31 ) ;
V_2 -> V_37 = 0 ;
return 0 ;
V_159:
F_132 ( V_2 ) ;
return V_159 ;
}
static int T_7 F_138 ( void )
{
int V_3 ;
int V_233 = 0 ;
int V_14 ;
if ( ! F_139 () )
return - V_234 ;
V_9 = F_140 () ;
V_6 = F_141 ( sizeof( struct V_6 ) * V_9 ) ;
if ( ! V_6 ) {
F_142 ( V_235 L_16 , V_236 ) ;
return - V_232 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
F_47 ( & V_7 -> V_109 ) ;
F_47 ( & V_7 -> V_214 ) ;
F_143 ( & V_7 -> V_130 ) ;
V_7 -> V_130 . V_53 = ( unsigned long ) V_7 ;
V_7 -> V_130 . V_200 = F_67 ;
V_7 -> V_26 = 0 ;
V_7 -> V_25 = V_21 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ )
V_7 -> V_157 [ V_3 ] = V_3 ;
F_144 ( & V_7 -> V_27 ) ;
V_7 -> V_237 = F_145 ( F_128 ,
( void * ) V_7 ,
L_17 , V_14 ) ;
if ( F_146 ( V_7 -> V_237 ) ) {
F_142 ( V_235 L_18 ) ;
F_147 ( & V_7 -> V_130 ) ;
V_233 = F_148 ( V_7 -> V_237 ) ;
goto V_238;
}
F_149 ( V_7 -> V_237 , V_14 ) ;
F_150 ( & V_7 -> V_133 ) ;
F_151 ( & V_7 -> V_132 ) ;
F_152 ( & V_7 -> V_8 , 0 ) ;
F_153 ( V_7 -> V_237 ) ;
}
V_233 = F_154 () ;
if ( V_233 )
goto V_238;
return 0 ;
V_238:
while ( -- V_14 >= 0 ) {
struct V_6 * V_7 = & V_6 [ V_14 ] ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
if ( V_7 -> V_11 [ V_3 ] )
F_155 ( V_7 -> V_11 [ V_3 ] ) ;
}
F_147 ( & V_7 -> V_130 ) ;
F_156 ( V_7 -> V_237 ) ;
}
F_157 ( V_6 ) ;
return V_233 ;
}
