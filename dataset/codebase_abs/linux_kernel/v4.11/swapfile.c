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
static inline struct V_24 * F_27 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_24 * V_34 ;
V_34 = V_4 -> V_35 ;
if ( V_34 ) {
V_34 += V_5 / V_36 ;
F_28 ( & V_34 -> V_37 ) ;
}
return V_34 ;
}
static inline void F_29 ( struct V_24 * V_34 )
{
if ( V_34 )
F_30 ( & V_34 -> V_37 ) ;
}
static inline struct V_24 * F_31 (
struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_24 * V_34 ;
V_34 = F_27 ( V_4 , V_5 ) ;
if ( ! V_34 )
F_28 ( & V_4 -> V_37 ) ;
return V_34 ;
}
static inline void F_32 ( struct V_3 * V_4 ,
struct V_24 * V_34 )
{
if ( V_34 )
F_29 ( V_34 ) ;
else
F_30 ( & V_4 -> V_37 ) ;
}
static inline bool F_33 ( struct V_38 * V_23 )
{
return F_25 ( & V_23 -> V_39 ) ;
}
static inline unsigned int F_34 ( struct V_38 * V_23 )
{
return F_21 ( & V_23 -> V_39 ) ;
}
static void F_35 ( struct V_38 * V_23 )
{
F_26 ( & V_23 -> V_39 ) ;
F_26 ( & V_23 -> V_40 ) ;
}
static void F_36 ( struct V_38 * V_23 ,
struct V_24 * V_34 ,
unsigned int V_41 )
{
if ( F_33 ( V_23 ) ) {
F_23 ( & V_23 -> V_39 , V_41 , 0 ) ;
F_23 ( & V_23 -> V_40 , V_41 , 0 ) ;
} else {
struct V_24 * V_42 ;
unsigned int V_40 = F_21 ( & V_23 -> V_40 ) ;
V_42 = V_34 + V_40 ;
F_37 ( & V_42 -> V_37 , V_43 ) ;
F_22 ( V_42 , V_41 ) ;
F_29 ( V_42 ) ;
F_23 ( & V_23 -> V_40 , V_41 , 0 ) ;
}
}
static unsigned int F_38 ( struct V_38 * V_23 ,
struct V_24 * V_34 )
{
unsigned int V_41 ;
V_41 = F_21 ( & V_23 -> V_39 ) ;
if ( F_21 ( & V_23 -> V_40 ) == V_41 ) {
F_26 ( & V_23 -> V_39 ) ;
F_26 ( & V_23 -> V_40 ) ;
} else
F_23 ( & V_23 -> V_39 ,
F_21 ( & V_34 [ V_41 ] ) , 0 ) ;
return V_41 ;
}
static void F_39 ( struct V_3 * V_4 ,
unsigned int V_41 )
{
memset ( V_4 -> V_44 + V_41 * V_36 ,
V_45 , V_36 ) ;
F_36 ( & V_4 -> V_46 , V_4 -> V_35 , V_41 ) ;
F_40 ( & V_4 -> V_47 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_24 * V_25 , * V_34 ;
unsigned int V_41 ;
V_25 = V_4 -> V_35 ;
while ( ! F_33 ( & V_4 -> V_46 ) ) {
V_41 = F_38 ( & V_4 -> V_46 , V_25 ) ;
F_30 ( & V_4 -> V_37 ) ;
F_15 ( V_4 , V_41 * V_36 ,
V_36 ) ;
F_28 ( & V_4 -> V_37 ) ;
V_34 = F_27 ( V_4 , V_41 * V_36 ) ;
F_17 ( V_34 , V_32 ) ;
F_29 ( V_34 ) ;
F_36 ( & V_4 -> V_48 , V_25 , V_41 ) ;
V_34 = F_27 ( V_4 , V_41 * V_36 ) ;
memset ( V_4 -> V_44 + V_41 * V_36 ,
0 , V_36 ) ;
F_29 ( V_34 ) ;
}
}
static void F_42 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
V_4 = F_43 ( V_50 , struct V_3 , V_47 ) ;
F_28 ( & V_4 -> V_37 ) ;
F_41 ( V_4 ) ;
F_30 ( & V_4 -> V_37 ) ;
}
static void F_44 ( struct V_3 * V_51 ,
struct V_24 * V_35 , unsigned long V_52 )
{
unsigned long V_41 = V_52 / V_36 ;
if ( ! V_35 )
return;
if ( F_24 ( & V_35 [ V_41 ] ) ) {
F_45 ( F_34 ( & V_51 -> V_48 ) != V_41 ) ;
F_38 ( & V_51 -> V_48 , V_35 ) ;
F_20 ( & V_35 [ V_41 ] , 0 , 0 ) ;
}
F_45 ( F_18 ( & V_35 [ V_41 ] ) >= V_36 ) ;
F_19 ( & V_35 [ V_41 ] ,
F_18 ( & V_35 [ V_41 ] ) + 1 ) ;
}
static void F_46 ( struct V_3 * V_51 ,
struct V_24 * V_35 , unsigned long V_52 )
{
unsigned long V_41 = V_52 / V_36 ;
if ( ! V_35 )
return;
F_45 ( F_18 ( & V_35 [ V_41 ] ) == 0 ) ;
F_19 ( & V_35 [ V_41 ] ,
F_18 ( & V_35 [ V_41 ] ) - 1 ) ;
if ( F_18 ( & V_35 [ V_41 ] ) == 0 ) {
if ( ( V_51 -> V_27 & ( V_53 | V_54 ) ) ==
( V_53 | V_54 ) ) {
F_39 ( V_51 , V_41 ) ;
return;
}
F_17 ( & V_35 [ V_41 ] , V_32 ) ;
F_36 ( & V_51 -> V_48 , V_35 , V_41 ) ;
}
}
static bool
F_47 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_55 * V_55 ;
bool V_56 ;
V_5 /= V_36 ;
V_56 = ! F_33 ( & V_4 -> V_48 ) &&
V_5 != F_34 ( & V_4 -> V_48 ) &&
F_24 ( & V_4 -> V_35 [ V_5 ] ) ;
if ( ! V_56 )
return false ;
V_55 = F_48 ( V_4 -> V_55 ) ;
F_26 ( & V_55 -> V_57 ) ;
return true ;
}
static bool F_49 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_58 )
{
struct V_55 * V_59 ;
struct V_24 * V_34 ;
bool V_60 ;
unsigned long V_61 , V_62 ;
V_63:
V_59 = F_48 ( V_4 -> V_55 ) ;
if ( F_25 ( & V_59 -> V_57 ) ) {
if ( ! F_33 ( & V_4 -> V_48 ) ) {
V_59 -> V_57 = V_4 -> V_48 . V_39 ;
V_59 -> V_64 = F_21 ( & V_59 -> V_57 ) *
V_36 ;
} else if ( ! F_33 ( & V_4 -> V_46 ) ) {
F_41 ( V_4 ) ;
* V_58 = * V_5 = V_4 -> F_21 ;
goto V_63;
} else
return false ;
}
V_60 = false ;
V_61 = V_59 -> V_64 ;
V_62 = F_50 (unsigned long, si->max,
(cluster_next(&cluster->index) + 1) * SWAPFILE_CLUSTER) ;
if ( V_61 >= V_62 ) {
F_26 ( & V_59 -> V_57 ) ;
goto V_63;
}
V_34 = F_27 ( V_4 , V_61 ) ;
while ( V_61 < V_62 ) {
if ( ! V_4 -> V_44 [ V_61 ] ) {
V_60 = true ;
break;
}
V_61 ++ ;
}
F_29 ( V_34 ) ;
if ( ! V_60 ) {
F_26 ( & V_59 -> V_57 ) ;
goto V_63;
}
V_59 -> V_64 = V_61 + 1 ;
* V_5 = V_61 ;
* V_58 = V_61 ;
return V_60 ;
}
static int F_51 ( struct V_3 * V_4 ,
unsigned char V_65 , int V_66 ,
T_1 V_67 [] )
{
struct V_24 * V_34 ;
unsigned long V_5 ;
unsigned long V_58 ;
unsigned long V_68 = 0 ;
int V_69 = V_70 ;
int V_71 = 0 ;
if ( V_66 > V_72 )
V_66 = V_72 ;
V_4 -> V_27 += V_73 ;
V_58 = V_5 = V_4 -> F_21 ;
if ( V_4 -> V_35 ) {
if ( F_49 ( V_4 , & V_5 , & V_58 ) )
goto V_74;
else
goto V_75;
}
if ( F_52 ( ! V_4 -> V_76 -- ) ) {
if ( V_4 -> V_77 - V_4 -> V_78 < V_36 ) {
V_4 -> V_76 = V_36 - 1 ;
goto V_74;
}
F_30 ( & V_4 -> V_37 ) ;
V_58 = V_5 = V_4 -> V_79 ;
V_68 = V_5 + V_36 - 1 ;
for (; V_68 <= V_4 -> V_80 ; V_5 ++ ) {
if ( V_4 -> V_44 [ V_5 ] )
V_68 = V_5 + V_36 ;
else if ( V_5 == V_68 ) {
F_28 ( & V_4 -> V_37 ) ;
V_5 -= V_36 - 1 ;
V_4 -> F_21 = V_5 ;
V_4 -> V_76 = V_36 - 1 ;
goto V_74;
}
if ( F_52 ( -- V_69 < 0 ) ) {
F_13 () ;
V_69 = V_70 ;
}
}
V_5 = V_58 ;
F_28 ( & V_4 -> V_37 ) ;
V_4 -> V_76 = V_36 - 1 ;
}
V_74:
if ( V_4 -> V_35 ) {
while ( F_47 ( V_4 , V_5 ) ) {
if ( V_71 )
goto V_81;
if ( ! F_49 ( V_4 , & V_5 ,
& V_58 ) )
goto V_75;
}
}
if ( ! ( V_4 -> V_27 & V_53 ) )
goto V_82;
if ( ! V_4 -> V_80 )
goto V_82;
if ( V_5 > V_4 -> V_80 )
V_58 = V_5 = V_4 -> V_79 ;
V_34 = F_27 ( V_4 , V_5 ) ;
if ( F_53 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
int V_83 ;
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
V_83 = F_2 ( V_4 , V_5 ) ;
F_28 ( & V_4 -> V_37 ) ;
if ( V_83 )
goto V_74;
goto V_75;
}
if ( V_4 -> V_44 [ V_5 ] ) {
F_29 ( V_34 ) ;
if ( ! V_71 )
goto V_75;
else
goto V_81;
}
if ( V_5 == V_4 -> V_79 )
V_4 -> V_79 ++ ;
if ( V_5 == V_4 -> V_80 )
V_4 -> V_80 -- ;
V_4 -> V_78 ++ ;
if ( V_4 -> V_78 == V_4 -> V_77 ) {
V_4 -> V_79 = V_4 -> V_62 ;
V_4 -> V_80 = 0 ;
F_28 ( & V_84 ) ;
F_54 ( & V_4 -> V_85 , & V_86 ) ;
F_30 ( & V_84 ) ;
}
V_4 -> V_44 [ V_5 ] = V_65 ;
F_44 ( V_4 , V_4 -> V_35 , V_5 ) ;
F_29 ( V_34 ) ;
V_4 -> F_21 = V_5 + 1 ;
V_67 [ V_71 ++ ] = F_3 ( V_4 -> type , V_5 ) ;
if ( ( V_71 == V_66 ) || ( V_5 >= V_4 -> V_80 ) )
goto V_81;
if ( F_52 ( -- V_69 < 0 ) ) {
if ( V_71 )
goto V_81;
F_30 ( & V_4 -> V_37 ) ;
F_13 () ;
F_28 ( & V_4 -> V_37 ) ;
V_69 = V_70 ;
}
if ( V_4 -> V_35 ) {
if ( F_49 ( V_4 , & V_5 , & V_58 ) )
goto V_74;
else
goto V_81;
}
++ V_5 ;
if ( V_4 -> V_76 && ! V_4 -> V_44 [ V_5 ] ) {
-- V_4 -> V_76 ;
goto V_74;
}
V_81:
V_4 -> V_27 -= V_73 ;
return V_71 ;
V_75:
F_30 ( & V_4 -> V_37 ) ;
while ( ++ V_5 <= V_4 -> V_80 ) {
if ( ! V_4 -> V_44 [ V_5 ] ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_74;
}
if ( F_53 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_74;
}
if ( F_52 ( -- V_69 < 0 ) ) {
F_13 () ;
V_69 = V_70 ;
}
}
V_5 = V_4 -> V_79 ;
while ( V_5 < V_58 ) {
if ( ! V_4 -> V_44 [ V_5 ] ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_74;
}
if ( F_53 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_74;
}
if ( F_52 ( -- V_69 < 0 ) ) {
F_13 () ;
V_69 = V_70 ;
}
V_5 ++ ;
}
F_28 ( & V_4 -> V_37 ) ;
V_82:
V_4 -> V_27 -= V_73 ;
return V_71 ;
}
static unsigned long F_55 ( struct V_3 * V_4 ,
unsigned char V_65 )
{
T_1 V_6 ;
int V_71 ;
V_71 = F_51 ( V_4 , V_65 , 1 , & V_6 ) ;
if ( V_71 )
return F_6 ( V_6 ) ;
else
return 0 ;
}
int F_56 ( int V_87 , T_1 V_88 [] )
{
struct V_3 * V_4 , * V_64 ;
long V_89 ;
int V_71 = 0 ;
V_89 = F_57 ( & V_90 ) ;
if ( V_89 <= 0 )
goto V_91;
if ( V_87 > V_72 )
V_87 = V_72 ;
if ( V_87 > V_89 )
V_87 = V_89 ;
F_58 ( V_87 , & V_90 ) ;
F_28 ( & V_84 ) ;
V_92:
F_59 (si, next, &swap_avail_head, avail_list) {
F_60 ( & V_4 -> V_85 , & V_86 ) ;
F_30 ( & V_84 ) ;
F_28 ( & V_4 -> V_37 ) ;
if ( ! V_4 -> V_80 || ! ( V_4 -> V_27 & V_53 ) ) {
F_28 ( & V_84 ) ;
if ( F_61 ( & V_4 -> V_85 ) ) {
F_30 ( & V_4 -> V_37 ) ;
goto V_93;
}
F_62 ( ! V_4 -> V_80 ,
L_1 ,
V_4 -> type ) ;
F_62 ( ! ( V_4 -> V_27 & V_53 ) ,
L_2 ,
V_4 -> type ) ;
F_54 ( & V_4 -> V_85 , & V_86 ) ;
F_30 ( & V_4 -> V_37 ) ;
goto V_93;
}
V_71 = F_51 ( V_4 , V_2 ,
V_87 , V_88 ) ;
F_30 ( & V_4 -> V_37 ) ;
if ( V_71 )
goto V_94;
F_63 ( L_3 ,
V_4 -> type ) ;
F_28 ( & V_84 ) ;
V_93:
if ( F_61 ( & V_64 -> V_85 ) )
goto V_92;
}
F_30 ( & V_84 ) ;
V_94:
if ( V_71 < V_87 )
F_64 ( ( long ) ( V_87 - V_71 ) , & V_90 ) ;
V_91:
return V_71 ;
}
T_1 F_65 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_95 [ type ] ;
F_28 ( & V_4 -> V_37 ) ;
if ( V_4 && ( V_4 -> V_27 & V_53 ) ) {
F_66 ( & V_90 ) ;
V_5 = F_55 ( V_4 , 1 ) ;
if ( V_5 ) {
F_30 ( & V_4 -> V_37 ) ;
return F_3 ( type , V_5 ) ;
}
F_67 ( & V_90 ) ;
}
F_30 ( & V_4 -> V_37 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_68 ( T_1 V_6 )
{
struct V_3 * V_51 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_96 )
goto V_97;
type = F_69 ( V_6 ) ;
if ( type >= V_98 )
goto V_99;
V_51 = V_95 [ type ] ;
if ( ! ( V_51 -> V_27 & V_100 ) )
goto V_101;
V_5 = F_6 ( V_6 ) ;
if ( V_5 >= V_51 -> V_62 )
goto V_102;
return V_51 ;
V_102:
F_70 ( L_4 , V_103 , V_6 . V_96 ) ;
goto V_97;
V_101:
F_70 ( L_4 , V_104 , V_6 . V_96 ) ;
goto V_97;
V_99:
F_70 ( L_4 , V_105 , V_6 . V_96 ) ;
V_97:
return NULL ;
}
static struct V_3 * F_71 ( T_1 V_6 )
{
struct V_3 * V_51 ;
V_51 = F_68 ( V_6 ) ;
if ( ! V_51 )
goto V_97;
if ( ! V_51 -> V_44 [ F_6 ( V_6 ) ] )
goto V_106;
return V_51 ;
V_106:
F_70 ( L_4 , V_107 , V_6 . V_96 ) ;
goto V_97;
V_97:
return NULL ;
}
static struct V_3 * F_72 ( T_1 V_6 )
{
struct V_3 * V_51 ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 )
F_28 ( & V_51 -> V_37 ) ;
return V_51 ;
}
static struct V_3 * F_73 ( T_1 V_6 ,
struct V_3 * V_108 )
{
struct V_3 * V_51 ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 != V_108 ) {
if ( V_108 != NULL )
F_30 ( & V_108 -> V_37 ) ;
if ( V_51 != NULL )
F_28 ( & V_51 -> V_37 ) ;
}
return V_51 ;
}
static unsigned char F_74 ( struct V_3 * V_51 ,
T_1 V_6 , unsigned char V_65 )
{
struct V_24 * V_34 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_109 ;
unsigned char V_110 ;
V_34 = F_31 ( V_51 , V_5 ) ;
V_109 = V_51 -> V_44 [ V_5 ] ;
V_110 = V_109 & V_2 ;
V_109 &= ~ V_2 ;
if ( V_65 == V_2 ) {
F_45 ( ! V_110 ) ;
V_110 = 0 ;
} else if ( V_109 == V_111 ) {
V_109 = 0 ;
} else if ( ( V_109 & ~ V_112 ) <= V_113 ) {
if ( V_109 == V_112 ) {
if ( F_75 ( V_51 , V_5 , V_109 ) )
V_109 = V_113 | V_112 ;
else
V_109 = V_113 ;
} else
V_109 -- ;
}
V_65 = V_109 | V_110 ;
V_51 -> V_44 [ V_5 ] = V_65 ? : V_2 ;
F_32 ( V_51 , V_34 ) ;
return V_65 ;
}
static void F_76 ( struct V_3 * V_51 , T_1 V_6 )
{
struct V_24 * V_34 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_109 ;
V_34 = F_27 ( V_51 , V_5 ) ;
V_109 = V_51 -> V_44 [ V_5 ] ;
F_45 ( V_109 != V_2 ) ;
V_51 -> V_44 [ V_5 ] = 0 ;
F_46 ( V_51 , V_51 -> V_35 , V_5 ) ;
F_29 ( V_34 ) ;
F_77 ( V_6 ) ;
if ( V_5 < V_51 -> V_79 )
V_51 -> V_79 = V_5 ;
if ( V_5 > V_51 -> V_80 ) {
bool V_114 = ! V_51 -> V_80 ;
V_51 -> V_80 = V_5 ;
if ( V_114 && ( V_51 -> V_27 & V_53 ) ) {
F_28 ( & V_84 ) ;
F_78 ( ! F_61 ( & V_51 -> V_85 ) ) ;
if ( F_61 ( & V_51 -> V_85 ) )
F_79 ( & V_51 -> V_85 ,
& V_86 ) ;
F_30 ( & V_84 ) ;
}
}
F_67 ( & V_90 ) ;
V_51 -> V_78 -- ;
F_80 ( V_51 -> type , V_5 ) ;
if ( V_51 -> V_27 & V_115 ) {
struct V_116 * V_117 = V_51 -> V_17 -> V_118 ;
if ( V_117 -> V_119 -> V_120 )
V_117 -> V_119 -> V_120 ( V_51 -> V_17 ,
V_5 ) ;
}
}
void F_81 ( T_1 V_6 )
{
struct V_3 * V_51 ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 ) {
if ( ! F_74 ( V_51 , V_6 , 1 ) )
F_82 ( V_6 ) ;
}
}
void F_83 ( T_1 V_6 )
{
struct V_3 * V_51 ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 ) {
if ( ! F_74 ( V_51 , V_6 , V_2 ) )
F_82 ( V_6 ) ;
}
}
void F_84 ( T_1 * V_121 , int V_31 )
{
struct V_3 * V_51 , * V_122 ;
int V_123 ;
if ( V_31 <= 0 )
return;
V_122 = NULL ;
V_51 = NULL ;
for ( V_123 = 0 ; V_123 < V_31 ; ++ V_123 ) {
V_51 = F_73 ( V_121 [ V_123 ] , V_122 ) ;
if ( V_51 )
F_76 ( V_51 , V_121 [ V_123 ] ) ;
else
break;
V_122 = V_51 ;
}
if ( V_51 )
F_30 ( & V_51 -> V_37 ) ;
}
int F_85 ( struct V_7 * V_7 )
{
int V_109 = 0 ;
struct V_3 * V_51 ;
struct V_24 * V_34 ;
T_1 V_6 ;
unsigned long V_5 ;
V_6 . V_96 = F_86 ( V_7 ) ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 ) {
V_5 = F_6 ( V_6 ) ;
V_34 = F_31 ( V_51 , V_5 ) ;
V_109 = F_1 ( V_51 -> V_44 [ V_5 ] ) ;
F_32 ( V_51 , V_34 ) ;
}
return V_109 ;
}
int F_87 ( T_1 V_6 )
{
int V_109 = 0 ;
T_3 V_5 ;
struct V_3 * V_4 ;
struct V_24 * V_34 ;
V_4 = F_68 ( V_6 ) ;
if ( V_4 ) {
V_5 = F_6 ( V_6 ) ;
V_34 = F_31 ( V_4 , V_5 ) ;
V_109 = F_1 ( V_4 -> V_44 [ V_5 ] ) ;
F_32 ( V_4 , V_34 ) ;
}
return V_109 ;
}
int F_88 ( T_1 V_6 )
{
int V_109 , V_124 , V_31 ;
struct V_3 * V_51 ;
struct V_24 * V_34 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_125 ;
V_51 = F_71 ( V_6 ) ;
if ( ! V_51 )
return 0 ;
V_5 = F_6 ( V_6 ) ;
V_34 = F_31 ( V_51 , V_5 ) ;
V_109 = F_1 ( V_51 -> V_44 [ V_5 ] ) ;
if ( ! ( V_109 & V_112 ) )
goto V_97;
V_109 &= ~ V_112 ;
V_31 = V_113 + 1 ;
V_7 = F_89 ( V_51 -> V_44 + V_5 ) ;
V_5 &= ~ V_126 ;
F_45 ( F_86 ( V_7 ) != V_127 ) ;
do {
V_7 = F_16 ( V_7 , V_128 ) ;
V_125 = F_90 ( V_7 ) ;
V_124 = V_125 [ V_5 ] ;
F_91 ( V_125 ) ;
V_109 += ( V_124 & ~ V_112 ) * V_31 ;
V_31 *= ( V_129 + 1 ) ;
} while ( V_124 & V_112 );
V_97:
F_32 ( V_51 , V_34 ) ;
return V_109 ;
}
bool F_92 ( struct V_7 * V_7 , int * V_130 )
{
int V_109 ;
F_93 ( ! F_94 ( V_7 ) , V_7 ) ;
if ( F_52 ( F_95 ( V_7 ) ) )
return false ;
V_109 = F_96 ( V_7 , V_130 ) ;
if ( V_109 <= 1 && F_97 ( V_7 ) ) {
V_109 += F_85 ( V_7 ) ;
if ( V_109 != 1 )
goto V_97;
if ( ! F_98 ( V_7 ) ) {
F_99 ( V_7 ) ;
F_100 ( V_7 ) ;
} else {
T_1 V_6 ;
struct V_3 * V_51 ;
V_6 . V_96 = F_86 ( V_7 ) ;
V_51 = F_72 ( V_6 ) ;
if ( V_51 -> V_27 & V_131 ) {
F_30 ( & V_51 -> V_37 ) ;
return false ;
}
F_30 ( & V_51 -> V_37 ) ;
}
}
V_97:
return V_109 <= 1 ;
}
int F_8 ( struct V_7 * V_7 )
{
F_93 ( ! F_94 ( V_7 ) , V_7 ) ;
if ( ! F_97 ( V_7 ) )
return 0 ;
if ( F_98 ( V_7 ) )
return 0 ;
if ( F_85 ( V_7 ) )
return 0 ;
if ( F_101 () )
return 0 ;
F_99 ( V_7 ) ;
F_100 ( V_7 ) ;
return 1 ;
}
int F_102 ( T_1 V_6 )
{
struct V_3 * V_51 ;
struct V_7 * V_7 = NULL ;
unsigned char V_109 ;
if ( F_103 ( V_6 ) )
return 1 ;
V_51 = F_71 ( V_6 ) ;
if ( V_51 ) {
V_109 = F_74 ( V_51 , V_6 , 1 ) ;
if ( V_109 == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
F_6 ( V_6 ) ) ;
if ( V_7 && ! F_7 ( V_7 ) ) {
F_10 ( V_7 ) ;
V_7 = NULL ;
}
} else if ( ! V_109 )
F_82 ( V_6 ) ;
}
if ( V_7 ) {
if ( F_97 ( V_7 ) && ! F_98 ( V_7 ) &&
( ! F_104 ( V_7 ) || F_105 ( V_7 ) ) ) {
F_99 ( V_7 ) ;
F_100 ( V_7 ) ;
}
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_51 != NULL ;
}
int F_106 ( T_4 V_132 , T_2 V_5 , struct V_133 * * V_134 )
{
struct V_133 * V_17 = NULL ;
int type ;
if ( V_132 )
V_17 = F_107 ( V_132 ) ;
F_28 ( & V_135 ) ;
for ( type = 0 ; type < V_98 ; type ++ ) {
struct V_3 * V_136 = V_95 [ type ] ;
if ( ! ( V_136 -> V_27 & V_53 ) )
continue;
if ( ! V_17 ) {
if ( V_134 )
* V_134 = F_108 ( V_136 -> V_17 ) ;
F_30 ( & V_135 ) ;
return type ;
}
if ( V_17 == V_136 -> V_17 ) {
struct V_9 * V_10 = & V_136 -> V_14 ;
if ( V_10 -> V_11 == V_5 ) {
if ( V_134 )
* V_134 = F_108 ( V_136 -> V_17 ) ;
F_30 ( & V_135 ) ;
F_109 ( V_17 ) ;
return type ;
}
}
}
F_30 ( & V_135 ) ;
if ( V_17 )
F_109 ( V_17 ) ;
return - V_137 ;
}
T_2 F_110 ( int type , T_3 V_5 )
{
struct V_133 * V_17 ;
if ( ( unsigned int ) type >= V_98 )
return 0 ;
if ( ! ( V_95 [ type ] -> V_27 & V_53 ) )
return 0 ;
return F_111 ( F_3 ( type , V_5 ) , & V_17 ) ;
}
unsigned int F_112 ( int type , int free )
{
unsigned int V_31 = 0 ;
F_28 ( & V_135 ) ;
if ( ( unsigned int ) type < V_98 ) {
struct V_3 * V_136 = V_95 [ type ] ;
F_28 ( & V_136 -> V_37 ) ;
if ( V_136 -> V_27 & V_53 ) {
V_31 = V_136 -> V_77 ;
if ( free )
V_31 -= V_136 -> V_78 ;
}
F_30 ( & V_136 -> V_37 ) ;
}
F_30 ( & V_135 ) ;
return V_31 ;
}
static inline int F_113 ( T_5 V_138 , T_5 V_139 )
{
return F_114 ( F_115 ( V_138 ) , V_139 ) ;
}
static int F_116 ( struct V_140 * V_141 , T_6 * V_142 ,
unsigned long V_143 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_144 ;
struct V_145 * V_146 ;
T_7 * V_147 ;
T_5 * V_138 ;
int V_8 = 1 ;
V_144 = V_7 ;
V_7 = F_117 ( V_7 , V_141 , V_143 ) ;
if ( F_52 ( ! V_7 ) )
return - V_148 ;
if ( F_118 ( V_7 , V_141 -> V_149 , V_18 ,
& V_146 , false ) ) {
V_8 = - V_148 ;
goto V_150;
}
V_138 = F_119 ( V_141 -> V_149 , V_142 , V_143 , & V_147 ) ;
if ( F_52 ( ! F_113 ( * V_138 , F_120 ( V_6 ) ) ) ) {
F_121 ( V_7 , V_146 , false ) ;
V_8 = 0 ;
goto V_97;
}
F_122 ( V_141 -> V_149 , V_151 ) ;
F_123 ( V_141 -> V_149 , V_152 ) ;
F_124 ( V_7 ) ;
F_125 ( V_141 -> V_149 , V_143 , V_138 ,
F_126 ( F_127 ( V_7 , V_141 -> V_153 ) ) ) ;
if ( V_7 == V_144 ) {
F_128 ( V_7 , V_141 , V_143 , false ) ;
F_129 ( V_7 , V_146 , true , false ) ;
} else {
F_130 ( V_7 , V_141 , V_143 , false ) ;
F_129 ( V_7 , V_146 , false , false ) ;
F_131 ( V_7 , V_141 ) ;
}
F_81 ( V_6 ) ;
F_132 ( V_7 ) ;
V_97:
F_133 ( V_138 , V_147 ) ;
V_150:
if ( V_7 != V_144 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_8 ;
}
static int F_134 ( struct V_140 * V_141 , T_6 * V_142 ,
unsigned long V_143 , unsigned long V_154 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_139 = F_120 ( V_6 ) ;
T_5 * V_138 ;
int V_8 = 0 ;
V_138 = F_135 ( V_142 , V_143 ) ;
do {
if ( F_52 ( F_113 ( * V_138 , V_139 ) ) ) {
F_136 ( V_138 ) ;
V_8 = F_116 ( V_141 , V_142 , V_143 , V_6 , V_7 ) ;
if ( V_8 )
goto V_97;
V_138 = F_135 ( V_142 , V_143 ) ;
}
} while ( V_138 ++ , V_143 += V_155 , V_143 != V_154 );
F_136 ( V_138 - 1 ) ;
V_97:
return V_8 ;
}
static inline int F_137 ( struct V_140 * V_141 , T_8 * V_156 ,
unsigned long V_143 , unsigned long V_154 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_142 ;
unsigned long V_64 ;
int V_8 ;
V_142 = F_138 ( V_156 , V_143 ) ;
do {
F_13 () ;
V_64 = F_139 ( V_143 , V_154 ) ;
if ( F_140 ( V_142 ) )
continue;
V_8 = F_134 ( V_141 , V_142 , V_143 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_142 ++ , V_143 = V_64 , V_143 != V_154 );
return 0 ;
}
static inline int F_141 ( struct V_140 * V_141 , T_9 * V_157 ,
unsigned long V_143 , unsigned long V_154 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_156 ;
unsigned long V_64 ;
int V_8 ;
V_156 = F_142 ( V_157 , V_143 ) ;
do {
V_64 = F_143 ( V_143 , V_154 ) ;
if ( F_144 ( V_156 ) )
continue;
V_8 = F_137 ( V_141 , V_156 , V_143 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_156 ++ , V_143 = V_64 , V_143 != V_154 );
return 0 ;
}
static inline int F_145 ( struct V_140 * V_141 , T_10 * V_158 ,
unsigned long V_143 , unsigned long V_154 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_157 ;
unsigned long V_64 ;
int V_8 ;
V_157 = F_146 ( V_158 , V_143 ) ;
do {
V_64 = F_147 ( V_143 , V_154 ) ;
if ( F_148 ( V_157 ) )
continue;
V_8 = F_141 ( V_141 , V_157 , V_143 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_157 ++ , V_143 = V_64 , V_143 != V_154 );
return 0 ;
}
static int F_149 ( struct V_140 * V_141 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_10 * V_158 ;
unsigned long V_143 , V_154 , V_64 ;
int V_8 ;
if ( F_150 ( V_7 ) ) {
V_143 = F_151 ( V_7 , V_141 ) ;
if ( V_143 == - V_159 )
return 0 ;
else
V_154 = V_143 + V_155 ;
} else {
V_143 = V_141 -> V_160 ;
V_154 = V_141 -> V_161 ;
}
V_158 = F_152 ( V_141 -> V_149 , V_143 ) ;
do {
V_64 = F_153 ( V_143 , V_154 ) ;
if ( F_154 ( V_158 ) )
continue;
V_8 = F_145 ( V_141 , V_158 , V_143 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_158 ++ , V_143 = V_64 , V_143 != V_154 );
return 0 ;
}
static int F_155 ( struct V_162 * V_163 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_140 * V_141 ;
int V_8 = 0 ;
if ( ! F_156 ( & V_163 -> V_164 ) ) {
F_132 ( V_7 ) ;
F_9 ( V_7 ) ;
F_157 ( & V_163 -> V_164 ) ;
F_158 ( V_7 ) ;
}
for ( V_141 = V_163 -> V_165 ; V_141 ; V_141 = V_141 -> V_166 ) {
if ( V_141 -> V_167 && ( V_8 = F_149 ( V_141 , V_6 , V_7 ) ) )
break;
F_13 () ;
}
F_159 ( & V_163 -> V_164 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_160 ( struct V_3 * V_4 ,
unsigned int V_122 , bool V_168 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_123 = V_122 ;
unsigned char V_109 ;
for (; ; ) {
if ( ++ V_123 >= V_62 ) {
if ( ! V_122 ) {
V_123 = 0 ;
break;
}
V_62 = V_122 + 1 ;
V_122 = 0 ;
V_123 = 1 ;
}
V_109 = F_161 ( V_4 -> V_44 [ V_123 ] ) ;
if ( V_109 && F_1 ( V_109 ) != V_45 )
if ( ! V_168 || F_162 ( V_4 , V_123 ) )
break;
if ( ( V_123 % V_70 ) == 0 )
F_13 () ;
}
return V_123 ;
}
int F_163 ( unsigned int type , bool V_168 ,
unsigned long V_169 )
{
struct V_3 * V_4 = V_95 [ type ] ;
struct V_162 * V_170 ;
volatile unsigned char * V_44 ;
unsigned char V_171 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_123 = 0 ;
int V_172 = 0 ;
V_170 = & V_173 ;
F_164 ( & V_173 ) ;
while ( ( V_123 = F_160 ( V_4 , V_123 , V_168 ) ) != 0 ) {
if ( F_165 ( V_174 ) ) {
V_172 = - V_175 ;
break;
}
V_44 = & V_4 -> V_44 [ V_123 ] ;
V_6 = F_3 ( type , V_123 ) ;
V_7 = F_166 ( V_6 ,
V_176 , NULL , 0 ) ;
if ( ! V_7 ) {
V_171 = * V_44 ;
if ( ! V_171 || V_171 == V_45 )
continue;
V_172 = - V_148 ;
break;
}
if ( F_167 ( & V_170 -> V_177 ) == 1 ) {
F_168 ( V_170 ) ;
V_170 = & V_173 ;
F_164 ( & V_173 ) ;
}
F_169 ( V_7 ) ;
F_170 ( V_7 ) ;
F_158 ( V_7 ) ;
F_170 ( V_7 ) ;
V_171 = * V_44 ;
if ( F_1 ( V_171 ) == V_111 ) {
V_172 = F_171 ( V_6 , V_7 ) ;
if ( V_172 < 0 )
break;
continue;
}
if ( F_1 ( V_171 ) && V_170 != & V_173 )
V_172 = F_155 ( V_170 , V_6 , V_7 ) ;
if ( F_1 ( * V_44 ) ) {
int V_178 = ( * V_44 >= V_171 ) ;
struct V_179 * V_51 = & V_170 -> V_180 ;
struct V_162 * V_181 = V_170 ;
struct V_162 * V_182 = V_170 ;
struct V_162 * V_163 ;
F_164 ( V_181 ) ;
F_164 ( V_182 ) ;
F_28 ( & V_183 ) ;
while ( F_1 ( * V_44 ) && ! V_172 &&
( V_51 = V_51 -> V_64 ) != & V_170 -> V_180 ) {
V_163 = F_172 ( V_51 , struct V_162 , V_180 ) ;
if ( ! F_173 ( V_163 ) )
continue;
F_30 ( & V_183 ) ;
F_168 ( V_182 ) ;
V_182 = V_163 ;
F_13 () ;
V_171 = * V_44 ;
if ( ! F_1 ( V_171 ) )
;
else if ( V_163 == & V_173 )
V_178 = 1 ;
else
V_172 = F_155 ( V_163 , V_6 , V_7 ) ;
if ( V_178 && * V_44 < V_171 ) {
F_168 ( V_181 ) ;
F_164 ( V_163 ) ;
V_181 = V_163 ;
V_178 = 0 ;
}
F_28 ( & V_183 ) ;
}
F_30 ( & V_183 ) ;
F_168 ( V_182 ) ;
F_168 ( V_170 ) ;
V_170 = V_181 ;
}
if ( V_172 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
break;
}
if ( F_1 ( * V_44 ) &&
F_174 ( V_7 ) && F_97 ( V_7 ) ) {
struct V_184 V_185 = {
. V_186 = V_187 ,
} ;
F_175 ( V_7 , & V_185 ) ;
F_158 ( V_7 ) ;
F_170 ( V_7 ) ;
}
if ( F_97 ( V_7 ) &&
F_176 ( F_86 ( V_7 ) == V_6 . V_96 ) )
F_99 ( V_7 ) ;
F_100 ( V_7 ) ;
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
F_13 () ;
if ( V_168 && V_169 > 0 ) {
if ( ! -- V_169 )
break;
}
}
F_168 ( V_170 ) ;
return V_172 ;
}
static void F_177 ( void )
{
struct V_179 * V_51 , * V_64 ;
unsigned int type ;
for ( type = 0 ; type < V_98 ; type ++ )
if ( V_95 [ type ] -> V_78 )
return;
F_28 ( & V_183 ) ;
F_178 (p, next, &init_mm.mmlist)
F_179 ( V_51 ) ;
F_30 ( & V_183 ) ;
}
static T_2 F_111 ( T_1 V_6 , struct V_133 * * V_17 )
{
struct V_3 * V_136 ;
struct V_9 * V_188 ;
struct V_9 * V_10 ;
T_3 V_5 ;
V_136 = V_95 [ F_69 ( V_6 ) ] ;
* V_17 = V_136 -> V_17 ;
V_5 = F_6 ( V_6 ) ;
V_188 = V_136 -> V_20 ;
V_10 = V_188 ;
for ( ; ; ) {
if ( V_10 -> V_19 <= V_5 &&
V_5 < ( V_10 -> V_19 + V_10 -> V_16 ) ) {
return V_10 -> V_11 + ( V_5 - V_10 -> V_19 ) ;
}
V_10 = F_16 ( V_10 , V_23 ) ;
V_136 -> V_20 = V_10 ;
F_180 ( V_10 == V_188 ) ;
}
}
T_2 F_181 ( struct V_7 * V_7 , struct V_133 * * V_17 )
{
T_1 V_6 ;
V_6 . V_96 = F_86 ( V_7 ) ;
return F_111 ( V_6 , V_17 ) ;
}
static void F_182 ( struct V_3 * V_136 )
{
while ( ! F_183 ( & V_136 -> V_14 . V_23 ) ) {
struct V_9 * V_10 ;
V_10 = F_184 ( & V_136 -> V_14 . V_23 ,
struct V_9 , V_23 ) ;
F_185 ( & V_10 -> V_23 ) ;
F_186 ( V_10 ) ;
}
if ( V_136 -> V_27 & V_189 ) {
struct V_190 * V_191 = V_136 -> V_191 ;
struct V_192 * V_193 = V_191 -> V_194 ;
V_136 -> V_27 &= ~ V_189 ;
V_193 -> V_195 -> V_196 ( V_191 ) ;
}
}
int
F_187 ( struct V_3 * V_136 , unsigned long V_19 ,
unsigned long V_16 , T_2 V_11 )
{
struct V_9 * V_10 ;
struct V_9 * V_197 ;
struct V_179 * V_198 ;
if ( V_19 == 0 ) {
V_10 = & V_136 -> V_14 ;
V_136 -> V_20 = V_10 ;
V_10 -> V_19 = 0 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_11 = V_11 ;
return 1 ;
} else {
V_198 = V_136 -> V_14 . V_23 . V_122 ;
V_10 = F_172 ( V_198 , struct V_9 , V_23 ) ;
F_180 ( V_10 -> V_19 + V_10 -> V_16 != V_19 ) ;
if ( V_10 -> V_11 + V_10 -> V_16 == V_11 ) {
V_10 -> V_16 += V_16 ;
return 0 ;
}
}
V_197 = F_188 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_197 == NULL )
return - V_148 ;
V_197 -> V_19 = V_19 ;
V_197 -> V_16 = V_16 ;
V_197 -> V_11 = V_11 ;
F_189 ( & V_197 -> V_23 , & V_136 -> V_14 . V_23 ) ;
return 1 ;
}
static int F_190 ( struct V_3 * V_136 , T_2 * V_199 )
{
struct V_190 * V_191 = V_136 -> V_191 ;
struct V_192 * V_193 = V_191 -> V_194 ;
struct V_200 * V_200 = V_193 -> V_201 ;
int V_8 ;
if ( F_191 ( V_200 -> V_202 ) ) {
V_8 = F_187 ( V_136 , 0 , V_136 -> V_62 , 0 ) ;
* V_199 = V_136 -> V_77 ;
return V_8 ;
}
if ( V_193 -> V_195 -> V_203 ) {
V_8 = V_193 -> V_195 -> V_203 ( V_136 , V_191 , V_199 ) ;
if ( ! V_8 ) {
V_136 -> V_27 |= V_189 ;
V_8 = F_187 ( V_136 , 0 , V_136 -> V_62 , 0 ) ;
* V_199 = V_136 -> V_77 ;
}
return V_8 ;
}
return F_192 ( V_136 , V_191 , V_199 ) ;
}
static void F_193 ( struct V_3 * V_51 , int V_204 ,
unsigned char * V_44 ,
struct V_24 * V_35 )
{
if ( V_204 >= 0 )
V_51 -> V_204 = V_204 ;
else
V_51 -> V_204 = -- V_205 ;
V_51 -> V_23 . V_204 = - V_51 -> V_204 ;
V_51 -> V_85 . V_204 = - V_51 -> V_204 ;
V_51 -> V_44 = V_44 ;
V_51 -> V_35 = V_35 ;
V_51 -> V_27 |= V_53 ;
F_64 ( V_51 -> V_77 , & V_90 ) ;
V_206 += V_51 -> V_77 ;
F_194 ( & V_135 ) ;
F_79 ( & V_51 -> V_23 , & V_207 ) ;
F_28 ( & V_84 ) ;
F_79 ( & V_51 -> V_85 , & V_86 ) ;
F_30 ( & V_84 ) ;
}
static void F_195 ( struct V_3 * V_51 , int V_204 ,
unsigned char * V_44 ,
struct V_24 * V_35 ,
unsigned long * V_208 )
{
F_196 ( V_51 -> type , V_208 ) ;
F_28 ( & V_135 ) ;
F_28 ( & V_51 -> V_37 ) ;
F_193 ( V_51 , V_204 , V_44 , V_35 ) ;
F_30 ( & V_51 -> V_37 ) ;
F_30 ( & V_135 ) ;
}
static void F_197 ( struct V_3 * V_51 )
{
F_28 ( & V_135 ) ;
F_28 ( & V_51 -> V_37 ) ;
F_193 ( V_51 , V_51 -> V_204 , V_51 -> V_44 , V_51 -> V_35 ) ;
F_30 ( & V_51 -> V_37 ) ;
F_30 ( & V_135 ) ;
}
bool F_198 ( void )
{
bool V_8 = true ;
F_28 ( & V_135 ) ;
if ( F_199 ( & V_207 ) )
V_8 = false ;
F_30 ( & V_135 ) ;
return V_8 ;
}
static unsigned F_200 ( struct V_190 * V_190 , T_11 * V_209 )
{
struct V_210 * V_211 = V_190 -> V_212 ;
F_201 ( V_190 , & V_213 , V_209 ) ;
if ( V_211 -> V_214 != F_167 ( & V_215 ) ) {
V_211 -> V_214 = F_167 ( & V_215 ) ;
return V_216 | V_217 | V_218 | V_219 ;
}
return V_216 | V_217 ;
}
static void * F_202 ( struct V_210 * V_220 , T_12 * V_221 )
{
struct V_3 * V_4 ;
int type ;
T_12 V_222 = * V_221 ;
F_203 ( & V_223 ) ;
if ( ! V_222 )
return V_224 ;
for ( type = 0 ; type < V_98 ; type ++ ) {
F_204 () ;
V_4 = V_95 [ type ] ;
if ( ! ( V_4 -> V_27 & V_100 ) || ! V_4 -> V_44 )
continue;
if ( ! -- V_222 )
return V_4 ;
}
return NULL ;
}
static void * F_205 ( struct V_210 * V_220 , void * V_225 , T_12 * V_221 )
{
struct V_3 * V_4 = V_225 ;
int type ;
if ( V_225 == V_224 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_98 ; type ++ ) {
F_204 () ;
V_4 = V_95 [ type ] ;
if ( ! ( V_4 -> V_27 & V_100 ) || ! V_4 -> V_44 )
continue;
++ * V_221 ;
return V_4 ;
}
return NULL ;
}
static void F_206 ( struct V_210 * V_220 , void * V_225 )
{
F_207 ( & V_223 ) ;
}
static int F_208 ( struct V_210 * V_220 , void * V_225 )
{
struct V_3 * V_4 = V_225 ;
struct V_190 * V_190 ;
int V_226 ;
if ( V_4 == V_224 ) {
F_209 ( V_220 , L_5 ) ;
return 0 ;
}
V_190 = V_4 -> V_191 ;
V_226 = F_210 ( V_220 , V_190 , L_6 ) ;
F_211 ( V_220 , L_7 ,
V_226 < 40 ? 40 - V_226 : 1 , L_8 ,
F_191 ( F_212 ( V_190 ) -> V_202 ) ?
L_9 : L_10 ,
V_4 -> V_77 << ( V_15 - 10 ) ,
V_4 -> V_78 << ( V_15 - 10 ) ,
V_4 -> V_204 ) ;
return 0 ;
}
static int F_213 ( struct V_200 * V_200 , struct V_190 * V_190 )
{
struct V_210 * V_211 ;
int V_8 ;
V_8 = F_214 ( V_190 , & V_227 ) ;
if ( V_8 )
return V_8 ;
V_211 = V_190 -> V_212 ;
V_211 -> V_214 = F_167 ( & V_215 ) ;
return 0 ;
}
static int T_13 F_215 ( void )
{
F_216 ( L_11 , 0 , NULL , & V_228 ) ;
return 0 ;
}
static int T_13 F_217 ( void )
{
F_218 () ;
return 0 ;
}
static struct V_3 * F_219 ( void )
{
struct V_3 * V_51 ;
unsigned int type ;
V_51 = F_220 ( sizeof( * V_51 ) , V_18 ) ;
if ( ! V_51 )
return F_221 ( - V_148 ) ;
F_28 ( & V_135 ) ;
for ( type = 0 ; type < V_98 ; type ++ ) {
if ( ! ( V_95 [ type ] -> V_27 & V_100 ) )
break;
}
if ( type >= V_229 ) {
F_30 ( & V_135 ) ;
F_186 ( V_51 ) ;
return F_221 ( - V_230 ) ;
}
if ( type >= V_98 ) {
V_51 -> type = type ;
V_95 [ type ] = V_51 ;
F_222 () ;
V_98 ++ ;
} else {
F_186 ( V_51 ) ;
V_51 = V_95 [ type ] ;
}
F_223 ( & V_51 -> V_14 . V_23 ) ;
F_224 ( & V_51 -> V_23 , 0 ) ;
F_224 ( & V_51 -> V_85 , 0 ) ;
V_51 -> V_27 = V_100 ;
F_30 ( & V_135 ) ;
F_225 ( & V_51 -> V_37 ) ;
return V_51 ;
}
static int F_226 ( struct V_3 * V_51 , struct V_200 * V_200 )
{
int error ;
if ( F_191 ( V_200 -> V_202 ) ) {
V_51 -> V_17 = F_108 ( F_227 ( V_200 ) ) ;
error = F_228 ( V_51 -> V_17 ,
V_231 | V_232 | V_233 , V_51 ) ;
if ( error < 0 ) {
V_51 -> V_17 = NULL ;
return error ;
}
V_51 -> V_234 = F_229 ( V_51 -> V_17 ) ;
error = F_230 ( V_51 -> V_17 , V_155 ) ;
if ( error < 0 )
return error ;
V_51 -> V_27 |= V_115 ;
} else if ( F_231 ( V_200 -> V_202 ) ) {
V_51 -> V_17 = V_200 -> V_235 -> V_236 ;
F_232 ( V_200 ) ;
if ( F_233 ( V_200 ) )
return - V_237 ;
} else
return - V_238 ;
return 0 ;
}
static unsigned long F_234 ( struct V_3 * V_51 ,
union V_239 * V_239 ,
struct V_200 * V_200 )
{
int V_123 ;
unsigned long V_240 ;
unsigned long V_241 ;
unsigned long V_242 ;
if ( memcmp ( L_12 , V_239 -> V_243 . V_243 , 10 ) ) {
F_70 ( L_13 ) ;
return 0 ;
}
if ( F_235 ( V_239 -> V_25 . V_244 ) == 1 ) {
F_236 ( & V_239 -> V_25 . V_244 ) ;
F_236 ( & V_239 -> V_25 . V_242 ) ;
F_236 ( & V_239 -> V_25 . V_245 ) ;
if ( V_239 -> V_25 . V_245 > V_246 )
return 0 ;
for ( V_123 = 0 ; V_123 < V_239 -> V_25 . V_245 ; V_123 ++ )
F_236 ( & V_239 -> V_25 . V_247 [ V_123 ] ) ;
}
if ( V_239 -> V_25 . V_244 != 1 ) {
F_237 ( L_14 ,
V_239 -> V_25 . V_244 ) ;
return 0 ;
}
V_51 -> V_79 = 1 ;
V_51 -> F_21 = 1 ;
V_51 -> V_76 = 0 ;
V_240 = F_6 ( F_238 (
F_120 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_242 = V_239 -> V_25 . V_242 ;
if ( V_242 > V_240 ) {
F_237 ( L_15 ,
V_240 << ( V_15 - 10 ) ,
V_242 << ( V_15 - 10 ) ) ;
}
if ( V_240 > V_242 ) {
V_240 = V_242 + 1 ;
if ( ( unsigned int ) V_240 == 0 )
V_240 = V_248 ;
}
V_51 -> V_80 = V_240 - 1 ;
if ( ! V_240 )
return 0 ;
V_241 = F_239 ( V_200 ) >> V_15 ;
if ( V_241 && V_240 > V_241 ) {
F_237 ( L_16 ) ;
return 0 ;
}
if ( V_239 -> V_25 . V_245 && F_231 ( V_200 -> V_202 ) )
return 0 ;
if ( V_239 -> V_25 . V_245 > V_246 )
return 0 ;
return V_240 ;
}
static int F_240 ( struct V_3 * V_51 ,
union V_239 * V_239 ,
unsigned char * V_44 ,
struct V_24 * V_35 ,
unsigned long V_240 ,
T_2 * V_199 )
{
unsigned int V_249 , V_250 ;
unsigned int V_251 ;
int V_252 ;
unsigned long V_253 = F_241 ( V_240 , V_36 ) ;
unsigned long V_254 = V_51 -> F_21 / V_36 % V_255 ;
unsigned long V_123 , V_41 ;
V_251 = V_240 - 1 ;
F_35 ( & V_51 -> V_48 ) ;
F_35 ( & V_51 -> V_46 ) ;
for ( V_123 = 0 ; V_123 < V_239 -> V_25 . V_245 ; V_123 ++ ) {
unsigned int V_52 = V_239 -> V_25 . V_247 [ V_123 ] ;
if ( V_52 == 0 || V_52 > V_239 -> V_25 . V_242 )
return - V_238 ;
if ( V_52 < V_240 ) {
V_44 [ V_52 ] = V_45 ;
V_251 -- ;
F_44 ( V_51 , V_35 , V_52 ) ;
}
}
for ( V_123 = V_240 ; V_123 < F_242 ( V_240 , V_36 ) ; V_123 ++ )
F_44 ( V_51 , V_35 , V_123 ) ;
if ( V_251 ) {
V_44 [ 0 ] = V_45 ;
F_44 ( V_51 , V_35 , 0 ) ;
V_51 -> V_62 = V_240 ;
V_51 -> V_77 = V_251 ;
V_252 = F_190 ( V_51 , V_199 ) ;
if ( V_252 < 0 )
return V_252 ;
V_251 = V_51 -> V_77 ;
}
if ( ! V_251 ) {
F_237 ( L_17 ) ;
return - V_238 ;
}
if ( ! V_35 )
return V_252 ;
for ( V_250 = 0 ; V_250 < V_255 ; V_250 ++ ) {
V_249 = ( V_250 + V_254 ) % V_255 ;
for ( V_123 = 0 ; V_123 < F_241 ( V_253 , V_255 ) ; V_123 ++ ) {
V_41 = V_123 * V_255 + V_249 ;
if ( V_41 >= V_253 )
continue;
if ( F_18 ( & V_35 [ V_41 ] ) )
continue;
F_17 ( & V_35 [ V_41 ] , V_32 ) ;
F_36 ( & V_51 -> V_48 , V_35 ,
V_41 ) ;
}
}
return V_252 ;
}
static bool F_243 ( struct V_3 * V_4 )
{
struct V_256 * V_108 = F_244 ( V_4 -> V_17 ) ;
if ( ! V_108 || ! F_245 ( V_108 ) )
return false ;
return true ;
}
void F_246 ( struct V_257 * V_96 )
{
unsigned int type ;
unsigned long V_258 = 0 ;
F_28 ( & V_135 ) ;
for ( type = 0 ; type < V_98 ; type ++ ) {
struct V_3 * V_4 = V_95 [ type ] ;
if ( ( V_4 -> V_27 & V_100 ) && ! ( V_4 -> V_27 & V_53 ) )
V_258 += V_4 -> V_78 ;
}
V_96 -> V_259 = F_57 ( & V_90 ) + V_258 ;
V_96 -> V_260 = V_206 + V_258 ;
F_30 ( & V_135 ) ;
}
static int F_247 ( T_1 V_6 , unsigned char V_65 )
{
struct V_3 * V_51 ;
struct V_24 * V_34 ;
unsigned long V_5 , type ;
unsigned char V_109 ;
unsigned char V_110 ;
int V_13 = - V_238 ;
if ( F_103 ( V_6 ) )
goto V_97;
type = F_69 ( V_6 ) ;
if ( type >= V_98 )
goto V_261;
V_51 = V_95 [ type ] ;
V_5 = F_6 ( V_6 ) ;
if ( F_52 ( V_5 >= V_51 -> V_62 ) )
goto V_97;
V_34 = F_31 ( V_51 , V_5 ) ;
V_109 = V_51 -> V_44 [ V_5 ] ;
if ( F_52 ( F_1 ( V_109 ) == V_45 ) ) {
V_13 = - V_262 ;
goto V_263;
}
V_110 = V_109 & V_2 ;
V_109 &= ~ V_2 ;
V_13 = 0 ;
if ( V_65 == V_2 ) {
if ( ! V_110 && V_109 )
V_110 = V_2 ;
else if ( V_110 )
V_13 = - V_264 ;
else
V_13 = - V_262 ;
} else if ( V_109 || V_110 ) {
if ( ( V_109 & ~ V_112 ) < V_113 )
V_109 += V_65 ;
else if ( ( V_109 & ~ V_112 ) > V_113 )
V_13 = - V_238 ;
else if ( F_75 ( V_51 , V_5 , V_109 ) )
V_109 = V_112 ;
else
V_13 = - V_148 ;
} else
V_13 = - V_262 ;
V_51 -> V_44 [ V_5 ] = V_109 | V_110 ;
V_263:
F_32 ( V_51 , V_34 ) ;
V_97:
return V_13 ;
V_261:
F_70 ( L_18 , V_105 , V_6 . V_96 ) ;
goto V_97;
}
void F_248 ( T_1 V_6 )
{
F_247 ( V_6 , V_111 ) ;
}
int F_249 ( T_1 V_6 )
{
int V_13 = 0 ;
while ( ! V_13 && F_247 ( V_6 , 1 ) == - V_148 )
V_13 = F_250 ( V_6 , V_265 ) ;
return V_13 ;
}
int F_251 ( T_1 V_6 )
{
return F_247 ( V_6 , V_2 ) ;
}
struct V_3 * F_252 ( struct V_7 * V_7 )
{
T_1 V_220 = { . V_96 = F_86 (page) } ;
return V_95 [ F_69 ( V_220 ) ] ;
}
struct V_192 * F_253 ( struct V_7 * V_7 )
{
F_93 ( ! F_97 ( V_7 ) , V_7 ) ;
return F_252 ( V_7 ) -> V_191 -> V_194 ;
}
T_3 F_254 ( struct V_7 * V_7 )
{
T_1 V_220 = { . V_96 = F_86 (page) } ;
F_93 ( ! F_97 ( V_7 ) , V_7 ) ;
return F_6 ( V_220 ) ;
}
int F_250 ( T_1 V_6 , T_14 V_266 )
{
struct V_3 * V_4 ;
struct V_24 * V_34 ;
struct V_7 * V_39 ;
struct V_7 * V_7 ;
struct V_7 * V_267 ;
T_3 V_5 ;
unsigned char V_109 ;
V_7 = F_255 ( V_266 | V_268 ) ;
V_4 = F_72 ( V_6 ) ;
if ( ! V_4 ) {
goto V_269;
}
V_5 = F_6 ( V_6 ) ;
V_34 = F_27 ( V_4 , V_5 ) ;
V_109 = V_4 -> V_44 [ V_5 ] & ~ V_2 ;
if ( ( V_109 & ~ V_112 ) != V_113 ) {
goto V_97;
}
if ( ! V_7 ) {
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
return - V_148 ;
}
V_39 = F_89 ( V_4 -> V_44 + V_5 ) ;
V_5 &= ~ V_126 ;
if ( ! F_86 ( V_39 ) ) {
F_180 ( V_109 & V_112 ) ;
F_223 ( & V_39 -> V_128 ) ;
F_256 ( V_39 , V_127 ) ;
V_4 -> V_27 |= V_127 ;
}
F_14 (list_page, &head->lru, lru) {
unsigned char * V_125 ;
if ( ! ( V_109 & V_112 ) )
goto V_97;
V_125 = F_90 ( V_267 ) + V_5 ;
V_109 = * V_125 ;
F_91 ( V_125 ) ;
if ( ( V_109 & ~ V_112 ) != V_129 )
goto V_97;
}
F_189 ( & V_7 -> V_128 , & V_39 -> V_128 ) ;
V_7 = NULL ;
V_97:
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
V_269:
if ( V_7 )
F_257 ( V_7 ) ;
return 0 ;
}
static bool F_75 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_109 )
{
struct V_7 * V_39 ;
struct V_7 * V_7 ;
unsigned char * V_125 ;
V_39 = F_89 ( V_4 -> V_44 + V_5 ) ;
if ( F_86 ( V_39 ) != V_127 ) {
F_180 ( V_109 & V_112 ) ;
return false ;
}
V_5 &= ~ V_126 ;
V_7 = F_172 ( V_39 -> V_128 . V_64 , struct V_7 , V_128 ) ;
V_125 = F_90 ( V_7 ) + V_5 ;
if ( V_109 == V_113 )
goto V_270;
if ( V_109 == ( V_113 | V_112 ) ) {
while ( * V_125 == ( V_129 | V_112 ) ) {
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_64 , struct V_7 , V_128 ) ;
F_180 ( V_7 == V_39 ) ;
V_125 = F_90 ( V_7 ) + V_5 ;
}
if ( * V_125 == V_129 ) {
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_64 , struct V_7 , V_128 ) ;
if ( V_7 == V_39 )
return false ;
V_125 = F_90 ( V_7 ) + V_5 ;
V_270: * V_125 = 0 ;
}
* V_125 += 1 ;
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_122 , struct V_7 , V_128 ) ;
while ( V_7 != V_39 ) {
V_125 = F_90 ( V_7 ) + V_5 ;
* V_125 = V_112 ;
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_122 , struct V_7 , V_128 ) ;
}
return true ;
} else {
F_180 ( V_109 != V_112 ) ;
while ( * V_125 == V_112 ) {
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_64 , struct V_7 , V_128 ) ;
F_180 ( V_7 == V_39 ) ;
V_125 = F_90 ( V_7 ) + V_5 ;
}
F_180 ( * V_125 == 0 ) ;
* V_125 -= 1 ;
if ( * V_125 == 0 )
V_109 = 0 ;
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_122 , struct V_7 , V_128 ) ;
while ( V_7 != V_39 ) {
V_125 = F_90 ( V_7 ) + V_5 ;
* V_125 = V_129 | V_109 ;
V_109 = V_112 ;
F_91 ( V_125 ) ;
V_7 = F_172 ( V_7 -> V_128 . V_122 , struct V_7 , V_128 ) ;
}
return V_109 == V_112 ;
}
}
static void F_258 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_155 ) {
struct V_7 * V_39 ;
V_39 = F_89 ( V_4 -> V_44 + V_5 ) ;
if ( F_86 ( V_39 ) ) {
struct V_7 * V_7 , * V_64 ;
F_259 (page, next, &head->lru, lru) {
F_185 ( & V_7 -> V_128 ) ;
F_257 ( V_7 ) ;
}
}
}
}
