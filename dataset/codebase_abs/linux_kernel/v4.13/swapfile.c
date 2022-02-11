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
F_30 ( & V_42 -> V_37 ) ;
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
static void F_41 ( struct V_3 * V_4 , unsigned long V_41 )
{
struct V_24 * V_34 = V_4 -> V_35 ;
F_17 ( V_34 + V_41 , V_32 ) ;
F_36 ( & V_4 -> V_48 , V_34 , V_41 ) ;
}
static void F_42 ( struct V_3 * V_4 )
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
F_41 ( V_4 , V_41 ) ;
memset ( V_4 -> V_44 + V_41 * V_36 ,
0 , V_36 ) ;
F_29 ( V_34 ) ;
}
}
static void F_43 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
V_4 = F_44 ( V_50 , struct V_3 , V_47 ) ;
F_28 ( & V_4 -> V_37 ) ;
F_42 ( V_4 ) ;
F_30 ( & V_4 -> V_37 ) ;
}
static void F_45 ( struct V_3 * V_4 , unsigned long V_41 )
{
struct V_24 * V_34 = V_4 -> V_35 ;
F_46 ( F_34 ( & V_4 -> V_48 ) != V_41 ) ;
F_38 ( & V_4 -> V_48 , V_34 ) ;
F_20 ( V_34 + V_41 , 0 , 0 ) ;
}
static void F_47 ( struct V_3 * V_4 , unsigned long V_41 )
{
struct V_24 * V_34 = V_4 -> V_35 + V_41 ;
F_46 ( F_18 ( V_34 ) != 0 ) ;
if ( ( V_4 -> V_27 & ( V_51 | V_52 ) ) ==
( V_51 | V_52 ) ) {
F_39 ( V_4 , V_41 ) ;
return;
}
F_41 ( V_4 , V_41 ) ;
}
static void F_48 ( struct V_3 * V_53 ,
struct V_24 * V_35 , unsigned long V_54 )
{
unsigned long V_41 = V_54 / V_36 ;
if ( ! V_35 )
return;
if ( F_24 ( & V_35 [ V_41 ] ) )
F_45 ( V_53 , V_41 ) ;
F_46 ( F_18 ( & V_35 [ V_41 ] ) >= V_36 ) ;
F_19 ( & V_35 [ V_41 ] ,
F_18 ( & V_35 [ V_41 ] ) + 1 ) ;
}
static void F_49 ( struct V_3 * V_53 ,
struct V_24 * V_35 , unsigned long V_54 )
{
unsigned long V_41 = V_54 / V_36 ;
if ( ! V_35 )
return;
F_46 ( F_18 ( & V_35 [ V_41 ] ) == 0 ) ;
F_19 ( & V_35 [ V_41 ] ,
F_18 ( & V_35 [ V_41 ] ) - 1 ) ;
if ( F_18 ( & V_35 [ V_41 ] ) == 0 )
F_47 ( V_53 , V_41 ) ;
}
static bool
F_50 ( struct V_3 * V_4 ,
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
V_55 = F_51 ( V_4 -> V_55 ) ;
F_26 ( & V_55 -> V_57 ) ;
return true ;
}
static bool F_52 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_58 )
{
struct V_55 * V_59 ;
struct V_24 * V_34 ;
bool V_60 ;
unsigned long V_61 , V_62 ;
V_63:
V_59 = F_51 ( V_4 -> V_55 ) ;
if ( F_25 ( & V_59 -> V_57 ) ) {
if ( ! F_33 ( & V_4 -> V_48 ) ) {
V_59 -> V_57 = V_4 -> V_48 . V_39 ;
V_59 -> V_64 = F_21 ( & V_59 -> V_57 ) *
V_36 ;
} else if ( ! F_33 ( & V_4 -> V_46 ) ) {
F_42 ( V_4 ) ;
* V_58 = * V_5 = V_4 -> F_21 ;
goto V_63;
} else
return false ;
}
V_60 = false ;
V_61 = V_59 -> V_64 ;
V_62 = F_53 (unsigned long, si->max,
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
static void F_54 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned int V_65 )
{
unsigned int V_66 = V_5 + V_65 - 1 ;
if ( V_5 == V_4 -> V_67 )
V_4 -> V_67 += V_65 ;
if ( V_66 == V_4 -> V_68 )
V_4 -> V_68 -= V_65 ;
V_4 -> V_69 += V_65 ;
if ( V_4 -> V_69 == V_4 -> V_70 ) {
V_4 -> V_67 = V_4 -> V_62 ;
V_4 -> V_68 = 0 ;
F_28 ( & V_71 ) ;
F_55 ( & V_4 -> V_72 , & V_73 ) ;
F_30 ( & V_71 ) ;
}
}
static void F_56 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned int V_65 )
{
unsigned long V_66 = V_5 + V_65 - 1 ;
void (* F_57)( struct V_74 * , unsigned long );
if ( V_5 < V_4 -> V_67 )
V_4 -> V_67 = V_5 ;
if ( V_66 > V_4 -> V_68 ) {
bool V_75 = ! V_4 -> V_68 ;
V_4 -> V_68 = V_66 ;
if ( V_75 && ( V_4 -> V_27 & V_51 ) ) {
F_28 ( & V_71 ) ;
F_58 ( ! F_59 ( & V_4 -> V_72 ) ) ;
if ( F_59 ( & V_4 -> V_72 ) )
F_60 ( & V_4 -> V_72 , & V_73 ) ;
F_30 ( & V_71 ) ;
}
}
F_61 ( V_65 , & V_76 ) ;
V_4 -> V_69 -= V_65 ;
if ( V_4 -> V_27 & V_77 )
F_57 =
V_4 -> V_17 -> V_78 -> V_79 -> F_57 ;
else
F_57 = NULL ;
while ( V_5 <= V_66 ) {
F_62 ( V_4 -> type , V_5 ) ;
if ( F_57 )
F_57 ( V_4 -> V_17 , V_5 ) ;
V_5 ++ ;
}
}
static int F_63 ( struct V_3 * V_4 ,
unsigned char V_80 , int V_81 ,
T_1 V_82 [] )
{
struct V_24 * V_34 ;
unsigned long V_5 ;
unsigned long V_58 ;
unsigned long V_83 = 0 ;
int V_84 = V_85 ;
int V_86 = 0 ;
if ( V_81 > V_87 )
V_81 = V_87 ;
V_4 -> V_27 += V_88 ;
V_58 = V_5 = V_4 -> F_21 ;
if ( V_4 -> V_35 ) {
if ( F_52 ( V_4 , & V_5 , & V_58 ) )
goto V_89;
else
goto V_90;
}
if ( F_64 ( ! V_4 -> V_91 -- ) ) {
if ( V_4 -> V_70 - V_4 -> V_69 < V_36 ) {
V_4 -> V_91 = V_36 - 1 ;
goto V_89;
}
F_30 ( & V_4 -> V_37 ) ;
V_58 = V_5 = V_4 -> V_67 ;
V_83 = V_5 + V_36 - 1 ;
for (; V_83 <= V_4 -> V_68 ; V_5 ++ ) {
if ( V_4 -> V_44 [ V_5 ] )
V_83 = V_5 + V_36 ;
else if ( V_5 == V_83 ) {
F_28 ( & V_4 -> V_37 ) ;
V_5 -= V_36 - 1 ;
V_4 -> F_21 = V_5 ;
V_4 -> V_91 = V_36 - 1 ;
goto V_89;
}
if ( F_64 ( -- V_84 < 0 ) ) {
F_13 () ;
V_84 = V_85 ;
}
}
V_5 = V_58 ;
F_28 ( & V_4 -> V_37 ) ;
V_4 -> V_91 = V_36 - 1 ;
}
V_89:
if ( V_4 -> V_35 ) {
while ( F_50 ( V_4 , V_5 ) ) {
if ( V_86 )
goto V_92;
if ( ! F_52 ( V_4 , & V_5 ,
& V_58 ) )
goto V_90;
}
}
if ( ! ( V_4 -> V_27 & V_51 ) )
goto V_93;
if ( ! V_4 -> V_68 )
goto V_93;
if ( V_5 > V_4 -> V_68 )
V_58 = V_5 = V_4 -> V_67 ;
V_34 = F_27 ( V_4 , V_5 ) ;
if ( F_65 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
int V_94 ;
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
V_94 = F_2 ( V_4 , V_5 ) ;
F_28 ( & V_4 -> V_37 ) ;
if ( V_94 )
goto V_89;
goto V_90;
}
if ( V_4 -> V_44 [ V_5 ] ) {
F_29 ( V_34 ) ;
if ( ! V_86 )
goto V_90;
else
goto V_92;
}
V_4 -> V_44 [ V_5 ] = V_80 ;
F_48 ( V_4 , V_4 -> V_35 , V_5 ) ;
F_29 ( V_34 ) ;
F_54 ( V_4 , V_5 , 1 ) ;
V_4 -> F_21 = V_5 + 1 ;
V_82 [ V_86 ++ ] = F_3 ( V_4 -> type , V_5 ) ;
if ( ( V_86 == V_81 ) || ( V_5 >= V_4 -> V_68 ) )
goto V_92;
if ( F_64 ( -- V_84 < 0 ) ) {
if ( V_86 )
goto V_92;
F_30 ( & V_4 -> V_37 ) ;
F_13 () ;
F_28 ( & V_4 -> V_37 ) ;
V_84 = V_85 ;
}
if ( V_4 -> V_35 ) {
if ( F_52 ( V_4 , & V_5 , & V_58 ) )
goto V_89;
else
goto V_92;
}
++ V_5 ;
if ( V_4 -> V_91 && ! V_4 -> V_44 [ V_5 ] ) {
-- V_4 -> V_91 ;
goto V_89;
}
V_92:
V_4 -> V_27 -= V_88 ;
return V_86 ;
V_90:
F_30 ( & V_4 -> V_37 ) ;
while ( ++ V_5 <= V_4 -> V_68 ) {
if ( ! V_4 -> V_44 [ V_5 ] ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_89;
}
if ( F_65 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_89;
}
if ( F_64 ( -- V_84 < 0 ) ) {
F_13 () ;
V_84 = V_85 ;
}
}
V_5 = V_4 -> V_67 ;
while ( V_5 < V_58 ) {
if ( ! V_4 -> V_44 [ V_5 ] ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_89;
}
if ( F_65 () && V_4 -> V_44 [ V_5 ] == V_2 ) {
F_28 ( & V_4 -> V_37 ) ;
goto V_89;
}
if ( F_64 ( -- V_84 < 0 ) ) {
F_13 () ;
V_84 = V_85 ;
}
V_5 ++ ;
}
F_28 ( & V_4 -> V_37 ) ;
V_93:
V_4 -> V_27 -= V_88 ;
return V_86 ;
}
static int F_66 ( struct V_3 * V_4 , T_1 * V_95 )
{
unsigned long V_41 ;
struct V_24 * V_34 ;
unsigned long V_5 , V_96 ;
unsigned char * V_97 ;
if ( F_33 ( & V_4 -> V_48 ) )
return 0 ;
V_41 = F_34 ( & V_4 -> V_48 ) ;
V_5 = V_41 * V_36 ;
V_34 = F_27 ( V_4 , V_5 ) ;
F_45 ( V_4 , V_41 ) ;
F_20 ( V_34 , V_36 , 0 ) ;
V_97 = V_4 -> V_44 + V_5 ;
for ( V_96 = 0 ; V_96 < V_36 ; V_96 ++ )
V_97 [ V_96 ] = V_2 ;
F_29 ( V_34 ) ;
F_54 ( V_4 , V_5 , V_36 ) ;
* V_95 = F_3 ( V_4 -> type , V_5 ) ;
return 1 ;
}
static void F_67 ( struct V_3 * V_4 , unsigned long V_41 )
{
unsigned long V_5 = V_41 * V_36 ;
struct V_24 * V_34 ;
V_34 = F_27 ( V_4 , V_5 ) ;
F_20 ( V_34 , 0 , 0 ) ;
F_47 ( V_4 , V_41 ) ;
F_29 ( V_34 ) ;
F_56 ( V_4 , V_5 , V_36 ) ;
}
static int F_66 ( struct V_3 * V_4 , T_1 * V_95 )
{
F_68 ( 1 ) ;
return 0 ;
}
static unsigned long F_69 ( struct V_3 * V_4 ,
unsigned char V_80 )
{
T_1 V_6 ;
int V_86 ;
V_86 = F_63 ( V_4 , V_80 , 1 , & V_6 ) ;
if ( V_86 )
return F_6 ( V_6 ) ;
else
return 0 ;
}
int F_70 ( int V_98 , bool V_59 , T_1 V_99 [] )
{
unsigned long V_16 = V_59 ? V_36 : 1 ;
struct V_3 * V_4 , * V_64 ;
long V_100 ;
int V_86 = 0 ;
F_71 ( V_98 > 1 && V_59 ) ;
V_100 = F_72 ( & V_76 ) / V_16 ;
if ( V_100 <= 0 )
goto V_101;
if ( V_98 > V_87 )
V_98 = V_87 ;
if ( V_98 > V_100 )
V_98 = V_100 ;
F_73 ( V_98 * V_16 , & V_76 ) ;
F_28 ( & V_71 ) ;
V_102:
F_74 (si, next, &swap_avail_head, avail_list) {
F_75 ( & V_4 -> V_72 , & V_73 ) ;
F_30 ( & V_71 ) ;
F_28 ( & V_4 -> V_37 ) ;
if ( ! V_4 -> V_68 || ! ( V_4 -> V_27 & V_51 ) ) {
F_28 ( & V_71 ) ;
if ( F_59 ( & V_4 -> V_72 ) ) {
F_30 ( & V_4 -> V_37 ) ;
goto V_103;
}
F_76 ( ! V_4 -> V_68 ,
L_1 ,
V_4 -> type ) ;
F_76 ( ! ( V_4 -> V_27 & V_51 ) ,
L_2 ,
V_4 -> type ) ;
F_55 ( & V_4 -> V_72 , & V_73 ) ;
F_30 ( & V_4 -> V_37 ) ;
goto V_103;
}
if ( V_59 )
V_86 = F_66 ( V_4 , V_99 ) ;
else
V_86 = F_63 ( V_4 , V_2 ,
V_98 , V_99 ) ;
F_30 ( & V_4 -> V_37 ) ;
if ( V_86 || V_59 )
goto V_104;
F_77 ( L_3 ,
V_4 -> type ) ;
F_28 ( & V_71 ) ;
V_103:
if ( F_59 ( & V_64 -> V_72 ) )
goto V_102;
}
F_30 ( & V_71 ) ;
V_104:
if ( V_86 < V_98 )
F_61 ( ( long ) ( V_98 - V_86 ) * V_16 ,
& V_76 ) ;
V_101:
return V_86 ;
}
T_1 F_78 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_105 [ type ] ;
F_28 ( & V_4 -> V_37 ) ;
if ( V_4 && ( V_4 -> V_27 & V_51 ) ) {
F_79 ( & V_76 ) ;
V_5 = F_69 ( V_4 , 1 ) ;
if ( V_5 ) {
F_30 ( & V_4 -> V_37 ) ;
return F_3 ( type , V_5 ) ;
}
F_80 ( & V_76 ) ;
}
F_30 ( & V_4 -> V_37 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_81 ( T_1 V_6 )
{
struct V_3 * V_53 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_106 )
goto V_107;
type = F_82 ( V_6 ) ;
if ( type >= V_108 )
goto V_109;
V_53 = V_105 [ type ] ;
if ( ! ( V_53 -> V_27 & V_110 ) )
goto V_111;
V_5 = F_6 ( V_6 ) ;
if ( V_5 >= V_53 -> V_62 )
goto V_112;
return V_53 ;
V_112:
F_83 ( L_4 , V_113 , V_6 . V_106 ) ;
goto V_107;
V_111:
F_83 ( L_4 , V_114 , V_6 . V_106 ) ;
goto V_107;
V_109:
F_83 ( L_4 , V_115 , V_6 . V_106 ) ;
V_107:
return NULL ;
}
static struct V_3 * F_84 ( T_1 V_6 )
{
struct V_3 * V_53 ;
V_53 = F_81 ( V_6 ) ;
if ( ! V_53 )
goto V_107;
if ( ! V_53 -> V_44 [ F_6 ( V_6 ) ] )
goto V_116;
return V_53 ;
V_116:
F_83 ( L_4 , V_117 , V_6 . V_106 ) ;
goto V_107;
V_107:
return NULL ;
}
static struct V_3 * F_85 ( T_1 V_6 )
{
struct V_3 * V_53 ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 )
F_28 ( & V_53 -> V_37 ) ;
return V_53 ;
}
static struct V_3 * F_86 ( T_1 V_6 ,
struct V_3 * V_118 )
{
struct V_3 * V_53 ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 != V_118 ) {
if ( V_118 != NULL )
F_30 ( & V_118 -> V_37 ) ;
if ( V_53 != NULL )
F_28 ( & V_53 -> V_37 ) ;
}
return V_53 ;
}
static unsigned char F_87 ( struct V_3 * V_53 ,
T_1 V_6 , unsigned char V_80 )
{
struct V_24 * V_34 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_119 ;
unsigned char V_120 ;
V_34 = F_31 ( V_53 , V_5 ) ;
V_119 = V_53 -> V_44 [ V_5 ] ;
V_120 = V_119 & V_2 ;
V_119 &= ~ V_2 ;
if ( V_80 == V_2 ) {
F_46 ( ! V_120 ) ;
V_120 = 0 ;
} else if ( V_119 == V_121 ) {
V_119 = 0 ;
} else if ( ( V_119 & ~ V_122 ) <= V_123 ) {
if ( V_119 == V_122 ) {
if ( F_88 ( V_53 , V_5 , V_119 ) )
V_119 = V_123 | V_122 ;
else
V_119 = V_123 ;
} else
V_119 -- ;
}
V_80 = V_119 | V_120 ;
V_53 -> V_44 [ V_5 ] = V_80 ? : V_2 ;
F_32 ( V_53 , V_34 ) ;
return V_80 ;
}
static void F_89 ( struct V_3 * V_53 , T_1 V_6 )
{
struct V_24 * V_34 ;
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_119 ;
V_34 = F_27 ( V_53 , V_5 ) ;
V_119 = V_53 -> V_44 [ V_5 ] ;
F_46 ( V_119 != V_2 ) ;
V_53 -> V_44 [ V_5 ] = 0 ;
F_49 ( V_53 , V_53 -> V_35 , V_5 ) ;
F_29 ( V_34 ) ;
F_90 ( V_6 , 1 ) ;
F_56 ( V_53 , V_5 , 1 ) ;
}
void F_91 ( T_1 V_6 )
{
struct V_3 * V_53 ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 ) {
if ( ! F_87 ( V_53 , V_6 , 1 ) )
F_92 ( V_6 ) ;
}
}
static void F_93 ( T_1 V_6 )
{
struct V_3 * V_53 ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 ) {
if ( ! F_87 ( V_53 , V_6 , V_2 ) )
F_92 ( V_6 ) ;
}
}
static void F_94 ( T_1 V_6 )
{
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned long V_41 = V_5 / V_36 ;
struct V_24 * V_34 ;
struct V_3 * V_4 ;
unsigned char * V_97 ;
unsigned int V_96 ;
V_4 = F_85 ( V_6 ) ;
if ( ! V_4 )
return;
V_34 = F_27 ( V_4 , V_5 ) ;
V_97 = V_4 -> V_44 + V_5 ;
for ( V_96 = 0 ; V_96 < V_36 ; V_96 ++ ) {
F_46 ( V_97 [ V_96 ] != V_2 ) ;
V_97 [ V_96 ] = 0 ;
}
F_29 ( V_34 ) ;
F_90 ( V_6 , V_36 ) ;
F_67 ( V_4 , V_41 ) ;
F_30 ( & V_4 -> V_37 ) ;
}
static inline void F_94 ( T_1 V_6 )
{
}
void F_95 ( struct V_7 * V_7 , T_1 V_6 )
{
if ( ! F_96 ( V_7 ) )
F_93 ( V_6 ) ;
else
F_94 ( V_6 ) ;
}
static int F_97 ( const void * V_124 , const void * V_125 )
{
const T_1 * V_126 = V_124 , * V_127 = V_125 ;
return ( int ) F_82 ( * V_126 ) - ( int ) F_82 ( * V_127 ) ;
}
void F_98 ( T_1 * V_128 , int V_31 )
{
struct V_3 * V_53 , * V_129 ;
int V_96 ;
if ( V_31 <= 0 )
return;
V_129 = NULL ;
V_53 = NULL ;
if ( V_108 > 1 )
F_99 ( V_128 , V_31 , sizeof( V_128 [ 0 ] ) , F_97 , NULL ) ;
for ( V_96 = 0 ; V_96 < V_31 ; ++ V_96 ) {
V_53 = F_86 ( V_128 [ V_96 ] , V_129 ) ;
if ( V_53 )
F_89 ( V_53 , V_128 [ V_96 ] ) ;
V_129 = V_53 ;
}
if ( V_53 )
F_30 ( & V_53 -> V_37 ) ;
}
int F_100 ( struct V_7 * V_7 )
{
int V_119 = 0 ;
struct V_3 * V_53 ;
struct V_24 * V_34 ;
T_1 V_6 ;
unsigned long V_5 ;
V_6 . V_106 = F_101 ( V_7 ) ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 ) {
V_5 = F_6 ( V_6 ) ;
V_34 = F_31 ( V_53 , V_5 ) ;
V_119 = F_1 ( V_53 -> V_44 [ V_5 ] ) ;
F_32 ( V_53 , V_34 ) ;
}
return V_119 ;
}
static int F_102 ( struct V_3 * V_4 , T_1 V_6 )
{
int V_119 = 0 ;
T_3 V_5 = F_6 ( V_6 ) ;
struct V_24 * V_34 ;
V_34 = F_31 ( V_4 , V_5 ) ;
V_119 = F_1 ( V_4 -> V_44 [ V_5 ] ) ;
F_32 ( V_4 , V_34 ) ;
return V_119 ;
}
int F_103 ( T_1 V_6 )
{
int V_119 = 0 ;
struct V_3 * V_4 ;
V_4 = F_81 ( V_6 ) ;
if ( V_4 )
V_119 = F_102 ( V_4 , V_6 ) ;
return V_119 ;
}
int F_104 ( T_1 V_6 )
{
int V_119 , V_130 , V_31 ;
struct V_3 * V_53 ;
struct V_24 * V_34 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_97 ;
V_53 = F_84 ( V_6 ) ;
if ( ! V_53 )
return 0 ;
V_5 = F_6 ( V_6 ) ;
V_34 = F_31 ( V_53 , V_5 ) ;
V_119 = F_1 ( V_53 -> V_44 [ V_5 ] ) ;
if ( ! ( V_119 & V_122 ) )
goto V_107;
V_119 &= ~ V_122 ;
V_31 = V_123 + 1 ;
V_7 = F_105 ( V_53 -> V_44 + V_5 ) ;
V_5 &= ~ V_131 ;
F_46 ( F_101 ( V_7 ) != V_132 ) ;
do {
V_7 = F_16 ( V_7 , V_133 ) ;
V_97 = F_106 ( V_7 ) ;
V_130 = V_97 [ V_5 ] ;
F_107 ( V_97 ) ;
V_119 += ( V_130 & ~ V_122 ) * V_31 ;
V_31 *= ( V_134 + 1 ) ;
} while ( V_130 & V_122 );
V_107:
F_32 ( V_53 , V_34 ) ;
return V_119 ;
}
bool F_108 ( struct V_7 * V_7 , int * V_135 )
{
int V_119 ;
F_109 ( ! F_110 ( V_7 ) , V_7 ) ;
if ( F_64 ( F_111 ( V_7 ) ) )
return false ;
V_119 = F_112 ( V_7 , V_135 ) ;
if ( V_119 <= 1 && F_113 ( V_7 ) ) {
V_119 += F_100 ( V_7 ) ;
if ( V_119 != 1 )
goto V_107;
if ( ! F_114 ( V_7 ) ) {
F_115 ( V_7 ) ;
F_116 ( V_7 ) ;
} else {
T_1 V_6 ;
struct V_3 * V_53 ;
V_6 . V_106 = F_101 ( V_7 ) ;
V_53 = F_85 ( V_6 ) ;
if ( V_53 -> V_27 & V_136 ) {
F_30 ( & V_53 -> V_37 ) ;
return false ;
}
F_30 ( & V_53 -> V_37 ) ;
}
}
V_107:
return V_119 <= 1 ;
}
int F_8 ( struct V_7 * V_7 )
{
F_109 ( ! F_110 ( V_7 ) , V_7 ) ;
if ( ! F_113 ( V_7 ) )
return 0 ;
if ( F_114 ( V_7 ) )
return 0 ;
if ( F_100 ( V_7 ) )
return 0 ;
if ( F_117 () )
return 0 ;
F_115 ( V_7 ) ;
F_116 ( V_7 ) ;
return 1 ;
}
int F_118 ( T_1 V_6 )
{
struct V_3 * V_53 ;
struct V_7 * V_7 = NULL ;
unsigned char V_119 ;
if ( F_119 ( V_6 ) )
return 1 ;
V_53 = F_84 ( V_6 ) ;
if ( V_53 ) {
V_119 = F_87 ( V_53 , V_6 , 1 ) ;
if ( V_119 == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
F_6 ( V_6 ) ) ;
if ( V_7 && ! F_7 ( V_7 ) ) {
F_10 ( V_7 ) ;
V_7 = NULL ;
}
} else if ( ! V_119 )
F_92 ( V_6 ) ;
}
if ( V_7 ) {
if ( F_113 ( V_7 ) && ! F_114 ( V_7 ) &&
( ! F_120 ( V_7 ) || F_121 ( V_7 ) ) &&
! F_102 ( V_53 , V_6 ) ) {
F_115 ( V_7 ) ;
F_116 ( V_7 ) ;
}
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_53 != NULL ;
}
int F_122 ( T_4 V_137 , T_2 V_5 , struct V_74 * * V_138 )
{
struct V_74 * V_17 = NULL ;
int type ;
if ( V_137 )
V_17 = F_123 ( V_137 ) ;
F_28 ( & V_139 ) ;
for ( type = 0 ; type < V_108 ; type ++ ) {
struct V_3 * V_140 = V_105 [ type ] ;
if ( ! ( V_140 -> V_27 & V_51 ) )
continue;
if ( ! V_17 ) {
if ( V_138 )
* V_138 = F_124 ( V_140 -> V_17 ) ;
F_30 ( & V_139 ) ;
return type ;
}
if ( V_17 == V_140 -> V_17 ) {
struct V_9 * V_10 = & V_140 -> V_14 ;
if ( V_10 -> V_11 == V_5 ) {
if ( V_138 )
* V_138 = F_124 ( V_140 -> V_17 ) ;
F_30 ( & V_139 ) ;
F_125 ( V_17 ) ;
return type ;
}
}
}
F_30 ( & V_139 ) ;
if ( V_17 )
F_125 ( V_17 ) ;
return - V_141 ;
}
T_2 F_126 ( int type , T_3 V_5 )
{
struct V_74 * V_17 ;
if ( ( unsigned int ) type >= V_108 )
return 0 ;
if ( ! ( V_105 [ type ] -> V_27 & V_51 ) )
return 0 ;
return F_127 ( F_3 ( type , V_5 ) , & V_17 ) ;
}
unsigned int F_128 ( int type , int free )
{
unsigned int V_31 = 0 ;
F_28 ( & V_139 ) ;
if ( ( unsigned int ) type < V_108 ) {
struct V_3 * V_140 = V_105 [ type ] ;
F_28 ( & V_140 -> V_37 ) ;
if ( V_140 -> V_27 & V_51 ) {
V_31 = V_140 -> V_70 ;
if ( free )
V_31 -= V_140 -> V_69 ;
}
F_30 ( & V_140 -> V_37 ) ;
}
F_30 ( & V_139 ) ;
return V_31 ;
}
static inline int F_129 ( T_5 V_142 , T_5 V_143 )
{
return F_130 ( F_131 ( V_142 ) , V_143 ) ;
}
static int F_132 ( struct V_144 * V_145 , T_6 * V_146 ,
unsigned long V_147 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_148 ;
struct V_149 * V_150 ;
T_7 * V_151 ;
T_5 * V_142 ;
int V_8 = 1 ;
V_148 = V_7 ;
V_7 = F_133 ( V_7 , V_145 , V_147 ) ;
if ( F_64 ( ! V_7 ) )
return - V_152 ;
if ( F_134 ( V_7 , V_145 -> V_153 , V_18 ,
& V_150 , false ) ) {
V_8 = - V_152 ;
goto V_154;
}
V_142 = F_135 ( V_145 -> V_153 , V_146 , V_147 , & V_151 ) ;
if ( F_64 ( ! F_129 ( * V_142 , F_136 ( V_6 ) ) ) ) {
F_137 ( V_7 , V_150 , false ) ;
V_8 = 0 ;
goto V_107;
}
F_138 ( V_145 -> V_153 , V_155 ) ;
F_139 ( V_145 -> V_153 , V_156 ) ;
F_140 ( V_7 ) ;
F_141 ( V_145 -> V_153 , V_147 , V_142 ,
F_142 ( F_143 ( V_7 , V_145 -> V_157 ) ) ) ;
if ( V_7 == V_148 ) {
F_144 ( V_7 , V_145 , V_147 , false ) ;
F_145 ( V_7 , V_150 , true , false ) ;
} else {
F_146 ( V_7 , V_145 , V_147 , false ) ;
F_145 ( V_7 , V_150 , false , false ) ;
F_147 ( V_7 , V_145 ) ;
}
F_91 ( V_6 ) ;
F_148 ( V_7 ) ;
V_107:
F_149 ( V_142 , V_151 ) ;
V_154:
if ( V_7 != V_148 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_8 ;
}
static int F_150 ( struct V_144 * V_145 , T_6 * V_146 ,
unsigned long V_147 , unsigned long V_66 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_143 = F_136 ( V_6 ) ;
T_5 * V_142 ;
int V_8 = 0 ;
V_142 = F_151 ( V_146 , V_147 ) ;
do {
if ( F_64 ( F_129 ( * V_142 , V_143 ) ) ) {
F_152 ( V_142 ) ;
V_8 = F_132 ( V_145 , V_146 , V_147 , V_6 , V_7 ) ;
if ( V_8 )
goto V_107;
V_142 = F_151 ( V_146 , V_147 ) ;
}
} while ( V_142 ++ , V_147 += V_158 , V_147 != V_66 );
F_152 ( V_142 - 1 ) ;
V_107:
return V_8 ;
}
static inline int F_153 ( struct V_144 * V_145 , T_8 * V_159 ,
unsigned long V_147 , unsigned long V_66 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_146 ;
unsigned long V_64 ;
int V_8 ;
V_146 = F_154 ( V_159 , V_147 ) ;
do {
F_13 () ;
V_64 = F_155 ( V_147 , V_66 ) ;
if ( F_156 ( V_146 ) )
continue;
V_8 = F_150 ( V_145 , V_146 , V_147 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_146 ++ , V_147 = V_64 , V_147 != V_66 );
return 0 ;
}
static inline int F_157 ( struct V_144 * V_145 , T_9 * V_160 ,
unsigned long V_147 , unsigned long V_66 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_159 ;
unsigned long V_64 ;
int V_8 ;
V_159 = F_158 ( V_160 , V_147 ) ;
do {
V_64 = F_159 ( V_147 , V_66 ) ;
if ( F_160 ( V_159 ) )
continue;
V_8 = F_153 ( V_145 , V_159 , V_147 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_159 ++ , V_147 = V_64 , V_147 != V_66 );
return 0 ;
}
static inline int F_161 ( struct V_144 * V_145 , T_10 * V_161 ,
unsigned long V_147 , unsigned long V_66 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_160 ;
unsigned long V_64 ;
int V_8 ;
V_160 = F_162 ( V_161 , V_147 ) ;
do {
V_64 = F_163 ( V_147 , V_66 ) ;
if ( F_164 ( V_160 ) )
continue;
V_8 = F_157 ( V_145 , V_160 , V_147 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_160 ++ , V_147 = V_64 , V_147 != V_66 );
return 0 ;
}
static int F_165 ( struct V_144 * V_145 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_10 * V_161 ;
unsigned long V_147 , V_66 , V_64 ;
int V_8 ;
if ( F_166 ( V_7 ) ) {
V_147 = F_167 ( V_7 , V_145 ) ;
if ( V_147 == - V_162 )
return 0 ;
else
V_66 = V_147 + V_158 ;
} else {
V_147 = V_145 -> V_163 ;
V_66 = V_145 -> V_164 ;
}
V_161 = F_168 ( V_145 -> V_153 , V_147 ) ;
do {
V_64 = F_169 ( V_147 , V_66 ) ;
if ( F_170 ( V_161 ) )
continue;
V_8 = F_161 ( V_145 , V_161 , V_147 , V_64 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_161 ++ , V_147 = V_64 , V_147 != V_66 );
return 0 ;
}
static int F_171 ( struct V_165 * V_166 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_144 * V_145 ;
int V_8 = 0 ;
if ( ! F_172 ( & V_166 -> V_167 ) ) {
F_148 ( V_7 ) ;
F_9 ( V_7 ) ;
F_173 ( & V_166 -> V_167 ) ;
F_174 ( V_7 ) ;
}
for ( V_145 = V_166 -> V_168 ; V_145 ; V_145 = V_145 -> V_169 ) {
if ( V_145 -> V_170 && ( V_8 = F_165 ( V_145 , V_6 , V_7 ) ) )
break;
F_13 () ;
}
F_175 ( & V_166 -> V_167 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_176 ( struct V_3 * V_4 ,
unsigned int V_129 , bool V_171 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_96 = V_129 ;
unsigned char V_119 ;
for (; ; ) {
if ( ++ V_96 >= V_62 ) {
if ( ! V_129 ) {
V_96 = 0 ;
break;
}
V_62 = V_129 + 1 ;
V_129 = 0 ;
V_96 = 1 ;
}
V_119 = F_177 ( V_4 -> V_44 [ V_96 ] ) ;
if ( V_119 && F_1 ( V_119 ) != V_45 )
if ( ! V_171 || F_178 ( V_4 , V_96 ) )
break;
if ( ( V_96 % V_85 ) == 0 )
F_13 () ;
}
return V_96 ;
}
int F_179 ( unsigned int type , bool V_171 ,
unsigned long V_172 )
{
struct V_3 * V_4 = V_105 [ type ] ;
struct V_165 * V_173 ;
volatile unsigned char * V_44 ;
unsigned char V_174 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_96 = 0 ;
int V_175 = 0 ;
V_173 = & V_176 ;
F_180 ( & V_176 ) ;
while ( ( V_96 = F_176 ( V_4 , V_96 , V_171 ) ) != 0 ) {
if ( F_181 ( V_177 ) ) {
V_175 = - V_178 ;
break;
}
V_44 = & V_4 -> V_44 [ V_96 ] ;
V_6 = F_3 ( type , V_96 ) ;
V_7 = F_182 ( V_6 ,
V_179 , NULL , 0 , false ) ;
if ( ! V_7 ) {
V_174 = * V_44 ;
if ( ! V_174 || V_174 == V_45 )
continue;
V_175 = - V_152 ;
break;
}
if ( F_183 ( & V_173 -> V_180 ) == 1 ) {
F_184 ( V_173 ) ;
V_173 = & V_176 ;
F_180 ( & V_176 ) ;
}
F_185 ( V_7 ) ;
F_186 ( V_7 ) ;
F_174 ( V_7 ) ;
F_186 ( V_7 ) ;
V_174 = * V_44 ;
if ( F_1 ( V_174 ) == V_121 ) {
V_175 = F_187 ( V_6 , V_7 ) ;
if ( V_175 < 0 )
break;
continue;
}
if ( F_1 ( V_174 ) && V_173 != & V_176 )
V_175 = F_171 ( V_173 , V_6 , V_7 ) ;
if ( F_1 ( * V_44 ) ) {
int V_181 = ( * V_44 >= V_174 ) ;
struct V_182 * V_53 = & V_173 -> V_183 ;
struct V_165 * V_184 = V_173 ;
struct V_165 * V_185 = V_173 ;
struct V_165 * V_166 ;
F_180 ( V_184 ) ;
F_180 ( V_185 ) ;
F_28 ( & V_186 ) ;
while ( F_1 ( * V_44 ) && ! V_175 &&
( V_53 = V_53 -> V_64 ) != & V_173 -> V_183 ) {
V_166 = F_188 ( V_53 , struct V_165 , V_183 ) ;
if ( ! F_189 ( V_166 ) )
continue;
F_30 ( & V_186 ) ;
F_184 ( V_185 ) ;
V_185 = V_166 ;
F_13 () ;
V_174 = * V_44 ;
if ( ! F_1 ( V_174 ) )
;
else if ( V_166 == & V_176 )
V_181 = 1 ;
else
V_175 = F_171 ( V_166 , V_6 , V_7 ) ;
if ( V_181 && * V_44 < V_174 ) {
F_184 ( V_184 ) ;
F_180 ( V_166 ) ;
V_184 = V_166 ;
V_181 = 0 ;
}
F_28 ( & V_186 ) ;
}
F_30 ( & V_186 ) ;
F_184 ( V_185 ) ;
F_184 ( V_173 ) ;
V_173 = V_184 ;
}
if ( V_175 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
break;
}
if ( F_1 ( * V_44 ) &&
F_190 ( V_7 ) && F_113 ( V_7 ) ) {
struct V_187 V_188 = {
. V_189 = V_190 ,
} ;
F_191 ( V_7 , & V_188 ) ;
F_174 ( V_7 ) ;
F_186 ( V_7 ) ;
}
if ( F_113 ( V_7 ) &&
F_192 ( F_101 ( V_7 ) == V_6 . V_106 ) )
F_115 ( V_7 ) ;
F_116 ( V_7 ) ;
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
F_13 () ;
if ( V_171 && V_172 > 0 ) {
if ( ! -- V_172 )
break;
}
}
F_184 ( V_173 ) ;
return V_175 ;
}
static void F_193 ( void )
{
struct V_182 * V_53 , * V_64 ;
unsigned int type ;
for ( type = 0 ; type < V_108 ; type ++ )
if ( V_105 [ type ] -> V_69 )
return;
F_28 ( & V_186 ) ;
F_194 (p, next, &init_mm.mmlist)
F_195 ( V_53 ) ;
F_30 ( & V_186 ) ;
}
static T_2 F_127 ( T_1 V_6 , struct V_74 * * V_17 )
{
struct V_3 * V_140 ;
struct V_9 * V_191 ;
struct V_9 * V_10 ;
T_3 V_5 ;
V_140 = V_105 [ F_82 ( V_6 ) ] ;
* V_17 = V_140 -> V_17 ;
V_5 = F_6 ( V_6 ) ;
V_191 = V_140 -> V_20 ;
V_10 = V_191 ;
for ( ; ; ) {
if ( V_10 -> V_19 <= V_5 &&
V_5 < ( V_10 -> V_19 + V_10 -> V_16 ) ) {
return V_10 -> V_11 + ( V_5 - V_10 -> V_19 ) ;
}
V_10 = F_16 ( V_10 , V_23 ) ;
V_140 -> V_20 = V_10 ;
F_196 ( V_10 == V_191 ) ;
}
}
T_2 F_197 ( struct V_7 * V_7 , struct V_74 * * V_17 )
{
T_1 V_6 ;
V_6 . V_106 = F_101 ( V_7 ) ;
return F_127 ( V_6 , V_17 ) ;
}
static void F_198 ( struct V_3 * V_140 )
{
while ( ! F_199 ( & V_140 -> V_14 . V_23 ) ) {
struct V_9 * V_10 ;
V_10 = F_200 ( & V_140 -> V_14 . V_23 ,
struct V_9 , V_23 ) ;
F_201 ( & V_10 -> V_23 ) ;
F_202 ( V_10 ) ;
}
if ( V_140 -> V_27 & V_192 ) {
struct V_193 * V_194 = V_140 -> V_194 ;
struct V_195 * V_196 = V_194 -> V_197 ;
V_140 -> V_27 &= ~ V_192 ;
V_196 -> V_198 -> V_199 ( V_194 ) ;
}
}
int
F_203 ( struct V_3 * V_140 , unsigned long V_19 ,
unsigned long V_16 , T_2 V_11 )
{
struct V_9 * V_10 ;
struct V_9 * V_200 ;
struct V_182 * V_201 ;
if ( V_19 == 0 ) {
V_10 = & V_140 -> V_14 ;
V_140 -> V_20 = V_10 ;
V_10 -> V_19 = 0 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_11 = V_11 ;
return 1 ;
} else {
V_201 = V_140 -> V_14 . V_23 . V_129 ;
V_10 = F_188 ( V_201 , struct V_9 , V_23 ) ;
F_196 ( V_10 -> V_19 + V_10 -> V_16 != V_19 ) ;
if ( V_10 -> V_11 + V_10 -> V_16 == V_11 ) {
V_10 -> V_16 += V_16 ;
return 0 ;
}
}
V_200 = F_204 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_200 == NULL )
return - V_152 ;
V_200 -> V_19 = V_19 ;
V_200 -> V_16 = V_16 ;
V_200 -> V_11 = V_11 ;
F_205 ( & V_200 -> V_23 , & V_140 -> V_14 . V_23 ) ;
return 1 ;
}
static int F_206 ( struct V_3 * V_140 , T_2 * V_202 )
{
struct V_193 * V_194 = V_140 -> V_194 ;
struct V_195 * V_196 = V_194 -> V_197 ;
struct V_203 * V_203 = V_196 -> V_204 ;
int V_8 ;
if ( F_207 ( V_203 -> V_205 ) ) {
V_8 = F_203 ( V_140 , 0 , V_140 -> V_62 , 0 ) ;
* V_202 = V_140 -> V_70 ;
return V_8 ;
}
if ( V_196 -> V_198 -> V_206 ) {
V_8 = V_196 -> V_198 -> V_206 ( V_140 , V_194 , V_202 ) ;
if ( ! V_8 ) {
V_140 -> V_27 |= V_192 ;
V_8 = F_203 ( V_140 , 0 , V_140 -> V_62 , 0 ) ;
* V_202 = V_140 -> V_70 ;
}
return V_8 ;
}
return F_208 ( V_140 , V_194 , V_202 ) ;
}
static void F_209 ( struct V_3 * V_53 , int V_207 ,
unsigned char * V_44 ,
struct V_24 * V_35 )
{
if ( V_207 >= 0 )
V_53 -> V_207 = V_207 ;
else
V_53 -> V_207 = -- V_208 ;
V_53 -> V_23 . V_207 = - V_53 -> V_207 ;
V_53 -> V_72 . V_207 = - V_53 -> V_207 ;
V_53 -> V_44 = V_44 ;
V_53 -> V_35 = V_35 ;
V_53 -> V_27 |= V_51 ;
F_61 ( V_53 -> V_70 , & V_76 ) ;
V_209 += V_53 -> V_70 ;
F_210 ( & V_139 ) ;
F_60 ( & V_53 -> V_23 , & V_210 ) ;
F_28 ( & V_71 ) ;
F_60 ( & V_53 -> V_72 , & V_73 ) ;
F_30 ( & V_71 ) ;
}
static void F_211 ( struct V_3 * V_53 , int V_207 ,
unsigned char * V_44 ,
struct V_24 * V_35 ,
unsigned long * V_211 )
{
F_212 ( V_53 -> type , V_211 ) ;
F_28 ( & V_139 ) ;
F_28 ( & V_53 -> V_37 ) ;
F_209 ( V_53 , V_207 , V_44 , V_35 ) ;
F_30 ( & V_53 -> V_37 ) ;
F_30 ( & V_139 ) ;
}
static void F_213 ( struct V_3 * V_53 )
{
F_28 ( & V_139 ) ;
F_28 ( & V_53 -> V_37 ) ;
F_209 ( V_53 , V_53 -> V_207 , V_53 -> V_44 , V_53 -> V_35 ) ;
F_30 ( & V_53 -> V_37 ) ;
F_30 ( & V_139 ) ;
}
bool F_214 ( void )
{
bool V_8 = true ;
F_28 ( & V_139 ) ;
if ( F_215 ( & V_210 ) )
V_8 = false ;
F_30 ( & V_139 ) ;
return V_8 ;
}
static unsigned F_216 ( struct V_193 * V_193 , T_11 * V_212 )
{
struct V_213 * V_214 = V_193 -> V_215 ;
F_217 ( V_193 , & V_216 , V_212 ) ;
if ( V_214 -> V_217 != F_183 ( & V_218 ) ) {
V_214 -> V_217 = F_183 ( & V_218 ) ;
return V_219 | V_220 | V_221 | V_222 ;
}
return V_219 | V_220 ;
}
static void * F_218 ( struct V_213 * V_223 , T_12 * V_224 )
{
struct V_3 * V_4 ;
int type ;
T_12 V_225 = * V_224 ;
F_219 ( & V_226 ) ;
if ( ! V_225 )
return V_227 ;
for ( type = 0 ; type < V_108 ; type ++ ) {
F_220 () ;
V_4 = V_105 [ type ] ;
if ( ! ( V_4 -> V_27 & V_110 ) || ! V_4 -> V_44 )
continue;
if ( ! -- V_225 )
return V_4 ;
}
return NULL ;
}
static void * F_221 ( struct V_213 * V_223 , void * V_228 , T_12 * V_224 )
{
struct V_3 * V_4 = V_228 ;
int type ;
if ( V_228 == V_227 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_108 ; type ++ ) {
F_220 () ;
V_4 = V_105 [ type ] ;
if ( ! ( V_4 -> V_27 & V_110 ) || ! V_4 -> V_44 )
continue;
++ * V_224 ;
return V_4 ;
}
return NULL ;
}
static void F_222 ( struct V_213 * V_223 , void * V_228 )
{
F_223 ( & V_226 ) ;
}
static int F_224 ( struct V_213 * V_223 , void * V_228 )
{
struct V_3 * V_4 = V_228 ;
struct V_193 * V_193 ;
int V_229 ;
if ( V_4 == V_227 ) {
F_225 ( V_223 , L_5 ) ;
return 0 ;
}
V_193 = V_4 -> V_194 ;
V_229 = F_226 ( V_223 , V_193 , L_6 ) ;
F_227 ( V_223 , L_7 ,
V_229 < 40 ? 40 - V_229 : 1 , L_8 ,
F_207 ( F_228 ( V_193 ) -> V_205 ) ?
L_9 : L_10 ,
V_4 -> V_70 << ( V_15 - 10 ) ,
V_4 -> V_69 << ( V_15 - 10 ) ,
V_4 -> V_207 ) ;
return 0 ;
}
static int F_229 ( struct V_203 * V_203 , struct V_193 * V_193 )
{
struct V_213 * V_214 ;
int V_8 ;
V_8 = F_230 ( V_193 , & V_230 ) ;
if ( V_8 )
return V_8 ;
V_214 = V_193 -> V_215 ;
V_214 -> V_217 = F_183 ( & V_218 ) ;
return 0 ;
}
static int T_13 F_231 ( void )
{
F_232 ( L_11 , 0 , NULL , & V_231 ) ;
return 0 ;
}
static int T_13 F_233 ( void )
{
F_234 () ;
return 0 ;
}
static struct V_3 * F_235 ( void )
{
struct V_3 * V_53 ;
unsigned int type ;
V_53 = F_236 ( sizeof( * V_53 ) , V_18 ) ;
if ( ! V_53 )
return F_237 ( - V_152 ) ;
F_28 ( & V_139 ) ;
for ( type = 0 ; type < V_108 ; type ++ ) {
if ( ! ( V_105 [ type ] -> V_27 & V_110 ) )
break;
}
if ( type >= V_232 ) {
F_30 ( & V_139 ) ;
F_202 ( V_53 ) ;
return F_237 ( - V_233 ) ;
}
if ( type >= V_108 ) {
V_53 -> type = type ;
V_105 [ type ] = V_53 ;
F_238 () ;
V_108 ++ ;
} else {
F_202 ( V_53 ) ;
V_53 = V_105 [ type ] ;
}
F_239 ( & V_53 -> V_14 . V_23 ) ;
F_240 ( & V_53 -> V_23 , 0 ) ;
F_240 ( & V_53 -> V_72 , 0 ) ;
V_53 -> V_27 = V_110 ;
F_30 ( & V_139 ) ;
F_241 ( & V_53 -> V_37 ) ;
return V_53 ;
}
static int F_242 ( struct V_3 * V_53 , struct V_203 * V_203 )
{
int error ;
if ( F_207 ( V_203 -> V_205 ) ) {
V_53 -> V_17 = F_124 ( F_243 ( V_203 ) ) ;
error = F_244 ( V_53 -> V_17 ,
V_234 | V_235 | V_236 , V_53 ) ;
if ( error < 0 ) {
V_53 -> V_17 = NULL ;
return error ;
}
V_53 -> V_237 = F_245 ( V_53 -> V_17 ) ;
error = F_246 ( V_53 -> V_17 , V_158 ) ;
if ( error < 0 )
return error ;
V_53 -> V_27 |= V_77 ;
} else if ( F_247 ( V_203 -> V_205 ) ) {
V_53 -> V_17 = V_203 -> V_238 -> V_239 ;
F_248 ( V_203 ) ;
if ( F_249 ( V_203 ) )
return - V_240 ;
} else
return - V_241 ;
return 0 ;
}
static unsigned long F_250 ( struct V_3 * V_53 ,
union V_242 * V_242 ,
struct V_203 * V_203 )
{
int V_96 ;
unsigned long V_243 ;
unsigned long V_244 ;
unsigned long V_245 ;
if ( memcmp ( L_12 , V_242 -> V_246 . V_246 , 10 ) ) {
F_83 ( L_13 ) ;
return 0 ;
}
if ( F_251 ( V_242 -> V_25 . V_247 ) == 1 ) {
F_252 ( & V_242 -> V_25 . V_247 ) ;
F_252 ( & V_242 -> V_25 . V_245 ) ;
F_252 ( & V_242 -> V_25 . V_248 ) ;
if ( V_242 -> V_25 . V_248 > V_249 )
return 0 ;
for ( V_96 = 0 ; V_96 < V_242 -> V_25 . V_248 ; V_96 ++ )
F_252 ( & V_242 -> V_25 . V_250 [ V_96 ] ) ;
}
if ( V_242 -> V_25 . V_247 != 1 ) {
F_253 ( L_14 ,
V_242 -> V_25 . V_247 ) ;
return 0 ;
}
V_53 -> V_67 = 1 ;
V_53 -> F_21 = 1 ;
V_53 -> V_91 = 0 ;
V_243 = F_6 ( F_254 (
F_136 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_245 = V_242 -> V_25 . V_245 ;
if ( V_245 > V_243 ) {
F_253 ( L_15 ,
V_243 << ( V_15 - 10 ) ,
V_245 << ( V_15 - 10 ) ) ;
}
if ( V_243 > V_245 ) {
V_243 = V_245 + 1 ;
if ( ( unsigned int ) V_243 == 0 )
V_243 = V_251 ;
}
V_53 -> V_68 = V_243 - 1 ;
if ( ! V_243 )
return 0 ;
V_244 = F_255 ( V_203 ) >> V_15 ;
if ( V_244 && V_243 > V_244 ) {
F_253 ( L_16 ) ;
return 0 ;
}
if ( V_242 -> V_25 . V_248 && F_247 ( V_203 -> V_205 ) )
return 0 ;
if ( V_242 -> V_25 . V_248 > V_249 )
return 0 ;
return V_243 ;
}
static int F_256 ( struct V_3 * V_53 ,
union V_242 * V_242 ,
unsigned char * V_44 ,
struct V_24 * V_35 ,
unsigned long V_243 ,
T_2 * V_202 )
{
unsigned int V_252 , V_253 ;
unsigned int V_254 ;
int V_255 ;
unsigned long V_256 = F_257 ( V_243 , V_36 ) ;
unsigned long V_257 = V_53 -> F_21 / V_36 % V_258 ;
unsigned long V_96 , V_41 ;
V_254 = V_243 - 1 ;
F_35 ( & V_53 -> V_48 ) ;
F_35 ( & V_53 -> V_46 ) ;
for ( V_96 = 0 ; V_96 < V_242 -> V_25 . V_248 ; V_96 ++ ) {
unsigned int V_54 = V_242 -> V_25 . V_250 [ V_96 ] ;
if ( V_54 == 0 || V_54 > V_242 -> V_25 . V_245 )
return - V_241 ;
if ( V_54 < V_243 ) {
V_44 [ V_54 ] = V_45 ;
V_254 -- ;
F_48 ( V_53 , V_35 , V_54 ) ;
}
}
for ( V_96 = V_243 ; V_96 < F_258 ( V_243 , V_36 ) ; V_96 ++ )
F_48 ( V_53 , V_35 , V_96 ) ;
if ( V_254 ) {
V_44 [ 0 ] = V_45 ;
F_48 ( V_53 , V_35 , 0 ) ;
V_53 -> V_62 = V_243 ;
V_53 -> V_70 = V_254 ;
V_255 = F_206 ( V_53 , V_202 ) ;
if ( V_255 < 0 )
return V_255 ;
V_254 = V_53 -> V_70 ;
}
if ( ! V_254 ) {
F_253 ( L_17 ) ;
return - V_241 ;
}
if ( ! V_35 )
return V_255 ;
for ( V_253 = 0 ; V_253 < V_258 ; V_253 ++ ) {
V_252 = ( V_253 + V_257 ) % V_258 ;
for ( V_96 = 0 ; V_96 < F_257 ( V_256 , V_258 ) ; V_96 ++ ) {
V_41 = V_96 * V_258 + V_252 ;
if ( V_41 >= V_256 )
continue;
if ( F_18 ( & V_35 [ V_41 ] ) )
continue;
F_17 ( & V_35 [ V_41 ] , V_32 ) ;
F_36 ( & V_53 -> V_48 , V_35 ,
V_41 ) ;
}
}
return V_255 ;
}
static bool F_259 ( struct V_3 * V_4 )
{
struct V_259 * V_118 = F_260 ( V_4 -> V_17 ) ;
if ( ! V_118 || ! F_261 ( V_118 ) )
return false ;
return true ;
}
void F_262 ( struct V_260 * V_106 )
{
unsigned int type ;
unsigned long V_261 = 0 ;
F_28 ( & V_139 ) ;
for ( type = 0 ; type < V_108 ; type ++ ) {
struct V_3 * V_4 = V_105 [ type ] ;
if ( ( V_4 -> V_27 & V_110 ) && ! ( V_4 -> V_27 & V_51 ) )
V_261 += V_4 -> V_69 ;
}
V_106 -> V_262 = F_72 ( & V_76 ) + V_261 ;
V_106 -> V_263 = V_209 + V_261 ;
F_30 ( & V_139 ) ;
}
static int F_263 ( T_1 V_6 , unsigned char V_80 )
{
struct V_3 * V_53 ;
struct V_24 * V_34 ;
unsigned long V_5 , type ;
unsigned char V_119 ;
unsigned char V_120 ;
int V_13 = - V_241 ;
if ( F_119 ( V_6 ) )
goto V_107;
type = F_82 ( V_6 ) ;
if ( type >= V_108 )
goto V_264;
V_53 = V_105 [ type ] ;
V_5 = F_6 ( V_6 ) ;
if ( F_64 ( V_5 >= V_53 -> V_62 ) )
goto V_107;
V_34 = F_31 ( V_53 , V_5 ) ;
V_119 = V_53 -> V_44 [ V_5 ] ;
if ( F_64 ( F_1 ( V_119 ) == V_45 ) ) {
V_13 = - V_265 ;
goto V_266;
}
V_120 = V_119 & V_2 ;
V_119 &= ~ V_2 ;
V_13 = 0 ;
if ( V_80 == V_2 ) {
if ( ! V_120 && V_119 )
V_120 = V_2 ;
else if ( V_120 )
V_13 = - V_267 ;
else
V_13 = - V_265 ;
} else if ( V_119 || V_120 ) {
if ( ( V_119 & ~ V_122 ) < V_123 )
V_119 += V_80 ;
else if ( ( V_119 & ~ V_122 ) > V_123 )
V_13 = - V_241 ;
else if ( F_88 ( V_53 , V_5 , V_119 ) )
V_119 = V_122 ;
else
V_13 = - V_152 ;
} else
V_13 = - V_265 ;
V_53 -> V_44 [ V_5 ] = V_119 | V_120 ;
V_266:
F_32 ( V_53 , V_34 ) ;
V_107:
return V_13 ;
V_264:
F_83 ( L_18 , V_115 , V_6 . V_106 ) ;
goto V_107;
}
void F_264 ( T_1 V_6 )
{
F_263 ( V_6 , V_121 ) ;
}
int F_265 ( T_1 V_6 )
{
int V_13 = 0 ;
while ( ! V_13 && F_263 ( V_6 , 1 ) == - V_152 )
V_13 = F_266 ( V_6 , V_268 ) ;
return V_13 ;
}
int F_267 ( T_1 V_6 )
{
return F_263 ( V_6 , V_2 ) ;
}
struct V_3 * F_268 ( struct V_7 * V_7 )
{
T_1 V_223 = { . V_106 = F_101 (page) } ;
return V_105 [ F_82 ( V_223 ) ] ;
}
struct V_195 * F_269 ( struct V_7 * V_7 )
{
F_109 ( ! F_113 ( V_7 ) , V_7 ) ;
return F_268 ( V_7 ) -> V_194 -> V_197 ;
}
T_3 F_270 ( struct V_7 * V_7 )
{
T_1 V_223 = { . V_106 = F_101 (page) } ;
F_109 ( ! F_113 ( V_7 ) , V_7 ) ;
return F_6 ( V_223 ) ;
}
int F_266 ( T_1 V_6 , T_14 V_269 )
{
struct V_3 * V_4 ;
struct V_24 * V_34 ;
struct V_7 * V_39 ;
struct V_7 * V_7 ;
struct V_7 * V_270 ;
T_3 V_5 ;
unsigned char V_119 ;
V_7 = F_271 ( V_269 | V_271 ) ;
V_4 = F_85 ( V_6 ) ;
if ( ! V_4 ) {
goto V_272;
}
V_5 = F_6 ( V_6 ) ;
V_34 = F_27 ( V_4 , V_5 ) ;
V_119 = V_4 -> V_44 [ V_5 ] & ~ V_2 ;
if ( ( V_119 & ~ V_122 ) != V_123 ) {
goto V_107;
}
if ( ! V_7 ) {
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
return - V_152 ;
}
V_39 = F_105 ( V_4 -> V_44 + V_5 ) ;
V_5 &= ~ V_131 ;
if ( ! F_101 ( V_39 ) ) {
F_196 ( V_119 & V_122 ) ;
F_239 ( & V_39 -> V_133 ) ;
F_272 ( V_39 , V_132 ) ;
V_4 -> V_27 |= V_132 ;
}
F_14 (list_page, &head->lru, lru) {
unsigned char * V_97 ;
if ( ! ( V_119 & V_122 ) )
goto V_107;
V_97 = F_106 ( V_270 ) + V_5 ;
V_119 = * V_97 ;
F_107 ( V_97 ) ;
if ( ( V_119 & ~ V_122 ) != V_134 )
goto V_107;
}
F_205 ( & V_7 -> V_133 , & V_39 -> V_133 ) ;
V_7 = NULL ;
V_107:
F_29 ( V_34 ) ;
F_30 ( & V_4 -> V_37 ) ;
V_272:
if ( V_7 )
F_273 ( V_7 ) ;
return 0 ;
}
static bool F_88 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_119 )
{
struct V_7 * V_39 ;
struct V_7 * V_7 ;
unsigned char * V_97 ;
V_39 = F_105 ( V_4 -> V_44 + V_5 ) ;
if ( F_101 ( V_39 ) != V_132 ) {
F_196 ( V_119 & V_122 ) ;
return false ;
}
V_5 &= ~ V_131 ;
V_7 = F_188 ( V_39 -> V_133 . V_64 , struct V_7 , V_133 ) ;
V_97 = F_106 ( V_7 ) + V_5 ;
if ( V_119 == V_123 )
goto V_273;
if ( V_119 == ( V_123 | V_122 ) ) {
while ( * V_97 == ( V_134 | V_122 ) ) {
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_64 , struct V_7 , V_133 ) ;
F_196 ( V_7 == V_39 ) ;
V_97 = F_106 ( V_7 ) + V_5 ;
}
if ( * V_97 == V_134 ) {
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_64 , struct V_7 , V_133 ) ;
if ( V_7 == V_39 )
return false ;
V_97 = F_106 ( V_7 ) + V_5 ;
V_273: * V_97 = 0 ;
}
* V_97 += 1 ;
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_129 , struct V_7 , V_133 ) ;
while ( V_7 != V_39 ) {
V_97 = F_106 ( V_7 ) + V_5 ;
* V_97 = V_122 ;
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_129 , struct V_7 , V_133 ) ;
}
return true ;
} else {
F_196 ( V_119 != V_122 ) ;
while ( * V_97 == V_122 ) {
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_64 , struct V_7 , V_133 ) ;
F_196 ( V_7 == V_39 ) ;
V_97 = F_106 ( V_7 ) + V_5 ;
}
F_196 ( * V_97 == 0 ) ;
* V_97 -= 1 ;
if ( * V_97 == 0 )
V_119 = 0 ;
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_129 , struct V_7 , V_133 ) ;
while ( V_7 != V_39 ) {
V_97 = F_106 ( V_7 ) + V_5 ;
* V_97 = V_134 | V_119 ;
V_119 = V_122 ;
F_107 ( V_97 ) ;
V_7 = F_188 ( V_7 -> V_133 . V_129 , struct V_7 , V_133 ) ;
}
return V_119 == V_122 ;
}
}
static void F_274 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_158 ) {
struct V_7 * V_39 ;
V_39 = F_105 ( V_4 -> V_44 + V_5 ) ;
if ( F_101 ( V_39 ) ) {
struct V_7 * V_7 , * V_64 ;
F_275 (page, next, &head->lru, lru) {
F_201 ( & V_7 -> V_133 ) ;
F_273 ( V_7 ) ;
}
}
}
}
