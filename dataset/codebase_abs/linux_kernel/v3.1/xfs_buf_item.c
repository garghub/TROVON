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
ASSERT ( F_7 ( V_22 ) > 0 ) ;
ASSERT ( V_22 -> V_30 != NULL ) ;
V_26 = V_5 -> V_28 ;
V_27 = V_22 -> V_30 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_22 ) ; V_8 ++ ) {
if ( V_26 [ V_8 ] != V_27 [ V_8 ] && ! F_8 ( V_5 -> V_16 , V_8 ) ) {
F_9 ( V_22 -> V_31 ,
L_1 ,
V_32 , V_5 , V_22 , V_26 , V_8 ) ;
ASSERT ( 0 ) ;
}
}
}
STATIC T_2
F_10 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
T_2 V_34 ;
int V_35 ;
int V_36 ;
ASSERT ( F_11 ( & V_5 -> V_37 ) > 0 ) ;
if ( V_5 -> V_38 & V_39 ) {
F_12 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_40 & V_41 ) ;
return 1 ;
}
ASSERT ( V_5 -> V_38 & V_42 ) ;
V_34 = 1 ;
V_36 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_43 , 0 ) ;
ASSERT ( V_36 != - 1 ) ;
V_34 ++ ;
while ( V_36 != - 1 ) {
V_35 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_43 ,
V_36 + 1 ) ;
if ( V_35 == - 1 ) {
V_36 = - 1 ;
} else if ( V_35 != V_36 + 1 ) {
V_36 = V_35 ;
V_34 ++ ;
} else if ( F_14 ( V_22 , V_35 * V_44 ) !=
( F_14 ( V_22 , V_36 * V_44 ) +
V_44 ) ) {
V_36 = V_35 ;
V_34 ++ ;
} else {
V_36 ++ ;
}
}
F_15 ( V_5 ) ;
return V_34 ;
}
STATIC void
F_16 (
struct V_2 * V_3 ,
struct V_45 * V_46 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
T_2 V_47 ;
T_2 V_34 ;
int V_48 ;
int V_36 ;
int V_35 ;
T_2 V_49 ;
T_2 V_50 ;
ASSERT ( F_11 ( & V_5 -> V_37 ) > 0 ) ;
ASSERT ( ( V_5 -> V_38 & V_42 ) ||
( V_5 -> V_38 & V_39 ) ) ;
V_47 =
( T_2 ) ( sizeof( V_51 ) +
( ( V_5 -> V_20 . V_43 - 1 ) * sizeof( T_2 ) ) ) ;
V_46 -> V_52 = & V_5 -> V_20 ;
V_46 -> V_53 = V_47 ;
V_46 -> V_54 = V_55 ;
V_46 ++ ;
V_34 = 1 ;
if ( V_5 -> V_38 & V_56 ) {
if ( ! ( ( V_5 -> V_38 & V_57 ) &&
F_17 ( V_3 ) ) )
V_5 -> V_20 . V_40 |= V_58 ;
V_5 -> V_38 &= ~ V_56 ;
}
if ( V_5 -> V_38 & V_39 ) {
F_18 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_40 & V_41 ) ;
V_5 -> V_20 . V_59 = V_34 ;
return;
}
V_48 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_43 , 0 ) ;
ASSERT ( V_48 != - 1 ) ;
V_36 = V_48 ;
V_49 = 1 ;
for (; ; ) {
V_35 = F_13 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_43 ,
( T_2 ) V_36 + 1 ) ;
if ( V_35 == - 1 ) {
V_50 = V_48 * V_44 ;
V_46 -> V_52 = F_14 ( V_22 , V_50 ) ;
V_46 -> V_53 = V_49 * V_44 ;
V_46 -> V_54 = V_60 ;
V_34 ++ ;
break;
} else if ( V_35 != V_36 + 1 ) {
V_50 = V_48 * V_44 ;
V_46 -> V_52 = F_14 ( V_22 , V_50 ) ;
V_46 -> V_53 = V_49 * V_44 ;
V_46 -> V_54 = V_60 ;
V_34 ++ ;
V_46 ++ ;
V_48 = V_35 ;
V_36 = V_35 ;
V_49 = 1 ;
} else if ( F_14 ( V_22 , V_35 << V_17 ) !=
( F_14 ( V_22 , V_36 << V_17 ) +
V_44 ) ) {
V_50 = V_48 * V_44 ;
V_46 -> V_52 = F_14 ( V_22 , V_50 ) ;
V_46 -> V_53 = V_49 * V_44 ;
V_46 -> V_54 = V_60 ;
V_46 ++ ;
V_48 = V_35 ;
V_36 = V_35 ;
V_49 = 1 ;
} else {
V_36 ++ ;
V_49 ++ ;
}
}
V_5 -> V_20 . V_59 = V_34 ;
F_19 ( V_5 ) ;
F_6 ( V_5 ) ;
}
STATIC void
F_20 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_11 ( & V_5 -> V_37 ) > 0 ) ;
ASSERT ( ( V_5 -> V_38 & V_42 ) ||
( V_5 -> V_38 & V_39 ) ) ;
F_21 ( V_5 ) ;
F_22 ( & V_5 -> V_37 ) ;
F_22 ( & V_5 -> V_29 -> V_61 ) ;
}
STATIC void
F_23 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 * V_22 = V_5 -> V_29 ;
struct V_62 * V_63 = V_3 -> V_64 ;
int V_65 = V_5 -> V_38 & V_39 ;
int V_66 ;
ASSERT ( V_22 -> V_23 == V_5 ) ;
ASSERT ( F_11 ( & V_5 -> V_37 ) > 0 ) ;
F_24 ( V_5 ) ;
V_66 = F_25 ( & V_5 -> V_37 ) ;
if ( F_25 ( & V_22 -> V_61 ) )
F_26 ( & V_22 -> V_67 ) ;
if ( V_66 && V_65 ) {
ASSERT ( V_5 -> V_38 & V_39 ) ;
ASSERT ( F_27 ( V_22 ) ) ;
ASSERT ( ! ( F_28 ( V_22 ) ) ) ;
ASSERT ( F_29 ( V_22 ) ) ;
ASSERT ( V_5 -> V_20 . V_40 & V_41 ) ;
F_30 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_68 )
F_31 ( V_3 ) ;
V_22 -> V_69 = NULL ;
}
if ( V_5 -> V_38 & V_70 ) {
F_32 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_71 = NULL ;
} else {
F_33 ( & V_63 -> V_72 ) ;
F_34 ( V_63 , ( V_73 * ) V_5 ) ;
F_35 ( V_22 ) ;
ASSERT ( V_22 -> V_23 == NULL ) ;
}
F_36 ( V_22 ) ;
}
}
STATIC T_2
F_37 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
if ( F_38 ( V_22 ) )
return V_74 ;
if ( ! F_39 ( V_22 ) )
return V_75 ;
F_40 ( V_22 ) ;
ASSERT ( ! ( V_5 -> V_38 & V_39 ) ) ;
F_41 ( V_5 ) ;
if ( F_28 ( V_22 ) )
return V_76 ;
return V_77 ;
}
STATIC void
F_42 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
int V_78 ;
T_2 V_79 ;
V_22 -> V_69 = NULL ;
V_78 = ( V_3 -> V_80 & V_81 ) != 0 ;
V_79 = V_5 -> V_38 & V_82 ;
V_5 -> V_38 &= ~ ( V_42 | V_82 ) ;
if ( V_5 -> V_38 & V_39 ) {
F_43 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_40 & V_41 ) ;
if ( ! V_78 ) {
F_44 ( & V_5 -> V_37 ) ;
return;
}
}
F_45 ( V_5 ) ;
if ( F_46 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_43 ) )
F_35 ( V_22 ) ;
else
F_44 ( & V_5 -> V_37 ) ;
if ( ! V_79 )
F_36 ( V_22 ) ;
}
STATIC T_4
F_47 (
struct V_2 * V_3 ,
T_4 V_83 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_48 ( V_5 ) ;
if ( ( V_5 -> V_38 & V_57 ) && V_3 -> V_84 != 0 )
return V_3 -> V_84 ;
return V_83 ;
}
STATIC void
F_49 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
ASSERT ( ! ( V_5 -> V_38 & V_39 ) ) ;
ASSERT ( ! F_28 ( V_22 ) ) ;
F_50 ( V_5 ) ;
F_36 ( V_22 ) ;
}
STATIC bool
F_51 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_33 * V_22 = V_5 -> V_29 ;
ASSERT ( ! ( V_5 -> V_38 & V_39 ) ) ;
ASSERT ( F_28 ( V_22 ) ) ;
F_52 ( V_5 ) ;
F_53 ( V_22 ) ;
F_36 ( V_22 ) ;
return true ;
}
STATIC void
F_54 (
struct V_2 * V_3 ,
T_4 V_85 )
{
}
void
F_55 (
T_3 * V_22 ,
T_5 * V_86 )
{
V_73 * V_3 = V_22 -> V_23 ;
T_1 * V_5 ;
int V_87 ;
int V_88 ;
ASSERT ( V_22 -> V_89 -> V_90 == V_86 ) ;
if ( V_3 != NULL && V_3 -> V_24 == V_25 )
return;
V_87 = ( int ) ( ( F_7 ( V_22 ) + ( V_44 - 1 ) ) >> V_17 ) ;
V_88 = ( int ) ( ( V_87 + V_19 ) >> V_18 ) ;
V_5 = ( T_1 * ) F_56 ( V_91 ,
V_92 ) ;
F_57 ( V_86 , & V_5 -> V_4 , V_25 , & V_93 ) ;
V_5 -> V_29 = V_22 ;
F_40 ( V_22 ) ;
V_5 -> V_20 . V_94 = V_25 ;
V_5 -> V_20 . V_95 = ( V_96 ) F_58 ( V_22 ) ;
V_5 -> V_20 . V_97 = ( V_98 ) F_59 ( F_7 ( V_22 ) ) ;
V_5 -> V_20 . V_43 = V_88 ;
#ifdef F_60
V_5 -> V_28 = ( char * ) F_61 ( F_7 ( V_22 ) , V_92 ) ;
memcpy ( V_5 -> V_28 , V_22 -> V_30 , F_7 ( V_22 ) ) ;
V_5 -> V_16 = ( char * ) F_62 ( F_7 ( V_22 ) / V_99 , V_92 ) ;
#endif
if ( V_22 -> V_23 )
V_5 -> V_4 . V_100 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 ;
}
void
F_63 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
T_2 V_48 ;
T_2 V_36 ;
T_2 V_101 ;
T_2 V_102 ;
T_2 V_12 ;
T_2 * V_15 ;
T_2 V_103 ;
T_2 V_104 ;
T_2 V_105 ;
V_5 -> V_38 |= V_106 ;
V_48 = V_6 >> V_17 ;
V_36 = V_7 >> V_17 ;
V_101 = V_36 - V_48 + 1 ;
V_12 = V_48 >> V_18 ;
V_15 = & ( V_5 -> V_20 . V_21 [ V_12 ] ) ;
V_103 = V_48 & ( T_2 ) ( V_19 - 1 ) ;
if ( V_103 ) {
V_104 = F_64 ( V_103 + V_101 , ( T_2 ) V_19 ) ;
V_105 = ( ( 1 << ( V_104 - V_103 ) ) - 1 ) << V_103 ;
* V_15 |= V_105 ;
V_15 ++ ;
V_102 = V_104 - V_103 ;
} else {
V_102 = 0 ;
}
while ( ( V_101 - V_102 ) >= V_19 ) {
* V_15 |= 0xffffffff ;
V_102 += V_19 ;
V_15 ++ ;
}
V_104 = V_101 - V_102 ;
if ( V_104 ) {
V_105 = ( 1 << V_104 ) - 1 ;
* V_15 |= V_105 ;
}
F_3 ( V_5 , V_6 , V_7 ) ;
}
T_2
F_65 (
T_1 * V_5 )
{
return ( V_5 -> V_38 & V_106 ) ;
}
STATIC void
F_66 (
T_1 * V_5 )
{
#ifdef F_60
F_67 ( V_5 -> V_28 ) ;
F_67 ( V_5 -> V_16 ) ;
#endif
F_68 ( V_91 , V_5 ) ;
}
void
F_35 (
T_3 * V_22 )
{
T_1 * V_5 ;
F_69 ( V_22 , V_107 ) ;
V_5 = V_22 -> V_23 ;
V_22 -> V_23 = V_5 -> V_4 . V_100 ;
if ( V_22 -> V_23 == NULL )
V_22 -> V_71 = NULL ;
F_70 ( V_22 ) ;
F_66 ( V_5 ) ;
}
void
F_71 (
T_3 * V_22 ,
void (* F_72)( T_3 * , V_73 * ) ,
V_73 * V_3 )
{
V_73 * V_108 ;
ASSERT ( F_27 ( V_22 ) ) ;
V_3 -> V_109 = F_72 ;
V_108 = V_22 -> V_23 ;
if ( V_108 ) {
V_3 -> V_100 = V_108 -> V_100 ;
V_108 -> V_100 = V_3 ;
} else {
V_22 -> V_23 = V_3 ;
}
ASSERT ( V_22 -> V_71 == NULL ||
V_22 -> V_71 == V_110 ) ;
V_22 -> V_71 = V_110 ;
}
STATIC void
F_32 (
struct V_33 * V_22 )
{
struct V_2 * V_3 ;
while ( ( V_3 = V_22 -> V_23 ) != NULL ) {
V_22 -> V_23 = V_3 -> V_100 ;
ASSERT ( V_3 -> V_109 != NULL ) ;
V_3 -> V_100 = NULL ;
V_3 -> V_109 ( V_22 , V_3 ) ;
}
}
void
V_110 (
struct V_33 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_23 ;
struct V_111 * V_86 = V_3 -> V_112 ;
static T_6 V_113 ;
static T_7 * V_114 ;
if ( F_73 ( ! F_74 ( V_22 ) ) )
goto V_115;
if ( F_75 ( V_86 ) ) {
F_76 ( V_22 ) ;
F_77 ( V_22 , V_107 ) ;
goto V_115;
}
if ( V_22 -> V_89 != V_114 ||
F_78 ( V_116 , ( V_113 + 5 * V_117 ) ) ) {
V_113 = V_116 ;
F_79 ( V_86 , L_2 ,
F_80 ( V_22 -> V_89 ) ,
( V_118 ) F_58 ( V_22 ) ) ;
}
V_114 = V_22 -> V_89 ;
if ( F_81 ( V_22 ) ) {
F_82 ( V_22 , 0 ) ;
if ( ! F_29 ( V_22 ) ) {
F_83 ( V_22 ) ;
F_84 ( V_22 ) ;
}
ASSERT ( V_22 -> V_71 != NULL ) ;
F_85 ( V_22 , V_107 ) ;
F_36 ( V_22 ) ;
return;
}
F_86 ( V_22 ) ;
F_84 ( V_22 ) ;
F_87 ( V_22 ) ;
F_88 ( V_22 , V_107 ) ;
V_115:
F_32 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_71 = NULL ;
F_89 ( V_22 , 0 ) ;
}
void
F_90 (
struct V_33 * V_22 ,
struct V_2 * V_3 )
{
struct V_62 * V_63 = V_3 -> V_64 ;
ASSERT ( F_1 ( V_3 ) -> V_29 == V_22 ) ;
F_70 ( V_22 ) ;
F_33 ( & V_63 -> V_72 ) ;
F_34 ( V_63 , V_3 ) ;
F_66 ( F_1 ( V_3 ) ) ;
}
