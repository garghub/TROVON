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
F_4 ( V_17 , L_1
L_2 , V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
F_4 ( V_17 , L_3 ) ;
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
F_12 ( L_4 , V_22 ) ;
goto V_23;
}
}
F_13 ( & V_19 -> V_24 , & V_4 -> V_12 ) ;
F_10 ( & V_4 -> V_14 ) ;
return 0 ;
V_23:
F_5 ( V_2 , V_19 ) ;
F_10 ( & V_4 -> V_14 ) ;
return V_22 ;
}
static inline void F_14 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 ;
while ( ! F_15 ( & V_4 -> V_13 ) ) {
V_19 = F_16 ( & V_4 -> V_13 ,
struct V_18 , V_24 ) ;
F_17 ( & V_19 -> V_24 ) ;
F_5 ( V_2 , V_19 ) ;
}
}
static inline void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_14 ) ;
F_14 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_14 ) ;
}
static inline int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_25 )
{
struct V_18 * V_19 , V_26 ;
int V_27 = 0 , V_22 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
F_8 ( & V_4 -> V_14 ) ;
if ( ! F_15 ( & V_4 -> V_13 ) ) {
if ( F_20 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_5
L_6 ) ;
F_14 ( V_2 , V_4 ) ;
} else {
F_10 ( & V_4 -> V_14 ) ;
return 1 ;
}
}
while ( ! F_15 ( & V_4 -> V_12 ) ) {
V_19 = F_16 ( & V_4 -> V_12 , struct V_18 ,
V_24 ) ;
F_21 ( ! V_19 -> V_29 ) ;
if ( V_27 + V_19 -> V_29 <= V_4 -> V_15 ) {
V_27 += V_19 -> V_29 ;
F_13 ( & V_26 . V_24 , & V_4 -> V_13 ) ;
F_22 () ;
F_17 ( & V_19 -> V_24 ) ;
F_13 ( & V_19 -> V_24 , & V_4 -> V_13 ) ;
F_17 ( & V_26 . V_24 ) ;
} else
break;
}
if ( ! V_27 ) {
F_10 ( & V_4 -> V_14 ) ;
return 0 ;
}
V_22 = V_4 -> V_16 ( V_2 , V_4 -> V_7 , & V_4 -> V_13 , V_25 ) ;
if ( V_22 < 0 )
F_23 ( & V_4 -> V_13 , & V_4 -> V_12 ) ;
else if ( ! V_22 )
F_14 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_14 ) ;
return V_22 ;
}
static inline bool F_24 ( struct V_3 * V_4 )
{
bool V_30 = F_15 ( & V_4 -> V_12 ) ;
F_22 () ;
return V_30 && F_15 ( & V_4 -> V_13 ) ;
}
static inline struct V_18 * F_25 (
struct V_1 * V_2 )
{
F_4 ( V_17 , L_7 ) ;
return F_26 ( sizeof( struct V_18 ) , V_31 ) ;
}
static bool F_27 ( struct V_32 * V_4 )
{
return ! ! F_20 ( V_4 -> V_33 , V_4 -> V_34 ) ;
}
static void F_28 ( struct V_32 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_33 , V_4 -> V_34 ) ;
F_31 () ;
}
static void F_32 ( struct V_32 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_33 , V_4 -> V_34 ) ;
F_31 () ;
}
static inline int F_34 ( struct V_1 * V_2 , int V_33 ,
unsigned long * V_34 )
{
int V_20 = 5000 ;
if ( F_35 ( V_2 ) )
V_20 *= 20 ;
F_4 ( V_17 , L_8 , V_33 ) ;
F_36 () ;
while ( V_20 -- ) {
if ( ! F_20 ( V_33 , V_34 ) ) {
#ifdef F_37
F_4 ( V_17 , L_9 , 5000 - V_20 ) ;
#endif
return 0 ;
}
F_38 ( 1000 , 1000 ) ;
if ( V_2 -> V_35 )
return - V_36 ;
}
F_12 ( L_10 , V_33 ) ;
#ifdef F_37
F_39 () ;
#endif
return - V_37 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_32 * V_38 )
{
return F_34 ( V_2 , V_38 -> V_33 , V_38 -> V_34 ) ;
}
static bool F_41 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_21 ( ! V_42 ) ;
return V_42 -> V_44 ( V_42 , V_40 ) ;
}
static bool F_42 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_21 ( ! V_42 ) ;
return V_42 -> V_11 ( V_42 , 1 ) ;
}
static bool F_43 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_21 ( ! V_45 ) ;
return V_45 -> V_44 ( V_45 , V_40 ) ;
}
static bool F_44 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_21 ( ! V_45 ) ;
return V_45 -> V_11 ( V_45 , 1 ) ;
}
static bool F_45 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
struct V_41 * V_45 = V_4 -> V_46 ;
if ( ! V_42 -> V_11 ( V_42 , 1 ) )
return false ;
if ( ! V_45 -> V_11 ( V_45 , 1 ) ) {
V_42 -> V_47 ( V_42 , 1 ) ;
return false ;
}
return true ;
}
static bool F_46 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_48 ( V_42 , V_40 ) ;
}
static bool F_47 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_47 ( V_42 , 1 ) ;
}
static bool F_48 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_48 ( V_45 , V_40 ) ;
}
static bool F_49 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_47 ( V_45 , 1 ) ;
}
static bool F_50 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
struct V_41 * V_45 = V_4 -> V_46 ;
if ( ! V_42 -> V_47 ( V_42 , 1 ) )
return false ;
if ( ! V_45 -> V_47 ( V_45 , 1 ) ) {
V_42 -> V_11 ( V_42 , 1 ) ;
return false ;
}
return true ;
}
static int F_51 ( struct V_1 * V_2 , struct V_39 * V_4 ,
int V_49 , T_6 * V_50 )
{
struct V_51 * V_52 ;
T_6 * V_53 = V_50 ;
int V_54 = 0 ;
F_9 (pos, &o->head, link) {
if ( V_54 < V_49 ) {
memset ( V_53 , 0 , V_55 ) ;
memcpy ( V_53 + V_55 , V_52 -> V_56 . V_57 . V_57 ,
V_58 ) ;
V_54 ++ ;
V_53 = V_50 + V_54 * F_52 ( V_58 , sizeof( V_59 ) ) ;
F_4 ( V_17 , L_11 ,
V_54 , V_53 , V_52 -> V_56 . V_57 . V_57 ) ;
}
}
return V_54 * V_58 ;
}
static int F_53 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
if ( ! F_54 ( V_61 -> V_57 . V_57 ) )
return - V_62 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_61 -> V_57 . V_57 , V_52 -> V_56 . V_57 . V_57 , V_58 ) )
return - V_63 ;
return 0 ;
}
static int F_55 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( V_61 -> V_64 . V_64 == V_52 -> V_56 . V_64 . V_64 )
return - V_63 ;
return 0 ;
}
static int F_56 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ( V_61 -> V_65 . V_64 == V_52 -> V_56 . V_65 . V_64 ) &&
( ! memcmp ( V_61 -> V_65 . V_57 , V_52 -> V_56 . V_65 . V_57 ,
V_58 ) ) )
return - V_63 ;
return 0 ;
}
static struct V_51 *
F_57 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_61 -> V_57 . V_57 , V_52 -> V_56 . V_57 . V_57 , V_58 ) )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_58 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( V_61 -> V_64 . V_64 == V_52 -> V_56 . V_64 . V_64 )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_59 ( struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ( V_61 -> V_65 . V_64 == V_52 -> V_56 . V_65 . V_64 ) &&
( ! memcmp ( V_61 -> V_65 . V_57 , V_52 -> V_56 . V_65 . V_57 ,
V_58 ) ) )
return V_52 ;
return NULL ;
}
static bool F_60 ( struct V_39 * V_66 ,
struct V_39 * V_67 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
int V_22 ;
V_52 = V_66 -> V_68 ( V_66 , V_61 ) ;
V_22 = V_67 -> V_69 ( V_67 , V_61 ) ;
if ( V_22 || ! V_52 )
return false ;
return true ;
}
static bool F_61 (
struct V_39 * V_66 ,
struct V_39 * V_67 ,
union V_60 * V_61 )
{
return false ;
}
static inline T_6 F_62 ( struct V_39 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_70 = 0 ;
if ( ( V_38 -> V_71 == V_72 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_74 ;
if ( ( V_38 -> V_71 == V_75 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_76 ;
return V_70 ;
}
static inline void F_63 ( struct V_1 * V_2 ,
bool V_77 , unsigned char * V_78 , int V_79 )
{
V_59 V_80 [ 2 ] ;
V_59 V_81 = F_64 ( V_2 ) ? V_82 :
V_83 ;
if ( ! F_65 ( V_2 ) || V_79 > V_84 )
return;
F_4 ( V_17 , L_12 ,
( V_77 ? L_13 : L_14 ) , V_79 ) ;
if ( V_77 ) {
V_81 += 8 * V_79 ;
V_80 [ 0 ] = ( ( V_78 [ 2 ] << 24 ) | ( V_78 [ 3 ] << 16 ) |
( V_78 [ 4 ] << 8 ) | V_78 [ 5 ] ) ;
V_80 [ 1 ] = ( ( V_78 [ 0 ] << 8 ) | V_78 [ 1 ] ) ;
F_66 ( V_2 , V_81 , V_80 , 2 ) ;
}
F_67 ( V_2 , ( F_64 ( V_2 ) ? V_85 :
V_86 ) + 4 * V_79 , V_77 ) ;
}
static inline void F_68 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_77 , int V_87 ,
struct V_88 * V_89 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_89 -> V_90 = V_38 -> V_91 ;
V_89 -> V_92 = V_38 -> V_92 ;
V_89 -> V_93 |=
F_62 ( V_4 ) ;
if ( V_77 )
V_89 -> V_93 |= V_94 ;
V_89 -> V_93 |=
( V_87 << V_95 ) ;
}
static inline void F_69 ( V_59 V_96 , int type ,
struct V_97 * V_89 , int V_98 )
{
V_89 -> V_99 = ( V_96 & V_100 ) | ( type << V_101 ) ;
V_89 -> V_98 = ( T_6 ) V_98 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_102 ,
int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_104 * V_61 =
(struct V_104 * ) ( V_38 -> V_105 ) ;
int V_98 = V_102 + 1 , V_106 = V_19 -> V_107 . V_65 . V_106 ;
union V_108 * V_109 = & V_61 -> V_110 [ V_102 ] ;
bool V_77 = ( V_106 == V_111 ) ? true : false ;
unsigned long * V_112 = & V_19 -> V_107 . V_65 . V_112 ;
T_6 * V_57 = V_19 -> V_107 . V_65 . V_56 . V_57 . V_57 ;
if ( V_106 != V_113 ) {
if ( F_20 ( V_114 , V_112 ) )
F_63 ( V_2 , V_77 , V_57 ,
V_115 ) ;
else if ( F_20 ( V_116 , V_112 ) )
F_63 ( V_2 , V_77 , V_57 , V_117 ) ;
}
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_68 ( V_2 , V_4 , V_77 , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_4 ( V_17 , L_15 ,
V_77 ? L_16 : L_17 , V_57 , V_38 -> V_91 ) ;
F_71 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_68 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_71 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
}
F_69 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static inline void F_72 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 ,
struct V_124 * V_89 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_89 -> V_126 = 1 ;
V_89 -> V_40 = ( T_6 ) V_103 ;
V_89 -> V_90 = 0xff ;
V_89 -> V_99 = ( ( V_125 -> V_96 & V_100 ) | ( type << V_101 ) ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_77 , int V_87 , T_6 * V_57 ,
T_7 V_127 , struct V_128 * V_129 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_59 V_130 = ( 1 << V_125 -> V_91 ) ;
V_129 -> V_131 = F_74 ( V_130 ) ;
V_129 -> V_132 = V_125 -> V_92 ;
V_129 -> V_127 = F_75 ( V_127 ) ;
if ( V_77 ) {
F_76 ( V_129 -> V_133 , V_134 ,
V_135 ) ;
F_76 ( V_129 -> V_133 ,
V_136 , V_87 ) ;
F_71 ( & V_129 -> V_137 ,
& V_129 -> V_138 ,
& V_129 -> V_139 , V_57 ) ;
} else
F_76 ( V_129 -> V_133 , V_134 ,
V_140 ) ;
}
static inline void F_77 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 , bool V_77 ,
T_6 * V_57 , T_7 V_127 , int V_87 , struct V_141 * V_142 )
{
struct V_128 * V_129 = & V_142 -> V_143 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_72 ( V_2 , V_4 , type , V_103 ,
& V_142 -> V_89 ) ;
F_73 ( V_2 , V_4 , V_77 , V_87 , V_57 , V_127 ,
V_129 ) ;
F_4 ( V_17 , L_18 ,
V_77 ? L_19 : L_20 ,
V_57 , V_38 -> V_91 , V_103 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_102 ,
int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_141 * V_142 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
bool V_77 = ( V_19 -> V_107 . V_65 . V_106 == V_111 ) ?
true : false ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
F_77 ( V_2 , V_4 , V_144 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_57 . V_57 , 0 ,
V_145 , V_142 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_102 ,
int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_104 * V_61 =
(struct V_104 * ) ( V_38 -> V_105 ) ;
int V_98 = V_102 + 1 ;
union V_108 * V_109 = & V_61 -> V_110 [ V_102 ] ;
int V_106 = V_19 -> V_107 . V_65 . V_106 ;
bool V_77 = ( V_106 == V_111 ) ? true : false ;
T_7 V_64 = V_19 -> V_107 . V_65 . V_56 . V_64 . V_64 ;
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_68 ( V_2 , V_4 , V_77 , V_146 ,
& V_109 -> V_64 . V_119 ) ;
F_4 ( V_17 , L_21 , ( V_77 ? L_16 : L_17 ) ,
V_64 ) ;
V_109 -> V_64 . V_64 = F_75 ( V_64 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_68 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_146 ,
& V_109 -> V_64 . V_119 ) ;
V_109 -> V_64 . V_64 = F_75 ( V_64 ) ;
}
F_69 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_102 , int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_104 * V_61 =
(struct V_104 * ) ( V_38 -> V_105 ) ;
int V_98 = V_102 + 1 ;
union V_108 * V_109 = & V_61 -> V_110 [ V_102 ] ;
int V_106 = V_19 -> V_107 . V_65 . V_106 ;
bool V_77 = ( V_106 == V_111 ) ? true : false ;
T_7 V_64 = V_19 -> V_107 . V_65 . V_56 . V_65 . V_64 ;
T_6 * V_57 = V_19 -> V_107 . V_65 . V_56 . V_65 . V_57 ;
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_68 ( V_2 , V_4 , V_77 , V_147 ,
& V_109 -> V_148 . V_119 ) ;
V_109 -> V_148 . V_64 = F_75 ( V_64 ) ;
F_71 ( & V_109 -> V_148 . V_120 ,
& V_109 -> V_148 . V_121 ,
& V_109 -> V_148 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_68 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_147 ,
& V_109 -> V_148 . V_119 ) ;
V_109 -> V_148 . V_64 = F_75 ( V_64 ) ;
F_71 ( & V_109 -> V_148 . V_120 ,
& V_109 -> V_148 . V_121 ,
& V_109 -> V_148 . V_122 , V_57 ) ;
}
F_69 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_102 , int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_141 * V_142 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
bool V_77 = ( V_19 -> V_107 . V_65 . V_106 == V_111 ) ?
true : false ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
F_77 ( V_2 , V_4 , V_149 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_57 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_64 ,
V_150 , V_142 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_151 * V_152 ,
struct V_51 * * V_153 )
{
struct V_51 * V_52 ;
struct V_39 * V_4 = V_152 -> V_154 ;
if ( F_15 ( & V_4 -> V_155 ) ) {
* V_153 = NULL ;
return 0 ;
}
if ( * V_153 == NULL )
* V_153 = F_16 ( & V_4 -> V_155 ,
struct V_51 ,
V_24 ) ;
else
* V_153 = F_83 ( * V_153 , V_24 ) ;
V_52 = * V_153 ;
if ( F_84 ( & V_52 -> V_24 , & V_4 -> V_155 ) )
* V_153 = NULL ;
memcpy ( & V_152 -> V_156 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_152 -> V_156 . V_106 = V_111 ;
V_152 -> V_156 . V_112 = V_52 -> V_112 ;
F_85 ( V_157 , & V_152 -> V_25 ) ;
return F_86 ( V_2 , V_152 ) ;
}
static struct V_18 * F_87 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_158 * V_61 = & V_19 -> V_107 . V_65 . V_56 . V_57 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_57 , V_61 ,
sizeof( * V_61 ) ) &&
( V_52 -> V_107 . V_65 . V_106 == V_19 -> V_107 . V_65 . V_106 ) )
return V_52 ;
return NULL ;
}
static struct V_18 * F_88 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_159 * V_61 = & V_19 -> V_107 . V_65 . V_56 . V_64 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_64 , V_61 ,
sizeof( * V_61 ) ) &&
( V_52 -> V_107 . V_65 . V_106 == V_19 -> V_107 . V_65 . V_106 ) )
return V_52 ;
return NULL ;
}
static struct V_18 * F_89 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_160 * V_61 =
& V_19 -> V_107 . V_65 . V_56 . V_65 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_65 , V_61 ,
sizeof( * V_61 ) ) &&
( V_52 -> V_107 . V_65 . V_106 == V_19 -> V_107 . V_65 . V_106 ) )
return V_52 ;
return NULL ;
}
static inline int F_90 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_161 -> V_65 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_69 ( V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_22
L_23 ) ;
return V_22 ;
}
if ( V_162 -> V_11 ( V_162 , V_19 ) ) {
F_4 ( V_17 , L_24 ) ;
return - V_63 ;
}
if ( ! ( F_20 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_164 ( V_4 ) ) )
return - V_62 ;
return 0 ;
}
static inline int F_91 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_161 -> V_65 ;
struct V_51 * V_52 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
struct V_18 V_165 ;
V_52 = V_4 -> V_68 ( V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( ! V_52 ) {
F_4 ( V_17 , L_25
L_23 ) ;
return - V_63 ;
}
memcpy ( & V_165 , V_19 , sizeof( V_165 ) ) ;
V_165 . V_107 . V_65 . V_106 = V_113 ;
if ( V_162 -> V_11 ( V_162 , & V_165 ) ) {
F_12 ( L_26 ) ;
return - V_62 ;
}
if ( V_162 -> V_11 ( V_162 , V_19 ) ) {
F_4 ( V_17 , L_27 ) ;
return - V_63 ;
}
if ( ! ( F_20 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_166 ( V_4 ) ) ) {
F_12 ( L_28 ) ;
return - V_62 ;
}
return 0 ;
}
static inline int F_92 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_66 = & V_161 -> V_65 ;
struct V_39 * V_167 = V_19 -> V_107 . V_65 . V_123 ;
struct V_18 V_165 ;
struct V_3 * V_168 = & V_66 -> V_12 ;
struct V_3 * V_169 = & V_167 -> V_12 ;
if ( ! V_66 -> V_170 ( V_66 , V_167 , & V_19 -> V_107 . V_65 . V_56 ) ) {
F_4 ( V_17 , L_29
L_23 ) ;
return - V_62 ;
}
memcpy ( & V_165 , V_19 , sizeof( V_165 ) ) ;
V_165 . V_107 . V_65 . V_106 = V_171 ;
if ( V_168 -> V_11 ( V_168 , & V_165 ) ) {
F_12 ( L_30
L_31 ) ;
return - V_62 ;
}
if ( V_168 -> V_11 ( V_168 , V_19 ) ) {
F_4 ( V_17 , L_26 ) ;
return - V_63 ;
}
V_165 . V_107 . V_65 . V_106 = V_111 ;
if ( V_169 -> V_11 ( V_169 , & V_165 ) ) {
F_12 ( L_32
L_33 ) ;
return - V_62 ;
}
if ( ! ( F_20 ( V_172 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_167 -> V_164 ( V_167 ) ) )
return - V_62 ;
if ( ! ( F_20 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_66 -> V_166 ( V_66 ) ) ) {
V_167 -> V_166 ( V_167 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
return F_90 ( V_2 , V_161 , V_19 ) ;
case V_171 :
return F_91 ( V_2 , V_161 , V_19 ) ;
case V_113 :
return F_92 ( V_2 , V_161 , V_19 ) ;
default:
return - V_62 ;
}
}
static int F_94 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_20 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) )
return 0 ;
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
case V_113 :
V_22 = V_161 -> V_65 . V_166 ( & V_161 -> V_65 ) ;
break;
case V_171 :
V_22 = V_161 -> V_65 . V_164 ( & V_161 -> V_65 ) ;
break;
default:
return - V_62 ;
}
if ( V_22 != true )
return - V_62 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_173 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_24 ( V_162 ) )
F_38 ( 1000 , 1000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_174 * V_175 ,
unsigned long * V_25 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 ;
F_18 ( V_2 , & V_4 -> V_12 ) ;
V_125 -> V_176 ( V_125 ) ;
if ( V_175 -> V_177 . error )
return - V_62 ;
if ( F_20 ( V_178 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_18 V_179 , * V_52 ;
struct V_39 * V_4 = & V_161 -> V_65 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
memcpy ( & V_179 , V_19 , sizeof( V_179 ) ) ;
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
V_179 . V_107 . V_65 . V_106 = V_171 ;
break;
case V_171 :
V_179 . V_107 . V_65 . V_106 = V_111 ;
break;
default:
return 0 ;
}
V_52 = V_162 -> V_11 ( V_162 , & V_179 ) ;
if ( V_52 ) {
if ( ! F_20 ( V_163 ,
& V_52 -> V_107 . V_65 . V_112 ) ) {
if ( ( V_179 . V_107 . V_65 . V_106 ==
V_111 ) && ! V_4 -> V_166 ( V_4 ) ) {
F_12 ( L_34
L_35 ) ;
return - V_62 ;
} else if ( ! V_4 -> V_164 ( V_4 ) ) {
F_12 ( L_36
L_37 ) ;
return - V_62 ;
}
}
F_4 ( V_17 , L_38 ,
( V_19 -> V_107 . V_65 . V_106 == V_111 ) ?
L_13 : L_39 ) ;
F_17 ( & V_52 -> V_24 ) ;
F_5 ( V_2 , V_52 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_98 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_51 * * V_180 )
{
int V_106 = V_19 -> V_107 . V_65 . V_106 ;
struct V_51 * V_181 ;
if ( ! V_21 &&
( ( V_106 == V_111 ) || ( V_106 == V_113 ) ) ) {
V_181 = F_26 ( sizeof( * V_181 ) , V_31 ) ;
if ( ! V_181 )
return - V_182 ;
if ( ! V_4 -> V_183 ( V_4 , & V_181 -> V_103 ) ) {
F_21 ( 1 ) ;
F_6 ( V_181 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_40 , V_181 -> V_103 ) ;
memcpy ( & V_181 -> V_56 , & V_19 -> V_107 . V_65 . V_56 ,
sizeof( V_181 -> V_56 ) ) ;
V_181 -> V_112 =
V_19 -> V_107 . V_65 . V_112 ;
} else
V_181 = V_4 -> V_68 ( V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
* V_180 = V_181 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_184 * V_185 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_161 -> V_65 , * V_186 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 , V_187 = 0 ;
bool V_21 = F_20 ( V_157 , V_25 ) ;
bool V_188 = F_20 ( V_28 , V_25 ) ;
struct V_51 * V_181 ;
int V_106 ;
if ( ! V_188 ) {
F_21 ( V_125 -> V_189 ( V_125 ) ) ;
V_125 -> V_190 ( V_125 ) ;
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( V_106 == V_113 )
V_186 = V_19 -> V_107 . V_65 . V_123 ;
else
V_186 = V_4 ;
V_22 = F_98 ( V_2 , V_186 ,
V_19 , V_21 ,
& V_181 ) ;
if ( V_22 )
goto V_191;
F_21 ( ! V_181 ) ;
if ( ! V_21 &&
( ( V_106 == V_111 ) ||
( V_106 == V_113 ) ) )
F_100 ( & V_181 -> V_24 , & V_186 -> V_155 ) ;
V_4 -> V_192 ( V_2 , V_4 , V_19 , V_187 ,
V_181 -> V_103 ) ;
if ( V_106 == V_113 )
V_187 += 2 ;
else
V_187 ++ ;
}
V_22 = F_101 ( V_2 , V_4 -> V_193 , V_125 -> V_96 ,
F_102 ( V_125 -> V_194 ) ,
F_103 ( V_125 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
goto V_191;
}
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( ( V_106 == V_171 ) ||
( V_106 == V_113 ) ) {
V_181 = V_4 -> V_68 ( V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
F_21 ( ! V_181 ) ;
V_4 -> V_196 ( V_4 , V_181 -> V_103 ) ;
F_17 ( & V_181 -> V_24 ) ;
F_6 ( V_181 ) ;
}
}
if ( ! V_188 )
return 1 ;
else
return 0 ;
V_191:
V_125 -> V_176 ( V_125 ) ;
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( V_106 == V_113 )
V_186 = V_19 -> V_107 . V_65 . V_123 ;
else
V_186 = V_4 ;
if ( ! V_21 &&
( ( V_106 == V_111 ) ||
( V_106 == V_113 ) ) ) {
V_181 = V_4 -> V_68 ( V_186 ,
& V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_181 ) {
F_17 ( & V_181 -> V_24 ) ;
F_6 ( V_181 ) ;
}
}
}
return V_22 ;
}
static inline int F_104 (
struct V_1 * V_2 ,
struct V_151 * V_152 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_152 -> V_154 ;
bool V_21 = F_20 ( V_157 , & V_152 -> V_25 ) ;
V_19 = F_25 ( V_2 ) ;
if ( ! V_19 )
return - V_182 ;
switch ( V_152 -> V_156 . V_106 ) {
case V_113 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_107 . V_65 , & V_152 -> V_156 , sizeof( V_152 -> V_156 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_86 (
struct V_1 * V_2 ,
struct V_151 * V_152 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_152 -> V_154 ;
unsigned long * V_25 = & V_152 -> V_25 ;
bool V_197 = F_20 ( V_178 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_197 ) {
V_22 = F_104 ( V_2 , V_152 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_20 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_5
L_41 ) ;
V_38 -> V_176 ( V_38 ) ;
}
if ( V_197 || F_20 ( V_198 , V_25 ) ||
F_20 ( V_199 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_20 ( V_199 , & V_152 -> V_25 ) ) {
int V_200 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_200 -- ) {
V_22 = V_38 -> V_173 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_19 ( V_2 , & V_4 -> V_12 ,
V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
return V_22 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_112 ,
unsigned long * V_25 )
{
struct V_51 * V_52 = NULL ;
int V_22 = 0 ;
struct V_151 V_152 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
struct V_18 * V_201 , * V_202 ;
F_8 ( & V_162 -> V_14 ) ;
F_106 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_201 -> V_107 . V_65 . V_112 ==
* V_112 ) {
V_22 = V_162 -> remove ( V_2 , V_162 -> V_7 , V_201 ) ;
if ( V_22 ) {
F_12 ( L_42 ) ;
return V_22 ;
}
F_17 ( & V_201 -> V_24 ) ;
}
}
F_10 ( & V_162 -> V_14 ) ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_154 = V_4 ;
V_152 . V_25 = * V_25 ;
V_152 . V_156 . V_106 = V_171 ;
F_107 ( V_199 , & V_152 . V_25 ) ;
F_107 ( V_198 , & V_152 . V_25 ) ;
F_107 ( V_178 , & V_152 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_52 -> V_112 == * V_112 ) {
V_152 . V_156 . V_112 = V_52 -> V_112 ;
memcpy ( & V_152 . V_156 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_22 = F_86 ( V_2 , & V_152 ) ;
if ( V_22 < 0 ) {
F_12 ( L_43 ) ;
return V_22 ;
}
}
}
V_152 . V_25 = * V_25 ;
F_85 ( V_178 , & V_152 . V_25 ) ;
return F_86 ( V_2 , & V_152 ) ;
}
static inline void F_108 ( struct V_32 * V_38 , T_6 V_91 ,
V_59 V_96 , T_6 V_92 , void * V_105 , T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type )
{
V_38 -> V_92 = V_92 ;
V_38 -> V_96 = V_96 ;
V_38 -> V_91 = V_91 ;
V_38 -> V_105 = V_105 ;
V_38 -> V_194 = V_194 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_71 = type ;
V_38 -> V_189 = F_27 ;
V_38 -> V_176 = F_28 ;
V_38 -> V_190 = F_32 ;
V_38 -> V_173 = F_40 ;
}
static inline void F_109 ( struct V_39 * V_4 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_155 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_203 = F_105 ;
V_4 -> V_21 = F_82 ;
V_4 -> V_204 = F_96 ;
V_4 -> V_205 = F_95 ;
F_108 ( & V_4 -> V_38 , V_91 , V_96 , V_92 , V_105 , V_194 ,
V_33 , V_34 , type ) ;
}
void F_110 ( struct V_1 * V_2 ,
struct V_39 * V_206 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 )
{
union V_6 * V_207 = (union V_6 * ) V_206 ;
F_109 ( V_206 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_206 -> V_164 = F_42 ;
V_206 -> V_166 = F_47 ;
V_206 -> V_183 = F_41 ;
V_206 -> V_196 = F_46 ;
if ( F_111 ( V_2 ) ) {
V_206 -> V_192 = F_78 ;
V_206 -> V_68 = F_57 ;
V_206 -> V_69 = F_53 ;
V_206 -> V_170 = F_61 ;
V_206 -> V_193 = V_208 ;
F_1 ( V_2 ,
& V_206 -> V_12 , 1 , V_207 ,
F_93 ,
F_94 ,
F_97 ,
F_99 ,
F_87 ) ;
} else {
V_206 -> V_192 = F_70 ;
V_206 -> V_68 = F_57 ;
V_206 -> V_69 = F_53 ;
V_206 -> V_170 = F_60 ;
V_206 -> V_193 =
V_209 ;
V_206 -> V_210 = F_51 ;
F_1 ( V_2 ,
& V_206 -> V_12 , V_211 ,
V_207 , F_93 ,
F_94 ,
F_97 ,
F_99 ,
F_87 ) ;
}
}
void F_112 ( struct V_1 * V_2 ,
struct V_39 * V_212 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_46 )
{
union V_6 * V_207 = (union V_6 * ) V_212 ;
F_109 ( V_212 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_212 -> V_164 = F_44 ;
V_212 -> V_166 = F_49 ;
V_212 -> V_183 = F_43 ;
V_212 -> V_196 = F_48 ;
if ( F_111 ( V_2 ) ) {
F_12 ( L_44 ) ;
F_113 () ;
} else {
V_212 -> V_192 = F_79 ;
V_212 -> V_68 = F_58 ;
V_212 -> V_69 = F_55 ;
V_212 -> V_170 = F_60 ;
V_212 -> V_193 =
V_209 ;
F_1 ( V_2 ,
& V_212 -> V_12 , V_211 ,
V_207 , F_93 ,
F_94 ,
F_97 ,
F_99 ,
F_88 ) ;
}
}
void F_114 ( struct V_1 * V_2 ,
struct V_39 * V_154 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_207 =
(union V_6 * ) V_154 ;
F_109 ( V_154 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_154 -> V_164 = F_45 ;
V_154 -> V_166 = F_50 ;
V_154 -> V_183 = F_41 ;
V_154 -> V_196 = F_46 ;
if ( F_115 ( V_2 ) ) {
F_12 ( L_45 ) ;
F_113 () ;
} else if ( F_116 ( V_2 ) ) {
V_154 -> V_192 = F_81 ;
V_154 -> V_68 = F_59 ;
V_154 -> V_69 = F_56 ;
V_154 -> V_170 = F_61 ;
V_154 -> V_193 = V_208 ;
F_1 ( V_2 ,
& V_154 -> V_12 , 1 , V_207 ,
F_93 ,
F_94 ,
F_97 ,
F_99 ,
F_89 ) ;
} else {
V_154 -> V_192 = F_80 ;
V_154 -> V_68 = F_59 ;
V_154 -> V_69 = F_56 ;
V_154 -> V_170 = F_60 ;
V_154 -> V_193 =
V_209 ;
F_1 ( V_2 ,
& V_154 -> V_12 ,
V_211 ,
V_207 , F_93 ,
F_94 ,
F_97 ,
F_99 ,
F_89 ) ;
}
}
static inline void F_117 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
T_7 V_132 )
{
T_10 V_215 = sizeof( struct V_213 ) ;
V_59 V_216 = V_217 +
F_118 ( V_132 ) ;
F_119 ( V_2 , V_216 , V_215 , ( V_59 * ) V_214 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
V_59 V_219 = ( 1 << V_152 -> V_91 ) ;
struct V_213 * V_214 =
(struct V_213 * ) V_152 -> V_105 ;
T_6 V_220 = 1 , V_221 = 1 ;
T_6 V_222 = 0 , V_223 = 0 , V_224 = 0 ;
T_6 V_225 = 0 ;
if ( F_20 ( V_226 , & V_152 -> V_227 ) )
V_220 = 0 ;
if ( F_20 ( V_228 , & V_152 -> V_227 ) )
V_221 = 0 ;
if ( F_20 ( V_229 , & V_152 -> V_227 ) ) {
V_220 = 0 ;
V_222 = 1 ;
}
if ( F_20 ( V_230 , & V_152 -> V_227 ) ) {
V_221 = 0 ;
V_224 = 1 ;
}
if ( F_20 ( V_231 , & V_152 -> V_227 ) )
V_223 = 1 ;
if ( F_20 ( V_232 , & V_152 -> V_227 ) )
V_225 = 1 ;
V_214 -> V_233 = V_220 ?
V_214 -> V_233 | V_219 :
V_214 -> V_233 & ~ V_219 ;
V_214 -> V_234 = V_221 ?
V_214 -> V_234 | V_219 :
V_214 -> V_234 & ~ V_219 ;
V_214 -> V_235 = V_222 ?
V_214 -> V_235 | V_219 :
V_214 -> V_235 & ~ V_219 ;
V_214 -> V_236 = V_224 ?
V_214 -> V_236 | V_219 :
V_214 -> V_236 & ~ V_219 ;
V_214 -> V_237 = V_223 ?
V_214 -> V_237 | V_219 :
V_214 -> V_237 & ~ V_219 ;
V_214 -> V_225 = V_225 ?
V_214 -> V_225 | V_219 :
V_214 -> V_225 & ~ V_219 ;
F_4 ( V_17 , L_46
L_47 ,
V_214 -> V_233 ,
V_214 -> V_234 ,
V_214 -> V_235 ,
V_214 -> V_236 ,
V_214 -> V_237 ) ;
F_117 ( V_2 , V_214 , V_152 -> V_92 ) ;
F_30 ( V_152 -> V_33 , V_152 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_121 ( V_59 V_96 ,
struct V_97 * V_89 ,
T_6 V_98 )
{
V_89 -> V_99 = V_96 ;
V_89 -> V_98 = V_98 ;
}
static inline void F_122 ( struct V_1 * V_2 ,
unsigned long V_238 ,
struct V_239 * V_106 ,
bool V_240 )
{
T_7 V_33 ;
V_33 = V_241 |
V_242 ;
if ( V_238 ) {
if ( F_20 ( V_226 , & V_238 ) )
V_33 &= ~ V_241 ;
if ( F_20 ( V_228 , & V_238 ) )
V_33 &= ~ V_242 ;
if ( F_20 ( V_229 , & V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_243 ;
}
if ( F_20 ( V_230 , & V_238 ) ) {
V_33 |= V_244 ;
V_33 &= ~ V_242 ;
}
if ( F_20 ( V_231 , & V_238 ) )
V_33 |= V_245 ;
if ( F_20 ( V_232 , & V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_246 ;
}
if ( F_20 ( V_247 , & V_238 ) )
V_33 |= V_248 ;
}
if ( V_240 ) {
V_33 &= ~ V_244 ;
V_33 &= ~ V_245 ;
V_33 &= ~ V_243 ;
V_33 &= ~ V_246 ;
}
V_106 -> V_33 = F_75 ( V_33 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
struct V_249 * V_61 = V_152 -> V_105 ;
int V_22 ;
T_6 V_102 = 0 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
if ( F_20 ( V_250 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_152 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_251 ;
F_122 ( V_2 , V_152 -> V_252 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) , false ) ;
}
if ( F_20 ( V_253 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_152 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_254 ;
F_122 ( V_2 , V_152 -> V_227 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) , false ) ;
}
if ( F_20 ( V_255 , & V_152 -> V_256 ) ) {
if ( F_20 ( V_250 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_124 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_251 ;
F_122 ( V_2 , V_152 -> V_252 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
true ) ;
}
if ( F_20 ( V_253 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_124 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_254 ;
F_122 ( V_2 , V_152 -> V_227 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
true ) ;
}
}
F_121 ( V_152 -> V_96 , & V_61 -> V_119 , V_102 ) ;
F_4 ( V_17 , L_48
L_49 ,
V_61 -> V_119 . V_98 , V_152 -> V_227 ,
V_152 -> V_252 ) ;
V_22 = F_101 ( V_2 , V_257 , V_152 -> V_96 ,
F_102 ( V_152 -> V_194 ) ,
F_103 ( V_152 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
return F_34 ( V_2 , V_152 -> V_33 , V_152 -> V_34 ) ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
return 0 ;
}
int F_127 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
int V_22 ;
V_22 = V_152 -> V_258 -> V_259 ( V_2 , V_152 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_20 ( V_199 , & V_152 -> V_25 ) ) {
V_22 = V_152 -> V_258 -> V_173 ( V_2 , V_152 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
if ( F_111 ( V_2 ) ) {
V_4 -> V_173 = F_126 ;
V_4 -> V_259 = F_120 ;
} else {
V_4 -> V_173 = F_125 ;
V_4 -> V_259 = F_123 ;
}
}
static inline T_6 F_129 ( T_6 * V_57 )
{
return ( F_130 ( 0 , V_57 , V_58 ) >> 24 ) & 0xff ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_262 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_173 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_152 ,
int V_106 )
{
int V_264 ;
struct V_265 * V_266 ;
struct V_267 * V_268 = NULL ;
struct V_269 * V_52 ;
int V_270 = ( ( V_106 == V_271 ) ?
V_152 -> V_272 : 0 ) ;
if ( ! V_152 -> V_272 )
return 0 ;
V_264 = sizeof( * V_266 ) +
V_270 * sizeof( struct V_267 ) ;
V_266 = F_26 ( V_264 , V_31 ) ;
if ( ! V_266 )
return - V_182 ;
F_4 ( V_17 , L_50
L_51 , V_106 , V_270 ) ;
F_2 ( & V_266 -> V_61 . V_273 ) ;
V_266 -> type = V_106 ;
V_266 -> V_274 = false ;
switch ( V_106 ) {
case V_271 :
V_268 = (struct V_267 * )
( ( T_6 * ) V_266 + sizeof( * V_266 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_268 -> V_57 , V_52 -> V_57 , V_58 ) ;
F_13 ( & V_268 -> V_24 , & V_266 -> V_61 . V_273 ) ;
V_268 ++ ;
}
break;
case V_275 :
V_266 -> V_61 . V_276 = V_152 -> V_272 ;
break;
case V_277 :
V_266 -> V_61 . V_278 = 0 ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return - V_62 ;
}
F_13 ( & V_266 -> V_24 , & V_4 -> V_279 ) ;
V_4 -> V_280 ( V_4 ) ;
return 1 ;
}
static inline int F_133 ( struct V_261 * V_4 , int V_281 )
{
int V_282 , V_283 , V_284 = V_281 % V_285 ;
for ( V_282 = V_281 / V_285 ; V_282 < V_286 ; V_282 ++ ) {
if ( V_4 -> V_287 . V_288 . V_289 [ V_282 ] )
for ( V_283 = V_284 ; V_283 < V_285 ; V_283 ++ ) {
int V_290 = V_283 + V_285 * V_282 ;
if ( F_134 ( V_4 -> V_287 . V_288 .
V_289 , V_290 ) ) {
return V_290 ;
}
}
V_284 = 0 ;
}
return - 1 ;
}
static inline int F_135 ( struct V_261 * V_4 )
{
int V_290 = F_133 ( V_4 , 0 ) ;
if ( V_290 >= 0 )
F_136 ( V_4 -> V_287 . V_288 . V_289 , V_290 ) ;
return V_290 ;
}
static inline T_6 F_137 ( struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_70 = 0 ;
if ( ( V_38 -> V_71 == V_72 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_291 ;
if ( ( V_38 -> V_71 == V_75 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_292 ;
return V_70 ;
}
static void F_138 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_187 ,
union V_293 * V_294 ,
int V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_295 * V_61 =
(struct V_295 * ) ( V_125 -> V_105 ) ;
T_6 V_92 = V_125 -> V_92 ;
T_6 V_296 = F_137 ( V_4 ) ;
int V_297 ;
if ( ( V_106 == V_271 ) || ( V_106 == V_277 ) )
V_296 |= V_298 ;
V_61 -> V_110 [ V_187 ] . V_93 |= V_296 ;
switch ( V_106 ) {
case V_271 :
V_297 = F_129 ( V_294 -> V_57 ) ;
F_139 ( V_4 -> V_287 . V_288 . V_289 , V_297 ) ;
break;
case V_275 :
V_297 = F_135 ( V_4 ) ;
break;
case V_277 :
V_297 = V_294 -> V_297 ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return;
}
F_4 ( V_17 , L_53 ,
( ( V_296 & V_298 ) ?
L_54 : L_55 ) , V_297 ) ;
V_61 -> V_110 [ V_187 ] . V_299 = ( T_6 ) V_297 ;
V_61 -> V_110 [ V_187 ] . V_92 = V_92 ;
V_61 -> V_110 [ V_187 ] . V_300 = V_4 -> V_300 ;
}
static inline int F_140 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_301 ,
int * V_302 )
{
int V_303 , V_20 = * V_302 ;
union V_293 V_294 = { 0 } ;
for ( V_303 = F_133 ( V_4 , V_301 ) ; V_303 >= 0 ;
V_303 = F_133 ( V_4 , V_303 + 1 ) ) {
V_294 . V_297 = ( T_6 ) V_303 ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_294 ,
V_277 ) ;
V_20 ++ ;
F_4 ( V_17 , L_56 , V_303 ) ;
if ( V_20 >= V_4 -> V_304 )
break;
}
* V_302 = V_20 ;
return V_303 ;
}
static inline void F_141 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_265 * V_305 ,
int * V_306 )
{
struct V_267 * V_307 , * V_308 ;
int V_20 = * V_306 ;
union V_293 V_294 = { 0 } ;
F_106 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_294 . V_57 = & V_307 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_294 , V_305 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_57 ,
V_307 -> V_57 ) ;
F_17 ( & V_307 -> V_24 ) ;
if ( V_20 >= V_4 -> V_304 )
break;
}
* V_306 = V_20 ;
if ( F_15 ( & V_305 -> V_61 . V_273 ) )
V_305 -> V_274 = true ;
}
static inline void F_142 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_265 * V_305 ,
int * V_306 )
{
int V_20 = * V_306 ;
while ( V_305 -> V_61 . V_276 ) {
V_4 -> V_192 ( V_2 , V_4 , V_20 , NULL , V_305 -> type ) ;
V_20 ++ ;
V_305 -> V_61 . V_276 -- ;
F_4 ( V_17 , L_58 ,
V_305 -> V_61 . V_276 , V_20 ) ;
if ( V_20 >= V_4 -> V_304 )
break;
}
* V_306 = V_20 ;
if ( ! V_305 -> V_61 . V_276 )
V_305 -> V_274 = true ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_265 * V_305 ,
int * V_306 )
{
V_305 -> V_61 . V_278 = V_4 -> V_309 ( V_2 , V_4 , V_305 -> V_61 . V_278 ,
V_306 ) ;
if ( V_305 -> V_61 . V_278 < 0 )
V_305 -> V_274 = true ;
else
V_305 -> V_61 . V_278 ++ ;
}
static inline int F_144 ( struct V_1 * V_2 ,
struct V_263 * V_152 )
{
struct V_265 * V_305 , * V_310 ;
int V_20 = 0 ;
struct V_261 * V_4 = V_152 -> V_311 ;
F_106 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_305 -> type ) {
case V_271 :
F_141 ( V_2 , V_4 , V_305 , & V_20 ) ;
break;
case V_275 :
F_142 ( V_2 , V_4 , V_305 , & V_20 ) ;
break;
case V_277 :
F_143 ( V_2 , V_4 , V_305 ,
& V_20 ) ;
break;
default:
F_12 ( L_52 , V_305 -> type ) ;
return - V_62 ;
}
if ( V_305 -> V_274 ) {
F_17 ( & V_305 -> V_24 ) ;
F_6 ( V_305 ) ;
}
if ( V_20 >= V_4 -> V_304 )
break;
}
return V_20 ;
}
static inline void F_145 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
int * V_306 )
{
struct V_269 * V_312 ;
union V_293 V_294 = { 0 } ;
int V_20 = * V_306 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_294 . V_57 = V_312 -> V_57 ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_294 , V_271 ) ;
V_20 ++ ;
F_4 ( V_17 , L_57 ,
V_312 -> V_57 ) ;
}
* V_306 = V_20 ;
}
static inline void F_146 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
int * V_306 )
{
int V_20 = * V_306 , V_282 ;
for ( V_282 = 0 ; V_282 < V_152 -> V_272 ; V_282 ++ ) {
V_4 -> V_192 ( V_2 , V_4 , V_20 , NULL , V_275 ) ;
V_20 ++ ;
F_4 ( V_17 , L_59 ,
V_152 -> V_272 - V_282 - 1 ) ;
}
* V_306 = V_20 ;
}
static inline int F_147 ( struct V_1 * V_2 ,
struct V_263 * V_152 , int V_106 ,
int V_313 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
int V_20 = V_313 ;
F_4 ( V_17 , L_60 , V_152 -> V_272 ) ;
switch ( V_106 ) {
case V_271 :
F_145 ( V_2 , V_4 , V_152 , & V_20 ) ;
break;
case V_275 :
F_146 ( V_2 , V_4 , V_152 , & V_20 ) ;
break;
case V_277 :
V_4 -> V_309 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return - V_62 ;
}
V_152 -> V_272 = 0 ;
return V_20 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
int V_314 = V_4 -> V_315 ( V_4 ) ;
switch ( V_106 ) {
case V_275 :
V_4 -> V_316 ( V_4 , 0 ) ;
case V_277 :
V_152 -> V_272 = V_314 ;
break;
case V_271 :
case V_317 :
V_4 -> V_316 ( V_4 , V_314 + V_152 -> V_272 ) ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return - V_62 ;
}
V_4 -> V_318 += V_152 -> V_272 ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_319 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
V_4 -> V_316 ( V_4 , V_319 ) ;
V_4 -> V_318 -= V_152 -> V_272 ;
}
static inline void F_150 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
T_6 V_320 )
{
struct V_32 * V_125 = & V_152 -> V_311 -> V_38 ;
struct V_295 * V_61 =
(struct V_295 * ) ( V_125 -> V_105 ) ;
V_61 -> V_119 . V_99 = ( ( V_125 -> V_96 & V_100 ) |
( V_321 << V_101 ) ) ;
V_61 -> V_119 . V_98 = V_320 ;
}
static inline int F_151 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
int V_282 , V_20 = 0 ;
T_11 V_19 ;
for ( V_282 = 0 ; V_282 < V_286 ; V_282 ++ ) {
V_19 = V_4 -> V_287 . V_288 . V_289 [ V_282 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_316 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
struct V_32 * V_38 = & V_152 -> V_311 -> V_38 ;
struct V_261 * V_4 = V_152 -> V_311 ;
struct V_295 * V_61 =
(struct V_295 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_20 = F_144 ( V_2 , V_152 ) ;
if ( F_15 ( & V_4 -> V_279 ) )
V_4 -> V_322 ( V_4 ) ;
if ( V_152 -> V_272 > 0 )
V_20 = F_147 ( V_2 , V_152 , V_106 , V_20 ) ;
V_4 -> V_318 -= V_20 ;
F_21 ( V_4 -> V_318 < 0 ) ;
F_21 ( V_20 > V_4 -> V_304 ) ;
F_150 ( V_2 , V_152 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_318 )
F_151 ( V_2 , V_4 ) ;
if ( F_20 ( V_28 , & V_152 -> V_25 ) ) {
V_38 -> V_176 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_101 ( V_2 , V_323 ,
V_38 -> V_96 , F_102 ( V_38 -> V_194 ) ,
F_103 ( V_38 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_153 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
if ( ( V_106 == V_275 ) || ( V_106 == V_277 ) )
V_152 -> V_272 = 1 ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_319 )
{
}
static inline void F_155 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_152 ,
V_59 * V_324 )
{
struct V_269 * V_312 ;
int V_325 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_325 = F_129 ( V_312 -> V_57 ) ;
F_156 ( V_324 , V_325 ) ;
F_4 ( V_17 , L_61 ,
V_312 -> V_57 , V_325 ) ;
F_139 ( V_4 -> V_287 . V_288 . V_289 ,
V_325 ) ;
}
}
static inline void F_157 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
V_59 * V_324 )
{
int V_325 ;
for ( V_325 = F_133 ( V_4 , 0 ) ;
V_325 >= 0 ;
V_325 = F_133 ( V_4 , V_325 + 1 ) ) {
F_156 ( V_324 , V_325 ) ;
F_4 ( V_17 , L_62 , V_325 ) ;
}
}
static int F_158 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
int V_282 ;
struct V_261 * V_4 = V_152 -> V_311 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( ! F_20 ( V_28 , & V_152 -> V_25 ) ) {
V_59 V_324 [ V_326 ] = { 0 } ;
switch ( V_106 ) {
case V_271 :
F_155 ( V_2 , V_4 , V_152 , V_324 ) ;
break;
case V_275 :
F_4 ( V_17 ,
L_63 ) ;
memset ( V_4 -> V_287 . V_288 . V_289 , 0 ,
sizeof( V_4 -> V_287 . V_288 . V_289 ) ) ;
break;
case V_277 :
F_157 ( V_2 , V_4 , V_152 , V_324 ) ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return - V_62 ;
}
for ( V_282 = 0 ; V_282 < V_326 ; V_282 ++ )
F_67 ( V_2 , F_159 ( V_2 , V_282 ) , V_324 [ V_282 ] ) ;
} else
memset ( V_4 -> V_287 . V_288 . V_289 , 0 ,
sizeof( V_4 -> V_287 . V_288 . V_289 ) ) ;
V_125 -> V_176 ( V_125 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
int V_314 = V_4 -> V_315 ( V_4 ) ;
switch ( V_106 ) {
case V_275 :
V_4 -> V_316 ( V_4 , 0 ) ;
case V_277 :
V_152 -> V_272 = V_314 ;
F_4 ( V_17 , L_64 ,
V_106 , V_152 -> V_272 ) ;
break;
case V_271 :
case V_317 :
if ( V_152 -> V_272 > V_4 -> V_304 ) {
F_12 ( L_65
L_66 , V_4 -> V_304 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_60 , V_152 -> V_272 ) ;
if ( V_152 -> V_272 > 0 )
V_4 -> V_316 ( V_4 , V_152 -> V_272 ) ;
break;
default:
F_12 ( L_52 , V_106 ) ;
return - V_62 ;
}
if ( V_152 -> V_272 )
V_4 -> V_318 += V_4 -> V_304 ;
return 0 ;
}
static void F_161 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_327 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
V_4 -> V_316 ( V_4 , V_327 ) ;
if ( V_152 -> V_272 )
V_4 -> V_318 -= V_4 -> V_304 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_187 ,
union V_293 * V_294 ,
int V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
if ( ( V_106 == V_271 ) || ( V_106 == V_277 ) ) {
F_71 ( & V_61 -> V_143 [ V_187 ] . V_137 ,
& V_61 -> V_143 [ V_187 ] . V_138 ,
& V_61 -> V_143 [ V_187 ] . V_139 ,
V_294 -> V_57 ) ;
V_61 -> V_143 [ V_187 ] . V_127 = 0 ;
V_61 -> V_143 [ V_187 ] . V_132 = V_125 -> V_92 ;
V_61 -> V_143 [ V_187 ] . V_131 =
F_74 ( 1 << V_125 -> V_91 ) ;
F_76 ( V_61 -> V_143 [ V_187 ] . V_133 ,
V_134 ,
V_135 ) ;
}
}
static inline void F_163 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
T_6 V_320 )
{
struct V_32 * V_125 = & V_152 -> V_311 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
T_6 V_40 = ( F_164 ( V_2 ) ?
V_328 * ( 1 + V_125 -> V_92 ) :
V_329 * ( 1 + V_125 -> V_92 ) ) ;
V_61 -> V_89 . V_40 = V_40 ;
V_61 -> V_89 . V_90 = 0xff ;
V_61 -> V_89 . V_99 = ( ( V_125 -> V_96 & V_100 ) |
( V_321 << V_101 ) ) ;
V_61 -> V_89 . V_126 = V_320 ;
}
static inline int F_165 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_330 ,
int * V_302 )
{
struct V_267 * V_19 ;
int V_282 = 0 ;
union V_293 V_294 = { 0 } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_294 . V_57 = & V_19 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_282 , & V_294 , V_277 ) ;
V_282 ++ ;
F_4 ( V_17 , L_57 ,
V_294 . V_57 ) ;
}
* V_302 = V_282 ;
return - 1 ;
}
static inline int F_166 (
struct V_1 * V_2 , struct V_263 * V_152 )
{
struct V_265 * V_305 ;
struct V_267 * V_307 ;
struct V_261 * V_4 = V_152 -> V_311 ;
union V_293 V_294 = { 0 } ;
int V_20 = 0 ;
if ( F_15 ( & V_4 -> V_279 ) )
return 0 ;
V_305 = F_16 ( & V_4 -> V_279 ,
struct V_265 , V_24 ) ;
switch ( V_305 -> type ) {
case V_271 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_294 . V_57 = & V_307 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_294 , V_305 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_57 ,
V_307 -> V_57 ) ;
}
break;
case V_275 :
V_20 = V_305 -> V_61 . V_276 ;
F_4 ( V_17 , L_67 , V_20 ) ;
break;
case V_277 :
V_4 -> V_309 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_52 , V_305 -> type ) ;
return - V_62 ;
}
F_17 ( & V_305 -> V_24 ) ;
F_6 ( V_305 ) ;
return V_20 ;
}
static inline void F_167 ( T_12 * V_331 , T_12 * V_332 ,
T_12 * V_333 , T_6 * V_57 )
{
V_57 [ 1 ] = ( ( T_6 * ) V_331 ) [ 0 ] ;
V_57 [ 0 ] = ( ( T_6 * ) V_331 ) [ 1 ] ;
V_57 [ 3 ] = ( ( T_6 * ) V_332 ) [ 0 ] ;
V_57 [ 2 ] = ( ( T_6 * ) V_332 ) [ 1 ] ;
V_57 [ 5 ] = ( ( T_6 * ) V_333 ) [ 0 ] ;
V_57 [ 4 ] = ( ( T_6 * ) V_333 ) [ 1 ] ;
}
static inline int F_168 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_267 * V_19 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
if ( F_169 ( V_61 -> V_143 [ 0 ] . V_133 ,
V_134 ) ) {
int V_282 , V_320 = V_61 -> V_89 . V_126 ;
if ( ! F_15 ( & V_4 -> V_287 . V_334 . V_335 ) )
return 0 ;
V_19 = F_170 ( V_320 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_12 ( L_68 ) ;
return - V_182 ;
}
for ( V_282 = 0 ; V_282 < V_320 ; V_282 ++ , V_19 ++ ) {
F_167 (
& V_61 -> V_143 [ V_282 ] . V_137 ,
& V_61 -> V_143 [ V_282 ] . V_138 ,
& V_61 -> V_143 [ V_282 ] . V_139 ,
V_19 -> V_57 ) ;
F_4 ( V_17 , L_69 ,
V_19 -> V_57 ) ;
F_13 ( & V_19 -> V_24 ,
& V_4 -> V_287 . V_334 . V_335 ) ;
}
} else {
V_19 = F_16 ( & V_4 -> V_287 . V_334 . V_335 ,
struct V_267 , V_24 ) ;
F_4 ( V_17 , L_70 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_287 . V_334 . V_335 ) ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_282 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
for ( V_282 = 0 ; V_282 < V_4 -> V_304 ; V_282 ++ )
F_76 ( V_61 -> V_143 [ V_282 ] . V_133 ,
V_134 ,
V_140 ) ;
V_20 = F_166 ( V_2 , V_152 ) ;
if ( F_15 ( & V_4 -> V_279 ) )
V_4 -> V_322 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_147 ( V_2 , V_152 , V_106 , 0 ) ;
V_4 -> V_318 -= V_4 -> V_304 ;
F_21 ( V_20 > V_4 -> V_304 ) ;
F_163 ( V_2 , V_152 , ( T_6 ) V_20 ) ;
V_22 = F_168 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_20 ( V_28 , & V_152 -> V_25 ) ) {
V_38 -> V_176 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_101 ( V_2 , V_208 , V_38 -> V_96 ,
F_102 ( V_38 -> V_194 ) ,
F_103 ( V_38 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_172 ( struct V_261 * V_4 )
{
return V_4 -> V_287 . V_334 . V_336 ;
}
static int F_173 ( struct V_261 * V_4 )
{
return V_4 -> V_287 . V_288 . V_337 ;
}
static void F_174 ( struct V_261 * V_4 ,
int V_49 )
{
V_4 -> V_287 . V_334 . V_336 = V_49 ;
}
static void F_175 ( struct V_261 * V_4 ,
int V_49 )
{
V_4 -> V_287 . V_288 . V_337 = V_49 ;
}
int F_176 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_106 )
{
struct V_261 * V_4 = V_152 -> V_311 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 = 0 , V_338 ;
V_338 = V_4 -> V_315 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_152 , V_106 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_152 -> V_272 ) && ( ! V_4 -> V_339 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_71
L_72 , V_4 -> V_318 ,
V_152 -> V_272 , V_4 -> V_304 ) ;
if ( V_125 -> V_189 ( V_125 ) ||
( ( V_4 -> V_304 > 0 ) && ( V_4 -> V_318 > V_4 -> V_304 ) ) ) {
V_22 = V_4 -> V_340 ( V_2 , V_152 -> V_311 , V_152 , V_106 ) ;
if ( V_22 < 0 )
goto V_341;
V_152 -> V_272 = 0 ;
}
if ( ! V_125 -> V_189 ( V_125 ) ) {
V_125 -> V_190 ( V_125 ) ;
V_22 = V_4 -> V_342 ( V_2 , V_152 , V_106 ) ;
if ( V_22 < 0 )
goto V_343;
if ( F_20 ( V_199 , & V_152 -> V_25 ) )
V_22 = V_4 -> V_173 ( V_2 , V_4 ) ;
}
return V_22 ;
V_343:
V_125 -> V_176 ( V_125 ) ;
V_341:
V_4 -> V_344 ( V_2 , V_152 , V_338 ) ;
return V_22 ;
}
static void F_177 ( struct V_261 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_178 ( struct V_261 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_179 ( struct V_261 * V_4 )
{
return ! ! F_20 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
}
static bool F_180 ( struct V_261 * V_4 )
{
return V_4 -> V_38 . V_189 ( & V_4 -> V_38 ) || V_4 -> V_339 ( V_4 ) ;
}
void F_181 ( struct V_1 * V_2 ,
struct V_261 * V_311 ,
T_6 V_345 , V_59 V_346 , T_6 V_92 ,
T_6 V_300 , void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 , T_9 type )
{
memset ( V_311 , 0 , sizeof( * V_311 ) ) ;
F_108 ( & V_311 -> V_38 , V_345 , V_346 , V_92 ,
V_105 , V_194 , V_33 , V_34 , type ) ;
V_311 -> V_300 = V_300 ;
F_2 ( & V_311 -> V_279 ) ;
V_311 -> V_262 = V_347 ;
V_311 -> V_339 = F_179 ;
V_311 -> V_280 = F_178 ;
V_311 -> V_322 = F_177 ;
if ( F_115 ( V_2 ) ) {
V_311 -> V_342 = F_171 ;
V_311 -> V_340 = F_132 ;
V_311 -> V_309 =
F_165 ;
V_311 -> V_189 = F_180 ;
if ( F_164 ( V_2 ) )
V_311 -> V_304 = V_328 ;
else
V_311 -> V_304 = V_329 ;
V_311 -> V_173 = F_131 ;
V_311 -> V_192 = F_162 ;
V_311 -> V_8 = F_160 ;
V_311 -> V_344 = F_161 ;
V_311 -> V_315 =
F_172 ;
V_311 -> V_316 =
F_174 ;
F_2 ( & V_311 -> V_287 . V_334 . V_335 ) ;
} else if ( F_116 ( V_2 ) ) {
V_311 -> V_342 = F_158 ;
V_311 -> V_340 = NULL ;
V_311 -> V_309 = NULL ;
V_311 -> V_189 = F_180 ;
V_311 -> V_304 = - 1 ;
V_311 -> V_173 = F_131 ;
V_311 -> V_192 = NULL ;
V_311 -> V_8 = F_153 ;
V_311 -> V_344 = F_154 ;
V_311 -> V_315 =
F_173 ;
V_311 -> V_316 =
F_175 ;
} else {
V_311 -> V_342 = F_152 ;
V_311 -> V_340 = F_132 ;
V_311 -> V_309 =
F_140 ;
V_311 -> V_189 = F_180 ;
V_311 -> V_304 = 16 ;
V_311 -> V_173 = F_131 ;
V_311 -> V_192 = F_138 ;
V_311 -> V_8 = F_148 ;
V_311 -> V_344 = F_149 ;
V_311 -> V_315 =
F_173 ;
V_311 -> V_316 =
F_175 ;
}
}
static inline bool F_182 ( T_13 * V_348 , int V_349 , int V_56 )
{
int V_350 , V_351 ;
V_350 = F_183 ( V_348 ) ;
for (; ; ) {
if ( F_184 ( V_350 + V_349 >= V_56 ) )
return false ;
V_351 = F_185 ( ( V_348 ) , V_350 , V_350 + V_349 ) ;
if ( F_186 ( V_351 == V_350 ) )
break;
V_350 = V_351 ;
}
return true ;
}
static inline bool F_187 ( T_13 * V_348 , int V_349 , int V_56 )
{
int V_350 , V_351 ;
V_350 = F_183 ( V_348 ) ;
for (; ; ) {
if ( F_184 ( V_350 - V_349 < V_56 ) )
return false ;
V_351 = F_185 ( ( V_348 ) , V_350 , V_350 - V_349 ) ;
if ( F_186 ( V_351 == V_350 ) )
break;
V_350 = V_351 ;
}
return true ;
}
static bool F_188 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_189 () ;
V_22 = F_187 ( & V_4 -> V_352 , V_20 , 0 ) ;
F_189 () ;
return V_22 ;
}
static bool F_190 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_189 () ;
V_22 = F_182 ( & V_4 -> V_352 , V_20 , V_4 -> V_353 + 1 ) ;
F_189 () ;
return V_22 ;
}
static int F_191 ( struct V_41 * V_4 )
{
int V_354 ;
F_189 () ;
V_354 = F_183 ( & V_4 -> V_352 ) ;
return V_354 ;
}
static bool F_192 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_193 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_187 , V_289 , V_282 ;
* V_40 = - 1 ;
for ( V_289 = 0 ; V_289 < V_355 ; V_289 ++ ) {
if ( ! V_4 -> V_356 [ V_289 ] )
continue;
for ( V_187 = V_289 * V_355 , V_282 = 0 ;
V_282 < V_285 ; V_187 ++ , V_282 ++ )
if ( F_134 ( V_4 -> V_356 , V_187 ) ) {
F_136 ( V_4 -> V_356 , V_187 ) ;
* V_40 = V_4 -> V_357 + V_187 ;
return true ;
}
}
return false ;
}
static bool F_194 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_357 )
return false ;
V_40 -= V_4 -> V_357 ;
if ( V_40 >= V_4 -> V_353 )
return false ;
F_139 ( V_4 -> V_356 , V_40 ) ;
return true ;
}
static bool F_195 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_196 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_197 ( struct V_41 * V_152 ,
int V_358 , int V_352 )
{
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
memset ( & V_152 -> V_356 , 0xff , sizeof( V_152 -> V_356 ) ) ;
F_198 ( & V_152 -> V_352 , V_352 ) ;
V_152 -> V_353 = V_352 ;
V_152 -> V_357 = V_358 ;
F_189 () ;
V_152 -> V_359 = F_191 ;
if ( V_352 >= 0 ) {
V_152 -> V_47 = F_190 ;
V_152 -> V_11 = F_188 ;
V_152 -> V_48 = F_194 ;
V_152 -> V_44 = F_193 ;
} else {
V_152 -> V_47 = F_192 ;
V_152 -> V_11 = F_192 ;
V_152 -> V_48 = F_195 ;
V_152 -> V_44 = F_196 ;
}
if ( V_358 < 0 ) {
V_152 -> V_48 = F_195 ;
V_152 -> V_44 = F_196 ;
}
}
void F_199 ( struct V_1 * V_2 ,
struct V_41 * V_152 , T_6 V_92 ,
T_6 V_360 )
{
#define F_200 5
int V_361 ;
if ( F_115 ( V_2 ) ) {
if ( ! F_164 ( V_2 ) )
V_361 = ( V_362 / 2 ) - V_329 ;
else
V_361 = F_200 - V_328 ;
F_197 ( V_152 , V_92 * V_361 , V_361 ) ;
} else if ( F_116 ( V_2 ) ) {
if ( ( V_360 > 0 ) ) {
if ( ! F_164 ( V_2 ) )
V_361 = ( V_363 / ( 2 * V_360 ) ) ;
else
V_361 = F_200 ;
F_197 ( V_152 , V_92 * V_361 , V_361 ) ;
} else {
F_197 ( V_152 , 0 , 0 ) ;
}
} else {
if ( ( V_360 > 0 ) ) {
if ( ! F_164 ( V_2 ) )
V_361 = ( V_364 / V_360 ) ;
else
V_361 = F_200 ;
F_197 ( V_152 , - 1 , V_361 ) ;
} else {
F_197 ( V_152 , 0 , 0 ) ;
}
}
}
void F_201 ( struct V_1 * V_2 ,
struct V_41 * V_152 ,
T_6 V_92 ,
T_6 V_360 )
{
if ( F_111 ( V_2 ) ) {
F_197 ( V_152 , 0 , - 1 ) ;
} else {
if ( V_360 > 0 ) {
int V_352 = V_365 / V_360 ;
F_197 ( V_152 , V_92 * V_352 , V_352 ) ;
} else
F_197 ( V_152 , 0 , 0 ) ;
}
}
static inline void F_202 ( struct V_1 * V_2 ,
struct V_366 * V_152 )
{
int V_282 ;
F_4 ( V_17 , L_73 ) ;
F_4 ( V_17 , L_74 ) ;
for ( V_282 = 0 ; V_282 < V_367 ; V_282 ++ ) {
F_203 ( V_17 , L_75 , V_152 -> V_368 [ V_282 ] ) ;
if ( ( V_282 + 1 < V_367 ) &&
( ( ( V_282 + 1 ) & 0x3 ) == 0 ) ) {
F_203 ( V_17 , L_76 ) ;
F_4 ( V_17 , L_77 , V_282 + 1 ) ;
}
}
F_203 ( V_17 , L_76 ) ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_366 * V_152 )
{
struct V_369 * V_4 = V_152 -> V_370 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_371 * V_61 =
(struct V_371 * ) ( V_125 -> V_105 ) ;
T_6 V_372 = 0 ;
int V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_4 ( V_17 , L_78 ) ;
V_61 -> V_99 = ( V_125 -> V_96 & V_100 ) |
( V_125 -> V_33 << V_101 ) ;
if ( F_20 ( V_373 , & V_152 -> V_374 ) )
V_372 = V_375 ;
else if ( F_20 ( V_376 , & V_152 -> V_374 ) )
V_372 = V_377 ;
else if ( F_20 ( V_378 , & V_152 -> V_374 ) )
V_372 = V_379 ;
else if ( F_20 ( V_380 , & V_152 -> V_374 ) )
V_372 = V_381 ;
else if ( F_20 ( V_382 , & V_152 -> V_374 ) )
V_372 = V_383 ;
V_61 -> V_372 = V_372 ;
F_4 ( V_17 , L_79 , V_372 ) ;
if ( F_20 ( V_384 , & V_152 -> V_374 ) )
V_61 -> V_385 |=
V_386 ;
if ( F_20 ( V_387 , & V_152 -> V_374 ) )
V_61 -> V_385 |=
V_388 ;
if ( F_20 ( V_389 , & V_152 -> V_374 ) )
V_61 -> V_385 |=
V_390 ;
if ( F_20 ( V_391 , & V_152 -> V_374 ) )
V_61 -> V_385 |=
V_392 ;
V_61 -> V_393 = V_152 -> V_393 ;
V_61 -> V_394 = V_4 -> V_300 ;
F_4 ( V_17 , L_80 , V_61 -> V_394 ) ;
memcpy ( V_61 -> V_395 , V_152 -> V_368 ,
V_367 ) ;
memcpy ( V_4 -> V_368 , V_152 -> V_368 , V_367 ) ;
if ( F_205 ( V_2 ) )
F_202 ( V_2 , V_152 ) ;
if ( F_20 ( V_396 , & V_152 -> V_374 ) ) {
memcpy ( & V_61 -> V_397 [ 0 ] , & V_152 -> V_397 [ 0 ] ,
sizeof( V_61 -> V_397 ) ) ;
V_61 -> V_385 |= V_398 ;
}
V_22 = F_101 ( V_2 , V_399 , V_125 -> V_96 ,
F_102 ( V_125 -> V_194 ) ,
F_103 ( V_125 -> V_194 ) ,
V_195 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_206 ( struct V_369 * V_370 ,
T_6 * V_368 )
{
memcpy ( V_368 , V_370 -> V_368 , sizeof( V_370 -> V_368 ) ) ;
}
int F_207 ( struct V_1 * V_2 ,
struct V_366 * V_152 )
{
int V_22 ;
struct V_369 * V_4 = V_152 -> V_370 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( F_20 ( V_28 , & V_152 -> V_25 ) )
return 0 ;
V_125 -> V_190 ( V_125 ) ;
V_22 = V_4 -> V_400 ( V_2 , V_152 ) ;
if ( V_22 < 0 ) {
V_125 -> V_176 ( V_125 ) ;
return V_22 ;
}
if ( F_20 ( V_199 , & V_152 -> V_25 ) )
V_22 = V_125 -> V_173 ( V_2 , V_125 ) ;
return V_22 ;
}
void F_208 ( struct V_1 * V_2 ,
struct V_369 * V_370 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , T_6 V_300 ,
void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 ,
T_9 type )
{
F_108 ( & V_370 -> V_38 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ) ;
V_370 -> V_300 = V_300 ;
V_370 -> V_400 = F_204 ;
}
int F_209 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
int V_22 , V_405 ;
unsigned long * V_406 = & V_4 -> V_406 ;
if ( V_4 -> V_407 ( V_2 , V_4 , V_402 ) )
return - V_62 ;
V_405 = V_4 -> V_190 ( V_4 , V_402 ) ;
if ( F_20 ( V_28 , & V_402 -> V_25 ) )
V_4 -> V_408 ( V_2 , V_4 , V_405 ) ;
else {
V_22 = V_4 -> V_409 ( V_2 , V_402 ) ;
if ( V_22 ) {
V_4 -> V_410 = V_411 ;
F_30 ( V_405 , V_406 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_199 , & V_402 -> V_25 ) ) {
V_22 = V_4 -> V_173 ( V_2 , V_4 , V_405 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_405 , V_406 ) ;
}
static int F_210 ( struct V_403 * V_412 ,
struct V_401 * V_402 )
{
enum V_413 V_106 = V_402 -> V_106 , V_325 ;
if ( ( V_106 == V_414 ) ||
( V_106 == V_415 ) )
V_325 = V_416 ;
else
V_325 = V_106 ;
F_33 ( V_325 , & V_412 -> V_406 ) ;
return V_325 ;
}
static int F_211 ( struct V_1 * V_2 ,
struct V_403 * V_4 ,
enum V_413 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_406 ) ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_403 * V_4 ,
enum V_413 V_106 )
{
unsigned long V_417 = V_4 -> V_406 ;
if ( ! F_213 ( V_106 , & V_417 ) ) {
F_12 ( L_81
L_82 , V_106 ,
V_4 -> V_418 [ V_419 ] ,
V_4 -> V_33 , V_417 , V_4 -> V_410 ) ;
return - V_62 ;
}
if ( V_4 -> V_420 >= V_4 -> V_421 )
F_12 ( L_83 ,
V_4 -> V_420 , V_4 -> V_421 ) ;
F_4 ( V_17 , L_84
L_85 , V_106 ,
V_4 -> V_418 [ V_419 ] , V_4 -> V_410 ) ;
if ( V_4 -> V_420 )
F_4 ( V_17 , L_86 ,
V_4 -> V_418 [ V_419 ] , V_4 -> V_420 ) ;
V_4 -> V_33 = V_4 -> V_410 ;
V_4 -> V_422 = V_4 -> V_420 ;
V_4 -> V_410 = V_411 ;
F_214 () ;
F_30 ( V_106 , & V_4 -> V_406 ) ;
F_31 () ;
return 0 ;
}
static void F_215 ( struct V_1 * V_2 ,
struct V_401 * V_423 ,
struct V_424 * V_61 )
{
struct V_425 * V_402 = & V_423 -> V_402 . V_426 ;
V_61 -> V_427 . V_428 |= F_20 ( V_429 , & V_402 -> V_133 ) *
V_430 ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_403 * V_4 ,
struct V_431 * V_402 ,
struct V_432 * V_433 ,
unsigned long * V_133 )
{
V_433 -> V_90 = V_4 -> V_91 ;
if ( F_20 ( V_434 , V_133 ) ) {
V_433 -> V_435 =
V_402 -> V_436 ;
V_433 -> V_437 = 1 ;
V_433 -> V_438 =
F_20 ( V_439 , V_133 ) ;
} else
V_433 -> V_435 =
V_440 ;
V_433 -> V_441 = F_20 ( V_442 , V_133 ) ;
V_433 -> V_443 = F_20 ( V_444 , V_133 ) ;
V_433 -> V_445 = V_402 -> V_446 ;
V_433 -> V_447 = F_75 ( V_402 -> V_447 ) ;
V_433 -> V_92 = V_4 -> V_92 ;
V_433 -> cos = V_402 -> cos ;
V_433 -> V_448 =
F_20 ( V_442 , V_133 ) ?
V_449 : V_450 ;
F_4 ( V_17 , L_87 ,
V_433 -> V_443 , V_433 -> cos , V_433 -> V_437 ) ;
}
static void F_217 ( struct V_403 * V_4 ,
struct V_451 * V_402 ,
struct V_452 * V_453 ,
unsigned long * V_133 )
{
V_453 -> V_454 =
F_20 ( V_455 , V_133 ) ;
V_453 -> V_456 =
F_75 ( V_402 -> V_456 ) ;
V_453 -> V_457 =
F_20 ( V_458 , V_133 ) ;
V_453 -> V_459 =
F_20 ( V_460 , V_133 ) ;
V_453 -> V_461 =
F_20 ( V_462 , V_133 ) ;
V_453 -> V_463 = V_402 -> V_464 ;
V_453 -> V_465 = V_402 -> V_466 ;
V_453 -> V_467 = V_402 -> V_468 ;
V_453 -> V_469 . V_470 =
F_74 ( F_103 ( V_402 -> V_471 ) ) ;
V_453 -> V_469 . V_472 =
F_74 ( F_102 ( V_402 -> V_471 ) ) ;
V_453 -> V_33 = 0 ;
}
static void F_218 ( struct V_403 * V_4 ,
struct V_473 * V_402 ,
struct V_474 * V_475 )
{
V_475 -> V_476 = F_75 ( V_402 -> V_477 ) ;
V_475 -> V_478 = F_75 ( V_402 -> V_479 ) ;
V_475 -> V_480 = F_75 ( V_402 -> V_481 ) ;
V_475 -> V_482 = F_75 ( V_402 -> V_483 ) ;
V_475 -> V_484 = F_75 ( V_402 -> V_485 ) ;
V_475 -> V_486 = F_75 ( V_402 -> V_487 ) ;
V_475 -> V_488 = F_75 ( V_402 -> V_489 ) ;
}
static void F_219 ( struct V_403 * V_4 ,
struct V_490 * V_402 ,
struct V_474 * V_475 ,
unsigned long * V_133 )
{
V_475 -> V_428 = F_20 ( V_491 , V_133 ) *
V_492 ;
V_475 -> V_493 = 0 ;
V_475 -> V_494 =
V_402 -> V_495 ;
V_475 -> V_496 =
F_20 ( V_497 , V_133 ) ;
V_475 -> V_498 = V_402 -> V_499 ;
V_475 -> V_500 = V_402 -> V_501 ;
V_475 -> V_502 = F_75 ( V_402 -> V_503 ) ;
V_475 -> V_33 = F_75 ( V_504 |
V_505 ) ;
V_475 -> V_506 = 0 ;
V_475 -> V_507 = 0 ;
V_475 -> V_508 = 0 ;
V_475 -> V_509 = 0 ;
V_475 -> V_510 =
F_20 ( V_511 , V_133 ) ;
V_475 -> V_512 =
F_20 ( V_513 , V_133 ) ;
V_475 -> V_514 = V_402 -> V_464 ;
V_475 -> V_515 = V_402 -> V_466 ;
V_475 -> V_516 = V_402 -> V_516 ;
V_475 -> V_517 = F_75 ( V_402 -> V_518 ) ;
V_475 -> V_519 = F_75 ( V_402 -> V_520 ) ;
V_475 -> V_521 . V_470 =
F_74 ( F_103 ( V_402 -> V_471 ) ) ;
V_475 -> V_521 . V_472 =
F_74 ( F_102 ( V_402 -> V_471 ) ) ;
V_475 -> V_522 . V_470 =
F_74 ( F_103 ( V_402 -> V_523 ) ) ;
V_475 -> V_522 . V_472 =
F_74 ( F_102 ( V_402 -> V_523 ) ) ;
V_475 -> V_524 . V_470 =
F_74 ( F_103 ( V_402 -> V_525 ) ) ;
V_475 -> V_524 . V_472 =
F_74 ( F_102 ( V_402 -> V_525 ) ) ;
V_475 -> V_526 = F_20 ( V_527 , V_133 ) ;
if ( F_20 ( V_528 , V_133 ) ) {
V_475 -> V_529 = V_4 -> V_92 ;
V_475 -> V_530 = 1 ;
}
V_475 -> V_394 = V_402 -> V_394 ;
V_475 -> V_531 =
F_20 ( V_532 , V_133 ) ;
V_475 -> V_533 =
F_75 ( V_402 -> V_534 ) ;
V_475 -> V_535 =
F_75 ( V_402 -> V_536 ) ;
}
static void F_220 ( struct V_1 * V_2 ,
struct V_401 * V_423 ,
struct V_424 * V_61 )
{
F_216 ( V_2 , V_423 -> V_404 ,
& V_423 -> V_402 . V_426 . V_537 ,
& V_61 -> V_538 ,
& V_423 -> V_402 . V_426 . V_133 ) ;
F_217 ( V_423 -> V_404 ,
& V_423 -> V_402 . V_426 . V_539 ,
& V_61 -> V_540 ,
& V_423 -> V_402 . V_426 . V_133 ) ;
F_219 ( V_423 -> V_404 ,
& V_423 -> V_402 . V_426 . V_541 ,
& V_61 -> V_427 ,
& V_423 -> V_402 . V_426 . V_133 ) ;
F_218 ( V_423 -> V_404 ,
& V_423 -> V_402 . V_426 . V_542 ,
& V_61 -> V_427 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_401 * V_423 ,
struct V_543 * V_61 )
{
F_216 ( V_2 , V_423 -> V_404 ,
& V_423 -> V_402 . V_544 . V_537 ,
& V_61 -> V_538 ,
& V_423 -> V_402 . V_544 . V_133 ) ;
F_217 ( V_423 -> V_404 ,
& V_423 -> V_402 . V_544 . V_539 ,
& V_61 -> V_540 ,
& V_423 -> V_402 . V_544 . V_133 ) ;
F_4 ( V_17 , L_88 , V_423 -> V_404 -> V_418 [ 0 ] ,
V_61 -> V_540 . V_469 . V_470 , V_61 -> V_540 . V_469 . V_472 ) ;
}
static inline int F_222 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
struct V_545 * V_546 = & V_402 -> V_402 . V_546 ;
T_7 V_547 ;
T_6 cos ;
if ( F_20 ( V_548 , & V_4 -> type ) &&
F_20 ( V_549 , & V_546 -> V_540 . V_133 ) ) {
V_547 = V_546 -> V_540 . V_550 ? 1000000 / V_546 -> V_540 . V_550 : 0 ;
F_223 ( V_2 , V_546 -> V_540 . V_464 ,
V_546 -> V_540 . V_466 ,
! F_20 ( V_551 , & V_546 -> V_540 . V_133 ) ,
V_547 ) ;
}
if ( F_20 ( V_552 , & V_4 -> type ) &&
F_20 ( V_549 , & V_546 -> V_427 . V_133 ) ) {
V_547 = V_546 -> V_427 . V_550 ? 1000000 / V_546 -> V_427 . V_550 : 0 ;
F_223 ( V_2 , V_546 -> V_427 . V_464 ,
V_546 -> V_427 . V_466 ,
! F_20 ( V_551 , & V_546 -> V_427 . V_133 ) ,
V_547 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_421 ; cos ++ ) {
F_4 ( V_17 , L_89 ,
V_4 -> V_418 [ cos ] , cos ) ;
F_4 ( V_17 , L_90 , V_546 -> V_553 [ cos ] ) ;
F_224 ( V_2 , V_546 -> V_553 [ cos ] , V_4 -> V_418 [ cos ] ) ;
}
V_4 -> V_408 ( V_2 , V_4 , V_554 ) ;
F_225 () ;
F_189 () ;
return 0 ;
}
static inline int F_226 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
struct V_424 * V_105 =
(struct V_424 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
int V_556 = V_557 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_220 ( V_2 , V_402 , V_105 ) ;
return F_101 ( V_2 , V_556 , V_4 -> V_418 [ V_419 ] ,
F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_195 ) ;
}
static inline int F_227 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
struct V_424 * V_105 =
(struct V_424 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
int V_556 = V_557 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_220 ( V_2 , V_402 , V_105 ) ;
F_215 ( V_2 , V_402 , V_105 ) ;
return F_101 ( V_2 , V_556 , V_4 -> V_418 [ V_419 ] ,
F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_195 ) ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
struct V_543 * V_105 =
(struct V_543 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
int V_556 = V_558 ;
struct V_559 * V_560 =
& V_402 -> V_402 . V_544 ;
T_6 V_561 = V_560 -> V_561 ;
if ( V_561 >= V_4 -> V_421 ) {
F_12 ( L_91 ,
V_4 -> V_91 , V_561 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_92 ,
V_560 -> V_537 . cos ,
V_560 -> V_537 . V_446 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_221 ( V_2 , V_402 , V_105 ) ;
F_4 ( V_17 , L_93
L_94 ,
V_4 -> V_418 [ V_561 ] ,
V_105 -> V_538 . V_90 ,
V_105 -> V_538 . V_445 , V_105 -> V_538 . cos ) ;
return F_101 ( V_2 , V_556 , V_4 -> V_418 [ V_561 ] ,
F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_195 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
struct V_403 * V_412 ,
struct V_562 * V_402 ,
struct V_563 * V_61 )
{
V_61 -> V_90 = V_412 -> V_91 ;
V_61 -> V_92 = V_412 -> V_92 ;
V_61 -> V_456 = F_75 ( V_402 -> V_564 ) ;
V_61 -> V_510 =
F_20 ( V_565 , & V_402 -> V_566 ) ;
V_61 -> V_567 =
F_20 ( V_568 ,
& V_402 -> V_566 ) ;
V_61 -> V_512 =
F_20 ( V_569 , & V_402 -> V_566 ) ;
V_61 -> V_570 =
F_20 ( V_571 ,
& V_402 -> V_566 ) ;
V_61 -> V_572 =
F_20 ( V_573 , & V_402 -> V_566 ) ;
V_61 -> V_574 =
F_20 ( V_575 , & V_402 -> V_566 ) ;
V_61 -> V_443 =
F_20 ( V_576 , & V_402 -> V_566 ) ;
V_61 -> V_577 =
F_20 ( V_578 , & V_402 -> V_566 ) ;
V_61 -> V_579 =
F_20 ( V_580 , & V_402 -> V_566 ) ;
V_61 -> V_581 =
F_20 ( V_582 ,
& V_402 -> V_566 ) ;
V_61 -> V_583 =
F_20 ( V_584 ,
& V_402 -> V_566 ) ;
V_61 -> V_531 =
F_20 ( V_585 , & V_402 -> V_566 ) ;
V_61 -> V_533 = F_75 ( V_402 -> V_534 ) ;
V_61 -> V_535 = F_75 ( V_402 -> V_536 ) ;
}
static inline int F_230 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
struct V_563 * V_105 =
(struct V_563 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
struct V_562 * V_586 =
& V_402 -> V_402 . V_587 ;
T_6 V_561 = V_586 -> V_561 ;
if ( V_561 >= V_4 -> V_421 ) {
F_12 ( L_91 ,
V_4 -> V_91 , V_561 ) ;
return - V_62 ;
}
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_229 ( V_2 , V_4 , V_586 , V_105 ) ;
return F_101 ( V_2 , V_588 ,
V_4 -> V_418 [ V_561 ] , F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_195 ) ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_562 * V_587 = & V_402 -> V_402 . V_587 ;
memset ( V_587 , 0 , sizeof( * V_587 ) ) ;
F_85 ( V_578 , & V_587 -> V_566 ) ;
return F_230 ( V_2 , V_402 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_562 * V_587 = & V_402 -> V_402 . V_587 ;
memset ( V_587 , 0 , sizeof( * V_587 ) ) ;
F_85 ( V_576 , & V_587 -> V_566 ) ;
F_85 ( V_578 , & V_587 -> V_566 ) ;
return F_230 ( V_2 , V_402 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
return - 1 ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
return F_101 ( V_2 , V_589 ,
V_4 -> V_418 [ V_419 ] , 0 , V_4 -> V_91 ,
V_195 ) ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
T_6 V_590 = V_402 -> V_402 . V_591 . V_561 ;
if ( V_590 >= V_4 -> V_421 ) {
F_12 ( L_91 ,
V_4 -> V_91 , V_590 ) ;
return - V_62 ;
}
return F_101 ( V_2 , V_592 ,
V_4 -> V_418 [ V_590 ] , 0 , 0 , V_593 ) ;
}
static inline int F_236 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
T_6 V_561 = V_402 -> V_402 . V_594 . V_561 ;
if ( V_561 >= V_4 -> V_421 ) {
F_12 ( L_91 ,
V_4 -> V_91 , V_561 ) ;
return - V_62 ;
}
return F_101 ( V_2 , V_595 ,
V_4 -> V_418 [ V_561 ] , 0 , 0 , V_195 ) ;
}
static inline int F_237 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
struct V_403 * V_4 = V_402 -> V_404 ;
return F_101 ( V_2 , V_596 ,
V_4 -> V_418 [ V_419 ] , 0 , 0 ,
V_195 ) ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
switch ( V_402 -> V_106 ) {
case V_554 :
return F_222 ( V_2 , V_402 ) ;
case V_597 :
return F_228 ( V_2 , V_402 ) ;
case V_415 :
return F_231 ( V_2 , V_402 ) ;
case V_414 :
return F_232 ( V_2 , V_402 ) ;
case V_416 :
return F_230 ( V_2 , V_402 ) ;
case V_598 :
return F_233 ( V_2 , V_402 ) ;
case V_599 :
return F_234 ( V_2 , V_402 ) ;
case V_600 :
return F_235 ( V_2 , V_402 ) ;
case V_601 :
return F_236 ( V_2 , V_402 ) ;
case V_602 :
return F_237 ( V_2 , V_402 ) ;
default:
F_12 ( L_52 , V_402 -> V_106 ) ;
return - V_62 ;
}
}
static int F_239 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
switch ( V_402 -> V_106 ) {
case V_603 :
return F_226 ( V_2 , V_402 ) ;
case V_554 :
case V_597 :
case V_415 :
case V_414 :
case V_416 :
case V_598 :
case V_599 :
case V_600 :
case V_601 :
case V_602 :
return F_238 ( V_2 , V_402 ) ;
default:
F_12 ( L_52 , V_402 -> V_106 ) ;
return - V_62 ;
}
}
static int F_240 ( struct V_1 * V_2 ,
struct V_401 * V_402 )
{
switch ( V_402 -> V_106 ) {
case V_603 :
return F_227 ( V_2 , V_402 ) ;
case V_554 :
case V_597 :
case V_415 :
case V_414 :
case V_416 :
case V_598 :
case V_599 :
case V_600 :
case V_601 :
case V_602 :
return F_238 ( V_2 , V_402 ) ;
default:
F_12 ( L_52 , V_402 -> V_106 ) ;
return - V_62 ;
}
}
static int F_241 ( struct V_1 * V_2 ,
struct V_403 * V_4 ,
struct V_401 * V_402 )
{
enum V_604 V_33 = V_4 -> V_33 , V_410 = V_411 ;
enum V_413 V_106 = V_402 -> V_106 ;
struct V_562 * V_586 =
& V_402 -> V_402 . V_587 ;
T_6 V_420 = V_4 -> V_422 ;
if ( F_20 ( V_28 , & V_402 -> V_25 ) ) {
V_4 -> V_406 = 0 ;
V_4 -> V_410 = V_411 ;
}
if ( V_4 -> V_406 )
return - V_37 ;
switch ( V_33 ) {
case V_605 :
if ( V_106 == V_554 )
V_410 = V_606 ;
break;
case V_606 :
if ( V_106 == V_603 ) {
if ( F_20 ( V_444 ,
& V_402 -> V_402 . V_426 . V_133 ) )
V_410 = V_607 ;
else
V_410 = V_608 ;
}
break;
case V_607 :
if ( V_106 == V_415 )
V_410 = V_608 ;
else if ( ( V_106 == V_602 ) ||
( V_106 == V_598 ) )
V_410 = V_607 ;
else if ( V_106 == V_597 ) {
V_410 = V_609 ;
V_420 = 1 ;
}
else if ( V_106 == V_599 )
V_410 = V_610 ;
else if ( V_106 == V_416 ) {
if ( F_20 ( V_578 ,
& V_586 -> V_566 ) &&
! F_20 ( V_576 ,
& V_586 -> V_566 ) )
V_410 = V_608 ;
else
V_410 = V_607 ;
}
break;
case V_609 :
if ( V_106 == V_601 )
V_410 = V_611 ;
else if ( V_106 == V_597 ) {
V_410 = V_609 ;
V_420 = V_4 -> V_422 + 1 ;
}
else if ( ( V_106 == V_602 ) ||
( V_106 == V_598 ) )
V_410 = V_609 ;
else if ( V_106 == V_416 ) {
if ( F_20 ( V_578 ,
& V_586 -> V_566 ) &&
! F_20 ( V_576 ,
& V_586 -> V_566 ) )
V_410 = V_608 ;
else
V_410 = V_609 ;
}
break;
case V_611 :
if ( V_106 == V_600 ) {
V_420 = V_4 -> V_422 - 1 ;
if ( V_420 == 0 )
V_410 = V_607 ;
else
V_410 = V_609 ;
}
break;
case V_608 :
if ( V_106 == V_414 )
V_410 = V_607 ;
else if ( ( V_106 == V_602 ) ||
( V_106 == V_598 ) )
V_410 = V_608 ;
else if ( V_106 == V_599 )
V_410 = V_610 ;
else if ( V_106 == V_416 ) {
if ( F_20 ( V_578 ,
& V_586 -> V_566 ) &&
F_20 ( V_576 ,
& V_586 -> V_566 ) ) {
if ( V_4 -> V_422 == 0 )
V_410 = V_607 ;
else
V_410 = V_609 ;
} else
V_410 = V_608 ;
}
break;
case V_610 :
if ( V_106 == V_601 )
V_410 = V_612 ;
break;
case V_612 :
if ( V_106 == V_600 )
V_410 = V_605 ;
break;
default:
F_12 ( L_95 , V_33 ) ;
}
if ( V_410 != V_411 ) {
F_4 ( V_17 , L_96 ,
V_33 , V_106 , V_410 ) ;
V_4 -> V_410 = V_410 ;
V_4 -> V_420 = V_420 ;
return 0 ;
}
F_4 ( V_17 , L_97 , V_33 , V_106 ) ;
return - V_62 ;
}
void F_242 ( struct V_1 * V_2 ,
struct V_403 * V_412 ,
T_6 V_91 , V_59 * V_418 , T_6 V_613 , T_6 V_92 ,
void * V_105 ,
T_8 V_194 , unsigned long type )
{
memset ( V_412 , 0 , sizeof( * V_412 ) ) ;
F_243 ( V_614 < V_613 ) ;
memcpy ( V_412 -> V_418 , V_418 , sizeof( V_412 -> V_418 [ 0 ] ) * V_613 ) ;
V_412 -> V_421 = V_613 ;
V_412 -> V_91 = V_91 ;
V_412 -> V_92 = V_92 ;
V_412 -> V_105 = V_105 ;
V_412 -> V_194 = V_194 ;
V_412 -> type = type ;
V_412 -> V_410 = V_411 ;
if ( F_111 ( V_2 ) )
V_412 -> V_409 = F_239 ;
else
V_412 -> V_409 = F_240 ;
V_412 -> V_407 = F_241 ;
V_412 -> V_408 = F_212 ;
V_412 -> V_173 = F_211 ;
V_412 -> V_190 = F_210 ;
}
void F_244 ( struct V_1 * V_2 ,
struct V_403 * V_412 ,
V_59 V_96 , T_6 V_79 )
{
V_412 -> V_418 [ V_79 ] = V_96 ;
}
enum V_615 F_245 ( struct V_1 * V_2 ,
struct V_616 * V_4 )
{
if ( V_4 -> V_406 )
return V_617 ;
F_246 () ;
return V_4 -> V_33 ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_616 * V_4 ,
enum V_618 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_406 ) ;
}
static inline int F_248 ( struct V_1 * V_2 ,
struct V_616 * V_4 ,
enum V_618 V_106 )
{
unsigned long V_417 = V_4 -> V_406 ;
if ( ! F_213 ( V_106 , & V_417 ) ) {
F_12 ( L_98
L_82 , V_106 , F_249 ( V_2 ) ,
V_4 -> V_33 , V_417 , V_4 -> V_410 ) ;
return - V_62 ;
}
F_4 ( V_17 ,
L_99 ,
V_106 , F_249 ( V_2 ) , V_4 -> V_410 ) ;
V_4 -> V_33 = V_4 -> V_410 ;
V_4 -> V_410 = V_617 ;
F_214 () ;
F_30 ( V_106 , & V_4 -> V_406 ) ;
F_31 () ;
return 0 ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_616 * V_4 ,
enum V_618 V_106 )
{
int V_22 = F_248 ( V_2 , V_4 , V_106 ) ;
return V_22 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_616 * V_4 ,
struct V_619 * V_402 )
{
enum V_615 V_33 = V_4 -> V_33 , V_410 = V_617 ;
enum V_618 V_106 = V_402 -> V_106 ;
if ( F_20 ( V_28 , & V_402 -> V_25 ) ) {
V_4 -> V_406 = 0 ;
V_4 -> V_410 = V_617 ;
}
if ( V_4 -> V_406 )
return - V_37 ;
switch ( V_33 ) {
case V_620 :
if ( V_106 == V_621 )
V_410 = V_622 ;
break;
case V_622 :
if ( V_106 == V_623 )
V_410 = V_624 ;
else if ( V_106 == V_625 )
V_410 = V_620 ;
break;
case V_624 :
if ( V_106 == V_626 )
V_410 = V_622 ;
else if ( V_106 == V_627 )
V_410 = V_628 ;
break;
case V_628 :
if ( V_106 == V_629 )
V_410 = V_624 ;
break;
default:
F_12 ( L_100 , V_33 ) ;
}
if ( V_410 != V_617 ) {
F_4 ( V_17 , L_101 ,
V_33 , V_106 , V_410 ) ;
V_4 -> V_410 = V_410 ;
return 0 ;
}
F_4 ( V_17 , L_102 ,
V_33 , V_106 ) ;
return - V_62 ;
}
static inline int F_252 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
return V_631 -> V_632 ( V_2 ) ;
}
static inline int F_253 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
int V_22 = V_631 -> V_633 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_252 ( V_2 , V_631 ) ;
}
static inline int F_254 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
int V_22 = V_631 -> V_634 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_253 ( V_2 , V_631 ) ;
}
static inline int F_255 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
int V_22 = V_631 -> V_635 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_253 ( V_2 , V_631 ) ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
V_59 V_636 = V_402 -> V_402 . V_637 . V_638 ;
struct V_616 * V_4 = V_402 -> V_639 ;
const struct V_630 * V_631 = V_4 -> V_631 ;
int V_22 = 0 ;
F_4 ( V_17 , L_103 ,
F_257 ( V_2 ) , V_636 ) ;
V_22 = V_631 -> V_640 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_631 -> V_641 ( V_2 ) ;
if ( V_22 ) {
F_12 ( L_104 ) ;
goto V_642;
}
switch ( V_636 ) {
case V_643 :
V_22 = F_254 ( V_2 , V_631 ) ;
if ( V_22 )
goto V_642;
break;
case V_644 :
V_22 = F_255 ( V_2 , V_631 ) ;
if ( V_22 )
goto V_642;
break;
case V_645 :
V_22 = F_253 ( V_2 , V_631 ) ;
if ( V_22 )
goto V_642;
break;
case V_646 :
V_22 = F_252 ( V_2 , V_631 ) ;
if ( V_22 )
goto V_642;
break;
default:
F_12 ( L_105 , V_636 ) ;
V_22 = - V_62 ;
}
V_642:
V_631 -> V_647 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_408 ( V_2 , V_4 , V_621 ) ;
return V_22 ;
}
static inline void F_258 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
V_631 -> V_648 ( V_2 ) ;
}
static inline void F_259 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
V_631 -> V_649 ( V_2 ) ;
F_258 ( V_2 , V_631 ) ;
}
static inline void F_260 ( struct V_1 * V_2 ,
const struct V_630 * V_631 )
{
F_259 ( V_2 , V_631 ) ;
V_631 -> V_650 ( V_2 ) ;
}
static inline int F_261 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
V_59 V_651 = V_402 -> V_402 . V_652 . V_651 ;
struct V_616 * V_4 = V_402 -> V_639 ;
const struct V_630 * V_631 = V_4 -> V_631 ;
F_4 ( V_17 , L_106 , F_257 ( V_2 ) ,
V_651 ) ;
switch ( V_651 ) {
case V_653 :
F_260 ( V_2 , V_631 ) ;
break;
case V_654 :
F_259 ( V_2 , V_631 ) ;
break;
case V_655 :
F_258 ( V_2 , V_631 ) ;
break;
default:
F_12 ( L_107 ,
V_651 ) ;
break;
}
V_4 -> V_408 ( V_2 , V_4 , V_625 ) ;
return 0 ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
struct V_616 * V_4 = V_402 -> V_639 ;
struct V_656 * V_105 =
(struct V_656 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
struct V_657 * V_658 = & V_402 -> V_402 . V_659 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_660 = F_75 ( V_658 -> V_661 ) ;
V_105 -> V_662 = F_75 ( V_658 -> V_662 ) ;
V_105 -> V_663 = F_263 ( V_2 ) ;
V_105 -> V_664 = V_658 -> V_664 ;
return F_101 ( V_2 , V_665 , 0 ,
F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_593 ) ;
}
static inline int F_264 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
return F_101 ( V_2 , V_666 , 0 , 0 , 0 ,
V_593 ) ;
}
static inline int F_265 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
return F_101 ( V_2 , V_667 , 0 , 0 , 0 ,
V_593 ) ;
}
static inline int F_266 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
struct V_616 * V_4 = V_402 -> V_639 ;
struct V_668 * V_105 =
(struct V_668 * ) V_4 -> V_105 ;
T_8 V_555 = V_4 -> V_194 ;
struct V_669 * V_670 =
& V_402 -> V_402 . V_671 ;
int V_282 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_672 = V_670 -> V_672 ;
V_105 -> V_673 = V_670 -> V_673 ;
V_105 -> V_674 = V_670 -> V_674 ;
for ( V_282 = 0 ; V_282 < F_267 ( V_105 -> V_675 ) ; V_282 ++ )
V_105 -> V_675 [ V_282 ] =
V_670 -> V_675 [ V_282 ] ;
return F_101 ( V_2 , V_676 , 0 ,
F_102 ( V_555 ) ,
F_103 ( V_555 ) , V_593 ) ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
switch ( V_402 -> V_106 ) {
case V_621 :
return F_256 ( V_2 , V_402 ) ;
case V_623 :
return F_262 ( V_2 , V_402 ) ;
case V_626 :
return F_264 ( V_2 , V_402 ) ;
case V_625 :
return F_261 ( V_2 , V_402 ) ;
case V_627 :
return F_265 ( V_2 , V_402 ) ;
case V_629 :
return F_266 ( V_2 , V_402 ) ;
default:
F_12 ( L_52 , V_402 -> V_106 ) ;
return - V_62 ;
}
}
void F_269 ( struct V_1 * V_2 ,
struct V_616 * V_412 ,
void * V_105 , T_8 V_194 ,
struct V_630 * V_677 )
{
memset ( V_412 , 0 , sizeof( * V_412 ) ) ;
F_270 ( & V_412 -> V_678 ) ;
V_412 -> V_105 = V_105 ;
V_412 -> V_194 = V_194 ;
V_412 -> V_409 = F_268 ;
V_412 -> V_407 = F_251 ;
V_412 -> V_408 = F_250 ;
V_412 -> V_173 = F_247 ;
V_412 -> V_631 = V_677 ;
}
int F_271 ( struct V_1 * V_2 ,
struct V_619 * V_402 )
{
struct V_616 * V_4 = V_402 -> V_639 ;
int V_22 ;
enum V_618 V_106 = V_402 -> V_106 ;
unsigned long * V_406 = & V_4 -> V_406 ;
F_272 ( & V_4 -> V_678 ) ;
if ( V_4 -> V_407 ( V_2 , V_4 , V_402 ) ) {
F_273 ( & V_4 -> V_678 ) ;
return - V_62 ;
}
F_33 ( V_106 , V_406 ) ;
if ( F_20 ( V_28 , & V_402 -> V_25 ) ) {
F_248 ( V_2 , V_4 , V_106 ) ;
F_273 ( & V_4 -> V_678 ) ;
} else {
V_22 = V_4 -> V_409 ( V_2 , V_402 ) ;
F_273 ( & V_4 -> V_678 ) ;
if ( V_22 ) {
V_4 -> V_410 = V_617 ;
F_30 ( V_106 , V_406 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_199 , & V_402 -> V_25 ) ) {
V_22 = V_4 -> V_173 ( V_2 , V_4 , V_106 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_106 , V_406 ) ;
}
