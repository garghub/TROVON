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
static struct V_30 *
F_13 (
struct V_1 * V_9 ,
struct V_30 * V_31 ,
T_1 V_32 ,
struct V_5 * V_6 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_33 ;
T_1 V_10 ;
int V_34 ;
int V_16 ;
int V_15 ;
T_1 V_35 ;
T_1 V_36 ;
V_6 -> V_23 = V_9 -> V_22 . V_23 ;
V_33 = F_3 ( V_6 ) ;
V_10 = 0 ;
V_34 = F_6 ( V_6 -> V_7 , V_6 -> V_8 , 0 ) ;
if ( ! ( V_9 -> V_20 & V_21 ) && V_34 == - 1 ) {
goto V_37;
}
V_31 -> V_38 = V_6 ;
V_31 -> V_39 = V_33 ;
V_31 -> V_40 = V_41 ;
V_31 ++ ;
V_10 = 1 ;
if ( V_9 -> V_20 & V_21 ) {
F_14 ( V_9 ) ;
ASSERT ( V_6 -> V_23 & V_24 ) ;
goto V_37;
}
V_16 = V_34 ;
V_35 = 1 ;
for (; ; ) {
V_15 = F_6 ( V_6 -> V_7 , V_6 -> V_8 ,
( T_1 ) V_16 + 1 ) ;
if ( V_15 == - 1 ) {
V_36 = V_32 + V_34 * V_17 ;
V_31 -> V_38 = F_7 ( V_13 , V_36 ) ;
V_31 -> V_39 = V_35 * V_17 ;
V_31 -> V_40 = V_42 ;
V_10 ++ ;
break;
} else if ( V_15 != V_16 + 1 ) {
V_36 = V_32 + V_34 * V_17 ;
V_31 -> V_38 = F_7 ( V_13 , V_36 ) ;
V_31 -> V_39 = V_35 * V_17 ;
V_31 -> V_40 = V_42 ;
V_10 ++ ;
V_31 ++ ;
V_34 = V_15 ;
V_16 = V_15 ;
V_35 = 1 ;
} else if ( F_7 ( V_13 , V_32 +
( V_15 << V_43 ) ) !=
( F_7 ( V_13 , V_32 +
( V_16 << V_43 ) ) +
V_17 ) ) {
V_36 = V_32 + V_34 * V_17 ;
V_31 -> V_38 = F_7 ( V_13 , V_36 ) ;
V_31 -> V_39 = V_35 * V_17 ;
V_31 -> V_40 = V_42 ;
V_10 ++ ;
V_31 ++ ;
V_34 = V_15 ;
V_16 = V_15 ;
V_35 = 1 ;
} else {
V_16 ++ ;
V_35 ++ ;
}
}
V_37:
V_6 -> V_44 = V_10 ;
return V_31 ;
}
STATIC void
F_15 (
struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_32 = 0 ;
int V_18 ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
ASSERT ( ( V_9 -> V_20 & V_27 ) ||
( V_9 -> V_20 & V_21 ) ) ;
if ( V_9 -> V_20 & V_45 ) {
if ( F_16 ( & V_3 -> V_46 -> V_47 ) ||
! ( ( V_9 -> V_20 & V_48 ) &&
F_17 ( V_3 ) ) )
V_9 -> V_22 . V_23 |= V_49 ;
V_9 -> V_20 &= ~ V_45 ;
}
if ( ( V_9 -> V_20 & ( V_28 | V_21 ) ) ==
V_28 ) {
F_18 ( V_9 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
V_31 = F_13 ( V_9 , V_31 , V_32 ,
& V_9 -> V_26 [ V_18 ] ) ;
V_32 += V_13 -> V_50 [ V_18 ] . V_51 ;
}
F_19 ( V_9 ) ;
}
STATIC void
F_20 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
ASSERT ( ( V_9 -> V_20 & V_27 ) ||
( V_9 -> V_20 & V_28 ) ||
( V_9 -> V_20 & V_21 ) ) ;
F_21 ( V_9 ) ;
F_22 ( & V_9 -> V_19 ) ;
F_22 ( & V_9 -> V_14 -> V_52 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 * V_13 = V_9 -> V_14 ;
struct V_53 * V_54 = V_3 -> V_55 ;
int V_56 = V_9 -> V_20 & V_21 ;
int V_57 ;
ASSERT ( V_13 -> V_58 == V_9 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
F_24 ( V_9 ) ;
V_57 = F_25 ( & V_9 -> V_19 ) ;
if ( F_25 ( & V_13 -> V_52 ) )
F_26 ( & V_13 -> V_59 ) ;
if ( V_57 && V_56 ) {
ASSERT ( V_9 -> V_20 & V_21 ) ;
ASSERT ( F_27 ( V_13 ) ) ;
ASSERT ( F_28 ( V_13 ) ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
F_29 ( V_9 ) ;
if ( remove ) {
if ( V_3 -> V_60 )
F_30 ( V_3 ) ;
V_13 -> V_61 = NULL ;
}
if ( V_9 -> V_20 & V_62 ) {
F_31 ( V_13 ) ;
V_13 -> V_58 = NULL ;
V_13 -> V_63 = NULL ;
} else {
F_32 ( & V_54 -> V_64 ) ;
F_33 ( V_54 , V_3 , V_65 ) ;
F_34 ( V_13 ) ;
ASSERT ( V_13 -> V_58 == NULL ) ;
}
F_35 ( V_13 ) ;
} else if ( V_57 && remove ) {
F_36 ( V_13 ) ;
F_37 ( V_13 ) ;
V_13 -> V_66 |= V_67 ;
F_38 ( V_13 , V_68 ) ;
F_39 ( V_13 ) ;
F_40 ( V_13 ) ;
F_41 ( V_13 , 0 ) ;
}
}
STATIC T_1
F_42 (
struct V_2 * V_3 ,
struct V_69 * V_70 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_71 = V_72 ;
if ( F_43 ( V_13 ) )
return V_73 ;
if ( ! F_44 ( V_13 ) ) {
if ( F_43 ( V_13 ) )
return V_73 ;
return V_74 ;
}
ASSERT ( ! ( V_9 -> V_20 & V_21 ) ) ;
F_45 ( V_9 ) ;
if ( ! F_46 ( V_13 , V_70 ) )
V_71 = V_75 ;
F_47 ( V_13 ) ;
return V_71 ;
}
STATIC void
F_48 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
bool V_76 ;
bool V_77 ;
int V_78 ;
V_13 -> V_61 = NULL ;
V_77 = ( V_3 -> V_79 & V_80 ) ? true : false ;
V_78 = V_9 -> V_20 ;
V_9 -> V_20 &= ~ ( V_27 | V_81 | V_28 ) ;
if ( V_78 & V_21 ) {
F_49 ( V_9 ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
if ( ! V_77 ) {
F_50 ( & V_9 -> V_19 ) ;
return;
}
}
F_51 ( V_9 ) ;
V_76 = ( V_78 & V_82 ) ? false : true ;
if ( V_76 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
if ( ! F_52 ( V_9 -> V_26 [ V_18 ] . V_7 ,
V_9 -> V_26 [ V_18 ] . V_8 ) ) {
V_76 = false ;
break;
}
}
}
if ( F_25 ( & V_9 -> V_19 ) ) {
if ( V_76 )
F_34 ( V_13 ) ;
else if ( V_77 ) {
ASSERT ( F_53 ( V_3 -> V_46 ) ) ;
if ( V_3 -> V_79 & V_83 ) {
F_32 ( & V_3 -> V_55 -> V_64 ) ;
F_33 ( V_3 -> V_55 , V_3 ,
V_65 ) ;
}
F_34 ( V_13 ) ;
}
}
if ( ! ( V_78 & V_81 ) )
F_35 ( V_13 ) ;
}
STATIC T_3
F_54 (
struct V_2 * V_3 ,
T_3 V_84 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_55 ( V_9 ) ;
if ( ( V_9 -> V_20 & V_48 ) && V_3 -> V_85 != 0 )
return V_3 -> V_85 ;
return V_84 ;
}
STATIC void
F_56 (
struct V_2 * V_3 ,
T_3 V_86 )
{
}
STATIC int
F_57 (
struct V_1 * V_9 ,
int V_87 )
{
ASSERT ( V_9 -> V_26 == NULL ) ;
V_9 -> V_25 = V_87 ;
if ( V_87 == 1 ) {
V_9 -> V_26 = & V_9 -> V_22 ;
return 0 ;
}
V_9 -> V_26 = F_58 ( V_87 * sizeof( struct V_5 ) ,
V_88 ) ;
if ( ! V_9 -> V_26 )
return V_89 ;
return 0 ;
}
STATIC void
F_59 (
struct V_1 * V_9 )
{
if ( V_9 -> V_26 != & V_9 -> V_22 ) {
F_60 ( V_9 -> V_26 ) ;
V_9 -> V_26 = NULL ;
}
}
void
F_61 (
T_2 * V_13 ,
T_4 * V_90 )
{
T_5 * V_3 = V_13 -> V_58 ;
T_6 * V_9 ;
int V_91 ;
int V_92 ;
int error ;
int V_18 ;
ASSERT ( V_13 -> V_93 -> V_94 == V_90 ) ;
if ( V_3 != NULL && V_3 -> V_95 == V_96 )
return;
V_9 = F_62 ( V_97 , V_88 ) ;
F_63 ( V_90 , & V_9 -> V_4 , V_96 , & V_98 ) ;
V_9 -> V_14 = V_13 ;
F_37 ( V_13 ) ;
error = F_57 ( V_9 , V_13 -> V_99 ) ;
ASSERT ( error == 0 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
V_91 = F_64 ( F_65 ( V_13 -> V_50 [ V_18 ] . V_51 ) ,
V_17 ) ;
V_92 = F_64 ( V_91 , V_100 ) ;
V_9 -> V_26 [ V_18 ] . V_101 = V_96 ;
V_9 -> V_26 [ V_18 ] . V_102 = V_13 -> V_50 [ V_18 ] . V_103 ;
V_9 -> V_26 [ V_18 ] . V_104 = V_13 -> V_50 [ V_18 ] . V_51 ;
V_9 -> V_26 [ V_18 ] . V_8 = V_92 ;
}
#ifdef F_66
V_9 -> V_105 = F_67 ( F_65 ( V_13 -> V_106 ) , V_88 ) ;
memcpy ( V_9 -> V_105 , V_13 -> V_107 , F_65 ( V_13 -> V_106 ) ) ;
V_9 -> V_108 = F_58 ( F_65 ( V_13 -> V_106 ) / V_109 , V_88 ) ;
#endif
if ( V_13 -> V_58 )
V_9 -> V_4 . V_110 = V_13 -> V_58 ;
V_13 -> V_58 = V_9 ;
}
void
F_68 (
struct V_1 * V_9 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 * V_113 )
{
T_1 V_34 ;
T_1 V_16 ;
T_1 V_114 ;
T_1 V_115 ;
T_1 V_116 ;
T_1 * V_117 ;
T_1 V_118 ;
T_1 V_119 ;
T_1 V_120 ;
V_34 = V_111 >> V_43 ;
V_16 = V_112 >> V_43 ;
V_114 = V_16 - V_34 + 1 ;
V_116 = V_34 >> V_121 ;
V_117 = & V_113 [ V_116 ] ;
V_118 = V_34 & ( T_1 ) ( V_100 - 1 ) ;
if ( V_118 ) {
V_119 = F_69 ( V_118 + V_114 , ( T_1 ) V_100 ) ;
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
F_70 (
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
V_123 = V_122 + F_65 ( V_13 -> V_50 [ V_18 ] . V_51 ) ;
if ( V_111 > V_123 ) {
V_122 += F_65 ( V_13 -> V_50 [ V_18 ] . V_51 ) ;
continue;
}
if ( V_111 < V_122 )
V_111 = V_122 ;
if ( V_123 > V_112 )
V_123 = V_112 ;
F_68 ( V_9 , V_111 , V_123 ,
& V_9 -> V_26 [ V_18 ] . V_7 [ 0 ] ) ;
V_122 += V_13 -> V_50 [ V_18 ] . V_51 ;
}
}
T_1
F_71 (
T_6 * V_9 )
{
return ( V_9 -> V_20 & V_82 ) ;
}
STATIC void
F_72 (
T_6 * V_9 )
{
#ifdef F_66
F_60 ( V_9 -> V_105 ) ;
F_60 ( V_9 -> V_108 ) ;
#endif
F_59 ( V_9 ) ;
F_73 ( V_97 , V_9 ) ;
}
void
F_34 (
T_2 * V_13 )
{
T_6 * V_9 = V_13 -> V_58 ;
F_74 ( V_13 , V_124 ) ;
ASSERT ( ! ( V_9 -> V_4 . V_79 & V_83 ) ) ;
V_13 -> V_58 = V_9 -> V_4 . V_110 ;
if ( V_13 -> V_58 == NULL )
V_13 -> V_63 = NULL ;
F_75 ( V_13 ) ;
F_72 ( V_9 ) ;
}
void
F_76 (
T_2 * V_13 ,
void (* F_77)( T_2 * , T_5 * ) ,
T_5 * V_3 )
{
T_5 * V_125 ;
ASSERT ( F_27 ( V_13 ) ) ;
V_3 -> V_126 = F_77 ;
V_125 = V_13 -> V_58 ;
if ( V_125 ) {
V_3 -> V_110 = V_125 -> V_110 ;
V_125 -> V_110 = V_3 ;
} else {
V_13 -> V_58 = V_3 ;
}
ASSERT ( V_13 -> V_63 == NULL ||
V_13 -> V_63 == V_127 ) ;
V_13 -> V_63 = V_127 ;
}
STATIC void
F_31 (
struct V_12 * V_13 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_13 -> V_58 ) != NULL ) {
V_13 -> V_58 = V_3 -> V_110 ;
ASSERT ( V_3 -> V_126 != NULL ) ;
V_3 -> V_110 = NULL ;
V_3 -> V_126 ( V_13 , V_3 ) ;
}
}
void
V_127 (
struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_58 ;
struct V_128 * V_90 = V_3 -> V_46 ;
static T_7 V_129 ;
static T_8 * V_130 ;
if ( F_78 ( ! F_79 ( V_13 ) ) )
goto V_131;
if ( F_53 ( V_90 ) ) {
F_40 ( V_13 ) ;
F_80 ( V_13 ) ;
F_81 ( V_13 , V_124 ) ;
goto V_131;
}
if ( V_13 -> V_93 != V_130 ||
F_82 ( V_132 , ( V_129 + 5 * V_133 ) ) ) {
V_129 = V_132 ;
F_83 ( V_13 , V_134 ) ;
}
V_130 = V_13 -> V_93 ;
if ( F_84 ( V_13 ) ) {
ASSERT ( V_13 -> V_63 != NULL ) ;
F_85 ( V_13 , V_124 ) ;
F_38 ( V_13 , 0 ) ;
if ( ! F_28 ( V_13 ) ) {
V_13 -> V_66 |= V_135 | V_67 | V_136 ;
F_86 ( V_13 ) ;
} else {
F_35 ( V_13 ) ;
}
return;
}
F_40 ( V_13 ) ;
F_80 ( V_13 ) ;
F_87 ( V_13 , V_124 ) ;
V_131:
F_31 ( V_13 ) ;
V_13 -> V_58 = NULL ;
V_13 -> V_63 = NULL ;
F_41 ( V_13 , 0 ) ;
}
void
F_88 (
struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_53 * V_54 = V_3 -> V_55 ;
ASSERT ( F_1 ( V_3 ) -> V_14 == V_13 ) ;
F_75 ( V_13 ) ;
F_32 ( & V_54 -> V_64 ) ;
F_33 ( V_54 , V_3 , V_137 ) ;
F_72 ( F_1 ( V_3 ) ) ;
}
