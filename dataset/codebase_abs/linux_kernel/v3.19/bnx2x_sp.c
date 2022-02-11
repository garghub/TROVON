static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
union V_6 * V_7 ,
T_1 V_8 ,
T_2 remove ,
T_3 V_9 ,
T_4 V_10 ,
T_5 V_11 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_2 ( & V_4 -> V_12 ) ;
F_2 ( & V_4 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
V_4 -> V_15 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> remove = remove ;
V_4 -> V_9 = V_9 ;
V_4 -> V_16 = V_10 ;
V_4 -> V_11 = V_11 ;
F_4 ( V_17 , L_1 ,
V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
F_4 ( V_17 , L_2 ) ;
F_6 ( V_19 ) ;
}
static inline int F_7 ( struct V_3 * V_4 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
F_8 ( & V_4 -> V_14 ) ;
F_9 (elem, &o->exe_queue, link)
V_20 ++ ;
F_10 ( & V_4 -> V_14 ) ;
return V_20 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_19 ,
bool V_21 )
{
int V_22 ;
F_8 ( & V_4 -> V_14 ) ;
if ( ! V_21 ) {
V_22 = V_4 -> V_9 ( V_2 , V_4 -> V_7 , V_19 ) ;
if ( V_22 )
goto V_23;
V_22 = V_4 -> V_8 ( V_2 , V_4 -> V_7 , V_19 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_3 , V_22 ) ;
goto V_23;
}
}
F_12 ( & V_19 -> V_24 , & V_4 -> V_12 ) ;
F_10 ( & V_4 -> V_14 ) ;
return 0 ;
V_23:
F_5 ( V_2 , V_19 ) ;
F_10 ( & V_4 -> V_14 ) ;
return V_22 ;
}
static inline void F_13 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 ;
while ( ! F_14 ( & V_4 -> V_13 ) ) {
V_19 = F_15 ( & V_4 -> V_13 ,
struct V_18 , V_24 ) ;
F_16 ( & V_19 -> V_24 ) ;
F_5 ( V_2 , V_19 ) ;
}
}
static inline int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_25 )
{
struct V_18 * V_19 , V_26 ;
int V_27 = 0 , V_22 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( ! F_14 ( & V_4 -> V_13 ) ) {
if ( F_18 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_4 ) ;
F_13 ( V_2 , V_4 ) ;
} else {
return 1 ;
}
}
while ( ! F_14 ( & V_4 -> V_12 ) ) {
V_19 = F_15 ( & V_4 -> V_12 , struct V_18 ,
V_24 ) ;
F_19 ( ! V_19 -> V_29 ) ;
if ( V_27 + V_19 -> V_29 <= V_4 -> V_15 ) {
V_27 += V_19 -> V_29 ;
F_12 ( & V_26 . V_24 , & V_4 -> V_13 ) ;
F_20 () ;
F_21 ( & V_19 -> V_24 , & V_4 -> V_13 ) ;
F_16 ( & V_26 . V_24 ) ;
} else
break;
}
if ( ! V_27 )
return 0 ;
V_22 = V_4 -> V_16 ( V_2 , V_4 -> V_7 , & V_4 -> V_13 , V_25 ) ;
if ( V_22 < 0 )
F_22 ( & V_4 -> V_13 , & V_4 -> V_12 ) ;
else if ( ! V_22 )
F_13 ( V_2 , V_4 ) ;
return V_22 ;
}
static inline bool F_23 ( struct V_3 * V_4 )
{
bool V_30 = F_14 ( & V_4 -> V_12 ) ;
F_20 () ;
return V_30 && F_14 ( & V_4 -> V_13 ) ;
}
static inline struct V_18 * F_24 (
struct V_1 * V_2 )
{
F_4 ( V_17 , L_5 ) ;
return F_25 ( sizeof( struct V_18 ) , V_31 ) ;
}
static bool F_26 ( struct V_32 * V_4 )
{
return ! ! F_18 ( V_4 -> V_33 , V_4 -> V_34 ) ;
}
static void F_27 ( struct V_32 * V_4 )
{
F_28 () ;
F_29 ( V_4 -> V_33 , V_4 -> V_34 ) ;
F_30 () ;
}
static void F_31 ( struct V_32 * V_4 )
{
F_28 () ;
F_32 ( V_4 -> V_33 , V_4 -> V_34 ) ;
F_30 () ;
}
static inline int F_33 ( struct V_1 * V_2 , int V_33 ,
unsigned long * V_34 )
{
int V_20 = 5000 ;
if ( F_34 ( V_2 ) )
V_20 *= 20 ;
F_4 ( V_17 , L_6 , V_33 ) ;
F_35 () ;
while ( V_20 -- ) {
if ( ! F_18 ( V_33 , V_34 ) ) {
#ifdef F_36
F_4 ( V_17 , L_7 , 5000 - V_20 ) ;
#endif
return 0 ;
}
F_37 ( 1000 , 2000 ) ;
if ( V_2 -> V_35 )
return - V_36 ;
}
F_38 ( L_8 , V_33 ) ;
#ifdef F_36
F_39 () ;
#endif
return - V_37 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_32 * V_38 )
{
return F_33 ( V_2 , V_38 -> V_33 , V_38 -> V_34 ) ;
}
static bool F_41 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_19 ( ! V_42 ) ;
return V_42 -> V_44 ( V_42 , V_40 ) ;
}
static bool F_42 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_19 ( ! V_42 ) ;
return V_42 -> V_11 ( V_42 , 1 ) ;
}
static bool F_43 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_19 ( ! V_45 ) ;
return V_45 -> V_44 ( V_45 , V_40 ) ;
}
static bool F_44 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_19 ( ! V_45 ) ;
return V_45 -> V_11 ( V_45 , 1 ) ;
}
static bool F_45 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_47 ( V_42 , V_40 ) ;
}
static bool F_46 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_48 ( V_42 , 1 ) ;
}
static bool F_47 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_47 ( V_45 , V_40 ) ;
}
static bool F_48 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_48 ( V_45 , 1 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
if ( V_4 -> V_49 ) {
F_4 ( V_17 , L_9 ) ;
return - V_37 ;
}
F_4 ( V_17 , L_10 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_22 ;
unsigned long V_25 = V_4 -> V_50 ;
F_4 ( V_17 , L_11 ,
V_25 ) ;
V_4 -> V_51 = false ;
V_4 -> V_50 = 0 ;
V_22 = F_17 ( V_2 , & V_4 -> V_12 , & V_25 ) ;
if ( V_22 != 0 ) {
F_38 ( L_12 ,
V_22 ) ;
#ifdef F_36
F_39 () ;
#endif
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long V_25 )
{
V_4 -> V_51 = true ;
V_4 -> V_50 = V_25 ;
F_4 ( V_17 , L_13 ,
V_25 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
while ( V_4 -> V_51 ) {
F_4 ( V_17 , L_14 ) ;
F_50 ( V_2 , V_4 ) ;
}
}
static int F_53 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
V_4 -> V_49 ++ ;
F_4 ( V_17 , L_15 ,
V_4 -> V_49 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_22 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
V_22 = F_53 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
return V_22 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
if ( ! V_4 -> V_49 ) {
F_38 ( L_16 ) ;
#ifdef F_36
F_39 () ;
#endif
} else {
V_4 -> V_49 -- ;
F_4 ( V_17 , L_17 ,
V_4 -> V_49 ) ;
}
if ( ! V_4 -> V_49 && V_4 -> V_51 ) {
F_4 ( V_17 , L_18 ) ;
F_52 ( V_2 , V_4 ) ;
}
}
void F_56 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_55 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_39 * V_4 ,
int V_52 , T_6 * V_53 , T_6 V_54 , T_6 V_55 )
{
struct V_56 * V_57 ;
T_6 * V_58 = V_53 ;
int V_59 = 0 ;
int V_60 ;
F_4 ( V_17 , L_19 ) ;
V_60 = F_54 ( V_2 , V_4 ) ;
if ( V_60 != 0 )
F_38 ( L_20 ) ;
F_9 (pos, &o->head, link) {
if ( V_59 < V_52 ) {
memcpy ( V_58 , & V_57 -> V_61 , V_55 ) ;
V_59 ++ ;
F_4 ( V_17 , L_21 ,
V_59 , V_58 ) ;
V_58 += V_54 + V_55 ;
}
}
if ( V_60 == 0 ) {
F_4 ( V_17 , L_22 ) ;
F_56 ( V_2 , V_4 ) ;
}
return V_59 * V_62 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_23 , V_64 -> V_65 . V_65 ) ;
if ( ! F_59 ( V_64 -> V_65 . V_65 ) )
return - V_66 ;
F_9 (pos, &o->head, link)
if ( F_60 ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 ) &&
( V_64 -> V_65 . V_67 == V_57 -> V_61 . V_65 . V_67 ) )
return - V_68 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_24 , V_64 -> V_69 . V_69 ) ;
F_9 (pos, &o->head, link)
if ( V_64 -> V_69 . V_69 == V_57 -> V_61 . V_69 . V_69 )
return - V_68 ;
return 0 ;
}
static struct V_56 *
F_62 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_25 , V_64 -> V_65 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( F_60 ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 ) &&
( V_64 -> V_65 . V_67 == V_57 -> V_61 . V_65 . V_67 ) )
return V_57 ;
return NULL ;
}
static struct V_56 *
F_63 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_26 , V_64 -> V_69 . V_69 ) ;
F_9 (pos, &o->head, link)
if ( V_64 -> V_69 . V_69 == V_57 -> V_61 . V_69 . V_69 )
return V_57 ;
return NULL ;
}
static bool F_64 ( struct V_1 * V_2 ,
struct V_39 * V_70 ,
struct V_39 * V_71 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
int V_22 ;
V_57 = V_70 -> V_72 ( V_2 , V_70 , V_64 ) ;
V_22 = V_71 -> V_73 ( V_2 , V_71 , V_64 ) ;
if ( V_22 || ! V_57 )
return false ;
return true ;
}
static bool F_65 (
struct V_1 * V_2 ,
struct V_39 * V_70 ,
struct V_39 * V_71 ,
union V_63 * V_64 )
{
return false ;
}
static inline T_6 F_66 ( struct V_39 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_74 = 0 ;
if ( ( V_38 -> V_75 == V_76 ) ||
( V_38 -> V_75 == V_77 ) )
V_74 |= V_78 ;
if ( ( V_38 -> V_75 == V_79 ) ||
( V_38 -> V_75 == V_77 ) )
V_74 |= V_80 ;
return V_74 ;
}
static void F_67 ( struct V_1 * V_2 ,
bool V_81 , unsigned char * V_82 , int V_83 )
{
T_7 V_84 [ 2 ] ;
T_7 V_85 = F_68 ( V_2 ) ? V_86 :
V_87 ;
if ( ! F_69 ( V_2 ) && ! F_70 ( V_2 ) )
return;
if ( V_83 > V_88 )
return;
F_4 ( V_17 , L_27 ,
( V_81 ? L_28 : L_29 ) , V_83 ) ;
if ( V_81 ) {
V_85 += 8 * V_83 ;
V_84 [ 0 ] = ( ( V_82 [ 2 ] << 24 ) | ( V_82 [ 3 ] << 16 ) |
( V_82 [ 4 ] << 8 ) | V_82 [ 5 ] ) ;
V_84 [ 1 ] = ( ( V_82 [ 0 ] << 8 ) | V_82 [ 1 ] ) ;
F_71 ( V_2 , V_85 , V_84 , 2 ) ;
}
F_72 ( V_2 , ( F_68 ( V_2 ) ? V_89 :
V_90 ) + 4 * V_83 , V_81 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_81 , int V_91 ,
struct V_92 * V_93 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_93 -> V_94 = V_38 -> V_95 ;
V_93 -> V_96 = V_38 -> V_96 ;
V_93 -> V_97 |=
F_66 ( V_4 ) ;
if ( V_81 )
V_93 -> V_97 |= V_98 ;
V_93 -> V_97 |=
( V_91 << V_99 ) ;
}
static inline void F_74 ( T_7 V_100 , int type ,
struct V_101 * V_93 , int V_102 )
{
V_93 -> V_103 = F_75 ( ( V_100 & V_104 ) |
( type << V_105 ) ) ;
V_93 -> V_102 = ( T_6 ) V_102 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_106 ,
int V_107 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_108 * V_64 =
(struct V_108 * ) ( V_38 -> V_109 ) ;
int V_102 = V_106 + 1 , V_110 = V_19 -> V_111 . V_112 . V_110 ;
union V_113 * V_114 = & V_64 -> V_115 [ V_106 ] ;
bool V_81 = ( V_110 == V_116 ) ? true : false ;
unsigned long * V_117 = & V_19 -> V_111 . V_112 . V_117 ;
T_6 * V_65 = V_19 -> V_111 . V_112 . V_61 . V_65 . V_65 ;
if ( V_110 != V_118 ) {
if ( F_18 ( V_119 , V_117 ) )
F_67 ( V_2 , V_81 , V_65 ,
V_120 ) ;
else if ( F_18 ( V_121 , V_117 ) )
F_67 ( V_2 , V_81 , V_65 ,
V_122 ) ;
}
if ( V_106 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_73 ( V_2 , V_4 , V_81 , V_123 ,
& V_114 -> V_65 . V_124 ) ;
F_4 ( V_17 , L_30 ,
( V_81 ? L_31 : L_32 ) , V_65 , V_38 -> V_95 ) ;
F_77 ( & V_114 -> V_65 . V_125 ,
& V_114 -> V_65 . V_126 ,
& V_114 -> V_65 . V_127 , V_65 ) ;
V_114 -> V_65 . V_128 =
F_78 ( V_19 -> V_111 . V_112 . V_61 . V_65 . V_67 ) ;
if ( V_110 == V_118 ) {
V_114 ++ ;
V_102 ++ ;
F_73 ( V_2 ,
V_19 -> V_111 . V_112 . V_129 ,
true , V_123 ,
& V_114 -> V_65 . V_124 ) ;
F_77 ( & V_114 -> V_65 . V_125 ,
& V_114 -> V_65 . V_126 ,
& V_114 -> V_65 . V_127 , V_65 ) ;
V_114 -> V_65 . V_128 =
F_78 ( V_19 -> V_111 . V_112 .
V_61 . V_65 . V_67 ) ;
}
F_74 ( V_38 -> V_100 , V_38 -> V_33 , & V_64 -> V_124 ,
V_102 ) ;
}
static inline void F_79 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_107 ,
struct V_130 * V_93 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
V_93 -> V_132 = 1 ;
V_93 -> V_40 = ( T_6 ) V_107 ;
V_93 -> V_94 = F_78 ( 0xff ) ;
V_93 -> V_103 = F_75 ( ( V_131 -> V_100 & V_104 ) |
( type << V_105 ) ) ;
}
static inline void F_80 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_81 , int V_91 , T_6 * V_65 ,
T_8 V_133 , struct V_134 * V_135 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
T_7 V_136 = ( 1 << V_131 -> V_95 ) ;
V_135 -> V_137 = F_75 ( V_136 ) ;
V_135 -> V_138 = V_131 -> V_96 ;
V_135 -> V_133 = F_78 ( V_133 ) ;
if ( V_81 ) {
F_81 ( V_135 -> V_139 , V_140 ,
V_141 ) ;
F_81 ( V_135 -> V_139 ,
V_142 , V_91 ) ;
F_77 ( & V_135 -> V_143 ,
& V_135 -> V_144 ,
& V_135 -> V_145 , V_65 ) ;
} else
F_81 ( V_135 -> V_139 , V_140 ,
V_146 ) ;
}
static inline void F_82 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_107 , bool V_81 ,
T_6 * V_65 , T_8 V_133 , int V_91 , struct V_147 * V_148 )
{
struct V_134 * V_135 = & V_148 -> V_149 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_79 ( V_2 , V_4 , type , V_107 ,
& V_148 -> V_93 ) ;
F_80 ( V_2 , V_4 , V_81 , V_91 , V_65 , V_133 ,
V_135 ) ;
F_4 ( V_17 , L_33 ,
( V_81 ? L_34 : L_35 ) ,
V_65 , V_38 -> V_95 , V_107 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_106 ,
int V_107 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_148 =
(struct V_147 * ) ( V_38 -> V_109 ) ;
bool V_81 = ( V_19 -> V_111 . V_112 . V_110 == V_116 ) ?
true : false ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
F_82 ( V_2 , V_4 , V_38 -> V_33 ,
V_107 , V_81 ,
V_19 -> V_111 . V_112 . V_61 . V_65 . V_65 , 0 ,
V_150 , V_148 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_106 ,
int V_107 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_108 * V_64 =
(struct V_108 * ) ( V_38 -> V_109 ) ;
int V_102 = V_106 + 1 ;
union V_113 * V_114 = & V_64 -> V_115 [ V_106 ] ;
enum V_151 V_110 = V_19 -> V_111 . V_112 . V_110 ;
bool V_81 = ( V_110 == V_116 ) ? true : false ;
T_8 V_69 = V_19 -> V_111 . V_112 . V_61 . V_69 . V_69 ;
if ( V_106 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_73 ( V_2 , V_4 , V_81 , V_152 ,
& V_114 -> V_69 . V_124 ) ;
F_4 ( V_17 , L_36 , ( V_81 ? L_31 : L_32 ) ,
V_69 ) ;
V_114 -> V_69 . V_69 = F_78 ( V_69 ) ;
if ( V_110 == V_118 ) {
V_114 ++ ;
V_102 ++ ;
F_73 ( V_2 ,
V_19 -> V_111 . V_112 . V_129 ,
true , V_152 ,
& V_114 -> V_69 . V_124 ) ;
V_114 -> V_69 . V_69 = F_78 ( V_69 ) ;
}
F_74 ( V_38 -> V_100 , V_38 -> V_33 , & V_64 -> V_124 ,
V_102 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
struct V_56 * * V_155 )
{
struct V_56 * V_57 ;
struct V_39 * V_4 = V_154 -> V_156 ;
if ( F_14 ( & V_4 -> V_157 ) ) {
* V_155 = NULL ;
return 0 ;
}
if ( * V_155 == NULL )
* V_155 = F_15 ( & V_4 -> V_157 ,
struct V_56 ,
V_24 ) ;
else
* V_155 = F_86 ( * V_155 , V_24 ) ;
V_57 = * V_155 ;
if ( F_87 ( & V_57 -> V_24 , & V_4 -> V_157 ) )
* V_155 = NULL ;
memcpy ( & V_154 -> V_158 . V_61 , & V_57 -> V_61 , sizeof( V_57 -> V_61 ) ) ;
V_154 -> V_158 . V_110 = V_116 ;
V_154 -> V_158 . V_117 = V_57 -> V_117 ;
F_88 ( V_159 , & V_154 -> V_25 ) ;
return F_89 ( V_2 , V_154 ) ;
}
static struct V_18 * F_90 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_57 ;
struct V_160 * V_64 = & V_19 -> V_111 . V_112 . V_61 . V_65 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_57 -> V_111 . V_112 . V_61 . V_65 , V_64 ,
sizeof( * V_64 ) ) &&
( V_57 -> V_111 . V_112 . V_110 == V_19 -> V_111 . V_112 . V_110 ) )
return V_57 ;
return NULL ;
}
static struct V_18 * F_91 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_57 ;
struct V_161 * V_64 = & V_19 -> V_111 . V_112 . V_61 . V_69 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_57 -> V_111 . V_112 . V_61 . V_69 , V_64 ,
sizeof( * V_64 ) ) &&
( V_57 -> V_111 . V_112 . V_110 == V_19 -> V_111 . V_112 . V_110 ) )
return V_57 ;
return NULL ;
}
static inline int F_92 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_162 -> V_112 ;
struct V_3 * V_163 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_73 ( V_2 , V_4 , & V_19 -> V_111 . V_112 . V_61 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_37 ) ;
return V_22 ;
}
if ( V_163 -> V_11 ( V_163 , V_19 ) ) {
F_4 ( V_17 , L_38 ) ;
return - V_68 ;
}
if ( ! ( F_18 ( V_164 ,
& V_19 -> V_111 . V_112 . V_117 ) ||
V_4 -> V_165 ( V_4 ) ) )
return - V_66 ;
return 0 ;
}
static inline int F_93 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_162 -> V_112 ;
struct V_56 * V_57 ;
struct V_3 * V_163 = & V_4 -> V_12 ;
struct V_18 V_166 ;
V_57 = V_4 -> V_72 ( V_2 , V_4 , & V_19 -> V_111 . V_112 . V_61 ) ;
if ( ! V_57 ) {
F_4 ( V_17 , L_39 ) ;
return - V_68 ;
}
memcpy ( & V_166 , V_19 , sizeof( V_166 ) ) ;
V_166 . V_111 . V_112 . V_110 = V_118 ;
if ( V_163 -> V_11 ( V_163 , & V_166 ) ) {
F_38 ( L_40 ) ;
return - V_66 ;
}
if ( V_163 -> V_11 ( V_163 , V_19 ) ) {
F_4 ( V_17 , L_41 ) ;
return - V_68 ;
}
if ( ! ( F_18 ( V_164 ,
& V_19 -> V_111 . V_112 . V_117 ) ||
V_4 -> V_167 ( V_4 ) ) ) {
F_38 ( L_42 ) ;
return - V_66 ;
}
return 0 ;
}
static inline int F_94 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
struct V_39 * V_70 = & V_162 -> V_112 ;
struct V_39 * V_168 = V_19 -> V_111 . V_112 . V_129 ;
struct V_18 V_166 ;
struct V_3 * V_169 = & V_70 -> V_12 ;
struct V_3 * V_170 = & V_168 -> V_12 ;
if ( ! V_70 -> V_171 ( V_2 , V_70 , V_168 ,
& V_19 -> V_111 . V_112 . V_61 ) ) {
F_4 ( V_17 , L_43 ) ;
return - V_66 ;
}
memcpy ( & V_166 , V_19 , sizeof( V_166 ) ) ;
V_166 . V_111 . V_112 . V_110 = V_172 ;
if ( V_169 -> V_11 ( V_169 , & V_166 ) ) {
F_38 ( L_44 ) ;
return - V_66 ;
}
if ( V_169 -> V_11 ( V_169 , V_19 ) ) {
F_4 ( V_17 , L_40 ) ;
return - V_68 ;
}
V_166 . V_111 . V_112 . V_110 = V_116 ;
if ( V_170 -> V_11 ( V_170 , & V_166 ) ) {
F_38 ( L_45 ) ;
return - V_66 ;
}
if ( ! ( F_18 ( V_173 ,
& V_19 -> V_111 . V_112 . V_117 ) ||
V_168 -> V_165 ( V_168 ) ) )
return - V_66 ;
if ( ! ( F_18 ( V_164 ,
& V_19 -> V_111 . V_112 . V_117 ) ||
V_70 -> V_167 ( V_70 ) ) ) {
V_168 -> V_167 ( V_168 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_111 . V_112 . V_110 ) {
case V_116 :
return F_92 ( V_2 , V_162 , V_19 ) ;
case V_172 :
return F_93 ( V_2 , V_162 , V_19 ) ;
case V_118 :
return F_94 ( V_2 , V_162 , V_19 ) ;
default:
return - V_66 ;
}
}
static int F_96 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_18 ( V_164 ,
& V_19 -> V_111 . V_112 . V_117 ) )
return 0 ;
switch ( V_19 -> V_111 . V_112 . V_110 ) {
case V_116 :
case V_118 :
V_22 = V_162 -> V_112 . V_167 ( & V_162 -> V_112 ) ;
break;
case V_172 :
V_22 = V_162 -> V_112 . V_165 ( & V_162 -> V_112 ) ;
break;
default:
return - V_66 ;
}
if ( V_22 != true )
return - V_66 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_163 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_174 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_23 ( V_163 ) )
F_37 ( 1000 , 2000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_25 )
{
int V_22 = 0 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_4 ( V_17 , L_46 ) ;
V_22 = F_49 ( V_2 , V_4 ) ;
if ( V_22 != 0 ) {
F_51 ( V_2 , V_4 , * V_25 ) ;
V_22 = 1 ;
} else {
V_22 = F_17 ( V_2 , & V_4 -> V_12 , V_25 ) ;
}
F_10 ( & V_4 -> V_12 . V_14 ) ;
return V_22 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_175 * V_176 ,
unsigned long * V_25 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_13 ( V_2 , & V_4 -> V_12 ) ;
V_131 -> V_177 ( V_131 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
if ( V_176 -> V_178 . error )
return - V_66 ;
if ( F_18 ( V_179 , V_25 ) ) {
V_22 = F_98 ( V_2 , V_4 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_23 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_18 * V_19 )
{
struct V_18 V_180 , * V_57 ;
struct V_39 * V_4 = & V_162 -> V_112 ;
struct V_3 * V_163 = & V_4 -> V_12 ;
memcpy ( & V_180 , V_19 , sizeof( V_180 ) ) ;
switch ( V_19 -> V_111 . V_112 . V_110 ) {
case V_116 :
V_180 . V_111 . V_112 . V_110 = V_172 ;
break;
case V_172 :
V_180 . V_111 . V_112 . V_110 = V_116 ;
break;
default:
return 0 ;
}
V_57 = V_163 -> V_11 ( V_163 , & V_180 ) ;
if ( V_57 ) {
if ( ! F_18 ( V_164 ,
& V_57 -> V_111 . V_112 . V_117 ) ) {
if ( ( V_180 . V_111 . V_112 . V_110 ==
V_116 ) && ! V_4 -> V_167 ( V_4 ) ) {
F_38 ( L_47 ) ;
return - V_66 ;
} else if ( ! V_4 -> V_165 ( V_4 ) ) {
F_38 ( L_48 ) ;
return - V_66 ;
}
}
F_4 ( V_17 , L_49 ,
( V_19 -> V_111 . V_112 . V_110 == V_116 ) ?
L_28 : L_50 ) ;
F_16 ( & V_57 -> V_24 ) ;
F_5 ( V_2 , V_57 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_101 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_56 * * V_181 )
{
enum V_151 V_110 = V_19 -> V_111 . V_112 . V_110 ;
struct V_56 * V_182 ;
if ( ! V_21 &&
( ( V_110 == V_116 ) || ( V_110 == V_118 ) ) ) {
V_182 = F_25 ( sizeof( * V_182 ) , V_31 ) ;
if ( ! V_182 )
return - V_183 ;
if ( ! V_4 -> V_184 ( V_4 , & V_182 -> V_107 ) ) {
F_19 ( 1 ) ;
F_6 ( V_182 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_51 , V_182 -> V_107 ) ;
memcpy ( & V_182 -> V_61 , & V_19 -> V_111 . V_112 . V_61 ,
sizeof( V_182 -> V_61 ) ) ;
V_182 -> V_117 =
V_19 -> V_111 . V_112 . V_117 ;
} else
V_182 = V_4 -> V_72 ( V_2 , V_4 , & V_19 -> V_111 . V_112 . V_61 ) ;
* V_181 = V_182 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
union V_6 * V_162 ,
struct V_185 * V_186 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_162 -> V_112 , * V_187 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 , V_188 = 0 ;
bool V_21 = F_18 ( V_159 , V_25 ) ;
bool V_189 = F_18 ( V_28 , V_25 ) ;
struct V_56 * V_182 ;
enum V_151 V_110 ;
if ( ! V_189 ) {
F_19 ( V_131 -> V_190 ( V_131 ) ) ;
V_131 -> V_191 ( V_131 ) ;
F_9 (elem, exe_chunk, link) {
V_110 = V_19 -> V_111 . V_112 . V_110 ;
if ( V_110 == V_118 )
V_187 = V_19 -> V_111 . V_112 . V_129 ;
else
V_187 = V_4 ;
V_22 = F_101 ( V_2 , V_187 ,
V_19 , V_21 ,
& V_182 ) ;
if ( V_22 )
goto V_192;
F_19 ( ! V_182 ) ;
if ( ! V_21 &&
( ( V_110 == V_116 ) ||
( V_110 == V_118 ) ) )
F_103 ( & V_182 -> V_24 , & V_187 -> V_157 ) ;
V_4 -> V_193 ( V_2 , V_4 , V_19 , V_188 ,
V_182 -> V_107 ) ;
if ( V_110 == V_118 )
V_188 += 2 ;
else
V_188 ++ ;
}
V_22 = F_104 ( V_2 , V_4 -> V_194 , V_131 -> V_100 ,
F_105 ( V_131 -> V_195 ) ,
F_106 ( V_131 -> V_195 ) ,
V_196 ) ;
if ( V_22 )
goto V_192;
}
F_9 (elem, exe_chunk, link) {
V_110 = V_19 -> V_111 . V_112 . V_110 ;
if ( ( V_110 == V_172 ) ||
( V_110 == V_118 ) ) {
V_182 = V_4 -> V_72 ( V_2 , V_4 ,
& V_19 -> V_111 . V_112 . V_61 ) ;
F_19 ( ! V_182 ) ;
V_4 -> V_197 ( V_4 , V_182 -> V_107 ) ;
F_16 ( & V_182 -> V_24 ) ;
F_6 ( V_182 ) ;
}
}
if ( ! V_189 )
return 1 ;
else
return 0 ;
V_192:
V_131 -> V_177 ( V_131 ) ;
F_9 (elem, exe_chunk, link) {
V_110 = V_19 -> V_111 . V_112 . V_110 ;
if ( V_110 == V_118 )
V_187 = V_19 -> V_111 . V_112 . V_129 ;
else
V_187 = V_4 ;
if ( ! V_21 &&
( ( V_110 == V_116 ) ||
( V_110 == V_118 ) ) ) {
V_182 = V_4 -> V_72 ( V_2 , V_187 ,
& V_19 -> V_111 . V_112 . V_61 ) ;
if ( V_182 ) {
F_16 ( & V_182 -> V_24 ) ;
F_6 ( V_182 ) ;
}
}
}
return V_22 ;
}
static inline int F_107 (
struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_154 -> V_156 ;
bool V_21 = F_18 ( V_159 , & V_154 -> V_25 ) ;
V_19 = F_24 ( V_2 ) ;
if ( ! V_19 )
return - V_183 ;
switch ( V_154 -> V_158 . V_110 ) {
case V_118 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_111 . V_112 , & V_154 -> V_158 , sizeof( V_154 -> V_158 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_154 -> V_156 ;
unsigned long * V_25 = & V_154 -> V_25 ;
bool V_198 = F_18 ( V_179 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_198 ) {
V_22 = F_107 ( V_2 , V_154 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_23 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_18 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_52 ) ;
V_38 -> V_177 ( V_38 ) ;
}
if ( V_198 || F_18 ( V_199 , V_25 ) ||
F_18 ( V_200 , V_25 ) ) {
V_22 = F_98 ( V_2 , V_154 -> V_156 ,
& V_154 -> V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_18 ( V_200 , & V_154 -> V_25 ) ) {
int V_201 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_23 ( & V_4 -> V_12 ) &&
V_201 -- ) {
V_22 = V_38 -> V_174 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_98 ( V_2 ,
V_154 -> V_156 ,
& V_154 -> V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
return V_22 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_117 ,
unsigned long * V_25 )
{
struct V_56 * V_57 = NULL ;
struct V_153 V_154 ;
struct V_3 * V_163 = & V_4 -> V_12 ;
struct V_18 * V_202 , * V_203 ;
unsigned long V_139 ;
int V_60 ;
int V_22 = 0 ;
F_8 ( & V_163 -> V_14 ) ;
F_109 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
V_139 = V_202 -> V_111 . V_112 . V_117 ;
if ( F_110 ( V_139 ) ==
F_110 ( * V_117 ) ) {
V_22 = V_163 -> remove ( V_2 , V_163 -> V_7 , V_202 ) ;
if ( V_22 ) {
F_38 ( L_53 ) ;
F_10 ( & V_163 -> V_14 ) ;
return V_22 ;
}
F_16 ( & V_202 -> V_24 ) ;
F_5 ( V_2 , V_202 ) ;
}
}
F_10 ( & V_163 -> V_14 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = V_4 ;
V_154 . V_25 = * V_25 ;
V_154 . V_158 . V_110 = V_172 ;
F_111 ( V_200 , & V_154 . V_25 ) ;
F_111 ( V_199 , & V_154 . V_25 ) ;
F_111 ( V_179 , & V_154 . V_25 ) ;
F_4 ( V_17 , L_54 ) ;
V_60 = F_54 ( V_2 , V_4 ) ;
if ( V_60 != 0 )
return V_60 ;
F_9 (pos, &o->head, link) {
V_139 = V_57 -> V_117 ;
if ( F_110 ( V_139 ) ==
F_110 ( * V_117 ) ) {
V_154 . V_158 . V_117 = V_57 -> V_117 ;
memcpy ( & V_154 . V_158 . V_61 , & V_57 -> V_61 , sizeof( V_57 -> V_61 ) ) ;
V_22 = F_89 ( V_2 , & V_154 ) ;
if ( V_22 < 0 ) {
F_38 ( L_55 ) ;
F_56 ( V_2 , V_4 ) ;
return V_22 ;
}
}
}
F_4 ( V_17 , L_56 ) ;
F_56 ( V_2 , V_4 ) ;
V_154 . V_25 = * V_25 ;
F_88 ( V_179 , & V_154 . V_25 ) ;
return F_89 ( V_2 , & V_154 ) ;
}
static inline void F_112 ( struct V_32 * V_38 , T_6 V_95 ,
T_7 V_100 , T_6 V_96 , void * V_109 , T_9 V_195 , int V_33 ,
unsigned long * V_34 , T_10 type )
{
V_38 -> V_96 = V_96 ;
V_38 -> V_100 = V_100 ;
V_38 -> V_95 = V_95 ;
V_38 -> V_109 = V_109 ;
V_38 -> V_195 = V_195 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_75 = type ;
V_38 -> V_190 = F_26 ;
V_38 -> V_177 = F_27 ;
V_38 -> V_191 = F_31 ;
V_38 -> V_174 = F_40 ;
}
static inline void F_113 ( struct V_39 * V_4 ,
T_6 V_95 , T_7 V_100 , T_6 V_96 , void * V_109 , T_9 V_195 ,
int V_33 , unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_157 ) ;
V_4 -> V_49 = 0 ;
V_4 -> V_51 = false ;
V_4 -> V_50 = 0 ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_204 = F_108 ;
V_4 -> V_21 = F_85 ;
V_4 -> V_205 = F_99 ;
V_4 -> V_206 = F_97 ;
F_112 ( & V_4 -> V_38 , V_95 , V_100 , V_96 , V_109 , V_195 ,
V_33 , V_34 , type ) ;
}
void F_114 ( struct V_1 * V_2 ,
struct V_39 * V_207 ,
T_6 V_95 , T_7 V_100 , T_6 V_96 , void * V_109 ,
T_9 V_195 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 )
{
union V_6 * V_208 = (union V_6 * ) V_207 ;
F_113 ( V_207 , V_95 , V_100 , V_96 , V_109 ,
V_195 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_207 -> V_165 = F_42 ;
V_207 -> V_167 = F_46 ;
V_207 -> V_184 = F_41 ;
V_207 -> V_197 = F_45 ;
if ( F_115 ( V_2 ) ) {
V_207 -> V_193 = F_83 ;
V_207 -> V_72 = F_62 ;
V_207 -> V_73 = F_58 ;
V_207 -> V_171 = F_65 ;
V_207 -> V_194 = V_209 ;
F_1 ( V_2 ,
& V_207 -> V_12 , 1 , V_208 ,
F_95 ,
F_96 ,
F_100 ,
F_102 ,
F_90 ) ;
} else {
V_207 -> V_193 = F_76 ;
V_207 -> V_72 = F_62 ;
V_207 -> V_73 = F_58 ;
V_207 -> V_171 = F_64 ;
V_207 -> V_194 =
V_210 ;
V_207 -> V_211 = F_57 ;
F_1 ( V_2 ,
& V_207 -> V_12 , V_212 ,
V_208 , F_95 ,
F_96 ,
F_100 ,
F_102 ,
F_90 ) ;
}
}
void F_116 ( struct V_1 * V_2 ,
struct V_39 * V_213 ,
T_6 V_95 , T_7 V_100 , T_6 V_96 , void * V_109 ,
T_9 V_195 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_46 )
{
union V_6 * V_208 = (union V_6 * ) V_213 ;
F_113 ( V_213 , V_95 , V_100 , V_96 , V_109 ,
V_195 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_213 -> V_165 = F_44 ;
V_213 -> V_167 = F_48 ;
V_213 -> V_184 = F_43 ;
V_213 -> V_197 = F_47 ;
if ( F_115 ( V_2 ) ) {
F_38 ( L_57 ) ;
F_117 () ;
} else {
V_213 -> V_193 = F_84 ;
V_213 -> V_72 = F_63 ;
V_213 -> V_73 = F_61 ;
V_213 -> V_171 = F_64 ;
V_213 -> V_194 =
V_210 ;
V_213 -> V_211 = F_57 ;
F_1 ( V_2 ,
& V_213 -> V_12 , V_212 ,
V_208 , F_95 ,
F_96 ,
F_100 ,
F_102 ,
F_91 ) ;
}
}
static inline void F_118 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
T_8 V_138 )
{
T_11 V_55 = sizeof( struct V_214 ) ;
T_7 V_216 = V_217 +
F_119 ( V_138 ) ;
F_120 ( V_2 , V_216 , V_55 , ( T_7 * ) V_215 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_218 * V_154 )
{
T_7 V_219 = ( 1 << V_154 -> V_95 ) ;
struct V_214 * V_215 =
(struct V_214 * ) V_154 -> V_109 ;
T_6 V_220 = 1 , V_221 = 1 ;
T_6 V_222 = 0 , V_223 = 0 , V_224 = 0 ;
T_6 V_225 = 0 ;
if ( F_18 ( V_226 , & V_154 -> V_227 ) )
V_220 = 0 ;
if ( F_18 ( V_228 , & V_154 -> V_227 ) )
V_221 = 0 ;
if ( F_18 ( V_229 , & V_154 -> V_227 ) ) {
V_220 = 0 ;
V_222 = 1 ;
}
if ( F_18 ( V_230 , & V_154 -> V_227 ) ) {
V_221 = 0 ;
V_224 = 1 ;
}
if ( F_18 ( V_231 , & V_154 -> V_227 ) )
V_223 = 1 ;
if ( F_18 ( V_232 , & V_154 -> V_227 ) )
V_225 = 1 ;
V_215 -> V_233 = V_220 ?
V_215 -> V_233 | V_219 :
V_215 -> V_233 & ~ V_219 ;
V_215 -> V_234 = V_221 ?
V_215 -> V_234 | V_219 :
V_215 -> V_234 & ~ V_219 ;
V_215 -> V_235 = V_222 ?
V_215 -> V_235 | V_219 :
V_215 -> V_235 & ~ V_219 ;
V_215 -> V_236 = V_224 ?
V_215 -> V_236 | V_219 :
V_215 -> V_236 & ~ V_219 ;
V_215 -> V_237 = V_223 ?
V_215 -> V_237 | V_219 :
V_215 -> V_237 & ~ V_219 ;
V_215 -> V_225 = V_225 ?
V_215 -> V_225 | V_219 :
V_215 -> V_225 & ~ V_219 ;
F_4 ( V_17 , L_58
L_59 ,
V_215 -> V_233 , V_215 -> V_234 ,
V_215 -> V_235 , V_215 -> V_236 ,
V_215 -> V_237 ) ;
F_118 ( V_2 , V_215 , V_154 -> V_96 ) ;
F_29 ( V_154 -> V_33 , V_154 -> V_34 ) ;
F_30 () ;
return 0 ;
}
static inline void F_122 ( T_7 V_100 ,
struct V_101 * V_93 ,
T_6 V_102 )
{
V_93 -> V_103 = F_75 ( V_100 ) ;
V_93 -> V_102 = V_102 ;
}
static inline void F_123 ( struct V_1 * V_2 ,
unsigned long * V_238 ,
struct V_239 * V_110 ,
bool V_240 )
{
T_8 V_33 ;
V_33 = V_241 |
V_242 ;
if ( F_18 ( V_226 , V_238 ) )
V_33 &= ~ V_241 ;
if ( F_18 ( V_228 , V_238 ) )
V_33 &= ~ V_242 ;
if ( F_18 ( V_229 , V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_243 ;
}
if ( F_18 ( V_230 , V_238 ) ) {
V_33 |= V_244 ;
V_33 &= ~ V_242 ;
}
if ( F_18 ( V_231 , V_238 ) )
V_33 |= V_245 ;
if ( F_18 ( V_232 , V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_246 ;
}
if ( F_18 ( V_247 , V_238 ) )
V_33 |= V_248 ;
if ( V_240 ) {
V_33 &= ~ V_244 ;
V_33 &= ~ V_245 ;
V_33 &= ~ V_243 ;
V_33 &= ~ V_246 ;
}
V_110 -> V_33 = F_78 ( V_33 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_218 * V_154 )
{
struct V_249 * V_64 = V_154 -> V_109 ;
int V_22 ;
T_6 V_106 = 0 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
if ( F_18 ( V_250 , & V_154 -> V_25 ) ) {
V_64 -> V_115 [ V_106 ] . V_94 = V_154 -> V_95 ;
V_64 -> V_115 [ V_106 ] . V_96 = V_154 -> V_96 ;
V_64 -> V_115 [ V_106 ] . V_97 =
V_251 ;
F_123 ( V_2 , & V_154 -> V_252 ,
& ( V_64 -> V_115 [ V_106 ++ ] ) ,
false ) ;
}
if ( F_18 ( V_253 , & V_154 -> V_25 ) ) {
V_64 -> V_115 [ V_106 ] . V_94 = V_154 -> V_95 ;
V_64 -> V_115 [ V_106 ] . V_96 = V_154 -> V_96 ;
V_64 -> V_115 [ V_106 ] . V_97 =
V_254 ;
F_123 ( V_2 , & V_154 -> V_227 ,
& ( V_64 -> V_115 [ V_106 ++ ] ) ,
false ) ;
}
if ( F_18 ( V_255 , & V_154 -> V_256 ) ) {
if ( F_18 ( V_250 , & V_154 -> V_25 ) ) {
V_64 -> V_115 [ V_106 ] . V_94 = F_125 ( V_2 , V_95 ) ;
V_64 -> V_115 [ V_106 ] . V_96 = V_154 -> V_96 ;
V_64 -> V_115 [ V_106 ] . V_97 =
V_251 ;
F_123 ( V_2 , & V_154 -> V_252 ,
& ( V_64 -> V_115 [ V_106 ] ) ,
true ) ;
V_106 ++ ;
}
if ( F_18 ( V_253 , & V_154 -> V_25 ) ) {
V_64 -> V_115 [ V_106 ] . V_94 = F_125 ( V_2 , V_95 ) ;
V_64 -> V_115 [ V_106 ] . V_96 = V_154 -> V_96 ;
V_64 -> V_115 [ V_106 ] . V_97 =
V_254 ;
F_123 ( V_2 , & V_154 -> V_227 ,
& ( V_64 -> V_115 [ V_106 ] ) ,
true ) ;
V_106 ++ ;
}
}
F_122 ( V_154 -> V_100 , & V_64 -> V_124 , V_106 ) ;
F_4 ( V_17 , L_60 ,
V_64 -> V_124 . V_102 , V_154 -> V_227 ,
V_154 -> V_252 ) ;
V_22 = F_104 ( V_2 , V_257 , V_154 -> V_100 ,
F_105 ( V_154 -> V_195 ) ,
F_106 ( V_154 -> V_195 ) ,
V_196 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_218 * V_154 )
{
return F_33 ( V_2 , V_154 -> V_33 , V_154 -> V_34 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_218 * V_154 )
{
return 0 ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_218 * V_154 )
{
int V_22 ;
V_22 = V_154 -> V_258 -> V_259 ( V_2 , V_154 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_18 ( V_200 , & V_154 -> V_25 ) ) {
V_22 = V_154 -> V_258 -> V_174 ( V_2 , V_154 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
if ( F_115 ( V_2 ) ) {
V_4 -> V_174 = F_127 ;
V_4 -> V_259 = F_121 ;
} else {
V_4 -> V_174 = F_126 ;
V_4 -> V_259 = F_124 ;
}
}
static inline T_6 F_130 ( T_6 * V_65 )
{
return ( F_131 ( 0 , V_65 , V_62 ) >> 24 ) & 0xff ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
if ( F_33 ( V_2 , V_4 -> V_262 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_174 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
int V_265 ;
struct V_266 * V_267 ;
struct V_268 * V_269 = NULL ;
struct V_270 * V_57 ;
int V_271 = ( ( V_110 == V_272 ) ?
V_154 -> V_273 : 0 ) ;
if ( ! V_154 -> V_273 )
return 0 ;
V_265 = sizeof( * V_267 ) +
V_271 * sizeof( struct V_268 ) ;
V_267 = F_25 ( V_265 , V_31 ) ;
if ( ! V_267 )
return - V_183 ;
F_4 ( V_17 , L_61 ,
V_110 , V_271 ) ;
F_2 ( & V_267 -> V_64 . V_274 ) ;
V_267 -> type = V_110 ;
V_267 -> V_275 = false ;
switch ( V_110 ) {
case V_272 :
V_269 = (struct V_268 * )
( ( T_6 * ) V_267 + sizeof( * V_267 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_269 -> V_65 , V_57 -> V_65 , V_62 ) ;
F_12 ( & V_269 -> V_24 , & V_267 -> V_64 . V_274 ) ;
V_269 ++ ;
}
break;
case V_276 :
V_267 -> V_64 . V_277 = V_154 -> V_273 ;
break;
case V_278 :
V_267 -> V_64 . V_279 = 0 ;
break;
default:
F_6 ( V_267 ) ;
F_38 ( L_62 , V_110 ) ;
return - V_66 ;
}
F_12 ( & V_267 -> V_24 , & V_4 -> V_280 ) ;
V_4 -> V_281 ( V_4 ) ;
return 1 ;
}
static inline int F_134 ( struct V_261 * V_4 , int V_282 )
{
int V_283 , V_284 , V_285 = V_282 % V_286 ;
for ( V_283 = V_282 / V_286 ; V_283 < V_287 ; V_283 ++ ) {
if ( V_4 -> V_288 . V_289 . V_290 [ V_283 ] )
for ( V_284 = V_285 ; V_284 < V_286 ; V_284 ++ ) {
int V_291 = V_284 + V_286 * V_283 ;
if ( F_135 ( V_4 -> V_288 . V_289 .
V_290 , V_291 ) ) {
return V_291 ;
}
}
V_285 = 0 ;
}
return - 1 ;
}
static inline int F_136 ( struct V_261 * V_4 )
{
int V_291 = F_134 ( V_4 , 0 ) ;
if ( V_291 >= 0 )
F_137 ( V_4 -> V_288 . V_289 . V_290 , V_291 ) ;
return V_291 ;
}
static inline T_6 F_138 ( struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_74 = 0 ;
if ( ( V_38 -> V_75 == V_76 ) ||
( V_38 -> V_75 == V_77 ) )
V_74 |= V_292 ;
if ( ( V_38 -> V_75 == V_79 ) ||
( V_38 -> V_75 == V_77 ) )
V_74 |= V_293 ;
return V_74 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_188 ,
union V_294 * V_295 ,
enum V_264 V_110 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_296 * V_64 =
(struct V_296 * ) ( V_131 -> V_109 ) ;
T_6 V_96 = V_131 -> V_96 ;
T_6 V_297 = F_138 ( V_4 ) ;
int V_298 ;
if ( ( V_110 == V_272 ) || ( V_110 == V_278 ) )
V_297 |= V_299 ;
V_64 -> V_115 [ V_188 ] . V_97 |= V_297 ;
switch ( V_110 ) {
case V_272 :
V_298 = F_130 ( V_295 -> V_65 ) ;
F_140 ( V_4 -> V_288 . V_289 . V_290 , V_298 ) ;
break;
case V_276 :
V_298 = F_136 ( V_4 ) ;
break;
case V_278 :
V_298 = V_295 -> V_298 ;
break;
default:
F_38 ( L_62 , V_110 ) ;
return;
}
F_4 ( V_17 , L_63 ,
( ( V_297 & V_299 ) ?
L_64 : L_65 ) , V_298 ) ;
V_64 -> V_115 [ V_188 ] . V_300 = ( T_6 ) V_298 ;
V_64 -> V_115 [ V_188 ] . V_96 = V_96 ;
V_64 -> V_115 [ V_188 ] . V_301 = V_4 -> V_301 ;
}
static inline int F_141 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_302 ,
int * V_303 )
{
int V_304 , V_20 = * V_303 ;
union V_294 V_295 = { NULL } ;
for ( V_304 = F_134 ( V_4 , V_302 ) ; V_304 >= 0 ;
V_304 = F_134 ( V_4 , V_304 + 1 ) ) {
V_295 . V_298 = ( T_6 ) V_304 ;
V_4 -> V_193 ( V_2 , V_4 , V_20 , & V_295 ,
V_278 ) ;
V_20 ++ ;
F_4 ( V_17 , L_66 , V_304 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_303 = V_20 ;
return V_304 ;
}
static inline void F_142 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
struct V_268 * V_308 , * V_309 ;
int V_20 = * V_307 ;
union V_294 V_295 = { NULL } ;
F_109 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_295 . V_65 = & V_308 -> V_65 [ 0 ] ;
V_4 -> V_193 ( V_2 , V_4 , V_20 , & V_295 , V_306 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_67 ,
V_308 -> V_65 ) ;
F_16 ( & V_308 -> V_24 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_307 = V_20 ;
if ( F_14 ( & V_306 -> V_64 . V_274 ) )
V_306 -> V_275 = true ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
int V_20 = * V_307 ;
while ( V_306 -> V_64 . V_277 ) {
V_4 -> V_193 ( V_2 , V_4 , V_20 , NULL , V_306 -> type ) ;
V_20 ++ ;
V_306 -> V_64 . V_277 -- ;
F_4 ( V_17 , L_68 ,
V_306 -> V_64 . V_277 , V_20 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_307 = V_20 ;
if ( ! V_306 -> V_64 . V_277 )
V_306 -> V_275 = true ;
}
static inline void F_144 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
V_306 -> V_64 . V_279 = V_4 -> V_310 ( V_2 , V_4 , V_306 -> V_64 . V_279 ,
V_307 ) ;
if ( V_306 -> V_64 . V_279 < 0 )
V_306 -> V_275 = true ;
else
V_306 -> V_64 . V_279 ++ ;
}
static inline int F_145 ( struct V_1 * V_2 ,
struct V_263 * V_154 )
{
struct V_266 * V_306 , * V_311 ;
int V_20 = 0 ;
struct V_261 * V_4 = V_154 -> V_312 ;
F_109 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_306 -> type ) {
case V_272 :
F_142 ( V_2 , V_4 , V_306 , & V_20 ) ;
break;
case V_276 :
F_143 ( V_2 , V_4 , V_306 , & V_20 ) ;
break;
case V_278 :
F_144 ( V_2 , V_4 , V_306 ,
& V_20 ) ;
break;
default:
F_38 ( L_62 , V_306 -> type ) ;
return - V_66 ;
}
if ( V_306 -> V_275 ) {
F_16 ( & V_306 -> V_24 ) ;
F_6 ( V_306 ) ;
}
if ( V_20 >= V_4 -> V_305 )
break;
}
return V_20 ;
}
static inline void F_146 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_154 ,
int * V_307 )
{
struct V_270 * V_313 ;
union V_294 V_295 = { NULL } ;
int V_20 = * V_307 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_295 . V_65 = V_313 -> V_65 ;
V_4 -> V_193 ( V_2 , V_4 , V_20 , & V_295 , V_272 ) ;
V_20 ++ ;
F_4 ( V_17 , L_67 ,
V_313 -> V_65 ) ;
}
* V_307 = V_20 ;
}
static inline void F_147 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_154 ,
int * V_307 )
{
int V_20 = * V_307 , V_283 ;
for ( V_283 = 0 ; V_283 < V_154 -> V_273 ; V_283 ++ ) {
V_4 -> V_193 ( V_2 , V_4 , V_20 , NULL , V_276 ) ;
V_20 ++ ;
F_4 ( V_17 , L_69 ,
V_154 -> V_273 - V_283 - 1 ) ;
}
* V_307 = V_20 ;
}
static inline int F_148 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 ,
int V_314 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
int V_20 = V_314 ;
F_4 ( V_17 , L_70 , V_154 -> V_273 ) ;
switch ( V_110 ) {
case V_272 :
F_146 ( V_2 , V_4 , V_154 , & V_20 ) ;
break;
case V_276 :
F_147 ( V_2 , V_4 , V_154 , & V_20 ) ;
break;
case V_278 :
V_4 -> V_310 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_62 , V_110 ) ;
return - V_66 ;
}
V_154 -> V_273 = 0 ;
return V_20 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
int V_315 = V_4 -> V_316 ( V_4 ) ;
switch ( V_110 ) {
case V_276 :
V_4 -> V_317 ( V_4 , 0 ) ;
case V_278 :
V_154 -> V_273 = V_315 ;
break;
case V_272 :
case V_318 :
V_4 -> V_317 ( V_4 , V_315 + V_154 -> V_273 ) ;
break;
default:
F_38 ( L_62 , V_110 ) ;
return - V_66 ;
}
V_4 -> V_319 += V_154 -> V_273 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
int V_320 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
V_4 -> V_317 ( V_4 , V_320 ) ;
V_4 -> V_319 -= V_154 -> V_273 ;
}
static inline void F_151 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
T_6 V_321 )
{
struct V_32 * V_131 = & V_154 -> V_312 -> V_38 ;
struct V_296 * V_64 =
(struct V_296 * ) ( V_131 -> V_109 ) ;
V_64 -> V_124 . V_103 = F_75 ( ( V_131 -> V_100 & V_104 ) |
( V_322 <<
V_105 ) ) ;
V_64 -> V_124 . V_102 = V_321 ;
}
static inline int F_152 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
int V_283 , V_20 = 0 ;
T_12 V_19 ;
for ( V_283 = 0 ; V_283 < V_287 ; V_283 ++ ) {
V_19 = V_4 -> V_288 . V_289 . V_290 [ V_283 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_317 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
struct V_32 * V_38 = & V_154 -> V_312 -> V_38 ;
struct V_261 * V_4 = V_154 -> V_312 ;
struct V_296 * V_64 =
(struct V_296 * ) ( V_38 -> V_109 ) ;
int V_20 = 0 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_20 = F_145 ( V_2 , V_154 ) ;
if ( F_14 ( & V_4 -> V_280 ) )
V_4 -> V_323 ( V_4 ) ;
if ( V_154 -> V_273 > 0 )
V_20 = F_148 ( V_2 , V_154 , V_110 , V_20 ) ;
V_4 -> V_319 -= V_20 ;
F_19 ( V_4 -> V_319 < 0 ) ;
F_19 ( V_20 > V_4 -> V_305 ) ;
F_151 ( V_2 , V_154 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_319 )
F_152 ( V_2 , V_4 ) ;
if ( F_18 ( V_28 , & V_154 -> V_25 ) ) {
V_38 -> V_177 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_104 ( V_2 , V_324 ,
V_38 -> V_100 , F_105 ( V_38 -> V_195 ) ,
F_106 ( V_38 -> V_195 ) ,
V_196 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_154 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
if ( ( V_110 == V_276 ) || ( V_110 == V_278 ) )
V_154 -> V_273 = 1 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
int V_320 )
{
}
static inline void F_156 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_154 ,
T_7 * V_325 )
{
struct V_270 * V_313 ;
int V_326 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_326 = F_130 ( V_313 -> V_65 ) ;
F_157 ( V_325 , V_326 ) ;
F_4 ( V_17 , L_71 ,
V_313 -> V_65 , V_326 ) ;
F_140 ( V_4 -> V_288 . V_289 . V_290 ,
V_326 ) ;
}
}
static inline void F_158 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_154 ,
T_7 * V_325 )
{
int V_326 ;
for ( V_326 = F_134 ( V_4 , 0 ) ;
V_326 >= 0 ;
V_326 = F_134 ( V_4 , V_326 + 1 ) ) {
F_157 ( V_325 , V_326 ) ;
F_4 ( V_17 , L_72 , V_326 ) ;
}
}
static int F_159 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
int V_283 ;
struct V_261 * V_4 = V_154 -> V_312 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( ! F_18 ( V_28 , & V_154 -> V_25 ) ) {
T_7 V_325 [ V_327 ] = { 0 } ;
switch ( V_110 ) {
case V_272 :
F_156 ( V_2 , V_4 , V_154 , V_325 ) ;
break;
case V_276 :
F_4 ( V_17 ,
L_73 ) ;
memset ( V_4 -> V_288 . V_289 . V_290 , 0 ,
sizeof( V_4 -> V_288 . V_289 . V_290 ) ) ;
break;
case V_278 :
F_158 ( V_2 , V_4 , V_154 , V_325 ) ;
break;
default:
F_38 ( L_62 , V_110 ) ;
return - V_66 ;
}
for ( V_283 = 0 ; V_283 < V_327 ; V_283 ++ )
F_72 ( V_2 , F_160 ( V_2 , V_283 ) , V_325 [ V_283 ] ) ;
} else
memset ( V_4 -> V_288 . V_289 . V_290 , 0 ,
sizeof( V_4 -> V_288 . V_289 . V_290 ) ) ;
V_131 -> V_177 ( V_131 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
int V_315 = V_4 -> V_316 ( V_4 ) ;
switch ( V_110 ) {
case V_276 :
V_4 -> V_317 ( V_4 , 0 ) ;
case V_278 :
V_154 -> V_273 = V_315 ;
F_4 ( V_17 , L_74 ,
V_110 , V_154 -> V_273 ) ;
break;
case V_272 :
case V_318 :
if ( V_154 -> V_273 > V_4 -> V_305 ) {
F_38 ( L_75 ,
V_4 -> V_305 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_70 , V_154 -> V_273 ) ;
if ( V_154 -> V_273 > 0 )
V_4 -> V_317 ( V_4 , V_154 -> V_273 ) ;
break;
default:
F_38 ( L_62 , V_110 ) ;
return - V_66 ;
}
if ( V_154 -> V_273 )
V_4 -> V_319 += V_4 -> V_305 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
int V_328 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
V_4 -> V_317 ( V_4 , V_328 ) ;
if ( V_154 -> V_273 )
V_4 -> V_319 -= V_4 -> V_305 ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_188 ,
union V_294 * V_295 ,
enum V_264 V_110 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_109 ) ;
if ( ( V_110 == V_272 ) || ( V_110 == V_278 ) ) {
F_77 ( & V_64 -> V_149 [ V_188 ] . V_143 ,
& V_64 -> V_149 [ V_188 ] . V_144 ,
& V_64 -> V_149 [ V_188 ] . V_145 ,
V_295 -> V_65 ) ;
V_64 -> V_149 [ V_188 ] . V_133 = 0 ;
V_64 -> V_149 [ V_188 ] . V_138 = V_131 -> V_96 ;
V_64 -> V_149 [ V_188 ] . V_137 =
F_75 ( 1 << V_131 -> V_95 ) ;
F_81 ( V_64 -> V_149 [ V_188 ] . V_139 ,
V_140 ,
V_141 ) ;
}
}
static inline void F_164 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
T_6 V_321 )
{
struct V_32 * V_131 = & V_154 -> V_312 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_109 ) ;
T_6 V_40 = ( F_165 ( V_2 ) ?
V_329 * ( 1 + V_131 -> V_96 ) :
V_330 * ( 1 + V_131 -> V_96 ) ) ;
V_64 -> V_93 . V_40 = V_40 ;
V_64 -> V_93 . V_94 = F_78 ( 0xff ) ;
V_64 -> V_93 . V_103 = F_75 ( ( V_131 -> V_100 & V_104 ) |
( V_322 <<
V_105 ) ) ;
V_64 -> V_93 . V_132 = V_321 ;
}
static inline int F_166 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_331 ,
int * V_303 )
{
struct V_268 * V_19 ;
int V_283 = 0 ;
union V_294 V_295 = { NULL } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_295 . V_65 = & V_19 -> V_65 [ 0 ] ;
V_4 -> V_193 ( V_2 , V_4 , V_283 , & V_295 , V_278 ) ;
V_283 ++ ;
F_4 ( V_17 , L_67 ,
V_295 . V_65 ) ;
}
* V_303 = V_283 ;
return - 1 ;
}
static inline int F_167 (
struct V_1 * V_2 , struct V_263 * V_154 )
{
struct V_266 * V_306 ;
struct V_268 * V_308 ;
struct V_261 * V_4 = V_154 -> V_312 ;
union V_294 V_295 = { NULL } ;
int V_20 = 0 ;
if ( F_14 ( & V_4 -> V_280 ) )
return 0 ;
V_306 = F_15 ( & V_4 -> V_280 ,
struct V_266 , V_24 ) ;
switch ( V_306 -> type ) {
case V_272 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_295 . V_65 = & V_308 -> V_65 [ 0 ] ;
V_4 -> V_193 ( V_2 , V_4 , V_20 , & V_295 , V_306 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_67 ,
V_308 -> V_65 ) ;
}
break;
case V_276 :
V_20 = V_306 -> V_64 . V_277 ;
F_4 ( V_17 , L_76 , V_20 ) ;
break;
case V_278 :
V_4 -> V_310 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_62 , V_306 -> type ) ;
return - V_66 ;
}
F_16 ( & V_306 -> V_24 ) ;
F_6 ( V_306 ) ;
return V_20 ;
}
static inline void F_168 ( T_13 * V_332 , T_13 * V_333 ,
T_13 * V_334 , T_6 * V_65 )
{
V_65 [ 1 ] = ( ( T_6 * ) V_332 ) [ 0 ] ;
V_65 [ 0 ] = ( ( T_6 * ) V_332 ) [ 1 ] ;
V_65 [ 3 ] = ( ( T_6 * ) V_333 ) [ 0 ] ;
V_65 [ 2 ] = ( ( T_6 * ) V_333 ) [ 1 ] ;
V_65 [ 5 ] = ( ( T_6 * ) V_334 ) [ 0 ] ;
V_65 [ 4 ] = ( ( T_6 * ) V_334 ) [ 1 ] ;
}
static inline int F_169 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_268 * V_19 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_109 ) ;
if ( F_170 ( V_64 -> V_149 [ 0 ] . V_139 ,
V_140 ) ) {
int V_283 , V_321 = V_64 -> V_93 . V_132 ;
if ( ! F_14 ( & V_4 -> V_288 . V_335 . V_336 ) )
return 0 ;
V_19 = F_171 ( V_321 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_38 ( L_77 ) ;
return - V_183 ;
}
for ( V_283 = 0 ; V_283 < V_321 ; V_283 ++ , V_19 ++ ) {
F_168 (
& V_64 -> V_149 [ V_283 ] . V_143 ,
& V_64 -> V_149 [ V_283 ] . V_144 ,
& V_64 -> V_149 [ V_283 ] . V_145 ,
V_19 -> V_65 ) ;
F_4 ( V_17 , L_78 ,
V_19 -> V_65 ) ;
F_12 ( & V_19 -> V_24 ,
& V_4 -> V_288 . V_335 . V_336 ) ;
}
} else {
V_19 = F_15 ( & V_4 -> V_288 . V_335 . V_336 ,
struct V_268 , V_24 ) ;
F_4 ( V_17 , L_79 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_288 . V_335 . V_336 ) ;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_109 ) ;
int V_20 = 0 , V_283 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
for ( V_283 = 0 ; V_283 < V_4 -> V_305 ; V_283 ++ )
F_81 ( V_64 -> V_149 [ V_283 ] . V_139 ,
V_140 ,
V_146 ) ;
V_20 = F_167 ( V_2 , V_154 ) ;
if ( F_14 ( & V_4 -> V_280 ) )
V_4 -> V_323 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_148 ( V_2 , V_154 , V_110 , 0 ) ;
V_4 -> V_319 -= V_4 -> V_305 ;
F_19 ( V_20 > V_4 -> V_305 ) ;
F_164 ( V_2 , V_154 , ( T_6 ) V_20 ) ;
V_22 = F_169 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_18 ( V_28 , & V_154 -> V_25 ) ) {
V_38 -> V_177 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_104 ( V_2 , V_209 , V_38 -> V_100 ,
F_105 ( V_38 -> V_195 ) ,
F_106 ( V_38 -> V_195 ) ,
V_196 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_173 ( struct V_261 * V_4 )
{
return V_4 -> V_288 . V_335 . V_337 ;
}
static int F_174 ( struct V_261 * V_4 )
{
return V_4 -> V_288 . V_289 . V_338 ;
}
static void F_175 ( struct V_261 * V_4 ,
int V_52 )
{
V_4 -> V_288 . V_335 . V_337 = V_52 ;
}
static void F_176 ( struct V_261 * V_4 ,
int V_52 )
{
V_4 -> V_288 . V_289 . V_338 = V_52 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_263 * V_154 ,
enum V_264 V_110 )
{
struct V_261 * V_4 = V_154 -> V_312 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 = 0 , V_339 ;
V_339 = V_4 -> V_316 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_154 , V_110 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_154 -> V_273 ) && ( ! V_4 -> V_340 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_80 ,
V_4 -> V_319 , V_154 -> V_273 , V_4 -> V_305 ) ;
if ( V_131 -> V_190 ( V_131 ) ||
( ( V_4 -> V_305 > 0 ) && ( V_4 -> V_319 > V_4 -> V_305 ) ) ) {
V_22 = V_4 -> V_341 ( V_2 , V_154 -> V_312 , V_154 , V_110 ) ;
if ( V_22 < 0 )
goto V_342;
V_154 -> V_273 = 0 ;
}
if ( ! V_131 -> V_190 ( V_131 ) ) {
V_131 -> V_191 ( V_131 ) ;
V_22 = V_4 -> V_343 ( V_2 , V_154 , V_110 ) ;
if ( V_22 < 0 )
goto V_344;
if ( F_18 ( V_200 , & V_154 -> V_25 ) )
V_22 = V_4 -> V_174 ( V_2 , V_4 ) ;
}
return V_22 ;
V_344:
V_131 -> V_177 ( V_131 ) ;
V_342:
V_4 -> V_345 ( V_2 , V_154 , V_339 ) ;
return V_22 ;
}
static void F_178 ( struct V_261 * V_4 )
{
F_28 () ;
F_29 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static void F_179 ( struct V_261 * V_4 )
{
F_28 () ;
F_32 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static bool F_180 ( struct V_261 * V_4 )
{
return ! ! F_18 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
}
static bool F_181 ( struct V_261 * V_4 )
{
return V_4 -> V_38 . V_190 ( & V_4 -> V_38 ) || V_4 -> V_340 ( V_4 ) ;
}
void F_182 ( struct V_1 * V_2 ,
struct V_261 * V_312 ,
T_6 V_346 , T_7 V_347 , T_6 V_96 ,
T_6 V_301 , void * V_109 , T_9 V_195 ,
int V_33 , unsigned long * V_34 , T_10 type )
{
memset ( V_312 , 0 , sizeof( * V_312 ) ) ;
F_112 ( & V_312 -> V_38 , V_346 , V_347 , V_96 ,
V_109 , V_195 , V_33 , V_34 , type ) ;
V_312 -> V_301 = V_301 ;
F_2 ( & V_312 -> V_280 ) ;
V_312 -> V_262 = V_348 ;
V_312 -> V_340 = F_180 ;
V_312 -> V_281 = F_179 ;
V_312 -> V_323 = F_178 ;
if ( F_183 ( V_2 ) ) {
V_312 -> V_343 = F_172 ;
V_312 -> V_341 = F_133 ;
V_312 -> V_310 =
F_166 ;
V_312 -> V_190 = F_181 ;
if ( F_165 ( V_2 ) )
V_312 -> V_305 = V_329 ;
else
V_312 -> V_305 = V_330 ;
V_312 -> V_174 = F_132 ;
V_312 -> V_193 = F_163 ;
V_312 -> V_8 = F_161 ;
V_312 -> V_345 = F_162 ;
V_312 -> V_316 =
F_173 ;
V_312 -> V_317 =
F_175 ;
F_2 ( & V_312 -> V_288 . V_335 . V_336 ) ;
} else if ( F_184 ( V_2 ) ) {
V_312 -> V_343 = F_159 ;
V_312 -> V_341 = NULL ;
V_312 -> V_310 = NULL ;
V_312 -> V_190 = F_181 ;
V_312 -> V_305 = - 1 ;
V_312 -> V_174 = F_132 ;
V_312 -> V_193 = NULL ;
V_312 -> V_8 = F_154 ;
V_312 -> V_345 = F_155 ;
V_312 -> V_316 =
F_174 ;
V_312 -> V_317 =
F_176 ;
} else {
V_312 -> V_343 = F_153 ;
V_312 -> V_341 = F_133 ;
V_312 -> V_310 =
F_141 ;
V_312 -> V_190 = F_181 ;
V_312 -> V_305 = 16 ;
V_312 -> V_174 = F_132 ;
V_312 -> V_193 = F_139 ;
V_312 -> V_8 = F_149 ;
V_312 -> V_345 = F_150 ;
V_312 -> V_316 =
F_174 ;
V_312 -> V_317 =
F_176 ;
}
}
static inline bool F_185 ( T_14 * V_349 , int V_350 , int V_61 )
{
int V_351 , V_352 ;
V_351 = F_186 ( V_349 ) ;
for (; ; ) {
if ( F_187 ( V_351 + V_350 >= V_61 ) )
return false ;
V_352 = F_188 ( ( V_349 ) , V_351 , V_351 + V_350 ) ;
if ( F_189 ( V_352 == V_351 ) )
break;
V_351 = V_352 ;
}
return true ;
}
static inline bool F_190 ( T_14 * V_349 , int V_350 , int V_61 )
{
int V_351 , V_352 ;
V_351 = F_186 ( V_349 ) ;
for (; ; ) {
if ( F_187 ( V_351 - V_350 < V_61 ) )
return false ;
V_352 = F_188 ( ( V_349 ) , V_351 , V_351 - V_350 ) ;
if ( F_189 ( V_352 == V_351 ) )
break;
V_351 = V_352 ;
}
return true ;
}
static bool F_191 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_192 () ;
V_22 = F_190 ( & V_4 -> V_353 , V_20 , 0 ) ;
F_192 () ;
return V_22 ;
}
static bool F_193 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_192 () ;
V_22 = F_185 ( & V_4 -> V_353 , V_20 , V_4 -> V_354 + 1 ) ;
F_192 () ;
return V_22 ;
}
static int F_194 ( struct V_41 * V_4 )
{
int V_355 ;
F_192 () ;
V_355 = F_186 ( & V_4 -> V_353 ) ;
return V_355 ;
}
static bool F_195 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_196 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_188 , V_290 , V_283 ;
* V_40 = - 1 ;
for ( V_290 = 0 ; V_290 < V_356 ; V_290 ++ ) {
if ( ! V_4 -> V_357 [ V_290 ] )
continue;
for ( V_188 = V_290 * V_286 , V_283 = 0 ;
V_283 < V_286 ; V_188 ++ , V_283 ++ )
if ( F_135 ( V_4 -> V_357 , V_188 ) ) {
F_137 ( V_4 -> V_357 , V_188 ) ;
* V_40 = V_4 -> V_358 + V_188 ;
return true ;
}
}
return false ;
}
static bool F_197 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_358 )
return false ;
V_40 -= V_4 -> V_358 ;
if ( V_40 >= V_4 -> V_354 )
return false ;
F_140 ( V_4 -> V_357 , V_40 ) ;
return true ;
}
static bool F_198 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_199 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_200 ( struct V_41 * V_154 ,
int V_53 , int V_353 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
memset ( & V_154 -> V_357 , 0xff , sizeof( V_154 -> V_357 ) ) ;
F_201 ( & V_154 -> V_353 , V_353 ) ;
V_154 -> V_354 = V_353 ;
V_154 -> V_358 = V_53 ;
F_192 () ;
V_154 -> V_359 = F_194 ;
if ( V_353 >= 0 ) {
V_154 -> V_48 = F_193 ;
V_154 -> V_11 = F_191 ;
V_154 -> V_47 = F_197 ;
V_154 -> V_44 = F_196 ;
} else {
V_154 -> V_48 = F_195 ;
V_154 -> V_11 = F_195 ;
V_154 -> V_47 = F_198 ;
V_154 -> V_44 = F_199 ;
}
if ( V_53 < 0 ) {
V_154 -> V_47 = F_198 ;
V_154 -> V_44 = F_199 ;
}
}
void F_202 ( struct V_1 * V_2 ,
struct V_41 * V_154 , T_6 V_96 ,
T_6 V_360 )
{
#define F_203 5
int V_361 ;
if ( F_183 ( V_2 ) ) {
if ( ! F_165 ( V_2 ) )
V_361 = ( V_362 / 2 ) - V_330 ;
else
V_361 = F_203 - V_329 ;
F_200 ( V_154 , V_96 * V_361 , V_361 ) ;
} else if ( F_184 ( V_2 ) ) {
if ( ( V_360 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_361 = ( V_363 / ( 2 * V_360 ) ) ;
else
V_361 = F_203 ;
F_200 ( V_154 , V_96 * V_361 , V_361 ) ;
} else {
F_200 ( V_154 , 0 , 0 ) ;
}
} else {
if ( ( V_360 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_361 = ( V_364 / V_360 ) ;
else
V_361 = F_203 ;
F_200 ( V_154 , - 1 , V_361 ) ;
} else {
F_200 ( V_154 , 0 , 0 ) ;
}
}
}
void F_204 ( struct V_1 * V_2 ,
struct V_41 * V_154 ,
T_6 V_96 ,
T_6 V_360 )
{
if ( F_115 ( V_2 ) ) {
F_200 ( V_154 , 0 , - 1 ) ;
} else {
if ( V_360 > 0 ) {
int V_353 = V_365 / V_360 ;
F_200 ( V_154 , V_96 * V_353 , V_353 ) ;
} else
F_200 ( V_154 , 0 , 0 ) ;
}
}
static inline void F_205 ( struct V_1 * V_2 ,
struct V_366 * V_154 )
{
int V_283 ;
F_4 ( V_17 , L_81 ) ;
F_4 ( V_17 , L_82 ) ;
for ( V_283 = 0 ; V_283 < V_367 ; V_283 ++ ) {
F_206 ( V_17 , L_83 , V_154 -> V_368 [ V_283 ] ) ;
if ( ( V_283 + 1 < V_367 ) &&
( ( ( V_283 + 1 ) & 0x3 ) == 0 ) ) {
F_206 ( V_17 , L_84 ) ;
F_4 ( V_17 , L_85 , V_283 + 1 ) ;
}
}
F_206 ( V_17 , L_84 ) ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_366 * V_154 )
{
struct V_369 * V_4 = V_154 -> V_370 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_371 * V_64 =
(struct V_371 * ) ( V_131 -> V_109 ) ;
T_8 V_372 = 0 ;
T_6 V_373 = 0 ;
int V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_4 ( V_17 , L_86 ) ;
V_64 -> V_103 = F_75 ( ( V_131 -> V_100 & V_104 ) |
( V_131 -> V_33 << V_105 ) ) ;
if ( F_18 ( V_374 , & V_154 -> V_375 ) )
V_373 = V_376 ;
else if ( F_18 ( V_377 , & V_154 -> V_375 ) )
V_373 = V_378 ;
V_64 -> V_373 = V_373 ;
F_4 ( V_17 , L_87 , V_373 ) ;
if ( F_18 ( V_379 , & V_154 -> V_375 ) )
V_372 |= V_380 ;
if ( F_18 ( V_381 , & V_154 -> V_375 ) )
V_372 |= V_382 ;
if ( F_18 ( V_383 , & V_154 -> V_375 ) )
V_372 |= V_384 ;
if ( F_18 ( V_385 , & V_154 -> V_375 ) )
V_372 |= V_386 ;
if ( F_18 ( V_387 , & V_154 -> V_375 ) )
V_372 |= V_388 ;
if ( F_18 ( V_389 , & V_154 -> V_375 ) )
V_372 |= V_390 ;
if ( F_18 ( V_391 , & V_154 -> V_375 ) )
V_372 |= V_392 ;
if ( F_18 ( V_393 , & V_154 -> V_375 ) ) {
memcpy ( & V_64 -> V_394 [ 0 ] , & V_154 -> V_394 [ 0 ] ,
sizeof( V_64 -> V_394 ) ) ;
V_372 |= V_395 ;
}
V_64 -> V_396 = F_78 ( V_372 ) ;
V_64 -> V_397 = V_154 -> V_397 ;
V_64 -> V_398 = V_4 -> V_301 ;
F_4 ( V_17 , L_88 , V_64 -> V_398 ) ;
memcpy ( V_64 -> V_399 , V_154 -> V_368 ,
V_367 ) ;
memcpy ( V_4 -> V_368 , V_154 -> V_368 , V_367 ) ;
if ( F_208 ( V_2 ) )
F_205 ( V_2 , V_154 ) ;
V_22 = F_104 ( V_2 , V_400 , V_131 -> V_100 ,
F_105 ( V_131 -> V_195 ) ,
F_106 ( V_131 -> V_195 ) ,
V_196 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_209 ( struct V_369 * V_370 ,
T_6 * V_368 )
{
memcpy ( V_368 , V_370 -> V_368 , sizeof( V_370 -> V_368 ) ) ;
}
int F_210 ( struct V_1 * V_2 ,
struct V_366 * V_154 )
{
int V_22 ;
struct V_369 * V_4 = V_154 -> V_370 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( F_18 ( V_28 , & V_154 -> V_25 ) ) {
F_4 ( V_17 , L_89 ,
V_154 -> V_25 ) ;
return 0 ;
}
V_131 -> V_191 ( V_131 ) ;
V_22 = V_4 -> V_401 ( V_2 , V_154 ) ;
if ( V_22 < 0 ) {
V_131 -> V_177 ( V_131 ) ;
return V_22 ;
}
if ( F_18 ( V_200 , & V_154 -> V_25 ) )
V_22 = V_131 -> V_174 ( V_2 , V_131 ) ;
return V_22 ;
}
void F_211 ( struct V_1 * V_2 ,
struct V_369 * V_370 ,
T_6 V_95 , T_7 V_100 , T_6 V_96 , T_6 V_301 ,
void * V_109 , T_9 V_195 ,
int V_33 , unsigned long * V_34 ,
T_10 type )
{
F_112 ( & V_370 -> V_38 , V_95 , V_100 , V_96 , V_109 ,
V_195 , V_33 , V_34 , type ) ;
V_370 -> V_301 = V_301 ;
V_370 -> V_401 = F_207 ;
}
int F_212 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
int V_22 , V_406 ;
unsigned long * V_407 = & V_4 -> V_407 ;
V_22 = V_4 -> V_408 ( V_2 , V_4 , V_403 ) ;
if ( V_22 ) {
F_38 ( L_90 , V_22 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_91 , V_4 -> V_407 ) ;
V_406 = V_4 -> V_191 ( V_4 , V_403 ) ;
F_4 ( V_17 , L_92 , V_4 -> V_407 ) ;
if ( F_18 ( V_28 , & V_403 -> V_25 ) )
V_4 -> V_409 ( V_2 , V_4 , V_406 ) ;
else {
V_22 = V_4 -> V_410 ( V_2 , V_403 ) ;
if ( V_22 ) {
V_4 -> V_411 = V_412 ;
F_29 ( V_406 , V_407 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_200 , & V_403 -> V_25 ) ) {
V_22 = V_4 -> V_174 ( V_2 , V_4 , V_406 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_406 , V_407 ) ;
}
static int F_213 ( struct V_404 * V_413 ,
struct V_402 * V_403 )
{
enum V_414 V_110 = V_403 -> V_110 , V_326 ;
if ( ( V_110 == V_415 ) ||
( V_110 == V_416 ) )
V_326 = V_417 ;
else
V_326 = V_110 ;
F_32 ( V_326 , & V_413 -> V_407 ) ;
return V_326 ;
}
static int F_214 ( struct V_1 * V_2 ,
struct V_404 * V_4 ,
enum V_414 V_110 )
{
return F_33 ( V_2 , V_110 , & V_4 -> V_407 ) ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_404 * V_4 ,
enum V_414 V_110 )
{
unsigned long V_418 = V_4 -> V_407 ;
if ( ! F_216 ( V_110 , & V_418 ) ) {
F_38 ( L_93 ,
V_110 , V_4 -> V_419 [ V_420 ] ,
V_4 -> V_33 , V_418 , V_4 -> V_411 ) ;
return - V_66 ;
}
if ( V_4 -> V_421 >= V_4 -> V_422 )
F_38 ( L_94 ,
V_4 -> V_421 , V_4 -> V_422 ) ;
F_4 ( V_17 ,
L_95 ,
V_110 , V_4 -> V_419 [ V_420 ] , V_4 -> V_411 ) ;
if ( V_4 -> V_421 )
F_4 ( V_17 , L_96 ,
V_4 -> V_419 [ V_420 ] , V_4 -> V_421 ) ;
V_4 -> V_33 = V_4 -> V_411 ;
V_4 -> V_423 = V_4 -> V_421 ;
V_4 -> V_411 = V_412 ;
F_217 () ;
F_29 ( V_110 , & V_4 -> V_407 ) ;
F_30 () ;
return 0 ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_402 * V_424 ,
struct V_425 * V_64 )
{
struct V_426 * V_403 = & V_424 -> V_403 . V_427 ;
V_64 -> V_428 . V_429 |= F_18 ( V_430 , & V_403 -> V_139 ) *
V_431 ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_404 * V_4 ,
struct V_432 * V_403 ,
struct V_433 * V_434 ,
unsigned long * V_139 )
{
V_434 -> V_94 = V_4 -> V_95 ;
if ( F_18 ( V_435 , V_139 ) ) {
V_434 -> V_436 =
V_403 -> V_437 ;
V_434 -> V_438 = 1 ;
V_434 -> V_439 =
F_18 ( V_440 , V_139 ) ;
} else
V_434 -> V_436 =
V_441 ;
V_434 -> V_442 = F_18 ( V_443 , V_139 ) ;
V_434 -> V_444 = F_18 ( V_445 , V_139 ) ;
V_434 -> V_446 = V_403 -> V_447 ;
V_434 -> V_448 = F_78 ( V_403 -> V_448 ) ;
V_434 -> V_96 = V_4 -> V_96 ;
V_434 -> cos = V_403 -> cos ;
V_434 -> V_449 =
F_18 ( V_443 , V_139 ) ?
V_450 : V_451 ;
V_434 -> V_452 = V_403 -> V_453 ;
F_4 ( V_17 , L_97 ,
V_434 -> V_444 , V_434 -> cos , V_434 -> V_438 ) ;
}
static void F_220 ( struct V_404 * V_4 ,
struct V_454 * V_403 ,
struct V_455 * V_456 ,
unsigned long * V_139 )
{
V_456 -> V_457 =
F_18 ( V_458 , V_139 ) ;
V_456 -> V_459 =
F_78 ( V_403 -> V_459 ) ;
V_456 -> V_460 =
F_18 ( V_461 , V_139 ) ;
V_456 -> V_462 =
F_18 ( V_463 , V_139 ) ;
V_456 -> V_464 =
F_18 ( V_465 , V_139 ) ;
V_456 -> V_466 =
F_18 ( V_467 , V_139 ) ;
V_456 -> V_468 =
F_18 ( V_469 , V_139 ) ;
V_456 -> V_470 =
F_18 ( V_471 , V_139 ) ;
V_456 -> V_472 =
F_18 ( V_473 , V_139 ) ? V_474 :
V_475 ;
V_456 -> V_476 = V_403 -> V_477 ;
V_456 -> V_478 = V_403 -> V_479 ;
V_456 -> V_480 = V_403 -> V_481 ;
V_456 -> V_482 . V_483 =
F_75 ( F_106 ( V_403 -> V_484 ) ) ;
V_456 -> V_482 . V_485 =
F_75 ( F_105 ( V_403 -> V_484 ) ) ;
V_456 -> V_33 = 0 ;
}
static void F_221 ( struct V_404 * V_4 ,
struct V_486 * V_403 ,
struct V_487 * V_488 )
{
V_488 -> V_489 = F_78 ( V_403 -> V_490 ) ;
V_488 -> V_491 = F_78 ( V_403 -> V_492 ) ;
V_488 -> V_493 = F_78 ( V_403 -> V_494 ) ;
V_488 -> V_495 = F_78 ( V_403 -> V_496 ) ;
V_488 -> V_497 = F_78 ( V_403 -> V_498 ) ;
V_488 -> V_499 = F_78 ( V_403 -> V_500 ) ;
V_488 -> V_501 = F_78 ( V_403 -> V_502 ) ;
}
static void F_222 ( struct V_404 * V_4 ,
struct V_503 * V_403 ,
struct V_487 * V_488 ,
unsigned long * V_139 )
{
V_488 -> V_429 = F_18 ( V_504 , V_139 ) *
V_505 ;
V_488 -> V_429 |= F_18 ( V_506 , V_139 ) *
V_507 ;
V_488 -> V_508 = 0 ;
V_488 -> V_509 =
V_403 -> V_510 ;
V_488 -> V_511 =
F_18 ( V_512 , V_139 ) ;
V_488 -> V_513 = V_403 -> V_514 ;
V_488 -> V_515 = V_403 -> V_516 ;
V_488 -> V_517 = F_78 ( V_403 -> V_518 ) ;
V_488 -> V_33 = F_78 ( V_519 |
V_520 ) ;
V_488 -> V_521 = 0 ;
V_488 -> V_522 = 0 ;
V_488 -> V_523 = 0 ;
V_488 -> V_524 = 0 ;
V_488 -> V_525 =
F_18 ( V_526 , V_139 ) ;
V_488 -> V_527 =
F_18 ( V_528 , V_139 ) ;
V_488 -> V_529 = V_403 -> V_477 ;
V_488 -> V_530 = V_403 -> V_479 ;
V_488 -> V_531 = V_403 -> V_531 ;
V_488 -> V_532 = F_78 ( V_403 -> V_533 ) ;
V_488 -> V_534 = F_78 ( V_403 -> V_535 ) ;
V_488 -> V_536 . V_483 =
F_75 ( F_106 ( V_403 -> V_484 ) ) ;
V_488 -> V_536 . V_485 =
F_75 ( F_105 ( V_403 -> V_484 ) ) ;
V_488 -> V_537 . V_483 =
F_75 ( F_106 ( V_403 -> V_538 ) ) ;
V_488 -> V_537 . V_485 =
F_75 ( F_105 ( V_403 -> V_538 ) ) ;
V_488 -> V_539 . V_483 =
F_75 ( F_106 ( V_403 -> V_540 ) ) ;
V_488 -> V_539 . V_485 =
F_75 ( F_105 ( V_403 -> V_540 ) ) ;
V_488 -> V_541 = F_18 ( V_542 , V_139 ) ;
if ( F_18 ( V_543 , V_139 ) ) {
V_488 -> V_544 = V_403 -> V_545 ;
V_488 -> V_546 = 1 ;
}
V_488 -> V_398 = V_403 -> V_398 ;
V_488 -> V_547 =
F_18 ( V_548 , V_139 ) ;
V_488 -> V_549 =
F_78 ( V_403 -> V_550 ) ;
V_488 -> V_551 =
F_78 ( V_403 -> V_552 ) ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_402 * V_424 ,
struct V_425 * V_64 )
{
F_219 ( V_2 , V_424 -> V_405 ,
& V_424 -> V_403 . V_427 . V_553 ,
& V_64 -> V_554 ,
& V_424 -> V_403 . V_427 . V_139 ) ;
F_220 ( V_424 -> V_405 ,
& V_424 -> V_403 . V_427 . V_555 ,
& V_64 -> V_556 ,
& V_424 -> V_403 . V_427 . V_139 ) ;
F_222 ( V_424 -> V_405 ,
& V_424 -> V_403 . V_427 . V_557 ,
& V_64 -> V_428 ,
& V_424 -> V_403 . V_427 . V_139 ) ;
F_221 ( V_424 -> V_405 ,
& V_424 -> V_403 . V_427 . V_558 ,
& V_64 -> V_428 ) ;
}
static void F_224 ( struct V_1 * V_2 ,
struct V_402 * V_424 ,
struct V_559 * V_64 )
{
F_219 ( V_2 , V_424 -> V_405 ,
& V_424 -> V_403 . V_560 . V_553 ,
& V_64 -> V_554 ,
& V_424 -> V_403 . V_560 . V_139 ) ;
F_220 ( V_424 -> V_405 ,
& V_424 -> V_403 . V_560 . V_555 ,
& V_64 -> V_556 ,
& V_424 -> V_403 . V_560 . V_139 ) ;
F_4 ( V_17 , L_98 ,
V_424 -> V_405 -> V_419 [ 0 ] ,
V_64 -> V_556 . V_482 . V_483 ,
V_64 -> V_556 . V_482 . V_485 ) ;
}
static inline int F_225 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_561 * V_562 = & V_403 -> V_403 . V_562 ;
T_8 V_563 ;
T_6 cos ;
if ( F_18 ( V_564 , & V_4 -> type ) &&
F_18 ( V_565 , & V_562 -> V_556 . V_139 ) ) {
V_563 = V_562 -> V_556 . V_566 ? 1000000 / V_562 -> V_556 . V_566 : 0 ;
F_226 ( V_2 , V_562 -> V_556 . V_477 ,
V_562 -> V_556 . V_479 ,
! F_18 ( V_567 , & V_562 -> V_556 . V_139 ) ,
V_563 ) ;
}
if ( F_18 ( V_568 , & V_4 -> type ) &&
F_18 ( V_565 , & V_562 -> V_428 . V_139 ) ) {
V_563 = V_562 -> V_428 . V_566 ? 1000000 / V_562 -> V_428 . V_566 : 0 ;
F_226 ( V_2 , V_562 -> V_428 . V_477 ,
V_562 -> V_428 . V_479 ,
! F_18 ( V_567 , & V_562 -> V_428 . V_139 ) ,
V_563 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_422 ; cos ++ ) {
F_4 ( V_17 , L_99 ,
V_4 -> V_419 [ cos ] , cos ) ;
F_4 ( V_17 , L_100 , V_562 -> V_569 [ cos ] ) ;
F_227 ( V_2 , V_562 -> V_569 [ cos ] , V_4 -> V_419 [ cos ] ) ;
}
V_4 -> V_409 ( V_2 , V_4 , V_570 ) ;
F_228 () ;
F_192 () ;
return 0 ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_425 * V_109 =
(struct V_425 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
int V_572 = V_573 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_223 ( V_2 , V_403 , V_109 ) ;
return F_104 ( V_2 , V_572 , V_4 -> V_419 [ V_420 ] ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_196 ) ;
}
static inline int F_230 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_425 * V_109 =
(struct V_425 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
int V_572 = V_573 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_223 ( V_2 , V_403 , V_109 ) ;
F_218 ( V_2 , V_403 , V_109 ) ;
return F_104 ( V_2 , V_572 , V_4 -> V_419 [ V_420 ] ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_196 ) ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_559 * V_109 =
(struct V_559 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
int V_572 = V_574 ;
struct V_575 * V_576 =
& V_403 -> V_403 . V_560 ;
T_6 V_577 = V_576 -> V_577 ;
if ( V_577 >= V_4 -> V_422 ) {
F_38 ( L_101 ,
V_4 -> V_95 , V_577 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_102 ,
V_576 -> V_553 . cos ,
V_576 -> V_553 . V_447 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_224 ( V_2 , V_403 , V_109 ) ;
F_4 ( V_17 , L_103 ,
V_4 -> V_419 [ V_577 ] , V_109 -> V_554 . V_94 ,
V_109 -> V_554 . V_446 , V_109 -> V_554 . cos ) ;
return F_104 ( V_2 , V_572 , V_4 -> V_419 [ V_577 ] ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_196 ) ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_404 * V_413 ,
struct V_578 * V_403 ,
struct V_579 * V_64 )
{
V_64 -> V_94 = V_413 -> V_95 ;
V_64 -> V_96 = V_413 -> V_96 ;
V_64 -> V_459 = F_78 ( V_403 -> V_580 ) ;
V_64 -> V_525 =
F_18 ( V_581 , & V_403 -> V_582 ) ;
V_64 -> V_583 =
F_18 ( V_584 ,
& V_403 -> V_582 ) ;
V_64 -> V_527 =
F_18 ( V_585 , & V_403 -> V_582 ) ;
V_64 -> V_586 =
F_18 ( V_587 ,
& V_403 -> V_582 ) ;
V_64 -> V_588 =
F_18 ( V_589 , & V_403 -> V_582 ) ;
V_64 -> V_590 =
F_18 ( V_591 , & V_403 -> V_582 ) ;
V_64 -> V_444 =
F_18 ( V_592 , & V_403 -> V_582 ) ;
V_64 -> V_593 =
F_18 ( V_594 , & V_403 -> V_582 ) ;
V_64 -> V_595 =
F_18 ( V_596 , & V_403 -> V_582 ) ;
V_64 -> V_597 =
F_18 ( V_598 ,
& V_403 -> V_582 ) ;
V_64 -> V_599 =
F_18 ( V_600 ,
& V_403 -> V_582 ) ;
V_64 -> V_547 =
F_18 ( V_601 , & V_403 -> V_582 ) ;
V_64 -> V_549 = F_78 ( V_403 -> V_550 ) ;
V_64 -> V_551 = F_78 ( V_403 -> V_552 ) ;
V_64 -> V_462 =
F_18 ( V_602 , & V_403 -> V_582 ) ;
V_64 -> V_603 =
F_18 ( V_604 ,
& V_403 -> V_582 ) ;
V_64 -> V_605 =
F_18 ( V_606 , & V_403 -> V_582 ) ;
V_64 -> V_607 =
F_18 ( V_608 , & V_403 -> V_582 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_579 * V_109 =
(struct V_579 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_578 * V_609 =
& V_403 -> V_403 . V_610 ;
T_6 V_577 = V_609 -> V_577 ;
if ( V_577 >= V_4 -> V_422 ) {
F_38 ( L_101 ,
V_4 -> V_95 , V_577 ) ;
return - V_66 ;
}
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_232 ( V_2 , V_4 , V_609 , V_109 ) ;
return F_104 ( V_2 , V_611 ,
V_4 -> V_419 [ V_577 ] , F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_196 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_578 * V_610 = & V_403 -> V_403 . V_610 ;
memset ( V_610 , 0 , sizeof( * V_610 ) ) ;
F_88 ( V_594 , & V_610 -> V_582 ) ;
return F_233 ( V_2 , V_403 ) ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_578 * V_610 = & V_403 -> V_403 . V_610 ;
memset ( V_610 , 0 , sizeof( * V_610 ) ) ;
F_88 ( V_592 , & V_610 -> V_582 ) ;
F_88 ( V_594 , & V_610 -> V_582 ) ;
return F_233 ( V_2 , V_403 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
struct V_404 * V_413 ,
struct V_612 * V_403 ,
struct V_613 * V_64 )
{
V_64 -> V_94 = V_413 -> V_95 ;
V_64 -> V_614 = V_403 -> V_614 ;
V_64 -> V_615 =
V_403 -> V_616 ;
V_64 -> V_517 = F_78 ( V_403 -> V_617 ) ;
V_64 -> V_513 = V_403 -> V_514 ;
V_64 -> V_531 = V_403 -> V_531 ;
V_64 -> V_534 = F_78 ( V_403 -> V_618 ) ;
V_64 -> V_619 = F_75 ( F_105 ( V_403 -> V_538 ) ) ;
V_64 -> V_620 = F_75 ( F_106 ( V_403 -> V_538 ) ) ;
V_64 -> V_499 = F_78 ( V_403 -> V_499 ) ;
V_64 -> V_497 = F_78 ( V_403 -> V_497 ) ;
V_64 -> V_621 = V_403 -> V_621 ;
V_64 -> V_622 = V_403 -> V_622 ;
V_64 -> V_623 = V_403 -> V_623 ;
}
static inline int F_237 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
struct V_613 * V_109 =
(struct V_613 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_612 * V_624 =
& V_403 -> V_403 . V_625 ;
T_8 type ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_236 ( V_2 , V_4 , V_624 , V_109 ) ;
type = V_196 |
( ( V_4 -> V_96 ) << V_626 ) ;
return F_104 ( V_2 , V_627 ,
V_4 -> V_419 [ V_420 ] ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , type ) ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
return F_104 ( V_2 , V_628 ,
V_4 -> V_419 [ V_420 ] , 0 , V_4 -> V_95 ,
V_196 ) ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
T_6 V_629 = V_403 -> V_403 . V_630 . V_577 ;
if ( V_629 >= V_4 -> V_422 ) {
F_38 ( L_101 ,
V_4 -> V_95 , V_629 ) ;
return - V_66 ;
}
return F_104 ( V_2 , V_631 ,
V_4 -> V_419 [ V_629 ] , 0 , 0 , V_632 ) ;
}
static inline int F_240 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
T_6 V_577 = V_403 -> V_403 . V_633 . V_577 ;
if ( V_577 >= V_4 -> V_422 ) {
F_38 ( L_101 ,
V_4 -> V_95 , V_577 ) ;
return - V_66 ;
}
return F_104 ( V_2 , V_634 ,
V_4 -> V_419 [ V_577 ] , 0 , 0 , V_196 ) ;
}
static inline int F_241 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
struct V_404 * V_4 = V_403 -> V_405 ;
return F_104 ( V_2 , V_635 ,
V_4 -> V_419 [ V_420 ] , 0 , 0 ,
V_196 ) ;
}
static inline int F_242 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
switch ( V_403 -> V_110 ) {
case V_570 :
return F_225 ( V_2 , V_403 ) ;
case V_636 :
return F_231 ( V_2 , V_403 ) ;
case V_416 :
return F_234 ( V_2 , V_403 ) ;
case V_415 :
return F_235 ( V_2 , V_403 ) ;
case V_417 :
return F_233 ( V_2 , V_403 ) ;
case V_637 :
return F_237 ( V_2 , V_403 ) ;
case V_638 :
return F_238 ( V_2 , V_403 ) ;
case V_639 :
return F_239 ( V_2 , V_403 ) ;
case V_640 :
return F_240 ( V_2 , V_403 ) ;
case V_641 :
return F_241 ( V_2 , V_403 ) ;
default:
F_38 ( L_62 , V_403 -> V_110 ) ;
return - V_66 ;
}
}
static int F_243 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
switch ( V_403 -> V_110 ) {
case V_642 :
return F_229 ( V_2 , V_403 ) ;
case V_570 :
case V_636 :
case V_416 :
case V_415 :
case V_417 :
case V_637 :
case V_638 :
case V_639 :
case V_640 :
case V_641 :
return F_242 ( V_2 , V_403 ) ;
default:
F_38 ( L_62 , V_403 -> V_110 ) ;
return - V_66 ;
}
}
static int F_244 ( struct V_1 * V_2 ,
struct V_402 * V_403 )
{
switch ( V_403 -> V_110 ) {
case V_642 :
return F_230 ( V_2 , V_403 ) ;
case V_570 :
case V_636 :
case V_416 :
case V_415 :
case V_417 :
case V_637 :
case V_638 :
case V_639 :
case V_640 :
case V_641 :
return F_242 ( V_2 , V_403 ) ;
default:
F_38 ( L_62 , V_403 -> V_110 ) ;
return - V_66 ;
}
}
static int F_245 ( struct V_1 * V_2 ,
struct V_404 * V_4 ,
struct V_402 * V_403 )
{
enum V_643 V_33 = V_4 -> V_33 , V_411 = V_412 ;
enum V_414 V_110 = V_403 -> V_110 ;
struct V_578 * V_609 =
& V_403 -> V_403 . V_610 ;
T_6 V_421 = V_4 -> V_423 ;
if ( F_18 ( V_28 , & V_403 -> V_25 ) ) {
V_4 -> V_407 = 0 ;
V_4 -> V_411 = V_412 ;
}
if ( V_4 -> V_407 ) {
F_38 ( L_104 ,
V_4 -> V_407 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_644 :
if ( V_110 == V_570 )
V_411 = V_645 ;
break;
case V_645 :
if ( V_110 == V_642 ) {
if ( F_18 ( V_445 ,
& V_403 -> V_403 . V_427 . V_139 ) )
V_411 = V_646 ;
else
V_411 = V_647 ;
}
break;
case V_646 :
if ( V_110 == V_416 )
V_411 = V_647 ;
else if ( ( V_110 == V_641 ) ||
( V_110 == V_637 ) )
V_411 = V_646 ;
else if ( V_110 == V_636 ) {
V_411 = V_648 ;
V_421 = 1 ;
}
else if ( V_110 == V_638 )
V_411 = V_649 ;
else if ( V_110 == V_417 ) {
if ( F_18 ( V_594 ,
& V_609 -> V_582 ) &&
! F_18 ( V_592 ,
& V_609 -> V_582 ) )
V_411 = V_647 ;
else
V_411 = V_646 ;
}
break;
case V_648 :
if ( V_110 == V_640 )
V_411 = V_650 ;
else if ( V_110 == V_636 ) {
V_411 = V_648 ;
V_421 = V_4 -> V_423 + 1 ;
}
else if ( ( V_110 == V_641 ) ||
( V_110 == V_637 ) )
V_411 = V_648 ;
else if ( V_110 == V_417 ) {
if ( F_18 ( V_594 ,
& V_609 -> V_582 ) &&
! F_18 ( V_592 ,
& V_609 -> V_582 ) )
V_411 = V_647 ;
else
V_411 = V_648 ;
}
break;
case V_650 :
if ( V_110 == V_639 ) {
V_421 = V_4 -> V_423 - 1 ;
if ( V_421 == 0 )
V_411 = V_646 ;
else
V_411 = V_648 ;
}
break;
case V_647 :
if ( V_110 == V_415 )
V_411 = V_646 ;
else if ( ( V_110 == V_641 ) ||
( V_110 == V_637 ) )
V_411 = V_647 ;
else if ( V_110 == V_638 )
V_411 = V_649 ;
else if ( V_110 == V_417 ) {
if ( F_18 ( V_594 ,
& V_609 -> V_582 ) &&
F_18 ( V_592 ,
& V_609 -> V_582 ) ) {
if ( V_4 -> V_423 == 0 )
V_411 = V_646 ;
else
V_411 = V_648 ;
} else
V_411 = V_647 ;
}
break;
case V_649 :
if ( V_110 == V_640 )
V_411 = V_651 ;
break;
case V_651 :
if ( V_110 == V_639 )
V_411 = V_644 ;
break;
default:
F_38 ( L_105 , V_33 ) ;
}
if ( V_411 != V_412 ) {
F_4 ( V_17 , L_106 ,
V_33 , V_110 , V_411 ) ;
V_4 -> V_411 = V_411 ;
V_4 -> V_421 = V_421 ;
return 0 ;
}
F_4 ( V_17 , L_107 , V_33 , V_110 ) ;
return - V_66 ;
}
void F_246 ( struct V_1 * V_2 ,
struct V_404 * V_413 ,
T_6 V_95 , T_7 * V_419 , T_6 V_652 , T_6 V_96 ,
void * V_109 ,
T_9 V_195 , unsigned long type )
{
memset ( V_413 , 0 , sizeof( * V_413 ) ) ;
F_247 ( V_653 < V_652 ) ;
memcpy ( V_413 -> V_419 , V_419 , sizeof( V_413 -> V_419 [ 0 ] ) * V_652 ) ;
V_413 -> V_422 = V_652 ;
V_413 -> V_95 = V_95 ;
V_413 -> V_96 = V_96 ;
V_413 -> V_109 = V_109 ;
V_413 -> V_195 = V_195 ;
V_413 -> type = type ;
V_413 -> V_411 = V_412 ;
if ( F_115 ( V_2 ) )
V_413 -> V_410 = F_243 ;
else
V_413 -> V_410 = F_244 ;
V_413 -> V_408 = F_245 ;
V_413 -> V_409 = F_215 ;
V_413 -> V_174 = F_214 ;
V_413 -> V_191 = F_213 ;
}
int F_248 ( struct V_1 * V_2 ,
struct V_404 * V_413 )
{
switch ( V_413 -> V_33 ) {
case V_646 :
case V_648 :
return V_654 ;
case V_644 :
case V_645 :
case V_650 :
case V_647 :
case V_649 :
case V_651 :
case V_655 :
return V_656 ;
default:
return - V_66 ;
}
}
enum V_657 F_249 ( struct V_1 * V_2 ,
struct V_658 * V_4 )
{
if ( V_4 -> V_407 )
return V_659 ;
F_250 () ;
return V_4 -> V_33 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_658 * V_4 ,
enum V_660 V_110 )
{
return F_33 ( V_2 , V_110 , & V_4 -> V_407 ) ;
}
static inline int F_252 ( struct V_1 * V_2 ,
struct V_658 * V_4 ,
enum V_660 V_110 )
{
unsigned long V_418 = V_4 -> V_407 ;
if ( ! F_216 ( V_110 , & V_418 ) ) {
F_38 ( L_108 ,
V_110 , F_253 ( V_2 ) , V_4 -> V_33 ,
V_418 , V_4 -> V_411 ) ;
return - V_66 ;
}
F_4 ( V_17 ,
L_109 ,
V_110 , F_253 ( V_2 ) , V_4 -> V_411 ) ;
V_4 -> V_33 = V_4 -> V_411 ;
V_4 -> V_411 = V_659 ;
F_217 () ;
F_29 ( V_110 , & V_4 -> V_407 ) ;
F_30 () ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_658 * V_4 ,
enum V_660 V_110 )
{
int V_22 = F_252 ( V_2 , V_4 , V_110 ) ;
return V_22 ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_658 * V_4 ,
struct V_661 * V_403 )
{
enum V_657 V_33 = V_4 -> V_33 , V_411 = V_659 ;
enum V_660 V_110 = V_403 -> V_110 ;
if ( F_18 ( V_28 , & V_403 -> V_25 ) ) {
V_4 -> V_407 = 0 ;
V_4 -> V_411 = V_659 ;
}
if ( V_4 -> V_407 )
return - V_37 ;
switch ( V_33 ) {
case V_662 :
if ( V_110 == V_663 )
V_411 = V_664 ;
break;
case V_664 :
if ( V_110 == V_665 )
V_411 = V_666 ;
else if ( V_110 == V_667 )
V_411 = V_662 ;
break;
case V_666 :
if ( V_110 == V_668 )
V_411 = V_664 ;
else if ( ( V_110 == V_669 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_666 ;
else if ( ( V_110 == V_670 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_666 ;
else if ( ( V_110 == V_671 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_666 ;
else if ( ( V_110 == V_672 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_666 ;
else if ( V_110 == V_673 )
V_411 = V_674 ;
break;
case V_674 :
if ( ( V_110 == V_671 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_674 ;
else if ( ( V_110 == V_672 ) &&
( ! F_18 ( V_668 , & V_4 -> V_407 ) ) )
V_411 = V_674 ;
else if ( V_110 == V_675 )
V_411 = V_666 ;
break;
default:
F_38 ( L_110 , V_33 ) ;
}
if ( V_411 != V_659 ) {
F_4 ( V_17 , L_111 ,
V_33 , V_110 , V_411 ) ;
V_4 -> V_411 = V_411 ;
return 0 ;
}
F_4 ( V_17 , L_112 ,
V_33 , V_110 ) ;
return - V_66 ;
}
static inline int F_256 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
return V_677 -> V_678 ( V_2 ) ;
}
static inline int F_257 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
int V_22 = V_677 -> V_679 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_256 ( V_2 , V_677 ) ;
}
static inline int F_258 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
int V_22 = V_677 -> V_680 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_257 ( V_2 , V_677 ) ;
}
static inline int F_259 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
int V_22 = V_677 -> V_681 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_257 ( V_2 , V_677 ) ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
T_7 V_682 = V_403 -> V_403 . V_683 . V_684 ;
struct V_658 * V_4 = V_403 -> V_685 ;
const struct V_676 * V_677 = V_4 -> V_677 ;
int V_22 = 0 ;
F_4 ( V_17 , L_113 ,
F_261 ( V_2 ) , V_682 ) ;
V_22 = V_677 -> V_686 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_677 -> V_687 ( V_2 ) ;
if ( V_22 ) {
F_38 ( L_114 ) ;
goto V_688;
}
switch ( V_682 ) {
case V_689 :
V_22 = F_258 ( V_2 , V_677 ) ;
if ( V_22 )
goto V_688;
break;
case V_690 :
V_22 = F_259 ( V_2 , V_677 ) ;
if ( V_22 )
goto V_688;
break;
case V_691 :
V_22 = F_257 ( V_2 , V_677 ) ;
if ( V_22 )
goto V_688;
break;
case V_692 :
V_22 = F_256 ( V_2 , V_677 ) ;
if ( V_22 )
goto V_688;
break;
default:
F_38 ( L_115 , V_682 ) ;
V_22 = - V_66 ;
}
V_688:
V_677 -> V_693 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_409 ( V_2 , V_4 , V_663 ) ;
return V_22 ;
}
static inline void F_262 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
V_677 -> V_694 ( V_2 ) ;
}
static inline void F_263 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
V_677 -> V_695 ( V_2 ) ;
F_262 ( V_2 , V_677 ) ;
}
static inline void F_264 ( struct V_1 * V_2 ,
const struct V_676 * V_677 )
{
F_263 ( V_2 , V_677 ) ;
V_677 -> V_696 ( V_2 ) ;
}
static inline int F_265 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
T_7 V_697 = V_403 -> V_403 . V_698 . V_697 ;
struct V_658 * V_4 = V_403 -> V_685 ;
const struct V_676 * V_677 = V_4 -> V_677 ;
F_4 ( V_17 , L_116 , F_261 ( V_2 ) ,
V_697 ) ;
switch ( V_697 ) {
case V_699 :
F_264 ( V_2 , V_677 ) ;
break;
case V_700 :
F_263 ( V_2 , V_677 ) ;
break;
case V_701 :
F_262 ( V_2 , V_677 ) ;
break;
default:
F_38 ( L_117 ,
V_697 ) ;
break;
}
V_4 -> V_409 ( V_2 , V_4 , V_667 ) ;
return 0 ;
}
static inline int F_266 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_702 * V_109 =
(struct V_702 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_703 * V_704 = & V_403 -> V_403 . V_705 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_706 = ( T_6 ) V_704 -> V_707 ;
V_109 -> V_708 = F_78 ( V_704 -> V_708 ) ;
V_109 -> V_709 = F_267 ( V_2 ) ;
V_109 -> V_710 = V_704 -> V_710 ;
V_109 -> V_711 = V_704 -> V_711 ;
V_109 -> V_712 = V_704 -> V_712 ;
V_109 -> V_713 = V_704 -> V_713 ;
V_109 -> V_714 = F_78 ( 4789 ) ;
V_109 -> V_715 = V_704 -> V_716 ;
if ( V_704 -> V_717 ) {
V_109 -> V_718 = 1 ;
V_109 -> V_719 =
F_78 ( V_704 -> V_717 ) ;
}
V_109 -> V_720 = V_704 -> V_721 ;
V_109 -> V_722 = V_704 -> V_722 ;
if ( V_704 -> V_723 )
V_109 -> V_723 =
F_78 ( V_704 -> V_723 ) ;
else
V_109 -> V_723 =
F_78 ( 0x8100 ) ;
V_109 -> V_724 = V_704 -> V_724 ;
return F_104 ( V_2 , V_725 , 0 ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_632 ) ;
}
static inline int F_268 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_726 * V_109 =
(struct V_726 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_727 * V_728 =
& V_403 -> V_403 . V_729 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
if ( F_18 ( V_730 ,
& V_728 -> V_731 ) ) {
V_109 -> V_732 = 1 ;
V_109 -> V_733 =
F_18 ( V_734 ,
& V_728 -> V_731 ) ;
}
if ( F_18 ( V_735 ,
& V_728 -> V_731 ) ) {
V_109 -> V_736 = 1 ;
V_109 -> V_708 =
F_78 ( V_728 -> V_69 ) ;
}
if ( F_18 ( V_737 ,
& V_728 -> V_731 ) ) {
V_109 -> V_738 = 1 ;
V_109 -> V_723 =
F_78 ( V_728 -> V_739 ) ;
}
if ( F_18 ( V_740 ,
& V_728 -> V_731 ) ) {
V_109 -> V_741 = 1 ;
if ( F_18 ( V_742 ,
& V_728 -> V_731 ) )
V_109 -> V_720 = 1 ;
V_109 -> V_720 =
V_728 -> V_743 ;
}
if ( F_18 ( V_744 ,
& V_728 -> V_731 ) ) {
V_109 -> V_745 = 1 ;
if ( F_18 ( V_746 ,
& V_728 -> V_731 ) )
V_109 -> V_747 = 1 ;
if ( F_18 ( V_748 ,
& V_728 -> V_731 ) )
V_109 -> V_713 = 1 ;
V_109 -> V_711 = V_728 -> V_711 ;
V_109 -> V_712 = V_728 -> V_712 ;
V_109 -> V_714 = F_78 ( 4789 ) ;
}
V_109 -> V_103 = V_749 ;
return F_104 ( V_2 , V_750 , 0 ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_632 ) ;
}
static inline int F_269 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_726 * V_109 =
(struct V_726 * ) V_4 -> V_751 ;
T_9 V_571 = V_4 -> V_752 ;
struct V_753 * V_754 =
& V_403 -> V_403 . V_755 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_756 = 1 ;
V_109 -> V_757 = F_78 ( V_754 -> V_757 ) ;
V_109 -> V_758 = 1 ;
V_109 -> V_759 =
F_78 ( V_754 -> V_759 ) ;
V_109 -> V_760 = 1 ;
V_109 -> V_761 = V_754 -> V_761 ;
V_109 -> V_103 = V_762 ;
F_4 ( V_17 ,
L_118 ,
V_109 -> V_757 ,
V_109 -> V_759 , V_109 -> V_761 ) ;
return F_104 ( V_2 , V_750 , 0 ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_632 ) ;
}
static
inline int F_270 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_763 * V_109 =
(struct V_763 * ) V_4 -> V_751 ;
struct V_764 * V_765 =
& V_403 -> V_403 . V_766 ;
T_12 * V_767 = ( T_12 * ) V_109 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_768 = F_78 ( V_765 -> V_768 ) ;
V_109 -> V_769 = V_765 -> V_769 ;
V_109 -> V_770 = V_765 -> V_770 ;
V_109 -> V_771 = V_765 -> V_771 ;
V_109 -> V_103 = V_765 -> V_770 ;
F_4 ( V_17 , L_119 ,
V_109 -> V_770 , V_109 -> V_768 ,
V_109 -> V_769 , V_109 -> V_771 ) ;
return F_104 ( V_2 , V_772 , 0 ,
F_105 ( * V_767 ) , F_106 ( * V_767 ) ,
V_632 ) ;
}
static inline int F_271 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
return F_104 ( V_2 , V_773 , 0 , 0 , 0 ,
V_632 ) ;
}
static inline int F_272 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
return F_104 ( V_2 , V_774 , 0 , 0 , 0 ,
V_632 ) ;
}
static inline int F_273 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_775 * V_109 =
(struct V_775 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_776 * V_777 =
& V_403 -> V_403 . V_778 ;
int V_283 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_779 = V_777 -> V_779 ;
V_109 -> V_780 = V_777 -> V_780 ;
V_109 -> V_781 = V_777 -> V_781 ;
for ( V_283 = 0 ; V_283 < F_274 ( V_109 -> V_782 ) ; V_283 ++ )
V_109 -> V_782 [ V_283 ] =
V_777 -> V_782 [ V_283 ] ;
return F_104 ( V_2 , V_783 , 0 ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_632 ) ;
}
static inline
int F_275 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
struct V_784 * V_109 =
(struct V_784 * ) V_4 -> V_109 ;
T_9 V_571 = V_4 -> V_195 ;
struct V_785 * V_786 =
& V_403 -> V_403 . V_787 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_788 = V_786 -> V_788 ;
V_109 -> V_789 = V_786 -> V_789 ;
V_109 -> V_790 =
V_786 -> V_790 ;
V_109 -> V_791 = V_786 -> V_791 ;
V_109 -> V_792 = V_786 -> V_792 ;
V_109 -> V_793 . V_483 =
F_75 ( F_106 ( V_786 -> V_793 ) ) ;
V_109 -> V_793 . V_485 =
F_75 ( F_105 ( V_786 -> V_793 ) ) ;
F_4 ( V_17 , L_120 ,
V_109 -> V_788 , V_109 -> V_789 ,
V_109 -> V_790 , V_109 -> V_791 ,
V_109 -> V_792 , V_109 -> V_793 . V_483 ,
V_109 -> V_793 . V_485 ) ;
return F_104 ( V_2 , V_794 , 0 ,
F_105 ( V_571 ) ,
F_106 ( V_571 ) , V_632 ) ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
switch ( V_403 -> V_110 ) {
case V_663 :
return F_260 ( V_2 , V_403 ) ;
case V_665 :
return F_266 ( V_2 , V_403 ) ;
case V_668 :
return F_271 ( V_2 , V_403 ) ;
case V_667 :
return F_265 ( V_2 , V_403 ) ;
case V_669 :
return F_269 ( V_2 , V_403 ) ;
case V_670 :
return F_270 ( V_2 , V_403 ) ;
case V_673 :
return F_272 ( V_2 , V_403 ) ;
case V_675 :
return F_273 ( V_2 , V_403 ) ;
case V_671 :
return F_268 ( V_2 , V_403 ) ;
case V_672 :
return F_275 ( V_2 , V_403 ) ;
default:
F_38 ( L_62 , V_403 -> V_110 ) ;
return - V_66 ;
}
}
void F_277 ( struct V_1 * V_2 ,
struct V_658 * V_413 ,
void * V_109 , T_9 V_195 ,
void * V_751 , T_9 V_752 ,
struct V_676 * V_795 )
{
memset ( V_413 , 0 , sizeof( * V_413 ) ) ;
F_278 ( & V_413 -> V_796 ) ;
V_413 -> V_109 = V_109 ;
V_413 -> V_195 = V_195 ;
V_413 -> V_751 = V_751 ;
V_413 -> V_752 = V_752 ;
V_413 -> V_410 = F_276 ;
V_413 -> V_408 = F_255 ;
V_413 -> V_409 = F_254 ;
V_413 -> V_174 = F_251 ;
V_413 -> V_677 = V_795 ;
}
int F_279 ( struct V_1 * V_2 ,
struct V_661 * V_403 )
{
struct V_658 * V_4 = V_403 -> V_685 ;
int V_22 , V_20 = 300 ;
enum V_660 V_110 = V_403 -> V_110 ;
unsigned long * V_407 = & V_4 -> V_407 ;
F_280 ( & V_4 -> V_796 ) ;
V_22 = V_4 -> V_408 ( V_2 , V_4 , V_403 ) ;
if ( ( V_22 == - V_37 ) &&
( F_18 ( V_797 , & V_403 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_281 ( & V_4 -> V_796 ) ;
F_282 ( 10 ) ;
F_280 ( & V_4 -> V_796 ) ;
V_22 = V_4 -> V_408 ( V_2 , V_4 , V_403 ) ;
}
if ( V_22 == - V_37 ) {
F_281 ( & V_4 -> V_796 ) ;
F_38 ( L_121 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_281 ( & V_4 -> V_796 ) ;
return V_22 ;
}
F_32 ( V_110 , V_407 ) ;
if ( F_18 ( V_28 , & V_403 -> V_25 ) ) {
F_252 ( V_2 , V_4 , V_110 ) ;
F_281 ( & V_4 -> V_796 ) ;
} else {
V_22 = V_4 -> V_410 ( V_2 , V_403 ) ;
F_281 ( & V_4 -> V_796 ) ;
if ( V_22 ) {
V_4 -> V_411 = V_659 ;
F_29 ( V_110 , V_407 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_200 , & V_403 -> V_25 ) ) {
V_22 = V_4 -> V_174 ( V_2 , V_4 , V_110 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_110 , V_407 ) ;
}
