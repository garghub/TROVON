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
static struct V_12 * F_12 ( const struct V_13 * V_14 )
{
return F_13 ( V_14 -> V_15 ) ;
}
static int F_14 ( struct V_12 * V_16 , struct V_17 * V_17 ,
struct V_1 * V_2 )
{
int V_18 = - V_9 ;
F_15 () ;
if ( V_2 -> V_19 )
goto V_20;
V_18 = 0 ;
F_16 ( V_16 -> V_21 [ V_16 -> V_22 ] , V_2 ) ;
V_2 -> V_23 = V_16 -> V_22 ;
V_2 -> V_19 = true ;
V_16 -> V_22 ++ ;
V_20:
return V_18 ;
}
static int F_17 ( struct V_12 * V_16 , struct V_17 * V_17 ,
struct V_1 * V_2 )
{
if ( V_16 -> V_24 == V_25 )
return - V_26 ;
F_16 ( V_2 -> V_16 , V_16 ) ;
F_16 ( V_16 -> V_21 [ V_16 -> V_22 ] , V_2 ) ;
F_18 ( & V_2 -> V_27 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_23 = V_16 -> V_22 ;
V_2 -> V_19 = true ;
V_17 -> V_28 = V_2 ;
F_19 ( & V_2 -> V_29 , & V_16 -> V_30 ) ;
V_16 -> V_22 ++ ;
V_16 -> V_24 ++ ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_16 ;
struct V_1 * V_31 ;
F_15 () ;
if ( ! V_2 -> V_19 )
return - V_9 ;
V_16 = F_21 ( V_2 -> V_16 ) ;
if ( V_16 ) {
int V_32 = V_2 -> V_23 ;
F_22 ( V_32 >= V_16 -> V_22 ) ;
V_31 = F_21 ( V_16 -> V_21 [ V_16 -> V_22 - 1 ] ) ;
V_31 -> V_23 = V_32 ;
F_16 ( V_16 -> V_21 [ V_32 ] , V_31 ) ;
F_23 ( V_16 -> V_21 [ V_16 -> V_22 - 1 ] , NULL ) ;
V_2 -> V_19 = false ;
V_16 -> V_22 -- ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_16 ;
F_25 () ;
V_16 = F_21 ( V_2 -> V_16 ) ;
if ( V_16 ) {
if ( V_2 -> V_19 )
F_22 ( F_20 ( V_2 ) ) ;
V_16 -> V_24 -- ;
F_23 ( V_2 -> V_16 , NULL ) ;
F_26 ( & V_2 -> V_27 ) ;
F_27 ( & V_2 -> V_29 ) ;
}
F_28 () ;
F_29 () ;
F_26 ( & V_2 -> V_27 ) ;
}
static struct V_1 * F_30 ( struct V_12 * V_16 ,
struct V_33 * V_34 )
{
struct V_1 * V_35 = NULL ;
int V_22 = F_31 ( V_16 -> V_22 ) ;
T_4 V_36 ;
if ( ! V_22 )
goto V_20;
if ( V_22 == 1 )
goto V_37;
V_36 = F_32 ( V_34 ) ;
if ( V_36 ) {
V_35 = F_13 ( V_16 -> V_21 [ V_36 % V_22 ] ) ;
goto V_20;
}
if ( F_33 ( F_34 ( V_34 ) ) ) {
V_36 = F_35 ( V_34 ) ;
while ( F_36 ( V_36 >= V_22 ) )
V_36 -= V_22 ;
V_35 = F_13 ( V_16 -> V_21 [ V_36 ] ) ;
goto V_20;
}
V_37:
V_35 = F_13 ( V_16 -> V_21 [ 0 ] ) ;
V_20:
return V_35 ;
}
void F_37 ( struct V_12 * V_16 )
{
struct V_1 * V_2 , * V_38 ;
F_15 () ;
F_38 (q, tmp, &tap->queue_list, next) {
F_27 ( & V_2 -> V_29 ) ;
F_23 ( V_2 -> V_16 , NULL ) ;
if ( V_2 -> V_19 )
V_16 -> V_22 -- ;
V_16 -> V_24 -- ;
F_26 ( & V_2 -> V_27 ) ;
}
F_22 ( V_16 -> V_22 ) ;
F_22 ( V_16 -> V_24 ) ;
V_16 -> V_22 = V_25 ;
}
T_5 F_39 ( struct V_33 * * V_39 )
{
struct V_33 * V_34 = * V_39 ;
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_12 * V_16 ;
struct V_1 * V_2 ;
T_6 V_40 = V_41 ;
V_16 = F_12 ( V_14 ) ;
if ( ! V_16 )
return V_42 ;
V_2 = F_30 ( V_16 , V_34 ) ;
if ( ! V_2 )
return V_42 ;
if ( F_40 ( & V_2 -> V_43 ) )
goto V_44;
F_41 ( V_34 , V_45 ) ;
if ( V_2 -> V_3 & V_46 )
V_40 |= V_16 -> V_47 ;
if ( F_42 ( V_34 , V_40 ) ) {
struct V_33 * V_48 = F_43 ( V_34 , V_40 , false ) ;
if ( F_44 ( V_48 ) )
goto V_44;
if ( ! V_48 ) {
if ( F_45 ( & V_2 -> V_43 , V_34 ) )
goto V_44;
goto V_49;
}
F_46 ( V_34 ) ;
while ( V_48 ) {
struct V_33 * V_50 = V_48 -> V_29 ;
V_48 -> V_29 = NULL ;
if ( F_45 ( & V_2 -> V_43 , V_48 ) ) {
F_47 ( V_48 ) ;
F_48 ( V_50 ) ;
break;
}
V_48 = V_50 ;
}
} else {
if ( V_34 -> V_51 == V_52 &&
! ( V_40 & V_53 ) &&
F_49 ( V_34 ) )
goto V_44;
if ( F_45 ( & V_2 -> V_43 , V_34 ) )
goto V_44;
}
V_49:
F_50 ( F_51 ( & V_2 -> V_27 ) , V_54 | V_55 | V_56 ) ;
return V_57 ;
V_44:
if ( V_16 -> V_58 )
V_16 -> V_58 ( V_16 ) ;
F_47 ( V_34 ) ;
return V_57 ;
}
static struct V_59 * F_52 ( int V_60 )
{
struct V_59 * V_61 ;
F_53 (tap_major, &major_list, next) {
if ( V_61 -> V_60 == V_60 )
return V_61 ;
}
return NULL ;
}
int F_54 ( T_7 V_60 , struct V_12 * V_16 )
{
int V_62 = - V_63 ;
struct V_59 * V_61 ;
F_55 () ;
V_61 = F_52 ( F_56 ( V_60 ) ) ;
if ( ! V_61 ) {
V_62 = - V_9 ;
goto V_64;
}
F_57 ( & V_61 -> V_65 ) ;
V_62 = F_58 ( & V_61 -> V_66 , V_16 , 1 , V_67 , V_68 ) ;
if ( V_62 >= 0 ) {
V_16 -> V_69 = V_62 ;
} else if ( V_62 == - V_70 ) {
F_59 ( V_16 -> V_14 , L_1 ) ;
V_62 = - V_9 ;
}
F_60 ( & V_61 -> V_65 ) ;
V_64:
F_61 () ;
return V_62 < 0 ? V_62 : 0 ;
}
void F_62 ( T_7 V_60 , struct V_12 * V_16 )
{
struct V_59 * V_61 ;
F_55 () ;
V_61 = F_52 ( F_56 ( V_60 ) ) ;
if ( ! V_61 ) {
goto V_64;
}
F_57 ( & V_61 -> V_65 ) ;
if ( V_16 -> V_69 ) {
F_63 ( & V_61 -> V_66 , V_16 -> V_69 ) ;
V_16 -> V_69 = 0 ;
}
F_60 ( & V_61 -> V_65 ) ;
V_64:
F_61 () ;
}
static struct V_12 * F_64 ( int V_60 , int V_69 )
{
struct V_13 * V_14 = NULL ;
struct V_12 * V_16 ;
struct V_59 * V_61 ;
F_55 () ;
V_61 = F_52 ( V_60 ) ;
if ( ! V_61 ) {
V_16 = NULL ;
goto V_64;
}
F_57 ( & V_61 -> V_65 ) ;
V_16 = F_65 ( & V_61 -> V_66 , V_69 ) ;
if ( V_16 ) {
V_14 = V_16 -> V_14 ;
F_66 ( V_14 ) ;
}
F_60 ( & V_61 -> V_65 ) ;
V_64:
F_61 () ;
return V_16 ;
}
static void F_67 ( struct V_71 * V_27 )
{
T_8 * V_72 ;
if ( ! F_68 ( V_27 ) ||
! F_69 ( V_73 , & V_27 -> V_74 -> V_3 ) )
return;
V_72 = F_51 ( V_27 ) ;
if ( V_72 && F_70 ( V_72 ) )
F_50 ( V_72 , V_75 | V_76 | V_77 ) ;
}
static void F_71 ( struct V_71 * V_27 )
{
struct V_1 * V_2 = F_72 ( V_27 , struct V_1 , V_27 ) ;
F_73 ( & V_2 -> V_43 ) ;
}
static int F_74 ( struct V_78 * V_78 , struct V_17 * V_17 )
{
struct V_79 * V_79 = V_80 -> V_81 -> V_82 ;
struct V_12 * V_16 ;
struct V_1 * V_2 ;
int V_18 = - V_83 ;
F_25 () ;
V_16 = F_64 ( F_75 ( V_78 ) , F_76 ( V_78 ) ) ;
if ( ! V_16 )
goto V_18;
V_18 = - V_63 ;
V_2 = (struct V_1 * ) F_77 ( V_79 , V_84 , V_68 ,
& V_85 , 0 ) ;
if ( ! V_2 )
goto V_18;
F_23 ( V_2 -> V_71 . V_86 , & V_2 -> V_86 ) ;
F_78 ( & V_2 -> V_86 . V_87 ) ;
V_2 -> V_71 . type = V_88 ;
V_2 -> V_71 . V_89 = V_90 ;
V_2 -> V_71 . V_17 = V_17 ;
V_2 -> V_71 . V_91 = & V_92 ;
F_79 ( & V_2 -> V_71 , & V_2 -> V_27 ) ;
V_2 -> V_27 . V_93 = F_67 ;
V_2 -> V_27 . V_94 = F_71 ;
V_2 -> V_3 = V_46 | V_95 | V_96 ;
V_2 -> V_97 = sizeof( struct V_98 ) ;
if ( ( V_16 -> V_14 -> V_40 & V_99 ) && ( V_16 -> V_14 -> V_40 & V_100 ) )
F_80 ( & V_2 -> V_27 , V_101 ) ;
V_18 = - V_63 ;
if ( F_81 ( & V_2 -> V_43 , V_16 -> V_14 -> V_102 , V_68 ) )
goto V_103;
V_18 = F_17 ( V_16 , V_17 , V_2 ) ;
if ( V_18 )
goto V_104;
F_82 ( V_16 -> V_14 ) ;
F_28 () ;
return V_18 ;
V_104:
F_73 ( & V_2 -> V_43 ) ;
V_103:
F_26 ( & V_2 -> V_27 ) ;
V_18:
if ( V_16 )
F_82 ( V_16 -> V_14 ) ;
F_28 () ;
return V_18 ;
}
static int F_83 ( struct V_78 * V_78 , struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_28 ;
F_24 ( V_2 ) ;
return 0 ;
}
static unsigned int F_84 ( struct V_17 * V_17 , T_9 * V_87 )
{
struct V_1 * V_2 = V_17 -> V_28 ;
unsigned int V_105 = V_106 ;
if ( ! V_2 )
goto V_20;
V_105 = 0 ;
F_85 ( V_17 , & V_2 -> V_86 . V_87 , V_87 ) ;
if ( ! F_86 ( & V_2 -> V_43 ) )
V_105 |= V_54 | V_55 ;
if ( F_68 ( & V_2 -> V_27 ) ||
( ! F_87 ( V_73 , & V_2 -> V_71 . V_3 ) &&
F_68 ( & V_2 -> V_27 ) ) )
V_105 |= V_75 | V_76 ;
V_20:
return V_105 ;
}
static inline struct V_33 * F_88 ( struct V_71 * V_27 , T_10 V_107 ,
T_10 V_108 , T_10 V_109 ,
int V_110 , int * V_18 )
{
struct V_33 * V_34 ;
if ( V_107 + V_108 < V_111 || ! V_109 )
V_109 = V_108 ;
V_34 = F_89 ( V_27 , V_107 + V_109 , V_108 - V_109 , V_110 ,
V_18 , 0 ) ;
if ( ! V_34 )
return NULL ;
F_90 ( V_34 , V_107 ) ;
F_91 ( V_34 , V_109 ) ;
V_34 -> V_112 = V_108 - V_109 ;
V_34 -> V_108 += V_108 - V_109 ;
return V_34 ;
}
static T_11 F_92 ( struct V_1 * V_2 , struct V_113 * V_114 ,
struct V_115 * V_116 , int V_110 )
{
int V_117 = F_93 ( V_118 ) ;
struct V_33 * V_34 ;
struct V_12 * V_16 ;
unsigned long V_119 = F_94 ( V_116 ) ;
unsigned long V_108 = V_119 ;
int V_18 ;
struct V_98 V_120 = { 0 } ;
int V_121 = 0 ;
int V_122 = 0 ;
int V_123 ;
bool V_124 = false ;
T_10 V_109 ;
if ( V_2 -> V_3 & V_46 ) {
V_121 = F_95 ( V_2 -> V_97 ) ;
V_18 = - V_9 ;
if ( V_108 < V_121 )
goto V_18;
V_108 -= V_121 ;
V_18 = - V_7 ;
if ( ! F_96 ( & V_120 , sizeof( V_120 ) , V_116 ) )
goto V_18;
F_97 ( V_116 , V_121 - sizeof( V_120 ) ) ;
if ( ( V_120 . V_3 & V_125 ) &&
F_8 ( V_2 , V_120 . V_126 ) +
F_8 ( V_2 , V_120 . V_127 ) + 2 >
F_8 ( V_2 , V_120 . V_128 ) )
V_120 . V_128 = F_10 ( V_2 ,
F_8 ( V_2 , V_120 . V_126 ) +
F_8 ( V_2 , V_120 . V_127 ) + 2 ) ;
V_18 = - V_9 ;
if ( F_8 ( V_2 , V_120 . V_128 ) > V_108 )
goto V_18;
}
V_18 = - V_9 ;
if ( F_36 ( V_108 < V_45 ) )
goto V_18;
if ( V_114 && V_114 -> V_129 && F_98 ( & V_2 -> V_27 , V_101 ) ) {
struct V_115 V_130 ;
V_122 = V_120 . V_128 ?
F_8 ( V_2 , V_120 . V_128 ) : V_131 ;
if ( V_122 > V_117 )
V_122 = V_117 ;
else if ( V_122 < V_45 )
V_122 = V_45 ;
V_109 = V_122 ;
V_130 = * V_116 ;
F_97 ( & V_130 , V_122 ) ;
if ( F_99 ( & V_130 , V_132 ) <= V_133 )
V_124 = true ;
}
if ( ! V_124 ) {
V_122 = V_108 ;
V_109 = F_8 ( V_2 , V_120 . V_128 ) ;
if ( V_109 > V_117 )
V_109 = V_117 ;
else if ( V_109 < V_45 )
V_109 = V_45 ;
}
V_34 = F_88 ( & V_2 -> V_27 , V_118 , V_122 ,
V_109 , V_110 , & V_18 ) ;
if ( ! V_34 )
goto V_18;
if ( V_124 )
V_18 = F_100 ( V_34 , V_116 ) ;
else
V_18 = F_101 ( V_34 , 0 , V_116 , V_108 ) ;
if ( V_18 )
goto V_134;
F_102 ( V_34 , V_45 ) ;
F_103 ( V_34 ) ;
V_34 -> V_135 = F_104 ( V_34 ) -> V_136 ;
if ( V_121 ) {
V_18 = F_105 ( V_34 , & V_120 ,
F_7 ( V_2 ) ) ;
if ( V_18 )
goto V_134;
}
F_106 ( V_34 , V_45 ) ;
if ( ( V_34 -> V_135 == F_107 ( V_137 ) ||
V_34 -> V_135 == F_107 ( V_138 ) ) &&
F_108 ( V_34 , V_34 -> V_135 , & V_123 ) != 0 )
F_102 ( V_34 , V_123 ) ;
F_55 () ;
V_16 = F_13 ( V_2 -> V_16 ) ;
if ( V_124 ) {
F_109 ( V_34 ) -> V_139 = V_114 -> V_129 ;
F_109 ( V_34 ) -> V_140 |= V_141 ;
F_109 ( V_34 ) -> V_140 |= V_142 ;
} else if ( V_114 && V_114 -> V_129 ) {
struct V_143 * V_144 = V_114 -> V_129 ;
V_144 -> V_145 ( V_144 , false ) ;
}
if ( V_16 ) {
V_34 -> V_14 = V_16 -> V_14 ;
F_110 ( V_34 ) ;
} else {
F_47 ( V_34 ) ;
}
F_61 () ;
return V_119 ;
V_134:
F_47 ( V_34 ) ;
V_18:
F_55 () ;
V_16 = F_13 ( V_2 -> V_16 ) ;
if ( V_16 && V_16 -> V_146 )
V_16 -> V_146 ( V_16 ) ;
F_61 () ;
return V_18 ;
}
static T_11 F_111 ( struct V_147 * V_148 , struct V_115 * V_116 )
{
struct V_17 * V_17 = V_148 -> V_149 ;
struct V_1 * V_2 = V_17 -> V_28 ;
return F_92 ( V_2 , NULL , V_116 , V_17 -> V_150 & V_151 ) ;
}
static T_11 F_112 ( struct V_1 * V_2 ,
const struct V_33 * V_34 ,
struct V_115 * V_152 )
{
int V_153 ;
int V_121 = 0 ;
int V_154 = 0 ;
int V_155 ;
if ( V_2 -> V_3 & V_46 ) {
struct V_98 V_120 ;
V_121 = F_95 ( V_2 -> V_97 ) ;
if ( F_94 ( V_152 ) < V_121 )
return - V_9 ;
if ( F_113 ( V_34 , & V_120 ,
F_7 ( V_2 ) , true ) )
F_114 () ;
if ( F_115 ( & V_120 , sizeof( V_120 ) , V_152 ) !=
sizeof( V_120 ) )
return - V_7 ;
F_97 ( V_152 , V_121 - sizeof( V_120 ) ) ;
}
V_155 = V_121 ;
V_155 += V_34 -> V_108 ;
if ( F_116 ( V_34 ) ) {
struct {
T_12 V_156 ;
T_12 V_157 ;
} V_158 ;
V_158 . V_156 = V_34 -> V_159 ;
V_158 . V_157 = F_107 ( F_117 ( V_34 ) ) ;
V_154 = F_118 ( struct V_160 , V_156 ) ;
V_155 += V_161 ;
V_153 = F_119 ( V_34 , 0 , V_152 , V_154 ) ;
if ( V_153 || ! F_94 ( V_152 ) )
goto V_162;
V_153 = F_115 ( & V_158 , sizeof( V_158 ) , V_152 ) ;
if ( V_153 != sizeof( V_158 ) || ! F_94 ( V_152 ) )
goto V_162;
}
V_153 = F_119 ( V_34 , V_154 , V_152 ,
V_34 -> V_108 - V_154 ) ;
V_162:
return V_153 ? V_153 : V_155 ;
}
static T_11 F_120 ( struct V_1 * V_2 ,
struct V_115 * V_163 ,
int V_110 )
{
F_121 ( V_87 ) ;
struct V_33 * V_34 ;
T_11 V_153 = 0 ;
if ( ! F_94 ( V_163 ) )
return 0 ;
while ( 1 ) {
if ( ! V_110 )
F_122 ( F_51 ( & V_2 -> V_27 ) , & V_87 ,
V_164 ) ;
V_34 = F_123 ( & V_2 -> V_43 ) ;
if ( V_34 )
break;
if ( V_110 ) {
V_153 = - V_165 ;
break;
}
if ( F_124 ( V_80 ) ) {
V_153 = - V_166 ;
break;
}
F_125 () ;
}
if ( ! V_110 )
F_126 ( F_51 ( & V_2 -> V_27 ) , & V_87 ) ;
if ( V_34 ) {
V_153 = F_112 ( V_2 , V_34 , V_163 ) ;
if ( F_36 ( V_153 < 0 ) )
F_47 ( V_34 ) ;
else
F_46 ( V_34 ) ;
}
return V_153 ;
}
static T_11 F_127 ( struct V_147 * V_148 , struct V_115 * V_163 )
{
struct V_17 * V_17 = V_148 -> V_149 ;
struct V_1 * V_2 = V_17 -> V_28 ;
T_11 V_108 = F_94 ( V_163 ) , V_153 ;
V_153 = F_120 ( V_2 , V_163 , V_17 -> V_150 & V_151 ) ;
V_153 = F_128 ( T_11 , V_153 , V_108 ) ;
if ( V_153 > 0 )
V_148 -> V_167 = V_153 ;
return V_153 ;
}
static struct V_12 * F_129 ( struct V_1 * V_2 )
{
struct V_12 * V_16 ;
F_15 () ;
V_16 = F_21 ( V_2 -> V_16 ) ;
if ( V_16 )
F_66 ( V_16 -> V_14 ) ;
return V_16 ;
}
static void F_130 ( struct V_12 * V_16 )
{
F_82 ( V_16 -> V_14 ) ;
}
static int F_131 ( struct V_17 * V_17 , unsigned int V_3 )
{
struct V_1 * V_2 = V_17 -> V_28 ;
struct V_12 * V_16 ;
int V_153 ;
V_16 = F_129 ( V_2 ) ;
if ( ! V_16 )
return - V_9 ;
if ( V_3 & V_168 )
V_153 = F_14 ( V_16 , V_17 , V_2 ) ;
else if ( V_3 & V_169 )
V_153 = F_20 ( V_2 ) ;
else
V_153 = - V_9 ;
F_130 ( V_16 ) ;
return V_153 ;
}
static int F_132 ( struct V_1 * V_2 , unsigned long V_170 )
{
struct V_12 * V_16 ;
T_6 V_40 ;
T_6 V_171 = 0 ;
V_16 = F_21 ( V_2 -> V_16 ) ;
if ( ! V_16 )
return - V_172 ;
V_40 = V_16 -> V_14 -> V_40 ;
if ( V_170 & V_173 ) {
V_171 = V_174 ;
if ( V_170 & ( V_175 | V_176 ) ) {
if ( V_170 & V_177 )
V_171 |= V_178 ;
if ( V_170 & V_175 )
V_171 |= V_179 ;
if ( V_170 & V_176 )
V_171 |= V_180 ;
}
if ( V_170 & V_181 )
V_171 |= V_182 ;
}
if ( V_171 & ( V_179 | V_180 | V_182 ) )
V_40 |= V_183 ;
else
V_40 &= ~ V_183 ;
V_16 -> V_47 = V_171 ;
if ( V_16 -> V_184 )
V_16 -> V_184 ( V_16 , V_40 ) ;
return 0 ;
}
static long F_133 ( struct V_17 * V_17 , unsigned int V_185 ,
unsigned long V_170 )
{
struct V_1 * V_2 = V_17 -> V_28 ;
struct V_12 * V_16 ;
void T_1 * V_8 = ( void T_1 * ) V_170 ;
struct V_186 T_1 * V_187 = V_8 ;
unsigned int T_1 * V_188 = V_8 ;
unsigned short V_189 ;
int T_1 * V_5 = V_8 ;
struct V_190 V_191 ;
int V_6 ;
int V_153 ;
switch ( V_185 ) {
case V_192 :
if ( F_6 ( V_189 , & V_187 -> V_193 ) )
return - V_7 ;
V_153 = 0 ;
if ( ( V_189 & ~ V_194 ) != ( V_95 | V_96 ) )
V_153 = - V_9 ;
else
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_194 ) | V_189 ;
return V_153 ;
case V_195 :
F_25 () ;
V_16 = F_129 ( V_2 ) ;
if ( ! V_16 ) {
F_28 () ;
return - V_172 ;
}
V_153 = 0 ;
V_189 = V_2 -> V_3 ;
if ( F_134 ( & V_187 -> V_196 , V_16 -> V_14 -> V_197 , V_198 ) ||
F_4 ( V_189 , & V_187 -> V_193 ) )
V_153 = - V_7 ;
F_130 ( V_16 ) ;
F_28 () ;
return V_153 ;
case V_199 :
if ( F_6 ( V_189 , & V_187 -> V_193 ) )
return - V_7 ;
F_25 () ;
V_153 = F_131 ( V_17 , V_189 ) ;
F_28 () ;
return V_153 ;
case V_200 :
if ( F_4 ( V_96 | V_95 | V_194 , V_188 ) )
return - V_7 ;
return 0 ;
case V_201 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
V_2 -> V_27 . V_202 = V_6 ;
return 0 ;
case V_203 :
V_6 = V_2 -> V_97 ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_204 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 < ( int ) sizeof( struct V_98 ) )
return - V_9 ;
V_2 -> V_97 = V_6 ;
return 0 ;
case V_205 :
V_6 = ! ! ( V_2 -> V_3 & V_10 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_206 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
case V_207 :
return F_3 ( V_2 , V_5 ) ;
case V_208 :
return F_5 ( V_2 , V_5 ) ;
case V_209 :
if ( V_170 & ~ ( V_173 | V_175 | V_176 |
V_177 | V_181 ) )
return - V_9 ;
F_25 () ;
V_153 = F_132 ( V_2 , V_170 ) ;
F_28 () ;
return V_153 ;
case V_210 :
F_25 () ;
V_16 = F_129 ( V_2 ) ;
if ( ! V_16 ) {
F_28 () ;
return - V_172 ;
}
V_153 = 0 ;
V_189 = V_16 -> V_14 -> type ;
if ( F_134 ( & V_187 -> V_196 , V_16 -> V_14 -> V_197 , V_198 ) ||
F_134 ( & V_187 -> V_211 . V_212 , V_16 -> V_14 -> V_213 , V_214 ) ||
F_4 ( V_189 , & V_187 -> V_211 . V_215 ) )
V_153 = - V_7 ;
F_130 ( V_16 ) ;
F_28 () ;
return V_153 ;
case V_216 :
if ( F_135 ( & V_191 , & V_187 -> V_211 , sizeof( V_191 ) ) )
return - V_7 ;
F_25 () ;
V_16 = F_129 ( V_2 ) ;
if ( ! V_16 ) {
F_28 () ;
return - V_172 ;
}
V_153 = F_136 ( V_16 -> V_14 , & V_191 ) ;
F_130 ( V_16 ) ;
F_28 () ;
return V_153 ;
default:
return - V_9 ;
}
}
static long F_137 ( struct V_17 * V_17 , unsigned int V_185 ,
unsigned long V_170 )
{
return F_133 ( V_17 , V_185 , ( unsigned long ) F_138 ( V_170 ) ) ;
}
static int F_139 ( struct V_217 * V_71 , struct V_113 * V_114 ,
T_10 V_119 )
{
struct V_1 * V_2 = F_72 ( V_71 , struct V_1 , V_71 ) ;
return F_92 ( V_2 , V_114 , & V_114 -> V_218 , V_114 -> V_219 & V_220 ) ;
}
static int F_140 ( struct V_217 * V_71 , struct V_113 * V_114 ,
T_10 V_119 , int V_3 )
{
struct V_1 * V_2 = F_72 ( V_71 , struct V_1 , V_71 ) ;
int V_153 ;
if ( V_3 & ~ ( V_220 | V_221 ) )
return - V_9 ;
V_153 = F_120 ( V_2 , & V_114 -> V_218 , V_3 & V_220 ) ;
if ( V_153 > V_119 ) {
V_114 -> V_219 |= V_221 ;
V_153 = V_3 & V_221 ? V_153 : V_119 ;
}
return V_153 ;
}
static int F_141 ( struct V_217 * V_71 )
{
struct V_1 * V_2 = F_72 ( V_71 , struct V_1 ,
V_71 ) ;
return F_142 ( & V_2 -> V_43 ) ;
}
struct V_217 * F_143 ( struct V_17 * V_17 )
{
struct V_1 * V_2 ;
if ( V_17 -> V_222 != & V_223 )
return F_144 ( - V_9 ) ;
V_2 = V_17 -> V_28 ;
if ( ! V_2 )
return F_144 ( - V_224 ) ;
return & V_2 -> V_71 ;
}
int F_145 ( struct V_12 * V_16 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
struct V_1 * V_2 ;
struct V_43 * * V_225 ;
int V_226 = V_16 -> V_24 ;
int V_153 , V_130 = 0 ;
V_225 = F_146 ( sizeof *V_225 * V_226 , V_68 ) ;
if ( ! V_225 )
return - V_63 ;
F_147 (q, &tap->queue_list, next)
V_225 [ V_130 ++ ] = & V_2 -> V_43 ;
V_153 = F_148 ( V_225 , V_226 ,
V_14 -> V_102 , V_68 ) ;
F_149 ( V_225 ) ;
return V_153 ;
}
static int F_150 ( T_7 V_60 , const char * V_227 )
{
struct V_59 * V_61 ;
V_61 = F_151 ( sizeof( * V_61 ) , V_228 ) ;
if ( ! V_61 )
return - V_63 ;
V_61 -> V_60 = F_56 ( V_60 ) ;
F_152 ( & V_61 -> V_66 ) ;
F_153 ( & V_61 -> V_65 ) ;
V_61 -> V_227 = V_227 ;
F_154 ( & V_61 -> V_29 , & V_229 ) ;
return 0 ;
}
int F_155 ( struct V_230 * V_231 ,
T_7 * V_61 , const char * V_227 )
{
int V_18 ;
V_18 = F_156 ( V_61 , 0 , V_67 , V_227 ) ;
if ( V_18 )
goto V_232;
F_157 ( V_231 , & V_223 ) ;
V_18 = F_158 ( V_231 , * V_61 , V_67 ) ;
if ( V_18 )
goto V_233;
V_18 = F_150 ( * V_61 , V_227 ) ;
if ( V_18 )
goto V_234;
return 0 ;
V_234:
F_159 ( V_231 ) ;
V_233:
F_160 ( * V_61 , V_67 ) ;
V_232:
return V_18 ;
}
void F_161 ( T_7 V_60 , struct V_230 * V_231 )
{
struct V_59 * V_61 , * V_38 ;
F_159 ( V_231 ) ;
F_160 ( V_60 , V_67 ) ;
F_38 (tap_major, tmp, &major_list, next) {
if ( V_61 -> V_60 == F_56 ( V_60 ) ) {
F_162 ( & V_61 -> V_66 ) ;
F_163 ( & V_61 -> V_29 ) ;
F_164 ( V_61 , V_235 ) ;
}
}
}
