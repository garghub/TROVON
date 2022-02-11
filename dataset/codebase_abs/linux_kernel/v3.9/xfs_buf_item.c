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
V_11 = 0 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_11 += F_3 ( V_5 , & V_5 -> V_26 [ V_17 ] ) ;
}
F_9 ( V_5 ) ;
return V_11 ;
}
static struct V_27 *
F_10 (
struct V_1 * V_5 ,
struct V_27 * V_28 ,
T_1 V_29 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_30 ;
T_1 V_11 ;
int V_31 ;
int V_13 ;
int V_12 ;
T_1 V_32 ;
T_1 V_33 ;
V_7 -> V_22 = V_5 -> V_21 . V_22 ;
V_30 = F_11 ( struct V_6 , V_14 ) +
( V_7 -> V_15 * sizeof( V_7 -> V_14 [ 0 ] ) ) ;
V_11 = 0 ;
V_31 = F_4 ( V_7 -> V_14 , V_7 -> V_15 , 0 ) ;
if ( ! ( V_5 -> V_19 & V_20 ) && V_31 == - 1 ) {
goto V_34;
}
V_28 -> V_35 = V_7 ;
V_28 -> V_36 = V_30 ;
V_28 -> V_37 = V_38 ;
V_28 ++ ;
V_11 = 1 ;
if ( V_5 -> V_19 & V_20 ) {
F_12 ( V_5 ) ;
ASSERT ( V_7 -> V_22 & V_23 ) ;
goto V_34;
}
V_13 = V_31 ;
V_32 = 1 ;
for (; ; ) {
V_12 = F_4 ( V_7 -> V_14 , V_7 -> V_15 ,
( T_1 ) V_13 + 1 ) ;
if ( V_12 == - 1 ) {
V_33 = V_29 + V_31 * V_16 ;
V_28 -> V_35 = F_5 ( V_9 , V_33 ) ;
V_28 -> V_36 = V_32 * V_16 ;
V_28 -> V_37 = V_39 ;
V_11 ++ ;
break;
} else if ( V_12 != V_13 + 1 ) {
V_33 = V_29 + V_31 * V_16 ;
V_28 -> V_35 = F_5 ( V_9 , V_33 ) ;
V_28 -> V_36 = V_32 * V_16 ;
V_28 -> V_37 = V_39 ;
V_11 ++ ;
V_28 ++ ;
V_31 = V_12 ;
V_13 = V_12 ;
V_32 = 1 ;
} else if ( F_5 ( V_9 , V_29 +
( V_12 << V_40 ) ) !=
( F_5 ( V_9 , V_29 +
( V_13 << V_40 ) ) +
V_16 ) ) {
V_33 = V_29 + V_31 * V_16 ;
V_28 -> V_35 = F_5 ( V_9 , V_33 ) ;
V_28 -> V_36 = V_32 * V_16 ;
V_28 -> V_37 = V_39 ;
V_28 ++ ;
V_31 = V_12 ;
V_13 = V_12 ;
V_32 = 1 ;
} else {
V_13 ++ ;
V_32 ++ ;
}
}
V_34:
V_7 -> V_41 = V_11 ;
return V_28 ;
}
STATIC void
F_13 (
struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_29 = 0 ;
int V_17 ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
ASSERT ( ( V_5 -> V_19 & V_25 ) ||
( V_5 -> V_19 & V_20 ) ) ;
if ( V_5 -> V_19 & V_42 ) {
if ( ! ( ( V_5 -> V_19 & V_43 ) &&
F_14 ( V_3 ) ) )
V_5 -> V_21 . V_22 |= V_44 ;
V_5 -> V_19 &= ~ V_42 ;
}
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_28 = F_10 ( V_5 , V_28 , V_29 ,
& V_5 -> V_26 [ V_17 ] ) ;
V_29 += V_9 -> V_45 [ V_17 ] . V_46 ;
}
F_15 ( V_5 ) ;
}
STATIC void
F_16 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
ASSERT ( ( V_5 -> V_19 & V_25 ) ||
( V_5 -> V_19 & V_20 ) ) ;
F_17 ( V_5 ) ;
F_18 ( & V_5 -> V_18 ) ;
F_18 ( & V_5 -> V_10 -> V_47 ) ;
}
STATIC void
F_19 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 * V_9 = V_5 -> V_10 ;
struct V_48 * V_49 = V_3 -> V_50 ;
int V_51 = V_5 -> V_19 & V_20 ;
int V_52 ;
ASSERT ( V_9 -> V_53 == V_5 ) ;
ASSERT ( F_7 ( & V_5 -> V_18 ) > 0 ) ;
F_20 ( V_5 ) ;
V_52 = F_21 ( & V_5 -> V_18 ) ;
if ( F_21 ( & V_9 -> V_47 ) )
F_22 ( & V_9 -> V_54 ) ;
if ( V_52 && V_51 ) {
ASSERT ( V_5 -> V_19 & V_20 ) ;
ASSERT ( F_23 ( V_9 ) ) ;
ASSERT ( F_24 ( V_9 ) ) ;
ASSERT ( V_5 -> V_21 . V_22 & V_23 ) ;
F_25 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_55 )
F_26 ( V_3 ) ;
V_9 -> V_56 = NULL ;
}
if ( V_5 -> V_19 & V_57 ) {
F_27 ( V_9 ) ;
V_9 -> V_53 = NULL ;
V_9 -> V_58 = NULL ;
} else {
F_28 ( & V_49 -> V_59 ) ;
F_29 ( V_49 , V_3 , V_60 ) ;
F_30 ( V_9 ) ;
ASSERT ( V_9 -> V_53 == NULL ) ;
}
F_31 ( V_9 ) ;
} else if ( V_52 && remove ) {
F_32 ( V_9 ) ;
F_33 ( V_9 ) ;
V_9 -> V_61 |= V_62 ;
F_34 ( V_9 , V_63 ) ;
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
F_37 ( V_9 , 0 ) ;
}
}
STATIC T_1
F_38 (
struct V_2 * V_3 ,
struct V_64 * V_65 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_66 = V_67 ;
if ( F_39 ( V_9 ) )
return V_68 ;
if ( ! F_40 ( V_9 ) ) {
if ( F_39 ( V_9 ) )
return V_68 ;
return V_69 ;
}
ASSERT ( ! ( V_5 -> V_19 & V_20 ) ) ;
F_41 ( V_5 ) ;
if ( ! F_42 ( V_9 , V_65 ) )
V_66 = V_70 ;
F_43 ( V_9 ) ;
return V_66 ;
}
STATIC void
F_44 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
int V_71 , V_72 , V_17 ;
T_1 V_73 ;
V_9 -> V_56 = NULL ;
V_71 = ( V_3 -> V_74 & V_75 ) != 0 ;
V_73 = V_5 -> V_19 & V_76 ;
V_5 -> V_19 &= ~ ( V_25 | V_76 ) ;
if ( V_5 -> V_19 & V_20 ) {
F_45 ( V_5 ) ;
ASSERT ( V_5 -> V_21 . V_22 & V_23 ) ;
if ( ! V_71 ) {
F_46 ( & V_5 -> V_18 ) ;
return;
}
}
F_47 ( V_5 ) ;
V_72 = 1 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
if ( ! F_48 ( V_5 -> V_26 [ V_17 ] . V_14 ,
V_5 -> V_26 [ V_17 ] . V_15 ) ) {
V_72 = 0 ;
break;
}
}
if ( V_72 )
F_30 ( V_9 ) ;
else if ( V_71 ) {
if ( F_21 ( & V_5 -> V_18 ) ) {
ASSERT ( F_49 ( V_3 -> V_77 ) ) ;
F_30 ( V_9 ) ;
}
} else
F_46 ( & V_5 -> V_18 ) ;
if ( ! V_73 )
F_31 ( V_9 ) ;
}
STATIC T_3
F_50 (
struct V_2 * V_3 ,
T_3 V_78 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_51 ( V_5 ) ;
if ( ( V_5 -> V_19 & V_43 ) && V_3 -> V_79 != 0 )
return V_3 -> V_79 ;
return V_78 ;
}
STATIC void
F_52 (
struct V_2 * V_3 ,
T_3 V_80 )
{
}
STATIC int
F_53 (
struct V_1 * V_5 ,
int V_81 )
{
ASSERT ( V_5 -> V_26 == NULL ) ;
V_5 -> V_24 = V_81 ;
if ( V_81 == 1 ) {
V_5 -> V_26 = & V_5 -> V_21 ;
return 0 ;
}
V_5 -> V_26 = F_54 ( V_81 * sizeof( struct V_6 ) ,
V_82 ) ;
if ( ! V_5 -> V_26 )
return V_83 ;
return 0 ;
}
STATIC void
F_55 (
struct V_1 * V_5 )
{
if ( V_5 -> V_26 != & V_5 -> V_21 ) {
F_56 ( V_5 -> V_26 ) ;
V_5 -> V_26 = NULL ;
}
}
void
F_57 (
T_2 * V_9 ,
T_4 * V_84 )
{
T_5 * V_3 = V_9 -> V_53 ;
T_6 * V_5 ;
int V_85 ;
int V_86 ;
int error ;
int V_17 ;
ASSERT ( V_9 -> V_87 -> V_88 == V_84 ) ;
if ( V_3 != NULL && V_3 -> V_89 == V_90 )
return;
V_5 = F_58 ( V_91 , V_82 ) ;
F_59 ( V_84 , & V_5 -> V_4 , V_90 , & V_92 ) ;
V_5 -> V_10 = V_9 ;
F_33 ( V_9 ) ;
error = F_53 ( V_5 , V_9 -> V_93 ) ;
ASSERT ( error == 0 ) ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
V_85 = F_60 ( F_61 ( V_9 -> V_45 [ V_17 ] . V_46 ) ,
V_16 ) ;
V_86 = F_60 ( V_85 , V_94 ) ;
V_5 -> V_26 [ V_17 ] . V_95 = V_90 ;
V_5 -> V_26 [ V_17 ] . V_96 = V_9 -> V_45 [ V_17 ] . V_97 ;
V_5 -> V_26 [ V_17 ] . V_98 = V_9 -> V_45 [ V_17 ] . V_46 ;
V_5 -> V_26 [ V_17 ] . V_15 = V_86 ;
}
#ifdef F_62
V_5 -> V_99 = F_63 ( F_61 ( V_9 -> V_100 ) , V_82 ) ;
memcpy ( V_5 -> V_99 , V_9 -> V_101 , F_61 ( V_9 -> V_100 ) ) ;
V_5 -> V_102 = F_54 ( F_61 ( V_9 -> V_100 ) / V_103 , V_82 ) ;
#endif
if ( V_9 -> V_53 )
V_5 -> V_4 . V_104 = V_9 -> V_53 ;
V_9 -> V_53 = V_5 ;
}
void
F_64 (
struct V_1 * V_5 ,
T_1 V_105 ,
T_1 V_106 ,
T_1 * V_107 )
{
T_1 V_31 ;
T_1 V_13 ;
T_1 V_108 ;
T_1 V_109 ;
T_1 V_110 ;
T_1 * V_111 ;
T_1 V_112 ;
T_1 V_113 ;
T_1 V_114 ;
V_31 = V_105 >> V_40 ;
V_13 = V_106 >> V_40 ;
V_108 = V_13 - V_31 + 1 ;
V_110 = V_31 >> V_115 ;
V_111 = & V_107 [ V_110 ] ;
V_112 = V_31 & ( T_1 ) ( V_94 - 1 ) ;
if ( V_112 ) {
V_113 = F_65 ( V_112 + V_108 , ( T_1 ) V_94 ) ;
V_114 = ( ( 1 << ( V_113 - V_112 ) ) - 1 ) << V_112 ;
* V_111 |= V_114 ;
V_111 ++ ;
V_109 = V_113 - V_112 ;
} else {
V_109 = 0 ;
}
while ( ( V_108 - V_109 ) >= V_94 ) {
* V_111 |= 0xffffffff ;
V_109 += V_94 ;
V_111 ++ ;
}
V_113 = V_108 - V_109 ;
if ( V_113 ) {
V_114 = ( 1 << V_113 ) - 1 ;
* V_111 |= V_114 ;
}
}
void
F_66 (
T_6 * V_5 ,
T_1 V_105 ,
T_1 V_106 )
{
int V_17 ;
T_1 V_116 ;
T_1 V_117 ;
struct V_8 * V_9 = V_5 -> V_10 ;
V_5 -> V_19 |= V_118 ;
V_116 = 0 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_24 ; V_17 ++ ) {
if ( V_116 > V_106 )
break;
V_117 = V_116 + F_61 ( V_9 -> V_45 [ V_17 ] . V_46 ) ;
if ( V_105 > V_117 ) {
V_116 += F_61 ( V_9 -> V_45 [ V_17 ] . V_46 ) ;
continue;
}
if ( V_105 < V_116 )
V_105 = V_116 ;
if ( V_117 > V_106 )
V_117 = V_106 ;
F_64 ( V_5 , V_105 , V_117 ,
& V_5 -> V_26 [ V_17 ] . V_14 [ 0 ] ) ;
V_116 += V_9 -> V_45 [ V_17 ] . V_46 ;
}
}
T_1
F_67 (
T_6 * V_5 )
{
return ( V_5 -> V_19 & V_118 ) ;
}
STATIC void
F_68 (
T_6 * V_5 )
{
#ifdef F_62
F_56 ( V_5 -> V_99 ) ;
F_56 ( V_5 -> V_102 ) ;
#endif
F_55 ( V_5 ) ;
F_69 ( V_91 , V_5 ) ;
}
void
F_30 (
T_2 * V_9 )
{
T_6 * V_5 ;
F_70 ( V_9 , V_119 ) ;
V_5 = V_9 -> V_53 ;
V_9 -> V_53 = V_5 -> V_4 . V_104 ;
if ( V_9 -> V_53 == NULL )
V_9 -> V_58 = NULL ;
F_71 ( V_9 ) ;
F_68 ( V_5 ) ;
}
void
F_72 (
T_2 * V_9 ,
void (* F_73)( T_2 * , T_5 * ) ,
T_5 * V_3 )
{
T_5 * V_120 ;
ASSERT ( F_23 ( V_9 ) ) ;
V_3 -> V_121 = F_73 ;
V_120 = V_9 -> V_53 ;
if ( V_120 ) {
V_3 -> V_104 = V_120 -> V_104 ;
V_120 -> V_104 = V_3 ;
} else {
V_9 -> V_53 = V_3 ;
}
ASSERT ( V_9 -> V_58 == NULL ||
V_9 -> V_58 == V_122 ) ;
V_9 -> V_58 = V_122 ;
}
STATIC void
F_27 (
struct V_8 * V_9 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_9 -> V_53 ) != NULL ) {
V_9 -> V_53 = V_3 -> V_104 ;
ASSERT ( V_3 -> V_121 != NULL ) ;
V_3 -> V_104 = NULL ;
V_3 -> V_121 ( V_9 , V_3 ) ;
}
}
void
V_122 (
struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_53 ;
struct V_123 * V_84 = V_3 -> V_77 ;
static T_7 V_124 ;
static T_8 * V_125 ;
if ( F_74 ( ! F_75 ( V_9 ) ) )
goto V_126;
if ( F_49 ( V_84 ) ) {
F_36 ( V_9 ) ;
F_76 ( V_9 ) ;
F_77 ( V_9 , V_119 ) ;
goto V_126;
}
if ( V_9 -> V_87 != V_125 ||
F_78 ( V_127 , ( V_124 + 5 * V_128 ) ) ) {
V_124 = V_127 ;
F_79 ( V_9 , V_129 ) ;
}
V_125 = V_9 -> V_87 ;
if ( F_80 ( V_9 ) ) {
ASSERT ( V_9 -> V_58 != NULL ) ;
F_81 ( V_9 , V_119 ) ;
F_34 ( V_9 , 0 ) ;
if ( ! F_24 ( V_9 ) ) {
V_9 -> V_61 |= V_130 | V_62 | V_131 ;
F_82 ( V_9 ) ;
} else {
F_31 ( V_9 ) ;
}
return;
}
F_36 ( V_9 ) ;
F_76 ( V_9 ) ;
F_83 ( V_9 , V_119 ) ;
V_126:
F_27 ( V_9 ) ;
V_9 -> V_53 = NULL ;
V_9 -> V_58 = NULL ;
F_37 ( V_9 , 0 ) ;
}
void
F_84 (
struct V_8 * V_9 ,
struct V_2 * V_3 )
{
struct V_48 * V_49 = V_3 -> V_50 ;
ASSERT ( F_1 ( V_3 ) -> V_10 == V_9 ) ;
F_71 ( V_9 ) ;
F_28 ( & V_49 -> V_59 ) ;
F_29 ( V_49 , V_3 , V_132 ) ;
F_68 ( F_1 ( V_3 ) ) ;
}
