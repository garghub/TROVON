static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static struct V_1 * F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_8 ;
F_6 ( & V_9 . V_10 ) ;
if ( ! V_7 -> V_2 ) {
F_7 (tmp, &mtk_aes.dev_list, aes_list) {
V_2 = V_8 ;
break;
}
V_7 -> V_2 = V_2 ;
} else {
V_2 = V_7 -> V_2 ;
}
F_8 ( & V_9 . V_10 ) ;
return V_2 ;
}
static inline T_2 F_9 ( T_2 V_11 )
{
V_11 &= V_12 - 1 ;
return V_11 ? V_12 - V_11 : 0 ;
}
static bool F_10 ( struct V_13 * V_14 , T_2 V_11 ,
struct V_15 * V_16 )
{
int V_17 ;
if ( ! F_11 ( V_11 , V_12 ) )
return false ;
for ( V_17 = 0 ; V_14 ; V_14 = F_12 ( V_14 ) , ++ V_17 ) {
if ( ! F_11 ( V_14 -> V_3 , sizeof( T_1 ) ) )
return false ;
if ( V_11 <= V_14 -> V_18 ) {
if ( ! F_11 ( V_11 , V_12 ) )
return false ;
V_16 -> V_17 = V_17 + 1 ;
V_16 -> V_19 = V_14 -> V_18 - V_11 ;
V_14 -> V_18 = V_11 ;
return true ;
}
if ( ! F_11 ( V_14 -> V_18 , V_12 ) )
return false ;
V_11 -= V_14 -> V_18 ;
}
return false ;
}
static inline void F_13 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
V_21 -> V_24 = ( V_21 -> V_24 & V_25 ) | V_23 -> V_26 ;
}
static inline void F_14 ( const struct V_15 * V_16 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
int V_17 = V_16 -> V_17 ;
if ( ! V_16 -> V_19 )
return;
while ( -- V_17 > 0 && V_14 )
V_14 = F_12 ( V_14 ) ;
if ( ! V_14 )
return;
V_14 -> V_18 += V_16 -> V_19 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_27 * V_28 = V_2 -> V_28 [ V_21 -> V_29 ] ;
struct V_30 * V_31 = NULL , * V_32 = NULL ;
struct V_13 * V_33 = V_21 -> V_34 . V_14 , * V_35 = V_21 -> V_36 . V_14 ;
T_1 V_37 = V_21 -> V_34 . V_38 , V_39 = V_21 -> V_36 . V_38 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_37 ; ++ V_17 , V_33 = F_12 ( V_33 ) ) {
V_31 = V_28 -> V_40 + V_28 -> V_41 ;
V_31 -> V_42 = F_16 ( V_33 -> V_18 ) ;
V_31 -> V_43 = F_17 ( F_18 ( V_33 ) ) ;
if ( V_17 == 0 ) {
V_31 -> V_42 |= V_44 |
F_19 ( V_21 -> V_7 -> V_45 ) ;
V_31 -> V_46 = F_17 ( V_21 -> V_7 -> V_47 ) ;
V_31 -> V_48 = V_21 -> V_7 -> V_48 ;
V_31 -> V_49 = F_17 ( V_21 -> V_7 -> V_50 ) ;
}
if ( ++ V_28 -> V_41 == V_51 )
V_28 -> V_41 = 0 ;
}
V_31 -> V_42 |= V_52 ;
for ( V_17 = 0 ; V_17 < V_39 ; ++ V_17 , V_35 = F_12 ( V_35 ) ) {
V_32 = V_28 -> V_53 + V_28 -> V_54 ;
V_32 -> V_42 = F_16 ( V_35 -> V_18 ) ;
V_32 -> V_43 = F_17 ( F_18 ( V_35 ) ) ;
if ( V_17 == 0 )
V_32 -> V_42 |= V_44 ;
if ( ++ V_28 -> V_54 == V_51 )
V_28 -> V_54 = 0 ;
}
V_32 -> V_42 |= V_52 ;
if ( V_21 -> V_24 & V_55 )
V_32 -> V_42 += V_12 ;
F_20 () ;
F_3 ( V_2 , F_21 ( V_21 -> V_29 ) , F_22 ( V_39 ) ) ;
F_3 ( V_2 , F_23 ( V_21 -> V_29 ) , F_22 ( V_37 ) ) ;
return - V_56 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
F_25 ( V_2 -> V_57 , V_7 -> V_47 , sizeof( V_7 -> V_46 ) ,
V_58 ) ;
F_25 ( V_2 -> V_57 , V_7 -> V_50 , sizeof( V_7 -> V_49 ) ,
V_58 ) ;
if ( V_21 -> V_34 . V_14 == V_21 -> V_36 . V_14 ) {
F_26 ( V_2 -> V_57 , V_21 -> V_34 . V_14 , V_21 -> V_34 . V_17 ,
V_59 ) ;
if ( V_21 -> V_34 . V_14 != & V_21 -> V_60 )
F_14 ( & V_21 -> V_34 ) ;
} else {
F_26 ( V_2 -> V_57 , V_21 -> V_36 . V_14 , V_21 -> V_36 . V_17 ,
V_61 ) ;
if ( V_21 -> V_36 . V_14 != & V_21 -> V_60 )
F_14 ( & V_21 -> V_36 ) ;
F_26 ( V_2 -> V_57 , V_21 -> V_34 . V_14 , V_21 -> V_34 . V_17 ,
V_58 ) ;
if ( V_21 -> V_34 . V_14 != & V_21 -> V_60 )
F_14 ( & V_21 -> V_34 ) ;
}
if ( V_21 -> V_36 . V_14 == & V_21 -> V_60 )
F_27 ( V_21 -> V_62 , F_28 ( V_21 -> V_62 ) ,
V_21 -> V_43 , V_21 -> V_63 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
V_7 -> V_47 = F_30 ( V_2 -> V_57 , & V_7 -> V_46 , sizeof( V_7 -> V_46 ) ,
V_58 ) ;
if ( F_31 ( F_32 ( V_2 -> V_57 , V_7 -> V_47 ) ) )
return - V_64 ;
V_7 -> V_50 = F_30 ( V_2 -> V_57 , & V_7 -> V_49 , sizeof( V_7 -> V_49 ) ,
V_58 ) ;
if ( F_31 ( F_32 ( V_2 -> V_57 , V_7 -> V_50 ) ) )
goto V_65;
if ( V_21 -> V_34 . V_14 == V_21 -> V_36 . V_14 ) {
V_21 -> V_34 . V_38 = F_33 ( V_2 -> V_57 , V_21 -> V_34 . V_14 ,
V_21 -> V_34 . V_17 ,
V_59 ) ;
V_21 -> V_36 . V_38 = V_21 -> V_34 . V_38 ;
if ( F_31 ( ! V_21 -> V_34 . V_38 ) )
goto V_66;
} else {
V_21 -> V_34 . V_38 = F_33 ( V_2 -> V_57 , V_21 -> V_34 . V_14 ,
V_21 -> V_34 . V_17 , V_58 ) ;
if ( F_31 ( ! V_21 -> V_34 . V_38 ) )
goto V_66;
V_21 -> V_36 . V_38 = F_33 ( V_2 -> V_57 , V_21 -> V_36 . V_14 ,
V_21 -> V_36 . V_17 , V_61 ) ;
if ( F_31 ( ! V_21 -> V_36 . V_38 ) ) {
F_26 ( V_2 -> V_57 , V_21 -> V_34 . V_14 , V_21 -> V_34 . V_17 ,
V_58 ) ;
goto V_66;
}
}
return F_15 ( V_2 , V_21 ) ;
V_66:
F_25 ( V_2 -> V_57 , V_7 -> V_50 , sizeof( V_7 -> V_49 ) ,
V_58 ) ;
V_65:
F_25 ( V_2 -> V_57 , V_7 -> V_47 , sizeof( V_7 -> V_46 ) ,
V_58 ) ;
return - V_64 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_20 * V_21 ,
T_2 V_11 )
{
struct V_67 * V_68 = F_35 ( V_21 -> V_69 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
V_7 -> V_48 = V_70 | F_17 ( V_11 ) ;
V_7 -> V_46 . V_31 [ 0 ] = V_71 | F_17 ( V_11 ) ;
V_7 -> V_46 . V_31 [ 1 ] = V_72 ;
if ( V_21 -> V_24 & V_73 )
V_7 -> V_49 . V_74 [ 0 ] = V_75 ;
else
V_7 -> V_49 . V_74 [ 0 ] = V_76 ;
if ( V_7 -> V_77 == F_36 ( V_78 ) )
V_7 -> V_49 . V_74 [ 0 ] |= V_79 ;
else if ( V_7 -> V_77 == F_36 ( V_80 ) )
V_7 -> V_49 . V_74 [ 0 ] |= V_81 ;
else
V_7 -> V_49 . V_74 [ 0 ] |= V_82 ;
if ( V_21 -> V_24 & V_83 ) {
const T_1 * V_84 = ( const T_1 * ) V_68 -> V_85 ;
T_1 * V_86 = V_7 -> V_49 . V_87 + V_7 -> V_77 ;
int V_88 ;
V_7 -> V_49 . V_74 [ 0 ] |= F_37 ( V_7 -> V_77 +
F_36 ( V_12 ) ) ;
V_7 -> V_49 . V_74 [ 1 ] = V_89 | V_90 ;
for ( V_88 = 0 ; V_88 < F_36 ( V_12 ) ; V_88 ++ )
V_86 [ V_88 ] = F_17 ( V_84 [ V_88 ] ) ;
V_7 -> V_46 . V_31 [ 2 ] = V_91 ;
V_7 -> V_45 = V_92 ;
} else if ( V_21 -> V_24 & V_93 ) {
V_7 -> V_49 . V_74 [ 0 ] |= F_37 ( V_7 -> V_77 ) ;
V_7 -> V_49 . V_74 [ 1 ] = V_94 ;
V_7 -> V_45 = V_95 ;
} else if ( V_21 -> V_24 & V_96 ) {
V_7 -> V_49 . V_74 [ 0 ] |= F_37 ( V_7 -> V_77 +
F_36 ( V_12 ) ) ;
V_7 -> V_49 . V_74 [ 1 ] = V_97 | V_90 ;
V_7 -> V_46 . V_31 [ 2 ] = V_91 ;
V_7 -> V_45 = V_98 ;
}
}
static int V_15 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_13 * V_34 , struct V_13 * V_36 ,
T_2 V_11 )
{
T_2 V_99 = 0 ;
bool V_100 , V_101 ;
V_21 -> V_63 = V_11 ;
V_21 -> V_34 . V_14 = V_34 ;
V_21 -> V_36 . V_14 = V_36 ;
V_21 -> V_62 = V_36 ;
V_100 = F_10 ( V_34 , V_11 , & V_21 -> V_34 ) ;
if ( V_34 == V_36 )
V_101 = V_100 ;
else
V_101 = F_10 ( V_36 , V_11 , & V_21 -> V_36 ) ;
if ( ! V_100 || ! V_101 ) {
V_99 = F_9 ( V_11 ) ;
if ( V_11 + V_99 > V_102 )
return - V_103 ;
if ( ! V_100 ) {
F_38 ( V_34 , F_28 ( V_34 ) , V_21 -> V_43 , V_11 ) ;
V_21 -> V_34 . V_14 = & V_21 -> V_60 ;
V_21 -> V_34 . V_17 = 1 ;
V_21 -> V_34 . V_19 = 0 ;
}
if ( ! V_101 ) {
V_21 -> V_36 . V_14 = & V_21 -> V_60 ;
V_21 -> V_36 . V_17 = 1 ;
V_21 -> V_36 . V_19 = 0 ;
}
F_39 ( & V_21 -> V_60 , 1 ) ;
F_40 ( & V_21 -> V_60 , V_21 -> V_43 , V_11 + V_99 ) ;
}
F_34 ( V_2 , V_21 , V_11 + V_99 ) ;
return F_29 ( V_2 , V_21 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_3 V_29 ,
struct V_104 * V_105 )
{
struct V_20 * V_21 = V_2 -> V_21 [ V_29 ] ;
struct V_104 * V_69 , * V_106 ;
struct V_6 * V_7 ;
unsigned long V_24 ;
int V_107 = 0 ;
F_42 ( & V_21 -> V_10 , V_24 ) ;
if ( V_105 )
V_107 = F_43 ( & V_21 -> V_108 , V_105 ) ;
if ( V_21 -> V_24 & V_25 ) {
F_44 ( & V_21 -> V_10 , V_24 ) ;
return V_107 ;
}
V_106 = F_45 ( & V_21 -> V_108 ) ;
V_69 = F_46 ( & V_21 -> V_108 ) ;
if ( V_69 )
V_21 -> V_24 |= V_25 ;
F_44 ( & V_21 -> V_10 , V_24 ) ;
if ( ! V_69 )
return V_107 ;
if ( V_106 )
V_106 -> V_109 ( V_106 , - V_56 ) ;
V_7 = F_47 ( V_69 -> V_49 ) ;
V_21 -> V_69 = V_69 ;
V_21 -> V_7 = V_7 ;
return V_7 -> V_110 ( V_2 , V_21 ) ;
}
static int F_48 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
V_21 -> V_24 &= ~ V_25 ;
V_21 -> V_69 -> V_109 ( V_21 -> V_69 , 0 ) ;
return F_41 ( V_2 , V_21 -> V_29 , NULL ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_67 * V_68 = F_35 ( V_21 -> V_69 ) ;
struct V_22 * V_23 = F_50 ( V_68 ) ;
F_13 ( V_21 , V_23 ) ;
V_21 -> V_111 = F_48 ;
return V_15 ( V_2 , V_21 , V_68 -> V_34 , V_68 -> V_36 , V_68 -> V_112 ) ;
}
static inline struct V_113 *
F_51 ( struct V_6 * V_7 )
{
return F_52 ( V_7 , struct V_113 , V_4 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_113 * V_114 = F_51 ( V_7 ) ;
struct V_67 * V_68 = F_35 ( V_21 -> V_69 ) ;
struct V_13 * V_34 , * V_36 ;
int V_88 ;
T_1 V_110 , V_115 , V_116 , V_117 , * V_86 ;
T_2 V_118 ;
bool V_119 = false ;
V_114 -> V_3 += V_21 -> V_63 ;
if ( V_114 -> V_3 >= V_68 -> V_112 )
return F_48 ( V_2 , V_21 ) ;
V_118 = V_68 -> V_112 - V_114 -> V_3 ;
V_117 = F_54 ( V_118 , V_12 ) ;
V_116 = F_55 ( V_114 -> V_84 [ 3 ] ) ;
V_110 = V_116 ;
V_115 = V_110 + V_117 - 1 ;
if ( V_115 < V_110 ) {
V_116 |= 0xffffffff ;
V_118 = V_12 * - V_110 ;
V_119 = true ;
}
V_34 = F_56 ( V_114 -> V_34 , V_68 -> V_34 , V_114 -> V_3 ) ;
V_36 = ( ( V_68 -> V_34 == V_68 -> V_36 ) ? V_34 :
F_56 ( V_114 -> V_36 , V_68 -> V_36 , V_114 -> V_3 ) ) ;
V_86 = V_7 -> V_49 . V_87 + V_7 -> V_77 ;
for ( V_88 = 0 ; V_88 < F_36 ( V_12 ) ; V_88 ++ )
V_86 [ V_88 ] = F_17 ( V_114 -> V_84 [ V_88 ] ) ;
if ( F_31 ( V_119 ) ) {
V_114 -> V_84 [ 3 ] = F_57 ( V_116 ) ;
F_58 ( ( T_3 * ) V_114 -> V_84 , V_12 ) ;
}
V_21 -> V_111 = F_53 ;
return V_15 ( V_2 , V_21 , V_34 , V_36 , V_118 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_113 * V_114 = F_51 ( V_21 -> V_7 ) ;
struct V_67 * V_68 = F_35 ( V_21 -> V_69 ) ;
struct V_22 * V_23 = F_50 ( V_68 ) ;
F_13 ( V_21 , V_23 ) ;
memcpy ( V_114 -> V_84 , V_68 -> V_85 , V_12 ) ;
V_114 -> V_3 = 0 ;
V_21 -> V_63 = 0 ;
return F_53 ( V_2 , V_21 ) ;
}
static int F_60 ( struct V_120 * V_49 ,
const T_3 * V_121 , T_1 V_77 )
{
struct V_6 * V_7 = F_61 ( V_49 ) ;
const T_1 * V_122 = ( const T_1 * ) V_121 ;
T_1 * V_123 = V_7 -> V_49 . V_87 ;
int V_88 ;
if ( V_77 != V_78 &&
V_77 != V_124 &&
V_77 != V_80 ) {
F_62 ( V_49 , V_125 ) ;
return - V_64 ;
}
V_7 -> V_77 = F_36 ( V_77 ) ;
for ( V_88 = 0 ; V_88 < V_7 -> V_77 ; V_88 ++ )
V_123 [ V_88 ] = F_17 ( V_122 [ V_88 ] ) ;
return 0 ;
}
static int F_63 ( struct V_67 * V_68 , T_4 V_26 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 ;
V_7 = F_61 ( F_64 ( V_68 ) ) ;
V_23 = F_50 ( V_68 ) ;
V_23 -> V_26 = V_26 ;
return F_41 ( V_7 -> V_2 , ! ( V_26 & V_73 ) ,
& V_68 -> V_4 ) ;
}
static int F_65 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_73 | V_93 ) ;
}
static int F_66 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_93 ) ;
}
static int F_67 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_73 | V_83 ) ;
}
static int F_68 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_83 ) ;
}
static int F_69 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_73 | V_96 ) ;
}
static int F_70 ( struct V_67 * V_68 )
{
return F_63 ( V_68 , V_96 ) ;
}
static int F_71 ( struct V_126 * V_49 )
{
struct V_127 * V_7 = F_47 ( V_49 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_72 ( L_1 ) ;
return - V_128 ;
}
V_49 -> V_129 . V_130 = sizeof( struct V_22 ) ;
V_7 -> V_4 . V_110 = F_49 ;
return 0 ;
}
static int F_73 ( struct V_126 * V_49 )
{
struct V_127 * V_7 = F_47 ( V_49 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_72 ( L_1 ) ;
return - V_128 ;
}
V_49 -> V_129 . V_130 = sizeof( struct V_22 ) ;
V_7 -> V_4 . V_110 = F_59 ;
return 0 ;
}
static inline struct V_131 *
F_74 ( struct V_6 * V_7 )
{
return F_52 ( V_7 , struct V_131 , V_4 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_2 V_11 )
{
struct V_132 * V_68 = F_76 ( V_21 -> V_69 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_131 * V_133 = F_74 ( V_7 ) ;
const T_1 * V_84 = ( const T_1 * ) V_68 -> V_84 ;
T_1 * V_86 = V_7 -> V_49 . V_87 + V_7 -> V_77 +
F_36 ( V_12 ) ;
T_1 V_134 = F_77 ( F_78 ( V_68 ) ) ;
int V_88 ;
V_7 -> V_48 = V_70 | V_11 ;
V_7 -> V_46 . V_31 [ 0 ] = V_135 | F_17 ( V_68 -> V_136 ) ;
V_7 -> V_46 . V_31 [ 1 ] = V_137 | F_17 ( V_68 -> V_136 ) ;
V_7 -> V_46 . V_31 [ 2 ] = V_138 ;
V_7 -> V_46 . V_31 [ 3 ] = V_139 | F_17 ( V_133 -> V_140 ) ;
if ( V_21 -> V_24 & V_73 ) {
V_7 -> V_46 . V_31 [ 4 ] = V_141 | F_17 ( V_133 -> V_142 ) ;
V_7 -> V_45 = V_143 ;
V_7 -> V_49 . V_74 [ 0 ] = V_144 ;
} else {
V_7 -> V_46 . V_31 [ 4 ] = V_145 | F_17 ( V_133 -> V_142 ) ;
V_7 -> V_46 . V_31 [ 5 ] = V_146 | F_17 ( V_133 -> V_142 ) ;
V_7 -> V_45 = V_147 ;
V_7 -> V_49 . V_74 [ 0 ] = V_148 ;
}
if ( V_7 -> V_77 == F_36 ( V_78 ) )
V_7 -> V_49 . V_74 [ 0 ] |= V_79 ;
else if ( V_7 -> V_77 == F_36 ( V_80 ) )
V_7 -> V_49 . V_74 [ 0 ] |= V_81 ;
else
V_7 -> V_49 . V_74 [ 0 ] |= V_82 ;
V_7 -> V_49 . V_74 [ 0 ] |= V_149 | V_150 |
F_37 ( V_7 -> V_77 + F_36 (
V_12 + V_134 ) ) ;
V_7 -> V_49 . V_74 [ 1 ] = V_151 | V_152 |
V_153 | V_154 ;
for ( V_88 = 0 ; V_88 < F_36 ( V_134 ) ; V_88 ++ )
V_86 [ V_88 ] = F_17 ( V_84 [ V_88 ] ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_13 * V_34 , struct V_13 * V_36 ,
T_2 V_11 )
{
bool V_100 , V_101 ;
V_21 -> V_34 . V_14 = V_34 ;
V_21 -> V_36 . V_14 = V_36 ;
V_21 -> V_62 = V_36 ;
V_100 = F_10 ( V_34 , V_11 , & V_21 -> V_34 ) ;
if ( V_34 == V_36 )
V_101 = V_100 ;
else
V_101 = F_10 ( V_36 , V_11 , & V_21 -> V_36 ) ;
if ( ! V_100 || ! V_101 ) {
if ( V_21 -> V_63 > V_102 )
return - V_103 ;
if ( ! V_100 ) {
F_38 ( V_34 , F_28 ( V_34 ) , V_21 -> V_43 , V_11 ) ;
V_21 -> V_34 . V_14 = & V_21 -> V_60 ;
V_21 -> V_34 . V_17 = 1 ;
V_21 -> V_34 . V_19 = 0 ;
}
if ( ! V_101 ) {
V_21 -> V_36 . V_14 = & V_21 -> V_60 ;
V_21 -> V_36 . V_17 = 1 ;
V_21 -> V_36 . V_19 = 0 ;
}
F_39 ( & V_21 -> V_60 , 1 ) ;
F_40 ( & V_21 -> V_60 , V_21 -> V_43 , V_21 -> V_63 ) ;
}
F_75 ( V_2 , V_21 , V_11 ) ;
return F_29 ( V_2 , V_21 ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_131 * V_133 = F_74 ( V_21 -> V_7 ) ;
struct V_132 * V_68 = F_76 ( V_21 -> V_69 ) ;
struct V_22 * V_23 = F_81 ( V_68 ) ;
T_1 V_11 = V_68 -> V_136 + V_68 -> V_155 ;
F_13 ( V_21 , V_23 ) ;
if ( V_21 -> V_24 & V_73 ) {
T_1 V_156 [ 4 ] ;
V_21 -> V_63 = V_11 + V_133 -> V_142 ;
V_133 -> V_140 = V_68 -> V_155 ;
F_82 ( V_156 , V_68 -> V_36 , V_11 , V_133 -> V_142 , 1 ) ;
} else {
V_21 -> V_63 = V_11 ;
V_133 -> V_140 = V_68 -> V_155 - V_133 -> V_142 ;
}
V_21 -> V_111 = F_48 ;
return F_79 ( V_2 , V_21 , V_68 -> V_34 , V_68 -> V_36 , V_11 ) ;
}
static int F_83 ( struct V_132 * V_68 , T_4 V_26 )
{
struct V_6 * V_7 = F_84 ( F_78 ( V_68 ) ) ;
struct V_22 * V_23 = F_81 ( V_68 ) ;
V_23 -> V_26 = V_55 | V_26 ;
return F_41 ( V_7 -> V_2 , ! ! ( V_26 & V_73 ) ,
& V_68 -> V_4 ) ;
}
static void F_85 ( struct V_104 * V_68 , int V_157 )
{
struct V_158 * V_159 = V_68 -> V_160 ;
if ( V_157 == - V_56 )
return;
V_159 -> V_157 = V_157 ;
V_109 ( & V_159 -> V_161 ) ;
}
static int F_86 ( struct V_162 * V_163 , const T_3 * V_121 ,
T_1 V_77 )
{
struct V_6 * V_7 = F_84 ( V_163 ) ;
struct V_131 * V_133 = F_74 ( V_7 ) ;
struct V_164 * V_116 = V_133 -> V_116 ;
struct {
T_1 V_165 [ 4 ] ;
T_3 V_84 [ 8 ] ;
struct V_158 V_159 ;
struct V_13 V_14 [ 1 ] ;
struct V_166 V_68 ;
} * V_160 ;
const T_1 * V_122 ;
T_1 * V_123 , * V_167 ;
int V_157 , V_88 ;
if ( V_77 != V_80 &&
V_77 != V_124 &&
V_77 != V_78 ) {
F_87 ( V_163 , V_125 ) ;
return - V_64 ;
}
V_123 = V_7 -> V_49 . V_87 ;
V_122 = ( T_1 * ) V_121 ;
V_7 -> V_77 = F_36 ( V_77 ) ;
for ( V_88 = 0 ; V_88 < V_7 -> V_77 ; V_88 ++ )
V_7 -> V_49 . V_87 [ V_88 ] = F_17 ( V_122 [ V_88 ] ) ;
F_88 ( V_116 , V_168 ) ;
F_89 ( V_116 , F_90 ( V_163 ) &
V_168 ) ;
V_157 = F_91 ( V_116 , V_121 , V_77 ) ;
F_87 ( V_163 , F_92 ( V_116 ) &
V_169 ) ;
if ( V_157 )
return V_157 ;
V_160 = F_93 ( sizeof( * V_160 ) + F_94 ( V_116 ) ,
V_170 ) ;
if ( ! V_160 )
return - V_103 ;
F_95 ( & V_160 -> V_159 . V_161 ) ;
F_96 ( V_160 -> V_14 , & V_160 -> V_165 , V_12 ) ;
F_97 ( & V_160 -> V_68 , V_116 ) ;
F_98 ( & V_160 -> V_68 , V_171 |
V_172 ,
F_85 , & V_160 -> V_159 ) ;
F_99 ( & V_160 -> V_68 , V_160 -> V_14 , V_160 -> V_14 ,
V_12 , V_160 -> V_84 ) ;
V_157 = F_100 ( & V_160 -> V_68 ) ;
if ( V_157 == - V_56 || V_157 == - V_173 ) {
V_157 = F_101 (
& V_160 -> V_159 . V_161 ) ;
if ( ! V_157 )
V_157 = V_160 -> V_159 . V_157 ;
}
if ( V_157 )
goto V_174;
V_167 = V_123 + V_7 -> V_77 ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ )
V_167 [ V_88 ] = F_57 ( V_160 -> V_165 [ V_88 ] ) ;
V_174:
F_102 ( V_160 ) ;
return V_157 ;
}
static int F_103 ( struct V_162 * V_163 ,
T_1 V_142 )
{
struct V_6 * V_7 = F_84 ( V_163 ) ;
struct V_131 * V_133 = F_74 ( V_7 ) ;
switch ( V_142 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_64 ;
}
V_133 -> V_142 = V_142 ;
return 0 ;
}
static int F_104 ( struct V_132 * V_68 )
{
return F_83 ( V_68 , V_73 ) ;
}
static int F_105 ( struct V_132 * V_68 )
{
return F_83 ( V_68 , 0 ) ;
}
static int F_106 ( struct V_162 * V_163 )
{
struct V_131 * V_7 = F_84 ( V_163 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_72 ( L_1 ) ;
return - V_128 ;
}
V_7 -> V_116 = F_107 ( L_2 , 0 ,
V_175 ) ;
if ( F_108 ( V_7 -> V_116 ) ) {
F_72 ( L_3 ) ;
return F_109 ( V_7 -> V_116 ) ;
}
F_110 ( V_163 , sizeof( struct V_22 ) ) ;
V_7 -> V_4 . V_110 = F_80 ;
return 0 ;
}
static void F_111 ( struct V_162 * V_163 )
{
struct V_131 * V_7 = F_84 ( V_163 ) ;
F_112 ( V_7 -> V_116 ) ;
}
static void F_113 ( unsigned long V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
struct V_20 * V_21 = V_2 -> V_21 [ 0 ] ;
F_24 ( V_2 , V_21 ) ;
V_21 -> V_111 ( V_2 , V_21 ) ;
}
static void F_114 ( unsigned long V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
struct V_20 * V_21 = V_2 -> V_21 [ 1 ] ;
F_24 ( V_2 , V_21 ) ;
V_21 -> V_111 ( V_2 , V_21 ) ;
}
static T_5 F_115 ( int V_176 , void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
struct V_20 * V_21 = V_2 -> V_21 [ 0 ] ;
T_1 V_178 = F_1 ( V_2 , F_116 ( V_179 ) ) ;
F_3 ( V_2 , F_116 ( V_179 ) , V_178 ) ;
if ( F_117 ( V_25 & V_21 -> V_24 ) ) {
F_3 ( V_2 , F_118 ( V_179 ) , V_180 ) ;
F_3 ( V_2 , F_119 ( V_179 ) ,
V_181 | V_182 ) ;
F_120 ( & V_21 -> V_183 ) ;
} else {
F_121 ( V_2 -> V_57 , L_4 ) ;
}
return V_184 ;
}
static T_5 F_122 ( int V_176 , void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
struct V_20 * V_21 = V_2 -> V_21 [ 1 ] ;
T_1 V_178 = F_1 ( V_2 , F_116 ( V_185 ) ) ;
F_3 ( V_2 , F_116 ( V_185 ) , V_178 ) ;
if ( F_117 ( V_25 & V_21 -> V_24 ) ) {
F_3 ( V_2 , F_118 ( V_185 ) , V_180 ) ;
F_3 ( V_2 , F_119 ( V_185 ) ,
V_181 | V_182 ) ;
F_120 ( & V_21 -> V_183 ) ;
} else {
F_121 ( V_2 -> V_57 , L_4 ) ;
}
return V_184 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_20 * * V_21 = V_2 -> V_21 ;
int V_88 , V_157 = - V_103 ;
for ( V_88 = 0 ; V_88 < V_186 ; V_88 ++ ) {
V_21 [ V_88 ] = F_93 ( sizeof( * * V_21 ) , V_170 ) ;
if ( ! V_21 [ V_88 ] )
goto V_187;
V_21 [ V_88 ] -> V_43 = ( void * ) F_124 ( V_170 ,
V_188 ) ;
if ( ! V_21 [ V_88 ] -> V_43 )
goto V_187;
V_21 [ V_88 ] -> V_29 = V_88 ;
F_125 ( & V_21 [ V_88 ] -> V_10 ) ;
F_126 ( & V_21 [ V_88 ] -> V_108 , V_189 ) ;
}
F_127 ( & V_21 [ 0 ] -> V_183 , F_113 , ( unsigned long ) V_2 ) ;
F_127 ( & V_21 [ 1 ] -> V_183 , F_114 , ( unsigned long ) V_2 ) ;
return 0 ;
V_187:
for (; V_88 -- ; ) {
F_128 ( ( unsigned long ) V_21 [ V_88 ] -> V_43 ) ;
F_129 ( V_21 [ V_88 ] ) ;
}
return V_157 ;
}
static void F_130 ( struct V_1 * V_2 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_186 ; V_88 ++ ) {
F_131 ( & V_2 -> V_21 [ V_88 ] -> V_183 ) ;
F_128 ( ( unsigned long ) V_2 -> V_21 [ V_88 ] -> V_43 ) ;
F_129 ( V_2 -> V_21 [ V_88 ] ) ;
}
}
static void F_132 ( void )
{
int V_88 ;
F_133 ( & V_190 ) ;
for ( V_88 = 0 ; V_88 < F_134 ( V_191 ) ; V_88 ++ )
F_135 ( & V_191 [ V_88 ] ) ;
}
static int F_136 ( void )
{
int V_157 , V_88 ;
for ( V_88 = 0 ; V_88 < F_134 ( V_191 ) ; V_88 ++ ) {
V_157 = F_137 ( & V_191 [ V_88 ] ) ;
if ( V_157 )
goto V_192;
}
V_157 = F_138 ( & V_190 ) ;
if ( V_157 )
goto V_192;
return 0 ;
V_192:
for (; V_88 -- ; )
F_135 ( & V_191 [ V_88 ] ) ;
return V_157 ;
}
int F_139 ( struct V_1 * V_2 )
{
int V_107 ;
F_140 ( & V_2 -> V_193 ) ;
V_107 = F_123 ( V_2 ) ;
if ( V_107 )
goto V_194;
V_107 = F_141 ( V_2 -> V_57 , V_2 -> V_176 [ V_179 ] , F_115 ,
V_195 , L_5 , V_2 ) ;
if ( V_107 ) {
F_142 ( V_2 -> V_57 , L_6 ) ;
goto V_196;
}
V_107 = F_141 ( V_2 -> V_57 , V_2 -> V_176 [ V_185 ] , F_122 ,
V_195 , L_5 , V_2 ) ;
if ( V_107 ) {
F_142 ( V_2 -> V_57 , L_7 ) ;
goto V_196;
}
F_3 ( V_2 , F_143 ( V_179 ) , V_197 ) ;
F_3 ( V_2 , F_143 ( V_185 ) , V_198 ) ;
F_144 ( & V_9 . V_10 ) ;
F_145 ( & V_2 -> V_193 , & V_9 . V_199 ) ;
F_146 ( & V_9 . V_10 ) ;
V_107 = F_136 () ;
if ( V_107 )
goto V_200;
return 0 ;
V_200:
F_144 ( & V_9 . V_10 ) ;
F_147 ( & V_2 -> V_193 ) ;
F_146 ( & V_9 . V_10 ) ;
V_196:
F_130 ( V_2 ) ;
V_194:
F_142 ( V_2 -> V_57 , L_8 ) ;
return V_107 ;
}
void F_148 ( struct V_1 * V_2 )
{
F_144 ( & V_9 . V_10 ) ;
F_147 ( & V_2 -> V_193 ) ;
F_146 ( & V_9 . V_10 ) ;
F_132 () ;
F_130 ( V_2 ) ;
}
