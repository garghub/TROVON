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
F_12 ( L_3 , V_22 ) ;
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
F_4 ( V_17 , L_4 ) ;
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
F_4 ( V_17 , L_5 ) ;
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
F_4 ( V_17 , L_6 , V_33 ) ;
F_36 () ;
while ( V_20 -- ) {
if ( ! F_20 ( V_33 , V_34 ) ) {
#ifdef F_37
F_4 ( V_17 , L_7 , 5000 - V_20 ) ;
#endif
return 0 ;
}
F_38 ( 1000 , 1000 ) ;
if ( V_2 -> V_35 )
return - V_36 ;
}
F_12 ( L_8 , V_33 ) ;
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
F_4 ( V_17 , L_9 ,
V_54 , V_53 , V_52 -> V_56 . V_57 . V_57 ) ;
}
}
return V_54 * V_58 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_60 * V_61 )
{
struct V_51 * V_52 ;
F_4 ( V_17 , L_10 , V_61 -> V_57 . V_57 ) ;
if ( ! F_54 ( V_61 -> V_57 . V_57 ) )
return - V_62 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_61 -> V_57 . V_57 , V_52 -> V_56 . V_57 . V_57 , V_58 ) )
return - V_63 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
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
static int F_56 ( struct V_1 * V_2 ,
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
F_57 ( struct V_1 * V_2 ,
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
F_58 ( struct V_1 * V_2 ,
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
F_59 ( struct V_1 * V_2 ,
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
static bool F_60 ( struct V_1 * V_2 ,
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
static bool F_61 (
struct V_1 * V_2 ,
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
void F_63 ( struct V_1 * V_2 ,
bool V_77 , unsigned char * V_78 , int V_79 )
{
V_59 V_80 [ 2 ] ;
V_59 V_81 = F_64 ( V_2 ) ? V_82 :
V_83 ;
if ( ! F_65 ( V_2 ) && ! F_66 ( V_2 ) )
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
F_67 ( V_2 , V_81 , V_80 , 2 ) ;
}
F_68 ( V_2 , ( F_64 ( V_2 ) ? V_85 :
V_86 ) + 4 * V_79 , V_77 ) ;
}
static inline void F_69 ( struct V_1 * V_2 ,
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
static inline void F_70 ( V_59 V_96 , int type ,
struct V_97 * V_89 , int V_98 )
{
V_89 -> V_99 = ( V_96 & V_100 ) | ( type << V_101 ) ;
V_89 -> V_98 = ( T_6 ) V_98 ;
}
static void F_71 ( struct V_1 * V_2 ,
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
F_63 ( V_2 , V_77 , V_57 ,
V_117 ) ;
}
if ( V_102 == 0 )
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_69 ( V_2 , V_4 , V_77 , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_4 ( V_17 , L_19 ,
( V_77 ? L_20 : L_21 ) , V_57 , V_38 -> V_91 ) ;
F_72 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_69 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_118 ,
& V_109 -> V_57 . V_119 ) ;
F_72 ( & V_109 -> V_57 . V_120 ,
& V_109 -> V_57 . V_121 ,
& V_109 -> V_57 . V_122 , V_57 ) ;
}
F_70 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 ,
struct V_124 * V_89 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_89 -> V_126 = 1 ;
V_89 -> V_40 = ( T_6 ) V_103 ;
V_89 -> V_90 = 0xff ;
V_89 -> V_99 = ( ( V_125 -> V_96 & V_100 ) | ( type << V_101 ) ) ;
}
static inline void F_74 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_77 , int V_87 , T_6 * V_57 ,
T_7 V_127 , struct V_128 * V_129 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
V_59 V_130 = ( 1 << V_125 -> V_91 ) ;
V_129 -> V_131 = F_75 ( V_130 ) ;
V_129 -> V_132 = V_125 -> V_92 ;
V_129 -> V_127 = F_76 ( V_127 ) ;
if ( V_77 ) {
F_77 ( V_129 -> V_133 , V_134 ,
V_135 ) ;
F_77 ( V_129 -> V_133 ,
V_136 , V_87 ) ;
F_72 ( & V_129 -> V_137 ,
& V_129 -> V_138 ,
& V_129 -> V_139 , V_57 ) ;
} else
F_77 ( V_129 -> V_133 , V_134 ,
V_140 ) ;
}
static inline void F_78 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_103 , bool V_77 ,
T_6 * V_57 , T_7 V_127 , int V_87 , struct V_141 * V_142 )
{
struct V_128 * V_129 = & V_142 -> V_143 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_73 ( V_2 , V_4 , type , V_103 ,
& V_142 -> V_89 ) ;
F_74 ( V_2 , V_4 , V_77 , V_87 , V_57 , V_127 ,
V_129 ) ;
F_4 ( V_17 , L_22 ,
( V_77 ? L_23 : L_24 ) ,
V_57 , V_38 -> V_91 , V_103 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
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
F_78 ( V_2 , V_4 , V_38 -> V_33 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_57 . V_57 , 0 ,
V_144 , V_142 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
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
F_69 ( V_2 , V_4 , V_77 , V_145 ,
& V_109 -> V_64 . V_119 ) ;
F_4 ( V_17 , L_25 , ( V_77 ? L_20 : L_21 ) ,
V_64 ) ;
V_109 -> V_64 . V_64 = F_76 ( V_64 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_69 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_145 ,
& V_109 -> V_64 . V_119 ) ;
V_109 -> V_64 . V_64 = F_76 ( V_64 ) ;
}
F_70 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
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
F_69 ( V_2 , V_4 , V_77 , V_146 ,
& V_109 -> V_147 . V_119 ) ;
V_109 -> V_147 . V_64 = F_76 ( V_64 ) ;
F_72 ( & V_109 -> V_147 . V_120 ,
& V_109 -> V_147 . V_121 ,
& V_109 -> V_147 . V_122 , V_57 ) ;
if ( V_106 == V_113 ) {
V_109 ++ ;
V_98 ++ ;
F_69 ( V_2 ,
V_19 -> V_107 . V_65 . V_123 ,
true , V_146 ,
& V_109 -> V_147 . V_119 ) ;
V_109 -> V_147 . V_64 = F_76 ( V_64 ) ;
F_72 ( & V_109 -> V_147 . V_120 ,
& V_109 -> V_147 . V_121 ,
& V_109 -> V_147 . V_122 , V_57 ) ;
}
F_70 ( V_38 -> V_96 , V_38 -> V_33 , & V_61 -> V_119 ,
V_98 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
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
F_78 ( V_2 , V_4 , V_148 ,
V_103 , V_77 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_57 ,
V_19 -> V_107 . V_65 . V_56 . V_65 . V_64 ,
V_149 , V_142 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_150 * V_151 ,
struct V_51 * * V_152 )
{
struct V_51 * V_52 ;
struct V_39 * V_4 = V_151 -> V_153 ;
if ( F_15 ( & V_4 -> V_154 ) ) {
* V_152 = NULL ;
return 0 ;
}
if ( * V_152 == NULL )
* V_152 = F_16 ( & V_4 -> V_154 ,
struct V_51 ,
V_24 ) ;
else
* V_152 = F_84 ( * V_152 , V_24 ) ;
V_52 = * V_152 ;
if ( F_85 ( & V_52 -> V_24 , & V_4 -> V_154 ) )
* V_152 = NULL ;
memcpy ( & V_151 -> V_155 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_151 -> V_155 . V_106 = V_111 ;
V_151 -> V_155 . V_112 = V_52 -> V_112 ;
F_86 ( V_156 , & V_151 -> V_25 ) ;
return F_87 ( V_2 , V_151 ) ;
}
static struct V_18 * F_88 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_157 * V_61 = & V_19 -> V_107 . V_65 . V_56 . V_57 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_57 , V_61 ,
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
struct V_158 * V_61 = & V_19 -> V_107 . V_65 . V_56 . V_64 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_64 , V_61 ,
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
struct V_159 * V_61 =
& V_19 -> V_107 . V_65 . V_56 . V_65 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_107 . V_65 . V_56 . V_65 , V_61 ,
sizeof( * V_61 ) ) &&
( V_52 -> V_107 . V_65 . V_106 == V_19 -> V_107 . V_65 . V_106 ) )
return V_52 ;
return NULL ;
}
static inline int F_91 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_160 -> V_65 ;
struct V_3 * V_161 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_69 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_26 ) ;
return V_22 ;
}
if ( V_161 -> V_11 ( V_161 , V_19 ) ) {
F_4 ( V_17 , L_27 ) ;
return - V_63 ;
}
if ( ! ( F_20 ( V_162 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_163 ( V_4 ) ) )
return - V_62 ;
return 0 ;
}
static inline int F_92 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_160 -> V_65 ;
struct V_51 * V_52 ;
struct V_3 * V_161 = & V_4 -> V_12 ;
struct V_18 V_164 ;
V_52 = V_4 -> V_68 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
if ( ! V_52 ) {
F_4 ( V_17 , L_28 ) ;
return - V_63 ;
}
memcpy ( & V_164 , V_19 , sizeof( V_164 ) ) ;
V_164 . V_107 . V_65 . V_106 = V_113 ;
if ( V_161 -> V_11 ( V_161 , & V_164 ) ) {
F_12 ( L_29 ) ;
return - V_62 ;
}
if ( V_161 -> V_11 ( V_161 , V_19 ) ) {
F_4 ( V_17 , L_30 ) ;
return - V_63 ;
}
if ( ! ( F_20 ( V_162 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_4 -> V_165 ( V_4 ) ) ) {
F_12 ( L_31 ) ;
return - V_62 ;
}
return 0 ;
}
static inline int F_93 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
struct V_39 * V_66 = & V_160 -> V_65 ;
struct V_39 * V_166 = V_19 -> V_107 . V_65 . V_123 ;
struct V_18 V_164 ;
struct V_3 * V_167 = & V_66 -> V_12 ;
struct V_3 * V_168 = & V_166 -> V_12 ;
if ( ! V_66 -> V_169 ( V_2 , V_66 , V_166 ,
& V_19 -> V_107 . V_65 . V_56 ) ) {
F_4 ( V_17 , L_32 ) ;
return - V_62 ;
}
memcpy ( & V_164 , V_19 , sizeof( V_164 ) ) ;
V_164 . V_107 . V_65 . V_106 = V_170 ;
if ( V_167 -> V_11 ( V_167 , & V_164 ) ) {
F_12 ( L_33 ) ;
return - V_62 ;
}
if ( V_167 -> V_11 ( V_167 , V_19 ) ) {
F_4 ( V_17 , L_29 ) ;
return - V_63 ;
}
V_164 . V_107 . V_65 . V_106 = V_111 ;
if ( V_168 -> V_11 ( V_168 , & V_164 ) ) {
F_12 ( L_34 ) ;
return - V_62 ;
}
if ( ! ( F_20 ( V_171 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_166 -> V_163 ( V_166 ) ) )
return - V_62 ;
if ( ! ( F_20 ( V_162 ,
& V_19 -> V_107 . V_65 . V_112 ) ||
V_66 -> V_165 ( V_66 ) ) ) {
V_166 -> V_165 ( V_166 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
return F_91 ( V_2 , V_160 , V_19 ) ;
case V_170 :
return F_92 ( V_2 , V_160 , V_19 ) ;
case V_113 :
return F_93 ( V_2 , V_160 , V_19 ) ;
default:
return - V_62 ;
}
}
static int F_95 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_20 ( V_162 ,
& V_19 -> V_107 . V_65 . V_112 ) )
return 0 ;
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
case V_113 :
V_22 = V_160 -> V_65 . V_165 ( & V_160 -> V_65 ) ;
break;
case V_170 :
V_22 = V_160 -> V_65 . V_163 ( & V_160 -> V_65 ) ;
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
struct V_3 * V_161 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_172 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_24 ( V_161 ) )
F_38 ( 1000 , 1000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_173 * V_174 ,
unsigned long * V_25 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 ;
F_18 ( V_2 , & V_4 -> V_12 ) ;
V_125 -> V_175 ( V_125 ) ;
if ( V_174 -> V_176 . error )
return - V_62 ;
if ( F_20 ( V_177 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_18 * V_19 )
{
struct V_18 V_178 , * V_52 ;
struct V_39 * V_4 = & V_160 -> V_65 ;
struct V_3 * V_161 = & V_4 -> V_12 ;
memcpy ( & V_178 , V_19 , sizeof( V_178 ) ) ;
switch ( V_19 -> V_107 . V_65 . V_106 ) {
case V_111 :
V_178 . V_107 . V_65 . V_106 = V_170 ;
break;
case V_170 :
V_178 . V_107 . V_65 . V_106 = V_111 ;
break;
default:
return 0 ;
}
V_52 = V_161 -> V_11 ( V_161 , & V_178 ) ;
if ( V_52 ) {
if ( ! F_20 ( V_162 ,
& V_52 -> V_107 . V_65 . V_112 ) ) {
if ( ( V_178 . V_107 . V_65 . V_106 ==
V_111 ) && ! V_4 -> V_165 ( V_4 ) ) {
F_12 ( L_35 ) ;
return - V_62 ;
} else if ( ! V_4 -> V_163 ( V_4 ) ) {
F_12 ( L_36 ) ;
return - V_62 ;
}
}
F_4 ( V_17 , L_37 ,
( V_19 -> V_107 . V_65 . V_106 == V_111 ) ?
L_17 : L_38 ) ;
F_17 ( & V_52 -> V_24 ) ;
F_5 ( V_2 , V_52 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_99 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_51 * * V_179 )
{
int V_106 = V_19 -> V_107 . V_65 . V_106 ;
struct V_51 * V_180 ;
if ( ! V_21 &&
( ( V_106 == V_111 ) || ( V_106 == V_113 ) ) ) {
V_180 = F_26 ( sizeof( * V_180 ) , V_31 ) ;
if ( ! V_180 )
return - V_181 ;
if ( ! V_4 -> V_182 ( V_4 , & V_180 -> V_103 ) ) {
F_21 ( 1 ) ;
F_6 ( V_180 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_39 , V_180 -> V_103 ) ;
memcpy ( & V_180 -> V_56 , & V_19 -> V_107 . V_65 . V_56 ,
sizeof( V_180 -> V_56 ) ) ;
V_180 -> V_112 =
V_19 -> V_107 . V_65 . V_112 ;
} else
V_180 = V_4 -> V_68 ( V_2 , V_4 , & V_19 -> V_107 . V_65 . V_56 ) ;
* V_179 = V_180 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
union V_6 * V_160 ,
struct V_183 * V_184 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_160 -> V_65 , * V_185 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 , V_186 = 0 ;
bool V_21 = F_20 ( V_156 , V_25 ) ;
bool V_187 = F_20 ( V_28 , V_25 ) ;
struct V_51 * V_180 ;
int V_106 ;
if ( ! V_187 ) {
F_21 ( V_125 -> V_188 ( V_125 ) ) ;
V_125 -> V_189 ( V_125 ) ;
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( V_106 == V_113 )
V_185 = V_19 -> V_107 . V_65 . V_123 ;
else
V_185 = V_4 ;
V_22 = F_99 ( V_2 , V_185 ,
V_19 , V_21 ,
& V_180 ) ;
if ( V_22 )
goto V_190;
F_21 ( ! V_180 ) ;
if ( ! V_21 &&
( ( V_106 == V_111 ) ||
( V_106 == V_113 ) ) )
F_101 ( & V_180 -> V_24 , & V_185 -> V_154 ) ;
V_4 -> V_191 ( V_2 , V_4 , V_19 , V_186 ,
V_180 -> V_103 ) ;
if ( V_106 == V_113 )
V_186 += 2 ;
else
V_186 ++ ;
}
V_22 = F_102 ( V_2 , V_4 -> V_192 , V_125 -> V_96 ,
F_103 ( V_125 -> V_193 ) ,
F_104 ( V_125 -> V_193 ) ,
V_194 ) ;
if ( V_22 )
goto V_190;
}
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( ( V_106 == V_170 ) ||
( V_106 == V_113 ) ) {
V_180 = V_4 -> V_68 ( V_2 , V_4 ,
& V_19 -> V_107 . V_65 . V_56 ) ;
F_21 ( ! V_180 ) ;
V_4 -> V_195 ( V_4 , V_180 -> V_103 ) ;
F_17 ( & V_180 -> V_24 ) ;
F_6 ( V_180 ) ;
}
}
if ( ! V_187 )
return 1 ;
else
return 0 ;
V_190:
V_125 -> V_175 ( V_125 ) ;
F_9 (elem, exe_chunk, link) {
V_106 = V_19 -> V_107 . V_65 . V_106 ;
if ( V_106 == V_113 )
V_185 = V_19 -> V_107 . V_65 . V_123 ;
else
V_185 = V_4 ;
if ( ! V_21 &&
( ( V_106 == V_111 ) ||
( V_106 == V_113 ) ) ) {
V_180 = V_4 -> V_68 ( V_2 , V_185 ,
& V_19 -> V_107 . V_65 . V_56 ) ;
if ( V_180 ) {
F_17 ( & V_180 -> V_24 ) ;
F_6 ( V_180 ) ;
}
}
}
return V_22 ;
}
static inline int F_105 (
struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_151 -> V_153 ;
bool V_21 = F_20 ( V_156 , & V_151 -> V_25 ) ;
V_19 = F_25 ( V_2 ) ;
if ( ! V_19 )
return - V_181 ;
switch ( V_151 -> V_155 . V_106 ) {
case V_113 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_107 . V_65 , & V_151 -> V_155 , sizeof( V_151 -> V_155 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_87 (
struct V_1 * V_2 ,
struct V_150 * V_151 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_151 -> V_153 ;
unsigned long * V_25 = & V_151 -> V_25 ;
bool V_196 = F_20 ( V_177 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_196 ) {
V_22 = F_105 ( V_2 , V_151 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_20 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_40 ) ;
V_38 -> V_175 ( V_38 ) ;
}
if ( V_196 || F_20 ( V_197 , V_25 ) ||
F_20 ( V_198 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_20 ( V_198 , & V_151 -> V_25 ) ) {
int V_199 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_199 -- ) {
V_22 = V_38 -> V_172 ( V_2 , V_38 ) ;
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
static int F_106 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_112 ,
unsigned long * V_25 )
{
struct V_51 * V_52 = NULL ;
int V_22 = 0 ;
struct V_150 V_151 ;
struct V_3 * V_161 = & V_4 -> V_12 ;
struct V_18 * V_200 , * V_201 ;
F_8 ( & V_161 -> V_14 ) ;
F_107 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_200 -> V_107 . V_65 . V_112 ==
* V_112 ) {
V_22 = V_161 -> remove ( V_2 , V_161 -> V_7 , V_200 ) ;
if ( V_22 ) {
F_12 ( L_41 ) ;
F_10 ( & V_161 -> V_14 ) ;
return V_22 ;
}
F_17 ( & V_200 -> V_24 ) ;
}
}
F_10 ( & V_161 -> V_14 ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_153 = V_4 ;
V_151 . V_25 = * V_25 ;
V_151 . V_155 . V_106 = V_170 ;
F_108 ( V_198 , & V_151 . V_25 ) ;
F_108 ( V_197 , & V_151 . V_25 ) ;
F_108 ( V_177 , & V_151 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_52 -> V_112 == * V_112 ) {
V_151 . V_155 . V_112 = V_52 -> V_112 ;
memcpy ( & V_151 . V_155 . V_56 , & V_52 -> V_56 , sizeof( V_52 -> V_56 ) ) ;
V_22 = F_87 ( V_2 , & V_151 ) ;
if ( V_22 < 0 ) {
F_12 ( L_42 ) ;
return V_22 ;
}
}
}
V_151 . V_25 = * V_25 ;
F_86 ( V_177 , & V_151 . V_25 ) ;
return F_87 ( V_2 , & V_151 ) ;
}
static inline void F_109 ( struct V_32 * V_38 , T_6 V_91 ,
V_59 V_96 , T_6 V_92 , void * V_105 , T_8 V_193 , int V_33 ,
unsigned long * V_34 , T_9 type )
{
V_38 -> V_92 = V_92 ;
V_38 -> V_96 = V_96 ;
V_38 -> V_91 = V_91 ;
V_38 -> V_105 = V_105 ;
V_38 -> V_193 = V_193 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_71 = type ;
V_38 -> V_188 = F_27 ;
V_38 -> V_175 = F_28 ;
V_38 -> V_189 = F_32 ;
V_38 -> V_172 = F_40 ;
}
static inline void F_110 ( struct V_39 * V_4 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 , T_8 V_193 ,
int V_33 , unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_154 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_202 = F_106 ;
V_4 -> V_21 = F_83 ;
V_4 -> V_203 = F_97 ;
V_4 -> V_204 = F_96 ;
F_109 ( & V_4 -> V_38 , V_91 , V_96 , V_92 , V_105 , V_193 ,
V_33 , V_34 , type ) ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_39 * V_205 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_193 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 )
{
union V_6 * V_206 = (union V_6 * ) V_205 ;
F_110 ( V_205 , V_91 , V_96 , V_92 , V_105 ,
V_193 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_205 -> V_163 = F_42 ;
V_205 -> V_165 = F_47 ;
V_205 -> V_182 = F_41 ;
V_205 -> V_195 = F_46 ;
if ( F_112 ( V_2 ) ) {
V_205 -> V_191 = F_79 ;
V_205 -> V_68 = F_57 ;
V_205 -> V_69 = F_53 ;
V_205 -> V_169 = F_61 ;
V_205 -> V_192 = V_207 ;
F_1 ( V_2 ,
& V_205 -> V_12 , 1 , V_206 ,
F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_88 ) ;
} else {
V_205 -> V_191 = F_71 ;
V_205 -> V_68 = F_57 ;
V_205 -> V_69 = F_53 ;
V_205 -> V_169 = F_60 ;
V_205 -> V_192 =
V_208 ;
V_205 -> V_209 = F_51 ;
F_1 ( V_2 ,
& V_205 -> V_12 , V_210 ,
V_206 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_88 ) ;
}
}
void F_113 ( struct V_1 * V_2 ,
struct V_39 * V_211 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_193 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_46 )
{
union V_6 * V_206 = (union V_6 * ) V_211 ;
F_110 ( V_211 , V_91 , V_96 , V_92 , V_105 ,
V_193 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_211 -> V_163 = F_44 ;
V_211 -> V_165 = F_49 ;
V_211 -> V_182 = F_43 ;
V_211 -> V_195 = F_48 ;
if ( F_112 ( V_2 ) ) {
F_12 ( L_43 ) ;
F_114 () ;
} else {
V_211 -> V_191 = F_80 ;
V_211 -> V_68 = F_58 ;
V_211 -> V_69 = F_55 ;
V_211 -> V_169 = F_60 ;
V_211 -> V_192 =
V_208 ;
F_1 ( V_2 ,
& V_211 -> V_12 , V_210 ,
V_206 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_89 ) ;
}
}
void F_115 ( struct V_1 * V_2 ,
struct V_39 * V_153 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , void * V_105 ,
T_8 V_193 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_206 =
(union V_6 * ) V_153 ;
F_110 ( V_153 , V_91 , V_96 , V_92 , V_105 ,
V_193 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_153 -> V_163 = F_45 ;
V_153 -> V_165 = F_50 ;
V_153 -> V_182 = F_41 ;
V_153 -> V_195 = F_46 ;
if ( F_116 ( V_2 ) ) {
F_12 ( L_44 ) ;
F_114 () ;
} else if ( F_117 ( V_2 ) ) {
V_153 -> V_191 = F_82 ;
V_153 -> V_68 = F_59 ;
V_153 -> V_69 = F_56 ;
V_153 -> V_169 = F_61 ;
V_153 -> V_192 = V_207 ;
F_1 ( V_2 ,
& V_153 -> V_12 , 1 , V_206 ,
F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_90 ) ;
} else {
V_153 -> V_191 = F_81 ;
V_153 -> V_68 = F_59 ;
V_153 -> V_69 = F_56 ;
V_153 -> V_169 = F_60 ;
V_153 -> V_192 =
V_208 ;
F_1 ( V_2 ,
& V_153 -> V_12 ,
V_210 ,
V_206 , F_94 ,
F_95 ,
F_98 ,
F_100 ,
F_90 ) ;
}
}
static inline void F_118 ( struct V_1 * V_2 ,
struct V_212 * V_213 ,
T_7 V_132 )
{
T_10 V_214 = sizeof( struct V_212 ) ;
V_59 V_215 = V_216 +
F_119 ( V_132 ) ;
F_120 ( V_2 , V_215 , V_214 , ( V_59 * ) V_213 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_217 * V_151 )
{
V_59 V_218 = ( 1 << V_151 -> V_91 ) ;
struct V_212 * V_213 =
(struct V_212 * ) V_151 -> V_105 ;
T_6 V_219 = 1 , V_220 = 1 ;
T_6 V_221 = 0 , V_222 = 0 , V_223 = 0 ;
T_6 V_224 = 0 ;
if ( F_20 ( V_225 , & V_151 -> V_226 ) )
V_219 = 0 ;
if ( F_20 ( V_227 , & V_151 -> V_226 ) )
V_220 = 0 ;
if ( F_20 ( V_228 , & V_151 -> V_226 ) ) {
V_219 = 0 ;
V_221 = 1 ;
}
if ( F_20 ( V_229 , & V_151 -> V_226 ) ) {
V_220 = 0 ;
V_223 = 1 ;
}
if ( F_20 ( V_230 , & V_151 -> V_226 ) )
V_222 = 1 ;
if ( F_20 ( V_231 , & V_151 -> V_226 ) )
V_224 = 1 ;
V_213 -> V_232 = V_219 ?
V_213 -> V_232 | V_218 :
V_213 -> V_232 & ~ V_218 ;
V_213 -> V_233 = V_220 ?
V_213 -> V_233 | V_218 :
V_213 -> V_233 & ~ V_218 ;
V_213 -> V_234 = V_221 ?
V_213 -> V_234 | V_218 :
V_213 -> V_234 & ~ V_218 ;
V_213 -> V_235 = V_223 ?
V_213 -> V_235 | V_218 :
V_213 -> V_235 & ~ V_218 ;
V_213 -> V_236 = V_222 ?
V_213 -> V_236 | V_218 :
V_213 -> V_236 & ~ V_218 ;
V_213 -> V_224 = V_224 ?
V_213 -> V_224 | V_218 :
V_213 -> V_224 & ~ V_218 ;
F_4 ( V_17 , L_45
L_46 ,
V_213 -> V_232 , V_213 -> V_233 ,
V_213 -> V_234 , V_213 -> V_235 ,
V_213 -> V_236 ) ;
F_118 ( V_2 , V_213 , V_151 -> V_92 ) ;
F_30 ( V_151 -> V_33 , V_151 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_122 ( V_59 V_96 ,
struct V_97 * V_89 ,
T_6 V_98 )
{
V_89 -> V_99 = V_96 ;
V_89 -> V_98 = V_98 ;
}
static inline void F_123 ( struct V_1 * V_2 ,
unsigned long V_237 ,
struct V_238 * V_106 ,
bool V_239 )
{
T_7 V_33 ;
V_33 = V_240 |
V_241 ;
if ( V_237 ) {
if ( F_20 ( V_225 , & V_237 ) )
V_33 &= ~ V_240 ;
if ( F_20 ( V_227 , & V_237 ) )
V_33 &= ~ V_241 ;
if ( F_20 ( V_228 , & V_237 ) ) {
V_33 &= ~ V_240 ;
V_33 |= V_242 ;
}
if ( F_20 ( V_229 , & V_237 ) ) {
V_33 |= V_243 ;
V_33 &= ~ V_241 ;
}
if ( F_20 ( V_230 , & V_237 ) )
V_33 |= V_244 ;
if ( F_20 ( V_231 , & V_237 ) ) {
V_33 &= ~ V_240 ;
V_33 |= V_245 ;
}
if ( F_20 ( V_246 , & V_237 ) )
V_33 |= V_247 ;
}
if ( V_239 ) {
V_33 &= ~ V_243 ;
V_33 &= ~ V_244 ;
V_33 &= ~ V_242 ;
V_33 &= ~ V_245 ;
}
V_106 -> V_33 = F_76 ( V_33 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_217 * V_151 )
{
struct V_248 * V_61 = V_151 -> V_105 ;
int V_22 ;
T_6 V_102 = 0 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
if ( F_20 ( V_249 , & V_151 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_151 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_151 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_250 ;
F_123 ( V_2 , V_151 -> V_251 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) , false ) ;
}
if ( F_20 ( V_252 , & V_151 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = V_151 -> V_91 ;
V_61 -> V_110 [ V_102 ] . V_92 = V_151 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_253 ;
F_123 ( V_2 , V_151 -> V_226 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) , false ) ;
}
if ( F_20 ( V_254 , & V_151 -> V_255 ) ) {
if ( F_20 ( V_249 , & V_151 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_125 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_151 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_250 ;
F_123 ( V_2 , V_151 -> V_251 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
true ) ;
}
if ( F_20 ( V_252 , & V_151 -> V_25 ) ) {
V_61 -> V_110 [ V_102 ] . V_90 = F_125 ( V_2 , V_91 ) ;
V_61 -> V_110 [ V_102 ] . V_92 = V_151 -> V_92 ;
V_61 -> V_110 [ V_102 ] . V_93 =
V_253 ;
F_123 ( V_2 , V_151 -> V_226 ,
& ( V_61 -> V_110 [ V_102 ++ ] ) ,
true ) ;
}
}
F_122 ( V_151 -> V_96 , & V_61 -> V_119 , V_102 ) ;
F_4 ( V_17 , L_47 ,
V_61 -> V_119 . V_98 , V_151 -> V_226 ,
V_151 -> V_251 ) ;
V_22 = F_102 ( V_2 , V_256 , V_151 -> V_96 ,
F_103 ( V_151 -> V_193 ) ,
F_104 ( V_151 -> V_193 ) ,
V_194 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_217 * V_151 )
{
return F_34 ( V_2 , V_151 -> V_33 , V_151 -> V_34 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_217 * V_151 )
{
return 0 ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_217 * V_151 )
{
int V_22 ;
V_22 = V_151 -> V_257 -> V_258 ( V_2 , V_151 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_20 ( V_198 , & V_151 -> V_25 ) ) {
V_22 = V_151 -> V_257 -> V_172 ( V_2 , V_151 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_259 * V_4 )
{
if ( F_112 ( V_2 ) ) {
V_4 -> V_172 = F_127 ;
V_4 -> V_258 = F_121 ;
} else {
V_4 -> V_172 = F_126 ;
V_4 -> V_258 = F_124 ;
}
}
static inline T_6 F_130 ( T_6 * V_57 )
{
return ( F_131 ( 0 , V_57 , V_58 ) >> 24 ) & 0xff ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_261 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_172 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_260 * V_4 ,
struct V_262 * V_151 ,
int V_106 )
{
int V_263 ;
struct V_264 * V_265 ;
struct V_266 * V_267 = NULL ;
struct V_268 * V_52 ;
int V_269 = ( ( V_106 == V_270 ) ?
V_151 -> V_271 : 0 ) ;
if ( ! V_151 -> V_271 )
return 0 ;
V_263 = sizeof( * V_265 ) +
V_269 * sizeof( struct V_266 ) ;
V_265 = F_26 ( V_263 , V_31 ) ;
if ( ! V_265 )
return - V_181 ;
F_4 ( V_17 , L_48 ,
V_106 , V_269 ) ;
F_2 ( & V_265 -> V_61 . V_272 ) ;
V_265 -> type = V_106 ;
V_265 -> V_273 = false ;
switch ( V_106 ) {
case V_270 :
V_267 = (struct V_266 * )
( ( T_6 * ) V_265 + sizeof( * V_265 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_267 -> V_57 , V_52 -> V_57 , V_58 ) ;
F_13 ( & V_267 -> V_24 , & V_265 -> V_61 . V_272 ) ;
V_267 ++ ;
}
break;
case V_274 :
V_265 -> V_61 . V_275 = V_151 -> V_271 ;
break;
case V_276 :
V_265 -> V_61 . V_277 = 0 ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return - V_62 ;
}
F_13 ( & V_265 -> V_24 , & V_4 -> V_278 ) ;
V_4 -> V_279 ( V_4 ) ;
return 1 ;
}
static inline int F_134 ( struct V_260 * V_4 , int V_280 )
{
int V_281 , V_282 , V_283 = V_280 % V_284 ;
for ( V_281 = V_280 / V_284 ; V_281 < V_285 ; V_281 ++ ) {
if ( V_4 -> V_286 . V_287 . V_288 [ V_281 ] )
for ( V_282 = V_283 ; V_282 < V_284 ; V_282 ++ ) {
int V_289 = V_282 + V_284 * V_281 ;
if ( F_135 ( V_4 -> V_286 . V_287 .
V_288 , V_289 ) ) {
return V_289 ;
}
}
V_283 = 0 ;
}
return - 1 ;
}
static inline int F_136 ( struct V_260 * V_4 )
{
int V_289 = F_134 ( V_4 , 0 ) ;
if ( V_289 >= 0 )
F_137 ( V_4 -> V_286 . V_287 . V_288 , V_289 ) ;
return V_289 ;
}
static inline T_6 F_138 ( struct V_260 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_70 = 0 ;
if ( ( V_38 -> V_71 == V_72 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_290 ;
if ( ( V_38 -> V_71 == V_75 ) ||
( V_38 -> V_71 == V_73 ) )
V_70 |= V_291 ;
return V_70 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_260 * V_4 , int V_186 ,
union V_292 * V_293 ,
int V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_294 * V_61 =
(struct V_294 * ) ( V_125 -> V_105 ) ;
T_6 V_92 = V_125 -> V_92 ;
T_6 V_295 = F_138 ( V_4 ) ;
int V_296 ;
if ( ( V_106 == V_270 ) || ( V_106 == V_276 ) )
V_295 |= V_297 ;
V_61 -> V_110 [ V_186 ] . V_93 |= V_295 ;
switch ( V_106 ) {
case V_270 :
V_296 = F_130 ( V_293 -> V_57 ) ;
F_140 ( V_4 -> V_286 . V_287 . V_288 , V_296 ) ;
break;
case V_274 :
V_296 = F_136 ( V_4 ) ;
break;
case V_276 :
V_296 = V_293 -> V_296 ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return;
}
F_4 ( V_17 , L_50 ,
( ( V_295 & V_297 ) ?
L_51 : L_52 ) , V_296 ) ;
V_61 -> V_110 [ V_186 ] . V_298 = ( T_6 ) V_296 ;
V_61 -> V_110 [ V_186 ] . V_92 = V_92 ;
V_61 -> V_110 [ V_186 ] . V_299 = V_4 -> V_299 ;
}
static inline int F_141 (
struct V_1 * V_2 , struct V_260 * V_4 , int V_300 ,
int * V_301 )
{
int V_302 , V_20 = * V_301 ;
union V_292 V_293 = { 0 } ;
for ( V_302 = F_134 ( V_4 , V_300 ) ; V_302 >= 0 ;
V_302 = F_134 ( V_4 , V_302 + 1 ) ) {
V_293 . V_296 = ( T_6 ) V_302 ;
V_4 -> V_191 ( V_2 , V_4 , V_20 , & V_293 ,
V_276 ) ;
V_20 ++ ;
F_4 ( V_17 , L_53 , V_302 ) ;
if ( V_20 >= V_4 -> V_303 )
break;
}
* V_301 = V_20 ;
return V_302 ;
}
static inline void F_142 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_264 * V_304 ,
int * V_305 )
{
struct V_266 * V_306 , * V_307 ;
int V_20 = * V_305 ;
union V_292 V_293 = { 0 } ;
F_107 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_293 . V_57 = & V_306 -> V_57 [ 0 ] ;
V_4 -> V_191 ( V_2 , V_4 , V_20 , & V_293 , V_304 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_306 -> V_57 ) ;
F_17 ( & V_306 -> V_24 ) ;
if ( V_20 >= V_4 -> V_303 )
break;
}
* V_305 = V_20 ;
if ( F_15 ( & V_304 -> V_61 . V_272 ) )
V_304 -> V_273 = true ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_264 * V_304 ,
int * V_305 )
{
int V_20 = * V_305 ;
while ( V_304 -> V_61 . V_275 ) {
V_4 -> V_191 ( V_2 , V_4 , V_20 , NULL , V_304 -> type ) ;
V_20 ++ ;
V_304 -> V_61 . V_275 -- ;
F_4 ( V_17 , L_55 ,
V_304 -> V_61 . V_275 , V_20 ) ;
if ( V_20 >= V_4 -> V_303 )
break;
}
* V_305 = V_20 ;
if ( ! V_304 -> V_61 . V_275 )
V_304 -> V_273 = true ;
}
static inline void F_144 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_264 * V_304 ,
int * V_305 )
{
V_304 -> V_61 . V_277 = V_4 -> V_308 ( V_2 , V_4 , V_304 -> V_61 . V_277 ,
V_305 ) ;
if ( V_304 -> V_61 . V_277 < 0 )
V_304 -> V_273 = true ;
else
V_304 -> V_61 . V_277 ++ ;
}
static inline int F_145 ( struct V_1 * V_2 ,
struct V_262 * V_151 )
{
struct V_264 * V_304 , * V_309 ;
int V_20 = 0 ;
struct V_260 * V_4 = V_151 -> V_310 ;
F_107 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_304 -> type ) {
case V_270 :
F_142 ( V_2 , V_4 , V_304 , & V_20 ) ;
break;
case V_274 :
F_143 ( V_2 , V_4 , V_304 , & V_20 ) ;
break;
case V_276 :
F_144 ( V_2 , V_4 , V_304 ,
& V_20 ) ;
break;
default:
F_12 ( L_49 , V_304 -> type ) ;
return - V_62 ;
}
if ( V_304 -> V_273 ) {
F_17 ( & V_304 -> V_24 ) ;
F_6 ( V_304 ) ;
}
if ( V_20 >= V_4 -> V_303 )
break;
}
return V_20 ;
}
static inline void F_146 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_262 * V_151 ,
int * V_305 )
{
struct V_268 * V_311 ;
union V_292 V_293 = { 0 } ;
int V_20 = * V_305 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_293 . V_57 = V_311 -> V_57 ;
V_4 -> V_191 ( V_2 , V_4 , V_20 , & V_293 , V_270 ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_311 -> V_57 ) ;
}
* V_305 = V_20 ;
}
static inline void F_147 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_262 * V_151 ,
int * V_305 )
{
int V_20 = * V_305 , V_281 ;
for ( V_281 = 0 ; V_281 < V_151 -> V_271 ; V_281 ++ ) {
V_4 -> V_191 ( V_2 , V_4 , V_20 , NULL , V_274 ) ;
V_20 ++ ;
F_4 ( V_17 , L_56 ,
V_151 -> V_271 - V_281 - 1 ) ;
}
* V_305 = V_20 ;
}
static inline int F_148 ( struct V_1 * V_2 ,
struct V_262 * V_151 , int V_106 ,
int V_312 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
int V_20 = V_312 ;
F_4 ( V_17 , L_57 , V_151 -> V_271 ) ;
switch ( V_106 ) {
case V_270 :
F_146 ( V_2 , V_4 , V_151 , & V_20 ) ;
break;
case V_274 :
F_147 ( V_2 , V_4 , V_151 , & V_20 ) ;
break;
case V_276 :
V_4 -> V_308 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return - V_62 ;
}
V_151 -> V_271 = 0 ;
return V_20 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
int V_313 = V_4 -> V_314 ( V_4 ) ;
switch ( V_106 ) {
case V_274 :
V_4 -> V_315 ( V_4 , 0 ) ;
case V_276 :
V_151 -> V_271 = V_313 ;
break;
case V_270 :
case V_316 :
V_4 -> V_315 ( V_4 , V_313 + V_151 -> V_271 ) ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return - V_62 ;
}
V_4 -> V_317 += V_151 -> V_271 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_318 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
V_4 -> V_315 ( V_4 , V_318 ) ;
V_4 -> V_317 -= V_151 -> V_271 ;
}
static inline void F_151 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
T_6 V_319 )
{
struct V_32 * V_125 = & V_151 -> V_310 -> V_38 ;
struct V_294 * V_61 =
(struct V_294 * ) ( V_125 -> V_105 ) ;
V_61 -> V_119 . V_99 = ( ( V_125 -> V_96 & V_100 ) |
( V_320 << V_101 ) ) ;
V_61 -> V_119 . V_98 = V_319 ;
}
static inline int F_152 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
int V_281 , V_20 = 0 ;
T_11 V_19 ;
for ( V_281 = 0 ; V_281 < V_285 ; V_281 ++ ) {
V_19 = V_4 -> V_286 . V_287 . V_288 [ V_281 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_315 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
struct V_32 * V_38 = & V_151 -> V_310 -> V_38 ;
struct V_260 * V_4 = V_151 -> V_310 ;
struct V_294 * V_61 =
(struct V_294 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_20 = F_145 ( V_2 , V_151 ) ;
if ( F_15 ( & V_4 -> V_278 ) )
V_4 -> V_321 ( V_4 ) ;
if ( V_151 -> V_271 > 0 )
V_20 = F_148 ( V_2 , V_151 , V_106 , V_20 ) ;
V_4 -> V_317 -= V_20 ;
F_21 ( V_4 -> V_317 < 0 ) ;
F_21 ( V_20 > V_4 -> V_303 ) ;
F_151 ( V_2 , V_151 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_317 )
F_152 ( V_2 , V_4 ) ;
if ( F_20 ( V_28 , & V_151 -> V_25 ) ) {
V_38 -> V_175 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_102 ( V_2 , V_322 ,
V_38 -> V_96 , F_103 ( V_38 -> V_193 ) ,
F_104 ( V_38 -> V_193 ) ,
V_194 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_154 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
if ( ( V_106 == V_274 ) || ( V_106 == V_276 ) )
V_151 -> V_271 = 1 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_318 )
{
}
static inline void F_156 ( struct V_1 * V_2 ,
struct V_260 * V_4 ,
struct V_262 * V_151 ,
V_59 * V_323 )
{
struct V_268 * V_311 ;
int V_324 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_324 = F_130 ( V_311 -> V_57 ) ;
F_157 ( V_323 , V_324 ) ;
F_4 ( V_17 , L_58 ,
V_311 -> V_57 , V_324 ) ;
F_140 ( V_4 -> V_286 . V_287 . V_288 ,
V_324 ) ;
}
}
static inline void F_158 ( struct V_1 * V_2 ,
struct V_260 * V_4 , struct V_262 * V_151 ,
V_59 * V_323 )
{
int V_324 ;
for ( V_324 = F_134 ( V_4 , 0 ) ;
V_324 >= 0 ;
V_324 = F_134 ( V_4 , V_324 + 1 ) ) {
F_157 ( V_323 , V_324 ) ;
F_4 ( V_17 , L_59 , V_324 ) ;
}
}
static int F_159 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
int V_281 ;
struct V_260 * V_4 = V_151 -> V_310 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( ! F_20 ( V_28 , & V_151 -> V_25 ) ) {
V_59 V_323 [ V_325 ] = { 0 } ;
switch ( V_106 ) {
case V_270 :
F_156 ( V_2 , V_4 , V_151 , V_323 ) ;
break;
case V_274 :
F_4 ( V_17 ,
L_60 ) ;
memset ( V_4 -> V_286 . V_287 . V_288 , 0 ,
sizeof( V_4 -> V_286 . V_287 . V_288 ) ) ;
break;
case V_276 :
F_158 ( V_2 , V_4 , V_151 , V_323 ) ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return - V_62 ;
}
for ( V_281 = 0 ; V_281 < V_325 ; V_281 ++ )
F_68 ( V_2 , F_160 ( V_2 , V_281 ) , V_323 [ V_281 ] ) ;
} else
memset ( V_4 -> V_286 . V_287 . V_288 , 0 ,
sizeof( V_4 -> V_286 . V_287 . V_288 ) ) ;
V_125 -> V_175 ( V_125 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
int V_313 = V_4 -> V_314 ( V_4 ) ;
switch ( V_106 ) {
case V_274 :
V_4 -> V_315 ( V_4 , 0 ) ;
case V_276 :
V_151 -> V_271 = V_313 ;
F_4 ( V_17 , L_61 ,
V_106 , V_151 -> V_271 ) ;
break;
case V_270 :
case V_316 :
if ( V_151 -> V_271 > V_4 -> V_303 ) {
F_12 ( L_62 ,
V_4 -> V_303 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_57 , V_151 -> V_271 ) ;
if ( V_151 -> V_271 > 0 )
V_4 -> V_315 ( V_4 , V_151 -> V_271 ) ;
break;
default:
F_12 ( L_49 , V_106 ) ;
return - V_62 ;
}
if ( V_151 -> V_271 )
V_4 -> V_317 += V_4 -> V_303 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_326 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
V_4 -> V_315 ( V_4 , V_326 ) ;
if ( V_151 -> V_271 )
V_4 -> V_317 -= V_4 -> V_303 ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_260 * V_4 , int V_186 ,
union V_292 * V_293 ,
int V_106 )
{
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
if ( ( V_106 == V_270 ) || ( V_106 == V_276 ) ) {
F_72 ( & V_61 -> V_143 [ V_186 ] . V_137 ,
& V_61 -> V_143 [ V_186 ] . V_138 ,
& V_61 -> V_143 [ V_186 ] . V_139 ,
V_293 -> V_57 ) ;
V_61 -> V_143 [ V_186 ] . V_127 = 0 ;
V_61 -> V_143 [ V_186 ] . V_132 = V_125 -> V_92 ;
V_61 -> V_143 [ V_186 ] . V_131 =
F_75 ( 1 << V_125 -> V_91 ) ;
F_77 ( V_61 -> V_143 [ V_186 ] . V_133 ,
V_134 ,
V_135 ) ;
}
}
static inline void F_164 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
T_6 V_319 )
{
struct V_32 * V_125 = & V_151 -> V_310 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_125 -> V_105 ) ;
T_6 V_40 = ( F_165 ( V_2 ) ?
V_327 * ( 1 + V_125 -> V_92 ) :
V_328 * ( 1 + V_125 -> V_92 ) ) ;
V_61 -> V_89 . V_40 = V_40 ;
V_61 -> V_89 . V_90 = 0xff ;
V_61 -> V_89 . V_99 = ( ( V_125 -> V_96 & V_100 ) |
( V_320 << V_101 ) ) ;
V_61 -> V_89 . V_126 = V_319 ;
}
static inline int F_166 (
struct V_1 * V_2 , struct V_260 * V_4 , int V_329 ,
int * V_301 )
{
struct V_266 * V_19 ;
int V_281 = 0 ;
union V_292 V_293 = { 0 } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_293 . V_57 = & V_19 -> V_57 [ 0 ] ;
V_4 -> V_191 ( V_2 , V_4 , V_281 , & V_293 , V_276 ) ;
V_281 ++ ;
F_4 ( V_17 , L_54 ,
V_293 . V_57 ) ;
}
* V_301 = V_281 ;
return - 1 ;
}
static inline int F_167 (
struct V_1 * V_2 , struct V_262 * V_151 )
{
struct V_264 * V_304 ;
struct V_266 * V_306 ;
struct V_260 * V_4 = V_151 -> V_310 ;
union V_292 V_293 = { 0 } ;
int V_20 = 0 ;
if ( F_15 ( & V_4 -> V_278 ) )
return 0 ;
V_304 = F_16 ( & V_4 -> V_278 ,
struct V_264 , V_24 ) ;
switch ( V_304 -> type ) {
case V_270 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_293 . V_57 = & V_306 -> V_57 [ 0 ] ;
V_4 -> V_191 ( V_2 , V_4 , V_20 , & V_293 , V_304 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 ,
V_306 -> V_57 ) ;
}
break;
case V_274 :
V_20 = V_304 -> V_61 . V_275 ;
F_4 ( V_17 , L_63 , V_20 ) ;
break;
case V_276 :
V_4 -> V_308 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_49 , V_304 -> type ) ;
return - V_62 ;
}
F_17 ( & V_304 -> V_24 ) ;
F_6 ( V_304 ) ;
return V_20 ;
}
static inline void F_168 ( T_12 * V_330 , T_12 * V_331 ,
T_12 * V_332 , T_6 * V_57 )
{
V_57 [ 1 ] = ( ( T_6 * ) V_330 ) [ 0 ] ;
V_57 [ 0 ] = ( ( T_6 * ) V_330 ) [ 1 ] ;
V_57 [ 3 ] = ( ( T_6 * ) V_331 ) [ 0 ] ;
V_57 [ 2 ] = ( ( T_6 * ) V_331 ) [ 1 ] ;
V_57 [ 5 ] = ( ( T_6 * ) V_332 ) [ 0 ] ;
V_57 [ 4 ] = ( ( T_6 * ) V_332 ) [ 1 ] ;
}
static inline int F_169 ( struct V_1 * V_2 ,
struct V_260 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_266 * V_19 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
if ( F_170 ( V_61 -> V_143 [ 0 ] . V_133 ,
V_134 ) ) {
int V_281 , V_319 = V_61 -> V_89 . V_126 ;
if ( ! F_15 ( & V_4 -> V_286 . V_333 . V_334 ) )
return 0 ;
V_19 = F_171 ( V_319 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_12 ( L_64 ) ;
return - V_181 ;
}
for ( V_281 = 0 ; V_281 < V_319 ; V_281 ++ , V_19 ++ ) {
F_168 (
& V_61 -> V_143 [ V_281 ] . V_137 ,
& V_61 -> V_143 [ V_281 ] . V_138 ,
& V_61 -> V_143 [ V_281 ] . V_139 ,
V_19 -> V_57 ) ;
F_4 ( V_17 , L_65 ,
V_19 -> V_57 ) ;
F_13 ( & V_19 -> V_24 ,
& V_4 -> V_286 . V_333 . V_334 ) ;
}
} else {
V_19 = F_16 ( & V_4 -> V_286 . V_333 . V_334 ,
struct V_266 , V_24 ) ;
F_4 ( V_17 , L_66 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_286 . V_333 . V_334 ) ;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_141 * V_61 =
(struct V_141 * ) ( V_38 -> V_105 ) ;
int V_20 = 0 , V_281 , V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
for ( V_281 = 0 ; V_281 < V_4 -> V_303 ; V_281 ++ )
F_77 ( V_61 -> V_143 [ V_281 ] . V_133 ,
V_134 ,
V_140 ) ;
V_20 = F_167 ( V_2 , V_151 ) ;
if ( F_15 ( & V_4 -> V_278 ) )
V_4 -> V_321 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_148 ( V_2 , V_151 , V_106 , 0 ) ;
V_4 -> V_317 -= V_4 -> V_303 ;
F_21 ( V_20 > V_4 -> V_303 ) ;
F_164 ( V_2 , V_151 , ( T_6 ) V_20 ) ;
V_22 = F_169 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_20 ( V_28 , & V_151 -> V_25 ) ) {
V_38 -> V_175 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_102 ( V_2 , V_207 , V_38 -> V_96 ,
F_103 ( V_38 -> V_193 ) ,
F_104 ( V_38 -> V_193 ) ,
V_194 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_173 ( struct V_260 * V_4 )
{
return V_4 -> V_286 . V_333 . V_335 ;
}
static int F_174 ( struct V_260 * V_4 )
{
return V_4 -> V_286 . V_287 . V_336 ;
}
static void F_175 ( struct V_260 * V_4 ,
int V_49 )
{
V_4 -> V_286 . V_333 . V_335 = V_49 ;
}
static void F_176 ( struct V_260 * V_4 ,
int V_49 )
{
V_4 -> V_286 . V_287 . V_336 = V_49 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_262 * V_151 ,
int V_106 )
{
struct V_260 * V_4 = V_151 -> V_310 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
int V_22 = 0 , V_337 ;
V_337 = V_4 -> V_314 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_151 , V_106 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_151 -> V_271 ) && ( ! V_4 -> V_338 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_67 ,
V_4 -> V_317 , V_151 -> V_271 , V_4 -> V_303 ) ;
if ( V_125 -> V_188 ( V_125 ) ||
( ( V_4 -> V_303 > 0 ) && ( V_4 -> V_317 > V_4 -> V_303 ) ) ) {
V_22 = V_4 -> V_339 ( V_2 , V_151 -> V_310 , V_151 , V_106 ) ;
if ( V_22 < 0 )
goto V_340;
V_151 -> V_271 = 0 ;
}
if ( ! V_125 -> V_188 ( V_125 ) ) {
V_125 -> V_189 ( V_125 ) ;
V_22 = V_4 -> V_341 ( V_2 , V_151 , V_106 ) ;
if ( V_22 < 0 )
goto V_342;
if ( F_20 ( V_198 , & V_151 -> V_25 ) )
V_22 = V_4 -> V_172 ( V_2 , V_4 ) ;
}
return V_22 ;
V_342:
V_125 -> V_175 ( V_125 ) ;
V_340:
V_4 -> V_343 ( V_2 , V_151 , V_337 ) ;
return V_22 ;
}
static void F_178 ( struct V_260 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_261 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_179 ( struct V_260 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_261 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_180 ( struct V_260 * V_4 )
{
return ! ! F_20 ( V_4 -> V_261 , V_4 -> V_38 . V_34 ) ;
}
static bool F_181 ( struct V_260 * V_4 )
{
return V_4 -> V_38 . V_188 ( & V_4 -> V_38 ) || V_4 -> V_338 ( V_4 ) ;
}
void F_182 ( struct V_1 * V_2 ,
struct V_260 * V_310 ,
T_6 V_344 , V_59 V_345 , T_6 V_92 ,
T_6 V_299 , void * V_105 , T_8 V_193 ,
int V_33 , unsigned long * V_34 , T_9 type )
{
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
F_109 ( & V_310 -> V_38 , V_344 , V_345 , V_92 ,
V_105 , V_193 , V_33 , V_34 , type ) ;
V_310 -> V_299 = V_299 ;
F_2 ( & V_310 -> V_278 ) ;
V_310 -> V_261 = V_346 ;
V_310 -> V_338 = F_180 ;
V_310 -> V_279 = F_179 ;
V_310 -> V_321 = F_178 ;
if ( F_116 ( V_2 ) ) {
V_310 -> V_341 = F_172 ;
V_310 -> V_339 = F_133 ;
V_310 -> V_308 =
F_166 ;
V_310 -> V_188 = F_181 ;
if ( F_165 ( V_2 ) )
V_310 -> V_303 = V_327 ;
else
V_310 -> V_303 = V_328 ;
V_310 -> V_172 = F_132 ;
V_310 -> V_191 = F_163 ;
V_310 -> V_8 = F_161 ;
V_310 -> V_343 = F_162 ;
V_310 -> V_314 =
F_173 ;
V_310 -> V_315 =
F_175 ;
F_2 ( & V_310 -> V_286 . V_333 . V_334 ) ;
} else if ( F_117 ( V_2 ) ) {
V_310 -> V_341 = F_159 ;
V_310 -> V_339 = NULL ;
V_310 -> V_308 = NULL ;
V_310 -> V_188 = F_181 ;
V_310 -> V_303 = - 1 ;
V_310 -> V_172 = F_132 ;
V_310 -> V_191 = NULL ;
V_310 -> V_8 = F_154 ;
V_310 -> V_343 = F_155 ;
V_310 -> V_314 =
F_174 ;
V_310 -> V_315 =
F_176 ;
} else {
V_310 -> V_341 = F_153 ;
V_310 -> V_339 = F_133 ;
V_310 -> V_308 =
F_141 ;
V_310 -> V_188 = F_181 ;
V_310 -> V_303 = 16 ;
V_310 -> V_172 = F_132 ;
V_310 -> V_191 = F_139 ;
V_310 -> V_8 = F_149 ;
V_310 -> V_343 = F_150 ;
V_310 -> V_314 =
F_174 ;
V_310 -> V_315 =
F_176 ;
}
}
static inline bool F_183 ( T_13 * V_347 , int V_348 , int V_56 )
{
int V_349 , V_350 ;
V_349 = F_184 ( V_347 ) ;
for (; ; ) {
if ( F_185 ( V_349 + V_348 >= V_56 ) )
return false ;
V_350 = F_186 ( ( V_347 ) , V_349 , V_349 + V_348 ) ;
if ( F_187 ( V_350 == V_349 ) )
break;
V_349 = V_350 ;
}
return true ;
}
static inline bool F_188 ( T_13 * V_347 , int V_348 , int V_56 )
{
int V_349 , V_350 ;
V_349 = F_184 ( V_347 ) ;
for (; ; ) {
if ( F_185 ( V_349 - V_348 < V_56 ) )
return false ;
V_350 = F_186 ( ( V_347 ) , V_349 , V_349 - V_348 ) ;
if ( F_187 ( V_350 == V_349 ) )
break;
V_349 = V_350 ;
}
return true ;
}
static bool F_189 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_190 () ;
V_22 = F_188 ( & V_4 -> V_351 , V_20 , 0 ) ;
F_190 () ;
return V_22 ;
}
static bool F_191 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_190 () ;
V_22 = F_183 ( & V_4 -> V_351 , V_20 , V_4 -> V_352 + 1 ) ;
F_190 () ;
return V_22 ;
}
static int F_192 ( struct V_41 * V_4 )
{
int V_353 ;
F_190 () ;
V_353 = F_184 ( & V_4 -> V_351 ) ;
return V_353 ;
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
int V_186 , V_288 , V_281 ;
* V_40 = - 1 ;
for ( V_288 = 0 ; V_288 < V_354 ; V_288 ++ ) {
if ( ! V_4 -> V_355 [ V_288 ] )
continue;
for ( V_186 = V_288 * V_284 , V_281 = 0 ;
V_281 < V_284 ; V_186 ++ , V_281 ++ )
if ( F_135 ( V_4 -> V_355 , V_186 ) ) {
F_137 ( V_4 -> V_355 , V_186 ) ;
* V_40 = V_4 -> V_356 + V_186 ;
return true ;
}
}
return false ;
}
static bool F_195 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_356 )
return false ;
V_40 -= V_4 -> V_356 ;
if ( V_40 >= V_4 -> V_352 )
return false ;
F_140 ( V_4 -> V_355 , V_40 ) ;
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
static inline void F_198 ( struct V_41 * V_151 ,
int V_357 , int V_351 )
{
memset ( V_151 , 0 , sizeof( * V_151 ) ) ;
memset ( & V_151 -> V_355 , 0xff , sizeof( V_151 -> V_355 ) ) ;
F_199 ( & V_151 -> V_351 , V_351 ) ;
V_151 -> V_352 = V_351 ;
V_151 -> V_356 = V_357 ;
F_190 () ;
V_151 -> V_358 = F_192 ;
if ( V_351 >= 0 ) {
V_151 -> V_47 = F_191 ;
V_151 -> V_11 = F_189 ;
V_151 -> V_48 = F_195 ;
V_151 -> V_44 = F_194 ;
} else {
V_151 -> V_47 = F_193 ;
V_151 -> V_11 = F_193 ;
V_151 -> V_48 = F_196 ;
V_151 -> V_44 = F_197 ;
}
if ( V_357 < 0 ) {
V_151 -> V_48 = F_196 ;
V_151 -> V_44 = F_197 ;
}
}
void F_200 ( struct V_1 * V_2 ,
struct V_41 * V_151 , T_6 V_92 ,
T_6 V_359 )
{
#define F_201 5
int V_360 ;
if ( F_116 ( V_2 ) ) {
if ( ! F_165 ( V_2 ) )
V_360 = ( V_361 / 2 ) - V_328 ;
else
V_360 = F_201 - V_327 ;
F_198 ( V_151 , V_92 * V_360 , V_360 ) ;
} else if ( F_117 ( V_2 ) ) {
if ( ( V_359 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_360 = ( V_362 / ( 2 * V_359 ) ) ;
else
V_360 = F_201 ;
F_198 ( V_151 , V_92 * V_360 , V_360 ) ;
} else {
F_198 ( V_151 , 0 , 0 ) ;
}
} else {
if ( ( V_359 > 0 ) ) {
if ( ! F_165 ( V_2 ) )
V_360 = ( V_363 / V_359 ) ;
else
V_360 = F_201 ;
F_198 ( V_151 , - 1 , V_360 ) ;
} else {
F_198 ( V_151 , 0 , 0 ) ;
}
}
}
void F_202 ( struct V_1 * V_2 ,
struct V_41 * V_151 ,
T_6 V_92 ,
T_6 V_359 )
{
if ( F_112 ( V_2 ) ) {
F_198 ( V_151 , 0 , - 1 ) ;
} else {
if ( V_359 > 0 ) {
int V_351 = V_364 / V_359 ;
F_198 ( V_151 , V_92 * V_351 , V_351 ) ;
} else
F_198 ( V_151 , 0 , 0 ) ;
}
}
static inline void F_203 ( struct V_1 * V_2 ,
struct V_365 * V_151 )
{
int V_281 ;
F_4 ( V_17 , L_68 ) ;
F_4 ( V_17 , L_69 ) ;
for ( V_281 = 0 ; V_281 < V_366 ; V_281 ++ ) {
F_204 ( V_17 , L_70 , V_151 -> V_367 [ V_281 ] ) ;
if ( ( V_281 + 1 < V_366 ) &&
( ( ( V_281 + 1 ) & 0x3 ) == 0 ) ) {
F_204 ( V_17 , L_71 ) ;
F_4 ( V_17 , L_72 , V_281 + 1 ) ;
}
}
F_204 ( V_17 , L_71 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_365 * V_151 )
{
struct V_368 * V_4 = V_151 -> V_369 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
struct V_370 * V_61 =
(struct V_370 * ) ( V_125 -> V_105 ) ;
T_6 V_371 = 0 ;
int V_22 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_4 ( V_17 , L_73 ) ;
V_61 -> V_99 = ( V_125 -> V_96 & V_100 ) |
( V_125 -> V_33 << V_101 ) ;
if ( F_20 ( V_372 , & V_151 -> V_373 ) )
V_371 = V_374 ;
else if ( F_20 ( V_375 , & V_151 -> V_373 ) )
V_371 = V_376 ;
V_61 -> V_371 = V_371 ;
F_4 ( V_17 , L_74 , V_371 ) ;
if ( F_20 ( V_377 , & V_151 -> V_373 ) )
V_61 -> V_378 |=
V_379 ;
if ( F_20 ( V_380 , & V_151 -> V_373 ) )
V_61 -> V_378 |=
V_381 ;
if ( F_20 ( V_382 , & V_151 -> V_373 ) )
V_61 -> V_378 |=
V_383 ;
if ( F_20 ( V_384 , & V_151 -> V_373 ) )
V_61 -> V_378 |=
V_385 ;
V_61 -> V_386 = V_151 -> V_386 ;
V_61 -> V_387 = V_4 -> V_299 ;
F_4 ( V_17 , L_75 , V_61 -> V_387 ) ;
memcpy ( V_61 -> V_388 , V_151 -> V_367 ,
V_366 ) ;
memcpy ( V_4 -> V_367 , V_151 -> V_367 , V_366 ) ;
if ( F_206 ( V_2 ) )
F_203 ( V_2 , V_151 ) ;
if ( F_20 ( V_389 , & V_151 -> V_373 ) ) {
memcpy ( & V_61 -> V_390 [ 0 ] , & V_151 -> V_390 [ 0 ] ,
sizeof( V_61 -> V_390 ) ) ;
V_61 -> V_378 |= V_391 ;
}
V_22 = F_102 ( V_2 , V_392 , V_125 -> V_96 ,
F_103 ( V_125 -> V_193 ) ,
F_104 ( V_125 -> V_193 ) ,
V_194 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_207 ( struct V_368 * V_369 ,
T_6 * V_367 )
{
memcpy ( V_367 , V_369 -> V_367 , sizeof( V_369 -> V_367 ) ) ;
}
int F_208 ( struct V_1 * V_2 ,
struct V_365 * V_151 )
{
int V_22 ;
struct V_368 * V_4 = V_151 -> V_369 ;
struct V_32 * V_125 = & V_4 -> V_38 ;
if ( F_20 ( V_28 , & V_151 -> V_25 ) )
return 0 ;
V_125 -> V_189 ( V_125 ) ;
V_22 = V_4 -> V_393 ( V_2 , V_151 ) ;
if ( V_22 < 0 ) {
V_125 -> V_175 ( V_125 ) ;
return V_22 ;
}
if ( F_20 ( V_198 , & V_151 -> V_25 ) )
V_22 = V_125 -> V_172 ( V_2 , V_125 ) ;
return V_22 ;
}
void F_209 ( struct V_1 * V_2 ,
struct V_368 * V_369 ,
T_6 V_91 , V_59 V_96 , T_6 V_92 , T_6 V_299 ,
void * V_105 , T_8 V_193 ,
int V_33 , unsigned long * V_34 ,
T_9 type )
{
F_109 ( & V_369 -> V_38 , V_91 , V_96 , V_92 , V_105 ,
V_193 , V_33 , V_34 , type ) ;
V_369 -> V_299 = V_299 ;
V_369 -> V_393 = F_205 ;
}
int F_210 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
int V_22 , V_398 ;
unsigned long * V_399 = & V_4 -> V_399 ;
if ( V_4 -> V_400 ( V_2 , V_4 , V_395 ) )
return - V_62 ;
V_398 = V_4 -> V_189 ( V_4 , V_395 ) ;
if ( F_20 ( V_28 , & V_395 -> V_25 ) )
V_4 -> V_401 ( V_2 , V_4 , V_398 ) ;
else {
V_22 = V_4 -> V_402 ( V_2 , V_395 ) ;
if ( V_22 ) {
V_4 -> V_403 = V_404 ;
F_30 ( V_398 , V_399 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_198 , & V_395 -> V_25 ) ) {
V_22 = V_4 -> V_172 ( V_2 , V_4 , V_398 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_398 , V_399 ) ;
}
static int F_211 ( struct V_396 * V_405 ,
struct V_394 * V_395 )
{
enum V_406 V_106 = V_395 -> V_106 , V_324 ;
if ( ( V_106 == V_407 ) ||
( V_106 == V_408 ) )
V_324 = V_409 ;
else
V_324 = V_106 ;
F_33 ( V_324 , & V_405 -> V_399 ) ;
return V_324 ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_396 * V_4 ,
enum V_406 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_399 ) ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_396 * V_4 ,
enum V_406 V_106 )
{
unsigned long V_410 = V_4 -> V_399 ;
if ( ! F_214 ( V_106 , & V_410 ) ) {
F_12 ( L_76 ,
V_106 , V_4 -> V_411 [ V_412 ] ,
V_4 -> V_33 , V_410 , V_4 -> V_403 ) ;
return - V_62 ;
}
if ( V_4 -> V_413 >= V_4 -> V_414 )
F_12 ( L_77 ,
V_4 -> V_413 , V_4 -> V_414 ) ;
F_4 ( V_17 ,
L_78 ,
V_106 , V_4 -> V_411 [ V_412 ] , V_4 -> V_403 ) ;
if ( V_4 -> V_413 )
F_4 ( V_17 , L_79 ,
V_4 -> V_411 [ V_412 ] , V_4 -> V_413 ) ;
V_4 -> V_33 = V_4 -> V_403 ;
V_4 -> V_415 = V_4 -> V_413 ;
V_4 -> V_403 = V_404 ;
F_215 () ;
F_30 ( V_106 , & V_4 -> V_399 ) ;
F_31 () ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_394 * V_416 ,
struct V_417 * V_61 )
{
struct V_418 * V_395 = & V_416 -> V_395 . V_419 ;
V_61 -> V_420 . V_421 |= F_20 ( V_422 , & V_395 -> V_133 ) *
V_423 ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_396 * V_4 ,
struct V_424 * V_395 ,
struct V_425 * V_426 ,
unsigned long * V_133 )
{
V_426 -> V_90 = V_4 -> V_91 ;
if ( F_20 ( V_427 , V_133 ) ) {
V_426 -> V_428 =
V_395 -> V_429 ;
V_426 -> V_430 = 1 ;
V_426 -> V_431 =
F_20 ( V_432 , V_133 ) ;
} else
V_426 -> V_428 =
V_433 ;
V_426 -> V_434 = F_20 ( V_435 , V_133 ) ;
V_426 -> V_436 = F_20 ( V_437 , V_133 ) ;
V_426 -> V_438 = V_395 -> V_439 ;
V_426 -> V_440 = F_76 ( V_395 -> V_440 ) ;
V_426 -> V_92 = V_4 -> V_92 ;
V_426 -> cos = V_395 -> cos ;
V_426 -> V_441 =
F_20 ( V_435 , V_133 ) ?
V_442 : V_443 ;
F_4 ( V_17 , L_80 ,
V_426 -> V_436 , V_426 -> cos , V_426 -> V_430 ) ;
}
static void F_218 ( struct V_396 * V_4 ,
struct V_444 * V_395 ,
struct V_445 * V_446 ,
unsigned long * V_133 )
{
V_446 -> V_447 =
F_20 ( V_448 , V_133 ) ;
V_446 -> V_449 =
F_76 ( V_395 -> V_449 ) ;
V_446 -> V_450 =
F_20 ( V_451 , V_133 ) ;
V_446 -> V_452 =
F_20 ( V_453 , V_133 ) ;
V_446 -> V_454 =
F_20 ( V_455 , V_133 ) ;
V_446 -> V_456 =
F_20 ( V_457 , V_133 ) ;
V_446 -> V_458 = V_395 -> V_459 ;
V_446 -> V_460 = V_395 -> V_461 ;
V_446 -> V_462 = V_395 -> V_463 ;
V_446 -> V_464 . V_465 =
F_75 ( F_104 ( V_395 -> V_466 ) ) ;
V_446 -> V_464 . V_467 =
F_75 ( F_103 ( V_395 -> V_466 ) ) ;
V_446 -> V_33 = 0 ;
}
static void F_219 ( struct V_396 * V_4 ,
struct V_468 * V_395 ,
struct V_469 * V_470 )
{
V_470 -> V_471 = F_76 ( V_395 -> V_472 ) ;
V_470 -> V_473 = F_76 ( V_395 -> V_474 ) ;
V_470 -> V_475 = F_76 ( V_395 -> V_476 ) ;
V_470 -> V_477 = F_76 ( V_395 -> V_478 ) ;
V_470 -> V_479 = F_76 ( V_395 -> V_480 ) ;
V_470 -> V_481 = F_76 ( V_395 -> V_482 ) ;
V_470 -> V_483 = F_76 ( V_395 -> V_484 ) ;
}
static void F_220 ( struct V_396 * V_4 ,
struct V_485 * V_395 ,
struct V_469 * V_470 ,
unsigned long * V_133 )
{
V_470 -> V_421 = F_20 ( V_486 , V_133 ) *
V_487 ;
V_470 -> V_421 |= F_20 ( V_488 , V_133 ) *
V_489 ;
V_470 -> V_490 = 0 ;
V_470 -> V_491 =
V_395 -> V_492 ;
V_470 -> V_493 =
F_20 ( V_494 , V_133 ) ;
V_470 -> V_495 = V_395 -> V_496 ;
V_470 -> V_497 = V_395 -> V_498 ;
V_470 -> V_499 = F_76 ( V_395 -> V_500 ) ;
V_470 -> V_33 = F_76 ( V_501 |
V_502 ) ;
V_470 -> V_503 = 0 ;
V_470 -> V_504 = 0 ;
V_470 -> V_505 = 0 ;
V_470 -> V_506 = 0 ;
V_470 -> V_507 =
F_20 ( V_508 , V_133 ) ;
V_470 -> V_509 =
F_20 ( V_510 , V_133 ) ;
V_470 -> V_511 = V_395 -> V_459 ;
V_470 -> V_512 = V_395 -> V_461 ;
V_470 -> V_513 = V_395 -> V_513 ;
V_470 -> V_514 = F_76 ( V_395 -> V_515 ) ;
V_470 -> V_516 = F_76 ( V_395 -> V_517 ) ;
V_470 -> V_518 . V_465 =
F_75 ( F_104 ( V_395 -> V_466 ) ) ;
V_470 -> V_518 . V_467 =
F_75 ( F_103 ( V_395 -> V_466 ) ) ;
V_470 -> V_519 . V_465 =
F_75 ( F_104 ( V_395 -> V_520 ) ) ;
V_470 -> V_519 . V_467 =
F_75 ( F_103 ( V_395 -> V_520 ) ) ;
V_470 -> V_521 . V_465 =
F_75 ( F_104 ( V_395 -> V_522 ) ) ;
V_470 -> V_521 . V_467 =
F_75 ( F_103 ( V_395 -> V_522 ) ) ;
V_470 -> V_523 = F_20 ( V_524 , V_133 ) ;
if ( F_20 ( V_525 , V_133 ) ) {
V_470 -> V_526 = V_395 -> V_527 ;
V_470 -> V_528 = 1 ;
}
V_470 -> V_387 = V_395 -> V_387 ;
V_470 -> V_529 =
F_20 ( V_530 , V_133 ) ;
V_470 -> V_531 =
F_76 ( V_395 -> V_532 ) ;
V_470 -> V_533 =
F_76 ( V_395 -> V_534 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_394 * V_416 ,
struct V_417 * V_61 )
{
F_217 ( V_2 , V_416 -> V_397 ,
& V_416 -> V_395 . V_419 . V_535 ,
& V_61 -> V_536 ,
& V_416 -> V_395 . V_419 . V_133 ) ;
F_218 ( V_416 -> V_397 ,
& V_416 -> V_395 . V_419 . V_537 ,
& V_61 -> V_538 ,
& V_416 -> V_395 . V_419 . V_133 ) ;
F_220 ( V_416 -> V_397 ,
& V_416 -> V_395 . V_419 . V_539 ,
& V_61 -> V_420 ,
& V_416 -> V_395 . V_419 . V_133 ) ;
F_219 ( V_416 -> V_397 ,
& V_416 -> V_395 . V_419 . V_540 ,
& V_61 -> V_420 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_394 * V_416 ,
struct V_541 * V_61 )
{
F_217 ( V_2 , V_416 -> V_397 ,
& V_416 -> V_395 . V_542 . V_535 ,
& V_61 -> V_536 ,
& V_416 -> V_395 . V_542 . V_133 ) ;
F_218 ( V_416 -> V_397 ,
& V_416 -> V_395 . V_542 . V_537 ,
& V_61 -> V_538 ,
& V_416 -> V_395 . V_542 . V_133 ) ;
F_4 ( V_17 , L_81 ,
V_416 -> V_397 -> V_411 [ 0 ] ,
V_61 -> V_538 . V_464 . V_465 ,
V_61 -> V_538 . V_464 . V_467 ) ;
}
static inline int F_223 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
struct V_543 * V_544 = & V_395 -> V_395 . V_544 ;
T_7 V_545 ;
T_6 cos ;
if ( F_20 ( V_546 , & V_4 -> type ) &&
F_20 ( V_547 , & V_544 -> V_538 . V_133 ) ) {
V_545 = V_544 -> V_538 . V_548 ? 1000000 / V_544 -> V_538 . V_548 : 0 ;
F_224 ( V_2 , V_544 -> V_538 . V_459 ,
V_544 -> V_538 . V_461 ,
! F_20 ( V_549 , & V_544 -> V_538 . V_133 ) ,
V_545 ) ;
}
if ( F_20 ( V_550 , & V_4 -> type ) &&
F_20 ( V_547 , & V_544 -> V_420 . V_133 ) ) {
V_545 = V_544 -> V_420 . V_548 ? 1000000 / V_544 -> V_420 . V_548 : 0 ;
F_224 ( V_2 , V_544 -> V_420 . V_459 ,
V_544 -> V_420 . V_461 ,
! F_20 ( V_549 , & V_544 -> V_420 . V_133 ) ,
V_545 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_414 ; cos ++ ) {
F_4 ( V_17 , L_82 ,
V_4 -> V_411 [ cos ] , cos ) ;
F_4 ( V_17 , L_83 , V_544 -> V_551 [ cos ] ) ;
F_225 ( V_2 , V_544 -> V_551 [ cos ] , V_4 -> V_411 [ cos ] ) ;
}
V_4 -> V_401 ( V_2 , V_4 , V_552 ) ;
F_226 () ;
F_190 () ;
return 0 ;
}
static inline int F_227 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
struct V_417 * V_105 =
(struct V_417 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
int V_554 = V_555 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_221 ( V_2 , V_395 , V_105 ) ;
return F_102 ( V_2 , V_554 , V_4 -> V_411 [ V_412 ] ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_194 ) ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
struct V_417 * V_105 =
(struct V_417 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
int V_554 = V_555 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_221 ( V_2 , V_395 , V_105 ) ;
F_216 ( V_2 , V_395 , V_105 ) ;
return F_102 ( V_2 , V_554 , V_4 -> V_411 [ V_412 ] ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_194 ) ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
struct V_541 * V_105 =
(struct V_541 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
int V_554 = V_556 ;
struct V_557 * V_558 =
& V_395 -> V_395 . V_542 ;
T_6 V_559 = V_558 -> V_559 ;
if ( V_559 >= V_4 -> V_414 ) {
F_12 ( L_84 ,
V_4 -> V_91 , V_559 ) ;
return - V_62 ;
}
F_4 ( V_17 , L_85 ,
V_558 -> V_535 . cos ,
V_558 -> V_535 . V_439 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_222 ( V_2 , V_395 , V_105 ) ;
F_4 ( V_17 , L_86 ,
V_4 -> V_411 [ V_559 ] , V_105 -> V_536 . V_90 ,
V_105 -> V_536 . V_438 , V_105 -> V_536 . cos ) ;
return F_102 ( V_2 , V_554 , V_4 -> V_411 [ V_559 ] ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_194 ) ;
}
static void F_230 ( struct V_1 * V_2 ,
struct V_396 * V_405 ,
struct V_560 * V_395 ,
struct V_561 * V_61 )
{
V_61 -> V_90 = V_405 -> V_91 ;
V_61 -> V_92 = V_405 -> V_92 ;
V_61 -> V_449 = F_76 ( V_395 -> V_562 ) ;
V_61 -> V_507 =
F_20 ( V_563 , & V_395 -> V_564 ) ;
V_61 -> V_565 =
F_20 ( V_566 ,
& V_395 -> V_564 ) ;
V_61 -> V_509 =
F_20 ( V_567 , & V_395 -> V_564 ) ;
V_61 -> V_568 =
F_20 ( V_569 ,
& V_395 -> V_564 ) ;
V_61 -> V_570 =
F_20 ( V_571 , & V_395 -> V_564 ) ;
V_61 -> V_572 =
F_20 ( V_573 , & V_395 -> V_564 ) ;
V_61 -> V_436 =
F_20 ( V_574 , & V_395 -> V_564 ) ;
V_61 -> V_575 =
F_20 ( V_576 , & V_395 -> V_564 ) ;
V_61 -> V_577 =
F_20 ( V_578 , & V_395 -> V_564 ) ;
V_61 -> V_579 =
F_20 ( V_580 ,
& V_395 -> V_564 ) ;
V_61 -> V_581 =
F_20 ( V_582 ,
& V_395 -> V_564 ) ;
V_61 -> V_529 =
F_20 ( V_583 , & V_395 -> V_564 ) ;
V_61 -> V_531 = F_76 ( V_395 -> V_532 ) ;
V_61 -> V_533 = F_76 ( V_395 -> V_534 ) ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
struct V_561 * V_105 =
(struct V_561 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
struct V_560 * V_584 =
& V_395 -> V_395 . V_585 ;
T_6 V_559 = V_584 -> V_559 ;
if ( V_559 >= V_4 -> V_414 ) {
F_12 ( L_84 ,
V_4 -> V_91 , V_559 ) ;
return - V_62 ;
}
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_230 ( V_2 , V_4 , V_584 , V_105 ) ;
return F_102 ( V_2 , V_586 ,
V_4 -> V_411 [ V_559 ] , F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_194 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_560 * V_585 = & V_395 -> V_395 . V_585 ;
memset ( V_585 , 0 , sizeof( * V_585 ) ) ;
F_86 ( V_576 , & V_585 -> V_564 ) ;
return F_231 ( V_2 , V_395 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_560 * V_585 = & V_395 -> V_395 . V_585 ;
memset ( V_585 , 0 , sizeof( * V_585 ) ) ;
F_86 ( V_574 , & V_585 -> V_564 ) ;
F_86 ( V_576 , & V_585 -> V_564 ) ;
return F_231 ( V_2 , V_395 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
return - 1 ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
return F_102 ( V_2 , V_587 ,
V_4 -> V_411 [ V_412 ] , 0 , V_4 -> V_91 ,
V_194 ) ;
}
static inline int F_236 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
T_6 V_588 = V_395 -> V_395 . V_589 . V_559 ;
if ( V_588 >= V_4 -> V_414 ) {
F_12 ( L_84 ,
V_4 -> V_91 , V_588 ) ;
return - V_62 ;
}
return F_102 ( V_2 , V_590 ,
V_4 -> V_411 [ V_588 ] , 0 , 0 , V_591 ) ;
}
static inline int F_237 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
T_6 V_559 = V_395 -> V_395 . V_592 . V_559 ;
if ( V_559 >= V_4 -> V_414 ) {
F_12 ( L_84 ,
V_4 -> V_91 , V_559 ) ;
return - V_62 ;
}
return F_102 ( V_2 , V_593 ,
V_4 -> V_411 [ V_559 ] , 0 , 0 , V_194 ) ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_396 * V_4 = V_395 -> V_397 ;
return F_102 ( V_2 , V_594 ,
V_4 -> V_411 [ V_412 ] , 0 , 0 ,
V_194 ) ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
switch ( V_395 -> V_106 ) {
case V_552 :
return F_223 ( V_2 , V_395 ) ;
case V_595 :
return F_229 ( V_2 , V_395 ) ;
case V_408 :
return F_232 ( V_2 , V_395 ) ;
case V_407 :
return F_233 ( V_2 , V_395 ) ;
case V_409 :
return F_231 ( V_2 , V_395 ) ;
case V_596 :
return F_234 ( V_2 , V_395 ) ;
case V_597 :
return F_235 ( V_2 , V_395 ) ;
case V_598 :
return F_236 ( V_2 , V_395 ) ;
case V_599 :
return F_237 ( V_2 , V_395 ) ;
case V_600 :
return F_238 ( V_2 , V_395 ) ;
default:
F_12 ( L_49 , V_395 -> V_106 ) ;
return - V_62 ;
}
}
static int F_240 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
switch ( V_395 -> V_106 ) {
case V_601 :
return F_227 ( V_2 , V_395 ) ;
case V_552 :
case V_595 :
case V_408 :
case V_407 :
case V_409 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
case V_600 :
return F_239 ( V_2 , V_395 ) ;
default:
F_12 ( L_49 , V_395 -> V_106 ) ;
return - V_62 ;
}
}
static int F_241 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
switch ( V_395 -> V_106 ) {
case V_601 :
return F_228 ( V_2 , V_395 ) ;
case V_552 :
case V_595 :
case V_408 :
case V_407 :
case V_409 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
case V_600 :
return F_239 ( V_2 , V_395 ) ;
default:
F_12 ( L_49 , V_395 -> V_106 ) ;
return - V_62 ;
}
}
static int F_242 ( struct V_1 * V_2 ,
struct V_396 * V_4 ,
struct V_394 * V_395 )
{
enum V_602 V_33 = V_4 -> V_33 , V_403 = V_404 ;
enum V_406 V_106 = V_395 -> V_106 ;
struct V_560 * V_584 =
& V_395 -> V_395 . V_585 ;
T_6 V_413 = V_4 -> V_415 ;
if ( F_20 ( V_28 , & V_395 -> V_25 ) ) {
V_4 -> V_399 = 0 ;
V_4 -> V_403 = V_404 ;
}
if ( V_4 -> V_399 )
return - V_37 ;
switch ( V_33 ) {
case V_603 :
if ( V_106 == V_552 )
V_403 = V_604 ;
break;
case V_604 :
if ( V_106 == V_601 ) {
if ( F_20 ( V_437 ,
& V_395 -> V_395 . V_419 . V_133 ) )
V_403 = V_605 ;
else
V_403 = V_606 ;
}
break;
case V_605 :
if ( V_106 == V_408 )
V_403 = V_606 ;
else if ( ( V_106 == V_600 ) ||
( V_106 == V_596 ) )
V_403 = V_605 ;
else if ( V_106 == V_595 ) {
V_403 = V_607 ;
V_413 = 1 ;
}
else if ( V_106 == V_597 )
V_403 = V_608 ;
else if ( V_106 == V_409 ) {
if ( F_20 ( V_576 ,
& V_584 -> V_564 ) &&
! F_20 ( V_574 ,
& V_584 -> V_564 ) )
V_403 = V_606 ;
else
V_403 = V_605 ;
}
break;
case V_607 :
if ( V_106 == V_599 )
V_403 = V_609 ;
else if ( V_106 == V_595 ) {
V_403 = V_607 ;
V_413 = V_4 -> V_415 + 1 ;
}
else if ( ( V_106 == V_600 ) ||
( V_106 == V_596 ) )
V_403 = V_607 ;
else if ( V_106 == V_409 ) {
if ( F_20 ( V_576 ,
& V_584 -> V_564 ) &&
! F_20 ( V_574 ,
& V_584 -> V_564 ) )
V_403 = V_606 ;
else
V_403 = V_607 ;
}
break;
case V_609 :
if ( V_106 == V_598 ) {
V_413 = V_4 -> V_415 - 1 ;
if ( V_413 == 0 )
V_403 = V_605 ;
else
V_403 = V_607 ;
}
break;
case V_606 :
if ( V_106 == V_407 )
V_403 = V_605 ;
else if ( ( V_106 == V_600 ) ||
( V_106 == V_596 ) )
V_403 = V_606 ;
else if ( V_106 == V_597 )
V_403 = V_608 ;
else if ( V_106 == V_409 ) {
if ( F_20 ( V_576 ,
& V_584 -> V_564 ) &&
F_20 ( V_574 ,
& V_584 -> V_564 ) ) {
if ( V_4 -> V_415 == 0 )
V_403 = V_605 ;
else
V_403 = V_607 ;
} else
V_403 = V_606 ;
}
break;
case V_608 :
if ( V_106 == V_599 )
V_403 = V_610 ;
break;
case V_610 :
if ( V_106 == V_598 )
V_403 = V_603 ;
break;
default:
F_12 ( L_87 , V_33 ) ;
}
if ( V_403 != V_404 ) {
F_4 ( V_17 , L_88 ,
V_33 , V_106 , V_403 ) ;
V_4 -> V_403 = V_403 ;
V_4 -> V_413 = V_413 ;
return 0 ;
}
F_4 ( V_17 , L_89 , V_33 , V_106 ) ;
return - V_62 ;
}
void F_243 ( struct V_1 * V_2 ,
struct V_396 * V_405 ,
T_6 V_91 , V_59 * V_411 , T_6 V_611 , T_6 V_92 ,
void * V_105 ,
T_8 V_193 , unsigned long type )
{
memset ( V_405 , 0 , sizeof( * V_405 ) ) ;
F_244 ( V_612 < V_611 ) ;
memcpy ( V_405 -> V_411 , V_411 , sizeof( V_405 -> V_411 [ 0 ] ) * V_611 ) ;
V_405 -> V_414 = V_611 ;
V_405 -> V_91 = V_91 ;
V_405 -> V_92 = V_92 ;
V_405 -> V_105 = V_105 ;
V_405 -> V_193 = V_193 ;
V_405 -> type = type ;
V_405 -> V_403 = V_404 ;
if ( F_112 ( V_2 ) )
V_405 -> V_402 = F_240 ;
else
V_405 -> V_402 = F_241 ;
V_405 -> V_400 = F_242 ;
V_405 -> V_401 = F_213 ;
V_405 -> V_172 = F_212 ;
V_405 -> V_189 = F_211 ;
}
enum V_613 F_245 ( struct V_1 * V_2 ,
struct V_614 * V_4 )
{
if ( V_4 -> V_399 )
return V_615 ;
F_246 () ;
return V_4 -> V_33 ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_614 * V_4 ,
enum V_616 V_106 )
{
return F_34 ( V_2 , V_106 , & V_4 -> V_399 ) ;
}
static inline int F_248 ( struct V_1 * V_2 ,
struct V_614 * V_4 ,
enum V_616 V_106 )
{
unsigned long V_410 = V_4 -> V_399 ;
if ( ! F_214 ( V_106 , & V_410 ) ) {
F_12 ( L_90 ,
V_106 , F_249 ( V_2 ) , V_4 -> V_33 ,
V_410 , V_4 -> V_403 ) ;
return - V_62 ;
}
F_4 ( V_17 ,
L_91 ,
V_106 , F_249 ( V_2 ) , V_4 -> V_403 ) ;
V_4 -> V_33 = V_4 -> V_403 ;
V_4 -> V_403 = V_615 ;
F_215 () ;
F_30 ( V_106 , & V_4 -> V_399 ) ;
F_31 () ;
return 0 ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_614 * V_4 ,
enum V_616 V_106 )
{
int V_22 = F_248 ( V_2 , V_4 , V_106 ) ;
return V_22 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_614 * V_4 ,
struct V_617 * V_395 )
{
enum V_613 V_33 = V_4 -> V_33 , V_403 = V_615 ;
enum V_616 V_106 = V_395 -> V_106 ;
if ( F_20 ( V_28 , & V_395 -> V_25 ) ) {
V_4 -> V_399 = 0 ;
V_4 -> V_403 = V_615 ;
}
if ( V_4 -> V_399 )
return - V_37 ;
switch ( V_33 ) {
case V_618 :
if ( V_106 == V_619 )
V_403 = V_620 ;
break;
case V_620 :
if ( V_106 == V_621 )
V_403 = V_622 ;
else if ( V_106 == V_623 )
V_403 = V_618 ;
break;
case V_622 :
if ( V_106 == V_624 )
V_403 = V_620 ;
else if ( ( V_106 == V_625 ) &&
( ! F_20 ( V_624 , & V_4 -> V_399 ) ) )
V_403 = V_622 ;
else if ( ( V_106 == V_626 ) &&
( ! F_20 ( V_624 , & V_4 -> V_399 ) ) )
V_403 = V_622 ;
else if ( V_106 == V_627 )
V_403 = V_628 ;
break;
case V_628 :
if ( V_106 == V_629 )
V_403 = V_622 ;
break;
default:
F_12 ( L_92 , V_33 ) ;
}
if ( V_403 != V_615 ) {
F_4 ( V_17 , L_93 ,
V_33 , V_106 , V_403 ) ;
V_4 -> V_403 = V_403 ;
return 0 ;
}
F_4 ( V_17 , L_94 ,
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
struct V_617 * V_395 )
{
V_59 V_636 = V_395 -> V_395 . V_637 . V_638 ;
struct V_614 * V_4 = V_395 -> V_639 ;
const struct V_630 * V_631 = V_4 -> V_631 ;
int V_22 = 0 ;
F_4 ( V_17 , L_95 ,
F_257 ( V_2 ) , V_636 ) ;
V_22 = V_631 -> V_640 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_631 -> V_641 ( V_2 ) ;
if ( V_22 ) {
F_12 ( L_96 ) ;
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
F_12 ( L_97 , V_636 ) ;
V_22 = - V_62 ;
}
V_642:
V_631 -> V_647 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_401 ( V_2 , V_4 , V_619 ) ;
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
struct V_617 * V_395 )
{
V_59 V_651 = V_395 -> V_395 . V_652 . V_651 ;
struct V_614 * V_4 = V_395 -> V_639 ;
const struct V_630 * V_631 = V_4 -> V_631 ;
F_4 ( V_17 , L_98 , F_257 ( V_2 ) ,
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
F_12 ( L_99 ,
V_651 ) ;
break;
}
V_4 -> V_401 ( V_2 , V_4 , V_623 ) ;
return 0 ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
struct V_614 * V_4 = V_395 -> V_639 ;
struct V_656 * V_105 =
(struct V_656 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
struct V_657 * V_658 = & V_395 -> V_395 . V_659 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_660 = F_76 ( V_658 -> V_661 ) ;
V_105 -> V_662 = F_76 ( V_658 -> V_662 ) ;
V_105 -> V_663 = F_263 ( V_2 ) ;
V_105 -> V_664 = V_658 -> V_664 ;
return F_102 ( V_2 , V_665 , 0 ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_591 ) ;
}
static inline int F_264 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
struct V_614 * V_4 = V_395 -> V_639 ;
struct V_666 * V_105 =
(struct V_666 * ) V_4 -> V_667 ;
T_8 V_553 = V_4 -> V_668 ;
struct V_669 * V_670 =
& V_395 -> V_395 . V_671 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_672 = 1 ;
V_105 -> V_673 = F_76 ( V_670 -> V_673 ) ;
V_105 -> V_674 = 1 ;
V_105 -> V_675 =
F_76 ( V_670 -> V_675 ) ;
V_105 -> V_676 = 1 ;
V_105 -> V_677 = V_670 -> V_677 ;
F_4 ( V_17 ,
L_100 ,
V_105 -> V_673 ,
V_105 -> V_675 , V_105 -> V_677 ) ;
return F_102 ( V_2 , V_678 , 0 ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_591 ) ;
}
static
inline int F_265 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
struct V_614 * V_4 = V_395 -> V_639 ;
struct V_679 * V_105 =
(struct V_679 * ) V_4 -> V_667 ;
struct V_680 * V_681 =
& V_395 -> V_395 . V_682 ;
T_11 * V_683 = ( T_11 * ) V_105 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_684 = V_681 -> V_684 ;
V_105 -> V_685 = V_681 -> V_685 ;
V_105 -> V_686 =
V_681 -> V_686 ;
V_105 -> V_687 = V_681 -> V_687 ;
V_105 -> V_99 = V_681 -> V_686 ;
F_4 ( V_17 , L_101 ,
V_105 -> V_686 , V_105 -> V_684 ,
V_105 -> V_685 , V_105 -> V_687 ) ;
return F_102 ( V_2 , V_688 , 0 ,
F_103 ( * V_683 ) , F_104 ( * V_683 ) ,
V_591 ) ;
}
static inline int F_266 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
return F_102 ( V_2 , V_689 , 0 , 0 , 0 ,
V_591 ) ;
}
static inline int F_267 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
return F_102 ( V_2 , V_690 , 0 , 0 , 0 ,
V_591 ) ;
}
static inline int F_268 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
struct V_614 * V_4 = V_395 -> V_639 ;
struct V_691 * V_105 =
(struct V_691 * ) V_4 -> V_105 ;
T_8 V_553 = V_4 -> V_193 ;
struct V_692 * V_693 =
& V_395 -> V_395 . V_694 ;
int V_281 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_695 = V_693 -> V_695 ;
V_105 -> V_696 = V_693 -> V_696 ;
V_105 -> V_697 = V_693 -> V_697 ;
for ( V_281 = 0 ; V_281 < F_269 ( V_105 -> V_698 ) ; V_281 ++ )
V_105 -> V_698 [ V_281 ] =
V_693 -> V_698 [ V_281 ] ;
return F_102 ( V_2 , V_699 , 0 ,
F_103 ( V_553 ) ,
F_104 ( V_553 ) , V_591 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
switch ( V_395 -> V_106 ) {
case V_619 :
return F_256 ( V_2 , V_395 ) ;
case V_621 :
return F_262 ( V_2 , V_395 ) ;
case V_624 :
return F_266 ( V_2 , V_395 ) ;
case V_623 :
return F_261 ( V_2 , V_395 ) ;
case V_625 :
return F_264 ( V_2 , V_395 ) ;
case V_626 :
return F_265 ( V_2 , V_395 ) ;
case V_627 :
return F_267 ( V_2 , V_395 ) ;
case V_629 :
return F_268 ( V_2 , V_395 ) ;
default:
F_12 ( L_49 , V_395 -> V_106 ) ;
return - V_62 ;
}
}
void F_271 ( struct V_1 * V_2 ,
struct V_614 * V_405 ,
void * V_105 , T_8 V_193 ,
void * V_667 , T_8 V_668 ,
struct V_630 * V_700 )
{
memset ( V_405 , 0 , sizeof( * V_405 ) ) ;
F_272 ( & V_405 -> V_701 ) ;
V_405 -> V_105 = V_105 ;
V_405 -> V_193 = V_193 ;
V_405 -> V_667 = V_667 ;
V_405 -> V_668 = V_668 ;
V_405 -> V_402 = F_270 ;
V_405 -> V_400 = F_251 ;
V_405 -> V_401 = F_250 ;
V_405 -> V_172 = F_247 ;
V_405 -> V_631 = V_700 ;
}
int F_273 ( struct V_1 * V_2 ,
struct V_617 * V_395 )
{
struct V_614 * V_4 = V_395 -> V_639 ;
int V_22 ;
enum V_616 V_106 = V_395 -> V_106 ;
unsigned long * V_399 = & V_4 -> V_399 ;
F_274 ( & V_4 -> V_701 ) ;
if ( V_4 -> V_400 ( V_2 , V_4 , V_395 ) ) {
F_275 ( & V_4 -> V_701 ) ;
return - V_62 ;
}
F_33 ( V_106 , V_399 ) ;
if ( F_20 ( V_28 , & V_395 -> V_25 ) ) {
F_248 ( V_2 , V_4 , V_106 ) ;
F_275 ( & V_4 -> V_701 ) ;
} else {
V_22 = V_4 -> V_402 ( V_2 , V_395 ) ;
F_275 ( & V_4 -> V_701 ) ;
if ( V_22 ) {
V_4 -> V_403 = V_615 ;
F_30 ( V_106 , V_399 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_198 , & V_395 -> V_25 ) ) {
V_22 = V_4 -> V_172 ( V_2 , V_4 , V_106 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_106 , V_399 ) ;
}
