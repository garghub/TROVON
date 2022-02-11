static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , & V_6 ) ) ;
}
static inline struct V_4 * F_5 ( struct V_1 * V_7 )
{
return F_6 ( & V_7 -> V_3 ) ;
}
static struct V_1 * F_7 ( struct V_8 * V_9 )
{
if ( V_9 && V_9 -> V_10 )
return F_2 ( V_9 , struct V_1 , V_11 ) ;
else
return NULL ;
}
static struct V_12 * F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_7 = F_7 ( V_9 ) ;
if ( V_7 )
return V_7 -> V_13 ;
else
return F_2 ( V_9 , struct V_12 , V_11 ) ;
}
static T_1 F_9 ( T_1 V_14 , struct V_12 * V_13 )
{
if ( V_13 -> V_15 < 4096 && F_10 ( V_16 ,
V_13 -> V_17 + V_13 -> V_15 * V_13 -> V_18 ) )
V_13 -> V_15 = ( V_16 - V_13 -> V_17 ) / V_13 -> V_18 ;
return V_14 + ( V_14 >> 1 ) * V_13 -> V_15 ;
}
static T_1 F_11 ( struct V_1 * V_7 , int V_19 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
struct V_12 * V_13 ;
T_1 V_20 ;
if ( F_12 ( V_21 ) && ! V_5 -> V_22 )
return V_23 ;
V_13 = V_7 -> V_13 ;
V_20 = V_7 -> V_24 [ V_19 ] [ V_13 -> V_25 ] ;
if ( V_20 == 0 && V_13 -> V_25 == V_26 ) {
if ( ! F_13 ( & V_5 -> V_27 -> V_28 . V_29 ) ||
V_7 -> V_30 [ V_19 ] [ V_13 -> V_25 ] )
return V_23 ;
else
return V_31 ;
}
if ( V_13 -> V_25 == V_32 && V_7 -> V_24 [ V_19 ] [ V_26 ] &&
V_7 -> V_24 [ V_19 ] [ V_26 ] != V_7 -> V_24 [ V_19 ] [ V_32 ] ) {
T_1 V_33 ;
V_33 = F_9 ( V_7 -> V_24 [ V_19 ] [ V_26 ] , V_13 ) ;
V_20 = F_14 ( V_7 -> V_24 [ V_19 ] [ V_32 ] , V_33 ) ;
}
return V_20 ;
}
static unsigned int F_15 ( struct V_1 * V_7 , int V_19 )
{
struct V_4 * V_5 = F_5 ( V_7 ) ;
struct V_12 * V_13 ;
unsigned int V_20 ;
if ( F_12 ( V_21 ) && ! V_5 -> V_22 )
return V_34 ;
V_13 = V_7 -> V_13 ;
V_20 = V_7 -> V_30 [ V_19 ] [ V_13 -> V_25 ] ;
if ( V_20 == 0 && V_7 -> V_13 -> V_25 == V_26 ) {
if ( ! F_13 ( & V_5 -> V_27 -> V_28 . V_29 ) ||
V_7 -> V_24 [ V_19 ] [ V_13 -> V_25 ] )
return V_34 ;
else
return V_35 ;
}
if ( V_13 -> V_25 == V_32 && V_7 -> V_30 [ V_19 ] [ V_26 ] &&
V_7 -> V_30 [ V_19 ] [ V_26 ] != V_7 -> V_30 [ V_19 ] [ V_32 ] ) {
T_1 V_33 ;
V_33 = F_9 ( V_7 -> V_30 [ V_19 ] [ V_26 ] , V_13 ) ;
if ( V_33 > V_34 )
V_33 = V_34 ;
V_20 = F_16 (unsigned int, tg->iops[rw][LIMIT_MAX], adjusted) ;
}
return V_20 ;
}
static void F_17 ( struct V_36 * V_37 , struct V_1 * V_7 )
{
F_18 ( & V_37 -> V_38 ) ;
F_19 ( & V_37 -> V_39 ) ;
V_37 -> V_7 = V_7 ;
}
static void F_20 ( struct V_40 * V_40 , struct V_36 * V_37 ,
struct V_41 * V_42 )
{
F_21 ( & V_37 -> V_39 , V_40 ) ;
if ( F_13 ( & V_37 -> V_38 ) ) {
F_22 ( & V_37 -> V_38 , V_42 ) ;
F_23 ( F_5 ( V_37 -> V_7 ) ) ;
}
}
static struct V_40 * F_24 ( struct V_41 * V_42 )
{
struct V_36 * V_37 = F_25 ( V_42 , struct V_36 , V_38 ) ;
struct V_40 * V_40 ;
if ( F_13 ( V_42 ) )
return NULL ;
V_40 = F_26 ( & V_37 -> V_39 ) ;
F_27 ( ! V_40 ) ;
return V_40 ;
}
static struct V_40 * F_28 ( struct V_41 * V_42 ,
struct V_1 * * V_43 )
{
struct V_36 * V_37 = F_25 ( V_42 , struct V_36 , V_38 ) ;
struct V_40 * V_40 ;
if ( F_13 ( V_42 ) )
return NULL ;
V_40 = F_29 ( & V_37 -> V_39 ) ;
F_27 ( ! V_40 ) ;
if ( F_30 ( & V_37 -> V_39 ) ) {
F_31 ( & V_37 -> V_38 ) ;
if ( V_43 )
* V_43 = V_37 -> V_7 ;
else
F_32 ( F_5 ( V_37 -> V_7 ) ) ;
} else {
F_33 ( & V_37 -> V_38 , V_42 ) ;
}
return V_40 ;
}
static void F_34 ( struct V_8 * V_9 )
{
F_18 ( & V_9 -> V_42 [ 0 ] ) ;
F_18 ( & V_9 -> V_42 [ 1 ] ) ;
V_9 -> V_44 = V_45 ;
F_35 ( & V_9 -> V_46 , V_47 ,
( unsigned long ) V_9 ) ;
}
static struct V_2 * F_36 ( T_2 V_48 , int V_38 )
{
struct V_1 * V_7 ;
int V_19 ;
V_7 = F_37 ( sizeof( * V_7 ) , V_48 , V_38 ) ;
if ( ! V_7 )
return NULL ;
F_34 ( & V_7 -> V_11 ) ;
for ( V_19 = V_49 ; V_19 <= V_50 ; V_19 ++ ) {
F_17 ( & V_7 -> V_51 [ V_19 ] , V_7 ) ;
F_17 ( & V_7 -> V_52 [ V_19 ] , V_7 ) ;
}
F_38 ( & V_7 -> V_53 ) ;
V_7 -> V_24 [ V_49 ] [ V_32 ] = V_23 ;
V_7 -> V_24 [ V_50 ] [ V_32 ] = V_23 ;
V_7 -> V_30 [ V_49 ] [ V_32 ] = V_34 ;
V_7 -> V_30 [ V_50 ] [ V_32 ] = V_34 ;
V_7 -> V_54 [ V_49 ] [ V_32 ] = V_23 ;
V_7 -> V_54 [ V_50 ] [ V_32 ] = V_23 ;
V_7 -> V_55 [ V_49 ] [ V_32 ] = V_34 ;
V_7 -> V_55 [ V_50 ] [ V_32 ] = V_34 ;
V_7 -> V_56 = V_57 ;
V_7 -> V_58 = V_57 ;
V_7 -> V_59 = V_60 ;
V_7 -> V_61 = V_60 ;
return & V_7 -> V_3 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_5 ( V_7 ) ;
struct V_12 * V_13 = V_5 -> V_62 -> V_13 ;
struct V_8 * V_9 = & V_7 -> V_11 ;
V_9 -> V_10 = & V_13 -> V_11 ;
if ( F_12 ( V_21 ) && V_5 -> V_22 )
V_9 -> V_10 = & F_3 ( V_5 -> V_22 ) -> V_11 ;
V_7 -> V_13 = V_13 ;
}
static void F_40 ( struct V_1 * V_7 )
{
struct V_1 * V_63 = F_7 ( V_7 -> V_11 . V_10 ) ;
struct V_12 * V_13 = V_7 -> V_13 ;
int V_19 ;
for ( V_19 = V_49 ; V_19 <= V_50 ; V_19 ++ )
V_7 -> V_64 [ V_19 ] = ( V_63 && V_63 -> V_64 [ V_19 ] ) ||
( V_13 -> V_65 [ V_13 -> V_25 ] &&
( F_11 ( V_7 , V_19 ) != V_23 ||
F_15 ( V_7 , V_19 ) != V_34 ) ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_40 ( V_7 ) ;
}
static void F_42 ( struct V_12 * V_13 )
{
struct V_66 * V_67 ;
struct V_4 * V_5 ;
bool V_68 = false ;
F_43 () ;
F_44 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( V_7 -> V_24 [ V_49 ] [ V_26 ] || V_7 -> V_24 [ V_50 ] [ V_26 ] ||
V_7 -> V_30 [ V_49 ] [ V_26 ] || V_7 -> V_30 [ V_50 ] [ V_26 ] )
V_68 = true ;
}
F_45 () ;
V_13 -> V_65 [ V_26 ] = V_68 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_24 [ V_49 ] [ V_26 ] = 0 ;
V_7 -> V_24 [ V_50 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_49 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_50 ] [ V_26 ] = 0 ;
F_42 ( V_7 -> V_13 ) ;
if ( ! V_7 -> V_13 -> V_65 [ V_7 -> V_13 -> V_25 ] )
F_47 ( V_7 -> V_13 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_49 ( & V_7 -> V_11 . V_46 ) ;
F_50 ( V_7 ) ;
}
static struct V_1 *
F_51 ( struct V_8 * V_10 )
{
if ( ! V_10 -> V_69 )
return NULL ;
if ( ! V_10 -> V_70 )
V_10 -> V_70 = F_52 ( & V_10 -> V_44 ) ;
if ( V_10 -> V_70 )
return F_53 ( V_10 -> V_70 ) ;
return NULL ;
}
static void F_54 ( struct V_53 * V_71 , struct V_72 * V_73 )
{
F_55 ( V_71 , V_73 ) ;
F_38 ( V_71 ) ;
}
static void F_56 ( struct V_53 * V_71 ,
struct V_8 * V_10 )
{
if ( V_10 -> V_70 == V_71 )
V_10 -> V_70 = NULL ;
F_54 ( V_71 , & V_10 -> V_44 ) ;
-- V_10 -> V_69 ;
}
static void F_57 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
V_7 = F_51 ( V_10 ) ;
if ( ! V_7 )
return;
V_10 -> V_74 = V_7 -> V_75 ;
}
static void F_58 ( struct V_1 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_11 . V_10 ;
struct V_53 * * V_38 = & V_10 -> V_44 . V_53 ;
struct V_53 * V_22 = NULL ;
struct V_1 * V_76 ;
unsigned long V_77 = V_7 -> V_75 ;
int V_78 = 1 ;
while ( * V_38 != NULL ) {
V_22 = * V_38 ;
V_76 = F_53 ( V_22 ) ;
if ( F_59 ( V_77 , V_76 -> V_75 ) )
V_38 = & V_22 -> V_79 ;
else {
V_38 = & V_22 -> V_80 ;
V_78 = 0 ;
}
}
if ( V_78 )
V_10 -> V_70 = & V_7 -> V_53 ;
F_60 ( & V_7 -> V_53 , V_22 , V_38 ) ;
F_61 ( & V_7 -> V_53 , & V_10 -> V_44 ) ;
}
static void F_62 ( struct V_1 * V_7 )
{
F_58 ( V_7 ) ;
V_7 -> V_81 |= V_82 ;
V_7 -> V_11 . V_10 -> V_69 ++ ;
}
static void F_63 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_81 & V_82 ) )
F_62 ( V_7 ) ;
}
static void F_64 ( struct V_1 * V_7 )
{
F_56 ( & V_7 -> V_53 , V_7 -> V_11 . V_10 ) ;
V_7 -> V_81 &= ~ V_82 ;
}
static void F_65 ( struct V_1 * V_7 )
{
if ( V_7 -> V_81 & V_82 )
F_64 ( V_7 ) ;
}
static void F_66 ( struct V_8 * V_9 ,
unsigned long V_83 )
{
unsigned long V_84 = V_16 + 8 * F_8 ( V_9 ) -> V_18 ;
if ( F_67 ( V_83 , V_84 ) )
V_83 = V_84 ;
F_68 ( & V_9 -> V_46 , V_83 ) ;
F_69 ( V_9 , L_1 ,
V_83 - V_16 , V_16 ) ;
}
static bool F_70 ( struct V_8 * V_9 ,
bool V_85 )
{
if ( ! V_9 -> V_69 )
return true ;
F_57 ( V_9 ) ;
if ( V_85 || F_67 ( V_9 -> V_74 , V_16 ) ) {
F_66 ( V_9 , V_9 -> V_74 ) ;
return true ;
}
return false ;
}
static inline void F_71 ( struct V_1 * V_7 ,
bool V_19 , unsigned long V_86 )
{
V_7 -> V_87 [ V_19 ] = 0 ;
V_7 -> V_88 [ V_19 ] = 0 ;
if ( F_10 ( V_86 , V_7 -> V_89 [ V_19 ] ) )
V_7 -> V_89 [ V_19 ] = V_86 ;
V_7 -> V_90 [ V_19 ] = V_16 + V_7 -> V_13 -> V_18 ;
F_69 ( & V_7 -> V_11 ,
L_2 ,
V_19 == V_49 ? 'R' : 'W' , V_7 -> V_89 [ V_19 ] ,
V_7 -> V_90 [ V_19 ] , V_16 ) ;
}
static inline void F_72 ( struct V_1 * V_7 , bool V_19 )
{
V_7 -> V_87 [ V_19 ] = 0 ;
V_7 -> V_88 [ V_19 ] = 0 ;
V_7 -> V_89 [ V_19 ] = V_16 ;
V_7 -> V_90 [ V_19 ] = V_16 + V_7 -> V_13 -> V_18 ;
F_69 ( & V_7 -> V_11 ,
L_3 ,
V_19 == V_49 ? 'R' : 'W' , V_7 -> V_89 [ V_19 ] ,
V_7 -> V_90 [ V_19 ] , V_16 ) ;
}
static inline void F_73 ( struct V_1 * V_7 , bool V_19 ,
unsigned long V_91 )
{
V_7 -> V_90 [ V_19 ] = F_74 ( V_91 , V_7 -> V_13 -> V_18 ) ;
}
static inline void F_75 ( struct V_1 * V_7 , bool V_19 ,
unsigned long V_91 )
{
V_7 -> V_90 [ V_19 ] = F_74 ( V_91 , V_7 -> V_13 -> V_18 ) ;
F_69 ( & V_7 -> V_11 ,
L_4 ,
V_19 == V_49 ? 'R' : 'W' , V_7 -> V_89 [ V_19 ] ,
V_7 -> V_90 [ V_19 ] , V_16 ) ;
}
static bool F_76 ( struct V_1 * V_7 , bool V_19 )
{
if ( F_77 ( V_16 , V_7 -> V_89 [ V_19 ] , V_7 -> V_90 [ V_19 ] ) )
return false ;
return 1 ;
}
static inline void F_78 ( struct V_1 * V_7 , bool V_19 )
{
unsigned long V_92 , V_93 , V_94 ;
T_3 V_95 , V_96 ;
F_79 ( F_59 ( V_7 -> V_90 [ V_19 ] , V_7 -> V_89 [ V_19 ] ) ) ;
if ( F_76 ( V_7 , V_19 ) )
return;
F_73 ( V_7 , V_19 , V_16 + V_7 -> V_13 -> V_18 ) ;
V_93 = V_16 - V_7 -> V_89 [ V_19 ] ;
V_92 = V_93 / V_7 -> V_13 -> V_18 ;
if ( ! V_92 )
return;
V_96 = F_11 ( V_7 , V_19 ) * V_7 -> V_13 -> V_18 * V_92 ;
F_80 ( V_96 , V_97 ) ;
V_95 = V_96 ;
V_94 = ( F_15 ( V_7 , V_19 ) * V_7 -> V_13 -> V_18 * V_92 ) /
V_97 ;
if ( ! V_95 && ! V_94 )
return;
if ( V_7 -> V_87 [ V_19 ] >= V_95 )
V_7 -> V_87 [ V_19 ] -= V_95 ;
else
V_7 -> V_87 [ V_19 ] = 0 ;
if ( V_7 -> V_88 [ V_19 ] >= V_94 )
V_7 -> V_88 [ V_19 ] -= V_94 ;
else
V_7 -> V_88 [ V_19 ] = 0 ;
V_7 -> V_89 [ V_19 ] += V_92 * V_7 -> V_13 -> V_18 ;
F_69 ( & V_7 -> V_11 ,
L_5 ,
V_19 == V_49 ? 'R' : 'W' , V_92 , V_95 , V_94 ,
V_7 -> V_89 [ V_19 ] , V_7 -> V_90 [ V_19 ] , V_16 ) ;
}
static bool F_81 ( struct V_1 * V_7 , struct V_40 * V_40 ,
unsigned long * V_98 )
{
bool V_19 = F_82 ( V_40 ) ;
unsigned int V_99 ;
unsigned long V_100 , V_101 , V_102 ;
T_3 V_96 ;
V_100 = V_102 = V_16 - V_7 -> V_89 [ V_19 ] ;
if ( ! V_100 )
V_102 = V_7 -> V_13 -> V_18 ;
V_102 = F_74 ( V_102 , V_7 -> V_13 -> V_18 ) ;
V_96 = ( T_3 ) F_15 ( V_7 , V_19 ) * V_102 ;
F_80 ( V_96 , V_97 ) ;
if ( V_96 > V_34 )
V_99 = V_34 ;
else
V_99 = V_96 ;
if ( V_7 -> V_88 [ V_19 ] + 1 <= V_99 ) {
if ( V_98 )
* V_98 = 0 ;
return true ;
}
V_101 = ( ( V_7 -> V_88 [ V_19 ] + 1 ) * V_97 ) / F_15 ( V_7 , V_19 ) + 1 ;
if ( V_101 > V_100 )
V_101 = V_101 - V_100 ;
else
V_101 = 1 ;
if ( V_98 )
* V_98 = V_101 ;
return 0 ;
}
static bool F_83 ( struct V_1 * V_7 , struct V_40 * V_40 ,
unsigned long * V_98 )
{
bool V_19 = F_82 ( V_40 ) ;
T_3 V_103 , V_104 , V_96 ;
unsigned long V_100 , V_101 , V_102 ;
V_100 = V_102 = V_16 - V_7 -> V_89 [ V_19 ] ;
if ( ! V_100 )
V_102 = V_7 -> V_13 -> V_18 ;
V_102 = F_74 ( V_102 , V_7 -> V_13 -> V_18 ) ;
V_96 = F_11 ( V_7 , V_19 ) * V_102 ;
F_80 ( V_96 , V_97 ) ;
V_103 = V_96 ;
if ( V_7 -> V_87 [ V_19 ] + V_40 -> V_105 . V_106 <= V_103 ) {
if ( V_98 )
* V_98 = 0 ;
return true ;
}
V_104 = V_7 -> V_87 [ V_19 ] + V_40 -> V_105 . V_106 - V_103 ;
V_101 = F_84 ( V_104 * V_97 , F_11 ( V_7 , V_19 ) ) ;
if ( ! V_101 )
V_101 = 1 ;
V_101 = V_101 + ( V_102 - V_100 ) ;
if ( V_98 )
* V_98 = V_101 ;
return 0 ;
}
static bool F_85 ( struct V_1 * V_7 , struct V_40 * V_40 ,
unsigned long * V_98 )
{
bool V_19 = F_82 ( V_40 ) ;
unsigned long V_107 = 0 , V_108 = 0 , V_109 = 0 ;
F_79 ( V_7 -> V_11 . V_110 [ V_19 ] &&
V_40 != F_24 ( & V_7 -> V_11 . V_42 [ V_19 ] ) ) ;
if ( F_11 ( V_7 , V_19 ) == V_23 &&
F_15 ( V_7 , V_19 ) == V_34 ) {
if ( V_98 )
* V_98 = 0 ;
return true ;
}
if ( F_76 ( V_7 , V_19 ) && ! ( V_7 -> V_11 . V_110 [ V_19 ] ) )
F_72 ( V_7 , V_19 ) ;
else {
if ( F_59 ( V_7 -> V_90 [ V_19 ] ,
V_16 + V_7 -> V_13 -> V_18 ) )
F_75 ( V_7 , V_19 ,
V_16 + V_7 -> V_13 -> V_18 ) ;
}
if ( F_83 ( V_7 , V_40 , & V_107 ) &&
F_81 ( V_7 , V_40 , & V_108 ) ) {
if ( V_98 )
* V_98 = 0 ;
return 1 ;
}
V_109 = F_86 ( V_107 , V_108 ) ;
if ( V_98 )
* V_98 = V_109 ;
if ( F_59 ( V_7 -> V_90 [ V_19 ] , V_16 + V_109 ) )
F_75 ( V_7 , V_19 , V_16 + V_109 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_7 , struct V_40 * V_40 )
{
bool V_19 = F_82 ( V_40 ) ;
V_7 -> V_87 [ V_19 ] += V_40 -> V_105 . V_106 ;
V_7 -> V_88 [ V_19 ] ++ ;
V_7 -> V_111 [ V_19 ] += V_40 -> V_105 . V_106 ;
V_7 -> V_112 [ V_19 ] ++ ;
if ( ! F_88 ( V_40 , V_113 ) )
F_89 ( V_40 , V_113 ) ;
}
static void F_90 ( struct V_40 * V_40 , struct V_36 * V_37 ,
struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_19 = F_82 ( V_40 ) ;
if ( ! V_37 )
V_37 = & V_7 -> V_51 [ V_19 ] ;
if ( ! V_9 -> V_110 [ V_19 ] )
V_7 -> V_81 |= V_114 ;
F_20 ( V_40 , V_37 , & V_9 -> V_42 [ V_19 ] ) ;
V_9 -> V_110 [ V_19 ] ++ ;
F_63 ( V_7 ) ;
}
static void F_91 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned long V_115 = - 1 , V_116 = - 1 , V_117 = - 1 , V_75 ;
struct V_40 * V_40 ;
V_40 = F_24 ( & V_9 -> V_42 [ V_49 ] ) ;
if ( V_40 )
F_85 ( V_7 , V_40 , & V_115 ) ;
V_40 = F_24 ( & V_9 -> V_42 [ V_50 ] ) ;
if ( V_40 )
F_85 ( V_7 , V_40 , & V_116 ) ;
V_117 = F_14 ( V_115 , V_116 ) ;
V_75 = V_16 + V_117 ;
F_65 ( V_7 ) ;
V_7 -> V_75 = V_75 ;
F_63 ( V_7 ) ;
V_7 -> V_81 &= ~ V_114 ;
}
static void F_92 ( struct V_1 * V_118 ,
struct V_1 * V_63 , bool V_19 )
{
if ( F_76 ( V_63 , V_19 ) ) {
F_71 ( V_63 , V_19 ,
V_118 -> V_89 [ V_19 ] ) ;
}
}
static void F_93 ( struct V_1 * V_7 , bool V_19 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_8 * V_10 = V_9 -> V_10 ;
struct V_1 * V_63 = F_7 ( V_10 ) ;
struct V_1 * V_43 = NULL ;
struct V_40 * V_40 ;
V_40 = F_28 ( & V_9 -> V_42 [ V_19 ] , & V_43 ) ;
V_9 -> V_110 [ V_19 ] -- ;
F_87 ( V_7 , V_40 ) ;
if ( V_63 ) {
F_90 ( V_40 , & V_7 -> V_52 [ V_19 ] , V_63 ) ;
F_92 ( V_7 , V_63 , V_19 ) ;
} else {
F_20 ( V_40 , & V_7 -> V_52 [ V_19 ] ,
& V_10 -> V_42 [ V_19 ] ) ;
F_79 ( V_7 -> V_13 -> V_110 [ V_19 ] <= 0 ) ;
V_7 -> V_13 -> V_110 [ V_19 ] -- ;
}
F_78 ( V_7 , V_19 ) ;
if ( V_43 )
F_32 ( F_5 ( V_43 ) ) ;
}
static int F_94 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned int V_119 = 0 , V_120 = 0 ;
unsigned int V_121 = V_122 * 3 / 4 ;
unsigned int V_123 = V_122 - V_121 ;
struct V_40 * V_40 ;
while ( ( V_40 = F_24 ( & V_9 -> V_42 [ V_49 ] ) ) &&
F_85 ( V_7 , V_40 , NULL ) ) {
F_93 ( V_7 , F_82 ( V_40 ) ) ;
V_119 ++ ;
if ( V_119 >= V_121 )
break;
}
while ( ( V_40 = F_24 ( & V_9 -> V_42 [ V_50 ] ) ) &&
F_85 ( V_7 , V_40 , NULL ) ) {
F_93 ( V_7 , F_82 ( V_40 ) ) ;
V_120 ++ ;
if ( V_120 >= V_123 )
break;
}
return V_119 + V_120 ;
}
static int F_95 ( struct V_8 * V_10 )
{
unsigned int V_124 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_51 ( V_10 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
if ( ! V_7 )
break;
if ( F_59 ( V_16 , V_7 -> V_75 ) )
break;
F_65 ( V_7 ) ;
V_124 += F_94 ( V_7 ) ;
if ( V_9 -> V_110 [ 0 ] || V_9 -> V_110 [ 1 ] )
F_91 ( V_7 ) ;
if ( V_124 >= V_125 )
break;
}
return V_124 ;
}
static void V_47 ( unsigned long V_126 )
{
struct V_8 * V_9 = ( void * ) V_126 ;
struct V_1 * V_7 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_127 * V_62 = V_13 -> V_128 ;
struct V_8 * V_10 ;
bool V_129 ;
int V_20 ;
F_96 ( V_62 -> V_130 ) ;
if ( F_97 ( V_13 , NULL ) )
F_47 ( V_13 ) ;
V_131:
V_10 = V_9 -> V_10 ;
V_129 = false ;
while ( true ) {
F_69 ( V_9 , L_6 ,
V_9 -> V_110 [ V_49 ] + V_9 -> V_110 [ V_50 ] ,
V_9 -> V_110 [ V_49 ] , V_9 -> V_110 [ V_50 ] ) ;
V_20 = F_95 ( V_9 ) ;
if ( V_20 ) {
F_69 ( V_9 , L_7 , V_20 ) ;
V_129 = true ;
}
if ( F_70 ( V_9 , false ) )
break;
F_98 ( V_62 -> V_130 ) ;
F_99 () ;
F_96 ( V_62 -> V_130 ) ;
}
if ( ! V_129 )
goto V_132;
if ( V_10 ) {
if ( V_7 -> V_81 & V_114 ) {
F_91 ( V_7 ) ;
if ( ! F_70 ( V_10 , false ) ) {
V_9 = V_10 ;
V_7 = F_7 ( V_9 ) ;
goto V_131;
}
}
} else {
F_100 ( V_133 , & V_13 -> V_134 ) ;
}
V_132:
F_98 ( V_62 -> V_130 ) ;
}
static void F_101 ( struct V_135 * V_136 )
{
struct V_12 * V_13 = F_2 ( V_136 , struct V_12 ,
V_134 ) ;
struct V_8 * V_137 = & V_13 -> V_11 ;
struct V_127 * V_62 = V_13 -> V_128 ;
struct V_138 V_139 ;
struct V_40 * V_40 ;
struct V_140 V_141 ;
int V_19 ;
F_19 ( & V_139 ) ;
F_96 ( V_62 -> V_130 ) ;
for ( V_19 = V_49 ; V_19 <= V_50 ; V_19 ++ )
while ( ( V_40 = F_28 ( & V_137 -> V_42 [ V_19 ] , NULL ) ) )
F_21 ( & V_139 , V_40 ) ;
F_98 ( V_62 -> V_130 ) ;
if ( ! F_30 ( & V_139 ) ) {
F_102 ( & V_141 ) ;
while( ( V_40 = F_29 ( & V_139 ) ) )
F_103 ( V_40 ) ;
F_104 ( & V_141 ) ;
}
}
static T_3 F_105 ( struct V_142 * V_143 , struct V_2 * V_3 ,
int V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_3 V_145 = * ( T_3 * ) ( ( void * ) V_7 + V_144 ) ;
if ( V_145 == V_23 )
return 0 ;
return F_106 ( V_143 , V_3 , V_145 ) ;
}
static T_3 F_107 ( struct V_142 * V_143 , struct V_2 * V_3 ,
int V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_145 = * ( unsigned int * ) ( ( void * ) V_7 + V_144 ) ;
if ( V_145 == V_34 )
return 0 ;
return F_106 ( V_143 , V_3 , V_145 ) ;
}
static int F_108 ( struct V_142 * V_143 , void * V_145 )
{
F_109 ( V_143 , F_110 ( F_111 ( V_143 ) ) , F_105 ,
& V_6 , F_112 ( V_143 ) -> V_146 , false ) ;
return 0 ;
}
static int F_113 ( struct V_142 * V_143 , void * V_145 )
{
F_109 ( V_143 , F_110 ( F_111 ( V_143 ) ) , F_107 ,
& V_6 , F_112 ( V_143 ) -> V_146 , false ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_7 , bool V_147 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_66 * V_67 ;
struct V_4 * V_5 ;
F_69 ( & V_7 -> V_11 ,
L_8 ,
F_11 ( V_7 , V_49 ) , F_11 ( V_7 , V_50 ) ,
F_15 ( V_7 , V_49 ) , F_15 ( V_7 , V_50 ) ) ;
F_115 (blkg, pos_css,
global ? tg->td->queue->root_blkg : tg_to_blkg(tg)) {
struct V_1 * V_148 = F_3 ( V_5 ) ;
struct V_1 * V_63 ;
F_40 ( V_148 ) ;
if ( ! F_12 ( V_21 ) || ! V_5 -> V_22 ||
! V_5 -> V_22 -> V_22 )
continue;
V_63 = F_3 ( V_5 -> V_22 ) ;
V_148 -> V_59 = F_14 ( V_148 -> V_59 ,
V_63 -> V_59 ) ;
V_148 -> V_56 = F_86 ( V_148 -> V_56 ,
V_63 -> V_56 ) ;
}
F_72 ( V_7 , 0 ) ;
F_72 ( V_7 , 1 ) ;
if ( V_7 -> V_81 & V_82 ) {
F_91 ( V_7 ) ;
F_70 ( V_9 -> V_10 , true ) ;
}
}
static T_4 F_116 ( struct V_149 * V_150 ,
char * V_151 , T_5 V_152 , T_6 V_144 , bool V_153 )
{
struct V_27 * V_27 = F_110 ( F_117 ( V_150 ) ) ;
struct V_154 V_155 ;
struct V_1 * V_7 ;
int V_20 ;
T_3 V_145 ;
V_20 = F_118 ( V_27 , & V_6 , V_151 , & V_155 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_156 ;
if ( sscanf ( V_155 . V_157 , L_9 , & V_145 ) != 1 )
goto V_158;
if ( ! V_145 )
V_145 = V_23 ;
V_7 = F_3 ( V_155 . V_5 ) ;
if ( V_153 )
* ( T_3 * ) ( ( void * ) V_7 + F_119 ( V_150 ) -> V_146 ) = V_145 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + F_119 ( V_150 ) -> V_146 ) = V_145 ;
F_114 ( V_7 , false ) ;
V_20 = 0 ;
V_158:
F_120 ( & V_155 ) ;
return V_20 ? : V_152 ;
}
static T_4 F_121 ( struct V_149 * V_150 ,
char * V_151 , T_5 V_152 , T_6 V_144 )
{
return F_116 ( V_150 , V_151 , V_152 , V_144 , true ) ;
}
static T_4 F_122 ( struct V_149 * V_150 ,
char * V_151 , T_5 V_152 , T_6 V_144 )
{
return F_116 ( V_150 , V_151 , V_152 , V_144 , false ) ;
}
static T_3 F_123 ( struct V_142 * V_143 , struct V_2 * V_3 ,
int V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
const char * V_159 = F_124 ( V_3 -> V_5 ) ;
char V_160 [ 4 ] [ 21 ] = { L_10 , L_10 , L_10 , L_10 } ;
T_3 V_161 ;
unsigned int V_162 ;
char V_163 [ 26 ] = L_11 ;
char V_164 [ 26 ] = L_11 ;
if ( ! V_159 )
return 0 ;
if ( V_144 == V_26 ) {
V_161 = 0 ;
V_162 = 0 ;
} else {
V_161 = V_23 ;
V_162 = V_34 ;
}
if ( V_7 -> V_54 [ V_49 ] [ V_144 ] == V_161 &&
V_7 -> V_54 [ V_50 ] [ V_144 ] == V_161 &&
V_7 -> V_55 [ V_49 ] [ V_144 ] == V_162 &&
V_7 -> V_55 [ V_50 ] [ V_144 ] == V_162 &&
( V_144 != V_26 ||
( V_7 -> V_61 == V_60 &&
V_7 -> V_58 == V_57 ) ) )
return 0 ;
if ( V_7 -> V_54 [ V_49 ] [ V_144 ] != V_23 )
snprintf ( V_160 [ 0 ] , sizeof( V_160 [ 0 ] ) , L_9 ,
V_7 -> V_54 [ V_49 ] [ V_144 ] ) ;
if ( V_7 -> V_54 [ V_50 ] [ V_144 ] != V_23 )
snprintf ( V_160 [ 1 ] , sizeof( V_160 [ 1 ] ) , L_9 ,
V_7 -> V_54 [ V_50 ] [ V_144 ] ) ;
if ( V_7 -> V_55 [ V_49 ] [ V_144 ] != V_34 )
snprintf ( V_160 [ 2 ] , sizeof( V_160 [ 2 ] ) , L_12 ,
V_7 -> V_55 [ V_49 ] [ V_144 ] ) ;
if ( V_7 -> V_55 [ V_50 ] [ V_144 ] != V_34 )
snprintf ( V_160 [ 3 ] , sizeof( V_160 [ 3 ] ) , L_12 ,
V_7 -> V_55 [ V_50 ] [ V_144 ] ) ;
if ( V_144 == V_26 ) {
if ( V_7 -> V_61 == V_165 )
strcpy ( V_163 , L_13 ) ;
else
snprintf ( V_163 , sizeof( V_163 ) , L_14 ,
V_7 -> V_61 ) ;
if ( V_7 -> V_58 == V_165 )
strcpy ( V_164 , L_15 ) ;
else
snprintf ( V_164 , sizeof( V_164 ) ,
L_16 , V_7 -> V_58 ) ;
}
F_125 ( V_143 , L_17 ,
V_159 , V_160 [ 0 ] , V_160 [ 1 ] , V_160 [ 2 ] , V_160 [ 3 ] , V_163 ,
V_164 ) ;
return 0 ;
}
static int F_126 ( struct V_142 * V_143 , void * V_145 )
{
F_109 ( V_143 , F_110 ( F_111 ( V_143 ) ) , F_123 ,
& V_6 , F_112 ( V_143 ) -> V_146 , false ) ;
return 0 ;
}
static T_4 F_127 ( struct V_149 * V_150 ,
char * V_151 , T_5 V_152 , T_6 V_144 )
{
struct V_27 * V_27 = F_110 ( F_117 ( V_150 ) ) ;
struct V_154 V_155 ;
struct V_1 * V_7 ;
T_3 V_145 [ 4 ] ;
unsigned long V_163 ;
unsigned long V_164 ;
int V_20 ;
int V_166 = F_119 ( V_150 ) -> V_146 ;
V_20 = F_118 ( V_27 , & V_6 , V_151 , & V_155 ) ;
if ( V_20 )
return V_20 ;
V_7 = F_3 ( V_155 . V_5 ) ;
V_145 [ 0 ] = V_7 -> V_54 [ V_49 ] [ V_166 ] ;
V_145 [ 1 ] = V_7 -> V_54 [ V_50 ] [ V_166 ] ;
V_145 [ 2 ] = V_7 -> V_55 [ V_49 ] [ V_166 ] ;
V_145 [ 3 ] = V_7 -> V_55 [ V_50 ] [ V_166 ] ;
V_163 = V_7 -> V_61 ;
V_164 = V_7 -> V_58 ;
while ( true ) {
char V_167 [ 27 ] ;
char * V_168 ;
T_3 V_169 = V_23 ;
int V_170 ;
if ( sscanf ( V_155 . V_157 , L_18 , V_167 , & V_170 ) != 1 )
break;
if ( V_167 [ 0 ] == '\0' )
break;
V_155 . V_157 += V_170 ;
V_20 = - V_156 ;
V_168 = V_167 ;
F_128 ( & V_168 , L_19 ) ;
if ( ! V_168 || ( sscanf ( V_168 , L_9 , & V_169 ) != 1 && strcmp ( V_168 , L_10 ) ) )
goto V_158;
V_20 = - V_171 ;
if ( ! V_169 )
goto V_158;
V_20 = - V_156 ;
if ( ! strcmp ( V_167 , L_20 ) )
V_145 [ 0 ] = V_169 ;
else if ( ! strcmp ( V_167 , L_21 ) )
V_145 [ 1 ] = V_169 ;
else if ( ! strcmp ( V_167 , L_22 ) )
V_145 [ 2 ] = F_16 ( T_3 , V_169 , V_34 ) ;
else if ( ! strcmp ( V_167 , L_23 ) )
V_145 [ 3 ] = F_16 ( T_3 , V_169 , V_34 ) ;
else if ( V_144 == V_26 && ! strcmp ( V_167 , L_24 ) )
V_163 = V_169 ;
else if ( V_144 == V_26 && ! strcmp ( V_167 , L_25 ) )
V_164 = V_169 ;
else
goto V_158;
}
V_7 -> V_54 [ V_49 ] [ V_166 ] = V_145 [ 0 ] ;
V_7 -> V_54 [ V_50 ] [ V_166 ] = V_145 [ 1 ] ;
V_7 -> V_55 [ V_49 ] [ V_166 ] = V_145 [ 2 ] ;
V_7 -> V_55 [ V_50 ] [ V_166 ] = V_145 [ 3 ] ;
if ( V_166 == V_32 ) {
V_7 -> V_24 [ V_49 ] [ V_166 ] = V_145 [ 0 ] ;
V_7 -> V_24 [ V_50 ] [ V_166 ] = V_145 [ 1 ] ;
V_7 -> V_30 [ V_49 ] [ V_166 ] = V_145 [ 2 ] ;
V_7 -> V_30 [ V_50 ] [ V_166 ] = V_145 [ 3 ] ;
}
V_7 -> V_24 [ V_49 ] [ V_26 ] = F_14 ( V_7 -> V_54 [ V_49 ] [ V_26 ] ,
V_7 -> V_54 [ V_49 ] [ V_32 ] ) ;
V_7 -> V_24 [ V_50 ] [ V_26 ] = F_14 ( V_7 -> V_54 [ V_50 ] [ V_26 ] ,
V_7 -> V_54 [ V_50 ] [ V_32 ] ) ;
V_7 -> V_30 [ V_49 ] [ V_26 ] = F_14 ( V_7 -> V_55 [ V_49 ] [ V_26 ] ,
V_7 -> V_55 [ V_49 ] [ V_32 ] ) ;
V_7 -> V_30 [ V_50 ] [ V_26 ] = F_14 ( V_7 -> V_55 [ V_50 ] [ V_26 ] ,
V_7 -> V_55 [ V_50 ] [ V_32 ] ) ;
V_7 -> V_61 = V_163 ;
V_7 -> V_58 = V_164 ;
if ( ! ( V_7 -> V_24 [ V_49 ] [ V_26 ] || V_7 -> V_30 [ V_49 ] [ V_26 ] ||
V_7 -> V_24 [ V_50 ] [ V_26 ] || V_7 -> V_30 [ V_50 ] [ V_26 ] ) ||
V_7 -> V_61 == V_60 ||
V_7 -> V_58 == V_57 ) {
V_7 -> V_24 [ V_49 ] [ V_26 ] = 0 ;
V_7 -> V_24 [ V_50 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_49 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_50 ] [ V_26 ] = 0 ;
V_7 -> V_59 = V_60 ;
V_7 -> V_56 = V_57 ;
} else if ( V_166 == V_26 ) {
V_7 -> V_59 = V_7 -> V_61 ;
V_7 -> V_56 = V_7 -> V_58 ;
}
F_42 ( V_7 -> V_13 ) ;
if ( V_7 -> V_13 -> V_65 [ V_26 ] ) {
if ( V_166 == V_26 )
V_7 -> V_13 -> V_25 = V_26 ;
} else
V_7 -> V_13 -> V_25 = V_32 ;
F_114 ( V_7 , V_166 == V_26 &&
V_7 -> V_13 -> V_65 [ V_26 ] ) ;
V_20 = 0 ;
V_158:
F_120 ( & V_155 ) ;
return V_20 ? : V_152 ;
}
static void F_129 ( struct V_127 * V_62 )
{
struct V_12 * V_13 = V_62 -> V_13 ;
F_130 ( & V_13 -> V_134 ) ;
}
static unsigned long F_131 ( struct V_1 * V_7 )
{
unsigned long V_172 = V_16 , V_173 = V_16 ;
if ( V_7 -> V_24 [ V_49 ] [ V_26 ] || V_7 -> V_30 [ V_49 ] [ V_26 ] )
V_172 = V_7 -> V_174 [ V_49 ] ;
if ( V_7 -> V_24 [ V_50 ] [ V_26 ] || V_7 -> V_30 [ V_50 ] [ V_26 ] )
V_173 = V_7 -> V_174 [ V_50 ] ;
return F_14 ( V_172 , V_173 ) ;
}
static unsigned long F_132 ( struct V_1 * V_7 )
{
struct V_8 * V_10 ;
struct V_1 * V_22 = V_7 ;
unsigned long V_20 = F_131 ( V_7 ) ;
while ( true ) {
V_10 = V_22 -> V_11 . V_10 ;
V_22 = F_7 ( V_10 ) ;
if ( ! V_22 )
break;
if ( ! V_22 -> V_24 [ V_49 ] [ V_26 ] &&
! V_22 -> V_30 [ V_49 ] [ V_26 ] &&
! V_22 -> V_24 [ V_50 ] [ V_26 ] &&
! V_22 -> V_30 [ V_50 ] [ V_26 ] )
continue;
if ( F_67 ( F_131 ( V_22 ) , V_20 ) )
V_20 = F_131 ( V_22 ) ;
}
return V_20 ;
}
static bool F_133 ( struct V_1 * V_7 )
{
unsigned long time ;
bool V_20 ;
time = F_16 (unsigned long, MAX_IDLE_TIME, 4 * tg->idletime_threshold) ;
V_20 = V_7 -> V_56 == V_57 ||
V_7 -> V_59 == V_60 ||
( F_134 () >> 10 ) - V_7 -> V_175 > time ||
V_7 -> V_176 > V_7 -> V_59 ||
( V_7 -> V_56 && V_7 -> V_177 &&
V_7 -> V_178 * 5 < V_7 -> V_177 ) ;
F_69 ( & V_7 -> V_11 ,
L_26 ,
V_7 -> V_176 , V_7 -> V_59 , V_7 -> V_178 ,
V_7 -> V_177 , V_20 , V_7 -> V_13 -> V_15 ) ;
return V_20 ;
}
static bool F_135 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_179 , V_180 ;
V_179 = V_7 -> V_24 [ V_49 ] [ V_26 ] || V_7 -> V_30 [ V_49 ] [ V_26 ] ;
V_180 = V_7 -> V_24 [ V_50 ] [ V_26 ] || V_7 -> V_30 [ V_50 ] [ V_26 ] ;
if ( ! V_179 && ! V_180 )
return true ;
if ( V_179 && V_9 -> V_110 [ V_49 ] &&
( ! V_180 || V_9 -> V_110 [ V_50 ] ) )
return true ;
if ( V_180 && V_9 -> V_110 [ V_50 ] &&
( ! V_179 || V_9 -> V_110 [ V_49 ] ) )
return true ;
if ( F_10 ( V_16 ,
F_132 ( V_7 ) + V_7 -> V_13 -> V_18 ) &&
F_133 ( V_7 ) )
return true ;
return false ;
}
static bool F_136 ( struct V_1 * V_7 )
{
while ( true ) {
if ( F_135 ( V_7 ) )
return true ;
V_7 = F_7 ( V_7 -> V_11 . V_10 ) ;
if ( ! V_7 || ! F_5 ( V_7 ) -> V_22 )
return false ;
}
return false ;
}
static bool F_97 ( struct V_12 * V_13 ,
struct V_1 * V_148 )
{
struct V_66 * V_67 ;
struct V_4 * V_5 ;
if ( V_13 -> V_25 != V_26 )
return false ;
if ( F_59 ( V_16 , V_13 -> V_181 + V_13 -> V_18 ) )
return false ;
F_43 () ;
F_44 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( V_7 == V_148 )
continue;
if ( ! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) )
continue;
if ( ! F_136 ( V_7 ) ) {
F_45 () ;
return false ;
}
}
F_45 () ;
return true ;
}
static void F_137 ( struct V_1 * V_7 )
{
unsigned long V_182 = V_16 ;
if ( V_7 -> V_13 -> V_25 != V_26 )
return;
if ( F_67 ( V_7 -> V_183 + V_7 -> V_13 -> V_18 , V_182 ) )
return;
V_7 -> V_183 = V_182 ;
if ( ! F_10 ( V_182 ,
F_131 ( V_7 ) + V_7 -> V_13 -> V_18 ) )
return;
if ( F_97 ( V_7 -> V_13 , NULL ) )
F_47 ( V_7 -> V_13 ) ;
}
static void F_47 ( struct V_12 * V_13 )
{
struct V_66 * V_67 ;
struct V_4 * V_5 ;
F_69 ( & V_13 -> V_11 , L_27 ) ;
V_13 -> V_25 = V_32 ;
V_13 -> V_17 = V_16 ;
V_13 -> V_15 = 0 ;
F_43 () ;
F_44 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
V_7 -> V_75 = V_16 - 1 ;
F_95 ( V_9 ) ;
F_70 ( V_9 , false ) ;
}
F_45 () ;
F_95 ( & V_13 -> V_11 ) ;
F_70 ( & V_13 -> V_11 , false ) ;
F_100 ( V_133 , & V_13 -> V_134 ) ;
}
static void F_138 ( struct V_12 * V_13 , int V_184 )
{
V_13 -> V_15 /= 2 ;
F_69 ( & V_13 -> V_11 , L_28 , V_13 -> V_15 ) ;
if ( V_13 -> V_15 ) {
V_13 -> V_17 = V_16 - V_13 -> V_15 * V_13 -> V_18 ;
return;
}
V_13 -> V_25 = V_184 ;
V_13 -> V_181 = V_16 ;
}
static bool F_139 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
unsigned long V_182 = V_16 ;
if ( F_10 ( V_182 , V_13 -> V_17 + V_13 -> V_18 ) &&
F_10 ( V_182 , F_132 ( V_7 ) +
V_13 -> V_18 ) &&
( ! F_133 ( V_7 ) ||
! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) ) )
return true ;
return false ;
}
static bool F_140 ( struct V_1 * V_7 )
{
while ( true ) {
if ( ! F_139 ( V_7 ) )
return false ;
V_7 = F_7 ( V_7 -> V_11 . V_10 ) ;
if ( ! V_7 || ! F_5 ( V_7 ) -> V_22 )
break;
}
return true ;
}
static void F_141 ( struct V_1 * V_7 )
{
T_1 V_24 ;
unsigned int V_30 ;
unsigned long V_185 ;
unsigned long V_182 = V_16 ;
if ( V_7 -> V_13 -> V_25 != V_32 ||
! V_7 -> V_13 -> V_65 [ V_26 ] )
return;
if ( ! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) )
return;
if ( F_67 ( V_7 -> V_183 + V_7 -> V_13 -> V_18 , V_182 ) )
return;
V_185 = V_182 - V_7 -> V_183 ;
V_7 -> V_183 = V_182 ;
if ( F_59 ( V_182 , F_132 ( V_7 ) +
V_7 -> V_13 -> V_18 ) )
return;
if ( V_7 -> V_24 [ V_49 ] [ V_26 ] ) {
V_24 = V_7 -> V_111 [ V_49 ] * V_97 ;
F_80 ( V_24 , V_185 ) ;
if ( V_24 >= V_7 -> V_24 [ V_49 ] [ V_26 ] )
V_7 -> V_174 [ V_49 ] = V_182 ;
}
if ( V_7 -> V_24 [ V_50 ] [ V_26 ] ) {
V_24 = V_7 -> V_111 [ V_50 ] * V_97 ;
F_80 ( V_24 , V_185 ) ;
if ( V_24 >= V_7 -> V_24 [ V_50 ] [ V_26 ] )
V_7 -> V_174 [ V_50 ] = V_182 ;
}
if ( V_7 -> V_30 [ V_49 ] [ V_26 ] ) {
V_30 = V_7 -> V_112 [ V_49 ] * V_97 / V_185 ;
if ( V_30 >= V_7 -> V_30 [ V_49 ] [ V_26 ] )
V_7 -> V_174 [ V_49 ] = V_182 ;
}
if ( V_7 -> V_30 [ V_50 ] [ V_26 ] ) {
V_30 = V_7 -> V_112 [ V_50 ] * V_97 / V_185 ;
if ( V_30 >= V_7 -> V_30 [ V_50 ] [ V_26 ] )
V_7 -> V_174 [ V_50 ] = V_182 ;
}
if ( F_140 ( V_7 ) )
F_138 ( V_7 -> V_13 , V_26 ) ;
V_7 -> V_111 [ V_49 ] = 0 ;
V_7 -> V_111 [ V_50 ] = 0 ;
V_7 -> V_112 [ V_49 ] = 0 ;
V_7 -> V_112 [ V_50 ] = 0 ;
}
static void F_142 ( struct V_1 * V_7 )
{
unsigned long V_182 = F_134 () >> 10 ;
unsigned long V_175 = V_7 -> V_175 ;
if ( V_182 <= V_175 || V_175 == 0 ||
V_175 == V_7 -> V_186 )
return;
V_7 -> V_176 = ( V_7 -> V_176 * 7 + V_182 - V_175 ) >> 3 ;
V_7 -> V_186 = V_175 ;
}
static void F_143 ( struct V_12 * V_13 )
{
struct V_187 V_188 [ V_189 ] ;
int V_190 , V_191 ;
unsigned long V_192 = 0 ;
unsigned long V_193 ;
if ( ! F_144 ( V_13 -> V_128 ) )
return;
if ( F_59 ( V_16 , V_13 -> V_194 + V_97 ) )
return;
V_13 -> V_194 = V_16 ;
memset ( V_188 , 0 , sizeof( V_188 ) ) ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
struct V_195 * V_96 = & V_13 -> V_196 [ V_190 ] ;
F_145 (cpu) {
struct V_195 * V_197 ;
V_197 = F_146 ( V_13 -> V_198 , V_191 ) ;
V_96 -> V_199 += V_197 [ V_190 ] . V_199 ;
V_96 -> V_200 += V_197 [ V_190 ] . V_200 ;
V_197 [ V_190 ] . V_199 = 0 ;
V_197 [ V_190 ] . V_200 = 0 ;
}
if ( V_96 -> V_200 >= 32 ) {
int V_200 = V_96 -> V_200 ;
V_193 = V_96 -> V_199 ;
V_96 -> V_199 = 0 ;
V_96 -> V_200 = 0 ;
V_193 /= V_200 ;
if ( V_193 == 0 )
continue;
V_188 [ V_190 ] . V_193 = V_193 ;
}
}
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
if ( ! V_188 [ V_190 ] . V_193 ) {
if ( V_13 -> V_201 [ V_190 ] . V_193 < V_192 )
V_13 -> V_201 [ V_190 ] . V_193 = V_192 ;
continue;
}
if ( ! V_13 -> V_201 [ V_190 ] . V_202 )
V_193 = V_188 [ V_190 ] . V_193 ;
else
V_193 = ( V_13 -> V_201 [ V_190 ] . V_193 * 7 +
V_188 [ V_190 ] . V_193 ) >> 3 ;
V_13 -> V_201 [ V_190 ] . V_193 = F_86 ( V_193 , V_192 ) ;
V_13 -> V_201 [ V_190 ] . V_202 = true ;
V_192 = V_13 -> V_201 [ V_190 ] . V_193 ;
}
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ )
F_69 ( & V_13 -> V_11 ,
L_29 , V_190 ,
V_13 -> V_201 [ V_190 ] . V_193 , V_13 -> V_201 [ V_190 ] . V_202 ) ;
}
static inline void F_143 ( struct V_12 * V_13 )
{
}
static void F_147 ( struct V_1 * V_7 , struct V_40 * V_40 )
{
#ifdef F_148
int V_20 ;
V_20 = F_149 ( V_40 ) ;
if ( V_20 == 0 || V_20 == - V_203 )
V_40 -> V_204 = V_7 ;
F_150 ( & V_40 -> V_205 , F_151 ( V_40 ) ) ;
#else
F_149 ( V_40 ) ;
#endif
}
bool F_152 ( struct V_127 * V_62 , struct V_4 * V_5 ,
struct V_40 * V_40 )
{
struct V_36 * V_37 = NULL ;
struct V_1 * V_7 = F_3 ( V_5 ? : V_62 -> V_206 ) ;
struct V_8 * V_9 ;
bool V_19 = F_82 ( V_40 ) ;
bool V_207 = false ;
struct V_12 * V_13 = V_7 -> V_13 ;
F_27 ( ! F_153 () ) ;
if ( F_88 ( V_40 , V_113 ) || ! V_7 -> V_64 [ V_19 ] )
goto V_208;
F_96 ( V_62 -> V_130 ) ;
F_143 ( V_13 ) ;
if ( F_154 ( F_155 ( V_62 ) ) )
goto V_132;
F_147 ( V_7 , V_40 ) ;
F_142 ( V_7 ) ;
V_9 = & V_7 -> V_11 ;
V_131:
while ( true ) {
if ( V_7 -> V_174 [ V_19 ] == 0 )
V_7 -> V_174 [ V_19 ] = V_16 ;
F_141 ( V_7 ) ;
F_137 ( V_7 ) ;
if ( V_9 -> V_110 [ V_19 ] )
break;
if ( ! F_85 ( V_7 , V_40 , NULL ) ) {
V_7 -> V_174 [ V_19 ] = V_16 ;
if ( F_97 ( V_13 , V_7 ) ) {
F_47 ( V_13 ) ;
goto V_131;
}
break;
}
F_87 ( V_7 , V_40 ) ;
F_78 ( V_7 , V_19 ) ;
V_37 = & V_7 -> V_52 [ V_19 ] ;
V_9 = V_9 -> V_10 ;
V_7 = F_7 ( V_9 ) ;
if ( ! V_7 )
goto V_132;
}
F_69 ( V_9 , L_30 ,
V_19 == V_49 ? 'R' : 'W' ,
V_7 -> V_87 [ V_19 ] , V_40 -> V_105 . V_106 ,
F_11 ( V_7 , V_19 ) ,
V_7 -> V_88 [ V_19 ] , F_15 ( V_7 , V_19 ) ,
V_9 -> V_110 [ V_49 ] , V_9 -> V_110 [ V_50 ] ) ;
V_7 -> V_174 [ V_19 ] = V_16 ;
V_13 -> V_110 [ V_19 ] ++ ;
F_90 ( V_40 , V_37 , V_7 ) ;
V_207 = true ;
if ( V_7 -> V_81 & V_114 ) {
F_91 ( V_7 ) ;
F_70 ( V_7 -> V_11 . V_10 , true ) ;
}
V_132:
F_98 ( V_62 -> V_130 ) ;
V_208:
if ( ! V_207 )
F_156 ( V_40 , V_113 ) ;
#ifdef F_148
if ( V_207 || ! V_13 -> V_209 )
V_40 -> V_205 . V_210 |= V_211 ;
#endif
return V_207 ;
}
static void F_157 ( struct V_12 * V_13 , T_7 V_212 ,
int V_213 , unsigned long time )
{
struct V_195 * V_193 ;
int V_166 ;
if ( ! V_13 || V_13 -> V_25 != V_26 || V_213 != V_214 ||
! F_144 ( V_13 -> V_128 ) )
return;
V_166 = F_158 ( V_212 ) ;
V_193 = F_159 ( V_13 -> V_198 ) ;
V_193 [ V_166 ] . V_199 += time ;
V_193 [ V_166 ] . V_200 ++ ;
F_160 ( V_13 -> V_198 ) ;
}
void F_161 ( struct V_215 * V_216 , T_3 V_217 )
{
struct V_127 * V_62 = V_216 -> V_62 ;
struct V_12 * V_13 = V_62 -> V_13 ;
F_157 ( V_13 , F_162 ( & V_216 -> V_218 ) ,
F_163 ( V_216 ) , V_217 >> 10 ) ;
}
void F_164 ( struct V_40 * V_40 )
{
struct V_1 * V_7 ;
T_3 V_219 ;
unsigned long V_220 ;
unsigned long V_221 ;
unsigned long V_222 ;
V_7 = V_40 -> V_204 ;
if ( ! V_7 )
return;
V_40 -> V_204 = NULL ;
V_219 = F_134 () ;
V_7 -> V_175 = V_219 >> 10 ;
V_221 = F_165 ( & V_40 -> V_205 ) >> 10 ;
V_220 = F_166 ( V_219 ) >> 10 ;
if ( ! V_221 || V_220 <= V_221 )
return;
V_222 = V_220 - V_221 ;
if ( ! ( V_40 -> V_205 . V_210 & V_211 ) )
F_157 ( V_7 -> V_13 , F_162 ( & V_40 -> V_205 ) ,
F_167 ( V_40 ) , V_222 ) ;
if ( V_7 -> V_56 && V_222 >= V_7 -> V_13 -> V_223 ) {
int V_197 ;
unsigned int V_224 ;
V_197 = F_158 (
F_162 ( & V_40 -> V_205 ) ) ;
V_224 = V_7 -> V_13 -> V_201 [ V_197 ] . V_193 +
V_7 -> V_56 ;
if ( V_222 > V_224 )
V_7 -> V_178 ++ ;
V_7 -> V_177 ++ ;
}
if ( F_67 ( V_16 , V_7 -> V_225 ) || V_7 -> V_177 > 1024 ) {
V_7 -> V_225 = V_7 -> V_13 -> V_18 + V_16 ;
V_7 -> V_177 /= 2 ;
V_7 -> V_178 /= 2 ;
}
}
static void F_168 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_51 ( V_10 ) ) ) {
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_40 * V_40 ;
F_65 ( V_7 ) ;
while ( ( V_40 = F_24 ( & V_9 -> V_42 [ V_49 ] ) ) )
F_93 ( V_7 , F_82 ( V_40 ) ) ;
while ( ( V_40 = F_24 ( & V_9 -> V_42 [ V_50 ] ) ) )
F_93 ( V_7 , F_82 ( V_40 ) ) ;
}
}
void F_169 ( struct V_127 * V_62 )
__releases( V_62 -> V_130 ) __acquires( V_62 -> V_130 )
{
struct V_12 * V_13 = V_62 -> V_13 ;
struct V_4 * V_5 ;
struct V_66 * V_67 ;
struct V_40 * V_40 ;
int V_19 ;
F_170 ( V_62 ) ;
F_43 () ;
F_44 (blkg, pos_css, td->queue->root_blkg)
F_168 ( & F_3 ( V_5 ) -> V_11 ) ;
F_168 ( & V_13 -> V_11 ) ;
F_45 () ;
F_98 ( V_62 -> V_130 ) ;
for ( V_19 = V_49 ; V_19 <= V_50 ; V_19 ++ )
while ( ( V_40 = F_28 ( & V_13 -> V_11 . V_42 [ V_19 ] ,
NULL ) ) )
F_103 ( V_40 ) ;
F_96 ( V_62 -> V_130 ) ;
}
int F_171 ( struct V_127 * V_62 )
{
struct V_12 * V_13 ;
int V_20 ;
V_13 = F_37 ( sizeof( * V_13 ) , V_226 , V_62 -> V_38 ) ;
if ( ! V_13 )
return - V_227 ;
V_13 -> V_198 = F_172 ( sizeof( struct V_195 ) *
V_189 , F_173 ( T_3 ) ) ;
if ( ! V_13 -> V_198 ) {
F_50 ( V_13 ) ;
return - V_227 ;
}
F_174 ( & V_13 -> V_134 , F_101 ) ;
F_34 ( & V_13 -> V_11 ) ;
V_62 -> V_13 = V_13 ;
V_13 -> V_128 = V_62 ;
V_13 -> V_65 [ V_32 ] = true ;
V_13 -> V_25 = V_32 ;
V_13 -> V_17 = V_16 ;
V_13 -> V_181 = V_16 ;
V_20 = F_175 ( V_62 , & V_6 ) ;
if ( V_20 ) {
F_176 ( V_13 -> V_198 ) ;
F_50 ( V_13 ) ;
}
return V_20 ;
}
void F_177 ( struct V_127 * V_62 )
{
F_79 ( ! V_62 -> V_13 ) ;
F_129 ( V_62 ) ;
F_178 ( V_62 , & V_6 ) ;
F_176 ( V_62 -> V_13 -> V_198 ) ;
F_50 ( V_62 -> V_13 ) ;
}
void F_179 ( struct V_127 * V_62 )
{
struct V_12 * V_13 ;
int V_190 ;
V_13 = V_62 -> V_13 ;
F_79 ( ! V_13 ) ;
if ( F_144 ( V_62 ) ) {
V_13 -> V_18 = V_228 ;
V_13 -> V_223 = V_229 ;
} else {
V_13 -> V_18 = V_230 ;
V_13 -> V_223 = V_231 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ )
V_13 -> V_201 [ V_190 ] . V_193 = V_232 ;
}
#ifndef F_148
V_13 -> V_18 = V_230 ;
#endif
V_13 -> V_209 = ! V_62 -> V_233 && ! V_62 -> V_234 ;
if ( ! V_13 -> V_209 )
F_180 ( V_62 ) ;
}
T_4 F_181 ( struct V_127 * V_62 , char * V_235 )
{
if ( ! V_62 -> V_13 )
return - V_156 ;
return sprintf ( V_235 , L_31 , F_182 ( V_62 -> V_13 -> V_18 ) ) ;
}
T_4 F_183 ( struct V_127 * V_62 ,
const char * V_235 , T_5 V_236 )
{
unsigned long V_145 ;
unsigned long V_237 ;
if ( ! V_62 -> V_13 )
return - V_156 ;
if ( F_184 ( V_235 , 10 , & V_145 ) )
return - V_156 ;
V_237 = F_185 ( V_145 ) ;
if ( V_237 == 0 || V_237 > V_238 )
return - V_156 ;
V_62 -> V_13 -> V_18 = V_237 ;
return V_236 ;
}
static int T_8 F_186 ( void )
{
V_133 = F_187 ( L_32 , V_239 , 0 ) ;
if ( ! V_133 )
F_188 ( L_33 ) ;
return F_189 ( & V_6 ) ;
}
