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
V_37 = 0 ;
V_55 = F_11 ( V_35 -> V_21 , V_35 -> V_40 , 0 ) ;
if ( ! ( V_5 -> V_44 & V_45 ) && V_55 == - 1 ) {
goto V_58;
}
V_52 -> V_59 = V_35 ;
V_52 -> V_60 = V_54 ;
V_52 -> V_61 = V_62 ;
V_52 ++ ;
V_37 = 1 ;
if ( V_5 -> V_44 & V_45 ) {
F_19 ( V_5 ) ;
ASSERT ( V_35 -> V_46 & V_47 ) ;
goto V_58;
}
V_39 = V_55 ;
V_56 = 1 ;
for (; ; ) {
V_38 = F_11 ( V_35 -> V_21 , V_35 -> V_40 ,
( T_2 ) V_39 + 1 ) ;
if ( V_38 == - 1 ) {
V_57 = V_53 + V_55 * V_41 ;
V_52 -> V_59 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_60 = V_56 * V_41 ;
V_52 -> V_61 = V_63 ;
V_37 ++ ;
break;
} else if ( V_38 != V_39 + 1 ) {
V_57 = V_53 + V_55 * V_41 ;
V_52 -> V_59 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_60 = V_56 * V_41 ;
V_52 -> V_61 = V_63 ;
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
V_52 -> V_59 = F_12 ( V_22 , V_57 ) ;
V_52 -> V_60 = V_56 * V_41 ;
V_52 -> V_61 = V_63 ;
V_52 ++ ;
V_55 = V_38 ;
V_39 = V_38 ;
V_56 = 1 ;
} else {
V_39 ++ ;
V_56 ++ ;
}
}
V_58:
V_35 -> V_64 = V_37 ;
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
if ( V_5 -> V_44 & V_65 ) {
if ( ! ( ( V_5 -> V_44 & V_66 ) &&
F_21 ( V_3 ) ) )
V_5 -> V_20 . V_46 |= V_67 ;
V_5 -> V_44 &= ~ V_65 ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
V_52 = F_17 ( V_5 , V_52 , V_53 ,
& V_5 -> V_50 [ V_42 ] ) ;
V_53 += V_22 -> V_68 [ V_42 ] . V_69 ;
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
F_25 ( & V_5 -> V_29 -> V_70 ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 * V_22 = V_5 -> V_29 ;
struct V_71 * V_72 = V_3 -> V_73 ;
int V_74 = V_5 -> V_44 & V_45 ;
int V_75 ;
ASSERT ( V_22 -> V_23 == V_5 ) ;
ASSERT ( F_14 ( & V_5 -> V_43 ) > 0 ) ;
F_27 ( V_5 ) ;
V_75 = F_28 ( & V_5 -> V_43 ) ;
if ( F_28 ( & V_22 -> V_70 ) )
F_29 ( & V_22 -> V_76 ) ;
if ( V_75 && V_74 ) {
ASSERT ( V_5 -> V_44 & V_45 ) ;
ASSERT ( F_30 ( V_22 ) ) ;
ASSERT ( F_31 ( V_22 ) ) ;
ASSERT ( V_5 -> V_20 . V_46 & V_47 ) ;
F_32 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_77 )
F_33 ( V_3 ) ;
V_22 -> V_78 = NULL ;
}
if ( V_5 -> V_44 & V_79 ) {
F_34 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_80 = NULL ;
} else {
F_35 ( & V_72 -> V_81 ) ;
F_36 ( V_72 , V_3 , V_82 ) ;
F_37 ( V_22 ) ;
ASSERT ( V_22 -> V_23 == NULL ) ;
}
F_38 ( V_22 ) ;
} else if ( V_75 && remove ) {
F_39 ( V_22 ) ;
F_40 ( V_22 ) ;
V_22 -> V_83 |= V_84 ;
F_41 ( V_22 , V_85 ) ;
F_42 ( V_22 ) ;
F_43 ( V_22 ) ;
F_44 ( V_22 , 0 ) ;
}
}
STATIC T_2
F_45 (
struct V_2 * V_3 ,
struct V_86 * V_87 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_22 = V_5 -> V_29 ;
T_2 V_88 = V_89 ;
if ( F_46 ( V_22 ) )
return V_90 ;
if ( ! F_47 ( V_22 ) )
return V_91 ;
ASSERT ( ! ( V_5 -> V_44 & V_45 ) ) ;
F_48 ( V_5 ) ;
if ( ! F_49 ( V_22 , V_87 ) )
V_88 = V_92 ;
F_50 ( V_22 ) ;
return V_88 ;
}
STATIC void
F_51 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_36 * V_22 = V_5 -> V_29 ;
int V_93 , V_94 , V_42 ;
T_2 V_95 ;
V_22 -> V_78 = NULL ;
V_93 = ( V_3 -> V_96 & V_97 ) != 0 ;
V_95 = V_5 -> V_44 & V_98 ;
V_5 -> V_44 &= ~ ( V_49 | V_98 ) ;
if ( V_5 -> V_44 & V_45 ) {
F_52 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_46 & V_47 ) ;
if ( ! V_93 ) {
F_53 ( & V_5 -> V_43 ) ;
return;
}
}
F_54 ( V_5 ) ;
V_94 = 1 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
if ( ! F_55 ( V_5 -> V_50 [ V_42 ] . V_21 ,
V_5 -> V_50 [ V_42 ] . V_40 ) ) {
V_94 = 0 ;
break;
}
}
if ( V_94 )
F_37 ( V_22 ) ;
else if ( V_93 ) {
if ( F_28 ( & V_5 -> V_43 ) ) {
ASSERT ( F_56 ( V_3 -> V_99 ) ) ;
F_37 ( V_22 ) ;
}
} else
F_53 ( & V_5 -> V_43 ) ;
if ( ! V_95 )
F_38 ( V_22 ) ;
}
STATIC T_4
F_57 (
struct V_2 * V_3 ,
T_4 V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_58 ( V_5 ) ;
if ( ( V_5 -> V_44 & V_66 ) && V_3 -> V_101 != 0 )
return V_3 -> V_101 ;
return V_100 ;
}
STATIC void
F_59 (
struct V_2 * V_3 ,
T_4 V_102 )
{
}
STATIC int
F_60 (
struct V_1 * V_5 ,
int V_103 )
{
ASSERT ( V_5 -> V_50 == NULL ) ;
V_5 -> V_48 = V_103 ;
if ( V_103 == 1 ) {
V_5 -> V_50 = & V_5 -> V_20 ;
return 0 ;
}
V_5 -> V_50 = F_61 ( V_103 * sizeof( struct V_34 ) ,
V_104 ) ;
if ( ! V_5 -> V_50 )
return V_105 ;
return 0 ;
}
STATIC void
F_62 (
struct V_1 * V_5 )
{
if ( V_5 -> V_50 != & V_5 -> V_20 ) {
F_63 ( V_5 -> V_50 ) ;
V_5 -> V_50 = NULL ;
}
}
void
F_64 (
T_3 * V_22 ,
T_5 * V_106 )
{
T_6 * V_3 = V_22 -> V_23 ;
T_1 * V_5 ;
int V_107 ;
int V_108 ;
int error ;
int V_42 ;
ASSERT ( V_22 -> V_109 -> V_110 == V_106 ) ;
if ( V_3 != NULL && V_3 -> V_24 == V_25 )
return;
V_5 = F_65 ( V_111 , V_104 ) ;
F_66 ( V_106 , & V_5 -> V_4 , V_25 , & V_112 ) ;
V_5 -> V_29 = V_22 ;
F_40 ( V_22 ) ;
error = F_60 ( V_5 , V_22 -> V_113 ) ;
ASSERT ( error == 0 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
V_107 = F_67 ( F_7 ( V_22 -> V_68 [ V_42 ] . V_69 ) ,
V_41 ) ;
V_108 = F_67 ( V_107 , V_19 ) ;
V_5 -> V_50 [ V_42 ] . V_114 = V_25 ;
V_5 -> V_50 [ V_42 ] . V_115 = V_22 -> V_68 [ V_42 ] . V_116 ;
V_5 -> V_50 [ V_42 ] . V_117 = V_22 -> V_68 [ V_42 ] . V_69 ;
V_5 -> V_50 [ V_42 ] . V_40 = V_108 ;
}
#ifdef F_68
V_5 -> V_28 = F_69 ( F_7 ( V_22 -> V_30 ) , V_104 ) ;
memcpy ( V_5 -> V_28 , V_22 -> V_31 , F_7 ( V_22 -> V_30 ) ) ;
V_5 -> V_16 = F_61 ( F_7 ( V_22 -> V_30 ) / V_118 , V_104 ) ;
#endif
if ( V_22 -> V_23 )
V_5 -> V_4 . V_119 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 ;
}
void
F_70 (
struct V_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 ,
T_2 * V_120 )
{
T_2 V_55 ;
T_2 V_39 ;
T_2 V_121 ;
T_2 V_122 ;
T_2 V_12 ;
T_2 * V_15 ;
T_2 V_123 ;
T_2 V_124 ;
T_2 V_125 ;
V_55 = V_6 >> V_17 ;
V_39 = V_7 >> V_17 ;
V_121 = V_39 - V_55 + 1 ;
V_12 = V_55 >> V_18 ;
V_15 = & V_120 [ V_12 ] ;
V_123 = V_55 & ( T_2 ) ( V_19 - 1 ) ;
if ( V_123 ) {
V_124 = F_71 ( V_123 + V_121 , ( T_2 ) V_19 ) ;
V_125 = ( ( 1 << ( V_124 - V_123 ) ) - 1 ) << V_123 ;
* V_15 |= V_125 ;
V_15 ++ ;
V_122 = V_124 - V_123 ;
} else {
V_122 = 0 ;
}
while ( ( V_121 - V_122 ) >= V_19 ) {
* V_15 |= 0xffffffff ;
V_122 += V_19 ;
V_15 ++ ;
}
V_124 = V_121 - V_122 ;
if ( V_124 ) {
V_125 = ( 1 << V_124 ) - 1 ;
* V_15 |= V_125 ;
}
F_3 ( V_5 , V_6 , V_7 ) ;
}
void
F_72 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
int V_42 ;
T_2 V_126 ;
T_2 V_127 ;
struct V_36 * V_22 = V_5 -> V_29 ;
V_5 -> V_44 |= V_128 ;
V_126 = 0 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_48 ; V_42 ++ ) {
if ( V_126 > V_7 )
break;
V_127 = V_126 + F_7 ( V_22 -> V_68 [ V_42 ] . V_69 ) ;
if ( V_6 > V_127 ) {
V_126 += F_7 ( V_22 -> V_68 [ V_42 ] . V_69 ) ;
continue;
}
if ( V_6 < V_126 )
V_6 = V_126 ;
if ( V_127 > V_7 )
V_127 = V_7 ;
F_70 ( V_5 , V_6 , V_127 ,
& V_5 -> V_50 [ V_42 ] . V_21 [ 0 ] ) ;
V_126 += V_22 -> V_68 [ V_42 ] . V_69 ;
}
}
T_2
F_73 (
T_1 * V_5 )
{
return ( V_5 -> V_44 & V_128 ) ;
}
STATIC void
F_74 (
T_1 * V_5 )
{
#ifdef F_68
F_63 ( V_5 -> V_28 ) ;
F_63 ( V_5 -> V_16 ) ;
#endif
F_62 ( V_5 ) ;
F_75 ( V_111 , V_5 ) ;
}
void
F_37 (
T_3 * V_22 )
{
T_1 * V_5 ;
F_76 ( V_22 , V_129 ) ;
V_5 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 -> V_4 . V_119 ;
if ( V_22 -> V_23 == NULL )
V_22 -> V_80 = NULL ;
F_77 ( V_22 ) ;
F_74 ( V_5 ) ;
}
void
F_78 (
T_3 * V_22 ,
void (* F_79)( T_3 * , T_6 * ) ,
T_6 * V_3 )
{
T_6 * V_130 ;
ASSERT ( F_30 ( V_22 ) ) ;
V_3 -> V_131 = F_79 ;
V_130 = V_22 -> V_23 ;
if ( V_130 ) {
V_3 -> V_119 = V_130 -> V_119 ;
V_130 -> V_119 = V_3 ;
} else {
V_22 -> V_23 = V_3 ;
}
ASSERT ( V_22 -> V_80 == NULL ||
V_22 -> V_80 == V_132 ) ;
V_22 -> V_80 = V_132 ;
}
STATIC void
F_34 (
struct V_36 * V_22 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_22 -> V_23 ) != NULL ) {
V_22 -> V_23 = V_3 -> V_119 ;
ASSERT ( V_3 -> V_131 != NULL ) ;
V_3 -> V_119 = NULL ;
V_3 -> V_131 ( V_22 , V_3 ) ;
}
}
void
V_132 (
struct V_36 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_23 ;
struct V_133 * V_106 = V_3 -> V_99 ;
static T_7 V_134 ;
static T_8 * V_135 ;
if ( F_80 ( ! F_81 ( V_22 ) ) )
goto V_136;
if ( F_56 ( V_106 ) ) {
F_43 ( V_22 ) ;
F_82 ( V_22 ) ;
F_83 ( V_22 , V_129 ) ;
goto V_136;
}
if ( V_22 -> V_109 != V_135 ||
F_84 ( V_137 , ( V_134 + 5 * V_138 ) ) ) {
V_134 = V_137 ;
F_85 ( V_22 , V_33 ) ;
}
V_135 = V_22 -> V_109 ;
if ( F_86 ( V_22 ) ) {
ASSERT ( V_22 -> V_80 != NULL ) ;
F_87 ( V_22 , V_129 ) ;
F_41 ( V_22 , 0 ) ;
if ( ! F_31 ( V_22 ) ) {
V_22 -> V_83 |= V_139 | V_84 | V_140 ;
F_88 ( V_22 ) ;
} else {
F_38 ( V_22 ) ;
}
return;
}
F_43 ( V_22 ) ;
F_82 ( V_22 ) ;
F_89 ( V_22 , V_129 ) ;
V_136:
F_34 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_80 = NULL ;
F_44 ( V_22 , 0 ) ;
}
void
F_90 (
struct V_36 * V_22 ,
struct V_2 * V_3 )
{
struct V_71 * V_72 = V_3 -> V_73 ;
ASSERT ( F_1 ( V_3 ) -> V_29 == V_22 ) ;
F_77 ( V_22 ) ;
F_35 ( & V_72 -> V_81 ) ;
F_36 ( V_72 , V_3 , V_141 ) ;
F_74 ( F_1 ( V_3 ) ) ;
}
