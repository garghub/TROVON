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
F_4 ( V_17 , L_14 V_114 L_15
L_16 , ( V_71 ? L_17 : L_18 ) ,
F_69 ( V_53 ) , V_38 -> V_85 ) ;
F_70 ( & V_103 -> V_53 . V_115 ,
& V_103 -> V_53 . V_116 ,
& V_103 -> V_53 . V_117 , V_53 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_118 ,
true , V_112 ,
& V_103 -> V_53 . V_113 ) ;
F_70 ( & V_103 -> V_53 . V_115 ,
& V_103 -> V_53 . V_116 ,
& V_103 -> V_53 . V_117 , V_53 ) ;
}
F_67 ( V_38 -> V_90 , V_38 -> V_33 , & V_50 -> V_113 ,
V_92 ) ;
}
static inline void F_71 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_97 ,
struct V_119 * V_83 )
{
struct V_32 * V_120 = & V_4 -> V_38 ;
V_83 -> V_121 = 1 ;
V_83 -> V_40 = ( T_5 ) V_97 ;
V_83 -> V_84 = 0xff ;
V_83 -> V_93 = ( ( V_120 -> V_90 & V_94 ) | ( type << V_95 ) ) ;
}
static inline void F_72 ( struct V_1 * V_2 ,
struct V_39 * V_4 , bool V_71 , int V_81 , T_5 * V_53 ,
T_7 V_122 , struct V_123 * V_124 )
{
struct V_32 * V_120 = & V_4 -> V_38 ;
T_6 V_125 = ( 1 << V_120 -> V_85 ) ;
V_124 -> V_126 = F_73 ( V_125 ) ;
V_124 -> V_127 = V_120 -> V_86 ;
V_124 -> V_122 = F_74 ( V_122 ) ;
if ( V_71 ) {
F_75 ( V_124 -> V_128 , V_129 ,
V_130 ) ;
F_75 ( V_124 -> V_128 ,
V_131 , V_81 ) ;
F_70 ( & V_124 -> V_132 ,
& V_124 -> V_133 ,
& V_124 -> V_134 , V_53 ) ;
} else
F_75 ( V_124 -> V_128 , V_129 ,
V_135 ) ;
}
static inline void F_76 ( struct V_1 * V_2 ,
struct V_39 * V_4 , int type , int V_97 , bool V_71 ,
T_5 * V_53 , T_7 V_122 , int V_81 , struct V_136 * V_137 )
{
struct V_123 * V_124 = & V_137 -> V_138 [ 0 ] ;
struct V_32 * V_38 = & V_4 -> V_38 ;
F_71 ( V_2 , V_4 , type , V_97 ,
& V_137 -> V_83 ) ;
F_72 ( V_2 , V_4 , V_71 , V_81 , V_53 , V_122 ,
V_124 ) ;
F_4 ( V_17 , L_19 V_114 L_20 ,
( V_71 ? L_21 : L_22 ) ,
F_69 ( V_53 ) , V_38 -> V_85 , V_97 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 , int V_96 ,
int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_136 * V_137 =
(struct V_136 * ) ( V_38 -> V_99 ) ;
bool V_71 = ( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
true : false ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
F_76 ( V_2 , V_4 , V_139 ,
V_97 , V_71 ,
V_19 -> V_101 . V_59 . V_55 . V_53 . V_53 , 0 ,
V_140 , V_137 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
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
F_66 ( V_2 , V_4 , V_71 , V_141 ,
& V_103 -> V_58 . V_113 ) ;
F_4 ( V_17 , L_23 , ( V_71 ? L_17 : L_18 ) ,
V_58 ) ;
V_103 -> V_58 . V_58 = F_74 ( V_58 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_118 ,
true , V_141 ,
& V_103 -> V_58 . V_113 ) ;
V_103 -> V_58 . V_58 = F_74 ( V_58 ) ;
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
F_66 ( V_2 , V_4 , V_71 , V_142 ,
& V_103 -> V_143 . V_113 ) ;
V_103 -> V_143 . V_58 = F_74 ( V_58 ) ;
F_70 ( & V_103 -> V_143 . V_115 ,
& V_103 -> V_143 . V_116 ,
& V_103 -> V_143 . V_117 , V_53 ) ;
if ( V_100 == V_107 ) {
V_103 ++ ;
V_92 ++ ;
F_66 ( V_2 ,
V_19 -> V_101 . V_59 . V_118 ,
true , V_142 ,
& V_103 -> V_143 . V_113 ) ;
V_103 -> V_143 . V_58 = F_74 ( V_58 ) ;
F_70 ( & V_103 -> V_143 . V_115 ,
& V_103 -> V_143 . V_116 ,
& V_103 -> V_143 . V_117 , V_53 ) ;
}
F_67 ( V_38 -> V_90 , V_38 -> V_33 , & V_50 -> V_113 ,
V_92 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
int V_96 , int V_97 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_136 * V_137 =
(struct V_136 * ) ( V_38 -> V_99 ) ;
bool V_71 = ( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
true : false ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
F_76 ( V_2 , V_4 , V_144 ,
V_97 , V_71 ,
V_19 -> V_101 . V_59 . V_55 . V_59 . V_53 ,
V_19 -> V_101 . V_59 . V_55 . V_59 . V_58 ,
V_145 , V_137 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_51 * * V_148 )
{
struct V_51 * V_52 ;
struct V_39 * V_4 = V_147 -> V_149 ;
if ( F_15 ( & V_4 -> V_150 ) ) {
* V_148 = NULL ;
return 0 ;
}
if ( * V_148 == NULL )
* V_148 = F_16 ( & V_4 -> V_150 ,
struct V_51 ,
V_24 ) ;
else
* V_148 = F_82 ( * V_148 , V_24 ) ;
V_52 = * V_148 ;
if ( F_83 ( & V_52 -> V_24 , & V_4 -> V_150 ) )
* V_148 = NULL ;
memcpy ( & V_147 -> V_151 . V_55 , & V_52 -> V_55 , sizeof( V_52 -> V_55 ) ) ;
V_147 -> V_151 . V_100 = V_105 ;
V_147 -> V_151 . V_106 = V_52 -> V_106 ;
F_84 ( V_152 , & V_147 -> V_25 ) ;
return F_85 ( V_2 , V_147 ) ;
}
static struct V_18 * F_86 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_153 * V_50 = & V_19 -> V_101 . V_59 . V_55 . V_53 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_53 , V_50 ,
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
struct V_154 * V_50 = & V_19 -> V_101 . V_59 . V_55 . V_58 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_58 , V_50 ,
sizeof( * V_50 ) ) &&
( V_52 -> V_101 . V_59 . V_100 == V_19 -> V_101 . V_59 . V_100 ) )
return V_52 ;
return NULL ;
}
static struct V_18 * F_88 (
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_18 * V_52 ;
struct V_155 * V_50 =
& V_19 -> V_101 . V_59 . V_55 . V_59 ;
F_9 (pos, &o->exe_queue, link)
if ( ! memcmp ( & V_52 -> V_101 . V_59 . V_55 . V_59 , V_50 ,
sizeof( * V_50 ) ) &&
( V_52 -> V_101 . V_59 . V_100 == V_19 -> V_101 . V_59 . V_100 ) )
return V_52 ;
return NULL ;
}
static inline int F_89 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_156 -> V_59 ;
struct V_3 * V_157 = & V_4 -> V_12 ;
int V_22 ;
V_22 = V_4 -> V_63 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
if ( V_22 ) {
F_4 ( V_17 , L_24
L_25 ) ;
return V_22 ;
}
if ( V_157 -> V_11 ( V_157 , V_19 ) ) {
F_4 ( V_17 , L_26 ) ;
return - V_57 ;
}
if ( ! ( F_20 ( V_158 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_4 -> V_159 ( V_4 ) ) )
return - V_54 ;
return 0 ;
}
static inline int F_90 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_18 * V_19 )
{
struct V_39 * V_4 = & V_156 -> V_59 ;
struct V_51 * V_52 ;
struct V_3 * V_157 = & V_4 -> V_12 ;
struct V_18 V_160 ;
V_52 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
if ( ! V_52 ) {
F_4 ( V_17 , L_27
L_25 ) ;
return - V_57 ;
}
memcpy ( & V_160 , V_19 , sizeof( V_160 ) ) ;
V_160 . V_101 . V_59 . V_100 = V_107 ;
if ( V_157 -> V_11 ( V_157 , & V_160 ) ) {
F_12 ( L_28 ) ;
return - V_54 ;
}
if ( V_157 -> V_11 ( V_157 , V_19 ) ) {
F_4 ( V_17 , L_29 ) ;
return - V_57 ;
}
if ( ! ( F_20 ( V_158 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_4 -> V_161 ( V_4 ) ) ) {
F_12 ( L_30 ) ;
return - V_54 ;
}
return 0 ;
}
static inline int F_91 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_18 * V_19 )
{
struct V_39 * V_60 = & V_156 -> V_59 ;
struct V_39 * V_162 = V_19 -> V_101 . V_59 . V_118 ;
struct V_18 V_160 ;
struct V_3 * V_163 = & V_60 -> V_12 ;
struct V_3 * V_164 = & V_162 -> V_12 ;
if ( ! V_60 -> V_165 ( V_60 , V_162 , & V_19 -> V_101 . V_59 . V_55 ) ) {
F_4 ( V_17 , L_31
L_25 ) ;
return - V_54 ;
}
memcpy ( & V_160 , V_19 , sizeof( V_160 ) ) ;
V_160 . V_101 . V_59 . V_100 = V_166 ;
if ( V_163 -> V_11 ( V_163 , & V_160 ) ) {
F_12 ( L_32
L_33 ) ;
return - V_54 ;
}
if ( V_163 -> V_11 ( V_163 , V_19 ) ) {
F_4 ( V_17 , L_28 ) ;
return - V_57 ;
}
V_160 . V_101 . V_59 . V_100 = V_105 ;
if ( V_164 -> V_11 ( V_164 , & V_160 ) ) {
F_12 ( L_34
L_35 ) ;
return - V_54 ;
}
if ( ! ( F_20 ( V_167 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_162 -> V_159 ( V_162 ) ) )
return - V_54 ;
if ( ! ( F_20 ( V_158 ,
& V_19 -> V_101 . V_59 . V_106 ) ||
V_60 -> V_161 ( V_60 ) ) ) {
V_162 -> V_161 ( V_162 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_18 * V_19 )
{
switch ( V_19 -> V_101 . V_59 . V_100 ) {
case V_105 :
return F_89 ( V_2 , V_156 , V_19 ) ;
case V_166 :
return F_90 ( V_2 , V_156 , V_19 ) ;
case V_107 :
return F_91 ( V_2 , V_156 , V_19 ) ;
default:
return - V_54 ;
}
}
static int F_93 ( struct V_1 * V_2 ,
struct V_39 * V_4 )
{
int V_20 = 5000 , V_22 ;
struct V_3 * V_157 = & V_4 -> V_12 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
while ( V_20 -- ) {
V_22 = V_38 -> V_168 ( V_2 , V_38 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_24 ( V_157 ) )
F_38 ( 1000 , 1000 ) ;
else
return 0 ;
}
return - V_37 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
union V_169 * V_170 ,
unsigned long * V_25 )
{
struct V_32 * V_120 = & V_4 -> V_38 ;
int V_22 ;
F_18 ( V_2 , & V_4 -> V_12 ) ;
V_120 -> V_171 ( V_120 ) ;
if ( V_170 -> V_172 . error )
return - V_54 ;
if ( F_20 ( V_173 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
return 1 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_18 * V_19 )
{
struct V_18 V_174 , * V_52 ;
struct V_39 * V_4 = & V_156 -> V_59 ;
struct V_3 * V_157 = & V_4 -> V_12 ;
memcpy ( & V_174 , V_19 , sizeof( V_174 ) ) ;
switch ( V_19 -> V_101 . V_59 . V_100 ) {
case V_105 :
V_174 . V_101 . V_59 . V_100 = V_166 ;
break;
case V_166 :
V_174 . V_101 . V_59 . V_100 = V_105 ;
break;
default:
return 0 ;
}
V_52 = V_157 -> V_11 ( V_157 , & V_174 ) ;
if ( V_52 ) {
if ( ! F_20 ( V_158 ,
& V_52 -> V_101 . V_59 . V_106 ) ) {
if ( ( V_174 . V_101 . V_59 . V_100 ==
V_105 ) && ! V_4 -> V_161 ( V_4 ) ) {
F_12 ( L_36
L_37 ) ;
return - V_54 ;
} else if ( ! V_4 -> V_159 ( V_4 ) ) {
F_12 ( L_38
L_39 ) ;
return - V_54 ;
}
}
F_4 ( V_17 , L_40 ,
( V_19 -> V_101 . V_59 . V_100 == V_105 ) ?
L_12 : L_41 ) ;
F_17 ( & V_52 -> V_24 ) ;
F_5 ( V_2 , V_52 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_96 (
struct V_1 * V_2 ,
struct V_39 * V_4 ,
struct V_18 * V_19 ,
bool V_21 ,
struct V_51 * * V_175 )
{
int V_100 = V_19 -> V_101 . V_59 . V_100 ;
struct V_51 * V_176 ;
if ( ! V_21 &&
( ( V_100 == V_105 ) || ( V_100 == V_107 ) ) ) {
V_176 = F_26 ( sizeof( * V_176 ) , V_31 ) ;
if ( ! V_176 )
return - V_177 ;
if ( ! V_4 -> V_178 ( V_4 , & V_176 -> V_97 ) ) {
F_21 ( 1 ) ;
F_6 ( V_176 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_42 , V_176 -> V_97 ) ;
memcpy ( & V_176 -> V_55 , & V_19 -> V_101 . V_59 . V_55 ,
sizeof( V_176 -> V_55 ) ) ;
V_176 -> V_106 =
V_19 -> V_101 . V_59 . V_106 ;
} else
V_176 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
* V_175 = V_176 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
union V_6 * V_156 ,
struct V_179 * V_180 ,
unsigned long * V_25 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = & V_156 -> V_59 , * V_181 ;
struct V_32 * V_120 = & V_4 -> V_38 ;
int V_22 , V_182 = 0 ;
bool V_21 = F_20 ( V_152 , V_25 ) ;
bool V_183 = F_20 ( V_28 , V_25 ) ;
struct V_51 * V_176 ;
int V_100 ;
if ( ! V_183 ) {
F_21 ( V_120 -> V_184 ( V_120 ) ) ;
V_120 -> V_185 ( V_120 ) ;
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( V_100 == V_107 )
V_181 = V_19 -> V_101 . V_59 . V_118 ;
else
V_181 = V_4 ;
V_22 = F_96 ( V_2 , V_181 ,
V_19 , V_21 ,
& V_176 ) ;
if ( V_22 )
goto V_186;
F_21 ( ! V_176 ) ;
if ( ! V_21 &&
( ( V_100 == V_105 ) ||
( V_100 == V_107 ) ) )
F_98 ( & V_176 -> V_24 , & V_181 -> V_150 ) ;
V_4 -> V_187 ( V_2 , V_4 , V_19 , V_182 ,
V_176 -> V_97 ) ;
if ( V_100 == V_107 )
V_182 += 2 ;
else
V_182 ++ ;
}
V_22 = F_99 ( V_2 , V_4 -> V_188 , V_120 -> V_90 ,
F_100 ( V_120 -> V_189 ) ,
F_101 ( V_120 -> V_189 ) ,
V_190 ) ;
if ( V_22 )
goto V_186;
}
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( ( V_100 == V_166 ) ||
( V_100 == V_107 ) ) {
V_176 = V_4 -> V_62 ( V_4 , & V_19 -> V_101 . V_59 . V_55 ) ;
F_21 ( ! V_176 ) ;
V_4 -> V_191 ( V_4 , V_176 -> V_97 ) ;
F_17 ( & V_176 -> V_24 ) ;
F_6 ( V_176 ) ;
}
}
if ( ! V_183 )
return 1 ;
else
return 0 ;
V_186:
V_120 -> V_171 ( V_120 ) ;
F_9 (elem, exe_chunk, link) {
V_100 = V_19 -> V_101 . V_59 . V_100 ;
if ( V_100 == V_107 )
V_181 = V_19 -> V_101 . V_59 . V_118 ;
else
V_181 = V_4 ;
if ( ! V_21 &&
( ( V_100 == V_105 ) ||
( V_100 == V_107 ) ) ) {
V_176 = V_4 -> V_62 ( V_181 ,
& V_19 -> V_101 . V_59 . V_55 ) ;
if ( V_176 ) {
F_17 ( & V_176 -> V_24 ) ;
F_6 ( V_176 ) ;
}
}
}
return V_22 ;
}
static inline int F_102 (
struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_18 * V_19 ;
struct V_39 * V_4 = V_147 -> V_149 ;
bool V_21 = F_20 ( V_152 , & V_147 -> V_25 ) ;
V_19 = F_25 ( V_2 ) ;
if ( ! V_19 )
return - V_177 ;
switch ( V_147 -> V_151 . V_100 ) {
case V_107 :
V_19 -> V_29 = 2 ;
break;
default:
V_19 -> V_29 = 1 ;
}
memcpy ( & V_19 -> V_101 . V_59 , & V_147 -> V_151 , sizeof( V_147 -> V_151 ) ) ;
return F_11 ( V_2 , & V_4 -> V_12 , V_19 , V_21 ) ;
}
int F_85 (
struct V_1 * V_2 ,
struct V_146 * V_147 )
{
int V_22 = 0 ;
struct V_39 * V_4 = V_147 -> V_149 ;
unsigned long * V_25 = & V_147 -> V_25 ;
bool V_192 = F_20 ( V_173 , V_25 ) ;
struct V_32 * V_38 = & V_4 -> V_38 ;
if ( ! V_192 ) {
V_22 = F_102 ( V_2 , V_147 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! F_24 ( & V_4 -> V_12 ) )
V_22 = 1 ;
if ( F_20 ( V_28 , V_25 ) ) {
F_4 ( V_17 , L_5
L_43 ) ;
V_38 -> V_171 ( V_38 ) ;
}
if ( V_192 || F_20 ( V_193 , V_25 ) ||
F_20 ( V_194 , V_25 ) ) {
V_22 = F_19 ( V_2 , & V_4 -> V_12 , V_25 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( F_20 ( V_194 , & V_147 -> V_25 ) ) {
int V_195 = F_7 ( & V_4 -> V_12 ) + 1 ;
while ( ! F_24 ( & V_4 -> V_12 ) &&
V_195 -- ) {
V_22 = V_38 -> V_168 ( V_2 , V_38 ) ;
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
static int F_103 ( struct V_1 * V_2 ,
struct V_39 * V_4 ,
unsigned long * V_106 ,
unsigned long * V_25 )
{
struct V_51 * V_52 = NULL ;
int V_22 = 0 ;
struct V_146 V_147 ;
struct V_3 * V_157 = & V_4 -> V_12 ;
struct V_18 * V_196 , * V_197 ;
F_8 ( & V_157 -> V_14 ) ;
F_104 (exeq_pos, exeq_pos_n, &exeq->exe_queue, link) {
if ( V_196 -> V_101 . V_59 . V_106 ==
* V_106 )
F_17 ( & V_196 -> V_24 ) ;
}
F_10 ( & V_157 -> V_14 ) ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_149 = V_4 ;
V_147 . V_25 = * V_25 ;
V_147 . V_151 . V_100 = V_166 ;
F_105 ( V_194 , & V_147 . V_25 ) ;
F_105 ( V_193 , & V_147 . V_25 ) ;
F_105 ( V_173 , & V_147 . V_25 ) ;
F_9 (pos, &o->head, link) {
if ( V_52 -> V_106 == * V_106 ) {
V_147 . V_151 . V_106 = V_52 -> V_106 ;
memcpy ( & V_147 . V_151 . V_55 , & V_52 -> V_55 , sizeof( V_52 -> V_55 ) ) ;
V_22 = F_85 ( V_2 , & V_147 ) ;
if ( V_22 < 0 ) {
F_12 ( L_44 ) ;
return V_22 ;
}
}
}
V_147 . V_25 = * V_25 ;
F_84 ( V_173 , & V_147 . V_25 ) ;
return F_85 ( V_2 , & V_147 ) ;
}
static inline void F_106 ( struct V_32 * V_38 , T_5 V_85 ,
T_6 V_90 , T_5 V_86 , void * V_99 , T_8 V_189 , int V_33 ,
unsigned long * V_34 , T_9 type )
{
V_38 -> V_86 = V_86 ;
V_38 -> V_90 = V_90 ;
V_38 -> V_85 = V_85 ;
V_38 -> V_99 = V_99 ;
V_38 -> V_189 = V_189 ;
V_38 -> V_33 = V_33 ;
V_38 -> V_34 = V_34 ;
V_38 -> V_65 = type ;
V_38 -> V_184 = F_27 ;
V_38 -> V_171 = F_28 ;
V_38 -> V_185 = F_32 ;
V_38 -> V_168 = F_40 ;
}
static inline void F_107 ( struct V_39 * V_4 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 , T_8 V_189 ,
int V_33 , unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
F_2 ( & V_4 -> V_150 ) ;
V_4 -> V_43 = V_43 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_198 = F_103 ;
V_4 -> V_21 = F_81 ;
V_4 -> V_199 = F_94 ;
V_4 -> V_200 = F_93 ;
F_106 ( & V_4 -> V_38 , V_85 , V_90 , V_86 , V_99 , V_189 ,
V_33 , V_34 , type ) ;
}
void F_108 ( struct V_1 * V_2 ,
struct V_39 * V_201 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_189 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 )
{
union V_6 * V_202 = (union V_6 * ) V_201 ;
F_107 ( V_201 , V_85 , V_90 , V_86 , V_99 ,
V_189 , V_33 , V_34 , type ,
V_43 , NULL ) ;
V_201 -> V_159 = F_42 ;
V_201 -> V_161 = F_47 ;
V_201 -> V_178 = F_41 ;
V_201 -> V_191 = F_46 ;
if ( F_109 ( V_2 ) ) {
V_201 -> V_187 = F_77 ;
V_201 -> V_62 = F_55 ;
V_201 -> V_63 = F_51 ;
V_201 -> V_165 = F_59 ;
V_201 -> V_188 = V_203 ;
F_1 ( V_2 ,
& V_201 -> V_12 , 1 , V_202 ,
F_92 ,
F_95 ,
F_97 ,
F_86 ) ;
} else {
V_201 -> V_187 = F_68 ;
V_201 -> V_62 = F_55 ;
V_201 -> V_63 = F_51 ;
V_201 -> V_165 = F_58 ;
V_201 -> V_188 =
V_204 ;
F_1 ( V_2 ,
& V_201 -> V_12 , V_205 ,
V_202 , F_92 ,
F_95 ,
F_97 ,
F_86 ) ;
}
}
void F_110 ( struct V_1 * V_2 ,
struct V_39 * V_206 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_189 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_46 )
{
union V_6 * V_202 = (union V_6 * ) V_206 ;
F_107 ( V_206 , V_85 , V_90 , V_86 , V_99 ,
V_189 , V_33 , V_34 , type , NULL ,
V_46 ) ;
V_206 -> V_159 = F_44 ;
V_206 -> V_161 = F_49 ;
V_206 -> V_178 = F_43 ;
V_206 -> V_191 = F_48 ;
if ( F_109 ( V_2 ) ) {
F_12 ( L_45 ) ;
F_111 () ;
} else {
V_206 -> V_187 = F_78 ;
V_206 -> V_62 = F_56 ;
V_206 -> V_63 = F_53 ;
V_206 -> V_165 = F_58 ;
V_206 -> V_188 =
V_204 ;
F_1 ( V_2 ,
& V_206 -> V_12 , V_205 ,
V_202 , F_92 ,
F_95 ,
F_97 ,
F_87 ) ;
}
}
void F_112 ( struct V_1 * V_2 ,
struct V_39 * V_149 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , void * V_99 ,
T_8 V_189 , int V_33 ,
unsigned long * V_34 , T_9 type ,
struct V_41 * V_43 ,
struct V_41 * V_46 )
{
union V_6 * V_202 =
(union V_6 * ) V_149 ;
F_107 ( V_149 , V_85 , V_90 , V_86 , V_99 ,
V_189 , V_33 , V_34 , type ,
V_43 , V_46 ) ;
V_149 -> V_159 = F_45 ;
V_149 -> V_161 = F_50 ;
V_149 -> V_178 = F_41 ;
V_149 -> V_191 = F_46 ;
if ( F_113 ( V_2 ) ) {
F_12 ( L_46 ) ;
F_111 () ;
} else if ( F_114 ( V_2 ) ) {
V_149 -> V_187 = F_80 ;
V_149 -> V_62 = F_57 ;
V_149 -> V_63 = F_54 ;
V_149 -> V_165 = F_59 ;
V_149 -> V_188 = V_203 ;
F_1 ( V_2 ,
& V_149 -> V_12 , 1 , V_202 ,
F_92 ,
F_95 ,
F_97 ,
F_88 ) ;
} else {
V_149 -> V_187 = F_79 ;
V_149 -> V_62 = F_57 ;
V_149 -> V_63 = F_54 ;
V_149 -> V_165 = F_58 ;
V_149 -> V_188 =
V_204 ;
F_1 ( V_2 ,
& V_149 -> V_12 ,
V_205 ,
V_202 , F_92 ,
F_95 ,
F_97 ,
F_88 ) ;
}
}
static inline void F_115 ( struct V_1 * V_2 ,
struct V_207 * V_208 ,
T_7 V_127 )
{
T_10 V_209 = sizeof( struct V_207 ) ;
T_6 V_210 = V_211 +
F_116 ( V_127 ) ;
F_117 ( V_2 , V_210 , V_209 , ( T_6 * ) V_208 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_212 * V_147 )
{
T_6 V_213 = ( 1 << V_147 -> V_85 ) ;
struct V_207 * V_208 =
(struct V_207 * ) V_147 -> V_99 ;
T_5 V_214 = 1 , V_215 = 1 ;
T_5 V_216 = 0 , V_217 = 0 , V_218 = 0 ;
T_5 V_219 = 0 ;
if ( F_20 ( V_220 , & V_147 -> V_221 ) )
V_214 = 0 ;
if ( F_20 ( V_222 , & V_147 -> V_221 ) )
V_215 = 0 ;
if ( F_20 ( V_223 , & V_147 -> V_221 ) ) {
V_214 = 0 ;
V_216 = 1 ;
}
if ( F_20 ( V_224 , & V_147 -> V_221 ) ) {
V_215 = 0 ;
V_218 = 1 ;
}
if ( F_20 ( V_225 , & V_147 -> V_221 ) )
V_217 = 1 ;
if ( F_20 ( V_226 , & V_147 -> V_221 ) )
V_219 = 1 ;
V_208 -> V_227 = V_214 ?
V_208 -> V_227 | V_213 :
V_208 -> V_227 & ~ V_213 ;
V_208 -> V_228 = V_215 ?
V_208 -> V_228 | V_213 :
V_208 -> V_228 & ~ V_213 ;
V_208 -> V_229 = V_216 ?
V_208 -> V_229 | V_213 :
V_208 -> V_229 & ~ V_213 ;
V_208 -> V_230 = V_218 ?
V_208 -> V_230 | V_213 :
V_208 -> V_230 & ~ V_213 ;
V_208 -> V_231 = V_217 ?
V_208 -> V_231 | V_213 :
V_208 -> V_231 & ~ V_213 ;
V_208 -> V_219 = V_219 ?
V_208 -> V_219 | V_213 :
V_208 -> V_219 & ~ V_213 ;
F_4 ( V_17 , L_47
L_48 ,
V_208 -> V_227 ,
V_208 -> V_228 ,
V_208 -> V_229 ,
V_208 -> V_230 ,
V_208 -> V_231 ) ;
F_115 ( V_2 , V_208 , V_147 -> V_86 ) ;
F_30 ( V_147 -> V_33 , V_147 -> V_34 ) ;
F_31 () ;
return 0 ;
}
static inline void F_119 ( T_6 V_90 ,
struct V_91 * V_83 ,
T_5 V_92 )
{
V_83 -> V_93 = V_90 ;
V_83 -> V_92 = V_92 ;
}
static inline void F_120 ( struct V_1 * V_2 ,
unsigned long V_232 ,
struct V_233 * V_100 ,
bool V_234 )
{
T_7 V_33 ;
V_33 = V_235 |
V_236 ;
if ( V_232 ) {
if ( F_20 ( V_220 , & V_232 ) )
V_33 &= ~ V_235 ;
if ( F_20 ( V_222 , & V_232 ) )
V_33 &= ~ V_236 ;
if ( F_20 ( V_223 , & V_232 ) ) {
V_33 &= ~ V_235 ;
V_33 |= V_237 ;
}
if ( F_20 ( V_224 , & V_232 ) ) {
V_33 |= V_238 ;
V_33 &= ~ V_236 ;
}
if ( F_20 ( V_225 , & V_232 ) )
V_33 |= V_239 ;
if ( F_20 ( V_226 , & V_232 ) ) {
V_33 &= ~ V_235 ;
V_33 |= V_240 ;
}
if ( F_20 ( V_241 , & V_232 ) )
V_33 |= V_242 ;
}
if ( V_234 ) {
V_33 &= ~ V_238 ;
V_33 &= ~ V_239 ;
V_33 &= ~ V_237 ;
V_33 &= ~ V_240 ;
}
V_100 -> V_33 = F_74 ( V_33 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_212 * V_147 )
{
struct V_243 * V_50 = V_147 -> V_99 ;
int V_22 ;
T_5 V_96 = 0 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
if ( F_20 ( V_244 , & V_147 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = V_147 -> V_85 ;
V_50 -> V_104 [ V_96 ] . V_86 = V_147 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_245 ;
F_120 ( V_2 , V_147 -> V_246 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) , false ) ;
}
if ( F_20 ( V_247 , & V_147 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = V_147 -> V_85 ;
V_50 -> V_104 [ V_96 ] . V_86 = V_147 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_248 ;
F_120 ( V_2 , V_147 -> V_221 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) , false ) ;
}
if ( F_20 ( V_249 , & V_147 -> V_250 ) ) {
if ( F_20 ( V_244 , & V_147 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = F_122 ( V_2 , V_85 ) ;
V_50 -> V_104 [ V_96 ] . V_86 = V_147 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_245 ;
F_120 ( V_2 , V_147 -> V_246 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) ,
true ) ;
}
if ( F_20 ( V_247 , & V_147 -> V_25 ) ) {
V_50 -> V_104 [ V_96 ] . V_84 = F_122 ( V_2 , V_85 ) ;
V_50 -> V_104 [ V_96 ] . V_86 = V_147 -> V_86 ;
V_50 -> V_104 [ V_96 ] . V_87 =
V_248 ;
F_120 ( V_2 , V_147 -> V_221 ,
& ( V_50 -> V_104 [ V_96 ++ ] ) ,
true ) ;
}
}
F_119 ( V_147 -> V_90 , & V_50 -> V_113 , V_96 ) ;
F_4 ( V_17 , L_49
L_50 ,
V_50 -> V_113 . V_92 , V_147 -> V_221 ,
V_147 -> V_246 ) ;
V_22 = F_99 ( V_2 , V_251 , V_147 -> V_90 ,
F_100 ( V_147 -> V_189 ) ,
F_101 ( V_147 -> V_189 ) ,
V_190 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_212 * V_147 )
{
return F_34 ( V_2 , V_147 -> V_33 , V_147 -> V_34 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_212 * V_147 )
{
return 0 ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_212 * V_147 )
{
int V_22 ;
V_22 = V_147 -> V_252 -> V_253 ( V_2 , V_147 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_20 ( V_194 , & V_147 -> V_25 ) ) {
V_22 = V_147 -> V_252 -> V_168 ( V_2 , V_147 ) ;
if ( V_22 )
return V_22 ;
}
return V_22 ;
}
void F_126 ( struct V_1 * V_2 ,
struct V_254 * V_4 )
{
if ( F_109 ( V_2 ) ) {
V_4 -> V_168 = F_124 ;
V_4 -> V_253 = F_118 ;
} else {
V_4 -> V_168 = F_123 ;
V_4 -> V_253 = F_121 ;
}
}
static inline T_5 F_127 ( T_5 * V_53 )
{
return ( F_128 ( 0 , V_53 , V_56 ) >> 24 ) & 0xff ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_255 * V_4 )
{
if ( F_34 ( V_2 , V_4 -> V_256 , V_4 -> V_38 . V_34 ) ||
V_4 -> V_38 . V_168 ( V_2 , & V_4 -> V_38 ) )
return - V_37 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_255 * V_4 ,
struct V_257 * V_147 ,
int V_100 )
{
int V_258 ;
struct V_259 * V_260 ;
struct V_261 * V_262 = NULL ;
struct V_263 * V_52 ;
int V_264 = ( ( V_100 == V_265 ) ?
V_147 -> V_266 : 0 ) ;
if ( ! V_147 -> V_266 )
return 0 ;
V_258 = sizeof( * V_260 ) +
V_264 * sizeof( struct V_261 ) ;
V_260 = F_26 ( V_258 , V_31 ) ;
if ( ! V_260 )
return - V_177 ;
F_4 ( V_17 , L_51
L_52 , V_100 , V_264 ) ;
F_2 ( & V_260 -> V_50 . V_267 ) ;
V_260 -> type = V_100 ;
V_260 -> V_268 = false ;
switch ( V_100 ) {
case V_265 :
V_262 = (struct V_261 * )
( ( T_5 * ) V_260 + sizeof( * V_260 ) ) ;
F_9 (pos, &p->mcast_list, link) {
memcpy ( V_262 -> V_53 , V_52 -> V_53 , V_56 ) ;
F_13 ( & V_262 -> V_24 , & V_260 -> V_50 . V_267 ) ;
V_262 ++ ;
}
break;
case V_269 :
V_260 -> V_50 . V_270 = V_147 -> V_266 ;
break;
case V_271 :
V_260 -> V_50 . V_272 = 0 ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return - V_54 ;
}
F_13 ( & V_260 -> V_24 , & V_4 -> V_273 ) ;
V_4 -> V_274 ( V_4 ) ;
return 1 ;
}
static inline int F_131 ( struct V_255 * V_4 , int V_275 )
{
int V_276 , V_277 , V_278 = V_275 % V_279 ;
for ( V_276 = V_275 / V_279 ; V_276 < V_280 ; V_276 ++ ) {
if ( V_4 -> V_281 . V_282 . V_283 [ V_276 ] )
for ( V_277 = V_278 ; V_277 < V_279 ; V_277 ++ ) {
int V_284 = V_277 + V_279 * V_276 ;
if ( F_132 ( V_4 -> V_281 . V_282 .
V_283 , V_284 ) ) {
return V_284 ;
}
}
V_278 = 0 ;
}
return - 1 ;
}
static inline int F_133 ( struct V_255 * V_4 )
{
int V_284 = F_131 ( V_4 , 0 ) ;
if ( V_284 >= 0 )
F_134 ( V_4 -> V_281 . V_282 . V_283 , V_284 ) ;
return V_284 ;
}
static inline T_5 F_135 ( struct V_255 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
T_5 V_64 = 0 ;
if ( ( V_38 -> V_65 == V_66 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_285 ;
if ( ( V_38 -> V_65 == V_69 ) ||
( V_38 -> V_65 == V_67 ) )
V_64 |= V_286 ;
return V_64 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_255 * V_4 , int V_182 ,
union V_287 * V_288 ,
int V_100 )
{
struct V_32 * V_120 = & V_4 -> V_38 ;
struct V_289 * V_50 =
(struct V_289 * ) ( V_120 -> V_99 ) ;
T_5 V_86 = V_120 -> V_86 ;
T_5 V_290 = F_135 ( V_4 ) ;
int V_291 ;
if ( ( V_100 == V_265 ) || ( V_100 == V_271 ) )
V_290 |= V_292 ;
V_50 -> V_104 [ V_182 ] . V_87 |= V_290 ;
switch ( V_100 ) {
case V_265 :
V_291 = F_127 ( V_288 -> V_53 ) ;
F_137 ( V_4 -> V_281 . V_282 . V_283 , V_291 ) ;
break;
case V_269 :
V_291 = F_133 ( V_4 ) ;
break;
case V_271 :
V_291 = V_288 -> V_291 ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return;
}
F_4 ( V_17 , L_54 ,
( ( V_290 & V_292 ) ?
L_55 : L_56 ) , V_291 ) ;
V_50 -> V_104 [ V_182 ] . V_293 = ( T_5 ) V_291 ;
V_50 -> V_104 [ V_182 ] . V_86 = V_86 ;
V_50 -> V_104 [ V_182 ] . V_294 = V_4 -> V_294 ;
}
static inline int F_138 (
struct V_1 * V_2 , struct V_255 * V_4 , int V_295 ,
int * V_296 )
{
int V_297 , V_20 = * V_296 ;
union V_287 V_288 = { 0 } ;
for ( V_297 = F_131 ( V_4 , V_295 ) ; V_297 >= 0 ;
V_297 = F_131 ( V_4 , V_297 + 1 ) ) {
V_288 . V_291 = ( T_5 ) V_297 ;
V_4 -> V_187 ( V_2 , V_4 , V_20 , & V_288 ,
V_271 ) ;
V_20 ++ ;
F_4 ( V_17 , L_57 , V_297 ) ;
if ( V_20 >= V_4 -> V_298 )
break;
}
* V_296 = V_20 ;
return V_297 ;
}
static inline void F_139 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_259 * V_299 ,
int * V_300 )
{
struct V_261 * V_301 , * V_302 ;
int V_20 = * V_300 ;
union V_287 V_288 = { 0 } ;
F_104 (pmac_pos, pmac_pos_n, &cmd_pos->data.macs_head,
link) {
V_288 . V_53 = & V_301 -> V_53 [ 0 ] ;
V_4 -> V_187 ( V_2 , V_4 , V_20 , & V_288 , V_299 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_58 V_114
L_59 ,
F_69 ( V_301 -> V_53 ) ) ;
F_17 ( & V_301 -> V_24 ) ;
if ( V_20 >= V_4 -> V_298 )
break;
}
* V_300 = V_20 ;
if ( F_15 ( & V_299 -> V_50 . V_267 ) )
V_299 -> V_268 = true ;
}
static inline void F_140 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_259 * V_299 ,
int * V_300 )
{
int V_20 = * V_300 ;
while ( V_299 -> V_50 . V_270 ) {
V_4 -> V_187 ( V_2 , V_4 , V_20 , NULL , V_299 -> type ) ;
V_20 ++ ;
V_299 -> V_50 . V_270 -- ;
F_4 ( V_17 , L_60 ,
V_299 -> V_50 . V_270 , V_20 ) ;
if ( V_20 >= V_4 -> V_298 )
break;
}
* V_300 = V_20 ;
if ( ! V_299 -> V_50 . V_270 )
V_299 -> V_268 = true ;
}
static inline void F_141 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_259 * V_299 ,
int * V_300 )
{
V_299 -> V_50 . V_272 = V_4 -> V_303 ( V_2 , V_4 , V_299 -> V_50 . V_272 ,
V_300 ) ;
if ( V_299 -> V_50 . V_272 < 0 )
V_299 -> V_268 = true ;
else
V_299 -> V_50 . V_272 ++ ;
}
static inline int F_142 ( struct V_1 * V_2 ,
struct V_257 * V_147 )
{
struct V_259 * V_299 , * V_304 ;
int V_20 = 0 ;
struct V_255 * V_4 = V_147 -> V_305 ;
F_104 (cmd_pos, cmd_pos_n, &o->pending_cmds_head,
link) {
switch ( V_299 -> type ) {
case V_265 :
F_139 ( V_2 , V_4 , V_299 , & V_20 ) ;
break;
case V_269 :
F_140 ( V_2 , V_4 , V_299 , & V_20 ) ;
break;
case V_271 :
F_141 ( V_2 , V_4 , V_299 ,
& V_20 ) ;
break;
default:
F_12 ( L_53 , V_299 -> type ) ;
return - V_54 ;
}
if ( V_299 -> V_268 ) {
F_17 ( & V_299 -> V_24 ) ;
F_6 ( V_299 ) ;
}
if ( V_20 >= V_4 -> V_298 )
break;
}
return V_20 ;
}
static inline void F_143 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_257 * V_147 ,
int * V_300 )
{
struct V_263 * V_306 ;
union V_287 V_288 = { 0 } ;
int V_20 = * V_300 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_288 . V_53 = V_306 -> V_53 ;
V_4 -> V_187 ( V_2 , V_4 , V_20 , & V_288 , V_265 ) ;
V_20 ++ ;
F_4 ( V_17 , L_58 V_114
L_59 ,
F_69 ( V_306 -> V_53 ) ) ;
}
* V_300 = V_20 ;
}
static inline void F_144 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_257 * V_147 ,
int * V_300 )
{
int V_20 = * V_300 , V_276 ;
for ( V_276 = 0 ; V_276 < V_147 -> V_266 ; V_276 ++ ) {
V_4 -> V_187 ( V_2 , V_4 , V_20 , NULL , V_269 ) ;
V_20 ++ ;
F_4 ( V_17 , L_61 ,
V_147 -> V_266 - V_276 - 1 ) ;
}
* V_300 = V_20 ;
}
static inline int F_145 ( struct V_1 * V_2 ,
struct V_257 * V_147 , int V_100 ,
int V_307 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
int V_20 = V_307 ;
F_4 ( V_17 , L_62 , V_147 -> V_266 ) ;
switch ( V_100 ) {
case V_265 :
F_143 ( V_2 , V_4 , V_147 , & V_20 ) ;
break;
case V_269 :
F_144 ( V_2 , V_4 , V_147 , & V_20 ) ;
break;
case V_271 :
V_4 -> V_303 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return - V_54 ;
}
V_147 -> V_266 = 0 ;
return V_20 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
int V_308 = V_4 -> V_309 ( V_4 ) ;
switch ( V_100 ) {
case V_269 :
V_4 -> V_310 ( V_4 , 0 ) ;
case V_271 :
V_147 -> V_266 = V_308 ;
break;
case V_265 :
case V_311 :
V_4 -> V_310 ( V_4 , V_308 + V_147 -> V_266 ) ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return - V_54 ;
}
V_4 -> V_312 += V_147 -> V_266 ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_313 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
V_4 -> V_310 ( V_4 , V_313 ) ;
V_4 -> V_312 -= V_147 -> V_266 ;
}
static inline void F_148 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
T_5 V_314 )
{
struct V_32 * V_120 = & V_147 -> V_305 -> V_38 ;
struct V_289 * V_50 =
(struct V_289 * ) ( V_120 -> V_99 ) ;
V_50 -> V_113 . V_93 = ( ( V_120 -> V_90 & V_94 ) |
( V_315 << V_95 ) ) ;
V_50 -> V_113 . V_92 = V_314 ;
}
static inline int F_149 ( struct V_1 * V_2 ,
struct V_255 * V_4 )
{
int V_276 , V_20 = 0 ;
T_11 V_19 ;
for ( V_276 = 0 ; V_276 < V_280 ; V_276 ++ ) {
V_19 = V_4 -> V_281 . V_282 . V_283 [ V_276 ] ;
for (; V_19 ; V_20 ++ )
V_19 &= V_19 - 1 ;
}
V_4 -> V_310 ( V_4 , V_20 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
struct V_32 * V_38 = & V_147 -> V_305 -> V_38 ;
struct V_255 * V_4 = V_147 -> V_305 ;
struct V_289 * V_50 =
(struct V_289 * ) ( V_38 -> V_99 ) ;
int V_20 = 0 , V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_20 = F_142 ( V_2 , V_147 ) ;
if ( F_15 ( & V_4 -> V_273 ) )
V_4 -> V_316 ( V_4 ) ;
if ( V_147 -> V_266 > 0 )
V_20 = F_145 ( V_2 , V_147 , V_100 , V_20 ) ;
V_4 -> V_312 -= V_20 ;
F_21 ( V_4 -> V_312 < 0 ) ;
F_21 ( V_20 > V_4 -> V_298 ) ;
F_148 ( V_2 , V_147 , ( T_5 ) V_20 ) ;
if ( ! V_4 -> V_312 )
F_149 ( V_2 , V_4 ) ;
if ( F_20 ( V_28 , & V_147 -> V_25 ) ) {
V_38 -> V_171 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_99 ( V_2 , V_317 ,
V_38 -> V_90 , F_100 ( V_38 -> V_189 ) ,
F_101 ( V_38 -> V_189 ) ,
V_190 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_151 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
if ( ( V_100 == V_269 ) || ( V_100 == V_271 ) )
V_147 -> V_266 = 1 ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_313 )
{
}
static inline void F_153 ( struct V_1 * V_2 ,
struct V_255 * V_4 ,
struct V_257 * V_147 ,
T_6 * V_318 )
{
struct V_263 * V_306 ;
int V_319 ;
F_9 (mlist_pos, &p->mcast_list, link) {
V_319 = F_127 ( V_306 -> V_53 ) ;
F_154 ( V_318 , V_319 ) ;
F_4 ( V_17 , L_58
V_114 L_63 ,
F_69 ( V_306 -> V_53 ) , V_319 ) ;
F_137 ( V_4 -> V_281 . V_282 . V_283 ,
V_319 ) ;
}
}
static inline void F_155 ( struct V_1 * V_2 ,
struct V_255 * V_4 , struct V_257 * V_147 ,
T_6 * V_318 )
{
int V_319 ;
for ( V_319 = F_131 ( V_4 , 0 ) ;
V_319 >= 0 ;
V_319 = F_131 ( V_4 , V_319 + 1 ) ) {
F_154 ( V_318 , V_319 ) ;
F_4 ( V_17 , L_64 , V_319 ) ;
}
}
static int F_156 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
int V_276 ;
struct V_255 * V_4 = V_147 -> V_305 ;
struct V_32 * V_120 = & V_4 -> V_38 ;
if ( ! F_20 ( V_28 , & V_147 -> V_25 ) ) {
T_6 V_318 [ V_320 ] = { 0 } ;
switch ( V_100 ) {
case V_265 :
F_153 ( V_2 , V_4 , V_147 , V_318 ) ;
break;
case V_269 :
F_4 ( V_17 , L_65
L_66 ) ;
memset ( V_4 -> V_281 . V_282 . V_283 , 0 ,
sizeof( V_4 -> V_281 . V_282 . V_283 ) ) ;
break;
case V_271 :
F_155 ( V_2 , V_4 , V_147 , V_318 ) ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return - V_54 ;
}
for ( V_276 = 0 ; V_276 < V_320 ; V_276 ++ )
F_65 ( V_2 , F_157 ( V_2 , V_276 ) , V_318 [ V_276 ] ) ;
} else
memset ( V_4 -> V_281 . V_282 . V_283 , 0 ,
sizeof( V_4 -> V_281 . V_282 . V_283 ) ) ;
V_120 -> V_171 ( V_120 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
int V_308 = V_4 -> V_309 ( V_4 ) ;
switch ( V_100 ) {
case V_269 :
V_4 -> V_310 ( V_4 , 0 ) ;
case V_271 :
V_147 -> V_266 = V_308 ;
F_4 ( V_17 , L_67 ,
V_100 , V_147 -> V_266 ) ;
break;
case V_265 :
case V_311 :
if ( V_147 -> V_266 > V_4 -> V_298 ) {
F_12 ( L_68
L_69 , V_4 -> V_298 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_62 , V_147 -> V_266 ) ;
if ( V_147 -> V_266 > 0 )
V_4 -> V_310 ( V_4 , V_147 -> V_266 ) ;
break;
default:
F_12 ( L_53 , V_100 ) ;
return - V_54 ;
}
if ( V_147 -> V_266 )
V_4 -> V_312 += V_4 -> V_298 ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_321 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
V_4 -> V_310 ( V_4 , V_321 ) ;
if ( V_147 -> V_266 )
V_4 -> V_312 -= V_4 -> V_298 ;
}
static void F_160 ( struct V_1 * V_2 ,
struct V_255 * V_4 , int V_182 ,
union V_287 * V_288 ,
int V_100 )
{
struct V_32 * V_120 = & V_4 -> V_38 ;
struct V_136 * V_50 =
(struct V_136 * ) ( V_120 -> V_99 ) ;
if ( ( V_100 == V_265 ) || ( V_100 == V_271 ) ) {
F_70 ( & V_50 -> V_138 [ V_182 ] . V_132 ,
& V_50 -> V_138 [ V_182 ] . V_133 ,
& V_50 -> V_138 [ V_182 ] . V_134 ,
V_288 -> V_53 ) ;
V_50 -> V_138 [ V_182 ] . V_122 = 0 ;
V_50 -> V_138 [ V_182 ] . V_127 = V_120 -> V_86 ;
V_50 -> V_138 [ V_182 ] . V_126 =
F_73 ( 1 << V_120 -> V_85 ) ;
F_75 ( V_50 -> V_138 [ V_182 ] . V_128 ,
V_129 ,
V_130 ) ;
}
}
static inline void F_161 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
T_5 V_314 )
{
struct V_32 * V_120 = & V_147 -> V_305 -> V_38 ;
struct V_136 * V_50 =
(struct V_136 * ) ( V_120 -> V_99 ) ;
T_5 V_40 = ( F_162 ( V_2 ) ?
V_322 * ( 1 + V_120 -> V_86 ) :
V_323 * ( 1 + V_120 -> V_86 ) ) ;
V_50 -> V_83 . V_40 = V_40 ;
V_50 -> V_83 . V_84 = 0xff ;
V_50 -> V_83 . V_93 = ( ( V_120 -> V_90 & V_94 ) |
( V_315 << V_95 ) ) ;
V_50 -> V_83 . V_121 = V_314 ;
}
static inline int F_163 (
struct V_1 * V_2 , struct V_255 * V_4 , int V_324 ,
int * V_296 )
{
struct V_261 * V_19 ;
int V_276 = 0 ;
union V_287 V_288 = { 0 } ;
F_9 (elem, &o->registry.exact_match.macs, link) {
V_288 . V_53 = & V_19 -> V_53 [ 0 ] ;
V_4 -> V_187 ( V_2 , V_4 , V_276 , & V_288 , V_271 ) ;
V_276 ++ ;
F_4 ( V_17 , L_58 V_114
L_59 ,
F_69 ( V_288 . V_53 ) ) ;
}
* V_296 = V_276 ;
return - 1 ;
}
static inline int F_164 (
struct V_1 * V_2 , struct V_257 * V_147 )
{
struct V_259 * V_299 ;
struct V_261 * V_301 ;
struct V_255 * V_4 = V_147 -> V_305 ;
union V_287 V_288 = { 0 } ;
int V_20 = 0 ;
if ( F_15 ( & V_4 -> V_273 ) )
return 0 ;
V_299 = F_16 ( & V_4 -> V_273 ,
struct V_259 , V_24 ) ;
switch ( V_299 -> type ) {
case V_265 :
F_9 (pmac_pos, &cmd_pos->data.macs_head, link) {
V_288 . V_53 = & V_301 -> V_53 [ 0 ] ;
V_4 -> V_187 ( V_2 , V_4 , V_20 , & V_288 , V_299 -> type ) ;
V_20 ++ ;
F_4 ( V_17 , L_58 V_114
L_59 ,
F_69 ( V_301 -> V_53 ) ) ;
}
break;
case V_269 :
V_20 = V_299 -> V_50 . V_270 ;
F_4 ( V_17 , L_70 , V_20 ) ;
break;
case V_271 :
V_4 -> V_303 ( V_2 , V_4 , 0 , & V_20 ) ;
break;
default:
F_12 ( L_53 , V_299 -> type ) ;
return - V_54 ;
}
F_17 ( & V_299 -> V_24 ) ;
F_6 ( V_299 ) ;
return V_20 ;
}
static inline void F_165 ( T_12 * V_325 , T_12 * V_326 ,
T_12 * V_327 , T_5 * V_53 )
{
V_53 [ 1 ] = ( ( T_5 * ) V_325 ) [ 0 ] ;
V_53 [ 0 ] = ( ( T_5 * ) V_325 ) [ 1 ] ;
V_53 [ 3 ] = ( ( T_5 * ) V_326 ) [ 0 ] ;
V_53 [ 2 ] = ( ( T_5 * ) V_326 ) [ 1 ] ;
V_53 [ 5 ] = ( ( T_5 * ) V_327 ) [ 0 ] ;
V_53 [ 4 ] = ( ( T_5 * ) V_327 ) [ 1 ] ;
}
static inline int F_166 ( struct V_1 * V_2 ,
struct V_255 * V_4 )
{
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_261 * V_19 ;
struct V_136 * V_50 =
(struct V_136 * ) ( V_38 -> V_99 ) ;
if ( F_167 ( V_50 -> V_138 [ 0 ] . V_128 ,
V_129 ) ) {
int V_276 , V_314 = V_50 -> V_83 . V_121 ;
if ( ! F_15 ( & V_4 -> V_281 . V_328 . V_329 ) )
return 0 ;
V_19 = F_26 ( sizeof( * V_19 ) * V_314 , V_31 ) ;
if ( ! V_19 ) {
F_12 ( L_71 ) ;
return - V_177 ;
}
for ( V_276 = 0 ; V_276 < V_314 ; V_276 ++ , V_19 ++ ) {
F_165 (
& V_50 -> V_138 [ V_276 ] . V_132 ,
& V_50 -> V_138 [ V_276 ] . V_133 ,
& V_50 -> V_138 [ V_276 ] . V_134 ,
V_19 -> V_53 ) ;
F_4 ( V_17 , L_72
V_114 L_73 ,
F_69 ( V_19 -> V_53 ) ) ;
F_13 ( & V_19 -> V_24 ,
& V_4 -> V_281 . V_328 . V_329 ) ;
}
} else {
V_19 = F_16 ( & V_4 -> V_281 . V_328 . V_329 ,
struct V_261 , V_24 ) ;
F_4 ( V_17 , L_74 ) ;
F_6 ( V_19 ) ;
F_2 ( & V_4 -> V_281 . V_328 . V_329 ) ;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
struct V_32 * V_38 = & V_4 -> V_38 ;
struct V_136 * V_50 =
(struct V_136 * ) ( V_38 -> V_99 ) ;
int V_20 = 0 , V_276 , V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
for ( V_276 = 0 ; V_276 < V_4 -> V_298 ; V_276 ++ )
F_75 ( V_50 -> V_138 [ V_276 ] . V_128 ,
V_129 ,
V_135 ) ;
V_20 = F_164 ( V_2 , V_147 ) ;
if ( F_15 ( & V_4 -> V_273 ) )
V_4 -> V_316 ( V_4 ) ;
if ( ! V_20 )
V_20 = F_145 ( V_2 , V_147 , V_100 , 0 ) ;
V_4 -> V_312 -= V_4 -> V_298 ;
F_21 ( V_20 > V_4 -> V_298 ) ;
F_161 ( V_2 , V_147 , ( T_5 ) V_20 ) ;
V_22 = F_166 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
if ( F_20 ( V_28 , & V_147 -> V_25 ) ) {
V_38 -> V_171 ( V_38 ) ;
return 0 ;
} else {
V_22 = F_99 ( V_2 , V_203 , V_38 -> V_90 ,
F_100 ( V_38 -> V_189 ) ,
F_101 ( V_38 -> V_189 ) ,
V_190 ) ;
if ( V_22 )
return V_22 ;
return 1 ;
}
}
static int F_169 ( struct V_255 * V_4 )
{
return V_4 -> V_281 . V_328 . V_330 ;
}
static int F_170 ( struct V_255 * V_4 )
{
return V_4 -> V_281 . V_282 . V_331 ;
}
static void F_171 ( struct V_255 * V_4 ,
int V_332 )
{
V_4 -> V_281 . V_328 . V_330 = V_332 ;
}
static void F_172 ( struct V_255 * V_4 ,
int V_332 )
{
V_4 -> V_281 . V_282 . V_331 = V_332 ;
}
int F_173 ( struct V_1 * V_2 ,
struct V_257 * V_147 ,
int V_100 )
{
struct V_255 * V_4 = V_147 -> V_305 ;
struct V_32 * V_120 = & V_4 -> V_38 ;
int V_22 = 0 , V_333 ;
V_333 = V_4 -> V_309 ( V_4 ) ;
V_22 = V_4 -> V_8 ( V_2 , V_147 , V_100 ) ;
if ( V_22 )
return V_22 ;
if ( ( ! V_147 -> V_266 ) && ( ! V_4 -> V_334 ( V_4 ) ) )
return 0 ;
F_4 ( V_17 , L_75
L_76 , V_4 -> V_312 ,
V_147 -> V_266 , V_4 -> V_298 ) ;
if ( V_120 -> V_184 ( V_120 ) ||
( ( V_4 -> V_298 > 0 ) && ( V_4 -> V_312 > V_4 -> V_298 ) ) ) {
V_22 = V_4 -> V_335 ( V_2 , V_147 -> V_305 , V_147 , V_100 ) ;
if ( V_22 < 0 )
goto V_336;
V_147 -> V_266 = 0 ;
}
if ( ! V_120 -> V_184 ( V_120 ) ) {
V_120 -> V_185 ( V_120 ) ;
V_22 = V_4 -> V_337 ( V_2 , V_147 , V_100 ) ;
if ( V_22 < 0 )
goto V_338;
if ( F_20 ( V_194 , & V_147 -> V_25 ) )
V_22 = V_4 -> V_168 ( V_2 , V_4 ) ;
}
return V_22 ;
V_338:
V_120 -> V_171 ( V_120 ) ;
V_336:
V_4 -> V_339 ( V_2 , V_147 , V_333 ) ;
return V_22 ;
}
static void F_174 ( struct V_255 * V_4 )
{
F_29 () ;
F_30 ( V_4 -> V_256 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static void F_175 ( struct V_255 * V_4 )
{
F_29 () ;
F_33 ( V_4 -> V_256 , V_4 -> V_38 . V_34 ) ;
F_31 () ;
}
static bool F_176 ( struct V_255 * V_4 )
{
return ! ! F_20 ( V_4 -> V_256 , V_4 -> V_38 . V_34 ) ;
}
static bool F_177 ( struct V_255 * V_4 )
{
return V_4 -> V_38 . V_184 ( & V_4 -> V_38 ) || V_4 -> V_334 ( V_4 ) ;
}
void F_178 ( struct V_1 * V_2 ,
struct V_255 * V_305 ,
T_5 V_340 , T_6 V_341 , T_5 V_86 ,
T_5 V_294 , void * V_99 , T_8 V_189 ,
int V_33 , unsigned long * V_34 , T_9 type )
{
memset ( V_305 , 0 , sizeof( * V_305 ) ) ;
F_106 ( & V_305 -> V_38 , V_340 , V_341 , V_86 ,
V_99 , V_189 , V_33 , V_34 , type ) ;
V_305 -> V_294 = V_294 ;
F_2 ( & V_305 -> V_273 ) ;
V_305 -> V_256 = V_342 ;
V_305 -> V_334 = F_176 ;
V_305 -> V_274 = F_175 ;
V_305 -> V_316 = F_174 ;
if ( F_113 ( V_2 ) ) {
V_305 -> V_337 = F_168 ;
V_305 -> V_335 = F_130 ;
V_305 -> V_303 =
F_163 ;
V_305 -> V_184 = F_177 ;
if ( F_162 ( V_2 ) )
V_305 -> V_298 = V_322 ;
else
V_305 -> V_298 = V_323 ;
V_305 -> V_168 = F_129 ;
V_305 -> V_187 = F_160 ;
V_305 -> V_8 = F_158 ;
V_305 -> V_339 = F_159 ;
V_305 -> V_309 =
F_169 ;
V_305 -> V_310 =
F_171 ;
F_2 ( & V_305 -> V_281 . V_328 . V_329 ) ;
} else if ( F_114 ( V_2 ) ) {
V_305 -> V_337 = F_156 ;
V_305 -> V_335 = NULL ;
V_305 -> V_303 = NULL ;
V_305 -> V_184 = F_177 ;
V_305 -> V_298 = - 1 ;
V_305 -> V_168 = F_129 ;
V_305 -> V_187 = NULL ;
V_305 -> V_8 = F_151 ;
V_305 -> V_339 = F_152 ;
V_305 -> V_309 =
F_170 ;
V_305 -> V_310 =
F_172 ;
} else {
V_305 -> V_337 = F_150 ;
V_305 -> V_335 = F_130 ;
V_305 -> V_303 =
F_138 ;
V_305 -> V_184 = F_177 ;
V_305 -> V_298 = 16 ;
V_305 -> V_168 = F_129 ;
V_305 -> V_187 = F_136 ;
V_305 -> V_8 = F_146 ;
V_305 -> V_339 = F_147 ;
V_305 -> V_309 =
F_170 ;
V_305 -> V_310 =
F_172 ;
}
}
static inline bool F_179 ( T_13 * V_343 , int V_344 , int V_55 )
{
int V_345 , V_346 ;
V_345 = F_180 ( V_343 ) ;
for (; ; ) {
if ( F_181 ( V_345 + V_344 >= V_55 ) )
return false ;
V_346 = F_182 ( ( V_343 ) , V_345 , V_345 + V_344 ) ;
if ( F_183 ( V_346 == V_345 ) )
break;
V_345 = V_346 ;
}
return true ;
}
static inline bool F_184 ( T_13 * V_343 , int V_344 , int V_55 )
{
int V_345 , V_346 ;
V_345 = F_180 ( V_343 ) ;
for (; ; ) {
if ( F_181 ( V_345 - V_344 < V_55 ) )
return false ;
V_346 = F_182 ( ( V_343 ) , V_345 , V_345 - V_344 ) ;
if ( F_183 ( V_346 == V_345 ) )
break;
V_345 = V_346 ;
}
return true ;
}
static bool F_185 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_186 () ;
V_22 = F_184 ( & V_4 -> V_347 , V_20 , 0 ) ;
F_186 () ;
return V_22 ;
}
static bool F_187 ( struct V_41 * V_4 , int V_20 )
{
bool V_22 ;
F_186 () ;
V_22 = F_179 ( & V_4 -> V_347 , V_20 , V_4 -> V_348 + 1 ) ;
F_186 () ;
return V_22 ;
}
static int F_188 ( struct V_41 * V_4 )
{
int V_349 ;
F_186 () ;
V_349 = F_180 ( & V_4 -> V_347 ) ;
return V_349 ;
}
static bool F_189 ( struct V_41 * V_4 ,
int V_20 )
{
return true ;
}
static bool F_190 (
struct V_41 * V_4 ,
int * V_40 )
{
int V_182 , V_283 , V_276 ;
* V_40 = - 1 ;
for ( V_283 = 0 ; V_283 < V_350 ; V_283 ++ ) {
if ( ! V_4 -> V_351 [ V_283 ] )
continue;
for ( V_182 = V_283 * V_350 , V_276 = 0 ;
V_276 < V_279 ; V_182 ++ , V_276 ++ )
if ( F_132 ( V_4 -> V_351 , V_182 ) ) {
F_134 ( V_4 -> V_351 , V_182 ) ;
* V_40 = V_4 -> V_352 + V_182 ;
return true ;
}
}
return false ;
}
static bool F_191 (
struct V_41 * V_4 ,
int V_40 )
{
if ( V_40 < V_4 -> V_352 )
return false ;
V_40 -= V_4 -> V_352 ;
if ( V_40 >= V_4 -> V_348 )
return false ;
F_137 ( V_4 -> V_351 , V_40 ) ;
return true ;
}
static bool F_192 (
struct V_41 * V_4 ,
int V_40 )
{
return true ;
}
static bool F_193 (
struct V_41 * V_4 ,
int * V_40 )
{
* V_40 = - 1 ;
return true ;
}
static inline void F_194 ( struct V_41 * V_147 ,
int V_353 , int V_347 )
{
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
memset ( & V_147 -> V_351 , 0xff , sizeof( V_147 -> V_351 ) ) ;
F_195 ( & V_147 -> V_347 , V_347 ) ;
V_147 -> V_348 = V_347 ;
V_147 -> V_352 = V_353 ;
F_186 () ;
V_147 -> V_354 = F_188 ;
if ( V_347 >= 0 ) {
V_147 -> V_47 = F_187 ;
V_147 -> V_11 = F_185 ;
V_147 -> V_48 = F_191 ;
V_147 -> V_44 = F_190 ;
} else {
V_147 -> V_47 = F_189 ;
V_147 -> V_11 = F_189 ;
V_147 -> V_48 = F_192 ;
V_147 -> V_44 = F_193 ;
}
if ( V_353 < 0 ) {
V_147 -> V_48 = F_192 ;
V_147 -> V_44 = F_193 ;
}
}
void F_196 ( struct V_1 * V_2 ,
struct V_41 * V_147 , T_5 V_86 ,
T_5 V_355 )
{
#define F_197 5
int V_356 ;
if ( F_113 ( V_2 ) ) {
if ( ! F_162 ( V_2 ) )
V_356 = ( V_357 / 2 ) - V_323 ;
else
V_356 = F_197 - V_322 ;
F_194 ( V_147 , V_86 * V_356 , V_356 ) ;
} else if ( F_114 ( V_2 ) ) {
if ( ( V_355 > 0 ) ) {
if ( ! F_162 ( V_2 ) )
V_356 = ( V_358 / ( 2 * V_355 ) ) ;
else
V_356 = F_197 ;
F_194 ( V_147 , V_86 * V_356 , V_356 ) ;
} else {
F_194 ( V_147 , 0 , 0 ) ;
}
} else {
if ( ( V_355 > 0 ) ) {
if ( ! F_162 ( V_2 ) )
V_356 = ( V_359 / V_355 ) ;
else
V_356 = F_197 ;
F_194 ( V_147 , - 1 , V_356 ) ;
} else {
F_194 ( V_147 , 0 , 0 ) ;
}
}
}
void F_198 ( struct V_1 * V_2 ,
struct V_41 * V_147 ,
T_5 V_86 ,
T_5 V_355 )
{
if ( F_109 ( V_2 ) ) {
F_194 ( V_147 , 0 , - 1 ) ;
} else {
if ( V_355 > 0 ) {
int V_347 = V_360 / V_355 ;
F_194 ( V_147 , V_86 * V_347 , V_347 ) ;
} else
F_194 ( V_147 , 0 , 0 ) ;
}
}
static inline void F_199 ( struct V_1 * V_2 ,
struct V_361 * V_147 )
{
int V_276 ;
F_4 ( V_17 , L_77 ) ;
F_4 ( V_17 , L_78 ) ;
for ( V_276 = 0 ; V_276 < V_362 ; V_276 ++ ) {
F_200 ( V_17 , L_79 , V_147 -> V_363 [ V_276 ] ) ;
if ( ( V_276 + 1 < V_362 ) &&
( ( ( V_276 + 1 ) & 0x3 ) == 0 ) ) {
F_200 ( V_17 , L_80 ) ;
F_4 ( V_17 , L_81 , V_276 + 1 ) ;
}
}
F_200 ( V_17 , L_80 ) ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_361 * V_147 )
{
struct V_364 * V_4 = V_147 -> V_365 ;
struct V_32 * V_120 = & V_4 -> V_38 ;
struct V_366 * V_50 =
(struct V_366 * ) ( V_120 -> V_99 ) ;
T_5 V_367 = 0 ;
int V_22 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_4 ( V_17 , L_82 ) ;
V_50 -> V_93 = ( V_120 -> V_90 & V_94 ) |
( V_120 -> V_33 << V_95 ) ;
if ( F_20 ( V_368 , & V_147 -> V_369 ) )
V_367 = V_370 ;
else if ( F_20 ( V_371 , & V_147 -> V_369 ) )
V_367 = V_372 ;
else if ( F_20 ( V_373 , & V_147 -> V_369 ) )
V_367 = V_374 ;
else if ( F_20 ( V_375 , & V_147 -> V_369 ) )
V_367 = V_376 ;
else if ( F_20 ( V_377 , & V_147 -> V_369 ) )
V_367 = V_378 ;
V_50 -> V_367 = V_367 ;
F_4 ( V_17 , L_83 , V_367 ) ;
if ( F_20 ( V_379 , & V_147 -> V_369 ) )
V_50 -> V_380 |=
V_381 ;
if ( F_20 ( V_382 , & V_147 -> V_369 ) )
V_50 -> V_380 |=
V_383 ;
if ( F_20 ( V_384 , & V_147 -> V_369 ) )
V_50 -> V_380 |=
V_385 ;
if ( F_20 ( V_386 , & V_147 -> V_369 ) )
V_50 -> V_380 |=
V_387 ;
V_50 -> V_388 = V_147 -> V_388 ;
V_50 -> V_389 = V_4 -> V_294 ;
F_4 ( V_17 , L_84 , V_50 -> V_389 ) ;
memcpy ( V_50 -> V_390 , V_147 -> V_363 ,
V_362 ) ;
memcpy ( V_4 -> V_363 , V_147 -> V_363 , V_362 ) ;
if ( F_202 ( V_2 ) )
F_199 ( V_2 , V_147 ) ;
if ( F_20 ( V_391 , & V_147 -> V_369 ) ) {
memcpy ( & V_50 -> V_392 [ 0 ] , & V_147 -> V_392 [ 0 ] ,
sizeof( V_50 -> V_392 ) ) ;
V_50 -> V_380 |= V_393 ;
}
V_22 = F_99 ( V_2 , V_394 , V_120 -> V_90 ,
F_100 ( V_120 -> V_189 ) ,
F_101 ( V_120 -> V_189 ) ,
V_190 ) ;
if ( V_22 < 0 )
return V_22 ;
return 1 ;
}
void F_203 ( struct V_364 * V_365 ,
T_5 * V_363 )
{
memcpy ( V_363 , V_365 -> V_363 , sizeof( V_365 -> V_363 ) ) ;
}
int F_204 ( struct V_1 * V_2 ,
struct V_361 * V_147 )
{
int V_22 ;
struct V_364 * V_4 = V_147 -> V_365 ;
struct V_32 * V_120 = & V_4 -> V_38 ;
if ( F_20 ( V_28 , & V_147 -> V_25 ) )
return 0 ;
V_120 -> V_185 ( V_120 ) ;
V_22 = V_4 -> V_395 ( V_2 , V_147 ) ;
if ( V_22 < 0 ) {
V_120 -> V_171 ( V_120 ) ;
return V_22 ;
}
if ( F_20 ( V_194 , & V_147 -> V_25 ) )
V_22 = V_120 -> V_168 ( V_2 , V_120 ) ;
return V_22 ;
}
void F_205 ( struct V_1 * V_2 ,
struct V_364 * V_365 ,
T_5 V_85 , T_6 V_90 , T_5 V_86 , T_5 V_294 ,
void * V_99 , T_8 V_189 ,
int V_33 , unsigned long * V_34 ,
T_9 type )
{
F_106 ( & V_365 -> V_38 , V_85 , V_90 , V_86 , V_99 ,
V_189 , V_33 , V_34 , type ) ;
V_365 -> V_294 = V_294 ;
V_365 -> V_395 = F_201 ;
}
int F_206 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
int V_22 , V_400 ;
unsigned long * V_401 = & V_4 -> V_401 ;
if ( V_4 -> V_402 ( V_2 , V_4 , V_397 ) )
return - V_54 ;
V_400 = V_4 -> V_185 ( V_4 , V_397 ) ;
if ( F_20 ( V_28 , & V_397 -> V_25 ) )
V_4 -> V_403 ( V_2 , V_4 , V_400 ) ;
else {
V_22 = V_4 -> V_404 ( V_2 , V_397 ) ;
if ( V_22 ) {
V_4 -> V_405 = V_406 ;
F_30 ( V_400 , V_401 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_194 , & V_397 -> V_25 ) ) {
V_22 = V_4 -> V_168 ( V_2 , V_4 , V_400 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_400 , V_401 ) ;
}
static int F_207 ( struct V_398 * V_407 ,
struct V_396 * V_397 )
{
enum V_408 V_100 = V_397 -> V_100 , V_319 ;
if ( ( V_100 == V_409 ) ||
( V_100 == V_410 ) )
V_319 = V_411 ;
else
V_319 = V_100 ;
F_33 ( V_319 , & V_407 -> V_401 ) ;
return V_319 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_398 * V_4 ,
enum V_408 V_100 )
{
return F_34 ( V_2 , V_100 , & V_4 -> V_401 ) ;
}
static int F_209 ( struct V_1 * V_2 ,
struct V_398 * V_4 ,
enum V_408 V_100 )
{
unsigned long V_412 = V_4 -> V_401 ;
if ( ! F_210 ( V_100 , & V_412 ) ) {
F_12 ( L_85
L_86 , V_100 ,
V_4 -> V_413 [ V_414 ] ,
V_4 -> V_33 , V_412 , V_4 -> V_405 ) ;
return - V_54 ;
}
if ( V_4 -> V_415 >= V_4 -> V_416 )
F_12 ( L_87 ,
V_4 -> V_415 , V_4 -> V_416 ) ;
F_4 ( V_17 , L_88
L_89 , V_100 ,
V_4 -> V_413 [ V_414 ] , V_4 -> V_405 ) ;
if ( V_4 -> V_415 )
F_4 ( V_17 , L_90 ,
V_4 -> V_413 [ V_414 ] , V_4 -> V_415 ) ;
V_4 -> V_33 = V_4 -> V_405 ;
V_4 -> V_417 = V_4 -> V_415 ;
V_4 -> V_405 = V_406 ;
F_211 () ;
F_30 ( V_100 , & V_4 -> V_401 ) ;
F_31 () ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_396 * V_418 ,
struct V_419 * V_50 )
{
struct V_420 * V_397 = & V_418 -> V_397 . V_421 ;
V_50 -> V_422 . V_423 |= F_20 ( V_424 , & V_397 -> V_128 ) *
V_425 ;
}
static void F_213 ( struct V_1 * V_2 ,
struct V_398 * V_4 ,
struct V_426 * V_397 ,
struct V_427 * V_428 ,
unsigned long * V_128 )
{
V_428 -> V_84 = V_4 -> V_85 ;
if ( F_20 ( V_429 , V_128 ) ) {
V_428 -> V_430 =
V_397 -> V_431 ;
V_428 -> V_432 = 1 ;
V_428 -> V_433 =
F_20 ( V_434 , V_128 ) ;
} else
V_428 -> V_430 =
V_435 ;
V_428 -> V_436 = F_20 ( V_437 , V_128 ) ;
V_428 -> V_438 = F_20 ( V_439 , V_128 ) ;
V_428 -> V_440 = V_397 -> V_441 ;
V_428 -> V_442 = F_74 ( V_397 -> V_442 ) ;
V_428 -> V_86 = V_4 -> V_86 ;
V_428 -> cos = V_397 -> cos ;
V_428 -> V_443 =
F_20 ( V_437 , V_128 ) ?
V_444 : V_445 ;
F_4 ( V_17 , L_91 ,
V_428 -> V_438 , V_428 -> cos , V_428 -> V_432 ) ;
}
static void F_214 ( struct V_398 * V_4 ,
struct V_446 * V_397 ,
struct V_447 * V_448 ,
unsigned long * V_128 )
{
V_448 -> V_449 =
F_20 ( V_450 , V_128 ) ;
V_448 -> V_451 =
F_74 ( V_397 -> V_451 ) ;
V_448 -> V_452 =
F_20 ( V_453 , V_128 ) ;
V_448 -> V_454 =
F_20 ( V_455 , V_128 ) ;
V_448 -> V_456 =
F_20 ( V_457 , V_128 ) ;
V_448 -> V_458 = V_397 -> V_459 ;
V_448 -> V_460 = V_397 -> V_461 ;
V_448 -> V_462 = V_397 -> V_463 ;
V_448 -> V_464 . V_465 =
F_73 ( F_101 ( V_397 -> V_466 ) ) ;
V_448 -> V_464 . V_467 =
F_73 ( F_100 ( V_397 -> V_466 ) ) ;
V_448 -> V_33 = 0 ;
}
static void F_215 ( struct V_398 * V_4 ,
struct V_468 * V_397 ,
struct V_469 * V_470 )
{
V_470 -> V_471 = F_74 ( V_397 -> V_472 ) ;
V_470 -> V_473 = F_74 ( V_397 -> V_474 ) ;
V_470 -> V_475 = F_74 ( V_397 -> V_476 ) ;
V_470 -> V_477 = F_74 ( V_397 -> V_478 ) ;
V_470 -> V_479 = F_74 ( V_397 -> V_480 ) ;
V_470 -> V_481 = F_74 ( V_397 -> V_482 ) ;
V_470 -> V_483 = F_74 ( V_397 -> V_484 ) ;
}
static void F_216 ( struct V_398 * V_4 ,
struct V_485 * V_397 ,
struct V_469 * V_470 ,
unsigned long * V_128 )
{
V_470 -> V_423 = F_20 ( V_486 , V_128 ) *
V_487 ;
V_470 -> V_488 = 0 ;
V_470 -> V_489 =
V_397 -> V_490 ;
V_470 -> V_491 =
F_20 ( V_492 , V_128 ) ;
V_470 -> V_493 = V_397 -> V_494 ;
V_470 -> V_495 = V_397 -> V_496 ;
V_470 -> V_497 = F_74 ( V_397 -> V_498 ) ;
V_470 -> V_33 = F_74 ( V_499 |
V_500 ) ;
V_470 -> V_501 = 0 ;
V_470 -> V_502 = 0 ;
V_470 -> V_503 = 0 ;
V_470 -> V_504 = 0 ;
V_470 -> V_505 =
F_20 ( V_506 , V_128 ) ;
V_470 -> V_507 =
F_20 ( V_508 , V_128 ) ;
V_470 -> V_509 = V_397 -> V_459 ;
V_470 -> V_510 = V_397 -> V_461 ;
V_470 -> V_511 = V_397 -> V_511 ;
V_470 -> V_512 = F_74 ( V_397 -> V_513 ) ;
V_470 -> V_514 = F_74 ( V_397 -> V_515 ) ;
V_470 -> V_516 . V_465 =
F_73 ( F_101 ( V_397 -> V_466 ) ) ;
V_470 -> V_516 . V_467 =
F_73 ( F_100 ( V_397 -> V_466 ) ) ;
V_470 -> V_517 . V_465 =
F_73 ( F_101 ( V_397 -> V_518 ) ) ;
V_470 -> V_517 . V_467 =
F_73 ( F_100 ( V_397 -> V_518 ) ) ;
V_470 -> V_519 . V_465 =
F_73 ( F_101 ( V_397 -> V_520 ) ) ;
V_470 -> V_519 . V_467 =
F_73 ( F_100 ( V_397 -> V_520 ) ) ;
V_470 -> V_521 = F_20 ( V_522 , V_128 ) ;
if ( F_20 ( V_523 , V_128 ) ) {
V_470 -> V_524 = V_4 -> V_86 ;
V_470 -> V_525 = 1 ;
}
V_470 -> V_389 = V_397 -> V_389 ;
V_470 -> V_526 =
F_20 ( V_527 , V_128 ) ;
V_470 -> V_528 =
F_74 ( V_397 -> V_529 ) ;
V_470 -> V_530 =
F_74 ( V_397 -> V_531 ) ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_396 * V_418 ,
struct V_419 * V_50 )
{
F_213 ( V_2 , V_418 -> V_399 ,
& V_418 -> V_397 . V_421 . V_532 ,
& V_50 -> V_533 ,
& V_418 -> V_397 . V_421 . V_128 ) ;
F_214 ( V_418 -> V_399 ,
& V_418 -> V_397 . V_421 . V_534 ,
& V_50 -> V_535 ,
& V_418 -> V_397 . V_421 . V_128 ) ;
F_216 ( V_418 -> V_399 ,
& V_418 -> V_397 . V_421 . V_536 ,
& V_50 -> V_422 ,
& V_418 -> V_397 . V_421 . V_128 ) ;
F_215 ( V_418 -> V_399 ,
& V_418 -> V_397 . V_421 . V_537 ,
& V_50 -> V_422 ) ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_396 * V_418 ,
struct V_538 * V_50 )
{
F_213 ( V_2 , V_418 -> V_399 ,
& V_418 -> V_397 . V_539 . V_532 ,
& V_50 -> V_533 ,
& V_418 -> V_397 . V_539 . V_128 ) ;
F_214 ( V_418 -> V_399 ,
& V_418 -> V_397 . V_539 . V_534 ,
& V_50 -> V_535 ,
& V_418 -> V_397 . V_539 . V_128 ) ;
F_4 ( V_17 , L_92 , V_418 -> V_399 -> V_413 [ 0 ] ,
V_50 -> V_535 . V_464 . V_465 , V_50 -> V_535 . V_464 . V_467 ) ;
}
static inline int F_219 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
struct V_540 * V_541 = & V_397 -> V_397 . V_541 ;
T_7 V_542 ;
T_5 cos ;
if ( F_20 ( V_543 , & V_4 -> type ) &&
F_20 ( V_544 , & V_541 -> V_535 . V_128 ) ) {
V_542 = V_541 -> V_535 . V_545 ? 1000000 / V_541 -> V_535 . V_545 : 0 ;
F_220 ( V_2 , V_541 -> V_535 . V_459 ,
V_541 -> V_535 . V_461 ,
! F_20 ( V_546 , & V_541 -> V_535 . V_128 ) ,
V_542 ) ;
}
if ( F_20 ( V_547 , & V_4 -> type ) &&
F_20 ( V_544 , & V_541 -> V_422 . V_128 ) ) {
V_542 = V_541 -> V_422 . V_545 ? 1000000 / V_541 -> V_422 . V_545 : 0 ;
F_220 ( V_2 , V_541 -> V_422 . V_459 ,
V_541 -> V_422 . V_461 ,
! F_20 ( V_546 , & V_541 -> V_422 . V_128 ) ,
V_542 ) ;
}
for ( cos = 0 ; cos < V_4 -> V_416 ; cos ++ ) {
F_4 ( V_17 , L_93 ,
V_4 -> V_413 [ cos ] , cos ) ;
F_4 ( V_17 , L_94 , V_541 -> V_548 [ cos ] ) ;
F_221 ( V_2 , V_541 -> V_548 [ cos ] , V_4 -> V_413 [ cos ] ) ;
}
V_4 -> V_403 ( V_2 , V_4 , V_549 ) ;
F_222 () ;
F_186 () ;
return 0 ;
}
static inline int F_223 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
struct V_419 * V_99 =
(struct V_419 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
int V_551 = V_552 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_217 ( V_2 , V_397 , V_99 ) ;
return F_99 ( V_2 , V_551 , V_4 -> V_413 [ V_414 ] ,
F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_190 ) ;
}
static inline int F_224 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
struct V_419 * V_99 =
(struct V_419 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
int V_551 = V_552 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_217 ( V_2 , V_397 , V_99 ) ;
F_212 ( V_2 , V_397 , V_99 ) ;
return F_99 ( V_2 , V_551 , V_4 -> V_413 [ V_414 ] ,
F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_190 ) ;
}
static inline int F_225 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
struct V_538 * V_99 =
(struct V_538 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
int V_551 = V_553 ;
struct V_554 * V_555 =
& V_397 -> V_397 . V_539 ;
T_5 V_556 = V_555 -> V_556 ;
if ( V_556 >= V_4 -> V_416 ) {
F_12 ( L_95 ,
V_4 -> V_85 , V_556 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_96 ,
V_555 -> V_532 . cos ,
V_555 -> V_532 . V_441 ) ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_218 ( V_2 , V_397 , V_99 ) ;
F_4 ( V_17 , L_97
L_98 ,
V_4 -> V_413 [ V_556 ] ,
V_99 -> V_533 . V_84 ,
V_99 -> V_533 . V_440 , V_99 -> V_533 . cos ) ;
return F_99 ( V_2 , V_551 , V_4 -> V_413 [ V_556 ] ,
F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_190 ) ;
}
static void F_226 ( struct V_1 * V_2 ,
struct V_398 * V_407 ,
struct V_557 * V_397 ,
struct V_558 * V_50 )
{
V_50 -> V_84 = V_407 -> V_85 ;
V_50 -> V_86 = V_407 -> V_86 ;
V_50 -> V_451 = F_74 ( V_397 -> V_559 ) ;
V_50 -> V_505 =
F_20 ( V_560 , & V_397 -> V_561 ) ;
V_50 -> V_562 =
F_20 ( V_563 ,
& V_397 -> V_561 ) ;
V_50 -> V_507 =
F_20 ( V_564 , & V_397 -> V_561 ) ;
V_50 -> V_565 =
F_20 ( V_566 ,
& V_397 -> V_561 ) ;
V_50 -> V_567 =
F_20 ( V_568 , & V_397 -> V_561 ) ;
V_50 -> V_569 =
F_20 ( V_570 , & V_397 -> V_561 ) ;
V_50 -> V_438 =
F_20 ( V_571 , & V_397 -> V_561 ) ;
V_50 -> V_572 =
F_20 ( V_573 , & V_397 -> V_561 ) ;
V_50 -> V_574 =
F_20 ( V_575 , & V_397 -> V_561 ) ;
V_50 -> V_576 =
F_20 ( V_577 ,
& V_397 -> V_561 ) ;
V_50 -> V_578 =
F_20 ( V_579 ,
& V_397 -> V_561 ) ;
V_50 -> V_526 =
F_20 ( V_580 , & V_397 -> V_561 ) ;
V_50 -> V_528 = F_74 ( V_397 -> V_529 ) ;
V_50 -> V_530 = F_74 ( V_397 -> V_531 ) ;
}
static inline int F_227 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
struct V_558 * V_99 =
(struct V_558 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
struct V_557 * V_581 =
& V_397 -> V_397 . V_582 ;
T_5 V_556 = V_581 -> V_556 ;
if ( V_556 >= V_4 -> V_416 ) {
F_12 ( L_95 ,
V_4 -> V_85 , V_556 ) ;
return - V_54 ;
}
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
F_226 ( V_2 , V_4 , V_581 , V_99 ) ;
return F_99 ( V_2 , V_583 ,
V_4 -> V_413 [ V_556 ] , F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_190 ) ;
}
static inline int F_228 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_557 * V_582 = & V_397 -> V_397 . V_582 ;
memset ( V_582 , 0 , sizeof( * V_582 ) ) ;
F_84 ( V_573 , & V_582 -> V_561 ) ;
return F_227 ( V_2 , V_397 ) ;
}
static inline int F_229 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_557 * V_582 = & V_397 -> V_397 . V_582 ;
memset ( V_582 , 0 , sizeof( * V_582 ) ) ;
F_84 ( V_571 , & V_582 -> V_561 ) ;
F_84 ( V_573 , & V_582 -> V_561 ) ;
return F_227 ( V_2 , V_397 ) ;
}
static inline int F_230 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
return - 1 ;
}
static inline int F_231 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
return F_99 ( V_2 , V_584 ,
V_4 -> V_413 [ V_414 ] , 0 , V_4 -> V_85 ,
V_190 ) ;
}
static inline int F_232 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
T_5 V_585 = V_397 -> V_397 . V_586 . V_556 ;
if ( V_585 >= V_4 -> V_416 ) {
F_12 ( L_95 ,
V_4 -> V_85 , V_585 ) ;
return - V_54 ;
}
return F_99 ( V_2 , V_587 ,
V_4 -> V_413 [ V_585 ] , 0 , 0 , V_588 ) ;
}
static inline int F_233 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
T_5 V_556 = V_397 -> V_397 . V_589 . V_556 ;
if ( V_556 >= V_4 -> V_416 ) {
F_12 ( L_95 ,
V_4 -> V_85 , V_556 ) ;
return - V_54 ;
}
return F_99 ( V_2 , V_590 ,
V_4 -> V_413 [ V_556 ] , 0 , 0 , V_190 ) ;
}
static inline int F_234 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
struct V_398 * V_4 = V_397 -> V_399 ;
return F_99 ( V_2 , V_591 ,
V_4 -> V_413 [ V_414 ] , 0 , 0 ,
V_190 ) ;
}
static inline int F_235 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
switch ( V_397 -> V_100 ) {
case V_549 :
return F_219 ( V_2 , V_397 ) ;
case V_592 :
return F_225 ( V_2 , V_397 ) ;
case V_410 :
return F_228 ( V_2 , V_397 ) ;
case V_409 :
return F_229 ( V_2 , V_397 ) ;
case V_411 :
return F_227 ( V_2 , V_397 ) ;
case V_593 :
return F_230 ( V_2 , V_397 ) ;
case V_594 :
return F_231 ( V_2 , V_397 ) ;
case V_595 :
return F_232 ( V_2 , V_397 ) ;
case V_596 :
return F_233 ( V_2 , V_397 ) ;
case V_597 :
return F_234 ( V_2 , V_397 ) ;
default:
F_12 ( L_53 , V_397 -> V_100 ) ;
return - V_54 ;
}
}
static int F_236 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
switch ( V_397 -> V_100 ) {
case V_598 :
return F_223 ( V_2 , V_397 ) ;
case V_549 :
case V_592 :
case V_410 :
case V_409 :
case V_411 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
return F_235 ( V_2 , V_397 ) ;
default:
F_12 ( L_53 , V_397 -> V_100 ) ;
return - V_54 ;
}
}
static int F_237 ( struct V_1 * V_2 ,
struct V_396 * V_397 )
{
switch ( V_397 -> V_100 ) {
case V_598 :
return F_224 ( V_2 , V_397 ) ;
case V_549 :
case V_592 :
case V_410 :
case V_409 :
case V_411 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
return F_235 ( V_2 , V_397 ) ;
default:
F_12 ( L_53 , V_397 -> V_100 ) ;
return - V_54 ;
}
}
static int F_238 ( struct V_1 * V_2 ,
struct V_398 * V_4 ,
struct V_396 * V_397 )
{
enum V_599 V_33 = V_4 -> V_33 , V_405 = V_406 ;
enum V_408 V_100 = V_397 -> V_100 ;
struct V_557 * V_581 =
& V_397 -> V_397 . V_582 ;
T_5 V_415 = V_4 -> V_417 ;
if ( F_20 ( V_28 , & V_397 -> V_25 ) ) {
V_4 -> V_401 = 0 ;
V_4 -> V_405 = V_406 ;
}
if ( V_4 -> V_401 )
return - V_37 ;
switch ( V_33 ) {
case V_600 :
if ( V_100 == V_549 )
V_405 = V_601 ;
break;
case V_601 :
if ( V_100 == V_598 ) {
if ( F_20 ( V_439 ,
& V_397 -> V_397 . V_421 . V_128 ) )
V_405 = V_602 ;
else
V_405 = V_603 ;
}
break;
case V_602 :
if ( V_100 == V_410 )
V_405 = V_603 ;
else if ( ( V_100 == V_597 ) ||
( V_100 == V_593 ) )
V_405 = V_602 ;
else if ( V_100 == V_592 ) {
V_405 = V_604 ;
V_415 = 1 ;
}
else if ( V_100 == V_594 )
V_405 = V_605 ;
else if ( V_100 == V_411 ) {
if ( F_20 ( V_573 ,
& V_581 -> V_561 ) &&
! F_20 ( V_571 ,
& V_581 -> V_561 ) )
V_405 = V_603 ;
else
V_405 = V_602 ;
}
break;
case V_604 :
if ( V_100 == V_596 )
V_405 = V_606 ;
else if ( V_100 == V_592 ) {
V_405 = V_604 ;
V_415 = V_4 -> V_417 + 1 ;
}
else if ( ( V_100 == V_597 ) ||
( V_100 == V_593 ) )
V_405 = V_604 ;
else if ( V_100 == V_411 ) {
if ( F_20 ( V_573 ,
& V_581 -> V_561 ) &&
! F_20 ( V_571 ,
& V_581 -> V_561 ) )
V_405 = V_603 ;
else
V_405 = V_604 ;
}
break;
case V_606 :
if ( V_100 == V_595 ) {
V_415 = V_4 -> V_417 - 1 ;
if ( V_415 == 0 )
V_405 = V_602 ;
else
V_405 = V_604 ;
}
break;
case V_603 :
if ( V_100 == V_409 )
V_405 = V_602 ;
else if ( ( V_100 == V_597 ) ||
( V_100 == V_593 ) )
V_405 = V_603 ;
else if ( V_100 == V_594 )
V_405 = V_605 ;
else if ( V_100 == V_411 ) {
if ( F_20 ( V_573 ,
& V_581 -> V_561 ) &&
F_20 ( V_571 ,
& V_581 -> V_561 ) ) {
if ( V_4 -> V_417 == 0 )
V_405 = V_602 ;
else
V_405 = V_604 ;
} else
V_405 = V_603 ;
}
break;
case V_605 :
if ( V_100 == V_596 )
V_405 = V_607 ;
break;
case V_607 :
if ( V_100 == V_595 )
V_405 = V_600 ;
break;
default:
F_12 ( L_99 , V_33 ) ;
}
if ( V_405 != V_406 ) {
F_4 ( V_17 , L_100 ,
V_33 , V_100 , V_405 ) ;
V_4 -> V_405 = V_405 ;
V_4 -> V_415 = V_415 ;
return 0 ;
}
F_4 ( V_17 , L_101 , V_33 , V_100 ) ;
return - V_54 ;
}
void F_239 ( struct V_1 * V_2 ,
struct V_398 * V_407 ,
T_5 V_85 , T_6 * V_413 , T_5 V_608 , T_5 V_86 ,
void * V_99 ,
T_8 V_189 , unsigned long type )
{
memset ( V_407 , 0 , sizeof( * V_407 ) ) ;
F_240 ( V_609 < V_608 ) ;
memcpy ( V_407 -> V_413 , V_413 , sizeof( V_407 -> V_413 [ 0 ] ) * V_608 ) ;
V_407 -> V_416 = V_608 ;
V_407 -> V_85 = V_85 ;
V_407 -> V_86 = V_86 ;
V_407 -> V_99 = V_99 ;
V_407 -> V_189 = V_189 ;
V_407 -> type = type ;
V_407 -> V_405 = V_406 ;
if ( F_109 ( V_2 ) )
V_407 -> V_404 = F_236 ;
else
V_407 -> V_404 = F_237 ;
V_407 -> V_402 = F_238 ;
V_407 -> V_403 = F_209 ;
V_407 -> V_168 = F_208 ;
V_407 -> V_185 = F_207 ;
}
void F_241 ( struct V_1 * V_2 ,
struct V_398 * V_407 ,
T_6 V_90 , T_5 V_73 )
{
V_407 -> V_413 [ V_73 ] = V_90 ;
}
enum V_610 F_242 ( struct V_1 * V_2 ,
struct V_611 * V_4 )
{
if ( V_4 -> V_401 )
return V_612 ;
F_243 () ;
return V_4 -> V_33 ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_611 * V_4 ,
enum V_613 V_100 )
{
return F_34 ( V_2 , V_100 , & V_4 -> V_401 ) ;
}
static inline int F_245 ( struct V_1 * V_2 ,
struct V_611 * V_4 ,
enum V_613 V_100 )
{
unsigned long V_412 = V_4 -> V_401 ;
if ( ! F_210 ( V_100 , & V_412 ) ) {
F_12 ( L_102
L_86 , V_100 , F_246 ( V_2 ) ,
V_4 -> V_33 , V_412 , V_4 -> V_405 ) ;
return - V_54 ;
}
F_4 ( V_17 , L_103
L_104 , V_100 , F_246 ( V_2 ) , V_4 -> V_405 ) ;
V_4 -> V_33 = V_4 -> V_405 ;
V_4 -> V_405 = V_612 ;
F_211 () ;
F_30 ( V_100 , & V_4 -> V_401 ) ;
F_31 () ;
return 0 ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_611 * V_4 ,
enum V_613 V_100 )
{
int V_22 = F_245 ( V_2 , V_4 , V_100 ) ;
return V_22 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_611 * V_4 ,
struct V_614 * V_397 )
{
enum V_610 V_33 = V_4 -> V_33 , V_405 = V_612 ;
enum V_613 V_100 = V_397 -> V_100 ;
if ( F_20 ( V_28 , & V_397 -> V_25 ) ) {
V_4 -> V_401 = 0 ;
V_4 -> V_405 = V_612 ;
}
if ( V_4 -> V_401 )
return - V_37 ;
switch ( V_33 ) {
case V_615 :
if ( V_100 == V_616 )
V_405 = V_617 ;
break;
case V_617 :
if ( V_100 == V_618 )
V_405 = V_619 ;
else if ( V_100 == V_620 )
V_405 = V_615 ;
break;
case V_619 :
if ( V_100 == V_621 )
V_405 = V_617 ;
else if ( V_100 == V_622 )
V_405 = V_623 ;
break;
case V_623 :
if ( V_100 == V_624 )
V_405 = V_619 ;
break;
default:
F_12 ( L_105 , V_33 ) ;
}
if ( V_405 != V_612 ) {
F_4 ( V_17 , L_106 ,
V_33 , V_100 , V_405 ) ;
V_4 -> V_405 = V_405 ;
return 0 ;
}
F_4 ( V_17 , L_107 ,
V_33 , V_100 ) ;
return - V_54 ;
}
static inline int F_249 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
return V_626 -> V_627 ( V_2 ) ;
}
static inline int F_250 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
int V_22 = V_626 -> V_628 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_249 ( V_2 , V_626 ) ;
}
static inline int F_251 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
int V_22 = V_626 -> V_629 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_250 ( V_2 , V_626 ) ;
}
static inline int F_252 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
int V_22 = V_626 -> V_630 ( V_2 ) ;
if ( V_22 )
return V_22 ;
return F_250 ( V_2 , V_626 ) ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
T_6 V_631 = V_397 -> V_397 . V_632 . V_633 ;
struct V_611 * V_4 = V_397 -> V_634 ;
const struct V_625 * V_626 = V_4 -> V_626 ;
int V_22 = 0 ;
F_4 ( V_17 , L_108 ,
F_254 ( V_2 ) , V_631 ) ;
V_22 = V_626 -> V_635 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_626 -> V_636 ( V_2 ) ;
if ( V_22 ) {
F_12 ( L_109 ) ;
goto V_637;
}
switch ( V_631 ) {
case V_638 :
V_22 = F_251 ( V_2 , V_626 ) ;
if ( V_22 )
goto V_639;
break;
case V_640 :
V_22 = F_252 ( V_2 , V_626 ) ;
if ( V_22 )
goto V_639;
break;
case V_641 :
V_22 = F_250 ( V_2 , V_626 ) ;
if ( V_22 )
goto V_639;
break;
case V_642 :
V_22 = F_249 ( V_2 , V_626 ) ;
if ( V_22 )
goto V_639;
break;
default:
F_12 ( L_110 , V_631 ) ;
V_22 = - V_54 ;
}
V_639:
V_626 -> V_643 ( V_2 ) ;
V_637:
V_626 -> V_644 ( V_2 ) ;
if ( ! V_22 )
V_4 -> V_403 ( V_2 , V_4 , V_616 ) ;
return V_22 ;
}
static inline void F_255 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
V_626 -> V_645 ( V_2 ) ;
}
static inline void F_256 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
V_626 -> V_646 ( V_2 ) ;
F_255 ( V_2 , V_626 ) ;
}
static inline void F_257 ( struct V_1 * V_2 ,
const struct V_625 * V_626 )
{
F_256 ( V_2 , V_626 ) ;
V_626 -> V_647 ( V_2 ) ;
}
static inline int F_258 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
T_6 V_648 = V_397 -> V_397 . V_649 . V_648 ;
struct V_611 * V_4 = V_397 -> V_634 ;
const struct V_625 * V_626 = V_4 -> V_626 ;
F_4 ( V_17 , L_111 , F_254 ( V_2 ) ,
V_648 ) ;
switch ( V_648 ) {
case V_650 :
F_257 ( V_2 , V_626 ) ;
break;
case V_651 :
F_256 ( V_2 , V_626 ) ;
break;
case V_652 :
F_255 ( V_2 , V_626 ) ;
break;
default:
F_12 ( L_112 ,
V_648 ) ;
break;
}
V_4 -> V_403 ( V_2 , V_4 , V_620 ) ;
return 0 ;
}
static inline int F_259 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
struct V_611 * V_4 = V_397 -> V_634 ;
struct V_653 * V_99 =
(struct V_653 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
struct V_654 * V_655 = & V_397 -> V_397 . V_656 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_657 = F_74 ( V_655 -> V_658 ) ;
V_99 -> V_659 = V_655 -> V_659 ;
V_99 -> V_660 = F_260 ( V_2 ) ;
V_99 -> V_661 = V_655 -> V_661 ;
return F_99 ( V_2 , V_662 , 0 ,
F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_588 ) ;
}
static inline int F_261 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
return F_99 ( V_2 , V_663 , 0 , 0 , 0 ,
V_588 ) ;
}
static inline int F_262 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
return F_99 ( V_2 , V_664 , 0 , 0 , 0 ,
V_588 ) ;
}
static inline int F_263 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
struct V_611 * V_4 = V_397 -> V_634 ;
struct V_665 * V_99 =
(struct V_665 * ) V_4 -> V_99 ;
T_8 V_550 = V_4 -> V_189 ;
struct V_666 * V_667 =
& V_397 -> V_397 . V_668 ;
int V_276 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_669 = V_667 -> V_669 ;
V_99 -> V_670 = V_667 -> V_670 ;
V_99 -> V_671 = V_667 -> V_671 ;
for ( V_276 = 0 ; V_276 < F_264 ( V_99 -> V_672 ) ; V_276 ++ )
V_99 -> V_672 [ V_276 ] =
V_667 -> V_672 [ V_276 ] ;
return F_99 ( V_2 , V_673 , 0 ,
F_100 ( V_550 ) ,
F_101 ( V_550 ) , V_588 ) ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
switch ( V_397 -> V_100 ) {
case V_616 :
return F_253 ( V_2 , V_397 ) ;
case V_618 :
return F_259 ( V_2 , V_397 ) ;
case V_621 :
return F_261 ( V_2 , V_397 ) ;
case V_620 :
return F_258 ( V_2 , V_397 ) ;
case V_622 :
return F_262 ( V_2 , V_397 ) ;
case V_624 :
return F_263 ( V_2 , V_397 ) ;
default:
F_12 ( L_53 , V_397 -> V_100 ) ;
return - V_54 ;
}
}
void F_266 ( struct V_1 * V_2 ,
struct V_611 * V_407 ,
void * V_99 , T_8 V_189 ,
struct V_625 * V_674 )
{
memset ( V_407 , 0 , sizeof( * V_407 ) ) ;
F_267 ( & V_407 -> V_675 ) ;
V_407 -> V_99 = V_99 ;
V_407 -> V_189 = V_189 ;
V_407 -> V_404 = F_265 ;
V_407 -> V_402 = F_248 ;
V_407 -> V_403 = F_247 ;
V_407 -> V_168 = F_244 ;
V_407 -> V_626 = V_674 ;
}
int F_268 ( struct V_1 * V_2 ,
struct V_614 * V_397 )
{
struct V_611 * V_4 = V_397 -> V_634 ;
int V_22 ;
enum V_613 V_100 = V_397 -> V_100 ;
unsigned long * V_401 = & V_4 -> V_401 ;
F_269 ( & V_4 -> V_675 ) ;
if ( V_4 -> V_402 ( V_2 , V_4 , V_397 ) ) {
F_270 ( & V_4 -> V_675 ) ;
return - V_54 ;
}
F_33 ( V_100 , V_401 ) ;
if ( F_20 ( V_28 , & V_397 -> V_25 ) ) {
F_245 ( V_2 , V_4 , V_100 ) ;
F_270 ( & V_4 -> V_675 ) ;
} else {
V_22 = V_4 -> V_404 ( V_2 , V_397 ) ;
F_270 ( & V_4 -> V_675 ) ;
if ( V_22 ) {
V_4 -> V_405 = V_612 ;
F_30 ( V_100 , V_401 ) ;
F_31 () ;
return V_22 ;
}
if ( F_20 ( V_194 , & V_397 -> V_25 ) ) {
V_22 = V_4 -> V_168 ( V_2 , V_4 , V_100 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
}
return ! ! F_20 ( V_100 , V_401 ) ;
}
