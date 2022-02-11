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
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_34 * V_22 = V_5 -> V_29 ;
T_2 V_35 ;
int V_36 ;
int V_37 ;
ASSERT ( F_11 ( & V_5 -> V_38 ) > 0 ) ;
if ( V_5 -> V_39 & V_40 ) {
F_12 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_41 & V_42 ) ;
return 1 ;
}
ASSERT ( V_5 -> V_39 & V_43 ) ;
V_35 = 1 ;
V_37 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_44 , 0 ) ;
ASSERT ( V_37 != - 1 ) ;
V_35 ++ ;
while ( V_37 != - 1 ) {
V_36 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_44 ,
V_37 + 1 ) ;
if ( V_36 == - 1 ) {
V_37 = - 1 ;
} else if ( V_36 != V_37 + 1 ) {
V_37 = V_36 ;
V_35 ++ ;
} else if ( F_14 ( V_22 , V_36 * V_45 ) !=
( F_14 ( V_22 , V_37 * V_45 ) +
V_45 ) ) {
V_37 = V_36 ;
V_35 ++ ;
} else {
V_37 ++ ;
}
}
F_15 ( V_5 ) ;
return V_35 ;
}
STATIC void
F_16 (
struct V_2 * V_3 ,
struct V_46 * V_47 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_34 * V_22 = V_5 -> V_29 ;
T_2 V_48 ;
T_2 V_35 ;
int V_49 ;
int V_37 ;
int V_36 ;
T_2 V_50 ;
T_2 V_51 ;
ASSERT ( F_11 ( & V_5 -> V_38 ) > 0 ) ;
ASSERT ( ( V_5 -> V_39 & V_43 ) ||
( V_5 -> V_39 & V_40 ) ) ;
V_48 =
( T_2 ) ( sizeof( V_52 ) +
( ( V_5 -> V_20 . V_44 - 1 ) * sizeof( T_2 ) ) ) ;
V_47 -> V_53 = & V_5 -> V_20 ;
V_47 -> V_54 = V_48 ;
V_47 -> V_55 = V_56 ;
V_47 ++ ;
V_35 = 1 ;
if ( V_5 -> V_39 & V_57 ) {
if ( ! ( ( V_5 -> V_39 & V_58 ) &&
F_17 ( V_3 ) ) )
V_5 -> V_20 . V_41 |= V_59 ;
V_5 -> V_39 &= ~ V_57 ;
}
if ( V_5 -> V_39 & V_40 ) {
F_18 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_41 & V_42 ) ;
V_5 -> V_20 . V_60 = V_35 ;
return;
}
V_49 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_44 , 0 ) ;
ASSERT ( V_49 != - 1 ) ;
V_37 = V_49 ;
V_50 = 1 ;
for (; ; ) {
V_36 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_44 ,
( T_2 ) V_37 + 1 ) ;
if ( V_36 == - 1 ) {
V_51 = V_49 * V_45 ;
V_47 -> V_53 = F_14 ( V_22 , V_51 ) ;
V_47 -> V_54 = V_50 * V_45 ;
V_47 -> V_55 = V_61 ;
V_35 ++ ;
break;
} else if ( V_36 != V_37 + 1 ) {
V_51 = V_49 * V_45 ;
V_47 -> V_53 = F_14 ( V_22 , V_51 ) ;
V_47 -> V_54 = V_50 * V_45 ;
V_47 -> V_55 = V_61 ;
V_35 ++ ;
V_47 ++ ;
V_49 = V_36 ;
V_37 = V_36 ;
V_50 = 1 ;
} else if ( F_14 ( V_22 , V_36 << V_17 ) !=
( F_14 ( V_22 , V_37 << V_17 ) +
V_45 ) ) {
V_51 = V_49 * V_45 ;
V_47 -> V_53 = F_14 ( V_22 , V_51 ) ;
V_47 -> V_54 = V_50 * V_45 ;
V_47 -> V_55 = V_61 ;
V_47 ++ ;
V_49 = V_36 ;
V_37 = V_36 ;
V_50 = 1 ;
} else {
V_37 ++ ;
V_50 ++ ;
}
}
V_5 -> V_20 . V_60 = V_35 ;
F_19 ( V_5 ) ;
F_6 ( V_5 ) ;
}
STATIC void
F_20 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_11 ( & V_5 -> V_38 ) > 0 ) ;
ASSERT ( ( V_5 -> V_39 & V_43 ) ||
( V_5 -> V_39 & V_40 ) ) ;
F_21 ( V_5 ) ;
F_22 ( & V_5 -> V_38 ) ;
F_22 ( & V_5 -> V_29 -> V_62 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 * V_22 = V_5 -> V_29 ;
struct V_63 * V_64 = V_3 -> V_65 ;
int V_66 = V_5 -> V_39 & V_40 ;
int V_67 ;
ASSERT ( V_22 -> V_23 == V_5 ) ;
ASSERT ( F_11 ( & V_5 -> V_38 ) > 0 ) ;
F_24 ( V_5 ) ;
V_67 = F_25 ( & V_5 -> V_38 ) ;
if ( F_25 ( & V_22 -> V_62 ) )
F_26 ( & V_22 -> V_68 ) ;
if ( V_67 && V_66 ) {
ASSERT ( V_5 -> V_39 & V_40 ) ;
ASSERT ( F_27 ( V_22 ) ) ;
ASSERT ( F_28 ( V_22 ) ) ;
ASSERT ( V_5 -> V_20 . V_41 & V_42 ) ;
F_29 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_69 )
F_30 ( V_3 ) ;
V_22 -> V_70 = NULL ;
}
if ( V_5 -> V_39 & V_71 ) {
F_31 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_72 = NULL ;
} else {
F_32 ( & V_64 -> V_73 ) ;
F_33 ( V_64 , V_3 , V_74 ) ;
F_34 ( V_22 ) ;
ASSERT ( V_22 -> V_23 == NULL ) ;
}
F_35 ( V_22 ) ;
} else if ( V_67 && remove ) {
F_36 ( V_22 ) ;
F_37 ( V_22 , V_75 ) ;
F_38 ( V_22 ) ;
F_39 ( V_22 ) ;
F_40 ( V_22 , 0 ) ;
}
}
STATIC T_2
F_41 (
struct V_2 * V_3 ,
struct V_76 * V_77 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_34 * V_22 = V_5 -> V_29 ;
T_2 V_78 = V_79 ;
if ( F_42 ( V_22 ) )
return V_80 ;
if ( ! F_43 ( V_22 ) )
return V_81 ;
ASSERT ( ! ( V_5 -> V_39 & V_40 ) ) ;
F_44 ( V_5 ) ;
if ( ! F_45 ( V_22 , V_77 ) )
V_78 = V_82 ;
F_46 ( V_22 ) ;
return V_78 ;
}
STATIC void
F_47 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_34 * V_22 = V_5 -> V_29 ;
int V_83 ;
T_2 V_84 ;
V_22 -> V_70 = NULL ;
V_83 = ( V_3 -> V_85 & V_86 ) != 0 ;
V_84 = V_5 -> V_39 & V_87 ;
V_5 -> V_39 &= ~ ( V_43 | V_87 ) ;
if ( V_5 -> V_39 & V_40 ) {
F_48 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_41 & V_42 ) ;
if ( ! V_83 ) {
F_49 ( & V_5 -> V_38 ) ;
return;
}
}
F_50 ( V_5 ) ;
if ( F_51 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_44 ) )
F_34 ( V_22 ) ;
else
F_49 ( & V_5 -> V_38 ) ;
if ( ! V_84 )
F_35 ( V_22 ) ;
}
STATIC T_4
F_52 (
struct V_2 * V_3 ,
T_4 V_88 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_53 ( V_5 ) ;
if ( ( V_5 -> V_39 & V_58 ) && V_3 -> V_89 != 0 )
return V_3 -> V_89 ;
return V_88 ;
}
STATIC void
F_54 (
struct V_2 * V_3 ,
T_4 V_90 )
{
}
void
F_55 (
T_3 * V_22 ,
T_5 * V_91 )
{
T_6 * V_3 = V_22 -> V_23 ;
T_1 * V_5 ;
int V_92 ;
int V_93 ;
ASSERT ( V_22 -> V_94 -> V_95 == V_91 ) ;
if ( V_3 != NULL && V_3 -> V_24 == V_25 )
return;
V_92 = ( int ) ( ( F_7 ( V_22 -> V_30 ) + ( V_45 - 1 ) ) >>
V_17 ) ;
V_93 = ( int ) ( ( V_92 + V_19 ) >> V_18 ) ;
V_5 = ( T_1 * ) F_56 ( V_96 ,
V_97 ) ;
F_57 ( V_91 , & V_5 -> V_4 , V_25 , & V_98 ) ;
V_5 -> V_29 = V_22 ;
F_58 ( V_22 ) ;
V_5 -> V_20 . V_99 = V_25 ;
V_5 -> V_20 . V_100 = ( V_101 ) F_59 ( V_22 ) ;
V_5 -> V_20 . V_102 = ( V_103 ) V_22 -> V_30 ;
V_5 -> V_20 . V_44 = V_93 ;
#ifdef F_60
V_5 -> V_28 = F_61 ( F_7 ( V_22 -> V_30 ) , V_97 ) ;
memcpy ( V_5 -> V_28 , V_22 -> V_31 , F_7 ( V_22 -> V_30 ) ) ;
V_5 -> V_16 = F_62 ( F_7 ( V_22 -> V_30 ) / V_104 , V_97 ) ;
#endif
if ( V_22 -> V_23 )
V_5 -> V_4 . V_105 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 ;
}
void
F_63 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
T_2 V_49 ;
T_2 V_37 ;
T_2 V_106 ;
T_2 V_107 ;
T_2 V_12 ;
T_2 * V_15 ;
T_2 V_108 ;
T_2 V_109 ;
T_2 V_110 ;
V_5 -> V_39 |= V_111 ;
V_49 = V_6 >> V_17 ;
V_37 = V_7 >> V_17 ;
V_106 = V_37 - V_49 + 1 ;
V_12 = V_49 >> V_18 ;
V_15 = & ( V_5 -> V_20 . V_21 [ V_12 ] ) ;
V_108 = V_49 & ( T_2 ) ( V_19 - 1 ) ;
if ( V_108 ) {
V_109 = F_64 ( V_108 + V_106 , ( T_2 ) V_19 ) ;
V_110 = ( ( 1 << ( V_109 - V_108 ) ) - 1 ) << V_108 ;
* V_15 |= V_110 ;
V_15 ++ ;
V_107 = V_109 - V_108 ;
} else {
V_107 = 0 ;
}
while ( ( V_106 - V_107 ) >= V_19 ) {
* V_15 |= 0xffffffff ;
V_107 += V_19 ;
V_15 ++ ;
}
V_109 = V_106 - V_107 ;
if ( V_109 ) {
V_110 = ( 1 << V_109 ) - 1 ;
* V_15 |= V_110 ;
}
F_3 ( V_5 , V_6 , V_7 ) ;
}
T_2
F_65 (
T_1 * V_5 )
{
return ( V_5 -> V_39 & V_111 ) ;
}
STATIC void
F_66 (
T_1 * V_5 )
{
#ifdef F_60
F_67 ( V_5 -> V_28 ) ;
F_67 ( V_5 -> V_16 ) ;
#endif
F_68 ( V_96 , V_5 ) ;
}
void
F_34 (
T_3 * V_22 )
{
T_1 * V_5 ;
F_69 ( V_22 , V_112 ) ;
V_5 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 -> V_4 . V_105 ;
if ( V_22 -> V_23 == NULL )
V_22 -> V_72 = NULL ;
F_70 ( V_22 ) ;
F_66 ( V_5 ) ;
}
void
F_71 (
T_3 * V_22 ,
void (* F_72)( T_3 * , T_6 * ) ,
T_6 * V_3 )
{
T_6 * V_113 ;
ASSERT ( F_27 ( V_22 ) ) ;
V_3 -> V_114 = F_72 ;
V_113 = V_22 -> V_23 ;
if ( V_113 ) {
V_3 -> V_105 = V_113 -> V_105 ;
V_113 -> V_105 = V_3 ;
} else {
V_22 -> V_23 = V_3 ;
}
ASSERT ( V_22 -> V_72 == NULL ||
V_22 -> V_72 == V_115 ) ;
V_22 -> V_72 = V_115 ;
}
STATIC void
F_31 (
struct V_34 * V_22 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_22 -> V_23 ) != NULL ) {
V_22 -> V_23 = V_3 -> V_105 ;
ASSERT ( V_3 -> V_114 != NULL ) ;
V_3 -> V_105 = NULL ;
V_3 -> V_114 ( V_22 , V_3 ) ;
}
}
void
V_115 (
struct V_34 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_23 ;
struct V_116 * V_91 = V_3 -> V_117 ;
static T_7 V_118 ;
static T_8 * V_119 ;
if ( F_73 ( ! F_74 ( V_22 ) ) )
goto V_120;
if ( F_75 ( V_91 ) ) {
F_39 ( V_22 ) ;
F_76 ( V_22 ) ;
F_77 ( V_22 , V_112 ) ;
goto V_120;
}
if ( V_22 -> V_94 != V_119 ||
F_78 ( V_121 , ( V_118 + 5 * V_122 ) ) ) {
V_118 = V_121 ;
F_79 ( V_22 , V_33 ) ;
}
V_119 = V_22 -> V_94 ;
if ( F_80 ( V_22 ) ) {
ASSERT ( V_22 -> V_72 != NULL ) ;
F_81 ( V_22 , V_112 ) ;
F_37 ( V_22 , 0 ) ;
if ( ! F_28 ( V_22 ) ) {
V_22 -> V_123 |= V_124 | V_125 | V_126 ;
F_82 ( V_22 ) ;
} else {
F_35 ( V_22 ) ;
}
return;
}
F_39 ( V_22 ) ;
F_76 ( V_22 ) ;
F_83 ( V_22 , V_112 ) ;
V_120:
F_31 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_72 = NULL ;
F_40 ( V_22 , 0 ) ;
}
void
F_84 (
struct V_34 * V_22 ,
struct V_2 * V_3 )
{
struct V_63 * V_64 = V_3 -> V_65 ;
ASSERT ( F_1 ( V_3 ) -> V_29 == V_22 ) ;
F_70 ( V_22 ) ;
F_32 ( & V_64 -> V_73 ) ;
F_33 ( V_64 , V_3 , V_127 ) ;
F_66 ( F_1 ( V_3 ) ) ;
}
