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
struct V_42 * V_43 ;
T_2 V_25 = 0 ;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
if ( F_19 ( V_43 -> V_45 ) )
V_25 = F_20 ( V_43 ) [ 0 ] ;
V_25 &= V_46 ;
return F_21 ( V_21 , V_25 ) ;
}
static bool F_22 ( struct V_5 * V_6 )
{
return ! F_23 ( & V_6 -> V_47 ) || ! F_23 ( & V_6 -> V_48 ) ;
}
static struct V_15 * F_24 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
V_16 = F_25 ( & V_6 -> V_48 ) ;
if ( ! V_16 )
V_16 = F_25 ( & V_6 -> V_47 ) ;
return V_16 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_17 * V_18 ;
struct V_15 * V_16 , * V_49 ;
struct V_29 * V_30 ;
struct V_14 * V_50 ;
F_27 (&tid->buf_q, skb, tskb) {
V_50 = F_6 ( V_16 ) ;
V_30 = V_50 -> V_30 ;
V_18 = F_7 ( V_16 ) ;
V_18 -> V_51 &= ~ V_52 ;
if ( V_30 )
continue;
V_30 = F_28 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_29 ( V_16 , & V_6 -> V_47 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
F_30 ( V_2 -> V_40 , V_16 ) ;
continue;
}
}
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
struct V_14 * V_50 ;
bool V_57 = false ;
F_32 ( & V_54 ) ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
while ( ( V_16 = F_25 ( & V_6 -> V_48 ) ) ) {
V_50 = F_6 ( V_16 ) ;
V_30 = V_50 -> V_30 ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
F_30 ( V_2 -> V_40 , V_16 ) ;
continue;
}
if ( V_50 -> V_58 ) {
F_33 ( V_2 , V_6 , V_30 -> V_59 . V_20 ) ;
V_57 = true ;
}
F_5 ( & V_30 -> V_11 , & V_54 ) ;
F_34 ( V_2 , V_30 , V_4 , & V_54 , & V_56 , 0 ) ;
}
if ( V_57 ) {
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , V_6 -> V_60 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_20 )
{
int V_61 , V_62 ;
V_61 = F_35 ( V_6 -> V_60 , V_20 ) ;
V_62 = ( V_6 -> V_63 + V_61 ) & ( V_64 - 1 ) ;
F_36 ( V_62 , V_6 -> V_65 ) ;
while ( V_6 -> V_63 != V_6 -> V_66 && ! F_37 ( V_6 -> V_63 , V_6 -> V_65 ) ) {
F_38 ( V_6 -> V_60 , V_67 ) ;
F_38 ( V_6 -> V_63 , V_64 ) ;
if ( V_6 -> V_68 >= 0 )
V_6 -> V_68 -- ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_14 * V_50 = F_6 ( V_30 -> V_31 ) ;
T_1 V_20 = V_30 -> V_59 . V_20 ;
int V_61 , V_62 ;
V_61 = F_35 ( V_6 -> V_60 , V_20 ) ;
V_62 = ( V_6 -> V_63 + V_61 ) & ( V_64 - 1 ) ;
F_40 ( V_62 , V_6 -> V_65 ) ;
V_50 -> V_58 = 1 ;
if ( V_61 >= ( ( V_6 -> V_66 - V_6 -> V_63 ) &
( V_64 - 1 ) ) ) {
V_6 -> V_66 = V_62 ;
F_38 ( V_6 -> V_66 , V_64 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
struct V_14 * V_50 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_32 ( & V_54 ) ;
while ( ( V_16 = F_24 ( V_6 ) ) ) {
V_50 = F_6 ( V_16 ) ;
V_30 = V_50 -> V_30 ;
if ( ! V_30 ) {
F_42 ( V_2 , V_16 , V_69 , V_4 ) ;
continue;
}
F_5 ( & V_30 -> V_11 , & V_54 ) ;
F_34 ( V_2 , V_30 , V_4 , & V_54 , & V_56 , 0 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , int V_70 )
{
struct V_14 * V_50 = F_6 ( V_16 ) ;
struct V_29 * V_30 = V_50 -> V_30 ;
struct V_42 * V_43 ;
int V_71 = V_50 -> V_72 ;
F_44 ( V_4 -> V_73 , V_74 ) ;
V_50 -> V_72 += V_70 ;
if ( V_71 > 0 )
return;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
V_43 -> V_45 |= F_45 ( V_75 ) ;
F_46 ( V_2 -> V_76 , V_30 -> V_77 ,
sizeof( * V_43 ) , V_78 ) ;
}
static struct V_29 * F_47 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = NULL ;
F_48 ( & V_2 -> V_34 . V_79 ) ;
if ( F_49 ( F_50 ( & V_2 -> V_34 . V_80 ) ) ) {
F_51 ( & V_2 -> V_34 . V_79 ) ;
return NULL ;
}
V_30 = F_52 ( & V_2 -> V_34 . V_80 , struct V_29 , V_11 ) ;
F_53 ( & V_30 -> V_11 ) ;
F_51 ( & V_2 -> V_34 . V_79 ) ;
return V_30 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
F_48 ( & V_2 -> V_34 . V_79 ) ;
F_5 ( & V_30 -> V_11 , & V_2 -> V_34 . V_80 ) ;
F_51 ( & V_2 -> V_34 . V_79 ) ;
}
static struct V_29 * F_55 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_29 * V_81 ;
V_81 = F_47 ( V_2 ) ;
if ( F_16 ( ! V_81 ) )
return NULL ;
F_56 ( V_81 ) ;
V_81 -> V_31 = V_30 -> V_31 ;
V_81 -> V_77 = V_30 -> V_77 ;
memcpy ( V_81 -> V_82 , V_30 -> V_82 , V_2 -> V_83 -> V_84 . V_85 ) ;
V_81 -> V_59 = V_30 -> V_59 ;
V_81 -> V_59 . V_86 = false ;
return V_81 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_55 * V_56 , int V_87 ,
int * V_88 , int * V_89 )
{
struct V_14 * V_50 ;
T_1 V_90 = 0 ;
V_91 V_92 [ V_93 >> 5 ] ;
int V_94 ;
int V_95 = 0 ;
* V_89 = 0 ;
* V_88 = 0 ;
V_95 = F_58 ( V_30 ) ;
if ( V_95 ) {
V_90 = V_56 -> V_96 ;
memcpy ( V_92 , & V_56 -> V_97 , V_93 >> 3 ) ;
}
while ( V_30 ) {
V_50 = F_6 ( V_30 -> V_31 ) ;
V_94 = F_35 ( V_90 , V_30 -> V_59 . V_20 ) ;
( * V_88 ) ++ ;
if ( ! V_87 || ( V_95 && ! F_59 ( V_92 , V_94 ) ) )
( * V_89 ) ++ ;
V_30 = V_30 -> V_98 ;
}
}
static void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_30 , struct V_53 * V_99 ,
struct V_55 * V_56 , int V_87 )
{
struct V_41 * V_21 = NULL ;
struct V_15 * V_16 ;
struct V_28 * V_22 ;
struct V_100 * V_40 = V_2 -> V_40 ;
struct V_42 * V_43 ;
struct V_17 * V_18 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_98 , * V_101 = V_30 -> V_102 ;
struct V_53 V_54 ;
struct V_103 V_104 ;
T_1 V_90 = 0 , V_105 = 0 , V_106 = 0 , V_107 ;
V_91 V_92 [ V_93 >> 5 ] ;
int V_95 , V_108 , V_109 , V_57 = 0 , V_110 = 0 , V_89 = 0 ;
bool V_111 = true , V_112 ;
struct V_113 V_32 [ 4 ] ;
struct V_14 * V_50 ;
int V_88 ;
bool V_114 = ! ! ( V_56 -> V_115 & V_116 ) ;
int V_117 , V_72 ;
int V_68 = - 1 ;
V_16 = V_30 -> V_31 ;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
V_18 = F_7 ( V_16 ) ;
memcpy ( V_32 , V_30 -> V_32 , sizeof( V_32 ) ) ;
V_72 = V_56 -> V_118 + 1 ;
for ( V_117 = 0 ; V_117 < V_56 -> V_119 ; V_117 ++ )
V_72 += V_32 [ V_117 ] . V_70 ;
F_61 () ;
V_22 = F_62 ( V_40 , V_43 -> V_120 , V_43 -> V_121 ) ;
if ( ! V_22 ) {
F_63 () ;
F_32 ( & V_54 ) ;
while ( V_30 ) {
V_98 = V_30 -> V_98 ;
if ( ! V_30 -> V_59 . V_86 || V_98 != NULL )
F_64 ( & V_30 -> V_11 , & V_54 ) ;
F_34 ( V_2 , V_30 , V_4 , & V_54 , V_56 , 0 ) ;
V_30 = V_98 ;
}
return;
}
V_21 = (struct V_41 * ) V_22 -> V_122 ;
V_6 = F_18 ( V_2 , V_21 , V_16 ) ;
V_107 = V_6 -> V_60 ;
V_112 = V_56 -> V_123 & V_124 ;
if ( V_112 && V_6 -> V_25 != V_56 -> V_6 )
V_87 = false ;
V_95 = F_58 ( V_30 ) ;
memset ( V_92 , 0 , V_93 >> 3 ) ;
if ( V_95 && V_87 ) {
if ( V_56 -> V_123 & V_124 ) {
V_90 = V_56 -> V_96 ;
memcpy ( V_92 , & V_56 -> V_97 , V_93 >> 3 ) ;
} else {
if ( V_2 -> V_83 -> V_125 == V_126 )
V_110 = 1 ;
}
}
F_65 ( & V_104 ) ;
F_57 ( V_2 , V_30 , V_56 , V_87 , & V_88 , & V_89 ) ;
while ( V_30 ) {
T_1 V_20 = V_30 -> V_59 . V_20 ;
V_108 = V_109 = V_57 = 0 ;
V_98 = V_30 -> V_98 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_50 = F_6 ( V_16 ) ;
if ( ! F_66 ( V_6 -> V_60 , V_6 -> V_127 , V_20 ) ||
! V_6 -> V_128 ) {
V_108 = 1 ;
} else if ( F_59 ( V_92 , F_35 ( V_90 , V_20 ) ) ) {
V_105 ++ ;
} else if ( ! V_95 && V_87 ) {
V_105 ++ ;
} else if ( V_114 ) {
V_109 = 1 ;
} else if ( V_50 -> V_72 < V_129 ) {
if ( V_87 || ! V_21 -> V_130 )
F_43 ( V_2 , V_4 , V_30 -> V_31 ,
V_72 ) ;
V_109 = 1 ;
} else {
V_108 = 1 ;
V_106 ++ ;
V_68 = F_67 ( int , V_68 ,
F_35 ( V_107 , V_20 ) ) ;
}
F_32 ( & V_54 ) ;
if ( V_98 != NULL || ! V_101 -> V_59 . V_86 )
F_64 ( & V_30 -> V_11 , & V_54 ) ;
if ( ! V_109 ) {
F_33 ( V_2 , V_6 , V_20 ) ;
if ( V_111 && ( V_105 == 1 || V_106 == 1 ) ) {
memcpy ( V_18 -> V_131 . V_32 , V_32 , sizeof( V_32 ) ) ;
F_68 ( V_2 , V_30 , V_56 , V_88 , V_89 , V_87 ) ;
V_111 = false ;
}
F_34 ( V_2 , V_30 , V_4 , & V_54 , V_56 ,
! V_108 ) ;
} else {
if ( V_18 -> V_51 & V_132 ) {
V_18 -> V_51 &= ~ V_132 ;
F_69 ( V_22 ) ;
}
if ( V_30 -> V_98 == NULL && V_101 -> V_59 . V_86 ) {
struct V_29 * V_81 ;
V_81 = F_55 ( V_2 , V_101 ) ;
if ( ! V_81 ) {
F_33 ( V_2 , V_6 , V_20 ) ;
F_34 ( V_2 , V_30 , V_4 ,
& V_54 , V_56 , 0 ) ;
V_68 = F_67 ( int , V_68 ,
F_35 ( V_107 , V_20 ) ) ;
break;
}
V_50 -> V_30 = V_81 ;
}
F_70 ( & V_104 , V_16 ) ;
}
V_30 = V_98 ;
}
if ( ! F_23 ( & V_104 ) ) {
if ( V_21 -> V_130 )
F_71 ( V_22 , V_6 -> V_25 , true ) ;
F_72 ( & V_104 , & V_6 -> V_48 ) ;
if ( ! V_21 -> V_130 ) {
F_4 ( V_4 , V_6 ) ;
if ( V_56 -> V_115 & ( V_133 | V_134 ) )
V_6 -> V_8 -> V_135 = true ;
}
}
if ( V_68 >= 0 ) {
T_1 V_136 = F_73 ( V_107 , V_68 ) ;
if ( F_66 ( V_6 -> V_60 , V_6 -> V_127 , V_136 ) )
V_6 -> V_68 = F_35 ( V_6 -> V_60 , V_136 ) ;
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , F_73 ( V_107 , V_68 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_63 () ;
if ( V_110 )
F_74 ( V_2 , V_137 ) ;
}
static bool F_75 ( struct V_29 * V_30 )
{
struct V_17 * V_138 = F_7 ( V_30 -> V_31 ) ;
return F_76 ( V_30 ) && ! ( V_138 -> V_51 & V_139 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_55 * V_56 , struct V_29 * V_30 ,
struct V_53 * V_54 )
{
struct V_17 * V_138 ;
bool V_87 , V_114 ;
V_87 = ! ( V_56 -> V_115 & V_140 ) ;
V_114 = ! ! ( V_56 -> V_115 & V_116 ) ;
V_4 -> V_141 = false ;
V_4 -> V_142 -- ;
if ( F_75 ( V_30 ) )
V_4 -> V_143 -- ;
if ( ! F_76 ( V_30 ) ) {
if ( ! V_114 ) {
V_138 = F_7 ( V_30 -> V_31 ) ;
memcpy ( V_138 -> V_131 . V_32 , V_30 -> V_32 ,
sizeof( V_138 -> V_131 . V_32 ) ) ;
F_68 ( V_2 , V_30 , V_56 , 1 , V_87 ? 0 : 1 , V_87 ) ;
}
F_34 ( V_2 , V_30 , V_4 , V_54 , V_56 , V_87 ) ;
} else
F_60 ( V_2 , V_4 , V_30 , V_54 , V_56 , V_87 ) ;
if ( ! V_114 )
F_78 ( V_2 , V_4 ) ;
}
static bool F_79 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_113 * V_32 ;
int V_117 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_18 -> V_131 . V_32 ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
if ( ! V_32 [ V_117 ] . V_70 || V_32 [ V_117 ] . V_144 < 0 )
break;
if ( ! ( V_32 [ V_117 ] . V_51 & V_145 ) )
return true ;
}
return false ;
}
static V_91 F_80 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_113 * V_32 ;
V_91 V_146 , V_147 ;
T_1 V_148 , V_149 , V_150 = 0 ;
int V_33 = V_6 -> V_8 -> V_4 -> V_151 ;
int V_117 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_146 = V_152 ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
int V_153 ;
if ( ! V_32 [ V_117 ] . V_70 )
continue;
if ( ! ( V_32 [ V_117 ] . V_51 & V_145 ) ) {
V_150 = 1 ;
break;
}
if ( V_32 [ V_117 ] . V_51 & V_154 )
V_153 = V_155 ;
else
V_153 = V_156 ;
if ( V_32 [ V_117 ] . V_51 & V_157 )
V_153 ++ ;
V_147 = V_2 -> V_34 . V_158 [ V_33 ] [ V_153 ] [ V_32 [ V_117 ] . V_144 ] ;
V_146 = F_81 ( V_146 , V_147 ) ;
}
if ( V_18 -> V_51 & V_139 || V_150 )
return 0 ;
V_148 = F_81 ( V_146 , ( V_91 ) V_152 ) ;
V_149 = F_82 ( V_2 , V_146 ) ;
if ( V_149 )
V_148 = V_149 ;
if ( V_6 -> V_21 -> V_159 )
V_148 = F_81 ( V_148 , V_6 -> V_21 -> V_159 ) ;
return V_148 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 V_147 ,
bool V_160 )
{
#define F_84 60
V_91 V_161 , V_162 ;
T_1 V_163 ;
T_2 V_51 , V_164 ;
int V_165 , V_166 , V_167 , V_168 , V_169 ;
struct V_14 * V_50 = F_6 ( V_30 -> V_31 ) ;
V_168 = F_85 ( V_147 ) ;
if ( ( V_50 -> V_170 != V_171 ) &&
! ( V_2 -> V_83 -> V_84 . V_172 & V_173 ) )
V_168 += V_174 ;
if ( V_160 && ! F_86 ( V_2 -> V_83 ) &&
( V_2 -> V_83 -> V_175 & V_176 ) )
V_168 = F_87 ( V_168 , F_84 ) ;
if ( V_6 -> V_21 -> V_177 == 0 )
return V_168 ;
V_164 = V_30 -> V_32 [ 0 ] . V_144 ;
V_51 = V_30 -> V_32 [ 0 ] . V_51 ;
V_165 = ( V_51 & V_154 ) ? 1 : 0 ;
V_167 = ( V_51 & V_157 ) ? 1 : 0 ;
if ( V_167 )
V_162 = F_88 ( V_6 -> V_21 -> V_177 ) ;
else
V_162 = F_89 ( V_6 -> V_21 -> V_177 ) ;
if ( V_162 == 0 )
V_162 = 1 ;
V_166 = F_90 ( V_164 ) ;
V_161 = V_178 [ V_164 % 8 ] [ V_165 ] * V_166 ;
V_163 = ( V_162 * V_161 ) / V_179 ;
if ( V_147 < V_163 ) {
V_169 = ( V_163 - V_147 ) / V_180 ;
V_168 = F_87 ( V_169 , V_168 ) ;
}
return V_168 ;
}
static struct V_29 *
F_91 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_103 * * V_33 )
{
struct V_17 * V_18 ;
struct V_14 * V_50 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
T_1 V_20 ;
while ( 1 ) {
* V_33 = & V_6 -> V_48 ;
if ( F_23 ( * V_33 ) )
* V_33 = & V_6 -> V_47 ;
V_16 = F_92 ( * V_33 ) ;
if ( ! V_16 )
break;
V_50 = F_6 ( V_16 ) ;
V_30 = V_50 -> V_30 ;
if ( ! V_50 -> V_30 )
V_30 = F_28 ( V_2 , V_4 , V_6 , V_16 ) ;
else
V_30 -> V_59 . V_86 = false ;
if ( ! V_30 ) {
F_29 ( V_16 , * V_33 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
F_30 ( V_2 -> V_40 , V_16 ) ;
continue;
}
V_30 -> V_98 = NULL ;
V_30 -> V_102 = V_30 ;
V_18 = F_7 ( V_16 ) ;
V_18 -> V_51 &= ~ V_181 ;
if ( ! ( V_18 -> V_51 & V_52 ) ) {
V_30 -> V_59 . V_182 = 0 ;
return V_30 ;
}
V_30 -> V_59 . V_182 = V_183 | V_184 ;
V_20 = V_30 -> V_59 . V_20 ;
if ( ! F_66 ( V_6 -> V_60 , V_6 -> V_127 , V_20 ) )
break;
if ( V_6 -> V_68 > F_35 ( V_6 -> V_60 , V_20 ) ) {
struct V_55 V_56 = {} ;
struct V_53 V_54 ;
F_32 ( & V_54 ) ;
F_93 ( & V_30 -> V_11 , & V_54 ) ;
F_29 ( V_16 , * V_33 ) ;
F_33 ( V_2 , V_6 , V_20 ) ;
F_34 ( V_2 , V_30 , V_4 , & V_54 , & V_56 , 0 ) ;
continue;
}
return V_30 ;
}
return NULL ;
}
static bool
F_94 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_53 * V_99 ,
struct V_29 * V_185 , struct V_103 * V_12 ,
int * V_186 )
{
#define F_95 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_29 * V_30 = V_185 , * V_187 = NULL ;
int V_88 = 0 , V_168 ;
T_1 V_148 = 0 , V_188 = 0 , V_189 = 0 ,
V_190 , V_191 = V_6 -> V_127 / 2 ;
struct V_17 * V_18 ;
struct V_14 * V_50 ;
struct V_15 * V_16 ;
bool V_192 = false ;
V_30 = V_185 ;
V_148 = F_80 ( V_2 , V_30 , V_6 ) ;
do {
V_16 = V_30 -> V_31 ;
V_50 = F_6 ( V_16 ) ;
V_190 = V_180 + V_50 -> V_193 ;
if ( V_88 ) {
if ( V_148 < V_188 + V_189 + V_190 ||
F_79 ( V_30 ) || V_88 >= V_191 )
break;
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( ( V_18 -> V_51 & V_139 ) ||
! ( V_18 -> V_51 & V_52 ) )
break;
}
V_188 += V_189 + V_190 ;
V_168 = F_83 ( V_2 , V_6 , V_185 , V_50 -> V_193 ,
! V_88 ) ;
V_189 = F_95 ( V_190 ) + ( V_168 << 2 ) ;
V_88 ++ ;
V_30 -> V_98 = NULL ;
if ( ! V_50 -> V_58 )
F_39 ( V_2 , V_6 , V_30 ) ;
V_30 -> V_59 . V_168 = V_168 ;
F_29 ( V_16 , V_12 ) ;
F_5 ( & V_30 -> V_11 , V_99 ) ;
if ( V_187 )
V_187 -> V_98 = V_30 ;
V_187 = V_30 ;
V_30 = F_91 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 ) {
V_192 = true ;
break;
}
} while ( F_22 ( V_6 ) );
V_30 = V_185 ;
V_30 -> V_102 = V_187 ;
if ( V_30 == V_187 ) {
V_188 = F_6 ( V_30 -> V_31 ) -> V_193 ;
V_30 -> V_59 . V_182 = V_183 ;
} else {
F_44 ( V_4 -> V_73 , V_194 ) ;
}
* V_186 = V_188 ;
return V_192 ;
#undef F_95
}
static V_91 F_96 ( struct V_1 * V_2 , T_2 V_164 , int V_195 ,
int V_165 , int V_167 , bool V_196 )
{
V_91 V_197 , V_161 , V_198 , V_162 ;
int V_166 ;
V_166 = F_90 ( V_164 ) ;
V_197 = ( V_195 << 3 ) + V_199 ;
V_161 = V_178 [ V_164 % 8 ] [ V_165 ] * V_166 ;
V_162 = ( V_197 + V_161 - 1 ) / V_161 ;
if ( ! V_167 )
V_198 = F_97 ( V_162 ) ;
else
V_198 = F_98 ( V_162 ) ;
V_198 += V_200 + V_201 + V_202 + V_203 + V_204 + F_99 ( V_166 ) ;
return V_198 ;
}
static int F_100 ( int V_205 , int V_206 , bool V_207 , bool V_208 )
{
int V_166 = F_90 ( V_206 ) ;
int V_209 , V_210 ;
int V_211 = 0 ;
V_209 = V_208 ? F_101 ( V_205 ) : F_102 ( V_205 ) ;
V_210 = V_209 * V_178 [ V_206 % 8 ] [ V_207 ] * V_166 ;
V_210 -= V_199 ;
V_211 = V_210 / 8 ;
V_211 -= V_200 + V_201 + V_202 + V_203 + V_204 + F_99 ( V_166 ) ;
if ( V_211 > 65532 )
V_211 = 65532 ;
return V_211 ;
}
void F_103 ( struct V_1 * V_2 , int V_212 , int V_213 )
{
T_1 * V_214 , * V_215 , * V_216 , * V_217 ;
int V_206 ;
if ( ! V_213 || V_213 > 4096 )
V_213 = 4096 ;
V_214 = V_2 -> V_34 . V_158 [ V_212 ] [ V_156 ] ;
V_215 = V_2 -> V_34 . V_158 [ V_212 ] [ V_218 ] ;
V_216 = V_2 -> V_34 . V_158 [ V_212 ] [ V_155 ] ;
V_217 = V_2 -> V_34 . V_158 [ V_212 ] [ V_219 ] ;
for ( V_206 = 0 ; V_206 < 32 ; V_206 ++ ) {
V_214 [ V_206 ] = F_100 ( V_213 , V_206 , false , false ) ;
V_215 [ V_206 ] = F_100 ( V_213 , V_206 , false , true ) ;
V_216 [ V_206 ] = F_100 ( V_213 , V_206 , true , false ) ;
V_217 [ V_206 ] = F_100 ( V_213 , V_206 , true , true ) ;
}
}
static void F_104 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_220 * V_138 , int V_221 , bool V_222 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_113 * V_32 ;
const struct V_225 * V_226 ;
struct V_42 * V_43 ;
struct V_14 * V_50 = F_6 ( V_30 -> V_31 ) ;
V_91 V_227 = V_2 -> V_40 -> V_228 -> V_229 ;
int V_117 ;
T_2 V_164 = 0 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
V_138 -> V_230 = ! F_105 ( V_43 -> V_45 ) ;
V_138 -> V_231 = V_50 -> V_231 ;
for ( V_117 = 0 ; V_117 < F_13 ( V_30 -> V_32 ) ; V_117 ++ ) {
bool V_232 , V_233 , V_234 ;
int V_235 ;
if ( ! V_32 [ V_117 ] . V_70 || ( V_32 [ V_117 ] . V_144 < 0 ) )
continue;
V_164 = V_32 [ V_117 ] . V_144 ;
V_138 -> V_32 [ V_117 ] . V_236 = V_32 [ V_117 ] . V_70 ;
if ( F_76 ( V_30 ) && ! F_58 ( V_30 ) &&
( V_32 [ V_117 ] . V_51 & V_145 ) &&
F_49 ( V_227 != ( V_91 ) - 1 ) ) {
if ( ! V_227 || ( V_221 > V_227 ) )
V_222 = true ;
}
if ( V_222 || V_32 [ V_117 ] . V_51 & V_237 ) {
V_138 -> V_32 [ V_117 ] . V_238 |= V_239 ;
V_138 -> V_51 |= V_240 ;
} else if ( V_32 [ V_117 ] . V_51 & V_241 ) {
V_138 -> V_32 [ V_117 ] . V_238 |= V_239 ;
V_138 -> V_51 |= V_242 ;
}
if ( V_32 [ V_117 ] . V_51 & V_154 )
V_138 -> V_32 [ V_117 ] . V_238 |= V_243 ;
if ( V_32 [ V_117 ] . V_51 & V_157 )
V_138 -> V_32 [ V_117 ] . V_238 |= V_244 ;
V_233 = ! ! ( V_32 [ V_117 ] . V_51 & V_157 ) ;
V_232 = ! ! ( V_32 [ V_117 ] . V_51 & V_154 ) ;
V_234 = ! ! ( V_32 [ V_117 ] . V_51 & V_245 ) ;
if ( V_32 [ V_117 ] . V_51 & V_145 ) {
V_138 -> V_32 [ V_117 ] . V_246 = V_164 | 0x80 ;
V_138 -> V_32 [ V_117 ] . V_247 = F_106 ( V_2 ,
V_224 -> V_248 , V_138 -> V_32 [ V_117 ] . V_246 ) ;
V_138 -> V_32 [ V_117 ] . V_249 = F_96 ( V_2 , V_164 , V_221 ,
V_232 , V_233 , V_234 ) ;
if ( V_164 < 8 && ( V_18 -> V_51 & V_250 ) )
V_138 -> V_32 [ V_117 ] . V_238 |= V_251 ;
continue;
}
V_226 = & V_2 -> V_252 [ V_18 -> V_253 ] . V_254 [ V_32 [ V_117 ] . V_144 ] ;
if ( ( V_18 -> V_253 == V_255 ) &&
! ( V_226 -> V_51 & V_256 ) )
V_235 = V_257 ;
else
V_235 = V_258 ;
V_138 -> V_32 [ V_117 ] . V_246 = V_226 -> V_259 ;
if ( V_226 -> V_260 ) {
if ( V_32 [ V_117 ] . V_51 & V_245 )
V_138 -> V_32 [ V_117 ] . V_246 |= V_226 -> V_260 ;
} else {
V_234 = false ;
}
if ( V_30 -> V_59 . V_261 )
V_138 -> V_32 [ V_117 ] . V_247 = V_224 -> V_248 ;
else
V_138 -> V_32 [ V_117 ] . V_247 = F_106 ( V_2 ,
V_224 -> V_248 , V_138 -> V_32 [ V_117 ] . V_246 ) ;
V_138 -> V_32 [ V_117 ] . V_249 = F_107 ( V_2 -> V_83 ,
V_235 , V_226 -> V_262 * 100 , V_221 , V_164 , V_234 ) ;
}
if ( F_58 ( V_30 ) && ( V_221 > V_2 -> V_83 -> V_84 . V_263 ) )
V_138 -> V_51 &= ~ V_240 ;
if ( V_138 -> V_51 & V_240 )
V_138 -> V_51 &= ~ V_242 ;
}
static enum V_264 F_108 ( struct V_15 * V_16 )
{
struct V_42 * V_43 ;
enum V_264 V_265 ;
T_4 V_266 ;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
V_266 = V_43 -> V_45 ;
if ( F_109 ( V_266 ) )
V_265 = V_267 ;
else if ( F_110 ( V_266 ) )
V_265 = V_268 ;
else if ( F_111 ( V_266 ) )
V_265 = V_269 ;
else if ( F_105 ( V_266 ) )
V_265 = V_270 ;
else
V_265 = V_271 ;
return V_265 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , int V_221 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_29 * V_185 = NULL ;
struct V_220 V_138 ;
V_91 V_227 = V_2 -> V_40 -> V_228 -> V_229 ;
bool V_222 = false ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_272 = true ;
V_138 . V_273 = true ;
V_138 . V_274 = V_275 ;
V_138 . V_276 = V_4 -> V_73 ;
while ( V_30 ) {
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_14 * V_50 = F_6 ( V_16 ) ;
bool V_277 = ! ! ( V_30 -> V_59 . V_182 & V_184 ) ;
V_138 . type = F_108 ( V_16 ) ;
if ( V_30 -> V_98 )
V_138 . V_278 = V_30 -> V_98 -> V_279 ;
else
V_138 . V_278 = 0 ;
if ( ! V_185 ) {
V_185 = V_30 ;
V_138 . V_51 = V_280 ;
if ( ( V_18 -> V_51 & V_181 ) ||
V_4 == V_2 -> V_34 . V_35 )
V_138 . V_51 |= V_281 ;
if ( V_18 -> V_51 & V_282 )
V_138 . V_51 |= V_283 ;
if ( V_18 -> V_51 & V_284 )
V_138 . V_51 |= V_285 ;
if ( V_30 -> V_59 . V_261 )
V_138 . V_51 |= ( V_91 ) V_30 -> V_59 . V_261 <<
V_286 ;
if ( V_277 && ( V_30 == V_185 ) &&
F_49 ( V_227 != ( V_91 ) - 1 ) ) {
if ( ! V_227 || ( V_221 > V_227 ) )
V_222 = true ;
}
F_104 ( V_2 , V_30 , & V_138 , V_221 , V_222 ) ;
}
V_138 . V_287 [ 0 ] = V_30 -> V_77 ;
V_138 . V_288 [ 0 ] = V_16 -> V_221 ;
V_138 . V_289 = V_50 -> V_193 ;
V_138 . V_170 = V_50 -> V_170 ;
V_138 . V_290 = V_50 -> V_290 ;
if ( V_277 ) {
if ( V_30 == V_185 )
V_138 . V_277 = V_291 ;
else if ( V_30 == V_185 -> V_102 )
V_138 . V_277 = V_292 ;
else
V_138 . V_277 = V_293 ;
V_138 . V_168 = V_30 -> V_59 . V_168 ;
V_138 . V_186 = V_221 ;
}
if ( V_30 == V_185 -> V_102 )
V_185 = NULL ;
F_113 ( V_224 , V_30 -> V_82 , & V_138 ) ;
V_30 = V_30 -> V_98 ;
}
}
static void
F_114 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_53 * V_99 ,
struct V_29 * V_185 , struct V_103 * V_12 )
{
struct V_29 * V_30 = V_185 , * V_187 = NULL ;
struct V_15 * V_16 ;
int V_88 = 0 ;
do {
struct V_17 * V_18 ;
V_16 = V_30 -> V_31 ;
V_88 ++ ;
F_29 ( V_16 , V_12 ) ;
F_5 ( & V_30 -> V_11 , V_99 ) ;
if ( V_187 )
V_187 -> V_98 = V_30 ;
V_187 = V_30 ;
if ( V_88 >= 2 )
break;
V_30 = F_91 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 )
break;
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( V_18 -> V_51 & V_52 )
break;
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
} while ( 1 );
}
static bool F_115 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_294 )
{
struct V_29 * V_30 ;
struct V_17 * V_18 ;
struct V_103 * V_12 ;
struct V_53 V_99 ;
int V_186 = 0 ;
bool V_277 , V_295 = true ;
if ( ! F_22 ( V_6 ) )
return false ;
F_32 ( & V_99 ) ;
V_30 = F_91 ( V_2 , V_4 , V_6 , & V_12 ) ;
if ( ! V_30 )
return false ;
V_18 = F_7 ( V_30 -> V_31 ) ;
V_277 = ! ! ( V_18 -> V_51 & V_52 ) ;
if ( ( V_277 && V_4 -> V_143 >= V_296 ) ||
( ! V_277 && V_4 -> V_142 >= V_297 ) ) {
* V_294 = true ;
return false ;
}
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
if ( V_277 )
V_295 = F_94 ( V_2 , V_4 , V_6 , & V_99 , V_30 ,
V_12 , & V_186 ) ;
else
F_114 ( V_2 , V_4 , V_6 , & V_99 , V_30 , V_12 ) ;
if ( F_50 ( & V_99 ) )
return false ;
if ( V_6 -> V_8 -> V_135 || V_6 -> V_21 -> V_298 ) {
V_6 -> V_8 -> V_135 = false ;
V_18 -> V_51 |= V_181 ;
}
F_112 ( V_2 , V_30 , V_4 , V_186 ) ;
F_116 ( V_2 , V_4 , & V_99 , false ) ;
return true ;
}
int F_117 ( struct V_1 * V_2 , struct V_28 * V_22 ,
T_1 V_6 , T_1 * V_299 )
{
struct V_5 * V_300 ;
struct V_3 * V_4 ;
struct V_41 * V_21 ;
T_2 V_301 ;
V_21 = (struct V_41 * ) V_22 -> V_122 ;
V_300 = F_21 ( V_21 , V_6 ) ;
V_4 = V_300 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_22 -> V_302 . V_303 ) {
V_21 -> V_159 = 1 << ( V_304 +
V_22 -> V_302 . V_305 ) ;
V_301 = F_118 ( V_22 -> V_302 . V_306 ) ;
V_21 -> V_177 = V_301 ;
}
F_26 ( V_2 , V_300 ) ;
V_300 -> V_128 = true ;
V_300 -> V_9 = true ;
* V_299 = V_300 -> V_60 = V_300 -> V_307 ;
V_300 -> V_68 = - 1 ;
memset ( V_300 -> V_65 , 0 , sizeof( V_300 -> V_65 ) ) ;
V_300 -> V_63 = V_300 -> V_66 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_119 ( struct V_1 * V_2 , struct V_28 * V_22 , T_1 V_6 )
{
struct V_41 * V_21 = (struct V_41 * ) V_22 -> V_122 ;
struct V_5 * V_300 = F_21 ( V_21 , V_6 ) ;
struct V_3 * V_4 = V_300 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_300 -> V_128 = false ;
V_300 -> V_9 = false ;
F_31 ( V_2 , V_300 ) ;
F_26 ( V_2 , V_300 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_120 ( struct V_28 * V_22 , struct V_1 * V_2 ,
struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_308 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_309 ; V_25 ++ , V_6 ++ ) {
if ( ! V_6 -> V_10 )
continue;
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_308 = F_22 ( V_6 ) ;
V_6 -> V_10 = false ;
F_53 ( & V_6 -> V_11 ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = false ;
F_53 ( & V_8 -> V_11 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_71 ( V_22 , V_25 , V_308 ) ;
}
}
void F_121 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_309 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_135 = true ;
if ( ! V_6 -> V_9 && F_22 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_78 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_122 ( struct V_1 * V_2 , struct V_28 * V_22 ,
T_1 V_25 )
{
struct V_5 * V_6 ;
struct V_41 * V_21 ;
struct V_3 * V_4 ;
V_21 = (struct V_41 * ) V_22 -> V_122 ;
V_6 = F_21 ( V_21 , V_25 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_127 = V_310 << V_22 -> V_302 . V_305 ;
V_6 -> V_9 = false ;
if ( F_22 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_78 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_123 ( struct V_100 * V_40 ,
struct V_28 * V_22 ,
T_1 V_311 , int V_88 ,
enum V_312 V_313 ,
bool V_314 )
{
struct V_1 * V_2 = V_40 -> V_315 ;
struct V_41 * V_21 = (struct V_41 * ) V_22 -> V_122 ;
struct V_3 * V_4 = V_2 -> V_34 . V_35 ;
struct V_17 * V_138 ;
struct V_53 V_99 ;
struct V_29 * V_316 = NULL , * V_30 ;
struct V_103 * V_12 ;
int V_317 = 0 ;
int V_117 ;
F_32 ( & V_99 ) ;
for ( V_117 = 0 ; V_311 && V_88 ; V_117 ++ , V_311 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_311 & 1 ) )
continue;
V_6 = F_21 ( V_21 , V_117 ) ;
if ( V_6 -> V_9 )
continue;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_88 > 0 ) {
V_30 = F_91 ( V_2 , V_2 -> V_34 . V_35 , V_6 , & V_12 ) ;
if ( ! V_30 )
break;
F_29 ( V_30 -> V_31 , V_12 ) ;
F_5 ( & V_30 -> V_11 , & V_99 ) ;
F_11 ( V_6 -> V_21 -> V_23 , V_6 -> V_21 -> V_22 , V_30 ) ;
if ( F_76 ( V_30 ) ) {
F_39 ( V_2 , V_6 , V_30 ) ;
V_30 -> V_59 . V_182 &= ~ V_184 ;
}
if ( V_316 )
V_316 -> V_98 = V_30 ;
V_316 = V_30 ;
V_88 -- ;
V_317 ++ ;
F_44 ( V_4 -> V_73 , V_318 ) ;
if ( V_21 -> V_22 && ! F_22 ( V_6 ) )
F_71 ( V_21 -> V_22 , V_117 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_50 ( & V_99 ) )
return;
V_138 = F_7 ( V_316 -> V_31 ) ;
V_138 -> V_51 |= V_132 ;
V_30 = F_52 ( & V_99 , struct V_29 , V_11 ) ;
F_1 ( V_2 , V_4 ) ;
F_112 ( V_2 , V_30 , V_4 , 0 ) ;
F_116 ( V_2 , V_4 , & V_99 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_124 ( struct V_1 * V_2 , int V_319 , int V_320 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_321 V_322 ;
static const int V_323 [] = {
[ V_324 ] = V_325 ,
[ V_326 ] = V_327 ,
[ V_328 ] = V_329 ,
[ V_330 ] = V_331 ,
} ;
int V_73 , V_117 ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_332 = V_323 [ V_320 ] ;
V_322 . V_333 = V_334 ;
V_322 . V_335 = V_334 ;
V_322 . V_336 = V_334 ;
V_322 . V_337 = 0 ;
if ( V_224 -> V_84 . V_172 & V_173 ) {
V_322 . V_338 = V_339 ;
} else {
if ( V_319 == V_340 )
V_322 . V_338 = V_341 ;
else
V_322 . V_338 = V_342 |
V_341 ;
}
V_73 = F_125 ( V_224 , V_319 , & V_322 ) ;
if ( V_73 == - 1 ) {
return NULL ;
}
if ( ! F_126 ( V_2 , V_73 ) ) {
struct V_3 * V_4 = & V_2 -> V_34 . V_4 [ V_73 ] ;
V_4 -> V_73 = V_73 ;
V_4 -> V_151 = - 1 ;
V_4 -> V_343 = NULL ;
F_65 ( & V_4 -> V_344 ) ;
F_32 ( & V_4 -> V_345 ) ;
F_32 ( & V_4 -> V_13 ) ;
F_127 ( & V_4 -> V_346 ) ;
V_4 -> V_142 = 0 ;
V_4 -> V_143 = 0 ;
V_4 -> V_141 = false ;
V_2 -> V_34 . V_347 |= 1 << V_73 ;
V_4 -> V_348 = V_4 -> V_349 = 0 ;
for ( V_117 = 0 ; V_117 < V_350 ; V_117 ++ )
F_32 ( & V_4 -> V_351 [ V_117 ] ) ;
}
return & V_2 -> V_34 . V_4 [ V_73 ] ;
}
int F_128 ( struct V_1 * V_2 , int V_352 ,
struct V_321 * V_353 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
int error = 0 ;
struct V_321 V_322 ;
F_129 ( V_2 -> V_34 . V_4 [ V_352 ] . V_73 != V_352 ) ;
F_130 ( V_224 , V_352 , & V_322 ) ;
V_322 . V_333 = V_353 -> V_333 ;
V_322 . V_335 = V_353 -> V_335 ;
V_322 . V_336 = V_353 -> V_336 ;
V_322 . V_354 = V_353 -> V_354 ;
V_322 . V_355 = V_353 -> V_355 ;
if ( ! F_131 ( V_224 , V_352 , & V_322 ) ) {
F_132 ( F_133 ( V_2 -> V_83 ) ,
L_1 , V_352 ) ;
error = - V_356 ;
} else {
F_134 ( V_224 , V_352 ) ;
}
return error ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_321 V_322 ;
struct V_357 * V_358 = & V_2 -> V_359 ;
int V_352 = V_2 -> V_360 . V_361 -> V_73 ;
F_130 ( V_2 -> V_83 , V_352 , & V_322 ) ;
if ( V_2 -> V_362 . V_363 < V_364 )
V_2 -> V_362 . V_363 = V_364 ;
else if ( V_2 -> V_362 . V_363 > V_365 )
V_2 -> V_362 . V_363 = V_365 ;
V_322 . V_355 = ( V_358 -> V_366 *
V_2 -> V_362 . V_363 ) / 100 ;
F_128 ( V_2 , V_352 , & V_322 ) ;
return 0 ;
}
static void F_136 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_53 * V_11 )
{
struct V_29 * V_30 , * V_367 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_115 = V_116 ;
F_32 ( & V_54 ) ;
while ( ! F_50 ( V_11 ) ) {
V_30 = F_52 ( V_11 , struct V_29 , V_11 ) ;
if ( V_30 -> V_59 . V_86 ) {
F_53 ( & V_30 -> V_11 ) ;
F_54 ( V_2 , V_30 ) ;
continue;
}
V_367 = V_30 -> V_102 ;
F_137 ( & V_54 , V_11 , & V_367 -> V_11 ) ;
F_77 ( V_2 , V_4 , & V_56 , V_30 , & V_54 ) ;
}
}
void F_138 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_83 -> V_84 . V_172 & V_173 ) {
int V_144 = V_4 -> V_349 ;
while ( ! F_50 ( & V_4 -> V_351 [ V_144 ] ) ) {
F_136 ( V_2 , V_4 , & V_4 -> V_351 [ V_144 ] ) ;
F_38 ( V_144 , V_350 ) ;
}
V_4 -> V_349 = V_144 ;
}
V_4 -> V_343 = NULL ;
V_4 -> V_141 = false ;
F_136 ( V_2 , V_4 , & V_4 -> V_345 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_139 ( struct V_1 * V_2 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_368 * V_369 = F_133 ( V_2 -> V_83 ) ;
struct V_3 * V_4 ;
int V_117 ;
V_91 V_370 = 0 ;
if ( F_37 ( V_371 , & V_2 -> V_372 ) )
return true ;
F_140 ( V_224 ) ;
for ( V_117 = 0 ; V_117 < V_373 ; V_117 ++ ) {
if ( ! F_126 ( V_2 , V_117 ) )
continue;
if ( F_141 ( V_224 , V_2 -> V_34 . V_4 [ V_117 ] . V_73 ) )
V_370 |= F_142 ( V_117 ) ;
}
if ( V_370 )
F_132 ( V_369 , L_2 , V_370 ) ;
for ( V_117 = 0 ; V_117 < V_373 ; V_117 ++ ) {
if ( ! F_126 ( V_2 , V_117 ) )
continue;
V_4 = & V_2 -> V_34 . V_4 [ V_117 ] ;
V_4 -> V_38 = false ;
F_138 ( V_2 , V_4 ) ;
}
return ! V_370 ;
}
void F_143 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_144 ( V_2 -> V_83 , V_4 -> V_73 ) ;
V_2 -> V_34 . V_347 &= ~ ( 1 << V_4 -> V_73 ) ;
}
void F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 , * V_374 ;
struct V_5 * V_6 , * V_375 ;
bool V_317 = false ;
if ( F_37 ( V_376 , & V_2 -> V_372 ) ||
F_50 ( & V_4 -> V_13 ) )
return;
F_61 () ;
V_374 = F_145 ( V_4 -> V_13 . V_71 , struct V_7 , V_11 ) ;
while ( ! F_50 ( & V_4 -> V_13 ) ) {
bool V_294 = false ;
V_8 = F_52 ( & V_4 -> V_13 , struct V_7 , V_11 ) ;
V_375 = F_145 ( V_8 -> V_12 . V_71 , struct V_5 , V_11 ) ;
F_53 ( & V_8 -> V_11 ) ;
V_8 -> V_10 = false ;
while ( ! F_50 ( & V_8 -> V_12 ) ) {
V_6 = F_52 ( & V_8 -> V_12 , struct V_5 ,
V_11 ) ;
F_53 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
if ( V_6 -> V_9 )
continue;
if ( F_115 ( V_2 , V_4 , V_6 , & V_294 ) )
V_317 = true ;
if ( F_22 ( V_6 ) )
F_4 ( V_4 , V_6 ) ;
if ( V_294 || V_6 == V_375 )
break;
}
if ( ! F_50 ( & V_8 -> V_12 ) && ! V_8 -> V_10 ) {
V_8 -> V_10 = true ;
F_5 ( & V_8 -> V_11 , & V_4 -> V_13 ) ;
}
if ( V_294 )
break;
if ( V_8 == V_374 ) {
if ( ! V_317 )
break;
V_317 = false ;
V_374 = F_145 ( V_4 -> V_13 . V_71 ,
struct V_7 , V_11 ) ;
}
}
F_63 () ;
}
static void F_116 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_53 * V_377 , bool V_378 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_368 * V_369 = F_133 ( V_224 ) ;
struct V_29 * V_30 , * V_101 ;
bool V_379 = false ;
bool V_380 ;
if ( F_50 ( V_377 ) )
return;
V_380 = ! ! ( V_224 -> V_84 . V_172 & V_173 ) ;
V_30 = F_52 ( V_377 , struct V_29 , V_11 ) ;
V_101 = F_145 ( V_377 -> V_71 , struct V_29 , V_11 ) ;
F_146 ( V_369 , V_381 , L_3 ,
V_4 -> V_73 , V_4 -> V_142 ) ;
if ( V_380 && F_50 ( & V_4 -> V_351 [ V_4 -> V_348 ] ) ) {
F_147 ( V_377 , & V_4 -> V_351 [ V_4 -> V_348 ] ) ;
F_38 ( V_4 -> V_348 , V_350 ) ;
V_379 = true ;
} else {
F_147 ( V_377 , & V_4 -> V_345 ) ;
if ( V_4 -> V_343 ) {
F_148 ( V_224 , V_4 -> V_343 , V_30 -> V_279 ) ;
F_146 ( V_369 , V_382 , L_4 ,
V_4 -> V_73 , V_4 -> V_343 ,
F_149 ( V_30 -> V_279 ) , V_30 -> V_82 ) ;
} else if ( ! V_380 )
V_379 = true ;
V_4 -> V_343 = V_101 -> V_82 ;
}
if ( V_379 ) {
F_44 ( V_4 -> V_73 , V_379 ) ;
F_150 ( V_224 , V_4 -> V_73 , V_30 -> V_279 ) ;
F_146 ( V_369 , V_382 , L_5 ,
V_4 -> V_73 , F_149 ( V_30 -> V_279 ) , V_30 -> V_82 ) ;
}
if ( ! V_380 ) {
F_44 ( V_4 -> V_73 , V_383 ) ;
F_151 ( V_224 , V_4 -> V_73 ) ;
}
if ( ! V_378 ) {
while ( V_30 ) {
V_4 -> V_142 ++ ;
if ( F_75 ( V_30 ) )
V_4 -> V_143 ++ ;
V_101 = V_30 -> V_102 ;
V_30 = V_101 -> V_98 ;
V_101 -> V_98 = NULL ;
}
}
}
static void F_152 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_14 * V_50 = F_6 ( V_16 ) ;
struct V_53 V_54 ;
struct V_29 * V_30 = V_50 -> V_30 ;
F_32 ( & V_54 ) ;
F_5 ( & V_30 -> V_11 , & V_54 ) ;
V_30 -> V_59 . V_182 = 0 ;
if ( V_6 && ( V_18 -> V_51 & V_52 ) ) {
V_30 -> V_59 . V_182 = V_183 ;
F_39 ( V_2 , V_6 , V_30 ) ;
}
V_30 -> V_98 = NULL ;
V_30 -> V_102 = V_30 ;
F_112 ( V_2 , V_30 , V_4 , V_50 -> V_193 ) ;
F_116 ( V_2 , V_4 , & V_54 , false ) ;
F_44 ( V_4 -> V_73 , V_384 ) ;
}
static void F_153 ( struct V_100 * V_40 ,
struct V_28 * V_22 ,
struct V_15 * V_16 ,
int V_193 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_385 * V_386 = V_18 -> V_131 . V_386 ;
struct V_42 * V_43 = (struct V_42 * ) V_16 -> V_44 ;
const struct V_225 * V_226 ;
struct V_14 * V_50 = F_6 ( V_16 ) ;
struct V_41 * V_21 = NULL ;
enum V_387 V_290 ;
bool V_388 = false ;
if ( V_18 -> V_131 . V_23 &&
V_18 -> V_131 . V_23 -> V_389 . V_390 )
V_388 = true ;
V_226 = F_154 ( V_40 , V_18 ) ;
V_290 = F_155 ( V_16 ) ;
if ( V_22 )
V_21 = (struct V_41 * ) V_22 -> V_122 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
if ( V_386 )
V_50 -> V_170 = V_386 -> V_391 ;
else if ( V_21 && F_156 ( V_43 -> V_45 ) && V_21 -> V_392 > 0 )
V_50 -> V_170 = V_21 -> V_392 ;
else
V_50 -> V_170 = V_171 ;
V_50 -> V_290 = V_290 ;
V_50 -> V_193 = V_193 ;
V_50 -> V_231 = V_226 -> V_259 ;
if ( V_388 )
V_50 -> V_231 |= V_226 -> V_260 ;
}
T_2 F_106 ( struct V_1 * V_2 , T_2 V_393 , V_91 V_226 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_394 * V_395 = V_224 -> V_395 ;
if ( ( V_224 -> V_84 . V_172 & V_396 ) &&
( V_395 -> V_397 & V_398 ) &&
( V_393 == 0x7 ) && ( V_226 < 0x90 ) )
return 0x3 ;
else if ( F_157 ( V_224 ) && F_158 ( V_224 ) &&
F_159 ( V_226 ) )
return 0x2 ;
else
return V_393 ;
}
static struct V_29 * F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
struct V_368 * V_369 = F_133 ( V_2 -> V_83 ) ;
struct V_14 * V_50 = F_6 ( V_16 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_16 -> V_44 ;
struct V_29 * V_30 ;
int V_399 ;
T_1 V_20 ;
V_30 = F_47 ( V_2 ) ;
if ( ! V_30 ) {
F_146 ( V_369 , V_382 , L_6 ) ;
return NULL ;
}
F_56 ( V_30 ) ;
if ( V_6 ) {
V_399 = F_160 ( V_43 -> V_400 ) & V_401 ;
V_20 = V_6 -> V_307 ;
V_43 -> V_400 = F_45 ( V_6 -> V_307 << V_26 ) ;
if ( V_399 )
V_43 -> V_400 |= F_45 ( V_399 ) ;
if ( ! F_161 ( V_43 -> V_45 ) )
F_38 ( V_6 -> V_307 , V_67 ) ;
V_30 -> V_59 . V_20 = V_20 ;
}
V_30 -> V_31 = V_16 ;
V_30 -> V_77 = F_162 ( V_2 -> V_76 , V_16 -> V_44 ,
V_16 -> V_221 , V_78 ) ;
if ( F_49 ( F_163 ( V_2 -> V_76 , V_30 -> V_77 ) ) ) {
V_30 -> V_31 = NULL ;
V_30 -> V_77 = 0 ;
F_132 ( F_133 ( V_2 -> V_83 ) ,
L_7 ) ;
F_54 ( V_2 , V_30 ) ;
return NULL ;
}
V_50 -> V_30 = V_30 ;
return V_30 ;
}
static int F_164 ( struct V_100 * V_40 , struct V_15 * V_16 ,
struct V_402 * V_403 )
{
struct V_42 * V_43 = (struct V_42 * ) V_16 -> V_44 ;
struct V_17 * V_138 = F_7 ( V_16 ) ;
struct V_28 * V_22 = V_403 -> V_22 ;
struct V_27 * V_23 = V_138 -> V_131 . V_23 ;
struct V_404 * V_405 ;
struct V_1 * V_2 = V_40 -> V_315 ;
int V_147 = V_16 -> V_221 + V_406 ;
int V_407 , V_408 ;
if ( V_22 )
V_403 -> V_21 = (struct V_41 * ) V_22 -> V_122 ;
else if ( V_23 && F_156 ( V_43 -> V_45 ) ) {
V_405 = ( void * ) V_23 -> V_122 ;
V_403 -> V_21 = & V_405 -> V_409 ;
}
if ( V_138 -> V_131 . V_386 )
V_147 += V_138 -> V_131 . V_386 -> V_410 ;
if ( V_138 -> V_51 & V_411 ) {
if ( V_138 -> V_51 & V_412 )
V_2 -> V_34 . V_413 += 0x10 ;
V_43 -> V_400 &= F_45 ( V_401 ) ;
V_43 -> V_400 |= F_45 ( V_2 -> V_34 . V_413 ) ;
}
if ( ( V_23 && V_23 -> type != V_414 &&
V_23 -> type != V_415 ) ||
! F_156 ( V_43 -> V_45 ) )
V_138 -> V_51 |= V_181 ;
V_407 = F_165 ( V_43 -> V_45 ) ;
V_408 = V_407 & 3 ;
if ( V_408 && V_16 -> V_221 > V_407 ) {
if ( F_166 ( V_16 ) < V_408 )
return - V_416 ;
F_167 ( V_16 , V_408 ) ;
memmove ( V_16 -> V_44 , V_16 -> V_44 + V_408 , V_407 ) ;
}
F_153 ( V_40 , V_22 , V_16 , V_147 ) ;
return 0 ;
}
int F_168 ( struct V_100 * V_40 , struct V_15 * V_16 ,
struct V_402 * V_403 )
{
struct V_42 * V_43 ;
struct V_17 * V_138 = F_7 ( V_16 ) ;
struct V_28 * V_22 = V_403 -> V_22 ;
struct V_27 * V_23 = V_138 -> V_131 . V_23 ;
struct V_1 * V_2 = V_40 -> V_315 ;
struct V_3 * V_4 = V_403 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_30 ;
int V_33 ;
int V_417 ;
V_417 = F_164 ( V_40 , V_16 , V_403 ) ;
if ( V_417 )
return V_417 ;
V_43 = (struct V_42 * ) V_16 -> V_44 ;
V_33 = F_15 ( V_16 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_34 . V_36 [ V_33 ] &&
++ V_4 -> V_37 > V_2 -> V_34 . V_39 [ V_33 ] &&
! V_4 -> V_38 ) {
F_169 ( V_2 -> V_40 , V_33 ) ;
V_4 -> V_38 = true ;
}
if ( V_138 -> V_51 & V_418 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_34 . V_35 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_403 -> V_21 &&
F_170 ( V_43 -> V_45 ) ) {
V_6 = F_18 ( V_2 , V_403 -> V_21 , V_16 ) ;
F_16 ( V_6 -> V_8 -> V_4 != V_403 -> V_4 ) ;
if ( V_138 -> V_51 & V_181 )
V_6 -> V_8 -> V_135 = true ;
F_44 ( V_4 -> V_73 , V_419 ) ;
F_70 ( & V_6 -> V_47 , V_16 ) ;
if ( ! V_403 -> V_21 -> V_130 )
F_4 ( V_4 , V_6 ) ;
F_78 ( V_2 , V_4 ) ;
goto V_420;
}
V_30 = F_28 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
if ( V_403 -> V_421 )
F_171 ( V_16 ) ;
else
F_30 ( V_2 -> V_40 , V_16 ) ;
goto V_420;
}
V_30 -> V_59 . V_261 = V_403 -> V_421 ;
if ( V_403 -> V_421 )
V_30 -> V_59 . V_422 = V_423 ;
F_11 ( V_23 , V_22 , V_30 ) ;
F_152 ( V_2 , V_4 , V_6 , V_16 ) ;
V_420:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_172 ( struct V_100 * V_40 , struct V_27 * V_23 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_40 -> V_315 ;
struct V_402 V_403 = {
. V_4 = V_2 -> V_360 . V_361
} ;
struct V_220 V_138 = {} ;
struct V_42 * V_43 ;
struct V_29 * V_316 = NULL ;
struct V_29 * V_30 ;
F_173 ( V_99 ) ;
int V_198 = 0 ;
int V_424 ;
V_424 =
V_2 -> V_359 . V_366 * 1000 *
V_2 -> V_359 . V_425 / V_426 ;
do {
struct V_14 * V_50 = F_6 ( V_16 ) ;
if ( F_164 ( V_40 , V_16 , & V_403 ) )
break;
V_30 = F_28 ( V_2 , V_403 . V_4 , NULL , V_16 ) ;
if ( ! V_30 )
break;
V_30 -> V_102 = V_30 ;
F_11 ( V_23 , NULL , V_30 ) ;
F_104 ( V_2 , V_30 , & V_138 , V_50 -> V_193 , false ) ;
V_198 += V_138 . V_32 [ 0 ] . V_249 ;
if ( V_316 )
V_316 -> V_98 = V_30 ;
F_5 ( & V_30 -> V_11 , & V_99 ) ;
V_316 = V_30 ;
V_16 = NULL ;
if ( V_198 > V_424 )
break;
V_16 = F_174 ( V_40 , V_23 ) ;
} while( V_16 );
if ( V_16 )
F_30 ( V_40 , V_16 ) ;
if ( F_50 ( & V_99 ) )
return;
V_30 = F_52 ( & V_99 , struct V_29 , V_11 ) ;
V_43 = (struct V_42 * ) V_30 -> V_31 -> V_44 ;
if ( V_43 -> V_45 & V_427 ) {
V_43 -> V_45 &= ~ V_427 ;
F_46 ( V_2 -> V_76 , V_30 -> V_77 ,
sizeof( * V_43 ) , V_78 ) ;
}
F_1 ( V_2 , V_403 . V_4 ) ;
F_112 ( V_2 , V_30 , V_403 . V_4 , 0 ) ;
F_116 ( V_2 , V_403 . V_4 , & V_99 , false ) ;
F_44 ( V_403 . V_4 -> V_73 , V_384 ) ;
F_2 ( V_2 , V_403 . V_4 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_428 , struct V_3 * V_4 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_368 * V_369 = F_133 ( V_2 -> V_83 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_16 -> V_44 ;
int V_407 , V_408 ;
unsigned long V_51 ;
F_146 ( V_369 , V_382 , L_8 , V_16 ) ;
if ( V_2 -> V_83 -> V_429 )
V_2 -> V_83 -> V_429 -> V_430 = true ;
if ( ! ( V_428 & V_69 ) )
V_18 -> V_51 |= V_431 ;
V_407 = F_165 ( V_43 -> V_45 ) ;
V_408 = V_407 & 3 ;
if ( V_408 && V_16 -> V_221 > V_407 + V_408 ) {
memmove ( V_16 -> V_44 + V_408 , V_16 -> V_44 , V_407 ) ;
F_175 ( V_16 , V_408 ) ;
}
F_176 ( & V_2 -> V_432 , V_51 ) ;
if ( ( V_2 -> V_433 & V_434 ) && ! V_4 -> V_142 ) {
V_2 -> V_433 &= ~ V_434 ;
F_146 ( V_369 , V_435 ,
L_9 ,
V_2 -> V_433 & ( V_436 |
V_437 |
V_438 |
V_434 ) ) ;
}
F_177 ( & V_2 -> V_432 , V_51 ) ;
F_70 ( & V_4 -> V_344 , V_16 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , struct V_53 * V_99 ,
struct V_55 * V_56 , int V_87 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
unsigned long V_51 ;
int V_428 = 0 ;
if ( ! V_87 )
V_428 |= V_69 ;
if ( V_56 -> V_115 & V_133 )
V_18 -> V_51 |= V_439 ;
F_178 ( V_2 -> V_76 , V_30 -> V_77 , V_16 -> V_221 , V_78 ) ;
V_30 -> V_77 = 0 ;
if ( V_30 -> V_59 . V_261 ) {
if ( F_179 ( V_423 ,
V_30 -> V_59 . V_422 +
F_180 ( V_440 ) ) )
F_171 ( V_16 ) ;
else
F_181 ( & V_2 -> V_441 ) ;
} else {
F_182 ( V_2 , V_30 , V_56 , V_4 , V_428 ) ;
F_42 ( V_2 , V_16 , V_428 , V_4 ) ;
}
V_30 -> V_31 = NULL ;
F_176 ( & V_2 -> V_34 . V_79 , V_51 ) ;
F_147 ( V_99 , & V_2 -> V_34 . V_80 ) ;
F_177 ( & V_2 -> V_34 . V_79 , V_51 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_55 * V_56 , int V_88 , int V_89 ,
int V_87 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_42 * V_43 = (struct V_42 * ) V_16 -> V_44 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_100 * V_40 = V_2 -> V_40 ;
struct V_223 * V_224 = V_2 -> V_83 ;
T_2 V_117 , V_442 ;
if ( V_87 )
V_18 -> V_443 . V_444 = V_56 -> V_445 ;
V_442 = V_56 -> V_119 ;
F_16 ( V_442 >= V_40 -> V_446 ) ;
if ( V_18 -> V_51 & V_52 ) {
V_18 -> V_51 |= V_447 ;
F_129 ( V_89 > V_88 ) ;
}
V_18 -> V_443 . V_448 = V_88 ;
V_18 -> V_443 . V_449 = V_88 - V_89 ;
if ( ( V_56 -> V_115 & V_133 ) == 0 &&
( V_18 -> V_51 & V_282 ) == 0 ) {
if ( F_49 ( V_56 -> V_123 & ( V_450 |
V_451 ) ) &&
F_156 ( V_43 -> V_45 ) &&
V_224 -> V_452 >= V_2 -> V_83 -> V_362 . V_453 )
V_18 -> V_443 . V_32 [ V_442 ] . V_70 =
V_40 -> V_454 ;
}
for ( V_117 = V_442 + 1 ; V_117 < V_40 -> V_446 ; V_117 ++ ) {
V_18 -> V_443 . V_32 [ V_117 ] . V_70 = 0 ;
V_18 -> V_443 . V_32 [ V_117 ] . V_144 = - 1 ;
}
V_18 -> V_443 . V_32 [ V_442 ] . V_70 = V_56 -> V_118 + 1 ;
}
static void F_183 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_368 * V_369 = F_133 ( V_224 ) ;
struct V_29 * V_30 , * V_367 , * V_455 = NULL ;
struct V_53 V_54 ;
struct V_456 * V_457 ;
struct V_55 V_56 ;
int V_443 ;
F_146 ( V_369 , V_381 , L_10 ,
V_4 -> V_73 , F_184 ( V_2 -> V_83 , V_4 -> V_73 ) ,
V_4 -> V_343 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_37 ( V_376 , & V_2 -> V_372 ) )
break;
if ( F_50 ( & V_4 -> V_345 ) ) {
V_4 -> V_343 = NULL ;
F_78 ( V_2 , V_4 ) ;
break;
}
V_30 = F_52 ( & V_4 -> V_345 , struct V_29 , V_11 ) ;
V_455 = NULL ;
if ( V_30 -> V_59 . V_86 ) {
V_455 = V_30 ;
if ( F_185 ( & V_455 -> V_11 , & V_4 -> V_345 ) )
break;
V_30 = F_145 ( V_455 -> V_11 . V_458 , struct V_29 ,
V_11 ) ;
}
V_367 = V_30 -> V_102 ;
V_457 = V_367 -> V_82 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_443 = F_186 ( V_224 , V_457 , & V_56 ) ;
if ( V_443 == - V_459 )
break;
F_44 ( V_4 -> V_73 , V_460 ) ;
V_367 -> V_59 . V_86 = true ;
F_32 ( & V_54 ) ;
if ( ! F_187 ( & V_367 -> V_11 ) )
F_137 ( & V_54 ,
& V_4 -> V_345 , V_367 -> V_11 . V_71 ) ;
if ( V_455 ) {
F_53 ( & V_455 -> V_11 ) ;
F_54 ( V_2 , V_455 ) ;
}
F_77 ( V_2 , V_4 , & V_56 , V_30 , & V_54 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
V_91 V_461 = ( ( 1 << V_373 ) - 1 ) & V_224 -> V_462 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_373 ; V_117 ++ ) {
if ( F_126 ( V_2 , V_117 ) && ( V_461 & ( 1 << V_117 ) ) )
F_183 ( V_2 , & V_2 -> V_34 . V_4 [ V_117 ] ) ;
}
}
void F_189 ( struct V_1 * V_2 )
{
struct V_55 V_56 ;
struct V_368 * V_369 = F_133 ( V_2 -> V_83 ) ;
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_3 * V_4 ;
struct V_29 * V_30 , * V_367 ;
struct V_53 V_54 ;
struct V_53 * V_463 ;
int V_443 ;
for (; ; ) {
if ( F_37 ( V_376 , & V_2 -> V_372 ) )
break;
V_443 = F_186 ( V_224 , NULL , ( void * ) & V_56 ) ;
if ( V_443 == - V_459 )
break;
if ( V_443 == - V_356 ) {
F_146 ( V_369 , V_382 , L_11 ) ;
break;
}
if ( V_56 . V_464 == V_2 -> V_360 . V_465 ) {
V_2 -> V_360 . V_466 = true ;
V_2 -> V_360 . V_467 = ! ( V_56 . V_115 & V_140 ) ;
F_190 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_34 . V_4 [ V_56 . V_464 ] ;
F_1 ( V_2 , V_4 ) ;
F_44 ( V_4 -> V_73 , V_460 ) ;
V_463 = & V_4 -> V_351 [ V_4 -> V_349 ] ;
if ( F_50 ( V_463 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_30 = F_52 ( V_463 , struct V_29 , V_11 ) ;
if ( V_30 -> V_59 . V_86 ) {
F_53 ( & V_30 -> V_11 ) ;
F_54 ( V_2 , V_30 ) ;
V_30 = F_52 ( V_463 , struct V_29 , V_11 ) ;
}
V_367 = V_30 -> V_102 ;
F_32 ( & V_54 ) ;
if ( F_185 ( & V_367 -> V_11 , V_463 ) ) {
F_147 ( V_463 , & V_54 ) ;
F_38 ( V_4 -> V_349 , V_350 ) ;
if ( ! F_50 ( & V_4 -> V_345 ) ) {
struct V_53 V_99 ;
F_32 ( & V_99 ) ;
V_4 -> V_343 = NULL ;
F_147 ( & V_4 -> V_345 , & V_99 ) ;
F_116 ( V_2 , V_4 , & V_99 , true ) ;
}
} else {
V_367 -> V_59 . V_86 = true ;
if ( V_30 != V_367 )
F_137 ( & V_54 , V_463 ,
V_367 -> V_11 . V_71 ) ;
}
F_77 ( V_2 , V_4 , & V_56 , V_30 , & V_54 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_191 ( struct V_1 * V_2 , int V_468 )
{
struct V_469 * V_470 = & V_2 -> V_471 ;
T_2 V_472 = V_2 -> V_83 -> V_84 . V_472 ;
V_470 -> V_473 = V_468 * V_472 ;
V_470 -> V_474 = F_192 ( V_2 -> V_76 , V_470 -> V_473 ,
& V_470 -> V_475 , V_476 ) ;
if ( ! V_470 -> V_474 )
return - V_416 ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 )
{
int V_477 ;
V_477 = F_191 ( V_2 , V_478 ) ;
if ( ! V_477 )
F_194 ( V_2 -> V_83 , V_2 -> V_471 . V_474 ,
V_2 -> V_471 . V_475 ,
V_478 ) ;
return V_477 ;
}
int F_195 ( struct V_1 * V_2 , int V_479 )
{
struct V_368 * V_369 = F_133 ( V_2 -> V_83 ) ;
int error = 0 ;
F_127 ( & V_2 -> V_34 . V_79 ) ;
error = F_196 ( V_2 , & V_2 -> V_34 . V_480 , & V_2 -> V_34 . V_80 ,
L_12 , V_479 , 1 , 1 ) ;
if ( error != 0 ) {
F_132 ( V_369 ,
L_13 , error ) ;
return error ;
}
error = F_196 ( V_2 , & V_2 -> V_360 . V_481 , & V_2 -> V_360 . V_482 ,
L_14 , V_426 , 1 , 1 ) ;
if ( error != 0 ) {
F_132 ( V_369 ,
L_15 , error ) ;
return error ;
}
F_197 ( & V_2 -> V_483 , V_484 ) ;
if ( V_2 -> V_83 -> V_84 . V_172 & V_173 )
error = F_193 ( V_2 ) ;
return error ;
}
void F_198 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_25 , V_485 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_309 ;
V_25 ++ , V_6 ++ ) {
V_6 -> V_21 = V_21 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_60 = V_6 -> V_307 = 0 ;
V_6 -> V_127 = V_486 ;
V_6 -> V_63 = V_6 -> V_66 = 0 ;
V_6 -> V_10 = false ;
V_6 -> V_9 = false ;
V_6 -> V_128 = false ;
F_65 ( & V_6 -> V_47 ) ;
F_65 ( & V_6 -> V_48 ) ;
V_485 = F_199 ( V_25 ) ;
V_6 -> V_8 = & V_21 -> V_8 [ V_485 ] ;
}
for ( V_485 = 0 , V_8 = & V_21 -> V_8 [ V_485 ] ;
V_485 < V_487 ; V_485 ++ , V_8 ++ ) {
V_8 -> V_10 = false ;
V_8 -> V_135 = true ;
V_8 -> V_4 = V_2 -> V_34 . V_36 [ V_485 ] ;
F_32 ( & V_8 -> V_12 ) ;
}
}
void F_200 ( struct V_1 * V_2 , struct V_41 * V_21 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_309 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_10 ) {
F_53 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
}
if ( V_8 -> V_10 ) {
F_53 ( & V_8 -> V_11 ) ;
V_6 -> V_8 -> V_10 = false ;
}
F_41 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_128 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
