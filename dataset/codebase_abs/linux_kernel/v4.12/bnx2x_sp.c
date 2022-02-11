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
if ( ( V_22 != 0 ) && ( V_22 != 1 ) ) {
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
static int F_55 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
V_4 -> V_49 ++ ;
F_4 ( V_17 , L_15 ,
V_4 -> V_49 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_22 ;
F_8 ( & V_4 -> V_12 . V_14 ) ;
V_22 = F_55 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
return V_22 ;
}
static void F_57 ( struct V_1 * V_2 ,
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
void F_58 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
F_8 ( & V_4 -> V_12 . V_14 ) ;
F_57 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_39 * V_4 ,
int V_52 , T_6 * V_53 , T_6 V_54 , T_6 V_55 )
{
struct V_56 * V_57 ;
T_6 * V_58 = V_53 ;
int V_59 = 0 ;
int V_60 ;
F_4 ( V_17 , L_19 ) ;
V_60 = F_56 ( V_2 , V_4 ) ;
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
F_58 ( V_2 , V_4 ) ;
}
return V_59 * V_62 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_63 * V_64 )
{
struct V_56 * V_57 ;
F_4 ( V_17 , L_23 , V_64 -> V_65 . V_65 ) ;
if ( ! F_61 ( V_64 -> V_65 . V_65 ) )
return - V_66 ;
F_9 (pos, &o->head, link)
if ( F_62 ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 ) &&
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
if ( F_62 ( V_64 -> V_65 . V_65 , V_57 -> V_61 . V_65 . V_65 ) &&
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
static void F_71 ( struct V_1 * V_2 ,
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
T_8 V_128 ;
if ( V_107 == 0 )
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_77 ( V_2 , V_4 , V_82 , V_153 ,
& V_114 -> V_154 . V_124 ) ;
V_114 -> V_154 . V_69 = F_82 ( V_69 ) ;
F_81 ( & V_114 -> V_154 . V_125 ,
& V_114 -> V_154 . V_126 ,
& V_114 -> V_154 . V_127 , V_65 ) ;
V_128 = V_19 -> V_112 . V_70 . V_61 . V_70 . V_67 ;
V_114 -> V_154 . V_128 = F_82 ( V_128 ) ;
if ( V_111 == V_118 ) {
struct V_39 * V_129 ;
V_114 ++ ;
V_103 ++ ;
V_129 = V_19 -> V_112 . V_70 . V_129 ;
F_77 ( V_2 , V_129 ,
true , V_153 ,
& V_114 -> V_154 . V_124 ) ;
V_114 -> V_154 . V_69 = F_82 ( V_69 ) ;
F_81 ( & V_114 -> V_154 . V_125 ,
& V_114 -> V_154 . V_126 ,
& V_114 -> V_154 . V_127 , V_65 ) ;
V_114 -> V_154 . V_128 = F_82 ( V_128 ) ;
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
( V_57 -> V_112 . V_70 . V_111 ==
V_19 -> V_112 . V_70 . V_111 ) )
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
V_60 = F_56 ( V_2 , V_4 ) ;
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
F_58 ( V_2 , V_4 ) ;
return V_22 ;
}
}
}
F_4 ( V_17 , L_58 ) ;
F_58 ( V_2 , V_4 ) ;
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
V_212 -> V_74 = F_60 ;
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
V_212 -> V_74 = F_60 ;
V_212 -> V_176 = F_68 ;
V_212 -> V_199 =
V_215 ;
V_212 -> V_216 = F_59 ;
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
V_218 -> V_216 = F_59 ;
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
static void F_143 ( struct V_190 * V_268 )
{
struct V_269 * V_270 ;
while ( ! F_14 ( V_268 ) ) {
V_270 = F_15 ( V_268 ,
struct V_269 ,
V_271 ) ;
F_16 ( & V_270 -> V_271 ) ;
F_144 ( ( unsigned long ) V_270 ) ;
}
}
static int F_145 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_274 * V_275 ;
struct V_276 * V_57 ;
struct V_269 * V_277 ;
struct V_278 * V_279 ;
int V_280 = 0 , V_281 = 0 , V_40 = 0 ;
if ( V_111 == V_282 || V_111 == V_283 )
V_281 = V_158 -> V_284 ;
if ( ! V_158 -> V_284 )
return 0 ;
V_275 = F_25 ( sizeof( * V_275 ) , V_31 ) ;
if ( ! V_275 )
return - V_188 ;
F_2 ( & V_275 -> V_64 . V_285 ) ;
F_2 ( & V_275 -> V_286 ) ;
V_275 -> type = V_111 ;
V_275 -> V_287 = false ;
F_4 ( V_17 , L_64 ,
V_111 , V_281 ) ;
switch ( V_111 ) {
case V_282 :
case V_283 :
V_280 = V_281 ;
if ( V_111 == V_283 ) {
if ( V_280 < V_288 )
V_280 = V_288 ;
}
while ( V_280 > 0 ) {
V_277 = (struct V_269 * )
F_146 ( V_31 | V_289 ) ;
if ( ! V_277 ) {
F_143 ( & V_275 -> V_286 ) ;
F_6 ( V_275 ) ;
return - V_188 ;
}
V_280 -= V_290 ;
F_12 ( & V_277 -> V_271 ,
& V_275 -> V_286 ) ;
}
V_277 = F_15 ( & V_275 -> V_286 ,
struct V_269 ,
V_271 ) ;
F_9 (pos, &p->mcast_list, link) {
V_279 = & V_277 -> V_291 [ V_40 ] . V_279 ;
memcpy ( V_279 -> V_65 , V_57 -> V_65 , V_62 ) ;
F_12 ( & V_279 -> V_24 ,
& V_275 -> V_64 . V_285 ) ;
V_40 ++ ;
if ( V_40 == V_290 ) {
V_40 = 0 ;
V_277 = F_92 ( V_277 ,
V_271 ) ;
}
}
break;
case V_292 :
V_275 -> V_64 . V_293 = V_158 -> V_284 ;
break;
case V_294 :
V_275 -> V_64 . V_295 = 0 ;
break;
default:
F_6 ( V_275 ) ;
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
F_12 ( & V_275 -> V_24 , & V_4 -> V_296 ) ;
V_4 -> V_297 ( V_4 ) ;
return 1 ;
}
static inline int F_147 ( struct V_266 * V_4 , int V_298 )
{
int V_299 , V_300 , V_301 = V_298 % V_302 ;
for ( V_299 = V_298 / V_302 ; V_299 < V_303 ; V_299 ++ ) {
if ( V_4 -> V_304 . V_305 . V_306 [ V_299 ] )
for ( V_300 = V_301 ; V_300 < V_302 ; V_300 ++ ) {
int V_307 = V_300 + V_302 * V_299 ;
if ( F_148 ( V_4 -> V_304 . V_305 .
V_306 , V_307 ) ) {
return V_307 ;
}
}
V_301 = 0 ;
}
return - 1 ;
}
static inline int F_149 ( struct V_266 * V_4 )
{
int V_307 = F_147 ( V_4 , 0 ) ;
if ( V_307 >= 0 )
F_150 ( V_4 -> V_304 . V_305 . V_306 , V_307 ) ;
return V_307 ;
}
static inline T_6 F_151 ( struct V_266 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_6 V_75 = 0 ;
if ( ( V_38 -> V_76 == V_77 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_308 ;
if ( ( V_38 -> V_76 == V_80 ) ||
( V_38 -> V_76 == V_78 ) )
V_75 |= V_309 ;
return V_75 ;
}
static void F_152 ( struct V_1 * V_2 ,
struct V_266 * V_4 , int V_193 ,
union V_310 * V_311 ,
enum V_273 V_111 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_312 * V_64 =
(struct V_312 * ) ( V_131 -> V_110 ) ;
T_6 V_97 = V_131 -> V_97 ;
T_6 V_313 = F_151 ( V_4 ) ;
int V_314 ;
if ( ( V_111 == V_282 ) || ( V_111 == V_294 ) ||
( V_111 == V_315 ) )
V_313 |= V_316 ;
V_64 -> V_115 [ V_193 ] . V_98 |= V_313 ;
switch ( V_111 ) {
case V_282 :
V_314 = F_140 ( V_311 -> V_65 ) ;
F_153 ( V_4 -> V_304 . V_305 . V_306 , V_314 ) ;
break;
case V_292 :
V_314 = F_149 ( V_4 ) ;
break;
case V_294 :
V_314 = V_311 -> V_314 ;
break;
case V_315 :
V_314 = V_311 -> V_314 ;
F_153 ( V_4 -> V_304 . V_305 . V_306 , V_314 ) ;
break;
case V_317 :
V_314 = V_311 -> V_314 ;
F_150 ( V_4 -> V_304 . V_305 . V_306 , V_314 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return;
}
F_4 ( V_17 , L_66 ,
( ( V_313 & V_316 ) ?
L_67 : L_68 ) , V_314 ) ;
V_64 -> V_115 [ V_193 ] . V_318 = ( T_6 ) V_314 ;
V_64 -> V_115 [ V_193 ] . V_97 = V_97 ;
V_64 -> V_115 [ V_193 ] . V_319 = V_4 -> V_319 ;
}
static inline int F_154 (
struct V_1 * V_2 , struct V_266 * V_4 , int V_320 ,
int * V_321 )
{
int V_322 , V_20 = * V_321 ;
union V_310 V_311 = { NULL } ;
for ( V_322 = F_147 ( V_4 , V_320 ) ; V_322 >= 0 ;
V_322 = F_147 ( V_4 , V_322 + 1 ) ) {
V_311 . V_314 = ( T_6 ) V_322 ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_311 ,
V_294 ) ;
V_20 ++ ;
F_4 ( V_17 , L_69 , V_322 ) ;
if ( V_20 >= V_4 -> V_323 )
break;
}
* V_321 = V_20 ;
return V_322 ;
}
static inline void F_155 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_274 * V_324 ,
int * V_325 )
{
struct V_278 * V_326 , * V_327 ;
int V_20 = * V_325 ;
union V_310 V_311 = { NULL } ;
F_116 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_311 . V_65 = & V_326 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_311 , V_324 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_326 -> V_65 ) ;
F_16 ( & V_326 -> V_24 ) ;
if ( V_20 >= V_4 -> V_323 )
break;
}
* V_325 = V_20 ;
if ( F_14 ( & V_324 -> V_64 . V_285 ) )
V_324 -> V_287 = true ;
}
static inline void F_156 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_274 * V_324 ,
int * V_325 )
{
int V_20 = * V_325 ;
while ( V_324 -> V_64 . V_293 ) {
V_4 -> V_198 ( V_2 , V_4 , V_20 , NULL , V_324 -> type ) ;
V_20 ++ ;
V_324 -> V_64 . V_293 -- ;
F_4 ( V_17 , L_71 ,
V_324 -> V_64 . V_293 , V_20 ) ;
if ( V_20 >= V_4 -> V_323 )
break;
}
* V_325 = V_20 ;
if ( ! V_324 -> V_64 . V_293 )
V_324 -> V_287 = true ;
}
static inline void F_157 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_274 * V_324 ,
int * V_325 )
{
V_324 -> V_64 . V_295 = V_4 -> V_328 ( V_2 , V_4 , V_324 -> V_64 . V_295 ,
V_325 ) ;
if ( V_324 -> V_64 . V_295 < 0 )
V_324 -> V_287 = true ;
else
V_324 -> V_64 . V_295 ++ ;
}
static void
F_158 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_274 * V_324 )
{
T_12 V_329 [ V_303 ] , V_330 [ V_303 ] ;
struct V_278 * V_326 , * V_327 ;
struct V_331 * V_332 ;
struct V_269 * V_277 ;
int V_20 = 0 , V_333 = 0 , V_40 = 0 , V_299 ;
memset ( V_330 , 0 , sizeof( T_12 ) * V_303 ) ;
memcpy ( V_329 , V_4 -> V_304 . V_305 . V_306 ,
sizeof( T_12 ) * V_303 ) ;
F_116 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
int V_314 = F_140 ( V_326 -> V_65 ) ;
F_4 ( V_17 , L_72 ,
V_326 -> V_65 ) ;
F_153 ( V_330 , V_314 ) ;
F_16 ( & V_326 -> V_24 ) ;
V_333 ++ ;
}
V_324 -> V_334 = true ;
F_2 ( & V_324 -> V_64 . V_285 ) ;
V_277 = F_15 ( & V_324 -> V_286 ,
struct V_269 ,
V_271 ) ;
for ( V_299 = 0 ; V_299 < V_288 ; V_299 ++ ) {
bool V_335 = ! ! F_148 ( V_329 , V_299 ) ;
bool V_336 = ! ! F_148 ( V_330 , V_299 ) ;
if ( V_335 == V_336 )
continue;
V_332 = & V_277 -> V_291 [ V_40 ] . V_337 ;
V_332 -> V_314 = V_299 ;
V_332 -> type = V_336 ? V_315
: V_317 ;
F_12 ( & V_332 -> V_24 , & V_324 -> V_64 . V_285 ) ;
V_20 ++ ;
V_40 ++ ;
if ( V_40 == V_290 ) {
V_40 = 0 ;
V_277 = F_92 ( V_277 ,
V_271 ) ;
}
}
V_4 -> V_338 -= ( V_4 -> V_323 + V_333 ) ;
V_4 -> V_338 += V_20 ;
F_4 ( V_17 , L_73 , V_4 -> V_338 ) ;
}
static void
F_159 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_274 * V_324 ,
int * V_20 )
{
union V_310 V_311 = { NULL } ;
struct V_331 * V_332 , * V_339 ;
if ( ! V_324 -> V_334 )
F_158 ( V_2 , V_4 , V_324 ) ;
F_116 (p_item, p_item_n, &cmd_pos->data.macs_head,
link) {
V_311 . V_314 = ( T_6 ) V_332 -> V_314 ;
V_4 -> V_198 ( V_2 , V_4 , * V_20 , & V_311 , V_332 -> type ) ;
( * V_20 ) ++ ;
F_16 ( & V_332 -> V_24 ) ;
if ( * V_20 >= V_4 -> V_323 )
break;
}
if ( F_14 ( & V_324 -> V_64 . V_285 ) )
V_324 -> V_287 = true ;
}
static inline int F_160 ( struct V_1 * V_2 ,
struct V_272 * V_158 )
{
struct V_274 * V_324 , * V_340 ;
int V_20 = 0 ;
struct V_266 * V_4 = V_158 -> V_341 ;
F_116 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_324 -> type ) {
case V_282 :
F_155 ( V_2 , V_4 , V_324 , & V_20 ) ;
break;
case V_292 :
F_156 ( V_2 , V_4 , V_324 , & V_20 ) ;
break;
case V_294 :
F_157 ( V_2 , V_4 , V_324 ,
& V_20 ) ;
break;
case V_283 :
F_159 ( V_2 , V_4 , V_324 , & V_20 ) ;
break;
default:
F_38 ( L_65 , V_324 -> type ) ;
return - V_66 ;
}
if ( V_324 -> V_287 ) {
F_16 ( & V_324 -> V_24 ) ;
F_143 ( & V_324 -> V_286 ) ;
F_6 ( V_324 ) ;
}
if ( V_20 >= V_4 -> V_323 )
break;
}
return V_20 ;
}
static inline void F_161 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_272 * V_158 ,
int * V_325 )
{
struct V_276 * V_342 ;
union V_310 V_311 = { NULL } ;
int V_20 = * V_325 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_311 . V_65 = V_342 -> V_65 ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_311 , V_282 ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_342 -> V_65 ) ;
}
* V_325 = V_20 ;
}
static inline void F_162 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_272 * V_158 ,
int * V_325 )
{
int V_20 = * V_325 , V_299 ;
for ( V_299 = 0 ; V_299 < V_158 -> V_284 ; V_299 ++ ) {
V_4 -> V_198 ( V_2 , V_4 , V_20 , NULL , V_292 ) ;
V_20 ++ ;
F_4 ( V_17 , L_74 ,
V_158 -> V_284 - V_299 - 1 ) ;
}
* V_325 = V_20 ;
}
static inline int F_163 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 ,
int V_343 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
int V_20 = V_343 ;
F_4 ( V_17 , L_75 , V_158 -> V_284 ) ;
switch ( V_111 ) {
case V_282 :
F_161 ( V_2 , V_4 , V_158 , & V_20 ) ;
break;
case V_292 :
F_162 ( V_2 , V_4 , V_158 , & V_20 ) ;
break;
case V_294 :
V_4 -> V_328 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
V_158 -> V_284 = 0 ;
return V_20 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
int V_344 = V_4 -> V_345 ( V_4 ) ;
switch ( V_111 ) {
case V_292 :
V_4 -> V_346 ( V_4 , 0 ) ;
case V_294 :
V_158 -> V_284 = V_344 ;
break;
case V_282 :
case V_347 :
V_4 -> V_346 ( V_4 , V_344 + V_158 -> V_284 ) ;
break;
case V_283 :
V_4 -> V_346 ( V_4 , V_344 + V_158 -> V_284 ) ;
V_4 -> V_338 += V_4 -> V_323 ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
V_4 -> V_338 += V_158 -> V_284 ;
return 0 ;
}
static void F_165 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
int V_348 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
V_4 -> V_346 ( V_4 , V_348 ) ;
V_4 -> V_338 -= V_158 -> V_284 ;
if ( V_111 == V_283 )
V_4 -> V_338 -= V_4 -> V_323 ;
}
static inline void F_166 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
T_6 V_349 )
{
struct V_32 * V_131 = & V_158 -> V_341 -> V_38 ;
struct V_312 * V_64 =
(struct V_312 * ) ( V_131 -> V_110 ) ;
V_64 -> V_124 . V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_350 <<
V_106 ) ) ;
V_64 -> V_124 . V_103 = V_349 ;
}
static inline int F_167 ( struct V_1 * V_2 ,
struct V_266 * V_4 )
{
int V_299 , V_20 = 0 ;
T_12 V_19 ;
for ( V_299 = 0 ; V_299 < V_303 ; V_299 ++ ) {
V_19 = V_4 -> V_304 . V_305 . V_306 [ V_299 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_346 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_32 * V_38 = & V_158 -> V_341 -> V_38 ;
struct V_266 * V_4 = V_158 -> V_341 ;
struct V_312 * V_64 =
(struct V_312 * ) ( V_38 -> V_110 ) ;
int V_20 = 0 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_20 = F_160 ( V_2 , V_158 ) ;
if ( F_14 ( & V_4 -> V_296 ) )
V_4 -> V_351 ( V_4 ) ;
if ( V_158 -> V_284 > 0 )
V_20 = F_163 ( V_2 , V_158 , V_111 , V_20 ) ;
V_4 -> V_338 -= V_20 ;
F_19 ( V_4 -> V_338 < 0 ) ;
F_19 ( V_20 > V_4 -> V_323 ) ;
F_166 ( V_2 , V_158 , ( T_6 ) V_20 ) ;
if ( ! V_4 -> V_338 )
F_167 ( V_2 , V_4 ) ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) || ! V_20 ) {
V_38 -> V_182 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_111 ( V_2 , V_352 ,
V_38 -> V_101 , F_112 ( V_38 -> V_200 ) ,
F_113 ( V_38 -> V_200 ) ,
V_201 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_169 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
if ( V_111 == V_283 ) {
F_38 ( L_76 ) ;
return - V_66 ;
}
if ( ( V_111 == V_292 ) || ( V_111 == V_294 ) )
V_158 -> V_284 = 1 ;
return 0 ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
int V_348 ,
enum V_273 V_111 )
{
}
static inline void F_171 ( struct V_1 * V_2 ,
struct V_266 * V_4 ,
struct V_272 * V_158 ,
T_7 * V_353 )
{
struct V_276 * V_342 ;
int V_354 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_354 = F_140 ( V_342 -> V_65 ) ;
F_172 ( V_353 , V_354 ) ;
F_4 ( V_17 , L_77 ,
V_342 -> V_65 , V_354 ) ;
F_153 ( V_4 -> V_304 . V_305 . V_306 ,
V_354 ) ;
}
}
static inline void F_173 ( struct V_1 * V_2 ,
struct V_266 * V_4 , struct V_272 * V_158 ,
T_7 * V_353 )
{
int V_354 ;
for ( V_354 = F_147 ( V_4 , 0 ) ;
V_354 >= 0 ;
V_354 = F_147 ( V_4 , V_354 + 1 ) ) {
F_172 ( V_353 , V_354 ) ;
F_4 ( V_17 , L_78 , V_354 ) ;
}
}
static int F_174 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
int V_299 ;
struct V_266 * V_4 = V_158 -> V_341 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( ! F_18 ( V_28 , & V_158 -> V_25 ) ) {
T_7 V_353 [ V_355 ] = { 0 } ;
switch ( V_111 ) {
case V_282 :
F_171 ( V_2 , V_4 , V_158 , V_353 ) ;
break;
case V_292 :
F_4 ( V_17 ,
L_79 ) ;
memset ( V_4 -> V_304 . V_305 . V_306 , 0 ,
sizeof( V_4 -> V_304 . V_305 . V_306 ) ) ;
break;
case V_294 :
F_173 ( V_2 , V_4 , V_158 , V_353 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
for ( V_299 = 0 ; V_299 < V_355 ; V_299 ++ )
F_76 ( V_2 , F_175 ( V_2 , V_299 ) , V_353 [ V_299 ] ) ;
} else
memset ( V_4 -> V_304 . V_305 . V_306 , 0 ,
sizeof( V_4 -> V_304 . V_305 . V_306 ) ) ;
V_131 -> V_182 ( V_131 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
int V_344 = V_4 -> V_345 ( V_4 ) ;
if ( V_111 == V_283 ) {
F_38 ( L_80 ) ;
return - V_66 ;
}
switch ( V_111 ) {
case V_292 :
V_4 -> V_346 ( V_4 , 0 ) ;
case V_294 :
V_158 -> V_284 = V_344 ;
F_4 ( V_17 , L_81 ,
V_111 , V_158 -> V_284 ) ;
break;
case V_282 :
case V_347 :
if ( V_158 -> V_284 > V_4 -> V_323 ) {
F_38 ( L_82 ,
V_4 -> V_323 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_75 , V_158 -> V_284 ) ;
if ( V_158 -> V_284 > 0 )
V_4 -> V_346 ( V_4 , V_158 -> V_284 ) ;
break;
default:
F_38 ( L_65 , V_111 ) ;
return - V_66 ;
}
if ( V_158 -> V_284 )
V_4 -> V_338 += V_4 -> V_323 ;
return 0 ;
}
static void F_177 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
int V_356 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
V_4 -> V_346 ( V_4 , V_356 ) ;
if ( V_158 -> V_284 )
V_4 -> V_338 -= V_4 -> V_323 ;
}
static void F_178 ( struct V_1 * V_2 ,
struct V_266 * V_4 , int V_193 ,
union V_310 * V_311 ,
enum V_273 V_111 )
{
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_110 ) ;
if ( ( V_111 == V_282 ) || ( V_111 == V_294 ) ) {
F_81 ( & V_64 -> V_149 [ V_193 ] . V_143 ,
& V_64 -> V_149 [ V_193 ] . V_144 ,
& V_64 -> V_149 [ V_193 ] . V_145 ,
V_311 -> V_65 ) ;
V_64 -> V_149 [ V_193 ] . V_133 = 0 ;
V_64 -> V_149 [ V_193 ] . V_138 = V_131 -> V_97 ;
V_64 -> V_149 [ V_193 ] . V_137 =
F_79 ( 1 << V_131 -> V_96 ) ;
F_85 ( V_64 -> V_149 [ V_193 ] . V_139 ,
V_140 ,
V_141 ) ;
}
}
static inline void F_179 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
T_6 V_349 )
{
struct V_32 * V_131 = & V_158 -> V_341 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_131 -> V_110 ) ;
T_6 V_40 = ( F_180 ( V_2 ) ?
V_357 * ( 1 + V_131 -> V_97 ) :
V_358 * ( 1 + V_131 -> V_97 ) ) ;
V_64 -> V_94 . V_40 = V_40 ;
V_64 -> V_94 . V_95 = F_82 ( 0xff ) ;
V_64 -> V_94 . V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_350 <<
V_106 ) ) ;
V_64 -> V_94 . V_132 = V_349 ;
}
static inline int F_181 (
struct V_1 * V_2 , struct V_266 * V_4 , int V_359 ,
int * V_321 )
{
struct V_278 * V_19 ;
int V_299 = 0 ;
union V_310 V_311 = { NULL } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_311 . V_65 = & V_19 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_299 , & V_311 , V_294 ) ;
V_299 ++ ;
F_4 ( V_17 , L_70 ,
V_311 . V_65 ) ;
}
* V_321 = V_299 ;
return - 1 ;
}
static inline int F_182 (
struct V_1 * V_2 , struct V_272 * V_158 )
{
struct V_274 * V_324 ;
struct V_278 * V_326 ;
struct V_266 * V_4 = V_158 -> V_341 ;
union V_310 V_311 = { NULL } ;
int V_20 = 0 ;
if ( F_14 ( & V_4 -> V_296 ) )
return 0 ;
V_324 = F_15 ( & V_4 -> V_296 ,
struct V_274 , V_24 ) ;
switch ( V_324 -> type ) {
case V_282 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_311 . V_65 = & V_326 -> V_65 [ 0 ] ;
V_4 -> V_198 ( V_2 , V_4 , V_20 , & V_311 , V_324 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_70 ,
V_326 -> V_65 ) ;
}
break;
case V_292 :
V_20 = V_324 -> V_64 . V_293 ;
F_4 ( V_17 , L_83 , V_20 ) ;
break;
case V_294 :
V_4 -> V_328 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_38 ( L_65 , V_324 -> type ) ;
return - V_66 ;
}
F_16 ( & V_324 -> V_24 ) ;
F_143 ( & V_324 -> V_286 ) ;
F_6 ( V_324 ) ;
return V_20 ;
}
static inline void F_183 ( T_13 * V_360 , T_13 * V_361 ,
T_13 * V_362 , T_6 * V_65 )
{
V_65 [ 1 ] = ( ( T_6 * ) V_360 ) [ 0 ] ;
V_65 [ 0 ] = ( ( T_6 * ) V_360 ) [ 1 ] ;
V_65 [ 3 ] = ( ( T_6 * ) V_361 ) [ 0 ] ;
V_65 [ 2 ] = ( ( T_6 * ) V_361 ) [ 1 ] ;
V_65 [ 5 ] = ( ( T_6 * ) V_362 ) [ 0 ] ;
V_65 [ 4 ] = ( ( T_6 * ) V_362 ) [ 1 ] ;
}
static inline int F_184 ( struct V_1 * V_2 ,
struct V_266 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_278 * V_19 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
if ( F_185 ( V_64 -> V_149 [ 0 ] . V_139 ,
V_140 ) ) {
int V_299 , V_349 = V_64 -> V_94 . V_132 ;
if ( ! F_14 ( & V_4 -> V_304 . V_363 . V_364 ) )
return 0 ;
V_19 = F_186 ( V_349 , sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 ) {
F_38 ( L_84 ) ;
return - V_188 ;
}
for ( V_299 = 0 ; V_299 < V_349 ; V_299 ++ , V_19 ++ ) {
F_183 (
& V_64 -> V_149 [ V_299 ] . V_143 ,
& V_64 -> V_149 [ V_299 ] . V_144 ,
& V_64 -> V_149 [ V_299 ] . V_145 ,
V_19 -> V_65 ) ;
F_4 ( V_17 , L_85 ,
V_19 -> V_65 ) ;
F_12 ( & V_19 -> V_24 ,
& V_4 -> V_304 . V_363 . V_364 ) ;
}
} else {
V_19 = F_15 ( & V_4 -> V_304 . V_363 . V_364 ,
struct V_278 , V_24 ) ;
F_4 ( V_17 , L_86 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_304 . V_363 . V_364 ) ;
}
return 0 ;
}
static int F_187 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_147 * V_64 =
(struct V_147 * ) ( V_38 -> V_110 ) ;
int V_20 = 0 , V_299 , V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
for ( V_299 = 0 ; V_299 < V_4 -> V_323 ; V_299 ++ )
F_85 ( V_64 -> V_149 [ V_299 ] . V_139 ,
V_140 ,
V_146 ) ;
V_20 = F_182 ( V_2 , V_158 ) ;
if ( F_14 ( & V_4 -> V_296 ) )
V_4 -> V_351 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_163 ( V_2 , V_158 , V_111 , 0 ) ;
V_4 -> V_338 -= V_4 -> V_323 ;
F_19 ( V_20 > V_4 -> V_323 ) ;
F_179 ( V_2 , V_158 , ( T_6 ) V_20 ) ;
V_22 = F_184 ( V_2 , V_4 ) ;
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
static int F_188 ( struct V_266 * V_4 )
{
return V_4 -> V_304 . V_363 . V_365 ;
}
static int F_189 ( struct V_266 * V_4 )
{
return V_4 -> V_304 . V_305 . V_366 ;
}
static void F_190 ( struct V_266 * V_4 ,
int V_52 )
{
V_4 -> V_304 . V_363 . V_365 = V_52 ;
}
static void F_191 ( struct V_266 * V_4 ,
int V_52 )
{
V_4 -> V_304 . V_305 . V_366 = V_52 ;
}
int F_192 ( struct V_1 * V_2 ,
struct V_272 * V_158 ,
enum V_273 V_111 )
{
struct V_266 * V_4 = V_158 -> V_341 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
int V_22 = 0 , V_367 ;
V_367 = V_4 -> V_345 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_158 , V_111 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_158 -> V_284 ) && ( ! V_4 -> V_368 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_87 ,
V_4 -> V_338 , V_158 -> V_284 , V_4 -> V_323 ) ;
if ( V_131 -> V_195 ( V_131 ) ||
( ( V_4 -> V_323 > 0 ) && ( V_4 -> V_338 > V_4 -> V_323 ) ) ) {
V_22 = V_4 -> V_369 ( V_2 , V_158 -> V_341 , V_158 , V_111 ) ;
if ( V_22 < 0 )
goto V_370;
V_158 -> V_284 = 0 ;
}
if ( ! V_131 -> V_195 ( V_131 ) ) {
V_131 -> V_196 ( V_131 ) ;
V_22 = V_4 -> V_371 ( V_2 , V_158 , V_111 ) ;
if ( V_22 < 0 )
goto V_372;
if ( F_18 ( V_205 , & V_158 -> V_25 ) )
V_22 = V_4 -> V_179 ( V_2 , V_4 ) ;
}
return V_22 ;
V_372:
V_131 -> V_182 ( V_131 ) ;
V_370:
V_4 -> V_373 ( V_2 , V_158 , V_367 , V_111 ) ;
return V_22 ;
}
static void F_193 ( struct V_266 * V_4 )
{
F_28 () ;
F_29 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static void F_194 ( struct V_266 * V_4 )
{
F_28 () ;
F_32 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
F_30 () ;
}
static bool F_195 ( struct V_266 * V_4 )
{
return ! ! F_18 ( V_4 -> V_267 , V_4 -> V_38 . V_34 ) ;
}
static bool F_196 ( struct V_266 * V_4 )
{
return V_4 -> V_38 . V_195 ( & V_4 -> V_38 ) || V_4 -> V_368 ( V_4 ) ;
}
void F_197 ( struct V_1 * V_2 ,
struct V_266 * V_341 ,
T_6 V_374 , T_7 V_375 , T_6 V_97 ,
T_6 V_319 , void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 , T_10 type )
{
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
F_119 ( & V_341 -> V_38 , V_374 , V_375 , V_97 ,
V_110 , V_200 , V_33 , V_34 , type ) ;
V_341 -> V_319 = V_319 ;
F_2 ( & V_341 -> V_296 ) ;
V_341 -> V_267 = V_376 ;
V_341 -> V_368 = F_195 ;
V_341 -> V_297 = F_194 ;
V_341 -> V_351 = F_193 ;
if ( F_126 ( V_2 ) ) {
V_341 -> V_371 = F_187 ;
V_341 -> V_369 = F_145 ;
V_341 -> V_328 =
F_181 ;
V_341 -> V_195 = F_196 ;
if ( F_180 ( V_2 ) )
V_341 -> V_323 = V_357 ;
else
V_341 -> V_323 = V_358 ;
V_341 -> V_179 = F_142 ;
V_341 -> V_198 = F_178 ;
V_341 -> V_8 = F_176 ;
V_341 -> V_373 = F_177 ;
V_341 -> V_345 =
F_188 ;
V_341 -> V_346 =
F_190 ;
F_2 ( & V_341 -> V_304 . V_363 . V_364 ) ;
} else if ( F_127 ( V_2 ) ) {
V_341 -> V_371 = F_174 ;
V_341 -> V_369 = NULL ;
V_341 -> V_328 = NULL ;
V_341 -> V_195 = F_196 ;
V_341 -> V_323 = - 1 ;
V_341 -> V_179 = F_142 ;
V_341 -> V_198 = NULL ;
V_341 -> V_8 = F_169 ;
V_341 -> V_373 = F_170 ;
V_341 -> V_345 =
F_189 ;
V_341 -> V_346 =
F_191 ;
} else {
V_341 -> V_371 = F_168 ;
V_341 -> V_369 = F_145 ;
V_341 -> V_328 =
F_154 ;
V_341 -> V_195 = F_196 ;
V_341 -> V_323 = 16 ;
V_341 -> V_179 = F_142 ;
V_341 -> V_198 = F_152 ;
V_341 -> V_8 = F_164 ;
V_341 -> V_373 = F_165 ;
V_341 -> V_345 =
F_189 ;
V_341 -> V_346 =
F_191 ;
}
}
static inline bool F_198 ( T_14 * V_377 , int V_378 , int V_61 )
{
int V_379 , V_380 ;
V_379 = F_199 ( V_377 ) ;
for (; ; ) {
if ( F_200 ( V_379 + V_378 >= V_61 ) )
return false ;
V_380 = F_201 ( ( V_377 ) , V_379 , V_379 + V_378 ) ;
if ( F_202 ( V_380 == V_379 ) )
break;
V_379 = V_380 ;
}
return true ;
}
static inline bool F_203 ( T_14 * V_377 , int V_378 , int V_61 )
{
int V_379 , V_380 ;
V_379 = F_199 ( V_377 ) ;
for (; ; ) {
if ( F_200 ( V_379 - V_378 < V_61 ) )
return false ;
V_380 = F_201 ( ( V_377 ) , V_379 , V_379 - V_378 ) ;
if ( F_202 ( V_380 == V_379 ) )
break;
V_379 = V_380 ;
}
return true ;
}
static bool F_204 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_205 () ;
V_22 = F_203 ( & V_4 -> V_381 , V_20 , 0 ) ;
F_205 () ;
return V_22 ;
}
static bool F_206 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_205 () ;
V_22 = F_198 ( & V_4 -> V_381 , V_20 , V_4 -> V_382 + 1 ) ;
F_205 () ;
return V_22 ;
}
static int F_207 ( struct V_41 * V_4 )
{
int V_383 ;
F_205 () ;
V_383 = F_199 ( & V_4 -> V_381 ) ;
return V_383 ;
}
static bool F_208 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_209 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_193 , V_306 , V_299 ;
* V_40 = - 1 ;
for ( V_306 = 0 ; V_306 < V_384 ; V_306 ++ ) {
if ( ! V_4 -> V_385 [ V_306 ] )
continue;
for ( V_193 = V_306 * V_302 , V_299 = 0 ;
V_299 < V_302 ; V_193 ++ , V_299 ++ )
if ( F_148 ( V_4 -> V_385 , V_193 ) ) {
F_150 ( V_4 -> V_385 , V_193 ) ;
* V_40 = V_4 -> V_386 + V_193 ;
return true ;
}
}
return false ;
}
static bool F_210 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_386 )
return false ;
V_40 -= V_4 -> V_386 ;
if ( V_40 >= V_4 -> V_382 )
return false ;
F_153 ( V_4 -> V_385 , V_40 ) ;
return true ;
}
static bool F_211 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_212 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
void F_213 ( struct V_41 * V_158 ,
int V_53 , int V_381 )
{
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
memset ( & V_158 -> V_385 , 0xff , sizeof( V_158 -> V_385 ) ) ;
F_214 ( & V_158 -> V_381 , V_381 ) ;
V_158 -> V_382 = V_381 ;
V_158 -> V_386 = V_53 ;
F_205 () ;
V_158 -> V_387 = F_207 ;
if ( V_381 >= 0 ) {
V_158 -> V_47 = F_206 ;
V_158 -> V_11 = F_204 ;
V_158 -> V_48 = F_210 ;
V_158 -> V_44 = F_209 ;
} else {
V_158 -> V_47 = F_208 ;
V_158 -> V_11 = F_208 ;
V_158 -> V_48 = F_211 ;
V_158 -> V_44 = F_212 ;
}
if ( V_53 < 0 ) {
V_158 -> V_48 = F_211 ;
V_158 -> V_44 = F_212 ;
}
}
void F_215 ( struct V_1 * V_2 ,
struct V_41 * V_158 , T_6 V_97 ,
T_6 V_388 )
{
#define F_216 5
int V_389 ;
if ( F_126 ( V_2 ) ) {
if ( ! F_180 ( V_2 ) )
V_389 = ( V_390 / 2 ) - V_358 ;
else
V_389 = F_216 - V_357 ;
F_213 ( V_158 , V_97 * V_389 , V_389 ) ;
} else if ( F_127 ( V_2 ) ) {
if ( ( V_388 > 0 ) ) {
if ( ! F_180 ( V_2 ) )
V_389 = ( V_391 / ( 2 * V_388 ) ) ;
else
V_389 = F_216 ;
F_213 ( V_158 , V_97 * V_389 , V_389 ) ;
} else {
F_213 ( V_158 , 0 , 0 ) ;
}
} else {
if ( V_388 > 0 ) {
if ( ! F_180 ( V_2 ) )
V_389 = F_217 ( V_2 , V_388 ) ;
else
V_389 = F_216 ;
F_213 ( V_158 , - 1 , V_389 ) ;
} else {
F_213 ( V_158 , 0 , 0 ) ;
}
}
}
void F_218 ( struct V_1 * V_2 ,
struct V_41 * V_158 ,
T_6 V_97 ,
T_6 V_388 )
{
if ( F_122 ( V_2 ) ) {
F_213 ( V_158 , 0 , - 1 ) ;
} else {
if ( V_388 > 0 ) {
int V_381 = F_219 ( V_2 , V_388 ) ;
F_213 ( V_158 , - 1 , V_381 ) ;
} else
F_213 ( V_158 , 0 , 0 ) ;
}
}
static inline void F_220 ( struct V_1 * V_2 ,
struct V_392 * V_158 )
{
int V_299 ;
F_4 ( V_17 , L_88 ) ;
F_4 ( V_17 , L_89 ) ;
for ( V_299 = 0 ; V_299 < V_393 ; V_299 ++ ) {
F_221 ( V_17 , L_90 , V_158 -> V_394 [ V_299 ] ) ;
if ( ( V_299 + 1 < V_393 ) &&
( ( ( V_299 + 1 ) & 0x3 ) == 0 ) ) {
F_221 ( V_17 , L_91 ) ;
F_4 ( V_17 , L_92 , V_299 + 1 ) ;
}
}
F_221 ( V_17 , L_91 ) ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_392 * V_158 )
{
struct V_395 * V_4 = V_158 -> V_396 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_397 * V_64 =
(struct V_397 * ) ( V_131 -> V_110 ) ;
T_8 V_398 = 0 ;
T_6 V_399 = 0 ;
int V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_4 ( V_17 , L_93 ) ;
V_64 -> V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_131 -> V_33 << V_106 ) ) ;
if ( F_18 ( V_400 , & V_158 -> V_401 ) )
V_399 = V_402 ;
else if ( F_18 ( V_403 , & V_158 -> V_401 ) )
V_399 = V_404 ;
V_64 -> V_399 = V_399 ;
F_4 ( V_17 , L_94 , V_399 ) ;
if ( F_18 ( V_405 , & V_158 -> V_401 ) )
V_398 |= V_406 ;
if ( F_18 ( V_407 , & V_158 -> V_401 ) )
V_398 |= V_408 ;
if ( F_18 ( V_409 , & V_158 -> V_401 ) )
V_398 |= V_410 ;
if ( F_18 ( V_411 , & V_158 -> V_401 ) )
V_398 |= V_412 ;
if ( F_18 ( V_413 , & V_158 -> V_401 ) )
V_398 |= V_414 ;
if ( F_18 ( V_415 , & V_158 -> V_401 ) )
V_398 |= V_416 ;
if ( F_18 ( V_417 , & V_158 -> V_401 ) )
V_398 |= V_418 ;
if ( F_18 ( V_419 , & V_158 -> V_401 ) )
V_398 |= V_420 ;
if ( F_18 ( V_421 , & V_158 -> V_401 ) )
V_398 |= V_422 ;
if ( F_18 ( V_423 , & V_158 -> V_401 ) ) {
T_6 * V_424 = ( T_6 * ) ( V_64 -> V_425 ) + sizeof( V_64 -> V_425 ) ;
const T_6 * V_426 = ( const T_6 * ) V_158 -> V_425 ;
int V_299 ;
for ( V_299 = 0 ; V_299 < sizeof( V_64 -> V_425 ) ; V_299 ++ )
* -- V_424 = * V_426 ++ ;
V_398 |= V_427 ;
}
V_64 -> V_428 = F_82 ( V_398 ) ;
V_64 -> V_429 = V_158 -> V_429 ;
V_64 -> V_430 = V_4 -> V_319 ;
F_4 ( V_17 , L_95 , V_64 -> V_430 ) ;
memcpy ( V_64 -> V_431 , V_158 -> V_394 ,
V_393 ) ;
memcpy ( V_4 -> V_394 , V_158 -> V_394 , V_393 ) ;
if ( F_223 ( V_2 ) )
F_220 ( V_2 , V_158 ) ;
V_22 = F_111 ( V_2 , V_432 , V_131 -> V_101 ,
F_112 ( V_131 -> V_200 ) ,
F_113 ( V_131 -> V_200 ) ,
V_201 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_224 ( struct V_395 * V_396 ,
T_6 * V_394 )
{
memcpy ( V_394 , V_396 -> V_394 , sizeof( V_396 -> V_394 ) ) ;
}
int F_225 ( struct V_1 * V_2 ,
struct V_392 * V_158 )
{
int V_22 ;
struct V_395 * V_4 = V_158 -> V_396 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) ) {
F_4 ( V_17 , L_96 ,
V_158 -> V_25 ) ;
return 0 ;
}
V_131 -> V_196 ( V_131 ) ;
V_22 = V_4 -> V_433 ( V_2 , V_158 ) ;
if ( V_22 < 0 ) {
V_131 -> V_182 ( V_131 ) ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_158 -> V_25 ) )
V_22 = V_131 -> V_179 ( V_2 , V_131 ) ;
return V_22 ;
}
void F_226 ( struct V_1 * V_2 ,
struct V_395 * V_396 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , T_6 V_319 ,
void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 ,
T_10 type )
{
F_119 ( & V_396 -> V_38 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type ) ;
V_396 -> V_319 = V_319 ;
V_396 -> V_433 = F_222 ;
}
int F_227 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
int V_22 , V_438 ;
unsigned long * V_439 = & V_4 -> V_439 ;
V_22 = V_4 -> V_440 ( V_2 , V_4 , V_435 ) ;
if ( V_22 ) {
F_38 ( L_97 , V_22 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_98 , V_4 -> V_439 ) ;
V_438 = V_4 -> V_196 ( V_4 , V_435 ) ;
F_4 ( V_17 , L_99 , V_4 -> V_439 ) ;
if ( F_18 ( V_28 , & V_435 -> V_25 ) )
V_4 -> V_441 ( V_2 , V_4 , V_438 ) ;
else {
V_22 = V_4 -> V_442 ( V_2 , V_435 ) ;
if ( V_22 ) {
V_4 -> V_443 = V_444 ;
F_29 ( V_438 , V_439 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_435 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_438 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_438 , V_439 ) ;
}
static int F_228 ( struct V_436 * V_445 ,
struct V_434 * V_435 )
{
enum V_446 V_111 = V_435 -> V_111 , V_354 ;
if ( ( V_111 == V_447 ) ||
( V_111 == V_448 ) )
V_354 = V_449 ;
else
V_354 = V_111 ;
F_32 ( V_354 , & V_445 -> V_439 ) ;
return V_354 ;
}
static int F_229 ( struct V_1 * V_2 ,
struct V_436 * V_4 ,
enum V_446 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_439 ) ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_436 * V_4 ,
enum V_446 V_111 )
{
unsigned long V_450 = V_4 -> V_439 ;
if ( ! F_231 ( V_111 , & V_450 ) ) {
F_38 ( L_100 ,
V_111 , V_4 -> V_451 [ V_452 ] ,
V_4 -> V_33 , V_450 , V_4 -> V_443 ) ;
return - V_66 ;
}
if ( V_4 -> V_453 >= V_4 -> V_454 )
F_38 ( L_101 ,
V_4 -> V_453 , V_4 -> V_454 ) ;
F_4 ( V_17 ,
L_102 ,
V_111 , V_4 -> V_451 [ V_452 ] , V_4 -> V_443 ) ;
if ( V_4 -> V_453 )
F_4 ( V_17 , L_103 ,
V_4 -> V_451 [ V_452 ] , V_4 -> V_453 ) ;
V_4 -> V_33 = V_4 -> V_443 ;
V_4 -> V_455 = V_4 -> V_453 ;
V_4 -> V_443 = V_444 ;
F_232 () ;
F_29 ( V_111 , & V_4 -> V_439 ) ;
F_30 () ;
return 0 ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_434 * V_456 ,
struct V_457 * V_64 )
{
struct V_458 * V_435 = & V_456 -> V_435 . V_459 ;
V_64 -> V_460 . V_461 |= F_18 ( V_462 , & V_435 -> V_139 ) *
V_463 ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_436 * V_4 ,
struct V_464 * V_435 ,
struct V_465 * V_466 ,
unsigned long * V_139 )
{
V_466 -> V_95 = V_4 -> V_96 ;
if ( F_18 ( V_467 , V_139 ) ) {
V_466 -> V_468 =
V_435 -> V_469 ;
V_466 -> V_470 = 1 ;
V_466 -> V_471 =
F_18 ( V_472 , V_139 ) ;
} else
V_466 -> V_468 =
V_473 ;
V_466 -> V_474 = F_18 ( V_475 , V_139 ) ;
V_466 -> V_476 = F_18 ( V_477 , V_139 ) ;
V_466 -> V_478 = V_435 -> V_479 ;
V_466 -> V_480 = F_82 ( V_435 -> V_480 ) ;
V_466 -> V_97 = V_4 -> V_97 ;
V_466 -> cos = V_435 -> cos ;
V_466 -> V_481 =
F_18 ( V_475 , V_139 ) ?
V_482 : V_483 ;
V_466 -> V_484 = V_435 -> V_485 ;
F_4 ( V_17 , L_104 ,
V_466 -> V_476 , V_466 -> cos , V_466 -> V_470 ) ;
}
static void F_235 ( struct V_436 * V_4 ,
struct V_486 * V_435 ,
struct V_487 * V_488 ,
unsigned long * V_139 )
{
V_488 -> V_489 =
F_18 ( V_490 , V_139 ) ;
V_488 -> V_491 =
F_82 ( V_435 -> V_491 ) ;
V_488 -> V_492 =
F_18 ( V_493 , V_139 ) ;
V_488 -> V_494 =
F_18 ( V_495 , V_139 ) ;
V_488 -> V_496 =
F_18 ( V_497 , V_139 ) ;
V_488 -> V_498 =
F_18 ( V_499 , V_139 ) ;
V_488 -> V_500 =
F_18 ( V_501 , V_139 ) ;
V_488 -> V_502 =
F_18 ( V_503 , V_139 ) ;
V_488 -> V_504 =
F_18 ( V_505 , V_139 ) ? V_506 :
V_507 ;
V_488 -> V_508 = V_435 -> V_509 ;
V_488 -> V_510 = V_435 -> V_511 ;
V_488 -> V_512 = V_435 -> V_513 ;
V_488 -> V_514 . V_515 =
F_79 ( F_113 ( V_435 -> V_516 ) ) ;
V_488 -> V_514 . V_517 =
F_79 ( F_112 ( V_435 -> V_516 ) ) ;
V_488 -> V_33 = 0 ;
}
static void F_236 ( struct V_436 * V_4 ,
struct V_518 * V_435 ,
struct V_519 * V_520 )
{
V_520 -> V_521 = F_82 ( V_435 -> V_522 ) ;
V_520 -> V_523 = F_82 ( V_435 -> V_524 ) ;
V_520 -> V_525 = F_82 ( V_435 -> V_526 ) ;
V_520 -> V_527 = F_82 ( V_435 -> V_528 ) ;
V_520 -> V_529 = F_82 ( V_435 -> V_530 ) ;
V_520 -> V_531 = F_82 ( V_435 -> V_532 ) ;
V_520 -> V_533 = F_82 ( V_435 -> V_534 ) ;
}
static void F_237 ( struct V_436 * V_4 ,
struct V_535 * V_435 ,
struct V_519 * V_520 ,
unsigned long * V_139 )
{
V_520 -> V_461 = F_18 ( V_536 , V_139 ) *
V_537 ;
V_520 -> V_461 |= F_18 ( V_538 , V_139 ) *
V_539 ;
V_520 -> V_540 = 0 ;
V_520 -> V_541 =
V_435 -> V_542 ;
V_520 -> V_543 =
F_18 ( V_544 , V_139 ) ;
V_520 -> V_545 = V_435 -> V_546 ;
V_520 -> V_547 = V_435 -> V_548 ;
V_520 -> V_549 = F_82 ( V_435 -> V_550 ) ;
V_520 -> V_33 = F_82 ( V_551 |
V_552 ) ;
V_520 -> V_553 = 0 ;
V_520 -> V_554 = 0 ;
V_520 -> V_555 = 0 ;
V_520 -> V_556 = 0 ;
V_520 -> V_557 =
F_18 ( V_558 , V_139 ) ;
V_520 -> V_559 =
F_18 ( V_560 , V_139 ) ;
V_520 -> V_561 = V_435 -> V_509 ;
V_520 -> V_562 = V_435 -> V_511 ;
V_520 -> V_563 = V_435 -> V_563 ;
V_520 -> V_564 = F_82 ( V_435 -> V_565 ) ;
V_520 -> V_566 = F_82 ( V_435 -> V_567 ) ;
V_520 -> V_568 . V_515 =
F_79 ( F_113 ( V_435 -> V_516 ) ) ;
V_520 -> V_568 . V_517 =
F_79 ( F_112 ( V_435 -> V_516 ) ) ;
V_520 -> V_569 . V_515 =
F_79 ( F_113 ( V_435 -> V_570 ) ) ;
V_520 -> V_569 . V_517 =
F_79 ( F_112 ( V_435 -> V_570 ) ) ;
V_520 -> V_571 . V_515 =
F_79 ( F_113 ( V_435 -> V_572 ) ) ;
V_520 -> V_571 . V_517 =
F_79 ( F_112 ( V_435 -> V_572 ) ) ;
V_520 -> V_573 = F_18 ( V_574 , V_139 ) ;
if ( F_18 ( V_575 , V_139 ) ) {
V_520 -> V_576 = V_435 -> V_577 ;
V_520 -> V_578 = 1 ;
}
V_520 -> V_430 = V_435 -> V_430 ;
V_520 -> V_579 =
F_18 ( V_580 , V_139 ) ;
V_520 -> V_581 =
F_82 ( V_435 -> V_582 ) ;
V_520 -> V_583 =
F_82 ( V_435 -> V_584 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
struct V_434 * V_456 ,
struct V_457 * V_64 )
{
F_234 ( V_2 , V_456 -> V_437 ,
& V_456 -> V_435 . V_459 . V_585 ,
& V_64 -> V_586 ,
& V_456 -> V_435 . V_459 . V_139 ) ;
F_235 ( V_456 -> V_437 ,
& V_456 -> V_435 . V_459 . V_587 ,
& V_64 -> V_588 ,
& V_456 -> V_435 . V_459 . V_139 ) ;
F_237 ( V_456 -> V_437 ,
& V_456 -> V_435 . V_459 . V_589 ,
& V_64 -> V_460 ,
& V_456 -> V_435 . V_459 . V_139 ) ;
F_236 ( V_456 -> V_437 ,
& V_456 -> V_435 . V_459 . V_590 ,
& V_64 -> V_460 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_434 * V_456 ,
struct V_591 * V_64 )
{
F_234 ( V_2 , V_456 -> V_437 ,
& V_456 -> V_435 . V_592 . V_585 ,
& V_64 -> V_586 ,
& V_456 -> V_435 . V_592 . V_139 ) ;
F_235 ( V_456 -> V_437 ,
& V_456 -> V_435 . V_592 . V_587 ,
& V_64 -> V_588 ,
& V_456 -> V_435 . V_592 . V_139 ) ;
F_4 ( V_17 , L_105 ,
V_456 -> V_437 -> V_451 [ 0 ] ,
V_64 -> V_588 . V_514 . V_515 ,
V_64 -> V_588 . V_514 . V_517 ) ;
}
static inline int F_240 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_593 * V_594 = & V_435 -> V_435 . V_594 ;
T_8 V_595 ;
T_6 cos ;
if ( F_18 ( V_596 , & V_4 -> type ) &&
F_18 ( V_597 , & V_594 -> V_588 . V_139 ) ) {
V_595 = V_594 -> V_588 . V_598 ? 1000000 / V_594 -> V_588 . V_598 : 0 ;
F_241 ( V_2 , V_594 -> V_588 . V_509 ,
V_594 -> V_588 . V_511 ,
! F_18 ( V_599 , & V_594 -> V_588 . V_139 ) ,
V_595 ) ;
}
if ( F_18 ( V_600 , & V_4 -> type ) &&
F_18 ( V_597 , & V_594 -> V_460 . V_139 ) ) {
V_595 = V_594 -> V_460 . V_598 ? 1000000 / V_594 -> V_460 . V_598 : 0 ;
F_241 ( V_2 , V_594 -> V_460 . V_509 ,
V_594 -> V_460 . V_511 ,
! F_18 ( V_599 , & V_594 -> V_460 . V_139 ) ,
V_595 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_454 ; cos ++ ) {
F_4 ( V_17 , L_106 ,
V_4 -> V_451 [ cos ] , cos ) ;
F_4 ( V_17 , L_107 , V_594 -> V_601 [ cos ] ) ;
F_242 ( V_2 , V_594 -> V_601 [ cos ] , V_4 -> V_451 [ cos ] ) ;
}
V_4 -> V_441 ( V_2 , V_4 , V_602 ) ;
F_243 () ;
F_205 () ;
return 0 ;
}
static inline int F_244 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_457 * V_110 =
(struct V_457 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
int V_604 = V_605 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_238 ( V_2 , V_435 , V_110 ) ;
return F_111 ( V_2 , V_604 , V_4 -> V_451 [ V_452 ] ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_201 ) ;
}
static inline int F_245 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_457 * V_110 =
(struct V_457 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
int V_604 = V_605 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_238 ( V_2 , V_435 , V_110 ) ;
F_233 ( V_2 , V_435 , V_110 ) ;
return F_111 ( V_2 , V_604 , V_4 -> V_451 [ V_452 ] ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_201 ) ;
}
static inline int F_246 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_591 * V_110 =
(struct V_591 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
int V_604 = V_606 ;
struct V_607 * V_608 =
& V_435 -> V_435 . V_592 ;
T_6 V_609 = V_608 -> V_609 ;
if ( V_609 >= V_4 -> V_454 ) {
F_38 ( L_108 ,
V_4 -> V_96 , V_609 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_109 ,
V_608 -> V_585 . cos ,
V_608 -> V_585 . V_479 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_239 ( V_2 , V_435 , V_110 ) ;
F_4 ( V_17 , L_110 ,
V_4 -> V_451 [ V_609 ] , V_110 -> V_586 . V_95 ,
V_110 -> V_586 . V_478 , V_110 -> V_586 . cos ) ;
return F_111 ( V_2 , V_604 , V_4 -> V_451 [ V_609 ] ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_201 ) ;
}
static void F_247 ( struct V_1 * V_2 ,
struct V_436 * V_445 ,
struct V_610 * V_435 ,
struct V_611 * V_64 )
{
V_64 -> V_95 = V_445 -> V_96 ;
V_64 -> V_97 = V_445 -> V_97 ;
V_64 -> V_491 = F_82 ( V_435 -> V_612 ) ;
V_64 -> V_557 =
F_18 ( V_613 , & V_435 -> V_614 ) ;
V_64 -> V_615 =
F_18 ( V_616 ,
& V_435 -> V_614 ) ;
V_64 -> V_559 =
F_18 ( V_617 , & V_435 -> V_614 ) ;
V_64 -> V_618 =
F_18 ( V_619 ,
& V_435 -> V_614 ) ;
V_64 -> V_620 =
F_18 ( V_621 , & V_435 -> V_614 ) ;
V_64 -> V_622 =
F_18 ( V_623 , & V_435 -> V_614 ) ;
V_64 -> V_476 =
F_18 ( V_624 , & V_435 -> V_614 ) ;
V_64 -> V_625 =
F_18 ( V_626 , & V_435 -> V_614 ) ;
V_64 -> V_627 =
F_18 ( V_628 , & V_435 -> V_614 ) ;
V_64 -> V_629 =
F_18 ( V_630 ,
& V_435 -> V_614 ) ;
V_64 -> V_631 =
F_18 ( V_632 ,
& V_435 -> V_614 ) ;
V_64 -> V_579 =
F_18 ( V_633 , & V_435 -> V_614 ) ;
V_64 -> V_581 = F_82 ( V_435 -> V_582 ) ;
V_64 -> V_583 = F_82 ( V_435 -> V_584 ) ;
V_64 -> V_494 =
F_18 ( V_634 , & V_435 -> V_614 ) ;
V_64 -> V_635 =
F_18 ( V_636 ,
& V_435 -> V_614 ) ;
V_64 -> V_637 =
F_18 ( V_638 , & V_435 -> V_614 ) ;
V_64 -> V_639 =
F_18 ( V_640 , & V_435 -> V_614 ) ;
}
static inline int F_248 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_611 * V_110 =
(struct V_611 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_610 * V_641 =
& V_435 -> V_435 . V_642 ;
T_6 V_609 = V_641 -> V_609 ;
if ( V_609 >= V_4 -> V_454 ) {
F_38 ( L_108 ,
V_4 -> V_96 , V_609 ) ;
return - V_66 ;
}
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_247 ( V_2 , V_4 , V_641 , V_110 ) ;
return F_111 ( V_2 , V_643 ,
V_4 -> V_451 [ V_609 ] , F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_201 ) ;
}
static inline int F_249 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_610 * V_642 = & V_435 -> V_435 . V_642 ;
memset ( V_642 , 0 , sizeof( * V_642 ) ) ;
F_94 ( V_626 , & V_642 -> V_614 ) ;
return F_248 ( V_2 , V_435 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_610 * V_642 = & V_435 -> V_435 . V_642 ;
memset ( V_642 , 0 , sizeof( * V_642 ) ) ;
F_94 ( V_624 , & V_642 -> V_614 ) ;
F_94 ( V_626 , & V_642 -> V_614 ) ;
return F_248 ( V_2 , V_435 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_436 * V_445 ,
struct V_644 * V_435 ,
struct V_645 * V_64 )
{
V_64 -> V_95 = V_445 -> V_96 ;
V_64 -> V_646 = V_435 -> V_646 ;
V_64 -> V_647 =
V_435 -> V_648 ;
V_64 -> V_549 = F_82 ( V_435 -> V_649 ) ;
V_64 -> V_545 = V_435 -> V_546 ;
V_64 -> V_563 = V_435 -> V_563 ;
V_64 -> V_566 = F_82 ( V_435 -> V_650 ) ;
V_64 -> V_651 = F_79 ( F_112 ( V_435 -> V_570 ) ) ;
V_64 -> V_652 = F_79 ( F_113 ( V_435 -> V_570 ) ) ;
V_64 -> V_531 = F_82 ( V_435 -> V_531 ) ;
V_64 -> V_529 = F_82 ( V_435 -> V_529 ) ;
V_64 -> V_653 = V_435 -> V_653 ;
V_64 -> V_654 = V_435 -> V_654 ;
V_64 -> V_655 = V_435 -> V_655 ;
}
static inline int F_252 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
struct V_645 * V_110 =
(struct V_645 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_644 * V_656 =
& V_435 -> V_435 . V_657 ;
T_8 type ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_251 ( V_2 , V_4 , V_656 , V_110 ) ;
type = V_201 |
( ( V_4 -> V_97 ) << V_658 ) ;
return F_111 ( V_2 , V_659 ,
V_4 -> V_451 [ V_452 ] ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , type ) ;
}
static inline int F_253 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
return F_111 ( V_2 , V_660 ,
V_4 -> V_451 [ V_452 ] , 0 , V_4 -> V_96 ,
V_201 ) ;
}
static inline int F_254 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
T_6 V_661 = V_435 -> V_435 . V_662 . V_609 ;
if ( V_661 >= V_4 -> V_454 ) {
F_38 ( L_108 ,
V_4 -> V_96 , V_661 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_663 ,
V_4 -> V_451 [ V_661 ] , 0 , 0 , V_664 ) ;
}
static inline int F_255 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
T_6 V_609 = V_435 -> V_435 . V_665 . V_609 ;
if ( V_609 >= V_4 -> V_454 ) {
F_38 ( L_108 ,
V_4 -> V_96 , V_609 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_666 ,
V_4 -> V_451 [ V_609 ] , 0 , 0 , V_201 ) ;
}
static inline int F_256 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
struct V_436 * V_4 = V_435 -> V_437 ;
return F_111 ( V_2 , V_667 ,
V_4 -> V_451 [ V_452 ] , 0 , 0 ,
V_201 ) ;
}
static inline int F_257 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
switch ( V_435 -> V_111 ) {
case V_602 :
return F_240 ( V_2 , V_435 ) ;
case V_668 :
return F_246 ( V_2 , V_435 ) ;
case V_448 :
return F_249 ( V_2 , V_435 ) ;
case V_447 :
return F_250 ( V_2 , V_435 ) ;
case V_449 :
return F_248 ( V_2 , V_435 ) ;
case V_669 :
return F_252 ( V_2 , V_435 ) ;
case V_670 :
return F_253 ( V_2 , V_435 ) ;
case V_671 :
return F_254 ( V_2 , V_435 ) ;
case V_672 :
return F_255 ( V_2 , V_435 ) ;
case V_673 :
return F_256 ( V_2 , V_435 ) ;
default:
F_38 ( L_65 , V_435 -> V_111 ) ;
return - V_66 ;
}
}
static int F_258 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
switch ( V_435 -> V_111 ) {
case V_674 :
return F_244 ( V_2 , V_435 ) ;
case V_602 :
case V_668 :
case V_448 :
case V_447 :
case V_449 :
case V_669 :
case V_670 :
case V_671 :
case V_672 :
case V_673 :
return F_257 ( V_2 , V_435 ) ;
default:
F_38 ( L_65 , V_435 -> V_111 ) ;
return - V_66 ;
}
}
static int F_259 ( struct V_1 * V_2 ,
struct V_434 * V_435 )
{
switch ( V_435 -> V_111 ) {
case V_674 :
return F_245 ( V_2 , V_435 ) ;
case V_602 :
case V_668 :
case V_448 :
case V_447 :
case V_449 :
case V_669 :
case V_670 :
case V_671 :
case V_672 :
case V_673 :
return F_257 ( V_2 , V_435 ) ;
default:
F_38 ( L_65 , V_435 -> V_111 ) ;
return - V_66 ;
}
}
static int F_260 ( struct V_1 * V_2 ,
struct V_436 * V_4 ,
struct V_434 * V_435 )
{
enum V_675 V_33 = V_4 -> V_33 , V_443 = V_444 ;
enum V_446 V_111 = V_435 -> V_111 ;
struct V_610 * V_641 =
& V_435 -> V_435 . V_642 ;
T_6 V_453 = V_4 -> V_455 ;
if ( F_18 ( V_28 , & V_435 -> V_25 ) ) {
V_4 -> V_439 = 0 ;
V_4 -> V_443 = V_444 ;
}
if ( V_4 -> V_439 ) {
F_38 ( L_111 ,
V_4 -> V_439 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_676 :
if ( V_111 == V_602 )
V_443 = V_677 ;
break;
case V_677 :
if ( V_111 == V_674 ) {
if ( F_18 ( V_477 ,
& V_435 -> V_435 . V_459 . V_139 ) )
V_443 = V_678 ;
else
V_443 = V_679 ;
}
break;
case V_678 :
if ( V_111 == V_448 )
V_443 = V_679 ;
else if ( ( V_111 == V_673 ) ||
( V_111 == V_669 ) )
V_443 = V_678 ;
else if ( V_111 == V_668 ) {
V_443 = V_680 ;
V_453 = 1 ;
}
else if ( V_111 == V_670 )
V_443 = V_681 ;
else if ( V_111 == V_449 ) {
if ( F_18 ( V_626 ,
& V_641 -> V_614 ) &&
! F_18 ( V_624 ,
& V_641 -> V_614 ) )
V_443 = V_679 ;
else
V_443 = V_678 ;
}
break;
case V_680 :
if ( V_111 == V_672 )
V_443 = V_682 ;
else if ( V_111 == V_668 ) {
V_443 = V_680 ;
V_453 = V_4 -> V_455 + 1 ;
}
else if ( ( V_111 == V_673 ) ||
( V_111 == V_669 ) )
V_443 = V_680 ;
else if ( V_111 == V_449 ) {
if ( F_18 ( V_626 ,
& V_641 -> V_614 ) &&
! F_18 ( V_624 ,
& V_641 -> V_614 ) )
V_443 = V_679 ;
else
V_443 = V_680 ;
}
break;
case V_682 :
if ( V_111 == V_671 ) {
V_453 = V_4 -> V_455 - 1 ;
if ( V_453 == 0 )
V_443 = V_678 ;
else
V_443 = V_680 ;
}
break;
case V_679 :
if ( V_111 == V_447 )
V_443 = V_678 ;
else if ( ( V_111 == V_673 ) ||
( V_111 == V_669 ) )
V_443 = V_679 ;
else if ( V_111 == V_670 )
V_443 = V_681 ;
else if ( V_111 == V_449 ) {
if ( F_18 ( V_626 ,
& V_641 -> V_614 ) &&
F_18 ( V_624 ,
& V_641 -> V_614 ) ) {
if ( V_4 -> V_455 == 0 )
V_443 = V_678 ;
else
V_443 = V_680 ;
} else
V_443 = V_679 ;
}
break;
case V_681 :
if ( V_111 == V_672 )
V_443 = V_683 ;
break;
case V_683 :
if ( V_111 == V_671 )
V_443 = V_676 ;
break;
default:
F_38 ( L_112 , V_33 ) ;
}
if ( V_443 != V_444 ) {
F_4 ( V_17 , L_113 ,
V_33 , V_111 , V_443 ) ;
V_4 -> V_443 = V_443 ;
V_4 -> V_453 = V_453 ;
return 0 ;
}
F_4 ( V_17 , L_114 , V_33 , V_111 ) ;
return - V_66 ;
}
void F_261 ( struct V_1 * V_2 ,
struct V_436 * V_445 ,
T_6 V_96 , T_7 * V_451 , T_6 V_684 , T_6 V_97 ,
void * V_110 ,
T_9 V_200 , unsigned long type )
{
memset ( V_445 , 0 , sizeof( * V_445 ) ) ;
F_262 ( V_685 < V_684 ) ;
memcpy ( V_445 -> V_451 , V_451 , sizeof( V_445 -> V_451 [ 0 ] ) * V_684 ) ;
V_445 -> V_454 = V_684 ;
V_445 -> V_96 = V_96 ;
V_445 -> V_97 = V_97 ;
V_445 -> V_110 = V_110 ;
V_445 -> V_200 = V_200 ;
V_445 -> type = type ;
V_445 -> V_443 = V_444 ;
if ( F_122 ( V_2 ) )
V_445 -> V_442 = F_258 ;
else
V_445 -> V_442 = F_259 ;
V_445 -> V_440 = F_260 ;
V_445 -> V_441 = F_230 ;
V_445 -> V_179 = F_229 ;
V_445 -> V_196 = F_228 ;
}
int F_263 ( struct V_1 * V_2 ,
struct V_436 * V_445 )
{
switch ( V_445 -> V_33 ) {
case V_678 :
case V_680 :
return V_686 ;
case V_676 :
case V_677 :
case V_682 :
case V_679 :
case V_681 :
case V_683 :
case V_687 :
return V_688 ;
default:
return - V_66 ;
}
}
enum V_689 F_264 ( struct V_1 * V_2 ,
struct V_690 * V_4 )
{
if ( V_4 -> V_439 )
return V_691 ;
F_265 () ;
return V_4 -> V_33 ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_690 * V_4 ,
enum V_692 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_439 ) ;
}
static inline int F_267 ( struct V_1 * V_2 ,
struct V_690 * V_4 ,
enum V_692 V_111 )
{
unsigned long V_450 = V_4 -> V_439 ;
if ( ! F_231 ( V_111 , & V_450 ) ) {
F_38 ( L_115 ,
V_111 , F_268 ( V_2 ) , V_4 -> V_33 ,
V_450 , V_4 -> V_443 ) ;
return - V_66 ;
}
F_4 ( V_17 ,
L_116 ,
V_111 , F_268 ( V_2 ) , V_4 -> V_443 ) ;
V_4 -> V_33 = V_4 -> V_443 ;
V_4 -> V_443 = V_691 ;
F_232 () ;
F_29 ( V_111 , & V_4 -> V_439 ) ;
F_30 () ;
return 0 ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_690 * V_4 ,
enum V_692 V_111 )
{
int V_22 = F_267 ( V_2 , V_4 , V_111 ) ;
return V_22 ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_690 * V_4 ,
struct V_693 * V_435 )
{
enum V_689 V_33 = V_4 -> V_33 , V_443 = V_691 ;
enum V_692 V_111 = V_435 -> V_111 ;
if ( F_18 ( V_28 , & V_435 -> V_25 ) ) {
V_4 -> V_439 = 0 ;
V_4 -> V_443 = V_691 ;
}
if ( V_4 -> V_439 )
return - V_37 ;
switch ( V_33 ) {
case V_694 :
if ( V_111 == V_695 )
V_443 = V_696 ;
break;
case V_696 :
if ( V_111 == V_697 )
V_443 = V_698 ;
else if ( V_111 == V_699 )
V_443 = V_694 ;
break;
case V_698 :
if ( V_111 == V_700 )
V_443 = V_696 ;
else if ( ( V_111 == V_701 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_698 ;
else if ( ( V_111 == V_702 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_698 ;
else if ( ( V_111 == V_703 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_698 ;
else if ( ( V_111 == V_704 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_698 ;
else if ( V_111 == V_705 )
V_443 = V_706 ;
break;
case V_706 :
if ( ( V_111 == V_703 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_706 ;
else if ( ( V_111 == V_704 ) &&
( ! F_18 ( V_700 , & V_4 -> V_439 ) ) )
V_443 = V_706 ;
else if ( V_111 == V_707 )
V_443 = V_698 ;
break;
default:
F_38 ( L_117 , V_33 ) ;
}
if ( V_443 != V_691 ) {
F_4 ( V_17 , L_118 ,
V_33 , V_111 , V_443 ) ;
V_4 -> V_443 = V_443 ;
return 0 ;
}
F_4 ( V_17 , L_119 ,
V_33 , V_111 ) ;
return - V_66 ;
}
static inline int F_271 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
return V_709 -> V_710 ( V_2 ) ;
}
static inline int F_272 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
int V_22 = V_709 -> V_711 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_271 ( V_2 , V_709 ) ;
}
static inline int F_273 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
int V_22 = V_709 -> V_712 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_272 ( V_2 , V_709 ) ;
}
static inline int F_274 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
int V_22 = V_709 -> V_713 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_272 ( V_2 , V_709 ) ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
T_7 V_714 = V_435 -> V_435 . V_715 . V_716 ;
struct V_690 * V_4 = V_435 -> V_717 ;
const struct V_708 * V_709 = V_4 -> V_709 ;
int V_22 = 0 ;
F_4 ( V_17 , L_120 ,
F_276 ( V_2 ) , V_714 ) ;
V_22 = V_709 -> V_718 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_709 -> V_719 ( V_2 ) ;
if ( V_22 ) {
F_38 ( L_121 ) ;
goto V_720;
}
switch ( V_714 ) {
case V_721 :
V_22 = F_273 ( V_2 , V_709 ) ;
if ( V_22 )
goto V_720;
break;
case V_722 :
V_22 = F_274 ( V_2 , V_709 ) ;
if ( V_22 )
goto V_720;
break;
case V_723 :
V_22 = F_272 ( V_2 , V_709 ) ;
if ( V_22 )
goto V_720;
break;
case V_724 :
V_22 = F_271 ( V_2 , V_709 ) ;
if ( V_22 )
goto V_720;
break;
default:
F_38 ( L_122 , V_714 ) ;
V_22 = - V_66 ;
}
V_720:
V_709 -> V_725 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_441 ( V_2 , V_4 , V_695 ) ;
return V_22 ;
}
static inline void F_277 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
V_709 -> V_726 ( V_2 ) ;
}
static inline void F_278 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
V_709 -> V_727 ( V_2 ) ;
F_277 ( V_2 , V_709 ) ;
}
static inline void F_279 ( struct V_1 * V_2 ,
const struct V_708 * V_709 )
{
F_278 ( V_2 , V_709 ) ;
V_709 -> V_728 ( V_2 ) ;
}
static inline int F_280 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
T_7 V_729 = V_435 -> V_435 . V_730 . V_729 ;
struct V_690 * V_4 = V_435 -> V_717 ;
const struct V_708 * V_709 = V_4 -> V_709 ;
F_4 ( V_17 , L_123 , F_276 ( V_2 ) ,
V_729 ) ;
switch ( V_729 ) {
case V_731 :
F_279 ( V_2 , V_709 ) ;
break;
case V_732 :
F_278 ( V_2 , V_709 ) ;
break;
case V_733 :
F_277 ( V_2 , V_709 ) ;
break;
default:
F_38 ( L_124 ,
V_729 ) ;
break;
}
V_4 -> V_441 ( V_2 , V_4 , V_699 ) ;
return 0 ;
}
static inline int F_281 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_734 * V_110 =
(struct V_734 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_735 * V_736 = & V_435 -> V_435 . V_737 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_738 = ( T_6 ) V_736 -> V_739 ;
V_110 -> V_740 = F_82 ( V_736 -> V_740 ) ;
V_110 -> V_741 = F_282 ( V_2 ) ;
V_110 -> V_742 = V_736 -> V_742 ;
V_110 -> V_743 = F_82 ( V_736 -> V_743 ) ;
V_110 -> V_744 = F_82 ( V_736 -> V_744 ) ;
V_110 -> V_745 = V_736 -> V_745 ;
V_110 -> V_746 = V_736 -> V_746 ;
V_110 -> V_747 = V_736 -> V_747 ;
V_110 -> V_748 = V_736 -> V_748 ;
V_110 -> V_749 = V_736 -> V_750 ;
if ( V_736 -> V_751 ) {
V_110 -> V_752 = 1 ;
V_110 -> V_753 =
F_82 ( V_736 -> V_751 ) ;
}
V_110 -> V_754 = V_736 -> V_755 ;
V_110 -> V_756 = V_736 -> V_756 ;
if ( V_736 -> V_757 )
V_110 -> V_757 =
F_82 ( V_736 -> V_757 ) ;
else
V_110 -> V_757 =
F_82 ( 0x8100 ) ;
V_110 -> V_758 = V_736 -> V_758 ;
V_110 -> V_759 = V_736 -> V_760 ;
if ( V_110 -> V_759 ) {
memcpy ( V_110 -> V_761 . V_762 ,
V_736 -> V_763 ,
V_764 ) ;
V_110 -> V_765 = V_736 -> V_765 ;
}
return F_111 ( V_2 , V_766 , 0 ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_664 ) ;
}
static inline int F_283 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_767 * V_110 =
(struct V_767 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_768 * V_769 =
& V_435 -> V_435 . V_770 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
if ( F_18 ( V_771 ,
& V_769 -> V_772 ) ) {
V_110 -> V_773 = 1 ;
V_110 -> V_774 =
F_18 ( V_775 ,
& V_769 -> V_772 ) ;
}
if ( F_18 ( V_776 ,
& V_769 -> V_772 ) ) {
V_110 -> V_777 = 1 ;
V_110 -> V_740 =
F_82 ( V_769 -> V_69 ) ;
}
if ( F_18 ( V_778 ,
& V_769 -> V_772 ) ) {
V_110 -> V_779 = 1 ;
V_110 -> V_757 =
F_82 ( V_769 -> V_780 ) ;
}
if ( F_18 ( V_781 ,
& V_769 -> V_772 ) ) {
V_110 -> V_782 = 1 ;
if ( F_18 ( V_783 ,
& V_769 -> V_772 ) )
V_110 -> V_754 = 1 ;
V_110 -> V_754 =
V_769 -> V_784 ;
}
if ( F_18 ( V_785 ,
& V_769 -> V_772 ) ) {
V_110 -> V_786 = 1 ;
if ( F_18 ( V_787 ,
& V_769 -> V_772 ) )
V_110 -> V_745 = 1 ;
if ( F_18 ( V_788 ,
& V_769 -> V_772 ) )
V_110 -> V_747 = 1 ;
if ( F_18 ( V_789 ,
& V_769 -> V_772 ) )
V_110 -> V_746 = 1 ;
if ( F_18 ( V_790 ,
& V_769 -> V_772 ) )
V_110 -> V_748 = 1 ;
V_110 -> V_743 =
F_82 ( V_769 -> V_743 ) ;
V_110 -> V_744 =
F_82 ( V_769 -> V_744 ) ;
}
V_110 -> V_104 = V_791 ;
return F_111 ( V_2 , V_792 , 0 ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_664 ) ;
}
static inline int F_284 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_767 * V_110 =
(struct V_767 * ) V_4 -> V_793 ;
T_9 V_603 = V_4 -> V_794 ;
struct V_795 * V_796 =
& V_435 -> V_435 . V_797 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_798 = 1 ;
V_110 -> V_799 = F_82 ( V_796 -> V_799 ) ;
V_110 -> V_800 = 1 ;
V_110 -> V_801 =
F_82 ( V_796 -> V_801 ) ;
V_110 -> V_802 = 1 ;
V_110 -> V_803 = V_796 -> V_803 ;
V_110 -> V_104 = V_804 ;
F_4 ( V_17 ,
L_125 ,
V_110 -> V_799 ,
V_110 -> V_801 , V_110 -> V_803 ) ;
return F_111 ( V_2 , V_792 , 0 ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_664 ) ;
}
static
inline int F_285 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_805 * V_110 =
(struct V_805 * ) V_4 -> V_793 ;
struct V_806 * V_807 =
& V_435 -> V_435 . V_808 ;
T_12 * V_809 = ( T_12 * ) V_110 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_810 = F_82 ( V_807 -> V_810 ) ;
V_110 -> V_811 = V_807 -> V_811 ;
V_110 -> V_812 = V_807 -> V_812 ;
V_110 -> V_813 = V_807 -> V_813 ;
V_110 -> V_104 = V_807 -> V_812 ;
F_4 ( V_17 , L_126 ,
V_110 -> V_812 , V_110 -> V_810 ,
V_110 -> V_811 , V_110 -> V_813 ) ;
return F_111 ( V_2 , V_814 , 0 ,
F_112 ( * V_809 ) , F_113 ( * V_809 ) ,
V_664 ) ;
}
static inline int F_286 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
return F_111 ( V_2 , V_815 , 0 , 0 , 0 ,
V_664 ) ;
}
static inline int F_287 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
return F_111 ( V_2 , V_816 , 0 , 0 , 0 ,
V_664 ) ;
}
static inline int F_288 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_817 * V_110 =
(struct V_817 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_818 * V_819 =
& V_435 -> V_435 . V_820 ;
int V_299 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_821 = V_819 -> V_821 ;
V_110 -> V_822 = V_819 -> V_822 ;
V_110 -> V_823 = V_819 -> V_823 ;
for ( V_299 = 0 ; V_299 < F_289 ( V_110 -> V_824 ) ; V_299 ++ )
V_110 -> V_824 [ V_299 ] =
V_819 -> V_824 [ V_299 ] ;
for ( V_299 = 0 ; V_299 < V_825 ; V_299 ++ )
V_110 -> V_826 [ V_299 ] = V_819 -> V_826 [ V_299 ] ;
return F_111 ( V_2 , V_827 , 0 ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_664 ) ;
}
static inline
int F_290 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
struct V_828 * V_110 =
(struct V_828 * ) V_4 -> V_110 ;
T_9 V_603 = V_4 -> V_200 ;
struct V_829 * V_830 =
& V_435 -> V_435 . V_831 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_832 = V_830 -> V_832 ;
V_110 -> V_833 = V_830 -> V_833 ;
V_110 -> V_834 =
V_830 -> V_834 ;
V_110 -> V_835 = V_830 -> V_835 ;
V_110 -> V_836 = V_830 -> V_836 ;
V_110 -> V_837 . V_515 =
F_79 ( F_113 ( V_830 -> V_837 ) ) ;
V_110 -> V_837 . V_517 =
F_79 ( F_112 ( V_830 -> V_837 ) ) ;
F_4 ( V_17 , L_127 ,
V_110 -> V_832 , V_110 -> V_833 ,
V_110 -> V_834 , V_110 -> V_835 ,
V_110 -> V_836 , V_110 -> V_837 . V_515 ,
V_110 -> V_837 . V_517 ) ;
return F_111 ( V_2 , V_838 , 0 ,
F_112 ( V_603 ) ,
F_113 ( V_603 ) , V_664 ) ;
}
static int F_291 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
switch ( V_435 -> V_111 ) {
case V_695 :
return F_275 ( V_2 , V_435 ) ;
case V_697 :
return F_281 ( V_2 , V_435 ) ;
case V_700 :
return F_286 ( V_2 , V_435 ) ;
case V_699 :
return F_280 ( V_2 , V_435 ) ;
case V_701 :
return F_284 ( V_2 , V_435 ) ;
case V_702 :
return F_285 ( V_2 , V_435 ) ;
case V_705 :
return F_287 ( V_2 , V_435 ) ;
case V_707 :
return F_288 ( V_2 , V_435 ) ;
case V_703 :
return F_283 ( V_2 , V_435 ) ;
case V_704 :
return F_290 ( V_2 , V_435 ) ;
default:
F_38 ( L_65 , V_435 -> V_111 ) ;
return - V_66 ;
}
}
void F_292 ( struct V_1 * V_2 ,
struct V_690 * V_445 ,
void * V_110 , T_9 V_200 ,
void * V_793 , T_9 V_794 ,
struct V_708 * V_839 )
{
memset ( V_445 , 0 , sizeof( * V_445 ) ) ;
F_293 ( & V_445 -> V_840 ) ;
V_445 -> V_110 = V_110 ;
V_445 -> V_200 = V_200 ;
V_445 -> V_793 = V_793 ;
V_445 -> V_794 = V_794 ;
V_445 -> V_442 = F_291 ;
V_445 -> V_440 = F_270 ;
V_445 -> V_441 = F_269 ;
V_445 -> V_179 = F_266 ;
V_445 -> V_709 = V_839 ;
}
int F_294 ( struct V_1 * V_2 ,
struct V_693 * V_435 )
{
struct V_690 * V_4 = V_435 -> V_717 ;
int V_22 , V_20 = 300 ;
enum V_692 V_111 = V_435 -> V_111 ;
unsigned long * V_439 = & V_4 -> V_439 ;
F_295 ( & V_4 -> V_840 ) ;
V_22 = V_4 -> V_440 ( V_2 , V_4 , V_435 ) ;
if ( ( V_22 == - V_37 ) &&
( F_18 ( V_841 , & V_435 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_296 ( & V_4 -> V_840 ) ;
F_297 ( 10 ) ;
F_295 ( & V_4 -> V_840 ) ;
V_22 = V_4 -> V_440 ( V_2 , V_4 , V_435 ) ;
}
if ( V_22 == - V_37 ) {
F_296 ( & V_4 -> V_840 ) ;
F_38 ( L_128 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_296 ( & V_4 -> V_840 ) ;
return V_22 ;
}
F_32 ( V_111 , V_439 ) ;
if ( F_18 ( V_28 , & V_435 -> V_25 ) ) {
F_267 ( V_2 , V_4 , V_111 ) ;
F_296 ( & V_4 -> V_840 ) ;
} else {
V_22 = V_4 -> V_442 ( V_2 , V_435 ) ;
F_296 ( & V_4 -> V_840 ) ;
if ( V_22 ) {
V_4 -> V_443 = V_691 ;
F_29 ( V_111 , V_439 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_435 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_111 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_111 , V_439 ) ;
}
