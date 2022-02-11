static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int
F_3 (
struct V_5 * V_6 )
{
return F_4 ( struct V_5 , V_7 ) +
( V_6 -> V_8 * sizeof( V_6 -> V_7 [ 0 ] ) ) ;
}
STATIC void
F_5 (
struct V_1 * V_9 ,
struct V_5 * V_6 ,
int * V_10 ,
int * V_11 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
int V_15 ;
int V_16 ;
V_16 = F_6 ( V_6 -> V_7 , V_6 -> V_8 , 0 ) ;
if ( V_16 == - 1 )
return;
* V_10 += 2 ;
* V_11 += F_3 ( V_6 ) + V_17 ;
while ( V_16 != - 1 ) {
V_15 = F_6 ( V_6 -> V_7 , V_6 -> V_8 ,
V_16 + 1 ) ;
if ( V_15 == - 1 ) {
break;
} else if ( V_15 != V_16 + 1 ) {
V_16 = V_15 ;
( * V_10 ) ++ ;
} else if ( F_7 ( V_13 , V_15 * V_17 ) !=
( F_7 ( V_13 , V_16 * V_17 ) +
V_17 ) ) {
V_16 = V_15 ;
( * V_10 ) ++ ;
} else {
V_16 ++ ;
}
* V_11 += V_17 ;
}
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int * V_10 ,
int * V_11 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_18 ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
if ( V_9 -> V_20 & V_21 ) {
F_10 ( V_9 ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
* V_10 += V_9 -> V_25 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
* V_11 += F_3 ( & V_9 -> V_26 [ V_18 ] ) ;
}
return;
}
ASSERT ( V_9 -> V_20 & V_27 ) ;
if ( V_9 -> V_20 & V_28 ) {
F_11 ( V_9 ) ;
* V_10 = V_29 ;
return;
}
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
F_5 ( V_9 , & V_9 -> V_26 [ V_18 ] ,
V_10 , V_11 ) ;
}
F_12 ( V_9 ) ;
}
static inline void
F_13 (
struct V_30 * V_31 ,
struct V_32 * * V_33 ,
struct V_12 * V_13 ,
T_1 V_34 ,
int V_35 ,
T_1 V_36 )
{
V_34 += V_35 * V_17 ;
F_14 ( V_31 , V_33 , V_37 ,
F_7 ( V_13 , V_34 ) ,
V_36 * V_17 ) ;
}
static inline bool
F_15 (
struct V_12 * V_13 ,
T_1 V_34 ,
int V_15 ,
int V_16 )
{
return F_7 ( V_13 , V_34 + ( V_15 << V_38 ) ) !=
( F_7 ( V_13 , V_34 + ( V_16 << V_38 ) ) +
V_17 ) ;
}
static void
F_16 (
struct V_1 * V_9 ,
struct V_30 * V_31 ,
struct V_32 * * V_33 ,
T_1 V_34 ,
struct V_5 * V_6 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_39 ;
int V_35 ;
int V_16 ;
int V_15 ;
T_1 V_36 ;
V_6 -> V_23 = V_9 -> V_22 . V_23 ;
V_39 = F_3 ( V_6 ) ;
V_35 = F_6 ( V_6 -> V_7 , V_6 -> V_8 , 0 ) ;
if ( ! ( V_9 -> V_20 & V_21 ) && V_35 == - 1 ) {
return;
}
V_6 = F_14 ( V_31 , V_33 , V_40 , V_6 , V_39 ) ;
V_6 -> V_41 = 1 ;
if ( V_9 -> V_20 & V_21 ) {
F_17 ( V_9 ) ;
ASSERT ( V_6 -> V_23 & V_24 ) ;
return;
}
V_16 = V_35 ;
V_36 = 1 ;
for (; ; ) {
V_15 = F_6 ( V_6 -> V_7 , V_6 -> V_8 ,
( T_1 ) V_16 + 1 ) ;
if ( V_15 == - 1 ) {
F_13 ( V_31 , V_33 , V_13 , V_34 ,
V_35 , V_36 ) ;
V_6 -> V_41 ++ ;
break;
} else if ( V_15 != V_16 + 1 ||
F_15 ( V_13 , V_34 , V_15 , V_16 ) ) {
F_13 ( V_31 , V_33 , V_13 , V_34 ,
V_35 , V_36 ) ;
V_6 -> V_41 ++ ;
V_35 = V_15 ;
V_16 = V_15 ;
V_36 = 1 ;
} else {
V_16 ++ ;
V_36 ++ ;
}
}
}
STATIC void
F_18 (
struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_32 * V_33 = NULL ;
T_1 V_34 = 0 ;
int V_18 ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
ASSERT ( ( V_9 -> V_20 & V_27 ) ||
( V_9 -> V_20 & V_21 ) ) ;
if ( V_9 -> V_20 & V_42 ) {
if ( F_19 ( & V_3 -> V_43 -> V_44 ) ||
! ( ( V_9 -> V_20 & V_45 ) &&
F_20 ( V_3 ) ) )
V_9 -> V_22 . V_23 |= V_46 ;
V_9 -> V_20 &= ~ V_42 ;
}
if ( ( V_9 -> V_20 & ( V_28 | V_21 ) ) ==
V_28 ) {
F_21 ( V_9 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
F_16 ( V_9 , V_31 , & V_33 , V_34 ,
& V_9 -> V_26 [ V_18 ] ) ;
V_34 += V_13 -> V_47 [ V_18 ] . V_48 ;
}
F_22 ( V_9 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
ASSERT ( ( V_9 -> V_20 & V_27 ) ||
( V_9 -> V_20 & V_28 ) ||
( V_9 -> V_20 & V_21 ) ) ;
F_24 ( V_9 ) ;
F_25 ( & V_9 -> V_19 ) ;
F_25 ( & V_9 -> V_14 -> V_49 ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 * V_13 = V_9 -> V_14 ;
struct V_50 * V_51 = V_3 -> V_52 ;
int V_53 = V_9 -> V_20 & V_21 ;
int V_54 ;
ASSERT ( V_13 -> V_55 == V_9 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
F_27 ( V_9 ) ;
V_54 = F_28 ( & V_9 -> V_19 ) ;
if ( F_28 ( & V_13 -> V_49 ) )
F_29 ( & V_13 -> V_56 ) ;
if ( V_54 && V_53 ) {
ASSERT ( V_9 -> V_20 & V_21 ) ;
ASSERT ( F_30 ( V_13 ) ) ;
ASSERT ( F_31 ( V_13 ) ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
F_32 ( V_9 ) ;
if ( remove ) {
if ( V_3 -> V_57 )
F_33 ( V_3 ) ;
V_13 -> V_58 = NULL ;
}
if ( V_9 -> V_20 & V_59 ) {
F_34 ( V_13 ) ;
V_13 -> V_55 = NULL ;
V_13 -> V_60 = NULL ;
} else {
F_35 ( & V_51 -> V_61 ) ;
F_36 ( V_51 , V_3 , V_62 ) ;
F_37 ( V_13 ) ;
ASSERT ( V_13 -> V_55 == NULL ) ;
}
F_38 ( V_13 ) ;
} else if ( V_54 && remove ) {
F_39 ( V_13 ) ;
F_40 ( V_13 ) ;
V_13 -> V_63 |= V_64 ;
F_41 ( V_13 , V_65 ) ;
F_42 ( V_13 ) ;
F_43 ( V_13 ) ;
F_44 ( V_13 , 0 ) ;
}
}
STATIC T_1
F_45 (
struct V_2 * V_3 ,
struct V_66 * V_67 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_68 = V_69 ;
if ( F_46 ( V_13 ) )
return V_70 ;
if ( ! F_47 ( V_13 ) ) {
if ( F_46 ( V_13 ) )
return V_70 ;
return V_71 ;
}
ASSERT ( ! ( V_9 -> V_20 & V_21 ) ) ;
F_48 ( V_9 ) ;
if ( ( V_13 -> V_63 & V_72 ) &&
F_49 ( & V_73 , L_1 ) ) {
F_50 ( V_13 -> V_74 -> V_75 ,
L_2 ,
( long long ) V_13 -> V_76 ) ;
}
if ( ! F_51 ( V_13 , V_67 ) )
V_68 = V_77 ;
F_52 ( V_13 ) ;
return V_68 ;
}
STATIC void
F_53 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
bool V_78 ;
bool V_79 ;
int V_80 ;
V_13 -> V_58 = NULL ;
V_79 = ( V_3 -> V_81 & V_82 ) ? true : false ;
V_80 = V_9 -> V_20 ;
V_9 -> V_20 &= ~ ( V_27 | V_83 | V_28 ) ;
if ( V_80 & V_21 ) {
F_54 ( V_9 ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
if ( ! V_79 ) {
F_55 ( & V_9 -> V_19 ) ;
return;
}
}
F_56 ( V_9 ) ;
V_78 = ( V_80 & V_84 ) ? false : true ;
if ( V_78 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
if ( ! F_57 ( V_9 -> V_26 [ V_18 ] . V_7 ,
V_9 -> V_26 [ V_18 ] . V_8 ) ) {
V_78 = false ;
break;
}
}
}
if ( F_28 ( & V_9 -> V_19 ) ) {
if ( V_78 )
F_37 ( V_13 ) ;
else if ( V_79 ) {
ASSERT ( F_58 ( V_3 -> V_43 ) ) ;
if ( V_3 -> V_81 & V_85 ) {
F_35 ( & V_3 -> V_52 -> V_61 ) ;
F_36 ( V_3 -> V_52 , V_3 ,
V_62 ) ;
}
F_37 ( V_13 ) ;
}
}
if ( ! ( V_80 & V_83 ) )
F_38 ( V_13 ) ;
}
STATIC T_3
F_59 (
struct V_2 * V_3 ,
T_3 V_86 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_60 ( V_9 ) ;
if ( ( V_9 -> V_20 & V_45 ) && V_3 -> V_87 != 0 )
return V_3 -> V_87 ;
return V_86 ;
}
STATIC void
F_61 (
struct V_2 * V_3 ,
T_3 V_88 )
{
}
STATIC int
F_62 (
struct V_1 * V_9 ,
int V_89 )
{
ASSERT ( V_9 -> V_26 == NULL ) ;
V_9 -> V_25 = V_89 ;
if ( V_89 == 1 ) {
V_9 -> V_26 = & V_9 -> V_22 ;
return 0 ;
}
V_9 -> V_26 = F_63 ( V_89 * sizeof( struct V_5 ) ,
V_90 ) ;
if ( ! V_9 -> V_26 )
return V_91 ;
return 0 ;
}
STATIC void
F_64 (
struct V_1 * V_9 )
{
if ( V_9 -> V_26 != & V_9 -> V_22 ) {
F_65 ( V_9 -> V_26 ) ;
V_9 -> V_26 = NULL ;
}
}
void
F_66 (
T_2 * V_13 ,
T_4 * V_92 )
{
T_5 * V_3 = V_13 -> V_55 ;
T_6 * V_9 ;
int V_93 ;
int V_94 ;
int error ;
int V_18 ;
ASSERT ( V_13 -> V_74 -> V_75 == V_92 ) ;
if ( V_3 != NULL && V_3 -> V_95 == V_96 )
return;
V_9 = F_67 ( V_97 , V_90 ) ;
F_68 ( V_92 , & V_9 -> V_4 , V_96 , & V_98 ) ;
V_9 -> V_14 = V_13 ;
F_40 ( V_13 ) ;
error = F_62 ( V_9 , V_13 -> V_99 ) ;
ASSERT ( error == 0 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
V_93 = F_69 ( F_70 ( V_13 -> V_47 [ V_18 ] . V_48 ) ,
V_17 ) ;
V_94 = F_69 ( V_93 , V_100 ) ;
V_9 -> V_26 [ V_18 ] . V_101 = V_96 ;
V_9 -> V_26 [ V_18 ] . V_102 = V_13 -> V_47 [ V_18 ] . V_103 ;
V_9 -> V_26 [ V_18 ] . V_104 = V_13 -> V_47 [ V_18 ] . V_48 ;
V_9 -> V_26 [ V_18 ] . V_8 = V_94 ;
}
#ifdef F_71
V_9 -> V_105 = F_72 ( F_70 ( V_13 -> V_106 ) , V_90 ) ;
memcpy ( V_9 -> V_105 , V_13 -> V_107 , F_70 ( V_13 -> V_106 ) ) ;
V_9 -> V_108 = F_63 ( F_70 ( V_13 -> V_106 ) / V_109 , V_90 ) ;
#endif
if ( V_13 -> V_55 )
V_9 -> V_4 . V_110 = V_13 -> V_55 ;
V_13 -> V_55 = V_9 ;
}
static void
F_73 (
struct V_1 * V_9 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 * V_113 )
{
T_1 V_35 ;
T_1 V_16 ;
T_1 V_114 ;
T_1 V_115 ;
T_1 V_116 ;
T_1 * V_117 ;
T_1 V_118 ;
T_1 V_119 ;
T_1 V_120 ;
V_35 = V_111 >> V_38 ;
V_16 = V_112 >> V_38 ;
V_114 = V_16 - V_35 + 1 ;
V_116 = V_35 >> V_121 ;
V_117 = & V_113 [ V_116 ] ;
V_118 = V_35 & ( T_1 ) ( V_100 - 1 ) ;
if ( V_118 ) {
V_119 = F_74 ( V_118 + V_114 , ( T_1 ) V_100 ) ;
V_120 = ( ( 1 << ( V_119 - V_118 ) ) - 1 ) << V_118 ;
* V_117 |= V_120 ;
V_117 ++ ;
V_115 = V_119 - V_118 ;
} else {
V_115 = 0 ;
}
while ( ( V_114 - V_115 ) >= V_100 ) {
* V_117 |= 0xffffffff ;
V_115 += V_100 ;
V_117 ++ ;
}
V_119 = V_114 - V_115 ;
if ( V_119 ) {
V_120 = ( 1 << V_119 ) - 1 ;
* V_117 |= V_120 ;
}
}
void
F_75 (
T_6 * V_9 ,
T_1 V_111 ,
T_1 V_112 )
{
int V_18 ;
T_1 V_122 ;
T_1 V_123 ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_122 = 0 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
if ( V_122 > V_112 )
break;
V_123 = V_122 + F_70 ( V_13 -> V_47 [ V_18 ] . V_48 ) ;
if ( V_111 > V_123 ) {
V_122 += F_70 ( V_13 -> V_47 [ V_18 ] . V_48 ) ;
continue;
}
if ( V_111 < V_122 )
V_111 = V_122 ;
if ( V_123 > V_112 )
V_123 = V_112 ;
F_73 ( V_9 , V_111 , V_123 ,
& V_9 -> V_26 [ V_18 ] . V_7 [ 0 ] ) ;
V_122 += V_13 -> V_47 [ V_18 ] . V_48 ;
}
}
T_1
F_76 (
T_6 * V_9 )
{
return ( V_9 -> V_20 & V_84 ) ;
}
STATIC void
F_77 (
T_6 * V_9 )
{
#ifdef F_71
F_65 ( V_9 -> V_105 ) ;
F_65 ( V_9 -> V_108 ) ;
#endif
F_64 ( V_9 ) ;
F_78 ( V_97 , V_9 ) ;
}
void
F_37 (
T_2 * V_13 )
{
T_6 * V_9 = V_13 -> V_55 ;
F_79 ( V_13 , V_124 ) ;
ASSERT ( ! ( V_9 -> V_4 . V_81 & V_85 ) ) ;
V_13 -> V_55 = V_9 -> V_4 . V_110 ;
if ( V_13 -> V_55 == NULL )
V_13 -> V_60 = NULL ;
F_80 ( V_13 ) ;
F_77 ( V_9 ) ;
}
void
F_81 (
T_2 * V_13 ,
void (* F_82)( T_2 * , T_5 * ) ,
T_5 * V_3 )
{
T_5 * V_125 ;
ASSERT ( F_30 ( V_13 ) ) ;
V_3 -> V_126 = F_82 ;
V_125 = V_13 -> V_55 ;
if ( V_125 ) {
V_3 -> V_110 = V_125 -> V_110 ;
V_125 -> V_110 = V_3 ;
} else {
V_13 -> V_55 = V_3 ;
}
ASSERT ( V_13 -> V_60 == NULL ||
V_13 -> V_60 == V_127 ) ;
V_13 -> V_60 = V_127 ;
}
STATIC void
F_34 (
struct V_12 * V_13 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_13 -> V_55 ) != NULL ) {
V_13 -> V_55 = V_3 -> V_110 ;
ASSERT ( V_3 -> V_126 != NULL ) ;
V_3 -> V_110 = NULL ;
V_3 -> V_126 ( V_13 , V_3 ) ;
}
}
void
V_127 (
struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_55 ;
struct V_128 * V_92 = V_3 -> V_43 ;
static T_7 V_129 ;
static T_8 * V_130 ;
if ( F_83 ( ! F_84 ( V_13 ) ) )
goto V_131;
if ( F_58 ( V_92 ) ) {
F_43 ( V_13 ) ;
F_85 ( V_13 ) ;
F_86 ( V_13 , V_124 ) ;
goto V_131;
}
if ( V_13 -> V_74 != V_130 ||
F_87 ( V_132 , ( V_129 + 5 * V_133 ) ) ) {
V_129 = V_132 ;
F_88 ( V_13 , V_134 ) ;
}
V_130 = V_13 -> V_74 ;
if ( F_89 ( V_13 ) ) {
ASSERT ( V_13 -> V_60 != NULL ) ;
F_90 ( V_13 , V_124 ) ;
F_41 ( V_13 , 0 ) ;
if ( ! ( V_13 -> V_63 & ( V_135 | V_72 ) ) ) {
V_13 -> V_63 |= V_136 | V_64 |
V_137 | V_72 ;
F_91 ( V_13 ) ;
} else {
F_38 ( V_13 ) ;
}
return;
}
F_43 ( V_13 ) ;
F_85 ( V_13 ) ;
F_92 ( V_13 , V_124 ) ;
V_131:
F_34 ( V_13 ) ;
V_13 -> V_55 = NULL ;
V_13 -> V_60 = NULL ;
F_44 ( V_13 , 0 ) ;
}
void
F_93 (
struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
ASSERT ( F_1 ( V_3 ) -> V_14 == V_13 ) ;
F_80 ( V_13 ) ;
F_35 ( & V_51 -> V_61 ) ;
F_36 ( V_51 , V_3 , V_138 ) ;
F_77 ( F_1 ( V_3 ) ) ;
}
