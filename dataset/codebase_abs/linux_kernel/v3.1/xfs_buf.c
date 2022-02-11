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
if ( ! F_57 ( V_2 ) ) {
if ( V_21 & V_84 ) {
F_58 ( V_2 ) ;
F_22 ( V_85 ) ;
return NULL ;
}
F_59 ( V_2 ) ;
F_22 ( V_86 ) ;
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
F_58 ( V_2 ) ;
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
V_2 -> V_3 &= ~ ( V_93 | V_94 | V_92 | V_24 ) ;
V_2 -> V_3 |= V_21 & ( V_95 | V_94 | V_24 ) ;
V_91 = F_67 ( V_2 ) ;
if ( V_91 || V_2 -> V_96 || ( V_21 & V_94 ) )
return V_91 ;
return F_68 ( V_2 ) ;
}
T_1 *
F_69 (
T_2 * V_18 ,
T_3 V_65 ,
T_4 V_66 ,
T_5 V_21 )
{
T_1 * V_2 ;
V_21 |= V_95 ;
V_2 = F_61 ( V_18 , V_65 , V_66 , V_21 ) ;
if ( V_2 ) {
F_70 ( V_2 , V_21 , V_37 ) ;
if ( ! F_71 ( V_2 ) ) {
F_22 ( V_97 ) ;
F_66 ( V_2 , V_21 ) ;
} else if ( V_21 & V_94 ) {
goto V_89;
} else {
V_2 -> V_3 &= ~ V_95 ;
}
}
return V_2 ;
V_89:
if ( V_21 & ( V_22 | V_84 ) )
F_65 ( V_2 ) ;
F_58 ( V_2 ) ;
return NULL ;
}
void
F_72 (
T_2 * V_18 ,
T_3 V_65 ,
T_4 V_66 )
{
if ( F_73 ( V_18 -> V_98 ) )
return;
F_69 ( V_18 , V_65 , V_66 ,
V_84 | V_94 | V_24 | V_23 ) ;
}
struct V_1 *
F_74 (
struct V_99 * V_100 ,
struct V_8 * V_18 ,
T_8 V_101 ,
T_4 V_102 ,
int V_21 )
{
T_1 * V_2 ;
int error ;
V_2 = F_75 ( V_18 , V_102 , V_21 ) ;
if ( ! V_2 )
return NULL ;
F_76 ( V_2 , V_101 ) ;
F_77 ( V_2 ) ;
F_78 ( V_100 , V_2 ) ;
error = F_68 ( V_2 ) ;
if ( error || V_2 -> V_96 ) {
F_79 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_1 *
F_80 (
T_4 V_103 ,
T_2 * V_18 )
{
T_1 * V_2 ;
V_2 = F_62 ( 0 ) ;
if ( V_2 )
F_15 ( V_2 , V_18 , 0 , V_103 , 0 ) ;
return V_2 ;
}
void
F_81 (
struct V_1 * V_2 ,
T_4 V_103 )
{
if ( V_2 -> V_39 )
F_28 ( V_2 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_5 = 0 ;
V_2 -> V_46 = NULL ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = V_2 -> V_31 = V_103 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_3 &= ~ V_4 ;
}
static inline struct V_42 *
F_82 (
void * V_104 )
{
if ( ( ! F_83 ( V_104 ) ) ) {
return F_38 ( V_104 ) ;
} else {
return F_84 ( V_104 ) ;
}
}
int
F_85 (
T_1 * V_2 ,
void * V_105 ,
T_4 V_103 )
{
int V_106 ;
int V_45 = 0 ;
unsigned long V_107 ;
unsigned long V_50 ;
T_4 V_108 ;
int V_38 ;
V_107 = ( unsigned long ) V_105 & V_54 ;
V_50 = ( unsigned long ) V_105 - V_107 ;
V_108 = F_86 ( V_103 + V_50 ) ;
V_38 = V_108 >> V_109 ;
if ( V_2 -> V_39 )
F_28 ( V_2 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_46 = V_105 ;
V_106 = F_24 ( V_2 , V_38 , V_23 ) ;
if ( V_106 )
return V_106 ;
V_2 -> V_7 = V_50 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_5 ; V_45 ++ ) {
V_2 -> V_39 [ V_45 ] = F_82 ( ( void * ) V_107 ) ;
V_107 += V_6 ;
}
V_2 -> V_31 = V_103 ;
V_2 -> V_30 = V_108 ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
T_1 *
F_75 (
struct V_8 * V_18 ,
T_4 V_103 ,
int V_21 )
{
unsigned long V_38 = F_86 ( V_103 ) >> V_109 ;
int error , V_45 ;
T_1 * V_2 ;
V_2 = F_62 ( 0 ) ;
if ( F_41 ( V_2 == NULL ) )
goto V_110;
F_15 ( V_2 , V_18 , 0 , V_103 , 0 ) ;
error = F_24 ( V_2 , V_38 , 0 ) ;
if ( error )
goto V_111;
for ( V_45 = 0 ; V_45 < V_38 ; V_45 ++ ) {
V_2 -> V_39 [ V_45 ] = F_42 ( F_36 ( V_21 ) ) ;
if ( ! V_2 -> V_39 [ V_45 ] )
goto V_112;
}
V_2 -> V_3 |= V_44 ;
error = F_46 ( V_2 , V_4 ) ;
if ( F_41 ( error ) ) {
F_63 ( V_18 -> V_76 ,
L_2 , V_58 ) ;
goto V_112;
}
F_87 ( V_2 , V_37 ) ;
return V_2 ;
V_112:
while ( -- V_45 >= 0 )
F_33 ( V_2 -> V_39 [ V_45 ] ) ;
F_28 ( V_2 ) ;
V_111:
F_34 ( V_2 ) ;
V_110:
return NULL ;
}
void
F_88 (
T_1 * V_2 )
{
F_89 ( V_2 , V_37 ) ;
F_6 ( & V_2 -> V_13 ) ;
}
void
F_58 (
T_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_82 ;
F_90 ( V_2 , V_37 ) ;
if ( ! V_69 ) {
ASSERT ( F_5 ( & V_2 -> V_12 ) ) ;
ASSERT ( F_91 ( & V_2 -> V_27 ) ) ;
if ( F_92 ( & V_2 -> V_13 ) )
F_30 ( V_2 ) ;
return;
}
ASSERT ( ! F_91 ( & V_2 -> V_27 ) ) ;
ASSERT ( F_14 ( & V_2 -> V_13 ) > 0 ) ;
if ( F_93 ( & V_2 -> V_13 , & V_69 -> V_77 ) ) {
if ( ! ( V_2 -> V_3 & V_16 ) &&
F_14 ( & V_2 -> V_17 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_69 -> V_77 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_3 & ( V_92 | V_87 ) ) ) ;
F_94 ( & V_2 -> V_27 , & V_69 -> V_78 ) ;
F_8 ( & V_69 -> V_77 ) ;
F_56 ( V_69 ) ;
F_30 ( V_2 ) ;
}
}
}
int
F_57 (
struct V_1 * V_2 )
{
int V_113 ;
V_113 = F_95 ( & V_2 -> V_28 ) == 0 ;
if ( V_113 )
F_20 ( V_2 ) ;
else if ( F_14 ( & V_2 -> V_34 ) && ( V_2 -> V_3 & V_16 ) )
F_96 ( V_2 -> V_10 -> V_76 , 0 ) ;
F_97 ( V_2 , V_37 ) ;
return V_113 ;
}
void
F_59 (
struct V_1 * V_2 )
{
F_98 ( V_2 , V_37 ) ;
if ( F_14 ( & V_2 -> V_34 ) && ( V_2 -> V_3 & V_16 ) )
F_96 ( V_2 -> V_10 -> V_76 , 0 ) ;
F_99 ( & V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_100 ( V_2 , V_37 ) ;
}
void
F_65 (
struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & ( V_92 | V_87 ) ) == V_92 ) {
F_6 ( & V_2 -> V_13 ) ;
V_2 -> V_3 |= V_94 ;
F_101 ( V_2 , 0 ) ;
}
F_102 ( V_2 ) ;
F_103 ( & V_2 -> V_28 ) ;
F_104 ( V_2 , V_37 ) ;
}
STATIC void
F_105 (
T_1 * V_2 )
{
F_106 ( V_114 , V_115 ) ;
if ( F_14 ( & V_2 -> V_34 ) == 0 )
return;
F_107 ( & V_2 -> V_35 , & V_114 ) ;
for (; ; ) {
F_108 ( V_116 ) ;
if ( F_14 ( & V_2 -> V_34 ) == 0 )
break;
F_109 () ;
}
F_110 ( & V_2 -> V_35 , & V_114 ) ;
F_108 ( V_117 ) ;
}
STATIC void
F_111 (
struct V_118 * V_119 )
{
T_1 * V_2 =
F_112 ( V_119 , T_1 , V_120 ) ;
if ( V_2 -> V_121 )
( * ( V_2 -> V_121 ) ) ( V_2 ) ;
else if ( V_2 -> V_3 & V_94 )
F_79 ( V_2 ) ;
}
void
F_113 (
T_1 * V_2 ,
int V_122 )
{
F_114 ( V_2 , V_37 ) ;
V_2 -> V_3 &= ~ ( V_95 | V_93 | V_24 ) ;
if ( V_2 -> V_96 == 0 )
V_2 -> V_3 |= V_123 ;
if ( ( V_2 -> V_121 ) || ( V_2 -> V_3 & V_94 ) ) {
if ( V_122 ) {
F_115 ( & V_2 -> V_120 , F_111 ) ;
F_116 ( V_124 , & V_2 -> V_120 ) ;
} else {
F_111 ( & V_2 -> V_120 ) ;
}
} else {
F_117 ( & V_2 -> V_25 ) ;
}
}
void
F_118 (
T_1 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_96 = ( unsigned short ) error ;
F_119 ( V_2 , error , V_37 ) ;
}
int
F_120 (
struct V_99 * V_100 ,
struct V_1 * V_2 )
{
int error ;
V_2 -> V_3 |= V_93 ;
V_2 -> V_3 &= ~ ( V_94 | V_95 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
error = F_68 ( V_2 ) ;
if ( error )
F_123 ( V_100 , V_125 ) ;
F_79 ( V_2 ) ;
return error ;
}
void
F_124 (
void * V_100 ,
struct V_1 * V_2 )
{
F_125 ( V_2 , V_37 ) ;
V_2 -> V_3 &= ~ V_95 ;
V_2 -> V_3 |= ( V_92 | V_94 ) ;
F_101 ( V_2 , 1 ) ;
}
STATIC int
F_126 (
T_1 * V_2 )
{
#ifdef F_127
ASSERT ( F_128 ( V_2 ) || V_2 -> V_121 ) ;
#endif
F_118 ( V_2 , V_126 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_113 ( V_2 , 0 ) ;
return V_126 ;
}
STATIC int
F_133 (
struct V_1 * V_2 )
{
T_9 V_127 = V_2 -> V_3 ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_134 ( V_2 ) ;
F_132 ( V_2 ) ;
V_2 -> V_121 = NULL ;
if ( ! ( V_127 & V_94 ) ) {
F_118 ( V_2 , V_126 ) ;
F_135 ( V_2 ) ;
} else {
F_79 ( V_2 ) ;
}
return V_126 ;
}
int
F_122 (
struct V_1 * V_2 )
{
if ( F_136 ( V_2 -> V_10 -> V_76 ) ) {
F_137 ( V_2 , V_37 ) ;
if ( ! V_2 -> V_121 && ! F_128 ( V_2 ) )
return F_133 ( V_2 ) ;
else
return F_126 ( V_2 ) ;
}
F_67 ( V_2 ) ;
return 0 ;
}
void
F_78 (
struct V_99 * V_100 ,
struct V_1 * V_2 )
{
if ( F_136 ( V_100 ) ) {
F_137 ( V_2 , V_37 ) ;
F_133 ( V_2 ) ;
return;
}
F_67 ( V_2 ) ;
}
STATIC void
F_138 (
T_1 * V_2 ,
int V_122 )
{
if ( F_92 ( & V_2 -> V_128 ) == 1 )
F_113 ( V_2 , V_122 ) ;
}
STATIC void
F_139 (
struct V_129 * V_129 ,
int error )
{
T_1 * V_2 = ( T_1 * ) V_129 -> V_130 ;
F_118 ( V_2 , - error ) ;
if ( ! error && F_1 ( V_2 ) && ( V_2 -> V_3 & V_95 ) )
F_140 ( V_2 -> V_46 , F_2 ( V_2 ) ) ;
F_138 ( V_2 , 1 ) ;
F_141 ( V_129 ) ;
}
STATIC void
F_142 (
T_1 * V_2 )
{
int V_131 , V_132 , V_133 , V_134 ;
struct V_129 * V_129 ;
int V_50 = V_2 -> V_7 ;
int V_48 = V_2 -> V_31 ;
T_10 V_135 = V_2 -> V_32 ;
V_133 = V_2 -> V_5 ;
V_132 = 0 ;
if ( V_2 -> V_3 & V_93 ) {
if ( V_2 -> V_3 & V_136 )
V_131 = V_137 ;
else
V_131 = V_138 ;
if ( V_2 -> V_3 & V_139 )
V_131 |= V_140 ;
if ( V_2 -> V_3 & V_141 )
V_131 |= V_142 ;
} else if ( V_2 -> V_3 & V_24 ) {
V_131 = V_143 ;
} else {
V_131 = V_144 ;
}
V_131 |= V_145 ;
V_146:
F_6 ( & V_2 -> V_128 ) ;
V_134 = V_147 >> ( V_109 - V_73 ) ;
if ( V_134 > V_133 )
V_134 = V_133 ;
V_129 = F_143 ( V_148 , V_134 ) ;
V_129 -> V_149 = V_2 -> V_10 -> V_150 ;
V_129 -> V_151 = V_135 ;
V_129 -> V_152 = F_139 ;
V_129 -> V_130 = V_2 ;
for (; V_48 && V_134 ; V_134 -- , V_132 ++ ) {
int V_153 , V_49 = V_6 - V_50 ;
if ( V_49 > V_48 )
V_49 = V_48 ;
V_153 = F_144 ( V_129 , V_2 -> V_39 [ V_132 ] , V_49 , V_50 ) ;
if ( V_153 < V_49 )
break;
V_50 = 0 ;
V_135 += V_49 >> V_73 ;
V_48 -= V_49 ;
V_133 -- ;
}
if ( F_145 ( V_129 -> V_154 ) ) {
if ( F_1 ( V_2 ) ) {
F_146 ( V_2 -> V_46 ,
F_2 ( V_2 ) ) ;
}
F_147 ( V_131 , V_129 ) ;
if ( V_48 )
goto V_146;
} else {
F_118 ( V_2 , V_126 ) ;
F_141 ( V_129 ) ;
}
}
int
F_67 (
T_1 * V_2 )
{
F_148 ( V_2 , V_37 ) ;
if ( V_2 -> V_3 & V_92 ) {
F_101 ( V_2 , 1 ) ;
return 0 ;
}
if ( V_2 -> V_3 & V_93 ) {
F_105 ( V_2 ) ;
}
F_88 ( V_2 ) ;
F_12 ( & V_2 -> V_128 , 1 ) ;
F_142 ( V_2 ) ;
F_138 ( V_2 , 0 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
int
F_68 (
T_1 * V_2 )
{
F_149 ( V_2 , V_37 ) ;
F_150 ( & V_2 -> V_25 ) ;
F_151 ( V_2 , V_37 ) ;
return V_2 -> V_96 ;
}
T_11
F_152 (
T_1 * V_2 ,
T_4 V_50 )
{
struct V_42 * V_42 ;
if ( V_2 -> V_3 & V_4 )
return V_2 -> V_46 + V_50 ;
V_50 += V_2 -> V_7 ;
V_42 = V_2 -> V_39 [ V_50 >> V_109 ] ;
return ( T_11 ) F_47 ( V_42 ) + ( V_50 & ( V_6 - 1 ) ) ;
}
void
F_153 (
T_1 * V_2 ,
T_4 V_155 ,
T_4 V_156 ,
void * V_157 ,
T_12 V_158 )
{
T_4 V_159 , V_160 , V_161 ;
struct V_42 * V_42 ;
V_159 = V_155 + V_156 ;
while ( V_155 < V_159 ) {
V_42 = V_2 -> V_39 [ F_40 ( V_155 + V_2 -> V_7 ) ] ;
V_160 = F_25 ( V_155 + V_2 -> V_7 ) ;
V_161 = F_45 ( T_4 ,
V_6 - V_160 , V_2 -> V_31 - V_155 ) ;
ASSERT ( ( ( V_161 + V_160 ) <= V_6 ) ) ;
switch ( V_158 ) {
case V_162 :
memset ( F_47 ( V_42 ) + V_160 , 0 , V_161 ) ;
break;
case V_163 :
memcpy ( V_157 , F_47 ( V_42 ) + V_160 , V_161 ) ;
break;
case V_164 :
memcpy ( F_47 ( V_42 ) + V_160 , V_157 , V_161 ) ;
}
V_155 += V_161 ;
V_157 += V_161 ;
}
}
void
F_154 (
struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_165:
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
V_2 = F_155 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( F_14 ( & V_2 -> V_13 ) > 1 ) {
F_8 ( & V_9 -> V_11 ) ;
F_156 ( 100 ) ;
goto V_165;
}
F_12 ( & V_2 -> V_17 , 0 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_58 ( V_2 ) ;
F_4 ( & V_9 -> V_11 ) ;
}
F_8 ( & V_9 -> V_11 ) ;
}
int
F_157 (
struct V_166 * V_167 ,
struct V_168 * V_169 )
{
struct V_8 * V_9 = F_112 ( V_167 ,
struct V_8 , V_170 ) ;
struct V_1 * V_2 ;
int V_171 = V_169 -> V_171 ;
F_158 ( V_172 ) ;
if ( ! V_171 )
return V_9 -> V_15 ;
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
if ( V_171 -- <= 0 )
break;
V_2 = F_155 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( ! F_159 ( & V_2 -> V_17 , - 1 , 0 ) ) {
F_160 ( & V_2 -> V_12 , & V_9 -> V_14 ) ;
continue;
}
F_161 ( & V_2 -> V_12 , & V_172 ) ;
V_9 -> V_15 -- ;
}
F_8 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_172 ) ) {
V_2 = F_155 ( & V_172 , struct V_1 , V_12 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_58 ( V_2 ) ;
}
return V_9 -> V_15 ;
}
void
F_162 (
struct V_99 * V_100 ,
struct V_8 * V_9 )
{
F_163 ( & V_9 -> V_170 ) ;
F_164 ( V_9 , 1 ) ;
if ( V_100 -> V_173 & V_174 )
F_165 ( V_9 ) ;
F_166 ( V_9 -> V_175 ) ;
F_29 ( V_9 ) ;
}
STATIC int
F_167 (
T_2 * V_9 ,
unsigned int V_176 ,
unsigned int V_177 ,
int V_178 )
{
V_9 -> V_179 = V_176 ;
V_9 -> V_74 = F_168 ( V_177 ) - 1 ;
V_9 -> V_75 = V_177 - 1 ;
if ( F_169 ( V_9 -> V_150 , V_177 ) ) {
F_63 ( V_9 -> V_76 ,
L_3 ,
V_177 , F_170 ( V_9 ) ) ;
return V_180 ;
}
return 0 ;
}
STATIC int
F_171 (
T_2 * V_9 ,
struct V_181 * V_182 )
{
return F_167 ( V_9 ,
V_6 , F_172 ( V_182 ) , 0 ) ;
}
int
F_173 (
T_2 * V_9 ,
unsigned int V_176 ,
unsigned int V_177 )
{
return F_167 ( V_9 , V_176 , V_177 , 1 ) ;
}
STATIC int
F_174 (
T_2 * V_9 ,
const char * V_183 )
{
F_17 ( & V_9 -> V_184 ) ;
F_175 ( & V_9 -> V_185 ) ;
V_9 -> V_186 = 0 ;
V_9 -> V_175 = F_176 ( V_187 , V_9 , L_4 , V_183 ) ;
if ( F_177 ( V_9 -> V_175 ) )
return F_178 ( V_9 -> V_175 ) ;
return 0 ;
}
T_2 *
F_179 (
struct V_99 * V_100 ,
struct V_181 * V_182 ,
int V_188 ,
const char * V_183 )
{
T_2 * V_9 ;
V_9 = F_180 ( sizeof( * V_9 ) , V_189 ) ;
V_9 -> V_76 = V_100 ;
V_9 -> V_190 = V_182 -> V_191 ;
V_9 -> V_150 = V_182 ;
V_9 -> V_98 = F_181 ( V_182 ) ;
if ( ! V_9 -> V_98 )
goto error;
F_17 ( & V_9 -> V_14 ) ;
F_175 ( & V_9 -> V_11 ) ;
if ( F_171 ( V_9 , V_182 ) )
goto error;
if ( F_174 ( V_9 , V_183 ) )
goto error;
V_9 -> V_170 . V_167 = F_157 ;
V_9 -> V_170 . V_192 = V_193 ;
F_182 ( & V_9 -> V_170 ) ;
return V_9 ;
error:
F_29 ( V_9 ) ;
return NULL ;
}
STATIC void
F_101 (
T_1 * V_2 ,
int V_194 )
{
struct V_195 * V_196 = & V_2 -> V_10 -> V_184 ;
T_13 * V_197 = & V_2 -> V_10 -> V_185 ;
F_183 ( V_2 , V_37 ) ;
ASSERT ( ( V_2 -> V_3 & ( V_92 | V_94 ) ) == ( V_92 | V_94 ) ) ;
F_4 ( V_197 ) ;
if ( ! F_5 ( & V_2 -> V_26 ) ) {
ASSERT ( V_2 -> V_3 & V_87 ) ;
if ( V_194 )
F_13 ( & V_2 -> V_13 ) ;
F_184 ( & V_2 -> V_26 ) ;
}
if ( F_5 ( V_196 ) ) {
F_185 ( V_2 -> V_10 -> V_175 ) ;
}
V_2 -> V_3 |= V_87 ;
F_7 ( & V_2 -> V_26 , V_196 ) ;
V_2 -> V_198 = V_199 ;
F_8 ( V_197 ) ;
if ( V_194 )
F_65 ( V_2 ) ;
}
void
F_121 (
T_1 * V_2 )
{
T_13 * V_197 = & V_2 -> V_10 -> V_185 ;
int V_200 = 0 ;
F_4 ( V_197 ) ;
if ( ( V_2 -> V_3 & V_92 ) && ! F_5 ( & V_2 -> V_26 ) ) {
ASSERT ( V_2 -> V_3 & V_87 ) ;
F_10 ( & V_2 -> V_26 ) ;
V_200 = 1 ;
}
V_2 -> V_3 &= ~ ( V_92 | V_87 ) ;
F_8 ( V_197 ) ;
if ( V_200 )
F_58 ( V_2 ) ;
F_186 ( V_2 , V_37 ) ;
}
void
F_187 (
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
long V_201 = V_202 * F_188 ( 10 ) + 1 ;
ASSERT ( V_2 -> V_3 & V_92 ) ;
ASSERT ( V_2 -> V_3 & V_87 ) ;
if ( V_2 -> V_198 < V_199 - V_201 )
return;
V_2 -> V_198 = V_199 - V_201 ;
F_4 ( & V_9 -> V_185 ) ;
F_161 ( & V_2 -> V_26 , & V_9 -> V_184 ) ;
F_8 ( & V_9 -> V_185 ) ;
}
STATIC void
F_189 (
struct V_203 * V_204 )
{
F_190 ( V_204 ) ;
}
STATIC int
F_191 (
T_2 * V_18 ,
struct V_195 * V_205 ,
unsigned long V_201 )
{
T_1 * V_2 , * V_206 ;
struct V_195 * V_196 = & V_18 -> V_184 ;
T_13 * V_197 = & V_18 -> V_185 ;
int V_207 = 0 ;
int V_208 ;
V_208 = F_192 ( V_209 , & V_18 -> V_186 ) ;
F_17 ( V_205 ) ;
F_4 ( V_197 ) ;
F_193 (bp, n, dwq, b_list) {
ASSERT ( V_2 -> V_3 & V_92 ) ;
if ( ! F_194 ( V_2 ) && F_57 ( V_2 ) ) {
if ( ! V_208 &&
F_195 ( V_199 , V_2 -> V_198 + V_201 ) ) {
F_65 ( V_2 ) ;
break;
}
V_2 -> V_3 &= ~ ( V_92 | V_87 ) ;
V_2 -> V_3 |= V_93 ;
F_160 ( & V_2 -> V_26 , V_205 ) ;
F_196 ( V_2 , V_37 ) ;
} else
V_207 ++ ;
}
F_8 ( V_197 ) ;
return V_207 ;
}
static int
F_197 (
void * V_210 ,
struct V_195 * V_211 ,
struct V_195 * V_212 )
{
struct V_1 * V_213 = F_112 ( V_211 , struct V_1 , V_26 ) ;
struct V_1 * V_2 = F_112 ( V_212 , struct V_1 , V_26 ) ;
T_8 V_214 ;
V_214 = V_213 -> V_32 - V_2 -> V_32 ;
if ( V_214 < 0 )
return - 1 ;
if ( V_214 > 0 )
return 1 ;
return 0 ;
}
STATIC int
V_187 (
void * V_157 )
{
T_2 * V_18 = ( T_2 * ) V_157 ;
V_115 -> V_21 |= V_215 ;
F_198 () ;
do {
long V_201 = V_202 * F_188 ( 10 ) ;
long V_216 = V_217 * F_188 ( 10 ) ;
struct V_195 V_218 ;
struct V_219 V_220 ;
if ( F_41 ( F_199 ( V_115 ) ) ) {
F_200 ( V_221 , & V_18 -> V_186 ) ;
F_201 () ;
} else {
F_202 ( V_221 , & V_18 -> V_186 ) ;
}
if ( F_5 ( & V_18 -> V_184 ) )
V_216 = V_222 ;
F_203 ( V_216 ) ;
F_191 ( V_18 , & V_218 , V_201 ) ;
F_204 ( NULL , & V_218 , F_197 ) ;
F_205 ( & V_220 ) ;
while ( ! F_5 ( & V_218 ) ) {
struct V_1 * V_2 ;
V_2 = F_155 ( & V_218 , struct V_1 , V_26 ) ;
F_10 ( & V_2 -> V_26 ) ;
F_122 ( V_2 ) ;
}
F_206 ( & V_220 ) ;
} while ( ! F_207 () );
return 0 ;
}
int
F_164 (
T_2 * V_18 ,
int V_114 )
{
T_1 * V_2 ;
int V_223 = 0 ;
F_158 ( V_224 ) ;
F_158 ( V_225 ) ;
struct V_219 V_220 ;
F_189 ( V_226 ) ;
F_189 ( V_227 ) ;
F_189 ( V_124 ) ;
F_200 ( V_209 , & V_18 -> V_186 ) ;
V_223 = F_191 ( V_18 , & V_224 , 0 ) ;
F_204 ( NULL , & V_224 , F_197 ) ;
F_205 ( & V_220 ) ;
while ( ! F_5 ( & V_224 ) ) {
V_2 = F_155 ( & V_224 , struct V_1 , V_26 ) ;
ASSERT ( V_18 == V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_26 ) ;
if ( V_114 ) {
V_2 -> V_3 &= ~ V_94 ;
F_208 ( & V_2 -> V_26 , & V_225 ) ;
}
F_122 ( V_2 ) ;
}
F_206 ( & V_220 ) ;
if ( V_114 ) {
while ( ! F_5 ( & V_225 ) ) {
V_2 = F_155 ( & V_225 , struct V_1 , V_26 ) ;
F_10 ( & V_2 -> V_26 ) ;
F_68 ( V_2 ) ;
F_79 ( V_2 ) ;
}
}
return V_223 ;
}
int T_14
F_209 ( void )
{
V_228 = F_210 ( sizeof( T_1 ) , L_5 ,
V_229 , NULL ) ;
if ( ! V_228 )
goto V_230;
V_124 = F_211 ( L_6 ,
V_231 | V_232 , 1 ) ;
if ( ! V_124 )
goto V_233;
V_227 = F_211 ( L_7 , V_231 , 1 ) ;
if ( ! V_227 )
goto V_234;
V_226 = F_211 ( L_8 ,
V_231 , 1 ) ;
if ( ! V_226 )
goto V_235;
return 0 ;
V_235:
F_212 ( V_227 ) ;
V_234:
F_212 ( V_124 ) ;
V_233:
F_213 ( V_228 ) ;
V_230:
return - V_43 ;
}
void
F_214 ( void )
{
F_212 ( V_226 ) ;
F_212 ( V_227 ) ;
F_212 ( V_124 ) ;
F_213 ( V_228 ) ;
}
struct V_195 *
F_215 ( void )
{
return & V_236 ;
}
