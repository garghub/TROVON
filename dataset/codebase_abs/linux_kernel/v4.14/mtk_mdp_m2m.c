static const struct V_1 * F_1 ( T_1 V_2 , T_1 type )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( type ) ? V_5 :
V_6 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_7 ) ; ++ V_3 ) {
if ( ! ( V_7 [ V_3 ] . V_8 & V_4 ) )
continue;
if ( V_7 [ V_3 ] . V_2 == V_2 )
return & V_7 [ V_3 ] ;
}
return NULL ;
}
static const struct V_1 * F_4 ( T_1 V_9 , T_1 type )
{
T_1 V_3 , V_4 , V_10 = 0 ;
V_4 = F_2 ( type ) ? V_5 :
V_6 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_7 ) ; ++ V_3 ) {
if ( ! ( V_7 [ V_3 ] . V_8 & V_4 ) )
continue;
if ( V_9 == V_10 )
return & V_7 [ V_3 ] ;
V_10 ++ ;
}
return NULL ;
}
static void F_5 ( T_1 * V_11 , unsigned int V_12 ,
unsigned int V_13 , unsigned int V_14 ,
T_1 * V_15 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 )
{
int V_19 , V_20 , V_21 , V_22 ;
int V_23 , V_24 ;
V_19 = * V_11 ;
V_20 = * V_15 ;
V_23 = F_6 ( V_14 ) - 1 ;
V_24 = F_6 ( V_18 ) - 1 ;
F_7 ( V_11 , V_12 , V_13 , V_23 , V_15 , V_16 , V_17 , V_24 , 0 ) ;
V_21 = 1 << V_23 ;
V_22 = 1 << V_24 ;
if ( * V_11 < V_19 && ( * V_11 + V_21 ) <= V_13 )
* V_11 += V_21 ;
if ( * V_15 < V_20 && ( * V_15 + V_22 ) <= V_17 )
* V_15 += V_22 ;
}
static const struct V_1 * F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_32 * V_33 = V_30 -> V_33 ;
struct V_34 * V_35 = & V_28 -> V_36 . V_35 ;
const struct V_1 * V_36 ;
T_1 V_37 , V_38 , V_14 , V_18 ;
T_1 V_39 , V_40 , V_19 , V_20 ;
int V_3 ;
V_36 = F_1 ( V_35 -> V_2 , V_28 -> type ) ;
if ( ! V_36 )
V_36 = F_4 ( 0 , V_28 -> type ) ;
if ( ! V_36 ) {
F_9 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_1 ,
V_35 -> V_2 ) ;
return NULL ;
}
V_35 -> V_43 = V_44 ;
V_35 -> V_2 = V_36 -> V_2 ;
if ( ! F_2 ( V_28 -> type ) ) {
V_35 -> V_45 = V_26 -> V_45 ;
V_35 -> V_46 = V_26 -> V_46 ;
V_35 -> V_47 = V_26 -> V_47 ;
V_35 -> V_48 = V_26 -> V_49 ;
}
memset ( V_35 -> V_50 , 0 , sizeof( V_35 -> V_50 ) ) ;
V_37 = V_33 -> V_51 -> V_52 ;
V_38 = V_33 -> V_51 -> V_53 ;
if ( V_36 -> V_54 == NULL ) {
V_14 = V_33 -> V_55 -> V_19 ;
V_18 = V_33 -> V_55 -> V_20 ;
} else {
V_14 = V_36 -> V_54 -> V_19 ;
V_18 = V_36 -> V_54 -> V_20 ;
}
if ( F_2 ( V_28 -> type ) ) {
V_39 = V_33 -> V_56 -> V_19 ;
V_40 = V_33 -> V_56 -> V_20 ;
} else {
V_39 = V_33 -> V_56 -> V_52 ;
V_40 = V_33 -> V_56 -> V_53 ;
}
F_10 ( 2 , L_2 ,
V_26 -> V_57 , V_28 -> type , V_35 -> V_58 , V_35 -> V_59 ,
V_14 , V_18 , V_37 , V_38 ) ;
V_19 = V_35 -> V_58 ;
V_20 = V_35 -> V_59 ;
F_5 ( & V_35 -> V_58 , V_39 , V_37 , V_14 ,
& V_35 -> V_59 , V_40 , V_38 , V_18 ) ;
if ( V_19 != V_35 -> V_58 || V_20 != V_35 -> V_59 )
F_10 ( 1 , L_3 , V_26 -> V_57 ,
V_19 , V_20 , V_35 -> V_58 , V_35 -> V_59 ) ;
V_35 -> V_60 = V_36 -> V_60 ;
for ( V_3 = 0 ; V_3 < V_35 -> V_60 ; ++ V_3 ) {
int V_61 = ( V_35 -> V_58 * V_36 -> V_62 [ V_3 ] ) / 8 ;
int V_63 = ( V_35 -> V_58 * V_35 -> V_59 *
V_36 -> V_64 [ V_3 ] ) / 8 ;
V_35 -> V_65 [ V_3 ] . V_66 = V_61 ;
if ( V_35 -> V_65 [ V_3 ] . V_63 < V_63 )
V_35 -> V_65 [ V_3 ] . V_63 = V_63 ;
memset ( V_35 -> V_65 [ V_3 ] . V_50 , 0 ,
sizeof( V_35 -> V_65 [ V_3 ] . V_50 ) ) ;
F_10 ( 2 , L_4 , V_26 -> V_57 ,
V_3 , V_61 , V_35 -> V_65 [ V_3 ] . V_63 , V_63 ) ;
}
return V_36 ;
}
static struct V_67 * F_11 ( struct V_25 * V_26 ,
enum V_68 type )
{
if ( F_2 ( type ) )
return & V_26 -> V_69 ;
return & V_26 -> V_70 ;
}
static void F_12 ( T_1 V_71 , T_1 V_72 , T_1 * V_11 , T_1 * V_15 )
{
if ( V_71 != * V_11 || V_72 != * V_15 ) {
F_10 ( 1 , L_5 ,
* V_11 , * V_15 , V_71 , V_72 ) ;
* V_11 = V_71 ;
* V_15 = V_72 ;
}
}
static int F_13 ( struct V_25 * V_26 , T_1 type ,
struct V_73 * V_74 )
{
struct V_67 * V_75 ;
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_32 * V_33 = V_30 -> V_33 ;
T_1 V_14 , V_18 , V_71 , V_72 ;
T_1 V_39 , V_40 , V_37 , V_38 ;
if ( V_74 -> V_76 < 0 || V_74 -> V_77 < 0 ) {
F_14 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_6 ) ;
return - V_78 ;
}
F_10 ( 2 , L_7 , V_26 -> V_57 , type ,
V_74 -> V_58 , V_74 -> V_59 ) ;
V_75 = F_11 ( V_26 , type ) ;
V_37 = V_75 -> V_58 ;
V_38 = V_75 -> V_59 ;
V_71 = V_74 -> V_58 ;
V_72 = V_74 -> V_59 ;
if ( F_2 ( type ) ) {
V_14 = 1 ;
V_18 = 1 ;
V_39 = 64 ;
V_40 = 32 ;
} else {
V_14 = V_33 -> V_55 -> V_79 ;
V_18 = V_33 -> V_55 -> V_80 ;
if ( V_26 -> V_81 . V_82 -> V_83 == 90 ||
V_26 -> V_81 . V_82 -> V_83 == 270 ) {
V_37 = V_75 -> V_59 ;
V_38 = V_75 -> V_58 ;
V_39 = V_33 -> V_56 -> V_84 ;
V_40 = V_33 -> V_56 -> V_85 ;
V_71 = V_74 -> V_59 ;
V_72 = V_74 -> V_58 ;
} else {
V_39 = V_33 -> V_56 -> V_52 ;
V_40 = V_33 -> V_56 -> V_53 ;
}
}
F_10 ( 2 , L_8 , V_26 -> V_57 ,
V_14 , V_18 , V_39 , V_40 , V_71 , V_72 ) ;
F_5 ( & V_71 , V_39 , V_37 , V_14 ,
& V_72 , V_40 , V_38 , V_18 ) ;
if ( ! F_2 ( type ) &&
( V_26 -> V_81 . V_82 -> V_83 == 90 ||
V_26 -> V_81 . V_82 -> V_83 == 270 ) )
F_12 ( V_72 , V_71 ,
& V_74 -> V_58 , & V_74 -> V_59 ) ;
else
F_12 ( V_71 , V_72 ,
& V_74 -> V_58 , & V_74 -> V_59 ) ;
if ( V_74 -> V_77 + V_71 > V_37 )
V_74 -> V_77 = V_37 - V_71 ;
if ( V_74 -> V_76 + V_72 > V_38 )
V_74 -> V_76 = V_38 - V_72 ;
if ( V_74 -> V_77 & 1 )
V_74 -> V_77 -= 1 ;
F_10 ( 2 , L_9 , V_26 -> V_57 ,
V_74 -> V_77 , V_74 -> V_76 , V_74 -> V_58 ,
V_74 -> V_59 , V_37 , V_38 ) ;
return 0 ;
}
static inline struct V_25 * F_15 ( struct V_86 * V_87 )
{
return F_16 ( V_87 , struct V_25 , V_87 ) ;
}
static inline struct V_25 * F_17 ( struct V_88 * V_89 )
{
return F_16 ( V_89 -> V_90 , struct V_25 , V_91 ) ;
}
void F_18 ( struct V_25 * V_26 , T_1 V_92 )
{
F_19 ( & V_26 -> V_93 ) ;
V_26 -> V_92 |= V_92 ;
F_20 ( & V_26 -> V_93 ) ;
}
static void F_21 ( struct V_25 * V_26 , T_1 V_92 )
{
F_19 ( & V_26 -> V_93 ) ;
V_26 -> V_92 &= ~ V_92 ;
F_20 ( & V_26 -> V_93 ) ;
}
static bool F_22 ( struct V_25 * V_26 , T_1 V_94 )
{
bool V_95 ;
F_19 ( & V_26 -> V_93 ) ;
V_95 = ( V_26 -> V_92 & V_94 ) == V_94 ;
F_20 ( & V_26 -> V_93 ) ;
return V_95 ;
}
static void F_23 ( struct V_96 * V_97 )
{
struct V_25 * V_26 = F_24 ( V_97 ) ;
F_19 ( & V_26 -> V_31 -> V_98 ) ;
}
static void F_25 ( struct V_96 * V_97 )
{
struct V_25 * V_26 = F_24 ( V_97 ) ;
F_20 ( & V_26 -> V_31 -> V_98 ) ;
}
static void F_26 ( struct V_67 * V_75 , int V_58 ,
int V_59 )
{
V_75 -> V_58 = V_58 ;
V_75 -> V_59 = V_59 ;
V_75 -> V_99 . V_58 = V_58 ;
V_75 -> V_99 . V_59 = V_59 ;
V_75 -> V_99 . V_77 = 0 ;
V_75 -> V_99 . V_76 = 0 ;
}
static int F_27 ( struct V_96 * V_100 , unsigned int V_101 )
{
struct V_25 * V_26 = V_100 -> V_102 ;
int V_95 ;
V_95 = F_28 ( & V_26 -> V_31 -> V_41 -> V_42 ) ;
if ( V_95 < 0 )
F_10 ( 1 , L_10 ,
V_26 -> V_57 , V_95 ) ;
return 0 ;
}
static void * F_29 ( struct V_25 * V_26 ,
enum V_68 type )
{
if ( F_2 ( type ) )
return F_30 ( V_26 -> V_103 ) ;
else
return F_31 ( V_26 -> V_103 ) ;
}
static void F_32 ( struct V_96 * V_100 )
{
struct V_25 * V_26 = V_100 -> V_102 ;
struct V_104 * V_105 ;
V_105 = F_29 ( V_26 , V_100 -> type ) ;
while ( V_105 != NULL ) {
F_33 ( F_34 ( V_105 ) , V_106 ) ;
V_105 = F_29 ( V_26 , V_100 -> type ) ;
}
F_35 ( & V_26 -> V_31 -> V_41 -> V_42 ) ;
}
static void F_36 ( void * V_107 )
{
}
static void F_37 ( struct V_25 * V_26 ,
struct V_104 * V_105 ,
struct V_67 * V_75 ,
struct V_108 * V_109 )
{
T_1 V_110 , V_111 , V_3 ;
V_110 = V_75 -> V_58 * V_75 -> V_59 ;
V_111 = F_38 ( T_1 , V_75 -> V_36 -> V_60 , F_3 ( V_109 -> V_109 ) ) ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ )
V_109 -> V_109 [ V_3 ] = F_39 ( V_105 , V_3 ) ;
if ( V_111 == 1 ) {
if ( V_75 -> V_36 -> V_2 == V_112 ) {
V_109 -> V_109 [ 1 ] = ( V_113 ) ( V_109 -> V_109 [ 0 ] + V_110 ) ;
V_109 -> V_109 [ 2 ] = ( V_113 ) ( V_109 -> V_109 [ 1 ] +
( V_110 >> 2 ) ) ;
} else {
F_14 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_11 ,
V_75 -> V_36 -> V_2 ) ;
}
}
F_10 ( 3 , L_12 ,
V_26 -> V_57 , V_111 , V_110 , ( void * ) V_109 -> V_109 [ 0 ] ,
( void * ) V_109 -> V_109 [ 1 ] , ( void * ) V_109 -> V_109 [ 2 ] ) ;
}
static void F_40 ( struct V_25 * V_26 )
{
struct V_67 * V_69 , * V_70 ;
struct V_104 * V_114 , * V_115 ;
struct V_116 * V_117 , * V_118 ;
V_69 = & V_26 -> V_69 ;
V_70 = & V_26 -> V_70 ;
V_114 = F_41 ( V_26 -> V_103 ) ;
F_37 ( V_26 , V_114 , V_69 , & V_69 -> V_109 ) ;
V_115 = F_42 ( V_26 -> V_103 ) ;
F_37 ( V_26 , V_115 , V_70 , & V_70 -> V_109 ) ;
V_117 = F_34 ( V_114 ) ;
V_118 = F_34 ( V_115 ) ;
V_118 -> V_119 . V_120 = V_117 -> V_119 . V_120 ;
}
static void F_43 ( void * V_107 , int V_121 )
{
struct V_29 * V_30 = V_107 ;
struct V_25 * V_26 ;
struct V_104 * V_114 , * V_115 ;
struct V_116 * V_117 = NULL , * V_118 = NULL ;
V_26 = F_44 ( V_30 -> V_122 ) ;
if ( ! V_26 )
return;
V_114 = F_30 ( V_26 -> V_103 ) ;
V_117 = F_34 ( V_114 ) ;
V_115 = F_31 ( V_26 -> V_103 ) ;
V_118 = F_34 ( V_115 ) ;
V_118 -> V_119 . V_120 = V_117 -> V_119 . V_120 ;
V_118 -> V_123 = V_117 -> V_123 ;
V_118 -> V_8 &= ~ V_124 ;
V_118 -> V_8 |= V_117 -> V_8 & V_124 ;
F_33 ( V_117 , V_121 ) ;
F_33 ( V_118 , V_121 ) ;
F_45 ( V_26 -> V_31 -> V_122 , V_26 -> V_103 ) ;
}
static void F_46 ( struct V_125 * V_126 )
{
struct V_25 * V_26 =
F_16 ( V_126 , struct V_25 , V_126 ) ;
struct V_29 * V_30 = V_26 -> V_31 ;
enum V_127 V_128 = V_106 ;
int V_95 ;
if ( F_22 ( V_26 , V_129 ) ) {
F_14 ( & V_30 -> V_41 -> V_42 , L_13 ) ;
goto V_130;
}
F_40 ( V_26 ) ;
F_47 ( V_26 , & V_26 -> V_69 . V_109 ) ;
F_48 ( V_26 , & V_26 -> V_70 . V_109 ) ;
F_49 ( V_26 ) ;
F_50 ( V_26 ) ;
F_51 ( V_26 ) ;
F_52 ( V_26 ) ;
F_53 ( V_26 ) ;
F_54 ( V_26 ) ;
V_95 = F_55 ( & V_26 -> V_131 ) ;
if ( V_95 ) {
F_14 ( & V_30 -> V_41 -> V_42 , L_14 , V_95 ) ;
goto V_130;
}
V_128 = V_132 ;
V_130:
F_43 ( V_30 , V_128 ) ;
}
static void F_56 ( void * V_107 )
{
struct V_25 * V_26 = V_107 ;
F_57 ( V_26 -> V_31 -> V_133 , & V_26 -> V_126 ) ;
}
static int F_58 ( struct V_96 * V_97 ,
unsigned int * V_134 , unsigned int * V_60 ,
unsigned int V_135 [] , struct V_136 * V_137 [] )
{
struct V_25 * V_26 = F_24 ( V_97 ) ;
struct V_67 * V_75 ;
int V_3 ;
V_75 = F_11 ( V_26 , V_97 -> type ) ;
* V_60 = V_75 -> V_36 -> V_60 ;
for ( V_3 = 0 ; V_3 < V_75 -> V_36 -> V_60 ; V_3 ++ )
V_135 [ V_3 ] = V_75 -> V_138 [ V_3 ] ;
F_10 ( 2 , L_15 ,
V_26 -> V_57 , V_97 -> type , * V_60 , * V_134 ,
V_135 [ 0 ] , V_135 [ 1 ] ) ;
return 0 ;
}
static int F_59 ( struct V_104 * V_105 )
{
struct V_25 * V_26 = F_24 ( V_105 -> V_96 ) ;
struct V_67 * V_75 ;
int V_3 ;
V_75 = F_11 ( V_26 , V_105 -> V_96 -> type ) ;
if ( ! F_2 ( V_105 -> V_96 -> type ) ) {
for ( V_3 = 0 ; V_3 < V_75 -> V_36 -> V_60 ; V_3 ++ )
F_60 ( V_105 , V_3 , V_75 -> V_138 [ V_3 ] ) ;
}
return 0 ;
}
static void F_61 ( struct V_104 * V_105 )
{
struct V_25 * V_26 = F_24 ( V_105 -> V_96 ) ;
F_62 ( V_26 -> V_103 , F_34 ( V_105 ) ) ;
}
static int F_63 ( struct V_139 * V_139 , void * V_87 ,
struct V_140 * V_141 )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
struct V_29 * V_30 = V_26 -> V_31 ;
F_64 ( V_141 -> V_142 , V_143 , sizeof( V_141 -> V_142 ) ) ;
F_64 ( V_141 -> V_144 , V_30 -> V_41 -> V_145 , sizeof( V_141 -> V_144 ) ) ;
F_64 ( V_141 -> V_146 , L_16 , sizeof( V_141 -> V_146 ) ) ;
return 0 ;
}
static int F_65 ( struct V_147 * V_28 , T_1 type )
{
const struct V_1 * V_36 ;
V_36 = F_4 ( V_28 -> V_9 , type ) ;
if ( ! V_36 )
return - V_78 ;
V_28 -> V_2 = V_36 -> V_2 ;
return 0 ;
}
static int F_66 ( struct V_139 * V_139 , void * V_107 ,
struct V_147 * V_28 )
{
return F_65 ( V_28 , V_148 ) ;
}
static int F_67 ( struct V_139 * V_139 , void * V_107 ,
struct V_147 * V_28 )
{
return F_65 ( V_28 , V_149 ) ;
}
static int F_68 ( struct V_139 * V_139 , void * V_87 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
struct V_67 * V_75 ;
struct V_34 * V_35 ;
int V_3 ;
F_10 ( 2 , L_17 , V_26 -> V_57 , V_28 -> type ) ;
V_75 = F_11 ( V_26 , V_28 -> type ) ;
V_35 = & V_28 -> V_36 . V_35 ;
V_35 -> V_58 = V_75 -> V_58 ;
V_35 -> V_59 = V_75 -> V_59 ;
V_35 -> V_43 = V_44 ;
V_35 -> V_2 = V_75 -> V_36 -> V_2 ;
V_35 -> V_60 = V_75 -> V_36 -> V_60 ;
V_35 -> V_45 = V_26 -> V_45 ;
V_35 -> V_46 = V_26 -> V_46 ;
V_35 -> V_47 = V_26 -> V_47 ;
V_35 -> V_48 = V_26 -> V_49 ;
F_10 ( 2 , L_18 , V_26 -> V_57 ,
V_35 -> V_58 , V_35 -> V_59 ) ;
for ( V_3 = 0 ; V_3 < V_35 -> V_60 ; ++ V_3 ) {
V_35 -> V_65 [ V_3 ] . V_66 = ( V_75 -> V_58 *
V_75 -> V_36 -> V_62 [ V_3 ] ) / 8 ;
V_35 -> V_65 [ V_3 ] . V_63 = ( V_75 -> V_58 *
V_75 -> V_59 * V_75 -> V_36 -> V_64 [ V_3 ] ) / 8 ;
F_10 ( 2 , L_19 , V_26 -> V_57 , V_3 ,
V_35 -> V_65 [ V_3 ] . V_66 ,
V_35 -> V_65 [ V_3 ] . V_63 ) ;
}
return 0 ;
}
static int F_69 ( struct V_139 * V_139 , void * V_87 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
if ( ! F_8 ( V_26 , V_28 ) )
return - V_78 ;
return 0 ;
}
static int F_70 ( struct V_139 * V_139 , void * V_87 ,
struct V_27 * V_28 )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
struct V_96 * V_97 ;
struct V_67 * V_75 ;
struct V_34 * V_35 ;
const struct V_1 * V_36 ;
int V_3 ;
F_10 ( 2 , L_17 , V_26 -> V_57 , V_28 -> type ) ;
V_75 = F_11 ( V_26 , V_28 -> type ) ;
V_36 = F_8 ( V_26 , V_28 ) ;
if ( ! V_36 ) {
F_71 ( L_20 , V_26 -> V_57 , V_28 -> type ) ;
return - V_78 ;
}
V_75 -> V_36 = V_36 ;
V_97 = F_72 ( V_26 -> V_103 , V_28 -> type ) ;
if ( F_73 ( V_97 ) ) {
F_74 ( & V_26 -> V_31 -> V_41 -> V_42 , L_21 , V_28 -> type ) ;
return - V_150 ;
}
V_35 = & V_28 -> V_36 . V_35 ;
for ( V_3 = 0 ; V_3 < V_75 -> V_36 -> V_60 ; V_3 ++ ) {
V_75 -> V_138 [ V_3 ] = V_35 -> V_65 [ V_3 ] . V_63 ;
V_75 -> V_151 [ V_3 ] = V_35 -> V_65 [ V_3 ] . V_66 ;
}
F_26 ( V_75 , V_35 -> V_58 , V_35 -> V_59 ) ;
if ( F_2 ( V_28 -> type ) ) {
V_26 -> V_45 = V_35 -> V_45 ;
V_26 -> V_46 = V_35 -> V_46 ;
V_26 -> V_47 = V_35 -> V_47 ;
V_26 -> V_49 = V_35 -> V_48 ;
}
if ( F_2 ( V_28 -> type ) )
F_18 ( V_26 , V_152 ) ;
else
F_18 ( V_26 , V_153 ) ;
F_10 ( 2 , L_22 , V_26 -> V_57 , V_28 -> type ,
V_75 -> V_58 , V_75 -> V_59 ) ;
return 0 ;
}
static int F_75 ( struct V_139 * V_139 , void * V_87 ,
struct V_154 * V_155 )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
if ( V_155 -> V_101 == 0 ) {
if ( V_155 -> type == V_149 )
F_21 ( V_26 , V_152 ) ;
else
F_21 ( V_26 , V_153 ) ;
}
return F_76 ( V_139 , V_26 -> V_103 , V_155 ) ;
}
static int F_77 ( struct V_139 * V_139 , void * V_87 ,
enum V_68 type )
{
struct V_25 * V_26 = F_15 ( V_87 ) ;
int V_95 ;
if ( F_2 ( type ) ) {
if ( ! F_22 ( V_26 , V_152 ) )
return - V_78 ;
} else if ( ! F_22 ( V_26 , V_153 ) ) {
return - V_78 ;
}
if ( ! F_22 ( V_26 , V_156 ) ) {
V_95 = F_78 ( & V_26 -> V_131 ) ;
if ( V_95 < 0 ) {
F_14 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_23 ,
V_95 ) ;
return - V_78 ;
}
F_18 ( V_26 , V_156 ) ;
}
return F_79 ( V_139 , V_26 -> V_103 , type ) ;
}
static inline bool F_80 ( T_1 V_157 )
{
if ( V_157 == V_158
|| V_157 == V_159
|| V_157 == V_160 )
return true ;
return false ;
}
static inline bool F_81 ( T_1 V_157 )
{
if ( V_157 == V_161
|| V_157 == V_162
|| V_157 == V_163 )
return true ;
return false ;
}
static int F_82 ( struct V_139 * V_139 , void * V_87 ,
struct V_164 * V_165 )
{
struct V_67 * V_75 ;
struct V_25 * V_26 = F_15 ( V_87 ) ;
bool V_166 = false ;
if ( V_165 -> type == V_167 ) {
if ( F_80 ( V_165 -> V_157 ) )
V_166 = true ;
} else if ( V_165 -> type == V_168 ) {
if ( F_81 ( V_165 -> V_157 ) )
V_166 = true ;
}
if ( ! V_166 ) {
F_10 ( 1 , L_24 , V_26 -> V_57 , V_165 -> type ,
V_165 -> V_157 ) ;
return - V_78 ;
}
V_75 = F_11 ( V_26 , V_165 -> type ) ;
switch ( V_165 -> V_157 ) {
case V_158 :
case V_159 :
case V_162 :
case V_161 :
V_165 -> V_74 . V_77 = 0 ;
V_165 -> V_74 . V_76 = 0 ;
V_165 -> V_74 . V_58 = V_75 -> V_58 ;
V_165 -> V_74 . V_59 = V_75 -> V_59 ;
return 0 ;
case V_160 :
case V_163 :
V_165 -> V_74 . V_77 = V_75 -> V_99 . V_77 ;
V_165 -> V_74 . V_76 = V_75 -> V_99 . V_76 ;
V_165 -> V_74 . V_58 = V_75 -> V_99 . V_58 ;
V_165 -> V_74 . V_59 = V_75 -> V_99 . V_59 ;
return 0 ;
}
return - V_78 ;
}
static int F_83 ( struct V_32 * V_169 , int V_170 ,
int V_171 , int V_172 , int V_173 , int V_174 )
{
int V_175 , V_176 ;
if ( V_174 == 90 || V_174 == 270 ) {
V_175 = V_173 ;
V_176 = V_172 ;
} else {
V_175 = V_172 ;
V_176 = V_173 ;
}
if ( ( V_170 / V_175 ) > V_169 -> V_177 ||
( V_171 / V_176 ) > V_169 -> V_178 ||
( V_175 / V_170 ) > V_169 -> V_179 ||
( V_176 / V_171 ) > V_169 -> V_180 )
return - V_78 ;
return 0 ;
}
static int F_84 ( struct V_139 * V_139 , void * V_87 ,
struct V_164 * V_165 )
{
struct V_67 * V_75 ;
struct V_25 * V_26 = F_15 ( V_87 ) ;
struct V_73 V_181 ;
struct V_32 * V_33 = V_26 -> V_31 -> V_33 ;
int V_95 ;
bool V_166 = false ;
if ( V_165 -> type == V_167 ) {
if ( V_165 -> V_157 == V_160 )
V_166 = true ;
} else if ( V_165 -> type == V_168 ) {
if ( V_165 -> V_157 == V_163 )
V_166 = true ;
}
if ( ! V_166 ) {
F_10 ( 1 , L_24 , V_26 -> V_57 , V_165 -> type ,
V_165 -> V_157 ) ;
return - V_78 ;
}
V_181 = V_165 -> V_74 ;
V_95 = F_13 ( V_26 , V_165 -> type , & V_181 ) ;
if ( V_95 )
return V_95 ;
if ( F_81 ( V_165 -> V_157 ) )
V_75 = & V_26 -> V_69 ;
else
V_75 = & V_26 -> V_70 ;
if ( F_22 ( V_26 , V_153 | V_152 ) ) {
if ( F_2 ( V_165 -> type ) ) {
V_95 = F_83 ( V_33 , V_181 . V_58 ,
V_181 . V_59 , V_26 -> V_70 . V_99 . V_58 ,
V_26 -> V_70 . V_99 . V_59 ,
V_26 -> V_81 . V_82 -> V_83 ) ;
} else {
V_95 = F_83 ( V_33 ,
V_26 -> V_69 . V_99 . V_58 ,
V_26 -> V_69 . V_99 . V_59 , V_181 . V_58 ,
V_181 . V_59 , V_26 -> V_81 . V_82 -> V_83 ) ;
}
if ( V_95 ) {
F_74 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_25 ) ;
return - V_78 ;
}
}
V_165 -> V_74 = V_181 ;
V_75 -> V_99 = V_181 ;
return 0 ;
}
static int F_85 ( void * V_107 , struct V_96 * V_182 ,
struct V_96 * V_183 )
{
struct V_25 * V_26 = V_107 ;
int V_95 ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> type = V_149 ;
V_182 -> V_184 = V_185 | V_186 ;
V_182 -> V_102 = V_26 ;
V_182 -> V_187 = & V_188 ;
V_182 -> V_189 = & V_190 ;
V_182 -> V_191 = sizeof( struct V_192 ) ;
V_182 -> V_193 = V_194 ;
V_182 -> V_42 = & V_26 -> V_31 -> V_41 -> V_42 ;
V_95 = F_86 ( V_182 ) ;
if ( V_95 )
return V_95 ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> type = V_148 ;
V_183 -> V_184 = V_185 | V_186 ;
V_183 -> V_102 = V_26 ;
V_183 -> V_187 = & V_188 ;
V_183 -> V_189 = & V_190 ;
V_183 -> V_191 = sizeof( struct V_192 ) ;
V_183 -> V_193 = V_194 ;
V_183 -> V_42 = & V_26 -> V_31 -> V_41 -> V_42 ;
return F_86 ( V_183 ) ;
}
static int F_87 ( struct V_88 * V_89 )
{
struct V_25 * V_26 = F_17 ( V_89 ) ;
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_32 * V_33 = V_30 -> V_33 ;
T_1 V_92 = V_153 | V_152 ;
int V_95 = 0 ;
if ( V_89 -> V_8 & V_195 )
return 0 ;
switch ( V_89 -> V_57 ) {
case V_196 :
V_26 -> V_197 = V_89 -> V_83 ;
break;
case V_198 :
V_26 -> V_199 = V_89 -> V_83 ;
break;
case V_200 :
if ( F_22 ( V_26 , V_92 ) ) {
V_95 = F_83 ( V_33 ,
V_26 -> V_69 . V_99 . V_58 ,
V_26 -> V_69 . V_99 . V_59 ,
V_26 -> V_70 . V_99 . V_58 ,
V_26 -> V_70 . V_99 . V_59 ,
V_26 -> V_81 . V_82 -> V_83 ) ;
if ( V_95 )
return - V_78 ;
}
V_26 -> V_201 = V_89 -> V_83 ;
break;
case V_202 :
V_26 -> V_70 . V_203 = V_89 -> V_83 ;
break;
}
return 0 ;
}
static int F_88 ( struct V_25 * V_26 )
{
F_89 ( & V_26 -> V_91 , V_204 ) ;
V_26 -> V_81 . V_82 = F_90 ( & V_26 -> V_91 ,
& V_205 , V_200 , 0 , 270 , 90 , 0 ) ;
V_26 -> V_81 . V_197 = F_90 ( & V_26 -> V_91 ,
& V_205 ,
V_196 ,
0 , 1 , 1 , 0 ) ;
V_26 -> V_81 . V_199 = F_90 ( & V_26 -> V_91 ,
& V_205 ,
V_198 ,
0 , 1 , 1 , 0 ) ;
V_26 -> V_81 . V_206 = F_90 ( & V_26 -> V_91 ,
& V_205 ,
V_202 ,
0 , 255 , 1 , 0 ) ;
V_26 -> V_207 = V_26 -> V_91 . error == 0 ;
if ( V_26 -> V_91 . error ) {
int V_208 = V_26 -> V_91 . error ;
F_91 ( & V_26 -> V_91 ) ;
F_14 ( & V_26 -> V_31 -> V_41 -> V_42 ,
L_26 ) ;
return V_208 ;
}
return 0 ;
}
static void F_92 ( struct V_25 * V_26 )
{
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_67 * V_75 ;
V_75 = F_11 ( V_26 , V_149 ) ;
V_75 -> V_36 = F_4 ( 0 ,
V_149 ) ;
V_75 -> V_58 = V_30 -> V_33 -> V_56 -> V_19 ;
V_75 -> V_59 = V_30 -> V_33 -> V_56 -> V_20 ;
V_75 -> V_138 [ 0 ] = V_75 -> V_58 * V_75 -> V_59 ;
V_75 -> V_138 [ 1 ] = V_75 -> V_138 [ 0 ] / 2 ;
V_75 = F_11 ( V_26 , V_148 ) ;
V_75 -> V_36 = F_4 ( 0 ,
V_148 ) ;
V_75 -> V_58 = V_30 -> V_33 -> V_56 -> V_52 ;
V_75 -> V_59 = V_30 -> V_33 -> V_56 -> V_53 ;
V_75 -> V_138 [ 0 ] = V_75 -> V_58 * V_75 -> V_59 ;
V_75 -> V_138 [ 1 ] = V_75 -> V_138 [ 0 ] / 2 ;
}
static int F_93 ( struct V_139 * V_139 )
{
struct V_29 * V_30 = F_94 ( V_139 ) ;
struct V_209 * V_210 = F_95 ( V_139 ) ;
struct V_25 * V_26 = NULL ;
int V_95 ;
V_26 = F_96 ( sizeof( * V_26 ) , V_211 ) ;
if ( ! V_26 )
return - V_212 ;
if ( F_97 ( & V_30 -> V_98 ) ) {
V_95 = - V_213 ;
goto V_214;
}
F_98 ( & V_26 -> V_93 ) ;
V_26 -> V_57 = V_30 -> V_215 ++ ;
F_99 ( & V_26 -> V_87 , V_210 ) ;
V_139 -> V_216 = & V_26 -> V_87 ;
V_95 = F_88 ( V_26 ) ;
if ( V_95 )
goto V_217;
V_26 -> V_87 . V_91 = & V_26 -> V_91 ;
F_100 ( & V_26 -> V_87 ) ;
F_101 ( & V_26 -> V_218 ) ;
V_26 -> V_31 = V_30 ;
F_92 ( V_26 ) ;
F_102 ( & V_26 -> V_126 , F_46 ) ;
V_26 -> V_103 = F_103 ( V_30 -> V_122 , V_26 ,
F_85 ) ;
if ( F_104 ( V_26 -> V_103 ) ) {
F_14 ( & V_30 -> V_41 -> V_42 , L_27 ) ;
V_95 = F_105 ( V_26 -> V_103 ) ;
goto V_219;
}
V_26 -> V_87 . V_103 = V_26 -> V_103 ;
if ( V_30 -> V_220 ++ == 0 ) {
V_95 = F_106 ( V_30 -> V_221 ) ;
if ( V_95 < 0 ) {
F_14 ( & V_30 -> V_41 -> V_42 ,
L_28 , V_95 ) ;
goto V_222;
}
V_95 = F_107 ( V_30 -> V_41 ) ;
if ( V_95 < 0 ) {
F_14 ( & V_30 -> V_41 -> V_42 ,
L_29 , V_95 ) ;
goto V_222;
}
}
F_108 ( & V_26 -> V_218 , & V_30 -> V_223 ) ;
F_20 ( & V_30 -> V_98 ) ;
F_10 ( 0 , L_30 , F_109 ( & V_30 -> V_41 -> V_42 ) , V_26 -> V_57 ) ;
return 0 ;
V_222:
V_30 -> V_220 -- ;
F_110 ( V_26 -> V_103 ) ;
V_219:
F_91 ( & V_26 -> V_91 ) ;
V_217:
F_111 ( & V_26 -> V_87 ) ;
F_112 ( & V_26 -> V_87 ) ;
F_20 ( & V_30 -> V_98 ) ;
V_214:
F_113 ( V_26 ) ;
return V_95 ;
}
static int F_114 ( struct V_139 * V_139 )
{
struct V_25 * V_26 = F_15 ( V_139 -> V_216 ) ;
struct V_29 * V_30 = V_26 -> V_31 ;
F_115 ( V_30 -> V_133 ) ;
F_19 ( & V_30 -> V_98 ) ;
F_110 ( V_26 -> V_103 ) ;
F_91 ( & V_26 -> V_91 ) ;
F_111 ( & V_26 -> V_87 ) ;
F_112 ( & V_26 -> V_87 ) ;
F_116 ( & V_26 -> V_131 ) ;
V_30 -> V_220 -- ;
F_117 ( & V_26 -> V_218 ) ;
F_10 ( 0 , L_30 , F_109 ( & V_30 -> V_41 -> V_42 ) , V_26 -> V_57 ) ;
F_20 ( & V_30 -> V_98 ) ;
F_113 ( V_26 ) ;
return 0 ;
}
int F_118 ( struct V_29 * V_30 )
{
struct V_136 * V_42 = & V_30 -> V_41 -> V_42 ;
int V_95 ;
V_30 -> V_33 = & V_224 ;
V_30 -> V_225 = F_119 () ;
if ( ! V_30 -> V_225 ) {
F_14 ( V_42 , L_31 ) ;
V_95 = - V_212 ;
goto V_226;
}
V_30 -> V_225 -> V_227 = V_228 | V_229 ;
V_30 -> V_225 -> V_230 = & V_231 ;
V_30 -> V_225 -> V_232 = & V_233 ;
V_30 -> V_225 -> V_234 = V_235 ;
V_30 -> V_225 -> V_98 = & V_30 -> V_98 ;
V_30 -> V_225 -> V_236 = V_237 ;
V_30 -> V_225 -> V_238 = & V_30 -> V_238 ;
snprintf ( V_30 -> V_225 -> V_145 , sizeof( V_30 -> V_225 -> V_145 ) , L_32 ,
V_143 ) ;
F_120 ( V_30 -> V_225 , V_30 ) ;
V_30 -> V_122 = F_121 ( & V_239 ) ;
if ( F_104 ( V_30 -> V_122 ) ) {
F_14 ( V_42 , L_33 ) ;
V_95 = F_105 ( V_30 -> V_122 ) ;
goto V_240;
}
V_95 = F_122 ( V_30 -> V_225 , V_241 , 2 ) ;
if ( V_95 ) {
F_14 ( V_42 , L_34 ) ;
goto V_242;
}
F_123 ( & V_30 -> V_238 , L_35 ,
V_30 -> V_225 -> V_10 ) ;
return 0 ;
V_242:
F_124 ( V_30 -> V_122 ) ;
V_240:
V_235 ( V_30 -> V_225 ) ;
V_226:
return V_95 ;
}
void F_125 ( struct V_29 * V_30 )
{
F_126 ( V_30 -> V_225 ) ;
F_124 ( V_30 -> V_122 ) ;
}
