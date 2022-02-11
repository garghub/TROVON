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
static inline unsigned int F_17 ( struct V_36 * V_36 )
{
if ( F_18 ( F_19 ( V_36 ) == V_37 ) )
return 512 ;
return V_36 -> V_38 . V_39 ;
}
static void F_20 ( struct V_40 * V_41 , struct V_1 * V_7 )
{
F_21 ( & V_41 -> V_42 ) ;
F_22 ( & V_41 -> V_43 ) ;
V_41 -> V_7 = V_7 ;
}
static void F_23 ( struct V_36 * V_36 , struct V_40 * V_41 ,
struct V_44 * V_45 )
{
F_24 ( & V_41 -> V_43 , V_36 ) ;
if ( F_13 ( & V_41 -> V_42 ) ) {
F_25 ( & V_41 -> V_42 , V_45 ) ;
F_26 ( F_5 ( V_41 -> V_7 ) ) ;
}
}
static struct V_36 * F_27 ( struct V_44 * V_45 )
{
struct V_40 * V_41 = F_28 ( V_45 , struct V_40 , V_42 ) ;
struct V_36 * V_36 ;
if ( F_13 ( V_45 ) )
return NULL ;
V_36 = F_29 ( & V_41 -> V_43 ) ;
F_30 ( ! V_36 ) ;
return V_36 ;
}
static struct V_36 * F_31 ( struct V_44 * V_45 ,
struct V_1 * * V_46 )
{
struct V_40 * V_41 = F_28 ( V_45 , struct V_40 , V_42 ) ;
struct V_36 * V_36 ;
if ( F_13 ( V_45 ) )
return NULL ;
V_36 = F_32 ( & V_41 -> V_43 ) ;
F_30 ( ! V_36 ) ;
if ( F_33 ( & V_41 -> V_43 ) ) {
F_34 ( & V_41 -> V_42 ) ;
if ( V_46 )
* V_46 = V_41 -> V_7 ;
else
F_35 ( F_5 ( V_41 -> V_7 ) ) ;
} else {
F_36 ( & V_41 -> V_42 , V_45 ) ;
}
return V_36 ;
}
static void F_37 ( struct V_8 * V_9 )
{
F_21 ( & V_9 -> V_45 [ 0 ] ) ;
F_21 ( & V_9 -> V_45 [ 1 ] ) ;
V_9 -> V_47 = V_48 ;
F_38 ( & V_9 -> V_49 , V_50 ,
( unsigned long ) V_9 ) ;
}
static struct V_2 * F_39 ( T_2 V_51 , int V_42 )
{
struct V_1 * V_7 ;
int V_19 ;
V_7 = F_40 ( sizeof( * V_7 ) , V_51 , V_42 ) ;
if ( ! V_7 )
return NULL ;
F_37 ( & V_7 -> V_11 ) ;
for ( V_19 = V_52 ; V_19 <= V_53 ; V_19 ++ ) {
F_20 ( & V_7 -> V_54 [ V_19 ] , V_7 ) ;
F_20 ( & V_7 -> V_55 [ V_19 ] , V_7 ) ;
}
F_41 ( & V_7 -> V_56 ) ;
V_7 -> V_24 [ V_52 ] [ V_32 ] = V_23 ;
V_7 -> V_24 [ V_53 ] [ V_32 ] = V_23 ;
V_7 -> V_30 [ V_52 ] [ V_32 ] = V_34 ;
V_7 -> V_30 [ V_53 ] [ V_32 ] = V_34 ;
V_7 -> V_57 [ V_52 ] [ V_32 ] = V_23 ;
V_7 -> V_57 [ V_53 ] [ V_32 ] = V_23 ;
V_7 -> V_58 [ V_52 ] [ V_32 ] = V_34 ;
V_7 -> V_58 [ V_53 ] [ V_32 ] = V_34 ;
V_7 -> V_59 = V_60 ;
V_7 -> V_61 = V_60 ;
V_7 -> V_62 = V_63 ;
V_7 -> V_64 = V_63 ;
return & V_7 -> V_3 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_5 ( V_7 ) ;
struct V_12 * V_13 = V_5 -> V_65 -> V_13 ;
struct V_8 * V_9 = & V_7 -> V_11 ;
V_9 -> V_10 = & V_13 -> V_11 ;
if ( F_12 ( V_21 ) && V_5 -> V_22 )
V_9 -> V_10 = & F_3 ( V_5 -> V_22 ) -> V_11 ;
V_7 -> V_13 = V_13 ;
}
static void F_43 ( struct V_1 * V_7 )
{
struct V_1 * V_66 = F_7 ( V_7 -> V_11 . V_10 ) ;
struct V_12 * V_13 = V_7 -> V_13 ;
int V_19 ;
for ( V_19 = V_52 ; V_19 <= V_53 ; V_19 ++ )
V_7 -> V_67 [ V_19 ] = ( V_66 && V_66 -> V_67 [ V_19 ] ) ||
( V_13 -> V_68 [ V_13 -> V_25 ] &&
( F_11 ( V_7 , V_19 ) != V_23 ||
F_15 ( V_7 , V_19 ) != V_34 ) ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_43 ( V_7 ) ;
}
static void F_45 ( struct V_12 * V_13 )
{
struct V_69 * V_70 ;
struct V_4 * V_5 ;
bool V_71 = false ;
F_46 () ;
F_47 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( V_7 -> V_24 [ V_52 ] [ V_26 ] || V_7 -> V_24 [ V_53 ] [ V_26 ] ||
V_7 -> V_30 [ V_52 ] [ V_26 ] || V_7 -> V_30 [ V_53 ] [ V_26 ] )
V_71 = true ;
}
F_48 () ;
V_13 -> V_68 [ V_26 ] = V_71 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_24 [ V_52 ] [ V_26 ] = 0 ;
V_7 -> V_24 [ V_53 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_52 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_53 ] [ V_26 ] = 0 ;
F_45 ( V_7 -> V_13 ) ;
if ( ! V_7 -> V_13 -> V_68 [ V_7 -> V_13 -> V_25 ] )
F_50 ( V_7 -> V_13 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_52 ( & V_7 -> V_11 . V_49 ) ;
F_53 ( V_7 ) ;
}
static struct V_1 *
F_54 ( struct V_8 * V_10 )
{
if ( ! V_10 -> V_72 )
return NULL ;
if ( ! V_10 -> V_73 )
V_10 -> V_73 = F_55 ( & V_10 -> V_47 ) ;
if ( V_10 -> V_73 )
return F_56 ( V_10 -> V_73 ) ;
return NULL ;
}
static void F_57 ( struct V_56 * V_74 , struct V_75 * V_76 )
{
F_58 ( V_74 , V_76 ) ;
F_41 ( V_74 ) ;
}
static void F_59 ( struct V_56 * V_74 ,
struct V_8 * V_10 )
{
if ( V_10 -> V_73 == V_74 )
V_10 -> V_73 = NULL ;
F_57 ( V_74 , & V_10 -> V_47 ) ;
-- V_10 -> V_72 ;
}
static void F_60 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
V_7 = F_54 ( V_10 ) ;
if ( ! V_7 )
return;
V_10 -> V_77 = V_7 -> V_78 ;
}
static void F_61 ( struct V_1 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_11 . V_10 ;
struct V_56 * * V_42 = & V_10 -> V_47 . V_56 ;
struct V_56 * V_22 = NULL ;
struct V_1 * V_79 ;
unsigned long V_80 = V_7 -> V_78 ;
int V_81 = 1 ;
while ( * V_42 != NULL ) {
V_22 = * V_42 ;
V_79 = F_56 ( V_22 ) ;
if ( F_62 ( V_80 , V_79 -> V_78 ) )
V_42 = & V_22 -> V_82 ;
else {
V_42 = & V_22 -> V_83 ;
V_81 = 0 ;
}
}
if ( V_81 )
V_10 -> V_73 = & V_7 -> V_56 ;
F_63 ( & V_7 -> V_56 , V_22 , V_42 ) ;
F_64 ( & V_7 -> V_56 , & V_10 -> V_47 ) ;
}
static void F_65 ( struct V_1 * V_7 )
{
F_61 ( V_7 ) ;
V_7 -> V_84 |= V_85 ;
V_7 -> V_11 . V_10 -> V_72 ++ ;
}
static void F_66 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_84 & V_85 ) )
F_65 ( V_7 ) ;
}
static void F_67 ( struct V_1 * V_7 )
{
F_59 ( & V_7 -> V_56 , V_7 -> V_11 . V_10 ) ;
V_7 -> V_84 &= ~ V_85 ;
}
static void F_68 ( struct V_1 * V_7 )
{
if ( V_7 -> V_84 & V_85 )
F_67 ( V_7 ) ;
}
static void F_69 ( struct V_8 * V_9 ,
unsigned long V_86 )
{
unsigned long V_87 = V_16 + 8 * F_8 ( V_9 ) -> V_18 ;
if ( F_70 ( V_86 , V_87 ) )
V_86 = V_87 ;
F_71 ( & V_9 -> V_49 , V_86 ) ;
F_72 ( V_9 , L_1 ,
V_86 - V_16 , V_16 ) ;
}
static bool F_73 ( struct V_8 * V_9 ,
bool V_88 )
{
if ( ! V_9 -> V_72 )
return true ;
F_60 ( V_9 ) ;
if ( V_88 || F_70 ( V_9 -> V_77 , V_16 ) ) {
F_69 ( V_9 , V_9 -> V_77 ) ;
return true ;
}
return false ;
}
static inline void F_74 ( struct V_1 * V_7 ,
bool V_19 , unsigned long V_89 )
{
V_7 -> V_90 [ V_19 ] = 0 ;
V_7 -> V_91 [ V_19 ] = 0 ;
if ( F_10 ( V_89 , V_7 -> V_92 [ V_19 ] ) )
V_7 -> V_92 [ V_19 ] = V_89 ;
V_7 -> V_93 [ V_19 ] = V_16 + V_7 -> V_13 -> V_18 ;
F_72 ( & V_7 -> V_11 ,
L_2 ,
V_19 == V_52 ? 'R' : 'W' , V_7 -> V_92 [ V_19 ] ,
V_7 -> V_93 [ V_19 ] , V_16 ) ;
}
static inline void F_75 ( struct V_1 * V_7 , bool V_19 )
{
V_7 -> V_90 [ V_19 ] = 0 ;
V_7 -> V_91 [ V_19 ] = 0 ;
V_7 -> V_92 [ V_19 ] = V_16 ;
V_7 -> V_93 [ V_19 ] = V_16 + V_7 -> V_13 -> V_18 ;
F_72 ( & V_7 -> V_11 ,
L_3 ,
V_19 == V_52 ? 'R' : 'W' , V_7 -> V_92 [ V_19 ] ,
V_7 -> V_93 [ V_19 ] , V_16 ) ;
}
static inline void F_76 ( struct V_1 * V_7 , bool V_19 ,
unsigned long V_94 )
{
V_7 -> V_93 [ V_19 ] = F_77 ( V_94 , V_7 -> V_13 -> V_18 ) ;
}
static inline void F_78 ( struct V_1 * V_7 , bool V_19 ,
unsigned long V_94 )
{
V_7 -> V_93 [ V_19 ] = F_77 ( V_94 , V_7 -> V_13 -> V_18 ) ;
F_72 ( & V_7 -> V_11 ,
L_4 ,
V_19 == V_52 ? 'R' : 'W' , V_7 -> V_92 [ V_19 ] ,
V_7 -> V_93 [ V_19 ] , V_16 ) ;
}
static bool F_79 ( struct V_1 * V_7 , bool V_19 )
{
if ( F_80 ( V_16 , V_7 -> V_92 [ V_19 ] , V_7 -> V_93 [ V_19 ] ) )
return false ;
return 1 ;
}
static inline void F_81 ( struct V_1 * V_7 , bool V_19 )
{
unsigned long V_95 , V_96 , V_97 ;
T_3 V_98 , V_99 ;
F_82 ( F_62 ( V_7 -> V_93 [ V_19 ] , V_7 -> V_92 [ V_19 ] ) ) ;
if ( F_79 ( V_7 , V_19 ) )
return;
F_76 ( V_7 , V_19 , V_16 + V_7 -> V_13 -> V_18 ) ;
V_96 = V_16 - V_7 -> V_92 [ V_19 ] ;
V_95 = V_96 / V_7 -> V_13 -> V_18 ;
if ( ! V_95 )
return;
V_99 = F_11 ( V_7 , V_19 ) * V_7 -> V_13 -> V_18 * V_95 ;
F_83 ( V_99 , V_100 ) ;
V_98 = V_99 ;
V_97 = ( F_15 ( V_7 , V_19 ) * V_7 -> V_13 -> V_18 * V_95 ) /
V_100 ;
if ( ! V_98 && ! V_97 )
return;
if ( V_7 -> V_90 [ V_19 ] >= V_98 )
V_7 -> V_90 [ V_19 ] -= V_98 ;
else
V_7 -> V_90 [ V_19 ] = 0 ;
if ( V_7 -> V_91 [ V_19 ] >= V_97 )
V_7 -> V_91 [ V_19 ] -= V_97 ;
else
V_7 -> V_91 [ V_19 ] = 0 ;
V_7 -> V_92 [ V_19 ] += V_95 * V_7 -> V_13 -> V_18 ;
F_72 ( & V_7 -> V_11 ,
L_5 ,
V_19 == V_52 ? 'R' : 'W' , V_95 , V_98 , V_97 ,
V_7 -> V_92 [ V_19 ] , V_7 -> V_93 [ V_19 ] , V_16 ) ;
}
static bool F_84 ( struct V_1 * V_7 , struct V_36 * V_36 ,
unsigned long * V_101 )
{
bool V_19 = F_85 ( V_36 ) ;
unsigned int V_102 ;
unsigned long V_103 , V_104 , V_105 ;
T_3 V_99 ;
V_103 = V_105 = V_16 - V_7 -> V_92 [ V_19 ] ;
if ( ! V_103 )
V_105 = V_7 -> V_13 -> V_18 ;
V_105 = F_77 ( V_105 , V_7 -> V_13 -> V_18 ) ;
V_99 = ( T_3 ) F_15 ( V_7 , V_19 ) * V_105 ;
F_83 ( V_99 , V_100 ) ;
if ( V_99 > V_34 )
V_102 = V_34 ;
else
V_102 = V_99 ;
if ( V_7 -> V_91 [ V_19 ] + 1 <= V_102 ) {
if ( V_101 )
* V_101 = 0 ;
return true ;
}
V_104 = ( ( V_7 -> V_91 [ V_19 ] + 1 ) * V_100 ) / F_15 ( V_7 , V_19 ) + 1 ;
if ( V_104 > V_103 )
V_104 = V_104 - V_103 ;
else
V_104 = 1 ;
if ( V_101 )
* V_101 = V_104 ;
return 0 ;
}
static bool F_86 ( struct V_1 * V_7 , struct V_36 * V_36 ,
unsigned long * V_101 )
{
bool V_19 = F_85 ( V_36 ) ;
T_3 V_106 , V_107 , V_99 ;
unsigned long V_103 , V_104 , V_105 ;
unsigned int V_108 = F_17 ( V_36 ) ;
V_103 = V_105 = V_16 - V_7 -> V_92 [ V_19 ] ;
if ( ! V_103 )
V_105 = V_7 -> V_13 -> V_18 ;
V_105 = F_77 ( V_105 , V_7 -> V_13 -> V_18 ) ;
V_99 = F_11 ( V_7 , V_19 ) * V_105 ;
F_83 ( V_99 , V_100 ) ;
V_106 = V_99 ;
if ( V_7 -> V_90 [ V_19 ] + V_108 <= V_106 ) {
if ( V_101 )
* V_101 = 0 ;
return true ;
}
V_107 = V_7 -> V_90 [ V_19 ] + V_108 - V_106 ;
V_104 = F_87 ( V_107 * V_100 , F_11 ( V_7 , V_19 ) ) ;
if ( ! V_104 )
V_104 = 1 ;
V_104 = V_104 + ( V_105 - V_103 ) ;
if ( V_101 )
* V_101 = V_104 ;
return 0 ;
}
static bool F_88 ( struct V_1 * V_7 , struct V_36 * V_36 ,
unsigned long * V_101 )
{
bool V_19 = F_85 ( V_36 ) ;
unsigned long V_109 = 0 , V_110 = 0 , V_111 = 0 ;
F_82 ( V_7 -> V_11 . V_112 [ V_19 ] &&
V_36 != F_27 ( & V_7 -> V_11 . V_45 [ V_19 ] ) ) ;
if ( F_11 ( V_7 , V_19 ) == V_23 &&
F_15 ( V_7 , V_19 ) == V_34 ) {
if ( V_101 )
* V_101 = 0 ;
return true ;
}
if ( F_79 ( V_7 , V_19 ) && ! ( V_7 -> V_11 . V_112 [ V_19 ] ) )
F_75 ( V_7 , V_19 ) ;
else {
if ( F_62 ( V_7 -> V_93 [ V_19 ] ,
V_16 + V_7 -> V_13 -> V_18 ) )
F_78 ( V_7 , V_19 ,
V_16 + V_7 -> V_13 -> V_18 ) ;
}
if ( F_86 ( V_7 , V_36 , & V_109 ) &&
F_84 ( V_7 , V_36 , & V_110 ) ) {
if ( V_101 )
* V_101 = 0 ;
return 1 ;
}
V_111 = F_89 ( V_109 , V_110 ) ;
if ( V_101 )
* V_101 = V_111 ;
if ( F_62 ( V_7 -> V_93 [ V_19 ] , V_16 + V_111 ) )
F_78 ( V_7 , V_19 , V_16 + V_111 ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_7 , struct V_36 * V_36 )
{
bool V_19 = F_85 ( V_36 ) ;
unsigned int V_108 = F_17 ( V_36 ) ;
V_7 -> V_90 [ V_19 ] += V_108 ;
V_7 -> V_91 [ V_19 ] ++ ;
V_7 -> V_113 [ V_19 ] += V_108 ;
V_7 -> V_114 [ V_19 ] ++ ;
if ( ! F_91 ( V_36 , V_115 ) )
F_92 ( V_36 , V_115 ) ;
}
static void F_93 ( struct V_36 * V_36 , struct V_40 * V_41 ,
struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_19 = F_85 ( V_36 ) ;
if ( ! V_41 )
V_41 = & V_7 -> V_54 [ V_19 ] ;
if ( ! V_9 -> V_112 [ V_19 ] )
V_7 -> V_84 |= V_116 ;
F_23 ( V_36 , V_41 , & V_9 -> V_45 [ V_19 ] ) ;
V_9 -> V_112 [ V_19 ] ++ ;
F_66 ( V_7 ) ;
}
static void F_94 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned long V_117 = - 1 , V_118 = - 1 , V_119 = - 1 , V_78 ;
struct V_36 * V_36 ;
V_36 = F_27 ( & V_9 -> V_45 [ V_52 ] ) ;
if ( V_36 )
F_88 ( V_7 , V_36 , & V_117 ) ;
V_36 = F_27 ( & V_9 -> V_45 [ V_53 ] ) ;
if ( V_36 )
F_88 ( V_7 , V_36 , & V_118 ) ;
V_119 = F_14 ( V_117 , V_118 ) ;
V_78 = V_16 + V_119 ;
F_68 ( V_7 ) ;
V_7 -> V_78 = V_78 ;
F_66 ( V_7 ) ;
V_7 -> V_84 &= ~ V_116 ;
}
static void F_95 ( struct V_1 * V_120 ,
struct V_1 * V_66 , bool V_19 )
{
if ( F_79 ( V_66 , V_19 ) ) {
F_74 ( V_66 , V_19 ,
V_120 -> V_92 [ V_19 ] ) ;
}
}
static void F_96 ( struct V_1 * V_7 , bool V_19 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_8 * V_10 = V_9 -> V_10 ;
struct V_1 * V_66 = F_7 ( V_10 ) ;
struct V_1 * V_46 = NULL ;
struct V_36 * V_36 ;
V_36 = F_31 ( & V_9 -> V_45 [ V_19 ] , & V_46 ) ;
V_9 -> V_112 [ V_19 ] -- ;
F_90 ( V_7 , V_36 ) ;
if ( V_66 ) {
F_93 ( V_36 , & V_7 -> V_55 [ V_19 ] , V_66 ) ;
F_95 ( V_7 , V_66 , V_19 ) ;
} else {
F_23 ( V_36 , & V_7 -> V_55 [ V_19 ] ,
& V_10 -> V_45 [ V_19 ] ) ;
F_82 ( V_7 -> V_13 -> V_112 [ V_19 ] <= 0 ) ;
V_7 -> V_13 -> V_112 [ V_19 ] -- ;
}
F_81 ( V_7 , V_19 ) ;
if ( V_46 )
F_35 ( F_5 ( V_46 ) ) ;
}
static int F_97 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned int V_121 = 0 , V_122 = 0 ;
unsigned int V_123 = V_124 * 3 / 4 ;
unsigned int V_125 = V_124 - V_123 ;
struct V_36 * V_36 ;
while ( ( V_36 = F_27 ( & V_9 -> V_45 [ V_52 ] ) ) &&
F_88 ( V_7 , V_36 , NULL ) ) {
F_96 ( V_7 , F_85 ( V_36 ) ) ;
V_121 ++ ;
if ( V_121 >= V_123 )
break;
}
while ( ( V_36 = F_27 ( & V_9 -> V_45 [ V_53 ] ) ) &&
F_88 ( V_7 , V_36 , NULL ) ) {
F_96 ( V_7 , F_85 ( V_36 ) ) ;
V_122 ++ ;
if ( V_122 >= V_125 )
break;
}
return V_121 + V_122 ;
}
static int F_98 ( struct V_8 * V_10 )
{
unsigned int V_126 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_54 ( V_10 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
if ( ! V_7 )
break;
if ( F_62 ( V_16 , V_7 -> V_78 ) )
break;
F_68 ( V_7 ) ;
V_126 += F_97 ( V_7 ) ;
if ( V_9 -> V_112 [ 0 ] || V_9 -> V_112 [ 1 ] )
F_94 ( V_7 ) ;
if ( V_126 >= V_127 )
break;
}
return V_126 ;
}
static void V_50 ( unsigned long V_128 )
{
struct V_8 * V_9 = ( void * ) V_128 ;
struct V_1 * V_7 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_129 * V_65 = V_13 -> V_130 ;
struct V_8 * V_10 ;
bool V_131 ;
int V_20 ;
F_99 ( V_65 -> V_132 ) ;
if ( F_100 ( V_13 , NULL ) )
F_50 ( V_13 ) ;
V_133:
V_10 = V_9 -> V_10 ;
V_131 = false ;
while ( true ) {
F_72 ( V_9 , L_6 ,
V_9 -> V_112 [ V_52 ] + V_9 -> V_112 [ V_53 ] ,
V_9 -> V_112 [ V_52 ] , V_9 -> V_112 [ V_53 ] ) ;
V_20 = F_98 ( V_9 ) ;
if ( V_20 ) {
F_72 ( V_9 , L_7 , V_20 ) ;
V_131 = true ;
}
if ( F_73 ( V_9 , false ) )
break;
F_101 ( V_65 -> V_132 ) ;
F_102 () ;
F_99 ( V_65 -> V_132 ) ;
}
if ( ! V_131 )
goto V_134;
if ( V_10 ) {
if ( V_7 -> V_84 & V_116 ) {
F_94 ( V_7 ) ;
if ( ! F_73 ( V_10 , false ) ) {
V_9 = V_10 ;
V_7 = F_7 ( V_9 ) ;
goto V_133;
}
}
} else {
F_103 ( V_135 , & V_13 -> V_136 ) ;
}
V_134:
F_101 ( V_65 -> V_132 ) ;
}
static void F_104 ( struct V_137 * V_138 )
{
struct V_12 * V_13 = F_2 ( V_138 , struct V_12 ,
V_136 ) ;
struct V_8 * V_139 = & V_13 -> V_11 ;
struct V_129 * V_65 = V_13 -> V_130 ;
struct V_140 V_141 ;
struct V_36 * V_36 ;
struct V_142 V_143 ;
int V_19 ;
F_22 ( & V_141 ) ;
F_99 ( V_65 -> V_132 ) ;
for ( V_19 = V_52 ; V_19 <= V_53 ; V_19 ++ )
while ( ( V_36 = F_31 ( & V_139 -> V_45 [ V_19 ] , NULL ) ) )
F_24 ( & V_141 , V_36 ) ;
F_101 ( V_65 -> V_132 ) ;
if ( ! F_33 ( & V_141 ) ) {
F_105 ( & V_143 ) ;
while( ( V_36 = F_32 ( & V_141 ) ) )
F_106 ( V_36 ) ;
F_107 ( & V_143 ) ;
}
}
static T_3 F_108 ( struct V_144 * V_145 , struct V_2 * V_3 ,
int V_146 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_3 V_147 = * ( T_3 * ) ( ( void * ) V_7 + V_146 ) ;
if ( V_147 == V_23 )
return 0 ;
return F_109 ( V_145 , V_3 , V_147 ) ;
}
static T_3 F_110 ( struct V_144 * V_145 , struct V_2 * V_3 ,
int V_146 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_147 = * ( unsigned int * ) ( ( void * ) V_7 + V_146 ) ;
if ( V_147 == V_34 )
return 0 ;
return F_109 ( V_145 , V_3 , V_147 ) ;
}
static int F_111 ( struct V_144 * V_145 , void * V_147 )
{
F_112 ( V_145 , F_113 ( F_114 ( V_145 ) ) , F_108 ,
& V_6 , F_115 ( V_145 ) -> V_148 , false ) ;
return 0 ;
}
static int F_116 ( struct V_144 * V_145 , void * V_147 )
{
F_112 ( V_145 , F_113 ( F_114 ( V_145 ) ) , F_110 ,
& V_6 , F_115 ( V_145 ) -> V_148 , false ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_7 , bool V_149 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_69 * V_70 ;
struct V_4 * V_5 ;
F_72 ( & V_7 -> V_11 ,
L_8 ,
F_11 ( V_7 , V_52 ) , F_11 ( V_7 , V_53 ) ,
F_15 ( V_7 , V_52 ) , F_15 ( V_7 , V_53 ) ) ;
F_118 (blkg, pos_css,
global ? tg->td->queue->root_blkg : tg_to_blkg(tg)) {
struct V_1 * V_150 = F_3 ( V_5 ) ;
struct V_1 * V_66 ;
F_43 ( V_150 ) ;
if ( ! F_12 ( V_21 ) || ! V_5 -> V_22 ||
! V_5 -> V_22 -> V_22 )
continue;
V_66 = F_3 ( V_5 -> V_22 ) ;
V_150 -> V_62 = F_14 ( V_150 -> V_62 ,
V_66 -> V_62 ) ;
V_150 -> V_59 = F_89 ( V_150 -> V_59 ,
V_66 -> V_59 ) ;
}
F_75 ( V_7 , 0 ) ;
F_75 ( V_7 , 1 ) ;
if ( V_7 -> V_84 & V_85 ) {
F_94 ( V_7 ) ;
F_73 ( V_9 -> V_10 , true ) ;
}
}
static T_4 F_119 ( struct V_151 * V_152 ,
char * V_153 , T_5 V_154 , T_6 V_146 , bool V_155 )
{
struct V_27 * V_27 = F_113 ( F_120 ( V_152 ) ) ;
struct V_156 V_157 ;
struct V_1 * V_7 ;
int V_20 ;
T_3 V_147 ;
V_20 = F_121 ( V_27 , & V_6 , V_153 , & V_157 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_158 ;
if ( sscanf ( V_157 . V_159 , L_9 , & V_147 ) != 1 )
goto V_160;
if ( ! V_147 )
V_147 = V_23 ;
V_7 = F_3 ( V_157 . V_5 ) ;
if ( V_155 )
* ( T_3 * ) ( ( void * ) V_7 + F_122 ( V_152 ) -> V_148 ) = V_147 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + F_122 ( V_152 ) -> V_148 ) = V_147 ;
F_117 ( V_7 , false ) ;
V_20 = 0 ;
V_160:
F_123 ( & V_157 ) ;
return V_20 ? : V_154 ;
}
static T_4 F_124 ( struct V_151 * V_152 ,
char * V_153 , T_5 V_154 , T_6 V_146 )
{
return F_119 ( V_152 , V_153 , V_154 , V_146 , true ) ;
}
static T_4 F_125 ( struct V_151 * V_152 ,
char * V_153 , T_5 V_154 , T_6 V_146 )
{
return F_119 ( V_152 , V_153 , V_154 , V_146 , false ) ;
}
static T_3 F_126 ( struct V_144 * V_145 , struct V_2 * V_3 ,
int V_146 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
const char * V_161 = F_127 ( V_3 -> V_5 ) ;
char V_162 [ 4 ] [ 21 ] = { L_10 , L_10 , L_10 , L_10 } ;
T_3 V_163 ;
unsigned int V_164 ;
char V_165 [ 26 ] = L_11 ;
char V_166 [ 26 ] = L_11 ;
if ( ! V_161 )
return 0 ;
if ( V_146 == V_26 ) {
V_163 = 0 ;
V_164 = 0 ;
} else {
V_163 = V_23 ;
V_164 = V_34 ;
}
if ( V_7 -> V_57 [ V_52 ] [ V_146 ] == V_163 &&
V_7 -> V_57 [ V_53 ] [ V_146 ] == V_163 &&
V_7 -> V_58 [ V_52 ] [ V_146 ] == V_164 &&
V_7 -> V_58 [ V_53 ] [ V_146 ] == V_164 &&
( V_146 != V_26 ||
( V_7 -> V_64 == V_63 &&
V_7 -> V_61 == V_60 ) ) )
return 0 ;
if ( V_7 -> V_57 [ V_52 ] [ V_146 ] != V_23 )
snprintf ( V_162 [ 0 ] , sizeof( V_162 [ 0 ] ) , L_9 ,
V_7 -> V_57 [ V_52 ] [ V_146 ] ) ;
if ( V_7 -> V_57 [ V_53 ] [ V_146 ] != V_23 )
snprintf ( V_162 [ 1 ] , sizeof( V_162 [ 1 ] ) , L_9 ,
V_7 -> V_57 [ V_53 ] [ V_146 ] ) ;
if ( V_7 -> V_58 [ V_52 ] [ V_146 ] != V_34 )
snprintf ( V_162 [ 2 ] , sizeof( V_162 [ 2 ] ) , L_12 ,
V_7 -> V_58 [ V_52 ] [ V_146 ] ) ;
if ( V_7 -> V_58 [ V_53 ] [ V_146 ] != V_34 )
snprintf ( V_162 [ 3 ] , sizeof( V_162 [ 3 ] ) , L_12 ,
V_7 -> V_58 [ V_53 ] [ V_146 ] ) ;
if ( V_146 == V_26 ) {
if ( V_7 -> V_64 == V_167 )
strcpy ( V_165 , L_13 ) ;
else
snprintf ( V_165 , sizeof( V_165 ) , L_14 ,
V_7 -> V_64 ) ;
if ( V_7 -> V_61 == V_167 )
strcpy ( V_166 , L_15 ) ;
else
snprintf ( V_166 , sizeof( V_166 ) ,
L_16 , V_7 -> V_61 ) ;
}
F_128 ( V_145 , L_17 ,
V_161 , V_162 [ 0 ] , V_162 [ 1 ] , V_162 [ 2 ] , V_162 [ 3 ] , V_165 ,
V_166 ) ;
return 0 ;
}
static int F_129 ( struct V_144 * V_145 , void * V_147 )
{
F_112 ( V_145 , F_113 ( F_114 ( V_145 ) ) , F_126 ,
& V_6 , F_115 ( V_145 ) -> V_148 , false ) ;
return 0 ;
}
static T_4 F_130 ( struct V_151 * V_152 ,
char * V_153 , T_5 V_154 , T_6 V_146 )
{
struct V_27 * V_27 = F_113 ( F_120 ( V_152 ) ) ;
struct V_156 V_157 ;
struct V_1 * V_7 ;
T_3 V_147 [ 4 ] ;
unsigned long V_165 ;
unsigned long V_166 ;
int V_20 ;
int V_168 = F_122 ( V_152 ) -> V_148 ;
V_20 = F_121 ( V_27 , & V_6 , V_153 , & V_157 ) ;
if ( V_20 )
return V_20 ;
V_7 = F_3 ( V_157 . V_5 ) ;
V_147 [ 0 ] = V_7 -> V_57 [ V_52 ] [ V_168 ] ;
V_147 [ 1 ] = V_7 -> V_57 [ V_53 ] [ V_168 ] ;
V_147 [ 2 ] = V_7 -> V_58 [ V_52 ] [ V_168 ] ;
V_147 [ 3 ] = V_7 -> V_58 [ V_53 ] [ V_168 ] ;
V_165 = V_7 -> V_64 ;
V_166 = V_7 -> V_61 ;
while ( true ) {
char V_169 [ 27 ] ;
char * V_170 ;
T_3 V_171 = V_23 ;
int V_172 ;
if ( sscanf ( V_157 . V_159 , L_18 , V_169 , & V_172 ) != 1 )
break;
if ( V_169 [ 0 ] == '\0' )
break;
V_157 . V_159 += V_172 ;
V_20 = - V_158 ;
V_170 = V_169 ;
F_131 ( & V_170 , L_19 ) ;
if ( ! V_170 || ( sscanf ( V_170 , L_9 , & V_171 ) != 1 && strcmp ( V_170 , L_10 ) ) )
goto V_160;
V_20 = - V_173 ;
if ( ! V_171 )
goto V_160;
V_20 = - V_158 ;
if ( ! strcmp ( V_169 , L_20 ) )
V_147 [ 0 ] = V_171 ;
else if ( ! strcmp ( V_169 , L_21 ) )
V_147 [ 1 ] = V_171 ;
else if ( ! strcmp ( V_169 , L_22 ) )
V_147 [ 2 ] = F_16 ( T_3 , V_171 , V_34 ) ;
else if ( ! strcmp ( V_169 , L_23 ) )
V_147 [ 3 ] = F_16 ( T_3 , V_171 , V_34 ) ;
else if ( V_146 == V_26 && ! strcmp ( V_169 , L_24 ) )
V_165 = V_171 ;
else if ( V_146 == V_26 && ! strcmp ( V_169 , L_25 ) )
V_166 = V_171 ;
else
goto V_160;
}
V_7 -> V_57 [ V_52 ] [ V_168 ] = V_147 [ 0 ] ;
V_7 -> V_57 [ V_53 ] [ V_168 ] = V_147 [ 1 ] ;
V_7 -> V_58 [ V_52 ] [ V_168 ] = V_147 [ 2 ] ;
V_7 -> V_58 [ V_53 ] [ V_168 ] = V_147 [ 3 ] ;
if ( V_168 == V_32 ) {
V_7 -> V_24 [ V_52 ] [ V_168 ] = V_147 [ 0 ] ;
V_7 -> V_24 [ V_53 ] [ V_168 ] = V_147 [ 1 ] ;
V_7 -> V_30 [ V_52 ] [ V_168 ] = V_147 [ 2 ] ;
V_7 -> V_30 [ V_53 ] [ V_168 ] = V_147 [ 3 ] ;
}
V_7 -> V_24 [ V_52 ] [ V_26 ] = F_14 ( V_7 -> V_57 [ V_52 ] [ V_26 ] ,
V_7 -> V_57 [ V_52 ] [ V_32 ] ) ;
V_7 -> V_24 [ V_53 ] [ V_26 ] = F_14 ( V_7 -> V_57 [ V_53 ] [ V_26 ] ,
V_7 -> V_57 [ V_53 ] [ V_32 ] ) ;
V_7 -> V_30 [ V_52 ] [ V_26 ] = F_14 ( V_7 -> V_58 [ V_52 ] [ V_26 ] ,
V_7 -> V_58 [ V_52 ] [ V_32 ] ) ;
V_7 -> V_30 [ V_53 ] [ V_26 ] = F_14 ( V_7 -> V_58 [ V_53 ] [ V_26 ] ,
V_7 -> V_58 [ V_53 ] [ V_32 ] ) ;
V_7 -> V_64 = V_165 ;
V_7 -> V_61 = V_166 ;
if ( ! ( V_7 -> V_24 [ V_52 ] [ V_26 ] || V_7 -> V_30 [ V_52 ] [ V_26 ] ||
V_7 -> V_24 [ V_53 ] [ V_26 ] || V_7 -> V_30 [ V_53 ] [ V_26 ] ) ||
V_7 -> V_64 == V_63 ||
V_7 -> V_61 == V_60 ) {
V_7 -> V_24 [ V_52 ] [ V_26 ] = 0 ;
V_7 -> V_24 [ V_53 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_52 ] [ V_26 ] = 0 ;
V_7 -> V_30 [ V_53 ] [ V_26 ] = 0 ;
V_7 -> V_62 = V_63 ;
V_7 -> V_59 = V_60 ;
} else if ( V_168 == V_26 ) {
V_7 -> V_62 = V_7 -> V_64 ;
V_7 -> V_59 = V_7 -> V_61 ;
}
F_45 ( V_7 -> V_13 ) ;
if ( V_7 -> V_13 -> V_68 [ V_26 ] ) {
if ( V_168 == V_26 )
V_7 -> V_13 -> V_25 = V_26 ;
} else
V_7 -> V_13 -> V_25 = V_32 ;
F_117 ( V_7 , V_168 == V_26 &&
V_7 -> V_13 -> V_68 [ V_26 ] ) ;
V_20 = 0 ;
V_160:
F_123 ( & V_157 ) ;
return V_20 ? : V_154 ;
}
static void F_132 ( struct V_129 * V_65 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
F_133 ( & V_13 -> V_136 ) ;
}
static unsigned long F_134 ( struct V_1 * V_7 )
{
unsigned long V_174 = V_16 , V_175 = V_16 ;
if ( V_7 -> V_24 [ V_52 ] [ V_26 ] || V_7 -> V_30 [ V_52 ] [ V_26 ] )
V_174 = V_7 -> V_176 [ V_52 ] ;
if ( V_7 -> V_24 [ V_53 ] [ V_26 ] || V_7 -> V_30 [ V_53 ] [ V_26 ] )
V_175 = V_7 -> V_176 [ V_53 ] ;
return F_14 ( V_174 , V_175 ) ;
}
static unsigned long F_135 ( struct V_1 * V_7 )
{
struct V_8 * V_10 ;
struct V_1 * V_22 = V_7 ;
unsigned long V_20 = F_134 ( V_7 ) ;
while ( true ) {
V_10 = V_22 -> V_11 . V_10 ;
V_22 = F_7 ( V_10 ) ;
if ( ! V_22 )
break;
if ( ! V_22 -> V_24 [ V_52 ] [ V_26 ] &&
! V_22 -> V_30 [ V_52 ] [ V_26 ] &&
! V_22 -> V_24 [ V_53 ] [ V_26 ] &&
! V_22 -> V_30 [ V_53 ] [ V_26 ] )
continue;
if ( F_70 ( F_134 ( V_22 ) , V_20 ) )
V_20 = F_134 ( V_22 ) ;
}
return V_20 ;
}
static bool F_136 ( struct V_1 * V_7 )
{
unsigned long time ;
bool V_20 ;
time = F_16 (unsigned long, MAX_IDLE_TIME, 4 * tg->idletime_threshold) ;
V_20 = V_7 -> V_59 == V_60 ||
V_7 -> V_62 == V_63 ||
( F_137 () >> 10 ) - V_7 -> V_177 > time ||
V_7 -> V_178 > V_7 -> V_62 ||
( V_7 -> V_59 && V_7 -> V_179 &&
V_7 -> V_180 * 5 < V_7 -> V_179 ) ;
F_72 ( & V_7 -> V_11 ,
L_26 ,
V_7 -> V_178 , V_7 -> V_62 , V_7 -> V_180 ,
V_7 -> V_179 , V_20 , V_7 -> V_13 -> V_15 ) ;
return V_20 ;
}
static bool F_138 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_181 , V_182 ;
V_181 = V_7 -> V_24 [ V_52 ] [ V_26 ] || V_7 -> V_30 [ V_52 ] [ V_26 ] ;
V_182 = V_7 -> V_24 [ V_53 ] [ V_26 ] || V_7 -> V_30 [ V_53 ] [ V_26 ] ;
if ( ! V_181 && ! V_182 )
return true ;
if ( V_181 && V_9 -> V_112 [ V_52 ] &&
( ! V_182 || V_9 -> V_112 [ V_53 ] ) )
return true ;
if ( V_182 && V_9 -> V_112 [ V_53 ] &&
( ! V_181 || V_9 -> V_112 [ V_52 ] ) )
return true ;
if ( F_10 ( V_16 ,
F_135 ( V_7 ) + V_7 -> V_13 -> V_18 ) &&
F_136 ( V_7 ) )
return true ;
return false ;
}
static bool F_139 ( struct V_1 * V_7 )
{
while ( true ) {
if ( F_138 ( V_7 ) )
return true ;
V_7 = F_7 ( V_7 -> V_11 . V_10 ) ;
if ( ! V_7 || ! F_5 ( V_7 ) -> V_22 )
return false ;
}
return false ;
}
static bool F_100 ( struct V_12 * V_13 ,
struct V_1 * V_150 )
{
struct V_69 * V_70 ;
struct V_4 * V_5 ;
if ( V_13 -> V_25 != V_26 )
return false ;
if ( F_62 ( V_16 , V_13 -> V_183 + V_13 -> V_18 ) )
return false ;
F_46 () ;
F_47 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( V_7 == V_150 )
continue;
if ( ! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) )
continue;
if ( ! F_139 ( V_7 ) ) {
F_48 () ;
return false ;
}
}
F_48 () ;
return true ;
}
static void F_140 ( struct V_1 * V_7 )
{
unsigned long V_184 = V_16 ;
if ( V_7 -> V_13 -> V_25 != V_26 )
return;
if ( F_70 ( V_7 -> V_185 + V_7 -> V_13 -> V_18 , V_184 ) )
return;
V_7 -> V_185 = V_184 ;
if ( ! F_10 ( V_184 ,
F_134 ( V_7 ) + V_7 -> V_13 -> V_18 ) )
return;
if ( F_100 ( V_7 -> V_13 , NULL ) )
F_50 ( V_7 -> V_13 ) ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_69 * V_70 ;
struct V_4 * V_5 ;
F_72 ( & V_13 -> V_11 , L_27 ) ;
V_13 -> V_25 = V_32 ;
V_13 -> V_17 = V_16 ;
V_13 -> V_15 = 0 ;
F_46 () ;
F_47 (blkg, pos_css, td->queue->root_blkg) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
V_7 -> V_78 = V_16 - 1 ;
F_98 ( V_9 ) ;
F_73 ( V_9 , true ) ;
}
F_48 () ;
F_98 ( & V_13 -> V_11 ) ;
F_73 ( & V_13 -> V_11 , true ) ;
F_103 ( V_135 , & V_13 -> V_136 ) ;
}
static void F_141 ( struct V_12 * V_13 , int V_186 )
{
V_13 -> V_15 /= 2 ;
F_72 ( & V_13 -> V_11 , L_28 , V_13 -> V_15 ) ;
if ( V_13 -> V_15 ) {
V_13 -> V_17 = V_16 - V_13 -> V_15 * V_13 -> V_18 ;
return;
}
V_13 -> V_25 = V_186 ;
V_13 -> V_183 = V_16 ;
}
static bool F_142 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_13 ;
unsigned long V_184 = V_16 ;
if ( F_10 ( V_184 , V_13 -> V_17 + V_13 -> V_18 ) &&
F_10 ( V_184 , F_135 ( V_7 ) +
V_13 -> V_18 ) &&
( ! F_136 ( V_7 ) ||
! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) ) )
return true ;
return false ;
}
static bool F_143 ( struct V_1 * V_7 )
{
while ( true ) {
if ( ! F_142 ( V_7 ) )
return false ;
V_7 = F_7 ( V_7 -> V_11 . V_10 ) ;
if ( ! V_7 || ! F_5 ( V_7 ) -> V_22 )
break;
}
return true ;
}
static void F_144 ( struct V_1 * V_7 )
{
T_1 V_24 ;
unsigned int V_30 ;
unsigned long V_187 ;
unsigned long V_184 = V_16 ;
if ( V_7 -> V_13 -> V_25 != V_32 ||
! V_7 -> V_13 -> V_68 [ V_26 ] )
return;
if ( ! F_13 ( & F_5 ( V_7 ) -> V_27 -> V_28 . V_29 ) )
return;
if ( F_70 ( V_7 -> V_185 + V_7 -> V_13 -> V_18 , V_184 ) )
return;
V_187 = V_184 - V_7 -> V_185 ;
V_7 -> V_185 = V_184 ;
if ( F_62 ( V_184 , F_135 ( V_7 ) +
V_7 -> V_13 -> V_18 ) )
return;
if ( V_7 -> V_24 [ V_52 ] [ V_26 ] ) {
V_24 = V_7 -> V_113 [ V_52 ] * V_100 ;
F_83 ( V_24 , V_187 ) ;
if ( V_24 >= V_7 -> V_24 [ V_52 ] [ V_26 ] )
V_7 -> V_176 [ V_52 ] = V_184 ;
}
if ( V_7 -> V_24 [ V_53 ] [ V_26 ] ) {
V_24 = V_7 -> V_113 [ V_53 ] * V_100 ;
F_83 ( V_24 , V_187 ) ;
if ( V_24 >= V_7 -> V_24 [ V_53 ] [ V_26 ] )
V_7 -> V_176 [ V_53 ] = V_184 ;
}
if ( V_7 -> V_30 [ V_52 ] [ V_26 ] ) {
V_30 = V_7 -> V_114 [ V_52 ] * V_100 / V_187 ;
if ( V_30 >= V_7 -> V_30 [ V_52 ] [ V_26 ] )
V_7 -> V_176 [ V_52 ] = V_184 ;
}
if ( V_7 -> V_30 [ V_53 ] [ V_26 ] ) {
V_30 = V_7 -> V_114 [ V_53 ] * V_100 / V_187 ;
if ( V_30 >= V_7 -> V_30 [ V_53 ] [ V_26 ] )
V_7 -> V_176 [ V_53 ] = V_184 ;
}
if ( F_143 ( V_7 ) )
F_141 ( V_7 -> V_13 , V_26 ) ;
V_7 -> V_113 [ V_52 ] = 0 ;
V_7 -> V_113 [ V_53 ] = 0 ;
V_7 -> V_114 [ V_52 ] = 0 ;
V_7 -> V_114 [ V_53 ] = 0 ;
}
static void F_145 ( struct V_1 * V_7 )
{
unsigned long V_184 = F_137 () >> 10 ;
unsigned long V_177 = V_7 -> V_177 ;
if ( V_184 <= V_177 || V_177 == 0 ||
V_177 == V_7 -> V_188 )
return;
V_7 -> V_178 = ( V_7 -> V_178 * 7 + V_184 - V_177 ) >> 3 ;
V_7 -> V_188 = V_177 ;
}
static void F_146 ( struct V_12 * V_13 )
{
struct V_189 V_190 [ V_191 ] ;
int V_192 , V_193 ;
unsigned long V_194 = 0 ;
unsigned long V_195 ;
if ( ! F_147 ( V_13 -> V_130 ) )
return;
if ( F_62 ( V_16 , V_13 -> V_196 + V_100 ) )
return;
V_13 -> V_196 = V_16 ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ ) {
struct V_197 * V_99 = & V_13 -> V_198 [ V_192 ] ;
F_148 (cpu) {
struct V_197 * V_199 ;
V_199 = F_149 ( V_13 -> V_200 , V_193 ) ;
V_99 -> V_201 += V_199 [ V_192 ] . V_201 ;
V_99 -> V_202 += V_199 [ V_192 ] . V_202 ;
V_199 [ V_192 ] . V_201 = 0 ;
V_199 [ V_192 ] . V_202 = 0 ;
}
if ( V_99 -> V_202 >= 32 ) {
int V_202 = V_99 -> V_202 ;
V_195 = V_99 -> V_201 ;
V_99 -> V_201 = 0 ;
V_99 -> V_202 = 0 ;
V_195 /= V_202 ;
if ( V_195 == 0 )
continue;
V_190 [ V_192 ] . V_195 = V_195 ;
}
}
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ ) {
if ( ! V_190 [ V_192 ] . V_195 ) {
if ( V_13 -> V_203 [ V_192 ] . V_195 < V_194 )
V_13 -> V_203 [ V_192 ] . V_195 = V_194 ;
continue;
}
if ( ! V_13 -> V_203 [ V_192 ] . V_204 )
V_195 = V_190 [ V_192 ] . V_195 ;
else
V_195 = ( V_13 -> V_203 [ V_192 ] . V_195 * 7 +
V_190 [ V_192 ] . V_195 ) >> 3 ;
V_13 -> V_203 [ V_192 ] . V_195 = F_89 ( V_195 , V_194 ) ;
V_13 -> V_203 [ V_192 ] . V_204 = true ;
V_194 = V_13 -> V_203 [ V_192 ] . V_195 ;
}
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ )
F_72 ( & V_13 -> V_11 ,
L_29 , V_192 ,
V_13 -> V_203 [ V_192 ] . V_195 , V_13 -> V_203 [ V_192 ] . V_204 ) ;
}
static inline void F_146 ( struct V_12 * V_13 )
{
}
static void F_150 ( struct V_1 * V_7 , struct V_36 * V_36 )
{
#ifdef F_151
if ( V_36 -> V_205 )
V_36 -> V_206 = V_7 ;
F_152 ( & V_36 -> V_207 , F_153 ( V_36 ) ) ;
#endif
}
bool F_154 ( struct V_129 * V_65 , struct V_4 * V_5 ,
struct V_36 * V_36 )
{
struct V_40 * V_41 = NULL ;
struct V_1 * V_7 = F_3 ( V_5 ? : V_65 -> V_208 ) ;
struct V_8 * V_9 ;
bool V_19 = F_85 ( V_36 ) ;
bool V_209 = false ;
struct V_12 * V_13 = V_7 -> V_13 ;
F_30 ( ! F_155 () ) ;
if ( F_91 ( V_36 , V_115 ) || ! V_7 -> V_67 [ V_19 ] )
goto V_210;
F_99 ( V_65 -> V_132 ) ;
F_146 ( V_13 ) ;
if ( F_18 ( F_156 ( V_65 ) ) )
goto V_134;
F_150 ( V_7 , V_36 ) ;
F_145 ( V_7 ) ;
V_9 = & V_7 -> V_11 ;
V_133:
while ( true ) {
if ( V_7 -> V_176 [ V_19 ] == 0 )
V_7 -> V_176 [ V_19 ] = V_16 ;
F_144 ( V_7 ) ;
F_140 ( V_7 ) ;
if ( V_9 -> V_112 [ V_19 ] )
break;
if ( ! F_88 ( V_7 , V_36 , NULL ) ) {
V_7 -> V_176 [ V_19 ] = V_16 ;
if ( F_100 ( V_13 , V_7 ) ) {
F_50 ( V_13 ) ;
goto V_133;
}
break;
}
F_90 ( V_7 , V_36 ) ;
F_81 ( V_7 , V_19 ) ;
V_41 = & V_7 -> V_55 [ V_19 ] ;
V_9 = V_9 -> V_10 ;
V_7 = F_7 ( V_9 ) ;
if ( ! V_7 )
goto V_134;
}
F_72 ( V_9 , L_30 ,
V_19 == V_52 ? 'R' : 'W' ,
V_7 -> V_90 [ V_19 ] , V_36 -> V_38 . V_39 ,
F_11 ( V_7 , V_19 ) ,
V_7 -> V_91 [ V_19 ] , F_15 ( V_7 , V_19 ) ,
V_9 -> V_112 [ V_52 ] , V_9 -> V_112 [ V_53 ] ) ;
V_7 -> V_176 [ V_19 ] = V_16 ;
V_13 -> V_112 [ V_19 ] ++ ;
F_93 ( V_36 , V_41 , V_7 ) ;
V_209 = true ;
if ( V_7 -> V_84 & V_116 ) {
F_94 ( V_7 ) ;
F_73 ( V_7 -> V_11 . V_10 , true ) ;
}
V_134:
F_101 ( V_65 -> V_132 ) ;
V_210:
if ( ! V_209 )
F_157 ( V_36 , V_115 ) ;
#ifdef F_151
if ( V_209 || ! V_13 -> V_211 )
V_36 -> V_207 . V_212 |= V_213 ;
#endif
return V_209 ;
}
static void F_158 ( struct V_12 * V_13 , T_7 V_214 ,
int V_215 , unsigned long time )
{
struct V_197 * V_195 ;
int V_168 ;
if ( ! V_13 || V_13 -> V_25 != V_26 || V_215 != V_216 ||
! F_147 ( V_13 -> V_130 ) )
return;
V_168 = F_159 ( V_214 ) ;
V_195 = F_160 ( V_13 -> V_200 ) ;
V_195 [ V_168 ] . V_201 += time ;
V_195 [ V_168 ] . V_202 ++ ;
F_161 ( V_13 -> V_200 ) ;
}
void F_162 ( struct V_217 * V_218 , T_3 V_219 )
{
struct V_129 * V_65 = V_218 -> V_65 ;
struct V_12 * V_13 = V_65 -> V_13 ;
F_158 ( V_13 , F_163 ( & V_218 -> V_220 ) ,
F_164 ( V_218 ) , V_219 >> 10 ) ;
}
void F_165 ( struct V_36 * V_36 )
{
struct V_1 * V_7 ;
T_3 V_221 ;
unsigned long V_222 ;
unsigned long V_223 ;
unsigned long V_224 ;
V_7 = V_36 -> V_206 ;
if ( ! V_7 )
return;
V_36 -> V_206 = NULL ;
V_221 = F_137 () ;
V_7 -> V_177 = V_221 >> 10 ;
V_223 = F_166 ( & V_36 -> V_207 ) >> 10 ;
V_222 = F_167 ( V_221 ) >> 10 ;
if ( ! V_223 || V_222 <= V_223 )
return;
V_224 = V_222 - V_223 ;
if ( ! ( V_36 -> V_207 . V_212 & V_213 ) )
F_158 ( V_7 -> V_13 , F_163 ( & V_36 -> V_207 ) ,
F_19 ( V_36 ) , V_224 ) ;
if ( V_7 -> V_59 && V_224 >= V_7 -> V_13 -> V_225 ) {
int V_199 ;
unsigned int V_226 ;
V_199 = F_159 (
F_163 ( & V_36 -> V_207 ) ) ;
V_226 = V_7 -> V_13 -> V_203 [ V_199 ] . V_195 +
V_7 -> V_59 ;
if ( V_224 > V_226 )
V_7 -> V_180 ++ ;
V_7 -> V_179 ++ ;
}
if ( F_70 ( V_16 , V_7 -> V_227 ) || V_7 -> V_179 > 1024 ) {
V_7 -> V_227 = V_7 -> V_13 -> V_18 + V_16 ;
V_7 -> V_179 /= 2 ;
V_7 -> V_180 /= 2 ;
}
}
static void F_168 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_54 ( V_10 ) ) ) {
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_36 * V_36 ;
F_68 ( V_7 ) ;
while ( ( V_36 = F_27 ( & V_9 -> V_45 [ V_52 ] ) ) )
F_96 ( V_7 , F_85 ( V_36 ) ) ;
while ( ( V_36 = F_27 ( & V_9 -> V_45 [ V_53 ] ) ) )
F_96 ( V_7 , F_85 ( V_36 ) ) ;
}
}
void F_169 ( struct V_129 * V_65 )
__releases( V_65 -> V_132 ) __acquires( V_65 -> V_132 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_4 * V_5 ;
struct V_69 * V_70 ;
struct V_36 * V_36 ;
int V_19 ;
F_170 ( V_65 ) ;
F_46 () ;
F_47 (blkg, pos_css, td->queue->root_blkg)
F_168 ( & F_3 ( V_5 ) -> V_11 ) ;
F_168 ( & V_13 -> V_11 ) ;
F_48 () ;
F_101 ( V_65 -> V_132 ) ;
for ( V_19 = V_52 ; V_19 <= V_53 ; V_19 ++ )
while ( ( V_36 = F_31 ( & V_13 -> V_11 . V_45 [ V_19 ] ,
NULL ) ) )
F_106 ( V_36 ) ;
F_99 ( V_65 -> V_132 ) ;
}
int F_171 ( struct V_129 * V_65 )
{
struct V_12 * V_13 ;
int V_20 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_228 , V_65 -> V_42 ) ;
if ( ! V_13 )
return - V_229 ;
V_13 -> V_200 = F_172 ( sizeof( struct V_197 ) *
V_191 , F_173 ( T_3 ) ) ;
if ( ! V_13 -> V_200 ) {
F_53 ( V_13 ) ;
return - V_229 ;
}
F_174 ( & V_13 -> V_136 , F_104 ) ;
F_37 ( & V_13 -> V_11 ) ;
V_65 -> V_13 = V_13 ;
V_13 -> V_130 = V_65 ;
V_13 -> V_68 [ V_32 ] = true ;
V_13 -> V_25 = V_32 ;
V_13 -> V_17 = V_16 ;
V_13 -> V_183 = V_16 ;
V_20 = F_175 ( V_65 , & V_6 ) ;
if ( V_20 ) {
F_176 ( V_13 -> V_200 ) ;
F_53 ( V_13 ) ;
}
return V_20 ;
}
void F_177 ( struct V_129 * V_65 )
{
F_82 ( ! V_65 -> V_13 ) ;
F_132 ( V_65 ) ;
F_178 ( V_65 , & V_6 ) ;
F_176 ( V_65 -> V_13 -> V_200 ) ;
F_53 ( V_65 -> V_13 ) ;
}
void F_179 ( struct V_129 * V_65 )
{
struct V_12 * V_13 ;
int V_192 ;
V_13 = V_65 -> V_13 ;
F_82 ( ! V_13 ) ;
if ( F_147 ( V_65 ) ) {
V_13 -> V_18 = V_230 ;
V_13 -> V_225 = V_231 ;
} else {
V_13 -> V_18 = V_232 ;
V_13 -> V_225 = V_233 ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ )
V_13 -> V_203 [ V_192 ] . V_195 = V_234 ;
}
#ifndef F_151
V_13 -> V_18 = V_232 ;
#endif
V_13 -> V_211 = ! V_65 -> V_235 && ! V_65 -> V_236 ;
if ( ! V_13 -> V_211 )
F_180 ( V_65 ) ;
}
T_4 F_181 ( struct V_129 * V_65 , char * V_237 )
{
if ( ! V_65 -> V_13 )
return - V_158 ;
return sprintf ( V_237 , L_31 , F_182 ( V_65 -> V_13 -> V_18 ) ) ;
}
T_4 F_183 ( struct V_129 * V_65 ,
const char * V_237 , T_5 V_238 )
{
unsigned long V_147 ;
unsigned long V_239 ;
if ( ! V_65 -> V_13 )
return - V_158 ;
if ( F_184 ( V_237 , 10 , & V_147 ) )
return - V_158 ;
V_239 = F_185 ( V_147 ) ;
if ( V_239 == 0 || V_239 > V_240 )
return - V_158 ;
V_65 -> V_13 -> V_18 = V_239 ;
return V_238 ;
}
static int T_8 F_186 ( void )
{
V_135 = F_187 ( L_32 , V_241 , 0 ) ;
if ( ! V_135 )
F_188 ( L_33 ) ;
return F_189 ( & V_6 ) ;
}
