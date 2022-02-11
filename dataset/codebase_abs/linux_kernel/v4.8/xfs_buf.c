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
if ( V_2 -> V_7 & ( V_8 | V_9 ) )
return;
ASSERT ( V_2 -> V_7 & V_10 ) ;
V_2 -> V_7 |= V_9 ;
F_4 ( & V_2 -> V_11 -> V_12 ) ;
}
static inline void
F_5 (
struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_7 & V_9 ) )
return;
V_2 -> V_7 &= ~ V_9 ;
F_6 ( & V_2 -> V_11 -> V_12 ) ;
}
void
F_7 (
struct V_1 * V_2 )
{
ASSERT ( F_8 ( V_2 ) ) ;
V_2 -> V_7 |= V_13 ;
V_2 -> V_7 &= ~ V_14 ;
F_5 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_10 ( & V_2 -> V_16 , 0 ) ;
if ( ! ( V_2 -> V_17 & V_18 ) &&
( F_11 ( & V_2 -> V_11 -> V_19 , & V_2 -> V_20 ) ) )
F_12 ( & V_2 -> V_21 ) ;
ASSERT ( F_13 ( & V_2 -> V_21 ) >= 1 ) ;
F_14 ( & V_2 -> V_15 ) ;
}
static int
F_15 (
struct V_1 * V_2 ,
int V_22 )
{
ASSERT ( V_2 -> V_23 == NULL ) ;
V_2 -> V_24 = V_22 ;
if ( V_22 == 1 ) {
V_2 -> V_23 = & V_2 -> V_25 ;
return 0 ;
}
V_2 -> V_23 = F_16 ( V_22 * sizeof( struct V_26 ) ,
V_27 ) ;
if ( ! V_2 -> V_23 )
return - V_28 ;
return 0 ;
}
static void
F_17 (
struct V_1 * V_2 )
{
if ( V_2 -> V_23 != & V_2 -> V_25 ) {
F_18 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
}
struct V_1 *
F_19 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 )
{
struct V_1 * V_2 ;
int error ;
int V_34 ;
V_2 = F_20 ( V_35 , V_27 ) ;
if ( F_21 ( ! V_2 ) )
return NULL ;
V_33 &= ~ ( V_36 | V_37 | V_10 | V_38 ) ;
F_10 ( & V_2 -> V_21 , 1 ) ;
F_10 ( & V_2 -> V_16 , 1 ) ;
F_22 ( & V_2 -> V_39 ) ;
F_23 ( & V_2 -> V_20 ) ;
F_23 ( & V_2 -> V_40 ) ;
F_24 ( & V_2 -> V_41 ) ;
F_25 ( & V_2 -> V_42 , 0 ) ;
F_26 ( & V_2 -> V_15 ) ;
F_27 ( V_2 ) ;
V_2 -> V_11 = V_30 ;
V_2 -> V_7 = V_33 ;
error = F_15 ( V_2 , V_32 ) ;
if ( error ) {
F_28 ( V_35 , V_2 ) ;
return NULL ;
}
V_2 -> V_43 = V_31 [ 0 ] . V_44 ;
V_2 -> V_45 = 0 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_2 -> V_23 [ V_34 ] . V_44 = V_31 [ V_34 ] . V_44 ;
V_2 -> V_23 [ V_34 ] . V_46 = V_31 [ V_34 ] . V_46 ;
V_2 -> V_45 += V_31 [ V_34 ] . V_46 ;
}
V_2 -> V_47 = V_2 -> V_45 ;
F_10 ( & V_2 -> V_48 , 0 ) ;
F_29 ( & V_2 -> V_49 ) ;
F_30 ( V_30 -> V_50 , V_51 ) ;
F_31 ( V_2 , V_52 ) ;
return V_2 ;
}
STATIC int
F_32 (
T_2 * V_2 ,
int V_53 )
{
if ( V_2 -> V_54 == NULL ) {
V_2 -> V_4 = V_53 ;
if ( V_53 <= V_55 ) {
V_2 -> V_54 = V_2 -> V_56 ;
} else {
V_2 -> V_54 = F_33 ( sizeof( struct V_57 * ) *
V_53 , V_27 ) ;
if ( V_2 -> V_54 == NULL )
return - V_28 ;
}
memset ( V_2 -> V_54 , 0 , sizeof( struct V_57 * ) * V_53 ) ;
}
return 0 ;
}
STATIC void
F_34 (
T_2 * V_2 )
{
if ( V_2 -> V_54 != V_2 -> V_56 ) {
F_18 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
}
void
F_35 (
T_2 * V_2 )
{
F_36 ( V_2 , V_52 ) ;
ASSERT ( F_37 ( & V_2 -> V_20 ) ) ;
if ( V_2 -> V_7 & V_58 ) {
T_3 V_34 ;
if ( F_1 ( V_2 ) )
F_38 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
struct V_57 * V_57 = V_2 -> V_54 [ V_34 ] ;
F_39 ( V_57 ) ;
}
} else if ( V_2 -> V_7 & V_59 )
F_18 ( V_2 -> V_3 ) ;
F_34 ( V_2 ) ;
F_17 ( V_2 ) ;
F_28 ( V_35 , V_2 ) ;
}
STATIC int
F_40 (
T_2 * V_2 ,
T_3 V_33 )
{
T_4 V_60 ;
T_4 V_61 , V_62 ;
T_5 V_63 = F_41 ( V_33 ) ;
unsigned short V_53 , V_34 ;
T_6 V_64 , V_65 ;
int error ;
V_60 = F_42 ( V_2 -> V_45 ) ;
if ( V_60 < V_5 ) {
V_2 -> V_3 = F_33 ( V_60 , V_27 ) ;
if ( ! V_2 -> V_3 ) {
goto V_66;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_60 - 1 ) & V_67 ) !=
( ( unsigned long ) V_2 -> V_3 & V_67 ) ) {
F_18 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_66;
}
V_2 -> V_6 = F_43 ( V_2 -> V_3 ) ;
V_2 -> V_54 = V_2 -> V_56 ;
V_2 -> V_54 [ 0 ] = F_44 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_7 |= V_59 ;
return 0 ;
}
V_66:
V_64 = F_42 ( V_2 -> V_23 [ 0 ] . V_44 ) >> V_68 ;
V_65 = ( F_42 ( V_2 -> V_23 [ 0 ] . V_44 + V_2 -> V_45 ) + V_5 - 1 )
>> V_68 ;
V_53 = V_65 - V_64 ;
error = F_32 ( V_2 , V_53 ) ;
if ( F_21 ( error ) )
return error ;
V_62 = V_2 -> V_6 ;
V_2 -> V_7 |= V_58 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
struct V_57 * V_57 ;
T_3 V_69 = 0 ;
V_70:
V_57 = F_45 ( V_63 ) ;
if ( F_21 ( V_57 == NULL ) ) {
if ( V_33 & V_38 ) {
V_2 -> V_4 = V_34 ;
error = - V_28 ;
goto V_71;
}
if ( ! ( ++ V_69 % 100 ) )
F_46 ( NULL ,
L_1 ,
V_72 -> V_73 , V_72 -> V_74 ,
V_75 , V_63 ) ;
F_30 ( V_2 -> V_11 -> V_50 , V_76 ) ;
F_47 ( V_77 , V_78 / 50 ) ;
goto V_70;
}
F_30 ( V_2 -> V_11 -> V_50 , V_79 ) ;
V_61 = F_48 ( T_4 , V_60 , V_5 - V_62 ) ;
V_60 -= V_61 ;
V_2 -> V_54 [ V_34 ] = V_57 ;
V_62 = 0 ;
}
return 0 ;
V_71:
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ )
F_39 ( V_2 -> V_54 [ V_34 ] ) ;
return error ;
}
STATIC int
F_49 (
T_2 * V_2 ,
T_3 V_33 )
{
ASSERT ( V_2 -> V_7 & V_58 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_50 ( V_2 -> V_54 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_33 & V_36 ) {
V_2 -> V_3 = NULL ;
} else {
int V_80 = 0 ;
unsigned V_81 ;
V_81 = F_51 () ;
do {
V_2 -> V_3 = F_52 ( V_2 -> V_54 , V_2 -> V_4 ,
- 1 , V_82 ) ;
if ( V_2 -> V_3 )
break;
F_53 () ;
} while ( V_80 ++ <= 1 );
F_54 ( V_81 ) ;
if ( ! V_2 -> V_3 )
return - V_28 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_2 *
F_55 (
struct V_29 * V_83 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 ,
T_2 * V_84 )
{
struct V_85 * V_86 ;
struct V_87 * * V_88 ;
struct V_87 * V_89 ;
T_2 * V_2 ;
T_7 V_90 = V_31 [ 0 ] . V_44 ;
T_7 V_91 ;
int V_92 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ )
V_92 += V_31 [ V_34 ] . V_46 ;
ASSERT ( ! ( F_42 ( V_92 ) < V_83 -> V_93 ) ) ;
ASSERT ( ! ( F_42 ( V_90 ) & ( T_6 ) V_83 -> V_94 ) ) ;
V_91 = F_56 ( V_83 -> V_50 , V_83 -> V_50 -> V_95 . V_96 ) ;
if ( V_90 < 0 || V_90 >= V_91 ) {
F_57 ( V_83 -> V_50 ,
L_2 ,
V_75 , V_90 , V_91 ) ;
F_58 ( 1 ) ;
return NULL ;
}
V_86 = F_59 ( V_83 -> V_50 ,
F_60 ( V_83 -> V_50 , V_90 ) ) ;
F_9 ( & V_86 -> V_97 ) ;
V_88 = & V_86 -> V_98 . V_87 ;
V_89 = NULL ;
V_2 = NULL ;
while ( * V_88 ) {
V_89 = * V_88 ;
V_2 = F_61 ( V_89 , struct V_1 , V_41 ) ;
if ( V_90 < V_2 -> V_43 )
V_88 = & ( * V_88 ) -> V_99 ;
else if ( V_90 > V_2 -> V_43 )
V_88 = & ( * V_88 ) -> V_100 ;
else {
if ( V_2 -> V_45 != V_92 ) {
ASSERT ( V_2 -> V_7 & V_13 ) ;
V_88 = & ( * V_88 ) -> V_100 ;
continue;
}
F_62 ( & V_2 -> V_21 ) ;
goto V_101;
}
}
if ( V_84 ) {
F_63 ( & V_84 -> V_41 , V_89 , V_88 ) ;
F_64 ( & V_84 -> V_41 , & V_86 -> V_98 ) ;
V_84 -> V_102 = V_86 ;
F_14 ( & V_86 -> V_97 ) ;
} else {
F_30 ( V_83 -> V_50 , V_103 ) ;
F_14 ( & V_86 -> V_97 ) ;
F_65 ( V_86 ) ;
}
return V_84 ;
V_101:
F_14 ( & V_86 -> V_97 ) ;
F_65 ( V_86 ) ;
if ( ! F_66 ( V_2 ) ) {
if ( V_33 & V_37 ) {
F_67 ( V_2 ) ;
F_30 ( V_83 -> V_50 , V_104 ) ;
return NULL ;
}
F_68 ( V_2 ) ;
F_30 ( V_83 -> V_50 , V_105 ) ;
}
if ( V_2 -> V_7 & V_13 ) {
ASSERT ( ( V_2 -> V_7 & V_14 ) == 0 ) ;
ASSERT ( V_2 -> V_106 == NULL ) ;
V_2 -> V_7 &= V_59 | V_58 ;
V_2 -> V_107 = NULL ;
}
F_69 ( V_2 , V_33 , V_52 ) ;
F_30 ( V_83 -> V_50 , V_108 ) ;
return V_2 ;
}
struct V_1 *
F_70 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 )
{
struct V_1 * V_2 ;
struct V_1 * V_84 ;
int error = 0 ;
V_2 = F_55 ( V_30 , V_31 , V_32 , V_33 , NULL ) ;
if ( F_71 ( V_2 ) )
goto V_101;
V_84 = F_19 ( V_30 , V_31 , V_32 , V_33 ) ;
if ( F_21 ( ! V_84 ) )
return NULL ;
error = F_40 ( V_84 , V_33 ) ;
if ( error ) {
F_35 ( V_84 ) ;
return NULL ;
}
V_2 = F_55 ( V_30 , V_31 , V_32 , V_33 , V_84 ) ;
if ( ! V_2 ) {
F_35 ( V_84 ) ;
return NULL ;
}
if ( V_2 != V_84 )
F_35 ( V_84 ) ;
V_101:
if ( ! V_2 -> V_3 ) {
error = F_49 ( V_2 , V_33 ) ;
if ( F_21 ( error ) ) {
F_72 ( V_30 -> V_50 ,
L_3 , V_75 ) ;
F_73 ( V_2 ) ;
return NULL ;
}
}
if ( ! ( V_33 & V_109 ) )
F_74 ( V_2 , 0 ) ;
F_30 ( V_30 -> V_50 , V_110 ) ;
F_75 ( V_2 , V_33 , V_52 ) ;
return V_2 ;
}
STATIC int
F_76 (
T_2 * V_2 ,
T_1 V_33 )
{
ASSERT ( ! ( V_33 & V_111 ) ) ;
ASSERT ( V_2 -> V_23 [ 0 ] . V_44 != V_112 ) ;
V_2 -> V_7 &= ~ ( V_111 | V_10 | V_38 ) ;
V_2 -> V_7 |= V_33 & ( V_109 | V_10 | V_38 ) ;
if ( V_33 & V_10 ) {
F_77 ( V_2 ) ;
return 0 ;
}
return F_78 ( V_2 ) ;
}
T_2 *
F_79 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
T_1 V_33 ,
const struct V_113 * V_114 )
{
struct V_1 * V_2 ;
V_33 |= V_109 ;
V_2 = F_70 ( V_30 , V_31 , V_32 , V_33 ) ;
if ( V_2 ) {
F_80 ( V_2 , V_33 , V_52 ) ;
if ( ! ( V_2 -> V_7 & V_115 ) ) {
F_30 ( V_30 -> V_50 , V_116 ) ;
V_2 -> V_107 = V_114 ;
F_76 ( V_2 , V_33 ) ;
} else if ( V_33 & V_10 ) {
F_73 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_7 &= ~ V_109 ;
}
}
return V_2 ;
}
void
F_81 (
struct V_29 * V_30 ,
struct V_26 * V_31 ,
int V_32 ,
const struct V_113 * V_114 )
{
if ( F_82 ( V_30 -> V_117 ) )
return;
F_79 ( V_30 , V_31 , V_32 ,
V_37 | V_10 | V_38 , V_114 ) ;
}
int
F_83 (
struct V_29 * V_30 ,
T_7 V_118 ,
T_4 V_92 ,
int V_33 ,
struct V_1 * * V_119 ,
const struct V_113 * V_114 )
{
struct V_1 * V_2 ;
* V_119 = NULL ;
V_2 = F_84 ( V_30 , V_92 , V_33 ) ;
if ( ! V_2 )
return - V_28 ;
ASSERT ( V_2 -> V_24 == 1 ) ;
V_2 -> V_43 = V_112 ;
V_2 -> V_23 [ 0 ] . V_44 = V_118 ;
V_2 -> V_7 |= V_109 ;
V_2 -> V_107 = V_114 ;
F_78 ( V_2 ) ;
if ( V_2 -> V_120 ) {
int error = V_2 -> V_120 ;
F_73 ( V_2 ) ;
return error ;
}
* V_119 = V_2 ;
return 0 ;
}
void
F_85 (
struct V_1 * V_2 ,
T_4 V_92 )
{
if ( V_2 -> V_54 )
F_34 ( V_2 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_45 = V_92 ;
V_2 -> V_47 = V_92 ;
ASSERT ( V_2 -> V_24 == 1 ) ;
V_2 -> V_43 = V_112 ;
V_2 -> V_23 [ 0 ] . V_44 = V_112 ;
V_2 -> V_23 [ 0 ] . V_46 = V_2 -> V_45 ;
}
static inline struct V_57 *
F_86 (
void * V_121 )
{
if ( ( ! F_87 ( V_121 ) ) ) {
return F_44 ( V_121 ) ;
} else {
return F_88 ( V_121 ) ;
}
}
int
F_89 (
T_2 * V_2 ,
void * V_122 ,
T_4 V_123 )
{
int V_124 ;
int V_34 = 0 ;
unsigned long V_125 ;
unsigned long V_62 ;
T_4 V_126 ;
int V_53 ;
V_125 = ( unsigned long ) V_122 & V_67 ;
V_62 = ( unsigned long ) V_122 - V_125 ;
V_126 = F_90 ( V_123 + V_62 ) ;
V_53 = V_126 >> V_68 ;
if ( V_2 -> V_54 )
F_34 ( V_2 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_3 = V_122 ;
V_124 = F_32 ( V_2 , V_53 ) ;
if ( V_124 )
return V_124 ;
V_2 -> V_6 = V_62 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 ; V_34 ++ ) {
V_2 -> V_54 [ V_34 ] = F_86 ( ( void * ) V_125 ) ;
V_125 += V_5 ;
}
V_2 -> V_47 = F_91 ( V_123 ) ;
V_2 -> V_45 = F_91 ( V_126 ) ;
return 0 ;
}
T_2 *
F_84 (
struct V_29 * V_30 ,
T_4 V_92 ,
int V_33 )
{
unsigned long V_53 ;
int error , V_34 ;
struct V_1 * V_2 ;
F_92 ( V_31 , V_112 , V_92 ) ;
V_2 = F_19 ( V_30 , & V_31 , 1 , V_33 & V_8 ) ;
if ( F_21 ( V_2 == NULL ) )
goto V_127;
V_53 = F_90 ( V_92 << V_128 ) >> V_68 ;
error = F_32 ( V_2 , V_53 ) ;
if ( error )
goto V_129;
for ( V_34 = 0 ; V_34 < V_53 ; V_34 ++ ) {
V_2 -> V_54 [ V_34 ] = F_45 ( F_41 ( V_33 ) ) ;
if ( ! V_2 -> V_54 [ V_34 ] )
goto V_130;
}
V_2 -> V_7 |= V_58 ;
error = F_49 ( V_2 , 0 ) ;
if ( F_21 ( error ) ) {
F_72 ( V_30 -> V_50 ,
L_4 , V_75 ) ;
goto V_130;
}
F_93 ( V_2 , V_52 ) ;
return V_2 ;
V_130:
while ( -- V_34 >= 0 )
F_39 ( V_2 -> V_54 [ V_34 ] ) ;
F_34 ( V_2 ) ;
V_129:
F_17 ( V_2 ) ;
F_28 ( V_35 , V_2 ) ;
V_127:
return NULL ;
}
void
F_94 (
T_2 * V_2 )
{
F_95 ( V_2 , V_52 ) ;
F_62 ( & V_2 -> V_21 ) ;
}
void
F_67 (
T_2 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_102 ;
bool V_131 ;
bool V_132 = false ;
F_96 ( V_2 , V_52 ) ;
if ( ! V_86 ) {
ASSERT ( F_37 ( & V_2 -> V_20 ) ) ;
ASSERT ( F_97 ( & V_2 -> V_41 ) ) ;
if ( F_98 ( & V_2 -> V_21 ) ) {
F_5 ( V_2 ) ;
F_35 ( V_2 ) ;
}
return;
}
ASSERT ( ! F_97 ( & V_2 -> V_41 ) ) ;
ASSERT ( F_13 ( & V_2 -> V_21 ) > 0 ) ;
V_131 = F_99 ( & V_2 -> V_21 , & V_86 -> V_97 ) ;
F_9 ( & V_2 -> V_15 ) ;
if ( ! V_131 ) {
if ( ( F_13 ( & V_2 -> V_21 ) == 1 ) && ! F_37 ( & V_2 -> V_20 ) )
F_5 ( V_2 ) ;
goto V_133;
}
F_5 ( V_2 ) ;
if ( ! ( V_2 -> V_7 & V_13 ) && F_13 ( & V_2 -> V_16 ) ) {
if ( F_100 ( & V_2 -> V_11 -> V_19 , & V_2 -> V_20 ) ) {
V_2 -> V_17 &= ~ V_18 ;
F_62 ( & V_2 -> V_21 ) ;
}
F_14 ( & V_86 -> V_97 ) ;
} else {
if ( ! ( V_2 -> V_17 & V_18 ) ) {
F_11 ( & V_2 -> V_11 -> V_19 , & V_2 -> V_20 ) ;
} else {
ASSERT ( F_37 ( & V_2 -> V_20 ) ) ;
}
ASSERT ( ! ( V_2 -> V_7 & V_14 ) ) ;
F_101 ( & V_2 -> V_41 , & V_86 -> V_98 ) ;
F_14 ( & V_86 -> V_97 ) ;
F_65 ( V_86 ) ;
V_132 = true ;
}
V_133:
F_14 ( & V_2 -> V_15 ) ;
if ( V_132 )
F_35 ( V_2 ) ;
}
int
F_66 (
struct V_1 * V_2 )
{
int V_134 ;
V_134 = F_102 ( & V_2 -> V_42 ) == 0 ;
if ( V_134 ) {
F_27 ( V_2 ) ;
F_103 ( V_2 , V_52 ) ;
} else {
F_104 ( V_2 , V_52 ) ;
}
return V_134 ;
}
void
F_68 (
struct V_1 * V_2 )
{
F_105 ( V_2 , V_52 ) ;
if ( F_13 ( & V_2 -> V_48 ) && ( V_2 -> V_7 & V_13 ) )
F_106 ( V_2 -> V_11 -> V_50 , 0 ) ;
F_107 ( & V_2 -> V_42 ) ;
F_27 ( V_2 ) ;
F_108 ( V_2 , V_52 ) ;
}
void
F_109 (
struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
F_111 ( & V_2 -> V_42 ) ;
F_112 ( V_2 , V_52 ) ;
}
STATIC void
F_113 (
T_2 * V_2 )
{
F_114 ( V_135 , V_72 ) ;
if ( F_13 ( & V_2 -> V_48 ) == 0 )
return;
F_115 ( & V_2 -> V_49 , & V_135 ) ;
for (; ; ) {
F_116 ( V_136 ) ;
if ( F_13 ( & V_2 -> V_48 ) == 0 )
break;
F_117 () ;
}
F_118 ( & V_2 -> V_49 , & V_135 ) ;
F_116 ( V_137 ) ;
}
void
F_119 (
struct V_1 * V_2 )
{
bool V_138 = V_2 -> V_7 & V_109 ;
F_120 ( V_2 , V_52 ) ;
V_2 -> V_7 &= ~ ( V_109 | V_111 | V_38 ) ;
if ( ! V_2 -> V_120 && V_2 -> V_139 )
F_74 ( V_2 , V_2 -> V_139 ) ;
if ( V_138 && ! V_2 -> V_120 && V_2 -> V_107 ) {
ASSERT ( ! V_2 -> V_106 ) ;
V_2 -> V_107 -> V_140 ( V_2 ) ;
}
if ( ! V_2 -> V_120 )
V_2 -> V_7 |= V_115 ;
if ( V_2 -> V_106 )
( * ( V_2 -> V_106 ) ) ( V_2 ) ;
else if ( V_2 -> V_7 & V_10 )
F_73 ( V_2 ) ;
else
F_121 ( & V_2 -> V_39 ) ;
}
static void
F_122 (
struct V_141 * V_142 )
{
struct V_1 * V_2 =
F_123 ( V_142 , T_2 , V_143 ) ;
F_119 ( V_2 ) ;
}
static void
F_124 (
struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_143 , F_122 ) ;
F_126 ( V_2 -> V_144 , & V_2 -> V_143 ) ;
}
void
F_74 (
T_2 * V_2 ,
int error )
{
ASSERT ( error <= 0 && error >= - 1000 ) ;
V_2 -> V_120 = error ;
F_127 ( V_2 , error , V_52 ) ;
}
void
F_128 (
struct V_1 * V_2 ,
const char * V_145 )
{
F_57 ( V_2 -> V_11 -> V_50 ,
L_5 ,
( V_146 ) F_129 ( V_2 ) , V_145 , - V_2 -> V_120 , V_2 -> V_45 ) ;
}
int
F_130 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_8 ( V_2 ) ) ;
V_2 -> V_7 |= V_111 ;
V_2 -> V_7 &= ~ ( V_10 | V_109 | V_14 |
V_147 | V_115 ) ;
error = F_78 ( V_2 ) ;
if ( error ) {
F_131 ( V_2 -> V_11 -> V_50 ,
V_148 ) ;
}
return error ;
}
static void
F_132 (
struct V_149 * V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 -> V_150 ;
if ( V_149 -> V_151 )
F_133 ( & V_2 -> V_139 , 0 , V_149 -> V_151 ) ;
if ( ! V_2 -> V_120 && F_1 ( V_2 ) && ( V_2 -> V_7 & V_109 ) )
F_134 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
if ( F_98 ( & V_2 -> V_152 ) == 1 )
F_124 ( V_2 ) ;
F_135 ( V_149 ) ;
}
static void
F_136 (
struct V_1 * V_2 ,
int V_31 ,
int * V_153 ,
int * V_154 ,
int V_155 ,
int V_156 )
{
int V_157 ;
int V_158 = V_2 -> V_4 ;
int V_159 ;
struct V_149 * V_149 ;
T_8 V_160 = V_2 -> V_23 [ V_31 ] . V_44 ;
int V_60 ;
int V_62 ;
V_158 = V_2 -> V_4 ;
V_157 = 0 ;
V_62 = * V_153 ;
while ( V_62 >= V_5 ) {
V_157 ++ ;
V_62 -= V_5 ;
}
V_60 = F_48 ( int , F_42 ( V_2 -> V_23 [ V_31 ] . V_46 ) , * V_154 ) ;
* V_154 -= V_60 ;
* V_153 += V_60 ;
V_161:
F_62 ( & V_2 -> V_152 ) ;
V_159 = F_137 ( V_158 , V_162 ) ;
V_149 = F_138 ( V_163 , V_159 ) ;
V_149 -> V_164 = V_2 -> V_11 -> V_165 ;
V_149 -> V_166 . V_167 = V_160 ;
V_149 -> V_168 = F_132 ;
V_149 -> V_150 = V_2 ;
F_139 ( V_149 , V_155 , V_156 ) ;
for (; V_60 && V_159 ; V_159 -- , V_157 ++ ) {
int V_169 , V_61 = V_5 - V_62 ;
if ( V_61 > V_60 )
V_61 = V_60 ;
V_169 = F_140 ( V_149 , V_2 -> V_54 [ V_157 ] , V_61 ,
V_62 ) ;
if ( V_169 < V_61 )
break;
V_62 = 0 ;
V_160 += F_91 ( V_61 ) ;
V_60 -= V_61 ;
V_158 -- ;
}
if ( F_71 ( V_149 -> V_166 . V_170 ) ) {
if ( F_1 ( V_2 ) ) {
F_141 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_142 ( V_149 ) ;
if ( V_60 )
goto V_161;
} else {
F_12 ( & V_2 -> V_152 ) ;
F_74 ( V_2 , - V_171 ) ;
F_135 ( V_149 ) ;
}
}
STATIC void
F_143 (
struct V_1 * V_2 )
{
struct V_172 V_173 ;
int V_155 ;
int V_156 = 0 ;
int V_62 ;
int V_60 ;
int V_34 ;
V_2 -> V_120 = 0 ;
if ( ! V_2 -> V_144 )
V_2 -> V_144 = V_2 -> V_11 -> V_50 -> V_174 ;
if ( V_2 -> V_7 & V_111 ) {
V_155 = V_175 ;
if ( V_2 -> V_7 & V_176 )
V_156 = V_177 ;
if ( V_2 -> V_7 & V_178 )
V_156 |= V_179 ;
if ( V_2 -> V_7 & V_180 )
V_156 |= V_181 ;
if ( V_2 -> V_107 ) {
V_2 -> V_107 -> V_182 ( V_2 ) ;
if ( V_2 -> V_120 ) {
F_131 ( V_2 -> V_11 -> V_50 ,
V_183 ) ;
return;
}
} else if ( V_2 -> V_43 != V_112 ) {
struct V_184 * V_185 = V_2 -> V_11 -> V_50 ;
if ( F_144 ( & V_185 -> V_95 ) ) {
F_72 ( V_185 ,
L_6 ,
V_75 , V_2 -> V_43 , V_2 -> V_45 ) ;
F_145 ( V_2 -> V_3 , 64 ) ;
F_146 () ;
}
}
} else if ( V_2 -> V_7 & V_38 ) {
V_155 = V_186 ;
V_156 = V_187 ;
} else {
V_155 = V_186 ;
}
V_156 |= V_188 ;
V_62 = V_2 -> V_6 ;
V_60 = F_42 ( V_2 -> V_47 ) ;
F_147 ( & V_173 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_24 ; V_34 ++ ) {
F_136 ( V_2 , V_34 , & V_62 , & V_60 , V_155 , V_156 ) ;
if ( V_2 -> V_120 )
break;
if ( V_60 <= 0 )
break;
}
F_148 ( & V_173 ) ;
}
void
F_77 (
struct V_1 * V_2 )
{
F_149 ( V_2 , V_52 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_14 ) ) ;
ASSERT ( V_2 -> V_7 & V_10 ) ;
if ( F_150 ( V_2 -> V_11 -> V_50 ) ) {
F_74 ( V_2 , - V_171 ) ;
V_2 -> V_7 &= ~ V_115 ;
F_7 ( V_2 ) ;
F_119 ( V_2 ) ;
return;
}
if ( V_2 -> V_7 & V_111 )
F_113 ( V_2 ) ;
V_2 -> V_139 = 0 ;
F_94 ( V_2 ) ;
F_10 ( & V_2 -> V_152 , 1 ) ;
F_3 ( V_2 ) ;
F_143 ( V_2 ) ;
if ( F_98 ( & V_2 -> V_152 ) == 1 ) {
if ( V_2 -> V_120 )
F_119 ( V_2 ) ;
else
F_124 ( V_2 ) ;
}
F_67 ( V_2 ) ;
}
int
F_78 (
struct V_1 * V_2 )
{
int error ;
F_151 ( V_2 , V_52 ) ;
ASSERT ( ! ( V_2 -> V_7 & ( V_14 | V_10 ) ) ) ;
if ( F_150 ( V_2 -> V_11 -> V_50 ) ) {
F_74 ( V_2 , - V_171 ) ;
F_7 ( V_2 ) ;
V_2 -> V_7 &= ~ V_115 ;
return - V_171 ;
}
if ( V_2 -> V_7 & V_111 )
F_113 ( V_2 ) ;
V_2 -> V_139 = 0 ;
F_94 ( V_2 ) ;
F_10 ( & V_2 -> V_152 , 1 ) ;
F_143 ( V_2 ) ;
if ( F_98 ( & V_2 -> V_152 ) == 1 )
F_119 ( V_2 ) ;
F_152 ( V_2 , V_52 ) ;
F_153 ( & V_2 -> V_39 ) ;
F_154 ( V_2 , V_52 ) ;
error = V_2 -> V_120 ;
F_67 ( V_2 ) ;
return error ;
}
void *
F_155 (
struct V_1 * V_2 ,
T_4 V_62 )
{
struct V_57 * V_57 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_62 ;
V_62 += V_2 -> V_6 ;
V_57 = V_2 -> V_54 [ V_62 >> V_68 ] ;
return F_50 ( V_57 ) + ( V_62 & ( V_5 - 1 ) ) ;
}
void
F_156 (
T_2 * V_2 ,
T_4 V_189 ,
T_4 V_190 ,
void * V_191 ,
T_9 V_192 )
{
T_4 V_193 ;
V_193 = V_189 + V_190 ;
while ( V_189 < V_193 ) {
struct V_57 * V_57 ;
int V_157 , V_194 , V_195 ;
V_157 = ( V_189 + V_2 -> V_6 ) >> V_68 ;
V_194 = ( V_189 + V_2 -> V_6 ) & ~ V_67 ;
V_57 = V_2 -> V_54 [ V_157 ] ;
V_195 = F_48 ( T_4 , V_5 - V_194 ,
F_42 ( V_2 -> V_47 ) - V_189 ) ;
ASSERT ( ( V_195 + V_194 ) <= V_5 ) ;
switch ( V_192 ) {
case V_196 :
memset ( F_50 ( V_57 ) + V_194 , 0 , V_195 ) ;
break;
case V_197 :
memcpy ( V_191 , F_50 ( V_57 ) + V_194 , V_195 ) ;
break;
case V_198 :
memcpy ( F_50 ( V_57 ) + V_194 , V_191 , V_195 ) ;
}
V_189 += V_195 ;
V_191 += V_195 ;
}
}
static enum V_199
F_157 (
struct V_200 * V_201 ,
struct V_202 * V_203 ,
T_10 * V_204 ,
void * V_205 )
{
struct V_1 * V_2 = F_123 ( V_201 , struct V_1 , V_20 ) ;
struct V_200 * V_206 = V_205 ;
if ( F_13 ( & V_2 -> V_21 ) > 1 ) {
F_158 ( V_2 , V_52 ) ;
return V_207 ;
}
if ( ! F_159 ( & V_2 -> V_15 ) )
return V_207 ;
F_10 ( & V_2 -> V_16 , 0 ) ;
V_2 -> V_17 |= V_18 ;
F_160 ( V_203 , V_201 , V_206 ) ;
F_14 ( & V_2 -> V_15 ) ;
return V_208 ;
}
void
F_161 (
struct V_29 * V_83 )
{
F_162 ( V_206 ) ;
int V_209 = 0 ;
while ( F_163 ( & V_83 -> V_12 ) )
F_164 ( 100 ) ;
F_165 ( V_83 -> V_50 -> V_174 ) ;
while ( F_166 ( & V_83 -> V_19 ) ) {
F_167 ( & V_83 -> V_19 , F_157 ,
& V_206 , V_210 ) ;
while ( ! F_37 ( & V_206 ) ) {
struct V_1 * V_2 ;
V_2 = F_168 ( & V_206 , struct V_1 , V_20 ) ;
F_169 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_7 & V_147 ) {
F_57 ( V_83 -> V_50 ,
L_7 ,
( long long ) V_2 -> V_43 ) ;
F_57 ( V_83 -> V_50 ,
L_8 ) ;
}
F_67 ( V_2 ) ;
}
if ( V_209 ++ != 0 )
F_164 ( 100 ) ;
}
}
static enum V_199
F_170 (
struct V_200 * V_201 ,
struct V_202 * V_203 ,
T_10 * V_204 ,
void * V_205 )
{
struct V_1 * V_2 = F_123 ( V_201 , struct V_1 , V_20 ) ;
struct V_200 * V_206 = V_205 ;
if ( ! F_159 ( & V_2 -> V_15 ) )
return V_207 ;
if ( ! F_171 ( & V_2 -> V_16 , - 1 , 0 ) ) {
F_14 ( & V_2 -> V_15 ) ;
return V_211 ;
}
V_2 -> V_17 |= V_18 ;
F_160 ( V_203 , V_201 , V_206 ) ;
F_14 ( & V_2 -> V_15 ) ;
return V_208 ;
}
static unsigned long
F_172 (
struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_29 * V_83 = F_123 ( V_213 ,
struct V_29 , V_216 ) ;
F_162 ( V_206 ) ;
unsigned long V_217 ;
V_217 = F_173 ( & V_83 -> V_19 , V_215 ,
F_170 , & V_206 ) ;
while ( ! F_37 ( & V_206 ) ) {
struct V_1 * V_2 ;
V_2 = F_168 ( & V_206 , struct V_1 , V_20 ) ;
F_169 ( & V_2 -> V_20 ) ;
F_67 ( V_2 ) ;
}
return V_217 ;
}
static unsigned long
F_174 (
struct V_212 * V_213 ,
struct V_214 * V_215 )
{
struct V_29 * V_83 = F_123 ( V_213 ,
struct V_29 , V_216 ) ;
return F_175 ( & V_83 -> V_19 , V_215 ) ;
}
void
F_176 (
struct V_184 * V_185 ,
struct V_29 * V_83 )
{
F_177 ( & V_83 -> V_216 ) ;
ASSERT ( F_163 ( & V_83 -> V_12 ) == 0 ) ;
F_178 ( & V_83 -> V_12 ) ;
F_179 ( & V_83 -> V_19 ) ;
if ( V_185 -> V_218 & V_219 )
F_180 ( V_83 ) ;
F_18 ( V_83 ) ;
}
int
F_181 (
T_11 * V_83 ,
unsigned int V_220 )
{
V_83 -> V_93 = V_220 ;
V_83 -> V_94 = V_220 - 1 ;
if ( F_182 ( V_83 -> V_165 , V_220 ) ) {
F_72 ( V_83 -> V_50 ,
L_9 ,
V_220 , V_83 -> V_165 ) ;
return - V_221 ;
}
V_83 -> V_222 = F_183 ( V_83 -> V_165 ) ;
V_83 -> V_223 = F_183 ( V_83 -> V_165 ) - 1 ;
return 0 ;
}
STATIC int
F_184 (
T_11 * V_83 ,
struct V_224 * V_225 )
{
return F_181 ( V_83 , F_183 ( V_225 ) ) ;
}
T_11 *
F_185 (
struct V_184 * V_185 ,
struct V_224 * V_225 )
{
T_11 * V_83 ;
V_83 = F_16 ( sizeof( * V_83 ) , V_226 | V_27 ) ;
V_83 -> V_50 = V_185 ;
V_83 -> V_227 = V_225 -> V_228 ;
V_83 -> V_165 = V_225 ;
V_83 -> V_117 = F_186 ( V_225 ) ;
if ( F_184 ( V_83 , V_225 ) )
goto error;
if ( F_187 ( & V_83 -> V_19 ) )
goto error;
if ( F_188 ( & V_83 -> V_12 , 0 , V_229 ) )
goto error;
V_83 -> V_216 . V_230 = F_174 ;
V_83 -> V_216 . V_231 = F_172 ;
V_83 -> V_216 . V_232 = V_233 ;
V_83 -> V_216 . V_33 = V_234 ;
F_189 ( & V_83 -> V_216 ) ;
return V_83 ;
error:
F_18 ( V_83 ) ;
return NULL ;
}
bool
F_190 (
struct V_1 * V_2 ,
struct V_200 * V_235 )
{
ASSERT ( F_8 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_7 & V_109 ) ) ;
if ( V_2 -> V_7 & V_14 ) {
F_191 ( V_2 , V_52 ) ;
return false ;
}
F_192 ( V_2 , V_52 ) ;
V_2 -> V_7 |= V_14 ;
if ( F_37 ( & V_2 -> V_40 ) ) {
F_62 ( & V_2 -> V_21 ) ;
F_193 ( & V_2 -> V_40 , V_235 ) ;
}
return true ;
}
static int
F_194 (
void * V_236 ,
struct V_200 * V_237 ,
struct V_200 * V_238 )
{
struct V_1 * V_239 = F_123 ( V_237 , struct V_1 , V_40 ) ;
struct V_1 * V_2 = F_123 ( V_238 , struct V_1 , V_40 ) ;
T_7 V_240 ;
V_240 = V_239 -> V_23 [ 0 ] . V_44 - V_2 -> V_23 [ 0 ] . V_44 ;
if ( V_240 < 0 )
return - 1 ;
if ( V_240 > 0 )
return 1 ;
return 0 ;
}
static int
F_195 (
struct V_200 * V_241 ,
struct V_200 * V_242 )
{
struct V_1 * V_2 , * V_243 ;
F_162 ( V_244 ) ;
int V_245 = 0 ;
struct V_172 V_173 ;
F_196 ( NULL , V_241 , F_194 ) ;
F_147 ( & V_173 ) ;
F_197 (bp, n, buffer_list, b_list) {
if ( ! V_242 ) {
if ( F_198 ( V_2 ) ) {
V_245 ++ ;
continue;
}
if ( ! F_66 ( V_2 ) )
continue;
} else {
F_68 ( V_2 ) ;
}
if ( ! ( V_2 -> V_7 & V_14 ) ) {
F_169 ( & V_2 -> V_40 ) ;
F_73 ( V_2 ) ;
continue;
}
F_199 ( V_2 , V_52 ) ;
V_2 -> V_7 &= ~ ( V_14 | V_147 ) ;
V_2 -> V_7 |= V_111 | V_10 ;
if ( V_242 ) {
F_94 ( V_2 ) ;
F_200 ( & V_2 -> V_40 , V_242 ) ;
} else
F_169 ( & V_2 -> V_40 ) ;
F_77 ( V_2 ) ;
}
F_148 ( & V_173 ) ;
return V_245 ;
}
int
F_201 (
struct V_200 * V_241 )
{
return F_195 ( V_241 , NULL ) ;
}
int
F_202 (
struct V_200 * V_241 )
{
F_162 ( V_242 ) ;
int error = 0 , V_246 ;
struct V_1 * V_2 ;
F_195 ( V_241 , & V_242 ) ;
while ( ! F_37 ( & V_242 ) ) {
V_2 = F_168 ( & V_242 , struct V_1 , V_40 ) ;
F_169 ( & V_2 -> V_40 ) ;
F_68 ( V_2 ) ;
V_246 = V_2 -> V_120 ;
F_73 ( V_2 ) ;
if ( ! error )
error = V_246 ;
}
return error ;
}
int T_12
F_203 ( void )
{
V_35 = F_204 ( sizeof( T_2 ) , L_10 ,
V_247 , NULL ) ;
if ( ! V_35 )
goto V_248;
return 0 ;
V_248:
return - V_28 ;
}
void
F_205 ( void )
{
F_206 ( V_35 ) ;
}
