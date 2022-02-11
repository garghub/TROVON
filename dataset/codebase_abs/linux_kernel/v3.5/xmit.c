static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
__acquires( &txq->axq_lock
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
static void F_4 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_9 )
return;
if ( V_6 -> V_10 )
return;
V_6 -> V_10 = true ;
F_5 ( & V_6 -> V_11 , & V_8 -> V_12 ) ;
if ( V_8 -> V_10 )
return;
V_8 -> V_10 = true ;
F_5 ( & V_8 -> V_11 , & V_4 -> V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
F_7 ( ! V_6 -> V_9 ) ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_9 = false ;
if ( F_8 ( & V_6 -> V_14 ) )
goto V_15;
F_4 ( V_4 , V_6 ) ;
F_9 ( V_2 , V_4 ) ;
V_15:
F_3 ( V_2 , V_4 ) ;
}
static struct V_16 * F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
F_12 ( sizeof( struct V_16 ) >
sizeof( V_20 -> V_21 ) ) ;
return (struct V_16 * ) & V_20 -> V_21 [ 0 ] ;
}
static void F_13 ( struct V_5 * V_6 , T_1 V_22 )
{
F_14 ( V_6 -> V_23 -> V_24 , V_6 -> V_23 -> V_25 -> V_26 , V_6 -> V_27 ,
V_22 << V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_17 * V_18 ;
struct V_29 * V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
struct V_16 * V_35 ;
bool V_36 = false ;
F_16 ( & V_32 ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
while ( ( V_18 = F_17 ( & V_6 -> V_14 ) ) ) {
V_35 = F_10 ( V_18 ) ;
V_30 = V_35 -> V_30 ;
if ( V_30 && V_35 -> V_37 ) {
F_5 ( & V_30 -> V_11 , & V_32 ) ;
F_18 ( V_2 , V_6 , V_30 -> V_38 . V_22 ) ;
F_19 ( V_2 , V_30 , V_4 , & V_32 , & V_34 , 0 ) ;
V_36 = true ;
} else {
F_20 ( V_2 , V_4 , NULL , V_18 ) ;
}
}
if ( V_6 -> V_39 == V_6 -> V_40 ) {
V_6 -> V_41 &= ~ V_42 ;
V_6 -> V_41 &= ~ V_43 ;
}
if ( V_36 ) {
F_2 ( V_2 , V_4 ) ;
F_13 ( V_6 , V_6 -> V_44 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_18 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_22 )
{
int V_45 , V_46 ;
V_45 = F_21 ( V_6 -> V_44 , V_22 ) ;
V_46 = ( V_6 -> V_39 + V_45 ) & ( V_47 - 1 ) ;
F_22 ( V_46 , V_6 -> V_48 ) ;
while ( V_6 -> V_39 != V_6 -> V_40 && ! F_23 ( V_6 -> V_39 , V_6 -> V_48 ) ) {
F_24 ( V_6 -> V_44 , V_49 ) ;
F_24 ( V_6 -> V_39 , V_47 ) ;
if ( V_6 -> V_50 >= 0 )
V_6 -> V_50 -- ;
}
}
static void F_25 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_22 )
{
int V_45 , V_46 ;
V_45 = F_21 ( V_6 -> V_44 , V_22 ) ;
V_46 = ( V_6 -> V_39 + V_45 ) & ( V_47 - 1 ) ;
F_26 ( V_46 , V_6 -> V_48 ) ;
if ( V_45 >= ( ( V_6 -> V_40 - V_6 -> V_39 ) &
( V_47 - 1 ) ) ) {
V_6 -> V_40 = V_46 ;
F_24 ( V_6 -> V_40 , V_47 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_17 * V_18 ;
struct V_29 * V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
struct V_16 * V_35 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
F_16 ( & V_32 ) ;
while ( ( V_18 = F_17 ( & V_6 -> V_14 ) ) ) {
V_35 = F_10 ( V_18 ) ;
V_30 = V_35 -> V_30 ;
if ( ! V_30 ) {
F_28 ( V_2 , V_18 , V_51 , V_4 ) ;
continue;
}
F_5 ( & V_30 -> V_11 , & V_32 ) ;
if ( V_35 -> V_37 )
F_18 ( V_2 , V_6 , V_30 -> V_38 . V_22 ) ;
F_19 ( V_2 , V_30 , V_4 , & V_32 , & V_34 , 0 ) ;
}
V_6 -> V_52 = V_6 -> V_44 ;
V_6 -> V_40 = V_6 -> V_39 ;
V_6 -> V_50 = - 1 ;
}
static void F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_17 * V_18 , int V_53 )
{
struct V_16 * V_35 = F_10 ( V_18 ) ;
struct V_29 * V_30 = V_35 -> V_30 ;
struct V_54 * V_55 ;
int V_56 = V_35 -> V_37 ;
F_30 ( V_4 -> V_57 , V_58 ) ;
V_35 -> V_37 += V_53 ;
if ( V_56 > 0 )
return;
V_55 = (struct V_54 * ) V_18 -> V_59 ;
V_55 -> V_60 |= F_31 ( V_61 ) ;
F_32 ( V_2 -> V_62 , V_30 -> V_63 ,
sizeof( * V_55 ) , V_64 ) ;
}
static struct V_29 * F_33 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = NULL ;
F_34 ( & V_2 -> V_65 . V_66 ) ;
if ( F_35 ( F_36 ( & V_2 -> V_65 . V_67 ) ) ) {
F_37 ( & V_2 -> V_65 . V_66 ) ;
return NULL ;
}
V_30 = F_38 ( & V_2 -> V_65 . V_67 , struct V_29 , V_11 ) ;
F_39 ( & V_30 -> V_11 ) ;
F_37 ( & V_2 -> V_65 . V_66 ) ;
return V_30 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
F_34 ( & V_2 -> V_65 . V_66 ) ;
F_5 ( & V_30 -> V_11 , & V_2 -> V_65 . V_67 ) ;
F_37 ( & V_2 -> V_65 . V_66 ) ;
}
static struct V_29 * F_41 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_29 * V_68 ;
V_68 = F_33 ( V_2 ) ;
if ( F_7 ( ! V_68 ) )
return NULL ;
F_42 ( V_68 ) ;
V_68 -> V_69 = V_30 -> V_69 ;
V_68 -> V_63 = V_30 -> V_63 ;
memcpy ( V_68 -> V_70 , V_30 -> V_70 , V_2 -> V_71 -> V_72 . V_73 ) ;
V_68 -> V_38 = V_30 -> V_38 ;
return V_68 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_33 * V_34 , int V_74 ,
int * V_75 , int * V_76 )
{
struct V_16 * V_35 ;
T_1 V_77 = 0 ;
V_78 V_79 [ V_80 >> 5 ] ;
int V_81 ;
int V_82 = 0 ;
* V_76 = 0 ;
* V_75 = 0 ;
V_82 = F_44 ( V_30 ) ;
if ( V_82 ) {
V_77 = V_34 -> V_83 ;
memcpy ( V_79 , & V_34 -> V_84 , V_80 >> 3 ) ;
}
while ( V_30 ) {
V_35 = F_10 ( V_30 -> V_69 ) ;
V_81 = F_21 ( V_77 , V_30 -> V_38 . V_22 ) ;
( * V_75 ) ++ ;
if ( ! V_74 || ( V_82 && ! F_45 ( V_79 , V_81 ) ) )
( * V_76 ) ++ ;
V_30 = V_30 -> V_85 ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_30 , struct V_31 * V_86 ,
struct V_33 * V_34 , int V_74 , bool V_87 )
{
struct V_88 * V_23 = NULL ;
struct V_17 * V_18 ;
struct V_89 * V_25 ;
struct V_90 * V_91 = V_2 -> V_91 ;
struct V_54 * V_55 ;
struct V_19 * V_20 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_85 , * V_92 = V_30 -> V_93 ;
struct V_31 V_32 ;
struct V_94 V_95 ;
T_1 V_77 = 0 , V_96 = 0 , V_97 = 0 , V_98 ;
V_78 V_79 [ V_80 >> 5 ] ;
int V_82 , V_99 , V_100 , V_36 = 0 , V_101 = 0 , V_76 = 0 ;
bool V_102 = true ;
struct V_103 V_104 [ 4 ] ;
struct V_16 * V_35 ;
int V_75 ;
T_2 V_27 ;
bool V_105 = ! ! ( V_34 -> V_106 & V_107 ) ;
int V_108 , V_37 ;
int V_50 = - 1 ;
V_18 = V_30 -> V_69 ;
V_55 = (struct V_54 * ) V_18 -> V_59 ;
V_20 = F_11 ( V_18 ) ;
memcpy ( V_104 , V_20 -> V_109 . V_104 , sizeof( V_104 ) ) ;
V_37 = V_34 -> V_110 + 1 ;
for ( V_108 = 0 ; V_108 < V_34 -> V_111 ; V_108 ++ )
V_37 += V_104 [ V_108 ] . V_53 ;
F_47 () ;
V_25 = F_48 ( V_91 , V_55 -> V_112 , V_55 -> V_113 ) ;
if ( ! V_25 ) {
F_49 () ;
F_16 ( & V_32 ) ;
while ( V_30 ) {
V_85 = V_30 -> V_85 ;
if ( ! V_30 -> V_114 || V_85 != NULL )
F_50 ( & V_30 -> V_11 , & V_32 ) ;
F_19 ( V_2 , V_30 , V_4 , & V_32 , V_34 , 0 ) ;
V_30 = V_85 ;
}
return;
}
V_23 = (struct V_88 * ) V_25 -> V_115 ;
V_27 = F_51 ( V_55 ) [ 0 ] & V_116 ;
V_6 = F_52 ( V_23 , V_27 ) ;
V_98 = V_6 -> V_44 ;
if ( V_27 != V_34 -> V_6 )
V_74 = false ;
V_82 = F_44 ( V_30 ) ;
memset ( V_79 , 0 , V_80 >> 3 ) ;
if ( V_82 && V_74 ) {
if ( V_34 -> V_117 & V_118 ) {
V_77 = V_34 -> V_83 ;
memcpy ( V_79 , & V_34 -> V_84 , V_80 >> 3 ) ;
} else {
if ( V_2 -> V_71 -> V_119 == V_120 )
V_101 = 1 ;
}
}
F_53 ( & V_95 ) ;
F_43 ( V_2 , V_30 , V_34 , V_74 , & V_75 , & V_76 ) ;
while ( V_30 ) {
T_1 V_22 = V_30 -> V_38 . V_22 ;
V_99 = V_100 = V_36 = 0 ;
V_85 = V_30 -> V_85 ;
V_18 = V_30 -> V_69 ;
V_20 = F_11 ( V_18 ) ;
V_35 = F_10 ( V_18 ) ;
if ( F_45 ( V_79 , F_21 ( V_77 , V_22 ) ) ) {
V_96 ++ ;
} else if ( ! V_82 && V_74 ) {
V_96 ++ ;
} else if ( ( V_6 -> V_41 & V_43 ) || ! V_87 ) {
V_99 = 1 ;
} else if ( V_105 ) {
V_100 = 1 ;
} else if ( V_35 -> V_37 < V_121 ) {
if ( V_74 || ! V_23 -> V_122 )
F_29 ( V_2 , V_4 , V_30 -> V_69 ,
V_37 ) ;
V_100 = 1 ;
} else {
V_99 = 1 ;
V_97 ++ ;
V_50 = F_54 ( int , V_50 ,
F_21 ( V_98 , V_22 ) ) ;
}
F_16 ( & V_32 ) ;
if ( ( V_2 -> V_71 -> V_72 . V_123 & V_124 ) ||
V_85 != NULL || ! V_92 -> V_114 )
F_50 ( & V_30 -> V_11 , & V_32 ) ;
if ( ! V_100 || ( V_6 -> V_41 & V_43 ) ) {
F_18 ( V_2 , V_6 , V_22 ) ;
if ( V_102 && ( V_96 == 1 || V_97 == 1 ) ) {
memcpy ( V_20 -> V_109 . V_104 , V_104 , sizeof( V_104 ) ) ;
F_55 ( V_2 , V_30 , V_34 , V_75 , V_76 , V_74 ) ;
V_102 = false ;
}
F_19 ( V_2 , V_30 , V_4 , & V_32 , V_34 ,
! V_99 ) ;
} else {
if ( ! ( V_2 -> V_71 -> V_72 . V_123 & V_124 ) &&
V_30 -> V_85 == NULL && V_92 -> V_114 ) {
struct V_29 * V_68 ;
V_68 = F_41 ( V_2 , V_92 ) ;
if ( ! V_68 ) {
F_18 ( V_2 , V_6 , V_22 ) ;
F_19 ( V_2 , V_30 , V_4 ,
& V_32 , V_34 , 0 ) ;
V_50 = F_54 ( int , V_50 ,
F_21 ( V_98 , V_22 ) ) ;
break;
}
V_35 -> V_30 = V_68 ;
}
F_56 ( & V_95 , V_18 ) ;
}
V_30 = V_85 ;
}
if ( ! F_8 ( & V_95 ) ) {
if ( V_23 -> V_122 )
F_57 ( V_25 , V_6 -> V_27 , true ) ;
F_58 ( & V_95 , & V_6 -> V_14 ) ;
if ( ! V_23 -> V_122 ) {
F_4 ( V_4 , V_6 ) ;
if ( V_34 -> V_106 & V_125 )
V_6 -> V_8 -> V_126 = true ;
}
}
if ( V_50 >= 0 ) {
T_1 V_127 = F_59 ( V_98 , V_50 ) ;
if ( F_60 ( V_6 -> V_44 , V_6 -> V_128 , V_127 ) )
V_6 -> V_50 = F_21 ( V_6 -> V_44 , V_127 ) ;
F_2 ( V_2 , V_4 ) ;
F_13 ( V_6 , F_59 ( V_98 , V_50 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
if ( V_6 -> V_41 & V_43 )
F_15 ( V_2 , V_6 ) ;
F_49 () ;
if ( V_101 ) {
F_61 ( V_2 , V_129 ) ;
F_62 ( V_2 -> V_91 , & V_2 -> V_130 ) ;
}
}
static bool F_63 ( struct V_29 * V_30 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_103 * V_104 ;
int V_108 ;
V_18 = V_30 -> V_69 ;
V_20 = F_11 ( V_18 ) ;
V_104 = V_20 -> V_109 . V_104 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
if ( ! V_104 [ V_108 ] . V_53 || V_104 [ V_108 ] . V_131 < 0 )
break;
if ( ! ( V_104 [ V_108 ] . V_132 & V_133 ) )
return true ;
}
return false ;
}
static V_78 F_64 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_103 * V_104 ;
V_78 V_134 , V_135 ;
T_1 V_136 , V_137 , V_138 = 0 ;
int V_108 ;
V_18 = V_30 -> V_69 ;
V_20 = F_11 ( V_18 ) ;
V_104 = V_20 -> V_109 . V_104 ;
V_134 = V_139 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
int V_140 ;
if ( ! V_104 [ V_108 ] . V_53 )
continue;
if ( ! ( V_104 [ V_108 ] . V_132 & V_133 ) ) {
V_138 = 1 ;
break;
}
if ( V_104 [ V_108 ] . V_132 & V_141 )
V_140 = V_142 ;
else
V_140 = V_143 ;
if ( V_104 [ V_108 ] . V_132 & V_144 )
V_140 ++ ;
V_135 = V_145 [ V_140 ] [ V_104 [ V_108 ] . V_131 ] ;
V_134 = F_65 ( V_134 , V_135 ) ;
}
if ( V_20 -> V_132 & V_146 || V_138 )
return 0 ;
V_136 = F_65 ( V_134 , ( V_78 ) V_139 ) ;
V_137 = F_66 ( V_2 , V_134 ) ;
if ( V_137 )
V_136 = V_137 ;
if ( V_6 -> V_23 -> V_147 )
V_136 = F_65 ( V_136 , V_6 -> V_23 -> V_147 ) ;
return V_136 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 V_135 ,
bool V_148 )
{
#define F_68 60
struct V_17 * V_18 = V_30 -> V_69 ;
struct V_19 * V_20 = F_11 ( V_18 ) ;
V_78 V_149 , V_150 ;
T_1 V_151 ;
T_2 V_132 , V_152 ;
int V_153 , V_154 , V_155 , V_156 , V_157 ;
struct V_16 * V_35 = F_10 ( V_30 -> V_69 ) ;
V_156 = F_69 ( V_135 ) ;
if ( ( V_35 -> V_158 != V_159 ) &&
! ( V_2 -> V_71 -> V_72 . V_123 & V_124 ) )
V_156 += V_160 ;
if ( V_148 && ! F_70 ( V_2 -> V_71 ) &&
( V_2 -> V_71 -> V_161 & V_162 ) )
V_156 = F_71 ( V_156 , F_68 ) ;
if ( V_6 -> V_23 -> V_163 == 0 )
return V_156 ;
V_152 = V_20 -> V_109 . V_104 [ 0 ] . V_131 ;
V_132 = V_20 -> V_109 . V_104 [ 0 ] . V_132 ;
V_153 = ( V_132 & V_141 ) ? 1 : 0 ;
V_155 = ( V_132 & V_144 ) ? 1 : 0 ;
if ( V_155 )
V_150 = F_72 ( V_6 -> V_23 -> V_163 ) ;
else
V_150 = F_73 ( V_6 -> V_23 -> V_163 ) ;
if ( V_150 == 0 )
V_150 = 1 ;
V_154 = F_74 ( V_152 ) ;
V_149 = V_164 [ V_152 % 8 ] [ V_153 ] * V_154 ;
V_151 = ( V_150 * V_149 ) / V_165 ;
if ( V_135 < V_151 ) {
V_157 = ( V_151 - V_135 ) / V_166 ;
V_156 = F_71 ( V_157 , V_156 ) ;
}
return V_156 ;
}
static enum V_167 F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_31 * V_86 ,
int * V_168 )
{
#define F_76 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_29 * V_30 , * V_169 = NULL , * V_170 = NULL ;
int V_171 = 0 , V_75 = 0 , V_156 , V_172 = 0 ;
T_1 V_136 = 0 , V_173 = 0 , V_174 = 0 ,
V_175 , V_176 = V_6 -> V_128 / 2 ;
enum V_167 V_177 = V_178 ;
struct V_19 * V_20 ;
struct V_16 * V_35 ;
struct V_17 * V_18 ;
T_1 V_22 ;
do {
V_18 = F_77 ( & V_6 -> V_14 ) ;
V_35 = F_10 ( V_18 ) ;
V_30 = V_35 -> V_30 ;
if ( ! V_35 -> V_30 )
V_30 = F_78 ( V_2 , V_4 , V_6 , V_18 , true ) ;
if ( ! V_30 )
continue;
V_30 -> V_38 . V_179 = V_180 | V_181 ;
V_22 = V_30 -> V_38 . V_22 ;
if ( ! F_60 ( V_6 -> V_44 , V_6 -> V_128 , V_22 ) ) {
V_177 = V_182 ;
break;
}
if ( V_6 -> V_50 > F_21 ( V_6 -> V_44 , V_22 ) ) {
struct V_33 V_34 = {} ;
struct V_31 V_32 ;
F_16 ( & V_32 ) ;
F_79 ( & V_30 -> V_11 , & V_32 ) ;
F_80 ( V_18 , & V_6 -> V_14 ) ;
F_18 ( V_2 , V_6 , V_22 ) ;
F_19 ( V_2 , V_30 , V_4 , & V_32 , & V_34 , 0 ) ;
continue;
}
if ( ! V_169 )
V_169 = V_30 ;
if ( ! V_171 ) {
V_136 = F_64 ( V_2 , V_30 , V_6 ) ;
V_171 = 1 ;
}
V_175 = V_166 + V_35 -> V_183 ;
if ( V_75 &&
( ( V_136 < ( V_173 + V_174 + V_175 + V_172 ) ) ||
F_63 ( V_30 ) ) ) {
V_177 = V_184 ;
break;
}
V_20 = F_11 ( V_30 -> V_69 ) ;
if ( V_75 && ( V_20 -> V_132 & V_146 ) )
break;
if ( V_75 >= F_65 ( ( int ) V_176 , V_185 ) ) {
V_177 = V_184 ;
break;
}
V_173 += V_174 + V_175 ;
V_156 = F_67 ( V_2 , V_6 , V_169 , V_35 -> V_183 ,
! V_75 ) ;
V_174 = F_76 ( V_175 ) + ( V_156 << 2 ) ;
V_75 ++ ;
V_30 -> V_85 = NULL ;
if ( ! V_35 -> V_37 )
F_25 ( V_2 , V_6 , V_22 ) ;
V_30 -> V_38 . V_156 = V_156 ;
F_80 ( V_18 , & V_6 -> V_14 ) ;
F_5 ( & V_30 -> V_11 , V_86 ) ;
if ( V_170 )
V_170 -> V_85 = V_30 ;
V_170 = V_30 ;
} while ( ! F_8 ( & V_6 -> V_14 ) );
* V_168 = V_173 ;
return V_177 ;
#undef F_76
}
static V_78 F_81 ( struct V_1 * V_2 , T_2 V_152 , int V_186 ,
int V_153 , int V_155 , bool V_187 )
{
V_78 V_188 , V_149 , V_189 , V_150 ;
int V_154 ;
V_154 = F_74 ( V_152 ) ;
V_188 = ( V_186 << 3 ) + V_190 ;
V_149 = V_164 [ V_152 % 8 ] [ V_153 ] * V_154 ;
V_150 = ( V_188 + V_149 - 1 ) / V_149 ;
if ( ! V_155 )
V_189 = F_82 ( V_150 ) ;
else
V_189 = F_83 ( V_150 ) ;
V_189 += V_191 + V_192 + V_193 + V_194 + V_195 + F_84 ( V_154 ) ;
return V_189 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_196 * V_197 , int V_198 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_103 * V_104 ;
const struct V_201 * V_202 ;
struct V_54 * V_55 ;
struct V_16 * V_35 = F_10 ( V_30 -> V_69 ) ;
int V_108 ;
T_2 V_152 = 0 ;
V_18 = V_30 -> V_69 ;
V_20 = F_11 ( V_18 ) ;
V_104 = V_20 -> V_109 . V_104 ;
V_55 = (struct V_54 * ) V_18 -> V_59 ;
V_197 -> V_203 = ! F_86 ( V_55 -> V_60 ) ;
V_197 -> V_204 = V_35 -> V_204 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
bool V_205 , V_206 , V_207 ;
int V_208 ;
if ( ! V_104 [ V_108 ] . V_53 || ( V_104 [ V_108 ] . V_131 < 0 ) )
continue;
V_152 = V_104 [ V_108 ] . V_131 ;
V_197 -> V_104 [ V_108 ] . V_209 = V_104 [ V_108 ] . V_53 ;
if ( V_104 [ V_108 ] . V_132 & V_210 ) {
V_197 -> V_104 [ V_108 ] . V_211 |= V_212 ;
V_197 -> V_132 |= V_213 ;
} else if ( V_104 [ V_108 ] . V_132 & V_214 ) {
V_197 -> V_104 [ V_108 ] . V_211 |= V_212 ;
V_197 -> V_132 |= V_215 ;
}
if ( V_104 [ V_108 ] . V_132 & V_141 )
V_197 -> V_104 [ V_108 ] . V_211 |= V_216 ;
if ( V_104 [ V_108 ] . V_132 & V_144 )
V_197 -> V_104 [ V_108 ] . V_211 |= V_217 ;
V_206 = ! ! ( V_104 [ V_108 ] . V_132 & V_144 ) ;
V_205 = ! ! ( V_104 [ V_108 ] . V_132 & V_141 ) ;
V_207 = ! ! ( V_104 [ V_108 ] . V_132 & V_218 ) ;
if ( V_104 [ V_108 ] . V_132 & V_133 ) {
V_197 -> V_104 [ V_108 ] . V_219 = V_152 | 0x80 ;
V_197 -> V_104 [ V_108 ] . V_220 = F_87 ( V_2 ,
V_200 -> V_221 , V_197 -> V_104 [ V_108 ] . V_219 ) ;
V_197 -> V_104 [ V_108 ] . V_222 = F_81 ( V_2 , V_152 , V_198 ,
V_205 , V_206 , V_207 ) ;
if ( V_152 < 8 && ( V_20 -> V_132 & V_223 ) )
V_197 -> V_104 [ V_108 ] . V_211 |= V_224 ;
continue;
}
V_202 = & V_2 -> V_225 [ V_20 -> V_226 ] . V_227 [ V_104 [ V_108 ] . V_131 ] ;
if ( ( V_20 -> V_226 == V_228 ) &&
! ( V_202 -> V_132 & V_229 ) )
V_208 = V_230 ;
else
V_208 = V_231 ;
V_197 -> V_104 [ V_108 ] . V_219 = V_202 -> V_232 ;
if ( V_202 -> V_233 ) {
if ( V_104 [ V_108 ] . V_132 & V_218 )
V_197 -> V_104 [ V_108 ] . V_219 |= V_202 -> V_233 ;
} else {
V_207 = false ;
}
if ( V_30 -> V_38 . V_234 )
V_197 -> V_104 [ V_108 ] . V_220 = V_200 -> V_221 ;
else
V_197 -> V_104 [ V_108 ] . V_220 = F_87 ( V_2 ,
V_200 -> V_221 , V_197 -> V_104 [ V_108 ] . V_219 ) ;
V_197 -> V_104 [ V_108 ] . V_222 = F_88 ( V_2 -> V_71 ,
V_208 , V_202 -> V_235 * 100 , V_198 , V_152 , V_207 ) ;
}
if ( F_44 ( V_30 ) && ( V_198 > V_2 -> V_71 -> V_72 . V_236 ) )
V_197 -> V_132 &= ~ V_213 ;
if ( V_197 -> V_132 & V_213 )
V_197 -> V_132 &= ~ V_215 ;
}
static enum V_237 F_89 ( struct V_17 * V_18 )
{
struct V_54 * V_55 ;
enum V_237 V_238 ;
T_4 V_239 ;
V_55 = (struct V_54 * ) V_18 -> V_59 ;
V_239 = V_55 -> V_60 ;
if ( F_90 ( V_239 ) )
V_238 = V_240 ;
else if ( F_91 ( V_239 ) )
V_238 = V_241 ;
else if ( F_92 ( V_239 ) )
V_238 = V_242 ;
else if ( F_86 ( V_239 ) )
V_238 = V_243 ;
else
V_238 = V_244 ;
return V_238 ;
}
static void F_93 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , int V_198 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_19 * V_20 = F_11 ( V_30 -> V_69 ) ;
struct V_29 * V_169 = V_30 ;
struct V_196 V_197 ;
bool V_245 = ! ! ( V_30 -> V_38 . V_179 & V_181 ) ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_246 = true ;
V_197 . V_247 = true ;
V_197 . V_248 = V_249 ;
V_197 . V_250 = V_4 -> V_57 ;
V_197 . V_132 = V_251 ;
if ( V_20 -> V_132 & V_252 )
V_197 . V_132 |= V_253 ;
if ( V_20 -> V_132 & V_254 )
V_197 . V_132 |= V_255 ;
F_85 ( V_2 , V_30 , & V_197 , V_198 ) ;
if ( V_20 -> V_132 & V_256 )
V_197 . V_132 |= V_257 ;
if ( V_30 -> V_38 . V_234 )
V_197 . V_132 |= ( V_78 ) V_30 -> V_38 . V_234 << V_258 ;
while ( V_30 ) {
struct V_17 * V_18 = V_30 -> V_69 ;
struct V_16 * V_35 = F_10 ( V_18 ) ;
V_197 . type = F_89 ( V_18 ) ;
if ( V_30 -> V_85 )
V_197 . V_259 = V_30 -> V_85 -> V_260 ;
else
V_197 . V_259 = 0 ;
V_197 . V_261 [ 0 ] = V_30 -> V_63 ;
V_197 . V_262 [ 0 ] = V_18 -> V_198 ;
V_197 . V_263 = V_35 -> V_183 ;
V_197 . V_158 = V_35 -> V_158 ;
V_197 . V_264 = V_35 -> V_264 ;
if ( V_245 ) {
if ( V_30 == V_169 )
V_197 . V_245 = V_265 ;
else if ( ! V_30 -> V_85 )
V_197 . V_245 = V_266 ;
else
V_197 . V_245 = V_267 ;
V_197 . V_156 = V_30 -> V_38 . V_156 ;
V_197 . V_168 = V_198 ;
}
F_94 ( V_200 , V_30 -> V_70 , & V_197 ) ;
V_30 = V_30 -> V_85 ;
}
}
static void F_95 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_29 * V_30 ;
enum V_167 V_177 ;
struct V_19 * V_20 ;
struct V_31 V_86 ;
int V_168 ;
do {
if ( F_8 ( & V_6 -> V_14 ) )
return;
F_16 ( & V_86 ) ;
V_177 = F_75 ( V_2 , V_4 , V_6 , & V_86 , & V_168 ) ;
if ( F_36 ( & V_86 ) )
break;
V_30 = F_38 ( & V_86 , struct V_29 , V_11 ) ;
V_30 -> V_93 = F_96 ( V_86 . V_56 , struct V_29 , V_11 ) ;
V_20 = F_11 ( V_30 -> V_69 ) ;
if ( V_6 -> V_8 -> V_126 ) {
V_6 -> V_8 -> V_126 = false ;
V_20 -> V_132 |= V_256 ;
} else {
V_20 -> V_132 &= ~ V_256 ;
}
if ( V_30 == V_30 -> V_93 ) {
V_168 = F_10 ( V_30 -> V_69 ) -> V_183 ;
V_30 -> V_38 . V_179 = V_180 ;
} else {
F_30 ( V_4 -> V_57 , V_268 ) ;
}
F_93 ( V_2 , V_30 , V_4 , V_168 ) ;
F_97 ( V_2 , V_4 , & V_86 , false ) ;
} while ( V_4 -> V_269 < V_270 &&
V_177 != V_182 );
}
int F_98 ( struct V_1 * V_2 , struct V_89 * V_25 ,
T_1 V_6 , T_1 * V_271 )
{
struct V_5 * V_272 ;
struct V_88 * V_23 ;
V_23 = (struct V_88 * ) V_25 -> V_115 ;
V_272 = F_52 ( V_23 , V_6 ) ;
if ( V_272 -> V_41 & ( V_43 | V_42 ) )
return - V_273 ;
V_272 -> V_41 |= V_274 ;
V_272 -> V_9 = true ;
* V_271 = V_272 -> V_44 = V_272 -> V_52 ;
V_272 -> V_50 = - 1 ;
memset ( V_272 -> V_48 , 0 , sizeof( V_272 -> V_48 ) ) ;
V_272 -> V_39 = V_272 -> V_40 = 0 ;
return 0 ;
}
void F_99 ( struct V_1 * V_2 , struct V_89 * V_25 , T_1 V_6 )
{
struct V_88 * V_23 = (struct V_88 * ) V_25 -> V_115 ;
struct V_5 * V_272 = F_52 ( V_23 , V_6 ) ;
struct V_3 * V_4 = V_272 -> V_8 -> V_4 ;
if ( V_272 -> V_41 & V_43 )
return;
if ( ! ( V_272 -> V_41 & V_42 ) ) {
V_272 -> V_41 &= ~ V_274 ;
return;
}
F_1 ( V_2 , V_4 ) ;
V_272 -> V_9 = true ;
if ( V_272 -> V_39 != V_272 -> V_40 )
V_272 -> V_41 |= V_43 ;
else
V_272 -> V_41 &= ~ V_42 ;
F_15 ( V_2 , V_272 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_100 ( struct V_89 * V_25 , struct V_1 * V_2 ,
struct V_88 * V_23 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_275 ;
int V_27 ;
for ( V_27 = 0 , V_6 = & V_23 -> V_6 [ V_27 ] ;
V_27 < V_276 ; V_27 ++ , V_6 ++ ) {
if ( ! V_6 -> V_10 )
continue;
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_275 = ! F_8 ( & V_6 -> V_14 ) ;
V_6 -> V_10 = false ;
F_39 ( & V_6 -> V_11 ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = false ;
F_39 ( & V_8 -> V_11 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_57 ( V_25 , V_27 , V_275 ) ;
}
}
void F_101 ( struct V_1 * V_2 , struct V_88 * V_23 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_27 ;
for ( V_27 = 0 , V_6 = & V_23 -> V_6 [ V_27 ] ;
V_27 < V_276 ; V_27 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_126 = true ;
if ( ! F_8 ( & V_6 -> V_14 ) && ! V_6 -> V_9 ) {
F_4 ( V_4 , V_6 ) ;
F_9 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_102 ( struct V_1 * V_2 , struct V_89 * V_25 , T_1 V_6 )
{
struct V_5 * V_272 ;
struct V_88 * V_23 ;
V_23 = (struct V_88 * ) V_25 -> V_115 ;
V_272 = F_52 ( V_23 , V_6 ) ;
V_272 -> V_128 = V_277 << V_25 -> V_278 . V_279 ;
V_272 -> V_41 |= V_42 ;
V_272 -> V_41 &= ~ V_274 ;
F_6 ( V_2 , V_272 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 , * V_280 ;
struct V_5 * V_6 , * V_281 ;
F_104 (ac, ac_tmp, &txq->axq_acq, list) {
F_39 ( & V_8 -> V_11 ) ;
V_8 -> V_10 = false ;
F_104 (tid, tid_tmp, &ac->tid_q, list) {
F_39 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
F_27 ( V_2 , V_4 , V_6 ) ;
}
}
}
struct V_3 * F_105 ( struct V_1 * V_2 , int V_282 , int V_283 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_284 V_285 ;
static const int V_286 [] = {
[ V_287 ] = V_288 ,
[ V_289 ] = V_290 ,
[ V_291 ] = V_292 ,
[ V_293 ] = V_294 ,
} ;
int V_57 , V_108 ;
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
V_285 . V_295 = V_286 [ V_283 ] ;
V_285 . V_296 = V_297 ;
V_285 . V_298 = V_297 ;
V_285 . V_299 = V_297 ;
V_285 . V_300 = 0 ;
if ( V_200 -> V_72 . V_123 & V_124 ) {
V_285 . V_301 = V_302 ;
} else {
if ( V_282 == V_303 )
V_285 . V_301 = V_304 ;
else
V_285 . V_301 = V_305 |
V_304 ;
}
V_57 = F_106 ( V_200 , V_282 , & V_285 ) ;
if ( V_57 == - 1 ) {
return NULL ;
}
if ( ! F_107 ( V_2 , V_57 ) ) {
struct V_3 * V_4 = & V_2 -> V_65 . V_4 [ V_57 ] ;
V_4 -> V_57 = V_57 ;
V_4 -> V_306 = - 1 ;
V_4 -> V_307 = NULL ;
F_53 ( & V_4 -> V_308 ) ;
F_16 ( & V_4 -> V_309 ) ;
F_16 ( & V_4 -> V_13 ) ;
F_108 ( & V_4 -> V_310 ) ;
V_4 -> V_311 = 0 ;
V_4 -> V_269 = 0 ;
V_4 -> V_312 = false ;
V_2 -> V_65 . V_313 |= 1 << V_57 ;
V_4 -> V_314 = V_4 -> V_315 = 0 ;
for ( V_108 = 0 ; V_108 < V_316 ; V_108 ++ )
F_16 ( & V_4 -> V_317 [ V_108 ] ) ;
}
return & V_2 -> V_65 . V_4 [ V_57 ] ;
}
int F_109 ( struct V_1 * V_2 , int V_318 ,
struct V_284 * V_319 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
int error = 0 ;
struct V_284 V_285 ;
if ( V_318 == V_2 -> V_320 . V_321 ) {
V_2 -> V_320 . V_322 = * V_319 ;
return 0 ;
}
F_110 ( V_2 -> V_65 . V_4 [ V_318 ] . V_57 != V_318 ) ;
F_111 ( V_200 , V_318 , & V_285 ) ;
V_285 . V_296 = V_319 -> V_296 ;
V_285 . V_298 = V_319 -> V_298 ;
V_285 . V_299 = V_319 -> V_299 ;
V_285 . V_323 = V_319 -> V_323 ;
V_285 . V_324 = V_319 -> V_324 ;
if ( ! F_112 ( V_200 , V_318 , & V_285 ) ) {
F_113 ( F_114 ( V_2 -> V_71 ) ,
L_1 , V_318 ) ;
error = - V_325 ;
} else {
F_115 ( V_200 , V_318 ) ;
}
return error ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_284 V_285 ;
struct V_326 * V_327 = & V_2 -> V_328 ;
int V_318 = V_2 -> V_320 . V_329 -> V_57 ;
F_111 ( V_2 -> V_71 , V_318 , & V_285 ) ;
if ( V_2 -> V_330 . V_331 < V_332 )
V_2 -> V_330 . V_331 = V_332 ;
else if ( V_2 -> V_330 . V_331 > V_333 )
V_2 -> V_330 . V_331 = V_333 ;
V_285 . V_324 = ( V_327 -> V_334 *
V_2 -> V_330 . V_331 ) / 100 ;
F_109 ( V_2 , V_318 , & V_285 ) ;
return 0 ;
}
static bool F_117 ( struct V_29 * V_30 )
{
struct V_19 * V_197 = F_11 ( V_30 -> V_69 ) ;
return F_118 ( V_30 ) && ! ( V_197 -> V_132 & V_146 ) ;
}
static void F_119 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_31 * V_11 , bool V_335 )
{
struct V_29 * V_30 , * V_336 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_106 = V_107 ;
F_16 ( & V_32 ) ;
while ( ! F_36 ( V_11 ) ) {
V_30 = F_38 ( V_11 , struct V_29 , V_11 ) ;
if ( V_30 -> V_114 ) {
F_39 ( & V_30 -> V_11 ) ;
F_40 ( V_2 , V_30 ) ;
continue;
}
V_336 = V_30 -> V_93 ;
F_120 ( & V_32 , V_11 , & V_336 -> V_11 ) ;
V_4 -> V_311 -- ;
if ( F_117 ( V_30 ) )
V_4 -> V_269 -- ;
if ( F_118 ( V_30 ) )
F_46 ( V_2 , V_4 , V_30 , & V_32 , & V_34 , 0 ,
V_335 ) ;
else
F_19 ( V_2 , V_30 , V_4 , & V_32 , & V_34 , 0 ) ;
}
}
void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_335 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_71 -> V_72 . V_123 & V_124 ) {
int V_131 = V_4 -> V_315 ;
while ( ! F_36 ( & V_4 -> V_317 [ V_131 ] ) ) {
F_119 ( V_2 , V_4 , & V_4 -> V_317 [ V_131 ] ,
V_335 ) ;
F_24 ( V_131 , V_316 ) ;
}
V_4 -> V_315 = V_131 ;
}
V_4 -> V_307 = NULL ;
V_4 -> V_312 = false ;
F_119 ( V_2 , V_4 , & V_4 -> V_309 , V_335 ) ;
if ( ( V_2 -> V_71 -> V_72 . V_123 & V_337 ) && ! V_335 )
F_103 ( V_2 , V_4 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_122 ( struct V_1 * V_2 , bool V_335 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_338 * V_339 = F_114 ( V_2 -> V_71 ) ;
struct V_3 * V_4 ;
int V_108 ;
V_78 V_340 = 0 ;
if ( V_2 -> V_341 & V_342 )
return true ;
F_123 ( V_200 ) ;
for ( V_108 = 0 ; V_108 < V_343 ; V_108 ++ ) {
if ( ! F_107 ( V_2 , V_108 ) )
continue;
if ( F_124 ( V_200 , V_2 -> V_65 . V_4 [ V_108 ] . V_57 ) )
V_340 |= F_125 ( V_108 ) ;
}
if ( V_340 )
F_113 ( V_339 , L_2 , V_340 ) ;
for ( V_108 = 0 ; V_108 < V_343 ; V_108 ++ ) {
if ( ! F_107 ( V_2 , V_108 ) )
continue;
V_4 = & V_2 -> V_65 . V_4 [ V_108 ] ;
V_4 -> V_344 = false ;
F_121 ( V_2 , V_4 , V_335 ) ;
}
return ! V_340 ;
}
void F_126 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_127 ( V_2 -> V_71 , V_4 -> V_57 ) ;
V_2 -> V_65 . V_313 &= ~ ( 1 << V_4 -> V_57 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 , * V_280 , * V_345 ;
struct V_5 * V_6 , * V_346 ;
if ( F_128 ( & V_2 -> V_130 ) || F_36 ( & V_4 -> V_13 ) ||
V_4 -> V_269 >= V_270 )
return;
V_8 = F_38 ( & V_4 -> V_13 , struct V_7 , V_11 ) ;
V_345 = F_96 ( V_4 -> V_13 . V_56 , struct V_7 , V_11 ) ;
F_104 (ac, ac_tmp, &txq->axq_acq, list) {
V_346 = F_96 ( V_8 -> V_12 . V_56 , struct V_5 , V_11 ) ;
F_39 ( & V_8 -> V_11 ) ;
V_8 -> V_10 = false ;
while ( ! F_36 ( & V_8 -> V_12 ) ) {
V_6 = F_38 ( & V_8 -> V_12 , struct V_5 ,
V_11 ) ;
F_39 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
if ( V_6 -> V_9 )
continue;
F_95 ( V_2 , V_4 , V_6 ) ;
if ( ! F_8 ( & V_6 -> V_14 ) )
F_4 ( V_4 , V_6 ) ;
if ( V_6 == V_346 ||
V_4 -> V_269 >= V_270 )
break;
}
if ( ! F_36 ( & V_8 -> V_12 ) && ! V_8 -> V_10 ) {
V_8 -> V_10 = true ;
F_5 ( & V_8 -> V_11 , & V_4 -> V_13 ) ;
}
if ( V_8 == V_345 ||
V_4 -> V_269 >= V_270 )
return;
}
}
static void F_97 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_31 * V_347 , bool V_348 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_338 * V_339 = F_114 ( V_200 ) ;
struct V_29 * V_30 , * V_92 ;
bool V_349 = false ;
bool V_350 ;
if ( F_36 ( V_347 ) )
return;
V_350 = ! ! ( V_200 -> V_72 . V_123 & V_124 ) ;
V_30 = F_38 ( V_347 , struct V_29 , V_11 ) ;
V_92 = F_96 ( V_347 -> V_56 , struct V_29 , V_11 ) ;
F_129 ( V_339 , V_351 , L_3 ,
V_4 -> V_57 , V_4 -> V_311 ) ;
if ( V_350 && F_36 ( & V_4 -> V_317 [ V_4 -> V_314 ] ) ) {
F_130 ( V_347 , & V_4 -> V_317 [ V_4 -> V_314 ] ) ;
F_24 ( V_4 -> V_314 , V_316 ) ;
V_349 = true ;
} else {
F_130 ( V_347 , & V_4 -> V_309 ) ;
if ( V_4 -> V_307 ) {
F_131 ( V_200 , V_4 -> V_307 , V_30 -> V_260 ) ;
F_129 ( V_339 , V_352 , L_4 ,
V_4 -> V_57 , V_4 -> V_307 ,
F_132 ( V_30 -> V_260 ) , V_30 -> V_70 ) ;
} else if ( ! V_350 )
V_349 = true ;
V_4 -> V_307 = V_92 -> V_70 ;
}
if ( V_349 ) {
F_30 ( V_4 -> V_57 , V_349 ) ;
F_133 ( V_200 , V_4 -> V_57 , V_30 -> V_260 ) ;
F_129 ( V_339 , V_352 , L_5 ,
V_4 -> V_57 , F_132 ( V_30 -> V_260 ) , V_30 -> V_70 ) ;
}
if ( ! V_350 ) {
F_30 ( V_4 -> V_57 , V_353 ) ;
F_134 ( V_200 , V_4 -> V_57 ) ;
}
if ( ! V_348 ) {
V_4 -> V_311 ++ ;
if ( F_117 ( V_30 ) )
V_4 -> V_269 ++ ;
}
}
static void F_135 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_17 * V_18 , struct V_354 * V_355 )
{
struct V_16 * V_35 = F_10 ( V_18 ) ;
struct V_31 V_32 ;
struct V_29 * V_30 ;
if ( ! F_8 ( & V_6 -> V_14 ) || V_6 -> V_9 ||
! F_60 ( V_6 -> V_44 , V_6 -> V_128 , V_6 -> V_52 ) ||
V_355 -> V_4 -> V_269 >= V_270 ) {
F_30 ( V_355 -> V_4 -> V_57 , V_356 ) ;
F_56 ( & V_6 -> V_14 , V_18 ) ;
if ( ! V_355 -> V_23 || ! V_355 -> V_23 -> V_122 )
F_4 ( V_355 -> V_4 , V_6 ) ;
return;
}
V_30 = F_78 ( V_2 , V_355 -> V_4 , V_6 , V_18 , false ) ;
if ( ! V_30 )
return;
V_30 -> V_38 . V_179 = V_180 ;
F_16 ( & V_32 ) ;
F_79 ( & V_30 -> V_11 , & V_32 ) ;
F_25 ( V_2 , V_6 , V_30 -> V_38 . V_22 ) ;
F_30 ( V_355 -> V_4 -> V_57 , V_357 ) ;
V_30 -> V_93 = V_30 ;
F_93 ( V_2 , V_30 , V_355 -> V_4 , V_35 -> V_183 ) ;
F_97 ( V_2 , V_355 -> V_4 , & V_32 , false ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_17 * V_18 )
{
struct V_16 * V_35 = F_10 ( V_18 ) ;
struct V_31 V_32 ;
struct V_29 * V_30 ;
V_30 = V_35 -> V_30 ;
if ( ! V_30 )
V_30 = F_78 ( V_2 , V_4 , V_6 , V_18 , false ) ;
if ( ! V_30 )
return;
F_16 ( & V_32 ) ;
F_5 ( & V_30 -> V_11 , & V_32 ) ;
V_30 -> V_38 . V_179 = 0 ;
V_30 -> V_93 = V_30 ;
F_93 ( V_2 , V_30 , V_4 , V_35 -> V_183 ) ;
F_97 ( V_2 , V_4 , & V_32 , false ) ;
F_30 ( V_4 -> V_57 , V_358 ) ;
}
static void F_136 ( struct V_90 * V_91 , struct V_17 * V_18 ,
int V_183 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
struct V_89 * V_25 = V_20 -> V_109 . V_25 ;
struct V_359 * V_360 = V_20 -> V_109 . V_360 ;
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
const struct V_201 * V_202 ;
struct V_16 * V_35 = F_10 ( V_18 ) ;
struct V_88 * V_23 = NULL ;
enum V_361 V_264 ;
bool V_362 = false ;
if ( V_20 -> V_109 . V_24 &&
V_20 -> V_109 . V_24 -> V_363 . V_364 )
V_362 = true ;
V_202 = F_137 ( V_91 , V_20 ) ;
V_264 = F_138 ( V_18 ) ;
if ( V_25 )
V_23 = (struct V_88 * ) V_25 -> V_115 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( V_360 )
V_35 -> V_158 = V_360 -> V_365 ;
else if ( V_23 && F_139 ( V_55 -> V_60 ) && V_23 -> V_366 > 0 )
V_35 -> V_158 = V_23 -> V_366 ;
else
V_35 -> V_158 = V_159 ;
V_35 -> V_264 = V_264 ;
V_35 -> V_183 = V_183 ;
V_35 -> V_204 = V_202 -> V_232 ;
if ( V_362 )
V_35 -> V_204 |= V_202 -> V_233 ;
}
T_2 F_87 ( struct V_1 * V_2 , T_2 V_367 , V_78 V_202 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_368 * V_369 = V_200 -> V_369 ;
if ( ( V_200 -> V_72 . V_123 & V_370 ) &&
( V_369 -> V_371 & V_372 ) &&
( V_367 == 0x7 ) && ( V_202 < 0x90 ) )
return 0x3 ;
else
return V_367 ;
}
static struct V_29 * F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_17 * V_18 ,
bool V_373 )
{
struct V_338 * V_339 = F_114 ( V_2 -> V_71 ) ;
struct V_16 * V_35 = F_10 ( V_18 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
struct V_29 * V_30 ;
int V_374 ;
T_1 V_22 ;
V_30 = F_33 ( V_2 ) ;
if ( ! V_30 ) {
F_129 ( V_339 , V_352 , L_6 ) ;
goto error;
}
F_42 ( V_30 ) ;
if ( V_6 ) {
V_374 = F_140 ( V_55 -> V_375 ) & V_376 ;
V_22 = V_6 -> V_52 ;
V_55 -> V_375 = F_31 ( V_6 -> V_52 << V_28 ) ;
if ( V_374 )
V_55 -> V_375 |= F_31 ( V_374 ) ;
if ( ! F_141 ( V_55 -> V_60 ) )
F_24 ( V_6 -> V_52 , V_49 ) ;
V_30 -> V_38 . V_22 = V_22 ;
}
V_30 -> V_69 = V_18 ;
V_30 -> V_63 = F_142 ( V_2 -> V_62 , V_18 -> V_59 ,
V_18 -> V_198 , V_64 ) ;
if ( F_35 ( F_143 ( V_2 -> V_62 , V_30 -> V_63 ) ) ) {
V_30 -> V_69 = NULL ;
V_30 -> V_63 = 0 ;
F_113 ( F_114 ( V_2 -> V_71 ) ,
L_7 ) ;
F_40 ( V_2 , V_30 ) ;
goto error;
}
V_35 -> V_30 = V_30 ;
return V_30 ;
error:
if ( V_373 )
F_80 ( V_18 , & V_6 -> V_14 ) ;
F_144 ( V_18 ) ;
return NULL ;
}
static void F_145 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_354 * V_355 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_30 ;
T_2 V_27 ;
if ( ( V_2 -> V_71 -> V_72 . V_123 & V_337 ) && V_355 -> V_23 &&
F_146 ( V_55 -> V_60 ) ) {
V_27 = F_51 ( V_55 ) [ 0 ] &
V_116 ;
V_6 = F_52 ( V_355 -> V_23 , V_27 ) ;
F_7 ( V_6 -> V_8 -> V_4 != V_355 -> V_4 ) ;
}
if ( ( V_20 -> V_132 & V_377 ) && V_6 ) {
F_135 ( V_2 , V_6 , V_18 , V_355 ) ;
} else {
V_30 = F_78 ( V_2 , V_355 -> V_4 , V_6 , V_18 , false ) ;
if ( ! V_30 )
return;
V_30 -> V_38 . V_234 = V_355 -> V_378 ;
if ( V_355 -> V_378 )
V_30 -> V_38 . V_379 = V_380 ;
F_20 ( V_2 , V_355 -> V_4 , V_6 , V_18 ) ;
}
}
int F_147 ( struct V_90 * V_91 , struct V_17 * V_18 ,
struct V_354 * V_355 )
{
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
struct V_19 * V_197 = F_11 ( V_18 ) ;
struct V_89 * V_25 = V_197 -> V_109 . V_25 ;
struct V_381 * V_24 = V_197 -> V_109 . V_24 ;
struct V_1 * V_2 = V_91 -> V_382 ;
struct V_3 * V_4 = V_355 -> V_4 ;
int V_383 , V_384 ;
int V_135 = V_18 -> V_198 + V_385 ;
int V_386 ;
if ( V_25 )
V_355 -> V_23 = (struct V_88 * ) V_25 -> V_115 ;
if ( V_197 -> V_109 . V_360 )
V_135 += V_197 -> V_109 . V_360 -> V_387 ;
if ( V_197 -> V_132 & V_388 ) {
if ( V_197 -> V_132 & V_389 )
V_2 -> V_65 . V_390 += 0x10 ;
V_55 -> V_375 &= F_31 ( V_376 ) ;
V_55 -> V_375 |= F_31 ( V_2 -> V_65 . V_390 ) ;
}
V_383 = F_148 ( V_55 -> V_60 ) ;
V_384 = V_383 & 3 ;
if ( V_384 && V_18 -> V_198 > V_383 ) {
if ( F_149 ( V_18 ) < V_384 )
return - V_391 ;
F_150 ( V_18 , V_384 ) ;
memmove ( V_18 -> V_59 , V_18 -> V_59 + V_384 , V_383 ) ;
V_55 = (struct V_54 * ) V_18 -> V_59 ;
}
if ( ( V_24 && V_24 -> type != V_392 &&
V_24 -> type != V_393 ) ||
! F_139 ( V_55 -> V_60 ) )
V_197 -> V_132 |= V_256 ;
F_136 ( V_91 , V_18 , V_135 ) ;
V_386 = F_151 ( V_18 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_65 . V_394 [ V_386 ] &&
++ V_4 -> V_395 > V_396 && ! V_4 -> V_344 ) {
F_152 ( V_2 -> V_91 , V_386 ) ;
V_4 -> V_344 = true ;
}
F_145 ( V_2 , V_18 , V_355 ) ;
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_17 * V_18 ,
int V_397 , struct V_3 * V_4 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
struct V_338 * V_339 = F_114 ( V_2 -> V_71 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
int V_386 , V_383 , V_384 ;
F_129 ( V_339 , V_352 , L_8 , V_18 ) ;
if ( ! ( V_397 & V_51 ) )
V_20 -> V_132 |= V_398 ;
V_383 = F_148 ( V_55 -> V_60 ) ;
V_384 = V_383 & 3 ;
if ( V_384 && V_18 -> V_198 > V_383 + V_384 ) {
memmove ( V_18 -> V_59 + V_384 , V_18 -> V_59 , V_383 ) ;
F_153 ( V_18 , V_384 ) ;
}
if ( ( V_2 -> V_399 & V_400 ) && ! V_4 -> V_311 ) {
V_2 -> V_399 &= ~ V_400 ;
F_129 ( V_339 , V_401 ,
L_9 ,
V_2 -> V_399 & ( V_402 |
V_403 |
V_404 |
V_400 ) ) ;
}
V_386 = F_151 ( V_18 ) ;
if ( V_4 == V_2 -> V_65 . V_394 [ V_386 ] ) {
if ( F_7 ( -- V_4 -> V_395 < 0 ) )
V_4 -> V_395 = 0 ;
if ( V_4 -> V_344 && V_4 -> V_395 < V_396 ) {
F_154 ( V_2 -> V_91 , V_386 ) ;
V_4 -> V_344 = false ;
}
}
F_56 ( & V_4 -> V_308 , V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , struct V_31 * V_86 ,
struct V_33 * V_34 , int V_74 )
{
struct V_17 * V_18 = V_30 -> V_69 ;
struct V_19 * V_20 = F_11 ( V_18 ) ;
unsigned long V_132 ;
int V_397 = 0 ;
if ( ! V_74 )
V_397 |= V_51 ;
if ( V_34 -> V_106 & V_125 )
V_20 -> V_132 |= V_405 ;
F_155 ( V_2 -> V_62 , V_30 -> V_63 , V_18 -> V_198 , V_64 ) ;
V_30 -> V_63 = 0 ;
if ( V_30 -> V_38 . V_234 ) {
if ( F_156 ( V_380 ,
V_30 -> V_38 . V_379 +
F_157 ( V_406 ) ) )
F_144 ( V_18 ) ;
else
F_158 ( & V_2 -> V_407 ) ;
} else {
F_159 ( V_2 , V_30 , V_34 , V_4 , V_397 ) ;
F_28 ( V_2 , V_18 , V_397 , V_4 ) ;
}
V_30 -> V_69 = NULL ;
F_160 ( & V_2 -> V_65 . V_66 , V_132 ) ;
F_130 ( V_86 , & V_2 -> V_65 . V_67 ) ;
F_161 ( & V_2 -> V_65 . V_66 , V_132 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_33 * V_34 , int V_75 , int V_76 ,
int V_74 )
{
struct V_17 * V_18 = V_30 -> V_69 ;
struct V_54 * V_55 = (struct V_54 * ) V_18 -> V_59 ;
struct V_19 * V_20 = F_11 ( V_18 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
struct V_199 * V_200 = V_2 -> V_71 ;
T_2 V_108 , V_408 ;
if ( V_74 )
V_20 -> V_177 . V_409 = V_34 -> V_410 ;
V_408 = V_34 -> V_111 ;
F_7 ( V_408 >= V_91 -> V_411 ) ;
if ( V_20 -> V_132 & V_377 ) {
V_20 -> V_132 |= V_412 ;
F_110 ( V_76 > V_75 ) ;
}
V_20 -> V_177 . V_413 = V_75 ;
V_20 -> V_177 . V_414 = V_75 - V_76 ;
if ( ( V_34 -> V_106 & V_125 ) == 0 &&
( V_20 -> V_132 & V_252 ) == 0 ) {
if ( F_35 ( V_34 -> V_117 & ( V_415 |
V_416 ) ) &&
F_139 ( V_55 -> V_60 ) &&
V_200 -> V_417 >= V_2 -> V_71 -> V_330 . V_418 )
V_20 -> V_177 . V_104 [ V_408 ] . V_53 =
V_91 -> V_419 ;
}
for ( V_108 = V_408 + 1 ; V_108 < V_91 -> V_411 ; V_108 ++ ) {
V_20 -> V_177 . V_104 [ V_108 ] . V_53 = 0 ;
V_20 -> V_177 . V_104 [ V_108 ] . V_131 = - 1 ;
}
V_20 -> V_177 . V_104 [ V_408 ] . V_53 = V_34 -> V_110 + 1 ;
}
static void F_162 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_33 * V_34 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
int V_74 ;
V_4 -> V_311 -- ;
V_74 = ! ( V_34 -> V_106 & V_420 ) ;
V_4 -> V_312 = false ;
if ( F_117 ( V_30 ) )
V_4 -> V_269 -- ;
if ( ! F_118 ( V_30 ) ) {
F_55 ( V_2 , V_30 , V_34 , 1 , V_74 ? 0 : 1 , V_74 ) ;
F_19 ( V_2 , V_30 , V_4 , V_32 , V_34 , V_74 ) ;
} else
F_46 ( V_2 , V_4 , V_30 , V_32 , V_34 , V_74 , true ) ;
if ( V_2 -> V_71 -> V_72 . V_123 & V_337 )
F_9 ( V_2 , V_4 ) ;
}
static void F_163 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_338 * V_339 = F_114 ( V_200 ) ;
struct V_29 * V_30 , * V_336 , * V_421 = NULL ;
struct V_31 V_32 ;
struct V_422 * V_423 ;
struct V_33 V_34 ;
int V_177 ;
F_129 ( V_339 , V_351 , L_10 ,
V_4 -> V_57 , F_164 ( V_2 -> V_71 , V_4 -> V_57 ) ,
V_4 -> V_307 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_128 ( & V_2 -> V_130 ) )
break;
if ( F_36 ( & V_4 -> V_309 ) ) {
V_4 -> V_307 = NULL ;
if ( V_2 -> V_71 -> V_72 . V_123 & V_337 )
F_9 ( V_2 , V_4 ) ;
break;
}
V_30 = F_38 ( & V_4 -> V_309 , struct V_29 , V_11 ) ;
V_421 = NULL ;
if ( V_30 -> V_114 ) {
V_421 = V_30 ;
if ( F_165 ( & V_421 -> V_11 , & V_4 -> V_309 ) )
break;
V_30 = F_96 ( V_421 -> V_11 . V_424 , struct V_29 ,
V_11 ) ;
}
V_336 = V_30 -> V_93 ;
V_423 = V_336 -> V_70 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_177 = F_166 ( V_200 , V_423 , & V_34 ) ;
if ( V_177 == - V_425 )
break;
F_30 ( V_4 -> V_57 , V_426 ) ;
V_336 -> V_114 = true ;
F_16 ( & V_32 ) ;
if ( ! F_167 ( & V_336 -> V_11 ) )
F_120 ( & V_32 ,
& V_4 -> V_309 , V_336 -> V_11 . V_56 ) ;
if ( V_421 ) {
F_39 ( & V_421 -> V_11 ) ;
F_40 ( V_2 , V_421 ) ;
}
F_162 ( V_2 , V_4 , & V_34 , V_30 , & V_32 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
static void F_168 ( struct V_427 * V_428 )
{
struct V_1 * V_2 = F_169 ( V_428 , struct V_1 ,
V_429 . V_428 ) ;
struct V_3 * V_4 ;
int V_108 ;
bool V_101 = false ;
#ifdef F_170
V_2 -> V_430 ++ ;
#endif
for ( V_108 = 0 ; V_108 < V_343 ; V_108 ++ )
if ( F_107 ( V_2 , V_108 ) ) {
V_4 = & V_2 -> V_65 . V_4 [ V_108 ] ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_311 ) {
if ( V_4 -> V_312 ) {
V_101 = true ;
F_2 ( V_2 , V_4 ) ;
break;
} else {
V_4 -> V_312 = true ;
}
}
F_3 ( V_2 , V_4 ) ;
}
if ( V_101 ) {
F_129 ( F_114 ( V_2 -> V_71 ) , V_431 ,
L_11 ) ;
F_61 ( V_2 , V_432 ) ;
F_62 ( V_2 -> V_91 , & V_2 -> V_130 ) ;
}
F_171 ( V_2 -> V_91 , & V_2 -> V_429 ,
F_157 ( V_433 ) ) ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = V_2 -> V_71 ;
V_78 V_434 = ( ( 1 << V_343 ) - 1 ) & V_200 -> V_435 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_343 ; V_108 ++ ) {
if ( F_107 ( V_2 , V_108 ) && ( V_434 & ( 1 << V_108 ) ) )
F_163 ( V_2 , & V_2 -> V_65 . V_4 [ V_108 ] ) ;
}
}
void F_173 ( struct V_1 * V_2 )
{
struct V_33 V_34 ;
struct V_338 * V_339 = F_114 ( V_2 -> V_71 ) ;
struct V_199 * V_200 = V_2 -> V_71 ;
struct V_3 * V_4 ;
struct V_29 * V_30 , * V_336 ;
struct V_31 V_32 ;
int V_177 ;
for (; ; ) {
if ( F_128 ( & V_2 -> V_130 ) )
break;
V_177 = F_166 ( V_200 , NULL , ( void * ) & V_34 ) ;
if ( V_177 == - V_425 )
break;
if ( V_177 == - V_325 ) {
F_129 ( V_339 , V_352 , L_12 ) ;
break;
}
if ( V_34 . V_436 == V_2 -> V_320 . V_321 ) {
V_2 -> V_320 . V_437 = true ;
V_2 -> V_320 . V_438 = ! ( V_34 . V_106 & V_420 ) ;
continue;
}
V_4 = & V_2 -> V_65 . V_4 [ V_34 . V_436 ] ;
F_1 ( V_2 , V_4 ) ;
if ( F_36 ( & V_4 -> V_317 [ V_4 -> V_315 ] ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_30 = F_38 ( & V_4 -> V_317 [ V_4 -> V_315 ] ,
struct V_29 , V_11 ) ;
V_336 = V_30 -> V_93 ;
F_16 ( & V_32 ) ;
F_120 ( & V_32 , & V_4 -> V_317 [ V_4 -> V_315 ] ,
& V_336 -> V_11 ) ;
if ( F_36 ( & V_4 -> V_317 [ V_4 -> V_315 ] ) ) {
F_24 ( V_4 -> V_315 , V_316 ) ;
if ( ! F_36 ( & V_4 -> V_309 ) ) {
struct V_31 V_86 ;
F_16 ( & V_86 ) ;
V_4 -> V_307 = NULL ;
F_130 ( & V_4 -> V_309 , & V_86 ) ;
F_97 ( V_2 , V_4 , & V_86 , true ) ;
}
}
F_162 ( V_2 , V_4 , & V_34 , V_30 , & V_32 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_174 ( struct V_1 * V_2 , int V_439 )
{
struct V_440 * V_441 = & V_2 -> V_442 ;
T_2 V_443 = V_2 -> V_71 -> V_72 . V_443 ;
V_441 -> V_444 = V_439 * V_443 ;
V_441 -> V_445 = F_175 ( V_2 -> V_62 , V_441 -> V_444 ,
& V_441 -> V_446 , V_447 ) ;
if ( ! V_441 -> V_445 )
return - V_391 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 )
{
int V_448 ;
V_448 = F_174 ( V_2 , V_449 ) ;
if ( ! V_448 )
F_177 ( V_2 -> V_71 , V_2 -> V_442 . V_445 ,
V_2 -> V_442 . V_446 ,
V_449 ) ;
return V_448 ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_440 * V_441 = & V_2 -> V_442 ;
F_179 ( V_2 -> V_62 , V_441 -> V_444 , V_441 -> V_445 ,
V_441 -> V_446 ) ;
}
int F_180 ( struct V_1 * V_2 , int V_450 )
{
struct V_338 * V_339 = F_114 ( V_2 -> V_71 ) ;
int error = 0 ;
F_108 ( & V_2 -> V_65 . V_66 ) ;
error = F_181 ( V_2 , & V_2 -> V_65 . V_451 , & V_2 -> V_65 . V_67 ,
L_13 , V_450 , 1 , 1 ) ;
if ( error != 0 ) {
F_113 ( V_339 ,
L_14 , error ) ;
goto V_448;
}
error = F_181 ( V_2 , & V_2 -> V_320 . V_452 , & V_2 -> V_320 . V_453 ,
L_15 , V_454 , 1 , 1 ) ;
if ( error != 0 ) {
F_113 ( V_339 ,
L_16 , error ) ;
goto V_448;
}
F_182 ( & V_2 -> V_429 , F_168 ) ;
if ( V_2 -> V_71 -> V_72 . V_123 & V_124 ) {
error = F_176 ( V_2 ) ;
if ( error )
goto V_448;
}
V_448:
if ( error != 0 )
F_183 ( V_2 ) ;
return error ;
}
void F_183 ( struct V_1 * V_2 )
{
if ( V_2 -> V_320 . V_452 . V_444 != 0 )
F_184 ( V_2 , & V_2 -> V_320 . V_452 , & V_2 -> V_320 . V_453 ) ;
if ( V_2 -> V_65 . V_451 . V_444 != 0 )
F_184 ( V_2 , & V_2 -> V_65 . V_451 , & V_2 -> V_65 . V_67 ) ;
if ( V_2 -> V_71 -> V_72 . V_123 & V_124 )
F_178 ( V_2 ) ;
}
void F_185 ( struct V_1 * V_2 , struct V_88 * V_23 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_27 , V_455 ;
for ( V_27 = 0 , V_6 = & V_23 -> V_6 [ V_27 ] ;
V_27 < V_276 ;
V_27 ++ , V_6 ++ ) {
V_6 -> V_23 = V_23 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_44 = V_6 -> V_52 = 0 ;
V_6 -> V_128 = V_456 ;
V_6 -> V_39 = V_6 -> V_40 = 0 ;
V_6 -> V_10 = false ;
V_6 -> V_9 = false ;
V_6 -> V_41 &= ~ V_43 ;
F_53 ( & V_6 -> V_14 ) ;
V_455 = F_186 ( V_27 ) ;
V_6 -> V_8 = & V_23 -> V_8 [ V_455 ] ;
V_6 -> V_41 &= ~ V_42 ;
V_6 -> V_41 &= ~ V_274 ;
}
for ( V_455 = 0 , V_8 = & V_23 -> V_8 [ V_455 ] ;
V_455 < V_457 ; V_455 ++ , V_8 ++ ) {
V_8 -> V_10 = false ;
V_8 -> V_4 = V_2 -> V_65 . V_394 [ V_455 ] ;
F_16 ( & V_8 -> V_12 ) ;
}
}
void F_187 ( struct V_1 * V_2 , struct V_88 * V_23 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_27 ;
for ( V_27 = 0 , V_6 = & V_23 -> V_6 [ V_27 ] ;
V_27 < V_276 ; V_27 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_10 ) {
F_39 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
}
if ( V_8 -> V_10 ) {
F_39 ( & V_8 -> V_11 ) ;
V_6 -> V_8 -> V_10 = false ;
}
F_27 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_41 &= ~ V_42 ;
V_6 -> V_41 &= ~ V_43 ;
F_2 ( V_2 , V_4 ) ;
}
}
