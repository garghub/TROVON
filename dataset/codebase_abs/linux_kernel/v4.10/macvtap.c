static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ? false :
F_2 () ;
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_5 )
{
int V_6 = ! ! ( V_2 -> V_3 & V_4 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_5 )
{
int V_6 ;
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_4 ;
else
V_2 -> V_3 &= ~ V_4 ;
return 0 ;
}
static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 () ;
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_8 )
{
return - V_9 ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_8 )
{
return - V_9 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_10 ||
F_1 ( V_2 ) ;
}
static inline T_2 F_8 ( struct V_1 * V_2 , T_3 V_11 )
{
return F_9 ( F_7 ( V_2 ) , V_11 ) ;
}
static inline T_3 F_10 ( struct V_1 * V_2 , T_2 V_11 )
{
return F_11 ( F_7 ( V_2 ) , V_11 ) ;
}
static const void * F_12 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_13 ( V_13 -> V_16 ) ;
return F_14 ( V_15 ) ;
}
static struct V_17 * F_15 ( const struct V_14 * V_15 )
{
return F_16 ( V_15 -> V_18 ) ;
}
static int F_17 ( struct V_14 * V_15 , struct V_19 * V_19 ,
struct V_1 * V_2 )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
int V_21 = - V_9 ;
F_19 () ;
if ( V_2 -> V_22 )
goto V_23;
V_21 = 0 ;
F_20 ( V_20 -> V_24 [ V_20 -> V_25 ] , V_2 ) ;
V_2 -> V_26 = V_20 -> V_25 ;
V_2 -> V_22 = true ;
V_20 -> V_25 ++ ;
V_23:
return V_21 ;
}
static int F_21 ( struct V_14 * V_15 , struct V_19 * V_19 ,
struct V_1 * V_2 )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
if ( V_20 -> V_27 == V_28 )
return - V_29 ;
F_20 ( V_2 -> V_20 , V_20 ) ;
F_20 ( V_20 -> V_24 [ V_20 -> V_25 ] , V_2 ) ;
F_22 ( & V_2 -> V_30 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = V_20 -> V_25 ;
V_2 -> V_22 = true ;
V_19 -> V_31 = V_2 ;
F_23 ( & V_2 -> V_32 , & V_20 -> V_33 ) ;
V_20 -> V_25 ++ ;
V_20 -> V_27 ++ ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_17 * V_20 ;
struct V_1 * V_34 ;
F_19 () ;
if ( ! V_2 -> V_22 )
return - V_9 ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( V_20 ) {
int V_35 = V_2 -> V_26 ;
F_26 ( V_35 >= V_20 -> V_25 ) ;
V_34 = F_25 ( V_20 -> V_24 [ V_20 -> V_25 - 1 ] ) ;
V_34 -> V_26 = V_35 ;
F_20 ( V_20 -> V_24 [ V_35 ] , V_34 ) ;
F_27 ( V_20 -> V_24 [ V_20 -> V_25 - 1 ] , NULL ) ;
V_2 -> V_22 = false ;
V_20 -> V_25 -- ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_17 * V_20 ;
F_29 () ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( V_20 ) {
if ( V_2 -> V_22 )
F_26 ( F_24 ( V_2 ) ) ;
V_20 -> V_27 -- ;
F_27 ( V_2 -> V_20 , NULL ) ;
F_30 ( & V_2 -> V_30 ) ;
F_31 ( & V_2 -> V_32 ) ;
}
F_32 () ;
F_33 () ;
F_30 ( & V_2 -> V_30 ) ;
}
static struct V_1 * F_34 ( struct V_14 * V_15 ,
struct V_36 * V_37 )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
struct V_1 * V_38 = NULL ;
int V_25 = F_35 ( V_20 -> V_25 ) ;
T_4 V_39 ;
if ( ! V_25 )
goto V_23;
if ( V_25 == 1 )
goto V_40;
V_39 = F_36 ( V_37 ) ;
if ( V_39 ) {
V_38 = F_16 ( V_20 -> V_24 [ V_39 % V_25 ] ) ;
goto V_23;
}
if ( F_37 ( F_38 ( V_37 ) ) ) {
V_39 = F_39 ( V_37 ) ;
while ( F_40 ( V_39 >= V_25 ) )
V_39 -= V_25 ;
V_38 = F_16 ( V_20 -> V_24 [ V_39 ] ) ;
goto V_23;
}
V_40:
V_38 = F_16 ( V_20 -> V_24 [ 0 ] ) ;
V_23:
return V_38 ;
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
struct V_1 * V_2 , * V_41 ;
F_19 () ;
F_42 (q, tmp, &vlan->queue_list, next) {
F_31 ( & V_2 -> V_32 ) ;
F_27 ( V_2 -> V_20 , NULL ) ;
if ( V_2 -> V_22 )
V_20 -> V_25 -- ;
V_20 -> V_27 -- ;
F_30 ( & V_2 -> V_30 ) ;
}
F_26 ( V_20 -> V_25 ) ;
F_26 ( V_20 -> V_27 ) ;
V_20 -> V_25 = V_28 ;
}
static T_5 F_43 ( struct V_36 * * V_42 )
{
struct V_36 * V_37 = * V_42 ;
struct V_14 * V_15 = V_37 -> V_15 ;
struct V_17 * V_20 ;
struct V_1 * V_2 ;
T_6 V_43 = V_44 ;
V_20 = F_15 ( V_15 ) ;
if ( ! V_20 )
return V_45 ;
V_2 = F_34 ( V_15 , V_37 ) ;
if ( ! V_2 )
return V_45 ;
if ( F_44 ( & V_2 -> V_46 ) )
goto V_47;
F_45 ( V_37 , V_48 ) ;
if ( V_2 -> V_3 & V_49 )
V_43 |= V_20 -> V_50 ;
if ( F_46 ( V_37 , V_43 ) ) {
struct V_36 * V_51 = F_47 ( V_37 , V_43 , false ) ;
if ( F_48 ( V_51 ) )
goto V_47;
if ( ! V_51 ) {
if ( F_49 ( & V_2 -> V_46 , V_37 ) )
goto V_47;
goto V_52;
}
F_50 ( V_37 ) ;
while ( V_51 ) {
struct V_36 * V_53 = V_51 -> V_32 ;
V_51 -> V_32 = NULL ;
if ( F_49 ( & V_2 -> V_46 , V_51 ) ) {
F_51 ( V_51 ) ;
F_52 ( V_53 ) ;
break;
}
V_51 = V_53 ;
}
} else {
if ( V_37 -> V_54 == V_55 &&
! ( V_43 & V_56 ) &&
F_53 ( V_37 ) )
goto V_47;
if ( F_49 ( & V_2 -> V_46 , V_37 ) )
goto V_47;
}
V_52:
F_54 ( F_55 ( & V_2 -> V_30 ) , V_57 | V_58 | V_59 ) ;
return V_60 ;
V_47:
F_56 ( V_20 , 0 , 0 , 0 ) ;
F_51 ( V_37 ) ;
return V_60 ;
}
static int F_57 ( struct V_17 * V_20 )
{
int V_61 = - V_62 ;
F_58 ( & V_63 ) ;
V_61 = F_59 ( & V_64 , V_20 , 1 , V_65 , V_66 ) ;
if ( V_61 >= 0 ) {
V_20 -> V_67 = V_61 ;
} else if ( V_61 == - V_68 ) {
F_60 ( V_20 -> V_15 , L_1 ) ;
V_61 = - V_9 ;
}
F_61 ( & V_63 ) ;
return V_61 < 0 ? V_61 : 0 ;
}
static void F_62 ( struct V_17 * V_20 )
{
F_58 ( & V_63 ) ;
if ( V_20 -> V_67 ) {
F_63 ( & V_64 , V_20 -> V_67 ) ;
V_20 -> V_67 = 0 ;
}
F_61 ( & V_63 ) ;
}
static struct V_14 * F_64 ( int V_67 )
{
struct V_14 * V_15 = NULL ;
struct V_17 * V_20 ;
F_58 ( & V_63 ) ;
V_20 = F_65 ( & V_64 , V_67 ) ;
if ( V_20 ) {
V_15 = V_20 -> V_15 ;
F_66 ( V_15 ) ;
}
F_61 ( & V_63 ) ;
return V_15 ;
}
static int F_67 ( struct V_69 * V_70 ,
struct V_14 * V_15 ,
struct V_71 * V_72 [] ,
struct V_71 * V_73 [] )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
int V_21 ;
F_68 ( & V_20 -> V_33 ) ;
V_20 -> V_50 = V_74 ;
V_21 = F_69 ( V_15 , F_43 , V_20 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_70 ( V_70 , V_15 , V_72 , V_73 ) ;
if ( V_21 ) {
F_71 ( V_15 ) ;
return V_21 ;
}
return 0 ;
}
static void F_72 ( struct V_14 * V_15 ,
struct V_75 * V_76 )
{
F_71 ( V_15 ) ;
F_41 ( V_15 ) ;
F_73 ( V_15 , V_76 ) ;
}
static void F_74 ( struct V_14 * V_15 )
{
F_75 ( V_15 ) ;
V_15 -> V_77 = V_78 ;
}
static void F_76 ( struct V_79 * V_30 )
{
T_7 * V_80 ;
if ( ! F_77 ( V_30 ) ||
! F_78 ( V_81 , & V_30 -> V_82 -> V_3 ) )
return;
V_80 = F_55 ( V_30 ) ;
if ( V_80 && F_79 ( V_80 ) )
F_54 ( V_80 , V_83 | V_84 | V_85 ) ;
}
static void F_80 ( struct V_79 * V_30 )
{
struct V_1 * V_2 = F_81 ( V_30 , struct V_1 , V_30 ) ;
F_82 ( & V_2 -> V_46 ) ;
}
static int F_83 ( struct V_86 * V_86 , struct V_19 * V_19 )
{
struct V_69 * V_69 = V_87 -> V_88 -> V_89 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_21 = - V_90 ;
F_29 () ;
V_15 = F_64 ( F_84 ( V_86 ) ) ;
if ( ! V_15 )
goto V_21;
V_21 = - V_62 ;
V_2 = (struct V_1 * ) F_85 ( V_69 , V_91 , V_66 ,
& V_92 , 0 ) ;
if ( ! V_2 )
goto V_21;
F_27 ( V_2 -> V_79 . V_93 , & V_2 -> V_93 ) ;
F_86 ( & V_2 -> V_93 . V_94 ) ;
V_2 -> V_79 . type = V_95 ;
V_2 -> V_79 . V_96 = V_97 ;
V_2 -> V_79 . V_19 = V_19 ;
V_2 -> V_79 . V_98 = & V_99 ;
F_87 ( & V_2 -> V_79 , & V_2 -> V_30 ) ;
V_2 -> V_30 . V_100 = F_76 ;
V_2 -> V_30 . V_101 = F_80 ;
V_2 -> V_3 = V_49 | V_102 | V_103 ;
V_2 -> V_104 = sizeof( struct V_105 ) ;
if ( ( V_15 -> V_43 & V_106 ) && ( V_15 -> V_43 & V_107 ) )
F_88 ( & V_2 -> V_30 , V_108 ) ;
V_21 = - V_62 ;
if ( F_89 ( & V_2 -> V_46 , V_15 -> V_77 , V_66 ) )
goto V_109;
V_21 = F_21 ( V_15 , V_19 , V_2 ) ;
if ( V_21 )
goto V_110;
F_90 ( V_15 ) ;
F_32 () ;
return V_21 ;
V_110:
F_82 ( & V_2 -> V_46 ) ;
V_109:
F_30 ( & V_2 -> V_30 ) ;
V_21:
if ( V_15 )
F_90 ( V_15 ) ;
F_32 () ;
return V_21 ;
}
static int F_91 ( struct V_86 * V_86 , struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
F_28 ( V_2 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_19 * V_19 , T_8 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
unsigned int V_111 = V_112 ;
if ( ! V_2 )
goto V_23;
V_111 = 0 ;
F_93 ( V_19 , & V_2 -> V_93 . V_94 , V_94 ) ;
if ( ! F_94 ( & V_2 -> V_46 ) )
V_111 |= V_57 | V_58 ;
if ( F_77 ( & V_2 -> V_30 ) ||
( ! F_95 ( V_81 , & V_2 -> V_79 . V_3 ) &&
F_77 ( & V_2 -> V_30 ) ) )
V_111 |= V_83 | V_84 ;
V_23:
return V_111 ;
}
static inline struct V_36 * F_96 ( struct V_79 * V_30 , T_9 V_113 ,
T_9 V_114 , T_9 V_115 ,
int V_116 , int * V_21 )
{
struct V_36 * V_37 ;
if ( V_113 + V_114 < V_117 || ! V_115 )
V_115 = V_114 ;
V_37 = F_97 ( V_30 , V_113 + V_115 , V_114 - V_115 , V_116 ,
V_21 , 0 ) ;
if ( ! V_37 )
return NULL ;
F_98 ( V_37 , V_113 ) ;
F_99 ( V_37 , V_115 ) ;
V_37 -> V_118 = V_114 - V_115 ;
V_37 -> V_114 += V_114 - V_115 ;
return V_37 ;
}
static T_10 F_100 ( struct V_1 * V_2 , struct V_119 * V_120 ,
struct V_121 * V_122 , int V_116 )
{
int V_123 = F_101 ( V_124 ) ;
struct V_36 * V_37 ;
struct V_17 * V_20 ;
unsigned long V_125 = F_102 ( V_122 ) ;
unsigned long V_114 = V_125 ;
int V_21 ;
struct V_105 V_126 = { 0 } ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_129 ;
bool V_130 = false ;
T_9 V_115 ;
if ( V_2 -> V_3 & V_49 ) {
V_127 = F_103 ( V_2 -> V_104 ) ;
V_21 = - V_9 ;
if ( V_114 < V_127 )
goto V_21;
V_114 -= V_127 ;
V_21 = - V_7 ;
if ( ! F_104 ( & V_126 , sizeof( V_126 ) , V_122 ) )
goto V_21;
F_105 ( V_122 , V_127 - sizeof( V_126 ) ) ;
if ( ( V_126 . V_3 & V_131 ) &&
F_8 ( V_2 , V_126 . V_132 ) +
F_8 ( V_2 , V_126 . V_133 ) + 2 >
F_8 ( V_2 , V_126 . V_134 ) )
V_126 . V_134 = F_10 ( V_2 ,
F_8 ( V_2 , V_126 . V_132 ) +
F_8 ( V_2 , V_126 . V_133 ) + 2 ) ;
V_21 = - V_9 ;
if ( F_8 ( V_2 , V_126 . V_134 ) > V_114 )
goto V_21;
}
V_21 = - V_9 ;
if ( F_40 ( V_114 < V_48 ) )
goto V_21;
if ( V_120 && V_120 -> V_135 && F_106 ( & V_2 -> V_30 , V_108 ) ) {
struct V_121 V_136 ;
V_128 = V_126 . V_134 ?
F_8 ( V_2 , V_126 . V_134 ) : V_137 ;
if ( V_128 > V_123 )
V_128 = V_123 ;
else if ( V_128 < V_48 )
V_128 = V_48 ;
V_115 = V_128 ;
V_136 = * V_122 ;
F_105 ( & V_136 , V_128 ) ;
if ( F_107 ( & V_136 , V_138 ) <= V_139 )
V_130 = true ;
}
if ( ! V_130 ) {
V_128 = V_114 ;
V_115 = F_8 ( V_2 , V_126 . V_134 ) ;
if ( V_115 > V_123 )
V_115 = V_123 ;
else if ( V_115 < V_48 )
V_115 = V_48 ;
}
V_37 = F_96 ( & V_2 -> V_30 , V_124 , V_128 ,
V_115 , V_116 , & V_21 ) ;
if ( ! V_37 )
goto V_21;
if ( V_130 )
V_21 = F_108 ( V_37 , V_122 ) ;
else
V_21 = F_109 ( V_37 , 0 , V_122 , V_114 ) ;
if ( V_21 )
goto V_140;
F_110 ( V_37 , V_48 ) ;
F_111 ( V_37 ) ;
V_37 -> V_141 = F_112 ( V_37 ) -> V_142 ;
if ( V_127 ) {
V_21 = F_113 ( V_37 , & V_126 ,
F_7 ( V_2 ) ) ;
if ( V_21 )
goto V_140;
}
F_114 ( V_37 , V_48 ) ;
if ( ( V_37 -> V_141 == F_115 ( V_143 ) ||
V_37 -> V_141 == F_115 ( V_144 ) ) &&
F_116 ( V_37 , V_37 -> V_141 , & V_129 ) != 0 )
F_110 ( V_37 , V_129 ) ;
F_117 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_130 ) {
F_118 ( V_37 ) -> V_145 = V_120 -> V_135 ;
F_118 ( V_37 ) -> V_146 |= V_147 ;
F_118 ( V_37 ) -> V_146 |= V_148 ;
} else if ( V_120 && V_120 -> V_135 ) {
struct V_149 * V_150 = V_120 -> V_135 ;
V_150 -> V_151 ( V_150 , false ) ;
}
if ( V_20 ) {
V_37 -> V_15 = V_20 -> V_15 ;
F_119 ( V_37 ) ;
} else {
F_51 ( V_37 ) ;
}
F_120 () ;
return V_125 ;
V_140:
F_51 ( V_37 ) ;
V_21:
F_117 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_20 )
F_121 ( V_20 -> V_152 -> V_153 ) ;
F_120 () ;
return V_21 ;
}
static T_10 F_122 ( struct V_154 * V_155 , struct V_121 * V_122 )
{
struct V_19 * V_19 = V_155 -> V_156 ;
struct V_1 * V_2 = V_19 -> V_31 ;
return F_100 ( V_2 , NULL , V_122 , V_19 -> V_157 & V_158 ) ;
}
static T_10 F_123 ( struct V_1 * V_2 ,
const struct V_36 * V_37 ,
struct V_121 * V_159 )
{
int V_160 ;
int V_127 = 0 ;
int V_161 = 0 ;
int V_162 ;
if ( V_2 -> V_3 & V_49 ) {
struct V_105 V_126 ;
V_127 = F_103 ( V_2 -> V_104 ) ;
if ( F_102 ( V_159 ) < V_127 )
return - V_9 ;
if ( F_124 ( V_37 , & V_126 ,
F_7 ( V_2 ) , true ) )
F_125 () ;
if ( F_126 ( & V_126 , sizeof( V_126 ) , V_159 ) !=
sizeof( V_126 ) )
return - V_7 ;
F_105 ( V_159 , V_127 - sizeof( V_126 ) ) ;
}
V_162 = V_127 ;
V_162 += V_37 -> V_114 ;
if ( F_127 ( V_37 ) ) {
struct {
T_11 V_163 ;
T_11 V_164 ;
} V_165 ;
V_165 . V_163 = V_37 -> V_166 ;
V_165 . V_164 = F_115 ( F_128 ( V_37 ) ) ;
V_161 = F_129 ( struct V_167 , V_163 ) ;
V_162 += V_168 ;
V_160 = F_130 ( V_37 , 0 , V_159 , V_161 ) ;
if ( V_160 || ! F_102 ( V_159 ) )
goto V_169;
V_160 = F_126 ( & V_165 , sizeof( V_165 ) , V_159 ) ;
if ( V_160 != sizeof( V_165 ) || ! F_102 ( V_159 ) )
goto V_169;
}
V_160 = F_130 ( V_37 , V_161 , V_159 ,
V_37 -> V_114 - V_161 ) ;
V_169:
return V_160 ? V_160 : V_162 ;
}
static T_10 F_131 ( struct V_1 * V_2 ,
struct V_121 * V_170 ,
int V_116 )
{
F_132 ( V_94 ) ;
struct V_36 * V_37 ;
T_10 V_160 = 0 ;
if ( ! F_102 ( V_170 ) )
return 0 ;
while ( 1 ) {
if ( ! V_116 )
F_133 ( F_55 ( & V_2 -> V_30 ) , & V_94 ,
V_171 ) ;
V_37 = F_134 ( & V_2 -> V_46 ) ;
if ( V_37 )
break;
if ( V_116 ) {
V_160 = - V_172 ;
break;
}
if ( F_135 ( V_87 ) ) {
V_160 = - V_173 ;
break;
}
F_136 () ;
}
if ( ! V_116 )
F_137 ( F_55 ( & V_2 -> V_30 ) , & V_94 ) ;
if ( V_37 ) {
V_160 = F_123 ( V_2 , V_37 , V_170 ) ;
if ( F_40 ( V_160 < 0 ) )
F_51 ( V_37 ) ;
else
F_50 ( V_37 ) ;
}
return V_160 ;
}
static T_10 F_138 ( struct V_154 * V_155 , struct V_121 * V_170 )
{
struct V_19 * V_19 = V_155 -> V_156 ;
struct V_1 * V_2 = V_19 -> V_31 ;
T_10 V_114 = F_102 ( V_170 ) , V_160 ;
V_160 = F_131 ( V_2 , V_170 , V_19 -> V_157 & V_158 ) ;
V_160 = F_139 ( T_10 , V_160 , V_114 ) ;
if ( V_160 > 0 )
V_155 -> V_174 = V_160 ;
return V_160 ;
}
static struct V_17 * F_140 ( struct V_1 * V_2 )
{
struct V_17 * V_20 ;
F_19 () ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( V_20 )
F_66 ( V_20 -> V_15 ) ;
return V_20 ;
}
static void F_141 ( struct V_17 * V_20 )
{
F_90 ( V_20 -> V_15 ) ;
}
static int F_142 ( struct V_19 * V_19 , unsigned int V_3 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
int V_160 ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 )
return - V_9 ;
if ( V_3 & V_175 )
V_160 = F_17 ( V_20 -> V_15 , V_19 , V_2 ) ;
else if ( V_3 & V_176 )
V_160 = F_24 ( V_2 ) ;
else
V_160 = - V_9 ;
F_141 ( V_20 ) ;
return V_160 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned long V_177 )
{
struct V_17 * V_20 ;
T_6 V_43 ;
T_6 V_178 = 0 ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( ! V_20 )
return - V_179 ;
V_43 = V_20 -> V_15 -> V_43 ;
if ( V_177 & V_180 ) {
V_178 = V_181 ;
if ( V_177 & ( V_182 | V_183 ) ) {
if ( V_177 & V_184 )
V_178 |= V_185 ;
if ( V_177 & V_182 )
V_178 |= V_186 ;
if ( V_177 & V_183 )
V_178 |= V_187 ;
}
if ( V_177 & V_188 )
V_178 |= V_189 ;
}
if ( V_178 & ( V_186 | V_187 | V_189 ) )
V_43 |= V_190 ;
else
V_43 &= ~ V_190 ;
V_20 -> V_50 = V_178 ;
V_20 -> V_191 = V_43 ;
F_144 ( V_20 -> V_15 ) ;
return 0 ;
}
static long F_145 ( struct V_19 * V_19 , unsigned int V_192 ,
unsigned long V_177 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
void T_1 * V_8 = ( void T_1 * ) V_177 ;
struct V_193 T_1 * V_194 = V_8 ;
unsigned int T_1 * V_195 = V_8 ;
unsigned short V_196 ;
int T_1 * V_5 = V_8 ;
struct V_197 V_198 ;
int V_6 ;
int V_160 ;
switch ( V_192 ) {
case V_199 :
if ( F_6 ( V_196 , & V_194 -> V_200 ) )
return - V_7 ;
V_160 = 0 ;
if ( ( V_196 & ~ V_201 ) != ( V_102 | V_103 ) )
V_160 = - V_9 ;
else
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_201 ) | V_196 ;
return V_160 ;
case V_202 :
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_179 ;
}
V_160 = 0 ;
V_196 = V_2 -> V_3 ;
if ( F_146 ( & V_194 -> V_203 , V_20 -> V_15 -> V_204 , V_205 ) ||
F_4 ( V_196 , & V_194 -> V_200 ) )
V_160 = - V_7 ;
F_141 ( V_20 ) ;
F_32 () ;
return V_160 ;
case V_206 :
if ( F_6 ( V_196 , & V_194 -> V_200 ) )
return - V_7 ;
F_29 () ;
V_160 = F_142 ( V_19 , V_196 ) ;
F_32 () ;
return V_160 ;
case V_207 :
if ( F_4 ( V_103 | V_102 | V_201 , V_195 ) )
return - V_7 ;
return 0 ;
case V_208 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
V_2 -> V_30 . V_209 = V_6 ;
return 0 ;
case V_210 :
V_6 = V_2 -> V_104 ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_211 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 < ( int ) sizeof( struct V_105 ) )
return - V_9 ;
V_2 -> V_104 = V_6 ;
return 0 ;
case V_212 :
V_6 = ! ! ( V_2 -> V_3 & V_10 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_213 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
case V_214 :
return F_3 ( V_2 , V_5 ) ;
case V_215 :
return F_5 ( V_2 , V_5 ) ;
case V_216 :
if ( V_177 & ~ ( V_180 | V_182 | V_183 |
V_184 | V_188 ) )
return - V_9 ;
F_29 () ;
V_160 = F_143 ( V_2 , V_177 ) ;
F_32 () ;
return V_160 ;
case V_217 :
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_179 ;
}
V_160 = 0 ;
V_196 = V_20 -> V_15 -> type ;
if ( F_146 ( & V_194 -> V_203 , V_20 -> V_15 -> V_204 , V_205 ) ||
F_146 ( & V_194 -> V_218 . V_219 , V_20 -> V_15 -> V_220 , V_221 ) ||
F_4 ( V_196 , & V_194 -> V_218 . V_222 ) )
V_160 = - V_7 ;
F_141 ( V_20 ) ;
F_32 () ;
return V_160 ;
case V_223 :
if ( F_147 ( & V_198 , & V_194 -> V_218 , sizeof( V_198 ) ) )
return - V_7 ;
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_179 ;
}
V_160 = F_148 ( V_20 -> V_15 , & V_198 ) ;
F_141 ( V_20 ) ;
F_32 () ;
return V_160 ;
default:
return - V_9 ;
}
}
static long F_149 ( struct V_19 * V_19 , unsigned int V_192 ,
unsigned long V_177 )
{
return F_145 ( V_19 , V_192 , ( unsigned long ) F_150 ( V_177 ) ) ;
}
static int F_151 ( struct V_224 * V_79 , struct V_119 * V_120 ,
T_9 V_125 )
{
struct V_1 * V_2 = F_81 ( V_79 , struct V_1 , V_79 ) ;
return F_100 ( V_2 , V_120 , & V_120 -> V_225 , V_120 -> V_226 & V_227 ) ;
}
static int F_152 ( struct V_224 * V_79 , struct V_119 * V_120 ,
T_9 V_125 , int V_3 )
{
struct V_1 * V_2 = F_81 ( V_79 , struct V_1 , V_79 ) ;
int V_160 ;
if ( V_3 & ~ ( V_227 | V_228 ) )
return - V_9 ;
V_160 = F_131 ( V_2 , & V_120 -> V_225 , V_3 & V_227 ) ;
if ( V_160 > V_125 ) {
V_120 -> V_226 |= V_228 ;
V_160 = V_3 & V_228 ? V_160 : V_125 ;
}
return V_160 ;
}
static int F_153 ( struct V_224 * V_79 )
{
struct V_1 * V_2 = F_81 ( V_79 , struct V_1 ,
V_79 ) ;
return F_154 ( & V_2 -> V_46 ) ;
}
struct V_224 * F_155 ( struct V_19 * V_19 )
{
struct V_1 * V_2 ;
if ( V_19 -> V_229 != & V_230 )
return F_156 ( - V_9 ) ;
V_2 = V_19 -> V_31 ;
if ( ! V_2 )
return F_156 ( - V_231 ) ;
return & V_2 -> V_79 ;
}
static int F_157 ( struct V_17 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_1 * V_2 ;
struct V_46 * * V_232 ;
int V_233 = V_20 -> V_27 ;
int V_160 , V_136 = 0 ;
V_232 = F_158 ( sizeof *V_232 * V_233 , V_66 ) ;
if ( ! V_232 )
return - V_62 ;
F_159 (q, &vlan->queue_list, next)
V_232 [ V_136 ++ ] = & V_2 -> V_46 ;
V_160 = F_160 ( V_232 , V_233 ,
V_15 -> V_77 , V_66 ) ;
F_161 ( V_232 ) ;
return V_160 ;
}
static int F_162 ( struct V_234 * V_235 ,
unsigned long V_236 , void * V_237 )
{
struct V_14 * V_15 = F_163 ( V_237 ) ;
struct V_17 * V_20 ;
struct V_12 * V_238 ;
T_12 V_239 ;
int V_21 ;
char V_240 [ V_205 ] ;
if ( V_15 -> V_241 != & V_242 )
return V_243 ;
snprintf ( V_240 , V_205 , L_2 , V_15 -> V_244 ) ;
V_20 = F_18 ( V_15 ) ;
switch ( V_236 ) {
case V_245 :
V_21 = F_57 ( V_20 ) ;
if ( V_21 )
return F_164 ( V_21 ) ;
V_239 = F_165 ( F_166 ( V_246 ) , V_20 -> V_67 ) ;
V_238 = F_167 ( & V_247 , & V_15 -> V_15 , V_239 ,
V_15 , V_240 ) ;
if ( F_48 ( V_238 ) ) {
F_62 ( V_20 ) ;
return F_164 ( F_168 ( V_238 ) ) ;
}
V_21 = F_169 ( & V_15 -> V_15 . V_248 , & V_238 -> V_248 ,
V_240 ) ;
if ( V_21 )
return F_164 ( V_21 ) ;
break;
case V_249 :
if ( V_20 -> V_67 == 0 )
break;
F_170 ( & V_15 -> V_15 . V_248 , V_240 ) ;
V_239 = F_165 ( F_166 ( V_246 ) , V_20 -> V_67 ) ;
F_171 ( & V_247 , V_239 ) ;
F_62 ( V_20 ) ;
break;
case V_250 :
if ( F_157 ( V_20 ) )
return V_251 ;
break;
}
return V_243 ;
}
static int F_172 ( void )
{
int V_21 ;
V_21 = F_173 ( & V_246 , 0 ,
V_65 , L_3 ) ;
if ( V_21 )
goto V_252;
F_174 ( & V_253 , & V_230 ) ;
V_21 = F_175 ( & V_253 , V_246 , V_65 ) ;
if ( V_21 )
goto V_254;
V_21 = F_176 ( & V_247 ) ;
if ( V_21 )
goto V_255;
V_21 = F_177 ( & V_256 ) ;
if ( V_21 )
goto V_257;
V_21 = F_178 ( & V_242 ) ;
if ( V_21 )
goto V_258;
return 0 ;
V_258:
F_179 ( & V_256 ) ;
V_257:
F_180 ( & V_247 ) ;
V_255:
F_181 ( & V_253 ) ;
V_254:
F_182 ( V_246 , V_65 ) ;
V_252:
return V_21 ;
}
static void F_183 ( void )
{
F_184 ( & V_242 ) ;
F_179 ( & V_256 ) ;
F_180 ( & V_247 ) ;
F_181 ( & V_253 ) ;
F_182 ( V_246 , V_65 ) ;
F_185 ( & V_64 ) ;
}
