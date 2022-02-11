static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
union V_6 * V_7 ,
T_1 V_8 ,
T_2 V_9 ,
T_3 V_10 ,
T_4 V_11 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_2 ( & V_4 -> V_12 ) ;
F_2 ( & V_4 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
V_4 -> V_15 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
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
static int F_51 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
if ( ! F_52 ( V_50 -> V_53 . V_53 ) )
return - V_54 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_50 -> V_53 . V_53 , V_52 -> V_55 . V_53 . V_53 , V_56 ) )
return - V_57 ;
return 0 ;
}
static int F_53 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( V_50 -> V_58 . V_58 == V_52 -> V_55 . V_58 . V_58 )
return - V_57 ;
return 0 ;
}
static int F_54 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ( V_50 -> V_59 . V_58 == V_52 -> V_55 . V_59 . V_58 ) &&
( ! memcmp ( V_50 -> V_59 . V_53 , V_52 -> V_55 . V_59 . V_53 ,
V_56 ) ) )
return - V_57 ;
return 0 ;
}
static struct V_51 *
F_55 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ! memcmp ( V_50 -> V_53 . V_53 , V_52 -> V_55 . V_53 . V_53 , V_56 ) )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_56 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( V_50 -> V_58 . V_58 == V_52 -> V_55 . V_58 . V_58 )
return V_52 ;
return NULL ;
}
static struct V_51 *
F_57 ( struct V_39 * V_4 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
F_9 (pos, &o->head, link)
if ( ( V_50 -> V_59 . V_58 == V_52 -> V_55 . V_59 . V_58 ) &&
( ! memcmp ( V_50 -> V_59 . V_53 , V_52 -> V_55 . V_59 . V_53 ,
V_56 ) ) )
return V_52 ;
return NULL ;
}
static bool F_58 ( struct V_39 * V_60 ,
struct V_39 * V_61 ,
union V_49 * V_50 )
{
struct V_51 * V_52 ;
int V_22 ;
V_52 = V_60 -> V_62 ( V_60 , V_50 ) ;
V_22 = V_61 -> V_63 ( V_61 , V_50 ) ;
if ( V_22 || ! V_52 )
return false ;
return true ;
}
static bool F_59 (
struct V_39 * V_60 ,
struct V_39 * V_61 ,
union V_49 * V_50 )
{
return false ;
}
static inline T_5 F_60 ( struct V_39 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_5 V_64 = 0 ;
if ( ( V_38 -> V_65 == V_66 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_68 ;
if ( ( V_38 -> V_65 == V_69 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_70 ;
return V_64 ;
}
static inline void F_61 ( struct V_1 * V_2 ,
bool V_71 , unsigned char * V_72 , int V_73 )
{
T_6 V_74 [ 2 ] ;
T_6 V_75 = F_62 ( V_2 ) ? V_76 :
V_77 ;
if ( ! F_63 ( V_2 ) || V_73 > V_78 )
return;
F_4 ( V_17 , L_11 ,
( V_71 ? L_12 : L_13 ) , V_73 ) ;
if ( V_71 ) {
V_75 += 8 * V_73 ;
V_74 [ 0 ] = ( ( V_72 [ 2 ] << 24 ) | ( V_72 [ 3 ] << 16 ) |
( V_72 [ 4 ] << 8 ) | V_72 [ 5 ] ) ;
V_74 [ 1 ] = ( ( V_72 [ 0 ] << 8 ) | V_72 [ 1 ] ) ;
F_64 ( V_2 , V_75 , V_74 , 2 ) ;
}
F_65 ( V_2 , ( F_62 ( V_2 ) ? V_79 :
V_80 ) + 4 * V_73 , V_71 ) ;
}
static inline void F_66 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_71 , int V_81 ,
struct V_82 * V_83 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
V_83 -> V_84 = V_38 -> V_85 ;
V_83 -> V_86 = V_38 -> V_86 ;
V_83 -> V_87 |=
F_60 ( V_4 ) ;
if ( V_71 )
V_83 -> V_87 |= V_88 ;
V_83 -> V_87 |=
( V_81 << V_89 ) ;
}
static inline void F_67 ( T_6 V_90 , int type ,
struct V_91 * V_83 , int V_92 )
{
V_83 -> V_93 = ( V_90 & V_94 ) | ( type << V_95 ) ;
V_83 -> V_92 = ( T_5 ) V_92 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_96 ,
int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_98 * V_50 =
(struct V_98 * ) ( V_38 -> V_99 ) ;
int V_92 = V_96 + 1 , V_100 = V_19 -> V_101 . V_59 . V_100 ;
union V_102 * V_103 = & V_50 -> V_104 [ V_96 ] ;
bool V_71 = ( V_100 == V_105 ) ? true : false ;
unsigned long * V_106 = & V_19 -> V_101 . V_59 . V_106 ;
T_5 * V_53 = V_19 -> V_101 . V_59 . V_55 . V_53 . V_53 ;
if ( V_100 != V_107 ) {
if ( F_20 ( V_108 , V_106 ) )
F_61 ( V_2 , V_71 , V_53 ,
V_109 ) ;
else if ( F_20 ( V_110 , V_106 ) )
F_61 ( V_2 , V_71 , V_53 , V_111 ) ;
}
if ( V_96 == 0 )
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_66 ( V_2 , V_4 , V_71 , V_112 ,
& V_103 -> V_53 . V_113 ) ;
F_4 ( V_17 , L_14 ,
V_71 ? L_15 : L_16 , V_53 , V_38 -> V_85 ) ;
F_69 ( & V_103 -> V_53 . V_114 ,
& V_103 -> V_53 . V_115 ,
& V_103 -> V_53 . V_116 , V_53 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_117 ,
true , V_112 ,
& V_103 -> V_53 . V_113 ) ;
F_69 ( & V_103 -> V_53 . V_114 ,
& V_103 -> V_53 . V_115 ,
& V_103 -> V_53 . V_116 , V_53 ) ;
}
F_67 ( V_38 -> V_90 , V_38 -> V_33 , & V_50 -> V_113 ,
V_92 ) ;
}
static inline void F_70 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_97 ,
struct V_118 * V_83 )
{
struct V_32 * V_119 = & V_4 -> V_38 ;
V_83 -> V_120 = 1 ;
V_83 -> V_40 = ( T_5 ) V_97 ;
V_83 -> V_84 = 0xff ;
V_83 -> V_93 = ( ( V_119 -> V_90 & V_94 ) | ( type << V_95 ) ) ;
}
static inline void F_71 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_71 , int V_81 , T_5 * V_53 ,
T_7 V_121 , struct V_122 * V_123 )
{
struct V_32 * V_119 = & V_4 -> V_38 ;
T_6 V_124 = ( 1 << V_119 -> V_85 ) ;
V_123 -> V_125 = F_72 ( V_124 ) ;
V_123 -> V_126 = V_119 -> V_86 ;
V_123 -> V_121 = F_73 ( V_121 ) ;
if ( V_71 ) {
F_74 ( V_123 -> V_127 , V_128 ,
V_129 ) ;
F_74 ( V_123 -> V_127 ,
V_130 , V_81 ) ;
F_69 ( & V_123 -> V_131 ,
& V_123 -> V_132 ,
& V_123 -> V_133 , V_53 ) ;
} else
F_74 ( V_123 -> V_127 , V_128 ,
V_134 ) ;
}
static inline void F_75 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_97 , bool V_71 ,
T_5 * V_53 , T_7 V_121 , int V_81 , struct V_135 * V_136 )
{
struct V_122 * V_123 = & V_136 -> V_137 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_70 ( V_2 , V_4 , type , V_97 ,
& V_136 -> V_83 ) ;
F_71 ( V_2 , V_4 , V_71 , V_81 , V_53 , V_121 ,
V_123 ) ;
F_4 ( V_17 , L_17 ,
V_71 ? L_18 : L_19 ,
V_53 , V_38 -> V_85 , V_97 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_96 ,
int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_135 * V_136 =
(struct V_135 * ) ( V_38 -> V_99 ) ;
bool V_71 = ( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
true : false ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
F_75 ( V_2 , V_4 , V_138 ,
V_97 , V_71 ,
V_19 -> V_101 . V_59 . V_55 . V_53 . V_53 , 0 ,
V_139 , V_136 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_96 ,
int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_98 * V_50 =
(struct V_98 * ) ( V_38 -> V_99 ) ;
int V_92 = V_96 + 1 ;
union V_102 * V_103 = & V_50 -> V_104 [ V_96 ] ;
int V_100 = V_19 -> V_101 . V_59 . V_100 ;
bool V_71 = ( V_100 == V_105 ) ? true : false ;
T_7 V_58 = V_19 -> V_101 . V_59 . V_55 . V_58 . V_58 ;
if ( V_96 == 0 )
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_66 ( V_2 , V_4 , V_71 , V_140 ,
& V_103 -> V_58 . V_113 ) ;
F_4 ( V_17 , L_20 , ( V_71 ? L_15 : L_16 ) ,
V_58 ) ;
V_103 -> V_58 . V_58 = F_73 ( V_58 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_117 ,
true , V_140 ,
& V_103 -> V_58 . V_113 ) ;
V_103 -> V_58 . V_58 = F_73 ( V_58 ) ;
}
F_67 ( V_38 -> V_90 , V_38 -> V_33 , & V_50 -> V_113 ,
V_92 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_96 , int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_98 * V_50 =
(struct V_98 * ) ( V_38 -> V_99 ) ;
int V_92 = V_96 + 1 ;
union V_102 * V_103 = & V_50 -> V_104 [ V_96 ] ;
int V_100 = V_19 -> V_101 . V_59 . V_100 ;
bool V_71 = ( V_100 == V_105 ) ? true : false ;
T_7 V_58 = V_19 -> V_101 . V_59 . V_55 . V_59 . V_58 ;
T_5 * V_53 = V_19 -> V_101 . V_59 . V_55 . V_59 . V_53 ;
if ( V_96 == 0 )
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_66 ( V_2 , V_4 , V_71 , V_141 ,
& V_103 -> V_142 . V_113 ) ;
V_103 -> V_142 . V_58 = F_73 ( V_58 ) ;
F_69 ( & V_103 -> V_142 . V_114 ,
& V_103 -> V_142 . V_115 ,
& V_103 -> V_142 . V_116 , V_53 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_117 ,
true , V_141 ,
& V_103 -> V_142 . V_113 ) ;
V_103 -> V_142 . V_58 = F_73 ( V_58 ) ;
F_69 ( & V_103 -> V_142 . V_114 ,
& V_103 -> V_142 . V_115 ,
& V_103 -> V_142 . V_116 , V_53 ) ;
}
F_67 ( V_38 -> V_90 , V_38 -> V_33 , & V_50 -> V_113 ,
V_92 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_96 , int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_135 * V_136 =
(struct V_135 * ) ( V_38 -> V_99 ) ;
bool V_71 = ( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
true : false ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
F_75 ( V_2 , V_4 , V_143 ,
V_97 , V_71 ,
V_19 -> V_101 . V_59 . V_55 . V_59 . V_53 ,
V_19 -> V_101 . V_59 . V_55 . V_59 . V_58 ,
V_144 , V_136 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_51 * * V_147 )
{
struct V_51 * V_52 ;
struct V_39 * V_4 = V_146 -> V_148 ;
if ( F_15 ( & V_4 -> V_149 ) ) {
* V_147 = NULL ;
return 0 ;
}
if ( * V_147 == NULL )
* V_147 = F_16 ( & V_4 -> V_149 ,
struct V_51 ,
V_24 ) ;
else
* V_147 = F_81 ( * V_147 , V_24 ) ;
V_52 = * V_147 ;
if ( F_82 ( & V_52 -> V_24 , & V_4 -> V_149 ) )
* V_147 = NULL ;
memcpy ( & V_146 -> V_150 . V_55 , & V_52 -> V_55 , sizeof( V_52 -> V_55 ) ) ;
V_146 -> V_150 . V_100 = V_105 ;
V_146 -> V_150 . V_106 = V_52 -> V_106 ;
F_83 ( V_151 , & V_146 -> V_25 ) ;
return F_84 ( V_2 , V_146 ) ;
}
static struct V_18 * F_85 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_152 * V_50 = & V_19 -> V_101 . V_59 . V_55 . V_53 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_53 , V_50 ,
sizeof( * V_50 ) ) &&
( V_52 -> V_101 . V_59 . V_100 == V_19 -> V_101 . V_59 . V_100 ) )
return V_52 ;
return NULL ;
}
static struct V_18 * F_86 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_153 * V_50 = & V_19 -> V_101 . V_59 . V_55 . V_58 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_58 , V_50 ,
sizeof( * V_50 ) ) &&
( V_52 -> V_101 . V_59 . V_100 == V_19 -> V_101 . V_59 . V_100 ) )
return V_52 ;
return NULL ;
}
static struct V_18 * F_87 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_154 * V_50 =
& V_19 -> V_101 . V_59 . V_55 . V_59 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_59 , V_50 ,
sizeof( * V_50 ) ) &&
( V_52 -> V_101 . V_59 . V_100 == V_19 -> V_101 . V_59 . V_100 ) )
return V_52 ;
return NULL ;
}
static inline int F_88 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_155 -> V_59 ;
struct V_3 * V_156 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_63 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_21
L_22 ) ;
return V_22 ;
}
if ( V_156 -> V_11 ( V_156 , V_19 ) ) {
F_4 ( V_17 , L_23 ) ;
return - V_57 ;
}
if ( ! ( F_20 ( V_157 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_4 -> V_158 ( V_4 ) ) )
return - V_54 ;
return 0 ;
}
static inline int F_89 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_155 -> V_59 ;
struct V_51 * V_52 ;
struct V_3 * V_156 = & V_4 -> V_12 ;
struct V_18 V_159 ;
V_52 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
if ( ! V_52 ) {
F_4 ( V_17 , L_24
L_22 ) ;
return - V_57 ;
}
memcpy ( & V_159 , V_19 , sizeof( V_159 ) ) ;
V_159 . V_101 . V_59 . V_100 = V_107 ;
if ( V_156 -> V_11 ( V_156 , & V_159 ) ) {
F_12 ( L_25 ) ;
return - V_54 ;
}
if ( V_156 -> V_11 ( V_156 , V_19 ) ) {
F_4 ( V_17 , L_26 ) ;
return - V_57 ;
}
if ( ! ( F_20 ( V_157 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_4 -> V_160 ( V_4 ) ) ) {
F_12 ( L_27 ) ;
return - V_54 ;
}
return 0 ;
}
static inline int F_90 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_18 * V_19 )
{
struct V_39 * V_60 = & V_155 -> V_59 ;
struct V_39 * V_161 = V_19 -> V_101 . V_59 . V_117 ;
struct V_18 V_159 ;
struct V_3 * V_162 = & V_60 -> V_12 ;
struct V_3 * V_163 = & V_161 -> V_12 ;
if ( ! V_60 -> V_164 ( V_60 , V_161 , & V_19 -> V_101 . V_59 . V_55 ) ) {
F_4 ( V_17 , L_28
L_22 ) ;
return - V_54 ;
}
memcpy ( & V_159 , V_19 , sizeof( V_159 ) ) ;
V_159 . V_101 . V_59 . V_100 = V_165 ;
if ( V_162 -> V_11 ( V_162 , & V_159 ) ) {
F_12 ( L_29
L_30 ) ;
return - V_54 ;
}
if ( V_162 -> V_11 ( V_162 , V_19 ) ) {
F_4 ( V_17 , L_25 ) ;
return - V_57 ;
}
V_159 . V_101 . V_59 . V_100 = V_105 ;
if ( V_163 -> V_11 ( V_163 , & V_159 ) ) {
F_12 ( L_31
L_32 ) ;
return - V_54 ;
}
if ( ! ( F_20 ( V_166 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_161 -> V_158 ( V_161 ) ) )
return - V_54 ;
if ( ! ( F_20 ( V_157 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_60 -> V_160 ( V_60 ) ) ) {
V_161 -> V_160 ( V_161 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_101 . V_59 . V_100 ) {
case V_105 :
return F_88 ( V_2 , V_155 , V_19 ) ;
case V_165 :
return F_89 ( V_2 , V_155 , V_19 ) ;
case V_107 :
return F_90 ( V_2 , V_155 , V_19 ) ;
default:
return - V_54 ;
}
}
static int F_92 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_156 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_167 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_24 ( V_156 ) )
F_38 ( 1000 , 1000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_168 * V_169 ,
unsigned long * V_25 )
{
struct V_32 * V_119 = & V_4 -> V_38 ;
int V_22 ;
F_18 ( V_2 , & V_4 -> V_12 ) ;
V_119 -> V_170 ( V_119 ) ;
if ( V_169 -> V_171 . error )
return - V_54 ;
if ( F_20 ( V_172 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_18 * V_19 )
{
struct V_18 V_173 , * V_52 ;
struct V_39 * V_4 = & V_155 -> V_59 ;
struct V_3 * V_156 = & V_4 -> V_12 ;
memcpy ( & V_173 , V_19 , sizeof( V_173 ) ) ;
switch ( V_19 -> V_101 . V_59 . V_100 ) {
case V_105 :
V_173 . V_101 . V_59 . V_100 = V_165 ;
break;
case V_165 :
V_173 . V_101 . V_59 . V_100 = V_105 ;
break;
default:
return 0 ;
}
V_52 = V_156 -> V_11 ( V_156 , & V_173 ) ;
if ( V_52 ) {
if ( ! F_20 ( V_157 ,
& V_52 -> V_101 . V_59 . V_106 ) ) {
if ( ( V_173 . V_101 . V_59 . V_100 ==
V_105 ) && ! V_4 -> V_160 ( V_4 ) ) {
F_12 ( L_33
L_34 ) ;
return - V_54 ;
} else if ( ! V_4 -> V_158 ( V_4 ) ) {
F_12 ( L_35
L_36 ) ;
return - V_54 ;
}
}
F_4 ( V_17 , L_37 ,
( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
L_12 : L_38 ) ;
F_17 ( & V_52 -> V_24 ) ;
F_5 ( V_2 , V_52 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_95 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_51 * * V_174 )
{
int V_100 = V_19 -> V_101 . V_59 . V_100 ;
struct V_51 * V_175 ;
if ( ! V_21 &&
( ( V_100 == V_105 ) || ( V_100 == V_107 ) ) ) {
V_175 = F_26 ( sizeof( * V_175 ) , V_31 ) ;
if ( ! V_175 )
return - V_176 ;
if ( ! V_4 -> V_177 ( V_4 , & V_175 -> V_97 ) ) {
F_21 ( 1 ) ;
F_6 ( V_175 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_39 , V_175 -> V_97 ) ;
memcpy ( & V_175 -> V_55 , & V_19 -> V_101 . V_59 . V_55 ,
sizeof( V_175 -> V_55 ) ) ;
V_175 -> V_106 =
V_19 -> V_101 . V_59 . V_106 ;
} else
V_175 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
* V_174 = V_175 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
union V_6 * V_155 ,
struct V_178 * V_179 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_155 -> V_59 , * V_180 ;
struct V_32 * V_119 = & V_4 -> V_38 ;
int V_22 , V_181 = 0 ;
bool V_21 = F_20 ( V_151 , V_25 ) ;
bool V_182 = F_20 ( V_28 , V_25 ) ;
struct V_51 * V_175 ;
int V_100 ;
if ( ! V_182 ) {
F_21 ( V_119 -> V_183 ( V_119 ) ) ;
V_119 -> V_184 ( V_119 ) ;
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( V_100 == V_107 )
V_180 = V_19 -> V_101 . V_59 . V_117 ;
else
V_180 = V_4 ;
V_22 = F_95 ( V_2 , V_180 ,
V_19 , V_21 ,
& V_175 ) ;
if ( V_22 )
goto V_185;
F_21 ( ! V_175 ) ;
if ( ! V_21 &&
( ( V_100 == V_105 ) ||
( V_100 == V_107 ) ) )
F_97 ( & V_175 -> V_24 , & V_180 -> V_149 ) ;
V_4 -> V_186 ( V_2 , V_4 , V_19 , V_181 ,
V_175 -> V_97 ) ;
if ( V_100 == V_107 )
V_181 += 2 ;
else
V_181 ++ ;
}
V_22 = F_98 ( V_2 , V_4 -> V_187 , V_119 -> V_90 ,
F_99 ( V_119 -> V_188 ) ,
F_100 ( V_119 -> V_188 ) ,
V_189 ) ;
if ( V_22 )
goto V_185;
}
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( ( V_100 == V_165 ) ||
( V_100 == V_107 ) ) {
V_175 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
F_21 ( ! V_175 ) ;
V_4 -> V_190 ( V_4 , V_175 -> V_97 ) ;
F_17 ( & V_175 -> V_24 ) ;
F_6 ( V_175 ) ;
}
}
if ( ! V_182 )
return 1 ;
else
return 0 ;
V_185:
V_119 -> V_170 ( V_119 ) ;
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( V_100 == V_107 )
V_180 = V_19 -> V_101 . V_59 . V_117 ;
else
V_180 = V_4 ;
if ( ! V_21 &&
( ( V_100 == V_105 ) ||
( V_100 == V_107 ) ) ) {
V_175 = V_4 -> V_62 ( V_180 ,
& V_19 -> V_101 . V_59 . V_55 ) ;
if ( V_175 ) {
F_17 ( & V_175 -> V_24 ) ;
F_6 ( V_175 ) ;
}
}
}
return V_22 ;
}
static inline int F_101 (
struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_146 -> V_148 ;
bool V_21 = F_20 ( V_151 , & V_146 -> V_25 ) ;
V_19 = F_25 ( V_2 ) ;
if ( ! V_19 )
return - V_176 ;
switch ( V_146 -> V_150 . V_100 ) {
case V_107 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_101 . V_59 , & V_146 -> V_150 , sizeof( V_146 -> V_150 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_84 (
struct V_1 * V_2 ,
struct V_145 * V_146 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_146 -> V_148 ;
unsigned long * V_25 = & V_146 -> V_25 ;
bool V_191 = F_20 ( V_172 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_191 ) {
V_22 = F_101 ( V_2 , V_146 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_20 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_5
L_40 ) ;
V_38 -> V_170 ( V_38 ) ;
}
if ( V_191 || F_20 ( V_192 , V_25 ) ||
F_20 ( V_193 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_20 ( V_193 , & V_146 -> V_25 ) ) {
int V_194 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_194 -- ) {
V_22 = V_38 -> V_167 ( V_2 , V_38 ) ;
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
static int F_102 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_106 ,
unsigned long * V_25 )
{
struct V_51 * V_52 = NULL ;
int V_22 = 0 ;
struct V_145 V_146 ;
struct V_3 * V_156 = & V_4 -> V_12 ;
struct V_18 * V_195 , * V_196 ;
F_8 ( & V_156 -> V_14 ) ;
F_103 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_195 -> V_101 . V_59 . V_106 ==
* V_106 )
F_17 ( & V_195 -> V_24 ) ;
}
F_10 ( & V_156 -> V_14 ) ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_148 = V_4 ;
V_146 . V_25 = * V_25 ;
V_146 . V_150 . V_100 = V_165 ;
F_104 ( V_193 , & V_146 . V_25 ) ;
F_104 ( V_192 , & V_146 . V_25 ) ;
F_104 ( V_172 , & V_146 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_52 -> V_106 == * V_106 ) {
V_146 . V_150 . V_106 = V_52 -> V_106 ;
memcpy ( & V_146 . V_150 . V_55 , & V_52 -> V_55 , sizeof( V_52 -> V_55 ) ) ;
V_22 = F_84 ( V_2 , & V_146 ) ;
if ( V_22 < 0 ) {
F_12 ( L_41 ) ;
return V_22 ;
}
}
}
V_146 . V_25 = * V_25 ;
F_83 ( V_172 , & V_146 . V_25 ) ;
return F_84 ( V_2 , & V_146 ) ;
}
static inline void F_105 ( struct V_32 * V_38 , T_5 V_85 ,
T_6 V_90 , T_5 V_86 , void * V_99 , T_8 V_188 , int V_33 ,
unsigned long * V_34 , T_9 type )
{
V_38 -> V_86 = V_86 ;
V_38 -> V_90 = V_90 ;
V_38 -> V_85 = V_85 ;
V_38 -> V_99 = V_99 ;
V_38 -> V_188 = V_188 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_65 = type ;
V_38 -> V_183 = F_27 ;
V_38 -> V_170 = F_28 ;
V_38 -> V_184 = F_32 ;
V_38 -> V_167 = F_40 ;
}
static inline void F_106 ( struct V_39 * V_4 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 , T_8 V_188 ,
int V_33 , unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_149 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_197 = F_102 ;
V_4 -> V_21 = F_80 ;
V_4 -> V_198 = F_93 ;
V_4 -> V_199 = F_92 ;
F_105 ( & V_4 -> V_38 , V_85 , V_90 , V_86 , V_99 , V_188 ,
V_33 , V_34 , type ) ;
}
void F_107 ( struct V_1 * V_2 ,
struct V_39 * V_200 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_188 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 )
{
union V_6 * V_201 = (union V_6 * ) V_200 ;
F_106 ( V_200 , V_85 , V_90 , V_86 , V_99 ,
V_188 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_200 -> V_158 = F_42 ;
V_200 -> V_160 = F_47 ;
V_200 -> V_177 = F_41 ;
V_200 -> V_190 = F_46 ;
if ( F_108 ( V_2 ) ) {
V_200 -> V_186 = F_76 ;
V_200 -> V_62 = F_55 ;
V_200 -> V_63 = F_51 ;
V_200 -> V_164 = F_59 ;
V_200 -> V_187 = V_202 ;
F_1 ( V_2 ,
& V_200 -> V_12 , 1 , V_201 ,
F_91 ,
F_94 ,
F_96 ,
F_85 ) ;
} else {
V_200 -> V_186 = F_68 ;
V_200 -> V_62 = F_55 ;
V_200 -> V_63 = F_51 ;
V_200 -> V_164 = F_58 ;
V_200 -> V_187 =
V_203 ;
F_1 ( V_2 ,
& V_200 -> V_12 , V_204 ,
V_201 , F_91 ,
F_94 ,
F_96 ,
F_85 ) ;
}
}
void F_109 ( struct V_1 * V_2 ,
struct V_39 * V_205 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_188 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_46 )
{
union V_6 * V_201 = (union V_6 * ) V_205 ;
F_106 ( V_205 , V_85 , V_90 , V_86 , V_99 ,
V_188 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_205 -> V_158 = F_44 ;
V_205 -> V_160 = F_49 ;
V_205 -> V_177 = F_43 ;
V_205 -> V_190 = F_48 ;
if ( F_108 ( V_2 ) ) {
F_12 ( L_42 ) ;
F_110 () ;
} else {
V_205 -> V_186 = F_77 ;
V_205 -> V_62 = F_56 ;
V_205 -> V_63 = F_53 ;
V_205 -> V_164 = F_58 ;
V_205 -> V_187 =
V_203 ;
F_1 ( V_2 ,
& V_205 -> V_12 , V_204 ,
V_201 , F_91 ,
F_94 ,
F_96 ,
F_86 ) ;
}
}
void F_111 ( struct V_1 * V_2 ,
struct V_39 * V_148 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_188 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_201 =
(union V_6 * ) V_148 ;
F_106 ( V_148 , V_85 , V_90 , V_86 , V_99 ,
V_188 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_148 -> V_158 = F_45 ;
V_148 -> V_160 = F_50 ;
V_148 -> V_177 = F_41 ;
V_148 -> V_190 = F_46 ;
if ( F_112 ( V_2 ) ) {
F_12 ( L_43 ) ;
F_110 () ;
} else if ( F_113 ( V_2 ) ) {
V_148 -> V_186 = F_79 ;
V_148 -> V_62 = F_57 ;
V_148 -> V_63 = F_54 ;
V_148 -> V_164 = F_59 ;
V_148 -> V_187 = V_202 ;
F_1 ( V_2 ,
& V_148 -> V_12 , 1 , V_201 ,
F_91 ,
F_94 ,
F_96 ,
F_87 ) ;
} else {
V_148 -> V_186 = F_78 ;
V_148 -> V_62 = F_57 ;
V_148 -> V_63 = F_54 ;
V_148 -> V_164 = F_58 ;
V_148 -> V_187 =
V_203 ;
F_1 ( V_2 ,
& V_148 -> V_12 ,
V_204 ,
V_201 , F_91 ,
F_94 ,
F_96 ,
F_87 ) ;
}
}
static inline void F_114 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
T_7 V_126 )
{
T_10 V_208 = sizeof( struct V_206 ) ;
T_6 V_209 = V_210 +
F_115 ( V_126 ) ;
F_116 ( V_2 , V_209 , V_208 , ( T_6 * ) V_207 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_211 * V_146 )
{
T_6 V_212 = ( 1 << V_146 -> V_85 ) ;
struct V_206 * V_207 =
(struct V_206 * ) V_146 -> V_99 ;
T_5 V_213 = 1 , V_214 = 1 ;
T_5 V_215 = 0 , V_216 = 0 , V_217 = 0 ;
T_5 V_218 = 0 ;
if ( F_20 ( V_219 , & V_146 -> V_220 ) )
V_213 = 0 ;
if ( F_20 ( V_221 , & V_146 -> V_220 ) )
V_214 = 0 ;
if ( F_20 ( V_222 , & V_146 -> V_220 ) ) {
V_213 = 0 ;
V_215 = 1 ;
}
if ( F_20 ( V_223 , & V_146 -> V_220 ) ) {
V_214 = 0 ;
V_217 = 1 ;
}
if ( F_20 ( V_224 , & V_146 -> V_220 ) )
V_216 = 1 ;
if ( F_20 ( V_225 , & V_146 -> V_220 ) )
V_218 = 1 ;
V_207 -> V_226 = V_213 ?
V_207 -> V_226 | V_212 :
V_207 -> V_226 & ~ V_212 ;
V_207 -> V_227 = V_214 ?
V_207 -> V_227 | V_212 :
V_207 -> V_227 & ~ V_212 ;
V_207 -> V_228 = V_215 ?
V_207 -> V_228 | V_212 :
V_207 -> V_228 & ~ V_212 ;
V_207 -> V_229 = V_217 ?
V_207 -> V_229 | V_212 :
V_207 -> V_229 & ~ V_212 ;
V_207 -> V_230 = V_216 ?
V_207 -> V_230 | V_212 :
V_207 -> V_230 & ~ V_212 ;
V_207 -> V_218 = V_218 ?
V_207 -> V_218 | V_212 :
V_207 -> V_218 & ~ V_212 ;
F_4 ( V_17 , L_44
L_45 ,
V_207 -> V_226 ,
V_207 -> V_227 ,
V_207 -> V_228 ,
V_207 -> V_229 ,
V_207 -> V_230 ) ;
F_114 ( V_2 , V_207 , V_146 -> V_86 ) ;
F_30 ( V_146 -> V_33 , V_146 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_118 ( T_6 V_90 ,
struct V_91 * V_83 ,
T_5 V_92 )
{
V_83 -> V_93 = V_90 ;
V_83 -> V_92 = V_92 ;
}
static inline void F_119 ( struct V_1 * V_2 ,
unsigned long V_231 ,
struct V_232 * V_100 ,
bool V_233 )
{
T_7 V_33 ;
V_33 = V_234 |
V_235 ;
if ( V_231 ) {
if ( F_20 ( V_219 , & V_231 ) )
V_33 &= ~ V_234 ;
if ( F_20 ( V_221 , & V_231 ) )
V_33 &= ~ V_235 ;
if ( F_20 ( V_222 , & V_231 ) ) {
V_33 &= ~ V_234 ;
V_33 |= V_236 ;
}
if ( F_20 ( V_223 , & V_231 ) ) {
V_33 |= V_237 ;
V_33 &= ~ V_235 ;
}
if ( F_20 ( V_224 , & V_231 ) )
V_33 |= V_238 ;
if ( F_20 ( V_225 , & V_231 ) ) {
V_33 &= ~ V_234 ;
V_33 |= V_239 ;
}
if ( F_20 ( V_240 , & V_231 ) )
V_33 |= V_241 ;
}
if ( V_233 ) {
V_33 &= ~ V_237 ;
V_33 &= ~ V_238 ;
V_33 &= ~ V_236 ;
V_33 &= ~ V_239 ;
}
V_100 -> V_33 = F_73 ( V_33 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_211 * V_146 )
{
struct V_242 * V_50 = V_146 -> V_99 ;
int V_22 ;
T_5 V_96 = 0 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
if ( F_20 ( V_243 , & V_146 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = V_146 -> V_85 ;
V_50 -> V_104 [ V_96 ] . V_86 = V_146 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_244 ;
F_119 ( V_2 , V_146 -> V_245 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) , false ) ;
}
if ( F_20 ( V_246 , & V_146 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = V_146 -> V_85 ;
V_50 -> V_104 [ V_96 ] . V_86 = V_146 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_247 ;
F_119 ( V_2 , V_146 -> V_220 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) , false ) ;
}
if ( F_20 ( V_248 , & V_146 -> V_249 ) ) {
if ( F_20 ( V_243 , & V_146 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = F_121 ( V_2 , V_85 ) ;
V_50 -> V_104 [ V_96 ] . V_86 = V_146 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_244 ;
F_119 ( V_2 , V_146 -> V_245 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) ,
true ) ;
}
if ( F_20 ( V_246 , & V_146 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = F_121 ( V_2 , V_85 ) ;
V_50 -> V_104 [ V_96 ] . V_86 = V_146 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_247 ;
F_119 ( V_2 , V_146 -> V_220 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) ,
true ) ;
}
}
F_118 ( V_146 -> V_90 , & V_50 -> V_113 , V_96 ) ;
F_4 ( V_17 , L_46
L_47 ,
V_50 -> V_113 . V_92 , V_146 -> V_220 ,
V_146 -> V_245 ) ;
V_22 = F_98 ( V_2 , V_250 , V_146 -> V_90 ,
F_99 ( V_146 -> V_188 ) ,
F_100 ( V_146 -> V_188 ) ,
V_189 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_211 * V_146 )
{
return F_34 ( V_2 , V_146 -> V_33 , V_146 -> V_34 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_211 * V_146 )
{
return 0 ;
}
int F_124 ( struct V_1 * V_2 ,
struct V_211 * V_146 )
{
int V_22 ;
V_22 = V_146 -> V_251 -> V_252 ( V_2 , V_146 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_20 ( V_193 , & V_146 -> V_25 ) ) {
V_22 = V_146 -> V_251 -> V_167 ( V_2 , V_146 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_125 ( struct V_1 * V_2 ,
struct V_253 * V_4 )
{
if ( F_108 ( V_2 ) ) {
V_4 -> V_167 = F_123 ;
V_4 -> V_252 = F_117 ;
} else {
V_4 -> V_167 = F_122 ;
V_4 -> V_252 = F_120 ;
}
}
static inline T_5 F_126 ( T_5 * V_53 )
{
return ( F_127 ( 0 , V_53 , V_56 ) >> 24 ) & 0xff ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_254 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_255 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_167 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_254 * V_4 ,
struct V_256 * V_146 ,
int V_100 )
{
int V_257 ;
struct V_258 * V_259 ;
struct V_260 * V_261 = NULL ;
struct V_262 * V_52 ;
int V_263 = ( ( V_100 == V_264 ) ?
V_146 -> V_265 : 0 ) ;
if ( ! V_146 -> V_265 )
return 0 ;
V_257 = sizeof( * V_259 ) +
V_263 * sizeof( struct V_260 ) ;
V_259 = F_26 ( V_257 , V_31 ) ;
if ( ! V_259 )
return - V_176 ;
F_4 ( V_17 , L_48
L_49 , V_100 , V_263 ) ;
F_2 ( & V_259 -> V_50 . V_266 ) ;
V_259 -> type = V_100 ;
V_259 -> V_267 = false ;
switch ( V_100 ) {
case V_264 :
V_261 = (struct V_260 * )
( ( T_5 * ) V_259 + sizeof( * V_259 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_261 -> V_53 , V_52 -> V_53 , V_56 ) ;
F_13 ( & V_261 -> V_24 , & V_259 -> V_50 . V_266 ) ;
V_261 ++ ;
}
break;
case V_268 :
V_259 -> V_50 . V_269 = V_146 -> V_265 ;
break;
case V_270 :
V_259 -> V_50 . V_271 = 0 ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return - V_54 ;
}
F_13 ( & V_259 -> V_24 , & V_4 -> V_272 ) ;
V_4 -> V_273 ( V_4 ) ;
return 1 ;
}
static inline int F_130 ( struct V_254 * V_4 , int V_274 )
{
int V_275 , V_276 , V_277 = V_274 % V_278 ;
for ( V_275 = V_274 / V_278 ; V_275 < V_279 ; V_275 ++ ) {
if ( V_4 -> V_280 . V_281 . V_282 [ V_275 ] )
for ( V_276 = V_277 ; V_276 < V_278 ; V_276 ++ ) {
int V_283 = V_276 + V_278 * V_275 ;
if ( F_131 ( V_4 -> V_280 . V_281 .
V_282 , V_283 ) ) {
return V_283 ;
}
}
V_277 = 0 ;
}
return - 1 ;
}
static inline int F_132 ( struct V_254 * V_4 )
{
int V_283 = F_130 ( V_4 , 0 ) ;
if ( V_283 >= 0 )
F_133 ( V_4 -> V_280 . V_281 . V_282 , V_283 ) ;
return V_283 ;
}
static inline T_5 F_134 ( struct V_254 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_5 V_64 = 0 ;
if ( ( V_38 -> V_65 == V_66 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_284 ;
if ( ( V_38 -> V_65 == V_69 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_285 ;
return V_64 ;
}
static void F_135 ( struct V_1 * V_2 ,
struct V_254 * V_4 , int V_181 ,
union V_286 * V_287 ,
int V_100 )
{
struct V_32 * V_119 = & V_4 -> V_38 ;
struct V_288 * V_50 =
(struct V_288 * ) ( V_119 -> V_99 ) ;
T_5 V_86 = V_119 -> V_86 ;
T_5 V_289 = F_134 ( V_4 ) ;
int V_290 ;
if ( ( V_100 == V_264 ) || ( V_100 == V_270 ) )
V_289 |= V_291 ;
V_50 -> V_104 [ V_181 ] . V_87 |= V_289 ;
switch ( V_100 ) {
case V_264 :
V_290 = F_126 ( V_287 -> V_53 ) ;
F_136 ( V_4 -> V_280 . V_281 . V_282 , V_290 ) ;
break;
case V_268 :
V_290 = F_132 ( V_4 ) ;
break;
case V_270 :
V_290 = V_287 -> V_290 ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return;
}
F_4 ( V_17 , L_51 ,
( ( V_289 & V_291 ) ?
L_52 : L_53 ) , V_290 ) ;
V_50 -> V_104 [ V_181 ] . V_292 = ( T_5 ) V_290 ;
V_50 -> V_104 [ V_181 ] . V_86 = V_86 ;
V_50 -> V_104 [ V_181 ] . V_293 = V_4 -> V_293 ;
}
static inline int F_137 (
struct V_1 * V_2 , struct V_254 * V_4 , int V_294 ,
int * V_295 )
{
int V_296 , V_20 = * V_295 ;
union V_286 V_287 = { 0 } ;
for ( V_296 = F_130 ( V_4 , V_294 ) ; V_296 >= 0 ;
V_296 = F_130 ( V_4 , V_296 + 1 ) ) {
V_287 . V_290 = ( T_5 ) V_296 ;
V_4 -> V_186 ( V_2 , V_4 , V_20 , & V_287 ,
V_270 ) ;
V_20 ++ ;
F_4 ( V_17 , L_54 , V_296 ) ;
if ( V_20 >= V_4 -> V_297 )
break;
}
* V_295 = V_20 ;
return V_296 ;
}
static inline void F_138 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_258 * V_298 ,
int * V_299 )
{
struct V_260 * V_300 , * V_301 ;
int V_20 = * V_299 ;
union V_286 V_287 = { 0 } ;
F_103 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_287 . V_53 = & V_300 -> V_53 [ 0 ] ;
V_4 -> V_186 ( V_2 , V_4 , V_20 , & V_287 , V_298 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_55 ,
V_300 -> V_53 ) ;
F_17 ( & V_300 -> V_24 ) ;
if ( V_20 >= V_4 -> V_297 )
break;
}
* V_299 = V_20 ;
if ( F_15 ( & V_298 -> V_50 . V_266 ) )
V_298 -> V_267 = true ;
}
static inline void F_139 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_258 * V_298 ,
int * V_299 )
{
int V_20 = * V_299 ;
while ( V_298 -> V_50 . V_269 ) {
V_4 -> V_186 ( V_2 , V_4 , V_20 , NULL , V_298 -> type ) ;
V_20 ++ ;
V_298 -> V_50 . V_269 -- ;
F_4 ( V_17 , L_56 ,
V_298 -> V_50 . V_269 , V_20 ) ;
if ( V_20 >= V_4 -> V_297 )
break;
}
* V_299 = V_20 ;
if ( ! V_298 -> V_50 . V_269 )
V_298 -> V_267 = true ;
}
static inline void F_140 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_258 * V_298 ,
int * V_299 )
{
V_298 -> V_50 . V_271 = V_4 -> V_302 ( V_2 , V_4 , V_298 -> V_50 . V_271 ,
V_299 ) ;
if ( V_298 -> V_50 . V_271 < 0 )
V_298 -> V_267 = true ;
else
V_298 -> V_50 . V_271 ++ ;
}
static inline int F_141 ( struct V_1 * V_2 ,
struct V_256 * V_146 )
{
struct V_258 * V_298 , * V_303 ;
int V_20 = 0 ;
struct V_254 * V_4 = V_146 -> V_304 ;
F_103 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_298 -> type ) {
case V_264 :
F_138 ( V_2 , V_4 , V_298 , & V_20 ) ;
break;
case V_268 :
F_139 ( V_2 , V_4 , V_298 , & V_20 ) ;
break;
case V_270 :
F_140 ( V_2 , V_4 , V_298 ,
& V_20 ) ;
break;
default:
F_12 ( L_50 , V_298 -> type ) ;
return - V_54 ;
}
if ( V_298 -> V_267 ) {
F_17 ( & V_298 -> V_24 ) ;
F_6 ( V_298 ) ;
}
if ( V_20 >= V_4 -> V_297 )
break;
}
return V_20 ;
}
static inline void F_142 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_256 * V_146 ,
int * V_299 )
{
struct V_262 * V_305 ;
union V_286 V_287 = { 0 } ;
int V_20 = * V_299 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_287 . V_53 = V_305 -> V_53 ;
V_4 -> V_186 ( V_2 , V_4 , V_20 , & V_287 , V_264 ) ;
V_20 ++ ;
F_4 ( V_17 , L_55 ,
V_305 -> V_53 ) ;
}
* V_299 = V_20 ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_256 * V_146 ,
int * V_299 )
{
int V_20 = * V_299 , V_275 ;
for ( V_275 = 0 ; V_275 < V_146 -> V_265 ; V_275 ++ ) {
V_4 -> V_186 ( V_2 , V_4 , V_20 , NULL , V_268 ) ;
V_20 ++ ;
F_4 ( V_17 , L_57 ,
V_146 -> V_265 - V_275 - 1 ) ;
}
* V_299 = V_20 ;
}
static inline int F_144 ( struct V_1 * V_2 ,
struct V_256 * V_146 , int V_100 ,
int V_306 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
int V_20 = V_306 ;
F_4 ( V_17 , L_58 , V_146 -> V_265 ) ;
switch ( V_100 ) {
case V_264 :
F_142 ( V_2 , V_4 , V_146 , & V_20 ) ;
break;
case V_268 :
F_143 ( V_2 , V_4 , V_146 , & V_20 ) ;
break;
case V_270 :
V_4 -> V_302 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return - V_54 ;
}
V_146 -> V_265 = 0 ;
return V_20 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
int V_307 = V_4 -> V_308 ( V_4 ) ;
switch ( V_100 ) {
case V_268 :
V_4 -> V_309 ( V_4 , 0 ) ;
case V_270 :
V_146 -> V_265 = V_307 ;
break;
case V_264 :
case V_310 :
V_4 -> V_309 ( V_4 , V_307 + V_146 -> V_265 ) ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return - V_54 ;
}
V_4 -> V_311 += V_146 -> V_265 ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_312 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
V_4 -> V_309 ( V_4 , V_312 ) ;
V_4 -> V_311 -= V_146 -> V_265 ;
}
static inline void F_147 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
T_5 V_313 )
{
struct V_32 * V_119 = & V_146 -> V_304 -> V_38 ;
struct V_288 * V_50 =
(struct V_288 * ) ( V_119 -> V_99 ) ;
V_50 -> V_113 . V_93 = ( ( V_119 -> V_90 & V_94 ) |
( V_314 << V_95 ) ) ;
V_50 -> V_113 . V_92 = V_313 ;
}
static inline int F_148 ( struct V_1 * V_2 ,
struct V_254 * V_4 )
{
int V_275 , V_20 = 0 ;
T_11 V_19 ;
for ( V_275 = 0 ; V_275 < V_279 ; V_275 ++ ) {
V_19 = V_4 -> V_280 . V_281 . V_282 [ V_275 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_309 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
struct V_32 * V_38 = & V_146 -> V_304 -> V_38 ;
struct V_254 * V_4 = V_146 -> V_304 ;
struct V_288 * V_50 =
(struct V_288 * ) ( V_38 -> V_99 ) ;
int V_20 = 0 , V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_20 = F_141 ( V_2 , V_146 ) ;
if ( F_15 ( & V_4 -> V_272 ) )
V_4 -> V_315 ( V_4 ) ;
if ( V_146 -> V_265 > 0 )
V_20 = F_144 ( V_2 , V_146 , V_100 , V_20 ) ;
V_4 -> V_311 -= V_20 ;
F_21 ( V_4 -> V_311 < 0 ) ;
F_21 ( V_20 > V_4 -> V_297 ) ;
F_147 ( V_2 , V_146 , ( T_5 ) V_20 ) ;
if ( ! V_4 -> V_311 )
F_148 ( V_2 , V_4 ) ;
if ( F_20 ( V_28 , & V_146 -> V_25 ) ) {
V_38 -> V_170 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_98 ( V_2 , V_316 ,
V_38 -> V_90 , F_99 ( V_38 -> V_188 ) ,
F_100 ( V_38 -> V_188 ) ,
V_189 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_150 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
if ( ( V_100 == V_268 ) || ( V_100 == V_270 ) )
V_146 -> V_265 = 1 ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_312 )
{
}
static inline void F_152 ( struct V_1 * V_2 ,
struct V_254 * V_4 ,
struct V_256 * V_146 ,
T_6 * V_317 )
{
struct V_262 * V_305 ;
int V_318 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_318 = F_126 ( V_305 -> V_53 ) ;
F_153 ( V_317 , V_318 ) ;
F_4 ( V_17 , L_59 ,
V_305 -> V_53 , V_318 ) ;
F_136 ( V_4 -> V_280 . V_281 . V_282 ,
V_318 ) ;
}
}
static inline void F_154 ( struct V_1 * V_2 ,
struct V_254 * V_4 , struct V_256 * V_146 ,
T_6 * V_317 )
{
int V_318 ;
for ( V_318 = F_130 ( V_4 , 0 ) ;
V_318 >= 0 ;
V_318 = F_130 ( V_4 , V_318 + 1 ) ) {
F_153 ( V_317 , V_318 ) ;
F_4 ( V_17 , L_60 , V_318 ) ;
}
}
static int F_155 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
int V_275 ;
struct V_254 * V_4 = V_146 -> V_304 ;
struct V_32 * V_119 = & V_4 -> V_38 ;
if ( ! F_20 ( V_28 , & V_146 -> V_25 ) ) {
T_6 V_317 [ V_319 ] = { 0 } ;
switch ( V_100 ) {
case V_264 :
F_152 ( V_2 , V_4 , V_146 , V_317 ) ;
break;
case V_268 :
F_4 ( V_17 ,
L_61 ) ;
memset ( V_4 -> V_280 . V_281 . V_282 , 0 ,
sizeof( V_4 -> V_280 . V_281 . V_282 ) ) ;
break;
case V_270 :
F_154 ( V_2 , V_4 , V_146 , V_317 ) ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return - V_54 ;
}
for ( V_275 = 0 ; V_275 < V_319 ; V_275 ++ )
F_65 ( V_2 , F_156 ( V_2 , V_275 ) , V_317 [ V_275 ] ) ;
} else
memset ( V_4 -> V_280 . V_281 . V_282 , 0 ,
sizeof( V_4 -> V_280 . V_281 . V_282 ) ) ;
V_119 -> V_170 ( V_119 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
int V_307 = V_4 -> V_308 ( V_4 ) ;
switch ( V_100 ) {
case V_268 :
V_4 -> V_309 ( V_4 , 0 ) ;
case V_270 :
V_146 -> V_265 = V_307 ;
F_4 ( V_17 , L_62 ,
V_100 , V_146 -> V_265 ) ;
break;
case V_264 :
case V_310 :
if ( V_146 -> V_265 > V_4 -> V_297 ) {
F_12 ( L_63
L_64 , V_4 -> V_297 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_58 , V_146 -> V_265 ) ;
if ( V_146 -> V_265 > 0 )
V_4 -> V_309 ( V_4 , V_146 -> V_265 ) ;
break;
default:
F_12 ( L_50 , V_100 ) ;
return - V_54 ;
}
if ( V_146 -> V_265 )
V_4 -> V_311 += V_4 -> V_297 ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_320 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
V_4 -> V_309 ( V_4 , V_320 ) ;
if ( V_146 -> V_265 )
V_4 -> V_311 -= V_4 -> V_297 ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_254 * V_4 , int V_181 ,
union V_286 * V_287 ,
int V_100 )
{
struct V_32 * V_119 = & V_4 -> V_38 ;
struct V_135 * V_50 =
(struct V_135 * ) ( V_119 -> V_99 ) ;
if ( ( V_100 == V_264 ) || ( V_100 == V_270 ) ) {
F_69 ( & V_50 -> V_137 [ V_181 ] . V_131 ,
& V_50 -> V_137 [ V_181 ] . V_132 ,
& V_50 -> V_137 [ V_181 ] . V_133 ,
V_287 -> V_53 ) ;
V_50 -> V_137 [ V_181 ] . V_121 = 0 ;
V_50 -> V_137 [ V_181 ] . V_126 = V_119 -> V_86 ;
V_50 -> V_137 [ V_181 ] . V_125 =
F_72 ( 1 << V_119 -> V_85 ) ;
F_74 ( V_50 -> V_137 [ V_181 ] . V_127 ,
V_128 ,
V_129 ) ;
}
}
static inline void F_160 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
T_5 V_313 )
{
struct V_32 * V_119 = & V_146 -> V_304 -> V_38 ;
struct V_135 * V_50 =
(struct V_135 * ) ( V_119 -> V_99 ) ;
T_5 V_40 = ( F_161 ( V_2 ) ?
V_321 * ( 1 + V_119 -> V_86 ) :
V_322 * ( 1 + V_119 -> V_86 ) ) ;
V_50 -> V_83 . V_40 = V_40 ;
V_50 -> V_83 . V_84 = 0xff ;
V_50 -> V_83 . V_93 = ( ( V_119 -> V_90 & V_94 ) |
( V_314 << V_95 ) ) ;
V_50 -> V_83 . V_120 = V_313 ;
}
static inline int F_162 (
struct V_1 * V_2 , struct V_254 * V_4 , int V_323 ,
int * V_295 )
{
struct V_260 * V_19 ;
int V_275 = 0 ;
union V_286 V_287 = { 0 } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_287 . V_53 = & V_19 -> V_53 [ 0 ] ;
V_4 -> V_186 ( V_2 , V_4 , V_275 , & V_287 , V_270 ) ;
V_275 ++ ;
F_4 ( V_17 , L_55 ,
V_287 . V_53 ) ;
}
* V_295 = V_275 ;
return - 1 ;
}
static inline int F_163 (
struct V_1 * V_2 , struct V_256 * V_146 )
{
struct V_258 * V_298 ;
struct V_260 * V_300 ;
struct V_254 * V_4 = V_146 -> V_304 ;
union V_286 V_287 = { 0 } ;
int V_20 = 0 ;
if ( F_15 ( & V_4 -> V_272 ) )
return 0 ;
V_298 = F_16 ( & V_4 -> V_272 ,
struct V_258 , V_24 ) ;
switch ( V_298 -> type ) {
case V_264 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_287 . V_53 = & V_300 -> V_53 [ 0 ] ;
V_4 -> V_186 ( V_2 , V_4 , V_20 , & V_287 , V_298 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_55 ,
V_300 -> V_53 ) ;
}
break;
case V_268 :
V_20 = V_298 -> V_50 . V_269 ;
F_4 ( V_17 , L_65 , V_20 ) ;
break;
case V_270 :
V_4 -> V_302 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_50 , V_298 -> type ) ;
return - V_54 ;
}
F_17 ( & V_298 -> V_24 ) ;
F_6 ( V_298 ) ;
return V_20 ;
}
static inline void F_164 ( T_12 * V_324 , T_12 * V_325 ,
T_12 * V_326 , T_5 * V_53 )
{
V_53 [ 1 ] = ( ( T_5 * ) V_324 ) [ 0 ] ;
V_53 [ 0 ] = ( ( T_5 * ) V_324 ) [ 1 ] ;
V_53 [ 3 ] = ( ( T_5 * ) V_325 ) [ 0 ] ;
V_53 [ 2 ] = ( ( T_5 * ) V_325 ) [ 1 ] ;
V_53 [ 5 ] = ( ( T_5 * ) V_326 ) [ 0 ] ;
V_53 [ 4 ] = ( ( T_5 * ) V_326 ) [ 1 ] ;
}
static inline int F_165 ( struct V_1 * V_2 ,
struct V_254 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_260 * V_19 ;
struct V_135 * V_50 =
(struct V_135 * ) ( V_38 -> V_99 ) ;
if ( F_166 ( V_50 -> V_137 [ 0 ] . V_127 ,
V_128 ) ) {
int V_275 , V_313 = V_50 -> V_83 . V_120 ;
if ( ! F_15 ( & V_4 -> V_280 . V_327 . V_328 ) )
return 0 ;
V_19 = F_26 ( sizeof( * V_19 ) * V_313 , V_31 ) ;
if ( ! V_19 ) {
F_12 ( L_66 ) ;
return - V_176 ;
}
for ( V_275 = 0 ; V_275 < V_313 ; V_275 ++ , V_19 ++ ) {
F_164 (
& V_50 -> V_137 [ V_275 ] . V_131 ,
& V_50 -> V_137 [ V_275 ] . V_132 ,
& V_50 -> V_137 [ V_275 ] . V_133 ,
V_19 -> V_53 ) ;
F_4 ( V_17 , L_67 ,
V_19 -> V_53 ) ;
F_13 ( & V_19 -> V_24 ,
& V_4 -> V_280 . V_327 . V_328 ) ;
}
} else {
V_19 = F_16 ( & V_4 -> V_280 . V_327 . V_328 ,
struct V_260 , V_24 ) ;
F_4 ( V_17 , L_68 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_280 . V_327 . V_328 ) ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_135 * V_50 =
(struct V_135 * ) ( V_38 -> V_99 ) ;
int V_20 = 0 , V_275 , V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
for ( V_275 = 0 ; V_275 < V_4 -> V_297 ; V_275 ++ )
F_74 ( V_50 -> V_137 [ V_275 ] . V_127 ,
V_128 ,
V_134 ) ;
V_20 = F_163 ( V_2 , V_146 ) ;
if ( F_15 ( & V_4 -> V_272 ) )
V_4 -> V_315 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_144 ( V_2 , V_146 , V_100 , 0 ) ;
V_4 -> V_311 -= V_4 -> V_297 ;
F_21 ( V_20 > V_4 -> V_297 ) ;
F_160 ( V_2 , V_146 , ( T_5 ) V_20 ) ;
V_22 = F_165 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_20 ( V_28 , & V_146 -> V_25 ) ) {
V_38 -> V_170 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_98 ( V_2 , V_202 , V_38 -> V_90 ,
F_99 ( V_38 -> V_188 ) ,
F_100 ( V_38 -> V_188 ) ,
V_189 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_168 ( struct V_254 * V_4 )
{
return V_4 -> V_280 . V_327 . V_329 ;
}
static int F_169 ( struct V_254 * V_4 )
{
return V_4 -> V_280 . V_281 . V_330 ;
}
static void F_170 ( struct V_254 * V_4 ,
int V_331 )
{
V_4 -> V_280 . V_327 . V_329 = V_331 ;
}
static void F_171 ( struct V_254 * V_4 ,
int V_331 )
{
V_4 -> V_280 . V_281 . V_330 = V_331 ;
}
int F_172 ( struct V_1 * V_2 ,
struct V_256 * V_146 ,
int V_100 )
{
struct V_254 * V_4 = V_146 -> V_304 ;
struct V_32 * V_119 = & V_4 -> V_38 ;
int V_22 = 0 , V_332 ;
V_332 = V_4 -> V_308 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_146 , V_100 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_146 -> V_265 ) && ( ! V_4 -> V_333 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_69
L_70 , V_4 -> V_311 ,
V_146 -> V_265 , V_4 -> V_297 ) ;
if ( V_119 -> V_183 ( V_119 ) ||
( ( V_4 -> V_297 > 0 ) && ( V_4 -> V_311 > V_4 -> V_297 ) ) ) {
V_22 = V_4 -> V_334 ( V_2 , V_146 -> V_304 , V_146 , V_100 ) ;
if ( V_22 < 0 )
goto V_335;
V_146 -> V_265 = 0 ;
}
if ( ! V_119 -> V_183 ( V_119 ) ) {
V_119 -> V_184 ( V_119 ) ;
V_22 = V_4 -> V_336 ( V_2 , V_146 , V_100 ) ;
if ( V_22 < 0 )
goto V_337;
if ( F_20 ( V_193 , & V_146 -> V_25 ) )
V_22 = V_4 -> V_167 ( V_2 , V_4 ) ;
}
return V_22 ;
V_337:
V_119 -> V_170 ( V_119 ) ;
V_335:
V_4 -> V_338 ( V_2 , V_146 , V_332 ) ;
return V_22 ;
}
static void F_173 ( struct V_254 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_255 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_174 ( struct V_254 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_255 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_175 ( struct V_254 * V_4 )
{
return ! ! F_20 ( V_4 -> V_255 , V_4 -> V_38 . V_34 ) ;
}
static bool F_176 ( struct V_254 * V_4 )
{
return V_4 -> V_38 . V_183 ( & V_4 -> V_38 ) || V_4 -> V_333 ( V_4 ) ;
}
void F_177 ( struct V_1 * V_2 ,
struct V_254 * V_304 ,
T_5 V_339 , T_6 V_340 , T_5 V_86 ,
T_5 V_293 , void * V_99 , T_8 V_188 ,
int V_33 , unsigned long * V_34 , T_9 type )
{
memset ( V_304 , 0 , sizeof( * V_304 ) ) ;
F_105 ( & V_304 -> V_38 , V_339 , V_340 , V_86 ,
V_99 , V_188 , V_33 , V_34 , type ) ;
V_304 -> V_293 = V_293 ;
F_2 ( & V_304 -> V_272 ) ;
V_304 -> V_255 = V_341 ;
V_304 -> V_333 = F_175 ;
V_304 -> V_273 = F_174 ;
V_304 -> V_315 = F_173 ;
if ( F_112 ( V_2 ) ) {
V_304 -> V_336 = F_167 ;
V_304 -> V_334 = F_129 ;
V_304 -> V_302 =
F_162 ;
V_304 -> V_183 = F_176 ;
if ( F_161 ( V_2 ) )
V_304 -> V_297 = V_321 ;
else
V_304 -> V_297 = V_322 ;
V_304 -> V_167 = F_128 ;
V_304 -> V_186 = F_159 ;
V_304 -> V_8 = F_157 ;
V_304 -> V_338 = F_158 ;
V_304 -> V_308 =
F_168 ;
V_304 -> V_309 =
F_170 ;
F_2 ( & V_304 -> V_280 . V_327 . V_328 ) ;
} else if ( F_113 ( V_2 ) ) {
V_304 -> V_336 = F_155 ;
V_304 -> V_334 = NULL ;
V_304 -> V_302 = NULL ;
V_304 -> V_183 = F_176 ;
V_304 -> V_297 = - 1 ;
V_304 -> V_167 = F_128 ;
V_304 -> V_186 = NULL ;
V_304 -> V_8 = F_150 ;
V_304 -> V_338 = F_151 ;
V_304 -> V_308 =
F_169 ;
V_304 -> V_309 =
F_171 ;
} else {
V_304 -> V_336 = F_149 ;
V_304 -> V_334 = F_129 ;
V_304 -> V_302 =
F_137 ;
V_304 -> V_183 = F_176 ;
V_304 -> V_297 = 16 ;
V_304 -> V_167 = F_128 ;
V_304 -> V_186 = F_135 ;
V_304 -> V_8 = F_145 ;
V_304 -> V_338 = F_146 ;
V_304 -> V_308 =
F_169 ;
V_304 -> V_309 =
F_171 ;
}
}
static inline bool F_178 ( T_13 * V_342 , int V_343 , int V_55 )
{
int V_344 , V_345 ;
V_344 = F_179 ( V_342 ) ;
for (; ; ) {
if ( F_180 ( V_344 + V_343 >= V_55 ) )
return false ;
V_345 = F_181 ( ( V_342 ) , V_344 , V_344 + V_343 ) ;
if ( F_182 ( V_345 == V_344 ) )
break;
V_344 = V_345 ;
}
return true ;
}
static inline bool F_183 ( T_13 * V_342 , int V_343 , int V_55 )
{
int V_344 , V_345 ;
V_344 = F_179 ( V_342 ) ;
for (; ; ) {
if ( F_180 ( V_344 - V_343 < V_55 ) )
return false ;
V_345 = F_181 ( ( V_342 ) , V_344 , V_344 - V_343 ) ;
if ( F_182 ( V_345 == V_344 ) )
break;
V_344 = V_345 ;
}
return true ;
}
static bool F_184 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_185 () ;
V_22 = F_183 ( & V_4 -> V_346 , V_20 , 0 ) ;
F_185 () ;
return V_22 ;
}
static bool F_186 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_185 () ;
V_22 = F_178 ( & V_4 -> V_346 , V_20 , V_4 -> V_347 + 1 ) ;
F_185 () ;
return V_22 ;
}
static int F_187 ( struct V_41 * V_4 )
{
int V_348 ;
F_185 () ;
V_348 = F_179 ( & V_4 -> V_346 ) ;
return V_348 ;
}
static bool F_188 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_189 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_181 , V_282 , V_275 ;
* V_40 = - 1 ;
for ( V_282 = 0 ; V_282 < V_349 ; V_282 ++ ) {
if ( ! V_4 -> V_350 [ V_282 ] )
continue;
for ( V_181 = V_282 * V_349 , V_275 = 0 ;
V_275 < V_278 ; V_181 ++ , V_275 ++ )
if ( F_131 ( V_4 -> V_350 , V_181 ) ) {
F_133 ( V_4 -> V_350 , V_181 ) ;
* V_40 = V_4 -> V_351 + V_181 ;
return true ;
}
}
return false ;
}
static bool F_190 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_351 )
return false ;
V_40 -= V_4 -> V_351 ;
if ( V_40 >= V_4 -> V_347 )
return false ;
F_136 ( V_4 -> V_350 , V_40 ) ;
return true ;
}
static bool F_191 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_192 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_193 ( struct V_41 * V_146 ,
int V_352 , int V_346 )
{
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
memset ( & V_146 -> V_350 , 0xff , sizeof( V_146 -> V_350 ) ) ;
F_194 ( & V_146 -> V_346 , V_346 ) ;
V_146 -> V_347 = V_346 ;
V_146 -> V_351 = V_352 ;
F_185 () ;
V_146 -> V_353 = F_187 ;
if ( V_346 >= 0 ) {
V_146 -> V_47 = F_186 ;
V_146 -> V_11 = F_184 ;
V_146 -> V_48 = F_190 ;
V_146 -> V_44 = F_189 ;
} else {
V_146 -> V_47 = F_188 ;
V_146 -> V_11 = F_188 ;
V_146 -> V_48 = F_191 ;
V_146 -> V_44 = F_192 ;
}
if ( V_352 < 0 ) {
V_146 -> V_48 = F_191 ;
V_146 -> V_44 = F_192 ;
}
}
void F_195 ( struct V_1 * V_2 ,
struct V_41 * V_146 , T_5 V_86 ,
T_5 V_354 )
{
#define F_196 5
int V_355 ;
if ( F_112 ( V_2 ) ) {
if ( ! F_161 ( V_2 ) )
V_355 = ( V_356 / 2 ) - V_322 ;
else
V_355 = F_196 - V_321 ;
F_193 ( V_146 , V_86 * V_355 , V_355 ) ;
} else if ( F_113 ( V_2 ) ) {
if ( ( V_354 > 0 ) ) {
if ( ! F_161 ( V_2 ) )
V_355 = ( V_357 / ( 2 * V_354 ) ) ;
else
V_355 = F_196 ;
F_193 ( V_146 , V_86 * V_355 , V_355 ) ;
} else {
F_193 ( V_146 , 0 , 0 ) ;
}
} else {
if ( ( V_354 > 0 ) ) {
if ( ! F_161 ( V_2 ) )
V_355 = ( V_358 / V_354 ) ;
else
V_355 = F_196 ;
F_193 ( V_146 , - 1 , V_355 ) ;
} else {
F_193 ( V_146 , 0 , 0 ) ;
}
}
}
void F_197 ( struct V_1 * V_2 ,
struct V_41 * V_146 ,
T_5 V_86 ,
T_5 V_354 )
{
if ( F_108 ( V_2 ) ) {
F_193 ( V_146 , 0 , - 1 ) ;
} else {
if ( V_354 > 0 ) {
int V_346 = V_359 / V_354 ;
F_193 ( V_146 , V_86 * V_346 , V_346 ) ;
} else
F_193 ( V_146 , 0 , 0 ) ;
}
}
static inline void F_198 ( struct V_1 * V_2 ,
struct V_360 * V_146 )
{
int V_275 ;
F_4 ( V_17 , L_71 ) ;
F_4 ( V_17 , L_72 ) ;
for ( V_275 = 0 ; V_275 < V_361 ; V_275 ++ ) {
F_199 ( V_17 , L_73 , V_146 -> V_362 [ V_275 ] ) ;
if ( ( V_275 + 1 < V_361 ) &&
( ( ( V_275 + 1 ) & 0x3 ) == 0 ) ) {
F_199 ( V_17 , L_74 ) ;
F_4 ( V_17 , L_75 , V_275 + 1 ) ;
}
}
F_199 ( V_17 , L_74 ) ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_360 * V_146 )
{
struct V_363 * V_4 = V_146 -> V_364 ;
struct V_32 * V_119 = & V_4 -> V_38 ;
struct V_365 * V_50 =
(struct V_365 * ) ( V_119 -> V_99 ) ;
T_5 V_366 = 0 ;
int V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_4 ( V_17 , L_76 ) ;
V_50 -> V_93 = ( V_119 -> V_90 & V_94 ) |
( V_119 -> V_33 << V_95 ) ;
if ( F_20 ( V_367 , & V_146 -> V_368 ) )
V_366 = V_369 ;
else if ( F_20 ( V_370 , & V_146 -> V_368 ) )
V_366 = V_371 ;
else if ( F_20 ( V_372 , & V_146 -> V_368 ) )
V_366 = V_373 ;
else if ( F_20 ( V_374 , & V_146 -> V_368 ) )
V_366 = V_375 ;
else if ( F_20 ( V_376 , & V_146 -> V_368 ) )
V_366 = V_377 ;
V_50 -> V_366 = V_366 ;
F_4 ( V_17 , L_77 , V_366 ) ;
if ( F_20 ( V_378 , & V_146 -> V_368 ) )
V_50 -> V_379 |=
V_380 ;
if ( F_20 ( V_381 , & V_146 -> V_368 ) )
V_50 -> V_379 |=
V_382 ;
if ( F_20 ( V_383 , & V_146 -> V_368 ) )
V_50 -> V_379 |=
V_384 ;
if ( F_20 ( V_385 , & V_146 -> V_368 ) )
V_50 -> V_379 |=
V_386 ;
V_50 -> V_387 = V_146 -> V_387 ;
V_50 -> V_388 = V_4 -> V_293 ;
F_4 ( V_17 , L_78 , V_50 -> V_388 ) ;
memcpy ( V_50 -> V_389 , V_146 -> V_362 ,
V_361 ) ;
memcpy ( V_4 -> V_362 , V_146 -> V_362 , V_361 ) ;
if ( F_201 ( V_2 ) )
F_198 ( V_2 , V_146 ) ;
if ( F_20 ( V_390 , & V_146 -> V_368 ) ) {
memcpy ( & V_50 -> V_391 [ 0 ] , & V_146 -> V_391 [ 0 ] ,
sizeof( V_50 -> V_391 ) ) ;
V_50 -> V_379 |= V_392 ;
}
V_22 = F_98 ( V_2 , V_393 , V_119 -> V_90 ,
F_99 ( V_119 -> V_188 ) ,
F_100 ( V_119 -> V_188 ) ,
V_189 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_202 ( struct V_363 * V_364 ,
T_5 * V_362 )
{
memcpy ( V_362 , V_364 -> V_362 , sizeof( V_364 -> V_362 ) ) ;
}
int F_203 ( struct V_1 * V_2 ,
struct V_360 * V_146 )
{
int V_22 ;
struct V_363 * V_4 = V_146 -> V_364 ;
struct V_32 * V_119 = & V_4 -> V_38 ;
if ( F_20 ( V_28 , & V_146 -> V_25 ) )
return 0 ;
V_119 -> V_184 ( V_119 ) ;
V_22 = V_4 -> V_394 ( V_2 , V_146 ) ;
if ( V_22 < 0 ) {
V_119 -> V_170 ( V_119 ) ;
return V_22 ;
}
if ( F_20 ( V_193 , & V_146 -> V_25 ) )
V_22 = V_119 -> V_167 ( V_2 , V_119 ) ;
return V_22 ;
}
void F_204 ( struct V_1 * V_2 ,
struct V_363 * V_364 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , T_5 V_293 ,
void * V_99 , T_8 V_188 ,
int V_33 , unsigned long * V_34 ,
T_9 type )
{
F_105 ( & V_364 -> V_38 , V_85 , V_90 , V_86 , V_99 ,
V_188 , V_33 , V_34 , type ) ;
V_364 -> V_293 = V_293 ;
V_364 -> V_394 = F_200 ;
}
int F_205 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
int V_22 , V_399 ;
unsigned long * V_400 = & V_4 -> V_400 ;
if ( V_4 -> V_401 ( V_2 , V_4 , V_396 ) )
return - V_54 ;
V_399 = V_4 -> V_184 ( V_4 , V_396 ) ;
if ( F_20 ( V_28 , & V_396 -> V_25 ) )
V_4 -> V_402 ( V_2 , V_4 , V_399 ) ;
else {
V_22 = V_4 -> V_403 ( V_2 , V_396 ) ;
if ( V_22 ) {
V_4 -> V_404 = V_405 ;
F_30 ( V_399 , V_400 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_193 , & V_396 -> V_25 ) ) {
V_22 = V_4 -> V_167 ( V_2 , V_4 , V_399 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_399 , V_400 ) ;
}
static int F_206 ( struct V_397 * V_406 ,
struct V_395 * V_396 )
{
enum V_407 V_100 = V_396 -> V_100 , V_318 ;
if ( ( V_100 == V_408 ) ||
( V_100 == V_409 ) )
V_318 = V_410 ;
else
V_318 = V_100 ;
F_33 ( V_318 , & V_406 -> V_400 ) ;
return V_318 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_397 * V_4 ,
enum V_407 V_100 )
{
return F_34 ( V_2 , V_100 , & V_4 -> V_400 ) ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_397 * V_4 ,
enum V_407 V_100 )
{
unsigned long V_411 = V_4 -> V_400 ;
if ( ! F_209 ( V_100 , & V_411 ) ) {
F_12 ( L_79
L_80 , V_100 ,
V_4 -> V_412 [ V_413 ] ,
V_4 -> V_33 , V_411 , V_4 -> V_404 ) ;
return - V_54 ;
}
if ( V_4 -> V_414 >= V_4 -> V_415 )
F_12 ( L_81 ,
V_4 -> V_414 , V_4 -> V_415 ) ;
F_4 ( V_17 , L_82
L_83 , V_100 ,
V_4 -> V_412 [ V_413 ] , V_4 -> V_404 ) ;
if ( V_4 -> V_414 )
F_4 ( V_17 , L_84 ,
V_4 -> V_412 [ V_413 ] , V_4 -> V_414 ) ;
V_4 -> V_33 = V_4 -> V_404 ;
V_4 -> V_416 = V_4 -> V_414 ;
V_4 -> V_404 = V_405 ;
F_210 () ;
F_30 ( V_100 , & V_4 -> V_400 ) ;
F_31 () ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 ,
struct V_395 * V_417 ,
struct V_418 * V_50 )
{
struct V_419 * V_396 = & V_417 -> V_396 . V_420 ;
V_50 -> V_421 . V_422 |= F_20 ( V_423 , & V_396 -> V_127 ) *
V_424 ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_397 * V_4 ,
struct V_425 * V_396 ,
struct V_426 * V_427 ,
unsigned long * V_127 )
{
V_427 -> V_84 = V_4 -> V_85 ;
if ( F_20 ( V_428 , V_127 ) ) {
V_427 -> V_429 =
V_396 -> V_430 ;
V_427 -> V_431 = 1 ;
V_427 -> V_432 =
F_20 ( V_433 , V_127 ) ;
} else
V_427 -> V_429 =
V_434 ;
V_427 -> V_435 = F_20 ( V_436 , V_127 ) ;
V_427 -> V_437 = F_20 ( V_438 , V_127 ) ;
V_427 -> V_439 = V_396 -> V_440 ;
V_427 -> V_441 = F_73 ( V_396 -> V_441 ) ;
V_427 -> V_86 = V_4 -> V_86 ;
V_427 -> cos = V_396 -> cos ;
V_427 -> V_442 =
F_20 ( V_436 , V_127 ) ?
V_443 : V_444 ;
F_4 ( V_17 , L_85 ,
V_427 -> V_437 , V_427 -> cos , V_427 -> V_431 ) ;
}
static void F_213 ( struct V_397 * V_4 ,
struct V_445 * V_396 ,
struct V_446 * V_447 ,
unsigned long * V_127 )
{
V_447 -> V_448 =
F_20 ( V_449 , V_127 ) ;
V_447 -> V_450 =
F_73 ( V_396 -> V_450 ) ;
V_447 -> V_451 =
F_20 ( V_452 , V_127 ) ;
V_447 -> V_453 =
F_20 ( V_454 , V_127 ) ;
V_447 -> V_455 =
F_20 ( V_456 , V_127 ) ;
V_447 -> V_457 = V_396 -> V_458 ;
V_447 -> V_459 = V_396 -> V_460 ;
V_447 -> V_461 = V_396 -> V_462 ;
V_447 -> V_463 . V_464 =
F_72 ( F_100 ( V_396 -> V_465 ) ) ;
V_447 -> V_463 . V_466 =
F_72 ( F_99 ( V_396 -> V_465 ) ) ;
V_447 -> V_33 = 0 ;
}
static void F_214 ( struct V_397 * V_4 ,
struct V_467 * V_396 ,
struct V_468 * V_469 )
{
V_469 -> V_470 = F_73 ( V_396 -> V_471 ) ;
V_469 -> V_472 = F_73 ( V_396 -> V_473 ) ;
V_469 -> V_474 = F_73 ( V_396 -> V_475 ) ;
V_469 -> V_476 = F_73 ( V_396 -> V_477 ) ;
V_469 -> V_478 = F_73 ( V_396 -> V_479 ) ;
V_469 -> V_480 = F_73 ( V_396 -> V_481 ) ;
V_469 -> V_482 = F_73 ( V_396 -> V_483 ) ;
}
static void F_215 ( struct V_397 * V_4 ,
struct V_484 * V_396 ,
struct V_468 * V_469 ,
unsigned long * V_127 )
{
V_469 -> V_422 = F_20 ( V_485 , V_127 ) *
V_486 ;
V_469 -> V_487 = 0 ;
V_469 -> V_488 =
V_396 -> V_489 ;
V_469 -> V_490 =
F_20 ( V_491 , V_127 ) ;
V_469 -> V_492 = V_396 -> V_493 ;
V_469 -> V_494 = V_396 -> V_495 ;
V_469 -> V_496 = F_73 ( V_396 -> V_497 ) ;
V_469 -> V_33 = F_73 ( V_498 |
V_499 ) ;
V_469 -> V_500 = 0 ;
V_469 -> V_501 = 0 ;
V_469 -> V_502 = 0 ;
V_469 -> V_503 = 0 ;
V_469 -> V_504 =
F_20 ( V_505 , V_127 ) ;
V_469 -> V_506 =
F_20 ( V_507 , V_127 ) ;
V_469 -> V_508 = V_396 -> V_458 ;
V_469 -> V_509 = V_396 -> V_460 ;
V_469 -> V_510 = V_396 -> V_510 ;
V_469 -> V_511 = F_73 ( V_396 -> V_512 ) ;
V_469 -> V_513 = F_73 ( V_396 -> V_514 ) ;
V_469 -> V_515 . V_464 =
F_72 ( F_100 ( V_396 -> V_465 ) ) ;
V_469 -> V_515 . V_466 =
F_72 ( F_99 ( V_396 -> V_465 ) ) ;
V_469 -> V_516 . V_464 =
F_72 ( F_100 ( V_396 -> V_517 ) ) ;
V_469 -> V_516 . V_466 =
F_72 ( F_99 ( V_396 -> V_517 ) ) ;
V_469 -> V_518 . V_464 =
F_72 ( F_100 ( V_396 -> V_519 ) ) ;
V_469 -> V_518 . V_466 =
F_72 ( F_99 ( V_396 -> V_519 ) ) ;
V_469 -> V_520 = F_20 ( V_521 , V_127 ) ;
if ( F_20 ( V_522 , V_127 ) ) {
V_469 -> V_523 = V_4 -> V_86 ;
V_469 -> V_524 = 1 ;
}
V_469 -> V_388 = V_396 -> V_388 ;
V_469 -> V_525 =
F_20 ( V_526 , V_127 ) ;
V_469 -> V_527 =
F_73 ( V_396 -> V_528 ) ;
V_469 -> V_529 =
F_73 ( V_396 -> V_530 ) ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_395 * V_417 ,
struct V_418 * V_50 )
{
F_212 ( V_2 , V_417 -> V_398 ,
& V_417 -> V_396 . V_420 . V_531 ,
& V_50 -> V_532 ,
& V_417 -> V_396 . V_420 . V_127 ) ;
F_213 ( V_417 -> V_398 ,
& V_417 -> V_396 . V_420 . V_533 ,
& V_50 -> V_534 ,
& V_417 -> V_396 . V_420 . V_127 ) ;
F_215 ( V_417 -> V_398 ,
& V_417 -> V_396 . V_420 . V_535 ,
& V_50 -> V_421 ,
& V_417 -> V_396 . V_420 . V_127 ) ;
F_214 ( V_417 -> V_398 ,
& V_417 -> V_396 . V_420 . V_536 ,
& V_50 -> V_421 ) ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_395 * V_417 ,
struct V_537 * V_50 )
{
F_212 ( V_2 , V_417 -> V_398 ,
& V_417 -> V_396 . V_538 . V_531 ,
& V_50 -> V_532 ,
& V_417 -> V_396 . V_538 . V_127 ) ;
F_213 ( V_417 -> V_398 ,
& V_417 -> V_396 . V_538 . V_533 ,
& V_50 -> V_534 ,
& V_417 -> V_396 . V_538 . V_127 ) ;
F_4 ( V_17 , L_86 , V_417 -> V_398 -> V_412 [ 0 ] ,
V_50 -> V_534 . V_463 . V_464 , V_50 -> V_534 . V_463 . V_466 ) ;
}
static inline int F_218 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
struct V_539 * V_540 = & V_396 -> V_396 . V_540 ;
T_7 V_541 ;
T_5 cos ;
if ( F_20 ( V_542 , & V_4 -> type ) &&
F_20 ( V_543 , & V_540 -> V_534 . V_127 ) ) {
V_541 = V_540 -> V_534 . V_544 ? 1000000 / V_540 -> V_534 . V_544 : 0 ;
F_219 ( V_2 , V_540 -> V_534 . V_458 ,
V_540 -> V_534 . V_460 ,
! F_20 ( V_545 , & V_540 -> V_534 . V_127 ) ,
V_541 ) ;
}
if ( F_20 ( V_546 , & V_4 -> type ) &&
F_20 ( V_543 , & V_540 -> V_421 . V_127 ) ) {
V_541 = V_540 -> V_421 . V_544 ? 1000000 / V_540 -> V_421 . V_544 : 0 ;
F_219 ( V_2 , V_540 -> V_421 . V_458 ,
V_540 -> V_421 . V_460 ,
! F_20 ( V_545 , & V_540 -> V_421 . V_127 ) ,
V_541 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_415 ; cos ++ ) {
F_4 ( V_17 , L_87 ,
V_4 -> V_412 [ cos ] , cos ) ;
F_4 ( V_17 , L_88 , V_540 -> V_547 [ cos ] ) ;
F_220 ( V_2 , V_540 -> V_547 [ cos ] , V_4 -> V_412 [ cos ] ) ;
}
V_4 -> V_402 ( V_2 , V_4 , V_548 ) ;
F_221 () ;
F_185 () ;
return 0 ;
}
static inline int F_222 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
struct V_418 * V_99 =
(struct V_418 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
int V_550 = V_551 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_216 ( V_2 , V_396 , V_99 ) ;
return F_98 ( V_2 , V_550 , V_4 -> V_412 [ V_413 ] ,
F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_189 ) ;
}
static inline int F_223 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
struct V_418 * V_99 =
(struct V_418 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
int V_550 = V_551 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_216 ( V_2 , V_396 , V_99 ) ;
F_211 ( V_2 , V_396 , V_99 ) ;
return F_98 ( V_2 , V_550 , V_4 -> V_412 [ V_413 ] ,
F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_189 ) ;
}
static inline int F_224 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
struct V_537 * V_99 =
(struct V_537 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
int V_550 = V_552 ;
struct V_553 * V_554 =
& V_396 -> V_396 . V_538 ;
T_5 V_555 = V_554 -> V_555 ;
if ( V_555 >= V_4 -> V_415 ) {
F_12 ( L_89 ,
V_4 -> V_85 , V_555 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_90 ,
V_554 -> V_531 . cos ,
V_554 -> V_531 . V_440 ) ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_217 ( V_2 , V_396 , V_99 ) ;
F_4 ( V_17 , L_91
L_92 ,
V_4 -> V_412 [ V_555 ] ,
V_99 -> V_532 . V_84 ,
V_99 -> V_532 . V_439 , V_99 -> V_532 . cos ) ;
return F_98 ( V_2 , V_550 , V_4 -> V_412 [ V_555 ] ,
F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_189 ) ;
}
static void F_225 ( struct V_1 * V_2 ,
struct V_397 * V_406 ,
struct V_556 * V_396 ,
struct V_557 * V_50 )
{
V_50 -> V_84 = V_406 -> V_85 ;
V_50 -> V_86 = V_406 -> V_86 ;
V_50 -> V_450 = F_73 ( V_396 -> V_558 ) ;
V_50 -> V_504 =
F_20 ( V_559 , & V_396 -> V_560 ) ;
V_50 -> V_561 =
F_20 ( V_562 ,
& V_396 -> V_560 ) ;
V_50 -> V_506 =
F_20 ( V_563 , & V_396 -> V_560 ) ;
V_50 -> V_564 =
F_20 ( V_565 ,
& V_396 -> V_560 ) ;
V_50 -> V_566 =
F_20 ( V_567 , & V_396 -> V_560 ) ;
V_50 -> V_568 =
F_20 ( V_569 , & V_396 -> V_560 ) ;
V_50 -> V_437 =
F_20 ( V_570 , & V_396 -> V_560 ) ;
V_50 -> V_571 =
F_20 ( V_572 , & V_396 -> V_560 ) ;
V_50 -> V_573 =
F_20 ( V_574 , & V_396 -> V_560 ) ;
V_50 -> V_575 =
F_20 ( V_576 ,
& V_396 -> V_560 ) ;
V_50 -> V_577 =
F_20 ( V_578 ,
& V_396 -> V_560 ) ;
V_50 -> V_525 =
F_20 ( V_579 , & V_396 -> V_560 ) ;
V_50 -> V_527 = F_73 ( V_396 -> V_528 ) ;
V_50 -> V_529 = F_73 ( V_396 -> V_530 ) ;
}
static inline int F_226 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
struct V_557 * V_99 =
(struct V_557 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
struct V_556 * V_580 =
& V_396 -> V_396 . V_581 ;
T_5 V_555 = V_580 -> V_555 ;
if ( V_555 >= V_4 -> V_415 ) {
F_12 ( L_89 ,
V_4 -> V_85 , V_555 ) ;
return - V_54 ;
}
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_225 ( V_2 , V_4 , V_580 , V_99 ) ;
return F_98 ( V_2 , V_582 ,
V_4 -> V_412 [ V_555 ] , F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_189 ) ;
}
static inline int F_227 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_556 * V_581 = & V_396 -> V_396 . V_581 ;
memset ( V_581 , 0 , sizeof( * V_581 ) ) ;
F_83 ( V_572 , & V_581 -> V_560 ) ;
return F_226 ( V_2 , V_396 ) ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_556 * V_581 = & V_396 -> V_396 . V_581 ;
memset ( V_581 , 0 , sizeof( * V_581 ) ) ;
F_83 ( V_570 , & V_581 -> V_560 ) ;
F_83 ( V_572 , & V_581 -> V_560 ) ;
return F_226 ( V_2 , V_396 ) ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
return - 1 ;
}
static inline int F_230 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
return F_98 ( V_2 , V_583 ,
V_4 -> V_412 [ V_413 ] , 0 , V_4 -> V_85 ,
V_189 ) ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
T_5 V_584 = V_396 -> V_396 . V_585 . V_555 ;
if ( V_584 >= V_4 -> V_415 ) {
F_12 ( L_89 ,
V_4 -> V_85 , V_584 ) ;
return - V_54 ;
}
return F_98 ( V_2 , V_586 ,
V_4 -> V_412 [ V_584 ] , 0 , 0 , V_587 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
T_5 V_555 = V_396 -> V_396 . V_588 . V_555 ;
if ( V_555 >= V_4 -> V_415 ) {
F_12 ( L_89 ,
V_4 -> V_85 , V_555 ) ;
return - V_54 ;
}
return F_98 ( V_2 , V_589 ,
V_4 -> V_412 [ V_555 ] , 0 , 0 , V_189 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
struct V_397 * V_4 = V_396 -> V_398 ;
return F_98 ( V_2 , V_590 ,
V_4 -> V_412 [ V_413 ] , 0 , 0 ,
V_189 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
switch ( V_396 -> V_100 ) {
case V_548 :
return F_218 ( V_2 , V_396 ) ;
case V_591 :
return F_224 ( V_2 , V_396 ) ;
case V_409 :
return F_227 ( V_2 , V_396 ) ;
case V_408 :
return F_228 ( V_2 , V_396 ) ;
case V_410 :
return F_226 ( V_2 , V_396 ) ;
case V_592 :
return F_229 ( V_2 , V_396 ) ;
case V_593 :
return F_230 ( V_2 , V_396 ) ;
case V_594 :
return F_231 ( V_2 , V_396 ) ;
case V_595 :
return F_232 ( V_2 , V_396 ) ;
case V_596 :
return F_233 ( V_2 , V_396 ) ;
default:
F_12 ( L_50 , V_396 -> V_100 ) ;
return - V_54 ;
}
}
static int F_235 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
switch ( V_396 -> V_100 ) {
case V_597 :
return F_222 ( V_2 , V_396 ) ;
case V_548 :
case V_591 :
case V_409 :
case V_408 :
case V_410 :
case V_592 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
return F_234 ( V_2 , V_396 ) ;
default:
F_12 ( L_50 , V_396 -> V_100 ) ;
return - V_54 ;
}
}
static int F_236 ( struct V_1 * V_2 ,
struct V_395 * V_396 )
{
switch ( V_396 -> V_100 ) {
case V_597 :
return F_223 ( V_2 , V_396 ) ;
case V_548 :
case V_591 :
case V_409 :
case V_408 :
case V_410 :
case V_592 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
return F_234 ( V_2 , V_396 ) ;
default:
F_12 ( L_50 , V_396 -> V_100 ) ;
return - V_54 ;
}
}
static int F_237 ( struct V_1 * V_2 ,
struct V_397 * V_4 ,
struct V_395 * V_396 )
{
enum V_598 V_33 = V_4 -> V_33 , V_404 = V_405 ;
enum V_407 V_100 = V_396 -> V_100 ;
struct V_556 * V_580 =
& V_396 -> V_396 . V_581 ;
T_5 V_414 = V_4 -> V_416 ;
if ( F_20 ( V_28 , & V_396 -> V_25 ) ) {
V_4 -> V_400 = 0 ;
V_4 -> V_404 = V_405 ;
}
if ( V_4 -> V_400 )
return - V_37 ;
switch ( V_33 ) {
case V_599 :
if ( V_100 == V_548 )
V_404 = V_600 ;
break;
case V_600 :
if ( V_100 == V_597 ) {
if ( F_20 ( V_438 ,
& V_396 -> V_396 . V_420 . V_127 ) )
V_404 = V_601 ;
else
V_404 = V_602 ;
}
break;
case V_601 :
if ( V_100 == V_409 )
V_404 = V_602 ;
else if ( ( V_100 == V_596 ) ||
( V_100 == V_592 ) )
V_404 = V_601 ;
else if ( V_100 == V_591 ) {
V_404 = V_603 ;
V_414 = 1 ;
}
else if ( V_100 == V_593 )
V_404 = V_604 ;
else if ( V_100 == V_410 ) {
if ( F_20 ( V_572 ,
& V_580 -> V_560 ) &&
! F_20 ( V_570 ,
& V_580 -> V_560 ) )
V_404 = V_602 ;
else
V_404 = V_601 ;
}
break;
case V_603 :
if ( V_100 == V_595 )
V_404 = V_605 ;
else if ( V_100 == V_591 ) {
V_404 = V_603 ;
V_414 = V_4 -> V_416 + 1 ;
}
else if ( ( V_100 == V_596 ) ||
( V_100 == V_592 ) )
V_404 = V_603 ;
else if ( V_100 == V_410 ) {
if ( F_20 ( V_572 ,
& V_580 -> V_560 ) &&
! F_20 ( V_570 ,
& V_580 -> V_560 ) )
V_404 = V_602 ;
else
V_404 = V_603 ;
}
break;
case V_605 :
if ( V_100 == V_594 ) {
V_414 = V_4 -> V_416 - 1 ;
if ( V_414 == 0 )
V_404 = V_601 ;
else
V_404 = V_603 ;
}
break;
case V_602 :
if ( V_100 == V_408 )
V_404 = V_601 ;
else if ( ( V_100 == V_596 ) ||
( V_100 == V_592 ) )
V_404 = V_602 ;
else if ( V_100 == V_593 )
V_404 = V_604 ;
else if ( V_100 == V_410 ) {
if ( F_20 ( V_572 ,
& V_580 -> V_560 ) &&
F_20 ( V_570 ,
& V_580 -> V_560 ) ) {
if ( V_4 -> V_416 == 0 )
V_404 = V_601 ;
else
V_404 = V_603 ;
} else
V_404 = V_602 ;
}
break;
case V_604 :
if ( V_100 == V_595 )
V_404 = V_606 ;
break;
case V_606 :
if ( V_100 == V_594 )
V_404 = V_599 ;
break;
default:
F_12 ( L_93 , V_33 ) ;
}
if ( V_404 != V_405 ) {
F_4 ( V_17 , L_94 ,
V_33 , V_100 , V_404 ) ;
V_4 -> V_404 = V_404 ;
V_4 -> V_414 = V_414 ;
return 0 ;
}
F_4 ( V_17 , L_95 , V_33 , V_100 ) ;
return - V_54 ;
}
void F_238 ( struct V_1 * V_2 ,
struct V_397 * V_406 ,
T_5 V_85 , T_6 * V_412 , T_5 V_607 , T_5 V_86 ,
void * V_99 ,
T_8 V_188 , unsigned long type )
{
memset ( V_406 , 0 , sizeof( * V_406 ) ) ;
F_239 ( V_608 < V_607 ) ;
memcpy ( V_406 -> V_412 , V_412 , sizeof( V_406 -> V_412 [ 0 ] ) * V_607 ) ;
V_406 -> V_415 = V_607 ;
V_406 -> V_85 = V_85 ;
V_406 -> V_86 = V_86 ;
V_406 -> V_99 = V_99 ;
V_406 -> V_188 = V_188 ;
V_406 -> type = type ;
V_406 -> V_404 = V_405 ;
if ( F_108 ( V_2 ) )
V_406 -> V_403 = F_235 ;
else
V_406 -> V_403 = F_236 ;
V_406 -> V_401 = F_237 ;
V_406 -> V_402 = F_208 ;
V_406 -> V_167 = F_207 ;
V_406 -> V_184 = F_206 ;
}
void F_240 ( struct V_1 * V_2 ,
struct V_397 * V_406 ,
T_6 V_90 , T_5 V_73 )
{
V_406 -> V_412 [ V_73 ] = V_90 ;
}
enum V_609 F_241 ( struct V_1 * V_2 ,
struct V_610 * V_4 )
{
if ( V_4 -> V_400 )
return V_611 ;
F_242 () ;
return V_4 -> V_33 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_610 * V_4 ,
enum V_612 V_100 )
{
return F_34 ( V_2 , V_100 , & V_4 -> V_400 ) ;
}
static inline int F_244 ( struct V_1 * V_2 ,
struct V_610 * V_4 ,
enum V_612 V_100 )
{
unsigned long V_411 = V_4 -> V_400 ;
if ( ! F_209 ( V_100 , & V_411 ) ) {
F_12 ( L_96
L_80 , V_100 , F_245 ( V_2 ) ,
V_4 -> V_33 , V_411 , V_4 -> V_404 ) ;
return - V_54 ;
}
F_4 ( V_17 ,
L_97 ,
V_100 , F_245 ( V_2 ) , V_4 -> V_404 ) ;
V_4 -> V_33 = V_4 -> V_404 ;
V_4 -> V_404 = V_611 ;
F_210 () ;
F_30 ( V_100 , & V_4 -> V_400 ) ;
F_31 () ;
return 0 ;
}
static int F_246 ( struct V_1 * V_2 ,
struct V_610 * V_4 ,
enum V_612 V_100 )
{
int V_22 = F_244 ( V_2 , V_4 , V_100 ) ;
return V_22 ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_610 * V_4 ,
struct V_613 * V_396 )
{
enum V_609 V_33 = V_4 -> V_33 , V_404 = V_611 ;
enum V_612 V_100 = V_396 -> V_100 ;
if ( F_20 ( V_28 , & V_396 -> V_25 ) ) {
V_4 -> V_400 = 0 ;
V_4 -> V_404 = V_611 ;
}
if ( V_4 -> V_400 )
return - V_37 ;
switch ( V_33 ) {
case V_614 :
if ( V_100 == V_615 )
V_404 = V_616 ;
break;
case V_616 :
if ( V_100 == V_617 )
V_404 = V_618 ;
else if ( V_100 == V_619 )
V_404 = V_614 ;
break;
case V_618 :
if ( V_100 == V_620 )
V_404 = V_616 ;
else if ( V_100 == V_621 )
V_404 = V_622 ;
break;
case V_622 :
if ( V_100 == V_623 )
V_404 = V_618 ;
break;
default:
F_12 ( L_98 , V_33 ) ;
}
if ( V_404 != V_611 ) {
F_4 ( V_17 , L_99 ,
V_33 , V_100 , V_404 ) ;
V_4 -> V_404 = V_404 ;
return 0 ;
}
F_4 ( V_17 , L_100 ,
V_33 , V_100 ) ;
return - V_54 ;
}
static inline int F_248 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
return V_625 -> V_626 ( V_2 ) ;
}
static inline int F_249 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
int V_22 = V_625 -> V_627 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_248 ( V_2 , V_625 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
int V_22 = V_625 -> V_628 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_249 ( V_2 , V_625 ) ;
}
static inline int F_251 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
int V_22 = V_625 -> V_629 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_249 ( V_2 , V_625 ) ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
T_6 V_630 = V_396 -> V_396 . V_631 . V_632 ;
struct V_610 * V_4 = V_396 -> V_633 ;
const struct V_624 * V_625 = V_4 -> V_625 ;
int V_22 = 0 ;
F_4 ( V_17 , L_101 ,
F_253 ( V_2 ) , V_630 ) ;
V_22 = V_625 -> V_634 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_625 -> V_635 ( V_2 ) ;
if ( V_22 ) {
F_12 ( L_102 ) ;
goto V_636;
}
switch ( V_630 ) {
case V_637 :
V_22 = F_250 ( V_2 , V_625 ) ;
if ( V_22 )
goto V_636;
break;
case V_638 :
V_22 = F_251 ( V_2 , V_625 ) ;
if ( V_22 )
goto V_636;
break;
case V_639 :
V_22 = F_249 ( V_2 , V_625 ) ;
if ( V_22 )
goto V_636;
break;
case V_640 :
V_22 = F_248 ( V_2 , V_625 ) ;
if ( V_22 )
goto V_636;
break;
default:
F_12 ( L_103 , V_630 ) ;
V_22 = - V_54 ;
}
V_636:
V_625 -> V_641 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_402 ( V_2 , V_4 , V_615 ) ;
return V_22 ;
}
static inline void F_254 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
V_625 -> V_642 ( V_2 ) ;
}
static inline void F_255 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
V_625 -> V_643 ( V_2 ) ;
F_254 ( V_2 , V_625 ) ;
}
static inline void F_256 ( struct V_1 * V_2 ,
const struct V_624 * V_625 )
{
F_255 ( V_2 , V_625 ) ;
V_625 -> V_644 ( V_2 ) ;
}
static inline int F_257 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
T_6 V_645 = V_396 -> V_396 . V_646 . V_645 ;
struct V_610 * V_4 = V_396 -> V_633 ;
const struct V_624 * V_625 = V_4 -> V_625 ;
F_4 ( V_17 , L_104 , F_253 ( V_2 ) ,
V_645 ) ;
switch ( V_645 ) {
case V_647 :
F_256 ( V_2 , V_625 ) ;
break;
case V_648 :
F_255 ( V_2 , V_625 ) ;
break;
case V_649 :
F_254 ( V_2 , V_625 ) ;
break;
default:
F_12 ( L_105 ,
V_645 ) ;
break;
}
V_4 -> V_402 ( V_2 , V_4 , V_619 ) ;
return 0 ;
}
static inline int F_258 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
struct V_610 * V_4 = V_396 -> V_633 ;
struct V_650 * V_99 =
(struct V_650 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
struct V_651 * V_652 = & V_396 -> V_396 . V_653 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_654 = F_73 ( V_652 -> V_655 ) ;
V_99 -> V_656 = V_652 -> V_656 ;
V_99 -> V_657 = F_259 ( V_2 ) ;
V_99 -> V_658 = V_652 -> V_658 ;
return F_98 ( V_2 , V_659 , 0 ,
F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_587 ) ;
}
static inline int F_260 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
return F_98 ( V_2 , V_660 , 0 , 0 , 0 ,
V_587 ) ;
}
static inline int F_261 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
return F_98 ( V_2 , V_661 , 0 , 0 , 0 ,
V_587 ) ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
struct V_610 * V_4 = V_396 -> V_633 ;
struct V_662 * V_99 =
(struct V_662 * ) V_4 -> V_99 ;
T_8 V_549 = V_4 -> V_188 ;
struct V_663 * V_664 =
& V_396 -> V_396 . V_665 ;
int V_275 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_666 = V_664 -> V_666 ;
V_99 -> V_667 = V_664 -> V_667 ;
V_99 -> V_668 = V_664 -> V_668 ;
for ( V_275 = 0 ; V_275 < F_263 ( V_99 -> V_669 ) ; V_275 ++ )
V_99 -> V_669 [ V_275 ] =
V_664 -> V_669 [ V_275 ] ;
return F_98 ( V_2 , V_670 , 0 ,
F_99 ( V_549 ) ,
F_100 ( V_549 ) , V_587 ) ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
switch ( V_396 -> V_100 ) {
case V_615 :
return F_252 ( V_2 , V_396 ) ;
case V_617 :
return F_258 ( V_2 , V_396 ) ;
case V_620 :
return F_260 ( V_2 , V_396 ) ;
case V_619 :
return F_257 ( V_2 , V_396 ) ;
case V_621 :
return F_261 ( V_2 , V_396 ) ;
case V_623 :
return F_262 ( V_2 , V_396 ) ;
default:
F_12 ( L_50 , V_396 -> V_100 ) ;
return - V_54 ;
}
}
void F_265 ( struct V_1 * V_2 ,
struct V_610 * V_406 ,
void * V_99 , T_8 V_188 ,
struct V_624 * V_671 )
{
memset ( V_406 , 0 , sizeof( * V_406 ) ) ;
F_266 ( & V_406 -> V_672 ) ;
V_406 -> V_99 = V_99 ;
V_406 -> V_188 = V_188 ;
V_406 -> V_403 = F_264 ;
V_406 -> V_401 = F_247 ;
V_406 -> V_402 = F_246 ;
V_406 -> V_167 = F_243 ;
V_406 -> V_625 = V_671 ;
}
int F_267 ( struct V_1 * V_2 ,
struct V_613 * V_396 )
{
struct V_610 * V_4 = V_396 -> V_633 ;
int V_22 ;
enum V_612 V_100 = V_396 -> V_100 ;
unsigned long * V_400 = & V_4 -> V_400 ;
F_268 ( & V_4 -> V_672 ) ;
if ( V_4 -> V_401 ( V_2 , V_4 , V_396 ) ) {
F_269 ( & V_4 -> V_672 ) ;
return - V_54 ;
}
F_33 ( V_100 , V_400 ) ;
if ( F_20 ( V_28 , & V_396 -> V_25 ) ) {
F_244 ( V_2 , V_4 , V_100 ) ;
F_269 ( & V_4 -> V_672 ) ;
} else {
V_22 = V_4 -> V_403 ( V_2 , V_396 ) ;
F_269 ( & V_4 -> V_672 ) ;
if ( V_22 ) {
V_4 -> V_404 = V_611 ;
F_30 ( V_100 , V_400 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_193 , & V_396 -> V_25 ) ) {
V_22 = V_4 -> V_167 ( V_2 , V_4 , V_100 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_100 , V_400 ) ;
}
