void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
__acquires( &txq->axq_lock
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_6 -> V_11 -> V_12 -> V_13 ;
struct V_14 * V_15 = V_10 -> V_16 ;
if ( ! V_15 )
return;
V_8 = & V_15 -> V_17 [ F_5 ( V_6 -> V_18 ) ] ;
if ( F_6 ( & V_6 -> V_8 ) )
F_7 ( & V_6 -> V_8 , V_8 ) ;
}
static struct V_19 * F_8 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_9 ( V_21 ) ;
F_10 ( sizeof( struct V_19 ) >
sizeof( V_23 -> V_24 ) ) ;
return (struct V_19 * ) & V_23 -> V_24 [ 0 ] ;
}
static void F_11 ( struct V_5 * V_6 , T_1 V_25 )
{
if ( ! V_6 -> V_11 -> V_26 )
return;
F_12 ( V_6 -> V_11 -> V_12 , V_6 -> V_11 -> V_26 -> V_27 , V_6 -> V_18 ,
V_25 << V_28 ) ;
}
static void F_13 ( struct V_29 * V_12 , struct V_30 * V_26 ,
struct V_31 * V_32 )
{
F_14 ( V_12 , V_26 , V_32 -> V_33 , V_32 -> V_34 ,
F_15 ( V_32 -> V_34 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_22 * V_35 = F_9 ( V_21 ) ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
int V_37 = V_36 -> V_4 ;
if ( V_37 < 0 )
return;
V_4 = V_2 -> V_38 . V_39 [ V_37 ] ;
if ( F_17 ( -- V_4 -> V_40 < 0 ) )
V_4 -> V_40 = 0 ;
if ( V_4 -> V_41 &&
V_4 -> V_40 < V_2 -> V_38 . V_42 [ V_37 ] ) {
if ( F_18 () )
F_19 ( V_2 -> V_43 , V_35 -> V_44 ) ;
else
F_19 ( V_2 -> V_43 , V_37 ) ;
V_4 -> V_41 = false ;
}
}
static struct V_5 *
F_20 ( struct V_1 * V_2 , struct V_45 * V_11 , struct V_20 * V_21 )
{
T_2 V_18 = V_21 -> V_46 & V_47 ;
return F_21 ( V_11 , V_18 ) ;
}
static bool F_22 ( struct V_5 * V_6 )
{
return ! F_23 ( & V_6 -> V_48 ) || ! F_23 ( & V_6 -> V_49 ) ;
}
static struct V_20 * F_24 ( struct V_5 * V_6 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( & V_6 -> V_49 ) ;
if ( ! V_21 )
V_21 = F_25 ( & V_6 -> V_48 ) ;
return V_21 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_22 * V_23 ;
struct V_20 * V_21 , * V_50 ;
struct V_31 * V_32 ;
struct V_19 * V_36 ;
F_27 (&tid->buf_q, skb, tskb) {
V_36 = F_8 ( V_21 ) ;
V_32 = V_36 -> V_32 ;
V_23 = F_9 ( V_21 ) ;
V_23 -> V_51 &= ~ V_52 ;
if ( V_32 )
continue;
V_32 = F_28 ( V_2 , V_4 , V_6 , V_21 ) ;
if ( ! V_32 ) {
F_29 ( V_21 , & V_6 -> V_48 ) ;
F_16 ( V_2 , V_4 , V_21 ) ;
F_30 ( V_2 -> V_43 , V_21 ) ;
continue;
}
}
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_20 * V_21 ;
struct V_31 * V_32 ;
struct V_7 V_53 ;
struct V_54 V_55 ;
struct V_19 * V_36 ;
bool V_56 = false ;
F_32 ( & V_53 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
while ( ( V_21 = F_25 ( & V_6 -> V_49 ) ) ) {
V_36 = F_8 ( V_21 ) ;
V_32 = V_36 -> V_32 ;
if ( ! V_32 ) {
F_16 ( V_2 , V_4 , V_21 ) ;
F_30 ( V_2 -> V_43 , V_21 ) ;
continue;
}
if ( V_36 -> V_57 ) {
F_33 ( V_2 , V_6 , V_32 -> V_58 . V_25 ) ;
V_56 = true ;
}
F_7 ( & V_32 -> V_8 , & V_53 ) ;
F_34 ( V_2 , V_32 , V_4 , & V_53 , & V_55 , 0 ) ;
}
if ( V_56 ) {
F_2 ( V_2 , V_4 ) ;
F_11 ( V_6 , V_6 -> V_59 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_25 )
{
int V_60 , V_61 ;
V_60 = F_35 ( V_6 -> V_59 , V_25 ) ;
V_61 = ( V_6 -> V_62 + V_60 ) & ( V_63 - 1 ) ;
F_36 ( V_61 , V_6 -> V_64 ) ;
while ( V_6 -> V_62 != V_6 -> V_65 && ! F_37 ( V_6 -> V_62 , V_6 -> V_64 ) ) {
F_38 ( V_6 -> V_59 , V_66 ) ;
F_38 ( V_6 -> V_62 , V_63 ) ;
if ( V_6 -> V_67 >= 0 )
V_6 -> V_67 -- ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_19 * V_36 = F_8 ( V_32 -> V_33 ) ;
T_1 V_25 = V_32 -> V_58 . V_25 ;
int V_60 , V_61 ;
V_60 = F_35 ( V_6 -> V_59 , V_25 ) ;
V_61 = ( V_6 -> V_62 + V_60 ) & ( V_63 - 1 ) ;
F_40 ( V_61 , V_6 -> V_64 ) ;
V_36 -> V_57 = 1 ;
if ( V_60 >= ( ( V_6 -> V_65 - V_6 -> V_62 ) &
( V_63 - 1 ) ) ) {
V_6 -> V_65 = V_61 ;
F_38 ( V_6 -> V_65 , V_63 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_20 * V_21 ;
struct V_31 * V_32 ;
struct V_7 V_53 ;
struct V_54 V_55 ;
struct V_19 * V_36 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
F_32 ( & V_53 ) ;
while ( ( V_21 = F_24 ( V_6 ) ) ) {
V_36 = F_8 ( V_21 ) ;
V_32 = V_36 -> V_32 ;
if ( ! V_32 ) {
F_42 ( V_2 , V_21 , V_68 , V_4 ) ;
continue;
}
F_7 ( & V_32 -> V_8 , & V_53 ) ;
F_34 ( V_2 , V_32 , V_4 , & V_53 , & V_55 , 0 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_20 * V_21 , int V_69 )
{
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_31 * V_32 = V_36 -> V_32 ;
struct V_70 * V_71 ;
int V_72 = V_36 -> V_73 ;
F_44 ( V_4 -> V_74 , V_75 ) ;
V_36 -> V_73 += V_69 ;
if ( V_72 > 0 )
return;
V_71 = (struct V_70 * ) V_21 -> V_76 ;
V_71 -> V_77 |= F_45 ( V_78 ) ;
F_46 ( V_2 -> V_79 , V_32 -> V_80 ,
sizeof( * V_71 ) , V_81 ) ;
}
static struct V_31 * F_47 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = NULL ;
F_48 ( & V_2 -> V_38 . V_82 ) ;
if ( F_49 ( F_6 ( & V_2 -> V_38 . V_83 ) ) ) {
F_50 ( & V_2 -> V_38 . V_82 ) ;
return NULL ;
}
V_32 = F_51 ( & V_2 -> V_38 . V_83 , struct V_31 , V_8 ) ;
F_52 ( & V_32 -> V_8 ) ;
F_50 ( & V_2 -> V_38 . V_82 ) ;
return V_32 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
F_48 ( & V_2 -> V_38 . V_82 ) ;
F_7 ( & V_32 -> V_8 , & V_2 -> V_38 . V_83 ) ;
F_50 ( & V_2 -> V_38 . V_82 ) ;
}
static struct V_31 * F_54 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_31 * V_84 ;
V_84 = F_47 ( V_2 ) ;
if ( F_17 ( ! V_84 ) )
return NULL ;
F_55 ( V_84 ) ;
V_84 -> V_33 = V_32 -> V_33 ;
V_84 -> V_80 = V_32 -> V_80 ;
memcpy ( V_84 -> V_85 , V_32 -> V_85 , V_2 -> V_86 -> V_87 . V_88 ) ;
V_84 -> V_58 = V_32 -> V_58 ;
V_84 -> V_58 . V_89 = false ;
return V_84 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_54 * V_55 , int V_90 ,
int * V_91 , int * V_92 )
{
struct V_19 * V_36 ;
T_1 V_93 = 0 ;
V_94 V_95 [ V_96 >> 5 ] ;
int V_97 ;
int V_98 = 0 ;
* V_92 = 0 ;
* V_91 = 0 ;
V_98 = F_57 ( V_32 ) ;
if ( V_98 ) {
V_93 = V_55 -> V_99 ;
memcpy ( V_95 , & V_55 -> V_100 , V_96 >> 3 ) ;
}
while ( V_32 ) {
V_36 = F_8 ( V_32 -> V_33 ) ;
V_97 = F_35 ( V_93 , V_32 -> V_58 . V_25 ) ;
( * V_91 ) ++ ;
if ( ! V_90 || ( V_98 && ! F_58 ( V_95 , V_97 ) ) )
( * V_92 ) ++ ;
V_32 = V_32 -> V_101 ;
}
}
static void F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_31 * V_32 , struct V_7 * V_102 ,
struct V_54 * V_55 , int V_90 )
{
struct V_45 * V_11 = NULL ;
struct V_20 * V_21 ;
struct V_30 * V_26 ;
struct V_103 * V_43 = V_2 -> V_43 ;
struct V_70 * V_71 ;
struct V_22 * V_23 ;
struct V_5 * V_6 = NULL ;
struct V_31 * V_101 , * V_104 = V_32 -> V_105 ;
struct V_7 V_53 ;
struct V_106 V_107 ;
T_1 V_93 = 0 , V_108 = 0 , V_109 = 0 , V_110 ;
V_94 V_95 [ V_96 >> 5 ] ;
int V_98 , V_111 , V_112 , V_56 = 0 , V_113 = 0 , V_92 = 0 ;
bool V_114 = true , V_115 ;
struct V_116 V_34 [ 4 ] ;
struct V_19 * V_36 ;
int V_91 ;
bool V_117 = ! ! ( V_55 -> V_118 & V_119 ) ;
int V_120 , V_73 ;
int V_67 = - 1 ;
V_21 = V_32 -> V_33 ;
V_71 = (struct V_70 * ) V_21 -> V_76 ;
V_23 = F_9 ( V_21 ) ;
memcpy ( V_34 , V_32 -> V_34 , sizeof( V_34 ) ) ;
V_73 = V_55 -> V_121 + 1 ;
for ( V_120 = 0 ; V_120 < V_55 -> V_122 ; V_120 ++ )
V_73 += V_34 [ V_120 ] . V_69 ;
F_60 () ;
V_26 = F_61 ( V_43 , V_71 -> V_123 , V_71 -> V_124 ) ;
if ( ! V_26 ) {
F_62 () ;
F_32 ( & V_53 ) ;
while ( V_32 ) {
V_101 = V_32 -> V_101 ;
if ( ! V_32 -> V_58 . V_89 || V_101 != NULL )
F_63 ( & V_32 -> V_8 , & V_53 ) ;
F_34 ( V_2 , V_32 , V_4 , & V_53 , V_55 , 0 ) ;
V_32 = V_101 ;
}
return;
}
V_11 = (struct V_45 * ) V_26 -> V_13 ;
V_6 = F_20 ( V_2 , V_11 , V_21 ) ;
V_110 = V_6 -> V_59 ;
V_115 = V_55 -> V_125 & V_126 ;
if ( V_115 && V_6 -> V_18 != V_55 -> V_6 )
V_90 = false ;
V_98 = F_57 ( V_32 ) ;
memset ( V_95 , 0 , V_96 >> 3 ) ;
if ( V_98 && V_90 ) {
if ( V_55 -> V_125 & V_126 ) {
V_93 = V_55 -> V_99 ;
memcpy ( V_95 , & V_55 -> V_100 , V_96 >> 3 ) ;
} else {
if ( V_2 -> V_86 -> V_127 == V_128 )
V_113 = 1 ;
}
}
F_64 ( & V_107 ) ;
F_56 ( V_2 , V_32 , V_55 , V_90 , & V_91 , & V_92 ) ;
while ( V_32 ) {
T_1 V_25 = V_32 -> V_58 . V_25 ;
V_111 = V_112 = V_56 = 0 ;
V_101 = V_32 -> V_101 ;
V_21 = V_32 -> V_33 ;
V_23 = F_9 ( V_21 ) ;
V_36 = F_8 ( V_21 ) ;
if ( ! F_65 ( V_6 -> V_59 , V_6 -> V_129 , V_25 ) ||
! V_6 -> V_130 ) {
V_111 = 1 ;
} else if ( F_58 ( V_95 , F_35 ( V_93 , V_25 ) ) ) {
V_108 ++ ;
} else if ( ! V_98 && V_90 ) {
V_108 ++ ;
} else if ( V_117 ) {
V_112 = 1 ;
} else if ( V_36 -> V_73 < V_131 ) {
if ( V_90 || ! V_11 -> V_132 )
F_43 ( V_2 , V_4 , V_32 -> V_33 ,
V_73 ) ;
V_112 = 1 ;
} else {
V_111 = 1 ;
V_109 ++ ;
V_67 = F_66 ( int , V_67 ,
F_35 ( V_110 , V_25 ) ) ;
}
F_32 ( & V_53 ) ;
if ( V_101 != NULL || ! V_104 -> V_58 . V_89 )
F_63 ( & V_32 -> V_8 , & V_53 ) ;
if ( ! V_112 ) {
F_33 ( V_2 , V_6 , V_25 ) ;
if ( V_114 && ( V_108 == 1 || V_109 == 1 ) ) {
memcpy ( V_23 -> V_133 . V_34 , V_34 , sizeof( V_34 ) ) ;
F_67 ( V_2 , V_32 , V_55 , V_91 , V_92 , V_90 ) ;
V_114 = false ;
if ( V_32 == V_32 -> V_105 )
F_68 ( V_2 -> V_86 ,
V_32 -> V_33 ,
V_55 ) ;
}
F_34 ( V_2 , V_32 , V_4 , & V_53 , V_55 ,
! V_111 ) ;
} else {
if ( V_23 -> V_51 & V_134 ) {
V_23 -> V_51 &= ~ V_134 ;
F_69 ( V_26 ) ;
}
if ( V_32 -> V_101 == NULL && V_104 -> V_58 . V_89 ) {
struct V_31 * V_84 ;
V_84 = F_54 ( V_2 , V_104 ) ;
if ( ! V_84 ) {
F_33 ( V_2 , V_6 , V_25 ) ;
F_34 ( V_2 , V_32 , V_4 ,
& V_53 , V_55 , 0 ) ;
V_67 = F_66 ( int , V_67 ,
F_35 ( V_110 , V_25 ) ) ;
break;
}
V_36 -> V_32 = V_84 ;
}
F_70 ( & V_107 , V_21 ) ;
}
V_32 = V_101 ;
}
if ( ! F_23 ( & V_107 ) ) {
if ( V_11 -> V_132 )
F_71 ( V_26 , V_6 -> V_18 , true ) ;
F_72 ( & V_107 , & V_6 -> V_49 ) ;
if ( ! V_11 -> V_132 ) {
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_55 -> V_118 & ( V_135 | V_136 ) )
V_6 -> V_137 = true ;
}
}
if ( V_67 >= 0 ) {
T_1 V_138 = F_73 ( V_110 , V_67 ) ;
if ( F_65 ( V_6 -> V_59 , V_6 -> V_129 , V_138 ) )
V_6 -> V_67 = F_35 ( V_6 -> V_59 , V_138 ) ;
F_2 ( V_2 , V_4 ) ;
F_11 ( V_6 , F_73 ( V_110 , V_67 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_62 () ;
if ( V_113 )
F_74 ( V_2 , V_139 ) ;
}
static bool F_75 ( struct V_31 * V_32 )
{
struct V_22 * V_35 = F_9 ( V_32 -> V_33 ) ;
return F_76 ( V_32 ) && ! ( V_35 -> V_51 & V_140 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_54 * V_55 , struct V_31 * V_32 ,
struct V_7 * V_53 )
{
struct V_22 * V_35 ;
bool V_90 , V_117 ;
V_90 = ! ( V_55 -> V_118 & V_141 ) ;
V_117 = ! ! ( V_55 -> V_118 & V_119 ) ;
V_4 -> V_142 = false ;
V_4 -> V_143 -- ;
if ( F_75 ( V_32 ) )
V_4 -> V_144 -- ;
V_55 -> V_145 = F_78 ( V_2 -> V_86 , V_32 -> V_85 ,
V_55 -> V_122 ) ;
if ( ! F_76 ( V_32 ) ) {
if ( ! V_117 ) {
V_35 = F_9 ( V_32 -> V_33 ) ;
memcpy ( V_35 -> V_133 . V_34 , V_32 -> V_34 ,
sizeof( V_35 -> V_133 . V_34 ) ) ;
F_67 ( V_2 , V_32 , V_55 , 1 , V_90 ? 0 : 1 , V_90 ) ;
F_68 ( V_2 -> V_86 , V_32 -> V_33 , V_55 ) ;
}
F_34 ( V_2 , V_32 , V_4 , V_53 , V_55 , V_90 ) ;
} else
F_59 ( V_2 , V_4 , V_32 , V_53 , V_55 , V_90 ) ;
if ( ! V_117 )
F_79 ( V_2 , V_4 ) ;
}
static bool F_80 ( struct V_31 * V_32 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_116 * V_34 ;
int V_120 ;
V_21 = V_32 -> V_33 ;
V_23 = F_9 ( V_21 ) ;
V_34 = V_23 -> V_133 . V_34 ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
if ( ! V_34 [ V_120 ] . V_69 || V_34 [ V_120 ] . V_146 < 0 )
break;
if ( ! ( V_34 [ V_120 ] . V_51 & V_147 ) )
return true ;
}
return false ;
}
static V_94 F_81 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_5 * V_6 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_116 * V_34 ;
V_94 V_148 , V_149 ;
T_1 V_150 , V_151 , V_152 = 0 ;
int V_37 = V_6 -> V_4 -> V_153 ;
int V_120 ;
V_21 = V_32 -> V_33 ;
V_23 = F_9 ( V_21 ) ;
V_34 = V_32 -> V_34 ;
V_148 = V_154 ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
int V_155 ;
if ( ! V_34 [ V_120 ] . V_69 )
continue;
if ( ! ( V_34 [ V_120 ] . V_51 & V_147 ) ) {
V_152 = 1 ;
break;
}
if ( V_34 [ V_120 ] . V_51 & V_156 )
V_155 = V_157 ;
else
V_155 = V_158 ;
if ( V_34 [ V_120 ] . V_51 & V_159 )
V_155 ++ ;
V_149 = V_2 -> V_38 . V_160 [ V_37 ] [ V_155 ] [ V_34 [ V_120 ] . V_146 ] ;
V_148 = F_82 ( V_148 , V_149 ) ;
}
if ( V_23 -> V_51 & V_140 || V_152 )
return 0 ;
V_150 = F_82 ( V_148 , ( V_94 ) V_154 ) ;
V_151 = F_83 ( V_2 , V_148 ) ;
if ( V_151 )
V_150 = V_151 ;
if ( V_6 -> V_11 -> V_161 )
V_150 = F_82 ( V_150 , V_6 -> V_11 -> V_161 ) ;
return V_150 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_31 * V_32 , T_1 V_149 ,
bool V_162 )
{
#define F_85 60
V_94 V_163 , V_164 ;
T_1 V_165 ;
T_2 V_51 , V_166 ;
int V_167 , V_168 , V_169 , V_170 , V_171 ;
struct V_19 * V_36 = F_8 ( V_32 -> V_33 ) ;
V_170 = F_86 ( V_149 ) ;
if ( ( V_36 -> V_172 != V_173 ) &&
! ( V_2 -> V_86 -> V_87 . V_174 & V_175 ) )
V_170 += V_176 ;
if ( V_162 && ! F_87 ( V_2 -> V_86 ) &&
( V_2 -> V_86 -> V_177 & V_178 ) )
V_170 = F_88 ( V_170 , F_85 ) ;
if ( V_6 -> V_11 -> V_179 == 0 )
return V_170 ;
V_166 = V_32 -> V_34 [ 0 ] . V_146 ;
V_51 = V_32 -> V_34 [ 0 ] . V_51 ;
V_167 = ( V_51 & V_156 ) ? 1 : 0 ;
V_169 = ( V_51 & V_159 ) ? 1 : 0 ;
if ( V_169 )
V_164 = F_89 ( V_6 -> V_11 -> V_179 ) ;
else
V_164 = F_90 ( V_6 -> V_11 -> V_179 ) ;
if ( V_164 == 0 )
V_164 = 1 ;
V_168 = F_91 ( V_166 ) ;
V_163 = V_180 [ V_166 % 8 ] [ V_167 ] * V_168 ;
V_165 = ( V_164 * V_163 ) / V_181 ;
if ( V_149 < V_165 ) {
V_171 = ( V_165 - V_149 ) / V_182 ;
V_170 = F_88 ( V_171 , V_170 ) ;
}
return V_170 ;
}
static struct V_31 *
F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_106 * * V_37 )
{
struct V_22 * V_23 ;
struct V_19 * V_36 ;
struct V_20 * V_21 ;
struct V_31 * V_32 ;
T_1 V_25 ;
while ( 1 ) {
* V_37 = & V_6 -> V_49 ;
if ( F_23 ( * V_37 ) )
* V_37 = & V_6 -> V_48 ;
V_21 = F_93 ( * V_37 ) ;
if ( ! V_21 )
break;
V_36 = F_8 ( V_21 ) ;
V_32 = V_36 -> V_32 ;
if ( ! V_36 -> V_32 )
V_32 = F_28 ( V_2 , V_4 , V_6 , V_21 ) ;
else
V_32 -> V_58 . V_89 = false ;
if ( ! V_32 ) {
F_29 ( V_21 , * V_37 ) ;
F_16 ( V_2 , V_4 , V_21 ) ;
F_30 ( V_2 -> V_43 , V_21 ) ;
continue;
}
V_32 -> V_101 = NULL ;
V_32 -> V_105 = V_32 ;
V_23 = F_9 ( V_21 ) ;
V_23 -> V_51 &= ~ V_183 ;
if ( ! V_6 -> V_130 )
V_23 -> V_51 &= ~ V_52 ;
if ( ! ( V_23 -> V_51 & V_52 ) ) {
V_32 -> V_58 . V_184 = 0 ;
return V_32 ;
}
V_32 -> V_58 . V_184 = V_185 | V_186 ;
V_25 = V_32 -> V_58 . V_25 ;
if ( ! F_65 ( V_6 -> V_59 , V_6 -> V_129 , V_25 ) )
break;
if ( V_6 -> V_67 > F_35 ( V_6 -> V_59 , V_25 ) ) {
struct V_54 V_55 = {} ;
struct V_7 V_53 ;
F_32 ( & V_53 ) ;
F_94 ( & V_32 -> V_8 , & V_53 ) ;
F_29 ( V_21 , * V_37 ) ;
F_33 ( V_2 , V_6 , V_25 ) ;
F_34 ( V_2 , V_32 , V_4 , & V_53 , & V_55 , 0 ) ;
continue;
}
return V_32 ;
}
return NULL ;
}
static bool
F_95 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_102 ,
struct V_31 * V_187 , struct V_106 * V_188 ,
int * V_189 )
{
#define F_96 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_31 * V_32 = V_187 , * V_190 = NULL ;
int V_91 = 0 , V_170 ;
T_1 V_150 = 0 , V_191 = 0 , V_192 = 0 ,
V_193 , V_194 = V_6 -> V_129 / 2 ;
struct V_22 * V_23 ;
struct V_19 * V_36 ;
struct V_20 * V_21 ;
bool V_195 = false ;
V_32 = V_187 ;
V_150 = F_81 ( V_2 , V_32 , V_6 ) ;
do {
V_21 = V_32 -> V_33 ;
V_36 = F_8 ( V_21 ) ;
V_193 = V_182 + V_36 -> V_196 ;
if ( V_91 ) {
if ( V_150 < V_191 + V_192 + V_193 ||
F_80 ( V_32 ) || V_91 >= V_194 )
break;
V_23 = F_9 ( V_32 -> V_33 ) ;
if ( ( V_23 -> V_51 & V_140 ) ||
! ( V_23 -> V_51 & V_52 ) )
break;
}
V_191 += V_192 + V_193 ;
V_170 = F_84 ( V_2 , V_6 , V_187 , V_36 -> V_196 ,
! V_91 ) ;
V_192 = F_96 ( V_193 ) + ( V_170 << 2 ) ;
V_91 ++ ;
V_32 -> V_101 = NULL ;
if ( ! V_36 -> V_57 )
F_39 ( V_2 , V_6 , V_32 ) ;
V_32 -> V_58 . V_170 = V_170 ;
F_29 ( V_21 , V_188 ) ;
F_7 ( & V_32 -> V_8 , V_102 ) ;
if ( V_190 )
V_190 -> V_101 = V_32 ;
V_190 = V_32 ;
V_32 = F_92 ( V_2 , V_4 , V_6 , & V_188 ) ;
if ( ! V_32 ) {
V_195 = true ;
break;
}
} while ( F_22 ( V_6 ) );
V_32 = V_187 ;
V_32 -> V_105 = V_190 ;
if ( V_32 == V_190 ) {
V_191 = F_8 ( V_32 -> V_33 ) -> V_196 ;
V_32 -> V_58 . V_184 = V_185 ;
} else {
F_44 ( V_4 -> V_74 , V_197 ) ;
}
* V_189 = V_191 ;
return V_195 ;
#undef F_96
}
static V_94 F_97 ( struct V_1 * V_2 , T_2 V_166 , int V_198 ,
int V_167 , int V_169 , bool V_199 )
{
V_94 V_200 , V_163 , V_145 , V_164 ;
int V_168 ;
V_168 = F_91 ( V_166 ) ;
V_200 = ( V_198 << 3 ) + V_201 ;
V_163 = V_180 [ V_166 % 8 ] [ V_167 ] * V_168 ;
V_164 = ( V_200 + V_163 - 1 ) / V_163 ;
if ( ! V_169 )
V_145 = F_98 ( V_164 ) ;
else
V_145 = F_99 ( V_164 ) ;
V_145 += V_202 + V_203 + V_204 + V_205 + V_206 + F_100 ( V_168 ) ;
return V_145 ;
}
static int F_101 ( int V_207 , int V_208 , bool V_209 , bool V_210 )
{
int V_168 = F_91 ( V_208 ) ;
int V_211 , V_212 ;
int V_213 = 0 ;
V_207 -= V_202 + V_203 + V_204 + V_205 + V_206 + F_100 ( V_168 ) ;
V_211 = V_210 ? F_102 ( V_207 ) : F_103 ( V_207 ) ;
V_212 = V_211 * V_180 [ V_208 % 8 ] [ V_209 ] * V_168 ;
V_212 -= V_201 ;
V_213 = V_212 / 8 ;
if ( V_213 > 65532 )
V_213 = 65532 ;
return V_213 ;
}
void F_104 ( struct V_1 * V_2 , int V_214 , int V_215 )
{
T_1 * V_216 , * V_217 , * V_218 , * V_219 ;
int V_208 ;
if ( ! V_215 || V_215 > 4096 )
V_215 = 4096 ;
V_216 = V_2 -> V_38 . V_160 [ V_214 ] [ V_158 ] ;
V_217 = V_2 -> V_38 . V_160 [ V_214 ] [ V_220 ] ;
V_218 = V_2 -> V_38 . V_160 [ V_214 ] [ V_157 ] ;
V_219 = V_2 -> V_38 . V_160 [ V_214 ] [ V_221 ] ;
for ( V_208 = 0 ; V_208 < 32 ; V_208 ++ ) {
V_216 [ V_208 ] = F_101 ( V_215 , V_208 , false , false ) ;
V_217 [ V_208 ] = F_101 ( V_215 , V_208 , false , true ) ;
V_218 [ V_208 ] = F_101 ( V_215 , V_208 , true , false ) ;
V_219 [ V_208 ] = F_101 ( V_215 , V_208 , true , true ) ;
}
}
static T_2 F_105 ( struct V_1 * V_2 , struct V_31 * V_32 ,
T_2 V_222 , bool V_223 , bool V_224 )
{
T_2 V_225 ;
struct V_20 * V_21 ;
struct V_19 * V_36 ;
struct V_22 * V_35 ;
struct V_226 * V_227 = V_2 -> V_86 ;
if ( V_2 -> V_228 || ! V_227 -> V_229 )
return V_230 ;
V_21 = V_32 -> V_33 ;
V_36 = F_8 ( V_21 ) ;
V_35 = F_9 ( V_21 ) ;
if ( ! F_106 ( V_227 ) ) {
int V_231 = V_36 -> V_232 ;
if ( V_223 ) {
T_2 V_233 ;
struct V_234 * V_235 = & V_227 -> V_236 . V_237 ;
if ( V_238 >= V_239 ) {
bool V_240 ;
struct V_241 * V_242 ;
V_240 = V_35 -> V_243 == V_244 ;
V_242 = & V_235 -> V_245 [ V_240 ] ;
V_233 = V_242 -> V_246 ;
} else {
V_233 = 2 ;
}
V_231 += V_233 ;
}
if ( F_107 ( V_227 ) || F_108 ( V_227 ) ||
F_109 ( V_227 ) ) {
V_231 -= 2 * V_247 ;
} else if ( F_110 ( V_227 ) ) {
T_4 V_248 ;
V_248 = V_227 -> V_249 -> V_250 ( V_227 ,
V_251 ) ;
V_231 -= 2 * V_248 ;
}
if ( V_252 && V_224 )
V_231 -= 2 ;
V_231 = F_88 ( V_231 , 0 ) ;
V_225 = F_111 ( T_2 , V_227 -> V_232 [ V_222 ] , V_231 ) ;
if ( ! V_225 && ! F_110 ( V_227 ) )
V_225 = 1 ;
} else if ( ! V_32 -> V_58 . V_253 ) {
if ( V_222 < 8 && ( V_35 -> V_51 & V_254 ) )
V_225 = F_111 ( T_2 , V_227 -> V_255 [ V_222 ] ,
V_36 -> V_232 ) ;
else
V_225 = F_111 ( T_2 , V_227 -> V_232 [ V_222 ] ,
V_36 -> V_232 ) ;
} else {
V_225 = V_227 -> V_256 ;
}
return V_225 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_257 * V_35 , int V_258 , bool V_259 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_260 * V_261 = F_113 ( V_227 ) ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_116 * V_34 ;
const struct V_262 * V_263 ;
struct V_70 * V_71 ;
struct V_19 * V_36 = F_8 ( V_32 -> V_33 ) ;
V_94 V_264 = V_2 -> V_43 -> V_265 -> V_266 ;
int V_120 ;
T_2 V_166 = 0 ;
V_21 = V_32 -> V_33 ;
V_23 = F_9 ( V_21 ) ;
V_34 = V_32 -> V_34 ;
V_71 = (struct V_70 * ) V_21 -> V_76 ;
V_35 -> V_267 = ! F_114 ( V_71 -> V_77 ) ;
V_35 -> V_268 = V_36 -> V_268 ;
for ( V_120 = 0 ; V_120 < F_15 ( V_32 -> V_34 ) ; V_120 ++ ) {
bool V_223 , V_269 , V_270 , V_224 ;
int V_271 ;
if ( ! V_34 [ V_120 ] . V_69 || ( V_34 [ V_120 ] . V_146 < 0 ) )
continue;
V_166 = V_34 [ V_120 ] . V_146 ;
V_35 -> V_34 [ V_120 ] . V_272 = V_34 [ V_120 ] . V_69 ;
if ( F_76 ( V_32 ) && ! F_57 ( V_32 ) &&
( V_34 [ V_120 ] . V_51 & V_147 ) &&
F_49 ( V_264 != ( V_94 ) - 1 ) ) {
if ( ! V_264 || ( V_258 > V_264 ) )
V_259 = true ;
}
if ( V_259 || V_34 [ V_120 ] . V_51 & V_273 ) {
V_35 -> V_34 [ V_120 ] . V_274 |= V_275 ;
V_35 -> V_51 |= V_276 ;
} else if ( V_34 [ V_120 ] . V_51 & V_277 ) {
V_35 -> V_34 [ V_120 ] . V_274 |= V_275 ;
V_35 -> V_51 |= V_278 ;
}
if ( V_34 [ V_120 ] . V_51 & V_156 )
V_35 -> V_34 [ V_120 ] . V_274 |= V_279 ;
if ( V_34 [ V_120 ] . V_51 & V_159 )
V_35 -> V_34 [ V_120 ] . V_274 |= V_280 ;
V_269 = ! ! ( V_34 [ V_120 ] . V_51 & V_159 ) ;
V_223 = ! ! ( V_34 [ V_120 ] . V_51 & V_156 ) ;
V_270 = ! ! ( V_34 [ V_120 ] . V_51 & V_281 ) ;
if ( V_34 [ V_120 ] . V_51 & V_147 ) {
V_35 -> V_34 [ V_120 ] . V_282 = V_166 | 0x80 ;
V_35 -> V_34 [ V_120 ] . V_283 = F_115 ( V_2 ,
V_227 -> V_284 , V_35 -> V_34 [ V_120 ] . V_282 ) ;
V_35 -> V_34 [ V_120 ] . V_285 = F_97 ( V_2 , V_166 , V_258 ,
V_223 , V_269 , V_270 ) ;
if ( V_166 < 8 && ( V_23 -> V_51 & V_254 ) )
V_35 -> V_34 [ V_120 ] . V_274 |= V_286 ;
V_35 -> V_231 [ V_120 ] = F_105 ( V_2 , V_32 , V_166 ,
V_223 , false ) ;
continue;
}
V_263 = & V_261 -> V_287 [ V_23 -> V_243 ] . V_288 [ V_34 [ V_120 ] . V_146 ] ;
if ( ( V_23 -> V_243 == V_244 ) &&
! ( V_263 -> V_51 & V_289 ) )
V_271 = V_290 ;
else
V_271 = V_291 ;
V_35 -> V_34 [ V_120 ] . V_282 = V_263 -> V_292 ;
if ( V_263 -> V_293 ) {
if ( V_34 [ V_120 ] . V_51 & V_281 )
V_35 -> V_34 [ V_120 ] . V_282 |= V_263 -> V_293 ;
} else {
V_270 = false ;
}
if ( V_32 -> V_58 . V_253 )
V_35 -> V_34 [ V_120 ] . V_283 = V_227 -> V_284 ;
else
V_35 -> V_34 [ V_120 ] . V_283 = F_115 ( V_2 ,
V_227 -> V_284 , V_35 -> V_34 [ V_120 ] . V_282 ) ;
V_35 -> V_34 [ V_120 ] . V_285 = F_116 ( V_2 -> V_86 ,
V_271 , V_263 -> V_294 * 100 , V_258 , V_166 , V_270 ) ;
V_224 = F_117 ( V_35 -> V_34 [ V_120 ] . V_282 ) ;
V_35 -> V_231 [ V_120 ] = F_105 ( V_2 , V_32 , V_166 , false ,
V_224 ) ;
}
if ( F_57 ( V_32 ) && ( V_258 > V_2 -> V_86 -> V_87 . V_295 ) )
V_35 -> V_51 &= ~ V_276 ;
if ( V_35 -> V_51 & V_276 )
V_35 -> V_51 &= ~ V_278 ;
}
static enum V_296 F_118 ( struct V_20 * V_21 )
{
struct V_70 * V_71 ;
enum V_296 V_297 ;
T_5 V_298 ;
V_71 = (struct V_70 * ) V_21 -> V_76 ;
V_298 = V_71 -> V_77 ;
if ( F_119 ( V_298 ) )
V_297 = V_299 ;
else if ( F_120 ( V_298 ) )
V_297 = V_300 ;
else if ( F_121 ( V_298 ) )
V_297 = V_301 ;
else if ( F_114 ( V_298 ) )
V_297 = V_302 ;
else
V_297 = V_303 ;
return V_297 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_3 * V_4 , int V_258 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_31 * V_187 = NULL ;
struct V_257 V_35 ;
V_94 V_264 = V_2 -> V_43 -> V_265 -> V_266 ;
bool V_259 = false ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_304 = true ;
V_35 . V_305 = true ;
V_35 . V_306 = V_4 -> V_74 ;
while ( V_32 ) {
struct V_20 * V_21 = V_32 -> V_33 ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
bool V_307 = ! ! ( V_32 -> V_58 . V_184 & V_186 ) ;
V_35 . type = F_118 ( V_21 ) ;
if ( V_32 -> V_101 )
V_35 . V_308 = V_32 -> V_101 -> V_309 ;
else
V_35 . V_308 = ( V_2 -> V_228 ) ? V_32 -> V_309 : 0 ;
if ( ! V_187 ) {
V_187 = V_32 ;
if ( ! V_2 -> V_228 )
V_35 . V_51 = V_310 ;
if ( ( V_23 -> V_51 & V_183 ) ||
V_4 == V_2 -> V_38 . V_311 )
V_35 . V_51 |= V_312 ;
if ( V_23 -> V_51 & V_313 )
V_35 . V_51 |= V_314 ;
if ( V_23 -> V_51 & V_315 )
V_35 . V_51 |= V_316 ;
if ( V_32 -> V_58 . V_253 )
V_35 . V_51 |= ( V_94 ) V_32 -> V_58 . V_253 <<
V_317 ;
if ( V_307 && ( V_32 == V_187 ) &&
F_49 ( V_264 != ( V_94 ) - 1 ) ) {
if ( ! V_264 || ( V_258 > V_264 ) )
V_259 = true ;
}
if ( ! V_307 )
V_258 = V_36 -> V_196 ;
F_112 ( V_2 , V_32 , & V_35 , V_258 , V_259 ) ;
}
V_35 . V_318 [ 0 ] = V_32 -> V_80 ;
V_35 . V_319 [ 0 ] = V_21 -> V_258 ;
V_35 . V_320 = V_36 -> V_196 ;
V_35 . V_172 = V_36 -> V_172 ;
V_35 . V_321 = V_36 -> V_321 ;
if ( V_307 ) {
if ( V_32 == V_187 )
V_35 . V_307 = V_322 ;
else if ( V_32 == V_187 -> V_105 )
V_35 . V_307 = V_323 ;
else
V_35 . V_307 = V_324 ;
V_35 . V_170 = V_32 -> V_58 . V_170 ;
V_35 . V_189 = V_258 ;
}
if ( V_32 == V_187 -> V_105 )
V_187 = NULL ;
F_123 ( V_227 , V_32 -> V_85 , & V_35 ) ;
V_32 = V_32 -> V_101 ;
}
}
static void
F_124 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_102 ,
struct V_31 * V_187 , struct V_106 * V_188 )
{
struct V_31 * V_32 = V_187 , * V_190 = NULL ;
struct V_20 * V_21 ;
int V_91 = 0 ;
do {
struct V_22 * V_23 ;
V_21 = V_32 -> V_33 ;
V_91 ++ ;
F_29 ( V_21 , V_188 ) ;
F_7 ( & V_32 -> V_8 , V_102 ) ;
if ( V_190 )
V_190 -> V_101 = V_32 ;
V_190 = V_32 ;
if ( V_91 >= 2 )
break;
V_32 = F_92 ( V_2 , V_4 , V_6 , & V_188 ) ;
if ( ! V_32 )
break;
V_23 = F_9 ( V_32 -> V_33 ) ;
if ( V_23 -> V_51 & V_52 )
break;
F_13 ( V_6 -> V_11 -> V_12 , V_6 -> V_11 -> V_26 , V_32 ) ;
} while ( 1 );
}
static bool F_125 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_325 )
{
struct V_31 * V_32 ;
struct V_22 * V_23 ;
struct V_106 * V_188 ;
struct V_7 V_102 ;
int V_189 = 0 ;
bool V_307 , V_326 = true ;
if ( ! F_22 ( V_6 ) )
return false ;
F_32 ( & V_102 ) ;
V_32 = F_92 ( V_2 , V_4 , V_6 , & V_188 ) ;
if ( ! V_32 )
return false ;
V_23 = F_9 ( V_32 -> V_33 ) ;
V_307 = ! ! ( V_23 -> V_51 & V_52 ) ;
if ( ( V_307 && V_4 -> V_144 >= V_327 ) ||
( ! V_307 && V_4 -> V_143 >= V_328 ) ) {
* V_325 = true ;
return false ;
}
F_13 ( V_6 -> V_11 -> V_12 , V_6 -> V_11 -> V_26 , V_32 ) ;
if ( V_307 )
V_326 = F_95 ( V_2 , V_4 , V_6 , & V_102 , V_32 ,
V_188 , & V_189 ) ;
else
F_124 ( V_2 , V_4 , V_6 , & V_102 , V_32 , V_188 ) ;
if ( F_6 ( & V_102 ) )
return false ;
if ( V_6 -> V_137 || V_6 -> V_11 -> V_329 ) {
V_6 -> V_137 = false ;
V_23 -> V_51 |= V_183 ;
}
F_122 ( V_2 , V_32 , V_4 , V_189 ) ;
F_126 ( V_2 , V_4 , & V_102 , false ) ;
return true ;
}
int F_127 ( struct V_1 * V_2 , struct V_30 * V_26 ,
T_1 V_6 , T_1 * V_330 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_5 * V_331 ;
struct V_3 * V_4 ;
struct V_45 * V_11 ;
T_2 V_332 ;
F_128 ( V_261 , V_333 , L_1 , V_334 ) ;
V_11 = (struct V_45 * ) V_26 -> V_13 ;
V_331 = F_21 ( V_11 , V_6 ) ;
V_4 = V_331 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_26 -> V_335 . V_336 ) {
V_11 -> V_161 = ( 1 << ( V_337 +
V_26 -> V_335 . V_338 ) ) - 1 ;
V_332 = F_129 ( V_26 -> V_335 . V_339 ) ;
V_11 -> V_179 = V_332 ;
}
F_26 ( V_2 , V_331 ) ;
V_331 -> V_130 = true ;
* V_330 = V_331 -> V_59 = V_331 -> V_340 ;
V_331 -> V_67 = - 1 ;
memset ( V_331 -> V_64 , 0 , sizeof( V_331 -> V_64 ) ) ;
V_331 -> V_62 = V_331 -> V_65 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_2 , struct V_30 * V_26 , T_1 V_6 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_45 * V_11 = (struct V_45 * ) V_26 -> V_13 ;
struct V_5 * V_331 = F_21 ( V_11 , V_6 ) ;
struct V_3 * V_4 = V_331 -> V_4 ;
F_128 ( V_261 , V_333 , L_1 , V_334 ) ;
F_1 ( V_2 , V_4 ) ;
V_331 -> V_130 = false ;
F_31 ( V_2 , V_331 ) ;
F_26 ( V_2 , V_331 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_131 ( struct V_30 * V_26 , struct V_1 * V_2 ,
struct V_45 * V_11 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
bool V_341 ;
int V_18 ;
F_128 ( V_261 , V_333 , L_1 , V_334 ) ;
for ( V_18 = 0 , V_6 = & V_11 -> V_6 [ V_18 ] ;
V_18 < V_342 ; V_18 ++ , V_6 ++ ) {
V_4 = V_6 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( F_6 ( & V_6 -> V_8 ) ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_341 = F_22 ( V_6 ) ;
F_132 ( & V_6 -> V_8 ) ;
F_2 ( V_2 , V_4 ) ;
F_71 ( V_26 , V_18 , V_341 ) ;
}
}
void F_133 ( struct V_1 * V_2 , struct V_45 * V_11 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_18 ;
F_128 ( V_261 , V_333 , L_1 , V_334 ) ;
for ( V_18 = 0 , V_6 = & V_11 -> V_6 [ V_18 ] ;
V_18 < V_342 ; V_18 ++ , V_6 ++ ) {
V_4 = V_6 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_137 = true ;
if ( F_22 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_134 ( struct V_1 * V_2 , struct V_30 * V_26 ,
T_1 V_18 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_5 * V_6 ;
struct V_45 * V_11 ;
struct V_3 * V_4 ;
F_128 ( V_261 , V_333 , L_1 , V_334 ) ;
V_11 = (struct V_45 * ) V_26 -> V_13 ;
V_6 = F_21 ( V_11 , V_18 ) ;
V_4 = V_6 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_129 = V_343 << V_26 -> V_335 . V_338 ;
if ( F_22 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_135 ( struct V_103 * V_43 ,
struct V_30 * V_26 ,
T_1 V_344 , int V_91 ,
enum V_345 V_346 ,
bool V_347 )
{
struct V_1 * V_2 = V_43 -> V_348 ;
struct V_45 * V_11 = (struct V_45 * ) V_26 -> V_13 ;
struct V_3 * V_4 = V_2 -> V_38 . V_311 ;
struct V_22 * V_35 ;
struct V_7 V_102 ;
struct V_31 * V_349 = NULL , * V_32 ;
struct V_106 * V_188 ;
int V_350 = 0 ;
int V_120 ;
F_32 ( & V_102 ) ;
for ( V_120 = 0 ; V_344 && V_91 ; V_120 ++ , V_344 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_344 & 1 ) )
continue;
V_6 = F_21 ( V_11 , V_120 ) ;
F_1 ( V_2 , V_6 -> V_4 ) ;
while ( V_91 > 0 ) {
V_32 = F_92 ( V_2 , V_2 -> V_38 . V_311 , V_6 , & V_188 ) ;
if ( ! V_32 )
break;
F_29 ( V_32 -> V_33 , V_188 ) ;
F_7 ( & V_32 -> V_8 , & V_102 ) ;
F_13 ( V_6 -> V_11 -> V_12 , V_6 -> V_11 -> V_26 , V_32 ) ;
if ( F_76 ( V_32 ) ) {
F_39 ( V_2 , V_6 , V_32 ) ;
V_32 -> V_58 . V_184 &= ~ V_186 ;
}
if ( V_349 )
V_349 -> V_101 = V_32 ;
V_349 = V_32 ;
V_91 -- ;
V_350 ++ ;
F_44 ( V_4 -> V_74 , V_351 ) ;
if ( V_11 -> V_26 && ! F_22 ( V_6 ) )
F_71 ( V_11 -> V_26 , V_120 , false ) ;
}
F_3 ( V_2 , V_6 -> V_4 ) ;
}
if ( F_6 ( & V_102 ) )
return;
V_35 = F_9 ( V_349 -> V_33 ) ;
V_35 -> V_51 |= V_134 ;
V_32 = F_51 ( & V_102 , struct V_31 , V_8 ) ;
F_1 ( V_2 , V_4 ) ;
F_122 ( V_2 , V_32 , V_4 , 0 ) ;
F_126 ( V_2 , V_4 , & V_102 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_136 ( struct V_1 * V_2 , int V_352 , int V_353 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_354 V_355 ;
static const int V_356 [] = {
[ V_357 ] = V_358 ,
[ V_359 ] = V_360 ,
[ V_361 ] = V_362 ,
[ V_363 ] = V_364 ,
} ;
int V_74 , V_120 ;
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
V_355 . V_365 = V_356 [ V_353 ] ;
V_355 . V_366 = V_367 ;
V_355 . V_368 = V_367 ;
V_355 . V_369 = V_367 ;
V_355 . V_370 = 0 ;
if ( V_227 -> V_87 . V_174 & V_175 ) {
V_355 . V_371 = V_372 ;
} else {
if ( V_352 == V_373 )
V_355 . V_371 = V_374 ;
else
V_355 . V_371 = V_375 |
V_374 ;
}
V_74 = F_137 ( V_227 , V_352 , & V_355 ) ;
if ( V_74 == - 1 ) {
return NULL ;
}
if ( ! F_138 ( V_2 , V_74 ) ) {
struct V_3 * V_4 = & V_2 -> V_38 . V_4 [ V_74 ] ;
V_4 -> V_74 = V_74 ;
V_4 -> V_153 = - 1 ;
V_4 -> V_376 = NULL ;
F_64 ( & V_4 -> V_377 ) ;
F_32 ( & V_4 -> V_378 ) ;
F_139 ( & V_4 -> V_379 ) ;
V_4 -> V_143 = 0 ;
V_4 -> V_144 = 0 ;
V_4 -> V_142 = false ;
V_2 -> V_38 . V_380 |= 1 << V_74 ;
V_4 -> V_381 = V_4 -> V_382 = 0 ;
for ( V_120 = 0 ; V_120 < V_383 ; V_120 ++ )
F_32 ( & V_4 -> V_384 [ V_120 ] ) ;
}
return & V_2 -> V_38 . V_4 [ V_74 ] ;
}
int F_140 ( struct V_1 * V_2 , int V_385 ,
struct V_354 * V_386 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
int error = 0 ;
struct V_354 V_355 ;
F_141 ( V_2 -> V_38 . V_4 [ V_385 ] . V_74 != V_385 ) ;
F_142 ( V_227 , V_385 , & V_355 ) ;
V_355 . V_366 = V_386 -> V_366 ;
V_355 . V_368 = V_386 -> V_368 ;
V_355 . V_369 = V_386 -> V_369 ;
V_355 . V_387 = V_386 -> V_387 ;
V_355 . V_388 = V_386 -> V_388 ;
if ( ! F_143 ( V_227 , V_385 , & V_355 ) ) {
F_144 ( F_113 ( V_2 -> V_86 ) ,
L_2 , V_385 ) ;
error = - V_389 ;
} else {
F_145 ( V_227 , V_385 ) ;
}
return error ;
}
int F_146 ( struct V_1 * V_2 )
{
struct V_354 V_355 ;
struct V_390 * V_391 = & V_2 -> V_392 -> V_393 ;
int V_385 = V_2 -> V_393 . V_394 -> V_74 ;
F_142 ( V_2 -> V_86 , V_385 , & V_355 ) ;
V_355 . V_388 = ( F_147 ( V_391 -> V_395 ) *
V_396 ) / 100 ;
F_140 ( V_2 , V_385 , & V_355 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 )
{
struct V_31 * V_32 , * V_397 ;
struct V_7 V_53 ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_118 = V_119 ;
F_32 ( & V_53 ) ;
while ( ! F_6 ( V_8 ) ) {
V_32 = F_51 ( V_8 , struct V_31 , V_8 ) ;
if ( V_32 -> V_58 . V_89 ) {
F_52 ( & V_32 -> V_8 ) ;
F_53 ( V_2 , V_32 ) ;
continue;
}
V_397 = V_32 -> V_105 ;
F_149 ( & V_53 , V_8 , & V_397 -> V_8 ) ;
F_77 ( V_2 , V_4 , & V_55 , V_32 , & V_53 ) ;
}
}
void F_150 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_86 -> V_87 . V_174 & V_175 ) {
int V_146 = V_4 -> V_382 ;
while ( ! F_6 ( & V_4 -> V_384 [ V_146 ] ) ) {
F_148 ( V_2 , V_4 , & V_4 -> V_384 [ V_146 ] ) ;
F_38 ( V_146 , V_383 ) ;
}
V_4 -> V_382 = V_146 ;
}
V_4 -> V_376 = NULL ;
V_4 -> V_142 = false ;
F_148 ( V_2 , V_4 , & V_4 -> V_378 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_151 ( struct V_1 * V_2 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_3 * V_4 ;
int V_120 ;
V_94 V_398 = 0 ;
if ( F_37 ( V_399 , & V_261 -> V_400 ) )
return true ;
F_152 ( V_227 ) ;
for ( V_120 = 0 ; V_120 < V_401 ; V_120 ++ ) {
if ( ! F_138 ( V_2 , V_120 ) )
continue;
if ( ! V_2 -> V_38 . V_4 [ V_120 ] . V_143 )
continue;
if ( F_153 ( V_227 , V_2 -> V_38 . V_4 [ V_120 ] . V_74 ) )
V_398 |= F_154 ( V_120 ) ;
}
if ( V_398 ) {
F_155 ( V_2 , V_402 ) ;
F_128 ( V_261 , V_403 ,
L_3 , V_398 ) ;
}
for ( V_120 = 0 ; V_120 < V_401 ; V_120 ++ ) {
if ( ! F_138 ( V_2 , V_120 ) )
continue;
V_4 = & V_2 -> V_38 . V_4 [ V_120 ] ;
V_4 -> V_41 = false ;
F_150 ( V_2 , V_4 ) ;
}
return ! V_398 ;
}
void F_156 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_157 ( V_2 -> V_86 , V_4 -> V_74 ) ;
V_2 -> V_38 . V_380 &= ~ ( 1 << V_4 -> V_74 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_5 * V_6 , * V_404 ;
struct V_7 * V_405 ;
bool V_350 = false ;
if ( V_4 -> V_153 < 0 )
return;
if ( F_37 ( V_406 , & V_261 -> V_400 ) )
return;
F_48 ( & V_2 -> V_407 ) ;
V_405 = & V_2 -> V_392 -> V_17 [ V_4 -> V_153 ] ;
if ( F_6 ( V_405 ) ) {
F_50 ( & V_2 -> V_407 ) ;
return;
}
F_60 () ;
V_404 = F_158 ( V_405 -> V_72 , struct V_5 , V_8 ) ;
while ( ! F_6 ( V_405 ) ) {
bool V_325 = false ;
if ( V_2 -> V_392 -> V_41 )
break;
V_6 = F_51 ( V_405 , struct V_5 , V_8 ) ;
F_132 ( & V_6 -> V_8 ) ;
if ( F_125 ( V_2 , V_4 , V_6 , & V_325 ) )
V_350 = true ;
if ( F_22 ( V_6 ) )
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_325 )
break;
if ( V_6 == V_404 ) {
if ( ! V_350 )
break;
V_350 = false ;
V_404 = F_158 ( V_405 -> V_72 ,
struct V_5 , V_8 ) ;
}
}
F_62 () ;
F_50 ( & V_2 -> V_407 ) ;
}
void F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_408 ; V_120 ++ ) {
V_4 = V_2 -> V_38 . V_39 [ V_120 ] ;
F_48 ( & V_4 -> V_379 ) ;
F_79 ( V_2 , V_4 ) ;
F_50 ( & V_4 -> V_379 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_409 , bool V_410 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_260 * V_261 = F_113 ( V_227 ) ;
struct V_31 * V_32 , * V_104 ;
bool V_411 = false ;
bool V_412 ;
if ( F_6 ( V_409 ) )
return;
V_412 = ! ! ( V_227 -> V_87 . V_174 & V_175 ) ;
V_32 = F_51 ( V_409 , struct V_31 , V_8 ) ;
V_104 = F_158 ( V_409 -> V_72 , struct V_31 , V_8 ) ;
F_128 ( V_261 , V_413 , L_4 ,
V_4 -> V_74 , V_4 -> V_143 ) ;
if ( V_412 && F_6 ( & V_4 -> V_384 [ V_4 -> V_381 ] ) ) {
F_160 ( V_409 , & V_4 -> V_384 [ V_4 -> V_381 ] ) ;
F_38 ( V_4 -> V_381 , V_383 ) ;
V_411 = true ;
} else {
F_160 ( V_409 , & V_4 -> V_378 ) ;
if ( V_4 -> V_376 ) {
F_161 ( V_227 , V_4 -> V_376 , V_32 -> V_309 ) ;
F_128 ( V_261 , V_333 , L_5 ,
V_4 -> V_74 , V_4 -> V_376 ,
F_162 ( V_32 -> V_309 ) , V_32 -> V_85 ) ;
} else if ( ! V_412 )
V_411 = true ;
V_4 -> V_376 = V_104 -> V_85 ;
}
if ( V_411 ) {
F_44 ( V_4 -> V_74 , V_411 ) ;
F_163 ( V_227 , V_4 -> V_74 , V_32 -> V_309 ) ;
F_128 ( V_261 , V_333 , L_6 ,
V_4 -> V_74 , F_162 ( V_32 -> V_309 ) , V_32 -> V_85 ) ;
}
if ( ! V_412 || V_2 -> V_228 ) {
F_44 ( V_4 -> V_74 , V_414 ) ;
F_164 ( V_227 , V_4 -> V_74 ) ;
}
if ( ! V_410 ) {
while ( V_32 ) {
V_4 -> V_143 ++ ;
if ( F_75 ( V_32 ) )
V_4 -> V_144 ++ ;
V_104 = V_32 -> V_105 ;
V_32 = V_104 -> V_101 ;
V_104 -> V_101 = NULL ;
}
}
}
static void F_165 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_7 V_53 ;
struct V_31 * V_32 = V_36 -> V_32 ;
F_32 ( & V_53 ) ;
F_7 ( & V_32 -> V_8 , & V_53 ) ;
V_32 -> V_58 . V_184 = 0 ;
if ( V_6 && ( V_23 -> V_51 & V_52 ) ) {
V_32 -> V_58 . V_184 = V_185 ;
F_39 ( V_2 , V_6 , V_32 ) ;
}
V_32 -> V_101 = NULL ;
V_32 -> V_105 = V_32 ;
F_122 ( V_2 , V_32 , V_4 , V_36 -> V_196 ) ;
F_126 ( V_2 , V_4 , & V_53 , false ) ;
F_44 ( V_4 -> V_74 , V_415 ) ;
}
static void F_166 ( struct V_103 * V_43 ,
struct V_30 * V_26 ,
struct V_20 * V_21 ,
int V_196 )
{
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_416 * V_417 = V_23 -> V_133 . V_417 ;
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
const struct V_262 * V_263 ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_45 * V_11 = NULL ;
enum V_418 V_321 ;
bool V_419 = false ;
T_2 V_231 ;
if ( V_23 -> V_133 . V_12 &&
V_23 -> V_133 . V_12 -> V_420 . V_421 )
V_419 = true ;
V_263 = F_167 ( V_43 , V_23 ) ;
V_321 = F_168 ( V_21 ) ;
if ( V_26 )
V_11 = (struct V_45 * ) V_26 -> V_13 ;
if ( V_23 -> V_133 . V_12 ) {
struct V_29 * V_12 = V_23 -> V_133 . V_12 ;
V_231 = 2 * V_12 -> V_420 . V_231 ;
} else {
struct V_1 * V_2 = V_43 -> V_348 ;
V_231 = V_2 -> V_392 -> V_422 ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_4 = - 1 ;
if ( V_417 )
V_36 -> V_172 = V_417 -> V_423 ;
else if ( V_11 && F_169 ( V_71 -> V_77 ) && V_11 -> V_424 > 0 )
V_36 -> V_172 = V_11 -> V_424 ;
else
V_36 -> V_172 = V_173 ;
V_36 -> V_321 = V_321 ;
V_36 -> V_196 = V_196 ;
V_36 -> V_232 = V_231 ;
if ( ! V_263 )
return;
V_36 -> V_268 = V_263 -> V_292 ;
if ( V_419 )
V_36 -> V_268 |= V_263 -> V_293 ;
}
T_2 F_115 ( struct V_1 * V_2 , T_2 V_425 , V_94 V_263 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_426 * V_427 = V_227 -> V_427 ;
if ( ( V_227 -> V_87 . V_174 & V_428 ) && F_170 ( V_427 ) &&
( V_425 == 0x7 ) && ( V_263 < 0x90 ) )
return 0x3 ;
else if ( F_171 ( V_227 ) && F_172 ( V_227 ) &&
F_117 ( V_263 ) )
return 0x2 ;
else
return V_425 ;
}
static struct V_31 * F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_20 * V_21 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
struct V_31 * V_32 ;
int V_429 ;
T_1 V_25 ;
V_32 = F_47 ( V_2 ) ;
if ( ! V_32 ) {
F_128 ( V_261 , V_333 , L_7 ) ;
return NULL ;
}
F_55 ( V_32 ) ;
if ( V_6 && F_173 ( V_71 -> V_77 ) ) {
V_429 = F_174 ( V_71 -> V_430 ) & V_431 ;
V_25 = V_6 -> V_340 ;
V_71 -> V_430 = F_45 ( V_6 -> V_340 << V_28 ) ;
if ( V_429 )
V_71 -> V_430 |= F_45 ( V_429 ) ;
if ( ! F_175 ( V_71 -> V_77 ) )
F_38 ( V_6 -> V_340 , V_66 ) ;
V_32 -> V_58 . V_25 = V_25 ;
}
V_32 -> V_33 = V_21 ;
V_32 -> V_80 = F_176 ( V_2 -> V_79 , V_21 -> V_76 ,
V_21 -> V_258 , V_81 ) ;
if ( F_49 ( F_177 ( V_2 -> V_79 , V_32 -> V_80 ) ) ) {
V_32 -> V_33 = NULL ;
V_32 -> V_80 = 0 ;
F_144 ( F_113 ( V_2 -> V_86 ) ,
L_8 ) ;
F_53 ( V_2 , V_32 ) ;
return NULL ;
}
V_36 -> V_32 = V_32 ;
return V_32 ;
}
void F_178 ( struct V_260 * V_261 , struct V_20 * V_21 )
{
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
struct V_22 * V_35 = F_9 ( V_21 ) ;
struct V_29 * V_12 = V_35 -> V_133 . V_12 ;
struct V_9 * V_10 ;
if ( ! ( V_35 -> V_51 & V_432 ) )
return;
if ( ! V_12 )
return;
V_10 = (struct V_9 * ) V_12 -> V_13 ;
if ( V_35 -> V_51 & V_433 )
V_10 -> V_434 += 0x10 ;
V_71 -> V_430 &= F_45 ( V_431 ) ;
V_71 -> V_430 |= F_45 ( V_10 -> V_434 ) ;
}
static int F_179 ( struct V_103 * V_43 , struct V_20 * V_21 ,
struct V_435 * V_436 )
{
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
struct V_22 * V_35 = F_9 ( V_21 ) ;
struct V_30 * V_26 = V_436 -> V_26 ;
struct V_29 * V_12 = V_35 -> V_133 . V_12 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = V_43 -> V_348 ;
int V_149 = V_21 -> V_258 + V_437 ;
int V_438 , V_439 ;
if ( V_26 )
V_436 -> V_11 = (struct V_45 * ) V_26 -> V_13 ;
else if ( V_12 && F_169 ( V_71 -> V_77 ) ) {
V_10 = ( void * ) V_12 -> V_13 ;
V_436 -> V_11 = & V_10 -> V_440 ;
}
if ( V_35 -> V_133 . V_417 )
V_149 += V_35 -> V_133 . V_417 -> V_441 ;
F_178 ( F_113 ( V_2 -> V_86 ) , V_21 ) ;
if ( ( V_12 && V_12 -> type != V_442 &&
V_12 -> type != V_443 ) ||
! F_169 ( V_71 -> V_77 ) )
V_35 -> V_51 |= V_183 ;
V_438 = F_180 ( V_71 -> V_77 ) ;
V_439 = V_438 & 3 ;
if ( V_439 && V_21 -> V_258 > V_438 ) {
if ( F_181 ( V_21 ) < V_439 )
return - V_444 ;
F_182 ( V_21 , V_439 ) ;
memmove ( V_21 -> V_76 , V_21 -> V_76 + V_439 , V_438 ) ;
}
F_166 ( V_43 , V_26 , V_21 , V_149 ) ;
return 0 ;
}
int F_183 ( struct V_103 * V_43 , struct V_20 * V_21 ,
struct V_435 * V_436 )
{
struct V_70 * V_71 ;
struct V_22 * V_35 = F_9 ( V_21 ) ;
struct V_30 * V_26 = V_436 -> V_26 ;
struct V_29 * V_12 = V_35 -> V_133 . V_12 ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_9 * V_10 = NULL ;
struct V_1 * V_2 = V_43 -> V_348 ;
struct V_3 * V_4 = V_436 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_31 * V_32 ;
bool V_214 , V_445 = false , V_446 ;
int V_37 , V_447 ;
if ( V_12 )
V_10 = ( void * ) V_12 -> V_13 ;
if ( V_35 -> V_51 & V_448 )
V_436 -> V_449 = true ;
V_446 = ! ! ( V_35 -> V_133 . V_51 & V_450 ) ;
V_447 = F_179 ( V_43 , V_21 , V_436 ) ;
if ( V_447 )
return V_447 ;
V_71 = (struct V_70 * ) V_21 -> V_76 ;
V_37 = F_184 ( V_21 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_38 . V_39 [ V_37 ] ) {
V_36 -> V_4 = V_37 ;
if ( ++ V_4 -> V_40 > V_2 -> V_38 . V_42 [ V_37 ] &&
! V_4 -> V_41 ) {
if ( F_18 () )
F_185 ( V_2 -> V_43 , V_35 -> V_44 ) ;
else
F_185 ( V_2 -> V_43 , V_37 ) ;
V_4 -> V_41 = true ;
}
}
V_214 = F_173 ( V_71 -> V_77 ) ;
if ( F_18 () &&
F_186 ( V_71 -> V_77 ) &&
! V_436 -> V_449 )
V_214 = true ;
if ( ( ( V_10 && V_10 -> V_16 != V_2 -> V_392 ) ||
V_2 -> V_392 -> V_41 ) && ! V_436 -> V_449 ) {
if ( ! V_436 -> V_11 )
V_436 -> V_11 = & V_10 -> V_440 ;
V_214 = true ;
V_445 = true ;
}
if ( V_436 -> V_11 && V_214 )
V_6 = F_20 ( V_2 , V_436 -> V_11 , V_21 ) ;
if ( ! V_445 && V_446 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_38 . V_311 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_436 -> V_11 && V_214 ) {
F_17 ( V_6 -> V_4 != V_436 -> V_4 ) ;
if ( V_35 -> V_51 & V_183 )
V_6 -> V_137 = true ;
F_44 ( V_4 -> V_74 , V_451 ) ;
F_70 ( & V_6 -> V_48 , V_21 ) ;
if ( ! V_436 -> V_11 -> V_132 )
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
goto V_452;
}
V_32 = F_28 ( V_2 , V_4 , V_6 , V_21 ) ;
if ( ! V_32 ) {
F_16 ( V_2 , V_4 , V_21 ) ;
if ( V_436 -> V_453 )
F_187 ( V_21 ) ;
else
F_30 ( V_2 -> V_43 , V_21 ) ;
goto V_452;
}
V_32 -> V_58 . V_253 = V_436 -> V_453 ;
if ( V_436 -> V_453 )
V_32 -> V_58 . V_454 = V_455 ;
F_13 ( V_12 , V_26 , V_32 ) ;
F_165 ( V_2 , V_4 , V_6 , V_21 ) ;
V_452:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_188 ( struct V_103 * V_43 , struct V_29 * V_12 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_43 -> V_348 ;
struct V_435 V_436 = {
. V_4 = V_2 -> V_393 . V_394
} ;
struct V_257 V_35 = {} ;
struct V_70 * V_71 ;
struct V_31 * V_349 = NULL ;
struct V_31 * V_32 ;
F_189 ( V_102 ) ;
int V_145 = 0 ;
int V_456 ;
V_456 =
V_2 -> V_392 -> V_393 . V_395 * 1000 *
V_2 -> V_392 -> V_393 . V_457 / V_458 ;
do {
struct V_19 * V_36 = F_8 ( V_21 ) ;
if ( F_179 ( V_43 , V_21 , & V_436 ) )
break;
V_32 = F_28 ( V_2 , V_436 . V_4 , NULL , V_21 ) ;
if ( ! V_32 )
break;
V_32 -> V_105 = V_32 ;
F_13 ( V_12 , NULL , V_32 ) ;
F_112 ( V_2 , V_32 , & V_35 , V_36 -> V_196 , false ) ;
V_145 += V_35 . V_34 [ 0 ] . V_285 ;
if ( V_349 )
V_349 -> V_101 = V_32 ;
F_7 ( & V_32 -> V_8 , & V_102 ) ;
V_349 = V_32 ;
V_21 = NULL ;
if ( V_145 > V_456 )
break;
V_21 = F_190 ( V_43 , V_12 ) ;
} while( V_21 );
if ( V_21 )
F_30 ( V_43 , V_21 ) ;
if ( F_6 ( & V_102 ) )
return;
V_32 = F_51 ( & V_102 , struct V_31 , V_8 ) ;
V_71 = (struct V_70 * ) V_32 -> V_33 -> V_76 ;
if ( V_71 -> V_77 & F_45 ( V_459 ) ) {
V_71 -> V_77 &= ~ F_45 ( V_459 ) ;
F_46 ( V_2 -> V_79 , V_32 -> V_80 ,
sizeof( * V_71 ) , V_81 ) ;
}
F_1 ( V_2 , V_436 . V_4 ) ;
F_122 ( V_2 , V_32 , V_436 . V_4 , 0 ) ;
F_126 ( V_2 , V_436 . V_4 , & V_102 , false ) ;
F_44 ( V_436 . V_4 -> V_74 , V_415 ) ;
F_2 ( V_2 , V_436 . V_4 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_20 * V_21 ,
int V_460 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
int V_438 , V_439 ;
unsigned long V_51 ;
F_128 ( V_261 , V_333 , L_9 , V_21 ) ;
if ( V_2 -> V_86 -> V_461 )
F_191 ( V_462 , & V_2 -> V_86 -> V_461 -> V_463 ) ;
if ( ! ( V_460 & V_68 ) ) {
if ( V_23 -> V_51 & V_313 )
V_23 -> V_51 |= V_464 ;
else
V_23 -> V_51 |= V_465 ;
}
V_438 = F_180 ( V_71 -> V_77 ) ;
V_439 = V_438 & 3 ;
if ( V_439 && V_21 -> V_258 > V_438 + V_439 ) {
memmove ( V_21 -> V_76 + V_439 , V_21 -> V_76 , V_438 ) ;
F_192 ( V_21 , V_439 ) ;
}
F_193 ( & V_2 -> V_466 , V_51 ) ;
if ( ( V_2 -> V_467 & V_468 ) && ! V_4 -> V_143 ) {
V_2 -> V_467 &= ~ V_468 ;
F_128 ( V_261 , V_469 ,
L_10 ,
V_2 -> V_467 & ( V_470 |
V_471 |
V_472 |
V_468 ) ) ;
}
F_194 ( & V_2 -> V_466 , V_51 ) ;
F_70 ( & V_4 -> V_377 , V_21 ) ;
F_16 ( V_2 , V_4 , V_21 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_3 * V_4 , struct V_7 * V_102 ,
struct V_54 * V_55 , int V_90 )
{
struct V_20 * V_21 = V_32 -> V_33 ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
unsigned long V_51 ;
int V_460 = 0 ;
if ( ! V_90 )
V_460 |= V_68 ;
if ( V_55 -> V_118 & V_135 )
V_23 -> V_51 |= V_473 ;
F_195 ( V_2 -> V_79 , V_32 -> V_80 , V_21 -> V_258 , V_81 ) ;
V_32 -> V_80 = 0 ;
if ( V_2 -> V_228 )
goto V_474;
if ( V_32 -> V_58 . V_253 ) {
if ( F_196 ( V_455 ,
V_32 -> V_58 . V_454 +
F_197 ( V_475 ) ) )
F_187 ( V_21 ) ;
else
F_198 ( & V_2 -> V_476 ) ;
} else {
F_199 ( V_2 , V_32 , V_55 , V_4 , V_460 ) ;
F_42 ( V_2 , V_21 , V_460 , V_4 ) ;
}
V_474:
V_32 -> V_33 = NULL ;
F_193 ( & V_2 -> V_38 . V_82 , V_51 ) ;
F_160 ( V_102 , & V_2 -> V_38 . V_83 ) ;
F_194 ( & V_2 -> V_38 . V_82 , V_51 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_54 * V_55 , int V_91 , int V_92 ,
int V_90 )
{
struct V_20 * V_21 = V_32 -> V_33 ;
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_103 * V_43 = V_2 -> V_43 ;
struct V_226 * V_227 = V_2 -> V_86 ;
T_2 V_120 , V_477 ;
if ( V_90 )
V_23 -> V_478 . V_479 = V_55 -> V_480 ;
V_477 = V_55 -> V_122 ;
F_17 ( V_477 >= V_43 -> V_481 ) ;
if ( V_23 -> V_51 & V_52 ) {
V_23 -> V_51 |= V_482 ;
F_141 ( V_92 > V_91 ) ;
}
V_23 -> V_478 . V_483 = V_91 ;
V_23 -> V_478 . V_484 = V_91 - V_92 ;
if ( ( V_55 -> V_118 & V_135 ) == 0 &&
( V_23 -> V_51 & V_313 ) == 0 ) {
if ( F_49 ( V_55 -> V_125 & ( V_485 |
V_486 ) ) &&
F_169 ( V_71 -> V_77 ) &&
V_227 -> V_487 >= V_2 -> V_86 -> V_488 . V_489 )
V_23 -> V_478 . V_34 [ V_477 ] . V_69 =
V_43 -> V_490 ;
}
for ( V_120 = V_477 + 1 ; V_120 < V_43 -> V_481 ; V_120 ++ ) {
V_23 -> V_478 . V_34 [ V_120 ] . V_69 = 0 ;
V_23 -> V_478 . V_34 [ V_120 ] . V_146 = - 1 ;
}
V_23 -> V_478 . V_34 [ V_477 ] . V_69 = V_55 -> V_121 + 1 ;
}
static void F_200 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_260 * V_261 = F_113 ( V_227 ) ;
struct V_31 * V_32 , * V_397 , * V_491 = NULL ;
struct V_7 V_53 ;
struct V_492 * V_493 ;
struct V_54 V_55 ;
int V_478 ;
F_128 ( V_261 , V_413 , L_11 ,
V_4 -> V_74 , F_201 ( V_2 -> V_86 , V_4 -> V_74 ) ,
V_4 -> V_376 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_37 ( V_406 , & V_261 -> V_400 ) )
break;
if ( F_6 ( & V_4 -> V_378 ) ) {
V_4 -> V_376 = NULL ;
F_79 ( V_2 , V_4 ) ;
break;
}
V_32 = F_51 ( & V_4 -> V_378 , struct V_31 , V_8 ) ;
V_491 = NULL ;
if ( V_32 -> V_58 . V_89 ) {
V_491 = V_32 ;
if ( F_202 ( & V_491 -> V_8 , & V_4 -> V_378 ) )
break;
V_32 = F_158 ( V_491 -> V_8 . V_494 , struct V_31 ,
V_8 ) ;
}
V_397 = V_32 -> V_105 ;
V_493 = V_397 -> V_85 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_478 = F_203 ( V_227 , V_493 , & V_55 ) ;
if ( V_478 == - V_495 )
break;
F_44 ( V_4 -> V_74 , V_496 ) ;
V_397 -> V_58 . V_89 = true ;
F_32 ( & V_53 ) ;
if ( ! F_204 ( & V_397 -> V_8 ) )
F_149 ( & V_53 ,
& V_4 -> V_378 , V_397 -> V_8 . V_72 ) ;
if ( V_491 ) {
F_52 ( & V_491 -> V_8 ) ;
F_53 ( V_2 , V_491 ) ;
}
F_77 ( V_2 , V_4 , & V_55 , V_32 , & V_53 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_226 * V_227 = V_2 -> V_86 ;
V_94 V_497 = ( ( 1 << V_401 ) - 1 ) & V_227 -> V_498 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_401 ; V_120 ++ ) {
if ( F_138 ( V_2 , V_120 ) && ( V_497 & ( 1 << V_120 ) ) )
F_200 ( V_2 , & V_2 -> V_38 . V_4 [ V_120 ] ) ;
}
}
void F_206 ( struct V_1 * V_2 )
{
struct V_54 V_55 ;
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_226 * V_227 = V_2 -> V_86 ;
struct V_3 * V_4 ;
struct V_31 * V_32 , * V_397 ;
struct V_7 V_53 ;
struct V_7 * V_499 ;
int V_478 ;
for (; ; ) {
if ( F_37 ( V_406 , & V_261 -> V_400 ) )
break;
V_478 = F_203 ( V_227 , NULL , ( void * ) & V_55 ) ;
if ( V_478 == - V_495 )
break;
if ( V_478 == - V_389 ) {
F_128 ( V_261 , V_333 , L_12 ) ;
break;
}
if ( V_55 . V_500 == V_2 -> V_393 . V_501 ) {
V_2 -> V_393 . V_502 = true ;
V_2 -> V_393 . V_503 = ! ( V_55 . V_118 & V_141 ) ;
if ( F_18 () ) {
F_207 ( V_2 , NULL ,
V_504 ) ;
}
F_208 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_38 . V_4 [ V_55 . V_500 ] ;
F_1 ( V_2 , V_4 ) ;
F_44 ( V_4 -> V_74 , V_496 ) ;
V_499 = & V_4 -> V_384 [ V_4 -> V_382 ] ;
if ( F_6 ( V_499 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_32 = F_51 ( V_499 , struct V_31 , V_8 ) ;
if ( V_32 -> V_58 . V_89 ) {
F_52 ( & V_32 -> V_8 ) ;
F_53 ( V_2 , V_32 ) ;
V_32 = F_51 ( V_499 , struct V_31 , V_8 ) ;
}
V_397 = V_32 -> V_105 ;
F_32 ( & V_53 ) ;
if ( F_202 ( & V_397 -> V_8 , V_499 ) ) {
F_160 ( V_499 , & V_53 ) ;
F_38 ( V_4 -> V_382 , V_383 ) ;
if ( ! F_6 ( & V_4 -> V_378 ) ) {
struct V_7 V_102 ;
F_32 ( & V_102 ) ;
V_4 -> V_376 = NULL ;
F_160 ( & V_4 -> V_378 , & V_102 ) ;
F_126 ( V_2 , V_4 , & V_102 , true ) ;
}
} else {
V_397 -> V_58 . V_89 = true ;
if ( V_32 != V_397 )
F_149 ( & V_53 , V_499 ,
V_397 -> V_8 . V_72 ) ;
}
F_77 ( V_2 , V_4 , & V_55 , V_32 , & V_53 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_209 ( struct V_1 * V_2 , int V_505 )
{
struct V_506 * V_507 = & V_2 -> V_508 ;
T_2 V_509 = V_2 -> V_86 -> V_87 . V_509 ;
V_507 -> V_510 = V_505 * V_509 ;
V_507 -> V_511 = F_210 ( V_2 -> V_79 , V_507 -> V_510 ,
& V_507 -> V_512 , V_513 ) ;
if ( ! V_507 -> V_511 )
return - V_444 ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
int V_514 ;
V_514 = F_209 ( V_2 , V_515 ) ;
if ( ! V_514 )
F_212 ( V_2 -> V_86 , V_2 -> V_508 . V_511 ,
V_2 -> V_508 . V_512 ,
V_515 ) ;
return V_514 ;
}
int F_213 ( struct V_1 * V_2 , int V_516 )
{
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
int error = 0 ;
F_139 ( & V_2 -> V_38 . V_82 ) ;
error = F_214 ( V_2 , & V_2 -> V_38 . V_517 , & V_2 -> V_38 . V_83 ,
L_13 , V_516 , 1 , 1 ) ;
if ( error != 0 ) {
F_144 ( V_261 ,
L_14 , error ) ;
return error ;
}
error = F_214 ( V_2 , & V_2 -> V_393 . V_518 , & V_2 -> V_393 . V_519 ,
L_15 , V_458 , 1 , 1 ) ;
if ( error != 0 ) {
F_144 ( V_261 ,
L_16 , error ) ;
return error ;
}
F_215 ( & V_2 -> V_520 , V_521 ) ;
if ( V_2 -> V_86 -> V_87 . V_174 & V_175 )
error = F_211 ( V_2 ) ;
return error ;
}
void F_216 ( struct V_1 * V_2 , struct V_45 * V_11 )
{
struct V_5 * V_6 ;
int V_18 , V_522 ;
for ( V_18 = 0 , V_6 = & V_11 -> V_6 [ V_18 ] ;
V_18 < V_342 ;
V_18 ++ , V_6 ++ ) {
V_6 -> V_11 = V_11 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_59 = V_6 -> V_340 = 0 ;
V_6 -> V_129 = V_523 ;
V_6 -> V_62 = V_6 -> V_65 = 0 ;
V_6 -> V_130 = false ;
V_6 -> V_137 = true ;
F_64 ( & V_6 -> V_48 ) ;
F_64 ( & V_6 -> V_49 ) ;
F_32 ( & V_6 -> V_8 ) ;
V_522 = F_5 ( V_18 ) ;
V_6 -> V_4 = V_2 -> V_38 . V_39 [ V_522 ] ;
}
}
void F_217 ( struct V_1 * V_2 , struct V_45 * V_11 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_18 ;
for ( V_18 = 0 , V_6 = & V_11 -> V_6 [ V_18 ] ;
V_18 < V_342 ; V_18 ++ , V_6 ++ ) {
V_4 = V_6 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! F_6 ( & V_6 -> V_8 ) )
F_132 ( & V_6 -> V_8 ) ;
F_41 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_130 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
int F_218 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_435 * V_436 )
{
struct V_70 * V_71 = (struct V_70 * ) V_21 -> V_76 ;
struct V_19 * V_36 = F_8 ( V_21 ) ;
struct V_260 * V_261 = F_113 ( V_2 -> V_86 ) ;
struct V_31 * V_32 ;
int V_438 , V_439 ;
V_438 = F_180 ( V_71 -> V_77 ) ;
V_439 = V_438 & 3 ;
if ( V_439 && V_21 -> V_258 > V_438 ) {
if ( F_181 ( V_21 ) < V_439 ) {
F_128 ( V_261 , V_333 ,
L_17 ) ;
return - V_524 ;
}
F_182 ( V_21 , V_439 ) ;
memmove ( V_21 -> V_76 , V_21 -> V_76 + V_439 , V_438 ) ;
}
V_36 -> V_172 = V_173 ;
V_36 -> V_196 = V_21 -> V_258 + V_437 ;
V_36 -> V_321 = V_525 ;
V_32 = F_28 ( V_2 , V_436 -> V_4 , NULL , V_21 ) ;
if ( ! V_32 ) {
F_128 ( V_261 , V_333 , L_18 ) ;
return - V_524 ;
}
F_13 ( V_2 -> V_526 , NULL , V_32 ) ;
F_161 ( V_2 -> V_86 , V_32 -> V_85 , V_32 -> V_309 ) ;
F_219 ( V_2 -> V_86 , V_436 -> V_4 -> V_74 ) ;
F_165 ( V_2 , V_436 -> V_4 , NULL , V_21 ) ;
return 0 ;
}
