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
int V_41 ;
int V_42 = V_40 -> V_4 ;
if ( V_42 < 0 )
return;
V_4 = V_2 -> V_43 . V_44 [ V_42 ] ;
if ( F_16 ( -- V_4 -> V_45 < 0 ) )
V_4 -> V_45 = 0 ;
V_41 = ( V_39 -> V_41 >= V_2 -> V_46 -> V_47 - 2 ) ? V_42 : V_39 -> V_41 ;
if ( V_4 -> V_48 &&
V_4 -> V_45 < V_2 -> V_43 . V_49 [ V_42 ] ) {
F_17 ( V_2 -> V_46 , V_41 ) ;
V_4 -> V_48 = false ;
}
}
static struct V_5 *
F_18 ( struct V_1 * V_2 , struct V_50 * V_13 , struct V_24 * V_25 )
{
T_2 V_22 = V_25 -> V_51 & V_52 ;
return F_19 ( V_13 , V_22 ) ;
}
static bool F_20 ( struct V_5 * V_6 )
{
return ! F_21 ( & V_6 -> V_53 ) || ! F_21 ( & V_6 -> V_54 ) ;
}
static struct V_24 * F_22 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
V_25 = F_23 ( & V_6 -> V_54 ) ;
if ( ! V_25 )
V_25 = F_23 ( & V_6 -> V_53 ) ;
return V_25 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_26 * V_27 ;
struct V_24 * V_25 , * V_55 ;
struct V_35 * V_36 ;
struct V_23 * V_40 ;
F_25 (&tid->buf_q, skb, tskb) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
V_27 = F_8 ( V_25 ) ;
V_27 -> V_56 &= ~ V_57 ;
if ( V_36 )
continue;
V_36 = F_26 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_27 ( V_25 , & V_6 -> V_53 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
F_28 ( V_2 -> V_46 , V_25 ) ;
continue;
}
}
}
static void F_29 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_24 * V_25 ;
struct V_35 * V_36 ;
struct V_9 V_58 ;
struct V_59 V_60 ;
struct V_23 * V_40 ;
bool V_61 = false ;
F_30 ( & V_58 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
while ( ( V_25 = F_23 ( & V_6 -> V_54 ) ) ) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
F_28 ( V_2 -> V_46 , V_25 ) ;
continue;
}
if ( V_40 -> V_62 ) {
F_31 ( V_2 , V_6 , V_36 -> V_63 . V_29 ) ;
V_61 = true ;
}
F_5 ( & V_36 -> V_10 , & V_58 ) ;
F_32 ( V_2 , V_36 , V_4 , & V_58 , & V_60 , 0 ) ;
}
if ( V_61 ) {
F_2 ( V_2 , V_4 ) ;
F_10 ( V_6 , V_6 -> V_64 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
int V_65 , V_66 ;
V_65 = F_33 ( V_6 -> V_64 , V_29 ) ;
V_66 = ( V_6 -> V_67 + V_65 ) & ( V_68 - 1 ) ;
F_34 ( V_66 , V_6 -> V_69 ) ;
while ( V_6 -> V_67 != V_6 -> V_70 && ! F_35 ( V_6 -> V_67 , V_6 -> V_69 ) ) {
F_36 ( V_6 -> V_64 , V_71 ) ;
F_36 ( V_6 -> V_67 , V_68 ) ;
if ( V_6 -> V_72 >= 0 )
V_6 -> V_72 -- ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
T_1 V_29 = V_36 -> V_63 . V_29 ;
int V_65 , V_66 ;
V_65 = F_33 ( V_6 -> V_64 , V_29 ) ;
V_66 = ( V_6 -> V_67 + V_65 ) & ( V_68 - 1 ) ;
F_38 ( V_66 , V_6 -> V_69 ) ;
V_40 -> V_62 = 1 ;
if ( V_65 >= ( ( V_6 -> V_70 - V_6 -> V_67 ) &
( V_68 - 1 ) ) ) {
V_6 -> V_70 = V_66 ;
F_36 ( V_6 -> V_70 , V_68 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_35 * V_36 ;
struct V_9 V_58 ;
struct V_59 V_60 ;
struct V_23 * V_40 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_30 ( & V_58 ) ;
while ( ( V_25 = F_22 ( V_6 ) ) ) {
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_36 ) {
F_40 ( V_2 , V_25 , V_73 , V_4 ) ;
continue;
}
F_5 ( & V_36 -> V_10 , & V_58 ) ;
F_32 ( V_2 , V_36 , V_4 , & V_58 , & V_60 , 0 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_24 * V_25 , int V_74 )
{
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_35 * V_36 = V_40 -> V_36 ;
struct V_75 * V_76 ;
int V_77 = V_40 -> V_78 ;
F_42 ( V_4 -> V_79 , V_80 ) ;
V_40 -> V_78 += V_74 ;
if ( V_77 > 0 )
return;
V_76 = (struct V_75 * ) V_25 -> V_81 ;
V_76 -> V_82 |= F_43 ( V_83 ) ;
F_44 ( V_2 -> V_84 , V_36 -> V_85 ,
sizeof( * V_76 ) , V_86 ) ;
}
static struct V_35 * F_45 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
F_46 ( & V_2 -> V_43 . V_87 ) ;
if ( F_47 ( F_48 ( & V_2 -> V_43 . V_88 ) ) ) {
F_49 ( & V_2 -> V_43 . V_87 ) ;
return NULL ;
}
V_36 = F_50 ( & V_2 -> V_43 . V_88 , struct V_35 , V_10 ) ;
F_51 ( & V_36 -> V_10 ) ;
F_49 ( & V_2 -> V_43 . V_87 ) ;
return V_36 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
F_46 ( & V_2 -> V_43 . V_87 ) ;
F_5 ( & V_36 -> V_10 , & V_2 -> V_43 . V_88 ) ;
F_49 ( & V_2 -> V_43 . V_87 ) ;
}
static struct V_35 * F_53 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_35 * V_89 ;
V_89 = F_45 ( V_2 ) ;
if ( F_16 ( ! V_89 ) )
return NULL ;
F_54 ( V_89 ) ;
V_89 -> V_37 = V_36 -> V_37 ;
V_89 -> V_85 = V_36 -> V_85 ;
memcpy ( V_89 -> V_90 , V_36 -> V_90 , V_2 -> V_91 -> V_92 . V_93 ) ;
V_89 -> V_63 = V_36 -> V_63 ;
V_89 -> V_63 . V_94 = false ;
return V_89 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_59 * V_60 , int V_95 ,
int * V_96 , int * V_97 )
{
struct V_23 * V_40 ;
T_1 V_98 = 0 ;
V_99 V_100 [ V_101 >> 5 ] ;
int V_102 ;
int V_103 = 0 ;
* V_97 = 0 ;
* V_96 = 0 ;
V_103 = F_56 ( V_36 ) ;
if ( V_103 ) {
V_98 = V_60 -> V_104 ;
memcpy ( V_100 , & V_60 -> V_105 , V_101 >> 3 ) ;
}
while ( V_36 ) {
V_40 = F_7 ( V_36 -> V_37 ) ;
V_102 = F_33 ( V_98 , V_36 -> V_63 . V_29 ) ;
( * V_96 ) ++ ;
if ( ! V_95 || ( V_103 && ! F_57 ( V_100 , V_102 ) ) )
( * V_97 ) ++ ;
V_36 = V_36 -> V_106 ;
}
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_9 * V_107 ,
struct V_59 * V_60 , int V_95 )
{
struct V_50 * V_13 = NULL ;
struct V_24 * V_25 ;
struct V_34 * V_30 ;
struct V_108 * V_46 = V_2 -> V_46 ;
struct V_75 * V_76 ;
struct V_26 * V_27 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_106 , * V_109 = V_36 -> V_110 ;
struct V_9 V_58 ;
struct V_111 V_112 ;
T_1 V_98 = 0 , V_113 = 0 , V_114 = 0 , V_115 ;
V_99 V_100 [ V_101 >> 5 ] ;
int V_103 , V_116 , V_117 , V_61 = 0 , V_118 = 0 , V_97 = 0 ;
bool V_119 = true , V_120 ;
struct V_121 V_38 [ 4 ] ;
struct V_23 * V_40 ;
int V_96 ;
bool V_122 = ! ! ( V_60 -> V_123 & V_124 ) ;
int V_125 , V_78 ;
int V_72 = - 1 ;
V_25 = V_36 -> V_37 ;
V_76 = (struct V_75 * ) V_25 -> V_81 ;
V_27 = F_8 ( V_25 ) ;
memcpy ( V_38 , V_36 -> V_38 , sizeof( V_38 ) ) ;
V_78 = V_60 -> V_126 + 1 ;
for ( V_125 = 0 ; V_125 < V_60 -> V_127 ; V_125 ++ )
V_78 += V_38 [ V_125 ] . V_74 ;
F_59 () ;
V_30 = F_60 ( V_46 , V_76 -> V_128 , V_76 -> V_129 ) ;
if ( ! V_30 ) {
F_61 () ;
F_30 ( & V_58 ) ;
while ( V_36 ) {
V_106 = V_36 -> V_106 ;
if ( ! V_36 -> V_63 . V_94 || V_106 != NULL )
F_62 ( & V_36 -> V_10 , & V_58 ) ;
F_32 ( V_2 , V_36 , V_4 , & V_58 , V_60 , 0 ) ;
V_36 = V_106 ;
}
return;
}
V_13 = (struct V_50 * ) V_30 -> V_15 ;
V_6 = F_18 ( V_2 , V_13 , V_25 ) ;
V_115 = V_6 -> V_64 ;
V_120 = V_60 -> V_130 & V_131 ;
if ( V_120 && V_6 -> V_22 != V_60 -> V_6 )
V_95 = false ;
V_103 = F_56 ( V_36 ) ;
memset ( V_100 , 0 , V_101 >> 3 ) ;
if ( V_103 && V_95 ) {
if ( V_60 -> V_130 & V_131 ) {
V_98 = V_60 -> V_104 ;
memcpy ( V_100 , & V_60 -> V_105 , V_101 >> 3 ) ;
} else {
if ( V_2 -> V_91 -> V_132 == V_133 )
V_118 = 1 ;
}
}
F_63 ( & V_112 ) ;
F_55 ( V_2 , V_36 , V_60 , V_95 , & V_96 , & V_97 ) ;
while ( V_36 ) {
T_1 V_29 = V_36 -> V_63 . V_29 ;
V_116 = V_117 = V_61 = 0 ;
V_106 = V_36 -> V_106 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_40 = F_7 ( V_25 ) ;
if ( ! F_64 ( V_6 -> V_64 , V_6 -> V_134 , V_29 ) ||
! V_6 -> V_135 ) {
V_116 = 1 ;
} else if ( F_57 ( V_100 , F_33 ( V_98 , V_29 ) ) ) {
V_113 ++ ;
} else if ( ! V_103 && V_95 ) {
V_113 ++ ;
} else if ( V_122 ) {
V_117 = 1 ;
} else if ( V_40 -> V_78 < V_136 ) {
if ( V_95 || ! V_13 -> V_137 )
F_41 ( V_2 , V_4 , V_36 -> V_37 ,
V_78 ) ;
V_117 = 1 ;
} else {
V_116 = 1 ;
V_114 ++ ;
V_72 = F_65 ( int , V_72 ,
F_33 ( V_115 , V_29 ) ) ;
}
F_30 ( & V_58 ) ;
if ( V_106 != NULL || ! V_109 -> V_63 . V_94 )
F_62 ( & V_36 -> V_10 , & V_58 ) ;
if ( ! V_117 ) {
F_31 ( V_2 , V_6 , V_29 ) ;
if ( V_119 && ( V_113 == 1 || V_114 == 1 ) ) {
memcpy ( V_27 -> V_138 . V_38 , V_38 , sizeof( V_38 ) ) ;
F_66 ( V_2 , V_36 , V_60 , V_96 , V_97 , V_95 ) ;
V_119 = false ;
}
F_32 ( V_2 , V_36 , V_4 , & V_58 , V_60 ,
! V_116 ) ;
} else {
if ( V_27 -> V_56 & V_139 ) {
V_27 -> V_56 &= ~ V_139 ;
F_67 ( V_30 ) ;
}
if ( V_36 -> V_106 == NULL && V_109 -> V_63 . V_94 ) {
struct V_35 * V_89 ;
V_89 = F_53 ( V_2 , V_109 ) ;
if ( ! V_89 ) {
F_31 ( V_2 , V_6 , V_29 ) ;
F_32 ( V_2 , V_36 , V_4 ,
& V_58 , V_60 , 0 ) ;
V_72 = F_65 ( int , V_72 ,
F_33 ( V_115 , V_29 ) ) ;
break;
}
V_40 -> V_36 = V_89 ;
}
F_68 ( & V_112 , V_25 ) ;
}
V_36 = V_106 ;
}
if ( ! F_21 ( & V_112 ) ) {
if ( V_13 -> V_137 )
F_69 ( V_30 , V_6 -> V_22 , true ) ;
F_70 ( & V_112 , & V_6 -> V_54 ) ;
if ( ! V_13 -> V_137 ) {
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_60 -> V_123 & ( V_140 | V_141 ) )
V_6 -> V_8 -> V_142 = true ;
}
}
if ( V_72 >= 0 ) {
T_1 V_143 = F_71 ( V_115 , V_72 ) ;
if ( F_64 ( V_6 -> V_64 , V_6 -> V_134 , V_143 ) )
V_6 -> V_72 = F_33 ( V_6 -> V_64 , V_143 ) ;
F_2 ( V_2 , V_4 ) ;
F_10 ( V_6 , F_71 ( V_115 , V_72 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_61 () ;
if ( V_118 )
F_72 ( V_2 , V_144 ) ;
}
static bool F_73 ( struct V_35 * V_36 )
{
struct V_26 * V_39 = F_8 ( V_36 -> V_37 ) ;
return F_74 ( V_36 ) && ! ( V_39 -> V_56 & V_145 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_59 * V_60 , struct V_35 * V_36 ,
struct V_9 * V_58 )
{
struct V_26 * V_39 ;
bool V_95 , V_122 ;
V_95 = ! ( V_60 -> V_123 & V_146 ) ;
V_122 = ! ! ( V_60 -> V_123 & V_124 ) ;
V_4 -> V_147 = false ;
V_4 -> V_148 -- ;
if ( F_73 ( V_36 ) )
V_4 -> V_149 -- ;
if ( ! F_74 ( V_36 ) ) {
if ( ! V_122 ) {
V_39 = F_8 ( V_36 -> V_37 ) ;
memcpy ( V_39 -> V_138 . V_38 , V_36 -> V_38 ,
sizeof( V_39 -> V_138 . V_38 ) ) ;
F_66 ( V_2 , V_36 , V_60 , 1 , V_95 ? 0 : 1 , V_95 ) ;
}
F_32 ( V_2 , V_36 , V_4 , V_58 , V_60 , V_95 ) ;
} else
F_58 ( V_2 , V_4 , V_36 , V_58 , V_60 , V_95 ) ;
if ( ! V_122 )
F_76 ( V_2 , V_4 ) ;
}
static bool F_77 ( struct V_35 * V_36 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_121 * V_38 ;
int V_125 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_27 -> V_138 . V_38 ;
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ ) {
if ( ! V_38 [ V_125 ] . V_74 || V_38 [ V_125 ] . V_150 < 0 )
break;
if ( ! ( V_38 [ V_125 ] . V_56 & V_151 ) )
return true ;
}
return false ;
}
static V_99 F_78 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_121 * V_38 ;
V_99 V_152 , V_153 ;
T_1 V_154 , V_155 , V_156 = 0 ;
int V_42 = V_6 -> V_8 -> V_4 -> V_157 ;
int V_125 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_152 = V_158 ;
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ ) {
int V_159 ;
if ( ! V_38 [ V_125 ] . V_74 )
continue;
if ( ! ( V_38 [ V_125 ] . V_56 & V_151 ) ) {
V_156 = 1 ;
break;
}
if ( V_38 [ V_125 ] . V_56 & V_160 )
V_159 = V_161 ;
else
V_159 = V_162 ;
if ( V_38 [ V_125 ] . V_56 & V_163 )
V_159 ++ ;
V_153 = V_2 -> V_43 . V_164 [ V_42 ] [ V_159 ] [ V_38 [ V_125 ] . V_150 ] ;
V_152 = F_79 ( V_152 , V_153 ) ;
}
if ( V_27 -> V_56 & V_145 || V_156 )
return 0 ;
V_154 = F_79 ( V_152 , ( V_99 ) V_158 ) ;
V_155 = F_80 ( V_2 , V_152 ) ;
if ( V_155 )
V_154 = V_155 ;
if ( V_6 -> V_13 -> V_165 )
V_154 = F_79 ( V_154 , V_6 -> V_13 -> V_165 ) ;
return V_154 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 , T_1 V_153 ,
bool V_166 )
{
#define F_82 60
V_99 V_167 , V_168 ;
T_1 V_169 ;
T_2 V_56 , V_170 ;
int V_171 , V_172 , V_173 , V_174 , V_175 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_174 = F_83 ( V_153 ) ;
if ( ( V_40 -> V_176 != V_177 ) &&
! ( V_2 -> V_91 -> V_92 . V_178 & V_179 ) )
V_174 += V_180 ;
if ( V_166 && ! F_84 ( V_2 -> V_91 ) &&
( V_2 -> V_91 -> V_181 & V_182 ) )
V_174 = F_85 ( V_174 , F_82 ) ;
if ( V_6 -> V_13 -> V_183 == 0 )
return V_174 ;
V_170 = V_36 -> V_38 [ 0 ] . V_150 ;
V_56 = V_36 -> V_38 [ 0 ] . V_56 ;
V_171 = ( V_56 & V_160 ) ? 1 : 0 ;
V_173 = ( V_56 & V_163 ) ? 1 : 0 ;
if ( V_173 )
V_168 = F_86 ( V_6 -> V_13 -> V_183 ) ;
else
V_168 = F_87 ( V_6 -> V_13 -> V_183 ) ;
if ( V_168 == 0 )
V_168 = 1 ;
V_172 = F_88 ( V_170 ) ;
V_167 = V_184 [ V_170 % 8 ] [ V_171 ] * V_172 ;
V_169 = ( V_168 * V_167 ) / V_185 ;
if ( V_153 < V_169 ) {
V_175 = ( V_169 - V_153 ) / V_186 ;
V_174 = F_85 ( V_175 , V_174 ) ;
}
return V_174 ;
}
static struct V_35 *
F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_111 * * V_42 )
{
struct V_26 * V_27 ;
struct V_23 * V_40 ;
struct V_24 * V_25 ;
struct V_35 * V_36 ;
T_1 V_29 ;
while ( 1 ) {
* V_42 = & V_6 -> V_54 ;
if ( F_21 ( * V_42 ) )
* V_42 = & V_6 -> V_53 ;
V_25 = F_90 ( * V_42 ) ;
if ( ! V_25 )
break;
V_40 = F_7 ( V_25 ) ;
V_36 = V_40 -> V_36 ;
if ( ! V_40 -> V_36 )
V_36 = F_26 ( V_2 , V_4 , V_6 , V_25 ) ;
else
V_36 -> V_63 . V_94 = false ;
if ( ! V_36 ) {
F_27 ( V_25 , * V_42 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
F_28 ( V_2 -> V_46 , V_25 ) ;
continue;
}
V_36 -> V_106 = NULL ;
V_36 -> V_110 = V_36 ;
V_27 = F_8 ( V_25 ) ;
V_27 -> V_56 &= ~ V_187 ;
if ( ! V_6 -> V_135 )
V_27 -> V_56 &= ~ V_57 ;
if ( ! ( V_27 -> V_56 & V_57 ) ) {
V_36 -> V_63 . V_188 = 0 ;
return V_36 ;
}
V_36 -> V_63 . V_188 = V_189 | V_190 ;
V_29 = V_36 -> V_63 . V_29 ;
if ( ! F_64 ( V_6 -> V_64 , V_6 -> V_134 , V_29 ) )
break;
if ( V_6 -> V_72 > F_33 ( V_6 -> V_64 , V_29 ) ) {
struct V_59 V_60 = {} ;
struct V_9 V_58 ;
F_30 ( & V_58 ) ;
F_91 ( & V_36 -> V_10 , & V_58 ) ;
F_27 ( V_25 , * V_42 ) ;
F_31 ( V_2 , V_6 , V_29 ) ;
F_32 ( V_2 , V_36 , V_4 , & V_58 , & V_60 , 0 ) ;
continue;
}
return V_36 ;
}
return NULL ;
}
static bool
F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_9 * V_107 ,
struct V_35 * V_191 , struct V_111 * V_20 ,
int * V_192 )
{
#define F_93 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_35 * V_36 = V_191 , * V_193 = NULL ;
int V_96 = 0 , V_174 ;
T_1 V_154 = 0 , V_194 = 0 , V_195 = 0 ,
V_196 , V_197 = V_6 -> V_134 / 2 ;
struct V_26 * V_27 ;
struct V_23 * V_40 ;
struct V_24 * V_25 ;
bool V_198 = false ;
V_36 = V_191 ;
V_154 = F_78 ( V_2 , V_36 , V_6 ) ;
do {
V_25 = V_36 -> V_37 ;
V_40 = F_7 ( V_25 ) ;
V_196 = V_186 + V_40 -> V_199 ;
if ( V_96 ) {
if ( V_154 < V_194 + V_195 + V_196 ||
F_77 ( V_36 ) || V_96 >= V_197 )
break;
V_27 = F_8 ( V_36 -> V_37 ) ;
if ( ( V_27 -> V_56 & V_145 ) ||
! ( V_27 -> V_56 & V_57 ) )
break;
}
V_194 += V_195 + V_196 ;
V_174 = F_81 ( V_2 , V_6 , V_191 , V_40 -> V_199 ,
! V_96 ) ;
V_195 = F_93 ( V_196 ) + ( V_174 << 2 ) ;
V_96 ++ ;
V_36 -> V_106 = NULL ;
if ( ! V_40 -> V_62 )
F_37 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_63 . V_174 = V_174 ;
F_27 ( V_25 , V_20 ) ;
F_5 ( & V_36 -> V_10 , V_107 ) ;
if ( V_193 )
V_193 -> V_106 = V_36 ;
V_193 = V_36 ;
V_36 = F_89 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 ) {
V_198 = true ;
break;
}
} while ( F_20 ( V_6 ) );
V_36 = V_191 ;
V_36 -> V_110 = V_193 ;
if ( V_36 == V_193 ) {
V_194 = F_7 ( V_36 -> V_37 ) -> V_199 ;
V_36 -> V_63 . V_188 = V_189 ;
} else {
F_42 ( V_4 -> V_79 , V_200 ) ;
}
* V_192 = V_194 ;
return V_198 ;
#undef F_93
}
static V_99 F_94 ( struct V_1 * V_2 , T_2 V_170 , int V_201 ,
int V_171 , int V_173 , bool V_202 )
{
V_99 V_203 , V_167 , V_204 , V_168 ;
int V_172 ;
V_172 = F_88 ( V_170 ) ;
V_203 = ( V_201 << 3 ) + V_205 ;
V_167 = V_184 [ V_170 % 8 ] [ V_171 ] * V_172 ;
V_168 = ( V_203 + V_167 - 1 ) / V_167 ;
if ( ! V_173 )
V_204 = F_95 ( V_168 ) ;
else
V_204 = F_96 ( V_168 ) ;
V_204 += V_206 + V_207 + V_208 + V_209 + V_210 + F_97 ( V_172 ) ;
return V_204 ;
}
static int F_98 ( int V_211 , int V_212 , bool V_213 , bool V_214 )
{
int V_172 = F_88 ( V_212 ) ;
int V_215 , V_216 ;
int V_217 = 0 ;
V_211 -= V_206 + V_207 + V_208 + V_209 + V_210 + F_97 ( V_172 ) ;
V_215 = V_214 ? F_99 ( V_211 ) : F_100 ( V_211 ) ;
V_216 = V_215 * V_184 [ V_212 % 8 ] [ V_213 ] * V_172 ;
V_216 -= V_205 ;
V_217 = V_216 / 8 ;
if ( V_217 > 65532 )
V_217 = 65532 ;
return V_217 ;
}
void F_101 ( struct V_1 * V_2 , int V_218 , int V_219 )
{
T_1 * V_220 , * V_221 , * V_222 , * V_223 ;
int V_212 ;
if ( ! V_219 || V_219 > 4096 )
V_219 = 4096 ;
V_220 = V_2 -> V_43 . V_164 [ V_218 ] [ V_162 ] ;
V_221 = V_2 -> V_43 . V_164 [ V_218 ] [ V_224 ] ;
V_222 = V_2 -> V_43 . V_164 [ V_218 ] [ V_161 ] ;
V_223 = V_2 -> V_43 . V_164 [ V_218 ] [ V_225 ] ;
for ( V_212 = 0 ; V_212 < 32 ; V_212 ++ ) {
V_220 [ V_212 ] = F_98 ( V_219 , V_212 , false , false ) ;
V_221 [ V_212 ] = F_98 ( V_219 , V_212 , false , true ) ;
V_222 [ V_212 ] = F_98 ( V_219 , V_212 , true , false ) ;
V_223 [ V_212 ] = F_98 ( V_219 , V_212 , true , true ) ;
}
}
static void F_102 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_226 * V_39 , int V_227 , bool V_228 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_231 * V_232 = F_103 ( V_230 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_121 * V_38 ;
const struct V_233 * V_234 ;
struct V_75 * V_76 ;
struct V_23 * V_40 = F_7 ( V_36 -> V_37 ) ;
V_99 V_235 = V_2 -> V_46 -> V_236 -> V_237 ;
int V_125 ;
T_2 V_170 = 0 ;
V_25 = V_36 -> V_37 ;
V_27 = F_8 ( V_25 ) ;
V_38 = V_36 -> V_38 ;
V_76 = (struct V_75 * ) V_25 -> V_81 ;
V_39 -> V_238 = ! F_104 ( V_76 -> V_82 ) ;
V_39 -> V_239 = V_40 -> V_239 ;
for ( V_125 = 0 ; V_125 < F_14 ( V_36 -> V_38 ) ; V_125 ++ ) {
bool V_240 , V_241 , V_242 ;
int V_243 ;
if ( ! V_38 [ V_125 ] . V_74 || ( V_38 [ V_125 ] . V_150 < 0 ) )
continue;
V_170 = V_38 [ V_125 ] . V_150 ;
V_39 -> V_38 [ V_125 ] . V_244 = V_38 [ V_125 ] . V_74 ;
if ( F_74 ( V_36 ) && ! F_56 ( V_36 ) &&
( V_38 [ V_125 ] . V_56 & V_151 ) &&
F_47 ( V_235 != ( V_99 ) - 1 ) ) {
if ( ! V_235 || ( V_227 > V_235 ) )
V_228 = true ;
}
if ( V_228 || V_38 [ V_125 ] . V_56 & V_245 ) {
V_39 -> V_38 [ V_125 ] . V_246 |= V_247 ;
V_39 -> V_56 |= V_248 ;
} else if ( V_38 [ V_125 ] . V_56 & V_249 ) {
V_39 -> V_38 [ V_125 ] . V_246 |= V_247 ;
V_39 -> V_56 |= V_250 ;
}
if ( V_38 [ V_125 ] . V_56 & V_160 )
V_39 -> V_38 [ V_125 ] . V_246 |= V_251 ;
if ( V_38 [ V_125 ] . V_56 & V_163 )
V_39 -> V_38 [ V_125 ] . V_246 |= V_252 ;
V_241 = ! ! ( V_38 [ V_125 ] . V_56 & V_163 ) ;
V_240 = ! ! ( V_38 [ V_125 ] . V_56 & V_160 ) ;
V_242 = ! ! ( V_38 [ V_125 ] . V_56 & V_253 ) ;
if ( V_38 [ V_125 ] . V_56 & V_151 ) {
V_39 -> V_38 [ V_125 ] . V_254 = V_170 | 0x80 ;
V_39 -> V_38 [ V_125 ] . V_255 = F_105 ( V_2 ,
V_230 -> V_256 , V_39 -> V_38 [ V_125 ] . V_254 ) ;
V_39 -> V_38 [ V_125 ] . V_257 = F_94 ( V_2 , V_170 , V_227 ,
V_240 , V_241 , V_242 ) ;
if ( V_170 < 8 && ( V_27 -> V_56 & V_258 ) )
V_39 -> V_38 [ V_125 ] . V_246 |= V_259 ;
continue;
}
V_234 = & V_232 -> V_260 [ V_27 -> V_261 ] . V_262 [ V_38 [ V_125 ] . V_150 ] ;
if ( ( V_27 -> V_261 == V_263 ) &&
! ( V_234 -> V_56 & V_264 ) )
V_243 = V_265 ;
else
V_243 = V_266 ;
V_39 -> V_38 [ V_125 ] . V_254 = V_234 -> V_267 ;
if ( V_234 -> V_268 ) {
if ( V_38 [ V_125 ] . V_56 & V_253 )
V_39 -> V_38 [ V_125 ] . V_254 |= V_234 -> V_268 ;
} else {
V_242 = false ;
}
if ( V_36 -> V_63 . V_269 )
V_39 -> V_38 [ V_125 ] . V_255 = V_230 -> V_256 ;
else
V_39 -> V_38 [ V_125 ] . V_255 = F_105 ( V_2 ,
V_230 -> V_256 , V_39 -> V_38 [ V_125 ] . V_254 ) ;
V_39 -> V_38 [ V_125 ] . V_257 = F_106 ( V_2 -> V_91 ,
V_243 , V_234 -> V_270 * 100 , V_227 , V_170 , V_242 ) ;
}
if ( F_56 ( V_36 ) && ( V_227 > V_2 -> V_91 -> V_92 . V_271 ) )
V_39 -> V_56 &= ~ V_248 ;
if ( V_39 -> V_56 & V_248 )
V_39 -> V_56 &= ~ V_250 ;
}
static enum V_272 F_107 ( struct V_24 * V_25 )
{
struct V_75 * V_76 ;
enum V_272 V_273 ;
T_4 V_274 ;
V_76 = (struct V_75 * ) V_25 -> V_81 ;
V_274 = V_76 -> V_82 ;
if ( F_108 ( V_274 ) )
V_273 = V_275 ;
else if ( F_109 ( V_274 ) )
V_273 = V_276 ;
else if ( F_110 ( V_274 ) )
V_273 = V_277 ;
else if ( F_104 ( V_274 ) )
V_273 = V_278 ;
else
V_273 = V_279 ;
return V_273 ;
}
static void F_111 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , int V_227 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_35 * V_191 = NULL ;
struct V_226 V_39 ;
V_99 V_235 = V_2 -> V_46 -> V_236 -> V_237 ;
bool V_228 = false ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_280 = true ;
V_39 . V_281 = true ;
V_39 . V_282 = V_283 ;
V_39 . V_284 = V_4 -> V_79 ;
while ( V_36 ) {
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
bool V_285 = ! ! ( V_36 -> V_63 . V_188 & V_190 ) ;
V_39 . type = F_107 ( V_25 ) ;
if ( V_36 -> V_106 )
V_39 . V_286 = V_36 -> V_106 -> V_287 ;
else
V_39 . V_286 = ( V_2 -> V_288 ) ? V_36 -> V_287 : 0 ;
if ( ! V_191 ) {
V_191 = V_36 ;
if ( ! V_2 -> V_288 )
V_39 . V_56 = V_289 ;
if ( ( V_27 -> V_56 & V_187 ) ||
V_4 == V_2 -> V_43 . V_290 )
V_39 . V_56 |= V_291 ;
if ( V_27 -> V_56 & V_292 )
V_39 . V_56 |= V_293 ;
if ( V_27 -> V_56 & V_294 )
V_39 . V_56 |= V_295 ;
if ( V_36 -> V_63 . V_269 )
V_39 . V_56 |= ( V_99 ) V_36 -> V_63 . V_269 <<
V_296 ;
if ( V_285 && ( V_36 == V_191 ) &&
F_47 ( V_235 != ( V_99 ) - 1 ) ) {
if ( ! V_235 || ( V_227 > V_235 ) )
V_228 = true ;
}
if ( ! V_285 )
V_227 = V_40 -> V_199 ;
F_102 ( V_2 , V_36 , & V_39 , V_227 , V_228 ) ;
}
V_39 . V_297 [ 0 ] = V_36 -> V_85 ;
V_39 . V_298 [ 0 ] = V_25 -> V_227 ;
V_39 . V_299 = V_40 -> V_199 ;
V_39 . V_176 = V_40 -> V_176 ;
V_39 . V_300 = V_40 -> V_300 ;
if ( V_285 ) {
if ( V_36 == V_191 )
V_39 . V_285 = V_301 ;
else if ( V_36 == V_191 -> V_110 )
V_39 . V_285 = V_302 ;
else
V_39 . V_285 = V_303 ;
V_39 . V_174 = V_36 -> V_63 . V_174 ;
V_39 . V_192 = V_227 ;
}
if ( V_36 == V_191 -> V_110 )
V_191 = NULL ;
F_112 ( V_230 , V_36 -> V_90 , & V_39 ) ;
V_36 = V_36 -> V_106 ;
}
}
static void
F_113 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_9 * V_107 ,
struct V_35 * V_191 , struct V_111 * V_20 )
{
struct V_35 * V_36 = V_191 , * V_193 = NULL ;
struct V_24 * V_25 ;
int V_96 = 0 ;
do {
struct V_26 * V_27 ;
V_25 = V_36 -> V_37 ;
V_96 ++ ;
F_27 ( V_25 , V_20 ) ;
F_5 ( & V_36 -> V_10 , V_107 ) ;
if ( V_193 )
V_193 -> V_106 = V_36 ;
V_193 = V_36 ;
if ( V_96 >= 2 )
break;
V_36 = F_89 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
V_27 = F_8 ( V_36 -> V_37 ) ;
if ( V_27 -> V_56 & V_57 )
break;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
} while ( 1 );
}
static bool F_114 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , bool * V_304 )
{
struct V_35 * V_36 ;
struct V_26 * V_27 ;
struct V_111 * V_20 ;
struct V_9 V_107 ;
int V_192 = 0 ;
bool V_285 , V_305 = true ;
if ( ! F_20 ( V_6 ) )
return false ;
F_30 ( & V_107 ) ;
V_36 = F_89 ( V_2 , V_4 , V_6 , & V_20 ) ;
if ( ! V_36 )
return false ;
V_27 = F_8 ( V_36 -> V_37 ) ;
V_285 = ! ! ( V_27 -> V_56 & V_57 ) ;
if ( ( V_285 && V_4 -> V_149 >= V_306 ) ||
( ! V_285 && V_4 -> V_148 >= V_307 ) ) {
* V_304 = true ;
return false ;
}
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( V_285 )
V_305 = F_92 ( V_2 , V_4 , V_6 , & V_107 , V_36 ,
V_20 , & V_192 ) ;
else
F_113 ( V_2 , V_4 , V_6 , & V_107 , V_36 , V_20 ) ;
if ( F_48 ( & V_107 ) )
return false ;
if ( V_6 -> V_8 -> V_142 || V_6 -> V_13 -> V_308 ) {
V_6 -> V_8 -> V_142 = false ;
V_27 -> V_56 |= V_187 ;
}
F_111 ( V_2 , V_36 , V_4 , V_192 ) ;
F_115 ( V_2 , V_4 , & V_107 , false ) ;
return true ;
}
int F_116 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_6 , T_1 * V_309 )
{
struct V_5 * V_310 ;
struct V_3 * V_4 ;
struct V_50 * V_13 ;
T_2 V_311 ;
V_13 = (struct V_50 * ) V_30 -> V_15 ;
V_310 = F_19 ( V_13 , V_6 ) ;
V_4 = V_310 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_30 -> V_312 . V_313 ) {
V_13 -> V_165 = ( 1 << ( V_314 +
V_30 -> V_312 . V_315 ) ) - 1 ;
V_311 = F_117 ( V_30 -> V_312 . V_316 ) ;
V_13 -> V_183 = V_311 ;
}
F_24 ( V_2 , V_310 ) ;
V_310 -> V_135 = true ;
* V_309 = V_310 -> V_64 = V_310 -> V_317 ;
V_310 -> V_72 = - 1 ;
memset ( V_310 -> V_69 , 0 , sizeof( V_310 -> V_69 ) ) ;
V_310 -> V_67 = V_310 -> V_70 = 0 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 , struct V_34 * V_30 , T_1 V_6 )
{
struct V_50 * V_13 = (struct V_50 * ) V_30 -> V_15 ;
struct V_5 * V_310 = F_19 ( V_13 , V_6 ) ;
struct V_3 * V_4 = V_310 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_310 -> V_135 = false ;
F_29 ( V_2 , V_310 ) ;
F_24 ( V_2 , V_310 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_119 ( struct V_34 * V_30 , struct V_1 * V_2 ,
struct V_50 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_318 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_319 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_19 ) {
F_2 ( V_2 , V_4 ) ;
continue;
}
V_318 = F_20 ( V_6 ) ;
V_6 -> V_19 = false ;
F_51 ( & V_6 -> V_10 ) ;
if ( V_8 -> V_19 ) {
V_8 -> V_19 = false ;
F_51 ( & V_8 -> V_10 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_69 ( V_30 , V_22 , V_318 ) ;
}
}
void F_120 ( struct V_1 * V_2 , struct V_50 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_319 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_142 = true ;
if ( F_20 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_121 ( struct V_1 * V_2 , struct V_34 * V_30 ,
T_1 V_22 )
{
struct V_5 * V_6 ;
struct V_50 * V_13 ;
struct V_3 * V_4 ;
V_13 = (struct V_50 * ) V_30 -> V_15 ;
V_6 = F_19 ( V_13 , V_22 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_134 = V_320 << V_30 -> V_312 . V_315 ;
if ( F_20 ( V_6 ) ) {
F_4 ( V_2 , V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_122 ( struct V_108 * V_46 ,
struct V_34 * V_30 ,
T_1 V_321 , int V_96 ,
enum V_322 V_323 ,
bool V_324 )
{
struct V_1 * V_2 = V_46 -> V_325 ;
struct V_50 * V_13 = (struct V_50 * ) V_30 -> V_15 ;
struct V_3 * V_4 = V_2 -> V_43 . V_290 ;
struct V_26 * V_39 ;
struct V_9 V_107 ;
struct V_35 * V_326 = NULL , * V_36 ;
struct V_111 * V_20 ;
int V_327 = 0 ;
int V_125 ;
F_30 ( & V_107 ) ;
for ( V_125 = 0 ; V_321 && V_96 ; V_125 ++ , V_321 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_321 & 1 ) )
continue;
V_6 = F_19 ( V_13 , V_125 ) ;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( V_96 > 0 ) {
V_36 = F_89 ( V_2 , V_2 -> V_43 . V_290 , V_6 , & V_20 ) ;
if ( ! V_36 )
break;
F_27 ( V_36 -> V_37 , V_20 ) ;
F_5 ( & V_36 -> V_10 , & V_107 ) ;
F_12 ( V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_30 , V_36 ) ;
if ( F_74 ( V_36 ) ) {
F_37 ( V_2 , V_6 , V_36 ) ;
V_36 -> V_63 . V_188 &= ~ V_190 ;
}
if ( V_326 )
V_326 -> V_106 = V_36 ;
V_326 = V_36 ;
V_96 -- ;
V_327 ++ ;
F_42 ( V_4 -> V_79 , V_328 ) ;
if ( V_13 -> V_30 && ! F_20 ( V_6 ) )
F_69 ( V_13 -> V_30 , V_125 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_48 ( & V_107 ) )
return;
V_39 = F_8 ( V_326 -> V_37 ) ;
V_39 -> V_56 |= V_139 ;
V_36 = F_50 ( & V_107 , struct V_35 , V_10 ) ;
F_1 ( V_2 , V_4 ) ;
F_111 ( V_2 , V_36 , V_4 , 0 ) ;
F_115 ( V_2 , V_4 , & V_107 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_123 ( struct V_1 * V_2 , int V_329 , int V_330 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_331 V_332 ;
static const int V_333 [] = {
[ V_334 ] = V_335 ,
[ V_336 ] = V_337 ,
[ V_338 ] = V_339 ,
[ V_340 ] = V_341 ,
} ;
int V_79 , V_125 ;
memset ( & V_332 , 0 , sizeof( V_332 ) ) ;
V_332 . V_342 = V_333 [ V_330 ] ;
V_332 . V_343 = V_344 ;
V_332 . V_345 = V_344 ;
V_332 . V_346 = V_344 ;
V_332 . V_347 = 0 ;
if ( V_230 -> V_92 . V_178 & V_179 ) {
V_332 . V_348 = V_349 ;
} else {
if ( V_329 == V_350 )
V_332 . V_348 = V_351 ;
else
V_332 . V_348 = V_352 |
V_351 ;
}
V_79 = F_124 ( V_230 , V_329 , & V_332 ) ;
if ( V_79 == - 1 ) {
return NULL ;
}
if ( ! F_125 ( V_2 , V_79 ) ) {
struct V_3 * V_4 = & V_2 -> V_43 . V_4 [ V_79 ] ;
V_4 -> V_79 = V_79 ;
V_4 -> V_157 = - 1 ;
V_4 -> V_353 = NULL ;
F_63 ( & V_4 -> V_354 ) ;
F_30 ( & V_4 -> V_355 ) ;
F_126 ( & V_4 -> V_356 ) ;
V_4 -> V_148 = 0 ;
V_4 -> V_149 = 0 ;
V_4 -> V_147 = false ;
V_2 -> V_43 . V_357 |= 1 << V_79 ;
V_4 -> V_358 = V_4 -> V_359 = 0 ;
for ( V_125 = 0 ; V_125 < V_360 ; V_125 ++ )
F_30 ( & V_4 -> V_361 [ V_125 ] ) ;
}
return & V_2 -> V_43 . V_4 [ V_79 ] ;
}
int F_127 ( struct V_1 * V_2 , int V_362 ,
struct V_331 * V_363 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
int error = 0 ;
struct V_331 V_332 ;
F_128 ( V_2 -> V_43 . V_4 [ V_362 ] . V_79 != V_362 ) ;
F_129 ( V_230 , V_362 , & V_332 ) ;
V_332 . V_343 = V_363 -> V_343 ;
V_332 . V_345 = V_363 -> V_345 ;
V_332 . V_346 = V_363 -> V_346 ;
V_332 . V_364 = V_363 -> V_364 ;
V_332 . V_365 = V_363 -> V_365 ;
if ( ! F_130 ( V_230 , V_362 , & V_332 ) ) {
F_131 ( F_103 ( V_2 -> V_91 ) ,
L_1 , V_362 ) ;
error = - V_366 ;
} else {
F_132 ( V_230 , V_362 ) ;
}
return error ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_331 V_332 ;
struct V_367 * V_368 = & V_2 -> V_369 -> V_370 ;
int V_362 = V_2 -> V_370 . V_371 -> V_79 ;
F_129 ( V_2 -> V_91 , V_362 , & V_332 ) ;
V_332 . V_365 = ( F_134 ( V_368 -> V_372 ) *
V_373 ) / 100 ;
F_127 ( V_2 , V_362 , & V_332 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_35 * V_36 , * V_374 ;
struct V_9 V_58 ;
struct V_59 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_123 = V_124 ;
F_30 ( & V_58 ) ;
while ( ! F_48 ( V_10 ) ) {
V_36 = F_50 ( V_10 , struct V_35 , V_10 ) ;
if ( V_36 -> V_63 . V_94 ) {
F_51 ( & V_36 -> V_10 ) ;
F_52 ( V_2 , V_36 ) ;
continue;
}
V_374 = V_36 -> V_110 ;
F_136 ( & V_58 , V_10 , & V_374 -> V_10 ) ;
F_75 ( V_2 , V_4 , & V_60 , V_36 , & V_58 ) ;
}
}
void F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_91 -> V_92 . V_178 & V_179 ) {
int V_150 = V_4 -> V_359 ;
while ( ! F_48 ( & V_4 -> V_361 [ V_150 ] ) ) {
F_135 ( V_2 , V_4 , & V_4 -> V_361 [ V_150 ] ) ;
F_36 ( V_150 , V_360 ) ;
}
V_4 -> V_359 = V_150 ;
}
V_4 -> V_353 = NULL ;
V_4 -> V_147 = false ;
F_135 ( V_2 , V_4 , & V_4 -> V_355 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_138 ( struct V_1 * V_2 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_3 * V_4 ;
int V_125 ;
V_99 V_375 = 0 ;
if ( F_35 ( V_376 , & V_232 -> V_377 ) )
return true ;
F_139 ( V_230 ) ;
for ( V_125 = 0 ; V_125 < V_378 ; V_125 ++ ) {
if ( ! F_125 ( V_2 , V_125 ) )
continue;
if ( ! V_2 -> V_43 . V_4 [ V_125 ] . V_148 )
continue;
if ( F_140 ( V_230 , V_2 -> V_43 . V_4 [ V_125 ] . V_79 ) )
V_375 |= F_141 ( V_125 ) ;
}
if ( V_375 )
F_131 ( V_232 , L_2 , V_375 ) ;
for ( V_125 = 0 ; V_125 < V_378 ; V_125 ++ ) {
if ( ! F_125 ( V_2 , V_125 ) )
continue;
V_4 = & V_2 -> V_43 . V_4 [ V_125 ] ;
V_4 -> V_48 = false ;
F_137 ( V_2 , V_4 ) ;
}
return ! V_375 ;
}
void F_142 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_143 ( V_2 -> V_91 , V_4 -> V_79 ) ;
V_2 -> V_43 . V_357 &= ~ ( 1 << V_4 -> V_79 ) ;
}
void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_7 * V_8 , * V_379 ;
struct V_5 * V_6 , * V_380 ;
struct V_9 * V_381 ;
bool V_327 = false ;
if ( V_4 -> V_157 < 0 )
return;
F_46 ( & V_2 -> V_382 ) ;
V_381 = & V_2 -> V_369 -> V_21 [ V_4 -> V_157 ] ;
F_49 ( & V_2 -> V_382 ) ;
if ( F_35 ( V_383 , & V_232 -> V_377 ) ||
F_48 ( V_381 ) )
return;
F_46 ( & V_2 -> V_382 ) ;
F_59 () ;
V_379 = F_144 ( V_381 -> V_77 , struct V_7 , V_10 ) ;
while ( ! F_48 ( V_381 ) ) {
bool V_304 = false ;
if ( V_2 -> V_369 -> V_48 )
break;
V_8 = F_50 ( V_381 , struct V_7 , V_10 ) ;
V_380 = F_144 ( V_8 -> V_20 . V_77 , struct V_5 , V_10 ) ;
F_51 ( & V_8 -> V_10 ) ;
V_8 -> V_19 = false ;
while ( ! F_48 ( & V_8 -> V_20 ) ) {
V_6 = F_50 ( & V_8 -> V_20 , struct V_5 ,
V_10 ) ;
F_51 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
if ( F_114 ( V_2 , V_4 , V_6 , & V_304 ) )
V_327 = true ;
if ( F_20 ( V_6 ) )
F_4 ( V_2 , V_4 , V_6 ) ;
if ( V_304 || V_6 == V_380 )
break;
}
if ( ! F_48 ( & V_8 -> V_20 ) && ! V_8 -> V_19 ) {
V_8 -> V_19 = true ;
F_5 ( & V_8 -> V_10 , V_381 ) ;
}
if ( V_304 )
break;
if ( V_8 == V_379 ) {
if ( ! V_327 )
break;
V_327 = false ;
V_379 = F_144 ( V_381 -> V_77 ,
struct V_7 , V_10 ) ;
}
}
F_61 () ;
F_49 ( & V_2 -> V_382 ) ;
}
void F_145 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_384 ; V_125 ++ ) {
V_4 = V_2 -> V_43 . V_44 [ V_125 ] ;
F_46 ( & V_4 -> V_356 ) ;
F_76 ( V_2 , V_4 ) ;
F_49 ( & V_4 -> V_356 ) ;
}
}
static void F_115 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_385 , bool V_386 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_231 * V_232 = F_103 ( V_230 ) ;
struct V_35 * V_36 , * V_109 ;
bool V_387 = false ;
bool V_388 ;
if ( F_48 ( V_385 ) )
return;
V_388 = ! ! ( V_230 -> V_92 . V_178 & V_179 ) ;
V_36 = F_50 ( V_385 , struct V_35 , V_10 ) ;
V_109 = F_144 ( V_385 -> V_77 , struct V_35 , V_10 ) ;
F_146 ( V_232 , V_389 , L_3 ,
V_4 -> V_79 , V_4 -> V_148 ) ;
if ( V_388 && F_48 ( & V_4 -> V_361 [ V_4 -> V_358 ] ) ) {
F_147 ( V_385 , & V_4 -> V_361 [ V_4 -> V_358 ] ) ;
F_36 ( V_4 -> V_358 , V_360 ) ;
V_387 = true ;
} else {
F_147 ( V_385 , & V_4 -> V_355 ) ;
if ( V_4 -> V_353 ) {
F_148 ( V_230 , V_4 -> V_353 , V_36 -> V_287 ) ;
F_146 ( V_232 , V_390 , L_4 ,
V_4 -> V_79 , V_4 -> V_353 ,
F_149 ( V_36 -> V_287 ) , V_36 -> V_90 ) ;
} else if ( ! V_388 )
V_387 = true ;
V_4 -> V_353 = V_109 -> V_90 ;
}
if ( V_387 ) {
F_42 ( V_4 -> V_79 , V_387 ) ;
F_150 ( V_230 , V_4 -> V_79 , V_36 -> V_287 ) ;
F_146 ( V_232 , V_390 , L_5 ,
V_4 -> V_79 , F_149 ( V_36 -> V_287 ) , V_36 -> V_90 ) ;
}
if ( ! V_388 || V_2 -> V_288 ) {
F_42 ( V_4 -> V_79 , V_391 ) ;
F_151 ( V_230 , V_4 -> V_79 ) ;
}
if ( ! V_386 ) {
while ( V_36 ) {
V_4 -> V_148 ++ ;
if ( F_73 ( V_36 ) )
V_4 -> V_149 ++ ;
V_109 = V_36 -> V_110 ;
V_36 = V_109 -> V_106 ;
V_109 -> V_106 = NULL ;
}
}
}
static void F_152 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_24 * V_25 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_9 V_58 ;
struct V_35 * V_36 = V_40 -> V_36 ;
F_30 ( & V_58 ) ;
F_5 ( & V_36 -> V_10 , & V_58 ) ;
V_36 -> V_63 . V_188 = 0 ;
if ( V_6 && ( V_27 -> V_56 & V_57 ) ) {
V_36 -> V_63 . V_188 = V_189 ;
F_37 ( V_2 , V_6 , V_36 ) ;
}
V_36 -> V_106 = NULL ;
V_36 -> V_110 = V_36 ;
F_111 ( V_2 , V_36 , V_4 , V_40 -> V_199 ) ;
F_115 ( V_2 , V_4 , & V_58 , false ) ;
F_42 ( V_4 -> V_79 , V_392 ) ;
}
static void F_153 ( struct V_108 * V_46 ,
struct V_34 * V_30 ,
struct V_24 * V_25 ,
int V_199 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_393 * V_394 = V_27 -> V_138 . V_394 ;
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
const struct V_233 * V_234 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_50 * V_13 = NULL ;
enum V_395 V_300 ;
bool V_396 = false ;
if ( V_27 -> V_138 . V_14 &&
V_27 -> V_138 . V_14 -> V_397 . V_398 )
V_396 = true ;
V_234 = F_154 ( V_46 , V_27 ) ;
V_300 = F_155 ( V_25 ) ;
if ( V_30 )
V_13 = (struct V_50 * ) V_30 -> V_15 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_4 = - 1 ;
if ( V_394 )
V_40 -> V_176 = V_394 -> V_399 ;
else if ( V_13 && F_156 ( V_76 -> V_82 ) && V_13 -> V_400 > 0 )
V_40 -> V_176 = V_13 -> V_400 ;
else
V_40 -> V_176 = V_177 ;
V_40 -> V_300 = V_300 ;
V_40 -> V_199 = V_199 ;
if ( ! V_234 )
return;
V_40 -> V_239 = V_234 -> V_267 ;
if ( V_396 )
V_40 -> V_239 |= V_234 -> V_268 ;
}
T_2 F_105 ( struct V_1 * V_2 , T_2 V_401 , V_99 V_234 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_402 * V_403 = V_230 -> V_403 ;
if ( ( V_230 -> V_92 . V_178 & V_404 ) && F_157 ( V_403 ) &&
( V_401 == 0x7 ) && ( V_234 < 0x90 ) )
return 0x3 ;
else if ( F_158 ( V_230 ) && F_159 ( V_230 ) &&
F_160 ( V_234 ) )
return 0x2 ;
else
return V_401 ;
}
static struct V_35 * F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
struct V_35 * V_36 ;
int V_405 ;
T_1 V_29 ;
V_36 = F_45 ( V_2 ) ;
if ( ! V_36 ) {
F_146 ( V_232 , V_390 , L_6 ) ;
return NULL ;
}
F_54 ( V_36 ) ;
if ( V_6 && F_161 ( V_76 -> V_82 ) ) {
V_405 = F_162 ( V_76 -> V_406 ) & V_407 ;
V_29 = V_6 -> V_317 ;
V_76 -> V_406 = F_43 ( V_6 -> V_317 << V_32 ) ;
if ( V_405 )
V_76 -> V_406 |= F_43 ( V_405 ) ;
if ( ! F_163 ( V_76 -> V_82 ) )
F_36 ( V_6 -> V_317 , V_71 ) ;
V_36 -> V_63 . V_29 = V_29 ;
}
V_36 -> V_37 = V_25 ;
V_36 -> V_85 = F_164 ( V_2 -> V_84 , V_25 -> V_81 ,
V_25 -> V_227 , V_86 ) ;
if ( F_47 ( F_165 ( V_2 -> V_84 , V_36 -> V_85 ) ) ) {
V_36 -> V_37 = NULL ;
V_36 -> V_85 = 0 ;
F_131 ( F_103 ( V_2 -> V_91 ) ,
L_7 ) ;
F_52 ( V_2 , V_36 ) ;
return NULL ;
}
V_40 -> V_36 = V_36 ;
return V_36 ;
}
static int F_166 ( struct V_108 * V_46 , struct V_24 * V_25 ,
struct V_408 * V_409 )
{
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_409 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_138 . V_14 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_46 -> V_325 ;
int V_153 = V_25 -> V_227 + V_410 ;
int V_411 , V_412 ;
if ( V_30 )
V_409 -> V_13 = (struct V_50 * ) V_30 -> V_15 ;
else if ( V_14 && F_156 ( V_76 -> V_82 ) ) {
V_12 = ( void * ) V_14 -> V_15 ;
V_409 -> V_13 = & V_12 -> V_413 ;
}
if ( V_39 -> V_138 . V_394 )
V_153 += V_39 -> V_138 . V_394 -> V_414 ;
if ( V_39 -> V_56 & V_415 ) {
if ( V_39 -> V_56 & V_416 )
V_2 -> V_43 . V_417 += 0x10 ;
V_76 -> V_406 &= F_43 ( V_407 ) ;
V_76 -> V_406 |= F_43 ( V_2 -> V_43 . V_417 ) ;
}
if ( ( V_14 && V_14 -> type != V_418 &&
V_14 -> type != V_419 ) ||
! F_156 ( V_76 -> V_82 ) )
V_39 -> V_56 |= V_187 ;
V_411 = F_167 ( V_76 -> V_82 ) ;
V_412 = V_411 & 3 ;
if ( V_412 && V_25 -> V_227 > V_411 ) {
if ( F_168 ( V_25 ) < V_412 )
return - V_420 ;
F_169 ( V_25 , V_412 ) ;
memmove ( V_25 -> V_81 , V_25 -> V_81 + V_412 , V_411 ) ;
}
F_153 ( V_46 , V_30 , V_25 , V_153 ) ;
return 0 ;
}
int F_170 ( struct V_108 * V_46 , struct V_24 * V_25 ,
struct V_408 * V_409 )
{
struct V_75 * V_76 ;
struct V_26 * V_39 = F_8 ( V_25 ) ;
struct V_34 * V_30 = V_409 -> V_30 ;
struct V_33 * V_14 = V_39 -> V_138 . V_14 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_11 * V_12 = NULL ;
struct V_1 * V_2 = V_46 -> V_325 ;
struct V_3 * V_4 = V_409 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_36 ;
bool V_218 ;
int V_42 , V_41 ;
int V_421 ;
if ( V_14 )
V_12 = ( void * ) V_14 -> V_15 ;
if ( V_39 -> V_56 & V_422 )
V_409 -> V_423 = true ;
V_421 = F_166 ( V_46 , V_25 , V_409 ) ;
if ( V_421 )
return V_421 ;
V_76 = (struct V_75 * ) V_25 -> V_81 ;
V_42 = F_171 ( V_25 ) ;
V_41 = ( V_39 -> V_41 >= V_2 -> V_46 -> V_47 - 2 ) ? V_42 : V_39 -> V_41 ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_43 . V_44 [ V_42 ] ) {
V_40 -> V_4 = V_42 ;
if ( ++ V_4 -> V_45 > V_2 -> V_43 . V_49 [ V_42 ] &&
! V_4 -> V_48 ) {
F_172 ( V_2 -> V_46 , V_41 ) ;
V_4 -> V_48 = true ;
}
}
V_218 = F_161 ( V_76 -> V_82 ) ;
if ( ( ( V_12 && V_12 -> V_18 != V_2 -> V_369 ) ||
V_2 -> V_369 -> V_48 ) && ! V_409 -> V_423 ) {
if ( ! V_409 -> V_13 )
V_409 -> V_13 = & V_12 -> V_413 ;
V_39 -> V_56 &= ~ V_424 ;
V_218 = true ;
}
if ( V_409 -> V_13 && V_218 )
V_6 = F_18 ( V_2 , V_409 -> V_13 , V_25 ) ;
if ( V_39 -> V_56 & ( V_424 |
V_422 ) ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_43 . V_290 ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_409 -> V_13 && V_218 ) {
F_16 ( V_6 -> V_8 -> V_4 != V_409 -> V_4 ) ;
if ( V_39 -> V_56 & V_187 )
V_6 -> V_8 -> V_142 = true ;
F_42 ( V_4 -> V_79 , V_425 ) ;
F_68 ( & V_6 -> V_53 , V_25 ) ;
if ( ! V_409 -> V_13 -> V_137 )
F_4 ( V_2 , V_4 , V_6 ) ;
F_76 ( V_2 , V_4 ) ;
goto V_426;
}
V_36 = F_26 ( V_2 , V_4 , V_6 , V_25 ) ;
if ( ! V_36 ) {
F_15 ( V_2 , V_4 , V_25 ) ;
if ( V_409 -> V_427 )
F_173 ( V_25 ) ;
else
F_28 ( V_2 -> V_46 , V_25 ) ;
goto V_426;
}
V_36 -> V_63 . V_269 = V_409 -> V_427 ;
if ( V_409 -> V_427 )
V_36 -> V_63 . V_428 = V_429 ;
F_12 ( V_14 , V_30 , V_36 ) ;
F_152 ( V_2 , V_4 , V_6 , V_25 ) ;
V_426:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_174 ( struct V_108 * V_46 , struct V_33 * V_14 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_46 -> V_325 ;
struct V_408 V_409 = {
. V_4 = V_2 -> V_370 . V_371
} ;
struct V_226 V_39 = {} ;
struct V_75 * V_76 ;
struct V_35 * V_326 = NULL ;
struct V_35 * V_36 ;
F_175 ( V_107 ) ;
int V_204 = 0 ;
int V_430 ;
V_430 =
V_2 -> V_369 -> V_370 . V_372 * 1000 *
V_2 -> V_369 -> V_370 . V_431 / V_432 ;
do {
struct V_23 * V_40 = F_7 ( V_25 ) ;
if ( F_166 ( V_46 , V_25 , & V_409 ) )
break;
V_36 = F_26 ( V_2 , V_409 . V_4 , NULL , V_25 ) ;
if ( ! V_36 )
break;
V_36 -> V_110 = V_36 ;
F_12 ( V_14 , NULL , V_36 ) ;
F_102 ( V_2 , V_36 , & V_39 , V_40 -> V_199 , false ) ;
V_204 += V_39 . V_38 [ 0 ] . V_257 ;
if ( V_326 )
V_326 -> V_106 = V_36 ;
F_5 ( & V_36 -> V_10 , & V_107 ) ;
V_326 = V_36 ;
V_25 = NULL ;
if ( V_204 > V_430 )
break;
V_25 = F_176 ( V_46 , V_14 ) ;
} while( V_25 );
if ( V_25 )
F_28 ( V_46 , V_25 ) ;
if ( F_48 ( & V_107 ) )
return;
V_36 = F_50 ( & V_107 , struct V_35 , V_10 ) ;
V_76 = (struct V_75 * ) V_36 -> V_37 -> V_81 ;
if ( V_76 -> V_82 & V_433 ) {
V_76 -> V_82 &= ~ V_433 ;
F_44 ( V_2 -> V_84 , V_36 -> V_85 ,
sizeof( * V_76 ) , V_86 ) ;
}
F_1 ( V_2 , V_409 . V_4 ) ;
F_111 ( V_2 , V_36 , V_409 . V_4 , 0 ) ;
F_115 ( V_2 , V_409 . V_4 , & V_107 , false ) ;
F_42 ( V_409 . V_4 -> V_79 , V_392 ) ;
F_2 ( V_2 , V_409 . V_4 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_24 * V_25 ,
int V_434 , struct V_3 * V_4 )
{
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
int V_411 , V_412 ;
unsigned long V_56 ;
F_146 ( V_232 , V_390 , L_8 , V_25 ) ;
if ( V_2 -> V_91 -> V_435 )
F_177 ( V_436 , & V_2 -> V_91 -> V_435 -> V_437 ) ;
if ( ! ( V_434 & V_73 ) )
V_27 -> V_56 |= V_438 ;
V_411 = F_167 ( V_76 -> V_82 ) ;
V_412 = V_411 & 3 ;
if ( V_412 && V_25 -> V_227 > V_411 + V_412 ) {
memmove ( V_25 -> V_81 + V_412 , V_25 -> V_81 , V_411 ) ;
F_178 ( V_25 , V_412 ) ;
}
F_179 ( & V_2 -> V_439 , V_56 ) ;
if ( ( V_2 -> V_440 & V_441 ) && ! V_4 -> V_148 ) {
V_2 -> V_440 &= ~ V_441 ;
F_146 ( V_232 , V_442 ,
L_9 ,
V_2 -> V_440 & ( V_443 |
V_444 |
V_445 |
V_441 ) ) ;
}
F_180 ( & V_2 -> V_439 , V_56 ) ;
F_68 ( & V_4 -> V_354 , V_25 ) ;
F_15 ( V_2 , V_4 , V_25 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 , struct V_9 * V_107 ,
struct V_59 * V_60 , int V_95 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
unsigned long V_56 ;
int V_434 = 0 ;
if ( ! V_95 )
V_434 |= V_73 ;
if ( V_60 -> V_123 & V_140 )
V_27 -> V_56 |= V_446 ;
F_181 ( V_2 -> V_84 , V_36 -> V_85 , V_25 -> V_227 , V_86 ) ;
V_36 -> V_85 = 0 ;
if ( V_2 -> V_288 )
goto V_447;
if ( V_36 -> V_63 . V_269 ) {
if ( F_182 ( V_429 ,
V_36 -> V_63 . V_428 +
F_183 ( V_448 ) ) )
F_173 ( V_25 ) ;
else
F_184 ( & V_2 -> V_449 ) ;
} else {
F_185 ( V_2 , V_36 , V_60 , V_4 , V_434 ) ;
F_40 ( V_2 , V_25 , V_434 , V_4 ) ;
}
V_447:
V_36 -> V_37 = NULL ;
F_179 ( & V_2 -> V_43 . V_87 , V_56 ) ;
F_147 ( V_107 , & V_2 -> V_43 . V_88 ) ;
F_180 ( & V_2 -> V_43 . V_87 , V_56 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_59 * V_60 , int V_96 , int V_97 ,
int V_95 )
{
struct V_24 * V_25 = V_36 -> V_37 ;
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_108 * V_46 = V_2 -> V_46 ;
struct V_229 * V_230 = V_2 -> V_91 ;
T_2 V_125 , V_450 ;
if ( V_95 )
V_27 -> V_451 . V_452 = V_60 -> V_453 ;
V_450 = V_60 -> V_127 ;
F_16 ( V_450 >= V_46 -> V_454 ) ;
if ( V_27 -> V_56 & V_57 ) {
V_27 -> V_56 |= V_455 ;
F_128 ( V_97 > V_96 ) ;
}
V_27 -> V_451 . V_456 = V_96 ;
V_27 -> V_451 . V_457 = V_96 - V_97 ;
if ( ( V_60 -> V_123 & V_140 ) == 0 &&
( V_27 -> V_56 & V_292 ) == 0 ) {
if ( F_47 ( V_60 -> V_130 & ( V_458 |
V_459 ) ) &&
F_156 ( V_76 -> V_82 ) &&
V_230 -> V_460 >= V_2 -> V_91 -> V_461 . V_462 )
V_27 -> V_451 . V_38 [ V_450 ] . V_74 =
V_46 -> V_463 ;
}
for ( V_125 = V_450 + 1 ; V_125 < V_46 -> V_454 ; V_125 ++ ) {
V_27 -> V_451 . V_38 [ V_125 ] . V_74 = 0 ;
V_27 -> V_451 . V_38 [ V_125 ] . V_150 = - 1 ;
}
V_27 -> V_451 . V_38 [ V_450 ] . V_74 = V_60 -> V_126 + 1 ;
}
static void F_186 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_231 * V_232 = F_103 ( V_230 ) ;
struct V_35 * V_36 , * V_374 , * V_464 = NULL ;
struct V_9 V_58 ;
struct V_465 * V_466 ;
struct V_59 V_60 ;
int V_451 ;
F_146 ( V_232 , V_389 , L_10 ,
V_4 -> V_79 , F_187 ( V_2 -> V_91 , V_4 -> V_79 ) ,
V_4 -> V_353 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_35 ( V_383 , & V_232 -> V_377 ) )
break;
if ( F_48 ( & V_4 -> V_355 ) ) {
V_4 -> V_353 = NULL ;
F_76 ( V_2 , V_4 ) ;
break;
}
V_36 = F_50 ( & V_4 -> V_355 , struct V_35 , V_10 ) ;
V_464 = NULL ;
if ( V_36 -> V_63 . V_94 ) {
V_464 = V_36 ;
if ( F_188 ( & V_464 -> V_10 , & V_4 -> V_355 ) )
break;
V_36 = F_144 ( V_464 -> V_10 . V_467 , struct V_35 ,
V_10 ) ;
}
V_374 = V_36 -> V_110 ;
V_466 = V_374 -> V_90 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_451 = F_189 ( V_230 , V_466 , & V_60 ) ;
if ( V_451 == - V_468 )
break;
F_42 ( V_4 -> V_79 , V_469 ) ;
V_374 -> V_63 . V_94 = true ;
F_30 ( & V_58 ) ;
if ( ! F_190 ( & V_374 -> V_10 ) )
F_136 ( & V_58 ,
& V_4 -> V_355 , V_374 -> V_10 . V_77 ) ;
if ( V_464 ) {
F_51 ( & V_464 -> V_10 ) ;
F_52 ( V_2 , V_464 ) ;
}
F_75 ( V_2 , V_4 , & V_60 , V_36 , & V_58 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_191 ( struct V_1 * V_2 )
{
struct V_229 * V_230 = V_2 -> V_91 ;
V_99 V_470 = ( ( 1 << V_378 ) - 1 ) & V_230 -> V_471 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_378 ; V_125 ++ ) {
if ( F_125 ( V_2 , V_125 ) && ( V_470 & ( 1 << V_125 ) ) )
F_186 ( V_2 , & V_2 -> V_43 . V_4 [ V_125 ] ) ;
}
}
void F_192 ( struct V_1 * V_2 )
{
struct V_59 V_60 ;
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_229 * V_230 = V_2 -> V_91 ;
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_374 ;
struct V_9 V_58 ;
struct V_9 * V_472 ;
int V_451 ;
for (; ; ) {
if ( F_35 ( V_383 , & V_232 -> V_377 ) )
break;
V_451 = F_189 ( V_230 , NULL , ( void * ) & V_60 ) ;
if ( V_451 == - V_468 )
break;
if ( V_451 == - V_366 ) {
F_146 ( V_232 , V_390 , L_11 ) ;
break;
}
if ( V_60 . V_473 == V_2 -> V_370 . V_474 ) {
V_2 -> V_370 . V_475 = true ;
V_2 -> V_370 . V_476 = ! ( V_60 . V_123 & V_146 ) ;
F_193 ( V_2 , NULL ,
V_477 ) ;
F_194 ( V_2 ) ;
continue;
}
V_4 = & V_2 -> V_43 . V_4 [ V_60 . V_473 ] ;
F_1 ( V_2 , V_4 ) ;
F_42 ( V_4 -> V_79 , V_469 ) ;
V_472 = & V_4 -> V_361 [ V_4 -> V_359 ] ;
if ( F_48 ( V_472 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_36 = F_50 ( V_472 , struct V_35 , V_10 ) ;
if ( V_36 -> V_63 . V_94 ) {
F_51 ( & V_36 -> V_10 ) ;
F_52 ( V_2 , V_36 ) ;
V_36 = F_50 ( V_472 , struct V_35 , V_10 ) ;
}
V_374 = V_36 -> V_110 ;
F_30 ( & V_58 ) ;
if ( F_188 ( & V_374 -> V_10 , V_472 ) ) {
F_147 ( V_472 , & V_58 ) ;
F_36 ( V_4 -> V_359 , V_360 ) ;
if ( ! F_48 ( & V_4 -> V_355 ) ) {
struct V_9 V_107 ;
F_30 ( & V_107 ) ;
V_4 -> V_353 = NULL ;
F_147 ( & V_4 -> V_355 , & V_107 ) ;
F_115 ( V_2 , V_4 , & V_107 , true ) ;
}
} else {
V_374 -> V_63 . V_94 = true ;
if ( V_36 != V_374 )
F_136 ( & V_58 , V_472 ,
V_374 -> V_10 . V_77 ) ;
}
F_75 ( V_2 , V_4 , & V_60 , V_36 , & V_58 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_195 ( struct V_1 * V_2 , int V_478 )
{
struct V_479 * V_480 = & V_2 -> V_481 ;
T_2 V_482 = V_2 -> V_91 -> V_92 . V_482 ;
V_480 -> V_483 = V_478 * V_482 ;
V_480 -> V_484 = F_196 ( V_2 -> V_84 , V_480 -> V_483 ,
& V_480 -> V_485 , V_486 ) ;
if ( ! V_480 -> V_484 )
return - V_420 ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_487 ;
V_487 = F_195 ( V_2 , V_488 ) ;
if ( ! V_487 )
F_198 ( V_2 -> V_91 , V_2 -> V_481 . V_484 ,
V_2 -> V_481 . V_485 ,
V_488 ) ;
return V_487 ;
}
int F_199 ( struct V_1 * V_2 , int V_489 )
{
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
int error = 0 ;
F_126 ( & V_2 -> V_43 . V_87 ) ;
error = F_200 ( V_2 , & V_2 -> V_43 . V_490 , & V_2 -> V_43 . V_88 ,
L_12 , V_489 , 1 , 1 ) ;
if ( error != 0 ) {
F_131 ( V_232 ,
L_13 , error ) ;
return error ;
}
error = F_200 ( V_2 , & V_2 -> V_370 . V_491 , & V_2 -> V_370 . V_492 ,
L_14 , V_432 , 1 , 1 ) ;
if ( error != 0 ) {
F_131 ( V_232 ,
L_15 , error ) ;
return error ;
}
F_201 ( & V_2 -> V_493 , V_494 ) ;
if ( V_2 -> V_91 -> V_92 . V_178 & V_179 )
error = F_197 ( V_2 ) ;
return error ;
}
void F_202 ( struct V_1 * V_2 , struct V_50 * V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_22 , V_495 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_319 ;
V_22 ++ , V_6 ++ ) {
V_6 -> V_13 = V_13 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_64 = V_6 -> V_317 = 0 ;
V_6 -> V_134 = V_496 ;
V_6 -> V_67 = V_6 -> V_70 = 0 ;
V_6 -> V_19 = false ;
V_6 -> V_135 = false ;
F_63 ( & V_6 -> V_53 ) ;
F_63 ( & V_6 -> V_54 ) ;
V_495 = F_6 ( V_22 ) ;
V_6 -> V_8 = & V_13 -> V_8 [ V_495 ] ;
}
for ( V_495 = 0 , V_8 = & V_13 -> V_8 [ V_495 ] ;
V_495 < V_384 ; V_495 ++ , V_8 ++ ) {
V_8 -> V_19 = false ;
V_8 -> V_142 = true ;
V_8 -> V_4 = V_2 -> V_43 . V_44 [ V_495 ] ;
F_30 ( & V_8 -> V_20 ) ;
}
}
void F_203 ( struct V_1 * V_2 , struct V_50 * V_13 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 , V_6 = & V_13 -> V_6 [ V_22 ] ;
V_22 < V_319 ; V_22 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_19 ) {
F_51 ( & V_6 -> V_10 ) ;
V_6 -> V_19 = false ;
}
if ( V_8 -> V_19 ) {
F_51 ( & V_8 -> V_10 ) ;
V_6 -> V_8 -> V_19 = false ;
}
F_39 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_135 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
int F_204 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_408 * V_409 )
{
struct V_75 * V_76 = (struct V_75 * ) V_25 -> V_81 ;
struct V_23 * V_40 = F_7 ( V_25 ) ;
struct V_231 * V_232 = F_103 ( V_2 -> V_91 ) ;
struct V_35 * V_36 ;
int V_411 , V_412 ;
V_411 = F_167 ( V_76 -> V_82 ) ;
V_412 = V_411 & 3 ;
if ( V_412 && V_25 -> V_227 > V_411 ) {
if ( F_168 ( V_25 ) < V_412 ) {
F_146 ( V_232 , V_390 ,
L_16 ) ;
return - V_497 ;
}
F_169 ( V_25 , V_412 ) ;
memmove ( V_25 -> V_81 , V_25 -> V_81 + V_412 , V_411 ) ;
}
V_40 -> V_176 = V_177 ;
V_40 -> V_199 = V_25 -> V_227 + V_410 ;
V_40 -> V_300 = V_498 ;
V_36 = F_26 ( V_2 , V_409 -> V_4 , NULL , V_25 ) ;
if ( ! V_36 ) {
F_146 ( V_232 , V_390 , L_17 ) ;
return - V_497 ;
}
F_12 ( V_2 -> V_499 , NULL , V_36 ) ;
F_148 ( V_2 -> V_91 , V_36 -> V_90 , V_36 -> V_287 ) ;
F_205 ( V_2 -> V_91 , V_409 -> V_4 -> V_79 ) ;
F_152 ( V_2 , V_409 -> V_4 , NULL , V_25 ) ;
return 0 ;
}
