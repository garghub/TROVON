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
V_6 -> V_9 = true ;
F_5 ( & V_6 -> V_10 , & V_8 -> V_11 ) ;
if ( V_8 -> V_9 )
return;
V_8 -> V_9 = true ;
F_5 ( & V_8 -> V_10 , & V_4 -> V_12 ) ;
}
static struct V_13 * F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
F_8 ( sizeof( struct V_13 ) >
sizeof( V_17 -> V_18 ) ) ;
return (struct V_13 * ) & V_17 -> V_18 [ 0 ] ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_19 )
{
if ( ! V_6 -> V_20 -> V_21 )
return;
F_10 ( V_6 -> V_20 -> V_22 , V_6 -> V_20 -> V_21 -> V_23 , V_6 -> V_24 ,
V_19 << V_25 ) ;
}
static void F_11 ( struct V_26 * V_22 , struct V_27 * V_21 ,
struct V_28 * V_29 )
{
F_12 ( V_22 , V_21 , V_29 -> V_30 , V_29 -> V_31 ,
F_13 ( V_29 -> V_31 ) ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 )
{
int V_32 ;
V_32 = F_15 ( V_15 ) ;
if ( V_4 == V_2 -> V_33 . V_34 )
V_4 = V_2 -> V_33 . V_35 [ V_32 ] ;
if ( V_4 != V_2 -> V_33 . V_35 [ V_32 ] )
return;
if ( F_16 ( -- V_4 -> V_36 < 0 ) )
V_4 -> V_36 = 0 ;
if ( V_4 -> V_37 &&
V_4 -> V_36 < V_2 -> V_33 . V_38 [ V_32 ] ) {
F_17 ( V_2 -> V_39 , V_32 ) ;
V_4 -> V_37 = false ;
}
}
static struct V_5 *
F_18 ( struct V_1 * V_2 , struct V_40 * V_20 , struct V_14 * V_15 )
{
T_2 V_24 = V_15 -> V_41 & V_42 ;
return F_19 ( V_20 , V_24 ) ;
}
static bool F_20 ( struct V_5 * V_6 )
{
return ! F_21 ( & V_6 -> V_43 ) || ! F_21 ( & V_6 -> V_44 ) ;
}
static struct V_14 * F_22 ( struct V_5 * V_6 )
{
struct V_14 * V_15 ;
V_15 = F_23 ( & V_6 -> V_44 ) ;
if ( ! V_15 )
V_15 = F_23 ( & V_6 -> V_43 ) ;
return V_15 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_16 * V_17 ;
struct V_14 * V_15 , * V_45 ;
struct V_28 * V_29 ;
struct V_13 * V_46 ;
F_25 (&tid->buf_q, skb, tskb) {
V_46 = F_6 ( V_15 ) ;
V_29 = V_46 -> V_29 ;
V_17 = F_7 ( V_15 ) ;
V_17 -> V_47 &= ~ V_48 ;
if ( V_29 )
continue;
V_29 = F_26 ( V_2 , V_4 , V_6 , V_15 ) ;
if ( ! V_29 ) {
F_27 ( V_15 , & V_6 -> V_43 ) ;
F_14 ( V_2 , V_4 , V_15 ) ;
F_28 ( V_2 -> V_39 , V_15 ) ;
continue;
}
}
}
static void F_29 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_14 * V_15 ;
struct V_28 * V_29 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
struct V_13 * V_46 ;
bool V_53 = false ;
F_30 ( & V_50 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
while ( ( V_15 = F_23 ( & V_6 -> V_44 ) ) ) {
V_46 = F_6 ( V_15 ) ;
V_29 = V_46 -> V_29 ;
if ( ! V_29 ) {
F_14 ( V_2 , V_4 , V_15 ) ;
F_28 ( V_2 -> V_39 , V_15 ) ;
continue;
}
if ( V_46 -> V_54 ) {
F_31 ( V_2 , V_6 , V_29 -> V_55 . V_19 ) ;
V_53 = true ;
}
F_5 ( & V_29 -> V_10 , & V_50 ) ;
F_32 ( V_2 , V_29 , V_4 , & V_50 , & V_52 , 0 ) ;
}
if ( V_53 ) {
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , V_6 -> V_56 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_19 )
{
int V_57 , V_58 ;
V_57 = F_33 ( V_6 -> V_56 , V_19 ) ;
V_58 = ( V_6 -> V_59 + V_57 ) & ( V_60 - 1 ) ;
F_34 ( V_58 , V_6 -> V_61 ) ;
while ( V_6 -> V_59 != V_6 -> V_62 && ! F_35 ( V_6 -> V_59 , V_6 -> V_61 ) ) {
F_36 ( V_6 -> V_56 , V_63 ) ;
F_36 ( V_6 -> V_59 , V_60 ) ;
if ( V_6 -> V_64 >= 0 )
V_6 -> V_64 -- ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_13 * V_46 = F_6 ( V_29 -> V_30 ) ;
T_1 V_19 = V_29 -> V_55 . V_19 ;
int V_57 , V_58 ;
V_57 = F_33 ( V_6 -> V_56 , V_19 ) ;
V_58 = ( V_6 -> V_59 + V_57 ) & ( V_60 - 1 ) ;
F_38 ( V_58 , V_6 -> V_61 ) ;
V_46 -> V_54 = 1 ;
if ( V_57 >= ( ( V_6 -> V_62 - V_6 -> V_59 ) &
( V_60 - 1 ) ) ) {
V_6 -> V_62 = V_58 ;
F_36 ( V_6 -> V_62 , V_60 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_14 * V_15 ;
struct V_28 * V_29 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
struct V_13 * V_46 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
F_30 ( & V_50 ) ;
while ( ( V_15 = F_22 ( V_6 ) ) ) {
V_46 = F_6 ( V_15 ) ;
V_29 = V_46 -> V_29 ;
if ( ! V_29 ) {
F_40 ( V_2 , V_15 , V_65 , V_4 ) ;
continue;
}
F_5 ( & V_29 -> V_10 , & V_50 ) ;
F_32 ( V_2 , V_29 , V_4 , & V_50 , & V_52 , 0 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , int V_66 )
{
struct V_13 * V_46 = F_6 ( V_15 ) ;
struct V_28 * V_29 = V_46 -> V_29 ;
struct V_67 * V_68 ;
int V_69 = V_46 -> V_70 ;
F_42 ( V_4 -> V_71 , V_72 ) ;
V_46 -> V_70 += V_66 ;
if ( V_69 > 0 )
return;
V_68 = (struct V_67 * ) V_15 -> V_73 ;
V_68 -> V_74 |= F_43 ( V_75 ) ;
F_44 ( V_2 -> V_76 , V_29 -> V_77 ,
sizeof( * V_68 ) , V_78 ) ;
}
static struct V_28 * F_45 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = NULL ;
F_46 ( & V_2 -> V_33 . V_79 ) ;
if ( F_47 ( F_48 ( & V_2 -> V_33 . V_80 ) ) ) {
F_49 ( & V_2 -> V_33 . V_79 ) ;
return NULL ;
}
V_29 = F_50 ( & V_2 -> V_33 . V_80 , struct V_28 , V_10 ) ;
F_51 ( & V_29 -> V_10 ) ;
F_49 ( & V_2 -> V_33 . V_79 ) ;
return V_29 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
F_46 ( & V_2 -> V_33 . V_79 ) ;
F_5 ( & V_29 -> V_10 , & V_2 -> V_33 . V_80 ) ;
F_49 ( & V_2 -> V_33 . V_79 ) ;
}
static struct V_28 * F_53 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_28 * V_81 ;
V_81 = F_45 ( V_2 ) ;
if ( F_16 ( ! V_81 ) )
return NULL ;
F_54 ( V_81 ) ;
V_81 -> V_30 = V_29 -> V_30 ;
V_81 -> V_77 = V_29 -> V_77 ;
memcpy ( V_81 -> V_82 , V_29 -> V_82 , V_2 -> V_83 -> V_84 . V_85 ) ;
V_81 -> V_55 = V_29 -> V_55 ;
V_81 -> V_55 . V_86 = false ;
return V_81 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_51 * V_52 , int V_87 ,
int * V_88 , int * V_89 )
{
struct V_13 * V_46 ;
T_1 V_90 = 0 ;
V_91 V_92 [ V_93 >> 5 ] ;
int V_94 ;
int V_95 = 0 ;
* V_89 = 0 ;
* V_88 = 0 ;
V_95 = F_56 ( V_29 ) ;
if ( V_95 ) {
V_90 = V_52 -> V_96 ;
memcpy ( V_92 , & V_52 -> V_97 , V_93 >> 3 ) ;
}
while ( V_29 ) {
V_46 = F_6 ( V_29 -> V_30 ) ;
V_94 = F_33 ( V_90 , V_29 -> V_55 . V_19 ) ;
( * V_88 ) ++ ;
if ( ! V_87 || ( V_95 && ! F_57 ( V_92 , V_94 ) ) )
( * V_89 ) ++ ;
V_29 = V_29 -> V_98 ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_28 * V_29 , struct V_49 * V_99 ,
struct V_51 * V_52 , int V_87 )
{
struct V_40 * V_20 = NULL ;
struct V_14 * V_15 ;
struct V_27 * V_21 ;
struct V_100 * V_39 = V_2 -> V_39 ;
struct V_67 * V_68 ;
struct V_16 * V_17 ;
struct V_5 * V_6 = NULL ;
struct V_28 * V_98 , * V_101 = V_29 -> V_102 ;
struct V_49 V_50 ;
struct V_103 V_104 ;
T_1 V_90 = 0 , V_105 = 0 , V_106 = 0 , V_107 ;
V_91 V_92 [ V_93 >> 5 ] ;
int V_95 , V_108 , V_109 , V_53 = 0 , V_110 = 0 , V_89 = 0 ;
bool V_111 = true , V_112 ;
struct V_113 V_31 [ 4 ] ;
struct V_13 * V_46 ;
int V_88 ;
bool V_114 = ! ! ( V_52 -> V_115 & V_116 ) ;
int V_117 , V_70 ;
int V_64 = - 1 ;
V_15 = V_29 -> V_30 ;
V_68 = (struct V_67 * ) V_15 -> V_73 ;
V_17 = F_7 ( V_15 ) ;
memcpy ( V_31 , V_29 -> V_31 , sizeof( V_31 ) ) ;
V_70 = V_52 -> V_118 + 1 ;
for ( V_117 = 0 ; V_117 < V_52 -> V_119 ; V_117 ++ )
V_70 += V_31 [ V_117 ] . V_66 ;
F_59 () ;
V_21 = F_60 ( V_39 , V_68 -> V_120 , V_68 -> V_121 ) ;
if ( ! V_21 ) {
F_61 () ;
F_30 ( & V_50 ) ;
while ( V_29 ) {
V_98 = V_29 -> V_98 ;
if ( ! V_29 -> V_55 . V_86 || V_98 != NULL )
F_62 ( & V_29 -> V_10 , & V_50 ) ;
F_32 ( V_2 , V_29 , V_4 , & V_50 , V_52 , 0 ) ;
V_29 = V_98 ;
}
return;
}
V_20 = (struct V_40 * ) V_21 -> V_122 ;
V_6 = F_18 ( V_2 , V_20 , V_15 ) ;
V_107 = V_6 -> V_56 ;
V_112 = V_52 -> V_123 & V_124 ;
if ( V_112 && V_6 -> V_24 != V_52 -> V_6 )
V_87 = false ;
V_95 = F_56 ( V_29 ) ;
memset ( V_92 , 0 , V_93 >> 3 ) ;
if ( V_95 && V_87 ) {
if ( V_52 -> V_123 & V_124 ) {
V_90 = V_52 -> V_96 ;
memcpy ( V_92 , & V_52 -> V_97 , V_93 >> 3 ) ;
} else {
if ( V_2 -> V_83 -> V_125 == V_126 )
V_110 = 1 ;
}
}
F_63 ( & V_104 ) ;
F_55 ( V_2 , V_29 , V_52 , V_87 , & V_88 , & V_89 ) ;
while ( V_29 ) {
T_1 V_19 = V_29 -> V_55 . V_19 ;
V_108 = V_109 = V_53 = 0 ;
V_98 = V_29 -> V_98 ;
V_15 = V_29 -> V_30 ;
V_17 = F_7 ( V_15 ) ;
V_46 = F_6 ( V_15 ) ;
if ( ! F_64 ( V_6 -> V_56 , V_6 -> V_127 , V_19 ) ||
! V_6 -> V_128 ) {
V_108 = 1 ;
} else if ( F_57 ( V_92 , F_33 ( V_90 , V_19 ) ) ) {
V_105 ++ ;
} else if ( ! V_95 && V_87 ) {
V_105 ++ ;
} else if ( V_114 ) {
V_109 = 1 ;
} else if ( V_46 -> V_70 < V_129 ) {
if ( V_87 || ! V_20 -> V_130 )
F_41 ( V_2 , V_4 , V_29 -> V_30 ,
V_70 ) ;
V_109 = 1 ;
} else {
V_108 = 1 ;
V_106 ++ ;
V_64 = F_65 ( int , V_64 ,
F_33 ( V_107 , V_19 ) ) ;
}
F_30 ( & V_50 ) ;
if ( V_98 != NULL || ! V_101 -> V_55 . V_86 )
F_62 ( & V_29 -> V_10 , & V_50 ) ;
if ( ! V_109 ) {
F_31 ( V_2 , V_6 , V_19 ) ;
if ( V_111 && ( V_105 == 1 || V_106 == 1 ) ) {
memcpy ( V_17 -> V_131 . V_31 , V_31 , sizeof( V_31 ) ) ;
F_66 ( V_2 , V_29 , V_52 , V_88 , V_89 , V_87 ) ;
V_111 = false ;
}
F_32 ( V_2 , V_29 , V_4 , & V_50 , V_52 ,
! V_108 ) ;
} else {
if ( V_17 -> V_47 & V_132 ) {
V_17 -> V_47 &= ~ V_132 ;
F_67 ( V_21 ) ;
}
if ( V_29 -> V_98 == NULL && V_101 -> V_55 . V_86 ) {
struct V_28 * V_81 ;
V_81 = F_53 ( V_2 , V_101 ) ;
if ( ! V_81 ) {
F_31 ( V_2 , V_6 , V_19 ) ;
F_32 ( V_2 , V_29 , V_4 ,
& V_50 , V_52 , 0 ) ;
V_64 = F_65 ( int , V_64 ,
F_33 ( V_107 , V_19 ) ) ;
break;
}
V_46 -> V_29 = V_81 ;
}
F_68 ( & V_104 , V_15 ) ;
}
V_29 = V_98 ;
}
if ( ! F_21 ( & V_104 ) ) {
if ( V_20 -> V_130 )
F_69 ( V_21 , V_6 -> V_24 , true ) ;
F_70 ( & V_104 , & V_6 -> V_44 ) ;
if ( ! V_20 -> V_130 ) {
F_4 ( V_4 , V_6 ) ;
if ( V_52 -> V_115 & ( V_133 | V_134 ) )
V_6 -> V_8 -> V_135 = true ;
}
}
if ( V_64 >= 0 ) {
T_1 V_136 = F_71 ( V_107 , V_64 ) ;
if ( F_64 ( V_6 -> V_56 , V_6 -> V_127 , V_136 ) )
V_6 -> V_64 = F_33 ( V_6 -> V_56 , V_136 ) ;
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , F_71 ( V_107 , V_64 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_61 () ;
if ( V_110 )
F_72 ( V_2 , V_137 ) ;
}
static bool F_73 ( struct V_28 * V_29 )
{
struct V_16 * V_138 = F_7 ( V_29 -> V_30 ) ;
return F_74 ( V_29 ) && ! ( V_138 -> V_47 & V_139 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_51 * V_52 , struct V_28 * V_29 ,
struct V_49 * V_50 )
{
struct V_16 * V_138 ;
bool V_87 , V_114 ;
V_87 = ! ( V_52 -> V_115 & V_140 ) ;
V_114 = ! ! ( V_52 -> V_115 & V_116 ) ;
V_4 -> V_141 = false ;
V_4 -> V_142 -- ;
if ( F_73 ( V_29 ) )
V_4 -> V_143 -- ;
if ( ! F_74 ( V_29 ) ) {
if ( ! V_114 ) {
V_138 = F_7 ( V_29 -> V_30 ) ;
memcpy ( V_138 -> V_131 . V_31 , V_29 -> V_31 ,
sizeof( V_138 -> V_131 . V_31 ) ) ;
F_66 ( V_2 , V_29 , V_52 , 1 , V_87 ? 0 : 1 , V_87 ) ;
}
F_32 ( V_2 , V_29 , V_4 , V_50 , V_52 , V_87 ) ;
} else
F_58 ( V_2 , V_4 , V_29 , V_50 , V_52 , V_87 ) ;
if ( ! V_114 )
F_76 ( V_2 , V_4 ) ;
}
static bool F_77 ( struct V_28 * V_29 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_113 * V_31 ;
int V_117 ;
V_15 = V_29 -> V_30 ;
V_17 = F_7 ( V_15 ) ;
V_31 = V_17 -> V_131 . V_31 ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
if ( ! V_31 [ V_117 ] . V_66 || V_31 [ V_117 ] . V_144 < 0 )
break;
if ( ! ( V_31 [ V_117 ] . V_47 & V_145 ) )
return true ;
}
return false ;
}
static V_91 F_78 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_5 * V_6 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_113 * V_31 ;
V_91 V_146 , V_147 ;
T_1 V_148 , V_149 , V_150 = 0 ;
int V_32 = V_6 -> V_8 -> V_4 -> V_151 ;
int V_117 ;
V_15 = V_29 -> V_30 ;
V_17 = F_7 ( V_15 ) ;
V_31 = V_29 -> V_31 ;
V_146 = V_152 ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
int V_153 ;
if ( ! V_31 [ V_117 ] . V_66 )
continue;
if ( ! ( V_31 [ V_117 ] . V_47 & V_145 ) ) {
V_150 = 1 ;
break;
}
if ( V_31 [ V_117 ] . V_47 & V_154 )
V_153 = V_155 ;
else
V_153 = V_156 ;
if ( V_31 [ V_117 ] . V_47 & V_157 )
V_153 ++ ;
V_147 = V_2 -> V_33 . V_158 [ V_32 ] [ V_153 ] [ V_31 [ V_117 ] . V_144 ] ;
V_146 = F_79 ( V_146 , V_147 ) ;
}
if ( V_17 -> V_47 & V_139 || V_150 )
return 0 ;
V_148 = F_79 ( V_146 , ( V_91 ) V_152 ) ;
V_149 = F_80 ( V_2 , V_146 ) ;
if ( V_149 )
V_148 = V_149 ;
if ( V_6 -> V_20 -> V_159 )
V_148 = F_79 ( V_148 , V_6 -> V_20 -> V_159 ) ;
return V_148 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_28 * V_29 , T_1 V_147 ,
bool V_160 )
{
#define F_82 60
V_91 V_161 , V_162 ;
T_1 V_163 ;
T_2 V_47 , V_164 ;
int V_165 , V_166 , V_167 , V_168 , V_169 ;
struct V_13 * V_46 = F_6 ( V_29 -> V_30 ) ;
V_168 = F_83 ( V_147 ) ;
if ( ( V_46 -> V_170 != V_171 ) &&
! ( V_2 -> V_83 -> V_84 . V_172 & V_173 ) )
V_168 += V_174 ;
if ( V_160 && ! F_84 ( V_2 -> V_83 ) &&
( V_2 -> V_83 -> V_175 & V_176 ) )
V_168 = F_85 ( V_168 , F_82 ) ;
if ( V_6 -> V_20 -> V_177 == 0 )
return V_168 ;
V_164 = V_29 -> V_31 [ 0 ] . V_144 ;
V_47 = V_29 -> V_31 [ 0 ] . V_47 ;
V_165 = ( V_47 & V_154 ) ? 1 : 0 ;
V_167 = ( V_47 & V_157 ) ? 1 : 0 ;
if ( V_167 )
V_162 = F_86 ( V_6 -> V_20 -> V_177 ) ;
else
V_162 = F_87 ( V_6 -> V_20 -> V_177 ) ;
if ( V_162 == 0 )
V_162 = 1 ;
V_166 = F_88 ( V_164 ) ;
V_161 = V_178 [ V_164 % 8 ] [ V_165 ] * V_166 ;
V_163 = ( V_162 * V_161 ) / V_179 ;
if ( V_147 < V_163 ) {
V_169 = ( V_163 - V_147 ) / V_180 ;
V_168 = F_85 ( V_169 , V_168 ) ;
}
return V_168 ;
}
static struct V_28 *
F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_103 * * V_32 )
{
struct V_16 * V_17 ;
struct V_13 * V_46 ;
struct V_14 * V_15 ;
struct V_28 * V_29 ;
T_1 V_19 ;
while ( 1 ) {
* V_32 = & V_6 -> V_44 ;
if ( F_21 ( * V_32 ) )
* V_32 = & V_6 -> V_43 ;
V_15 = F_90 ( * V_32 ) ;
if ( ! V_15 )
break;
V_46 = F_6 ( V_15 ) ;
V_29 = V_46 -> V_29 ;
if ( ! V_46 -> V_29 )
V_29 = F_26 ( V_2 , V_4 , V_6 , V_15 ) ;
else
V_29 -> V_55 . V_86 = false ;
if ( ! V_29 ) {
F_27 ( V_15 , * V_32 ) ;
F_14 ( V_2 , V_4 , V_15 ) ;
F_28 ( V_2 -> V_39 , V_15 ) ;
continue;
}
V_29 -> V_98 = NULL ;
V_29 -> V_102 = V_29 ;
V_17 = F_7 ( V_15 ) ;
V_17 -> V_47 &= ~ V_181 ;
if ( ! ( V_17 -> V_47 & V_48 ) ) {
V_29 -> V_55 . V_182 = 0 ;
return V_29 ;
}
V_29 -> V_55 . V_182 = V_183 | V_184 ;
V_19 = V_29 -> V_55 . V_19 ;
if ( ! F_64 ( V_6 -> V_56 , V_6 -> V_127 , V_19 ) )
break;
if ( V_6 -> V_64 > F_33 ( V_6 -> V_56 , V_19 ) ) {
struct V_51 V_52 = {} ;
struct V_49 V_50 ;
F_30 ( & V_50 ) ;
F_91 ( & V_29 -> V_10 , & V_50 ) ;
F_27 ( V_15 , * V_32 ) ;
F_31 ( V_2 , V_6 , V_19 ) ;
F_32 ( V_2 , V_29 , V_4 , & V_50 , & V_52 , 0 ) ;
continue;
}
return V_29 ;
}
return NULL ;
}
static bool
F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_49 * V_99 ,
struct V_28 * V_185 , struct V_103 * V_11 ,
int * V_186 )
{
#define F_93 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_28 * V_29 = V_185 , * V_187 = NULL ;
int V_88 = 0 , V_168 ;
T_1 V_148 = 0 , V_188 = 0 , V_189 = 0 ,
V_190 , V_191 = V_6 -> V_127 / 2 ;
struct V_16 * V_17 ;
struct V_13 * V_46 ;
struct V_14 * V_15 ;
bool V_192 = false ;
V_29 = V_185 ;
V_148 = F_78 ( V_2 , V_29 , V_6 ) ;
do {
V_15 = V_29 -> V_30 ;
V_46 = F_6 ( V_15 ) ;
V_190 = V_180 + V_46 -> V_193 ;
if ( V_88 ) {
if ( V_148 < V_188 + V_189 + V_190 ||
F_77 ( V_29 ) || V_88 >= V_191 )
break;
V_17 = F_7 ( V_29 -> V_30 ) ;
if ( ( V_17 -> V_47 & V_139 ) ||
! ( V_17 -> V_47 & V_48 ) )
break;
}
V_188 += V_189 + V_190 ;
V_168 = F_81 ( V_2 , V_6 , V_185 , V_46 -> V_193 ,
! V_88 ) ;
V_189 = F_93 ( V_190 ) + ( V_168 << 2 ) ;
V_88 ++ ;
V_29 -> V_98 = NULL ;
if ( ! V_46 -> V_54 )
F_37 ( V_2 , V_6 , V_29 ) ;
V_29 -> V_55 . V_168 = V_168 ;
F_27 ( V_15 , V_11 ) ;
F_5 ( & V_29 -> V_10 , V_99 ) ;
if ( V_187 )
V_187 -> V_98 = V_29 ;
V_187 = V_29 ;
V_29 = F_89 ( V_2 , V_4 , V_6 , & V_11 ) ;
if ( ! V_29 ) {
V_192 = true ;
break;
}
} while ( F_20 ( V_6 ) );
V_29 = V_185 ;
V_29 -> V_102 = V_187 ;
if ( V_29 == V_187 ) {
V_188 = F_6 ( V_29 -> V_30 ) -> V_193 ;
V_29 -> V_55 . V_182 = V_183 ;
} else {
F_42 ( V_4 -> V_71 , V_194 ) ;
}
* V_186 = V_188 ;
return V_192 ;
#undef F_93
}
static V_91 F_94 ( struct V_1 * V_2 , T_2 V_164 , int V_195 ,
int V_165 , int V_167 , bool V_196 )
{
V_91 V_197 , V_161 , V_198 , V_162 ;
int V_166 ;
V_166 = F_88 ( V_164 ) ;
V_197 = ( V_195 << 3 ) + V_199 ;
V_161 = V_178 [ V_164 % 8 ] [ V_165 ] * V_166 ;
V_162 = ( V_197 + V_161 - 1 ) / V_161 ;
if ( ! V_167 )
V_198 = F_95 ( V_162 ) ;
else
V_198 = F_96 ( V_162 ) ;
V_198 += V_200 + V_201 + V_202 + V_203 + V_204 + F_97 ( V_166 ) ;
return V_198 ;
}
static int F_98 ( int V_205 , int V_206 , bool V_207 , bool V_208 )
{
int V_166 = F_88 ( V_206 ) ;
int V_209 , V_210 ;
int V_211 = 0 ;
V_205 -= V_200 + V_201 + V_202 + V_203 + V_204 + F_97 ( V_166 ) ;
V_209 = V_208 ? F_99 ( V_205 ) : F_100 ( V_205 ) ;
V_210 = V_209 * V_178 [ V_206 % 8 ] [ V_207 ] * V_166 ;
V_210 -= V_199 ;
V_211 = V_210 / 8 ;
if ( V_211 > 65532 )
V_211 = 65532 ;
return V_211 ;
}
void F_101 ( struct V_1 * V_2 , int V_212 , int V_213 )
{
T_1 * V_214 , * V_215 , * V_216 , * V_217 ;
int V_206 ;
if ( ! V_213 || V_213 > 4096 )
V_213 = 4096 ;
V_214 = V_2 -> V_33 . V_158 [ V_212 ] [ V_156 ] ;
V_215 = V_2 -> V_33 . V_158 [ V_212 ] [ V_218 ] ;
V_216 = V_2 -> V_33 . V_158 [ V_212 ] [ V_155 ] ;
V_217 = V_2 -> V_33 . V_158 [ V_212 ] [ V_219 ] ;
for ( V_206 = 0 ; V_206 < 32 ; V_206 ++ ) {
V_214 [ V_206 ] = F_98 ( V_213 , V_206 , false , false ) ;
V_215 [ V_206 ] = F_98 ( V_213 , V_206 , false , true ) ;
V_216 [ V_206 ] = F_98 ( V_213 , V_206 , true , false ) ;
V_217 [ V_206 ] = F_98 ( V_213 , V_206 , true , true ) ;
}
}
static void F_102 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_220 * V_138 , int V_221 , bool V_222 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_225 * V_226 = F_103 ( V_224 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_113 * V_31 ;
const struct V_227 * V_228 ;
struct V_67 * V_68 ;
struct V_13 * V_46 = F_6 ( V_29 -> V_30 ) ;
V_91 V_229 = V_2 -> V_39 -> V_230 -> V_231 ;
int V_117 ;
T_2 V_164 = 0 ;
V_15 = V_29 -> V_30 ;
V_17 = F_7 ( V_15 ) ;
V_31 = V_29 -> V_31 ;
V_68 = (struct V_67 * ) V_15 -> V_73 ;
V_138 -> V_232 = ! F_104 ( V_68 -> V_74 ) ;
V_138 -> V_233 = V_46 -> V_233 ;
for ( V_117 = 0 ; V_117 < F_13 ( V_29 -> V_31 ) ; V_117 ++ ) {
bool V_234 , V_235 , V_236 ;
int V_237 ;
if ( ! V_31 [ V_117 ] . V_66 || ( V_31 [ V_117 ] . V_144 < 0 ) )
continue;
V_164 = V_31 [ V_117 ] . V_144 ;
V_138 -> V_31 [ V_117 ] . V_238 = V_31 [ V_117 ] . V_66 ;
if ( F_74 ( V_29 ) && ! F_56 ( V_29 ) &&
( V_31 [ V_117 ] . V_47 & V_145 ) &&
F_47 ( V_229 != ( V_91 ) - 1 ) ) {
if ( ! V_229 || ( V_221 > V_229 ) )
V_222 = true ;
}
if ( V_222 || V_31 [ V_117 ] . V_47 & V_239 ) {
V_138 -> V_31 [ V_117 ] . V_240 |= V_241 ;
V_138 -> V_47 |= V_242 ;
} else if ( V_31 [ V_117 ] . V_47 & V_243 ) {
V_138 -> V_31 [ V_117 ] . V_240 |= V_241 ;
V_138 -> V_47 |= V_244 ;
}
if ( V_31 [ V_117 ] . V_47 & V_154 )
V_138 -> V_31 [ V_117 ] . V_240 |= V_245 ;
if ( V_31 [ V_117 ] . V_47 & V_157 )
V_138 -> V_31 [ V_117 ] . V_240 |= V_246 ;
V_235 = ! ! ( V_31 [ V_117 ] . V_47 & V_157 ) ;
V_234 = ! ! ( V_31 [ V_117 ] . V_47 & V_154 ) ;
V_236 = ! ! ( V_31 [ V_117 ] . V_47 & V_247 ) ;
if ( V_31 [ V_117 ] . V_47 & V_145 ) {
V_138 -> V_31 [ V_117 ] . V_248 = V_164 | 0x80 ;
V_138 -> V_31 [ V_117 ] . V_249 = F_105 ( V_2 ,
V_224 -> V_250 , V_138 -> V_31 [ V_117 ] . V_248 ) ;
V_138 -> V_31 [ V_117 ] . V_251 = F_94 ( V_2 , V_164 , V_221 ,
V_234 , V_235 , V_236 ) ;
if ( V_164 < 8 && ( V_17 -> V_47 & V_252 ) )
V_138 -> V_31 [ V_117 ] . V_240 |= V_253 ;
continue;
}
V_228 = & V_226 -> V_254 [ V_17 -> V_255 ] . V_256 [ V_31 [ V_117 ] . V_144 ] ;
if ( ( V_17 -> V_255 == V_257 ) &&
! ( V_228 -> V_47 & V_258 ) )
V_237 = V_259 ;
else
V_237 = V_260 ;
V_138 -> V_31 [ V_117 ] . V_248 = V_228 -> V_261 ;
if ( V_228 -> V_262 ) {
if ( V_31 [ V_117 ] . V_47 & V_247 )
V_138 -> V_31 [ V_117 ] . V_248 |= V_228 -> V_262 ;
} else {
V_236 = false ;
}
if ( V_29 -> V_55 . V_263 )
V_138 -> V_31 [ V_117 ] . V_249 = V_224 -> V_250 ;
else
V_138 -> V_31 [ V_117 ] . V_249 = F_105 ( V_2 ,
V_224 -> V_250 , V_138 -> V_31 [ V_117 ] . V_248 ) ;
V_138 -> V_31 [ V_117 ] . V_251 = F_106 ( V_2 -> V_83 ,
V_237 , V_228 -> V_264 * 100 , V_221 , V_164 , V_236 ) ;
}
if ( F_56 ( V_29 ) && ( V_221 > V_2 -> V_83 -> V_84 . V_265 ) )
V_138 -> V_47 &= ~ V_242 ;
if ( V_138 -> V_47 & V_242 )
V_138 -> V_47 &= ~ V_244 ;
}
static enum V_266 F_107 ( struct V_14 * V_15 )
{
struct V_67 * V_68 ;
enum V_266 V_267 ;
T_4 V_268 ;
V_68 = (struct V_67 * ) V_15 -> V_73 ;
V_268 = V_68 -> V_74 ;
if ( F_108 ( V_268 ) )
V_267 = V_269 ;
else if ( F_109 ( V_268 ) )
V_267 = V_270 ;
else if ( F_110 ( V_268 ) )
V_267 = V_271 ;
else if ( F_104 ( V_268 ) )
V_267 = V_272 ;
else
V_267 = V_273 ;
return V_267 ;
}
static void F_111 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_3 * V_4 , int V_221 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_28 * V_185 = NULL ;
struct V_220 V_138 ;
V_91 V_229 = V_2 -> V_39 -> V_230 -> V_231 ;
bool V_222 = false ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_274 = true ;
V_138 . V_275 = true ;
V_138 . V_276 = V_277 ;
V_138 . V_278 = V_4 -> V_71 ;
while ( V_29 ) {
struct V_14 * V_15 = V_29 -> V_30 ;
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_13 * V_46 = F_6 ( V_15 ) ;
bool V_279 = ! ! ( V_29 -> V_55 . V_182 & V_184 ) ;
V_138 . type = F_107 ( V_15 ) ;
if ( V_29 -> V_98 )
V_138 . V_280 = V_29 -> V_98 -> V_281 ;
else
V_138 . V_280 = ( V_2 -> V_282 ) ? V_29 -> V_281 : 0 ;
if ( ! V_185 ) {
V_185 = V_29 ;
if ( ! V_2 -> V_282 )
V_138 . V_47 = V_283 ;
if ( ( V_17 -> V_47 & V_181 ) ||
V_4 == V_2 -> V_33 . V_34 )
V_138 . V_47 |= V_284 ;
if ( V_17 -> V_47 & V_285 )
V_138 . V_47 |= V_286 ;
if ( V_17 -> V_47 & V_287 )
V_138 . V_47 |= V_288 ;
if ( V_29 -> V_55 . V_263 )
V_138 . V_47 |= ( V_91 ) V_29 -> V_55 . V_263 <<
V_289 ;
if ( V_279 && ( V_29 == V_185 ) &&
F_47 ( V_229 != ( V_91 ) - 1 ) ) {
if ( ! V_229 || ( V_221 > V_229 ) )
V_222 = true ;
}
if ( ! V_279 )
V_221 = V_46 -> V_193 ;
F_102 ( V_2 , V_29 , & V_138 , V_221 , V_222 ) ;
}
V_138 . V_290 [ 0 ] = V_29 -> V_77 ;
V_138 . V_291 [ 0 ] = V_15 -> V_221 ;
V_138 . V_292 = V_46 -> V_193 ;
V_138 . V_170 = V_46 -> V_170 ;
V_138 . V_293 = V_46 -> V_293 ;
if ( V_279 ) {
if ( V_29 == V_185 )
V_138 . V_279 = V_294 ;
else if ( V_29 == V_185 -> V_102 )
V_138 . V_279 = V_295 ;
else
V_138 . V_279 = V_296 ;
V_138 . V_168 = V_29 -> V_55 . V_168 ;
V_138 . V_186 = V_221 ;
}
if ( V_29 == V_185 -> V_102 )
V_185 = NULL ;
F_112 ( V_224 , V_29 -> V_82 , & V_138 ) ;
V_29 = V_29 -> V_98 ;
}
}
static void
F_113 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_49 * V_99 ,
struct V_28 * V_185 , struct V_103 * V_11 )
{
struct V_28 * V_29 = V_185 , * V_187 = NULL ;
struct V_14 * V_15 ;
int V_88 = 0 ;
do {
struct V_16 * V_17 ;
V_15 = V_29 -> V_30 ;
V_88 ++ ;
F_27 ( V_15 , V_11 ) ;
F_5 ( & V_29 -> V_10 , V_99 ) ;
if ( V_187 )
V_187 -> V_98 = V_29 ;
V_187 = V_29 ;
if ( V_88 >= 2 )
break;
V_29 = F_89 ( V_2 , V_4 , V_6 , & V_11 ) ;
if ( ! V_29 )
break;
V_17 = F_7 ( V_29 -> V_30 ) ;
if ( V_17 -> V_47 & V_48 )
break;
F_11 ( V_6 -> V_20 -> V_22 , V_6 -> V_20 -> V_21 , V_29 ) ;
} while ( 1 );
}
static bool F_114 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_297 )
{
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_103 * V_11 ;
struct V_49 V_99 ;
int V_186 = 0 ;
bool V_279 , V_298 = true ;
if ( ! F_20 ( V_6 ) )
return false ;
F_30 ( & V_99 ) ;
V_29 = F_89 ( V_2 , V_4 , V_6 , & V_11 ) ;
if ( ! V_29 )
return false ;
V_17 = F_7 ( V_29 -> V_30 ) ;
V_279 = ! ! ( V_17 -> V_47 & V_48 ) ;
if ( ( V_279 && V_4 -> V_143 >= V_299 ) ||
( ! V_279 && V_4 -> V_142 >= V_300 ) ) {
* V_297 = true ;
return false ;
}
F_11 ( V_6 -> V_20 -> V_22 , V_6 -> V_20 -> V_21 , V_29 ) ;
if ( V_279 )
V_298 = F_92 ( V_2 , V_4 , V_6 , & V_99 , V_29 ,
V_11 , & V_186 ) ;
else
F_113 ( V_2 , V_4 , V_6 , & V_99 , V_29 , V_11 ) ;
if ( F_48 ( & V_99 ) )
return false ;
if ( V_6 -> V_8 -> V_135 || V_6 -> V_20 -> V_301 ) {
V_6 -> V_8 -> V_135 = false ;
V_17 -> V_47 |= V_181 ;
}
F_111 ( V_2 , V_29 , V_4 , V_186 ) ;
F_115 ( V_2 , V_4 , & V_99 , false ) ;
return true ;
}
int F_116 ( struct V_1 * V_2 , struct V_27 * V_21 ,
T_1 V_6 , T_1 * V_302 )
{
struct V_5 * V_303 ;
struct V_3 * V_4 ;
struct V_40 * V_20 ;
T_2 V_304 ;
V_20 = (struct V_40 * ) V_21 -> V_122 ;
V_303 = F_19 ( V_20 , V_6 ) ;
V_4 = V_303 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_21 -> V_305 . V_306 ) {
V_20 -> V_159 = ( 1 << ( V_307 +
V_21 -> V_305 . V_308 ) ) - 1 ;
V_304 = F_117 ( V_21 -> V_305 . V_309 ) ;
V_20 -> V_177 = V_304 ;
}
F_24 ( V_2 , V_303 ) ;
V_303 -> V_128 = true ;
* V_302 = V_303 -> V_56 = V_303 -> V_310 ;
V_303 -> V_64 = - 1 ;
memset ( V_303 -> V_61 , 0 , sizeof( V_303 -> V_61 ) ) ;
V_303 -> V_59 = V_303 -> V_62 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 , struct V_27 * V_21 , T_1 V_6 )
{
struct V_40 * V_20 = (struct V_40 * ) V_21 -> V_122 ;
struct V_5 * V_303 = F_19 ( V_20 , V_6 ) ;
struct V_3 * V_4 = V_303 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_303 -> V_128 = false ;
F_29 ( V_2 , V_303 ) ;
F_24 ( V_2 , V_303 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_119 ( struct V_27 * V_21 , struct V_1 * V_2 ,
struct V_40 * V_20 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_311 ;
int V_24 ;
for ( V_24 = 0 , V_6 = & V_20 -> V_6 [ V_24 ] ;
V_24 < V_312 ; V_24 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_9 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_311 = F_20 ( V_6 ) ;
V_6 -> V_9 = false ;
F_51 ( & V_6 -> V_10 ) ;
if ( V_8 -> V_9 ) {
V_8 -> V_9 = false ;
F_51 ( & V_8 -> V_10 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_69 ( V_21 , V_24 , V_311 ) ;
}
}
void F_120 ( struct V_1 * V_2 , struct V_40 * V_20 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_24 ;
for ( V_24 = 0 , V_6 = & V_20 -> V_6 [ V_24 ] ;
V_24 < V_312 ; V_24 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_135 = true ;
if ( F_20 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_121 ( struct V_1 * V_2 , struct V_27 * V_21 ,
T_1 V_24 )
{
struct V_5 * V_6 ;
struct V_40 * V_20 ;
struct V_3 * V_4 ;
V_20 = (struct V_40 * ) V_21 -> V_122 ;
V_6 = F_19 ( V_20 , V_24 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_127 = V_313 << V_21 -> V_305 . V_308 ;
if ( F_20 ( V_6 ) ) {
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_122 ( struct V_100 * V_39 ,
struct V_27 * V_21 ,
T_1 V_314 , int V_88 ,
enum V_315 V_316 ,
bool V_317 )
{
struct V_1 * V_2 = V_39 -> V_318 ;
struct V_40 * V_20 = (struct V_40 * ) V_21 -> V_122 ;
struct V_3 * V_4 = V_2 -> V_33 . V_34 ;
struct V_16 * V_138 ;
struct V_49 V_99 ;
struct V_28 * V_319 = NULL , * V_29 ;
struct V_103 * V_11 ;
int V_320 = 0 ;
int V_117 ;
F_30 ( & V_99 ) ;
for ( V_117 = 0 ; V_314 && V_88 ; V_117 ++ , V_314 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_314 & 1 ) )
continue;
V_6 = F_19 ( V_20 , V_117 ) ;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_88 > 0 ) {
V_29 = F_89 ( V_2 , V_2 -> V_33 . V_34 , V_6 , & V_11 ) ;
if ( ! V_29 )
break;
F_27 ( V_29 -> V_30 , V_11 ) ;
F_5 ( & V_29 -> V_10 , & V_99 ) ;
F_11 ( V_6 -> V_20 -> V_22 , V_6 -> V_20 -> V_21 , V_29 ) ;
if ( F_74 ( V_29 ) ) {
F_37 ( V_2 , V_6 , V_29 ) ;
V_29 -> V_55 . V_182 &= ~ V_184 ;
}
if ( V_319 )
V_319 -> V_98 = V_29 ;
V_319 = V_29 ;
V_88 -- ;
V_320 ++ ;
F_42 ( V_4 -> V_71 , V_321 ) ;
if ( V_20 -> V_21 && ! F_20 ( V_6 ) )
F_69 ( V_20 -> V_21 , V_117 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_48 ( & V_99 ) )
return;
V_138 = F_7 ( V_319 -> V_30 ) ;
V_138 -> V_47 |= V_132 ;
V_29 = F_50 ( & V_99 , struct V_28 , V_10 ) ;
F_1 ( V_2 , V_4 ) ;
F_111 ( V_2 , V_29 , V_4 , 0 ) ;
F_115 ( V_2 , V_4 , & V_99 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_123 ( struct V_1 * V_2 , int V_322 , int V_323 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_324 V_325 ;
static const int V_326 [] = {
[ V_327 ] = V_328 ,
[ V_329 ] = V_330 ,
[ V_331 ] = V_332 ,
[ V_333 ] = V_334 ,
} ;
int V_71 , V_117 ;
memset ( & V_325 , 0 , sizeof( V_325 ) ) ;
V_325 . V_335 = V_326 [ V_323 ] ;
V_325 . V_336 = V_337 ;
V_325 . V_338 = V_337 ;
V_325 . V_339 = V_337 ;
V_325 . V_340 = 0 ;
if ( V_224 -> V_84 . V_172 & V_173 ) {
V_325 . V_341 = V_342 ;
} else {
if ( V_322 == V_343 )
V_325 . V_341 = V_344 ;
else
V_325 . V_341 = V_345 |
V_344 ;
}
V_71 = F_124 ( V_224 , V_322 , & V_325 ) ;
if ( V_71 == - 1 ) {
return NULL ;
}
if ( ! F_125 ( V_2 , V_71 ) ) {
struct V_3 * V_4 = & V_2 -> V_33 . V_4 [ V_71 ] ;
V_4 -> V_71 = V_71 ;
V_4 -> V_151 = - 1 ;
V_4 -> V_346 = NULL ;
F_63 ( & V_4 -> V_347 ) ;
F_30 ( & V_4 -> V_348 ) ;
F_30 ( & V_4 -> V_12 ) ;
F_126 ( & V_4 -> V_349 ) ;
V_4 -> V_142 = 0 ;
V_4 -> V_143 = 0 ;
V_4 -> V_141 = false ;
V_2 -> V_33 . V_350 |= 1 << V_71 ;
V_4 -> V_351 = V_4 -> V_352 = 0 ;
for ( V_117 = 0 ; V_117 < V_353 ; V_117 ++ )
F_30 ( & V_4 -> V_354 [ V_117 ] ) ;
}
return & V_2 -> V_33 . V_4 [ V_71 ] ;
}
int F_127 ( struct V_1 * V_2 , int V_355 ,
struct V_324 * V_356 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
int error = 0 ;
struct V_324 V_325 ;
F_128 ( V_2 -> V_33 . V_4 [ V_355 ] . V_71 != V_355 ) ;
F_129 ( V_224 , V_355 , & V_325 ) ;
V_325 . V_336 = V_356 -> V_336 ;
V_325 . V_338 = V_356 -> V_338 ;
V_325 . V_339 = V_356 -> V_339 ;
V_325 . V_357 = V_356 -> V_357 ;
V_325 . V_358 = V_356 -> V_358 ;
if ( ! F_130 ( V_224 , V_355 , & V_325 ) ) {
F_131 ( F_103 ( V_2 -> V_83 ) ,
L_1 , V_355 ) ;
error = - V_359 ;
} else {
F_132 ( V_224 , V_355 ) ;
}
return error ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_324 V_325 ;
struct V_360 * V_361 = & V_2 -> V_362 ;
int V_355 = V_2 -> V_363 . V_364 -> V_71 ;
F_129 ( V_2 -> V_83 , V_355 , & V_325 ) ;
V_325 . V_358 = ( F_134 ( V_361 -> V_365 ) *
V_366 ) / 100 ;
F_127 ( V_2 , V_355 , & V_325 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_49 * V_10 )
{
struct V_28 * V_29 , * V_367 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_115 = V_116 ;
F_30 ( & V_50 ) ;
while ( ! F_48 ( V_10 ) ) {
V_29 = F_50 ( V_10 , struct V_28 , V_10 ) ;
if ( V_29 -> V_55 . V_86 ) {
F_51 ( & V_29 -> V_10 ) ;
F_52 ( V_2 , V_29 ) ;
continue;
}
V_367 = V_29 -> V_102 ;
F_136 ( & V_50 , V_10 , & V_367 -> V_10 ) ;
F_75 ( V_2 , V_4 , & V_52 , V_29 , & V_50 ) ;
}
}
void F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_83 -> V_84 . V_172 & V_173 ) {
int V_144 = V_4 -> V_352 ;
while ( ! F_48 ( & V_4 -> V_354 [ V_144 ] ) ) {
F_135 ( V_2 , V_4 , & V_4 -> V_354 [ V_144 ] ) ;
F_36 ( V_144 , V_353 ) ;
}
V_4 -> V_352 = V_144 ;
}
V_4 -> V_346 = NULL ;
V_4 -> V_141 = false ;
F_135 ( V_2 , V_4 , & V_4 -> V_348 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_138 ( struct V_1 * V_2 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_3 * V_4 ;
int V_117 ;
V_91 V_368 = 0 ;
if ( F_35 ( V_369 , & V_226 -> V_370 ) )
return true ;
F_139 ( V_224 ) ;
for ( V_117 = 0 ; V_117 < V_371 ; V_117 ++ ) {
if ( ! F_125 ( V_2 , V_117 ) )
continue;
if ( ! V_2 -> V_33 . V_4 [ V_117 ] . V_142 )
continue;
if ( F_140 ( V_224 , V_2 -> V_33 . V_4 [ V_117 ] . V_71 ) )
V_368 |= F_141 ( V_117 ) ;
}
if ( V_368 )
F_131 ( V_226 , L_2 , V_368 ) ;
for ( V_117 = 0 ; V_117 < V_371 ; V_117 ++ ) {
if ( ! F_125 ( V_2 , V_117 ) )
continue;
V_4 = & V_2 -> V_33 . V_4 [ V_117 ] ;
V_4 -> V_37 = false ;
F_137 ( V_2 , V_4 ) ;
}
return ! V_368 ;
}
void F_142 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_143 ( V_2 -> V_83 , V_4 -> V_71 ) ;
V_2 -> V_33 . V_350 &= ~ ( 1 << V_4 -> V_71 ) ;
}
void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_7 * V_8 , * V_372 ;
struct V_5 * V_6 , * V_373 ;
bool V_320 = false ;
if ( F_35 ( V_374 , & V_226 -> V_370 ) ||
F_48 ( & V_4 -> V_12 ) )
return;
F_59 () ;
V_372 = F_144 ( V_4 -> V_12 . V_69 , struct V_7 , V_10 ) ;
while ( ! F_48 ( & V_4 -> V_12 ) ) {
bool V_297 = false ;
V_8 = F_50 ( & V_4 -> V_12 , struct V_7 , V_10 ) ;
V_373 = F_144 ( V_8 -> V_11 . V_69 , struct V_5 , V_10 ) ;
F_51 ( & V_8 -> V_10 ) ;
V_8 -> V_9 = false ;
while ( ! F_48 ( & V_8 -> V_11 ) ) {
V_6 = F_50 ( & V_8 -> V_11 , struct V_5 ,
V_10 ) ;
F_51 ( & V_6 -> V_10 ) ;
V_6 -> V_9 = false ;
if ( F_114 ( V_2 , V_4 , V_6 , & V_297 ) )
V_320 = true ;
if ( F_20 ( V_6 ) )
F_4 ( V_4 , V_6 ) ;
if ( V_297 || V_6 == V_373 )
break;
}
if ( ! F_48 ( & V_8 -> V_11 ) && ! V_8 -> V_9 ) {
V_8 -> V_9 = true ;
F_5 ( & V_8 -> V_10 , & V_4 -> V_12 ) ;
}
if ( V_297 )
break;
if ( V_8 == V_372 ) {
if ( ! V_320 )
break;
V_320 = false ;
V_372 = F_144 ( V_4 -> V_12 . V_69 ,
struct V_7 , V_10 ) ;
}
}
F_61 () ;
}
static void F_115 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_49 * V_375 , bool V_376 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_225 * V_226 = F_103 ( V_224 ) ;
struct V_28 * V_29 , * V_101 ;
bool V_377 = false ;
bool V_378 ;
if ( F_48 ( V_375 ) )
return;
V_378 = ! ! ( V_224 -> V_84 . V_172 & V_173 ) ;
V_29 = F_50 ( V_375 , struct V_28 , V_10 ) ;
V_101 = F_144 ( V_375 -> V_69 , struct V_28 , V_10 ) ;
F_145 ( V_226 , V_379 , L_3 ,
V_4 -> V_71 , V_4 -> V_142 ) ;
if ( V_378 && F_48 ( & V_4 -> V_354 [ V_4 -> V_351 ] ) ) {
F_146 ( V_375 , & V_4 -> V_354 [ V_4 -> V_351 ] ) ;
F_36 ( V_4 -> V_351 , V_353 ) ;
V_377 = true ;
} else {
F_146 ( V_375 , & V_4 -> V_348 ) ;
if ( V_4 -> V_346 ) {
F_147 ( V_224 , V_4 -> V_346 , V_29 -> V_281 ) ;
F_145 ( V_226 , V_380 , L_4 ,
V_4 -> V_71 , V_4 -> V_346 ,
F_148 ( V_29 -> V_281 ) , V_29 -> V_82 ) ;
} else if ( ! V_378 )
V_377 = true ;
V_4 -> V_346 = V_101 -> V_82 ;
}
if ( V_377 ) {
F_42 ( V_4 -> V_71 , V_377 ) ;
F_149 ( V_224 , V_4 -> V_71 , V_29 -> V_281 ) ;
F_145 ( V_226 , V_380 , L_5 ,
V_4 -> V_71 , F_148 ( V_29 -> V_281 ) , V_29 -> V_82 ) ;
}
if ( ! V_378 || V_2 -> V_282 ) {
F_42 ( V_4 -> V_71 , V_381 ) ;
F_150 ( V_224 , V_4 -> V_71 ) ;
}
if ( ! V_376 ) {
while ( V_29 ) {
V_4 -> V_142 ++ ;
if ( F_73 ( V_29 ) )
V_4 -> V_143 ++ ;
V_101 = V_29 -> V_102 ;
V_29 = V_101 -> V_98 ;
V_101 -> V_98 = NULL ;
}
}
}
static void F_151 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_13 * V_46 = F_6 ( V_15 ) ;
struct V_49 V_50 ;
struct V_28 * V_29 = V_46 -> V_29 ;
F_30 ( & V_50 ) ;
F_5 ( & V_29 -> V_10 , & V_50 ) ;
V_29 -> V_55 . V_182 = 0 ;
if ( V_6 && ( V_17 -> V_47 & V_48 ) ) {
V_29 -> V_55 . V_182 = V_183 ;
F_37 ( V_2 , V_6 , V_29 ) ;
}
V_29 -> V_98 = NULL ;
V_29 -> V_102 = V_29 ;
F_111 ( V_2 , V_29 , V_4 , V_46 -> V_193 ) ;
F_115 ( V_2 , V_4 , & V_50 , false ) ;
F_42 ( V_4 -> V_71 , V_382 ) ;
}
static void F_152 ( struct V_100 * V_39 ,
struct V_27 * V_21 ,
struct V_14 * V_15 ,
int V_193 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_383 * V_384 = V_17 -> V_131 . V_384 ;
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
const struct V_227 * V_228 ;
struct V_13 * V_46 = F_6 ( V_15 ) ;
struct V_40 * V_20 = NULL ;
enum V_385 V_293 ;
bool V_386 = false ;
if ( V_17 -> V_131 . V_22 &&
V_17 -> V_131 . V_22 -> V_387 . V_388 )
V_386 = true ;
V_228 = F_153 ( V_39 , V_17 ) ;
V_293 = F_154 ( V_15 ) ;
if ( V_21 )
V_20 = (struct V_40 * ) V_21 -> V_122 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
if ( V_384 )
V_46 -> V_170 = V_384 -> V_389 ;
else if ( V_20 && F_155 ( V_68 -> V_74 ) && V_20 -> V_390 > 0 )
V_46 -> V_170 = V_20 -> V_390 ;
else
V_46 -> V_170 = V_171 ;
V_46 -> V_293 = V_293 ;
V_46 -> V_193 = V_193 ;
if ( ! V_228 )
return;
V_46 -> V_233 = V_228 -> V_261 ;
if ( V_386 )
V_46 -> V_233 |= V_228 -> V_262 ;
}
T_2 F_105 ( struct V_1 * V_2 , T_2 V_391 , V_91 V_228 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_392 * V_393 = V_224 -> V_393 ;
if ( ( V_224 -> V_84 . V_172 & V_394 ) && F_156 ( V_393 ) &&
( V_391 == 0x7 ) && ( V_228 < 0x90 ) )
return 0x3 ;
else if ( F_157 ( V_224 ) && F_158 ( V_224 ) &&
F_159 ( V_228 ) )
return 0x2 ;
else
return V_391 ;
}
static struct V_28 * F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_13 * V_46 = F_6 ( V_15 ) ;
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
struct V_28 * V_29 ;
int V_395 ;
T_1 V_19 ;
V_29 = F_45 ( V_2 ) ;
if ( ! V_29 ) {
F_145 ( V_226 , V_380 , L_6 ) ;
return NULL ;
}
F_54 ( V_29 ) ;
if ( V_6 && F_160 ( V_68 -> V_74 ) ) {
V_395 = F_161 ( V_68 -> V_396 ) & V_397 ;
V_19 = V_6 -> V_310 ;
V_68 -> V_396 = F_43 ( V_6 -> V_310 << V_25 ) ;
if ( V_395 )
V_68 -> V_396 |= F_43 ( V_395 ) ;
if ( ! F_162 ( V_68 -> V_74 ) )
F_36 ( V_6 -> V_310 , V_63 ) ;
V_29 -> V_55 . V_19 = V_19 ;
}
V_29 -> V_30 = V_15 ;
V_29 -> V_77 = F_163 ( V_2 -> V_76 , V_15 -> V_73 ,
V_15 -> V_221 , V_78 ) ;
if ( F_47 ( F_164 ( V_2 -> V_76 , V_29 -> V_77 ) ) ) {
V_29 -> V_30 = NULL ;
V_29 -> V_77 = 0 ;
F_131 ( F_103 ( V_2 -> V_83 ) ,
L_7 ) ;
F_52 ( V_2 , V_29 ) ;
return NULL ;
}
V_46 -> V_29 = V_29 ;
return V_29 ;
}
static int F_165 ( struct V_100 * V_39 , struct V_14 * V_15 ,
struct V_398 * V_399 )
{
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
struct V_16 * V_138 = F_7 ( V_15 ) ;
struct V_27 * V_21 = V_399 -> V_21 ;
struct V_26 * V_22 = V_138 -> V_131 . V_22 ;
struct V_400 * V_401 ;
struct V_1 * V_2 = V_39 -> V_318 ;
int V_147 = V_15 -> V_221 + V_402 ;
int V_403 , V_404 ;
if ( V_21 )
V_399 -> V_20 = (struct V_40 * ) V_21 -> V_122 ;
else if ( V_22 && F_155 ( V_68 -> V_74 ) ) {
V_401 = ( void * ) V_22 -> V_122 ;
V_399 -> V_20 = & V_401 -> V_405 ;
}
if ( V_138 -> V_131 . V_384 )
V_147 += V_138 -> V_131 . V_384 -> V_406 ;
if ( V_138 -> V_47 & V_407 ) {
if ( V_138 -> V_47 & V_408 )
V_2 -> V_33 . V_409 += 0x10 ;
V_68 -> V_396 &= F_43 ( V_397 ) ;
V_68 -> V_396 |= F_43 ( V_2 -> V_33 . V_409 ) ;
}
if ( ( V_22 && V_22 -> type != V_410 &&
V_22 -> type != V_411 ) ||
! F_155 ( V_68 -> V_74 ) )
V_138 -> V_47 |= V_181 ;
V_403 = F_166 ( V_68 -> V_74 ) ;
V_404 = V_403 & 3 ;
if ( V_404 && V_15 -> V_221 > V_403 ) {
if ( F_167 ( V_15 ) < V_404 )
return - V_412 ;
F_168 ( V_15 , V_404 ) ;
memmove ( V_15 -> V_73 , V_15 -> V_73 + V_404 , V_403 ) ;
}
F_152 ( V_39 , V_21 , V_15 , V_147 ) ;
return 0 ;
}
int F_169 ( struct V_100 * V_39 , struct V_14 * V_15 ,
struct V_398 * V_399 )
{
struct V_67 * V_68 ;
struct V_16 * V_138 = F_7 ( V_15 ) ;
struct V_27 * V_21 = V_399 -> V_21 ;
struct V_26 * V_22 = V_138 -> V_131 . V_22 ;
struct V_1 * V_2 = V_39 -> V_318 ;
struct V_3 * V_4 = V_399 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_28 * V_29 ;
int V_32 ;
int V_413 ;
V_413 = F_165 ( V_39 , V_15 , V_399 ) ;
if ( V_413 )
return V_413 ;
V_68 = (struct V_67 * ) V_15 -> V_73 ;
V_32 = F_15 ( V_15 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_33 . V_35 [ V_32 ] &&
++ V_4 -> V_36 > V_2 -> V_33 . V_38 [ V_32 ] &&
! V_4 -> V_37 ) {
F_170 ( V_2 -> V_39 , V_32 ) ;
V_4 -> V_37 = true ;
}
if ( V_399 -> V_20 && F_160 ( V_68 -> V_74 ) )
V_6 = F_18 ( V_2 , V_399 -> V_20 , V_15 ) ;
if ( V_138 -> V_47 & V_414 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_33 . V_34 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_399 -> V_20 &&
F_160 ( V_68 -> V_74 ) ) {
F_16 ( V_6 -> V_8 -> V_4 != V_399 -> V_4 ) ;
if ( V_138 -> V_47 & V_181 )
V_6 -> V_8 -> V_135 = true ;
F_42 ( V_4 -> V_71 , V_415 ) ;
F_68 ( & V_6 -> V_43 , V_15 ) ;
if ( ! V_399 -> V_20 -> V_130 )
F_4 ( V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
goto V_416;
}
V_29 = F_26 ( V_2 , V_4 , V_6 , V_15 ) ;
if ( ! V_29 ) {
F_14 ( V_2 , V_4 , V_15 ) ;
if ( V_399 -> V_417 )
F_171 ( V_15 ) ;
else
F_28 ( V_2 -> V_39 , V_15 ) ;
goto V_416;
}
V_29 -> V_55 . V_263 = V_399 -> V_417 ;
if ( V_399 -> V_417 )
V_29 -> V_55 . V_418 = V_419 ;
F_11 ( V_22 , V_21 , V_29 ) ;
F_151 ( V_2 , V_4 , V_6 , V_15 ) ;
V_416:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_172 ( struct V_100 * V_39 , struct V_26 * V_22 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = V_39 -> V_318 ;
struct V_398 V_399 = {
. V_4 = V_2 -> V_363 . V_364
} ;
struct V_220 V_138 = {} ;
struct V_67 * V_68 ;
struct V_28 * V_319 = NULL ;
struct V_28 * V_29 ;
F_173 ( V_99 ) ;
int V_198 = 0 ;
int V_420 ;
V_420 =
V_2 -> V_362 . V_365 * 1000 *
V_2 -> V_362 . V_421 / V_422 ;
do {
struct V_13 * V_46 = F_6 ( V_15 ) ;
if ( F_165 ( V_39 , V_15 , & V_399 ) )
break;
V_29 = F_26 ( V_2 , V_399 . V_4 , NULL , V_15 ) ;
if ( ! V_29 )
break;
V_29 -> V_102 = V_29 ;
F_11 ( V_22 , NULL , V_29 ) ;
F_102 ( V_2 , V_29 , & V_138 , V_46 -> V_193 , false ) ;
V_198 += V_138 . V_31 [ 0 ] . V_251 ;
if ( V_319 )
V_319 -> V_98 = V_29 ;
F_5 ( & V_29 -> V_10 , & V_99 ) ;
V_319 = V_29 ;
V_15 = NULL ;
if ( V_198 > V_420 )
break;
V_15 = F_174 ( V_39 , V_22 ) ;
} while( V_15 );
if ( V_15 )
F_28 ( V_39 , V_15 ) ;
if ( F_48 ( & V_99 ) )
return;
V_29 = F_50 ( & V_99 , struct V_28 , V_10 ) ;
V_68 = (struct V_67 * ) V_29 -> V_30 -> V_73 ;
if ( V_68 -> V_74 & V_423 ) {
V_68 -> V_74 &= ~ V_423 ;
F_44 ( V_2 -> V_76 , V_29 -> V_77 ,
sizeof( * V_68 ) , V_78 ) ;
}
F_1 ( V_2 , V_399 . V_4 ) ;
F_111 ( V_2 , V_29 , V_399 . V_4 , 0 ) ;
F_115 ( V_2 , V_399 . V_4 , & V_99 , false ) ;
F_42 ( V_399 . V_4 -> V_71 , V_382 ) ;
F_2 ( V_2 , V_399 . V_4 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_424 , struct V_3 * V_4 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
int V_403 , V_404 ;
unsigned long V_47 ;
F_145 ( V_226 , V_380 , L_8 , V_15 ) ;
if ( V_2 -> V_83 -> V_425 )
F_175 ( V_426 , & V_2 -> V_83 -> V_425 -> V_427 ) ;
if ( ! ( V_424 & V_65 ) )
V_17 -> V_47 |= V_428 ;
V_403 = F_166 ( V_68 -> V_74 ) ;
V_404 = V_403 & 3 ;
if ( V_404 && V_15 -> V_221 > V_403 + V_404 ) {
memmove ( V_15 -> V_73 + V_404 , V_15 -> V_73 , V_403 ) ;
F_176 ( V_15 , V_404 ) ;
}
F_177 ( & V_2 -> V_429 , V_47 ) ;
if ( ( V_2 -> V_430 & V_431 ) && ! V_4 -> V_142 ) {
V_2 -> V_430 &= ~ V_431 ;
F_145 ( V_226 , V_432 ,
L_9 ,
V_2 -> V_430 & ( V_433 |
V_434 |
V_435 |
V_431 ) ) ;
}
F_178 ( & V_2 -> V_429 , V_47 ) ;
F_68 ( & V_4 -> V_347 , V_15 ) ;
F_14 ( V_2 , V_4 , V_15 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_3 * V_4 , struct V_49 * V_99 ,
struct V_51 * V_52 , int V_87 )
{
struct V_14 * V_15 = V_29 -> V_30 ;
struct V_16 * V_17 = F_7 ( V_15 ) ;
unsigned long V_47 ;
int V_424 = 0 ;
if ( ! V_87 )
V_424 |= V_65 ;
if ( V_52 -> V_115 & V_133 )
V_17 -> V_47 |= V_436 ;
F_179 ( V_2 -> V_76 , V_29 -> V_77 , V_15 -> V_221 , V_78 ) ;
V_29 -> V_77 = 0 ;
if ( V_2 -> V_282 )
goto V_437;
if ( V_29 -> V_55 . V_263 ) {
if ( F_180 ( V_419 ,
V_29 -> V_55 . V_418 +
F_181 ( V_438 ) ) )
F_171 ( V_15 ) ;
else
F_182 ( & V_2 -> V_439 ) ;
} else {
F_183 ( V_2 , V_29 , V_52 , V_4 , V_424 ) ;
F_40 ( V_2 , V_15 , V_424 , V_4 ) ;
}
V_437:
V_29 -> V_30 = NULL ;
F_177 ( & V_2 -> V_33 . V_79 , V_47 ) ;
F_146 ( V_99 , & V_2 -> V_33 . V_80 ) ;
F_178 ( & V_2 -> V_33 . V_79 , V_47 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_51 * V_52 , int V_88 , int V_89 ,
int V_87 )
{
struct V_14 * V_15 = V_29 -> V_30 ;
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_100 * V_39 = V_2 -> V_39 ;
struct V_223 * V_224 = V_2 -> V_83 ;
T_2 V_117 , V_440 ;
if ( V_87 )
V_17 -> V_441 . V_442 = V_52 -> V_443 ;
V_440 = V_52 -> V_119 ;
F_16 ( V_440 >= V_39 -> V_444 ) ;
if ( V_17 -> V_47 & V_48 ) {
V_17 -> V_47 |= V_445 ;
F_128 ( V_89 > V_88 ) ;
}
V_17 -> V_441 . V_446 = V_88 ;
V_17 -> V_441 . V_447 = V_88 - V_89 ;
if ( ( V_52 -> V_115 & V_133 ) == 0 &&
( V_17 -> V_47 & V_285 ) == 0 ) {
if ( F_47 ( V_52 -> V_123 & ( V_448 |
V_449 ) ) &&
F_155 ( V_68 -> V_74 ) &&
V_224 -> V_450 >= V_2 -> V_83 -> V_451 . V_452 )
V_17 -> V_441 . V_31 [ V_440 ] . V_66 =
V_39 -> V_453 ;
}
for ( V_117 = V_440 + 1 ; V_117 < V_39 -> V_444 ; V_117 ++ ) {
V_17 -> V_441 . V_31 [ V_117 ] . V_66 = 0 ;
V_17 -> V_441 . V_31 [ V_117 ] . V_144 = - 1 ;
}
V_17 -> V_441 . V_31 [ V_440 ] . V_66 = V_52 -> V_118 + 1 ;
}
static void F_184 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_225 * V_226 = F_103 ( V_224 ) ;
struct V_28 * V_29 , * V_367 , * V_454 = NULL ;
struct V_49 V_50 ;
struct V_455 * V_456 ;
struct V_51 V_52 ;
int V_441 ;
F_145 ( V_226 , V_379 , L_10 ,
V_4 -> V_71 , F_185 ( V_2 -> V_83 , V_4 -> V_71 ) ,
V_4 -> V_346 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_35 ( V_374 , & V_226 -> V_370 ) )
break;
if ( F_48 ( & V_4 -> V_348 ) ) {
V_4 -> V_346 = NULL ;
F_76 ( V_2 , V_4 ) ;
break;
}
V_29 = F_50 ( & V_4 -> V_348 , struct V_28 , V_10 ) ;
V_454 = NULL ;
if ( V_29 -> V_55 . V_86 ) {
V_454 = V_29 ;
if ( F_186 ( & V_454 -> V_10 , & V_4 -> V_348 ) )
break;
V_29 = F_144 ( V_454 -> V_10 . V_457 , struct V_28 ,
V_10 ) ;
}
V_367 = V_29 -> V_102 ;
V_456 = V_367 -> V_82 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_441 = F_187 ( V_224 , V_456 , & V_52 ) ;
if ( V_441 == - V_458 )
break;
F_42 ( V_4 -> V_71 , V_459 ) ;
V_367 -> V_55 . V_86 = true ;
F_30 ( & V_50 ) ;
if ( ! F_188 ( & V_367 -> V_10 ) )
F_136 ( & V_50 ,
& V_4 -> V_348 , V_367 -> V_10 . V_69 ) ;
if ( V_454 ) {
F_51 ( & V_454 -> V_10 ) ;
F_52 ( V_2 , V_454 ) ;
}
F_75 ( V_2 , V_4 , & V_52 , V_29 , & V_50 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_189 ( struct V_1 * V_2 )
{
struct V_223 * V_224 = V_2 -> V_83 ;
V_91 V_460 = ( ( 1 << V_371 ) - 1 ) & V_224 -> V_461 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_371 ; V_117 ++ ) {
if ( F_125 ( V_2 , V_117 ) && ( V_460 & ( 1 << V_117 ) ) )
F_184 ( V_2 , & V_2 -> V_33 . V_4 [ V_117 ] ) ;
}
}
void F_190 ( struct V_1 * V_2 )
{
struct V_51 V_52 ;
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_223 * V_224 = V_2 -> V_83 ;
struct V_3 * V_4 ;
struct V_28 * V_29 , * V_367 ;
struct V_49 V_50 ;
struct V_49 * V_462 ;
int V_441 ;
for (; ; ) {
if ( F_35 ( V_374 , & V_226 -> V_370 ) )
break;
V_441 = F_187 ( V_224 , NULL , ( void * ) & V_52 ) ;
if ( V_441 == - V_458 )
break;
if ( V_441 == - V_359 ) {
F_145 ( V_226 , V_380 , L_11 ) ;
break;
}
if ( V_52 . V_463 == V_2 -> V_363 . V_464 ) {
V_2 -> V_363 . V_465 = true ;
V_2 -> V_363 . V_466 = ! ( V_52 . V_115 & V_140 ) ;
F_191 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_33 . V_4 [ V_52 . V_463 ] ;
F_1 ( V_2 , V_4 ) ;
F_42 ( V_4 -> V_71 , V_459 ) ;
V_462 = & V_4 -> V_354 [ V_4 -> V_352 ] ;
if ( F_48 ( V_462 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_29 = F_50 ( V_462 , struct V_28 , V_10 ) ;
if ( V_29 -> V_55 . V_86 ) {
F_51 ( & V_29 -> V_10 ) ;
F_52 ( V_2 , V_29 ) ;
V_29 = F_50 ( V_462 , struct V_28 , V_10 ) ;
}
V_367 = V_29 -> V_102 ;
F_30 ( & V_50 ) ;
if ( F_186 ( & V_367 -> V_10 , V_462 ) ) {
F_146 ( V_462 , & V_50 ) ;
F_36 ( V_4 -> V_352 , V_353 ) ;
if ( ! F_48 ( & V_4 -> V_348 ) ) {
struct V_49 V_99 ;
F_30 ( & V_99 ) ;
V_4 -> V_346 = NULL ;
F_146 ( & V_4 -> V_348 , & V_99 ) ;
F_115 ( V_2 , V_4 , & V_99 , true ) ;
}
} else {
V_367 -> V_55 . V_86 = true ;
if ( V_29 != V_367 )
F_136 ( & V_50 , V_462 ,
V_367 -> V_10 . V_69 ) ;
}
F_75 ( V_2 , V_4 , & V_52 , V_29 , & V_50 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_192 ( struct V_1 * V_2 , int V_467 )
{
struct V_468 * V_469 = & V_2 -> V_470 ;
T_2 V_471 = V_2 -> V_83 -> V_84 . V_471 ;
V_469 -> V_472 = V_467 * V_471 ;
V_469 -> V_473 = F_193 ( V_2 -> V_76 , V_469 -> V_472 ,
& V_469 -> V_474 , V_475 ) ;
if ( ! V_469 -> V_473 )
return - V_412 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 )
{
int V_476 ;
V_476 = F_192 ( V_2 , V_477 ) ;
if ( ! V_476 )
F_195 ( V_2 -> V_83 , V_2 -> V_470 . V_473 ,
V_2 -> V_470 . V_474 ,
V_477 ) ;
return V_476 ;
}
int F_196 ( struct V_1 * V_2 , int V_478 )
{
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
int error = 0 ;
F_126 ( & V_2 -> V_33 . V_79 ) ;
error = F_197 ( V_2 , & V_2 -> V_33 . V_479 , & V_2 -> V_33 . V_80 ,
L_12 , V_478 , 1 , 1 ) ;
if ( error != 0 ) {
F_131 ( V_226 ,
L_13 , error ) ;
return error ;
}
error = F_197 ( V_2 , & V_2 -> V_363 . V_480 , & V_2 -> V_363 . V_481 ,
L_14 , V_422 , 1 , 1 ) ;
if ( error != 0 ) {
F_131 ( V_226 ,
L_15 , error ) ;
return error ;
}
F_198 ( & V_2 -> V_482 , V_483 ) ;
if ( V_2 -> V_83 -> V_84 . V_172 & V_173 )
error = F_194 ( V_2 ) ;
return error ;
}
void F_199 ( struct V_1 * V_2 , struct V_40 * V_20 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_24 , V_484 ;
for ( V_24 = 0 , V_6 = & V_20 -> V_6 [ V_24 ] ;
V_24 < V_312 ;
V_24 ++ , V_6 ++ ) {
V_6 -> V_20 = V_20 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_56 = V_6 -> V_310 = 0 ;
V_6 -> V_127 = V_485 ;
V_6 -> V_59 = V_6 -> V_62 = 0 ;
V_6 -> V_9 = false ;
V_6 -> V_128 = false ;
F_63 ( & V_6 -> V_43 ) ;
F_63 ( & V_6 -> V_44 ) ;
V_484 = F_200 ( V_24 ) ;
V_6 -> V_8 = & V_20 -> V_8 [ V_484 ] ;
}
for ( V_484 = 0 , V_8 = & V_20 -> V_8 [ V_484 ] ;
V_484 < V_486 ; V_484 ++ , V_8 ++ ) {
V_8 -> V_9 = false ;
V_8 -> V_135 = true ;
V_8 -> V_4 = V_2 -> V_33 . V_35 [ V_484 ] ;
F_30 ( & V_8 -> V_11 ) ;
}
}
void F_201 ( struct V_1 * V_2 , struct V_40 * V_20 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_24 ;
for ( V_24 = 0 , V_6 = & V_20 -> V_6 [ V_24 ] ;
V_24 < V_312 ; V_24 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_9 ) {
F_51 ( & V_6 -> V_10 ) ;
V_6 -> V_9 = false ;
}
if ( V_8 -> V_9 ) {
F_51 ( & V_8 -> V_10 ) ;
V_6 -> V_8 -> V_9 = false ;
}
F_39 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_128 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
int F_202 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_398 * V_399 )
{
struct V_67 * V_68 = (struct V_67 * ) V_15 -> V_73 ;
struct V_13 * V_46 = F_6 ( V_15 ) ;
struct V_225 * V_226 = F_103 ( V_2 -> V_83 ) ;
struct V_28 * V_29 ;
int V_403 , V_404 ;
V_403 = F_166 ( V_68 -> V_74 ) ;
V_404 = V_403 & 3 ;
if ( V_404 && V_15 -> V_221 > V_403 ) {
if ( F_167 ( V_15 ) < V_404 ) {
F_145 ( V_226 , V_380 ,
L_16 ) ;
return - V_487 ;
}
F_168 ( V_15 , V_404 ) ;
memmove ( V_15 -> V_73 , V_15 -> V_73 + V_404 , V_403 ) ;
}
V_46 -> V_170 = V_171 ;
V_46 -> V_193 = V_15 -> V_221 + V_402 ;
V_46 -> V_293 = V_488 ;
V_29 = F_26 ( V_2 , V_399 -> V_4 , NULL , V_15 ) ;
if ( ! V_29 ) {
F_145 ( V_226 , V_380 , L_17 ) ;
return - V_487 ;
}
F_11 ( V_2 -> V_489 , NULL , V_29 ) ;
F_147 ( V_2 -> V_83 , V_29 -> V_82 , V_29 -> V_281 ) ;
F_203 ( V_2 -> V_83 , V_399 -> V_4 -> V_71 ) ;
F_151 ( V_2 , V_399 -> V_4 , NULL , V_15 ) ;
return 0 ;
}
