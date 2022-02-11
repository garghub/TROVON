static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC T_1
F_3 (
struct V_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_11 ;
int V_12 ;
int V_13 ;
V_13 = F_4 ( V_7 -> V_14 , V_7 -> V_15 , 0 ) ;
if ( V_13 == - 1 )
return 0 ;
V_11 = 2 ;
while ( V_13 != - 1 ) {
V_12 = F_4 ( V_7 -> V_14 , V_7 -> V_15 ,
V_13 + 1 ) ;
if ( V_12 == - 1 ) {
break;
} else if ( V_12 != V_13 + 1 ) {
V_13 = V_12 ;
V_11 ++ ;
} else if ( F_5 ( V_9 , V_12 * V_16 ) !=
( F_5 ( V_9 , V_13 * V_16 ) +
V_16 ) ) {
V_13 = V_12 ;
V_11 ++ ;
} else {
V_13 ++ ;
}
}
return V_11 ;
}
STATIC T_1
F_6 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_11 ;
int V_17 ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
if ( V_5 -> V_19 & V_20 ) {
F_8 ( V_5 ) ;
ASSERT ( V_5 -> V_21 . V_22 & V_23 ) ;
return V_5 -> V_24 ;
}
ASSERT ( V_5 -> V_19 & V_25 ) ;
if ( V_5 -> V_19 & V_26 ) {
F_9 ( V_5 ) ;
return V_27 ;
}
V_11 = 0 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_11 += F_3 ( V_5 , & V_5 -> V_28 [ V_17 ] ) ;
}
F_10 ( V_5 ) ;
return V_11 ;
}
static struct V_29 *
F_11 (
struct V_1 * V_5 ,
struct V_29 * V_30 ,
T_1 V_31 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_32 ;
T_1 V_11 ;
int V_33 ;
int V_13 ;
int V_12 ;
T_1 V_34 ;
T_1 V_35 ;
V_7 -> V_22 = V_5 -> V_21 . V_22 ;
V_32 = F_12 ( struct V_6 , V_14 ) +
( V_7 -> V_15 * sizeof( V_7 -> V_14 [ 0 ] ) ) ;
V_11 = 0 ;
V_33 = F_4 ( V_7 -> V_14 , V_7 -> V_15 , 0 ) ;
if ( ! ( V_5 -> V_19 & V_20 ) && V_33 == - 1 ) {
goto V_36;
}
V_30 -> V_37 = V_7 ;
V_30 -> V_38 = V_32 ;
V_30 -> V_39 = V_40 ;
V_30 ++ ;
V_11 = 1 ;
if ( V_5 -> V_19 & V_20 ) {
F_13 ( V_5 ) ;
ASSERT ( V_7 -> V_22 & V_23 ) ;
goto V_36;
}
V_13 = V_33 ;
V_34 = 1 ;
for (; ; ) {
V_12 = F_4 ( V_7 -> V_14 , V_7 -> V_15 ,
( T_1 ) V_13 + 1 ) ;
if ( V_12 == - 1 ) {
V_35 = V_31 + V_33 * V_16 ;
V_30 -> V_37 = F_5 ( V_9 , V_35 ) ;
V_30 -> V_38 = V_34 * V_16 ;
V_30 -> V_39 = V_41 ;
V_11 ++ ;
break;
} else if ( V_12 != V_13 + 1 ) {
V_35 = V_31 + V_33 * V_16 ;
V_30 -> V_37 = F_5 ( V_9 , V_35 ) ;
V_30 -> V_38 = V_34 * V_16 ;
V_30 -> V_39 = V_41 ;
V_11 ++ ;
V_30 ++ ;
V_33 = V_12 ;
V_13 = V_12 ;
V_34 = 1 ;
} else if ( F_5 ( V_9 , V_31 +
( V_12 << V_42 ) ) !=
( F_5 ( V_9 , V_31 +
( V_13 << V_42 ) ) +
V_16 ) ) {
V_35 = V_31 + V_33 * V_16 ;
V_30 -> V_37 = F_5 ( V_9 , V_35 ) ;
V_30 -> V_38 = V_34 * V_16 ;
V_30 -> V_39 = V_41 ;
V_11 ++ ;
V_30 ++ ;
V_33 = V_12 ;
V_13 = V_12 ;
V_34 = 1 ;
} else {
V_13 ++ ;
V_34 ++ ;
}
}
V_36:
V_7 -> V_43 = V_11 ;
return V_30 ;
}
STATIC void
F_14 (
struct V_2 * V_3 ,
struct V_29 * V_30 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_31 = 0 ;
int V_17 ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
ASSERT ( ( V_5 -> V_19 & V_25 ) ||
( V_5 -> V_19 & V_20 ) ) ;
if ( V_5 -> V_19 & V_44 ) {
if ( F_15 ( & V_3 -> V_45 -> V_46 ) ||
! ( ( V_5 -> V_19 & V_47 ) &&
F_16 ( V_3 ) ) )
V_5 -> V_21 . V_22 |= V_48 ;
V_5 -> V_19 &= ~ V_44 ;
}
if ( ( V_5 -> V_19 & ( V_26 | V_20 ) ) ==
V_26 ) {
F_17 ( V_5 ) ;
return;
}
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_30 = F_11 ( V_5 , V_30 , V_31 ,
& V_5 -> V_28 [ V_17 ] ) ;
V_31 += V_9 -> V_49 [ V_17 ] . V_50 ;
}
F_18 ( V_5 ) ;
}
STATIC void
F_19 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
ASSERT ( ( V_5 -> V_19 & V_25 ) ||
( V_5 -> V_19 & V_26 ) ||
( V_5 -> V_19 & V_20 ) ) ;
F_20 ( V_5 ) ;
F_21 ( & V_5 -> V_18 ) ;
F_21 ( & V_5 -> V_10 -> V_51 ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 * V_9 = V_5 -> V_10 ;
struct V_52 * V_53 = V_3 -> V_54 ;
int V_55 = V_5 -> V_19 & V_20 ;
int V_56 ;
ASSERT ( V_9 -> V_57 == V_5 ) ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
F_23 ( V_5 ) ;
V_56 = F_24 ( & V_5 -> V_18 ) ;
if ( F_24 ( & V_9 -> V_51 ) )
F_25 ( & V_9 -> V_58 ) ;
if ( V_56 && V_55 ) {
ASSERT ( V_5 -> V_19 & V_20 ) ;
ASSERT ( F_26 ( V_9 ) ) ;
ASSERT ( F_27 ( V_9 ) ) ;
ASSERT ( V_5 -> V_21 . V_22 & V_23 ) ;
F_28 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_59 )
F_29 ( V_3 ) ;
V_9 -> V_60 = NULL ;
}
if ( V_5 -> V_19 & V_61 ) {
F_30 ( V_9 ) ;
V_9 -> V_57 = NULL ;
V_9 -> V_62 = NULL ;
} else {
F_31 ( & V_53 -> V_63 ) ;
F_32 ( V_53 , V_3 , V_64 ) ;
F_33 ( V_9 ) ;
ASSERT ( V_9 -> V_57 == NULL ) ;
}
F_34 ( V_9 ) ;
} else if ( V_56 && remove ) {
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
V_9 -> V_65 |= V_66 ;
F_37 ( V_9 , V_67 ) ;
F_38 ( V_9 ) ;
F_39 ( V_9 ) ;
F_40 ( V_9 , 0 ) ;
}
}
STATIC T_1
F_41 (
struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_70 = V_71 ;
if ( F_42 ( V_9 ) )
return V_72 ;
if ( ! F_43 ( V_9 ) ) {
if ( F_42 ( V_9 ) )
return V_72 ;
return V_73 ;
}
ASSERT ( ! ( V_5 -> V_19 & V_20 ) ) ;
F_44 ( V_5 ) ;
if ( ! F_45 ( V_9 , V_69 ) )
V_70 = V_74 ;
F_46 ( V_9 ) ;
return V_70 ;
}
STATIC void
F_47 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
bool V_75 ;
bool V_76 ;
int V_77 ;
V_9 -> V_60 = NULL ;
V_76 = ( V_3 -> V_78 & V_79 ) ? true : false ;
V_77 = V_5 -> V_19 ;
V_5 -> V_19 &= ~ ( V_25 | V_80 | V_26 ) ;
if ( V_77 & V_20 ) {
F_48 ( V_5 ) ;
ASSERT ( V_5 -> V_21 . V_22 & V_23 ) ;
if ( ! V_76 ) {
F_49 ( & V_5 -> V_18 ) ;
return;
}
}
F_50 ( V_5 ) ;
V_75 = ( V_77 & V_81 ) ? false : true ;
if ( V_75 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
if ( ! F_51 ( V_5 -> V_28 [ V_17 ] . V_14 ,
V_5 -> V_28 [ V_17 ] . V_15 ) ) {
V_75 = false ;
break;
}
}
}
if ( V_75 )
F_33 ( V_9 ) ;
else if ( V_76 ) {
if ( F_24 ( & V_5 -> V_18 ) ) {
ASSERT ( F_52 ( V_3 -> V_45 ) ) ;
F_33 ( V_9 ) ;
}
} else
F_49 ( & V_5 -> V_18 ) ;
if ( ! ( V_77 & V_80 ) )
F_34 ( V_9 ) ;
}
STATIC T_3
F_53 (
struct V_2 * V_3 ,
T_3 V_82 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_54 ( V_5 ) ;
if ( ( V_5 -> V_19 & V_47 ) && V_3 -> V_83 != 0 )
return V_3 -> V_83 ;
return V_82 ;
}
STATIC void
F_55 (
struct V_2 * V_3 ,
T_3 V_84 )
{
}
STATIC int
F_56 (
struct V_1 * V_5 ,
int V_85 )
{
ASSERT ( V_5 -> V_28 == NULL ) ;
V_5 -> V_24 = V_85 ;
if ( V_85 == 1 ) {
V_5 -> V_28 = & V_5 -> V_21 ;
return 0 ;
}
V_5 -> V_28 = F_57 ( V_85 * sizeof( struct V_6 ) ,
V_86 ) ;
if ( ! V_5 -> V_28 )
return V_87 ;
return 0 ;
}
STATIC void
F_58 (
struct V_1 * V_5 )
{
if ( V_5 -> V_28 != & V_5 -> V_21 ) {
F_59 ( V_5 -> V_28 ) ;
V_5 -> V_28 = NULL ;
}
}
void
F_60 (
T_2 * V_9 ,
T_4 * V_88 )
{
T_5 * V_3 = V_9 -> V_57 ;
T_6 * V_5 ;
int V_89 ;
int V_90 ;
int error ;
int V_17 ;
ASSERT ( V_9 -> V_91 -> V_92 == V_88 ) ;
if ( V_3 != NULL && V_3 -> V_93 == V_94 )
return;
V_5 = F_61 ( V_95 , V_86 ) ;
F_62 ( V_88 , & V_5 -> V_4 , V_94 , & V_96 ) ;
V_5 -> V_10 = V_9 ;
F_36 ( V_9 ) ;
error = F_56 ( V_5 , V_9 -> V_97 ) ;
ASSERT ( error == 0 ) ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_89 = F_63 ( F_64 ( V_9 -> V_49 [ V_17 ] . V_50 ) ,
V_16 ) ;
V_90 = F_63 ( V_89 , V_98 ) ;
V_5 -> V_28 [ V_17 ] . V_99 = V_94 ;
V_5 -> V_28 [ V_17 ] . V_100 = V_9 -> V_49 [ V_17 ] . V_101 ;
V_5 -> V_28 [ V_17 ] . V_102 = V_9 -> V_49 [ V_17 ] . V_50 ;
V_5 -> V_28 [ V_17 ] . V_15 = V_90 ;
}
#ifdef F_65
V_5 -> V_103 = F_66 ( F_64 ( V_9 -> V_104 ) , V_86 ) ;
memcpy ( V_5 -> V_103 , V_9 -> V_105 , F_64 ( V_9 -> V_104 ) ) ;
V_5 -> V_106 = F_57 ( F_64 ( V_9 -> V_104 ) / V_107 , V_86 ) ;
#endif
if ( V_9 -> V_57 )
V_5 -> V_4 . V_108 = V_9 -> V_57 ;
V_9 -> V_57 = V_5 ;
}
void
F_67 (
struct V_1 * V_5 ,
T_1 V_109 ,
T_1 V_110 ,
T_1 * V_111 )
{
T_1 V_33 ;
T_1 V_13 ;
T_1 V_112 ;
T_1 V_113 ;
T_1 V_114 ;
T_1 * V_115 ;
T_1 V_116 ;
T_1 V_117 ;
T_1 V_118 ;
V_33 = V_109 >> V_42 ;
V_13 = V_110 >> V_42 ;
V_112 = V_13 - V_33 + 1 ;
V_114 = V_33 >> V_119 ;
V_115 = & V_111 [ V_114 ] ;
V_116 = V_33 & ( T_1 ) ( V_98 - 1 ) ;
if ( V_116 ) {
V_117 = F_68 ( V_116 + V_112 , ( T_1 ) V_98 ) ;
V_118 = ( ( 1 << ( V_117 - V_116 ) ) - 1 ) << V_116 ;
* V_115 |= V_118 ;
V_115 ++ ;
V_113 = V_117 - V_116 ;
} else {
V_113 = 0 ;
}
while ( ( V_112 - V_113 ) >= V_98 ) {
* V_115 |= 0xffffffff ;
V_113 += V_98 ;
V_115 ++ ;
}
V_117 = V_112 - V_113 ;
if ( V_117 ) {
V_118 = ( 1 << V_117 ) - 1 ;
* V_115 |= V_118 ;
}
}
void
F_69 (
T_6 * V_5 ,
T_1 V_109 ,
T_1 V_110 )
{
int V_17 ;
T_1 V_120 ;
T_1 V_121 ;
struct V_8 * V_9 = V_5 -> V_10 ;
V_120 = 0 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
if ( V_120 > V_110 )
break;
V_121 = V_120 + F_64 ( V_9 -> V_49 [ V_17 ] . V_50 ) ;
if ( V_109 > V_121 ) {
V_120 += F_64 ( V_9 -> V_49 [ V_17 ] . V_50 ) ;
continue;
}
if ( V_109 < V_120 )
V_109 = V_120 ;
if ( V_121 > V_110 )
V_121 = V_110 ;
F_67 ( V_5 , V_109 , V_121 ,
& V_5 -> V_28 [ V_17 ] . V_14 [ 0 ] ) ;
V_120 += V_9 -> V_49 [ V_17 ] . V_50 ;
}
}
T_1
F_70 (
T_6 * V_5 )
{
return ( V_5 -> V_19 & V_81 ) ;
}
STATIC void
F_71 (
T_6 * V_5 )
{
#ifdef F_65
F_59 ( V_5 -> V_103 ) ;
F_59 ( V_5 -> V_106 ) ;
#endif
F_58 ( V_5 ) ;
F_72 ( V_95 , V_5 ) ;
}
void
F_33 (
T_2 * V_9 )
{
T_6 * V_5 = V_9 -> V_57 ;
F_73 ( V_9 , V_122 ) ;
ASSERT ( ! ( V_5 -> V_4 . V_78 & V_123 ) ) ;
V_9 -> V_57 = V_5 -> V_4 . V_108 ;
if ( V_9 -> V_57 == NULL )
V_9 -> V_62 = NULL ;
F_74 ( V_9 ) ;
F_71 ( V_5 ) ;
}
void
F_75 (
T_2 * V_9 ,
void (* F_76)( T_2 * , T_5 * ) ,
T_5 * V_3 )
{
T_5 * V_124 ;
ASSERT ( F_26 ( V_9 ) ) ;
V_3 -> V_125 = F_76 ;
V_124 = V_9 -> V_57 ;
if ( V_124 ) {
V_3 -> V_108 = V_124 -> V_108 ;
V_124 -> V_108 = V_3 ;
} else {
V_9 -> V_57 = V_3 ;
}
ASSERT ( V_9 -> V_62 == NULL ||
V_9 -> V_62 == V_126 ) ;
V_9 -> V_62 = V_126 ;
}
STATIC void
F_30 (
struct V_8 * V_9 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_9 -> V_57 ) != NULL ) {
V_9 -> V_57 = V_3 -> V_108 ;
ASSERT ( V_3 -> V_125 != NULL ) ;
V_3 -> V_108 = NULL ;
V_3 -> V_125 ( V_9 , V_3 ) ;
}
}
void
V_126 (
struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_57 ;
struct V_127 * V_88 = V_3 -> V_45 ;
static T_7 V_128 ;
static T_8 * V_129 ;
if ( F_77 ( ! F_78 ( V_9 ) ) )
goto V_130;
if ( F_52 ( V_88 ) ) {
F_39 ( V_9 ) ;
F_79 ( V_9 ) ;
F_80 ( V_9 , V_122 ) ;
goto V_130;
}
if ( V_9 -> V_91 != V_129 ||
F_81 ( V_131 , ( V_128 + 5 * V_132 ) ) ) {
V_128 = V_131 ;
F_82 ( V_9 , V_133 ) ;
}
V_129 = V_9 -> V_91 ;
if ( F_83 ( V_9 ) ) {
ASSERT ( V_9 -> V_62 != NULL ) ;
F_84 ( V_9 , V_122 ) ;
F_37 ( V_9 , 0 ) ;
if ( ! F_27 ( V_9 ) ) {
V_9 -> V_65 |= V_134 | V_66 | V_135 ;
F_85 ( V_9 ) ;
} else {
F_34 ( V_9 ) ;
}
return;
}
F_39 ( V_9 ) ;
F_79 ( V_9 ) ;
F_86 ( V_9 , V_122 ) ;
V_130:
F_30 ( V_9 ) ;
V_9 -> V_57 = NULL ;
V_9 -> V_62 = NULL ;
F_40 ( V_9 , 0 ) ;
}
void
F_87 (
struct V_8 * V_9 ,
struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
ASSERT ( F_1 ( V_3 ) -> V_10 == V_9 ) ;
F_74 ( V_9 ) ;
F_31 ( & V_53 -> V_63 ) ;
F_32 ( V_53 , V_3 , V_136 ) ;
F_71 ( F_1 ( V_3 ) ) ;
}
