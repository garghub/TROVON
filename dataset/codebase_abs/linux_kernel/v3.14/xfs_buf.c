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
do {
V_2 -> V_3 = F_47 ( V_2 -> V_50 , V_2 -> V_4 ,
- 1 , V_74 ) ;
if ( V_2 -> V_3 )
break;
F_48 () ;
} while ( V_73 ++ <= 1 );
if ( ! V_2 -> V_3 )
return - V_24 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_2 *
F_49 (
struct V_25 * V_75 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
T_2 * V_76 )
{
T_4 V_77 ;
struct V_78 * V_79 ;
struct V_80 * * V_81 ;
struct V_80 * V_82 ;
T_2 * V_2 ;
T_7 V_83 = V_27 [ 0 ] . V_41 ;
T_7 V_84 ;
int V_85 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_85 += V_27 [ V_30 ] . V_43 ;
V_77 = F_38 ( V_85 ) ;
ASSERT ( ! ( V_77 < V_75 -> V_86 ) ) ;
ASSERT ( ! ( F_38 ( V_83 ) & ( T_6 ) V_75 -> V_87 ) ) ;
V_84 = F_50 ( V_75 -> V_88 , V_75 -> V_88 -> V_89 . V_90 ) ;
if ( V_83 >= V_84 ) {
F_51 ( V_75 -> V_88 ,
L_2 ,
V_68 , V_83 , V_84 ) ;
F_52 ( 1 ) ;
return NULL ;
}
V_79 = F_53 ( V_75 -> V_88 ,
F_54 ( V_75 -> V_88 , V_83 ) ) ;
F_5 ( & V_79 -> V_91 ) ;
V_81 = & V_79 -> V_92 . V_80 ;
V_82 = NULL ;
V_2 = NULL ;
while ( * V_81 ) {
V_82 = * V_81 ;
V_2 = F_55 ( V_82 , struct V_1 , V_38 ) ;
if ( V_83 < V_2 -> V_40 )
V_81 = & ( * V_81 ) -> V_93 ;
else if ( V_83 > V_2 -> V_40 )
V_81 = & ( * V_81 ) -> V_94 ;
else {
if ( V_2 -> V_42 != V_85 ) {
ASSERT ( V_2 -> V_7 & V_8 ) ;
V_81 = & ( * V_81 ) -> V_94 ;
continue;
}
F_56 ( & V_2 -> V_17 ) ;
goto V_95;
}
}
if ( V_76 ) {
F_57 ( & V_76 -> V_38 , V_82 , V_81 ) ;
F_58 ( & V_76 -> V_38 , & V_79 -> V_92 ) ;
V_76 -> V_96 = V_79 ;
F_10 ( & V_79 -> V_91 ) ;
} else {
F_26 ( V_97 ) ;
F_10 ( & V_79 -> V_91 ) ;
F_59 ( V_79 ) ;
}
return V_76 ;
V_95:
F_10 ( & V_79 -> V_91 ) ;
F_59 ( V_79 ) ;
if ( ! F_60 ( V_2 ) ) {
if ( V_29 & V_33 ) {
F_61 ( V_2 ) ;
F_26 ( V_98 ) ;
return NULL ;
}
F_62 ( V_2 ) ;
F_26 ( V_99 ) ;
}
if ( V_2 -> V_7 & V_8 ) {
ASSERT ( ( V_2 -> V_7 & V_9 ) == 0 ) ;
ASSERT ( V_2 -> V_100 == NULL ) ;
V_2 -> V_7 &= V_55 | V_54 ;
V_2 -> V_101 = NULL ;
}
F_63 ( V_2 , V_29 , V_48 ) ;
F_26 ( V_102 ) ;
return V_2 ;
}
struct V_1 *
F_64 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 )
{
struct V_1 * V_2 ;
struct V_1 * V_76 ;
int error = 0 ;
V_2 = F_49 ( V_26 , V_27 , V_28 , V_29 , NULL ) ;
if ( F_65 ( V_2 ) )
goto V_95;
V_76 = F_15 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( F_17 ( ! V_76 ) )
return NULL ;
error = F_36 ( V_76 , V_29 ) ;
if ( error ) {
F_31 ( V_76 ) ;
return NULL ;
}
V_2 = F_49 ( V_26 , V_27 , V_28 , V_29 , V_76 ) ;
if ( ! V_2 ) {
F_31 ( V_76 ) ;
return NULL ;
}
if ( V_2 != V_76 )
F_31 ( V_76 ) ;
V_95:
if ( ! V_2 -> V_3 ) {
error = F_45 ( V_2 , V_29 ) ;
if ( F_17 ( error ) ) {
F_66 ( V_26 -> V_88 ,
L_3 , V_68 ) ;
F_67 ( V_2 ) ;
return NULL ;
}
}
F_26 ( V_103 ) ;
F_68 ( V_2 , V_29 , V_48 ) ;
return V_2 ;
}
STATIC int
F_69 (
T_2 * V_2 ,
T_1 V_29 )
{
ASSERT ( ! ( V_29 & V_104 ) ) ;
ASSERT ( V_2 -> V_19 [ 0 ] . V_41 != V_105 ) ;
V_2 -> V_7 &= ~ ( V_104 | V_34 | V_35 ) ;
V_2 -> V_7 |= V_29 & ( V_106 | V_34 | V_35 ) ;
F_70 ( V_2 ) ;
if ( V_29 & V_34 )
return 0 ;
return F_71 ( V_2 ) ;
}
T_2 *
F_72 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
T_1 V_29 ,
const struct V_107 * V_108 )
{
struct V_1 * V_2 ;
V_29 |= V_106 ;
V_2 = F_64 ( V_26 , V_27 , V_28 , V_29 ) ;
if ( V_2 ) {
F_73 ( V_2 , V_29 , V_48 ) ;
if ( ! F_74 ( V_2 ) ) {
F_26 ( V_109 ) ;
V_2 -> V_101 = V_108 ;
F_69 ( V_2 , V_29 ) ;
} else if ( V_29 & V_34 ) {
F_67 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_7 &= ~ V_106 ;
}
}
return V_2 ;
}
void
F_75 (
struct V_25 * V_26 ,
struct V_22 * V_27 ,
int V_28 ,
const struct V_107 * V_108 )
{
if ( F_76 ( V_26 -> V_110 ) )
return;
F_72 ( V_26 , V_27 , V_28 ,
V_33 | V_34 | V_35 , V_108 ) ;
}
struct V_1 *
F_77 (
struct V_25 * V_26 ,
T_7 V_111 ,
T_4 V_85 ,
int V_29 ,
const struct V_107 * V_108 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_26 , V_85 , V_29 ) ;
if ( ! V_2 )
return NULL ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_111 ;
V_2 -> V_19 [ 0 ] . V_41 = V_111 ;
V_2 -> V_7 |= V_106 ;
V_2 -> V_101 = V_108 ;
if ( F_79 ( V_26 -> V_88 ) ) {
F_67 ( V_2 ) ;
return NULL ;
}
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
return V_2 ;
}
void
F_80 (
struct V_1 * V_2 ,
T_4 V_85 )
{
if ( V_2 -> V_50 )
F_30 ( V_2 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_42 = V_85 ;
V_2 -> V_44 = V_85 ;
ASSERT ( V_2 -> V_20 == 1 ) ;
V_2 -> V_40 = V_105 ;
V_2 -> V_19 [ 0 ] . V_41 = V_105 ;
V_2 -> V_19 [ 0 ] . V_43 = V_2 -> V_42 ;
}
static inline struct V_53 *
F_81 (
void * V_112 )
{
if ( ( ! F_82 ( V_112 ) ) ) {
return F_40 ( V_112 ) ;
} else {
return F_83 ( V_112 ) ;
}
}
int
F_84 (
T_2 * V_2 ,
void * V_113 ,
T_4 V_114 )
{
int V_115 ;
int V_30 = 0 ;
unsigned long V_116 ;
unsigned long V_58 ;
T_4 V_117 ;
int V_49 ;
V_116 = ( unsigned long ) V_113 & V_63 ;
V_58 = ( unsigned long ) V_113 - V_116 ;
V_117 = F_85 ( V_114 + V_58 ) ;
V_49 = V_117 >> V_64 ;
if ( V_2 -> V_50 )
F_30 ( V_2 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_3 = V_113 ;
V_115 = F_28 ( V_2 , V_49 , 0 ) ;
if ( V_115 )
return V_115 ;
V_2 -> V_6 = V_58 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_4 ; V_30 ++ ) {
V_2 -> V_50 [ V_30 ] = F_81 ( ( void * ) V_116 ) ;
V_116 += V_5 ;
}
V_2 -> V_44 = F_86 ( V_114 ) ;
V_2 -> V_42 = F_86 ( V_117 ) ;
return 0 ;
}
T_2 *
F_78 (
struct V_25 * V_26 ,
T_4 V_85 ,
int V_29 )
{
unsigned long V_49 ;
int error , V_30 ;
struct V_1 * V_2 ;
F_87 ( V_27 , V_105 , V_85 ) ;
V_2 = F_15 ( V_26 , & V_27 , 1 , 0 ) ;
if ( F_17 ( V_2 == NULL ) )
goto V_118;
V_49 = F_85 ( V_85 << V_119 ) >> V_64 ;
error = F_28 ( V_2 , V_49 , 0 ) ;
if ( error )
goto V_120;
for ( V_30 = 0 ; V_30 < V_49 ; V_30 ++ ) {
V_2 -> V_50 [ V_30 ] = F_41 ( F_37 ( V_29 ) ) ;
if ( ! V_2 -> V_50 [ V_30 ] )
goto V_121;
}
V_2 -> V_7 |= V_54 ;
error = F_45 ( V_2 , 0 ) ;
if ( F_17 ( error ) ) {
F_66 ( V_26 -> V_88 ,
L_4 , V_68 ) ;
goto V_121;
}
F_88 ( V_2 , V_48 ) ;
return V_2 ;
V_121:
while ( -- V_30 >= 0 )
F_35 ( V_2 -> V_50 [ V_30 ] ) ;
F_30 ( V_2 ) ;
V_120:
F_13 ( V_2 ) ;
F_24 ( V_31 , V_2 ) ;
V_118:
return NULL ;
}
void
F_89 (
T_2 * V_2 )
{
F_90 ( V_2 , V_48 ) ;
F_56 ( & V_2 -> V_17 ) ;
}
void
F_61 (
T_2 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_96 ;
F_91 ( V_2 , V_48 ) ;
if ( ! V_79 ) {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
ASSERT ( F_92 ( & V_2 -> V_38 ) ) ;
if ( F_93 ( & V_2 -> V_17 ) )
F_31 ( V_2 ) ;
return;
}
ASSERT ( ! F_92 ( & V_2 -> V_38 ) ) ;
ASSERT ( F_9 ( & V_2 -> V_17 ) > 0 ) ;
if ( F_94 ( & V_2 -> V_17 , & V_79 -> V_91 ) ) {
F_5 ( & V_2 -> V_10 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) && F_9 ( & V_2 -> V_11 ) ) {
if ( F_95 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ) {
V_2 -> V_12 &= ~ V_13 ;
F_56 ( & V_2 -> V_17 ) ;
}
F_10 ( & V_2 -> V_10 ) ;
F_10 ( & V_79 -> V_91 ) ;
} else {
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_7 ( & V_2 -> V_14 -> V_15 , & V_2 -> V_16 ) ;
} else {
ASSERT ( F_33 ( & V_2 -> V_16 ) ) ;
}
F_10 ( & V_2 -> V_10 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
F_96 ( & V_2 -> V_38 , & V_79 -> V_92 ) ;
F_10 ( & V_79 -> V_91 ) ;
F_59 ( V_79 ) ;
F_31 ( V_2 ) ;
}
}
}
int
F_60 (
struct V_1 * V_2 )
{
int V_122 ;
V_122 = F_97 ( & V_2 -> V_39 ) == 0 ;
if ( V_122 )
F_23 ( V_2 ) ;
F_98 ( V_2 , V_48 ) ;
return V_122 ;
}
void
F_62 (
struct V_1 * V_2 )
{
F_99 ( V_2 , V_48 ) ;
if ( F_9 ( & V_2 -> V_45 ) && ( V_2 -> V_7 & V_8 ) )
F_100 ( V_2 -> V_14 -> V_88 , 0 ) ;
F_101 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
F_102 ( V_2 , V_48 ) ;
}
void
F_103 (
struct V_1 * V_2 )
{
F_104 ( V_2 ) ;
F_105 ( & V_2 -> V_39 ) ;
F_106 ( V_2 , V_48 ) ;
}
STATIC void
F_107 (
T_2 * V_2 )
{
F_108 ( V_123 , V_124 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
return;
F_109 ( & V_2 -> V_46 , & V_123 ) ;
for (; ; ) {
F_110 ( V_125 ) ;
if ( F_9 ( & V_2 -> V_45 ) == 0 )
break;
F_111 () ;
}
F_112 ( & V_2 -> V_46 , & V_123 ) ;
F_110 ( V_126 ) ;
}
STATIC void
F_113 (
struct V_127 * V_128 )
{
struct V_1 * V_2 =
F_114 ( V_128 , T_2 , V_129 ) ;
bool V_130 = ! ! ( V_2 -> V_7 & V_106 ) ;
V_2 -> V_7 &= ~ ( V_106 | V_104 | V_35 ) ;
if ( V_130 && V_2 -> V_101 && ! V_2 -> V_131 && ( V_2 -> V_7 & V_132 ) )
V_2 -> V_101 -> V_133 ( V_2 ) ;
if ( V_2 -> V_100 )
( * ( V_2 -> V_100 ) ) ( V_2 ) ;
else if ( V_2 -> V_7 & V_34 )
F_67 ( V_2 ) ;
else {
ASSERT ( V_130 && V_2 -> V_101 ) ;
F_115 ( & V_2 -> V_36 ) ;
}
}
void
F_116 (
struct V_1 * V_2 ,
int V_134 )
{
bool V_130 = ! ! ( V_2 -> V_7 & V_106 ) ;
F_117 ( V_2 , V_48 ) ;
if ( V_2 -> V_131 == 0 )
V_2 -> V_7 |= V_132 ;
if ( V_2 -> V_100 || ( V_130 && V_2 -> V_101 ) || ( V_2 -> V_7 & V_34 ) ) {
if ( V_134 ) {
F_118 ( & V_2 -> V_129 , F_113 ) ;
F_119 ( V_135 , & V_2 -> V_129 ) ;
} else {
F_113 ( & V_2 -> V_129 ) ;
}
} else {
V_2 -> V_7 &= ~ ( V_106 | V_104 | V_35 ) ;
F_115 ( & V_2 -> V_36 ) ;
}
}
void
F_120 (
T_2 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_131 = ( unsigned short ) error ;
F_121 ( V_2 , error , V_48 ) ;
}
void
F_122 (
struct V_1 * V_2 ,
const char * V_136 )
{
F_51 ( V_2 -> V_14 -> V_88 ,
L_5 ,
( V_137 ) F_123 ( V_2 ) , V_136 , V_2 -> V_131 , V_2 -> V_42 ) ;
}
STATIC int
F_124 (
T_2 * V_2 )
{
#ifdef F_125
ASSERT ( F_126 ( V_2 ) || V_2 -> V_100 ) ;
#endif
F_120 ( V_2 , V_138 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_3 ( V_2 ) ;
F_116 ( V_2 , 0 ) ;
return V_138 ;
}
int
F_129 (
struct V_1 * V_2 )
{
T_8 V_139 = V_2 -> V_7 ;
F_127 ( V_2 ) ;
F_130 ( V_2 ) ;
F_3 ( V_2 ) ;
V_2 -> V_100 = NULL ;
if ( ! ( V_139 & V_34 ) ) {
F_120 ( V_2 , V_138 ) ;
F_115 ( & V_2 -> V_36 ) ;
} else {
F_67 ( V_2 ) ;
}
return V_138 ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
if ( F_79 ( V_2 -> V_14 -> V_88 ) ) {
F_132 ( V_2 , V_48 ) ;
if ( ! V_2 -> V_100 && ! F_126 ( V_2 ) )
return F_129 ( V_2 ) ;
else
return F_124 ( V_2 ) ;
}
F_70 ( V_2 ) ;
return 0 ;
}
int
F_133 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_4 ( V_2 ) ) ;
V_2 -> V_7 |= V_104 ;
V_2 -> V_7 &= ~ ( V_34 | V_106 | V_9 | V_140 ) ;
F_131 ( V_2 ) ;
error = F_71 ( V_2 ) ;
if ( error ) {
F_134 ( V_2 -> V_14 -> V_88 ,
V_141 ) ;
}
return error ;
}
STATIC void
F_135 (
T_2 * V_2 ,
int V_134 )
{
if ( F_93 ( & V_2 -> V_142 ) == 1 )
F_116 ( V_2 , V_134 ) ;
}
STATIC void
F_136 (
struct V_143 * V_143 ,
int error )
{
T_2 * V_2 = ( T_2 * ) V_143 -> V_144 ;
if ( ! V_2 -> V_131 )
F_120 ( V_2 , - error ) ;
if ( ! V_2 -> V_131 && F_1 ( V_2 ) && ( V_2 -> V_7 & V_106 ) )
F_137 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
F_135 ( V_2 , 1 ) ;
F_138 ( V_143 ) ;
}
static void
F_139 (
struct V_1 * V_2 ,
int V_27 ,
int * V_145 ,
int * V_146 ,
int V_147 )
{
int V_148 ;
int V_149 = V_2 -> V_4 ;
int V_150 ;
struct V_143 * V_143 ;
T_9 V_151 = V_2 -> V_19 [ V_27 ] . V_41 ;
int V_56 ;
int V_58 ;
V_149 = V_2 -> V_4 ;
V_148 = 0 ;
V_58 = * V_145 ;
while ( V_58 >= V_5 ) {
V_148 ++ ;
V_58 -= V_5 ;
}
V_56 = F_44 ( int , F_38 ( V_2 -> V_19 [ V_27 ] . V_43 ) , * V_146 ) ;
* V_146 -= V_56 ;
* V_145 += V_56 ;
V_152:
F_56 ( & V_2 -> V_142 ) ;
V_150 = V_153 >> ( V_64 - V_119 ) ;
if ( V_150 > V_149 )
V_150 = V_149 ;
V_143 = F_140 ( V_154 , V_150 ) ;
V_143 -> V_155 = V_2 -> V_14 -> V_156 ;
V_143 -> V_157 . V_158 = V_151 ;
V_143 -> V_159 = F_136 ;
V_143 -> V_144 = V_2 ;
for (; V_56 && V_150 ; V_150 -- , V_148 ++ ) {
int V_160 , V_57 = V_5 - V_58 ;
if ( V_57 > V_56 )
V_57 = V_56 ;
V_160 = F_141 ( V_143 , V_2 -> V_50 [ V_148 ] , V_57 ,
V_58 ) ;
if ( V_160 < V_57 )
break;
V_58 = 0 ;
V_151 += F_86 ( V_57 ) ;
V_56 -= V_57 ;
V_149 -- ;
}
if ( F_65 ( V_143 -> V_157 . V_161 ) ) {
if ( F_1 ( V_2 ) ) {
F_142 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_143 ( V_147 , V_143 ) ;
if ( V_56 )
goto V_152;
} else {
F_8 ( & V_2 -> V_142 ) ;
F_120 ( V_2 , V_138 ) ;
F_138 ( V_143 ) ;
}
}
STATIC void
F_144 (
struct V_1 * V_2 )
{
struct V_162 V_163 ;
int V_147 ;
int V_58 ;
int V_56 ;
int V_30 ;
V_2 -> V_131 = 0 ;
if ( V_2 -> V_7 & V_104 ) {
if ( V_2 -> V_7 & V_164 )
V_147 = V_165 ;
else
V_147 = V_166 ;
if ( V_2 -> V_7 & V_167 )
V_147 |= V_168 ;
if ( V_2 -> V_7 & V_169 )
V_147 |= V_170 ;
if ( V_2 -> V_101 ) {
V_2 -> V_101 -> V_171 ( V_2 ) ;
if ( V_2 -> V_131 ) {
F_134 ( V_2 -> V_14 -> V_88 ,
V_172 ) ;
return;
}
}
} else if ( V_2 -> V_7 & V_35 ) {
V_147 = V_173 ;
} else {
V_147 = V_174 ;
}
V_147 |= V_175 ;
V_58 = V_2 -> V_6 ;
V_56 = F_38 ( V_2 -> V_44 ) ;
F_145 ( & V_163 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_20 ; V_30 ++ ) {
F_139 ( V_2 , V_30 , & V_58 , & V_56 , V_147 ) ;
if ( V_2 -> V_131 )
break;
if ( V_56 <= 0 )
break;
}
F_146 ( & V_163 ) ;
}
void
F_70 (
T_2 * V_2 )
{
F_147 ( V_2 , V_48 ) ;
ASSERT ( ! ( V_2 -> V_7 & V_9 ) ) ;
if ( V_2 -> V_7 & V_104 )
F_107 ( V_2 ) ;
F_89 ( V_2 ) ;
F_6 ( & V_2 -> V_142 , 1 ) ;
F_144 ( V_2 ) ;
F_135 ( V_2 , 1 ) ;
F_61 ( V_2 ) ;
}
int
F_71 (
T_2 * V_2 )
{
F_148 ( V_2 , V_48 ) ;
if ( ! V_2 -> V_131 )
F_149 ( & V_2 -> V_36 ) ;
F_150 ( V_2 , V_48 ) ;
return V_2 -> V_131 ;
}
T_10
F_151 (
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
F_152 (
T_2 * V_2 ,
T_4 V_176 ,
T_4 V_177 ,
void * V_178 ,
T_11 V_179 )
{
T_4 V_180 ;
V_180 = V_176 + V_177 ;
while ( V_176 < V_180 ) {
struct V_53 * V_53 ;
int V_148 , V_181 , V_182 ;
V_148 = ( V_176 + V_2 -> V_6 ) >> V_64 ;
V_181 = ( V_176 + V_2 -> V_6 ) & ~ V_63 ;
V_53 = V_2 -> V_50 [ V_148 ] ;
V_182 = F_44 ( T_4 , V_5 - V_181 ,
F_38 ( V_2 -> V_44 ) - V_176 ) ;
ASSERT ( ( V_182 + V_181 ) <= V_5 ) ;
switch ( V_179 ) {
case V_183 :
memset ( F_46 ( V_53 ) + V_181 , 0 , V_182 ) ;
break;
case V_184 :
memcpy ( V_178 , F_46 ( V_53 ) + V_181 , V_182 ) ;
break;
case V_185 :
memcpy ( F_46 ( V_53 ) + V_181 , V_178 , V_182 ) ;
}
V_176 += V_182 ;
V_178 += V_182 ;
}
}
static enum V_186
F_153 (
struct V_187 * V_188 ,
T_12 * V_189 ,
void * V_190 )
{
struct V_1 * V_2 = F_114 ( V_188 , struct V_1 , V_16 ) ;
struct V_187 * V_191 = V_190 ;
if ( F_9 ( & V_2 -> V_17 ) > 1 ) {
F_154 ( V_2 , V_48 ) ;
return V_192 ;
}
if ( ! F_155 ( & V_2 -> V_10 ) )
return V_192 ;
F_6 ( & V_2 -> V_11 , 0 ) ;
V_2 -> V_12 |= V_13 ;
F_156 ( V_188 , V_191 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_193 ;
}
void
F_157 (
struct V_25 * V_75 )
{
F_158 ( V_191 ) ;
int V_194 = 0 ;
while ( F_159 ( & V_75 -> V_15 ) ) {
F_160 ( & V_75 -> V_15 , F_153 ,
& V_191 , V_195 ) ;
while ( ! F_33 ( & V_191 ) ) {
struct V_1 * V_2 ;
V_2 = F_161 ( & V_191 , struct V_1 , V_16 ) ;
F_162 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_7 & V_140 ) {
F_51 ( V_75 -> V_88 ,
L_6
L_7 ,
( long long ) V_2 -> V_40 ) ;
}
F_61 ( V_2 ) ;
}
if ( V_194 ++ != 0 )
F_163 ( 100 ) ;
}
}
static enum V_186
F_164 (
struct V_187 * V_188 ,
T_12 * V_189 ,
void * V_190 )
{
struct V_1 * V_2 = F_114 ( V_188 , struct V_1 , V_16 ) ;
struct V_187 * V_191 = V_190 ;
if ( ! F_155 ( & V_2 -> V_10 ) )
return V_192 ;
if ( ! F_165 ( & V_2 -> V_11 , - 1 , 0 ) ) {
F_10 ( & V_2 -> V_10 ) ;
return V_196 ;
}
V_2 -> V_12 |= V_13 ;
F_156 ( V_188 , V_191 ) ;
F_10 ( & V_2 -> V_10 ) ;
return V_193 ;
}
static unsigned long
F_166 (
struct V_197 * V_198 ,
struct V_199 * V_200 )
{
struct V_25 * V_75 = F_114 ( V_198 ,
struct V_25 , V_201 ) ;
F_158 ( V_191 ) ;
unsigned long V_202 ;
unsigned long V_203 = V_200 -> V_203 ;
V_202 = F_167 ( & V_75 -> V_15 , V_200 -> V_204 , F_164 ,
& V_191 , & V_203 ) ;
while ( ! F_33 ( & V_191 ) ) {
struct V_1 * V_2 ;
V_2 = F_161 ( & V_191 , struct V_1 , V_16 ) ;
F_162 ( & V_2 -> V_16 ) ;
F_61 ( V_2 ) ;
}
return V_202 ;
}
static unsigned long
F_168 (
struct V_197 * V_198 ,
struct V_199 * V_200 )
{
struct V_25 * V_75 = F_114 ( V_198 ,
struct V_25 , V_201 ) ;
return F_169 ( & V_75 -> V_15 , V_200 -> V_204 ) ;
}
void
F_170 (
struct V_205 * V_206 ,
struct V_25 * V_75 )
{
F_171 ( & V_75 -> V_201 ) ;
F_172 ( & V_75 -> V_15 ) ;
if ( V_206 -> V_207 & V_208 )
F_173 ( V_75 ) ;
F_14 ( V_75 ) ;
}
int
F_174 (
T_13 * V_75 ,
unsigned int V_209 ,
unsigned int V_210 )
{
V_75 -> V_86 = V_210 ;
V_75 -> V_87 = V_210 - 1 ;
if ( F_175 ( V_75 -> V_156 , V_210 ) ) {
char V_211 [ V_212 ] ;
F_176 ( V_75 -> V_156 , V_211 ) ;
F_66 ( V_75 -> V_88 ,
L_8 ,
V_210 , V_211 ) ;
return V_213 ;
}
V_75 -> V_214 = F_177 ( V_75 -> V_156 ) ;
V_75 -> V_215 = F_177 ( V_75 -> V_156 ) - 1 ;
return 0 ;
}
STATIC int
F_178 (
T_13 * V_75 ,
struct V_216 * V_217 )
{
return F_174 ( V_75 , V_5 ,
F_177 ( V_217 ) ) ;
}
T_13 *
F_179 (
struct V_205 * V_206 ,
struct V_216 * V_217 ,
int V_218 ,
const char * V_219 )
{
T_13 * V_75 ;
V_75 = F_12 ( sizeof( * V_75 ) , V_220 | V_23 ) ;
V_75 -> V_88 = V_206 ;
V_75 -> V_221 = V_217 -> V_222 ;
V_75 -> V_156 = V_217 ;
V_75 -> V_110 = F_180 ( V_217 ) ;
if ( ! V_75 -> V_110 )
goto error;
if ( F_178 ( V_75 , V_217 ) )
goto error;
if ( F_181 ( & V_75 -> V_15 ) )
goto error;
V_75 -> V_201 . V_223 = F_168 ;
V_75 -> V_201 . V_224 = F_166 ;
V_75 -> V_201 . V_225 = V_226 ;
V_75 -> V_201 . V_29 = V_227 ;
F_182 ( & V_75 -> V_201 ) ;
return V_75 ;
error:
F_14 ( V_75 ) ;
return NULL ;
}
bool
F_183 (
struct V_1 * V_2 ,
struct V_187 * V_228 )
{
ASSERT ( F_4 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_7 & V_106 ) ) ;
if ( V_2 -> V_7 & V_9 ) {
F_184 ( V_2 , V_48 ) ;
return false ;
}
F_185 ( V_2 , V_48 ) ;
V_2 -> V_7 |= V_9 ;
if ( F_33 ( & V_2 -> V_37 ) ) {
F_56 ( & V_2 -> V_17 ) ;
F_186 ( & V_2 -> V_37 , V_228 ) ;
}
return true ;
}
static int
F_187 (
void * V_229 ,
struct V_187 * V_230 ,
struct V_187 * V_231 )
{
struct V_1 * V_232 = F_114 ( V_230 , struct V_1 , V_37 ) ;
struct V_1 * V_2 = F_114 ( V_231 , struct V_1 , V_37 ) ;
T_7 V_233 ;
V_233 = V_232 -> V_19 [ 0 ] . V_41 - V_2 -> V_19 [ 0 ] . V_41 ;
if ( V_233 < 0 )
return - 1 ;
if ( V_233 > 0 )
return 1 ;
return 0 ;
}
static int
F_188 (
struct V_187 * V_234 ,
struct V_187 * V_235 ,
bool V_123 )
{
struct V_162 V_163 ;
struct V_1 * V_2 , * V_236 ;
int V_237 = 0 ;
F_189 (bp, n, buffer_list, b_list) {
if ( ! V_123 ) {
if ( F_190 ( V_2 ) ) {
V_237 ++ ;
continue;
}
if ( ! F_60 ( V_2 ) )
continue;
} else {
F_62 ( V_2 ) ;
}
if ( ! ( V_2 -> V_7 & V_9 ) ) {
F_162 ( & V_2 -> V_37 ) ;
F_67 ( V_2 ) ;
continue;
}
F_191 ( & V_2 -> V_37 , V_235 ) ;
F_192 ( V_2 , V_48 ) ;
}
F_193 ( NULL , V_235 , F_187 ) ;
F_145 ( & V_163 ) ;
F_189 (bp, n, io_list, b_list) {
V_2 -> V_7 &= ~ ( V_9 | V_34 | V_140 ) ;
V_2 -> V_7 |= V_104 ;
if ( ! V_123 ) {
V_2 -> V_7 |= V_34 ;
F_162 ( & V_2 -> V_37 ) ;
}
F_131 ( V_2 ) ;
}
F_146 ( & V_163 ) ;
return V_237 ;
}
int
F_194 (
struct V_187 * V_234 )
{
F_158 ( V_235 ) ;
return F_188 ( V_234 , & V_235 , false ) ;
}
int
F_195 (
struct V_187 * V_234 )
{
F_158 ( V_235 ) ;
int error = 0 , V_238 ;
struct V_1 * V_2 ;
F_188 ( V_234 , & V_235 , true ) ;
while ( ! F_33 ( & V_235 ) ) {
V_2 = F_161 ( & V_235 , struct V_1 , V_37 ) ;
F_162 ( & V_2 -> V_37 ) ;
V_238 = F_71 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( ! error )
error = V_238 ;
}
return error ;
}
int T_14
F_196 ( void )
{
V_31 = F_197 ( sizeof( T_2 ) , L_9 ,
V_239 , NULL ) ;
if ( ! V_31 )
goto V_240;
V_135 = F_198 ( L_10 ,
V_241 | V_242 , 1 ) ;
if ( ! V_135 )
goto V_243;
return 0 ;
V_243:
F_199 ( V_31 ) ;
V_240:
return - V_24 ;
}
void
F_200 ( void )
{
F_201 ( V_135 ) ;
F_199 ( V_31 ) ;
}
