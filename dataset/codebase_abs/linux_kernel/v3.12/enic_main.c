int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_4 ;
}
int F_2 ( struct V_1 * V_1 )
{
return ( V_1 -> V_5 & V_6 ) ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 == V_7 ;
}
int F_4 ( struct V_1 * V_1 , int V_8 )
{
#ifdef F_5
return V_8 >= 0 && V_8 < V_1 -> V_9 ;
#else
return 0 ;
#endif
}
static void F_6 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_1 = F_7 ( V_11 -> V_14 ) ;
if ( V_13 -> V_15 )
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_18 ) ;
else
F_9 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_18 ) ;
if ( V_13 -> V_19 )
F_10 ( V_13 -> V_19 ) ;
}
static void F_11 ( struct V_10 * V_11 ,
struct V_20 * V_20 , struct V_12 * V_13 , void * V_21 )
{
F_6 ( V_11 , V_13 ) ;
}
static int F_12 ( struct V_22 * V_14 , struct V_20 * V_20 ,
T_1 type , T_2 V_23 , T_2 V_24 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_14 ) ;
F_13 ( & V_1 -> V_25 [ V_23 ] ) ;
F_14 ( & V_1 -> V_11 [ V_23 ] , V_20 ,
V_24 , F_11 ,
V_21 ) ;
if ( F_15 ( F_16 ( V_1 -> V_26 , V_23 ) ) &&
F_17 ( & V_1 -> V_11 [ V_23 ] ) >=
( V_27 + V_28 ) )
F_18 ( V_1 -> V_26 , V_23 ) ;
F_19 ( & V_1 -> V_25 [ V_23 ] ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
T_3 V_30 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_30 = F_21 ( & V_1 -> V_11 [ V_29 ] ) ;
if ( V_30 )
F_22 ( V_1 -> V_26 , L_1 ,
V_29 , V_30 ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_30 = F_23 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( V_30 )
F_22 ( V_1 -> V_26 , L_2 ,
V_29 , V_30 ) ;
}
}
static void F_24 ( struct V_1 * V_1 )
{
T_3 V_34 = F_25 ( V_1 -> V_14 ) ;
if ( V_34 != V_1 -> V_34 ) {
F_26 ( V_1 -> V_26 , L_3 ,
V_1 -> V_34 , V_34 ) ;
V_1 -> V_34 = V_34 ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
T_3 V_35 = F_28 ( V_1 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
if ( V_35 && V_35 != V_1 -> V_37 ) {
V_1 -> V_37 = V_35 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
V_35 = F_29 ( int , V_38 ,
F_30 ( int , V_39 , V_35 ) ) ;
if ( V_35 != V_26 -> V_35 )
F_31 ( & V_1 -> V_40 ) ;
} else {
if ( V_35 < V_26 -> V_35 )
F_32 ( V_26 ,
L_4
L_5 ,
V_26 -> V_35 , V_35 ) ;
}
}
}
static void F_33 ( struct V_1 * V_1 )
{
int V_41 = F_34 ( V_1 -> V_14 ) ;
int V_42 = F_35 ( V_1 -> V_26 ) ;
if ( V_41 && ! V_42 ) {
F_26 ( V_1 -> V_26 , L_6 ) ;
F_36 ( V_1 -> V_26 ) ;
} else if ( ! V_41 && V_42 ) {
F_26 ( V_1 -> V_26 , L_7 ) ;
F_37 ( V_1 -> V_26 ) ;
}
}
static void F_38 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
F_27 ( V_1 ) ;
F_33 ( V_1 ) ;
}
static T_4 F_39 ( int V_43 , void * V_44 )
{
struct V_36 * V_26 = V_44 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_45 = F_41 () ;
unsigned int V_46 = F_42 () ;
unsigned int V_47 = F_43 () ;
T_3 V_48 ;
F_44 ( & V_1 -> V_49 [ V_45 ] ) ;
V_48 = F_45 ( V_1 -> V_50 ) ;
if ( ! V_48 ) {
F_46 ( & V_1 -> V_49 [ V_45 ] ) ;
return V_51 ;
}
if ( F_47 ( V_48 , V_47 ) ) {
F_48 ( & V_1 -> V_49 [ V_47 ] ) ;
F_38 ( V_1 ) ;
}
if ( F_47 ( V_48 , V_46 ) ) {
F_48 ( & V_1 -> V_49 [ V_46 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
if ( F_47 ( V_48 , V_45 ) ) {
if ( F_49 ( & V_1 -> V_54 [ 0 ] ) )
F_50 ( & V_1 -> V_54 [ 0 ] ) ;
} else {
F_46 ( & V_1 -> V_49 [ V_45 ] ) ;
}
return V_53 ;
}
static T_4 F_51 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
F_52 ( & V_1 -> V_54 [ 0 ] ) ;
return V_53 ;
}
static T_4 F_53 ( int V_43 , void * V_44 )
{
struct V_55 * V_54 = V_44 ;
F_52 ( V_54 ) ;
return V_53 ;
}
static T_4 F_54 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_56 ;
unsigned int V_49 ;
unsigned int V_57 = - 1 ;
unsigned int V_58 ;
unsigned int V_59 ;
V_59 = ( T_3 ) V_43 - V_1 -> V_60 [ F_55 ( V_1 , 0 ) ] . V_61 ;
V_56 = F_56 ( V_1 , V_59 ) ;
V_49 = F_55 ( V_1 , V_59 ) ;
V_58 = F_57 ( & V_1 -> V_56 [ V_56 ] ,
V_57 , F_12 , NULL ) ;
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_58 ,
1 ,
1 ) ;
return V_53 ;
}
static T_4 F_59 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_60 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
F_20 ( V_1 ) ;
F_31 ( & V_1 -> V_52 ) ;
return V_53 ;
}
static T_4 F_61 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_49 = F_62 ( V_1 ) ;
F_48 ( & V_1 -> V_49 [ V_49 ] ) ;
F_38 ( V_1 ) ;
return V_53 ;
}
static inline void F_63 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
unsigned int V_64 , int V_65 )
{
const T_5 * V_66 ;
for ( V_66 = F_64 ( V_63 ) -> V_67 ; V_64 ; V_66 ++ ) {
V_64 -= F_65 ( V_66 ) ;
F_66 ( V_11 , V_63 ,
F_67 ( & V_1 -> V_2 -> V_68 ,
V_66 , 0 , F_65 ( V_66 ) ,
V_69 ) ,
F_65 ( V_66 ) ,
( V_64 == 0 ) ,
V_65 ) ;
}
}
static inline void F_68 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_72 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_72 ;
int V_73 = ( V_64 == 0 ) ;
F_70 ( V_11 , V_63 ,
F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_72 , V_18 ) ,
V_72 ,
V_70 , V_71 ,
V_73 , V_65 ) ;
if ( ! V_73 )
F_63 ( V_1 , V_11 , V_63 , V_64 , V_65 ) ;
}
static inline void F_72 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_72 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_72 ;
unsigned int V_74 = F_73 ( V_63 ) ;
unsigned int V_75 = V_74 + V_63 -> V_75 ;
int V_73 = ( V_64 == 0 ) ;
F_74 ( V_11 , V_63 ,
F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_72 , V_18 ) ,
V_72 ,
V_75 ,
V_74 ,
V_70 , V_71 ,
V_73 , V_65 ) ;
if ( ! V_73 )
F_63 ( V_1 , V_11 , V_63 , V_64 , V_65 ) ;
}
static inline void F_75 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 , unsigned int V_76 ,
int V_70 , unsigned int V_71 , int V_65 )
{
unsigned int V_77 = F_69 ( V_63 ) ;
unsigned int V_64 = V_63 -> V_17 - V_77 ;
unsigned int V_74 = F_76 ( V_63 ) + F_77 ( V_63 ) ;
int V_73 = ( V_64 == 0 ) ;
unsigned int V_17 ;
T_6 V_16 ;
unsigned int V_78 = 0 ;
T_5 * V_66 ;
if ( V_63 -> V_79 == F_78 ( V_80 ) ) {
F_79 ( V_63 ) -> V_81 = 0 ;
F_80 ( V_63 ) -> V_81 = ~ F_81 ( F_79 ( V_63 ) -> V_82 ,
F_79 ( V_63 ) -> V_83 , 0 , V_84 , 0 ) ;
} else if ( V_63 -> V_79 == F_78 ( V_85 ) ) {
F_80 ( V_63 ) -> V_81 = ~ F_82 ( & F_83 ( V_63 ) -> V_82 ,
& F_83 ( V_63 ) -> V_83 , 0 , V_84 , 0 ) ;
}
while ( V_77 ) {
V_17 = F_84 ( V_77 , ( unsigned int ) V_86 ) ;
V_16 = F_71 ( V_1 -> V_2 , V_63 -> V_44 + V_78 ,
V_17 , V_18 ) ;
F_85 ( V_11 , V_63 ,
V_16 ,
V_17 ,
V_76 , V_74 ,
V_70 , V_71 ,
V_73 && ( V_17 == V_77 ) , V_65 ) ;
V_77 -= V_17 ;
V_78 += V_17 ;
}
if ( V_73 )
return;
for ( V_66 = F_64 ( V_63 ) -> V_67 ; V_64 ; V_66 ++ ) {
V_64 -= F_65 ( V_66 ) ;
V_77 = F_65 ( V_66 ) ;
V_78 = 0 ;
while ( V_77 ) {
V_17 = F_84 ( V_77 ,
( unsigned int ) V_86 ) ;
V_16 = F_67 ( & V_1 -> V_2 -> V_68 , V_66 ,
V_78 , V_17 ,
V_69 ) ;
F_66 ( V_11 , V_63 ,
V_16 ,
V_17 ,
( V_64 == 0 ) &&
( V_17 == V_77 ) ,
V_65 ) ;
V_77 -= V_17 ;
V_78 += V_17 ;
}
}
}
static inline void F_86 ( struct V_1 * V_1 ,
struct V_10 * V_11 , struct V_62 * V_63 )
{
unsigned int V_76 = F_64 ( V_63 ) -> V_87 ;
unsigned int V_71 = 0 ;
int V_70 = 0 ;
int V_65 = 0 ;
if ( F_87 ( V_63 ) ) {
V_70 = 1 ;
V_71 = F_88 ( V_63 ) ;
} else if ( V_1 -> V_88 ) {
V_71 = V_1 -> V_89 ;
V_65 = 1 ;
}
if ( V_76 )
F_75 ( V_1 , V_11 , V_63 , V_76 ,
V_70 , V_71 , V_65 ) ;
else if ( V_63 -> V_90 == V_91 )
F_72 ( V_1 , V_11 , V_63 ,
V_70 , V_71 , V_65 ) ;
else
F_68 ( V_1 , V_11 , V_63 ,
V_70 , V_71 , V_65 ) ;
}
static T_7 F_89 ( struct V_62 * V_63 ,
struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_10 * V_11 ;
unsigned long V_92 ;
unsigned int V_93 ;
if ( V_63 -> V_17 <= 0 ) {
F_90 ( V_63 ) ;
return V_94 ;
}
V_93 = F_91 ( V_63 ) % V_1 -> V_31 ;
V_11 = & V_1 -> V_11 [ V_93 ] ;
if ( F_64 ( V_63 ) -> V_87 == 0 &&
F_64 ( V_63 ) -> V_95 + 1 > V_96 &&
F_92 ( V_63 ) ) {
F_90 ( V_63 ) ;
return V_94 ;
}
F_93 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
if ( F_17 ( V_11 ) <
F_64 ( V_63 ) -> V_95 + V_28 ) {
F_94 ( F_16 ( V_26 , V_93 ) ) ;
F_22 ( V_26 , L_8 ) ;
F_95 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
return V_97 ;
}
F_86 ( V_1 , V_11 , V_63 ) ;
if ( F_17 ( V_11 ) < V_27 + V_28 )
F_94 ( F_16 ( V_26 , V_93 ) ) ;
F_95 ( & V_1 -> V_25 [ V_93 ] , V_92 ) ;
return V_94 ;
}
static struct V_98 * F_96 ( struct V_36 * V_26 ,
struct V_98 * V_99 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_100 * V_101 ;
F_97 ( V_1 , & V_101 ) ;
V_99 -> V_102 = V_101 -> V_103 . V_104 ;
V_99 -> V_105 = V_101 -> V_103 . V_106 ;
V_99 -> V_107 = V_101 -> V_103 . V_107 ;
V_99 -> V_108 = V_101 -> V_103 . V_109 ;
V_99 -> V_110 = V_101 -> V_111 . V_112 ;
V_99 -> V_113 = V_101 -> V_111 . V_114 ;
V_99 -> V_115 = V_101 -> V_111 . V_115 ;
V_99 -> V_116 = V_101 -> V_111 . V_117 ;
V_99 -> V_118 = V_1 -> V_119 ;
V_99 -> V_120 = V_1 -> V_121 ;
V_99 -> V_122 = V_101 -> V_111 . V_123 + V_101 -> V_111 . V_124 ;
return V_99 ;
}
void F_98 ( struct V_1 * V_1 )
{
V_1 -> V_125 = 0 ;
V_1 -> V_126 = 0 ;
V_1 -> V_92 = 0 ;
}
static int F_99 ( struct V_36 * V_26 , char * V_127 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) ) {
if ( ! F_100 ( V_127 ) && ! F_101 ( V_127 ) )
return - V_128 ;
} else {
if ( ! F_100 ( V_127 ) )
return - V_128 ;
}
memcpy ( V_26 -> V_129 , V_127 , V_26 -> V_130 ) ;
return 0 ;
}
static int F_102 ( struct V_36 * V_26 , void * V_131 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_132 * V_82 = V_131 ;
char * V_127 = V_82 -> V_133 ;
int V_134 ;
if ( F_103 ( V_1 -> V_26 ) ) {
V_134 = F_104 ( V_1 ) ;
if ( V_134 )
return V_134 ;
}
V_134 = F_99 ( V_26 , V_127 ) ;
if ( V_134 )
return V_134 ;
if ( F_103 ( V_1 -> V_26 ) ) {
V_134 = F_105 ( V_1 ) ;
if ( V_134 )
return V_134 ;
}
return V_134 ;
}
static int F_106 ( struct V_36 * V_26 , void * V_131 )
{
struct V_132 * V_82 = V_131 ;
char * V_127 = V_82 -> V_133 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_134 ;
V_134 = F_104 ( V_1 ) ;
if ( V_134 )
return V_134 ;
V_134 = F_99 ( V_26 , V_127 ) ;
if ( V_134 )
return V_134 ;
return F_105 ( V_1 ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_135 * V_136 ;
unsigned int V_125 = F_108 ( V_26 ) ;
T_1 V_137 [ V_138 ] [ V_139 ] ;
unsigned int V_29 , V_140 ;
if ( V_125 > V_138 ) {
F_32 ( V_26 , L_9
L_10 ,
V_138 , V_125 ) ;
V_125 = V_138 ;
}
V_29 = 0 ;
F_109 (ha, netdev) {
if ( V_29 == V_125 )
break;
memcpy ( V_137 [ V_29 ++ ] , V_136 -> V_127 , V_139 ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_125 ; V_29 ++ ) {
for ( V_140 = 0 ; V_140 < V_125 ; V_140 ++ )
if ( F_110 ( V_1 -> V_137 [ V_29 ] , V_137 [ V_140 ] ) )
break;
if ( V_140 == V_125 )
F_111 ( V_1 , V_1 -> V_137 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_125 ; V_29 ++ ) {
for ( V_140 = 0 ; V_140 < V_1 -> V_125 ; V_140 ++ )
if ( F_110 ( V_137 [ V_29 ] , V_1 -> V_137 [ V_140 ] ) )
break;
if ( V_140 == V_1 -> V_125 )
F_112 ( V_1 , V_137 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_125 ; V_29 ++ )
memcpy ( V_1 -> V_137 [ V_29 ] , V_137 [ V_29 ] , V_139 ) ;
V_1 -> V_125 = V_125 ;
}
static void F_113 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_135 * V_136 ;
unsigned int V_126 = F_114 ( V_26 ) ;
T_1 V_141 [ V_142 ] [ V_139 ] ;
unsigned int V_29 , V_140 ;
if ( V_126 > V_142 ) {
F_32 ( V_26 , L_9
L_11 ,
V_142 , V_126 ) ;
V_126 = V_142 ;
}
V_29 = 0 ;
F_115 (ha, netdev) {
if ( V_29 == V_126 )
break;
memcpy ( V_141 [ V_29 ++ ] , V_136 -> V_127 , V_139 ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_126 ; V_29 ++ ) {
for ( V_140 = 0 ; V_140 < V_126 ; V_140 ++ )
if ( F_110 ( V_1 -> V_141 [ V_29 ] , V_141 [ V_140 ] ) )
break;
if ( V_140 == V_126 )
F_111 ( V_1 , V_1 -> V_141 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_126 ; V_29 ++ ) {
for ( V_140 = 0 ; V_140 < V_1 -> V_126 ; V_140 ++ )
if ( F_110 ( V_141 [ V_29 ] , V_1 -> V_141 [ V_140 ] ) )
break;
if ( V_140 == V_1 -> V_126 )
F_112 ( V_1 , V_141 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_126 ; V_29 ++ )
memcpy ( V_1 -> V_141 [ V_29 ] , V_141 [ V_29 ] , V_139 ) ;
V_1 -> V_126 = V_126 ;
}
static void F_116 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_143 = 1 ;
int V_116 = ( V_26 -> V_92 & V_144 ) ? 1 : 0 ;
int V_145 = ( V_26 -> V_92 & V_146 ) ? 1 : 0 ;
int V_147 = ( V_26 -> V_92 & V_148 ) ||
F_114 ( V_26 ) > V_142 ;
int V_149 = ( V_26 -> V_92 & V_150 ) ||
F_108 ( V_26 ) > V_138 ;
unsigned int V_92 = V_26 -> V_92 |
( V_149 ? V_150 : 0 ) |
( V_147 ? V_148 : 0 ) ;
if ( V_1 -> V_92 != V_92 ) {
V_1 -> V_92 = V_92 ;
F_117 ( V_1 , V_143 ,
V_116 , V_145 , V_147 , V_149 ) ;
}
if ( ! V_147 ) {
F_113 ( V_1 ) ;
if ( ! V_149 )
F_107 ( V_1 ) ;
}
}
static void F_118 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_31 ( & V_1 -> V_52 ) ;
}
static int F_119 ( struct V_36 * V_26 , int V_8 , T_1 * V_151 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_152 * V_153 ;
int V_134 ;
F_120 ( V_1 , V_8 , V_153 , & V_134 ) ;
if ( V_134 )
return V_134 ;
if ( F_100 ( V_151 ) || F_101 ( V_151 ) ) {
if ( V_8 == V_154 ) {
memcpy ( V_153 -> V_155 , V_151 , V_139 ) ;
return 0 ;
} else {
F_121 ( V_8 , V_134 , V_1 ,
V_156 , V_151 ) ;
return F_122 ( V_134 ) ;
}
} else
return - V_157 ;
}
static int F_123 ( struct V_36 * V_26 , int V_8 ,
struct V_158 * V_159 [] )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_152 V_160 ;
struct V_152 * V_153 ;
int V_134 = 0 , V_161 = 1 ;
F_120 ( V_1 , V_8 , V_153 , & V_134 ) ;
if ( V_134 )
return V_134 ;
if ( ! V_159 [ V_162 ] )
return - V_163 ;
memcpy ( & V_160 , V_153 , sizeof( * V_1 -> V_153 ) ) ;
memset ( V_153 , 0 , sizeof( * V_1 -> V_153 ) ) ;
V_153 -> V_164 |= V_165 ;
V_153 -> V_166 = F_124 ( V_159 [ V_162 ] ) ;
if ( V_159 [ V_167 ] ) {
V_153 -> V_164 |= V_168 ;
memcpy ( V_153 -> V_169 , F_125 ( V_159 [ V_167 ] ) ,
V_170 ) ;
}
if ( V_159 [ V_171 ] ) {
V_153 -> V_164 |= V_172 ;
memcpy ( V_153 -> V_173 ,
F_125 ( V_159 [ V_171 ] ) , V_174 ) ;
}
if ( V_159 [ V_175 ] ) {
V_153 -> V_164 |= V_176 ;
memcpy ( V_153 -> V_177 ,
F_125 ( V_159 [ V_175 ] ) , V_174 ) ;
}
if ( V_8 == V_154 ) {
if ( ! F_101 ( V_160 . V_155 ) )
memcpy ( V_153 -> V_178 , V_160 . V_155 , V_139 ) ;
if ( F_101 ( V_26 -> V_129 ) )
F_126 ( V_26 ) ;
} else {
F_121 ( V_8 , V_134 , V_1 ,
V_179 , V_153 -> V_178 ) ;
if ( V_134 ) {
F_22 ( V_26 , L_12 , V_8 ) ;
memcpy ( V_153 , & V_160 , sizeof( * V_153 ) ) ;
return F_122 ( V_134 ) ;
}
}
V_134 = F_127 ( V_1 , V_8 , & V_160 , & V_161 ) ;
if ( V_134 ) {
if ( V_161 ) {
memcpy ( V_153 , & V_160 , sizeof( * V_153 ) ) ;
} else {
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
if ( V_8 == V_154 )
memset ( V_26 -> V_129 , 0 , V_139 ) ;
}
} else {
V_153 -> V_164 |= V_180 ;
if ( V_153 -> V_166 == V_181 ) {
memset ( V_153 -> V_178 , 0 , V_139 ) ;
if ( V_8 == V_154 )
memset ( V_26 -> V_129 , 0 , V_139 ) ;
}
}
if ( V_8 == V_154 )
memset ( V_153 -> V_155 , 0 , V_139 ) ;
return V_134 ;
}
static int F_128 ( struct V_36 * V_26 , int V_8 ,
struct V_62 * V_63 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
T_2 V_182 = V_183 ;
struct V_152 * V_153 ;
int V_134 ;
F_120 ( V_1 , V_8 , V_153 , & V_134 ) ;
if ( V_134 )
return V_134 ;
if ( ! ( V_153 -> V_164 & V_180 ) )
return - V_184 ;
V_134 = F_129 ( V_1 , V_8 , V_153 -> V_166 , & V_182 ) ;
if ( V_134 )
return V_134 ;
if ( F_130 ( V_63 , V_162 , V_153 -> V_166 ) ||
F_130 ( V_63 , V_185 , V_182 ) ||
( ( V_153 -> V_164 & V_168 ) &&
F_131 ( V_63 , V_167 , V_170 , V_153 -> V_169 ) ) ||
( ( V_153 -> V_164 & V_172 ) &&
F_131 ( V_63 , V_171 , V_174 ,
V_153 -> V_173 ) ) ||
( ( V_153 -> V_164 & V_176 ) &&
F_131 ( V_63 , V_175 , V_174 , V_153 -> V_177 ) ) )
goto V_186;
return 0 ;
V_186:
return - V_187 ;
}
static void F_132 ( struct V_188 * V_33 , struct V_189 * V_13 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
if ( ! V_13 -> V_19 )
return;
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_190 ) ;
F_10 ( V_13 -> V_19 ) ;
}
static int F_133 ( struct V_188 * V_33 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_62 * V_63 ;
unsigned int V_17 = V_26 -> V_35 + V_191 ;
unsigned int V_192 = 0 ;
T_6 V_16 ;
V_63 = F_134 ( V_26 , V_17 ) ;
if ( ! V_63 )
return - V_193 ;
V_16 = F_71 ( V_1 -> V_2 , V_63 -> V_44 ,
V_17 , V_190 ) ;
F_135 ( V_33 , V_63 , V_192 ,
V_16 , V_17 ) ;
return 0 ;
}
static void F_136 ( struct V_188 * V_33 ,
struct V_20 * V_20 , struct V_189 * V_13 ,
int V_194 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_33 -> V_14 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
struct V_62 * V_63 ;
T_1 type , V_195 , V_73 , V_15 , V_196 , V_197 ;
T_1 V_198 , V_199 , V_200 , V_201 , V_202 ;
T_1 V_203 , V_204 , V_205 , V_206 ;
T_1 V_207 , V_208 , V_209 , V_210 , V_211 , V_212 ;
T_1 V_213 ;
T_2 V_23 , V_24 , V_214 , V_215 , V_216 ;
T_3 V_217 ;
if ( V_194 )
return;
V_63 = V_13 -> V_19 ;
F_137 ( V_63 -> V_44 - V_218 ) ;
F_8 ( V_1 -> V_2 , V_13 -> V_16 ,
V_13 -> V_17 , V_190 ) ;
F_138 ( (struct V_219 * ) V_20 ,
& type , & V_195 , & V_23 , & V_24 ,
& V_196 , & V_198 , & V_73 , & V_15 , & V_211 ,
& V_212 , & V_217 , & V_214 ,
& V_213 , & V_197 , & V_215 , & V_216 ,
& V_199 , & V_200 , & V_201 ,
& V_202 , & V_203 , & V_204 , & V_205 ,
& V_206 , & V_207 , & V_208 , & V_209 ,
& V_210 ) ;
if ( V_213 ) {
if ( ! V_210 ) {
if ( V_214 > 0 )
V_1 -> V_121 ++ ;
else if ( V_214 == 0 )
V_1 -> V_119 ++ ;
}
F_10 ( V_63 ) ;
return;
}
if ( V_73 && V_214 > 0 ) {
F_139 ( V_63 , V_214 ) ;
V_63 -> V_79 = F_140 ( V_63 , V_26 ) ;
F_141 ( V_63 , V_23 ) ;
if ( V_26 -> V_220 & V_221 ) {
V_63 -> V_222 = V_217 ;
if ( V_211 & ( V_223 |
V_224 |
V_225 ) )
V_63 -> V_226 = true ;
}
if ( ( V_26 -> V_220 & V_227 ) && ! V_212 ) {
V_63 -> V_228 = F_142 ( V_216 ) ;
V_63 -> V_90 = V_229 ;
}
if ( V_197 )
F_143 ( V_63 , F_142 ( V_230 ) , V_215 ) ;
if ( V_26 -> V_220 & V_231 )
F_144 ( & V_1 -> V_54 [ V_23 ] , V_63 ) ;
else
F_145 ( V_63 ) ;
} else {
F_10 ( V_63 ) ;
}
}
static int F_146 ( struct V_22 * V_14 , struct V_20 * V_20 ,
T_1 type , T_2 V_23 , T_2 V_24 , void * V_21 )
{
struct V_1 * V_1 = F_7 ( V_14 ) ;
F_147 ( & V_1 -> V_33 [ V_23 ] , V_20 ,
V_24 , V_232 ,
F_136 , V_21 ) ;
return 0 ;
}
static int F_148 ( struct V_55 * V_54 , int V_233 )
{
struct V_36 * V_26 = V_54 -> V_68 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_234 = F_149 ( V_1 , 0 ) ;
unsigned int V_235 = F_56 ( V_1 , 0 ) ;
unsigned int V_49 = F_41 () ;
unsigned int V_236 = V_233 ;
unsigned int V_57 = - 1 ;
unsigned int V_237 , V_238 , V_58 ;
int V_134 ;
V_238 = F_57 ( & V_1 -> V_56 [ V_234 ] ,
V_236 , F_146 , NULL ) ;
V_58 = F_57 ( & V_1 -> V_56 [ V_235 ] ,
V_57 , F_12 , NULL ) ;
V_237 = V_238 + V_58 ;
if ( V_237 > 0 )
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_237 ,
0 ,
0 ) ;
V_134 = F_150 ( & V_1 -> V_33 [ 0 ] , F_133 ) ;
if ( V_134 )
V_238 = V_236 ;
if ( V_238 < V_236 ) {
F_151 ( V_54 ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_238 ;
}
static int F_152 ( struct V_55 * V_54 , int V_233 )
{
struct V_36 * V_26 = V_54 -> V_68 ;
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_33 = ( V_54 - & V_1 -> V_54 [ 0 ] ) ;
unsigned int V_56 = F_149 ( V_1 , V_33 ) ;
unsigned int V_49 = F_153 ( V_1 , V_33 ) ;
unsigned int V_239 = V_233 ;
unsigned int V_237 ;
int V_134 ;
V_237 = F_57 ( & V_1 -> V_56 [ V_56 ] ,
V_239 , F_146 , NULL ) ;
if ( V_237 > 0 )
F_58 ( & V_1 -> V_49 [ V_49 ] ,
V_237 ,
0 ,
0 ) ;
V_134 = F_150 ( & V_1 -> V_33 [ V_33 ] , F_133 ) ;
if ( V_134 )
V_237 = V_239 ;
if ( V_237 < V_239 ) {
F_151 ( V_54 ) ;
F_46 ( & V_1 -> V_49 [ V_49 ] ) ;
}
return V_237 ;
}
static void F_154 ( unsigned long V_44 )
{
struct V_1 * V_1 = (struct V_1 * ) V_44 ;
F_38 ( V_1 ) ;
F_155 ( & V_1 -> V_240 ,
F_156 ( V_241 + V_242 ) ) ;
}
static void F_157 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_243 :
F_159 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
case V_244 :
F_159 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_245 :
for ( V_29 = 0 ; V_29 < F_160 ( V_1 -> V_246 ) ; V_29 ++ )
if ( V_1 -> V_246 [ V_29 ] . V_247 )
F_159 ( V_1 -> V_60 [ V_29 ] . V_61 ,
V_1 -> V_246 [ V_29 ] . V_248 ) ;
break;
default:
break;
}
}
static int F_161 ( struct V_1 * V_1 )
{
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 , V_49 ;
int V_134 = 0 ;
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_243 :
V_134 = F_162 ( V_1 -> V_2 -> V_43 , F_39 ,
V_249 , V_26 -> V_169 , V_26 ) ;
break;
case V_244 :
V_134 = F_162 ( V_1 -> V_2 -> V_43 , F_51 ,
0 , V_26 -> V_169 , V_1 ) ;
break;
case V_245 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_153 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_246 [ V_49 ] . V_250 ,
sizeof( V_1 -> V_246 [ V_49 ] . V_250 ) ,
L_13 , V_26 -> V_169 , V_29 ) ;
V_1 -> V_246 [ V_49 ] . V_251 = F_53 ;
V_1 -> V_246 [ V_49 ] . V_248 = & V_1 -> V_54 [ V_29 ] ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_49 = F_55 ( V_1 , V_29 ) ;
snprintf ( V_1 -> V_246 [ V_49 ] . V_250 ,
sizeof( V_1 -> V_246 [ V_49 ] . V_250 ) ,
L_14 , V_26 -> V_169 , V_29 ) ;
V_1 -> V_246 [ V_49 ] . V_251 = F_54 ;
V_1 -> V_246 [ V_49 ] . V_248 = V_1 ;
}
V_49 = F_60 ( V_1 ) ;
snprintf ( V_1 -> V_246 [ V_49 ] . V_250 ,
sizeof( V_1 -> V_246 [ V_49 ] . V_250 ) ,
L_15 , V_26 -> V_169 ) ;
V_1 -> V_246 [ V_49 ] . V_251 = F_59 ;
V_1 -> V_246 [ V_49 ] . V_248 = V_1 ;
V_49 = F_62 ( V_1 ) ;
snprintf ( V_1 -> V_246 [ V_49 ] . V_250 ,
sizeof( V_1 -> V_246 [ V_49 ] . V_250 ) ,
L_16 , V_26 -> V_169 ) ;
V_1 -> V_246 [ V_49 ] . V_251 = F_61 ;
V_1 -> V_246 [ V_49 ] . V_248 = V_1 ;
for ( V_29 = 0 ; V_29 < F_160 ( V_1 -> V_246 ) ; V_29 ++ )
V_1 -> V_246 [ V_29 ] . V_247 = 0 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_252 ; V_29 ++ ) {
V_134 = F_162 ( V_1 -> V_60 [ V_29 ] . V_61 ,
V_1 -> V_246 [ V_29 ] . V_251 , 0 ,
V_1 -> V_246 [ V_29 ] . V_250 ,
V_1 -> V_246 [ V_29 ] . V_248 ) ;
if ( V_134 ) {
F_157 ( V_1 ) ;
break;
}
V_1 -> V_246 [ V_29 ] . V_247 = 1 ;
}
break;
default:
break;
}
return V_134 ;
}
static void F_163 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_243 :
case V_244 :
F_164 ( V_1 -> V_2 -> V_43 ) ;
break;
case V_245 :
for ( V_29 = 0 ; V_29 < V_1 -> V_252 ; V_29 ++ )
F_164 ( V_1 -> V_60 [ V_29 ] . V_61 ) ;
break;
default:
break;
}
}
static int F_165 ( struct V_1 * V_1 )
{
int V_134 ;
F_13 ( & V_1 -> V_253 ) ;
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_243 :
V_134 = F_166 ( V_1 -> V_14 ,
F_43 () ) ;
break;
case V_245 :
V_134 = F_166 ( V_1 -> V_14 ,
F_62 ( V_1 ) ) ;
break;
default:
V_134 = F_166 ( V_1 -> V_14 , - 1 ) ;
break;
}
F_19 ( & V_1 -> V_253 ) ;
return V_134 ;
}
static void F_167 ( struct V_1 * V_1 )
{
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_244 :
F_155 ( & V_1 -> V_240 , V_241 ) ;
break;
default:
break;
}
}
static int F_168 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_134 ;
V_134 = F_161 ( V_1 ) ;
if ( V_134 ) {
F_22 ( V_26 , L_17 ) ;
return V_134 ;
}
V_134 = F_165 ( V_1 ) ;
if ( V_134 ) {
F_22 ( V_26 ,
L_18 ) ;
goto V_254;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
F_150 ( & V_1 -> V_33 [ V_29 ] , F_133 ) ;
if ( F_169 ( & V_1 -> V_33 [ V_29 ] ) == 0 ) {
F_22 ( V_26 , L_19 ) ;
V_134 = - V_193 ;
goto V_255;
}
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_170 ( & V_1 -> V_11 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_171 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_105 ( V_1 ) ;
F_116 ( V_26 ) ;
F_172 ( V_26 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_173 ( & V_1 -> V_54 [ V_29 ] ) ;
F_174 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_252 ; V_29 ++ )
F_46 ( & V_1 -> V_49 [ V_29 ] ) ;
F_167 ( V_1 ) ;
return 0 ;
V_255:
F_175 ( V_1 ) ;
V_254:
F_157 ( V_1 ) ;
return V_134 ;
}
static int F_176 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
unsigned int V_29 ;
int V_134 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_252 ; V_29 ++ ) {
F_44 ( & V_1 -> V_49 [ V_29 ] ) ;
( void ) F_177 ( & V_1 -> V_49 [ V_29 ] ) ;
}
F_163 ( V_1 ) ;
F_178 ( & V_1 -> V_240 ) ;
F_179 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_180 ( & V_1 -> V_54 [ V_29 ] ) ;
F_37 ( V_26 ) ;
F_181 ( V_26 ) ;
if ( ! F_1 ( V_1 ) && ! F_3 ( V_1 ) )
F_104 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_134 = F_182 ( & V_1 -> V_11 [ V_29 ] ) ;
if ( V_134 )
return V_134 ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_134 = F_183 ( & V_1 -> V_33 [ V_29 ] ) ;
if ( V_134 )
return V_134 ;
}
F_175 ( V_1 ) ;
F_157 ( V_1 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_184 ( & V_1 -> V_11 [ V_29 ] , F_6 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_185 ( & V_1 -> V_33 [ V_29 ] , F_132 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_256 ; V_29 ++ )
F_186 ( & V_1 -> V_56 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_252 ; V_29 ++ )
F_187 ( & V_1 -> V_49 [ V_29 ] ) ;
return 0 ;
}
static int F_188 ( struct V_36 * V_26 , int V_257 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
int V_258 = F_103 ( V_26 ) ;
if ( V_257 < V_38 || V_257 > V_39 )
return - V_157 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
return - V_163 ;
if ( V_258 )
F_176 ( V_26 ) ;
V_26 -> V_35 = V_257 ;
if ( V_26 -> V_35 > V_1 -> V_37 )
F_32 ( V_26 ,
L_20 ,
V_26 -> V_35 , V_1 -> V_37 ) ;
if ( V_258 )
F_168 ( V_26 ) ;
return 0 ;
}
static void F_189 ( struct V_259 * V_260 )
{
struct V_1 * V_1 = F_190 ( V_260 , struct V_1 , V_40 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
int V_257 = F_28 ( V_1 -> V_14 ) ;
int V_134 ;
unsigned int V_29 ;
V_257 = F_29 ( int , V_38 , F_30 ( int , V_39 , V_257 ) ) ;
F_191 () ;
F_178 ( & V_1 -> V_240 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_180 ( & V_1 -> V_54 [ V_29 ] ) ;
F_44 ( & V_1 -> V_49 [ 0 ] ) ;
F_163 ( V_1 ) ;
V_134 = F_183 ( & V_1 -> V_33 [ 0 ] ) ;
if ( V_134 ) {
F_192 () ;
F_22 ( V_26 , L_21 ) ;
return;
}
F_185 ( & V_1 -> V_33 [ 0 ] , F_132 ) ;
F_186 ( & V_1 -> V_56 [ 0 ] ) ;
F_187 ( & V_1 -> V_49 [ 0 ] ) ;
V_26 -> V_35 = V_257 ;
F_150 ( & V_1 -> V_33 [ 0 ] , F_133 ) ;
if ( F_169 ( & V_1 -> V_33 [ 0 ] ) == 0 ) {
F_192 () ;
F_22 ( V_26 , L_22 ) ;
return;
}
F_171 ( & V_1 -> V_33 [ 0 ] ) ;
F_173 ( & V_1 -> V_54 [ 0 ] ) ;
F_46 ( & V_1 -> V_49 [ 0 ] ) ;
F_167 ( V_1 ) ;
F_192 () ;
F_26 ( V_26 , L_23 , V_26 -> V_35 ) ;
}
static void F_193 ( struct V_36 * V_26 )
{
struct V_1 * V_1 = F_40 ( V_26 ) ;
struct V_22 * V_14 = V_1 -> V_14 ;
unsigned int V_29 , V_49 ;
switch ( F_158 ( V_14 ) ) {
case V_245 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ ) {
V_49 = F_153 ( V_1 , V_29 ) ;
F_53 ( V_1 -> V_60 [ V_49 ] . V_61 ,
& V_1 -> V_54 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_49 = F_55 ( V_1 , V_29 ) ;
F_54 ( V_1 -> V_60 [ V_49 ] . V_61 , V_1 ) ;
}
break;
case V_244 :
F_51 ( V_1 -> V_2 -> V_43 , V_1 ) ;
break;
case V_243 :
F_39 ( V_1 -> V_2 -> V_43 , V_26 ) ;
break;
default:
break;
}
}
static int F_194 ( struct V_22 * V_14 ,
int (* F_195)( struct V_22 * , int ) ,
int (* F_196)( struct V_22 * , int * ) ,
int V_261 )
{
unsigned long time ;
int V_262 ;
int V_134 ;
F_197 ( F_198 () ) ;
V_134 = F_195 ( V_14 , V_261 ) ;
if ( V_134 )
return V_134 ;
time = V_241 + ( V_263 * 2 ) ;
do {
V_134 = F_196 ( V_14 , & V_262 ) ;
if ( V_134 )
return V_134 ;
if ( V_262 )
return 0 ;
F_199 ( V_263 / 10 ) ;
} while ( F_200 ( time , V_241 ) );
return - V_264 ;
}
static int F_201 ( struct V_1 * V_1 )
{
int V_134 ;
V_134 = F_194 ( V_1 -> V_14 , V_265 ,
V_266 , 0 ) ;
if ( V_134 )
F_202 ( F_203 ( V_1 ) , L_24 ,
V_134 ) ;
return V_134 ;
}
static int F_204 ( struct V_1 * V_1 )
{
int V_134 ;
V_134 = F_194 ( V_1 -> V_14 , V_267 ,
V_268 , 0 ) ;
if ( V_134 )
F_22 ( V_1 -> V_26 , L_25 ,
V_134 ) ;
return V_134 ;
}
static int F_205 ( struct V_1 * V_1 )
{
T_6 V_269 ;
union V_270 * V_271 = NULL ;
union V_270 V_272 = {
. V_273 [ 0 ] . V_274 = { 85 , 67 , 83 , 97 , 119 , 101 , 115 , 111 , 109 , 101 } ,
. V_273 [ 1 ] . V_274 = { 80 , 65 , 76 , 79 , 117 , 110 , 105 , 113 , 117 , 101 } ,
. V_273 [ 2 ] . V_274 = { 76 , 73 , 78 , 85 , 88 , 114 , 111 , 99 , 107 , 115 } ,
. V_273 [ 3 ] . V_274 = { 69 , 78 , 73 , 67 , 105 , 115 , 99 , 111 , 111 , 108 } ,
} ;
int V_134 ;
V_271 = F_206 ( V_1 -> V_2 ,
sizeof( union V_270 ) , & V_269 ) ;
if ( ! V_271 )
return - V_193 ;
memcpy ( V_271 , & V_272 , sizeof( union V_270 ) ) ;
F_13 ( & V_1 -> V_253 ) ;
V_134 = F_207 ( V_1 ,
V_269 ,
sizeof( union V_270 ) ) ;
F_19 ( & V_1 -> V_253 ) ;
F_208 ( V_1 -> V_2 , sizeof( union V_270 ) ,
V_271 , V_269 ) ;
return V_134 ;
}
static int F_209 ( struct V_1 * V_1 , T_1 V_275 )
{
T_6 V_276 ;
union V_277 * V_278 = NULL ;
unsigned int V_29 ;
int V_134 ;
V_278 = F_206 ( V_1 -> V_2 ,
sizeof( union V_277 ) , & V_276 ) ;
if ( ! V_278 )
return - V_193 ;
for ( V_29 = 0 ; V_29 < ( 1 << V_275 ) ; V_29 ++ )
( * V_278 ) . V_279 [ V_29 / 4 ] . V_274 [ V_29 % 4 ] = V_29 % V_1 -> V_32 ;
F_13 ( & V_1 -> V_253 ) ;
V_134 = F_210 ( V_1 ,
V_276 ,
sizeof( union V_277 ) ) ;
F_19 ( & V_1 -> V_253 ) ;
F_208 ( V_1 -> V_2 , sizeof( union V_277 ) ,
V_278 , V_276 ) ;
return V_134 ;
}
static int F_211 ( struct V_1 * V_1 , T_1 V_280 ,
T_1 V_281 , T_1 V_275 , T_1 V_282 , T_1 V_283 )
{
const T_1 V_284 = 0 ;
const T_1 V_285 = 1 ;
int V_134 ;
F_13 ( & V_1 -> V_253 ) ;
V_134 = F_212 ( V_1 ,
V_280 , V_281 ,
V_275 , V_282 ,
V_283 , V_284 ,
V_285 ) ;
F_19 ( & V_1 -> V_253 ) ;
return V_134 ;
}
static int F_213 ( struct V_1 * V_1 )
{
struct V_3 * V_68 = F_203 ( V_1 ) ;
const T_1 V_280 = 0 ;
const T_1 V_281 = V_286 |
V_225 |
V_287 |
V_224 ;
const T_1 V_275 = 7 ;
const T_1 V_282 = 0 ;
T_1 V_283 = F_214 ( V_1 , V_288 ) && ( V_1 -> V_32 > 1 ) ;
if ( V_283 ) {
if ( ! F_205 ( V_1 ) ) {
if ( F_209 ( V_1 , V_275 ) ) {
V_283 = 0 ;
F_215 ( V_68 , L_26
L_27 ) ;
}
} else {
V_283 = 0 ;
F_215 ( V_68 , L_28 ) ;
}
}
return F_211 ( V_1 , V_280 , V_281 ,
V_275 , V_282 , V_283 ) ;
}
static void F_216 ( struct V_259 * V_260 )
{
struct V_1 * V_1 = F_190 ( V_260 , struct V_1 , V_52 ) ;
if ( ! F_103 ( V_1 -> V_26 ) )
return;
F_191 () ;
F_13 ( & V_1 -> V_289 ) ;
F_217 ( V_1 ) ;
F_176 ( V_1 -> V_26 ) ;
F_204 ( V_1 ) ;
F_98 ( V_1 ) ;
F_218 ( V_1 ) ;
F_213 ( V_1 ) ;
F_219 ( V_1 ) ;
F_168 ( V_1 -> V_26 ) ;
F_19 ( & V_1 -> V_289 ) ;
F_220 ( V_290 , V_1 -> V_26 ) ;
F_192 () ;
}
static int F_221 ( struct V_1 * V_1 )
{
unsigned int V_291 = F_30 (unsigned int, enic->rq_count, ENIC_RQ_MAX) ;
unsigned int V_292 = F_30 (unsigned int, enic->wq_count, ENIC_WQ_MAX) ;
unsigned int V_29 ;
F_197 ( F_160 ( V_1 -> V_60 ) < V_291 + V_292 + 2 ) ;
for ( V_29 = 0 ; V_29 < V_291 + V_292 + 2 ; V_29 ++ )
V_1 -> V_60 [ V_29 ] . V_293 = V_29 ;
if ( F_214 ( V_1 , V_288 ) &&
V_1 -> V_294 . V_295 < 1 &&
V_1 -> V_32 >= V_291 &&
V_1 -> V_31 >= V_292 &&
V_1 -> V_256 >= V_291 + V_292 &&
V_1 -> V_252 >= V_291 + V_292 + 2 ) {
if ( ! F_222 ( V_1 -> V_2 , V_1 -> V_60 , V_291 + V_292 + 2 ) ) {
V_1 -> V_32 = V_291 ;
V_1 -> V_31 = V_292 ;
V_1 -> V_256 = V_291 + V_292 ;
V_1 -> V_252 = V_291 + V_292 + 2 ;
F_223 ( V_1 -> V_14 ,
V_245 ) ;
return 0 ;
}
}
if ( V_1 -> V_294 . V_295 < 1 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= V_292 &&
V_1 -> V_256 >= 1 + V_292 &&
V_1 -> V_252 >= 1 + V_292 + 2 ) {
if ( ! F_222 ( V_1 -> V_2 , V_1 -> V_60 , 1 + V_292 + 2 ) ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = V_292 ;
V_1 -> V_256 = 1 + V_292 ;
V_1 -> V_252 = 1 + V_292 + 2 ;
F_223 ( V_1 -> V_14 ,
V_245 ) ;
return 0 ;
}
}
if ( V_1 -> V_294 . V_295 < 2 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_256 >= 2 &&
V_1 -> V_252 >= 1 &&
! F_224 ( V_1 -> V_2 ) ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_256 = 2 ;
V_1 -> V_252 = 1 ;
F_223 ( V_1 -> V_14 , V_244 ) ;
return 0 ;
}
if ( V_1 -> V_294 . V_295 < 3 &&
V_1 -> V_32 >= 1 &&
V_1 -> V_31 >= 1 &&
V_1 -> V_256 >= 2 &&
V_1 -> V_252 >= 3 ) {
V_1 -> V_32 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_256 = 2 ;
V_1 -> V_252 = 3 ;
F_223 ( V_1 -> V_14 , V_243 ) ;
return 0 ;
}
F_223 ( V_1 -> V_14 , V_296 ) ;
return - V_157 ;
}
static void F_225 ( struct V_1 * V_1 )
{
switch ( F_158 ( V_1 -> V_14 ) ) {
case V_245 :
F_226 ( V_1 -> V_2 ) ;
break;
case V_244 :
F_227 ( V_1 -> V_2 ) ;
break;
default:
break;
}
F_223 ( V_1 -> V_14 , V_296 ) ;
}
static void F_228 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_229 ( & V_1 -> V_54 [ V_29 ] ) ;
F_230 ( V_1 ) ;
F_225 ( V_1 ) ;
}
static int F_231 ( struct V_1 * V_1 )
{
struct V_3 * V_68 = F_203 ( V_1 ) ;
struct V_36 * V_26 = V_1 -> V_26 ;
unsigned int V_29 ;
int V_134 ;
V_134 = F_232 ( V_1 ) ;
if ( V_134 ) {
F_215 ( V_68 , L_29
L_30 ) ;
F_233 ( V_1 -> V_14 ) ;
}
V_134 = F_234 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_31 ) ;
return V_134 ;
}
F_235 ( V_1 ) ;
V_134 = F_221 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_32
L_33 ) ;
return V_134 ;
}
V_134 = F_236 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_34 ) ;
goto V_297;
}
F_218 ( V_1 ) ;
V_134 = F_213 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_35 ) ;
goto V_297;
}
switch ( F_158 ( V_1 -> V_14 ) ) {
default:
F_237 ( V_26 , & V_1 -> V_54 [ 0 ] , F_148 , 64 ) ;
break;
case V_245 :
for ( V_29 = 0 ; V_29 < V_1 -> V_32 ; V_29 ++ )
F_237 ( V_26 , & V_1 -> V_54 [ V_29 ] ,
F_152 , 64 ) ;
break;
}
return 0 ;
V_297:
F_225 ( V_1 ) ;
F_230 ( V_1 ) ;
return V_134 ;
}
static void F_238 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_160 ( V_1 -> V_298 ) ; V_29 ++ )
if ( V_1 -> V_298 [ V_29 ] . V_299 )
F_239 ( V_1 -> V_298 [ V_29 ] . V_299 ) ;
}
static int F_240 ( struct V_300 * V_2 , const struct V_301 * V_302 )
{
struct V_3 * V_68 = & V_2 -> V_68 ;
struct V_36 * V_26 ;
struct V_1 * V_1 ;
int V_303 = 0 ;
unsigned int V_29 ;
int V_134 ;
#ifdef F_5
int V_304 = 0 ;
#endif
int V_305 = 1 ;
V_26 = F_241 ( sizeof( struct V_1 ) ,
V_306 , V_307 ) ;
if ( ! V_26 )
return - V_193 ;
F_242 ( V_2 , V_26 ) ;
F_243 ( V_26 , & V_2 -> V_68 ) ;
V_1 = F_40 ( V_26 ) ;
V_1 -> V_26 = V_26 ;
V_1 -> V_2 = V_2 ;
V_134 = F_244 ( V_2 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_36 ) ;
goto V_308;
}
V_134 = F_245 ( V_2 , V_309 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_37 ) ;
goto V_310;
}
F_246 ( V_2 ) ;
V_134 = F_247 ( V_2 , F_248 ( 64 ) ) ;
if ( V_134 ) {
V_134 = F_247 ( V_2 , F_248 ( 32 ) ) ;
if ( V_134 ) {
F_202 ( V_68 , L_38 ) ;
goto V_311;
}
V_134 = F_249 ( V_2 , F_248 ( 32 ) ) ;
if ( V_134 ) {
F_202 ( V_68 , L_39
L_40 , 32 ) ;
goto V_311;
}
} else {
V_134 = F_249 ( V_2 , F_248 ( 64 ) ) ;
if ( V_134 ) {
F_202 ( V_68 , L_39
L_40 , 64 ) ;
goto V_311;
}
V_303 = 1 ;
}
for ( V_29 = 0 ; V_29 < F_160 ( V_1 -> V_298 ) ; V_29 ++ ) {
if ( ! ( F_250 ( V_2 , V_29 ) & V_312 ) )
continue;
V_1 -> V_298 [ V_29 ] . V_17 = F_251 ( V_2 , V_29 ) ;
V_1 -> V_298 [ V_29 ] . V_299 = F_252 ( V_2 , V_29 , V_1 -> V_298 [ V_29 ] . V_17 ) ;
if ( ! V_1 -> V_298 [ V_29 ] . V_299 ) {
F_202 ( V_68 , L_41 , V_29 ) ;
V_134 = - V_313 ;
goto V_314;
}
V_1 -> V_298 [ V_29 ] . V_315 = F_253 ( V_2 , V_29 ) ;
}
V_1 -> V_14 = F_254 ( NULL , V_1 , V_2 , V_1 -> V_298 ,
F_160 ( V_1 -> V_298 ) ) ;
if ( ! V_1 -> V_14 ) {
F_202 ( V_68 , L_42 ) ;
V_134 = - V_313 ;
goto V_314;
}
#ifdef F_5
V_304 = F_255 ( V_2 , V_316 ) ;
if ( V_304 ) {
F_256 ( V_2 , V_304 + V_317 ,
& V_1 -> V_9 ) ;
if ( V_1 -> V_9 ) {
V_134 = F_257 ( V_2 , V_1 -> V_9 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_43
L_44 ,
V_134 ) ;
goto V_318;
}
V_1 -> V_5 |= V_6 ;
V_305 = V_1 -> V_9 ;
}
}
#endif
V_1 -> V_153 = F_258 ( V_305 , sizeof( * V_1 -> V_153 ) , V_319 ) ;
if ( ! V_1 -> V_153 ) {
V_134 = - V_193 ;
goto V_320;
}
V_134 = F_201 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_45 ) ;
goto V_321;
}
F_259 ( & V_1 -> V_253 ) ;
F_259 ( & V_1 -> V_289 ) ;
V_134 = F_219 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 ,
L_46 ) ;
goto V_322;
}
F_37 ( V_26 ) ;
if ( ! F_1 ( V_1 ) ) {
V_134 = F_260 ( V_1 -> V_14 , 0 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_47 ) ;
goto V_322;
}
}
V_134 = F_231 ( V_1 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_48 ) ;
goto V_322;
}
F_261 ( V_26 , V_1 -> V_31 ) ;
F_262 ( V_26 , V_1 -> V_32 ) ;
F_263 ( & V_1 -> V_240 ) ;
V_1 -> V_240 . V_323 = F_154 ;
V_1 -> V_240 . V_44 = ( unsigned long ) V_1 ;
F_264 ( & V_1 -> V_52 , F_216 ) ;
F_264 ( & V_1 -> V_40 , F_189 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_259 ( & V_1 -> V_25 [ V_29 ] ) ;
V_1 -> V_37 = V_1 -> V_294 . V_35 ;
( void ) F_188 ( V_26 , V_1 -> V_37 ) ;
V_134 = F_99 ( V_26 , V_1 -> V_178 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_49 ) ;
goto V_324;
}
V_1 -> V_325 = V_1 -> V_294 . V_326 ;
V_1 -> V_327 = V_1 -> V_325 ;
if ( F_1 ( V_1 ) || F_3 ( V_1 ) )
V_26 -> V_328 = & V_329 ;
else
V_26 -> V_328 = & V_330 ;
V_26 -> V_331 = 2 * V_263 ;
F_265 ( V_26 ) ;
V_26 -> V_220 |= V_332 | V_333 ;
if ( F_214 ( V_1 , V_334 ) ) {
V_26 -> V_220 &= ~ V_332 ;
V_1 -> V_88 = 1 ;
V_1 -> V_89 = V_1 -> V_294 . V_89 ;
F_266 ( V_68 , L_50 , V_1 -> V_89 ) ;
}
if ( F_214 ( V_1 , V_335 ) )
V_26 -> V_336 |= V_337 | V_338 ;
if ( F_214 ( V_1 , V_339 ) )
V_26 -> V_336 |= V_340 |
V_341 | V_342 ;
if ( F_214 ( V_1 , V_288 ) )
V_26 -> V_336 |= V_221 ;
if ( F_214 ( V_1 , V_343 ) )
V_26 -> V_336 |= V_227 ;
V_26 -> V_220 |= V_26 -> V_336 ;
if ( V_303 )
V_26 -> V_220 |= V_344 ;
V_26 -> V_5 |= V_345 ;
V_134 = F_267 ( V_26 ) ;
if ( V_134 ) {
F_202 ( V_68 , L_51 ) ;
goto V_324;
}
return 0 ;
V_324:
F_228 ( V_1 ) ;
V_322:
F_268 ( V_1 -> V_14 ) ;
V_321:
F_269 ( V_1 -> V_153 ) ;
V_320:
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_270 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
V_318:
#endif
F_271 ( V_1 -> V_14 ) ;
V_314:
F_238 ( V_1 ) ;
V_311:
F_272 ( V_2 ) ;
V_310:
F_273 ( V_2 ) ;
V_308:
F_242 ( V_2 , NULL ) ;
F_274 ( V_26 ) ;
return V_134 ;
}
static void F_275 ( struct V_300 * V_2 )
{
struct V_36 * V_26 = F_276 ( V_2 ) ;
if ( V_26 ) {
struct V_1 * V_1 = F_40 ( V_26 ) ;
F_277 ( & V_1 -> V_52 ) ;
F_277 ( & V_1 -> V_40 ) ;
F_278 ( V_26 ) ;
F_228 ( V_1 ) ;
F_268 ( V_1 -> V_14 ) ;
#ifdef F_5
if ( F_2 ( V_1 ) ) {
F_270 ( V_2 ) ;
V_1 -> V_5 &= ~ V_6 ;
}
#endif
F_269 ( V_1 -> V_153 ) ;
F_271 ( V_1 -> V_14 ) ;
F_238 ( V_1 ) ;
F_272 ( V_2 ) ;
F_273 ( V_2 ) ;
F_242 ( V_2 , NULL ) ;
F_274 ( V_26 ) ;
}
}
static int T_8 F_279 ( void )
{
F_280 ( L_52 , V_346 , V_347 ) ;
return F_281 ( & V_348 ) ;
}
static void T_9 F_282 ( void )
{
F_283 ( & V_348 ) ;
}
