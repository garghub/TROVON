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
V_53 = V_50 + V_54 * F_53 ( V_58 , sizeof( V_59 ) ) ;
F_4 ( V_17 , L_9 ,
V_54 , V_53 , V_52 -> V_56 . V_57 . V_57 ) ;
}
}
return V_54 * V_58 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_10 , V_61 -> V_57 . V_57 ) ;
if ( ! F_55 ( V_61 -> V_57 . V_57 ) )
return - V_62 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_61 -> V_57 . V_57 , V_52 -> V_56 . V_57 . V_57 , V_58 ) )
return - V_63 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_11 , V_61 -> V_64 . V_64 ) ;
F_9 (pos, &o->head, link)
if ( V_61 -> V_64 . V_64 == V_52 -> V_56 . V_64 . V_64 )
return - V_63 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_12 ,
V_61 -> V_65 . V_57 , V_61 -> V_65 . V_64 ) ;
F_9 (pos, &o->head, link)
if ( ( V_61 -> V_65 . V_64 == V_52 -> V_56 . V_65 . V_64 ) &&
( ! memcmp ( V_61 -> V_65 . V_57 , V_52 -> V_56 . V_65 . V_57 ,
V_58 ) ) )
return - V_63 ;
return 0 ;
}
static struct V_51 *
F_58 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_13 , V_61 -> V_57 . V_57 ) ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_61 -> V_57 . V_57 , V_52 -> V_56 . V_57 . V_57 , V_58 ) )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_59 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_14 , V_61 -> V_64 . V_64 ) ;
F_9 (pos, &o->head, link)
if ( V_61 -> V_64 . V_64 == V_52 -> V_56 . V_64 . V_64 )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_60 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_15 ,
V_61 -> V_65 . V_57 , V_61 -> V_65 . V_64 ) ;
F_9 (pos, &o->head, link)
if ( ( V_61 -> V_65 . V_64 == V_52 -> V_56 . V_65 . V_64 ) &&
( ! memcmp ( V_61 -> V_65 . V_57 , V_52 -> V_56 . V_65 . V_57 ,
V_58 ) ) )
return V_52 ;
return NULL ;
}
static bool F_61 ( struct V_1 * V_2 ,
struct V_39 * V_66 ,
struct V_39 * V_67 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
int V_22 ;
V_52 = V_66 -> V_68 ( V_2 , V_66 , V_61 ) ;
V_22 = V_67 -> V_69 ( V_2 , V_67 , V_61 ) ;
if ( V_22 || ! V_52 )
return false ;
return true ;
}
static bool F_62 (
struct V_1 * V_2 ,
struct V_39 * V_66 ,
struct V_39 * V_67 ,
union V_60 * V_61 )
{
return false ;
}
static inline T_6 F_63 ( struct V_39 * V_4 )
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
void F_64 ( struct V_1 * V_2 ,
bool V_77 , unsigned char * V_78 , int V_79 )
{
V_59 V_80 [ 2 ] ;
V_59 V_81 = F_65 ( V_2 ) ? V_82 :
V_83 ;
if ( ! F_66 ( V_2 ) && ! F_67 ( V_2 ) )
return;
if ( V_79 > V_84 )
return;
F_4 ( V_17 , L_16 ,
( V_77 ? L_17 : L_18 ) , V_79 ) ;
if ( V_77 ) {
V_81 += 8 * V_79 ;
V_80 [ 0 ] = ( ( V_78 [ 2 ] << 24 ) | ( V_78 [ 3 ] << 16 ) |
( V_78 [ 4 ] << 8 ) | V_78 [ 5 ] ) ;
V_80 [ 1 ] = ( ( V_78 [ 0 ] << 8 ) | V_78 [ 1 ] ) ;
F_68 ( V_2 , V_81 , V_80 , 2 ) ;
}
F_69 ( V_2 , ( F_65 ( V_2 ) ? V_85 :
V_86 ) + 4 * V_79 , V_77 ) ;
}
static inline void F_70 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_77 , int V_87 ,
struct V_88 * V_89 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_89 -> V_90 = V_38 -> V_91 ;
V_89 -> V_92 = V_38 -> V_92 ;
V_89 -> V_93 |=
F_63 ( V_4 ) ;
if ( V_77 )
V_89 -> V_93 |= V_94 ;
V_89 -> V_93 |=
( V_87 << V_95 ) ;
}
static inline void F_71 ( V_59 V_96 , int type ,
struct V_97 * V_89 , int V_98 )
{
V_89 -> V_99 = F_72 ( ( V_96 & V_100 ) |
( type << V_101 ) ) ;
V_89 -> V_98 = ( T_6 ) V_98 ;
}
static void F_73 ( struct V_1 * V_2 ,
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
if ( F_19 ( V_114 , V_112 ) )
F_64 ( V_2 , V_77 , V_57 ,
V_115 ) ;
else if ( F_19 ( V_116 , V_112 ) )
F_64 ( V_2 , V_77 , V_57 ,
V_117 ) ;
}
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_70 ( V_2 , V_4 , V_77 , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_4 ( V_17 , L_19 ,
( V_77 ? L_20 : L_21 ) , V_57 , V_38 -> V_91 ) ;
F_74 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_70 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_74 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
}
F_71 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static inline void F_75 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 ,
struct V_124 * V_89 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_89 -> V_126 = 1 ;
V_89 -> V_40 = ( T_6 ) V_103 ;
V_89 -> V_90 = F_76 ( 0xff ) ;
V_89 -> V_99 = F_72 ( ( V_125 -> V_96 & V_100 ) |
( type << V_101 ) ) ;
}
static inline void F_77 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_77 , int V_87 , T_6 * V_57 ,
T_7 V_127 , struct V_128 * V_129 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_59 V_130 = ( 1 << V_125 -> V_91 ) ;
V_129 -> V_131 = F_72 ( V_130 ) ;
V_129 -> V_132 = V_125 -> V_92 ;
V_129 -> V_127 = F_76 ( V_127 ) ;
if ( V_77 ) {
F_78 ( V_129 -> V_133 , V_134 ,
V_135 ) ;
F_78 ( V_129 -> V_133 ,
V_136 , V_87 ) ;
F_74 ( & V_129 -> V_137 ,
& V_129 -> V_138 ,
& V_129 -> V_139 , V_57 ) ;
} else
F_78 ( V_129 -> V_133 , V_134 ,
V_140 ) ;
}
static inline void F_79 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 , bool V_77 ,
T_6 * V_57 , T_7 V_127 , int V_87 , struct V_141 * V_142 )
{
struct V_128 * V_129 = & V_142 -> V_143 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_75 ( V_2 , V_4 , type , V_103 ,
& V_142 -> V_89 ) ;
F_77 ( V_2 , V_4 , V_77 , V_87 , V_57 , V_127 ,
V_129 ) ;
F_4 ( V_17 , L_22 ,
( V_77 ? L_23 : L_24 ) ,
V_57 , V_38 -> V_91 , V_103 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
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
F_79 ( V_2 , V_4 , V_38 -> V_33 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_57 . V_57 , 0 ,
V_144 , V_142 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_102 ,
int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_104 * V_61 =
(struct V_104 * ) ( V_38 -> V_105 ) ;
int V_98 = V_102 + 1 ;
union V_108 * V_109 = & V_61 -> V_110 [ V_102 ] ;
enum V_145 V_106 = V_19 -> V_107 . V_65 . V_106 ;
bool V_77 = ( V_106 == V_111 ) ? true : false ;
T_7 V_64 = V_19 -> V_107 . V_65 . V_56 . V_64 . V_64 ;
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_70 ( V_2 , V_4 , V_77 , V_146 ,
& V_109 -> V_64 . V_119 ) ;
F_4 ( V_17 , L_25 , ( V_77 ? L_20 : L_21 ) ,
V_64 ) ;
V_109 -> V_64 . V_64 = F_76 ( V_64 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_70 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_146 ,
& V_109 -> V_64 . V_119 ) ;
V_109 -> V_64 . V_64 = F_76 ( V_64 ) ;
}
F_71 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_102 , int V_103 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_104 * V_61 =
(struct V_104 * ) ( V_38 -> V_105 ) ;
int V_98 = V_102 + 1 ;
union V_108 * V_109 = & V_61 -> V_110 [ V_102 ] ;
enum V_145 V_106 = V_19 -> V_107 . V_65 . V_106 ;
bool V_77 = ( V_106 == V_111 ) ? true : false ;
T_7 V_64 = V_19 -> V_107 . V_65 . V_56 . V_65 . V_64 ;
T_6 * V_57 = V_19 -> V_107 . V_65 . V_56 . V_65 . V_57 ;
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_70 ( V_2 , V_4 , V_77 , V_147 ,
& V_109 -> V_148 . V_119 ) ;
V_109 -> V_148 . V_64 = F_76 ( V_64 ) ;
F_74 ( & V_109 -> V_148 . V_120 ,
& V_109 -> V_148 . V_121 ,
& V_109 -> V_148 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_70 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_147 ,
& V_109 -> V_148 . V_119 ) ;
V_109 -> V_148 . V_64 = F_76 ( V_64 ) ;
F_74 ( & V_109 -> V_148 . V_120 ,
& V_109 -> V_148 . V_121 ,
& V_109 -> V_148 . V_122 , V_57 ) ;
}
F_71 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
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
F_79 ( V_2 , V_4 , V_149 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_57 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_64 ,
V_150 , V_142 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_151 * V_152 ,
struct V_51 * * V_153 )
{
struct V_51 * V_52 ;
struct V_39 * V_4 = V_152 -> V_154 ;
if ( F_14 ( & V_4 -> V_155 ) ) {
* V_153 = NULL ;
return 0 ;
}
if ( * V_153 == NULL )
* V_153 = F_15 ( & V_4 -> V_155 ,
struct V_51 ,
V_24 ) ;
else
* V_153 = F_85 ( * V_153 , V_24 ) ;
V_52 = * V_153 ;
if ( F_86 ( & V_52 -> V_24 , & V_4 -> V_155 ) )
* V_153 = NULL ;
memcpy ( & V_152 -> V_156 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_152 -> V_156 . V_106 = V_111 ;
V_152 -> V_156 . V_112 = V_52 -> V_112 ;
F_87 ( V_157 , & V_152 -> V_25 ) ;
return F_88 ( V_2 , V_152 ) ;
}
static struct V_18 * F_89 (
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
static struct V_18 * F_90 (
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
static struct V_18 * F_91 (
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
static inline int F_92 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_161 -> V_65 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_69 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_26 ) ;
return V_22 ;
}
if ( V_162 -> V_11 ( V_162 , V_19 ) ) {
F_4 ( V_17 , L_27 ) ;
return - V_63 ;
}
if ( ! ( F_19 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_164 ( V_4 ) ) )
return - V_62 ;
return 0 ;
}
static inline int F_93 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_161 -> V_65 ;
struct V_51 * V_52 ;
struct V_3 * V_162 = & V_4 -> V_12 ;
struct V_18 V_165 ;
V_52 = V_4 -> V_68 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( ! V_52 ) {
F_4 ( V_17 , L_28 ) ;
return - V_63 ;
}
memcpy ( & V_165 , V_19 , sizeof( V_165 ) ) ;
V_165 . V_107 . V_65 . V_106 = V_113 ;
if ( V_162 -> V_11 ( V_162 , & V_165 ) ) {
F_39 ( L_29 ) ;
return - V_62 ;
}
if ( V_162 -> V_11 ( V_162 , V_19 ) ) {
F_4 ( V_17 , L_30 ) ;
return - V_63 ;
}
if ( ! ( F_19 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_166 ( V_4 ) ) ) {
F_39 ( L_31 ) ;
return - V_62 ;
}
return 0 ;
}
static inline int F_94 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
struct V_39 * V_66 = & V_161 -> V_65 ;
struct V_39 * V_167 = V_19 -> V_107 . V_65 . V_123 ;
struct V_18 V_165 ;
struct V_3 * V_168 = & V_66 -> V_12 ;
struct V_3 * V_169 = & V_167 -> V_12 ;
if ( ! V_66 -> V_170 ( V_2 , V_66 , V_167 ,
& V_19 -> V_107 . V_65 . V_56 ) ) {
F_4 ( V_17 , L_32 ) ;
return - V_62 ;
}
memcpy ( & V_165 , V_19 , sizeof( V_165 ) ) ;
V_165 . V_107 . V_65 . V_106 = V_171 ;
if ( V_168 -> V_11 ( V_168 , & V_165 ) ) {
F_39 ( L_33 ) ;
return - V_62 ;
}
if ( V_168 -> V_11 ( V_168 , V_19 ) ) {
F_4 ( V_17 , L_29 ) ;
return - V_63 ;
}
V_165 . V_107 . V_65 . V_106 = V_111 ;
if ( V_169 -> V_11 ( V_169 , & V_165 ) ) {
F_39 ( L_34 ) ;
return - V_62 ;
}
if ( ! ( F_19 ( V_172 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_167 -> V_164 ( V_167 ) ) )
return - V_62 ;
if ( ! ( F_19 ( V_163 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_66 -> V_166 ( V_66 ) ) ) {
V_167 -> V_166 ( V_167 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
return F_92 ( V_2 , V_161 , V_19 ) ;
case V_171 :
return F_93 ( V_2 , V_161 , V_19 ) ;
case V_113 :
return F_94 ( V_2 , V_161 , V_19 ) ;
default:
return - V_62 ;
}
}
static int F_96 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_19 ( V_163 ,
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
static int F_97 ( struct V_1 * V_2 ,
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
F_38 ( 1000 , 2000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_174 * V_175 ,
unsigned long * V_25 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 ;
F_17 ( V_2 , & V_4 -> V_12 ) ;
V_125 -> V_176 ( V_125 ) ;
if ( V_175 -> V_177 . error )
return - V_62 ;
if ( F_19 ( V_178 , V_25 ) ) {
V_22 = F_18 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
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
if ( ! F_19 ( V_163 ,
& V_52 -> V_107 . V_65 . V_112 ) ) {
if ( ( V_179 . V_107 . V_65 . V_106 ==
V_111 ) && ! V_4 -> V_166 ( V_4 ) ) {
F_39 ( L_35 ) ;
return - V_62 ;
} else if ( ! V_4 -> V_164 ( V_4 ) ) {
F_39 ( L_36 ) ;
return - V_62 ;
}
}
F_4 ( V_17 , L_37 ,
( V_19 -> V_107 . V_65 . V_106 == V_111 ) ?
L_17 : L_38 ) ;
F_16 ( & V_52 -> V_24 ) ;
F_5 ( V_2 , V_52 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_100 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_51 * * V_180 )
{
enum V_145 V_106 = V_19 -> V_107 . V_65 . V_106 ;
struct V_51 * V_181 ;
if ( ! V_21 &&
( ( V_106 == V_111 ) || ( V_106 == V_113 ) ) ) {
V_181 = F_26 ( sizeof( * V_181 ) , V_31 ) ;
if ( ! V_181 )
return - V_182 ;
if ( ! V_4 -> V_183 ( V_4 , & V_181 -> V_103 ) ) {
F_20 ( 1 ) ;
F_6 ( V_181 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_39 , V_181 -> V_103 ) ;
memcpy ( & V_181 -> V_56 , & V_19 -> V_107 . V_65 . V_56 ,
sizeof( V_181 -> V_56 ) ) ;
V_181 -> V_112 =
V_19 -> V_107 . V_65 . V_112 ;
} else
V_181 = V_4 -> V_68 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
* V_180 = V_181 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
union V_6 * V_161 ,
struct V_184 * V_185 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_161 -> V_65 , * V_186 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 , V_187 = 0 ;
bool V_21 = F_19 ( V_157 , V_25 ) ;
bool V_188 = F_19 ( V_28 , V_25 ) ;
struct V_51 * V_181 ;
enum V_145 V_106 ;
if ( ! V_188 ) {
F_20 ( V_125 -> V_189 ( V_125 ) ) ;
V_125 -> V_190 ( V_125 ) ;
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( V_106 == V_113 )
V_186 = V_19 -> V_107 . V_65 . V_123 ;
else
V_186 = V_4 ;
V_22 = F_100 ( V_2 , V_186 ,
V_19 , V_21 ,
& V_181 ) ;
if ( V_22 )
goto V_191;
F_20 ( ! V_181 ) ;
if ( ! V_21 &&
( ( V_106 == V_111 ) ||
( V_106 == V_113 ) ) )
F_102 ( & V_181 -> V_24 , & V_186 -> V_155 ) ;
V_4 -> V_192 ( V_2 , V_4 , V_19 , V_187 ,
V_181 -> V_103 ) ;
if ( V_106 == V_113 )
V_187 += 2 ;
else
V_187 ++ ;
}
V_22 = F_103 ( V_2 , V_4 -> V_193 , V_125 -> V_96 ,
F_104 ( V_125 -> V_194 ) ,
F_105 ( V_125 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
goto V_191;
}
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( ( V_106 == V_171 ) ||
( V_106 == V_113 ) ) {
V_181 = V_4 -> V_68 ( V_2 , V_4 ,
& V_19 -> V_107 . V_65 . V_56 ) ;
F_20 ( ! V_181 ) ;
V_4 -> V_196 ( V_4 , V_181 -> V_103 ) ;
F_16 ( & V_181 -> V_24 ) ;
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
V_181 = V_4 -> V_68 ( V_2 , V_186 ,
& V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_181 ) {
F_16 ( & V_181 -> V_24 ) ;
F_6 ( V_181 ) ;
}
}
}
return V_22 ;
}
static inline int F_106 (
struct V_1 * V_2 ,
struct V_151 * V_152 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_152 -> V_154 ;
bool V_21 = F_19 ( V_157 , & V_152 -> V_25 ) ;
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
int F_88 (
struct V_1 * V_2 ,
struct V_151 * V_152 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_152 -> V_154 ;
unsigned long * V_25 = & V_152 -> V_25 ;
bool V_197 = F_19 ( V_178 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_197 ) {
V_22 = F_106 ( V_2 , V_152 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_19 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_40 ) ;
V_38 -> V_176 ( V_38 ) ;
}
if ( V_197 || F_19 ( V_198 , V_25 ) ||
F_19 ( V_199 , V_25 ) ) {
V_22 = F_18 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_19 ( V_199 , & V_152 -> V_25 ) ) {
int V_200 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_200 -- ) {
V_22 = V_38 -> V_173 ( V_2 , V_38 ) ;
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
static int F_107 ( struct V_1 * V_2 ,
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
F_108 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_201 -> V_107 . V_65 . V_112 ==
* V_112 ) {
V_22 = V_162 -> remove ( V_2 , V_162 -> V_7 , V_201 ) ;
if ( V_22 ) {
F_39 ( L_41 ) ;
F_10 ( & V_162 -> V_14 ) ;
return V_22 ;
}
F_16 ( & V_201 -> V_24 ) ;
}
}
F_10 ( & V_162 -> V_14 ) ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_154 = V_4 ;
V_152 . V_25 = * V_25 ;
V_152 . V_156 . V_106 = V_171 ;
F_109 ( V_199 , & V_152 . V_25 ) ;
F_109 ( V_198 , & V_152 . V_25 ) ;
F_109 ( V_178 , & V_152 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_52 -> V_112 == * V_112 ) {
V_152 . V_156 . V_112 = V_52 -> V_112 ;
memcpy ( & V_152 . V_156 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_22 = F_88 ( V_2 , & V_152 ) ;
if ( V_22 < 0 ) {
F_39 ( L_42 ) ;
return V_22 ;
}
}
}
V_152 . V_25 = * V_25 ;
F_87 ( V_178 , & V_152 . V_25 ) ;
return F_88 ( V_2 , & V_152 ) ;
}
static inline void F_110 ( struct V_32 * V_38 , T_6 V_91 ,
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
V_38 -> V_173 = F_41 ;
}
static inline void F_111 ( struct V_39 * V_4 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_155 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_203 = F_107 ;
V_4 -> V_21 = F_84 ;
V_4 -> V_204 = F_98 ;
V_4 -> V_205 = F_97 ;
F_110 ( & V_4 -> V_38 , V_91 , V_96 , V_92 , V_105 , V_194 ,
V_33 , V_34 , type ) ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_39 * V_206 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 )
{
union V_6 * V_207 = (union V_6 * ) V_206 ;
F_111 ( V_206 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_206 -> V_164 = F_43 ;
V_206 -> V_166 = F_48 ;
V_206 -> V_183 = F_42 ;
V_206 -> V_196 = F_47 ;
if ( F_113 ( V_2 ) ) {
V_206 -> V_192 = F_80 ;
V_206 -> V_68 = F_58 ;
V_206 -> V_69 = F_54 ;
V_206 -> V_170 = F_62 ;
V_206 -> V_193 = V_208 ;
F_1 ( V_2 ,
& V_206 -> V_12 , 1 , V_207 ,
F_95 ,
F_96 ,
F_99 ,
F_101 ,
F_89 ) ;
} else {
V_206 -> V_192 = F_73 ;
V_206 -> V_68 = F_58 ;
V_206 -> V_69 = F_54 ;
V_206 -> V_170 = F_61 ;
V_206 -> V_193 =
V_209 ;
V_206 -> V_210 = F_52 ;
F_1 ( V_2 ,
& V_206 -> V_12 , V_211 ,
V_207 , F_95 ,
F_96 ,
F_99 ,
F_101 ,
F_89 ) ;
}
}
void F_114 ( struct V_1 * V_2 ,
struct V_39 * V_212 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_46 )
{
union V_6 * V_207 = (union V_6 * ) V_212 ;
F_111 ( V_212 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_212 -> V_164 = F_45 ;
V_212 -> V_166 = F_50 ;
V_212 -> V_183 = F_44 ;
V_212 -> V_196 = F_49 ;
if ( F_113 ( V_2 ) ) {
F_39 ( L_43 ) ;
F_115 () ;
} else {
V_212 -> V_192 = F_81 ;
V_212 -> V_68 = F_59 ;
V_212 -> V_69 = F_56 ;
V_212 -> V_170 = F_61 ;
V_212 -> V_193 =
V_209 ;
F_1 ( V_2 ,
& V_212 -> V_12 , V_211 ,
V_207 , F_95 ,
F_96 ,
F_99 ,
F_101 ,
F_90 ) ;
}
}
void F_116 ( struct V_1 * V_2 ,
struct V_39 * V_154 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_194 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_207 =
(union V_6 * ) V_154 ;
F_111 ( V_154 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_154 -> V_164 = F_46 ;
V_154 -> V_166 = F_51 ;
V_154 -> V_183 = F_42 ;
V_154 -> V_196 = F_47 ;
if ( F_117 ( V_2 ) ) {
F_39 ( L_44 ) ;
F_115 () ;
} else if ( F_118 ( V_2 ) ) {
V_154 -> V_192 = F_83 ;
V_154 -> V_68 = F_60 ;
V_154 -> V_69 = F_57 ;
V_154 -> V_170 = F_62 ;
V_154 -> V_193 = V_208 ;
F_1 ( V_2 ,
& V_154 -> V_12 , 1 , V_207 ,
F_95 ,
F_96 ,
F_99 ,
F_101 ,
F_91 ) ;
} else {
V_154 -> V_192 = F_82 ;
V_154 -> V_68 = F_60 ;
V_154 -> V_69 = F_57 ;
V_154 -> V_170 = F_61 ;
V_154 -> V_193 =
V_209 ;
F_1 ( V_2 ,
& V_154 -> V_12 ,
V_211 ,
V_207 , F_95 ,
F_96 ,
F_99 ,
F_101 ,
F_91 ) ;
}
}
static inline void F_119 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
T_7 V_132 )
{
T_10 V_215 = sizeof( struct V_213 ) ;
V_59 V_216 = V_217 +
F_120 ( V_132 ) ;
F_121 ( V_2 , V_216 , V_215 , ( V_59 * ) V_214 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
V_59 V_219 = ( 1 << V_152 -> V_91 ) ;
struct V_213 * V_214 =
(struct V_213 * ) V_152 -> V_105 ;
T_6 V_220 = 1 , V_221 = 1 ;
T_6 V_222 = 0 , V_223 = 0 , V_224 = 0 ;
T_6 V_225 = 0 ;
if ( F_19 ( V_226 , & V_152 -> V_227 ) )
V_220 = 0 ;
if ( F_19 ( V_228 , & V_152 -> V_227 ) )
V_221 = 0 ;
if ( F_19 ( V_229 , & V_152 -> V_227 ) ) {
V_220 = 0 ;
V_222 = 1 ;
}
if ( F_19 ( V_230 , & V_152 -> V_227 ) ) {
V_221 = 0 ;
V_224 = 1 ;
}
if ( F_19 ( V_231 , & V_152 -> V_227 ) )
V_223 = 1 ;
if ( F_19 ( V_232 , & V_152 -> V_227 ) )
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
F_4 ( V_17 , L_45
L_46 ,
V_214 -> V_233 , V_214 -> V_234 ,
V_214 -> V_235 , V_214 -> V_236 ,
V_214 -> V_237 ) ;
F_119 ( V_2 , V_214 , V_152 -> V_92 ) ;
F_30 ( V_152 -> V_33 , V_152 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_123 ( V_59 V_96 ,
struct V_97 * V_89 ,
T_6 V_98 )
{
V_89 -> V_99 = F_72 ( V_96 ) ;
V_89 -> V_98 = V_98 ;
}
static inline void F_124 ( struct V_1 * V_2 ,
unsigned long * V_238 ,
struct V_239 * V_106 ,
bool V_240 )
{
T_7 V_33 ;
V_33 = V_241 |
V_242 ;
if ( F_19 ( V_226 , V_238 ) )
V_33 &= ~ V_241 ;
if ( F_19 ( V_228 , V_238 ) )
V_33 &= ~ V_242 ;
if ( F_19 ( V_229 , V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_243 ;
}
if ( F_19 ( V_230 , V_238 ) ) {
V_33 |= V_244 ;
V_33 &= ~ V_242 ;
}
if ( F_19 ( V_231 , V_238 ) )
V_33 |= V_245 ;
if ( F_19 ( V_232 , V_238 ) ) {
V_33 &= ~ V_241 ;
V_33 |= V_246 ;
}
if ( F_19 ( V_247 , V_238 ) )
V_33 |= V_248 ;
if ( V_240 ) {
V_33 &= ~ V_244 ;
V_33 &= ~ V_245 ;
V_33 &= ~ V_243 ;
V_33 &= ~ V_246 ;
}
V_106 -> V_33 = F_76 ( V_33 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
struct V_249 * V_61 = V_152 -> V_105 ;
int V_22 ;
T_6 V_102 = 0 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
if ( F_19 ( V_250 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_152 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_251 ;
F_124 ( V_2 , & V_152 -> V_252 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
false ) ;
}
if ( F_19 ( V_253 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_152 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_254 ;
F_124 ( V_2 , & V_152 -> V_227 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
false ) ;
}
if ( F_19 ( V_255 , & V_152 -> V_256 ) ) {
if ( F_19 ( V_250 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_126 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_251 ;
F_124 ( V_2 , & V_152 -> V_252 ,
& ( V_61 -> V_110 [ V_102 ] ) ,
true ) ;
V_102 ++ ;
}
if ( F_19 ( V_253 , & V_152 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_126 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_152 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_254 ;
F_124 ( V_2 , & V_152 -> V_227 ,
& ( V_61 -> V_110 [ V_102 ] ) ,
true ) ;
V_102 ++ ;
}
}
F_123 ( V_152 -> V_96 , & V_61 -> V_119 , V_102 ) ;
F_4 ( V_17 , L_47 ,
V_61 -> V_119 . V_98 , V_152 -> V_227 ,
V_152 -> V_252 ) ;
V_22 = F_103 ( V_2 , V_257 , V_152 -> V_96 ,
F_104 ( V_152 -> V_194 ) ,
F_105 ( V_152 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
return F_34 ( V_2 , V_152 -> V_33 , V_152 -> V_34 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
return 0 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_218 * V_152 )
{
int V_22 ;
V_22 = V_152 -> V_258 -> V_259 ( V_2 , V_152 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_19 ( V_199 , & V_152 -> V_25 ) ) {
V_22 = V_152 -> V_258 -> V_173 ( V_2 , V_152 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_130 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
if ( F_113 ( V_2 ) ) {
V_4 -> V_173 = F_128 ;
V_4 -> V_259 = F_122 ;
} else {
V_4 -> V_173 = F_127 ;
V_4 -> V_259 = F_125 ;
}
}
static inline T_6 F_131 ( T_6 * V_57 )
{
return ( F_132 ( 0 , V_57 , V_58 ) >> 24 ) & 0xff ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_262 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_173 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
int V_265 ;
struct V_266 * V_267 ;
struct V_268 * V_269 = NULL ;
struct V_270 * V_52 ;
int V_271 = ( ( V_106 == V_272 ) ?
V_152 -> V_273 : 0 ) ;
if ( ! V_152 -> V_273 )
return 0 ;
V_265 = sizeof( * V_267 ) +
V_271 * sizeof( struct V_268 ) ;
V_267 = F_26 ( V_265 , V_31 ) ;
if ( ! V_267 )
return - V_182 ;
F_4 ( V_17 , L_48 ,
V_106 , V_271 ) ;
F_2 ( & V_267 -> V_61 . V_274 ) ;
V_267 -> type = V_106 ;
V_267 -> V_275 = false ;
switch ( V_106 ) {
case V_272 :
V_269 = (struct V_268 * )
( ( T_6 * ) V_267 + sizeof( * V_267 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_269 -> V_57 , V_52 -> V_57 , V_58 ) ;
F_12 ( & V_269 -> V_24 , & V_267 -> V_61 . V_274 ) ;
V_269 ++ ;
}
break;
case V_276 :
V_267 -> V_61 . V_277 = V_152 -> V_273 ;
break;
case V_278 :
V_267 -> V_61 . V_279 = 0 ;
break;
default:
F_6 ( V_267 ) ;
F_39 ( L_49 , V_106 ) ;
return - V_62 ;
}
F_12 ( & V_267 -> V_24 , & V_4 -> V_280 ) ;
V_4 -> V_281 ( V_4 ) ;
return 1 ;
}
static inline int F_135 ( struct V_261 * V_4 , int V_282 )
{
int V_283 , V_284 , V_285 = V_282 % V_286 ;
for ( V_283 = V_282 / V_286 ; V_283 < V_287 ; V_283 ++ ) {
if ( V_4 -> V_288 . V_289 . V_290 [ V_283 ] )
for ( V_284 = V_285 ; V_284 < V_286 ; V_284 ++ ) {
int V_291 = V_284 + V_286 * V_283 ;
if ( F_136 ( V_4 -> V_288 . V_289 .
V_290 , V_291 ) ) {
return V_291 ;
}
}
V_285 = 0 ;
}
return - 1 ;
}
static inline int F_137 ( struct V_261 * V_4 )
{
int V_291 = F_135 ( V_4 , 0 ) ;
if ( V_291 >= 0 )
F_138 ( V_4 -> V_288 . V_289 . V_290 , V_291 ) ;
return V_291 ;
}
static inline T_6 F_139 ( struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_70 = 0 ;
if ( ( V_38 -> V_71 == V_72 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_292 ;
if ( ( V_38 -> V_71 == V_75 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_293 ;
return V_70 ;
}
static void F_140 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_187 ,
union V_294 * V_295 ,
enum V_264 V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_296 * V_61 =
(struct V_296 * ) ( V_125 -> V_105 ) ;
T_6 V_92 = V_125 -> V_92 ;
T_6 V_297 = F_139 ( V_4 ) ;
int V_298 ;
if ( ( V_106 == V_272 ) || ( V_106 == V_278 ) )
V_297 |= V_299 ;
V_61 -> V_110 [ V_187 ] . V_93 |= V_297 ;
switch ( V_106 ) {
case V_272 :
V_298 = F_131 ( V_295 -> V_57 ) ;
F_141 ( V_4 -> V_288 . V_289 . V_290 , V_298 ) ;
break;
case V_276 :
V_298 = F_137 ( V_4 ) ;
break;
case V_278 :
V_298 = V_295 -> V_298 ;
break;
default:
F_39 ( L_49 , V_106 ) ;
return;
}
F_4 ( V_17 , L_50 ,
( ( V_297 & V_299 ) ?
L_51 : L_52 ) , V_298 ) ;
V_61 -> V_110 [ V_187 ] . V_300 = ( T_6 ) V_298 ;
V_61 -> V_110 [ V_187 ] . V_92 = V_92 ;
V_61 -> V_110 [ V_187 ] . V_301 = V_4 -> V_301 ;
}
static inline int F_142 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_302 ,
int * V_303 )
{
int V_304 , V_20 = * V_303 ;
union V_294 V_295 = { NULL } ;
for ( V_304 = F_135 ( V_4 , V_302 ) ; V_304 >= 0 ;
V_304 = F_135 ( V_4 , V_304 + 1 ) ) {
V_295 . V_298 = ( T_6 ) V_304 ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_295 ,
V_278 ) ;
V_20 ++ ;
F_4 ( V_17 , L_53 , V_304 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_303 = V_20 ;
return V_304 ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
struct V_268 * V_308 , * V_309 ;
int V_20 = * V_307 ;
union V_294 V_295 = { NULL } ;
F_108 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_295 . V_57 = & V_308 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_295 , V_306 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_308 -> V_57 ) ;
F_16 ( & V_308 -> V_24 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_307 = V_20 ;
if ( F_14 ( & V_306 -> V_61 . V_274 ) )
V_306 -> V_275 = true ;
}
static inline void F_144 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
int V_20 = * V_307 ;
while ( V_306 -> V_61 . V_277 ) {
V_4 -> V_192 ( V_2 , V_4 , V_20 , NULL , V_306 -> type ) ;
V_20 ++ ;
V_306 -> V_61 . V_277 -- ;
F_4 ( V_17 , L_55 ,
V_306 -> V_61 . V_277 , V_20 ) ;
if ( V_20 >= V_4 -> V_305 )
break;
}
* V_307 = V_20 ;
if ( ! V_306 -> V_61 . V_277 )
V_306 -> V_275 = true ;
}
static inline void F_145 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_266 * V_306 ,
int * V_307 )
{
V_306 -> V_61 . V_279 = V_4 -> V_310 ( V_2 , V_4 , V_306 -> V_61 . V_279 ,
V_307 ) ;
if ( V_306 -> V_61 . V_279 < 0 )
V_306 -> V_275 = true ;
else
V_306 -> V_61 . V_279 ++ ;
}
static inline int F_146 ( struct V_1 * V_2 ,
struct V_263 * V_152 )
{
struct V_266 * V_306 , * V_311 ;
int V_20 = 0 ;
struct V_261 * V_4 = V_152 -> V_312 ;
F_108 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_306 -> type ) {
case V_272 :
F_143 ( V_2 , V_4 , V_306 , & V_20 ) ;
break;
case V_276 :
F_144 ( V_2 , V_4 , V_306 , & V_20 ) ;
break;
case V_278 :
F_145 ( V_2 , V_4 , V_306 ,
& V_20 ) ;
break;
default:
F_39 ( L_49 , V_306 -> type ) ;
return - V_62 ;
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
static inline void F_147 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
int * V_307 )
{
struct V_270 * V_313 ;
union V_294 V_295 = { NULL } ;
int V_20 = * V_307 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_295 . V_57 = V_313 -> V_57 ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_295 , V_272 ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_313 -> V_57 ) ;
}
* V_307 = V_20 ;
}
static inline void F_148 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
int * V_307 )
{
int V_20 = * V_307 , V_283 ;
for ( V_283 = 0 ; V_283 < V_152 -> V_273 ; V_283 ++ ) {
V_4 -> V_192 ( V_2 , V_4 , V_20 , NULL , V_276 ) ;
V_20 ++ ;
F_4 ( V_17 , L_56 ,
V_152 -> V_273 - V_283 - 1 ) ;
}
* V_307 = V_20 ;
}
static inline int F_149 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 ,
int V_314 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
int V_20 = V_314 ;
F_4 ( V_17 , L_57 , V_152 -> V_273 ) ;
switch ( V_106 ) {
case V_272 :
F_147 ( V_2 , V_4 , V_152 , & V_20 ) ;
break;
case V_276 :
F_148 ( V_2 , V_4 , V_152 , & V_20 ) ;
break;
case V_278 :
V_4 -> V_310 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_39 ( L_49 , V_106 ) ;
return - V_62 ;
}
V_152 -> V_273 = 0 ;
return V_20 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
int V_315 = V_4 -> V_316 ( V_4 ) ;
switch ( V_106 ) {
case V_276 :
V_4 -> V_317 ( V_4 , 0 ) ;
case V_278 :
V_152 -> V_273 = V_315 ;
break;
case V_272 :
case V_318 :
V_4 -> V_317 ( V_4 , V_315 + V_152 -> V_273 ) ;
break;
default:
F_39 ( L_49 , V_106 ) ;
return - V_62 ;
}
V_4 -> V_319 += V_152 -> V_273 ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_320 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
V_4 -> V_317 ( V_4 , V_320 ) ;
V_4 -> V_319 -= V_152 -> V_273 ;
}
static inline void F_152 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
T_6 V_321 )
{
struct V_32 * V_125 = & V_152 -> V_312 -> V_38 ;
struct V_296 * V_61 =
(struct V_296 * ) ( V_125 -> V_105 ) ;
V_61 -> V_119 . V_99 = F_72 ( ( V_125 -> V_96 & V_100 ) |
( V_322 <<
V_101 ) ) ;
V_61 -> V_119 . V_98 = V_321 ;
}
static inline int F_153 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
int V_283 , V_20 = 0 ;
T_11 V_19 ;
for ( V_283 = 0 ; V_283 < V_287 ; V_283 ++ ) {
V_19 = V_4 -> V_288 . V_289 . V_290 [ V_283 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_317 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
struct V_32 * V_38 = & V_152 -> V_312 -> V_38 ;
struct V_261 * V_4 = V_152 -> V_312 ;
struct V_296 * V_61 =
(struct V_296 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_20 = F_146 ( V_2 , V_152 ) ;
if ( F_14 ( & V_4 -> V_280 ) )
V_4 -> V_323 ( V_4 ) ;
if ( V_152 -> V_273 > 0 )
V_20 = F_149 ( V_2 , V_152 , V_106 , V_20 ) ;
V_4 -> V_319 -= V_20 ;
F_20 ( V_4 -> V_319 < 0 ) ;
F_20 ( V_20 > V_4 -> V_305 ) ;
F_152 ( V_2 , V_152 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_319 )
F_153 ( V_2 , V_4 ) ;
if ( F_19 ( V_28 , & V_152 -> V_25 ) ) {
V_38 -> V_176 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_103 ( V_2 , V_324 ,
V_38 -> V_96 , F_104 ( V_38 -> V_194 ) ,
F_105 ( V_38 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_155 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
if ( ( V_106 == V_276 ) || ( V_106 == V_278 ) )
V_152 -> V_273 = 1 ;
return 0 ;
}
static void F_156 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_320 )
{
}
static inline void F_157 ( struct V_1 * V_2 ,
struct V_261 * V_4 ,
struct V_263 * V_152 ,
V_59 * V_325 )
{
struct V_270 * V_313 ;
int V_326 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_326 = F_131 ( V_313 -> V_57 ) ;
F_158 ( V_325 , V_326 ) ;
F_4 ( V_17 , L_58 ,
V_313 -> V_57 , V_326 ) ;
F_141 ( V_4 -> V_288 . V_289 . V_290 ,
V_326 ) ;
}
}
static inline void F_159 ( struct V_1 * V_2 ,
struct V_261 * V_4 , struct V_263 * V_152 ,
V_59 * V_325 )
{
int V_326 ;
for ( V_326 = F_135 ( V_4 , 0 ) ;
V_326 >= 0 ;
V_326 = F_135 ( V_4 , V_326 + 1 ) ) {
F_158 ( V_325 , V_326 ) ;
F_4 ( V_17 , L_59 , V_326 ) ;
}
}
static int F_160 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
int V_283 ;
struct V_261 * V_4 = V_152 -> V_312 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( ! F_19 ( V_28 , & V_152 -> V_25 ) ) {
V_59 V_325 [ V_327 ] = { 0 } ;
switch ( V_106 ) {
case V_272 :
F_157 ( V_2 , V_4 , V_152 , V_325 ) ;
break;
case V_276 :
F_4 ( V_17 ,
L_60 ) ;
memset ( V_4 -> V_288 . V_289 . V_290 , 0 ,
sizeof( V_4 -> V_288 . V_289 . V_290 ) ) ;
break;
case V_278 :
F_159 ( V_2 , V_4 , V_152 , V_325 ) ;
break;
default:
F_39 ( L_49 , V_106 ) ;
return - V_62 ;
}
for ( V_283 = 0 ; V_283 < V_327 ; V_283 ++ )
F_69 ( V_2 , F_161 ( V_2 , V_283 ) , V_325 [ V_283 ] ) ;
} else
memset ( V_4 -> V_288 . V_289 . V_290 , 0 ,
sizeof( V_4 -> V_288 . V_289 . V_290 ) ) ;
V_125 -> V_176 ( V_125 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
int V_315 = V_4 -> V_316 ( V_4 ) ;
switch ( V_106 ) {
case V_276 :
V_4 -> V_317 ( V_4 , 0 ) ;
case V_278 :
V_152 -> V_273 = V_315 ;
F_4 ( V_17 , L_61 ,
V_106 , V_152 -> V_273 ) ;
break;
case V_272 :
case V_318 :
if ( V_152 -> V_273 > V_4 -> V_305 ) {
F_39 ( L_62 ,
V_4 -> V_305 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_57 , V_152 -> V_273 ) ;
if ( V_152 -> V_273 > 0 )
V_4 -> V_317 ( V_4 , V_152 -> V_273 ) ;
break;
default:
F_39 ( L_49 , V_106 ) ;
return - V_62 ;
}
if ( V_152 -> V_273 )
V_4 -> V_319 += V_4 -> V_305 ;
return 0 ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
int V_328 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
V_4 -> V_317 ( V_4 , V_328 ) ;
if ( V_152 -> V_273 )
V_4 -> V_319 -= V_4 -> V_305 ;
}
static void F_164 ( struct V_1 * V_2 ,
struct V_261 * V_4 , int V_187 ,
union V_294 * V_295 ,
enum V_264 V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
if ( ( V_106 == V_272 ) || ( V_106 == V_278 ) ) {
F_74 ( & V_61 -> V_143 [ V_187 ] . V_137 ,
& V_61 -> V_143 [ V_187 ] . V_138 ,
& V_61 -> V_143 [ V_187 ] . V_139 ,
V_295 -> V_57 ) ;
V_61 -> V_143 [ V_187 ] . V_127 = 0 ;
V_61 -> V_143 [ V_187 ] . V_132 = V_125 -> V_92 ;
V_61 -> V_143 [ V_187 ] . V_131 =
F_72 ( 1 << V_125 -> V_91 ) ;
F_78 ( V_61 -> V_143 [ V_187 ] . V_133 ,
V_134 ,
V_135 ) ;
}
}
static inline void F_165 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
T_6 V_321 )
{
struct V_32 * V_125 = & V_152 -> V_312 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
T_6 V_40 = ( F_166 ( V_2 ) ?
V_329 * ( 1 + V_125 -> V_92 ) :
V_330 * ( 1 + V_125 -> V_92 ) ) ;
V_61 -> V_89 . V_40 = V_40 ;
V_61 -> V_89 . V_90 = F_76 ( 0xff ) ;
V_61 -> V_89 . V_99 = F_72 ( ( V_125 -> V_96 & V_100 ) |
( V_322 <<
V_101 ) ) ;
V_61 -> V_89 . V_126 = V_321 ;
}
static inline int F_167 (
struct V_1 * V_2 , struct V_261 * V_4 , int V_331 ,
int * V_303 )
{
struct V_268 * V_19 ;
int V_283 = 0 ;
union V_294 V_295 = { NULL } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_295 . V_57 = & V_19 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_283 , & V_295 , V_278 ) ;
V_283 ++ ;
F_4 ( V_17 , L_54 ,
V_295 . V_57 ) ;
}
* V_303 = V_283 ;
return - 1 ;
}
static inline int F_168 (
struct V_1 * V_2 , struct V_263 * V_152 )
{
struct V_266 * V_306 ;
struct V_268 * V_308 ;
struct V_261 * V_4 = V_152 -> V_312 ;
union V_294 V_295 = { NULL } ;
int V_20 = 0 ;
if ( F_14 ( & V_4 -> V_280 ) )
return 0 ;
V_306 = F_15 ( & V_4 -> V_280 ,
struct V_266 , V_24 ) ;
switch ( V_306 -> type ) {
case V_272 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_295 . V_57 = & V_308 -> V_57 [ 0 ] ;
V_4 -> V_192 ( V_2 , V_4 , V_20 , & V_295 , V_306 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_308 -> V_57 ) ;
}
break;
case V_276 :
V_20 = V_306 -> V_61 . V_277 ;
F_4 ( V_17 , L_63 , V_20 ) ;
break;
case V_278 :
V_4 -> V_310 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_39 ( L_49 , V_306 -> type ) ;
return - V_62 ;
}
F_16 ( & V_306 -> V_24 ) ;
F_6 ( V_306 ) ;
return V_20 ;
}
static inline void F_169 ( T_12 * V_332 , T_12 * V_333 ,
T_12 * V_334 , T_6 * V_57 )
{
V_57 [ 1 ] = ( ( T_6 * ) V_332 ) [ 0 ] ;
V_57 [ 0 ] = ( ( T_6 * ) V_332 ) [ 1 ] ;
V_57 [ 3 ] = ( ( T_6 * ) V_333 ) [ 0 ] ;
V_57 [ 2 ] = ( ( T_6 * ) V_333 ) [ 1 ] ;
V_57 [ 5 ] = ( ( T_6 * ) V_334 ) [ 0 ] ;
V_57 [ 4 ] = ( ( T_6 * ) V_334 ) [ 1 ] ;
}
static inline int F_170 ( struct V_1 * V_2 ,
struct V_261 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_268 * V_19 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
if ( F_171 ( V_61 -> V_143 [ 0 ] . V_133 ,
V_134 ) ) {
int V_283 , V_321 = V_61 -> V_89 . V_126 ;
if ( ! F_14 ( & V_4 -> V_288 . V_335 . V_336 ) )
return 0 ;
V_19 = F_172 ( V_321 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_39 ( L_64 ) ;
return - V_182 ;
}
for ( V_283 = 0 ; V_283 < V_321 ; V_283 ++ , V_19 ++ ) {
F_169 (
& V_61 -> V_143 [ V_283 ] . V_137 ,
& V_61 -> V_143 [ V_283 ] . V_138 ,
& V_61 -> V_143 [ V_283 ] . V_139 ,
V_19 -> V_57 ) ;
F_4 ( V_17 , L_65 ,
V_19 -> V_57 ) ;
F_12 ( & V_19 -> V_24 ,
& V_4 -> V_288 . V_335 . V_336 ) ;
}
} else {
V_19 = F_15 ( & V_4 -> V_288 . V_335 . V_336 ,
struct V_268 , V_24 ) ;
F_4 ( V_17 , L_66 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_288 . V_335 . V_336 ) ;
}
return 0 ;
}
static int F_173 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_283 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
for ( V_283 = 0 ; V_283 < V_4 -> V_305 ; V_283 ++ )
F_78 ( V_61 -> V_143 [ V_283 ] . V_133 ,
V_134 ,
V_140 ) ;
V_20 = F_168 ( V_2 , V_152 ) ;
if ( F_14 ( & V_4 -> V_280 ) )
V_4 -> V_323 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_149 ( V_2 , V_152 , V_106 , 0 ) ;
V_4 -> V_319 -= V_4 -> V_305 ;
F_20 ( V_20 > V_4 -> V_305 ) ;
F_165 ( V_2 , V_152 , ( T_6 ) V_20 ) ;
V_22 = F_170 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_19 ( V_28 , & V_152 -> V_25 ) ) {
V_38 -> V_176 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_103 ( V_2 , V_208 , V_38 -> V_96 ,
F_104 ( V_38 -> V_194 ) ,
F_105 ( V_38 -> V_194 ) ,
V_195 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_174 ( struct V_261 * V_4 )
{
return V_4 -> V_288 . V_335 . V_337 ;
}
static int F_175 ( struct V_261 * V_4 )
{
return V_4 -> V_288 . V_289 . V_338 ;
}
static void F_176 ( struct V_261 * V_4 ,
int V_49 )
{
V_4 -> V_288 . V_335 . V_337 = V_49 ;
}
static void F_177 ( struct V_261 * V_4 ,
int V_49 )
{
V_4 -> V_288 . V_289 . V_338 = V_49 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_263 * V_152 ,
enum V_264 V_106 )
{
struct V_261 * V_4 = V_152 -> V_312 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 = 0 , V_339 ;
V_339 = V_4 -> V_316 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_152 , V_106 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_152 -> V_273 ) && ( ! V_4 -> V_340 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_67 ,
V_4 -> V_319 , V_152 -> V_273 , V_4 -> V_305 ) ;
if ( V_125 -> V_189 ( V_125 ) ||
( ( V_4 -> V_305 > 0 ) && ( V_4 -> V_319 > V_4 -> V_305 ) ) ) {
V_22 = V_4 -> V_341 ( V_2 , V_152 -> V_312 , V_152 , V_106 ) ;
if ( V_22 < 0 )
goto V_342;
V_152 -> V_273 = 0 ;
}
if ( ! V_125 -> V_189 ( V_125 ) ) {
V_125 -> V_190 ( V_125 ) ;
V_22 = V_4 -> V_343 ( V_2 , V_152 , V_106 ) ;
if ( V_22 < 0 )
goto V_344;
if ( F_19 ( V_199 , & V_152 -> V_25 ) )
V_22 = V_4 -> V_173 ( V_2 , V_4 ) ;
}
return V_22 ;
V_344:
V_125 -> V_176 ( V_125 ) ;
V_342:
V_4 -> V_345 ( V_2 , V_152 , V_339 ) ;
return V_22 ;
}
static void F_179 ( struct V_261 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_180 ( struct V_261 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_181 ( struct V_261 * V_4 )
{
return ! ! F_19 ( V_4 -> V_262 , V_4 -> V_38 . V_34 ) ;
}
static bool F_182 ( struct V_261 * V_4 )
{
return V_4 -> V_38 . V_189 ( & V_4 -> V_38 ) || V_4 -> V_340 ( V_4 ) ;
}
void F_183 ( struct V_1 * V_2 ,
struct V_261 * V_312 ,
T_6 V_346 , V_59 V_347 , T_6 V_92 ,
T_6 V_301 , void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 , T_9 type )
{
memset ( V_312 , 0 , sizeof( * V_312 ) ) ;
F_110 ( & V_312 -> V_38 , V_346 , V_347 , V_92 ,
V_105 , V_194 , V_33 , V_34 , type ) ;
V_312 -> V_301 = V_301 ;
F_2 ( & V_312 -> V_280 ) ;
V_312 -> V_262 = V_348 ;
V_312 -> V_340 = F_181 ;
V_312 -> V_281 = F_180 ;
V_312 -> V_323 = F_179 ;
if ( F_117 ( V_2 ) ) {
V_312 -> V_343 = F_173 ;
V_312 -> V_341 = F_134 ;
V_312 -> V_310 =
F_167 ;
V_312 -> V_189 = F_182 ;
if ( F_166 ( V_2 ) )
V_312 -> V_305 = V_329 ;
else
V_312 -> V_305 = V_330 ;
V_312 -> V_173 = F_133 ;
V_312 -> V_192 = F_164 ;
V_312 -> V_8 = F_162 ;
V_312 -> V_345 = F_163 ;
V_312 -> V_316 =
F_174 ;
V_312 -> V_317 =
F_176 ;
F_2 ( & V_312 -> V_288 . V_335 . V_336 ) ;
} else if ( F_118 ( V_2 ) ) {
V_312 -> V_343 = F_160 ;
V_312 -> V_341 = NULL ;
V_312 -> V_310 = NULL ;
V_312 -> V_189 = F_182 ;
V_312 -> V_305 = - 1 ;
V_312 -> V_173 = F_133 ;
V_312 -> V_192 = NULL ;
V_312 -> V_8 = F_155 ;
V_312 -> V_345 = F_156 ;
V_312 -> V_316 =
F_175 ;
V_312 -> V_317 =
F_177 ;
} else {
V_312 -> V_343 = F_154 ;
V_312 -> V_341 = F_134 ;
V_312 -> V_310 =
F_142 ;
V_312 -> V_189 = F_182 ;
V_312 -> V_305 = 16 ;
V_312 -> V_173 = F_133 ;
V_312 -> V_192 = F_140 ;
V_312 -> V_8 = F_150 ;
V_312 -> V_345 = F_151 ;
V_312 -> V_316 =
F_175 ;
V_312 -> V_317 =
F_177 ;
}
}
static inline bool F_184 ( T_13 * V_349 , int V_350 , int V_56 )
{
int V_351 , V_352 ;
V_351 = F_185 ( V_349 ) ;
for (; ; ) {
if ( F_186 ( V_351 + V_350 >= V_56 ) )
return false ;
V_352 = F_187 ( ( V_349 ) , V_351 , V_351 + V_350 ) ;
if ( F_188 ( V_352 == V_351 ) )
break;
V_351 = V_352 ;
}
return true ;
}
static inline bool F_189 ( T_13 * V_349 , int V_350 , int V_56 )
{
int V_351 , V_352 ;
V_351 = F_185 ( V_349 ) ;
for (; ; ) {
if ( F_186 ( V_351 - V_350 < V_56 ) )
return false ;
V_352 = F_187 ( ( V_349 ) , V_351 , V_351 - V_350 ) ;
if ( F_188 ( V_352 == V_351 ) )
break;
V_351 = V_352 ;
}
return true ;
}
static bool F_190 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_191 () ;
V_22 = F_189 ( & V_4 -> V_353 , V_20 , 0 ) ;
F_191 () ;
return V_22 ;
}
static bool F_192 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_191 () ;
V_22 = F_184 ( & V_4 -> V_353 , V_20 , V_4 -> V_354 + 1 ) ;
F_191 () ;
return V_22 ;
}
static int F_193 ( struct V_41 * V_4 )
{
int V_355 ;
F_191 () ;
V_355 = F_185 ( & V_4 -> V_353 ) ;
return V_355 ;
}
static bool F_194 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_195 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_187 , V_290 , V_283 ;
* V_40 = - 1 ;
for ( V_290 = 0 ; V_290 < V_356 ; V_290 ++ ) {
if ( ! V_4 -> V_357 [ V_290 ] )
continue;
for ( V_187 = V_290 * V_286 , V_283 = 0 ;
V_283 < V_286 ; V_187 ++ , V_283 ++ )
if ( F_136 ( V_4 -> V_357 , V_187 ) ) {
F_138 ( V_4 -> V_357 , V_187 ) ;
* V_40 = V_4 -> V_358 + V_187 ;
return true ;
}
}
return false ;
}
static bool F_196 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_358 )
return false ;
V_40 -= V_4 -> V_358 ;
if ( V_40 >= V_4 -> V_354 )
return false ;
F_141 ( V_4 -> V_357 , V_40 ) ;
return true ;
}
static bool F_197 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_198 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_199 ( struct V_41 * V_152 ,
int V_359 , int V_353 )
{
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
memset ( & V_152 -> V_357 , 0xff , sizeof( V_152 -> V_357 ) ) ;
F_200 ( & V_152 -> V_353 , V_353 ) ;
V_152 -> V_354 = V_353 ;
V_152 -> V_358 = V_359 ;
F_191 () ;
V_152 -> V_360 = F_193 ;
if ( V_353 >= 0 ) {
V_152 -> V_47 = F_192 ;
V_152 -> V_11 = F_190 ;
V_152 -> V_48 = F_196 ;
V_152 -> V_44 = F_195 ;
} else {
V_152 -> V_47 = F_194 ;
V_152 -> V_11 = F_194 ;
V_152 -> V_48 = F_197 ;
V_152 -> V_44 = F_198 ;
}
if ( V_359 < 0 ) {
V_152 -> V_48 = F_197 ;
V_152 -> V_44 = F_198 ;
}
}
void F_201 ( struct V_1 * V_2 ,
struct V_41 * V_152 , T_6 V_92 ,
T_6 V_361 )
{
#define F_202 5
int V_362 ;
if ( F_117 ( V_2 ) ) {
if ( ! F_166 ( V_2 ) )
V_362 = ( V_363 / 2 ) - V_330 ;
else
V_362 = F_202 - V_329 ;
F_199 ( V_152 , V_92 * V_362 , V_362 ) ;
} else if ( F_118 ( V_2 ) ) {
if ( ( V_361 > 0 ) ) {
if ( ! F_166 ( V_2 ) )
V_362 = ( V_364 / ( 2 * V_361 ) ) ;
else
V_362 = F_202 ;
F_199 ( V_152 , V_92 * V_362 , V_362 ) ;
} else {
F_199 ( V_152 , 0 , 0 ) ;
}
} else {
if ( ( V_361 > 0 ) ) {
if ( ! F_166 ( V_2 ) )
V_362 = ( V_365 / V_361 ) ;
else
V_362 = F_202 ;
F_199 ( V_152 , - 1 , V_362 ) ;
} else {
F_199 ( V_152 , 0 , 0 ) ;
}
}
}
void F_203 ( struct V_1 * V_2 ,
struct V_41 * V_152 ,
T_6 V_92 ,
T_6 V_361 )
{
if ( F_113 ( V_2 ) ) {
F_199 ( V_152 , 0 , - 1 ) ;
} else {
if ( V_361 > 0 ) {
int V_353 = V_366 / V_361 ;
F_199 ( V_152 , V_92 * V_353 , V_353 ) ;
} else
F_199 ( V_152 , 0 , 0 ) ;
}
}
static inline void F_204 ( struct V_1 * V_2 ,
struct V_367 * V_152 )
{
int V_283 ;
F_4 ( V_17 , L_68 ) ;
F_4 ( V_17 , L_69 ) ;
for ( V_283 = 0 ; V_283 < V_368 ; V_283 ++ ) {
F_205 ( V_17 , L_70 , V_152 -> V_369 [ V_283 ] ) ;
if ( ( V_283 + 1 < V_368 ) &&
( ( ( V_283 + 1 ) & 0x3 ) == 0 ) ) {
F_205 ( V_17 , L_71 ) ;
F_4 ( V_17 , L_72 , V_283 + 1 ) ;
}
}
F_205 ( V_17 , L_71 ) ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_367 * V_152 )
{
struct V_370 * V_4 = V_152 -> V_371 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_372 * V_61 =
(struct V_372 * ) ( V_125 -> V_105 ) ;
T_6 V_373 = 0 ;
int V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_4 ( V_17 , L_73 ) ;
V_61 -> V_99 = F_72 ( ( V_125 -> V_96 & V_100 ) |
( V_125 -> V_33 << V_101 ) ) ;
if ( F_19 ( V_374 , & V_152 -> V_375 ) )
V_373 = V_376 ;
else if ( F_19 ( V_377 , & V_152 -> V_375 ) )
V_373 = V_378 ;
V_61 -> V_373 = V_373 ;
F_4 ( V_17 , L_74 , V_373 ) ;
if ( F_19 ( V_379 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_381 ;
if ( F_19 ( V_382 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_383 ;
if ( F_19 ( V_384 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_385 ;
if ( F_19 ( V_386 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_387 ;
if ( F_19 ( V_388 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_389 ;
if ( F_19 ( V_390 , & V_152 -> V_375 ) )
V_61 -> V_380 |=
V_391 ;
V_61 -> V_392 = V_152 -> V_392 ;
V_61 -> V_393 = V_4 -> V_301 ;
F_4 ( V_17 , L_75 , V_61 -> V_393 ) ;
memcpy ( V_61 -> V_394 , V_152 -> V_369 ,
V_368 ) ;
memcpy ( V_4 -> V_369 , V_152 -> V_369 , V_368 ) ;
if ( F_207 ( V_2 ) )
F_204 ( V_2 , V_152 ) ;
if ( F_19 ( V_395 , & V_152 -> V_375 ) ) {
memcpy ( & V_61 -> V_396 [ 0 ] , & V_152 -> V_396 [ 0 ] ,
sizeof( V_61 -> V_396 ) ) ;
V_61 -> V_380 |= V_397 ;
}
V_22 = F_103 ( V_2 , V_398 , V_125 -> V_96 ,
F_104 ( V_125 -> V_194 ) ,
F_105 ( V_125 -> V_194 ) ,
V_195 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_208 ( struct V_370 * V_371 ,
T_6 * V_369 )
{
memcpy ( V_369 , V_371 -> V_369 , sizeof( V_371 -> V_369 ) ) ;
}
int F_209 ( struct V_1 * V_2 ,
struct V_367 * V_152 )
{
int V_22 ;
struct V_370 * V_4 = V_152 -> V_371 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( F_19 ( V_28 , & V_152 -> V_25 ) )
return 0 ;
V_125 -> V_190 ( V_125 ) ;
V_22 = V_4 -> V_399 ( V_2 , V_152 ) ;
if ( V_22 < 0 ) {
V_125 -> V_176 ( V_125 ) ;
return V_22 ;
}
if ( F_19 ( V_199 , & V_152 -> V_25 ) )
V_22 = V_125 -> V_173 ( V_2 , V_125 ) ;
return V_22 ;
}
void F_210 ( struct V_1 * V_2 ,
struct V_370 * V_371 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , T_6 V_301 ,
void * V_105 , T_8 V_194 ,
int V_33 , unsigned long * V_34 ,
T_9 type )
{
F_110 ( & V_371 -> V_38 , V_91 , V_96 , V_92 , V_105 ,
V_194 , V_33 , V_34 , type ) ;
V_371 -> V_301 = V_301 ;
V_371 -> V_399 = F_206 ;
}
int F_211 ( struct V_1 * V_2 ,
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
V_404 = V_4 -> V_190 ( V_4 , V_401 ) ;
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
if ( F_19 ( V_199 , & V_401 -> V_25 ) ) {
V_22 = V_4 -> V_173 ( V_2 , V_4 , V_404 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_19 ( V_404 , V_405 ) ;
}
static int F_212 ( struct V_402 * V_411 ,
struct V_400 * V_401 )
{
enum V_412 V_106 = V_401 -> V_106 , V_326 ;
if ( ( V_106 == V_413 ) ||
( V_106 == V_414 ) )
V_326 = V_415 ;
else
V_326 = V_106 ;
F_33 ( V_326 , & V_411 -> V_405 ) ;
return V_326 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
enum V_412 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_405 ) ;
}
static int F_214 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
enum V_412 V_106 )
{
unsigned long V_416 = V_4 -> V_405 ;
if ( ! F_215 ( V_106 , & V_416 ) ) {
F_39 ( L_79 ,
V_106 , V_4 -> V_417 [ V_418 ] ,
V_4 -> V_33 , V_416 , V_4 -> V_409 ) ;
return - V_62 ;
}
if ( V_4 -> V_419 >= V_4 -> V_420 )
F_39 ( L_80 ,
V_4 -> V_419 , V_4 -> V_420 ) ;
F_4 ( V_17 ,
L_81 ,
V_106 , V_4 -> V_417 [ V_418 ] , V_4 -> V_409 ) ;
if ( V_4 -> V_419 )
F_4 ( V_17 , L_82 ,
V_4 -> V_417 [ V_418 ] , V_4 -> V_419 ) ;
V_4 -> V_33 = V_4 -> V_409 ;
V_4 -> V_421 = V_4 -> V_419 ;
V_4 -> V_409 = V_410 ;
F_216 () ;
F_30 ( V_106 , & V_4 -> V_405 ) ;
F_31 () ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_423 * V_61 )
{
struct V_424 * V_401 = & V_422 -> V_401 . V_425 ;
V_61 -> V_426 . V_427 |= F_19 ( V_428 , & V_401 -> V_133 ) *
V_429 ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
struct V_430 * V_401 ,
struct V_431 * V_432 ,
unsigned long * V_133 )
{
V_432 -> V_90 = V_4 -> V_91 ;
if ( F_19 ( V_433 , V_133 ) ) {
V_432 -> V_434 =
V_401 -> V_435 ;
V_432 -> V_436 = 1 ;
V_432 -> V_437 =
F_19 ( V_438 , V_133 ) ;
} else
V_432 -> V_434 =
V_439 ;
V_432 -> V_440 = F_19 ( V_441 , V_133 ) ;
V_432 -> V_442 = F_19 ( V_443 , V_133 ) ;
V_432 -> V_444 = V_401 -> V_445 ;
V_432 -> V_446 = F_76 ( V_401 -> V_446 ) ;
V_432 -> V_92 = V_4 -> V_92 ;
V_432 -> cos = V_401 -> cos ;
V_432 -> V_447 =
F_19 ( V_441 , V_133 ) ?
V_448 : V_449 ;
F_4 ( V_17 , L_83 ,
V_432 -> V_442 , V_432 -> cos , V_432 -> V_436 ) ;
}
static void F_219 ( struct V_402 * V_4 ,
struct V_450 * V_401 ,
struct V_451 * V_452 ,
unsigned long * V_133 )
{
V_452 -> V_453 =
F_19 ( V_454 , V_133 ) ;
V_452 -> V_455 =
F_76 ( V_401 -> V_455 ) ;
V_452 -> V_456 =
F_19 ( V_457 , V_133 ) ;
V_452 -> V_458 =
F_19 ( V_459 , V_133 ) ;
V_452 -> V_460 =
F_19 ( V_461 , V_133 ) ;
V_452 -> V_462 =
F_19 ( V_463 , V_133 ) ;
V_452 -> V_464 = V_401 -> V_465 ;
V_452 -> V_466 = V_401 -> V_467 ;
V_452 -> V_468 = V_401 -> V_469 ;
V_452 -> V_470 . V_471 =
F_72 ( F_105 ( V_401 -> V_472 ) ) ;
V_452 -> V_470 . V_473 =
F_72 ( F_104 ( V_401 -> V_472 ) ) ;
V_452 -> V_33 = 0 ;
}
static void F_220 ( struct V_402 * V_4 ,
struct V_474 * V_401 ,
struct V_475 * V_476 )
{
V_476 -> V_477 = F_76 ( V_401 -> V_478 ) ;
V_476 -> V_479 = F_76 ( V_401 -> V_480 ) ;
V_476 -> V_481 = F_76 ( V_401 -> V_482 ) ;
V_476 -> V_483 = F_76 ( V_401 -> V_484 ) ;
V_476 -> V_485 = F_76 ( V_401 -> V_486 ) ;
V_476 -> V_487 = F_76 ( V_401 -> V_488 ) ;
V_476 -> V_489 = F_76 ( V_401 -> V_490 ) ;
}
static void F_221 ( struct V_402 * V_4 ,
struct V_491 * V_401 ,
struct V_475 * V_476 ,
unsigned long * V_133 )
{
V_476 -> V_427 = F_19 ( V_492 , V_133 ) *
V_493 ;
V_476 -> V_427 |= F_19 ( V_494 , V_133 ) *
V_495 ;
V_476 -> V_496 = 0 ;
V_476 -> V_497 =
V_401 -> V_498 ;
V_476 -> V_499 =
F_19 ( V_500 , V_133 ) ;
V_476 -> V_501 = V_401 -> V_502 ;
V_476 -> V_503 = V_401 -> V_504 ;
V_476 -> V_505 = F_76 ( V_401 -> V_506 ) ;
V_476 -> V_33 = F_76 ( V_507 |
V_508 ) ;
V_476 -> V_509 = 0 ;
V_476 -> V_510 = 0 ;
V_476 -> V_511 = 0 ;
V_476 -> V_512 = 0 ;
V_476 -> V_513 =
F_19 ( V_514 , V_133 ) ;
V_476 -> V_515 =
F_19 ( V_516 , V_133 ) ;
V_476 -> V_517 = V_401 -> V_465 ;
V_476 -> V_518 = V_401 -> V_467 ;
V_476 -> V_519 = V_401 -> V_519 ;
V_476 -> V_520 = F_76 ( V_401 -> V_521 ) ;
V_476 -> V_522 = F_76 ( V_401 -> V_523 ) ;
V_476 -> V_524 . V_471 =
F_72 ( F_105 ( V_401 -> V_472 ) ) ;
V_476 -> V_524 . V_473 =
F_72 ( F_104 ( V_401 -> V_472 ) ) ;
V_476 -> V_525 . V_471 =
F_72 ( F_105 ( V_401 -> V_526 ) ) ;
V_476 -> V_525 . V_473 =
F_72 ( F_104 ( V_401 -> V_526 ) ) ;
V_476 -> V_527 . V_471 =
F_72 ( F_105 ( V_401 -> V_528 ) ) ;
V_476 -> V_527 . V_473 =
F_72 ( F_104 ( V_401 -> V_528 ) ) ;
V_476 -> V_529 = F_19 ( V_530 , V_133 ) ;
if ( F_19 ( V_531 , V_133 ) ) {
V_476 -> V_532 = V_401 -> V_533 ;
V_476 -> V_534 = 1 ;
}
V_476 -> V_393 = V_401 -> V_393 ;
V_476 -> V_535 =
F_19 ( V_536 , V_133 ) ;
V_476 -> V_537 =
F_76 ( V_401 -> V_538 ) ;
V_476 -> V_539 =
F_76 ( V_401 -> V_540 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_423 * V_61 )
{
F_218 ( V_2 , V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_541 ,
& V_61 -> V_542 ,
& V_422 -> V_401 . V_425 . V_133 ) ;
F_219 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_543 ,
& V_61 -> V_544 ,
& V_422 -> V_401 . V_425 . V_133 ) ;
F_221 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_545 ,
& V_61 -> V_426 ,
& V_422 -> V_401 . V_425 . V_133 ) ;
F_220 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_425 . V_546 ,
& V_61 -> V_426 ) ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_400 * V_422 ,
struct V_547 * V_61 )
{
F_218 ( V_2 , V_422 -> V_403 ,
& V_422 -> V_401 . V_548 . V_541 ,
& V_61 -> V_542 ,
& V_422 -> V_401 . V_548 . V_133 ) ;
F_219 ( V_422 -> V_403 ,
& V_422 -> V_401 . V_548 . V_543 ,
& V_61 -> V_544 ,
& V_422 -> V_401 . V_548 . V_133 ) ;
F_4 ( V_17 , L_84 ,
V_422 -> V_403 -> V_417 [ 0 ] ,
V_61 -> V_544 . V_470 . V_471 ,
V_61 -> V_544 . V_470 . V_473 ) ;
}
static inline int F_224 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_549 * V_550 = & V_401 -> V_401 . V_550 ;
T_7 V_551 ;
T_6 cos ;
if ( F_19 ( V_552 , & V_4 -> type ) &&
F_19 ( V_553 , & V_550 -> V_544 . V_133 ) ) {
V_551 = V_550 -> V_544 . V_554 ? 1000000 / V_550 -> V_544 . V_554 : 0 ;
F_225 ( V_2 , V_550 -> V_544 . V_465 ,
V_550 -> V_544 . V_467 ,
! F_19 ( V_555 , & V_550 -> V_544 . V_133 ) ,
V_551 ) ;
}
if ( F_19 ( V_556 , & V_4 -> type ) &&
F_19 ( V_553 , & V_550 -> V_426 . V_133 ) ) {
V_551 = V_550 -> V_426 . V_554 ? 1000000 / V_550 -> V_426 . V_554 : 0 ;
F_225 ( V_2 , V_550 -> V_426 . V_465 ,
V_550 -> V_426 . V_467 ,
! F_19 ( V_555 , & V_550 -> V_426 . V_133 ) ,
V_551 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_420 ; cos ++ ) {
F_4 ( V_17 , L_85 ,
V_4 -> V_417 [ cos ] , cos ) ;
F_4 ( V_17 , L_86 , V_550 -> V_557 [ cos ] ) ;
F_226 ( V_2 , V_550 -> V_557 [ cos ] , V_4 -> V_417 [ cos ] ) ;
}
V_4 -> V_407 ( V_2 , V_4 , V_558 ) ;
F_227 () ;
F_191 () ;
return 0 ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_423 * V_105 =
(struct V_423 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
int V_560 = V_561 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_222 ( V_2 , V_401 , V_105 ) ;
return F_103 ( V_2 , V_560 , V_4 -> V_417 [ V_418 ] ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_195 ) ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_423 * V_105 =
(struct V_423 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
int V_560 = V_561 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_222 ( V_2 , V_401 , V_105 ) ;
F_217 ( V_2 , V_401 , V_105 ) ;
return F_103 ( V_2 , V_560 , V_4 -> V_417 [ V_418 ] ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_195 ) ;
}
static inline int F_230 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_547 * V_105 =
(struct V_547 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
int V_560 = V_562 ;
struct V_563 * V_564 =
& V_401 -> V_401 . V_548 ;
T_6 V_565 = V_564 -> V_565 ;
if ( V_565 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_91 , V_565 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_88 ,
V_564 -> V_541 . cos ,
V_564 -> V_541 . V_445 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_223 ( V_2 , V_401 , V_105 ) ;
F_4 ( V_17 , L_89 ,
V_4 -> V_417 [ V_565 ] , V_105 -> V_542 . V_90 ,
V_105 -> V_542 . V_444 , V_105 -> V_542 . cos ) ;
return F_103 ( V_2 , V_560 , V_4 -> V_417 [ V_565 ] ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_195 ) ;
}
static void F_231 ( struct V_1 * V_2 ,
struct V_402 * V_411 ,
struct V_566 * V_401 ,
struct V_567 * V_61 )
{
V_61 -> V_90 = V_411 -> V_91 ;
V_61 -> V_92 = V_411 -> V_92 ;
V_61 -> V_455 = F_76 ( V_401 -> V_568 ) ;
V_61 -> V_513 =
F_19 ( V_569 , & V_401 -> V_570 ) ;
V_61 -> V_571 =
F_19 ( V_572 ,
& V_401 -> V_570 ) ;
V_61 -> V_515 =
F_19 ( V_573 , & V_401 -> V_570 ) ;
V_61 -> V_574 =
F_19 ( V_575 ,
& V_401 -> V_570 ) ;
V_61 -> V_576 =
F_19 ( V_577 , & V_401 -> V_570 ) ;
V_61 -> V_578 =
F_19 ( V_579 , & V_401 -> V_570 ) ;
V_61 -> V_442 =
F_19 ( V_580 , & V_401 -> V_570 ) ;
V_61 -> V_581 =
F_19 ( V_582 , & V_401 -> V_570 ) ;
V_61 -> V_583 =
F_19 ( V_584 , & V_401 -> V_570 ) ;
V_61 -> V_585 =
F_19 ( V_586 ,
& V_401 -> V_570 ) ;
V_61 -> V_587 =
F_19 ( V_588 ,
& V_401 -> V_570 ) ;
V_61 -> V_535 =
F_19 ( V_589 , & V_401 -> V_570 ) ;
V_61 -> V_537 = F_76 ( V_401 -> V_538 ) ;
V_61 -> V_539 = F_76 ( V_401 -> V_540 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
struct V_567 * V_105 =
(struct V_567 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
struct V_566 * V_590 =
& V_401 -> V_401 . V_591 ;
T_6 V_565 = V_590 -> V_565 ;
if ( V_565 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_91 , V_565 ) ;
return - V_62 ;
}
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_231 ( V_2 , V_4 , V_590 , V_105 ) ;
return F_103 ( V_2 , V_592 ,
V_4 -> V_417 [ V_565 ] , F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_195 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_566 * V_591 = & V_401 -> V_401 . V_591 ;
memset ( V_591 , 0 , sizeof( * V_591 ) ) ;
F_87 ( V_582 , & V_591 -> V_570 ) ;
return F_232 ( V_2 , V_401 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_566 * V_591 = & V_401 -> V_401 . V_591 ;
memset ( V_591 , 0 , sizeof( * V_591 ) ) ;
F_87 ( V_580 , & V_591 -> V_570 ) ;
F_87 ( V_582 , & V_591 -> V_570 ) ;
return F_232 ( V_2 , V_401 ) ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
return - 1 ;
}
static inline int F_236 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
return F_103 ( V_2 , V_593 ,
V_4 -> V_417 [ V_418 ] , 0 , V_4 -> V_91 ,
V_195 ) ;
}
static inline int F_237 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
T_6 V_594 = V_401 -> V_401 . V_595 . V_565 ;
if ( V_594 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_91 , V_594 ) ;
return - V_62 ;
}
return F_103 ( V_2 , V_596 ,
V_4 -> V_417 [ V_594 ] , 0 , 0 , V_597 ) ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
T_6 V_565 = V_401 -> V_401 . V_598 . V_565 ;
if ( V_565 >= V_4 -> V_420 ) {
F_39 ( L_87 ,
V_4 -> V_91 , V_565 ) ;
return - V_62 ;
}
return F_103 ( V_2 , V_599 ,
V_4 -> V_417 [ V_565 ] , 0 , 0 , V_195 ) ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_402 * V_4 = V_401 -> V_403 ;
return F_103 ( V_2 , V_600 ,
V_4 -> V_417 [ V_418 ] , 0 , 0 ,
V_195 ) ;
}
static inline int F_240 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_106 ) {
case V_558 :
return F_224 ( V_2 , V_401 ) ;
case V_601 :
return F_230 ( V_2 , V_401 ) ;
case V_414 :
return F_233 ( V_2 , V_401 ) ;
case V_413 :
return F_234 ( V_2 , V_401 ) ;
case V_415 :
return F_232 ( V_2 , V_401 ) ;
case V_602 :
return F_235 ( V_2 , V_401 ) ;
case V_603 :
return F_236 ( V_2 , V_401 ) ;
case V_604 :
return F_237 ( V_2 , V_401 ) ;
case V_605 :
return F_238 ( V_2 , V_401 ) ;
case V_606 :
return F_239 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_106 ) ;
return - V_62 ;
}
}
static int F_241 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_106 ) {
case V_607 :
return F_228 ( V_2 , V_401 ) ;
case V_558 :
case V_601 :
case V_414 :
case V_413 :
case V_415 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
return F_240 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_106 ) ;
return - V_62 ;
}
}
static int F_242 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
switch ( V_401 -> V_106 ) {
case V_607 :
return F_229 ( V_2 , V_401 ) ;
case V_558 :
case V_601 :
case V_414 :
case V_413 :
case V_415 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
return F_240 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_106 ) ;
return - V_62 ;
}
}
static int F_243 ( struct V_1 * V_2 ,
struct V_402 * V_4 ,
struct V_400 * V_401 )
{
enum V_608 V_33 = V_4 -> V_33 , V_409 = V_410 ;
enum V_412 V_106 = V_401 -> V_106 ;
struct V_566 * V_590 =
& V_401 -> V_401 . V_591 ;
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
case V_609 :
if ( V_106 == V_558 )
V_409 = V_610 ;
break;
case V_610 :
if ( V_106 == V_607 ) {
if ( F_19 ( V_443 ,
& V_401 -> V_401 . V_425 . V_133 ) )
V_409 = V_611 ;
else
V_409 = V_612 ;
}
break;
case V_611 :
if ( V_106 == V_414 )
V_409 = V_612 ;
else if ( ( V_106 == V_606 ) ||
( V_106 == V_602 ) )
V_409 = V_611 ;
else if ( V_106 == V_601 ) {
V_409 = V_613 ;
V_419 = 1 ;
}
else if ( V_106 == V_603 )
V_409 = V_614 ;
else if ( V_106 == V_415 ) {
if ( F_19 ( V_582 ,
& V_590 -> V_570 ) &&
! F_19 ( V_580 ,
& V_590 -> V_570 ) )
V_409 = V_612 ;
else
V_409 = V_611 ;
}
break;
case V_613 :
if ( V_106 == V_605 )
V_409 = V_615 ;
else if ( V_106 == V_601 ) {
V_409 = V_613 ;
V_419 = V_4 -> V_421 + 1 ;
}
else if ( ( V_106 == V_606 ) ||
( V_106 == V_602 ) )
V_409 = V_613 ;
else if ( V_106 == V_415 ) {
if ( F_19 ( V_582 ,
& V_590 -> V_570 ) &&
! F_19 ( V_580 ,
& V_590 -> V_570 ) )
V_409 = V_612 ;
else
V_409 = V_613 ;
}
break;
case V_615 :
if ( V_106 == V_604 ) {
V_419 = V_4 -> V_421 - 1 ;
if ( V_419 == 0 )
V_409 = V_611 ;
else
V_409 = V_613 ;
}
break;
case V_612 :
if ( V_106 == V_413 )
V_409 = V_611 ;
else if ( ( V_106 == V_606 ) ||
( V_106 == V_602 ) )
V_409 = V_612 ;
else if ( V_106 == V_603 )
V_409 = V_614 ;
else if ( V_106 == V_415 ) {
if ( F_19 ( V_582 ,
& V_590 -> V_570 ) &&
F_19 ( V_580 ,
& V_590 -> V_570 ) ) {
if ( V_4 -> V_421 == 0 )
V_409 = V_611 ;
else
V_409 = V_613 ;
} else
V_409 = V_612 ;
}
break;
case V_614 :
if ( V_106 == V_605 )
V_409 = V_616 ;
break;
case V_616 :
if ( V_106 == V_604 )
V_409 = V_609 ;
break;
default:
F_39 ( L_91 , V_33 ) ;
}
if ( V_409 != V_410 ) {
F_4 ( V_17 , L_92 ,
V_33 , V_106 , V_409 ) ;
V_4 -> V_409 = V_409 ;
V_4 -> V_419 = V_419 ;
return 0 ;
}
F_4 ( V_17 , L_93 , V_33 , V_106 ) ;
return - V_62 ;
}
void F_244 ( struct V_1 * V_2 ,
struct V_402 * V_411 ,
T_6 V_91 , V_59 * V_417 , T_6 V_617 , T_6 V_92 ,
void * V_105 ,
T_8 V_194 , unsigned long type )
{
memset ( V_411 , 0 , sizeof( * V_411 ) ) ;
F_245 ( V_618 < V_617 ) ;
memcpy ( V_411 -> V_417 , V_417 , sizeof( V_411 -> V_417 [ 0 ] ) * V_617 ) ;
V_411 -> V_420 = V_617 ;
V_411 -> V_91 = V_91 ;
V_411 -> V_92 = V_92 ;
V_411 -> V_105 = V_105 ;
V_411 -> V_194 = V_194 ;
V_411 -> type = type ;
V_411 -> V_409 = V_410 ;
if ( F_113 ( V_2 ) )
V_411 -> V_408 = F_241 ;
else
V_411 -> V_408 = F_242 ;
V_411 -> V_406 = F_243 ;
V_411 -> V_407 = F_214 ;
V_411 -> V_173 = F_213 ;
V_411 -> V_190 = F_212 ;
}
int F_246 ( struct V_1 * V_2 ,
struct V_402 * V_411 )
{
switch ( V_411 -> V_33 ) {
case V_611 :
case V_613 :
return V_619 ;
case V_609 :
case V_610 :
case V_615 :
case V_612 :
case V_614 :
case V_616 :
case V_620 :
return V_621 ;
default:
return - V_62 ;
}
}
enum V_622 F_247 ( struct V_1 * V_2 ,
struct V_623 * V_4 )
{
if ( V_4 -> V_405 )
return V_624 ;
F_248 () ;
return V_4 -> V_33 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_623 * V_4 ,
enum V_625 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_405 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
struct V_623 * V_4 ,
enum V_625 V_106 )
{
unsigned long V_416 = V_4 -> V_405 ;
if ( ! F_215 ( V_106 , & V_416 ) ) {
F_39 ( L_94 ,
V_106 , F_251 ( V_2 ) , V_4 -> V_33 ,
V_416 , V_4 -> V_409 ) ;
return - V_62 ;
}
F_4 ( V_17 ,
L_95 ,
V_106 , F_251 ( V_2 ) , V_4 -> V_409 ) ;
V_4 -> V_33 = V_4 -> V_409 ;
V_4 -> V_409 = V_624 ;
F_216 () ;
F_30 ( V_106 , & V_4 -> V_405 ) ;
F_31 () ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_623 * V_4 ,
enum V_625 V_106 )
{
int V_22 = F_250 ( V_2 , V_4 , V_106 ) ;
return V_22 ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_623 * V_4 ,
struct V_626 * V_401 )
{
enum V_622 V_33 = V_4 -> V_33 , V_409 = V_624 ;
enum V_625 V_106 = V_401 -> V_106 ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) ) {
V_4 -> V_405 = 0 ;
V_4 -> V_409 = V_624 ;
}
if ( V_4 -> V_405 )
return - V_37 ;
switch ( V_33 ) {
case V_627 :
if ( V_106 == V_628 )
V_409 = V_629 ;
break;
case V_629 :
if ( V_106 == V_630 )
V_409 = V_631 ;
else if ( V_106 == V_632 )
V_409 = V_627 ;
break;
case V_631 :
if ( V_106 == V_633 )
V_409 = V_629 ;
else if ( ( V_106 == V_634 ) &&
( ! F_19 ( V_633 , & V_4 -> V_405 ) ) )
V_409 = V_631 ;
else if ( ( V_106 == V_635 ) &&
( ! F_19 ( V_633 , & V_4 -> V_405 ) ) )
V_409 = V_631 ;
else if ( ( V_106 == V_636 ) &&
( ! F_19 ( V_633 , & V_4 -> V_405 ) ) )
V_409 = V_631 ;
else if ( V_106 == V_637 )
V_409 = V_638 ;
break;
case V_638 :
if ( ( V_106 == V_636 ) &&
( ! F_19 ( V_633 , & V_4 -> V_405 ) ) )
V_409 = V_638 ;
else if ( V_106 == V_639 )
V_409 = V_631 ;
break;
default:
F_39 ( L_96 , V_33 ) ;
}
if ( V_409 != V_624 ) {
F_4 ( V_17 , L_97 ,
V_33 , V_106 , V_409 ) ;
V_4 -> V_409 = V_409 ;
return 0 ;
}
F_4 ( V_17 , L_98 ,
V_33 , V_106 ) ;
return - V_62 ;
}
static inline int F_254 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
return V_641 -> V_642 ( V_2 ) ;
}
static inline int F_255 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
int V_22 = V_641 -> V_643 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_254 ( V_2 , V_641 ) ;
}
static inline int F_256 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
int V_22 = V_641 -> V_644 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_255 ( V_2 , V_641 ) ;
}
static inline int F_257 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
int V_22 = V_641 -> V_645 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_255 ( V_2 , V_641 ) ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
V_59 V_646 = V_401 -> V_401 . V_647 . V_648 ;
struct V_623 * V_4 = V_401 -> V_649 ;
const struct V_640 * V_641 = V_4 -> V_641 ;
int V_22 = 0 ;
F_4 ( V_17 , L_99 ,
F_259 ( V_2 ) , V_646 ) ;
V_22 = V_641 -> V_650 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_641 -> V_651 ( V_2 ) ;
if ( V_22 ) {
F_39 ( L_100 ) ;
goto V_652;
}
switch ( V_646 ) {
case V_653 :
V_22 = F_256 ( V_2 , V_641 ) ;
if ( V_22 )
goto V_652;
break;
case V_654 :
V_22 = F_257 ( V_2 , V_641 ) ;
if ( V_22 )
goto V_652;
break;
case V_655 :
V_22 = F_255 ( V_2 , V_641 ) ;
if ( V_22 )
goto V_652;
break;
case V_656 :
V_22 = F_254 ( V_2 , V_641 ) ;
if ( V_22 )
goto V_652;
break;
default:
F_39 ( L_101 , V_646 ) ;
V_22 = - V_62 ;
}
V_652:
V_641 -> V_657 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_407 ( V_2 , V_4 , V_628 ) ;
return V_22 ;
}
static inline void F_260 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
V_641 -> V_658 ( V_2 ) ;
}
static inline void F_261 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
V_641 -> V_659 ( V_2 ) ;
F_260 ( V_2 , V_641 ) ;
}
static inline void F_262 ( struct V_1 * V_2 ,
const struct V_640 * V_641 )
{
F_261 ( V_2 , V_641 ) ;
V_641 -> V_660 ( V_2 ) ;
}
static inline int F_263 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
V_59 V_661 = V_401 -> V_401 . V_662 . V_661 ;
struct V_623 * V_4 = V_401 -> V_649 ;
const struct V_640 * V_641 = V_4 -> V_641 ;
F_4 ( V_17 , L_102 , F_259 ( V_2 ) ,
V_661 ) ;
switch ( V_661 ) {
case V_663 :
F_262 ( V_2 , V_641 ) ;
break;
case V_664 :
F_261 ( V_2 , V_641 ) ;
break;
case V_665 :
F_260 ( V_2 , V_641 ) ;
break;
default:
F_39 ( L_103 ,
V_661 ) ;
break;
}
V_4 -> V_407 ( V_2 , V_4 , V_632 ) ;
return 0 ;
}
static inline int F_264 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
struct V_666 * V_105 =
(struct V_666 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
struct V_667 * V_668 = & V_401 -> V_401 . V_669 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_670 = ( T_6 ) V_668 -> V_671 ;
V_105 -> V_672 = F_76 ( V_668 -> V_672 ) ;
V_105 -> V_673 = F_265 ( V_2 ) ;
V_105 -> V_674 = V_668 -> V_674 ;
return F_103 ( V_2 , V_675 , 0 ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_597 ) ;
}
static inline int F_266 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
struct V_676 * V_105 =
(struct V_676 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
struct V_677 * V_678 =
& V_401 -> V_401 . V_679 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_680 = 1 ;
V_105 -> V_681 = V_678 -> V_682 ;
V_105 -> V_99 = V_683 ;
return F_103 ( V_2 , V_684 , 0 ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_597 ) ;
}
static inline int F_267 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
struct V_676 * V_105 =
(struct V_676 * ) V_4 -> V_685 ;
T_8 V_559 = V_4 -> V_686 ;
struct V_687 * V_688 =
& V_401 -> V_401 . V_689 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_690 = 1 ;
V_105 -> V_691 = F_76 ( V_688 -> V_691 ) ;
V_105 -> V_692 = 1 ;
V_105 -> V_693 =
F_76 ( V_688 -> V_693 ) ;
V_105 -> V_694 = 1 ;
V_105 -> V_695 = V_688 -> V_695 ;
V_105 -> V_99 = V_696 ;
F_4 ( V_17 ,
L_104 ,
V_105 -> V_691 ,
V_105 -> V_693 , V_105 -> V_695 ) ;
return F_103 ( V_2 , V_684 , 0 ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_597 ) ;
}
static
inline int F_268 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
struct V_697 * V_105 =
(struct V_697 * ) V_4 -> V_685 ;
struct V_698 * V_699 =
& V_401 -> V_401 . V_700 ;
T_11 * V_701 = ( T_11 * ) V_105 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_702 = F_76 ( V_699 -> V_702 ) ;
V_105 -> V_703 = V_699 -> V_703 ;
V_105 -> V_704 = V_699 -> V_704 ;
V_105 -> V_705 = V_699 -> V_705 ;
V_105 -> V_99 = V_699 -> V_704 ;
F_4 ( V_17 , L_105 ,
V_105 -> V_704 , V_105 -> V_702 ,
V_105 -> V_703 , V_105 -> V_705 ) ;
return F_103 ( V_2 , V_706 , 0 ,
F_104 ( * V_701 ) , F_105 ( * V_701 ) ,
V_597 ) ;
}
static inline int F_269 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
return F_103 ( V_2 , V_707 , 0 , 0 , 0 ,
V_597 ) ;
}
static inline int F_270 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
return F_103 ( V_2 , V_708 , 0 , 0 , 0 ,
V_597 ) ;
}
static inline int F_271 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
struct V_709 * V_105 =
(struct V_709 * ) V_4 -> V_105 ;
T_8 V_559 = V_4 -> V_194 ;
struct V_710 * V_711 =
& V_401 -> V_401 . V_712 ;
int V_283 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_713 = V_711 -> V_713 ;
V_105 -> V_714 = V_711 -> V_714 ;
V_105 -> V_715 = V_711 -> V_715 ;
for ( V_283 = 0 ; V_283 < F_272 ( V_105 -> V_716 ) ; V_283 ++ )
V_105 -> V_716 [ V_283 ] =
V_711 -> V_716 [ V_283 ] ;
return F_103 ( V_2 , V_717 , 0 ,
F_104 ( V_559 ) ,
F_105 ( V_559 ) , V_597 ) ;
}
static int F_273 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
switch ( V_401 -> V_106 ) {
case V_628 :
return F_258 ( V_2 , V_401 ) ;
case V_630 :
return F_264 ( V_2 , V_401 ) ;
case V_633 :
return F_269 ( V_2 , V_401 ) ;
case V_632 :
return F_263 ( V_2 , V_401 ) ;
case V_634 :
return F_267 ( V_2 , V_401 ) ;
case V_635 :
return F_268 ( V_2 , V_401 ) ;
case V_637 :
return F_270 ( V_2 , V_401 ) ;
case V_639 :
return F_271 ( V_2 , V_401 ) ;
case V_636 :
return F_266 ( V_2 , V_401 ) ;
default:
F_39 ( L_49 , V_401 -> V_106 ) ;
return - V_62 ;
}
}
void F_274 ( struct V_1 * V_2 ,
struct V_623 * V_411 ,
void * V_105 , T_8 V_194 ,
void * V_685 , T_8 V_686 ,
struct V_640 * V_718 )
{
memset ( V_411 , 0 , sizeof( * V_411 ) ) ;
F_275 ( & V_411 -> V_719 ) ;
V_411 -> V_105 = V_105 ;
V_411 -> V_194 = V_194 ;
V_411 -> V_685 = V_685 ;
V_411 -> V_686 = V_686 ;
V_411 -> V_408 = F_273 ;
V_411 -> V_406 = F_253 ;
V_411 -> V_407 = F_252 ;
V_411 -> V_173 = F_249 ;
V_411 -> V_641 = V_718 ;
}
int F_276 ( struct V_1 * V_2 ,
struct V_626 * V_401 )
{
struct V_623 * V_4 = V_401 -> V_649 ;
int V_22 , V_20 = 300 ;
enum V_625 V_106 = V_401 -> V_106 ;
unsigned long * V_405 = & V_4 -> V_405 ;
F_277 ( & V_4 -> V_719 ) ;
V_22 = V_4 -> V_406 ( V_2 , V_4 , V_401 ) ;
if ( ( V_22 == - V_37 ) &&
( F_19 ( V_720 , & V_401 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_278 ( & V_4 -> V_719 ) ;
F_279 ( 10 ) ;
F_277 ( & V_4 -> V_719 ) ;
V_22 = V_4 -> V_406 ( V_2 , V_4 , V_401 ) ;
}
if ( V_22 == - V_37 ) {
F_278 ( & V_4 -> V_719 ) ;
F_39 ( L_106 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_278 ( & V_4 -> V_719 ) ;
return V_22 ;
}
F_33 ( V_106 , V_405 ) ;
if ( F_19 ( V_28 , & V_401 -> V_25 ) ) {
F_250 ( V_2 , V_4 , V_106 ) ;
F_278 ( & V_4 -> V_719 ) ;
} else {
V_22 = V_4 -> V_408 ( V_2 , V_401 ) ;
F_278 ( & V_4 -> V_719 ) ;
if ( V_22 ) {
V_4 -> V_409 = V_624 ;
F_30 ( V_106 , V_405 ) ;
F_31 () ;
return V_22 ;
}
if ( F_19 ( V_199 , & V_401 -> V_25 ) ) {
V_22 = V_4 -> V_173 ( V_2 , V_4 , V_106 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_19 ( V_106 , V_405 ) ;
}
