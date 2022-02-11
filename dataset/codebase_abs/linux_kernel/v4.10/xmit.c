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
void F_13 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_13 * V_14 = V_2 -> V_33 ;
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_32 -> V_25 ;
struct V_15 * V_16 = V_18 -> V_16 ;
F_15 ( V_35 , V_37 , L_1 ,
V_32 -> V_8 ? V_32 -> V_8 -> V_38 : V_32 -> V_24 -> V_38 ,
V_18 -> V_30 ) ;
F_6 ( V_14 , V_16 ) ;
V_18 -> V_39 = true ;
F_9 ( V_14 , V_16 , V_18 ) ;
F_16 ( V_14 , V_16 ) ;
F_7 ( V_14 , V_16 ) ;
}
static struct V_40 * F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_41 = F_2 ( V_4 ) ;
F_18 ( sizeof( struct V_40 ) >
sizeof( V_41 -> V_42 ) ) ;
return (struct V_40 * ) & V_41 -> V_42 [ 0 ] ;
}
static void F_19 ( struct V_17 * V_18 , T_1 V_43 )
{
if ( ! V_18 -> V_23 -> V_8 )
return;
F_20 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 -> V_38 , V_18 -> V_30 ,
V_43 << V_44 ) ;
}
static void F_21 ( struct V_45 * V_24 , struct V_7 * V_8 ,
struct V_46 * V_47 )
{
F_22 ( V_24 , V_8 , V_47 -> V_48 , V_47 -> V_49 ,
F_23 ( V_47 -> V_49 ) ) ;
}
static void F_24 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_3 * V_4 )
{
struct V_40 * V_50 = F_17 ( V_4 ) ;
int V_51 = V_50 -> V_16 ;
if ( V_51 < 0 )
return;
V_16 = V_14 -> V_52 . V_53 [ V_51 ] ;
if ( F_25 ( -- V_16 -> V_54 < 0 ) )
V_16 -> V_54 = 0 ;
}
static struct V_17 *
F_26 ( struct V_13 * V_14 , struct V_55 * V_23 , struct V_3 * V_4 )
{
T_2 V_30 = V_4 -> V_56 & V_57 ;
return F_27 ( V_23 , V_30 ) ;
}
static struct V_3 *
F_28 ( struct V_17 * V_18 )
{
struct V_31 * V_16 = F_29 ( ( void * ) V_18 , struct V_31 , V_25 ) ;
struct V_13 * V_14 = V_18 -> V_23 -> V_14 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_58 V_59 = {
. V_16 = V_18 -> V_16 ,
. V_8 = V_18 -> V_23 -> V_8 ,
} ;
struct V_3 * V_4 ;
struct V_40 * V_50 ;
int V_51 ;
if ( ! V_18 -> V_39 )
return NULL ;
V_4 = F_30 ( V_2 , V_16 ) ;
if ( ! V_4 ) {
V_18 -> V_39 = false ;
return NULL ;
}
if ( F_31 ( V_2 , V_4 , & V_59 ) ) {
F_32 ( V_2 , V_4 ) ;
return NULL ;
}
V_51 = F_33 ( V_4 ) ;
if ( V_18 -> V_16 == V_14 -> V_52 . V_53 [ V_51 ] ) {
V_50 = F_17 ( V_4 ) ;
V_50 -> V_16 = V_51 ;
++ V_18 -> V_16 -> V_54 ;
}
return V_4 ;
}
static bool F_34 ( struct V_17 * V_18 )
{
return ! F_35 ( & V_18 -> V_60 ) || V_18 -> V_39 ;
}
static struct V_3 * F_36 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
V_4 = F_37 ( & V_18 -> V_60 ) ;
if ( ! V_4 )
V_4 = F_28 ( V_18 ) ;
return V_4 ;
}
static void F_38 ( struct V_13 * V_14 , struct V_17 * V_18 )
{
struct V_15 * V_16 = V_18 -> V_16 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
struct V_19 V_61 ;
struct F_1 V_62 ;
struct V_40 * V_50 ;
bool V_63 = false ;
F_39 ( & V_61 ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
while ( ( V_4 = F_37 ( & V_18 -> V_60 ) ) ) {
V_50 = F_17 ( V_4 ) ;
V_47 = V_50 -> V_47 ;
if ( ! V_47 ) {
F_24 ( V_14 , V_16 , V_4 ) ;
F_32 ( V_14 -> V_2 , V_4 ) ;
continue;
}
if ( V_50 -> V_64 ) {
F_40 ( V_14 , V_18 , V_47 -> V_65 . V_43 ) ;
V_63 = true ;
}
F_12 ( & V_47 -> V_20 , & V_61 ) ;
F_41 ( V_14 , V_47 , V_16 , & V_61 , NULL , & V_62 , 0 ) ;
}
if ( V_63 ) {
F_7 ( V_14 , V_16 ) ;
F_19 ( V_18 , V_18 -> V_66 ) ;
F_6 ( V_14 , V_16 ) ;
}
}
static void F_40 ( struct V_13 * V_14 , struct V_17 * V_18 ,
int V_43 )
{
int V_67 , V_68 ;
V_67 = F_42 ( V_18 -> V_66 , V_43 ) ;
V_68 = ( V_18 -> V_69 + V_67 ) & ( V_70 - 1 ) ;
F_43 ( V_68 , V_18 -> V_71 ) ;
while ( V_18 -> V_69 != V_18 -> V_72 && ! F_44 ( V_18 -> V_69 , V_18 -> V_71 ) ) {
F_45 ( V_18 -> V_66 , V_73 ) ;
F_45 ( V_18 -> V_69 , V_70 ) ;
if ( V_18 -> V_74 >= 0 )
V_18 -> V_74 -- ;
}
}
static void F_46 ( struct V_13 * V_14 , struct V_17 * V_18 ,
struct V_46 * V_47 )
{
struct V_40 * V_50 = F_17 ( V_47 -> V_48 ) ;
T_1 V_43 = V_47 -> V_65 . V_43 ;
int V_67 , V_68 ;
V_67 = F_42 ( V_18 -> V_66 , V_43 ) ;
V_68 = ( V_18 -> V_69 + V_67 ) & ( V_70 - 1 ) ;
F_47 ( V_68 , V_18 -> V_71 ) ;
V_50 -> V_64 = 1 ;
if ( V_67 >= ( ( V_18 -> V_72 - V_18 -> V_69 ) &
( V_70 - 1 ) ) ) {
V_18 -> V_72 = V_68 ;
F_45 ( V_18 -> V_72 , V_70 ) ;
}
}
static void F_48 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_46 * V_47 ;
struct V_19 V_61 ;
struct F_1 V_62 ;
struct V_40 * V_50 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
F_39 ( & V_61 ) ;
while ( ( V_4 = F_36 ( V_18 ) ) ) {
V_50 = F_17 ( V_4 ) ;
V_47 = V_50 -> V_47 ;
if ( ! V_47 ) {
F_49 ( V_14 , V_4 , V_75 , V_16 , NULL ) ;
continue;
}
F_12 ( & V_47 -> V_20 , & V_61 ) ;
F_41 ( V_14 , V_47 , V_16 , & V_61 , NULL , & V_62 , 0 ) ;
}
}
static void F_50 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_3 * V_4 , int V_76 )
{
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_46 * V_47 = V_50 -> V_47 ;
struct V_77 * V_78 ;
int V_79 = V_50 -> V_80 ;
F_51 ( V_16 -> V_81 , V_82 ) ;
V_50 -> V_80 += V_76 ;
if ( V_79 > 0 )
return;
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_78 -> V_84 |= F_52 ( V_85 ) ;
F_53 ( V_14 -> V_86 , V_47 -> V_87 ,
sizeof( * V_78 ) , V_88 ) ;
}
static struct V_46 * F_54 ( struct V_13 * V_14 )
{
struct V_46 * V_47 = NULL ;
F_55 ( & V_14 -> V_52 . V_89 ) ;
if ( F_56 ( F_11 ( & V_14 -> V_52 . V_90 ) ) ) {
F_57 ( & V_14 -> V_52 . V_89 ) ;
return NULL ;
}
V_47 = F_58 ( & V_14 -> V_52 . V_90 , struct V_46 , V_20 ) ;
F_59 ( & V_47 -> V_20 ) ;
F_57 ( & V_14 -> V_52 . V_89 ) ;
return V_47 ;
}
static void F_60 ( struct V_13 * V_14 , struct V_46 * V_47 )
{
F_55 ( & V_14 -> V_52 . V_89 ) ;
F_12 ( & V_47 -> V_20 , & V_14 -> V_52 . V_90 ) ;
F_57 ( & V_14 -> V_52 . V_89 ) ;
}
static struct V_46 * F_61 ( struct V_13 * V_14 , struct V_46 * V_47 )
{
struct V_46 * V_91 ;
V_91 = F_54 ( V_14 ) ;
if ( F_25 ( ! V_91 ) )
return NULL ;
F_62 ( V_91 ) ;
V_91 -> V_48 = V_47 -> V_48 ;
V_91 -> V_87 = V_47 -> V_87 ;
memcpy ( V_91 -> V_92 , V_47 -> V_92 , V_14 -> V_36 -> V_93 . V_94 ) ;
V_91 -> V_65 = V_47 -> V_65 ;
V_91 -> V_65 . V_95 = false ;
return V_91 ;
}
static void F_63 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct F_1 * V_62 , int V_96 ,
int * V_97 , int * V_98 )
{
struct V_40 * V_50 ;
T_1 V_99 = 0 ;
V_100 V_101 [ V_102 >> 5 ] ;
int V_103 ;
int V_104 = 0 ;
* V_98 = 0 ;
* V_97 = 0 ;
V_104 = F_64 ( V_47 ) ;
if ( V_104 ) {
V_99 = V_62 -> V_105 ;
memcpy ( V_101 , & V_62 -> V_106 , V_102 >> 3 ) ;
}
while ( V_47 ) {
V_50 = F_17 ( V_47 -> V_48 ) ;
V_103 = F_42 ( V_99 , V_47 -> V_65 . V_43 ) ;
( * V_97 ) ++ ;
if ( ! V_96 || ( V_104 && ! F_65 ( V_101 , V_103 ) ) )
( * V_98 ) ++ ;
V_47 = V_47 -> V_107 ;
}
}
static void F_66 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_46 * V_47 , struct V_19 * V_108 ,
struct V_7 * V_8 ,
struct V_17 * V_18 ,
struct F_1 * V_62 , int V_96 )
{
struct V_55 * V_23 = NULL ;
struct V_3 * V_4 ;
struct V_77 * V_78 ;
struct V_5 * V_41 ;
struct V_46 * V_107 , * V_109 = V_47 -> V_110 ;
struct V_19 V_61 ;
struct V_111 V_112 ;
T_1 V_99 = 0 , V_113 = 0 , V_114 = 0 , V_115 ;
V_100 V_101 [ V_102 >> 5 ] ;
int V_104 , V_116 , V_117 , V_63 = 0 , V_118 = 0 , V_98 = 0 ;
bool V_119 = true , V_120 ;
struct V_121 V_49 [ 4 ] ;
struct V_40 * V_50 ;
int V_97 ;
bool V_122 = ! ! ( V_62 -> V_123 & V_124 ) ;
int V_125 , V_80 ;
int V_74 = - 1 ;
V_4 = V_47 -> V_48 ;
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_41 = F_2 ( V_4 ) ;
memcpy ( V_49 , V_47 -> V_49 , sizeof( V_49 ) ) ;
V_80 = V_62 -> V_126 + 1 ;
for ( V_125 = 0 ; V_125 < V_62 -> V_127 ; V_125 ++ )
V_80 += V_49 [ V_125 ] . V_76 ;
if ( ! V_8 ) {
F_39 ( & V_61 ) ;
while ( V_47 ) {
V_107 = V_47 -> V_107 ;
if ( ! V_47 -> V_65 . V_95 || V_107 != NULL )
F_67 ( & V_47 -> V_20 , & V_61 ) ;
F_41 ( V_14 , V_47 , V_16 , & V_61 , NULL , V_62 , 0 ) ;
V_47 = V_107 ;
}
return;
}
V_23 = (struct V_55 * ) V_8 -> V_25 ;
V_115 = V_18 -> V_66 ;
V_120 = V_62 -> V_128 & V_129 ;
if ( V_120 && V_18 -> V_30 != V_62 -> V_18 )
V_96 = false ;
V_104 = F_64 ( V_47 ) ;
memset ( V_101 , 0 , V_102 >> 3 ) ;
if ( V_104 && V_96 ) {
if ( V_62 -> V_128 & V_129 ) {
V_99 = V_62 -> V_105 ;
memcpy ( V_101 , & V_62 -> V_106 , V_102 >> 3 ) ;
} else {
if ( V_14 -> V_36 -> V_130 == V_131 )
V_118 = 1 ;
}
}
F_68 ( & V_112 ) ;
F_63 ( V_14 , V_47 , V_62 , V_96 , & V_97 , & V_98 ) ;
while ( V_47 ) {
T_1 V_43 = V_47 -> V_65 . V_43 ;
V_116 = V_117 = V_63 = 0 ;
V_107 = V_47 -> V_107 ;
V_4 = V_47 -> V_48 ;
V_41 = F_2 ( V_4 ) ;
V_50 = F_17 ( V_4 ) ;
if ( ! F_69 ( V_18 -> V_66 , V_18 -> V_132 , V_43 ) ||
! V_18 -> V_133 ) {
V_116 = 1 ;
} else if ( F_65 ( V_101 , F_42 ( V_99 , V_43 ) ) ) {
V_113 ++ ;
} else if ( ! V_104 && V_96 ) {
V_113 ++ ;
} else if ( V_122 ) {
V_117 = 1 ;
} else if ( V_50 -> V_80 < V_134 ) {
if ( V_96 || ! V_23 -> V_135 )
F_50 ( V_14 , V_16 , V_47 -> V_48 ,
V_80 ) ;
V_117 = 1 ;
} else {
V_116 = 1 ;
V_114 ++ ;
V_74 = F_70 ( int , V_74 ,
F_42 ( V_115 , V_43 ) ) ;
}
F_39 ( & V_61 ) ;
if ( V_107 != NULL || ! V_109 -> V_65 . V_95 )
F_67 ( & V_47 -> V_20 , & V_61 ) ;
if ( ! V_117 ) {
F_40 ( V_14 , V_18 , V_43 ) ;
if ( V_119 && ( V_113 == 1 || V_114 == 1 ) ) {
memcpy ( V_41 -> V_136 . V_49 , V_49 , sizeof( V_49 ) ) ;
F_71 ( V_14 , V_47 , V_62 , V_97 , V_98 , V_96 ) ;
V_119 = false ;
if ( V_47 == V_47 -> V_110 )
F_72 ( V_14 -> V_36 ,
V_47 -> V_48 ,
V_62 ) ;
}
F_41 ( V_14 , V_47 , V_16 , & V_61 , V_8 , V_62 ,
! V_116 ) ;
} else {
if ( V_41 -> V_11 & V_137 ) {
V_41 -> V_11 &= ~ V_137 ;
F_73 ( V_8 ) ;
}
if ( V_47 -> V_107 == NULL && V_109 -> V_65 . V_95 ) {
struct V_46 * V_91 ;
V_91 = F_61 ( V_14 , V_109 ) ;
if ( ! V_91 ) {
F_40 ( V_14 , V_18 , V_43 ) ;
F_41 ( V_14 , V_47 , V_16 ,
& V_61 , NULL , V_62 ,
0 ) ;
V_74 = F_70 ( int , V_74 ,
F_42 ( V_115 , V_43 ) ) ;
break;
}
V_50 -> V_47 = V_91 ;
}
F_74 ( & V_112 , V_4 ) ;
}
V_47 = V_107 ;
}
if ( ! F_35 ( & V_112 ) ) {
if ( V_23 -> V_135 )
F_75 ( V_8 , V_18 -> V_30 , true ) ;
F_76 ( & V_112 , & V_18 -> V_60 ) ;
if ( ! V_23 -> V_135 ) {
F_9 ( V_14 , V_16 , V_18 ) ;
if ( V_62 -> V_123 & ( V_138 | V_139 ) )
V_18 -> V_140 = true ;
}
}
if ( V_74 >= 0 ) {
T_1 V_141 = F_77 ( V_115 , V_74 ) ;
if ( F_69 ( V_18 -> V_66 , V_18 -> V_132 , V_141 ) )
V_18 -> V_74 = F_42 ( V_18 -> V_66 , V_141 ) ;
F_7 ( V_14 , V_16 ) ;
F_19 ( V_18 , F_77 ( V_115 , V_74 + 1 ) ) ;
F_6 ( V_14 , V_16 ) ;
}
if ( V_118 )
F_78 ( V_14 , V_142 ) ;
}
static bool F_79 ( struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_47 -> V_48 ) ;
return F_80 ( V_47 ) && ! ( V_6 -> V_11 & V_143 ) ;
}
static void F_81 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct F_1 * V_62 , struct V_46 * V_47 ,
struct V_19 * V_61 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_77 * V_78 ;
struct V_17 * V_18 = NULL ;
bool V_96 , V_122 ;
V_96 = ! ( V_62 -> V_123 & V_144 ) ;
V_122 = ! ! ( V_62 -> V_123 & V_124 ) ;
V_16 -> V_145 = false ;
V_16 -> V_146 -- ;
if ( F_79 ( V_47 ) )
V_16 -> V_147 -- ;
V_62 -> V_148 = F_82 ( V_14 -> V_36 , V_47 -> V_92 ,
V_62 -> V_127 ) ;
V_78 = (struct V_77 * ) V_47 -> V_48 -> V_83 ;
V_8 = F_83 ( V_2 , V_78 -> V_149 , V_78 -> V_150 ) ;
if ( V_8 ) {
struct V_55 * V_23 = (struct V_55 * ) V_8 -> V_25 ;
V_18 = F_26 ( V_14 , V_23 , V_47 -> V_48 ) ;
if ( V_62 -> V_123 & ( V_138 | V_139 ) )
V_18 -> V_140 = true ;
}
if ( ! F_80 ( V_47 ) ) {
if ( ! V_122 ) {
V_6 = F_2 ( V_47 -> V_48 ) ;
memcpy ( V_6 -> V_136 . V_49 , V_47 -> V_49 ,
sizeof( V_6 -> V_136 . V_49 ) ) ;
F_71 ( V_14 , V_47 , V_62 , 1 , V_96 ? 0 : 1 , V_96 ) ;
F_72 ( V_14 -> V_36 , V_47 -> V_48 , V_62 ) ;
}
F_41 ( V_14 , V_47 , V_16 , V_61 , V_8 , V_62 , V_96 ) ;
} else
F_66 ( V_14 , V_16 , V_47 , V_61 , V_8 , V_18 , V_62 , V_96 ) ;
if ( ! V_122 )
F_16 ( V_14 , V_16 ) ;
}
static bool F_84 ( struct V_46 * V_47 )
{
struct V_3 * V_4 ;
struct V_5 * V_41 ;
struct V_121 * V_49 ;
int V_125 ;
V_4 = V_47 -> V_48 ;
V_41 = F_2 ( V_4 ) ;
V_49 = V_41 -> V_136 . V_49 ;
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ ) {
if ( ! V_49 [ V_125 ] . V_76 || V_49 [ V_125 ] . V_151 < 0 )
break;
if ( ! ( V_49 [ V_125 ] . V_11 & V_152 ) )
return true ;
}
return false ;
}
static V_100 F_85 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_5 * V_41 ;
struct V_121 * V_49 ;
V_100 V_153 , V_154 ;
T_1 V_155 , V_156 , V_157 = 0 ;
int V_51 = V_18 -> V_16 -> V_158 ;
int V_125 ;
V_4 = V_47 -> V_48 ;
V_41 = F_2 ( V_4 ) ;
V_49 = V_47 -> V_49 ;
V_153 = V_159 ;
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ ) {
int V_160 ;
if ( ! V_49 [ V_125 ] . V_76 )
continue;
if ( ! ( V_49 [ V_125 ] . V_11 & V_152 ) ) {
V_157 = 1 ;
break;
}
if ( V_49 [ V_125 ] . V_11 & V_161 )
V_160 = V_162 ;
else
V_160 = V_163 ;
if ( V_49 [ V_125 ] . V_11 & V_164 )
V_160 ++ ;
V_154 = V_14 -> V_52 . V_165 [ V_51 ] [ V_160 ] [ V_49 [ V_125 ] . V_151 ] ;
V_153 = F_86 ( V_153 , V_154 ) ;
}
if ( V_41 -> V_11 & V_143 || V_157 )
return 0 ;
V_155 = F_86 ( V_153 , ( V_100 ) V_159 ) ;
V_156 = F_87 ( V_14 , V_153 ) ;
if ( V_156 )
V_155 = V_156 ;
if ( V_18 -> V_23 -> V_166 )
V_155 = F_86 ( V_155 , V_18 -> V_23 -> V_166 ) ;
return V_155 ;
}
static int F_88 ( struct V_13 * V_14 , struct V_17 * V_18 ,
struct V_46 * V_47 , T_1 V_154 ,
bool V_167 )
{
#define F_89 60
V_100 V_168 , V_169 ;
T_1 V_170 ;
T_2 V_11 , V_171 ;
int V_172 , V_173 , V_174 , V_175 , V_176 ;
struct V_40 * V_50 = F_17 ( V_47 -> V_48 ) ;
V_175 = F_90 ( V_154 ) ;
if ( ( V_50 -> V_177 != V_178 ) &&
! ( V_14 -> V_36 -> V_93 . V_179 & V_180 ) )
V_175 += V_181 ;
if ( V_167 && ! F_91 ( V_14 -> V_36 ) &&
( V_14 -> V_36 -> V_182 & V_183 ) )
V_175 = F_92 ( V_175 , F_89 ) ;
if ( V_18 -> V_23 -> V_184 == 0 )
return V_175 ;
V_171 = V_47 -> V_49 [ 0 ] . V_151 ;
V_11 = V_47 -> V_49 [ 0 ] . V_11 ;
V_172 = ( V_11 & V_161 ) ? 1 : 0 ;
V_174 = ( V_11 & V_164 ) ? 1 : 0 ;
if ( V_174 )
V_169 = F_93 ( V_18 -> V_23 -> V_184 ) ;
else
V_169 = F_94 ( V_18 -> V_23 -> V_184 ) ;
if ( V_169 == 0 )
V_169 = 1 ;
V_173 = F_95 ( V_171 ) ;
V_168 = V_185 [ V_171 % 8 ] [ V_172 ] * V_173 ;
V_170 = ( V_169 * V_168 ) / V_186 ;
if ( V_154 < V_170 ) {
V_176 = ( V_170 - V_154 ) / V_187 ;
V_175 = F_92 ( V_176 , V_175 ) ;
}
return V_175 ;
}
static struct V_46 *
F_96 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_41 ;
struct V_40 * V_50 ;
struct V_3 * V_4 , * V_188 = NULL ;
struct V_46 * V_47 ;
T_1 V_43 ;
while ( 1 ) {
V_4 = F_36 ( V_18 ) ;
if ( ! V_4 )
break;
V_50 = F_17 ( V_4 ) ;
V_47 = V_50 -> V_47 ;
if ( ! V_50 -> V_47 )
V_47 = F_97 ( V_14 , V_16 , V_18 , V_4 ) ;
else
V_47 -> V_65 . V_95 = false ;
if ( ! V_47 ) {
F_24 ( V_14 , V_16 , V_4 ) ;
F_32 ( V_14 -> V_2 , V_4 ) ;
continue;
}
V_47 -> V_107 = NULL ;
V_47 -> V_110 = V_47 ;
V_41 = F_2 ( V_4 ) ;
V_41 -> V_11 &= ~ V_189 ;
if ( ! V_18 -> V_133 )
V_41 -> V_11 &= ~ V_190 ;
if ( ! ( V_41 -> V_11 & V_190 ) ) {
V_47 -> V_65 . V_191 = 0 ;
return V_47 ;
}
V_47 -> V_65 . V_191 = V_192 | V_193 ;
V_43 = V_47 -> V_65 . V_43 ;
if ( ! F_69 ( V_18 -> V_66 , V_18 -> V_132 , V_43 ) ) {
F_74 ( & V_18 -> V_60 , V_4 ) ;
if ( ! F_98 ( & V_18 -> V_60 , V_4 ) &&
! F_25 ( V_4 == V_188 ) ) {
if( ! V_188 )
V_188 = V_4 ;
continue;
}
break;
}
if ( V_18 -> V_74 > F_42 ( V_18 -> V_66 , V_43 ) ) {
struct F_1 V_62 = {} ;
struct V_19 V_61 ;
F_39 ( & V_61 ) ;
F_99 ( & V_47 -> V_20 , & V_61 ) ;
F_40 ( V_14 , V_18 , V_43 ) ;
F_41 ( V_14 , V_47 , V_16 , & V_61 , NULL , & V_62 , 0 ) ;
continue;
}
return V_47 ;
}
return NULL ;
}
static int
F_100 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_108 ,
struct V_46 * V_194 )
{
#define F_101 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_46 * V_47 = V_194 , * V_195 = NULL ;
int V_97 = 0 , V_175 ;
T_1 V_155 = 0 , V_196 = 0 , V_197 = 0 ,
V_198 , V_199 = V_18 -> V_132 / 2 ;
struct V_5 * V_41 ;
struct V_40 * V_50 ;
struct V_3 * V_4 ;
V_47 = V_194 ;
V_155 = F_85 ( V_14 , V_47 , V_18 ) ;
while ( V_47 )
{
V_4 = V_47 -> V_48 ;
V_50 = F_17 ( V_4 ) ;
V_198 = V_187 + V_50 -> V_200 ;
if ( V_97 ) {
if ( V_155 < V_196 + V_197 + V_198 ||
F_84 ( V_47 ) || V_97 >= V_199 )
goto V_201;
V_41 = F_2 ( V_47 -> V_48 ) ;
if ( ( V_41 -> V_11 & V_143 ) ||
! ( V_41 -> V_11 & V_190 ) )
goto V_201;
}
V_196 += V_197 + V_198 ;
V_175 = F_88 ( V_14 , V_18 , V_194 , V_50 -> V_200 ,
! V_97 ) ;
V_197 = F_101 ( V_198 ) + ( V_175 << 2 ) ;
V_97 ++ ;
V_47 -> V_107 = NULL ;
if ( ! V_50 -> V_64 )
F_46 ( V_14 , V_18 , V_47 ) ;
V_47 -> V_65 . V_175 = V_175 ;
F_12 ( & V_47 -> V_20 , V_108 ) ;
if ( V_195 )
V_195 -> V_107 = V_47 ;
V_195 = V_47 ;
V_47 = F_96 ( V_14 , V_16 , V_18 ) ;
}
goto V_202;
V_201:
F_74 ( & V_18 -> V_60 , V_47 -> V_48 ) ;
V_202:
V_47 = V_194 ;
V_47 -> V_110 = V_195 ;
if ( V_47 == V_195 ) {
V_196 = F_17 ( V_47 -> V_48 ) -> V_200 ;
V_47 -> V_65 . V_191 = V_192 ;
} else {
F_51 ( V_16 -> V_81 , V_203 ) ;
}
return V_196 ;
#undef F_101
}
static V_100 F_102 ( struct V_13 * V_14 , T_2 V_171 , int V_204 ,
int V_172 , int V_174 , bool V_205 )
{
V_100 V_206 , V_168 , V_148 , V_169 ;
int V_173 ;
V_173 = F_95 ( V_171 ) ;
V_206 = ( V_204 << 3 ) + V_207 ;
V_168 = V_185 [ V_171 % 8 ] [ V_172 ] * V_173 ;
V_169 = ( V_206 + V_168 - 1 ) / V_168 ;
if ( ! V_174 )
V_148 = F_103 ( V_169 ) ;
else
V_148 = F_104 ( V_169 ) ;
V_148 += V_208 + V_209 + V_210 + V_211 + V_212 + F_105 ( V_173 ) ;
return V_148 ;
}
static int F_106 ( int V_213 , int V_214 , bool V_215 , bool V_216 )
{
int V_173 = F_95 ( V_214 ) ;
int V_217 , V_218 ;
int V_219 = 0 ;
V_213 -= V_208 + V_209 + V_210 + V_211 + V_212 + F_105 ( V_173 ) ;
V_217 = V_216 ? F_107 ( V_213 ) : F_108 ( V_213 ) ;
V_218 = V_217 * V_185 [ V_214 % 8 ] [ V_215 ] * V_173 ;
V_218 -= V_207 ;
V_219 = V_218 / 8 ;
if ( V_219 > 65532 )
V_219 = 65532 ;
return V_219 ;
}
void F_109 ( struct V_13 * V_14 , int V_32 , int V_220 )
{
T_1 * V_221 , * V_222 , * V_223 , * V_224 ;
int V_214 ;
if ( ! V_220 || V_220 > 4096 )
V_220 = 4096 ;
V_221 = V_14 -> V_52 . V_165 [ V_32 ] [ V_163 ] ;
V_222 = V_14 -> V_52 . V_165 [ V_32 ] [ V_225 ] ;
V_223 = V_14 -> V_52 . V_165 [ V_32 ] [ V_162 ] ;
V_224 = V_14 -> V_52 . V_165 [ V_32 ] [ V_226 ] ;
for ( V_214 = 0 ; V_214 < 32 ; V_214 ++ ) {
V_221 [ V_214 ] = F_106 ( V_220 , V_214 , false , false ) ;
V_222 [ V_214 ] = F_106 ( V_220 , V_214 , false , true ) ;
V_223 [ V_214 ] = F_106 ( V_220 , V_214 , true , false ) ;
V_224 [ V_214 ] = F_106 ( V_220 , V_214 , true , true ) ;
}
}
static T_2 F_110 ( struct V_13 * V_14 , struct V_46 * V_47 ,
T_2 V_227 , bool V_228 , bool V_229 )
{
T_2 V_230 ;
struct V_3 * V_4 ;
struct V_40 * V_50 ;
struct V_5 * V_6 ;
struct V_231 * V_232 = V_14 -> V_36 ;
if ( V_14 -> V_233 || ! V_232 -> V_234 )
return V_235 ;
V_4 = V_47 -> V_48 ;
V_50 = F_17 ( V_4 ) ;
V_6 = F_2 ( V_4 ) ;
if ( ! F_111 ( V_232 ) ) {
int V_236 = V_50 -> V_237 ;
if ( V_228 ) {
T_2 V_238 ;
struct V_239 * V_240 = & V_232 -> V_241 . V_242 ;
if ( V_243 >= V_244 ) {
bool V_245 ;
struct V_246 * V_247 ;
V_245 = V_6 -> V_248 == V_249 ;
V_247 = & V_240 -> V_250 [ V_245 ] ;
V_238 = V_247 -> V_251 ;
} else {
V_238 = 2 ;
}
V_236 += V_238 ;
}
if ( F_112 ( V_232 ) || F_113 ( V_232 ) ||
F_114 ( V_232 ) ) {
V_236 -= 2 * V_252 ;
} else if ( F_115 ( V_232 ) ) {
T_4 V_253 ;
V_253 = V_232 -> V_254 -> V_255 ( V_232 ,
V_256 ) ;
V_236 -= 2 * V_253 ;
}
if ( V_257 && V_229 )
V_236 -= 2 ;
V_236 = F_92 ( V_236 , 0 ) ;
V_230 = F_116 ( T_2 , V_232 -> V_237 [ V_227 ] , V_236 ) ;
if ( ! V_230 && ! F_115 ( V_232 ) )
V_230 = 1 ;
} else if ( ! V_47 -> V_65 . V_258 ) {
if ( V_227 < 8 && ( V_6 -> V_11 & V_259 ) )
V_230 = F_116 ( T_2 , V_232 -> V_260 [ V_227 ] ,
V_50 -> V_237 ) ;
else
V_230 = F_116 ( T_2 , V_232 -> V_237 [ V_227 ] ,
V_50 -> V_237 ) ;
} else {
V_230 = V_232 -> V_261 ;
}
return V_230 ;
}
static void F_117 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct V_262 * V_6 , int V_263 , bool V_264 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_34 * V_35 = F_14 ( V_232 ) ;
struct V_3 * V_4 ;
struct V_5 * V_41 ;
struct V_121 * V_49 ;
const struct V_265 * V_266 ;
struct V_77 * V_78 ;
struct V_40 * V_50 = F_17 ( V_47 -> V_48 ) ;
V_100 V_267 = V_14 -> V_2 -> V_268 -> V_269 ;
int V_125 ;
T_2 V_171 = 0 ;
V_4 = V_47 -> V_48 ;
V_41 = F_2 ( V_4 ) ;
V_49 = V_47 -> V_49 ;
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_6 -> V_270 = ! F_118 ( V_78 -> V_84 ) ;
V_6 -> V_271 = V_50 -> V_271 ;
for ( V_125 = 0 ; V_125 < F_23 ( V_47 -> V_49 ) ; V_125 ++ ) {
bool V_228 , V_272 , V_273 , V_229 ;
int V_274 ;
if ( ! V_49 [ V_125 ] . V_76 || ( V_49 [ V_125 ] . V_151 < 0 ) )
continue;
V_171 = V_49 [ V_125 ] . V_151 ;
V_6 -> V_49 [ V_125 ] . V_275 = V_49 [ V_125 ] . V_76 ;
if ( F_80 ( V_47 ) && ! F_64 ( V_47 ) &&
( V_49 [ V_125 ] . V_11 & V_152 ) &&
F_56 ( V_267 != ( V_100 ) - 1 ) ) {
if ( ! V_267 || ( V_263 > V_267 ) )
V_264 = true ;
}
if ( V_264 || V_49 [ V_125 ] . V_11 & V_276 ) {
V_6 -> V_49 [ V_125 ] . V_277 |= V_278 ;
V_6 -> V_11 |= V_279 ;
} else if ( V_49 [ V_125 ] . V_11 & V_280 ) {
V_6 -> V_49 [ V_125 ] . V_277 |= V_278 ;
V_6 -> V_11 |= V_281 ;
}
if ( V_49 [ V_125 ] . V_11 & V_161 )
V_6 -> V_49 [ V_125 ] . V_277 |= V_282 ;
if ( V_49 [ V_125 ] . V_11 & V_164 )
V_6 -> V_49 [ V_125 ] . V_277 |= V_283 ;
V_272 = ! ! ( V_49 [ V_125 ] . V_11 & V_164 ) ;
V_228 = ! ! ( V_49 [ V_125 ] . V_11 & V_161 ) ;
V_273 = ! ! ( V_49 [ V_125 ] . V_11 & V_284 ) ;
if ( V_49 [ V_125 ] . V_11 & V_152 ) {
V_6 -> V_49 [ V_125 ] . V_285 = V_171 | 0x80 ;
V_6 -> V_49 [ V_125 ] . V_286 = F_119 ( V_14 ,
V_232 -> V_287 , V_6 -> V_49 [ V_125 ] . V_285 ) ;
V_6 -> V_49 [ V_125 ] . V_288 = F_102 ( V_14 , V_171 , V_263 ,
V_228 , V_272 , V_273 ) ;
if ( V_171 < 8 && ( V_41 -> V_11 & V_259 ) )
V_6 -> V_49 [ V_125 ] . V_277 |= V_289 ;
V_6 -> V_236 [ V_125 ] = F_110 ( V_14 , V_47 , V_171 ,
V_228 , false ) ;
continue;
}
V_266 = & V_35 -> V_290 [ V_41 -> V_248 ] . V_291 [ V_49 [ V_125 ] . V_151 ] ;
if ( ( V_41 -> V_248 == V_249 ) &&
! ( V_266 -> V_11 & V_292 ) )
V_274 = V_293 ;
else
V_274 = V_294 ;
V_6 -> V_49 [ V_125 ] . V_285 = V_266 -> V_295 ;
if ( V_266 -> V_296 ) {
if ( V_49 [ V_125 ] . V_11 & V_284 )
V_6 -> V_49 [ V_125 ] . V_285 |= V_266 -> V_296 ;
} else {
V_273 = false ;
}
if ( V_47 -> V_65 . V_258 )
V_6 -> V_49 [ V_125 ] . V_286 = V_232 -> V_287 ;
else
V_6 -> V_49 [ V_125 ] . V_286 = F_119 ( V_14 ,
V_232 -> V_287 , V_6 -> V_49 [ V_125 ] . V_285 ) ;
V_6 -> V_49 [ V_125 ] . V_288 = F_120 ( V_14 -> V_36 ,
V_274 , V_266 -> V_297 * 100 , V_263 , V_171 , V_273 ) ;
V_229 = F_121 ( V_6 -> V_49 [ V_125 ] . V_285 ) ;
V_6 -> V_236 [ V_125 ] = F_110 ( V_14 , V_47 , V_171 , false ,
V_229 ) ;
}
if ( F_64 ( V_47 ) && ( V_263 > V_14 -> V_36 -> V_93 . V_298 ) )
V_6 -> V_11 &= ~ V_279 ;
if ( V_6 -> V_11 & V_279 )
V_6 -> V_11 &= ~ V_281 ;
}
static enum V_299 F_122 ( struct V_3 * V_4 )
{
struct V_77 * V_78 ;
enum V_299 V_300 ;
T_5 V_301 ;
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_301 = V_78 -> V_84 ;
if ( F_123 ( V_301 ) )
V_300 = V_302 ;
else if ( F_124 ( V_301 ) )
V_300 = V_303 ;
else if ( F_125 ( V_301 ) )
V_300 = V_304 ;
else if ( F_118 ( V_301 ) )
V_300 = V_305 ;
else
V_300 = V_306 ;
return V_300 ;
}
static void F_126 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct V_15 * V_16 , int V_263 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_46 * V_194 = NULL ;
struct V_262 V_6 ;
V_100 V_267 = V_14 -> V_2 -> V_268 -> V_269 ;
bool V_264 = false ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_307 = true ;
V_6 . V_308 = true ;
V_6 . V_309 = V_16 -> V_81 ;
while ( V_47 ) {
struct V_3 * V_4 = V_47 -> V_48 ;
struct V_5 * V_41 = F_2 ( V_4 ) ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
bool V_310 = ! ! ( V_47 -> V_65 . V_191 & V_193 ) ;
V_6 . type = F_122 ( V_4 ) ;
if ( V_47 -> V_107 )
V_6 . V_311 = V_47 -> V_107 -> V_312 ;
else
V_6 . V_311 = ( V_14 -> V_233 ) ? V_47 -> V_312 : 0 ;
if ( ! V_194 ) {
V_194 = V_47 ;
if ( ! V_14 -> V_233 )
V_6 . V_11 = V_313 ;
if ( ( V_41 -> V_11 & V_189 ) ||
V_16 == V_14 -> V_52 . V_314 )
V_6 . V_11 |= V_315 ;
if ( V_41 -> V_11 & V_316 )
V_6 . V_11 |= V_317 ;
if ( V_41 -> V_11 & V_318 )
V_6 . V_11 |= V_319 ;
if ( V_47 -> V_65 . V_258 )
V_6 . V_11 |= ( V_100 ) V_47 -> V_65 . V_258 <<
V_320 ;
if ( V_310 && ( V_47 == V_194 ) &&
F_56 ( V_267 != ( V_100 ) - 1 ) ) {
if ( ! V_267 || ( V_263 > V_267 ) )
V_264 = true ;
}
if ( ! V_310 )
V_263 = V_50 -> V_200 ;
F_117 ( V_14 , V_47 , & V_6 , V_263 , V_264 ) ;
}
V_6 . V_321 [ 0 ] = V_47 -> V_87 ;
V_6 . V_322 [ 0 ] = V_4 -> V_263 ;
V_6 . V_323 = V_50 -> V_200 ;
V_6 . V_177 = V_50 -> V_177 ;
V_6 . V_324 = V_50 -> V_324 ;
if ( V_310 ) {
if ( V_47 == V_194 )
V_6 . V_310 = V_325 ;
else if ( V_47 == V_194 -> V_110 )
V_6 . V_310 = V_326 ;
else
V_6 . V_310 = V_327 ;
V_6 . V_175 = V_47 -> V_65 . V_175 ;
V_6 . V_328 = V_263 ;
}
if ( V_47 == V_194 -> V_110 )
V_194 = NULL ;
F_127 ( V_232 , V_47 -> V_92 , & V_6 ) ;
V_47 = V_47 -> V_107 ;
}
}
static void
F_128 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_108 ,
struct V_46 * V_194 )
{
struct V_46 * V_47 = V_194 , * V_195 = NULL ;
int V_97 = 0 ;
do {
struct V_5 * V_41 ;
V_97 ++ ;
F_12 ( & V_47 -> V_20 , V_108 ) ;
if ( V_195 )
V_195 -> V_107 = V_47 ;
V_195 = V_47 ;
if ( V_97 >= 2 )
break;
V_47 = F_96 ( V_14 , V_16 , V_18 ) ;
if ( ! V_47 )
break;
V_41 = F_2 ( V_47 -> V_48 ) ;
if ( V_41 -> V_11 & V_190 ) {
F_74 ( & V_18 -> V_60 , V_47 -> V_48 ) ;
break;
}
F_21 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_47 ) ;
} while ( 1 );
}
static bool F_129 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , bool * V_201 )
{
struct V_46 * V_47 ;
struct V_5 * V_41 ;
struct V_19 V_108 ;
int V_328 = 0 ;
bool V_310 ;
if ( ! F_34 ( V_18 ) )
return false ;
F_39 ( & V_108 ) ;
V_47 = F_96 ( V_14 , V_16 , V_18 ) ;
if ( ! V_47 )
return false ;
V_41 = F_2 ( V_47 -> V_48 ) ;
V_310 = ! ! ( V_41 -> V_11 & V_190 ) ;
if ( ( V_310 && V_16 -> V_147 >= V_329 ) ||
( ! V_310 && V_16 -> V_146 >= V_330 ) ) {
F_74 ( & V_18 -> V_60 , V_47 -> V_48 ) ;
* V_201 = true ;
return false ;
}
F_21 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_47 ) ;
if ( V_310 )
V_328 = F_100 ( V_14 , V_16 , V_18 , & V_108 , V_47 ) ;
else
F_128 ( V_14 , V_16 , V_18 , & V_108 , V_47 ) ;
if ( F_11 ( & V_108 ) )
return false ;
if ( V_18 -> V_140 || V_18 -> V_23 -> V_331 ) {
V_18 -> V_140 = false ;
V_41 -> V_11 |= V_189 ;
}
F_126 ( V_14 , V_47 , V_16 , V_328 ) ;
F_130 ( V_14 , V_16 , & V_108 , false ) ;
return true ;
}
int F_131 ( struct V_13 * V_14 , struct V_7 * V_8 ,
T_1 V_18 , T_1 * V_332 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_17 * V_333 ;
struct V_15 * V_16 ;
struct V_55 * V_23 ;
T_2 V_334 ;
F_15 ( V_35 , V_335 , L_2 , V_336 ) ;
V_23 = (struct V_55 * ) V_8 -> V_25 ;
V_333 = F_27 ( V_23 , V_18 ) ;
V_16 = V_333 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( V_8 -> V_337 . V_338 ) {
V_23 -> V_166 = ( 1 << ( V_339 +
V_8 -> V_337 . V_340 ) ) - 1 ;
V_334 = F_132 ( V_8 -> V_337 . V_341 ) ;
V_23 -> V_184 = V_334 ;
}
V_333 -> V_133 = true ;
* V_332 = V_333 -> V_66 = V_333 -> V_342 ;
V_333 -> V_74 = - 1 ;
memset ( V_333 -> V_71 , 0 , sizeof( V_333 -> V_71 ) ) ;
V_333 -> V_69 = V_333 -> V_72 = 0 ;
F_8 ( V_14 , V_16 ) ;
return 0 ;
}
void F_133 ( struct V_13 * V_14 , struct V_7 * V_8 , T_1 V_18 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_55 * V_23 = (struct V_55 * ) V_8 -> V_25 ;
struct V_17 * V_333 = F_27 ( V_23 , V_18 ) ;
struct V_15 * V_16 = V_333 -> V_16 ;
F_15 ( V_35 , V_335 , L_2 , V_336 ) ;
F_6 ( V_14 , V_16 ) ;
V_333 -> V_133 = false ;
F_38 ( V_14 , V_333 ) ;
F_8 ( V_14 , V_16 ) ;
}
void F_134 ( struct V_7 * V_8 , struct V_13 * V_14 ,
struct V_55 * V_23 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
int V_30 ;
F_15 ( V_35 , V_335 , L_2 , V_336 ) ;
for ( V_30 = 0 ; V_30 < V_343 ; V_30 ++ ) {
V_18 = F_135 ( V_23 , V_30 ) ;
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( F_11 ( & V_18 -> V_20 ) ) {
F_7 ( V_14 , V_16 ) ;
continue;
}
if ( ! F_35 ( & V_18 -> V_60 ) )
F_75 ( V_8 , V_18 -> V_30 , true ) ;
F_136 ( & V_18 -> V_20 ) ;
F_7 ( V_14 , V_16 ) ;
}
}
void F_137 ( struct V_13 * V_14 , struct V_55 * V_23 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
int V_30 ;
F_15 ( V_35 , V_335 , L_2 , V_336 ) ;
for ( V_30 = 0 ; V_30 < V_343 ; V_30 ++ ) {
V_18 = F_135 ( V_23 , V_30 ) ;
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
V_18 -> V_140 = true ;
if ( F_34 ( V_18 ) ) {
F_9 ( V_14 , V_16 , V_18 ) ;
F_16 ( V_14 , V_16 ) ;
}
F_8 ( V_14 , V_16 ) ;
}
}
void F_138 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
T_1 V_344 , int V_97 ,
enum V_345 V_346 ,
bool V_347 )
{
struct V_13 * V_14 = V_2 -> V_33 ;
struct V_55 * V_23 = (struct V_55 * ) V_8 -> V_25 ;
struct V_15 * V_16 = V_14 -> V_52 . V_314 ;
struct V_5 * V_6 ;
struct V_19 V_108 ;
struct V_46 * V_348 = NULL , * V_47 ;
int V_349 = 0 ;
int V_125 ;
F_39 ( & V_108 ) ;
for ( V_125 = 0 ; V_344 && V_97 ; V_125 ++ , V_344 >>= 1 ) {
struct V_17 * V_18 ;
if ( ! ( V_344 & 1 ) )
continue;
V_18 = F_27 ( V_23 , V_125 ) ;
F_6 ( V_14 , V_18 -> V_16 ) ;
while ( V_97 > 0 ) {
V_47 = F_96 ( V_14 , V_14 -> V_52 . V_314 , V_18 ) ;
if ( ! V_47 )
break;
F_12 ( & V_47 -> V_20 , & V_108 ) ;
F_21 ( V_18 -> V_23 -> V_24 , V_18 -> V_23 -> V_8 , V_47 ) ;
if ( F_80 ( V_47 ) ) {
F_46 ( V_14 , V_18 , V_47 ) ;
V_47 -> V_65 . V_191 &= ~ V_193 ;
}
if ( V_348 )
V_348 -> V_107 = V_47 ;
V_348 = V_47 ;
V_97 -- ;
V_349 ++ ;
F_51 ( V_16 -> V_81 , V_350 ) ;
if ( V_23 -> V_8 && F_35 ( & V_18 -> V_60 ) )
F_75 ( V_23 -> V_8 , V_125 , false ) ;
}
F_8 ( V_14 , V_18 -> V_16 ) ;
}
if ( F_11 ( & V_108 ) )
return;
V_6 = F_2 ( V_348 -> V_48 ) ;
V_6 -> V_11 |= V_137 ;
V_47 = F_58 ( & V_108 , struct V_46 , V_20 ) ;
F_6 ( V_14 , V_16 ) ;
F_126 ( V_14 , V_47 , V_16 , 0 ) ;
F_130 ( V_14 , V_16 , & V_108 , false ) ;
F_7 ( V_14 , V_16 ) ;
}
struct V_15 * F_139 ( struct V_13 * V_14 , int V_351 , int V_352 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_353 V_354 ;
static const int V_355 [] = {
[ V_356 ] = V_357 ,
[ V_358 ] = V_359 ,
[ V_360 ] = V_361 ,
[ V_362 ] = V_363 ,
} ;
int V_81 , V_125 ;
memset ( & V_354 , 0 , sizeof( V_354 ) ) ;
V_354 . V_364 = V_355 [ V_352 ] ;
V_354 . V_365 = V_366 ;
V_354 . V_367 = V_366 ;
V_354 . V_368 = V_366 ;
V_354 . V_369 = 0 ;
if ( V_232 -> V_93 . V_179 & V_180 ) {
V_354 . V_370 = V_371 ;
} else {
if ( V_351 == V_372 )
V_354 . V_370 = V_373 ;
else
V_354 . V_370 = V_374 |
V_373 ;
}
V_81 = F_140 ( V_232 , V_351 , & V_354 ) ;
if ( V_81 == - 1 ) {
return NULL ;
}
if ( ! F_141 ( V_14 , V_81 ) ) {
struct V_15 * V_16 = & V_14 -> V_52 . V_16 [ V_81 ] ;
V_16 -> V_81 = V_81 ;
V_16 -> V_158 = - 1 ;
V_16 -> V_375 = NULL ;
F_68 ( & V_16 -> V_376 ) ;
F_39 ( & V_16 -> V_377 ) ;
F_142 ( & V_16 -> V_378 ) ;
V_16 -> V_146 = 0 ;
V_16 -> V_147 = 0 ;
V_16 -> V_145 = false ;
V_14 -> V_52 . V_379 |= 1 << V_81 ;
V_16 -> V_380 = V_16 -> V_381 = 0 ;
for ( V_125 = 0 ; V_125 < V_382 ; V_125 ++ )
F_39 ( & V_16 -> V_383 [ V_125 ] ) ;
}
return & V_14 -> V_52 . V_16 [ V_81 ] ;
}
int F_143 ( struct V_13 * V_14 , int V_384 ,
struct V_353 * V_385 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
int error = 0 ;
struct V_353 V_354 ;
F_144 ( V_14 -> V_52 . V_16 [ V_384 ] . V_81 != V_384 ) ;
F_145 ( V_232 , V_384 , & V_354 ) ;
V_354 . V_365 = V_385 -> V_365 ;
V_354 . V_367 = V_385 -> V_367 ;
V_354 . V_368 = V_385 -> V_368 ;
V_354 . V_386 = V_385 -> V_386 ;
V_354 . V_387 = V_385 -> V_387 ;
if ( ! F_146 ( V_232 , V_384 , & V_354 ) ) {
F_147 ( F_14 ( V_14 -> V_36 ) ,
L_3 , V_384 ) ;
error = - V_388 ;
} else {
F_148 ( V_232 , V_384 ) ;
}
return error ;
}
int F_149 ( struct V_13 * V_14 )
{
struct V_353 V_354 ;
struct V_389 * V_390 = & V_14 -> V_391 -> V_392 ;
int V_384 = V_14 -> V_392 . V_393 -> V_81 ;
F_145 ( V_14 -> V_36 , V_384 , & V_354 ) ;
V_354 . V_387 = ( F_150 ( V_390 -> V_394 ) *
V_395 ) / 100 ;
F_143 ( V_14 , V_384 , & V_354 ) ;
return 0 ;
}
static void F_151 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_19 * V_20 )
{
struct V_46 * V_47 , * V_396 ;
struct V_19 V_61 ;
struct F_1 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_123 = V_124 ;
F_39 ( & V_61 ) ;
while ( ! F_11 ( V_20 ) ) {
V_47 = F_58 ( V_20 , struct V_46 , V_20 ) ;
if ( V_47 -> V_65 . V_95 ) {
F_59 ( & V_47 -> V_20 ) ;
F_60 ( V_14 , V_47 ) ;
continue;
}
V_396 = V_47 -> V_110 ;
F_152 ( & V_61 , V_20 , & V_396 -> V_20 ) ;
F_81 ( V_14 , V_16 , & V_62 , V_47 , & V_61 ) ;
}
}
void F_153 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
F_154 () ;
F_6 ( V_14 , V_16 ) ;
if ( V_14 -> V_36 -> V_93 . V_179 & V_180 ) {
int V_151 = V_16 -> V_381 ;
while ( ! F_11 ( & V_16 -> V_383 [ V_151 ] ) ) {
F_151 ( V_14 , V_16 , & V_16 -> V_383 [ V_151 ] ) ;
F_45 ( V_151 , V_382 ) ;
}
V_16 -> V_381 = V_151 ;
}
V_16 -> V_375 = NULL ;
V_16 -> V_145 = false ;
F_151 ( V_14 , V_16 , & V_16 -> V_377 ) ;
F_8 ( V_14 , V_16 ) ;
F_155 () ;
}
bool F_156 ( struct V_13 * V_14 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_15 * V_16 ;
int V_125 ;
V_100 V_397 = 0 ;
if ( F_44 ( V_398 , & V_35 -> V_399 ) )
return true ;
F_157 ( V_232 ) ;
for ( V_125 = 0 ; V_125 < V_400 ; V_125 ++ ) {
if ( ! F_141 ( V_14 , V_125 ) )
continue;
if ( ! V_14 -> V_52 . V_16 [ V_125 ] . V_146 )
continue;
if ( F_158 ( V_232 , V_14 -> V_52 . V_16 [ V_125 ] . V_81 ) )
V_397 |= F_159 ( V_125 ) ;
}
if ( V_397 ) {
F_160 ( V_14 , V_401 ) ;
F_15 ( V_35 , V_402 ,
L_4 , V_397 ) ;
}
for ( V_125 = 0 ; V_125 < V_400 ; V_125 ++ ) {
if ( ! F_141 ( V_14 , V_125 ) )
continue;
V_16 = & V_14 -> V_52 . V_16 [ V_125 ] ;
F_153 ( V_14 , V_16 ) ;
}
return ! V_397 ;
}
void F_161 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
F_162 ( V_14 -> V_36 , V_16 -> V_81 ) ;
V_14 -> V_52 . V_379 &= ~ ( 1 << V_16 -> V_81 ) ;
}
void F_16 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_17 * V_18 , * V_403 ;
struct V_19 * V_404 ;
bool V_349 = false ;
if ( V_16 -> V_158 < 0 )
return;
if ( F_44 ( V_405 , & V_35 -> V_399 ) )
return;
F_55 ( & V_14 -> V_406 ) ;
V_404 = & V_14 -> V_391 -> V_29 [ V_16 -> V_158 ] ;
if ( F_11 ( V_404 ) ) {
F_57 ( & V_14 -> V_406 ) ;
return;
}
F_154 () ;
V_403 = F_163 ( V_404 -> V_79 , struct V_17 , V_20 ) ;
while ( ! F_11 ( V_404 ) ) {
bool V_201 = false ;
if ( V_14 -> V_391 -> V_407 )
break;
V_18 = F_58 ( V_404 , struct V_17 , V_20 ) ;
F_136 ( & V_18 -> V_20 ) ;
if ( F_129 ( V_14 , V_16 , V_18 , & V_201 ) )
V_349 = true ;
if ( F_34 ( V_18 ) )
F_9 ( V_14 , V_16 , V_18 ) ;
if ( V_201 )
break;
if ( V_18 == V_403 ) {
if ( ! V_349 )
break;
V_349 = false ;
V_403 = F_163 ( V_404 -> V_79 ,
struct V_17 , V_20 ) ;
}
}
F_155 () ;
F_57 ( & V_14 -> V_406 ) ;
}
void F_164 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_408 ; V_125 ++ ) {
V_16 = V_14 -> V_52 . V_53 [ V_125 ] ;
F_55 ( & V_16 -> V_378 ) ;
F_16 ( V_14 , V_16 ) ;
F_57 ( & V_16 -> V_378 ) ;
}
}
static void F_130 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_19 * V_409 , bool V_410 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_34 * V_35 = F_14 ( V_232 ) ;
struct V_46 * V_47 , * V_109 ;
bool V_411 = false ;
bool V_412 ;
if ( F_11 ( V_409 ) )
return;
V_412 = ! ! ( V_232 -> V_93 . V_179 & V_180 ) ;
V_47 = F_58 ( V_409 , struct V_46 , V_20 ) ;
V_109 = F_163 ( V_409 -> V_79 , struct V_46 , V_20 ) ;
F_15 ( V_35 , V_37 , L_5 ,
V_16 -> V_81 , V_16 -> V_146 ) ;
if ( V_412 && F_11 ( & V_16 -> V_383 [ V_16 -> V_380 ] ) ) {
F_165 ( V_409 , & V_16 -> V_383 [ V_16 -> V_380 ] ) ;
F_45 ( V_16 -> V_380 , V_382 ) ;
V_411 = true ;
} else {
F_165 ( V_409 , & V_16 -> V_377 ) ;
if ( V_16 -> V_375 ) {
F_166 ( V_232 , V_16 -> V_375 , V_47 -> V_312 ) ;
F_15 ( V_35 , V_335 , L_6 ,
V_16 -> V_81 , V_16 -> V_375 ,
F_167 ( V_47 -> V_312 ) , V_47 -> V_92 ) ;
} else if ( ! V_412 )
V_411 = true ;
V_16 -> V_375 = V_109 -> V_92 ;
}
if ( V_411 ) {
F_51 ( V_16 -> V_81 , V_411 ) ;
F_168 ( V_232 , V_16 -> V_81 , V_47 -> V_312 ) ;
F_15 ( V_35 , V_335 , L_7 ,
V_16 -> V_81 , F_167 ( V_47 -> V_312 ) , V_47 -> V_92 ) ;
}
if ( ! V_412 || V_14 -> V_233 ) {
F_51 ( V_16 -> V_81 , V_413 ) ;
F_169 ( V_232 , V_16 -> V_81 ) ;
}
if ( ! V_410 ) {
while ( V_47 ) {
V_16 -> V_146 ++ ;
if ( F_79 ( V_47 ) )
V_16 -> V_147 ++ ;
V_109 = V_47 -> V_110 ;
V_47 = V_109 -> V_107 ;
V_109 -> V_107 = NULL ;
}
}
}
static void F_170 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_3 * V_4 )
{
struct V_5 * V_41 = F_2 ( V_4 ) ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_19 V_61 ;
struct V_46 * V_47 = V_50 -> V_47 ;
F_39 ( & V_61 ) ;
F_12 ( & V_47 -> V_20 , & V_61 ) ;
V_47 -> V_65 . V_191 = 0 ;
if ( V_18 && ( V_41 -> V_11 & V_190 ) ) {
V_47 -> V_65 . V_191 = V_192 ;
F_46 ( V_14 , V_18 , V_47 ) ;
}
V_47 -> V_107 = NULL ;
V_47 -> V_110 = V_47 ;
F_126 ( V_14 , V_47 , V_16 , V_50 -> V_200 ) ;
F_130 ( V_14 , V_16 , & V_61 , false ) ;
F_51 ( V_16 -> V_81 , V_414 ) ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_3 * V_4 ,
int V_200 )
{
struct V_5 * V_41 = F_2 ( V_4 ) ;
struct V_415 * V_416 = V_41 -> V_136 . V_416 ;
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
const struct V_265 * V_266 ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_55 * V_23 = NULL ;
enum V_417 V_324 ;
bool V_418 = false ;
T_2 V_236 ;
if ( V_41 -> V_136 . V_24 &&
V_41 -> V_136 . V_24 -> V_419 . V_420 )
V_418 = true ;
V_266 = F_172 ( V_2 , V_41 ) ;
V_324 = F_173 ( V_4 ) ;
if ( V_8 )
V_23 = (struct V_55 * ) V_8 -> V_25 ;
if ( V_41 -> V_136 . V_24 ) {
struct V_45 * V_24 = V_41 -> V_136 . V_24 ;
V_236 = 2 * V_24 -> V_419 . V_236 ;
} else {
struct V_13 * V_14 = V_2 -> V_33 ;
V_236 = V_14 -> V_391 -> V_421 ;
}
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_16 = - 1 ;
if ( V_416 )
V_50 -> V_177 = V_416 -> V_422 ;
else if ( V_23 && F_174 ( V_78 -> V_84 ) && V_23 -> V_423 > 0 )
V_50 -> V_177 = V_23 -> V_423 ;
else
V_50 -> V_177 = V_178 ;
V_50 -> V_324 = V_324 ;
V_50 -> V_200 = V_200 ;
V_50 -> V_237 = V_236 ;
if ( ! V_266 )
return;
V_50 -> V_271 = V_266 -> V_295 ;
if ( V_418 )
V_50 -> V_271 |= V_266 -> V_296 ;
}
T_2 F_119 ( struct V_13 * V_14 , T_2 V_424 , V_100 V_266 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_425 * V_426 = V_232 -> V_426 ;
if ( ( V_232 -> V_93 . V_179 & V_427 ) && F_175 ( V_426 ) &&
( V_424 == 0x7 ) && ( V_266 < 0x90 ) )
return 0x3 ;
else if ( F_176 ( V_232 ) && F_177 ( V_232 ) &&
F_121 ( V_266 ) )
return 0x2 ;
else
return V_424 ;
}
static struct V_46 * F_97 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
struct V_46 * V_47 ;
int V_428 ;
T_1 V_43 ;
V_47 = F_54 ( V_14 ) ;
if ( ! V_47 ) {
F_15 ( V_35 , V_335 , L_8 ) ;
return NULL ;
}
F_62 ( V_47 ) ;
if ( V_18 && F_178 ( V_78 -> V_84 ) ) {
V_428 = F_179 ( V_78 -> V_429 ) & V_430 ;
V_43 = V_18 -> V_342 ;
V_78 -> V_429 = F_52 ( V_18 -> V_342 << V_44 ) ;
if ( V_428 )
V_78 -> V_429 |= F_52 ( V_428 ) ;
if ( ! F_180 ( V_78 -> V_84 ) )
F_45 ( V_18 -> V_342 , V_73 ) ;
V_47 -> V_65 . V_43 = V_43 ;
}
V_47 -> V_48 = V_4 ;
V_47 -> V_87 = F_181 ( V_14 -> V_86 , V_4 -> V_83 ,
V_4 -> V_263 , V_88 ) ;
if ( F_56 ( F_182 ( V_14 -> V_86 , V_47 -> V_87 ) ) ) {
V_47 -> V_48 = NULL ;
V_47 -> V_87 = 0 ;
F_147 ( F_14 ( V_14 -> V_36 ) ,
L_9 ) ;
F_60 ( V_14 , V_47 ) ;
return NULL ;
}
V_50 -> V_47 = V_47 ;
return V_47 ;
}
void F_183 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_45 * V_24 = V_6 -> V_136 . V_24 ;
struct V_21 * V_22 ;
if ( ! ( V_6 -> V_11 & V_431 ) )
return;
if ( ! V_24 )
return;
V_22 = (struct V_21 * ) V_24 -> V_25 ;
if ( V_6 -> V_11 & V_432 )
V_22 -> V_433 += 0x10 ;
V_78 -> V_429 &= F_52 ( V_430 ) ;
V_78 -> V_429 |= F_52 ( V_22 -> V_433 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_58 * V_59 )
{
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_59 -> V_8 ;
struct V_45 * V_24 = V_6 -> V_136 . V_24 ;
struct V_21 * V_22 ;
struct V_13 * V_14 = V_2 -> V_33 ;
int V_154 = V_4 -> V_263 + V_434 ;
int V_435 , V_436 ;
if ( V_8 )
V_59 -> V_23 = (struct V_55 * ) V_8 -> V_25 ;
else if ( V_24 && F_174 ( V_78 -> V_84 ) ) {
V_22 = ( void * ) V_24 -> V_25 ;
V_59 -> V_23 = & V_22 -> V_437 ;
}
if ( V_6 -> V_136 . V_416 )
V_154 += V_6 -> V_136 . V_416 -> V_438 ;
F_183 ( F_14 ( V_14 -> V_36 ) , V_4 ) ;
if ( ( V_24 && V_24 -> type != V_439 &&
V_24 -> type != V_440 ) ||
! F_174 ( V_78 -> V_84 ) )
V_6 -> V_11 |= V_189 ;
V_435 = F_184 ( V_78 -> V_84 ) ;
V_436 = V_435 & 3 ;
if ( V_436 && V_4 -> V_263 > V_435 ) {
if ( F_185 ( V_4 ) < V_436 )
return - V_441 ;
F_186 ( V_4 , V_436 ) ;
memmove ( V_4 -> V_83 , V_4 -> V_83 + V_436 , V_435 ) ;
}
F_171 ( V_2 , V_8 , V_4 , V_154 ) ;
return 0 ;
}
int F_187 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_58 * V_59 )
{
struct V_77 * V_78 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_59 -> V_8 ;
struct V_45 * V_24 = V_6 -> V_136 . V_24 ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_21 * V_22 = NULL ;
struct V_13 * V_14 = V_2 -> V_33 ;
struct V_15 * V_16 = V_59 -> V_16 ;
struct V_17 * V_18 = NULL ;
struct V_55 * V_23 = NULL ;
struct V_46 * V_47 ;
bool V_442 ;
int V_51 , V_443 ;
if ( V_24 )
V_22 = ( void * ) V_24 -> V_25 ;
V_442 = ! ! ( V_6 -> V_136 . V_11 & V_444 ) ;
V_443 = F_31 ( V_2 , V_4 , V_59 ) ;
if ( V_443 )
return V_443 ;
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_51 = F_33 ( V_4 ) ;
if ( V_442 )
V_16 = V_14 -> V_52 . V_314 ;
if ( V_59 -> V_8 ) {
V_23 = (struct V_55 * ) V_8 -> V_25 ;
V_18 = F_26 ( V_14 , V_23 , V_4 ) ;
}
F_6 ( V_14 , V_16 ) ;
if ( V_16 == V_14 -> V_52 . V_53 [ V_51 ] ) {
V_50 -> V_16 = V_51 ;
++ V_16 -> V_54 ;
}
V_47 = F_97 ( V_14 , V_16 , V_18 , V_4 ) ;
if ( ! V_47 ) {
F_24 ( V_14 , V_16 , V_4 ) ;
if ( V_59 -> V_445 )
F_188 ( V_4 ) ;
else
F_32 ( V_14 -> V_2 , V_4 ) ;
goto V_446;
}
V_47 -> V_65 . V_258 = V_59 -> V_445 ;
if ( V_59 -> V_445 )
V_47 -> V_65 . V_447 = V_448 ;
F_21 ( V_24 , V_8 , V_47 ) ;
F_170 ( V_14 , V_16 , V_18 , V_4 ) ;
V_446:
F_7 ( V_14 , V_16 ) ;
return 0 ;
}
void F_189 ( struct V_1 * V_2 , struct V_45 * V_24 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_2 -> V_33 ;
struct V_58 V_59 = {
. V_16 = V_14 -> V_392 . V_393
} ;
struct V_262 V_6 = {} ;
struct V_77 * V_78 ;
struct V_46 * V_348 = NULL ;
struct V_46 * V_47 ;
F_190 ( V_108 ) ;
int V_148 = 0 ;
int V_449 ;
V_449 =
V_14 -> V_391 -> V_392 . V_394 * 1000 *
V_14 -> V_391 -> V_392 . V_450 / V_451 ;
do {
struct V_40 * V_50 = F_17 ( V_4 ) ;
if ( F_31 ( V_2 , V_4 , & V_59 ) )
break;
V_47 = F_97 ( V_14 , V_59 . V_16 , NULL , V_4 ) ;
if ( ! V_47 )
break;
V_47 -> V_110 = V_47 ;
F_21 ( V_24 , NULL , V_47 ) ;
F_117 ( V_14 , V_47 , & V_6 , V_50 -> V_200 , false ) ;
V_148 += V_6 . V_49 [ 0 ] . V_288 ;
if ( V_348 )
V_348 -> V_107 = V_47 ;
F_12 ( & V_47 -> V_20 , & V_108 ) ;
V_348 = V_47 ;
V_4 = NULL ;
if ( V_148 > V_449 )
break;
V_4 = F_191 ( V_2 , V_24 ) ;
} while( V_4 );
if ( V_4 )
F_32 ( V_2 , V_4 ) ;
if ( F_11 ( & V_108 ) )
return;
V_47 = F_58 ( & V_108 , struct V_46 , V_20 ) ;
V_78 = (struct V_77 * ) V_47 -> V_48 -> V_83 ;
if ( V_78 -> V_84 & F_52 ( V_452 ) ) {
V_78 -> V_84 &= ~ F_52 ( V_452 ) ;
F_53 ( V_14 -> V_86 , V_47 -> V_87 ,
sizeof( * V_78 ) , V_88 ) ;
}
F_6 ( V_14 , V_59 . V_16 ) ;
F_126 ( V_14 , V_47 , V_59 . V_16 , 0 ) ;
F_130 ( V_14 , V_59 . V_16 , & V_108 , false ) ;
F_51 ( V_59 . V_16 -> V_81 , V_414 ) ;
F_7 ( V_14 , V_59 . V_16 ) ;
}
static void F_49 ( struct V_13 * V_14 , struct V_3 * V_4 ,
int V_453 , struct V_15 * V_16 ,
struct V_7 * V_8 )
{
struct V_5 * V_41 = F_2 ( V_4 ) ;
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
int V_435 , V_436 ;
unsigned long V_11 ;
F_15 ( V_35 , V_335 , L_10 , V_4 ) ;
if ( V_14 -> V_36 -> V_454 )
F_192 ( V_455 , & V_14 -> V_36 -> V_454 -> V_456 ) ;
if ( ! ( V_453 & V_75 ) ) {
if ( V_41 -> V_11 & V_316 )
V_41 -> V_11 |= V_457 ;
else
V_41 -> V_11 |= V_458 ;
}
if ( V_41 -> V_11 & V_12 ) {
V_435 = F_184 ( V_78 -> V_84 ) ;
V_436 = V_435 & 3 ;
if ( V_436 && V_4 -> V_263 > V_435 + V_436 ) {
memmove ( V_4 -> V_83 + V_436 , V_4 -> V_83 , V_435 ) ;
F_193 ( V_4 , V_436 ) ;
}
}
F_194 ( & V_14 -> V_459 , V_11 ) ;
if ( ( V_14 -> V_460 & V_461 ) && ! V_16 -> V_146 ) {
V_14 -> V_460 &= ~ V_461 ;
F_15 ( V_35 , V_462 ,
L_11 ,
V_14 -> V_460 & ( V_463 |
V_464 |
V_465 |
V_461 ) ) ;
}
F_195 ( & V_14 -> V_459 , V_11 ) ;
F_24 ( V_14 , V_16 , V_4 ) ;
V_41 -> V_9 . V_10 [ 0 ] = V_8 ;
F_74 ( & V_16 -> V_376 , V_4 ) ;
}
static void F_41 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct V_15 * V_16 , struct V_19 * V_108 ,
struct V_7 * V_8 ,
struct F_1 * V_62 , int V_96 )
{
struct V_3 * V_4 = V_47 -> V_48 ;
struct V_5 * V_41 = F_2 ( V_4 ) ;
unsigned long V_11 ;
int V_453 = 0 ;
if ( ! V_96 )
V_453 |= V_75 ;
if ( V_62 -> V_123 & V_138 )
V_41 -> V_11 |= V_466 ;
F_196 ( V_14 -> V_86 , V_47 -> V_87 , V_4 -> V_263 , V_88 ) ;
V_47 -> V_87 = 0 ;
if ( V_14 -> V_233 )
goto V_467;
if ( V_47 -> V_65 . V_258 ) {
if ( F_197 ( V_448 ,
V_47 -> V_65 . V_447 +
F_198 ( V_468 ) ) )
F_188 ( V_4 ) ;
else
F_199 ( & V_14 -> V_469 ) ;
} else {
F_200 ( V_14 , V_47 , V_62 , V_16 , V_453 ) ;
F_49 ( V_14 , V_4 , V_453 , V_16 , V_8 ) ;
}
V_467:
V_47 -> V_48 = NULL ;
F_194 ( & V_14 -> V_52 . V_89 , V_11 ) ;
F_165 ( V_108 , & V_14 -> V_52 . V_90 ) ;
F_195 ( & V_14 -> V_52 . V_89 , V_11 ) ;
}
static void F_71 ( struct V_13 * V_14 , struct V_46 * V_47 ,
struct F_1 * V_62 , int V_97 , int V_98 ,
int V_96 )
{
struct V_3 * V_4 = V_47 -> V_48 ;
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
struct V_5 * V_41 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_231 * V_232 = V_14 -> V_36 ;
T_2 V_125 , V_470 ;
if ( V_96 )
V_41 -> V_9 . V_471 = V_62 -> V_472 ;
V_470 = V_62 -> V_127 ;
F_25 ( V_470 >= V_2 -> V_473 ) ;
if ( V_41 -> V_11 & V_190 ) {
V_41 -> V_11 |= V_474 ;
F_144 ( V_98 > V_97 ) ;
}
V_41 -> V_9 . V_475 = V_97 ;
V_41 -> V_9 . V_476 = V_97 - V_98 ;
if ( ( V_62 -> V_123 & V_138 ) == 0 &&
( V_41 -> V_11 & V_316 ) == 0 ) {
if ( F_56 ( V_62 -> V_128 & ( V_477 |
V_478 ) ) &&
F_174 ( V_78 -> V_84 ) &&
V_232 -> V_479 >= V_14 -> V_36 -> V_480 . V_481 )
V_41 -> V_9 . V_49 [ V_470 ] . V_76 =
V_2 -> V_482 ;
}
for ( V_125 = V_470 + 1 ; V_125 < V_2 -> V_473 ; V_125 ++ ) {
V_41 -> V_9 . V_49 [ V_125 ] . V_76 = 0 ;
V_41 -> V_9 . V_49 [ V_125 ] . V_151 = - 1 ;
}
V_41 -> V_9 . V_49 [ V_470 ] . V_76 = V_62 -> V_126 + 1 ;
}
static void F_201 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_34 * V_35 = F_14 ( V_232 ) ;
struct V_46 * V_47 , * V_396 , * V_483 = NULL ;
struct V_19 V_61 ;
struct V_484 * V_485 ;
struct F_1 V_62 ;
int V_9 ;
F_15 ( V_35 , V_37 , L_12 ,
V_16 -> V_81 , F_202 ( V_14 -> V_36 , V_16 -> V_81 ) ,
V_16 -> V_375 ) ;
F_6 ( V_14 , V_16 ) ;
for (; ; ) {
if ( F_44 ( V_405 , & V_35 -> V_399 ) )
break;
if ( F_11 ( & V_16 -> V_377 ) ) {
V_16 -> V_375 = NULL ;
F_16 ( V_14 , V_16 ) ;
break;
}
V_47 = F_58 ( & V_16 -> V_377 , struct V_46 , V_20 ) ;
V_483 = NULL ;
if ( V_47 -> V_65 . V_95 ) {
V_483 = V_47 ;
if ( F_203 ( & V_483 -> V_20 , & V_16 -> V_377 ) )
break;
V_47 = F_163 ( V_483 -> V_20 . V_486 , struct V_46 ,
V_20 ) ;
}
V_396 = V_47 -> V_110 ;
V_485 = V_396 -> V_92 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_9 = F_204 ( V_232 , V_485 , & V_62 ) ;
if ( V_9 == - V_487 )
break;
F_51 ( V_16 -> V_81 , V_488 ) ;
V_396 -> V_65 . V_95 = true ;
F_39 ( & V_61 ) ;
if ( ! F_205 ( & V_396 -> V_20 ) )
F_152 ( & V_61 ,
& V_16 -> V_377 , V_396 -> V_20 . V_79 ) ;
if ( V_483 ) {
F_59 ( & V_483 -> V_20 ) ;
F_60 ( V_14 , V_483 ) ;
}
F_81 ( V_14 , V_16 , & V_62 , V_47 , & V_61 ) ;
}
F_8 ( V_14 , V_16 ) ;
}
void F_206 ( struct V_13 * V_14 )
{
struct V_231 * V_232 = V_14 -> V_36 ;
V_100 V_489 = ( ( 1 << V_400 ) - 1 ) & V_232 -> V_490 ;
int V_125 ;
F_154 () ;
for ( V_125 = 0 ; V_125 < V_400 ; V_125 ++ ) {
if ( F_141 ( V_14 , V_125 ) && ( V_489 & ( 1 << V_125 ) ) )
F_201 ( V_14 , & V_14 -> V_52 . V_16 [ V_125 ] ) ;
}
F_155 () ;
}
void F_207 ( struct V_13 * V_14 )
{
struct F_1 V_62 ;
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_231 * V_232 = V_14 -> V_36 ;
struct V_15 * V_16 ;
struct V_46 * V_47 , * V_396 ;
struct V_19 V_61 ;
struct V_19 * V_491 ;
int V_9 ;
F_154 () ;
for (; ; ) {
if ( F_44 ( V_405 , & V_35 -> V_399 ) )
break;
V_9 = F_204 ( V_232 , NULL , ( void * ) & V_62 ) ;
if ( V_9 == - V_487 )
break;
if ( V_9 == - V_388 ) {
F_15 ( V_35 , V_335 , L_13 ) ;
break;
}
if ( V_62 . V_492 == V_14 -> V_392 . V_493 ) {
V_14 -> V_392 . V_494 = true ;
V_14 -> V_392 . V_495 = ! ( V_62 . V_123 & V_144 ) ;
if ( F_208 () ) {
F_209 ( V_14 , NULL ,
V_496 ) ;
}
F_210 ( V_14 ) ;
continue;
}
V_16 = & V_14 -> V_52 . V_16 [ V_62 . V_492 ] ;
F_6 ( V_14 , V_16 ) ;
F_51 ( V_16 -> V_81 , V_488 ) ;
V_491 = & V_16 -> V_383 [ V_16 -> V_381 ] ;
if ( F_11 ( V_491 ) ) {
F_7 ( V_14 , V_16 ) ;
break;
}
V_47 = F_58 ( V_491 , struct V_46 , V_20 ) ;
if ( V_47 -> V_65 . V_95 ) {
F_59 ( & V_47 -> V_20 ) ;
F_60 ( V_14 , V_47 ) ;
V_47 = F_58 ( V_491 , struct V_46 , V_20 ) ;
}
V_396 = V_47 -> V_110 ;
F_39 ( & V_61 ) ;
if ( F_203 ( & V_396 -> V_20 , V_491 ) ) {
F_165 ( V_491 , & V_61 ) ;
F_45 ( V_16 -> V_381 , V_382 ) ;
if ( ! F_11 ( & V_16 -> V_377 ) ) {
struct V_19 V_108 ;
F_39 ( & V_108 ) ;
V_16 -> V_375 = NULL ;
F_165 ( & V_16 -> V_377 , & V_108 ) ;
F_130 ( V_14 , V_16 , & V_108 , true ) ;
}
} else {
V_396 -> V_65 . V_95 = true ;
if ( V_47 != V_396 )
F_152 ( & V_61 , V_491 ,
V_396 -> V_20 . V_79 ) ;
}
F_81 ( V_14 , V_16 , & V_62 , V_47 , & V_61 ) ;
F_8 ( V_14 , V_16 ) ;
}
F_155 () ;
}
static int F_211 ( struct V_13 * V_14 , int V_497 )
{
struct V_498 * V_499 = & V_14 -> V_500 ;
T_2 V_501 = V_14 -> V_36 -> V_93 . V_501 ;
V_499 -> V_502 = V_497 * V_501 ;
V_499 -> V_503 = F_212 ( V_14 -> V_86 , V_499 -> V_502 ,
& V_499 -> V_504 , V_505 ) ;
if ( ! V_499 -> V_503 )
return - V_441 ;
return 0 ;
}
static int F_213 ( struct V_13 * V_14 )
{
int V_506 ;
V_506 = F_211 ( V_14 , V_507 ) ;
if ( ! V_506 )
F_214 ( V_14 -> V_36 , V_14 -> V_500 . V_503 ,
V_14 -> V_500 . V_504 ,
V_507 ) ;
return V_506 ;
}
int F_215 ( struct V_13 * V_14 , int V_508 )
{
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
int error = 0 ;
F_142 ( & V_14 -> V_52 . V_89 ) ;
error = F_216 ( V_14 , & V_14 -> V_52 . V_509 , & V_14 -> V_52 . V_90 ,
L_14 , V_508 , 1 , 1 ) ;
if ( error != 0 ) {
F_147 ( V_35 ,
L_15 , error ) ;
return error ;
}
error = F_216 ( V_14 , & V_14 -> V_392 . V_510 , & V_14 -> V_392 . V_511 ,
L_16 , V_451 , 1 , 1 ) ;
if ( error != 0 ) {
F_147 ( V_35 ,
L_17 , error ) ;
return error ;
}
F_217 ( & V_14 -> V_512 , V_513 ) ;
if ( V_14 -> V_36 -> V_93 . V_179 & V_180 )
error = F_213 ( V_14 ) ;
return error ;
}
void F_218 ( struct V_13 * V_14 , struct V_55 * V_23 )
{
struct V_17 * V_18 ;
int V_30 , V_514 ;
for ( V_30 = 0 ; V_30 < V_343 ; V_30 ++ ) {
V_18 = F_135 ( V_23 , V_30 ) ;
V_18 -> V_23 = V_23 ;
V_18 -> V_30 = V_30 ;
V_18 -> V_66 = V_18 -> V_342 = 0 ;
V_18 -> V_132 = V_515 ;
V_18 -> V_69 = V_18 -> V_72 = 0 ;
V_18 -> V_133 = false ;
V_18 -> V_140 = true ;
V_18 -> V_39 = false ;
F_68 ( & V_18 -> V_60 ) ;
F_39 ( & V_18 -> V_20 ) ;
V_514 = F_10 ( V_30 ) ;
V_18 -> V_16 = V_14 -> V_52 . V_53 [ V_514 ] ;
if ( ! V_23 -> V_8 )
break;
}
}
void F_219 ( struct V_13 * V_14 , struct V_55 * V_23 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_343 ; V_30 ++ ) {
V_18 = F_135 ( V_23 , V_30 ) ;
V_16 = V_18 -> V_16 ;
F_6 ( V_14 , V_16 ) ;
if ( ! F_11 ( & V_18 -> V_20 ) )
F_136 ( & V_18 -> V_20 ) ;
F_48 ( V_14 , V_16 , V_18 ) ;
V_18 -> V_133 = false ;
F_7 ( V_14 , V_16 ) ;
if ( ! V_23 -> V_8 )
break;
}
}
int F_220 ( struct V_13 * V_14 , struct V_3 * V_4 ,
struct V_58 * V_59 )
{
struct V_77 * V_78 = (struct V_77 * ) V_4 -> V_83 ;
struct V_40 * V_50 = F_17 ( V_4 ) ;
struct V_34 * V_35 = F_14 ( V_14 -> V_36 ) ;
struct V_46 * V_47 ;
int V_435 , V_436 ;
V_435 = F_184 ( V_78 -> V_84 ) ;
V_436 = V_435 & 3 ;
if ( V_436 && V_4 -> V_263 > V_435 ) {
if ( F_185 ( V_4 ) < V_436 ) {
F_15 ( V_35 , V_335 ,
L_18 ) ;
return - V_516 ;
}
F_186 ( V_4 , V_436 ) ;
memmove ( V_4 -> V_83 , V_4 -> V_83 + V_436 , V_435 ) ;
}
V_50 -> V_177 = V_178 ;
V_50 -> V_200 = V_4 -> V_263 + V_434 ;
V_50 -> V_324 = V_517 ;
V_47 = F_97 ( V_14 , V_59 -> V_16 , NULL , V_4 ) ;
if ( ! V_47 ) {
F_15 ( V_35 , V_335 , L_19 ) ;
return - V_516 ;
}
F_21 ( V_14 -> V_518 , NULL , V_47 ) ;
F_166 ( V_14 -> V_36 , V_47 -> V_92 , V_47 -> V_312 ) ;
F_221 ( V_14 -> V_36 , V_59 -> V_16 -> V_81 ) ;
F_170 ( V_14 , V_59 -> V_16 , NULL , V_4 ) ;
return 0 ;
}
