static inline T_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) + V_2 -> V_4 ;
}
static inline T_2 F_3 ( struct V_5 * V_6 , const T_1 * V_7 )
{
#if F_4 ( V_8 )
return F_5 ( ( const V_9 * ) ( V_7 + V_6 -> V_10 ) ) ;
#else
const T_1 * V_11 = V_7 + V_6 -> V_10 ;
return ( T_2 ) V_11 [ 0 ] |
( T_2 ) V_11 [ 1 ] << 8 |
( T_2 ) V_11 [ 2 ] << 16 |
( T_2 ) V_11 [ 3 ] << 24 ;
#endif
}
static inline struct V_1 *
F_6 ( struct V_12 * V_13 , struct V_1 * V_14 )
{
if ( F_7 ( V_14 == V_1 ( V_13 , V_13 -> V_15 ) ) )
return V_1 ( V_13 , 0 ) ;
else
return V_14 + 1 ;
}
static inline void F_8 ( struct V_5 * V_6 ,
struct V_1 * V_14 ,
unsigned int V_16 )
{
F_9 ( & V_6 -> V_17 -> V_18 , V_14 -> V_19 , V_16 ,
V_20 ) ;
}
void F_10 ( struct V_5 * V_6 )
{
V_6 -> V_21 = F_11 ( V_6 -> V_22 + V_6 -> V_23 ,
V_24 ) ;
V_6 -> V_25 = V_6 -> V_26 ? 1 :
( ( V_27 - sizeof( struct V_28 ) ) /
V_6 -> V_21 ) ;
V_6 -> V_29 = ( V_27 << V_6 -> V_26 ) /
V_6 -> V_25 ;
V_6 -> V_30 = F_12 ( V_31 ,
V_6 -> V_25 ) ;
}
static struct V_3 * F_13 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_3 * V_3 ;
struct V_28 * V_32 ;
unsigned V_33 ;
V_33 = V_13 -> V_34 & V_13 -> V_35 ;
V_3 = V_13 -> V_36 [ V_33 ] ;
if ( V_3 == NULL )
return NULL ;
V_13 -> V_36 [ V_33 ] = NULL ;
if ( V_13 -> V_34 != V_13 -> V_37 )
++ V_13 -> V_34 ;
if ( F_14 ( V_3 ) == 1 ) {
++ V_13 -> V_38 ;
return V_3 ;
} else {
V_32 = F_2 ( V_3 ) ;
F_15 ( & V_6 -> V_17 -> V_18 , V_32 -> V_19 ,
V_27 << V_6 -> V_26 ,
V_20 ) ;
F_16 ( V_3 ) ;
++ V_13 -> V_39 ;
}
return NULL ;
}
static int F_17 ( struct V_12 * V_13 , bool V_40 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_1 * V_14 ;
struct V_3 * V_3 ;
unsigned int V_4 ;
struct V_28 * V_32 ;
T_3 V_19 ;
unsigned V_33 , V_41 ;
V_41 = 0 ;
do {
V_3 = F_13 ( V_13 ) ;
if ( V_3 == NULL ) {
V_3 = F_18 ( V_42 | V_43 |
( V_40 ? V_44 : V_45 ) ,
V_6 -> V_26 ) ;
if ( F_7 ( V_3 == NULL ) )
return - V_46 ;
V_19 =
F_19 ( & V_6 -> V_17 -> V_18 , V_3 , 0 ,
V_27 << V_6 -> V_26 ,
V_20 ) ;
if ( F_7 ( F_20 ( & V_6 -> V_17 -> V_18 ,
V_19 ) ) ) {
F_21 ( V_3 , V_6 -> V_26 ) ;
return - V_47 ;
}
V_32 = F_2 ( V_3 ) ;
V_32 -> V_19 = V_19 ;
} else {
V_32 = F_2 ( V_3 ) ;
V_19 = V_32 -> V_19 ;
}
V_19 += sizeof( struct V_28 ) ;
V_4 = sizeof( struct V_28 ) ;
do {
V_33 = V_13 -> V_48 & V_13 -> V_15 ;
V_14 = V_1 ( V_13 , V_33 ) ;
V_14 -> V_19 = V_19 + V_6 -> V_23 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_4 = V_4 + V_6 -> V_23 ;
V_14 -> V_16 = V_6 -> V_22 ;
V_14 -> V_49 = 0 ;
++ V_13 -> V_48 ;
F_22 ( V_3 ) ;
V_19 += V_6 -> V_21 ;
V_4 += V_6 -> V_21 ;
} while ( V_4 + V_6 -> V_21 <= V_27 );
V_14 -> V_49 = V_50 ;
} while ( ++ V_41 < V_6 -> V_30 );
return 0 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_1 * V_14 )
{
struct V_3 * V_3 = V_14 -> V_3 ;
if ( V_3 ) {
struct V_28 * V_32 = F_2 ( V_3 ) ;
F_15 ( & V_6 -> V_17 -> V_18 ,
V_32 -> V_19 ,
V_27 << V_6 -> V_26 ,
V_20 ) ;
}
}
static void F_24 ( struct V_12 * V_13 ,
struct V_1 * V_14 ,
unsigned int V_51 )
{
do {
if ( V_14 -> V_3 ) {
F_16 ( V_14 -> V_3 ) ;
V_14 -> V_3 = NULL ;
}
V_14 = F_6 ( V_13 , V_14 ) ;
} while ( -- V_51 );
}
static void F_25 ( struct V_52 * V_53 ,
struct V_1 * V_14 )
{
struct V_3 * V_3 = V_14 -> V_3 ;
struct V_12 * V_13 = F_26 ( V_53 ) ;
struct V_5 * V_6 = V_13 -> V_6 ;
unsigned V_33 ;
if ( ! ( V_14 -> V_49 & V_50 ) )
return;
V_33 = V_13 -> V_37 & V_13 -> V_35 ;
if ( V_13 -> V_36 [ V_33 ] == NULL ) {
unsigned V_54 = V_13 -> V_34 &
V_13 -> V_35 ;
if ( V_54 == V_33 )
++ V_13 -> V_34 ;
V_13 -> V_36 [ V_33 ] = V_3 ;
++ V_13 -> V_37 ;
return;
}
++ V_13 -> V_55 ;
F_23 ( V_6 , V_14 ) ;
F_16 ( V_14 -> V_3 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
if ( V_14 -> V_3 )
F_16 ( V_14 -> V_3 ) ;
if ( V_14 -> V_49 & V_50 ) {
F_23 ( V_13 -> V_6 , V_14 ) ;
F_24 ( V_13 , V_14 , 1 ) ;
}
V_14 -> V_3 = NULL ;
}
static void F_28 ( struct V_52 * V_53 ,
struct V_1 * V_14 ,
unsigned int V_56 )
{
struct V_12 * V_13 = F_26 ( V_53 ) ;
do {
F_25 ( V_53 , V_14 ) ;
V_14 = F_6 ( V_13 , V_14 ) ;
} while ( -- V_56 );
}
static void F_29 ( struct V_52 * V_53 ,
struct V_1 * V_14 ,
unsigned int V_56 )
{
struct V_12 * V_13 = F_26 ( V_53 ) ;
F_28 ( V_53 , V_14 , V_56 ) ;
F_24 ( V_13 , V_14 , V_56 ) ;
}
void F_30 ( struct V_12 * V_13 , bool V_40 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
unsigned int V_57 , V_58 ;
int V_59 , V_60 = 0 ;
if ( ! V_13 -> V_61 )
return;
V_57 = ( V_13 -> V_48 - V_13 -> V_62 ) ;
F_31 ( V_57 > V_13 -> V_6 -> V_63 ) ;
if ( V_57 >= V_13 -> V_64 )
goto V_65;
if ( F_7 ( V_57 < V_13 -> V_66 ) ) {
if ( V_57 )
V_13 -> V_66 = V_57 ;
}
V_58 = V_6 -> V_30 * V_6 -> V_25 ;
V_59 = V_13 -> V_67 - V_57 ;
F_31 ( V_59 < V_58 ) ;
F_32 ( V_13 -> V_6 , V_68 , V_13 -> V_6 -> V_69 ,
L_1
L_2 ,
F_33 ( V_13 ) , V_57 ,
V_13 -> V_67 ) ;
do {
V_60 = F_17 ( V_13 , V_40 ) ;
if ( F_7 ( V_60 ) ) {
if ( V_13 -> V_48 == V_13 -> V_62 )
F_34 ( V_13 ) ;
goto V_65;
}
} while ( ( V_59 -= V_58 ) >= V_58 );
F_32 ( V_13 -> V_6 , V_68 , V_13 -> V_6 -> V_69 ,
L_3
L_4 , F_33 ( V_13 ) ,
V_13 -> V_48 - V_13 -> V_62 ) ;
V_65:
if ( V_13 -> V_70 != V_13 -> V_48 )
F_35 ( V_13 ) ;
}
void F_36 ( unsigned long V_71 )
{
struct V_12 * V_13 = (struct V_12 * ) V_71 ;
F_37 ( V_13 ) ;
++ V_13 -> V_72 ;
}
static void F_38 ( struct V_12 * V_13 ,
struct V_1 * V_14 ,
int V_16 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
unsigned V_73 = V_14 -> V_16 - V_6 -> type -> V_74 ;
if ( F_39 ( V_16 <= V_73 ) )
return;
V_14 -> V_49 |= V_75 ;
if ( ( V_16 > V_14 -> V_16 ) && F_40 ( V_6 ) ) {
if ( F_41 () )
F_42 ( V_6 , V_76 , V_6 -> V_69 ,
L_5
L_6 ,
F_33 ( V_13 ) , V_16 , V_73 ,
V_6 -> type -> V_74 ) ;
F_43 ( V_6 , V_77 ) ;
} else {
if ( F_41 () )
F_42 ( V_6 , V_76 , V_6 -> V_69 ,
L_7
L_8 ,
F_33 ( V_13 ) , V_16 , V_73 ) ;
}
F_44 ( V_13 ) -> V_78 ++ ;
}
static void
F_45 ( struct V_52 * V_53 , struct V_1 * V_14 ,
unsigned int V_56 , T_1 * V_7 )
{
struct V_79 * V_80 = & V_53 -> V_81 ;
T_4 V_82 ;
struct V_5 * V_6 = V_53 -> V_6 ;
struct V_83 * V_84 ;
V_84 = F_46 ( V_80 ) ;
if ( F_7 ( ! V_84 ) ) {
struct V_12 * V_13 ;
V_13 = F_26 ( V_53 ) ;
F_24 ( V_13 , V_14 , V_56 ) ;
return;
}
if ( V_6 -> V_69 -> V_85 & V_86 )
F_47 ( V_84 , F_3 ( V_6 , V_7 ) ,
V_87 ) ;
V_84 -> V_88 = ( ( V_14 -> V_49 & V_89 ) ?
V_90 : V_91 ) ;
for (; ; ) {
F_48 ( V_84 , F_49 ( V_84 ) -> V_92 ,
V_14 -> V_3 , V_14 -> V_4 ,
V_14 -> V_16 ) ;
V_14 -> V_3 = NULL ;
V_84 -> V_16 += V_14 -> V_16 ;
if ( F_49 ( V_84 ) -> V_92 == V_56 )
break;
V_14 = F_6 ( & V_53 -> V_13 , V_14 ) ;
}
V_84 -> V_93 = V_84 -> V_16 ;
V_84 -> V_94 += V_56 * V_6 -> V_29 ;
F_50 ( V_84 , V_53 -> V_13 . V_95 ) ;
V_82 = F_51 ( V_80 ) ;
if ( V_82 != V_96 )
V_53 -> V_97 += 2 ;
}
static struct V_83 * F_52 ( struct V_52 * V_53 ,
struct V_1 * V_14 ,
unsigned int V_56 ,
T_1 * V_7 , int V_98 )
{
struct V_5 * V_6 = V_53 -> V_6 ;
struct V_83 * V_84 ;
V_84 = F_53 ( V_6 -> V_69 ,
V_6 -> V_23 + V_6 -> V_99 +
V_98 ) ;
if ( F_7 ( V_84 == NULL ) ) {
F_54 ( & V_6 -> V_100 ) ;
return NULL ;
}
F_31 ( V_14 -> V_16 < V_98 ) ;
memcpy ( V_84 -> V_11 + V_6 -> V_23 , V_7 - V_6 -> V_99 ,
V_6 -> V_99 + V_98 ) ;
F_55 ( V_84 , V_6 -> V_23 + V_6 -> V_99 ) ;
F_56 ( V_84 , V_98 ) ;
if ( V_14 -> V_16 > V_98 ) {
V_14 -> V_4 += V_98 ;
V_14 -> V_16 -= V_98 ;
for (; ; ) {
F_48 ( V_84 , F_49 ( V_84 ) -> V_92 ,
V_14 -> V_3 , V_14 -> V_4 ,
V_14 -> V_16 ) ;
V_14 -> V_3 = NULL ;
V_84 -> V_16 += V_14 -> V_16 ;
V_84 -> V_93 += V_14 -> V_16 ;
if ( F_49 ( V_84 ) -> V_92 == V_56 )
break;
V_14 = F_6 ( & V_53 -> V_13 , V_14 ) ;
}
} else {
F_21 ( V_14 -> V_3 , V_6 -> V_26 ) ;
V_14 -> V_3 = NULL ;
V_56 = 0 ;
}
V_84 -> V_94 += V_56 * V_6 -> V_29 ;
V_84 -> V_101 = F_57 ( V_84 , V_6 -> V_69 ) ;
F_58 ( V_84 , & V_53 -> V_81 ) ;
return V_84 ;
}
void F_59 ( struct V_12 * V_13 , unsigned int V_33 ,
unsigned int V_56 , unsigned int V_16 , T_5 V_49 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_52 * V_53 = F_44 ( V_13 ) ;
struct V_1 * V_14 ;
V_13 -> V_102 ++ ;
V_14 = V_1 ( V_13 , V_33 ) ;
V_14 -> V_49 |= V_49 ;
if ( V_56 == 1 ) {
if ( ! ( V_49 & V_103 ) )
F_38 ( V_13 , V_14 , V_16 ) ;
} else if ( F_7 ( V_56 > V_104 ) ||
F_7 ( V_16 <= ( V_56 - 1 ) * V_6 -> V_22 ) ||
F_7 ( V_16 > V_56 * V_6 -> V_22 ) ||
F_7 ( ! V_6 -> V_105 ) ) {
F_60 ( ! ( V_16 == 0 && V_14 -> V_49 & V_75 ) ) ;
V_14 -> V_49 |= V_75 ;
}
F_32 ( V_6 , V_68 , V_6 -> V_69 ,
L_9 ,
F_33 ( V_13 ) , V_33 ,
( V_33 + V_56 - 1 ) & V_13 -> V_15 , V_16 ,
( V_14 -> V_49 & V_89 ) ? L_10 : L_11 ,
( V_14 -> V_49 & V_75 ) ? L_12 : L_11 ) ;
if ( F_7 ( V_14 -> V_49 & V_75 ) ) {
F_61 ( V_53 ) ;
F_29 ( V_53 , V_14 , V_56 ) ;
return;
}
if ( V_56 == 1 && ! ( V_49 & V_103 ) )
V_14 -> V_16 = V_16 ;
F_8 ( V_6 , V_14 , V_14 -> V_16 ) ;
F_62 ( F_1 ( V_14 ) ) ;
V_14 -> V_4 += V_6 -> V_99 ;
V_14 -> V_16 -= V_6 -> V_99 ;
if ( V_56 > 1 ) {
unsigned int V_106 = V_56 - 1 ;
for (; ; ) {
V_14 = F_6 ( V_13 , V_14 ) ;
if ( -- V_106 == 0 )
break;
F_8 ( V_6 , V_14 , V_6 -> V_22 ) ;
}
V_14 -> V_16 = V_16 - ( V_56 - 1 ) * V_6 -> V_22 ;
F_8 ( V_6 , V_14 , V_14 -> V_16 ) ;
}
V_14 = V_1 ( V_13 , V_33 ) ;
F_28 ( V_53 , V_14 , V_56 ) ;
F_61 ( V_53 ) ;
V_53 -> V_107 = V_56 ;
V_53 -> V_108 = V_33 ;
}
static void F_63 ( struct V_52 * V_53 , T_1 * V_7 ,
struct V_1 * V_14 ,
unsigned int V_56 )
{
struct V_83 * V_84 ;
T_5 V_98 = F_64 ( T_5 , V_14 -> V_16 , V_109 ) ;
V_84 = F_52 ( V_53 , V_14 , V_56 , V_7 , V_98 ) ;
if ( F_7 ( V_84 == NULL ) ) {
struct V_12 * V_13 ;
V_13 = F_26 ( V_53 ) ;
F_24 ( V_13 , V_14 , V_56 ) ;
return;
}
F_50 ( V_84 , V_53 -> V_13 . V_95 ) ;
F_65 ( V_84 ) ;
if ( F_39 ( V_14 -> V_49 & V_89 ) )
V_84 -> V_88 = V_90 ;
if ( V_53 -> type -> V_110 )
if ( V_53 -> type -> V_110 ( V_53 , V_84 ) )
return;
F_66 ( V_84 ) ;
}
void F_67 ( struct V_52 * V_53 )
{
struct V_5 * V_6 = V_53 -> V_6 ;
struct V_1 * V_14 =
V_1 ( & V_53 -> V_13 , V_53 -> V_108 ) ;
T_1 * V_7 = F_1 ( V_14 ) ;
if ( V_14 -> V_49 & V_103 )
V_14 -> V_16 = F_68 ( ( V_111 * )
( V_7 + V_6 -> V_112 ) ) ;
if ( F_7 ( V_6 -> V_113 ) ) {
struct V_12 * V_13 ;
F_69 ( V_6 , V_7 , V_14 -> V_16 ) ;
V_13 = F_26 ( V_53 ) ;
F_24 ( V_13 , V_14 ,
V_53 -> V_107 ) ;
goto V_65;
}
if ( F_7 ( ! ( V_6 -> V_69 -> V_85 & V_114 ) ) )
V_14 -> V_49 &= ~ V_89 ;
if ( ( V_14 -> V_49 & V_115 ) && ! V_53 -> type -> V_110 )
F_45 ( V_53 , V_14 , V_53 -> V_107 , V_7 ) ;
else
F_63 ( V_53 , V_7 , V_14 , V_53 -> V_107 ) ;
V_65:
V_53 -> V_107 = 0 ;
}
int F_70 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
unsigned int V_116 ;
int V_60 ;
V_116 = F_71 ( F_72 ( V_6 -> V_63 ) , V_117 ) ;
F_31 ( V_116 > V_118 ) ;
V_13 -> V_15 = V_116 - 1 ;
F_73 ( V_6 , V_119 , V_6 -> V_69 ,
L_13 ,
F_33 ( V_13 ) , V_6 -> V_63 ,
V_13 -> V_15 ) ;
V_13 -> V_120 = F_74 ( V_116 , sizeof( * V_13 -> V_120 ) ,
V_45 ) ;
if ( ! V_13 -> V_120 )
return - V_46 ;
V_60 = F_75 ( V_13 ) ;
if ( V_60 ) {
F_76 ( V_13 -> V_120 ) ;
V_13 -> V_120 = NULL ;
}
return V_60 ;
}
static void F_77 ( struct V_5 * V_6 ,
struct V_12 * V_13 )
{
unsigned int V_121 , V_122 ;
#ifdef F_78
V_121 = V_123 ;
#else
if ( F_79 ( & V_124 ) )
V_121 = V_123 ;
else
V_121 = V_125 ;
#endif
V_122 = F_72 ( V_121 /
V_6 -> V_25 ) ;
V_13 -> V_36 = F_74 ( V_122 ,
sizeof( * V_13 -> V_36 ) , V_45 ) ;
V_13 -> V_35 = V_122 - 1 ;
}
void F_80 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
unsigned int V_67 , V_126 , V_127 ;
F_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,
L_14 , F_33 ( V_13 ) ) ;
V_13 -> V_48 = 0 ;
V_13 -> V_70 = 0 ;
V_13 -> V_62 = 0 ;
V_13 -> V_66 = - 1U ;
F_77 ( V_6 , V_13 ) ;
V_13 -> V_34 = 0 ;
V_13 -> V_37 = V_13 -> V_35 + 1 ;
V_13 -> V_38 = 0 ;
V_13 -> V_39 = 0 ;
V_13 -> V_55 = 0 ;
V_67 = V_6 -> V_63 - V_129 ;
V_127 =
V_67 - V_6 -> V_30 * V_6 -> V_25 ;
if ( V_130 != 0 ) {
V_126 = V_67 * F_81 ( V_130 , 100U ) / 100U ;
if ( V_126 > V_127 )
V_126 = V_127 ;
} else {
V_126 = V_127 ;
}
V_13 -> V_67 = V_67 ;
V_13 -> V_64 = V_126 ;
V_13 -> V_61 = true ;
F_82 ( V_13 ) ;
}
void F_83 ( struct V_12 * V_13 )
{
int V_131 ;
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_1 * V_14 ;
F_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,
L_15 , F_33 ( V_13 ) ) ;
F_84 ( & V_13 -> V_132 ) ;
if ( V_13 -> V_120 ) {
for ( V_131 = V_13 -> V_62 ; V_131 < V_13 -> V_48 ;
V_131 ++ ) {
unsigned V_33 = V_131 & V_13 -> V_15 ;
V_14 = V_1 ( V_13 , V_33 ) ;
F_27 ( V_13 , V_14 ) ;
}
}
for ( V_131 = 0 ; V_131 <= V_13 -> V_35 ; V_131 ++ ) {
struct V_3 * V_3 = V_13 -> V_36 [ V_131 ] ;
struct V_28 * V_32 ;
if ( V_3 == NULL )
continue;
V_32 = F_2 ( V_3 ) ;
F_15 ( & V_6 -> V_17 -> V_18 , V_32 -> V_19 ,
V_27 << V_6 -> V_26 ,
V_20 ) ;
F_16 ( V_3 ) ;
}
F_76 ( V_13 -> V_36 ) ;
V_13 -> V_36 = NULL ;
}
void F_85 ( struct V_12 * V_13 )
{
F_73 ( V_13 -> V_6 , V_128 , V_13 -> V_6 -> V_69 ,
L_16 , F_33 ( V_13 ) ) ;
F_86 ( V_13 ) ;
F_76 ( V_13 -> V_120 ) ;
V_13 -> V_120 = NULL ;
}
int F_87 ( struct V_133 * V_69 , const struct V_83 * V_84 ,
T_5 V_134 , T_2 V_135 )
{
struct V_5 * V_6 = F_88 ( V_69 ) ;
struct V_52 * V_53 ;
struct V_136 V_137 ;
struct V_138 V_139 ;
int V_60 ;
if ( V_135 == V_140 )
return - V_141 ;
if ( ! F_89 ( V_84 , & V_139 , 0 ) )
return - V_142 ;
if ( V_139 . V_143 . V_144 != F_90 ( V_145 ) && V_139 . V_143 . V_144 != F_90 ( V_146 ) )
return - V_142 ;
if ( V_139 . V_147 . V_49 & V_148 )
return - V_142 ;
F_91 ( & V_137 , V_149 ,
V_6 -> V_105 ? V_150 : 0 ,
V_134 ) ;
V_137 . V_151 =
V_152 | V_153 |
V_154 | V_155 |
V_156 | V_157 ;
V_137 . V_158 = V_139 . V_143 . V_144 ;
V_137 . V_159 = V_139 . V_143 . V_159 ;
if ( V_139 . V_143 . V_144 == F_90 ( V_145 ) ) {
V_137 . V_160 [ 0 ] = V_139 . V_161 . V_162 . V_163 ;
V_137 . V_164 [ 0 ] = V_139 . V_161 . V_162 . V_165 ;
} else {
memcpy ( V_137 . V_160 , & V_139 . V_161 . V_166 . V_163 , sizeof( struct V_167 ) ) ;
memcpy ( V_137 . V_164 , & V_139 . V_161 . V_166 . V_165 , sizeof( struct V_167 ) ) ;
}
V_137 . V_168 = V_139 . V_169 . V_163 ;
V_137 . V_170 = V_139 . V_169 . V_165 ;
V_60 = V_6 -> type -> V_171 ( V_6 , & V_137 ) ;
if ( V_60 < 0 )
return V_60 ;
V_53 = F_92 ( V_6 , V_134 ) ;
V_53 -> V_172 [ V_60 ] = V_135 ;
++ V_53 -> V_173 ;
if ( V_137 . V_158 == F_90 ( V_145 ) )
F_93 ( V_6 , V_68 , V_6 -> V_69 ,
L_17 ,
( V_137 . V_159 == V_174 ) ? L_18 : L_19 ,
V_137 . V_160 , F_94 ( V_137 . V_168 ) , V_137 . V_164 ,
F_94 ( V_137 . V_170 ) , V_134 , V_135 , V_60 ) ;
else
F_93 ( V_6 , V_68 , V_6 -> V_69 ,
L_20 ,
( V_137 . V_159 == V_174 ) ? L_18 : L_19 ,
V_137 . V_160 , F_94 ( V_137 . V_168 ) , V_137 . V_164 ,
F_94 ( V_137 . V_170 ) , V_134 , V_135 , V_60 ) ;
return V_60 ;
}
bool F_95 ( struct V_5 * V_6 , unsigned int V_175 )
{
bool (* F_96)( struct V_5 * V_6 , T_2 V_135 , unsigned int V_33 );
unsigned int V_176 , V_33 , V_177 ;
T_2 V_135 ;
if ( ! F_97 ( & V_6 -> V_178 ) )
return false ;
F_96 = V_6 -> type -> V_179 ;
V_176 = V_6 -> V_180 ;
V_33 = V_6 -> V_181 ;
V_177 = V_6 -> type -> V_182 ;
while ( V_175 -- ) {
struct V_52 * V_53 = F_92 ( V_6 , V_176 ) ;
V_135 = V_53 -> V_172 [ V_33 ] ;
if ( V_135 != V_140 &&
F_96 ( V_6 , V_135 , V_33 ) ) {
F_93 ( V_6 , V_68 , V_6 -> V_69 ,
L_21 ,
V_33 , V_176 , V_135 ) ;
V_53 -> V_172 [ V_33 ] = V_140 ;
}
if ( ++ V_33 == V_177 ) {
if ( ++ V_176 == V_6 -> V_183 )
V_176 = 0 ;
V_33 = 0 ;
}
}
V_6 -> V_180 = V_176 ;
V_6 -> V_181 = V_33 ;
F_98 ( & V_6 -> V_178 ) ;
return true ;
}
bool F_99 ( const struct V_136 * V_137 )
{
if ( ! ( V_137 -> V_49 & V_184 ) ||
V_137 -> V_185 == V_186 )
return false ;
if ( V_137 -> V_151 &
( V_187 | V_188 ) &&
F_100 ( V_137 -> V_189 ) )
return true ;
if ( ( V_137 -> V_151 &
( V_152 | V_154 ) ) ==
( V_152 | V_154 ) ) {
if ( V_137 -> V_158 == F_90 ( V_145 ) &&
F_101 ( V_137 -> V_164 [ 0 ] ) )
return true ;
if ( V_137 -> V_158 == F_90 ( V_146 ) &&
( ( const T_1 * ) V_137 -> V_164 ) [ 0 ] == 0xff )
return true ;
}
return false ;
}
