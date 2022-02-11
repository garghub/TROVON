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
F_60 ( V_69 L_1 ) ;
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
static int F_67 ( struct V_70 * V_71 ,
struct V_14 * V_15 ,
struct V_72 * V_73 [] ,
struct V_72 * V_74 [] )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
int V_21 ;
F_68 ( & V_20 -> V_33 ) ;
V_20 -> V_50 = V_75 ;
V_21 = F_69 ( V_15 , F_43 , V_20 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_70 ( V_71 , V_15 , V_73 , V_74 ) ;
if ( V_21 ) {
F_71 ( V_15 ) ;
return V_21 ;
}
return 0 ;
}
static void F_72 ( struct V_14 * V_15 ,
struct V_76 * V_77 )
{
F_71 ( V_15 ) ;
F_41 ( V_15 ) ;
F_73 ( V_15 , V_77 ) ;
}
static void F_74 ( struct V_14 * V_15 )
{
F_75 ( V_15 ) ;
V_15 -> V_78 = V_79 ;
}
static void F_76 ( struct V_80 * V_30 )
{
T_7 * V_81 ;
if ( ! F_77 ( V_30 ) ||
! F_78 ( V_82 , & V_30 -> V_83 -> V_3 ) )
return;
V_81 = F_55 ( V_30 ) ;
if ( V_81 && F_79 ( V_81 ) )
F_54 ( V_81 , V_84 | V_85 | V_86 ) ;
}
static void F_80 ( struct V_80 * V_30 )
{
struct V_1 * V_2 = F_81 ( V_30 , struct V_1 , V_30 ) ;
F_82 ( & V_2 -> V_46 ) ;
}
static int F_83 ( struct V_87 * V_87 , struct V_19 * V_19 )
{
struct V_70 * V_70 = V_88 -> V_89 -> V_90 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_21 = - V_91 ;
F_29 () ;
V_15 = F_64 ( F_84 ( V_87 ) ) ;
if ( ! V_15 )
goto V_21;
V_21 = - V_62 ;
V_2 = (struct V_1 * ) F_85 ( V_70 , V_92 , V_66 ,
& V_93 , 0 ) ;
if ( ! V_2 )
goto V_21;
F_27 ( V_2 -> V_80 . V_94 , & V_2 -> V_94 ) ;
F_86 ( & V_2 -> V_94 . V_95 ) ;
V_2 -> V_80 . type = V_96 ;
V_2 -> V_80 . V_97 = V_98 ;
V_2 -> V_80 . V_19 = V_19 ;
V_2 -> V_80 . V_99 = & V_100 ;
F_87 ( & V_2 -> V_80 , & V_2 -> V_30 ) ;
V_2 -> V_30 . V_101 = F_76 ;
V_2 -> V_30 . V_102 = F_80 ;
V_2 -> V_3 = V_49 | V_103 | V_104 ;
V_2 -> V_105 = sizeof( struct V_106 ) ;
if ( ( V_15 -> V_43 & V_107 ) && ( V_15 -> V_43 & V_108 ) )
F_88 ( & V_2 -> V_30 , V_109 ) ;
V_21 = - V_62 ;
if ( F_89 ( & V_2 -> V_46 , V_15 -> V_78 , V_66 ) )
goto V_110;
V_21 = F_21 ( V_15 , V_19 , V_2 ) ;
if ( V_21 )
goto V_111;
F_90 ( V_15 ) ;
F_32 () ;
return V_21 ;
V_111:
F_82 ( & V_2 -> V_46 ) ;
V_110:
F_30 ( & V_2 -> V_30 ) ;
V_21:
if ( V_15 )
F_90 ( V_15 ) ;
F_32 () ;
return V_21 ;
}
static int F_91 ( struct V_87 * V_87 , struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
F_28 ( V_2 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_19 * V_19 , T_8 * V_95 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
unsigned int V_112 = V_113 ;
if ( ! V_2 )
goto V_23;
V_112 = 0 ;
F_93 ( V_19 , & V_2 -> V_94 . V_95 , V_95 ) ;
if ( ! F_94 ( & V_2 -> V_46 ) )
V_112 |= V_57 | V_58 ;
if ( F_77 ( & V_2 -> V_30 ) ||
( ! F_95 ( V_82 , & V_2 -> V_80 . V_3 ) &&
F_77 ( & V_2 -> V_30 ) ) )
V_112 |= V_84 | V_85 ;
V_23:
return V_112 ;
}
static inline struct V_36 * F_96 ( struct V_80 * V_30 , T_9 V_114 ,
T_9 V_115 , T_9 V_116 ,
int V_117 , int * V_21 )
{
struct V_36 * V_37 ;
if ( V_114 + V_115 < V_118 || ! V_116 )
V_116 = V_115 ;
V_37 = F_97 ( V_30 , V_114 + V_116 , V_115 - V_116 , V_117 ,
V_21 , 0 ) ;
if ( ! V_37 )
return NULL ;
F_98 ( V_37 , V_114 ) ;
F_99 ( V_37 , V_116 ) ;
V_37 -> V_119 = V_115 - V_116 ;
V_37 -> V_115 += V_115 - V_116 ;
return V_37 ;
}
static T_10 F_100 ( struct V_1 * V_2 , struct V_120 * V_121 ,
struct V_122 * V_123 , int V_117 )
{
int V_124 = F_101 ( V_125 ) ;
struct V_36 * V_37 ;
struct V_17 * V_20 ;
unsigned long V_126 = F_102 ( V_123 ) ;
unsigned long V_115 = V_126 ;
int V_21 ;
struct V_106 V_127 = { 0 } ;
int V_128 = 0 ;
int V_129 = 0 ;
int V_130 ;
bool V_131 = false ;
T_9 V_116 ;
T_10 V_132 ;
if ( V_2 -> V_3 & V_49 ) {
V_128 = V_2 -> V_105 ;
V_21 = - V_9 ;
if ( V_115 < V_128 )
goto V_21;
V_115 -= V_128 ;
V_21 = - V_7 ;
V_132 = F_103 ( & V_127 , sizeof( V_127 ) , V_123 ) ;
if ( V_132 != sizeof( V_127 ) )
goto V_21;
F_104 ( V_123 , V_128 - sizeof( V_127 ) ) ;
if ( ( V_127 . V_3 & V_133 ) &&
F_8 ( V_2 , V_127 . V_134 ) +
F_8 ( V_2 , V_127 . V_135 ) + 2 >
F_8 ( V_2 , V_127 . V_136 ) )
V_127 . V_136 = F_10 ( V_2 ,
F_8 ( V_2 , V_127 . V_134 ) +
F_8 ( V_2 , V_127 . V_135 ) + 2 ) ;
V_21 = - V_9 ;
if ( F_8 ( V_2 , V_127 . V_136 ) > V_115 )
goto V_21;
}
V_21 = - V_9 ;
if ( F_40 ( V_115 < V_48 ) )
goto V_21;
if ( V_121 && V_121 -> V_137 && F_105 ( & V_2 -> V_30 , V_109 ) ) {
struct V_122 V_138 ;
V_129 = V_127 . V_136 ?
F_8 ( V_2 , V_127 . V_136 ) : V_139 ;
if ( V_129 > V_124 )
V_129 = V_124 ;
else if ( V_129 < V_48 )
V_129 = V_48 ;
V_116 = V_129 ;
V_138 = * V_123 ;
F_104 ( & V_138 , V_129 ) ;
if ( F_106 ( & V_138 , V_140 ) <= V_141 )
V_131 = true ;
}
if ( ! V_131 ) {
V_129 = V_115 ;
V_116 = F_8 ( V_2 , V_127 . V_136 ) ;
if ( V_116 > V_124 )
V_116 = V_124 ;
else if ( V_116 < V_48 )
V_116 = V_48 ;
}
V_37 = F_96 ( & V_2 -> V_30 , V_125 , V_129 ,
V_116 , V_117 , & V_21 ) ;
if ( ! V_37 )
goto V_21;
if ( V_131 )
V_21 = F_107 ( V_37 , V_123 ) ;
else
V_21 = F_108 ( V_37 , 0 , V_123 , V_115 ) ;
if ( V_21 )
goto V_142;
F_109 ( V_37 , V_48 ) ;
F_110 ( V_37 ) ;
V_37 -> V_143 = F_111 ( V_37 ) -> V_144 ;
if ( V_128 ) {
V_21 = F_112 ( V_37 , & V_127 ,
F_7 ( V_2 ) ) ;
if ( V_21 )
goto V_142;
}
F_113 ( V_37 , V_48 ) ;
if ( ( V_37 -> V_143 == F_114 ( V_145 ) ||
V_37 -> V_143 == F_114 ( V_146 ) ) &&
F_115 ( V_37 , V_37 -> V_143 , & V_130 ) != 0 )
F_109 ( V_37 , V_130 ) ;
F_116 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_131 ) {
F_117 ( V_37 ) -> V_147 = V_121 -> V_137 ;
F_117 ( V_37 ) -> V_148 |= V_149 ;
F_117 ( V_37 ) -> V_148 |= V_150 ;
} else if ( V_121 && V_121 -> V_137 ) {
struct V_151 * V_152 = V_121 -> V_137 ;
V_152 -> V_153 ( V_152 , false ) ;
}
if ( V_20 ) {
V_37 -> V_15 = V_20 -> V_15 ;
F_118 ( V_37 ) ;
} else {
F_51 ( V_37 ) ;
}
F_119 () ;
return V_126 ;
V_142:
F_51 ( V_37 ) ;
V_21:
F_116 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_20 )
F_120 ( V_20 -> V_154 -> V_155 ) ;
F_119 () ;
return V_21 ;
}
static T_10 F_121 ( struct V_156 * V_157 , struct V_122 * V_123 )
{
struct V_19 * V_19 = V_157 -> V_158 ;
struct V_1 * V_2 = V_19 -> V_31 ;
return F_100 ( V_2 , NULL , V_123 , V_19 -> V_159 & V_160 ) ;
}
static T_10 F_122 ( struct V_1 * V_2 ,
const struct V_36 * V_37 ,
struct V_122 * V_161 )
{
int V_162 ;
int V_128 = 0 ;
int V_163 = 0 ;
int V_164 ;
if ( V_2 -> V_3 & V_49 ) {
struct V_106 V_127 ;
V_128 = V_2 -> V_105 ;
if ( F_102 ( V_161 ) < V_128 )
return - V_9 ;
V_162 = F_123 ( V_37 , & V_127 ,
F_7 ( V_2 ) ) ;
if ( V_162 )
F_124 () ;
if ( F_125 ( & V_127 , sizeof( V_127 ) , V_161 ) !=
sizeof( V_127 ) )
return - V_7 ;
F_104 ( V_161 , V_128 - sizeof( V_127 ) ) ;
}
V_164 = V_128 ;
V_164 += V_37 -> V_115 ;
if ( F_126 ( V_37 ) ) {
struct {
T_11 V_165 ;
T_11 V_166 ;
} V_167 ;
V_167 . V_165 = V_37 -> V_168 ;
V_167 . V_166 = F_114 ( F_127 ( V_37 ) ) ;
V_163 = F_128 ( struct V_169 , V_165 ) ;
V_164 += V_170 ;
V_162 = F_129 ( V_37 , 0 , V_161 , V_163 ) ;
if ( V_162 || ! F_102 ( V_161 ) )
goto V_171;
V_162 = F_125 ( & V_167 , sizeof( V_167 ) , V_161 ) ;
if ( V_162 != sizeof( V_167 ) || ! F_102 ( V_161 ) )
goto V_171;
}
V_162 = F_129 ( V_37 , V_163 , V_161 ,
V_37 -> V_115 - V_163 ) ;
V_171:
return V_162 ? V_162 : V_164 ;
}
static T_10 F_130 ( struct V_1 * V_2 ,
struct V_122 * V_172 ,
int V_117 )
{
F_131 ( V_95 ) ;
struct V_36 * V_37 ;
T_10 V_162 = 0 ;
if ( ! F_102 ( V_172 ) )
return 0 ;
while ( 1 ) {
if ( ! V_117 )
F_132 ( F_55 ( & V_2 -> V_30 ) , & V_95 ,
V_173 ) ;
V_37 = F_133 ( & V_2 -> V_46 ) ;
if ( V_37 )
break;
if ( V_117 ) {
V_162 = - V_174 ;
break;
}
if ( F_134 ( V_88 ) ) {
V_162 = - V_175 ;
break;
}
F_135 () ;
}
if ( ! V_117 )
F_136 ( F_55 ( & V_2 -> V_30 ) , & V_95 ) ;
if ( V_37 ) {
V_162 = F_122 ( V_2 , V_37 , V_172 ) ;
if ( F_40 ( V_162 < 0 ) )
F_51 ( V_37 ) ;
else
F_50 ( V_37 ) ;
}
return V_162 ;
}
static T_10 F_137 ( struct V_156 * V_157 , struct V_122 * V_172 )
{
struct V_19 * V_19 = V_157 -> V_158 ;
struct V_1 * V_2 = V_19 -> V_31 ;
T_10 V_115 = F_102 ( V_172 ) , V_162 ;
V_162 = F_130 ( V_2 , V_172 , V_19 -> V_159 & V_160 ) ;
V_162 = F_138 ( T_10 , V_162 , V_115 ) ;
if ( V_162 > 0 )
V_157 -> V_176 = V_162 ;
return V_162 ;
}
static struct V_17 * F_139 ( struct V_1 * V_2 )
{
struct V_17 * V_20 ;
F_19 () ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( V_20 )
F_66 ( V_20 -> V_15 ) ;
return V_20 ;
}
static void F_140 ( struct V_17 * V_20 )
{
F_90 ( V_20 -> V_15 ) ;
}
static int F_141 ( struct V_19 * V_19 , unsigned int V_3 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
int V_162 ;
V_20 = F_139 ( V_2 ) ;
if ( ! V_20 )
return - V_9 ;
if ( V_3 & V_177 )
V_162 = F_17 ( V_20 -> V_15 , V_19 , V_2 ) ;
else if ( V_3 & V_178 )
V_162 = F_24 ( V_2 ) ;
else
V_162 = - V_9 ;
F_140 ( V_20 ) ;
return V_162 ;
}
static int F_142 ( struct V_1 * V_2 , unsigned long V_179 )
{
struct V_17 * V_20 ;
T_6 V_43 ;
T_6 V_180 = 0 ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( ! V_20 )
return - V_181 ;
V_43 = V_20 -> V_15 -> V_43 ;
if ( V_179 & V_182 ) {
V_180 = V_183 ;
if ( V_179 & ( V_184 | V_185 ) ) {
if ( V_179 & V_186 )
V_180 |= V_187 ;
if ( V_179 & V_184 )
V_180 |= V_188 ;
if ( V_179 & V_185 )
V_180 |= V_189 ;
}
if ( V_179 & V_190 )
V_180 |= V_191 ;
}
if ( V_180 & ( V_188 | V_189 | V_191 ) )
V_43 |= V_192 ;
else
V_43 &= ~ V_192 ;
V_20 -> V_50 = V_180 ;
V_20 -> V_193 = V_43 ;
F_143 ( V_20 -> V_15 ) ;
return 0 ;
}
static long F_144 ( struct V_19 * V_19 , unsigned int V_194 ,
unsigned long V_179 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
void T_1 * V_8 = ( void T_1 * ) V_179 ;
struct V_195 T_1 * V_196 = V_8 ;
unsigned int T_1 * V_197 = V_8 ;
unsigned short V_198 ;
int T_1 * V_5 = V_8 ;
struct V_199 V_200 ;
int V_6 ;
int V_162 ;
switch ( V_194 ) {
case V_201 :
if ( F_6 ( V_198 , & V_196 -> V_202 ) )
return - V_7 ;
V_162 = 0 ;
if ( ( V_198 & ~ V_203 ) != ( V_103 | V_104 ) )
V_162 = - V_9 ;
else
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_203 ) | V_198 ;
return V_162 ;
case V_204 :
F_29 () ;
V_20 = F_139 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_181 ;
}
V_162 = 0 ;
V_198 = V_2 -> V_3 ;
if ( F_145 ( & V_196 -> V_205 , V_20 -> V_15 -> V_206 , V_207 ) ||
F_4 ( V_198 , & V_196 -> V_202 ) )
V_162 = - V_7 ;
F_140 ( V_20 ) ;
F_32 () ;
return V_162 ;
case V_208 :
if ( F_6 ( V_198 , & V_196 -> V_202 ) )
return - V_7 ;
F_29 () ;
V_162 = F_141 ( V_19 , V_198 ) ;
F_32 () ;
return V_162 ;
case V_209 :
if ( F_4 ( V_104 | V_103 | V_203 , V_197 ) )
return - V_7 ;
return 0 ;
case V_210 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
V_2 -> V_30 . V_211 = V_6 ;
return 0 ;
case V_212 :
V_6 = V_2 -> V_105 ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_213 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 < ( int ) sizeof( struct V_106 ) )
return - V_9 ;
V_2 -> V_105 = V_6 ;
return 0 ;
case V_214 :
V_6 = ! ! ( V_2 -> V_3 & V_10 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_215 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
case V_216 :
return F_3 ( V_2 , V_5 ) ;
case V_217 :
return F_5 ( V_2 , V_5 ) ;
case V_218 :
if ( V_179 & ~ ( V_182 | V_184 | V_185 |
V_186 | V_190 ) )
return - V_9 ;
F_29 () ;
V_162 = F_142 ( V_2 , V_179 ) ;
F_32 () ;
return V_162 ;
case V_219 :
F_29 () ;
V_20 = F_139 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_181 ;
}
V_162 = 0 ;
V_198 = V_20 -> V_15 -> type ;
if ( F_145 ( & V_196 -> V_205 , V_20 -> V_15 -> V_206 , V_207 ) ||
F_145 ( & V_196 -> V_220 . V_221 , V_20 -> V_15 -> V_222 , V_223 ) ||
F_4 ( V_198 , & V_196 -> V_220 . V_224 ) )
V_162 = - V_7 ;
F_140 ( V_20 ) ;
F_32 () ;
return V_162 ;
case V_225 :
if ( F_146 ( & V_200 , & V_196 -> V_220 , sizeof( V_200 ) ) )
return - V_7 ;
F_29 () ;
V_20 = F_139 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_181 ;
}
V_162 = F_147 ( V_20 -> V_15 , & V_200 ) ;
F_140 ( V_20 ) ;
F_32 () ;
return V_162 ;
default:
return - V_9 ;
}
}
static long F_148 ( struct V_19 * V_19 , unsigned int V_194 ,
unsigned long V_179 )
{
return F_144 ( V_19 , V_194 , ( unsigned long ) F_149 ( V_179 ) ) ;
}
static int F_150 ( struct V_226 * V_80 , struct V_120 * V_121 ,
T_9 V_126 )
{
struct V_1 * V_2 = F_81 ( V_80 , struct V_1 , V_80 ) ;
return F_100 ( V_2 , V_121 , & V_121 -> V_227 , V_121 -> V_228 & V_229 ) ;
}
static int F_151 ( struct V_226 * V_80 , struct V_120 * V_121 ,
T_9 V_126 , int V_3 )
{
struct V_1 * V_2 = F_81 ( V_80 , struct V_1 , V_80 ) ;
int V_162 ;
if ( V_3 & ~ ( V_229 | V_230 ) )
return - V_9 ;
V_162 = F_130 ( V_2 , & V_121 -> V_227 , V_3 & V_229 ) ;
if ( V_162 > V_126 ) {
V_121 -> V_228 |= V_230 ;
V_162 = V_3 & V_230 ? V_162 : V_126 ;
}
return V_162 ;
}
static int F_152 ( struct V_226 * V_80 )
{
struct V_1 * V_2 = F_81 ( V_80 , struct V_1 ,
V_80 ) ;
return F_153 ( & V_2 -> V_46 ) ;
}
struct V_226 * F_154 ( struct V_19 * V_19 )
{
struct V_1 * V_2 ;
if ( V_19 -> V_231 != & V_232 )
return F_155 ( - V_9 ) ;
V_2 = V_19 -> V_31 ;
if ( ! V_2 )
return F_155 ( - V_233 ) ;
return & V_2 -> V_80 ;
}
static int F_156 ( struct V_17 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_1 * V_2 ;
struct V_46 * * V_234 ;
int V_132 = V_20 -> V_27 ;
int V_162 , V_138 = 0 ;
V_234 = F_157 ( sizeof *V_234 * V_132 , V_66 ) ;
if ( ! V_234 )
return - V_62 ;
F_158 (q, &vlan->queue_list, next)
V_234 [ V_138 ++ ] = & V_2 -> V_46 ;
V_162 = F_159 ( V_234 , V_132 ,
V_15 -> V_78 , V_66 ) ;
F_160 ( V_234 ) ;
return V_162 ;
}
static int F_161 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
struct V_14 * V_15 = F_162 ( V_238 ) ;
struct V_17 * V_20 ;
struct V_12 * V_239 ;
T_12 V_240 ;
int V_21 ;
char V_241 [ V_207 ] ;
if ( V_15 -> V_242 != & V_243 )
return V_244 ;
snprintf ( V_241 , V_207 , L_2 , V_15 -> V_245 ) ;
V_20 = F_18 ( V_15 ) ;
switch ( V_237 ) {
case V_246 :
V_21 = F_57 ( V_20 ) ;
if ( V_21 )
return F_163 ( V_21 ) ;
V_240 = F_164 ( F_165 ( V_247 ) , V_20 -> V_67 ) ;
V_239 = F_166 ( & V_248 , & V_15 -> V_15 , V_240 ,
V_15 , V_241 ) ;
if ( F_48 ( V_239 ) ) {
F_62 ( V_20 ) ;
return F_163 ( F_167 ( V_239 ) ) ;
}
V_21 = F_168 ( & V_15 -> V_15 . V_249 , & V_239 -> V_249 ,
V_241 ) ;
if ( V_21 )
return F_163 ( V_21 ) ;
break;
case V_250 :
if ( V_20 -> V_67 == 0 )
break;
F_169 ( & V_15 -> V_15 . V_249 , V_241 ) ;
V_240 = F_164 ( F_165 ( V_247 ) , V_20 -> V_67 ) ;
F_170 ( & V_248 , V_240 ) ;
F_62 ( V_20 ) ;
break;
case V_251 :
if ( F_156 ( V_20 ) )
return V_252 ;
break;
}
return V_244 ;
}
static int F_171 ( void )
{
int V_21 ;
V_21 = F_172 ( & V_247 , 0 ,
V_65 , L_3 ) ;
if ( V_21 )
goto V_253;
F_173 ( & V_254 , & V_232 ) ;
V_21 = F_174 ( & V_254 , V_247 , V_65 ) ;
if ( V_21 )
goto V_255;
V_21 = F_175 ( & V_248 ) ;
if ( V_21 )
goto V_256;
V_21 = F_176 ( & V_257 ) ;
if ( V_21 )
goto V_258;
V_21 = F_177 ( & V_243 ) ;
if ( V_21 )
goto V_259;
return 0 ;
V_259:
F_178 ( & V_257 ) ;
V_258:
F_179 ( & V_248 ) ;
V_256:
F_180 ( & V_254 ) ;
V_255:
F_181 ( V_247 , V_65 ) ;
V_253:
return V_21 ;
}
static void F_182 ( void )
{
F_183 ( & V_243 ) ;
F_178 ( & V_257 ) ;
F_179 ( & V_248 ) ;
F_180 ( & V_254 ) ;
F_181 ( V_247 , V_65 ) ;
F_184 ( & V_64 ) ;
}
