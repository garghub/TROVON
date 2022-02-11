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
T_1 * V_5 ;
T_2 V_10 ;
V_5 = F_6 ( V_22 , T_1 * ) ;
if ( ( V_5 == NULL ) || ( V_5 -> V_4 . V_23 != V_24 ) ) {
return;
}
ASSERT ( V_5 -> V_16 != NULL ) ;
V_10 = V_7 - V_6 + 1 ;
F_4 ( V_5 -> V_16 , V_6 , V_10 ) ;
}
STATIC void
F_7 (
T_1 * V_5 )
{
char * V_25 ;
char * V_26 ;
int V_8 ;
T_3 * V_22 ;
ASSERT ( V_5 -> V_27 != NULL ) ;
ASSERT ( V_5 -> V_16 != NULL ) ;
V_22 = V_5 -> V_28 ;
ASSERT ( F_8 ( V_22 ) > 0 ) ;
ASSERT ( F_9 ( V_22 ) != NULL ) ;
V_25 = V_5 -> V_27 ;
V_26 = F_9 ( V_22 ) ;
for ( V_8 = 0 ; V_8 < F_8 ( V_22 ) ; V_8 ++ ) {
if ( V_25 [ V_8 ] != V_26 [ V_8 ] && ! F_10 ( V_5 -> V_16 , V_8 ) ) {
F_11 ( V_22 -> V_29 ,
L_1 ,
V_30 , V_5 , V_22 , V_25 , V_8 ) ;
ASSERT ( 0 ) ;
}
}
}
STATIC T_2
F_12 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
T_2 V_32 ;
int V_33 ;
int V_34 ;
ASSERT ( F_13 ( & V_5 -> V_35 ) > 0 ) ;
if ( V_5 -> V_36 & V_37 ) {
F_14 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_38 & V_39 ) ;
return 1 ;
}
ASSERT ( V_5 -> V_36 & V_40 ) ;
V_32 = 1 ;
V_34 = F_15 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_41 , 0 ) ;
ASSERT ( V_34 != - 1 ) ;
V_32 ++ ;
while ( V_34 != - 1 ) {
V_33 = F_15 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_41 ,
V_34 + 1 ) ;
if ( V_33 == - 1 ) {
V_34 = - 1 ;
} else if ( V_33 != V_34 + 1 ) {
V_34 = V_33 ;
V_32 ++ ;
} else if ( F_16 ( V_22 , V_33 * V_42 ) !=
( F_16 ( V_22 , V_34 * V_42 ) +
V_42 ) ) {
V_34 = V_33 ;
V_32 ++ ;
} else {
V_34 ++ ;
}
}
F_17 ( V_5 ) ;
return V_32 ;
}
STATIC void
F_18 (
struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
T_2 V_45 ;
T_2 V_32 ;
int V_46 ;
int V_34 ;
int V_33 ;
T_2 V_47 ;
T_2 V_48 ;
ASSERT ( F_13 ( & V_5 -> V_35 ) > 0 ) ;
ASSERT ( ( V_5 -> V_36 & V_40 ) ||
( V_5 -> V_36 & V_37 ) ) ;
V_45 =
( T_2 ) ( sizeof( V_49 ) +
( ( V_5 -> V_20 . V_41 - 1 ) * sizeof( T_2 ) ) ) ;
V_44 -> V_50 = & V_5 -> V_20 ;
V_44 -> V_51 = V_45 ;
V_44 -> V_52 = V_53 ;
V_44 ++ ;
V_32 = 1 ;
if ( V_5 -> V_36 & V_54 ) {
if ( ! ( ( V_5 -> V_36 & V_55 ) &&
F_19 ( V_3 ) ) )
V_5 -> V_20 . V_38 |= V_56 ;
V_5 -> V_36 &= ~ V_54 ;
}
if ( V_5 -> V_36 & V_37 ) {
F_20 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_38 & V_39 ) ;
V_5 -> V_20 . V_57 = V_32 ;
return;
}
V_46 = F_15 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_41 , 0 ) ;
ASSERT ( V_46 != - 1 ) ;
V_34 = V_46 ;
V_47 = 1 ;
for (; ; ) {
V_33 = F_15 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_41 ,
( T_2 ) V_34 + 1 ) ;
if ( V_33 == - 1 ) {
V_48 = V_46 * V_42 ;
V_44 -> V_50 = F_16 ( V_22 , V_48 ) ;
V_44 -> V_51 = V_47 * V_42 ;
V_44 -> V_52 = V_58 ;
V_32 ++ ;
break;
} else if ( V_33 != V_34 + 1 ) {
V_48 = V_46 * V_42 ;
V_44 -> V_50 = F_16 ( V_22 , V_48 ) ;
V_44 -> V_51 = V_47 * V_42 ;
V_44 -> V_52 = V_58 ;
V_32 ++ ;
V_44 ++ ;
V_46 = V_33 ;
V_34 = V_33 ;
V_47 = 1 ;
} else if ( F_16 ( V_22 , V_33 << V_17 ) !=
( F_16 ( V_22 , V_34 << V_17 ) +
V_42 ) ) {
V_48 = V_46 * V_42 ;
V_44 -> V_50 = F_16 ( V_22 , V_48 ) ;
V_44 -> V_51 = V_47 * V_42 ;
V_44 -> V_52 = V_58 ;
V_44 ++ ;
V_46 = V_33 ;
V_34 = V_33 ;
V_47 = 1 ;
} else {
V_34 ++ ;
V_47 ++ ;
}
}
V_5 -> V_20 . V_57 = V_32 ;
F_21 ( V_5 ) ;
F_7 ( V_5 ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_23 ( V_5 -> V_28 ) ) ;
ASSERT ( F_13 ( & V_5 -> V_35 ) > 0 ) ;
ASSERT ( ( V_5 -> V_36 & V_40 ) ||
( V_5 -> V_36 & V_37 ) ) ;
F_24 ( V_5 ) ;
F_25 ( & V_5 -> V_35 ) ;
F_25 ( & V_5 -> V_28 -> V_59 ) ;
}
STATIC void
F_26 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 * V_22 = V_5 -> V_28 ;
struct V_60 * V_61 = V_3 -> V_62 ;
int V_63 = V_5 -> V_36 & V_37 ;
int V_64 ;
ASSERT ( F_6 ( V_22 , T_1 * ) == V_5 ) ;
ASSERT ( F_13 ( & V_5 -> V_35 ) > 0 ) ;
F_27 ( V_5 ) ;
V_64 = F_28 ( & V_5 -> V_35 ) ;
if ( F_28 ( & V_22 -> V_59 ) )
F_29 ( & V_22 -> V_65 ) ;
if ( V_64 && V_63 ) {
ASSERT ( V_5 -> V_36 & V_37 ) ;
ASSERT ( F_30 ( V_22 ) <= 0 ) ;
ASSERT ( ! ( F_31 ( V_22 ) ) ) ;
ASSERT ( F_32 ( V_22 ) ) ;
ASSERT ( V_5 -> V_20 . V_38 & V_39 ) ;
F_33 ( V_5 ) ;
if ( remove ) {
if ( V_3 -> V_66 )
F_34 ( V_3 ) ;
F_35 ( V_22 , NULL ) ;
}
if ( V_5 -> V_36 & V_67 ) {
F_36 ( V_22 ) ;
F_37 ( V_22 , NULL ) ;
F_38 ( V_22 ) ;
} else {
F_39 ( & V_61 -> V_68 ) ;
F_40 ( V_61 , ( V_69 * ) V_5 ) ;
F_41 ( V_22 ) ;
ASSERT ( F_6 ( V_22 , void * ) == NULL ) ;
}
F_42 ( V_22 ) ;
}
}
STATIC T_2
F_43 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
if ( F_44 ( V_22 ) )
return V_70 ;
if ( ! F_45 ( V_22 ) )
return V_71 ;
F_46 ( V_22 ) ;
ASSERT ( ! ( V_5 -> V_36 & V_37 ) ) ;
F_47 ( V_5 ) ;
if ( F_31 ( V_22 ) )
return V_72 ;
return V_73 ;
}
STATIC void
F_48 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
int V_74 ;
T_2 V_75 ;
F_35 ( V_22 , NULL ) ;
V_74 = ( V_3 -> V_76 & V_77 ) != 0 ;
V_75 = V_5 -> V_36 & V_78 ;
V_5 -> V_36 &= ~ ( V_40 | V_78 ) ;
if ( V_5 -> V_36 & V_37 ) {
F_49 ( V_5 ) ;
ASSERT ( V_5 -> V_20 . V_38 & V_39 ) ;
if ( ! V_74 ) {
F_50 ( & V_5 -> V_35 ) ;
return;
}
}
F_51 ( V_5 ) ;
if ( F_52 ( V_5 -> V_20 . V_21 ,
V_5 -> V_20 . V_41 ) )
F_41 ( V_22 ) ;
else
F_50 ( & V_5 -> V_35 ) ;
if ( ! V_75 )
F_42 ( V_22 ) ;
}
STATIC T_4
F_53 (
struct V_2 * V_3 ,
T_4 V_79 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_54 ( V_5 ) ;
if ( ( V_5 -> V_36 & V_55 ) && V_3 -> V_80 != 0 )
return V_3 -> V_80 ;
return V_79 ;
}
STATIC void
F_55 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
ASSERT ( ! ( V_5 -> V_36 & V_37 ) ) ;
ASSERT ( ! F_31 ( V_22 ) ) ;
F_56 ( V_5 ) ;
F_42 ( V_22 ) ;
}
STATIC void
F_57 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_31 * V_22 = V_5 -> V_28 ;
ASSERT ( ! ( V_5 -> V_36 & V_37 ) ) ;
ASSERT ( F_31 ( V_22 ) ) ;
F_58 ( V_5 ) ;
F_59 ( V_22 ) ;
F_42 ( V_22 ) ;
}
STATIC void
F_60 (
struct V_2 * V_3 ,
T_4 V_81 )
{
}
void
F_61 (
T_3 * V_22 ,
T_5 * V_82 )
{
V_69 * V_3 ;
T_1 * V_5 ;
int V_83 ;
int V_84 ;
ASSERT ( V_22 -> V_85 -> V_86 == V_82 ) ;
if ( F_6 ( V_22 , void * ) != NULL ) {
V_3 = F_6 ( V_22 , V_69 * ) ;
if ( V_3 -> V_23 == V_24 ) {
return;
}
}
V_83 = ( int ) ( ( F_8 ( V_22 ) + ( V_42 - 1 ) ) >> V_17 ) ;
V_84 = ( int ) ( ( V_83 + V_19 ) >> V_18 ) ;
V_5 = ( T_1 * ) F_62 ( V_87 ,
V_88 ) ;
F_63 ( V_82 , & V_5 -> V_4 , V_24 , & V_89 ) ;
V_5 -> V_28 = V_22 ;
F_64 ( V_22 ) ;
V_5 -> V_20 . V_90 = V_24 ;
V_5 -> V_20 . V_91 = ( V_92 ) F_65 ( V_22 ) ;
V_5 -> V_20 . V_93 = ( V_94 ) F_66 ( F_8 ( V_22 ) ) ;
V_5 -> V_20 . V_41 = V_84 ;
#ifdef F_67
V_5 -> V_27 = ( char * ) F_68 ( F_8 ( V_22 ) , V_88 ) ;
memcpy ( V_5 -> V_27 , F_9 ( V_22 ) , F_8 ( V_22 ) ) ;
V_5 -> V_16 = ( char * ) F_69 ( F_8 ( V_22 ) / V_95 , V_88 ) ;
#endif
if ( F_6 ( V_22 , void * ) != NULL ) {
V_5 -> V_4 . V_96 =
F_6 ( V_22 , V_69 * ) ;
}
F_37 ( V_22 , V_5 ) ;
}
void
F_70 (
T_1 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
T_2 V_46 ;
T_2 V_34 ;
T_2 V_97 ;
T_2 V_98 ;
T_2 V_12 ;
T_2 * V_15 ;
T_2 V_99 ;
T_2 V_100 ;
T_2 V_101 ;
V_5 -> V_36 |= V_102 ;
V_46 = V_6 >> V_17 ;
V_34 = V_7 >> V_17 ;
V_97 = V_34 - V_46 + 1 ;
V_12 = V_46 >> V_18 ;
V_15 = & ( V_5 -> V_20 . V_21 [ V_12 ] ) ;
V_99 = V_46 & ( T_2 ) ( V_19 - 1 ) ;
if ( V_99 ) {
V_100 = F_71 ( V_99 + V_97 , ( T_2 ) V_19 ) ;
V_101 = ( ( 1 << ( V_100 - V_99 ) ) - 1 ) << V_99 ;
* V_15 |= V_101 ;
V_15 ++ ;
V_98 = V_100 - V_99 ;
} else {
V_98 = 0 ;
}
while ( ( V_97 - V_98 ) >= V_19 ) {
* V_15 |= 0xffffffff ;
V_98 += V_19 ;
V_15 ++ ;
}
V_100 = V_97 - V_98 ;
if ( V_100 ) {
V_101 = ( 1 << V_100 ) - 1 ;
* V_15 |= V_101 ;
}
F_3 ( V_5 , V_6 , V_7 ) ;
}
T_2
F_72 (
T_1 * V_5 )
{
return ( V_5 -> V_36 & V_102 ) ;
}
STATIC void
F_73 (
T_1 * V_5 )
{
#ifdef F_67
F_74 ( V_5 -> V_27 ) ;
F_74 ( V_5 -> V_16 ) ;
#endif
F_75 ( V_87 , V_5 ) ;
}
void
F_41 (
T_3 * V_22 )
{
T_1 * V_5 ;
F_76 ( V_22 , V_103 ) ;
V_5 = F_6 ( V_22 , T_1 * ) ;
F_37 ( V_22 , V_5 -> V_4 . V_96 ) ;
if ( ( F_6 ( V_22 , void * ) == NULL ) &&
( F_77 ( V_22 ) != NULL ) ) {
F_38 ( V_22 ) ;
}
F_78 ( V_22 ) ;
F_73 ( V_5 ) ;
}
void
F_79 (
T_3 * V_22 ,
void (* F_80)( T_3 * , V_69 * ) ,
V_69 * V_3 )
{
V_69 * V_104 ;
ASSERT ( F_23 ( V_22 ) ) ;
ASSERT ( F_30 ( V_22 ) <= 0 ) ;
V_3 -> V_105 = F_80 ;
if ( F_6 ( V_22 , void * ) != NULL ) {
V_104 = F_6 ( V_22 , V_69 * ) ;
V_3 -> V_96 = V_104 -> V_96 ;
V_104 -> V_96 = V_3 ;
} else {
F_37 ( V_22 , V_3 ) ;
}
ASSERT ( ( F_77 ( V_22 ) == V_106 ) ||
( F_77 ( V_22 ) == NULL ) ) ;
F_81 ( V_22 , V_106 ) ;
}
STATIC void
F_36 (
struct V_31 * V_22 )
{
struct V_2 * V_3 ;
while ( ( V_3 = F_6 ( V_22 , V_69 * ) ) != NULL ) {
F_37 ( V_22 , V_3 -> V_96 ) ;
ASSERT ( V_3 -> V_105 != NULL ) ;
V_3 -> V_96 = NULL ;
V_3 -> V_105 ( V_22 , V_3 ) ;
}
}
void
V_106 (
struct V_31 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_107 ;
struct V_108 * V_82 = V_3 -> V_109 ;
static T_6 V_110 ;
static T_7 * V_111 ;
if ( F_82 ( ! F_83 ( V_22 ) ) )
goto V_112;
if ( F_84 ( V_82 ) ) {
F_85 ( V_22 ) ;
F_86 ( V_22 , V_103 ) ;
goto V_112;
}
if ( F_87 ( V_22 ) != V_111 ||
F_88 ( V_113 , ( V_110 + 5 * V_114 ) ) ) {
V_110 = V_113 ;
F_89 ( V_82 , L_2 ,
F_90 ( F_87 ( V_22 ) ) ,
( V_115 ) F_65 ( V_22 ) ) ;
}
V_111 = F_87 ( V_22 ) ;
if ( F_91 ( V_22 ) ) {
F_92 ( V_22 , 0 ) ;
if ( ! F_32 ( V_22 ) ) {
F_93 ( V_22 ) ;
F_94 ( V_22 ) ;
F_95 ( V_22 ) ;
}
ASSERT ( F_77 ( V_22 ) ) ;
F_96 ( V_22 , V_103 ) ;
F_42 ( V_22 ) ;
return;
}
F_97 ( V_22 ) ;
F_94 ( V_22 ) ;
F_98 ( V_22 ) ;
F_99 ( V_22 , V_103 ) ;
F_100 ( V_82 , V_116 ) ;
V_112:
F_36 ( V_22 ) ;
F_37 ( V_22 , NULL ) ;
F_38 ( V_22 ) ;
F_101 ( V_22 , 0 ) ;
}
void
F_102 (
struct V_31 * V_22 ,
struct V_2 * V_3 )
{
struct V_60 * V_61 = V_3 -> V_62 ;
ASSERT ( F_1 ( V_3 ) -> V_28 == V_22 ) ;
F_78 ( V_22 ) ;
F_39 ( & V_61 -> V_68 ) ;
F_40 ( V_61 , V_3 ) ;
F_73 ( F_1 ( V_3 ) ) ;
}
