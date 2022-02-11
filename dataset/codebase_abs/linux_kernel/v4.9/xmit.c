static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_9 . V_10 [ 0 ] ;
if ( V_6 -> V_11 & V_12 ) {
F_3 ( V_2 , V_4 ) ;
return;
}
if ( V_8 )
F_4 ( V_2 , V_8 , V_6 ) ;
F_5 ( V_4 ) ;
}
void F_6 ( struct V_13 * V_14 , struct V_15 * V_16 )
__acquires( &txq->axq_lock
void F_7 ( struct V_13 * V_14 , struct V_15 * V_16 )
__releases( &txq->axq_lock
void F_8 ( struct V_13 * V_14 , struct V_15 * V_16 )
__releases( &txq->axq_lock
static void F_9 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_18 -> V_23 -> V_24 -> V_25 ;
struct V_26 * V_27 = V_22 -> V_28 ;
if ( ! V_27 )
return;
V_20 = & V_27 -> V_29 [ F_10 ( V_18 -> V_30 ) ] ;
if ( F_11 ( & V_18 -> V_20 ) )
F_12 ( & V_18 -> V_20 , V_20 ) ;
}
static struct V_31 * F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_32 = F_2 ( V_4 ) ;
F_14 ( sizeof( struct V_31 ) >
sizeof( V_32 -> V_33 ) ) ;
return (struct V_31 * ) & V_32 -> V_33 [ 0 ] ;
}
static void F_15 ( struct V_17 * V_18 , T_1 V_34 )
{
if ( ! V_18 -> V_23 -> V_8 )
return;
F_16 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 -> V_35 , V_18 -> V_30 ,
V_34 << V_36 ) ;
}
static void F_17 ( struct V_37 * V_24 , struct V_7 * V_8 ,
struct V_38 * V_39 )
{
F_18 ( V_24 , V_8 , V_39 -> V_40 , V_39 -> V_41 ,
F_19 ( V_39 -> V_41 ) ) ;
}
static void F_20 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
int V_43 = V_42 -> V_16 ;
if ( V_43 < 0 )
return;
V_16 = V_14 -> V_44 . V_45 [ V_43 ] ;
if ( F_21 ( -- V_16 -> V_46 < 0 ) )
V_16 -> V_46 = 0 ;
if ( V_16 -> V_47 &&
V_16 -> V_46 < V_14 -> V_44 . V_48 [ V_43 ] ) {
if ( F_22 () )
F_23 ( V_14 -> V_2 , V_6 -> V_49 ) ;
else
F_23 ( V_14 -> V_2 , V_43 ) ;
V_16 -> V_47 = false ;
}
}
static struct V_17 *
F_24 ( struct V_13 * V_14 , struct V_50 * V_23 , struct V_3 * V_4 )
{
T_2 V_30 = V_4 -> V_51 & V_52 ;
return F_25 ( V_23 , V_30 ) ;
}
static bool F_26 ( struct V_17 * V_18 )
{
return ! F_27 ( & V_18 -> V_53 ) || ! F_27 ( & V_18 -> V_54 ) ;
}
static struct V_3 * F_28 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
V_4 = F_29 ( & V_18 -> V_54 ) ;
if ( ! V_4 )
V_4 = F_29 ( & V_18 -> V_53 ) ;
return V_4 ;
}
static void
F_30 ( struct V_13 * V_14 , struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_16 ;
struct V_5 * V_32 ;
struct V_3 * V_4 , * V_55 ;
struct V_38 * V_39 ;
struct V_31 * V_42 ;
F_31 (&tid->buf_q, skb, tskb) {
V_42 = F_13 ( V_4 ) ;
V_39 = V_42 -> V_39 ;
V_32 = F_2 ( V_4 ) ;
V_32 -> V_11 &= ~ V_56 ;
if ( V_39 )
continue;
V_39 = F_32 ( V_14 , V_16 , V_18 , V_4 ) ;
if ( ! V_39 ) {
F_33 ( V_4 , & V_18 -> V_53 ) ;
F_20 ( V_14 , V_16 , V_4 ) ;
F_34 ( V_14 -> V_2 , V_4 ) ;
continue;
}
}
}
static void F_35 ( struct V_13 * V_14 , struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_16 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
struct V_19 V_57 ;
struct F_1 V_58 ;
struct V_31 * V_42 ;
bool V_59 = false ;
F_36 ( & V_57 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
while ( ( V_4 = F_29 ( & V_18 -> V_54 ) ) ) {
V_42 = F_13 ( V_4 ) ;
V_39 = V_42 -> V_39 ;
if ( ! V_39 ) {
F_20 ( V_14 , V_16 , V_4 ) ;
F_34 ( V_14 -> V_2 , V_4 ) ;
continue;
}
if ( V_42 -> V_60 ) {
F_37 ( V_14 , V_18 , V_39 -> V_61 . V_34 ) ;
V_59 = true ;
}
F_12 ( & V_39 -> V_20 , & V_57 ) ;
F_38 ( V_14 , V_39 , V_16 , & V_57 , NULL , & V_58 , 0 ) ;
}
if ( V_59 ) {
F_7 ( V_14 , V_16 ) ;
F_15 ( V_18 , V_18 -> V_62 ) ;
F_6 ( V_14 , V_16 ) ;
}
}
static void F_37 ( struct V_13 * V_14 , struct V_17 * V_18 ,
int V_34 )
{
int V_63 , V_64 ;
V_63 = F_39 ( V_18 -> V_62 , V_34 ) ;
V_64 = ( V_18 -> V_65 + V_63 ) & ( V_66 - 1 ) ;
F_40 ( V_64 , V_18 -> V_67 ) ;
while ( V_18 -> V_65 != V_18 -> V_68 && ! F_41 ( V_18 -> V_65 , V_18 -> V_67 ) ) {
F_42 ( V_18 -> V_62 , V_69 ) ;
F_42 ( V_18 -> V_65 , V_66 ) ;
if ( V_18 -> V_70 >= 0 )
V_18 -> V_70 -- ;
}
}
static void F_43 ( struct V_13 * V_14 , struct V_17 * V_18 ,
struct V_38 * V_39 )
{
struct V_31 * V_42 = F_13 ( V_39 -> V_40 ) ;
T_1 V_34 = V_39 -> V_61 . V_34 ;
int V_63 , V_64 ;
V_63 = F_39 ( V_18 -> V_62 , V_34 ) ;
V_64 = ( V_18 -> V_65 + V_63 ) & ( V_66 - 1 ) ;
F_44 ( V_64 , V_18 -> V_67 ) ;
V_42 -> V_60 = 1 ;
if ( V_63 >= ( ( V_18 -> V_68 - V_18 -> V_65 ) &
( V_66 - 1 ) ) ) {
V_18 -> V_68 = V_64 ;
F_42 ( V_18 -> V_68 , V_66 ) ;
}
}
static void F_45 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_38 * V_39 ;
struct V_19 V_57 ;
struct F_1 V_58 ;
struct V_31 * V_42 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_36 ( & V_57 ) ;
while ( ( V_4 = F_28 ( V_18 ) ) ) {
V_42 = F_13 ( V_4 ) ;
V_39 = V_42 -> V_39 ;
if ( ! V_39 ) {
F_46 ( V_14 , V_4 , V_71 , V_16 , NULL ) ;
continue;
}
F_12 ( & V_39 -> V_20 , & V_57 ) ;
F_38 ( V_14 , V_39 , V_16 , & V_57 , NULL , & V_58 , 0 ) ;
}
}
static void F_47 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_3 * V_4 , int V_72 )
{
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_38 * V_39 = V_42 -> V_39 ;
struct V_73 * V_74 ;
int V_75 = V_42 -> V_76 ;
F_48 ( V_16 -> V_77 , V_78 ) ;
V_42 -> V_76 += V_72 ;
if ( V_75 > 0 )
return;
V_74 = (struct V_73 * ) V_4 -> V_79 ;
V_74 -> V_80 |= F_49 ( V_81 ) ;
F_50 ( V_14 -> V_82 , V_39 -> V_83 ,
sizeof( * V_74 ) , V_84 ) ;
}
static struct V_38 * F_51 ( struct V_13 * V_14 )
{
struct V_38 * V_39 = NULL ;
F_52 ( & V_14 -> V_44 . V_85 ) ;
if ( F_53 ( F_11 ( & V_14 -> V_44 . V_86 ) ) ) {
F_54 ( & V_14 -> V_44 . V_85 ) ;
return NULL ;
}
V_39 = F_55 ( & V_14 -> V_44 . V_86 , struct V_38 , V_20 ) ;
F_56 ( & V_39 -> V_20 ) ;
F_54 ( & V_14 -> V_44 . V_85 ) ;
return V_39 ;
}
static void F_57 ( struct V_13 * V_14 , struct V_38 * V_39 )
{
F_52 ( & V_14 -> V_44 . V_85 ) ;
F_12 ( & V_39 -> V_20 , & V_14 -> V_44 . V_86 ) ;
F_54 ( & V_14 -> V_44 . V_85 ) ;
}
static struct V_38 * F_58 ( struct V_13 * V_14 , struct V_38 * V_39 )
{
struct V_38 * V_87 ;
V_87 = F_51 ( V_14 ) ;
if ( F_21 ( ! V_87 ) )
return NULL ;
F_59 ( V_87 ) ;
V_87 -> V_40 = V_39 -> V_40 ;
V_87 -> V_83 = V_39 -> V_83 ;
memcpy ( V_87 -> V_88 , V_39 -> V_88 , V_14 -> V_89 -> V_90 . V_91 ) ;
V_87 -> V_61 = V_39 -> V_61 ;
V_87 -> V_61 . V_92 = false ;
return V_87 ;
}
static void F_60 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct F_1 * V_58 , int V_93 ,
int * V_94 , int * V_95 )
{
struct V_31 * V_42 ;
T_1 V_96 = 0 ;
V_97 V_98 [ V_99 >> 5 ] ;
int V_100 ;
int V_101 = 0 ;
* V_95 = 0 ;
* V_94 = 0 ;
V_101 = F_61 ( V_39 ) ;
if ( V_101 ) {
V_96 = V_58 -> V_102 ;
memcpy ( V_98 , & V_58 -> V_103 , V_99 >> 3 ) ;
}
while ( V_39 ) {
V_42 = F_13 ( V_39 -> V_40 ) ;
V_100 = F_39 ( V_96 , V_39 -> V_61 . V_34 ) ;
( * V_94 ) ++ ;
if ( ! V_93 || ( V_101 && ! F_62 ( V_98 , V_100 ) ) )
( * V_95 ) ++ ;
V_39 = V_39 -> V_104 ;
}
}
static void F_63 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_38 * V_39 , struct V_19 * V_105 ,
struct V_7 * V_8 ,
struct V_17 * V_18 ,
struct F_1 * V_58 , int V_93 )
{
struct V_50 * V_23 = NULL ;
struct V_3 * V_4 ;
struct V_73 * V_74 ;
struct V_5 * V_32 ;
struct V_38 * V_104 , * V_106 = V_39 -> V_107 ;
struct V_19 V_57 ;
struct V_108 V_109 ;
T_1 V_96 = 0 , V_110 = 0 , V_111 = 0 , V_112 ;
V_97 V_98 [ V_99 >> 5 ] ;
int V_101 , V_113 , V_114 , V_59 = 0 , V_115 = 0 , V_95 = 0 ;
bool V_116 = true , V_117 ;
struct V_118 V_41 [ 4 ] ;
struct V_31 * V_42 ;
int V_94 ;
bool V_119 = ! ! ( V_58 -> V_120 & V_121 ) ;
int V_122 , V_76 ;
int V_70 = - 1 ;
V_4 = V_39 -> V_40 ;
V_74 = (struct V_73 * ) V_4 -> V_79 ;
V_32 = F_2 ( V_4 ) ;
memcpy ( V_41 , V_39 -> V_41 , sizeof( V_41 ) ) ;
V_76 = V_58 -> V_123 + 1 ;
for ( V_122 = 0 ; V_122 < V_58 -> V_124 ; V_122 ++ )
V_76 += V_41 [ V_122 ] . V_72 ;
if ( ! V_8 ) {
F_36 ( & V_57 ) ;
while ( V_39 ) {
V_104 = V_39 -> V_104 ;
if ( ! V_39 -> V_61 . V_92 || V_104 != NULL )
F_64 ( & V_39 -> V_20 , & V_57 ) ;
F_38 ( V_14 , V_39 , V_16 , & V_57 , NULL , V_58 , 0 ) ;
V_39 = V_104 ;
}
return;
}
V_23 = (struct V_50 * ) V_8 -> V_25 ;
V_112 = V_18 -> V_62 ;
V_117 = V_58 -> V_125 & V_126 ;
if ( V_117 && V_18 -> V_30 != V_58 -> V_18 )
V_93 = false ;
V_101 = F_61 ( V_39 ) ;
memset ( V_98 , 0 , V_99 >> 3 ) ;
if ( V_101 && V_93 ) {
if ( V_58 -> V_125 & V_126 ) {
V_96 = V_58 -> V_102 ;
memcpy ( V_98 , & V_58 -> V_103 , V_99 >> 3 ) ;
} else {
if ( V_14 -> V_89 -> V_127 == V_128 )
V_115 = 1 ;
}
}
F_65 ( & V_109 ) ;
F_60 ( V_14 , V_39 , V_58 , V_93 , & V_94 , & V_95 ) ;
while ( V_39 ) {
T_1 V_34 = V_39 -> V_61 . V_34 ;
V_113 = V_114 = V_59 = 0 ;
V_104 = V_39 -> V_104 ;
V_4 = V_39 -> V_40 ;
V_32 = F_2 ( V_4 ) ;
V_42 = F_13 ( V_4 ) ;
if ( ! F_66 ( V_18 -> V_62 , V_18 -> V_129 , V_34 ) ||
! V_18 -> V_130 ) {
V_113 = 1 ;
} else if ( F_62 ( V_98 , F_39 ( V_96 , V_34 ) ) ) {
V_110 ++ ;
} else if ( ! V_101 && V_93 ) {
V_110 ++ ;
} else if ( V_119 ) {
V_114 = 1 ;
} else if ( V_42 -> V_76 < V_131 ) {
if ( V_93 || ! V_23 -> V_132 )
F_47 ( V_14 , V_16 , V_39 -> V_40 ,
V_76 ) ;
V_114 = 1 ;
} else {
V_113 = 1 ;
V_111 ++ ;
V_70 = F_67 ( int , V_70 ,
F_39 ( V_112 , V_34 ) ) ;
}
F_36 ( & V_57 ) ;
if ( V_104 != NULL || ! V_106 -> V_61 . V_92 )
F_64 ( & V_39 -> V_20 , & V_57 ) ;
if ( ! V_114 ) {
F_37 ( V_14 , V_18 , V_34 ) ;
if ( V_116 && ( V_110 == 1 || V_111 == 1 ) ) {
memcpy ( V_32 -> V_133 . V_41 , V_41 , sizeof( V_41 ) ) ;
F_68 ( V_14 , V_39 , V_58 , V_94 , V_95 , V_93 ) ;
V_116 = false ;
if ( V_39 == V_39 -> V_107 )
F_69 ( V_14 -> V_89 ,
V_39 -> V_40 ,
V_58 ) ;
}
F_38 ( V_14 , V_39 , V_16 , & V_57 , V_8 , V_58 ,
! V_113 ) ;
} else {
if ( V_32 -> V_11 & V_134 ) {
V_32 -> V_11 &= ~ V_134 ;
F_70 ( V_8 ) ;
}
if ( V_39 -> V_104 == NULL && V_106 -> V_61 . V_92 ) {
struct V_38 * V_87 ;
V_87 = F_58 ( V_14 , V_106 ) ;
if ( ! V_87 ) {
F_37 ( V_14 , V_18 , V_34 ) ;
F_38 ( V_14 , V_39 , V_16 ,
& V_57 , NULL , V_58 ,
0 ) ;
V_70 = F_67 ( int , V_70 ,
F_39 ( V_112 , V_34 ) ) ;
break;
}
V_42 -> V_39 = V_87 ;
}
F_71 ( & V_109 , V_4 ) ;
}
V_39 = V_104 ;
}
if ( ! F_27 ( & V_109 ) ) {
if ( V_23 -> V_132 )
F_72 ( V_8 , V_18 -> V_30 , true ) ;
F_73 ( & V_109 , & V_18 -> V_54 ) ;
if ( ! V_23 -> V_132 ) {
F_9 ( V_14 , V_16 , V_18 ) ;
if ( V_58 -> V_120 & ( V_135 | V_136 ) )
V_18 -> V_137 = true ;
}
}
if ( V_70 >= 0 ) {
T_1 V_138 = F_74 ( V_112 , V_70 ) ;
if ( F_66 ( V_18 -> V_62 , V_18 -> V_129 , V_138 ) )
V_18 -> V_70 = F_39 ( V_18 -> V_62 , V_138 ) ;
F_7 ( V_14 , V_16 ) ;
F_15 ( V_18 , F_74 ( V_112 , V_70 + 1 ) ) ;
F_6 ( V_14 , V_16 ) ;
}
if ( V_115 )
F_75 ( V_14 , V_139 ) ;
}
static bool F_76 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_39 -> V_40 ) ;
return F_77 ( V_39 ) && ! ( V_6 -> V_11 & V_140 ) ;
}
static void F_78 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct F_1 * V_58 , struct V_38 * V_39 ,
struct V_19 * V_57 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_73 * V_74 ;
struct V_17 * V_18 = NULL ;
bool V_93 , V_119 ;
V_93 = ! ( V_58 -> V_120 & V_141 ) ;
V_119 = ! ! ( V_58 -> V_120 & V_121 ) ;
V_16 -> V_142 = false ;
V_16 -> V_143 -- ;
if ( F_76 ( V_39 ) )
V_16 -> V_144 -- ;
V_58 -> V_145 = F_79 ( V_14 -> V_89 , V_39 -> V_88 ,
V_58 -> V_124 ) ;
V_74 = (struct V_73 * ) V_39 -> V_40 -> V_79 ;
V_8 = F_80 ( V_2 , V_74 -> V_146 , V_74 -> V_147 ) ;
if ( V_8 ) {
struct V_50 * V_23 = (struct V_50 * ) V_8 -> V_25 ;
V_18 = F_24 ( V_14 , V_23 , V_39 -> V_40 ) ;
if ( V_58 -> V_120 & ( V_135 | V_136 ) )
V_18 -> V_137 = true ;
}
if ( ! F_77 ( V_39 ) ) {
if ( ! V_119 ) {
V_6 = F_2 ( V_39 -> V_40 ) ;
memcpy ( V_6 -> V_133 . V_41 , V_39 -> V_41 ,
sizeof( V_6 -> V_133 . V_41 ) ) ;
F_68 ( V_14 , V_39 , V_58 , 1 , V_93 ? 0 : 1 , V_93 ) ;
F_69 ( V_14 -> V_89 , V_39 -> V_40 , V_58 ) ;
}
F_38 ( V_14 , V_39 , V_16 , V_57 , V_8 , V_58 , V_93 ) ;
} else
F_63 ( V_14 , V_16 , V_39 , V_57 , V_8 , V_18 , V_58 , V_93 ) ;
if ( ! V_119 )
F_81 ( V_14 , V_16 ) ;
}
static bool F_82 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
struct V_5 * V_32 ;
struct V_118 * V_41 ;
int V_122 ;
V_4 = V_39 -> V_40 ;
V_32 = F_2 ( V_4 ) ;
V_41 = V_32 -> V_133 . V_41 ;
for ( V_122 = 0 ; V_122 < 4 ; V_122 ++ ) {
if ( ! V_41 [ V_122 ] . V_72 || V_41 [ V_122 ] . V_148 < 0 )
break;
if ( ! ( V_41 [ V_122 ] . V_11 & V_149 ) )
return true ;
}
return false ;
}
static V_97 F_83 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_5 * V_32 ;
struct V_118 * V_41 ;
V_97 V_150 , V_151 ;
T_1 V_152 , V_153 , V_154 = 0 ;
int V_43 = V_18 -> V_16 -> V_155 ;
int V_122 ;
V_4 = V_39 -> V_40 ;
V_32 = F_2 ( V_4 ) ;
V_41 = V_39 -> V_41 ;
V_150 = V_156 ;
for ( V_122 = 0 ; V_122 < 4 ; V_122 ++ ) {
int V_157 ;
if ( ! V_41 [ V_122 ] . V_72 )
continue;
if ( ! ( V_41 [ V_122 ] . V_11 & V_149 ) ) {
V_154 = 1 ;
break;
}
if ( V_41 [ V_122 ] . V_11 & V_158 )
V_157 = V_159 ;
else
V_157 = V_160 ;
if ( V_41 [ V_122 ] . V_11 & V_161 )
V_157 ++ ;
V_151 = V_14 -> V_44 . V_162 [ V_43 ] [ V_157 ] [ V_41 [ V_122 ] . V_148 ] ;
V_150 = F_84 ( V_150 , V_151 ) ;
}
if ( V_32 -> V_11 & V_140 || V_154 )
return 0 ;
V_152 = F_84 ( V_150 , ( V_97 ) V_156 ) ;
V_153 = F_85 ( V_14 , V_150 ) ;
if ( V_153 )
V_152 = V_153 ;
if ( V_18 -> V_23 -> V_163 )
V_152 = F_84 ( V_152 , V_18 -> V_23 -> V_163 ) ;
return V_152 ;
}
static int F_86 ( struct V_13 * V_14 , struct V_17 * V_18 ,
struct V_38 * V_39 , T_1 V_151 ,
bool V_164 )
{
#define F_87 60
V_97 V_165 , V_166 ;
T_1 V_167 ;
T_2 V_11 , V_168 ;
int V_169 , V_170 , V_171 , V_172 , V_173 ;
struct V_31 * V_42 = F_13 ( V_39 -> V_40 ) ;
V_172 = F_88 ( V_151 ) ;
if ( ( V_42 -> V_174 != V_175 ) &&
! ( V_14 -> V_89 -> V_90 . V_176 & V_177 ) )
V_172 += V_178 ;
if ( V_164 && ! F_89 ( V_14 -> V_89 ) &&
( V_14 -> V_89 -> V_179 & V_180 ) )
V_172 = F_90 ( V_172 , F_87 ) ;
if ( V_18 -> V_23 -> V_181 == 0 )
return V_172 ;
V_168 = V_39 -> V_41 [ 0 ] . V_148 ;
V_11 = V_39 -> V_41 [ 0 ] . V_11 ;
V_169 = ( V_11 & V_158 ) ? 1 : 0 ;
V_171 = ( V_11 & V_161 ) ? 1 : 0 ;
if ( V_171 )
V_166 = F_91 ( V_18 -> V_23 -> V_181 ) ;
else
V_166 = F_92 ( V_18 -> V_23 -> V_181 ) ;
if ( V_166 == 0 )
V_166 = 1 ;
V_170 = F_93 ( V_168 ) ;
V_165 = V_182 [ V_168 % 8 ] [ V_169 ] * V_170 ;
V_167 = ( V_166 * V_165 ) / V_183 ;
if ( V_151 < V_167 ) {
V_173 = ( V_167 - V_151 ) / V_184 ;
V_172 = F_90 ( V_173 , V_172 ) ;
}
return V_172 ;
}
static struct V_38 *
F_94 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_108 * * V_43 )
{
struct V_5 * V_32 ;
struct V_31 * V_42 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
T_1 V_34 ;
while ( 1 ) {
* V_43 = & V_18 -> V_54 ;
if ( F_27 ( * V_43 ) )
* V_43 = & V_18 -> V_53 ;
V_4 = F_95 ( * V_43 ) ;
if ( ! V_4 )
break;
V_42 = F_13 ( V_4 ) ;
V_39 = V_42 -> V_39 ;
if ( ! V_42 -> V_39 )
V_39 = F_32 ( V_14 , V_16 , V_18 , V_4 ) ;
else
V_39 -> V_61 . V_92 = false ;
if ( ! V_39 ) {
F_33 ( V_4 , * V_43 ) ;
F_20 ( V_14 , V_16 , V_4 ) ;
F_34 ( V_14 -> V_2 , V_4 ) ;
continue;
}
V_39 -> V_104 = NULL ;
V_39 -> V_107 = V_39 ;
V_32 = F_2 ( V_4 ) ;
V_32 -> V_11 &= ~ V_185 ;
if ( ! V_18 -> V_130 )
V_32 -> V_11 &= ~ V_56 ;
if ( ! ( V_32 -> V_11 & V_56 ) ) {
V_39 -> V_61 . V_186 = 0 ;
return V_39 ;
}
V_39 -> V_61 . V_186 = V_187 | V_188 ;
V_34 = V_39 -> V_61 . V_34 ;
if ( ! F_66 ( V_18 -> V_62 , V_18 -> V_129 , V_34 ) )
break;
if ( V_18 -> V_70 > F_39 ( V_18 -> V_62 , V_34 ) ) {
struct F_1 V_58 = {} ;
struct V_19 V_57 ;
F_36 ( & V_57 ) ;
F_96 ( & V_39 -> V_20 , & V_57 ) ;
F_33 ( V_4 , * V_43 ) ;
F_37 ( V_14 , V_18 , V_34 ) ;
F_38 ( V_14 , V_39 , V_16 , & V_57 , NULL , & V_58 , 0 ) ;
continue;
}
return V_39 ;
}
return NULL ;
}
static bool
F_97 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_105 ,
struct V_38 * V_189 , struct V_108 * V_190 ,
int * V_191 )
{
#define F_98 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_38 * V_39 = V_189 , * V_192 = NULL ;
int V_94 = 0 , V_172 ;
T_1 V_152 = 0 , V_193 = 0 , V_194 = 0 ,
V_195 , V_196 = V_18 -> V_129 / 2 ;
struct V_5 * V_32 ;
struct V_31 * V_42 ;
struct V_3 * V_4 ;
bool V_197 = false ;
V_39 = V_189 ;
V_152 = F_83 ( V_14 , V_39 , V_18 ) ;
do {
V_4 = V_39 -> V_40 ;
V_42 = F_13 ( V_4 ) ;
V_195 = V_184 + V_42 -> V_198 ;
if ( V_94 ) {
if ( V_152 < V_193 + V_194 + V_195 ||
F_82 ( V_39 ) || V_94 >= V_196 )
break;
V_32 = F_2 ( V_39 -> V_40 ) ;
if ( ( V_32 -> V_11 & V_140 ) ||
! ( V_32 -> V_11 & V_56 ) )
break;
}
V_193 += V_194 + V_195 ;
V_172 = F_86 ( V_14 , V_18 , V_189 , V_42 -> V_198 ,
! V_94 ) ;
V_194 = F_98 ( V_195 ) + ( V_172 << 2 ) ;
V_94 ++ ;
V_39 -> V_104 = NULL ;
if ( ! V_42 -> V_60 )
F_43 ( V_14 , V_18 , V_39 ) ;
V_39 -> V_61 . V_172 = V_172 ;
F_33 ( V_4 , V_190 ) ;
F_12 ( & V_39 -> V_20 , V_105 ) ;
if ( V_192 )
V_192 -> V_104 = V_39 ;
V_192 = V_39 ;
V_39 = F_94 ( V_14 , V_16 , V_18 , & V_190 ) ;
if ( ! V_39 ) {
V_197 = true ;
break;
}
} while ( F_26 ( V_18 ) );
V_39 = V_189 ;
V_39 -> V_107 = V_192 ;
if ( V_39 == V_192 ) {
V_193 = F_13 ( V_39 -> V_40 ) -> V_198 ;
V_39 -> V_61 . V_186 = V_187 ;
} else {
F_48 ( V_16 -> V_77 , V_199 ) ;
}
* V_191 = V_193 ;
return V_197 ;
#undef F_98
}
static V_97 F_99 ( struct V_13 * V_14 , T_2 V_168 , int V_200 ,
int V_169 , int V_171 , bool V_201 )
{
V_97 V_202 , V_165 , V_145 , V_166 ;
int V_170 ;
V_170 = F_93 ( V_168 ) ;
V_202 = ( V_200 << 3 ) + V_203 ;
V_165 = V_182 [ V_168 % 8 ] [ V_169 ] * V_170 ;
V_166 = ( V_202 + V_165 - 1 ) / V_165 ;
if ( ! V_171 )
V_145 = F_100 ( V_166 ) ;
else
V_145 = F_101 ( V_166 ) ;
V_145 += V_204 + V_205 + V_206 + V_207 + V_208 + F_102 ( V_170 ) ;
return V_145 ;
}
static int F_103 ( int V_209 , int V_210 , bool V_211 , bool V_212 )
{
int V_170 = F_93 ( V_210 ) ;
int V_213 , V_214 ;
int V_215 = 0 ;
V_209 -= V_204 + V_205 + V_206 + V_207 + V_208 + F_102 ( V_170 ) ;
V_213 = V_212 ? F_104 ( V_209 ) : F_105 ( V_209 ) ;
V_214 = V_213 * V_182 [ V_210 % 8 ] [ V_211 ] * V_170 ;
V_214 -= V_203 ;
V_215 = V_214 / 8 ;
if ( V_215 > 65532 )
V_215 = 65532 ;
return V_215 ;
}
void F_106 ( struct V_13 * V_14 , int V_216 , int V_217 )
{
T_1 * V_218 , * V_219 , * V_220 , * V_221 ;
int V_210 ;
if ( ! V_217 || V_217 > 4096 )
V_217 = 4096 ;
V_218 = V_14 -> V_44 . V_162 [ V_216 ] [ V_160 ] ;
V_219 = V_14 -> V_44 . V_162 [ V_216 ] [ V_222 ] ;
V_220 = V_14 -> V_44 . V_162 [ V_216 ] [ V_159 ] ;
V_221 = V_14 -> V_44 . V_162 [ V_216 ] [ V_223 ] ;
for ( V_210 = 0 ; V_210 < 32 ; V_210 ++ ) {
V_218 [ V_210 ] = F_103 ( V_217 , V_210 , false , false ) ;
V_219 [ V_210 ] = F_103 ( V_217 , V_210 , false , true ) ;
V_220 [ V_210 ] = F_103 ( V_217 , V_210 , true , false ) ;
V_221 [ V_210 ] = F_103 ( V_217 , V_210 , true , true ) ;
}
}
static T_2 F_107 ( struct V_13 * V_14 , struct V_38 * V_39 ,
T_2 V_224 , bool V_225 , bool V_226 )
{
T_2 V_227 ;
struct V_3 * V_4 ;
struct V_31 * V_42 ;
struct V_5 * V_6 ;
struct V_228 * V_229 = V_14 -> V_89 ;
if ( V_14 -> V_230 || ! V_229 -> V_231 )
return V_232 ;
V_4 = V_39 -> V_40 ;
V_42 = F_13 ( V_4 ) ;
V_6 = F_2 ( V_4 ) ;
if ( ! F_108 ( V_229 ) ) {
int V_233 = V_42 -> V_234 ;
if ( V_225 ) {
T_2 V_235 ;
struct V_236 * V_237 = & V_229 -> V_238 . V_239 ;
if ( V_240 >= V_241 ) {
bool V_242 ;
struct V_243 * V_244 ;
V_242 = V_6 -> V_245 == V_246 ;
V_244 = & V_237 -> V_247 [ V_242 ] ;
V_235 = V_244 -> V_248 ;
} else {
V_235 = 2 ;
}
V_233 += V_235 ;
}
if ( F_109 ( V_229 ) || F_110 ( V_229 ) ||
F_111 ( V_229 ) ) {
V_233 -= 2 * V_249 ;
} else if ( F_112 ( V_229 ) ) {
T_4 V_250 ;
V_250 = V_229 -> V_251 -> V_252 ( V_229 ,
V_253 ) ;
V_233 -= 2 * V_250 ;
}
if ( V_254 && V_226 )
V_233 -= 2 ;
V_233 = F_90 ( V_233 , 0 ) ;
V_227 = F_113 ( T_2 , V_229 -> V_234 [ V_224 ] , V_233 ) ;
if ( ! V_227 && ! F_112 ( V_229 ) )
V_227 = 1 ;
} else if ( ! V_39 -> V_61 . V_255 ) {
if ( V_224 < 8 && ( V_6 -> V_11 & V_256 ) )
V_227 = F_113 ( T_2 , V_229 -> V_257 [ V_224 ] ,
V_42 -> V_234 ) ;
else
V_227 = F_113 ( T_2 , V_229 -> V_234 [ V_224 ] ,
V_42 -> V_234 ) ;
} else {
V_227 = V_229 -> V_258 ;
}
return V_227 ;
}
static void F_114 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct V_259 * V_6 , int V_260 , bool V_261 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_262 * V_263 = F_115 ( V_229 ) ;
struct V_3 * V_4 ;
struct V_5 * V_32 ;
struct V_118 * V_41 ;
const struct V_264 * V_265 ;
struct V_73 * V_74 ;
struct V_31 * V_42 = F_13 ( V_39 -> V_40 ) ;
V_97 V_266 = V_14 -> V_2 -> V_267 -> V_268 ;
int V_122 ;
T_2 V_168 = 0 ;
V_4 = V_39 -> V_40 ;
V_32 = F_2 ( V_4 ) ;
V_41 = V_39 -> V_41 ;
V_74 = (struct V_73 * ) V_4 -> V_79 ;
V_6 -> V_269 = ! F_116 ( V_74 -> V_80 ) ;
V_6 -> V_270 = V_42 -> V_270 ;
for ( V_122 = 0 ; V_122 < F_19 ( V_39 -> V_41 ) ; V_122 ++ ) {
bool V_225 , V_271 , V_272 , V_226 ;
int V_273 ;
if ( ! V_41 [ V_122 ] . V_72 || ( V_41 [ V_122 ] . V_148 < 0 ) )
continue;
V_168 = V_41 [ V_122 ] . V_148 ;
V_6 -> V_41 [ V_122 ] . V_274 = V_41 [ V_122 ] . V_72 ;
if ( F_77 ( V_39 ) && ! F_61 ( V_39 ) &&
( V_41 [ V_122 ] . V_11 & V_149 ) &&
F_53 ( V_266 != ( V_97 ) - 1 ) ) {
if ( ! V_266 || ( V_260 > V_266 ) )
V_261 = true ;
}
if ( V_261 || V_41 [ V_122 ] . V_11 & V_275 ) {
V_6 -> V_41 [ V_122 ] . V_276 |= V_277 ;
V_6 -> V_11 |= V_278 ;
} else if ( V_41 [ V_122 ] . V_11 & V_279 ) {
V_6 -> V_41 [ V_122 ] . V_276 |= V_277 ;
V_6 -> V_11 |= V_280 ;
}
if ( V_41 [ V_122 ] . V_11 & V_158 )
V_6 -> V_41 [ V_122 ] . V_276 |= V_281 ;
if ( V_41 [ V_122 ] . V_11 & V_161 )
V_6 -> V_41 [ V_122 ] . V_276 |= V_282 ;
V_271 = ! ! ( V_41 [ V_122 ] . V_11 & V_161 ) ;
V_225 = ! ! ( V_41 [ V_122 ] . V_11 & V_158 ) ;
V_272 = ! ! ( V_41 [ V_122 ] . V_11 & V_283 ) ;
if ( V_41 [ V_122 ] . V_11 & V_149 ) {
V_6 -> V_41 [ V_122 ] . V_284 = V_168 | 0x80 ;
V_6 -> V_41 [ V_122 ] . V_285 = F_117 ( V_14 ,
V_229 -> V_286 , V_6 -> V_41 [ V_122 ] . V_284 ) ;
V_6 -> V_41 [ V_122 ] . V_287 = F_99 ( V_14 , V_168 , V_260 ,
V_225 , V_271 , V_272 ) ;
if ( V_168 < 8 && ( V_32 -> V_11 & V_256 ) )
V_6 -> V_41 [ V_122 ] . V_276 |= V_288 ;
V_6 -> V_233 [ V_122 ] = F_107 ( V_14 , V_39 , V_168 ,
V_225 , false ) ;
continue;
}
V_265 = & V_263 -> V_289 [ V_32 -> V_245 ] . V_290 [ V_41 [ V_122 ] . V_148 ] ;
if ( ( V_32 -> V_245 == V_246 ) &&
! ( V_265 -> V_11 & V_291 ) )
V_273 = V_292 ;
else
V_273 = V_293 ;
V_6 -> V_41 [ V_122 ] . V_284 = V_265 -> V_294 ;
if ( V_265 -> V_295 ) {
if ( V_41 [ V_122 ] . V_11 & V_283 )
V_6 -> V_41 [ V_122 ] . V_284 |= V_265 -> V_295 ;
} else {
V_272 = false ;
}
if ( V_39 -> V_61 . V_255 )
V_6 -> V_41 [ V_122 ] . V_285 = V_229 -> V_286 ;
else
V_6 -> V_41 [ V_122 ] . V_285 = F_117 ( V_14 ,
V_229 -> V_286 , V_6 -> V_41 [ V_122 ] . V_284 ) ;
V_6 -> V_41 [ V_122 ] . V_287 = F_118 ( V_14 -> V_89 ,
V_273 , V_265 -> V_296 * 100 , V_260 , V_168 , V_272 ) ;
V_226 = F_119 ( V_6 -> V_41 [ V_122 ] . V_284 ) ;
V_6 -> V_233 [ V_122 ] = F_107 ( V_14 , V_39 , V_168 , false ,
V_226 ) ;
}
if ( F_61 ( V_39 ) && ( V_260 > V_14 -> V_89 -> V_90 . V_297 ) )
V_6 -> V_11 &= ~ V_278 ;
if ( V_6 -> V_11 & V_278 )
V_6 -> V_11 &= ~ V_280 ;
}
static enum V_298 F_120 ( struct V_3 * V_4 )
{
struct V_73 * V_74 ;
enum V_298 V_299 ;
T_5 V_300 ;
V_74 = (struct V_73 * ) V_4 -> V_79 ;
V_300 = V_74 -> V_80 ;
if ( F_121 ( V_300 ) )
V_299 = V_301 ;
else if ( F_122 ( V_300 ) )
V_299 = V_302 ;
else if ( F_123 ( V_300 ) )
V_299 = V_303 ;
else if ( F_116 ( V_300 ) )
V_299 = V_304 ;
else
V_299 = V_305 ;
return V_299 ;
}
static void F_124 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct V_15 * V_16 , int V_260 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_38 * V_189 = NULL ;
struct V_259 V_6 ;
V_97 V_266 = V_14 -> V_2 -> V_267 -> V_268 ;
bool V_261 = false ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_306 = true ;
V_6 . V_307 = true ;
V_6 . V_308 = V_16 -> V_77 ;
while ( V_39 ) {
struct V_3 * V_4 = V_39 -> V_40 ;
struct V_5 * V_32 = F_2 ( V_4 ) ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
bool V_309 = ! ! ( V_39 -> V_61 . V_186 & V_188 ) ;
V_6 . type = F_120 ( V_4 ) ;
if ( V_39 -> V_104 )
V_6 . V_310 = V_39 -> V_104 -> V_311 ;
else
V_6 . V_310 = ( V_14 -> V_230 ) ? V_39 -> V_311 : 0 ;
if ( ! V_189 ) {
V_189 = V_39 ;
if ( ! V_14 -> V_230 )
V_6 . V_11 = V_312 ;
if ( ( V_32 -> V_11 & V_185 ) ||
V_16 == V_14 -> V_44 . V_313 )
V_6 . V_11 |= V_314 ;
if ( V_32 -> V_11 & V_315 )
V_6 . V_11 |= V_316 ;
if ( V_32 -> V_11 & V_317 )
V_6 . V_11 |= V_318 ;
if ( V_39 -> V_61 . V_255 )
V_6 . V_11 |= ( V_97 ) V_39 -> V_61 . V_255 <<
V_319 ;
if ( V_309 && ( V_39 == V_189 ) &&
F_53 ( V_266 != ( V_97 ) - 1 ) ) {
if ( ! V_266 || ( V_260 > V_266 ) )
V_261 = true ;
}
if ( ! V_309 )
V_260 = V_42 -> V_198 ;
F_114 ( V_14 , V_39 , & V_6 , V_260 , V_261 ) ;
}
V_6 . V_320 [ 0 ] = V_39 -> V_83 ;
V_6 . V_321 [ 0 ] = V_4 -> V_260 ;
V_6 . V_322 = V_42 -> V_198 ;
V_6 . V_174 = V_42 -> V_174 ;
V_6 . V_323 = V_42 -> V_323 ;
if ( V_309 ) {
if ( V_39 == V_189 )
V_6 . V_309 = V_324 ;
else if ( V_39 == V_189 -> V_107 )
V_6 . V_309 = V_325 ;
else
V_6 . V_309 = V_326 ;
V_6 . V_172 = V_39 -> V_61 . V_172 ;
V_6 . V_191 = V_260 ;
}
if ( V_39 == V_189 -> V_107 )
V_189 = NULL ;
F_125 ( V_229 , V_39 -> V_88 , & V_6 ) ;
V_39 = V_39 -> V_104 ;
}
}
static void
F_126 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_105 ,
struct V_38 * V_189 , struct V_108 * V_190 )
{
struct V_38 * V_39 = V_189 , * V_192 = NULL ;
struct V_3 * V_4 ;
int V_94 = 0 ;
do {
struct V_5 * V_32 ;
V_4 = V_39 -> V_40 ;
V_94 ++ ;
F_33 ( V_4 , V_190 ) ;
F_12 ( & V_39 -> V_20 , V_105 ) ;
if ( V_192 )
V_192 -> V_104 = V_39 ;
V_192 = V_39 ;
if ( V_94 >= 2 )
break;
V_39 = F_94 ( V_14 , V_16 , V_18 , & V_190 ) ;
if ( ! V_39 )
break;
V_32 = F_2 ( V_39 -> V_40 ) ;
if ( V_32 -> V_11 & V_56 )
break;
F_17 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_39 ) ;
} while ( 1 );
}
static bool F_127 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , bool * V_327 )
{
struct V_38 * V_39 ;
struct V_5 * V_32 ;
struct V_108 * V_190 ;
struct V_19 V_105 ;
int V_191 = 0 ;
bool V_309 , V_328 = true ;
if ( ! F_26 ( V_18 ) )
return false ;
F_36 ( & V_105 ) ;
V_39 = F_94 ( V_14 , V_16 , V_18 , & V_190 ) ;
if ( ! V_39 )
return false ;
V_32 = F_2 ( V_39 -> V_40 ) ;
V_309 = ! ! ( V_32 -> V_11 & V_56 ) ;
if ( ( V_309 && V_16 -> V_144 >= V_329 ) ||
( ! V_309 && V_16 -> V_143 >= V_330 ) ) {
* V_327 = true ;
return false ;
}
F_17 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_39 ) ;
if ( V_309 )
V_328 = F_97 ( V_14 , V_16 , V_18 , & V_105 , V_39 ,
V_190 , & V_191 ) ;
else
F_126 ( V_14 , V_16 , V_18 , & V_105 , V_39 , V_190 ) ;
if ( F_11 ( & V_105 ) )
return false ;
if ( V_18 -> V_137 || V_18 -> V_23 -> V_331 ) {
V_18 -> V_137 = false ;
V_32 -> V_11 |= V_185 ;
}
F_124 ( V_14 , V_39 , V_16 , V_191 ) ;
F_128 ( V_14 , V_16 , & V_105 , false ) ;
return true ;
}
int F_129 ( struct V_13 * V_14 , struct V_7 * V_8 ,
T_1 V_18 , T_1 * V_332 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_17 * V_333 ;
struct V_15 * V_16 ;
struct V_50 * V_23 ;
T_2 V_334 ;
F_130 ( V_263 , V_335 , L_1 , V_336 ) ;
V_23 = (struct V_50 * ) V_8 -> V_25 ;
V_333 = F_25 ( V_23 , V_18 ) ;
V_16 = V_333 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( V_8 -> V_337 . V_338 ) {
V_23 -> V_163 = ( 1 << ( V_339 +
V_8 -> V_337 . V_340 ) ) - 1 ;
V_334 = F_131 ( V_8 -> V_337 . V_341 ) ;
V_23 -> V_181 = V_334 ;
}
F_30 ( V_14 , V_333 ) ;
V_333 -> V_130 = true ;
* V_332 = V_333 -> V_62 = V_333 -> V_342 ;
V_333 -> V_70 = - 1 ;
memset ( V_333 -> V_67 , 0 , sizeof( V_333 -> V_67 ) ) ;
V_333 -> V_65 = V_333 -> V_68 = 0 ;
F_8 ( V_14 , V_16 ) ;
return 0 ;
}
void F_132 ( struct V_13 * V_14 , struct V_7 * V_8 , T_1 V_18 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_50 * V_23 = (struct V_50 * ) V_8 -> V_25 ;
struct V_17 * V_333 = F_25 ( V_23 , V_18 ) ;
struct V_15 * V_16 = V_333 -> V_16 ;
F_130 ( V_263 , V_335 , L_1 , V_336 ) ;
F_6 ( V_14 , V_16 ) ;
V_333 -> V_130 = false ;
F_35 ( V_14 , V_333 ) ;
F_30 ( V_14 , V_333 ) ;
F_8 ( V_14 , V_16 ) ;
}
void F_133 ( struct V_7 * V_8 , struct V_13 * V_14 ,
struct V_50 * V_23 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
bool V_343 ;
int V_30 ;
F_130 ( V_263 , V_335 , L_1 , V_336 ) ;
for ( V_30 = 0 , V_18 = & V_23 -> V_18 [ V_30 ] ;
V_30 < V_344 ; V_30 ++ , V_18 ++ ) {
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( F_11 ( & V_18 -> V_20 ) ) {
F_7 ( V_14 , V_16 ) ;
continue;
}
V_343 = F_26 ( V_18 ) ;
F_134 ( & V_18 -> V_20 ) ;
F_7 ( V_14 , V_16 ) ;
F_72 ( V_8 , V_30 , V_343 ) ;
}
}
void F_135 ( struct V_13 * V_14 , struct V_50 * V_23 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
int V_30 ;
F_130 ( V_263 , V_335 , L_1 , V_336 ) ;
for ( V_30 = 0 , V_18 = & V_23 -> V_18 [ V_30 ] ;
V_30 < V_344 ; V_30 ++ , V_18 ++ ) {
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
V_18 -> V_137 = true ;
if ( F_26 ( V_18 ) ) {
F_9 ( V_14 , V_16 , V_18 ) ;
F_81 ( V_14 , V_16 ) ;
}
F_8 ( V_14 , V_16 ) ;
}
}
void F_136 ( struct V_13 * V_14 , struct V_7 * V_8 ,
T_1 V_30 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_17 * V_18 ;
struct V_50 * V_23 ;
struct V_15 * V_16 ;
F_130 ( V_263 , V_335 , L_1 , V_336 ) ;
V_23 = (struct V_50 * ) V_8 -> V_25 ;
V_18 = F_25 ( V_23 , V_30 ) ;
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
V_18 -> V_129 = V_345 << V_8 -> V_337 . V_340 ;
if ( F_26 ( V_18 ) ) {
F_9 ( V_14 , V_16 , V_18 ) ;
F_81 ( V_14 , V_16 ) ;
}
F_8 ( V_14 , V_16 ) ;
}
void F_137 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
T_1 V_346 , int V_94 ,
enum V_347 V_348 ,
bool V_349 )
{
struct V_13 * V_14 = V_2 -> V_350 ;
struct V_50 * V_23 = (struct V_50 * ) V_8 -> V_25 ;
struct V_15 * V_16 = V_14 -> V_44 . V_313 ;
struct V_5 * V_6 ;
struct V_19 V_105 ;
struct V_38 * V_351 = NULL , * V_39 ;
struct V_108 * V_190 ;
int V_352 = 0 ;
int V_122 ;
F_36 ( & V_105 ) ;
for ( V_122 = 0 ; V_346 && V_94 ; V_122 ++ , V_346 >>= 1 ) {
struct V_17 * V_18 ;
if ( ! ( V_346 & 1 ) )
continue;
V_18 = F_25 ( V_23 , V_122 ) ;
F_6 ( V_14 , V_18 -> V_16 ) ;
while ( V_94 > 0 ) {
V_39 = F_94 ( V_14 , V_14 -> V_44 . V_313 , V_18 , & V_190 ) ;
if ( ! V_39 )
break;
F_33 ( V_39 -> V_40 , V_190 ) ;
F_12 ( & V_39 -> V_20 , & V_105 ) ;
F_17 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_39 ) ;
if ( F_77 ( V_39 ) ) {
F_43 ( V_14 , V_18 , V_39 ) ;
V_39 -> V_61 . V_186 &= ~ V_188 ;
}
if ( V_351 )
V_351 -> V_104 = V_39 ;
V_351 = V_39 ;
V_94 -- ;
V_352 ++ ;
F_48 ( V_16 -> V_77 , V_353 ) ;
if ( V_23 -> V_8 && ! F_26 ( V_18 ) )
F_72 ( V_23 -> V_8 , V_122 , false ) ;
}
F_8 ( V_14 , V_18 -> V_16 ) ;
}
if ( F_11 ( & V_105 ) )
return;
V_6 = F_2 ( V_351 -> V_40 ) ;
V_6 -> V_11 |= V_134 ;
V_39 = F_55 ( & V_105 , struct V_38 , V_20 ) ;
F_6 ( V_14 , V_16 ) ;
F_124 ( V_14 , V_39 , V_16 , 0 ) ;
F_128 ( V_14 , V_16 , & V_105 , false ) ;
F_7 ( V_14 , V_16 ) ;
}
struct V_15 * F_138 ( struct V_13 * V_14 , int V_354 , int V_355 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_356 V_357 ;
static const int V_358 [] = {
[ V_359 ] = V_360 ,
[ V_361 ] = V_362 ,
[ V_363 ] = V_364 ,
[ V_365 ] = V_366 ,
} ;
int V_77 , V_122 ;
memset ( & V_357 , 0 , sizeof( V_357 ) ) ;
V_357 . V_367 = V_358 [ V_355 ] ;
V_357 . V_368 = V_369 ;
V_357 . V_370 = V_369 ;
V_357 . V_371 = V_369 ;
V_357 . V_372 = 0 ;
if ( V_229 -> V_90 . V_176 & V_177 ) {
V_357 . V_373 = V_374 ;
} else {
if ( V_354 == V_375 )
V_357 . V_373 = V_376 ;
else
V_357 . V_373 = V_377 |
V_376 ;
}
V_77 = F_139 ( V_229 , V_354 , & V_357 ) ;
if ( V_77 == - 1 ) {
return NULL ;
}
if ( ! F_140 ( V_14 , V_77 ) ) {
struct V_15 * V_16 = & V_14 -> V_44 . V_16 [ V_77 ] ;
V_16 -> V_77 = V_77 ;
V_16 -> V_155 = - 1 ;
V_16 -> V_378 = NULL ;
F_65 ( & V_16 -> V_379 ) ;
F_36 ( & V_16 -> V_380 ) ;
F_141 ( & V_16 -> V_381 ) ;
V_16 -> V_143 = 0 ;
V_16 -> V_144 = 0 ;
V_16 -> V_142 = false ;
V_14 -> V_44 . V_382 |= 1 << V_77 ;
V_16 -> V_383 = V_16 -> V_384 = 0 ;
for ( V_122 = 0 ; V_122 < V_385 ; V_122 ++ )
F_36 ( & V_16 -> V_386 [ V_122 ] ) ;
}
return & V_14 -> V_44 . V_16 [ V_77 ] ;
}
int F_142 ( struct V_13 * V_14 , int V_387 ,
struct V_356 * V_388 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
int error = 0 ;
struct V_356 V_357 ;
F_143 ( V_14 -> V_44 . V_16 [ V_387 ] . V_77 != V_387 ) ;
F_144 ( V_229 , V_387 , & V_357 ) ;
V_357 . V_368 = V_388 -> V_368 ;
V_357 . V_370 = V_388 -> V_370 ;
V_357 . V_371 = V_388 -> V_371 ;
V_357 . V_389 = V_388 -> V_389 ;
V_357 . V_390 = V_388 -> V_390 ;
if ( ! F_145 ( V_229 , V_387 , & V_357 ) ) {
F_146 ( F_115 ( V_14 -> V_89 ) ,
L_2 , V_387 ) ;
error = - V_391 ;
} else {
F_147 ( V_229 , V_387 ) ;
}
return error ;
}
int F_148 ( struct V_13 * V_14 )
{
struct V_356 V_357 ;
struct V_392 * V_393 = & V_14 -> V_394 -> V_395 ;
int V_387 = V_14 -> V_395 . V_396 -> V_77 ;
F_144 ( V_14 -> V_89 , V_387 , & V_357 ) ;
V_357 . V_390 = ( F_149 ( V_393 -> V_397 ) *
V_398 ) / 100 ;
F_142 ( V_14 , V_387 , & V_357 ) ;
return 0 ;
}
static void F_150 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_19 * V_20 )
{
struct V_38 * V_39 , * V_399 ;
struct V_19 V_57 ;
struct F_1 V_58 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_120 = V_121 ;
F_36 ( & V_57 ) ;
while ( ! F_11 ( V_20 ) ) {
V_39 = F_55 ( V_20 , struct V_38 , V_20 ) ;
if ( V_39 -> V_61 . V_92 ) {
F_56 ( & V_39 -> V_20 ) ;
F_57 ( V_14 , V_39 ) ;
continue;
}
V_399 = V_39 -> V_107 ;
F_151 ( & V_57 , V_20 , & V_399 -> V_20 ) ;
F_78 ( V_14 , V_16 , & V_58 , V_39 , & V_57 ) ;
}
}
void F_152 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
F_153 () ;
F_6 ( V_14 , V_16 ) ;
if ( V_14 -> V_89 -> V_90 . V_176 & V_177 ) {
int V_148 = V_16 -> V_384 ;
while ( ! F_11 ( & V_16 -> V_386 [ V_148 ] ) ) {
F_150 ( V_14 , V_16 , & V_16 -> V_386 [ V_148 ] ) ;
F_42 ( V_148 , V_385 ) ;
}
V_16 -> V_384 = V_148 ;
}
V_16 -> V_378 = NULL ;
V_16 -> V_142 = false ;
F_150 ( V_14 , V_16 , & V_16 -> V_380 ) ;
F_8 ( V_14 , V_16 ) ;
F_154 () ;
}
bool F_155 ( struct V_13 * V_14 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_15 * V_16 ;
int V_122 ;
V_97 V_400 = 0 ;
if ( F_41 ( V_401 , & V_263 -> V_402 ) )
return true ;
F_156 ( V_229 ) ;
for ( V_122 = 0 ; V_122 < V_403 ; V_122 ++ ) {
if ( ! F_140 ( V_14 , V_122 ) )
continue;
if ( ! V_14 -> V_44 . V_16 [ V_122 ] . V_143 )
continue;
if ( F_157 ( V_229 , V_14 -> V_44 . V_16 [ V_122 ] . V_77 ) )
V_400 |= F_158 ( V_122 ) ;
}
if ( V_400 ) {
F_159 ( V_14 , V_404 ) ;
F_130 ( V_263 , V_405 ,
L_3 , V_400 ) ;
}
for ( V_122 = 0 ; V_122 < V_403 ; V_122 ++ ) {
if ( ! F_140 ( V_14 , V_122 ) )
continue;
V_16 = & V_14 -> V_44 . V_16 [ V_122 ] ;
V_16 -> V_47 = false ;
F_152 ( V_14 , V_16 ) ;
}
return ! V_400 ;
}
void F_160 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
F_161 ( V_14 -> V_89 , V_16 -> V_77 ) ;
V_14 -> V_44 . V_382 &= ~ ( 1 << V_16 -> V_77 ) ;
}
void F_81 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_17 * V_18 , * V_406 ;
struct V_19 * V_407 ;
bool V_352 = false ;
if ( V_16 -> V_155 < 0 )
return;
if ( F_41 ( V_408 , & V_263 -> V_402 ) )
return;
F_52 ( & V_14 -> V_409 ) ;
V_407 = & V_14 -> V_394 -> V_29 [ V_16 -> V_155 ] ;
if ( F_11 ( V_407 ) ) {
F_54 ( & V_14 -> V_409 ) ;
return;
}
F_153 () ;
V_406 = F_162 ( V_407 -> V_75 , struct V_17 , V_20 ) ;
while ( ! F_11 ( V_407 ) ) {
bool V_327 = false ;
if ( V_14 -> V_394 -> V_47 )
break;
V_18 = F_55 ( V_407 , struct V_17 , V_20 ) ;
F_134 ( & V_18 -> V_20 ) ;
if ( F_127 ( V_14 , V_16 , V_18 , & V_327 ) )
V_352 = true ;
if ( F_26 ( V_18 ) )
F_9 ( V_14 , V_16 , V_18 ) ;
if ( V_327 )
break;
if ( V_18 == V_406 ) {
if ( ! V_352 )
break;
V_352 = false ;
V_406 = F_162 ( V_407 -> V_75 ,
struct V_17 , V_20 ) ;
}
}
F_154 () ;
F_54 ( & V_14 -> V_409 ) ;
}
void F_163 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_410 ; V_122 ++ ) {
V_16 = V_14 -> V_44 . V_45 [ V_122 ] ;
F_52 ( & V_16 -> V_381 ) ;
F_81 ( V_14 , V_16 ) ;
F_54 ( & V_16 -> V_381 ) ;
}
}
static void F_128 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_19 * V_411 , bool V_412 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_262 * V_263 = F_115 ( V_229 ) ;
struct V_38 * V_39 , * V_106 ;
bool V_413 = false ;
bool V_414 ;
if ( F_11 ( V_411 ) )
return;
V_414 = ! ! ( V_229 -> V_90 . V_176 & V_177 ) ;
V_39 = F_55 ( V_411 , struct V_38 , V_20 ) ;
V_106 = F_162 ( V_411 -> V_75 , struct V_38 , V_20 ) ;
F_130 ( V_263 , V_415 , L_4 ,
V_16 -> V_77 , V_16 -> V_143 ) ;
if ( V_414 && F_11 ( & V_16 -> V_386 [ V_16 -> V_383 ] ) ) {
F_164 ( V_411 , & V_16 -> V_386 [ V_16 -> V_383 ] ) ;
F_42 ( V_16 -> V_383 , V_385 ) ;
V_413 = true ;
} else {
F_164 ( V_411 , & V_16 -> V_380 ) ;
if ( V_16 -> V_378 ) {
F_165 ( V_229 , V_16 -> V_378 , V_39 -> V_311 ) ;
F_130 ( V_263 , V_335 , L_5 ,
V_16 -> V_77 , V_16 -> V_378 ,
F_166 ( V_39 -> V_311 ) , V_39 -> V_88 ) ;
} else if ( ! V_414 )
V_413 = true ;
V_16 -> V_378 = V_106 -> V_88 ;
}
if ( V_413 ) {
F_48 ( V_16 -> V_77 , V_413 ) ;
F_167 ( V_229 , V_16 -> V_77 , V_39 -> V_311 ) ;
F_130 ( V_263 , V_335 , L_6 ,
V_16 -> V_77 , F_166 ( V_39 -> V_311 ) , V_39 -> V_88 ) ;
}
if ( ! V_414 || V_14 -> V_230 ) {
F_48 ( V_16 -> V_77 , V_416 ) ;
F_168 ( V_229 , V_16 -> V_77 ) ;
}
if ( ! V_412 ) {
while ( V_39 ) {
V_16 -> V_143 ++ ;
if ( F_76 ( V_39 ) )
V_16 -> V_144 ++ ;
V_106 = V_39 -> V_107 ;
V_39 = V_106 -> V_104 ;
V_106 -> V_104 = NULL ;
}
}
}
static void F_169 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_3 * V_4 )
{
struct V_5 * V_32 = F_2 ( V_4 ) ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_19 V_57 ;
struct V_38 * V_39 = V_42 -> V_39 ;
F_36 ( & V_57 ) ;
F_12 ( & V_39 -> V_20 , & V_57 ) ;
V_39 -> V_61 . V_186 = 0 ;
if ( V_18 && ( V_32 -> V_11 & V_56 ) ) {
V_39 -> V_61 . V_186 = V_187 ;
F_43 ( V_14 , V_18 , V_39 ) ;
}
V_39 -> V_104 = NULL ;
V_39 -> V_107 = V_39 ;
F_124 ( V_14 , V_39 , V_16 , V_42 -> V_198 ) ;
F_128 ( V_14 , V_16 , & V_57 , false ) ;
F_48 ( V_16 -> V_77 , V_417 ) ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_3 * V_4 ,
int V_198 )
{
struct V_5 * V_32 = F_2 ( V_4 ) ;
struct V_418 * V_419 = V_32 -> V_133 . V_419 ;
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
const struct V_264 * V_265 ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_50 * V_23 = NULL ;
enum V_420 V_323 ;
bool V_421 = false ;
T_2 V_233 ;
if ( V_32 -> V_133 . V_24 &&
V_32 -> V_133 . V_24 -> V_422 . V_423 )
V_421 = true ;
V_265 = F_171 ( V_2 , V_32 ) ;
V_323 = F_172 ( V_4 ) ;
if ( V_8 )
V_23 = (struct V_50 * ) V_8 -> V_25 ;
if ( V_32 -> V_133 . V_24 ) {
struct V_37 * V_24 = V_32 -> V_133 . V_24 ;
V_233 = 2 * V_24 -> V_422 . V_233 ;
} else {
struct V_13 * V_14 = V_2 -> V_350 ;
V_233 = V_14 -> V_394 -> V_424 ;
}
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_16 = - 1 ;
if ( V_419 )
V_42 -> V_174 = V_419 -> V_425 ;
else if ( V_23 && F_173 ( V_74 -> V_80 ) && V_23 -> V_426 > 0 )
V_42 -> V_174 = V_23 -> V_426 ;
else
V_42 -> V_174 = V_175 ;
V_42 -> V_323 = V_323 ;
V_42 -> V_198 = V_198 ;
V_42 -> V_234 = V_233 ;
if ( ! V_265 )
return;
V_42 -> V_270 = V_265 -> V_294 ;
if ( V_421 )
V_42 -> V_270 |= V_265 -> V_295 ;
}
T_2 F_117 ( struct V_13 * V_14 , T_2 V_427 , V_97 V_265 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_428 * V_429 = V_229 -> V_429 ;
if ( ( V_229 -> V_90 . V_176 & V_430 ) && F_174 ( V_429 ) &&
( V_427 == 0x7 ) && ( V_265 < 0x90 ) )
return 0x3 ;
else if ( F_175 ( V_229 ) && F_176 ( V_229 ) &&
F_119 ( V_265 ) )
return 0x2 ;
else
return V_427 ;
}
static struct V_38 * F_32 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
struct V_38 * V_39 ;
int V_431 ;
T_1 V_34 ;
V_39 = F_51 ( V_14 ) ;
if ( ! V_39 ) {
F_130 ( V_263 , V_335 , L_7 ) ;
return NULL ;
}
F_59 ( V_39 ) ;
if ( V_18 && F_177 ( V_74 -> V_80 ) ) {
V_431 = F_178 ( V_74 -> V_432 ) & V_433 ;
V_34 = V_18 -> V_342 ;
V_74 -> V_432 = F_49 ( V_18 -> V_342 << V_36 ) ;
if ( V_431 )
V_74 -> V_432 |= F_49 ( V_431 ) ;
if ( ! F_179 ( V_74 -> V_80 ) )
F_42 ( V_18 -> V_342 , V_69 ) ;
V_39 -> V_61 . V_34 = V_34 ;
}
V_39 -> V_40 = V_4 ;
V_39 -> V_83 = F_180 ( V_14 -> V_82 , V_4 -> V_79 ,
V_4 -> V_260 , V_84 ) ;
if ( F_53 ( F_181 ( V_14 -> V_82 , V_39 -> V_83 ) ) ) {
V_39 -> V_40 = NULL ;
V_39 -> V_83 = 0 ;
F_146 ( F_115 ( V_14 -> V_89 ) ,
L_8 ) ;
F_57 ( V_14 , V_39 ) ;
return NULL ;
}
V_42 -> V_39 = V_39 ;
return V_39 ;
}
void F_182 ( struct V_262 * V_263 , struct V_3 * V_4 )
{
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_37 * V_24 = V_6 -> V_133 . V_24 ;
struct V_21 * V_22 ;
if ( ! ( V_6 -> V_11 & V_434 ) )
return;
if ( ! V_24 )
return;
V_22 = (struct V_21 * ) V_24 -> V_25 ;
if ( V_6 -> V_11 & V_435 )
V_22 -> V_436 += 0x10 ;
V_74 -> V_432 &= F_49 ( V_433 ) ;
V_74 -> V_432 |= F_49 ( V_22 -> V_436 ) ;
}
static int F_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_437 * V_438 )
{
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_438 -> V_8 ;
struct V_37 * V_24 = V_6 -> V_133 . V_24 ;
struct V_21 * V_22 ;
struct V_13 * V_14 = V_2 -> V_350 ;
int V_151 = V_4 -> V_260 + V_439 ;
int V_440 , V_441 ;
if ( V_8 )
V_438 -> V_23 = (struct V_50 * ) V_8 -> V_25 ;
else if ( V_24 && F_173 ( V_74 -> V_80 ) ) {
V_22 = ( void * ) V_24 -> V_25 ;
V_438 -> V_23 = & V_22 -> V_442 ;
}
if ( V_6 -> V_133 . V_419 )
V_151 += V_6 -> V_133 . V_419 -> V_443 ;
F_182 ( F_115 ( V_14 -> V_89 ) , V_4 ) ;
if ( ( V_24 && V_24 -> type != V_444 &&
V_24 -> type != V_445 ) ||
! F_173 ( V_74 -> V_80 ) )
V_6 -> V_11 |= V_185 ;
V_440 = F_184 ( V_74 -> V_80 ) ;
V_441 = V_440 & 3 ;
if ( V_441 && V_4 -> V_260 > V_440 ) {
if ( F_185 ( V_4 ) < V_441 )
return - V_446 ;
F_186 ( V_4 , V_441 ) ;
memmove ( V_4 -> V_79 , V_4 -> V_79 + V_441 , V_440 ) ;
}
F_170 ( V_2 , V_8 , V_4 , V_151 ) ;
return 0 ;
}
int F_187 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_437 * V_438 )
{
struct V_73 * V_74 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_438 -> V_8 ;
struct V_37 * V_24 = V_6 -> V_133 . V_24 ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_21 * V_22 = NULL ;
struct V_13 * V_14 = V_2 -> V_350 ;
struct V_15 * V_16 = V_438 -> V_16 ;
struct V_17 * V_18 = NULL ;
struct V_38 * V_39 ;
bool V_216 , V_447 = false , V_448 ;
int V_43 , V_449 ;
if ( V_24 )
V_22 = ( void * ) V_24 -> V_25 ;
if ( V_6 -> V_11 & V_450 )
V_438 -> V_451 = true ;
V_448 = ! ! ( V_6 -> V_133 . V_11 & V_452 ) ;
V_449 = F_183 ( V_2 , V_4 , V_438 ) ;
if ( V_449 )
return V_449 ;
V_74 = (struct V_73 * ) V_4 -> V_79 ;
V_43 = F_188 ( V_4 ) ;
F_6 ( V_14 , V_16 ) ;
if ( V_16 == V_14 -> V_44 . V_45 [ V_43 ] ) {
V_42 -> V_16 = V_43 ;
if ( ++ V_16 -> V_46 > V_14 -> V_44 . V_48 [ V_43 ] &&
! V_16 -> V_47 ) {
if ( F_22 () )
F_189 ( V_14 -> V_2 , V_6 -> V_49 ) ;
else
F_189 ( V_14 -> V_2 , V_43 ) ;
V_16 -> V_47 = true ;
}
}
V_216 = F_177 ( V_74 -> V_80 ) ;
if ( F_22 () &&
F_190 ( V_74 -> V_80 ) &&
! V_438 -> V_451 )
V_216 = true ;
if ( ( ( V_22 && V_22 -> V_28 != V_14 -> V_394 ) ||
V_14 -> V_394 -> V_47 ) && ! V_438 -> V_451 ) {
if ( ! V_438 -> V_23 )
V_438 -> V_23 = & V_22 -> V_442 ;
V_216 = true ;
V_447 = true ;
}
if ( V_438 -> V_23 && V_216 )
V_18 = F_24 ( V_14 , V_438 -> V_23 , V_4 ) ;
if ( ! V_447 && V_448 ) {
F_7 ( V_14 , V_16 ) ;
V_16 = V_14 -> V_44 . V_313 ;
F_6 ( V_14 , V_16 ) ;
} else if ( V_438 -> V_23 && V_216 ) {
F_21 ( V_18 -> V_16 != V_438 -> V_16 ) ;
if ( V_6 -> V_11 & V_185 )
V_18 -> V_137 = true ;
F_48 ( V_16 -> V_77 , V_453 ) ;
F_71 ( & V_18 -> V_53 , V_4 ) ;
if ( ! V_438 -> V_23 -> V_132 )
F_9 ( V_14 , V_16 , V_18 ) ;
F_81 ( V_14 , V_16 ) ;
goto V_454;
}
V_39 = F_32 ( V_14 , V_16 , V_18 , V_4 ) ;
if ( ! V_39 ) {
F_20 ( V_14 , V_16 , V_4 ) ;
if ( V_438 -> V_455 )
F_191 ( V_4 ) ;
else
F_34 ( V_14 -> V_2 , V_4 ) ;
goto V_454;
}
V_39 -> V_61 . V_255 = V_438 -> V_455 ;
if ( V_438 -> V_455 )
V_39 -> V_61 . V_456 = V_457 ;
F_17 ( V_24 , V_8 , V_39 ) ;
F_169 ( V_14 , V_16 , V_18 , V_4 ) ;
V_454:
F_7 ( V_14 , V_16 ) ;
return 0 ;
}
void F_192 ( struct V_1 * V_2 , struct V_37 * V_24 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_2 -> V_350 ;
struct V_437 V_438 = {
. V_16 = V_14 -> V_395 . V_396
} ;
struct V_259 V_6 = {} ;
struct V_73 * V_74 ;
struct V_38 * V_351 = NULL ;
struct V_38 * V_39 ;
F_193 ( V_105 ) ;
int V_145 = 0 ;
int V_458 ;
V_458 =
V_14 -> V_394 -> V_395 . V_397 * 1000 *
V_14 -> V_394 -> V_395 . V_459 / V_460 ;
do {
struct V_31 * V_42 = F_13 ( V_4 ) ;
if ( F_183 ( V_2 , V_4 , & V_438 ) )
break;
V_39 = F_32 ( V_14 , V_438 . V_16 , NULL , V_4 ) ;
if ( ! V_39 )
break;
V_39 -> V_107 = V_39 ;
F_17 ( V_24 , NULL , V_39 ) ;
F_114 ( V_14 , V_39 , & V_6 , V_42 -> V_198 , false ) ;
V_145 += V_6 . V_41 [ 0 ] . V_287 ;
if ( V_351 )
V_351 -> V_104 = V_39 ;
F_12 ( & V_39 -> V_20 , & V_105 ) ;
V_351 = V_39 ;
V_4 = NULL ;
if ( V_145 > V_458 )
break;
V_4 = F_194 ( V_2 , V_24 ) ;
} while( V_4 );
if ( V_4 )
F_34 ( V_2 , V_4 ) ;
if ( F_11 ( & V_105 ) )
return;
V_39 = F_55 ( & V_105 , struct V_38 , V_20 ) ;
V_74 = (struct V_73 * ) V_39 -> V_40 -> V_79 ;
if ( V_74 -> V_80 & F_49 ( V_461 ) ) {
V_74 -> V_80 &= ~ F_49 ( V_461 ) ;
F_50 ( V_14 -> V_82 , V_39 -> V_83 ,
sizeof( * V_74 ) , V_84 ) ;
}
F_6 ( V_14 , V_438 . V_16 ) ;
F_124 ( V_14 , V_39 , V_438 . V_16 , 0 ) ;
F_128 ( V_14 , V_438 . V_16 , & V_105 , false ) ;
F_48 ( V_438 . V_16 -> V_77 , V_417 ) ;
F_7 ( V_14 , V_438 . V_16 ) ;
}
static void F_46 ( struct V_13 * V_14 , struct V_3 * V_4 ,
int V_462 , struct V_15 * V_16 ,
struct V_7 * V_8 )
{
struct V_5 * V_32 = F_2 ( V_4 ) ;
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
int V_440 , V_441 ;
unsigned long V_11 ;
F_130 ( V_263 , V_335 , L_9 , V_4 ) ;
if ( V_14 -> V_89 -> V_463 )
F_195 ( V_464 , & V_14 -> V_89 -> V_463 -> V_465 ) ;
if ( ! ( V_462 & V_71 ) ) {
if ( V_32 -> V_11 & V_315 )
V_32 -> V_11 |= V_466 ;
else
V_32 -> V_11 |= V_467 ;
}
if ( V_32 -> V_11 & V_12 ) {
V_440 = F_184 ( V_74 -> V_80 ) ;
V_441 = V_440 & 3 ;
if ( V_441 && V_4 -> V_260 > V_440 + V_441 ) {
memmove ( V_4 -> V_79 + V_441 , V_4 -> V_79 , V_440 ) ;
F_196 ( V_4 , V_441 ) ;
}
}
F_197 ( & V_14 -> V_468 , V_11 ) ;
if ( ( V_14 -> V_469 & V_470 ) && ! V_16 -> V_143 ) {
V_14 -> V_469 &= ~ V_470 ;
F_130 ( V_263 , V_471 ,
L_10 ,
V_14 -> V_469 & ( V_472 |
V_473 |
V_474 |
V_470 ) ) ;
}
F_198 ( & V_14 -> V_468 , V_11 ) ;
F_20 ( V_14 , V_16 , V_4 ) ;
V_32 -> V_9 . V_10 [ 0 ] = V_8 ;
F_71 ( & V_16 -> V_379 , V_4 ) ;
}
static void F_38 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct V_15 * V_16 , struct V_19 * V_105 ,
struct V_7 * V_8 ,
struct F_1 * V_58 , int V_93 )
{
struct V_3 * V_4 = V_39 -> V_40 ;
struct V_5 * V_32 = F_2 ( V_4 ) ;
unsigned long V_11 ;
int V_462 = 0 ;
if ( ! V_93 )
V_462 |= V_71 ;
if ( V_58 -> V_120 & V_135 )
V_32 -> V_11 |= V_475 ;
F_199 ( V_14 -> V_82 , V_39 -> V_83 , V_4 -> V_260 , V_84 ) ;
V_39 -> V_83 = 0 ;
if ( V_14 -> V_230 )
goto V_476;
if ( V_39 -> V_61 . V_255 ) {
if ( F_200 ( V_457 ,
V_39 -> V_61 . V_456 +
F_201 ( V_477 ) ) )
F_191 ( V_4 ) ;
else
F_202 ( & V_14 -> V_478 ) ;
} else {
F_203 ( V_14 , V_39 , V_58 , V_16 , V_462 ) ;
F_46 ( V_14 , V_4 , V_462 , V_16 , V_8 ) ;
}
V_476:
V_39 -> V_40 = NULL ;
F_197 ( & V_14 -> V_44 . V_85 , V_11 ) ;
F_164 ( V_105 , & V_14 -> V_44 . V_86 ) ;
F_198 ( & V_14 -> V_44 . V_85 , V_11 ) ;
}
static void F_68 ( struct V_13 * V_14 , struct V_38 * V_39 ,
struct F_1 * V_58 , int V_94 , int V_95 ,
int V_93 )
{
struct V_3 * V_4 = V_39 -> V_40 ;
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
struct V_5 * V_32 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_228 * V_229 = V_14 -> V_89 ;
T_2 V_122 , V_479 ;
if ( V_93 )
V_32 -> V_9 . V_480 = V_58 -> V_481 ;
V_479 = V_58 -> V_124 ;
F_21 ( V_479 >= V_2 -> V_482 ) ;
if ( V_32 -> V_11 & V_56 ) {
V_32 -> V_11 |= V_483 ;
F_143 ( V_95 > V_94 ) ;
}
V_32 -> V_9 . V_484 = V_94 ;
V_32 -> V_9 . V_485 = V_94 - V_95 ;
if ( ( V_58 -> V_120 & V_135 ) == 0 &&
( V_32 -> V_11 & V_315 ) == 0 ) {
if ( F_53 ( V_58 -> V_125 & ( V_486 |
V_487 ) ) &&
F_173 ( V_74 -> V_80 ) &&
V_229 -> V_488 >= V_14 -> V_89 -> V_489 . V_490 )
V_32 -> V_9 . V_41 [ V_479 ] . V_72 =
V_2 -> V_491 ;
}
for ( V_122 = V_479 + 1 ; V_122 < V_2 -> V_482 ; V_122 ++ ) {
V_32 -> V_9 . V_41 [ V_122 ] . V_72 = 0 ;
V_32 -> V_9 . V_41 [ V_122 ] . V_148 = - 1 ;
}
V_32 -> V_9 . V_41 [ V_479 ] . V_72 = V_58 -> V_123 + 1 ;
}
static void F_204 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_262 * V_263 = F_115 ( V_229 ) ;
struct V_38 * V_39 , * V_399 , * V_492 = NULL ;
struct V_19 V_57 ;
struct V_493 * V_494 ;
struct F_1 V_58 ;
int V_9 ;
F_130 ( V_263 , V_415 , L_11 ,
V_16 -> V_77 , F_205 ( V_14 -> V_89 , V_16 -> V_77 ) ,
V_16 -> V_378 ) ;
F_6 ( V_14 , V_16 ) ;
for (; ; ) {
if ( F_41 ( V_408 , & V_263 -> V_402 ) )
break;
if ( F_11 ( & V_16 -> V_380 ) ) {
V_16 -> V_378 = NULL ;
F_81 ( V_14 , V_16 ) ;
break;
}
V_39 = F_55 ( & V_16 -> V_380 , struct V_38 , V_20 ) ;
V_492 = NULL ;
if ( V_39 -> V_61 . V_92 ) {
V_492 = V_39 ;
if ( F_206 ( & V_492 -> V_20 , & V_16 -> V_380 ) )
break;
V_39 = F_162 ( V_492 -> V_20 . V_495 , struct V_38 ,
V_20 ) ;
}
V_399 = V_39 -> V_107 ;
V_494 = V_399 -> V_88 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_9 = F_207 ( V_229 , V_494 , & V_58 ) ;
if ( V_9 == - V_496 )
break;
F_48 ( V_16 -> V_77 , V_497 ) ;
V_399 -> V_61 . V_92 = true ;
F_36 ( & V_57 ) ;
if ( ! F_208 ( & V_399 -> V_20 ) )
F_151 ( & V_57 ,
& V_16 -> V_380 , V_399 -> V_20 . V_75 ) ;
if ( V_492 ) {
F_56 ( & V_492 -> V_20 ) ;
F_57 ( V_14 , V_492 ) ;
}
F_78 ( V_14 , V_16 , & V_58 , V_39 , & V_57 ) ;
}
F_8 ( V_14 , V_16 ) ;
}
void F_209 ( struct V_13 * V_14 )
{
struct V_228 * V_229 = V_14 -> V_89 ;
V_97 V_498 = ( ( 1 << V_403 ) - 1 ) & V_229 -> V_499 ;
int V_122 ;
F_153 () ;
for ( V_122 = 0 ; V_122 < V_403 ; V_122 ++ ) {
if ( F_140 ( V_14 , V_122 ) && ( V_498 & ( 1 << V_122 ) ) )
F_204 ( V_14 , & V_14 -> V_44 . V_16 [ V_122 ] ) ;
}
F_154 () ;
}
void F_210 ( struct V_13 * V_14 )
{
struct F_1 V_58 ;
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_228 * V_229 = V_14 -> V_89 ;
struct V_15 * V_16 ;
struct V_38 * V_39 , * V_399 ;
struct V_19 V_57 ;
struct V_19 * V_500 ;
int V_9 ;
F_153 () ;
for (; ; ) {
if ( F_41 ( V_408 , & V_263 -> V_402 ) )
break;
V_9 = F_207 ( V_229 , NULL , ( void * ) & V_58 ) ;
if ( V_9 == - V_496 )
break;
if ( V_9 == - V_391 ) {
F_130 ( V_263 , V_335 , L_12 ) ;
break;
}
if ( V_58 . V_501 == V_14 -> V_395 . V_502 ) {
V_14 -> V_395 . V_503 = true ;
V_14 -> V_395 . V_504 = ! ( V_58 . V_120 & V_141 ) ;
if ( F_22 () ) {
F_211 ( V_14 , NULL ,
V_505 ) ;
}
F_212 ( V_14 ) ;
continue;
}
V_16 = & V_14 -> V_44 . V_16 [ V_58 . V_501 ] ;
F_6 ( V_14 , V_16 ) ;
F_48 ( V_16 -> V_77 , V_497 ) ;
V_500 = & V_16 -> V_386 [ V_16 -> V_384 ] ;
if ( F_11 ( V_500 ) ) {
F_7 ( V_14 , V_16 ) ;
return;
}
V_39 = F_55 ( V_500 , struct V_38 , V_20 ) ;
if ( V_39 -> V_61 . V_92 ) {
F_56 ( & V_39 -> V_20 ) ;
F_57 ( V_14 , V_39 ) ;
V_39 = F_55 ( V_500 , struct V_38 , V_20 ) ;
}
V_399 = V_39 -> V_107 ;
F_36 ( & V_57 ) ;
if ( F_206 ( & V_399 -> V_20 , V_500 ) ) {
F_164 ( V_500 , & V_57 ) ;
F_42 ( V_16 -> V_384 , V_385 ) ;
if ( ! F_11 ( & V_16 -> V_380 ) ) {
struct V_19 V_105 ;
F_36 ( & V_105 ) ;
V_16 -> V_378 = NULL ;
F_164 ( & V_16 -> V_380 , & V_105 ) ;
F_128 ( V_14 , V_16 , & V_105 , true ) ;
}
} else {
V_399 -> V_61 . V_92 = true ;
if ( V_39 != V_399 )
F_151 ( & V_57 , V_500 ,
V_399 -> V_20 . V_75 ) ;
}
F_78 ( V_14 , V_16 , & V_58 , V_39 , & V_57 ) ;
F_8 ( V_14 , V_16 ) ;
}
F_154 () ;
}
static int F_213 ( struct V_13 * V_14 , int V_506 )
{
struct V_507 * V_508 = & V_14 -> V_509 ;
T_2 V_510 = V_14 -> V_89 -> V_90 . V_510 ;
V_508 -> V_511 = V_506 * V_510 ;
V_508 -> V_512 = F_214 ( V_14 -> V_82 , V_508 -> V_511 ,
& V_508 -> V_513 , V_514 ) ;
if ( ! V_508 -> V_512 )
return - V_446 ;
return 0 ;
}
static int F_215 ( struct V_13 * V_14 )
{
int V_515 ;
V_515 = F_213 ( V_14 , V_516 ) ;
if ( ! V_515 )
F_216 ( V_14 -> V_89 , V_14 -> V_509 . V_512 ,
V_14 -> V_509 . V_513 ,
V_516 ) ;
return V_515 ;
}
int F_217 ( struct V_13 * V_14 , int V_517 )
{
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
int error = 0 ;
F_141 ( & V_14 -> V_44 . V_85 ) ;
error = F_218 ( V_14 , & V_14 -> V_44 . V_518 , & V_14 -> V_44 . V_86 ,
L_13 , V_517 , 1 , 1 ) ;
if ( error != 0 ) {
F_146 ( V_263 ,
L_14 , error ) ;
return error ;
}
error = F_218 ( V_14 , & V_14 -> V_395 . V_519 , & V_14 -> V_395 . V_520 ,
L_15 , V_460 , 1 , 1 ) ;
if ( error != 0 ) {
F_146 ( V_263 ,
L_16 , error ) ;
return error ;
}
F_219 ( & V_14 -> V_521 , V_522 ) ;
if ( V_14 -> V_89 -> V_90 . V_176 & V_177 )
error = F_215 ( V_14 ) ;
return error ;
}
void F_220 ( struct V_13 * V_14 , struct V_50 * V_23 )
{
struct V_17 * V_18 ;
int V_30 , V_523 ;
for ( V_30 = 0 , V_18 = & V_23 -> V_18 [ V_30 ] ;
V_30 < V_344 ;
V_30 ++ , V_18 ++ ) {
V_18 -> V_23 = V_23 ;
V_18 -> V_30 = V_30 ;
V_18 -> V_62 = V_18 -> V_342 = 0 ;
V_18 -> V_129 = V_524 ;
V_18 -> V_65 = V_18 -> V_68 = 0 ;
V_18 -> V_130 = false ;
V_18 -> V_137 = true ;
F_65 ( & V_18 -> V_53 ) ;
F_65 ( & V_18 -> V_54 ) ;
F_36 ( & V_18 -> V_20 ) ;
V_523 = F_10 ( V_30 ) ;
V_18 -> V_16 = V_14 -> V_44 . V_45 [ V_523 ] ;
}
}
void F_221 ( struct V_13 * V_14 , struct V_50 * V_23 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
int V_30 ;
for ( V_30 = 0 , V_18 = & V_23 -> V_18 [ V_30 ] ;
V_30 < V_344 ; V_30 ++ , V_18 ++ ) {
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( ! F_11 ( & V_18 -> V_20 ) )
F_134 ( & V_18 -> V_20 ) ;
F_45 ( V_14 , V_16 , V_18 ) ;
V_18 -> V_130 = false ;
F_7 ( V_14 , V_16 ) ;
}
}
int F_222 ( struct V_13 * V_14 , struct V_3 * V_4 ,
struct V_437 * V_438 )
{
struct V_73 * V_74 = (struct V_73 * ) V_4 -> V_79 ;
struct V_31 * V_42 = F_13 ( V_4 ) ;
struct V_262 * V_263 = F_115 ( V_14 -> V_89 ) ;
struct V_38 * V_39 ;
int V_440 , V_441 ;
V_440 = F_184 ( V_74 -> V_80 ) ;
V_441 = V_440 & 3 ;
if ( V_441 && V_4 -> V_260 > V_440 ) {
if ( F_185 ( V_4 ) < V_441 ) {
F_130 ( V_263 , V_335 ,
L_17 ) ;
return - V_525 ;
}
F_186 ( V_4 , V_441 ) ;
memmove ( V_4 -> V_79 , V_4 -> V_79 + V_441 , V_440 ) ;
}
V_42 -> V_174 = V_175 ;
V_42 -> V_198 = V_4 -> V_260 + V_439 ;
V_42 -> V_323 = V_526 ;
V_39 = F_32 ( V_14 , V_438 -> V_16 , NULL , V_4 ) ;
if ( ! V_39 ) {
F_130 ( V_263 , V_335 , L_18 ) ;
return - V_525 ;
}
F_17 ( V_14 -> V_527 , NULL , V_39 ) ;
F_165 ( V_14 -> V_89 , V_39 -> V_88 , V_39 -> V_311 ) ;
F_223 ( V_14 -> V_89 , V_438 -> V_16 -> V_77 ) ;
F_169 ( V_14 , V_438 -> V_16 , NULL , V_4 ) ;
return 0 ;
}
