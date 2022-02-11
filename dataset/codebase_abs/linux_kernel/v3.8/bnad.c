static void
F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_2 ) ;
F_3 ( & V_1 -> V_3 , & V_4 ) ;
V_1 -> V_5 = V_6 ++ ;
F_4 ( & V_2 ) ;
}
static void
F_5 ( struct V_1 * V_1 )
{
F_2 ( & V_2 ) ;
F_6 ( & V_1 -> V_3 ) ;
F_4 ( & V_2 ) ;
}
static void
F_7 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
V_10 = & ( (struct V_9 * ) V_8 -> V_13 ) [ V_11 ] ;
V_10 -> V_14 = 0 ;
}
}
static T_1
F_8 ( struct V_1 * V_1 ,
struct V_15 * V_16 ,
T_1 V_12 , T_1 V_17 )
{
struct V_15 * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_22 ;
V_18 = & V_16 [ V_17 ] ;
V_22 = V_18 -> V_22 ;
V_20 = V_18 -> V_20 ;
V_18 -> V_20 = NULL ;
V_18 -> V_22 = 0 ;
F_9 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_25 [ 0 ] , V_26 ) ,
F_11 ( V_20 ) , V_27 ) ;
F_12 ( & V_18 -> V_25 [ 0 ] , V_26 , 0 ) ;
V_22 -- ;
V_21 = 0 ;
while ( V_22 ) {
V_21 ++ ;
if ( V_21 == V_28 ) {
V_21 = 0 ;
F_13 ( V_17 , V_12 ) ;
V_18 = & V_16 [ V_17 ] ;
}
F_14 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_25 [ V_21 ] , V_26 ) ,
F_15 ( V_20 ) -> V_29 [ V_22 ] . V_30 , V_27 ) ;
F_12 ( & V_18 -> V_25 [ V_21 ] , V_26 , 0 ) ;
V_22 -- ;
}
F_13 ( V_17 , V_12 ) ;
return V_17 ;
}
static void
F_16 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_32 -> V_16 ;
struct V_19 * V_20 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_32 -> V_12 ; V_11 ++ ) {
V_20 = V_16 [ V_11 ] . V_20 ;
if ( ! V_20 )
continue;
F_8 ( V_1 , V_16 , V_32 -> V_12 , V_11 ) ;
F_17 ( V_20 ) ;
}
}
static T_1
F_18 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
T_1 V_33 = 0 , V_34 = 0 ;
T_1 V_35 , V_36 , V_37 , V_38 , V_12 ;
struct V_15 * V_16 = V_32 -> V_16 ;
struct V_15 * V_18 ;
struct V_19 * V_20 ;
if ( ! F_19 ( V_39 , & V_32 -> V_40 ) )
return 0 ;
V_37 = * ( V_32 -> V_41 ) ;
V_38 = V_32 -> V_42 ;
V_12 = V_32 -> V_12 ;
V_35 = F_20 ( V_38 , V_37 , V_12 ) ;
F_21 ( ! ( V_35 <= F_22 ( V_32 , V_32 -> V_12 ) ) ) ;
while ( V_35 ) {
V_18 = & V_16 [ V_38 ] ;
V_20 = V_18 -> V_20 ;
V_33 ++ ;
V_34 += V_20 -> V_43 ;
V_36 = F_23 ( V_18 -> V_22 ) ;
V_35 -= V_36 ;
V_38 = F_8 ( V_1 , V_16 , V_12 , V_38 ) ;
F_17 ( V_20 ) ;
}
V_32 -> V_42 = V_37 ;
V_32 -> V_44 -> V_45 += V_33 ;
V_32 -> V_44 -> V_46 += V_34 ;
return V_33 ;
}
static T_1
F_24 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_47 * V_48 = V_1 -> V_48 ;
T_1 V_49 = 0 ;
if ( F_25 ( V_50 , & V_32 -> V_40 ) )
return 0 ;
V_49 = F_18 ( V_1 , V_32 ) ;
if ( V_49 ) {
if ( F_26 ( V_48 ) &&
F_27 ( V_48 ) &&
F_28 ( V_32 , V_32 -> V_12 ) >=
V_51 ) {
if ( F_19 ( V_39 , & V_32 -> V_40 ) ) {
F_29 ( V_48 ) ;
F_30 ( V_1 , V_52 ) ;
}
}
}
if ( F_31 ( F_19 ( V_39 , & V_32 -> V_40 ) ) )
F_32 ( V_32 -> V_53 , V_49 ) ;
F_33 () ;
F_34 ( V_50 , & V_32 -> V_40 ) ;
return V_49 ;
}
static T_2
F_35 ( int V_54 , void * V_55 )
{
struct V_31 * V_32 = (struct V_31 * ) V_55 ;
struct V_1 * V_1 = V_32 -> V_1 ;
F_24 ( V_1 , V_32 ) ;
return V_56 ;
}
static inline void
F_36 ( struct V_1 * V_1 , struct V_57 * V_58 )
{
struct V_59 * V_16 = V_58 -> V_16 ;
V_16 -> V_60 = - 1 ;
V_16 -> V_61 = - 1 ;
V_16 -> V_62 = 0 ;
V_16 -> type = V_63 ;
}
static int
F_37 ( struct V_1 * V_1 , struct V_57 * V_58 )
{
struct V_59 * V_16 = V_58 -> V_16 ;
int V_64 , V_65 ;
F_36 ( V_1 , V_58 ) ;
V_64 = F_38 ( & V_1 -> V_66 . V_67 ) ;
V_65 = F_39 ( V_64 ) ;
if ( F_40 ( V_58 -> V_5 ) ) {
V_16 -> V_61 = 0 ;
V_16 -> V_62 = V_58 -> V_68 -> V_69 ;
} else {
V_16 -> V_61 = V_65 ;
V_16 -> V_62 =
( V_58 -> V_68 -> V_69 > 2048 ) ?
V_70 << V_65 : 2048 ;
}
F_21 ( ( ( V_70 << V_65 ) % V_16 -> V_62 ) ) ;
V_16 -> type = V_71 ;
return 0 ;
}
static inline void
F_41 ( struct V_1 * V_1 , struct V_72 * V_18 )
{
if ( ! V_18 -> V_73 )
return;
F_14 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_21 , V_26 ) ,
V_18 -> V_21 . V_43 , V_74 ) ;
F_42 ( V_18 -> V_73 ) ;
V_18 -> V_73 = NULL ;
F_12 ( & V_18 -> V_21 , V_26 , 0 ) ;
V_18 -> V_21 . V_43 = 0 ;
}
static inline void
F_43 ( struct V_1 * V_1 , struct V_72 * V_18 )
{
if ( ! V_18 -> V_20 )
return;
F_9 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_21 , V_26 ) ,
V_18 -> V_21 . V_43 , V_74 ) ;
F_17 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
F_12 ( & V_18 -> V_21 , V_26 , 0 ) ;
V_18 -> V_21 . V_43 = 0 ;
}
static void
F_44 ( struct V_1 * V_1 , struct V_57 * V_58 )
{
struct V_59 * V_16 = V_58 -> V_16 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_58 -> V_12 ; V_11 ++ ) {
struct V_72 * V_18 = & V_16 -> V_18 [ V_11 ] ;
if ( F_45 ( V_16 -> type ) )
F_41 ( V_1 , V_18 ) ;
else
F_43 ( V_1 , V_18 ) ;
}
F_36 ( V_1 , V_58 ) ;
}
static T_1
F_46 ( struct V_1 * V_1 , struct V_57 * V_58 , T_1 V_75 )
{
T_1 V_76 , V_77 , V_12 ;
struct V_59 * V_16 = V_58 -> V_16 ;
struct V_72 * V_18 , * V_78 ;
struct V_79 * V_80 ;
struct V_73 * V_73 ;
T_1 V_81 , V_82 ;
T_3 V_26 ;
V_77 = V_58 -> V_83 ;
V_12 = V_58 -> V_12 ;
V_82 = V_70 << V_16 -> V_61 ;
V_76 = 0 ;
while ( V_75 -- ) {
V_18 = & V_16 -> V_18 [ V_77 ] ;
if ( V_16 -> V_60 < 0 ) {
V_73 = F_47 ( V_84 | V_85 ,
V_16 -> V_61 ) ;
V_81 = 0 ;
} else {
V_78 = & V_16 -> V_18 [ V_16 -> V_60 ] ;
V_73 = V_78 -> V_73 ;
V_81 = V_78 -> V_81 + V_16 -> V_62 ;
F_48 ( V_73 ) ;
}
if ( F_49 ( ! V_73 ) ) {
F_30 ( V_1 , V_86 ) ;
V_58 -> V_68 -> V_86 ++ ;
goto V_87;
}
V_26 = F_50 ( & V_1 -> V_23 -> V_24 , V_73 , V_81 ,
V_16 -> V_62 , V_74 ) ;
V_18 -> V_73 = V_73 ;
V_18 -> V_81 = V_81 ;
F_12 ( & V_18 -> V_21 , V_26 , V_26 ) ;
V_18 -> V_21 . V_43 = V_16 -> V_62 ;
V_81 += V_16 -> V_62 ;
if ( V_81 < V_82 )
V_16 -> V_60 = V_77 ;
else
V_16 -> V_60 = - 1 ;
V_80 = & ( (struct V_79 * ) V_58 -> V_13 ) [ V_77 ] ;
F_51 ( V_26 , & V_80 -> V_88 ) ;
F_13 ( V_77 , V_12 ) ;
V_76 ++ ;
}
V_87:
if ( F_31 ( V_76 ) ) {
V_58 -> V_83 = V_77 ;
F_52 () ;
if ( F_31 ( F_19 ( V_89 , & V_58 -> V_40 ) ) )
F_53 ( V_58 ) ;
}
return V_76 ;
}
static T_1
F_54 ( struct V_1 * V_1 , struct V_57 * V_58 , T_1 V_75 )
{
T_1 V_76 , V_77 , V_12 , V_90 ;
struct V_59 * V_16 = V_58 -> V_16 ;
struct V_72 * V_18 ;
struct V_79 * V_80 ;
struct V_19 * V_20 ;
T_3 V_26 ;
V_90 = V_58 -> V_68 -> V_69 ;
V_77 = V_58 -> V_83 ;
V_12 = V_58 -> V_12 ;
V_76 = 0 ;
while ( V_75 -- ) {
V_18 = & V_16 -> V_18 [ V_77 ] ;
V_20 = F_55 ( V_1 -> V_48 , V_90 ) ;
if ( F_49 ( ! V_20 ) ) {
F_30 ( V_1 , V_86 ) ;
V_58 -> V_68 -> V_86 ++ ;
goto V_87;
}
V_26 = F_56 ( & V_1 -> V_23 -> V_24 , V_20 -> V_55 ,
V_90 , V_74 ) ;
V_18 -> V_20 = V_20 ;
F_12 ( & V_18 -> V_21 , V_26 , V_26 ) ;
V_18 -> V_21 . V_43 = V_90 ;
V_80 = & ( (struct V_79 * ) V_58 -> V_13 ) [ V_77 ] ;
F_51 ( V_26 , & V_80 -> V_88 ) ;
F_13 ( V_77 , V_12 ) ;
V_76 ++ ;
}
V_87:
if ( F_31 ( V_76 ) ) {
V_58 -> V_83 = V_77 ;
F_52 () ;
if ( F_31 ( F_19 ( V_89 , & V_58 -> V_40 ) ) )
F_53 ( V_58 ) ;
}
return V_76 ;
}
static inline void
F_57 ( struct V_1 * V_1 , struct V_57 * V_58 )
{
struct V_59 * V_16 = V_58 -> V_16 ;
T_1 V_91 ;
V_91 = F_28 ( V_58 , V_58 -> V_12 ) ;
if ( ! ( V_91 >> V_92 ) )
return;
if ( F_45 ( V_16 -> type ) )
F_46 ( V_1 , V_58 , V_91 ) ;
else
F_54 ( V_1 , V_58 , V_91 ) ;
}
static inline struct V_19 *
F_58 ( struct V_93 * V_94 ,
struct V_59 * V_16 ,
struct V_72 * V_18 ,
T_1 V_95 , T_1 V_40 )
{
struct V_1 * V_1 = V_94 -> V_1 ;
struct V_19 * V_20 ;
if ( F_45 ( V_16 -> type ) ) {
V_20 = F_59 ( & V_94 -> V_96 ) ;
if ( F_49 ( ! V_20 ) )
return NULL ;
F_14 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_21 , V_26 ) ,
V_18 -> V_21 . V_43 , V_74 ) ;
F_60 ( V_20 , F_15 ( V_20 ) -> V_97 ,
V_18 -> V_73 , V_18 -> V_81 , V_95 ) ;
V_20 -> V_43 += V_95 ;
V_20 -> V_98 += V_95 ;
V_20 -> V_99 += V_95 ;
V_18 -> V_73 = NULL ;
V_18 -> V_21 . V_43 = 0 ;
return V_20 ;
}
V_20 = V_18 -> V_20 ;
F_21 ( ! V_20 ) ;
F_9 ( & V_1 -> V_23 -> V_24 ,
F_10 ( & V_18 -> V_21 , V_26 ) ,
V_18 -> V_21 . V_43 , V_74 ) ;
F_61 ( V_20 , V_95 ) ;
V_20 -> V_100 = F_62 ( V_20 , V_1 -> V_48 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_21 . V_43 = 0 ;
return V_20 ;
}
static T_1
F_63 ( struct V_1 * V_1 , struct V_7 * V_8 , int V_101 )
{
struct V_9 * V_102 , * V_10 ;
struct V_57 * V_58 = NULL ;
struct V_59 * V_16 ;
struct V_72 * V_18 ;
struct V_19 * V_20 ;
struct V_103 * V_104 = & V_8 -> V_105 ;
struct V_93 * V_94 = V_8 -> V_106 ;
T_1 V_107 = 0 , V_95 = 0 , V_40 , V_108 ;
F_64 ( V_1 -> V_48 ) ;
V_102 = V_8 -> V_13 ;
V_10 = & V_102 [ V_8 -> V_83 ] ;
while ( V_10 -> V_14 && ( V_107 < V_101 ) ) {
V_107 ++ ;
V_40 = F_65 ( V_10 -> V_40 ) ;
V_95 = F_66 ( V_10 -> V_95 ) ;
F_67 ( V_104 , F_66 ( V_10 -> V_95 ) ) ;
if ( F_40 ( V_10 -> V_109 ) )
V_58 = V_8 -> V_58 [ 1 ] ;
else
V_58 = V_8 -> V_58 [ 0 ] ;
V_16 = V_58 -> V_16 ;
V_18 = & V_16 -> V_18 [ V_58 -> V_42 ] ;
if ( F_49 ( V_40 & ( V_110 |
V_111 |
V_112 ) ) ) {
if ( F_45 ( V_16 -> type ) )
F_41 ( V_1 , V_18 ) ;
else
F_43 ( V_1 , V_18 ) ;
V_58 -> V_68 -> V_113 ++ ;
goto V_114;
}
V_20 = F_58 ( V_8 -> V_106 , V_16 , V_18 ,
V_95 , V_40 ) ;
if ( F_49 ( ! V_20 ) )
break;
V_108 = V_40 & V_115 ;
if ( F_31
( ( V_1 -> V_48 -> V_116 & V_117 ) &&
( ( V_108 == V_118 ) ||
( V_108 == V_119 ) ||
( V_108 == V_120 ) ||
( V_108 == V_121 ) ) ) )
V_20 -> V_122 = V_123 ;
else
F_68 ( V_20 ) ;
V_58 -> V_68 -> V_124 ++ ;
V_58 -> V_68 -> V_125 += V_95 ;
if ( V_40 & V_126 )
F_69 ( V_20 , F_66 ( V_10 -> V_127 ) ) ;
if ( F_45 ( V_16 -> type ) )
F_70 ( & V_94 -> V_96 ) ;
else
F_71 ( V_20 ) ;
V_114:
V_10 -> V_14 = 0 ;
F_13 ( V_58 -> V_42 , V_58 -> V_12 ) ;
F_13 ( V_8 -> V_83 , V_8 -> V_12 ) ;
V_10 = & V_102 [ V_8 -> V_83 ] ;
}
F_72 ( & V_94 -> V_96 , false ) ;
if ( F_31 ( F_19 ( V_128 , & V_8 -> V_58 [ 0 ] -> V_40 ) ) )
F_73 ( V_8 -> V_53 , V_107 ) ;
F_57 ( V_1 , V_8 -> V_58 [ 0 ] ) ;
if ( V_8 -> V_58 [ 1 ] )
F_57 ( V_1 , V_8 -> V_58 [ 1 ] ) ;
return V_107 ;
}
static void
F_74 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_93 * V_94 = (struct V_93 * ) ( V_8 -> V_106 ) ;
struct V_129 * V_96 = & V_94 -> V_96 ;
if ( F_31 ( F_75 ( V_96 ) ) ) {
F_76 ( V_96 ) ;
V_94 -> V_130 ++ ;
}
}
static T_2
F_77 ( int V_54 , void * V_55 )
{
struct V_7 * V_8 = (struct V_7 * ) V_55 ;
if ( V_8 ) {
( (struct V_93 * ) ( V_8 -> V_106 ) ) -> V_131 ++ ;
F_74 ( V_8 -> V_1 , V_8 ) ;
}
return V_56 ;
}
static T_2
F_78 ( int V_54 , void * V_55 )
{
T_1 V_132 ;
unsigned long V_40 ;
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( F_49 ( F_19 ( V_134 , & V_1 -> V_135 ) ) ) {
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_56 ;
}
F_81 ( & V_1 -> V_66 , V_132 ) ;
if ( F_82 ( & V_1 -> V_66 , V_132 ) )
F_83 ( & V_1 -> V_66 , V_132 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_56 ;
}
static T_2
F_84 ( int V_54 , void * V_55 )
{
int V_11 , V_136 ;
T_1 V_132 ;
unsigned long V_40 ;
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
struct V_137 * V_138 ;
struct V_93 * V_94 ;
struct V_31 * V_32 = NULL ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( F_49 ( F_19 ( V_134 , & V_1 -> V_135 ) ) ) {
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_139 ;
}
F_81 ( & V_1 -> V_66 , V_132 ) ;
if ( F_49 ( ! V_132 ) ) {
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_139 ;
}
if ( F_82 ( & V_1 -> V_66 , V_132 ) )
F_83 ( & V_1 -> V_66 , V_132 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( ! F_85 ( V_132 ) )
return V_56 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_140 ; V_11 ++ ) {
for ( V_136 = 0 ; V_136 < V_1 -> V_141 ; V_136 ++ ) {
V_32 = V_1 -> V_142 [ V_11 ] . V_32 [ V_136 ] ;
if ( V_32 && F_19 ( V_39 , & V_32 -> V_40 ) )
F_24 ( V_1 , V_1 -> V_142 [ V_11 ] . V_32 [ V_136 ] ) ;
}
}
for ( V_11 = 0 ; V_11 < V_1 -> V_143 ; V_11 ++ ) {
V_138 = & V_1 -> V_138 [ V_11 ] ;
if ( ! V_138 -> V_144 )
continue;
for ( V_136 = 0 ; V_136 < V_1 -> V_145 ; V_136 ++ ) {
V_94 = & V_138 -> V_94 [ V_136 ] ;
if ( V_94 -> V_8 )
F_74 ( V_1 ,
V_94 -> V_8 ) ;
}
}
return V_56 ;
}
static void
F_86 ( struct V_1 * V_1 )
{
F_34 ( V_134 , & V_1 -> V_135 ) ;
F_30 ( V_1 , V_146 ) ;
}
static void
F_87 ( struct V_1 * V_1 )
{
F_88 ( V_134 , & V_1 -> V_135 ) ;
F_30 ( V_1 , V_147 ) ;
}
static void
F_89 ( struct V_1 * V_1 )
{
struct V_47 * V_48 = V_1 -> V_48 ;
memcpy ( V_48 -> V_148 , & V_1 -> V_148 , V_48 -> V_149 ) ;
if ( F_90 ( V_48 -> V_150 ) )
memcpy ( V_48 -> V_150 , & V_1 -> V_148 , V_48 -> V_149 ) ;
}
void
F_91 ( struct V_1 * V_1 )
{
F_86 ( V_1 ) ;
}
void
F_92 ( struct V_1 * V_1 )
{
F_87 ( V_1 ) ;
}
void
F_93 ( struct V_1 * V_1 )
{
V_1 -> V_151 . V_152 = V_153 ;
F_94 ( & V_1 -> V_151 . V_154 ) ;
}
void
F_95 ( struct V_1 * V_1 )
{
V_1 -> V_151 . V_152 = V_155 ;
F_94 ( & V_1 -> V_151 . V_154 ) ;
}
void
F_96 ( struct V_1 * V_1 )
{
V_1 -> V_151 . V_152 = V_153 ;
F_94 ( & V_1 -> V_151 . V_154 ) ;
}
static void
F_97 ( void * V_156 )
{
struct V_1 * V_1 = (struct V_1 * ) V_156 ;
F_98 ( V_1 -> V_48 ) ;
F_94 ( & V_1 -> V_151 . V_157 ) ;
}
void
F_99 ( struct V_1 * V_1 ,
enum V_158 V_159 )
{
bool V_160 = false ;
V_160 = ( V_159 == V_161 ) || ( V_159 == V_162 ) ;
if ( V_159 == V_162 ) {
if ( ! F_19 ( V_163 , & V_1 -> V_135 ) )
F_30 ( V_1 , V_164 ) ;
F_88 ( V_163 , & V_1 -> V_135 ) ;
} else {
if ( F_19 ( V_163 , & V_1 -> V_135 ) )
F_30 ( V_1 , V_164 ) ;
F_34 ( V_163 , & V_1 -> V_135 ) ;
}
if ( V_160 ) {
if ( ! F_27 ( V_1 -> V_48 ) ) {
T_4 V_165 , V_166 ;
F_100 ( V_167 L_1 ,
V_1 -> V_48 -> V_168 ) ;
F_101 ( V_1 -> V_48 ) ;
F_30 ( V_1 , V_169 ) ;
for ( V_165 = 0 ; V_165 < V_1 -> V_140 ; V_165 ++ ) {
for ( V_166 = 0 ; V_166 < V_1 -> V_141 ;
V_166 ++ ) {
struct V_31 * V_32 =
V_1 -> V_142 [ V_165 ] . V_32 [ V_166 ] ;
T_1 V_170 ;
if ( ! V_32 )
continue;
V_170 = V_32 -> V_5 ;
if ( F_19 ( V_39 ,
& V_32 -> V_40 ) ) {
F_100 ( V_171 L_2
L_3 ,
V_1 -> V_48 -> V_168 ,
V_170 ) ;
F_102 (
V_1 -> V_48 ,
V_170 ) ;
F_30 ( V_1 ,
V_52 ) ;
} else {
F_103 (
V_1 -> V_48 ,
V_170 ) ;
F_30 ( V_1 ,
V_172 ) ;
}
}
}
}
} else {
if ( F_27 ( V_1 -> V_48 ) ) {
F_100 ( V_167 L_4 ,
V_1 -> V_48 -> V_168 ) ;
F_98 ( V_1 -> V_48 ) ;
F_30 ( V_1 , V_169 ) ;
}
}
}
static void
F_104 ( void * V_156 , struct V_173 * V_174 )
{
struct V_1 * V_1 = (struct V_1 * ) V_156 ;
F_94 ( & V_1 -> V_151 . V_175 ) ;
}
static void
F_105 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_176 * V_142 =
(struct V_176 * ) V_32 -> V_44 -> V_174 -> V_177 ;
V_32 -> V_177 = V_32 ;
V_142 -> V_32 [ V_32 -> V_5 ] = V_32 ;
}
static void
F_106 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_176 * V_142 =
(struct V_176 * ) V_32 -> V_44 -> V_174 -> V_177 ;
V_142 -> V_32 [ V_32 -> V_5 ] = NULL ;
V_32 -> V_177 = NULL ;
}
static void
F_107 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_137 * V_138 =
(struct V_137 * ) V_8 -> V_102 -> V_144 -> V_177 ;
V_138 -> V_94 [ V_8 -> V_5 ] . V_8 = V_8 ;
V_8 -> V_106 = & V_138 -> V_94 [ V_8 -> V_5 ] ;
}
static void
F_108 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_137 * V_138 =
(struct V_137 * ) V_8 -> V_102 -> V_144 -> V_177 ;
V_138 -> V_94 [ V_8 -> V_5 ] . V_8 = NULL ;
}
static void
F_109 ( struct V_1 * V_1 , struct V_173 * V_174 )
{
struct V_176 * V_142 =
(struct V_176 * ) V_174 -> V_177 ;
struct V_31 * V_32 ;
T_1 V_170 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
V_32 = V_142 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_170 = V_32 -> V_5 ;
F_34 ( V_39 , & V_32 -> V_40 ) ;
F_103 ( V_1 -> V_48 , V_170 ) ;
F_100 ( V_171 L_5 ,
V_1 -> V_48 -> V_168 , V_170 ) ;
}
}
static void
F_110 ( struct V_1 * V_1 , struct V_173 * V_174 )
{
struct V_176 * V_142 = (struct V_176 * ) V_174 -> V_177 ;
struct V_31 * V_32 ;
T_1 V_170 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
V_32 = V_142 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_170 = V_32 -> V_5 ;
F_21 ( F_19 ( V_39 , & V_32 -> V_40 ) ) ;
F_88 ( V_39 , & V_32 -> V_40 ) ;
F_21 ( * ( V_32 -> V_41 ) != 0 ) ;
if ( F_27 ( V_1 -> V_48 ) ) {
F_100 ( V_171 L_6 ,
V_1 -> V_48 -> V_168 , V_170 ) ;
F_102 ( V_1 -> V_48 , V_170 ) ;
F_30 ( V_1 , V_52 ) ;
}
}
if ( F_90 ( & V_1 -> V_148 . V_179 [ 0 ] ) ) {
F_111 ( & V_1 -> V_66 . V_67 , & V_1 -> V_148 ) ;
F_89 ( V_1 ) ;
}
}
static void
F_112 ( struct V_180 * V_181 )
{
struct V_176 * V_142 =
F_113 ( V_181 , struct V_176 , V_182 ) ;
struct V_1 * V_1 = NULL ;
struct V_31 * V_32 ;
unsigned long V_40 ;
T_1 V_11 , V_183 = 0 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
V_32 = V_142 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_1 = V_32 -> V_1 ;
if ( F_25 ( V_50 , & V_32 -> V_40 ) ) {
V_183 ++ ;
continue;
}
F_16 ( V_1 , V_32 ) ;
F_33 () ;
F_34 ( V_50 , & V_32 -> V_40 ) ;
}
if ( V_183 ) {
F_114 ( V_1 -> V_184 , & V_142 -> V_182 ,
F_115 ( 1 ) ) ;
return;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_116 ( V_142 -> V_174 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_117 ( struct V_1 * V_1 , struct V_173 * V_174 )
{
struct V_176 * V_142 = (struct V_176 * ) V_174 -> V_177 ;
struct V_31 * V_32 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
V_32 = V_142 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
}
F_114 ( V_1 -> V_184 , & V_142 -> V_182 , 0 ) ;
}
static void
F_118 ( struct V_1 * V_1 , struct V_185 * V_144 )
{
struct V_137 * V_138 = (struct V_137 * ) V_144 -> V_177 ;
struct V_7 * V_8 ;
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_186 ; V_11 ++ ) {
V_94 = & V_138 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_34 ( V_89 , & V_8 -> V_58 [ 0 ] -> V_40 ) ;
if ( V_8 -> V_58 [ 1 ] )
F_34 ( V_89 , & V_8 -> V_58 [ 1 ] -> V_40 ) ;
}
}
static void
F_119 ( void * V_181 )
{
struct V_137 * V_138 =
F_113 ( V_181 , struct V_137 , V_187 ) ;
struct V_93 * V_94 ;
struct V_1 * V_1 = NULL ;
unsigned long V_40 ;
T_1 V_11 ;
for ( V_11 = 0 ; V_11 < V_186 ; V_11 ++ ) {
V_94 = & V_138 -> V_94 [ V_11 ] ;
if ( ! V_94 -> V_8 )
continue;
V_1 = V_94 -> V_8 -> V_1 ;
F_120 ( & V_94 -> V_96 ) ;
F_7 ( V_1 , V_94 -> V_8 ) ;
F_44 ( V_1 , V_94 -> V_8 -> V_58 [ 0 ] ) ;
if ( V_94 -> V_8 -> V_58 [ 1 ] )
F_44 ( V_1 , V_94 -> V_8 -> V_58 [ 1 ] ) ;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_121 ( V_138 -> V_144 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_122 ( struct V_1 * V_1 , struct V_185 * V_144 )
{
struct V_137 * V_138 = (struct V_137 * ) V_144 -> V_177 ;
struct V_7 * V_8 ;
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_186 ; V_11 ++ ) {
V_94 = & V_138 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_34 ( V_128 , & V_8 -> V_58 [ 0 ] -> V_40 ) ;
if ( V_8 -> V_58 [ 1 ] )
F_34 ( V_128 , & V_8 -> V_58 [ 1 ] -> V_40 ) ;
}
F_123 ( V_1 -> V_184 , & V_138 -> V_187 ) ;
}
static void
F_124 ( struct V_1 * V_1 , struct V_185 * V_144 )
{
struct V_137 * V_138 = (struct V_137 * ) V_144 -> V_177 ;
struct V_7 * V_8 ;
struct V_57 * V_58 ;
struct V_93 * V_94 ;
int V_11 , V_136 ;
for ( V_11 = 0 ; V_11 < V_186 ; V_11 ++ ) {
V_94 = & V_138 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_125 ( & V_94 -> V_96 ) ;
for ( V_136 = 0 ; V_136 < V_188 ; V_136 ++ ) {
V_58 = V_8 -> V_58 [ V_136 ] ;
if ( ! V_58 )
continue;
F_37 ( V_1 , V_58 ) ;
F_88 ( V_128 , & V_58 -> V_40 ) ;
F_88 ( V_89 , & V_58 -> V_40 ) ;
F_57 ( V_1 , V_58 ) ;
}
}
}
static void
F_126 ( void * V_156 , struct V_185 * V_144 )
{
struct V_1 * V_1 = (struct V_1 * ) V_156 ;
F_94 ( & V_1 -> V_151 . V_189 ) ;
}
static void
F_127 ( struct V_1 * V_1 , struct V_185 * V_144 )
{
V_1 -> V_151 . V_190 = V_153 ;
F_94 ( & V_1 -> V_151 . V_191 ) ;
}
void
F_128 ( struct V_1 * V_1 , enum V_192 V_193 ,
struct V_194 * V_195 )
{
if ( V_193 == V_153 )
F_30 ( V_1 , V_196 ) ;
if ( ! F_129 ( V_1 -> V_48 ) ||
! F_19 ( V_197 , & V_1 -> V_135 ) )
return;
F_130 ( & V_1 -> V_198 ,
V_199 + F_115 ( V_200 ) ) ;
}
static void
F_131 ( struct V_1 * V_1 )
{
V_1 -> V_151 . V_201 = V_153 ;
F_94 ( & V_1 -> V_151 . V_202 ) ;
}
void
F_132 ( void * V_156 , enum V_203 V_193 )
{
struct V_204 * V_205 =
(struct V_204 * ) V_156 ;
V_205 -> V_206 = ( T_1 ) V_193 ;
F_94 ( & V_205 -> V_207 ) ;
}
static void
F_133 ( struct V_1 * V_1 ,
struct V_208 * V_209 )
{
int V_11 ;
T_3 V_210 ;
if ( V_209 -> V_211 == NULL )
return;
for ( V_11 = 0 ; V_11 < V_209 -> V_212 ; V_11 ++ ) {
if ( V_209 -> V_211 [ V_11 ] . V_213 != NULL ) {
if ( V_209 -> V_214 == V_215 ) {
F_134 ( & ( V_209 -> V_211 [ V_11 ] . V_216 ) ,
V_210 ) ;
F_135 ( & V_1 -> V_23 -> V_24 ,
V_209 -> V_211 [ V_11 ] . V_43 ,
V_209 -> V_211 [ V_11 ] . V_213 , V_210 ) ;
} else
F_136 ( V_209 -> V_211 [ V_11 ] . V_213 ) ;
}
}
F_136 ( V_209 -> V_211 ) ;
V_209 -> V_211 = NULL ;
}
static int
F_137 ( struct V_1 * V_1 ,
struct V_208 * V_209 )
{
int V_11 ;
T_3 V_210 ;
if ( ( V_209 -> V_212 == 0 ) || ( V_209 -> V_43 == 0 ) ) {
V_209 -> V_211 = NULL ;
return 0 ;
}
V_209 -> V_211 = F_138 ( V_209 -> V_212 , sizeof( struct V_217 ) ,
V_218 ) ;
if ( V_209 -> V_211 == NULL )
return - V_219 ;
if ( V_209 -> V_214 == V_215 ) {
for ( V_11 = 0 ; V_11 < V_209 -> V_212 ; V_11 ++ ) {
V_209 -> V_211 [ V_11 ] . V_43 = V_209 -> V_43 ;
V_209 -> V_211 [ V_11 ] . V_213 =
F_139 ( & V_1 -> V_23 -> V_24 ,
V_209 -> V_43 , & V_210 ,
V_218 ) ;
if ( V_209 -> V_211 [ V_11 ] . V_213 == NULL )
goto V_220;
F_51 ( V_210 ,
& ( V_209 -> V_211 [ V_11 ] . V_216 ) ) ;
}
} else {
for ( V_11 = 0 ; V_11 < V_209 -> V_212 ; V_11 ++ ) {
V_209 -> V_211 [ V_11 ] . V_43 = V_209 -> V_43 ;
V_209 -> V_211 [ V_11 ] . V_213 = F_140 ( V_209 -> V_43 ,
V_218 ) ;
if ( V_209 -> V_211 [ V_11 ] . V_213 == NULL )
goto V_220;
}
}
return 0 ;
V_220:
F_133 ( V_1 , V_209 ) ;
return - V_219 ;
}
static void
F_141 ( struct V_1 * V_1 )
{
int V_54 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_87 ( V_1 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_54 = F_142 ( V_1 ) ;
F_143 ( V_54 , V_1 ) ;
}
static int
F_144 ( struct V_1 * V_1 )
{
int V_221 = 0 ;
unsigned long V_222 , V_40 ;
T_1 V_54 ;
T_5 V_223 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( V_1 -> V_224 & V_225 ) {
V_223 = ( T_5 ) F_78 ;
V_54 = V_1 -> V_226 [ V_227 ] . V_21 ;
V_222 = 0 ;
} else {
V_223 = ( T_5 ) F_84 ;
V_54 = V_1 -> V_23 -> V_54 ;
V_222 = V_228 ;
}
F_80 ( & V_1 -> V_133 , V_40 ) ;
sprintf ( V_1 -> V_229 , L_7 , V_230 ) ;
F_88 ( V_134 , & V_1 -> V_135 ) ;
F_30 ( V_1 , V_147 ) ;
V_221 = F_145 ( V_54 , V_223 , V_222 ,
V_1 -> V_229 , V_1 ) ;
return V_221 ;
}
static void
F_146 ( struct V_1 * V_1 , struct V_231 * V_232 )
{
F_136 ( V_232 -> V_233 ) ;
V_232 -> V_233 = NULL ;
}
static int
F_147 ( struct V_1 * V_1 , enum V_234 V_235 ,
T_1 V_236 , struct V_231 * V_232 )
{
int V_11 , V_237 = 0 ;
T_1 V_224 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_224 = V_1 -> V_224 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_224 & V_225 ) {
V_232 -> V_238 = V_239 ;
V_232 -> V_233 = F_138 ( V_232 -> V_212 ,
sizeof( struct V_240 ) ,
V_218 ) ;
if ( ! V_232 -> V_233 )
return - V_219 ;
switch ( V_235 ) {
case V_241 :
V_237 = V_242 + V_236 ;
break;
case V_243 :
V_237 = V_242 +
( V_1 -> V_140 * V_1 -> V_141 ) +
V_236 ;
break;
default:
F_148 () ;
}
for ( V_11 = 0 ; V_11 < V_232 -> V_212 ; V_11 ++ )
V_232 -> V_233 [ V_11 ] . V_21 = V_237 + V_11 ;
} else {
V_232 -> V_238 = V_244 ;
V_232 -> V_212 = 1 ;
V_232 -> V_233 = F_138 ( V_232 -> V_212 ,
sizeof( struct V_240 ) ,
V_218 ) ;
if ( ! V_232 -> V_233 )
return - V_219 ;
switch ( V_235 ) {
case V_241 :
V_232 -> V_233 [ 0 ] . V_21 = V_245 ;
break;
case V_243 :
V_232 -> V_233 [ 0 ] . V_21 = V_246 ;
break;
}
}
return 0 ;
}
static void
F_149 ( struct V_1 * V_1 , struct V_176 * V_142 ,
int V_247 )
{
int V_11 ;
int V_248 ;
for ( V_11 = 0 ; V_11 < V_247 ; V_11 ++ ) {
if ( V_142 -> V_32 [ V_11 ] == NULL )
continue;
V_248 = V_142 -> V_32 [ V_11 ] -> V_249 ;
F_143 ( V_1 -> V_226 [ V_248 ] . V_21 , V_142 -> V_32 [ V_11 ] ) ;
}
}
static int
F_150 ( struct V_1 * V_1 , struct V_176 * V_142 ,
T_1 V_165 , int V_247 )
{
int V_11 ;
int V_221 ;
int V_248 ;
for ( V_11 = 0 ; V_11 < V_247 ; V_11 ++ ) {
V_248 = V_142 -> V_32 [ V_11 ] -> V_249 ;
sprintf ( V_142 -> V_32 [ V_11 ] -> V_168 , L_8 , V_1 -> V_48 -> V_168 ,
V_165 + V_142 -> V_32 [ V_11 ] -> V_5 ) ;
V_221 = F_145 ( V_1 -> V_226 [ V_248 ] . V_21 ,
( T_5 ) F_35 , 0 ,
V_142 -> V_32 [ V_11 ] -> V_168 ,
V_142 -> V_32 [ V_11 ] ) ;
if ( V_221 )
goto V_220;
}
return 0 ;
V_220:
if ( V_11 > 0 )
F_149 ( V_1 , V_142 , ( V_11 - 1 ) ) ;
return - 1 ;
}
static void
F_151 ( struct V_1 * V_1 , struct V_137 * V_138 ,
int V_250 )
{
int V_11 ;
int V_248 ;
for ( V_11 = 0 ; V_11 < V_250 ; V_11 ++ ) {
if ( V_138 -> V_94 [ V_11 ] . V_8 == NULL )
continue;
V_248 = V_138 -> V_94 [ V_11 ] . V_8 -> V_249 ;
F_143 ( V_1 -> V_226 [ V_248 ] . V_21 ,
V_138 -> V_94 [ V_11 ] . V_8 ) ;
}
}
static int
F_152 ( struct V_1 * V_1 , struct V_137 * V_138 ,
T_1 V_251 , int V_250 )
{
int V_11 ;
int V_221 ;
int V_248 ;
for ( V_11 = 0 ; V_11 < V_250 ; V_11 ++ ) {
V_248 = V_138 -> V_94 [ V_11 ] . V_8 -> V_249 ;
sprintf ( V_138 -> V_94 [ V_11 ] . V_8 -> V_168 , L_9 ,
V_1 -> V_48 -> V_168 ,
V_251 + V_138 -> V_94 [ V_11 ] . V_8 -> V_5 ) ;
V_221 = F_145 ( V_1 -> V_226 [ V_248 ] . V_21 ,
( T_5 ) F_77 , 0 ,
V_138 -> V_94 [ V_11 ] . V_8 -> V_168 ,
V_138 -> V_94 [ V_11 ] . V_8 ) ;
if ( V_221 )
goto V_220;
}
return 0 ;
V_220:
if ( V_11 > 0 )
F_151 ( V_1 , V_138 , ( V_11 - 1 ) ) ;
return - 1 ;
}
static void
F_153 ( struct V_1 * V_1 , struct V_252 * V_253 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_254 ; V_11 ++ ) {
if ( V_253 [ V_11 ] . V_255 == V_256 )
F_133 ( V_1 , & V_253 [ V_11 ] . V_257 . V_209 ) ;
else if ( V_253 [ V_11 ] . V_255 == V_258 )
F_146 ( V_1 , & V_253 [ V_11 ] . V_257 . V_232 ) ;
}
}
static int
F_154 ( struct V_1 * V_1 , struct V_252 * V_253 ,
T_1 V_165 )
{
int V_11 , V_221 = 0 ;
for ( V_11 = 0 ; V_11 < V_254 ; V_11 ++ ) {
if ( V_253 [ V_11 ] . V_255 == V_256 )
V_221 = F_137 ( V_1 ,
& V_253 [ V_11 ] . V_257 . V_209 ) ;
else if ( V_253 [ V_11 ] . V_255 == V_258 )
V_221 = F_147 ( V_1 , V_241 , V_165 ,
& V_253 [ V_11 ] . V_257 . V_232 ) ;
if ( V_221 )
goto V_220;
}
return 0 ;
V_220:
F_153 ( V_1 , V_253 ) ;
return V_221 ;
}
static void
F_155 ( struct V_1 * V_1 , struct V_252 * V_253 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_259 ; V_11 ++ ) {
if ( V_253 [ V_11 ] . V_255 == V_256 )
F_133 ( V_1 , & V_253 [ V_11 ] . V_257 . V_209 ) ;
else if ( V_253 [ V_11 ] . V_255 == V_258 )
F_146 ( V_1 , & V_253 [ V_11 ] . V_257 . V_232 ) ;
}
}
static int
F_156 ( struct V_1 * V_1 , struct V_252 * V_253 ,
T_4 V_251 )
{
int V_11 , V_221 = 0 ;
for ( V_11 = 0 ; V_11 < V_259 ; V_11 ++ ) {
if ( V_253 [ V_11 ] . V_255 == V_256 )
V_221 = F_137 ( V_1 ,
& V_253 [ V_11 ] . V_257 . V_209 ) ;
else if ( V_253 [ V_11 ] . V_255 == V_258 )
V_221 = F_147 ( V_1 , V_243 , V_251 ,
& V_253 [ V_11 ] . V_257 . V_232 ) ;
if ( V_221 )
goto V_220;
}
return 0 ;
V_220:
F_155 ( V_1 , V_253 ) ;
return V_221 ;
}
static void
F_157 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_158 ( ( void * ) & V_1 -> V_66 . V_260 . V_261 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_159 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_160 ( ( void * ) & V_1 -> V_66 . V_260 . V_261 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_161 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_162 ( ( void * ) & V_1 -> V_66 . V_260 . V_261 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_163 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_164 ( ( void * ) & V_1 -> V_66 . V_260 . V_261 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_165 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
struct V_137 * V_138 ;
struct V_93 * V_94 ;
int V_11 , V_136 ;
unsigned long V_40 ;
if ( ! F_27 ( V_1 -> V_48 ) )
return;
F_79 ( & V_1 -> V_133 , V_40 ) ;
for ( V_11 = 0 ; V_11 < V_1 -> V_143 ; V_11 ++ ) {
V_138 = & V_1 -> V_138 [ V_11 ] ;
if ( ! V_138 -> V_144 )
continue;
for ( V_136 = 0 ; V_136 < V_1 -> V_145 ; V_136 ++ ) {
V_94 = & V_138 -> V_94 [ V_136 ] ;
if ( ! V_94 -> V_8 )
continue;
F_166 ( V_94 -> V_8 ) ;
}
}
if ( F_19 ( V_262 , & V_1 -> V_135 ) )
F_130 ( & V_1 -> V_263 ,
V_199 + F_115 ( V_264 ) ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_167 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
if ( ! F_129 ( V_1 -> V_48 ) ||
! F_19 ( V_197 , & V_1 -> V_135 ) )
return;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_168 ( & V_1 -> V_66 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
void
F_169 ( struct V_1 * V_1 )
{
if ( V_1 -> V_224 & V_265 &&
! F_19 ( V_262 , & V_1 -> V_135 ) ) {
F_170 ( & V_1 -> V_263 , F_165 ,
( unsigned long ) V_1 ) ;
F_88 ( V_262 , & V_1 -> V_135 ) ;
F_130 ( & V_1 -> V_263 ,
V_199 + F_115 ( V_264 ) ) ;
}
}
static void
F_171 ( struct V_1 * V_1 )
{
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( ! F_25 ( V_197 , & V_1 -> V_135 ) ) {
F_170 ( & V_1 -> V_198 , F_167 ,
( unsigned long ) V_1 ) ;
F_130 ( & V_1 -> V_198 ,
V_199 + F_115 ( V_200 ) ) ;
}
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_172 ( struct V_1 * V_1 )
{
int V_266 = 0 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( F_173 ( V_197 , & V_1 -> V_135 ) )
V_266 = 1 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_266 )
F_174 ( & V_1 -> V_198 ) ;
}
static void
F_175 ( struct V_47 * V_48 , T_6 * V_267 )
{
int V_11 = 1 ;
struct V_268 * V_269 ;
F_176 (mc_addr, netdev) {
memcpy ( & V_267 [ V_11 * V_270 ] , & V_269 -> V_271 [ 0 ] ,
V_270 ) ;
V_11 ++ ;
}
}
static int
F_177 ( struct V_129 * V_96 , int V_101 )
{
struct V_93 * V_94 =
F_113 ( V_96 , struct V_93 , V_96 ) ;
struct V_1 * V_1 = V_94 -> V_1 ;
int V_272 = 0 ;
V_94 -> V_273 ++ ;
if ( ! F_27 ( V_1 -> V_48 ) )
goto V_274;
V_272 = F_63 ( V_1 , V_94 -> V_8 , V_101 ) ;
if ( V_272 >= V_101 )
return V_272 ;
V_274:
F_178 ( V_96 ) ;
V_94 -> V_275 ++ ;
if ( V_94 -> V_8 )
F_179 ( V_94 -> V_8 ) ;
return V_272 ;
}
static void
F_180 ( struct V_1 * V_1 , T_1 V_251 )
{
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_145 ; V_11 ++ ) {
V_94 = & V_1 -> V_138 [ V_251 ] . V_94 [ V_11 ] ;
F_181 ( V_1 -> V_48 , & V_94 -> V_96 ,
F_177 , V_276 ) ;
}
}
static void
F_182 ( struct V_1 * V_1 , T_1 V_251 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_145 ; V_11 ++ )
F_183 ( & V_1 -> V_138 [ V_251 ] . V_94 [ V_11 ] . V_96 ) ;
}
void
F_184 ( struct V_1 * V_1 , T_1 V_165 )
{
struct V_176 * V_142 = & V_1 -> V_142 [ V_165 ] ;
struct V_252 * V_253 = & V_1 -> V_277 [ V_165 ] . V_253 [ 0 ] ;
unsigned long V_40 ;
if ( ! V_142 -> V_174 )
return;
F_185 ( & V_1 -> V_151 . V_175 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_186 ( V_142 -> V_174 , V_278 , F_104 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_187 ( & V_1 -> V_151 . V_175 ) ;
if ( V_142 -> V_32 [ 0 ] -> V_238 == V_239 )
F_149 ( V_1 , V_142 ,
V_1 -> V_141 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_188 ( V_142 -> V_174 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_142 -> V_174 = NULL ;
V_142 -> V_165 = 0 ;
F_153 ( V_1 , V_253 ) ;
}
int
F_189 ( struct V_1 * V_1 , T_1 V_165 )
{
int V_221 ;
struct V_176 * V_142 = & V_1 -> V_142 [ V_165 ] ;
struct V_252 * V_253 = & V_1 -> V_277 [ V_165 ] . V_253 [ 0 ] ;
struct V_231 * V_232 =
& V_253 [ V_279 ] . V_257 . V_232 ;
struct V_280 * V_281 = & V_1 -> V_281 [ V_165 ] ;
static const struct V_282 V_283 = {
. V_284 = F_105 ,
. V_285 = F_106 ,
. V_286 = F_109 ,
. V_287 = F_110 ,
. V_288 = F_117 ,
} ;
struct V_173 * V_174 ;
unsigned long V_40 ;
V_142 -> V_165 = V_165 ;
V_281 -> V_289 = V_1 -> V_141 ;
V_281 -> V_290 = V_1 -> V_290 ;
V_281 -> V_291 = V_292 ;
V_281 -> V_293 = V_1 -> V_294 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_190 ( V_1 -> V_141 ,
V_1 -> V_290 , V_253 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_191 ( & V_253 [ V_295 ] ,
V_1 -> V_141 , ( sizeof( struct V_15 ) *
V_1 -> V_290 ) ) ;
V_221 = F_154 ( V_1 , V_253 , V_165 ) ;
if ( V_221 )
return V_221 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_174 = F_192 ( & V_1 -> V_66 , V_1 , V_281 , & V_283 , V_253 ,
V_142 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( ! V_174 )
goto V_220;
V_142 -> V_174 = V_174 ;
F_193 ( & V_142 -> V_182 ,
( V_296 ) F_112 ) ;
if ( V_232 -> V_238 == V_239 ) {
V_221 = F_150 ( V_1 , V_142 ,
V_165 , V_1 -> V_141 ) ;
if ( V_221 )
goto V_220;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_194 ( V_174 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
return 0 ;
V_220:
F_153 ( V_1 , V_253 ) ;
return V_221 ;
}
static void
F_195 ( struct V_1 * V_1 , struct V_297 * V_298 )
{
V_298 -> V_299 = V_300 ;
V_298 -> V_301 = V_1 -> V_145 ;
V_298 -> V_293 = V_1 -> V_302 ;
if ( V_1 -> V_145 > 1 ) {
V_298 -> V_303 = V_304 ;
V_298 -> V_305 . V_306 =
( V_307 |
V_308 |
V_309 |
V_310 ) ;
V_298 -> V_305 . V_311 =
V_1 -> V_145 - 1 ;
F_196 ( V_298 -> V_305 . V_312 ,
sizeof( V_298 -> V_305 . V_312 ) ) ;
} else {
V_298 -> V_303 = V_313 ;
memset ( & V_298 -> V_305 , 0 ,
sizeof( V_298 -> V_305 ) ) ;
}
V_298 -> V_314 = V_315 ;
V_298 -> V_12 = V_1 -> V_316 ;
V_298 -> V_317 = V_318 ;
V_298 -> V_319 = V_304 ;
}
static void
F_197 ( struct V_1 * V_1 , T_1 V_251 )
{
struct V_137 * V_138 = & V_1 -> V_138 [ V_251 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_145 ; V_11 ++ )
V_138 -> V_94 [ V_11 ] . V_1 = V_1 ;
}
void
F_198 ( struct V_1 * V_1 , T_1 V_251 )
{
struct V_137 * V_138 = & V_1 -> V_138 [ V_251 ] ;
struct V_297 * V_298 = & V_1 -> V_298 [ V_251 ] ;
struct V_252 * V_253 = & V_1 -> V_320 [ V_251 ] . V_253 [ 0 ] ;
unsigned long V_40 ;
int V_266 = 0 ;
if ( ! V_138 -> V_144 )
return;
if ( 0 == V_251 ) {
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( V_1 -> V_224 & V_265 &&
F_19 ( V_262 , & V_1 -> V_135 ) ) {
F_34 ( V_262 , & V_1 -> V_135 ) ;
V_266 = 1 ;
}
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_266 )
F_174 ( & V_1 -> V_263 ) ;
}
F_185 ( & V_1 -> V_151 . V_189 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_199 ( V_138 -> V_144 , V_278 , F_126 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_187 ( & V_1 -> V_151 . V_189 ) ;
if ( V_138 -> V_94 [ 0 ] . V_8 -> V_238 == V_239 )
F_151 ( V_1 , V_138 , V_298 -> V_301 ) ;
F_182 ( V_1 , V_251 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_200 ( V_138 -> V_144 ) ;
V_138 -> V_144 = NULL ;
V_138 -> V_251 = 0 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_155 ( V_1 , V_253 ) ;
}
int
F_201 ( struct V_1 * V_1 , T_1 V_251 )
{
int V_221 ;
struct V_137 * V_138 = & V_1 -> V_138 [ V_251 ] ;
struct V_252 * V_253 = & V_1 -> V_320 [ V_251 ] . V_253 [ 0 ] ;
struct V_231 * V_232 =
& V_253 [ V_321 ] . V_257 . V_232 ;
struct V_297 * V_298 = & V_1 -> V_298 [ V_251 ] ;
static const struct V_322 V_323 = {
. V_324 = NULL ,
. V_325 = NULL ,
. V_326 = F_107 ,
. V_327 = F_108 ,
. V_328 = F_118 ,
. V_329 = F_122 ,
. V_330 = F_124 ,
} ;
struct V_185 * V_144 ;
unsigned long V_40 ;
V_138 -> V_251 = V_251 ;
F_195 ( V_1 , V_298 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_202 ( V_298 , V_253 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_191 ( & V_253 [ V_331 ] ,
V_298 -> V_301 +
( ( V_298 -> V_314 == V_332 ) ?
0 : V_298 -> V_301 ) ,
( ( V_1 -> V_316 * sizeof( struct V_72 ) ) +
sizeof( struct V_59 ) ) ) ;
V_221 = F_156 ( V_1 , V_253 , V_251 ) ;
if ( V_221 )
return V_221 ;
F_197 ( V_1 , V_251 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_144 = F_203 ( & V_1 -> V_66 , V_1 , V_298 , & V_323 , V_253 ,
V_138 ) ;
if ( ! V_144 ) {
V_221 = - V_219 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
goto V_220;
}
V_138 -> V_144 = V_144 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_204 ( & V_138 -> V_187 ,
( V_296 ) ( F_119 ) ) ;
F_180 ( V_1 , V_251 ) ;
if ( V_232 -> V_238 == V_239 ) {
V_221 = F_152 ( V_1 , V_138 , V_251 ,
V_298 -> V_301 ) ;
if ( V_221 )
goto V_220;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( 0 == V_251 ) {
if ( V_1 -> V_224 & V_265 )
F_205 ( & V_1 -> V_66 , V_333 ) ;
F_206 ( V_144 ) ;
F_169 ( V_1 ) ;
}
F_207 ( V_144 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
return 0 ;
V_220:
F_198 ( V_1 , V_251 ) ;
return V_221 ;
}
void
F_208 ( struct V_1 * V_1 )
{
struct V_176 * V_142 ;
V_142 = & V_1 -> V_142 [ 0 ] ;
if ( ! V_142 -> V_174 )
return;
F_209 ( V_142 -> V_174 , V_1 -> V_294 ) ;
}
void
F_210 ( struct V_1 * V_1 )
{
struct V_137 * V_138 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_143 ; V_11 ++ ) {
V_138 = & V_1 -> V_138 [ V_11 ] ;
if ( ! V_138 -> V_144 )
continue;
F_211 ( V_138 -> V_144 ,
V_1 -> V_302 ) ;
}
}
int
F_212 ( struct V_1 * V_1 , T_6 * V_334 )
{
int V_335 ;
if ( ! F_213 ( V_334 ) )
return - V_336 ;
if ( ! V_1 -> V_138 [ 0 ] . V_144 )
return 0 ;
V_335 = F_214 ( V_1 -> V_138 [ 0 ] . V_144 , V_334 , NULL ) ;
if ( V_335 != V_153 )
return - V_336 ;
return 0 ;
}
int
F_215 ( struct V_1 * V_1 )
{
struct V_137 * V_138 = & V_1 -> V_138 [ 0 ] ;
int V_335 ;
unsigned long V_40 ;
F_185 ( & V_1 -> V_151 . V_191 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_335 = F_216 ( V_138 -> V_144 , ( T_6 * ) V_337 ,
F_127 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_335 == V_153 )
F_187 ( & V_1 -> V_151 . V_191 ) ;
else
return - V_338 ;
if ( V_1 -> V_151 . V_190 != V_153 )
return - V_338 ;
return 0 ;
}
void
F_217 ( struct V_1 * V_1 , T_1 V_251 )
{
T_7 V_339 ;
unsigned long V_40 ;
F_218 (vid, bnad->active_vlans, VLAN_N_VID) {
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_219 ( V_1 -> V_138 [ V_251 ] . V_144 , V_339 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
}
void
F_220 ( struct V_1 * V_1 , struct V_340 * V_195 )
{
int V_11 , V_136 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_143 ; V_11 ++ ) {
for ( V_136 = 0 ; V_136 < V_1 -> V_145 ; V_136 ++ ) {
if ( V_1 -> V_138 [ V_11 ] . V_94 [ V_136 ] . V_8 ) {
V_195 -> V_124 += V_1 -> V_138 [ V_11 ] .
V_94 [ V_136 ] . V_8 -> V_58 [ 0 ] -> V_68 -> V_124 ;
V_195 -> V_125 += V_1 -> V_138 [ V_11 ] .
V_94 [ V_136 ] . V_8 -> V_58 [ 0 ] -> V_68 -> V_125 ;
if ( V_1 -> V_138 [ V_11 ] . V_94 [ V_136 ] . V_8 -> V_58 [ 1 ] &&
V_1 -> V_138 [ V_11 ] . V_94 [ V_136 ] . V_8 ->
V_58 [ 1 ] -> V_68 ) {
V_195 -> V_124 +=
V_1 -> V_138 [ V_11 ] . V_94 [ V_136 ] .
V_8 -> V_58 [ 1 ] -> V_68 -> V_124 ;
V_195 -> V_125 +=
V_1 -> V_138 [ V_11 ] . V_94 [ V_136 ] .
V_8 -> V_58 [ 1 ] -> V_68 -> V_125 ;
}
}
}
}
for ( V_11 = 0 ; V_11 < V_1 -> V_140 ; V_11 ++ ) {
for ( V_136 = 0 ; V_136 < V_1 -> V_141 ; V_136 ++ ) {
if ( V_1 -> V_142 [ V_11 ] . V_32 [ V_136 ] ) {
V_195 -> V_45 +=
V_1 -> V_142 [ V_11 ] . V_32 [ V_136 ] -> V_44 -> V_45 ;
V_195 -> V_46 +=
V_1 -> V_142 [ V_11 ] . V_32 [ V_136 ] -> V_44 -> V_46 ;
}
}
}
}
void
F_221 ( struct V_1 * V_1 , struct V_340 * V_195 )
{
struct V_341 * V_342 ;
T_1 V_343 ;
int V_11 ;
V_342 = & V_1 -> V_195 . V_194 -> V_344 . V_342 ;
V_195 -> V_345 =
V_342 -> V_346 + V_342 -> V_347 +
V_342 -> V_348 + V_342 -> V_349 +
V_342 -> V_350 ;
V_195 -> V_351 = V_342 -> V_352 +
V_342 -> V_353 ;
V_195 -> V_354 = V_342 -> V_355 ;
V_195 -> V_356 = V_342 -> V_357 ;
V_195 -> V_358 = V_342 -> V_359 ;
V_195 -> V_360 = V_342 -> V_361 ;
V_195 -> V_362 = V_342 -> V_348 ;
V_195 -> V_363 = V_342 -> V_346 ;
V_195 -> V_364 = V_342 -> V_347 ;
V_343 = F_222 ( & V_1 -> V_66 ) ;
for ( V_11 = 0 ; V_343 ; V_11 ++ ) {
if ( V_343 & 1 ) {
V_195 -> V_365 +=
V_1 -> V_195 . V_194 ->
V_344 . V_366 [ V_11 ] . V_367 ;
break;
}
V_343 >>= 1 ;
}
}
static void
F_223 ( struct V_1 * V_1 )
{
T_1 V_54 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( V_1 -> V_224 & V_225 )
V_54 = V_1 -> V_226 [ V_227 ] . V_21 ;
else
V_54 = V_1 -> V_23 -> V_54 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_224 ( V_54 ) ;
}
static int
F_225 ( struct V_1 * V_1 , struct V_19 * V_20 )
{
int V_221 ;
if ( F_226 ( V_20 ) ) {
V_221 = F_227 ( V_20 , 0 , 0 , V_84 ) ;
if ( V_221 ) {
F_30 ( V_1 , V_368 ) ;
return V_221 ;
}
}
if ( V_20 -> V_100 == F_228 ( V_369 ) ) {
struct V_370 * V_371 = F_229 ( V_20 ) ;
V_371 -> V_372 = 0 ;
V_371 -> V_373 = 0 ;
F_230 ( V_20 ) -> V_373 =
~ F_231 ( V_371 -> V_374 , V_371 -> V_375 , 0 ,
V_376 , 0 ) ;
F_30 ( V_1 , V_377 ) ;
} else {
struct V_378 * V_379 = F_232 ( V_20 ) ;
V_379 -> V_380 = 0 ;
F_230 ( V_20 ) -> V_373 =
~ F_233 ( & V_379 -> V_374 , & V_379 -> V_375 , 0 ,
V_376 , 0 ) ;
F_30 ( V_1 , V_381 ) ;
}
return 0 ;
}
static void
F_234 ( struct V_1 * V_1 )
{
int V_382 ;
V_382 = F_235 ( ( T_4 ) F_236 () ,
( T_4 ) ( V_383 * V_186 ) ) ;
if ( ! ( V_1 -> V_224 & V_225 ) )
V_382 = 1 ;
V_1 -> V_143 = 1 ;
V_1 -> V_140 = 1 ;
V_1 -> V_145 = V_382 ;
V_1 -> V_141 = V_384 ;
}
static void
F_237 ( struct V_1 * V_1 , int V_385 , int V_386 )
{
V_1 -> V_141 = 1 ;
if ( ( V_385 >= ( V_1 -> V_140 * V_1 -> V_141 ) +
V_387 + V_242 ) &&
( V_1 -> V_224 & V_225 ) ) {
V_1 -> V_145 = V_385 -
( V_1 -> V_140 * V_1 -> V_141 ) -
V_242 ;
} else
V_1 -> V_145 = 1 ;
}
static int
F_238 ( struct V_1 * V_1 )
{
unsigned long V_40 ;
int V_221 = 0 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_185 ( & V_1 -> V_151 . V_154 ) ;
F_239 ( & V_1 -> V_66 . V_260 , V_278 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_240 ( & V_1 -> V_151 . V_154 ,
F_115 ( V_388 ) ) ;
V_221 = V_1 -> V_151 . V_152 ;
return V_221 ;
}
static int
F_241 ( struct V_1 * V_1 )
{
int V_221 = 0 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_185 ( & V_1 -> V_151 . V_154 ) ;
V_1 -> V_151 . V_152 = V_389 ;
F_242 ( & V_1 -> V_66 . V_260 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_240 ( & V_1 -> V_151 . V_154 ,
F_115 ( V_388 ) ) ;
V_221 = V_1 -> V_151 . V_152 ;
return V_221 ;
}
static void
F_243 ( struct V_1 * V_1 , struct V_252 * V_253 ,
T_1 V_390 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_390 ; V_11 ++ )
F_133 ( V_1 , & V_253 [ V_11 ] . V_257 . V_209 ) ;
}
static int
F_244 ( struct V_1 * V_1 , struct V_252 * V_253 ,
T_1 V_390 )
{
int V_11 , V_221 ;
for ( V_11 = 0 ; V_11 < V_390 ; V_11 ++ ) {
V_221 = F_137 ( V_1 , & V_253 [ V_11 ] . V_257 . V_209 ) ;
if ( V_221 )
goto V_220;
}
return 0 ;
V_220:
F_243 ( V_1 , V_253 , V_390 ) ;
return V_221 ;
}
static void
F_245 ( struct V_1 * V_1 )
{
int V_11 , V_335 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( ! ( V_1 -> V_224 & V_225 ) ) {
F_80 ( & V_1 -> V_133 , V_40 ) ;
return;
}
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_1 -> V_226 )
return;
V_1 -> V_226 =
F_138 ( V_1 -> V_391 , sizeof( struct V_392 ) , V_218 ) ;
if ( ! V_1 -> V_226 )
goto V_393;
for ( V_11 = 0 ; V_11 < V_1 -> V_391 ; V_11 ++ )
V_1 -> V_226 [ V_11 ] . V_394 = V_11 ;
V_335 = F_246 ( V_1 -> V_23 , V_1 -> V_226 , V_1 -> V_391 ) ;
if ( V_335 > 0 ) {
F_247 ( L_10 ,
V_335 , V_1 -> V_391 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_237 ( V_1 , ( V_335 - V_242 ) / 2 ,
( V_335 - V_242 ) / 2 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_1 -> V_391 = V_395 + V_396 +
V_242 ;
if ( V_1 -> V_391 > V_335 )
goto V_393;
V_335 = F_246 ( V_1 -> V_23 , V_1 -> V_226 ,
V_1 -> V_391 ) ;
if ( V_335 )
goto V_393;
} else if ( V_335 < 0 )
goto V_393;
F_248 ( V_1 -> V_23 , 0 ) ;
return;
V_393:
F_247 ( L_11 ) ;
F_136 ( V_1 -> V_226 ) ;
V_1 -> V_226 = NULL ;
V_1 -> V_391 = 0 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_1 -> V_224 &= ~ V_225 ;
F_234 ( V_1 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static void
F_249 ( struct V_1 * V_1 )
{
T_1 V_224 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_224 = V_1 -> V_224 ;
if ( V_1 -> V_224 & V_225 )
V_1 -> V_224 &= ~ V_225 ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_224 & V_225 ) {
F_250 ( V_1 -> V_23 ) ;
F_136 ( V_1 -> V_226 ) ;
V_1 -> V_226 = NULL ;
}
}
static int
F_251 ( struct V_47 * V_48 )
{
int V_221 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_397 V_398 ;
int V_64 ;
unsigned long V_40 ;
F_2 ( & V_1 -> V_399 ) ;
V_221 = F_189 ( V_1 , 0 ) ;
if ( V_221 )
goto V_220;
V_221 = F_201 ( V_1 , 0 ) ;
if ( V_221 )
goto V_400;
V_398 . V_401 = 0 ;
V_398 . V_402 = 0 ;
V_64 = V_403 + V_404 + V_1 -> V_48 -> V_64 + V_405 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_253 ( & V_1 -> V_66 . V_67 , V_64 , NULL ) ;
F_254 ( & V_1 -> V_66 . V_67 , & V_398 , NULL ) ;
F_255 ( & V_1 -> V_66 . V_67 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_215 ( V_1 ) ;
F_217 ( V_1 , 0 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_212 ( V_1 , V_48 -> V_150 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_171 ( V_1 ) ;
F_4 ( & V_1 -> V_399 ) ;
return 0 ;
V_400:
F_184 ( V_1 , 0 ) ;
V_220:
F_4 ( & V_1 -> V_399 ) ;
return V_221 ;
}
static int
F_256 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
F_2 ( & V_1 -> V_399 ) ;
F_172 ( V_1 ) ;
F_185 ( & V_1 -> V_151 . V_157 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_257 ( & V_1 -> V_66 . V_67 , V_278 ,
F_97 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_187 ( & V_1 -> V_151 . V_157 ) ;
F_184 ( V_1 , 0 ) ;
F_198 ( V_1 , 0 ) ;
F_223 ( V_1 ) ;
F_4 ( & V_1 -> V_399 ) ;
return 0 ;
}
static int
F_258 ( struct V_1 * V_1 , struct V_31 * V_32 ,
struct V_19 * V_20 , struct V_406 * V_407 )
{
T_7 V_40 = 0 ;
T_1 V_408 ;
T_7 V_127 = 0 ;
if ( F_259 ( V_20 ) ) {
V_127 = ( T_7 ) F_260 ( V_20 ) ;
V_40 |= ( V_409 | V_410 ) ;
}
if ( F_19 ( V_163 , & V_1 -> V_135 ) ) {
V_127 = ( ( V_32 -> V_411 & 0x7 ) << V_412 )
| ( V_127 & 0x1fff ) ;
V_40 |= ( V_409 | V_410 ) ;
}
V_407 -> V_413 . V_414 . V_127 = F_228 ( V_127 ) ;
if ( F_261 ( V_20 ) ) {
V_408 = F_15 ( V_20 ) -> V_408 ;
if ( F_49 ( V_408 > V_1 -> V_48 -> V_64 ) ) {
F_30 ( V_1 , V_415 ) ;
return - V_416 ;
}
if ( F_49 ( ( V_408 + F_262 ( V_20 ) +
F_263 ( V_20 ) ) >= V_20 -> V_43 ) ) {
V_407 -> V_413 . V_414 . V_417 =
F_264 ( V_418 ) ;
V_407 -> V_413 . V_414 . V_419 = 0 ;
F_30 ( V_1 , V_420 ) ;
} else {
V_407 -> V_413 . V_414 . V_417 =
F_264 ( V_421 ) ;
V_407 -> V_413 . V_414 . V_419 = F_228 ( V_408 ) ;
}
if ( F_225 ( V_1 , V_20 ) ) {
F_30 ( V_1 , V_422 ) ;
return - V_416 ;
}
V_40 |= ( V_423 | V_424 ) ;
V_407 -> V_413 . V_414 . V_425 =
F_228 ( F_265 (
F_263 ( V_20 ) >> 2 , F_262 ( V_20 ) ) ) ;
} else {
V_407 -> V_413 . V_414 . V_417 = F_264 ( V_418 ) ;
V_407 -> V_413 . V_414 . V_419 = 0 ;
if ( F_49 ( V_20 -> V_43 > ( V_1 -> V_48 -> V_64 + V_403 ) ) ) {
F_30 ( V_1 , V_426 ) ;
return - V_416 ;
}
if ( V_20 -> V_122 == V_427 ) {
T_6 V_428 = 0 ;
if ( V_20 -> V_100 == F_264 ( V_369 ) )
V_428 = F_229 ( V_20 ) -> V_100 ;
#ifdef F_266
else if ( V_20 -> V_100 ==
F_264 ( V_429 ) ) {
V_428 = F_232 ( V_20 ) -> V_430 ;
}
#endif
if ( V_428 == V_376 ) {
V_40 |= V_424 ;
V_407 -> V_413 . V_414 . V_425 =
F_228 ( F_265
( 0 , F_262 ( V_20 ) ) ) ;
F_30 ( V_1 , V_431 ) ;
if ( F_49 ( F_11 ( V_20 ) <
F_262 ( V_20 ) +
F_263 ( V_20 ) ) ) {
F_30 ( V_1 , V_432 ) ;
return - V_416 ;
}
} else if ( V_428 == V_433 ) {
V_40 |= V_434 ;
V_407 -> V_413 . V_414 . V_425 =
F_228 ( F_265
( 0 , F_262 ( V_20 ) ) ) ;
F_30 ( V_1 , V_435 ) ;
if ( F_49 ( F_11 ( V_20 ) <
F_262 ( V_20 ) +
sizeof( struct V_436 ) ) ) {
F_30 ( V_1 , V_437 ) ;
return - V_416 ;
}
} else {
F_30 ( V_1 , V_438 ) ;
return - V_416 ;
}
} else
V_407 -> V_413 . V_414 . V_425 = 0 ;
}
V_407 -> V_413 . V_414 . V_40 = F_228 ( V_40 ) ;
V_407 -> V_413 . V_414 . V_439 = F_267 ( V_20 -> V_43 ) ;
return 0 ;
}
static T_8
F_268 ( struct V_19 * V_20 , struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
T_1 V_170 = 0 ;
struct V_31 * V_32 = NULL ;
struct V_15 * V_16 , * V_18 , * V_440 ;
T_1 V_77 , V_12 , V_441 ;
T_1 V_35 , V_25 , V_43 ;
int V_11 ;
T_3 V_26 ;
struct V_406 * V_407 ;
V_43 = F_11 ( V_20 ) ;
if ( F_49 ( V_20 -> V_43 <= V_403 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_442 ) ;
return V_443 ;
}
if ( F_49 ( V_43 > V_444 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_445 ) ;
return V_443 ;
}
if ( F_49 ( V_43 == 0 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_445 ) ;
return V_443 ;
}
V_32 = V_1 -> V_142 [ 0 ] . V_32 [ V_170 ] ;
V_12 = V_32 -> V_12 ;
V_77 = V_32 -> V_83 ;
V_16 = V_32 -> V_16 ;
if ( F_49 ( ! F_19 ( V_39 , & V_32 -> V_40 ) ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_446 ) ;
return V_443 ;
}
V_25 = 1 + F_15 ( V_20 ) -> V_97 ;
V_35 = F_23 ( V_25 ) ;
if ( F_49 ( V_25 > V_447 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_448 ) ;
return V_443 ;
}
if ( F_49 ( V_35 > F_28 ( V_32 , V_12 ) ) ) {
if ( ( * V_32 -> V_41 != V_32 -> V_42 ) &&
! F_25 ( V_50 , & V_32 -> V_40 ) ) {
T_1 V_49 ;
V_49 = F_18 ( V_1 , V_32 ) ;
if ( F_31 ( F_19 ( V_39 , & V_32 -> V_40 ) ) )
F_32 ( V_32 -> V_53 , V_49 ) ;
F_33 () ;
F_34 ( V_50 , & V_32 -> V_40 ) ;
} else {
F_270 ( V_48 ) ;
F_30 ( V_1 , V_172 ) ;
}
F_52 () ;
if ( F_31 ( V_35 > F_28 ( V_32 , V_12 ) ) ) {
F_30 ( V_1 , V_172 ) ;
return V_449 ;
} else {
F_29 ( V_48 ) ;
F_30 ( V_1 , V_52 ) ;
}
}
V_407 = & ( (struct V_406 * ) V_32 -> V_13 ) [ V_77 ] ;
V_440 = & V_16 [ V_77 ] ;
if ( F_258 ( V_1 , V_32 , V_20 , V_407 ) ) {
F_269 ( V_20 ) ;
return V_443 ;
}
V_407 -> V_413 . V_414 . V_450 = 0 ;
V_407 -> V_413 . V_414 . V_451 = V_25 ;
V_440 -> V_20 = V_20 ;
V_440 -> V_22 = 0 ;
V_18 = V_440 ;
V_26 = F_56 ( & V_1 -> V_23 -> V_24 , V_20 -> V_55 ,
V_43 , V_27 ) ;
F_51 ( V_26 , & V_407 -> V_21 [ 0 ] . V_88 ) ;
V_407 -> V_21 [ 0 ] . V_95 = F_228 ( V_43 ) ;
F_12 ( & V_18 -> V_25 [ 0 ] , V_26 , V_26 ) ;
V_440 -> V_22 ++ ;
for ( V_11 = 0 , V_441 = 0 ; V_11 < V_25 - 1 ; V_11 ++ ) {
const struct V_452 * V_453 = & F_15 ( V_20 ) -> V_29 [ V_11 ] ;
T_7 V_30 = F_271 ( V_453 ) ;
if ( F_49 ( V_30 == 0 ) ) {
F_8 ( V_1 , V_16 , V_12 ,
V_32 -> V_83 ) ;
F_269 ( V_20 ) ;
F_30 ( V_1 , V_454 ) ;
return V_443 ;
}
V_43 += V_30 ;
V_441 ++ ;
if ( V_441 == V_28 ) {
V_441 = 0 ;
F_13 ( V_77 , V_12 ) ;
V_407 = & ( (struct V_406 * ) V_32 -> V_13 ) [ V_77 ] ;
V_407 -> V_413 . V_455 . V_417 =
F_264 ( V_456 ) ;
V_18 = & V_16 [ V_77 ] ;
}
V_26 = F_272 ( & V_1 -> V_23 -> V_24 , V_453 ,
0 , V_30 , V_27 ) ;
F_51 ( V_26 , & V_407 -> V_21 [ V_441 ] . V_88 ) ;
V_407 -> V_21 [ V_441 ] . V_95 = F_228 ( V_30 ) ;
F_12 ( & V_18 -> V_25 [ V_441 ] , V_26 ,
V_26 ) ;
V_440 -> V_22 ++ ;
}
if ( F_49 ( V_43 != V_20 -> V_43 ) ) {
F_8 ( V_1 , V_16 , V_12 , V_32 -> V_83 ) ;
F_269 ( V_20 ) ;
F_30 ( V_1 , V_457 ) ;
return V_443 ;
}
F_13 ( V_77 , V_12 ) ;
V_32 -> V_83 = V_77 ;
F_52 () ;
if ( F_49 ( ! F_19 ( V_39 , & V_32 -> V_40 ) ) )
return V_443 ;
F_273 ( V_32 ) ;
F_52 () ;
return V_443 ;
}
static struct V_340 *
F_274 ( struct V_47 * V_48 , struct V_340 * V_195 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_220 ( V_1 , V_195 ) ;
F_221 ( V_1 , V_195 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_195 ;
}
void
F_275 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
T_1 V_458 , V_459 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_458 = V_459 = 0 ;
if ( V_48 -> V_40 & V_460 ) {
if ( ! ( V_1 -> V_224 & V_461 ) ) {
V_458 = V_462 ;
V_459 = V_462 ;
V_1 -> V_224 |= V_461 ;
}
} else {
if ( V_1 -> V_224 & V_461 ) {
V_458 = ~ V_462 ;
V_459 = V_462 ;
V_1 -> V_224 &= ~ V_461 ;
}
}
if ( V_48 -> V_40 & V_463 ) {
if ( ! ( V_1 -> V_224 & V_464 ) ) {
V_458 |= V_465 ;
V_459 |= V_465 ;
V_1 -> V_224 |= V_464 ;
}
} else {
if ( V_1 -> V_224 & V_464 ) {
V_458 &= ~ V_465 ;
V_459 |= V_465 ;
V_1 -> V_224 &= ~ V_464 ;
}
}
if ( V_1 -> V_138 [ 0 ] . V_144 == NULL )
goto V_466;
F_276 ( V_1 -> V_138 [ 0 ] . V_144 , V_458 , V_459 , NULL ) ;
if ( ! F_277 ( V_48 ) ) {
T_6 * V_467 ;
int V_468 = F_278 ( V_48 ) ;
V_467 =
F_140 ( ( V_468 + 1 ) * V_270 ,
V_84 ) ;
if ( ! V_467 )
goto V_466;
memcpy ( & V_467 [ 0 ] , & V_337 [ 0 ] , V_270 ) ;
F_175 ( V_48 , V_467 ) ;
F_279 ( V_1 -> V_138 [ 0 ] . V_144 , V_468 + 1 ,
V_467 , NULL ) ;
F_136 ( V_467 ) ;
}
V_466:
F_80 ( & V_1 -> V_133 , V_40 ) ;
}
static int
F_280 ( struct V_47 * V_48 , void * V_334 )
{
int V_221 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_469 * V_470 = (struct V_469 * ) V_334 ;
unsigned long V_40 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
V_221 = F_212 ( V_1 , V_470 -> V_471 ) ;
if ( ! V_221 )
memcpy ( V_48 -> V_150 , V_470 -> V_471 , V_48 -> V_149 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
return V_221 ;
}
static int
F_281 ( struct V_1 * V_1 , int V_64 )
{
unsigned long V_40 ;
F_185 ( & V_1 -> V_151 . V_202 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_253 ( & V_1 -> V_66 . V_67 , V_64 , F_131 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_187 ( & V_1 -> V_151 . V_202 ) ;
return V_1 -> V_151 . V_201 ;
}
static int
F_282 ( struct V_47 * V_48 , int V_472 )
{
int V_221 , V_64 = V_48 -> V_64 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
if ( V_472 + V_403 < V_473 || V_472 > V_474 )
return - V_416 ;
F_2 ( & V_1 -> V_399 ) ;
V_48 -> V_64 = V_472 ;
V_64 = V_403 + V_404 + V_472 + V_405 ;
V_221 = F_281 ( V_1 , V_64 ) ;
if ( V_221 )
V_221 = - V_475 ;
F_4 ( & V_1 -> V_399 ) ;
return V_221 ;
}
static int
F_283 ( struct V_47 * V_48 ,
unsigned short V_339 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
if ( ! V_1 -> V_138 [ 0 ] . V_144 )
return 0 ;
F_2 ( & V_1 -> V_399 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_219 ( V_1 -> V_138 [ 0 ] . V_144 , V_339 ) ;
F_88 ( V_339 , V_1 -> V_476 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_4 ( & V_1 -> V_399 ) ;
return 0 ;
}
static int
F_284 ( struct V_47 * V_48 ,
unsigned short V_339 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
if ( ! V_1 -> V_138 [ 0 ] . V_144 )
return 0 ;
F_2 ( & V_1 -> V_399 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_34 ( V_339 , V_1 -> V_476 ) ;
F_285 ( V_1 -> V_138 [ 0 ] . V_144 , V_339 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_4 ( & V_1 -> V_399 ) ;
return 0 ;
}
static void
F_286 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_137 * V_138 ;
struct V_93 * V_94 ;
T_1 V_477 ;
int V_11 , V_136 ;
if ( ! ( V_1 -> V_224 & V_225 ) ) {
F_287 ( & V_1 -> V_66 , V_477 ) ;
F_84 ( V_1 -> V_23 -> V_54 , V_48 ) ;
F_288 ( & V_1 -> V_66 , V_477 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_1 -> V_143 ; V_11 ++ ) {
V_138 = & V_1 -> V_138 [ V_11 ] ;
if ( ! V_138 -> V_144 )
continue;
for ( V_136 = 0 ; V_136 < V_1 -> V_145 ; V_136 ++ ) {
V_94 = & V_138 -> V_94 [ V_136 ] ;
if ( V_94 -> V_8 )
F_74 ( V_1 ,
V_94 -> V_8 ) ;
}
}
}
}
static void
F_289 ( struct V_1 * V_1 , bool V_478 )
{
struct V_47 * V_48 = V_1 -> V_48 ;
V_48 -> V_479 = V_480 | V_117 |
V_481 | F_266 |
V_482 | V_483 | V_484 ;
V_48 -> V_485 = V_480 | V_486 |
V_481 | F_266 |
V_482 | V_483 ;
V_48 -> V_116 |= V_48 -> V_479 |
V_487 | V_488 ;
if ( V_478 )
V_48 -> V_116 |= V_486 ;
V_48 -> V_489 = V_1 -> V_490 ;
V_48 -> V_491 = V_1 -> V_490 + V_1 -> V_492 - 1 ;
V_48 -> V_493 = & V_494 ;
F_290 ( V_48 ) ;
}
static int
F_291 ( struct V_1 * V_1 ,
struct V_495 * V_496 , struct V_47 * V_48 )
{
unsigned long V_40 ;
F_292 ( V_48 , & V_496 -> V_24 ) ;
F_293 ( V_496 , V_48 ) ;
V_1 -> V_48 = V_48 ;
V_1 -> V_23 = V_496 ;
V_1 -> V_490 = F_294 ( V_496 , 0 ) ;
V_1 -> V_492 = F_295 ( V_496 , 0 ) ;
V_1 -> V_497 = F_296 ( V_1 -> V_490 , V_1 -> V_492 ) ;
if ( ! V_1 -> V_497 ) {
F_297 ( & V_496 -> V_24 , L_12 ) ;
F_293 ( V_496 , NULL ) ;
return - V_219 ;
}
F_298 ( L_13 , V_1 -> V_497 ,
( unsigned long long ) V_1 -> V_492 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( ! V_498 )
V_1 -> V_224 = V_225 ;
V_1 -> V_224 |= V_265 ;
F_234 ( V_1 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_1 -> V_391 = ( V_1 -> V_140 * V_1 -> V_141 ) +
( V_1 -> V_143 * V_1 -> V_145 ) +
V_242 ;
V_1 -> V_290 = V_499 ;
V_1 -> V_316 = V_500 ;
V_1 -> V_294 = V_501 ;
V_1 -> V_302 = V_502 ;
sprintf ( V_1 -> V_503 , L_14 , V_230 , V_1 -> V_5 ) ;
V_1 -> V_184 = F_299 ( V_1 -> V_503 ) ;
if ( ! V_1 -> V_184 )
return - V_219 ;
return 0 ;
}
static void
F_300 ( struct V_1 * V_1 )
{
if ( V_1 -> V_184 ) {
F_301 ( V_1 -> V_184 ) ;
F_302 ( V_1 -> V_184 ) ;
V_1 -> V_184 = NULL ;
}
if ( V_1 -> V_497 )
F_303 ( V_1 -> V_497 ) ;
F_293 ( V_1 -> V_23 , NULL ) ;
}
static void
F_304 ( struct V_1 * V_1 )
{
F_305 ( & V_1 -> V_133 ) ;
F_306 ( & V_1 -> V_399 ) ;
F_306 ( & V_2 ) ;
}
static void
F_307 ( struct V_1 * V_1 )
{
F_308 ( & V_1 -> V_399 ) ;
F_308 ( & V_2 ) ;
}
static int
F_309 ( struct V_1 * V_1 ,
struct V_495 * V_496 , bool * V_478 )
{
int V_221 ;
V_221 = F_310 ( V_496 ) ;
if ( V_221 )
return V_221 ;
V_221 = F_311 ( V_496 , V_230 ) ;
if ( V_221 )
goto V_504;
if ( ! F_312 ( & V_496 -> V_24 , F_313 ( 64 ) ) &&
! F_314 ( & V_496 -> V_24 , F_313 ( 64 ) ) ) {
* V_478 = true ;
} else {
V_221 = F_312 ( & V_496 -> V_24 , F_313 ( 32 ) ) ;
if ( V_221 ) {
V_221 = F_314 ( & V_496 -> V_24 ,
F_313 ( 32 ) ) ;
if ( V_221 )
goto V_505;
}
* V_478 = false ;
}
F_315 ( V_496 ) ;
return 0 ;
V_505:
F_316 ( V_496 ) ;
V_504:
F_317 ( V_496 ) ;
return V_221 ;
}
static void
F_318 ( struct V_495 * V_496 )
{
F_316 ( V_496 ) ;
F_317 ( V_496 ) ;
}
static int
F_319 ( struct V_495 * V_496 ,
const struct V_506 * V_507 )
{
bool V_478 ;
int V_221 ;
struct V_1 * V_1 ;
struct V_66 * V_66 ;
struct V_47 * V_48 ;
struct V_508 V_509 ;
unsigned long V_40 ;
F_298 ( L_15 ,
V_496 , V_507 , F_320 ( V_496 -> V_510 ) ) ;
F_2 ( & V_511 ) ;
if ( ! F_321 ( V_496 ) ) {
F_4 ( & V_511 ) ;
F_247 ( L_16 ) ;
return - V_338 ;
}
F_4 ( & V_511 ) ;
V_48 = F_322 ( sizeof( struct V_1 ) ) ;
if ( ! V_48 ) {
V_221 = - V_219 ;
return V_221 ;
}
V_1 = F_252 ( V_48 ) ;
F_304 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( & V_1 -> V_399 ) ;
V_478 = false ;
V_221 = F_309 ( V_1 , V_496 , & V_478 ) ;
if ( V_221 )
goto V_512;
V_221 = F_291 ( V_1 , V_496 , V_48 ) ;
if ( V_221 )
goto V_513;
F_289 ( V_1 , V_478 ) ;
F_98 ( V_48 ) ;
if ( V_514 )
F_323 ( V_1 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_324 ( & V_1 -> V_253 [ 0 ] ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_221 = F_244 ( V_1 , & V_1 -> V_253 [ 0 ] , V_515 ) ;
if ( V_221 )
goto V_516;
V_66 = & V_1 -> V_66 ;
V_509 . V_517 = F_325 ( V_1 -> V_23 -> V_510 ) ;
V_509 . V_518 = F_320 ( V_1 -> V_23 -> V_510 ) ;
V_509 . V_519 = V_1 -> V_23 -> V_520 ;
V_509 . V_521 = V_1 -> V_497 ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_326 ( V_66 , V_1 , & V_509 , & V_1 -> V_253 [ 0 ] ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_1 -> V_195 . V_194 = & V_66 -> V_195 ;
F_245 ( V_1 ) ;
V_221 = F_144 ( V_1 ) ;
if ( V_221 )
goto V_522;
F_170 ( & V_1 -> V_66 . V_260 . V_261 . V_523 , F_157 ,
( ( unsigned long ) V_1 ) ) ;
F_170 ( & V_1 -> V_66 . V_260 . V_261 . V_524 , F_159 ,
( ( unsigned long ) V_1 ) ) ;
F_170 ( & V_1 -> V_66 . V_260 . V_261 . V_525 , F_161 ,
( ( unsigned long ) V_1 ) ) ;
F_170 ( & V_1 -> V_66 . V_260 . V_261 . V_526 , F_163 ,
( ( unsigned long ) V_1 ) ) ;
F_130 ( & V_1 -> V_66 . V_260 . V_261 . V_525 ,
V_199 + F_115 ( V_527 ) ) ;
V_221 = F_241 ( V_1 ) ;
if ( V_221 ) {
F_327 ( L_17 ,
V_221 ) ;
goto V_528;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
if ( F_328 ( V_66 , V_395 + 1 ) ||
F_329 ( V_66 , V_396 + 1 ) ) {
F_237 ( V_1 , F_330 ( V_66 ) -> V_289 - 1 ,
F_330 ( V_66 ) -> V_529 - 1 ) ;
if ( F_328 ( V_66 , V_395 + 1 ) ||
F_329 ( V_66 , V_396 + 1 ) )
V_221 = - V_530 ;
}
F_80 ( & V_1 -> V_133 , V_40 ) ;
if ( V_221 )
goto V_531;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_331 ( & V_1 -> V_66 , & V_1 -> V_532 [ 0 ] ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
V_221 = F_244 ( V_1 , & V_1 -> V_532 [ 0 ] , V_533 ) ;
if ( V_221 ) {
V_221 = - V_530 ;
goto V_531;
}
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_332 ( & V_1 -> V_66 , & V_1 -> V_532 [ 0 ] ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_111 ( & V_66 -> V_67 , & V_1 -> V_148 ) ;
F_89 ( V_1 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_4 ( & V_1 -> V_399 ) ;
V_221 = F_333 ( V_48 ) ;
if ( V_221 ) {
F_327 ( L_18 ) ;
goto V_534;
}
F_88 ( V_535 , & V_1 -> V_135 ) ;
return 0 ;
V_528:
F_4 ( & V_1 -> V_399 ) ;
return 0 ;
V_534:
F_2 ( & V_1 -> V_399 ) ;
F_243 ( V_1 , & V_1 -> V_532 [ 0 ] , V_533 ) ;
V_531:
F_238 ( V_1 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_523 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_526 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_524 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_334 ( V_66 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_141 ( V_1 ) ;
F_249 ( V_1 ) ;
V_522:
F_243 ( V_1 , & V_1 -> V_253 [ 0 ] , V_515 ) ;
V_516:
F_136 ( V_1 -> V_536 ) ;
F_335 ( V_1 ) ;
F_300 ( V_1 ) ;
V_513:
F_318 ( V_496 ) ;
V_512:
F_4 ( & V_1 -> V_399 ) ;
F_5 ( V_1 ) ;
F_307 ( V_1 ) ;
F_336 ( V_48 ) ;
return V_221 ;
}
static void
F_337 ( struct V_495 * V_496 )
{
struct V_47 * V_48 = F_338 ( V_496 ) ;
struct V_1 * V_1 ;
struct V_66 * V_66 ;
unsigned long V_40 ;
if ( ! V_48 )
return;
F_298 ( L_19 , V_48 -> V_168 ) ;
V_1 = F_252 ( V_48 ) ;
V_66 = & V_1 -> V_66 ;
if ( F_173 ( V_535 , & V_1 -> V_135 ) )
F_339 ( V_48 ) ;
F_2 ( & V_1 -> V_399 ) ;
F_238 ( V_1 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_523 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_526 ) ;
F_174 ( & V_1 -> V_66 . V_260 . V_261 . V_524 ) ;
F_79 ( & V_1 -> V_133 , V_40 ) ;
F_334 ( V_66 ) ;
F_80 ( & V_1 -> V_133 , V_40 ) ;
F_243 ( V_1 , & V_1 -> V_532 [ 0 ] , V_533 ) ;
F_243 ( V_1 , & V_1 -> V_253 [ 0 ] , V_515 ) ;
F_141 ( V_1 ) ;
F_249 ( V_1 ) ;
F_318 ( V_496 ) ;
F_4 ( & V_1 -> V_399 ) ;
F_5 ( V_1 ) ;
F_307 ( V_1 ) ;
F_136 ( V_1 -> V_536 ) ;
F_335 ( V_1 ) ;
F_300 ( V_1 ) ;
F_336 ( V_48 ) ;
}
static int T_9
F_340 ( void )
{
int V_221 ;
F_298 ( L_20 ,
V_537 ) ;
F_341 ( V_538 ) ;
V_221 = F_342 ( & V_539 ) ;
if ( V_221 < 0 ) {
F_327 ( L_21
L_22 , V_221 ) ;
return V_221 ;
}
return 0 ;
}
static void T_10
F_343 ( void )
{
F_344 ( & V_539 ) ;
F_345 ( V_540 ) ;
}
