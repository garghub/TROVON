static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC void
F_3 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
T_2 V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 * V_15 ;
ASSERT ( V_5 -> V_16 != NULL ) ;
V_9 = V_6 ;
V_10 = V_7 - V_6 + 1 ;
F_4 ( V_5 -> V_16 , V_6 , V_10 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_11 = V_9 >> V_17 ;
V_12 = V_11 >> V_18 ;
V_13 = V_11 & ( V_19 - 1 ) ;
V_15 = & ( V_5 -> V_20 . V_21 [ V_12 ] ) ;
V_14 = * V_15 & ( 1 << V_13 ) ;
ASSERT ( V_14 ) ;
V_9 ++ ;
}
}
void
F_5 (
T_3 * V_22 ,
T_2 V_6 ,
T_2 V_7 )
{
T_1 * V_5 = V_22 -> V_23 ;
T_2 V_10 ;
if ( V_5 == NULL || ( V_5 -> V_4 . V_24 != V_25 ) )
return;
ASSERT ( V_5 -> V_16 != NULL ) ;
V_10 = V_7 - V_6 + 1 ;
F_4 ( V_5 -> V_16 , V_6 , V_10 ) ;
}
STATIC void
F_6 (
T_1 * V_5 )
{
char * V_26 ;
char * V_27 ;
int V_8 ;
T_3 * V_22 ;
ASSERT ( V_5 -> V_28 != NULL ) ;
ASSERT ( V_5 -> V_16 != NULL ) ;
V_22 = V_5 -> V_29 ;
ASSERT ( V_22 -> V_30 > 0 ) ;
ASSERT ( V_22 -> V_31 != NULL ) ;
V_26 = V_5 -> V_28 ;
V_27 = V_22 -> V_31 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_22 -> V_30 ) ; V_8 ++ ) {
if ( V_26 [ V_8 ] != V_27 [ V_8 ] && ! F_8 ( V_5 -> V_16 , V_8 ) ) {
F_9 ( V_22 -> V_32 ,
L_1 ,
V_33 , V_5 , V_22 , V_26 , V_8 ) ;
ASSERT ( 0 ) ;
}
}
}
STATIC T_2
F_10 (
struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_36 * V_22 = V_5 -> V_29 ;
T_2 V_37 ;
int V_38 ;
int V_39 ;
V_39 = F_11 ( V_35 -> V_21 , V_35 -> V_40 , 0 ) ;
if ( V_39 == - 1 )
return 0 ;
V_37 = 2 ;
while ( V_39 != - 1 ) {
V_38 = F_11 ( V_35 -> V_21 , V_35 -> V_40 ,
V_39 + 1 ) ;
if ( V_38 == - 1 ) {
break;
} else if ( V_38 != V_39 + 1 ) {
V_39 = V_38 ;
V_37 ++ ;
} else if ( F_12 ( V_22 , V_38 * V_41 ) !=
( F_12 ( V_22 , V_39 * V_41 ) +
V_41 ) ) {
V_39 = V_38 ;
V_37 ++ ;
} else {
V_39 ++ ;
}
}
return V_37 ;
}
STATIC T_2
F_13 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_37 ;
int V_42 ;
ASSERT ( F_14 ( & V_5 -> V_43 ) > 0 ) ;
if ( V_5 -> V_44 & V_45 ) {
F_15 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_46 & V_47 ) ;
return V_5 -> V_48 ;
}
ASSERT ( V_5 -> V_44 & V_49 ) ;
V_37 = 0 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
V_37 += F_10 ( V_5 , & V_5 -> V_50 [ V_42 ] ) ;
}
F_16 ( V_5 ) ;
return V_37 ;
}
static struct V_51 *
F_17 (
struct V_1 * V_5 ,
struct V_51 * V_52 ,
T_2 V_53 ,
struct V_34 * V_35 )
{
struct V_36 * V_22 = V_5 -> V_29 ;
T_2 V_54 ;
T_2 V_37 ;
int V_55 ;
int V_39 ;
int V_38 ;
T_2 V_56 ;
T_2 V_57 ;
V_35 -> V_46 = V_5 -> V_20 . V_46 ;
V_54 = F_18 ( struct V_34 , V_21 ) +
( V_35 -> V_40 * sizeof( V_35 -> V_21 [ 0 ] ) ) ;
V_52 -> V_58 = V_35 ;
V_52 -> V_59 = V_54 ;
V_52 -> V_60 = V_61 ;
V_52 ++ ;
V_37 = 1 ;
if ( V_5 -> V_44 & V_45 ) {
F_19 ( V_5 ) ;
ASSERT ( V_35 -> V_46 & V_47 ) ;
V_35 -> V_62 = V_37 ;
return V_52 ;
}
V_55 = F_11 ( V_35 -> V_21 , V_35 -> V_40 , 0 ) ;
ASSERT ( V_55 != - 1 ) ;
V_39 = V_55 ;
V_56 = 1 ;
for (; ; ) {
V_38 = F_11 ( V_35 -> V_21 , V_35 -> V_40 ,
( T_2 ) V_39 + 1 ) ;
if ( V_38 == - 1 ) {
V_57 = V_53 + V_55 * V_41 ;
V_52 -> V_58 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_59 = V_56 * V_41 ;
V_52 -> V_60 = V_63 ;
V_37 ++ ;
break;
} else if ( V_38 != V_39 + 1 ) {
V_57 = V_53 + V_55 * V_41 ;
V_52 -> V_58 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_59 = V_56 * V_41 ;
V_52 -> V_60 = V_63 ;
V_37 ++ ;
V_52 ++ ;
V_55 = V_38 ;
V_39 = V_38 ;
V_56 = 1 ;
} else if ( F_12 ( V_22 , V_53 +
( V_38 << V_17 ) ) !=
( F_12 ( V_22 , V_53 +
( V_39 << V_17 ) ) +
V_41 ) ) {
V_57 = V_53 + V_55 * V_41 ;
V_52 -> V_58 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_59 = V_56 * V_41 ;
V_52 -> V_60 = V_63 ;
V_52 ++ ;
V_55 = V_38 ;
V_39 = V_38 ;
V_56 = 1 ;
} else {
V_39 ++ ;
V_56 ++ ;
}
}
V_5 -> V_20 . V_62 = V_37 ;
return V_52 ;
}
STATIC void
F_20 (
struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_22 = V_5 -> V_29 ;
T_2 V_53 = 0 ;
int V_42 ;
ASSERT ( F_14 ( & V_5 -> V_43 ) > 0 ) ;
ASSERT ( ( V_5 -> V_44 & V_49 ) ||
( V_5 -> V_44 & V_45 ) ) ;
if ( V_5 -> V_44 & V_64 ) {
if ( ! ( ( V_5 -> V_44 & V_65 ) &&
F_21 ( V_3 ) ) )
V_5 -> V_20 . V_46 |= V_66 ;
V_5 -> V_44 &= ~ V_64 ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
V_52 = F_17 ( V_5 , V_52 , V_53 ,
& V_5 -> V_50 [ V_42 ] ) ;
V_53 += V_22 -> V_67 [ V_42 ] . V_68 ;
}
F_22 ( V_5 ) ;
F_6 ( V_5 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_14 ( & V_5 -> V_43 ) > 0 ) ;
ASSERT ( ( V_5 -> V_44 & V_49 ) ||
( V_5 -> V_44 & V_45 ) ) ;
F_24 ( V_5 ) ;
F_25 ( & V_5 -> V_43 ) ;
F_25 ( & V_5 -> V_29 -> V_69 ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 * V_22 = V_5 -> V_29 ;
struct V_70 * V_71 = V_3 -> V_72 ;
int V_73 = V_5 -> V_44 & V_45 ;
int V_74 ;
ASSERT ( V_22 -> V_23 == V_5 ) ;
ASSERT ( F_14 ( & V_5 -> V_43 ) > 0 ) ;
F_27 ( V_5 ) ;
V_74 = F_28 ( & V_5 -> V_43 ) ;
if ( F_28 ( & V_22 -> V_69 ) )
F_29 ( & V_22 -> V_75 ) ;
if ( V_74 && V_73 ) {
ASSERT ( V_5 -> V_44 & V_45 ) ;
ASSERT ( F_30 ( V_22 ) ) ;
ASSERT ( F_31 ( V_22 ) ) ;
ASSERT ( V_5 -> V_20 . V_46 & V_47 ) ;
F_32 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_76 )
F_33 ( V_3 ) ;
V_22 -> V_77 = NULL ;
}
if ( V_5 -> V_44 & V_78 ) {
F_34 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_79 = NULL ;
} else {
F_35 ( & V_71 -> V_80 ) ;
F_36 ( V_71 , V_3 , V_81 ) ;
F_37 ( V_22 ) ;
ASSERT ( V_22 -> V_23 == NULL ) ;
}
F_38 ( V_22 ) ;
} else if ( V_74 && remove ) {
F_39 ( V_22 ) ;
F_40 ( V_22 , V_82 ) ;
F_41 ( V_22 ) ;
F_42 ( V_22 ) ;
F_43 ( V_22 , 0 ) ;
}
}
STATIC T_2
F_44 (
struct V_2 * V_3 ,
struct V_83 * V_84 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_22 = V_5 -> V_29 ;
T_2 V_85 = V_86 ;
if ( F_45 ( V_22 ) )
return V_87 ;
if ( ! F_46 ( V_22 ) )
return V_88 ;
ASSERT ( ! ( V_5 -> V_44 & V_45 ) ) ;
F_47 ( V_5 ) ;
if ( ! F_48 ( V_22 , V_84 ) )
V_85 = V_89 ;
F_49 ( V_22 ) ;
return V_85 ;
}
STATIC void
F_50 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_22 = V_5 -> V_29 ;
int V_90 ;
T_2 V_91 ;
V_22 -> V_77 = NULL ;
V_90 = ( V_3 -> V_92 & V_93 ) != 0 ;
V_91 = V_5 -> V_44 & V_94 ;
V_5 -> V_44 &= ~ ( V_49 | V_94 ) ;
if ( V_5 -> V_44 & V_45 ) {
F_51 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_46 & V_47 ) ;
if ( ! V_90 ) {
F_52 ( & V_5 -> V_43 ) ;
return;
}
}
F_53 ( V_5 ) ;
if ( F_54 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_40 ) )
F_37 ( V_22 ) ;
else
F_52 ( & V_5 -> V_43 ) ;
if ( ! V_91 )
F_38 ( V_22 ) ;
}
STATIC T_4
F_55 (
struct V_2 * V_3 ,
T_4 V_95 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_56 ( V_5 ) ;
if ( ( V_5 -> V_44 & V_65 ) && V_3 -> V_96 != 0 )
return V_3 -> V_96 ;
return V_95 ;
}
STATIC void
F_57 (
struct V_2 * V_3 ,
T_4 V_97 )
{
}
STATIC int
F_58 (
struct V_1 * V_5 ,
int V_98 )
{
ASSERT ( V_5 -> V_50 == NULL ) ;
V_5 -> V_48 = V_98 ;
if ( V_98 == 1 ) {
V_5 -> V_50 = & V_5 -> V_20 ;
return 0 ;
}
V_5 -> V_50 = F_59 ( V_98 * sizeof( struct V_34 ) ,
V_99 ) ;
if ( ! V_5 -> V_50 )
return V_100 ;
return 0 ;
}
STATIC void
F_60 (
struct V_1 * V_5 )
{
if ( V_5 -> V_50 != & V_5 -> V_20 ) {
F_61 ( V_5 -> V_50 ) ;
V_5 -> V_50 = NULL ;
}
}
void
F_62 (
T_3 * V_22 ,
T_5 * V_101 )
{
T_6 * V_3 = V_22 -> V_23 ;
T_1 * V_5 ;
int V_102 ;
int V_103 ;
int error ;
int V_42 ;
ASSERT ( V_22 -> V_104 -> V_105 == V_101 ) ;
if ( V_3 != NULL && V_3 -> V_24 == V_25 )
return;
V_5 = F_63 ( V_106 , V_99 ) ;
F_64 ( V_101 , & V_5 -> V_4 , V_25 , & V_107 ) ;
V_5 -> V_29 = V_22 ;
F_65 ( V_22 ) ;
error = F_58 ( V_5 , V_22 -> V_108 ) ;
ASSERT ( error == 0 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
V_102 = F_66 ( F_7 ( V_22 -> V_67 [ V_42 ] . V_68 ) ,
V_41 ) ;
V_103 = F_66 ( V_102 , V_19 ) ;
V_5 -> V_50 [ V_42 ] . V_109 = V_25 ;
V_5 -> V_50 [ V_42 ] . V_110 = V_22 -> V_67 [ V_42 ] . V_111 ;
V_5 -> V_50 [ V_42 ] . V_112 = V_22 -> V_67 [ V_42 ] . V_68 ;
V_5 -> V_50 [ V_42 ] . V_40 = V_103 ;
}
#ifdef F_67
V_5 -> V_28 = F_68 ( F_7 ( V_22 -> V_30 ) , V_99 ) ;
memcpy ( V_5 -> V_28 , V_22 -> V_31 , F_7 ( V_22 -> V_30 ) ) ;
V_5 -> V_16 = F_59 ( F_7 ( V_22 -> V_30 ) / V_113 , V_99 ) ;
#endif
if ( V_22 -> V_23 )
V_5 -> V_4 . V_114 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 ;
}
void
F_69 (
struct V_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 ,
T_2 * V_115 )
{
T_2 V_55 ;
T_2 V_39 ;
T_2 V_116 ;
T_2 V_117 ;
T_2 V_12 ;
T_2 * V_15 ;
T_2 V_118 ;
T_2 V_119 ;
T_2 V_120 ;
V_55 = V_6 >> V_17 ;
V_39 = V_7 >> V_17 ;
V_116 = V_39 - V_55 + 1 ;
V_12 = V_55 >> V_18 ;
V_15 = & V_115 [ V_12 ] ;
V_118 = V_55 & ( T_2 ) ( V_19 - 1 ) ;
if ( V_118 ) {
V_119 = F_70 ( V_118 + V_116 , ( T_2 ) V_19 ) ;
V_120 = ( ( 1 << ( V_119 - V_118 ) ) - 1 ) << V_118 ;
* V_15 |= V_120 ;
V_15 ++ ;
V_117 = V_119 - V_118 ;
} else {
V_117 = 0 ;
}
while ( ( V_116 - V_117 ) >= V_19 ) {
* V_15 |= 0xffffffff ;
V_117 += V_19 ;
V_15 ++ ;
}
V_119 = V_116 - V_117 ;
if ( V_119 ) {
V_120 = ( 1 << V_119 ) - 1 ;
* V_15 |= V_120 ;
}
F_3 ( V_5 , V_6 , V_7 ) ;
}
void
F_71 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
int V_42 ;
T_2 V_121 ;
T_2 V_122 ;
struct V_36 * V_22 = V_5 -> V_29 ;
V_5 -> V_44 |= V_123 ;
V_121 = 0 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
if ( V_121 > V_7 )
break;
V_122 = V_121 + F_7 ( V_22 -> V_67 [ V_42 ] . V_68 ) ;
if ( V_6 > V_122 ) {
V_121 += F_7 ( V_22 -> V_67 [ V_42 ] . V_68 ) ;
continue;
}
if ( V_6 < V_121 )
V_6 = V_121 ;
if ( V_122 > V_7 )
V_122 = V_7 ;
F_69 ( V_5 , V_6 , V_122 ,
& V_5 -> V_50 [ V_42 ] . V_21 [ 0 ] ) ;
V_121 += V_22 -> V_67 [ V_42 ] . V_68 ;
}
}
T_2
F_72 (
T_1 * V_5 )
{
return ( V_5 -> V_44 & V_123 ) ;
}
STATIC void
F_73 (
T_1 * V_5 )
{
#ifdef F_67
F_61 ( V_5 -> V_28 ) ;
F_61 ( V_5 -> V_16 ) ;
#endif
F_60 ( V_5 ) ;
F_74 ( V_106 , V_5 ) ;
}
void
F_37 (
T_3 * V_22 )
{
T_1 * V_5 ;
F_75 ( V_22 , V_124 ) ;
V_5 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 -> V_4 . V_114 ;
if ( V_22 -> V_23 == NULL )
V_22 -> V_79 = NULL ;
F_76 ( V_22 ) ;
F_73 ( V_5 ) ;
}
void
F_77 (
T_3 * V_22 ,
void (* F_78)( T_3 * , T_6 * ) ,
T_6 * V_3 )
{
T_6 * V_125 ;
ASSERT ( F_30 ( V_22 ) ) ;
V_3 -> V_126 = F_78 ;
V_125 = V_22 -> V_23 ;
if ( V_125 ) {
V_3 -> V_114 = V_125 -> V_114 ;
V_125 -> V_114 = V_3 ;
} else {
V_22 -> V_23 = V_3 ;
}
ASSERT ( V_22 -> V_79 == NULL ||
V_22 -> V_79 == V_127 ) ;
V_22 -> V_79 = V_127 ;
}
STATIC void
F_34 (
struct V_36 * V_22 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_22 -> V_23 ) != NULL ) {
V_22 -> V_23 = V_3 -> V_114 ;
ASSERT ( V_3 -> V_126 != NULL ) ;
V_3 -> V_114 = NULL ;
V_3 -> V_126 ( V_22 , V_3 ) ;
}
}
void
V_127 (
struct V_36 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_23 ;
struct V_128 * V_101 = V_3 -> V_129 ;
static T_7 V_130 ;
static T_8 * V_131 ;
if ( F_79 ( ! F_80 ( V_22 ) ) )
goto V_132;
if ( F_81 ( V_101 ) ) {
F_42 ( V_22 ) ;
F_82 ( V_22 ) ;
F_83 ( V_22 , V_124 ) ;
goto V_132;
}
if ( V_22 -> V_104 != V_131 ||
F_84 ( V_133 , ( V_130 + 5 * V_134 ) ) ) {
V_130 = V_133 ;
F_85 ( V_22 , V_33 ) ;
}
V_131 = V_22 -> V_104 ;
if ( F_86 ( V_22 ) ) {
ASSERT ( V_22 -> V_79 != NULL ) ;
F_87 ( V_22 , V_124 ) ;
F_40 ( V_22 , 0 ) ;
if ( ! F_31 ( V_22 ) ) {
V_22 -> V_135 |= V_136 | V_137 | V_138 ;
F_88 ( V_22 ) ;
} else {
F_38 ( V_22 ) ;
}
return;
}
F_42 ( V_22 ) ;
F_82 ( V_22 ) ;
F_89 ( V_22 , V_124 ) ;
V_132:
F_34 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_79 = NULL ;
F_43 ( V_22 , 0 ) ;
}
void
F_90 (
struct V_36 * V_22 ,
struct V_2 * V_3 )
{
struct V_70 * V_71 = V_3 -> V_72 ;
ASSERT ( F_1 ( V_3 ) -> V_29 == V_22 ) ;
F_76 ( V_22 ) ;
F_35 ( & V_71 -> V_80 ) ;
F_36 ( V_71 , V_3 , V_139 ) ;
F_73 ( F_1 ( V_3 ) ) ;
}
