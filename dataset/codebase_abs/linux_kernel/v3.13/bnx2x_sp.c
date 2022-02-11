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
static int F_51 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
if ( V_4 -> V_49 ) {
F_4 ( V_17 , L_9 ) ;
return - V_37 ;
}
F_4 ( V_17 , L_10 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
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
static void F_53 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long V_25 )
{
V_4 -> V_51 = true ;
V_4 -> V_50 = V_25 ;
F_4 ( V_17 , L_13 ,
V_25 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
while ( V_4 -> V_51 ) {
F_4 ( V_17 , L_14 ) ;
F_52 ( V_2 , V_4 ) ;
}
}
void F_55 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
V_4 -> V_49 ++ ;
F_4 ( V_17 , L_15 ,
V_4 -> V_49 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_22 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
V_22 = F_56 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
return V_22 ;
}
static void F_58 ( struct V_1 * V_2 ,
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
F_54 ( V_2 , V_4 ) ;
}
}
void F_59 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_58 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_39 * V_4 ,
int V_52 , T_6 * V_53 , T_6 V_54 , T_6 V_55 )
{
struct V_56 * V_57 ;
T_6 * V_58 = V_53 ;
int V_59 = 0 ;
int V_60 ;
F_4 ( V_17 , L_19 ) ;
V_60 = F_57 ( V_2 , V_4 ) ;
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
F_59 ( V_2 , V_4 ) ;
}
return V_59 * V_62 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_23 , V_64 -> V_65 . V_65 ) ;
if ( ! F_62 ( V_64 -> V_65 . V_65 ) )
return - V_66 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 , V_62 ) &&
( V_64 -> V_65 . V_67 == V_57 -> V_61 . V_65 . V_67 ) )
return - V_68 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
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
static int F_64 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_25 ,
V_64 -> V_70 . V_65 , V_64 -> V_70 . V_69 ) ;
F_9 (pos, &o->head, link)
if ( ( V_64 -> V_70 . V_69 == V_57 -> V_61 . V_70 . V_69 ) &&
( ! memcmp ( V_64 -> V_70 . V_65 , V_57 -> V_61 . V_70 . V_65 ,
V_62 ) ) &&
( V_64 -> V_70 . V_67 ==
V_57 -> V_61 . V_70 . V_67 ) )
return - V_68 ;
return 0 ;
}
static struct V_56 *
F_65 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_26 , V_64 -> V_65 . V_65 ) ;
F_9 (pos, &o->head, link)
if ( ( ! memcmp ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 , V_62 ) ) &&
( V_64 -> V_65 . V_67 == V_57 -> V_61 . V_65 . V_67 ) )
return V_57 ;
return NULL ;
}
static struct V_56 *
F_66 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_27 , V_64 -> V_69 . V_69 ) ;
F_9 (pos, &o->head, link)
if ( V_64 -> V_69 . V_69 == V_57 -> V_61 . V_69 . V_69 )
return V_57 ;
return NULL ;
}
static struct V_56 *
F_67 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_28 ,
V_64 -> V_70 . V_65 , V_64 -> V_70 . V_69 ) ;
F_9 (pos, &o->head, link)
if ( ( V_64 -> V_70 . V_69 == V_57 -> V_61 . V_70 . V_69 ) &&
( ! memcmp ( V_64 -> V_70 . V_65 , V_57 -> V_61 . V_70 . V_65 ,
V_62 ) ) &&
( V_64 -> V_70 . V_67 ==
V_57 -> V_61 . V_70 . V_67 ) )
return V_57 ;
return NULL ;
}
static bool F_68 ( struct V_1 * V_2 ,
struct V_39 * V_71 ,
struct V_39 * V_72 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
int V_22 ;
V_57 = V_71 -> V_73 ( V_2 , V_71 , V_64 ) ;
V_22 = V_72 -> V_74 ( V_2 , V_72 , V_64 ) ;
if ( V_22 || ! V_57 )
return false ;
return true ;
}
static bool F_69 (
struct V_1 * V_2 ,
struct V_39 * V_71 ,
struct V_39 * V_72 ,
union V_63 * V_64 )
{
return false ;
}
static inline T_6 F_70 ( struct V_39 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_75 = 0 ;
if ( ( V_38 -> V_76 == V_77 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_79 ;
if ( ( V_38 -> V_76 == V_80 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_81 ;
return V_75 ;
}
void F_71 ( struct V_1 * V_2 ,
bool V_82 , unsigned char * V_83 , int V_84 )
{
T_7 V_85 [ 2 ] ;
T_7 V_86 = F_72 ( V_2 ) ? V_87 :
V_88 ;
if ( ! F_73 ( V_2 ) && ! F_74 ( V_2 ) )
return;
if ( V_84 > V_89 )
return;
F_4 ( V_17 , L_29 ,
( V_82 ? L_30 : L_31 ) , V_84 ) ;
if ( V_82 ) {
V_86 += 8 * V_84 ;
V_85 [ 0 ] = ( ( V_83 [ 2 ] << 24 ) | ( V_83 [ 3 ] << 16 ) |
( V_83 [ 4 ] << 8 ) | V_83 [ 5 ] ) ;
V_85 [ 1 ] = ( ( V_83 [ 0 ] << 8 ) | V_83 [ 1 ] ) ;
F_75 ( V_2 , V_86 , V_85 , 2 ) ;
}
F_76 ( V_2 , ( F_72 ( V_2 ) ? V_90 :
V_91 ) + 4 * V_84 , V_82 ) ;
}
static inline void F_77 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_82 , int V_92 ,
struct V_93 * V_94 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_94 -> V_95 = V_38 -> V_96 ;
V_94 -> V_97 = V_38 -> V_97 ;
V_94 -> V_98 |=
F_70 ( V_4 ) ;
if ( V_82 )
V_94 -> V_98 |= V_99 ;
V_94 -> V_98 |=
( V_92 << V_100 ) ;
}
static inline void F_78 ( T_7 V_101 , int type ,
struct V_102 * V_94 , int V_103 )
{
V_94 -> V_104 = F_79 ( ( V_101 & V_105 ) |
( type << V_106 ) ) ;
V_94 -> V_103 = ( T_6 ) V_103 ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_107 ,
int V_108 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_109 * V_64 =
(struct V_109 * ) ( V_38 -> V_110 ) ;
int V_103 = V_107 + 1 , V_111 = V_19 -> V_112 . V_70 . V_111 ;
union V_113 * V_114 = & V_64 -> V_115 [ V_107 ] ;
bool V_82 = ( V_111 == V_116 ) ? true : false ;
unsigned long * V_117 = & V_19 -> V_112 . V_70 . V_117 ;
T_6 * V_65 = V_19 -> V_112 . V_70 . V_61 . V_65 . V_65 ;
if ( V_111 != V_118 ) {
if ( F_18 ( V_119 , V_117 ) )
F_71 ( V_2 , V_82 , V_65 ,
V_120 ) ;
else if ( F_18 ( V_121 , V_117 ) )
F_71 ( V_2 , V_82 , V_65 ,
V_122 ) ;
}
if ( V_107 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_77 ( V_2 , V_4 , V_82 , V_123 ,
& V_114 -> V_65 . V_124 ) ;
F_4 ( V_17 , L_32 ,
( V_82 ? L_33 : L_34 ) , V_65 , V_38 -> V_96 ) ;
F_81 ( & V_114 -> V_65 . V_125 ,
& V_114 -> V_65 . V_126 ,
& V_114 -> V_65 . V_127 , V_65 ) ;
V_114 -> V_65 . V_128 =
F_82 ( V_19 -> V_112 . V_70 . V_61 . V_65 . V_67 ) ;
if ( V_111 == V_118 ) {
V_114 ++ ;
V_103 ++ ;
F_77 ( V_2 ,
V_19 -> V_112 . V_70 . V_129 ,
true , V_123 ,
& V_114 -> V_65 . V_124 ) ;
F_81 ( & V_114 -> V_65 . V_125 ,
& V_114 -> V_65 . V_126 ,
& V_114 -> V_65 . V_127 , V_65 ) ;
V_114 -> V_65 . V_128 =
F_82 ( V_19 -> V_112 . V_70 .
V_61 . V_65 . V_67 ) ;
}
F_78 ( V_38 -> V_101 , V_38 -> V_33 , & V_64 -> V_124 ,
V_103 ) ;
}
static inline void F_83 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_108 ,
struct V_130 * V_94 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
V_94 -> V_132 = 1 ;
V_94 -> V_40 = ( T_6 ) V_108 ;
V_94 -> V_95 = F_82 ( 0xff ) ;
V_94 -> V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( type << V_106 ) ) ;
}
static inline void F_84 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_82 , int V_92 , T_6 * V_65 ,
T_8 V_133 , struct V_134 * V_135 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
T_7 V_136 = ( 1 << V_131 -> V_96 ) ;
V_135 -> V_137 = F_79 ( V_136 ) ;
V_135 -> V_138 = V_131 -> V_97 ;
V_135 -> V_133 = F_82 ( V_133 ) ;
if ( V_82 ) {
F_85 ( V_135 -> V_139 , V_140 ,
V_141 ) ;
F_85 ( V_135 -> V_139 ,
V_142 , V_92 ) ;
F_81 ( & V_135 -> V_143 ,
& V_135 -> V_144 ,
& V_135 -> V_145 , V_65 ) ;
} else
F_85 ( V_135 -> V_139 , V_140 ,
V_146 ) ;
}
static inline void F_86 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_108 , bool V_82 ,
T_6 * V_65 , T_8 V_133 , int V_92 , struct V_147 * V_148 )
{
struct V_134 * V_135 = & V_148 -> V_149 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_83 ( V_2 , V_4 , type , V_108 ,
& V_148 -> V_94 ) ;
F_84 ( V_2 , V_4 , V_82 , V_92 , V_65 , V_133 ,
V_135 ) ;
F_4 ( V_17 , L_35 ,
( V_82 ? L_36 : L_37 ) ,
V_65 , V_38 -> V_96 , V_108 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_107 ,
int V_108 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_148 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
bool V_82 = ( V_19 -> V_112 . V_70 . V_111 == V_116 ) ?
true : false ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
F_86 ( V_2 , V_4 , V_38 -> V_33 ,
V_108 , V_82 ,
V_19 -> V_112 . V_70 . V_61 . V_65 . V_65 , 0 ,
V_150 , V_148 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_107 ,
int V_108 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_109 * V_64 =
(struct V_109 * ) ( V_38 -> V_110 ) ;
int V_103 = V_107 + 1 ;
union V_113 * V_114 = & V_64 -> V_115 [ V_107 ] ;
enum V_151 V_111 = V_19 -> V_112 . V_70 . V_111 ;
bool V_82 = ( V_111 == V_116 ) ? true : false ;
T_8 V_69 = V_19 -> V_112 . V_70 . V_61 . V_69 . V_69 ;
if ( V_107 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_77 ( V_2 , V_4 , V_82 , V_152 ,
& V_114 -> V_69 . V_124 ) ;
F_4 ( V_17 , L_38 , ( V_82 ? L_33 : L_34 ) ,
V_69 ) ;
V_114 -> V_69 . V_69 = F_82 ( V_69 ) ;
if ( V_111 == V_118 ) {
V_114 ++ ;
V_103 ++ ;
F_77 ( V_2 ,
V_19 -> V_112 . V_70 . V_129 ,
true , V_152 ,
& V_114 -> V_69 . V_124 ) ;
V_114 -> V_69 . V_69 = F_82 ( V_69 ) ;
}
F_78 ( V_38 -> V_101 , V_38 -> V_33 , & V_64 -> V_124 ,
V_103 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_107 , int V_108 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_109 * V_64 =
(struct V_109 * ) ( V_38 -> V_110 ) ;
int V_103 = V_107 + 1 ;
union V_113 * V_114 = & V_64 -> V_115 [ V_107 ] ;
enum V_151 V_111 = V_19 -> V_112 . V_70 . V_111 ;
bool V_82 = ( V_111 == V_116 ) ? true : false ;
T_8 V_69 = V_19 -> V_112 . V_70 . V_61 . V_70 . V_69 ;
T_6 * V_65 = V_19 -> V_112 . V_70 . V_61 . V_70 . V_65 ;
if ( V_107 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_77 ( V_2 , V_4 , V_82 , V_153 ,
& V_114 -> V_154 . V_124 ) ;
V_114 -> V_154 . V_69 = F_82 ( V_69 ) ;
F_81 ( & V_114 -> V_154 . V_125 ,
& V_114 -> V_154 . V_126 ,
& V_114 -> V_154 . V_127 , V_65 ) ;
V_114 -> V_154 . V_128 =
F_82 ( V_19 -> V_112 . V_70 . V_61 . V_70 . V_67 ) ;
if ( V_111 == V_118 ) {
V_114 ++ ;
V_103 ++ ;
F_77 ( V_2 ,
V_19 -> V_112 . V_70 . V_129 ,
true , V_153 ,
& V_114 -> V_154 . V_124 ) ;
V_114 -> V_154 . V_69 = F_82 ( V_69 ) ;
F_81 ( & V_114 -> V_154 . V_125 ,
& V_114 -> V_154 . V_126 ,
& V_114 -> V_154 . V_127 , V_65 ) ;
V_114 -> V_154 . V_128 =
F_82 ( V_19 -> V_112 . V_70 . V_61 .
V_70 . V_67 ) ;
}
F_78 ( V_38 -> V_101 , V_38 -> V_33 , & V_64 -> V_124 ,
V_103 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_107 , int V_108 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_148 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
bool V_82 = ( V_19 -> V_112 . V_70 . V_111 == V_116 ) ?
true : false ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
F_86 ( V_2 , V_4 , V_155 ,
V_108 , V_82 ,
V_19 -> V_112 . V_70 . V_61 . V_70 . V_65 ,
V_19 -> V_112 . V_70 . V_61 . V_70 . V_69 ,
V_156 , V_148 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_157 * V_158 ,
struct V_56 * * V_159 )
{
struct V_56 * V_57 ;
struct V_39 * V_4 = V_158 -> V_160 ;
if ( F_14 ( & V_4 -> V_161 ) ) {
* V_159 = NULL ;
return 0 ;
}
if ( * V_159 == NULL )
* V_159 = F_15 ( & V_4 -> V_161 ,
struct V_56 ,
V_24 ) ;
else
* V_159 = F_92 ( * V_159 , V_24 ) ;
V_57 = * V_159 ;
if ( F_93 ( & V_57 -> V_24 , & V_4 -> V_161 ) )
* V_159 = NULL ;
memcpy ( & V_158 -> V_162 . V_61 , & V_57 -> V_61 , sizeof( V_57 -> V_61 ) ) ;
V_158 -> V_162 . V_111 = V_116 ;
V_158 -> V_162 . V_117 = V_57 -> V_117 ;
F_94 ( V_163 , & V_158 -> V_25 ) ;
return F_95 ( V_2 , V_158 ) ;
}
static struct V_18 * F_96 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_57 ;
struct V_164 * V_64 = & V_19 -> V_112 . V_70 . V_61 . V_65 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_57 -> V_112 . V_70 . V_61 . V_65 , V_64 ,
sizeof( * V_64 ) ) &&
( V_57 -> V_112 . V_70 . V_111 == V_19 -> V_112 . V_70 . V_111 ) )
return V_57 ;
return NULL ;
}
static struct V_18 * F_97 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_57 ;
struct V_165 * V_64 = & V_19 -> V_112 . V_70 . V_61 . V_69 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_57 -> V_112 . V_70 . V_61 . V_69 , V_64 ,
sizeof( * V_64 ) ) &&
( V_57 -> V_112 . V_70 . V_111 == V_19 -> V_112 . V_70 . V_111 ) )
return V_57 ;
return NULL ;
}
static struct V_18 * F_98 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_57 ;
struct V_166 * V_64 =
& V_19 -> V_112 . V_70 . V_61 . V_70 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_57 -> V_112 . V_70 . V_61 . V_70 , V_64 ,
sizeof( * V_64 ) ) &&
( V_57 -> V_112 . V_70 . V_111 == V_19 -> V_112 . V_70 . V_111 ) )
return V_57 ;
return NULL ;
}
static inline int F_99 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_167 -> V_70 ;
struct V_3 * V_168 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_74 ( V_2 , V_4 , & V_19 -> V_112 . V_70 . V_61 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_39 ) ;
return V_22 ;
}
if ( V_168 -> V_11 ( V_168 , V_19 ) ) {
F_4 ( V_17 , L_40 ) ;
return - V_68 ;
}
if ( ! ( F_18 ( V_169 ,
& V_19 -> V_112 . V_70 . V_117 ) ||
V_4 -> V_170 ( V_4 ) ) )
return - V_66 ;
return 0 ;
}
static inline int F_100 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_167 -> V_70 ;
struct V_56 * V_57 ;
struct V_3 * V_168 = & V_4 -> V_12 ;
struct V_18 V_171 ;
V_57 = V_4 -> V_73 ( V_2 , V_4 , & V_19 -> V_112 . V_70 . V_61 ) ;
if ( ! V_57 ) {
F_4 ( V_17 , L_41 ) ;
return - V_68 ;
}
memcpy ( & V_171 , V_19 , sizeof( V_171 ) ) ;
V_171 . V_112 . V_70 . V_111 = V_118 ;
if ( V_168 -> V_11 ( V_168 , & V_171 ) ) {
F_38 ( L_42 ) ;
return - V_66 ;
}
if ( V_168 -> V_11 ( V_168 , V_19 ) ) {
F_4 ( V_17 , L_43 ) ;
return - V_68 ;
}
if ( ! ( F_18 ( V_169 ,
& V_19 -> V_112 . V_70 . V_117 ) ||
V_4 -> V_172 ( V_4 ) ) ) {
F_38 ( L_44 ) ;
return - V_66 ;
}
return 0 ;
}
static inline int F_101 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
struct V_39 * V_71 = & V_167 -> V_70 ;
struct V_39 * V_173 = V_19 -> V_112 . V_70 . V_129 ;
struct V_18 V_171 ;
struct V_3 * V_174 = & V_71 -> V_12 ;
struct V_3 * V_175 = & V_173 -> V_12 ;
if ( ! V_71 -> V_176 ( V_2 , V_71 , V_173 ,
& V_19 -> V_112 . V_70 . V_61 ) ) {
F_4 ( V_17 , L_45 ) ;
return - V_66 ;
}
memcpy ( & V_171 , V_19 , sizeof( V_171 ) ) ;
V_171 . V_112 . V_70 . V_111 = V_177 ;
if ( V_174 -> V_11 ( V_174 , & V_171 ) ) {
F_38 ( L_46 ) ;
return - V_66 ;
}
if ( V_174 -> V_11 ( V_174 , V_19 ) ) {
F_4 ( V_17 , L_42 ) ;
return - V_68 ;
}
V_171 . V_112 . V_70 . V_111 = V_116 ;
if ( V_175 -> V_11 ( V_175 , & V_171 ) ) {
F_38 ( L_47 ) ;
return - V_66 ;
}
if ( ! ( F_18 ( V_178 ,
& V_19 -> V_112 . V_70 . V_117 ) ||
V_173 -> V_170 ( V_173 ) ) )
return - V_66 ;
if ( ! ( F_18 ( V_169 ,
& V_19 -> V_112 . V_70 . V_117 ) ||
V_71 -> V_172 ( V_71 ) ) ) {
V_173 -> V_172 ( V_173 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_112 . V_70 . V_111 ) {
case V_116 :
return F_99 ( V_2 , V_167 , V_19 ) ;
case V_177 :
return F_100 ( V_2 , V_167 , V_19 ) ;
case V_118 :
return F_101 ( V_2 , V_167 , V_19 ) ;
default:
return - V_66 ;
}
}
static int F_103 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
int V_22 = 0 ;
if ( F_18 ( V_169 ,
& V_19 -> V_112 . V_70 . V_117 ) )
return 0 ;
switch ( V_19 -> V_112 . V_70 . V_111 ) {
case V_116 :
case V_118 :
V_22 = V_167 -> V_70 . V_172 ( & V_167 -> V_70 ) ;
break;
case V_177 :
V_22 = V_167 -> V_70 . V_170 ( & V_167 -> V_70 ) ;
break;
default:
return - V_66 ;
}
if ( V_22 != true )
return - V_66 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_168 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_179 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_23 ( V_168 ) )
F_37 ( 1000 , 2000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_25 )
{
int V_22 = 0 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_4 ( V_17 , L_48 ) ;
V_22 = F_51 ( V_2 , V_4 ) ;
if ( V_22 != 0 ) {
F_53 ( V_2 , V_4 , * V_25 ) ;
V_22 = 1 ;
} else {
V_22 = F_17 ( V_2 , & V_4 -> V_12 , V_25 ) ;
}
F_10 ( & V_4 -> V_12 . V_14 ) ;
return V_22 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_180 * V_181 ,
unsigned long * V_25 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_13 ( V_2 , & V_4 -> V_12 ) ;
V_131 -> V_182 ( V_131 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
if ( V_181 -> V_183 . error )
return - V_66 ;
if ( F_18 ( V_184 , V_25 ) ) {
V_22 = F_105 ( V_2 , V_4 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_23 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_18 * V_19 )
{
struct V_18 V_185 , * V_57 ;
struct V_39 * V_4 = & V_167 -> V_70 ;
struct V_3 * V_168 = & V_4 -> V_12 ;
memcpy ( & V_185 , V_19 , sizeof( V_185 ) ) ;
switch ( V_19 -> V_112 . V_70 . V_111 ) {
case V_116 :
V_185 . V_112 . V_70 . V_111 = V_177 ;
break;
case V_177 :
V_185 . V_112 . V_70 . V_111 = V_116 ;
break;
default:
return 0 ;
}
V_57 = V_168 -> V_11 ( V_168 , & V_185 ) ;
if ( V_57 ) {
if ( ! F_18 ( V_169 ,
& V_57 -> V_112 . V_70 . V_117 ) ) {
if ( ( V_185 . V_112 . V_70 . V_111 ==
V_116 ) && ! V_4 -> V_172 ( V_4 ) ) {
F_38 ( L_49 ) ;
return - V_66 ;
} else if ( ! V_4 -> V_170 ( V_4 ) ) {
F_38 ( L_50 ) ;
return - V_66 ;
}
}
F_4 ( V_17 , L_51 ,
( V_19 -> V_112 . V_70 . V_111 == V_116 ) ?
L_30 : L_52 ) ;
F_16 ( & V_57 -> V_24 ) ;
F_5 ( V_2 , V_57 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_108 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_56 * * V_186 )
{
enum V_151 V_111 = V_19 -> V_112 . V_70 . V_111 ;
struct V_56 * V_187 ;
if ( ! V_21 &&
( ( V_111 == V_116 ) || ( V_111 == V_118 ) ) ) {
V_187 = F_25 ( sizeof( * V_187 ) , V_31 ) ;
if ( ! V_187 )
return - V_188 ;
if ( ! V_4 -> V_189 ( V_4 , & V_187 -> V_108 ) ) {
F_19 ( 1 ) ;
F_6 ( V_187 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_53 , V_187 -> V_108 ) ;
memcpy ( & V_187 -> V_61 , & V_19 -> V_112 . V_70 . V_61 ,
sizeof( V_187 -> V_61 ) ) ;
V_187 -> V_117 =
V_19 -> V_112 . V_70 . V_117 ;
} else
V_187 = V_4 -> V_73 ( V_2 , V_4 , & V_19 -> V_112 . V_70 . V_61 ) ;
* V_186 = V_187 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
union V_6 * V_167 ,
struct V_190 * V_191 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_167 -> V_70 , * V_192 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 , V_193 = 0 ;
bool V_21 = F_18 ( V_163 , V_25 ) ;
bool V_194 = F_18 ( V_28 , V_25 ) ;
struct V_56 * V_187 ;
enum V_151 V_111 ;
if ( ! V_194 ) {
F_19 ( V_131 -> V_195 ( V_131 ) ) ;
V_131 -> V_196 ( V_131 ) ;
F_9 (elem, exe_chunk, link) {
V_111 = V_19 -> V_112 . V_70 . V_111 ;
if ( V_111 == V_118 )
V_192 = V_19 -> V_112 . V_70 . V_129 ;
else
V_192 = V_4 ;
V_22 = F_108 ( V_2 , V_192 ,
V_19 , V_21 ,
& V_187 ) ;
if ( V_22 )
goto V_197;
F_19 ( ! V_187 ) ;
if ( ! V_21 &&
( ( V_111 == V_116 ) ||
( V_111 == V_118 ) ) )
F_110 ( & V_187 -> V_24 , & V_192 -> V_161 ) ;
V_4 -> V_198 ( V_2 , V_4 , V_19 , V_193 ,
V_187 -> V_108 ) ;
if ( V_111 == V_118 )
V_193 += 2 ;
else
V_193 ++ ;
}
V_22 = F_111 ( V_2 , V_4 -> V_199 , V_131 -> V_101 ,
F_112 ( V_131 -> V_200 ) ,
F_113 ( V_131 -> V_200 ) ,
V_201 ) ;
if ( V_22 )
goto V_197;
}
F_9 (elem, exe_chunk, link) {
V_111 = V_19 -> V_112 . V_70 . V_111 ;
if ( ( V_111 == V_177 ) ||
( V_111 == V_118 ) ) {
V_187 = V_4 -> V_73 ( V_2 , V_4 ,
& V_19 -> V_112 . V_70 . V_61 ) ;
F_19 ( ! V_187 ) ;
V_4 -> V_202 ( V_4 , V_187 -> V_108 ) ;
F_16 ( & V_187 -> V_24 ) ;
F_6 ( V_187 ) ;
}
}
if ( ! V_194 )
return 1 ;
else
return 0 ;
V_197:
V_131 -> V_182 ( V_131 ) ;
F_9 (elem, exe_chunk, link) {
V_111 = V_19 -> V_112 . V_70 . V_111 ;
if ( V_111 == V_118 )
V_192 = V_19 -> V_112 . V_70 . V_129 ;
else
V_192 = V_4 ;
if ( ! V_21 &&
( ( V_111 == V_116 ) ||
( V_111 == V_118 ) ) ) {
V_187 = V_4 -> V_73 ( V_2 , V_192 ,
& V_19 -> V_112 . V_70 . V_61 ) ;
if ( V_187 ) {
F_16 ( & V_187 -> V_24 ) ;
F_6 ( V_187 ) ;
}
}
}
return V_22 ;
}
static inline int F_114 (
struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_158 -> V_160 ;
bool V_21 = F_18 ( V_163 , & V_158 -> V_25 ) ;
V_19 = F_24 ( V_2 ) ;
if ( ! V_19 )
return - V_188 ;
switch ( V_158 -> V_162 . V_111 ) {
case V_118 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_112 . V_70 , & V_158 -> V_162 , sizeof( V_158 -> V_162 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_158 -> V_160 ;
unsigned long * V_25 = & V_158 -> V_25 ;
bool V_203 = F_18 ( V_184 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_203 ) {
V_22 = F_114 ( V_2 , V_158 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_23 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_18 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_54 ) ;
V_38 -> V_182 ( V_38 ) ;
}
if ( V_203 || F_18 ( V_204 , V_25 ) ||
F_18 ( V_205 , V_25 ) ) {
V_22 = F_105 ( V_2 , V_158 -> V_160 ,
& V_158 -> V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_18 ( V_205 , & V_158 -> V_25 ) ) {
int V_206 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_23 ( & V_4 -> V_12 ) &&
V_206 -- ) {
V_22 = V_38 -> V_179 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_105 ( V_2 ,
V_158 -> V_160 ,
& V_158 -> V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
return V_22 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_117 ,
unsigned long * V_25 )
{
struct V_56 * V_57 = NULL ;
struct V_157 V_158 ;
struct V_3 * V_168 = & V_4 -> V_12 ;
struct V_18 * V_207 , * V_208 ;
unsigned long V_139 ;
int V_60 ;
int V_22 = 0 ;
F_8 ( & V_168 -> V_14 ) ;
F_116 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
V_139 = V_207 -> V_112 . V_70 . V_117 ;
if ( F_117 ( V_139 ) ==
F_117 ( * V_117 ) ) {
V_22 = V_168 -> remove ( V_2 , V_168 -> V_7 , V_207 ) ;
if ( V_22 ) {
F_38 ( L_55 ) ;
F_10 ( & V_168 -> V_14 ) ;
return V_22 ;
}
F_16 ( & V_207 -> V_24 ) ;
F_5 ( V_2 , V_207 ) ;
}
}
F_10 ( & V_168 -> V_14 ) ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_160 = V_4 ;
V_158 . V_25 = * V_25 ;
V_158 . V_162 . V_111 = V_177 ;
F_118 ( V_205 , & V_158 . V_25 ) ;
F_118 ( V_204 , & V_158 . V_25 ) ;
F_118 ( V_184 , & V_158 . V_25 ) ;
F_4 ( V_17 , L_56 ) ;
V_60 = F_57 ( V_2 , V_4 ) ;
if ( V_60 != 0 )
return V_60 ;
F_9 (pos, &o->head, link) {
V_139 = V_57 -> V_117 ;
if ( F_117 ( V_139 ) ==
F_117 ( * V_117 ) ) {
V_158 . V_162 . V_117 = V_57 -> V_117 ;
memcpy ( & V_158 . V_162 . V_61 , & V_57 -> V_61 , sizeof( V_57 -> V_61 ) ) ;
V_22 = F_95 ( V_2 , & V_158 ) ;
if ( V_22 < 0 ) {
F_38 ( L_57 ) ;
F_59 ( V_2 , V_4 ) ;
return V_22 ;
}
}
}
F_4 ( V_17 , L_58 ) ;
F_59 ( V_2 , V_4 ) ;
V_158 . V_25 = * V_25 ;
F_94 ( V_184 , & V_158 . V_25 ) ;
return F_95 ( V_2 , & V_158 ) ;
}
static inline void F_119 ( struct V_32 * V_38 , T_6 V_96 ,
T_7 V_101 , T_6 V_97 , void * V_110 , T_9 V_200 , int V_33 ,
unsigned long * V_34 , T_10 type )
{
V_38 -> V_97 = V_97 ;
V_38 -> V_101 = V_101 ;
V_38 -> V_96 = V_96 ;
V_38 -> V_110 = V_110 ;
V_38 -> V_200 = V_200 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_76 = type ;
V_38 -> V_195 = F_26 ;
V_38 -> V_182 = F_27 ;
V_38 -> V_196 = F_31 ;
V_38 -> V_179 = F_40 ;
}
static inline void F_120 ( struct V_39 * V_4 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_161 ) ;
V_4 -> V_49 = 0 ;
V_4 -> V_51 = false ;
V_4 -> V_50 = 0 ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_209 = F_115 ;
V_4 -> V_21 = F_91 ;
V_4 -> V_210 = F_106 ;
V_4 -> V_211 = F_104 ;
F_119 ( & V_4 -> V_38 , V_96 , V_101 , V_97 , V_110 , V_200 ,
V_33 , V_34 , type ) ;
}
void F_121 ( struct V_1 * V_2 ,
struct V_39 * V_212 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , void * V_110 ,
T_9 V_200 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 )
{
union V_6 * V_213 = (union V_6 * ) V_212 ;
F_120 ( V_212 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_212 -> V_170 = F_42 ;
V_212 -> V_172 = F_47 ;
V_212 -> V_189 = F_41 ;
V_212 -> V_202 = F_46 ;
if ( F_122 ( V_2 ) ) {
V_212 -> V_198 = F_87 ;
V_212 -> V_73 = F_65 ;
V_212 -> V_74 = F_61 ;
V_212 -> V_176 = F_69 ;
V_212 -> V_199 = V_214 ;
F_1 ( V_2 ,
& V_212 -> V_12 , 1 , V_213 ,
F_102 ,
F_103 ,
F_107 ,
F_109 ,
F_96 ) ;
} else {
V_212 -> V_198 = F_80 ;
V_212 -> V_73 = F_65 ;
V_212 -> V_74 = F_61 ;
V_212 -> V_176 = F_68 ;
V_212 -> V_199 =
V_215 ;
V_212 -> V_216 = F_60 ;
F_1 ( V_2 ,
& V_212 -> V_12 , V_217 ,
V_213 , F_102 ,
F_103 ,
F_107 ,
F_109 ,
F_96 ) ;
}
}
void F_123 ( struct V_1 * V_2 ,
struct V_39 * V_218 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , void * V_110 ,
T_9 V_200 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_46 )
{
union V_6 * V_213 = (union V_6 * ) V_218 ;
F_120 ( V_218 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_218 -> V_170 = F_44 ;
V_218 -> V_172 = F_49 ;
V_218 -> V_189 = F_43 ;
V_218 -> V_202 = F_48 ;
if ( F_122 ( V_2 ) ) {
F_38 ( L_59 ) ;
F_124 () ;
} else {
V_218 -> V_198 = F_88 ;
V_218 -> V_73 = F_66 ;
V_218 -> V_74 = F_63 ;
V_218 -> V_176 = F_68 ;
V_218 -> V_199 =
V_215 ;
V_218 -> V_216 = F_60 ;
F_1 ( V_2 ,
& V_218 -> V_12 , V_217 ,
V_213 , F_102 ,
F_103 ,
F_107 ,
F_109 ,
F_97 ) ;
}
}
void F_125 ( struct V_1 * V_2 ,
struct V_39 * V_160 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , void * V_110 ,
T_9 V_200 , int V_33 ,
unsigned long * V_34 , T_10 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_213 =
(union V_6 * ) V_160 ;
F_120 ( V_160 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_160 -> V_170 = F_45 ;
V_160 -> V_172 = F_50 ;
V_160 -> V_189 = F_41 ;
V_160 -> V_202 = F_46 ;
if ( F_126 ( V_2 ) ) {
F_38 ( L_60 ) ;
F_124 () ;
} else if ( F_127 ( V_2 ) ) {
V_160 -> V_198 = F_90 ;
V_160 -> V_73 = F_67 ;
V_160 -> V_74 = F_64 ;
V_160 -> V_176 = F_69 ;
V_160 -> V_199 = V_214 ;
F_1 ( V_2 ,
& V_160 -> V_12 , 1 , V_213 ,
F_102 ,
F_103 ,
F_107 ,
F_109 ,
F_98 ) ;
} else {
V_160 -> V_198 = F_89 ;
V_160 -> V_73 = F_67 ;
V_160 -> V_74 = F_64 ;
V_160 -> V_176 = F_68 ;
V_160 -> V_199 =
V_215 ;
F_1 ( V_2 ,
& V_160 -> V_12 ,
V_217 ,
V_213 , F_102 ,
F_103 ,
F_107 ,
F_109 ,
F_98 ) ;
}
}
static inline void F_128 ( struct V_1 * V_2 ,
struct V_219 * V_220 ,
T_8 V_138 )
{
T_11 V_55 = sizeof( struct V_219 ) ;
T_7 V_221 = V_222 +
F_129 ( V_138 ) ;
F_130 ( V_2 , V_221 , V_55 , ( T_7 * ) V_220 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_223 * V_158 )
{
T_7 V_224 = ( 1 << V_158 -> V_96 ) ;
struct V_219 * V_220 =
(struct V_219 * ) V_158 -> V_110 ;
T_6 V_225 = 1 , V_226 = 1 ;
T_6 V_227 = 0 , V_228 = 0 , V_229 = 0 ;
T_6 V_230 = 0 ;
if ( F_18 ( V_231 , & V_158 -> V_232 ) )
V_225 = 0 ;
if ( F_18 ( V_233 , & V_158 -> V_232 ) )
V_226 = 0 ;
if ( F_18 ( V_234 , & V_158 -> V_232 ) ) {
V_225 = 0 ;
V_227 = 1 ;
}
if ( F_18 ( V_235 , & V_158 -> V_232 ) ) {
V_226 = 0 ;
V_229 = 1 ;
}
if ( F_18 ( V_236 , & V_158 -> V_232 ) )
V_228 = 1 ;
if ( F_18 ( V_237 , & V_158 -> V_232 ) )
V_230 = 1 ;
V_220 -> V_238 = V_225 ?
V_220 -> V_238 | V_224 :
V_220 -> V_238 & ~ V_224 ;
V_220 -> V_239 = V_226 ?
V_220 -> V_239 | V_224 :
V_220 -> V_239 & ~ V_224 ;
V_220 -> V_240 = V_227 ?
V_220 -> V_240 | V_224 :
V_220 -> V_240 & ~ V_224 ;
V_220 -> V_241 = V_229 ?
V_220 -> V_241 | V_224 :
V_220 -> V_241 & ~ V_224 ;
V_220 -> V_242 = V_228 ?
V_220 -> V_242 | V_224 :
V_220 -> V_242 & ~ V_224 ;
V_220 -> V_230 = V_230 ?
V_220 -> V_230 | V_224 :
V_220 -> V_230 & ~ V_224 ;
F_4 ( V_17 , L_61
L_62 ,
V_220 -> V_238 , V_220 -> V_239 ,
V_220 -> V_240 , V_220 -> V_241 ,
V_220 -> V_242 ) ;
F_128 ( V_2 , V_220 , V_158 -> V_97 ) ;
F_29 ( V_158 -> V_33 , V_158 -> V_34 ) ;
F_30 () ;
return 0 ;
}
static inline void F_132 ( T_7 V_101 ,
struct V_102 * V_94 ,
T_6 V_103 )
{
V_94 -> V_104 = F_79 ( V_101 ) ;
V_94 -> V_103 = V_103 ;
}
static inline void F_133 ( struct V_1 * V_2 ,
unsigned long * V_243 ,
struct V_244 * V_111 ,
bool V_245 )
{
T_8 V_33 ;
V_33 = V_246 |
V_247 ;
if ( F_18 ( V_231 , V_243 ) )
V_33 &= ~ V_246 ;
if ( F_18 ( V_233 , V_243 ) )
V_33 &= ~ V_247 ;
if ( F_18 ( V_234 , V_243 ) ) {
V_33 &= ~ V_246 ;
V_33 |= V_248 ;
}
if ( F_18 ( V_235 , V_243 ) ) {
V_33 |= V_249 ;
V_33 &= ~ V_247 ;
}
if ( F_18 ( V_236 , V_243 ) )
V_33 |= V_250 ;
if ( F_18 ( V_237 , V_243 ) ) {
V_33 &= ~ V_246 ;
V_33 |= V_251 ;
}
if ( F_18 ( V_252 , V_243 ) )
V_33 |= V_253 ;
if ( V_245 ) {
V_33 &= ~ V_249 ;
V_33 &= ~ V_250 ;
V_33 &= ~ V_248 ;
V_33 &= ~ V_251 ;
}
V_111 -> V_33 = F_82 ( V_33 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_223 * V_158 )
{
struct V_254 * V_64 = V_158 -> V_110 ;
int V_22 ;
T_6 V_107 = 0 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
if ( F_18 ( V_255 , & V_158 -> V_25 ) ) {
V_64 -> V_115 [ V_107 ] . V_95 = V_158 -> V_96 ;
V_64 -> V_115 [ V_107 ] . V_97 = V_158 -> V_97 ;
V_64 -> V_115 [ V_107 ] . V_98 =
V_256 ;
F_133 ( V_2 , & V_158 -> V_257 ,
& ( V_64 -> V_115 [ V_107 ++ ] ) ,
false ) ;
}
if ( F_18 ( V_258 , & V_158 -> V_25 ) ) {
V_64 -> V_115 [ V_107 ] . V_95 = V_158 -> V_96 ;
V_64 -> V_115 [ V_107 ] . V_97 = V_158 -> V_97 ;
V_64 -> V_115 [ V_107 ] . V_98 =
V_259 ;
F_133 ( V_2 , & V_158 -> V_232 ,
& ( V_64 -> V_115 [ V_107 ++ ] ) ,
false ) ;
}
if ( F_18 ( V_260 , & V_158 -> V_261 ) ) {
if ( F_18 ( V_255 , & V_158 -> V_25 ) ) {
V_64 -> V_115 [ V_107 ] . V_95 = F_135 ( V_2 , V_96 ) ;
V_64 -> V_115 [ V_107 ] . V_97 = V_158 -> V_97 ;
V_64 -> V_115 [ V_107 ] . V_98 =
V_256 ;
F_133 ( V_2 , & V_158 -> V_257 ,
& ( V_64 -> V_115 [ V_107 ] ) ,
true ) ;
V_107 ++ ;
}
if ( F_18 ( V_258 , & V_158 -> V_25 ) ) {
V_64 -> V_115 [ V_107 ] . V_95 = F_135 ( V_2 , V_96 ) ;
V_64 -> V_115 [ V_107 ] . V_97 = V_158 -> V_97 ;
V_64 -> V_115 [ V_107 ] . V_98 =
V_259 ;
F_133 ( V_2 , & V_158 -> V_232 ,
& ( V_64 -> V_115 [ V_107 ] ) ,
true ) ;
V_107 ++ ;
}
}
F_132 ( V_158 -> V_101 , & V_64 -> V_124 , V_107 ) ;
F_4 ( V_17 , L_63 ,
V_64 -> V_124 . V_103 , V_158 -> V_232 ,
V_158 -> V_257 ) ;
V_22 = F_111 ( V_2 , V_262 , V_158 -> V_101 ,
F_112 ( V_158 -> V_200 ) ,
F_113 ( V_158 -> V_200 ) ,
V_201 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_223 * V_158 )
{
return F_33 ( V_2 , V_158 -> V_33 , V_158 -> V_34 ) ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_223 * V_158 )
{
return 0 ;
}
int F_138 ( struct V_1 * V_2 ,
struct V_223 * V_158 )
{
int V_22 ;
V_22 = V_158 -> V_263 -> V_264 ( V_2 , V_158 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_18 ( V_205 , & V_158 -> V_25 ) ) {
V_22 = V_158 -> V_263 -> V_179 ( V_2 , V_158 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_139 ( struct V_1 * V_2 ,
struct V_265 * V_4 )
{
if ( F_122 ( V_2 ) ) {
V_4 -> V_179 = F_137 ;
V_4 -> V_264 = F_131 ;
} else {
V_4 -> V_179 = F_136 ;
V_4 -> V_264 = F_134 ;
}
}
static inline T_6 F_140 ( T_6 * V_65 )
{
return ( F_141 ( 0 , V_65 , V_62 ) >> 24 ) & 0xff ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_266 * V_4 )
{
if ( F_33 ( V_2 , V_4 -> V_267 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_179 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
int V_270 ;
struct V_271 * V_272 ;
struct V_273 * V_274 = NULL ;
struct V_275 * V_57 ;
int V_276 = ( ( V_111 == V_277 ) ?
V_158 -> V_278 : 0 ) ;
if ( ! V_158 -> V_278 )
return 0 ;
V_270 = sizeof( * V_272 ) +
V_276 * sizeof( struct V_273 ) ;
V_272 = F_25 ( V_270 , V_31 ) ;
if ( ! V_272 )
return - V_188 ;
F_4 ( V_17 , L_64 ,
V_111 , V_276 ) ;
F_2 ( & V_272 -> V_64 . V_279 ) ;
V_272 -> type = V_111 ;
V_272 -> V_280 = false ;
switch ( V_111 ) {
case V_277 :
V_274 = (struct V_273 * )
( ( T_6 * ) V_272 + sizeof( * V_272 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_274 -> V_65 , V_57 -> V_65 , V_62 ) ;
F_12 ( & V_274 -> V_24 , & V_272 -> V_64 . V_279 ) ;
V_274 ++ ;
}
break;
case V_281 :
V_272 -> V_64 . V_282 = V_158 -> V_278 ;
break;
case V_283 :
V_272 -> V_64 . V_284 = 0 ;
break;
default:
F_6 ( V_272 ) ;
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
F_12 ( & V_272 -> V_24 , & V_4 -> V_285 ) ;
V_4 -> V_286 ( V_4 ) ;
return 1 ;
}
static inline int F_144 ( struct V_266 * V_4 , int V_287 )
{
int V_288 , V_289 , V_290 = V_287 % V_291 ;
for ( V_288 = V_287 / V_291 ; V_288 < V_292 ; V_288 ++ ) {
if ( V_4 -> V_293 . V_294 . V_295 [ V_288 ] )
for ( V_289 = V_290 ; V_289 < V_291 ; V_289 ++ ) {
int V_296 = V_289 + V_291 * V_288 ;
if ( F_145 ( V_4 -> V_293 . V_294 .
V_295 , V_296 ) ) {
return V_296 ;
}
}
V_290 = 0 ;
}
return - 1 ;
}
static inline int F_146 ( struct V_266 * V_4 )
{
int V_296 = F_144 ( V_4 , 0 ) ;
if ( V_296 >= 0 )
F_147 ( V_4 -> V_293 . V_294 . V_295 , V_296 ) ;
return V_296 ;
}
static inline T_6 F_148 ( struct V_266 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_75 = 0 ;
if ( ( V_38 -> V_76 == V_77 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_297 ;
if ( ( V_38 -> V_76 == V_80 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_298 ;
return V_75 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_266 * V_4 , int V_193 ,
union V_299 * V_300 ,
enum V_269 V_111 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_301 * V_64 =
(struct V_301 * ) ( V_131 -> V_110 ) ;
T_6 V_97 = V_131 -> V_97 ;
T_6 V_302 = F_148 ( V_4 ) ;
int V_303 ;
if ( ( V_111 == V_277 ) || ( V_111 == V_283 ) )
V_302 |= V_304 ;
V_64 -> V_115 [ V_193 ] . V_98 |= V_302 ;
switch ( V_111 ) {
case V_277 :
V_303 = F_140 ( V_300 -> V_65 ) ;
F_150 ( V_4 -> V_293 . V_294 . V_295 , V_303 ) ;
break;
case V_281 :
V_303 = F_146 ( V_4 ) ;
break;
case V_283 :
V_303 = V_300 -> V_303 ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return;
}
F_4 ( V_17 , L_66 ,
( ( V_302 & V_304 ) ?
L_67 : L_68 ) , V_303 ) ;
V_64 -> V_115 [ V_193 ] . V_305 = ( T_6 ) V_303 ;
V_64 -> V_115 [ V_193 ] . V_97 = V_97 ;
V_64 -> V_115 [ V_193 ] . V_306 = V_4 -> V_306 ;
}
static inline int F_151 (
struct V_1 * V_2 , struct V_266 * V_4 , int V_307 ,
int * V_308 )
{
int V_309 , V_20 = * V_308 ;
union V_299 V_300 = { NULL } ;
for ( V_309 = F_144 ( V_4 , V_307 ) ; V_309 >= 0 ;
V_309 = F_144 ( V_4 , V_309 + 1 ) ) {
V_300 . V_303 = ( T_6 ) V_309 ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_300 ,
V_283 ) ;
V_20 ++ ;
F_4 ( V_17 , L_69 , V_309 ) ;
if ( V_20 >= V_4 -> V_310 )
break;
}
* V_308 = V_20 ;
return V_309 ;
}
static inline void F_152 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_271 * V_311 ,
int * V_312 )
{
struct V_273 * V_313 , * V_314 ;
int V_20 = * V_312 ;
union V_299 V_300 = { NULL } ;
F_116 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_300 . V_65 = & V_313 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_300 , V_311 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_313 -> V_65 ) ;
F_16 ( & V_313 -> V_24 ) ;
if ( V_20 >= V_4 -> V_310 )
break;
}
* V_312 = V_20 ;
if ( F_14 ( & V_311 -> V_64 . V_279 ) )
V_311 -> V_280 = true ;
}
static inline void F_153 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_271 * V_311 ,
int * V_312 )
{
int V_20 = * V_312 ;
while ( V_311 -> V_64 . V_282 ) {
V_4 -> V_198 ( V_2 , V_4 , V_20 , NULL , V_311 -> type ) ;
V_20 ++ ;
V_311 -> V_64 . V_282 -- ;
F_4 ( V_17 , L_71 ,
V_311 -> V_64 . V_282 , V_20 ) ;
if ( V_20 >= V_4 -> V_310 )
break;
}
* V_312 = V_20 ;
if ( ! V_311 -> V_64 . V_282 )
V_311 -> V_280 = true ;
}
static inline void F_154 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_271 * V_311 ,
int * V_312 )
{
V_311 -> V_64 . V_284 = V_4 -> V_315 ( V_2 , V_4 , V_311 -> V_64 . V_284 ,
V_312 ) ;
if ( V_311 -> V_64 . V_284 < 0 )
V_311 -> V_280 = true ;
else
V_311 -> V_64 . V_284 ++ ;
}
static inline int F_155 ( struct V_1 * V_2 ,
struct V_268 * V_158 )
{
struct V_271 * V_311 , * V_316 ;
int V_20 = 0 ;
struct V_266 * V_4 = V_158 -> V_317 ;
F_116 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_311 -> type ) {
case V_277 :
F_152 ( V_2 , V_4 , V_311 , & V_20 ) ;
break;
case V_281 :
F_153 ( V_2 , V_4 , V_311 , & V_20 ) ;
break;
case V_283 :
F_154 ( V_2 , V_4 , V_311 ,
& V_20 ) ;
break;
default:
F_38 ( L_65 , V_311 -> type ) ;
return - V_66 ;
}
if ( V_311 -> V_280 ) {
F_16 ( & V_311 -> V_24 ) ;
F_6 ( V_311 ) ;
}
if ( V_20 >= V_4 -> V_310 )
break;
}
return V_20 ;
}
static inline void F_156 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_268 * V_158 ,
int * V_312 )
{
struct V_275 * V_318 ;
union V_299 V_300 = { NULL } ;
int V_20 = * V_312 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_300 . V_65 = V_318 -> V_65 ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_300 , V_277 ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_318 -> V_65 ) ;
}
* V_312 = V_20 ;
}
static inline void F_157 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_268 * V_158 ,
int * V_312 )
{
int V_20 = * V_312 , V_288 ;
for ( V_288 = 0 ; V_288 < V_158 -> V_278 ; V_288 ++ ) {
V_4 -> V_198 ( V_2 , V_4 , V_20 , NULL , V_281 ) ;
V_20 ++ ;
F_4 ( V_17 , L_72 ,
V_158 -> V_278 - V_288 - 1 ) ;
}
* V_312 = V_20 ;
}
static inline int F_158 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 ,
int V_319 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
int V_20 = V_319 ;
F_4 ( V_17 , L_73 , V_158 -> V_278 ) ;
switch ( V_111 ) {
case V_277 :
F_156 ( V_2 , V_4 , V_158 , & V_20 ) ;
break;
case V_281 :
F_157 ( V_2 , V_4 , V_158 , & V_20 ) ;
break;
case V_283 :
V_4 -> V_315 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
V_158 -> V_278 = 0 ;
return V_20 ;
}
static int F_159 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
int V_320 = V_4 -> V_321 ( V_4 ) ;
switch ( V_111 ) {
case V_281 :
V_4 -> V_322 ( V_4 , 0 ) ;
case V_283 :
V_158 -> V_278 = V_320 ;
break;
case V_277 :
case V_323 :
V_4 -> V_322 ( V_4 , V_320 + V_158 -> V_278 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
V_4 -> V_324 += V_158 -> V_278 ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
int V_325 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
V_4 -> V_322 ( V_4 , V_325 ) ;
V_4 -> V_324 -= V_158 -> V_278 ;
}
static inline void F_161 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
T_6 V_326 )
{
struct V_32 * V_131 = & V_158 -> V_317 -> V_38 ;
struct V_301 * V_64 =
(struct V_301 * ) ( V_131 -> V_110 ) ;
V_64 -> V_124 . V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_327 <<
V_106 ) ) ;
V_64 -> V_124 . V_103 = V_326 ;
}
static inline int F_162 ( struct V_1 * V_2 ,
struct V_266 * V_4 )
{
int V_288 , V_20 = 0 ;
T_12 V_19 ;
for ( V_288 = 0 ; V_288 < V_292 ; V_288 ++ ) {
V_19 = V_4 -> V_293 . V_294 . V_295 [ V_288 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_322 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
struct V_32 * V_38 = & V_158 -> V_317 -> V_38 ;
struct V_266 * V_4 = V_158 -> V_317 ;
struct V_301 * V_64 =
(struct V_301 * ) ( V_38 -> V_110 ) ;
int V_20 = 0 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_20 = F_155 ( V_2 , V_158 ) ;
if ( F_14 ( & V_4 -> V_285 ) )
V_4 -> V_328 ( V_4 ) ;
if ( V_158 -> V_278 > 0 )
V_20 = F_158 ( V_2 , V_158 , V_111 , V_20 ) ;
V_4 -> V_324 -= V_20 ;
F_19 ( V_4 -> V_324 < 0 ) ;
F_19 ( V_20 > V_4 -> V_310 ) ;
F_161 ( V_2 , V_158 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_324 )
F_162 ( V_2 , V_4 ) ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) ) {
V_38 -> V_182 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_111 ( V_2 , V_329 ,
V_38 -> V_101 , F_112 ( V_38 -> V_200 ) ,
F_113 ( V_38 -> V_200 ) ,
V_201 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_164 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
if ( ( V_111 == V_281 ) || ( V_111 == V_283 ) )
V_158 -> V_278 = 1 ;
return 0 ;
}
static void F_165 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
int V_325 )
{
}
static inline void F_166 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_268 * V_158 ,
T_7 * V_330 )
{
struct V_275 * V_318 ;
int V_331 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_331 = F_140 ( V_318 -> V_65 ) ;
F_167 ( V_330 , V_331 ) ;
F_4 ( V_17 , L_74 ,
V_318 -> V_65 , V_331 ) ;
F_150 ( V_4 -> V_293 . V_294 . V_295 ,
V_331 ) ;
}
}
static inline void F_168 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_268 * V_158 ,
T_7 * V_330 )
{
int V_331 ;
for ( V_331 = F_144 ( V_4 , 0 ) ;
V_331 >= 0 ;
V_331 = F_144 ( V_4 , V_331 + 1 ) ) {
F_167 ( V_330 , V_331 ) ;
F_4 ( V_17 , L_75 , V_331 ) ;
}
}
static int F_169 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
int V_288 ;
struct V_266 * V_4 = V_158 -> V_317 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( ! F_18 ( V_28 , & V_158 -> V_25 ) ) {
T_7 V_330 [ V_332 ] = { 0 } ;
switch ( V_111 ) {
case V_277 :
F_166 ( V_2 , V_4 , V_158 , V_330 ) ;
break;
case V_281 :
F_4 ( V_17 ,
L_76 ) ;
memset ( V_4 -> V_293 . V_294 . V_295 , 0 ,
sizeof( V_4 -> V_293 . V_294 . V_295 ) ) ;
break;
case V_283 :
F_168 ( V_2 , V_4 , V_158 , V_330 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
for ( V_288 = 0 ; V_288 < V_332 ; V_288 ++ )
F_76 ( V_2 , F_170 ( V_2 , V_288 ) , V_330 [ V_288 ] ) ;
} else
memset ( V_4 -> V_293 . V_294 . V_295 , 0 ,
sizeof( V_4 -> V_293 . V_294 . V_295 ) ) ;
V_131 -> V_182 ( V_131 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
int V_320 = V_4 -> V_321 ( V_4 ) ;
switch ( V_111 ) {
case V_281 :
V_4 -> V_322 ( V_4 , 0 ) ;
case V_283 :
V_158 -> V_278 = V_320 ;
F_4 ( V_17 , L_77 ,
V_111 , V_158 -> V_278 ) ;
break;
case V_277 :
case V_323 :
if ( V_158 -> V_278 > V_4 -> V_310 ) {
F_38 ( L_78 ,
V_4 -> V_310 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_73 , V_158 -> V_278 ) ;
if ( V_158 -> V_278 > 0 )
V_4 -> V_322 ( V_4 , V_158 -> V_278 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
if ( V_158 -> V_278 )
V_4 -> V_324 += V_4 -> V_310 ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
int V_333 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
V_4 -> V_322 ( V_4 , V_333 ) ;
if ( V_158 -> V_278 )
V_4 -> V_324 -= V_4 -> V_310 ;
}
static void F_173 ( struct V_1 * V_2 ,
struct V_266 * V_4 , int V_193 ,
union V_299 * V_300 ,
enum V_269 V_111 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_110 ) ;
if ( ( V_111 == V_277 ) || ( V_111 == V_283 ) ) {
F_81 ( & V_64 -> V_149 [ V_193 ] . V_143 ,
& V_64 -> V_149 [ V_193 ] . V_144 ,
& V_64 -> V_149 [ V_193 ] . V_145 ,
V_300 -> V_65 ) ;
V_64 -> V_149 [ V_193 ] . V_133 = 0 ;
V_64 -> V_149 [ V_193 ] . V_138 = V_131 -> V_97 ;
V_64 -> V_149 [ V_193 ] . V_137 =
F_79 ( 1 << V_131 -> V_96 ) ;
F_85 ( V_64 -> V_149 [ V_193 ] . V_139 ,
V_140 ,
V_141 ) ;
}
}
static inline void F_174 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
T_6 V_326 )
{
struct V_32 * V_131 = & V_158 -> V_317 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_110 ) ;
T_6 V_40 = ( F_175 ( V_2 ) ?
V_334 * ( 1 + V_131 -> V_97 ) :
V_335 * ( 1 + V_131 -> V_97 ) ) ;
V_64 -> V_94 . V_40 = V_40 ;
V_64 -> V_94 . V_95 = F_82 ( 0xff ) ;
V_64 -> V_94 . V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_327 <<
V_106 ) ) ;
V_64 -> V_94 . V_132 = V_326 ;
}
static inline int F_176 (
struct V_1 * V_2 , struct V_266 * V_4 , int V_336 ,
int * V_308 )
{
struct V_273 * V_19 ;
int V_288 = 0 ;
union V_299 V_300 = { NULL } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_300 . V_65 = & V_19 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_288 , & V_300 , V_283 ) ;
V_288 ++ ;
F_4 ( V_17 , L_70 ,
V_300 . V_65 ) ;
}
* V_308 = V_288 ;
return - 1 ;
}
static inline int F_177 (
struct V_1 * V_2 , struct V_268 * V_158 )
{
struct V_271 * V_311 ;
struct V_273 * V_313 ;
struct V_266 * V_4 = V_158 -> V_317 ;
union V_299 V_300 = { NULL } ;
int V_20 = 0 ;
if ( F_14 ( & V_4 -> V_285 ) )
return 0 ;
V_311 = F_15 ( & V_4 -> V_285 ,
struct V_271 , V_24 ) ;
switch ( V_311 -> type ) {
case V_277 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_300 . V_65 = & V_313 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_300 , V_311 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_313 -> V_65 ) ;
}
break;
case V_281 :
V_20 = V_311 -> V_64 . V_282 ;
F_4 ( V_17 , L_79 , V_20 ) ;
break;
case V_283 :
V_4 -> V_315 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_65 , V_311 -> type ) ;
return - V_66 ;
}
F_16 ( & V_311 -> V_24 ) ;
F_6 ( V_311 ) ;
return V_20 ;
}
static inline void F_178 ( T_13 * V_337 , T_13 * V_338 ,
T_13 * V_339 , T_6 * V_65 )
{
V_65 [ 1 ] = ( ( T_6 * ) V_337 ) [ 0 ] ;
V_65 [ 0 ] = ( ( T_6 * ) V_337 ) [ 1 ] ;
V_65 [ 3 ] = ( ( T_6 * ) V_338 ) [ 0 ] ;
V_65 [ 2 ] = ( ( T_6 * ) V_338 ) [ 1 ] ;
V_65 [ 5 ] = ( ( T_6 * ) V_339 ) [ 0 ] ;
V_65 [ 4 ] = ( ( T_6 * ) V_339 ) [ 1 ] ;
}
static inline int F_179 ( struct V_1 * V_2 ,
struct V_266 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_273 * V_19 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
if ( F_180 ( V_64 -> V_149 [ 0 ] . V_139 ,
V_140 ) ) {
int V_288 , V_326 = V_64 -> V_94 . V_132 ;
if ( ! F_14 ( & V_4 -> V_293 . V_340 . V_341 ) )
return 0 ;
V_19 = F_181 ( V_326 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_38 ( L_80 ) ;
return - V_188 ;
}
for ( V_288 = 0 ; V_288 < V_326 ; V_288 ++ , V_19 ++ ) {
F_178 (
& V_64 -> V_149 [ V_288 ] . V_143 ,
& V_64 -> V_149 [ V_288 ] . V_144 ,
& V_64 -> V_149 [ V_288 ] . V_145 ,
V_19 -> V_65 ) ;
F_4 ( V_17 , L_81 ,
V_19 -> V_65 ) ;
F_12 ( & V_19 -> V_24 ,
& V_4 -> V_293 . V_340 . V_341 ) ;
}
} else {
V_19 = F_15 ( & V_4 -> V_293 . V_340 . V_341 ,
struct V_273 , V_24 ) ;
F_4 ( V_17 , L_82 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_293 . V_340 . V_341 ) ;
}
return 0 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
int V_20 = 0 , V_288 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
for ( V_288 = 0 ; V_288 < V_4 -> V_310 ; V_288 ++ )
F_85 ( V_64 -> V_149 [ V_288 ] . V_139 ,
V_140 ,
V_146 ) ;
V_20 = F_177 ( V_2 , V_158 ) ;
if ( F_14 ( & V_4 -> V_285 ) )
V_4 -> V_328 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_158 ( V_2 , V_158 , V_111 , 0 ) ;
V_4 -> V_324 -= V_4 -> V_310 ;
F_19 ( V_20 > V_4 -> V_310 ) ;
F_174 ( V_2 , V_158 , ( T_6 ) V_20 ) ;
V_22 = F_179 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) ) {
V_38 -> V_182 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_111 ( V_2 , V_214 , V_38 -> V_101 ,
F_112 ( V_38 -> V_200 ) ,
F_113 ( V_38 -> V_200 ) ,
V_201 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_183 ( struct V_266 * V_4 )
{
return V_4 -> V_293 . V_340 . V_342 ;
}
static int F_184 ( struct V_266 * V_4 )
{
return V_4 -> V_293 . V_294 . V_343 ;
}
static void F_185 ( struct V_266 * V_4 ,
int V_52 )
{
V_4 -> V_293 . V_340 . V_342 = V_52 ;
}
static void F_186 ( struct V_266 * V_4 ,
int V_52 )
{
V_4 -> V_293 . V_294 . V_343 = V_52 ;
}
int F_187 ( struct V_1 * V_2 ,
struct V_268 * V_158 ,
enum V_269 V_111 )
{
struct V_266 * V_4 = V_158 -> V_317 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 = 0 , V_344 ;
V_344 = V_4 -> V_321 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_158 , V_111 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_158 -> V_278 ) && ( ! V_4 -> V_345 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_83 ,
V_4 -> V_324 , V_158 -> V_278 , V_4 -> V_310 ) ;
if ( V_131 -> V_195 ( V_131 ) ||
( ( V_4 -> V_310 > 0 ) && ( V_4 -> V_324 > V_4 -> V_310 ) ) ) {
V_22 = V_4 -> V_346 ( V_2 , V_158 -> V_317 , V_158 , V_111 ) ;
if ( V_22 < 0 )
goto V_347;
V_158 -> V_278 = 0 ;
}
if ( ! V_131 -> V_195 ( V_131 ) ) {
V_131 -> V_196 ( V_131 ) ;
V_22 = V_4 -> V_348 ( V_2 , V_158 , V_111 ) ;
if ( V_22 < 0 )
goto V_349;
if ( F_18 ( V_205 , & V_158 -> V_25 ) )
V_22 = V_4 -> V_179 ( V_2 , V_4 ) ;
}
return V_22 ;
V_349:
V_131 -> V_182 ( V_131 ) ;
V_347:
V_4 -> V_350 ( V_2 , V_158 , V_344 ) ;
return V_22 ;
}
static void F_188 ( struct V_266 * V_4 )
{
F_28 () ;
F_29 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static void F_189 ( struct V_266 * V_4 )
{
F_28 () ;
F_32 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static bool F_190 ( struct V_266 * V_4 )
{
return ! ! F_18 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
}
static bool F_191 ( struct V_266 * V_4 )
{
return V_4 -> V_38 . V_195 ( & V_4 -> V_38 ) || V_4 -> V_345 ( V_4 ) ;
}
void F_192 ( struct V_1 * V_2 ,
struct V_266 * V_317 ,
T_6 V_351 , T_7 V_352 , T_6 V_97 ,
T_6 V_306 , void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 , T_10 type )
{
memset ( V_317 , 0 , sizeof( * V_317 ) ) ;
F_119 ( & V_317 -> V_38 , V_351 , V_352 , V_97 ,
V_110 , V_200 , V_33 , V_34 , type ) ;
V_317 -> V_306 = V_306 ;
F_2 ( & V_317 -> V_285 ) ;
V_317 -> V_267 = V_353 ;
V_317 -> V_345 = F_190 ;
V_317 -> V_286 = F_189 ;
V_317 -> V_328 = F_188 ;
if ( F_126 ( V_2 ) ) {
V_317 -> V_348 = F_182 ;
V_317 -> V_346 = F_143 ;
V_317 -> V_315 =
F_176 ;
V_317 -> V_195 = F_191 ;
if ( F_175 ( V_2 ) )
V_317 -> V_310 = V_334 ;
else
V_317 -> V_310 = V_335 ;
V_317 -> V_179 = F_142 ;
V_317 -> V_198 = F_173 ;
V_317 -> V_8 = F_171 ;
V_317 -> V_350 = F_172 ;
V_317 -> V_321 =
F_183 ;
V_317 -> V_322 =
F_185 ;
F_2 ( & V_317 -> V_293 . V_340 . V_341 ) ;
} else if ( F_127 ( V_2 ) ) {
V_317 -> V_348 = F_169 ;
V_317 -> V_346 = NULL ;
V_317 -> V_315 = NULL ;
V_317 -> V_195 = F_191 ;
V_317 -> V_310 = - 1 ;
V_317 -> V_179 = F_142 ;
V_317 -> V_198 = NULL ;
V_317 -> V_8 = F_164 ;
V_317 -> V_350 = F_165 ;
V_317 -> V_321 =
F_184 ;
V_317 -> V_322 =
F_186 ;
} else {
V_317 -> V_348 = F_163 ;
V_317 -> V_346 = F_143 ;
V_317 -> V_315 =
F_151 ;
V_317 -> V_195 = F_191 ;
V_317 -> V_310 = 16 ;
V_317 -> V_179 = F_142 ;
V_317 -> V_198 = F_149 ;
V_317 -> V_8 = F_159 ;
V_317 -> V_350 = F_160 ;
V_317 -> V_321 =
F_184 ;
V_317 -> V_322 =
F_186 ;
}
}
static inline bool F_193 ( T_14 * V_354 , int V_355 , int V_61 )
{
int V_356 , V_357 ;
V_356 = F_194 ( V_354 ) ;
for (; ; ) {
if ( F_195 ( V_356 + V_355 >= V_61 ) )
return false ;
V_357 = F_196 ( ( V_354 ) , V_356 , V_356 + V_355 ) ;
if ( F_197 ( V_357 == V_356 ) )
break;
V_356 = V_357 ;
}
return true ;
}
static inline bool F_198 ( T_14 * V_354 , int V_355 , int V_61 )
{
int V_356 , V_357 ;
V_356 = F_194 ( V_354 ) ;
for (; ; ) {
if ( F_195 ( V_356 - V_355 < V_61 ) )
return false ;
V_357 = F_196 ( ( V_354 ) , V_356 , V_356 - V_355 ) ;
if ( F_197 ( V_357 == V_356 ) )
break;
V_356 = V_357 ;
}
return true ;
}
static bool F_199 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_200 () ;
V_22 = F_198 ( & V_4 -> V_358 , V_20 , 0 ) ;
F_200 () ;
return V_22 ;
}
static bool F_201 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_200 () ;
V_22 = F_193 ( & V_4 -> V_358 , V_20 , V_4 -> V_359 + 1 ) ;
F_200 () ;
return V_22 ;
}
static int F_202 ( struct V_41 * V_4 )
{
int V_360 ;
F_200 () ;
V_360 = F_194 ( & V_4 -> V_358 ) ;
return V_360 ;
}
static bool F_203 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_204 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_193 , V_295 , V_288 ;
* V_40 = - 1 ;
for ( V_295 = 0 ; V_295 < V_361 ; V_295 ++ ) {
if ( ! V_4 -> V_362 [ V_295 ] )
continue;
for ( V_193 = V_295 * V_291 , V_288 = 0 ;
V_288 < V_291 ; V_193 ++ , V_288 ++ )
if ( F_145 ( V_4 -> V_362 , V_193 ) ) {
F_147 ( V_4 -> V_362 , V_193 ) ;
* V_40 = V_4 -> V_363 + V_193 ;
return true ;
}
}
return false ;
}
static bool F_205 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_363 )
return false ;
V_40 -= V_4 -> V_363 ;
if ( V_40 >= V_4 -> V_359 )
return false ;
F_150 ( V_4 -> V_362 , V_40 ) ;
return true ;
}
static bool F_206 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_207 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_208 ( struct V_41 * V_158 ,
int V_53 , int V_358 )
{
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
memset ( & V_158 -> V_362 , 0xff , sizeof( V_158 -> V_362 ) ) ;
F_209 ( & V_158 -> V_358 , V_358 ) ;
V_158 -> V_359 = V_358 ;
V_158 -> V_363 = V_53 ;
F_200 () ;
V_158 -> V_364 = F_202 ;
if ( V_358 >= 0 ) {
V_158 -> V_47 = F_201 ;
V_158 -> V_11 = F_199 ;
V_158 -> V_48 = F_205 ;
V_158 -> V_44 = F_204 ;
} else {
V_158 -> V_47 = F_203 ;
V_158 -> V_11 = F_203 ;
V_158 -> V_48 = F_206 ;
V_158 -> V_44 = F_207 ;
}
if ( V_53 < 0 ) {
V_158 -> V_48 = F_206 ;
V_158 -> V_44 = F_207 ;
}
}
void F_210 ( struct V_1 * V_2 ,
struct V_41 * V_158 , T_6 V_97 ,
T_6 V_365 )
{
#define F_211 5
int V_366 ;
if ( F_126 ( V_2 ) ) {
if ( ! F_175 ( V_2 ) )
V_366 = ( V_367 / 2 ) - V_335 ;
else
V_366 = F_211 - V_334 ;
F_208 ( V_158 , V_97 * V_366 , V_366 ) ;
} else if ( F_127 ( V_2 ) ) {
if ( ( V_365 > 0 ) ) {
if ( ! F_175 ( V_2 ) )
V_366 = ( V_368 / ( 2 * V_365 ) ) ;
else
V_366 = F_211 ;
F_208 ( V_158 , V_97 * V_366 , V_366 ) ;
} else {
F_208 ( V_158 , 0 , 0 ) ;
}
} else {
if ( ( V_365 > 0 ) ) {
if ( ! F_175 ( V_2 ) )
V_366 = ( V_369 / V_365 ) ;
else
V_366 = F_211 ;
F_208 ( V_158 , - 1 , V_366 ) ;
} else {
F_208 ( V_158 , 0 , 0 ) ;
}
}
}
void F_212 ( struct V_1 * V_2 ,
struct V_41 * V_158 ,
T_6 V_97 ,
T_6 V_365 )
{
if ( F_122 ( V_2 ) ) {
F_208 ( V_158 , 0 , - 1 ) ;
} else {
if ( V_365 > 0 ) {
int V_358 = V_370 / V_365 ;
F_208 ( V_158 , V_97 * V_358 , V_358 ) ;
} else
F_208 ( V_158 , 0 , 0 ) ;
}
}
static inline void F_213 ( struct V_1 * V_2 ,
struct V_371 * V_158 )
{
int V_288 ;
F_4 ( V_17 , L_84 ) ;
F_4 ( V_17 , L_85 ) ;
for ( V_288 = 0 ; V_288 < V_372 ; V_288 ++ ) {
F_214 ( V_17 , L_86 , V_158 -> V_373 [ V_288 ] ) ;
if ( ( V_288 + 1 < V_372 ) &&
( ( ( V_288 + 1 ) & 0x3 ) == 0 ) ) {
F_214 ( V_17 , L_87 ) ;
F_4 ( V_17 , L_88 , V_288 + 1 ) ;
}
}
F_214 ( V_17 , L_87 ) ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_371 * V_158 )
{
struct V_374 * V_4 = V_158 -> V_375 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_376 * V_64 =
(struct V_376 * ) ( V_131 -> V_110 ) ;
T_6 V_377 = 0 ;
int V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_4 ( V_17 , L_89 ) ;
V_64 -> V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_131 -> V_33 << V_106 ) ) ;
if ( F_18 ( V_378 , & V_158 -> V_379 ) )
V_377 = V_380 ;
else if ( F_18 ( V_381 , & V_158 -> V_379 ) )
V_377 = V_382 ;
V_64 -> V_377 = V_377 ;
F_4 ( V_17 , L_90 , V_377 ) ;
if ( F_18 ( V_383 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_385 ;
if ( F_18 ( V_386 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_387 ;
if ( F_18 ( V_388 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_389 ;
if ( F_18 ( V_390 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_391 ;
if ( F_18 ( V_392 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_393 ;
if ( F_18 ( V_394 , & V_158 -> V_379 ) )
V_64 -> V_384 |=
V_395 ;
V_64 -> V_396 = V_158 -> V_396 ;
V_64 -> V_397 = V_4 -> V_306 ;
F_4 ( V_17 , L_91 , V_64 -> V_397 ) ;
memcpy ( V_64 -> V_398 , V_158 -> V_373 ,
V_372 ) ;
memcpy ( V_4 -> V_373 , V_158 -> V_373 , V_372 ) ;
if ( F_216 ( V_2 ) )
F_213 ( V_2 , V_158 ) ;
if ( F_18 ( V_399 , & V_158 -> V_379 ) ) {
memcpy ( & V_64 -> V_400 [ 0 ] , & V_158 -> V_400 [ 0 ] ,
sizeof( V_64 -> V_400 ) ) ;
V_64 -> V_384 |= V_401 ;
}
V_22 = F_111 ( V_2 , V_402 , V_131 -> V_101 ,
F_112 ( V_131 -> V_200 ) ,
F_113 ( V_131 -> V_200 ) ,
V_201 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_217 ( struct V_374 * V_375 ,
T_6 * V_373 )
{
memcpy ( V_373 , V_375 -> V_373 , sizeof( V_375 -> V_373 ) ) ;
}
int F_218 ( struct V_1 * V_2 ,
struct V_371 * V_158 )
{
int V_22 ;
struct V_374 * V_4 = V_158 -> V_375 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) ) {
F_4 ( V_17 , L_92 ,
V_158 -> V_25 ) ;
return 0 ;
}
V_131 -> V_196 ( V_131 ) ;
V_22 = V_4 -> V_403 ( V_2 , V_158 ) ;
if ( V_22 < 0 ) {
V_131 -> V_182 ( V_131 ) ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_158 -> V_25 ) )
V_22 = V_131 -> V_179 ( V_2 , V_131 ) ;
return V_22 ;
}
void F_219 ( struct V_1 * V_2 ,
struct V_374 * V_375 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , T_6 V_306 ,
void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 ,
T_10 type )
{
F_119 ( & V_375 -> V_38 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type ) ;
V_375 -> V_306 = V_306 ;
V_375 -> V_403 = F_215 ;
}
int F_220 ( struct V_1 * V_2 ,
struct V_39 * V_70 )
{
if ( ! V_70 -> V_216 ) {
F_38 ( L_93 ) ;
return - V_66 ;
}
return 0 ;
}
int F_221 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
int V_22 , V_408 ;
unsigned long * V_409 = & V_4 -> V_409 ;
V_22 = V_4 -> V_410 ( V_2 , V_4 , V_405 ) ;
if ( V_22 ) {
F_38 ( L_94 , V_22 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_95 , V_4 -> V_409 ) ;
V_408 = V_4 -> V_196 ( V_4 , V_405 ) ;
F_4 ( V_17 , L_96 , V_4 -> V_409 ) ;
if ( F_18 ( V_28 , & V_405 -> V_25 ) )
V_4 -> V_411 ( V_2 , V_4 , V_408 ) ;
else {
V_22 = V_4 -> V_412 ( V_2 , V_405 ) ;
if ( V_22 ) {
V_4 -> V_413 = V_414 ;
F_29 ( V_408 , V_409 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_405 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_408 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_408 , V_409 ) ;
}
static int F_222 ( struct V_406 * V_415 ,
struct V_404 * V_405 )
{
enum V_416 V_111 = V_405 -> V_111 , V_331 ;
if ( ( V_111 == V_417 ) ||
( V_111 == V_418 ) )
V_331 = V_419 ;
else
V_331 = V_111 ;
F_32 ( V_331 , & V_415 -> V_409 ) ;
return V_331 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_406 * V_4 ,
enum V_416 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_409 ) ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_406 * V_4 ,
enum V_416 V_111 )
{
unsigned long V_420 = V_4 -> V_409 ;
if ( ! F_225 ( V_111 , & V_420 ) ) {
F_38 ( L_97 ,
V_111 , V_4 -> V_421 [ V_422 ] ,
V_4 -> V_33 , V_420 , V_4 -> V_413 ) ;
return - V_66 ;
}
if ( V_4 -> V_423 >= V_4 -> V_424 )
F_38 ( L_98 ,
V_4 -> V_423 , V_4 -> V_424 ) ;
F_4 ( V_17 ,
L_99 ,
V_111 , V_4 -> V_421 [ V_422 ] , V_4 -> V_413 ) ;
if ( V_4 -> V_423 )
F_4 ( V_17 , L_100 ,
V_4 -> V_421 [ V_422 ] , V_4 -> V_423 ) ;
V_4 -> V_33 = V_4 -> V_413 ;
V_4 -> V_425 = V_4 -> V_423 ;
V_4 -> V_413 = V_414 ;
F_226 () ;
F_29 ( V_111 , & V_4 -> V_409 ) ;
F_30 () ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 ,
struct V_404 * V_426 ,
struct V_427 * V_64 )
{
struct V_428 * V_405 = & V_426 -> V_405 . V_429 ;
V_64 -> V_430 . V_431 |= F_18 ( V_432 , & V_405 -> V_139 ) *
V_433 ;
}
static void F_228 ( struct V_1 * V_2 ,
struct V_406 * V_4 ,
struct V_434 * V_405 ,
struct V_435 * V_436 ,
unsigned long * V_139 )
{
V_436 -> V_95 = V_4 -> V_96 ;
if ( F_18 ( V_437 , V_139 ) ) {
V_436 -> V_438 =
V_405 -> V_439 ;
V_436 -> V_440 = 1 ;
V_436 -> V_441 =
F_18 ( V_442 , V_139 ) ;
} else
V_436 -> V_438 =
V_443 ;
V_436 -> V_444 = F_18 ( V_445 , V_139 ) ;
V_436 -> V_446 = F_18 ( V_447 , V_139 ) ;
V_436 -> V_448 = V_405 -> V_449 ;
V_436 -> V_450 = F_82 ( V_405 -> V_450 ) ;
V_436 -> V_97 = V_4 -> V_97 ;
V_436 -> cos = V_405 -> cos ;
V_436 -> V_451 =
F_18 ( V_445 , V_139 ) ?
V_452 : V_453 ;
F_4 ( V_17 , L_101 ,
V_436 -> V_446 , V_436 -> cos , V_436 -> V_440 ) ;
}
static void F_229 ( struct V_406 * V_4 ,
struct V_454 * V_405 ,
struct V_455 * V_456 ,
unsigned long * V_139 )
{
V_456 -> V_457 =
F_18 ( V_458 , V_139 ) ;
V_456 -> V_459 =
F_82 ( V_405 -> V_459 ) ;
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
F_18 ( V_471 , V_139 ) ? V_472 :
V_473 ;
V_456 -> V_474 = V_405 -> V_475 ;
V_456 -> V_476 = V_405 -> V_477 ;
V_456 -> V_478 = V_405 -> V_479 ;
V_456 -> V_480 . V_481 =
F_79 ( F_113 ( V_405 -> V_482 ) ) ;
V_456 -> V_480 . V_483 =
F_79 ( F_112 ( V_405 -> V_482 ) ) ;
V_456 -> V_33 = 0 ;
}
static void F_230 ( struct V_406 * V_4 ,
struct V_484 * V_405 ,
struct V_485 * V_486 )
{
V_486 -> V_487 = F_82 ( V_405 -> V_488 ) ;
V_486 -> V_489 = F_82 ( V_405 -> V_490 ) ;
V_486 -> V_491 = F_82 ( V_405 -> V_492 ) ;
V_486 -> V_493 = F_82 ( V_405 -> V_494 ) ;
V_486 -> V_495 = F_82 ( V_405 -> V_496 ) ;
V_486 -> V_497 = F_82 ( V_405 -> V_498 ) ;
V_486 -> V_499 = F_82 ( V_405 -> V_500 ) ;
}
static void F_231 ( struct V_406 * V_4 ,
struct V_501 * V_405 ,
struct V_485 * V_486 ,
unsigned long * V_139 )
{
V_486 -> V_431 = F_18 ( V_502 , V_139 ) *
V_503 ;
V_486 -> V_431 |= F_18 ( V_504 , V_139 ) *
V_505 ;
V_486 -> V_506 = 0 ;
V_486 -> V_507 =
V_405 -> V_508 ;
V_486 -> V_509 =
F_18 ( V_510 , V_139 ) ;
V_486 -> V_511 = V_405 -> V_512 ;
V_486 -> V_513 = V_405 -> V_514 ;
V_486 -> V_515 = F_82 ( V_405 -> V_516 ) ;
V_486 -> V_33 = F_82 ( V_517 |
V_518 ) ;
V_486 -> V_519 = 0 ;
V_486 -> V_520 = 0 ;
V_486 -> V_521 = 0 ;
V_486 -> V_522 = 0 ;
V_486 -> V_523 =
F_18 ( V_524 , V_139 ) ;
V_486 -> V_525 =
F_18 ( V_526 , V_139 ) ;
V_486 -> V_527 = V_405 -> V_475 ;
V_486 -> V_528 = V_405 -> V_477 ;
V_486 -> V_529 = V_405 -> V_529 ;
V_486 -> V_530 = F_82 ( V_405 -> V_531 ) ;
V_486 -> V_532 = F_82 ( V_405 -> V_533 ) ;
V_486 -> V_534 . V_481 =
F_79 ( F_113 ( V_405 -> V_482 ) ) ;
V_486 -> V_534 . V_483 =
F_79 ( F_112 ( V_405 -> V_482 ) ) ;
V_486 -> V_535 . V_481 =
F_79 ( F_113 ( V_405 -> V_536 ) ) ;
V_486 -> V_535 . V_483 =
F_79 ( F_112 ( V_405 -> V_536 ) ) ;
V_486 -> V_537 . V_481 =
F_79 ( F_113 ( V_405 -> V_538 ) ) ;
V_486 -> V_537 . V_483 =
F_79 ( F_112 ( V_405 -> V_538 ) ) ;
V_486 -> V_539 = F_18 ( V_540 , V_139 ) ;
if ( F_18 ( V_541 , V_139 ) ) {
V_486 -> V_542 = V_405 -> V_543 ;
V_486 -> V_544 = 1 ;
}
V_486 -> V_397 = V_405 -> V_397 ;
V_486 -> V_545 =
F_18 ( V_546 , V_139 ) ;
V_486 -> V_547 =
F_82 ( V_405 -> V_548 ) ;
V_486 -> V_549 =
F_82 ( V_405 -> V_550 ) ;
}
static void F_232 ( struct V_1 * V_2 ,
struct V_404 * V_426 ,
struct V_427 * V_64 )
{
F_228 ( V_2 , V_426 -> V_407 ,
& V_426 -> V_405 . V_429 . V_551 ,
& V_64 -> V_552 ,
& V_426 -> V_405 . V_429 . V_139 ) ;
F_229 ( V_426 -> V_407 ,
& V_426 -> V_405 . V_429 . V_553 ,
& V_64 -> V_554 ,
& V_426 -> V_405 . V_429 . V_139 ) ;
F_231 ( V_426 -> V_407 ,
& V_426 -> V_405 . V_429 . V_555 ,
& V_64 -> V_430 ,
& V_426 -> V_405 . V_429 . V_139 ) ;
F_230 ( V_426 -> V_407 ,
& V_426 -> V_405 . V_429 . V_556 ,
& V_64 -> V_430 ) ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_404 * V_426 ,
struct V_557 * V_64 )
{
F_228 ( V_2 , V_426 -> V_407 ,
& V_426 -> V_405 . V_558 . V_551 ,
& V_64 -> V_552 ,
& V_426 -> V_405 . V_558 . V_139 ) ;
F_229 ( V_426 -> V_407 ,
& V_426 -> V_405 . V_558 . V_553 ,
& V_64 -> V_554 ,
& V_426 -> V_405 . V_558 . V_139 ) ;
F_4 ( V_17 , L_102 ,
V_426 -> V_407 -> V_421 [ 0 ] ,
V_64 -> V_554 . V_480 . V_481 ,
V_64 -> V_554 . V_480 . V_483 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
struct V_559 * V_560 = & V_405 -> V_405 . V_560 ;
T_8 V_561 ;
T_6 cos ;
if ( F_18 ( V_562 , & V_4 -> type ) &&
F_18 ( V_563 , & V_560 -> V_554 . V_139 ) ) {
V_561 = V_560 -> V_554 . V_564 ? 1000000 / V_560 -> V_554 . V_564 : 0 ;
F_235 ( V_2 , V_560 -> V_554 . V_475 ,
V_560 -> V_554 . V_477 ,
! F_18 ( V_565 , & V_560 -> V_554 . V_139 ) ,
V_561 ) ;
}
if ( F_18 ( V_566 , & V_4 -> type ) &&
F_18 ( V_563 , & V_560 -> V_430 . V_139 ) ) {
V_561 = V_560 -> V_430 . V_564 ? 1000000 / V_560 -> V_430 . V_564 : 0 ;
F_235 ( V_2 , V_560 -> V_430 . V_475 ,
V_560 -> V_430 . V_477 ,
! F_18 ( V_565 , & V_560 -> V_430 . V_139 ) ,
V_561 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_424 ; cos ++ ) {
F_4 ( V_17 , L_103 ,
V_4 -> V_421 [ cos ] , cos ) ;
F_4 ( V_17 , L_104 , V_560 -> V_567 [ cos ] ) ;
F_236 ( V_2 , V_560 -> V_567 [ cos ] , V_4 -> V_421 [ cos ] ) ;
}
V_4 -> V_411 ( V_2 , V_4 , V_568 ) ;
F_237 () ;
F_200 () ;
return 0 ;
}
static inline int F_238 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
struct V_427 * V_110 =
(struct V_427 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
int V_570 = V_571 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_232 ( V_2 , V_405 , V_110 ) ;
return F_111 ( V_2 , V_570 , V_4 -> V_421 [ V_422 ] ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_201 ) ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
struct V_427 * V_110 =
(struct V_427 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
int V_570 = V_571 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_232 ( V_2 , V_405 , V_110 ) ;
F_227 ( V_2 , V_405 , V_110 ) ;
return F_111 ( V_2 , V_570 , V_4 -> V_421 [ V_422 ] ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_201 ) ;
}
static inline int F_240 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
struct V_557 * V_110 =
(struct V_557 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
int V_570 = V_572 ;
struct V_573 * V_574 =
& V_405 -> V_405 . V_558 ;
T_6 V_575 = V_574 -> V_575 ;
if ( V_575 >= V_4 -> V_424 ) {
F_38 ( L_105 ,
V_4 -> V_96 , V_575 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_106 ,
V_574 -> V_551 . cos ,
V_574 -> V_551 . V_449 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_233 ( V_2 , V_405 , V_110 ) ;
F_4 ( V_17 , L_107 ,
V_4 -> V_421 [ V_575 ] , V_110 -> V_552 . V_95 ,
V_110 -> V_552 . V_448 , V_110 -> V_552 . cos ) ;
return F_111 ( V_2 , V_570 , V_4 -> V_421 [ V_575 ] ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_201 ) ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_406 * V_415 ,
struct V_576 * V_405 ,
struct V_577 * V_64 )
{
V_64 -> V_95 = V_415 -> V_96 ;
V_64 -> V_97 = V_415 -> V_97 ;
V_64 -> V_459 = F_82 ( V_405 -> V_578 ) ;
V_64 -> V_523 =
F_18 ( V_579 , & V_405 -> V_580 ) ;
V_64 -> V_581 =
F_18 ( V_582 ,
& V_405 -> V_580 ) ;
V_64 -> V_525 =
F_18 ( V_583 , & V_405 -> V_580 ) ;
V_64 -> V_584 =
F_18 ( V_585 ,
& V_405 -> V_580 ) ;
V_64 -> V_586 =
F_18 ( V_587 , & V_405 -> V_580 ) ;
V_64 -> V_588 =
F_18 ( V_589 , & V_405 -> V_580 ) ;
V_64 -> V_446 =
F_18 ( V_590 , & V_405 -> V_580 ) ;
V_64 -> V_591 =
F_18 ( V_592 , & V_405 -> V_580 ) ;
V_64 -> V_593 =
F_18 ( V_594 , & V_405 -> V_580 ) ;
V_64 -> V_595 =
F_18 ( V_596 ,
& V_405 -> V_580 ) ;
V_64 -> V_597 =
F_18 ( V_598 ,
& V_405 -> V_580 ) ;
V_64 -> V_545 =
F_18 ( V_599 , & V_405 -> V_580 ) ;
V_64 -> V_547 = F_82 ( V_405 -> V_548 ) ;
V_64 -> V_549 = F_82 ( V_405 -> V_550 ) ;
}
static inline int F_242 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
struct V_577 * V_110 =
(struct V_577 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
struct V_576 * V_600 =
& V_405 -> V_405 . V_601 ;
T_6 V_575 = V_600 -> V_575 ;
if ( V_575 >= V_4 -> V_424 ) {
F_38 ( L_105 ,
V_4 -> V_96 , V_575 ) ;
return - V_66 ;
}
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_241 ( V_2 , V_4 , V_600 , V_110 ) ;
return F_111 ( V_2 , V_602 ,
V_4 -> V_421 [ V_575 ] , F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_201 ) ;
}
static inline int F_243 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_576 * V_601 = & V_405 -> V_405 . V_601 ;
memset ( V_601 , 0 , sizeof( * V_601 ) ) ;
F_94 ( V_592 , & V_601 -> V_580 ) ;
return F_242 ( V_2 , V_405 ) ;
}
static inline int F_244 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_576 * V_601 = & V_405 -> V_405 . V_601 ;
memset ( V_601 , 0 , sizeof( * V_601 ) ) ;
F_94 ( V_590 , & V_601 -> V_580 ) ;
F_94 ( V_592 , & V_601 -> V_580 ) ;
return F_242 ( V_2 , V_405 ) ;
}
static inline int F_245 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
return - 1 ;
}
static inline int F_246 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
return F_111 ( V_2 , V_603 ,
V_4 -> V_421 [ V_422 ] , 0 , V_4 -> V_96 ,
V_201 ) ;
}
static inline int F_247 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
T_6 V_604 = V_405 -> V_405 . V_605 . V_575 ;
if ( V_604 >= V_4 -> V_424 ) {
F_38 ( L_105 ,
V_4 -> V_96 , V_604 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_606 ,
V_4 -> V_421 [ V_604 ] , 0 , 0 , V_607 ) ;
}
static inline int F_248 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
T_6 V_575 = V_405 -> V_405 . V_608 . V_575 ;
if ( V_575 >= V_4 -> V_424 ) {
F_38 ( L_105 ,
V_4 -> V_96 , V_575 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_609 ,
V_4 -> V_421 [ V_575 ] , 0 , 0 , V_201 ) ;
}
static inline int F_249 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
struct V_406 * V_4 = V_405 -> V_407 ;
return F_111 ( V_2 , V_610 ,
V_4 -> V_421 [ V_422 ] , 0 , 0 ,
V_201 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
switch ( V_405 -> V_111 ) {
case V_568 :
return F_234 ( V_2 , V_405 ) ;
case V_611 :
return F_240 ( V_2 , V_405 ) ;
case V_418 :
return F_243 ( V_2 , V_405 ) ;
case V_417 :
return F_244 ( V_2 , V_405 ) ;
case V_419 :
return F_242 ( V_2 , V_405 ) ;
case V_612 :
return F_245 ( V_2 , V_405 ) ;
case V_613 :
return F_246 ( V_2 , V_405 ) ;
case V_614 :
return F_247 ( V_2 , V_405 ) ;
case V_615 :
return F_248 ( V_2 , V_405 ) ;
case V_616 :
return F_249 ( V_2 , V_405 ) ;
default:
F_38 ( L_65 , V_405 -> V_111 ) ;
return - V_66 ;
}
}
static int F_251 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
switch ( V_405 -> V_111 ) {
case V_617 :
return F_238 ( V_2 , V_405 ) ;
case V_568 :
case V_611 :
case V_418 :
case V_417 :
case V_419 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
return F_250 ( V_2 , V_405 ) ;
default:
F_38 ( L_65 , V_405 -> V_111 ) ;
return - V_66 ;
}
}
static int F_252 ( struct V_1 * V_2 ,
struct V_404 * V_405 )
{
switch ( V_405 -> V_111 ) {
case V_617 :
return F_239 ( V_2 , V_405 ) ;
case V_568 :
case V_611 :
case V_418 :
case V_417 :
case V_419 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
return F_250 ( V_2 , V_405 ) ;
default:
F_38 ( L_65 , V_405 -> V_111 ) ;
return - V_66 ;
}
}
static int F_253 ( struct V_1 * V_2 ,
struct V_406 * V_4 ,
struct V_404 * V_405 )
{
enum V_618 V_33 = V_4 -> V_33 , V_413 = V_414 ;
enum V_416 V_111 = V_405 -> V_111 ;
struct V_576 * V_600 =
& V_405 -> V_405 . V_601 ;
T_6 V_423 = V_4 -> V_425 ;
if ( F_18 ( V_28 , & V_405 -> V_25 ) ) {
V_4 -> V_409 = 0 ;
V_4 -> V_413 = V_414 ;
}
if ( V_4 -> V_409 ) {
F_38 ( L_108 ,
V_4 -> V_409 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_619 :
if ( V_111 == V_568 )
V_413 = V_620 ;
break;
case V_620 :
if ( V_111 == V_617 ) {
if ( F_18 ( V_447 ,
& V_405 -> V_405 . V_429 . V_139 ) )
V_413 = V_621 ;
else
V_413 = V_622 ;
}
break;
case V_621 :
if ( V_111 == V_418 )
V_413 = V_622 ;
else if ( ( V_111 == V_616 ) ||
( V_111 == V_612 ) )
V_413 = V_621 ;
else if ( V_111 == V_611 ) {
V_413 = V_623 ;
V_423 = 1 ;
}
else if ( V_111 == V_613 )
V_413 = V_624 ;
else if ( V_111 == V_419 ) {
if ( F_18 ( V_592 ,
& V_600 -> V_580 ) &&
! F_18 ( V_590 ,
& V_600 -> V_580 ) )
V_413 = V_622 ;
else
V_413 = V_621 ;
}
break;
case V_623 :
if ( V_111 == V_615 )
V_413 = V_625 ;
else if ( V_111 == V_611 ) {
V_413 = V_623 ;
V_423 = V_4 -> V_425 + 1 ;
}
else if ( ( V_111 == V_616 ) ||
( V_111 == V_612 ) )
V_413 = V_623 ;
else if ( V_111 == V_419 ) {
if ( F_18 ( V_592 ,
& V_600 -> V_580 ) &&
! F_18 ( V_590 ,
& V_600 -> V_580 ) )
V_413 = V_622 ;
else
V_413 = V_623 ;
}
break;
case V_625 :
if ( V_111 == V_614 ) {
V_423 = V_4 -> V_425 - 1 ;
if ( V_423 == 0 )
V_413 = V_621 ;
else
V_413 = V_623 ;
}
break;
case V_622 :
if ( V_111 == V_417 )
V_413 = V_621 ;
else if ( ( V_111 == V_616 ) ||
( V_111 == V_612 ) )
V_413 = V_622 ;
else if ( V_111 == V_613 )
V_413 = V_624 ;
else if ( V_111 == V_419 ) {
if ( F_18 ( V_592 ,
& V_600 -> V_580 ) &&
F_18 ( V_590 ,
& V_600 -> V_580 ) ) {
if ( V_4 -> V_425 == 0 )
V_413 = V_621 ;
else
V_413 = V_623 ;
} else
V_413 = V_622 ;
}
break;
case V_624 :
if ( V_111 == V_615 )
V_413 = V_626 ;
break;
case V_626 :
if ( V_111 == V_614 )
V_413 = V_619 ;
break;
default:
F_38 ( L_109 , V_33 ) ;
}
if ( V_413 != V_414 ) {
F_4 ( V_17 , L_110 ,
V_33 , V_111 , V_413 ) ;
V_4 -> V_413 = V_413 ;
V_4 -> V_423 = V_423 ;
return 0 ;
}
F_4 ( V_17 , L_111 , V_33 , V_111 ) ;
return - V_66 ;
}
void F_254 ( struct V_1 * V_2 ,
struct V_406 * V_415 ,
T_6 V_96 , T_7 * V_421 , T_6 V_627 , T_6 V_97 ,
void * V_110 ,
T_9 V_200 , unsigned long type )
{
memset ( V_415 , 0 , sizeof( * V_415 ) ) ;
F_255 ( V_628 < V_627 ) ;
memcpy ( V_415 -> V_421 , V_421 , sizeof( V_415 -> V_421 [ 0 ] ) * V_627 ) ;
V_415 -> V_424 = V_627 ;
V_415 -> V_96 = V_96 ;
V_415 -> V_97 = V_97 ;
V_415 -> V_110 = V_110 ;
V_415 -> V_200 = V_200 ;
V_415 -> type = type ;
V_415 -> V_413 = V_414 ;
if ( F_122 ( V_2 ) )
V_415 -> V_412 = F_251 ;
else
V_415 -> V_412 = F_252 ;
V_415 -> V_410 = F_253 ;
V_415 -> V_411 = F_224 ;
V_415 -> V_179 = F_223 ;
V_415 -> V_196 = F_222 ;
}
int F_256 ( struct V_1 * V_2 ,
struct V_406 * V_415 )
{
switch ( V_415 -> V_33 ) {
case V_621 :
case V_623 :
return V_629 ;
case V_619 :
case V_620 :
case V_625 :
case V_622 :
case V_624 :
case V_626 :
case V_630 :
return V_631 ;
default:
return - V_66 ;
}
}
enum V_632 F_257 ( struct V_1 * V_2 ,
struct V_633 * V_4 )
{
if ( V_4 -> V_409 )
return V_634 ;
F_258 () ;
return V_4 -> V_33 ;
}
static int F_259 ( struct V_1 * V_2 ,
struct V_633 * V_4 ,
enum V_635 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_409 ) ;
}
static inline int F_260 ( struct V_1 * V_2 ,
struct V_633 * V_4 ,
enum V_635 V_111 )
{
unsigned long V_420 = V_4 -> V_409 ;
if ( ! F_225 ( V_111 , & V_420 ) ) {
F_38 ( L_112 ,
V_111 , F_261 ( V_2 ) , V_4 -> V_33 ,
V_420 , V_4 -> V_413 ) ;
return - V_66 ;
}
F_4 ( V_17 ,
L_113 ,
V_111 , F_261 ( V_2 ) , V_4 -> V_413 ) ;
V_4 -> V_33 = V_4 -> V_413 ;
V_4 -> V_413 = V_634 ;
F_226 () ;
F_29 ( V_111 , & V_4 -> V_409 ) ;
F_30 () ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_633 * V_4 ,
enum V_635 V_111 )
{
int V_22 = F_260 ( V_2 , V_4 , V_111 ) ;
return V_22 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_633 * V_4 ,
struct V_636 * V_405 )
{
enum V_632 V_33 = V_4 -> V_33 , V_413 = V_634 ;
enum V_635 V_111 = V_405 -> V_111 ;
if ( F_18 ( V_28 , & V_405 -> V_25 ) ) {
V_4 -> V_409 = 0 ;
V_4 -> V_413 = V_634 ;
}
if ( V_4 -> V_409 )
return - V_37 ;
switch ( V_33 ) {
case V_637 :
if ( V_111 == V_638 )
V_413 = V_639 ;
break;
case V_639 :
if ( V_111 == V_640 )
V_413 = V_641 ;
else if ( V_111 == V_642 )
V_413 = V_637 ;
break;
case V_641 :
if ( V_111 == V_643 )
V_413 = V_639 ;
else if ( ( V_111 == V_644 ) &&
( ! F_18 ( V_643 , & V_4 -> V_409 ) ) )
V_413 = V_641 ;
else if ( ( V_111 == V_645 ) &&
( ! F_18 ( V_643 , & V_4 -> V_409 ) ) )
V_413 = V_641 ;
else if ( ( V_111 == V_646 ) &&
( ! F_18 ( V_643 , & V_4 -> V_409 ) ) )
V_413 = V_641 ;
else if ( V_111 == V_647 )
V_413 = V_648 ;
break;
case V_648 :
if ( ( V_111 == V_646 ) &&
( ! F_18 ( V_643 , & V_4 -> V_409 ) ) )
V_413 = V_648 ;
else if ( V_111 == V_649 )
V_413 = V_641 ;
break;
default:
F_38 ( L_114 , V_33 ) ;
}
if ( V_413 != V_634 ) {
F_4 ( V_17 , L_115 ,
V_33 , V_111 , V_413 ) ;
V_4 -> V_413 = V_413 ;
return 0 ;
}
F_4 ( V_17 , L_116 ,
V_33 , V_111 ) ;
return - V_66 ;
}
static inline int F_264 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
return V_651 -> V_652 ( V_2 ) ;
}
static inline int F_265 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
int V_22 = V_651 -> V_653 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_264 ( V_2 , V_651 ) ;
}
static inline int F_266 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
int V_22 = V_651 -> V_654 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_265 ( V_2 , V_651 ) ;
}
static inline int F_267 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
int V_22 = V_651 -> V_655 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_265 ( V_2 , V_651 ) ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
T_7 V_656 = V_405 -> V_405 . V_657 . V_658 ;
struct V_633 * V_4 = V_405 -> V_659 ;
const struct V_650 * V_651 = V_4 -> V_651 ;
int V_22 = 0 ;
F_4 ( V_17 , L_117 ,
F_269 ( V_2 ) , V_656 ) ;
V_22 = V_651 -> V_660 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_651 -> V_661 ( V_2 ) ;
if ( V_22 ) {
F_38 ( L_118 ) ;
goto V_662;
}
switch ( V_656 ) {
case V_663 :
V_22 = F_266 ( V_2 , V_651 ) ;
if ( V_22 )
goto V_662;
break;
case V_664 :
V_22 = F_267 ( V_2 , V_651 ) ;
if ( V_22 )
goto V_662;
break;
case V_665 :
V_22 = F_265 ( V_2 , V_651 ) ;
if ( V_22 )
goto V_662;
break;
case V_666 :
V_22 = F_264 ( V_2 , V_651 ) ;
if ( V_22 )
goto V_662;
break;
default:
F_38 ( L_119 , V_656 ) ;
V_22 = - V_66 ;
}
V_662:
V_651 -> V_667 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_411 ( V_2 , V_4 , V_638 ) ;
return V_22 ;
}
static inline void F_270 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
V_651 -> V_668 ( V_2 ) ;
}
static inline void F_271 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
V_651 -> V_669 ( V_2 ) ;
F_270 ( V_2 , V_651 ) ;
}
static inline void F_272 ( struct V_1 * V_2 ,
const struct V_650 * V_651 )
{
F_271 ( V_2 , V_651 ) ;
V_651 -> V_670 ( V_2 ) ;
}
static inline int F_273 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
T_7 V_671 = V_405 -> V_405 . V_672 . V_671 ;
struct V_633 * V_4 = V_405 -> V_659 ;
const struct V_650 * V_651 = V_4 -> V_651 ;
F_4 ( V_17 , L_120 , F_269 ( V_2 ) ,
V_671 ) ;
switch ( V_671 ) {
case V_673 :
F_272 ( V_2 , V_651 ) ;
break;
case V_674 :
F_271 ( V_2 , V_651 ) ;
break;
case V_675 :
F_270 ( V_2 , V_651 ) ;
break;
default:
F_38 ( L_121 ,
V_671 ) ;
break;
}
V_4 -> V_411 ( V_2 , V_4 , V_642 ) ;
return 0 ;
}
static inline int F_274 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
struct V_676 * V_110 =
(struct V_676 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
struct V_677 * V_678 = & V_405 -> V_405 . V_679 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_680 = ( T_6 ) V_678 -> V_681 ;
V_110 -> V_682 = F_82 ( V_678 -> V_682 ) ;
V_110 -> V_683 = F_275 ( V_2 ) ;
V_110 -> V_684 = V_678 -> V_684 ;
V_110 -> V_685 = V_678 -> V_685 ;
V_110 -> V_686 = V_678 -> V_686 ;
return F_111 ( V_2 , V_687 , 0 ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_607 ) ;
}
static inline int F_276 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
struct V_688 * V_110 =
(struct V_688 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
struct V_689 * V_690 =
& V_405 -> V_405 . V_691 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_692 = 1 ;
V_110 -> V_693 = V_690 -> V_694 ;
V_110 -> V_104 = V_695 ;
return F_111 ( V_2 , V_696 , 0 ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_607 ) ;
}
static inline int F_277 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
struct V_688 * V_110 =
(struct V_688 * ) V_4 -> V_697 ;
T_9 V_569 = V_4 -> V_698 ;
struct V_699 * V_700 =
& V_405 -> V_405 . V_701 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_702 = 1 ;
V_110 -> V_703 = F_82 ( V_700 -> V_703 ) ;
V_110 -> V_704 = 1 ;
V_110 -> V_705 =
F_82 ( V_700 -> V_705 ) ;
V_110 -> V_706 = 1 ;
V_110 -> V_707 = V_700 -> V_707 ;
V_110 -> V_104 = V_708 ;
F_4 ( V_17 ,
L_122 ,
V_110 -> V_703 ,
V_110 -> V_705 , V_110 -> V_707 ) ;
return F_111 ( V_2 , V_696 , 0 ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_607 ) ;
}
static
inline int F_278 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
struct V_709 * V_110 =
(struct V_709 * ) V_4 -> V_697 ;
struct V_710 * V_711 =
& V_405 -> V_405 . V_712 ;
T_12 * V_713 = ( T_12 * ) V_110 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_714 = F_82 ( V_711 -> V_714 ) ;
V_110 -> V_715 = V_711 -> V_715 ;
V_110 -> V_716 = V_711 -> V_716 ;
V_110 -> V_717 = V_711 -> V_717 ;
V_110 -> V_104 = V_711 -> V_716 ;
F_4 ( V_17 , L_123 ,
V_110 -> V_716 , V_110 -> V_714 ,
V_110 -> V_715 , V_110 -> V_717 ) ;
return F_111 ( V_2 , V_718 , 0 ,
F_112 ( * V_713 ) , F_113 ( * V_713 ) ,
V_607 ) ;
}
static inline int F_279 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
return F_111 ( V_2 , V_719 , 0 , 0 , 0 ,
V_607 ) ;
}
static inline int F_280 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
return F_111 ( V_2 , V_720 , 0 , 0 , 0 ,
V_607 ) ;
}
static inline int F_281 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
struct V_721 * V_110 =
(struct V_721 * ) V_4 -> V_110 ;
T_9 V_569 = V_4 -> V_200 ;
struct V_722 * V_723 =
& V_405 -> V_405 . V_724 ;
int V_288 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_725 = V_723 -> V_725 ;
V_110 -> V_726 = V_723 -> V_726 ;
V_110 -> V_727 = V_723 -> V_727 ;
for ( V_288 = 0 ; V_288 < F_282 ( V_110 -> V_728 ) ; V_288 ++ )
V_110 -> V_728 [ V_288 ] =
V_723 -> V_728 [ V_288 ] ;
return F_111 ( V_2 , V_729 , 0 ,
F_112 ( V_569 ) ,
F_113 ( V_569 ) , V_607 ) ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
switch ( V_405 -> V_111 ) {
case V_638 :
return F_268 ( V_2 , V_405 ) ;
case V_640 :
return F_274 ( V_2 , V_405 ) ;
case V_643 :
return F_279 ( V_2 , V_405 ) ;
case V_642 :
return F_273 ( V_2 , V_405 ) ;
case V_644 :
return F_277 ( V_2 , V_405 ) ;
case V_645 :
return F_278 ( V_2 , V_405 ) ;
case V_647 :
return F_280 ( V_2 , V_405 ) ;
case V_649 :
return F_281 ( V_2 , V_405 ) ;
case V_646 :
return F_276 ( V_2 , V_405 ) ;
default:
F_38 ( L_65 , V_405 -> V_111 ) ;
return - V_66 ;
}
}
void F_284 ( struct V_1 * V_2 ,
struct V_633 * V_415 ,
void * V_110 , T_9 V_200 ,
void * V_697 , T_9 V_698 ,
struct V_650 * V_730 )
{
memset ( V_415 , 0 , sizeof( * V_415 ) ) ;
F_285 ( & V_415 -> V_731 ) ;
V_415 -> V_110 = V_110 ;
V_415 -> V_200 = V_200 ;
V_415 -> V_697 = V_697 ;
V_415 -> V_698 = V_698 ;
V_415 -> V_412 = F_283 ;
V_415 -> V_410 = F_263 ;
V_415 -> V_411 = F_262 ;
V_415 -> V_179 = F_259 ;
V_415 -> V_651 = V_730 ;
}
int F_286 ( struct V_1 * V_2 ,
struct V_636 * V_405 )
{
struct V_633 * V_4 = V_405 -> V_659 ;
int V_22 , V_20 = 300 ;
enum V_635 V_111 = V_405 -> V_111 ;
unsigned long * V_409 = & V_4 -> V_409 ;
F_287 ( & V_4 -> V_731 ) ;
V_22 = V_4 -> V_410 ( V_2 , V_4 , V_405 ) ;
if ( ( V_22 == - V_37 ) &&
( F_18 ( V_732 , & V_405 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_288 ( & V_4 -> V_731 ) ;
F_289 ( 10 ) ;
F_287 ( & V_4 -> V_731 ) ;
V_22 = V_4 -> V_410 ( V_2 , V_4 , V_405 ) ;
}
if ( V_22 == - V_37 ) {
F_288 ( & V_4 -> V_731 ) ;
F_38 ( L_124 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_288 ( & V_4 -> V_731 ) ;
return V_22 ;
}
F_32 ( V_111 , V_409 ) ;
if ( F_18 ( V_28 , & V_405 -> V_25 ) ) {
F_260 ( V_2 , V_4 , V_111 ) ;
F_288 ( & V_4 -> V_731 ) ;
} else {
V_22 = V_4 -> V_412 ( V_2 , V_405 ) ;
F_288 ( & V_4 -> V_731 ) ;
if ( V_22 ) {
V_4 -> V_413 = V_634 ;
F_29 ( V_111 , V_409 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_405 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_111 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_111 , V_409 ) ;
}
