void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
__acquires( &txq->axq_lock
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
__releases( &txq->axq_lock
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
static struct V_14 * F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
F_8 ( sizeof( struct V_14 ) >
sizeof( V_18 -> V_19 ) ) ;
return (struct V_14 * ) & V_18 -> V_19 [ 0 ] ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_20 )
{
if ( ! V_6 -> V_21 -> V_22 )
return;
F_10 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 -> V_24 , V_6 -> V_25 ,
V_20 << V_26 ) ;
}
static void F_11 ( struct V_27 * V_23 , struct V_28 * V_22 ,
struct V_29 * V_30 )
{
F_12 ( V_23 , V_22 , V_30 -> V_31 , V_30 -> V_32 ,
F_13 ( V_30 -> V_32 ) ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 )
{
int V_33 ;
V_33 = F_15 ( V_16 ) ;
if ( V_4 == V_2 -> V_34 . V_35 )
V_4 = V_2 -> V_34 . V_36 [ V_33 ] ;
if ( V_4 != V_2 -> V_34 . V_36 [ V_33 ] )
return;
if ( F_16 ( -- V_4 -> V_37 < 0 ) )
V_4 -> V_37 = 0 ;
if ( V_4 -> V_38 &&
V_4 -> V_37 < V_2 -> V_34 . V_39 [ V_33 ] ) {
F_17 ( V_2 -> V_40 , V_33 ) ;
V_4 -> V_38 = false ;
}
}
static struct V_5 *
F_18 ( struct V_1 * V_2 , struct V_41 * V_21 , struct V_15 * V_16 )
{
T_2 V_25 = V_16 -> V_42 & V_43 ;
return F_19 ( V_21 , V_25 ) ;
}
static bool F_20 ( struct V_5 * V_6 )
{
return ! F_21 ( & V_6 -> V_44 ) || ! F_21 ( & V_6 -> V_45 ) ;
}
static struct V_15 * F_22 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
V_16 = F_23 ( & V_6 -> V_45 ) ;
if ( ! V_16 )
V_16 = F_23 ( & V_6 -> V_44 ) ;
return V_16 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_17 * V_18 ;
struct V_15 * V_16 , * V_46 ;
struct V_29 * V_30 ;
struct V_14 * V_47 ;
F_25 (&tid->buf_q, skb, tskb) {
V_47 = F_6 ( V_16 ) ;
V_30 = V_47 -> V_30 ;
V_18 = F_7 ( V_16 ) ;
V_18 -> V_48 &= ~ V_49 ;
if ( V_30 )
continue;
V_30 = F_26 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_27 ( V_16 , & V_6 -> V_44 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
F_28 ( V_2 -> V_40 , V_16 ) ;
continue;
}
}
}
static void F_29 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
struct V_14 * V_47 ;
bool V_54 = false ;
F_30 ( & V_51 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
while ( ( V_16 = F_23 ( & V_6 -> V_45 ) ) ) {
V_47 = F_6 ( V_16 ) ;
V_30 = V_47 -> V_30 ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
F_28 ( V_2 -> V_40 , V_16 ) ;
continue;
}
if ( V_47 -> V_55 ) {
F_31 ( V_2 , V_6 , V_30 -> V_56 . V_20 ) ;
V_54 = true ;
}
F_5 ( & V_30 -> V_11 , & V_51 ) ;
F_32 ( V_2 , V_30 , V_4 , & V_51 , & V_53 , 0 ) ;
}
if ( V_54 ) {
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , V_6 -> V_57 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_20 )
{
int V_58 , V_59 ;
V_58 = F_33 ( V_6 -> V_57 , V_20 ) ;
V_59 = ( V_6 -> V_60 + V_58 ) & ( V_61 - 1 ) ;
F_34 ( V_59 , V_6 -> V_62 ) ;
while ( V_6 -> V_60 != V_6 -> V_63 && ! F_35 ( V_6 -> V_60 , V_6 -> V_62 ) ) {
F_36 ( V_6 -> V_57 , V_64 ) ;
F_36 ( V_6 -> V_60 , V_61 ) ;
if ( V_6 -> V_65 >= 0 )
V_6 -> V_65 -- ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_14 * V_47 = F_6 ( V_30 -> V_31 ) ;
T_1 V_20 = V_30 -> V_56 . V_20 ;
int V_58 , V_59 ;
V_58 = F_33 ( V_6 -> V_57 , V_20 ) ;
V_59 = ( V_6 -> V_60 + V_58 ) & ( V_61 - 1 ) ;
F_38 ( V_59 , V_6 -> V_62 ) ;
V_47 -> V_55 = 1 ;
if ( V_58 >= ( ( V_6 -> V_63 - V_6 -> V_60 ) &
( V_61 - 1 ) ) ) {
V_6 -> V_63 = V_59 ;
F_36 ( V_6 -> V_63 , V_61 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
struct V_14 * V_47 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_30 ( & V_51 ) ;
while ( ( V_16 = F_22 ( V_6 ) ) ) {
V_47 = F_6 ( V_16 ) ;
V_30 = V_47 -> V_30 ;
if ( ! V_30 ) {
F_40 ( V_2 , V_16 , V_66 , V_4 ) ;
continue;
}
F_5 ( & V_30 -> V_11 , & V_51 ) ;
F_32 ( V_2 , V_30 , V_4 , & V_51 , & V_53 , 0 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , int V_67 )
{
struct V_14 * V_47 = F_6 ( V_16 ) ;
struct V_29 * V_30 = V_47 -> V_30 ;
struct V_68 * V_69 ;
int V_70 = V_47 -> V_71 ;
F_42 ( V_4 -> V_72 , V_73 ) ;
V_47 -> V_71 += V_67 ;
if ( V_70 > 0 )
return;
V_69 = (struct V_68 * ) V_16 -> V_74 ;
V_69 -> V_75 |= F_43 ( V_76 ) ;
F_44 ( V_2 -> V_77 , V_30 -> V_78 ,
sizeof( * V_69 ) , V_79 ) ;
}
static struct V_29 * F_45 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = NULL ;
F_46 ( & V_2 -> V_34 . V_80 ) ;
if ( F_47 ( F_48 ( & V_2 -> V_34 . V_81 ) ) ) {
F_49 ( & V_2 -> V_34 . V_80 ) ;
return NULL ;
}
V_30 = F_50 ( & V_2 -> V_34 . V_81 , struct V_29 , V_11 ) ;
F_51 ( & V_30 -> V_11 ) ;
F_49 ( & V_2 -> V_34 . V_80 ) ;
return V_30 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
F_46 ( & V_2 -> V_34 . V_80 ) ;
F_5 ( & V_30 -> V_11 , & V_2 -> V_34 . V_81 ) ;
F_49 ( & V_2 -> V_34 . V_80 ) ;
}
static struct V_29 * F_53 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_29 * V_82 ;
V_82 = F_45 ( V_2 ) ;
if ( F_16 ( ! V_82 ) )
return NULL ;
F_54 ( V_82 ) ;
V_82 -> V_31 = V_30 -> V_31 ;
V_82 -> V_78 = V_30 -> V_78 ;
memcpy ( V_82 -> V_83 , V_30 -> V_83 , V_2 -> V_84 -> V_85 . V_86 ) ;
V_82 -> V_56 = V_30 -> V_56 ;
V_82 -> V_56 . V_87 = false ;
return V_82 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_52 * V_53 , int V_88 ,
int * V_89 , int * V_90 )
{
struct V_14 * V_47 ;
T_1 V_91 = 0 ;
V_92 V_93 [ V_94 >> 5 ] ;
int V_95 ;
int V_96 = 0 ;
* V_90 = 0 ;
* V_89 = 0 ;
V_96 = F_56 ( V_30 ) ;
if ( V_96 ) {
V_91 = V_53 -> V_97 ;
memcpy ( V_93 , & V_53 -> V_98 , V_94 >> 3 ) ;
}
while ( V_30 ) {
V_47 = F_6 ( V_30 -> V_31 ) ;
V_95 = F_33 ( V_91 , V_30 -> V_56 . V_20 ) ;
( * V_89 ) ++ ;
if ( ! V_88 || ( V_96 && ! F_57 ( V_93 , V_95 ) ) )
( * V_90 ) ++ ;
V_30 = V_30 -> V_99 ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_30 , struct V_50 * V_100 ,
struct V_52 * V_53 , int V_88 )
{
struct V_41 * V_21 = NULL ;
struct V_15 * V_16 ;
struct V_28 * V_22 ;
struct V_101 * V_40 = V_2 -> V_40 ;
struct V_68 * V_69 ;
struct V_17 * V_18 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_99 , * V_102 = V_30 -> V_103 ;
struct V_50 V_51 ;
struct V_104 V_105 ;
T_1 V_91 = 0 , V_106 = 0 , V_107 = 0 , V_108 ;
V_92 V_93 [ V_94 >> 5 ] ;
int V_96 , V_109 , V_110 , V_54 = 0 , V_111 = 0 , V_90 = 0 ;
bool V_112 = true , V_113 ;
struct V_114 V_32 [ 4 ] ;
struct V_14 * V_47 ;
int V_89 ;
bool V_115 = ! ! ( V_53 -> V_116 & V_117 ) ;
int V_118 , V_71 ;
int V_65 = - 1 ;
V_16 = V_30 -> V_31 ;
V_69 = (struct V_68 * ) V_16 -> V_74 ;
V_18 = F_7 ( V_16 ) ;
memcpy ( V_32 , V_30 -> V_32 , sizeof( V_32 ) ) ;
V_71 = V_53 -> V_119 + 1 ;
for ( V_118 = 0 ; V_118 < V_53 -> V_120 ; V_118 ++ )
V_71 += V_32 [ V_118 ] . V_67 ;
F_59 () ;
V_22 = F_60 ( V_40 , V_69 -> V_121 , V_69 -> V_122 ) ;
if ( ! V_22 ) {
F_61 () ;
F_30 ( & V_51 ) ;
while ( V_30 ) {
V_99 = V_30 -> V_99 ;
if ( ! V_30 -> V_56 . V_87 || V_99 != NULL )
F_62 ( & V_30 -> V_11 , & V_51 ) ;
F_32 ( V_2 , V_30 , V_4 , & V_51 , V_53 , 0 ) ;
V_30 = V_99 ;
}
return;
}
V_21 = (struct V_41 * ) V_22 -> V_123 ;
V_6 = F_18 ( V_2 , V_21 , V_16 ) ;
V_108 = V_6 -> V_57 ;
V_113 = V_53 -> V_124 & V_125 ;
if ( V_113 && V_6 -> V_25 != V_53 -> V_6 )
V_88 = false ;
V_96 = F_56 ( V_30 ) ;
memset ( V_93 , 0 , V_94 >> 3 ) ;
if ( V_96 && V_88 ) {
if ( V_53 -> V_124 & V_125 ) {
V_91 = V_53 -> V_97 ;
memcpy ( V_93 , & V_53 -> V_98 , V_94 >> 3 ) ;
} else {
if ( V_2 -> V_84 -> V_126 == V_127 )
V_111 = 1 ;
}
}
F_63 ( & V_105 ) ;
F_55 ( V_2 , V_30 , V_53 , V_88 , & V_89 , & V_90 ) ;
while ( V_30 ) {
T_1 V_20 = V_30 -> V_56 . V_20 ;
V_109 = V_110 = V_54 = 0 ;
V_99 = V_30 -> V_99 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_47 = F_6 ( V_16 ) ;
if ( ! F_64 ( V_6 -> V_57 , V_6 -> V_128 , V_20 ) ||
! V_6 -> V_129 ) {
V_109 = 1 ;
} else if ( F_57 ( V_93 , F_33 ( V_91 , V_20 ) ) ) {
V_106 ++ ;
} else if ( ! V_96 && V_88 ) {
V_106 ++ ;
} else if ( V_115 ) {
V_110 = 1 ;
} else if ( V_47 -> V_71 < V_130 ) {
if ( V_88 || ! V_21 -> V_131 )
F_41 ( V_2 , V_4 , V_30 -> V_31 ,
V_71 ) ;
V_110 = 1 ;
} else {
V_109 = 1 ;
V_107 ++ ;
V_65 = F_65 ( int , V_65 ,
F_33 ( V_108 , V_20 ) ) ;
}
F_30 ( & V_51 ) ;
if ( V_99 != NULL || ! V_102 -> V_56 . V_87 )
F_62 ( & V_30 -> V_11 , & V_51 ) ;
if ( ! V_110 ) {
F_31 ( V_2 , V_6 , V_20 ) ;
if ( V_112 && ( V_106 == 1 || V_107 == 1 ) ) {
memcpy ( V_18 -> V_132 . V_32 , V_32 , sizeof( V_32 ) ) ;
F_66 ( V_2 , V_30 , V_53 , V_89 , V_90 , V_88 ) ;
V_112 = false ;
}
F_32 ( V_2 , V_30 , V_4 , & V_51 , V_53 ,
! V_109 ) ;
} else {
if ( V_18 -> V_48 & V_133 ) {
V_18 -> V_48 &= ~ V_133 ;
F_67 ( V_22 ) ;
}
if ( V_30 -> V_99 == NULL && V_102 -> V_56 . V_87 ) {
struct V_29 * V_82 ;
V_82 = F_53 ( V_2 , V_102 ) ;
if ( ! V_82 ) {
F_31 ( V_2 , V_6 , V_20 ) ;
F_32 ( V_2 , V_30 , V_4 ,
& V_51 , V_53 , 0 ) ;
V_65 = F_65 ( int , V_65 ,
F_33 ( V_108 , V_20 ) ) ;
break;
}
V_47 -> V_30 = V_82 ;
}
F_68 ( & V_105 , V_16 ) ;
}
V_30 = V_99 ;
}
if ( ! F_21 ( & V_105 ) ) {
if ( V_21 -> V_131 )
F_69 ( V_22 , V_6 -> V_25 , true ) ;
F_70 ( & V_105 , & V_6 -> V_45 ) ;
if ( ! V_21 -> V_131 ) {
F_4 ( V_4 , V_6 ) ;
if ( V_53 -> V_116 & ( V_134 | V_135 ) )
V_6 -> V_8 -> V_136 = true ;
}
}
if ( V_65 >= 0 ) {
T_1 V_137 = F_71 ( V_108 , V_65 ) ;
if ( F_64 ( V_6 -> V_57 , V_6 -> V_128 , V_137 ) )
V_6 -> V_65 = F_33 ( V_6 -> V_57 , V_137 ) ;
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , F_71 ( V_108 , V_65 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_61 () ;
if ( V_111 )
F_72 ( V_2 , V_138 ) ;
}
static bool F_73 ( struct V_29 * V_30 )
{
struct V_17 * V_139 = F_7 ( V_30 -> V_31 ) ;
return F_74 ( V_30 ) && ! ( V_139 -> V_48 & V_140 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_52 * V_53 , struct V_29 * V_30 ,
struct V_50 * V_51 )
{
struct V_17 * V_139 ;
bool V_88 , V_115 ;
V_88 = ! ( V_53 -> V_116 & V_141 ) ;
V_115 = ! ! ( V_53 -> V_116 & V_117 ) ;
V_4 -> V_142 = false ;
V_4 -> V_143 -- ;
if ( F_73 ( V_30 ) )
V_4 -> V_144 -- ;
if ( ! F_74 ( V_30 ) ) {
if ( ! V_115 ) {
V_139 = F_7 ( V_30 -> V_31 ) ;
memcpy ( V_139 -> V_132 . V_32 , V_30 -> V_32 ,
sizeof( V_139 -> V_132 . V_32 ) ) ;
F_66 ( V_2 , V_30 , V_53 , 1 , V_88 ? 0 : 1 , V_88 ) ;
}
F_32 ( V_2 , V_30 , V_4 , V_51 , V_53 , V_88 ) ;
} else
F_58 ( V_2 , V_4 , V_30 , V_51 , V_53 , V_88 ) ;
if ( ! V_115 )
F_76 ( V_2 , V_4 ) ;
}
static bool F_77 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_114 * V_32 ;
int V_118 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_18 -> V_132 . V_32 ;
for ( V_118 = 0 ; V_118 < 4 ; V_118 ++ ) {
if ( ! V_32 [ V_118 ] . V_67 || V_32 [ V_118 ] . V_145 < 0 )
break;
if ( ! ( V_32 [ V_118 ] . V_48 & V_146 ) )
return true ;
}
return false ;
}
static V_92 F_78 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_114 * V_32 ;
V_92 V_147 , V_148 ;
T_1 V_149 , V_150 , V_151 = 0 ;
int V_33 = V_6 -> V_8 -> V_4 -> V_152 ;
int V_118 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_147 = V_153 ;
for ( V_118 = 0 ; V_118 < 4 ; V_118 ++ ) {
int V_154 ;
if ( ! V_32 [ V_118 ] . V_67 )
continue;
if ( ! ( V_32 [ V_118 ] . V_48 & V_146 ) ) {
V_151 = 1 ;
break;
}
if ( V_32 [ V_118 ] . V_48 & V_155 )
V_154 = V_156 ;
else
V_154 = V_157 ;
if ( V_32 [ V_118 ] . V_48 & V_158 )
V_154 ++ ;
V_148 = V_2 -> V_34 . V_159 [ V_33 ] [ V_154 ] [ V_32 [ V_118 ] . V_145 ] ;
V_147 = F_79 ( V_147 , V_148 ) ;
}
if ( V_18 -> V_48 & V_140 || V_151 )
return 0 ;
V_149 = F_79 ( V_147 , ( V_92 ) V_153 ) ;
V_150 = F_80 ( V_2 , V_147 ) ;
if ( V_150 )
V_149 = V_150 ;
if ( V_6 -> V_21 -> V_160 )
V_149 = F_79 ( V_149 , V_6 -> V_21 -> V_160 ) ;
return V_149 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 V_148 ,
bool V_161 )
{
#define F_82 60
V_92 V_162 , V_163 ;
T_1 V_164 ;
T_2 V_48 , V_165 ;
int V_166 , V_167 , V_168 , V_169 , V_170 ;
struct V_14 * V_47 = F_6 ( V_30 -> V_31 ) ;
V_169 = F_83 ( V_148 ) ;
if ( ( V_47 -> V_171 != V_172 ) &&
! ( V_2 -> V_84 -> V_85 . V_173 & V_174 ) )
V_169 += V_175 ;
if ( V_161 && ! F_84 ( V_2 -> V_84 ) &&
( V_2 -> V_84 -> V_176 & V_177 ) )
V_169 = F_85 ( V_169 , F_82 ) ;
if ( V_6 -> V_21 -> V_178 == 0 )
return V_169 ;
V_165 = V_30 -> V_32 [ 0 ] . V_145 ;
V_48 = V_30 -> V_32 [ 0 ] . V_48 ;
V_166 = ( V_48 & V_155 ) ? 1 : 0 ;
V_168 = ( V_48 & V_158 ) ? 1 : 0 ;
if ( V_168 )
V_163 = F_86 ( V_6 -> V_21 -> V_178 ) ;
else
V_163 = F_87 ( V_6 -> V_21 -> V_178 ) ;
if ( V_163 == 0 )
V_163 = 1 ;
V_167 = F_88 ( V_165 ) ;
V_162 = V_179 [ V_165 % 8 ] [ V_166 ] * V_167 ;
V_164 = ( V_163 * V_162 ) / V_180 ;
if ( V_148 < V_164 ) {
V_170 = ( V_164 - V_148 ) / V_181 ;
V_169 = F_85 ( V_170 , V_169 ) ;
}
return V_169 ;
}
static struct V_29 *
F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_104 * * V_33 )
{
struct V_17 * V_18 ;
struct V_14 * V_47 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
T_1 V_20 ;
while ( 1 ) {
* V_33 = & V_6 -> V_45 ;
if ( F_21 ( * V_33 ) )
* V_33 = & V_6 -> V_44 ;
V_16 = F_90 ( * V_33 ) ;
if ( ! V_16 )
break;
V_47 = F_6 ( V_16 ) ;
V_30 = V_47 -> V_30 ;
if ( ! V_47 -> V_30 )
V_30 = F_26 ( V_2 , V_4 , V_6 , V_16 ) ;
else
V_30 -> V_56 . V_87 = false ;
if ( ! V_30 ) {
F_27 ( V_16 , * V_33 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
F_28 ( V_2 -> V_40 , V_16 ) ;
continue;
}
V_30 -> V_99 = NULL ;
V_30 -> V_103 = V_30 ;
V_18 = F_7 ( V_16 ) ;
V_18 -> V_48 &= ~ V_182 ;
if ( ! ( V_18 -> V_48 & V_49 ) ) {
V_30 -> V_56 . V_183 = 0 ;
return V_30 ;
}
V_30 -> V_56 . V_183 = V_184 | V_185 ;
V_20 = V_30 -> V_56 . V_20 ;
if ( ! F_64 ( V_6 -> V_57 , V_6 -> V_128 , V_20 ) )
break;
if ( V_6 -> V_65 > F_33 ( V_6 -> V_57 , V_20 ) ) {
struct V_52 V_53 = {} ;
struct V_50 V_51 ;
F_30 ( & V_51 ) ;
F_91 ( & V_30 -> V_11 , & V_51 ) ;
F_27 ( V_16 , * V_33 ) ;
F_31 ( V_2 , V_6 , V_20 ) ;
F_32 ( V_2 , V_30 , V_4 , & V_51 , & V_53 , 0 ) ;
continue;
}
return V_30 ;
}
return NULL ;
}
static bool
F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_50 * V_100 ,
struct V_29 * V_186 , struct V_104 * V_12 ,
int * V_187 )
{
#define F_93 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_29 * V_30 = V_186 , * V_188 = NULL ;
int V_89 = 0 , V_169 ;
T_1 V_149 = 0 , V_189 = 0 , V_190 = 0 ,
V_191 , V_192 = V_6 -> V_128 / 2 ;
struct V_17 * V_18 ;
struct V_14 * V_47 ;
struct V_15 * V_16 ;
bool V_193 = false ;
V_30 = V_186 ;
V_149 = F_78 ( V_2 , V_30 , V_6 ) ;
do {
V_16 = V_30 -> V_31 ;
V_47 = F_6 ( V_16 ) ;
V_191 = V_181 + V_47 -> V_194 ;
if ( V_89 ) {
if ( V_149 < V_189 + V_190 + V_191 ||
F_77 ( V_30 ) || V_89 >= V_192 )
break;
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( ( V_18 -> V_48 & V_140 ) ||
! ( V_18 -> V_48 & V_49 ) )
break;
}
V_189 += V_190 + V_191 ;
V_169 = F_81 ( V_2 , V_6 , V_186 , V_47 -> V_194 ,
! V_89 ) ;
V_190 = F_93 ( V_191 ) + ( V_169 << 2 ) ;
V_89 ++ ;
V_30 -> V_99 = NULL ;
if ( ! V_47 -> V_55 )
F_37 ( V_2 , V_6 , V_30 ) ;
V_30 -> V_56 . V_169 = V_169 ;
F_27 ( V_16 , V_12 ) ;
F_5 ( & V_30 -> V_11 , V_100 ) ;
if ( V_188 )
V_188 -> V_99 = V_30 ;
V_188 = V_30 ;
V_30 = F_89 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 ) {
V_193 = true ;
break;
}
} while ( F_20 ( V_6 ) );
V_30 = V_186 ;
V_30 -> V_103 = V_188 ;
if ( V_30 == V_188 ) {
V_189 = F_6 ( V_30 -> V_31 ) -> V_194 ;
V_30 -> V_56 . V_183 = V_184 ;
} else {
F_42 ( V_4 -> V_72 , V_195 ) ;
}
* V_187 = V_189 ;
return V_193 ;
#undef F_93
}
static V_92 F_94 ( struct V_1 * V_2 , T_2 V_165 , int V_196 ,
int V_166 , int V_168 , bool V_197 )
{
V_92 V_198 , V_162 , V_199 , V_163 ;
int V_167 ;
V_167 = F_88 ( V_165 ) ;
V_198 = ( V_196 << 3 ) + V_200 ;
V_162 = V_179 [ V_165 % 8 ] [ V_166 ] * V_167 ;
V_163 = ( V_198 + V_162 - 1 ) / V_162 ;
if ( ! V_168 )
V_199 = F_95 ( V_163 ) ;
else
V_199 = F_96 ( V_163 ) ;
V_199 += V_201 + V_202 + V_203 + V_204 + V_205 + F_97 ( V_167 ) ;
return V_199 ;
}
static int F_98 ( int V_206 , int V_207 , bool V_208 , bool V_209 )
{
int V_167 = F_88 ( V_207 ) ;
int V_210 , V_211 ;
int V_212 = 0 ;
V_210 = V_209 ? F_99 ( V_206 ) : F_100 ( V_206 ) ;
V_211 = V_210 * V_179 [ V_207 % 8 ] [ V_208 ] * V_167 ;
V_211 -= V_200 ;
V_212 = V_211 / 8 ;
V_212 -= V_201 + V_202 + V_203 + V_204 + V_205 + F_97 ( V_167 ) ;
if ( V_212 > 65532 )
V_212 = 65532 ;
return V_212 ;
}
void F_101 ( struct V_1 * V_2 , int V_213 , int V_214 )
{
T_1 * V_215 , * V_216 , * V_217 , * V_218 ;
int V_207 ;
if ( ! V_214 || V_214 > 4096 )
V_214 = 4096 ;
V_215 = V_2 -> V_34 . V_159 [ V_213 ] [ V_157 ] ;
V_216 = V_2 -> V_34 . V_159 [ V_213 ] [ V_219 ] ;
V_217 = V_2 -> V_34 . V_159 [ V_213 ] [ V_156 ] ;
V_218 = V_2 -> V_34 . V_159 [ V_213 ] [ V_220 ] ;
for ( V_207 = 0 ; V_207 < 32 ; V_207 ++ ) {
V_215 [ V_207 ] = F_98 ( V_214 , V_207 , false , false ) ;
V_216 [ V_207 ] = F_98 ( V_214 , V_207 , false , true ) ;
V_217 [ V_207 ] = F_98 ( V_214 , V_207 , true , false ) ;
V_218 [ V_207 ] = F_98 ( V_214 , V_207 , true , true ) ;
}
}
static void F_102 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_221 * V_139 , int V_222 , bool V_223 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_114 * V_32 ;
const struct V_226 * V_227 ;
struct V_68 * V_69 ;
struct V_14 * V_47 = F_6 ( V_30 -> V_31 ) ;
V_92 V_228 = V_2 -> V_40 -> V_229 -> V_230 ;
int V_118 ;
T_2 V_165 = 0 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_69 = (struct V_68 * ) V_16 -> V_74 ;
V_139 -> V_231 = ! F_103 ( V_69 -> V_75 ) ;
V_139 -> V_232 = V_47 -> V_232 ;
for ( V_118 = 0 ; V_118 < F_13 ( V_30 -> V_32 ) ; V_118 ++ ) {
bool V_233 , V_234 , V_235 ;
int V_236 ;
if ( ! V_32 [ V_118 ] . V_67 || ( V_32 [ V_118 ] . V_145 < 0 ) )
continue;
V_165 = V_32 [ V_118 ] . V_145 ;
V_139 -> V_32 [ V_118 ] . V_237 = V_32 [ V_118 ] . V_67 ;
if ( F_74 ( V_30 ) && ! F_56 ( V_30 ) &&
( V_32 [ V_118 ] . V_48 & V_146 ) &&
F_47 ( V_228 != ( V_92 ) - 1 ) ) {
if ( ! V_228 || ( V_222 > V_228 ) )
V_223 = true ;
}
if ( V_223 || V_32 [ V_118 ] . V_48 & V_238 ) {
V_139 -> V_32 [ V_118 ] . V_239 |= V_240 ;
V_139 -> V_48 |= V_241 ;
} else if ( V_32 [ V_118 ] . V_48 & V_242 ) {
V_139 -> V_32 [ V_118 ] . V_239 |= V_240 ;
V_139 -> V_48 |= V_243 ;
}
if ( V_32 [ V_118 ] . V_48 & V_155 )
V_139 -> V_32 [ V_118 ] . V_239 |= V_244 ;
if ( V_32 [ V_118 ] . V_48 & V_158 )
V_139 -> V_32 [ V_118 ] . V_239 |= V_245 ;
V_234 = ! ! ( V_32 [ V_118 ] . V_48 & V_158 ) ;
V_233 = ! ! ( V_32 [ V_118 ] . V_48 & V_155 ) ;
V_235 = ! ! ( V_32 [ V_118 ] . V_48 & V_246 ) ;
if ( V_32 [ V_118 ] . V_48 & V_146 ) {
V_139 -> V_32 [ V_118 ] . V_247 = V_165 | 0x80 ;
V_139 -> V_32 [ V_118 ] . V_248 = F_104 ( V_2 ,
V_225 -> V_249 , V_139 -> V_32 [ V_118 ] . V_247 ) ;
V_139 -> V_32 [ V_118 ] . V_250 = F_94 ( V_2 , V_165 , V_222 ,
V_233 , V_234 , V_235 ) ;
if ( V_165 < 8 && ( V_18 -> V_48 & V_251 ) )
V_139 -> V_32 [ V_118 ] . V_239 |= V_252 ;
continue;
}
V_227 = & V_2 -> V_253 [ V_18 -> V_254 ] . V_255 [ V_32 [ V_118 ] . V_145 ] ;
if ( ( V_18 -> V_254 == V_256 ) &&
! ( V_227 -> V_48 & V_257 ) )
V_236 = V_258 ;
else
V_236 = V_259 ;
V_139 -> V_32 [ V_118 ] . V_247 = V_227 -> V_260 ;
if ( V_227 -> V_261 ) {
if ( V_32 [ V_118 ] . V_48 & V_246 )
V_139 -> V_32 [ V_118 ] . V_247 |= V_227 -> V_261 ;
} else {
V_235 = false ;
}
if ( V_30 -> V_56 . V_262 )
V_139 -> V_32 [ V_118 ] . V_248 = V_225 -> V_249 ;
else
V_139 -> V_32 [ V_118 ] . V_248 = F_104 ( V_2 ,
V_225 -> V_249 , V_139 -> V_32 [ V_118 ] . V_247 ) ;
V_139 -> V_32 [ V_118 ] . V_250 = F_105 ( V_2 -> V_84 ,
V_236 , V_227 -> V_263 * 100 , V_222 , V_165 , V_235 ) ;
}
if ( F_56 ( V_30 ) && ( V_222 > V_2 -> V_84 -> V_85 . V_264 ) )
V_139 -> V_48 &= ~ V_241 ;
if ( V_139 -> V_48 & V_241 )
V_139 -> V_48 &= ~ V_243 ;
}
static enum V_265 F_106 ( struct V_15 * V_16 )
{
struct V_68 * V_69 ;
enum V_265 V_266 ;
T_4 V_267 ;
V_69 = (struct V_68 * ) V_16 -> V_74 ;
V_267 = V_69 -> V_75 ;
if ( F_107 ( V_267 ) )
V_266 = V_268 ;
else if ( F_108 ( V_267 ) )
V_266 = V_269 ;
else if ( F_109 ( V_267 ) )
V_266 = V_270 ;
else if ( F_103 ( V_267 ) )
V_266 = V_271 ;
else
V_266 = V_272 ;
return V_266 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , int V_222 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_29 * V_186 = NULL ;
struct V_221 V_139 ;
V_92 V_228 = V_2 -> V_40 -> V_229 -> V_230 ;
bool V_223 = false ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_273 = true ;
V_139 . V_274 = true ;
V_139 . V_275 = V_276 ;
V_139 . V_277 = V_4 -> V_72 ;
while ( V_30 ) {
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_14 * V_47 = F_6 ( V_16 ) ;
bool V_278 = ! ! ( V_30 -> V_56 . V_183 & V_185 ) ;
V_139 . type = F_106 ( V_16 ) ;
if ( V_30 -> V_99 )
V_139 . V_279 = V_30 -> V_99 -> V_280 ;
else
V_139 . V_279 = ( V_2 -> V_281 ) ? V_30 -> V_280 : 0 ;
if ( ! V_186 ) {
V_186 = V_30 ;
if ( ! V_2 -> V_281 )
V_139 . V_48 = V_282 ;
if ( ( V_18 -> V_48 & V_182 ) ||
V_4 == V_2 -> V_34 . V_35 )
V_139 . V_48 |= V_283 ;
if ( V_18 -> V_48 & V_284 )
V_139 . V_48 |= V_285 ;
if ( V_18 -> V_48 & V_286 )
V_139 . V_48 |= V_287 ;
if ( V_30 -> V_56 . V_262 )
V_139 . V_48 |= ( V_92 ) V_30 -> V_56 . V_262 <<
V_288 ;
if ( V_278 && ( V_30 == V_186 ) &&
F_47 ( V_228 != ( V_92 ) - 1 ) ) {
if ( ! V_228 || ( V_222 > V_228 ) )
V_223 = true ;
}
if ( ! V_278 )
V_222 = V_47 -> V_194 ;
F_102 ( V_2 , V_30 , & V_139 , V_222 , V_223 ) ;
}
V_139 . V_289 [ 0 ] = V_30 -> V_78 ;
V_139 . V_290 [ 0 ] = V_16 -> V_222 ;
V_139 . V_291 = V_47 -> V_194 ;
V_139 . V_171 = V_47 -> V_171 ;
V_139 . V_292 = V_47 -> V_292 ;
if ( V_278 ) {
if ( V_30 == V_186 )
V_139 . V_278 = V_293 ;
else if ( V_30 == V_186 -> V_103 )
V_139 . V_278 = V_294 ;
else
V_139 . V_278 = V_295 ;
V_139 . V_169 = V_30 -> V_56 . V_169 ;
V_139 . V_187 = V_222 ;
}
if ( V_30 == V_186 -> V_103 )
V_186 = NULL ;
F_111 ( V_225 , V_30 -> V_83 , & V_139 ) ;
V_30 = V_30 -> V_99 ;
}
}
static void
F_112 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_50 * V_100 ,
struct V_29 * V_186 , struct V_104 * V_12 )
{
struct V_29 * V_30 = V_186 , * V_188 = NULL ;
struct V_15 * V_16 ;
int V_89 = 0 ;
do {
struct V_17 * V_18 ;
V_16 = V_30 -> V_31 ;
V_89 ++ ;
F_27 ( V_16 , V_12 ) ;
F_5 ( & V_30 -> V_11 , V_100 ) ;
if ( V_188 )
V_188 -> V_99 = V_30 ;
V_188 = V_30 ;
if ( V_89 >= 2 )
break;
V_30 = F_89 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 )
break;
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( V_18 -> V_48 & V_49 )
break;
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
} while ( 1 );
}
static bool F_113 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_296 )
{
struct V_29 * V_30 ;
struct V_17 * V_18 ;
struct V_104 * V_12 ;
struct V_50 V_100 ;
int V_187 = 0 ;
bool V_278 , V_297 = true ;
if ( ! F_20 ( V_6 ) )
return false ;
F_30 ( & V_100 ) ;
V_30 = F_89 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 )
return false ;
V_18 = F_7 ( V_30 -> V_31 ) ;
V_278 = ! ! ( V_18 -> V_48 & V_49 ) ;
if ( ( V_278 && V_4 -> V_144 >= V_298 ) ||
( ! V_278 && V_4 -> V_143 >= V_299 ) ) {
* V_296 = true ;
return false ;
}
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
if ( V_278 )
V_297 = F_92 ( V_2 , V_4 , V_6 , & V_100 , V_30 ,
V_12 , & V_187 ) ;
else
F_112 ( V_2 , V_4 , V_6 , & V_100 , V_30 , V_12 ) ;
if ( F_48 ( & V_100 ) )
return false ;
if ( V_6 -> V_8 -> V_136 || V_6 -> V_21 -> V_300 ) {
V_6 -> V_8 -> V_136 = false ;
V_18 -> V_48 |= V_182 ;
}
F_110 ( V_2 , V_30 , V_4 , V_187 ) ;
F_114 ( V_2 , V_4 , & V_100 , false ) ;
return true ;
}
int F_115 ( struct V_1 * V_2 , struct V_28 * V_22 ,
T_1 V_6 , T_1 * V_301 )
{
struct V_5 * V_302 ;
struct V_3 * V_4 ;
struct V_41 * V_21 ;
T_2 V_303 ;
V_21 = (struct V_41 * ) V_22 -> V_123 ;
V_302 = F_19 ( V_21 , V_6 ) ;
V_4 = V_302 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_22 -> V_304 . V_305 ) {
V_21 -> V_160 = ( 1 << ( V_306 +
V_22 -> V_304 . V_307 ) ) - 1 ;
V_303 = F_116 ( V_22 -> V_304 . V_308 ) ;
V_21 -> V_178 = V_303 ;
}
F_24 ( V_2 , V_302 ) ;
V_302 -> V_129 = true ;
V_302 -> V_9 = true ;
* V_301 = V_302 -> V_57 = V_302 -> V_309 ;
V_302 -> V_65 = - 1 ;
memset ( V_302 -> V_62 , 0 , sizeof( V_302 -> V_62 ) ) ;
V_302 -> V_60 = V_302 -> V_63 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_117 ( struct V_1 * V_2 , struct V_28 * V_22 , T_1 V_6 )
{
struct V_41 * V_21 = (struct V_41 * ) V_22 -> V_123 ;
struct V_5 * V_302 = F_19 ( V_21 , V_6 ) ;
struct V_3 * V_4 = V_302 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_302 -> V_129 = false ;
V_302 -> V_9 = false ;
F_29 ( V_2 , V_302 ) ;
F_24 ( V_2 , V_302 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_118 ( struct V_28 * V_22 , struct V_1 * V_2 ,
struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_310 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_311 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_10 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_310 = F_20 ( V_6 ) ;
V_6 -> V_10 = false ;
F_51 ( & V_6 -> V_11 ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = false ;
F_51 ( & V_8 -> V_11 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_69 ( V_22 , V_25 , V_310 ) ;
}
}
void F_119 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_311 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_136 = true ;
if ( ! V_6 -> V_9 && F_20 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_120 ( struct V_1 * V_2 , struct V_28 * V_22 ,
T_1 V_25 )
{
struct V_5 * V_6 ;
struct V_41 * V_21 ;
struct V_3 * V_4 ;
V_21 = (struct V_41 * ) V_22 -> V_123 ;
V_6 = F_19 ( V_21 , V_25 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_128 = V_312 << V_22 -> V_304 . V_307 ;
V_6 -> V_9 = false ;
if ( F_20 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_121 ( struct V_101 * V_40 ,
struct V_28 * V_22 ,
T_1 V_313 , int V_89 ,
enum V_314 V_315 ,
bool V_316 )
{
struct V_1 * V_2 = V_40 -> V_317 ;
struct V_41 * V_21 = (struct V_41 * ) V_22 -> V_123 ;
struct V_3 * V_4 = V_2 -> V_34 . V_35 ;
struct V_17 * V_139 ;
struct V_50 V_100 ;
struct V_29 * V_318 = NULL , * V_30 ;
struct V_104 * V_12 ;
int V_319 = 0 ;
int V_118 ;
F_30 ( & V_100 ) ;
for ( V_118 = 0 ; V_313 && V_89 ; V_118 ++ , V_313 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_313 & 1 ) )
continue;
V_6 = F_19 ( V_21 , V_118 ) ;
if ( V_6 -> V_9 )
continue;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_89 > 0 ) {
V_30 = F_89 ( V_2 , V_2 -> V_34 . V_35 , V_6 , & V_12 ) ;
if ( ! V_30 )
break;
F_27 ( V_30 -> V_31 , V_12 ) ;
F_5 ( & V_30 -> V_11 , & V_100 ) ;
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
if ( F_74 ( V_30 ) ) {
F_37 ( V_2 , V_6 , V_30 ) ;
V_30 -> V_56 . V_183 &= ~ V_185 ;
}
if ( V_318 )
V_318 -> V_99 = V_30 ;
V_318 = V_30 ;
V_89 -- ;
V_319 ++ ;
F_42 ( V_4 -> V_72 , V_320 ) ;
if ( V_21 -> V_22 && ! F_20 ( V_6 ) )
F_69 ( V_21 -> V_22 , V_118 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_48 ( & V_100 ) )
return;
V_139 = F_7 ( V_318 -> V_31 ) ;
V_139 -> V_48 |= V_133 ;
V_30 = F_50 ( & V_100 , struct V_29 , V_11 ) ;
F_1 ( V_2 , V_4 ) ;
F_110 ( V_2 , V_30 , V_4 , 0 ) ;
F_114 ( V_2 , V_4 , & V_100 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_122 ( struct V_1 * V_2 , int V_321 , int V_322 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_323 V_324 ;
static const int V_325 [] = {
[ V_326 ] = V_327 ,
[ V_328 ] = V_329 ,
[ V_330 ] = V_331 ,
[ V_332 ] = V_333 ,
} ;
int V_72 , V_118 ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
V_324 . V_334 = V_325 [ V_322 ] ;
V_324 . V_335 = V_336 ;
V_324 . V_337 = V_336 ;
V_324 . V_338 = V_336 ;
V_324 . V_339 = 0 ;
if ( V_225 -> V_85 . V_173 & V_174 ) {
V_324 . V_340 = V_341 ;
} else {
if ( V_321 == V_342 )
V_324 . V_340 = V_343 ;
else
V_324 . V_340 = V_344 |
V_343 ;
}
V_72 = F_123 ( V_225 , V_321 , & V_324 ) ;
if ( V_72 == - 1 ) {
return NULL ;
}
if ( ! F_124 ( V_2 , V_72 ) ) {
struct V_3 * V_4 = & V_2 -> V_34 . V_4 [ V_72 ] ;
V_4 -> V_72 = V_72 ;
V_4 -> V_152 = - 1 ;
V_4 -> V_345 = NULL ;
F_63 ( & V_4 -> V_346 ) ;
F_30 ( & V_4 -> V_347 ) ;
F_30 ( & V_4 -> V_13 ) ;
F_125 ( & V_4 -> V_348 ) ;
V_4 -> V_143 = 0 ;
V_4 -> V_144 = 0 ;
V_4 -> V_142 = false ;
V_2 -> V_34 . V_349 |= 1 << V_72 ;
V_4 -> V_350 = V_4 -> V_351 = 0 ;
for ( V_118 = 0 ; V_118 < V_352 ; V_118 ++ )
F_30 ( & V_4 -> V_353 [ V_118 ] ) ;
}
return & V_2 -> V_34 . V_4 [ V_72 ] ;
}
int F_126 ( struct V_1 * V_2 , int V_354 ,
struct V_323 * V_355 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
int error = 0 ;
struct V_323 V_324 ;
F_127 ( V_2 -> V_34 . V_4 [ V_354 ] . V_72 != V_354 ) ;
F_128 ( V_225 , V_354 , & V_324 ) ;
V_324 . V_335 = V_355 -> V_335 ;
V_324 . V_337 = V_355 -> V_337 ;
V_324 . V_338 = V_355 -> V_338 ;
V_324 . V_356 = V_355 -> V_356 ;
V_324 . V_357 = V_355 -> V_357 ;
if ( ! F_129 ( V_225 , V_354 , & V_324 ) ) {
F_130 ( F_131 ( V_2 -> V_84 ) ,
L_1 , V_354 ) ;
error = - V_358 ;
} else {
F_132 ( V_225 , V_354 ) ;
}
return error ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_323 V_324 ;
struct V_359 * V_360 = & V_2 -> V_361 ;
int V_354 = V_2 -> V_362 . V_363 -> V_72 ;
F_128 ( V_2 -> V_84 , V_354 , & V_324 ) ;
V_324 . V_357 = ( V_360 -> V_364 *
V_365 ) / 100 ;
F_126 ( V_2 , V_354 , & V_324 ) ;
return 0 ;
}
static void F_134 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_50 * V_11 )
{
struct V_29 * V_30 , * V_366 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_116 = V_117 ;
F_30 ( & V_51 ) ;
while ( ! F_48 ( V_11 ) ) {
V_30 = F_50 ( V_11 , struct V_29 , V_11 ) ;
if ( V_30 -> V_56 . V_87 ) {
F_51 ( & V_30 -> V_11 ) ;
F_52 ( V_2 , V_30 ) ;
continue;
}
V_366 = V_30 -> V_103 ;
F_135 ( & V_51 , V_11 , & V_366 -> V_11 ) ;
F_75 ( V_2 , V_4 , & V_53 , V_30 , & V_51 ) ;
}
}
void F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_84 -> V_85 . V_173 & V_174 ) {
int V_145 = V_4 -> V_351 ;
while ( ! F_48 ( & V_4 -> V_353 [ V_145 ] ) ) {
F_134 ( V_2 , V_4 , & V_4 -> V_353 [ V_145 ] ) ;
F_36 ( V_145 , V_352 ) ;
}
V_4 -> V_351 = V_145 ;
}
V_4 -> V_345 = NULL ;
V_4 -> V_142 = false ;
F_134 ( V_2 , V_4 , & V_4 -> V_347 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_137 ( struct V_1 * V_2 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
struct V_3 * V_4 ;
int V_118 ;
V_92 V_369 = 0 ;
if ( F_35 ( V_370 , & V_2 -> V_371 ) )
return true ;
F_138 ( V_225 ) ;
for ( V_118 = 0 ; V_118 < V_372 ; V_118 ++ ) {
if ( ! F_124 ( V_2 , V_118 ) )
continue;
if ( ! V_2 -> V_34 . V_4 [ V_118 ] . V_143 )
continue;
if ( F_139 ( V_225 , V_2 -> V_34 . V_4 [ V_118 ] . V_72 ) )
V_369 |= F_140 ( V_118 ) ;
}
if ( V_369 )
F_130 ( V_368 , L_2 , V_369 ) ;
for ( V_118 = 0 ; V_118 < V_372 ; V_118 ++ ) {
if ( ! F_124 ( V_2 , V_118 ) )
continue;
V_4 = & V_2 -> V_34 . V_4 [ V_118 ] ;
V_4 -> V_38 = false ;
F_136 ( V_2 , V_4 ) ;
}
return ! V_369 ;
}
void F_141 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_142 ( V_2 -> V_84 , V_4 -> V_72 ) ;
V_2 -> V_34 . V_349 &= ~ ( 1 << V_4 -> V_72 ) ;
}
void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 , * V_373 ;
struct V_5 * V_6 , * V_374 ;
bool V_319 = false ;
if ( F_35 ( V_375 , & V_2 -> V_371 ) ||
F_48 ( & V_4 -> V_13 ) )
return;
F_59 () ;
V_373 = F_143 ( V_4 -> V_13 . V_70 , struct V_7 , V_11 ) ;
while ( ! F_48 ( & V_4 -> V_13 ) ) {
bool V_296 = false ;
V_8 = F_50 ( & V_4 -> V_13 , struct V_7 , V_11 ) ;
V_374 = F_143 ( V_8 -> V_12 . V_70 , struct V_5 , V_11 ) ;
F_51 ( & V_8 -> V_11 ) ;
V_8 -> V_10 = false ;
while ( ! F_48 ( & V_8 -> V_12 ) ) {
V_6 = F_50 ( & V_8 -> V_12 , struct V_5 ,
V_11 ) ;
F_51 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
if ( V_6 -> V_9 )
continue;
if ( F_113 ( V_2 , V_4 , V_6 , & V_296 ) )
V_319 = true ;
if ( F_20 ( V_6 ) )
F_4 ( V_4 , V_6 ) ;
if ( V_296 || V_6 == V_374 )
break;
}
if ( ! F_48 ( & V_8 -> V_12 ) && ! V_8 -> V_10 ) {
V_8 -> V_10 = true ;
F_5 ( & V_8 -> V_11 , & V_4 -> V_13 ) ;
}
if ( V_296 )
break;
if ( V_8 == V_373 ) {
if ( ! V_319 )
break;
V_319 = false ;
V_373 = F_143 ( V_4 -> V_13 . V_70 ,
struct V_7 , V_11 ) ;
}
}
F_61 () ;
}
static void F_114 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_50 * V_376 , bool V_377 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_367 * V_368 = F_131 ( V_225 ) ;
struct V_29 * V_30 , * V_102 ;
bool V_378 = false ;
bool V_379 ;
if ( F_48 ( V_376 ) )
return;
V_379 = ! ! ( V_225 -> V_85 . V_173 & V_174 ) ;
V_30 = F_50 ( V_376 , struct V_29 , V_11 ) ;
V_102 = F_143 ( V_376 -> V_70 , struct V_29 , V_11 ) ;
F_144 ( V_368 , V_380 , L_3 ,
V_4 -> V_72 , V_4 -> V_143 ) ;
if ( V_379 && F_48 ( & V_4 -> V_353 [ V_4 -> V_350 ] ) ) {
F_145 ( V_376 , & V_4 -> V_353 [ V_4 -> V_350 ] ) ;
F_36 ( V_4 -> V_350 , V_352 ) ;
V_378 = true ;
} else {
F_145 ( V_376 , & V_4 -> V_347 ) ;
if ( V_4 -> V_345 ) {
F_146 ( V_225 , V_4 -> V_345 , V_30 -> V_280 ) ;
F_144 ( V_368 , V_381 , L_4 ,
V_4 -> V_72 , V_4 -> V_345 ,
F_147 ( V_30 -> V_280 ) , V_30 -> V_83 ) ;
} else if ( ! V_379 )
V_378 = true ;
V_4 -> V_345 = V_102 -> V_83 ;
}
if ( V_378 ) {
F_42 ( V_4 -> V_72 , V_378 ) ;
F_148 ( V_225 , V_4 -> V_72 , V_30 -> V_280 ) ;
F_144 ( V_368 , V_381 , L_5 ,
V_4 -> V_72 , F_147 ( V_30 -> V_280 ) , V_30 -> V_83 ) ;
}
if ( ! V_379 || V_2 -> V_281 ) {
F_42 ( V_4 -> V_72 , V_382 ) ;
F_149 ( V_225 , V_4 -> V_72 ) ;
}
if ( ! V_377 ) {
while ( V_30 ) {
V_4 -> V_143 ++ ;
if ( F_73 ( V_30 ) )
V_4 -> V_144 ++ ;
V_102 = V_30 -> V_103 ;
V_30 = V_102 -> V_99 ;
V_102 -> V_99 = NULL ;
}
}
}
static void F_150 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_14 * V_47 = F_6 ( V_16 ) ;
struct V_50 V_51 ;
struct V_29 * V_30 = V_47 -> V_30 ;
F_30 ( & V_51 ) ;
F_5 ( & V_30 -> V_11 , & V_51 ) ;
V_30 -> V_56 . V_183 = 0 ;
if ( V_6 && ( V_18 -> V_48 & V_49 ) ) {
V_30 -> V_56 . V_183 = V_184 ;
F_37 ( V_2 , V_6 , V_30 ) ;
}
V_30 -> V_99 = NULL ;
V_30 -> V_103 = V_30 ;
F_110 ( V_2 , V_30 , V_4 , V_47 -> V_194 ) ;
F_114 ( V_2 , V_4 , & V_51 , false ) ;
F_42 ( V_4 -> V_72 , V_383 ) ;
}
static void F_151 ( struct V_101 * V_40 ,
struct V_28 * V_22 ,
struct V_15 * V_16 ,
int V_194 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_384 * V_385 = V_18 -> V_132 . V_385 ;
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
const struct V_226 * V_227 ;
struct V_14 * V_47 = F_6 ( V_16 ) ;
struct V_41 * V_21 = NULL ;
enum V_386 V_292 ;
bool V_387 = false ;
if ( V_18 -> V_132 . V_23 &&
V_18 -> V_132 . V_23 -> V_388 . V_389 )
V_387 = true ;
V_227 = F_152 ( V_40 , V_18 ) ;
V_292 = F_153 ( V_16 ) ;
if ( V_22 )
V_21 = (struct V_41 * ) V_22 -> V_123 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
if ( V_385 )
V_47 -> V_171 = V_385 -> V_390 ;
else if ( V_21 && F_154 ( V_69 -> V_75 ) && V_21 -> V_391 > 0 )
V_47 -> V_171 = V_21 -> V_391 ;
else
V_47 -> V_171 = V_172 ;
V_47 -> V_292 = V_292 ;
V_47 -> V_194 = V_194 ;
if ( ! V_227 )
return;
V_47 -> V_232 = V_227 -> V_260 ;
if ( V_387 )
V_47 -> V_232 |= V_227 -> V_261 ;
}
T_2 F_104 ( struct V_1 * V_2 , T_2 V_392 , V_92 V_227 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_393 * V_394 = V_225 -> V_394 ;
if ( ( V_225 -> V_85 . V_173 & V_395 ) && F_155 ( V_394 ) &&
( V_392 == 0x7 ) && ( V_227 < 0x90 ) )
return 0x3 ;
else if ( F_156 ( V_225 ) && F_157 ( V_225 ) &&
F_158 ( V_227 ) )
return 0x2 ;
else
return V_392 ;
}
static struct V_29 * F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
struct V_14 * V_47 = F_6 ( V_16 ) ;
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
struct V_29 * V_30 ;
int V_396 ;
T_1 V_20 ;
V_30 = F_45 ( V_2 ) ;
if ( ! V_30 ) {
F_144 ( V_368 , V_381 , L_6 ) ;
return NULL ;
}
F_54 ( V_30 ) ;
if ( V_6 && F_159 ( V_69 -> V_75 ) ) {
V_396 = F_160 ( V_69 -> V_397 ) & V_398 ;
V_20 = V_6 -> V_309 ;
V_69 -> V_397 = F_43 ( V_6 -> V_309 << V_26 ) ;
if ( V_396 )
V_69 -> V_397 |= F_43 ( V_396 ) ;
if ( ! F_161 ( V_69 -> V_75 ) )
F_36 ( V_6 -> V_309 , V_64 ) ;
V_30 -> V_56 . V_20 = V_20 ;
}
V_30 -> V_31 = V_16 ;
V_30 -> V_78 = F_162 ( V_2 -> V_77 , V_16 -> V_74 ,
V_16 -> V_222 , V_79 ) ;
if ( F_47 ( F_163 ( V_2 -> V_77 , V_30 -> V_78 ) ) ) {
V_30 -> V_31 = NULL ;
V_30 -> V_78 = 0 ;
F_130 ( F_131 ( V_2 -> V_84 ) ,
L_7 ) ;
F_52 ( V_2 , V_30 ) ;
return NULL ;
}
V_47 -> V_30 = V_30 ;
return V_30 ;
}
static int F_164 ( struct V_101 * V_40 , struct V_15 * V_16 ,
struct V_399 * V_400 )
{
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
struct V_17 * V_139 = F_7 ( V_16 ) ;
struct V_28 * V_22 = V_400 -> V_22 ;
struct V_27 * V_23 = V_139 -> V_132 . V_23 ;
struct V_401 * V_402 ;
struct V_1 * V_2 = V_40 -> V_317 ;
int V_148 = V_16 -> V_222 + V_403 ;
int V_404 , V_405 ;
if ( V_22 )
V_400 -> V_21 = (struct V_41 * ) V_22 -> V_123 ;
else if ( V_23 && F_154 ( V_69 -> V_75 ) ) {
V_402 = ( void * ) V_23 -> V_123 ;
V_400 -> V_21 = & V_402 -> V_406 ;
}
if ( V_139 -> V_132 . V_385 )
V_148 += V_139 -> V_132 . V_385 -> V_407 ;
if ( V_139 -> V_48 & V_408 ) {
if ( V_139 -> V_48 & V_409 )
V_2 -> V_34 . V_410 += 0x10 ;
V_69 -> V_397 &= F_43 ( V_398 ) ;
V_69 -> V_397 |= F_43 ( V_2 -> V_34 . V_410 ) ;
}
if ( ( V_23 && V_23 -> type != V_411 &&
V_23 -> type != V_412 ) ||
! F_154 ( V_69 -> V_75 ) )
V_139 -> V_48 |= V_182 ;
V_404 = F_165 ( V_69 -> V_75 ) ;
V_405 = V_404 & 3 ;
if ( V_405 && V_16 -> V_222 > V_404 ) {
if ( F_166 ( V_16 ) < V_405 )
return - V_413 ;
F_167 ( V_16 , V_405 ) ;
memmove ( V_16 -> V_74 , V_16 -> V_74 + V_405 , V_404 ) ;
}
F_151 ( V_40 , V_22 , V_16 , V_148 ) ;
return 0 ;
}
int F_168 ( struct V_101 * V_40 , struct V_15 * V_16 ,
struct V_399 * V_400 )
{
struct V_68 * V_69 ;
struct V_17 * V_139 = F_7 ( V_16 ) ;
struct V_28 * V_22 = V_400 -> V_22 ;
struct V_27 * V_23 = V_139 -> V_132 . V_23 ;
struct V_1 * V_2 = V_40 -> V_317 ;
struct V_3 * V_4 = V_400 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_30 ;
int V_33 ;
int V_414 ;
V_414 = F_164 ( V_40 , V_16 , V_400 ) ;
if ( V_414 )
return V_414 ;
V_69 = (struct V_68 * ) V_16 -> V_74 ;
V_33 = F_15 ( V_16 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_34 . V_36 [ V_33 ] &&
++ V_4 -> V_37 > V_2 -> V_34 . V_39 [ V_33 ] &&
! V_4 -> V_38 ) {
F_169 ( V_2 -> V_40 , V_33 ) ;
V_4 -> V_38 = true ;
}
if ( V_400 -> V_21 && F_159 ( V_69 -> V_75 ) )
V_6 = F_18 ( V_2 , V_400 -> V_21 , V_16 ) ;
if ( V_139 -> V_48 & V_415 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_34 . V_35 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_400 -> V_21 &&
F_159 ( V_69 -> V_75 ) ) {
F_16 ( V_6 -> V_8 -> V_4 != V_400 -> V_4 ) ;
if ( V_139 -> V_48 & V_182 )
V_6 -> V_8 -> V_136 = true ;
F_42 ( V_4 -> V_72 , V_416 ) ;
F_68 ( & V_6 -> V_44 , V_16 ) ;
if ( ! V_400 -> V_21 -> V_131 )
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
goto V_417;
}
V_30 = F_26 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
if ( V_400 -> V_418 )
F_170 ( V_16 ) ;
else
F_28 ( V_2 -> V_40 , V_16 ) ;
goto V_417;
}
V_30 -> V_56 . V_262 = V_400 -> V_418 ;
if ( V_400 -> V_418 )
V_30 -> V_56 . V_419 = V_420 ;
F_11 ( V_23 , V_22 , V_30 ) ;
F_150 ( V_2 , V_4 , V_6 , V_16 ) ;
V_417:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_171 ( struct V_101 * V_40 , struct V_27 * V_23 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_40 -> V_317 ;
struct V_399 V_400 = {
. V_4 = V_2 -> V_362 . V_363
} ;
struct V_221 V_139 = {} ;
struct V_68 * V_69 ;
struct V_29 * V_318 = NULL ;
struct V_29 * V_30 ;
F_172 ( V_100 ) ;
int V_199 = 0 ;
int V_421 ;
V_421 =
V_2 -> V_361 . V_364 * 1000 *
V_2 -> V_361 . V_422 / V_423 ;
do {
struct V_14 * V_47 = F_6 ( V_16 ) ;
if ( F_164 ( V_40 , V_16 , & V_400 ) )
break;
V_30 = F_26 ( V_2 , V_400 . V_4 , NULL , V_16 ) ;
if ( ! V_30 )
break;
V_30 -> V_103 = V_30 ;
F_11 ( V_23 , NULL , V_30 ) ;
F_102 ( V_2 , V_30 , & V_139 , V_47 -> V_194 , false ) ;
V_199 += V_139 . V_32 [ 0 ] . V_250 ;
if ( V_318 )
V_318 -> V_99 = V_30 ;
F_5 ( & V_30 -> V_11 , & V_100 ) ;
V_318 = V_30 ;
V_16 = NULL ;
if ( V_199 > V_421 )
break;
V_16 = F_173 ( V_40 , V_23 ) ;
} while( V_16 );
if ( V_16 )
F_28 ( V_40 , V_16 ) ;
if ( F_48 ( & V_100 ) )
return;
V_30 = F_50 ( & V_100 , struct V_29 , V_11 ) ;
V_69 = (struct V_68 * ) V_30 -> V_31 -> V_74 ;
if ( V_69 -> V_75 & V_424 ) {
V_69 -> V_75 &= ~ V_424 ;
F_44 ( V_2 -> V_77 , V_30 -> V_78 ,
sizeof( * V_69 ) , V_79 ) ;
}
F_1 ( V_2 , V_400 . V_4 ) ;
F_110 ( V_2 , V_30 , V_400 . V_4 , 0 ) ;
F_114 ( V_2 , V_400 . V_4 , & V_100 , false ) ;
F_42 ( V_400 . V_4 -> V_72 , V_383 ) ;
F_2 ( V_2 , V_400 . V_4 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_425 , struct V_3 * V_4 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
int V_404 , V_405 ;
unsigned long V_48 ;
F_144 ( V_368 , V_381 , L_8 , V_16 ) ;
if ( V_2 -> V_84 -> V_426 )
F_174 ( V_427 , & V_2 -> V_84 -> V_426 -> V_428 ) ;
if ( ! ( V_425 & V_66 ) )
V_18 -> V_48 |= V_429 ;
V_404 = F_165 ( V_69 -> V_75 ) ;
V_405 = V_404 & 3 ;
if ( V_405 && V_16 -> V_222 > V_404 + V_405 ) {
memmove ( V_16 -> V_74 + V_405 , V_16 -> V_74 , V_404 ) ;
F_175 ( V_16 , V_405 ) ;
}
F_176 ( & V_2 -> V_430 , V_48 ) ;
if ( ( V_2 -> V_431 & V_432 ) && ! V_4 -> V_143 ) {
V_2 -> V_431 &= ~ V_432 ;
F_144 ( V_368 , V_433 ,
L_9 ,
V_2 -> V_431 & ( V_434 |
V_435 |
V_436 |
V_432 ) ) ;
}
F_177 ( & V_2 -> V_430 , V_48 ) ;
F_68 ( & V_4 -> V_346 , V_16 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , struct V_50 * V_100 ,
struct V_52 * V_53 , int V_88 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
unsigned long V_48 ;
int V_425 = 0 ;
if ( ! V_88 )
V_425 |= V_66 ;
if ( V_53 -> V_116 & V_134 )
V_18 -> V_48 |= V_437 ;
F_178 ( V_2 -> V_77 , V_30 -> V_78 , V_16 -> V_222 , V_79 ) ;
V_30 -> V_78 = 0 ;
if ( V_2 -> V_281 )
goto V_438;
if ( V_30 -> V_56 . V_262 ) {
if ( F_179 ( V_420 ,
V_30 -> V_56 . V_419 +
F_180 ( V_439 ) ) )
F_170 ( V_16 ) ;
else
F_181 ( & V_2 -> V_440 ) ;
} else {
F_182 ( V_2 , V_30 , V_53 , V_4 , V_425 ) ;
F_40 ( V_2 , V_16 , V_425 , V_4 ) ;
}
V_438:
V_30 -> V_31 = NULL ;
F_176 ( & V_2 -> V_34 . V_80 , V_48 ) ;
F_145 ( V_100 , & V_2 -> V_34 . V_81 ) ;
F_177 ( & V_2 -> V_34 . V_80 , V_48 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_52 * V_53 , int V_89 , int V_90 ,
int V_88 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_101 * V_40 = V_2 -> V_40 ;
struct V_224 * V_225 = V_2 -> V_84 ;
T_2 V_118 , V_441 ;
if ( V_88 )
V_18 -> V_442 . V_443 = V_53 -> V_444 ;
V_441 = V_53 -> V_120 ;
F_16 ( V_441 >= V_40 -> V_445 ) ;
if ( V_18 -> V_48 & V_49 ) {
V_18 -> V_48 |= V_446 ;
F_127 ( V_90 > V_89 ) ;
}
V_18 -> V_442 . V_447 = V_89 ;
V_18 -> V_442 . V_448 = V_89 - V_90 ;
if ( ( V_53 -> V_116 & V_134 ) == 0 &&
( V_18 -> V_48 & V_284 ) == 0 ) {
if ( F_47 ( V_53 -> V_124 & ( V_449 |
V_450 ) ) &&
F_154 ( V_69 -> V_75 ) &&
V_225 -> V_451 >= V_2 -> V_84 -> V_452 . V_453 )
V_18 -> V_442 . V_32 [ V_441 ] . V_67 =
V_40 -> V_454 ;
}
for ( V_118 = V_441 + 1 ; V_118 < V_40 -> V_445 ; V_118 ++ ) {
V_18 -> V_442 . V_32 [ V_118 ] . V_67 = 0 ;
V_18 -> V_442 . V_32 [ V_118 ] . V_145 = - 1 ;
}
V_18 -> V_442 . V_32 [ V_441 ] . V_67 = V_53 -> V_119 + 1 ;
}
static void F_183 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_367 * V_368 = F_131 ( V_225 ) ;
struct V_29 * V_30 , * V_366 , * V_455 = NULL ;
struct V_50 V_51 ;
struct V_456 * V_457 ;
struct V_52 V_53 ;
int V_442 ;
F_144 ( V_368 , V_380 , L_10 ,
V_4 -> V_72 , F_184 ( V_2 -> V_84 , V_4 -> V_72 ) ,
V_4 -> V_345 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_35 ( V_375 , & V_2 -> V_371 ) )
break;
if ( F_48 ( & V_4 -> V_347 ) ) {
V_4 -> V_345 = NULL ;
F_76 ( V_2 , V_4 ) ;
break;
}
V_30 = F_50 ( & V_4 -> V_347 , struct V_29 , V_11 ) ;
V_455 = NULL ;
if ( V_30 -> V_56 . V_87 ) {
V_455 = V_30 ;
if ( F_185 ( & V_455 -> V_11 , & V_4 -> V_347 ) )
break;
V_30 = F_143 ( V_455 -> V_11 . V_458 , struct V_29 ,
V_11 ) ;
}
V_366 = V_30 -> V_103 ;
V_457 = V_366 -> V_83 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_442 = F_186 ( V_225 , V_457 , & V_53 ) ;
if ( V_442 == - V_459 )
break;
F_42 ( V_4 -> V_72 , V_460 ) ;
V_366 -> V_56 . V_87 = true ;
F_30 ( & V_51 ) ;
if ( ! F_187 ( & V_366 -> V_11 ) )
F_135 ( & V_51 ,
& V_4 -> V_347 , V_366 -> V_11 . V_70 ) ;
if ( V_455 ) {
F_51 ( & V_455 -> V_11 ) ;
F_52 ( V_2 , V_455 ) ;
}
F_75 ( V_2 , V_4 , & V_53 , V_30 , & V_51 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_224 * V_225 = V_2 -> V_84 ;
V_92 V_461 = ( ( 1 << V_372 ) - 1 ) & V_225 -> V_462 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_372 ; V_118 ++ ) {
if ( F_124 ( V_2 , V_118 ) && ( V_461 & ( 1 << V_118 ) ) )
F_183 ( V_2 , & V_2 -> V_34 . V_4 [ V_118 ] ) ;
}
}
void F_189 ( struct V_1 * V_2 )
{
struct V_52 V_53 ;
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
struct V_224 * V_225 = V_2 -> V_84 ;
struct V_3 * V_4 ;
struct V_29 * V_30 , * V_366 ;
struct V_50 V_51 ;
struct V_50 * V_463 ;
int V_442 ;
for (; ; ) {
if ( F_35 ( V_375 , & V_2 -> V_371 ) )
break;
V_442 = F_186 ( V_225 , NULL , ( void * ) & V_53 ) ;
if ( V_442 == - V_459 )
break;
if ( V_442 == - V_358 ) {
F_144 ( V_368 , V_381 , L_11 ) ;
break;
}
if ( V_53 . V_464 == V_2 -> V_362 . V_465 ) {
V_2 -> V_362 . V_466 = true ;
V_2 -> V_362 . V_467 = ! ( V_53 . V_116 & V_141 ) ;
F_190 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_34 . V_4 [ V_53 . V_464 ] ;
F_1 ( V_2 , V_4 ) ;
F_42 ( V_4 -> V_72 , V_460 ) ;
V_463 = & V_4 -> V_353 [ V_4 -> V_351 ] ;
if ( F_48 ( V_463 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_30 = F_50 ( V_463 , struct V_29 , V_11 ) ;
if ( V_30 -> V_56 . V_87 ) {
F_51 ( & V_30 -> V_11 ) ;
F_52 ( V_2 , V_30 ) ;
V_30 = F_50 ( V_463 , struct V_29 , V_11 ) ;
}
V_366 = V_30 -> V_103 ;
F_30 ( & V_51 ) ;
if ( F_185 ( & V_366 -> V_11 , V_463 ) ) {
F_145 ( V_463 , & V_51 ) ;
F_36 ( V_4 -> V_351 , V_352 ) ;
if ( ! F_48 ( & V_4 -> V_347 ) ) {
struct V_50 V_100 ;
F_30 ( & V_100 ) ;
V_4 -> V_345 = NULL ;
F_145 ( & V_4 -> V_347 , & V_100 ) ;
F_114 ( V_2 , V_4 , & V_100 , true ) ;
}
} else {
V_366 -> V_56 . V_87 = true ;
if ( V_30 != V_366 )
F_135 ( & V_51 , V_463 ,
V_366 -> V_11 . V_70 ) ;
}
F_75 ( V_2 , V_4 , & V_53 , V_30 , & V_51 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_191 ( struct V_1 * V_2 , int V_468 )
{
struct V_469 * V_470 = & V_2 -> V_471 ;
T_2 V_472 = V_2 -> V_84 -> V_85 . V_472 ;
V_470 -> V_473 = V_468 * V_472 ;
V_470 -> V_474 = F_192 ( V_2 -> V_77 , V_470 -> V_473 ,
& V_470 -> V_475 , V_476 ) ;
if ( ! V_470 -> V_474 )
return - V_413 ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 )
{
int V_477 ;
V_477 = F_191 ( V_2 , V_478 ) ;
if ( ! V_477 )
F_194 ( V_2 -> V_84 , V_2 -> V_471 . V_474 ,
V_2 -> V_471 . V_475 ,
V_478 ) ;
return V_477 ;
}
int F_195 ( struct V_1 * V_2 , int V_479 )
{
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
int error = 0 ;
F_125 ( & V_2 -> V_34 . V_80 ) ;
error = F_196 ( V_2 , & V_2 -> V_34 . V_480 , & V_2 -> V_34 . V_81 ,
L_12 , V_479 , 1 , 1 ) ;
if ( error != 0 ) {
F_130 ( V_368 ,
L_13 , error ) ;
return error ;
}
error = F_196 ( V_2 , & V_2 -> V_362 . V_481 , & V_2 -> V_362 . V_482 ,
L_14 , V_423 , 1 , 1 ) ;
if ( error != 0 ) {
F_130 ( V_368 ,
L_15 , error ) ;
return error ;
}
F_197 ( & V_2 -> V_483 , V_484 ) ;
if ( V_2 -> V_84 -> V_85 . V_173 & V_174 )
error = F_193 ( V_2 ) ;
return error ;
}
void F_198 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_25 , V_485 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_311 ;
V_25 ++ , V_6 ++ ) {
V_6 -> V_21 = V_21 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_57 = V_6 -> V_309 = 0 ;
V_6 -> V_128 = V_486 ;
V_6 -> V_60 = V_6 -> V_63 = 0 ;
V_6 -> V_10 = false ;
V_6 -> V_9 = false ;
V_6 -> V_129 = false ;
F_63 ( & V_6 -> V_44 ) ;
F_63 ( & V_6 -> V_45 ) ;
V_485 = F_199 ( V_25 ) ;
V_6 -> V_8 = & V_21 -> V_8 [ V_485 ] ;
}
for ( V_485 = 0 , V_8 = & V_21 -> V_8 [ V_485 ] ;
V_485 < V_487 ; V_485 ++ , V_8 ++ ) {
V_8 -> V_10 = false ;
V_8 -> V_136 = true ;
V_8 -> V_4 = V_2 -> V_34 . V_36 [ V_485 ] ;
F_30 ( & V_8 -> V_12 ) ;
}
}
void F_200 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_311 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_10 ) {
F_51 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
}
if ( V_8 -> V_10 ) {
F_51 ( & V_8 -> V_11 ) ;
V_6 -> V_8 -> V_10 = false ;
}
F_39 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_129 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
int F_201 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_399 * V_400 )
{
struct V_68 * V_69 = (struct V_68 * ) V_16 -> V_74 ;
struct V_14 * V_47 = F_6 ( V_16 ) ;
struct V_367 * V_368 = F_131 ( V_2 -> V_84 ) ;
struct V_29 * V_30 ;
int V_404 , V_405 ;
V_404 = F_165 ( V_69 -> V_75 ) ;
V_405 = V_404 & 3 ;
if ( V_405 && V_16 -> V_222 > V_404 ) {
if ( F_166 ( V_16 ) < V_405 ) {
F_144 ( V_368 , V_381 ,
L_16 ) ;
return - V_488 ;
}
F_167 ( V_16 , V_405 ) ;
memmove ( V_16 -> V_74 , V_16 -> V_74 + V_405 , V_404 ) ;
}
V_47 -> V_171 = V_172 ;
V_47 -> V_194 = V_16 -> V_222 + V_403 ;
V_47 -> V_292 = V_489 ;
V_30 = F_26 ( V_2 , V_400 -> V_4 , NULL , V_16 ) ;
if ( ! V_30 ) {
F_144 ( V_368 , V_381 , L_17 ) ;
return - V_488 ;
}
F_11 ( V_2 -> V_490 , NULL , V_30 ) ;
F_146 ( V_2 -> V_84 , V_30 -> V_83 , V_30 -> V_280 ) ;
F_202 ( V_2 -> V_84 , V_400 -> V_4 -> V_72 ) ;
F_150 ( V_2 , V_400 -> V_4 , NULL , V_16 ) ;
return 0 ;
}
