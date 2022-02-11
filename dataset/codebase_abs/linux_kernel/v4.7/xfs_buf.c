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
return - V_24 ;
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
F_26 ( V_26 -> V_47 , V_48 ) ;
F_27 ( V_2 , V_49 ) ;
return V_2 ;
}
STATIC int
F_28 (
T_2 * V_2 ,
int V_50 )
{
if ( V_2 -> V_51 == NULL ) {
V_2 -> V_4 = V_50 ;
if ( V_50 <= V_52 ) {
V_2 -> V_51 = V_2 -> V_53 ;
} else {
V_2 -> V_51 = F_29 ( sizeof( struct V_54 * ) *
V_50 , V_23 ) ;
if ( V_2 -> V_51 == NULL )
return - V_24 ;
}
memset ( V_2 -> V_51 , 0 , sizeof( struct V_54 * ) * V_50 ) ;
}
return 0 ;
}
STATIC void
F_30 (
T_2 * V_2 )
{
if ( V_2 -> V_51 != V_2 -> V_53 ) {
F_14 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
}
}
void
F_31 (
T_2 * V_2 )
{
F_32 ( V_2 , V_49 ) ;
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
if ( V_2 -> V_7 & V_55 ) {
T_3 V_30 ;
if ( F_1 ( V_2 ) )
F_34 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
struct V_54 * V_54 = V_2 -> V_51 [ V_30 ] ;
F_35 ( V_54 ) ;
}
} else if ( V_2 -> V_7 & V_56 )
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
T_4 V_57 ;
T_4 V_58 , V_59 ;
T_5 V_60 = F_37 ( V_29 ) ;
unsigned short V_50 , V_30 ;
T_6 V_61 , V_62 ;
int error ;
V_57 = F_38 ( V_2 -> V_42 ) ;
if ( V_57 < V_5 ) {
V_2 -> V_3 = F_29 ( V_57 , V_23 ) ;
if ( ! V_2 -> V_3 ) {
goto V_63;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_57 - 1 ) & V_64 ) !=
( ( unsigned long ) V_2 -> V_3 & V_64 ) ) {
F_14 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_63;
}
V_2 -> V_6 = F_39 ( V_2 -> V_3 ) ;
V_2 -> V_51 = V_2 -> V_53 ;
V_2 -> V_51 [ 0 ] = F_40 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_7 |= V_56 ;
return 0 ;
}
V_63:
V_61 = F_38 ( V_2 -> V_19 [ 0 ] . V_41 ) >> V_65 ;
V_62 = ( F_38 ( V_2 -> V_19 [ 0 ] . V_41 + V_2 -> V_42 ) + V_5 - 1 )
>> V_65 ;
V_50 = V_62 - V_61 ;
error = F_28 ( V_2 , V_50 ) ;
if ( F_17 ( error ) )
return error ;
V_59 = V_2 -> V_6 ;
V_2 -> V_7 |= V_55 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
struct V_54 * V_54 ;
T_3 V_66 = 0 ;
V_67:
V_54 = F_41 ( V_60 ) ;
if ( F_17 ( V_54 == NULL ) ) {
if ( V_29 & V_35 ) {
V_2 -> V_4 = V_30 ;
error = - V_24 ;
goto V_68;
}
if ( ! ( ++ V_66 % 100 ) )
F_42 ( NULL ,
L_1 ,
V_69 -> V_70 , V_69 -> V_71 ,
V_72 , V_60 ) ;
F_26 ( V_2 -> V_14 -> V_47 , V_73 ) ;
F_43 ( V_74 , V_75 / 50 ) ;
goto V_67;
}
F_26 ( V_2 -> V_14 -> V_47 , V_76 ) ;
V_58 = F_44 ( T_4 , V_57 , V_5 - V_59 ) ;
V_57 -= V_58 ;
V_2 -> V_51 [ V_30 ] = V_54 ;
V_59 = 0 ;
}
return 0 ;
V_68:
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ )
F_35 ( V_2 -> V_51 [ V_30 ] ) ;
return error ;
}
STATIC int
F_45 (
T_2 * V_2 ,
T_3 V_29 )
{
ASSERT ( V_2 -> V_7 & V_55 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_46 ( V_2 -> V_51 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_29 & V_32 ) {
V_2 -> V_3 = NULL ;
} else {
int V_77 = 0 ;
unsigned V_78 ;
V_78 = F_47 () ;
do {
V_2 -> V_3 = F_48 ( V_2 -> V_51 , V_2 -> V_4 ,
- 1 , V_79 ) ;
if ( V_2 -> V_3 )
break;
F_49 () ;
} while ( V_77 ++ <= 1 );
F_50 ( V_78 ) ;
if ( ! V_2 -> V_3 )
return - V_24 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_2 *
F_51 (
struct V_25 * V_80 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
T_2 * V_81 )
{
struct V_82 * V_83 ;
struct V_84 * * V_85 ;
struct V_84 * V_86 ;
T_2 * V_2 ;
T_7 V_87 = V_27 [ 0 ] . V_41 ;
T_7 V_88 ;
int V_89 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_89 += V_27 [ V_30 ] . V_43 ;
ASSERT ( ! ( F_38 ( V_89 ) < V_80 -> V_90 ) ) ;
ASSERT ( ! ( F_38 ( V_87 ) & ( T_6 ) V_80 -> V_91 ) ) ;
V_88 = F_52 ( V_80 -> V_47 , V_80 -> V_47 -> V_92 . V_93 ) ;
if ( V_87 < 0 || V_87 >= V_88 ) {
F_53 ( V_80 -> V_47 ,
L_2 ,
V_72 , V_87 , V_88 ) ;
F_54 ( 1 ) ;
return NULL ;
}
V_83 = F_55 ( V_80 -> V_47 ,
F_56 ( V_80 -> V_47 , V_87 ) ) ;
F_5 ( & V_83 -> V_94 ) ;
V_85 = & V_83 -> V_95 . V_84 ;
V_86 = NULL ;
V_2 = NULL ;
while ( * V_85 ) {
V_86 = * V_85 ;
V_2 = F_57 ( V_86 , struct V_1 , V_38 ) ;
if ( V_87 < V_2 -> V_40 )
V_85 = & ( * V_85 ) -> V_96 ;
else if ( V_87 > V_2 -> V_40 )
V_85 = & ( * V_85 ) -> V_97 ;
else {
if ( V_2 -> V_42 != V_89 ) {
ASSERT ( V_2 -> V_7 & V_8 ) ;
V_85 = & ( * V_85 ) -> V_97 ;
continue;
}
F_58 ( & V_2 -> V_17 ) ;
goto V_98;
}
}
if ( V_81 ) {
F_59 ( & V_81 -> V_38 , V_86 , V_85 ) ;
F_60 ( & V_81 -> V_38 , & V_83 -> V_95 ) ;
V_81 -> V_99 = V_83 ;
F_10 ( & V_83 -> V_94 ) ;
} else {
F_26 ( V_80 -> V_47 , V_100 ) ;
F_10 ( & V_83 -> V_94 ) ;
F_61 ( V_83 ) ;
}
return V_81 ;
V_98:
F_10 ( & V_83 -> V_94 ) ;
F_61 ( V_83 ) ;
if ( ! F_62 ( V_2 ) ) {
if ( V_29 & V_33 ) {
F_63 ( V_2 ) ;
F_26 ( V_80 -> V_47 , V_101 ) ;
return NULL ;
}
F_64 ( V_2 ) ;
F_26 ( V_80 -> V_47 , V_102 ) ;
}
if ( V_2 -> V_7 & V_8 ) {
ASSERT ( ( V_2 -> V_7 & V_9 ) == 0 ) ;
ASSERT ( V_2 -> V_103 == NULL ) ;
V_2 -> V_7 &= V_56 | V_55 ;
V_2 -> V_104 = NULL ;
}
F_65 ( V_2 , V_29 , V_49 ) ;
F_26 ( V_80 -> V_47 , V_105 ) ;
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
struct V_1 * V_81 ;
int error = 0 ;
V_2 = F_51 ( V_26 , V_27 , V_28 , V_29 , NULL ) ;
if ( F_67 ( V_2 ) )
goto V_98;
V_81 = F_15 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( F_17 ( ! V_81 ) )
return NULL ;
error = F_36 ( V_81 , V_29 ) ;
if ( error ) {
F_31 ( V_81 ) ;
return NULL ;
}
V_2 = F_51 ( V_26 , V_27 , V_28 , V_29 , V_81 ) ;
if ( ! V_2 ) {
F_31 ( V_81 ) ;
return NULL ;
}
if ( V_2 != V_81 )
F_31 ( V_81 ) ;
V_98:
if ( ! V_2 -> V_3 ) {
error = F_45 ( V_2 , V_29 ) ;
if ( F_17 ( error ) ) {
F_68 ( V_26 -> V_47 ,
L_3 , V_72 ) ;
F_69 ( V_2 ) ;
return NULL ;
}
}
if ( ! ( V_29 & V_106 ) )
F_70 ( V_2 , 0 ) ;
F_26 ( V_26 -> V_47 , V_107 ) ;
F_71 ( V_2 , V_29 , V_49 ) ;
return V_2 ;
}
STATIC int
F_72 (
T_2 * V_2 ,
T_1 V_29 )
{
ASSERT ( ! ( V_29 & V_108 ) ) ;
ASSERT ( V_2 -> V_19 [ 0 ] . V_41 != V_109 ) ;
V_2 -> V_7 &= ~ ( V_108 | V_34 | V_35 ) ;
V_2 -> V_7 |= V_29 & ( V_106 | V_34 | V_35 ) ;
if ( V_29 & V_34 ) {
F_73 ( V_2 ) ;
return 0 ;
}
return F_74 ( V_2 ) ;
}
T_2 *
F_75 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
const struct V_110 * V_111 )
{
struct V_1 * V_2 ;
V_29 |= V_106 ;
V_2 = F_66 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( V_2 ) {
F_76 ( V_2 , V_29 , V_49 ) ;
if ( ! ( V_2 -> V_7 & V_112 ) ) {
F_26 ( V_26 -> V_47 , V_113 ) ;
V_2 -> V_104 = V_111 ;
F_72 ( V_2 , V_29 ) ;
} else if ( V_29 & V_34 ) {
F_69 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_7 &= ~ V_106 ;
}
}
return V_2 ;
}
void
F_77 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
const struct V_110 * V_111 )
{
if ( F_78 ( V_26 -> V_114 ) )
return;
F_75 ( V_26 , V_27 , V_28 ,
V_33 | V_34 | V_35 , V_111 ) ;
}
int
F_79 (
struct V_25 * V_26 ,
T_7 V_115 ,
T_4 V_89 ,
int V_29 ,
struct V_1 * * V_116 ,
const struct V_110 * V_111 )
{
struct V_1 * V_2 ;
* V_116 = NULL ;
V_2 = F_80 ( V_26 , V_89 , V_29 ) ;
if ( ! V_2 )
return - V_24 ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_109 ;
V_2 -> V_19 [ 0 ] . V_41 = V_115 ;
V_2 -> V_7 |= V_106 ;
V_2 -> V_104 = V_111 ;
F_74 ( V_2 ) ;
if ( V_2 -> V_117 ) {
int error = V_2 -> V_117 ;
F_69 ( V_2 ) ;
return error ;
}
* V_116 = V_2 ;
return 0 ;
}
void
F_81 (
struct V_1 * V_2 ,
T_4 V_89 )
{
if ( V_2 -> V_51 )
F_30 ( V_2 ) ;
V_2 -> V_51 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_42 = V_89 ;
V_2 -> V_44 = V_89 ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_109 ;
V_2 -> V_19 [ 0 ] . V_41 = V_109 ;
V_2 -> V_19 [ 0 ] . V_43 = V_2 -> V_42 ;
}
static inline struct V_54 *
F_82 (
void * V_118 )
{
if ( ( ! F_83 ( V_118 ) ) ) {
return F_40 ( V_118 ) ;
} else {
return F_84 ( V_118 ) ;
}
}
int
F_85 (
T_2 * V_2 ,
void * V_119 ,
T_4 V_120 )
{
int V_121 ;
int V_30 = 0 ;
unsigned long V_122 ;
unsigned long V_59 ;
T_4 V_123 ;
int V_50 ;
V_122 = ( unsigned long ) V_119 & V_64 ;
V_59 = ( unsigned long ) V_119 - V_122 ;
V_123 = F_86 ( V_120 + V_59 ) ;
V_50 = V_123 >> V_65 ;
if ( V_2 -> V_51 )
F_30 ( V_2 ) ;
V_2 -> V_51 = NULL ;
V_2 -> V_3 = V_119 ;
V_121 = F_28 ( V_2 , V_50 ) ;
if ( V_121 )
return V_121 ;
V_2 -> V_6 = V_59 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
V_2 -> V_51 [ V_30 ] = F_82 ( ( void * ) V_122 ) ;
V_122 += V_5 ;
}
V_2 -> V_44 = F_87 ( V_120 ) ;
V_2 -> V_42 = F_87 ( V_123 ) ;
return 0 ;
}
T_2 *
F_80 (
struct V_25 * V_26 ,
T_4 V_89 ,
int V_29 )
{
unsigned long V_50 ;
int error , V_30 ;
struct V_1 * V_2 ;
F_88 ( V_27 , V_109 , V_89 ) ;
V_2 = F_15 ( V_26 , & V_27 , 1 , 0 ) ;
if ( F_17 ( V_2 == NULL ) )
goto V_124;
V_50 = F_86 ( V_89 << V_125 ) >> V_65 ;
error = F_28 ( V_2 , V_50 ) ;
if ( error )
goto V_126;
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
V_2 -> V_51 [ V_30 ] = F_41 ( F_37 ( V_29 ) ) ;
if ( ! V_2 -> V_51 [ V_30 ] )
goto V_127;
}
V_2 -> V_7 |= V_55 ;
error = F_45 ( V_2 , 0 ) ;
if ( F_17 ( error ) ) {
F_68 ( V_26 -> V_47 ,
L_4 , V_72 ) ;
goto V_127;
}
F_89 ( V_2 , V_49 ) ;
return V_2 ;
V_127:
while ( -- V_30 >= 0 )
F_35 ( V_2 -> V_51 [ V_30 ] ) ;
F_30 ( V_2 ) ;
V_126:
F_13 ( V_2 ) ;
F_24 ( V_31 , V_2 ) ;
V_124:
return NULL ;
}
void
F_90 (
T_2 * V_2 )
{
F_91 ( V_2 , V_49 ) ;
F_58 ( & V_2 -> V_17 ) ;
}
void
F_63 (
T_2 * V_2 )
{
struct V_82 * V_83 = V_2 -> V_99 ;
F_92 ( V_2 , V_49 ) ;
if ( ! V_83 ) {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
ASSERT ( F_93 ( & V_2 -> V_38 ) ) ;
if ( F_94 ( & V_2 -> V_17 ) )
F_31 ( V_2 ) ;
return;
}
ASSERT ( ! F_93 ( & V_2 -> V_38 ) ) ;
ASSERT ( F_9 ( & V_2 -> V_17 ) > 0 ) ;
if ( F_95 ( & V_2 -> V_17 , & V_83 -> V_94 ) ) {
F_5 ( & V_2 -> V_10 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) && F_9 ( & V_2 -> V_11 ) ) {
if ( F_96 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ) {
V_2 -> V_12 &= ~ V_13 ;
F_58 ( & V_2 -> V_17 ) ;
}
F_10 ( & V_2 -> V_10 ) ;
F_10 ( & V_83 -> V_94 ) ;
} else {
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_7 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ;
} else {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
}
F_10 ( & V_2 -> V_10 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
F_97 ( & V_2 -> V_38 , & V_83 -> V_95 ) ;
F_10 ( & V_83 -> V_94 ) ;
F_61 ( V_83 ) ;
F_31 ( V_2 ) ;
}
}
}
int
F_62 (
struct V_1 * V_2 )
{
int V_128 ;
V_128 = F_98 ( & V_2 -> V_39 ) == 0 ;
if ( V_128 )
F_23 ( V_2 ) ;
F_99 ( V_2 , V_49 ) ;
return V_128 ;
}
void
F_64 (
struct V_1 * V_2 )
{
F_100 ( V_2 , V_49 ) ;
if ( F_9 ( & V_2 -> V_45 ) && ( V_2 -> V_7 & V_8 ) )
F_101 ( V_2 -> V_14 -> V_47 , 0 ) ;
F_102 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
F_103 ( V_2 , V_49 ) ;
}
void
F_104 (
struct V_1 * V_2 )
{
F_105 ( V_2 ) ;
F_106 ( & V_2 -> V_39 ) ;
F_107 ( V_2 , V_49 ) ;
}
STATIC void
F_108 (
T_2 * V_2 )
{
F_109 ( V_129 , V_69 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
return;
F_110 ( & V_2 -> V_46 , & V_129 ) ;
for (; ; ) {
F_111 ( V_130 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
break;
F_112 () ;
}
F_113 ( & V_2 -> V_46 , & V_129 ) ;
F_111 ( V_131 ) ;
}
void
F_114 (
struct V_1 * V_2 )
{
bool V_132 = V_2 -> V_7 & V_106 ;
F_115 ( V_2 , V_49 ) ;
V_2 -> V_7 &= ~ ( V_106 | V_108 | V_35 ) ;
if ( ! V_2 -> V_117 && V_2 -> V_133 )
F_70 ( V_2 , V_2 -> V_133 ) ;
if ( V_132 && ! V_2 -> V_117 && V_2 -> V_104 ) {
ASSERT ( ! V_2 -> V_103 ) ;
V_2 -> V_104 -> V_134 ( V_2 ) ;
}
if ( ! V_2 -> V_117 )
V_2 -> V_7 |= V_112 ;
if ( V_2 -> V_103 )
( * ( V_2 -> V_103 ) ) ( V_2 ) ;
else if ( V_2 -> V_7 & V_34 )
F_69 ( V_2 ) ;
else
F_116 ( & V_2 -> V_36 ) ;
}
static void
F_117 (
struct V_135 * V_136 )
{
struct V_1 * V_2 =
F_118 ( V_136 , T_2 , V_137 ) ;
F_114 ( V_2 ) ;
}
static void
F_119 (
struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_137 , F_117 ) ;
F_121 ( V_2 -> V_138 , & V_2 -> V_137 ) ;
}
void
F_70 (
T_2 * V_2 ,
int error )
{
ASSERT ( error <= 0 && error >= - 1000 ) ;
V_2 -> V_117 = error ;
F_122 ( V_2 , error , V_49 ) ;
}
void
F_123 (
struct V_1 * V_2 ,
const char * V_139 )
{
F_53 ( V_2 -> V_14 -> V_47 ,
L_5 ,
( V_140 ) F_124 ( V_2 ) , V_139 , - V_2 -> V_117 , V_2 -> V_42 ) ;
}
int
F_125 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_4 ( V_2 ) ) ;
V_2 -> V_7 |= V_108 ;
V_2 -> V_7 &= ~ ( V_34 | V_106 | V_9 |
V_141 | V_112 ) ;
error = F_74 ( V_2 ) ;
if ( error ) {
F_126 ( V_2 -> V_14 -> V_47 ,
V_142 ) ;
}
return error ;
}
static void
F_127 (
struct V_143 * V_143 )
{
struct V_1 * V_2 = (struct V_1 * ) V_143 -> V_144 ;
if ( V_143 -> V_145 )
F_128 ( & V_2 -> V_133 , 0 , V_143 -> V_145 ) ;
if ( ! V_2 -> V_117 && F_1 ( V_2 ) && ( V_2 -> V_7 & V_106 ) )
F_129 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
if ( F_94 ( & V_2 -> V_146 ) == 1 )
F_119 ( V_2 ) ;
F_130 ( V_143 ) ;
}
static void
F_131 (
struct V_1 * V_2 ,
int V_27 ,
int * V_147 ,
int * V_148 ,
int V_149 )
{
int V_150 ;
int V_151 = V_2 -> V_4 ;
int V_152 ;
struct V_143 * V_143 ;
T_8 V_153 = V_2 -> V_19 [ V_27 ] . V_41 ;
int V_57 ;
int V_59 ;
V_151 = V_2 -> V_4 ;
V_150 = 0 ;
V_59 = * V_147 ;
while ( V_59 >= V_5 ) {
V_150 ++ ;
V_59 -= V_5 ;
}
V_57 = F_44 ( int , F_38 ( V_2 -> V_19 [ V_27 ] . V_43 ) , * V_148 ) ;
* V_148 -= V_57 ;
* V_147 += V_57 ;
V_154:
F_58 ( & V_2 -> V_146 ) ;
V_152 = V_155 >> ( V_65 - V_125 ) ;
if ( V_152 > V_151 )
V_152 = V_151 ;
V_143 = F_132 ( V_156 , V_152 ) ;
V_143 -> V_157 = V_2 -> V_14 -> V_158 ;
V_143 -> V_159 . V_160 = V_153 ;
V_143 -> V_161 = F_127 ;
V_143 -> V_144 = V_2 ;
for (; V_57 && V_152 ; V_152 -- , V_150 ++ ) {
int V_162 , V_58 = V_5 - V_59 ;
if ( V_58 > V_57 )
V_58 = V_57 ;
V_162 = F_133 ( V_143 , V_2 -> V_51 [ V_150 ] , V_58 ,
V_59 ) ;
if ( V_162 < V_58 )
break;
V_59 = 0 ;
V_153 += F_87 ( V_58 ) ;
V_57 -= V_58 ;
V_151 -- ;
}
if ( F_67 ( V_143 -> V_159 . V_163 ) ) {
if ( F_1 ( V_2 ) ) {
F_134 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_135 ( V_149 , V_143 ) ;
if ( V_57 )
goto V_154;
} else {
F_8 ( & V_2 -> V_146 ) ;
F_70 ( V_2 , - V_164 ) ;
F_130 ( V_143 ) ;
}
}
STATIC void
F_136 (
struct V_1 * V_2 )
{
struct V_165 V_166 ;
int V_149 ;
int V_59 ;
int V_57 ;
int V_30 ;
V_2 -> V_117 = 0 ;
if ( ! V_2 -> V_138 )
V_2 -> V_138 = V_2 -> V_14 -> V_47 -> V_167 ;
if ( V_2 -> V_7 & V_108 ) {
if ( V_2 -> V_7 & V_168 )
V_149 = V_169 ;
else
V_149 = V_170 ;
if ( V_2 -> V_7 & V_171 )
V_149 |= V_172 ;
if ( V_2 -> V_7 & V_173 )
V_149 |= V_174 ;
if ( V_2 -> V_104 ) {
V_2 -> V_104 -> V_175 ( V_2 ) ;
if ( V_2 -> V_117 ) {
F_126 ( V_2 -> V_14 -> V_47 ,
V_176 ) ;
return;
}
} else if ( V_2 -> V_40 != V_109 ) {
struct V_177 * V_178 = V_2 -> V_14 -> V_47 ;
if ( F_137 ( & V_178 -> V_92 ) ) {
F_68 ( V_178 ,
L_6 ,
V_72 , V_2 -> V_40 , V_2 -> V_42 ) ;
F_138 ( V_2 -> V_3 , 64 ) ;
F_139 () ;
}
}
} else if ( V_2 -> V_7 & V_35 ) {
V_149 = V_179 ;
} else {
V_149 = V_180 ;
}
V_149 |= V_181 ;
V_59 = V_2 -> V_6 ;
V_57 = F_38 ( V_2 -> V_44 ) ;
F_140 ( & V_166 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_20 ; V_30 ++ ) {
F_131 ( V_2 , V_30 , & V_59 , & V_57 , V_149 ) ;
if ( V_2 -> V_117 )
break;
if ( V_57 <= 0 )
break;
}
F_141 ( & V_166 ) ;
}
void
F_73 (
struct V_1 * V_2 )
{
F_142 ( V_2 , V_49 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
ASSERT ( V_2 -> V_7 & V_34 ) ;
if ( F_143 ( V_2 -> V_14 -> V_47 ) ) {
F_70 ( V_2 , - V_164 ) ;
V_2 -> V_7 &= ~ V_112 ;
F_3 ( V_2 ) ;
F_114 ( V_2 ) ;
return;
}
if ( V_2 -> V_7 & V_108 )
F_108 ( V_2 ) ;
V_2 -> V_133 = 0 ;
F_90 ( V_2 ) ;
F_6 ( & V_2 -> V_146 , 1 ) ;
F_136 ( V_2 ) ;
if ( F_94 ( & V_2 -> V_146 ) == 1 ) {
if ( V_2 -> V_117 )
F_114 ( V_2 ) ;
else
F_119 ( V_2 ) ;
}
F_63 ( V_2 ) ;
}
int
F_74 (
struct V_1 * V_2 )
{
int error ;
F_144 ( V_2 , V_49 ) ;
ASSERT ( ! ( V_2 -> V_7 & ( V_9 | V_34 ) ) ) ;
if ( F_143 ( V_2 -> V_14 -> V_47 ) ) {
F_70 ( V_2 , - V_164 ) ;
F_3 ( V_2 ) ;
V_2 -> V_7 &= ~ V_112 ;
return - V_164 ;
}
if ( V_2 -> V_7 & V_108 )
F_108 ( V_2 ) ;
V_2 -> V_133 = 0 ;
F_90 ( V_2 ) ;
F_6 ( & V_2 -> V_146 , 1 ) ;
F_136 ( V_2 ) ;
if ( F_94 ( & V_2 -> V_146 ) == 1 )
F_114 ( V_2 ) ;
F_145 ( V_2 , V_49 ) ;
F_146 ( & V_2 -> V_36 ) ;
F_147 ( V_2 , V_49 ) ;
error = V_2 -> V_117 ;
F_63 ( V_2 ) ;
return error ;
}
void *
F_148 (
struct V_1 * V_2 ,
T_4 V_59 )
{
struct V_54 * V_54 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_59 ;
V_59 += V_2 -> V_6 ;
V_54 = V_2 -> V_51 [ V_59 >> V_65 ] ;
return F_46 ( V_54 ) + ( V_59 & ( V_5 - 1 ) ) ;
}
void
F_149 (
T_2 * V_2 ,
T_4 V_182 ,
T_4 V_183 ,
void * V_184 ,
T_9 V_185 )
{
T_4 V_186 ;
V_186 = V_182 + V_183 ;
while ( V_182 < V_186 ) {
struct V_54 * V_54 ;
int V_150 , V_187 , V_188 ;
V_150 = ( V_182 + V_2 -> V_6 ) >> V_65 ;
V_187 = ( V_182 + V_2 -> V_6 ) & ~ V_64 ;
V_54 = V_2 -> V_51 [ V_150 ] ;
V_188 = F_44 ( T_4 , V_5 - V_187 ,
F_38 ( V_2 -> V_44 ) - V_182 ) ;
ASSERT ( ( V_188 + V_187 ) <= V_5 ) ;
switch ( V_185 ) {
case V_189 :
memset ( F_46 ( V_54 ) + V_187 , 0 , V_188 ) ;
break;
case V_190 :
memcpy ( V_184 , F_46 ( V_54 ) + V_187 , V_188 ) ;
break;
case V_191 :
memcpy ( F_46 ( V_54 ) + V_187 , V_184 , V_188 ) ;
}
V_182 += V_188 ;
V_184 += V_188 ;
}
}
static enum V_192
F_150 (
struct V_193 * V_194 ,
struct V_195 * V_196 ,
T_10 * V_197 ,
void * V_198 )
{
struct V_1 * V_2 = F_118 ( V_194 , struct V_1 , V_16 ) ;
struct V_193 * V_199 = V_198 ;
if ( F_9 ( & V_2 -> V_17 ) > 1 ) {
F_151 ( V_2 , V_49 ) ;
return V_200 ;
}
if ( ! F_152 ( & V_2 -> V_10 ) )
return V_200 ;
F_6 ( & V_2 -> V_11 , 0 ) ;
V_2 -> V_12 |= V_13 ;
F_153 ( V_196 , V_194 , V_199 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_201 ;
}
void
F_154 (
struct V_25 * V_80 )
{
F_155 ( V_199 ) ;
int V_202 = 0 ;
F_156 ( V_80 -> V_47 -> V_167 ) ;
while ( F_157 ( & V_80 -> V_15 ) ) {
F_158 ( & V_80 -> V_15 , F_150 ,
& V_199 , V_203 ) ;
while ( ! F_33 ( & V_199 ) ) {
struct V_1 * V_2 ;
V_2 = F_159 ( & V_199 , struct V_1 , V_16 ) ;
F_160 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_7 & V_141 ) {
F_53 ( V_80 -> V_47 ,
L_7 ,
( long long ) V_2 -> V_40 ) ;
F_53 ( V_80 -> V_47 ,
L_8 ) ;
}
F_63 ( V_2 ) ;
}
if ( V_202 ++ != 0 )
F_161 ( 100 ) ;
}
}
static enum V_192
F_162 (
struct V_193 * V_194 ,
struct V_195 * V_196 ,
T_10 * V_197 ,
void * V_198 )
{
struct V_1 * V_2 = F_118 ( V_194 , struct V_1 , V_16 ) ;
struct V_193 * V_199 = V_198 ;
if ( ! F_152 ( & V_2 -> V_10 ) )
return V_200 ;
if ( ! F_163 ( & V_2 -> V_11 , - 1 , 0 ) ) {
F_10 ( & V_2 -> V_10 ) ;
return V_204 ;
}
V_2 -> V_12 |= V_13 ;
F_153 ( V_196 , V_194 , V_199 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_201 ;
}
static unsigned long
F_164 (
struct V_205 * V_206 ,
struct V_207 * V_208 )
{
struct V_25 * V_80 = F_118 ( V_206 ,
struct V_25 , V_209 ) ;
F_155 ( V_199 ) ;
unsigned long V_210 ;
V_210 = F_165 ( & V_80 -> V_15 , V_208 ,
F_162 , & V_199 ) ;
while ( ! F_33 ( & V_199 ) ) {
struct V_1 * V_2 ;
V_2 = F_159 ( & V_199 , struct V_1 , V_16 ) ;
F_160 ( & V_2 -> V_16 ) ;
F_63 ( V_2 ) ;
}
return V_210 ;
}
static unsigned long
F_166 (
struct V_205 * V_206 ,
struct V_207 * V_208 )
{
struct V_25 * V_80 = F_118 ( V_206 ,
struct V_25 , V_209 ) ;
return F_167 ( & V_80 -> V_15 , V_208 ) ;
}
void
F_168 (
struct V_177 * V_178 ,
struct V_25 * V_80 )
{
F_169 ( & V_80 -> V_209 ) ;
F_170 ( & V_80 -> V_15 ) ;
if ( V_178 -> V_211 & V_212 )
F_171 ( V_80 ) ;
F_14 ( V_80 ) ;
}
int
F_172 (
T_11 * V_80 ,
unsigned int V_213 )
{
V_80 -> V_90 = V_213 ;
V_80 -> V_91 = V_213 - 1 ;
if ( F_173 ( V_80 -> V_158 , V_213 ) ) {
F_68 ( V_80 -> V_47 ,
L_9 ,
V_213 , V_80 -> V_158 ) ;
return - V_214 ;
}
V_80 -> V_215 = F_174 ( V_80 -> V_158 ) ;
V_80 -> V_216 = F_174 ( V_80 -> V_158 ) - 1 ;
return 0 ;
}
STATIC int
F_175 (
T_11 * V_80 ,
struct V_217 * V_218 )
{
return F_172 ( V_80 , F_174 ( V_218 ) ) ;
}
T_11 *
F_176 (
struct V_177 * V_178 ,
struct V_217 * V_218 )
{
T_11 * V_80 ;
V_80 = F_12 ( sizeof( * V_80 ) , V_219 | V_23 ) ;
V_80 -> V_47 = V_178 ;
V_80 -> V_220 = V_218 -> V_221 ;
V_80 -> V_158 = V_218 ;
V_80 -> V_114 = F_177 ( V_218 ) ;
if ( F_175 ( V_80 , V_218 ) )
goto error;
if ( F_178 ( & V_80 -> V_15 ) )
goto error;
V_80 -> V_209 . V_222 = F_166 ;
V_80 -> V_209 . V_223 = F_164 ;
V_80 -> V_209 . V_224 = V_225 ;
V_80 -> V_209 . V_29 = V_226 ;
F_179 ( & V_80 -> V_209 ) ;
return V_80 ;
error:
F_14 ( V_80 ) ;
return NULL ;
}
bool
F_180 (
struct V_1 * V_2 ,
struct V_193 * V_227 )
{
ASSERT ( F_4 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_7 & V_106 ) ) ;
if ( V_2 -> V_7 & V_9 ) {
F_181 ( V_2 , V_49 ) ;
return false ;
}
F_182 ( V_2 , V_49 ) ;
V_2 -> V_7 |= V_9 ;
if ( F_33 ( & V_2 -> V_37 ) ) {
F_58 ( & V_2 -> V_17 ) ;
F_183 ( & V_2 -> V_37 , V_227 ) ;
}
return true ;
}
static int
F_184 (
void * V_228 ,
struct V_193 * V_229 ,
struct V_193 * V_230 )
{
struct V_1 * V_231 = F_118 ( V_229 , struct V_1 , V_37 ) ;
struct V_1 * V_2 = F_118 ( V_230 , struct V_1 , V_37 ) ;
T_7 V_232 ;
V_232 = V_231 -> V_19 [ 0 ] . V_41 - V_2 -> V_19 [ 0 ] . V_41 ;
if ( V_232 < 0 )
return - 1 ;
if ( V_232 > 0 )
return 1 ;
return 0 ;
}
static int
F_185 (
struct V_193 * V_233 ,
struct V_193 * V_234 ,
bool V_129 )
{
struct V_165 V_166 ;
struct V_1 * V_2 , * V_235 ;
int V_236 = 0 ;
F_186 (bp, n, buffer_list, b_list) {
if ( ! V_129 ) {
if ( F_187 ( V_2 ) ) {
V_236 ++ ;
continue;
}
if ( ! F_62 ( V_2 ) )
continue;
} else {
F_64 ( V_2 ) ;
}
if ( ! ( V_2 -> V_7 & V_9 ) ) {
F_160 ( & V_2 -> V_37 ) ;
F_69 ( V_2 ) ;
continue;
}
F_188 ( & V_2 -> V_37 , V_234 ) ;
F_189 ( V_2 , V_49 ) ;
}
F_190 ( NULL , V_234 , F_184 ) ;
F_140 ( & V_166 ) ;
F_186 (bp, n, io_list, b_list) {
V_2 -> V_7 &= ~ ( V_9 | V_34 | V_141 ) ;
V_2 -> V_7 |= V_108 | V_34 ;
if ( V_129 )
F_90 ( V_2 ) ;
else
F_160 ( & V_2 -> V_37 ) ;
F_73 ( V_2 ) ;
}
F_141 ( & V_166 ) ;
return V_236 ;
}
int
F_191 (
struct V_193 * V_233 )
{
F_155 ( V_234 ) ;
return F_185 ( V_233 , & V_234 , false ) ;
}
int
F_192 (
struct V_193 * V_233 )
{
F_155 ( V_234 ) ;
int error = 0 , V_237 ;
struct V_1 * V_2 ;
F_185 ( V_233 , & V_234 , true ) ;
while ( ! F_33 ( & V_234 ) ) {
V_2 = F_159 ( & V_234 , struct V_1 , V_37 ) ;
F_160 ( & V_2 -> V_37 ) ;
F_64 ( V_2 ) ;
V_237 = V_2 -> V_117 ;
F_69 ( V_2 ) ;
if ( ! error )
error = V_237 ;
}
return error ;
}
int T_12
F_193 ( void )
{
V_31 = F_194 ( sizeof( T_2 ) , L_10 ,
V_238 , NULL ) ;
if ( ! V_31 )
goto V_239;
return 0 ;
V_239:
return - V_24 ;
}
void
F_195 ( void )
{
F_196 ( V_31 ) ;
}
