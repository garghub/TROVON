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
F_69 ( V_20 , F_70 ( V_127 ) , F_66 ( V_10 -> V_128 ) ) ;
if ( F_45 ( V_16 -> type ) )
F_71 ( & V_94 -> V_96 ) ;
else
F_72 ( V_20 ) ;
V_114:
V_10 -> V_14 = 0 ;
F_13 ( V_58 -> V_42 , V_58 -> V_12 ) ;
F_13 ( V_8 -> V_83 , V_8 -> V_12 ) ;
V_10 = & V_102 [ V_8 -> V_83 ] ;
}
F_73 ( & V_94 -> V_96 , false ) ;
if ( F_31 ( F_19 ( V_129 , & V_8 -> V_58 [ 0 ] -> V_40 ) ) )
F_74 ( V_8 -> V_53 , V_107 ) ;
F_57 ( V_1 , V_8 -> V_58 [ 0 ] ) ;
if ( V_8 -> V_58 [ 1 ] )
F_57 ( V_1 , V_8 -> V_58 [ 1 ] ) ;
return V_107 ;
}
static void
F_75 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_93 * V_94 = (struct V_93 * ) ( V_8 -> V_106 ) ;
struct V_130 * V_96 = & V_94 -> V_96 ;
if ( F_31 ( F_76 ( V_96 ) ) ) {
F_77 ( V_96 ) ;
V_94 -> V_131 ++ ;
}
}
static T_2
F_78 ( int V_54 , void * V_55 )
{
struct V_7 * V_8 = (struct V_7 * ) V_55 ;
if ( V_8 ) {
( (struct V_93 * ) ( V_8 -> V_106 ) ) -> V_132 ++ ;
F_75 ( V_8 -> V_1 , V_8 ) ;
}
return V_56 ;
}
static T_2
F_79 ( int V_54 , void * V_55 )
{
T_1 V_133 ;
unsigned long V_40 ;
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( F_49 ( F_19 ( V_135 , & V_1 -> V_136 ) ) ) {
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_56 ;
}
F_82 ( & V_1 -> V_66 , V_133 ) ;
if ( F_83 ( & V_1 -> V_66 , V_133 ) )
F_84 ( & V_1 -> V_66 , V_133 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_56 ;
}
static T_2
F_85 ( int V_54 , void * V_55 )
{
int V_11 , V_137 ;
T_1 V_133 ;
unsigned long V_40 ;
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
struct V_138 * V_139 ;
struct V_93 * V_94 ;
struct V_31 * V_32 = NULL ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( F_49 ( F_19 ( V_135 , & V_1 -> V_136 ) ) ) {
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_140 ;
}
F_82 ( & V_1 -> V_66 , V_133 ) ;
if ( F_49 ( ! V_133 ) ) {
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_140 ;
}
if ( F_83 ( & V_1 -> V_66 , V_133 ) )
F_84 ( & V_1 -> V_66 , V_133 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( ! F_86 ( V_133 ) )
return V_56 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_141 ; V_11 ++ ) {
for ( V_137 = 0 ; V_137 < V_1 -> V_142 ; V_137 ++ ) {
V_32 = V_1 -> V_143 [ V_11 ] . V_32 [ V_137 ] ;
if ( V_32 && F_19 ( V_39 , & V_32 -> V_40 ) )
F_24 ( V_1 , V_1 -> V_143 [ V_11 ] . V_32 [ V_137 ] ) ;
}
}
for ( V_11 = 0 ; V_11 < V_1 -> V_144 ; V_11 ++ ) {
V_139 = & V_1 -> V_139 [ V_11 ] ;
if ( ! V_139 -> V_145 )
continue;
for ( V_137 = 0 ; V_137 < V_1 -> V_146 ; V_137 ++ ) {
V_94 = & V_139 -> V_94 [ V_137 ] ;
if ( V_94 -> V_8 )
F_75 ( V_1 ,
V_94 -> V_8 ) ;
}
}
return V_56 ;
}
static void
F_87 ( struct V_1 * V_1 )
{
F_34 ( V_135 , & V_1 -> V_136 ) ;
F_30 ( V_1 , V_147 ) ;
}
static void
F_88 ( struct V_1 * V_1 )
{
F_89 ( V_135 , & V_1 -> V_136 ) ;
F_30 ( V_1 , V_148 ) ;
}
static void
F_90 ( struct V_1 * V_1 )
{
struct V_47 * V_48 = V_1 -> V_48 ;
memcpy ( V_48 -> V_149 , & V_1 -> V_149 , V_48 -> V_150 ) ;
if ( F_91 ( V_48 -> V_151 ) )
memcpy ( V_48 -> V_151 , & V_1 -> V_149 , V_48 -> V_150 ) ;
}
void
F_92 ( struct V_1 * V_1 )
{
F_87 ( V_1 ) ;
}
void
F_93 ( struct V_1 * V_1 )
{
F_88 ( V_1 ) ;
}
void
F_94 ( struct V_1 * V_1 )
{
V_1 -> V_152 . V_153 = V_154 ;
F_95 ( & V_1 -> V_152 . V_155 ) ;
}
void
F_96 ( struct V_1 * V_1 )
{
V_1 -> V_152 . V_153 = V_156 ;
F_95 ( & V_1 -> V_152 . V_155 ) ;
}
void
F_97 ( struct V_1 * V_1 )
{
V_1 -> V_152 . V_153 = V_154 ;
F_95 ( & V_1 -> V_152 . V_155 ) ;
}
static void
F_98 ( void * V_157 )
{
struct V_1 * V_1 = (struct V_1 * ) V_157 ;
F_99 ( V_1 -> V_48 ) ;
F_95 ( & V_1 -> V_152 . V_158 ) ;
}
void
F_100 ( struct V_1 * V_1 ,
enum V_159 V_160 )
{
bool V_161 = false ;
V_161 = ( V_160 == V_162 ) || ( V_160 == V_163 ) ;
if ( V_160 == V_163 ) {
if ( ! F_19 ( V_164 , & V_1 -> V_136 ) )
F_30 ( V_1 , V_165 ) ;
F_89 ( V_164 , & V_1 -> V_136 ) ;
} else {
if ( F_19 ( V_164 , & V_1 -> V_136 ) )
F_30 ( V_1 , V_165 ) ;
F_34 ( V_164 , & V_1 -> V_136 ) ;
}
if ( V_161 ) {
if ( ! F_27 ( V_1 -> V_48 ) ) {
T_4 V_166 , V_167 ;
F_101 ( V_168 L_1 ,
V_1 -> V_48 -> V_169 ) ;
F_102 ( V_1 -> V_48 ) ;
F_30 ( V_1 , V_170 ) ;
for ( V_166 = 0 ; V_166 < V_1 -> V_141 ; V_166 ++ ) {
for ( V_167 = 0 ; V_167 < V_1 -> V_142 ;
V_167 ++ ) {
struct V_31 * V_32 =
V_1 -> V_143 [ V_166 ] . V_32 [ V_167 ] ;
T_1 V_171 ;
if ( ! V_32 )
continue;
V_171 = V_32 -> V_5 ;
if ( F_19 ( V_39 ,
& V_32 -> V_40 ) ) {
F_101 ( V_172 L_2
L_3 ,
V_1 -> V_48 -> V_169 ,
V_171 ) ;
F_103 (
V_1 -> V_48 ,
V_171 ) ;
F_30 ( V_1 ,
V_52 ) ;
} else {
F_104 (
V_1 -> V_48 ,
V_171 ) ;
F_30 ( V_1 ,
V_173 ) ;
}
}
}
}
} else {
if ( F_27 ( V_1 -> V_48 ) ) {
F_101 ( V_168 L_4 ,
V_1 -> V_48 -> V_169 ) ;
F_99 ( V_1 -> V_48 ) ;
F_30 ( V_1 , V_170 ) ;
}
}
}
static void
F_105 ( void * V_157 , struct V_174 * V_175 )
{
struct V_1 * V_1 = (struct V_1 * ) V_157 ;
F_95 ( & V_1 -> V_152 . V_176 ) ;
}
static void
F_106 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_177 * V_143 =
(struct V_177 * ) V_32 -> V_44 -> V_175 -> V_178 ;
V_32 -> V_178 = V_32 ;
V_143 -> V_32 [ V_32 -> V_5 ] = V_32 ;
}
static void
F_107 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
struct V_177 * V_143 =
(struct V_177 * ) V_32 -> V_44 -> V_175 -> V_178 ;
V_143 -> V_32 [ V_32 -> V_5 ] = NULL ;
V_32 -> V_178 = NULL ;
}
static void
F_108 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_138 * V_139 =
(struct V_138 * ) V_8 -> V_102 -> V_145 -> V_178 ;
V_139 -> V_94 [ V_8 -> V_5 ] . V_8 = V_8 ;
V_8 -> V_106 = & V_139 -> V_94 [ V_8 -> V_5 ] ;
}
static void
F_109 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_138 * V_139 =
(struct V_138 * ) V_8 -> V_102 -> V_145 -> V_178 ;
V_139 -> V_94 [ V_8 -> V_5 ] . V_8 = NULL ;
}
static void
F_110 ( struct V_1 * V_1 , struct V_174 * V_175 )
{
struct V_177 * V_143 =
(struct V_177 * ) V_175 -> V_178 ;
struct V_31 * V_32 ;
T_1 V_171 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
V_32 = V_143 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_171 = V_32 -> V_5 ;
F_34 ( V_39 , & V_32 -> V_40 ) ;
F_104 ( V_1 -> V_48 , V_171 ) ;
F_101 ( V_172 L_5 ,
V_1 -> V_48 -> V_169 , V_171 ) ;
}
}
static void
F_111 ( struct V_1 * V_1 , struct V_174 * V_175 )
{
struct V_177 * V_143 = (struct V_177 * ) V_175 -> V_178 ;
struct V_31 * V_32 ;
T_1 V_171 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
V_32 = V_143 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_171 = V_32 -> V_5 ;
F_21 ( F_19 ( V_39 , & V_32 -> V_40 ) ) ;
F_89 ( V_39 , & V_32 -> V_40 ) ;
F_21 ( * ( V_32 -> V_41 ) != 0 ) ;
if ( F_27 ( V_1 -> V_48 ) ) {
F_101 ( V_172 L_6 ,
V_1 -> V_48 -> V_169 , V_171 ) ;
F_103 ( V_1 -> V_48 , V_171 ) ;
F_30 ( V_1 , V_52 ) ;
}
}
if ( F_91 ( & V_1 -> V_149 . V_180 [ 0 ] ) ) {
F_112 ( & V_1 -> V_66 . V_67 , & V_1 -> V_149 ) ;
F_90 ( V_1 ) ;
}
}
static void
F_113 ( struct V_181 * V_182 )
{
struct V_177 * V_143 =
F_114 ( V_182 , struct V_177 , V_183 ) ;
struct V_1 * V_1 = NULL ;
struct V_31 * V_32 ;
unsigned long V_40 ;
T_1 V_11 , V_184 = 0 ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
V_32 = V_143 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
V_1 = V_32 -> V_1 ;
if ( F_25 ( V_50 , & V_32 -> V_40 ) ) {
V_184 ++ ;
continue;
}
F_16 ( V_1 , V_32 ) ;
F_33 () ;
F_34 ( V_50 , & V_32 -> V_40 ) ;
}
if ( V_184 ) {
F_115 ( V_1 -> V_185 , & V_143 -> V_183 ,
F_116 ( 1 ) ) ;
return;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_117 ( V_143 -> V_175 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_118 ( struct V_1 * V_1 , struct V_174 * V_175 )
{
struct V_177 * V_143 = (struct V_177 * ) V_175 -> V_178 ;
struct V_31 * V_32 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
V_32 = V_143 -> V_32 [ V_11 ] ;
if ( ! V_32 )
continue;
}
F_115 ( V_1 -> V_185 , & V_143 -> V_183 , 0 ) ;
}
static void
F_119 ( struct V_1 * V_1 , struct V_186 * V_145 )
{
struct V_138 * V_139 = (struct V_138 * ) V_145 -> V_178 ;
struct V_7 * V_8 ;
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
V_94 = & V_139 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_34 ( V_89 , & V_8 -> V_58 [ 0 ] -> V_40 ) ;
if ( V_8 -> V_58 [ 1 ] )
F_34 ( V_89 , & V_8 -> V_58 [ 1 ] -> V_40 ) ;
}
}
static void
F_120 ( void * V_182 )
{
struct V_138 * V_139 =
F_114 ( V_182 , struct V_138 , V_188 ) ;
struct V_93 * V_94 ;
struct V_1 * V_1 = NULL ;
unsigned long V_40 ;
T_1 V_11 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
V_94 = & V_139 -> V_94 [ V_11 ] ;
if ( ! V_94 -> V_8 )
continue;
V_1 = V_94 -> V_8 -> V_1 ;
F_121 ( & V_94 -> V_96 ) ;
F_7 ( V_1 , V_94 -> V_8 ) ;
F_44 ( V_1 , V_94 -> V_8 -> V_58 [ 0 ] ) ;
if ( V_94 -> V_8 -> V_58 [ 1 ] )
F_44 ( V_1 , V_94 -> V_8 -> V_58 [ 1 ] ) ;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_122 ( V_139 -> V_145 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_123 ( struct V_1 * V_1 , struct V_186 * V_145 )
{
struct V_138 * V_139 = (struct V_138 * ) V_145 -> V_178 ;
struct V_7 * V_8 ;
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
V_94 = & V_139 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_34 ( V_129 , & V_8 -> V_58 [ 0 ] -> V_40 ) ;
if ( V_8 -> V_58 [ 1 ] )
F_34 ( V_129 , & V_8 -> V_58 [ 1 ] -> V_40 ) ;
}
F_124 ( V_1 -> V_185 , & V_139 -> V_188 ) ;
}
static void
F_125 ( struct V_1 * V_1 , struct V_186 * V_145 )
{
struct V_138 * V_139 = (struct V_138 * ) V_145 -> V_178 ;
struct V_7 * V_8 ;
struct V_57 * V_58 ;
struct V_93 * V_94 ;
int V_11 , V_137 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
V_94 = & V_139 -> V_94 [ V_11 ] ;
V_8 = V_94 -> V_8 ;
if ( ! V_8 )
continue;
F_126 ( & V_94 -> V_96 ) ;
for ( V_137 = 0 ; V_137 < V_189 ; V_137 ++ ) {
V_58 = V_8 -> V_58 [ V_137 ] ;
if ( ! V_58 )
continue;
F_37 ( V_1 , V_58 ) ;
F_89 ( V_129 , & V_58 -> V_40 ) ;
F_89 ( V_89 , & V_58 -> V_40 ) ;
F_57 ( V_1 , V_58 ) ;
}
}
}
static void
F_127 ( void * V_157 , struct V_186 * V_145 )
{
struct V_1 * V_1 = (struct V_1 * ) V_157 ;
F_95 ( & V_1 -> V_152 . V_190 ) ;
}
static void
F_128 ( struct V_1 * V_1 , struct V_186 * V_145 )
{
V_1 -> V_152 . V_191 = V_154 ;
F_95 ( & V_1 -> V_152 . V_192 ) ;
}
void
F_129 ( struct V_1 * V_1 , enum V_193 V_194 ,
struct V_195 * V_196 )
{
if ( V_194 == V_154 )
F_30 ( V_1 , V_197 ) ;
if ( ! F_130 ( V_1 -> V_48 ) ||
! F_19 ( V_198 , & V_1 -> V_136 ) )
return;
F_131 ( & V_1 -> V_199 ,
V_200 + F_116 ( V_201 ) ) ;
}
static void
F_132 ( struct V_1 * V_1 )
{
V_1 -> V_152 . V_202 = V_154 ;
F_95 ( & V_1 -> V_152 . V_203 ) ;
}
void
F_133 ( void * V_157 , enum V_204 V_194 )
{
struct V_205 * V_206 =
(struct V_205 * ) V_157 ;
V_206 -> V_207 = ( T_1 ) V_194 ;
F_95 ( & V_206 -> V_208 ) ;
}
static void
F_134 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
int V_11 ;
T_3 V_211 ;
if ( V_210 -> V_212 == NULL )
return;
for ( V_11 = 0 ; V_11 < V_210 -> V_213 ; V_11 ++ ) {
if ( V_210 -> V_212 [ V_11 ] . V_214 != NULL ) {
if ( V_210 -> V_215 == V_216 ) {
F_135 ( & ( V_210 -> V_212 [ V_11 ] . V_217 ) ,
V_211 ) ;
F_136 ( & V_1 -> V_23 -> V_24 ,
V_210 -> V_212 [ V_11 ] . V_43 ,
V_210 -> V_212 [ V_11 ] . V_214 , V_211 ) ;
} else
F_137 ( V_210 -> V_212 [ V_11 ] . V_214 ) ;
}
}
F_137 ( V_210 -> V_212 ) ;
V_210 -> V_212 = NULL ;
}
static int
F_138 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
int V_11 ;
T_3 V_211 ;
if ( ( V_210 -> V_213 == 0 ) || ( V_210 -> V_43 == 0 ) ) {
V_210 -> V_212 = NULL ;
return 0 ;
}
V_210 -> V_212 = F_139 ( V_210 -> V_213 , sizeof( struct V_218 ) ,
V_219 ) ;
if ( V_210 -> V_212 == NULL )
return - V_220 ;
if ( V_210 -> V_215 == V_216 ) {
for ( V_11 = 0 ; V_11 < V_210 -> V_213 ; V_11 ++ ) {
V_210 -> V_212 [ V_11 ] . V_43 = V_210 -> V_43 ;
V_210 -> V_212 [ V_11 ] . V_214 =
F_140 ( & V_1 -> V_23 -> V_24 ,
V_210 -> V_43 , & V_211 ,
V_219 ) ;
if ( V_210 -> V_212 [ V_11 ] . V_214 == NULL )
goto V_221;
F_51 ( V_211 ,
& ( V_210 -> V_212 [ V_11 ] . V_217 ) ) ;
}
} else {
for ( V_11 = 0 ; V_11 < V_210 -> V_213 ; V_11 ++ ) {
V_210 -> V_212 [ V_11 ] . V_43 = V_210 -> V_43 ;
V_210 -> V_212 [ V_11 ] . V_214 = F_141 ( V_210 -> V_43 ,
V_219 ) ;
if ( V_210 -> V_212 [ V_11 ] . V_214 == NULL )
goto V_221;
}
}
return 0 ;
V_221:
F_134 ( V_1 , V_210 ) ;
return - V_220 ;
}
static void
F_142 ( struct V_1 * V_1 )
{
int V_54 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_88 ( V_1 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_54 = F_143 ( V_1 ) ;
F_144 ( V_54 , V_1 ) ;
}
static int
F_145 ( struct V_1 * V_1 )
{
int V_222 = 0 ;
unsigned long V_223 , V_40 ;
T_1 V_54 ;
T_5 V_224 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( V_1 -> V_225 & V_226 ) {
V_224 = ( T_5 ) F_79 ;
V_54 = V_1 -> V_227 [ V_228 ] . V_21 ;
V_223 = 0 ;
} else {
V_224 = ( T_5 ) F_85 ;
V_54 = V_1 -> V_23 -> V_54 ;
V_223 = V_229 ;
}
F_81 ( & V_1 -> V_134 , V_40 ) ;
sprintf ( V_1 -> V_230 , L_7 , V_231 ) ;
F_89 ( V_135 , & V_1 -> V_136 ) ;
F_30 ( V_1 , V_148 ) ;
V_222 = F_146 ( V_54 , V_224 , V_223 ,
V_1 -> V_230 , V_1 ) ;
return V_222 ;
}
static void
F_147 ( struct V_1 * V_1 , struct V_232 * V_233 )
{
F_137 ( V_233 -> V_234 ) ;
V_233 -> V_234 = NULL ;
}
static int
F_148 ( struct V_1 * V_1 , enum V_235 V_236 ,
T_1 V_237 , struct V_232 * V_233 )
{
int V_11 , V_238 = 0 ;
T_1 V_225 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_225 = V_1 -> V_225 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_225 & V_226 ) {
V_233 -> V_239 = V_240 ;
V_233 -> V_234 = F_139 ( V_233 -> V_213 ,
sizeof( struct V_241 ) ,
V_219 ) ;
if ( ! V_233 -> V_234 )
return - V_220 ;
switch ( V_236 ) {
case V_242 :
V_238 = V_243 + V_237 ;
break;
case V_244 :
V_238 = V_243 +
( V_1 -> V_141 * V_1 -> V_142 ) +
V_237 ;
break;
default:
F_149 () ;
}
for ( V_11 = 0 ; V_11 < V_233 -> V_213 ; V_11 ++ )
V_233 -> V_234 [ V_11 ] . V_21 = V_238 + V_11 ;
} else {
V_233 -> V_239 = V_245 ;
V_233 -> V_213 = 1 ;
V_233 -> V_234 = F_139 ( V_233 -> V_213 ,
sizeof( struct V_241 ) ,
V_219 ) ;
if ( ! V_233 -> V_234 )
return - V_220 ;
switch ( V_236 ) {
case V_242 :
V_233 -> V_234 [ 0 ] . V_21 = V_246 ;
break;
case V_244 :
V_233 -> V_234 [ 0 ] . V_21 = V_247 ;
break;
}
}
return 0 ;
}
static void
F_150 ( struct V_1 * V_1 , struct V_177 * V_143 ,
int V_248 )
{
int V_11 ;
int V_249 ;
for ( V_11 = 0 ; V_11 < V_248 ; V_11 ++ ) {
if ( V_143 -> V_32 [ V_11 ] == NULL )
continue;
V_249 = V_143 -> V_32 [ V_11 ] -> V_250 ;
F_144 ( V_1 -> V_227 [ V_249 ] . V_21 , V_143 -> V_32 [ V_11 ] ) ;
}
}
static int
F_151 ( struct V_1 * V_1 , struct V_177 * V_143 ,
T_1 V_166 , int V_248 )
{
int V_11 ;
int V_222 ;
int V_249 ;
for ( V_11 = 0 ; V_11 < V_248 ; V_11 ++ ) {
V_249 = V_143 -> V_32 [ V_11 ] -> V_250 ;
sprintf ( V_143 -> V_32 [ V_11 ] -> V_169 , L_8 , V_1 -> V_48 -> V_169 ,
V_166 + V_143 -> V_32 [ V_11 ] -> V_5 ) ;
V_222 = F_146 ( V_1 -> V_227 [ V_249 ] . V_21 ,
( T_5 ) F_35 , 0 ,
V_143 -> V_32 [ V_11 ] -> V_169 ,
V_143 -> V_32 [ V_11 ] ) ;
if ( V_222 )
goto V_221;
}
return 0 ;
V_221:
if ( V_11 > 0 )
F_150 ( V_1 , V_143 , ( V_11 - 1 ) ) ;
return - 1 ;
}
static void
F_152 ( struct V_1 * V_1 , struct V_138 * V_139 ,
int V_251 )
{
int V_11 ;
int V_249 ;
for ( V_11 = 0 ; V_11 < V_251 ; V_11 ++ ) {
if ( V_139 -> V_94 [ V_11 ] . V_8 == NULL )
continue;
V_249 = V_139 -> V_94 [ V_11 ] . V_8 -> V_250 ;
F_144 ( V_1 -> V_227 [ V_249 ] . V_21 ,
V_139 -> V_94 [ V_11 ] . V_8 ) ;
}
}
static int
F_153 ( struct V_1 * V_1 , struct V_138 * V_139 ,
T_1 V_252 , int V_251 )
{
int V_11 ;
int V_222 ;
int V_249 ;
for ( V_11 = 0 ; V_11 < V_251 ; V_11 ++ ) {
V_249 = V_139 -> V_94 [ V_11 ] . V_8 -> V_250 ;
sprintf ( V_139 -> V_94 [ V_11 ] . V_8 -> V_169 , L_9 ,
V_1 -> V_48 -> V_169 ,
V_252 + V_139 -> V_94 [ V_11 ] . V_8 -> V_5 ) ;
V_222 = F_146 ( V_1 -> V_227 [ V_249 ] . V_21 ,
( T_5 ) F_78 , 0 ,
V_139 -> V_94 [ V_11 ] . V_8 -> V_169 ,
V_139 -> V_94 [ V_11 ] . V_8 ) ;
if ( V_222 )
goto V_221;
}
return 0 ;
V_221:
if ( V_11 > 0 )
F_152 ( V_1 , V_139 , ( V_11 - 1 ) ) ;
return - 1 ;
}
static void
F_154 ( struct V_1 * V_1 , struct V_253 * V_254 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_255 ; V_11 ++ ) {
if ( V_254 [ V_11 ] . V_256 == V_257 )
F_134 ( V_1 , & V_254 [ V_11 ] . V_258 . V_210 ) ;
else if ( V_254 [ V_11 ] . V_256 == V_259 )
F_147 ( V_1 , & V_254 [ V_11 ] . V_258 . V_233 ) ;
}
}
static int
F_155 ( struct V_1 * V_1 , struct V_253 * V_254 ,
T_1 V_166 )
{
int V_11 , V_222 = 0 ;
for ( V_11 = 0 ; V_11 < V_255 ; V_11 ++ ) {
if ( V_254 [ V_11 ] . V_256 == V_257 )
V_222 = F_138 ( V_1 ,
& V_254 [ V_11 ] . V_258 . V_210 ) ;
else if ( V_254 [ V_11 ] . V_256 == V_259 )
V_222 = F_148 ( V_1 , V_242 , V_166 ,
& V_254 [ V_11 ] . V_258 . V_233 ) ;
if ( V_222 )
goto V_221;
}
return 0 ;
V_221:
F_154 ( V_1 , V_254 ) ;
return V_222 ;
}
static void
F_156 ( struct V_1 * V_1 , struct V_253 * V_254 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_260 ; V_11 ++ ) {
if ( V_254 [ V_11 ] . V_256 == V_257 )
F_134 ( V_1 , & V_254 [ V_11 ] . V_258 . V_210 ) ;
else if ( V_254 [ V_11 ] . V_256 == V_259 )
F_147 ( V_1 , & V_254 [ V_11 ] . V_258 . V_233 ) ;
}
}
static int
F_157 ( struct V_1 * V_1 , struct V_253 * V_254 ,
T_4 V_252 )
{
int V_11 , V_222 = 0 ;
for ( V_11 = 0 ; V_11 < V_260 ; V_11 ++ ) {
if ( V_254 [ V_11 ] . V_256 == V_257 )
V_222 = F_138 ( V_1 ,
& V_254 [ V_11 ] . V_258 . V_210 ) ;
else if ( V_254 [ V_11 ] . V_256 == V_259 )
V_222 = F_148 ( V_1 , V_244 , V_252 ,
& V_254 [ V_11 ] . V_258 . V_233 ) ;
if ( V_222 )
goto V_221;
}
return 0 ;
V_221:
F_156 ( V_1 , V_254 ) ;
return V_222 ;
}
static void
F_158 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_159 ( ( void * ) & V_1 -> V_66 . V_261 . V_262 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_160 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_161 ( ( void * ) & V_1 -> V_66 . V_261 . V_262 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_162 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_163 ( ( void * ) & V_1 -> V_66 . V_261 . V_262 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_164 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_165 ( ( void * ) & V_1 -> V_66 . V_261 . V_262 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_166 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
struct V_138 * V_139 ;
struct V_93 * V_94 ;
int V_11 , V_137 ;
unsigned long V_40 ;
if ( ! F_27 ( V_1 -> V_48 ) )
return;
F_80 ( & V_1 -> V_134 , V_40 ) ;
for ( V_11 = 0 ; V_11 < V_1 -> V_144 ; V_11 ++ ) {
V_139 = & V_1 -> V_139 [ V_11 ] ;
if ( ! V_139 -> V_145 )
continue;
for ( V_137 = 0 ; V_137 < V_1 -> V_146 ; V_137 ++ ) {
V_94 = & V_139 -> V_94 [ V_137 ] ;
if ( ! V_94 -> V_8 )
continue;
F_167 ( V_94 -> V_8 ) ;
}
}
if ( F_19 ( V_263 , & V_1 -> V_136 ) )
F_131 ( & V_1 -> V_264 ,
V_200 + F_116 ( V_265 ) ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_168 ( unsigned long V_55 )
{
struct V_1 * V_1 = (struct V_1 * ) V_55 ;
unsigned long V_40 ;
if ( ! F_130 ( V_1 -> V_48 ) ||
! F_19 ( V_198 , & V_1 -> V_136 ) )
return;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_169 ( & V_1 -> V_66 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
void
F_170 ( struct V_1 * V_1 )
{
if ( V_1 -> V_225 & V_266 &&
! F_19 ( V_263 , & V_1 -> V_136 ) ) {
F_171 ( & V_1 -> V_264 , F_166 ,
( unsigned long ) V_1 ) ;
F_89 ( V_263 , & V_1 -> V_136 ) ;
F_131 ( & V_1 -> V_264 ,
V_200 + F_116 ( V_265 ) ) ;
}
}
static void
F_172 ( struct V_1 * V_1 )
{
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( ! F_25 ( V_198 , & V_1 -> V_136 ) ) {
F_171 ( & V_1 -> V_199 , F_168 ,
( unsigned long ) V_1 ) ;
F_131 ( & V_1 -> V_199 ,
V_200 + F_116 ( V_201 ) ) ;
}
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_173 ( struct V_1 * V_1 )
{
int V_267 = 0 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( F_174 ( V_198 , & V_1 -> V_136 ) )
V_267 = 1 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_267 )
F_175 ( & V_1 -> V_199 ) ;
}
static void
F_176 ( struct V_47 * V_48 , T_6 * V_268 )
{
int V_11 = 1 ;
struct V_269 * V_270 ;
F_177 (mc_addr, netdev) {
memcpy ( & V_268 [ V_11 * V_271 ] , & V_270 -> V_272 [ 0 ] ,
V_271 ) ;
V_11 ++ ;
}
}
static int
F_178 ( struct V_130 * V_96 , int V_101 )
{
struct V_93 * V_94 =
F_114 ( V_96 , struct V_93 , V_96 ) ;
struct V_1 * V_1 = V_94 -> V_1 ;
int V_273 = 0 ;
V_94 -> V_274 ++ ;
if ( ! F_27 ( V_1 -> V_48 ) )
goto V_275;
V_273 = F_63 ( V_1 , V_94 -> V_8 , V_101 ) ;
if ( V_273 >= V_101 )
return V_273 ;
V_275:
F_179 ( V_96 ) ;
V_94 -> V_276 ++ ;
if ( V_94 -> V_8 )
F_180 ( V_94 -> V_8 ) ;
return V_273 ;
}
static void
F_181 ( struct V_1 * V_1 , T_1 V_252 )
{
struct V_93 * V_94 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_146 ; V_11 ++ ) {
V_94 = & V_1 -> V_139 [ V_252 ] . V_94 [ V_11 ] ;
F_182 ( V_1 -> V_48 , & V_94 -> V_96 ,
F_178 , V_277 ) ;
}
}
static void
F_183 ( struct V_1 * V_1 , T_1 V_252 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_146 ; V_11 ++ )
F_184 ( & V_1 -> V_139 [ V_252 ] . V_94 [ V_11 ] . V_96 ) ;
}
void
F_185 ( struct V_1 * V_1 , T_1 V_166 )
{
struct V_177 * V_143 = & V_1 -> V_143 [ V_166 ] ;
struct V_253 * V_254 = & V_1 -> V_278 [ V_166 ] . V_254 [ 0 ] ;
unsigned long V_40 ;
if ( ! V_143 -> V_175 )
return;
F_186 ( & V_1 -> V_152 . V_176 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_187 ( V_143 -> V_175 , V_279 , F_105 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_188 ( & V_1 -> V_152 . V_176 ) ;
if ( V_143 -> V_32 [ 0 ] -> V_239 == V_240 )
F_150 ( V_1 , V_143 ,
V_1 -> V_142 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_189 ( V_143 -> V_175 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_143 -> V_175 = NULL ;
V_143 -> V_166 = 0 ;
F_154 ( V_1 , V_254 ) ;
}
int
F_190 ( struct V_1 * V_1 , T_1 V_166 )
{
int V_222 ;
struct V_177 * V_143 = & V_1 -> V_143 [ V_166 ] ;
struct V_253 * V_254 = & V_1 -> V_278 [ V_166 ] . V_254 [ 0 ] ;
struct V_232 * V_233 =
& V_254 [ V_280 ] . V_258 . V_233 ;
struct V_281 * V_282 = & V_1 -> V_282 [ V_166 ] ;
static const struct V_283 V_284 = {
. V_285 = F_106 ,
. V_286 = F_107 ,
. V_287 = F_110 ,
. V_288 = F_111 ,
. V_289 = F_118 ,
} ;
struct V_174 * V_175 ;
unsigned long V_40 ;
V_143 -> V_166 = V_166 ;
V_282 -> V_290 = V_1 -> V_142 ;
V_282 -> V_291 = V_1 -> V_291 ;
V_282 -> V_292 = V_293 ;
V_282 -> V_294 = V_1 -> V_295 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_191 ( V_1 -> V_142 ,
V_1 -> V_291 , V_254 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_192 ( & V_254 [ V_296 ] ,
V_1 -> V_142 , ( sizeof( struct V_15 ) *
V_1 -> V_291 ) ) ;
V_222 = F_155 ( V_1 , V_254 , V_166 ) ;
if ( V_222 )
return V_222 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_175 = F_193 ( & V_1 -> V_66 , V_1 , V_282 , & V_284 , V_254 ,
V_143 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( ! V_175 )
goto V_221;
V_143 -> V_175 = V_175 ;
F_194 ( & V_143 -> V_183 ,
( V_297 ) F_113 ) ;
if ( V_233 -> V_239 == V_240 ) {
V_222 = F_151 ( V_1 , V_143 ,
V_166 , V_1 -> V_142 ) ;
if ( V_222 )
goto V_221;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_195 ( V_175 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
return 0 ;
V_221:
F_154 ( V_1 , V_254 ) ;
return V_222 ;
}
static void
F_196 ( struct V_1 * V_1 , struct V_298 * V_299 )
{
V_299 -> V_300 = V_301 ;
V_299 -> V_302 = V_1 -> V_146 ;
V_299 -> V_294 = V_1 -> V_303 ;
if ( V_1 -> V_146 > 1 ) {
V_299 -> V_304 = V_305 ;
V_299 -> V_306 . V_307 =
( V_308 |
V_309 |
V_310 |
V_311 ) ;
V_299 -> V_306 . V_312 =
V_1 -> V_146 - 1 ;
F_197 ( V_299 -> V_306 . V_313 ,
sizeof( V_299 -> V_306 . V_313 ) ) ;
} else {
V_299 -> V_304 = V_314 ;
memset ( & V_299 -> V_306 , 0 ,
sizeof( V_299 -> V_306 ) ) ;
}
V_299 -> V_315 = V_316 ;
V_299 -> V_12 = V_1 -> V_317 ;
V_299 -> V_318 = V_319 ;
V_299 -> V_320 = V_305 ;
}
static void
F_198 ( struct V_1 * V_1 , T_1 V_252 )
{
struct V_138 * V_139 = & V_1 -> V_139 [ V_252 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_146 ; V_11 ++ )
V_139 -> V_94 [ V_11 ] . V_1 = V_1 ;
}
void
F_199 ( struct V_1 * V_1 , T_1 V_252 )
{
struct V_138 * V_139 = & V_1 -> V_139 [ V_252 ] ;
struct V_298 * V_299 = & V_1 -> V_299 [ V_252 ] ;
struct V_253 * V_254 = & V_1 -> V_321 [ V_252 ] . V_254 [ 0 ] ;
unsigned long V_40 ;
int V_267 = 0 ;
if ( ! V_139 -> V_145 )
return;
if ( 0 == V_252 ) {
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( V_1 -> V_225 & V_266 &&
F_19 ( V_263 , & V_1 -> V_136 ) ) {
F_34 ( V_263 , & V_1 -> V_136 ) ;
V_267 = 1 ;
}
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_267 )
F_175 ( & V_1 -> V_264 ) ;
}
F_186 ( & V_1 -> V_152 . V_190 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_200 ( V_139 -> V_145 , V_279 , F_127 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_188 ( & V_1 -> V_152 . V_190 ) ;
if ( V_139 -> V_94 [ 0 ] . V_8 -> V_239 == V_240 )
F_152 ( V_1 , V_139 , V_299 -> V_302 ) ;
F_183 ( V_1 , V_252 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_201 ( V_139 -> V_145 ) ;
V_139 -> V_145 = NULL ;
V_139 -> V_252 = 0 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_156 ( V_1 , V_254 ) ;
}
int
F_202 ( struct V_1 * V_1 , T_1 V_252 )
{
int V_222 ;
struct V_138 * V_139 = & V_1 -> V_139 [ V_252 ] ;
struct V_253 * V_254 = & V_1 -> V_321 [ V_252 ] . V_254 [ 0 ] ;
struct V_232 * V_233 =
& V_254 [ V_322 ] . V_258 . V_233 ;
struct V_298 * V_299 = & V_1 -> V_299 [ V_252 ] ;
static const struct V_323 V_324 = {
. V_325 = NULL ,
. V_326 = NULL ,
. V_327 = F_108 ,
. V_328 = F_109 ,
. V_329 = F_119 ,
. V_330 = F_123 ,
. V_331 = F_125 ,
} ;
struct V_186 * V_145 ;
unsigned long V_40 ;
V_139 -> V_252 = V_252 ;
F_196 ( V_1 , V_299 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_203 ( V_299 , V_254 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_192 ( & V_254 [ V_332 ] ,
V_299 -> V_302 +
( ( V_299 -> V_315 == V_333 ) ?
0 : V_299 -> V_302 ) ,
( ( V_1 -> V_317 * sizeof( struct V_72 ) ) +
sizeof( struct V_59 ) ) ) ;
V_222 = F_157 ( V_1 , V_254 , V_252 ) ;
if ( V_222 )
return V_222 ;
F_198 ( V_1 , V_252 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_145 = F_204 ( & V_1 -> V_66 , V_1 , V_299 , & V_324 , V_254 ,
V_139 ) ;
if ( ! V_145 ) {
V_222 = - V_220 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
goto V_221;
}
V_139 -> V_145 = V_145 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_205 ( & V_139 -> V_188 ,
( V_297 ) ( F_120 ) ) ;
F_181 ( V_1 , V_252 ) ;
if ( V_233 -> V_239 == V_240 ) {
V_222 = F_153 ( V_1 , V_139 , V_252 ,
V_299 -> V_302 ) ;
if ( V_222 )
goto V_221;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( 0 == V_252 ) {
if ( V_1 -> V_225 & V_266 )
F_206 ( & V_1 -> V_66 , V_334 ) ;
F_207 ( V_145 ) ;
F_170 ( V_1 ) ;
}
F_208 ( V_145 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
return 0 ;
V_221:
F_199 ( V_1 , V_252 ) ;
return V_222 ;
}
void
F_209 ( struct V_1 * V_1 )
{
struct V_177 * V_143 ;
V_143 = & V_1 -> V_143 [ 0 ] ;
if ( ! V_143 -> V_175 )
return;
F_210 ( V_143 -> V_175 , V_1 -> V_295 ) ;
}
void
F_211 ( struct V_1 * V_1 )
{
struct V_138 * V_139 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_144 ; V_11 ++ ) {
V_139 = & V_1 -> V_139 [ V_11 ] ;
if ( ! V_139 -> V_145 )
continue;
F_212 ( V_139 -> V_145 ,
V_1 -> V_303 ) ;
}
}
int
F_213 ( struct V_1 * V_1 , T_6 * V_335 )
{
int V_336 ;
if ( ! F_214 ( V_335 ) )
return - V_337 ;
if ( ! V_1 -> V_139 [ 0 ] . V_145 )
return 0 ;
V_336 = F_215 ( V_1 -> V_139 [ 0 ] . V_145 , V_335 , NULL ) ;
if ( V_336 != V_154 )
return - V_337 ;
return 0 ;
}
int
F_216 ( struct V_1 * V_1 )
{
struct V_138 * V_139 = & V_1 -> V_139 [ 0 ] ;
int V_336 ;
unsigned long V_40 ;
F_186 ( & V_1 -> V_152 . V_192 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_336 = F_217 ( V_139 -> V_145 , ( T_6 * ) V_338 ,
F_128 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_336 == V_154 )
F_188 ( & V_1 -> V_152 . V_192 ) ;
else
return - V_339 ;
if ( V_1 -> V_152 . V_191 != V_154 )
return - V_339 ;
return 0 ;
}
void
F_218 ( struct V_1 * V_1 , T_1 V_252 )
{
T_7 V_340 ;
unsigned long V_40 ;
F_219 (vid, bnad->active_vlans, VLAN_N_VID) {
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_220 ( V_1 -> V_139 [ V_252 ] . V_145 , V_340 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
}
void
F_221 ( struct V_1 * V_1 , struct V_341 * V_196 )
{
int V_11 , V_137 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_144 ; V_11 ++ ) {
for ( V_137 = 0 ; V_137 < V_1 -> V_146 ; V_137 ++ ) {
if ( V_1 -> V_139 [ V_11 ] . V_94 [ V_137 ] . V_8 ) {
V_196 -> V_124 += V_1 -> V_139 [ V_11 ] .
V_94 [ V_137 ] . V_8 -> V_58 [ 0 ] -> V_68 -> V_124 ;
V_196 -> V_125 += V_1 -> V_139 [ V_11 ] .
V_94 [ V_137 ] . V_8 -> V_58 [ 0 ] -> V_68 -> V_125 ;
if ( V_1 -> V_139 [ V_11 ] . V_94 [ V_137 ] . V_8 -> V_58 [ 1 ] &&
V_1 -> V_139 [ V_11 ] . V_94 [ V_137 ] . V_8 ->
V_58 [ 1 ] -> V_68 ) {
V_196 -> V_124 +=
V_1 -> V_139 [ V_11 ] . V_94 [ V_137 ] .
V_8 -> V_58 [ 1 ] -> V_68 -> V_124 ;
V_196 -> V_125 +=
V_1 -> V_139 [ V_11 ] . V_94 [ V_137 ] .
V_8 -> V_58 [ 1 ] -> V_68 -> V_125 ;
}
}
}
}
for ( V_11 = 0 ; V_11 < V_1 -> V_141 ; V_11 ++ ) {
for ( V_137 = 0 ; V_137 < V_1 -> V_142 ; V_137 ++ ) {
if ( V_1 -> V_143 [ V_11 ] . V_32 [ V_137 ] ) {
V_196 -> V_45 +=
V_1 -> V_143 [ V_11 ] . V_32 [ V_137 ] -> V_44 -> V_45 ;
V_196 -> V_46 +=
V_1 -> V_143 [ V_11 ] . V_32 [ V_137 ] -> V_44 -> V_46 ;
}
}
}
}
void
F_222 ( struct V_1 * V_1 , struct V_341 * V_196 )
{
struct V_342 * V_343 ;
T_1 V_344 ;
int V_11 ;
V_343 = & V_1 -> V_196 . V_195 -> V_345 . V_343 ;
V_196 -> V_346 =
V_343 -> V_347 + V_343 -> V_348 +
V_343 -> V_349 + V_343 -> V_350 +
V_343 -> V_351 ;
V_196 -> V_352 = V_343 -> V_353 +
V_343 -> V_354 ;
V_196 -> V_355 = V_343 -> V_356 ;
V_196 -> V_357 = V_343 -> V_358 ;
V_196 -> V_359 = V_343 -> V_360 ;
V_196 -> V_361 = V_343 -> V_362 ;
V_196 -> V_363 = V_343 -> V_349 ;
V_196 -> V_364 = V_343 -> V_347 ;
V_196 -> V_365 = V_343 -> V_348 ;
V_344 = F_223 ( & V_1 -> V_66 ) ;
for ( V_11 = 0 ; V_344 ; V_11 ++ ) {
if ( V_344 & 1 ) {
V_196 -> V_366 +=
V_1 -> V_196 . V_195 ->
V_345 . V_367 [ V_11 ] . V_368 ;
break;
}
V_344 >>= 1 ;
}
}
static void
F_224 ( struct V_1 * V_1 )
{
T_1 V_54 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( V_1 -> V_225 & V_226 )
V_54 = V_1 -> V_227 [ V_228 ] . V_21 ;
else
V_54 = V_1 -> V_23 -> V_54 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_225 ( V_54 ) ;
}
static int
F_226 ( struct V_1 * V_1 , struct V_19 * V_20 )
{
int V_222 ;
if ( F_227 ( V_20 ) ) {
V_222 = F_228 ( V_20 , 0 , 0 , V_84 ) ;
if ( V_222 ) {
F_30 ( V_1 , V_369 ) ;
return V_222 ;
}
}
if ( V_20 -> V_100 == F_70 ( V_370 ) ) {
struct V_371 * V_372 = F_229 ( V_20 ) ;
V_372 -> V_373 = 0 ;
V_372 -> V_374 = 0 ;
F_230 ( V_20 ) -> V_374 =
~ F_231 ( V_372 -> V_375 , V_372 -> V_376 , 0 ,
V_377 , 0 ) ;
F_30 ( V_1 , V_378 ) ;
} else {
struct V_379 * V_380 = F_232 ( V_20 ) ;
V_380 -> V_381 = 0 ;
F_230 ( V_20 ) -> V_374 =
~ F_233 ( & V_380 -> V_375 , & V_380 -> V_376 , 0 ,
V_377 , 0 ) ;
F_30 ( V_1 , V_382 ) ;
}
return 0 ;
}
static void
F_234 ( struct V_1 * V_1 )
{
int V_383 ;
V_383 = F_235 ( ( T_4 ) F_236 () ,
( T_4 ) ( V_384 * V_187 ) ) ;
if ( ! ( V_1 -> V_225 & V_226 ) )
V_383 = 1 ;
V_1 -> V_144 = 1 ;
V_1 -> V_141 = 1 ;
V_1 -> V_146 = V_383 ;
V_1 -> V_142 = V_385 ;
}
static void
F_237 ( struct V_1 * V_1 , int V_386 , int V_387 )
{
V_1 -> V_142 = 1 ;
if ( ( V_386 >= ( V_1 -> V_141 * V_1 -> V_142 ) +
V_388 + V_243 ) &&
( V_1 -> V_225 & V_226 ) ) {
V_1 -> V_146 = V_386 -
( V_1 -> V_141 * V_1 -> V_142 ) -
V_243 ;
} else
V_1 -> V_146 = 1 ;
}
static int
F_238 ( struct V_1 * V_1 )
{
unsigned long V_40 ;
int V_222 = 0 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_186 ( & V_1 -> V_152 . V_155 ) ;
F_239 ( & V_1 -> V_66 . V_261 , V_279 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_240 ( & V_1 -> V_152 . V_155 ,
F_116 ( V_389 ) ) ;
V_222 = V_1 -> V_152 . V_153 ;
return V_222 ;
}
static int
F_241 ( struct V_1 * V_1 )
{
int V_222 = 0 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_186 ( & V_1 -> V_152 . V_155 ) ;
V_1 -> V_152 . V_153 = V_390 ;
F_242 ( & V_1 -> V_66 . V_261 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_240 ( & V_1 -> V_152 . V_155 ,
F_116 ( V_389 ) ) ;
V_222 = V_1 -> V_152 . V_153 ;
return V_222 ;
}
static void
F_243 ( struct V_1 * V_1 , struct V_253 * V_254 ,
T_1 V_391 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_391 ; V_11 ++ )
F_134 ( V_1 , & V_254 [ V_11 ] . V_258 . V_210 ) ;
}
static int
F_244 ( struct V_1 * V_1 , struct V_253 * V_254 ,
T_1 V_391 )
{
int V_11 , V_222 ;
for ( V_11 = 0 ; V_11 < V_391 ; V_11 ++ ) {
V_222 = F_138 ( V_1 , & V_254 [ V_11 ] . V_258 . V_210 ) ;
if ( V_222 )
goto V_221;
}
return 0 ;
V_221:
F_243 ( V_1 , V_254 , V_391 ) ;
return V_222 ;
}
static void
F_245 ( struct V_1 * V_1 )
{
int V_11 , V_336 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( ! ( V_1 -> V_225 & V_226 ) ) {
F_81 ( & V_1 -> V_134 , V_40 ) ;
return;
}
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_1 -> V_227 )
return;
V_1 -> V_227 =
F_139 ( V_1 -> V_392 , sizeof( struct V_393 ) , V_219 ) ;
if ( ! V_1 -> V_227 )
goto V_394;
for ( V_11 = 0 ; V_11 < V_1 -> V_392 ; V_11 ++ )
V_1 -> V_227 [ V_11 ] . V_395 = V_11 ;
V_336 = F_246 ( V_1 -> V_23 , V_1 -> V_227 , V_1 -> V_392 ) ;
if ( V_336 > 0 ) {
F_247 ( L_10 ,
V_336 , V_1 -> V_392 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_237 ( V_1 , ( V_336 - V_243 ) / 2 ,
( V_336 - V_243 ) / 2 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_1 -> V_392 = V_396 + V_397 +
V_243 ;
if ( V_1 -> V_392 > V_336 )
goto V_394;
V_336 = F_246 ( V_1 -> V_23 , V_1 -> V_227 ,
V_1 -> V_392 ) ;
if ( V_336 )
goto V_394;
} else if ( V_336 < 0 )
goto V_394;
F_248 ( V_1 -> V_23 , 0 ) ;
return;
V_394:
F_247 ( L_11 ) ;
F_137 ( V_1 -> V_227 ) ;
V_1 -> V_227 = NULL ;
V_1 -> V_392 = 0 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_1 -> V_225 &= ~ V_226 ;
F_234 ( V_1 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static void
F_249 ( struct V_1 * V_1 )
{
T_1 V_225 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_225 = V_1 -> V_225 ;
if ( V_1 -> V_225 & V_226 )
V_1 -> V_225 &= ~ V_226 ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_225 & V_226 ) {
F_250 ( V_1 -> V_23 ) ;
F_137 ( V_1 -> V_227 ) ;
V_1 -> V_227 = NULL ;
}
}
static int
F_251 ( struct V_47 * V_48 )
{
int V_222 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_398 V_399 ;
int V_64 ;
unsigned long V_40 ;
F_2 ( & V_1 -> V_400 ) ;
V_222 = F_190 ( V_1 , 0 ) ;
if ( V_222 )
goto V_221;
V_222 = F_202 ( V_1 , 0 ) ;
if ( V_222 )
goto V_401;
V_399 . V_402 = 0 ;
V_399 . V_403 = 0 ;
V_64 = V_404 + V_405 + V_1 -> V_48 -> V_64 + V_406 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_253 ( & V_1 -> V_66 . V_67 , V_64 , NULL ) ;
F_254 ( & V_1 -> V_66 . V_67 , & V_399 , NULL ) ;
F_255 ( & V_1 -> V_66 . V_67 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_216 ( V_1 ) ;
F_218 ( V_1 , 0 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_213 ( V_1 , V_48 -> V_151 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_172 ( V_1 ) ;
F_4 ( & V_1 -> V_400 ) ;
return 0 ;
V_401:
F_185 ( V_1 , 0 ) ;
V_221:
F_4 ( & V_1 -> V_400 ) ;
return V_222 ;
}
static int
F_256 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
F_2 ( & V_1 -> V_400 ) ;
F_173 ( V_1 ) ;
F_186 ( & V_1 -> V_152 . V_158 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_257 ( & V_1 -> V_66 . V_67 , V_279 ,
F_98 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_188 ( & V_1 -> V_152 . V_158 ) ;
F_185 ( V_1 , 0 ) ;
F_199 ( V_1 , 0 ) ;
F_224 ( V_1 ) ;
F_4 ( & V_1 -> V_400 ) ;
return 0 ;
}
static int
F_258 ( struct V_1 * V_1 , struct V_31 * V_32 ,
struct V_19 * V_20 , struct V_407 * V_408 )
{
T_7 V_40 = 0 ;
T_1 V_409 ;
T_7 V_128 = 0 ;
if ( F_259 ( V_20 ) ) {
V_128 = ( T_7 ) F_260 ( V_20 ) ;
V_40 |= ( V_410 | V_411 ) ;
}
if ( F_19 ( V_164 , & V_1 -> V_136 ) ) {
V_128 = ( ( V_32 -> V_412 & 0x7 ) << V_413 )
| ( V_128 & 0x1fff ) ;
V_40 |= ( V_410 | V_411 ) ;
}
V_408 -> V_414 . V_415 . V_128 = F_70 ( V_128 ) ;
if ( F_261 ( V_20 ) ) {
V_409 = F_15 ( V_20 ) -> V_409 ;
if ( F_49 ( V_409 > V_1 -> V_48 -> V_64 ) ) {
F_30 ( V_1 , V_416 ) ;
return - V_417 ;
}
if ( F_49 ( ( V_409 + F_262 ( V_20 ) +
F_263 ( V_20 ) ) >= V_20 -> V_43 ) ) {
V_408 -> V_414 . V_415 . V_418 =
F_264 ( V_419 ) ;
V_408 -> V_414 . V_415 . V_420 = 0 ;
F_30 ( V_1 , V_421 ) ;
} else {
V_408 -> V_414 . V_415 . V_418 =
F_264 ( V_422 ) ;
V_408 -> V_414 . V_415 . V_420 = F_70 ( V_409 ) ;
}
if ( F_226 ( V_1 , V_20 ) ) {
F_30 ( V_1 , V_423 ) ;
return - V_417 ;
}
V_40 |= ( V_424 | V_425 ) ;
V_408 -> V_414 . V_415 . V_426 =
F_70 ( F_265 (
F_263 ( V_20 ) >> 2 , F_262 ( V_20 ) ) ) ;
} else {
V_408 -> V_414 . V_415 . V_418 = F_264 ( V_419 ) ;
V_408 -> V_414 . V_415 . V_420 = 0 ;
if ( F_49 ( V_20 -> V_43 > ( V_1 -> V_48 -> V_64 + V_404 ) ) ) {
F_30 ( V_1 , V_427 ) ;
return - V_417 ;
}
if ( V_20 -> V_122 == V_428 ) {
T_6 V_429 = 0 ;
if ( V_20 -> V_100 == F_264 ( V_370 ) )
V_429 = F_229 ( V_20 ) -> V_100 ;
#ifdef F_266
else if ( V_20 -> V_100 ==
F_264 ( V_430 ) ) {
V_429 = F_232 ( V_20 ) -> V_431 ;
}
#endif
if ( V_429 == V_377 ) {
V_40 |= V_425 ;
V_408 -> V_414 . V_415 . V_426 =
F_70 ( F_265
( 0 , F_262 ( V_20 ) ) ) ;
F_30 ( V_1 , V_432 ) ;
if ( F_49 ( F_11 ( V_20 ) <
F_262 ( V_20 ) +
F_263 ( V_20 ) ) ) {
F_30 ( V_1 , V_433 ) ;
return - V_417 ;
}
} else if ( V_429 == V_434 ) {
V_40 |= V_435 ;
V_408 -> V_414 . V_415 . V_426 =
F_70 ( F_265
( 0 , F_262 ( V_20 ) ) ) ;
F_30 ( V_1 , V_436 ) ;
if ( F_49 ( F_11 ( V_20 ) <
F_262 ( V_20 ) +
sizeof( struct V_437 ) ) ) {
F_30 ( V_1 , V_438 ) ;
return - V_417 ;
}
} else {
F_30 ( V_1 , V_439 ) ;
return - V_417 ;
}
} else
V_408 -> V_414 . V_415 . V_426 = 0 ;
}
V_408 -> V_414 . V_415 . V_40 = F_70 ( V_40 ) ;
V_408 -> V_414 . V_415 . V_440 = F_267 ( V_20 -> V_43 ) ;
return 0 ;
}
static T_8
F_268 ( struct V_19 * V_20 , struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
T_1 V_171 = 0 ;
struct V_31 * V_32 = NULL ;
struct V_15 * V_16 , * V_18 , * V_441 ;
T_1 V_77 , V_12 , V_442 ;
T_1 V_35 , V_25 , V_43 ;
int V_11 ;
T_3 V_26 ;
struct V_407 * V_408 ;
V_43 = F_11 ( V_20 ) ;
if ( F_49 ( V_20 -> V_43 <= V_404 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_443 ) ;
return V_444 ;
}
if ( F_49 ( V_43 > V_445 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_446 ) ;
return V_444 ;
}
if ( F_49 ( V_43 == 0 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_446 ) ;
return V_444 ;
}
V_32 = V_1 -> V_143 [ 0 ] . V_32 [ V_171 ] ;
V_12 = V_32 -> V_12 ;
V_77 = V_32 -> V_83 ;
V_16 = V_32 -> V_16 ;
if ( F_49 ( ! F_19 ( V_39 , & V_32 -> V_40 ) ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_447 ) ;
return V_444 ;
}
V_25 = 1 + F_15 ( V_20 ) -> V_97 ;
V_35 = F_23 ( V_25 ) ;
if ( F_49 ( V_25 > V_448 ) ) {
F_269 ( V_20 ) ;
F_30 ( V_1 , V_449 ) ;
return V_444 ;
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
F_30 ( V_1 , V_173 ) ;
}
F_52 () ;
if ( F_31 ( V_35 > F_28 ( V_32 , V_12 ) ) ) {
F_30 ( V_1 , V_173 ) ;
return V_450 ;
} else {
F_29 ( V_48 ) ;
F_30 ( V_1 , V_52 ) ;
}
}
V_408 = & ( (struct V_407 * ) V_32 -> V_13 ) [ V_77 ] ;
V_441 = & V_16 [ V_77 ] ;
if ( F_258 ( V_1 , V_32 , V_20 , V_408 ) ) {
F_269 ( V_20 ) ;
return V_444 ;
}
V_408 -> V_414 . V_415 . V_451 = 0 ;
V_408 -> V_414 . V_415 . V_452 = V_25 ;
V_441 -> V_20 = V_20 ;
V_441 -> V_22 = 0 ;
V_18 = V_441 ;
V_26 = F_56 ( & V_1 -> V_23 -> V_24 , V_20 -> V_55 ,
V_43 , V_27 ) ;
F_51 ( V_26 , & V_408 -> V_21 [ 0 ] . V_88 ) ;
V_408 -> V_21 [ 0 ] . V_95 = F_70 ( V_43 ) ;
F_12 ( & V_18 -> V_25 [ 0 ] , V_26 , V_26 ) ;
V_441 -> V_22 ++ ;
for ( V_11 = 0 , V_442 = 0 ; V_11 < V_25 - 1 ; V_11 ++ ) {
const struct V_453 * V_454 = & F_15 ( V_20 ) -> V_29 [ V_11 ] ;
T_7 V_30 = F_271 ( V_454 ) ;
if ( F_49 ( V_30 == 0 ) ) {
F_8 ( V_1 , V_16 , V_12 ,
V_32 -> V_83 ) ;
F_269 ( V_20 ) ;
F_30 ( V_1 , V_455 ) ;
return V_444 ;
}
V_43 += V_30 ;
V_442 ++ ;
if ( V_442 == V_28 ) {
V_442 = 0 ;
F_13 ( V_77 , V_12 ) ;
V_408 = & ( (struct V_407 * ) V_32 -> V_13 ) [ V_77 ] ;
V_408 -> V_414 . V_456 . V_418 =
F_264 ( V_457 ) ;
V_18 = & V_16 [ V_77 ] ;
}
V_26 = F_272 ( & V_1 -> V_23 -> V_24 , V_454 ,
0 , V_30 , V_27 ) ;
F_51 ( V_26 , & V_408 -> V_21 [ V_442 ] . V_88 ) ;
V_408 -> V_21 [ V_442 ] . V_95 = F_70 ( V_30 ) ;
F_12 ( & V_18 -> V_25 [ V_442 ] , V_26 ,
V_26 ) ;
V_441 -> V_22 ++ ;
}
if ( F_49 ( V_43 != V_20 -> V_43 ) ) {
F_8 ( V_1 , V_16 , V_12 , V_32 -> V_83 ) ;
F_269 ( V_20 ) ;
F_30 ( V_1 , V_458 ) ;
return V_444 ;
}
F_13 ( V_77 , V_12 ) ;
V_32 -> V_83 = V_77 ;
F_52 () ;
if ( F_49 ( ! F_19 ( V_39 , & V_32 -> V_40 ) ) )
return V_444 ;
F_273 ( V_32 ) ;
F_52 () ;
return V_444 ;
}
static struct V_341 *
F_274 ( struct V_47 * V_48 , struct V_341 * V_196 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_221 ( V_1 , V_196 ) ;
F_222 ( V_1 , V_196 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_196 ;
}
void
F_275 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
T_1 V_459 , V_460 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_459 = V_460 = 0 ;
if ( V_48 -> V_40 & V_461 ) {
if ( ! ( V_1 -> V_225 & V_462 ) ) {
V_459 = V_463 ;
V_460 = V_463 ;
V_1 -> V_225 |= V_462 ;
}
} else {
if ( V_1 -> V_225 & V_462 ) {
V_459 = ~ V_463 ;
V_460 = V_463 ;
V_1 -> V_225 &= ~ V_462 ;
}
}
if ( V_48 -> V_40 & V_464 ) {
if ( ! ( V_1 -> V_225 & V_465 ) ) {
V_459 |= V_466 ;
V_460 |= V_466 ;
V_1 -> V_225 |= V_465 ;
}
} else {
if ( V_1 -> V_225 & V_465 ) {
V_459 &= ~ V_466 ;
V_460 |= V_466 ;
V_1 -> V_225 &= ~ V_465 ;
}
}
if ( V_1 -> V_139 [ 0 ] . V_145 == NULL )
goto V_467;
F_276 ( V_1 -> V_139 [ 0 ] . V_145 , V_459 , V_460 , NULL ) ;
if ( ! F_277 ( V_48 ) ) {
T_6 * V_468 ;
int V_469 = F_278 ( V_48 ) ;
V_468 =
F_141 ( ( V_469 + 1 ) * V_271 ,
V_84 ) ;
if ( ! V_468 )
goto V_467;
memcpy ( & V_468 [ 0 ] , & V_338 [ 0 ] , V_271 ) ;
F_176 ( V_48 , V_468 ) ;
F_279 ( V_1 -> V_139 [ 0 ] . V_145 , V_469 + 1 ,
V_468 , NULL ) ;
F_137 ( V_468 ) ;
}
V_467:
F_81 ( & V_1 -> V_134 , V_40 ) ;
}
static int
F_280 ( struct V_47 * V_48 , void * V_335 )
{
int V_222 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_470 * V_471 = (struct V_470 * ) V_335 ;
unsigned long V_40 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
V_222 = F_213 ( V_1 , V_471 -> V_472 ) ;
if ( ! V_222 )
memcpy ( V_48 -> V_151 , V_471 -> V_472 , V_48 -> V_150 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
return V_222 ;
}
static int
F_281 ( struct V_1 * V_1 , int V_64 )
{
unsigned long V_40 ;
F_186 ( & V_1 -> V_152 . V_203 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_253 ( & V_1 -> V_66 . V_67 , V_64 , F_132 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_188 ( & V_1 -> V_152 . V_203 ) ;
return V_1 -> V_152 . V_202 ;
}
static int
F_282 ( struct V_47 * V_48 , int V_473 )
{
int V_222 , V_64 = V_48 -> V_64 ;
struct V_1 * V_1 = F_252 ( V_48 ) ;
if ( V_473 + V_404 < V_474 || V_473 > V_475 )
return - V_417 ;
F_2 ( & V_1 -> V_400 ) ;
V_48 -> V_64 = V_473 ;
V_64 = V_404 + V_405 + V_473 + V_406 ;
V_222 = F_281 ( V_1 , V_64 ) ;
if ( V_222 )
V_222 = - V_476 ;
F_4 ( & V_1 -> V_400 ) ;
return V_222 ;
}
static int
F_283 ( struct V_47 * V_48 , T_9 V_429 , T_7 V_340 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
if ( ! V_1 -> V_139 [ 0 ] . V_145 )
return 0 ;
F_2 ( & V_1 -> V_400 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_220 ( V_1 -> V_139 [ 0 ] . V_145 , V_340 ) ;
F_89 ( V_340 , V_1 -> V_477 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_4 ( & V_1 -> V_400 ) ;
return 0 ;
}
static int
F_284 ( struct V_47 * V_48 , T_9 V_429 , T_7 V_340 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
unsigned long V_40 ;
if ( ! V_1 -> V_139 [ 0 ] . V_145 )
return 0 ;
F_2 ( & V_1 -> V_400 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_34 ( V_340 , V_1 -> V_477 ) ;
F_285 ( V_1 -> V_139 [ 0 ] . V_145 , V_340 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_4 ( & V_1 -> V_400 ) ;
return 0 ;
}
static void
F_286 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_252 ( V_48 ) ;
struct V_138 * V_139 ;
struct V_93 * V_94 ;
T_1 V_478 ;
int V_11 , V_137 ;
if ( ! ( V_1 -> V_225 & V_226 ) ) {
F_287 ( & V_1 -> V_66 , V_478 ) ;
F_85 ( V_1 -> V_23 -> V_54 , V_48 ) ;
F_288 ( & V_1 -> V_66 , V_478 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_1 -> V_144 ; V_11 ++ ) {
V_139 = & V_1 -> V_139 [ V_11 ] ;
if ( ! V_139 -> V_145 )
continue;
for ( V_137 = 0 ; V_137 < V_1 -> V_146 ; V_137 ++ ) {
V_94 = & V_139 -> V_94 [ V_137 ] ;
if ( V_94 -> V_8 )
F_75 ( V_1 ,
V_94 -> V_8 ) ;
}
}
}
}
static void
F_289 ( struct V_1 * V_1 , bool V_479 )
{
struct V_47 * V_48 = V_1 -> V_48 ;
V_48 -> V_480 = V_481 | V_117 |
V_482 | F_266 |
V_483 | V_484 | V_485 ;
V_48 -> V_486 = V_481 | V_487 |
V_482 | F_266 |
V_483 | V_484 ;
V_48 -> V_116 |= V_48 -> V_480 |
V_488 | V_489 ;
if ( V_479 )
V_48 -> V_116 |= V_487 ;
V_48 -> V_490 = V_1 -> V_491 ;
V_48 -> V_492 = V_1 -> V_491 + V_1 -> V_493 - 1 ;
V_48 -> V_494 = & V_495 ;
F_290 ( V_48 ) ;
}
static int
F_291 ( struct V_1 * V_1 ,
struct V_496 * V_497 , struct V_47 * V_48 )
{
unsigned long V_40 ;
F_292 ( V_48 , & V_497 -> V_24 ) ;
F_293 ( V_497 , V_48 ) ;
V_1 -> V_48 = V_48 ;
V_1 -> V_23 = V_497 ;
V_1 -> V_491 = F_294 ( V_497 , 0 ) ;
V_1 -> V_493 = F_295 ( V_497 , 0 ) ;
V_1 -> V_498 = F_296 ( V_1 -> V_491 , V_1 -> V_493 ) ;
if ( ! V_1 -> V_498 ) {
F_297 ( & V_497 -> V_24 , L_12 ) ;
F_293 ( V_497 , NULL ) ;
return - V_220 ;
}
F_298 ( L_13 , V_1 -> V_498 ,
( unsigned long long ) V_1 -> V_493 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( ! V_499 )
V_1 -> V_225 = V_226 ;
V_1 -> V_225 |= V_266 ;
F_234 ( V_1 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_1 -> V_392 = ( V_1 -> V_141 * V_1 -> V_142 ) +
( V_1 -> V_144 * V_1 -> V_146 ) +
V_243 ;
V_1 -> V_291 = V_500 ;
V_1 -> V_317 = V_501 ;
V_1 -> V_295 = V_502 ;
V_1 -> V_303 = V_503 ;
sprintf ( V_1 -> V_504 , L_14 , V_231 , V_1 -> V_5 ) ;
V_1 -> V_185 = F_299 ( V_1 -> V_504 ) ;
if ( ! V_1 -> V_185 ) {
F_300 ( V_1 -> V_498 ) ;
return - V_220 ;
}
return 0 ;
}
static void
F_301 ( struct V_1 * V_1 )
{
if ( V_1 -> V_185 ) {
F_302 ( V_1 -> V_185 ) ;
F_303 ( V_1 -> V_185 ) ;
V_1 -> V_185 = NULL ;
}
if ( V_1 -> V_498 )
F_300 ( V_1 -> V_498 ) ;
F_293 ( V_1 -> V_23 , NULL ) ;
}
static void
F_304 ( struct V_1 * V_1 )
{
F_305 ( & V_1 -> V_134 ) ;
F_306 ( & V_1 -> V_400 ) ;
F_306 ( & V_2 ) ;
}
static void
F_307 ( struct V_1 * V_1 )
{
F_308 ( & V_1 -> V_400 ) ;
F_308 ( & V_2 ) ;
}
static int
F_309 ( struct V_1 * V_1 ,
struct V_496 * V_497 , bool * V_479 )
{
int V_222 ;
V_222 = F_310 ( V_497 ) ;
if ( V_222 )
return V_222 ;
V_222 = F_311 ( V_497 , V_231 ) ;
if ( V_222 )
goto V_505;
if ( ! F_312 ( & V_497 -> V_24 , F_313 ( 64 ) ) &&
! F_314 ( & V_497 -> V_24 , F_313 ( 64 ) ) ) {
* V_479 = true ;
} else {
V_222 = F_312 ( & V_497 -> V_24 , F_313 ( 32 ) ) ;
if ( V_222 ) {
V_222 = F_314 ( & V_497 -> V_24 ,
F_313 ( 32 ) ) ;
if ( V_222 )
goto V_506;
}
* V_479 = false ;
}
F_315 ( V_497 ) ;
return 0 ;
V_506:
F_316 ( V_497 ) ;
V_505:
F_317 ( V_497 ) ;
return V_222 ;
}
static void
F_318 ( struct V_496 * V_497 )
{
F_316 ( V_497 ) ;
F_317 ( V_497 ) ;
}
static int
F_319 ( struct V_496 * V_497 ,
const struct V_507 * V_508 )
{
bool V_479 ;
int V_222 ;
struct V_1 * V_1 ;
struct V_66 * V_66 ;
struct V_47 * V_48 ;
struct V_509 V_510 ;
unsigned long V_40 ;
F_298 ( L_15 ,
V_497 , V_508 , F_320 ( V_497 -> V_511 ) ) ;
F_2 ( & V_512 ) ;
if ( ! F_321 ( V_497 ) ) {
F_4 ( & V_512 ) ;
F_247 ( L_16 ) ;
return - V_339 ;
}
F_4 ( & V_512 ) ;
V_48 = F_322 ( sizeof( struct V_1 ) ) ;
if ( ! V_48 ) {
V_222 = - V_220 ;
return V_222 ;
}
V_1 = F_252 ( V_48 ) ;
F_304 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( & V_1 -> V_400 ) ;
V_479 = false ;
V_222 = F_309 ( V_1 , V_497 , & V_479 ) ;
if ( V_222 )
goto V_513;
V_222 = F_291 ( V_1 , V_497 , V_48 ) ;
if ( V_222 )
goto V_514;
F_289 ( V_1 , V_479 ) ;
F_99 ( V_48 ) ;
if ( V_515 )
F_323 ( V_1 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_324 ( & V_1 -> V_254 [ 0 ] ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_222 = F_244 ( V_1 , & V_1 -> V_254 [ 0 ] , V_516 ) ;
if ( V_222 )
goto V_517;
V_66 = & V_1 -> V_66 ;
V_510 . V_518 = F_325 ( V_1 -> V_23 -> V_511 ) ;
V_510 . V_519 = F_320 ( V_1 -> V_23 -> V_511 ) ;
V_510 . V_520 = V_1 -> V_23 -> V_521 ;
V_510 . V_522 = V_1 -> V_498 ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_326 ( V_66 , V_1 , & V_510 , & V_1 -> V_254 [ 0 ] ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_1 -> V_196 . V_195 = & V_66 -> V_196 ;
F_245 ( V_1 ) ;
V_222 = F_145 ( V_1 ) ;
if ( V_222 )
goto V_523;
F_171 ( & V_1 -> V_66 . V_261 . V_262 . V_524 , F_158 ,
( ( unsigned long ) V_1 ) ) ;
F_171 ( & V_1 -> V_66 . V_261 . V_262 . V_525 , F_160 ,
( ( unsigned long ) V_1 ) ) ;
F_171 ( & V_1 -> V_66 . V_261 . V_262 . V_526 , F_162 ,
( ( unsigned long ) V_1 ) ) ;
F_171 ( & V_1 -> V_66 . V_261 . V_262 . V_527 , F_164 ,
( ( unsigned long ) V_1 ) ) ;
F_131 ( & V_1 -> V_66 . V_261 . V_262 . V_526 ,
V_200 + F_116 ( V_528 ) ) ;
V_222 = F_241 ( V_1 ) ;
if ( V_222 ) {
F_327 ( L_17 ,
V_222 ) ;
goto V_529;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
if ( F_328 ( V_66 , V_396 + 1 ) ||
F_329 ( V_66 , V_397 + 1 ) ) {
F_237 ( V_1 , F_330 ( V_66 ) -> V_290 - 1 ,
F_330 ( V_66 ) -> V_530 - 1 ) ;
if ( F_328 ( V_66 , V_396 + 1 ) ||
F_329 ( V_66 , V_397 + 1 ) )
V_222 = - V_531 ;
}
F_81 ( & V_1 -> V_134 , V_40 ) ;
if ( V_222 )
goto V_532;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_331 ( & V_1 -> V_66 , & V_1 -> V_533 [ 0 ] ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
V_222 = F_244 ( V_1 , & V_1 -> V_533 [ 0 ] , V_534 ) ;
if ( V_222 ) {
V_222 = - V_531 ;
goto V_532;
}
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_332 ( & V_1 -> V_66 , & V_1 -> V_533 [ 0 ] ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_112 ( & V_66 -> V_67 , & V_1 -> V_149 ) ;
F_90 ( V_1 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_4 ( & V_1 -> V_400 ) ;
V_222 = F_333 ( V_48 ) ;
if ( V_222 ) {
F_327 ( L_18 ) ;
goto V_535;
}
F_89 ( V_536 , & V_1 -> V_136 ) ;
return 0 ;
V_529:
F_4 ( & V_1 -> V_400 ) ;
return 0 ;
V_535:
F_2 ( & V_1 -> V_400 ) ;
F_243 ( V_1 , & V_1 -> V_533 [ 0 ] , V_534 ) ;
V_532:
F_238 ( V_1 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_524 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_527 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_525 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_334 ( V_66 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_142 ( V_1 ) ;
F_249 ( V_1 ) ;
V_523:
F_243 ( V_1 , & V_1 -> V_254 [ 0 ] , V_516 ) ;
V_517:
F_137 ( V_1 -> V_537 ) ;
F_335 ( V_1 ) ;
F_301 ( V_1 ) ;
V_514:
F_318 ( V_497 ) ;
V_513:
F_4 ( & V_1 -> V_400 ) ;
F_5 ( V_1 ) ;
F_307 ( V_1 ) ;
F_336 ( V_48 ) ;
return V_222 ;
}
static void
F_337 ( struct V_496 * V_497 )
{
struct V_47 * V_48 = F_338 ( V_497 ) ;
struct V_1 * V_1 ;
struct V_66 * V_66 ;
unsigned long V_40 ;
if ( ! V_48 )
return;
F_298 ( L_19 , V_48 -> V_169 ) ;
V_1 = F_252 ( V_48 ) ;
V_66 = & V_1 -> V_66 ;
if ( F_174 ( V_536 , & V_1 -> V_136 ) )
F_339 ( V_48 ) ;
F_2 ( & V_1 -> V_400 ) ;
F_238 ( V_1 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_524 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_527 ) ;
F_175 ( & V_1 -> V_66 . V_261 . V_262 . V_525 ) ;
F_80 ( & V_1 -> V_134 , V_40 ) ;
F_334 ( V_66 ) ;
F_81 ( & V_1 -> V_134 , V_40 ) ;
F_243 ( V_1 , & V_1 -> V_533 [ 0 ] , V_534 ) ;
F_243 ( V_1 , & V_1 -> V_254 [ 0 ] , V_516 ) ;
F_142 ( V_1 ) ;
F_249 ( V_1 ) ;
F_318 ( V_497 ) ;
F_4 ( & V_1 -> V_400 ) ;
F_5 ( V_1 ) ;
F_307 ( V_1 ) ;
F_137 ( V_1 -> V_537 ) ;
F_335 ( V_1 ) ;
F_301 ( V_1 ) ;
F_336 ( V_48 ) ;
}
static int T_10
F_340 ( void )
{
int V_222 ;
F_298 ( L_20 ,
V_538 ) ;
F_341 ( V_539 ) ;
V_222 = F_342 ( & V_540 ) ;
if ( V_222 < 0 ) {
F_327 ( L_21
L_22 , V_222 ) ;
return V_222 ;
}
return 0 ;
}
static void T_11
F_343 ( void )
{
F_344 ( & V_540 ) ;
F_345 ( V_541 ) ;
}
