static void F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( & V_1 -> V_3 -> V_4 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) || F_4 ( V_1 , V_5 ) ||
( V_1 -> V_7 [ V_5 ] . V_8 &&
! F_5 ( V_1 -> V_7 [ V_5 ] . V_8 ) ) )
continue;
if ( F_6 ( & V_1 -> V_7 [ V_5 ] . V_8 ,
V_9 ) )
F_7 ( F_8 ( V_5 , V_2 ) ,
V_1 -> V_7 [ V_5 ] . V_8 ) ;
}
}
static void F_9 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) || F_4 ( V_1 , V_5 ) )
continue;
F_10 ( V_1 -> V_7 [ V_5 ] . V_8 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
int V_5 ;
int V_10 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
if ( F_3 ( V_1 , V_5 ) ||
F_4 ( V_1 , V_5 ) ||
! V_1 -> V_7 [ V_5 ] . V_8 ||
F_5 ( V_1 -> V_7 [ V_5 ] . V_8 ) )
continue;
V_10 = F_12 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_8 ) ;
if ( V_10 )
F_13 ( V_1 -> V_13 , L_1 ,
V_10 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
int V_15 = F_14 ( V_1 , V_5 ) ;
if ( V_1 -> V_7 [ V_15 ] . V_8 &&
! F_5 ( V_1 -> V_7 [ V_15 ] . V_8 ) )
F_15 ( V_1 -> V_13 ,
V_1 -> V_7 [ V_15 ] . V_8 ,
V_5 ) ;
}
}
static void F_16 ( struct V_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_12 ( V_1 -> V_11 [ V_5 ] . V_12 , NULL ) ;
}
int F_17 ( struct V_1 * V_1 )
{
return V_1 -> V_3 -> V_16 == V_17 ;
}
int F_18 ( struct V_1 * V_1 )
{
return ( V_1 -> V_18 & V_19 ) ? 1 : 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
return V_1 -> V_3 -> V_16 == V_20 ;
}
int F_20 ( struct V_1 * V_1 , int V_21 )
{
#ifdef F_21
return V_21 >= 0 && V_21 < V_1 -> V_22 ;
#else
return 0 ;
#endif
}
static void F_22 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_1 * V_1 = F_23 ( V_24 -> V_27 ) ;
if ( V_26 -> V_28 )
F_24 ( V_1 -> V_3 , V_26 -> V_29 ,
V_26 -> V_30 , V_31 ) ;
else
F_25 ( V_1 -> V_3 , V_26 -> V_29 ,
V_26 -> V_30 , V_31 ) ;
if ( V_26 -> V_32 )
F_26 ( V_26 -> V_32 ) ;
}
static void F_27 ( struct V_23 * V_24 ,
struct V_33 * V_33 , struct V_25 * V_26 , void * V_34 )
{
F_22 ( V_24 , V_26 ) ;
}
static int F_28 ( struct V_35 * V_27 , struct V_33 * V_33 ,
T_1 type , T_2 V_36 , T_2 V_37 , void * V_34 )
{
struct V_1 * V_1 = F_23 ( V_27 ) ;
F_29 ( & V_1 -> V_38 [ V_36 ] ) ;
F_30 ( & V_1 -> V_24 [ V_36 ] , V_33 ,
V_37 , F_27 ,
V_34 ) ;
if ( F_31 ( F_32 ( V_1 -> V_13 , V_36 ) ) &&
F_33 ( & V_1 -> V_24 [ V_36 ] ) >=
( V_39 + V_40 ) )
F_34 ( V_1 -> V_13 , V_36 ) ;
F_35 ( & V_1 -> V_38 [ V_36 ] ) ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
T_3 V_41 ;
bool V_10 = false ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_41 = F_37 ( & V_1 -> V_24 [ V_5 ] ) ;
V_10 |= V_41 ;
if ( V_41 )
F_38 ( V_1 -> V_13 , L_2 ,
V_5 , V_41 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
V_41 = F_39 ( & V_1 -> V_43 [ V_5 ] ) ;
V_10 |= V_41 ;
if ( V_41 )
F_38 ( V_1 -> V_13 , L_3 ,
V_5 , V_41 ) ;
}
return V_10 ;
}
static void F_40 ( struct V_1 * V_1 )
{
T_3 V_44 = F_41 ( V_1 -> V_27 ) ;
if ( V_44 != V_1 -> V_44 ) {
F_42 ( V_1 -> V_13 , L_4 ,
V_1 -> V_44 , V_44 ) ;
V_1 -> V_44 = V_44 ;
}
}
static void F_43 ( struct V_1 * V_1 )
{
T_3 V_45 = F_44 ( V_1 -> V_27 ) ;
struct V_46 * V_13 = V_1 -> V_13 ;
if ( V_45 && V_45 != V_1 -> V_47 ) {
V_1 -> V_47 = V_45 ;
if ( F_17 ( V_1 ) || F_19 ( V_1 ) ) {
V_45 = F_45 ( int , V_48 ,
F_46 ( int , V_49 , V_45 ) ) ;
if ( V_45 != V_13 -> V_45 )
F_47 ( & V_1 -> V_50 ) ;
} else {
if ( V_45 < V_13 -> V_45 )
F_13 ( V_13 ,
L_5
L_6 ,
V_13 -> V_45 , V_45 ) ;
}
}
}
static void F_48 ( struct V_1 * V_1 )
{
int V_51 = F_49 ( V_1 -> V_27 ) ;
int V_52 = F_50 ( V_1 -> V_13 ) ;
if ( V_51 && ! V_52 ) {
F_42 ( V_1 -> V_13 , L_7 ) ;
F_51 ( V_1 -> V_13 ) ;
} else if ( ! V_51 && V_52 ) {
F_42 ( V_1 -> V_13 , L_8 ) ;
F_52 ( V_1 -> V_13 ) ;
}
}
static void F_53 ( struct V_1 * V_1 )
{
F_40 ( V_1 ) ;
F_43 ( V_1 ) ;
F_48 ( V_1 ) ;
}
static T_4 F_54 ( int V_53 , void * V_54 )
{
struct V_46 * V_13 = V_54 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_55 = F_56 () ;
unsigned int V_56 = F_57 () ;
unsigned int V_57 = F_58 () ;
T_3 V_58 ;
F_59 ( & V_1 -> V_59 [ V_55 ] ) ;
V_58 = F_60 ( V_1 -> V_60 ) ;
if ( ! V_58 ) {
F_61 ( & V_1 -> V_59 [ V_55 ] ) ;
return V_61 ;
}
if ( F_62 ( V_58 , V_57 ) ) {
F_53 ( V_1 ) ;
F_63 ( & V_1 -> V_59 [ V_57 ] ) ;
}
if ( F_62 ( V_58 , V_56 ) ) {
F_63 ( & V_1 -> V_59 [ V_56 ] ) ;
F_36 ( V_1 ) ;
F_47 ( & V_1 -> V_62 ) ;
return V_63 ;
}
if ( F_62 ( V_58 , V_55 ) )
F_64 ( & V_1 -> V_64 [ 0 ] ) ;
else
F_61 ( & V_1 -> V_59 [ V_55 ] ) ;
return V_63 ;
}
static T_4 F_65 ( int V_53 , void * V_54 )
{
struct V_1 * V_1 = V_54 ;
F_64 ( & V_1 -> V_64 [ 0 ] ) ;
return V_63 ;
}
static T_4 F_66 ( int V_53 , void * V_54 )
{
struct V_65 * V_64 = V_54 ;
F_64 ( V_64 ) ;
return V_63 ;
}
static T_4 F_67 ( int V_53 , void * V_54 )
{
struct V_1 * V_1 = V_54 ;
unsigned int V_59 = F_68 ( V_1 ) ;
F_63 ( & V_1 -> V_59 [ V_59 ] ) ;
if ( F_36 ( V_1 ) )
F_47 ( & V_1 -> V_62 ) ;
return V_63 ;
}
static T_4 F_69 ( int V_53 , void * V_54 )
{
struct V_1 * V_1 = V_54 ;
unsigned int V_59 = F_70 ( V_1 ) ;
F_53 ( V_1 ) ;
F_63 ( & V_1 -> V_59 [ V_59 ] ) ;
return V_63 ;
}
static int F_71 ( struct V_1 * V_1 , struct V_23 * V_24 ,
struct V_66 * V_67 , unsigned int V_68 ,
int V_69 )
{
const T_5 * V_70 ;
T_6 V_29 ;
for ( V_70 = F_72 ( V_67 ) -> V_71 ; V_68 ; V_70 ++ ) {
V_68 -= F_73 ( V_70 ) ;
V_29 = F_74 ( & V_1 -> V_3 -> V_4 , V_70 , 0 ,
F_73 ( V_70 ) ,
V_72 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) )
return - V_73 ;
F_77 ( V_24 , V_67 , V_29 , F_73 ( V_70 ) ,
( V_68 == 0 ) ,
V_69 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_1 , struct V_23 * V_24 ,
struct V_66 * V_67 , int V_74 ,
unsigned int V_75 , int V_69 )
{
unsigned int V_76 = F_79 ( V_67 ) ;
unsigned int V_68 = V_67 -> V_30 - V_76 ;
int V_77 = ( V_68 == 0 ) ;
T_6 V_29 ;
int V_10 = 0 ;
V_29 = F_80 ( V_1 -> V_3 , V_67 -> V_54 , V_76 ,
V_31 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) )
return - V_73 ;
F_81 ( V_24 , V_67 , V_29 , V_76 , V_74 ,
V_75 , V_77 , V_69 ) ;
if ( ! V_77 )
V_10 = F_71 ( V_1 , V_24 , V_67 , V_68 , V_69 ) ;
return V_10 ;
}
static int F_82 ( struct V_1 * V_1 , struct V_23 * V_24 ,
struct V_66 * V_67 , int V_74 ,
unsigned int V_75 , int V_69 )
{
unsigned int V_76 = F_79 ( V_67 ) ;
unsigned int V_68 = V_67 -> V_30 - V_76 ;
unsigned int V_78 = F_83 ( V_67 ) ;
unsigned int V_79 = V_78 + V_67 -> V_79 ;
int V_77 = ( V_68 == 0 ) ;
T_6 V_29 ;
int V_10 = 0 ;
V_29 = F_80 ( V_1 -> V_3 , V_67 -> V_54 , V_76 ,
V_31 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) )
return - V_73 ;
F_84 ( V_24 , V_67 , V_29 , V_76 , V_79 ,
V_78 , V_74 , V_75 , V_77 ,
V_69 ) ;
if ( ! V_77 )
V_10 = F_71 ( V_1 , V_24 , V_67 , V_68 , V_69 ) ;
return V_10 ;
}
static int F_85 ( struct V_1 * V_1 , struct V_23 * V_24 ,
struct V_66 * V_67 , unsigned int V_80 ,
int V_74 , unsigned int V_75 ,
int V_69 )
{
unsigned int V_81 = F_79 ( V_67 ) ;
unsigned int V_68 = V_67 -> V_30 - V_81 ;
unsigned int V_78 = F_86 ( V_67 ) + F_87 ( V_67 ) ;
int V_77 = ( V_68 == 0 ) ;
unsigned int V_30 ;
T_6 V_29 ;
unsigned int V_82 = 0 ;
T_5 * V_70 ;
if ( V_67 -> V_83 == F_88 ( V_84 ) ) {
F_89 ( V_67 ) -> V_85 = 0 ;
F_90 ( V_67 ) -> V_85 = ~ F_91 ( F_89 ( V_67 ) -> V_86 ,
F_89 ( V_67 ) -> V_87 , 0 , V_88 , 0 ) ;
} else if ( V_67 -> V_83 == F_88 ( V_89 ) ) {
F_90 ( V_67 ) -> V_85 = ~ F_92 ( & F_93 ( V_67 ) -> V_86 ,
& F_93 ( V_67 ) -> V_87 , 0 , V_88 , 0 ) ;
}
while ( V_81 ) {
V_30 = F_94 ( V_81 , ( unsigned int ) V_90 ) ;
V_29 = F_80 ( V_1 -> V_3 , V_67 -> V_54 + V_82 , V_30 ,
V_31 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) )
return - V_73 ;
F_95 ( V_24 , V_67 , V_29 , V_30 , V_80 , V_78 ,
V_74 , V_75 ,
V_77 && ( V_30 == V_81 ) , V_69 ) ;
V_81 -= V_30 ;
V_82 += V_30 ;
}
if ( V_77 )
return 0 ;
for ( V_70 = F_72 ( V_67 ) -> V_71 ; V_68 ; V_70 ++ ) {
V_68 -= F_73 ( V_70 ) ;
V_81 = F_73 ( V_70 ) ;
V_82 = 0 ;
while ( V_81 ) {
V_30 = F_94 ( V_81 ,
( unsigned int ) V_90 ) ;
V_29 = F_74 ( & V_1 -> V_3 -> V_4 , V_70 ,
V_82 , V_30 ,
V_72 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) )
return - V_73 ;
F_77 ( V_24 , V_67 , V_29 , V_30 ,
( V_68 == 0 ) &&
( V_30 == V_81 ) ,
V_69 ) ;
V_81 -= V_30 ;
V_82 += V_30 ;
}
}
return 0 ;
}
static inline void F_96 ( struct V_1 * V_1 ,
struct V_23 * V_24 , struct V_66 * V_67 )
{
unsigned int V_80 = F_72 ( V_67 ) -> V_91 ;
unsigned int V_75 = 0 ;
int V_74 = 0 ;
int V_69 = 0 ;
int V_10 ;
if ( F_97 ( V_67 ) ) {
V_74 = 1 ;
V_75 = F_98 ( V_67 ) ;
} else if ( V_1 -> V_92 ) {
V_75 = V_1 -> V_93 ;
V_69 = 1 ;
}
if ( V_80 )
V_10 = F_85 ( V_1 , V_24 , V_67 , V_80 ,
V_74 , V_75 ,
V_69 ) ;
else if ( V_67 -> V_94 == V_95 )
V_10 = F_82 ( V_1 , V_24 , V_67 , V_74 ,
V_75 , V_69 ) ;
else
V_10 = F_78 ( V_1 , V_24 , V_67 , V_74 ,
V_75 , V_69 ) ;
if ( F_75 ( V_10 ) ) {
struct V_25 * V_26 ;
V_26 = V_24 -> V_96 -> V_97 ;
while ( ! V_26 -> V_32 && ( V_26 -> V_98 != V_24 -> V_99 ) ) {
F_22 ( V_24 , V_26 ) ;
V_24 -> V_100 . V_101 ++ ;
V_26 = V_26 -> V_97 ;
}
V_24 -> V_96 = V_26 -> V_98 ;
F_99 ( V_67 ) ;
}
}
static T_7 F_100 ( struct V_66 * V_67 ,
struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_23 * V_24 ;
unsigned int V_102 ;
struct V_103 * V_104 ;
if ( V_67 -> V_30 <= 0 ) {
F_26 ( V_67 ) ;
return V_105 ;
}
V_102 = F_101 ( V_67 ) % V_1 -> V_14 ;
V_24 = & V_1 -> V_24 [ V_102 ] ;
V_104 = F_32 ( V_13 , V_102 ) ;
if ( F_72 ( V_67 ) -> V_91 == 0 &&
F_72 ( V_67 ) -> V_106 + 1 > V_107 &&
F_102 ( V_67 ) ) {
F_26 ( V_67 ) ;
return V_105 ;
}
F_29 ( & V_1 -> V_38 [ V_102 ] ) ;
if ( F_33 ( V_24 ) <
F_72 ( V_67 ) -> V_106 + V_40 ) {
F_103 ( V_104 ) ;
F_38 ( V_13 , L_9 ) ;
F_35 ( & V_1 -> V_38 [ V_102 ] ) ;
return V_108 ;
}
F_96 ( V_1 , V_24 , V_67 ) ;
if ( F_33 ( V_24 ) < V_39 + V_40 )
F_103 ( V_104 ) ;
if ( ! V_67 -> V_109 || F_104 ( V_104 ) )
F_105 ( V_24 ) ;
F_35 ( & V_1 -> V_38 [ V_102 ] ) ;
return V_105 ;
}
static struct V_110 * F_106 ( struct V_46 * V_13 ,
struct V_110 * V_111 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_112 * V_113 ;
int V_10 ;
V_10 = F_107 ( V_1 , & V_113 ) ;
if ( V_10 == - V_73 )
return V_111 ;
V_111 -> V_114 = V_113 -> V_115 . V_116 ;
V_111 -> V_117 = V_113 -> V_115 . V_118 ;
V_111 -> V_119 = V_113 -> V_115 . V_119 ;
V_111 -> V_120 = V_113 -> V_115 . V_121 ;
V_111 -> V_122 = V_113 -> V_123 . V_124 ;
V_111 -> V_125 = V_113 -> V_123 . V_126 ;
V_111 -> V_127 = V_113 -> V_123 . V_127 ;
V_111 -> V_128 = V_113 -> V_123 . V_129 ;
V_111 -> V_130 = V_1 -> V_131 ;
V_111 -> V_132 = V_1 -> V_133 ;
V_111 -> V_134 = V_113 -> V_123 . V_135 + V_113 -> V_123 . V_136 ;
return V_111 ;
}
static int F_108 ( struct V_46 * V_13 , const T_1 * V_137 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
if ( V_1 -> V_138 == V_139 ) {
unsigned int V_138 = F_109 ( V_13 ) ;
F_13 ( V_13 , L_10 ,
V_139 , V_138 ) ;
return - V_140 ;
}
F_110 ( V_1 , V_137 ) ;
V_1 -> V_138 ++ ;
return 0 ;
}
static int F_111 ( struct V_46 * V_13 , const T_1 * V_137 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
F_112 ( V_1 , V_137 ) ;
V_1 -> V_138 -- ;
return 0 ;
}
static int F_113 ( struct V_46 * V_13 , const T_1 * V_141 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
if ( V_1 -> V_142 == V_143 ) {
unsigned int V_142 = F_114 ( V_13 ) ;
F_13 ( V_13 , L_11 ,
V_143 , V_142 ) ;
return - V_140 ;
}
F_110 ( V_1 , V_141 ) ;
V_1 -> V_142 ++ ;
return 0 ;
}
static int F_115 ( struct V_46 * V_13 , const T_1 * V_141 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
F_112 ( V_1 , V_141 ) ;
V_1 -> V_142 -- ;
return 0 ;
}
void F_116 ( struct V_1 * V_1 )
{
struct V_46 * V_13 = V_1 -> V_13 ;
F_117 ( V_13 , NULL ) ;
F_118 ( V_13 , NULL ) ;
V_1 -> V_138 = 0 ;
V_1 -> V_142 = 0 ;
V_1 -> V_144 = 0 ;
}
static int F_119 ( struct V_46 * V_13 , char * V_145 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
if ( F_17 ( V_1 ) || F_19 ( V_1 ) ) {
if ( ! F_120 ( V_145 ) && ! F_121 ( V_145 ) )
return - V_146 ;
} else {
if ( ! F_120 ( V_145 ) )
return - V_146 ;
}
memcpy ( V_13 -> V_147 , V_145 , V_13 -> V_148 ) ;
return 0 ;
}
static int F_122 ( struct V_46 * V_13 , void * V_149 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_150 * V_86 = V_149 ;
char * V_145 = V_86 -> V_151 ;
int V_10 ;
if ( F_123 ( V_1 -> V_13 ) ) {
V_10 = F_124 ( V_1 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_119 ( V_13 , V_145 ) ;
if ( V_10 )
return V_10 ;
if ( F_123 ( V_1 -> V_13 ) ) {
V_10 = F_125 ( V_1 ) ;
if ( V_10 )
return V_10 ;
}
return V_10 ;
}
static int F_126 ( struct V_46 * V_13 , void * V_149 )
{
struct V_150 * V_86 = V_149 ;
char * V_145 = V_86 -> V_151 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
int V_10 ;
V_10 = F_124 ( V_1 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_119 ( V_13 , V_145 ) ;
if ( V_10 )
return V_10 ;
return F_125 ( V_1 ) ;
}
static void F_127 ( struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
int V_152 = 1 ;
int V_128 = ( V_13 -> V_144 & V_153 ) ? 1 : 0 ;
int V_154 = ( V_13 -> V_144 & V_155 ) ? 1 : 0 ;
int V_156 = ( V_13 -> V_144 & V_157 ) ||
F_114 ( V_13 ) > V_143 ;
int V_158 = ( V_13 -> V_144 & V_159 ) ||
F_109 ( V_13 ) > V_139 ;
unsigned int V_144 = V_13 -> V_144 |
( V_158 ? V_159 : 0 ) |
( V_156 ? V_157 : 0 ) ;
if ( V_1 -> V_144 != V_144 ) {
V_1 -> V_144 = V_144 ;
F_128 ( V_1 , V_152 ,
V_128 , V_154 , V_156 , V_158 ) ;
}
if ( ! V_156 ) {
F_129 ( V_13 , F_113 , F_115 ) ;
if ( ! V_158 )
F_130 ( V_13 , F_108 , F_111 ) ;
}
}
static void F_131 ( struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
F_47 ( & V_1 -> V_160 ) ;
}
static int F_132 ( struct V_46 * V_13 , int V_21 , T_1 * V_161 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_162 * V_163 ;
int V_10 ;
F_133 ( V_1 , V_21 , V_163 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( F_120 ( V_161 ) || F_121 ( V_161 ) ) {
if ( V_21 == V_164 ) {
memcpy ( V_163 -> V_165 , V_161 , V_166 ) ;
return 0 ;
} else {
F_134 ( V_21 , V_10 , V_1 ,
V_167 , V_161 ) ;
return F_135 ( V_10 ) ;
}
} else
return - V_168 ;
}
static int F_136 ( struct V_46 * V_13 , int V_21 ,
struct V_169 * V_170 [] )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_162 V_171 ;
struct V_162 * V_163 ;
int V_10 = 0 , V_172 = 1 ;
F_133 ( V_1 , V_21 , V_163 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_170 [ V_173 ] )
return - V_174 ;
memcpy ( & V_171 , V_163 , sizeof( * V_1 -> V_163 ) ) ;
memset ( V_163 , 0 , sizeof( * V_1 -> V_163 ) ) ;
V_163 -> V_175 |= V_176 ;
V_163 -> V_177 = F_137 ( V_170 [ V_173 ] ) ;
if ( V_170 [ V_178 ] ) {
V_163 -> V_175 |= V_179 ;
memcpy ( V_163 -> V_180 , F_138 ( V_170 [ V_178 ] ) ,
V_181 ) ;
}
if ( V_170 [ V_182 ] ) {
V_163 -> V_175 |= V_183 ;
memcpy ( V_163 -> V_184 ,
F_138 ( V_170 [ V_182 ] ) , V_185 ) ;
}
if ( V_170 [ V_186 ] ) {
V_163 -> V_175 |= V_187 ;
memcpy ( V_163 -> V_188 ,
F_138 ( V_170 [ V_186 ] ) , V_185 ) ;
}
if ( V_21 == V_164 ) {
if ( ! F_121 ( V_171 . V_165 ) )
memcpy ( V_163 -> V_189 , V_171 . V_165 , V_166 ) ;
if ( F_121 ( V_13 -> V_147 ) )
F_139 ( V_13 ) ;
} else {
F_134 ( V_21 , V_10 , V_1 ,
V_190 , V_163 -> V_189 ) ;
if ( V_10 ) {
F_38 ( V_13 , L_12 , V_21 ) ;
memcpy ( V_163 , & V_171 , sizeof( * V_163 ) ) ;
return F_135 ( V_10 ) ;
}
}
V_10 = F_140 ( V_1 , V_21 , & V_171 , & V_172 ) ;
if ( V_10 ) {
if ( V_172 ) {
memcpy ( V_163 , & V_171 , sizeof( * V_163 ) ) ;
} else {
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
if ( V_21 == V_164 )
F_141 ( V_13 -> V_147 ) ;
}
} else {
V_163 -> V_175 |= V_191 ;
if ( V_163 -> V_177 == V_192 ) {
F_141 ( V_163 -> V_189 ) ;
if ( V_21 == V_164 )
F_141 ( V_13 -> V_147 ) ;
}
}
if ( V_21 == V_164 )
F_141 ( V_163 -> V_165 ) ;
return V_10 ;
}
static int F_142 ( struct V_46 * V_13 , int V_21 ,
struct V_66 * V_67 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
T_2 V_193 = V_194 ;
struct V_162 * V_163 ;
int V_10 ;
F_133 ( V_1 , V_21 , V_163 , & V_10 ) ;
if ( V_10 )
return V_10 ;
if ( ! ( V_163 -> V_175 & V_191 ) )
return - V_195 ;
V_10 = F_143 ( V_1 , V_21 , V_163 -> V_177 , & V_193 ) ;
if ( V_10 )
return V_10 ;
if ( F_144 ( V_67 , V_173 , V_163 -> V_177 ) ||
F_144 ( V_67 , V_196 , V_193 ) ||
( ( V_163 -> V_175 & V_179 ) &&
F_145 ( V_67 , V_178 , V_181 , V_163 -> V_180 ) ) ||
( ( V_163 -> V_175 & V_183 ) &&
F_145 ( V_67 , V_182 , V_185 ,
V_163 -> V_184 ) ) ||
( ( V_163 -> V_175 & V_187 ) &&
F_145 ( V_67 , V_186 , V_185 , V_163 -> V_188 ) ) )
goto V_197;
return 0 ;
V_197:
return - V_198 ;
}
static void F_146 ( struct V_199 * V_43 , struct V_200 * V_26 )
{
struct V_1 * V_1 = F_23 ( V_43 -> V_27 ) ;
if ( ! V_26 -> V_32 )
return;
F_24 ( V_1 -> V_3 , V_26 -> V_29 ,
V_26 -> V_30 , V_201 ) ;
F_26 ( V_26 -> V_32 ) ;
V_26 -> V_32 = NULL ;
}
static int F_147 ( struct V_199 * V_43 )
{
struct V_1 * V_1 = F_23 ( V_43 -> V_27 ) ;
struct V_46 * V_13 = V_1 -> V_13 ;
struct V_66 * V_67 ;
unsigned int V_30 = V_13 -> V_45 + V_202 ;
unsigned int V_203 = 0 ;
T_6 V_29 ;
struct V_200 * V_26 = V_43 -> V_96 ;
if ( V_26 -> V_32 ) {
F_148 ( V_43 , V_26 -> V_32 , V_203 , V_26 -> V_29 ,
V_26 -> V_30 ) ;
return 0 ;
}
V_67 = F_149 ( V_13 , V_30 ) ;
if ( ! V_67 )
return - V_73 ;
V_29 = F_80 ( V_1 -> V_3 , V_67 -> V_54 , V_30 ,
V_201 ) ;
if ( F_75 ( F_76 ( V_1 , V_29 ) ) ) {
F_99 ( V_67 ) ;
return - V_73 ;
}
F_148 ( V_43 , V_67 , V_203 ,
V_29 , V_30 ) ;
return 0 ;
}
static void F_150 ( struct V_204 * V_205 ,
T_3 V_206 )
{
if ( V_207 <= V_206 )
V_205 -> V_208 += V_206 ;
else
V_205 -> V_209 += V_206 ;
}
static bool F_151 ( struct V_46 * V_13 , struct V_66 * * V_67 ,
struct V_200 * V_26 , T_2 V_30 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_66 * V_210 ;
if ( V_30 > V_1 -> V_211 )
return false ;
V_210 = F_149 ( V_13 , V_30 ) ;
if ( ! V_210 )
return false ;
F_152 ( V_1 -> V_3 , V_26 -> V_29 , V_30 ,
V_212 ) ;
memcpy ( V_210 -> V_54 , ( * V_67 ) -> V_54 , V_30 ) ;
* V_67 = V_210 ;
return true ;
}
static void F_153 ( struct V_199 * V_43 ,
struct V_33 * V_33 , struct V_200 * V_26 ,
int V_213 , void * V_34 )
{
struct V_1 * V_1 = F_23 ( V_43 -> V_27 ) ;
struct V_46 * V_13 = V_1 -> V_13 ;
struct V_66 * V_67 ;
struct V_214 * V_215 = & V_1 -> V_215 [ F_154 ( V_1 , V_43 -> V_216 ) ] ;
T_1 type , V_217 , V_77 , V_28 , V_218 , V_219 ;
T_1 V_220 , V_221 , V_222 , V_223 , V_224 ;
T_1 V_225 , V_226 , V_227 , V_228 ;
T_1 V_229 , V_230 , V_231 , V_232 , V_233 , V_234 ;
T_1 V_235 ;
T_2 V_36 , V_37 , V_236 , V_237 , V_238 ;
T_3 V_239 ;
if ( V_213 )
return;
V_67 = V_26 -> V_32 ;
F_155 ( (struct V_240 * ) V_33 ,
& type , & V_217 , & V_36 , & V_37 ,
& V_218 , & V_220 , & V_77 , & V_28 , & V_233 ,
& V_234 , & V_239 , & V_236 ,
& V_235 , & V_219 , & V_237 , & V_238 ,
& V_221 , & V_222 , & V_223 ,
& V_224 , & V_225 , & V_226 , & V_227 ,
& V_228 , & V_229 , & V_230 , & V_231 ,
& V_232 ) ;
if ( V_235 ) {
if ( ! V_232 ) {
if ( V_236 > 0 )
V_1 -> V_133 ++ ;
else if ( V_236 == 0 )
V_1 -> V_131 ++ ;
}
F_24 ( V_1 -> V_3 , V_26 -> V_29 , V_26 -> V_30 ,
V_201 ) ;
F_26 ( V_67 ) ;
V_26 -> V_32 = NULL ;
return;
}
if ( V_77 && V_236 > 0 ) {
if ( ! F_151 ( V_13 , & V_67 , V_26 , V_236 ) ) {
V_26 -> V_32 = NULL ;
F_24 ( V_1 -> V_3 , V_26 -> V_29 , V_26 -> V_30 ,
V_201 ) ;
}
F_156 ( V_67 -> V_54 - V_241 ) ;
F_157 ( V_67 , V_236 ) ;
V_67 -> V_83 = F_158 ( V_67 , V_13 ) ;
F_159 ( V_67 , V_36 ) ;
if ( V_13 -> V_242 & V_243 ) {
F_160 ( V_67 , V_239 ,
( V_233 &
( V_244 |
V_245 |
V_246 ) ) ?
V_247 : V_248 ) ;
}
if ( ( V_13 -> V_242 & V_249 ) && V_225 &&
V_228 )
V_67 -> V_94 = V_250 ;
if ( V_219 )
F_161 ( V_67 , F_162 ( V_251 ) , V_237 ) ;
F_163 ( V_67 , & V_1 -> V_64 [ V_43 -> V_216 ] ) ;
if ( F_164 ( V_43 ) ||
! ( V_13 -> V_242 & V_252 ) )
F_165 ( V_67 ) ;
else
F_166 ( & V_1 -> V_64 [ V_36 ] , V_67 ) ;
if ( V_1 -> V_253 . V_254 )
F_150 ( & V_215 -> V_255 ,
V_236 ) ;
} else {
F_24 ( V_1 -> V_3 , V_26 -> V_29 , V_26 -> V_30 ,
V_201 ) ;
F_26 ( V_67 ) ;
V_26 -> V_32 = NULL ;
}
}
static int F_167 ( struct V_35 * V_27 , struct V_33 * V_33 ,
T_1 type , T_2 V_36 , T_2 V_37 , void * V_34 )
{
struct V_1 * V_1 = F_23 ( V_27 ) ;
F_168 ( & V_1 -> V_43 [ V_36 ] , V_33 ,
V_37 , V_256 ,
F_153 , V_34 ) ;
return 0 ;
}
static void F_169 ( struct V_1 * V_1 , struct V_199 * V_43 )
{
unsigned int V_59 = F_170 ( V_1 , V_43 -> V_216 ) ;
struct V_214 * V_215 = & V_1 -> V_215 [ F_154 ( V_1 , V_43 -> V_216 ) ] ;
T_3 V_257 = V_215 -> V_258 ;
if ( V_215 -> V_258 != V_215 -> V_259 ) {
F_171 ( & V_1 -> V_59 [ V_59 ] , V_257 ) ;
V_215 -> V_259 = V_215 -> V_258 ;
}
}
static void F_172 ( struct V_1 * V_1 , struct V_199 * V_43 )
{
struct V_260 * V_261 = & V_1 -> V_253 ;
struct V_214 * V_215 = & V_1 -> V_215 [ F_154 ( V_1 , V_43 -> V_216 ) ] ;
struct V_204 * V_255 = & V_215 -> V_255 ;
int V_216 ;
T_3 V_257 ;
T_3 V_262 ;
T_3 V_263 ;
T_8 V_264 ;
T_9 V_265 = F_173 () ;
V_264 = F_174 ( V_265 , V_215 -> V_266 ) ;
if ( V_264 < V_267 )
return;
V_215 -> V_266 = V_265 ;
V_263 = V_255 -> V_208 +
V_255 -> V_209 ;
V_263 <<= 3 ;
V_263 = V_264 > V_268 ? 0 : V_263 / ( T_3 ) V_264 ;
for ( V_216 = 0 ; V_216 < V_269 ; V_216 ++ )
if ( V_263 < V_270 [ V_216 ] . V_271 )
break;
V_262 = ( V_255 -> V_209 >
V_255 -> V_208 << 1 ) ?
V_261 -> V_272 :
V_261 -> V_273 ;
V_257 = V_262 + ( ( V_261 -> V_274 - V_262 ) *
V_270 [ V_216 ] . V_275 / 100 ) ;
V_215 -> V_258 = ( V_257 + V_215 -> V_258 ) >> 1 ;
V_255 -> V_208 = 0 ;
V_255 -> V_209 = 0 ;
}
static int F_175 ( struct V_65 * V_64 , int V_276 )
{
struct V_46 * V_13 = V_64 -> V_4 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_277 = F_154 ( V_1 , 0 ) ;
unsigned int V_278 = F_176 ( V_1 , 0 ) ;
unsigned int V_59 = F_56 () ;
unsigned int V_279 = V_276 ;
unsigned int V_280 = - 1 ;
unsigned int V_281 , V_282 = 0 , V_283 ;
int V_10 ;
V_283 = F_177 ( & V_1 -> V_215 [ V_278 ] , V_280 ,
F_28 , NULL ) ;
if ( ! F_178 ( & V_1 -> V_43 [ V_277 ] ) ) {
if ( V_283 > 0 )
F_179 ( & V_1 -> V_59 [ V_59 ] ,
V_283 ,
0 ,
0 ) ;
return V_276 ;
}
if ( V_276 > 0 )
V_282 = F_177 ( & V_1 -> V_215 [ V_277 ] ,
V_279 , F_167 , NULL ) ;
V_281 = V_282 + V_283 ;
if ( V_281 > 0 )
F_179 ( & V_1 -> V_59 [ V_59 ] ,
V_281 ,
0 ,
0 ) ;
V_10 = F_180 ( & V_1 -> V_43 [ 0 ] , F_147 ) ;
F_181 ( & V_1 -> V_43 [ V_277 ] , V_64 ) ;
if ( V_10 )
V_282 = V_279 ;
if ( V_1 -> V_253 . V_254 )
F_172 ( V_1 , & V_1 -> V_43 [ 0 ] ) ;
if ( V_282 < V_279 ) {
F_182 ( V_64 ) ;
if ( V_1 -> V_253 . V_254 )
F_169 ( V_1 , & V_1 -> V_43 [ 0 ] ) ;
F_61 ( & V_1 -> V_59 [ V_59 ] ) ;
}
return V_282 ;
}
static void F_183 ( struct V_1 * V_1 )
{
F_184 ( V_1 -> V_13 -> V_284 ) ;
V_1 -> V_13 -> V_284 = NULL ;
}
static void F_185 ( struct V_1 * V_1 )
{
int V_5 , V_285 ;
if ( F_186 ( V_1 -> V_27 ) == V_286 ) {
V_1 -> V_13 -> V_284 = F_187 ( V_1 -> V_42 ) ;
if ( F_75 ( ! V_1 -> V_13 -> V_284 ) )
return;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
V_285 = F_188 ( V_1 -> V_13 -> V_284 ,
V_1 -> V_11 [ V_5 ] . V_12 ) ;
if ( F_75 ( V_285 ) ) {
F_183 ( V_1 ) ;
return;
}
}
}
}
static void F_183 ( struct V_1 * V_1 )
{
}
static void F_185 ( struct V_1 * V_1 )
{
}
static int F_189 ( struct V_65 * V_64 )
{
struct V_46 * V_13 = V_64 -> V_4 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_43 = ( V_64 - & V_1 -> V_64 [ 0 ] ) ;
unsigned int V_215 = F_154 ( V_1 , V_43 ) ;
unsigned int V_59 = F_170 ( V_1 , V_43 ) ;
unsigned int V_287 = - 1 ;
unsigned int V_281 ;
if ( ! F_190 ( & V_1 -> V_43 [ V_43 ] ) )
return V_288 ;
V_281 = F_177 ( & V_1 -> V_215 [ V_215 ] , V_287 ,
F_167 , NULL ) ;
if ( V_281 > 0 )
F_179 ( & V_1 -> V_59 [ V_59 ] ,
V_281 , 0 , 0 ) ;
F_180 ( & V_1 -> V_43 [ V_43 ] , F_147 ) ;
if ( V_1 -> V_253 . V_254 )
F_172 ( V_1 , & V_1 -> V_43 [ V_43 ] ) ;
F_191 ( & V_1 -> V_43 [ V_43 ] ) ;
return V_281 ;
}
static int F_192 ( struct V_65 * V_64 , int V_276 )
{
struct V_46 * V_13 = V_64 -> V_4 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_289 = ( V_64 - & V_1 -> V_64 [ 0 ] ) - V_1 -> V_42 ;
struct V_23 * V_24 = & V_1 -> V_24 [ V_289 ] ;
unsigned int V_215 ;
unsigned int V_59 ;
unsigned int V_280 = - 1 ;
unsigned int V_283 ;
unsigned int V_290 ;
V_290 = V_24 -> V_216 ;
V_215 = F_176 ( V_1 , V_290 ) ;
V_59 = F_14 ( V_1 , V_290 ) ;
V_283 = F_177 ( & V_1 -> V_215 [ V_215 ] , V_280 ,
F_28 , NULL ) ;
F_179 ( & V_1 -> V_59 [ V_59 ] , V_283 ,
0 ,
1 ) ;
if ( ! V_283 ) {
F_182 ( V_64 ) ;
F_61 ( & V_1 -> V_59 [ V_59 ] ) ;
return 0 ;
}
return V_276 ;
}
static int F_193 ( struct V_65 * V_64 , int V_276 )
{
struct V_46 * V_13 = V_64 -> V_4 ;
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_43 = ( V_64 - & V_1 -> V_64 [ 0 ] ) ;
unsigned int V_215 = F_154 ( V_1 , V_43 ) ;
unsigned int V_59 = F_170 ( V_1 , V_43 ) ;
unsigned int V_287 = V_276 ;
unsigned int V_281 = 0 ;
int V_10 ;
if ( ! F_178 ( & V_1 -> V_43 [ V_43 ] ) )
return V_276 ;
if ( V_276 > 0 )
V_281 = F_177 ( & V_1 -> V_215 [ V_215 ] ,
V_287 , F_167 , NULL ) ;
if ( V_281 > 0 )
F_179 ( & V_1 -> V_59 [ V_59 ] ,
V_281 ,
0 ,
0 ) ;
V_10 = F_180 ( & V_1 -> V_43 [ V_43 ] , F_147 ) ;
if ( V_10 )
V_281 = V_287 ;
if ( V_1 -> V_253 . V_254 )
F_172 ( V_1 , & V_1 -> V_43 [ V_43 ] ) ;
F_181 ( & V_1 -> V_43 [ V_43 ] , V_64 ) ;
if ( V_281 < V_287 ) {
F_182 ( V_64 ) ;
if ( V_1 -> V_253 . V_254 )
F_169 ( V_1 , & V_1 -> V_43 [ V_43 ] ) ;
F_61 ( & V_1 -> V_59 [ V_59 ] ) ;
}
return V_281 ;
}
static void F_194 ( unsigned long V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_54 ;
F_53 ( V_1 ) ;
F_195 ( & V_1 -> V_291 ,
F_196 ( V_292 + V_293 ) ) ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_46 * V_13 = V_1 -> V_13 ;
unsigned int V_5 ;
F_183 ( V_1 ) ;
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_294 :
F_198 ( V_1 -> V_3 -> V_53 , V_13 ) ;
break;
case V_295 :
F_198 ( V_1 -> V_3 -> V_53 , V_1 ) ;
break;
case V_286 :
for ( V_5 = 0 ; V_5 < F_199 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_1 -> V_7 [ V_5 ] . V_296 )
F_198 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_297 ) ;
break;
default:
break;
}
}
static int F_200 ( struct V_1 * V_1 )
{
struct V_46 * V_13 = V_1 -> V_13 ;
unsigned int V_5 , V_59 ;
int V_10 = 0 ;
F_185 ( V_1 ) ;
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_294 :
V_10 = F_201 ( V_1 -> V_3 -> V_53 , F_54 ,
V_298 , V_13 -> V_180 , V_13 ) ;
break;
case V_295 :
V_10 = F_201 ( V_1 -> V_3 -> V_53 , F_65 ,
0 , V_13 -> V_180 , V_1 ) ;
break;
case V_286 :
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
V_59 = F_170 ( V_1 , V_5 ) ;
snprintf ( V_1 -> V_7 [ V_59 ] . V_299 ,
sizeof( V_1 -> V_7 [ V_59 ] . V_299 ) ,
L_13 , V_13 -> V_180 , V_5 ) ;
V_1 -> V_7 [ V_59 ] . V_300 = F_66 ;
V_1 -> V_7 [ V_59 ] . V_297 = & V_1 -> V_64 [ V_5 ] ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
int V_24 = F_176 ( V_1 , V_5 ) ;
V_59 = F_14 ( V_1 , V_5 ) ;
snprintf ( V_1 -> V_7 [ V_59 ] . V_299 ,
sizeof( V_1 -> V_7 [ V_59 ] . V_299 ) ,
L_14 , V_13 -> V_180 , V_5 ) ;
V_1 -> V_7 [ V_59 ] . V_300 = F_66 ;
V_1 -> V_7 [ V_59 ] . V_297 = & V_1 -> V_64 [ V_24 ] ;
}
V_59 = F_68 ( V_1 ) ;
snprintf ( V_1 -> V_7 [ V_59 ] . V_299 ,
sizeof( V_1 -> V_7 [ V_59 ] . V_299 ) ,
L_15 , V_13 -> V_180 ) ;
V_1 -> V_7 [ V_59 ] . V_300 = F_67 ;
V_1 -> V_7 [ V_59 ] . V_297 = V_1 ;
V_59 = F_70 ( V_1 ) ;
snprintf ( V_1 -> V_7 [ V_59 ] . V_299 ,
sizeof( V_1 -> V_7 [ V_59 ] . V_299 ) ,
L_16 , V_13 -> V_180 ) ;
V_1 -> V_7 [ V_59 ] . V_300 = F_69 ;
V_1 -> V_7 [ V_59 ] . V_297 = V_1 ;
for ( V_5 = 0 ; V_5 < F_199 ( V_1 -> V_7 ) ; V_5 ++ )
V_1 -> V_7 [ V_5 ] . V_296 = 0 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
V_10 = F_201 ( V_1 -> V_11 [ V_5 ] . V_12 ,
V_1 -> V_7 [ V_5 ] . V_300 , 0 ,
V_1 -> V_7 [ V_5 ] . V_299 ,
V_1 -> V_7 [ V_5 ] . V_297 ) ;
if ( V_10 ) {
F_197 ( V_1 ) ;
break;
}
V_1 -> V_7 [ V_5 ] . V_296 = 1 ;
}
break;
default:
break;
}
return V_10 ;
}
static void F_202 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_294 :
case V_295 :
F_203 ( V_1 -> V_3 -> V_53 ) ;
break;
case V_286 :
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_203 ( V_1 -> V_11 [ V_5 ] . V_12 ) ;
break;
default:
break;
}
}
static void F_204 ( struct V_1 * V_1 )
{
unsigned int V_301 ;
int V_216 = - 1 ;
struct V_260 * V_261 = & V_1 -> V_253 ;
V_301 = F_205 ( V_1 -> V_27 ) ;
if ( V_302 < V_301 )
V_216 = V_303 ;
else if ( V_304 < V_301 )
V_216 = V_305 ;
else
V_216 = V_306 ;
V_261 -> V_272 = V_307 [ V_216 ] . V_272 ;
V_261 -> V_273 = V_307 [ V_216 ] . V_273 ;
V_261 -> V_274 = V_308 ;
for ( V_216 = 0 ; V_216 < V_1 -> V_42 ; V_216 ++ )
V_1 -> V_215 [ V_216 ] . V_259 =
V_1 -> V_309 . V_310 ;
V_261 -> V_254 = 1 ;
}
static int F_206 ( struct V_1 * V_1 )
{
int V_10 ;
F_207 ( & V_1 -> V_311 ) ;
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_294 :
V_10 = F_208 ( V_1 -> V_27 ,
F_58 () ) ;
break;
case V_286 :
V_10 = F_208 ( V_1 -> V_27 ,
F_70 ( V_1 ) ) ;
break;
default:
V_10 = F_208 ( V_1 -> V_27 , - 1 ) ;
break;
}
F_209 ( & V_1 -> V_311 ) ;
return V_10 ;
}
static void F_210 ( struct V_1 * V_1 )
{
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_295 :
F_195 ( & V_1 -> V_291 , V_292 ) ;
break;
default:
break;
}
}
static int F_211 ( struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_5 ;
int V_10 ;
V_10 = F_200 ( V_1 ) ;
if ( V_10 ) {
F_38 ( V_13 , L_17 ) ;
return V_10 ;
}
F_1 ( V_1 ) ;
F_11 ( V_1 ) ;
V_10 = F_206 ( V_1 ) ;
if ( V_10 ) {
F_38 ( V_13 ,
L_18 ) ;
goto V_312;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
F_180 ( & V_1 -> V_43 [ V_5 ] , F_147 ) ;
if ( F_212 ( & V_1 -> V_43 [ V_5 ] ) == 0 ) {
F_38 ( V_13 , L_19 ) ;
V_10 = - V_73 ;
goto V_313;
}
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_213 ( & V_1 -> V_24 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ )
F_214 ( & V_1 -> V_43 [ V_5 ] ) ;
if ( ! F_17 ( V_1 ) && ! F_19 ( V_1 ) )
F_125 ( V_1 ) ;
F_127 ( V_13 ) ;
F_215 ( V_13 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
F_216 ( & V_1 -> V_43 [ V_5 ] ) ;
F_217 ( & V_1 -> V_64 [ V_5 ] ) ;
}
if ( F_186 ( V_1 -> V_27 ) == V_286 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_217 ( & V_1 -> V_64 [ F_176 ( V_1 , V_5 ) ] ) ;
F_218 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_61 ( & V_1 -> V_59 [ V_5 ] ) ;
F_210 ( V_1 ) ;
F_219 ( V_1 ) ;
return 0 ;
V_313:
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ )
F_220 ( & V_1 -> V_43 [ V_5 ] , F_146 ) ;
F_221 ( V_1 ) ;
V_312:
F_16 ( V_1 ) ;
F_197 ( V_1 ) ;
return V_10 ;
}
static int F_222 ( struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
unsigned int V_5 ;
int V_10 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ ) {
F_59 ( & V_1 -> V_59 [ V_5 ] ) ;
( void ) F_223 ( & V_1 -> V_59 [ V_5 ] ) ;
}
F_202 ( V_1 ) ;
F_224 ( & V_1 -> V_291 ) ;
F_225 ( V_1 ) ;
F_226 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
F_227 ( & V_1 -> V_64 [ V_5 ] ) ;
F_228 () ;
while ( ! F_178 ( & V_1 -> V_43 [ V_5 ] ) )
F_229 ( 1 ) ;
F_230 () ;
}
F_52 ( V_13 ) ;
F_231 ( V_13 ) ;
if ( F_186 ( V_1 -> V_27 ) == V_286 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_227 ( & V_1 -> V_64 [ F_176 ( V_1 , V_5 ) ] ) ;
if ( ! F_17 ( V_1 ) && ! F_19 ( V_1 ) )
F_124 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_10 = F_232 ( & V_1 -> V_24 [ V_5 ] ) ;
if ( V_10 )
return V_10 ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
V_10 = F_233 ( & V_1 -> V_43 [ V_5 ] ) ;
if ( V_10 )
return V_10 ;
}
F_221 ( V_1 ) ;
F_16 ( V_1 ) ;
F_197 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_234 ( & V_1 -> V_24 [ V_5 ] , F_22 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ )
F_220 ( & V_1 -> V_43 [ V_5 ] , F_146 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_314 ; V_5 ++ )
F_235 ( & V_1 -> V_215 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_6 ; V_5 ++ )
F_236 ( & V_1 -> V_59 [ V_5 ] ) ;
return 0 ;
}
static int F_237 ( struct V_46 * V_13 , int V_315 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
int V_316 = F_123 ( V_13 ) ;
if ( V_315 < V_48 || V_315 > V_49 )
return - V_168 ;
if ( F_17 ( V_1 ) || F_19 ( V_1 ) )
return - V_174 ;
if ( V_316 )
F_222 ( V_13 ) ;
V_13 -> V_45 = V_315 ;
if ( V_13 -> V_45 > V_1 -> V_47 )
F_13 ( V_13 ,
L_20 ,
V_13 -> V_45 , V_1 -> V_47 ) ;
if ( V_316 )
F_211 ( V_13 ) ;
return 0 ;
}
static void F_238 ( struct V_317 * V_318 )
{
struct V_1 * V_1 = F_239 ( V_318 , struct V_1 , V_50 ) ;
struct V_46 * V_13 = V_1 -> V_13 ;
int V_315 = F_44 ( V_1 -> V_27 ) ;
int V_10 ;
unsigned int V_5 ;
V_315 = F_45 ( int , V_48 , F_46 ( int , V_49 , V_315 ) ) ;
F_240 () ;
F_224 ( & V_1 -> V_291 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ )
F_227 ( & V_1 -> V_64 [ V_5 ] ) ;
F_59 ( & V_1 -> V_59 [ 0 ] ) ;
F_202 ( V_1 ) ;
V_10 = F_233 ( & V_1 -> V_43 [ 0 ] ) ;
if ( V_10 ) {
F_241 () ;
F_38 ( V_13 , L_21 ) ;
return;
}
F_220 ( & V_1 -> V_43 [ 0 ] , F_146 ) ;
F_235 ( & V_1 -> V_215 [ 0 ] ) ;
F_236 ( & V_1 -> V_59 [ 0 ] ) ;
V_13 -> V_45 = V_315 ;
F_180 ( & V_1 -> V_43 [ 0 ] , F_147 ) ;
if ( F_212 ( & V_1 -> V_43 [ 0 ] ) == 0 ) {
F_241 () ;
F_38 ( V_13 , L_22 ) ;
return;
}
F_214 ( & V_1 -> V_43 [ 0 ] ) ;
F_217 ( & V_1 -> V_64 [ 0 ] ) ;
F_61 ( & V_1 -> V_59 [ 0 ] ) ;
F_210 ( V_1 ) ;
F_241 () ;
F_42 ( V_13 , L_23 , V_13 -> V_45 ) ;
}
static void F_242 ( struct V_46 * V_13 )
{
struct V_1 * V_1 = F_55 ( V_13 ) ;
struct V_35 * V_27 = V_1 -> V_27 ;
unsigned int V_5 , V_59 ;
switch ( F_186 ( V_27 ) ) {
case V_286 :
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
V_59 = F_170 ( V_1 , V_5 ) ;
F_66 ( V_1 -> V_11 [ V_59 ] . V_12 ,
& V_1 -> V_64 [ V_5 ] ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ ) {
V_59 = F_14 ( V_1 , V_5 ) ;
F_66 ( V_1 -> V_11 [ V_59 ] . V_12 ,
& V_1 -> V_64 [ F_176 ( V_1 , V_5 ) ] ) ;
}
break;
case V_295 :
F_65 ( V_1 -> V_3 -> V_53 , V_1 ) ;
break;
case V_294 :
F_54 ( V_1 -> V_3 -> V_53 , V_13 ) ;
break;
default:
break;
}
}
static int F_243 ( struct V_35 * V_27 ,
int (* F_244)( struct V_35 * , int ) ,
int (* F_245)( struct V_35 * , int * ) ,
int V_319 )
{
unsigned long time ;
int V_320 ;
int V_10 ;
F_246 ( F_247 () ) ;
V_10 = F_244 ( V_27 , V_319 ) ;
if ( V_10 )
return V_10 ;
time = V_292 + ( V_321 * 2 ) ;
do {
V_10 = F_245 ( V_27 , & V_320 ) ;
if ( V_10 )
return V_10 ;
if ( V_320 )
return 0 ;
F_248 ( V_321 / 10 ) ;
} while ( F_249 ( time , V_292 ) );
return - V_322 ;
}
static int F_250 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_243 ( V_1 -> V_27 , V_323 ,
V_324 , 0 ) ;
if ( V_10 )
F_251 ( F_252 ( V_1 ) , L_24 ,
V_10 ) ;
return V_10 ;
}
static int F_253 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_243 ( V_1 -> V_27 , V_325 ,
V_326 , 0 ) ;
if ( V_10 )
F_38 ( V_1 -> V_13 , L_25 ,
V_10 ) ;
return V_10 ;
}
static int F_254 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_243 ( V_1 -> V_27 , V_327 ,
V_328 , 0 ) ;
if ( V_10 )
F_38 ( V_1 -> V_13 , L_26 ,
V_10 ) ;
return V_10 ;
}
int F_255 ( struct V_1 * V_1 )
{
union V_329 * V_330 ;
T_6 V_331 ;
int V_5 , V_332 , V_333 , V_10 ;
V_330 = F_256 ( V_1 -> V_3 ,
sizeof( union V_329 ) ,
& V_331 ) ;
if ( ! V_330 )
return - V_73 ;
for ( V_5 = 0 ; V_5 < V_334 ; V_5 ++ ) {
V_332 = V_5 / V_335 ;
V_333 = V_5 % V_335 ;
V_330 -> V_336 [ V_332 ] . V_337 [ V_333 ] = V_1 -> V_338 [ V_5 ] ;
}
F_207 ( & V_1 -> V_311 ) ;
V_10 = F_257 ( V_1 ,
V_331 ,
sizeof( union V_329 ) ) ;
F_209 ( & V_1 -> V_311 ) ;
F_258 ( V_1 -> V_3 , sizeof( union V_329 ) ,
V_330 , V_331 ) ;
return V_10 ;
}
static int F_259 ( struct V_1 * V_1 )
{
F_260 ( V_1 -> V_338 , V_334 ) ;
return F_255 ( V_1 ) ;
}
static int F_261 ( struct V_1 * V_1 , T_1 V_339 )
{
T_6 V_340 ;
union V_341 * V_342 = NULL ;
unsigned int V_5 ;
int V_10 ;
V_342 = F_262 ( V_1 -> V_3 ,
sizeof( union V_341 ) , & V_340 ) ;
if ( ! V_342 )
return - V_73 ;
for ( V_5 = 0 ; V_5 < ( 1 << V_339 ) ; V_5 ++ )
( * V_342 ) . V_343 [ V_5 / 4 ] . V_337 [ V_5 % 4 ] = V_5 % V_1 -> V_42 ;
F_207 ( & V_1 -> V_311 ) ;
V_10 = F_263 ( V_1 ,
V_340 ,
sizeof( union V_341 ) ) ;
F_209 ( & V_1 -> V_311 ) ;
F_258 ( V_1 -> V_3 , sizeof( union V_341 ) ,
V_342 , V_340 ) ;
return V_10 ;
}
static int F_264 ( struct V_1 * V_1 , T_1 V_344 ,
T_1 V_345 , T_1 V_339 , T_1 V_346 , T_1 V_347 )
{
const T_1 V_348 = 0 ;
const T_1 V_349 = 1 ;
int V_10 ;
F_207 ( & V_1 -> V_311 ) ;
V_10 = F_265 ( V_1 ,
V_344 , V_345 ,
V_339 , V_346 ,
V_347 , V_348 ,
V_349 ) ;
F_209 ( & V_1 -> V_311 ) ;
return V_10 ;
}
static int F_266 ( struct V_1 * V_1 )
{
struct V_16 * V_4 = F_252 ( V_1 ) ;
const T_1 V_344 = 0 ;
const T_1 V_345 = V_350 |
V_246 |
V_351 |
V_245 ;
const T_1 V_339 = 7 ;
const T_1 V_346 = 0 ;
T_1 V_347 = F_267 ( V_1 , V_352 ) && ( V_1 -> V_42 > 1 ) ;
if ( V_347 ) {
if ( ! F_259 ( V_1 ) ) {
if ( F_261 ( V_1 , V_339 ) ) {
V_347 = 0 ;
F_268 ( V_4 , L_27
L_28 ) ;
}
} else {
V_347 = 0 ;
F_268 ( V_4 , L_29 ) ;
}
}
return F_264 ( V_1 , V_344 , V_345 ,
V_339 , V_346 , V_347 ) ;
}
static void F_269 ( struct V_317 * V_318 )
{
struct V_1 * V_1 = F_239 ( V_318 , struct V_1 , V_62 ) ;
if ( ! F_123 ( V_1 -> V_13 ) )
return;
F_240 () ;
F_29 ( & V_1 -> V_353 ) ;
F_222 ( V_1 -> V_13 ) ;
F_253 ( V_1 ) ;
F_116 ( V_1 ) ;
F_270 ( V_1 ) ;
F_266 ( V_1 ) ;
F_271 ( V_1 ) ;
F_211 ( V_1 -> V_13 ) ;
F_35 ( & V_1 -> V_353 ) ;
F_272 ( V_354 , V_1 -> V_13 ) ;
F_241 () ;
}
static void F_273 ( struct V_317 * V_318 )
{
struct V_1 * V_1 = F_239 ( V_318 , struct V_1 , V_160 ) ;
F_240 () ;
F_29 ( & V_1 -> V_353 ) ;
F_274 ( V_1 ) ;
F_222 ( V_1 -> V_13 ) ;
F_254 ( V_1 ) ;
F_116 ( V_1 ) ;
F_270 ( V_1 ) ;
F_266 ( V_1 ) ;
F_271 ( V_1 ) ;
F_211 ( V_1 -> V_13 ) ;
F_35 ( & V_1 -> V_353 ) ;
F_272 ( V_354 , V_1 -> V_13 ) ;
F_241 () ;
}
static int F_275 ( struct V_1 * V_1 )
{
unsigned int V_355 = F_46 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_356 = F_46 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_5 ;
F_246 ( F_199 ( V_1 -> V_11 ) < V_355 + V_356 + 2 ) ;
for ( V_5 = 0 ; V_5 < V_355 + V_356 + 2 ; V_5 ++ )
V_1 -> V_11 [ V_5 ] . V_357 = V_5 ;
if ( F_267 ( V_1 , V_352 ) &&
V_1 -> V_309 . V_358 < 1 &&
V_1 -> V_42 >= V_355 &&
V_1 -> V_14 >= V_356 &&
V_1 -> V_314 >= V_355 + V_356 &&
V_1 -> V_6 >= V_355 + V_356 + 2 ) {
if ( F_276 ( V_1 -> V_3 , V_1 -> V_11 ,
V_355 + V_356 + 2 , V_355 + V_356 + 2 ) > 0 ) {
V_1 -> V_42 = V_355 ;
V_1 -> V_14 = V_356 ;
V_1 -> V_314 = V_355 + V_356 ;
V_1 -> V_6 = V_355 + V_356 + 2 ;
F_277 ( V_1 -> V_27 ,
V_286 ) ;
return 0 ;
}
}
if ( V_1 -> V_309 . V_358 < 1 &&
V_1 -> V_42 >= 1 &&
V_1 -> V_14 >= V_356 &&
V_1 -> V_314 >= 1 + V_356 &&
V_1 -> V_6 >= 1 + V_356 + 2 ) {
if ( F_276 ( V_1 -> V_3 , V_1 -> V_11 ,
1 + V_356 + 2 , 1 + V_356 + 2 ) > 0 ) {
V_1 -> V_42 = 1 ;
V_1 -> V_14 = V_356 ;
V_1 -> V_314 = 1 + V_356 ;
V_1 -> V_6 = 1 + V_356 + 2 ;
F_277 ( V_1 -> V_27 ,
V_286 ) ;
return 0 ;
}
}
if ( V_1 -> V_309 . V_358 < 2 &&
V_1 -> V_42 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_314 >= 2 &&
V_1 -> V_6 >= 1 &&
! F_278 ( V_1 -> V_3 ) ) {
V_1 -> V_42 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_314 = 2 ;
V_1 -> V_6 = 1 ;
F_277 ( V_1 -> V_27 , V_295 ) ;
return 0 ;
}
if ( V_1 -> V_309 . V_358 < 3 &&
V_1 -> V_42 >= 1 &&
V_1 -> V_14 >= 1 &&
V_1 -> V_314 >= 2 &&
V_1 -> V_6 >= 3 ) {
V_1 -> V_42 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_314 = 2 ;
V_1 -> V_6 = 3 ;
F_277 ( V_1 -> V_27 , V_294 ) ;
return 0 ;
}
F_277 ( V_1 -> V_27 , V_359 ) ;
return - V_168 ;
}
static void F_279 ( struct V_1 * V_1 )
{
switch ( F_186 ( V_1 -> V_27 ) ) {
case V_286 :
F_280 ( V_1 -> V_3 ) ;
break;
case V_295 :
F_281 ( V_1 -> V_3 ) ;
break;
default:
break;
}
F_277 ( V_1 -> V_27 , V_359 ) ;
}
static void F_282 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
F_283 ( & V_1 -> V_64 [ V_5 ] ) ;
F_284 ( & V_1 -> V_64 [ V_5 ] ) ;
}
if ( F_186 ( V_1 -> V_27 ) == V_286 )
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_284 ( & V_1 -> V_64 [ F_176 ( V_1 , V_5 ) ] ) ;
F_285 ( V_1 ) ;
F_279 ( V_1 ) ;
F_9 ( V_1 ) ;
}
static void F_286 ( struct V_1 * V_1 )
{
if ( F_287 () ) {
F_288 ( F_252 ( V_1 ) , L_30 ) ;
V_1 -> V_42 = 1 ;
V_1 -> V_14 = 1 ;
V_1 -> V_309 . V_360 = V_361 ;
V_1 -> V_309 . V_362 = V_363 ;
V_1 -> V_309 . V_45 = F_46 ( T_2 , 1500 , V_1 -> V_309 . V_45 ) ;
}
}
static int F_289 ( struct V_1 * V_1 )
{
struct V_16 * V_4 = F_252 ( V_1 ) ;
struct V_46 * V_13 = V_1 -> V_13 ;
unsigned int V_5 ;
int V_10 ;
V_10 = F_290 ( V_1 ) ;
if ( V_10 ) {
F_268 ( V_4 , L_31
L_32 ) ;
F_291 ( V_1 -> V_27 ) ;
}
V_10 = F_292 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_33 ) ;
return V_10 ;
}
F_293 ( V_1 ) ;
F_286 ( V_1 ) ;
V_10 = F_275 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_34
L_35 ) ;
return V_10 ;
}
V_10 = F_294 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_36 ) ;
goto V_364;
}
F_270 ( V_1 ) ;
V_10 = F_266 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_37 ) ;
goto V_364;
}
switch ( F_186 ( V_1 -> V_27 ) ) {
default:
F_295 ( V_13 , & V_1 -> V_64 [ 0 ] , F_175 , 64 ) ;
break;
case V_286 :
for ( V_5 = 0 ; V_5 < V_1 -> V_42 ; V_5 ++ ) {
F_295 ( V_13 , & V_1 -> V_64 [ V_5 ] ,
F_193 , V_365 ) ;
}
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_295 ( V_13 , & V_1 -> V_64 [ F_176 ( V_1 , V_5 ) ] ,
F_192 , V_365 ) ;
break;
}
return 0 ;
V_364:
F_9 ( V_1 ) ;
F_279 ( V_1 ) ;
F_285 ( V_1 ) ;
return V_10 ;
}
static void F_296 ( struct V_1 * V_1 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_199 ( V_1 -> V_366 ) ; V_5 ++ )
if ( V_1 -> V_366 [ V_5 ] . V_367 )
F_297 ( V_1 -> V_366 [ V_5 ] . V_367 ) ;
}
static int F_298 ( struct V_368 * V_3 , const struct V_369 * V_370 )
{
struct V_16 * V_4 = & V_3 -> V_4 ;
struct V_46 * V_13 ;
struct V_1 * V_1 ;
int V_371 = 0 ;
unsigned int V_5 ;
int V_10 ;
#ifdef F_21
int V_372 = 0 ;
#endif
int V_373 = 1 ;
V_13 = F_299 ( sizeof( struct V_1 ) ,
V_374 , V_375 ) ;
if ( ! V_13 )
return - V_73 ;
F_300 ( V_3 , V_13 ) ;
F_301 ( V_13 , & V_3 -> V_4 ) ;
V_1 = F_55 ( V_13 ) ;
V_1 -> V_13 = V_13 ;
V_1 -> V_3 = V_3 ;
V_10 = F_302 ( V_3 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_38 ) ;
goto V_376;
}
V_10 = F_303 ( V_3 , V_377 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_39 ) ;
goto V_378;
}
F_304 ( V_3 ) ;
V_10 = F_305 ( V_3 , F_306 ( 64 ) ) ;
if ( V_10 ) {
V_10 = F_305 ( V_3 , F_306 ( 32 ) ) ;
if ( V_10 ) {
F_251 ( V_4 , L_40 ) ;
goto V_379;
}
V_10 = F_307 ( V_3 , F_306 ( 32 ) ) ;
if ( V_10 ) {
F_251 ( V_4 , L_41
L_42 , 32 ) ;
goto V_379;
}
} else {
V_10 = F_307 ( V_3 , F_306 ( 64 ) ) ;
if ( V_10 ) {
F_251 ( V_4 , L_41
L_42 , 64 ) ;
goto V_379;
}
V_371 = 1 ;
}
for ( V_5 = 0 ; V_5 < F_199 ( V_1 -> V_366 ) ; V_5 ++ ) {
if ( ! ( F_308 ( V_3 , V_5 ) & V_380 ) )
continue;
V_1 -> V_366 [ V_5 ] . V_30 = F_309 ( V_3 , V_5 ) ;
V_1 -> V_366 [ V_5 ] . V_367 = F_310 ( V_3 , V_5 , V_1 -> V_366 [ V_5 ] . V_30 ) ;
if ( ! V_1 -> V_366 [ V_5 ] . V_367 ) {
F_251 ( V_4 , L_43 , V_5 ) ;
V_10 = - V_381 ;
goto V_382;
}
V_1 -> V_366 [ V_5 ] . V_383 = F_311 ( V_3 , V_5 ) ;
}
V_1 -> V_27 = F_312 ( NULL , V_1 , V_3 , V_1 -> V_366 ,
F_199 ( V_1 -> V_366 ) ) ;
if ( ! V_1 -> V_27 ) {
F_251 ( V_4 , L_44 ) ;
V_10 = - V_381 ;
goto V_382;
}
V_10 = F_313 ( V_1 -> V_27 ) ;
if ( V_10 )
goto V_384;
#ifdef F_21
V_372 = F_314 ( V_3 , V_385 ) ;
if ( V_372 ) {
F_315 ( V_3 , V_372 + V_386 ,
& V_1 -> V_22 ) ;
if ( V_1 -> V_22 ) {
V_10 = F_316 ( V_3 , V_1 -> V_22 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_45
L_46 ,
V_10 ) ;
goto V_384;
}
V_1 -> V_18 |= V_19 ;
V_373 = V_1 -> V_22 ;
}
}
#endif
V_1 -> V_163 = F_317 ( V_373 , sizeof( * V_1 -> V_163 ) , V_9 ) ;
if ( ! V_1 -> V_163 ) {
V_10 = - V_73 ;
goto V_387;
}
V_10 = F_250 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_47 ) ;
goto V_388;
}
F_318 ( & V_1 -> V_311 ) ;
F_318 ( & V_1 -> V_353 ) ;
V_10 = F_271 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 ,
L_48 ) ;
goto V_389;
}
F_52 ( V_13 ) ;
if ( ! F_17 ( V_1 ) ) {
V_10 = F_319 ( V_1 -> V_27 , 0 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_49 ) ;
goto V_389;
}
}
V_10 = F_289 ( V_1 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_50 ) ;
goto V_389;
}
F_320 ( V_13 , V_1 -> V_14 ) ;
F_321 ( V_13 , V_1 -> V_42 ) ;
F_322 ( & V_1 -> V_291 ) ;
V_1 -> V_291 . V_390 = F_194 ;
V_1 -> V_291 . V_54 = ( unsigned long ) V_1 ;
F_204 ( V_1 ) ;
F_323 ( & V_1 -> V_62 , F_269 ) ;
F_323 ( & V_1 -> V_160 , F_273 ) ;
F_323 ( & V_1 -> V_50 , F_238 ) ;
for ( V_5 = 0 ; V_5 < V_1 -> V_14 ; V_5 ++ )
F_318 ( & V_1 -> V_38 [ V_5 ] ) ;
V_1 -> V_47 = V_1 -> V_309 . V_45 ;
( void ) F_237 ( V_13 , V_1 -> V_47 ) ;
V_10 = F_119 ( V_13 , V_1 -> V_189 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_51 ) ;
goto V_391;
}
V_1 -> V_392 = V_1 -> V_309 . V_310 ;
V_1 -> V_393 = V_1 -> V_392 ;
if ( F_17 ( V_1 ) || F_19 ( V_1 ) )
V_13 -> V_394 = & V_395 ;
else
V_13 -> V_394 = & V_396 ;
V_13 -> V_397 = 2 * V_321 ;
F_324 ( V_13 ) ;
V_13 -> V_242 |= V_398 | V_399 ;
if ( F_267 ( V_1 , V_400 ) ) {
V_13 -> V_242 &= ~ V_398 ;
V_1 -> V_92 = 1 ;
V_1 -> V_93 = V_1 -> V_309 . V_93 ;
F_288 ( V_4 , L_52 , V_1 -> V_93 ) ;
}
if ( F_267 ( V_1 , V_401 ) )
V_13 -> V_402 |= V_403 | V_404 ;
if ( F_267 ( V_1 , V_405 ) )
V_13 -> V_402 |= V_406 |
V_407 | V_408 ;
if ( F_267 ( V_1 , V_352 ) )
V_13 -> V_402 |= V_243 ;
if ( F_267 ( V_1 , V_409 ) )
V_13 -> V_402 |= V_249 ;
V_13 -> V_242 |= V_13 -> V_402 ;
#ifdef F_325
V_13 -> V_402 |= V_410 ;
#endif
if ( V_371 )
V_13 -> V_242 |= V_411 ;
V_13 -> V_18 |= V_412 ;
V_10 = F_326 ( V_13 ) ;
if ( V_10 ) {
F_251 ( V_4 , L_53 ) ;
goto V_391;
}
V_1 -> V_211 = V_413 ;
return 0 ;
V_391:
F_282 ( V_1 ) ;
V_389:
F_327 ( V_1 -> V_27 ) ;
V_388:
F_328 ( V_1 -> V_163 ) ;
V_387:
#ifdef F_21
if ( F_18 ( V_1 ) ) {
F_329 ( V_3 ) ;
V_1 -> V_18 &= ~ V_19 ;
}
#endif
V_384:
F_330 ( V_1 -> V_27 ) ;
V_382:
F_296 ( V_1 ) ;
V_379:
F_331 ( V_3 ) ;
V_378:
F_332 ( V_3 ) ;
V_376:
F_333 ( V_13 ) ;
return V_10 ;
}
static void F_334 ( struct V_368 * V_3 )
{
struct V_46 * V_13 = F_335 ( V_3 ) ;
if ( V_13 ) {
struct V_1 * V_1 = F_55 ( V_13 ) ;
F_336 ( & V_1 -> V_62 ) ;
F_336 ( & V_1 -> V_50 ) ;
F_337 ( V_13 ) ;
F_282 ( V_1 ) ;
F_327 ( V_1 -> V_27 ) ;
#ifdef F_21
if ( F_18 ( V_1 ) ) {
F_329 ( V_3 ) ;
V_1 -> V_18 &= ~ V_19 ;
}
#endif
F_328 ( V_1 -> V_163 ) ;
F_330 ( V_1 -> V_27 ) ;
F_296 ( V_1 ) ;
F_331 ( V_3 ) ;
F_332 ( V_3 ) ;
F_333 ( V_13 ) ;
}
}
static int T_10 F_338 ( void )
{
F_339 ( L_54 , V_414 , V_415 ) ;
return F_340 ( & V_416 ) ;
}
static void T_11 F_341 ( void )
{
F_342 ( & V_416 ) ;
}
