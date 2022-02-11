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
V_62 = F_41 ( V_2 -> V_22 [ 0 ] . V_43 ) >> V_66 ;
V_63 = ( F_41 ( V_2 -> V_22 [ 0 ] . V_43 + V_2 -> V_44 ) + V_5 - 1 )
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
T_7 V_85 ;
int V_86 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ )
V_86 += V_29 [ V_32 ] . V_45 ;
V_78 = F_41 ( V_86 ) ;
ASSERT ( ! ( V_78 < ( 1 << V_8 -> V_87 ) ) ) ;
ASSERT ( ! ( F_41 ( V_84 ) & ( T_6 ) V_8 -> V_88 ) ) ;
V_85 = F_53 ( V_8 -> V_89 , V_8 -> V_89 -> V_90 . V_91 ) ;
if ( V_84 >= V_85 ) {
F_54 ( V_8 -> V_89 ,
L_2 ,
V_70 , V_84 , V_85 ) ;
return NULL ;
}
V_80 = F_55 ( V_8 -> V_89 ,
F_56 ( V_8 -> V_89 , V_84 ) ) ;
F_4 ( & V_80 -> V_92 ) ;
V_82 = & V_80 -> V_93 . V_81 ;
V_83 = NULL ;
V_2 = NULL ;
while ( * V_82 ) {
V_83 = * V_82 ;
V_2 = F_57 ( V_83 , struct V_1 , V_40 ) ;
if ( V_84 < V_2 -> V_42 )
V_82 = & ( * V_82 ) -> V_94 ;
else if ( V_84 > V_2 -> V_42 )
V_82 = & ( * V_82 ) -> V_95 ;
else {
if ( V_2 -> V_44 != V_86 ) {
ASSERT ( V_2 -> V_17 & V_18 ) ;
V_82 = & ( * V_82 ) -> V_95 ;
continue;
}
F_6 ( & V_2 -> V_12 ) ;
goto V_96;
}
}
if ( V_77 ) {
F_58 ( & V_77 -> V_40 , V_83 , V_82 ) ;
F_59 ( & V_77 -> V_40 , & V_80 -> V_93 ) ;
V_77 -> V_97 = V_80 ;
F_8 ( & V_80 -> V_92 ) ;
} else {
F_30 ( V_98 ) ;
F_8 ( & V_80 -> V_92 ) ;
F_60 ( V_80 ) ;
}
return V_77 ;
V_96:
F_8 ( & V_80 -> V_92 ) ;
F_60 ( V_80 ) ;
if ( ! F_61 ( V_2 ) ) {
if ( V_31 & V_35 ) {
F_62 ( V_2 ) ;
F_30 ( V_99 ) ;
return NULL ;
}
F_63 ( V_2 ) ;
F_30 ( V_100 ) ;
}
if ( V_2 -> V_17 & V_18 ) {
ASSERT ( ( V_2 -> V_17 & V_19 ) == 0 ) ;
ASSERT ( V_2 -> V_101 == NULL ) ;
V_2 -> V_17 &= V_57 | V_56 ;
V_2 -> V_102 = NULL ;
}
F_64 ( V_2 , V_31 , V_50 ) ;
F_30 ( V_103 ) ;
return V_2 ;
}
struct V_1 *
F_65 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_77 ;
int error = 0 ;
V_2 = F_52 ( V_28 , V_29 , V_30 , V_31 , NULL ) ;
if ( F_66 ( V_2 ) )
goto V_96;
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
V_96:
if ( ! V_2 -> V_3 ) {
error = F_48 ( V_2 , V_31 ) ;
if ( F_22 ( error ) ) {
F_67 ( V_28 -> V_89 ,
L_3 , V_70 ) ;
F_68 ( V_2 ) ;
return NULL ;
}
}
F_30 ( V_104 ) ;
F_69 ( V_2 , V_31 , V_50 ) ;
return V_2 ;
}
STATIC int
F_70 (
T_2 * V_2 ,
T_1 V_31 )
{
ASSERT ( ! ( V_31 & V_105 ) ) ;
ASSERT ( V_2 -> V_22 [ 0 ] . V_43 != V_106 ) ;
V_2 -> V_17 &= ~ ( V_105 | V_36 | V_37 ) ;
V_2 -> V_17 |= V_31 & ( V_107 | V_36 | V_37 ) ;
F_71 ( V_2 ) ;
if ( V_31 & V_36 )
return 0 ;
return F_72 ( V_2 ) ;
}
T_2 *
F_73 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
T_1 V_31 ,
const struct V_108 * V_109 )
{
struct V_1 * V_2 ;
V_31 |= V_107 ;
V_2 = F_65 ( V_28 , V_29 , V_30 , V_31 ) ;
if ( V_2 ) {
F_74 ( V_2 , V_31 , V_50 ) ;
if ( ! F_75 ( V_2 ) ) {
F_30 ( V_110 ) ;
V_2 -> V_102 = V_109 ;
F_70 ( V_2 , V_31 ) ;
} else if ( V_31 & V_36 ) {
F_68 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_17 &= ~ V_107 ;
}
}
return V_2 ;
}
void
F_76 (
struct V_7 * V_28 ,
struct V_25 * V_29 ,
int V_30 ,
const struct V_108 * V_109 )
{
if ( F_77 ( V_28 -> V_111 ) )
return;
F_73 ( V_28 , V_29 , V_30 ,
V_35 | V_36 | V_37 , V_109 ) ;
}
struct V_1 *
F_78 (
struct V_7 * V_28 ,
T_7 V_112 ,
T_4 V_86 ,
int V_31 ,
const struct V_108 * V_109 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_28 , V_86 , V_31 ) ;
if ( ! V_2 )
return NULL ;
ASSERT ( V_2 -> V_23 == 1 ) ;
V_2 -> V_42 = V_112 ;
V_2 -> V_22 [ 0 ] . V_43 = V_112 ;
V_2 -> V_17 |= V_107 ;
V_2 -> V_102 = V_109 ;
F_80 ( V_28 -> V_89 , V_2 ) ;
F_72 ( V_2 ) ;
return V_2 ;
}
void
F_81 (
struct V_1 * V_2 ,
T_4 V_86 )
{
if ( V_2 -> V_52 )
F_34 ( V_2 ) ;
V_2 -> V_52 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_44 = V_86 ;
V_2 -> V_46 = V_86 ;
ASSERT ( V_2 -> V_23 == 1 ) ;
V_2 -> V_42 = V_106 ;
V_2 -> V_22 [ 0 ] . V_43 = V_106 ;
V_2 -> V_22 [ 0 ] . V_45 = V_2 -> V_44 ;
}
static inline struct V_55 *
F_82 (
void * V_113 )
{
if ( ( ! F_83 ( V_113 ) ) ) {
return F_43 ( V_113 ) ;
} else {
return F_84 ( V_113 ) ;
}
}
int
F_85 (
T_2 * V_2 ,
void * V_114 ,
T_4 V_115 )
{
int V_116 ;
int V_32 = 0 ;
unsigned long V_117 ;
unsigned long V_60 ;
T_4 V_118 ;
int V_51 ;
V_117 = ( unsigned long ) V_114 & V_65 ;
V_60 = ( unsigned long ) V_114 - V_117 ;
V_118 = F_86 ( V_115 + V_60 ) ;
V_51 = V_118 >> V_66 ;
if ( V_2 -> V_52 )
F_34 ( V_2 ) ;
V_2 -> V_52 = NULL ;
V_2 -> V_3 = V_114 ;
V_116 = F_32 ( V_2 , V_51 , 0 ) ;
if ( V_116 )
return V_116 ;
V_2 -> V_6 = V_60 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_4 ; V_32 ++ ) {
V_2 -> V_52 [ V_32 ] = F_82 ( ( void * ) V_117 ) ;
V_117 += V_5 ;
}
V_2 -> V_46 = F_87 ( V_115 ) ;
V_2 -> V_44 = F_87 ( V_118 ) ;
return 0 ;
}
T_2 *
F_79 (
struct V_7 * V_28 ,
T_4 V_86 ,
int V_31 )
{
unsigned long V_51 ;
int error , V_32 ;
struct V_1 * V_2 ;
F_88 ( V_29 , V_106 , V_86 ) ;
V_2 = F_20 ( V_28 , & V_29 , 1 , 0 ) ;
if ( F_22 ( V_2 == NULL ) )
goto V_119;
V_51 = F_86 ( V_86 << V_120 ) >> V_66 ;
error = F_32 ( V_2 , V_51 , 0 ) ;
if ( error )
goto V_121;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_2 -> V_52 [ V_32 ] = F_44 ( F_40 ( V_31 ) ) ;
if ( ! V_2 -> V_52 [ V_32 ] )
goto V_122;
}
V_2 -> V_17 |= V_56 ;
error = F_48 ( V_2 , 0 ) ;
if ( F_22 ( error ) ) {
F_67 ( V_28 -> V_89 ,
L_3 , V_70 ) ;
goto V_122;
}
F_89 ( V_2 , V_50 ) ;
return V_2 ;
V_122:
while ( -- V_32 >= 0 )
F_38 ( V_2 -> V_52 [ V_32 ] ) ;
F_34 ( V_2 ) ;
V_121:
F_18 ( V_2 ) ;
F_28 ( V_33 , V_2 ) ;
V_119:
return NULL ;
}
void
F_90 (
T_2 * V_2 )
{
F_91 ( V_2 , V_50 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
void
F_62 (
T_2 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_97 ;
F_92 ( V_2 , V_50 ) ;
if ( ! V_80 ) {
ASSERT ( F_5 ( & V_2 -> V_11 ) ) ;
ASSERT ( F_93 ( & V_2 -> V_40 ) ) ;
if ( F_94 ( & V_2 -> V_12 ) )
F_35 ( V_2 ) ;
return;
}
ASSERT ( ! F_93 ( & V_2 -> V_40 ) ) ;
ASSERT ( F_15 ( & V_2 -> V_12 ) > 0 ) ;
if ( F_95 ( & V_2 -> V_12 , & V_80 -> V_92 ) ) {
if ( ! ( V_2 -> V_17 & V_18 ) &&
F_15 ( & V_2 -> V_20 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_80 -> V_92 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_17 & V_19 ) ) ;
F_96 ( & V_2 -> V_40 , & V_80 -> V_93 ) ;
F_8 ( & V_80 -> V_92 ) ;
F_60 ( V_80 ) ;
F_35 ( V_2 ) ;
}
}
}
int
F_61 (
struct V_1 * V_2 )
{
int V_123 ;
V_123 = F_97 ( & V_2 -> V_41 ) == 0 ;
if ( V_123 )
F_27 ( V_2 ) ;
F_98 ( V_2 , V_50 ) ;
return V_123 ;
}
void
F_63 (
struct V_1 * V_2 )
{
F_99 ( V_2 , V_50 ) ;
if ( F_15 ( & V_2 -> V_47 ) && ( V_2 -> V_17 & V_18 ) )
F_100 ( V_2 -> V_9 -> V_89 , 0 ) ;
F_101 ( & V_2 -> V_41 ) ;
F_27 ( V_2 ) ;
F_102 ( V_2 , V_50 ) ;
}
void
F_103 (
struct V_1 * V_2 )
{
F_104 ( V_2 ) ;
F_105 ( & V_2 -> V_41 ) ;
F_106 ( V_2 , V_50 ) ;
}
STATIC void
F_107 (
T_2 * V_2 )
{
F_108 ( V_124 , V_125 ) ;
if ( F_15 ( & V_2 -> V_47 ) == 0 )
return;
F_109 ( & V_2 -> V_48 , & V_124 ) ;
for (; ; ) {
F_110 ( V_126 ) ;
if ( F_15 ( & V_2 -> V_47 ) == 0 )
break;
F_111 () ;
}
F_112 ( & V_2 -> V_48 , & V_124 ) ;
F_110 ( V_127 ) ;
}
STATIC void
F_113 (
struct V_128 * V_129 )
{
struct V_1 * V_2 =
F_114 ( V_129 , T_2 , V_130 ) ;
bool V_131 = ! ! ( V_2 -> V_17 & V_107 ) ;
V_2 -> V_17 &= ~ ( V_107 | V_105 | V_37 ) ;
if ( V_131 && V_2 -> V_102 )
V_2 -> V_102 -> V_132 ( V_2 ) ;
if ( V_2 -> V_101 )
( * ( V_2 -> V_101 ) ) ( V_2 ) ;
else if ( V_2 -> V_17 & V_36 )
F_68 ( V_2 ) ;
else {
ASSERT ( V_131 && V_2 -> V_102 ) ;
F_115 ( & V_2 -> V_38 ) ;
}
}
void
F_116 (
struct V_1 * V_2 ,
int V_133 )
{
bool V_131 = ! ! ( V_2 -> V_17 & V_107 ) ;
F_117 ( V_2 , V_50 ) ;
if ( V_2 -> V_134 == 0 )
V_2 -> V_17 |= V_135 ;
if ( V_2 -> V_101 || ( V_131 && V_2 -> V_102 ) || ( V_2 -> V_17 & V_36 ) ) {
if ( V_133 ) {
F_118 ( & V_2 -> V_130 , F_113 ) ;
F_119 ( V_136 , & V_2 -> V_130 ) ;
} else {
F_113 ( & V_2 -> V_130 ) ;
}
} else {
V_2 -> V_17 &= ~ ( V_107 | V_105 | V_37 ) ;
F_115 ( & V_2 -> V_38 ) ;
}
}
void
F_120 (
T_2 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_134 = ( unsigned short ) error ;
F_121 ( V_2 , error , V_50 ) ;
}
void
F_122 (
struct V_1 * V_2 ,
const char * V_137 )
{
F_54 ( V_2 -> V_9 -> V_89 ,
L_4 ,
( V_138 ) F_123 ( V_2 ) , V_137 , V_2 -> V_134 , V_2 -> V_44 ) ;
}
STATIC int
F_124 (
T_2 * V_2 )
{
#ifdef F_125
ASSERT ( F_126 ( V_2 ) || V_2 -> V_101 ) ;
#endif
F_120 ( V_2 , V_139 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_11 ( V_2 ) ;
F_116 ( V_2 , 0 ) ;
return V_139 ;
}
STATIC int
F_129 (
struct V_1 * V_2 )
{
T_8 V_140 = V_2 -> V_17 ;
F_127 ( V_2 ) ;
F_130 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_101 = NULL ;
if ( ! ( V_140 & V_36 ) ) {
F_120 ( V_2 , V_139 ) ;
F_115 ( & V_2 -> V_38 ) ;
} else {
F_68 ( V_2 ) ;
}
return V_139 ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
if ( F_132 ( V_2 -> V_9 -> V_89 ) ) {
F_133 ( V_2 , V_50 ) ;
if ( ! V_2 -> V_101 && ! F_126 ( V_2 ) )
return F_129 ( V_2 ) ;
else
return F_124 ( V_2 ) ;
}
F_71 ( V_2 ) ;
return 0 ;
}
int
F_134 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_17 |= V_105 ;
V_2 -> V_17 &= ~ ( V_36 | V_107 | V_19 ) ;
F_131 ( V_2 ) ;
error = F_72 ( V_2 ) ;
if ( error ) {
F_135 ( V_2 -> V_9 -> V_89 ,
V_141 ) ;
}
return error ;
}
void
F_80 (
struct V_142 * V_143 ,
struct V_1 * V_2 )
{
if ( F_132 ( V_143 ) ) {
F_133 ( V_2 , V_50 ) ;
F_129 ( V_2 ) ;
return;
}
F_71 ( V_2 ) ;
}
STATIC void
F_136 (
T_2 * V_2 ,
int V_133 )
{
if ( F_94 ( & V_2 -> V_144 ) == 1 )
F_116 ( V_2 , V_133 ) ;
}
STATIC void
F_137 (
struct V_145 * V_145 ,
int error )
{
T_2 * V_2 = ( T_2 * ) V_145 -> V_146 ;
if ( ! V_2 -> V_134 )
F_120 ( V_2 , - error ) ;
if ( ! V_2 -> V_134 && F_1 ( V_2 ) && ( V_2 -> V_17 & V_107 ) )
F_138 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
F_136 ( V_2 , 1 ) ;
F_139 ( V_145 ) ;
}
static void
F_140 (
struct V_1 * V_2 ,
int V_29 ,
int * V_147 ,
int * V_148 ,
int V_149 )
{
int V_150 ;
int V_151 = V_2 -> V_4 ;
int V_152 ;
struct V_145 * V_145 ;
T_9 V_153 = V_2 -> V_22 [ V_29 ] . V_43 ;
int V_58 ;
int V_60 ;
V_151 = V_2 -> V_4 ;
V_150 = 0 ;
V_60 = * V_147 ;
while ( V_60 >= V_5 ) {
V_150 ++ ;
V_60 -= V_5 ;
}
V_58 = F_47 ( int , F_41 ( V_2 -> V_22 [ V_29 ] . V_45 ) , * V_148 ) ;
* V_148 -= V_58 ;
* V_147 += V_58 ;
V_154:
F_6 ( & V_2 -> V_144 ) ;
V_152 = V_155 >> ( V_66 - V_120 ) ;
if ( V_152 > V_151 )
V_152 = V_151 ;
V_145 = F_141 ( V_156 , V_152 ) ;
V_145 -> V_157 = V_2 -> V_9 -> V_158 ;
V_145 -> V_159 = V_153 ;
V_145 -> V_160 = F_137 ;
V_145 -> V_146 = V_2 ;
for (; V_58 && V_152 ; V_152 -- , V_150 ++ ) {
int V_161 , V_59 = V_5 - V_60 ;
if ( V_59 > V_58 )
V_59 = V_58 ;
V_161 = F_142 ( V_145 , V_2 -> V_52 [ V_150 ] , V_59 ,
V_60 ) ;
if ( V_161 < V_59 )
break;
V_60 = 0 ;
V_153 += F_87 ( V_59 ) ;
V_58 -= V_59 ;
V_151 -- ;
}
if ( F_66 ( V_145 -> V_162 ) ) {
if ( F_1 ( V_2 ) ) {
F_143 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_144 ( V_149 , V_145 ) ;
if ( V_58 )
goto V_154;
} else {
F_14 ( & V_2 -> V_144 ) ;
F_120 ( V_2 , V_139 ) ;
F_139 ( V_145 ) ;
}
}
STATIC void
F_145 (
struct V_1 * V_2 )
{
struct V_163 V_164 ;
int V_149 ;
int V_60 ;
int V_58 ;
int V_32 ;
V_2 -> V_134 = 0 ;
if ( V_2 -> V_17 & V_105 ) {
if ( V_2 -> V_17 & V_165 )
V_149 = V_166 ;
else
V_149 = V_167 ;
if ( V_2 -> V_17 & V_168 )
V_149 |= V_169 ;
if ( V_2 -> V_17 & V_170 )
V_149 |= V_171 ;
if ( V_2 -> V_102 ) {
V_2 -> V_102 -> V_172 ( V_2 ) ;
if ( V_2 -> V_134 ) {
F_135 ( V_2 -> V_9 -> V_89 ,
V_173 ) ;
return;
}
}
} else if ( V_2 -> V_17 & V_37 ) {
V_149 = V_174 ;
} else {
V_149 = V_175 ;
}
V_149 |= V_176 ;
V_60 = V_2 -> V_6 ;
V_58 = F_41 ( V_2 -> V_46 ) ;
F_146 ( & V_164 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_23 ; V_32 ++ ) {
F_140 ( V_2 , V_32 , & V_60 , & V_58 , V_149 ) ;
if ( V_2 -> V_134 )
break;
if ( V_58 <= 0 )
break;
}
F_147 ( & V_164 ) ;
}
void
F_71 (
T_2 * V_2 )
{
F_148 ( V_2 , V_50 ) ;
ASSERT ( ! ( V_2 -> V_17 & V_19 ) ) ;
if ( V_2 -> V_17 & V_105 )
F_107 ( V_2 ) ;
F_90 ( V_2 ) ;
F_13 ( & V_2 -> V_144 , 1 ) ;
F_145 ( V_2 ) ;
F_136 ( V_2 , 1 ) ;
F_62 ( V_2 ) ;
}
int
F_72 (
T_2 * V_2 )
{
F_149 ( V_2 , V_50 ) ;
if ( ! V_2 -> V_134 )
F_150 ( & V_2 -> V_38 ) ;
F_151 ( V_2 , V_50 ) ;
return V_2 -> V_134 ;
}
T_10
F_152 (
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
F_153 (
T_2 * V_2 ,
T_4 V_177 ,
T_4 V_178 ,
void * V_179 ,
T_11 V_180 )
{
T_4 V_181 ;
V_181 = V_177 + V_178 ;
while ( V_177 < V_181 ) {
struct V_55 * V_55 ;
int V_150 , V_182 , V_183 ;
V_150 = ( V_177 + V_2 -> V_6 ) >> V_66 ;
V_182 = ( V_177 + V_2 -> V_6 ) & ~ V_65 ;
V_55 = V_2 -> V_52 [ V_150 ] ;
V_183 = F_47 ( T_4 , V_5 - V_182 ,
F_41 ( V_2 -> V_46 ) - V_177 ) ;
ASSERT ( ( V_183 + V_182 ) <= V_5 ) ;
switch ( V_180 ) {
case V_184 :
memset ( F_49 ( V_55 ) + V_182 , 0 , V_183 ) ;
break;
case V_185 :
memcpy ( V_179 , F_49 ( V_55 ) + V_182 , V_183 ) ;
break;
case V_186 :
memcpy ( F_49 ( V_55 ) + V_182 , V_179 , V_183 ) ;
}
V_177 += V_183 ;
V_179 += V_183 ;
}
}
void
F_154 (
struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_187:
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
V_2 = F_155 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( F_15 ( & V_2 -> V_12 ) > 1 ) {
F_156 ( V_2 , V_50 ) ;
F_157 ( & V_2 -> V_11 , & V_8 -> V_13 ) ;
F_8 ( & V_8 -> V_10 ) ;
F_158 ( 100 ) ;
goto V_187;
}
F_13 ( & V_2 -> V_20 , 0 ) ;
F_8 ( & V_8 -> V_10 ) ;
F_62 ( V_2 ) ;
F_4 ( & V_8 -> V_10 ) ;
}
F_8 ( & V_8 -> V_10 ) ;
}
int
F_159 (
struct V_188 * V_189 ,
struct V_190 * V_191 )
{
struct V_7 * V_8 = F_114 ( V_189 ,
struct V_7 , V_192 ) ;
struct V_1 * V_2 ;
int V_193 = V_191 -> V_193 ;
F_160 ( V_194 ) ;
if ( ! V_193 )
return V_8 -> V_14 ;
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
if ( V_193 -- <= 0 )
break;
V_2 = F_155 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( ! F_161 ( & V_2 -> V_20 , - 1 , 0 ) ) {
F_157 ( & V_2 -> V_11 , & V_8 -> V_13 ) ;
continue;
}
F_162 ( & V_2 -> V_11 , & V_194 ) ;
V_8 -> V_14 -- ;
V_2 -> V_15 |= V_16 ;
}
F_8 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_194 ) ) {
V_2 = F_155 ( & V_194 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_62 ( V_2 ) ;
}
return V_8 -> V_14 ;
}
void
F_163 (
struct V_142 * V_143 ,
struct V_7 * V_8 )
{
F_164 ( & V_8 -> V_192 ) ;
if ( V_143 -> V_195 & V_196 )
F_165 ( V_8 ) ;
F_19 ( V_8 ) ;
}
STATIC int
F_166 (
T_12 * V_8 ,
unsigned int V_197 ,
unsigned int V_198 ,
int V_199 )
{
V_8 -> V_200 = V_197 ;
V_8 -> V_87 = F_167 ( V_198 ) - 1 ;
V_8 -> V_88 = V_198 - 1 ;
if ( F_168 ( V_8 -> V_158 , V_198 ) ) {
char V_201 [ V_202 ] ;
F_169 ( V_8 -> V_158 , V_201 ) ;
F_67 ( V_8 -> V_89 ,
L_5 ,
V_198 , V_201 ) ;
return V_203 ;
}
return 0 ;
}
STATIC int
F_170 (
T_12 * V_8 ,
struct V_204 * V_205 )
{
return F_166 ( V_8 ,
V_5 , F_171 ( V_205 ) , 0 ) ;
}
int
F_172 (
T_12 * V_8 ,
unsigned int V_197 ,
unsigned int V_198 )
{
return F_166 ( V_8 , V_197 , V_198 , 1 ) ;
}
T_12 *
F_173 (
struct V_142 * V_143 ,
struct V_204 * V_205 ,
int V_206 ,
const char * V_207 )
{
T_12 * V_8 ;
V_8 = F_17 ( sizeof( * V_8 ) , V_208 ) ;
V_8 -> V_89 = V_143 ;
V_8 -> V_209 = V_205 -> V_210 ;
V_8 -> V_158 = V_205 ;
V_8 -> V_111 = F_174 ( V_205 ) ;
if ( ! V_8 -> V_111 )
goto error;
F_24 ( & V_8 -> V_13 ) ;
F_175 ( & V_8 -> V_10 ) ;
if ( F_170 ( V_8 , V_205 ) )
goto error;
V_8 -> V_192 . V_189 = F_159 ;
V_8 -> V_192 . V_211 = V_212 ;
F_176 ( & V_8 -> V_192 ) ;
return V_8 ;
error:
F_19 ( V_8 ) ;
return NULL ;
}
bool
F_177 (
struct V_1 * V_2 ,
struct V_213 * V_214 )
{
ASSERT ( F_12 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_17 & V_107 ) ) ;
if ( V_2 -> V_17 & V_19 ) {
F_178 ( V_2 , V_50 ) ;
return false ;
}
F_179 ( V_2 , V_50 ) ;
V_2 -> V_17 |= V_19 ;
if ( F_5 ( & V_2 -> V_39 ) ) {
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_39 , V_214 ) ;
}
return true ;
}
static int
F_180 (
void * V_215 ,
struct V_213 * V_216 ,
struct V_213 * V_217 )
{
struct V_1 * V_218 = F_114 ( V_216 , struct V_1 , V_39 ) ;
struct V_1 * V_2 = F_114 ( V_217 , struct V_1 , V_39 ) ;
T_7 V_219 ;
V_219 = V_218 -> V_22 [ 0 ] . V_43 - V_2 -> V_22 [ 0 ] . V_43 ;
if ( V_219 < 0 )
return - 1 ;
if ( V_219 > 0 )
return 1 ;
return 0 ;
}
static int
F_181 (
struct V_213 * V_220 ,
struct V_213 * V_221 ,
bool V_124 )
{
struct V_163 V_164 ;
struct V_1 * V_2 , * V_222 ;
int V_223 = 0 ;
F_182 (bp, n, buffer_list, b_list) {
if ( ! V_124 ) {
if ( F_183 ( V_2 ) ) {
V_223 ++ ;
continue;
}
if ( ! F_61 ( V_2 ) )
continue;
} else {
F_63 ( V_2 ) ;
}
if ( ! ( V_2 -> V_17 & V_19 ) ) {
F_10 ( & V_2 -> V_39 ) ;
F_68 ( V_2 ) ;
continue;
}
F_157 ( & V_2 -> V_39 , V_221 ) ;
F_184 ( V_2 , V_50 ) ;
}
F_185 ( NULL , V_221 , F_180 ) ;
F_146 ( & V_164 ) ;
F_182 (bp, n, io_list, b_list) {
V_2 -> V_17 &= ~ ( V_19 | V_36 ) ;
V_2 -> V_17 |= V_105 ;
if ( ! V_124 ) {
V_2 -> V_17 |= V_36 ;
F_10 ( & V_2 -> V_39 ) ;
}
F_131 ( V_2 ) ;
}
F_147 ( & V_164 ) ;
return V_223 ;
}
int
F_186 (
struct V_213 * V_220 )
{
F_160 ( V_221 ) ;
return F_181 ( V_220 , & V_221 , false ) ;
}
int
F_187 (
struct V_213 * V_220 )
{
F_160 ( V_221 ) ;
int error = 0 , V_224 ;
struct V_1 * V_2 ;
F_181 ( V_220 , & V_221 , true ) ;
while ( ! F_5 ( & V_221 ) ) {
V_2 = F_155 ( & V_221 , struct V_1 , V_39 ) ;
F_10 ( & V_2 -> V_39 ) ;
V_224 = F_72 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( ! error )
error = V_224 ;
}
return error ;
}
int T_13
F_188 ( void )
{
V_33 = F_189 ( sizeof( T_2 ) , L_6 ,
V_225 , NULL ) ;
if ( ! V_33 )
goto V_226;
V_136 = F_190 ( L_7 ,
V_227 | V_228 , 1 ) ;
if ( ! V_136 )
goto V_229;
return 0 ;
V_229:
F_191 ( V_33 ) ;
V_226:
return - V_27 ;
}
void
F_192 ( void )
{
F_193 ( V_136 ) ;
F_191 ( V_33 ) ;
}
