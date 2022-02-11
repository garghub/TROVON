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
static inline void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_14 ) ;
F_13 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_14 ) ;
}
static inline int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_25 )
{
struct V_18 * V_19 , V_26 ;
int V_27 = 0 , V_22 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
F_8 ( & V_4 -> V_14 ) ;
if ( ! F_14 ( & V_4 -> V_13 ) ) {
if ( F_19 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_4 ) ;
F_13 ( V_2 , V_4 ) ;
} else {
F_10 ( & V_4 -> V_14 ) ;
return 1 ;
}
}
while ( ! F_14 ( & V_4 -> V_12 ) ) {
V_19 = F_15 ( & V_4 -> V_12 , struct V_18 ,
V_24 ) ;
F_20 ( ! V_19 -> V_29 ) ;
if ( V_27 + V_19 -> V_29 <= V_4 -> V_15 ) {
V_27 += V_19 -> V_29 ;
F_12 ( & V_26 . V_24 , & V_4 -> V_13 ) ;
F_21 () ;
F_22 ( & V_19 -> V_24 , & V_4 -> V_13 ) ;
F_16 ( & V_26 . V_24 ) ;
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
F_13 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_14 ) ;
return V_22 ;
}
static inline bool F_24 ( struct V_3 * V_4 )
{
bool V_30 = F_14 ( & V_4 -> V_12 ) ;
F_21 () ;
return V_30 && F_14 ( & V_4 -> V_13 ) ;
}
static inline struct V_18 * F_25 (
struct V_1 * V_2 )
{
F_4 ( V_17 , L_5 ) ;
return F_26 ( sizeof( struct V_18 ) , V_31 ) ;
}
static bool F_27 ( struct V_32 * V_4 )
{
return ! ! F_19 ( V_4 -> V_33 , V_4 -> V_34 ) ;
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
F_4 ( V_17 , L_6 , V_33 ) ;
F_36 () ;
while ( V_20 -- ) {
if ( ! F_19 ( V_33 , V_34 ) ) {
#ifdef F_37
F_4 ( V_17 , L_7 , 5000 - V_20 ) ;
#endif
return 0 ;
}
F_38 ( 1000 , 2000 ) ;
if ( V_2 -> V_35 )
return - V_36 ;
}
F_39 ( L_8 , V_33 ) ;
#ifdef F_37
F_40 () ;
#endif
return - V_37 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_32 * V_38 )
{
return F_34 ( V_2 , V_38 -> V_33 , V_38 -> V_34 ) ;
}
static bool F_42 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_20 ( ! V_42 ) ;
return V_42 -> V_44 ( V_42 , V_40 ) ;
}
static bool F_43 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
F_20 ( ! V_42 ) ;
return V_42 -> V_11 ( V_42 , 1 ) ;
}
static bool F_44 ( struct V_39 * V_4 , int * V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_20 ( ! V_45 ) ;
return V_45 -> V_44 ( V_45 , V_40 ) ;
}
static bool F_45 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
F_20 ( ! V_45 ) ;
return V_45 -> V_11 ( V_45 , 1 ) ;
}
static bool F_46 ( struct V_39 * V_4 )
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
static bool F_47 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_48 ( V_42 , V_40 ) ;
}
static bool F_48 ( struct V_39 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
return V_42 -> V_47 ( V_42 , 1 ) ;
}
static bool F_49 ( struct V_39 * V_4 , int V_40 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_48 ( V_45 , V_40 ) ;
}
static bool F_50 ( struct V_39 * V_4 )
{
struct V_41 * V_45 = V_4 -> V_46 ;
return V_45 -> V_47 ( V_45 , 1 ) ;
}
static bool F_51 ( struct V_39 * V_4 )
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
static int F_52 ( struct V_1 * V_2 , struct V_39 * V_4 ,
int V_49 , T_6 * V_50 , T_6 V_51 , T_6 V_52 )
{
struct V_53 * V_54 ;
T_6 * V_55 = V_50 ;
int V_56 = 0 ;
F_9 (pos, &o->head, link) {
if ( V_56 < V_49 ) {
memcpy ( V_55 , & V_54 -> V_57 , V_52 ) ;
V_56 ++ ;
F_4 ( V_17 , L_9 ,
V_56 , V_55 ) ;
V_55 += V_51 + V_52 ;
}
}
return V_56 * V_58 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_10 , V_60 -> V_61 . V_61 ) ;
if ( ! F_54 ( V_60 -> V_61 . V_61 ) )
return - V_62 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_60 -> V_61 . V_61 , V_54 -> V_57 . V_61 . V_61 , V_58 ) &&
( V_60 -> V_61 . V_63 == V_54 -> V_57 . V_61 . V_63 ) )
return - V_64 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_11 , V_60 -> V_65 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( V_60 -> V_65 . V_65 == V_54 -> V_57 . V_65 . V_65 )
return - V_64 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_12 ,
V_60 -> V_66 . V_61 , V_60 -> V_66 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( ( V_60 -> V_66 . V_65 == V_54 -> V_57 . V_66 . V_65 ) &&
( ! memcmp ( V_60 -> V_66 . V_61 , V_54 -> V_57 . V_66 . V_61 ,
V_58 ) ) &&
( V_60 -> V_66 . V_63 ==
V_54 -> V_57 . V_66 . V_63 ) )
return - V_64 ;
return 0 ;
}
static struct V_53 *
F_57 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_13 , V_60 -> V_61 . V_61 ) ;
F_9 (pos, &o->head, link)
if ( ( ! memcmp ( V_60 -> V_61 . V_61 , V_54 -> V_57 . V_61 . V_61 , V_58 ) ) &&
( V_60 -> V_61 . V_63 == V_54 -> V_57 . V_61 . V_63 ) )
return V_54 ;
return NULL ;
}
static struct V_53 *
F_58 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_14 , V_60 -> V_65 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( V_60 -> V_65 . V_65 == V_54 -> V_57 . V_65 . V_65 )
return V_54 ;
return NULL ;
}
static struct V_53 *
F_59 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
F_4 ( V_17 , L_15 ,
V_60 -> V_66 . V_61 , V_60 -> V_66 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( ( V_60 -> V_66 . V_65 == V_54 -> V_57 . V_66 . V_65 ) &&
( ! memcmp ( V_60 -> V_66 . V_61 , V_54 -> V_57 . V_66 . V_61 ,
V_58 ) ) &&
( V_60 -> V_66 . V_63 ==
V_54 -> V_57 . V_66 . V_63 ) )
return V_54 ;
return NULL ;
}
static bool F_60 ( struct V_1 * V_2 ,
struct V_39 * V_67 ,
struct V_39 * V_68 ,
union V_59 * V_60 )
{
struct V_53 * V_54 ;
int V_22 ;
V_54 = V_67 -> V_69 ( V_2 , V_67 , V_60 ) ;
V_22 = V_68 -> V_70 ( V_2 , V_68 , V_60 ) ;
if ( V_22 || ! V_54 )
return false ;
return true ;
}
static bool F_61 (
struct V_1 * V_2 ,
struct V_39 * V_67 ,
struct V_39 * V_68 ,
union V_59 * V_60 )
{
return false ;
}
static inline T_6 F_62 ( struct V_39 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_71 = 0 ;
if ( ( V_38 -> V_72 == V_73 ) ||
( V_38 -> V_72 == V_74 ) )
V_71 |= V_75 ;
if ( ( V_38 -> V_72 == V_76 ) ||
( V_38 -> V_72 == V_74 ) )
V_71 |= V_77 ;
return V_71 ;
}
void F_63 ( struct V_1 * V_2 ,
bool V_78 , unsigned char * V_79 , int V_80 )
{
T_7 V_81 [ 2 ] ;
T_7 V_82 = F_64 ( V_2 ) ? V_83 :
V_84 ;
if ( ! F_65 ( V_2 ) && ! F_66 ( V_2 ) )
return;
if ( V_80 > V_85 )
return;
F_4 ( V_17 , L_16 ,
( V_78 ? L_17 : L_18 ) , V_80 ) ;
if ( V_78 ) {
V_82 += 8 * V_80 ;
V_81 [ 0 ] = ( ( V_79 [ 2 ] << 24 ) | ( V_79 [ 3 ] << 16 ) |
( V_79 [ 4 ] << 8 ) | V_79 [ 5 ] ) ;
V_81 [ 1 ] = ( ( V_79 [ 0 ] << 8 ) | V_79 [ 1 ] ) ;
F_67 ( V_2 , V_82 , V_81 , 2 ) ;
}
F_68 ( V_2 , ( F_64 ( V_2 ) ? V_86 :
V_87 ) + 4 * V_80 , V_78 ) ;
}
static inline void F_69 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_78 , int V_88 ,
struct V_89 * V_90 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_90 -> V_91 = V_38 -> V_92 ;
V_90 -> V_93 = V_38 -> V_93 ;
V_90 -> V_94 |=
F_62 ( V_4 ) ;
if ( V_78 )
V_90 -> V_94 |= V_95 ;
V_90 -> V_94 |=
( V_88 << V_96 ) ;
}
static inline void F_70 ( T_7 V_97 , int type ,
struct V_98 * V_90 , int V_99 )
{
V_90 -> V_100 = F_71 ( ( V_97 & V_101 ) |
( type << V_102 ) ) ;
V_90 -> V_99 = ( T_6 ) V_99 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_103 ,
int V_104 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_105 * V_60 =
(struct V_105 * ) ( V_38 -> V_106 ) ;
int V_99 = V_103 + 1 , V_107 = V_19 -> V_108 . V_66 . V_107 ;
union V_109 * V_110 = & V_60 -> V_111 [ V_103 ] ;
bool V_78 = ( V_107 == V_112 ) ? true : false ;
unsigned long * V_113 = & V_19 -> V_108 . V_66 . V_113 ;
T_6 * V_61 = V_19 -> V_108 . V_66 . V_57 . V_61 . V_61 ;
if ( V_107 != V_114 ) {
if ( F_19 ( V_115 , V_113 ) )
F_63 ( V_2 , V_78 , V_61 ,
V_116 ) ;
else if ( F_19 ( V_117 , V_113 ) )
F_63 ( V_2 , V_78 , V_61 ,
V_118 ) ;
}
if ( V_103 == 0 )
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_69 ( V_2 , V_4 , V_78 , V_119 ,
& V_110 -> V_61 . V_120 ) ;
F_4 ( V_17 , L_19 ,
( V_78 ? L_20 : L_21 ) , V_61 , V_38 -> V_92 ) ;
F_73 ( & V_110 -> V_61 . V_121 ,
& V_110 -> V_61 . V_122 ,
& V_110 -> V_61 . V_123 , V_61 ) ;
V_110 -> V_61 . V_124 =
F_74 ( V_19 -> V_108 . V_66 . V_57 . V_61 . V_63 ) ;
if ( V_107 == V_114 ) {
V_110 ++ ;
V_99 ++ ;
F_69 ( V_2 ,
V_19 -> V_108 . V_66 . V_125 ,
true , V_119 ,
& V_110 -> V_61 . V_120 ) ;
F_73 ( & V_110 -> V_61 . V_121 ,
& V_110 -> V_61 . V_122 ,
& V_110 -> V_61 . V_123 , V_61 ) ;
V_110 -> V_61 . V_124 =
F_74 ( V_19 -> V_108 . V_66 .
V_57 . V_61 . V_63 ) ;
}
F_70 ( V_38 -> V_97 , V_38 -> V_33 , & V_60 -> V_120 ,
V_99 ) ;
}
static inline void F_75 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_104 ,
struct V_126 * V_90 )
{
struct V_32 * V_127 = & V_4 -> V_38 ;
V_90 -> V_128 = 1 ;
V_90 -> V_40 = ( T_6 ) V_104 ;
V_90 -> V_91 = F_74 ( 0xff ) ;
V_90 -> V_100 = F_71 ( ( V_127 -> V_97 & V_101 ) |
( type << V_102 ) ) ;
}
static inline void F_76 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_78 , int V_88 , T_6 * V_61 ,
T_8 V_129 , struct V_130 * V_131 )
{
struct V_32 * V_127 = & V_4 -> V_38 ;
T_7 V_132 = ( 1 << V_127 -> V_92 ) ;
V_131 -> V_133 = F_71 ( V_132 ) ;
V_131 -> V_134 = V_127 -> V_93 ;
V_131 -> V_129 = F_74 ( V_129 ) ;
if ( V_78 ) {
F_77 ( V_131 -> V_135 , V_136 ,
V_137 ) ;
F_77 ( V_131 -> V_135 ,
V_138 , V_88 ) ;
F_73 ( & V_131 -> V_139 ,
& V_131 -> V_140 ,
& V_131 -> V_141 , V_61 ) ;
} else
F_77 ( V_131 -> V_135 , V_136 ,
V_142 ) ;
}
static inline void F_78 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_104 , bool V_78 ,
T_6 * V_61 , T_8 V_129 , int V_88 , struct V_143 * V_144 )
{
struct V_130 * V_131 = & V_144 -> V_145 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_75 ( V_2 , V_4 , type , V_104 ,
& V_144 -> V_90 ) ;
F_76 ( V_2 , V_4 , V_78 , V_88 , V_61 , V_129 ,
V_131 ) ;
F_4 ( V_17 , L_22 ,
( V_78 ? L_23 : L_24 ) ,
V_61 , V_38 -> V_92 , V_104 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_103 ,
int V_104 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_143 * V_144 =
(struct V_143 * ) ( V_38 -> V_106 ) ;
bool V_78 = ( V_19 -> V_108 . V_66 . V_107 == V_112 ) ?
true : false ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
F_78 ( V_2 , V_4 , V_38 -> V_33 ,
V_104 , V_78 ,
V_19 -> V_108 . V_66 . V_57 . V_61 . V_61 , 0 ,
V_146 , V_144 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_103 ,
int V_104 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_105 * V_60 =
(struct V_105 * ) ( V_38 -> V_106 ) ;
int V_99 = V_103 + 1 ;
union V_109 * V_110 = & V_60 -> V_111 [ V_103 ] ;
enum V_147 V_107 = V_19 -> V_108 . V_66 . V_107 ;
bool V_78 = ( V_107 == V_112 ) ? true : false ;
T_8 V_65 = V_19 -> V_108 . V_66 . V_57 . V_65 . V_65 ;
if ( V_103 == 0 )
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_69 ( V_2 , V_4 , V_78 , V_148 ,
& V_110 -> V_65 . V_120 ) ;
F_4 ( V_17 , L_25 , ( V_78 ? L_20 : L_21 ) ,
V_65 ) ;
V_110 -> V_65 . V_65 = F_74 ( V_65 ) ;
if ( V_107 == V_114 ) {
V_110 ++ ;
V_99 ++ ;
F_69 ( V_2 ,
V_19 -> V_108 . V_66 . V_125 ,
true , V_148 ,
& V_110 -> V_65 . V_120 ) ;
V_110 -> V_65 . V_65 = F_74 ( V_65 ) ;
}
F_70 ( V_38 -> V_97 , V_38 -> V_33 , & V_60 -> V_120 ,
V_99 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_103 , int V_104 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_105 * V_60 =
(struct V_105 * ) ( V_38 -> V_106 ) ;
int V_99 = V_103 + 1 ;
union V_109 * V_110 = & V_60 -> V_111 [ V_103 ] ;
enum V_147 V_107 = V_19 -> V_108 . V_66 . V_107 ;
bool V_78 = ( V_107 == V_112 ) ? true : false ;
T_8 V_65 = V_19 -> V_108 . V_66 . V_57 . V_66 . V_65 ;
T_6 * V_61 = V_19 -> V_108 . V_66 . V_57 . V_66 . V_61 ;
if ( V_103 == 0 )
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_69 ( V_2 , V_4 , V_78 , V_149 ,
& V_110 -> V_150 . V_120 ) ;
V_110 -> V_150 . V_65 = F_74 ( V_65 ) ;
F_73 ( & V_110 -> V_150 . V_121 ,
& V_110 -> V_150 . V_122 ,
& V_110 -> V_150 . V_123 , V_61 ) ;
V_110 -> V_150 . V_124 =
F_74 ( V_19 -> V_108 . V_66 . V_57 . V_66 . V_63 ) ;
if ( V_107 == V_114 ) {
V_110 ++ ;
V_99 ++ ;
F_69 ( V_2 ,
V_19 -> V_108 . V_66 . V_125 ,
true , V_149 ,
& V_110 -> V_150 . V_120 ) ;
V_110 -> V_150 . V_65 = F_74 ( V_65 ) ;
F_73 ( & V_110 -> V_150 . V_121 ,
& V_110 -> V_150 . V_122 ,
& V_110 -> V_150 . V_123 , V_61 ) ;
V_110 -> V_150 . V_124 =
F_74 ( V_19 -> V_108 . V_66 . V_57 .
V_66 . V_63 ) ;
}
F_70 ( V_38 -> V_97 , V_38 -> V_33 , & V_60 -> V_120 ,
V_99 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_103 , int V_104 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_143 * V_144 =
(struct V_143 * ) ( V_38 -> V_106 ) ;
bool V_78 = ( V_19 -> V_108 . V_66 . V_107 == V_112 ) ?
true : false ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
F_78 ( V_2 , V_4 , V_151 ,
V_104 , V_78 ,
V_19 -> V_108 . V_66 . V_57 . V_66 . V_61 ,
V_19 -> V_108 . V_66 . V_57 . V_66 . V_65 ,
V_152 , V_144 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
struct V_53 * * V_155 )
{
struct V_53 * V_54 ;
struct V_39 * V_4 = V_154 -> V_156 ;
if ( F_14 ( & V_4 -> V_157 ) ) {
* V_155 = NULL ;
return 0 ;
}
if ( * V_155 == NULL )
* V_155 = F_15 ( & V_4 -> V_157 ,
struct V_53 ,
V_24 ) ;
else
* V_155 = F_84 ( * V_155 , V_24 ) ;
V_54 = * V_155 ;
if ( F_85 ( & V_54 -> V_24 , & V_4 -> V_157 ) )
* V_155 = NULL ;
memcpy ( & V_154 -> V_158 . V_57 , & V_54 -> V_57 , sizeof( V_54 -> V_57 ) ) ;
V_154 -> V_158 . V_107 = V_112 ;
V_154 -> V_158 . V_113 = V_54 -> V_113 ;
F_86 ( V_159 , & V_154 -> V_25 ) ;
return F_87 ( V_2 , V_154 ) ;
}
static struct V_18 * F_88 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_54 ;
struct V_160 * V_60 = & V_19 -> V_108 . V_66 . V_57 . V_61 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_54 -> V_108 . V_66 . V_57 . V_61 , V_60 ,
sizeof( * V_60 ) ) &&
( V_54 -> V_108 . V_66 . V_107 == V_19 -> V_108 . V_66 . V_107 ) )
return V_54 ;
return NULL ;
}
static struct V_18 * F_89 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_54 ;
struct V_161 * V_60 = & V_19 -> V_108 . V_66 . V_57 . V_65 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_54 -> V_108 . V_66 . V_57 . V_65 , V_60 ,
sizeof( * V_60 ) ) &&
( V_54 -> V_108 . V_66 . V_107 == V_19 -> V_108 . V_66 . V_107 ) )
return V_54 ;
return NULL ;
}
static struct V_18 * F_90 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_54 ;
struct V_162 * V_60 =
& V_19 -> V_108 . V_66 . V_57 . V_66 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_54 -> V_108 . V_66 . V_57 . V_66 , V_60 ,
sizeof( * V_60 ) ) &&
( V_54 -> V_108 . V_66 . V_107 == V_19 -> V_108 . V_66 . V_107 ) )
return V_54 ;
return NULL ;
}
static inline int F_91 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_163 -> V_66 ;
struct V_3 * V_164 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_70 ( V_2 , V_4 , & V_19 -> V_108 . V_66 . V_57 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_26 ) ;
return V_22 ;
}
if ( V_164 -> V_11 ( V_164 , V_19 ) ) {
F_4 ( V_17 , L_27 ) ;
return - V_64 ;
}
if ( ! ( F_19 ( V_165 ,
& V_19 -> V_108 . V_66 . V_113 ) ||
V_4 -> V_166 ( V_4 ) ) )
return - V_62 ;
return 0 ;
}
static inline int F_92 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_163 -> V_66 ;
struct V_53 * V_54 ;
struct V_3 * V_164 = & V_4 -> V_12 ;
struct V_18 V_167 ;
V_54 = V_4 -> V_69 ( V_2 , V_4 , & V_19 -> V_108 . V_66 . V_57 ) ;
if ( ! V_54 ) {
F_4 ( V_17 , L_28 ) ;
return - V_64 ;
}
memcpy ( & V_167 , V_19 , sizeof( V_167 ) ) ;
V_167 . V_108 . V_66 . V_107 = V_114 ;
if ( V_164 -> V_11 ( V_164 , & V_167 ) ) {
F_39 ( L_29 ) ;
return - V_62 ;
}
if ( V_164 -> V_11 ( V_164 , V_19 ) ) {
F_4 ( V_17 , L_30 ) ;
return - V_64 ;
}
if ( ! ( F_19 ( V_165 ,
& V_19 -> V_108 . V_66 . V_113 ) ||
V_4 -> V_168 ( V_4 ) ) ) {
F_39 ( L_31 ) ;
return - V_62 ;
}
return 0 ;
}
static inline int F_93 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
struct V_39 * V_67 = & V_163 -> V_66 ;
struct V_39 * V_169 = V_19 -> V_108 . V_66 . V_125 ;
struct V_18 V_167 ;
struct V_3 * V_170 = & V_67 -> V_12 ;
struct V_3 * V_171 = & V_169 -> V_12 ;
if ( ! V_67 -> V_172 ( V_2 , V_67 , V_169 ,
& V_19 -> V_108 . V_66 . V_57 ) ) {
F_4 ( V_17 , L_32 ) ;
return - V_62 ;
}
memcpy ( & V_167 , V_19 , sizeof( V_167 ) ) ;
V_167 . V_108 . V_66 . V_107 = V_173 ;
if ( V_170 -> V_11 ( V_170 , & V_167 ) ) {
F_39 ( L_33 ) ;
return - V_62 ;
}
if ( V_170 -> V_11 ( V_170 , V_19 ) ) {
F_4 ( V_17 , L_29 ) ;
return - V_64 ;
}
V_167 . V_108 . V_66 . V_107 = V_112 ;
if ( V_171 -> V_11 ( V_171 , & V_167 ) ) {
F_39 ( L_34 ) ;
return - V_62 ;
}
if ( ! ( F_19 ( V_174 ,
& V_19 -> V_108 . V_66 . V_113 ) ||
V_169 -> V_166 ( V_169 ) ) )
return - V_62 ;
if ( ! ( F_19 ( V_165 ,
& V_19 -> V_108 . V_66 . V_113 ) ||
V_67 -> V_168 ( V_67 ) ) ) {
V_169 -> V_168 ( V_169 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_108 . V_66 . V_107 ) {
case V_112 :
return F_91 ( V_2 , V_163 , V_19 ) ;
case V_173 :
return F_92 ( V_2 , V_163 , V_19 ) ;
case V_114 :
return F_93 ( V_2 , V_163 , V_19 ) ;
default:
return - V_62 ;
}
}
static int F_95 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_19 ( V_165 ,
& V_19 -> V_108 . V_66 . V_113 ) )
return 0 ;
switch ( V_19 -> V_108 . V_66 . V_107 ) {
case V_112 :
case V_114 :
V_22 = V_163 -> V_66 . V_168 ( & V_163 -> V_66 ) ;
break;
case V_173 :
V_22 = V_163 -> V_66 . V_166 ( & V_163 -> V_66 ) ;
break;
default:
return - V_62 ;
}
if ( V_22 != true )
return - V_62 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_164 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_175 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_24 ( V_164 ) )
F_38 ( 1000 , 2000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_176 * V_177 ,
unsigned long * V_25 )
{
struct V_32 * V_127 = & V_4 -> V_38 ;
int V_22 ;
F_17 ( V_2 , & V_4 -> V_12 ) ;
V_127 -> V_178 ( V_127 ) ;
if ( V_177 -> V_179 . error )
return - V_62 ;
if ( F_19 ( V_180 , V_25 ) ) {
V_22 = F_18 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_18 * V_19 )
{
struct V_18 V_181 , * V_54 ;
struct V_39 * V_4 = & V_163 -> V_66 ;
struct V_3 * V_164 = & V_4 -> V_12 ;
memcpy ( & V_181 , V_19 , sizeof( V_181 ) ) ;
switch ( V_19 -> V_108 . V_66 . V_107 ) {
case V_112 :
V_181 . V_108 . V_66 . V_107 = V_173 ;
break;
case V_173 :
V_181 . V_108 . V_66 . V_107 = V_112 ;
break;
default:
return 0 ;
}
V_54 = V_164 -> V_11 ( V_164 , & V_181 ) ;
if ( V_54 ) {
if ( ! F_19 ( V_165 ,
& V_54 -> V_108 . V_66 . V_113 ) ) {
if ( ( V_181 . V_108 . V_66 . V_107 ==
V_112 ) && ! V_4 -> V_168 ( V_4 ) ) {
F_39 ( L_35 ) ;
return - V_62 ;
} else if ( ! V_4 -> V_166 ( V_4 ) ) {
F_39 ( L_36 ) ;
return - V_62 ;
}
}
F_4 ( V_17 , L_37 ,
( V_19 -> V_108 . V_66 . V_107 == V_112 ) ?
L_17 : L_38 ) ;
F_16 ( & V_54 -> V_24 ) ;
F_5 ( V_2 , V_54 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_99 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_53 * * V_182 )
{
enum V_147 V_107 = V_19 -> V_108 . V_66 . V_107 ;
struct V_53 * V_183 ;
if ( ! V_21 &&
( ( V_107 == V_112 ) || ( V_107 == V_114 ) ) ) {
V_183 = F_26 ( sizeof( * V_183 ) , V_31 ) ;
if ( ! V_183 )
return - V_184 ;
if ( ! V_4 -> V_185 ( V_4 , & V_183 -> V_104 ) ) {
F_20 ( 1 ) ;
F_6 ( V_183 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_39 , V_183 -> V_104 ) ;
memcpy ( & V_183 -> V_57 , & V_19 -> V_108 . V_66 . V_57 ,
sizeof( V_183 -> V_57 ) ) ;
V_183 -> V_113 =
V_19 -> V_108 . V_66 . V_113 ;
} else
V_183 = V_4 -> V_69 ( V_2 , V_4 , & V_19 -> V_108 . V_66 . V_57 ) ;
* V_182 = V_183 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
union V_6 * V_163 ,
struct V_186 * V_187 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_163 -> V_66 , * V_188 ;
struct V_32 * V_127 = & V_4 -> V_38 ;
int V_22 , V_189 = 0 ;
bool V_21 = F_19 ( V_159 , V_25 ) ;
bool V_190 = F_19 ( V_28 , V_25 ) ;
struct V_53 * V_183 ;
enum V_147 V_107 ;
if ( ! V_190 ) {
F_20 ( V_127 -> V_191 ( V_127 ) ) ;
V_127 -> V_192 ( V_127 ) ;
F_9 (elem, exe_chunk, link) {
V_107 = V_19 -> V_108 . V_66 . V_107 ;
if ( V_107 == V_114 )
V_188 = V_19 -> V_108 . V_66 . V_125 ;
else
V_188 = V_4 ;
V_22 = F_99 ( V_2 , V_188 ,
V_19 , V_21 ,
& V_183 ) ;
if ( V_22 )
goto V_193;
F_20 ( ! V_183 ) ;
if ( ! V_21 &&
( ( V_107 == V_112 ) ||
( V_107 == V_114 ) ) )
F_101 ( & V_183 -> V_24 , & V_188 -> V_157 ) ;
V_4 -> V_194 ( V_2 , V_4 , V_19 , V_189 ,
V_183 -> V_104 ) ;
if ( V_107 == V_114 )
V_189 += 2 ;
else
V_189 ++ ;
}
V_22 = F_102 ( V_2 , V_4 -> V_195 , V_127 -> V_97 ,
F_103 ( V_127 -> V_196 ) ,
F_104 ( V_127 -> V_196 ) ,
V_197 ) ;
if ( V_22 )
goto V_193;
}
F_9 (elem, exe_chunk, link) {
V_107 = V_19 -> V_108 . V_66 . V_107 ;
if ( ( V_107 == V_173 ) ||
( V_107 == V_114 ) ) {
V_183 = V_4 -> V_69 ( V_2 , V_4 ,
& V_19 -> V_108 . V_66 . V_57 ) ;
F_20 ( ! V_183 ) ;
V_4 -> V_198 ( V_4 , V_183 -> V_104 ) ;
F_16 ( & V_183 -> V_24 ) ;
F_6 ( V_183 ) ;
}
}
if ( ! V_190 )
return 1 ;
else
return 0 ;
V_193:
V_127 -> V_178 ( V_127 ) ;
F_9 (elem, exe_chunk, link) {
V_107 = V_19 -> V_108 . V_66 . V_107 ;
if ( V_107 == V_114 )
V_188 = V_19 -> V_108 . V_66 . V_125 ;
else
V_188 = V_4 ;
if ( ! V_21 &&
( ( V_107 == V_112 ) ||
( V_107 == V_114 ) ) ) {
V_183 = V_4 -> V_69 ( V_2 , V_188 ,
& V_19 -> V_108 . V_66 . V_57 ) ;
if ( V_183 ) {
F_16 ( & V_183 -> V_24 ) ;
F_6 ( V_183 ) ;
}
}
}
return V_22 ;
}
static inline int F_105 (
struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_154 -> V_156 ;
bool V_21 = F_19 ( V_159 , & V_154 -> V_25 ) ;
V_19 = F_25 ( V_2 ) ;
if ( ! V_19 )
return - V_184 ;
switch ( V_154 -> V_158 . V_107 ) {
case V_114 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_108 . V_66 , & V_154 -> V_158 , sizeof( V_154 -> V_158 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_87 (
struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_154 -> V_156 ;
unsigned long * V_25 = & V_154 -> V_25 ;
bool V_199 = F_19 ( V_180 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_199 ) {
V_22 = F_105 ( V_2 , V_154 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_19 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_40 ) ;
V_38 -> V_178 ( V_38 ) ;
}
if ( V_199 || F_19 ( V_200 , V_25 ) ||
F_19 ( V_201 , V_25 ) ) {
V_22 = F_18 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_19 ( V_201 , & V_154 -> V_25 ) ) {
int V_202 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_202 -- ) {
V_22 = V_38 -> V_175 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_18 ( V_2 , & V_4 -> V_12 ,
V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
return V_22 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_113 ,
unsigned long * V_25 )
{
struct V_53 * V_54 = NULL ;
int V_22 = 0 ;
struct V_153 V_154 ;
struct V_3 * V_164 = & V_4 -> V_12 ;
struct V_18 * V_203 , * V_204 ;
F_8 ( & V_164 -> V_14 ) ;
F_107 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_203 -> V_108 . V_66 . V_113 ==
* V_113 ) {
V_22 = V_164 -> remove ( V_2 , V_164 -> V_7 , V_203 ) ;
if ( V_22 ) {
F_39 ( L_41 ) ;
F_10 ( & V_164 -> V_14 ) ;
return V_22 ;
}
F_16 ( & V_203 -> V_24 ) ;
F_5 ( V_2 , V_203 ) ;
}
}
F_10 ( & V_164 -> V_14 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = V_4 ;
V_154 . V_25 = * V_25 ;
V_154 . V_158 . V_107 = V_173 ;
F_108 ( V_201 , & V_154 . V_25 ) ;
F_108 ( V_200 , & V_154 . V_25 ) ;
F_108 ( V_180 , & V_154 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_54 -> V_113 == * V_113 ) {
V_154 . V_158 . V_113 = V_54 -> V_113 ;
memcpy ( & V_154 . V_158 . V_57 , & V_54 -> V_57 , sizeof( V_54 -> V_57 ) ) ;
V_22 = F_87 ( V_2 , & V_154 ) ;
if ( V_22 < 0 ) {
F_39 ( L_42 ) ;
return V_22 ;
}
}
}
V_154 . V_25 = * V_25 ;
F_86 ( V_180 , & V_154 . V_25 ) ;
return F_87 ( V_2 , & V_154 ) ;
}
static inline void F_109 ( struct V_32 * V_38 , T_6 V_92 ,
T_7 V_97 , T_6 V_93 , void * V_106 , T_9 V_196 , int V_33 ,
unsigned long * V_34 , T_10 type )
{
V_38 -> V_93 = V_93 ;
V_38 -> V_97 = V_97 ;
V_38 -> V_92 = V_92 ;
V_38 -> V_106 = V_106 ;
V_38 -> V_196 = V_196 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_72 = type ;
V_38 -> V_191 = F_27 ;
V_38 -> V_178 = F_28 ;
V_38 -> V_192 = F_32 ;
V_38 -> V_175 = F_41 ;
}
static inline void F_110 ( struct V_39 * V_4 ,
T_6 V_92 , T_7 V_97 , T_6 V_93 , void * V_106 , T_9 V_196 ,
int V_33 , unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_157 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_205 = F_106 ;
V_4 -> V_21 = F_83 ;
V_4 -> V_206 = F_97 ;
V_4 -> V_207 = F_96 ;
F_109 ( & V_4 -> V_38 , V_92 , V_97 , V_93 , V_106 , V_196 ,
V_33 , V_34 , type ) ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_39 * V_208 ,
T_6 V_92 , T_7 V_97 , T_6 V_93 , void * V_106 ,
T_9 V_196 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 )
{
union V_6 * V_209 = (union V_6 * ) V_208 ;
F_110 ( V_208 , V_92 , V_97 , V_93 , V_106 ,
V_196 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_208 -> V_166 = F_43 ;
V_208 -> V_168 = F_48 ;
V_208 -> V_185 = F_42 ;
V_208 -> V_198 = F_47 ;
if ( F_112 ( V_2 ) ) {
V_208 -> V_194 = F_79 ;
V_208 -> V_69 = F_57 ;
V_208 -> V_70 = F_53 ;
V_208 -> V_172 = F_61 ;
V_208 -> V_195 = V_210 ;
F_1 ( V_2 ,
& V_208 -> V_12 , 1 , V_209 ,
F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_88 ) ;
} else {
V_208 -> V_194 = F_72 ;
V_208 -> V_69 = F_57 ;
V_208 -> V_70 = F_53 ;
V_208 -> V_172 = F_60 ;
V_208 -> V_195 =
V_211 ;
V_208 -> V_212 = F_52 ;
F_1 ( V_2 ,
& V_208 -> V_12 , V_213 ,
V_209 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_88 ) ;
}
}
void F_113 ( struct V_1 * V_2 ,
struct V_39 * V_214 ,
T_6 V_92 , T_7 V_97 , T_6 V_93 , void * V_106 ,
T_9 V_196 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_46 )
{
union V_6 * V_209 = (union V_6 * ) V_214 ;
F_110 ( V_214 , V_92 , V_97 , V_93 , V_106 ,
V_196 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_214 -> V_166 = F_45 ;
V_214 -> V_168 = F_50 ;
V_214 -> V_185 = F_44 ;
V_214 -> V_198 = F_49 ;
if ( F_112 ( V_2 ) ) {
F_39 ( L_43 ) ;
F_114 () ;
} else {
V_214 -> V_194 = F_80 ;
V_214 -> V_69 = F_58 ;
V_214 -> V_70 = F_55 ;
V_214 -> V_172 = F_60 ;
V_214 -> V_195 =
V_211 ;
V_214 -> V_212 = F_52 ;
F_1 ( V_2 ,
& V_214 -> V_12 , V_213 ,
V_209 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_89 ) ;
}
}
void F_115 ( struct V_1 * V_2 ,
struct V_39 * V_156 ,
T_6 V_92 , T_7 V_97 , T_6 V_93 , void * V_106 ,
T_9 V_196 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_209 =
(union V_6 * ) V_156 ;
F_110 ( V_156 , V_92 , V_97 , V_93 , V_106 ,
V_196 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_156 -> V_166 = F_46 ;
V_156 -> V_168 = F_51 ;
V_156 -> V_185 = F_42 ;
V_156 -> V_198 = F_47 ;
if ( F_116 ( V_2 ) ) {
F_39 ( L_44 ) ;
F_114 () ;
} else if ( F_117 ( V_2 ) ) {
V_156 -> V_194 = F_82 ;
V_156 -> V_69 = F_59 ;
V_156 -> V_70 = F_56 ;
V_156 -> V_172 = F_61 ;
V_156 -> V_195 = V_210 ;
F_1 ( V_2 ,
& V_156 -> V_12 , 1 , V_209 ,
F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_90 ) ;
} else {
V_156 -> V_194 = F_81 ;
V_156 -> V_69 = F_59 ;
V_156 -> V_70 = F_56 ;
V_156 -> V_172 = F_60 ;
V_156 -> V_195 =
V_211 ;
F_1 ( V_2 ,
& V_156 -> V_12 ,
V_213 ,
V_209 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_90 ) ;
}
}
static inline void F_118 ( struct V_1 * V_2 ,
struct V_215 * V_216 ,
T_8 V_134 )
{
T_11 V_52 = sizeof( struct V_215 ) ;
T_7 V_217 = V_218 +
F_119 ( V_134 ) ;
F_120 ( V_2 , V_217 , V_52 , ( T_7 * ) V_216 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_219 * V_154 )
{
T_7 V_220 = ( 1 << V_154 -> V_92 ) ;
struct V_215 * V_216 =
(struct V_215 * ) V_154 -> V_106 ;
T_6 V_221 = 1 , V_222 = 1 ;
T_6 V_223 = 0 , V_224 = 0 , V_225 = 0 ;
T_6 V_226 = 0 ;
if ( F_19 ( V_227 , & V_154 -> V_228 ) )
V_221 = 0 ;
if ( F_19 ( V_229 , & V_154 -> V_228 ) )
V_222 = 0 ;
if ( F_19 ( V_230 , & V_154 -> V_228 ) ) {
V_221 = 0 ;
V_223 = 1 ;
}
if ( F_19 ( V_231 , & V_154 -> V_228 ) ) {
V_222 = 0 ;
V_225 = 1 ;
}
if ( F_19 ( V_232 , & V_154 -> V_228 ) )
V_224 = 1 ;
if ( F_19 ( V_233 , & V_154 -> V_228 ) )
V_226 = 1 ;
V_216 -> V_234 = V_221 ?
V_216 -> V_234 | V_220 :
V_216 -> V_234 & ~ V_220 ;
V_216 -> V_235 = V_222 ?
V_216 -> V_235 | V_220 :
V_216 -> V_235 & ~ V_220 ;
V_216 -> V_236 = V_223 ?
V_216 -> V_236 | V_220 :
V_216 -> V_236 & ~ V_220 ;
V_216 -> V_237 = V_225 ?
V_216 -> V_237 | V_220 :
V_216 -> V_237 & ~ V_220 ;
V_216 -> V_238 = V_224 ?
V_216 -> V_238 | V_220 :
V_216 -> V_238 & ~ V_220 ;
V_216 -> V_226 = V_226 ?
V_216 -> V_226 | V_220 :
V_216 -> V_226 & ~ V_220 ;
F_4 ( V_17 , L_45
L_46 ,
V_216 -> V_234 , V_216 -> V_235 ,
V_216 -> V_236 , V_216 -> V_237 ,
V_216 -> V_238 ) ;
F_118 ( V_2 , V_216 , V_154 -> V_93 ) ;
F_30 ( V_154 -> V_33 , V_154 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_122 ( T_7 V_97 ,
struct V_98 * V_90 ,
T_6 V_99 )
{
V_90 -> V_100 = F_71 ( V_97 ) ;
V_90 -> V_99 = V_99 ;
}
static inline void F_123 ( struct V_1 * V_2 ,
unsigned long * V_239 ,
struct V_240 * V_107 ,
bool V_241 )
{
T_8 V_33 ;
V_33 = V_242 |
V_243 ;
if ( F_19 ( V_227 , V_239 ) )
V_33 &= ~ V_242 ;
if ( F_19 ( V_229 , V_239 ) )
V_33 &= ~ V_243 ;
if ( F_19 ( V_230 , V_239 ) ) {
V_33 &= ~ V_242 ;
V_33 |= V_244 ;
}
if ( F_19 ( V_231 , V_239 ) ) {
V_33 |= V_245 ;
V_33 &= ~ V_243 ;
}
if ( F_19 ( V_232 , V_239 ) )
V_33 |= V_246 ;
if ( F_19 ( V_233 , V_239 ) ) {
V_33 &= ~ V_242 ;
V_33 |= V_247 ;
}
if ( F_19 ( V_248 , V_239 ) )
V_33 |= V_249 ;
if ( V_241 ) {
V_33 &= ~ V_245 ;
V_33 &= ~ V_246 ;
V_33 &= ~ V_244 ;
V_33 &= ~ V_247 ;
}
V_107 -> V_33 = F_74 ( V_33 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_219 * V_154 )
{
struct V_250 * V_60 = V_154 -> V_106 ;
int V_22 ;
T_6 V_103 = 0 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
if ( F_19 ( V_251 , & V_154 -> V_25 ) ) {
V_60 -> V_111 [ V_103 ] . V_91 = V_154 -> V_92 ;
V_60 -> V_111 [ V_103 ] . V_93 = V_154 -> V_93 ;
V_60 -> V_111 [ V_103 ] . V_94 =
V_252 ;
F_123 ( V_2 , & V_154 -> V_253 ,
& ( V_60 -> V_111 [ V_103 ++ ] ) ,
false ) ;
}
if ( F_19 ( V_254 , & V_154 -> V_25 ) ) {
V_60 -> V_111 [ V_103 ] . V_91 = V_154 -> V_92 ;
V_60 -> V_111 [ V_103 ] . V_93 = V_154 -> V_93 ;
V_60 -> V_111 [ V_103 ] . V_94 =
V_255 ;
F_123 ( V_2 , & V_154 -> V_228 ,
& ( V_60 -> V_111 [ V_103 ++ ] ) ,
false ) ;
}
if ( F_19 ( V_256 , & V_154 -> V_257 ) ) {
if ( F_19 ( V_251 , & V_154 -> V_25 ) ) {
V_60 -> V_111 [ V_103 ] . V_91 = F_125 ( V_2 , V_92 ) ;
V_60 -> V_111 [ V_103 ] . V_93 = V_154 -> V_93 ;
V_60 -> V_111 [ V_103 ] . V_94 =
V_252 ;
F_123 ( V_2 , & V_154 -> V_253 ,
& ( V_60 -> V_111 [ V_103 ] ) ,
true ) ;
V_103 ++ ;
}
if ( F_19 ( V_254 , & V_154 -> V_25 ) ) {
V_60 -> V_111 [ V_103 ] . V_91 = F_125 ( V_2 , V_92 ) ;
V_60 -> V_111 [ V_103 ] . V_93 = V_154 -> V_93 ;
V_60 -> V_111 [ V_103 ] . V_94 =
V_255 ;
F_123 ( V_2 , & V_154 -> V_228 ,
& ( V_60 -> V_111 [ V_103 ] ) ,
true ) ;
V_103 ++ ;
}
}
F_122 ( V_154 -> V_97 , & V_60 -> V_120 , V_103 ) ;
F_4 ( V_17 , L_47 ,
V_60 -> V_120 . V_99 , V_154 -> V_228 ,
V_154 -> V_253 ) ;
V_22 = F_102 ( V_2 , V_258 , V_154 -> V_97 ,
F_103 ( V_154 -> V_196 ) ,
F_104 ( V_154 -> V_196 ) ,
V_197 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_219 * V_154 )
{
return F_34 ( V_2 , V_154 -> V_33 , V_154 -> V_34 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_219 * V_154 )
{
return 0 ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_219 * V_154 )
{
int V_22 ;
V_22 = V_154 -> V_259 -> V_260 ( V_2 , V_154 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_19 ( V_201 , & V_154 -> V_25 ) ) {
V_22 = V_154 -> V_259 -> V_175 ( V_2 , V_154 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
if ( F_112 ( V_2 ) ) {
V_4 -> V_175 = F_127 ;
V_4 -> V_260 = F_121 ;
} else {
V_4 -> V_175 = F_126 ;
V_4 -> V_260 = F_124 ;
}
}
static inline T_6 F_130 ( T_6 * V_61 )
{
return ( F_131 ( 0 , V_61 , V_58 ) >> 24 ) & 0xff ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_262 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_263 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_175 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_262 * V_4 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
int V_266 ;
struct V_267 * V_268 ;
struct V_269 * V_270 = NULL ;
struct V_271 * V_54 ;
int V_272 = ( ( V_107 == V_273 ) ?
V_154 -> V_274 : 0 ) ;
if ( ! V_154 -> V_274 )
return 0 ;
V_266 = sizeof( * V_268 ) +
V_272 * sizeof( struct V_269 ) ;
V_268 = F_26 ( V_266 , V_31 ) ;
if ( ! V_268 )
return - V_184 ;
F_4 ( V_17 , L_48 ,
V_107 , V_272 ) ;
F_2 ( & V_268 -> V_60 . V_275 ) ;
V_268 -> type = V_107 ;
V_268 -> V_276 = false ;
switch ( V_107 ) {
case V_273 :
V_270 = (struct V_269 * )
( ( T_6 * ) V_268 + sizeof( * V_268 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_270 -> V_61 , V_54 -> V_61 , V_58 ) ;
F_12 ( & V_270 -> V_24 , & V_268 -> V_60 . V_275 ) ;
V_270 ++ ;
}
break;
case V_277 :
V_268 -> V_60 . V_278 = V_154 -> V_274 ;
break;
case V_279 :
V_268 -> V_60 . V_280 = 0 ;
break;
default:
F_6 ( V_268 ) ;
F_39 ( L_49 , V_107 ) ;
return - V_62 ;
}
F_12 ( & V_268 -> V_24 , & V_4 -> V_281 ) ;
V_4 -> V_282 ( V_4 ) ;
return 1 ;
}
static inline int F_134 ( struct V_262 * V_4 , int V_283 )
{
int V_284 , V_285 , V_286 = V_283 % V_287 ;
for ( V_284 = V_283 / V_287 ; V_284 < V_288 ; V_284 ++ ) {
if ( V_4 -> V_289 . V_290 . V_291 [ V_284 ] )
for ( V_285 = V_286 ; V_285 < V_287 ; V_285 ++ ) {
int V_292 = V_285 + V_287 * V_284 ;
if ( F_135 ( V_4 -> V_289 . V_290 .
V_291 , V_292 ) ) {
return V_292 ;
}
}
V_286 = 0 ;
}
return - 1 ;
}
static inline int F_136 ( struct V_262 * V_4 )
{
int V_292 = F_134 ( V_4 , 0 ) ;
if ( V_292 >= 0 )
F_137 ( V_4 -> V_289 . V_290 . V_291 , V_292 ) ;
return V_292 ;
}
static inline T_6 F_138 ( struct V_262 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_71 = 0 ;
if ( ( V_38 -> V_72 == V_73 ) ||
( V_38 -> V_72 == V_74 ) )
V_71 |= V_293 ;
if ( ( V_38 -> V_72 == V_76 ) ||
( V_38 -> V_72 == V_74 ) )
V_71 |= V_294 ;
return V_71 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_262 * V_4 , int V_189 ,
union V_295 * V_296 ,
enum V_265 V_107 )
{
struct V_32 * V_127 = & V_4 -> V_38 ;
struct V_297 * V_60 =
(struct V_297 * ) ( V_127 -> V_106 ) ;
T_6 V_93 = V_127 -> V_93 ;
T_6 V_298 = F_138 ( V_4 ) ;
int V_299 ;
if ( ( V_107 == V_273 ) || ( V_107 == V_279 ) )
V_298 |= V_300 ;
V_60 -> V_111 [ V_189 ] . V_94 |= V_298 ;
switch ( V_107 ) {
case V_273 :
V_299 = F_130 ( V_296 -> V_61 ) ;
F_140 ( V_4 -> V_289 . V_290 . V_291 , V_299 ) ;
break;
case V_277 :
V_299 = F_136 ( V_4 ) ;
break;
case V_279 :
V_299 = V_296 -> V_299 ;
break;
default:
F_39 ( L_49 , V_107 ) ;
return;
}
F_4 ( V_17 , L_50 ,
( ( V_298 & V_300 ) ?
L_51 : L_52 ) , V_299 ) ;
V_60 -> V_111 [ V_189 ] . V_301 = ( T_6 ) V_299 ;
V_60 -> V_111 [ V_189 ] . V_93 = V_93 ;
V_60 -> V_111 [ V_189 ] . V_302 = V_4 -> V_302 ;
}
static inline int F_141 (
struct V_1 * V_2 , struct V_262 * V_4 , int V_303 ,
int * V_304 )
{
int V_305 , V_20 = * V_304 ;
union V_295 V_296 = { NULL } ;
for ( V_305 = F_134 ( V_4 , V_303 ) ; V_305 >= 0 ;
V_305 = F_134 ( V_4 , V_305 + 1 ) ) {
V_296 . V_299 = ( T_6 ) V_305 ;
V_4 -> V_194 ( V_2 , V_4 , V_20 , & V_296 ,
V_279 ) ;
V_20 ++ ;
F_4 ( V_17 , L_53 , V_305 ) ;
if ( V_20 >= V_4 -> V_306 )
break;
}
* V_304 = V_20 ;
return V_305 ;
}
static inline void F_142 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_267 * V_307 ,
int * V_308 )
{
struct V_269 * V_309 , * V_310 ;
int V_20 = * V_308 ;
union V_295 V_296 = { NULL } ;
F_107 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_296 . V_61 = & V_309 -> V_61 [ 0 ] ;
V_4 -> V_194 ( V_2 , V_4 , V_20 , & V_296 , V_307 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_309 -> V_61 ) ;
F_16 ( & V_309 -> V_24 ) ;
if ( V_20 >= V_4 -> V_306 )
break;
}
* V_308 = V_20 ;
if ( F_14 ( & V_307 -> V_60 . V_275 ) )
V_307 -> V_276 = true ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_267 * V_307 ,
int * V_308 )
{
int V_20 = * V_308 ;
while ( V_307 -> V_60 . V_278 ) {
V_4 -> V_194 ( V_2 , V_4 , V_20 , NULL , V_307 -> type ) ;
V_20 ++ ;
V_307 -> V_60 . V_278 -- ;
F_4 ( V_17 , L_55 ,
V_307 -> V_60 . V_278 , V_20 ) ;
if ( V_20 >= V_4 -> V_306 )
break;
}
* V_308 = V_20 ;
if ( ! V_307 -> V_60 . V_278 )
V_307 -> V_276 = true ;
}
static inline void F_144 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_267 * V_307 ,
int * V_308 )
{
V_307 -> V_60 . V_280 = V_4 -> V_311 ( V_2 , V_4 , V_307 -> V_60 . V_280 ,
V_308 ) ;
if ( V_307 -> V_60 . V_280 < 0 )
V_307 -> V_276 = true ;
else
V_307 -> V_60 . V_280 ++ ;
}
static inline int F_145 ( struct V_1 * V_2 ,
struct V_264 * V_154 )
{
struct V_267 * V_307 , * V_312 ;
int V_20 = 0 ;
struct V_262 * V_4 = V_154 -> V_313 ;
F_107 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_307 -> type ) {
case V_273 :
F_142 ( V_2 , V_4 , V_307 , & V_20 ) ;
break;
case V_277 :
F_143 ( V_2 , V_4 , V_307 , & V_20 ) ;
break;
case V_279 :
F_144 ( V_2 , V_4 , V_307 ,
& V_20 ) ;
break;
default:
F_39 ( L_49 , V_307 -> type ) ;
return - V_62 ;
}
if ( V_307 -> V_276 ) {
F_16 ( & V_307 -> V_24 ) ;
F_6 ( V_307 ) ;
}
if ( V_20 >= V_4 -> V_306 )
break;
}
return V_20 ;
}
static inline void F_146 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_264 * V_154 ,
int * V_308 )
{
struct V_271 * V_314 ;
union V_295 V_296 = { NULL } ;
int V_20 = * V_308 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_296 . V_61 = V_314 -> V_61 ;
V_4 -> V_194 ( V_2 , V_4 , V_20 , & V_296 , V_273 ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_314 -> V_61 ) ;
}
* V_308 = V_20 ;
}
static inline void F_147 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_264 * V_154 ,
int * V_308 )
{
int V_20 = * V_308 , V_284 ;
for ( V_284 = 0 ; V_284 < V_154 -> V_274 ; V_284 ++ ) {
V_4 -> V_194 ( V_2 , V_4 , V_20 , NULL , V_277 ) ;
V_20 ++ ;
F_4 ( V_17 , L_56 ,
V_154 -> V_274 - V_284 - 1 ) ;
}
* V_308 = V_20 ;
}
static inline int F_148 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 ,
int V_315 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
int V_20 = V_315 ;
F_4 ( V_17 , L_57 , V_154 -> V_274 ) ;
switch ( V_107 ) {
case V_273 :
F_146 ( V_2 , V_4 , V_154 , & V_20 ) ;
break;
case V_277 :
F_147 ( V_2 , V_4 , V_154 , & V_20 ) ;
break;
case V_279 :
V_4 -> V_311 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_39 ( L_49 , V_107 ) ;
return - V_62 ;
}
V_154 -> V_274 = 0 ;
return V_20 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
int V_316 = V_4 -> V_317 ( V_4 ) ;
switch ( V_107 ) {
case V_277 :
V_4 -> V_318 ( V_4 , 0 ) ;
case V_279 :
V_154 -> V_274 = V_316 ;
break;
case V_273 :
case V_319 :
V_4 -> V_318 ( V_4 , V_316 + V_154 -> V_274 ) ;
break;
default:
F_39 ( L_49 , V_107 ) ;
return - V_62 ;
}
V_4 -> V_320 += V_154 -> V_274 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
int V_321 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
V_4 -> V_318 ( V_4 , V_321 ) ;
V_4 -> V_320 -= V_154 -> V_274 ;
}
static inline void F_151 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
T_6 V_322 )
{
struct V_32 * V_127 = & V_154 -> V_313 -> V_38 ;
struct V_297 * V_60 =
(struct V_297 * ) ( V_127 -> V_106 ) ;
V_60 -> V_120 . V_100 = F_71 ( ( V_127 -> V_97 & V_101 ) |
( V_323 <<
V_102 ) ) ;
V_60 -> V_120 . V_99 = V_322 ;
}
static inline int F_152 ( struct V_1 * V_2 ,
struct V_262 * V_4 )
{
int V_284 , V_20 = 0 ;
T_12 V_19 ;
for ( V_284 = 0 ; V_284 < V_288 ; V_284 ++ ) {
V_19 = V_4 -> V_289 . V_290 . V_291 [ V_284 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_318 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
struct V_32 * V_38 = & V_154 -> V_313 -> V_38 ;
struct V_262 * V_4 = V_154 -> V_313 ;
struct V_297 * V_60 =
(struct V_297 * ) ( V_38 -> V_106 ) ;
int V_20 = 0 , V_22 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_20 = F_145 ( V_2 , V_154 ) ;
if ( F_14 ( & V_4 -> V_281 ) )
V_4 -> V_324 ( V_4 ) ;
if ( V_154 -> V_274 > 0 )
V_20 = F_148 ( V_2 , V_154 , V_107 , V_20 ) ;
V_4 -> V_320 -= V_20 ;
F_20 ( V_4 -> V_320 < 0 ) ;
F_20 ( V_20 > V_4 -> V_306 ) ;
F_151 ( V_2 , V_154 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_320 )
F_152 ( V_2 , V_4 ) ;
if ( F_19 ( V_28 , & V_154 -> V_25 ) ) {
V_38 -> V_178 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_102 ( V_2 , V_325 ,
V_38 -> V_97 , F_103 ( V_38 -> V_196 ) ,
F_104 ( V_38 -> V_196 ) ,
V_197 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_154 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
if ( ( V_107 == V_277 ) || ( V_107 == V_279 ) )
V_154 -> V_274 = 1 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
int V_321 )
{
}
static inline void F_156 ( struct V_1 * V_2 ,
struct V_262 * V_4 ,
struct V_264 * V_154 ,
T_7 * V_326 )
{
struct V_271 * V_314 ;
int V_327 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_327 = F_130 ( V_314 -> V_61 ) ;
F_157 ( V_326 , V_327 ) ;
F_4 ( V_17 , L_58 ,
V_314 -> V_61 , V_327 ) ;
F_140 ( V_4 -> V_289 . V_290 . V_291 ,
V_327 ) ;
}
}
static inline void F_158 ( struct V_1 * V_2 ,
struct V_262 * V_4 , struct V_264 * V_154 ,
T_7 * V_326 )
{
int V_327 ;
for ( V_327 = F_134 ( V_4 , 0 ) ;
V_327 >= 0 ;
V_327 = F_134 ( V_4 , V_327 + 1 ) ) {
F_157 ( V_326 , V_327 ) ;
F_4 ( V_17 , L_59 , V_327 ) ;
}
}
static int F_159 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
int V_284 ;
struct V_262 * V_4 = V_154 -> V_313 ;
struct V_32 * V_127 = & V_4 -> V_38 ;
if ( ! F_19 ( V_28 , & V_154 -> V_25 ) ) {
T_7 V_326 [ V_328 ] = { 0 } ;
switch ( V_107 ) {
case V_273 :
F_156 ( V_2 , V_4 , V_154 , V_326 ) ;
break;
case V_277 :
F_4 ( V_17 ,
L_60 ) ;
memset ( V_4 -> V_289 . V_290 . V_291 , 0 ,
sizeof( V_4 -> V_289 . V_290 . V_291 ) ) ;
break;
case V_279 :
F_158 ( V_2 , V_4 , V_154 , V_326 ) ;
break;
default:
F_39 ( L_49 , V_107 ) ;
return - V_62 ;
}
for ( V_284 = 0 ; V_284 < V_328 ; V_284 ++ )
F_68 ( V_2 , F_160 ( V_2 , V_284 ) , V_326 [ V_284 ] ) ;
} else
memset ( V_4 -> V_289 . V_290 . V_291 , 0 ,
sizeof( V_4 -> V_289 . V_290 . V_291 ) ) ;
V_127 -> V_178 ( V_127 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
int V_316 = V_4 -> V_317 ( V_4 ) ;
switch ( V_107 ) {
case V_277 :
V_4 -> V_318 ( V_4 , 0 ) ;
case V_279 :
V_154 -> V_274 = V_316 ;
F_4 ( V_17 , L_61 ,
V_107 , V_154 -> V_274 ) ;
break;
case V_273 :
case V_319 :
if ( V_154 -> V_274 > V_4 -> V_306 ) {
F_39 ( L_62 ,
V_4 -> V_306 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_57 , V_154 -> V_274 ) ;
if ( V_154 -> V_274 > 0 )
V_4 -> V_318 ( V_4 , V_154 -> V_274 ) ;
break;
default:
F_39 ( L_49 , V_107 ) ;
return - V_62 ;
}
if ( V_154 -> V_274 )
V_4 -> V_320 += V_4 -> V_306 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
int V_329 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
V_4 -> V_318 ( V_4 , V_329 ) ;
if ( V_154 -> V_274 )
V_4 -> V_320 -= V_4 -> V_306 ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_262 * V_4 , int V_189 ,
union V_295 * V_296 ,
enum V_265 V_107 )
{
struct V_32 * V_127 = & V_4 -> V_38 ;
struct V_143 * V_60 =
(struct V_143 * ) ( V_127 -> V_106 ) ;
if ( ( V_107 == V_273 ) || ( V_107 == V_279 ) ) {
F_73 ( & V_60 -> V_145 [ V_189 ] . V_139 ,
& V_60 -> V_145 [ V_189 ] . V_140 ,
& V_60 -> V_145 [ V_189 ] . V_141 ,
V_296 -> V_61 ) ;
V_60 -> V_145 [ V_189 ] . V_129 = 0 ;
V_60 -> V_145 [ V_189 ] . V_134 = V_127 -> V_93 ;
V_60 -> V_145 [ V_189 ] . V_133 =
F_71 ( 1 << V_127 -> V_92 ) ;
F_77 ( V_60 -> V_145 [ V_189 ] . V_135 ,
V_136 ,
V_137 ) ;
}
}
static inline void F_164 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
T_6 V_322 )
{
struct V_32 * V_127 = & V_154 -> V_313 -> V_38 ;
struct V_143 * V_60 =
(struct V_143 * ) ( V_127 -> V_106 ) ;
T_6 V_40 = ( F_165 ( V_2 ) ?
V_330 * ( 1 + V_127 -> V_93 ) :
V_331 * ( 1 + V_127 -> V_93 ) ) ;
V_60 -> V_90 . V_40 = V_40 ;
V_60 -> V_90 . V_91 = F_74 ( 0xff ) ;
V_60 -> V_90 . V_100 = F_71 ( ( V_127 -> V_97 & V_101 ) |
( V_323 <<
V_102 ) ) ;
V_60 -> V_90 . V_128 = V_322 ;
}
static inline int F_166 (
struct V_1 * V_2 , struct V_262 * V_4 , int V_332 ,
int * V_304 )
{
struct V_269 * V_19 ;
int V_284 = 0 ;
union V_295 V_296 = { NULL } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_296 . V_61 = & V_19 -> V_61 [ 0 ] ;
V_4 -> V_194 ( V_2 , V_4 , V_284 , & V_296 , V_279 ) ;
V_284 ++ ;
F_4 ( V_17 , L_54 ,
V_296 . V_61 ) ;
}
* V_304 = V_284 ;
return - 1 ;
}
static inline int F_167 (
struct V_1 * V_2 , struct V_264 * V_154 )
{
struct V_267 * V_307 ;
struct V_269 * V_309 ;
struct V_262 * V_4 = V_154 -> V_313 ;
union V_295 V_296 = { NULL } ;
int V_20 = 0 ;
if ( F_14 ( & V_4 -> V_281 ) )
return 0 ;
V_307 = F_15 ( & V_4 -> V_281 ,
struct V_267 , V_24 ) ;
switch ( V_307 -> type ) {
case V_273 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_296 . V_61 = & V_309 -> V_61 [ 0 ] ;
V_4 -> V_194 ( V_2 , V_4 , V_20 , & V_296 , V_307 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_309 -> V_61 ) ;
}
break;
case V_277 :
V_20 = V_307 -> V_60 . V_278 ;
F_4 ( V_17 , L_63 , V_20 ) ;
break;
case V_279 :
V_4 -> V_311 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_39 ( L_49 , V_307 -> type ) ;
return - V_62 ;
}
F_16 ( & V_307 -> V_24 ) ;
F_6 ( V_307 ) ;
return V_20 ;
}
static inline void F_168 ( T_13 * V_333 , T_13 * V_334 ,
T_13 * V_335 , T_6 * V_61 )
{
V_61 [ 1 ] = ( ( T_6 * ) V_333 ) [ 0 ] ;
V_61 [ 0 ] = ( ( T_6 * ) V_333 ) [ 1 ] ;
V_61 [ 3 ] = ( ( T_6 * ) V_334 ) [ 0 ] ;
V_61 [ 2 ] = ( ( T_6 * ) V_334 ) [ 1 ] ;
V_61 [ 5 ] = ( ( T_6 * ) V_335 ) [ 0 ] ;
V_61 [ 4 ] = ( ( T_6 * ) V_335 ) [ 1 ] ;
}
static inline int F_169 ( struct V_1 * V_2 ,
struct V_262 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_269 * V_19 ;
struct V_143 * V_60 =
(struct V_143 * ) ( V_38 -> V_106 ) ;
if ( F_170 ( V_60 -> V_145 [ 0 ] . V_135 ,
V_136 ) ) {
int V_284 , V_322 = V_60 -> V_90 . V_128 ;
if ( ! F_14 ( & V_4 -> V_289 . V_336 . V_337 ) )
return 0 ;
V_19 = F_171 ( V_322 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_39 ( L_64 ) ;
return - V_184 ;
}
for ( V_284 = 0 ; V_284 < V_322 ; V_284 ++ , V_19 ++ ) {
F_168 (
& V_60 -> V_145 [ V_284 ] . V_139 ,
& V_60 -> V_145 [ V_284 ] . V_140 ,
& V_60 -> V_145 [ V_284 ] . V_141 ,
V_19 -> V_61 ) ;
F_4 ( V_17 , L_65 ,
V_19 -> V_61 ) ;
F_12 ( & V_19 -> V_24 ,
& V_4 -> V_289 . V_336 . V_337 ) ;
}
} else {
V_19 = F_15 ( & V_4 -> V_289 . V_336 . V_337 ,
struct V_269 , V_24 ) ;
F_4 ( V_17 , L_66 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_289 . V_336 . V_337 ) ;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_143 * V_60 =
(struct V_143 * ) ( V_38 -> V_106 ) ;
int V_20 = 0 , V_284 , V_22 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
for ( V_284 = 0 ; V_284 < V_4 -> V_306 ; V_284 ++ )
F_77 ( V_60 -> V_145 [ V_284 ] . V_135 ,
V_136 ,
V_142 ) ;
V_20 = F_167 ( V_2 , V_154 ) ;
if ( F_14 ( & V_4 -> V_281 ) )
V_4 -> V_324 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_148 ( V_2 , V_154 , V_107 , 0 ) ;
V_4 -> V_320 -= V_4 -> V_306 ;
F_20 ( V_20 > V_4 -> V_306 ) ;
F_164 ( V_2 , V_154 , ( T_6 ) V_20 ) ;
V_22 = F_169 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_19 ( V_28 , & V_154 -> V_25 ) ) {
V_38 -> V_178 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_102 ( V_2 , V_210 , V_38 -> V_97 ,
F_103 ( V_38 -> V_196 ) ,
F_104 ( V_38 -> V_196 ) ,
V_197 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_173 ( struct V_262 * V_4 )
{
return V_4 -> V_289 . V_336 . V_338 ;
}
static int F_174 ( struct V_262 * V_4 )
{
return V_4 -> V_289 . V_290 . V_339 ;
}
static void F_175 ( struct V_262 * V_4 ,
int V_49 )
{
V_4 -> V_289 . V_336 . V_338 = V_49 ;
}
static void F_176 ( struct V_262 * V_4 ,
int V_49 )
{
V_4 -> V_289 . V_290 . V_339 = V_49 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_264 * V_154 ,
enum V_265 V_107 )
{
struct V_262 * V_4 = V_154 -> V_313 ;
struct V_32 * V_127 = & V_4 -> V_38 ;
int V_22 = 0 , V_340 ;
V_340 = V_4 -> V_317 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_154 , V_107 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_154 -> V_274 ) && ( ! V_4 -> V_341 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_67 ,
V_4 -> V_320 , V_154 -> V_274 , V_4 -> V_306 ) ;
if ( V_127 -> V_191 ( V_127 ) ||
( ( V_4 -> V_306 > 0 ) && ( V_4 -> V_320 > V_4 -> V_306 ) ) ) {
V_22 = V_4 -> V_342 ( V_2 , V_154 -> V_313 , V_154 , V_107 ) ;
if ( V_22 < 0 )
goto V_343;
V_154 -> V_274 = 0 ;
}
if ( ! V_127 -> V_191 ( V_127 ) ) {
V_127 -> V_192 ( V_127 ) ;
V_22 = V_4 -> V_344 ( V_2 , V_154 , V_107 ) ;
if ( V_22 < 0 )
goto V_345;
if ( F_19 ( V_201 , & V_154 -> V_25 ) )
V_22 = V_4 -> V_175 ( V_2 , V_4 ) ;
}
return V_22 ;
V_345:
V_127 -> V_178 ( V_127 ) ;
V_343:
V_4 -> V_346 ( V_2 , V_154 , V_340 ) ;
return V_22 ;
}
static void F_178 ( struct V_262 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_263 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_179 ( struct V_262 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_263 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_180 ( struct V_262 * V_4 )
{
return ! ! F_19 ( V_4 -> V_263 , V_4 -> V_38 . V_34 ) ;
}
static bool F_181 ( struct V_262 * V_4 )
{
return V_4 -> V_38 . V_191 ( & V_4 -> V_38 ) || V_4 -> V_341 ( V_4 ) ;
}
void F_182 ( struct V_1 * V_2 ,
struct V_262 * V_313 ,
T_6 V_347 , T_7 V_348 , T_6 V_93 ,
T_6 V_302 , void * V_106 , T_9 V_196 ,
int V_33 , unsigned long * V_34 , T_10 type )
{
memset ( V_313 , 0 , sizeof( * V_313 ) ) ;
F_109 ( & V_313 -> V_38 , V_347 , V_348 , V_93 ,
V_106 , V_196 , V_33 , V_34 , type ) ;
V_313 -> V_302 = V_302 ;
F_2 ( & V_313 -> V_281 ) ;
V_313 -> V_263 = V_349 ;
V_313 -> V_341 = F_180 ;
V_313 -> V_282 = F_179 ;
V_313 -> V_324 = F_178 ;
if ( F_116 ( V_2 ) ) {
V_313 -> V_344 = F_172 ;
V_313 -> V_342 = F_133 ;
V_313 -> V_311 =
F_166 ;
V_313 -> V_191 = F_181 ;
if ( F_165 ( V_2 ) )
V_313 -> V_306 = V_330 ;
else
V_313 -> V_306 = V_331 ;
V_313 -> V_175 = F_132 ;
V_313 -> V_194 = F_163 ;
V_313 -> V_8 = F_161 ;
V_313 -> V_346 = F_162 ;
V_313 -> V_317 =
F_173 ;
V_313 -> V_318 =
F_175 ;
F_2 ( & V_313 -> V_289 . V_336 . V_337 ) ;
} else if ( F_117 ( V_2 ) ) {
V_313 -> V_344 = F_159 ;
V_313 -> V_342 = NULL ;
V_313 -> V_311 = NULL ;
V_313 -> V_191 = F_181 ;
V_313 -> V_306 = - 1 ;
V_313 -> V_175 = F_132 ;
V_313 -> V_194 = NULL ;
V_313 -> V_8 = F_154 ;
V_313 -> V_346 = F_155 ;
V_313 -> V_317 =
F_174 ;
V_313 -> V_318 =
F_176 ;
} else {
V_313 -> V_344 = F_153 ;
V_313 -> V_342 = F_133 ;
V_313 -> V_311 =
F_141 ;
V_313 -> V_191 = F_181 ;
V_313 -> V_306 = 16 ;
V_313 -> V_175 = F_132 ;
V_313 -> V_194 = F_139 ;
V_313 -> V_8 = F_149 ;
V_313 -> V_346 = F_150 ;
V_313 -> V_317 =
F_174 ;
V_313 -> V_318 =
F_176 ;
}
}
static inline bool F_183 ( T_14 * V_350 , int V_351 , int V_57 )
{
int V_352 , V_353 ;
V_352 = F_184 ( V_350 ) ;
for (; ; ) {
if ( F_185 ( V_352 + V_351 >= V_57 ) )
return false ;
V_353 = F_186 ( ( V_350 ) , V_352 , V_352 + V_351 ) ;
if ( F_187 ( V_353 == V_352 ) )
break;
V_352 = V_353 ;
}
return true ;
}
static inline bool F_188 ( T_14 * V_350 , int V_351 , int V_57 )
{
int V_352 , V_353 ;
V_352 = F_184 ( V_350 ) ;
for (; ; ) {
if ( F_185 ( V_352 - V_351 < V_57 ) )
return false ;
V_353 = F_186 ( ( V_350 ) , V_352 , V_352 - V_351 ) ;
if ( F_187 ( V_353 == V_352 ) )
break;
V_352 = V_353 ;
}
return true ;
}
static bool F_189 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_190 () ;
V_22 = F_188 ( & V_4 -> V_354 , V_20 , 0 ) ;
F_190 () ;
return V_22 ;
}
static bool F_191 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_190 () ;
V_22 = F_183 ( & V_4 -> V_354 , V_20 , V_4 -> V_355 + 1 ) ;
F_190 () ;
return V_22 ;
}
static int F_192 ( struct V_41 * V_4 )
{
int V_356 ;
F_190 () ;
V_356 = F_184 ( & V_4 -> V_354 ) ;
return V_356 ;
}
static bool F_193 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_194 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_189 , V_291 , V_284 ;
* V_40 = - 1 ;
for ( V_291 = 0 ; V_291 < V_357 ; V_291 ++ ) {
if ( ! V_4 -> V_358 [ V_291 ] )
continue;
for ( V_189 = V_291 * V_287 , V_284 = 0 ;
V_284 < V_287 ; V_189 ++ , V_284 ++ )
if ( F_135 ( V_4 -> V_358 , V_189 ) ) {
F_137 ( V_4 -> V_358 , V_189 ) ;
* V_40 = V_4 -> V_359 + V_189 ;
return true ;
}
}
return false ;
}
static bool F_195 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_359 )
return false ;
V_40 -= V_4 -> V_359 ;
if ( V_40 >= V_4 -> V_355 )
return false ;
F_140 ( V_4 -> V_358 , V_40 ) ;
return true ;
}
static bool F_196 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_197 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_198 ( struct V_41 * V_154 ,
int V_50 , int V_354 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
memset ( & V_154 -> V_358 , 0xff , sizeof( V_154 -> V_358 ) ) ;
F_199 ( & V_154 -> V_354 , V_354 ) ;
V_154 -> V_355 = V_354 ;
V_154 -> V_359 = V_50 ;
F_190 () ;
V_154 -> V_360 = F_192 ;
if ( V_354 >= 0 ) {
V_154 -> V_47 = F_191 ;
V_154 -> V_11 = F_189 ;
V_154 -> V_48 = F_195 ;
V_154 -> V_44 = F_194 ;
} else {
V_154 -> V_47 = F_193 ;
V_154 -> V_11 = F_193 ;
V_154 -> V_48 = F_196 ;
V_154 -> V_44 = F_197 ;
}
if ( V_50 < 0 ) {
V_154 -> V_48 = F_196 ;
V_154 -> V_44 = F_197 ;
}
}
void F_200 ( struct V_1 * V_2 ,
struct V_41 * V_154 , T_6 V_93 ,
T_6 V_361 )
{
#define F_201 5
int V_362 ;
if ( F_116 ( V_2 ) ) {
if ( ! F_165 ( V_2 ) )
V_362 = ( V_363 / 2 ) - V_331 ;
else
V_362 = F_201 - V_330 ;
F_198 ( V_154 , V_93 * V_362 , V_362 ) ;
} else if ( F_117 ( V_2 ) ) {
if ( ( V_361 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_362 = ( V_364 / ( 2 * V_361 ) ) ;
else
V_362 = F_201 ;
F_198 ( V_154 , V_93 * V_362 , V_362 ) ;
} else {
F_198 ( V_154 , 0 , 0 ) ;
}
} else {
if ( ( V_361 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_362 = ( V_365 / V_361 ) ;
else
V_362 = F_201 ;
F_198 ( V_154 , - 1 , V_362 ) ;
} else {
F_198 ( V_154 , 0 , 0 ) ;
}
}
}
void F_202 ( struct V_1 * V_2 ,
struct V_41 * V_154 ,
T_6 V_93 ,
T_6 V_361 )
{
if ( F_112 ( V_2 ) ) {
F_198 ( V_154 , 0 , - 1 ) ;
} else {
if ( V_361 > 0 ) {
int V_354 = V_366 / V_361 ;
F_198 ( V_154 , V_93 * V_354 , V_354 ) ;
} else
F_198 ( V_154 , 0 , 0 ) ;
}
}
static inline void F_203 ( struct V_1 * V_2 ,
struct V_367 * V_154 )
{
int V_284 ;
F_4 ( V_17 , L_68 ) ;
F_4 ( V_17 , L_69 ) ;
for ( V_284 = 0 ; V_284 < V_368 ; V_284 ++ ) {
F_204 ( V_17 , L_70 , V_154 -> V_369 [ V_284 ] ) ;
if ( ( V_284 + 1 < V_368 ) &&
( ( ( V_284 + 1 ) & 0x3 ) == 0 ) ) {
F_204 ( V_17 , L_71 ) ;
F_4 ( V_17 , L_72 , V_284 + 1 ) ;
}
}
F_204 ( V_17 , L_71 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_367 * V_154 )
{
struct V_370 * V_4 = V_154 -> V_371 ;
struct V_32 * V_127 = & V_4 -> V_38 ;
struct V_372 * V_60 =
(struct V_372 * ) ( V_127 -> V_106 ) ;
T_6 V_373 = 0 ;
int V_22 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_4 ( V_17 , L_73 ) ;
V_60 -> V_100 = F_71 ( ( V_127 -> V_97 & V_101 ) |
( V_127 -> V_33 << V_102 ) ) ;
if ( F_19 ( V_374 , & V_154 -> V_375 ) )
V_373 = V_376 ;
else if ( F_19 ( V_377 , & V_154 -> V_375 ) )
V_373 = V_378 ;
V_60 -> V_373 = V_373 ;
F_4 ( V_17 , L_74 , V_373 ) ;
if ( F_19 ( V_379 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_381 ;
if ( F_19 ( V_382 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_383 ;
if ( F_19 ( V_384 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_385 ;
if ( F_19 ( V_386 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_387 ;
if ( F_19 ( V_388 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_389 ;
if ( F_19 ( V_390 , & V_154 -> V_375 ) )
V_60 -> V_380 |=
V_391 ;
V_60 -> V_392 = V_154 -> V_392 ;
V_60 -> V_393 = V_4 -> V_302 ;
F_4 ( V_17 , L_75 , V_60 -> V_393 ) ;
memcpy ( V_60 -> V_394 , V_154 -> V_369 ,
V_368 ) ;
memcpy ( V_4 -> V_369 , V_154 -> V_369 , V_368 ) ;
if ( F_206 ( V_2 ) )
F_203 ( V_2 , V_154 ) ;
if ( F_19 ( V_395 , & V_154 -> V_375 ) ) {
memcpy ( & V_60 -> V_396 [ 0 ] , & V_154 -> V_396 [ 0 ] ,
sizeof( V_60 -> V_396 ) ) ;
V_60 -> V_380 |= V_397 ;
}
V_22 = F_102 ( V_2 , V_398 , V_127 -> V_97 ,
F_103 ( V_127 -> V_196 ) ,
F_104 ( V_127 -> V_196 ) ,
V_197 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_207 ( struct V_370 * V_371 ,
T_6 * V_369 )
{
memcpy ( V_369 , V_371 -> V_369 , sizeof( V_371 -> V_369 ) ) ;
}
int F_208 ( struct V_1 * V_2 ,
struct V_367 * V_154 )
{
int V_22 ;
struct V_370 * V_4 = V_154 -> V_371 ;
struct V_32 * V_127 = & V_4 -> V_38 ;
if ( F_19 ( V_28 , & V_154 -> V_25 ) )
return 0 ;
V_127 -> V_192 ( V_127 ) ;
V_22 = V_4 -> V_399 ( V_2 , V_154 ) ;
if ( V_22 < 0 ) {
V_127 -> V_178 ( V_127 ) ;
return V_22 ;
}
if ( F_19 ( V_201 , & V_154 -> V_25 ) )
V_22 = V_127 -> V_175 ( V_2 , V_127 ) ;
return V_22 ;
}
void F_209 ( struct V_1 * V_2 ,
struct V_370 * V_371 ,
T_6 V_92 , T_7 V_97 , T_6 V_93 , T_6 V_302 ,
void * V_106 , T_9 V_196 ,
int V_33 , unsigned long * V_34 ,
T_10 type )
{
F_109 ( & V_371 -> V_38 , V_92 , V_97 , V_93 , V_106 ,
V_196 , V_33 , V_34 , type ) ;
V_371 -> V_302 = V_302 ;
V_371 -> V_399 = F_205 ;
}
int F_210 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
int V_22 , V_404 ;
unsigned long * V_405 = & V_4 -> V_405 ;
V_22 = V_4 -> V_406 ( V_2 , V_4 , V_401 ) ;
if ( V_22 ) {
F_39 ( L_76 , V_22 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_77 , V_4 -> V_405 ) ;
V_404 = V_4 -> V_192 ( V_4 , V_401 ) ;
F_4 ( V_17 , L_78 , V_4 -> V_405 ) ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) )
V_4 -> V_407 ( V_2 , V_4 , V_404 ) ;
else {
V_22 = V_4 -> V_408 ( V_2 , V_401 ) ;
if ( V_22 ) {
V_4 -> V_409 = V_410 ;
F_30 ( V_404 , V_405 ) ;
F_31 () ;
return V_22 ;
}
if ( F_19 ( V_201 , & V_401 -> V_25 ) ) {
V_22 = V_4 -> V_175 ( V_2 , V_4 , V_404 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_19 ( V_404 , V_405 ) ;
}
static int F_211 ( struct V_402 * V_411 ,
struct V_400 * V_401 )
{
enum V_412 V_107 = V_401 -> V_107 , V_327 ;
if ( ( V_107 == V_413 ) ||
( V_107 == V_414 ) )
V_327 = V_415 ;
else
V_327 = V_107 ;
F_33 ( V_327 , & V_411 -> V_405 ) ;
return V_327 ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
enum V_412 V_107 )
{
return F_34 ( V_2 , V_107 , & V_4 -> V_405 ) ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
enum V_412 V_107 )
{
unsigned long V_416 = V_4 -> V_405 ;
if ( ! F_214 ( V_107 , & V_416 ) ) {
F_39 ( L_79 ,
V_107 , V_4 -> V_417 [ V_418 ] ,
V_4 -> V_33 , V_416 , V_4 -> V_409 ) ;
return - V_62 ;
}
if ( V_4 -> V_419 >= V_4 -> V_420 )
F_39 ( L_80 ,
V_4 -> V_419 , V_4 -> V_420 ) ;
F_4 ( V_17 ,
L_81 ,
V_107 , V_4 -> V_417 [ V_418 ] , V_4 -> V_409 ) ;
if ( V_4 -> V_419 )
F_4 ( V_17 , L_82 ,
V_4 -> V_417 [ V_418 ] , V_4 -> V_419 ) ;
V_4 -> V_33 = V_4 -> V_409 ;
V_4 -> V_421 = V_4 -> V_419 ;
V_4 -> V_409 = V_410 ;
F_215 () ;
F_30 ( V_107 , & V_4 -> V_405 ) ;
F_31 () ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_423 * V_60 )
{
struct V_424 * V_401 = & V_422 -> V_401 . V_425 ;
V_60 -> V_426 . V_427 |= F_19 ( V_428 , & V_401 -> V_135 ) *
V_429 ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
struct V_430 * V_401 ,
struct V_431 * V_432 ,
unsigned long * V_135 )
{
V_432 -> V_91 = V_4 -> V_92 ;
if ( F_19 ( V_433 , V_135 ) ) {
V_432 -> V_434 =
V_401 -> V_435 ;
V_432 -> V_436 = 1 ;
V_432 -> V_437 =
F_19 ( V_438 , V_135 ) ;
} else
V_432 -> V_434 =
V_439 ;
V_432 -> V_440 = F_19 ( V_441 , V_135 ) ;
V_432 -> V_442 = F_19 ( V_443 , V_135 ) ;
V_432 -> V_444 = V_401 -> V_445 ;
V_432 -> V_446 = F_74 ( V_401 -> V_446 ) ;
V_432 -> V_93 = V_4 -> V_93 ;
V_432 -> cos = V_401 -> cos ;
V_432 -> V_447 =
F_19 ( V_441 , V_135 ) ?
V_448 : V_449 ;
F_4 ( V_17 , L_83 ,
V_432 -> V_442 , V_432 -> cos , V_432 -> V_436 ) ;
}
static void F_218 ( struct V_402 * V_4 ,
struct V_450 * V_401 ,
struct V_451 * V_452 ,
unsigned long * V_135 )
{
V_452 -> V_453 =
F_19 ( V_454 , V_135 ) ;
V_452 -> V_455 =
F_74 ( V_401 -> V_455 ) ;
V_452 -> V_456 =
F_19 ( V_457 , V_135 ) ;
V_452 -> V_458 =
F_19 ( V_459 , V_135 ) ;
V_452 -> V_460 =
F_19 ( V_461 , V_135 ) ;
V_452 -> V_462 =
F_19 ( V_463 , V_135 ) ;
V_452 -> V_464 =
F_19 ( V_465 , V_135 ) ;
V_452 -> V_466 =
F_19 ( V_467 , V_135 ) ? V_468 :
V_469 ;
V_452 -> V_470 = V_401 -> V_471 ;
V_452 -> V_472 = V_401 -> V_473 ;
V_452 -> V_474 = V_401 -> V_475 ;
V_452 -> V_476 . V_477 =
F_71 ( F_104 ( V_401 -> V_478 ) ) ;
V_452 -> V_476 . V_479 =
F_71 ( F_103 ( V_401 -> V_478 ) ) ;
V_452 -> V_33 = 0 ;
}
static void F_219 ( struct V_402 * V_4 ,
struct V_480 * V_401 ,
struct V_481 * V_482 )
{
V_482 -> V_483 = F_74 ( V_401 -> V_484 ) ;
V_482 -> V_485 = F_74 ( V_401 -> V_486 ) ;
V_482 -> V_487 = F_74 ( V_401 -> V_488 ) ;
V_482 -> V_489 = F_74 ( V_401 -> V_490 ) ;
V_482 -> V_491 = F_74 ( V_401 -> V_492 ) ;
V_482 -> V_493 = F_74 ( V_401 -> V_494 ) ;
V_482 -> V_495 = F_74 ( V_401 -> V_496 ) ;
}
static void F_220 ( struct V_402 * V_4 ,
struct V_497 * V_401 ,
struct V_481 * V_482 ,
unsigned long * V_135 )
{
V_482 -> V_427 = F_19 ( V_498 , V_135 ) *
V_499 ;
V_482 -> V_427 |= F_19 ( V_500 , V_135 ) *
V_501 ;
V_482 -> V_502 = 0 ;
V_482 -> V_503 =
V_401 -> V_504 ;
V_482 -> V_505 =
F_19 ( V_506 , V_135 ) ;
V_482 -> V_507 = V_401 -> V_508 ;
V_482 -> V_509 = V_401 -> V_510 ;
V_482 -> V_511 = F_74 ( V_401 -> V_512 ) ;
V_482 -> V_33 = F_74 ( V_513 |
V_514 ) ;
V_482 -> V_515 = 0 ;
V_482 -> V_516 = 0 ;
V_482 -> V_517 = 0 ;
V_482 -> V_518 = 0 ;
V_482 -> V_519 =
F_19 ( V_520 , V_135 ) ;
V_482 -> V_521 =
F_19 ( V_522 , V_135 ) ;
V_482 -> V_523 = V_401 -> V_471 ;
V_482 -> V_524 = V_401 -> V_473 ;
V_482 -> V_525 = V_401 -> V_525 ;
V_482 -> V_526 = F_74 ( V_401 -> V_527 ) ;
V_482 -> V_528 = F_74 ( V_401 -> V_529 ) ;
V_482 -> V_530 . V_477 =
F_71 ( F_104 ( V_401 -> V_478 ) ) ;
V_482 -> V_530 . V_479 =
F_71 ( F_103 ( V_401 -> V_478 ) ) ;
V_482 -> V_531 . V_477 =
F_71 ( F_104 ( V_401 -> V_532 ) ) ;
V_482 -> V_531 . V_479 =
F_71 ( F_103 ( V_401 -> V_532 ) ) ;
V_482 -> V_533 . V_477 =
F_71 ( F_104 ( V_401 -> V_534 ) ) ;
V_482 -> V_533 . V_479 =
F_71 ( F_103 ( V_401 -> V_534 ) ) ;
V_482 -> V_535 = F_19 ( V_536 , V_135 ) ;
if ( F_19 ( V_537 , V_135 ) ) {
V_482 -> V_538 = V_401 -> V_539 ;
V_482 -> V_540 = 1 ;
}
V_482 -> V_393 = V_401 -> V_393 ;
V_482 -> V_541 =
F_19 ( V_542 , V_135 ) ;
V_482 -> V_543 =
F_74 ( V_401 -> V_544 ) ;
V_482 -> V_545 =
F_74 ( V_401 -> V_546 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_423 * V_60 )
{
F_217 ( V_2 , V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_547 ,
& V_60 -> V_548 ,
& V_422 -> V_401 . V_425 . V_135 ) ;
F_218 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_549 ,
& V_60 -> V_550 ,
& V_422 -> V_401 . V_425 . V_135 ) ;
F_220 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_551 ,
& V_60 -> V_426 ,
& V_422 -> V_401 . V_425 . V_135 ) ;
F_219 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_552 ,
& V_60 -> V_426 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_553 * V_60 )
{
F_217 ( V_2 , V_422 -> V_403 ,
& V_422 -> V_401 . V_554 . V_547 ,
& V_60 -> V_548 ,
& V_422 -> V_401 . V_554 . V_135 ) ;
F_218 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_554 . V_549 ,
& V_60 -> V_550 ,
& V_422 -> V_401 . V_554 . V_135 ) ;
F_4 ( V_17 , L_84 ,
V_422 -> V_403 -> V_417 [ 0 ] ,
V_60 -> V_550 . V_476 . V_477 ,
V_60 -> V_550 . V_476 . V_479 ) ;
}
static inline int F_223 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_555 * V_556 = & V_401 -> V_401 . V_556 ;
T_8 V_557 ;
T_6 cos ;
if ( F_19 ( V_558 , & V_4 -> type ) &&
F_19 ( V_559 , & V_556 -> V_550 . V_135 ) ) {
V_557 = V_556 -> V_550 . V_560 ? 1000000 / V_556 -> V_550 . V_560 : 0 ;
F_224 ( V_2 , V_556 -> V_550 . V_471 ,
V_556 -> V_550 . V_473 ,
! F_19 ( V_561 , & V_556 -> V_550 . V_135 ) ,
V_557 ) ;
}
if ( F_19 ( V_562 , & V_4 -> type ) &&
F_19 ( V_559 , & V_556 -> V_426 . V_135 ) ) {
V_557 = V_556 -> V_426 . V_560 ? 1000000 / V_556 -> V_426 . V_560 : 0 ;
F_224 ( V_2 , V_556 -> V_426 . V_471 ,
V_556 -> V_426 . V_473 ,
! F_19 ( V_561 , & V_556 -> V_426 . V_135 ) ,
V_557 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_420 ; cos ++ ) {
F_4 ( V_17 , L_85 ,
V_4 -> V_417 [ cos ] , cos ) ;
F_4 ( V_17 , L_86 , V_556 -> V_563 [ cos ] ) ;
F_225 ( V_2 , V_556 -> V_563 [ cos ] , V_4 -> V_417 [ cos ] ) ;
}
V_4 -> V_407 ( V_2 , V_4 , V_564 ) ;
F_226 () ;
F_190 () ;
return 0 ;
}
static inline int F_227 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_423 * V_106 =
(struct V_423 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
int V_566 = V_567 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
F_221 ( V_2 , V_401 , V_106 ) ;
return F_102 ( V_2 , V_566 , V_4 -> V_417 [ V_418 ] ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_197 ) ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_423 * V_106 =
(struct V_423 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
int V_566 = V_567 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
F_221 ( V_2 , V_401 , V_106 ) ;
F_216 ( V_2 , V_401 , V_106 ) ;
return F_102 ( V_2 , V_566 , V_4 -> V_417 [ V_418 ] ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_197 ) ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_553 * V_106 =
(struct V_553 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
int V_566 = V_568 ;
struct V_569 * V_570 =
& V_401 -> V_401 . V_554 ;
T_6 V_571 = V_570 -> V_571 ;
if ( V_571 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_92 , V_571 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_88 ,
V_570 -> V_547 . cos ,
V_570 -> V_547 . V_445 ) ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
F_222 ( V_2 , V_401 , V_106 ) ;
F_4 ( V_17 , L_89 ,
V_4 -> V_417 [ V_571 ] , V_106 -> V_548 . V_91 ,
V_106 -> V_548 . V_444 , V_106 -> V_548 . cos ) ;
return F_102 ( V_2 , V_566 , V_4 -> V_417 [ V_571 ] ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_197 ) ;
}
static void F_230 ( struct V_1 * V_2 ,
struct V_402 * V_411 ,
struct V_572 * V_401 ,
struct V_573 * V_60 )
{
V_60 -> V_91 = V_411 -> V_92 ;
V_60 -> V_93 = V_411 -> V_93 ;
V_60 -> V_455 = F_74 ( V_401 -> V_574 ) ;
V_60 -> V_519 =
F_19 ( V_575 , & V_401 -> V_576 ) ;
V_60 -> V_577 =
F_19 ( V_578 ,
& V_401 -> V_576 ) ;
V_60 -> V_521 =
F_19 ( V_579 , & V_401 -> V_576 ) ;
V_60 -> V_580 =
F_19 ( V_581 ,
& V_401 -> V_576 ) ;
V_60 -> V_582 =
F_19 ( V_583 , & V_401 -> V_576 ) ;
V_60 -> V_584 =
F_19 ( V_585 , & V_401 -> V_576 ) ;
V_60 -> V_442 =
F_19 ( V_586 , & V_401 -> V_576 ) ;
V_60 -> V_587 =
F_19 ( V_588 , & V_401 -> V_576 ) ;
V_60 -> V_589 =
F_19 ( V_590 , & V_401 -> V_576 ) ;
V_60 -> V_591 =
F_19 ( V_592 ,
& V_401 -> V_576 ) ;
V_60 -> V_593 =
F_19 ( V_594 ,
& V_401 -> V_576 ) ;
V_60 -> V_541 =
F_19 ( V_595 , & V_401 -> V_576 ) ;
V_60 -> V_543 = F_74 ( V_401 -> V_544 ) ;
V_60 -> V_545 = F_74 ( V_401 -> V_546 ) ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_573 * V_106 =
(struct V_573 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
struct V_572 * V_596 =
& V_401 -> V_401 . V_597 ;
T_6 V_571 = V_596 -> V_571 ;
if ( V_571 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_92 , V_571 ) ;
return - V_62 ;
}
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
F_230 ( V_2 , V_4 , V_596 , V_106 ) ;
return F_102 ( V_2 , V_598 ,
V_4 -> V_417 [ V_571 ] , F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_197 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_572 * V_597 = & V_401 -> V_401 . V_597 ;
memset ( V_597 , 0 , sizeof( * V_597 ) ) ;
F_86 ( V_588 , & V_597 -> V_576 ) ;
return F_231 ( V_2 , V_401 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_572 * V_597 = & V_401 -> V_401 . V_597 ;
memset ( V_597 , 0 , sizeof( * V_597 ) ) ;
F_86 ( V_586 , & V_597 -> V_576 ) ;
F_86 ( V_588 , & V_597 -> V_576 ) ;
return F_231 ( V_2 , V_401 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
return - 1 ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
return F_102 ( V_2 , V_599 ,
V_4 -> V_417 [ V_418 ] , 0 , V_4 -> V_92 ,
V_197 ) ;
}
static inline int F_236 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
T_6 V_600 = V_401 -> V_401 . V_601 . V_571 ;
if ( V_600 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_92 , V_600 ) ;
return - V_62 ;
}
return F_102 ( V_2 , V_602 ,
V_4 -> V_417 [ V_600 ] , 0 , 0 , V_603 ) ;
}
static inline int F_237 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
T_6 V_571 = V_401 -> V_401 . V_604 . V_571 ;
if ( V_571 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_92 , V_571 ) ;
return - V_62 ;
}
return F_102 ( V_2 , V_605 ,
V_4 -> V_417 [ V_571 ] , 0 , 0 , V_197 ) ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
return F_102 ( V_2 , V_606 ,
V_4 -> V_417 [ V_418 ] , 0 , 0 ,
V_197 ) ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_107 ) {
case V_564 :
return F_223 ( V_2 , V_401 ) ;
case V_607 :
return F_229 ( V_2 , V_401 ) ;
case V_414 :
return F_232 ( V_2 , V_401 ) ;
case V_413 :
return F_233 ( V_2 , V_401 ) ;
case V_415 :
return F_231 ( V_2 , V_401 ) ;
case V_608 :
return F_234 ( V_2 , V_401 ) ;
case V_609 :
return F_235 ( V_2 , V_401 ) ;
case V_610 :
return F_236 ( V_2 , V_401 ) ;
case V_611 :
return F_237 ( V_2 , V_401 ) ;
case V_612 :
return F_238 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_107 ) ;
return - V_62 ;
}
}
static int F_240 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_107 ) {
case V_613 :
return F_227 ( V_2 , V_401 ) ;
case V_564 :
case V_607 :
case V_414 :
case V_413 :
case V_415 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
return F_239 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_107 ) ;
return - V_62 ;
}
}
static int F_241 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_107 ) {
case V_613 :
return F_228 ( V_2 , V_401 ) ;
case V_564 :
case V_607 :
case V_414 :
case V_413 :
case V_415 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
return F_239 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_107 ) ;
return - V_62 ;
}
}
static int F_242 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
struct V_400 * V_401 )
{
enum V_614 V_33 = V_4 -> V_33 , V_409 = V_410 ;
enum V_412 V_107 = V_401 -> V_107 ;
struct V_572 * V_596 =
& V_401 -> V_401 . V_597 ;
T_6 V_419 = V_4 -> V_421 ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) ) {
V_4 -> V_405 = 0 ;
V_4 -> V_409 = V_410 ;
}
if ( V_4 -> V_405 ) {
F_39 ( L_90 ,
V_4 -> V_405 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_615 :
if ( V_107 == V_564 )
V_409 = V_616 ;
break;
case V_616 :
if ( V_107 == V_613 ) {
if ( F_19 ( V_443 ,
& V_401 -> V_401 . V_425 . V_135 ) )
V_409 = V_617 ;
else
V_409 = V_618 ;
}
break;
case V_617 :
if ( V_107 == V_414 )
V_409 = V_618 ;
else if ( ( V_107 == V_612 ) ||
( V_107 == V_608 ) )
V_409 = V_617 ;
else if ( V_107 == V_607 ) {
V_409 = V_619 ;
V_419 = 1 ;
}
else if ( V_107 == V_609 )
V_409 = V_620 ;
else if ( V_107 == V_415 ) {
if ( F_19 ( V_588 ,
& V_596 -> V_576 ) &&
! F_19 ( V_586 ,
& V_596 -> V_576 ) )
V_409 = V_618 ;
else
V_409 = V_617 ;
}
break;
case V_619 :
if ( V_107 == V_611 )
V_409 = V_621 ;
else if ( V_107 == V_607 ) {
V_409 = V_619 ;
V_419 = V_4 -> V_421 + 1 ;
}
else if ( ( V_107 == V_612 ) ||
( V_107 == V_608 ) )
V_409 = V_619 ;
else if ( V_107 == V_415 ) {
if ( F_19 ( V_588 ,
& V_596 -> V_576 ) &&
! F_19 ( V_586 ,
& V_596 -> V_576 ) )
V_409 = V_618 ;
else
V_409 = V_619 ;
}
break;
case V_621 :
if ( V_107 == V_610 ) {
V_419 = V_4 -> V_421 - 1 ;
if ( V_419 == 0 )
V_409 = V_617 ;
else
V_409 = V_619 ;
}
break;
case V_618 :
if ( V_107 == V_413 )
V_409 = V_617 ;
else if ( ( V_107 == V_612 ) ||
( V_107 == V_608 ) )
V_409 = V_618 ;
else if ( V_107 == V_609 )
V_409 = V_620 ;
else if ( V_107 == V_415 ) {
if ( F_19 ( V_588 ,
& V_596 -> V_576 ) &&
F_19 ( V_586 ,
& V_596 -> V_576 ) ) {
if ( V_4 -> V_421 == 0 )
V_409 = V_617 ;
else
V_409 = V_619 ;
} else
V_409 = V_618 ;
}
break;
case V_620 :
if ( V_107 == V_611 )
V_409 = V_622 ;
break;
case V_622 :
if ( V_107 == V_610 )
V_409 = V_615 ;
break;
default:
F_39 ( L_91 , V_33 ) ;
}
if ( V_409 != V_410 ) {
F_4 ( V_17 , L_92 ,
V_33 , V_107 , V_409 ) ;
V_4 -> V_409 = V_409 ;
V_4 -> V_419 = V_419 ;
return 0 ;
}
F_4 ( V_17 , L_93 , V_33 , V_107 ) ;
return - V_62 ;
}
void F_243 ( struct V_1 * V_2 ,
struct V_402 * V_411 ,
T_6 V_92 , T_7 * V_417 , T_6 V_623 , T_6 V_93 ,
void * V_106 ,
T_9 V_196 , unsigned long type )
{
memset ( V_411 , 0 , sizeof( * V_411 ) ) ;
F_244 ( V_624 < V_623 ) ;
memcpy ( V_411 -> V_417 , V_417 , sizeof( V_411 -> V_417 [ 0 ] ) * V_623 ) ;
V_411 -> V_420 = V_623 ;
V_411 -> V_92 = V_92 ;
V_411 -> V_93 = V_93 ;
V_411 -> V_106 = V_106 ;
V_411 -> V_196 = V_196 ;
V_411 -> type = type ;
V_411 -> V_409 = V_410 ;
if ( F_112 ( V_2 ) )
V_411 -> V_408 = F_240 ;
else
V_411 -> V_408 = F_241 ;
V_411 -> V_406 = F_242 ;
V_411 -> V_407 = F_213 ;
V_411 -> V_175 = F_212 ;
V_411 -> V_192 = F_211 ;
}
int F_245 ( struct V_1 * V_2 ,
struct V_402 * V_411 )
{
switch ( V_411 -> V_33 ) {
case V_617 :
case V_619 :
return V_625 ;
case V_615 :
case V_616 :
case V_621 :
case V_618 :
case V_620 :
case V_622 :
case V_626 :
return V_627 ;
default:
return - V_62 ;
}
}
enum V_628 F_246 ( struct V_1 * V_2 ,
struct V_629 * V_4 )
{
if ( V_4 -> V_405 )
return V_630 ;
F_247 () ;
return V_4 -> V_33 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_629 * V_4 ,
enum V_631 V_107 )
{
return F_34 ( V_2 , V_107 , & V_4 -> V_405 ) ;
}
static inline int F_249 ( struct V_1 * V_2 ,
struct V_629 * V_4 ,
enum V_631 V_107 )
{
unsigned long V_416 = V_4 -> V_405 ;
if ( ! F_214 ( V_107 , & V_416 ) ) {
F_39 ( L_94 ,
V_107 , F_250 ( V_2 ) , V_4 -> V_33 ,
V_416 , V_4 -> V_409 ) ;
return - V_62 ;
}
F_4 ( V_17 ,
L_95 ,
V_107 , F_250 ( V_2 ) , V_4 -> V_409 ) ;
V_4 -> V_33 = V_4 -> V_409 ;
V_4 -> V_409 = V_630 ;
F_215 () ;
F_30 ( V_107 , & V_4 -> V_405 ) ;
F_31 () ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_629 * V_4 ,
enum V_631 V_107 )
{
int V_22 = F_249 ( V_2 , V_4 , V_107 ) ;
return V_22 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_629 * V_4 ,
struct V_632 * V_401 )
{
enum V_628 V_33 = V_4 -> V_33 , V_409 = V_630 ;
enum V_631 V_107 = V_401 -> V_107 ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) ) {
V_4 -> V_405 = 0 ;
V_4 -> V_409 = V_630 ;
}
if ( V_4 -> V_405 )
return - V_37 ;
switch ( V_33 ) {
case V_633 :
if ( V_107 == V_634 )
V_409 = V_635 ;
break;
case V_635 :
if ( V_107 == V_636 )
V_409 = V_637 ;
else if ( V_107 == V_638 )
V_409 = V_633 ;
break;
case V_637 :
if ( V_107 == V_639 )
V_409 = V_635 ;
else if ( ( V_107 == V_640 ) &&
( ! F_19 ( V_639 , & V_4 -> V_405 ) ) )
V_409 = V_637 ;
else if ( ( V_107 == V_641 ) &&
( ! F_19 ( V_639 , & V_4 -> V_405 ) ) )
V_409 = V_637 ;
else if ( ( V_107 == V_642 ) &&
( ! F_19 ( V_639 , & V_4 -> V_405 ) ) )
V_409 = V_637 ;
else if ( V_107 == V_643 )
V_409 = V_644 ;
break;
case V_644 :
if ( ( V_107 == V_642 ) &&
( ! F_19 ( V_639 , & V_4 -> V_405 ) ) )
V_409 = V_644 ;
else if ( V_107 == V_645 )
V_409 = V_637 ;
break;
default:
F_39 ( L_96 , V_33 ) ;
}
if ( V_409 != V_630 ) {
F_4 ( V_17 , L_97 ,
V_33 , V_107 , V_409 ) ;
V_4 -> V_409 = V_409 ;
return 0 ;
}
F_4 ( V_17 , L_98 ,
V_33 , V_107 ) ;
return - V_62 ;
}
static inline int F_253 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
return V_647 -> V_648 ( V_2 ) ;
}
static inline int F_254 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
int V_22 = V_647 -> V_649 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_253 ( V_2 , V_647 ) ;
}
static inline int F_255 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
int V_22 = V_647 -> V_650 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_254 ( V_2 , V_647 ) ;
}
static inline int F_256 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
int V_22 = V_647 -> V_651 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_254 ( V_2 , V_647 ) ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
T_7 V_652 = V_401 -> V_401 . V_653 . V_654 ;
struct V_629 * V_4 = V_401 -> V_655 ;
const struct V_646 * V_647 = V_4 -> V_647 ;
int V_22 = 0 ;
F_4 ( V_17 , L_99 ,
F_258 ( V_2 ) , V_652 ) ;
V_22 = V_647 -> V_656 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_647 -> V_657 ( V_2 ) ;
if ( V_22 ) {
F_39 ( L_100 ) ;
goto V_658;
}
switch ( V_652 ) {
case V_659 :
V_22 = F_255 ( V_2 , V_647 ) ;
if ( V_22 )
goto V_658;
break;
case V_660 :
V_22 = F_256 ( V_2 , V_647 ) ;
if ( V_22 )
goto V_658;
break;
case V_661 :
V_22 = F_254 ( V_2 , V_647 ) ;
if ( V_22 )
goto V_658;
break;
case V_662 :
V_22 = F_253 ( V_2 , V_647 ) ;
if ( V_22 )
goto V_658;
break;
default:
F_39 ( L_101 , V_652 ) ;
V_22 = - V_62 ;
}
V_658:
V_647 -> V_663 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_407 ( V_2 , V_4 , V_634 ) ;
return V_22 ;
}
static inline void F_259 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
V_647 -> V_664 ( V_2 ) ;
}
static inline void F_260 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
V_647 -> V_665 ( V_2 ) ;
F_259 ( V_2 , V_647 ) ;
}
static inline void F_261 ( struct V_1 * V_2 ,
const struct V_646 * V_647 )
{
F_260 ( V_2 , V_647 ) ;
V_647 -> V_666 ( V_2 ) ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
T_7 V_667 = V_401 -> V_401 . V_668 . V_667 ;
struct V_629 * V_4 = V_401 -> V_655 ;
const struct V_646 * V_647 = V_4 -> V_647 ;
F_4 ( V_17 , L_102 , F_258 ( V_2 ) ,
V_667 ) ;
switch ( V_667 ) {
case V_669 :
F_261 ( V_2 , V_647 ) ;
break;
case V_670 :
F_260 ( V_2 , V_647 ) ;
break;
case V_671 :
F_259 ( V_2 , V_647 ) ;
break;
default:
F_39 ( L_103 ,
V_667 ) ;
break;
}
V_4 -> V_407 ( V_2 , V_4 , V_638 ) ;
return 0 ;
}
static inline int F_263 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
struct V_672 * V_106 =
(struct V_672 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
struct V_673 * V_674 = & V_401 -> V_401 . V_675 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_676 = ( T_6 ) V_674 -> V_677 ;
V_106 -> V_678 = F_74 ( V_674 -> V_678 ) ;
V_106 -> V_679 = F_264 ( V_2 ) ;
V_106 -> V_680 = V_674 -> V_680 ;
V_106 -> V_681 = V_674 -> V_681 ;
V_106 -> V_682 = V_674 -> V_682 ;
return F_102 ( V_2 , V_683 , 0 ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_603 ) ;
}
static inline int F_265 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
struct V_684 * V_106 =
(struct V_684 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
struct V_685 * V_686 =
& V_401 -> V_401 . V_687 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_688 = 1 ;
V_106 -> V_689 = V_686 -> V_690 ;
V_106 -> V_100 = V_691 ;
return F_102 ( V_2 , V_692 , 0 ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_603 ) ;
}
static inline int F_266 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
struct V_684 * V_106 =
(struct V_684 * ) V_4 -> V_693 ;
T_9 V_565 = V_4 -> V_694 ;
struct V_695 * V_696 =
& V_401 -> V_401 . V_697 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_698 = 1 ;
V_106 -> V_699 = F_74 ( V_696 -> V_699 ) ;
V_106 -> V_700 = 1 ;
V_106 -> V_701 =
F_74 ( V_696 -> V_701 ) ;
V_106 -> V_702 = 1 ;
V_106 -> V_703 = V_696 -> V_703 ;
V_106 -> V_100 = V_704 ;
F_4 ( V_17 ,
L_104 ,
V_106 -> V_699 ,
V_106 -> V_701 , V_106 -> V_703 ) ;
return F_102 ( V_2 , V_692 , 0 ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_603 ) ;
}
static
inline int F_267 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
struct V_705 * V_106 =
(struct V_705 * ) V_4 -> V_693 ;
struct V_706 * V_707 =
& V_401 -> V_401 . V_708 ;
T_12 * V_709 = ( T_12 * ) V_106 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_710 = F_74 ( V_707 -> V_710 ) ;
V_106 -> V_711 = V_707 -> V_711 ;
V_106 -> V_712 = V_707 -> V_712 ;
V_106 -> V_713 = V_707 -> V_713 ;
V_106 -> V_100 = V_707 -> V_712 ;
F_4 ( V_17 , L_105 ,
V_106 -> V_712 , V_106 -> V_710 ,
V_106 -> V_711 , V_106 -> V_713 ) ;
return F_102 ( V_2 , V_714 , 0 ,
F_103 ( * V_709 ) , F_104 ( * V_709 ) ,
V_603 ) ;
}
static inline int F_268 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
return F_102 ( V_2 , V_715 , 0 , 0 , 0 ,
V_603 ) ;
}
static inline int F_269 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
return F_102 ( V_2 , V_716 , 0 , 0 , 0 ,
V_603 ) ;
}
static inline int F_270 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
struct V_717 * V_106 =
(struct V_717 * ) V_4 -> V_106 ;
T_9 V_565 = V_4 -> V_196 ;
struct V_718 * V_719 =
& V_401 -> V_401 . V_720 ;
int V_284 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_721 = V_719 -> V_721 ;
V_106 -> V_722 = V_719 -> V_722 ;
V_106 -> V_723 = V_719 -> V_723 ;
for ( V_284 = 0 ; V_284 < F_271 ( V_106 -> V_724 ) ; V_284 ++ )
V_106 -> V_724 [ V_284 ] =
V_719 -> V_724 [ V_284 ] ;
return F_102 ( V_2 , V_725 , 0 ,
F_103 ( V_565 ) ,
F_104 ( V_565 ) , V_603 ) ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
switch ( V_401 -> V_107 ) {
case V_634 :
return F_257 ( V_2 , V_401 ) ;
case V_636 :
return F_263 ( V_2 , V_401 ) ;
case V_639 :
return F_268 ( V_2 , V_401 ) ;
case V_638 :
return F_262 ( V_2 , V_401 ) ;
case V_640 :
return F_266 ( V_2 , V_401 ) ;
case V_641 :
return F_267 ( V_2 , V_401 ) ;
case V_643 :
return F_269 ( V_2 , V_401 ) ;
case V_645 :
return F_270 ( V_2 , V_401 ) ;
case V_642 :
return F_265 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_107 ) ;
return - V_62 ;
}
}
void F_273 ( struct V_1 * V_2 ,
struct V_629 * V_411 ,
void * V_106 , T_9 V_196 ,
void * V_693 , T_9 V_694 ,
struct V_646 * V_726 )
{
memset ( V_411 , 0 , sizeof( * V_411 ) ) ;
F_274 ( & V_411 -> V_727 ) ;
V_411 -> V_106 = V_106 ;
V_411 -> V_196 = V_196 ;
V_411 -> V_693 = V_693 ;
V_411 -> V_694 = V_694 ;
V_411 -> V_408 = F_272 ;
V_411 -> V_406 = F_252 ;
V_411 -> V_407 = F_251 ;
V_411 -> V_175 = F_248 ;
V_411 -> V_647 = V_726 ;
}
int F_275 ( struct V_1 * V_2 ,
struct V_632 * V_401 )
{
struct V_629 * V_4 = V_401 -> V_655 ;
int V_22 , V_20 = 300 ;
enum V_631 V_107 = V_401 -> V_107 ;
unsigned long * V_405 = & V_4 -> V_405 ;
F_276 ( & V_4 -> V_727 ) ;
V_22 = V_4 -> V_406 ( V_2 , V_4 , V_401 ) ;
if ( ( V_22 == - V_37 ) &&
( F_19 ( V_728 , & V_401 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_277 ( & V_4 -> V_727 ) ;
F_278 ( 10 ) ;
F_276 ( & V_4 -> V_727 ) ;
V_22 = V_4 -> V_406 ( V_2 , V_4 , V_401 ) ;
}
if ( V_22 == - V_37 ) {
F_277 ( & V_4 -> V_727 ) ;
F_39 ( L_106 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_277 ( & V_4 -> V_727 ) ;
return V_22 ;
}
F_33 ( V_107 , V_405 ) ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) ) {
F_249 ( V_2 , V_4 , V_107 ) ;
F_277 ( & V_4 -> V_727 ) ;
} else {
V_22 = V_4 -> V_408 ( V_2 , V_401 ) ;
F_277 ( & V_4 -> V_727 ) ;
if ( V_22 ) {
V_4 -> V_409 = V_630 ;
F_30 ( V_107 , V_405 ) ;
F_31 () ;
return V_22 ;
}
if ( F_19 ( V_201 , & V_401 -> V_25 ) ) {
V_22 = V_4 -> V_175 ( V_2 , V_4 , V_107 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_19 ( V_107 , V_405 ) ;
}
