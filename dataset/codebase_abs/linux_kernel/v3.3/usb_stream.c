static unsigned F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_5 = ( V_2 -> V_6 & 0xffff ) + V_2 -> V_7 ;
return ( V_2 -> V_5 >> 16 ) * V_4 -> V_8 . V_9 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_11 , V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_13 ; V_11 ++ ) {
int V_14 = F_1 ( V_2 ) ;
if ( V_4 -> V_15 + V_12 + V_14 > V_4 -> V_16 )
goto V_17;
V_2 -> V_6 = V_2 -> V_5 ;
V_10 -> V_18 [ V_11 ] . V_19 = V_12 ;
V_10 -> V_18 [ V_11 ] . V_20 = V_14 ;
V_12 += V_14 ;
}
F_3 ( V_21 L_1 , V_12 ) ;
V_17:
V_10 -> V_22 = V_11 ;
V_10 -> V_23 = V_12 ;
V_4 -> V_15 += V_12 - V_4 -> V_16 ;
F_3 ( V_21 L_2 , V_4 -> V_15 ,
V_12 , V_4 -> V_16 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_24 ,
struct V_10 * * V_25 , char * V_26 ,
struct V_27 * V_28 , int V_29 )
{
int V_30 , V_31 ;
int V_32 = V_24 ?
V_24 : F_5 ( V_28 , V_29 , F_6 ( V_29 ) ) ;
int V_33 = V_32 * V_2 -> V_13 ;
for ( V_30 = 0 ; V_30 < V_34 ;
++ V_30 , V_26 += V_33 ) {
struct V_10 * V_10 = V_25 [ V_30 ] ;
struct V_35 * V_36 ;
V_10 -> V_37 = V_38 ;
V_10 -> V_39 = V_26 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_22 = V_2 -> V_13 ;
V_10 -> V_40 = V_2 ;
V_10 -> V_41 = 1 ;
if ( F_6 ( V_29 ) )
continue;
V_10 -> V_23 = V_33 ;
V_36 = V_10 -> V_18 ;
V_36 -> V_19 = 0 ;
V_36 -> V_20 = V_32 ;
for ( V_31 = 1 ; V_31 < V_2 -> V_13 ; ++ V_31 ) {
V_36 [ V_31 ] . V_19 = V_36 [ V_31 - 1 ] . V_19 + V_32 ;
V_36 [ V_31 ] . V_20 = V_32 ;
}
}
}
static void F_7 ( struct V_1 * V_2 , unsigned V_24 ,
struct V_27 * V_28 , int V_42 , int V_43 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
char * V_44 = ( char * ) V_4 + sizeof( * V_4 ) +
sizeof( struct V_45 ) *
V_4 -> V_46 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
V_2 -> V_47 [ V_30 ] = F_8 ( V_2 -> V_13 , V_48 ) ;
V_2 -> V_49 [ V_30 ] = F_8 ( V_2 -> V_13 , V_48 ) ;
}
F_4 ( V_2 , V_24 , V_2 -> V_47 , V_44 , V_28 , V_42 ) ;
F_4 ( V_2 , V_24 , V_2 -> V_49 , V_2 -> V_50 , V_28 ,
V_43 ) ;
}
static inline unsigned F_9 ( unsigned V_51 )
{
return ( ( V_51 << 13 ) + 62 ) / 125 ;
}
static inline unsigned F_10 ( unsigned V_51 )
{
return ( ( V_51 << 10 ) + 62 ) / 125 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
F_12 ( V_2 -> V_47 [ V_30 ] ) ;
V_2 -> V_47 [ V_30 ] = NULL ;
F_12 ( V_2 -> V_49 [ V_30 ] ) ;
V_2 -> V_49 [ V_30 ] = NULL ;
}
V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return;
F_13 ( ( unsigned long ) V_2 -> V_50 , F_14 ( V_4 -> V_52 ) ) ;
V_2 -> V_50 = NULL ;
F_13 ( ( unsigned long ) V_4 , F_14 ( V_4 -> V_53 ) ) ;
V_2 -> V_4 = NULL ;
}
struct V_3 * F_15 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned V_54 , unsigned V_55 ,
unsigned V_56 , unsigned V_24 ,
unsigned V_57 , unsigned V_9 )
{
int V_58 , V_59 ;
int V_42 , V_43 ;
int V_53 = sizeof( struct V_3 ) ;
int V_52 ;
int V_60 = V_28 -> V_61 == V_62 ? 8000 : 1000 ;
int V_63 ;
V_42 = F_16 ( V_28 , V_54 ) ;
V_43 = F_17 ( V_28 , V_55 ) ;
V_59 = V_24 ?
V_24 : F_5 ( V_28 , V_42 , 0 ) ;
V_58 = V_57 * V_60 / V_56 + 1 ;
if ( V_28 -> V_61 == V_62 )
V_58 = ( V_58 + 7 ) & ~ 7 ;
V_53 += V_58 * V_64 *
( V_59 + sizeof( struct V_45 ) ) ;
V_59 = F_5 ( V_28 , V_43 , 1 ) ;
V_52 = V_59 * V_58 * V_64 ;
if ( V_53 >= 256 * V_65 || V_52 >= 256 * V_65 ) {
F_18 ( V_66 L_3 ) ;
goto V_67;
}
V_63 = F_14 ( V_53 ) ;
V_2 -> V_4 = ( void * ) F_19 ( V_48 | V_68 | V_69 , V_63 ) ;
if ( ! V_2 -> V_4 ) {
F_18 ( V_66 L_4 ) ;
goto V_67;
}
V_2 -> V_4 -> V_8 . V_70 = V_71 ;
V_2 -> V_4 -> V_53 = V_53 ;
V_2 -> V_4 -> V_8 . V_56 = V_56 ;
V_2 -> V_4 -> V_8 . V_9 = V_9 ;
V_2 -> V_13 = V_58 ;
V_2 -> V_4 -> V_46 = V_58 * V_64 ;
V_2 -> V_4 -> V_8 . V_57 = V_57 ;
V_2 -> V_4 -> V_16 = V_9 * V_57 ;
V_2 -> V_4 -> V_52 = V_52 ;
V_63 = F_14 ( V_52 ) ;
V_2 -> V_50 =
( void * ) F_19 ( V_48 | V_68 | V_69 , V_63 ) ;
if ( ! V_2 -> V_50 ) {
F_18 ( V_66 L_4 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
if ( V_28 -> V_61 == V_72 )
V_2 -> V_7 = F_9 ( V_56 ) ;
else
V_2 -> V_7 = F_10 ( V_56 ) ;
F_7 ( V_2 , V_24 , V_28 , V_42 , V_43 ) ;
V_2 -> V_4 -> V_73 = V_74 ;
V_67:
return V_2 -> V_4 ;
}
static bool F_20 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
bool V_75 ;
if ( F_21 ( V_10 -> V_76 ) ) {
if ( V_10 -> V_76 != - V_77 && V_10 -> V_76 != - V_78 )
F_18 ( V_66 L_5 , V_10 -> V_76 ) ;
V_2 -> V_79 = 0x7FFFFFFF ;
return false ;
}
V_75 = V_2 -> V_79 == 0 ;
if ( ! V_75 )
V_2 -> V_80 = V_10 ;
return V_75 ;
}
static bool F_22 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
V_2 -> V_79 += V_10 -> V_22 ;
return F_20 ( V_2 , V_10 ) ;
}
static bool F_23 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
V_2 -> V_79 -= V_10 -> V_22 ;
return F_20 ( V_2 , V_10 ) ;
}
static void F_24 ( struct V_10 * * V_25 , void (* F_25)( struct V_10 * ) )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_34 ; V_30 ++ ) {
struct V_10 * V_10 = V_25 [ V_30 ] ;
V_10 -> F_25 = F_25 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_10 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_10 * V_81 ;
struct V_35 * V_82 , * V_83 ;
int V_31 = 0 , V_12 = 0 , V_14 = 0 ;
V_81 = V_2 -> V_84 ;
V_83 = V_81 -> V_18 ;
for (; V_4 -> V_85 < 0 ; ++ V_31 , ++ V_4 -> V_85 ) {
struct V_10 * V_86 = V_2 -> V_87 ;
V_82 = V_86 -> V_18 +
V_86 -> V_22 + V_4 -> V_85 ;
V_14 = V_82 -> V_88 ;
V_83 [ V_31 ] . V_20 = V_14 ;
V_83 [ V_31 ] . V_19 = V_12 ;
V_12 += V_14 ;
}
for (;
V_4 -> V_85 < V_47 -> V_22 && V_31 < V_2 -> V_13 ;
++ V_31 , ++ V_4 -> V_85 ) {
V_14 = V_47 -> V_18 [ V_4 -> V_85 ] . V_88 ;
if ( V_4 -> V_15 + V_12 + V_14 > V_4 -> V_16 )
goto V_89;
V_83 [ V_31 ] . V_20 = V_14 ;
V_83 [ V_31 ] . V_19 = V_12 ;
V_12 += V_14 ;
}
V_89:
V_4 -> V_85 -= V_47 -> V_22 ;
if ( F_21 ( V_4 -> V_85 < - 2 || V_4 -> V_85 > 0 ) ) {
F_18 ( V_66 L_6
L_7 ,
V_4 -> V_85 , V_31 , V_47 -> V_22 ,
V_4 -> V_15 + V_12 + V_14 ,
V_4 -> V_15 , V_12 , V_14 ,
V_4 -> V_16 ) ;
return - 1 ;
}
if ( F_21 ( V_12 % V_4 -> V_8 . V_9 ) ) {
F_18 ( V_66 L_8 ,
V_12 ) ;
return - 1 ;
}
V_4 -> V_15 += V_12 - V_4 -> V_16 ;
V_81 -> V_22 = V_31 ;
V_81 -> V_23 = V_12 ;
if ( V_4 -> V_15 <= 0 )
return 0 ;
F_18 ( V_66 L_9 , V_4 -> V_15 ) ;
return - 1 ;
}
static void F_27 ( int V_22 , struct V_10 * V_90 )
{
struct V_35 * V_82 ;
int V_31 ;
V_90 -> V_22 = V_22 ;
V_82 = V_90 -> V_18 ;
V_82 -> V_19 = 0 ;
for ( V_31 = 0 ; V_31 < V_90 -> V_22 - 1 ; ++ V_31 )
V_82 [ V_31 + 1 ] . V_19 = V_82 [ V_31 ] . V_19 + V_82 [ V_31 ] . V_20 ;
V_90 -> V_23 =
V_82 [ 0 ] . V_20 * V_90 -> V_22 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_47 , struct V_10 * V_49 )
{
int V_91 ;
F_27 ( V_2 -> V_84 -> V_22 , V_2 -> V_92 ) ;
V_91 = F_29 ( V_2 -> V_92 , V_93 ) ;
if ( V_91 < 0 ) {
F_18 ( V_94 L_1 , V_91 ) ;
return V_91 ;
}
V_2 -> V_92 = V_2 -> V_87 ;
V_2 -> V_87 = V_47 ;
V_91 = F_29 ( V_2 -> V_84 , V_93 ) ;
if ( V_91 < 0 ) {
F_18 ( V_94 L_1 , V_91 ) ;
return V_91 ;
}
V_2 -> V_84 = V_2 -> V_95 ;
V_2 -> V_95 = V_49 ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
char * V_96 , * V_97 ;
int V_98 , V_99 , V_14 , V_31 ;
struct V_10 * V_90 ;
struct V_35 * V_82 ;
V_97 = V_4 -> V_100 ;
V_99 = V_4 -> V_101 ;
V_14 = 0 ;
if ( V_4 -> V_102 >= 0 ) {
V_90 = V_2 -> V_92 ;
V_82 = V_90 -> V_18 ;
V_31 = V_4 -> V_102 ;
} else
goto V_103;
V_104:
for (; V_31 < V_90 -> V_22 && V_14 < V_4 -> V_16 ; ++ V_31 ) {
V_96 = V_90 -> V_39 + V_82 [ V_31 ] . V_19 ;
V_98 = V_82 [ V_31 ] . V_88 ;
if ( V_14 + V_98 > V_4 -> V_16 )
V_98 = V_4 -> V_16 - V_14 ;
if ( V_98 <= V_99 ) {
memcpy ( V_97 , V_96 , V_98 ) ;
V_97 += V_98 ;
V_99 -= V_98 ;
} else {
memcpy ( V_97 , V_96 , V_99 ) ;
F_31 ( V_97 , V_99 ) ;
V_97 = V_4 -> V_105 ;
memcpy ( V_97 , V_96 + V_99 , V_98 - V_99 ) ;
V_97 += V_98 - V_99 ;
V_99 = V_4 -> V_16 - V_4 -> V_101 ;
}
V_14 += V_98 ;
}
if ( V_90 == V_2 -> V_87 ) {
if ( V_14 != V_4 -> V_16 )
F_32 ( V_21 L_10 , V_106 , __LINE__ ,
V_14 / ( int ) V_4 -> V_8 . V_9 ) ;
return;
}
V_103:
V_90 = V_2 -> V_87 ;
V_82 = V_90 -> V_18 ;
V_31 = 0 ;
goto V_104;
}
static void F_30 ( struct V_3 * V_4 )
{
}
static void F_33 ( struct V_1 * V_2 ,
struct V_10 * V_47 , struct V_10 * V_49 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 , V_31 ;
int V_107 = V_4 -> V_108 ;
int V_109 = 0 ;
V_4 -> V_110 = V_4 -> V_111 ;
V_4 -> V_112 = V_4 -> V_113 ;
V_4 -> V_111 = - 1 ;
V_4 -> V_113 = 0 ;
for ( V_31 = 0 ; V_31 < V_47 -> V_22 ; ++ V_31 ) {
struct V_35 * V_82 = V_47 -> V_18 ;
V_14 = V_82 [ V_31 ] . V_88 ;
if ( F_21 ( V_14 == 0 || V_82 [ V_31 ] . V_76 ) ) {
F_18 ( V_66 L_11 ,
V_82 [ V_31 ] . V_76 ) ;
goto V_114;
}
V_4 -> V_115 ++ ;
V_4 -> V_115 %= V_4 -> V_46 ;
if ( V_4 -> V_110 == - 1 )
V_4 -> V_110 = V_4 -> V_115 ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_19 =
V_82 [ V_31 ] . V_19 + ( V_47 -> V_39 - ( void * ) V_4 ) ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_20 = V_14 ;
if ( V_107 + V_14 > V_4 -> V_16 &&
V_4 -> V_111 == - 1 ) {
V_4 -> V_111 = V_4 -> V_115 ;
V_4 -> V_113 = V_4 -> V_16 - V_107 ;
}
V_107 += V_14 ;
V_109 += V_14 ;
}
V_4 -> V_108 += V_109 - V_4 -> V_16 ;
if ( V_4 -> V_108 < 0 ) {
F_18 ( V_66 L_1 ,
( V_4 -> V_108 ) / ( int ) V_4 -> V_8 . V_9 ) ;
goto V_114;
}
V_4 -> V_117 += V_109 ;
V_14 = V_4 -> V_15 ;
V_4 -> V_118 [ 0 ] . V_19 = ( V_2 -> V_84 -> V_39 -
V_2 -> V_50 ) - V_14 ;
if ( F_26 ( V_2 , V_47 ) < 0 )
goto V_114;
V_4 -> V_118 [ 0 ] . V_20 = V_2 -> V_84 -> V_23 + V_14 ;
V_4 -> V_118 [ 1 ] . V_19 = V_2 -> V_95 -> V_39 -
V_2 -> V_50 ;
if ( F_28 ( V_2 , V_47 , V_49 ) < 0 )
goto V_114;
F_30 ( V_4 ) ;
V_4 -> V_119 ++ ;
F_34 ( & V_2 -> V_120 ) ;
return;
V_114:
V_4 -> V_73 = V_121 ;
F_34 ( & V_2 -> V_120 ) ;
}
static void F_35 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_40 ;
if ( F_23 ( V_2 , V_10 ) )
F_33 ( V_2 , V_10 , V_2 -> V_80 ) ;
}
static void F_36 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_40 ;
if ( F_22 ( V_2 , V_10 ) )
F_33 ( V_2 , V_2 -> V_80 , V_10 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_10 * V_47 , struct V_10 * V_49 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_73 >= V_122 ) {
int V_14 , V_31 , V_123 , V_124 ;
int V_109 = 0 ;
unsigned V_125 , V_126 = 0 ;
V_125 = ( V_4 -> V_16 - V_4 -> V_108 ) ;
V_125 <<= 8 ;
V_125 /=
V_4 -> V_8 . V_9 * V_47 -> V_22 ;
V_125 ++ ;
V_124 = V_4 -> V_8 . V_9 ;
if ( V_4 -> V_8 . V_57 >= 256 )
V_124 <<= 1 ;
if ( V_4 -> V_8 . V_57 >= 1024 )
V_124 <<= 1 ;
V_123 = V_124 ;
for ( V_31 = 0 ; V_31 < V_47 -> V_22 ; ++ V_31 ) {
int V_127 ;
V_14 = V_47 -> V_18 [ V_31 ] . V_88 ;
V_109 += V_14 ;
V_126 += V_125 ;
V_127 = V_109 -
( V_126 >> 8 ) * V_4 -> V_8 . V_9 ;
if ( V_127 < V_123 ) {
F_3 ( V_21 L_12 ,
V_4 -> V_117 ,
V_109 / ( int ) V_4 -> V_8 . V_9 ,
V_47 -> V_22 , V_127 ) ;
V_123 = V_127 ;
}
}
V_4 -> V_108 -= V_123 - V_124 ;
V_4 -> V_108 += V_109 - V_4 -> V_16 ;
if ( V_4 -> V_108 < 0 ) {
F_18 ( V_66 L_13 ,
V_4 -> V_108 , V_109 , V_4 -> V_16 ) ;
return;
} else if ( V_4 -> V_108 == 0 ) {
V_4 -> V_111 =
( V_4 -> V_115 + 1 ) % V_4 -> V_46 ;
V_4 -> V_113 = 0 ;
} else {
unsigned V_128 = V_4 -> V_115 ;
V_14 = V_4 -> V_108 ;
while ( V_14 > V_4 -> V_116 [ V_128 ] . V_20 ) {
V_14 -= V_4 -> V_116 [ V_128 ] . V_20 ;
if ( V_128 == 0 )
V_128 = V_4 -> V_46 - 1 ;
else
V_128 -- ;
}
V_4 -> V_111 = V_128 ;
V_4 -> V_113 =
V_4 -> V_116 [ V_128 ] . V_20 - V_14 ;
}
V_4 -> V_117 += V_109 ;
if ( F_26 ( V_2 , V_47 ) < 0 )
return;
} else
F_2 ( V_2 , V_2 -> V_84 ) ;
if ( F_28 ( V_2 , V_47 , V_49 ) < 0 )
return;
if ( V_4 -> V_73 == V_122 && V_4 -> V_117 > 360000 ) {
V_4 -> V_73 = V_129 ;
F_24 ( V_2 -> V_47 , F_35 ) ;
F_24 ( V_2 -> V_49 , F_36 ) ;
}
}
static void F_38 ( struct V_10 * V_10 )
{
struct V_35 * V_82 = V_10 -> V_18 ;
struct V_1 * V_2 = V_10 -> V_40 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 ;
int V_130 = 0 ;
if ( V_10 -> V_76 ) {
F_18 ( V_66 L_5 , V_10 -> V_76 ) ;
return;
}
for ( V_31 = 0 ; V_31 < V_10 -> V_22 ; ++ V_31 ) {
int V_14 = V_82 [ V_31 ] . V_88 ;
if ( V_14 < V_4 -> V_8 . V_9 ) {
++ V_130 ;
if ( V_4 -> V_73 >= V_131 ) {
F_18 ( V_66 L_1 , V_14 ) ;
return;
}
}
V_4 -> V_115 ++ ;
V_4 -> V_115 %= V_4 -> V_46 ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_19 =
V_82 [ V_31 ] . V_19 + ( V_10 -> V_39 - ( void * ) V_4 ) ;
V_4 -> V_116 [ V_4 -> V_115 ] . V_20 = V_14 ;
}
#ifdef F_39
if ( V_130 ) {
F_32 ( V_21 L_14 , V_106 , __LINE__ ,
V_10 -> V_18 [ 0 ] . V_88 ) ;
for ( V_11 = 1 ; V_11 < V_10 -> V_22 ; ++ V_11 ) {
int V_14 = V_10 -> V_18 [ V_11 ] . V_88 ;
F_32 ( L_15 , V_14 ) ;
}
F_32 ( L_16 ) ;
}
#endif
if ( ! V_130 && V_4 -> V_73 < V_122 )
++ V_4 -> V_73 ;
if ( F_23 ( V_2 , V_10 ) )
F_37 ( V_2 , V_10 , V_2 -> V_80 ) ;
}
static void F_40 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_40 ;
if ( F_22 ( V_2 , V_10 ) )
F_37 ( V_2 , V_2 -> V_80 , V_10 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_132 = 0 , V_133 = 0 ;
int V_30 , V_91 ;
int V_134 = 0 ;
if ( V_4 -> V_73 != V_74 )
return - V_135 ;
F_24 ( V_2 -> V_47 , F_38 ) ;
F_24 ( V_2 -> V_49 , F_40 ) ;
memset ( V_2 -> V_50 , 0 , V_4 -> V_52 ) ;
V_136:
V_4 -> V_117 = 0 ;
V_4 -> V_108 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_85 = - 1 ;
V_4 -> V_115 = - 1 ;
V_2 -> V_79 = 0 ;
++ V_134 ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
struct V_10 * V_47 = V_2 -> V_47 [ V_30 ] ;
struct V_10 * V_49 = V_2 -> V_49 [ V_30 ] ;
F_2 ( V_2 , V_49 ) ;
V_47 -> V_22 = V_49 -> V_22 ;
V_47 -> V_23 =
V_47 -> V_22 *
V_47 -> V_18 [ 0 ] . V_20 ;
if ( V_30 == 0 ) {
int V_137 ;
struct V_27 * V_28 = V_47 -> V_28 ;
V_132 = F_42 ( V_28 ) ;
do {
V_137 = F_42 ( V_28 ) ;
++ V_133 ;
} while ( V_137 > - 1 && V_137 == V_132 );
}
V_91 = F_29 ( V_47 , V_93 ) ;
if ( V_91 < 0 ) {
F_18 ( V_94 L_17
L_18 , V_30 , V_91 ) ;
return V_91 ;
}
V_91 = F_29 ( V_49 , V_93 ) ;
if ( V_91 < 0 ) {
F_18 ( V_94 L_19
L_18 , V_30 , V_91 ) ;
return V_91 ;
}
if ( V_47 -> V_138 != V_49 -> V_138 ) {
F_43 ( V_21
L_20 ,
V_30 , V_47 -> V_138 , V_49 -> V_138 ) ;
goto V_139;
}
}
F_3 ( V_21 L_21 , V_132 , V_133 ) ;
V_134 = 0 ;
V_139:
if ( V_134 ) {
F_44 ( V_2 ) ;
if ( V_134 < 5 ) {
F_45 ( 1500 ) ;
F_43 ( V_21 L_22 ) ;
goto V_136;
}
F_18 ( V_66 L_23
L_24 ) ;
return - V_140 ;
}
V_2 -> V_92 = V_2 -> V_47 [ V_34 - 2 ] ;
V_2 -> V_84 = V_2 -> V_49 [ V_34 - 2 ] ;
V_2 -> V_87 = V_2 -> V_47 [ V_34 - 1 ] ;
V_2 -> V_95 = V_2 -> V_49 [ V_34 - 1 ] ;
{
int V_141 = 3000 ;
while ( V_4 -> V_73 != V_129 && V_141 > 0 ) {
F_3 ( V_21 L_1 , V_4 -> V_73 ) ;
F_45 ( 200 ) ;
V_141 -= 200 ;
}
}
return V_4 -> V_73 == V_129 ? 0 : - V_140 ;
}
void F_44 ( struct V_1 * V_2 )
{
int V_30 ;
if ( ! V_2 -> V_4 )
return;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
F_46 ( V_2 -> V_47 [ V_30 ] ) ;
F_46 ( V_2 -> V_49 [ V_30 ] ) ;
}
V_2 -> V_4 -> V_73 = V_74 ;
F_45 ( 400 ) ;
}
