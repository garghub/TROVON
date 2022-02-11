static inline unsigned char F_1 ( unsigned char V_1 )
{
return V_1 & ~ V_2 ;
}
static int
F_2 ( struct V_3 * V_4 , unsigned long V_5 )
{
T_1 V_6 = F_3 ( V_4 -> type , V_5 ) ;
struct V_7 * V_7 ;
int V_8 = 0 ;
V_7 = F_4 ( F_5 ( V_6 ) , F_6 ( V_6 ) ) ;
if ( ! V_7 )
return 0 ;
if ( F_7 ( V_7 ) ) {
V_8 = F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
F_10 ( V_7 ) ;
return V_8 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
T_2 V_11 ;
T_2 V_12 ;
int V_13 = 0 ;
V_10 = & V_4 -> V_14 ;
V_11 = ( V_10 -> V_11 + 1 ) << ( V_15 - 9 ) ;
V_12 = ( ( T_2 ) V_10 -> V_16 - 1 ) << ( V_15 - 9 ) ;
if ( V_12 ) {
V_13 = F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_18 , 0 ) ;
if ( V_13 )
return V_13 ;
F_13 () ;
}
F_14 (se, &si->first_swap_extent.list, list) {
V_11 = V_10 -> V_11 << ( V_15 - 9 ) ;
V_12 = ( T_2 ) V_10 -> V_16 << ( V_15 - 9 ) ;
V_13 = F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_18 , 0 ) ;
if ( V_13 )
break;
F_13 () ;
}
return V_13 ;
}
static void F_15 ( struct V_3 * V_4 ,
T_3 V_19 , T_3 V_16 )
{
struct V_9 * V_10 = V_4 -> V_20 ;
int V_21 = 0 ;
while ( V_16 ) {
if ( V_10 -> V_19 <= V_19 &&
V_19 < V_10 -> V_19 + V_10 -> V_16 ) {
T_3 V_5 = V_19 - V_10 -> V_19 ;
T_2 V_11 = V_10 -> V_11 + V_5 ;
T_2 V_12 = V_10 -> V_16 - V_5 ;
if ( V_12 > V_16 )
V_12 = V_16 ;
V_19 += V_12 ;
V_16 -= V_12 ;
if ( ! V_21 ++ )
V_4 -> V_20 = V_10 ;
V_11 <<= V_15 - 9 ;
V_12 <<= V_15 - 9 ;
if ( F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_22 , 0 ) )
break;
}
V_10 = F_16 ( V_10 , V_23 ) ;
}
}
static inline void F_17 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
V_25 -> V_27 = V_26 ;
}
static inline unsigned int F_18 ( struct V_24 * V_25 )
{
return V_25 -> V_28 ;
}
static inline void F_19 ( struct V_24 * V_25 ,
unsigned int V_29 )
{
V_25 -> V_28 = V_29 ;
}
static inline void F_20 ( struct V_24 * V_25 ,
unsigned int V_29 , unsigned int V_30 )
{
V_25 -> V_27 = V_30 ;
V_25 -> V_28 = V_29 ;
}
static inline unsigned int F_21 ( struct V_24 * V_25 )
{
return V_25 -> V_28 ;
}
static inline void F_22 ( struct V_24 * V_25 ,
unsigned int V_31 )
{
V_25 -> V_28 = V_31 ;
}
static inline void F_23 ( struct V_24 * V_25 ,
unsigned int V_31 , unsigned int V_30 )
{
V_25 -> V_27 = V_30 ;
V_25 -> V_28 = V_31 ;
}
static inline bool F_24 ( struct V_24 * V_25 )
{
return V_25 -> V_27 & V_32 ;
}
static inline bool F_25 ( struct V_24 * V_25 )
{
return V_25 -> V_27 & V_33 ;
}
static inline void F_26 ( struct V_24 * V_25 )
{
V_25 -> V_27 = V_33 ;
V_25 -> V_28 = 0 ;
}
static inline bool F_27 ( struct V_24 * V_25 )
{
return V_25 -> V_27 & V_34 ;
}
static inline void F_28 ( struct V_24 * V_25 )
{
V_25 -> V_27 &= ~ V_34 ;
}
static inline struct V_24 * F_29 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_24 * V_35 ;
V_35 = V_4 -> V_36 ;
if ( V_35 ) {
V_35 += V_5 / V_37 ;
F_30 ( & V_35 -> V_38 ) ;
}
return V_35 ;
}
static inline void F_31 ( struct V_24 * V_35 )
{
if ( V_35 )
F_32 ( & V_35 -> V_38 ) ;
}
static inline struct V_24 * F_33 (
struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_24 * V_35 ;
V_35 = F_29 ( V_4 , V_5 ) ;
if ( ! V_35 )
F_30 ( & V_4 -> V_38 ) ;
return V_35 ;
}
static inline void F_34 ( struct V_3 * V_4 ,
struct V_24 * V_35 )
{
if ( V_35 )
F_31 ( V_35 ) ;
else
F_32 ( & V_4 -> V_38 ) ;
}
static inline bool F_35 ( struct V_39 * V_23 )
{
return F_25 ( & V_23 -> V_40 ) ;
}
static inline unsigned int F_36 ( struct V_39 * V_23 )
{
return F_21 ( & V_23 -> V_40 ) ;
}
static void F_37 ( struct V_39 * V_23 )
{
F_26 ( & V_23 -> V_40 ) ;
F_26 ( & V_23 -> V_41 ) ;
}
static void F_38 ( struct V_39 * V_23 ,
struct V_24 * V_35 ,
unsigned int V_42 )
{
if ( F_35 ( V_23 ) ) {
F_23 ( & V_23 -> V_40 , V_42 , 0 ) ;
F_23 ( & V_23 -> V_41 , V_42 , 0 ) ;
} else {
struct V_24 * V_43 ;
unsigned int V_41 = F_21 ( & V_23 -> V_41 ) ;
V_43 = V_35 + V_41 ;
F_39 ( & V_43 -> V_38 , V_44 ) ;
F_22 ( V_43 , V_42 ) ;
F_32 ( & V_43 -> V_38 ) ;
F_23 ( & V_23 -> V_41 , V_42 , 0 ) ;
}
}
static unsigned int F_40 ( struct V_39 * V_23 ,
struct V_24 * V_35 )
{
unsigned int V_42 ;
V_42 = F_21 ( & V_23 -> V_40 ) ;
if ( F_21 ( & V_23 -> V_41 ) == V_42 ) {
F_26 ( & V_23 -> V_40 ) ;
F_26 ( & V_23 -> V_41 ) ;
} else
F_23 ( & V_23 -> V_40 ,
F_21 ( & V_35 [ V_42 ] ) , 0 ) ;
return V_42 ;
}
static void F_41 ( struct V_3 * V_4 ,
unsigned int V_42 )
{
memset ( V_4 -> V_45 + V_42 * V_37 ,
V_46 , V_37 ) ;
F_38 ( & V_4 -> V_47 , V_4 -> V_36 , V_42 ) ;
F_42 ( & V_4 -> V_48 ) ;
}
static void F_43 ( struct V_3 * V_4 , unsigned long V_42 )
{
struct V_24 * V_35 = V_4 -> V_36 ;
F_17 ( V_35 + V_42 , V_32 ) ;
F_38 ( & V_4 -> V_49 , V_35 , V_42 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_24 * V_25 , * V_35 ;
unsigned int V_42 ;
V_25 = V_4 -> V_36 ;
while ( ! F_35 ( & V_4 -> V_47 ) ) {
V_42 = F_40 ( & V_4 -> V_47 , V_25 ) ;
F_32 ( & V_4 -> V_38 ) ;
F_15 ( V_4 , V_42 * V_37 ,
V_37 ) ;
F_30 ( & V_4 -> V_38 ) ;
V_35 = F_29 ( V_4 , V_42 * V_37 ) ;
F_43 ( V_4 , V_42 ) ;
memset ( V_4 -> V_45 + V_42 * V_37 ,
0 , V_37 ) ;
F_31 ( V_35 ) ;
}
}
static void F_45 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
V_4 = F_46 ( V_51 , struct V_3 , V_48 ) ;
F_30 ( & V_4 -> V_38 ) ;
F_44 ( V_4 ) ;
F_32 ( & V_4 -> V_38 ) ;
}
static void F_47 ( struct V_3 * V_4 , unsigned long V_42 )
{
struct V_24 * V_35 = V_4 -> V_36 ;
F_48 ( F_36 ( & V_4 -> V_49 ) != V_42 ) ;
F_40 ( & V_4 -> V_49 , V_35 ) ;
F_20 ( V_35 + V_42 , 0 , 0 ) ;
}
static void F_49 ( struct V_3 * V_4 , unsigned long V_42 )
{
struct V_24 * V_35 = V_4 -> V_36 + V_42 ;
F_48 ( F_18 ( V_35 ) != 0 ) ;
if ( ( V_4 -> V_27 & ( V_52 | V_53 ) ) ==
( V_52 | V_53 ) ) {
F_41 ( V_4 , V_42 ) ;
return;
}
F_43 ( V_4 , V_42 ) ;
}
static void F_50 ( struct V_3 * V_54 ,
struct V_24 * V_36 , unsigned long V_55 )
{
unsigned long V_42 = V_55 / V_37 ;
if ( ! V_36 )
return;
if ( F_24 ( & V_36 [ V_42 ] ) )
F_47 ( V_54 , V_42 ) ;
F_48 ( F_18 ( & V_36 [ V_42 ] ) >= V_37 ) ;
F_19 ( & V_36 [ V_42 ] ,
F_18 ( & V_36 [ V_42 ] ) + 1 ) ;
}
static void F_51 ( struct V_3 * V_54 ,
struct V_24 * V_36 , unsigned long V_55 )
{
unsigned long V_42 = V_55 / V_37 ;
if ( ! V_36 )
return;
F_48 ( F_18 ( & V_36 [ V_42 ] ) == 0 ) ;
F_19 ( & V_36 [ V_42 ] ,
F_18 ( & V_36 [ V_42 ] ) - 1 ) ;
if ( F_18 ( & V_36 [ V_42 ] ) == 0 )
F_49 ( V_54 , V_42 ) ;
}
static bool
F_52 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_56 * V_56 ;
bool V_57 ;
V_5 /= V_37 ;
V_57 = ! F_35 ( & V_4 -> V_49 ) &&
V_5 != F_36 ( & V_4 -> V_49 ) &&
F_24 ( & V_4 -> V_36 [ V_5 ] ) ;
if ( ! V_57 )
return false ;
V_56 = F_53 ( V_4 -> V_56 ) ;
F_26 ( & V_56 -> V_58 ) ;
return true ;
}
static bool F_54 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_59 )
{
struct V_56 * V_60 ;
struct V_24 * V_35 ;
bool V_61 ;
unsigned long V_62 , V_63 ;
V_64:
V_60 = F_53 ( V_4 -> V_56 ) ;
if ( F_25 ( & V_60 -> V_58 ) ) {
if ( ! F_35 ( & V_4 -> V_49 ) ) {
V_60 -> V_58 = V_4 -> V_49 . V_40 ;
V_60 -> V_65 = F_21 ( & V_60 -> V_58 ) *
V_37 ;
} else if ( ! F_35 ( & V_4 -> V_47 ) ) {
F_44 ( V_4 ) ;
* V_59 = * V_5 = V_4 -> F_21 ;
goto V_64;
} else
return false ;
}
V_61 = false ;
V_62 = V_60 -> V_65 ;
V_63 = F_55 (unsigned long, si->max,
(cluster_next(&cluster->index) + 1) * SWAPFILE_CLUSTER) ;
if ( V_62 >= V_63 ) {
F_26 ( & V_60 -> V_58 ) ;
goto V_64;
}
V_35 = F_29 ( V_4 , V_62 ) ;
while ( V_62 < V_63 ) {
if ( ! V_4 -> V_45 [ V_62 ] ) {
V_61 = true ;
break;
}
V_62 ++ ;
}
F_31 ( V_35 ) ;
if ( ! V_61 ) {
F_26 ( & V_60 -> V_58 ) ;
goto V_64;
}
V_60 -> V_65 = V_62 + 1 ;
* V_5 = V_62 ;
* V_59 = V_62 ;
return V_61 ;
}
static void F_56 ( struct V_3 * V_54 )
{
int V_66 ;
F_57 (nid)
F_58 ( & V_54 -> V_67 [ V_66 ] , & V_68 [ V_66 ] ) ;
}
static void F_59 ( struct V_3 * V_54 )
{
F_30 ( & V_69 ) ;
F_56 ( V_54 ) ;
F_32 ( & V_69 ) ;
}
static void F_60 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned int V_70 )
{
unsigned int V_71 = V_5 + V_70 - 1 ;
if ( V_5 == V_4 -> V_72 )
V_4 -> V_72 += V_70 ;
if ( V_71 == V_4 -> V_73 )
V_4 -> V_73 -= V_70 ;
V_4 -> V_74 += V_70 ;
if ( V_4 -> V_74 == V_4 -> V_75 ) {
V_4 -> V_72 = V_4 -> V_63 ;
V_4 -> V_73 = 0 ;
F_59 ( V_4 ) ;
}
}
static void F_61 ( struct V_3 * V_54 )
{
int V_66 ;
F_30 ( & V_69 ) ;
F_57 (nid) {
F_62 ( ! F_63 ( & V_54 -> V_67 [ V_66 ] ) ) ;
F_64 ( & V_54 -> V_67 [ V_66 ] , & V_68 [ V_66 ] ) ;
}
F_32 ( & V_69 ) ;
}
static void F_65 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned int V_70 )
{
unsigned long V_71 = V_5 + V_70 - 1 ;
void (* F_66)( struct V_76 * , unsigned long );
if ( V_5 < V_4 -> V_72 )
V_4 -> V_72 = V_5 ;
if ( V_71 > V_4 -> V_73 ) {
bool V_77 = ! V_4 -> V_73 ;
V_4 -> V_73 = V_71 ;
if ( V_77 && ( V_4 -> V_27 & V_52 ) )
F_61 ( V_4 ) ;
}
F_67 ( V_70 , & V_78 ) ;
V_4 -> V_74 -= V_70 ;
if ( V_4 -> V_27 & V_79 )
F_66 =
V_4 -> V_17 -> V_80 -> V_81 -> F_66 ;
else
F_66 = NULL ;
while ( V_5 <= V_71 ) {
F_68 ( V_4 -> type , V_5 ) ;
if ( F_66 )
F_66 ( V_4 -> V_17 , V_5 ) ;
V_5 ++ ;
}
}
static int F_69 ( struct V_3 * V_4 ,
unsigned char V_82 , int V_83 ,
T_1 V_84 [] )
{
struct V_24 * V_35 ;
unsigned long V_5 ;
unsigned long V_59 ;
unsigned long V_85 = 0 ;
int V_86 = V_87 ;
int V_88 = 0 ;
if ( V_83 > V_89 )
V_83 = V_89 ;
V_4 -> V_27 += V_90 ;
V_59 = V_5 = V_4 -> F_21 ;
if ( V_4 -> V_36 ) {
if ( F_54 ( V_4 , & V_5 , & V_59 ) )
goto V_91;
else
goto V_92;
}
if ( F_70 ( ! V_4 -> V_93 -- ) ) {
if ( V_4 -> V_75 - V_4 -> V_74 < V_37 ) {
V_4 -> V_93 = V_37 - 1 ;
goto V_91;
}
F_32 ( & V_4 -> V_38 ) ;
V_59 = V_5 = V_4 -> V_72 ;
V_85 = V_5 + V_37 - 1 ;
for (; V_85 <= V_4 -> V_73 ; V_5 ++ ) {
if ( V_4 -> V_45 [ V_5 ] )
V_85 = V_5 + V_37 ;
else if ( V_5 == V_85 ) {
F_30 ( & V_4 -> V_38 ) ;
V_5 -= V_37 - 1 ;
V_4 -> F_21 = V_5 ;
V_4 -> V_93 = V_37 - 1 ;
goto V_91;
}
if ( F_70 ( -- V_86 < 0 ) ) {
F_13 () ;
V_86 = V_87 ;
}
}
V_5 = V_59 ;
F_30 ( & V_4 -> V_38 ) ;
V_4 -> V_93 = V_37 - 1 ;
}
V_91:
if ( V_4 -> V_36 ) {
while ( F_52 ( V_4 , V_5 ) ) {
if ( V_88 )
goto V_94;
if ( ! F_54 ( V_4 , & V_5 ,
& V_59 ) )
goto V_92;
}
}
if ( ! ( V_4 -> V_27 & V_52 ) )
goto V_95;
if ( ! V_4 -> V_73 )
goto V_95;
if ( V_5 > V_4 -> V_73 )
V_59 = V_5 = V_4 -> V_72 ;
V_35 = F_29 ( V_4 , V_5 ) ;
if ( F_71 () && V_4 -> V_45 [ V_5 ] == V_2 ) {
int V_96 ;
F_31 ( V_35 ) ;
F_32 ( & V_4 -> V_38 ) ;
V_96 = F_2 ( V_4 , V_5 ) ;
F_30 ( & V_4 -> V_38 ) ;
if ( V_96 )
goto V_91;
goto V_92;
}
if ( V_4 -> V_45 [ V_5 ] ) {
F_31 ( V_35 ) ;
if ( ! V_88 )
goto V_92;
else
goto V_94;
}
V_4 -> V_45 [ V_5 ] = V_82 ;
F_50 ( V_4 , V_4 -> V_36 , V_5 ) ;
F_31 ( V_35 ) ;
F_60 ( V_4 , V_5 , 1 ) ;
V_4 -> F_21 = V_5 + 1 ;
V_84 [ V_88 ++ ] = F_3 ( V_4 -> type , V_5 ) ;
if ( ( V_88 == V_83 ) || ( V_5 >= V_4 -> V_73 ) )
goto V_94;
if ( F_70 ( -- V_86 < 0 ) ) {
if ( V_88 )
goto V_94;
F_32 ( & V_4 -> V_38 ) ;
F_13 () ;
F_30 ( & V_4 -> V_38 ) ;
V_86 = V_87 ;
}
if ( V_4 -> V_36 ) {
if ( F_54 ( V_4 , & V_5 , & V_59 ) )
goto V_91;
else
goto V_94;
}
++ V_5 ;
if ( V_4 -> V_93 && ! V_4 -> V_45 [ V_5 ] ) {
-- V_4 -> V_93 ;
goto V_91;
}
V_94:
V_4 -> V_27 -= V_90 ;
return V_88 ;
V_92:
F_32 ( & V_4 -> V_38 ) ;
while ( ++ V_5 <= V_4 -> V_73 ) {
if ( ! V_4 -> V_45 [ V_5 ] ) {
F_30 ( & V_4 -> V_38 ) ;
goto V_91;
}
if ( F_71 () && V_4 -> V_45 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_38 ) ;
goto V_91;
}
if ( F_70 ( -- V_86 < 0 ) ) {
F_13 () ;
V_86 = V_87 ;
}
}
V_5 = V_4 -> V_72 ;
while ( V_5 < V_59 ) {
if ( ! V_4 -> V_45 [ V_5 ] ) {
F_30 ( & V_4 -> V_38 ) ;
goto V_91;
}
if ( F_71 () && V_4 -> V_45 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_38 ) ;
goto V_91;
}
if ( F_70 ( -- V_86 < 0 ) ) {
F_13 () ;
V_86 = V_87 ;
}
V_5 ++ ;
}
F_30 ( & V_4 -> V_38 ) ;
V_95:
V_4 -> V_27 -= V_90 ;
return V_88 ;
}
static int F_72 ( struct V_3 * V_4 , T_1 * V_97 )
{
unsigned long V_42 ;
struct V_24 * V_35 ;
unsigned long V_5 , V_98 ;
unsigned char * V_99 ;
if ( F_35 ( & V_4 -> V_49 ) )
return 0 ;
V_42 = F_36 ( & V_4 -> V_49 ) ;
V_5 = V_42 * V_37 ;
V_35 = F_29 ( V_4 , V_5 ) ;
F_47 ( V_4 , V_42 ) ;
F_20 ( V_35 , V_37 , V_34 ) ;
V_99 = V_4 -> V_45 + V_5 ;
for ( V_98 = 0 ; V_98 < V_37 ; V_98 ++ )
V_99 [ V_98 ] = V_2 ;
F_31 ( V_35 ) ;
F_60 ( V_4 , V_5 , V_37 ) ;
* V_97 = F_3 ( V_4 -> type , V_5 ) ;
return 1 ;
}
static void F_73 ( struct V_3 * V_4 , unsigned long V_42 )
{
unsigned long V_5 = V_42 * V_37 ;
struct V_24 * V_35 ;
V_35 = F_29 ( V_4 , V_5 ) ;
F_20 ( V_35 , 0 , 0 ) ;
F_49 ( V_4 , V_42 ) ;
F_31 ( V_35 ) ;
F_65 ( V_4 , V_5 , V_37 ) ;
}
static int F_72 ( struct V_3 * V_4 , T_1 * V_97 )
{
F_74 ( 1 ) ;
return 0 ;
}
static unsigned long F_75 ( struct V_3 * V_4 ,
unsigned char V_82 )
{
T_1 V_6 ;
int V_88 ;
V_88 = F_69 ( V_4 , V_82 , 1 , & V_6 ) ;
if ( V_88 )
return F_6 ( V_6 ) ;
else
return 0 ;
}
int F_76 ( int V_100 , bool V_60 , T_1 V_101 [] )
{
unsigned long V_16 = V_60 ? V_37 : 1 ;
struct V_3 * V_4 , * V_65 ;
long V_102 ;
int V_88 = 0 ;
int V_103 ;
F_77 ( V_100 > 1 && V_60 ) ;
V_102 = F_78 ( & V_78 ) / V_16 ;
if ( V_102 <= 0 )
goto V_104;
if ( V_100 > V_89 )
V_100 = V_89 ;
if ( V_100 > V_102 )
V_100 = V_102 ;
F_79 ( V_100 * V_16 , & V_78 ) ;
F_30 ( & V_69 ) ;
V_105:
V_103 = F_80 () ;
F_81 (si, next, &swap_avail_heads[node], avail_lists[node]) {
F_82 ( & V_4 -> V_67 [ V_103 ] , & V_68 [ V_103 ] ) ;
F_32 ( & V_69 ) ;
F_30 ( & V_4 -> V_38 ) ;
if ( ! V_4 -> V_73 || ! ( V_4 -> V_27 & V_52 ) ) {
F_30 ( & V_69 ) ;
if ( F_63 ( & V_4 -> V_67 [ V_103 ] ) ) {
F_32 ( & V_4 -> V_38 ) ;
goto V_106;
}
F_83 ( ! V_4 -> V_73 ,
L_1 ,
V_4 -> type ) ;
F_83 ( ! ( V_4 -> V_27 & V_52 ) ,
L_2 ,
V_4 -> type ) ;
F_56 ( V_4 ) ;
F_32 ( & V_4 -> V_38 ) ;
goto V_106;
}
if ( V_60 ) {
if ( ! ( V_4 -> V_27 & V_107 ) )
V_88 = F_72 ( V_4 , V_101 ) ;
} else
V_88 = F_69 ( V_4 , V_2 ,
V_100 , V_101 ) ;
F_32 ( & V_4 -> V_38 ) ;
if ( V_88 || V_60 )
goto V_108;
F_84 ( L_3 ,
V_4 -> type ) ;
F_30 ( & V_69 ) ;
V_106:
if ( F_63 ( & V_65 -> V_67 [ V_103 ] ) )
goto V_105;
}
F_32 ( & V_69 ) ;
V_108:
if ( V_88 < V_100 )
F_67 ( ( long ) ( V_100 - V_88 ) * V_16 ,
& V_78 ) ;
V_104:
return V_88 ;
}
T_1 F_85 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_109 [ type ] ;
F_30 ( & V_4 -> V_38 ) ;
if ( V_4 && ( V_4 -> V_27 & V_52 ) ) {
F_86 ( & V_78 ) ;
V_5 = F_75 ( V_4 , 1 ) ;
if ( V_5 ) {
F_32 ( & V_4 -> V_38 ) ;
return F_3 ( type , V_5 ) ;
}
F_87 ( & V_78 ) ;
}
F_32 ( & V_4 -> V_38 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_88 ( T_1 V_6 )
{
struct V_3 * V_54 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_110 )
goto V_111;
type = F_89 ( V_6 ) ;
if ( type >= V_112 )
goto V_113;
V_54 = V_109 [ type ] ;
if ( ! ( V_54 -> V_27 & V_114 ) )
goto V_115;
V_5 = F_6 ( V_6 ) ;
if ( V_5 >= V_54 -> V_63 )
goto V_116;
return V_54 ;
V_116:
F_90 ( L_4 , V_117 , V_6 . V_110 ) ;
goto V_111;
V_115:
F_90 ( L_4 , V_118 , V_6 . V_110 ) ;
goto V_111;
V_113:
F_90 ( L_4 , V_119 , V_6 . V_110 ) ;
V_111:
return NULL ;
}
static struct V_3 * F_91 ( T_1 V_6 )
{
struct V_3 * V_54 ;
V_54 = F_88 ( V_6 ) ;
if ( ! V_54 )
goto V_111;
if ( ! V_54 -> V_45 [ F_6 ( V_6 ) ] )
goto V_120;
return V_54 ;
V_120:
F_90 ( L_4 , V_121 , V_6 . V_110 ) ;
goto V_111;
V_111:
return NULL ;
}
static struct V_3 * F_92 ( T_1 V_6 )
{
struct V_3 * V_54 ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 )
F_30 ( & V_54 -> V_38 ) ;
return V_54 ;
}
static struct V_3 * F_93 ( T_1 V_6 ,
struct V_3 * V_122 )
{
struct V_3 * V_54 ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 != V_122 ) {
if ( V_122 != NULL )
F_32 ( & V_122 -> V_38 ) ;
if ( V_54 != NULL )
F_30 ( & V_54 -> V_38 ) ;
}
return V_54 ;
}
static unsigned char F_94 ( struct V_3 * V_54 ,
T_1 V_6 , unsigned char V_82 )
{
struct V_24 * V_35 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_123 ;
unsigned char V_124 ;
V_35 = F_33 ( V_54 , V_5 ) ;
V_123 = V_54 -> V_45 [ V_5 ] ;
V_124 = V_123 & V_2 ;
V_123 &= ~ V_2 ;
if ( V_82 == V_2 ) {
F_48 ( ! V_124 ) ;
V_124 = 0 ;
} else if ( V_123 == V_125 ) {
V_123 = 0 ;
} else if ( ( V_123 & ~ V_126 ) <= V_127 ) {
if ( V_123 == V_126 ) {
if ( F_95 ( V_54 , V_5 , V_123 ) )
V_123 = V_127 | V_126 ;
else
V_123 = V_127 ;
} else
V_123 -- ;
}
V_82 = V_123 | V_124 ;
V_54 -> V_45 [ V_5 ] = V_82 ? : V_2 ;
F_34 ( V_54 , V_35 ) ;
return V_82 ;
}
static void F_96 ( struct V_3 * V_54 , T_1 V_6 )
{
struct V_24 * V_35 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_123 ;
V_35 = F_29 ( V_54 , V_5 ) ;
V_123 = V_54 -> V_45 [ V_5 ] ;
F_48 ( V_123 != V_2 ) ;
V_54 -> V_45 [ V_5 ] = 0 ;
F_51 ( V_54 , V_54 -> V_36 , V_5 ) ;
F_31 ( V_35 ) ;
F_97 ( V_6 , 1 ) ;
F_65 ( V_54 , V_5 , 1 ) ;
}
void F_98 ( T_1 V_6 )
{
struct V_3 * V_54 ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 ) {
if ( ! F_94 ( V_54 , V_6 , 1 ) )
F_99 ( V_6 ) ;
}
}
static void F_100 ( T_1 V_6 )
{
struct V_3 * V_54 ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 ) {
if ( ! F_94 ( V_54 , V_6 , V_2 ) )
F_99 ( V_6 ) ;
}
}
static void F_101 ( T_1 V_6 )
{
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned long V_42 = V_5 / V_37 ;
struct V_24 * V_35 ;
struct V_3 * V_4 ;
unsigned char * V_99 ;
unsigned int V_98 , V_128 = 0 ;
unsigned char V_110 ;
V_4 = F_91 ( V_6 ) ;
if ( ! V_4 )
return;
V_35 = F_29 ( V_4 , V_5 ) ;
F_48 ( ! F_27 ( V_35 ) ) ;
V_99 = V_4 -> V_45 + V_5 ;
for ( V_98 = 0 ; V_98 < V_37 ; V_98 ++ ) {
V_110 = V_99 [ V_98 ] ;
F_48 ( ! ( V_110 & V_2 ) ) ;
if ( V_110 == V_2 )
V_128 ++ ;
}
if ( ! V_128 ) {
for ( V_98 = 0 ; V_98 < V_37 ; V_98 ++ )
V_99 [ V_98 ] &= ~ V_2 ;
}
F_28 ( V_35 ) ;
F_31 ( V_35 ) ;
if ( V_128 == V_37 ) {
F_30 ( & V_4 -> V_38 ) ;
V_35 = F_29 ( V_4 , V_5 ) ;
memset ( V_99 , 0 , V_37 ) ;
F_31 ( V_35 ) ;
F_97 ( V_6 , V_37 ) ;
F_73 ( V_4 , V_42 ) ;
F_32 ( & V_4 -> V_38 ) ;
} else if ( V_128 ) {
for ( V_98 = 0 ; V_98 < V_37 ; V_98 ++ , V_6 . V_110 ++ ) {
if ( ! F_94 ( V_4 , V_6 , V_2 ) )
F_99 ( V_6 ) ;
}
}
}
int F_102 ( T_1 V_6 )
{
struct V_3 * V_4 ;
struct V_24 * V_35 ;
unsigned long V_5 = F_6 ( V_6 ) ;
V_4 = F_91 ( V_6 ) ;
if ( ! V_4 )
return - V_129 ;
V_35 = F_29 ( V_4 , V_5 ) ;
F_28 ( V_35 ) ;
F_31 ( V_35 ) ;
return 0 ;
}
static inline void F_101 ( T_1 V_6 )
{
}
void F_103 ( struct V_7 * V_7 , T_1 V_6 )
{
if ( ! F_104 ( V_7 ) )
F_100 ( V_6 ) ;
else
F_101 ( V_6 ) ;
}
static int F_105 ( const void * V_130 , const void * V_131 )
{
const T_1 * V_132 = V_130 , * V_133 = V_131 ;
return ( int ) F_89 ( * V_132 ) - ( int ) F_89 ( * V_133 ) ;
}
void F_106 ( T_1 * V_134 , int V_31 )
{
struct V_3 * V_54 , * V_135 ;
int V_98 ;
if ( V_31 <= 0 )
return;
V_135 = NULL ;
V_54 = NULL ;
if ( V_112 > 1 )
F_107 ( V_134 , V_31 , sizeof( V_134 [ 0 ] ) , F_105 , NULL ) ;
for ( V_98 = 0 ; V_98 < V_31 ; ++ V_98 ) {
V_54 = F_93 ( V_134 [ V_98 ] , V_135 ) ;
if ( V_54 )
F_96 ( V_54 , V_134 [ V_98 ] ) ;
V_135 = V_54 ;
}
if ( V_54 )
F_32 ( & V_54 -> V_38 ) ;
}
int F_108 ( struct V_7 * V_7 )
{
int V_123 = 0 ;
struct V_3 * V_54 ;
struct V_24 * V_35 ;
T_1 V_6 ;
unsigned long V_5 ;
V_6 . V_110 = F_109 ( V_7 ) ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 ) {
V_5 = F_6 ( V_6 ) ;
V_35 = F_33 ( V_54 , V_5 ) ;
V_123 = F_1 ( V_54 -> V_45 [ V_5 ] ) ;
F_34 ( V_54 , V_35 ) ;
}
return V_123 ;
}
static int F_110 ( struct V_3 * V_4 , T_1 V_6 )
{
int V_123 = 0 ;
T_3 V_5 = F_6 ( V_6 ) ;
struct V_24 * V_35 ;
V_35 = F_33 ( V_4 , V_5 ) ;
V_123 = F_1 ( V_4 -> V_45 [ V_5 ] ) ;
F_34 ( V_4 , V_35 ) ;
return V_123 ;
}
int F_111 ( T_1 V_6 )
{
int V_123 = 0 ;
struct V_3 * V_4 ;
V_4 = F_88 ( V_6 ) ;
if ( V_4 )
V_123 = F_110 ( V_4 , V_6 ) ;
return V_123 ;
}
int F_112 ( T_1 V_6 )
{
int V_123 , V_136 , V_31 ;
struct V_3 * V_54 ;
struct V_24 * V_35 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_99 ;
V_54 = F_91 ( V_6 ) ;
if ( ! V_54 )
return 0 ;
V_5 = F_6 ( V_6 ) ;
V_35 = F_33 ( V_54 , V_5 ) ;
V_123 = F_1 ( V_54 -> V_45 [ V_5 ] ) ;
if ( ! ( V_123 & V_126 ) )
goto V_111;
V_123 &= ~ V_126 ;
V_31 = V_127 + 1 ;
V_7 = F_113 ( V_54 -> V_45 + V_5 ) ;
V_5 &= ~ V_137 ;
F_48 ( F_109 ( V_7 ) != V_138 ) ;
do {
V_7 = F_16 ( V_7 , V_139 ) ;
V_99 = F_114 ( V_7 ) ;
V_136 = V_99 [ V_5 ] ;
F_115 ( V_99 ) ;
V_123 += ( V_136 & ~ V_126 ) * V_31 ;
V_31 *= ( V_140 + 1 ) ;
} while ( V_136 & V_126 );
V_111:
F_34 ( V_54 , V_35 ) ;
return V_123 ;
}
static bool F_116 ( struct V_3 * V_4 ,
T_1 V_6 )
{
struct V_24 * V_35 ;
unsigned char * V_99 = V_4 -> V_45 ;
unsigned long V_141 = F_6 ( V_6 ) ;
unsigned long V_5 = F_117 ( V_141 , V_37 ) ;
int V_98 ;
bool V_8 = false ;
V_35 = F_33 ( V_4 , V_5 ) ;
if ( ! V_35 || ! F_27 ( V_35 ) ) {
if ( V_99 [ V_141 ] != V_2 )
V_8 = true ;
goto V_142;
}
for ( V_98 = 0 ; V_98 < V_37 ; V_98 ++ ) {
if ( V_99 [ V_5 + V_98 ] != V_2 ) {
V_8 = true ;
break;
}
}
V_142:
F_34 ( V_4 , V_35 ) ;
return V_8 ;
}
static bool F_118 ( struct V_7 * V_7 )
{
T_1 V_6 ;
struct V_3 * V_4 ;
if ( F_119 ( ! F_120 ( V_7 ) ) )
return F_108 ( V_7 ) != 0 ;
V_7 = F_121 ( V_7 ) ;
V_6 . V_110 = F_109 ( V_7 ) ;
V_4 = F_91 ( V_6 ) ;
if ( V_4 )
return F_116 ( V_4 , V_6 ) ;
return false ;
}
static int F_122 ( struct V_7 * V_7 , int * V_143 ,
int * V_144 )
{
int V_98 , V_145 , V_146 , V_147 ;
unsigned long V_5 = 0 ;
struct V_3 * V_4 ;
struct V_24 * V_35 = NULL ;
unsigned char * V_99 = NULL ;
int V_148 , V_149 = 0 ;
F_123 ( F_124 ( V_7 ) , V_7 ) ;
if ( F_119 ( ! F_120 ( V_7 ) ) ) {
V_148 = F_125 ( & V_7 -> V_150 ) + 1 ;
if ( V_143 )
* V_143 = V_148 ;
if ( F_126 ( V_7 ) )
V_149 = F_108 ( V_7 ) ;
if ( V_144 )
* V_144 = V_149 ;
return V_148 + V_149 ;
}
V_7 = F_121 ( V_7 ) ;
V_146 = V_147 = V_145 = 0 ;
if ( F_126 ( V_7 ) ) {
T_1 V_6 ;
V_6 . V_110 = F_109 ( V_7 ) ;
V_4 = F_91 ( V_6 ) ;
if ( V_4 ) {
V_99 = V_4 -> V_45 ;
V_5 = F_6 ( V_6 ) ;
}
}
if ( V_99 )
V_35 = F_29 ( V_4 , V_5 ) ;
for ( V_98 = 0 ; V_98 < V_151 ; V_98 ++ ) {
V_148 = F_125 ( & V_7 [ V_98 ] . V_150 ) + 1 ;
V_146 += V_148 ;
if ( V_99 ) {
V_149 = F_1 ( V_99 [ V_5 + V_98 ] ) ;
V_147 += V_149 ;
}
V_145 = V_63 ( V_145 , V_148 + V_149 ) ;
}
F_31 ( V_35 ) ;
if ( F_127 ( V_7 ) ) {
V_145 -= 1 ;
V_146 -= V_151 ;
}
V_148 = F_128 ( V_7 ) ;
V_145 += V_148 ;
V_146 += V_148 ;
if ( V_143 )
* V_143 = V_146 ;
if ( V_144 )
* V_144 = V_147 ;
return V_145 ;
}
static int F_122 ( struct V_7 * V_7 , int * V_143 ,
int * V_144 )
{
int V_148 , V_149 = 0 ;
F_123 ( F_124 ( V_7 ) , V_7 ) ;
V_148 = F_129 ( V_7 , V_143 ) ;
if ( F_126 ( V_7 ) )
V_149 = F_108 ( V_7 ) ;
if ( V_144 )
* V_144 = V_149 ;
return V_148 + V_149 ;
}
bool F_130 ( struct V_7 * V_7 , int * V_152 )
{
int V_123 , V_143 , V_144 ;
F_123 ( ! F_131 ( V_7 ) , V_7 ) ;
if ( F_70 ( F_132 ( V_7 ) ) )
return false ;
V_123 = F_122 ( V_7 , & V_143 ,
& V_144 ) ;
if ( V_152 )
* V_152 = V_143 + V_144 ;
if ( V_123 == 1 && F_126 ( V_7 ) &&
( F_119 ( ! F_120 ( V_7 ) ) ||
V_144 == F_108 ( V_7 ) ) ) {
if ( ! F_133 ( V_7 ) ) {
V_7 = F_121 ( V_7 ) ;
F_134 ( V_7 ) ;
F_135 ( V_7 ) ;
} else {
T_1 V_6 ;
struct V_3 * V_54 ;
V_6 . V_110 = F_109 ( V_7 ) ;
V_54 = F_92 ( V_6 ) ;
if ( V_54 -> V_27 & V_153 ) {
F_32 ( & V_54 -> V_38 ) ;
return false ;
}
F_32 ( & V_54 -> V_38 ) ;
}
}
return V_123 <= 1 ;
}
int F_8 ( struct V_7 * V_7 )
{
F_123 ( ! F_131 ( V_7 ) , V_7 ) ;
if ( ! F_126 ( V_7 ) )
return 0 ;
if ( F_133 ( V_7 ) )
return 0 ;
if ( F_118 ( V_7 ) )
return 0 ;
if ( F_136 () )
return 0 ;
V_7 = F_121 ( V_7 ) ;
F_134 ( V_7 ) ;
F_135 ( V_7 ) ;
return 1 ;
}
int F_137 ( T_1 V_6 )
{
struct V_3 * V_54 ;
struct V_7 * V_7 = NULL ;
unsigned char V_123 ;
if ( F_138 ( V_6 ) )
return 1 ;
V_54 = F_91 ( V_6 ) ;
if ( V_54 ) {
V_123 = F_94 ( V_54 , V_6 , 1 ) ;
if ( V_123 == V_2 &&
! F_116 ( V_54 , V_6 ) ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
F_6 ( V_6 ) ) ;
if ( V_7 && ! F_7 ( V_7 ) ) {
F_10 ( V_7 ) ;
V_7 = NULL ;
}
} else if ( ! V_123 )
F_99 ( V_6 ) ;
}
if ( V_7 ) {
if ( F_126 ( V_7 ) && ! F_133 ( V_7 ) &&
( ! F_139 ( V_7 ) || F_140 ( V_7 ) ) &&
! F_116 ( V_54 , V_6 ) ) {
V_7 = F_121 ( V_7 ) ;
F_134 ( V_7 ) ;
F_135 ( V_7 ) ;
}
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_54 != NULL ;
}
int F_141 ( T_4 V_154 , T_2 V_5 , struct V_76 * * V_155 )
{
struct V_76 * V_17 = NULL ;
int type ;
if ( V_154 )
V_17 = F_142 ( V_154 ) ;
F_30 ( & V_156 ) ;
for ( type = 0 ; type < V_112 ; type ++ ) {
struct V_3 * V_157 = V_109 [ type ] ;
if ( ! ( V_157 -> V_27 & V_52 ) )
continue;
if ( ! V_17 ) {
if ( V_155 )
* V_155 = F_143 ( V_157 -> V_17 ) ;
F_32 ( & V_156 ) ;
return type ;
}
if ( V_17 == V_157 -> V_17 ) {
struct V_9 * V_10 = & V_157 -> V_14 ;
if ( V_10 -> V_11 == V_5 ) {
if ( V_155 )
* V_155 = F_143 ( V_157 -> V_17 ) ;
F_32 ( & V_156 ) ;
F_144 ( V_17 ) ;
return type ;
}
}
}
F_32 ( & V_156 ) ;
if ( V_17 )
F_144 ( V_17 ) ;
return - V_158 ;
}
T_2 F_145 ( int type , T_3 V_5 )
{
struct V_76 * V_17 ;
if ( ( unsigned int ) type >= V_112 )
return 0 ;
if ( ! ( V_109 [ type ] -> V_27 & V_52 ) )
return 0 ;
return F_146 ( F_3 ( type , V_5 ) , & V_17 ) ;
}
unsigned int F_147 ( int type , int free )
{
unsigned int V_31 = 0 ;
F_30 ( & V_156 ) ;
if ( ( unsigned int ) type < V_112 ) {
struct V_3 * V_157 = V_109 [ type ] ;
F_30 ( & V_157 -> V_38 ) ;
if ( V_157 -> V_27 & V_52 ) {
V_31 = V_157 -> V_75 ;
if ( free )
V_31 -= V_157 -> V_74 ;
}
F_32 ( & V_157 -> V_38 ) ;
}
F_32 ( & V_156 ) ;
return V_31 ;
}
static inline int F_148 ( T_5 V_159 , T_5 V_160 )
{
return F_149 ( F_150 ( V_159 ) , V_160 ) ;
}
static int F_151 ( struct V_161 * V_162 , T_6 * V_163 ,
unsigned long V_164 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_165 ;
struct V_166 * V_167 ;
T_7 * V_168 ;
T_5 * V_159 ;
int V_8 = 1 ;
V_165 = V_7 ;
V_7 = F_152 ( V_7 , V_162 , V_164 ) ;
if ( F_70 ( ! V_7 ) )
return - V_169 ;
if ( F_153 ( V_7 , V_162 -> V_170 , V_18 ,
& V_167 , false ) ) {
V_8 = - V_169 ;
goto V_171;
}
V_159 = F_154 ( V_162 -> V_170 , V_163 , V_164 , & V_168 ) ;
if ( F_70 ( ! F_148 ( * V_159 , F_155 ( V_6 ) ) ) ) {
F_156 ( V_7 , V_167 , false ) ;
V_8 = 0 ;
goto V_111;
}
F_157 ( V_162 -> V_170 , V_172 ) ;
F_158 ( V_162 -> V_170 , V_173 ) ;
F_159 ( V_7 ) ;
F_160 ( V_162 -> V_170 , V_164 , V_159 ,
F_161 ( F_162 ( V_7 , V_162 -> V_174 ) ) ) ;
if ( V_7 == V_165 ) {
F_163 ( V_7 , V_162 , V_164 , false ) ;
F_164 ( V_7 , V_167 , true , false ) ;
} else {
F_165 ( V_7 , V_162 , V_164 , false ) ;
F_164 ( V_7 , V_167 , false , false ) ;
F_166 ( V_7 , V_162 ) ;
}
F_98 ( V_6 ) ;
F_167 ( V_7 ) ;
V_111:
F_168 ( V_159 , V_168 ) ;
V_171:
if ( V_7 != V_165 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_8 ;
}
static int F_169 ( struct V_161 * V_162 , T_6 * V_163 ,
unsigned long V_164 , unsigned long V_71 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_160 = F_155 ( V_6 ) ;
T_5 * V_159 ;
int V_8 = 0 ;
V_159 = F_170 ( V_163 , V_164 ) ;
do {
if ( F_70 ( F_148 ( * V_159 , V_160 ) ) ) {
F_171 ( V_159 ) ;
V_8 = F_151 ( V_162 , V_163 , V_164 , V_6 , V_7 ) ;
if ( V_8 )
goto V_111;
V_159 = F_170 ( V_163 , V_164 ) ;
}
} while ( V_159 ++ , V_164 += V_175 , V_164 != V_71 );
F_171 ( V_159 - 1 ) ;
V_111:
return V_8 ;
}
static inline int F_172 ( struct V_161 * V_162 , T_8 * V_176 ,
unsigned long V_164 , unsigned long V_71 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_163 ;
unsigned long V_65 ;
int V_8 ;
V_163 = F_173 ( V_176 , V_164 ) ;
do {
F_13 () ;
V_65 = F_174 ( V_164 , V_71 ) ;
if ( F_175 ( V_163 ) )
continue;
V_8 = F_169 ( V_162 , V_163 , V_164 , V_65 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_163 ++ , V_164 = V_65 , V_164 != V_71 );
return 0 ;
}
static inline int F_176 ( struct V_161 * V_162 , T_9 * V_177 ,
unsigned long V_164 , unsigned long V_71 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_176 ;
unsigned long V_65 ;
int V_8 ;
V_176 = F_177 ( V_177 , V_164 ) ;
do {
V_65 = F_178 ( V_164 , V_71 ) ;
if ( F_179 ( V_176 ) )
continue;
V_8 = F_172 ( V_162 , V_176 , V_164 , V_65 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_176 ++ , V_164 = V_65 , V_164 != V_71 );
return 0 ;
}
static inline int F_180 ( struct V_161 * V_162 , T_10 * V_178 ,
unsigned long V_164 , unsigned long V_71 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_177 ;
unsigned long V_65 ;
int V_8 ;
V_177 = F_181 ( V_178 , V_164 ) ;
do {
V_65 = F_182 ( V_164 , V_71 ) ;
if ( F_183 ( V_177 ) )
continue;
V_8 = F_176 ( V_162 , V_177 , V_164 , V_65 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_177 ++ , V_164 = V_65 , V_164 != V_71 );
return 0 ;
}
static int F_184 ( struct V_161 * V_162 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_10 * V_178 ;
unsigned long V_164 , V_71 , V_65 ;
int V_8 ;
if ( F_185 ( V_7 ) ) {
V_164 = F_186 ( V_7 , V_162 ) ;
if ( V_164 == - V_179 )
return 0 ;
else
V_71 = V_164 + V_175 ;
} else {
V_164 = V_162 -> V_180 ;
V_71 = V_162 -> V_181 ;
}
V_178 = F_187 ( V_162 -> V_170 , V_164 ) ;
do {
V_65 = F_188 ( V_164 , V_71 ) ;
if ( F_189 ( V_178 ) )
continue;
V_8 = F_180 ( V_162 , V_178 , V_164 , V_65 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_178 ++ , V_164 = V_65 , V_164 != V_71 );
return 0 ;
}
static int F_190 ( struct V_182 * V_183 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_161 * V_162 ;
int V_8 = 0 ;
if ( ! F_191 ( & V_183 -> V_184 ) ) {
F_167 ( V_7 ) ;
F_9 ( V_7 ) ;
F_192 ( & V_183 -> V_184 ) ;
F_193 ( V_7 ) ;
}
for ( V_162 = V_183 -> V_185 ; V_162 ; V_162 = V_162 -> V_186 ) {
if ( V_162 -> V_187 && ( V_8 = F_184 ( V_162 , V_6 , V_7 ) ) )
break;
F_13 () ;
}
F_194 ( & V_183 -> V_184 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_195 ( struct V_3 * V_4 ,
unsigned int V_135 , bool V_188 )
{
unsigned int V_63 = V_4 -> V_63 ;
unsigned int V_98 = V_135 ;
unsigned char V_123 ;
for (; ; ) {
if ( ++ V_98 >= V_63 ) {
if ( ! V_135 ) {
V_98 = 0 ;
break;
}
V_63 = V_135 + 1 ;
V_135 = 0 ;
V_98 = 1 ;
}
V_123 = F_196 ( V_4 -> V_45 [ V_98 ] ) ;
if ( V_123 && F_1 ( V_123 ) != V_46 )
if ( ! V_188 || F_197 ( V_4 , V_98 ) )
break;
if ( ( V_98 % V_87 ) == 0 )
F_13 () ;
}
return V_98 ;
}
int F_198 ( unsigned int type , bool V_188 ,
unsigned long V_189 )
{
struct V_3 * V_4 = V_109 [ type ] ;
struct V_182 * V_190 ;
volatile unsigned char * V_45 ;
unsigned char V_191 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_98 = 0 ;
int V_192 = 0 ;
V_190 = & V_193 ;
F_199 ( & V_193 ) ;
while ( ( V_98 = F_195 ( V_4 , V_98 , V_188 ) ) != 0 ) {
if ( F_200 ( V_194 ) ) {
V_192 = - V_195 ;
break;
}
V_45 = & V_4 -> V_45 [ V_98 ] ;
V_6 = F_3 ( type , V_98 ) ;
V_7 = F_201 ( V_6 ,
V_196 , NULL , 0 , false ) ;
if ( ! V_7 ) {
V_191 = * V_45 ;
if ( ! V_191 || V_191 == V_46 )
continue;
V_192 = - V_169 ;
break;
}
if ( F_125 ( & V_190 -> V_197 ) == 1 ) {
F_202 ( V_190 ) ;
V_190 = & V_193 ;
F_199 ( & V_193 ) ;
}
F_203 ( V_7 ) ;
F_204 ( V_7 ) ;
F_193 ( V_7 ) ;
F_204 ( V_7 ) ;
V_191 = * V_45 ;
if ( F_1 ( V_191 ) == V_125 ) {
V_192 = F_205 ( V_6 , V_7 ) ;
if ( V_192 < 0 )
break;
continue;
}
if ( F_1 ( V_191 ) && V_190 != & V_193 )
V_192 = F_190 ( V_190 , V_6 , V_7 ) ;
if ( F_1 ( * V_45 ) ) {
int V_198 = ( * V_45 >= V_191 ) ;
struct V_199 * V_54 = & V_190 -> V_200 ;
struct V_182 * V_201 = V_190 ;
struct V_182 * V_202 = V_190 ;
struct V_182 * V_183 ;
F_199 ( V_201 ) ;
F_199 ( V_202 ) ;
F_30 ( & V_203 ) ;
while ( F_1 ( * V_45 ) && ! V_192 &&
( V_54 = V_54 -> V_65 ) != & V_190 -> V_200 ) {
V_183 = F_206 ( V_54 , struct V_182 , V_200 ) ;
if ( ! F_207 ( V_183 ) )
continue;
F_32 ( & V_203 ) ;
F_202 ( V_202 ) ;
V_202 = V_183 ;
F_13 () ;
V_191 = * V_45 ;
if ( ! F_1 ( V_191 ) )
;
else if ( V_183 == & V_193 )
V_198 = 1 ;
else
V_192 = F_190 ( V_183 , V_6 , V_7 ) ;
if ( V_198 && * V_45 < V_191 ) {
F_202 ( V_201 ) ;
F_199 ( V_183 ) ;
V_201 = V_183 ;
V_198 = 0 ;
}
F_30 ( & V_203 ) ;
}
F_32 ( & V_203 ) ;
F_202 ( V_202 ) ;
F_202 ( V_190 ) ;
V_190 = V_201 ;
}
if ( V_192 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
break;
}
if ( F_1 ( * V_45 ) &&
F_208 ( V_7 ) && F_126 ( V_7 ) ) {
struct V_204 V_205 = {
. V_206 = V_207 ,
} ;
F_209 ( F_121 ( V_7 ) , & V_205 ) ;
F_193 ( V_7 ) ;
F_204 ( V_7 ) ;
}
if ( F_126 ( V_7 ) &&
F_119 ( F_109 ( V_7 ) == V_6 . V_110 ) &&
! F_118 ( V_7 ) )
F_134 ( F_121 ( V_7 ) ) ;
F_135 ( V_7 ) ;
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
F_13 () ;
if ( V_188 && V_189 > 0 ) {
if ( ! -- V_189 )
break;
}
}
F_202 ( V_190 ) ;
return V_192 ;
}
static void F_210 ( void )
{
struct V_199 * V_54 , * V_65 ;
unsigned int type ;
for ( type = 0 ; type < V_112 ; type ++ )
if ( V_109 [ type ] -> V_74 )
return;
F_30 ( & V_203 ) ;
F_211 (p, next, &init_mm.mmlist)
F_212 ( V_54 ) ;
F_32 ( & V_203 ) ;
}
static T_2 F_146 ( T_1 V_6 , struct V_76 * * V_17 )
{
struct V_3 * V_157 ;
struct V_9 * V_208 ;
struct V_9 * V_10 ;
T_3 V_5 ;
V_157 = V_109 [ F_89 ( V_6 ) ] ;
* V_17 = V_157 -> V_17 ;
V_5 = F_6 ( V_6 ) ;
V_208 = V_157 -> V_20 ;
V_10 = V_208 ;
for ( ; ; ) {
if ( V_10 -> V_19 <= V_5 &&
V_5 < ( V_10 -> V_19 + V_10 -> V_16 ) ) {
return V_10 -> V_11 + ( V_5 - V_10 -> V_19 ) ;
}
V_10 = F_16 ( V_10 , V_23 ) ;
V_157 -> V_20 = V_10 ;
F_213 ( V_10 == V_208 ) ;
}
}
T_2 F_214 ( struct V_7 * V_7 , struct V_76 * * V_17 )
{
T_1 V_6 ;
V_6 . V_110 = F_109 ( V_7 ) ;
return F_146 ( V_6 , V_17 ) ;
}
static void F_215 ( struct V_3 * V_157 )
{
while ( ! F_216 ( & V_157 -> V_14 . V_23 ) ) {
struct V_9 * V_10 ;
V_10 = F_217 ( & V_157 -> V_14 . V_23 ,
struct V_9 , V_23 ) ;
F_218 ( & V_10 -> V_23 ) ;
F_219 ( V_10 ) ;
}
if ( V_157 -> V_27 & V_107 ) {
struct V_209 * V_210 = V_157 -> V_210 ;
struct V_211 * V_212 = V_210 -> V_213 ;
V_157 -> V_27 &= ~ V_107 ;
V_212 -> V_214 -> V_215 ( V_210 ) ;
}
}
int
F_220 ( struct V_3 * V_157 , unsigned long V_19 ,
unsigned long V_16 , T_2 V_11 )
{
struct V_9 * V_10 ;
struct V_9 * V_216 ;
struct V_199 * V_217 ;
if ( V_19 == 0 ) {
V_10 = & V_157 -> V_14 ;
V_157 -> V_20 = V_10 ;
V_10 -> V_19 = 0 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_11 = V_11 ;
return 1 ;
} else {
V_217 = V_157 -> V_14 . V_23 . V_135 ;
V_10 = F_206 ( V_217 , struct V_9 , V_23 ) ;
F_213 ( V_10 -> V_19 + V_10 -> V_16 != V_19 ) ;
if ( V_10 -> V_11 + V_10 -> V_16 == V_11 ) {
V_10 -> V_16 += V_16 ;
return 0 ;
}
}
V_216 = F_221 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_216 == NULL )
return - V_169 ;
V_216 -> V_19 = V_19 ;
V_216 -> V_16 = V_16 ;
V_216 -> V_11 = V_11 ;
F_222 ( & V_216 -> V_23 , & V_157 -> V_14 . V_23 ) ;
return 1 ;
}
static int F_223 ( struct V_3 * V_157 , T_2 * V_218 )
{
struct V_209 * V_210 = V_157 -> V_210 ;
struct V_211 * V_212 = V_210 -> V_213 ;
struct V_219 * V_219 = V_212 -> V_220 ;
int V_8 ;
if ( F_224 ( V_219 -> V_221 ) ) {
V_8 = F_220 ( V_157 , 0 , V_157 -> V_63 , 0 ) ;
* V_218 = V_157 -> V_75 ;
return V_8 ;
}
if ( V_212 -> V_214 -> V_222 ) {
V_8 = V_212 -> V_214 -> V_222 ( V_157 , V_210 , V_218 ) ;
if ( ! V_8 ) {
V_157 -> V_27 |= V_107 ;
V_8 = F_220 ( V_157 , 0 , V_157 -> V_63 , 0 ) ;
* V_218 = V_157 -> V_75 ;
}
return V_8 ;
}
return F_225 ( V_157 , V_210 , V_218 ) ;
}
static int F_226 ( struct V_3 * V_54 )
{
struct V_76 * V_17 ;
if ( V_54 -> V_17 )
V_17 = V_54 -> V_17 ;
else
V_17 = V_54 -> V_210 -> V_223 -> V_224 -> V_225 ;
return V_17 ? V_17 -> V_80 -> V_226 : V_227 ;
}
static void F_227 ( struct V_3 * V_54 , int V_228 ,
unsigned char * V_45 ,
struct V_24 * V_36 )
{
int V_98 ;
if ( V_228 >= 0 )
V_54 -> V_228 = V_228 ;
else
V_54 -> V_228 = -- V_229 ;
V_54 -> V_23 . V_228 = - V_54 -> V_228 ;
F_57 (i) {
if ( V_54 -> V_228 >= 0 )
V_54 -> V_67 [ V_98 ] . V_228 = - V_54 -> V_228 ;
else {
if ( F_226 ( V_54 ) == V_98 )
V_54 -> V_67 [ V_98 ] . V_228 = 1 ;
else
V_54 -> V_67 [ V_98 ] . V_228 = - V_54 -> V_228 ;
}
}
V_54 -> V_45 = V_45 ;
V_54 -> V_36 = V_36 ;
V_54 -> V_27 |= V_52 ;
F_67 ( V_54 -> V_75 , & V_78 ) ;
V_230 += V_54 -> V_75 ;
F_228 ( & V_156 ) ;
F_64 ( & V_54 -> V_23 , & V_231 ) ;
F_61 ( V_54 ) ;
}
static void F_229 ( struct V_3 * V_54 , int V_228 ,
unsigned char * V_45 ,
struct V_24 * V_36 ,
unsigned long * V_232 )
{
F_230 ( V_54 -> type , V_232 ) ;
F_30 ( & V_156 ) ;
F_30 ( & V_54 -> V_38 ) ;
F_227 ( V_54 , V_228 , V_45 , V_36 ) ;
F_32 ( & V_54 -> V_38 ) ;
F_32 ( & V_156 ) ;
}
static void F_231 ( struct V_3 * V_54 )
{
F_30 ( & V_156 ) ;
F_30 ( & V_54 -> V_38 ) ;
F_227 ( V_54 , V_54 -> V_228 , V_54 -> V_45 , V_54 -> V_36 ) ;
F_32 ( & V_54 -> V_38 ) ;
F_32 ( & V_156 ) ;
}
bool F_232 ( void )
{
bool V_8 = true ;
F_30 ( & V_156 ) ;
if ( F_233 ( & V_231 ) )
V_8 = false ;
F_32 ( & V_156 ) ;
return V_8 ;
}
static unsigned F_234 ( struct V_209 * V_209 , T_11 * V_233 )
{
struct V_234 * V_235 = V_209 -> V_236 ;
F_235 ( V_209 , & V_237 , V_233 ) ;
if ( V_235 -> V_238 != F_125 ( & V_239 ) ) {
V_235 -> V_238 = F_125 ( & V_239 ) ;
return V_240 | V_241 | V_242 | V_243 ;
}
return V_240 | V_241 ;
}
static void * F_236 ( struct V_234 * V_244 , T_12 * V_245 )
{
struct V_3 * V_4 ;
int type ;
T_12 V_246 = * V_245 ;
F_237 ( & V_247 ) ;
if ( ! V_246 )
return V_248 ;
for ( type = 0 ; type < V_112 ; type ++ ) {
F_238 () ;
V_4 = V_109 [ type ] ;
if ( ! ( V_4 -> V_27 & V_114 ) || ! V_4 -> V_45 )
continue;
if ( ! -- V_246 )
return V_4 ;
}
return NULL ;
}
static void * F_239 ( struct V_234 * V_244 , void * V_249 , T_12 * V_245 )
{
struct V_3 * V_4 = V_249 ;
int type ;
if ( V_249 == V_248 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_112 ; type ++ ) {
F_238 () ;
V_4 = V_109 [ type ] ;
if ( ! ( V_4 -> V_27 & V_114 ) || ! V_4 -> V_45 )
continue;
++ * V_245 ;
return V_4 ;
}
return NULL ;
}
static void F_240 ( struct V_234 * V_244 , void * V_249 )
{
F_241 ( & V_247 ) ;
}
static int F_242 ( struct V_234 * V_244 , void * V_249 )
{
struct V_3 * V_4 = V_249 ;
struct V_209 * V_209 ;
int V_250 ;
if ( V_4 == V_248 ) {
F_243 ( V_244 , L_5 ) ;
return 0 ;
}
V_209 = V_4 -> V_210 ;
V_250 = F_244 ( V_244 , V_209 , L_6 ) ;
F_245 ( V_244 , L_7 ,
V_250 < 40 ? 40 - V_250 : 1 , L_8 ,
F_224 ( F_246 ( V_209 ) -> V_221 ) ?
L_9 : L_10 ,
V_4 -> V_75 << ( V_15 - 10 ) ,
V_4 -> V_74 << ( V_15 - 10 ) ,
V_4 -> V_228 ) ;
return 0 ;
}
static int F_247 ( struct V_219 * V_219 , struct V_209 * V_209 )
{
struct V_234 * V_235 ;
int V_8 ;
V_8 = F_248 ( V_209 , & V_251 ) ;
if ( V_8 )
return V_8 ;
V_235 = V_209 -> V_236 ;
V_235 -> V_238 = F_125 ( & V_239 ) ;
return 0 ;
}
static int T_13 F_249 ( void )
{
F_250 ( L_11 , 0 , NULL , & V_252 ) ;
return 0 ;
}
static int T_13 F_251 ( void )
{
F_252 () ;
return 0 ;
}
static struct V_3 * F_253 ( void )
{
struct V_3 * V_54 ;
unsigned int type ;
int V_98 ;
V_54 = F_254 ( sizeof( * V_54 ) , V_18 ) ;
if ( ! V_54 )
return F_255 ( - V_169 ) ;
F_30 ( & V_156 ) ;
for ( type = 0 ; type < V_112 ; type ++ ) {
if ( ! ( V_109 [ type ] -> V_27 & V_114 ) )
break;
}
if ( type >= V_253 ) {
F_32 ( & V_156 ) ;
F_219 ( V_54 ) ;
return F_255 ( - V_254 ) ;
}
if ( type >= V_112 ) {
V_54 -> type = type ;
V_109 [ type ] = V_54 ;
F_256 () ;
V_112 ++ ;
} else {
F_219 ( V_54 ) ;
V_54 = V_109 [ type ] ;
}
F_257 ( & V_54 -> V_14 . V_23 ) ;
F_258 ( & V_54 -> V_23 , 0 ) ;
F_57 (i)
F_258 ( & V_54 -> V_67 [ V_98 ] , 0 ) ;
V_54 -> V_27 = V_114 ;
F_32 ( & V_156 ) ;
F_259 ( & V_54 -> V_38 ) ;
F_259 ( & V_54 -> V_255 ) ;
return V_54 ;
}
static int F_260 ( struct V_3 * V_54 , struct V_219 * V_219 )
{
int error ;
if ( F_224 ( V_219 -> V_221 ) ) {
V_54 -> V_17 = F_143 ( F_261 ( V_219 ) ) ;
error = F_262 ( V_54 -> V_17 ,
V_256 | V_257 | V_258 , V_54 ) ;
if ( error < 0 ) {
V_54 -> V_17 = NULL ;
return error ;
}
V_54 -> V_259 = F_263 ( V_54 -> V_17 ) ;
error = F_264 ( V_54 -> V_17 , V_175 ) ;
if ( error < 0 )
return error ;
V_54 -> V_27 |= V_79 ;
} else if ( F_265 ( V_219 -> V_221 ) ) {
V_54 -> V_17 = V_219 -> V_224 -> V_225 ;
F_266 ( V_219 ) ;
if ( F_267 ( V_219 ) )
return - V_129 ;
} else
return - V_260 ;
return 0 ;
}
static unsigned long F_268 ( struct V_3 * V_54 ,
union V_261 * V_261 ,
struct V_219 * V_219 )
{
int V_98 ;
unsigned long V_262 ;
unsigned long V_263 ;
unsigned long V_264 ;
if ( memcmp ( L_12 , V_261 -> V_265 . V_265 , 10 ) ) {
F_90 ( L_13 ) ;
return 0 ;
}
if ( F_269 ( V_261 -> V_25 . V_266 ) == 1 ) {
F_270 ( & V_261 -> V_25 . V_266 ) ;
F_270 ( & V_261 -> V_25 . V_264 ) ;
F_270 ( & V_261 -> V_25 . V_267 ) ;
if ( V_261 -> V_25 . V_267 > V_268 )
return 0 ;
for ( V_98 = 0 ; V_98 < V_261 -> V_25 . V_267 ; V_98 ++ )
F_270 ( & V_261 -> V_25 . V_269 [ V_98 ] ) ;
}
if ( V_261 -> V_25 . V_266 != 1 ) {
F_271 ( L_14 ,
V_261 -> V_25 . V_266 ) ;
return 0 ;
}
V_54 -> V_72 = 1 ;
V_54 -> F_21 = 1 ;
V_54 -> V_93 = 0 ;
V_262 = F_6 ( F_272 (
F_155 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_264 = V_261 -> V_25 . V_264 ;
if ( V_264 > V_262 ) {
F_271 ( L_15 ,
V_262 << ( V_15 - 10 ) ,
V_264 << ( V_15 - 10 ) ) ;
}
if ( V_262 > V_264 ) {
V_262 = V_264 + 1 ;
if ( ( unsigned int ) V_262 == 0 )
V_262 = V_270 ;
}
V_54 -> V_73 = V_262 - 1 ;
if ( ! V_262 )
return 0 ;
V_263 = F_273 ( V_219 ) >> V_15 ;
if ( V_263 && V_262 > V_263 ) {
F_271 ( L_16 ) ;
return 0 ;
}
if ( V_261 -> V_25 . V_267 && F_265 ( V_219 -> V_221 ) )
return 0 ;
if ( V_261 -> V_25 . V_267 > V_268 )
return 0 ;
return V_262 ;
}
static int F_274 ( struct V_3 * V_54 ,
union V_261 * V_261 ,
unsigned char * V_45 ,
struct V_24 * V_36 ,
unsigned long V_262 ,
T_2 * V_218 )
{
unsigned int V_271 , V_272 ;
unsigned int V_273 ;
int V_274 ;
unsigned long V_275 = F_275 ( V_262 , V_37 ) ;
unsigned long V_276 = V_54 -> F_21 / V_37 % V_277 ;
unsigned long V_98 , V_42 ;
V_273 = V_262 - 1 ;
F_37 ( & V_54 -> V_49 ) ;
F_37 ( & V_54 -> V_47 ) ;
for ( V_98 = 0 ; V_98 < V_261 -> V_25 . V_267 ; V_98 ++ ) {
unsigned int V_55 = V_261 -> V_25 . V_269 [ V_98 ] ;
if ( V_55 == 0 || V_55 > V_261 -> V_25 . V_264 )
return - V_260 ;
if ( V_55 < V_262 ) {
V_45 [ V_55 ] = V_46 ;
V_273 -- ;
F_50 ( V_54 , V_36 , V_55 ) ;
}
}
for ( V_98 = V_262 ; V_98 < F_276 ( V_262 , V_37 ) ; V_98 ++ )
F_50 ( V_54 , V_36 , V_98 ) ;
if ( V_273 ) {
V_45 [ 0 ] = V_46 ;
F_50 ( V_54 , V_36 , 0 ) ;
V_54 -> V_63 = V_262 ;
V_54 -> V_75 = V_273 ;
V_274 = F_223 ( V_54 , V_218 ) ;
if ( V_274 < 0 )
return V_274 ;
V_273 = V_54 -> V_75 ;
}
if ( ! V_273 ) {
F_271 ( L_17 ) ;
return - V_260 ;
}
if ( ! V_36 )
return V_274 ;
for ( V_272 = 0 ; V_272 < V_277 ; V_272 ++ ) {
V_271 = ( V_272 + V_276 ) % V_277 ;
for ( V_98 = 0 ; V_98 < F_275 ( V_275 , V_277 ) ; V_98 ++ ) {
V_42 = V_98 * V_277 + V_271 ;
if ( V_42 >= V_275 )
continue;
if ( F_18 ( & V_36 [ V_42 ] ) )
continue;
F_17 ( & V_36 [ V_42 ] , V_32 ) ;
F_38 ( & V_54 -> V_49 , V_36 ,
V_42 ) ;
}
}
return V_274 ;
}
static bool F_277 ( struct V_3 * V_4 )
{
struct V_278 * V_122 = F_278 ( V_4 -> V_17 ) ;
if ( ! V_122 || ! F_279 ( V_122 ) )
return false ;
return true ;
}
void F_280 ( struct V_279 * V_110 )
{
unsigned int type ;
unsigned long V_280 = 0 ;
F_30 ( & V_156 ) ;
for ( type = 0 ; type < V_112 ; type ++ ) {
struct V_3 * V_4 = V_109 [ type ] ;
if ( ( V_4 -> V_27 & V_114 ) && ! ( V_4 -> V_27 & V_52 ) )
V_280 += V_4 -> V_74 ;
}
V_110 -> V_281 = F_78 ( & V_78 ) + V_280 ;
V_110 -> V_282 = V_230 + V_280 ;
F_32 ( & V_156 ) ;
}
static int F_281 ( T_1 V_6 , unsigned char V_82 )
{
struct V_3 * V_54 ;
struct V_24 * V_35 ;
unsigned long V_5 , type ;
unsigned char V_123 ;
unsigned char V_124 ;
int V_13 = - V_260 ;
if ( F_138 ( V_6 ) )
goto V_111;
type = F_89 ( V_6 ) ;
if ( type >= V_112 )
goto V_283;
V_54 = V_109 [ type ] ;
V_5 = F_6 ( V_6 ) ;
if ( F_70 ( V_5 >= V_54 -> V_63 ) )
goto V_111;
V_35 = F_33 ( V_54 , V_5 ) ;
V_123 = V_54 -> V_45 [ V_5 ] ;
if ( F_70 ( F_1 ( V_123 ) == V_46 ) ) {
V_13 = - V_284 ;
goto V_142;
}
V_124 = V_123 & V_2 ;
V_123 &= ~ V_2 ;
V_13 = 0 ;
if ( V_82 == V_2 ) {
if ( ! V_124 && V_123 )
V_124 = V_2 ;
else if ( V_124 )
V_13 = - V_285 ;
else
V_13 = - V_284 ;
} else if ( V_123 || V_124 ) {
if ( ( V_123 & ~ V_126 ) < V_127 )
V_123 += V_82 ;
else if ( ( V_123 & ~ V_126 ) > V_127 )
V_13 = - V_260 ;
else if ( F_95 ( V_54 , V_5 , V_123 ) )
V_123 = V_126 ;
else
V_13 = - V_169 ;
} else
V_13 = - V_284 ;
V_54 -> V_45 [ V_5 ] = V_123 | V_124 ;
V_142:
F_34 ( V_54 , V_35 ) ;
V_111:
return V_13 ;
V_283:
F_90 ( L_18 , V_119 , V_6 . V_110 ) ;
goto V_111;
}
void F_282 ( T_1 V_6 )
{
F_281 ( V_6 , V_125 ) ;
}
int F_283 ( T_1 V_6 )
{
int V_13 = 0 ;
while ( ! V_13 && F_281 ( V_6 , 1 ) == - V_169 )
V_13 = F_284 ( V_6 , V_286 ) ;
return V_13 ;
}
int F_285 ( T_1 V_6 )
{
return F_281 ( V_6 , V_2 ) ;
}
struct V_3 * F_286 ( struct V_7 * V_7 )
{
T_1 V_244 = { . V_110 = F_109 (page) } ;
return V_109 [ F_89 ( V_244 ) ] ;
}
struct V_211 * F_287 ( struct V_7 * V_7 )
{
F_123 ( ! F_126 ( V_7 ) , V_7 ) ;
return F_286 ( V_7 ) -> V_210 -> V_213 ;
}
T_3 F_288 ( struct V_7 * V_7 )
{
T_1 V_244 = { . V_110 = F_109 (page) } ;
F_123 ( ! F_126 ( V_7 ) , V_7 ) ;
return F_6 ( V_244 ) ;
}
int F_284 ( T_1 V_6 , T_14 V_287 )
{
struct V_3 * V_4 ;
struct V_24 * V_35 ;
struct V_7 * V_40 ;
struct V_7 * V_7 ;
struct V_7 * V_288 ;
T_3 V_5 ;
unsigned char V_123 ;
V_7 = F_289 ( V_287 | V_289 ) ;
V_4 = F_92 ( V_6 ) ;
if ( ! V_4 ) {
goto V_290;
}
V_5 = F_6 ( V_6 ) ;
V_35 = F_29 ( V_4 , V_5 ) ;
V_123 = V_4 -> V_45 [ V_5 ] & ~ V_2 ;
if ( ( V_123 & ~ V_126 ) != V_127 ) {
goto V_111;
}
if ( ! V_7 ) {
F_31 ( V_35 ) ;
F_32 ( & V_4 -> V_38 ) ;
return - V_169 ;
}
V_40 = F_113 ( V_4 -> V_45 + V_5 ) ;
V_5 &= ~ V_137 ;
F_30 ( & V_4 -> V_255 ) ;
if ( ! F_109 ( V_40 ) ) {
F_213 ( V_123 & V_126 ) ;
F_257 ( & V_40 -> V_139 ) ;
F_290 ( V_40 , V_138 ) ;
V_4 -> V_27 |= V_138 ;
}
F_14 (list_page, &head->lru, lru) {
unsigned char * V_99 ;
if ( ! ( V_123 & V_126 ) )
goto V_291;
V_99 = F_114 ( V_288 ) + V_5 ;
V_123 = * V_99 ;
F_115 ( V_99 ) ;
if ( ( V_123 & ~ V_126 ) != V_140 )
goto V_291;
}
F_222 ( & V_7 -> V_139 , & V_40 -> V_139 ) ;
V_7 = NULL ;
V_291:
F_32 ( & V_4 -> V_255 ) ;
V_111:
F_31 ( V_35 ) ;
F_32 ( & V_4 -> V_38 ) ;
V_290:
if ( V_7 )
F_291 ( V_7 ) ;
return 0 ;
}
static bool F_95 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_123 )
{
struct V_7 * V_40 ;
struct V_7 * V_7 ;
unsigned char * V_99 ;
bool V_8 ;
V_40 = F_113 ( V_4 -> V_45 + V_5 ) ;
if ( F_109 ( V_40 ) != V_138 ) {
F_213 ( V_123 & V_126 ) ;
return false ;
}
F_30 ( & V_4 -> V_255 ) ;
V_5 &= ~ V_137 ;
V_7 = F_206 ( V_40 -> V_139 . V_65 , struct V_7 , V_139 ) ;
V_99 = F_114 ( V_7 ) + V_5 ;
if ( V_123 == V_127 )
goto V_292;
if ( V_123 == ( V_127 | V_126 ) ) {
while ( * V_99 == ( V_140 | V_126 ) ) {
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_65 , struct V_7 , V_139 ) ;
F_213 ( V_7 == V_40 ) ;
V_99 = F_114 ( V_7 ) + V_5 ;
}
if ( * V_99 == V_140 ) {
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_65 , struct V_7 , V_139 ) ;
if ( V_7 == V_40 ) {
V_8 = false ;
goto V_111;
}
V_99 = F_114 ( V_7 ) + V_5 ;
V_292: * V_99 = 0 ;
}
* V_99 += 1 ;
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_135 , struct V_7 , V_139 ) ;
while ( V_7 != V_40 ) {
V_99 = F_114 ( V_7 ) + V_5 ;
* V_99 = V_126 ;
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_135 , struct V_7 , V_139 ) ;
}
V_8 = true ;
} else {
F_213 ( V_123 != V_126 ) ;
while ( * V_99 == V_126 ) {
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_65 , struct V_7 , V_139 ) ;
F_213 ( V_7 == V_40 ) ;
V_99 = F_114 ( V_7 ) + V_5 ;
}
F_213 ( * V_99 == 0 ) ;
* V_99 -= 1 ;
if ( * V_99 == 0 )
V_123 = 0 ;
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_135 , struct V_7 , V_139 ) ;
while ( V_7 != V_40 ) {
V_99 = F_114 ( V_7 ) + V_5 ;
* V_99 = V_140 | V_123 ;
V_123 = V_126 ;
F_115 ( V_99 ) ;
V_7 = F_206 ( V_7 -> V_139 . V_135 , struct V_7 , V_139 ) ;
}
V_8 = V_123 == V_126 ;
}
V_111:
F_32 ( & V_4 -> V_255 ) ;
return V_8 ;
}
static void F_292 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_63 ; V_5 += V_175 ) {
struct V_7 * V_40 ;
V_40 = F_113 ( V_4 -> V_45 + V_5 ) ;
if ( F_109 ( V_40 ) ) {
struct V_7 * V_7 , * V_65 ;
F_293 (page, next, &head->lru, lru) {
F_218 ( & V_7 -> V_139 ) ;
F_291 ( V_7 ) ;
}
}
}
}
static int T_13 F_294 ( void )
{
int V_66 ;
V_68 = F_295 ( V_293 , sizeof( struct V_294 ) ,
V_18 ) ;
if ( ! V_68 ) {
F_296 ( L_19 ) ;
return - V_169 ;
}
F_57 (nid)
F_297 ( & V_68 [ V_66 ] ) ;
return 0 ;
}
