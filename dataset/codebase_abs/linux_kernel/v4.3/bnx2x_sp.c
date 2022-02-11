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
void F_208 ( struct V_41 * V_158 ,
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
if ( V_365 > 0 ) {
if ( ! F_175 ( V_2 ) )
V_366 = F_212 ( V_2 , V_365 ) ;
else
V_366 = F_211 ;
F_208 ( V_158 , - 1 , V_366 ) ;
} else {
F_208 ( V_158 , 0 , 0 ) ;
}
}
}
void F_213 ( struct V_1 * V_2 ,
struct V_41 * V_158 ,
T_6 V_97 ,
T_6 V_365 )
{
if ( F_122 ( V_2 ) ) {
F_208 ( V_158 , 0 , - 1 ) ;
} else {
if ( V_365 > 0 ) {
int V_358 = F_214 ( V_2 , V_365 ) ;
F_208 ( V_158 , - 1 , V_358 ) ;
} else
F_208 ( V_158 , 0 , 0 ) ;
}
}
static inline void F_215 ( struct V_1 * V_2 ,
struct V_369 * V_158 )
{
int V_288 ;
F_4 ( V_17 , L_84 ) ;
F_4 ( V_17 , L_85 ) ;
for ( V_288 = 0 ; V_288 < V_370 ; V_288 ++ ) {
F_216 ( V_17 , L_86 , V_158 -> V_371 [ V_288 ] ) ;
if ( ( V_288 + 1 < V_370 ) &&
( ( ( V_288 + 1 ) & 0x3 ) == 0 ) ) {
F_216 ( V_17 , L_87 ) ;
F_4 ( V_17 , L_88 , V_288 + 1 ) ;
}
}
F_216 ( V_17 , L_87 ) ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_369 * V_158 )
{
struct V_372 * V_4 = V_158 -> V_373 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
struct V_374 * V_64 =
(struct V_374 * ) ( V_131 -> V_110 ) ;
T_8 V_375 = 0 ;
T_6 V_376 = 0 ;
int V_22 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_4 ( V_17 , L_89 ) ;
V_64 -> V_104 = F_79 ( ( V_131 -> V_101 & V_105 ) |
( V_131 -> V_33 << V_106 ) ) ;
if ( F_18 ( V_377 , & V_158 -> V_378 ) )
V_376 = V_379 ;
else if ( F_18 ( V_380 , & V_158 -> V_378 ) )
V_376 = V_381 ;
V_64 -> V_376 = V_376 ;
F_4 ( V_17 , L_90 , V_376 ) ;
if ( F_18 ( V_382 , & V_158 -> V_378 ) )
V_375 |= V_383 ;
if ( F_18 ( V_384 , & V_158 -> V_378 ) )
V_375 |= V_385 ;
if ( F_18 ( V_386 , & V_158 -> V_378 ) )
V_375 |= V_387 ;
if ( F_18 ( V_388 , & V_158 -> V_378 ) )
V_375 |= V_389 ;
if ( F_18 ( V_390 , & V_158 -> V_378 ) )
V_375 |= V_391 ;
if ( F_18 ( V_392 , & V_158 -> V_378 ) )
V_375 |= V_393 ;
if ( F_18 ( V_394 , & V_158 -> V_378 ) )
V_375 |= V_395 ;
if ( F_18 ( V_396 , & V_158 -> V_378 ) )
V_375 |= V_397 ;
if ( F_18 ( V_398 , & V_158 -> V_378 ) )
V_375 |= V_399 ;
if ( F_18 ( V_400 , & V_158 -> V_378 ) ) {
T_6 * V_401 = ( T_6 * ) ( V_64 -> V_402 ) + sizeof( V_64 -> V_402 ) ;
const T_6 * V_403 = ( const T_6 * ) V_158 -> V_402 ;
int V_288 ;
for ( V_288 = 0 ; V_288 < sizeof( V_64 -> V_402 ) ; V_288 ++ )
* -- V_401 = * V_403 ++ ;
V_375 |= V_404 ;
}
V_64 -> V_405 = F_82 ( V_375 ) ;
V_64 -> V_406 = V_158 -> V_406 ;
V_64 -> V_407 = V_4 -> V_306 ;
F_4 ( V_17 , L_91 , V_64 -> V_407 ) ;
memcpy ( V_64 -> V_408 , V_158 -> V_371 ,
V_370 ) ;
memcpy ( V_4 -> V_371 , V_158 -> V_371 , V_370 ) ;
if ( F_218 ( V_2 ) )
F_215 ( V_2 , V_158 ) ;
V_22 = F_111 ( V_2 , V_409 , V_131 -> V_101 ,
F_112 ( V_131 -> V_200 ) ,
F_113 ( V_131 -> V_200 ) ,
V_201 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_219 ( struct V_372 * V_373 ,
T_6 * V_371 )
{
memcpy ( V_371 , V_373 -> V_371 , sizeof( V_373 -> V_371 ) ) ;
}
int F_220 ( struct V_1 * V_2 ,
struct V_369 * V_158 )
{
int V_22 ;
struct V_372 * V_4 = V_158 -> V_373 ;
struct V_32 * V_131 = & V_4 -> V_38 ;
if ( F_18 ( V_28 , & V_158 -> V_25 ) ) {
F_4 ( V_17 , L_92 ,
V_158 -> V_25 ) ;
return 0 ;
}
V_131 -> V_196 ( V_131 ) ;
V_22 = V_4 -> V_410 ( V_2 , V_158 ) ;
if ( V_22 < 0 ) {
V_131 -> V_182 ( V_131 ) ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_158 -> V_25 ) )
V_22 = V_131 -> V_179 ( V_2 , V_131 ) ;
return V_22 ;
}
void F_221 ( struct V_1 * V_2 ,
struct V_372 * V_373 ,
T_6 V_96 , T_7 V_101 , T_6 V_97 , T_6 V_306 ,
void * V_110 , T_9 V_200 ,
int V_33 , unsigned long * V_34 ,
T_10 type )
{
F_119 ( & V_373 -> V_38 , V_96 , V_101 , V_97 , V_110 ,
V_200 , V_33 , V_34 , type ) ;
V_373 -> V_306 = V_306 ;
V_373 -> V_410 = F_217 ;
}
int F_222 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
int V_22 , V_415 ;
unsigned long * V_416 = & V_4 -> V_416 ;
V_22 = V_4 -> V_417 ( V_2 , V_4 , V_412 ) ;
if ( V_22 ) {
F_38 ( L_93 , V_22 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_94 , V_4 -> V_416 ) ;
V_415 = V_4 -> V_196 ( V_4 , V_412 ) ;
F_4 ( V_17 , L_95 , V_4 -> V_416 ) ;
if ( F_18 ( V_28 , & V_412 -> V_25 ) )
V_4 -> V_418 ( V_2 , V_4 , V_415 ) ;
else {
V_22 = V_4 -> V_419 ( V_2 , V_412 ) ;
if ( V_22 ) {
V_4 -> V_420 = V_421 ;
F_29 ( V_415 , V_416 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_412 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_415 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_415 , V_416 ) ;
}
static int F_223 ( struct V_413 * V_422 ,
struct V_411 * V_412 )
{
enum V_423 V_111 = V_412 -> V_111 , V_331 ;
if ( ( V_111 == V_424 ) ||
( V_111 == V_425 ) )
V_331 = V_426 ;
else
V_331 = V_111 ;
F_32 ( V_331 , & V_422 -> V_416 ) ;
return V_331 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_413 * V_4 ,
enum V_423 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_416 ) ;
}
static int F_225 ( struct V_1 * V_2 ,
struct V_413 * V_4 ,
enum V_423 V_111 )
{
unsigned long V_427 = V_4 -> V_416 ;
if ( ! F_226 ( V_111 , & V_427 ) ) {
F_38 ( L_96 ,
V_111 , V_4 -> V_428 [ V_429 ] ,
V_4 -> V_33 , V_427 , V_4 -> V_420 ) ;
return - V_66 ;
}
if ( V_4 -> V_430 >= V_4 -> V_431 )
F_38 ( L_97 ,
V_4 -> V_430 , V_4 -> V_431 ) ;
F_4 ( V_17 ,
L_98 ,
V_111 , V_4 -> V_428 [ V_429 ] , V_4 -> V_420 ) ;
if ( V_4 -> V_430 )
F_4 ( V_17 , L_99 ,
V_4 -> V_428 [ V_429 ] , V_4 -> V_430 ) ;
V_4 -> V_33 = V_4 -> V_420 ;
V_4 -> V_432 = V_4 -> V_430 ;
V_4 -> V_420 = V_421 ;
F_227 () ;
F_29 ( V_111 , & V_4 -> V_416 ) ;
F_30 () ;
return 0 ;
}
static void F_228 ( struct V_1 * V_2 ,
struct V_411 * V_433 ,
struct V_434 * V_64 )
{
struct V_435 * V_412 = & V_433 -> V_412 . V_436 ;
V_64 -> V_437 . V_438 |= F_18 ( V_439 , & V_412 -> V_139 ) *
V_440 ;
}
static void F_229 ( struct V_1 * V_2 ,
struct V_413 * V_4 ,
struct V_441 * V_412 ,
struct V_442 * V_443 ,
unsigned long * V_139 )
{
V_443 -> V_95 = V_4 -> V_96 ;
if ( F_18 ( V_444 , V_139 ) ) {
V_443 -> V_445 =
V_412 -> V_446 ;
V_443 -> V_447 = 1 ;
V_443 -> V_448 =
F_18 ( V_449 , V_139 ) ;
} else
V_443 -> V_445 =
V_450 ;
V_443 -> V_451 = F_18 ( V_452 , V_139 ) ;
V_443 -> V_453 = F_18 ( V_454 , V_139 ) ;
V_443 -> V_455 = V_412 -> V_456 ;
V_443 -> V_457 = F_82 ( V_412 -> V_457 ) ;
V_443 -> V_97 = V_4 -> V_97 ;
V_443 -> cos = V_412 -> cos ;
V_443 -> V_458 =
F_18 ( V_452 , V_139 ) ?
V_459 : V_460 ;
V_443 -> V_461 = V_412 -> V_462 ;
F_4 ( V_17 , L_100 ,
V_443 -> V_453 , V_443 -> cos , V_443 -> V_447 ) ;
}
static void F_230 ( struct V_413 * V_4 ,
struct V_463 * V_412 ,
struct V_464 * V_465 ,
unsigned long * V_139 )
{
V_465 -> V_466 =
F_18 ( V_467 , V_139 ) ;
V_465 -> V_468 =
F_82 ( V_412 -> V_468 ) ;
V_465 -> V_469 =
F_18 ( V_470 , V_139 ) ;
V_465 -> V_471 =
F_18 ( V_472 , V_139 ) ;
V_465 -> V_473 =
F_18 ( V_474 , V_139 ) ;
V_465 -> V_475 =
F_18 ( V_476 , V_139 ) ;
V_465 -> V_477 =
F_18 ( V_478 , V_139 ) ;
V_465 -> V_479 =
F_18 ( V_480 , V_139 ) ;
V_465 -> V_481 =
F_18 ( V_482 , V_139 ) ? V_483 :
V_484 ;
V_465 -> V_485 = V_412 -> V_486 ;
V_465 -> V_487 = V_412 -> V_488 ;
V_465 -> V_489 = V_412 -> V_490 ;
V_465 -> V_491 . V_492 =
F_79 ( F_113 ( V_412 -> V_493 ) ) ;
V_465 -> V_491 . V_494 =
F_79 ( F_112 ( V_412 -> V_493 ) ) ;
V_465 -> V_33 = 0 ;
}
static void F_231 ( struct V_413 * V_4 ,
struct V_495 * V_412 ,
struct V_496 * V_497 )
{
V_497 -> V_498 = F_82 ( V_412 -> V_499 ) ;
V_497 -> V_500 = F_82 ( V_412 -> V_501 ) ;
V_497 -> V_502 = F_82 ( V_412 -> V_503 ) ;
V_497 -> V_504 = F_82 ( V_412 -> V_505 ) ;
V_497 -> V_506 = F_82 ( V_412 -> V_507 ) ;
V_497 -> V_508 = F_82 ( V_412 -> V_509 ) ;
V_497 -> V_510 = F_82 ( V_412 -> V_511 ) ;
}
static void F_232 ( struct V_413 * V_4 ,
struct V_512 * V_412 ,
struct V_496 * V_497 ,
unsigned long * V_139 )
{
V_497 -> V_438 = F_18 ( V_513 , V_139 ) *
V_514 ;
V_497 -> V_438 |= F_18 ( V_515 , V_139 ) *
V_516 ;
V_497 -> V_517 = 0 ;
V_497 -> V_518 =
V_412 -> V_519 ;
V_497 -> V_520 =
F_18 ( V_521 , V_139 ) ;
V_497 -> V_522 = V_412 -> V_523 ;
V_497 -> V_524 = V_412 -> V_525 ;
V_497 -> V_526 = F_82 ( V_412 -> V_527 ) ;
V_497 -> V_33 = F_82 ( V_528 |
V_529 ) ;
V_497 -> V_530 = 0 ;
V_497 -> V_531 = 0 ;
V_497 -> V_532 = 0 ;
V_497 -> V_533 = 0 ;
V_497 -> V_534 =
F_18 ( V_535 , V_139 ) ;
V_497 -> V_536 =
F_18 ( V_537 , V_139 ) ;
V_497 -> V_538 = V_412 -> V_486 ;
V_497 -> V_539 = V_412 -> V_488 ;
V_497 -> V_540 = V_412 -> V_540 ;
V_497 -> V_541 = F_82 ( V_412 -> V_542 ) ;
V_497 -> V_543 = F_82 ( V_412 -> V_544 ) ;
V_497 -> V_545 . V_492 =
F_79 ( F_113 ( V_412 -> V_493 ) ) ;
V_497 -> V_545 . V_494 =
F_79 ( F_112 ( V_412 -> V_493 ) ) ;
V_497 -> V_546 . V_492 =
F_79 ( F_113 ( V_412 -> V_547 ) ) ;
V_497 -> V_546 . V_494 =
F_79 ( F_112 ( V_412 -> V_547 ) ) ;
V_497 -> V_548 . V_492 =
F_79 ( F_113 ( V_412 -> V_549 ) ) ;
V_497 -> V_548 . V_494 =
F_79 ( F_112 ( V_412 -> V_549 ) ) ;
V_497 -> V_550 = F_18 ( V_551 , V_139 ) ;
if ( F_18 ( V_552 , V_139 ) ) {
V_497 -> V_553 = V_412 -> V_554 ;
V_497 -> V_555 = 1 ;
}
V_497 -> V_407 = V_412 -> V_407 ;
V_497 -> V_556 =
F_18 ( V_557 , V_139 ) ;
V_497 -> V_558 =
F_82 ( V_412 -> V_559 ) ;
V_497 -> V_560 =
F_82 ( V_412 -> V_561 ) ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_411 * V_433 ,
struct V_434 * V_64 )
{
F_229 ( V_2 , V_433 -> V_414 ,
& V_433 -> V_412 . V_436 . V_562 ,
& V_64 -> V_563 ,
& V_433 -> V_412 . V_436 . V_139 ) ;
F_230 ( V_433 -> V_414 ,
& V_433 -> V_412 . V_436 . V_564 ,
& V_64 -> V_565 ,
& V_433 -> V_412 . V_436 . V_139 ) ;
F_232 ( V_433 -> V_414 ,
& V_433 -> V_412 . V_436 . V_566 ,
& V_64 -> V_437 ,
& V_433 -> V_412 . V_436 . V_139 ) ;
F_231 ( V_433 -> V_414 ,
& V_433 -> V_412 . V_436 . V_567 ,
& V_64 -> V_437 ) ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_411 * V_433 ,
struct V_568 * V_64 )
{
F_229 ( V_2 , V_433 -> V_414 ,
& V_433 -> V_412 . V_569 . V_562 ,
& V_64 -> V_563 ,
& V_433 -> V_412 . V_569 . V_139 ) ;
F_230 ( V_433 -> V_414 ,
& V_433 -> V_412 . V_569 . V_564 ,
& V_64 -> V_565 ,
& V_433 -> V_412 . V_569 . V_139 ) ;
F_4 ( V_17 , L_101 ,
V_433 -> V_414 -> V_428 [ 0 ] ,
V_64 -> V_565 . V_491 . V_492 ,
V_64 -> V_565 . V_491 . V_494 ) ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_570 * V_571 = & V_412 -> V_412 . V_571 ;
T_8 V_572 ;
T_6 cos ;
if ( F_18 ( V_573 , & V_4 -> type ) &&
F_18 ( V_574 , & V_571 -> V_565 . V_139 ) ) {
V_572 = V_571 -> V_565 . V_575 ? 1000000 / V_571 -> V_565 . V_575 : 0 ;
F_236 ( V_2 , V_571 -> V_565 . V_486 ,
V_571 -> V_565 . V_488 ,
! F_18 ( V_576 , & V_571 -> V_565 . V_139 ) ,
V_572 ) ;
}
if ( F_18 ( V_577 , & V_4 -> type ) &&
F_18 ( V_574 , & V_571 -> V_437 . V_139 ) ) {
V_572 = V_571 -> V_437 . V_575 ? 1000000 / V_571 -> V_437 . V_575 : 0 ;
F_236 ( V_2 , V_571 -> V_437 . V_486 ,
V_571 -> V_437 . V_488 ,
! F_18 ( V_576 , & V_571 -> V_437 . V_139 ) ,
V_572 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_431 ; cos ++ ) {
F_4 ( V_17 , L_102 ,
V_4 -> V_428 [ cos ] , cos ) ;
F_4 ( V_17 , L_103 , V_571 -> V_578 [ cos ] ) ;
F_237 ( V_2 , V_571 -> V_578 [ cos ] , V_4 -> V_428 [ cos ] ) ;
}
V_4 -> V_418 ( V_2 , V_4 , V_579 ) ;
F_238 () ;
F_200 () ;
return 0 ;
}
static inline int F_239 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_434 * V_110 =
(struct V_434 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
int V_581 = V_582 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_233 ( V_2 , V_412 , V_110 ) ;
return F_111 ( V_2 , V_581 , V_4 -> V_428 [ V_429 ] ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_201 ) ;
}
static inline int F_240 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_434 * V_110 =
(struct V_434 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
int V_581 = V_582 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_233 ( V_2 , V_412 , V_110 ) ;
F_228 ( V_2 , V_412 , V_110 ) ;
return F_111 ( V_2 , V_581 , V_4 -> V_428 [ V_429 ] ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_201 ) ;
}
static inline int F_241 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_568 * V_110 =
(struct V_568 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
int V_581 = V_583 ;
struct V_584 * V_585 =
& V_412 -> V_412 . V_569 ;
T_6 V_586 = V_585 -> V_586 ;
if ( V_586 >= V_4 -> V_431 ) {
F_38 ( L_104 ,
V_4 -> V_96 , V_586 ) ;
return - V_66 ;
}
F_4 ( V_17 , L_105 ,
V_585 -> V_562 . cos ,
V_585 -> V_562 . V_456 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_234 ( V_2 , V_412 , V_110 ) ;
F_4 ( V_17 , L_106 ,
V_4 -> V_428 [ V_586 ] , V_110 -> V_563 . V_95 ,
V_110 -> V_563 . V_455 , V_110 -> V_563 . cos ) ;
return F_111 ( V_2 , V_581 , V_4 -> V_428 [ V_586 ] ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_201 ) ;
}
static void F_242 ( struct V_1 * V_2 ,
struct V_413 * V_422 ,
struct V_587 * V_412 ,
struct V_588 * V_64 )
{
V_64 -> V_95 = V_422 -> V_96 ;
V_64 -> V_97 = V_422 -> V_97 ;
V_64 -> V_468 = F_82 ( V_412 -> V_589 ) ;
V_64 -> V_534 =
F_18 ( V_590 , & V_412 -> V_591 ) ;
V_64 -> V_592 =
F_18 ( V_593 ,
& V_412 -> V_591 ) ;
V_64 -> V_536 =
F_18 ( V_594 , & V_412 -> V_591 ) ;
V_64 -> V_595 =
F_18 ( V_596 ,
& V_412 -> V_591 ) ;
V_64 -> V_597 =
F_18 ( V_598 , & V_412 -> V_591 ) ;
V_64 -> V_599 =
F_18 ( V_600 , & V_412 -> V_591 ) ;
V_64 -> V_453 =
F_18 ( V_601 , & V_412 -> V_591 ) ;
V_64 -> V_602 =
F_18 ( V_603 , & V_412 -> V_591 ) ;
V_64 -> V_604 =
F_18 ( V_605 , & V_412 -> V_591 ) ;
V_64 -> V_606 =
F_18 ( V_607 ,
& V_412 -> V_591 ) ;
V_64 -> V_608 =
F_18 ( V_609 ,
& V_412 -> V_591 ) ;
V_64 -> V_556 =
F_18 ( V_610 , & V_412 -> V_591 ) ;
V_64 -> V_558 = F_82 ( V_412 -> V_559 ) ;
V_64 -> V_560 = F_82 ( V_412 -> V_561 ) ;
V_64 -> V_471 =
F_18 ( V_611 , & V_412 -> V_591 ) ;
V_64 -> V_612 =
F_18 ( V_613 ,
& V_412 -> V_591 ) ;
V_64 -> V_614 =
F_18 ( V_615 , & V_412 -> V_591 ) ;
V_64 -> V_616 =
F_18 ( V_617 , & V_412 -> V_591 ) ;
}
static inline int F_243 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_588 * V_110 =
(struct V_588 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_587 * V_618 =
& V_412 -> V_412 . V_619 ;
T_6 V_586 = V_618 -> V_586 ;
if ( V_586 >= V_4 -> V_431 ) {
F_38 ( L_104 ,
V_4 -> V_96 , V_586 ) ;
return - V_66 ;
}
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_242 ( V_2 , V_4 , V_618 , V_110 ) ;
return F_111 ( V_2 , V_620 ,
V_4 -> V_428 [ V_586 ] , F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_201 ) ;
}
static inline int F_244 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_587 * V_619 = & V_412 -> V_412 . V_619 ;
memset ( V_619 , 0 , sizeof( * V_619 ) ) ;
F_94 ( V_603 , & V_619 -> V_591 ) ;
return F_243 ( V_2 , V_412 ) ;
}
static inline int F_245 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_587 * V_619 = & V_412 -> V_412 . V_619 ;
memset ( V_619 , 0 , sizeof( * V_619 ) ) ;
F_94 ( V_601 , & V_619 -> V_591 ) ;
F_94 ( V_603 , & V_619 -> V_591 ) ;
return F_243 ( V_2 , V_412 ) ;
}
static void F_246 ( struct V_1 * V_2 ,
struct V_413 * V_422 ,
struct V_621 * V_412 ,
struct V_622 * V_64 )
{
V_64 -> V_95 = V_422 -> V_96 ;
V_64 -> V_623 = V_412 -> V_623 ;
V_64 -> V_624 =
V_412 -> V_625 ;
V_64 -> V_526 = F_82 ( V_412 -> V_626 ) ;
V_64 -> V_522 = V_412 -> V_523 ;
V_64 -> V_540 = V_412 -> V_540 ;
V_64 -> V_543 = F_82 ( V_412 -> V_627 ) ;
V_64 -> V_628 = F_79 ( F_112 ( V_412 -> V_547 ) ) ;
V_64 -> V_629 = F_79 ( F_113 ( V_412 -> V_547 ) ) ;
V_64 -> V_508 = F_82 ( V_412 -> V_508 ) ;
V_64 -> V_506 = F_82 ( V_412 -> V_506 ) ;
V_64 -> V_630 = V_412 -> V_630 ;
V_64 -> V_631 = V_412 -> V_631 ;
V_64 -> V_632 = V_412 -> V_632 ;
}
static inline int F_247 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
struct V_622 * V_110 =
(struct V_622 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_621 * V_633 =
& V_412 -> V_412 . V_634 ;
T_8 type ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_246 ( V_2 , V_4 , V_633 , V_110 ) ;
type = V_201 |
( ( V_4 -> V_97 ) << V_635 ) ;
return F_111 ( V_2 , V_636 ,
V_4 -> V_428 [ V_429 ] ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , type ) ;
}
static inline int F_248 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
return F_111 ( V_2 , V_637 ,
V_4 -> V_428 [ V_429 ] , 0 , V_4 -> V_96 ,
V_201 ) ;
}
static inline int F_249 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
T_6 V_638 = V_412 -> V_412 . V_639 . V_586 ;
if ( V_638 >= V_4 -> V_431 ) {
F_38 ( L_104 ,
V_4 -> V_96 , V_638 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_640 ,
V_4 -> V_428 [ V_638 ] , 0 , 0 , V_641 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
T_6 V_586 = V_412 -> V_412 . V_642 . V_586 ;
if ( V_586 >= V_4 -> V_431 ) {
F_38 ( L_104 ,
V_4 -> V_96 , V_586 ) ;
return - V_66 ;
}
return F_111 ( V_2 , V_643 ,
V_4 -> V_428 [ V_586 ] , 0 , 0 , V_201 ) ;
}
static inline int F_251 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
struct V_413 * V_4 = V_412 -> V_414 ;
return F_111 ( V_2 , V_644 ,
V_4 -> V_428 [ V_429 ] , 0 , 0 ,
V_201 ) ;
}
static inline int F_252 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
switch ( V_412 -> V_111 ) {
case V_579 :
return F_235 ( V_2 , V_412 ) ;
case V_645 :
return F_241 ( V_2 , V_412 ) ;
case V_425 :
return F_244 ( V_2 , V_412 ) ;
case V_424 :
return F_245 ( V_2 , V_412 ) ;
case V_426 :
return F_243 ( V_2 , V_412 ) ;
case V_646 :
return F_247 ( V_2 , V_412 ) ;
case V_647 :
return F_248 ( V_2 , V_412 ) ;
case V_648 :
return F_249 ( V_2 , V_412 ) ;
case V_649 :
return F_250 ( V_2 , V_412 ) ;
case V_650 :
return F_251 ( V_2 , V_412 ) ;
default:
F_38 ( L_65 , V_412 -> V_111 ) ;
return - V_66 ;
}
}
static int F_253 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
switch ( V_412 -> V_111 ) {
case V_651 :
return F_239 ( V_2 , V_412 ) ;
case V_579 :
case V_645 :
case V_425 :
case V_424 :
case V_426 :
case V_646 :
case V_647 :
case V_648 :
case V_649 :
case V_650 :
return F_252 ( V_2 , V_412 ) ;
default:
F_38 ( L_65 , V_412 -> V_111 ) ;
return - V_66 ;
}
}
static int F_254 ( struct V_1 * V_2 ,
struct V_411 * V_412 )
{
switch ( V_412 -> V_111 ) {
case V_651 :
return F_240 ( V_2 , V_412 ) ;
case V_579 :
case V_645 :
case V_425 :
case V_424 :
case V_426 :
case V_646 :
case V_647 :
case V_648 :
case V_649 :
case V_650 :
return F_252 ( V_2 , V_412 ) ;
default:
F_38 ( L_65 , V_412 -> V_111 ) ;
return - V_66 ;
}
}
static int F_255 ( struct V_1 * V_2 ,
struct V_413 * V_4 ,
struct V_411 * V_412 )
{
enum V_652 V_33 = V_4 -> V_33 , V_420 = V_421 ;
enum V_423 V_111 = V_412 -> V_111 ;
struct V_587 * V_618 =
& V_412 -> V_412 . V_619 ;
T_6 V_430 = V_4 -> V_432 ;
if ( F_18 ( V_28 , & V_412 -> V_25 ) ) {
V_4 -> V_416 = 0 ;
V_4 -> V_420 = V_421 ;
}
if ( V_4 -> V_416 ) {
F_38 ( L_107 ,
V_4 -> V_416 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_653 :
if ( V_111 == V_579 )
V_420 = V_654 ;
break;
case V_654 :
if ( V_111 == V_651 ) {
if ( F_18 ( V_454 ,
& V_412 -> V_412 . V_436 . V_139 ) )
V_420 = V_655 ;
else
V_420 = V_656 ;
}
break;
case V_655 :
if ( V_111 == V_425 )
V_420 = V_656 ;
else if ( ( V_111 == V_650 ) ||
( V_111 == V_646 ) )
V_420 = V_655 ;
else if ( V_111 == V_645 ) {
V_420 = V_657 ;
V_430 = 1 ;
}
else if ( V_111 == V_647 )
V_420 = V_658 ;
else if ( V_111 == V_426 ) {
if ( F_18 ( V_603 ,
& V_618 -> V_591 ) &&
! F_18 ( V_601 ,
& V_618 -> V_591 ) )
V_420 = V_656 ;
else
V_420 = V_655 ;
}
break;
case V_657 :
if ( V_111 == V_649 )
V_420 = V_659 ;
else if ( V_111 == V_645 ) {
V_420 = V_657 ;
V_430 = V_4 -> V_432 + 1 ;
}
else if ( ( V_111 == V_650 ) ||
( V_111 == V_646 ) )
V_420 = V_657 ;
else if ( V_111 == V_426 ) {
if ( F_18 ( V_603 ,
& V_618 -> V_591 ) &&
! F_18 ( V_601 ,
& V_618 -> V_591 ) )
V_420 = V_656 ;
else
V_420 = V_657 ;
}
break;
case V_659 :
if ( V_111 == V_648 ) {
V_430 = V_4 -> V_432 - 1 ;
if ( V_430 == 0 )
V_420 = V_655 ;
else
V_420 = V_657 ;
}
break;
case V_656 :
if ( V_111 == V_424 )
V_420 = V_655 ;
else if ( ( V_111 == V_650 ) ||
( V_111 == V_646 ) )
V_420 = V_656 ;
else if ( V_111 == V_647 )
V_420 = V_658 ;
else if ( V_111 == V_426 ) {
if ( F_18 ( V_603 ,
& V_618 -> V_591 ) &&
F_18 ( V_601 ,
& V_618 -> V_591 ) ) {
if ( V_4 -> V_432 == 0 )
V_420 = V_655 ;
else
V_420 = V_657 ;
} else
V_420 = V_656 ;
}
break;
case V_658 :
if ( V_111 == V_649 )
V_420 = V_660 ;
break;
case V_660 :
if ( V_111 == V_648 )
V_420 = V_653 ;
break;
default:
F_38 ( L_108 , V_33 ) ;
}
if ( V_420 != V_421 ) {
F_4 ( V_17 , L_109 ,
V_33 , V_111 , V_420 ) ;
V_4 -> V_420 = V_420 ;
V_4 -> V_430 = V_430 ;
return 0 ;
}
F_4 ( V_17 , L_110 , V_33 , V_111 ) ;
return - V_66 ;
}
void F_256 ( struct V_1 * V_2 ,
struct V_413 * V_422 ,
T_6 V_96 , T_7 * V_428 , T_6 V_661 , T_6 V_97 ,
void * V_110 ,
T_9 V_200 , unsigned long type )
{
memset ( V_422 , 0 , sizeof( * V_422 ) ) ;
F_257 ( V_662 < V_661 ) ;
memcpy ( V_422 -> V_428 , V_428 , sizeof( V_422 -> V_428 [ 0 ] ) * V_661 ) ;
V_422 -> V_431 = V_661 ;
V_422 -> V_96 = V_96 ;
V_422 -> V_97 = V_97 ;
V_422 -> V_110 = V_110 ;
V_422 -> V_200 = V_200 ;
V_422 -> type = type ;
V_422 -> V_420 = V_421 ;
if ( F_122 ( V_2 ) )
V_422 -> V_419 = F_253 ;
else
V_422 -> V_419 = F_254 ;
V_422 -> V_417 = F_255 ;
V_422 -> V_418 = F_225 ;
V_422 -> V_179 = F_224 ;
V_422 -> V_196 = F_223 ;
}
int F_258 ( struct V_1 * V_2 ,
struct V_413 * V_422 )
{
switch ( V_422 -> V_33 ) {
case V_655 :
case V_657 :
return V_663 ;
case V_653 :
case V_654 :
case V_659 :
case V_656 :
case V_658 :
case V_660 :
case V_664 :
return V_665 ;
default:
return - V_66 ;
}
}
enum V_666 F_259 ( struct V_1 * V_2 ,
struct V_667 * V_4 )
{
if ( V_4 -> V_416 )
return V_668 ;
F_260 () ;
return V_4 -> V_33 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_667 * V_4 ,
enum V_669 V_111 )
{
return F_33 ( V_2 , V_111 , & V_4 -> V_416 ) ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_667 * V_4 ,
enum V_669 V_111 )
{
unsigned long V_427 = V_4 -> V_416 ;
if ( ! F_226 ( V_111 , & V_427 ) ) {
F_38 ( L_111 ,
V_111 , F_263 ( V_2 ) , V_4 -> V_33 ,
V_427 , V_4 -> V_420 ) ;
return - V_66 ;
}
F_4 ( V_17 ,
L_112 ,
V_111 , F_263 ( V_2 ) , V_4 -> V_420 ) ;
V_4 -> V_33 = V_4 -> V_420 ;
V_4 -> V_420 = V_668 ;
F_227 () ;
F_29 ( V_111 , & V_4 -> V_416 ) ;
F_30 () ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_667 * V_4 ,
enum V_669 V_111 )
{
int V_22 = F_262 ( V_2 , V_4 , V_111 ) ;
return V_22 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_667 * V_4 ,
struct V_670 * V_412 )
{
enum V_666 V_33 = V_4 -> V_33 , V_420 = V_668 ;
enum V_669 V_111 = V_412 -> V_111 ;
if ( F_18 ( V_28 , & V_412 -> V_25 ) ) {
V_4 -> V_416 = 0 ;
V_4 -> V_420 = V_668 ;
}
if ( V_4 -> V_416 )
return - V_37 ;
switch ( V_33 ) {
case V_671 :
if ( V_111 == V_672 )
V_420 = V_673 ;
break;
case V_673 :
if ( V_111 == V_674 )
V_420 = V_675 ;
else if ( V_111 == V_676 )
V_420 = V_671 ;
break;
case V_675 :
if ( V_111 == V_677 )
V_420 = V_673 ;
else if ( ( V_111 == V_678 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_675 ;
else if ( ( V_111 == V_679 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_675 ;
else if ( ( V_111 == V_680 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_675 ;
else if ( ( V_111 == V_681 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_675 ;
else if ( V_111 == V_682 )
V_420 = V_683 ;
break;
case V_683 :
if ( ( V_111 == V_680 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_683 ;
else if ( ( V_111 == V_681 ) &&
( ! F_18 ( V_677 , & V_4 -> V_416 ) ) )
V_420 = V_683 ;
else if ( V_111 == V_684 )
V_420 = V_675 ;
break;
default:
F_38 ( L_113 , V_33 ) ;
}
if ( V_420 != V_668 ) {
F_4 ( V_17 , L_114 ,
V_33 , V_111 , V_420 ) ;
V_4 -> V_420 = V_420 ;
return 0 ;
}
F_4 ( V_17 , L_115 ,
V_33 , V_111 ) ;
return - V_66 ;
}
static inline int F_266 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
return V_686 -> V_687 ( V_2 ) ;
}
static inline int F_267 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
int V_22 = V_686 -> V_688 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_266 ( V_2 , V_686 ) ;
}
static inline int F_268 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
int V_22 = V_686 -> V_689 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_267 ( V_2 , V_686 ) ;
}
static inline int F_269 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
int V_22 = V_686 -> V_690 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_267 ( V_2 , V_686 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
T_7 V_691 = V_412 -> V_412 . V_692 . V_693 ;
struct V_667 * V_4 = V_412 -> V_694 ;
const struct V_685 * V_686 = V_4 -> V_686 ;
int V_22 = 0 ;
F_4 ( V_17 , L_116 ,
F_271 ( V_2 ) , V_691 ) ;
V_22 = V_686 -> V_695 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_686 -> V_696 ( V_2 ) ;
if ( V_22 ) {
F_38 ( L_117 ) ;
goto V_697;
}
switch ( V_691 ) {
case V_698 :
V_22 = F_268 ( V_2 , V_686 ) ;
if ( V_22 )
goto V_697;
break;
case V_699 :
V_22 = F_269 ( V_2 , V_686 ) ;
if ( V_22 )
goto V_697;
break;
case V_700 :
V_22 = F_267 ( V_2 , V_686 ) ;
if ( V_22 )
goto V_697;
break;
case V_701 :
V_22 = F_266 ( V_2 , V_686 ) ;
if ( V_22 )
goto V_697;
break;
default:
F_38 ( L_118 , V_691 ) ;
V_22 = - V_66 ;
}
V_697:
V_686 -> V_702 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_418 ( V_2 , V_4 , V_672 ) ;
return V_22 ;
}
static inline void F_272 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
V_686 -> V_703 ( V_2 ) ;
}
static inline void F_273 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
V_686 -> V_704 ( V_2 ) ;
F_272 ( V_2 , V_686 ) ;
}
static inline void F_274 ( struct V_1 * V_2 ,
const struct V_685 * V_686 )
{
F_273 ( V_2 , V_686 ) ;
V_686 -> V_705 ( V_2 ) ;
}
static inline int F_275 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
T_7 V_706 = V_412 -> V_412 . V_707 . V_706 ;
struct V_667 * V_4 = V_412 -> V_694 ;
const struct V_685 * V_686 = V_4 -> V_686 ;
F_4 ( V_17 , L_119 , F_271 ( V_2 ) ,
V_706 ) ;
switch ( V_706 ) {
case V_708 :
F_274 ( V_2 , V_686 ) ;
break;
case V_709 :
F_273 ( V_2 , V_686 ) ;
break;
case V_710 :
F_272 ( V_2 , V_686 ) ;
break;
default:
F_38 ( L_120 ,
V_706 ) ;
break;
}
V_4 -> V_418 ( V_2 , V_4 , V_676 ) ;
return 0 ;
}
static inline int F_276 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_711 * V_110 =
(struct V_711 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_712 * V_713 = & V_412 -> V_412 . V_714 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_715 = ( T_6 ) V_713 -> V_716 ;
V_110 -> V_717 = F_82 ( V_713 -> V_717 ) ;
V_110 -> V_718 = F_277 ( V_2 ) ;
V_110 -> V_719 = V_713 -> V_719 ;
V_110 -> V_720 = F_82 ( V_713 -> V_720 ) ;
V_110 -> V_721 = F_82 ( V_713 -> V_721 ) ;
V_110 -> V_722 = V_713 -> V_722 ;
V_110 -> V_723 = V_713 -> V_723 ;
V_110 -> V_724 = V_713 -> V_724 ;
V_110 -> V_725 = V_713 -> V_725 ;
V_110 -> V_726 = V_713 -> V_727 ;
if ( V_713 -> V_728 ) {
V_110 -> V_729 = 1 ;
V_110 -> V_730 =
F_82 ( V_713 -> V_728 ) ;
}
V_110 -> V_731 = V_713 -> V_732 ;
V_110 -> V_733 = V_713 -> V_733 ;
if ( V_713 -> V_734 )
V_110 -> V_734 =
F_82 ( V_713 -> V_734 ) ;
else
V_110 -> V_734 =
F_82 ( 0x8100 ) ;
V_110 -> V_735 = V_713 -> V_735 ;
V_110 -> V_736 = V_713 -> V_737 ;
if ( V_110 -> V_736 ) {
memcpy ( V_110 -> V_738 . V_739 ,
V_713 -> V_740 ,
V_741 ) ;
V_110 -> V_742 = V_713 -> V_742 ;
}
return F_111 ( V_2 , V_743 , 0 ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_641 ) ;
}
static inline int F_278 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_744 * V_110 =
(struct V_744 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_745 * V_746 =
& V_412 -> V_412 . V_747 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
if ( F_18 ( V_748 ,
& V_746 -> V_749 ) ) {
V_110 -> V_750 = 1 ;
V_110 -> V_751 =
F_18 ( V_752 ,
& V_746 -> V_749 ) ;
}
if ( F_18 ( V_753 ,
& V_746 -> V_749 ) ) {
V_110 -> V_754 = 1 ;
V_110 -> V_717 =
F_82 ( V_746 -> V_69 ) ;
}
if ( F_18 ( V_755 ,
& V_746 -> V_749 ) ) {
V_110 -> V_756 = 1 ;
V_110 -> V_734 =
F_82 ( V_746 -> V_757 ) ;
}
if ( F_18 ( V_758 ,
& V_746 -> V_749 ) ) {
V_110 -> V_759 = 1 ;
if ( F_18 ( V_760 ,
& V_746 -> V_749 ) )
V_110 -> V_731 = 1 ;
V_110 -> V_731 =
V_746 -> V_761 ;
}
if ( F_18 ( V_762 ,
& V_746 -> V_749 ) ) {
V_110 -> V_763 = 1 ;
if ( F_18 ( V_764 ,
& V_746 -> V_749 ) )
V_110 -> V_722 = 1 ;
if ( F_18 ( V_765 ,
& V_746 -> V_749 ) )
V_110 -> V_724 = 1 ;
if ( F_18 ( V_766 ,
& V_746 -> V_749 ) )
V_110 -> V_723 = 1 ;
if ( F_18 ( V_767 ,
& V_746 -> V_749 ) )
V_110 -> V_725 = 1 ;
V_110 -> V_720 =
F_82 ( V_746 -> V_720 ) ;
V_110 -> V_721 =
F_82 ( V_746 -> V_721 ) ;
}
V_110 -> V_104 = V_768 ;
return F_111 ( V_2 , V_769 , 0 ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_641 ) ;
}
static inline int F_279 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_744 * V_110 =
(struct V_744 * ) V_4 -> V_770 ;
T_9 V_580 = V_4 -> V_771 ;
struct V_772 * V_773 =
& V_412 -> V_412 . V_774 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_775 = 1 ;
V_110 -> V_776 = F_82 ( V_773 -> V_776 ) ;
V_110 -> V_777 = 1 ;
V_110 -> V_778 =
F_82 ( V_773 -> V_778 ) ;
V_110 -> V_779 = 1 ;
V_110 -> V_780 = V_773 -> V_780 ;
V_110 -> V_104 = V_781 ;
F_4 ( V_17 ,
L_121 ,
V_110 -> V_776 ,
V_110 -> V_778 , V_110 -> V_780 ) ;
return F_111 ( V_2 , V_769 , 0 ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_641 ) ;
}
static
inline int F_280 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_782 * V_110 =
(struct V_782 * ) V_4 -> V_770 ;
struct V_783 * V_784 =
& V_412 -> V_412 . V_785 ;
T_12 * V_786 = ( T_12 * ) V_110 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_787 = F_82 ( V_784 -> V_787 ) ;
V_110 -> V_788 = V_784 -> V_788 ;
V_110 -> V_789 = V_784 -> V_789 ;
V_110 -> V_790 = V_784 -> V_790 ;
V_110 -> V_104 = V_784 -> V_789 ;
F_4 ( V_17 , L_122 ,
V_110 -> V_789 , V_110 -> V_787 ,
V_110 -> V_788 , V_110 -> V_790 ) ;
return F_111 ( V_2 , V_791 , 0 ,
F_112 ( * V_786 ) , F_113 ( * V_786 ) ,
V_641 ) ;
}
static inline int F_281 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
return F_111 ( V_2 , V_792 , 0 , 0 , 0 ,
V_641 ) ;
}
static inline int F_282 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
return F_111 ( V_2 , V_793 , 0 , 0 , 0 ,
V_641 ) ;
}
static inline int F_283 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_794 * V_110 =
(struct V_794 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_795 * V_796 =
& V_412 -> V_412 . V_797 ;
int V_288 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_798 = V_796 -> V_798 ;
V_110 -> V_799 = V_796 -> V_799 ;
V_110 -> V_800 = V_796 -> V_800 ;
for ( V_288 = 0 ; V_288 < F_284 ( V_110 -> V_801 ) ; V_288 ++ )
V_110 -> V_801 [ V_288 ] =
V_796 -> V_801 [ V_288 ] ;
for ( V_288 = 0 ; V_288 < V_802 ; V_288 ++ )
V_110 -> V_803 [ V_288 ] = V_796 -> V_803 [ V_288 ] ;
return F_111 ( V_2 , V_804 , 0 ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_641 ) ;
}
static inline
int F_285 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
struct V_805 * V_110 =
(struct V_805 * ) V_4 -> V_110 ;
T_9 V_580 = V_4 -> V_200 ;
struct V_806 * V_807 =
& V_412 -> V_412 . V_808 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_809 = V_807 -> V_809 ;
V_110 -> V_810 = V_807 -> V_810 ;
V_110 -> V_811 =
V_807 -> V_811 ;
V_110 -> V_812 = V_807 -> V_812 ;
V_110 -> V_813 = V_807 -> V_813 ;
V_110 -> V_814 . V_492 =
F_79 ( F_113 ( V_807 -> V_814 ) ) ;
V_110 -> V_814 . V_494 =
F_79 ( F_112 ( V_807 -> V_814 ) ) ;
F_4 ( V_17 , L_123 ,
V_110 -> V_809 , V_110 -> V_810 ,
V_110 -> V_811 , V_110 -> V_812 ,
V_110 -> V_813 , V_110 -> V_814 . V_492 ,
V_110 -> V_814 . V_494 ) ;
return F_111 ( V_2 , V_815 , 0 ,
F_112 ( V_580 ) ,
F_113 ( V_580 ) , V_641 ) ;
}
static int F_286 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
switch ( V_412 -> V_111 ) {
case V_672 :
return F_270 ( V_2 , V_412 ) ;
case V_674 :
return F_276 ( V_2 , V_412 ) ;
case V_677 :
return F_281 ( V_2 , V_412 ) ;
case V_676 :
return F_275 ( V_2 , V_412 ) ;
case V_678 :
return F_279 ( V_2 , V_412 ) ;
case V_679 :
return F_280 ( V_2 , V_412 ) ;
case V_682 :
return F_282 ( V_2 , V_412 ) ;
case V_684 :
return F_283 ( V_2 , V_412 ) ;
case V_680 :
return F_278 ( V_2 , V_412 ) ;
case V_681 :
return F_285 ( V_2 , V_412 ) ;
default:
F_38 ( L_65 , V_412 -> V_111 ) ;
return - V_66 ;
}
}
void F_287 ( struct V_1 * V_2 ,
struct V_667 * V_422 ,
void * V_110 , T_9 V_200 ,
void * V_770 , T_9 V_771 ,
struct V_685 * V_816 )
{
memset ( V_422 , 0 , sizeof( * V_422 ) ) ;
F_288 ( & V_422 -> V_817 ) ;
V_422 -> V_110 = V_110 ;
V_422 -> V_200 = V_200 ;
V_422 -> V_770 = V_770 ;
V_422 -> V_771 = V_771 ;
V_422 -> V_419 = F_286 ;
V_422 -> V_417 = F_265 ;
V_422 -> V_418 = F_264 ;
V_422 -> V_179 = F_261 ;
V_422 -> V_686 = V_816 ;
}
int F_289 ( struct V_1 * V_2 ,
struct V_670 * V_412 )
{
struct V_667 * V_4 = V_412 -> V_694 ;
int V_22 , V_20 = 300 ;
enum V_669 V_111 = V_412 -> V_111 ;
unsigned long * V_416 = & V_4 -> V_416 ;
F_290 ( & V_4 -> V_817 ) ;
V_22 = V_4 -> V_417 ( V_2 , V_4 , V_412 ) ;
if ( ( V_22 == - V_37 ) &&
( F_18 ( V_818 , & V_412 -> V_25 ) ) ) {
while ( ( V_22 == - V_37 ) && ( -- V_20 > 0 ) ) {
F_291 ( & V_4 -> V_817 ) ;
F_292 ( 10 ) ;
F_290 ( & V_4 -> V_817 ) ;
V_22 = V_4 -> V_417 ( V_2 , V_4 , V_412 ) ;
}
if ( V_22 == - V_37 ) {
F_291 ( & V_4 -> V_817 ) ;
F_38 ( L_124 ) ;
return V_22 ;
}
} else if ( V_22 ) {
F_291 ( & V_4 -> V_817 ) ;
return V_22 ;
}
F_32 ( V_111 , V_416 ) ;
if ( F_18 ( V_28 , & V_412 -> V_25 ) ) {
F_262 ( V_2 , V_4 , V_111 ) ;
F_291 ( & V_4 -> V_817 ) ;
} else {
V_22 = V_4 -> V_419 ( V_2 , V_412 ) ;
F_291 ( & V_4 -> V_817 ) ;
if ( V_22 ) {
V_4 -> V_420 = V_668 ;
F_29 ( V_111 , V_416 ) ;
F_30 () ;
return V_22 ;
}
if ( F_18 ( V_205 , & V_412 -> V_25 ) ) {
V_22 = V_4 -> V_179 ( V_2 , V_4 , V_111 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_18 ( V_111 , V_416 ) ;
}
