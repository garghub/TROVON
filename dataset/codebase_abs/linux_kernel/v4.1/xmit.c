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
T_2 V_225 , bool V_226 , bool V_227 )
{
T_2 V_228 ;
struct V_24 * V_25 ;
struct V_23 * V_40 ;
struct V_26 * V_39 ;
struct V_229 * V_230 = V_2 -> V_90 ;
if ( V_2 -> V_231 || ! V_230 -> V_232 )
return V_233 ;
V_25 = V_36 -> V_37 ;
V_40 = F_7 ( V_25 ) ;
V_39 = F_8 ( V_25 ) ;
if ( ! F_106 ( V_230 ) ) {
int V_234 = V_40 -> V_235 ;
if ( V_226 ) {
T_2 V_236 ;
struct V_237 * V_238 = & V_230 -> V_239 . V_240 ;
if ( V_241 >= V_242 ) {
bool V_243 ;
struct V_244 * V_245 ;
V_243 = V_39 -> V_246 == V_247 ;
V_245 = & V_238 -> V_248 [ V_243 ] ;
V_236 = V_245 -> V_249 ;
} else {
V_236 = 2 ;
}
V_234 += V_236 ;
}
if ( F_107 ( V_230 ) || F_108 ( V_230 ) ||
F_109 ( V_230 ) ) {
V_234 -= 2 * V_250 ;
} else if ( F_110 ( V_230 ) ) {
T_4 V_251 ;
V_251 = V_230 -> V_252 -> V_253 ( V_230 ,
V_254 ) ;
V_234 -= 2 * V_251 ;
}
if ( V_255 && V_227 )
V_234 -= 2 ;
V_234 = F_88 ( V_234 , 0 ) ;
V_228 = F_111 ( T_2 , V_230 -> V_235 [ V_225 ] , V_234 ) ;
if ( ! V_228 && ! F_110 ( V_230 ) )
V_228 = 1 ;
} else if ( ! V_36 -> V_62 . V_256 ) {
if ( V_225 < 8 && ( V_39 -> V_55 & V_257 ) )
V_228 = F_111 ( T_2 , V_230 -> V_258 [ V_225 ] ,
V_40 -> V_235 ) ;
else
V_228 = F_111 ( T_2 , V_230 -> V_235 [ V_225 ] ,
V_40 -> V_235 ) ;
} else {
V_228 = V_230 -> V_259 ;
}
return V_228 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_260 * V_39 , int V_261 , bool V_262 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_263 * V_264 = F_113 ( V_230 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_120 * V_38 ;
const struct V_265 * V_266 ;
struct V_74 * V_75 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_98 V_267 = V_2 -> V_47 -> V_268 -> V_269 ;
int V_124 ;
T_2 V_170 = 0 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_39 -> V_270 = ! F_114 ( V_75 -> V_81 ) ;
V_39 -> V_271 = V_40 -> V_271 ;
for ( V_124 = 0 ; V_124 < F_14 ( V_36 -> V_38 ) ; V_124 ++ ) {
bool V_226 , V_272 , V_273 , V_227 ;
int V_274 ;
if ( ! V_38 [ V_124 ] . V_73 || ( V_38 [ V_124 ] . V_150 < 0 ) )
continue;
V_170 = V_38 [ V_124 ] . V_150 ;
V_39 -> V_38 [ V_124 ] . V_275 = V_38 [ V_124 ] . V_73 ;
if ( F_76 ( V_36 ) && ! F_57 ( V_36 ) &&
( V_38 [ V_124 ] . V_55 & V_151 ) &&
F_48 ( V_267 != ( V_98 ) - 1 ) ) {
if ( ! V_267 || ( V_261 > V_267 ) )
V_262 = true ;
}
if ( V_262 || V_38 [ V_124 ] . V_55 & V_276 ) {
V_39 -> V_38 [ V_124 ] . V_277 |= V_278 ;
V_39 -> V_55 |= V_279 ;
} else if ( V_38 [ V_124 ] . V_55 & V_280 ) {
V_39 -> V_38 [ V_124 ] . V_277 |= V_278 ;
V_39 -> V_55 |= V_281 ;
}
if ( V_38 [ V_124 ] . V_55 & V_160 )
V_39 -> V_38 [ V_124 ] . V_277 |= V_282 ;
if ( V_38 [ V_124 ] . V_55 & V_163 )
V_39 -> V_38 [ V_124 ] . V_277 |= V_283 ;
V_272 = ! ! ( V_38 [ V_124 ] . V_55 & V_163 ) ;
V_226 = ! ! ( V_38 [ V_124 ] . V_55 & V_160 ) ;
V_273 = ! ! ( V_38 [ V_124 ] . V_55 & V_284 ) ;
if ( V_38 [ V_124 ] . V_55 & V_151 ) {
V_39 -> V_38 [ V_124 ] . V_285 = V_170 | 0x80 ;
V_39 -> V_38 [ V_124 ] . V_286 = F_115 ( V_2 ,
V_230 -> V_287 , V_39 -> V_38 [ V_124 ] . V_285 ) ;
V_39 -> V_38 [ V_124 ] . V_288 = F_97 ( V_2 , V_170 , V_261 ,
V_226 , V_272 , V_273 ) ;
if ( V_170 < 8 && ( V_27 -> V_55 & V_257 ) )
V_39 -> V_38 [ V_124 ] . V_277 |= V_289 ;
V_39 -> V_234 [ V_124 ] = F_105 ( V_2 , V_36 , V_170 ,
V_226 , false ) ;
continue;
}
V_266 = & V_264 -> V_290 [ V_27 -> V_246 ] . V_291 [ V_38 [ V_124 ] . V_150 ] ;
if ( ( V_27 -> V_246 == V_247 ) &&
! ( V_266 -> V_55 & V_292 ) )
V_274 = V_293 ;
else
V_274 = V_294 ;
V_39 -> V_38 [ V_124 ] . V_285 = V_266 -> V_295 ;
if ( V_266 -> V_296 ) {
if ( V_38 [ V_124 ] . V_55 & V_284 )
V_39 -> V_38 [ V_124 ] . V_285 |= V_266 -> V_296 ;
} else {
V_273 = false ;
}
if ( V_36 -> V_62 . V_256 )
V_39 -> V_38 [ V_124 ] . V_286 = V_230 -> V_287 ;
else
V_39 -> V_38 [ V_124 ] . V_286 = F_115 ( V_2 ,
V_230 -> V_287 , V_39 -> V_38 [ V_124 ] . V_285 ) ;
V_39 -> V_38 [ V_124 ] . V_288 = F_116 ( V_2 -> V_90 ,
V_274 , V_266 -> V_297 * 100 , V_261 , V_170 , V_273 ) ;
V_227 = F_117 ( V_39 -> V_38 [ V_124 ] . V_285 ) ;
V_39 -> V_234 [ V_124 ] = F_105 ( V_2 , V_36 , V_170 , false ,
V_227 ) ;
}
if ( F_57 ( V_36 ) && ( V_261 > V_2 -> V_90 -> V_91 . V_298 ) )
V_39 -> V_55 &= ~ V_279 ;
if ( V_39 -> V_55 & V_279 )
V_39 -> V_55 &= ~ V_281 ;
}
static enum V_299 F_118 ( struct V_24 * V_25 )
{
struct V_74 * V_75 ;
enum V_299 V_300 ;
T_5 V_301 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_301 = V_75 -> V_81 ;
if ( F_119 ( V_301 ) )
V_300 = V_302 ;
else if ( F_120 ( V_301 ) )
V_300 = V_303 ;
else if ( F_121 ( V_301 ) )
V_300 = V_304 ;
else if ( F_114 ( V_301 ) )
V_300 = V_305 ;
else
V_300 = V_306 ;
return V_300 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , int V_261 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_35 * V_191 = NULL ;
struct V_260 V_39 ;
V_98 V_267 = V_2 -> V_47 -> V_268 -> V_269 ;
bool V_262 = false ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_307 = true ;
V_39 . V_308 = true ;
V_39 . V_309 = V_4 -> V_78 ;
while ( V_36 ) {
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
bool V_310 = ! ! ( V_36 -> V_62 . V_188 & V_190 ) ;
V_39 . type = F_118 ( V_25 ) ;
if ( V_36 -> V_105 )
V_39 . V_311 = V_36 -> V_105 -> V_312 ;
else
V_39 . V_311 = ( V_2 -> V_231 ) ? V_36 -> V_312 : 0 ;
if ( ! V_191 ) {
V_191 = V_36 ;
if ( ! V_2 -> V_231 )
V_39 . V_55 = V_313 ;
if ( ( V_27 -> V_55 & V_187 ) ||
V_4 == V_2 -> V_42 . V_314 )
V_39 . V_55 |= V_315 ;
if ( V_27 -> V_55 & V_316 )
V_39 . V_55 |= V_317 ;
if ( V_27 -> V_55 & V_318 )
V_39 . V_55 |= V_319 ;
if ( V_36 -> V_62 . V_256 )
V_39 . V_55 |= ( V_98 ) V_36 -> V_62 . V_256 <<
V_320 ;
if ( V_310 && ( V_36 == V_191 ) &&
F_48 ( V_267 != ( V_98 ) - 1 ) ) {
if ( ! V_267 || ( V_261 > V_267 ) )
V_262 = true ;
}
if ( ! V_310 )
V_261 = V_40 -> V_199 ;
F_112 ( V_2 , V_36 , & V_39 , V_261 , V_262 ) ;
}
V_39 . V_321 [ 0 ] = V_36 -> V_84 ;
V_39 . V_322 [ 0 ] = V_25 -> V_261 ;
V_39 . V_323 = V_40 -> V_199 ;
V_39 . V_176 = V_40 -> V_176 ;
V_39 . V_324 = V_40 -> V_324 ;
if ( V_310 ) {
if ( V_36 == V_191 )
V_39 . V_310 = V_325 ;
else if ( V_36 == V_191 -> V_109 )
V_39 . V_310 = V_326 ;
else
V_39 . V_310 = V_327 ;
V_39 . V_174 = V_36 -> V_62 . V_174 ;
V_39 . V_192 = V_261 ;
}
if ( V_36 == V_191 -> V_109 )
V_191 = NULL ;
F_123 ( V_230 , V_36 -> V_89 , & V_39 ) ;
V_36 = V_36 -> V_105 ;
}
}
static void
F_124 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
static bool F_125 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_328 )
{
struct V_35 * V_36 ;
struct V_26 * V_27 ;
struct V_110 * V_20 ;
struct V_9 V_106 ;
int V_192 = 0 ;
bool V_310 , V_329 = true ;
if ( ! F_21 ( V_6 ) )
return false ;
F_31 ( & V_106 ) ;
V_36 = F_92 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
return false ;
V_27 = F_8 ( V_36 -> V_37 ) ;
V_310 = ! ! ( V_27 -> V_55 & V_56 ) ;
if ( ( V_310 && V_4 -> V_148 >= V_330 ) ||
( ! V_310 && V_4 -> V_147 >= V_331 ) ) {
* V_328 = true ;
return false ;
}
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( V_310 )
V_329 = F_95 ( V_2 , V_4 , V_6 , & V_106 , V_36 ,
V_20 , & V_192 ) ;
else
F_124 ( V_2 , V_4 , V_6 , & V_106 , V_36 , V_20 ) ;
if ( F_49 ( & V_106 ) )
return false ;
if ( V_6 -> V_8 -> V_141 || V_6 -> V_13 -> V_332 ) {
V_6 -> V_8 -> V_141 = false ;
V_27 -> V_55 |= V_187 ;
}
F_122 ( V_2 , V_36 , V_4 , V_192 ) ;
F_126 ( V_2 , V_4 , & V_106 , false ) ;
return true ;
}
int F_127 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_6 , T_1 * V_333 )
{
struct V_5 * V_334 ;
struct V_3 * V_4 ;
struct V_49 * V_13 ;
T_2 V_335 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_334 = F_20 ( V_13 , V_6 ) ;
V_4 = V_334 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_30 -> V_336 . V_337 ) {
V_13 -> V_165 = ( 1 << ( V_338 +
V_30 -> V_336 . V_339 ) ) - 1 ;
V_335 = F_128 ( V_30 -> V_336 . V_340 ) ;
V_13 -> V_183 = V_335 ;
}
F_25 ( V_2 , V_334 ) ;
V_334 -> V_134 = true ;
* V_333 = V_334 -> V_63 = V_334 -> V_341 ;
V_334 -> V_71 = - 1 ;
memset ( V_334 -> V_68 , 0 , sizeof( V_334 -> V_68 ) ) ;
V_334 -> V_66 = V_334 -> V_69 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 , struct V_34 * V_30 , T_1 V_6 )
{
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_5 * V_334 = F_20 ( V_13 , V_6 ) ;
struct V_3 * V_4 = V_334 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_334 -> V_134 = false ;
F_30 ( V_2 , V_334 ) ;
F_25 ( V_2 , V_334 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_130 ( struct V_34 * V_30 , struct V_1 * V_2 ,
struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_342 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_343 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_19 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_342 = F_21 ( V_6 ) ;
V_6 -> V_19 = false ;
F_52 ( & V_6 -> V_10 ) ;
if ( V_8 -> V_19 ) {
V_8 -> V_19 = false ;
F_52 ( & V_8 -> V_10 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_71 ( V_30 , V_22 , V_342 ) ;
}
}
void F_131 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_343 ; V_22 ++ , V_6 ++ ) {
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
void F_132 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_22 )
{
struct V_5 * V_6 ;
struct V_49 * V_13 ;
struct V_3 * V_4 ;
V_13 = (struct V_49 * ) V_30 -> V_15 ;
V_6 = F_20 ( V_13 , V_22 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_133 = V_344 << V_30 -> V_336 . V_339 ;
if ( F_21 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_133 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
T_1 V_345 , int V_95 ,
enum V_346 V_347 ,
bool V_348 )
{
struct V_1 * V_2 = V_47 -> V_349 ;
struct V_49 * V_13 = (struct V_49 * ) V_30 -> V_15 ;
struct V_3 * V_4 = V_2 -> V_42 . V_314 ;
struct V_26 * V_39 ;
struct V_9 V_106 ;
struct V_35 * V_350 = NULL , * V_36 ;
struct V_110 * V_20 ;
int V_351 = 0 ;
int V_124 ;
F_31 ( & V_106 ) ;
for ( V_124 = 0 ; V_345 && V_95 ; V_124 ++ , V_345 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_345 & 1 ) )
continue;
V_6 = F_20 ( V_13 , V_124 ) ;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_95 > 0 ) {
V_36 = F_92 ( V_2 , V_2 -> V_42 . V_314 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
F_28 ( V_36 -> V_37 , V_20 ) ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( F_76 ( V_36 ) ) {
F_38 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_62 . V_188 &= ~ V_190 ;
}
if ( V_350 )
V_350 -> V_105 = V_36 ;
V_350 = V_36 ;
V_95 -- ;
V_351 ++ ;
F_43 ( V_4 -> V_78 , V_352 ) ;
if ( V_13 -> V_30 && ! F_21 ( V_6 ) )
F_71 ( V_13 -> V_30 , V_124 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_49 ( & V_106 ) )
return;
V_39 = F_8 ( V_350 -> V_37 ) ;
V_39 -> V_55 |= V_138 ;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
F_1 ( V_2 , V_4 ) ;
F_122 ( V_2 , V_36 , V_4 , 0 ) ;
F_126 ( V_2 , V_4 , & V_106 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_134 ( struct V_1 * V_2 , int V_353 , int V_354 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_355 V_356 ;
static const int V_357 [] = {
[ V_358 ] = V_359 ,
[ V_360 ] = V_361 ,
[ V_362 ] = V_363 ,
[ V_364 ] = V_365 ,
} ;
int V_78 , V_124 ;
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
V_356 . V_366 = V_357 [ V_354 ] ;
V_356 . V_367 = V_368 ;
V_356 . V_369 = V_368 ;
V_356 . V_370 = V_368 ;
V_356 . V_371 = 0 ;
if ( V_230 -> V_91 . V_178 & V_179 ) {
V_356 . V_372 = V_373 ;
} else {
if ( V_353 == V_374 )
V_356 . V_372 = V_375 ;
else
V_356 . V_372 = V_376 |
V_375 ;
}
V_78 = F_135 ( V_230 , V_353 , & V_356 ) ;
if ( V_78 == - 1 ) {
return NULL ;
}
if ( ! F_136 ( V_2 , V_78 ) ) {
struct V_3 * V_4 = & V_2 -> V_42 . V_4 [ V_78 ] ;
V_4 -> V_78 = V_78 ;
V_4 -> V_157 = - 1 ;
V_4 -> V_377 = NULL ;
F_64 ( & V_4 -> V_378 ) ;
F_31 ( & V_4 -> V_379 ) ;
F_137 ( & V_4 -> V_380 ) ;
V_4 -> V_147 = 0 ;
V_4 -> V_148 = 0 ;
V_4 -> V_146 = false ;
V_2 -> V_42 . V_381 |= 1 << V_78 ;
V_4 -> V_382 = V_4 -> V_383 = 0 ;
for ( V_124 = 0 ; V_124 < V_384 ; V_124 ++ )
F_31 ( & V_4 -> V_385 [ V_124 ] ) ;
}
return & V_2 -> V_42 . V_4 [ V_78 ] ;
}
int F_138 ( struct V_1 * V_2 , int V_386 ,
struct V_355 * V_387 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
int error = 0 ;
struct V_355 V_356 ;
F_139 ( V_2 -> V_42 . V_4 [ V_386 ] . V_78 != V_386 ) ;
F_140 ( V_230 , V_386 , & V_356 ) ;
V_356 . V_367 = V_387 -> V_367 ;
V_356 . V_369 = V_387 -> V_369 ;
V_356 . V_370 = V_387 -> V_370 ;
V_356 . V_388 = V_387 -> V_388 ;
V_356 . V_389 = V_387 -> V_389 ;
if ( ! F_141 ( V_230 , V_386 , & V_356 ) ) {
F_142 ( F_113 ( V_2 -> V_90 ) ,
L_1 , V_386 ) ;
error = - V_390 ;
} else {
F_143 ( V_230 , V_386 ) ;
}
return error ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_355 V_356 ;
struct V_391 * V_392 = & V_2 -> V_393 -> V_394 ;
int V_386 = V_2 -> V_394 . V_395 -> V_78 ;
F_140 ( V_2 -> V_90 , V_386 , & V_356 ) ;
V_356 . V_389 = ( F_145 ( V_392 -> V_396 ) *
V_397 ) / 100 ;
F_138 ( V_2 , V_386 , & V_356 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_35 * V_36 , * V_398 ;
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
V_398 = V_36 -> V_109 ;
F_147 ( & V_57 , V_10 , & V_398 -> V_10 ) ;
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
}
void F_148 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 ) {
int V_150 = V_4 -> V_383 ;
while ( ! F_49 ( & V_4 -> V_385 [ V_150 ] ) ) {
F_146 ( V_2 , V_4 , & V_4 -> V_385 [ V_150 ] ) ;
F_37 ( V_150 , V_384 ) ;
}
V_4 -> V_383 = V_150 ;
}
V_4 -> V_377 = NULL ;
V_4 -> V_146 = false ;
F_146 ( V_2 , V_4 , & V_4 -> V_379 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_149 ( struct V_1 * V_2 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_3 * V_4 ;
int V_124 ;
V_98 V_399 = 0 ;
if ( F_36 ( V_400 , & V_264 -> V_401 ) )
return true ;
F_150 ( V_230 ) ;
for ( V_124 = 0 ; V_124 < V_402 ; V_124 ++ ) {
if ( ! F_136 ( V_2 , V_124 ) )
continue;
if ( ! V_2 -> V_42 . V_4 [ V_124 ] . V_147 )
continue;
if ( F_151 ( V_230 , V_2 -> V_42 . V_4 [ V_124 ] . V_78 ) )
V_399 |= F_152 ( V_124 ) ;
}
if ( V_399 )
F_142 ( V_264 , L_2 , V_399 ) ;
for ( V_124 = 0 ; V_124 < V_402 ; V_124 ++ ) {
if ( ! F_136 ( V_2 , V_124 ) )
continue;
V_4 = & V_2 -> V_42 . V_4 [ V_124 ] ;
V_4 -> V_45 = false ;
F_148 ( V_2 , V_4 ) ;
}
return ! V_399 ;
}
void F_153 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_154 ( V_2 -> V_90 , V_4 -> V_78 ) ;
V_2 -> V_42 . V_381 &= ~ ( 1 << V_4 -> V_78 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_7 * V_8 , * V_403 ;
struct V_5 * V_6 , * V_404 ;
struct V_9 * V_405 ;
bool V_351 = false ;
if ( V_4 -> V_157 < 0 )
return;
if ( F_36 ( V_406 , & V_264 -> V_401 ) )
return;
F_47 ( & V_2 -> V_407 ) ;
V_405 = & V_2 -> V_393 -> V_21 [ V_4 -> V_157 ] ;
if ( F_49 ( V_405 ) ) {
F_50 ( & V_2 -> V_407 ) ;
return;
}
F_60 () ;
V_403 = F_155 ( V_405 -> V_76 , struct V_7 , V_10 ) ;
while ( ! F_49 ( V_405 ) ) {
bool V_328 = false ;
if ( V_2 -> V_393 -> V_45 )
break;
V_8 = F_51 ( V_405 , struct V_7 , V_10 ) ;
V_404 = F_155 ( V_8 -> V_20 . V_76 , struct V_5 , V_10 ) ;
F_52 ( & V_8 -> V_10 ) ;
V_8 -> V_19 = false ;
while ( ! F_49 ( & V_8 -> V_20 ) ) {
V_6 = F_51 ( & V_8 -> V_20 , struct V_5 ,
V_10 ) ;
F_52 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
if ( F_125 ( V_2 , V_4 , V_6 , & V_328 ) )
V_351 = true ;
if ( F_21 ( V_6 ) )
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_328 || V_6 == V_404 )
break;
}
if ( ! F_49 ( & V_8 -> V_20 ) && ! V_8 -> V_19 ) {
V_8 -> V_19 = true ;
F_5 ( & V_8 -> V_10 , V_405 ) ;
}
if ( V_328 )
break;
if ( V_8 == V_403 ) {
if ( ! V_351 )
break;
V_351 = false ;
V_403 = F_155 ( V_405 -> V_76 ,
struct V_7 , V_10 ) ;
}
}
F_62 () ;
F_50 ( & V_2 -> V_407 ) ;
}
void F_156 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_408 ; V_124 ++ ) {
V_4 = V_2 -> V_42 . V_43 [ V_124 ] ;
F_47 ( & V_4 -> V_380 ) ;
F_79 ( V_2 , V_4 ) ;
F_50 ( & V_4 -> V_380 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_409 , bool V_410 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_263 * V_264 = F_113 ( V_230 ) ;
struct V_35 * V_36 , * V_108 ;
bool V_411 = false ;
bool V_412 ;
if ( F_49 ( V_409 ) )
return;
V_412 = ! ! ( V_230 -> V_91 . V_178 & V_179 ) ;
V_36 = F_51 ( V_409 , struct V_35 , V_10 ) ;
V_108 = F_155 ( V_409 -> V_76 , struct V_35 , V_10 ) ;
F_157 ( V_264 , V_413 , L_3 ,
V_4 -> V_78 , V_4 -> V_147 ) ;
if ( V_412 && F_49 ( & V_4 -> V_385 [ V_4 -> V_382 ] ) ) {
F_158 ( V_409 , & V_4 -> V_385 [ V_4 -> V_382 ] ) ;
F_37 ( V_4 -> V_382 , V_384 ) ;
V_411 = true ;
} else {
F_158 ( V_409 , & V_4 -> V_379 ) ;
if ( V_4 -> V_377 ) {
F_159 ( V_230 , V_4 -> V_377 , V_36 -> V_312 ) ;
F_157 ( V_264 , V_414 , L_4 ,
V_4 -> V_78 , V_4 -> V_377 ,
F_160 ( V_36 -> V_312 ) , V_36 -> V_89 ) ;
} else if ( ! V_412 )
V_411 = true ;
V_4 -> V_377 = V_108 -> V_89 ;
}
if ( V_411 ) {
F_43 ( V_4 -> V_78 , V_411 ) ;
F_161 ( V_230 , V_4 -> V_78 , V_36 -> V_312 ) ;
F_157 ( V_264 , V_414 , L_5 ,
V_4 -> V_78 , F_160 ( V_36 -> V_312 ) , V_36 -> V_89 ) ;
}
if ( ! V_412 || V_2 -> V_231 ) {
F_43 ( V_4 -> V_78 , V_415 ) ;
F_162 ( V_230 , V_4 -> V_78 ) ;
}
if ( ! V_410 ) {
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
static void F_163 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_122 ( V_2 , V_36 , V_4 , V_40 -> V_199 ) ;
F_126 ( V_2 , V_4 , & V_57 , false ) ;
F_43 ( V_4 -> V_78 , V_416 ) ;
}
static void F_164 ( struct V_107 * V_47 ,
struct V_34 * V_30 ,
struct V_24 * V_25 ,
int V_199 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_417 * V_418 = V_27 -> V_137 . V_418 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
const struct V_265 * V_266 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_49 * V_13 = NULL ;
enum V_419 V_324 ;
bool V_420 = false ;
T_2 V_234 ;
if ( V_27 -> V_137 . V_14 &&
V_27 -> V_137 . V_14 -> V_421 . V_422 )
V_420 = true ;
V_266 = F_165 ( V_47 , V_27 ) ;
V_324 = F_166 ( V_25 ) ;
if ( V_30 )
V_13 = (struct V_49 * ) V_30 -> V_15 ;
if ( V_27 -> V_137 . V_14 ) {
struct V_33 * V_14 = V_27 -> V_137 . V_14 ;
V_234 = 2 * V_14 -> V_421 . V_234 ;
} else {
struct V_1 * V_2 = V_47 -> V_349 ;
V_234 = V_2 -> V_393 -> V_423 ;
}
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_4 = - 1 ;
if ( V_418 )
V_40 -> V_176 = V_418 -> V_424 ;
else if ( V_13 && F_167 ( V_75 -> V_81 ) && V_13 -> V_425 > 0 )
V_40 -> V_176 = V_13 -> V_425 ;
else
V_40 -> V_176 = V_177 ;
V_40 -> V_324 = V_324 ;
V_40 -> V_199 = V_199 ;
V_40 -> V_235 = V_234 ;
if ( ! V_266 )
return;
V_40 -> V_271 = V_266 -> V_295 ;
if ( V_420 )
V_40 -> V_271 |= V_266 -> V_296 ;
}
T_2 F_115 ( struct V_1 * V_2 , T_2 V_426 , V_98 V_266 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_427 * V_428 = V_230 -> V_428 ;
if ( ( V_230 -> V_91 . V_178 & V_429 ) && F_168 ( V_428 ) &&
( V_426 == 0x7 ) && ( V_266 < 0x90 ) )
return 0x3 ;
else if ( F_169 ( V_230 ) && F_170 ( V_230 ) &&
F_117 ( V_266 ) )
return 0x2 ;
else
return V_426 ;
}
static struct V_35 * F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_35 * V_36 ;
int V_430 ;
T_1 V_29 ;
V_36 = F_46 ( V_2 ) ;
if ( ! V_36 ) {
F_157 ( V_264 , V_414 , L_6 ) ;
return NULL ;
}
F_55 ( V_36 ) ;
if ( V_6 && F_171 ( V_75 -> V_81 ) ) {
V_430 = F_172 ( V_75 -> V_431 ) & V_432 ;
V_29 = V_6 -> V_341 ;
V_75 -> V_431 = F_44 ( V_6 -> V_341 << V_32 ) ;
if ( V_430 )
V_75 -> V_431 |= F_44 ( V_430 ) ;
if ( ! F_173 ( V_75 -> V_81 ) )
F_37 ( V_6 -> V_341 , V_70 ) ;
V_36 -> V_62 . V_29 = V_29 ;
}
V_36 -> V_37 = V_25 ;
V_36 -> V_84 = F_174 ( V_2 -> V_83 , V_25 -> V_80 ,
V_25 -> V_261 , V_85 ) ;
if ( F_48 ( F_175 ( V_2 -> V_83 , V_36 -> V_84 ) ) ) {
V_36 -> V_37 = NULL ;
V_36 -> V_84 = 0 ;
F_142 ( F_113 ( V_2 -> V_90 ) ,
L_7 ) ;
F_53 ( V_2 , V_36 ) ;
return NULL ;
}
V_40 -> V_36 = V_36 ;
return V_36 ;
}
void F_176 ( struct V_263 * V_264 , struct V_24 * V_25 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
if ( ! ( V_39 -> V_55 & V_433 ) )
return;
if ( ! V_14 )
return;
V_12 = (struct V_11 * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_434 )
V_12 -> V_435 += 0x10 ;
V_75 -> V_431 &= F_44 ( V_432 ) ;
V_75 -> V_431 |= F_44 ( V_12 -> V_435 ) ;
}
static int F_177 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_436 * V_437 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_437 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_47 -> V_349 ;
int V_153 = V_25 -> V_261 + V_438 ;
int V_439 , V_440 ;
if ( V_30 )
V_437 -> V_13 = (struct V_49 * ) V_30 -> V_15 ;
else if ( V_14 && F_167 ( V_75 -> V_81 ) ) {
V_12 = ( void * ) V_14 -> V_15 ;
V_437 -> V_13 = & V_12 -> V_441 ;
}
if ( V_39 -> V_137 . V_418 )
V_153 += V_39 -> V_137 . V_418 -> V_442 ;
F_176 ( F_113 ( V_2 -> V_90 ) , V_25 ) ;
if ( ( V_14 && V_14 -> type != V_443 &&
V_14 -> type != V_444 ) ||
! F_167 ( V_75 -> V_81 ) )
V_39 -> V_55 |= V_187 ;
V_439 = F_178 ( V_75 -> V_81 ) ;
V_440 = V_439 & 3 ;
if ( V_440 && V_25 -> V_261 > V_439 ) {
if ( F_179 ( V_25 ) < V_440 )
return - V_445 ;
F_180 ( V_25 , V_440 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_440 , V_439 ) ;
}
F_164 ( V_47 , V_30 , V_25 , V_153 ) ;
return 0 ;
}
int F_181 ( struct V_107 * V_47 , struct V_24 * V_25 ,
struct V_436 * V_437 )
{
struct V_74 * V_75 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_437 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_137 . V_14 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_11 * V_12 = NULL ;
struct V_1 * V_2 = V_47 -> V_349 ;
struct V_3 * V_4 = V_437 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_36 ;
bool V_217 , V_446 = false , V_447 ;
int V_41 , V_448 ;
if ( V_14 )
V_12 = ( void * ) V_14 -> V_15 ;
if ( V_39 -> V_55 & V_449 )
V_437 -> V_450 = true ;
V_447 = ! ! ( V_39 -> V_137 . V_55 & V_451 ) ;
V_448 = F_177 ( V_47 , V_25 , V_437 ) ;
if ( V_448 )
return V_448 ;
V_75 = (struct V_74 * ) V_25 -> V_80 ;
V_41 = F_182 ( V_25 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_42 . V_43 [ V_41 ] ) {
V_40 -> V_4 = V_41 ;
if ( ++ V_4 -> V_44 > V_2 -> V_42 . V_46 [ V_41 ] &&
! V_4 -> V_45 ) {
if ( F_17 () )
F_183 ( V_2 -> V_47 , V_39 -> V_48 ) ;
else
F_183 ( V_2 -> V_47 , V_41 ) ;
V_4 -> V_45 = true ;
}
}
V_217 = F_171 ( V_75 -> V_81 ) ;
if ( ( ( V_12 && V_12 -> V_18 != V_2 -> V_393 ) ||
V_2 -> V_393 -> V_45 ) && ! V_437 -> V_450 ) {
if ( ! V_437 -> V_13 )
V_437 -> V_13 = & V_12 -> V_441 ;
V_217 = true ;
V_446 = true ;
}
if ( V_437 -> V_13 && V_217 )
V_6 = F_19 ( V_2 , V_437 -> V_13 , V_25 ) ;
if ( ! V_446 && V_447 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_42 . V_314 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_437 -> V_13 && V_217 ) {
F_16 ( V_6 -> V_8 -> V_4 != V_437 -> V_4 ) ;
if ( V_39 -> V_55 & V_187 )
V_6 -> V_8 -> V_141 = true ;
F_43 ( V_4 -> V_78 , V_452 ) ;
F_70 ( & V_6 -> V_52 , V_25 ) ;
if ( ! V_437 -> V_13 -> V_136 )
F_4 ( V_2 , V_4 , V_6 ) ;
F_79 ( V_2 , V_4 ) ;
goto V_453;
}
V_36 = F_27 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
if ( V_437 -> V_454 )
F_184 ( V_25 ) ;
else
F_29 ( V_2 -> V_47 , V_25 ) ;
goto V_453;
}
V_36 -> V_62 . V_256 = V_437 -> V_454 ;
if ( V_437 -> V_454 )
V_36 -> V_62 . V_455 = V_456 ;
F_12 ( V_14 , V_30 , V_36 ) ;
F_163 ( V_2 , V_4 , V_6 , V_25 ) ;
V_453:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_185 ( struct V_107 * V_47 , struct V_33 * V_14 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_47 -> V_349 ;
struct V_436 V_437 = {
. V_4 = V_2 -> V_394 . V_395
} ;
struct V_260 V_39 = {} ;
struct V_74 * V_75 ;
struct V_35 * V_350 = NULL ;
struct V_35 * V_36 ;
F_186 ( V_106 ) ;
int V_149 = 0 ;
int V_457 ;
V_457 =
V_2 -> V_393 -> V_394 . V_396 * 1000 *
V_2 -> V_393 -> V_394 . V_458 / V_459 ;
do {
struct V_23 * V_40 = F_7 ( V_25 ) ;
if ( F_177 ( V_47 , V_25 , & V_437 ) )
break;
V_36 = F_27 ( V_2 , V_437 . V_4 , NULL , V_25 ) ;
if ( ! V_36 )
break;
V_36 -> V_109 = V_36 ;
F_12 ( V_14 , NULL , V_36 ) ;
F_112 ( V_2 , V_36 , & V_39 , V_40 -> V_199 , false ) ;
V_149 += V_39 . V_38 [ 0 ] . V_288 ;
if ( V_350 )
V_350 -> V_105 = V_36 ;
F_5 ( & V_36 -> V_10 , & V_106 ) ;
V_350 = V_36 ;
V_25 = NULL ;
if ( V_149 > V_457 )
break;
V_25 = F_187 ( V_47 , V_14 ) ;
} while( V_25 );
if ( V_25 )
F_29 ( V_47 , V_25 ) ;
if ( F_49 ( & V_106 ) )
return;
V_36 = F_51 ( & V_106 , struct V_35 , V_10 ) ;
V_75 = (struct V_74 * ) V_36 -> V_37 -> V_80 ;
if ( V_75 -> V_81 & V_460 ) {
V_75 -> V_81 &= ~ V_460 ;
F_45 ( V_2 -> V_83 , V_36 -> V_84 ,
sizeof( * V_75 ) , V_85 ) ;
}
F_1 ( V_2 , V_437 . V_4 ) ;
F_122 ( V_2 , V_36 , V_437 . V_4 , 0 ) ;
F_126 ( V_2 , V_437 . V_4 , & V_106 , false ) ;
F_43 ( V_437 . V_4 -> V_78 , V_416 ) ;
F_2 ( V_2 , V_437 . V_4 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_24 * V_25 ,
int V_461 , struct V_3 * V_4 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
int V_439 , V_440 ;
unsigned long V_55 ;
F_157 ( V_264 , V_414 , L_8 , V_25 ) ;
if ( V_2 -> V_90 -> V_462 )
F_188 ( V_463 , & V_2 -> V_90 -> V_462 -> V_464 ) ;
if ( ! ( V_461 & V_72 ) ) {
if ( V_27 -> V_55 & V_316 )
V_27 -> V_55 |= V_465 ;
else
V_27 -> V_55 |= V_466 ;
}
V_439 = F_178 ( V_75 -> V_81 ) ;
V_440 = V_439 & 3 ;
if ( V_440 && V_25 -> V_261 > V_439 + V_440 ) {
memmove ( V_25 -> V_80 + V_440 , V_25 -> V_80 , V_439 ) ;
F_189 ( V_25 , V_440 ) ;
}
F_190 ( & V_2 -> V_467 , V_55 ) ;
if ( ( V_2 -> V_468 & V_469 ) && ! V_4 -> V_147 ) {
V_2 -> V_468 &= ~ V_469 ;
F_157 ( V_264 , V_470 ,
L_9 ,
V_2 -> V_468 & ( V_471 |
V_472 |
V_473 |
V_469 ) ) ;
}
F_191 ( & V_2 -> V_467 , V_55 ) ;
F_70 ( & V_4 -> V_378 , V_25 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_9 * V_106 ,
struct V_58 * V_59 , int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
unsigned long V_55 ;
int V_461 = 0 ;
if ( ! V_94 )
V_461 |= V_72 ;
if ( V_59 -> V_122 & V_139 )
V_27 -> V_55 |= V_474 ;
F_192 ( V_2 -> V_83 , V_36 -> V_84 , V_25 -> V_261 , V_85 ) ;
V_36 -> V_84 = 0 ;
if ( V_2 -> V_231 )
goto V_475;
if ( V_36 -> V_62 . V_256 ) {
if ( F_193 ( V_456 ,
V_36 -> V_62 . V_455 +
F_194 ( V_476 ) ) )
F_184 ( V_25 ) ;
else
F_195 ( & V_2 -> V_477 ) ;
} else {
F_196 ( V_2 , V_36 , V_59 , V_4 , V_461 ) ;
F_41 ( V_2 , V_25 , V_461 , V_4 ) ;
}
V_475:
V_36 -> V_37 = NULL ;
F_190 ( & V_2 -> V_42 . V_86 , V_55 ) ;
F_158 ( V_106 , & V_2 -> V_42 . V_87 ) ;
F_191 ( & V_2 -> V_42 . V_86 , V_55 ) ;
}
static void F_67 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_58 * V_59 , int V_95 , int V_96 ,
int V_94 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_107 * V_47 = V_2 -> V_47 ;
struct V_229 * V_230 = V_2 -> V_90 ;
T_2 V_124 , V_478 ;
if ( V_94 )
V_27 -> V_479 . V_480 = V_59 -> V_481 ;
V_478 = V_59 -> V_126 ;
F_16 ( V_478 >= V_47 -> V_482 ) ;
if ( V_27 -> V_55 & V_56 ) {
V_27 -> V_55 |= V_483 ;
F_139 ( V_96 > V_95 ) ;
}
V_27 -> V_479 . V_484 = V_95 ;
V_27 -> V_479 . V_485 = V_95 - V_96 ;
if ( ( V_59 -> V_122 & V_139 ) == 0 &&
( V_27 -> V_55 & V_316 ) == 0 ) {
if ( F_48 ( V_59 -> V_129 & ( V_486 |
V_487 ) ) &&
F_167 ( V_75 -> V_81 ) &&
V_230 -> V_488 >= V_2 -> V_90 -> V_489 . V_490 )
V_27 -> V_479 . V_38 [ V_478 ] . V_73 =
V_47 -> V_491 ;
}
for ( V_124 = V_478 + 1 ; V_124 < V_47 -> V_482 ; V_124 ++ ) {
V_27 -> V_479 . V_38 [ V_124 ] . V_73 = 0 ;
V_27 -> V_479 . V_38 [ V_124 ] . V_150 = - 1 ;
}
V_27 -> V_479 . V_38 [ V_478 ] . V_73 = V_59 -> V_125 + 1 ;
}
static void F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_263 * V_264 = F_113 ( V_230 ) ;
struct V_35 * V_36 , * V_398 , * V_492 = NULL ;
struct V_9 V_57 ;
struct V_493 * V_494 ;
struct V_58 V_59 ;
int V_479 ;
F_157 ( V_264 , V_413 , L_10 ,
V_4 -> V_78 , F_198 ( V_2 -> V_90 , V_4 -> V_78 ) ,
V_4 -> V_377 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_36 ( V_406 , & V_264 -> V_401 ) )
break;
if ( F_49 ( & V_4 -> V_379 ) ) {
V_4 -> V_377 = NULL ;
F_79 ( V_2 , V_4 ) ;
break;
}
V_36 = F_51 ( & V_4 -> V_379 , struct V_35 , V_10 ) ;
V_492 = NULL ;
if ( V_36 -> V_62 . V_93 ) {
V_492 = V_36 ;
if ( F_199 ( & V_492 -> V_10 , & V_4 -> V_379 ) )
break;
V_36 = F_155 ( V_492 -> V_10 . V_495 , struct V_35 ,
V_10 ) ;
}
V_398 = V_36 -> V_109 ;
V_494 = V_398 -> V_89 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_479 = F_200 ( V_230 , V_494 , & V_59 ) ;
if ( V_479 == - V_496 )
break;
F_43 ( V_4 -> V_78 , V_497 ) ;
V_398 -> V_62 . V_93 = true ;
F_31 ( & V_57 ) ;
if ( ! F_201 ( & V_398 -> V_10 ) )
F_147 ( & V_57 ,
& V_4 -> V_379 , V_398 -> V_10 . V_76 ) ;
if ( V_492 ) {
F_52 ( & V_492 -> V_10 ) ;
F_53 ( V_2 , V_492 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_202 ( struct V_1 * V_2 )
{
struct V_229 * V_230 = V_2 -> V_90 ;
V_98 V_498 = ( ( 1 << V_402 ) - 1 ) & V_230 -> V_499 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_402 ; V_124 ++ ) {
if ( F_136 ( V_2 , V_124 ) && ( V_498 & ( 1 << V_124 ) ) )
F_197 ( V_2 , & V_2 -> V_42 . V_4 [ V_124 ] ) ;
}
}
void F_203 ( struct V_1 * V_2 )
{
struct V_58 V_59 ;
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_229 * V_230 = V_2 -> V_90 ;
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_398 ;
struct V_9 V_57 ;
struct V_9 * V_500 ;
int V_479 ;
for (; ; ) {
if ( F_36 ( V_406 , & V_264 -> V_401 ) )
break;
V_479 = F_200 ( V_230 , NULL , ( void * ) & V_59 ) ;
if ( V_479 == - V_496 )
break;
if ( V_479 == - V_390 ) {
F_157 ( V_264 , V_414 , L_11 ) ;
break;
}
if ( V_59 . V_501 == V_2 -> V_394 . V_502 ) {
V_2 -> V_394 . V_503 = true ;
V_2 -> V_394 . V_504 = ! ( V_59 . V_122 & V_145 ) ;
if ( F_17 () ) {
F_204 ( V_2 , NULL ,
V_505 ) ;
}
F_205 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_42 . V_4 [ V_59 . V_501 ] ;
F_1 ( V_2 , V_4 ) ;
F_43 ( V_4 -> V_78 , V_497 ) ;
V_500 = & V_4 -> V_385 [ V_4 -> V_383 ] ;
if ( F_49 ( V_500 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_36 = F_51 ( V_500 , struct V_35 , V_10 ) ;
if ( V_36 -> V_62 . V_93 ) {
F_52 ( & V_36 -> V_10 ) ;
F_53 ( V_2 , V_36 ) ;
V_36 = F_51 ( V_500 , struct V_35 , V_10 ) ;
}
V_398 = V_36 -> V_109 ;
F_31 ( & V_57 ) ;
if ( F_199 ( & V_398 -> V_10 , V_500 ) ) {
F_158 ( V_500 , & V_57 ) ;
F_37 ( V_4 -> V_383 , V_384 ) ;
if ( ! F_49 ( & V_4 -> V_379 ) ) {
struct V_9 V_106 ;
F_31 ( & V_106 ) ;
V_4 -> V_377 = NULL ;
F_158 ( & V_4 -> V_379 , & V_106 ) ;
F_126 ( V_2 , V_4 , & V_106 , true ) ;
}
} else {
V_398 -> V_62 . V_93 = true ;
if ( V_36 != V_398 )
F_147 ( & V_57 , V_500 ,
V_398 -> V_10 . V_76 ) ;
}
F_77 ( V_2 , V_4 , & V_59 , V_36 , & V_57 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_206 ( struct V_1 * V_2 , int V_506 )
{
struct V_507 * V_508 = & V_2 -> V_509 ;
T_2 V_510 = V_2 -> V_90 -> V_91 . V_510 ;
V_508 -> V_511 = V_506 * V_510 ;
V_508 -> V_512 = F_207 ( V_2 -> V_83 , V_508 -> V_511 ,
& V_508 -> V_513 , V_514 ) ;
if ( ! V_508 -> V_512 )
return - V_445 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 )
{
int V_515 ;
V_515 = F_206 ( V_2 , V_516 ) ;
if ( ! V_515 )
F_209 ( V_2 -> V_90 , V_2 -> V_509 . V_512 ,
V_2 -> V_509 . V_513 ,
V_516 ) ;
return V_515 ;
}
int F_210 ( struct V_1 * V_2 , int V_517 )
{
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
int error = 0 ;
F_137 ( & V_2 -> V_42 . V_86 ) ;
error = F_211 ( V_2 , & V_2 -> V_42 . V_518 , & V_2 -> V_42 . V_87 ,
L_12 , V_517 , 1 , 1 ) ;
if ( error != 0 ) {
F_142 ( V_264 ,
L_13 , error ) ;
return error ;
}
error = F_211 ( V_2 , & V_2 -> V_394 . V_519 , & V_2 -> V_394 . V_520 ,
L_14 , V_459 , 1 , 1 ) ;
if ( error != 0 ) {
F_142 ( V_264 ,
L_15 , error ) ;
return error ;
}
F_212 ( & V_2 -> V_521 , V_522 ) ;
if ( V_2 -> V_90 -> V_91 . V_178 & V_179 )
error = F_208 ( V_2 ) ;
return error ;
}
void F_213 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_22 , V_523 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_343 ;
V_22 ++ , V_6 ++ ) {
V_6 -> V_13 = V_13 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_63 = V_6 -> V_341 = 0 ;
V_6 -> V_133 = V_524 ;
V_6 -> V_66 = V_6 -> V_69 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_134 = false ;
F_64 ( & V_6 -> V_52 ) ;
F_64 ( & V_6 -> V_53 ) ;
V_523 = F_6 ( V_22 ) ;
V_6 -> V_8 = & V_13 -> V_8 [ V_523 ] ;
}
for ( V_523 = 0 , V_8 = & V_13 -> V_8 [ V_523 ] ;
V_523 < V_408 ; V_523 ++ , V_8 ++ ) {
V_8 -> V_19 = false ;
V_8 -> V_141 = true ;
V_8 -> V_4 = V_2 -> V_42 . V_43 [ V_523 ] ;
F_31 ( & V_8 -> V_20 ) ;
}
}
void F_214 ( struct V_1 * V_2 , struct V_49 * V_13 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_343 ; V_22 ++ , V_6 ++ ) {
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
int F_215 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_436 * V_437 )
{
struct V_74 * V_75 = (struct V_74 * ) V_25 -> V_80 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_263 * V_264 = F_113 ( V_2 -> V_90 ) ;
struct V_35 * V_36 ;
int V_439 , V_440 ;
V_439 = F_178 ( V_75 -> V_81 ) ;
V_440 = V_439 & 3 ;
if ( V_440 && V_25 -> V_261 > V_439 ) {
if ( F_179 ( V_25 ) < V_440 ) {
F_157 ( V_264 , V_414 ,
L_16 ) ;
return - V_525 ;
}
F_180 ( V_25 , V_440 ) ;
memmove ( V_25 -> V_80 , V_25 -> V_80 + V_440 , V_439 ) ;
}
V_40 -> V_176 = V_177 ;
V_40 -> V_199 = V_25 -> V_261 + V_438 ;
V_40 -> V_324 = V_526 ;
V_36 = F_27 ( V_2 , V_437 -> V_4 , NULL , V_25 ) ;
if ( ! V_36 ) {
F_157 ( V_264 , V_414 , L_17 ) ;
return - V_525 ;
}
F_12 ( V_2 -> V_527 , NULL , V_36 ) ;
F_159 ( V_2 -> V_90 , V_36 -> V_89 , V_36 -> V_312 ) ;
F_216 ( V_2 -> V_90 , V_437 -> V_4 -> V_78 ) ;
F_163 ( V_2 , V_437 -> V_4 , NULL , V_25 ) ;
return 0 ;
}
