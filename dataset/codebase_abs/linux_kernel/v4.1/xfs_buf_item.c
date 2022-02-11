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
ASSERT ( ( V_9 -> V_20 & V_21 ) ||
( F_19 ( & V_9 -> V_22 ) > V_42
&& F_19 ( & V_9 -> V_22 ) < V_43 ) ) ;
if ( V_9 -> V_20 & V_44 ) {
if ( F_20 ( & V_3 -> V_45 -> V_46 ) ||
! ( ( V_9 -> V_20 & V_47 ) &&
F_21 ( V_3 ) ) )
V_9 -> V_22 . V_23 |= V_48 ;
V_9 -> V_20 &= ~ V_44 ;
}
if ( ( V_9 -> V_20 & ( V_28 | V_21 ) ) ==
V_28 ) {
F_22 ( V_9 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
F_16 ( V_9 , V_31 , & V_33 , V_34 ,
& V_9 -> V_26 [ V_18 ] ) ;
V_34 += V_13 -> V_49 [ V_18 ] . V_50 ;
}
F_23 ( V_9 ) ;
}
STATIC void
F_24 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
ASSERT ( ( V_9 -> V_20 & V_27 ) ||
( V_9 -> V_20 & V_28 ) ||
( V_9 -> V_20 & V_21 ) ) ;
F_25 ( V_9 ) ;
F_26 ( & V_9 -> V_19 ) ;
F_26 ( & V_9 -> V_14 -> V_51 ) ;
}
STATIC void
F_27 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 * V_13 = V_9 -> V_14 ;
struct V_52 * V_53 = V_3 -> V_54 ;
int V_55 = V_9 -> V_20 & V_21 ;
int V_56 ;
ASSERT ( V_13 -> V_57 == V_9 ) ;
ASSERT ( F_9 ( & V_9 -> V_19 ) > 0 ) ;
F_28 ( V_9 ) ;
V_56 = F_29 ( & V_9 -> V_19 ) ;
if ( F_29 ( & V_13 -> V_51 ) )
F_30 ( & V_13 -> V_58 ) ;
if ( V_56 && V_55 ) {
ASSERT ( V_9 -> V_20 & V_21 ) ;
ASSERT ( F_31 ( V_13 ) ) ;
ASSERT ( F_32 ( V_13 ) ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
F_33 ( V_9 ) ;
if ( remove ) {
if ( V_3 -> V_59 )
F_34 ( V_3 ) ;
V_13 -> V_60 = NULL ;
}
if ( V_9 -> V_20 & V_61 ) {
F_35 ( V_13 ) ;
V_13 -> V_57 = NULL ;
V_13 -> V_62 = NULL ;
} else {
F_36 ( & V_53 -> V_63 ) ;
F_37 ( V_53 , V_3 , V_64 ) ;
F_38 ( V_13 ) ;
ASSERT ( V_13 -> V_57 == NULL ) ;
}
F_39 ( V_13 ) ;
} else if ( V_56 && remove ) {
F_40 ( V_13 ) ;
F_41 ( V_13 ) ;
V_13 -> V_65 |= V_66 ;
F_42 ( V_13 , - V_67 ) ;
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
F_45 ( V_13 ) ;
}
}
STATIC T_1
F_46 (
struct V_2 * V_3 ,
struct V_68 * V_69 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
T_1 V_70 = V_71 ;
if ( F_47 ( V_13 ) )
return V_72 ;
if ( ! F_48 ( V_13 ) ) {
if ( F_47 ( V_13 ) )
return V_72 ;
return V_73 ;
}
ASSERT ( ! ( V_9 -> V_20 & V_21 ) ) ;
F_49 ( V_9 ) ;
if ( ( V_13 -> V_65 & V_74 ) &&
F_50 ( & V_75 , L_1 ) ) {
F_51 ( V_13 -> V_76 -> V_77 ,
L_2 ,
( long long ) V_13 -> V_78 ) ;
}
if ( ! F_52 ( V_13 , V_69 ) )
V_70 = V_79 ;
F_53 ( V_13 ) ;
return V_70 ;
}
STATIC void
F_54 (
struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
bool V_80 ;
bool V_81 ;
int V_82 ;
V_13 -> V_60 = NULL ;
V_81 = ( V_3 -> V_83 & V_84 ) ? true : false ;
V_82 = V_9 -> V_20 ;
V_9 -> V_20 &= ~ ( V_27 | V_85 | V_28 ) ;
if ( V_82 & V_21 ) {
F_55 ( V_9 ) ;
ASSERT ( V_9 -> V_22 . V_23 & V_24 ) ;
if ( ! V_81 ) {
F_56 ( & V_9 -> V_19 ) ;
return;
}
}
F_57 ( V_9 ) ;
V_80 = ( V_82 & V_86 ) ? false : true ;
if ( V_80 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
if ( ! F_58 ( V_9 -> V_26 [ V_18 ] . V_7 ,
V_9 -> V_26 [ V_18 ] . V_8 ) ) {
V_80 = false ;
break;
}
}
}
if ( F_29 ( & V_9 -> V_19 ) ) {
if ( V_80 )
F_38 ( V_13 ) ;
else if ( V_81 ) {
ASSERT ( F_59 ( V_3 -> V_45 ) ) ;
if ( V_3 -> V_83 & V_87 ) {
F_36 ( & V_3 -> V_54 -> V_63 ) ;
F_37 ( V_3 -> V_54 , V_3 ,
V_64 ) ;
}
F_38 ( V_13 ) ;
}
}
if ( ! ( V_82 & V_85 ) )
F_39 ( V_13 ) ;
}
STATIC T_3
F_60 (
struct V_2 * V_3 ,
T_3 V_88 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_61 ( V_9 ) ;
if ( ( V_9 -> V_20 & V_47 ) && V_3 -> V_89 != 0 )
return V_3 -> V_89 ;
return V_88 ;
}
STATIC void
F_62 (
struct V_2 * V_3 ,
T_3 V_90 )
{
}
STATIC int
F_63 (
struct V_1 * V_9 ,
int V_91 )
{
ASSERT ( V_9 -> V_26 == NULL ) ;
V_9 -> V_25 = V_91 ;
if ( V_91 == 1 ) {
V_9 -> V_26 = & V_9 -> V_22 ;
return 0 ;
}
V_9 -> V_26 = F_64 ( V_91 * sizeof( struct V_5 ) ,
V_92 ) ;
if ( ! V_9 -> V_26 )
return - V_93 ;
return 0 ;
}
STATIC void
F_65 (
struct V_1 * V_9 )
{
if ( V_9 -> V_26 != & V_9 -> V_22 ) {
F_66 ( V_9 -> V_26 ) ;
V_9 -> V_26 = NULL ;
}
}
void
F_67 (
T_2 * V_13 ,
T_4 * V_94 )
{
T_5 * V_3 = V_13 -> V_57 ;
T_6 * V_9 ;
int V_95 ;
int V_96 ;
int error ;
int V_18 ;
ASSERT ( V_13 -> V_76 -> V_77 == V_94 ) ;
if ( V_3 != NULL && V_3 -> V_97 == V_98 )
return;
V_9 = F_68 ( V_99 , V_92 ) ;
F_69 ( V_94 , & V_9 -> V_4 , V_98 , & V_100 ) ;
V_9 -> V_14 = V_13 ;
F_41 ( V_13 ) ;
error = F_63 ( V_9 , V_13 -> V_101 ) ;
ASSERT ( error == 0 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
V_95 = F_70 ( F_71 ( V_13 -> V_49 [ V_18 ] . V_50 ) ,
V_17 ) ;
V_96 = F_70 ( V_95 , V_102 ) ;
V_9 -> V_26 [ V_18 ] . V_103 = V_98 ;
V_9 -> V_26 [ V_18 ] . V_104 = V_13 -> V_49 [ V_18 ] . V_105 ;
V_9 -> V_26 [ V_18 ] . V_106 = V_13 -> V_49 [ V_18 ] . V_50 ;
V_9 -> V_26 [ V_18 ] . V_8 = V_96 ;
}
if ( V_13 -> V_57 )
V_9 -> V_4 . V_107 = V_13 -> V_57 ;
V_13 -> V_57 = V_9 ;
}
static void
F_72 (
T_1 V_108 ,
T_1 V_109 ,
T_1 * V_110 )
{
T_1 V_35 ;
T_1 V_16 ;
T_1 V_111 ;
T_1 V_112 ;
T_1 V_113 ;
T_1 * V_114 ;
T_1 V_115 ;
T_1 V_116 ;
T_1 V_117 ;
V_35 = V_108 >> V_38 ;
V_16 = V_109 >> V_38 ;
V_111 = V_16 - V_35 + 1 ;
V_113 = V_35 >> V_118 ;
V_114 = & V_110 [ V_113 ] ;
V_115 = V_35 & ( T_1 ) ( V_102 - 1 ) ;
if ( V_115 ) {
V_116 = F_73 ( V_115 + V_111 , ( T_1 ) V_102 ) ;
V_117 = ( ( 1 << ( V_116 - V_115 ) ) - 1 ) << V_115 ;
* V_114 |= V_117 ;
V_114 ++ ;
V_112 = V_116 - V_115 ;
} else {
V_112 = 0 ;
}
while ( ( V_111 - V_112 ) >= V_102 ) {
* V_114 |= 0xffffffff ;
V_112 += V_102 ;
V_114 ++ ;
}
V_116 = V_111 - V_112 ;
if ( V_116 ) {
V_117 = ( 1 << V_116 ) - 1 ;
* V_114 |= V_117 ;
}
}
void
F_74 (
T_6 * V_9 ,
T_1 V_108 ,
T_1 V_109 )
{
int V_18 ;
T_1 V_119 ;
T_1 V_120 ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_119 = 0 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_25 ; V_18 ++ ) {
if ( V_119 > V_109 )
break;
V_120 = V_119 + F_71 ( V_13 -> V_49 [ V_18 ] . V_50 ) ;
if ( V_108 > V_120 ) {
V_119 += F_71 ( V_13 -> V_49 [ V_18 ] . V_50 ) ;
continue;
}
if ( V_108 < V_119 )
V_108 = V_119 ;
if ( V_120 > V_109 )
V_120 = V_109 ;
F_72 ( V_108 , V_120 ,
& V_9 -> V_26 [ V_18 ] . V_7 [ 0 ] ) ;
V_119 += V_13 -> V_49 [ V_18 ] . V_50 ;
}
}
T_1
F_75 (
T_6 * V_9 )
{
return ( V_9 -> V_20 & V_86 ) ;
}
STATIC void
F_76 (
T_6 * V_9 )
{
F_65 ( V_9 ) ;
F_77 ( V_99 , V_9 ) ;
}
void
F_38 (
T_2 * V_13 )
{
T_6 * V_9 = V_13 -> V_57 ;
F_78 ( V_13 , V_121 ) ;
ASSERT ( ! ( V_9 -> V_4 . V_83 & V_87 ) ) ;
V_13 -> V_57 = V_9 -> V_4 . V_107 ;
if ( V_13 -> V_57 == NULL )
V_13 -> V_62 = NULL ;
F_79 ( V_13 ) ;
F_76 ( V_9 ) ;
}
void
F_80 (
T_2 * V_13 ,
void (* F_81)( T_2 * , T_5 * ) ,
T_5 * V_3 )
{
T_5 * V_122 ;
ASSERT ( F_31 ( V_13 ) ) ;
V_3 -> V_123 = F_81 ;
V_122 = V_13 -> V_57 ;
if ( V_122 ) {
V_3 -> V_107 = V_122 -> V_107 ;
V_122 -> V_107 = V_3 ;
} else {
V_13 -> V_57 = V_3 ;
}
ASSERT ( V_13 -> V_62 == NULL ||
V_13 -> V_62 == V_124 ) ;
V_13 -> V_62 = V_124 ;
}
STATIC void
F_35 (
struct V_12 * V_13 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_13 -> V_57 ) != NULL ) {
V_13 -> V_57 = V_3 -> V_107 ;
ASSERT ( V_3 -> V_123 != NULL ) ;
V_3 -> V_107 = NULL ;
V_3 -> V_123 ( V_13 , V_3 ) ;
}
}
void
V_124 (
struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_57 ;
struct V_125 * V_94 = V_3 -> V_45 ;
static T_7 V_126 ;
static T_8 * V_127 ;
if ( F_82 ( ! V_13 -> V_128 ) )
goto V_129;
if ( F_59 ( V_94 ) ) {
F_44 ( V_13 ) ;
F_83 ( V_13 ) ;
F_84 ( V_13 , V_121 ) ;
goto V_129;
}
if ( V_13 -> V_76 != V_127 ||
F_85 ( V_130 , ( V_126 + 5 * V_131 ) ) ) {
V_126 = V_130 ;
F_86 ( V_13 , V_132 ) ;
}
V_127 = V_13 -> V_76 ;
if ( F_87 ( V_13 ) ) {
ASSERT ( V_13 -> V_62 != NULL ) ;
F_88 ( V_13 , V_121 ) ;
F_42 ( V_13 , 0 ) ;
if ( ! ( V_13 -> V_65 & ( V_133 | V_74 ) ) ) {
V_13 -> V_65 |= V_134 | V_66 |
V_135 | V_74 ;
F_89 ( V_13 ) ;
} else {
F_39 ( V_13 ) ;
}
return;
}
F_44 ( V_13 ) ;
F_83 ( V_13 ) ;
F_90 ( V_13 , V_121 ) ;
V_129:
F_35 ( V_13 ) ;
V_13 -> V_57 = NULL ;
V_13 -> V_62 = NULL ;
F_45 ( V_13 ) ;
}
void
F_91 (
struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_54 ;
ASSERT ( F_1 ( V_3 ) -> V_14 == V_13 ) ;
F_79 ( V_13 ) ;
F_36 ( & V_53 -> V_63 ) ;
F_37 ( V_53 , V_3 , V_136 ) ;
F_76 ( F_1 ( V_3 ) ) ;
}
