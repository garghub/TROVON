static inline int
F_1 (
struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) && V_2 -> V_5 > 1 ;
}
static inline int
F_2 (
struct V_1 * V_2 )
{
return ( V_2 -> V_5 * V_6 ) - V_2 -> V_7 ;
}
STATIC void
F_3 (
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( & V_9 -> V_11 ) ;
if ( F_5 ( & V_2 -> V_12 ) ) {
F_6 ( & V_2 -> V_13 ) ;
F_7 ( & V_2 -> V_12 , & V_9 -> V_14 ) ;
V_9 -> V_15 ++ ;
}
F_8 ( & V_9 -> V_11 ) ;
}
STATIC void
F_9 (
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( F_5 ( & V_2 -> V_12 ) )
return;
F_4 ( & V_9 -> V_11 ) ;
if ( ! F_5 ( & V_2 -> V_12 ) ) {
F_10 ( & V_2 -> V_12 ) ;
V_9 -> V_15 -- ;
}
F_8 ( & V_9 -> V_11 ) ;
}
void
F_11 (
struct V_1 * V_2 )
{
V_2 -> V_3 |= V_16 ;
F_12 ( & ( V_2 ) -> V_17 , 0 ) ;
if ( ! F_5 ( & V_2 -> V_12 ) ) {
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( & V_9 -> V_11 ) ;
if ( ! F_5 ( & V_2 -> V_12 ) ) {
F_10 ( & V_2 -> V_12 ) ;
V_9 -> V_15 -- ;
F_13 ( & V_2 -> V_13 ) ;
}
F_8 ( & V_9 -> V_11 ) ;
}
ASSERT ( F_14 ( & V_2 -> V_13 ) >= 1 ) ;
}
STATIC void
F_15 (
T_1 * V_2 ,
T_2 * V_18 ,
T_3 V_19 ,
T_4 V_20 ,
T_5 V_21 )
{
V_21 &= ~ ( V_22 | V_4 | V_23 | V_24 ) ;
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
F_12 ( & V_2 -> V_13 , 1 ) ;
F_12 ( & V_2 -> V_17 , 1 ) ;
F_16 ( & V_2 -> V_25 ) ;
F_17 ( & V_2 -> V_12 ) ;
F_17 ( & V_2 -> V_26 ) ;
F_18 ( & V_2 -> V_27 ) ;
F_19 ( & V_2 -> V_28 , 0 ) ;
F_20 ( V_2 ) ;
V_2 -> V_10 = V_18 ;
V_2 -> V_29 = V_19 ;
V_2 -> V_30 = V_2 -> V_31 = V_20 ;
V_2 -> V_3 = V_21 ;
V_2 -> V_32 = V_33 ;
F_12 ( & V_2 -> V_34 , 0 ) ;
F_21 ( & V_2 -> V_35 ) ;
F_22 ( V_36 ) ;
F_23 ( V_2 , V_37 ) ;
}
STATIC int
F_24 (
T_1 * V_2 ,
int V_38 ,
T_5 V_21 )
{
if ( V_2 -> V_39 == NULL ) {
V_2 -> V_7 = F_25 ( V_2 -> V_29 ) ;
V_2 -> V_5 = V_38 ;
if ( V_38 <= V_40 ) {
V_2 -> V_39 = V_2 -> V_41 ;
} else {
V_2 -> V_39 = F_26 ( sizeof( struct V_42 * ) *
V_38 , F_27 ( V_21 ) ) ;
if ( V_2 -> V_39 == NULL )
return - V_43 ;
}
memset ( V_2 -> V_39 , 0 , sizeof( struct V_42 * ) * V_38 ) ;
}
return 0 ;
}
STATIC void
F_28 (
T_1 * V_2 )
{
if ( V_2 -> V_39 != V_2 -> V_41 ) {
F_29 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
}
}
void
F_30 (
T_1 * V_2 )
{
F_31 ( V_2 , V_37 ) ;
ASSERT ( F_5 ( & V_2 -> V_12 ) ) ;
if ( V_2 -> V_3 & V_44 ) {
T_6 V_45 ;
if ( F_1 ( V_2 ) )
F_32 ( V_2 -> V_46 - V_2 -> V_7 ,
V_2 -> V_5 ) ;
for ( V_45 = 0 ; V_45 < V_2 -> V_5 ; V_45 ++ ) {
struct V_42 * V_42 = V_2 -> V_39 [ V_45 ] ;
F_33 ( V_42 ) ;
}
} else if ( V_2 -> V_3 & V_47 )
F_29 ( V_2 -> V_46 ) ;
F_28 ( V_2 ) ;
F_34 ( V_2 ) ;
}
STATIC int
F_35 (
T_1 * V_2 ,
T_6 V_21 )
{
T_4 V_48 = V_2 -> V_31 ;
T_4 V_49 , V_50 ;
T_7 V_51 = F_36 ( V_21 ) ;
unsigned short V_38 , V_45 ;
T_3 V_52 ;
int error ;
if ( V_2 -> V_30 < V_6 ) {
V_2 -> V_46 = F_26 ( V_2 -> V_30 , F_27 ( V_21 ) ) ;
if ( ! V_2 -> V_46 ) {
goto V_53;
}
if ( ( ( unsigned long ) ( V_2 -> V_46 + V_2 -> V_30 - 1 ) &
V_54 ) !=
( ( unsigned long ) V_2 -> V_46 & V_54 ) ) {
F_29 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
goto V_53;
}
V_2 -> V_7 = F_37 ( V_2 -> V_46 ) ;
V_2 -> V_39 = V_2 -> V_41 ;
V_2 -> V_39 [ 0 ] = F_38 ( V_2 -> V_46 ) ;
V_2 -> V_5 = 1 ;
V_2 -> V_3 |= V_4 | V_47 ;
return 0 ;
}
V_53:
V_52 = V_2 -> V_29 + V_2 -> V_30 ;
V_38 = F_39 ( V_52 ) - F_40 ( V_2 -> V_29 ) ;
error = F_24 ( V_2 , V_38 , V_21 ) ;
if ( F_41 ( error ) )
return error ;
V_50 = V_2 -> V_7 ;
V_2 -> V_3 |= V_44 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_5 ; V_45 ++ ) {
struct V_42 * V_42 ;
T_6 V_55 = 0 ;
V_56:
V_42 = F_42 ( V_51 ) ;
if ( F_41 ( V_42 == NULL ) ) {
if ( V_21 & V_24 ) {
V_2 -> V_5 = V_45 ;
error = V_43 ;
goto V_57;
}
if ( ! ( ++ V_55 % 100 ) )
F_43 ( NULL ,
L_1 ,
V_58 , V_51 ) ;
F_22 ( V_59 ) ;
F_44 ( V_60 , V_61 / 50 ) ;
goto V_56;
}
F_22 ( V_62 ) ;
V_49 = F_45 ( T_4 , V_48 , V_6 - V_50 ) ;
V_48 -= V_49 ;
V_2 -> V_39 [ V_45 ] = V_42 ;
V_50 = 0 ;
}
return 0 ;
V_57:
for ( V_45 = 0 ; V_45 < V_2 -> V_5 ; V_45 ++ )
F_33 ( V_2 -> V_39 [ V_45 ] ) ;
return error ;
}
STATIC int
F_46 (
T_1 * V_2 ,
T_6 V_21 )
{
ASSERT ( V_2 -> V_3 & V_44 ) ;
if ( V_2 -> V_5 == 1 ) {
V_2 -> V_46 = F_47 ( V_2 -> V_39 [ 0 ] ) + V_2 -> V_7 ;
V_2 -> V_3 |= V_4 ;
} else if ( V_21 & V_4 ) {
int V_63 = 0 ;
do {
V_2 -> V_46 = F_48 ( V_2 -> V_39 , V_2 -> V_5 ,
- 1 , V_64 ) ;
if ( V_2 -> V_46 )
break;
F_49 () ;
} while ( V_63 ++ <= 1 );
if ( ! V_2 -> V_46 )
return - V_43 ;
V_2 -> V_46 += V_2 -> V_7 ;
V_2 -> V_3 |= V_4 ;
}
return 0 ;
}
T_1 *
F_50 (
T_2 * V_9 ,
T_3 V_65 ,
T_4 V_66 ,
T_5 V_21 ,
T_1 * V_67 )
{
T_3 V_19 ;
T_4 V_20 ;
struct V_68 * V_69 ;
struct V_70 * * V_71 ;
struct V_70 * V_72 ;
T_1 * V_2 ;
V_19 = ( V_65 << V_73 ) ;
V_20 = ( V_66 << V_73 ) ;
ASSERT ( ! ( V_20 < ( 1 << V_9 -> V_74 ) ) ) ;
ASSERT ( ! ( V_19 & ( T_3 ) V_9 -> V_75 ) ) ;
V_69 = F_51 ( V_9 -> V_76 ,
F_52 ( V_9 -> V_76 , V_65 ) ) ;
F_4 ( & V_69 -> V_77 ) ;
V_71 = & V_69 -> V_78 . V_70 ;
V_72 = NULL ;
V_2 = NULL ;
while ( * V_71 ) {
V_72 = * V_71 ;
V_2 = F_53 ( V_72 , struct V_1 , V_27 ) ;
if ( V_19 < V_2 -> V_29 )
V_71 = & ( * V_71 ) -> V_79 ;
else if ( V_19 > V_2 -> V_29 )
V_71 = & ( * V_71 ) -> V_80 ;
else {
if ( V_2 -> V_30 != V_20 ) {
ASSERT ( V_2 -> V_3 & V_16 ) ;
V_71 = & ( * V_71 ) -> V_80 ;
continue;
}
F_6 ( & V_2 -> V_13 ) ;
goto V_81;
}
}
if ( V_67 ) {
F_15 ( V_67 , V_9 , V_19 ,
V_20 , V_21 ) ;
F_54 ( & V_67 -> V_27 , V_72 , V_71 ) ;
F_55 ( & V_67 -> V_27 , & V_69 -> V_78 ) ;
V_67 -> V_82 = V_69 ;
F_8 ( & V_69 -> V_77 ) ;
} else {
F_22 ( V_83 ) ;
F_8 ( & V_69 -> V_77 ) ;
F_56 ( V_69 ) ;
}
return V_67 ;
V_81:
F_8 ( & V_69 -> V_77 ) ;
F_56 ( V_69 ) ;
if ( F_57 ( V_2 ) ) {
if ( ! ( V_21 & V_84 ) ) {
F_58 ( V_2 ) ;
F_22 ( V_85 ) ;
} else {
F_59 ( V_2 ) ;
F_22 ( V_86 ) ;
return NULL ;
}
}
if ( V_2 -> V_3 & V_16 ) {
ASSERT ( ( V_2 -> V_3 & V_87 ) == 0 ) ;
V_2 -> V_3 &= V_4 | V_47 | V_44 ;
}
F_60 ( V_2 , V_21 , V_37 ) ;
F_22 ( V_88 ) ;
return V_2 ;
}
T_1 *
F_61 (
T_2 * V_18 ,
T_3 V_65 ,
T_4 V_66 ,
T_5 V_21 )
{
T_1 * V_2 , * V_67 ;
int error = 0 ;
V_67 = F_62 ( V_21 ) ;
if ( F_41 ( ! V_67 ) )
return NULL ;
V_2 = F_50 ( V_18 , V_65 , V_66 , V_21 , V_67 ) ;
if ( V_2 == V_67 ) {
error = F_35 ( V_2 , V_21 ) ;
if ( error )
goto V_89;
} else {
F_34 ( V_67 ) ;
if ( F_41 ( V_2 == NULL ) )
return NULL ;
}
if ( ! ( V_2 -> V_3 & V_4 ) ) {
error = F_46 ( V_2 , V_21 ) ;
if ( F_41 ( error ) ) {
F_63 ( V_18 -> V_76 ,
L_2 , V_58 ) ;
goto V_89;
}
}
F_22 ( V_90 ) ;
V_2 -> V_32 = V_65 ;
V_2 -> V_31 = V_2 -> V_30 ;
F_64 ( V_2 , V_21 , V_37 ) ;
return V_2 ;
V_89:
if ( V_21 & ( V_22 | V_84 ) )
F_65 ( V_2 ) ;
F_59 ( V_2 ) ;
return NULL ;
}
STATIC int
F_66 (
T_1 * V_2 ,
T_5 V_21 )
{
int V_91 ;
ASSERT ( ! ( V_21 & ( V_92 | V_93 ) ) ) ;
ASSERT ( V_2 -> V_32 != V_33 ) ;
V_2 -> V_3 &= ~ ( V_93 | V_94 | V_92 | \
V_24 | V_95 ) ;
V_2 -> V_3 |= V_21 & ( V_96 | V_94 | \
V_24 | V_95 ) ;
V_91 = F_67 ( V_2 ) ;
if ( V_91 || F_68 ( V_2 ) || ( V_21 & V_94 ) )
return V_91 ;
return F_69 ( V_2 ) ;
}
T_1 *
F_70 (
T_2 * V_18 ,
T_3 V_65 ,
T_4 V_66 ,
T_5 V_21 )
{
T_1 * V_2 ;
V_21 |= V_96 ;
V_2 = F_61 ( V_18 , V_65 , V_66 , V_21 ) ;
if ( V_2 ) {
F_71 ( V_2 , V_21 , V_37 ) ;
if ( ! F_72 ( V_2 ) ) {
F_22 ( V_97 ) ;
F_66 ( V_2 , V_21 ) ;
} else if ( V_21 & V_94 ) {
goto V_89;
} else {
V_2 -> V_3 &= ~ V_96 ;
}
}
return V_2 ;
V_89:
if ( V_21 & ( V_22 | V_84 ) )
F_65 ( V_2 ) ;
F_59 ( V_2 ) ;
return NULL ;
}
void
F_73 (
T_2 * V_18 ,
T_3 V_65 ,
T_4 V_66 )
{
if ( F_74 ( V_18 -> V_98 ) )
return;
F_70 ( V_18 , V_65 , V_66 ,
V_84 | V_94 | V_24 | V_23 ) ;
}
struct V_1 *
F_75 (
struct V_99 * V_100 ,
struct V_8 * V_18 ,
T_8 V_101 ,
T_4 V_102 ,
int V_21 )
{
T_1 * V_2 ;
int error ;
V_2 = F_76 ( V_18 , V_102 , V_21 ) ;
if ( ! V_2 )
return NULL ;
F_58 ( V_2 ) ;
F_77 ( V_2 , V_101 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_100 , V_2 ) ;
error = F_69 ( V_2 ) ;
if ( error || V_2 -> V_103 ) {
F_81 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_1 *
F_82 (
T_4 V_104 ,
T_2 * V_18 )
{
T_1 * V_2 ;
V_2 = F_62 ( 0 ) ;
if ( V_2 )
F_15 ( V_2 , V_18 , 0 , V_104 , 0 ) ;
return V_2 ;
}
void
F_83 (
struct V_1 * V_2 ,
T_4 V_104 )
{
if ( V_2 -> V_39 )
F_28 ( V_2 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_5 = 0 ;
V_2 -> V_46 = NULL ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = V_2 -> V_31 = V_104 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_3 &= ~ V_4 ;
}
static inline struct V_42 *
F_84 (
void * V_105 )
{
if ( ( ! F_85 ( V_105 ) ) ) {
return F_38 ( V_105 ) ;
} else {
return F_86 ( V_105 ) ;
}
}
int
F_87 (
T_1 * V_2 ,
void * V_106 ,
T_4 V_104 )
{
int V_107 ;
int V_45 = 0 ;
unsigned long V_108 ;
unsigned long V_50 ;
T_4 V_109 ;
int V_38 ;
V_108 = ( unsigned long ) V_106 & V_54 ;
V_50 = ( unsigned long ) V_106 - V_108 ;
V_109 = F_88 ( V_104 + V_50 ) ;
V_38 = V_109 >> V_110 ;
if ( V_2 -> V_39 )
F_28 ( V_2 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_46 = V_106 ;
V_107 = F_24 ( V_2 , V_38 , V_23 ) ;
if ( V_107 )
return V_107 ;
V_2 -> V_7 = V_50 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_5 ; V_45 ++ ) {
V_2 -> V_39 [ V_45 ] = F_84 ( ( void * ) V_108 ) ;
V_108 += V_6 ;
}
V_2 -> V_31 = V_104 ;
V_2 -> V_30 = V_109 ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
T_1 *
F_76 (
struct V_8 * V_18 ,
T_4 V_104 ,
int V_21 )
{
unsigned long V_38 = F_88 ( V_104 ) >> V_110 ;
int error , V_45 ;
T_1 * V_2 ;
V_2 = F_62 ( 0 ) ;
if ( F_41 ( V_2 == NULL ) )
goto V_111;
F_15 ( V_2 , V_18 , 0 , V_104 , 0 ) ;
error = F_24 ( V_2 , V_38 , 0 ) ;
if ( error )
goto V_112;
for ( V_45 = 0 ; V_45 < V_38 ; V_45 ++ ) {
V_2 -> V_39 [ V_45 ] = F_42 ( F_36 ( V_21 ) ) ;
if ( ! V_2 -> V_39 [ V_45 ] )
goto V_113;
}
V_2 -> V_3 |= V_44 ;
error = F_46 ( V_2 , V_4 ) ;
if ( F_41 ( error ) ) {
F_63 ( V_18 -> V_76 ,
L_2 , V_58 ) ;
goto V_113;
}
F_65 ( V_2 ) ;
F_89 ( V_2 , V_37 ) ;
return V_2 ;
V_113:
while ( -- V_45 >= 0 )
F_33 ( V_2 -> V_39 [ V_45 ] ) ;
F_28 ( V_2 ) ;
V_112:
F_34 ( V_2 ) ;
V_111:
return NULL ;
}
void
F_90 (
T_1 * V_2 )
{
F_91 ( V_2 , V_37 ) ;
F_6 ( & V_2 -> V_13 ) ;
}
void
F_59 (
T_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_82 ;
F_92 ( V_2 , V_37 ) ;
if ( ! V_69 ) {
ASSERT ( F_5 ( & V_2 -> V_12 ) ) ;
ASSERT ( F_93 ( & V_2 -> V_27 ) ) ;
if ( F_94 ( & V_2 -> V_13 ) )
F_30 ( V_2 ) ;
return;
}
ASSERT ( ! F_93 ( & V_2 -> V_27 ) ) ;
ASSERT ( F_14 ( & V_2 -> V_13 ) > 0 ) ;
if ( F_95 ( & V_2 -> V_13 , & V_69 -> V_77 ) ) {
if ( ! ( V_2 -> V_3 & V_16 ) &&
F_14 ( & V_2 -> V_17 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_69 -> V_77 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_3 & ( V_92 | V_87 ) ) ) ;
F_96 ( & V_2 -> V_27 , & V_69 -> V_78 ) ;
F_8 ( & V_69 -> V_77 ) ;
F_56 ( V_69 ) ;
F_30 ( V_2 ) ;
}
}
}
int
F_57 (
T_1 * V_2 )
{
int V_114 ;
V_114 = F_97 ( & V_2 -> V_28 ) == 0 ;
if ( V_114 )
F_20 ( V_2 ) ;
else if ( F_14 ( & V_2 -> V_34 ) && ( V_2 -> V_3 & V_16 ) )
F_98 ( V_2 -> V_10 -> V_76 , 0 ) ;
F_99 ( V_2 , V_37 ) ;
return V_114 ? 0 : - V_115 ;
}
int
F_100 (
T_1 * V_2 )
{
return V_2 -> V_28 . V_116 ;
}
void
F_58 (
T_1 * V_2 )
{
F_101 ( V_2 , V_37 ) ;
if ( F_14 ( & V_2 -> V_34 ) && ( V_2 -> V_3 & V_16 ) )
F_98 ( V_2 -> V_10 -> V_76 , 0 ) ;
F_102 ( & V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_103 ( V_2 , V_37 ) ;
}
void
F_65 (
T_1 * V_2 )
{
if ( ( V_2 -> V_3 & ( V_92 | V_87 ) ) == V_92 ) {
F_6 ( & V_2 -> V_13 ) ;
V_2 -> V_3 |= V_94 ;
F_104 ( V_2 , 0 ) ;
}
F_105 ( V_2 ) ;
F_106 ( & V_2 -> V_28 ) ;
F_107 ( V_2 , V_37 ) ;
}
STATIC void
F_108 (
T_1 * V_2 )
{
F_109 ( V_117 , V_118 ) ;
if ( F_14 ( & V_2 -> V_34 ) == 0 )
return;
F_110 ( & V_2 -> V_35 , & V_117 ) ;
for (; ; ) {
F_111 ( V_119 ) ;
if ( F_14 ( & V_2 -> V_34 ) == 0 )
break;
F_112 () ;
}
F_113 ( & V_2 -> V_35 , & V_117 ) ;
F_111 ( V_120 ) ;
}
STATIC void
F_114 (
struct V_121 * V_122 )
{
T_1 * V_2 =
F_115 ( V_122 , T_1 , V_123 ) ;
if ( V_2 -> V_124 )
( * ( V_2 -> V_124 ) ) ( V_2 ) ;
else if ( V_2 -> V_3 & V_94 )
F_81 ( V_2 ) ;
}
void
F_116 (
T_1 * V_2 ,
int V_125 )
{
F_117 ( V_2 , V_37 ) ;
V_2 -> V_3 &= ~ ( V_96 | V_93 | V_24 ) ;
if ( V_2 -> V_103 == 0 )
V_2 -> V_3 |= V_126 ;
if ( ( V_2 -> V_124 ) || ( V_2 -> V_3 & V_94 ) ) {
if ( V_125 ) {
F_118 ( & V_2 -> V_123 , F_114 ) ;
F_119 ( V_127 , & V_2 -> V_123 ) ;
} else {
F_114 ( & V_2 -> V_123 ) ;
}
} else {
F_120 ( & V_2 -> V_25 ) ;
}
}
void
F_121 (
T_1 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_103 = ( unsigned short ) error ;
F_122 ( V_2 , error , V_37 ) ;
}
int
F_123 (
struct V_99 * V_100 ,
struct V_1 * V_2 )
{
int error ;
V_2 -> V_3 |= V_93 ;
V_2 -> V_3 &= ~ ( V_94 | V_96 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
error = F_69 ( V_2 ) ;
if ( error )
F_126 ( V_100 , V_128 ) ;
F_81 ( V_2 ) ;
return error ;
}
void
F_127 (
void * V_100 ,
struct V_1 * V_2 )
{
F_128 ( V_2 , V_37 ) ;
V_2 -> V_3 &= ~ V_96 ;
V_2 -> V_3 |= ( V_92 | V_94 ) ;
F_104 ( V_2 , 1 ) ;
}
STATIC int
F_129 (
T_1 * V_2 )
{
#ifdef F_130
ASSERT ( F_131 ( V_2 ) || V_2 -> V_124 ) ;
#endif
F_132 ( V_2 , V_129 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
F_116 ( V_2 , 0 ) ;
return V_129 ;
}
STATIC int
F_137 (
struct V_1 * V_2 )
{
T_9 V_130 = F_138 ( V_2 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_139 ( V_2 ) ;
F_136 ( V_2 ) ;
F_140 ( V_2 ) ;
if ( ! ( V_130 & V_94 ) ) {
F_132 ( V_2 , V_129 ) ;
F_141 ( V_2 ) ;
} else {
F_81 ( V_2 ) ;
}
return V_129 ;
}
int
F_125 (
struct V_1 * V_2 )
{
if ( F_142 ( V_2 -> V_10 -> V_76 ) ) {
F_143 ( V_2 , V_37 ) ;
if ( ! V_2 -> V_124 && ! F_131 ( V_2 ) )
return F_137 ( V_2 ) ;
else
return F_129 ( V_2 ) ;
}
F_67 ( V_2 ) ;
return 0 ;
}
void
F_80 (
struct V_99 * V_100 ,
struct V_1 * V_2 )
{
if ( F_142 ( V_100 ) ) {
F_143 ( V_2 , V_37 ) ;
F_137 ( V_2 ) ;
return;
}
F_67 ( V_2 ) ;
}
STATIC void
F_144 (
T_1 * V_2 ,
int V_125 )
{
if ( F_94 ( & V_2 -> V_131 ) == 1 )
F_116 ( V_2 , V_125 ) ;
}
STATIC void
F_145 (
struct V_132 * V_132 ,
int error )
{
T_1 * V_2 = ( T_1 * ) V_132 -> V_133 ;
F_121 ( V_2 , - error ) ;
if ( ! error && F_1 ( V_2 ) && ( V_2 -> V_3 & V_96 ) )
F_146 ( V_2 -> V_46 , F_2 ( V_2 ) ) ;
F_144 ( V_2 , 1 ) ;
F_147 ( V_132 ) ;
}
STATIC void
F_148 (
T_1 * V_2 )
{
int V_134 , V_135 , V_136 , V_137 ;
struct V_132 * V_132 ;
int V_50 = V_2 -> V_7 ;
int V_48 = V_2 -> V_31 ;
T_10 V_138 = V_2 -> V_32 ;
V_136 = V_2 -> V_5 ;
V_135 = 0 ;
if ( V_2 -> V_3 & V_139 ) {
ASSERT ( ! ( V_2 -> V_3 & V_96 ) ) ;
V_134 = V_140 ;
} else if ( V_2 -> V_3 & V_141 ) {
ASSERT ( ! ( V_2 -> V_3 & V_24 ) ) ;
V_2 -> V_3 &= ~ V_95 ;
V_134 = ( V_2 -> V_3 & V_93 ) ? V_142 : V_143 ;
} else if ( V_2 -> V_3 & V_95 ) {
ASSERT ( ! ( V_2 -> V_3 & V_24 ) ) ;
V_2 -> V_3 &= ~ V_95 ;
V_134 = ( V_2 -> V_3 & V_93 ) ? V_144 : V_145 ;
} else {
V_134 = ( V_2 -> V_3 & V_93 ) ? V_146 :
( V_2 -> V_3 & V_24 ) ? V_147 : V_148 ;
}
V_149:
F_6 ( & V_2 -> V_131 ) ;
V_137 = V_150 >> ( V_110 - V_73 ) ;
if ( V_137 > V_136 )
V_137 = V_136 ;
V_132 = F_149 ( V_151 , V_137 ) ;
V_132 -> V_152 = V_2 -> V_10 -> V_153 ;
V_132 -> V_154 = V_138 ;
V_132 -> V_155 = F_145 ;
V_132 -> V_133 = V_2 ;
for (; V_48 && V_137 ; V_137 -- , V_135 ++ ) {
int V_156 , V_49 = V_6 - V_50 ;
if ( V_49 > V_48 )
V_49 = V_48 ;
V_156 = F_150 ( V_132 , V_2 -> V_39 [ V_135 ] , V_49 , V_50 ) ;
if ( V_156 < V_49 )
break;
V_50 = 0 ;
V_138 += V_49 >> V_73 ;
V_48 -= V_49 ;
V_136 -- ;
}
if ( F_151 ( V_132 -> V_157 ) ) {
if ( F_1 ( V_2 ) ) {
F_152 ( V_2 -> V_46 ,
F_2 ( V_2 ) ) ;
}
F_153 ( V_134 , V_132 ) ;
if ( V_48 )
goto V_149;
} else {
F_121 ( V_2 , V_129 ) ;
F_147 ( V_132 ) ;
}
}
int
F_67 (
T_1 * V_2 )
{
F_154 ( V_2 , V_37 ) ;
if ( V_2 -> V_3 & V_92 ) {
F_104 ( V_2 , 1 ) ;
return 0 ;
}
if ( V_2 -> V_3 & V_93 ) {
F_108 ( V_2 ) ;
}
F_90 ( V_2 ) ;
F_12 ( & V_2 -> V_131 , 1 ) ;
F_148 ( V_2 ) ;
F_144 ( V_2 , 0 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
int
F_69 (
T_1 * V_2 )
{
F_155 ( V_2 , V_37 ) ;
F_156 ( & V_2 -> V_25 ) ;
F_157 ( V_2 , V_37 ) ;
return V_2 -> V_103 ;
}
T_11
F_158 (
T_1 * V_2 ,
T_4 V_50 )
{
struct V_42 * V_42 ;
if ( V_2 -> V_3 & V_4 )
return F_159 ( V_2 ) + V_50 ;
V_50 += V_2 -> V_7 ;
V_42 = V_2 -> V_39 [ V_50 >> V_110 ] ;
return ( T_11 ) F_47 ( V_42 ) + ( V_50 & ( V_6 - 1 ) ) ;
}
void
F_160 (
T_1 * V_2 ,
T_4 V_158 ,
T_4 V_159 ,
void * V_160 ,
T_12 V_161 )
{
T_4 V_162 , V_163 , V_164 ;
struct V_42 * V_42 ;
V_162 = V_158 + V_159 ;
while ( V_158 < V_162 ) {
V_42 = V_2 -> V_39 [ F_40 ( V_158 + V_2 -> V_7 ) ] ;
V_163 = F_25 ( V_158 + V_2 -> V_7 ) ;
V_164 = F_45 ( T_4 ,
V_6 - V_163 , V_2 -> V_31 - V_158 ) ;
ASSERT ( ( ( V_164 + V_163 ) <= V_6 ) ) ;
switch ( V_161 ) {
case V_165 :
memset ( F_47 ( V_42 ) + V_163 , 0 , V_164 ) ;
break;
case V_166 :
memcpy ( V_160 , F_47 ( V_42 ) + V_163 , V_164 ) ;
break;
case V_167 :
memcpy ( F_47 ( V_42 ) + V_163 , V_160 , V_164 ) ;
}
V_158 += V_164 ;
V_160 += V_164 ;
}
}
void
F_161 (
struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_168:
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
V_2 = F_162 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( F_14 ( & V_2 -> V_13 ) > 1 ) {
F_8 ( & V_9 -> V_11 ) ;
F_163 ( 100 ) ;
goto V_168;
}
F_12 ( & V_2 -> V_17 , 0 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_59 ( V_2 ) ;
F_4 ( & V_9 -> V_11 ) ;
}
F_8 ( & V_9 -> V_11 ) ;
}
int
F_164 (
struct V_169 * V_170 ,
struct V_171 * V_172 )
{
struct V_8 * V_9 = F_115 ( V_170 ,
struct V_8 , V_173 ) ;
struct V_1 * V_2 ;
int V_174 = V_172 -> V_174 ;
F_165 ( V_175 ) ;
if ( ! V_174 )
return V_9 -> V_15 ;
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
if ( V_174 -- <= 0 )
break;
V_2 = F_162 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( ! F_166 ( & V_2 -> V_17 , - 1 , 0 ) ) {
F_167 ( & V_2 -> V_12 , & V_9 -> V_14 ) ;
continue;
}
F_168 ( & V_2 -> V_12 , & V_175 ) ;
V_9 -> V_15 -- ;
}
F_8 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_175 ) ) {
V_2 = F_162 ( & V_175 , struct V_1 , V_12 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_59 ( V_2 ) ;
}
return V_9 -> V_15 ;
}
void
F_169 (
struct V_99 * V_100 ,
struct V_8 * V_9 )
{
F_170 ( & V_9 -> V_173 ) ;
F_171 ( V_9 , 1 ) ;
if ( V_100 -> V_176 & V_177 )
F_172 ( V_9 ) ;
F_173 ( V_9 -> V_178 ) ;
F_29 ( V_9 ) ;
}
STATIC int
F_174 (
T_2 * V_9 ,
unsigned int V_179 ,
unsigned int V_180 ,
int V_181 )
{
V_9 -> V_182 = V_179 ;
V_9 -> V_74 = F_175 ( V_180 ) - 1 ;
V_9 -> V_75 = V_180 - 1 ;
if ( F_176 ( V_9 -> V_153 , V_180 ) ) {
F_63 ( V_9 -> V_76 ,
L_3 ,
V_180 , F_177 ( V_9 ) ) ;
return V_183 ;
}
return 0 ;
}
STATIC int
F_178 (
T_2 * V_9 ,
struct V_184 * V_185 )
{
return F_174 ( V_9 ,
V_6 , F_179 ( V_185 ) , 0 ) ;
}
int
F_180 (
T_2 * V_9 ,
unsigned int V_179 ,
unsigned int V_180 )
{
return F_174 ( V_9 , V_179 , V_180 , 1 ) ;
}
STATIC int
F_181 (
T_2 * V_9 ,
const char * V_186 )
{
F_17 ( & V_9 -> V_187 ) ;
F_182 ( & V_9 -> V_188 ) ;
V_9 -> V_189 = 0 ;
V_9 -> V_178 = F_183 ( V_190 , V_9 , L_4 , V_186 ) ;
if ( F_184 ( V_9 -> V_178 ) )
return F_185 ( V_9 -> V_178 ) ;
return 0 ;
}
T_2 *
F_186 (
struct V_99 * V_100 ,
struct V_184 * V_185 ,
int V_191 ,
const char * V_186 )
{
T_2 * V_9 ;
V_9 = F_187 ( sizeof( * V_9 ) , V_192 ) ;
V_9 -> V_76 = V_100 ;
V_9 -> V_193 = V_185 -> V_194 ;
V_9 -> V_153 = V_185 ;
V_9 -> V_98 = F_188 ( V_185 ) ;
if ( ! V_9 -> V_98 )
goto error;
F_17 ( & V_9 -> V_14 ) ;
F_182 ( & V_9 -> V_11 ) ;
if ( F_178 ( V_9 , V_185 ) )
goto error;
if ( F_181 ( V_9 , V_186 ) )
goto error;
V_9 -> V_173 . V_170 = F_164 ;
V_9 -> V_173 . V_195 = V_196 ;
F_189 ( & V_9 -> V_173 ) ;
return V_9 ;
error:
F_29 ( V_9 ) ;
return NULL ;
}
STATIC void
F_104 (
T_1 * V_2 ,
int V_197 )
{
struct V_198 * V_199 = & V_2 -> V_10 -> V_187 ;
T_13 * V_200 = & V_2 -> V_10 -> V_188 ;
F_190 ( V_2 , V_37 ) ;
ASSERT ( ( V_2 -> V_3 & ( V_92 | V_94 ) ) == ( V_92 | V_94 ) ) ;
F_4 ( V_200 ) ;
if ( ! F_5 ( & V_2 -> V_26 ) ) {
ASSERT ( V_2 -> V_3 & V_87 ) ;
if ( V_197 )
F_13 ( & V_2 -> V_13 ) ;
F_191 ( & V_2 -> V_26 ) ;
}
if ( F_5 ( V_199 ) ) {
F_192 ( V_2 -> V_10 -> V_178 ) ;
}
V_2 -> V_3 |= V_87 ;
F_7 ( & V_2 -> V_26 , V_199 ) ;
V_2 -> V_201 = V_202 ;
F_8 ( V_200 ) ;
if ( V_197 )
F_65 ( V_2 ) ;
}
void
F_124 (
T_1 * V_2 )
{
T_13 * V_200 = & V_2 -> V_10 -> V_188 ;
int V_203 = 0 ;
F_4 ( V_200 ) ;
if ( ( V_2 -> V_3 & V_92 ) && ! F_5 ( & V_2 -> V_26 ) ) {
ASSERT ( V_2 -> V_3 & V_87 ) ;
F_10 ( & V_2 -> V_26 ) ;
V_203 = 1 ;
}
V_2 -> V_3 &= ~ ( V_92 | V_87 ) ;
F_8 ( V_200 ) ;
if ( V_203 )
F_59 ( V_2 ) ;
F_193 ( V_2 , V_37 ) ;
}
void
F_194 (
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
long V_204 = V_205 * F_195 ( 10 ) + 1 ;
ASSERT ( V_2 -> V_3 & V_92 ) ;
ASSERT ( V_2 -> V_3 & V_87 ) ;
if ( V_2 -> V_201 < V_202 - V_204 )
return;
V_2 -> V_201 = V_202 - V_204 ;
F_4 ( & V_9 -> V_188 ) ;
F_168 ( & V_2 -> V_26 , & V_9 -> V_187 ) ;
F_8 ( & V_9 -> V_188 ) ;
}
STATIC void
F_196 (
struct V_206 * V_207 )
{
F_197 ( V_207 ) ;
}
STATIC int
F_198 (
T_2 * V_18 ,
struct V_198 * V_208 ,
unsigned long V_204 )
{
T_1 * V_2 , * V_209 ;
struct V_198 * V_199 = & V_18 -> V_187 ;
T_13 * V_200 = & V_18 -> V_188 ;
int V_210 = 0 ;
int V_211 ;
V_211 = F_199 ( V_212 , & V_18 -> V_189 ) ;
F_17 ( V_208 ) ;
F_4 ( V_200 ) ;
F_200 (bp, n, dwq, b_list) {
ASSERT ( V_2 -> V_3 & V_92 ) ;
if ( ! F_201 ( V_2 ) && ! F_57 ( V_2 ) ) {
if ( ! V_211 &&
F_202 ( V_202 , V_2 -> V_201 + V_204 ) ) {
F_65 ( V_2 ) ;
break;
}
V_2 -> V_3 &= ~ ( V_92 | V_87 |
V_95 ) ;
V_2 -> V_3 |= V_93 ;
F_167 ( & V_2 -> V_26 , V_208 ) ;
F_203 ( V_2 , V_37 ) ;
} else
V_210 ++ ;
}
F_8 ( V_200 ) ;
return V_210 ;
}
static int
F_204 (
void * V_213 ,
struct V_198 * V_214 ,
struct V_198 * V_215 )
{
struct V_1 * V_216 = F_115 ( V_214 , struct V_1 , V_26 ) ;
struct V_1 * V_2 = F_115 ( V_215 , struct V_1 , V_26 ) ;
T_8 V_217 ;
V_217 = V_216 -> V_32 - V_2 -> V_32 ;
if ( V_217 < 0 )
return - 1 ;
if ( V_217 > 0 )
return 1 ;
return 0 ;
}
void
F_205 (
T_2 * V_18 ,
struct V_198 * V_208 )
{
F_206 ( NULL , V_208 , F_204 ) ;
}
STATIC int
V_190 (
void * V_160 )
{
T_2 * V_18 = ( T_2 * ) V_160 ;
V_118 -> V_21 |= V_218 ;
F_207 () ;
do {
long V_204 = V_205 * F_195 ( 10 ) ;
long V_219 = V_220 * F_195 ( 10 ) ;
struct V_198 V_221 ;
struct V_222 V_223 ;
if ( F_41 ( F_208 ( V_118 ) ) ) {
F_209 ( V_224 , & V_18 -> V_189 ) ;
F_210 () ;
} else {
F_211 ( V_224 , & V_18 -> V_189 ) ;
}
if ( F_5 ( & V_18 -> V_187 ) )
V_219 = V_225 ;
F_212 ( V_219 ) ;
F_198 ( V_18 , & V_221 , V_204 ) ;
F_206 ( NULL , & V_221 , F_204 ) ;
F_213 ( & V_223 ) ;
while ( ! F_5 ( & V_221 ) ) {
struct V_1 * V_2 ;
V_2 = F_162 ( & V_221 , struct V_1 , V_26 ) ;
F_10 ( & V_2 -> V_26 ) ;
F_125 ( V_2 ) ;
}
F_214 ( & V_223 ) ;
} while ( ! F_215 () );
return 0 ;
}
int
F_171 (
T_2 * V_18 ,
int V_117 )
{
T_1 * V_2 ;
int V_226 = 0 ;
F_165 ( V_227 ) ;
F_165 ( V_228 ) ;
struct V_222 V_223 ;
F_196 ( V_229 ) ;
F_196 ( V_230 ) ;
F_196 ( V_127 ) ;
F_209 ( V_212 , & V_18 -> V_189 ) ;
V_226 = F_198 ( V_18 , & V_227 , 0 ) ;
F_206 ( NULL , & V_227 , F_204 ) ;
F_213 ( & V_223 ) ;
while ( ! F_5 ( & V_227 ) ) {
V_2 = F_162 ( & V_227 , struct V_1 , V_26 ) ;
ASSERT ( V_18 == V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_26 ) ;
if ( V_117 ) {
V_2 -> V_3 &= ~ V_94 ;
F_216 ( & V_2 -> V_26 , & V_228 ) ;
}
F_125 ( V_2 ) ;
}
F_214 ( & V_223 ) ;
if ( V_117 ) {
while ( ! F_5 ( & V_228 ) ) {
V_2 = F_162 ( & V_228 , struct V_1 , V_26 ) ;
F_10 ( & V_2 -> V_26 ) ;
F_69 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
return V_226 ;
}
int T_14
F_217 ( void )
{
V_231 = F_218 ( sizeof( T_1 ) , L_5 ,
V_232 , NULL ) ;
if ( ! V_231 )
goto V_233;
V_127 = F_219 ( L_6 ,
V_234 | V_235 , 1 ) ;
if ( ! V_127 )
goto V_236;
V_230 = F_219 ( L_7 , V_234 , 1 ) ;
if ( ! V_230 )
goto V_237;
V_229 = F_219 ( L_8 ,
V_234 , 1 ) ;
if ( ! V_229 )
goto V_238;
return 0 ;
V_238:
F_220 ( V_230 ) ;
V_237:
F_220 ( V_127 ) ;
V_236:
F_221 ( V_231 ) ;
V_233:
return - V_43 ;
}
void
F_222 ( void )
{
F_220 ( V_229 ) ;
F_220 ( V_230 ) ;
F_220 ( V_127 ) ;
F_221 ( V_231 ) ;
}
struct V_198 *
F_223 ( void )
{
return & V_239 ;
}
