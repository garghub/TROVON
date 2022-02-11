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
static T_2 F_105 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_2 V_225 )
{
T_2 V_226 ;
struct V_227 * V_228 = V_2 -> V_90 ;
if ( V_2 -> V_229 )
return V_230 ;
if ( ! F_106 ( V_228 ) ) {
return V_230 ;
}
if ( ! V_36 -> V_62 . V_231 ) {
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
if ( V_225 < 8 && ( V_39 -> V_55 & V_232 ) )
V_226 = F_82 ( V_228 -> V_233 [ V_225 ] ,
V_40 -> V_234 ) ;
else
V_226 = F_82 ( V_228 -> V_234 [ V_225 ] , V_40 -> V_234 ) ;
} else {
V_226 = V_228 -> V_235 ;
}
return V_226 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_236 * V_39 , int V_237 , bool V_238 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_239 * V_240 = F_108 ( V_228 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_120 * V_38 ;
const struct V_241 * V_242 ;
struct V_74 * V_75 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_98 V_243 = V_2 -> V_47 -> V_244 -> V_245 ;
int V_124 ;
T_2 V_170 = 0 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_39 -> V_246 = ! F_109 ( V_75 -> V_81 ) ;
V_39 -> V_247 = V_40 -> V_247 ;
for ( V_124 = 0 ; V_124 < F_14 ( V_36 -> V_38 ) ; V_124 ++ ) {
bool V_248 , V_249 , V_250 ;
int V_251 ;
if ( ! V_38 [ V_124 ] . V_73 || ( V_38 [ V_124 ] . V_150 < 0 ) )
continue;
V_170 = V_38 [ V_124 ] . V_150 ;
V_39 -> V_38 [ V_124 ] . V_252 = V_38 [ V_124 ] . V_73 ;
if ( F_76 ( V_36 ) && ! F_57 ( V_36 ) &&
( V_38 [ V_124 ] . V_55 & V_151 ) &&
F_48 ( V_243 != ( V_98 ) - 1 ) ) {
if ( ! V_243 || ( V_237 > V_243 ) )
V_238 = true ;
}
if ( V_238 || V_38 [ V_124 ] . V_55 & V_253 ) {
V_39 -> V_38 [ V_124 ] . V_254 |= V_255 ;
V_39 -> V_55 |= V_256 ;
} else if ( V_38 [ V_124 ] . V_55 & V_257 ) {
V_39 -> V_38 [ V_124 ] . V_254 |= V_255 ;
V_39 -> V_55 |= V_258 ;
}
if ( V_38 [ V_124 ] . V_55 & V_160 )
V_39 -> V_38 [ V_124 ] . V_254 |= V_259 ;
if ( V_38 [ V_124 ] . V_55 & V_163 )
V_39 -> V_38 [ V_124 ] . V_254 |= V_260 ;
V_249 = ! ! ( V_38 [ V_124 ] . V_55 & V_163 ) ;
V_248 = ! ! ( V_38 [ V_124 ] . V_55 & V_160 ) ;
V_250 = ! ! ( V_38 [ V_124 ] . V_55 & V_261 ) ;
if ( V_38 [ V_124 ] . V_55 & V_151 ) {
V_39 -> V_38 [ V_124 ] . V_262 = V_170 | 0x80 ;
V_39 -> V_38 [ V_124 ] . V_263 = F_110 ( V_2 ,
V_228 -> V_264 , V_39 -> V_38 [ V_124 ] . V_262 ) ;
V_39 -> V_38 [ V_124 ] . V_265 = F_97 ( V_2 , V_170 , V_237 ,
V_248 , V_249 , V_250 ) ;
if ( V_170 < 8 && ( V_27 -> V_55 & V_232 ) )
V_39 -> V_38 [ V_124 ] . V_254 |= V_266 ;
V_39 -> V_267 [ V_124 ] = F_105 ( V_2 , V_36 , V_170 ) ;
continue;
}
V_242 = & V_240 -> V_268 [ V_27 -> V_269 ] . V_270 [ V_38 [ V_124 ] . V_150 ] ;
if ( ( V_27 -> V_269 == V_271 ) &&
! ( V_242 -> V_55 & V_272 ) )
V_251 = V_273 ;
else
V_251 = V_274 ;
V_39 -> V_38 [ V_124 ] . V_262 = V_242 -> V_275 ;
if ( V_242 -> V_276 ) {
if ( V_38 [ V_124 ] . V_55 & V_261 )
V_39 -> V_38 [ V_124 ] . V_262 |= V_242 -> V_276 ;
} else {
V_250 = false ;
}
if ( V_36 -> V_62 . V_231 )
V_39 -> V_38 [ V_124 ] . V_263 = V_228 -> V_264 ;
else
V_39 -> V_38 [ V_124 ] . V_263 = F_110 ( V_2 ,
V_228 -> V_264 , V_39 -> V_38 [ V_124 ] . V_262 ) ;
V_39 -> V_38 [ V_124 ] . V_265 = F_111 ( V_2 -> V_90 ,
V_251 , V_242 -> V_277 * 100 , V_237 , V_170 , V_250 ) ;
V_39 -> V_267 [ V_124 ] = F_105 ( V_2 , V_36 , V_170 ) ;
}
if ( F_57 ( V_36 ) && ( V_237 > V_2 -> V_90 -> V_91 . V_278 ) )
V_39 -> V_55 &= ~ V_256 ;
if ( V_39 -> V_55 & V_256 )
V_39 -> V_55 &= ~ V_258 ;
}
static enum V_279 F_112 ( struct V_24 * V_25 )
{
struct V_74 * V_75 ;
enum V_279 V_280 ;
T_4 V_281 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_281 = V_75 -> V_81 ;
if ( F_113 ( V_281 ) )
V_280 = V_282 ;
else if ( F_114 ( V_281 ) )
V_280 = V_283 ;
else if ( F_115 ( V_281 ) )
V_280 = V_284 ;
else if ( F_109 ( V_281 ) )
V_280 = V_285 ;
else
V_280 = V_286 ;
return V_280 ;
}
static void F_116 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , int V_237 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_35 * V_191 = NULL ;
struct V_236 V_39 ;
V_98 V_243 = V_2 -> V_47 -> V_244 -> V_245 ;
bool V_238 = false ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_287 = true ;
V_39 . V_288 = true ;
V_39 . V_289 = V_4 -> V_78 ;
while ( V_36 ) {
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
bool V_290 = ! ! ( V_36 -> V_62 . V_188 & V_190 ) ;
V_39 . type = F_112 ( V_25 ) ;
if ( V_36 -> V_105 )
V_39 . V_291 = V_36 -> V_105 -> V_292 ;
else
V_39 . V_291 = ( V_2 -> V_229 ) ? V_36 -> V_292 : 0 ;
if ( ! V_191 ) {
V_191 = V_36 ;
if ( ! V_2 -> V_229 )
V_39 . V_55 = V_293 ;
if ( ( V_27 -> V_55 & V_187 ) ||
V_4 == V_2 -> V_42 . V_294 )
V_39 . V_55 |= V_295 ;
if ( V_27 -> V_55 & V_296 )
V_39 . V_55 |= V_297 ;
if ( V_27 -> V_55 & V_298 )
V_39 . V_55 |= V_299 ;
if ( V_36 -> V_62 . V_231 )
V_39 . V_55 |= ( V_98 ) V_36 -> V_62 . V_231 <<
V_300 ;
if ( V_290 && ( V_36 == V_191 ) &&
F_48 ( V_243 != ( V_98 ) - 1 ) ) {
if ( ! V_243 || ( V_237 > V_243 ) )
V_238 = true ;
}
if ( ! V_290 )
V_237 = V_40 -> V_199 ;
F_107 ( V_2 , V_36 , & V_39 , V_237 , V_238 ) ;
}
V_39 . V_301 [ 0 ] = V_36 -> V_84 ;
V_39 . V_302 [ 0 ] = V_25 -> V_237 ;
V_39 . V_303 = V_40 -> V_199 ;
V_39 . V_176 = V_40 -> V_176 ;
V_39 . V_304 = V_40 -> V_304 ;
if ( V_290 ) {
if ( V_36 == V_191 )
V_39 . V_290 = V_305 ;
else if ( V_36 == V_191 -> V_109 )
V_39 . V_290 = V_306 ;
else
V_39 . V_290 = V_307 ;
V_39 . V_174 = V_36 -> V_62 . V_174 ;
V_39 . V_192 = V_237 ;
}
if ( V_36 == V_191 -> V_109 )
V_191 = NULL ;
F_117 ( V_228 , V_36 -> V_89 , & V_39 ) ;
V_36 = V_36 -> V_105 ;
}
}
static void
F_118 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
static bool F_119 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_308 )
{
struct V_35 * V_36 ;
struct V_26 * V_27 ;
struct V_110 * V_20 ;
struct V_9 V_106 ;
int V_192 = 0 ;
bool V_290 , V_309 = true ;
if ( ! F_21 ( V_6 ) )
return false ;
F_31 ( & V_106 ) ;
V_36 = F_92 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
return false ;
V_27 = F_8 ( V_36 -> V_37 ) ;
V_290 = ! ! ( V_27 -> V_55 & V_56 ) ;
if ( ( V_290 && V_4 -> V_148 >= V_310 ) ||
( ! V_290 && V_4 -> V_147 >= V_311 ) ) {
* V_308 = true ;
return false ;
}
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( V_290 )
V_309 = F_95 ( V_2 , V_4 , V_6 , & V_106 , V_36 ,
V_20 , & V_192 ) ;
else
F_118 ( V_2 , V_4 , V_6 , & V_106 , V_36 , V_20 ) ;
if ( F_49 ( & V_106 ) )
return false ;
if ( V_6 -> V_8 -> V_141 || V_6 -> V_13 -> V_312 ) {
V_6 -> V_8 -> V_141 = false ;
V_27 -> V_55 |= V_187 ;
}
F_116 ( V_2 , V_36 , V_4 , V_192 ) ;
F_120 ( V_2 , V_4 , & V_106 , false ) ;
return true ;
}
int F_121 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_6 , T_1 * V_313 )
{
struct V_5 * V_314 ;
struct V_3 * V_4 ;
struct V_49 * V_13 ;
T_2 V_315 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_314 = F_20 ( V_13 , V_6 ) ;
V_4 = V_314 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_30 -> V_316 . V_317 ) {
V_13 -> V_165 = ( 1 << ( V_318 +
V_30 -> V_316 . V_319 ) ) - 1 ;
V_315 = F_122 ( V_30 -> V_316 . V_320 ) ;
V_13 -> V_183 = V_315 ;
}
F_25 ( V_2 , V_314 ) ;
V_314 -> V_134 = true ;
* V_313 = V_314 -> V_63 = V_314 -> V_321 ;
V_314 -> V_71 = - 1 ;
memset ( V_314 -> V_68 , 0 , sizeof( V_314 -> V_68 ) ) ;
V_314 -> V_66 = V_314 -> V_69 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_123 ( struct V_1 * V_2 , struct V_34 * V_30 , T_1 V_6 )
{
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_5 * V_314 = F_20 ( V_13 , V_6 ) ;
struct V_3 * V_4 = V_314 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_314 -> V_134 = false ;
F_30 ( V_2 , V_314 ) ;
F_25 ( V_2 , V_314 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_124 ( struct V_34 * V_30 , struct V_1 * V_2 ,
struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_322 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_323 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_19 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_322 = F_21 ( V_6 ) ;
V_6 -> V_19 = false ;
F_52 ( & V_6 -> V_10 ) ;
if ( V_8 -> V_19 ) {
V_8 -> V_19 = false ;
F_52 ( & V_8 -> V_10 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_71 ( V_30 , V_22 , V_322 ) ;
}
}
void F_125 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_323 ; V_22 ++ , V_6 ++ ) {
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
void F_126 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_22 )
{
struct V_5 * V_6 ;
struct V_49 * V_13 ;
struct V_3 * V_4 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_6 = F_20 ( V_13 , V_22 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_133 = V_324 << V_30 -> V_316 . V_319 ;
if ( F_21 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_127 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
T_1 V_325 , int V_95 ,
enum V_326 V_327 ,
bool V_328 )
{
struct V_1 * V_2 = V_47 -> V_329 ;
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_3 * V_4 = V_2 -> V_42 . V_294 ;
struct V_26 * V_39 ;
struct V_9 V_106 ;
struct V_35 * V_330 = NULL , * V_36 ;
struct V_110 * V_20 ;
int V_331 = 0 ;
int V_124 ;
F_31 ( & V_106 ) ;
for ( V_124 = 0 ; V_325 && V_95 ; V_124 ++ , V_325 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_325 & 1 ) )
continue;
V_6 = F_20 ( V_13 , V_124 ) ;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_95 > 0 ) {
V_36 = F_92 ( V_2 , V_2 -> V_42 . V_294 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
F_28 ( V_36 -> V_37 , V_20 ) ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( F_76 ( V_36 ) ) {
F_38 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_62 . V_188 &= ~ V_190 ;
}
if ( V_330 )
V_330 -> V_105 = V_36 ;
V_330 = V_36 ;
V_95 -- ;
V_331 ++ ;
F_43 ( V_4 -> V_78 , V_332 ) ;
if ( V_13 -> V_30 && ! F_21 ( V_6 ) )
F_71 ( V_13 -> V_30 , V_124 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_49 ( & V_106 ) )
return;
V_39 = F_8 ( V_330 -> V_37 ) ;
V_39 -> V_55 |= V_138 ;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
F_1 ( V_2 , V_4 ) ;
F_116 ( V_2 , V_36 , V_4 , 0 ) ;
F_120 ( V_2 , V_4 , & V_106 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_128 ( struct V_1 * V_2 , int V_333 , int V_334 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_335 V_336 ;
static const int V_337 [] = {
[ V_338 ] = V_339 ,
[ V_340 ] = V_341 ,
[ V_342 ] = V_343 ,
[ V_344 ] = V_345 ,
} ;
int V_78 , V_124 ;
memset ( & V_336 , 0 , sizeof( V_336 ) ) ;
V_336 . V_346 = V_337 [ V_334 ] ;
V_336 . V_347 = V_348 ;
V_336 . V_349 = V_348 ;
V_336 . V_350 = V_348 ;
V_336 . V_351 = 0 ;
if ( V_228 -> V_91 . V_178 & V_179 ) {
V_336 . V_352 = V_353 ;
} else {
if ( V_333 == V_354 )
V_336 . V_352 = V_355 ;
else
V_336 . V_352 = V_356 |
V_355 ;
}
V_78 = F_129 ( V_228 , V_333 , & V_336 ) ;
if ( V_78 == - 1 ) {
return NULL ;
}
if ( ! F_130 ( V_2 , V_78 ) ) {
struct V_3 * V_4 = & V_2 -> V_42 . V_4 [ V_78 ] ;
V_4 -> V_78 = V_78 ;
V_4 -> V_157 = - 1 ;
V_4 -> V_357 = NULL ;
F_64 ( & V_4 -> V_358 ) ;
F_31 ( & V_4 -> V_359 ) ;
F_131 ( & V_4 -> V_360 ) ;
V_4 -> V_147 = 0 ;
V_4 -> V_148 = 0 ;
V_4 -> V_146 = false ;
V_2 -> V_42 . V_361 |= 1 << V_78 ;
V_4 -> V_362 = V_4 -> V_363 = 0 ;
for ( V_124 = 0 ; V_124 < V_364 ; V_124 ++ )
F_31 ( & V_4 -> V_365 [ V_124 ] ) ;
}
return & V_2 -> V_42 . V_4 [ V_78 ] ;
}
int F_132 ( struct V_1 * V_2 , int V_366 ,
struct V_335 * V_367 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
int error = 0 ;
struct V_335 V_336 ;
F_133 ( V_2 -> V_42 . V_4 [ V_366 ] . V_78 != V_366 ) ;
F_134 ( V_228 , V_366 , & V_336 ) ;
V_336 . V_347 = V_367 -> V_347 ;
V_336 . V_349 = V_367 -> V_349 ;
V_336 . V_350 = V_367 -> V_350 ;
V_336 . V_368 = V_367 -> V_368 ;
V_336 . V_369 = V_367 -> V_369 ;
if ( ! F_135 ( V_228 , V_366 , & V_336 ) ) {
F_136 ( F_108 ( V_2 -> V_90 ) ,
L_1 , V_366 ) ;
error = - V_370 ;
} else {
F_137 ( V_228 , V_366 ) ;
}
return error ;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_335 V_336 ;
struct V_371 * V_372 = & V_2 -> V_373 -> V_374 ;
int V_366 = V_2 -> V_374 . V_375 -> V_78 ;
F_134 ( V_2 -> V_90 , V_366 , & V_336 ) ;
V_336 . V_369 = ( F_139 ( V_372 -> V_376 ) *
V_377 ) / 100 ;
F_132 ( V_2 , V_366 , & V_336 ) ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_35 * V_36 , * V_378 ;
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
V_378 = V_36 -> V_109 ;
F_141 ( & V_57 , V_10 , & V_378 -> V_10 ) ;
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
}
void F_142 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 ) {
int V_150 = V_4 -> V_363 ;
while ( ! F_49 ( & V_4 -> V_365 [ V_150 ] ) ) {
F_140 ( V_2 , V_4 , & V_4 -> V_365 [ V_150 ] ) ;
F_37 ( V_150 , V_364 ) ;
}
V_4 -> V_363 = V_150 ;
}
V_4 -> V_357 = NULL ;
V_4 -> V_146 = false ;
F_140 ( V_2 , V_4 , & V_4 -> V_359 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_143 ( struct V_1 * V_2 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_3 * V_4 ;
int V_124 ;
V_98 V_379 = 0 ;
if ( F_36 ( V_380 , & V_240 -> V_381 ) )
return true ;
F_144 ( V_228 ) ;
for ( V_124 = 0 ; V_124 < V_382 ; V_124 ++ ) {
if ( ! F_130 ( V_2 , V_124 ) )
continue;
if ( ! V_2 -> V_42 . V_4 [ V_124 ] . V_147 )
continue;
if ( F_145 ( V_228 , V_2 -> V_42 . V_4 [ V_124 ] . V_78 ) )
V_379 |= F_146 ( V_124 ) ;
}
if ( V_379 )
F_136 ( V_240 , L_2 , V_379 ) ;
for ( V_124 = 0 ; V_124 < V_382 ; V_124 ++ ) {
if ( ! F_130 ( V_2 , V_124 ) )
continue;
V_4 = & V_2 -> V_42 . V_4 [ V_124 ] ;
V_4 -> V_45 = false ;
F_142 ( V_2 , V_4 ) ;
}
return ! V_379 ;
}
void F_147 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_148 ( V_2 -> V_90 , V_4 -> V_78 ) ;
V_2 -> V_42 . V_361 &= ~ ( 1 << V_4 -> V_78 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_7 * V_8 , * V_383 ;
struct V_5 * V_6 , * V_384 ;
struct V_9 * V_385 ;
bool V_331 = false ;
if ( V_4 -> V_157 < 0 )
return;
if ( F_36 ( V_386 , & V_240 -> V_381 ) )
return;
F_47 ( & V_2 -> V_387 ) ;
V_385 = & V_2 -> V_373 -> V_21 [ V_4 -> V_157 ] ;
if ( F_49 ( V_385 ) ) {
F_50 ( & V_2 -> V_387 ) ;
return;
}
F_60 () ;
V_383 = F_149 ( V_385 -> V_76 , struct V_7 , V_10 ) ;
while ( ! F_49 ( V_385 ) ) {
bool V_308 = false ;
if ( V_2 -> V_373 -> V_45 )
break;
V_8 = F_51 ( V_385 , struct V_7 , V_10 ) ;
V_384 = F_149 ( V_8 -> V_20 . V_76 , struct V_5 , V_10 ) ;
F_52 ( & V_8 -> V_10 ) ;
V_8 -> V_19 = false ;
while ( ! F_49 ( & V_8 -> V_20 ) ) {
V_6 = F_51 ( & V_8 -> V_20 , struct V_5 ,
V_10 ) ;
F_52 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
if ( F_119 ( V_2 , V_4 , V_6 , & V_308 ) )
V_331 = true ;
if ( F_21 ( V_6 ) )
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_308 || V_6 == V_384 )
break;
}
if ( ! F_49 ( & V_8 -> V_20 ) && ! V_8 -> V_19 ) {
V_8 -> V_19 = true ;
F_5 ( & V_8 -> V_10 , V_385 ) ;
}
if ( V_308 )
break;
if ( V_8 == V_383 ) {
if ( ! V_331 )
break;
V_331 = false ;
V_383 = F_149 ( V_385 -> V_76 ,
struct V_7 , V_10 ) ;
}
}
F_62 () ;
F_50 ( & V_2 -> V_387 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_388 ; V_124 ++ ) {
V_4 = V_2 -> V_42 . V_43 [ V_124 ] ;
F_47 ( & V_4 -> V_360 ) ;
F_79 ( V_2 , V_4 ) ;
F_50 ( & V_4 -> V_360 ) ;
}
}
static void F_120 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_389 , bool V_390 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_239 * V_240 = F_108 ( V_228 ) ;
struct V_35 * V_36 , * V_108 ;
bool V_391 = false ;
bool V_392 ;
if ( F_49 ( V_389 ) )
return;
V_392 = ! ! ( V_228 -> V_91 . V_178 & V_179 ) ;
V_36 = F_51 ( V_389 , struct V_35 , V_10 ) ;
V_108 = F_149 ( V_389 -> V_76 , struct V_35 , V_10 ) ;
F_151 ( V_240 , V_393 , L_3 ,
V_4 -> V_78 , V_4 -> V_147 ) ;
if ( V_392 && F_49 ( & V_4 -> V_365 [ V_4 -> V_362 ] ) ) {
F_152 ( V_389 , & V_4 -> V_365 [ V_4 -> V_362 ] ) ;
F_37 ( V_4 -> V_362 , V_364 ) ;
V_391 = true ;
} else {
F_152 ( V_389 , & V_4 -> V_359 ) ;
if ( V_4 -> V_357 ) {
F_153 ( V_228 , V_4 -> V_357 , V_36 -> V_292 ) ;
F_151 ( V_240 , V_394 , L_4 ,
V_4 -> V_78 , V_4 -> V_357 ,
F_154 ( V_36 -> V_292 ) , V_36 -> V_89 ) ;
} else if ( ! V_392 )
V_391 = true ;
V_4 -> V_357 = V_108 -> V_89 ;
}
if ( V_391 ) {
F_43 ( V_4 -> V_78 , V_391 ) ;
F_155 ( V_228 , V_4 -> V_78 , V_36 -> V_292 ) ;
F_151 ( V_240 , V_394 , L_5 ,
V_4 -> V_78 , F_154 ( V_36 -> V_292 ) , V_36 -> V_89 ) ;
}
if ( ! V_392 || V_2 -> V_229 ) {
F_43 ( V_4 -> V_78 , V_395 ) ;
F_156 ( V_228 , V_4 -> V_78 ) ;
}
if ( ! V_390 ) {
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
static void F_157 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_116 ( V_2 , V_36 , V_4 , V_40 -> V_199 ) ;
F_120 ( V_2 , V_4 , & V_57 , false ) ;
F_43 ( V_4 -> V_78 , V_396 ) ;
}
static void F_158 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
struct V_24 * V_25 ,
int V_199 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_397 * V_398 = V_27 -> V_137 . V_398 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
const struct V_241 * V_242 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_49 * V_13 = NULL ;
enum V_399 V_304 ;
bool V_400 = false ;
if ( V_27 -> V_137 . V_14 &&
V_27 -> V_137 . V_14 -> V_401 . V_402 )
V_400 = true ;
V_242 = F_159 ( V_47 , V_27 ) ;
V_304 = F_160 ( V_25 ) ;
if ( V_30 )
V_13 = (struct V_49 * ) V_30 -> V_15 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_4 = - 1 ;
if ( V_398 )
V_40 -> V_176 = V_398 -> V_403 ;
else if ( V_13 && F_161 ( V_75 -> V_81 ) && V_13 -> V_404 > 0 )
V_40 -> V_176 = V_13 -> V_404 ;
else
V_40 -> V_176 = V_177 ;
V_40 -> V_304 = V_304 ;
V_40 -> V_199 = V_199 ;
V_40 -> V_234 = V_230 ;
if ( ! V_242 )
return;
V_40 -> V_247 = V_242 -> V_275 ;
if ( V_400 )
V_40 -> V_247 |= V_242 -> V_276 ;
}
T_2 F_110 ( struct V_1 * V_2 , T_2 V_405 , V_98 V_242 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_406 * V_407 = V_228 -> V_407 ;
if ( ( V_228 -> V_91 . V_178 & V_408 ) && F_162 ( V_407 ) &&
( V_405 == 0x7 ) && ( V_242 < 0x90 ) )
return 0x3 ;
else if ( F_163 ( V_228 ) && F_164 ( V_228 ) &&
F_165 ( V_242 ) )
return 0x2 ;
else
return V_405 ;
}
static struct V_35 * F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_35 * V_36 ;
int V_409 ;
T_1 V_29 ;
V_36 = F_46 ( V_2 ) ;
if ( ! V_36 ) {
F_151 ( V_240 , V_394 , L_6 ) ;
return NULL ;
}
F_55 ( V_36 ) ;
if ( V_6 && F_166 ( V_75 -> V_81 ) ) {
V_409 = F_167 ( V_75 -> V_410 ) & V_411 ;
V_29 = V_6 -> V_321 ;
V_75 -> V_410 = F_44 ( V_6 -> V_321 << V_32 ) ;
if ( V_409 )
V_75 -> V_410 |= F_44 ( V_409 ) ;
if ( ! F_168 ( V_75 -> V_81 ) )
F_37 ( V_6 -> V_321 , V_70 ) ;
V_36 -> V_62 . V_29 = V_29 ;
}
V_36 -> V_37 = V_25 ;
V_36 -> V_84 = F_169 ( V_2 -> V_83 , V_25 -> V_80 ,
V_25 -> V_237 , V_85 ) ;
if ( F_48 ( F_170 ( V_2 -> V_83 , V_36 -> V_84 ) ) ) {
V_36 -> V_37 = NULL ;
V_36 -> V_84 = 0 ;
F_136 ( F_108 ( V_2 -> V_90 ) ,
L_7 ) ;
F_53 ( V_2 , V_36 ) ;
return NULL ;
}
V_40 -> V_36 = V_36 ;
return V_36 ;
}
void F_171 ( struct V_239 * V_240 , struct V_24 * V_25 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
if ( ! ( V_39 -> V_55 & V_412 ) )
return;
if ( ! V_14 )
return;
V_12 = (struct V_11 * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_413 )
V_12 -> V_414 += 0x10 ;
V_75 -> V_410 &= F_44 ( V_411 ) ;
V_75 -> V_410 |= F_44 ( V_12 -> V_414 ) ;
}
static int F_172 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_415 * V_416 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_416 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_47 -> V_329 ;
int V_153 = V_25 -> V_237 + V_417 ;
int V_418 , V_419 ;
if ( V_30 )
V_416 -> V_13 = (struct V_49 * ) V_30 -> V_15 ;
else if ( V_14 && F_161 ( V_75 -> V_81 ) ) {
V_12 = ( void * ) V_14 -> V_15 ;
V_416 -> V_13 = & V_12 -> V_420 ;
}
if ( V_39 -> V_137 . V_398 )
V_153 += V_39 -> V_137 . V_398 -> V_421 ;
F_171 ( F_108 ( V_2 -> V_90 ) , V_25 ) ;
if ( ( V_14 && V_14 -> type != V_422 &&
V_14 -> type != V_423 ) ||
! F_161 ( V_75 -> V_81 ) )
V_39 -> V_55 |= V_187 ;
V_418 = F_173 ( V_75 -> V_81 ) ;
V_419 = V_418 & 3 ;
if ( V_419 && V_25 -> V_237 > V_418 ) {
if ( F_174 ( V_25 ) < V_419 )
return - V_424 ;
F_175 ( V_25 , V_419 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_419 , V_418 ) ;
}
F_158 ( V_47 , V_30 , V_25 , V_153 ) ;
return 0 ;
}
int F_176 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_415 * V_416 )
{
struct V_74 * V_75 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_416 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_11 * V_12 = NULL ;
struct V_1 * V_2 = V_47 -> V_329 ;
struct V_3 * V_4 = V_416 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_36 ;
bool V_217 , V_425 = false ;
int V_41 , V_426 ;
if ( V_14 )
V_12 = ( void * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_427 )
V_416 -> V_428 = true ;
V_426 = F_172 ( V_47 , V_25 , V_416 ) ;
if ( V_426 )
return V_426 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_41 = F_177 ( V_25 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_42 . V_43 [ V_41 ] ) {
V_40 -> V_4 = V_41 ;
if ( ++ V_4 -> V_44 > V_2 -> V_42 . V_46 [ V_41 ] &&
! V_4 -> V_45 ) {
if ( F_17 () )
F_178 ( V_2 -> V_47 , V_39 -> V_48 ) ;
else
F_178 ( V_2 -> V_47 , V_41 ) ;
V_4 -> V_45 = true ;
}
}
V_217 = F_166 ( V_75 -> V_81 ) ;
if ( ( ( V_12 && V_12 -> V_18 != V_2 -> V_373 ) ||
V_2 -> V_373 -> V_45 ) && ! V_416 -> V_428 ) {
if ( ! V_416 -> V_13 )
V_416 -> V_13 = & V_12 -> V_420 ;
V_217 = true ;
V_425 = true ;
}
if ( V_416 -> V_13 && V_217 )
V_6 = F_19 ( V_2 , V_416 -> V_13 , V_25 ) ;
if ( ! V_425 && ( V_39 -> V_55 & V_429 ) ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_42 . V_294 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_416 -> V_13 && V_217 ) {
F_16 ( V_6 -> V_8 -> V_4 != V_416 -> V_4 ) ;
if ( V_39 -> V_55 & V_187 )
V_6 -> V_8 -> V_141 = true ;
F_43 ( V_4 -> V_78 , V_430 ) ;
F_70 ( & V_6 -> V_52 , V_25 ) ;
if ( ! V_416 -> V_13 -> V_136 )
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
goto V_431;
}
V_36 = F_27 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
if ( V_416 -> V_432 )
F_179 ( V_25 ) ;
else
F_29 ( V_2 -> V_47 , V_25 ) ;
goto V_431;
}
V_36 -> V_62 . V_231 = V_416 -> V_432 ;
if ( V_416 -> V_432 )
V_36 -> V_62 . V_433 = V_434 ;
F_12 ( V_14 , V_30 , V_36 ) ;
F_157 ( V_2 , V_4 , V_6 , V_25 ) ;
V_431:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_180 ( struct V_107 * V_47 , struct V_33 * V_14 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_47 -> V_329 ;
struct V_415 V_416 = {
. V_4 = V_2 -> V_374 . V_375
} ;
struct V_236 V_39 = {} ;
struct V_74 * V_75 ;
struct V_35 * V_330 = NULL ;
struct V_35 * V_36 ;
F_181 ( V_106 ) ;
int V_149 = 0 ;
int V_435 ;
V_435 =
V_2 -> V_373 -> V_374 . V_376 * 1000 *
V_2 -> V_373 -> V_374 . V_436 / V_437 ;
do {
struct V_23 * V_40 = F_7 ( V_25 ) ;
if ( F_172 ( V_47 , V_25 , & V_416 ) )
break;
V_36 = F_27 ( V_2 , V_416 . V_4 , NULL , V_25 ) ;
if ( ! V_36 )
break;
V_36 -> V_109 = V_36 ;
F_12 ( V_14 , NULL , V_36 ) ;
F_107 ( V_2 , V_36 , & V_39 , V_40 -> V_199 , false ) ;
V_149 += V_39 . V_38 [ 0 ] . V_265 ;
if ( V_330 )
V_330 -> V_105 = V_36 ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
V_330 = V_36 ;
V_25 = NULL ;
if ( V_149 > V_435 )
break;
V_25 = F_182 ( V_47 , V_14 ) ;
} while( V_25 );
if ( V_25 )
F_29 ( V_47 , V_25 ) ;
if ( F_49 ( & V_106 ) )
return;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
V_75 = (struct V_74 * ) V_36 -> V_37 -> V_80 ;
if ( V_75 -> V_81 & V_438 ) {
V_75 -> V_81 &= ~ V_438 ;
F_45 ( V_2 -> V_83 , V_36 -> V_84 ,
sizeof( * V_75 ) , V_85 ) ;
}
F_1 ( V_2 , V_416 . V_4 ) ;
F_116 ( V_2 , V_36 , V_416 . V_4 , 0 ) ;
F_120 ( V_2 , V_416 . V_4 , & V_106 , false ) ;
F_43 ( V_416 . V_4 -> V_78 , V_396 ) ;
F_2 ( V_2 , V_416 . V_4 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_24 * V_25 ,
int V_439 , struct V_3 * V_4 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
int V_418 , V_419 ;
unsigned long V_55 ;
F_151 ( V_240 , V_394 , L_8 , V_25 ) ;
if ( V_2 -> V_90 -> V_440 )
F_183 ( V_441 , & V_2 -> V_90 -> V_440 -> V_442 ) ;
if ( ! ( V_439 & V_72 ) )
V_27 -> V_55 |= V_443 ;
V_418 = F_173 ( V_75 -> V_81 ) ;
V_419 = V_418 & 3 ;
if ( V_419 && V_25 -> V_237 > V_418 + V_419 ) {
memmove ( V_25 -> V_80 + V_419 , V_25 -> V_80 , V_418 ) ;
F_184 ( V_25 , V_419 ) ;
}
F_185 ( & V_2 -> V_444 , V_55 ) ;
if ( ( V_2 -> V_445 & V_446 ) && ! V_4 -> V_147 ) {
V_2 -> V_445 &= ~ V_446 ;
F_151 ( V_240 , V_447 ,
L_9 ,
V_2 -> V_445 & ( V_448 |
V_449 |
V_450 |
V_446 ) ) ;
}
F_186 ( & V_2 -> V_444 , V_55 ) ;
F_70 ( & V_4 -> V_358 , V_25 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_9 * V_106 ,
struct V_58 * V_59 , int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
unsigned long V_55 ;
int V_439 = 0 ;
if ( ! V_94 )
V_439 |= V_72 ;
if ( V_59 -> V_122 & V_139 )
V_27 -> V_55 |= V_451 ;
F_187 ( V_2 -> V_83 , V_36 -> V_84 , V_25 -> V_237 , V_85 ) ;
V_36 -> V_84 = 0 ;
if ( V_2 -> V_229 )
goto V_452;
if ( V_36 -> V_62 . V_231 ) {
if ( F_188 ( V_434 ,
V_36 -> V_62 . V_433 +
F_189 ( V_453 ) ) )
F_179 ( V_25 ) ;
else
F_190 ( & V_2 -> V_454 ) ;
} else {
F_191 ( V_2 , V_36 , V_59 , V_4 , V_439 ) ;
F_41 ( V_2 , V_25 , V_439 , V_4 ) ;
}
V_452:
V_36 -> V_37 = NULL ;
F_185 ( & V_2 -> V_42 . V_86 , V_55 ) ;
F_152 ( V_106 , & V_2 -> V_42 . V_87 ) ;
F_186 ( & V_2 -> V_42 . V_86 , V_55 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_58 * V_59 , int V_95 , int V_96 ,
int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_107 * V_47 = V_2 -> V_47 ;
struct V_227 * V_228 = V_2 -> V_90 ;
T_2 V_124 , V_455 ;
if ( V_94 )
V_27 -> V_456 . V_457 = V_59 -> V_458 ;
V_455 = V_59 -> V_126 ;
F_16 ( V_455 >= V_47 -> V_459 ) ;
if ( V_27 -> V_55 & V_56 ) {
V_27 -> V_55 |= V_460 ;
F_133 ( V_96 > V_95 ) ;
}
V_27 -> V_456 . V_461 = V_95 ;
V_27 -> V_456 . V_462 = V_95 - V_96 ;
if ( ( V_59 -> V_122 & V_139 ) == 0 &&
( V_27 -> V_55 & V_296 ) == 0 ) {
if ( F_48 ( V_59 -> V_129 & ( V_463 |
V_464 ) ) &&
F_161 ( V_75 -> V_81 ) &&
V_228 -> V_465 >= V_2 -> V_90 -> V_466 . V_467 )
V_27 -> V_456 . V_38 [ V_455 ] . V_73 =
V_47 -> V_468 ;
}
for ( V_124 = V_455 + 1 ; V_124 < V_47 -> V_459 ; V_124 ++ ) {
V_27 -> V_456 . V_38 [ V_124 ] . V_73 = 0 ;
V_27 -> V_456 . V_38 [ V_124 ] . V_150 = - 1 ;
}
V_27 -> V_456 . V_38 [ V_455 ] . V_73 = V_59 -> V_125 + 1 ;
}
static void F_192 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_239 * V_240 = F_108 ( V_228 ) ;
struct V_35 * V_36 , * V_378 , * V_469 = NULL ;
struct V_9 V_57 ;
struct V_470 * V_471 ;
struct V_58 V_59 ;
int V_456 ;
F_151 ( V_240 , V_393 , L_10 ,
V_4 -> V_78 , F_193 ( V_2 -> V_90 , V_4 -> V_78 ) ,
V_4 -> V_357 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_36 ( V_386 , & V_240 -> V_381 ) )
break;
if ( F_49 ( & V_4 -> V_359 ) ) {
V_4 -> V_357 = NULL ;
F_79 ( V_2 , V_4 ) ;
break;
}
V_36 = F_51 ( & V_4 -> V_359 , struct V_35 , V_10 ) ;
V_469 = NULL ;
if ( V_36 -> V_62 . V_93 ) {
V_469 = V_36 ;
if ( F_194 ( & V_469 -> V_10 , & V_4 -> V_359 ) )
break;
V_36 = F_149 ( V_469 -> V_10 . V_472 , struct V_35 ,
V_10 ) ;
}
V_378 = V_36 -> V_109 ;
V_471 = V_378 -> V_89 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_456 = F_195 ( V_228 , V_471 , & V_59 ) ;
if ( V_456 == - V_473 )
break;
F_43 ( V_4 -> V_78 , V_474 ) ;
V_378 -> V_62 . V_93 = true ;
F_31 ( & V_57 ) ;
if ( ! F_196 ( & V_378 -> V_10 ) )
F_141 ( & V_57 ,
& V_4 -> V_359 , V_378 -> V_10 . V_76 ) ;
if ( V_469 ) {
F_52 ( & V_469 -> V_10 ) ;
F_53 ( V_2 , V_469 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_197 ( struct V_1 * V_2 )
{
struct V_227 * V_228 = V_2 -> V_90 ;
V_98 V_475 = ( ( 1 << V_382 ) - 1 ) & V_228 -> V_476 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_382 ; V_124 ++ ) {
if ( F_130 ( V_2 , V_124 ) && ( V_475 & ( 1 << V_124 ) ) )
F_192 ( V_2 , & V_2 -> V_42 . V_4 [ V_124 ] ) ;
}
}
void F_198 ( struct V_1 * V_2 )
{
struct V_58 V_59 ;
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_227 * V_228 = V_2 -> V_90 ;
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_378 ;
struct V_9 V_57 ;
struct V_9 * V_477 ;
int V_456 ;
for (; ; ) {
if ( F_36 ( V_386 , & V_240 -> V_381 ) )
break;
V_456 = F_195 ( V_228 , NULL , ( void * ) & V_59 ) ;
if ( V_456 == - V_473 )
break;
if ( V_456 == - V_370 ) {
F_151 ( V_240 , V_394 , L_11 ) ;
break;
}
if ( V_59 . V_478 == V_2 -> V_374 . V_479 ) {
V_2 -> V_374 . V_480 = true ;
V_2 -> V_374 . V_481 = ! ( V_59 . V_122 & V_145 ) ;
if ( F_17 () ) {
F_199 ( V_2 , NULL ,
V_482 ) ;
}
F_200 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_42 . V_4 [ V_59 . V_478 ] ;
F_1 ( V_2 , V_4 ) ;
F_43 ( V_4 -> V_78 , V_474 ) ;
V_477 = & V_4 -> V_365 [ V_4 -> V_363 ] ;
if ( F_49 ( V_477 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_36 = F_51 ( V_477 , struct V_35 , V_10 ) ;
if ( V_36 -> V_62 . V_93 ) {
F_52 ( & V_36 -> V_10 ) ;
F_53 ( V_2 , V_36 ) ;
V_36 = F_51 ( V_477 , struct V_35 , V_10 ) ;
}
V_378 = V_36 -> V_109 ;
F_31 ( & V_57 ) ;
if ( F_194 ( & V_378 -> V_10 , V_477 ) ) {
F_152 ( V_477 , & V_57 ) ;
F_37 ( V_4 -> V_363 , V_364 ) ;
if ( ! F_49 ( & V_4 -> V_359 ) ) {
struct V_9 V_106 ;
F_31 ( & V_106 ) ;
V_4 -> V_357 = NULL ;
F_152 ( & V_4 -> V_359 , & V_106 ) ;
F_120 ( V_2 , V_4 , & V_106 , true ) ;
}
} else {
V_378 -> V_62 . V_93 = true ;
if ( V_36 != V_378 )
F_141 ( & V_57 , V_477 ,
V_378 -> V_10 . V_76 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_201 ( struct V_1 * V_2 , int V_483 )
{
struct V_484 * V_485 = & V_2 -> V_486 ;
T_2 V_487 = V_2 -> V_90 -> V_91 . V_487 ;
V_485 -> V_488 = V_483 * V_487 ;
V_485 -> V_489 = F_202 ( V_2 -> V_83 , V_485 -> V_488 ,
& V_485 -> V_490 , V_491 ) ;
if ( ! V_485 -> V_489 )
return - V_424 ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
int V_492 ;
V_492 = F_201 ( V_2 , V_493 ) ;
if ( ! V_492 )
F_204 ( V_2 -> V_90 , V_2 -> V_486 . V_489 ,
V_2 -> V_486 . V_490 ,
V_493 ) ;
return V_492 ;
}
int F_205 ( struct V_1 * V_2 , int V_494 )
{
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
int error = 0 ;
F_131 ( & V_2 -> V_42 . V_86 ) ;
error = F_206 ( V_2 , & V_2 -> V_42 . V_495 , & V_2 -> V_42 . V_87 ,
L_12 , V_494 , 1 , 1 ) ;
if ( error != 0 ) {
F_136 ( V_240 ,
L_13 , error ) ;
return error ;
}
error = F_206 ( V_2 , & V_2 -> V_374 . V_496 , & V_2 -> V_374 . V_497 ,
L_14 , V_437 , 1 , 1 ) ;
if ( error != 0 ) {
F_136 ( V_240 ,
L_15 , error ) ;
return error ;
}
F_207 ( & V_2 -> V_498 , V_499 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 )
error = F_203 ( V_2 ) ;
return error ;
}
void F_208 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_22 , V_500 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_323 ;
V_22 ++ , V_6 ++ ) {
V_6 -> V_13 = V_13 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_63 = V_6 -> V_321 = 0 ;
V_6 -> V_133 = V_501 ;
V_6 -> V_66 = V_6 -> V_69 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_134 = false ;
F_64 ( & V_6 -> V_52 ) ;
F_64 ( & V_6 -> V_53 ) ;
V_500 = F_6 ( V_22 ) ;
V_6 -> V_8 = & V_13 -> V_8 [ V_500 ] ;
}
for ( V_500 = 0 , V_8 = & V_13 -> V_8 [ V_500 ] ;
V_500 < V_388 ; V_500 ++ , V_8 ++ ) {
V_8 -> V_19 = false ;
V_8 -> V_141 = true ;
V_8 -> V_4 = V_2 -> V_42 . V_43 [ V_500 ] ;
F_31 ( & V_8 -> V_20 ) ;
}
}
void F_209 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_323 ; V_22 ++ , V_6 ++ ) {
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
int F_210 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_415 * V_416 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_239 * V_240 = F_108 ( V_2 -> V_90 ) ;
struct V_35 * V_36 ;
int V_418 , V_419 ;
V_418 = F_173 ( V_75 -> V_81 ) ;
V_419 = V_418 & 3 ;
if ( V_419 && V_25 -> V_237 > V_418 ) {
if ( F_174 ( V_25 ) < V_419 ) {
F_151 ( V_240 , V_394 ,
L_16 ) ;
return - V_502 ;
}
F_175 ( V_25 , V_419 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_419 , V_418 ) ;
}
V_40 -> V_176 = V_177 ;
V_40 -> V_199 = V_25 -> V_237 + V_417 ;
V_40 -> V_304 = V_503 ;
V_36 = F_27 ( V_2 , V_416 -> V_4 , NULL , V_25 ) ;
if ( ! V_36 ) {
F_151 ( V_240 , V_394 , L_17 ) ;
return - V_502 ;
}
F_12 ( V_2 -> V_504 , NULL , V_36 ) ;
F_153 ( V_2 -> V_90 , V_36 -> V_89 , V_36 -> V_292 ) ;
F_211 ( V_2 -> V_90 , V_416 -> V_4 -> V_78 ) ;
F_157 ( V_2 , V_416 -> V_4 , NULL , V_25 ) ;
return 0 ;
}
