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
static int F_14 ( struct V_13 * V_14 , struct V_16 * V_16 ,
struct V_1 * V_2 )
{
struct V_12 * V_17 = F_15 ( V_14 ) ;
int V_18 = - V_9 ;
F_16 () ;
if ( V_2 -> V_19 )
goto V_20;
V_18 = 0 ;
F_17 ( V_17 -> V_21 [ V_17 -> V_22 ] , V_2 ) ;
V_2 -> V_23 = V_17 -> V_22 ;
V_2 -> V_19 = true ;
V_17 -> V_22 ++ ;
V_20:
return V_18 ;
}
static int F_18 ( struct V_13 * V_14 , struct V_16 * V_16 ,
struct V_1 * V_2 )
{
struct V_12 * V_17 = F_15 ( V_14 ) ;
if ( V_17 -> V_24 == V_25 )
return - V_26 ;
F_17 ( V_2 -> V_17 , V_17 ) ;
F_17 ( V_17 -> V_21 [ V_17 -> V_22 ] , V_2 ) ;
F_19 ( & V_2 -> V_27 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_23 = V_17 -> V_22 ;
V_2 -> V_19 = true ;
V_16 -> V_28 = V_2 ;
F_20 ( & V_2 -> V_29 , & V_17 -> V_30 ) ;
V_17 -> V_22 ++ ;
V_17 -> V_24 ++ ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
struct V_1 * V_31 ;
F_16 () ;
if ( ! V_2 -> V_19 )
return - V_9 ;
V_17 = F_22 ( V_2 -> V_17 ) ;
if ( V_17 ) {
int V_32 = V_2 -> V_23 ;
F_23 ( V_32 >= V_17 -> V_22 ) ;
V_31 = F_22 ( V_17 -> V_21 [ V_17 -> V_22 - 1 ] ) ;
V_31 -> V_23 = V_32 ;
F_17 ( V_17 -> V_21 [ V_32 ] , V_31 ) ;
F_24 ( V_17 -> V_21 [ V_17 -> V_22 - 1 ] , NULL ) ;
V_2 -> V_19 = false ;
V_17 -> V_22 -- ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
F_26 () ;
V_17 = F_22 ( V_2 -> V_17 ) ;
if ( V_17 ) {
if ( V_2 -> V_19 )
F_23 ( F_21 ( V_2 ) ) ;
V_17 -> V_24 -- ;
F_24 ( V_2 -> V_17 , NULL ) ;
F_27 ( & V_2 -> V_27 ) ;
F_28 ( & V_2 -> V_29 ) ;
}
F_29 () ;
F_30 () ;
F_27 ( & V_2 -> V_27 ) ;
}
static struct V_1 * F_31 ( struct V_13 * V_14 ,
struct V_33 * V_34 )
{
struct V_12 * V_17 = F_15 ( V_14 ) ;
struct V_1 * V_35 = NULL ;
int V_22 = F_32 ( V_17 -> V_22 ) ;
T_4 V_36 ;
if ( ! V_22 )
goto V_20;
V_36 = F_33 ( V_34 ) ;
if ( V_36 ) {
V_35 = F_13 ( V_17 -> V_21 [ V_36 % V_22 ] ) ;
goto V_20;
}
if ( F_34 ( F_35 ( V_34 ) ) ) {
V_36 = F_36 ( V_34 ) ;
while ( F_37 ( V_36 >= V_22 ) )
V_36 -= V_22 ;
V_35 = F_13 ( V_17 -> V_21 [ V_36 ] ) ;
goto V_20;
}
V_35 = F_13 ( V_17 -> V_21 [ 0 ] ) ;
V_20:
return V_35 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_12 * V_17 = F_15 ( V_14 ) ;
struct V_1 * V_2 , * V_37 ;
F_16 () ;
F_39 (q, tmp, &vlan->queue_list, next) {
F_28 ( & V_2 -> V_29 ) ;
F_24 ( V_2 -> V_17 , NULL ) ;
if ( V_2 -> V_19 )
V_17 -> V_22 -- ;
V_17 -> V_24 -- ;
F_27 ( & V_2 -> V_27 ) ;
}
F_23 ( V_17 -> V_22 ) ;
F_23 ( V_17 -> V_24 ) ;
V_17 -> V_22 = V_25 ;
}
static T_5 F_40 ( struct V_33 * * V_38 )
{
struct V_33 * V_34 = * V_38 ;
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_12 * V_17 ;
struct V_1 * V_2 ;
T_6 V_39 = V_40 ;
V_17 = F_12 ( V_14 ) ;
if ( ! V_17 )
return V_41 ;
V_2 = F_31 ( V_14 , V_34 ) ;
if ( ! V_2 )
return V_41 ;
if ( F_41 ( & V_2 -> V_27 . V_42 ) >= V_14 -> V_43 )
goto V_44;
F_42 ( V_34 , V_45 ) ;
if ( V_2 -> V_3 & V_46 )
V_39 |= V_17 -> V_47 ;
if ( F_43 ( V_34 , V_39 ) ) {
struct V_33 * V_48 = F_44 ( V_34 , V_39 , false ) ;
if ( F_45 ( V_48 ) )
goto V_44;
if ( ! V_48 ) {
F_46 ( & V_2 -> V_27 . V_42 , V_34 ) ;
goto V_49;
}
F_47 ( V_34 ) ;
while ( V_48 ) {
struct V_33 * V_50 = V_48 -> V_29 ;
V_48 -> V_29 = NULL ;
F_46 ( & V_2 -> V_27 . V_42 , V_48 ) ;
V_48 = V_50 ;
}
} else {
if ( V_34 -> V_51 == V_52 &&
! ( V_39 & V_53 ) &&
F_48 ( V_34 ) )
goto V_44;
F_46 ( & V_2 -> V_27 . V_42 , V_34 ) ;
}
V_49:
F_49 ( F_50 ( & V_2 -> V_27 ) , V_54 | V_55 | V_56 ) ;
return V_57 ;
V_44:
F_51 ( V_17 , 0 , 0 , 0 ) ;
F_47 ( V_34 ) ;
return V_57 ;
}
static int F_52 ( struct V_12 * V_17 )
{
int V_58 = - V_59 ;
F_53 ( & V_60 ) ;
V_58 = F_54 ( & V_61 , V_17 , 1 , V_62 , V_63 ) ;
if ( V_58 >= 0 ) {
V_17 -> V_64 = V_58 ;
} else if ( V_58 == - V_65 ) {
F_55 ( V_66 L_1 ) ;
V_58 = - V_9 ;
}
F_56 ( & V_60 ) ;
return V_58 < 0 ? V_58 : 0 ;
}
static void F_57 ( struct V_12 * V_17 )
{
F_53 ( & V_60 ) ;
if ( V_17 -> V_64 ) {
F_58 ( & V_61 , V_17 -> V_64 ) ;
V_17 -> V_64 = 0 ;
}
F_56 ( & V_60 ) ;
}
static struct V_13 * F_59 ( int V_64 )
{
struct V_13 * V_14 = NULL ;
struct V_12 * V_17 ;
F_53 ( & V_60 ) ;
V_17 = F_60 ( & V_61 , V_64 ) ;
if ( V_17 ) {
V_14 = V_17 -> V_14 ;
F_61 ( V_14 ) ;
}
F_56 ( & V_60 ) ;
return V_14 ;
}
static int F_62 ( struct V_67 * V_68 ,
struct V_13 * V_14 ,
struct V_69 * V_70 [] ,
struct V_69 * V_71 [] )
{
struct V_12 * V_17 = F_15 ( V_14 ) ;
int V_18 ;
F_63 ( & V_17 -> V_30 ) ;
V_17 -> V_47 = V_72 ;
V_18 = F_64 ( V_14 , F_40 , V_17 ) ;
if ( V_18 )
return V_18 ;
return F_65 ( V_68 , V_14 , V_70 , V_71 ) ;
}
static void F_66 ( struct V_13 * V_14 ,
struct V_73 * V_74 )
{
F_67 ( V_14 ) ;
F_38 ( V_14 ) ;
F_68 ( V_14 , V_74 ) ;
}
static void F_69 ( struct V_13 * V_14 )
{
F_70 ( V_14 ) ;
V_14 -> V_43 = V_75 ;
}
static void F_71 ( struct V_76 * V_27 )
{
T_7 * V_77 ;
if ( ! F_72 ( V_27 ) ||
! F_73 ( V_78 , & V_27 -> V_79 -> V_3 ) )
return;
V_77 = F_50 ( V_27 ) ;
if ( V_77 && F_74 ( V_77 ) )
F_49 ( V_77 , V_80 | V_81 | V_82 ) ;
}
static void F_75 ( struct V_76 * V_27 )
{
F_76 ( & V_27 -> V_42 ) ;
}
static int F_77 ( struct V_83 * V_83 , struct V_16 * V_16 )
{
struct V_67 * V_67 = V_84 -> V_85 -> V_86 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_18 = - V_87 ;
F_26 () ;
V_14 = F_59 ( F_78 ( V_83 ) ) ;
if ( ! V_14 )
goto V_20;
V_18 = - V_59 ;
V_2 = (struct V_1 * ) F_79 ( V_67 , V_88 , V_63 ,
& V_89 , 0 ) ;
if ( ! V_2 )
goto V_20;
F_24 ( V_2 -> V_76 . V_90 , & V_2 -> V_90 ) ;
F_80 ( & V_2 -> V_90 . V_91 ) ;
V_2 -> V_76 . type = V_92 ;
V_2 -> V_76 . V_93 = V_94 ;
V_2 -> V_76 . V_16 = V_16 ;
V_2 -> V_76 . V_95 = & V_96 ;
F_81 ( & V_2 -> V_76 , & V_2 -> V_27 ) ;
V_2 -> V_27 . V_97 = F_71 ;
V_2 -> V_27 . V_98 = F_75 ;
V_2 -> V_3 = V_46 | V_99 | V_100 ;
V_2 -> V_101 = sizeof( struct V_102 ) ;
if ( ( V_14 -> V_39 & V_103 ) && ( V_14 -> V_39 & V_104 ) )
F_82 ( & V_2 -> V_27 , V_105 ) ;
V_18 = F_18 ( V_14 , V_16 , V_2 ) ;
if ( V_18 )
F_27 ( & V_2 -> V_27 ) ;
V_20:
if ( V_14 )
F_83 ( V_14 ) ;
F_29 () ;
return V_18 ;
}
static int F_84 ( struct V_83 * V_83 , struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_28 ;
F_25 ( V_2 ) ;
return 0 ;
}
static unsigned int F_85 ( struct V_16 * V_16 , T_8 * V_91 )
{
struct V_1 * V_2 = V_16 -> V_28 ;
unsigned int V_106 = V_107 ;
if ( ! V_2 )
goto V_20;
V_106 = 0 ;
F_86 ( V_16 , & V_2 -> V_90 . V_91 , V_91 ) ;
if ( ! F_87 ( & V_2 -> V_27 . V_42 ) )
V_106 |= V_54 | V_55 ;
if ( F_72 ( & V_2 -> V_27 ) ||
( ! F_88 ( V_78 , & V_2 -> V_76 . V_3 ) &&
F_72 ( & V_2 -> V_27 ) ) )
V_106 |= V_80 | V_81 ;
V_20:
return V_106 ;
}
static inline struct V_33 * F_89 ( struct V_76 * V_27 , T_9 V_108 ,
T_9 V_109 , T_9 V_110 ,
int V_111 , int * V_18 )
{
struct V_33 * V_34 ;
if ( V_108 + V_109 < V_112 || ! V_110 )
V_110 = V_109 ;
V_34 = F_90 ( V_27 , V_108 + V_110 , V_109 - V_110 , V_111 ,
V_18 , 0 ) ;
if ( ! V_34 )
return NULL ;
F_91 ( V_34 , V_108 ) ;
F_92 ( V_34 , V_110 ) ;
V_34 -> V_113 = V_109 - V_110 ;
V_34 -> V_109 += V_109 - V_110 ;
return V_34 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_102 * V_114 )
{
unsigned short V_115 = 0 ;
if ( V_114 -> V_115 != V_116 ) {
switch ( V_114 -> V_115 & ~ V_117 ) {
case V_118 :
V_115 = V_119 ;
break;
case V_120 :
V_115 = V_121 ;
break;
case V_122 :
V_115 = V_123 ;
break;
default:
return - V_9 ;
}
if ( V_114 -> V_115 & V_117 )
V_115 |= V_124 ;
if ( V_114 -> V_125 == 0 )
return - V_9 ;
}
if ( V_114 -> V_3 & V_126 ) {
if ( ! F_94 ( V_34 , F_8 ( V_2 , V_114 -> V_127 ) ,
F_8 ( V_2 , V_114 -> V_128 ) ) )
return - V_9 ;
}
if ( V_114 -> V_115 != V_116 ) {
F_95 ( V_34 ) -> V_125 = F_8 ( V_2 , V_114 -> V_125 ) ;
F_95 ( V_34 ) -> V_115 = V_115 ;
F_95 ( V_34 ) -> V_115 |= V_129 ;
F_95 ( V_34 ) -> V_130 = 0 ;
}
return 0 ;
}
static void F_96 ( struct V_1 * V_2 ,
const struct V_33 * V_34 ,
struct V_102 * V_114 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( F_97 ( V_34 ) ) {
struct V_131 * V_132 = F_95 ( V_34 ) ;
V_114 -> V_133 = F_10 ( V_2 , F_98 ( V_34 ) ) ;
V_114 -> V_125 = F_10 ( V_2 , V_132 -> V_125 ) ;
if ( V_132 -> V_115 & V_119 )
V_114 -> V_115 = V_118 ;
else if ( V_132 -> V_115 & V_121 )
V_114 -> V_115 = V_120 ;
else if ( V_132 -> V_115 & V_123 )
V_114 -> V_115 = V_122 ;
else
F_99 () ;
if ( V_132 -> V_115 & V_124 )
V_114 -> V_115 |= V_117 ;
} else
V_114 -> V_115 = V_116 ;
if ( V_34 -> V_51 == V_52 ) {
V_114 -> V_3 = V_126 ;
if ( F_100 ( V_34 ) )
V_114 -> V_127 = F_10 ( V_2 ,
F_101 ( V_34 ) + V_134 ) ;
else
V_114 -> V_127 = F_10 ( V_2 ,
F_101 ( V_34 ) ) ;
V_114 -> V_128 = F_10 ( V_2 , V_34 -> V_128 ) ;
} else if ( V_34 -> V_51 == V_135 ) {
V_114 -> V_3 = V_136 ;
}
}
static T_10 F_102 ( struct V_1 * V_2 , struct V_137 * V_138 ,
struct V_139 * V_140 , int V_111 )
{
int V_141 = F_103 ( V_142 ) ;
struct V_33 * V_34 ;
struct V_12 * V_17 ;
unsigned long V_143 = F_104 ( V_140 ) ;
unsigned long V_109 = V_143 ;
int V_18 ;
struct V_102 V_114 = { 0 } ;
int V_144 = 0 ;
int V_145 = 0 ;
int V_146 ;
bool V_147 = false ;
T_9 V_110 ;
T_10 V_148 ;
if ( V_2 -> V_3 & V_46 ) {
V_144 = V_2 -> V_101 ;
V_18 = - V_9 ;
if ( V_109 < V_144 )
goto V_18;
V_109 -= V_144 ;
V_18 = - V_7 ;
V_148 = F_105 ( & V_114 , sizeof( V_114 ) , V_140 ) ;
if ( V_148 != sizeof( V_114 ) )
goto V_18;
F_106 ( V_140 , V_144 - sizeof( V_114 ) ) ;
if ( ( V_114 . V_3 & V_126 ) &&
F_8 ( V_2 , V_114 . V_127 ) +
F_8 ( V_2 , V_114 . V_128 ) + 2 >
F_8 ( V_2 , V_114 . V_133 ) )
V_114 . V_133 = F_10 ( V_2 ,
F_8 ( V_2 , V_114 . V_127 ) +
F_8 ( V_2 , V_114 . V_128 ) + 2 ) ;
V_18 = - V_9 ;
if ( F_8 ( V_2 , V_114 . V_133 ) > V_109 )
goto V_18;
}
V_18 = - V_9 ;
if ( F_37 ( V_109 < V_45 ) )
goto V_18;
if ( V_138 && V_138 -> V_149 && F_107 ( & V_2 -> V_27 , V_105 ) ) {
struct V_139 V_150 ;
V_145 = V_114 . V_133 ?
F_8 ( V_2 , V_114 . V_133 ) : V_151 ;
if ( V_145 > V_141 )
V_145 = V_141 ;
V_110 = V_145 ;
V_150 = * V_140 ;
F_106 ( & V_150 , V_145 ) ;
if ( F_108 ( & V_150 , V_152 ) <= V_153 )
V_147 = true ;
}
if ( ! V_147 ) {
V_145 = V_109 ;
if ( F_8 ( V_2 , V_114 . V_133 ) > V_141 )
V_110 = V_141 ;
else
V_110 = F_8 ( V_2 , V_114 . V_133 ) ;
}
V_34 = F_89 ( & V_2 -> V_27 , V_142 , V_145 ,
V_110 , V_111 , & V_18 ) ;
if ( ! V_34 )
goto V_18;
if ( V_147 )
V_18 = F_109 ( V_34 , V_140 ) ;
else {
V_18 = F_110 ( V_34 , 0 , V_140 , V_109 ) ;
if ( ! V_18 && V_138 && V_138 -> V_149 ) {
struct V_154 * V_155 = V_138 -> V_149 ;
V_155 -> V_156 ( V_155 , false ) ;
}
}
if ( V_18 )
goto V_157;
F_111 ( V_34 , V_45 ) ;
F_112 ( V_34 ) ;
V_34 -> V_158 = F_113 ( V_34 ) -> V_159 ;
if ( V_144 ) {
V_18 = F_93 ( V_2 , V_34 , & V_114 ) ;
if ( V_18 )
goto V_157;
}
F_114 ( V_34 , V_45 ) ;
if ( ( V_34 -> V_158 == F_115 ( V_160 ) ||
V_34 -> V_158 == F_115 ( V_161 ) ) &&
F_116 ( V_34 , V_34 -> V_158 , & V_146 ) != 0 )
F_111 ( V_34 , V_146 ) ;
F_117 () ;
V_17 = F_13 ( V_2 -> V_17 ) ;
if ( V_147 ) {
F_95 ( V_34 ) -> V_162 = V_138 -> V_149 ;
F_95 ( V_34 ) -> V_163 |= V_164 ;
F_95 ( V_34 ) -> V_163 |= V_165 ;
}
if ( V_17 ) {
V_34 -> V_14 = V_17 -> V_14 ;
F_118 ( V_34 ) ;
} else {
F_47 ( V_34 ) ;
}
F_119 () ;
return V_143 ;
V_157:
F_47 ( V_34 ) ;
V_18:
F_117 () ;
V_17 = F_13 ( V_2 -> V_17 ) ;
if ( V_17 )
F_120 ( V_17 -> V_166 -> V_167 ) ;
F_119 () ;
return V_18 ;
}
static T_10 F_121 ( struct V_168 * V_169 , struct V_139 * V_140 )
{
struct V_16 * V_16 = V_169 -> V_170 ;
struct V_1 * V_2 = V_16 -> V_28 ;
return F_102 ( V_2 , NULL , V_140 , V_16 -> V_171 & V_172 ) ;
}
static T_10 F_122 ( struct V_1 * V_2 ,
const struct V_33 * V_34 ,
struct V_139 * V_173 )
{
int V_174 ;
int V_144 = 0 ;
int V_175 = 0 ;
int V_176 ;
if ( V_2 -> V_3 & V_46 ) {
struct V_102 V_114 ;
V_144 = V_2 -> V_101 ;
if ( F_104 ( V_173 ) < V_144 )
return - V_9 ;
F_96 ( V_2 , V_34 , & V_114 ) ;
if ( F_123 ( & V_114 , sizeof( V_114 ) , V_173 ) !=
sizeof( V_114 ) )
return - V_7 ;
F_106 ( V_173 , V_144 - sizeof( V_114 ) ) ;
}
V_176 = V_144 ;
V_176 += V_34 -> V_109 ;
if ( F_100 ( V_34 ) ) {
struct {
T_11 V_177 ;
T_11 V_178 ;
} V_179 ;
V_179 . V_177 = V_34 -> V_180 ;
V_179 . V_178 = F_115 ( F_124 ( V_34 ) ) ;
V_175 = F_125 ( struct V_181 , V_177 ) ;
V_176 += V_134 ;
V_174 = F_126 ( V_34 , 0 , V_173 , V_175 ) ;
if ( V_174 || ! F_104 ( V_173 ) )
goto V_182;
V_174 = F_123 ( & V_179 , sizeof( V_179 ) , V_173 ) ;
if ( V_174 != sizeof( V_179 ) || ! F_104 ( V_173 ) )
goto V_182;
}
V_174 = F_126 ( V_34 , V_175 , V_173 ,
V_34 -> V_109 - V_175 ) ;
V_182:
return V_174 ? V_174 : V_176 ;
}
static T_10 F_127 ( struct V_1 * V_2 ,
struct V_139 * V_183 ,
int V_111 )
{
F_128 ( V_91 ) ;
struct V_33 * V_34 ;
T_10 V_174 = 0 ;
if ( ! F_104 ( V_183 ) )
return 0 ;
while ( 1 ) {
if ( ! V_111 )
F_129 ( F_50 ( & V_2 -> V_27 ) , & V_91 ,
V_184 ) ;
V_34 = F_130 ( & V_2 -> V_27 . V_42 ) ;
if ( V_34 )
break;
if ( V_111 ) {
V_174 = - V_185 ;
break;
}
if ( F_131 ( V_84 ) ) {
V_174 = - V_186 ;
break;
}
F_132 () ;
}
if ( V_34 ) {
V_174 = F_122 ( V_2 , V_34 , V_183 ) ;
if ( F_37 ( V_174 < 0 ) )
F_47 ( V_34 ) ;
else
F_133 ( V_34 ) ;
}
if ( ! V_111 )
F_134 ( F_50 ( & V_2 -> V_27 ) , & V_91 ) ;
return V_174 ;
}
static T_10 F_135 ( struct V_168 * V_169 , struct V_139 * V_183 )
{
struct V_16 * V_16 = V_169 -> V_170 ;
struct V_1 * V_2 = V_16 -> V_28 ;
T_10 V_109 = F_104 ( V_183 ) , V_174 ;
V_174 = F_127 ( V_2 , V_183 , V_16 -> V_171 & V_172 ) ;
V_174 = F_136 ( T_10 , V_174 , V_109 ) ;
if ( V_174 > 0 )
V_169 -> V_187 = V_174 ;
return V_174 ;
}
static struct V_12 * F_137 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
F_16 () ;
V_17 = F_22 ( V_2 -> V_17 ) ;
if ( V_17 )
F_61 ( V_17 -> V_14 ) ;
return V_17 ;
}
static void F_138 ( struct V_12 * V_17 )
{
F_83 ( V_17 -> V_14 ) ;
}
static int F_139 ( struct V_16 * V_16 , unsigned int V_3 )
{
struct V_1 * V_2 = V_16 -> V_28 ;
struct V_12 * V_17 ;
int V_174 ;
V_17 = F_137 ( V_2 ) ;
if ( ! V_17 )
return - V_9 ;
if ( V_3 & V_188 )
V_174 = F_14 ( V_17 -> V_14 , V_16 , V_2 ) ;
else if ( V_3 & V_189 )
V_174 = F_21 ( V_2 ) ;
else
V_174 = - V_9 ;
F_138 ( V_17 ) ;
return V_174 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned long V_190 )
{
struct V_12 * V_17 ;
T_6 V_39 ;
T_6 V_191 = 0 ;
V_17 = F_22 ( V_2 -> V_17 ) ;
if ( ! V_17 )
return - V_192 ;
V_39 = V_17 -> V_14 -> V_39 ;
if ( V_190 & V_193 ) {
V_191 = V_194 ;
if ( V_190 & ( V_195 | V_196 ) ) {
if ( V_190 & V_197 )
V_191 |= V_198 ;
if ( V_190 & V_195 )
V_191 |= V_199 ;
if ( V_190 & V_196 )
V_191 |= V_200 ;
}
if ( V_190 & V_201 )
V_191 |= V_202 ;
}
if ( V_191 & ( V_199 | V_200 | V_202 ) )
V_39 |= V_203 ;
else
V_39 &= ~ V_203 ;
V_17 -> V_47 = V_191 ;
V_17 -> V_204 = V_39 ;
F_141 ( V_17 -> V_14 ) ;
return 0 ;
}
static long F_142 ( struct V_16 * V_16 , unsigned int V_205 ,
unsigned long V_190 )
{
struct V_1 * V_2 = V_16 -> V_28 ;
struct V_12 * V_17 ;
void T_1 * V_8 = ( void T_1 * ) V_190 ;
struct V_206 T_1 * V_207 = V_8 ;
unsigned int T_1 * V_208 = V_8 ;
unsigned short V_209 ;
int T_1 * V_5 = V_8 ;
struct V_210 V_211 ;
int V_6 ;
int V_174 ;
switch ( V_205 ) {
case V_212 :
if ( F_6 ( V_209 , & V_207 -> V_213 ) )
return - V_7 ;
V_174 = 0 ;
if ( ( V_209 & ~ V_214 ) != ( V_99 | V_100 ) )
V_174 = - V_9 ;
else
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_214 ) | V_209 ;
return V_174 ;
case V_215 :
F_26 () ;
V_17 = F_137 ( V_2 ) ;
if ( ! V_17 ) {
F_29 () ;
return - V_192 ;
}
V_174 = 0 ;
V_209 = V_2 -> V_3 ;
if ( F_143 ( & V_207 -> V_216 , V_17 -> V_14 -> V_217 , V_218 ) ||
F_4 ( V_209 , & V_207 -> V_213 ) )
V_174 = - V_7 ;
F_138 ( V_17 ) ;
F_29 () ;
return V_174 ;
case V_219 :
if ( F_6 ( V_209 , & V_207 -> V_213 ) )
return - V_7 ;
F_26 () ;
V_174 = F_139 ( V_16 , V_209 ) ;
F_29 () ;
return V_174 ;
case V_220 :
if ( F_4 ( V_100 | V_99 | V_214 , V_208 ) )
return - V_7 ;
return 0 ;
case V_221 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
V_2 -> V_27 . V_222 = V_6 ;
return 0 ;
case V_223 :
V_6 = V_2 -> V_101 ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_224 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 < ( int ) sizeof( struct V_102 ) )
return - V_9 ;
V_2 -> V_101 = V_6 ;
return 0 ;
case V_225 :
V_6 = ! ! ( V_2 -> V_3 & V_10 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
case V_226 :
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
case V_227 :
return F_3 ( V_2 , V_5 ) ;
case V_228 :
return F_5 ( V_2 , V_5 ) ;
case V_229 :
if ( V_190 & ~ ( V_193 | V_195 | V_196 |
V_197 | V_201 ) )
return - V_9 ;
F_26 () ;
V_174 = F_140 ( V_2 , V_190 ) ;
F_29 () ;
return V_174 ;
case V_230 :
F_26 () ;
V_17 = F_137 ( V_2 ) ;
if ( ! V_17 ) {
F_29 () ;
return - V_192 ;
}
V_174 = 0 ;
V_209 = V_17 -> V_14 -> type ;
if ( F_143 ( & V_207 -> V_216 , V_17 -> V_14 -> V_217 , V_218 ) ||
F_143 ( & V_207 -> V_231 . V_232 , V_17 -> V_14 -> V_233 , V_234 ) ||
F_4 ( V_209 , & V_207 -> V_231 . V_235 ) )
V_174 = - V_7 ;
F_138 ( V_17 ) ;
F_29 () ;
return V_174 ;
case V_236 :
if ( F_144 ( & V_211 , & V_207 -> V_231 , sizeof( V_211 ) ) )
return - V_7 ;
F_26 () ;
V_17 = F_137 ( V_2 ) ;
if ( ! V_17 ) {
F_29 () ;
return - V_192 ;
}
V_174 = F_145 ( V_17 -> V_14 , & V_211 ) ;
F_138 ( V_17 ) ;
F_29 () ;
return V_174 ;
default:
return - V_9 ;
}
}
static long F_146 ( struct V_16 * V_16 , unsigned int V_205 ,
unsigned long V_190 )
{
return F_142 ( V_16 , V_205 , ( unsigned long ) F_147 ( V_190 ) ) ;
}
static int F_148 ( struct V_237 * V_76 , struct V_137 * V_138 ,
T_9 V_143 )
{
struct V_1 * V_2 = F_149 ( V_76 , struct V_1 , V_76 ) ;
return F_102 ( V_2 , V_138 , & V_138 -> V_238 , V_138 -> V_239 & V_240 ) ;
}
static int F_150 ( struct V_237 * V_76 , struct V_137 * V_138 ,
T_9 V_143 , int V_3 )
{
struct V_1 * V_2 = F_149 ( V_76 , struct V_1 , V_76 ) ;
int V_174 ;
if ( V_3 & ~ ( V_240 | V_241 ) )
return - V_9 ;
V_174 = F_127 ( V_2 , & V_138 -> V_238 , V_3 & V_240 ) ;
if ( V_174 > V_143 ) {
V_138 -> V_239 |= V_241 ;
V_174 = V_3 & V_241 ? V_174 : V_143 ;
}
return V_174 ;
}
struct V_237 * F_151 ( struct V_16 * V_16 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_242 != & V_243 )
return F_152 ( - V_9 ) ;
V_2 = V_16 -> V_28 ;
if ( ! V_2 )
return F_152 ( - V_244 ) ;
return & V_2 -> V_76 ;
}
static int F_153 ( struct V_245 * V_246 ,
unsigned long V_247 , void * V_248 )
{
struct V_13 * V_14 = F_154 ( V_248 ) ;
struct V_12 * V_17 ;
struct V_249 * V_250 ;
T_12 V_251 ;
int V_18 ;
if ( V_14 -> V_252 != & V_253 )
return V_254 ;
V_17 = F_15 ( V_14 ) ;
switch ( V_247 ) {
case V_255 :
V_18 = F_52 ( V_17 ) ;
if ( V_18 )
return F_155 ( V_18 ) ;
V_251 = F_156 ( F_157 ( V_256 ) , V_17 -> V_64 ) ;
V_250 = F_158 ( V_257 , & V_14 -> V_14 , V_251 ,
V_14 , L_2 , V_14 -> V_258 ) ;
if ( F_45 ( V_250 ) ) {
F_57 ( V_17 ) ;
return F_155 ( F_159 ( V_250 ) ) ;
}
break;
case V_259 :
V_251 = F_156 ( F_157 ( V_256 ) , V_17 -> V_64 ) ;
F_160 ( V_257 , V_251 ) ;
F_57 ( V_17 ) ;
break;
}
return V_254 ;
}
static int F_161 ( void )
{
int V_18 ;
V_18 = F_162 ( & V_256 , 0 ,
V_62 , L_3 ) ;
if ( V_18 )
goto V_260;
F_163 ( & V_261 , & V_243 ) ;
V_18 = F_164 ( & V_261 , V_256 , V_62 ) ;
if ( V_18 )
goto V_262;
V_257 = F_165 ( V_263 , L_3 ) ;
if ( F_45 ( V_257 ) ) {
V_18 = F_159 ( V_257 ) ;
goto V_264;
}
V_18 = F_166 ( & V_265 ) ;
if ( V_18 )
goto V_266;
V_18 = F_167 ( & V_253 ) ;
if ( V_18 )
goto V_267;
return 0 ;
V_267:
F_168 ( & V_265 ) ;
V_266:
F_169 ( V_257 ) ;
V_264:
F_170 ( & V_261 ) ;
V_262:
F_171 ( V_256 , V_62 ) ;
V_260:
return V_18 ;
}
static void F_172 ( void )
{
F_173 ( & V_253 ) ;
F_168 ( & V_265 ) ;
F_169 ( V_257 ) ;
F_170 ( & V_261 ) ;
F_171 ( V_256 , V_62 ) ;
F_174 ( & V_61 ) ;
}
