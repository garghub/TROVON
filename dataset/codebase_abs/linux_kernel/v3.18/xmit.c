void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
__acquires( &txq->axq_lock
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_6 -> V_13 -> V_14 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_18 ;
if ( ! V_17 )
return;
if ( V_6 -> V_19 )
return;
V_6 -> V_19 = true ;
F_5 ( & V_6 -> V_10 , & V_8 -> V_20 ) ;
if ( V_8 -> V_19 )
return;
V_8 -> V_19 = true ;
V_10 = & V_17 -> V_21 [ F_6 ( V_6 -> V_22 ) ] ;
F_5 ( & V_8 -> V_10 , V_10 ) ;
}
static struct V_23 * F_7 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
F_9 ( sizeof( struct V_23 ) >
sizeof( V_27 -> V_28 ) ) ;
return (struct V_23 * ) & V_27 -> V_28 [ 0 ] ;
}
static void F_10 ( struct V_5 * V_6 , T_1 V_29 )
{
if ( ! V_6 -> V_13 -> V_30 )
return;
F_11 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 -> V_31 , V_6 -> V_22 ,
V_29 << V_32 ) ;
}
static void F_12 ( struct V_33 * V_14 , struct V_34 * V_30 ,
struct V_35 * V_36 )
{
F_13 ( V_14 , V_30 , V_36 -> V_37 , V_36 -> V_38 ,
F_14 ( V_36 -> V_38 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_24 * V_25 )
{
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
int V_41 = V_40 -> V_4 ;
if ( V_41 < 0 )
return;
V_4 = V_2 -> V_42 . V_43 [ V_41 ] ;
if ( F_16 ( -- V_4 -> V_44 < 0 ) )
V_4 -> V_44 = 0 ;
if ( V_4 -> V_45 &&
V_4 -> V_44 < V_2 -> V_42 . V_46 [ V_41 ] ) {
if ( F_17 () )
F_18 ( V_2 -> V_47 , V_39 -> V_48 ) ;
else
F_18 ( V_2 -> V_47 , V_41 ) ;
V_4 -> V_45 = false ;
}
}
static struct V_5 *
F_19 ( struct V_1 * V_2 , struct V_49 * V_13 , struct V_24 * V_25 )
{
T_2 V_22 = V_25 -> V_50 & V_51 ;
return F_20 ( V_13 , V_22 ) ;
}
static bool F_21 ( struct V_5 * V_6 )
{
return ! F_22 ( & V_6 -> V_52 ) || ! F_22 ( & V_6 -> V_53 ) ;
}
static struct V_24 * F_23 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
V_25 = F_24 ( & V_6 -> V_53 ) ;
if ( ! V_25 )
V_25 = F_24 ( & V_6 -> V_52 ) ;
return V_25 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_26 * V_27 ;
struct V_24 * V_25 , * V_54 ;
struct V_35 * V_36 ;
struct V_23 * V_40 ;
F_26 (&tid->buf_q, skb, tskb) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
V_27 = F_8 ( V_25 ) ;
V_27 -> V_55 &= ~ V_56 ;
if ( V_36 )
continue;
V_36 = F_27 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_28 ( V_25 , & V_6 -> V_52 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
F_29 ( V_2 -> V_47 , V_25 ) ;
continue;
}
}
}
static void F_30 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_24 * V_25 ;
struct V_35 * V_36 ;
struct V_9 V_57 ;
struct V_58 V_59 ;
struct V_23 * V_40 ;
bool V_60 = false ;
F_31 ( & V_57 ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
while ( ( V_25 = F_24 ( & V_6 -> V_53 ) ) ) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
F_29 ( V_2 -> V_47 , V_25 ) ;
continue;
}
if ( V_40 -> V_61 ) {
F_32 ( V_2 , V_6 , V_36 -> V_62 . V_29 ) ;
V_60 = true ;
}
F_5 ( & V_36 -> V_10 , & V_57 ) ;
F_33 ( V_2 , V_36 , V_4 , & V_57 , & V_59 , 0 ) ;
}
if ( V_60 ) {
F_2 ( V_2 , V_4 ) ;
F_10 ( V_6 , V_6 -> V_63 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_32 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
int V_64 , V_65 ;
V_64 = F_34 ( V_6 -> V_63 , V_29 ) ;
V_65 = ( V_6 -> V_66 + V_64 ) & ( V_67 - 1 ) ;
F_35 ( V_65 , V_6 -> V_68 ) ;
while ( V_6 -> V_66 != V_6 -> V_69 && ! F_36 ( V_6 -> V_66 , V_6 -> V_68 ) ) {
F_37 ( V_6 -> V_63 , V_70 ) ;
F_37 ( V_6 -> V_66 , V_67 ) ;
if ( V_6 -> V_71 >= 0 )
V_6 -> V_71 -- ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
T_1 V_29 = V_36 -> V_62 . V_29 ;
int V_64 , V_65 ;
V_64 = F_34 ( V_6 -> V_63 , V_29 ) ;
V_65 = ( V_6 -> V_66 + V_64 ) & ( V_67 - 1 ) ;
F_39 ( V_65 , V_6 -> V_68 ) ;
V_40 -> V_61 = 1 ;
if ( V_64 >= ( ( V_6 -> V_69 - V_6 -> V_66 ) &
( V_67 - 1 ) ) ) {
V_6 -> V_69 = V_65 ;
F_37 ( V_6 -> V_69 , V_67 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_35 * V_36 ;
struct V_9 V_57 ;
struct V_58 V_59 ;
struct V_23 * V_40 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_31 ( & V_57 ) ;
while ( ( V_25 = F_23 ( V_6 ) ) ) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_36 ) {
F_41 ( V_2 , V_25 , V_72 , V_4 ) ;
continue;
}
F_5 ( & V_36 -> V_10 , & V_57 ) ;
F_33 ( V_2 , V_36 , V_4 , & V_57 , & V_59 , 0 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_24 * V_25 , int V_73 )
{
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_35 * V_36 = V_40 -> V_36 ;
struct V_74 * V_75 ;
int V_76 = V_40 -> V_77 ;
F_43 ( V_4 -> V_78 , V_79 ) ;
V_40 -> V_77 += V_73 ;
if ( V_76 > 0 )
return;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_75 -> V_81 |= F_44 ( V_82 ) ;
F_45 ( V_2 -> V_83 , V_36 -> V_84 ,
sizeof( * V_75 ) , V_85 ) ;
}
static struct V_35 * F_46 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
F_47 ( & V_2 -> V_42 . V_86 ) ;
if ( F_48 ( F_49 ( & V_2 -> V_42 . V_87 ) ) ) {
F_50 ( & V_2 -> V_42 . V_86 ) ;
return NULL ;
}
V_36 = F_51 ( & V_2 -> V_42 . V_87 , struct V_35 , V_10 ) ;
F_52 ( & V_36 -> V_10 ) ;
F_50 ( & V_2 -> V_42 . V_86 ) ;
return V_36 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
F_47 ( & V_2 -> V_42 . V_86 ) ;
F_5 ( & V_36 -> V_10 , & V_2 -> V_42 . V_87 ) ;
F_50 ( & V_2 -> V_42 . V_86 ) ;
}
static struct V_35 * F_54 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_35 * V_88 ;
V_88 = F_46 ( V_2 ) ;
if ( F_16 ( ! V_88 ) )
return NULL ;
F_55 ( V_88 ) ;
V_88 -> V_37 = V_36 -> V_37 ;
V_88 -> V_84 = V_36 -> V_84 ;
memcpy ( V_88 -> V_89 , V_36 -> V_89 , V_2 -> V_90 -> V_91 . V_92 ) ;
V_88 -> V_62 = V_36 -> V_62 ;
V_88 -> V_62 . V_93 = false ;
return V_88 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_58 * V_59 , int V_94 ,
int * V_95 , int * V_96 )
{
struct V_23 * V_40 ;
T_1 V_97 = 0 ;
V_98 V_99 [ V_100 >> 5 ] ;
int V_101 ;
int V_102 = 0 ;
* V_96 = 0 ;
* V_95 = 0 ;
V_102 = F_57 ( V_36 ) ;
if ( V_102 ) {
V_97 = V_59 -> V_103 ;
memcpy ( V_99 , & V_59 -> V_104 , V_100 >> 3 ) ;
}
while ( V_36 ) {
V_40 = F_7 ( V_36 -> V_37 ) ;
V_101 = F_34 ( V_97 , V_36 -> V_62 . V_29 ) ;
( * V_95 ) ++ ;
if ( ! V_94 || ( V_102 && ! F_58 ( V_99 , V_101 ) ) )
( * V_96 ) ++ ;
V_36 = V_36 -> V_105 ;
}
}
static void F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_9 * V_106 ,
struct V_58 * V_59 , int V_94 )
{
struct V_49 * V_13 = NULL ;
struct V_24 * V_25 ;
struct V_34 * V_30 ;
struct V_107 * V_47 = V_2 -> V_47 ;
struct V_74 * V_75 ;
struct V_26 * V_27 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_105 , * V_108 = V_36 -> V_109 ;
struct V_9 V_57 ;
struct V_110 V_111 ;
T_1 V_97 = 0 , V_112 = 0 , V_113 = 0 , V_114 ;
V_98 V_99 [ V_100 >> 5 ] ;
int V_102 , V_115 , V_116 , V_60 = 0 , V_117 = 0 , V_96 = 0 ;
bool V_118 = true , V_119 ;
struct V_120 V_38 [ 4 ] ;
struct V_23 * V_40 ;
int V_95 ;
bool V_121 = ! ! ( V_59 -> V_122 & V_123 ) ;
int V_124 , V_77 ;
int V_71 = - 1 ;
V_25 = V_36 -> V_37 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_27 = F_8 ( V_25 ) ;
memcpy ( V_38 , V_36 -> V_38 , sizeof( V_38 ) ) ;
V_77 = V_59 -> V_125 + 1 ;
for ( V_124 = 0 ; V_124 < V_59 -> V_126 ; V_124 ++ )
V_77 += V_38 [ V_124 ] . V_73 ;
F_60 () ;
V_30 = F_61 ( V_47 , V_75 -> V_127 , V_75 -> V_128 ) ;
if ( ! V_30 ) {
F_62 () ;
F_31 ( & V_57 ) ;
while ( V_36 ) {
V_105 = V_36 -> V_105 ;
if ( ! V_36 -> V_62 . V_93 || V_105 != NULL )
F_63 ( & V_36 -> V_10 , & V_57 ) ;
F_33 ( V_2 , V_36 , V_4 , & V_57 , V_59 , 0 ) ;
V_36 = V_105 ;
}
return;
}
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_6 = F_19 ( V_2 , V_13 , V_25 ) ;
V_114 = V_6 -> V_63 ;
V_119 = V_59 -> V_129 & V_130 ;
if ( V_119 && V_6 -> V_22 != V_59 -> V_6 )
V_94 = false ;
V_102 = F_57 ( V_36 ) ;
memset ( V_99 , 0 , V_100 >> 3 ) ;
if ( V_102 && V_94 ) {
if ( V_59 -> V_129 & V_130 ) {
V_97 = V_59 -> V_103 ;
memcpy ( V_99 , & V_59 -> V_104 , V_100 >> 3 ) ;
} else {
if ( V_2 -> V_90 -> V_131 == V_132 )
V_117 = 1 ;
}
}
F_64 ( & V_111 ) ;
F_56 ( V_2 , V_36 , V_59 , V_94 , & V_95 , & V_96 ) ;
while ( V_36 ) {
T_1 V_29 = V_36 -> V_62 . V_29 ;
V_115 = V_116 = V_60 = 0 ;
V_105 = V_36 -> V_105 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_40 = F_7 ( V_25 ) ;
if ( ! F_65 ( V_6 -> V_63 , V_6 -> V_133 , V_29 ) ||
! V_6 -> V_134 ) {
V_115 = 1 ;
} else if ( F_58 ( V_99 , F_34 ( V_97 , V_29 ) ) ) {
V_112 ++ ;
} else if ( ! V_102 && V_94 ) {
V_112 ++ ;
} else if ( V_121 ) {
V_116 = 1 ;
} else if ( V_40 -> V_77 < V_135 ) {
if ( V_94 || ! V_13 -> V_136 )
F_42 ( V_2 , V_4 , V_36 -> V_37 ,
V_77 ) ;
V_116 = 1 ;
} else {
V_115 = 1 ;
V_113 ++ ;
V_71 = F_66 ( int , V_71 ,
F_34 ( V_114 , V_29 ) ) ;
}
F_31 ( & V_57 ) ;
if ( V_105 != NULL || ! V_108 -> V_62 . V_93 )
F_63 ( & V_36 -> V_10 , & V_57 ) ;
if ( ! V_116 ) {
F_32 ( V_2 , V_6 , V_29 ) ;
if ( V_118 && ( V_112 == 1 || V_113 == 1 ) ) {
memcpy ( V_27 -> V_137 . V_38 , V_38 , sizeof( V_38 ) ) ;
F_67 ( V_2 , V_36 , V_59 , V_95 , V_96 , V_94 ) ;
V_118 = false ;
if ( V_36 == V_36 -> V_109 )
F_68 ( V_2 -> V_90 ,
V_36 -> V_37 ,
V_59 ) ;
}
F_33 ( V_2 , V_36 , V_4 , & V_57 , V_59 ,
! V_115 ) ;
} else {
if ( V_27 -> V_55 & V_138 ) {
V_27 -> V_55 &= ~ V_138 ;
F_69 ( V_30 ) ;
}
if ( V_36 -> V_105 == NULL && V_108 -> V_62 . V_93 ) {
struct V_35 * V_88 ;
V_88 = F_54 ( V_2 , V_108 ) ;
if ( ! V_88 ) {
F_32 ( V_2 , V_6 , V_29 ) ;
F_33 ( V_2 , V_36 , V_4 ,
& V_57 , V_59 , 0 ) ;
V_71 = F_66 ( int , V_71 ,
F_34 ( V_114 , V_29 ) ) ;
break;
}
V_40 -> V_36 = V_88 ;
}
F_70 ( & V_111 , V_25 ) ;
}
V_36 = V_105 ;
}
if ( ! F_22 ( & V_111 ) ) {
if ( V_13 -> V_136 )
F_71 ( V_30 , V_6 -> V_22 , true ) ;
F_72 ( & V_111 , & V_6 -> V_53 ) ;
if ( ! V_13 -> V_136 ) {
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_59 -> V_122 & ( V_139 | V_140 ) )
V_6 -> V_8 -> V_141 = true ;
}
}
if ( V_71 >= 0 ) {
T_1 V_142 = F_73 ( V_114 , V_71 ) ;
if ( F_65 ( V_6 -> V_63 , V_6 -> V_133 , V_142 ) )
V_6 -> V_71 = F_34 ( V_6 -> V_63 , V_142 ) ;
F_2 ( V_2 , V_4 ) ;
F_10 ( V_6 , F_73 ( V_114 , V_71 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_62 () ;
if ( V_117 )
F_74 ( V_2 , V_143 ) ;
}
static bool F_75 ( struct V_35 * V_36 )
{
struct V_26 * V_39 = F_8 ( V_36 -> V_37 ) ;
return F_76 ( V_36 ) && ! ( V_39 -> V_55 & V_144 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_58 * V_59 , struct V_35 * V_36 ,
struct V_9 * V_57 )
{
struct V_26 * V_39 ;
bool V_94 , V_121 ;
V_94 = ! ( V_59 -> V_122 & V_145 ) ;
V_121 = ! ! ( V_59 -> V_122 & V_123 ) ;
V_4 -> V_146 = false ;
V_4 -> V_147 -- ;
if ( F_75 ( V_36 ) )
V_4 -> V_148 -- ;
V_59 -> V_149 = F_78 ( V_2 -> V_90 , V_36 -> V_89 ,
V_59 -> V_126 ) ;
if ( ! F_76 ( V_36 ) ) {
if ( ! V_121 ) {
V_39 = F_8 ( V_36 -> V_37 ) ;
memcpy ( V_39 -> V_137 . V_38 , V_36 -> V_38 ,
sizeof( V_39 -> V_137 . V_38 ) ) ;
F_67 ( V_2 , V_36 , V_59 , 1 , V_94 ? 0 : 1 , V_94 ) ;
F_68 ( V_2 -> V_90 , V_36 -> V_37 , V_59 ) ;
}
F_33 ( V_2 , V_36 , V_4 , V_57 , V_59 , V_94 ) ;
} else
F_59 ( V_2 , V_4 , V_36 , V_57 , V_59 , V_94 ) ;
if ( ! V_121 )
F_79 ( V_2 , V_4 ) ;
}
static bool F_80 ( struct V_35 * V_36 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_120 * V_38 ;
int V_124 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_27 -> V_137 . V_38 ;
for ( V_124 = 0 ; V_124 < 4 ; V_124 ++ ) {
if ( ! V_38 [ V_124 ] . V_73 || V_38 [ V_124 ] . V_150 < 0 )
break;
if ( ! ( V_38 [ V_124 ] . V_55 & V_151 ) )
return true ;
}
return false ;
}
static V_98 F_81 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_120 * V_38 ;
V_98 V_152 , V_153 ;
T_1 V_154 , V_155 , V_156 = 0 ;
int V_41 = V_6 -> V_8 -> V_4 -> V_157 ;
int V_124 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_152 = V_158 ;
for ( V_124 = 0 ; V_124 < 4 ; V_124 ++ ) {
int V_159 ;
if ( ! V_38 [ V_124 ] . V_73 )
continue;
if ( ! ( V_38 [ V_124 ] . V_55 & V_151 ) ) {
V_156 = 1 ;
break;
}
if ( V_38 [ V_124 ] . V_55 & V_160 )
V_159 = V_161 ;
else
V_159 = V_162 ;
if ( V_38 [ V_124 ] . V_55 & V_163 )
V_159 ++ ;
V_153 = V_2 -> V_42 . V_164 [ V_41 ] [ V_159 ] [ V_38 [ V_124 ] . V_150 ] ;
V_152 = F_82 ( V_152 , V_153 ) ;
}
if ( V_27 -> V_55 & V_144 || V_156 )
return 0 ;
V_154 = F_82 ( V_152 , ( V_98 ) V_158 ) ;
V_155 = F_83 ( V_2 , V_152 ) ;
if ( V_155 )
V_154 = V_155 ;
if ( V_6 -> V_13 -> V_165 )
V_154 = F_82 ( V_154 , V_6 -> V_13 -> V_165 ) ;
return V_154 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 , T_1 V_153 ,
bool V_166 )
{
#define F_85 60
V_98 V_167 , V_168 ;
T_1 V_169 ;
T_2 V_55 , V_170 ;
int V_171 , V_172 , V_173 , V_174 , V_175 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_174 = F_86 ( V_153 ) ;
if ( ( V_40 -> V_176 != V_177 ) &&
! ( V_2 -> V_90 -> V_91 . V_178 & V_179 ) )
V_174 += V_180 ;
if ( V_166 && ! F_87 ( V_2 -> V_90 ) &&
( V_2 -> V_90 -> V_181 & V_182 ) )
V_174 = F_88 ( V_174 , F_85 ) ;
if ( V_6 -> V_13 -> V_183 == 0 )
return V_174 ;
V_170 = V_36 -> V_38 [ 0 ] . V_150 ;
V_55 = V_36 -> V_38 [ 0 ] . V_55 ;
V_171 = ( V_55 & V_160 ) ? 1 : 0 ;
V_173 = ( V_55 & V_163 ) ? 1 : 0 ;
if ( V_173 )
V_168 = F_89 ( V_6 -> V_13 -> V_183 ) ;
else
V_168 = F_90 ( V_6 -> V_13 -> V_183 ) ;
if ( V_168 == 0 )
V_168 = 1 ;
V_172 = F_91 ( V_170 ) ;
V_167 = V_184 [ V_170 % 8 ] [ V_171 ] * V_172 ;
V_169 = ( V_168 * V_167 ) / V_185 ;
if ( V_153 < V_169 ) {
V_175 = ( V_169 - V_153 ) / V_186 ;
V_174 = F_88 ( V_175 , V_174 ) ;
}
return V_174 ;
}
static struct V_35 *
F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_110 * * V_41 )
{
struct V_26 * V_27 ;
struct V_23 * V_40 ;
struct V_24 * V_25 ;
struct V_35 * V_36 ;
T_1 V_29 ;
while ( 1 ) {
* V_41 = & V_6 -> V_53 ;
if ( F_22 ( * V_41 ) )
* V_41 = & V_6 -> V_52 ;
V_25 = F_93 ( * V_41 ) ;
if ( ! V_25 )
break;
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_40 -> V_36 )
V_36 = F_27 ( V_2 , V_4 , V_6 , V_25 ) ;
else
V_36 -> V_62 . V_93 = false ;
if ( ! V_36 ) {
F_28 ( V_25 , * V_41 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
F_29 ( V_2 -> V_47 , V_25 ) ;
continue;
}
V_36 -> V_105 = NULL ;
V_36 -> V_109 = V_36 ;
V_27 = F_8 ( V_25 ) ;
V_27 -> V_55 &= ~ V_187 ;
if ( ! V_6 -> V_134 )
V_27 -> V_55 &= ~ V_56 ;
if ( ! ( V_27 -> V_55 & V_56 ) ) {
V_36 -> V_62 . V_188 = 0 ;
return V_36 ;
}
V_36 -> V_62 . V_188 = V_189 | V_190 ;
V_29 = V_36 -> V_62 . V_29 ;
if ( ! F_65 ( V_6 -> V_63 , V_6 -> V_133 , V_29 ) )
break;
if ( V_6 -> V_71 > F_34 ( V_6 -> V_63 , V_29 ) ) {
struct V_58 V_59 = {} ;
struct V_9 V_57 ;
F_31 ( & V_57 ) ;
F_94 ( & V_36 -> V_10 , & V_57 ) ;
F_28 ( V_25 , * V_41 ) ;
F_32 ( V_2 , V_6 , V_29 ) ;
F_33 ( V_2 , V_36 , V_4 , & V_57 , & V_59 , 0 ) ;
continue;
}
return V_36 ;
}
return NULL ;
}
static bool
F_95 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_9 * V_106 ,
struct V_35 * V_191 , struct V_110 * V_20 ,
int * V_192 )
{
#define F_96 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_35 * V_36 = V_191 , * V_193 = NULL ;
int V_95 = 0 , V_174 ;
T_1 V_154 = 0 , V_194 = 0 , V_195 = 0 ,
V_196 , V_197 = V_6 -> V_133 / 2 ;
struct V_26 * V_27 ;
struct V_23 * V_40 ;
struct V_24 * V_25 ;
bool V_198 = false ;
V_36 = V_191 ;
V_154 = F_81 ( V_2 , V_36 , V_6 ) ;
do {
V_25 = V_36 -> V_37 ;
V_40 = F_7 ( V_25 ) ;
V_196 = V_186 + V_40 -> V_199 ;
if ( V_95 ) {
if ( V_154 < V_194 + V_195 + V_196 ||
F_80 ( V_36 ) || V_95 >= V_197 )
break;
V_27 = F_8 ( V_36 -> V_37 ) ;
if ( ( V_27 -> V_55 & V_144 ) ||
! ( V_27 -> V_55 & V_56 ) )
break;
}
V_194 += V_195 + V_196 ;
V_174 = F_84 ( V_2 , V_6 , V_191 , V_40 -> V_199 ,
! V_95 ) ;
V_195 = F_96 ( V_196 ) + ( V_174 << 2 ) ;
V_95 ++ ;
V_36 -> V_105 = NULL ;
if ( ! V_40 -> V_61 )
F_38 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_62 . V_174 = V_174 ;
F_28 ( V_25 , V_20 ) ;
F_5 ( & V_36 -> V_10 , V_106 ) ;
if ( V_193 )
V_193 -> V_105 = V_36 ;
V_193 = V_36 ;
V_36 = F_92 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 ) {
V_198 = true ;
break;
}
} while ( F_21 ( V_6 ) );
V_36 = V_191 ;
V_36 -> V_109 = V_193 ;
if ( V_36 == V_193 ) {
V_194 = F_7 ( V_36 -> V_37 ) -> V_199 ;
V_36 -> V_62 . V_188 = V_189 ;
} else {
F_43 ( V_4 -> V_78 , V_200 ) ;
}
* V_192 = V_194 ;
return V_198 ;
#undef F_96
}
static V_98 F_97 ( struct V_1 * V_2 , T_2 V_170 , int V_201 ,
int V_171 , int V_173 , bool V_202 )
{
V_98 V_203 , V_167 , V_149 , V_168 ;
int V_172 ;
V_172 = F_91 ( V_170 ) ;
V_203 = ( V_201 << 3 ) + V_204 ;
V_167 = V_184 [ V_170 % 8 ] [ V_171 ] * V_172 ;
V_168 = ( V_203 + V_167 - 1 ) / V_167 ;
if ( ! V_173 )
V_149 = F_98 ( V_168 ) ;
else
V_149 = F_99 ( V_168 ) ;
V_149 += V_205 + V_206 + V_207 + V_208 + V_209 + F_100 ( V_172 ) ;
return V_149 ;
}
static int F_101 ( int V_210 , int V_211 , bool V_212 , bool V_213 )
{
int V_172 = F_91 ( V_211 ) ;
int V_214 , V_215 ;
int V_216 = 0 ;
V_210 -= V_205 + V_206 + V_207 + V_208 + V_209 + F_100 ( V_172 ) ;
V_214 = V_213 ? F_102 ( V_210 ) : F_103 ( V_210 ) ;
V_215 = V_214 * V_184 [ V_211 % 8 ] [ V_212 ] * V_172 ;
V_215 -= V_204 ;
V_216 = V_215 / 8 ;
if ( V_216 > 65532 )
V_216 = 65532 ;
return V_216 ;
}
void F_104 ( struct V_1 * V_2 , int V_217 , int V_218 )
{
T_1 * V_219 , * V_220 , * V_221 , * V_222 ;
int V_211 ;
if ( ! V_218 || V_218 > 4096 )
V_218 = 4096 ;
V_219 = V_2 -> V_42 . V_164 [ V_217 ] [ V_162 ] ;
V_220 = V_2 -> V_42 . V_164 [ V_217 ] [ V_223 ] ;
V_221 = V_2 -> V_42 . V_164 [ V_217 ] [ V_161 ] ;
V_222 = V_2 -> V_42 . V_164 [ V_217 ] [ V_224 ] ;
for ( V_211 = 0 ; V_211 < 32 ; V_211 ++ ) {
V_219 [ V_211 ] = F_101 ( V_218 , V_211 , false , false ) ;
V_220 [ V_211 ] = F_101 ( V_218 , V_211 , false , true ) ;
V_221 [ V_211 ] = F_101 ( V_218 , V_211 , true , false ) ;
V_222 [ V_211 ] = F_101 ( V_218 , V_211 , true , true ) ;
}
}
static void F_105 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_225 * V_39 , int V_226 , bool V_227 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_230 * V_231 = F_106 ( V_229 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_120 * V_38 ;
const struct V_232 * V_233 ;
struct V_74 * V_75 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_98 V_234 = V_2 -> V_47 -> V_235 -> V_236 ;
int V_124 ;
T_2 V_170 = 0 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_39 -> V_237 = ! F_107 ( V_75 -> V_81 ) ;
V_39 -> V_238 = V_40 -> V_238 ;
for ( V_124 = 0 ; V_124 < F_14 ( V_36 -> V_38 ) ; V_124 ++ ) {
bool V_239 , V_240 , V_241 ;
int V_242 ;
if ( ! V_38 [ V_124 ] . V_73 || ( V_38 [ V_124 ] . V_150 < 0 ) )
continue;
V_170 = V_38 [ V_124 ] . V_150 ;
V_39 -> V_38 [ V_124 ] . V_243 = V_38 [ V_124 ] . V_73 ;
if ( F_76 ( V_36 ) && ! F_57 ( V_36 ) &&
( V_38 [ V_124 ] . V_55 & V_151 ) &&
F_48 ( V_234 != ( V_98 ) - 1 ) ) {
if ( ! V_234 || ( V_226 > V_234 ) )
V_227 = true ;
}
if ( V_227 || V_38 [ V_124 ] . V_55 & V_244 ) {
V_39 -> V_38 [ V_124 ] . V_245 |= V_246 ;
V_39 -> V_55 |= V_247 ;
} else if ( V_38 [ V_124 ] . V_55 & V_248 ) {
V_39 -> V_38 [ V_124 ] . V_245 |= V_246 ;
V_39 -> V_55 |= V_249 ;
}
if ( V_38 [ V_124 ] . V_55 & V_160 )
V_39 -> V_38 [ V_124 ] . V_245 |= V_250 ;
if ( V_38 [ V_124 ] . V_55 & V_163 )
V_39 -> V_38 [ V_124 ] . V_245 |= V_251 ;
V_240 = ! ! ( V_38 [ V_124 ] . V_55 & V_163 ) ;
V_239 = ! ! ( V_38 [ V_124 ] . V_55 & V_160 ) ;
V_241 = ! ! ( V_38 [ V_124 ] . V_55 & V_252 ) ;
if ( V_38 [ V_124 ] . V_55 & V_151 ) {
V_39 -> V_38 [ V_124 ] . V_253 = V_170 | 0x80 ;
V_39 -> V_38 [ V_124 ] . V_254 = F_108 ( V_2 ,
V_229 -> V_255 , V_39 -> V_38 [ V_124 ] . V_253 ) ;
V_39 -> V_38 [ V_124 ] . V_256 = F_97 ( V_2 , V_170 , V_226 ,
V_239 , V_240 , V_241 ) ;
if ( V_170 < 8 && ( V_27 -> V_55 & V_257 ) )
V_39 -> V_38 [ V_124 ] . V_245 |= V_258 ;
continue;
}
V_233 = & V_231 -> V_259 [ V_27 -> V_260 ] . V_261 [ V_38 [ V_124 ] . V_150 ] ;
if ( ( V_27 -> V_260 == V_262 ) &&
! ( V_233 -> V_55 & V_263 ) )
V_242 = V_264 ;
else
V_242 = V_265 ;
V_39 -> V_38 [ V_124 ] . V_253 = V_233 -> V_266 ;
if ( V_233 -> V_267 ) {
if ( V_38 [ V_124 ] . V_55 & V_252 )
V_39 -> V_38 [ V_124 ] . V_253 |= V_233 -> V_267 ;
} else {
V_241 = false ;
}
if ( V_36 -> V_62 . V_268 )
V_39 -> V_38 [ V_124 ] . V_254 = V_229 -> V_255 ;
else
V_39 -> V_38 [ V_124 ] . V_254 = F_108 ( V_2 ,
V_229 -> V_255 , V_39 -> V_38 [ V_124 ] . V_253 ) ;
V_39 -> V_38 [ V_124 ] . V_256 = F_109 ( V_2 -> V_90 ,
V_242 , V_233 -> V_269 * 100 , V_226 , V_170 , V_241 ) ;
}
if ( F_57 ( V_36 ) && ( V_226 > V_2 -> V_90 -> V_91 . V_270 ) )
V_39 -> V_55 &= ~ V_247 ;
if ( V_39 -> V_55 & V_247 )
V_39 -> V_55 &= ~ V_249 ;
}
static enum V_271 F_110 ( struct V_24 * V_25 )
{
struct V_74 * V_75 ;
enum V_271 V_272 ;
T_4 V_273 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_273 = V_75 -> V_81 ;
if ( F_111 ( V_273 ) )
V_272 = V_274 ;
else if ( F_112 ( V_273 ) )
V_272 = V_275 ;
else if ( F_113 ( V_273 ) )
V_272 = V_276 ;
else if ( F_107 ( V_273 ) )
V_272 = V_277 ;
else
V_272 = V_278 ;
return V_272 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , int V_226 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_35 * V_191 = NULL ;
struct V_225 V_39 ;
V_98 V_234 = V_2 -> V_47 -> V_235 -> V_236 ;
bool V_227 = false ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_279 = true ;
V_39 . V_280 = true ;
V_39 . V_281 = V_282 ;
V_39 . V_283 = V_4 -> V_78 ;
while ( V_36 ) {
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
bool V_284 = ! ! ( V_36 -> V_62 . V_188 & V_190 ) ;
V_39 . type = F_110 ( V_25 ) ;
if ( V_36 -> V_105 )
V_39 . V_285 = V_36 -> V_105 -> V_286 ;
else
V_39 . V_285 = ( V_2 -> V_287 ) ? V_36 -> V_286 : 0 ;
if ( ! V_191 ) {
V_191 = V_36 ;
if ( ! V_2 -> V_287 )
V_39 . V_55 = V_288 ;
if ( ( V_27 -> V_55 & V_187 ) ||
V_4 == V_2 -> V_42 . V_289 )
V_39 . V_55 |= V_290 ;
if ( V_27 -> V_55 & V_291 )
V_39 . V_55 |= V_292 ;
if ( V_27 -> V_55 & V_293 )
V_39 . V_55 |= V_294 ;
if ( V_36 -> V_62 . V_268 )
V_39 . V_55 |= ( V_98 ) V_36 -> V_62 . V_268 <<
V_295 ;
if ( V_284 && ( V_36 == V_191 ) &&
F_48 ( V_234 != ( V_98 ) - 1 ) ) {
if ( ! V_234 || ( V_226 > V_234 ) )
V_227 = true ;
}
if ( ! V_284 )
V_226 = V_40 -> V_199 ;
F_105 ( V_2 , V_36 , & V_39 , V_226 , V_227 ) ;
}
V_39 . V_296 [ 0 ] = V_36 -> V_84 ;
V_39 . V_297 [ 0 ] = V_25 -> V_226 ;
V_39 . V_298 = V_40 -> V_199 ;
V_39 . V_176 = V_40 -> V_176 ;
V_39 . V_299 = V_40 -> V_299 ;
if ( V_284 ) {
if ( V_36 == V_191 )
V_39 . V_284 = V_300 ;
else if ( V_36 == V_191 -> V_109 )
V_39 . V_284 = V_301 ;
else
V_39 . V_284 = V_302 ;
V_39 . V_174 = V_36 -> V_62 . V_174 ;
V_39 . V_192 = V_226 ;
}
if ( V_36 == V_191 -> V_109 )
V_191 = NULL ;
F_115 ( V_229 , V_36 -> V_89 , & V_39 ) ;
V_36 = V_36 -> V_105 ;
}
}
static void
F_116 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_9 * V_106 ,
struct V_35 * V_191 , struct V_110 * V_20 )
{
struct V_35 * V_36 = V_191 , * V_193 = NULL ;
struct V_24 * V_25 ;
int V_95 = 0 ;
do {
struct V_26 * V_27 ;
V_25 = V_36 -> V_37 ;
V_95 ++ ;
F_28 ( V_25 , V_20 ) ;
F_5 ( & V_36 -> V_10 , V_106 ) ;
if ( V_193 )
V_193 -> V_105 = V_36 ;
V_193 = V_36 ;
if ( V_95 >= 2 )
break;
V_36 = F_92 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
V_27 = F_8 ( V_36 -> V_37 ) ;
if ( V_27 -> V_55 & V_56 )
break;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
} while ( 1 );
}
static bool F_117 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_303 )
{
struct V_35 * V_36 ;
struct V_26 * V_27 ;
struct V_110 * V_20 ;
struct V_9 V_106 ;
int V_192 = 0 ;
bool V_284 , V_304 = true ;
if ( ! F_21 ( V_6 ) )
return false ;
F_31 ( & V_106 ) ;
V_36 = F_92 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
return false ;
V_27 = F_8 ( V_36 -> V_37 ) ;
V_284 = ! ! ( V_27 -> V_55 & V_56 ) ;
if ( ( V_284 && V_4 -> V_148 >= V_305 ) ||
( ! V_284 && V_4 -> V_147 >= V_306 ) ) {
* V_303 = true ;
return false ;
}
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( V_284 )
V_304 = F_95 ( V_2 , V_4 , V_6 , & V_106 , V_36 ,
V_20 , & V_192 ) ;
else
F_116 ( V_2 , V_4 , V_6 , & V_106 , V_36 , V_20 ) ;
if ( F_49 ( & V_106 ) )
return false ;
if ( V_6 -> V_8 -> V_141 || V_6 -> V_13 -> V_307 ) {
V_6 -> V_8 -> V_141 = false ;
V_27 -> V_55 |= V_187 ;
}
F_114 ( V_2 , V_36 , V_4 , V_192 ) ;
F_118 ( V_2 , V_4 , & V_106 , false ) ;
return true ;
}
int F_119 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_6 , T_1 * V_308 )
{
struct V_5 * V_309 ;
struct V_3 * V_4 ;
struct V_49 * V_13 ;
T_2 V_310 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_309 = F_20 ( V_13 , V_6 ) ;
V_4 = V_309 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_30 -> V_311 . V_312 ) {
V_13 -> V_165 = ( 1 << ( V_313 +
V_30 -> V_311 . V_314 ) ) - 1 ;
V_310 = F_120 ( V_30 -> V_311 . V_315 ) ;
V_13 -> V_183 = V_310 ;
}
F_25 ( V_2 , V_309 ) ;
V_309 -> V_134 = true ;
* V_308 = V_309 -> V_63 = V_309 -> V_316 ;
V_309 -> V_71 = - 1 ;
memset ( V_309 -> V_68 , 0 , sizeof( V_309 -> V_68 ) ) ;
V_309 -> V_66 = V_309 -> V_69 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_121 ( struct V_1 * V_2 , struct V_34 * V_30 , T_1 V_6 )
{
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_5 * V_309 = F_20 ( V_13 , V_6 ) ;
struct V_3 * V_4 = V_309 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_309 -> V_134 = false ;
F_30 ( V_2 , V_309 ) ;
F_25 ( V_2 , V_309 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_122 ( struct V_34 * V_30 , struct V_1 * V_2 ,
struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_317 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_318 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_19 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_317 = F_21 ( V_6 ) ;
V_6 -> V_19 = false ;
F_52 ( & V_6 -> V_10 ) ;
if ( V_8 -> V_19 ) {
V_8 -> V_19 = false ;
F_52 ( & V_8 -> V_10 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_71 ( V_30 , V_22 , V_317 ) ;
}
}
void F_123 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_318 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_141 = true ;
if ( F_21 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_124 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_22 )
{
struct V_5 * V_6 ;
struct V_49 * V_13 ;
struct V_3 * V_4 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_6 = F_20 ( V_13 , V_22 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_133 = V_319 << V_30 -> V_311 . V_314 ;
if ( F_21 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_125 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
T_1 V_320 , int V_95 ,
enum V_321 V_322 ,
bool V_323 )
{
struct V_1 * V_2 = V_47 -> V_324 ;
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_3 * V_4 = V_2 -> V_42 . V_289 ;
struct V_26 * V_39 ;
struct V_9 V_106 ;
struct V_35 * V_325 = NULL , * V_36 ;
struct V_110 * V_20 ;
int V_326 = 0 ;
int V_124 ;
F_31 ( & V_106 ) ;
for ( V_124 = 0 ; V_320 && V_95 ; V_124 ++ , V_320 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_320 & 1 ) )
continue;
V_6 = F_20 ( V_13 , V_124 ) ;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_95 > 0 ) {
V_36 = F_92 ( V_2 , V_2 -> V_42 . V_289 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
F_28 ( V_36 -> V_37 , V_20 ) ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( F_76 ( V_36 ) ) {
F_38 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_62 . V_188 &= ~ V_190 ;
}
if ( V_325 )
V_325 -> V_105 = V_36 ;
V_325 = V_36 ;
V_95 -- ;
V_326 ++ ;
F_43 ( V_4 -> V_78 , V_327 ) ;
if ( V_13 -> V_30 && ! F_21 ( V_6 ) )
F_71 ( V_13 -> V_30 , V_124 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_49 ( & V_106 ) )
return;
V_39 = F_8 ( V_325 -> V_37 ) ;
V_39 -> V_55 |= V_138 ;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
F_1 ( V_2 , V_4 ) ;
F_114 ( V_2 , V_36 , V_4 , 0 ) ;
F_118 ( V_2 , V_4 , & V_106 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_126 ( struct V_1 * V_2 , int V_328 , int V_329 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_330 V_331 ;
static const int V_332 [] = {
[ V_333 ] = V_334 ,
[ V_335 ] = V_336 ,
[ V_337 ] = V_338 ,
[ V_339 ] = V_340 ,
} ;
int V_78 , V_124 ;
memset ( & V_331 , 0 , sizeof( V_331 ) ) ;
V_331 . V_341 = V_332 [ V_329 ] ;
V_331 . V_342 = V_343 ;
V_331 . V_344 = V_343 ;
V_331 . V_345 = V_343 ;
V_331 . V_346 = 0 ;
if ( V_229 -> V_91 . V_178 & V_179 ) {
V_331 . V_347 = V_348 ;
} else {
if ( V_328 == V_349 )
V_331 . V_347 = V_350 ;
else
V_331 . V_347 = V_351 |
V_350 ;
}
V_78 = F_127 ( V_229 , V_328 , & V_331 ) ;
if ( V_78 == - 1 ) {
return NULL ;
}
if ( ! F_128 ( V_2 , V_78 ) ) {
struct V_3 * V_4 = & V_2 -> V_42 . V_4 [ V_78 ] ;
V_4 -> V_78 = V_78 ;
V_4 -> V_157 = - 1 ;
V_4 -> V_352 = NULL ;
F_64 ( & V_4 -> V_353 ) ;
F_31 ( & V_4 -> V_354 ) ;
F_129 ( & V_4 -> V_355 ) ;
V_4 -> V_147 = 0 ;
V_4 -> V_148 = 0 ;
V_4 -> V_146 = false ;
V_2 -> V_42 . V_356 |= 1 << V_78 ;
V_4 -> V_357 = V_4 -> V_358 = 0 ;
for ( V_124 = 0 ; V_124 < V_359 ; V_124 ++ )
F_31 ( & V_4 -> V_360 [ V_124 ] ) ;
}
return & V_2 -> V_42 . V_4 [ V_78 ] ;
}
int F_130 ( struct V_1 * V_2 , int V_361 ,
struct V_330 * V_362 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
int error = 0 ;
struct V_330 V_331 ;
F_131 ( V_2 -> V_42 . V_4 [ V_361 ] . V_78 != V_361 ) ;
F_132 ( V_229 , V_361 , & V_331 ) ;
V_331 . V_342 = V_362 -> V_342 ;
V_331 . V_344 = V_362 -> V_344 ;
V_331 . V_345 = V_362 -> V_345 ;
V_331 . V_363 = V_362 -> V_363 ;
V_331 . V_364 = V_362 -> V_364 ;
if ( ! F_133 ( V_229 , V_361 , & V_331 ) ) {
F_134 ( F_106 ( V_2 -> V_90 ) ,
L_1 , V_361 ) ;
error = - V_365 ;
} else {
F_135 ( V_229 , V_361 ) ;
}
return error ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_330 V_331 ;
struct V_366 * V_367 = & V_2 -> V_368 -> V_369 ;
int V_361 = V_2 -> V_369 . V_370 -> V_78 ;
F_132 ( V_2 -> V_90 , V_361 , & V_331 ) ;
V_331 . V_364 = ( F_137 ( V_367 -> V_371 ) *
V_372 ) / 100 ;
F_130 ( V_2 , V_361 , & V_331 ) ;
return 0 ;
}
static void F_138 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_35 * V_36 , * V_373 ;
struct V_9 V_57 ;
struct V_58 V_59 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_122 = V_123 ;
F_31 ( & V_57 ) ;
while ( ! F_49 ( V_10 ) ) {
V_36 = F_51 ( V_10 , struct V_35 , V_10 ) ;
if ( V_36 -> V_62 . V_93 ) {
F_52 ( & V_36 -> V_10 ) ;
F_53 ( V_2 , V_36 ) ;
continue;
}
V_373 = V_36 -> V_109 ;
F_139 ( & V_57 , V_10 , & V_373 -> V_10 ) ;
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
}
void F_140 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 ) {
int V_150 = V_4 -> V_358 ;
while ( ! F_49 ( & V_4 -> V_360 [ V_150 ] ) ) {
F_138 ( V_2 , V_4 , & V_4 -> V_360 [ V_150 ] ) ;
F_37 ( V_150 , V_359 ) ;
}
V_4 -> V_358 = V_150 ;
}
V_4 -> V_352 = NULL ;
V_4 -> V_146 = false ;
F_138 ( V_2 , V_4 , & V_4 -> V_354 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_141 ( struct V_1 * V_2 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_3 * V_4 ;
int V_124 ;
V_98 V_374 = 0 ;
if ( F_36 ( V_375 , & V_231 -> V_376 ) )
return true ;
F_142 ( V_229 ) ;
for ( V_124 = 0 ; V_124 < V_377 ; V_124 ++ ) {
if ( ! F_128 ( V_2 , V_124 ) )
continue;
if ( ! V_2 -> V_42 . V_4 [ V_124 ] . V_147 )
continue;
if ( F_143 ( V_229 , V_2 -> V_42 . V_4 [ V_124 ] . V_78 ) )
V_374 |= F_144 ( V_124 ) ;
}
if ( V_374 )
F_134 ( V_231 , L_2 , V_374 ) ;
for ( V_124 = 0 ; V_124 < V_377 ; V_124 ++ ) {
if ( ! F_128 ( V_2 , V_124 ) )
continue;
V_4 = & V_2 -> V_42 . V_4 [ V_124 ] ;
V_4 -> V_45 = false ;
F_140 ( V_2 , V_4 ) ;
}
return ! V_374 ;
}
void F_145 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_146 ( V_2 -> V_90 , V_4 -> V_78 ) ;
V_2 -> V_42 . V_356 &= ~ ( 1 << V_4 -> V_78 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_7 * V_8 , * V_378 ;
struct V_5 * V_6 , * V_379 ;
struct V_9 * V_380 ;
bool V_326 = false ;
if ( V_4 -> V_157 < 0 )
return;
if ( F_36 ( V_381 , & V_231 -> V_376 ) )
return;
F_47 ( & V_2 -> V_382 ) ;
V_380 = & V_2 -> V_368 -> V_21 [ V_4 -> V_157 ] ;
if ( F_49 ( V_380 ) ) {
F_50 ( & V_2 -> V_382 ) ;
return;
}
F_60 () ;
V_378 = F_147 ( V_380 -> V_76 , struct V_7 , V_10 ) ;
while ( ! F_49 ( V_380 ) ) {
bool V_303 = false ;
if ( V_2 -> V_368 -> V_45 )
break;
V_8 = F_51 ( V_380 , struct V_7 , V_10 ) ;
V_379 = F_147 ( V_8 -> V_20 . V_76 , struct V_5 , V_10 ) ;
F_52 ( & V_8 -> V_10 ) ;
V_8 -> V_19 = false ;
while ( ! F_49 ( & V_8 -> V_20 ) ) {
V_6 = F_51 ( & V_8 -> V_20 , struct V_5 ,
V_10 ) ;
F_52 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
if ( F_117 ( V_2 , V_4 , V_6 , & V_303 ) )
V_326 = true ;
if ( F_21 ( V_6 ) )
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_303 || V_6 == V_379 )
break;
}
if ( ! F_49 ( & V_8 -> V_20 ) && ! V_8 -> V_19 ) {
V_8 -> V_19 = true ;
F_5 ( & V_8 -> V_10 , V_380 ) ;
}
if ( V_303 )
break;
if ( V_8 == V_378 ) {
if ( ! V_326 )
break;
V_326 = false ;
V_378 = F_147 ( V_380 -> V_76 ,
struct V_7 , V_10 ) ;
}
}
F_62 () ;
F_50 ( & V_2 -> V_382 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_383 ; V_124 ++ ) {
V_4 = V_2 -> V_42 . V_43 [ V_124 ] ;
F_47 ( & V_4 -> V_355 ) ;
F_79 ( V_2 , V_4 ) ;
F_50 ( & V_4 -> V_355 ) ;
}
}
static void F_118 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_384 , bool V_385 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_230 * V_231 = F_106 ( V_229 ) ;
struct V_35 * V_36 , * V_108 ;
bool V_386 = false ;
bool V_387 ;
if ( F_49 ( V_384 ) )
return;
V_387 = ! ! ( V_229 -> V_91 . V_178 & V_179 ) ;
V_36 = F_51 ( V_384 , struct V_35 , V_10 ) ;
V_108 = F_147 ( V_384 -> V_76 , struct V_35 , V_10 ) ;
F_149 ( V_231 , V_388 , L_3 ,
V_4 -> V_78 , V_4 -> V_147 ) ;
if ( V_387 && F_49 ( & V_4 -> V_360 [ V_4 -> V_357 ] ) ) {
F_150 ( V_384 , & V_4 -> V_360 [ V_4 -> V_357 ] ) ;
F_37 ( V_4 -> V_357 , V_359 ) ;
V_386 = true ;
} else {
F_150 ( V_384 , & V_4 -> V_354 ) ;
if ( V_4 -> V_352 ) {
F_151 ( V_229 , V_4 -> V_352 , V_36 -> V_286 ) ;
F_149 ( V_231 , V_389 , L_4 ,
V_4 -> V_78 , V_4 -> V_352 ,
F_152 ( V_36 -> V_286 ) , V_36 -> V_89 ) ;
} else if ( ! V_387 )
V_386 = true ;
V_4 -> V_352 = V_108 -> V_89 ;
}
if ( V_386 ) {
F_43 ( V_4 -> V_78 , V_386 ) ;
F_153 ( V_229 , V_4 -> V_78 , V_36 -> V_286 ) ;
F_149 ( V_231 , V_389 , L_5 ,
V_4 -> V_78 , F_152 ( V_36 -> V_286 ) , V_36 -> V_89 ) ;
}
if ( ! V_387 || V_2 -> V_287 ) {
F_43 ( V_4 -> V_78 , V_390 ) ;
F_154 ( V_229 , V_4 -> V_78 ) ;
}
if ( ! V_385 ) {
while ( V_36 ) {
V_4 -> V_147 ++ ;
if ( F_75 ( V_36 ) )
V_4 -> V_148 ++ ;
V_108 = V_36 -> V_109 ;
V_36 = V_108 -> V_105 ;
V_108 -> V_105 = NULL ;
}
}
}
static void F_155 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_24 * V_25 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_9 V_57 ;
struct V_35 * V_36 = V_40 -> V_36 ;
F_31 ( & V_57 ) ;
F_5 ( & V_36 -> V_10 , & V_57 ) ;
V_36 -> V_62 . V_188 = 0 ;
if ( V_6 && ( V_27 -> V_55 & V_56 ) ) {
V_36 -> V_62 . V_188 = V_189 ;
F_38 ( V_2 , V_6 , V_36 ) ;
}
V_36 -> V_105 = NULL ;
V_36 -> V_109 = V_36 ;
F_114 ( V_2 , V_36 , V_4 , V_40 -> V_199 ) ;
F_118 ( V_2 , V_4 , & V_57 , false ) ;
F_43 ( V_4 -> V_78 , V_391 ) ;
}
static void F_156 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
struct V_24 * V_25 ,
int V_199 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_392 * V_393 = V_27 -> V_137 . V_393 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
const struct V_232 * V_233 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_49 * V_13 = NULL ;
enum V_394 V_299 ;
bool V_395 = false ;
if ( V_27 -> V_137 . V_14 &&
V_27 -> V_137 . V_14 -> V_396 . V_397 )
V_395 = true ;
V_233 = F_157 ( V_47 , V_27 ) ;
V_299 = F_158 ( V_25 ) ;
if ( V_30 )
V_13 = (struct V_49 * ) V_30 -> V_15 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_4 = - 1 ;
if ( V_393 )
V_40 -> V_176 = V_393 -> V_398 ;
else if ( V_13 && F_159 ( V_75 -> V_81 ) && V_13 -> V_399 > 0 )
V_40 -> V_176 = V_13 -> V_399 ;
else
V_40 -> V_176 = V_177 ;
V_40 -> V_299 = V_299 ;
V_40 -> V_199 = V_199 ;
if ( ! V_233 )
return;
V_40 -> V_238 = V_233 -> V_266 ;
if ( V_395 )
V_40 -> V_238 |= V_233 -> V_267 ;
}
T_2 F_108 ( struct V_1 * V_2 , T_2 V_400 , V_98 V_233 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_401 * V_402 = V_229 -> V_402 ;
if ( ( V_229 -> V_91 . V_178 & V_403 ) && F_160 ( V_402 ) &&
( V_400 == 0x7 ) && ( V_233 < 0x90 ) )
return 0x3 ;
else if ( F_161 ( V_229 ) && F_162 ( V_229 ) &&
F_163 ( V_233 ) )
return 0x2 ;
else
return V_400 ;
}
static struct V_35 * F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_35 * V_36 ;
int V_404 ;
T_1 V_29 ;
V_36 = F_46 ( V_2 ) ;
if ( ! V_36 ) {
F_149 ( V_231 , V_389 , L_6 ) ;
return NULL ;
}
F_55 ( V_36 ) ;
if ( V_6 && F_164 ( V_75 -> V_81 ) ) {
V_404 = F_165 ( V_75 -> V_405 ) & V_406 ;
V_29 = V_6 -> V_316 ;
V_75 -> V_405 = F_44 ( V_6 -> V_316 << V_32 ) ;
if ( V_404 )
V_75 -> V_405 |= F_44 ( V_404 ) ;
if ( ! F_166 ( V_75 -> V_81 ) )
F_37 ( V_6 -> V_316 , V_70 ) ;
V_36 -> V_62 . V_29 = V_29 ;
}
V_36 -> V_37 = V_25 ;
V_36 -> V_84 = F_167 ( V_2 -> V_83 , V_25 -> V_80 ,
V_25 -> V_226 , V_85 ) ;
if ( F_48 ( F_168 ( V_2 -> V_83 , V_36 -> V_84 ) ) ) {
V_36 -> V_37 = NULL ;
V_36 -> V_84 = 0 ;
F_134 ( F_106 ( V_2 -> V_90 ) ,
L_7 ) ;
F_53 ( V_2 , V_36 ) ;
return NULL ;
}
V_40 -> V_36 = V_36 ;
return V_36 ;
}
void F_169 ( struct V_230 * V_231 , struct V_24 * V_25 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
if ( ! ( V_39 -> V_55 & V_407 ) )
return;
if ( ! V_14 )
return;
V_12 = (struct V_11 * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_408 )
V_12 -> V_409 += 0x10 ;
V_75 -> V_405 &= F_44 ( V_406 ) ;
V_75 -> V_405 |= F_44 ( V_12 -> V_409 ) ;
}
static int F_170 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_410 * V_411 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_411 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_47 -> V_324 ;
int V_153 = V_25 -> V_226 + V_412 ;
int V_413 , V_414 ;
if ( V_30 )
V_411 -> V_13 = (struct V_49 * ) V_30 -> V_15 ;
else if ( V_14 && F_159 ( V_75 -> V_81 ) ) {
V_12 = ( void * ) V_14 -> V_15 ;
V_411 -> V_13 = & V_12 -> V_415 ;
}
if ( V_39 -> V_137 . V_393 )
V_153 += V_39 -> V_137 . V_393 -> V_416 ;
F_169 ( F_106 ( V_2 -> V_90 ) , V_25 ) ;
if ( ( V_14 && V_14 -> type != V_417 &&
V_14 -> type != V_418 ) ||
! F_159 ( V_75 -> V_81 ) )
V_39 -> V_55 |= V_187 ;
V_413 = F_171 ( V_75 -> V_81 ) ;
V_414 = V_413 & 3 ;
if ( V_414 && V_25 -> V_226 > V_413 ) {
if ( F_172 ( V_25 ) < V_414 )
return - V_419 ;
F_173 ( V_25 , V_414 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_414 , V_413 ) ;
}
F_156 ( V_47 , V_30 , V_25 , V_153 ) ;
return 0 ;
}
int F_174 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_410 * V_411 )
{
struct V_74 * V_75 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_411 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_11 * V_12 = NULL ;
struct V_1 * V_2 = V_47 -> V_324 ;
struct V_3 * V_4 = V_411 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_36 ;
bool V_217 , V_420 = false ;
int V_41 , V_421 ;
if ( V_14 )
V_12 = ( void * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_422 )
V_411 -> V_423 = true ;
V_421 = F_170 ( V_47 , V_25 , V_411 ) ;
if ( V_421 )
return V_421 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_41 = F_175 ( V_25 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_42 . V_43 [ V_41 ] ) {
V_40 -> V_4 = V_41 ;
if ( ++ V_4 -> V_44 > V_2 -> V_42 . V_46 [ V_41 ] &&
! V_4 -> V_45 ) {
if ( F_17 () )
F_176 ( V_2 -> V_47 , V_39 -> V_48 ) ;
else
F_176 ( V_2 -> V_47 , V_41 ) ;
V_4 -> V_45 = true ;
}
}
V_217 = F_164 ( V_75 -> V_81 ) ;
if ( ( ( V_12 && V_12 -> V_18 != V_2 -> V_368 ) ||
V_2 -> V_368 -> V_45 ) && ! V_411 -> V_423 ) {
if ( ! V_411 -> V_13 )
V_411 -> V_13 = & V_12 -> V_415 ;
V_217 = true ;
V_420 = true ;
}
if ( V_411 -> V_13 && V_217 )
V_6 = F_19 ( V_2 , V_411 -> V_13 , V_25 ) ;
if ( ! V_420 && ( V_39 -> V_55 & V_424 ) ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_42 . V_289 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_411 -> V_13 && V_217 ) {
F_16 ( V_6 -> V_8 -> V_4 != V_411 -> V_4 ) ;
if ( V_39 -> V_55 & V_187 )
V_6 -> V_8 -> V_141 = true ;
F_43 ( V_4 -> V_78 , V_425 ) ;
F_70 ( & V_6 -> V_52 , V_25 ) ;
if ( ! V_411 -> V_13 -> V_136 )
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
goto V_426;
}
V_36 = F_27 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
if ( V_411 -> V_427 )
F_177 ( V_25 ) ;
else
F_29 ( V_2 -> V_47 , V_25 ) ;
goto V_426;
}
V_36 -> V_62 . V_268 = V_411 -> V_427 ;
if ( V_411 -> V_427 )
V_36 -> V_62 . V_428 = V_429 ;
F_12 ( V_14 , V_30 , V_36 ) ;
F_155 ( V_2 , V_4 , V_6 , V_25 ) ;
V_426:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_178 ( struct V_107 * V_47 , struct V_33 * V_14 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_47 -> V_324 ;
struct V_410 V_411 = {
. V_4 = V_2 -> V_369 . V_370
} ;
struct V_225 V_39 = {} ;
struct V_74 * V_75 ;
struct V_35 * V_325 = NULL ;
struct V_35 * V_36 ;
F_179 ( V_106 ) ;
int V_149 = 0 ;
int V_430 ;
V_430 =
V_2 -> V_368 -> V_369 . V_371 * 1000 *
V_2 -> V_368 -> V_369 . V_431 / V_432 ;
do {
struct V_23 * V_40 = F_7 ( V_25 ) ;
if ( F_170 ( V_47 , V_25 , & V_411 ) )
break;
V_36 = F_27 ( V_2 , V_411 . V_4 , NULL , V_25 ) ;
if ( ! V_36 )
break;
V_36 -> V_109 = V_36 ;
F_12 ( V_14 , NULL , V_36 ) ;
F_105 ( V_2 , V_36 , & V_39 , V_40 -> V_199 , false ) ;
V_149 += V_39 . V_38 [ 0 ] . V_256 ;
if ( V_325 )
V_325 -> V_105 = V_36 ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
V_325 = V_36 ;
V_25 = NULL ;
if ( V_149 > V_430 )
break;
V_25 = F_180 ( V_47 , V_14 ) ;
} while( V_25 );
if ( V_25 )
F_29 ( V_47 , V_25 ) ;
if ( F_49 ( & V_106 ) )
return;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
V_75 = (struct V_74 * ) V_36 -> V_37 -> V_80 ;
if ( V_75 -> V_81 & V_433 ) {
V_75 -> V_81 &= ~ V_433 ;
F_45 ( V_2 -> V_83 , V_36 -> V_84 ,
sizeof( * V_75 ) , V_85 ) ;
}
F_1 ( V_2 , V_411 . V_4 ) ;
F_114 ( V_2 , V_36 , V_411 . V_4 , 0 ) ;
F_118 ( V_2 , V_411 . V_4 , & V_106 , false ) ;
F_43 ( V_411 . V_4 -> V_78 , V_391 ) ;
F_2 ( V_2 , V_411 . V_4 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_24 * V_25 ,
int V_434 , struct V_3 * V_4 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
int V_413 , V_414 ;
unsigned long V_55 ;
F_149 ( V_231 , V_389 , L_8 , V_25 ) ;
if ( V_2 -> V_90 -> V_435 )
F_181 ( V_436 , & V_2 -> V_90 -> V_435 -> V_437 ) ;
if ( ! ( V_434 & V_72 ) )
V_27 -> V_55 |= V_438 ;
V_413 = F_171 ( V_75 -> V_81 ) ;
V_414 = V_413 & 3 ;
if ( V_414 && V_25 -> V_226 > V_413 + V_414 ) {
memmove ( V_25 -> V_80 + V_414 , V_25 -> V_80 , V_413 ) ;
F_182 ( V_25 , V_414 ) ;
}
F_183 ( & V_2 -> V_439 , V_55 ) ;
if ( ( V_2 -> V_440 & V_441 ) && ! V_4 -> V_147 ) {
V_2 -> V_440 &= ~ V_441 ;
F_149 ( V_231 , V_442 ,
L_9 ,
V_2 -> V_440 & ( V_443 |
V_444 |
V_445 |
V_441 ) ) ;
}
F_184 ( & V_2 -> V_439 , V_55 ) ;
F_70 ( & V_4 -> V_353 , V_25 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_9 * V_106 ,
struct V_58 * V_59 , int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
unsigned long V_55 ;
int V_434 = 0 ;
if ( ! V_94 )
V_434 |= V_72 ;
if ( V_59 -> V_122 & V_139 )
V_27 -> V_55 |= V_446 ;
F_185 ( V_2 -> V_83 , V_36 -> V_84 , V_25 -> V_226 , V_85 ) ;
V_36 -> V_84 = 0 ;
if ( V_2 -> V_287 )
goto V_447;
if ( V_36 -> V_62 . V_268 ) {
if ( F_186 ( V_429 ,
V_36 -> V_62 . V_428 +
F_187 ( V_448 ) ) )
F_177 ( V_25 ) ;
else
F_188 ( & V_2 -> V_449 ) ;
} else {
F_189 ( V_2 , V_36 , V_59 , V_4 , V_434 ) ;
F_41 ( V_2 , V_25 , V_434 , V_4 ) ;
}
V_447:
V_36 -> V_37 = NULL ;
F_183 ( & V_2 -> V_42 . V_86 , V_55 ) ;
F_150 ( V_106 , & V_2 -> V_42 . V_87 ) ;
F_184 ( & V_2 -> V_42 . V_86 , V_55 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_58 * V_59 , int V_95 , int V_96 ,
int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_107 * V_47 = V_2 -> V_47 ;
struct V_228 * V_229 = V_2 -> V_90 ;
T_2 V_124 , V_450 ;
if ( V_94 )
V_27 -> V_451 . V_452 = V_59 -> V_453 ;
V_450 = V_59 -> V_126 ;
F_16 ( V_450 >= V_47 -> V_454 ) ;
if ( V_27 -> V_55 & V_56 ) {
V_27 -> V_55 |= V_455 ;
F_131 ( V_96 > V_95 ) ;
}
V_27 -> V_451 . V_456 = V_95 ;
V_27 -> V_451 . V_457 = V_95 - V_96 ;
if ( ( V_59 -> V_122 & V_139 ) == 0 &&
( V_27 -> V_55 & V_291 ) == 0 ) {
if ( F_48 ( V_59 -> V_129 & ( V_458 |
V_459 ) ) &&
F_159 ( V_75 -> V_81 ) &&
V_229 -> V_460 >= V_2 -> V_90 -> V_461 . V_462 )
V_27 -> V_451 . V_38 [ V_450 ] . V_73 =
V_47 -> V_463 ;
}
for ( V_124 = V_450 + 1 ; V_124 < V_47 -> V_454 ; V_124 ++ ) {
V_27 -> V_451 . V_38 [ V_124 ] . V_73 = 0 ;
V_27 -> V_451 . V_38 [ V_124 ] . V_150 = - 1 ;
}
V_27 -> V_451 . V_38 [ V_450 ] . V_73 = V_59 -> V_125 + 1 ;
}
static void F_190 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_230 * V_231 = F_106 ( V_229 ) ;
struct V_35 * V_36 , * V_373 , * V_464 = NULL ;
struct V_9 V_57 ;
struct V_465 * V_466 ;
struct V_58 V_59 ;
int V_451 ;
F_149 ( V_231 , V_388 , L_10 ,
V_4 -> V_78 , F_191 ( V_2 -> V_90 , V_4 -> V_78 ) ,
V_4 -> V_352 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_36 ( V_381 , & V_231 -> V_376 ) )
break;
if ( F_49 ( & V_4 -> V_354 ) ) {
V_4 -> V_352 = NULL ;
F_79 ( V_2 , V_4 ) ;
break;
}
V_36 = F_51 ( & V_4 -> V_354 , struct V_35 , V_10 ) ;
V_464 = NULL ;
if ( V_36 -> V_62 . V_93 ) {
V_464 = V_36 ;
if ( F_192 ( & V_464 -> V_10 , & V_4 -> V_354 ) )
break;
V_36 = F_147 ( V_464 -> V_10 . V_467 , struct V_35 ,
V_10 ) ;
}
V_373 = V_36 -> V_109 ;
V_466 = V_373 -> V_89 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_451 = F_193 ( V_229 , V_466 , & V_59 ) ;
if ( V_451 == - V_468 )
break;
F_43 ( V_4 -> V_78 , V_469 ) ;
V_373 -> V_62 . V_93 = true ;
F_31 ( & V_57 ) ;
if ( ! F_194 ( & V_373 -> V_10 ) )
F_139 ( & V_57 ,
& V_4 -> V_354 , V_373 -> V_10 . V_76 ) ;
if ( V_464 ) {
F_52 ( & V_464 -> V_10 ) ;
F_53 ( V_2 , V_464 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_195 ( struct V_1 * V_2 )
{
struct V_228 * V_229 = V_2 -> V_90 ;
V_98 V_470 = ( ( 1 << V_377 ) - 1 ) & V_229 -> V_471 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_377 ; V_124 ++ ) {
if ( F_128 ( V_2 , V_124 ) && ( V_470 & ( 1 << V_124 ) ) )
F_190 ( V_2 , & V_2 -> V_42 . V_4 [ V_124 ] ) ;
}
}
void F_196 ( struct V_1 * V_2 )
{
struct V_58 V_59 ;
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_228 * V_229 = V_2 -> V_90 ;
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_373 ;
struct V_9 V_57 ;
struct V_9 * V_472 ;
int V_451 ;
for (; ; ) {
if ( F_36 ( V_381 , & V_231 -> V_376 ) )
break;
V_451 = F_193 ( V_229 , NULL , ( void * ) & V_59 ) ;
if ( V_451 == - V_468 )
break;
if ( V_451 == - V_365 ) {
F_149 ( V_231 , V_389 , L_11 ) ;
break;
}
if ( V_59 . V_473 == V_2 -> V_369 . V_474 ) {
V_2 -> V_369 . V_475 = true ;
V_2 -> V_369 . V_476 = ! ( V_59 . V_122 & V_145 ) ;
if ( F_17 () ) {
F_197 ( V_2 , NULL ,
V_477 ) ;
}
F_198 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_42 . V_4 [ V_59 . V_473 ] ;
F_1 ( V_2 , V_4 ) ;
F_43 ( V_4 -> V_78 , V_469 ) ;
V_472 = & V_4 -> V_360 [ V_4 -> V_358 ] ;
if ( F_49 ( V_472 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_36 = F_51 ( V_472 , struct V_35 , V_10 ) ;
if ( V_36 -> V_62 . V_93 ) {
F_52 ( & V_36 -> V_10 ) ;
F_53 ( V_2 , V_36 ) ;
V_36 = F_51 ( V_472 , struct V_35 , V_10 ) ;
}
V_373 = V_36 -> V_109 ;
F_31 ( & V_57 ) ;
if ( F_192 ( & V_373 -> V_10 , V_472 ) ) {
F_150 ( V_472 , & V_57 ) ;
F_37 ( V_4 -> V_358 , V_359 ) ;
if ( ! F_49 ( & V_4 -> V_354 ) ) {
struct V_9 V_106 ;
F_31 ( & V_106 ) ;
V_4 -> V_352 = NULL ;
F_150 ( & V_4 -> V_354 , & V_106 ) ;
F_118 ( V_2 , V_4 , & V_106 , true ) ;
}
} else {
V_373 -> V_62 . V_93 = true ;
if ( V_36 != V_373 )
F_139 ( & V_57 , V_472 ,
V_373 -> V_10 . V_76 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_199 ( struct V_1 * V_2 , int V_478 )
{
struct V_479 * V_480 = & V_2 -> V_481 ;
T_2 V_482 = V_2 -> V_90 -> V_91 . V_482 ;
V_480 -> V_483 = V_478 * V_482 ;
V_480 -> V_484 = F_200 ( V_2 -> V_83 , V_480 -> V_483 ,
& V_480 -> V_485 , V_486 ) ;
if ( ! V_480 -> V_484 )
return - V_419 ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_487 ;
V_487 = F_199 ( V_2 , V_488 ) ;
if ( ! V_487 )
F_202 ( V_2 -> V_90 , V_2 -> V_481 . V_484 ,
V_2 -> V_481 . V_485 ,
V_488 ) ;
return V_487 ;
}
int F_203 ( struct V_1 * V_2 , int V_489 )
{
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
int error = 0 ;
F_129 ( & V_2 -> V_42 . V_86 ) ;
error = F_204 ( V_2 , & V_2 -> V_42 . V_490 , & V_2 -> V_42 . V_87 ,
L_12 , V_489 , 1 , 1 ) ;
if ( error != 0 ) {
F_134 ( V_231 ,
L_13 , error ) ;
return error ;
}
error = F_204 ( V_2 , & V_2 -> V_369 . V_491 , & V_2 -> V_369 . V_492 ,
L_14 , V_432 , 1 , 1 ) ;
if ( error != 0 ) {
F_134 ( V_231 ,
L_15 , error ) ;
return error ;
}
F_205 ( & V_2 -> V_493 , V_494 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 )
error = F_201 ( V_2 ) ;
return error ;
}
void F_206 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_22 , V_495 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_318 ;
V_22 ++ , V_6 ++ ) {
V_6 -> V_13 = V_13 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_63 = V_6 -> V_316 = 0 ;
V_6 -> V_133 = V_496 ;
V_6 -> V_66 = V_6 -> V_69 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_134 = false ;
F_64 ( & V_6 -> V_52 ) ;
F_64 ( & V_6 -> V_53 ) ;
V_495 = F_6 ( V_22 ) ;
V_6 -> V_8 = & V_13 -> V_8 [ V_495 ] ;
}
for ( V_495 = 0 , V_8 = & V_13 -> V_8 [ V_495 ] ;
V_495 < V_383 ; V_495 ++ , V_8 ++ ) {
V_8 -> V_19 = false ;
V_8 -> V_141 = true ;
V_8 -> V_4 = V_2 -> V_42 . V_43 [ V_495 ] ;
F_31 ( & V_8 -> V_20 ) ;
}
}
void F_207 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_318 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_19 ) {
F_52 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
}
if ( V_8 -> V_19 ) {
F_52 ( & V_8 -> V_10 ) ;
V_6 -> V_8 -> V_19 = false ;
}
F_40 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_134 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
int F_208 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_410 * V_411 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_230 * V_231 = F_106 ( V_2 -> V_90 ) ;
struct V_35 * V_36 ;
int V_413 , V_414 ;
V_413 = F_171 ( V_75 -> V_81 ) ;
V_414 = V_413 & 3 ;
if ( V_414 && V_25 -> V_226 > V_413 ) {
if ( F_172 ( V_25 ) < V_414 ) {
F_149 ( V_231 , V_389 ,
L_16 ) ;
return - V_497 ;
}
F_173 ( V_25 , V_414 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_414 , V_413 ) ;
}
V_40 -> V_176 = V_177 ;
V_40 -> V_199 = V_25 -> V_226 + V_412 ;
V_40 -> V_299 = V_498 ;
V_36 = F_27 ( V_2 , V_411 -> V_4 , NULL , V_25 ) ;
if ( ! V_36 ) {
F_149 ( V_231 , V_389 , L_17 ) ;
return - V_497 ;
}
F_12 ( V_2 -> V_499 , NULL , V_36 ) ;
F_151 ( V_2 -> V_90 , V_36 -> V_89 , V_36 -> V_286 ) ;
F_209 ( V_2 -> V_90 , V_411 -> V_4 -> V_78 ) ;
F_155 ( V_2 , V_411 -> V_4 , NULL , V_25 ) ;
return 0 ;
}
