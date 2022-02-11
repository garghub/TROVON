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
F_10 ( V_6 -> V_21 -> V_22 , V_6 -> V_21 -> V_23 -> V_24 , V_6 -> V_25 ,
V_20 << V_26 ) ;
}
static void F_11 ( struct V_27 * V_22 , struct V_28 * V_23 ,
struct V_29 * V_30 )
{
F_12 ( V_22 , V_23 , V_30 -> V_31 , V_30 -> V_32 ,
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
static void F_18 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_8 -> V_4 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
struct V_14 * V_45 ;
bool V_46 = false ;
F_19 ( & V_42 ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
while ( ( V_16 = F_20 ( & V_6 -> V_47 ) ) ) {
V_45 = F_6 ( V_16 ) ;
V_30 = V_45 -> V_30 ;
if ( ! V_30 ) {
V_30 = F_21 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
F_22 ( V_2 -> V_40 , V_16 ) ;
continue;
}
}
if ( V_45 -> V_48 ) {
F_5 ( & V_30 -> V_11 , & V_42 ) ;
F_23 ( V_2 , V_6 , V_30 -> V_49 . V_20 ) ;
F_24 ( V_2 , V_30 , V_4 , & V_42 , & V_44 , 0 ) ;
V_46 = true ;
} else {
F_11 ( V_6 -> V_21 -> V_22 , V_6 -> V_21 -> V_23 , V_30 ) ;
F_25 ( V_2 , V_4 , NULL , V_16 ) ;
}
}
if ( V_46 ) {
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , V_6 -> V_50 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_20 )
{
int V_51 , V_52 ;
V_51 = F_26 ( V_6 -> V_50 , V_20 ) ;
V_52 = ( V_6 -> V_53 + V_51 ) & ( V_54 - 1 ) ;
F_27 ( V_52 , V_6 -> V_55 ) ;
while ( V_6 -> V_53 != V_6 -> V_56 && ! F_28 ( V_6 -> V_53 , V_6 -> V_55 ) ) {
F_29 ( V_6 -> V_50 , V_57 ) ;
F_29 ( V_6 -> V_53 , V_54 ) ;
if ( V_6 -> V_58 >= 0 )
V_6 -> V_58 -- ;
}
}
static void F_30 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_20 )
{
int V_51 , V_52 ;
V_51 = F_26 ( V_6 -> V_50 , V_20 ) ;
V_52 = ( V_6 -> V_53 + V_51 ) & ( V_54 - 1 ) ;
F_31 ( V_52 , V_6 -> V_55 ) ;
if ( V_51 >= ( ( V_6 -> V_56 - V_6 -> V_53 ) &
( V_54 - 1 ) ) ) {
V_6 -> V_56 = V_52 ;
F_29 ( V_6 -> V_56 , V_54 ) ;
}
}
static void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_29 * V_30 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
struct V_14 * V_45 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
F_19 ( & V_42 ) ;
while ( ( V_16 = F_20 ( & V_6 -> V_47 ) ) ) {
V_45 = F_6 ( V_16 ) ;
V_30 = V_45 -> V_30 ;
if ( ! V_30 ) {
F_33 ( V_2 , V_16 , V_59 , V_4 ) ;
continue;
}
F_5 ( & V_30 -> V_11 , & V_42 ) ;
F_23 ( V_2 , V_6 , V_30 -> V_49 . V_20 ) ;
F_24 ( V_2 , V_30 , V_4 , & V_42 , & V_44 , 0 ) ;
}
V_6 -> V_60 = V_6 -> V_50 ;
V_6 -> V_56 = V_6 -> V_53 ;
V_6 -> V_58 = - 1 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , int V_61 )
{
struct V_14 * V_45 = F_6 ( V_16 ) ;
struct V_29 * V_30 = V_45 -> V_30 ;
struct V_62 * V_63 ;
int V_64 = V_45 -> V_48 ;
F_35 ( V_4 -> V_65 , V_66 ) ;
V_45 -> V_48 += V_61 ;
if ( V_64 > 0 )
return;
V_63 = (struct V_62 * ) V_16 -> V_67 ;
V_63 -> V_68 |= F_36 ( V_69 ) ;
F_37 ( V_2 -> V_70 , V_30 -> V_71 ,
sizeof( * V_63 ) , V_72 ) ;
}
static struct V_29 * F_38 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = NULL ;
F_39 ( & V_2 -> V_34 . V_73 ) ;
if ( F_40 ( F_41 ( & V_2 -> V_34 . V_74 ) ) ) {
F_42 ( & V_2 -> V_34 . V_73 ) ;
return NULL ;
}
V_30 = F_43 ( & V_2 -> V_34 . V_74 , struct V_29 , V_11 ) ;
F_44 ( & V_30 -> V_11 ) ;
F_42 ( & V_2 -> V_34 . V_73 ) ;
return V_30 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
F_39 ( & V_2 -> V_34 . V_73 ) ;
F_5 ( & V_30 -> V_11 , & V_2 -> V_34 . V_74 ) ;
F_42 ( & V_2 -> V_34 . V_73 ) ;
}
static struct V_29 * F_46 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_29 * V_75 ;
V_75 = F_38 ( V_2 ) ;
if ( F_16 ( ! V_75 ) )
return NULL ;
F_47 ( V_75 ) ;
V_75 -> V_31 = V_30 -> V_31 ;
V_75 -> V_71 = V_30 -> V_71 ;
memcpy ( V_75 -> V_76 , V_30 -> V_76 , V_2 -> V_77 -> V_78 . V_79 ) ;
V_75 -> V_49 = V_30 -> V_49 ;
return V_75 ;
}
static void F_48 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_43 * V_44 , int V_80 ,
int * V_81 , int * V_82 )
{
struct V_14 * V_45 ;
T_1 V_83 = 0 ;
V_84 V_85 [ V_86 >> 5 ] ;
int V_87 ;
int V_88 = 0 ;
* V_82 = 0 ;
* V_81 = 0 ;
V_88 = F_49 ( V_30 ) ;
if ( V_88 ) {
V_83 = V_44 -> V_89 ;
memcpy ( V_85 , & V_44 -> V_90 , V_86 >> 3 ) ;
}
while ( V_30 ) {
V_45 = F_6 ( V_30 -> V_31 ) ;
V_87 = F_26 ( V_83 , V_30 -> V_49 . V_20 ) ;
( * V_81 ) ++ ;
if ( ! V_80 || ( V_88 && ! F_50 ( V_85 , V_87 ) ) )
( * V_82 ) ++ ;
V_30 = V_30 -> V_91 ;
}
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_30 , struct V_41 * V_92 ,
struct V_43 * V_44 , int V_80 )
{
struct V_93 * V_21 = NULL ;
struct V_15 * V_16 ;
struct V_28 * V_23 ;
struct V_94 * V_40 = V_2 -> V_40 ;
struct V_62 * V_63 ;
struct V_17 * V_18 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_91 , * V_95 = V_30 -> V_96 ;
struct V_41 V_42 ;
struct V_97 V_98 ;
T_1 V_83 = 0 , V_99 = 0 , V_100 = 0 , V_101 ;
V_84 V_85 [ V_86 >> 5 ] ;
int V_88 , V_102 , V_103 , V_46 = 0 , V_104 = 0 , V_82 = 0 ;
bool V_105 = true , V_106 ;
struct V_107 V_32 [ 4 ] ;
struct V_14 * V_45 ;
int V_81 ;
T_2 V_25 ;
bool V_108 = ! ! ( V_44 -> V_109 & V_110 ) ;
int V_111 , V_48 ;
int V_58 = - 1 ;
V_16 = V_30 -> V_31 ;
V_63 = (struct V_62 * ) V_16 -> V_67 ;
V_18 = F_7 ( V_16 ) ;
memcpy ( V_32 , V_30 -> V_32 , sizeof( V_32 ) ) ;
V_48 = V_44 -> V_112 + 1 ;
for ( V_111 = 0 ; V_111 < V_44 -> V_113 ; V_111 ++ )
V_48 += V_32 [ V_111 ] . V_61 ;
F_52 () ;
V_23 = F_53 ( V_40 , V_63 -> V_114 , V_63 -> V_115 ) ;
if ( ! V_23 ) {
F_54 () ;
F_19 ( & V_42 ) ;
while ( V_30 ) {
V_91 = V_30 -> V_91 ;
if ( ! V_30 -> V_116 || V_91 != NULL )
F_55 ( & V_30 -> V_11 , & V_42 ) ;
F_24 ( V_2 , V_30 , V_4 , & V_42 , V_44 , 0 ) ;
V_30 = V_91 ;
}
return;
}
V_21 = (struct V_93 * ) V_23 -> V_117 ;
V_25 = F_56 ( V_63 ) [ 0 ] & V_118 ;
V_6 = F_57 ( V_21 , V_25 ) ;
V_101 = V_6 -> V_50 ;
V_106 = V_44 -> V_119 & V_120 ;
if ( V_106 && V_25 != V_44 -> V_6 )
V_80 = false ;
V_88 = F_49 ( V_30 ) ;
memset ( V_85 , 0 , V_86 >> 3 ) ;
if ( V_88 && V_80 ) {
if ( V_44 -> V_119 & V_120 ) {
V_83 = V_44 -> V_89 ;
memcpy ( V_85 , & V_44 -> V_90 , V_86 >> 3 ) ;
} else {
if ( V_2 -> V_77 -> V_121 == V_122 )
V_104 = 1 ;
}
}
F_58 ( & V_98 ) ;
F_48 ( V_2 , V_30 , V_44 , V_80 , & V_81 , & V_82 ) ;
while ( V_30 ) {
T_1 V_20 = V_30 -> V_49 . V_20 ;
V_102 = V_103 = V_46 = 0 ;
V_91 = V_30 -> V_91 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_45 = F_6 ( V_16 ) ;
if ( ! F_59 ( V_6 -> V_50 , V_6 -> V_123 , V_20 ) ) {
V_102 = 1 ;
} else if ( F_50 ( V_85 , F_26 ( V_83 , V_20 ) ) ) {
V_99 ++ ;
} else if ( ! V_88 && V_80 ) {
V_99 ++ ;
} else if ( V_108 ) {
V_103 = 1 ;
} else if ( V_45 -> V_48 < V_124 ) {
if ( V_80 || ! V_21 -> V_125 )
F_34 ( V_2 , V_4 , V_30 -> V_31 ,
V_48 ) ;
V_103 = 1 ;
} else {
V_102 = 1 ;
V_100 ++ ;
V_58 = F_60 ( int , V_58 ,
F_26 ( V_101 , V_20 ) ) ;
}
F_19 ( & V_42 ) ;
if ( V_91 != NULL || ! V_95 -> V_116 )
F_55 ( & V_30 -> V_11 , & V_42 ) ;
if ( ! V_103 ) {
F_23 ( V_2 , V_6 , V_20 ) ;
if ( V_105 && ( V_99 == 1 || V_100 == 1 ) ) {
memcpy ( V_18 -> V_126 . V_32 , V_32 , sizeof( V_32 ) ) ;
F_61 ( V_2 , V_30 , V_44 , V_81 , V_82 , V_80 ) ;
V_105 = false ;
}
F_24 ( V_2 , V_30 , V_4 , & V_42 , V_44 ,
! V_102 ) ;
} else {
if ( V_18 -> V_127 & V_128 ) {
V_18 -> V_127 &= ~ V_128 ;
F_62 ( V_23 ) ;
}
if ( V_30 -> V_91 == NULL && V_95 -> V_116 ) {
struct V_29 * V_75 ;
V_75 = F_46 ( V_2 , V_95 ) ;
if ( ! V_75 ) {
F_23 ( V_2 , V_6 , V_20 ) ;
F_24 ( V_2 , V_30 , V_4 ,
& V_42 , V_44 , 0 ) ;
V_58 = F_60 ( int , V_58 ,
F_26 ( V_101 , V_20 ) ) ;
break;
}
V_45 -> V_30 = V_75 ;
}
F_63 ( & V_98 , V_16 ) ;
}
V_30 = V_91 ;
}
if ( ! F_64 ( & V_98 ) ) {
if ( V_21 -> V_125 )
F_65 ( V_23 , V_6 -> V_25 , true ) ;
F_66 ( & V_98 , & V_6 -> V_47 ) ;
if ( ! V_21 -> V_125 ) {
F_4 ( V_4 , V_6 ) ;
if ( V_44 -> V_109 & ( V_129 | V_130 ) )
V_6 -> V_8 -> V_131 = true ;
}
}
if ( V_58 >= 0 ) {
T_1 V_132 = F_67 ( V_101 , V_58 ) ;
if ( F_59 ( V_6 -> V_50 , V_6 -> V_123 , V_132 ) )
V_6 -> V_58 = F_26 ( V_6 -> V_50 , V_132 ) ;
F_2 ( V_2 , V_4 ) ;
F_9 ( V_6 , F_67 ( V_101 , V_58 + 1 ) ) ;
F_1 ( V_2 , V_4 ) ;
}
F_54 () ;
if ( V_104 )
F_68 ( V_2 , V_133 ) ;
}
static bool F_69 ( struct V_29 * V_30 )
{
struct V_17 * V_134 = F_7 ( V_30 -> V_31 ) ;
return F_70 ( V_30 ) && ! ( V_134 -> V_127 & V_135 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_43 * V_44 , struct V_29 * V_30 ,
struct V_41 * V_42 )
{
struct V_17 * V_134 ;
bool V_80 , V_108 ;
V_80 = ! ( V_44 -> V_109 & V_136 ) ;
V_108 = ! ! ( V_44 -> V_109 & V_110 ) ;
V_4 -> V_137 = false ;
V_4 -> V_138 -- ;
if ( F_69 ( V_30 ) )
V_4 -> V_139 -- ;
if ( ! F_70 ( V_30 ) ) {
if ( ! V_108 ) {
V_134 = F_7 ( V_30 -> V_31 ) ;
memcpy ( V_134 -> V_126 . V_32 , V_30 -> V_32 ,
sizeof( V_134 -> V_126 . V_32 ) ) ;
F_61 ( V_2 , V_30 , V_44 , 1 , V_80 ? 0 : 1 , V_80 ) ;
}
F_24 ( V_2 , V_30 , V_4 , V_42 , V_44 , V_80 ) ;
} else
F_51 ( V_2 , V_4 , V_30 , V_42 , V_44 , V_80 ) ;
if ( ( V_2 -> V_77 -> V_78 . V_140 & V_141 ) && ! V_108 )
F_72 ( V_2 , V_4 ) ;
}
static bool F_73 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_107 * V_32 ;
int V_111 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_18 -> V_126 . V_32 ;
for ( V_111 = 0 ; V_111 < 4 ; V_111 ++ ) {
if ( ! V_32 [ V_111 ] . V_61 || V_32 [ V_111 ] . V_142 < 0 )
break;
if ( ! ( V_32 [ V_111 ] . V_127 & V_143 ) )
return true ;
}
return false ;
}
static V_84 F_74 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_107 * V_32 ;
V_84 V_144 , V_145 ;
T_1 V_146 , V_147 , V_148 = 0 ;
int V_33 = V_6 -> V_8 -> V_4 -> V_149 ;
int V_111 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_144 = V_150 ;
for ( V_111 = 0 ; V_111 < 4 ; V_111 ++ ) {
int V_151 ;
if ( ! V_32 [ V_111 ] . V_61 )
continue;
if ( ! ( V_32 [ V_111 ] . V_127 & V_143 ) ) {
V_148 = 1 ;
break;
}
if ( V_32 [ V_111 ] . V_127 & V_152 )
V_151 = V_153 ;
else
V_151 = V_154 ;
if ( V_32 [ V_111 ] . V_127 & V_155 )
V_151 ++ ;
V_145 = V_2 -> V_34 . V_156 [ V_33 ] [ V_151 ] [ V_32 [ V_111 ] . V_142 ] ;
V_144 = F_75 ( V_144 , V_145 ) ;
}
if ( V_18 -> V_127 & V_135 || V_148 )
return 0 ;
V_146 = F_75 ( V_144 , ( V_84 ) V_150 ) ;
V_147 = F_76 ( V_2 , V_144 ) ;
if ( V_147 )
V_146 = V_147 ;
if ( V_6 -> V_21 -> V_157 )
V_146 = F_75 ( V_146 , V_6 -> V_21 -> V_157 ) ;
return V_146 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_29 * V_30 , T_1 V_145 ,
bool V_158 )
{
#define F_78 60
V_84 V_159 , V_160 ;
T_1 V_161 ;
T_2 V_127 , V_162 ;
int V_163 , V_164 , V_165 , V_166 , V_167 ;
struct V_14 * V_45 = F_6 ( V_30 -> V_31 ) ;
V_166 = F_79 ( V_145 ) ;
if ( ( V_45 -> V_168 != V_169 ) &&
! ( V_2 -> V_77 -> V_78 . V_140 & V_170 ) )
V_166 += V_171 ;
if ( V_158 && ! F_80 ( V_2 -> V_77 ) &&
( V_2 -> V_77 -> V_172 & V_173 ) )
V_166 = F_81 ( V_166 , F_78 ) ;
if ( V_6 -> V_21 -> V_174 == 0 )
return V_166 ;
V_162 = V_30 -> V_32 [ 0 ] . V_142 ;
V_127 = V_30 -> V_32 [ 0 ] . V_127 ;
V_163 = ( V_127 & V_152 ) ? 1 : 0 ;
V_165 = ( V_127 & V_155 ) ? 1 : 0 ;
if ( V_165 )
V_160 = F_82 ( V_6 -> V_21 -> V_174 ) ;
else
V_160 = F_83 ( V_6 -> V_21 -> V_174 ) ;
if ( V_160 == 0 )
V_160 = 1 ;
V_164 = F_84 ( V_162 ) ;
V_159 = V_175 [ V_162 % 8 ] [ V_163 ] * V_164 ;
V_161 = ( V_160 * V_159 ) / V_176 ;
if ( V_145 < V_161 ) {
V_167 = ( V_161 - V_145 ) / V_177 ;
V_166 = F_81 ( V_167 , V_166 ) ;
}
return V_166 ;
}
static struct V_29 *
F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_14 * V_45 ;
struct V_15 * V_16 ;
struct V_29 * V_30 ;
T_1 V_20 ;
while ( 1 ) {
V_16 = F_86 ( & V_6 -> V_47 ) ;
if ( ! V_16 )
break;
V_45 = F_6 ( V_16 ) ;
V_30 = V_45 -> V_30 ;
if ( ! V_45 -> V_30 )
V_30 = F_21 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_87 ( V_16 , & V_6 -> V_47 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
F_22 ( V_2 -> V_40 , V_16 ) ;
continue;
}
V_30 -> V_49 . V_178 = V_179 | V_180 ;
V_20 = V_30 -> V_49 . V_20 ;
if ( ! F_59 ( V_6 -> V_50 , V_6 -> V_123 , V_20 ) )
break;
if ( V_6 -> V_58 > F_26 ( V_6 -> V_50 , V_20 ) ) {
struct V_43 V_44 = {} ;
struct V_41 V_42 ;
F_19 ( & V_42 ) ;
F_88 ( & V_30 -> V_11 , & V_42 ) ;
F_87 ( V_16 , & V_6 -> V_47 ) ;
F_23 ( V_2 , V_6 , V_20 ) ;
F_24 ( V_2 , V_30 , V_4 , & V_42 , & V_44 , 0 ) ;
continue;
}
V_30 -> V_91 = NULL ;
V_30 -> V_96 = V_30 ;
return V_30 ;
}
return NULL ;
}
static enum V_181 F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_41 * V_92 ,
int * V_182 )
{
#define F_90 ( T_3 ) ((4 - ((_len) % 4)) % 4)
struct V_29 * V_30 , * V_183 = NULL , * V_184 = NULL ;
int V_185 = 0 , V_81 = 0 , V_166 , V_186 = 0 ;
T_1 V_146 = 0 , V_187 = 0 , V_188 = 0 ,
V_189 , V_190 = V_6 -> V_123 / 2 ;
enum V_181 V_191 = V_192 ;
struct V_17 * V_18 ;
struct V_14 * V_45 ;
struct V_15 * V_16 ;
do {
V_30 = F_85 ( V_2 , V_4 , V_6 ) ;
if ( ! V_30 ) {
V_191 = V_193 ;
break;
}
V_16 = V_30 -> V_31 ;
V_45 = F_6 ( V_16 ) ;
if ( ! V_183 )
V_183 = V_30 ;
if ( ! V_185 ) {
F_11 ( V_6 -> V_21 -> V_22 , V_6 -> V_21 -> V_23 , V_30 ) ;
V_146 = F_74 ( V_2 , V_30 , V_6 ) ;
V_185 = 1 ;
}
V_189 = V_177 + V_45 -> V_194 ;
if ( V_81 &&
( ( V_146 < ( V_187 + V_188 + V_189 + V_186 ) ) ||
F_73 ( V_30 ) ) ) {
V_191 = V_195 ;
break;
}
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( V_81 && ( V_18 -> V_127 & V_135 ) )
break;
if ( V_81 >= F_75 ( ( int ) V_190 , V_196 ) ) {
V_191 = V_195 ;
break;
}
V_187 += V_188 + V_189 ;
V_166 = F_77 ( V_2 , V_6 , V_183 , V_45 -> V_194 ,
! V_81 ) ;
V_188 = F_90 ( V_189 ) + ( V_166 << 2 ) ;
V_81 ++ ;
V_30 -> V_91 = NULL ;
if ( ! V_45 -> V_48 )
F_30 ( V_2 , V_6 , V_30 -> V_49 . V_20 ) ;
V_30 -> V_49 . V_166 = V_166 ;
F_87 ( V_16 , & V_6 -> V_47 ) ;
F_5 ( & V_30 -> V_11 , V_92 ) ;
if ( V_184 )
V_184 -> V_91 = V_30 ;
V_184 = V_30 ;
} while ( ! F_64 ( & V_6 -> V_47 ) );
* V_182 = V_187 ;
return V_191 ;
#undef F_90
}
static V_84 F_91 ( struct V_1 * V_2 , T_2 V_162 , int V_197 ,
int V_163 , int V_165 , bool V_198 )
{
V_84 V_199 , V_159 , V_200 , V_160 ;
int V_164 ;
V_164 = F_84 ( V_162 ) ;
V_199 = ( V_197 << 3 ) + V_201 ;
V_159 = V_175 [ V_162 % 8 ] [ V_163 ] * V_164 ;
V_160 = ( V_199 + V_159 - 1 ) / V_159 ;
if ( ! V_165 )
V_200 = F_92 ( V_160 ) ;
else
V_200 = F_93 ( V_160 ) ;
V_200 += V_202 + V_203 + V_204 + V_205 + V_206 + F_94 ( V_164 ) ;
return V_200 ;
}
static int F_95 ( int V_207 , int V_208 , bool V_209 , bool V_210 )
{
int V_164 = F_84 ( V_208 ) ;
int V_211 , V_212 ;
int V_213 = 0 ;
V_211 = V_210 ? F_96 ( V_207 ) : F_97 ( V_207 ) ;
V_212 = V_211 * V_175 [ V_208 % 8 ] [ V_209 ] * V_164 ;
V_212 -= V_201 ;
V_213 = V_212 / 8 ;
V_213 -= V_202 + V_203 + V_204 + V_205 + V_206 + F_94 ( V_164 ) ;
if ( V_213 > 65532 )
V_213 = 65532 ;
return V_213 ;
}
void F_98 ( struct V_1 * V_2 , int V_214 , int V_215 )
{
T_1 * V_216 , * V_217 , * V_218 , * V_219 ;
int V_208 ;
if ( ! V_215 || V_215 > 4096 )
V_215 = 4096 ;
V_216 = V_2 -> V_34 . V_156 [ V_214 ] [ V_154 ] ;
V_217 = V_2 -> V_34 . V_156 [ V_214 ] [ V_220 ] ;
V_218 = V_2 -> V_34 . V_156 [ V_214 ] [ V_153 ] ;
V_219 = V_2 -> V_34 . V_156 [ V_214 ] [ V_221 ] ;
for ( V_208 = 0 ; V_208 < 32 ; V_208 ++ ) {
V_216 [ V_208 ] = F_95 ( V_215 , V_208 , false , false ) ;
V_217 [ V_208 ] = F_95 ( V_215 , V_208 , false , true ) ;
V_218 [ V_208 ] = F_95 ( V_215 , V_208 , true , false ) ;
V_219 [ V_208 ] = F_95 ( V_215 , V_208 , true , true ) ;
}
}
static void F_99 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_222 * V_134 , int V_223 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_107 * V_32 ;
const struct V_226 * V_227 ;
struct V_62 * V_63 ;
struct V_14 * V_45 = F_6 ( V_30 -> V_31 ) ;
int V_111 ;
T_2 V_162 = 0 ;
V_16 = V_30 -> V_31 ;
V_18 = F_7 ( V_16 ) ;
V_32 = V_30 -> V_32 ;
V_63 = (struct V_62 * ) V_16 -> V_67 ;
V_134 -> V_228 = ! F_100 ( V_63 -> V_68 ) ;
V_134 -> V_229 = V_45 -> V_229 ;
for ( V_111 = 0 ; V_111 < F_13 ( V_30 -> V_32 ) ; V_111 ++ ) {
bool V_230 , V_231 , V_232 ;
int V_233 ;
if ( ! V_32 [ V_111 ] . V_61 || ( V_32 [ V_111 ] . V_142 < 0 ) )
continue;
V_162 = V_32 [ V_111 ] . V_142 ;
V_134 -> V_32 [ V_111 ] . V_234 = V_32 [ V_111 ] . V_61 ;
if ( V_32 [ V_111 ] . V_127 & V_235 ) {
V_134 -> V_32 [ V_111 ] . V_236 |= V_237 ;
V_134 -> V_127 |= V_238 ;
} else if ( V_32 [ V_111 ] . V_127 & V_239 ) {
V_134 -> V_32 [ V_111 ] . V_236 |= V_237 ;
V_134 -> V_127 |= V_240 ;
}
if ( V_32 [ V_111 ] . V_127 & V_152 )
V_134 -> V_32 [ V_111 ] . V_236 |= V_241 ;
if ( V_32 [ V_111 ] . V_127 & V_155 )
V_134 -> V_32 [ V_111 ] . V_236 |= V_242 ;
V_231 = ! ! ( V_32 [ V_111 ] . V_127 & V_155 ) ;
V_230 = ! ! ( V_32 [ V_111 ] . V_127 & V_152 ) ;
V_232 = ! ! ( V_32 [ V_111 ] . V_127 & V_243 ) ;
if ( V_32 [ V_111 ] . V_127 & V_143 ) {
V_134 -> V_32 [ V_111 ] . V_244 = V_162 | 0x80 ;
V_134 -> V_32 [ V_111 ] . V_245 = F_101 ( V_2 ,
V_225 -> V_246 , V_134 -> V_32 [ V_111 ] . V_244 ) ;
V_134 -> V_32 [ V_111 ] . V_247 = F_91 ( V_2 , V_162 , V_223 ,
V_230 , V_231 , V_232 ) ;
if ( V_162 < 8 && ( V_18 -> V_127 & V_248 ) )
V_134 -> V_32 [ V_111 ] . V_236 |= V_249 ;
continue;
}
V_227 = & V_2 -> V_250 [ V_18 -> V_251 ] . V_252 [ V_32 [ V_111 ] . V_142 ] ;
if ( ( V_18 -> V_251 == V_253 ) &&
! ( V_227 -> V_127 & V_254 ) )
V_233 = V_255 ;
else
V_233 = V_256 ;
V_134 -> V_32 [ V_111 ] . V_244 = V_227 -> V_257 ;
if ( V_227 -> V_258 ) {
if ( V_32 [ V_111 ] . V_127 & V_243 )
V_134 -> V_32 [ V_111 ] . V_244 |= V_227 -> V_258 ;
} else {
V_232 = false ;
}
if ( V_30 -> V_49 . V_259 )
V_134 -> V_32 [ V_111 ] . V_245 = V_225 -> V_246 ;
else
V_134 -> V_32 [ V_111 ] . V_245 = F_101 ( V_2 ,
V_225 -> V_246 , V_134 -> V_32 [ V_111 ] . V_244 ) ;
V_134 -> V_32 [ V_111 ] . V_247 = F_102 ( V_2 -> V_77 ,
V_233 , V_227 -> V_260 * 100 , V_223 , V_162 , V_232 ) ;
}
if ( F_49 ( V_30 ) && ( V_223 > V_2 -> V_77 -> V_78 . V_261 ) )
V_134 -> V_127 &= ~ V_238 ;
if ( V_134 -> V_127 & V_238 )
V_134 -> V_127 &= ~ V_240 ;
}
static enum V_262 F_103 ( struct V_15 * V_16 )
{
struct V_62 * V_63 ;
enum V_262 V_263 ;
T_4 V_264 ;
V_63 = (struct V_62 * ) V_16 -> V_67 ;
V_264 = V_63 -> V_68 ;
if ( F_104 ( V_264 ) )
V_263 = V_265 ;
else if ( F_105 ( V_264 ) )
V_263 = V_266 ;
else if ( F_106 ( V_264 ) )
V_263 = V_267 ;
else if ( F_100 ( V_264 ) )
V_263 = V_268 ;
else
V_263 = V_269 ;
return V_263 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , int V_223 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_29 * V_183 = NULL ;
struct V_222 V_134 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_270 = true ;
V_134 . V_271 = true ;
V_134 . V_272 = V_273 ;
V_134 . V_274 = V_4 -> V_65 ;
while ( V_30 ) {
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_14 * V_45 = F_6 ( V_16 ) ;
bool V_275 = ! ! ( V_30 -> V_49 . V_178 & V_180 ) ;
V_134 . type = F_103 ( V_16 ) ;
if ( V_30 -> V_91 )
V_134 . V_276 = V_30 -> V_91 -> V_277 ;
else
V_134 . V_276 = 0 ;
if ( ! V_183 ) {
V_183 = V_30 ;
V_134 . V_127 = V_278 ;
if ( ( V_18 -> V_127 & V_279 ) ||
V_4 == V_2 -> V_34 . V_35 )
V_134 . V_127 |= V_280 ;
if ( V_18 -> V_127 & V_281 )
V_134 . V_127 |= V_282 ;
if ( V_18 -> V_127 & V_283 )
V_134 . V_127 |= V_284 ;
if ( V_30 -> V_49 . V_259 )
V_134 . V_127 |= ( V_84 ) V_30 -> V_49 . V_259 <<
V_285 ;
F_99 ( V_2 , V_30 , & V_134 , V_223 ) ;
}
V_134 . V_286 [ 0 ] = V_30 -> V_71 ;
V_134 . V_287 [ 0 ] = V_16 -> V_223 ;
V_134 . V_288 = V_45 -> V_194 ;
V_134 . V_168 = V_45 -> V_168 ;
V_134 . V_289 = V_45 -> V_289 ;
if ( V_275 ) {
if ( V_30 == V_183 )
V_134 . V_275 = V_290 ;
else if ( V_30 == V_183 -> V_96 )
V_134 . V_275 = V_291 ;
else
V_134 . V_275 = V_292 ;
V_134 . V_166 = V_30 -> V_49 . V_166 ;
V_134 . V_182 = V_223 ;
}
if ( V_30 == V_183 -> V_96 )
V_183 = NULL ;
F_108 ( V_225 , V_30 -> V_76 , & V_134 ) ;
V_30 = V_30 -> V_91 ;
}
}
static void F_109 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_29 * V_30 ;
enum V_181 V_191 ;
struct V_17 * V_18 ;
struct V_41 V_92 ;
int V_182 ;
do {
if ( F_64 ( & V_6 -> V_47 ) )
return;
F_19 ( & V_92 ) ;
V_191 = F_89 ( V_2 , V_4 , V_6 , & V_92 , & V_182 ) ;
if ( F_41 ( & V_92 ) )
break;
V_30 = F_43 ( & V_92 , struct V_29 , V_11 ) ;
V_30 -> V_96 = F_110 ( V_92 . V_64 , struct V_29 , V_11 ) ;
V_18 = F_7 ( V_30 -> V_31 ) ;
if ( V_6 -> V_8 -> V_131 ) {
V_6 -> V_8 -> V_131 = false ;
V_18 -> V_127 |= V_279 ;
} else {
V_18 -> V_127 &= ~ V_279 ;
}
if ( V_30 == V_30 -> V_96 ) {
V_182 = F_6 ( V_30 -> V_31 ) -> V_194 ;
V_30 -> V_49 . V_178 = V_179 ;
} else {
F_35 ( V_4 -> V_65 , V_293 ) ;
}
F_107 ( V_2 , V_30 , V_4 , V_182 ) ;
F_111 ( V_2 , V_4 , & V_92 , false ) ;
} while ( V_4 -> V_139 < V_294 &&
V_191 != V_193 );
}
int F_112 ( struct V_1 * V_2 , struct V_28 * V_23 ,
T_1 V_6 , T_1 * V_295 )
{
struct V_5 * V_296 ;
struct V_93 * V_21 ;
T_2 V_297 ;
V_21 = (struct V_93 * ) V_23 -> V_117 ;
V_296 = F_57 ( V_21 , V_6 ) ;
if ( V_23 -> V_298 . V_299 ) {
V_21 -> V_157 = 1 << ( V_300 +
V_23 -> V_298 . V_301 ) ;
V_297 = F_113 ( V_23 -> V_298 . V_302 ) ;
V_21 -> V_174 = V_297 ;
}
V_296 -> V_303 = true ;
V_296 -> V_9 = true ;
* V_295 = V_296 -> V_50 = V_296 -> V_60 ;
V_296 -> V_58 = - 1 ;
memset ( V_296 -> V_55 , 0 , sizeof( V_296 -> V_55 ) ) ;
V_296 -> V_53 = V_296 -> V_56 = 0 ;
return 0 ;
}
void F_114 ( struct V_1 * V_2 , struct V_28 * V_23 , T_1 V_6 )
{
struct V_93 * V_21 = (struct V_93 * ) V_23 -> V_117 ;
struct V_5 * V_296 = F_57 ( V_21 , V_6 ) ;
struct V_3 * V_4 = V_296 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_296 -> V_303 = false ;
V_296 -> V_9 = true ;
F_18 ( V_2 , V_296 ) ;
F_3 ( V_2 , V_4 ) ;
}
void F_115 ( struct V_28 * V_23 , struct V_1 * V_2 ,
struct V_93 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
bool V_304 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_305 ; V_25 ++ , V_6 ++ ) {
if ( ! V_6 -> V_10 )
continue;
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_304 = ! F_64 ( & V_6 -> V_47 ) ;
V_6 -> V_10 = false ;
F_44 ( & V_6 -> V_11 ) ;
if ( V_8 -> V_10 ) {
V_8 -> V_10 = false ;
F_44 ( & V_8 -> V_11 ) ;
}
F_2 ( V_2 , V_4 ) ;
F_65 ( V_23 , V_25 , V_304 ) ;
}
}
void F_116 ( struct V_1 * V_2 , struct V_93 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_305 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_8 -> V_131 = true ;
if ( ! F_64 ( & V_6 -> V_47 ) && ! V_6 -> V_9 ) {
F_4 ( V_4 , V_6 ) ;
F_72 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
}
void F_117 ( struct V_1 * V_2 , struct V_28 * V_23 ,
T_1 V_25 )
{
struct V_5 * V_6 ;
struct V_93 * V_21 ;
struct V_3 * V_4 ;
V_21 = (struct V_93 * ) V_23 -> V_117 ;
V_6 = F_57 ( V_21 , V_25 ) ;
V_4 = V_6 -> V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
V_6 -> V_123 = V_306 << V_23 -> V_298 . V_301 ;
V_6 -> V_9 = false ;
if ( ! F_64 ( & V_6 -> V_47 ) ) {
F_4 ( V_4 , V_6 ) ;
F_72 ( V_2 , V_4 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_118 ( struct V_94 * V_40 ,
struct V_28 * V_23 ,
T_1 V_307 , int V_81 ,
enum V_308 V_309 ,
bool V_310 )
{
struct V_1 * V_2 = V_40 -> V_311 ;
struct V_93 * V_21 = (struct V_93 * ) V_23 -> V_117 ;
struct V_3 * V_4 = V_2 -> V_34 . V_35 ;
struct V_17 * V_134 ;
struct V_41 V_92 ;
struct V_29 * V_312 = NULL , * V_30 ;
int V_313 = 0 ;
int V_111 ;
F_19 ( & V_92 ) ;
for ( V_111 = 0 ; V_307 && V_81 ; V_111 ++ , V_307 >>= 1 ) {
struct V_5 * V_6 ;
if ( ! ( V_307 & 1 ) )
continue;
V_6 = F_57 ( V_21 , V_111 ) ;
if ( V_6 -> V_9 )
continue;
F_1 ( V_2 , V_6 -> V_8 -> V_4 ) ;
while ( ! F_64 ( & V_6 -> V_47 ) && V_81 > 0 ) {
V_30 = F_85 ( V_2 , V_2 -> V_34 . V_35 , V_6 ) ;
if ( ! V_30 )
break;
F_87 ( V_30 -> V_31 , & V_6 -> V_47 ) ;
F_5 ( & V_30 -> V_11 , & V_92 ) ;
F_11 ( V_6 -> V_21 -> V_22 , V_6 -> V_21 -> V_23 , V_30 ) ;
F_30 ( V_2 , V_6 , V_30 -> V_49 . V_20 ) ;
V_30 -> V_49 . V_178 &= ~ V_180 ;
if ( V_312 )
V_312 -> V_91 = V_30 ;
V_312 = V_30 ;
V_81 -- ;
V_313 ++ ;
F_35 ( V_4 -> V_65 , V_314 ) ;
if ( F_64 ( & V_6 -> V_47 ) )
F_65 ( V_21 -> V_23 , V_111 , false ) ;
}
F_3 ( V_2 , V_6 -> V_8 -> V_4 ) ;
}
if ( F_41 ( & V_92 ) )
return;
V_134 = F_7 ( V_312 -> V_31 ) ;
V_134 -> V_127 |= V_128 ;
V_30 = F_43 ( & V_92 , struct V_29 , V_11 ) ;
F_1 ( V_2 , V_4 ) ;
F_107 ( V_2 , V_30 , V_4 , 0 ) ;
F_111 ( V_2 , V_4 , & V_92 , false ) ;
F_2 ( V_2 , V_4 ) ;
}
struct V_3 * F_119 ( struct V_1 * V_2 , int V_315 , int V_316 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_317 V_318 ;
static const int V_319 [] = {
[ V_320 ] = V_321 ,
[ V_322 ] = V_323 ,
[ V_324 ] = V_325 ,
[ V_326 ] = V_327 ,
} ;
int V_65 , V_111 ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
V_318 . V_328 = V_319 [ V_316 ] ;
V_318 . V_329 = V_330 ;
V_318 . V_331 = V_330 ;
V_318 . V_332 = V_330 ;
V_318 . V_333 = 0 ;
if ( V_225 -> V_78 . V_140 & V_170 ) {
V_318 . V_334 = V_335 ;
} else {
if ( V_315 == V_336 )
V_318 . V_334 = V_337 ;
else
V_318 . V_334 = V_338 |
V_337 ;
}
V_65 = F_120 ( V_225 , V_315 , & V_318 ) ;
if ( V_65 == - 1 ) {
return NULL ;
}
if ( ! F_121 ( V_2 , V_65 ) ) {
struct V_3 * V_4 = & V_2 -> V_34 . V_4 [ V_65 ] ;
V_4 -> V_65 = V_65 ;
V_4 -> V_149 = - 1 ;
V_4 -> V_339 = NULL ;
F_58 ( & V_4 -> V_340 ) ;
F_19 ( & V_4 -> V_341 ) ;
F_19 ( & V_4 -> V_13 ) ;
F_122 ( & V_4 -> V_342 ) ;
V_4 -> V_138 = 0 ;
V_4 -> V_139 = 0 ;
V_4 -> V_137 = false ;
V_2 -> V_34 . V_343 |= 1 << V_65 ;
V_4 -> V_344 = V_4 -> V_345 = 0 ;
for ( V_111 = 0 ; V_111 < V_346 ; V_111 ++ )
F_19 ( & V_4 -> V_347 [ V_111 ] ) ;
}
return & V_2 -> V_34 . V_4 [ V_65 ] ;
}
int F_123 ( struct V_1 * V_2 , int V_348 ,
struct V_317 * V_349 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
int error = 0 ;
struct V_317 V_318 ;
F_124 ( V_2 -> V_34 . V_4 [ V_348 ] . V_65 != V_348 ) ;
F_125 ( V_225 , V_348 , & V_318 ) ;
V_318 . V_329 = V_349 -> V_329 ;
V_318 . V_331 = V_349 -> V_331 ;
V_318 . V_332 = V_349 -> V_332 ;
V_318 . V_350 = V_349 -> V_350 ;
V_318 . V_351 = V_349 -> V_351 ;
if ( ! F_126 ( V_225 , V_348 , & V_318 ) ) {
F_127 ( F_128 ( V_2 -> V_77 ) ,
L_1 , V_348 ) ;
error = - V_352 ;
} else {
F_129 ( V_225 , V_348 ) ;
}
return error ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_317 V_318 ;
struct V_353 * V_354 = & V_2 -> V_355 ;
int V_348 = V_2 -> V_356 . V_357 -> V_65 ;
F_125 ( V_2 -> V_77 , V_348 , & V_318 ) ;
if ( V_2 -> V_358 . V_359 < V_360 )
V_2 -> V_358 . V_359 = V_360 ;
else if ( V_2 -> V_358 . V_359 > V_361 )
V_2 -> V_358 . V_359 = V_361 ;
V_318 . V_351 = ( V_354 -> V_362 *
V_2 -> V_358 . V_359 ) / 100 ;
F_123 ( V_2 , V_348 , & V_318 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_41 * V_11 )
{
struct V_29 * V_30 , * V_363 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_109 = V_110 ;
F_19 ( & V_42 ) ;
while ( ! F_41 ( V_11 ) ) {
V_30 = F_43 ( V_11 , struct V_29 , V_11 ) ;
if ( V_30 -> V_116 ) {
F_44 ( & V_30 -> V_11 ) ;
F_45 ( V_2 , V_30 ) ;
continue;
}
V_363 = V_30 -> V_96 ;
F_132 ( & V_42 , V_11 , & V_363 -> V_11 ) ;
F_71 ( V_2 , V_4 , & V_44 , V_30 , & V_42 ) ;
}
}
void F_133 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_77 -> V_78 . V_140 & V_170 ) {
int V_142 = V_4 -> V_345 ;
while ( ! F_41 ( & V_4 -> V_347 [ V_142 ] ) ) {
F_131 ( V_2 , V_4 , & V_4 -> V_347 [ V_142 ] ) ;
F_29 ( V_142 , V_346 ) ;
}
V_4 -> V_345 = V_142 ;
}
V_4 -> V_339 = NULL ;
V_4 -> V_137 = false ;
F_131 ( V_2 , V_4 , & V_4 -> V_341 ) ;
F_3 ( V_2 , V_4 ) ;
}
bool F_134 ( struct V_1 * V_2 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_364 * V_365 = F_128 ( V_2 -> V_77 ) ;
struct V_3 * V_4 ;
int V_111 ;
V_84 V_366 = 0 ;
if ( F_28 ( V_367 , & V_2 -> V_368 ) )
return true ;
F_135 ( V_225 ) ;
for ( V_111 = 0 ; V_111 < V_369 ; V_111 ++ ) {
if ( ! F_121 ( V_2 , V_111 ) )
continue;
if ( F_136 ( V_225 , V_2 -> V_34 . V_4 [ V_111 ] . V_65 ) )
V_366 |= F_137 ( V_111 ) ;
}
if ( V_366 )
F_127 ( V_365 , L_2 , V_366 ) ;
for ( V_111 = 0 ; V_111 < V_369 ; V_111 ++ ) {
if ( ! F_121 ( V_2 , V_111 ) )
continue;
V_4 = & V_2 -> V_34 . V_4 [ V_111 ] ;
V_4 -> V_38 = false ;
F_133 ( V_2 , V_4 ) ;
}
return ! V_366 ;
}
void F_138 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_139 ( V_2 -> V_77 , V_4 -> V_65 ) ;
V_2 -> V_34 . V_343 &= ~ ( 1 << V_4 -> V_65 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 , * V_370 , * V_371 ;
struct V_5 * V_6 , * V_372 ;
if ( F_28 ( V_373 , & V_2 -> V_368 ) ||
F_41 ( & V_4 -> V_13 ) ||
V_4 -> V_139 >= V_294 )
return;
F_52 () ;
V_8 = F_43 ( & V_4 -> V_13 , struct V_7 , V_11 ) ;
V_371 = F_110 ( V_4 -> V_13 . V_64 , struct V_7 , V_11 ) ;
F_140 (ac, ac_tmp, &txq->axq_acq, list) {
V_372 = F_110 ( V_8 -> V_12 . V_64 , struct V_5 , V_11 ) ;
F_44 ( & V_8 -> V_11 ) ;
V_8 -> V_10 = false ;
while ( ! F_41 ( & V_8 -> V_12 ) ) {
V_6 = F_43 ( & V_8 -> V_12 , struct V_5 ,
V_11 ) ;
F_44 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
if ( V_6 -> V_9 )
continue;
F_109 ( V_2 , V_4 , V_6 ) ;
if ( ! F_64 ( & V_6 -> V_47 ) )
F_4 ( V_4 , V_6 ) ;
if ( V_6 == V_372 ||
V_4 -> V_139 >= V_294 )
break;
}
if ( ! F_41 ( & V_8 -> V_12 ) && ! V_8 -> V_10 ) {
V_8 -> V_10 = true ;
F_5 ( & V_8 -> V_11 , & V_4 -> V_13 ) ;
}
if ( V_8 == V_371 ||
V_4 -> V_139 >= V_294 )
break;
}
F_54 () ;
}
static void F_111 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_41 * V_374 , bool V_375 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_364 * V_365 = F_128 ( V_225 ) ;
struct V_29 * V_30 , * V_95 ;
bool V_376 = false ;
bool V_377 ;
if ( F_41 ( V_374 ) )
return;
V_377 = ! ! ( V_225 -> V_78 . V_140 & V_170 ) ;
V_30 = F_43 ( V_374 , struct V_29 , V_11 ) ;
V_95 = F_110 ( V_374 -> V_64 , struct V_29 , V_11 ) ;
F_141 ( V_365 , V_378 , L_3 ,
V_4 -> V_65 , V_4 -> V_138 ) ;
if ( V_377 && F_41 ( & V_4 -> V_347 [ V_4 -> V_344 ] ) ) {
F_142 ( V_374 , & V_4 -> V_347 [ V_4 -> V_344 ] ) ;
F_29 ( V_4 -> V_344 , V_346 ) ;
V_376 = true ;
} else {
F_142 ( V_374 , & V_4 -> V_341 ) ;
if ( V_4 -> V_339 ) {
F_143 ( V_225 , V_4 -> V_339 , V_30 -> V_277 ) ;
F_141 ( V_365 , V_379 , L_4 ,
V_4 -> V_65 , V_4 -> V_339 ,
F_144 ( V_30 -> V_277 ) , V_30 -> V_76 ) ;
} else if ( ! V_377 )
V_376 = true ;
V_4 -> V_339 = V_95 -> V_76 ;
}
if ( V_376 ) {
F_35 ( V_4 -> V_65 , V_376 ) ;
F_145 ( V_225 , V_4 -> V_65 , V_30 -> V_277 ) ;
F_141 ( V_365 , V_379 , L_5 ,
V_4 -> V_65 , F_144 ( V_30 -> V_277 ) , V_30 -> V_76 ) ;
}
if ( ! V_377 ) {
F_35 ( V_4 -> V_65 , V_380 ) ;
F_146 ( V_225 , V_4 -> V_65 ) ;
}
if ( ! V_375 ) {
while ( V_30 ) {
V_4 -> V_138 ++ ;
if ( F_69 ( V_30 ) )
V_4 -> V_139 ++ ;
V_30 = V_30 -> V_96 -> V_91 ;
}
}
}
static void F_147 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_15 * V_16 ,
struct V_381 * V_382 )
{
struct V_14 * V_45 = F_6 ( V_16 ) ;
struct V_41 V_42 ;
struct V_29 * V_30 ;
if ( ( ! F_64 ( & V_6 -> V_47 ) || V_6 -> V_9 ||
! F_59 ( V_6 -> V_50 , V_6 -> V_123 , V_6 -> V_60 ) ||
V_4 -> V_139 >= V_294 ) &&
V_4 != V_2 -> V_34 . V_35 ) {
F_35 ( V_4 -> V_65 , V_383 ) ;
F_63 ( & V_6 -> V_47 , V_16 ) ;
if ( ! V_382 -> V_21 || ! V_382 -> V_21 -> V_125 )
F_4 ( V_4 , V_6 ) ;
return;
}
V_30 = F_21 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
F_22 ( V_2 -> V_40 , V_16 ) ;
return;
}
F_11 ( V_6 -> V_21 -> V_22 , V_6 -> V_21 -> V_23 , V_30 ) ;
V_30 -> V_49 . V_178 = V_179 ;
F_19 ( & V_42 ) ;
F_88 ( & V_30 -> V_11 , & V_42 ) ;
F_30 ( V_2 , V_6 , V_30 -> V_49 . V_20 ) ;
F_35 ( V_4 -> V_65 , V_314 ) ;
V_30 -> V_96 = V_30 ;
F_107 ( V_2 , V_30 , V_4 , V_45 -> V_194 ) ;
F_111 ( V_2 , V_4 , & V_42 , false ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_15 * V_16 )
{
struct V_14 * V_45 = F_6 ( V_16 ) ;
struct V_41 V_42 ;
struct V_29 * V_30 ;
V_30 = V_45 -> V_30 ;
F_19 ( & V_42 ) ;
F_5 ( & V_30 -> V_11 , & V_42 ) ;
V_30 -> V_49 . V_178 = 0 ;
V_30 -> V_91 = NULL ;
V_30 -> V_96 = V_30 ;
F_107 ( V_2 , V_30 , V_4 , V_45 -> V_194 ) ;
F_111 ( V_2 , V_4 , & V_42 , false ) ;
F_35 ( V_4 -> V_65 , V_384 ) ;
}
static void F_148 ( struct V_94 * V_40 ,
struct V_28 * V_23 ,
struct V_15 * V_16 ,
int V_194 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_385 * V_386 = V_18 -> V_126 . V_386 ;
struct V_62 * V_63 = (struct V_62 * ) V_16 -> V_67 ;
const struct V_226 * V_227 ;
struct V_14 * V_45 = F_6 ( V_16 ) ;
struct V_93 * V_21 = NULL ;
enum V_387 V_289 ;
bool V_388 = false ;
if ( V_18 -> V_126 . V_22 &&
V_18 -> V_126 . V_22 -> V_389 . V_390 )
V_388 = true ;
V_227 = F_149 ( V_40 , V_18 ) ;
V_289 = F_150 ( V_16 ) ;
if ( V_23 )
V_21 = (struct V_93 * ) V_23 -> V_117 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
if ( V_386 )
V_45 -> V_168 = V_386 -> V_391 ;
else if ( V_21 && F_151 ( V_63 -> V_68 ) && V_21 -> V_392 > 0 )
V_45 -> V_168 = V_21 -> V_392 ;
else
V_45 -> V_168 = V_169 ;
V_45 -> V_289 = V_289 ;
V_45 -> V_194 = V_194 ;
V_45 -> V_229 = V_227 -> V_257 ;
if ( V_388 )
V_45 -> V_229 |= V_227 -> V_258 ;
}
T_2 F_101 ( struct V_1 * V_2 , T_2 V_393 , V_84 V_227 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_394 * V_395 = V_225 -> V_395 ;
if ( ( V_225 -> V_78 . V_140 & V_396 ) &&
( V_395 -> V_397 & V_398 ) &&
( V_393 == 0x7 ) && ( V_227 < 0x90 ) )
return 0x3 ;
else if ( F_152 ( V_225 ) && F_153 ( V_225 ) &&
F_154 ( V_227 ) )
return 0x2 ;
else
return V_393 ;
}
static struct V_29 * F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
struct V_364 * V_365 = F_128 ( V_2 -> V_77 ) ;
struct V_14 * V_45 = F_6 ( V_16 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_16 -> V_67 ;
struct V_29 * V_30 ;
int V_399 ;
T_1 V_20 ;
V_30 = F_38 ( V_2 ) ;
if ( ! V_30 ) {
F_141 ( V_365 , V_379 , L_6 ) ;
return NULL ;
}
F_47 ( V_30 ) ;
if ( V_6 ) {
V_399 = F_155 ( V_63 -> V_400 ) & V_401 ;
V_20 = V_6 -> V_60 ;
V_63 -> V_400 = F_36 ( V_6 -> V_60 << V_26 ) ;
if ( V_399 )
V_63 -> V_400 |= F_36 ( V_399 ) ;
if ( ! F_156 ( V_63 -> V_68 ) )
F_29 ( V_6 -> V_60 , V_57 ) ;
V_30 -> V_49 . V_20 = V_20 ;
}
V_30 -> V_31 = V_16 ;
V_30 -> V_71 = F_157 ( V_2 -> V_70 , V_16 -> V_67 ,
V_16 -> V_223 , V_72 ) ;
if ( F_40 ( F_158 ( V_2 -> V_70 , V_30 -> V_71 ) ) ) {
V_30 -> V_31 = NULL ;
V_30 -> V_71 = 0 ;
F_127 ( F_128 ( V_2 -> V_77 ) ,
L_7 ) ;
F_45 ( V_2 , V_30 ) ;
return NULL ;
}
V_45 -> V_30 = V_30 ;
return V_30 ;
}
static int F_159 ( struct V_94 * V_40 , struct V_15 * V_16 ,
struct V_381 * V_382 )
{
struct V_62 * V_63 = (struct V_62 * ) V_16 -> V_67 ;
struct V_17 * V_134 = F_7 ( V_16 ) ;
struct V_28 * V_23 = V_382 -> V_23 ;
struct V_27 * V_22 = V_134 -> V_126 . V_22 ;
struct V_1 * V_2 = V_40 -> V_311 ;
int V_145 = V_16 -> V_223 + V_402 ;
int V_403 , V_404 ;
if ( V_23 )
V_382 -> V_21 = (struct V_93 * ) V_23 -> V_117 ;
if ( V_134 -> V_126 . V_386 )
V_145 += V_134 -> V_126 . V_386 -> V_405 ;
if ( V_134 -> V_127 & V_406 ) {
if ( V_134 -> V_127 & V_407 )
V_2 -> V_34 . V_408 += 0x10 ;
V_63 -> V_400 &= F_36 ( V_401 ) ;
V_63 -> V_400 |= F_36 ( V_2 -> V_34 . V_408 ) ;
}
if ( ( V_22 && V_22 -> type != V_409 &&
V_22 -> type != V_410 ) ||
! F_151 ( V_63 -> V_68 ) )
V_134 -> V_127 |= V_279 ;
V_403 = F_160 ( V_63 -> V_68 ) ;
V_404 = V_403 & 3 ;
if ( V_404 && V_16 -> V_223 > V_403 ) {
if ( F_161 ( V_16 ) < V_404 )
return - V_411 ;
F_162 ( V_16 , V_404 ) ;
memmove ( V_16 -> V_67 , V_16 -> V_67 + V_404 , V_403 ) ;
}
F_148 ( V_40 , V_23 , V_16 , V_145 ) ;
return 0 ;
}
int F_163 ( struct V_94 * V_40 , struct V_15 * V_16 ,
struct V_381 * V_382 )
{
struct V_62 * V_63 ;
struct V_17 * V_134 = F_7 ( V_16 ) ;
struct V_28 * V_23 = V_382 -> V_23 ;
struct V_27 * V_22 = V_134 -> V_126 . V_22 ;
struct V_1 * V_2 = V_40 -> V_311 ;
struct V_3 * V_4 = V_382 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_29 * V_30 ;
T_2 V_25 ;
int V_33 ;
int V_412 ;
V_412 = F_159 ( V_40 , V_16 , V_382 ) ;
if ( V_412 )
return V_412 ;
V_63 = (struct V_62 * ) V_16 -> V_67 ;
V_33 = F_15 ( V_16 ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 == V_2 -> V_34 . V_36 [ V_33 ] &&
++ V_4 -> V_37 > V_2 -> V_34 . V_39 [ V_33 ] &&
! V_4 -> V_38 ) {
F_164 ( V_2 -> V_40 , V_33 ) ;
V_4 -> V_38 = true ;
}
if ( V_134 -> V_127 & V_413 ) {
F_2 ( V_2 , V_4 ) ;
V_4 = V_2 -> V_34 . V_35 ;
F_1 ( V_2 , V_4 ) ;
}
if ( V_382 -> V_21 && F_165 ( V_63 -> V_68 ) ) {
V_25 = F_56 ( V_63 ) [ 0 ] &
V_118 ;
V_6 = F_57 ( V_382 -> V_21 , V_25 ) ;
F_16 ( V_6 -> V_8 -> V_4 != V_382 -> V_4 ) ;
}
if ( ( V_134 -> V_127 & V_414 ) && V_6 ) {
F_147 ( V_2 , V_4 , V_6 , V_16 , V_382 ) ;
goto V_415;
}
V_30 = F_21 ( V_2 , V_4 , V_6 , V_16 ) ;
if ( ! V_30 ) {
F_14 ( V_2 , V_4 , V_16 ) ;
if ( V_382 -> V_416 )
F_166 ( V_16 ) ;
else
F_22 ( V_2 -> V_40 , V_16 ) ;
goto V_415;
}
V_30 -> V_49 . V_259 = V_382 -> V_416 ;
if ( V_382 -> V_416 )
V_30 -> V_49 . V_417 = V_418 ;
F_11 ( V_22 , V_23 , V_30 ) ;
F_25 ( V_2 , V_4 , V_6 , V_16 ) ;
V_415:
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
void F_167 ( struct V_94 * V_40 , struct V_27 * V_22 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_40 -> V_311 ;
struct V_381 V_382 = {
. V_4 = V_2 -> V_356 . V_357
} ;
struct V_222 V_134 = {} ;
struct V_62 * V_63 ;
struct V_29 * V_312 = NULL ;
struct V_29 * V_30 ;
F_168 ( V_92 ) ;
int V_200 = 0 ;
int V_419 ;
V_419 =
V_2 -> V_355 . V_362 * 1000 *
V_2 -> V_355 . V_420 / V_421 ;
do {
struct V_14 * V_45 = F_6 ( V_16 ) ;
if ( F_159 ( V_40 , V_16 , & V_382 ) )
break;
V_30 = F_21 ( V_2 , V_382 . V_4 , NULL , V_16 ) ;
if ( ! V_30 )
break;
V_30 -> V_96 = V_30 ;
F_11 ( V_22 , NULL , V_30 ) ;
F_99 ( V_2 , V_30 , & V_134 , V_45 -> V_194 ) ;
V_200 += V_134 . V_32 [ 0 ] . V_247 ;
if ( V_312 )
V_312 -> V_91 = V_30 ;
F_5 ( & V_30 -> V_11 , & V_92 ) ;
V_312 = V_30 ;
V_16 = NULL ;
if ( V_200 > V_419 )
break;
V_16 = F_169 ( V_40 , V_22 ) ;
} while( V_16 );
if ( V_16 )
F_22 ( V_40 , V_16 ) ;
if ( F_41 ( & V_92 ) )
return;
V_30 = F_43 ( & V_92 , struct V_29 , V_11 ) ;
V_63 = (struct V_62 * ) V_30 -> V_31 -> V_67 ;
if ( V_63 -> V_68 & V_422 ) {
V_63 -> V_68 &= ~ V_422 ;
F_37 ( V_2 -> V_70 , V_30 -> V_71 ,
sizeof( * V_63 ) , V_72 ) ;
}
F_1 ( V_2 , V_382 . V_4 ) ;
F_107 ( V_2 , V_30 , V_382 . V_4 , 0 ) ;
F_111 ( V_2 , V_382 . V_4 , & V_92 , false ) ;
F_35 ( V_382 . V_4 -> V_65 , V_384 ) ;
F_2 ( V_2 , V_382 . V_4 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_423 , struct V_3 * V_4 )
{
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_364 * V_365 = F_128 ( V_2 -> V_77 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_16 -> V_67 ;
int V_403 , V_404 ;
unsigned long V_127 ;
F_141 ( V_365 , V_379 , L_8 , V_16 ) ;
if ( V_2 -> V_77 -> V_424 )
V_2 -> V_77 -> V_424 -> V_425 = true ;
if ( ! ( V_423 & V_59 ) )
V_18 -> V_127 |= V_426 ;
V_403 = F_160 ( V_63 -> V_68 ) ;
V_404 = V_403 & 3 ;
if ( V_404 && V_16 -> V_223 > V_403 + V_404 ) {
memmove ( V_16 -> V_67 + V_404 , V_16 -> V_67 , V_403 ) ;
F_170 ( V_16 , V_404 ) ;
}
F_171 ( & V_2 -> V_427 , V_127 ) ;
if ( ( V_2 -> V_428 & V_429 ) && ! V_4 -> V_138 ) {
V_2 -> V_428 &= ~ V_429 ;
F_141 ( V_365 , V_430 ,
L_9 ,
V_2 -> V_428 & ( V_431 |
V_432 |
V_433 |
V_429 ) ) ;
}
F_172 ( & V_2 -> V_427 , V_127 ) ;
F_63 ( & V_4 -> V_340 , V_16 ) ;
F_14 ( V_2 , V_4 , V_16 ) ;
}
static void F_24 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_4 , struct V_41 * V_92 ,
struct V_43 * V_44 , int V_80 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
unsigned long V_127 ;
int V_423 = 0 ;
if ( ! V_80 )
V_423 |= V_59 ;
if ( V_44 -> V_109 & V_129 )
V_18 -> V_127 |= V_434 ;
F_173 ( V_2 -> V_70 , V_30 -> V_71 , V_16 -> V_223 , V_72 ) ;
V_30 -> V_71 = 0 ;
if ( V_30 -> V_49 . V_259 ) {
if ( F_174 ( V_418 ,
V_30 -> V_49 . V_417 +
F_175 ( V_435 ) ) )
F_166 ( V_16 ) ;
else
F_176 ( & V_2 -> V_436 ) ;
} else {
F_177 ( V_2 , V_30 , V_44 , V_4 , V_423 ) ;
F_33 ( V_2 , V_16 , V_423 , V_4 ) ;
}
V_30 -> V_31 = NULL ;
F_171 ( & V_2 -> V_34 . V_73 , V_127 ) ;
F_142 ( V_92 , & V_2 -> V_34 . V_74 ) ;
F_172 ( & V_2 -> V_34 . V_73 , V_127 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_43 * V_44 , int V_81 , int V_82 ,
int V_80 )
{
struct V_15 * V_16 = V_30 -> V_31 ;
struct V_62 * V_63 = (struct V_62 * ) V_16 -> V_67 ;
struct V_17 * V_18 = F_7 ( V_16 ) ;
struct V_94 * V_40 = V_2 -> V_40 ;
struct V_224 * V_225 = V_2 -> V_77 ;
T_2 V_111 , V_437 ;
if ( V_80 )
V_18 -> V_191 . V_438 = V_44 -> V_439 ;
V_437 = V_44 -> V_113 ;
F_16 ( V_437 >= V_40 -> V_440 ) ;
if ( V_18 -> V_127 & V_414 ) {
V_18 -> V_127 |= V_441 ;
F_124 ( V_82 > V_81 ) ;
}
V_18 -> V_191 . V_442 = V_81 ;
V_18 -> V_191 . V_443 = V_81 - V_82 ;
if ( ( V_44 -> V_109 & V_129 ) == 0 &&
( V_18 -> V_127 & V_281 ) == 0 ) {
if ( F_40 ( V_44 -> V_119 & ( V_444 |
V_445 ) ) &&
F_151 ( V_63 -> V_68 ) &&
V_225 -> V_446 >= V_2 -> V_77 -> V_358 . V_447 )
V_18 -> V_191 . V_32 [ V_437 ] . V_61 =
V_40 -> V_448 ;
}
for ( V_111 = V_437 + 1 ; V_111 < V_40 -> V_440 ; V_111 ++ ) {
V_18 -> V_191 . V_32 [ V_111 ] . V_61 = 0 ;
V_18 -> V_191 . V_32 [ V_111 ] . V_142 = - 1 ;
}
V_18 -> V_191 . V_32 [ V_437 ] . V_61 = V_44 -> V_112 + 1 ;
}
static void F_178 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_364 * V_365 = F_128 ( V_225 ) ;
struct V_29 * V_30 , * V_363 , * V_449 = NULL ;
struct V_41 V_42 ;
struct V_450 * V_451 ;
struct V_43 V_44 ;
int V_191 ;
F_141 ( V_365 , V_378 , L_10 ,
V_4 -> V_65 , F_179 ( V_2 -> V_77 , V_4 -> V_65 ) ,
V_4 -> V_339 ) ;
F_1 ( V_2 , V_4 ) ;
for (; ; ) {
if ( F_28 ( V_373 , & V_2 -> V_368 ) )
break;
if ( F_41 ( & V_4 -> V_341 ) ) {
V_4 -> V_339 = NULL ;
if ( V_2 -> V_77 -> V_78 . V_140 & V_141 )
F_72 ( V_2 , V_4 ) ;
break;
}
V_30 = F_43 ( & V_4 -> V_341 , struct V_29 , V_11 ) ;
V_449 = NULL ;
if ( V_30 -> V_116 ) {
V_449 = V_30 ;
if ( F_180 ( & V_449 -> V_11 , & V_4 -> V_341 ) )
break;
V_30 = F_110 ( V_449 -> V_11 . V_452 , struct V_29 ,
V_11 ) ;
}
V_363 = V_30 -> V_96 ;
V_451 = V_363 -> V_76 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_191 = F_181 ( V_225 , V_451 , & V_44 ) ;
if ( V_191 == - V_453 )
break;
F_35 ( V_4 -> V_65 , V_454 ) ;
V_363 -> V_116 = true ;
F_19 ( & V_42 ) ;
if ( ! F_182 ( & V_363 -> V_11 ) )
F_132 ( & V_42 ,
& V_4 -> V_341 , V_363 -> V_11 . V_64 ) ;
if ( V_449 ) {
F_44 ( & V_449 -> V_11 ) ;
F_45 ( V_2 , V_449 ) ;
}
F_71 ( V_2 , V_4 , & V_44 , V_30 , & V_42 ) ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_183 ( struct V_1 * V_2 )
{
struct V_224 * V_225 = V_2 -> V_77 ;
V_84 V_455 = ( ( 1 << V_369 ) - 1 ) & V_225 -> V_456 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < V_369 ; V_111 ++ ) {
if ( F_121 ( V_2 , V_111 ) && ( V_455 & ( 1 << V_111 ) ) )
F_178 ( V_2 , & V_2 -> V_34 . V_4 [ V_111 ] ) ;
}
}
void F_184 ( struct V_1 * V_2 )
{
struct V_43 V_44 ;
struct V_364 * V_365 = F_128 ( V_2 -> V_77 ) ;
struct V_224 * V_225 = V_2 -> V_77 ;
struct V_3 * V_4 ;
struct V_29 * V_30 , * V_363 ;
struct V_41 V_42 ;
struct V_41 * V_457 ;
int V_191 ;
for (; ; ) {
if ( F_28 ( V_373 , & V_2 -> V_368 ) )
break;
V_191 = F_181 ( V_225 , NULL , ( void * ) & V_44 ) ;
if ( V_191 == - V_453 )
break;
if ( V_191 == - V_352 ) {
F_141 ( V_365 , V_379 , L_11 ) ;
break;
}
if ( V_44 . V_458 == V_2 -> V_356 . V_459 ) {
V_2 -> V_356 . V_460 = true ;
V_2 -> V_356 . V_461 = ! ( V_44 . V_109 & V_136 ) ;
continue;
}
V_4 = & V_2 -> V_34 . V_4 [ V_44 . V_458 ] ;
F_1 ( V_2 , V_4 ) ;
F_35 ( V_4 -> V_65 , V_454 ) ;
V_457 = & V_4 -> V_347 [ V_4 -> V_345 ] ;
if ( F_41 ( V_457 ) ) {
F_2 ( V_2 , V_4 ) ;
return;
}
V_30 = F_43 ( V_457 , struct V_29 , V_11 ) ;
if ( V_30 -> V_116 ) {
F_44 ( & V_30 -> V_11 ) ;
F_45 ( V_2 , V_30 ) ;
V_30 = F_43 ( V_457 , struct V_29 , V_11 ) ;
}
V_363 = V_30 -> V_96 ;
F_19 ( & V_42 ) ;
if ( F_180 ( & V_363 -> V_11 , V_457 ) ) {
F_142 ( V_457 , & V_42 ) ;
F_29 ( V_4 -> V_345 , V_346 ) ;
if ( ! F_41 ( & V_4 -> V_341 ) ) {
struct V_41 V_92 ;
F_19 ( & V_92 ) ;
V_4 -> V_339 = NULL ;
F_142 ( & V_4 -> V_341 , & V_92 ) ;
F_111 ( V_2 , V_4 , & V_92 , true ) ;
}
} else {
V_363 -> V_116 = true ;
if ( V_30 != V_363 )
F_132 ( & V_42 , V_457 ,
V_363 -> V_11 . V_64 ) ;
}
F_71 ( V_2 , V_4 , & V_44 , V_30 , & V_42 ) ;
F_3 ( V_2 , V_4 ) ;
}
}
static int F_185 ( struct V_1 * V_2 , int V_462 )
{
struct V_463 * V_464 = & V_2 -> V_465 ;
T_2 V_466 = V_2 -> V_77 -> V_78 . V_466 ;
V_464 -> V_467 = V_462 * V_466 ;
V_464 -> V_468 = F_186 ( V_2 -> V_70 , V_464 -> V_467 ,
& V_464 -> V_469 , V_470 ) ;
if ( ! V_464 -> V_468 )
return - V_411 ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 )
{
int V_471 ;
V_471 = F_185 ( V_2 , V_472 ) ;
if ( ! V_471 )
F_188 ( V_2 -> V_77 , V_2 -> V_465 . V_468 ,
V_2 -> V_465 . V_469 ,
V_472 ) ;
return V_471 ;
}
int F_189 ( struct V_1 * V_2 , int V_473 )
{
struct V_364 * V_365 = F_128 ( V_2 -> V_77 ) ;
int error = 0 ;
F_122 ( & V_2 -> V_34 . V_73 ) ;
error = F_190 ( V_2 , & V_2 -> V_34 . V_474 , & V_2 -> V_34 . V_74 ,
L_12 , V_473 , 1 , 1 ) ;
if ( error != 0 ) {
F_127 ( V_365 ,
L_13 , error ) ;
return error ;
}
error = F_190 ( V_2 , & V_2 -> V_356 . V_475 , & V_2 -> V_356 . V_476 ,
L_14 , V_421 , 1 , 1 ) ;
if ( error != 0 ) {
F_127 ( V_365 ,
L_15 , error ) ;
return error ;
}
F_191 ( & V_2 -> V_477 , V_478 ) ;
if ( V_2 -> V_77 -> V_78 . V_140 & V_170 )
error = F_187 ( V_2 ) ;
return error ;
}
void F_192 ( struct V_1 * V_2 , struct V_93 * V_21 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_25 , V_479 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_305 ;
V_25 ++ , V_6 ++ ) {
V_6 -> V_21 = V_21 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_50 = V_6 -> V_60 = 0 ;
V_6 -> V_123 = V_480 ;
V_6 -> V_53 = V_6 -> V_56 = 0 ;
V_6 -> V_10 = false ;
V_6 -> V_9 = false ;
V_6 -> V_303 = false ;
F_58 ( & V_6 -> V_47 ) ;
V_479 = F_193 ( V_25 ) ;
V_6 -> V_8 = & V_21 -> V_8 [ V_479 ] ;
}
for ( V_479 = 0 , V_8 = & V_21 -> V_8 [ V_479 ] ;
V_479 < V_481 ; V_479 ++ , V_8 ++ ) {
V_8 -> V_10 = false ;
V_8 -> V_4 = V_2 -> V_34 . V_36 [ V_479 ] ;
F_19 ( & V_8 -> V_12 ) ;
}
}
void F_194 ( struct V_1 * V_2 , struct V_93 * V_21 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_25 ;
for ( V_25 = 0 , V_6 = & V_21 -> V_6 [ V_25 ] ;
V_25 < V_305 ; V_25 ++ , V_6 ++ ) {
V_8 = V_6 -> V_8 ;
V_4 = V_8 -> V_4 ;
F_1 ( V_2 , V_4 ) ;
if ( V_6 -> V_10 ) {
F_44 ( & V_6 -> V_11 ) ;
V_6 -> V_10 = false ;
}
if ( V_8 -> V_10 ) {
F_44 ( & V_8 -> V_11 ) ;
V_6 -> V_8 -> V_10 = false ;
}
F_32 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_303 = false ;
F_2 ( V_2 , V_4 ) ;
}
}
