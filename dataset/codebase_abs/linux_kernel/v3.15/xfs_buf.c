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
void
F_3 (
struct V_1 * V_2 )
{
ASSERT ( F_4 ( V_2 ) ) ;
V_2 -> V_7 |= V_8 ;
V_2 -> V_7 &= ~ V_9 ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_11 , 0 ) ;
if ( ! ( V_2 -> V_12 & V_13 ) &&
( F_7 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ) )
F_8 ( & V_2 -> V_17 ) ;
ASSERT ( F_9 ( & V_2 -> V_17 ) >= 1 ) ;
F_10 ( & V_2 -> V_10 ) ;
}
static int
F_11 (
struct V_1 * V_2 ,
int V_18 )
{
ASSERT ( V_2 -> V_19 == NULL ) ;
V_2 -> V_20 = V_18 ;
if ( V_18 == 1 ) {
V_2 -> V_19 = & V_2 -> V_21 ;
return 0 ;
}
V_2 -> V_19 = F_12 ( V_18 * sizeof( struct V_22 ) ,
V_23 ) ;
if ( ! V_2 -> V_19 )
return V_24 ;
return 0 ;
}
static void
F_13 (
struct V_1 * V_2 )
{
if ( V_2 -> V_19 != & V_2 -> V_21 ) {
F_14 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
}
struct V_1 *
F_15 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 )
{
struct V_1 * V_2 ;
int error ;
int V_30 ;
V_2 = F_16 ( V_31 , V_23 ) ;
if ( F_17 ( ! V_2 ) )
return NULL ;
V_29 &= ~ ( V_32 | V_33 | V_34 | V_35 ) ;
F_6 ( & V_2 -> V_17 , 1 ) ;
F_6 ( & V_2 -> V_11 , 1 ) ;
F_18 ( & V_2 -> V_36 ) ;
F_19 ( & V_2 -> V_16 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_20 ( & V_2 -> V_38 ) ;
F_21 ( & V_2 -> V_39 , 0 ) ;
F_22 ( & V_2 -> V_10 ) ;
F_23 ( V_2 ) ;
V_2 -> V_14 = V_26 ;
V_2 -> V_7 = V_29 ;
error = F_11 ( V_2 , V_28 ) ;
if ( error ) {
F_24 ( V_31 , V_2 ) ;
return NULL ;
}
V_2 -> V_40 = V_27 [ 0 ] . V_41 ;
V_2 -> V_42 = 0 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_2 -> V_19 [ V_30 ] . V_41 = V_27 [ V_30 ] . V_41 ;
V_2 -> V_19 [ V_30 ] . V_43 = V_27 [ V_30 ] . V_43 ;
V_2 -> V_42 += V_27 [ V_30 ] . V_43 ;
}
V_2 -> V_44 = V_2 -> V_42 ;
F_6 ( & V_2 -> V_45 , 0 ) ;
F_25 ( & V_2 -> V_46 ) ;
F_26 ( V_47 ) ;
F_27 ( V_2 , V_48 ) ;
return V_2 ;
}
STATIC int
F_28 (
T_2 * V_2 ,
int V_49 ,
T_1 V_29 )
{
if ( V_2 -> V_50 == NULL ) {
V_2 -> V_4 = V_49 ;
if ( V_49 <= V_51 ) {
V_2 -> V_50 = V_2 -> V_52 ;
} else {
V_2 -> V_50 = F_29 ( sizeof( struct V_53 * ) *
V_49 , V_23 ) ;
if ( V_2 -> V_50 == NULL )
return - V_24 ;
}
memset ( V_2 -> V_50 , 0 , sizeof( struct V_53 * ) * V_49 ) ;
}
return 0 ;
}
STATIC void
F_30 (
T_2 * V_2 )
{
if ( V_2 -> V_50 != V_2 -> V_52 ) {
F_14 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
}
}
void
F_31 (
T_2 * V_2 )
{
F_32 ( V_2 , V_48 ) ;
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
if ( V_2 -> V_7 & V_54 ) {
T_3 V_30 ;
if ( F_1 ( V_2 ) )
F_34 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
struct V_53 * V_53 = V_2 -> V_50 [ V_30 ] ;
F_35 ( V_53 ) ;
}
} else if ( V_2 -> V_7 & V_55 )
F_14 ( V_2 -> V_3 ) ;
F_30 ( V_2 ) ;
F_13 ( V_2 ) ;
F_24 ( V_31 , V_2 ) ;
}
STATIC int
F_36 (
T_2 * V_2 ,
T_3 V_29 )
{
T_4 V_56 ;
T_4 V_57 , V_58 ;
T_5 V_59 = F_37 ( V_29 ) ;
unsigned short V_49 , V_30 ;
T_6 V_60 , V_61 ;
int error ;
V_56 = F_38 ( V_2 -> V_42 ) ;
if ( V_56 < V_5 ) {
V_2 -> V_3 = F_29 ( V_56 , V_23 ) ;
if ( ! V_2 -> V_3 ) {
goto V_62;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_56 - 1 ) & V_63 ) !=
( ( unsigned long ) V_2 -> V_3 & V_63 ) ) {
F_14 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_62;
}
V_2 -> V_6 = F_39 ( V_2 -> V_3 ) ;
V_2 -> V_50 = V_2 -> V_52 ;
V_2 -> V_50 [ 0 ] = F_40 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_7 |= V_55 ;
return 0 ;
}
V_62:
V_60 = F_38 ( V_2 -> V_19 [ 0 ] . V_41 ) >> V_64 ;
V_61 = ( F_38 ( V_2 -> V_19 [ 0 ] . V_41 + V_2 -> V_42 ) + V_5 - 1 )
>> V_64 ;
V_49 = V_61 - V_60 ;
error = F_28 ( V_2 , V_49 , V_29 ) ;
if ( F_17 ( error ) )
return error ;
V_58 = V_2 -> V_6 ;
V_2 -> V_7 |= V_54 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
struct V_53 * V_53 ;
T_3 V_65 = 0 ;
V_66:
V_53 = F_41 ( V_59 ) ;
if ( F_17 ( V_53 == NULL ) ) {
if ( V_29 & V_35 ) {
V_2 -> V_4 = V_30 ;
error = V_24 ;
goto V_67;
}
if ( ! ( ++ V_65 % 100 ) )
F_42 ( NULL ,
L_1 ,
V_68 , V_59 ) ;
F_26 ( V_69 ) ;
F_43 ( V_70 , V_71 / 50 ) ;
goto V_66;
}
F_26 ( V_72 ) ;
V_57 = F_44 ( T_4 , V_56 , V_5 - V_58 ) ;
V_56 -= V_57 ;
V_2 -> V_50 [ V_30 ] = V_53 ;
V_58 = 0 ;
}
return 0 ;
V_67:
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ )
F_35 ( V_2 -> V_50 [ V_30 ] ) ;
return error ;
}
STATIC int
F_45 (
T_2 * V_2 ,
T_3 V_29 )
{
ASSERT ( V_2 -> V_7 & V_54 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_46 ( V_2 -> V_50 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_29 & V_32 ) {
V_2 -> V_3 = NULL ;
} else {
int V_73 = 0 ;
unsigned V_74 ;
V_74 = F_47 () ;
do {
V_2 -> V_3 = F_48 ( V_2 -> V_50 , V_2 -> V_4 ,
- 1 , V_75 ) ;
if ( V_2 -> V_3 )
break;
F_49 () ;
} while ( V_73 ++ <= 1 );
F_50 ( V_74 ) ;
if ( ! V_2 -> V_3 )
return - V_24 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_2 *
F_51 (
struct V_25 * V_76 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
T_2 * V_77 )
{
T_4 V_78 ;
struct V_79 * V_80 ;
struct V_81 * * V_82 ;
struct V_81 * V_83 ;
T_2 * V_2 ;
T_7 V_84 = V_27 [ 0 ] . V_41 ;
T_7 V_85 ;
int V_86 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_86 += V_27 [ V_30 ] . V_43 ;
V_78 = F_38 ( V_86 ) ;
ASSERT ( ! ( V_78 < V_76 -> V_87 ) ) ;
ASSERT ( ! ( F_38 ( V_84 ) & ( T_6 ) V_76 -> V_88 ) ) ;
V_85 = F_52 ( V_76 -> V_89 , V_76 -> V_89 -> V_90 . V_91 ) ;
if ( V_84 >= V_85 ) {
F_53 ( V_76 -> V_89 ,
L_2 ,
V_68 , V_84 , V_85 ) ;
F_54 ( 1 ) ;
return NULL ;
}
V_80 = F_55 ( V_76 -> V_89 ,
F_56 ( V_76 -> V_89 , V_84 ) ) ;
F_5 ( & V_80 -> V_92 ) ;
V_82 = & V_80 -> V_93 . V_81 ;
V_83 = NULL ;
V_2 = NULL ;
while ( * V_82 ) {
V_83 = * V_82 ;
V_2 = F_57 ( V_83 , struct V_1 , V_38 ) ;
if ( V_84 < V_2 -> V_40 )
V_82 = & ( * V_82 ) -> V_94 ;
else if ( V_84 > V_2 -> V_40 )
V_82 = & ( * V_82 ) -> V_95 ;
else {
if ( V_2 -> V_42 != V_86 ) {
ASSERT ( V_2 -> V_7 & V_8 ) ;
V_82 = & ( * V_82 ) -> V_95 ;
continue;
}
F_58 ( & V_2 -> V_17 ) ;
goto V_96;
}
}
if ( V_77 ) {
F_59 ( & V_77 -> V_38 , V_83 , V_82 ) ;
F_60 ( & V_77 -> V_38 , & V_80 -> V_93 ) ;
V_77 -> V_97 = V_80 ;
F_10 ( & V_80 -> V_92 ) ;
} else {
F_26 ( V_98 ) ;
F_10 ( & V_80 -> V_92 ) ;
F_61 ( V_80 ) ;
}
return V_77 ;
V_96:
F_10 ( & V_80 -> V_92 ) ;
F_61 ( V_80 ) ;
if ( ! F_62 ( V_2 ) ) {
if ( V_29 & V_33 ) {
F_63 ( V_2 ) ;
F_26 ( V_99 ) ;
return NULL ;
}
F_64 ( V_2 ) ;
F_26 ( V_100 ) ;
}
if ( V_2 -> V_7 & V_8 ) {
ASSERT ( ( V_2 -> V_7 & V_9 ) == 0 ) ;
ASSERT ( V_2 -> V_101 == NULL ) ;
V_2 -> V_7 &= V_55 | V_54 ;
V_2 -> V_102 = NULL ;
}
F_65 ( V_2 , V_29 , V_48 ) ;
F_26 ( V_103 ) ;
return V_2 ;
}
struct V_1 *
F_66 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 )
{
struct V_1 * V_2 ;
struct V_1 * V_77 ;
int error = 0 ;
V_2 = F_51 ( V_26 , V_27 , V_28 , V_29 , NULL ) ;
if ( F_67 ( V_2 ) )
goto V_96;
V_77 = F_15 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( F_17 ( ! V_77 ) )
return NULL ;
error = F_36 ( V_77 , V_29 ) ;
if ( error ) {
F_31 ( V_77 ) ;
return NULL ;
}
V_2 = F_51 ( V_26 , V_27 , V_28 , V_29 , V_77 ) ;
if ( ! V_2 ) {
F_31 ( V_77 ) ;
return NULL ;
}
if ( V_2 != V_77 )
F_31 ( V_77 ) ;
V_96:
if ( ! V_2 -> V_3 ) {
error = F_45 ( V_2 , V_29 ) ;
if ( F_17 ( error ) ) {
F_68 ( V_26 -> V_89 ,
L_3 , V_68 ) ;
F_69 ( V_2 ) ;
return NULL ;
}
}
F_26 ( V_104 ) ;
F_70 ( V_2 , V_29 , V_48 ) ;
return V_2 ;
}
STATIC int
F_71 (
T_2 * V_2 ,
T_1 V_29 )
{
ASSERT ( ! ( V_29 & V_105 ) ) ;
ASSERT ( V_2 -> V_19 [ 0 ] . V_41 != V_106 ) ;
V_2 -> V_7 &= ~ ( V_105 | V_34 | V_35 ) ;
V_2 -> V_7 |= V_29 & ( V_107 | V_34 | V_35 ) ;
F_72 ( V_2 ) ;
if ( V_29 & V_34 )
return 0 ;
return F_73 ( V_2 ) ;
}
T_2 *
F_74 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
const struct V_108 * V_109 )
{
struct V_1 * V_2 ;
V_29 |= V_107 ;
V_2 = F_66 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( V_2 ) {
F_75 ( V_2 , V_29 , V_48 ) ;
if ( ! F_76 ( V_2 ) ) {
F_26 ( V_110 ) ;
V_2 -> V_102 = V_109 ;
F_71 ( V_2 , V_29 ) ;
} else if ( V_29 & V_34 ) {
F_69 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_7 &= ~ V_107 ;
}
}
return V_2 ;
}
void
F_77 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
const struct V_108 * V_109 )
{
if ( F_78 ( V_26 -> V_111 ) )
return;
F_74 ( V_26 , V_27 , V_28 ,
V_33 | V_34 | V_35 , V_109 ) ;
}
struct V_1 *
F_79 (
struct V_25 * V_26 ,
T_7 V_112 ,
T_4 V_86 ,
int V_29 ,
const struct V_108 * V_109 )
{
struct V_1 * V_2 ;
V_2 = F_80 ( V_26 , V_86 , V_29 ) ;
if ( ! V_2 )
return NULL ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_112 ;
V_2 -> V_19 [ 0 ] . V_41 = V_112 ;
V_2 -> V_7 |= V_107 ;
V_2 -> V_102 = V_109 ;
if ( F_81 ( V_26 -> V_89 ) ) {
F_69 ( V_2 ) ;
return NULL ;
}
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
return V_2 ;
}
void
F_82 (
struct V_1 * V_2 ,
T_4 V_86 )
{
if ( V_2 -> V_50 )
F_30 ( V_2 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_42 = V_86 ;
V_2 -> V_44 = V_86 ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_106 ;
V_2 -> V_19 [ 0 ] . V_41 = V_106 ;
V_2 -> V_19 [ 0 ] . V_43 = V_2 -> V_42 ;
}
static inline struct V_53 *
F_83 (
void * V_113 )
{
if ( ( ! F_84 ( V_113 ) ) ) {
return F_40 ( V_113 ) ;
} else {
return F_85 ( V_113 ) ;
}
}
int
F_86 (
T_2 * V_2 ,
void * V_114 ,
T_4 V_115 )
{
int V_116 ;
int V_30 = 0 ;
unsigned long V_117 ;
unsigned long V_58 ;
T_4 V_118 ;
int V_49 ;
V_117 = ( unsigned long ) V_114 & V_63 ;
V_58 = ( unsigned long ) V_114 - V_117 ;
V_118 = F_87 ( V_115 + V_58 ) ;
V_49 = V_118 >> V_64 ;
if ( V_2 -> V_50 )
F_30 ( V_2 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_3 = V_114 ;
V_116 = F_28 ( V_2 , V_49 , 0 ) ;
if ( V_116 )
return V_116 ;
V_2 -> V_6 = V_58 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
V_2 -> V_50 [ V_30 ] = F_83 ( ( void * ) V_117 ) ;
V_117 += V_5 ;
}
V_2 -> V_44 = F_88 ( V_115 ) ;
V_2 -> V_42 = F_88 ( V_118 ) ;
return 0 ;
}
T_2 *
F_80 (
struct V_25 * V_26 ,
T_4 V_86 ,
int V_29 )
{
unsigned long V_49 ;
int error , V_30 ;
struct V_1 * V_2 ;
F_89 ( V_27 , V_106 , V_86 ) ;
V_2 = F_15 ( V_26 , & V_27 , 1 , 0 ) ;
if ( F_17 ( V_2 == NULL ) )
goto V_119;
V_49 = F_87 ( V_86 << V_120 ) >> V_64 ;
error = F_28 ( V_2 , V_49 , 0 ) ;
if ( error )
goto V_121;
for ( V_30 = 0 ; V_30 < V_49 ; V_30 ++ ) {
V_2 -> V_50 [ V_30 ] = F_41 ( F_37 ( V_29 ) ) ;
if ( ! V_2 -> V_50 [ V_30 ] )
goto V_122;
}
V_2 -> V_7 |= V_54 ;
error = F_45 ( V_2 , 0 ) ;
if ( F_17 ( error ) ) {
F_68 ( V_26 -> V_89 ,
L_4 , V_68 ) ;
goto V_122;
}
F_90 ( V_2 , V_48 ) ;
return V_2 ;
V_122:
while ( -- V_30 >= 0 )
F_35 ( V_2 -> V_50 [ V_30 ] ) ;
F_30 ( V_2 ) ;
V_121:
F_13 ( V_2 ) ;
F_24 ( V_31 , V_2 ) ;
V_119:
return NULL ;
}
void
F_91 (
T_2 * V_2 )
{
F_92 ( V_2 , V_48 ) ;
F_58 ( & V_2 -> V_17 ) ;
}
void
F_63 (
T_2 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_97 ;
F_93 ( V_2 , V_48 ) ;
if ( ! V_80 ) {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
ASSERT ( F_94 ( & V_2 -> V_38 ) ) ;
if ( F_95 ( & V_2 -> V_17 ) )
F_31 ( V_2 ) ;
return;
}
ASSERT ( ! F_94 ( & V_2 -> V_38 ) ) ;
ASSERT ( F_9 ( & V_2 -> V_17 ) > 0 ) ;
if ( F_96 ( & V_2 -> V_17 , & V_80 -> V_92 ) ) {
F_5 ( & V_2 -> V_10 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) && F_9 ( & V_2 -> V_11 ) ) {
if ( F_97 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ) {
V_2 -> V_12 &= ~ V_13 ;
F_58 ( & V_2 -> V_17 ) ;
}
F_10 ( & V_2 -> V_10 ) ;
F_10 ( & V_80 -> V_92 ) ;
} else {
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_7 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ;
} else {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
}
F_10 ( & V_2 -> V_10 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
F_98 ( & V_2 -> V_38 , & V_80 -> V_93 ) ;
F_10 ( & V_80 -> V_92 ) ;
F_61 ( V_80 ) ;
F_31 ( V_2 ) ;
}
}
}
int
F_62 (
struct V_1 * V_2 )
{
int V_123 ;
V_123 = F_99 ( & V_2 -> V_39 ) == 0 ;
if ( V_123 )
F_23 ( V_2 ) ;
F_100 ( V_2 , V_48 ) ;
return V_123 ;
}
void
F_64 (
struct V_1 * V_2 )
{
F_101 ( V_2 , V_48 ) ;
if ( F_9 ( & V_2 -> V_45 ) && ( V_2 -> V_7 & V_8 ) )
F_102 ( V_2 -> V_14 -> V_89 , 0 ) ;
F_103 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
F_104 ( V_2 , V_48 ) ;
}
void
F_105 (
struct V_1 * V_2 )
{
F_106 ( V_2 ) ;
F_107 ( & V_2 -> V_39 ) ;
F_108 ( V_2 , V_48 ) ;
}
STATIC void
F_109 (
T_2 * V_2 )
{
F_110 ( V_124 , V_125 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
return;
F_111 ( & V_2 -> V_46 , & V_124 ) ;
for (; ; ) {
F_112 ( V_126 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
break;
F_113 () ;
}
F_114 ( & V_2 -> V_46 , & V_124 ) ;
F_112 ( V_127 ) ;
}
STATIC void
F_115 (
struct V_128 * V_129 )
{
struct V_1 * V_2 =
F_116 ( V_129 , T_2 , V_130 ) ;
bool V_131 = ! ! ( V_2 -> V_7 & V_107 ) ;
V_2 -> V_7 &= ~ ( V_107 | V_105 | V_35 ) ;
if ( V_131 && V_2 -> V_102 && ! V_2 -> V_132 && ( V_2 -> V_7 & V_133 ) )
V_2 -> V_102 -> V_134 ( V_2 ) ;
if ( V_2 -> V_101 )
( * ( V_2 -> V_101 ) ) ( V_2 ) ;
else if ( V_2 -> V_7 & V_34 )
F_69 ( V_2 ) ;
else {
ASSERT ( V_131 && V_2 -> V_102 ) ;
F_117 ( & V_2 -> V_36 ) ;
}
}
void
F_118 (
struct V_1 * V_2 ,
int V_135 )
{
bool V_131 = ! ! ( V_2 -> V_7 & V_107 ) ;
F_119 ( V_2 , V_48 ) ;
if ( V_2 -> V_132 == 0 )
V_2 -> V_7 |= V_133 ;
if ( V_2 -> V_101 || ( V_131 && V_2 -> V_102 ) || ( V_2 -> V_7 & V_34 ) ) {
if ( V_135 ) {
F_120 ( & V_2 -> V_130 , F_115 ) ;
F_121 ( V_136 , & V_2 -> V_130 ) ;
} else {
F_115 ( & V_2 -> V_130 ) ;
}
} else {
V_2 -> V_7 &= ~ ( V_107 | V_105 | V_35 ) ;
F_117 ( & V_2 -> V_36 ) ;
}
}
void
F_122 (
T_2 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_132 = ( unsigned short ) error ;
F_123 ( V_2 , error , V_48 ) ;
}
void
F_124 (
struct V_1 * V_2 ,
const char * V_137 )
{
F_53 ( V_2 -> V_14 -> V_89 ,
L_5 ,
( V_138 ) F_125 ( V_2 ) , V_137 , V_2 -> V_132 , V_2 -> V_42 ) ;
}
STATIC int
F_126 (
T_2 * V_2 )
{
#ifdef F_127
ASSERT ( F_128 ( V_2 ) || V_2 -> V_101 ) ;
#endif
F_122 ( V_2 , V_139 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_3 ( V_2 ) ;
F_118 ( V_2 , 0 ) ;
return V_139 ;
}
int
F_131 (
struct V_1 * V_2 )
{
T_8 V_140 = V_2 -> V_7 ;
F_129 ( V_2 ) ;
F_132 ( V_2 ) ;
F_3 ( V_2 ) ;
V_2 -> V_101 = NULL ;
if ( ! ( V_140 & V_34 ) ) {
F_122 ( V_2 , V_139 ) ;
F_117 ( & V_2 -> V_36 ) ;
} else {
F_69 ( V_2 ) ;
}
return V_139 ;
}
STATIC int
F_133 (
struct V_1 * V_2 )
{
if ( F_81 ( V_2 -> V_14 -> V_89 ) ) {
F_134 ( V_2 , V_48 ) ;
if ( ! V_2 -> V_101 && ! F_128 ( V_2 ) )
return F_131 ( V_2 ) ;
else
return F_126 ( V_2 ) ;
}
F_72 ( V_2 ) ;
return 0 ;
}
int
F_135 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_4 ( V_2 ) ) ;
V_2 -> V_7 |= V_105 ;
V_2 -> V_7 &= ~ ( V_34 | V_107 | V_9 | V_141 ) ;
F_133 ( V_2 ) ;
error = F_73 ( V_2 ) ;
if ( error ) {
F_136 ( V_2 -> V_14 -> V_89 ,
V_142 ) ;
}
return error ;
}
STATIC void
F_137 (
T_2 * V_2 ,
int V_135 )
{
if ( F_95 ( & V_2 -> V_143 ) == 1 )
F_118 ( V_2 , V_135 ) ;
}
STATIC void
F_138 (
struct V_144 * V_144 ,
int error )
{
T_2 * V_2 = ( T_2 * ) V_144 -> V_145 ;
if ( ! V_2 -> V_132 )
F_122 ( V_2 , - error ) ;
if ( ! V_2 -> V_132 && F_1 ( V_2 ) && ( V_2 -> V_7 & V_107 ) )
F_139 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
F_137 ( V_2 , 1 ) ;
F_140 ( V_144 ) ;
}
static void
F_141 (
struct V_1 * V_2 ,
int V_27 ,
int * V_146 ,
int * V_147 ,
int V_148 )
{
int V_149 ;
int V_150 = V_2 -> V_4 ;
int V_151 ;
struct V_144 * V_144 ;
T_9 V_152 = V_2 -> V_19 [ V_27 ] . V_41 ;
int V_56 ;
int V_58 ;
V_150 = V_2 -> V_4 ;
V_149 = 0 ;
V_58 = * V_146 ;
while ( V_58 >= V_5 ) {
V_149 ++ ;
V_58 -= V_5 ;
}
V_56 = F_44 ( int , F_38 ( V_2 -> V_19 [ V_27 ] . V_43 ) , * V_147 ) ;
* V_147 -= V_56 ;
* V_146 += V_56 ;
V_153:
F_58 ( & V_2 -> V_143 ) ;
V_151 = V_154 >> ( V_64 - V_120 ) ;
if ( V_151 > V_150 )
V_151 = V_150 ;
V_144 = F_142 ( V_155 , V_151 ) ;
V_144 -> V_156 = V_2 -> V_14 -> V_157 ;
V_144 -> V_158 . V_159 = V_152 ;
V_144 -> V_160 = F_138 ;
V_144 -> V_145 = V_2 ;
for (; V_56 && V_151 ; V_151 -- , V_149 ++ ) {
int V_161 , V_57 = V_5 - V_58 ;
if ( V_57 > V_56 )
V_57 = V_56 ;
V_161 = F_143 ( V_144 , V_2 -> V_50 [ V_149 ] , V_57 ,
V_58 ) ;
if ( V_161 < V_57 )
break;
V_58 = 0 ;
V_152 += F_88 ( V_57 ) ;
V_56 -= V_57 ;
V_150 -- ;
}
if ( F_67 ( V_144 -> V_158 . V_162 ) ) {
if ( F_1 ( V_2 ) ) {
F_144 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_145 ( V_148 , V_144 ) ;
if ( V_56 )
goto V_153;
} else {
F_8 ( & V_2 -> V_143 ) ;
F_122 ( V_2 , V_139 ) ;
F_140 ( V_144 ) ;
}
}
STATIC void
F_146 (
struct V_1 * V_2 )
{
struct V_163 V_164 ;
int V_148 ;
int V_58 ;
int V_56 ;
int V_30 ;
V_2 -> V_132 = 0 ;
if ( V_2 -> V_7 & V_105 ) {
if ( V_2 -> V_7 & V_165 )
V_148 = V_166 ;
else
V_148 = V_167 ;
if ( V_2 -> V_7 & V_168 )
V_148 |= V_169 ;
if ( V_2 -> V_7 & V_170 )
V_148 |= V_171 ;
if ( V_2 -> V_102 ) {
V_2 -> V_102 -> V_172 ( V_2 ) ;
if ( V_2 -> V_132 ) {
F_136 ( V_2 -> V_14 -> V_89 ,
V_173 ) ;
return;
}
}
} else if ( V_2 -> V_7 & V_35 ) {
V_148 = V_174 ;
} else {
V_148 = V_175 ;
}
V_148 |= V_176 ;
V_58 = V_2 -> V_6 ;
V_56 = F_38 ( V_2 -> V_44 ) ;
F_147 ( & V_164 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_20 ; V_30 ++ ) {
F_141 ( V_2 , V_30 , & V_58 , & V_56 , V_148 ) ;
if ( V_2 -> V_132 )
break;
if ( V_56 <= 0 )
break;
}
F_148 ( & V_164 ) ;
}
void
F_72 (
T_2 * V_2 )
{
F_149 ( V_2 , V_48 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
if ( V_2 -> V_7 & V_105 )
F_109 ( V_2 ) ;
F_91 ( V_2 ) ;
F_6 ( & V_2 -> V_143 , 1 ) ;
F_146 ( V_2 ) ;
F_137 ( V_2 , V_2 -> V_132 ? 0 : 1 ) ;
F_63 ( V_2 ) ;
}
int
F_73 (
T_2 * V_2 )
{
F_150 ( V_2 , V_48 ) ;
if ( ! V_2 -> V_132 )
F_151 ( & V_2 -> V_36 ) ;
F_152 ( V_2 , V_48 ) ;
return V_2 -> V_132 ;
}
T_10
F_153 (
T_2 * V_2 ,
T_4 V_58 )
{
struct V_53 * V_53 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_58 ;
V_58 += V_2 -> V_6 ;
V_53 = V_2 -> V_50 [ V_58 >> V_64 ] ;
return ( T_10 ) F_46 ( V_53 ) + ( V_58 & ( V_5 - 1 ) ) ;
}
void
F_154 (
T_2 * V_2 ,
T_4 V_177 ,
T_4 V_178 ,
void * V_179 ,
T_11 V_180 )
{
T_4 V_181 ;
V_181 = V_177 + V_178 ;
while ( V_177 < V_181 ) {
struct V_53 * V_53 ;
int V_149 , V_182 , V_183 ;
V_149 = ( V_177 + V_2 -> V_6 ) >> V_64 ;
V_182 = ( V_177 + V_2 -> V_6 ) & ~ V_63 ;
V_53 = V_2 -> V_50 [ V_149 ] ;
V_183 = F_44 ( T_4 , V_5 - V_182 ,
F_38 ( V_2 -> V_44 ) - V_177 ) ;
ASSERT ( ( V_183 + V_182 ) <= V_5 ) ;
switch ( V_180 ) {
case V_184 :
memset ( F_46 ( V_53 ) + V_182 , 0 , V_183 ) ;
break;
case V_185 :
memcpy ( V_179 , F_46 ( V_53 ) + V_182 , V_183 ) ;
break;
case V_186 :
memcpy ( F_46 ( V_53 ) + V_182 , V_179 , V_183 ) ;
}
V_177 += V_183 ;
V_179 += V_183 ;
}
}
static enum V_187
F_155 (
struct V_188 * V_189 ,
T_12 * V_190 ,
void * V_191 )
{
struct V_1 * V_2 = F_116 ( V_189 , struct V_1 , V_16 ) ;
struct V_188 * V_192 = V_191 ;
if ( F_9 ( & V_2 -> V_17 ) > 1 ) {
F_156 ( V_2 , V_48 ) ;
return V_193 ;
}
if ( ! F_157 ( & V_2 -> V_10 ) )
return V_193 ;
F_6 ( & V_2 -> V_11 , 0 ) ;
V_2 -> V_12 |= V_13 ;
F_158 ( V_189 , V_192 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_194 ;
}
void
F_159 (
struct V_25 * V_76 )
{
F_160 ( V_192 ) ;
int V_195 = 0 ;
while ( F_161 ( & V_76 -> V_15 ) ) {
F_162 ( & V_76 -> V_15 , F_155 ,
& V_192 , V_196 ) ;
while ( ! F_33 ( & V_192 ) ) {
struct V_1 * V_2 ;
V_2 = F_163 ( & V_192 , struct V_1 , V_16 ) ;
F_164 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_7 & V_141 ) {
F_53 ( V_76 -> V_89 ,
L_6
L_7 ,
( long long ) V_2 -> V_40 ) ;
}
F_63 ( V_2 ) ;
}
if ( V_195 ++ != 0 )
F_165 ( 100 ) ;
}
}
static enum V_187
F_166 (
struct V_188 * V_189 ,
T_12 * V_190 ,
void * V_191 )
{
struct V_1 * V_2 = F_116 ( V_189 , struct V_1 , V_16 ) ;
struct V_188 * V_192 = V_191 ;
if ( ! F_157 ( & V_2 -> V_10 ) )
return V_193 ;
if ( ! F_167 ( & V_2 -> V_11 , - 1 , 0 ) ) {
F_10 ( & V_2 -> V_10 ) ;
return V_197 ;
}
V_2 -> V_12 |= V_13 ;
F_158 ( V_189 , V_192 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_194 ;
}
static unsigned long
F_168 (
struct V_198 * V_199 ,
struct V_200 * V_201 )
{
struct V_25 * V_76 = F_116 ( V_199 ,
struct V_25 , V_202 ) ;
F_160 ( V_192 ) ;
unsigned long V_203 ;
unsigned long V_204 = V_201 -> V_204 ;
V_203 = F_169 ( & V_76 -> V_15 , V_201 -> V_205 , F_166 ,
& V_192 , & V_204 ) ;
while ( ! F_33 ( & V_192 ) ) {
struct V_1 * V_2 ;
V_2 = F_163 ( & V_192 , struct V_1 , V_16 ) ;
F_164 ( & V_2 -> V_16 ) ;
F_63 ( V_2 ) ;
}
return V_203 ;
}
static unsigned long
F_170 (
struct V_198 * V_199 ,
struct V_200 * V_201 )
{
struct V_25 * V_76 = F_116 ( V_199 ,
struct V_25 , V_202 ) ;
return F_171 ( & V_76 -> V_15 , V_201 -> V_205 ) ;
}
void
F_172 (
struct V_206 * V_207 ,
struct V_25 * V_76 )
{
F_173 ( & V_76 -> V_202 ) ;
F_174 ( & V_76 -> V_15 ) ;
if ( V_207 -> V_208 & V_209 )
F_175 ( V_76 ) ;
F_14 ( V_76 ) ;
}
int
F_176 (
T_13 * V_76 ,
unsigned int V_210 ,
unsigned int V_211 )
{
V_76 -> V_87 = V_211 ;
V_76 -> V_88 = V_211 - 1 ;
if ( F_177 ( V_76 -> V_157 , V_211 ) ) {
char V_212 [ V_213 ] ;
F_178 ( V_76 -> V_157 , V_212 ) ;
F_68 ( V_76 -> V_89 ,
L_8 ,
V_211 , V_212 ) ;
return V_214 ;
}
V_76 -> V_215 = F_179 ( V_76 -> V_157 ) ;
V_76 -> V_216 = F_179 ( V_76 -> V_157 ) - 1 ;
return 0 ;
}
STATIC int
F_180 (
T_13 * V_76 ,
struct V_217 * V_218 )
{
return F_176 ( V_76 , V_5 ,
F_179 ( V_218 ) ) ;
}
T_13 *
F_181 (
struct V_206 * V_207 ,
struct V_217 * V_218 ,
int V_219 ,
const char * V_220 )
{
T_13 * V_76 ;
V_76 = F_12 ( sizeof( * V_76 ) , V_221 | V_23 ) ;
V_76 -> V_89 = V_207 ;
V_76 -> V_222 = V_218 -> V_223 ;
V_76 -> V_157 = V_218 ;
V_76 -> V_111 = F_182 ( V_218 ) ;
if ( ! V_76 -> V_111 )
goto error;
if ( F_180 ( V_76 , V_218 ) )
goto error;
if ( F_183 ( & V_76 -> V_15 ) )
goto error;
V_76 -> V_202 . V_224 = F_170 ;
V_76 -> V_202 . V_225 = F_168 ;
V_76 -> V_202 . V_226 = V_227 ;
V_76 -> V_202 . V_29 = V_228 ;
F_184 ( & V_76 -> V_202 ) ;
return V_76 ;
error:
F_14 ( V_76 ) ;
return NULL ;
}
bool
F_185 (
struct V_1 * V_2 ,
struct V_188 * V_229 )
{
ASSERT ( F_4 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_7 & V_107 ) ) ;
if ( V_2 -> V_7 & V_9 ) {
F_186 ( V_2 , V_48 ) ;
return false ;
}
F_187 ( V_2 , V_48 ) ;
V_2 -> V_7 |= V_9 ;
if ( F_33 ( & V_2 -> V_37 ) ) {
F_58 ( & V_2 -> V_17 ) ;
F_188 ( & V_2 -> V_37 , V_229 ) ;
}
return true ;
}
static int
F_189 (
void * V_230 ,
struct V_188 * V_231 ,
struct V_188 * V_232 )
{
struct V_1 * V_233 = F_116 ( V_231 , struct V_1 , V_37 ) ;
struct V_1 * V_2 = F_116 ( V_232 , struct V_1 , V_37 ) ;
T_7 V_234 ;
V_234 = V_233 -> V_19 [ 0 ] . V_41 - V_2 -> V_19 [ 0 ] . V_41 ;
if ( V_234 < 0 )
return - 1 ;
if ( V_234 > 0 )
return 1 ;
return 0 ;
}
static int
F_190 (
struct V_188 * V_235 ,
struct V_188 * V_236 ,
bool V_124 )
{
struct V_163 V_164 ;
struct V_1 * V_2 , * V_237 ;
int V_238 = 0 ;
F_191 (bp, n, buffer_list, b_list) {
if ( ! V_124 ) {
if ( F_192 ( V_2 ) ) {
V_238 ++ ;
continue;
}
if ( ! F_62 ( V_2 ) )
continue;
} else {
F_64 ( V_2 ) ;
}
if ( ! ( V_2 -> V_7 & V_9 ) ) {
F_164 ( & V_2 -> V_37 ) ;
F_69 ( V_2 ) ;
continue;
}
F_193 ( & V_2 -> V_37 , V_236 ) ;
F_194 ( V_2 , V_48 ) ;
}
F_195 ( NULL , V_236 , F_189 ) ;
F_147 ( & V_164 ) ;
F_191 (bp, n, io_list, b_list) {
V_2 -> V_7 &= ~ ( V_9 | V_34 | V_141 ) ;
V_2 -> V_7 |= V_105 ;
if ( ! V_124 ) {
V_2 -> V_7 |= V_34 ;
F_164 ( & V_2 -> V_37 ) ;
}
F_133 ( V_2 ) ;
}
F_148 ( & V_164 ) ;
return V_238 ;
}
int
F_196 (
struct V_188 * V_235 )
{
F_160 ( V_236 ) ;
return F_190 ( V_235 , & V_236 , false ) ;
}
int
F_197 (
struct V_188 * V_235 )
{
F_160 ( V_236 ) ;
int error = 0 , V_239 ;
struct V_1 * V_2 ;
F_190 ( V_235 , & V_236 , true ) ;
while ( ! F_33 ( & V_236 ) ) {
V_2 = F_163 ( & V_236 , struct V_1 , V_37 ) ;
F_164 ( & V_2 -> V_37 ) ;
V_239 = F_73 ( V_2 ) ;
F_69 ( V_2 ) ;
if ( ! error )
error = V_239 ;
}
return error ;
}
int T_14
F_198 ( void )
{
V_31 = F_199 ( sizeof( T_2 ) , L_9 ,
V_240 , NULL ) ;
if ( ! V_31 )
goto V_241;
V_136 = F_200 ( L_10 ,
V_242 | V_243 , 1 ) ;
if ( ! V_136 )
goto V_244;
return 0 ;
V_244:
F_201 ( V_31 ) ;
V_241:
return - V_24 ;
}
void
F_202 ( void )
{
F_203 ( V_136 ) ;
F_201 ( V_31 ) ;
}
