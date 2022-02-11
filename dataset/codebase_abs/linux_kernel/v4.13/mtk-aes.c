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
static inline void F_15 ( T_3 * V_27 , const T_1 * V_28 , T_1 V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_29 ) ; V_30 ++ )
V_27 [ V_30 ] = F_17 ( V_28 [ V_30 ] ) ;
}
static inline void F_18 ( T_4 * V_27 , const T_1 * V_28 , T_1 V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_29 ) ; V_30 ++ )
V_27 [ V_30 ] = F_19 ( V_28 [ V_30 ] ) ;
}
static inline int F_20 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_31 )
{
V_21 -> V_24 &= ~ V_25 ;
V_21 -> V_32 -> V_33 ( V_21 -> V_32 , V_31 ) ;
F_21 ( & V_21 -> V_34 ) ;
return V_31 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_35 * V_36 = V_2 -> V_36 [ V_21 -> V_37 ] ;
struct V_38 * V_39 = NULL , * V_40 = NULL ;
struct V_13 * V_41 = V_21 -> V_28 . V_14 , * V_42 = V_21 -> V_27 . V_14 ;
T_1 V_43 = V_21 -> V_28 . V_44 , V_45 = V_21 -> V_27 . V_44 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_43 ; ++ V_17 , V_41 = F_12 ( V_41 ) ) {
V_39 = V_36 -> V_46 ;
V_39 -> V_47 = F_23 ( V_41 -> V_18 ) ;
V_39 -> V_48 = F_17 ( F_24 ( V_41 ) ) ;
if ( V_17 == 0 ) {
V_39 -> V_47 |= V_49 |
F_25 ( V_21 -> V_7 -> V_50 ) ;
V_39 -> V_51 = F_17 ( V_21 -> V_7 -> V_52 ) ;
V_39 -> V_53 = V_21 -> V_7 -> V_53 ;
V_39 -> V_54 = F_17 ( V_21 -> V_7 -> V_55 ) ;
}
if ( ++ V_36 -> V_46 == V_36 -> V_56 + V_57 )
V_36 -> V_46 = V_36 -> V_56 ;
}
V_39 -> V_47 |= V_58 ;
for ( V_17 = 0 ; V_17 < V_45 ; ++ V_17 , V_42 = F_12 ( V_42 ) ) {
V_40 = V_36 -> V_59 ;
V_40 -> V_47 = F_23 ( V_42 -> V_18 ) ;
V_40 -> V_48 = F_17 ( F_24 ( V_42 ) ) ;
if ( V_17 == 0 )
V_40 -> V_47 |= V_49 ;
if ( ++ V_36 -> V_59 == V_36 -> V_60 + V_57 )
V_36 -> V_59 = V_36 -> V_60 ;
}
V_40 -> V_47 |= V_58 ;
V_36 -> V_61 = V_40 ;
if ( V_21 -> V_24 & V_62 )
V_40 -> V_47 += V_12 ;
F_26 () ;
F_3 ( V_2 , F_27 ( V_21 -> V_37 ) , F_28 ( V_45 ) ) ;
F_3 ( V_2 , F_29 ( V_21 -> V_37 ) , F_28 ( V_43 ) ) ;
return - V_63 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
F_31 ( V_2 -> V_64 , V_7 -> V_52 , sizeof( V_7 -> V_65 ) ,
V_66 ) ;
if ( V_21 -> V_28 . V_14 == V_21 -> V_27 . V_14 ) {
F_32 ( V_2 -> V_64 , V_21 -> V_28 . V_14 , V_21 -> V_28 . V_17 ,
V_67 ) ;
if ( V_21 -> V_28 . V_14 != & V_21 -> V_68 )
F_14 ( & V_21 -> V_28 ) ;
} else {
F_32 ( V_2 -> V_64 , V_21 -> V_27 . V_14 , V_21 -> V_27 . V_17 ,
V_69 ) ;
if ( V_21 -> V_27 . V_14 != & V_21 -> V_68 )
F_14 ( & V_21 -> V_27 ) ;
F_32 ( V_2 -> V_64 , V_21 -> V_28 . V_14 , V_21 -> V_28 . V_17 ,
V_66 ) ;
if ( V_21 -> V_28 . V_14 != & V_21 -> V_68 )
F_14 ( & V_21 -> V_28 ) ;
}
if ( V_21 -> V_27 . V_14 == & V_21 -> V_68 )
F_33 ( V_21 -> V_70 , F_34 ( V_21 -> V_70 ) ,
V_21 -> V_48 , V_21 -> V_71 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_72 * V_65 = & V_7 -> V_65 ;
V_7 -> V_52 = F_36 ( V_2 -> V_64 , V_65 , sizeof( * V_65 ) ,
V_66 ) ;
if ( F_37 ( F_38 ( V_2 -> V_64 , V_7 -> V_52 ) ) )
goto exit;
V_7 -> V_55 = V_7 -> V_52 + sizeof( V_65 -> V_39 ) ;
if ( V_21 -> V_28 . V_14 == V_21 -> V_27 . V_14 ) {
V_21 -> V_28 . V_44 = F_39 ( V_2 -> V_64 , V_21 -> V_28 . V_14 ,
V_21 -> V_28 . V_17 ,
V_67 ) ;
V_21 -> V_27 . V_44 = V_21 -> V_28 . V_44 ;
if ( F_37 ( ! V_21 -> V_28 . V_44 ) )
goto V_73;
} else {
V_21 -> V_28 . V_44 = F_39 ( V_2 -> V_64 , V_21 -> V_28 . V_14 ,
V_21 -> V_28 . V_17 , V_66 ) ;
if ( F_37 ( ! V_21 -> V_28 . V_44 ) )
goto V_73;
V_21 -> V_27 . V_44 = F_39 ( V_2 -> V_64 , V_21 -> V_27 . V_14 ,
V_21 -> V_27 . V_17 , V_69 ) ;
if ( F_37 ( ! V_21 -> V_27 . V_44 ) ) {
F_32 ( V_2 -> V_64 , V_21 -> V_28 . V_14 , V_21 -> V_28 . V_17 ,
V_66 ) ;
goto V_73;
}
}
return F_22 ( V_2 , V_21 ) ;
V_73:
F_31 ( V_2 -> V_64 , V_7 -> V_52 , sizeof( * V_65 ) , V_66 ) ;
exit:
return F_20 ( V_2 , V_21 , - V_74 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_20 * V_21 ,
T_2 V_11 )
{
struct V_75 * V_76 = F_41 ( V_21 -> V_32 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_72 * V_65 = & V_7 -> V_65 ;
T_1 V_77 = 0 ;
V_7 -> V_53 = V_78 | F_17 ( V_11 ) ;
V_65 -> V_39 [ V_77 ++ ] = V_79 | F_17 ( V_11 ) ;
V_65 -> V_39 [ V_77 ++ ] = V_80 ;
V_65 -> V_54 [ 0 ] = F_42 ( V_7 -> V_81 ) | V_7 -> V_82 ;
if ( V_21 -> V_24 & V_83 )
V_65 -> V_54 [ 0 ] |= V_84 ;
else
V_65 -> V_54 [ 0 ] |= V_85 ;
switch ( V_21 -> V_24 & V_86 ) {
case V_87 :
V_65 -> V_54 [ 1 ] = V_88 ;
break;
case V_89 :
V_65 -> V_54 [ 1 ] = V_90 ;
goto V_91;
case V_92 :
V_65 -> V_54 [ 1 ] = V_93 ;
goto V_94;
default:
return;
}
F_15 ( V_65 -> V_95 + V_7 -> V_81 , V_76 -> V_65 ,
V_12 ) ;
V_94:
V_65 -> V_54 [ 0 ] += F_42 ( F_16 ( V_12 ) ) ;
V_65 -> V_54 [ 1 ] |= V_96 ;
V_65 -> V_39 [ V_77 ++ ] = V_97 ;
V_91:
V_7 -> V_50 = V_77 ;
}
static int V_15 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_13 * V_28 , struct V_13 * V_27 ,
T_2 V_11 )
{
T_2 V_98 = 0 ;
bool V_99 , V_100 ;
V_21 -> V_71 = V_11 ;
V_21 -> V_28 . V_14 = V_28 ;
V_21 -> V_27 . V_14 = V_27 ;
V_21 -> V_70 = V_27 ;
V_99 = F_10 ( V_28 , V_11 , & V_21 -> V_28 ) ;
if ( V_28 == V_27 )
V_100 = V_99 ;
else
V_100 = F_10 ( V_27 , V_11 , & V_21 -> V_27 ) ;
if ( ! V_99 || ! V_100 ) {
V_98 = F_9 ( V_11 ) ;
if ( V_11 + V_98 > V_101 )
return F_20 ( V_2 , V_21 , - V_102 ) ;
if ( ! V_99 ) {
F_43 ( V_28 , F_34 ( V_28 ) , V_21 -> V_48 , V_11 ) ;
V_21 -> V_28 . V_14 = & V_21 -> V_68 ;
V_21 -> V_28 . V_17 = 1 ;
V_21 -> V_28 . V_19 = 0 ;
}
if ( ! V_100 ) {
V_21 -> V_27 . V_14 = & V_21 -> V_68 ;
V_21 -> V_27 . V_17 = 1 ;
V_21 -> V_27 . V_19 = 0 ;
}
F_44 ( & V_21 -> V_68 , 1 ) ;
F_45 ( & V_21 -> V_68 , V_21 -> V_48 , V_11 + V_98 ) ;
}
F_40 ( V_2 , V_21 , V_11 + V_98 ) ;
return F_35 ( V_2 , V_21 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_5 V_37 ,
struct V_103 * V_104 )
{
struct V_20 * V_21 = V_2 -> V_21 [ V_37 ] ;
struct V_103 * V_32 , * V_105 ;
struct V_6 * V_7 ;
unsigned long V_24 ;
int V_106 = 0 ;
F_47 ( & V_21 -> V_10 , V_24 ) ;
if ( V_104 )
V_106 = F_48 ( & V_21 -> V_107 , V_104 ) ;
if ( V_21 -> V_24 & V_25 ) {
F_49 ( & V_21 -> V_10 , V_24 ) ;
return V_106 ;
}
V_105 = F_50 ( & V_21 -> V_107 ) ;
V_32 = F_51 ( & V_21 -> V_107 ) ;
if ( V_32 )
V_21 -> V_24 |= V_25 ;
F_49 ( & V_21 -> V_10 , V_24 ) ;
if ( ! V_32 )
return V_106 ;
if ( V_105 )
V_105 -> V_33 ( V_105 , - V_63 ) ;
V_7 = F_52 ( V_32 -> V_54 ) ;
V_21 -> V_32 = V_32 ;
V_21 -> V_7 = V_7 ;
return V_7 -> V_108 ( V_2 , V_21 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
return F_20 ( V_2 , V_21 , 0 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_75 * V_76 = F_41 ( V_21 -> V_32 ) ;
struct V_22 * V_23 = F_55 ( V_76 ) ;
F_13 ( V_21 , V_23 ) ;
V_21 -> V_109 = F_53 ;
return V_15 ( V_2 , V_21 , V_76 -> V_28 , V_76 -> V_27 , V_76 -> V_110 ) ;
}
static inline struct V_111 *
F_56 ( struct V_6 * V_7 )
{
return F_57 ( V_7 , struct V_111 , V_4 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_111 * V_112 = F_56 ( V_7 ) ;
struct V_75 * V_76 = F_41 ( V_21 -> V_32 ) ;
struct V_13 * V_28 , * V_27 ;
T_1 V_108 , V_113 , V_94 , V_114 ;
T_2 V_115 ;
bool V_116 = false ;
V_112 -> V_3 += V_21 -> V_71 ;
if ( V_112 -> V_3 >= V_76 -> V_110 )
return F_53 ( V_2 , V_21 ) ;
V_115 = V_76 -> V_110 - V_112 -> V_3 ;
V_114 = F_59 ( V_115 , V_12 ) ;
V_94 = F_60 ( V_112 -> V_117 [ 3 ] ) ;
V_108 = V_94 ;
V_113 = V_108 + V_114 - 1 ;
if ( V_113 < V_108 ) {
V_94 |= 0xffffffff ;
V_115 = V_12 * - V_108 ;
V_116 = true ;
}
V_28 = F_61 ( V_112 -> V_28 , V_76 -> V_28 , V_112 -> V_3 ) ;
V_27 = ( ( V_76 -> V_28 == V_76 -> V_27 ) ? V_28 :
F_61 ( V_112 -> V_27 , V_76 -> V_27 , V_112 -> V_3 ) ) ;
F_15 ( V_7 -> V_65 . V_95 + V_7 -> V_81 , V_112 -> V_117 ,
V_12 ) ;
if ( F_37 ( V_116 ) ) {
V_112 -> V_117 [ 3 ] = F_19 ( V_94 ) ;
F_62 ( ( T_5 * ) V_112 -> V_117 , V_12 ) ;
}
return V_15 ( V_2 , V_21 , V_28 , V_27 , V_115 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_111 * V_112 = F_56 ( V_21 -> V_7 ) ;
struct V_75 * V_76 = F_41 ( V_21 -> V_32 ) ;
struct V_22 * V_23 = F_55 ( V_76 ) ;
F_13 ( V_21 , V_23 ) ;
memcpy ( V_112 -> V_117 , V_76 -> V_65 , V_12 ) ;
V_112 -> V_3 = 0 ;
V_21 -> V_71 = 0 ;
V_21 -> V_109 = F_58 ;
return F_58 ( V_2 , V_21 ) ;
}
static int F_64 ( struct V_118 * V_54 ,
const T_5 * V_119 , T_1 V_81 )
{
struct V_6 * V_7 = F_65 ( V_54 ) ;
switch ( V_81 ) {
case V_120 :
V_7 -> V_82 = V_121 ;
break;
case V_122 :
V_7 -> V_82 = V_123 ;
break;
case V_124 :
V_7 -> V_82 = V_125 ;
break;
default:
F_66 ( V_54 , V_126 ) ;
return - V_74 ;
}
V_7 -> V_81 = F_16 ( V_81 ) ;
F_15 ( V_7 -> V_65 . V_95 , ( const T_1 * ) V_119 , V_81 ) ;
return 0 ;
}
static int F_67 ( struct V_75 * V_76 , T_6 V_26 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 ;
V_7 = F_65 ( F_68 ( V_76 ) ) ;
V_23 = F_55 ( V_76 ) ;
V_23 -> V_26 = V_26 ;
return F_46 ( V_7 -> V_2 , ! ( V_26 & V_83 ) ,
& V_76 -> V_4 ) ;
}
static int F_69 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_83 | V_89 ) ;
}
static int F_70 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_89 ) ;
}
static int F_71 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_83 | V_87 ) ;
}
static int F_72 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_87 ) ;
}
static int F_73 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_83 | V_92 ) ;
}
static int F_74 ( struct V_75 * V_76 )
{
return F_67 ( V_76 , V_92 ) ;
}
static int F_75 ( struct V_127 * V_54 )
{
struct V_128 * V_7 = F_52 ( V_54 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_76 ( L_1 ) ;
return - V_129 ;
}
V_54 -> V_130 . V_131 = sizeof( struct V_22 ) ;
V_7 -> V_4 . V_108 = F_54 ;
return 0 ;
}
static int F_77 ( struct V_127 * V_54 )
{
struct V_128 * V_7 = F_52 ( V_54 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_76 ( L_1 ) ;
return - V_129 ;
}
V_54 -> V_130 . V_131 = sizeof( struct V_22 ) ;
V_7 -> V_4 . V_108 = F_63 ;
return 0 ;
}
static inline struct V_132 *
F_78 ( struct V_6 * V_7 )
{
return F_57 ( V_7 , struct V_132 , V_4 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
T_1 V_133 = V_2 -> V_36 [ V_21 -> V_37 ] -> V_61 -> V_51 ;
return F_20 ( V_2 , V_21 , ( V_133 & V_134 ) ?
- V_135 : 0 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_2 V_11 )
{
struct V_136 * V_76 = F_81 ( V_21 -> V_32 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_132 * V_137 = F_78 ( V_7 ) ;
struct V_72 * V_65 = & V_7 -> V_65 ;
T_1 V_138 = F_82 ( F_83 ( V_76 ) ) ;
T_1 V_77 = 0 ;
V_7 -> V_53 = V_78 | V_11 ;
V_65 -> V_39 [ V_77 ++ ] = V_139 | F_17 ( V_76 -> V_140 ) ;
V_65 -> V_39 [ V_77 ++ ] = V_141 | F_17 ( V_76 -> V_140 ) ;
V_65 -> V_39 [ V_77 ++ ] = V_142 ;
V_65 -> V_39 [ V_77 ++ ] = V_143 | F_17 ( V_137 -> V_144 ) ;
if ( V_21 -> V_24 & V_83 ) {
V_65 -> V_39 [ V_77 ++ ] = V_145 | F_17 ( V_137 -> V_146 ) ;
V_65 -> V_54 [ 0 ] = V_147 ;
} else {
V_65 -> V_39 [ V_77 ++ ] = V_148 | F_17 ( V_137 -> V_146 ) ;
V_65 -> V_39 [ V_77 ++ ] = V_149 | F_17 ( V_137 -> V_146 ) ;
V_65 -> V_54 [ 0 ] = V_150 ;
}
V_7 -> V_50 = V_77 ;
V_65 -> V_54 [ 0 ] |= V_151 | V_152 | F_42 (
V_7 -> V_81 + F_16 ( V_12 + V_138 ) ) |
V_7 -> V_82 ;
V_65 -> V_54 [ 1 ] = V_153 | V_154 | V_155 |
V_156 ;
F_15 ( V_65 -> V_95 + V_7 -> V_81 + F_16 (
V_12 ) , ( const T_1 * ) V_76 -> V_117 , V_138 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_13 * V_28 , struct V_13 * V_27 ,
T_2 V_11 )
{
bool V_99 , V_100 ;
V_21 -> V_28 . V_14 = V_28 ;
V_21 -> V_27 . V_14 = V_27 ;
V_21 -> V_70 = V_27 ;
V_99 = F_10 ( V_28 , V_11 , & V_21 -> V_28 ) ;
if ( V_28 == V_27 )
V_100 = V_99 ;
else
V_100 = F_10 ( V_27 , V_11 , & V_21 -> V_27 ) ;
if ( ! V_99 || ! V_100 ) {
if ( V_21 -> V_71 > V_101 )
return F_20 ( V_2 , V_21 , - V_102 ) ;
if ( ! V_99 ) {
F_43 ( V_28 , F_34 ( V_28 ) , V_21 -> V_48 , V_11 ) ;
V_21 -> V_28 . V_14 = & V_21 -> V_68 ;
V_21 -> V_28 . V_17 = 1 ;
V_21 -> V_28 . V_19 = 0 ;
}
if ( ! V_100 ) {
V_21 -> V_27 . V_14 = & V_21 -> V_68 ;
V_21 -> V_27 . V_17 = 1 ;
V_21 -> V_27 . V_19 = 0 ;
}
F_44 ( & V_21 -> V_68 , 1 ) ;
F_45 ( & V_21 -> V_68 , V_21 -> V_48 , V_21 -> V_71 ) ;
}
F_80 ( V_2 , V_21 , V_11 ) ;
return F_35 ( V_2 , V_21 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_132 * V_137 = F_78 ( V_21 -> V_7 ) ;
struct V_136 * V_76 = F_81 ( V_21 -> V_32 ) ;
struct V_22 * V_23 = F_86 ( V_76 ) ;
T_1 V_11 = V_76 -> V_140 + V_76 -> V_157 ;
F_13 ( V_21 , V_23 ) ;
if ( V_21 -> V_24 & V_83 ) {
T_1 V_158 [ 4 ] ;
V_21 -> V_109 = F_53 ;
V_21 -> V_71 = V_11 + V_137 -> V_146 ;
V_137 -> V_144 = V_76 -> V_157 ;
F_87 ( V_158 , V_76 -> V_27 , V_11 , V_137 -> V_146 , 1 ) ;
} else {
V_21 -> V_109 = F_79 ;
V_21 -> V_71 = V_11 ;
V_137 -> V_144 = V_76 -> V_157 - V_137 -> V_146 ;
}
return F_84 ( V_2 , V_21 , V_76 -> V_28 , V_76 -> V_27 , V_11 ) ;
}
static int F_88 ( struct V_136 * V_76 , T_6 V_26 )
{
struct V_6 * V_7 = F_89 ( F_83 ( V_76 ) ) ;
struct V_22 * V_23 = F_86 ( V_76 ) ;
V_23 -> V_26 = V_62 | V_26 ;
return F_46 ( V_7 -> V_2 , ! ! ( V_26 & V_83 ) ,
& V_76 -> V_4 ) ;
}
static void F_90 ( struct V_103 * V_76 , int V_31 )
{
struct V_159 * V_160 = V_76 -> V_161 ;
if ( V_31 == - V_63 )
return;
V_160 -> V_31 = V_31 ;
V_33 ( & V_160 -> V_162 ) ;
}
static int F_91 ( struct V_163 * V_164 , const T_5 * V_119 ,
T_1 V_81 )
{
struct V_6 * V_7 = F_89 ( V_164 ) ;
struct V_132 * V_137 = F_78 ( V_7 ) ;
struct V_165 * V_94 = V_137 -> V_94 ;
struct {
T_1 V_166 [ 4 ] ;
T_5 V_117 [ 8 ] ;
struct V_159 V_160 ;
struct V_13 V_14 [ 1 ] ;
struct V_167 V_76 ;
} * V_161 ;
int V_31 ;
switch ( V_81 ) {
case V_120 :
V_7 -> V_82 = V_121 ;
break;
case V_122 :
V_7 -> V_82 = V_123 ;
break;
case V_124 :
V_7 -> V_82 = V_125 ;
break;
default:
F_92 ( V_164 , V_126 ) ;
return - V_74 ;
}
V_7 -> V_81 = F_16 ( V_81 ) ;
F_93 ( V_94 , V_168 ) ;
F_94 ( V_94 , F_95 ( V_164 ) &
V_168 ) ;
V_31 = F_96 ( V_94 , V_119 , V_81 ) ;
F_92 ( V_164 , F_97 ( V_94 ) &
V_169 ) ;
if ( V_31 )
return V_31 ;
V_161 = F_98 ( sizeof( * V_161 ) + F_99 ( V_94 ) ,
V_170 ) ;
if ( ! V_161 )
return - V_102 ;
F_100 ( & V_161 -> V_160 . V_162 ) ;
F_101 ( V_161 -> V_14 , & V_161 -> V_166 , V_12 ) ;
F_102 ( & V_161 -> V_76 , V_94 ) ;
F_103 ( & V_161 -> V_76 , V_171 |
V_172 ,
F_90 , & V_161 -> V_160 ) ;
F_104 ( & V_161 -> V_76 , V_161 -> V_14 , V_161 -> V_14 ,
V_12 , V_161 -> V_117 ) ;
V_31 = F_105 ( & V_161 -> V_76 ) ;
if ( V_31 == - V_63 || V_31 == - V_173 ) {
V_31 = F_106 (
& V_161 -> V_160 . V_162 ) ;
if ( ! V_31 )
V_31 = V_161 -> V_160 . V_31 ;
}
if ( V_31 )
goto V_174;
F_15 ( V_7 -> V_65 . V_95 , ( const T_1 * ) V_119 , V_81 ) ;
F_18 ( V_7 -> V_65 . V_95 + V_7 -> V_81 , V_161 -> V_166 ,
V_12 ) ;
V_174:
F_107 ( V_161 ) ;
return V_31 ;
}
static int F_108 ( struct V_163 * V_164 ,
T_1 V_146 )
{
struct V_6 * V_7 = F_89 ( V_164 ) ;
struct V_132 * V_137 = F_78 ( V_7 ) ;
switch ( V_146 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_74 ;
}
V_137 -> V_146 = V_146 ;
return 0 ;
}
static int F_109 ( struct V_136 * V_76 )
{
return F_88 ( V_76 , V_83 ) ;
}
static int F_110 ( struct V_136 * V_76 )
{
return F_88 ( V_76 , 0 ) ;
}
static int F_111 ( struct V_163 * V_164 )
{
struct V_132 * V_7 = F_89 ( V_164 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( & V_7 -> V_4 ) ;
if ( ! V_2 ) {
F_76 ( L_1 ) ;
return - V_129 ;
}
V_7 -> V_94 = F_112 ( L_2 , 0 ,
V_175 ) ;
if ( F_113 ( V_7 -> V_94 ) ) {
F_76 ( L_3 ) ;
return F_114 ( V_7 -> V_94 ) ;
}
F_115 ( V_164 , sizeof( struct V_22 ) ) ;
V_7 -> V_4 . V_108 = F_85 ;
return 0 ;
}
static void F_116 ( struct V_163 * V_164 )
{
struct V_132 * V_7 = F_89 ( V_164 ) ;
F_117 ( V_7 -> V_94 ) ;
}
static void F_118 ( unsigned long V_161 )
{
struct V_20 * V_21 = (struct V_20 * ) V_161 ;
F_46 ( V_21 -> V_2 , V_21 -> V_37 , NULL ) ;
}
static void F_119 ( unsigned long V_161 )
{
struct V_20 * V_21 = (struct V_20 * ) V_161 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_30 ( V_2 , V_21 ) ;
V_21 -> V_109 ( V_2 , V_21 ) ;
}
static T_7 F_120 ( int V_176 , void * V_177 )
{
struct V_20 * V_21 = (struct V_20 * ) V_177 ;
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_178 = F_1 ( V_2 , F_121 ( V_21 -> V_37 ) ) ;
F_3 ( V_2 , F_121 ( V_21 -> V_37 ) , V_178 ) ;
if ( F_122 ( V_25 & V_21 -> V_24 ) ) {
F_3 ( V_2 , F_123 ( V_21 -> V_37 ) , V_179 ) ;
F_3 ( V_2 , F_124 ( V_21 -> V_37 ) ,
V_180 | V_181 ) ;
F_21 ( & V_21 -> V_182 ) ;
} else {
F_125 ( V_2 -> V_64 , L_4 ) ;
}
return V_183 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_20 * * V_21 = V_2 -> V_21 ;
int V_30 , V_31 = - V_102 ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ ) {
V_21 [ V_30 ] = F_98 ( sizeof( * * V_21 ) , V_170 ) ;
if ( ! V_21 [ V_30 ] )
goto V_185;
V_21 [ V_30 ] -> V_48 = ( void * ) F_127 ( V_170 ,
V_186 ) ;
if ( ! V_21 [ V_30 ] -> V_48 )
goto V_185;
V_21 [ V_30 ] -> V_2 = V_2 ;
F_128 ( & V_21 [ V_30 ] -> V_10 ) ;
F_129 ( & V_21 [ V_30 ] -> V_107 , V_187 ) ;
F_130 ( & V_21 [ V_30 ] -> V_34 , F_118 ,
( unsigned long ) V_21 [ V_30 ] ) ;
F_130 ( & V_21 [ V_30 ] -> V_182 , F_119 ,
( unsigned long ) V_21 [ V_30 ] ) ;
}
V_21 [ 0 ] -> V_37 = V_188 ;
V_21 [ 1 ] -> V_37 = V_189 ;
return 0 ;
V_185:
for (; V_30 -- ; ) {
F_131 ( ( unsigned long ) V_21 [ V_30 ] -> V_48 ) ;
F_132 ( V_21 [ V_30 ] ) ;
}
return V_31 ;
}
static void F_133 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_184 ; V_30 ++ ) {
F_134 ( & V_2 -> V_21 [ V_30 ] -> V_182 ) ;
F_134 ( & V_2 -> V_21 [ V_30 ] -> V_34 ) ;
F_131 ( ( unsigned long ) V_2 -> V_21 [ V_30 ] -> V_48 ) ;
F_132 ( V_2 -> V_21 [ V_30 ] ) ;
}
}
static void F_135 ( void )
{
int V_30 ;
F_136 ( & V_190 ) ;
for ( V_30 = 0 ; V_30 < F_137 ( V_191 ) ; V_30 ++ )
F_138 ( & V_191 [ V_30 ] ) ;
}
static int F_139 ( void )
{
int V_31 , V_30 ;
for ( V_30 = 0 ; V_30 < F_137 ( V_191 ) ; V_30 ++ ) {
V_31 = F_140 ( & V_191 [ V_30 ] ) ;
if ( V_31 )
goto V_192;
}
V_31 = F_141 ( & V_190 ) ;
if ( V_31 )
goto V_192;
return 0 ;
V_192:
for (; V_30 -- ; )
F_138 ( & V_191 [ V_30 ] ) ;
return V_31 ;
}
int F_142 ( struct V_1 * V_2 )
{
int V_106 ;
F_143 ( & V_2 -> V_193 ) ;
V_106 = F_126 ( V_2 ) ;
if ( V_106 )
goto V_194;
V_106 = F_144 ( V_2 -> V_64 , V_2 -> V_176 [ V_188 ] , F_120 ,
0 , L_5 , V_2 -> V_21 [ 0 ] ) ;
if ( V_106 ) {
F_145 ( V_2 -> V_64 , L_6 ) ;
goto V_195;
}
V_106 = F_144 ( V_2 -> V_64 , V_2 -> V_176 [ V_189 ] , F_120 ,
0 , L_5 , V_2 -> V_21 [ 1 ] ) ;
if ( V_106 ) {
F_145 ( V_2 -> V_64 , L_6 ) ;
goto V_195;
}
F_3 ( V_2 , F_146 ( V_188 ) , V_196 ) ;
F_3 ( V_2 , F_146 ( V_189 ) , V_197 ) ;
F_147 ( & V_9 . V_10 ) ;
F_148 ( & V_2 -> V_193 , & V_9 . V_198 ) ;
F_149 ( & V_9 . V_10 ) ;
V_106 = F_139 () ;
if ( V_106 )
goto V_199;
return 0 ;
V_199:
F_147 ( & V_9 . V_10 ) ;
F_150 ( & V_2 -> V_193 ) ;
F_149 ( & V_9 . V_10 ) ;
V_195:
F_133 ( V_2 ) ;
V_194:
F_145 ( V_2 -> V_64 , L_7 ) ;
return V_106 ;
}
void F_151 ( struct V_1 * V_2 )
{
F_147 ( & V_9 . V_10 ) ;
F_150 ( & V_2 -> V_193 ) ;
F_149 ( & V_9 . V_10 ) ;
F_135 () ;
F_133 ( V_2 ) ;
}
