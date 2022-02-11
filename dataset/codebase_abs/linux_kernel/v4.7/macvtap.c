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
V_38 = F_16 ( V_20 -> V_24 [ 0 ] ) ;
V_23:
return V_38 ;
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
struct V_1 * V_2 , * V_40 ;
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
static T_5 F_43 ( struct V_36 * * V_41 )
{
struct V_36 * V_37 = * V_41 ;
struct V_14 * V_15 = V_37 -> V_15 ;
struct V_17 * V_20 ;
struct V_1 * V_2 ;
T_6 V_42 = V_43 ;
V_20 = F_15 ( V_15 ) ;
if ( ! V_20 )
return V_44 ;
V_2 = F_34 ( V_15 , V_37 ) ;
if ( ! V_2 )
return V_44 ;
if ( F_44 ( & V_2 -> V_30 . V_45 ) >= V_15 -> V_46 )
goto V_47;
F_45 ( V_37 , V_48 ) ;
if ( V_2 -> V_3 & V_49 )
V_42 |= V_20 -> V_50 ;
if ( F_46 ( V_37 , V_42 ) ) {
struct V_36 * V_51 = F_47 ( V_37 , V_42 , false ) ;
if ( F_48 ( V_51 ) )
goto V_47;
if ( ! V_51 ) {
F_49 ( & V_2 -> V_30 . V_45 , V_37 ) ;
goto V_52;
}
F_50 ( V_37 ) ;
while ( V_51 ) {
struct V_36 * V_53 = V_51 -> V_32 ;
V_51 -> V_32 = NULL ;
F_49 ( & V_2 -> V_30 . V_45 , V_51 ) ;
V_51 = V_53 ;
}
} else {
if ( V_37 -> V_54 == V_55 &&
! ( V_42 & V_56 ) &&
F_51 ( V_37 ) )
goto V_47;
F_49 ( & V_2 -> V_30 . V_45 , V_37 ) ;
}
V_52:
F_52 ( F_53 ( & V_2 -> V_30 ) , V_57 | V_58 | V_59 ) ;
return V_60 ;
V_47:
F_54 ( V_20 , 0 , 0 , 0 ) ;
F_55 ( V_37 ) ;
return V_60 ;
}
static int F_56 ( struct V_17 * V_20 )
{
int V_61 = - V_62 ;
F_57 ( & V_63 ) ;
V_61 = F_58 ( & V_64 , V_20 , 1 , V_65 , V_66 ) ;
if ( V_61 >= 0 ) {
V_20 -> V_67 = V_61 ;
} else if ( V_61 == - V_68 ) {
F_59 ( V_69 L_1 ) ;
V_61 = - V_9 ;
}
F_60 ( & V_63 ) ;
return V_61 < 0 ? V_61 : 0 ;
}
static void F_61 ( struct V_17 * V_20 )
{
F_57 ( & V_63 ) ;
if ( V_20 -> V_67 ) {
F_62 ( & V_64 , V_20 -> V_67 ) ;
V_20 -> V_67 = 0 ;
}
F_60 ( & V_63 ) ;
}
static struct V_14 * F_63 ( int V_67 )
{
struct V_14 * V_15 = NULL ;
struct V_17 * V_20 ;
F_57 ( & V_63 ) ;
V_20 = F_64 ( & V_64 , V_67 ) ;
if ( V_20 ) {
V_15 = V_20 -> V_15 ;
F_65 ( V_15 ) ;
}
F_60 ( & V_63 ) ;
return V_15 ;
}
static int F_66 ( struct V_70 * V_71 ,
struct V_14 * V_15 ,
struct V_72 * V_73 [] ,
struct V_72 * V_74 [] )
{
struct V_17 * V_20 = F_18 ( V_15 ) ;
int V_21 ;
F_67 ( & V_20 -> V_33 ) ;
V_20 -> V_50 = V_75 ;
V_21 = F_68 ( V_15 , F_43 , V_20 ) ;
if ( V_21 )
return V_21 ;
return F_69 ( V_71 , V_15 , V_73 , V_74 ) ;
}
static void F_70 ( struct V_14 * V_15 ,
struct V_76 * V_77 )
{
F_71 ( V_15 ) ;
F_41 ( V_15 ) ;
F_72 ( V_15 , V_77 ) ;
}
static void F_73 ( struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
V_15 -> V_46 = V_78 ;
}
static void F_75 ( struct V_79 * V_30 )
{
T_7 * V_80 ;
if ( ! F_76 ( V_30 ) ||
! F_77 ( V_81 , & V_30 -> V_82 -> V_3 ) )
return;
V_80 = F_53 ( V_30 ) ;
if ( V_80 && F_78 ( V_80 ) )
F_52 ( V_80 , V_83 | V_84 | V_85 ) ;
}
static void F_79 ( struct V_79 * V_30 )
{
F_80 ( & V_30 -> V_45 ) ;
}
static int F_81 ( struct V_86 * V_86 , struct V_19 * V_19 )
{
struct V_70 * V_70 = V_87 -> V_88 -> V_89 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_21 = - V_90 ;
F_29 () ;
V_15 = F_63 ( F_82 ( V_86 ) ) ;
if ( ! V_15 )
goto V_23;
V_21 = - V_62 ;
V_2 = (struct V_1 * ) F_83 ( V_70 , V_91 , V_66 ,
& V_92 , 0 ) ;
if ( ! V_2 )
goto V_23;
F_27 ( V_2 -> V_79 . V_93 , & V_2 -> V_93 ) ;
F_84 ( & V_2 -> V_93 . V_94 ) ;
V_2 -> V_79 . type = V_95 ;
V_2 -> V_79 . V_96 = V_97 ;
V_2 -> V_79 . V_19 = V_19 ;
V_2 -> V_79 . V_98 = & V_99 ;
F_85 ( & V_2 -> V_79 , & V_2 -> V_30 ) ;
V_2 -> V_30 . V_100 = F_75 ;
V_2 -> V_30 . V_101 = F_79 ;
V_2 -> V_3 = V_49 | V_102 | V_103 ;
V_2 -> V_104 = sizeof( struct V_105 ) ;
if ( ( V_15 -> V_42 & V_106 ) && ( V_15 -> V_42 & V_107 ) )
F_86 ( & V_2 -> V_30 , V_108 ) ;
V_21 = F_21 ( V_15 , V_19 , V_2 ) ;
if ( V_21 )
F_30 ( & V_2 -> V_30 ) ;
V_23:
if ( V_15 )
F_87 ( V_15 ) ;
F_32 () ;
return V_21 ;
}
static int F_88 ( struct V_86 * V_86 , struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
F_28 ( V_2 ) ;
return 0 ;
}
static unsigned int F_89 ( struct V_19 * V_19 , T_8 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
unsigned int V_109 = V_110 ;
if ( ! V_2 )
goto V_23;
V_109 = 0 ;
F_90 ( V_19 , & V_2 -> V_93 . V_94 , V_94 ) ;
if ( ! F_91 ( & V_2 -> V_30 . V_45 ) )
V_109 |= V_57 | V_58 ;
if ( F_76 ( & V_2 -> V_30 ) ||
( ! F_92 ( V_81 , & V_2 -> V_79 . V_3 ) &&
F_76 ( & V_2 -> V_30 ) ) )
V_109 |= V_83 | V_84 ;
V_23:
return V_109 ;
}
static inline struct V_36 * F_93 ( struct V_79 * V_30 , T_9 V_111 ,
T_9 V_112 , T_9 V_113 ,
int V_114 , int * V_21 )
{
struct V_36 * V_37 ;
if ( V_111 + V_112 < V_115 || ! V_113 )
V_113 = V_112 ;
V_37 = F_94 ( V_30 , V_111 + V_113 , V_112 - V_113 , V_114 ,
V_21 , 0 ) ;
if ( ! V_37 )
return NULL ;
F_95 ( V_37 , V_111 ) ;
F_96 ( V_37 , V_113 ) ;
V_37 -> V_116 = V_112 - V_113 ;
V_37 -> V_112 += V_112 - V_113 ;
return V_37 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_105 * V_117 )
{
unsigned short V_118 = 0 ;
if ( V_117 -> V_118 != V_119 ) {
switch ( V_117 -> V_118 & ~ V_120 ) {
case V_121 :
V_118 = V_122 ;
break;
case V_123 :
V_118 = V_124 ;
break;
case V_125 :
V_118 = V_126 ;
break;
default:
return - V_9 ;
}
if ( V_117 -> V_118 & V_120 )
V_118 |= V_127 ;
if ( V_117 -> V_128 == 0 )
return - V_9 ;
}
if ( V_117 -> V_3 & V_129 ) {
if ( ! F_98 ( V_37 , F_8 ( V_2 , V_117 -> V_130 ) ,
F_8 ( V_2 , V_117 -> V_131 ) ) )
return - V_9 ;
}
if ( V_117 -> V_118 != V_119 ) {
F_99 ( V_37 ) -> V_128 = F_8 ( V_2 , V_117 -> V_128 ) ;
F_99 ( V_37 ) -> V_118 = V_118 ;
F_99 ( V_37 ) -> V_118 |= V_132 ;
F_99 ( V_37 ) -> V_133 = 0 ;
}
return 0 ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_36 * V_37 ,
struct V_105 * V_117 )
{
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
if ( F_101 ( V_37 ) ) {
struct V_134 * V_135 = F_99 ( V_37 ) ;
V_117 -> V_136 = F_10 ( V_2 , F_102 ( V_37 ) ) ;
V_117 -> V_128 = F_10 ( V_2 , V_135 -> V_128 ) ;
if ( V_135 -> V_118 & V_122 )
V_117 -> V_118 = V_121 ;
else if ( V_135 -> V_118 & V_124 )
V_117 -> V_118 = V_123 ;
else if ( V_135 -> V_118 & V_126 )
V_117 -> V_118 = V_125 ;
else
F_103 () ;
if ( V_135 -> V_118 & V_127 )
V_117 -> V_118 |= V_120 ;
} else
V_117 -> V_118 = V_119 ;
if ( V_37 -> V_54 == V_55 ) {
V_117 -> V_3 = V_129 ;
if ( F_104 ( V_37 ) )
V_117 -> V_130 = F_10 ( V_2 ,
F_105 ( V_37 ) + V_137 ) ;
else
V_117 -> V_130 = F_10 ( V_2 ,
F_105 ( V_37 ) ) ;
V_117 -> V_131 = F_10 ( V_2 , V_37 -> V_131 ) ;
} else if ( V_37 -> V_54 == V_138 ) {
V_117 -> V_3 = V_139 ;
}
}
static T_10 F_106 ( struct V_1 * V_2 , struct V_140 * V_141 ,
struct V_142 * V_143 , int V_114 )
{
int V_144 = F_107 ( V_145 ) ;
struct V_36 * V_37 ;
struct V_17 * V_20 ;
unsigned long V_146 = F_108 ( V_143 ) ;
unsigned long V_112 = V_146 ;
int V_21 ;
struct V_105 V_117 = { 0 } ;
int V_147 = 0 ;
int V_148 = 0 ;
int V_149 ;
bool V_150 = false ;
T_9 V_113 ;
T_10 V_151 ;
if ( V_2 -> V_3 & V_49 ) {
V_147 = V_2 -> V_104 ;
V_21 = - V_9 ;
if ( V_112 < V_147 )
goto V_21;
V_112 -= V_147 ;
V_21 = - V_7 ;
V_151 = F_109 ( & V_117 , sizeof( V_117 ) , V_143 ) ;
if ( V_151 != sizeof( V_117 ) )
goto V_21;
F_110 ( V_143 , V_147 - sizeof( V_117 ) ) ;
if ( ( V_117 . V_3 & V_129 ) &&
F_8 ( V_2 , V_117 . V_130 ) +
F_8 ( V_2 , V_117 . V_131 ) + 2 >
F_8 ( V_2 , V_117 . V_136 ) )
V_117 . V_136 = F_10 ( V_2 ,
F_8 ( V_2 , V_117 . V_130 ) +
F_8 ( V_2 , V_117 . V_131 ) + 2 ) ;
V_21 = - V_9 ;
if ( F_8 ( V_2 , V_117 . V_136 ) > V_112 )
goto V_21;
}
V_21 = - V_9 ;
if ( F_40 ( V_112 < V_48 ) )
goto V_21;
if ( V_141 && V_141 -> V_152 && F_111 ( & V_2 -> V_30 , V_108 ) ) {
struct V_142 V_153 ;
V_148 = V_117 . V_136 ?
F_8 ( V_2 , V_117 . V_136 ) : V_154 ;
if ( V_148 > V_144 )
V_148 = V_144 ;
else if ( V_148 < V_48 )
V_148 = V_48 ;
V_113 = V_148 ;
V_153 = * V_143 ;
F_110 ( & V_153 , V_148 ) ;
if ( F_112 ( & V_153 , V_155 ) <= V_156 )
V_150 = true ;
}
if ( ! V_150 ) {
V_148 = V_112 ;
V_113 = F_8 ( V_2 , V_117 . V_136 ) ;
if ( V_113 > V_144 )
V_113 = V_144 ;
else if ( V_113 < V_48 )
V_113 = V_48 ;
}
V_37 = F_93 ( & V_2 -> V_30 , V_145 , V_148 ,
V_113 , V_114 , & V_21 ) ;
if ( ! V_37 )
goto V_21;
if ( V_150 )
V_21 = F_113 ( V_37 , V_143 ) ;
else {
V_21 = F_114 ( V_37 , 0 , V_143 , V_112 ) ;
if ( ! V_21 && V_141 && V_141 -> V_152 ) {
struct V_157 * V_158 = V_141 -> V_152 ;
V_158 -> V_159 ( V_158 , false ) ;
}
}
if ( V_21 )
goto V_160;
F_115 ( V_37 , V_48 ) ;
F_116 ( V_37 ) ;
V_37 -> V_161 = F_117 ( V_37 ) -> V_162 ;
if ( V_147 ) {
V_21 = F_97 ( V_2 , V_37 , & V_117 ) ;
if ( V_21 )
goto V_160;
}
F_118 ( V_37 , V_48 ) ;
if ( ( V_37 -> V_161 == F_119 ( V_163 ) ||
V_37 -> V_161 == F_119 ( V_164 ) ) &&
F_120 ( V_37 , V_37 -> V_161 , & V_149 ) != 0 )
F_115 ( V_37 , V_149 ) ;
F_121 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_150 ) {
F_99 ( V_37 ) -> V_165 = V_141 -> V_152 ;
F_99 ( V_37 ) -> V_166 |= V_167 ;
F_99 ( V_37 ) -> V_166 |= V_168 ;
}
if ( V_20 ) {
V_37 -> V_15 = V_20 -> V_15 ;
F_122 ( V_37 ) ;
} else {
F_55 ( V_37 ) ;
}
F_123 () ;
return V_146 ;
V_160:
F_55 ( V_37 ) ;
V_21:
F_121 () ;
V_20 = F_16 ( V_2 -> V_20 ) ;
if ( V_20 )
F_124 ( V_20 -> V_169 -> V_170 ) ;
F_123 () ;
return V_21 ;
}
static T_10 F_125 ( struct V_171 * V_172 , struct V_142 * V_143 )
{
struct V_19 * V_19 = V_172 -> V_173 ;
struct V_1 * V_2 = V_19 -> V_31 ;
return F_106 ( V_2 , NULL , V_143 , V_19 -> V_174 & V_175 ) ;
}
static T_10 F_126 ( struct V_1 * V_2 ,
const struct V_36 * V_37 ,
struct V_142 * V_176 )
{
int V_177 ;
int V_147 = 0 ;
int V_178 = 0 ;
int V_179 ;
if ( V_2 -> V_3 & V_49 ) {
struct V_105 V_117 ;
V_147 = V_2 -> V_104 ;
if ( F_108 ( V_176 ) < V_147 )
return - V_9 ;
F_100 ( V_2 , V_37 , & V_117 ) ;
if ( F_127 ( & V_117 , sizeof( V_117 ) , V_176 ) !=
sizeof( V_117 ) )
return - V_7 ;
F_110 ( V_176 , V_147 - sizeof( V_117 ) ) ;
}
V_179 = V_147 ;
V_179 += V_37 -> V_112 ;
if ( F_104 ( V_37 ) ) {
struct {
T_11 V_180 ;
T_11 V_181 ;
} V_182 ;
V_182 . V_180 = V_37 -> V_183 ;
V_182 . V_181 = F_119 ( F_128 ( V_37 ) ) ;
V_178 = F_129 ( struct V_184 , V_180 ) ;
V_179 += V_137 ;
V_177 = F_130 ( V_37 , 0 , V_176 , V_178 ) ;
if ( V_177 || ! F_108 ( V_176 ) )
goto V_185;
V_177 = F_127 ( & V_182 , sizeof( V_182 ) , V_176 ) ;
if ( V_177 != sizeof( V_182 ) || ! F_108 ( V_176 ) )
goto V_185;
}
V_177 = F_130 ( V_37 , V_178 , V_176 ,
V_37 -> V_112 - V_178 ) ;
V_185:
return V_177 ? V_177 : V_179 ;
}
static T_10 F_131 ( struct V_1 * V_2 ,
struct V_142 * V_186 ,
int V_114 )
{
F_132 ( V_94 ) ;
struct V_36 * V_37 ;
T_10 V_177 = 0 ;
if ( ! F_108 ( V_186 ) )
return 0 ;
while ( 1 ) {
if ( ! V_114 )
F_133 ( F_53 ( & V_2 -> V_30 ) , & V_94 ,
V_187 ) ;
V_37 = F_134 ( & V_2 -> V_30 . V_45 ) ;
if ( V_37 )
break;
if ( V_114 ) {
V_177 = - V_188 ;
break;
}
if ( F_135 ( V_87 ) ) {
V_177 = - V_189 ;
break;
}
F_136 () ;
}
if ( ! V_114 )
F_137 ( F_53 ( & V_2 -> V_30 ) , & V_94 ) ;
if ( V_37 ) {
V_177 = F_126 ( V_2 , V_37 , V_186 ) ;
if ( F_40 ( V_177 < 0 ) )
F_55 ( V_37 ) ;
else
F_50 ( V_37 ) ;
}
return V_177 ;
}
static T_10 F_138 ( struct V_171 * V_172 , struct V_142 * V_186 )
{
struct V_19 * V_19 = V_172 -> V_173 ;
struct V_1 * V_2 = V_19 -> V_31 ;
T_10 V_112 = F_108 ( V_186 ) , V_177 ;
V_177 = F_131 ( V_2 , V_186 , V_19 -> V_174 & V_175 ) ;
V_177 = F_139 ( T_10 , V_177 , V_112 ) ;
if ( V_177 > 0 )
V_172 -> V_190 = V_177 ;
return V_177 ;
}
static struct V_17 * F_140 ( struct V_1 * V_2 )
{
struct V_17 * V_20 ;
F_19 () ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( V_20 )
F_65 ( V_20 -> V_15 ) ;
return V_20 ;
}
static void F_141 ( struct V_17 * V_20 )
{
F_87 ( V_20 -> V_15 ) ;
}
static int F_142 ( struct V_19 * V_19 , unsigned int V_3 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
int V_177 ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 )
return - V_9 ;
if ( V_3 & V_191 )
V_177 = F_17 ( V_20 -> V_15 , V_19 , V_2 ) ;
else if ( V_3 & V_192 )
V_177 = F_24 ( V_2 ) ;
else
V_177 = - V_9 ;
F_141 ( V_20 ) ;
return V_177 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned long V_193 )
{
struct V_17 * V_20 ;
T_6 V_42 ;
T_6 V_194 = 0 ;
V_20 = F_25 ( V_2 -> V_20 ) ;
if ( ! V_20 )
return - V_195 ;
V_42 = V_20 -> V_15 -> V_42 ;
if ( V_193 & V_196 ) {
V_194 = V_197 ;
if ( V_193 & ( V_198 | V_199 ) ) {
if ( V_193 & V_200 )
V_194 |= V_201 ;
if ( V_193 & V_198 )
V_194 |= V_202 ;
if ( V_193 & V_199 )
V_194 |= V_203 ;
}
if ( V_193 & V_204 )
V_194 |= V_205 ;
}
if ( V_194 & ( V_202 | V_203 | V_205 ) )
V_42 |= V_206 ;
else
V_42 &= ~ V_206 ;
V_20 -> V_50 = V_194 ;
V_20 -> V_207 = V_42 ;
F_144 ( V_20 -> V_15 ) ;
return 0 ;
}
static long F_145 ( struct V_19 * V_19 , unsigned int V_208 ,
unsigned long V_193 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_17 * V_20 ;
void T_1 * V_8 = ( void T_1 * ) V_193 ;
struct V_209 T_1 * V_210 = V_8 ;
unsigned int T_1 * V_211 = V_8 ;
unsigned short V_212 ;
int T_1 * V_5 = V_8 ;
struct V_213 V_214 ;
int V_6 ;
int V_177 ;
switch ( V_208 ) {
case V_215 :
if ( F_6 ( V_212 , & V_210 -> V_216 ) )
return - V_7 ;
V_177 = 0 ;
if ( ( V_212 & ~ V_217 ) != ( V_102 | V_103 ) )
V_177 = - V_9 ;
else
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_217 ) | V_212 ;
return V_177 ;
case V_218 :
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_195 ;
}
V_177 = 0 ;
V_212 = V_2 -> V_3 ;
if ( F_146 ( & V_210 -> V_219 , V_20 -> V_15 -> V_220 , V_221 ) ||
F_4 ( V_212 , & V_210 -> V_216 ) )
V_177 = - V_7 ;
F_141 ( V_20 ) ;
F_32 () ;
return V_177 ;
case V_222 :
if ( F_6 ( V_212 , & V_210 -> V_216 ) )
return - V_7 ;
F_29 () ;
V_177 = F_142 ( V_19 , V_212 ) ;
F_32 () ;
return V_177 ;
case V_223 :
if ( F_4 ( V_103 | V_102 | V_217 , V_211 ) )
return - V_7 ;
return 0 ;
case V_224 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
V_2 -> V_30 . V_225 = V_6 ;
return 0 ;
case V_226 :
V_6 = V_2 -> V_104 ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_227 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 < ( int ) sizeof( struct V_105 ) )
return - V_9 ;
V_2 -> V_104 = V_6 ;
return 0 ;
case V_228 :
V_6 = ! ! ( V_2 -> V_3 & V_10 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_229 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
case V_230 :
return F_3 ( V_2 , V_5 ) ;
case V_231 :
return F_5 ( V_2 , V_5 ) ;
case V_232 :
if ( V_193 & ~ ( V_196 | V_198 | V_199 |
V_200 | V_204 ) )
return - V_9 ;
F_29 () ;
V_177 = F_143 ( V_2 , V_193 ) ;
F_32 () ;
return V_177 ;
case V_233 :
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_195 ;
}
V_177 = 0 ;
V_212 = V_20 -> V_15 -> type ;
if ( F_146 ( & V_210 -> V_219 , V_20 -> V_15 -> V_220 , V_221 ) ||
F_146 ( & V_210 -> V_234 . V_235 , V_20 -> V_15 -> V_236 , V_237 ) ||
F_4 ( V_212 , & V_210 -> V_234 . V_238 ) )
V_177 = - V_7 ;
F_141 ( V_20 ) ;
F_32 () ;
return V_177 ;
case V_239 :
if ( F_147 ( & V_214 , & V_210 -> V_234 , sizeof( V_214 ) ) )
return - V_7 ;
F_29 () ;
V_20 = F_140 ( V_2 ) ;
if ( ! V_20 ) {
F_32 () ;
return - V_195 ;
}
V_177 = F_148 ( V_20 -> V_15 , & V_214 ) ;
F_141 ( V_20 ) ;
F_32 () ;
return V_177 ;
default:
return - V_9 ;
}
}
static long F_149 ( struct V_19 * V_19 , unsigned int V_208 ,
unsigned long V_193 )
{
return F_145 ( V_19 , V_208 , ( unsigned long ) F_150 ( V_193 ) ) ;
}
static int F_151 ( struct V_240 * V_79 , struct V_140 * V_141 ,
T_9 V_146 )
{
struct V_1 * V_2 = F_152 ( V_79 , struct V_1 , V_79 ) ;
return F_106 ( V_2 , V_141 , & V_141 -> V_241 , V_141 -> V_242 & V_243 ) ;
}
static int F_153 ( struct V_240 * V_79 , struct V_140 * V_141 ,
T_9 V_146 , int V_3 )
{
struct V_1 * V_2 = F_152 ( V_79 , struct V_1 , V_79 ) ;
int V_177 ;
if ( V_3 & ~ ( V_243 | V_244 ) )
return - V_9 ;
V_177 = F_131 ( V_2 , & V_141 -> V_241 , V_3 & V_243 ) ;
if ( V_177 > V_146 ) {
V_141 -> V_242 |= V_244 ;
V_177 = V_3 & V_244 ? V_177 : V_146 ;
}
return V_177 ;
}
struct V_240 * F_154 ( struct V_19 * V_19 )
{
struct V_1 * V_2 ;
if ( V_19 -> V_245 != & V_246 )
return F_155 ( - V_9 ) ;
V_2 = V_19 -> V_31 ;
if ( ! V_2 )
return F_155 ( - V_247 ) ;
return & V_2 -> V_79 ;
}
static int F_156 ( struct V_248 * V_249 ,
unsigned long V_250 , void * V_251 )
{
struct V_14 * V_15 = F_157 ( V_251 ) ;
struct V_17 * V_20 ;
struct V_12 * V_252 ;
T_12 V_253 ;
int V_21 ;
char V_254 [ V_221 ] ;
if ( V_15 -> V_255 != & V_256 )
return V_257 ;
snprintf ( V_254 , V_221 , L_2 , V_15 -> V_258 ) ;
V_20 = F_18 ( V_15 ) ;
switch ( V_250 ) {
case V_259 :
V_21 = F_56 ( V_20 ) ;
if ( V_21 )
return F_158 ( V_21 ) ;
V_253 = F_159 ( F_160 ( V_260 ) , V_20 -> V_67 ) ;
V_252 = F_161 ( & V_261 , & V_15 -> V_15 , V_253 ,
V_15 , V_254 ) ;
if ( F_48 ( V_252 ) ) {
F_61 ( V_20 ) ;
return F_158 ( F_162 ( V_252 ) ) ;
}
V_21 = F_163 ( & V_15 -> V_15 . V_262 , & V_252 -> V_262 ,
V_254 ) ;
if ( V_21 )
return F_158 ( V_21 ) ;
break;
case V_263 :
if ( V_20 -> V_67 == 0 )
break;
F_164 ( & V_15 -> V_15 . V_262 , V_254 ) ;
V_253 = F_159 ( F_160 ( V_260 ) , V_20 -> V_67 ) ;
F_165 ( & V_261 , V_253 ) ;
F_61 ( V_20 ) ;
break;
}
return V_257 ;
}
static int F_166 ( void )
{
int V_21 ;
V_21 = F_167 ( & V_260 , 0 ,
V_65 , L_3 ) ;
if ( V_21 )
goto V_264;
F_168 ( & V_265 , & V_246 ) ;
V_21 = F_169 ( & V_265 , V_260 , V_65 ) ;
if ( V_21 )
goto V_266;
V_21 = F_170 ( & V_261 ) ;
if ( V_21 )
goto V_267;
V_21 = F_171 ( & V_268 ) ;
if ( V_21 )
goto V_269;
V_21 = F_172 ( & V_256 ) ;
if ( V_21 )
goto V_270;
return 0 ;
V_270:
F_173 ( & V_268 ) ;
V_269:
F_174 ( & V_261 ) ;
V_267:
F_175 ( & V_265 ) ;
V_266:
F_176 ( V_260 , V_65 ) ;
V_264:
return V_21 ;
}
static void F_177 ( void )
{
F_178 ( & V_256 ) ;
F_173 ( & V_268 ) ;
F_174 ( & V_261 ) ;
F_175 ( & V_265 ) ;
F_176 ( V_260 , V_65 ) ;
F_179 ( & V_64 ) ;
}
