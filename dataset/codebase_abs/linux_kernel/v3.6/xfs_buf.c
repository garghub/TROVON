static inline int
F_1 (
struct V_1 * V_2 )
{
return V_2 -> V_3 && V_2 -> V_4 > 1 ;
}
static inline int
F_2 (
struct V_1 * V_2 )
{
return ( V_2 -> V_4 * V_5 ) - V_2 -> V_6 ;
}
STATIC void
F_3 (
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( & V_8 -> V_10 ) ;
if ( F_5 ( & V_2 -> V_11 ) ) {
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_11 , & V_8 -> V_13 ) ;
V_8 -> V_14 ++ ;
V_2 -> V_15 &= ~ V_16 ;
}
F_8 ( & V_8 -> V_10 ) ;
}
STATIC void
F_9 (
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_5 ( & V_2 -> V_11 ) )
return;
F_4 ( & V_8 -> V_10 ) ;
if ( ! F_5 ( & V_2 -> V_11 ) ) {
F_10 ( & V_2 -> V_11 ) ;
V_8 -> V_14 -- ;
}
F_8 ( & V_8 -> V_10 ) ;
}
void
F_11 (
struct V_1 * V_2 )
{
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_17 |= V_18 ;
V_2 -> V_17 &= ~ V_19 ;
F_13 ( & ( V_2 ) -> V_20 , 0 ) ;
if ( ! F_5 ( & V_2 -> V_11 ) ) {
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( & V_8 -> V_10 ) ;
if ( ! F_5 ( & V_2 -> V_11 ) &&
! ( V_2 -> V_15 & V_16 ) ) {
F_10 ( & V_2 -> V_11 ) ;
V_8 -> V_14 -- ;
F_14 ( & V_2 -> V_12 ) ;
}
F_8 ( & V_8 -> V_10 ) ;
}
ASSERT ( F_15 ( & V_2 -> V_12 ) >= 1 ) ;
}
static int
F_16 (
struct V_1 * V_2 ,
int V_21 )
{
ASSERT ( V_2 -> V_22 == NULL ) ;
V_2 -> V_23 = V_21 ;
if ( V_21 == 1 ) {
V_2 -> V_22 = & V_2 -> V_24 ;
return 0 ;
}
V_2 -> V_22 = F_17 ( V_21 * sizeof( struct V_25 ) ,
V_26 ) ;
if ( ! V_2 -> V_22 )
return V_27 ;
return 0 ;
}
static void
F_18 (
struct V_1 * V_2 )
{
if ( V_2 -> V_22 != & V_2 -> V_24 ) {
F_19 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
}
struct V_1 *
F_20 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 )
{
struct V_1 * V_2 ;
int error ;
int V_32 ;
V_2 = F_21 ( V_33 , V_26 ) ;
if ( F_22 ( ! V_2 ) )
return NULL ;
V_31 &= ~ ( V_34 | V_35 | V_36 | V_37 ) ;
F_13 ( & V_2 -> V_12 , 1 ) ;
F_13 ( & V_2 -> V_20 , 1 ) ;
F_23 ( & V_2 -> V_38 ) ;
F_24 ( & V_2 -> V_11 ) ;
F_24 ( & V_2 -> V_39 ) ;
F_25 ( & V_2 -> V_40 ) ;
F_26 ( & V_2 -> V_41 , 0 ) ;
F_27 ( V_2 ) ;
V_2 -> V_9 = V_28 ;
V_2 -> V_17 = V_31 ;
error = F_16 ( V_2 , V_30 ) ;
if ( error ) {
F_28 ( V_33 , V_2 ) ;
return NULL ;
}
V_2 -> V_42 = V_29 [ 0 ] . V_43 ;
V_2 -> V_44 = 0 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ ) {
V_2 -> V_22 [ V_32 ] . V_43 = V_29 [ V_32 ] . V_43 ;
V_2 -> V_22 [ V_32 ] . V_45 = V_29 [ V_32 ] . V_45 ;
V_2 -> V_44 += V_29 [ V_32 ] . V_45 ;
}
V_2 -> V_46 = V_2 -> V_44 ;
F_13 ( & V_2 -> V_47 , 0 ) ;
F_29 ( & V_2 -> V_48 ) ;
F_30 ( V_49 ) ;
F_31 ( V_2 , V_50 ) ;
return V_2 ;
}
STATIC int
F_32 (
T_2 * V_2 ,
int V_51 ,
T_1 V_31 )
{
if ( V_2 -> V_52 == NULL ) {
V_2 -> V_4 = V_51 ;
if ( V_51 <= V_53 ) {
V_2 -> V_52 = V_2 -> V_54 ;
} else {
V_2 -> V_52 = F_33 ( sizeof( struct V_55 * ) *
V_51 , V_26 ) ;
if ( V_2 -> V_52 == NULL )
return - V_27 ;
}
memset ( V_2 -> V_52 , 0 , sizeof( struct V_55 * ) * V_51 ) ;
}
return 0 ;
}
STATIC void
F_34 (
T_2 * V_2 )
{
if ( V_2 -> V_52 != V_2 -> V_54 ) {
F_19 ( V_2 -> V_52 ) ;
V_2 -> V_52 = NULL ;
}
}
void
F_35 (
T_2 * V_2 )
{
F_36 ( V_2 , V_50 ) ;
ASSERT ( F_5 ( & V_2 -> V_11 ) ) ;
if ( V_2 -> V_17 & V_56 ) {
T_3 V_32 ;
if ( F_1 ( V_2 ) )
F_37 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_4 ; V_32 ++ ) {
struct V_55 * V_55 = V_2 -> V_52 [ V_32 ] ;
F_38 ( V_55 ) ;
}
} else if ( V_2 -> V_17 & V_57 )
F_19 ( V_2 -> V_3 ) ;
F_34 ( V_2 ) ;
F_18 ( V_2 ) ;
F_28 ( V_33 , V_2 ) ;
}
STATIC int
F_39 (
T_2 * V_2 ,
T_3 V_31 )
{
T_4 V_58 ;
T_4 V_59 , V_60 ;
T_5 V_61 = F_40 ( V_31 ) ;
unsigned short V_51 , V_32 ;
T_6 V_62 , V_63 ;
int error ;
V_58 = F_41 ( V_2 -> V_44 ) ;
if ( V_58 < V_5 ) {
V_2 -> V_3 = F_33 ( V_58 , V_26 ) ;
if ( ! V_2 -> V_3 ) {
goto V_64;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_58 - 1 ) & V_65 ) !=
( ( unsigned long ) V_2 -> V_3 & V_65 ) ) {
F_19 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_64;
}
V_2 -> V_6 = F_42 ( V_2 -> V_3 ) ;
V_2 -> V_52 = V_2 -> V_54 ;
V_2 -> V_52 [ 0 ] = F_43 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_17 |= V_57 ;
return 0 ;
}
V_64:
V_62 = F_41 ( V_2 -> V_24 . V_43 ) >> V_66 ;
V_63 = ( F_41 ( V_2 -> V_24 . V_43 + V_2 -> V_44 ) + V_5 - 1 )
>> V_66 ;
V_51 = V_63 - V_62 ;
error = F_32 ( V_2 , V_51 , V_31 ) ;
if ( F_22 ( error ) )
return error ;
V_60 = V_2 -> V_6 ;
V_2 -> V_17 |= V_56 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_4 ; V_32 ++ ) {
struct V_55 * V_55 ;
T_3 V_67 = 0 ;
V_68:
V_55 = F_44 ( V_61 ) ;
if ( F_22 ( V_55 == NULL ) ) {
if ( V_31 & V_37 ) {
V_2 -> V_4 = V_32 ;
error = V_27 ;
goto V_69;
}
if ( ! ( ++ V_67 % 100 ) )
F_45 ( NULL ,
L_1 ,
V_70 , V_61 ) ;
F_30 ( V_71 ) ;
F_46 ( V_72 , V_73 / 50 ) ;
goto V_68;
}
F_30 ( V_74 ) ;
V_59 = F_47 ( T_4 , V_58 , V_5 - V_60 ) ;
V_58 -= V_59 ;
V_2 -> V_52 [ V_32 ] = V_55 ;
V_60 = 0 ;
}
return 0 ;
V_69:
for ( V_32 = 0 ; V_32 < V_2 -> V_4 ; V_32 ++ )
F_38 ( V_2 -> V_52 [ V_32 ] ) ;
return error ;
}
STATIC int
F_48 (
T_2 * V_2 ,
T_3 V_31 )
{
ASSERT ( V_2 -> V_17 & V_56 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_49 ( V_2 -> V_52 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_31 & V_34 ) {
V_2 -> V_3 = NULL ;
} else {
int V_75 = 0 ;
do {
V_2 -> V_3 = F_50 ( V_2 -> V_52 , V_2 -> V_4 ,
- 1 , V_76 ) ;
if ( V_2 -> V_3 )
break;
F_51 () ;
} while ( V_75 ++ <= 1 );
if ( ! V_2 -> V_3 )
return - V_27 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_2 *
F_52 (
struct V_7 * V_8 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 ,
T_2 * V_77 )
{
T_4 V_78 ;
struct V_79 * V_80 ;
struct V_81 * * V_82 ;
struct V_81 * V_83 ;
T_2 * V_2 ;
T_7 V_84 = V_29 [ 0 ] . V_43 ;
int V_85 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ )
V_85 += V_29 [ V_32 ] . V_45 ;
V_78 = F_41 ( V_85 ) ;
ASSERT ( ! ( V_78 < ( 1 << V_8 -> V_86 ) ) ) ;
ASSERT ( ! ( F_41 ( V_84 ) & ( T_6 ) V_8 -> V_87 ) ) ;
V_80 = F_53 ( V_8 -> V_88 ,
F_54 ( V_8 -> V_88 , V_84 ) ) ;
F_4 ( & V_80 -> V_89 ) ;
V_82 = & V_80 -> V_90 . V_81 ;
V_83 = NULL ;
V_2 = NULL ;
while ( * V_82 ) {
V_83 = * V_82 ;
V_2 = F_55 ( V_83 , struct V_1 , V_40 ) ;
if ( V_84 < V_2 -> V_42 )
V_82 = & ( * V_82 ) -> V_91 ;
else if ( V_84 > V_2 -> V_42 )
V_82 = & ( * V_82 ) -> V_92 ;
else {
if ( V_2 -> V_44 != V_85 ) {
ASSERT ( V_2 -> V_17 & V_18 ) ;
V_82 = & ( * V_82 ) -> V_92 ;
continue;
}
F_6 ( & V_2 -> V_12 ) ;
goto V_93;
}
}
if ( V_77 ) {
F_56 ( & V_77 -> V_40 , V_83 , V_82 ) ;
F_57 ( & V_77 -> V_40 , & V_80 -> V_90 ) ;
V_77 -> V_94 = V_80 ;
F_8 ( & V_80 -> V_89 ) ;
} else {
F_30 ( V_95 ) ;
F_8 ( & V_80 -> V_89 ) ;
F_58 ( V_80 ) ;
}
return V_77 ;
V_93:
F_8 ( & V_80 -> V_89 ) ;
F_58 ( V_80 ) ;
if ( ! F_59 ( V_2 ) ) {
if ( V_31 & V_35 ) {
F_60 ( V_2 ) ;
F_30 ( V_96 ) ;
return NULL ;
}
F_61 ( V_2 ) ;
F_30 ( V_97 ) ;
}
if ( V_2 -> V_17 & V_18 ) {
ASSERT ( ( V_2 -> V_17 & V_19 ) == 0 ) ;
V_2 -> V_17 &= V_57 | V_56 ;
}
F_62 ( V_2 , V_31 , V_50 ) ;
F_30 ( V_98 ) ;
return V_2 ;
}
struct V_1 *
F_63 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_77 ;
int error = 0 ;
V_2 = F_52 ( V_28 , V_29 , V_30 , V_31 , NULL ) ;
if ( F_64 ( V_2 ) )
goto V_93;
V_77 = F_20 ( V_28 , V_29 , V_30 , V_31 ) ;
if ( F_22 ( ! V_77 ) )
return NULL ;
error = F_39 ( V_77 , V_31 ) ;
if ( error ) {
F_35 ( V_77 ) ;
return NULL ;
}
V_2 = F_52 ( V_28 , V_29 , V_30 , V_31 , V_77 ) ;
if ( ! V_2 ) {
F_35 ( V_77 ) ;
return NULL ;
}
if ( V_2 != V_77 )
F_35 ( V_77 ) ;
V_93:
if ( ! V_2 -> V_3 ) {
error = F_48 ( V_2 , V_31 ) ;
if ( F_22 ( error ) ) {
F_65 ( V_28 -> V_88 ,
L_2 , V_70 ) ;
F_66 ( V_2 ) ;
return NULL ;
}
}
F_30 ( V_99 ) ;
F_67 ( V_2 , V_31 , V_50 ) ;
return V_2 ;
}
STATIC int
F_68 (
T_2 * V_2 ,
T_1 V_31 )
{
ASSERT ( ! ( V_31 & V_100 ) ) ;
ASSERT ( V_2 -> V_24 . V_43 != V_101 ) ;
V_2 -> V_17 &= ~ ( V_100 | V_36 | V_37 ) ;
V_2 -> V_17 |= V_31 & ( V_102 | V_36 | V_37 ) ;
F_69 ( V_2 ) ;
if ( V_31 & V_36 )
return 0 ;
return F_70 ( V_2 ) ;
}
T_2 *
F_71 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 )
{
struct V_1 * V_2 ;
V_31 |= V_102 ;
V_2 = F_63 ( V_28 , V_29 , V_30 , V_31 ) ;
if ( V_2 ) {
F_72 ( V_2 , V_31 , V_50 ) ;
if ( ! F_73 ( V_2 ) ) {
F_30 ( V_103 ) ;
F_68 ( V_2 , V_31 ) ;
} else if ( V_31 & V_36 ) {
F_66 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_17 &= ~ V_102 ;
}
}
return V_2 ;
}
void
F_74 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 )
{
if ( F_75 ( V_28 -> V_104 ) )
return;
F_71 ( V_28 , V_29 , V_30 ,
V_35 | V_36 | V_37 ) ;
}
struct V_1 *
F_76 (
struct V_7 * V_28 ,
T_7 V_105 ,
T_4 V_85 ,
int V_31 )
{
T_2 * V_2 ;
int error ;
V_2 = F_77 ( V_28 , V_85 , V_31 ) ;
if ( ! V_2 )
return NULL ;
ASSERT ( V_2 -> V_23 == 1 ) ;
V_2 -> V_42 = V_105 ;
V_2 -> V_22 [ 0 ] . V_43 = V_105 ;
V_2 -> V_17 |= V_102 ;
F_78 ( V_28 -> V_88 , V_2 ) ;
error = F_70 ( V_2 ) ;
if ( error ) {
F_66 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void
F_79 (
struct V_1 * V_2 ,
T_4 V_85 )
{
if ( V_2 -> V_52 )
F_34 ( V_2 ) ;
V_2 -> V_52 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_44 = V_85 ;
V_2 -> V_46 = V_85 ;
ASSERT ( V_2 -> V_23 == 1 ) ;
V_2 -> V_42 = V_101 ;
V_2 -> V_22 [ 0 ] . V_43 = V_101 ;
V_2 -> V_22 [ 0 ] . V_45 = V_2 -> V_44 ;
}
static inline struct V_55 *
F_80 (
void * V_106 )
{
if ( ( ! F_81 ( V_106 ) ) ) {
return F_43 ( V_106 ) ;
} else {
return F_82 ( V_106 ) ;
}
}
int
F_83 (
T_2 * V_2 ,
void * V_107 ,
T_4 V_108 )
{
int V_109 ;
int V_32 = 0 ;
unsigned long V_110 ;
unsigned long V_60 ;
T_4 V_111 ;
int V_51 ;
V_110 = ( unsigned long ) V_107 & V_65 ;
V_60 = ( unsigned long ) V_107 - V_110 ;
V_111 = F_84 ( V_108 + V_60 ) ;
V_51 = V_111 >> V_66 ;
if ( V_2 -> V_52 )
F_34 ( V_2 ) ;
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_107 ;
V_109 = F_32 ( V_2 , V_51 , 0 ) ;
if ( V_109 )
return V_109 ;
V_2 -> V_6 = V_60 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_4 ; V_32 ++ ) {
V_2 -> V_52 [ V_32 ] = F_80 ( ( void * ) V_110 ) ;
V_110 += V_5 ;
}
V_2 -> V_46 = F_85 ( V_108 ) ;
V_2 -> V_44 = F_85 ( V_111 ) ;
return 0 ;
}
T_2 *
F_77 (
struct V_7 * V_28 ,
T_4 V_85 ,
int V_31 )
{
unsigned long V_51 ;
int error , V_32 ;
struct V_1 * V_2 ;
F_86 ( V_29 , V_101 , V_85 ) ;
V_2 = F_20 ( V_28 , & V_29 , 1 , 0 ) ;
if ( F_22 ( V_2 == NULL ) )
goto V_112;
V_51 = F_84 ( V_85 << V_113 ) >> V_66 ;
error = F_32 ( V_2 , V_51 , 0 ) ;
if ( error )
goto V_114;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_2 -> V_52 [ V_32 ] = F_44 ( F_40 ( V_31 ) ) ;
if ( ! V_2 -> V_52 [ V_32 ] )
goto V_115;
}
V_2 -> V_17 |= V_56 ;
error = F_48 ( V_2 , 0 ) ;
if ( F_22 ( error ) ) {
F_65 ( V_28 -> V_88 ,
L_2 , V_70 ) ;
goto V_115;
}
F_87 ( V_2 , V_50 ) ;
return V_2 ;
V_115:
while ( -- V_32 >= 0 )
F_38 ( V_2 -> V_52 [ V_32 ] ) ;
F_34 ( V_2 ) ;
V_114:
F_18 ( V_2 ) ;
F_28 ( V_33 , V_2 ) ;
V_112:
return NULL ;
}
void
F_88 (
T_2 * V_2 )
{
F_89 ( V_2 , V_50 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
void
F_60 (
T_2 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_94 ;
F_90 ( V_2 , V_50 ) ;
if ( ! V_80 ) {
ASSERT ( F_5 ( & V_2 -> V_11 ) ) ;
ASSERT ( F_91 ( & V_2 -> V_40 ) ) ;
if ( F_92 ( & V_2 -> V_12 ) )
F_35 ( V_2 ) ;
return;
}
ASSERT ( ! F_91 ( & V_2 -> V_40 ) ) ;
ASSERT ( F_15 ( & V_2 -> V_12 ) > 0 ) ;
if ( F_93 ( & V_2 -> V_12 , & V_80 -> V_89 ) ) {
if ( ! ( V_2 -> V_17 & V_18 ) &&
F_15 ( & V_2 -> V_20 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_80 -> V_89 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_17 & V_19 ) ) ;
F_94 ( & V_2 -> V_40 , & V_80 -> V_90 ) ;
F_8 ( & V_80 -> V_89 ) ;
F_58 ( V_80 ) ;
F_35 ( V_2 ) ;
}
}
}
int
F_59 (
struct V_1 * V_2 )
{
int V_116 ;
V_116 = F_95 ( & V_2 -> V_41 ) == 0 ;
if ( V_116 )
F_27 ( V_2 ) ;
else if ( F_15 ( & V_2 -> V_47 ) && ( V_2 -> V_17 & V_18 ) )
F_96 ( V_2 -> V_9 -> V_88 , 0 ) ;
F_97 ( V_2 , V_50 ) ;
return V_116 ;
}
void
F_61 (
struct V_1 * V_2 )
{
F_98 ( V_2 , V_50 ) ;
if ( F_15 ( & V_2 -> V_47 ) && ( V_2 -> V_17 & V_18 ) )
F_96 ( V_2 -> V_9 -> V_88 , 0 ) ;
F_99 ( & V_2 -> V_41 ) ;
F_27 ( V_2 ) ;
F_100 ( V_2 , V_50 ) ;
}
void
F_101 (
struct V_1 * V_2 )
{
F_102 ( V_2 ) ;
F_103 ( & V_2 -> V_41 ) ;
F_104 ( V_2 , V_50 ) ;
}
STATIC void
F_105 (
T_2 * V_2 )
{
F_106 ( V_117 , V_118 ) ;
if ( F_15 ( & V_2 -> V_47 ) == 0 )
return;
F_107 ( & V_2 -> V_48 , & V_117 ) ;
for (; ; ) {
F_108 ( V_119 ) ;
if ( F_15 ( & V_2 -> V_47 ) == 0 )
break;
F_109 () ;
}
F_110 ( & V_2 -> V_48 , & V_117 ) ;
F_108 ( V_120 ) ;
}
STATIC void
F_111 (
struct V_121 * V_122 )
{
T_2 * V_2 =
F_112 ( V_122 , T_2 , V_123 ) ;
if ( V_2 -> V_124 )
( * ( V_2 -> V_124 ) ) ( V_2 ) ;
else if ( V_2 -> V_17 & V_36 )
F_66 ( V_2 ) ;
}
void
F_113 (
T_2 * V_2 ,
int V_125 )
{
F_114 ( V_2 , V_50 ) ;
V_2 -> V_17 &= ~ ( V_102 | V_100 | V_37 ) ;
if ( V_2 -> V_126 == 0 )
V_2 -> V_17 |= V_127 ;
if ( ( V_2 -> V_124 ) || ( V_2 -> V_17 & V_36 ) ) {
if ( V_125 ) {
F_115 ( & V_2 -> V_123 , F_111 ) ;
F_116 ( V_128 , & V_2 -> V_123 ) ;
} else {
F_111 ( & V_2 -> V_123 ) ;
}
} else {
F_117 ( & V_2 -> V_38 ) ;
}
}
void
F_118 (
T_2 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_126 = ( unsigned short ) error ;
F_119 ( V_2 , error , V_50 ) ;
}
void
F_120 (
struct V_1 * V_2 ,
const char * V_129 )
{
F_121 ( V_2 -> V_9 -> V_88 ,
L_3 ,
( V_130 ) F_122 ( V_2 ) , V_129 , V_2 -> V_126 , V_2 -> V_44 ) ;
}
STATIC int
F_123 (
T_2 * V_2 )
{
#ifdef F_124
ASSERT ( F_125 ( V_2 ) || V_2 -> V_124 ) ;
#endif
F_118 ( V_2 , V_131 ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
F_11 ( V_2 ) ;
F_113 ( V_2 , 0 ) ;
return V_131 ;
}
STATIC int
F_128 (
struct V_1 * V_2 )
{
T_8 V_132 = V_2 -> V_17 ;
F_126 ( V_2 ) ;
F_129 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_124 = NULL ;
if ( ! ( V_132 & V_36 ) ) {
F_118 ( V_2 , V_131 ) ;
F_117 ( & V_2 -> V_38 ) ;
} else {
F_66 ( V_2 ) ;
}
return V_131 ;
}
STATIC int
F_130 (
struct V_1 * V_2 )
{
if ( F_131 ( V_2 -> V_9 -> V_88 ) ) {
F_132 ( V_2 , V_50 ) ;
if ( ! V_2 -> V_124 && ! F_125 ( V_2 ) )
return F_128 ( V_2 ) ;
else
return F_123 ( V_2 ) ;
}
F_69 ( V_2 ) ;
return 0 ;
}
int
F_133 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_17 |= V_100 ;
V_2 -> V_17 &= ~ ( V_36 | V_102 | V_19 ) ;
F_130 ( V_2 ) ;
error = F_70 ( V_2 ) ;
if ( error ) {
F_134 ( V_2 -> V_9 -> V_88 ,
V_133 ) ;
}
return error ;
}
void
F_78 (
struct V_134 * V_135 ,
struct V_1 * V_2 )
{
if ( F_131 ( V_135 ) ) {
F_132 ( V_2 , V_50 ) ;
F_128 ( V_2 ) ;
return;
}
F_69 ( V_2 ) ;
}
STATIC void
F_135 (
T_2 * V_2 ,
int V_125 )
{
if ( F_92 ( & V_2 -> V_136 ) == 1 )
F_113 ( V_2 , V_125 ) ;
}
STATIC void
F_136 (
struct V_137 * V_137 ,
int error )
{
T_2 * V_2 = ( T_2 * ) V_137 -> V_138 ;
F_118 ( V_2 , - error ) ;
if ( ! error && F_1 ( V_2 ) && ( V_2 -> V_17 & V_102 ) )
F_137 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
F_135 ( V_2 , 1 ) ;
F_138 ( V_137 ) ;
}
static void
F_139 (
struct V_1 * V_2 ,
int V_29 ,
int * V_139 ,
int * V_140 ,
int V_141 )
{
int V_142 ;
int V_143 = V_2 -> V_4 ;
int V_144 ;
struct V_137 * V_137 ;
T_9 V_145 = V_2 -> V_22 [ V_29 ] . V_43 ;
int V_58 ;
int V_60 ;
V_143 = V_2 -> V_4 ;
V_142 = 0 ;
V_60 = * V_139 ;
while ( V_60 >= V_5 ) {
V_142 ++ ;
V_60 -= V_5 ;
}
V_58 = F_47 ( int , F_41 ( V_2 -> V_22 [ V_29 ] . V_45 ) , * V_140 ) ;
* V_140 -= V_58 ;
* V_139 += V_58 ;
V_146:
F_6 ( & V_2 -> V_136 ) ;
V_144 = V_147 >> ( V_66 - V_113 ) ;
if ( V_144 > V_143 )
V_144 = V_143 ;
V_137 = F_140 ( V_148 , V_144 ) ;
V_137 -> V_149 = V_2 -> V_9 -> V_150 ;
V_137 -> V_151 = V_145 ;
V_137 -> V_152 = F_136 ;
V_137 -> V_138 = V_2 ;
for (; V_58 && V_144 ; V_144 -- , V_142 ++ ) {
int V_153 , V_59 = V_5 - V_60 ;
if ( V_59 > V_58 )
V_59 = V_58 ;
V_153 = F_141 ( V_137 , V_2 -> V_52 [ V_142 ] , V_59 ,
V_60 ) ;
if ( V_153 < V_59 )
break;
V_60 = 0 ;
V_145 += F_85 ( V_59 ) ;
V_58 -= V_59 ;
V_143 -- ;
}
if ( F_64 ( V_137 -> V_154 ) ) {
if ( F_1 ( V_2 ) ) {
F_142 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_143 ( V_141 , V_137 ) ;
if ( V_58 )
goto V_146;
} else {
F_118 ( V_2 , V_131 ) ;
F_138 ( V_137 ) ;
}
}
STATIC void
F_144 (
struct V_1 * V_2 )
{
struct V_155 V_156 ;
int V_141 ;
int V_60 ;
int V_58 ;
int V_32 ;
if ( V_2 -> V_17 & V_100 ) {
if ( V_2 -> V_17 & V_157 )
V_141 = V_158 ;
else
V_141 = V_159 ;
if ( V_2 -> V_17 & V_160 )
V_141 |= V_161 ;
if ( V_2 -> V_17 & V_162 )
V_141 |= V_163 ;
} else if ( V_2 -> V_17 & V_37 ) {
V_141 = V_164 ;
} else {
V_141 = V_165 ;
}
V_141 |= V_166 ;
V_60 = V_2 -> V_6 ;
V_58 = F_41 ( V_2 -> V_46 ) ;
F_145 ( & V_156 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_23 ; V_32 ++ ) {
F_139 ( V_2 , V_32 , & V_60 , & V_58 , V_141 ) ;
if ( V_2 -> V_126 )
break;
if ( V_58 <= 0 )
break;
}
F_146 ( & V_156 ) ;
}
void
F_69 (
T_2 * V_2 )
{
F_147 ( V_2 , V_50 ) ;
ASSERT ( ! ( V_2 -> V_17 & V_19 ) ) ;
if ( V_2 -> V_17 & V_100 )
F_105 ( V_2 ) ;
F_88 ( V_2 ) ;
F_13 ( & V_2 -> V_136 , 1 ) ;
F_144 ( V_2 ) ;
F_135 ( V_2 , 1 ) ;
F_60 ( V_2 ) ;
}
int
F_70 (
T_2 * V_2 )
{
F_148 ( V_2 , V_50 ) ;
if ( ! V_2 -> V_126 )
F_149 ( & V_2 -> V_38 ) ;
F_150 ( V_2 , V_50 ) ;
return V_2 -> V_126 ;
}
T_10
F_151 (
T_2 * V_2 ,
T_4 V_60 )
{
struct V_55 * V_55 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_60 ;
V_60 += V_2 -> V_6 ;
V_55 = V_2 -> V_52 [ V_60 >> V_66 ] ;
return ( T_10 ) F_49 ( V_55 ) + ( V_60 & ( V_5 - 1 ) ) ;
}
void
F_152 (
T_2 * V_2 ,
T_4 V_167 ,
T_4 V_168 ,
void * V_169 ,
T_11 V_170 )
{
T_4 V_171 ;
V_171 = V_167 + V_168 ;
while ( V_167 < V_171 ) {
struct V_55 * V_55 ;
int V_142 , V_172 , V_173 ;
V_142 = ( V_167 + V_2 -> V_6 ) >> V_66 ;
V_172 = ( V_167 + V_2 -> V_6 ) & ~ V_65 ;
V_55 = V_2 -> V_52 [ V_142 ] ;
V_173 = F_47 ( T_4 , V_5 - V_172 ,
F_41 ( V_2 -> V_46 ) - V_167 ) ;
ASSERT ( ( V_173 + V_172 ) <= V_5 ) ;
switch ( V_170 ) {
case V_174 :
memset ( F_49 ( V_55 ) + V_172 , 0 , V_173 ) ;
break;
case V_175 :
memcpy ( V_169 , F_49 ( V_55 ) + V_172 , V_173 ) ;
break;
case V_176 :
memcpy ( F_49 ( V_55 ) + V_172 , V_169 , V_173 ) ;
}
V_167 += V_173 ;
V_169 += V_173 ;
}
}
void
F_153 (
struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_177:
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
V_2 = F_154 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( F_15 ( & V_2 -> V_12 ) > 1 ) {
F_8 ( & V_8 -> V_10 ) ;
F_155 ( 100 ) ;
goto V_177;
}
F_13 ( & V_2 -> V_20 , 0 ) ;
F_8 ( & V_8 -> V_10 ) ;
F_60 ( V_2 ) ;
F_4 ( & V_8 -> V_10 ) ;
}
F_8 ( & V_8 -> V_10 ) ;
}
int
F_156 (
struct V_178 * V_179 ,
struct V_180 * V_181 )
{
struct V_7 * V_8 = F_112 ( V_179 ,
struct V_7 , V_182 ) ;
struct V_1 * V_2 ;
int V_183 = V_181 -> V_183 ;
F_157 ( V_184 ) ;
if ( ! V_183 )
return V_8 -> V_14 ;
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
if ( V_183 -- <= 0 )
break;
V_2 = F_154 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( ! F_158 ( & V_2 -> V_20 , - 1 , 0 ) ) {
F_159 ( & V_2 -> V_11 , & V_8 -> V_13 ) ;
continue;
}
F_160 ( & V_2 -> V_11 , & V_184 ) ;
V_8 -> V_14 -- ;
V_2 -> V_15 |= V_16 ;
}
F_8 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_184 ) ) {
V_2 = F_154 ( & V_184 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_60 ( V_2 ) ;
}
return V_8 -> V_14 ;
}
void
F_161 (
struct V_134 * V_135 ,
struct V_7 * V_8 )
{
F_162 ( & V_8 -> V_182 ) ;
if ( V_135 -> V_185 & V_186 )
F_163 ( V_8 ) ;
F_19 ( V_8 ) ;
}
STATIC int
F_164 (
T_12 * V_8 ,
unsigned int V_187 ,
unsigned int V_188 ,
int V_189 )
{
V_8 -> V_190 = V_187 ;
V_8 -> V_86 = F_165 ( V_188 ) - 1 ;
V_8 -> V_87 = V_188 - 1 ;
if ( F_166 ( V_8 -> V_150 , V_188 ) ) {
char V_191 [ V_192 ] ;
F_167 ( V_8 -> V_150 , V_191 ) ;
F_65 ( V_8 -> V_88 ,
L_4 ,
V_188 , V_191 ) ;
return V_193 ;
}
return 0 ;
}
STATIC int
F_168 (
T_12 * V_8 ,
struct V_194 * V_195 )
{
return F_164 ( V_8 ,
V_5 , F_169 ( V_195 ) , 0 ) ;
}
int
F_170 (
T_12 * V_8 ,
unsigned int V_187 ,
unsigned int V_188 )
{
return F_164 ( V_8 , V_187 , V_188 , 1 ) ;
}
T_12 *
F_171 (
struct V_134 * V_135 ,
struct V_194 * V_195 ,
int V_196 ,
const char * V_197 )
{
T_12 * V_8 ;
V_8 = F_17 ( sizeof( * V_8 ) , V_198 ) ;
V_8 -> V_88 = V_135 ;
V_8 -> V_199 = V_195 -> V_200 ;
V_8 -> V_150 = V_195 ;
V_8 -> V_104 = F_172 ( V_195 ) ;
if ( ! V_8 -> V_104 )
goto error;
F_24 ( & V_8 -> V_13 ) ;
F_173 ( & V_8 -> V_10 ) ;
if ( F_168 ( V_8 , V_195 ) )
goto error;
V_8 -> V_182 . V_179 = F_156 ;
V_8 -> V_182 . V_201 = V_202 ;
F_174 ( & V_8 -> V_182 ) ;
return V_8 ;
error:
F_19 ( V_8 ) ;
return NULL ;
}
bool
F_175 (
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
ASSERT ( F_12 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_17 & V_102 ) ) ;
if ( V_2 -> V_17 & V_19 ) {
F_176 ( V_2 , V_50 ) ;
return false ;
}
F_177 ( V_2 , V_50 ) ;
V_2 -> V_17 |= V_19 ;
if ( F_5 ( & V_2 -> V_39 ) ) {
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_39 , V_204 ) ;
}
return true ;
}
static int
F_178 (
void * V_205 ,
struct V_203 * V_206 ,
struct V_203 * V_207 )
{
struct V_1 * V_208 = F_112 ( V_206 , struct V_1 , V_39 ) ;
struct V_1 * V_2 = F_112 ( V_207 , struct V_1 , V_39 ) ;
T_7 V_209 ;
V_209 = V_208 -> V_24 . V_43 - V_2 -> V_24 . V_43 ;
if ( V_209 < 0 )
return - 1 ;
if ( V_209 > 0 )
return 1 ;
return 0 ;
}
static int
F_179 (
struct V_203 * V_210 ,
struct V_203 * V_211 ,
bool V_117 )
{
struct V_155 V_156 ;
struct V_1 * V_2 , * V_212 ;
int V_213 = 0 ;
F_180 (bp, n, buffer_list, b_list) {
if ( ! V_117 ) {
if ( F_181 ( V_2 ) ) {
V_213 ++ ;
continue;
}
if ( ! F_59 ( V_2 ) )
continue;
} else {
F_61 ( V_2 ) ;
}
if ( ! ( V_2 -> V_17 & V_19 ) ) {
F_10 ( & V_2 -> V_39 ) ;
F_66 ( V_2 ) ;
continue;
}
F_159 ( & V_2 -> V_39 , V_211 ) ;
F_182 ( V_2 , V_50 ) ;
}
F_183 ( NULL , V_211 , F_178 ) ;
F_145 ( & V_156 ) ;
F_180 (bp, n, io_list, b_list) {
V_2 -> V_17 &= ~ ( V_19 | V_36 ) ;
V_2 -> V_17 |= V_100 ;
if ( ! V_117 ) {
V_2 -> V_17 |= V_36 ;
F_10 ( & V_2 -> V_39 ) ;
}
F_130 ( V_2 ) ;
}
F_146 ( & V_156 ) ;
return V_213 ;
}
int
F_184 (
struct V_203 * V_210 )
{
F_157 ( V_211 ) ;
return F_179 ( V_210 , & V_211 , false ) ;
}
int
F_185 (
struct V_203 * V_210 )
{
F_157 ( V_211 ) ;
int error = 0 , V_214 ;
struct V_1 * V_2 ;
F_179 ( V_210 , & V_211 , true ) ;
while ( ! F_5 ( & V_211 ) ) {
V_2 = F_154 ( & V_211 , struct V_1 , V_39 ) ;
F_10 ( & V_2 -> V_39 ) ;
V_214 = F_70 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( ! error )
error = V_214 ;
}
return error ;
}
int T_13
F_186 ( void )
{
V_33 = F_187 ( sizeof( T_2 ) , L_5 ,
V_215 , NULL ) ;
if ( ! V_33 )
goto V_216;
V_128 = F_188 ( L_6 ,
V_217 | V_218 , 1 ) ;
if ( ! V_128 )
goto V_219;
return 0 ;
V_219:
F_189 ( V_33 ) ;
V_216:
return - V_27 ;
}
void
F_190 ( void )
{
F_191 ( V_128 ) ;
F_189 ( V_33 ) ;
}
