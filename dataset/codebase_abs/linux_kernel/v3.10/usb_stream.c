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
V_10 -> V_37 = V_26 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_22 = V_2 -> V_13 ;
V_10 -> V_38 = V_2 ;
V_10 -> V_39 = 1 ;
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
struct V_27 * V_28 , int V_40 , int V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
char * V_42 = ( char * ) V_4 + sizeof( * V_4 ) +
sizeof( struct V_43 ) *
V_4 -> V_44 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
V_2 -> V_45 [ V_30 ] = F_8 ( V_2 -> V_13 , V_46 ) ;
V_2 -> V_47 [ V_30 ] = F_8 ( V_2 -> V_13 , V_46 ) ;
}
F_4 ( V_2 , V_24 , V_2 -> V_45 , V_42 , V_28 , V_40 ) ;
F_4 ( V_2 , V_24 , V_2 -> V_47 , V_2 -> V_48 , V_28 ,
V_41 ) ;
}
static inline unsigned F_9 ( unsigned V_49 )
{
return ( ( V_49 << 13 ) + 62 ) / 125 ;
}
static inline unsigned F_10 ( unsigned V_49 )
{
return ( ( V_49 << 10 ) + 62 ) / 125 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
F_12 ( V_2 -> V_45 [ V_30 ] ) ;
V_2 -> V_45 [ V_30 ] = NULL ;
F_12 ( V_2 -> V_47 [ V_30 ] ) ;
V_2 -> V_47 [ V_30 ] = NULL ;
}
V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return;
F_13 ( ( unsigned long ) V_2 -> V_48 , F_14 ( V_4 -> V_50 ) ) ;
V_2 -> V_48 = NULL ;
F_13 ( ( unsigned long ) V_4 , F_14 ( V_4 -> V_51 ) ) ;
V_2 -> V_4 = NULL ;
}
struct V_3 * F_15 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned V_52 , unsigned V_53 ,
unsigned V_54 , unsigned V_24 ,
unsigned V_55 , unsigned V_9 )
{
int V_56 , V_57 ;
int V_40 , V_41 ;
int V_51 = sizeof( struct V_3 ) ;
int V_50 ;
int V_58 = V_28 -> V_59 == V_60 ? 8000 : 1000 ;
int V_61 ;
V_40 = F_16 ( V_28 , V_52 ) ;
V_41 = F_17 ( V_28 , V_53 ) ;
V_57 = V_24 ?
V_24 : F_5 ( V_28 , V_40 , 0 ) ;
V_56 = V_55 * V_58 / V_54 + 1 ;
if ( V_28 -> V_59 == V_60 )
V_56 = ( V_56 + 7 ) & ~ 7 ;
V_51 += V_56 * V_62 *
( V_57 + sizeof( struct V_43 ) ) ;
V_57 = F_5 ( V_28 , V_41 , 1 ) ;
V_50 = V_57 * V_56 * V_62 ;
if ( V_51 >= 256 * V_63 || V_50 >= 256 * V_63 ) {
F_18 ( V_64 L_3 ) ;
goto V_65;
}
V_61 = F_14 ( V_51 ) ;
V_2 -> V_4 = ( void * ) F_19 ( V_46 | V_66 | V_67 , V_61 ) ;
if ( ! V_2 -> V_4 ) {
F_18 ( V_64 L_4 ) ;
goto V_65;
}
V_2 -> V_4 -> V_8 . V_68 = V_69 ;
V_2 -> V_4 -> V_51 = V_51 ;
V_2 -> V_4 -> V_8 . V_54 = V_54 ;
V_2 -> V_4 -> V_8 . V_9 = V_9 ;
V_2 -> V_13 = V_56 ;
V_2 -> V_4 -> V_44 = V_56 * V_62 ;
V_2 -> V_4 -> V_8 . V_55 = V_55 ;
V_2 -> V_4 -> V_16 = V_9 * V_55 ;
V_2 -> V_4 -> V_50 = V_50 ;
V_61 = F_14 ( V_50 ) ;
V_2 -> V_48 =
( void * ) F_19 ( V_46 | V_66 | V_67 , V_61 ) ;
if ( ! V_2 -> V_48 ) {
F_18 ( V_64 L_4 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
if ( V_28 -> V_59 == V_70 )
V_2 -> V_7 = F_9 ( V_54 ) ;
else
V_2 -> V_7 = F_10 ( V_54 ) ;
F_7 ( V_2 , V_24 , V_28 , V_40 , V_41 ) ;
V_2 -> V_4 -> V_71 = V_72 ;
V_65:
return V_2 -> V_4 ;
}
static bool F_20 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
bool V_73 ;
if ( F_21 ( V_10 -> V_74 ) ) {
if ( V_10 -> V_74 != - V_75 && V_10 -> V_74 != - V_76 )
F_18 ( V_64 L_5 , V_10 -> V_74 ) ;
V_2 -> V_77 = 0x7FFFFFFF ;
return false ;
}
V_73 = V_2 -> V_77 == 0 ;
if ( ! V_73 )
V_2 -> V_78 = V_10 ;
return V_73 ;
}
static bool F_22 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
V_2 -> V_77 += V_10 -> V_22 ;
return F_20 ( V_2 , V_10 ) ;
}
static bool F_23 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
V_2 -> V_77 -= V_10 -> V_22 ;
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
struct V_10 * V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_10 * V_79 ;
struct V_35 * V_80 , * V_81 ;
int V_31 = 0 , V_12 = 0 , V_14 = 0 ;
V_79 = V_2 -> V_82 ;
V_81 = V_79 -> V_18 ;
for (; V_4 -> V_83 < 0 ; ++ V_31 , ++ V_4 -> V_83 ) {
struct V_10 * V_84 = V_2 -> V_85 ;
V_80 = V_84 -> V_18 +
V_84 -> V_22 + V_4 -> V_83 ;
V_14 = V_80 -> V_86 ;
V_81 [ V_31 ] . V_20 = V_14 ;
V_81 [ V_31 ] . V_19 = V_12 ;
V_12 += V_14 ;
}
for (;
V_4 -> V_83 < V_45 -> V_22 && V_31 < V_2 -> V_13 ;
++ V_31 , ++ V_4 -> V_83 ) {
V_14 = V_45 -> V_18 [ V_4 -> V_83 ] . V_86 ;
if ( V_4 -> V_15 + V_12 + V_14 > V_4 -> V_16 )
goto V_87;
V_81 [ V_31 ] . V_20 = V_14 ;
V_81 [ V_31 ] . V_19 = V_12 ;
V_12 += V_14 ;
}
V_87:
V_4 -> V_83 -= V_45 -> V_22 ;
if ( F_21 ( V_4 -> V_83 < - 2 || V_4 -> V_83 > 0 ) ) {
F_18 ( V_64 L_6
L_7 ,
V_4 -> V_83 , V_31 , V_45 -> V_22 ,
V_4 -> V_15 + V_12 + V_14 ,
V_4 -> V_15 , V_12 , V_14 ,
V_4 -> V_16 ) ;
return - 1 ;
}
if ( F_21 ( V_12 % V_4 -> V_8 . V_9 ) ) {
F_18 ( V_64 L_8 ,
V_12 ) ;
return - 1 ;
}
V_4 -> V_15 += V_12 - V_4 -> V_16 ;
V_79 -> V_22 = V_31 ;
V_79 -> V_23 = V_12 ;
if ( V_4 -> V_15 <= 0 )
return 0 ;
F_18 ( V_64 L_9 , V_4 -> V_15 ) ;
return - 1 ;
}
static void F_27 ( int V_22 , struct V_10 * V_88 )
{
struct V_35 * V_80 ;
int V_31 ;
V_88 -> V_22 = V_22 ;
V_80 = V_88 -> V_18 ;
V_80 -> V_19 = 0 ;
for ( V_31 = 0 ; V_31 < V_88 -> V_22 - 1 ; ++ V_31 )
V_80 [ V_31 + 1 ] . V_19 = V_80 [ V_31 ] . V_19 + V_80 [ V_31 ] . V_20 ;
V_88 -> V_23 =
V_80 [ 0 ] . V_20 * V_88 -> V_22 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_45 , struct V_10 * V_47 )
{
int V_89 ;
F_27 ( V_2 -> V_82 -> V_22 , V_2 -> V_90 ) ;
V_89 = F_29 ( V_2 -> V_90 , V_91 ) ;
if ( V_89 < 0 ) {
F_18 ( V_92 L_1 , V_89 ) ;
return V_89 ;
}
V_2 -> V_90 = V_2 -> V_85 ;
V_2 -> V_85 = V_45 ;
V_89 = F_29 ( V_2 -> V_82 , V_91 ) ;
if ( V_89 < 0 ) {
F_18 ( V_92 L_1 , V_89 ) ;
return V_89 ;
}
V_2 -> V_82 = V_2 -> V_93 ;
V_2 -> V_93 = V_47 ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
char * V_94 , * V_95 ;
int V_96 , V_97 , V_14 , V_31 ;
struct V_10 * V_88 ;
struct V_35 * V_80 ;
V_95 = V_4 -> V_98 ;
V_97 = V_4 -> V_99 ;
V_14 = 0 ;
if ( V_4 -> V_100 >= 0 ) {
V_88 = V_2 -> V_90 ;
V_80 = V_88 -> V_18 ;
V_31 = V_4 -> V_100 ;
} else
goto V_101;
V_102:
for (; V_31 < V_88 -> V_22 && V_14 < V_4 -> V_16 ; ++ V_31 ) {
V_94 = V_88 -> V_37 + V_80 [ V_31 ] . V_19 ;
V_96 = V_80 [ V_31 ] . V_86 ;
if ( V_14 + V_96 > V_4 -> V_16 )
V_96 = V_4 -> V_16 - V_14 ;
if ( V_96 <= V_97 ) {
memcpy ( V_95 , V_94 , V_96 ) ;
V_95 += V_96 ;
V_97 -= V_96 ;
} else {
memcpy ( V_95 , V_94 , V_97 ) ;
F_31 ( V_95 , V_97 ) ;
V_95 = V_4 -> V_103 ;
memcpy ( V_95 , V_94 + V_97 , V_96 - V_97 ) ;
V_95 += V_96 - V_97 ;
V_97 = V_4 -> V_16 - V_4 -> V_99 ;
}
V_14 += V_96 ;
}
if ( V_88 == V_2 -> V_85 ) {
if ( V_14 != V_4 -> V_16 )
F_32 ( V_21 L_10 , V_104 , __LINE__ ,
V_14 / ( int ) V_4 -> V_8 . V_9 ) ;
return;
}
V_101:
V_88 = V_2 -> V_85 ;
V_80 = V_88 -> V_18 ;
V_31 = 0 ;
goto V_102;
}
static void F_30 ( struct V_3 * V_4 )
{
}
static void F_33 ( struct V_1 * V_2 ,
struct V_10 * V_45 , struct V_10 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 , V_31 ;
int V_105 = V_4 -> V_106 ;
int V_107 = 0 ;
V_4 -> V_108 = V_4 -> V_109 ;
V_4 -> V_110 = V_4 -> V_111 ;
V_4 -> V_109 = - 1 ;
V_4 -> V_111 = 0 ;
for ( V_31 = 0 ; V_31 < V_45 -> V_22 ; ++ V_31 ) {
struct V_35 * V_80 = V_45 -> V_18 ;
V_14 = V_80 [ V_31 ] . V_86 ;
if ( F_21 ( V_14 == 0 || V_80 [ V_31 ] . V_74 ) ) {
F_18 ( V_64 L_11 ,
V_80 [ V_31 ] . V_74 ) ;
goto V_112;
}
V_4 -> V_113 ++ ;
V_4 -> V_113 %= V_4 -> V_44 ;
if ( V_4 -> V_108 == - 1 )
V_4 -> V_108 = V_4 -> V_113 ;
V_4 -> V_114 [ V_4 -> V_113 ] . V_19 =
V_80 [ V_31 ] . V_19 + ( V_45 -> V_37 - ( void * ) V_4 ) ;
V_4 -> V_114 [ V_4 -> V_113 ] . V_20 = V_14 ;
if ( V_105 + V_14 > V_4 -> V_16 &&
V_4 -> V_109 == - 1 ) {
V_4 -> V_109 = V_4 -> V_113 ;
V_4 -> V_111 = V_4 -> V_16 - V_105 ;
}
V_105 += V_14 ;
V_107 += V_14 ;
}
V_4 -> V_106 += V_107 - V_4 -> V_16 ;
if ( V_4 -> V_106 < 0 ) {
F_18 ( V_64 L_1 ,
( V_4 -> V_106 ) / ( int ) V_4 -> V_8 . V_9 ) ;
goto V_112;
}
V_4 -> V_115 += V_107 ;
V_14 = V_4 -> V_15 ;
V_4 -> V_116 [ 0 ] . V_19 = ( V_2 -> V_82 -> V_37 -
V_2 -> V_48 ) - V_14 ;
if ( F_26 ( V_2 , V_45 ) < 0 )
goto V_112;
V_4 -> V_116 [ 0 ] . V_20 = V_2 -> V_82 -> V_23 + V_14 ;
V_4 -> V_116 [ 1 ] . V_19 = V_2 -> V_93 -> V_37 -
V_2 -> V_48 ;
if ( F_28 ( V_2 , V_45 , V_47 ) < 0 )
goto V_112;
F_30 ( V_4 ) ;
V_4 -> V_117 ++ ;
F_34 ( & V_2 -> V_118 ) ;
return;
V_112:
V_4 -> V_71 = V_119 ;
F_34 ( & V_2 -> V_118 ) ;
}
static void F_35 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_38 ;
if ( F_23 ( V_2 , V_10 ) )
F_33 ( V_2 , V_10 , V_2 -> V_78 ) ;
}
static void F_36 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_38 ;
if ( F_22 ( V_2 , V_10 ) )
F_33 ( V_2 , V_2 -> V_78 , V_10 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_10 * V_45 , struct V_10 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_71 >= V_120 ) {
int V_14 , V_31 , V_121 , V_122 ;
int V_107 = 0 ;
unsigned V_123 , V_124 = 0 ;
V_123 = ( V_4 -> V_16 - V_4 -> V_106 ) ;
V_123 <<= 8 ;
V_123 /=
V_4 -> V_8 . V_9 * V_45 -> V_22 ;
V_123 ++ ;
V_122 = V_4 -> V_8 . V_9 ;
if ( V_4 -> V_8 . V_55 >= 256 )
V_122 <<= 1 ;
if ( V_4 -> V_8 . V_55 >= 1024 )
V_122 <<= 1 ;
V_121 = V_122 ;
for ( V_31 = 0 ; V_31 < V_45 -> V_22 ; ++ V_31 ) {
int V_125 ;
V_14 = V_45 -> V_18 [ V_31 ] . V_86 ;
V_107 += V_14 ;
V_124 += V_123 ;
V_125 = V_107 -
( V_124 >> 8 ) * V_4 -> V_8 . V_9 ;
if ( V_125 < V_121 ) {
F_3 ( V_21 L_12 ,
V_4 -> V_115 ,
V_107 / ( int ) V_4 -> V_8 . V_9 ,
V_45 -> V_22 , V_125 ) ;
V_121 = V_125 ;
}
}
V_4 -> V_106 -= V_121 - V_122 ;
V_4 -> V_106 += V_107 - V_4 -> V_16 ;
if ( V_4 -> V_106 < 0 ) {
F_18 ( V_64 L_13 ,
V_4 -> V_106 , V_107 , V_4 -> V_16 ) ;
return;
} else if ( V_4 -> V_106 == 0 ) {
V_4 -> V_109 =
( V_4 -> V_113 + 1 ) % V_4 -> V_44 ;
V_4 -> V_111 = 0 ;
} else {
unsigned V_126 = V_4 -> V_113 ;
V_14 = V_4 -> V_106 ;
while ( V_14 > V_4 -> V_114 [ V_126 ] . V_20 ) {
V_14 -= V_4 -> V_114 [ V_126 ] . V_20 ;
if ( V_126 == 0 )
V_126 = V_4 -> V_44 - 1 ;
else
V_126 -- ;
}
V_4 -> V_109 = V_126 ;
V_4 -> V_111 =
V_4 -> V_114 [ V_126 ] . V_20 - V_14 ;
}
V_4 -> V_115 += V_107 ;
if ( F_26 ( V_2 , V_45 ) < 0 )
return;
} else
F_2 ( V_2 , V_2 -> V_82 ) ;
if ( F_28 ( V_2 , V_45 , V_47 ) < 0 )
return;
if ( V_4 -> V_71 == V_120 && V_4 -> V_115 > 360000 ) {
V_4 -> V_71 = V_127 ;
F_24 ( V_2 -> V_45 , F_35 ) ;
F_24 ( V_2 -> V_47 , F_36 ) ;
}
}
static void F_38 ( struct V_10 * V_10 )
{
struct V_35 * V_80 = V_10 -> V_18 ;
struct V_1 * V_2 = V_10 -> V_38 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 ;
int V_128 = 0 ;
if ( V_10 -> V_74 ) {
F_18 ( V_64 L_5 , V_10 -> V_74 ) ;
return;
}
for ( V_31 = 0 ; V_31 < V_10 -> V_22 ; ++ V_31 ) {
int V_14 = V_80 [ V_31 ] . V_86 ;
if ( V_14 < V_4 -> V_8 . V_9 ) {
++ V_128 ;
if ( V_4 -> V_71 >= V_129 ) {
F_18 ( V_64 L_1 , V_14 ) ;
return;
}
}
V_4 -> V_113 ++ ;
V_4 -> V_113 %= V_4 -> V_44 ;
V_4 -> V_114 [ V_4 -> V_113 ] . V_19 =
V_80 [ V_31 ] . V_19 + ( V_10 -> V_37 - ( void * ) V_4 ) ;
V_4 -> V_114 [ V_4 -> V_113 ] . V_20 = V_14 ;
}
#ifdef F_39
if ( V_128 ) {
F_32 ( V_21 L_14 , V_104 , __LINE__ ,
V_10 -> V_18 [ 0 ] . V_86 ) ;
for ( V_11 = 1 ; V_11 < V_10 -> V_22 ; ++ V_11 ) {
int V_14 = V_10 -> V_18 [ V_11 ] . V_86 ;
F_32 ( L_15 , V_14 ) ;
}
F_32 ( L_16 ) ;
}
#endif
if ( ! V_128 && V_4 -> V_71 < V_120 )
++ V_4 -> V_71 ;
if ( F_23 ( V_2 , V_10 ) )
F_37 ( V_2 , V_10 , V_2 -> V_78 ) ;
}
static void F_40 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_38 ;
if ( F_22 ( V_2 , V_10 ) )
F_37 ( V_2 , V_2 -> V_78 , V_10 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_130 = 0 , V_131 = 0 ;
int V_30 , V_89 ;
int V_132 = 0 ;
if ( V_4 -> V_71 != V_72 )
return - V_133 ;
F_24 ( V_2 -> V_45 , F_38 ) ;
F_24 ( V_2 -> V_47 , F_40 ) ;
memset ( V_2 -> V_48 , 0 , V_4 -> V_50 ) ;
V_134:
V_4 -> V_115 = 0 ;
V_4 -> V_106 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_83 = - 1 ;
V_4 -> V_113 = - 1 ;
V_2 -> V_77 = 0 ;
++ V_132 ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
struct V_10 * V_45 = V_2 -> V_45 [ V_30 ] ;
struct V_10 * V_47 = V_2 -> V_47 [ V_30 ] ;
F_2 ( V_2 , V_47 ) ;
V_45 -> V_22 = V_47 -> V_22 ;
V_45 -> V_23 =
V_45 -> V_22 *
V_45 -> V_18 [ 0 ] . V_20 ;
if ( V_30 == 0 ) {
int V_135 ;
struct V_27 * V_28 = V_45 -> V_28 ;
V_130 = F_42 ( V_28 ) ;
do {
V_135 = F_42 ( V_28 ) ;
++ V_131 ;
} while ( V_135 > - 1 && V_135 == V_130 );
}
V_89 = F_29 ( V_45 , V_91 ) ;
if ( V_89 < 0 ) {
F_18 ( V_92 L_17
L_18 , V_30 , V_89 ) ;
return V_89 ;
}
V_89 = F_29 ( V_47 , V_91 ) ;
if ( V_89 < 0 ) {
F_18 ( V_92 L_19
L_18 , V_30 , V_89 ) ;
return V_89 ;
}
if ( V_45 -> V_136 != V_47 -> V_136 ) {
F_43 ( V_21
L_20 ,
V_30 , V_45 -> V_136 , V_47 -> V_136 ) ;
goto V_137;
}
}
F_3 ( V_21 L_21 , V_130 , V_131 ) ;
V_132 = 0 ;
V_137:
if ( V_132 ) {
F_44 ( V_2 ) ;
if ( V_132 < 5 ) {
F_45 ( 1500 ) ;
F_43 ( V_21 L_22 ) ;
goto V_134;
}
F_18 ( V_64 L_23
L_24 ) ;
return - V_138 ;
}
V_2 -> V_90 = V_2 -> V_45 [ V_34 - 2 ] ;
V_2 -> V_82 = V_2 -> V_47 [ V_34 - 2 ] ;
V_2 -> V_85 = V_2 -> V_45 [ V_34 - 1 ] ;
V_2 -> V_93 = V_2 -> V_47 [ V_34 - 1 ] ;
{
int V_139 = 3000 ;
while ( V_4 -> V_71 != V_127 && V_139 > 0 ) {
F_3 ( V_21 L_1 , V_4 -> V_71 ) ;
F_45 ( 200 ) ;
V_139 -= 200 ;
}
}
return V_4 -> V_71 == V_127 ? 0 : - V_138 ;
}
void F_44 ( struct V_1 * V_2 )
{
int V_30 ;
if ( ! V_2 -> V_4 )
return;
for ( V_30 = 0 ; V_30 < V_34 ; ++ V_30 ) {
F_46 ( V_2 -> V_45 [ V_30 ] ) ;
F_46 ( V_2 -> V_47 [ V_30 ] ) ;
}
V_2 -> V_4 -> V_71 = V_72 ;
F_45 ( 400 ) ;
}
