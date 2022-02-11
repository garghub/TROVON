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
static inline void
F_3 (
struct V_1 * V_2 )
{
if ( V_2 -> V_7 & V_8 )
return;
ASSERT ( V_2 -> V_7 & V_9 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( ! ( V_2 -> V_11 & V_12 ) ) {
V_2 -> V_11 |= V_12 ;
F_5 ( & V_2 -> V_13 -> V_14 ) ;
}
F_6 ( & V_2 -> V_10 ) ;
}
static inline void
F_7 (
struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_11 & V_12 ) {
V_2 -> V_11 &= ~ V_12 ;
F_9 ( & V_2 -> V_13 -> V_14 ) ;
}
}
static inline void
F_10 (
struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_10 ) ;
F_7 ( V_2 ) ;
F_6 ( & V_2 -> V_10 ) ;
}
void
F_11 (
struct V_1 * V_2 )
{
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_7 |= V_15 ;
V_2 -> V_7 &= ~ V_16 ;
F_4 ( & V_2 -> V_10 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_17 , 0 ) ;
if ( ! ( V_2 -> V_11 & V_18 ) &&
( F_14 ( & V_2 -> V_13 -> V_19 , & V_2 -> V_20 ) ) )
F_15 ( & V_2 -> V_21 ) ;
ASSERT ( F_16 ( & V_2 -> V_21 ) >= 1 ) ;
F_6 ( & V_2 -> V_10 ) ;
}
static int
F_17 (
struct V_1 * V_2 ,
int V_22 )
{
ASSERT ( V_2 -> V_23 == NULL ) ;
V_2 -> V_24 = V_22 ;
if ( V_22 == 1 ) {
V_2 -> V_23 = & V_2 -> V_25 ;
return 0 ;
}
V_2 -> V_23 = F_18 ( V_22 * sizeof( struct V_26 ) ,
V_27 ) ;
if ( ! V_2 -> V_23 )
return - V_28 ;
return 0 ;
}
static void
F_19 (
struct V_1 * V_2 )
{
if ( V_2 -> V_23 != & V_2 -> V_25 ) {
F_20 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
}
struct V_1 *
F_21 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 )
{
struct V_1 * V_2 ;
int error ;
int V_34 ;
V_2 = F_22 ( V_35 , V_27 ) ;
if ( F_23 ( ! V_2 ) )
return NULL ;
V_33 &= ~ ( V_36 | V_37 | V_9 | V_38 ) ;
F_13 ( & V_2 -> V_21 , 1 ) ;
F_13 ( & V_2 -> V_17 , 1 ) ;
F_24 ( & V_2 -> V_39 ) ;
F_25 ( & V_2 -> V_20 ) ;
F_25 ( & V_2 -> V_40 ) ;
F_26 ( & V_2 -> V_41 , 0 ) ;
F_27 ( & V_2 -> V_10 ) ;
F_28 ( V_2 ) ;
V_2 -> V_13 = V_30 ;
V_2 -> V_7 = V_33 ;
error = F_17 ( V_2 , V_32 ) ;
if ( error ) {
F_29 ( V_35 , V_2 ) ;
return NULL ;
}
V_2 -> V_42 = V_31 [ 0 ] . V_43 ;
V_2 -> V_44 = 0 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_2 -> V_23 [ V_34 ] . V_43 = V_31 [ V_34 ] . V_43 ;
V_2 -> V_23 [ V_34 ] . V_45 = V_31 [ V_34 ] . V_45 ;
V_2 -> V_44 += V_31 [ V_34 ] . V_45 ;
}
V_2 -> V_46 = V_2 -> V_44 ;
F_13 ( & V_2 -> V_47 , 0 ) ;
F_30 ( & V_2 -> V_48 ) ;
F_31 ( V_30 -> V_49 , V_50 ) ;
F_32 ( V_2 , V_51 ) ;
return V_2 ;
}
STATIC int
F_33 (
T_2 * V_2 ,
int V_52 )
{
if ( V_2 -> V_53 == NULL ) {
V_2 -> V_4 = V_52 ;
if ( V_52 <= V_54 ) {
V_2 -> V_53 = V_2 -> V_55 ;
} else {
V_2 -> V_53 = F_34 ( sizeof( struct V_56 * ) *
V_52 , V_27 ) ;
if ( V_2 -> V_53 == NULL )
return - V_28 ;
}
memset ( V_2 -> V_53 , 0 , sizeof( struct V_56 * ) * V_52 ) ;
}
return 0 ;
}
STATIC void
F_35 (
T_2 * V_2 )
{
if ( V_2 -> V_53 != V_2 -> V_55 ) {
F_20 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
}
void
F_36 (
T_2 * V_2 )
{
F_37 ( V_2 , V_51 ) ;
ASSERT ( F_38 ( & V_2 -> V_20 ) ) ;
if ( V_2 -> V_7 & V_57 ) {
T_3 V_34 ;
if ( F_1 ( V_2 ) )
F_39 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
struct V_56 * V_56 = V_2 -> V_53 [ V_34 ] ;
F_40 ( V_56 ) ;
}
} else if ( V_2 -> V_7 & V_58 )
F_20 ( V_2 -> V_3 ) ;
F_35 ( V_2 ) ;
F_19 ( V_2 ) ;
F_29 ( V_35 , V_2 ) ;
}
STATIC int
F_41 (
T_2 * V_2 ,
T_3 V_33 )
{
T_4 V_59 ;
T_4 V_60 , V_61 ;
T_5 V_62 = F_42 ( V_33 ) ;
unsigned short V_52 , V_34 ;
T_6 V_63 , V_64 ;
int error ;
V_59 = F_43 ( V_2 -> V_44 ) ;
if ( V_59 < V_5 ) {
V_2 -> V_3 = F_34 ( V_59 , V_27 ) ;
if ( ! V_2 -> V_3 ) {
goto V_65;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_59 - 1 ) & V_66 ) !=
( ( unsigned long ) V_2 -> V_3 & V_66 ) ) {
F_20 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_65;
}
V_2 -> V_6 = F_44 ( V_2 -> V_3 ) ;
V_2 -> V_53 = V_2 -> V_55 ;
V_2 -> V_53 [ 0 ] = F_45 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_7 |= V_58 ;
return 0 ;
}
V_65:
V_63 = F_43 ( V_2 -> V_23 [ 0 ] . V_43 ) >> V_67 ;
V_64 = ( F_43 ( V_2 -> V_23 [ 0 ] . V_43 + V_2 -> V_44 ) + V_5 - 1 )
>> V_67 ;
V_52 = V_64 - V_63 ;
error = F_33 ( V_2 , V_52 ) ;
if ( F_23 ( error ) )
return error ;
V_61 = V_2 -> V_6 ;
V_2 -> V_7 |= V_57 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
struct V_56 * V_56 ;
T_3 V_68 = 0 ;
V_69:
V_56 = F_46 ( V_62 ) ;
if ( F_23 ( V_56 == NULL ) ) {
if ( V_33 & V_38 ) {
V_2 -> V_4 = V_34 ;
error = - V_28 ;
goto V_70;
}
if ( ! ( ++ V_68 % 100 ) )
F_47 ( NULL ,
L_1 ,
V_71 -> V_72 , V_71 -> V_73 ,
V_74 , V_62 ) ;
F_31 ( V_2 -> V_13 -> V_49 , V_75 ) ;
F_48 ( V_76 , V_77 / 50 ) ;
goto V_69;
}
F_31 ( V_2 -> V_13 -> V_49 , V_78 ) ;
V_60 = F_49 ( T_4 , V_59 , V_5 - V_61 ) ;
V_59 -= V_60 ;
V_2 -> V_53 [ V_34 ] = V_56 ;
V_61 = 0 ;
}
return 0 ;
V_70:
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ )
F_40 ( V_2 -> V_53 [ V_34 ] ) ;
V_2 -> V_7 &= ~ V_57 ;
return error ;
}
STATIC int
F_50 (
T_2 * V_2 ,
T_3 V_33 )
{
ASSERT ( V_2 -> V_7 & V_57 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_51 ( V_2 -> V_53 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_33 & V_36 ) {
V_2 -> V_3 = NULL ;
} else {
int V_79 = 0 ;
unsigned V_80 ;
V_80 = F_52 () ;
do {
V_2 -> V_3 = F_53 ( V_2 -> V_53 , V_2 -> V_4 ,
- 1 , V_81 ) ;
if ( V_2 -> V_3 )
break;
F_54 () ;
} while ( V_79 ++ <= 1 );
F_55 ( V_80 ) ;
if ( ! V_2 -> V_3 )
return - V_28 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
static int
F_56 (
struct V_82 * V_83 ,
const void * V_84 )
{
const struct V_26 * V_31 = V_83 -> V_85 ;
const struct V_1 * V_2 = V_84 ;
F_57 ( F_58 ( struct V_26 , V_43 ) != 0 ) ;
if ( V_2 -> V_42 != V_31 -> V_43 )
return 1 ;
if ( F_23 ( V_2 -> V_44 != V_31 -> V_45 ) ) {
ASSERT ( V_2 -> V_7 & V_15 ) ;
return 1 ;
}
return 0 ;
}
int
F_59 (
struct V_86 * V_87 )
{
F_27 ( & V_87 -> V_88 ) ;
return F_60 ( & V_87 -> V_89 , & V_90 ) ;
}
void
F_61 (
struct V_86 * V_87 )
{
F_62 ( & V_87 -> V_89 ) ;
}
T_2 *
F_63 (
struct V_29 * V_91 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 ,
T_2 * V_92 )
{
struct V_86 * V_87 ;
T_2 * V_2 ;
struct V_26 V_93 = { . V_43 = V_31 [ 0 ] . V_43 } ;
T_7 V_94 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ )
V_93 . V_45 += V_31 [ V_34 ] . V_45 ;
ASSERT ( ! ( F_43 ( V_93 . V_45 ) < V_91 -> V_95 ) ) ;
ASSERT ( ! ( F_43 ( V_93 . V_43 ) & ( T_6 ) V_91 -> V_96 ) ) ;
V_94 = F_64 ( V_91 -> V_49 , V_91 -> V_49 -> V_97 . V_98 ) ;
if ( V_93 . V_43 < 0 || V_93 . V_43 >= V_94 ) {
F_65 ( V_91 -> V_49 ,
L_2 ,
V_74 , V_93 . V_43 , V_94 ) ;
F_66 ( 1 ) ;
return NULL ;
}
V_87 = F_67 ( V_91 -> V_49 ,
F_68 ( V_91 -> V_49 , V_93 . V_43 ) ) ;
F_4 ( & V_87 -> V_88 ) ;
V_2 = F_69 ( & V_87 -> V_89 , & V_93 ,
V_90 ) ;
if ( V_2 ) {
F_70 ( & V_2 -> V_21 ) ;
goto V_99;
}
if ( V_92 ) {
V_92 -> V_100 = V_87 ;
F_71 ( & V_87 -> V_89 ,
& V_92 -> V_101 ,
V_90 ) ;
F_6 ( & V_87 -> V_88 ) ;
} else {
F_31 ( V_91 -> V_49 , V_102 ) ;
F_6 ( & V_87 -> V_88 ) ;
F_72 ( V_87 ) ;
}
return V_92 ;
V_99:
F_6 ( & V_87 -> V_88 ) ;
F_72 ( V_87 ) ;
if ( ! F_73 ( V_2 ) ) {
if ( V_33 & V_37 ) {
F_74 ( V_2 ) ;
F_31 ( V_91 -> V_49 , V_103 ) ;
return NULL ;
}
F_75 ( V_2 ) ;
F_31 ( V_91 -> V_49 , V_104 ) ;
}
if ( V_2 -> V_7 & V_15 ) {
ASSERT ( ( V_2 -> V_7 & V_16 ) == 0 ) ;
ASSERT ( V_2 -> V_105 == NULL ) ;
V_2 -> V_7 &= V_58 | V_57 ;
V_2 -> V_106 = NULL ;
}
F_76 ( V_2 , V_33 , V_51 ) ;
F_31 ( V_91 -> V_49 , V_107 ) ;
return V_2 ;
}
struct V_1 *
F_77 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 )
{
struct V_1 * V_2 ;
struct V_1 * V_92 ;
int error = 0 ;
V_2 = F_63 ( V_30 , V_31 , V_32 , V_33 , NULL ) ;
if ( F_78 ( V_2 ) )
goto V_99;
V_92 = F_21 ( V_30 , V_31 , V_32 , V_33 ) ;
if ( F_23 ( ! V_92 ) )
return NULL ;
error = F_41 ( V_92 , V_33 ) ;
if ( error ) {
F_36 ( V_92 ) ;
return NULL ;
}
V_2 = F_63 ( V_30 , V_31 , V_32 , V_33 , V_92 ) ;
if ( ! V_2 ) {
F_36 ( V_92 ) ;
return NULL ;
}
if ( V_2 != V_92 )
F_36 ( V_92 ) ;
V_99:
if ( ! V_2 -> V_3 ) {
error = F_50 ( V_2 , V_33 ) ;
if ( F_23 ( error ) ) {
F_79 ( V_30 -> V_49 ,
L_3 , V_74 ) ;
F_80 ( V_2 ) ;
return NULL ;
}
}
if ( ! ( V_33 & V_108 ) )
F_81 ( V_2 , 0 ) ;
F_31 ( V_30 -> V_49 , V_109 ) ;
F_82 ( V_2 , V_33 , V_51 ) ;
return V_2 ;
}
STATIC int
F_83 (
T_2 * V_2 ,
T_1 V_33 )
{
ASSERT ( ! ( V_33 & V_110 ) ) ;
ASSERT ( V_2 -> V_23 [ 0 ] . V_43 != V_111 ) ;
V_2 -> V_7 &= ~ ( V_110 | V_9 | V_38 ) ;
V_2 -> V_7 |= V_33 & ( V_108 | V_9 | V_38 ) ;
if ( V_33 & V_9 ) {
F_84 ( V_2 ) ;
return 0 ;
}
return F_85 ( V_2 ) ;
}
T_2 *
F_86 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 ,
const struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_33 |= V_108 ;
V_2 = F_77 ( V_30 , V_31 , V_32 , V_33 ) ;
if ( V_2 ) {
F_87 ( V_2 , V_33 , V_51 ) ;
if ( ! ( V_2 -> V_7 & V_114 ) ) {
F_31 ( V_30 -> V_49 , V_115 ) ;
V_2 -> V_106 = V_113 ;
F_83 ( V_2 , V_33 ) ;
} else if ( V_33 & V_9 ) {
F_80 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_7 &= ~ V_108 ;
}
}
return V_2 ;
}
void
F_88 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
const struct V_112 * V_113 )
{
if ( F_89 ( V_30 -> V_116 -> V_117 ) )
return;
F_86 ( V_30 , V_31 , V_32 ,
V_37 | V_9 | V_38 , V_113 ) ;
}
int
F_90 (
struct V_29 * V_30 ,
T_7 V_118 ,
T_4 V_119 ,
int V_33 ,
struct V_1 * * V_120 ,
const struct V_112 * V_113 )
{
struct V_1 * V_2 ;
* V_120 = NULL ;
V_2 = F_91 ( V_30 , V_119 , V_33 ) ;
if ( ! V_2 )
return - V_28 ;
ASSERT ( V_2 -> V_24 == 1 ) ;
V_2 -> V_42 = V_111 ;
V_2 -> V_23 [ 0 ] . V_43 = V_118 ;
V_2 -> V_7 |= V_108 ;
V_2 -> V_106 = V_113 ;
F_85 ( V_2 ) ;
if ( V_2 -> V_121 ) {
int error = V_2 -> V_121 ;
F_80 ( V_2 ) ;
return error ;
}
* V_120 = V_2 ;
return 0 ;
}
void
F_92 (
struct V_1 * V_2 ,
T_4 V_119 )
{
if ( V_2 -> V_53 )
F_35 ( V_2 ) ;
V_2 -> V_53 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_44 = V_119 ;
V_2 -> V_46 = V_119 ;
ASSERT ( V_2 -> V_24 == 1 ) ;
V_2 -> V_42 = V_111 ;
V_2 -> V_23 [ 0 ] . V_43 = V_111 ;
V_2 -> V_23 [ 0 ] . V_45 = V_2 -> V_44 ;
}
static inline struct V_56 *
F_93 (
void * V_122 )
{
if ( ( ! F_94 ( V_122 ) ) ) {
return F_45 ( V_122 ) ;
} else {
return F_95 ( V_122 ) ;
}
}
int
F_96 (
T_2 * V_2 ,
void * V_123 ,
T_4 V_124 )
{
int V_125 ;
int V_34 = 0 ;
unsigned long V_126 ;
unsigned long V_61 ;
T_4 V_127 ;
int V_52 ;
V_126 = ( unsigned long ) V_123 & V_66 ;
V_61 = ( unsigned long ) V_123 - V_126 ;
V_127 = F_97 ( V_124 + V_61 ) ;
V_52 = V_127 >> V_67 ;
if ( V_2 -> V_53 )
F_35 ( V_2 ) ;
V_2 -> V_53 = NULL ;
V_2 -> V_3 = V_123 ;
V_125 = F_33 ( V_2 , V_52 ) ;
if ( V_125 )
return V_125 ;
V_2 -> V_6 = V_61 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
V_2 -> V_53 [ V_34 ] = F_93 ( ( void * ) V_126 ) ;
V_126 += V_5 ;
}
V_2 -> V_46 = F_98 ( V_124 ) ;
V_2 -> V_44 = F_98 ( V_127 ) ;
return 0 ;
}
T_2 *
F_91 (
struct V_29 * V_30 ,
T_4 V_119 ,
int V_33 )
{
unsigned long V_52 ;
int error , V_34 ;
struct V_1 * V_2 ;
F_99 ( V_31 , V_111 , V_119 ) ;
V_2 = F_21 ( V_30 , & V_31 , 1 , V_33 & V_8 ) ;
if ( F_23 ( V_2 == NULL ) )
goto V_128;
V_52 = F_97 ( V_119 << V_129 ) >> V_67 ;
error = F_33 ( V_2 , V_52 ) ;
if ( error )
goto V_130;
for ( V_34 = 0 ; V_34 < V_52 ; V_34 ++ ) {
V_2 -> V_53 [ V_34 ] = F_46 ( F_42 ( V_33 ) ) ;
if ( ! V_2 -> V_53 [ V_34 ] )
goto V_131;
}
V_2 -> V_7 |= V_57 ;
error = F_50 ( V_2 , 0 ) ;
if ( F_23 ( error ) ) {
F_79 ( V_30 -> V_49 ,
L_4 , V_74 ) ;
goto V_131;
}
F_100 ( V_2 , V_51 ) ;
return V_2 ;
V_131:
while ( -- V_34 >= 0 )
F_40 ( V_2 -> V_53 [ V_34 ] ) ;
F_35 ( V_2 ) ;
V_130:
F_19 ( V_2 ) ;
F_29 ( V_35 , V_2 ) ;
V_128:
return NULL ;
}
void
F_101 (
T_2 * V_2 )
{
F_102 ( V_2 , V_51 ) ;
F_70 ( & V_2 -> V_21 ) ;
}
void
F_74 (
T_2 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_100 ;
bool V_132 ;
bool V_133 = false ;
F_103 ( V_2 , V_51 ) ;
if ( ! V_87 ) {
ASSERT ( F_38 ( & V_2 -> V_20 ) ) ;
if ( F_104 ( & V_2 -> V_21 ) ) {
F_10 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return;
}
ASSERT ( F_16 ( & V_2 -> V_21 ) > 0 ) ;
V_132 = F_105 ( & V_2 -> V_21 , & V_87 -> V_88 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( ! V_132 ) {
if ( ( F_16 ( & V_2 -> V_21 ) == 1 ) && ! F_38 ( & V_2 -> V_20 ) )
F_7 ( V_2 ) ;
goto V_134;
}
F_7 ( V_2 ) ;
if ( ! ( V_2 -> V_7 & V_15 ) && F_16 ( & V_2 -> V_17 ) ) {
if ( F_106 ( & V_2 -> V_13 -> V_19 , & V_2 -> V_20 ) ) {
V_2 -> V_11 &= ~ V_18 ;
F_70 ( & V_2 -> V_21 ) ;
}
F_6 ( & V_87 -> V_88 ) ;
} else {
if ( ! ( V_2 -> V_11 & V_18 ) ) {
F_14 ( & V_2 -> V_13 -> V_19 , & V_2 -> V_20 ) ;
} else {
ASSERT ( F_38 ( & V_2 -> V_20 ) ) ;
}
ASSERT ( ! ( V_2 -> V_7 & V_16 ) ) ;
F_107 ( & V_87 -> V_89 , & V_2 -> V_101 ,
V_90 ) ;
F_6 ( & V_87 -> V_88 ) ;
F_72 ( V_87 ) ;
V_133 = true ;
}
V_134:
F_6 ( & V_2 -> V_10 ) ;
if ( V_133 )
F_36 ( V_2 ) ;
}
int
F_73 (
struct V_1 * V_2 )
{
int V_135 ;
V_135 = F_108 ( & V_2 -> V_41 ) == 0 ;
if ( V_135 ) {
F_28 ( V_2 ) ;
F_109 ( V_2 , V_51 ) ;
} else {
F_110 ( V_2 , V_51 ) ;
}
return V_135 ;
}
void
F_75 (
struct V_1 * V_2 )
{
F_111 ( V_2 , V_51 ) ;
if ( F_16 ( & V_2 -> V_47 ) && ( V_2 -> V_7 & V_15 ) )
F_112 ( V_2 -> V_13 -> V_49 , 0 ) ;
F_113 ( & V_2 -> V_41 ) ;
F_28 ( V_2 ) ;
F_114 ( V_2 , V_51 ) ;
}
void
F_115 (
struct V_1 * V_2 )
{
ASSERT ( F_12 ( V_2 ) ) ;
F_116 ( V_2 ) ;
F_117 ( & V_2 -> V_41 ) ;
F_118 ( V_2 , V_51 ) ;
}
STATIC void
F_119 (
T_2 * V_2 )
{
F_120 ( V_136 , V_71 ) ;
if ( F_16 ( & V_2 -> V_47 ) == 0 )
return;
F_121 ( & V_2 -> V_48 , & V_136 ) ;
for (; ; ) {
F_122 ( V_137 ) ;
if ( F_16 ( & V_2 -> V_47 ) == 0 )
break;
F_123 () ;
}
F_124 ( & V_2 -> V_48 , & V_136 ) ;
F_122 ( V_138 ) ;
}
void
F_125 (
struct V_1 * V_2 )
{
bool V_139 = V_2 -> V_7 & V_108 ;
F_126 ( V_2 , V_51 ) ;
V_2 -> V_7 &= ~ ( V_108 | V_110 | V_38 ) ;
if ( ! V_2 -> V_121 && V_2 -> V_140 )
F_81 ( V_2 , V_2 -> V_140 ) ;
if ( V_139 && ! V_2 -> V_121 && V_2 -> V_106 ) {
ASSERT ( ! V_2 -> V_105 ) ;
V_2 -> V_106 -> V_141 ( V_2 ) ;
}
if ( ! V_2 -> V_121 )
V_2 -> V_7 |= V_114 ;
if ( V_2 -> V_105 )
( * ( V_2 -> V_105 ) ) ( V_2 ) ;
else if ( V_2 -> V_7 & V_9 )
F_80 ( V_2 ) ;
else
F_127 ( & V_2 -> V_39 ) ;
}
static void
F_128 (
struct V_142 * V_143 )
{
struct V_1 * V_2 =
F_129 ( V_143 , T_2 , V_144 ) ;
F_125 ( V_2 ) ;
}
static void
F_130 (
struct V_1 * V_2 )
{
F_131 ( & V_2 -> V_144 , F_128 ) ;
F_132 ( V_2 -> V_145 , & V_2 -> V_144 ) ;
}
void
F_81 (
T_2 * V_2 ,
int error )
{
ASSERT ( error <= 0 && error >= - 1000 ) ;
V_2 -> V_121 = error ;
F_133 ( V_2 , error , V_51 ) ;
}
void
F_134 (
struct V_1 * V_2 ,
const char * V_146 )
{
F_65 ( V_2 -> V_13 -> V_49 ,
L_5 ,
( V_147 ) F_135 ( V_2 ) , V_146 , - V_2 -> V_121 , V_2 -> V_44 ) ;
}
int
F_136 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_7 |= V_110 ;
V_2 -> V_7 &= ~ ( V_9 | V_108 | V_16 |
V_148 | V_114 ) ;
error = F_85 ( V_2 ) ;
if ( error ) {
F_137 ( V_2 -> V_13 -> V_49 ,
V_149 ) ;
}
return error ;
}
static void
F_138 (
struct V_150 * V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 -> V_151 ;
if ( V_150 -> V_152 )
F_139 ( & V_2 -> V_140 , 0 , V_150 -> V_152 ) ;
if ( ! V_2 -> V_121 && F_1 ( V_2 ) && ( V_2 -> V_7 & V_108 ) )
F_140 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
if ( F_104 ( & V_2 -> V_153 ) == 1 )
F_130 ( V_2 ) ;
F_141 ( V_150 ) ;
}
static void
F_142 (
struct V_1 * V_2 ,
int V_31 ,
int * V_154 ,
int * V_155 ,
int V_156 ,
int V_157 )
{
int V_158 ;
int V_159 = V_2 -> V_4 ;
int V_160 ;
struct V_150 * V_150 ;
T_8 V_161 = V_2 -> V_23 [ V_31 ] . V_43 ;
int V_59 ;
int V_61 ;
V_159 = V_2 -> V_4 ;
V_158 = 0 ;
V_61 = * V_154 ;
while ( V_61 >= V_5 ) {
V_158 ++ ;
V_61 -= V_5 ;
}
V_59 = F_49 ( int , F_43 ( V_2 -> V_23 [ V_31 ] . V_45 ) , * V_155 ) ;
* V_155 -= V_59 ;
* V_154 += V_59 ;
V_162:
F_70 ( & V_2 -> V_153 ) ;
V_160 = F_143 ( V_159 , V_163 ) ;
V_150 = F_144 ( V_164 , V_160 ) ;
V_150 -> V_165 = V_2 -> V_13 -> V_116 ;
V_150 -> V_166 . V_167 = V_161 ;
V_150 -> V_168 = F_138 ;
V_150 -> V_151 = V_2 ;
F_145 ( V_150 , V_156 , V_157 ) ;
for (; V_59 && V_160 ; V_160 -- , V_158 ++ ) {
int V_169 , V_60 = V_5 - V_61 ;
if ( V_60 > V_59 )
V_60 = V_59 ;
V_169 = F_146 ( V_150 , V_2 -> V_53 [ V_158 ] , V_60 ,
V_61 ) ;
if ( V_169 < V_60 )
break;
V_61 = 0 ;
V_161 += F_98 ( V_60 ) ;
V_59 -= V_60 ;
V_159 -- ;
}
if ( F_78 ( V_150 -> V_166 . V_170 ) ) {
if ( F_1 ( V_2 ) ) {
F_147 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_148 ( V_150 ) ;
if ( V_59 )
goto V_162;
} else {
F_15 ( & V_2 -> V_153 ) ;
F_81 ( V_2 , - V_171 ) ;
F_141 ( V_150 ) ;
}
}
STATIC void
F_149 (
struct V_1 * V_2 )
{
struct V_172 V_173 ;
int V_156 ;
int V_157 = 0 ;
int V_61 ;
int V_59 ;
int V_34 ;
V_2 -> V_121 = 0 ;
if ( ! V_2 -> V_145 )
V_2 -> V_145 = V_2 -> V_13 -> V_49 -> V_174 ;
if ( V_2 -> V_7 & V_110 ) {
V_156 = V_175 ;
if ( V_2 -> V_7 & V_176 )
V_157 = V_177 ;
if ( V_2 -> V_7 & V_178 )
V_157 |= V_179 ;
if ( V_2 -> V_7 & V_180 )
V_157 |= V_181 ;
if ( V_2 -> V_106 ) {
V_2 -> V_106 -> V_182 ( V_2 ) ;
if ( V_2 -> V_121 ) {
F_137 ( V_2 -> V_13 -> V_49 ,
V_183 ) ;
return;
}
} else if ( V_2 -> V_42 != V_111 ) {
struct V_184 * V_185 = V_2 -> V_13 -> V_49 ;
if ( F_150 ( & V_185 -> V_97 ) ) {
F_79 ( V_185 ,
L_6 ,
V_74 , V_2 -> V_42 , V_2 -> V_44 ) ;
F_151 ( V_2 -> V_3 , 64 ) ;
F_152 () ;
}
}
} else if ( V_2 -> V_7 & V_38 ) {
V_156 = V_186 ;
V_157 = V_187 ;
} else {
V_156 = V_186 ;
}
V_157 |= V_188 ;
V_61 = V_2 -> V_6 ;
V_59 = F_43 ( V_2 -> V_46 ) ;
F_153 ( & V_173 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_24 ; V_34 ++ ) {
F_142 ( V_2 , V_34 , & V_61 , & V_59 , V_156 , V_157 ) ;
if ( V_2 -> V_121 )
break;
if ( V_59 <= 0 )
break;
}
F_154 ( & V_173 ) ;
}
void
F_84 (
struct V_1 * V_2 )
{
F_155 ( V_2 , V_51 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_16 ) ) ;
ASSERT ( V_2 -> V_7 & V_9 ) ;
if ( F_156 ( V_2 -> V_13 -> V_49 ) ) {
F_81 ( V_2 , - V_171 ) ;
V_2 -> V_7 &= ~ V_114 ;
F_11 ( V_2 ) ;
F_125 ( V_2 ) ;
return;
}
if ( V_2 -> V_7 & V_110 )
F_119 ( V_2 ) ;
V_2 -> V_140 = 0 ;
F_101 ( V_2 ) ;
F_13 ( & V_2 -> V_153 , 1 ) ;
F_3 ( V_2 ) ;
F_149 ( V_2 ) ;
if ( F_104 ( & V_2 -> V_153 ) == 1 ) {
if ( V_2 -> V_121 )
F_125 ( V_2 ) ;
else
F_130 ( V_2 ) ;
}
F_74 ( V_2 ) ;
}
int
F_85 (
struct V_1 * V_2 )
{
int error ;
F_157 ( V_2 , V_51 ) ;
ASSERT ( ! ( V_2 -> V_7 & ( V_16 | V_9 ) ) ) ;
if ( F_156 ( V_2 -> V_13 -> V_49 ) ) {
F_81 ( V_2 , - V_171 ) ;
F_11 ( V_2 ) ;
V_2 -> V_7 &= ~ V_114 ;
return - V_171 ;
}
if ( V_2 -> V_7 & V_110 )
F_119 ( V_2 ) ;
V_2 -> V_140 = 0 ;
F_101 ( V_2 ) ;
F_13 ( & V_2 -> V_153 , 1 ) ;
F_149 ( V_2 ) ;
if ( F_104 ( & V_2 -> V_153 ) == 1 )
F_125 ( V_2 ) ;
F_158 ( V_2 , V_51 ) ;
F_159 ( & V_2 -> V_39 ) ;
F_160 ( V_2 , V_51 ) ;
error = V_2 -> V_121 ;
F_74 ( V_2 ) ;
return error ;
}
void *
F_161 (
struct V_1 * V_2 ,
T_4 V_61 )
{
struct V_56 * V_56 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_61 ;
V_61 += V_2 -> V_6 ;
V_56 = V_2 -> V_53 [ V_61 >> V_67 ] ;
return F_51 ( V_56 ) + ( V_61 & ( V_5 - 1 ) ) ;
}
void
F_162 (
T_2 * V_2 ,
T_4 V_189 ,
T_4 V_190 ,
void * V_191 ,
T_9 V_192 )
{
T_4 V_193 ;
V_193 = V_189 + V_190 ;
while ( V_189 < V_193 ) {
struct V_56 * V_56 ;
int V_158 , V_194 , V_195 ;
V_158 = ( V_189 + V_2 -> V_6 ) >> V_67 ;
V_194 = ( V_189 + V_2 -> V_6 ) & ~ V_66 ;
V_56 = V_2 -> V_53 [ V_158 ] ;
V_195 = F_49 ( T_4 , V_5 - V_194 ,
F_43 ( V_2 -> V_46 ) - V_189 ) ;
ASSERT ( ( V_195 + V_194 ) <= V_5 ) ;
switch ( V_192 ) {
case V_196 :
memset ( F_51 ( V_56 ) + V_194 , 0 , V_195 ) ;
break;
case V_197 :
memcpy ( V_191 , F_51 ( V_56 ) + V_194 , V_195 ) ;
break;
case V_198 :
memcpy ( F_51 ( V_56 ) + V_194 , V_191 , V_195 ) ;
}
V_189 += V_195 ;
V_191 += V_195 ;
}
}
static enum V_199
F_163 (
struct V_200 * V_201 ,
struct V_202 * V_203 ,
T_10 * V_204 ,
void * V_83 )
{
struct V_1 * V_2 = F_129 ( V_201 , struct V_1 , V_20 ) ;
struct V_200 * V_205 = V_83 ;
if ( F_16 ( & V_2 -> V_21 ) > 1 ) {
F_164 ( V_2 , V_51 ) ;
return V_206 ;
}
if ( ! F_165 ( & V_2 -> V_10 ) )
return V_206 ;
F_13 ( & V_2 -> V_17 , 0 ) ;
V_2 -> V_11 |= V_18 ;
F_166 ( V_203 , V_201 , V_205 ) ;
F_6 ( & V_2 -> V_10 ) ;
return V_207 ;
}
void
F_167 (
struct V_29 * V_91 )
{
F_168 ( V_205 ) ;
int V_208 = 0 ;
while ( F_169 ( & V_91 -> V_14 ) )
F_170 ( 100 ) ;
F_171 ( V_91 -> V_49 -> V_174 ) ;
while ( F_172 ( & V_91 -> V_19 ) ) {
F_173 ( & V_91 -> V_19 , F_163 ,
& V_205 , V_209 ) ;
while ( ! F_38 ( & V_205 ) ) {
struct V_1 * V_2 ;
V_2 = F_174 ( & V_205 , struct V_1 , V_20 ) ;
F_175 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_7 & V_148 ) {
F_65 ( V_91 -> V_49 ,
L_7 ,
( long long ) V_2 -> V_42 ) ;
F_65 ( V_91 -> V_49 ,
L_8 ) ;
}
F_74 ( V_2 ) ;
}
if ( V_208 ++ != 0 )
F_170 ( 100 ) ;
}
}
static enum V_199
F_176 (
struct V_200 * V_201 ,
struct V_202 * V_203 ,
T_10 * V_204 ,
void * V_83 )
{
struct V_1 * V_2 = F_129 ( V_201 , struct V_1 , V_20 ) ;
struct V_200 * V_205 = V_83 ;
if ( ! F_165 ( & V_2 -> V_10 ) )
return V_206 ;
if ( ! F_177 ( & V_2 -> V_17 , - 1 , 0 ) ) {
F_6 ( & V_2 -> V_10 ) ;
return V_210 ;
}
V_2 -> V_11 |= V_18 ;
F_166 ( V_203 , V_201 , V_205 ) ;
F_6 ( & V_2 -> V_10 ) ;
return V_207 ;
}
static unsigned long
F_178 (
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_29 * V_91 = F_129 ( V_212 ,
struct V_29 , V_215 ) ;
F_168 ( V_205 ) ;
unsigned long V_216 ;
V_216 = F_179 ( & V_91 -> V_19 , V_214 ,
F_176 , & V_205 ) ;
while ( ! F_38 ( & V_205 ) ) {
struct V_1 * V_2 ;
V_2 = F_174 ( & V_205 , struct V_1 , V_20 ) ;
F_175 ( & V_2 -> V_20 ) ;
F_74 ( V_2 ) ;
}
return V_216 ;
}
static unsigned long
F_180 (
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_29 * V_91 = F_129 ( V_212 ,
struct V_29 , V_215 ) ;
return F_181 ( & V_91 -> V_19 , V_214 ) ;
}
void
F_182 (
struct V_184 * V_185 ,
struct V_29 * V_91 )
{
F_183 ( & V_91 -> V_215 ) ;
ASSERT ( F_169 ( & V_91 -> V_14 ) == 0 ) ;
F_184 ( & V_91 -> V_14 ) ;
F_185 ( & V_91 -> V_19 ) ;
F_186 ( V_91 ) ;
F_20 ( V_91 ) ;
}
int
F_187 (
T_11 * V_91 ,
unsigned int V_217 )
{
V_91 -> V_95 = V_217 ;
V_91 -> V_96 = V_217 - 1 ;
if ( F_188 ( V_91 -> V_116 , V_217 ) ) {
F_79 ( V_91 -> V_49 ,
L_9 ,
V_217 , V_91 -> V_116 ) ;
return - V_218 ;
}
V_91 -> V_219 = F_189 ( V_91 -> V_116 ) ;
V_91 -> V_220 = F_189 ( V_91 -> V_116 ) - 1 ;
return 0 ;
}
STATIC int
F_190 (
T_11 * V_91 ,
struct V_221 * V_222 )
{
return F_187 ( V_91 , F_189 ( V_222 ) ) ;
}
T_11 *
F_191 (
struct V_184 * V_185 ,
struct V_221 * V_222 )
{
T_11 * V_91 ;
V_91 = F_18 ( sizeof( * V_91 ) , V_223 | V_27 ) ;
V_91 -> V_49 = V_185 ;
V_91 -> V_224 = V_222 -> V_225 ;
V_91 -> V_116 = V_222 ;
if ( F_190 ( V_91 , V_222 ) )
goto error;
if ( F_192 ( & V_91 -> V_19 ) )
goto error;
if ( F_193 ( & V_91 -> V_14 , 0 , V_226 ) )
goto error;
V_91 -> V_215 . V_227 = F_180 ;
V_91 -> V_215 . V_228 = F_178 ;
V_91 -> V_215 . V_229 = V_230 ;
V_91 -> V_215 . V_33 = V_231 ;
F_194 ( & V_91 -> V_215 ) ;
return V_91 ;
error:
F_20 ( V_91 ) ;
return NULL ;
}
void
F_195 (
struct V_200 * V_232 )
{
struct V_1 * V_2 ;
while ( ! F_38 ( V_232 ) ) {
V_2 = F_174 ( V_232 , struct V_1 , V_40 ) ;
F_75 ( V_2 ) ;
V_2 -> V_7 &= ~ V_16 ;
F_175 ( & V_2 -> V_40 ) ;
F_80 ( V_2 ) ;
}
}
bool
F_196 (
struct V_1 * V_2 ,
struct V_200 * V_232 )
{
ASSERT ( F_12 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_7 & V_108 ) ) ;
if ( V_2 -> V_7 & V_16 ) {
F_197 ( V_2 , V_51 ) ;
return false ;
}
F_198 ( V_2 , V_51 ) ;
V_2 -> V_7 |= V_16 ;
if ( F_38 ( & V_2 -> V_40 ) ) {
F_70 ( & V_2 -> V_21 ) ;
F_199 ( & V_2 -> V_40 , V_232 ) ;
}
return true ;
}
static int
F_200 (
void * V_233 ,
struct V_200 * V_234 ,
struct V_200 * V_235 )
{
struct V_1 * V_236 = F_129 ( V_234 , struct V_1 , V_40 ) ;
struct V_1 * V_2 = F_129 ( V_235 , struct V_1 , V_40 ) ;
T_7 V_237 ;
V_237 = V_236 -> V_23 [ 0 ] . V_43 - V_2 -> V_23 [ 0 ] . V_43 ;
if ( V_237 < 0 )
return - 1 ;
if ( V_237 > 0 )
return 1 ;
return 0 ;
}
static int
F_201 (
struct V_200 * V_238 ,
struct V_200 * V_239 )
{
struct V_1 * V_2 , * V_240 ;
F_168 ( V_241 ) ;
int V_242 = 0 ;
struct V_172 V_173 ;
F_202 ( NULL , V_238 , F_200 ) ;
F_153 ( & V_173 ) ;
F_203 (bp, n, buffer_list, b_list) {
if ( ! V_239 ) {
if ( F_204 ( V_2 ) ) {
V_242 ++ ;
continue;
}
if ( ! F_73 ( V_2 ) )
continue;
} else {
F_75 ( V_2 ) ;
}
if ( ! ( V_2 -> V_7 & V_16 ) ) {
F_175 ( & V_2 -> V_40 ) ;
F_80 ( V_2 ) ;
continue;
}
F_205 ( V_2 , V_51 ) ;
V_2 -> V_7 &= ~ ( V_16 | V_148 ) ;
V_2 -> V_7 |= V_110 | V_9 ;
if ( V_239 ) {
F_101 ( V_2 ) ;
F_206 ( & V_2 -> V_40 , V_239 ) ;
} else
F_175 ( & V_2 -> V_40 ) ;
F_84 ( V_2 ) ;
}
F_154 ( & V_173 ) ;
return V_242 ;
}
int
F_207 (
struct V_200 * V_238 )
{
return F_201 ( V_238 , NULL ) ;
}
int
F_208 (
struct V_200 * V_238 )
{
F_168 ( V_239 ) ;
int error = 0 , V_243 ;
struct V_1 * V_2 ;
F_201 ( V_238 , & V_239 ) ;
while ( ! F_38 ( & V_239 ) ) {
V_2 = F_174 ( & V_239 , struct V_1 , V_40 ) ;
F_175 ( & V_2 -> V_40 ) ;
F_75 ( V_2 ) ;
V_243 = V_2 -> V_121 ;
F_80 ( V_2 ) ;
if ( ! error )
error = V_243 ;
}
return error ;
}
int T_12
F_209 ( void )
{
V_35 = F_210 ( sizeof( T_2 ) , L_10 ,
V_244 , NULL ) ;
if ( ! V_35 )
goto V_245;
return 0 ;
V_245:
return - V_28 ;
}
void
F_211 ( void )
{
F_212 ( V_35 ) ;
}
