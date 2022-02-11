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
V_2 -> V_15 |= V_16 ;
V_2 -> V_15 &= ~ V_17 ;
F_13 ( & ( V_2 ) -> V_18 , 0 ) ;
if ( ! F_5 ( & V_2 -> V_11 ) ) {
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( & V_8 -> V_10 ) ;
if ( ! F_5 ( & V_2 -> V_11 ) ) {
F_10 ( & V_2 -> V_11 ) ;
V_8 -> V_14 -- ;
F_14 ( & V_2 -> V_12 ) ;
}
F_8 ( & V_8 -> V_10 ) ;
}
ASSERT ( F_15 ( & V_2 -> V_12 ) >= 1 ) ;
}
struct V_1 *
F_16 (
struct V_7 * V_19 ,
T_1 V_20 ,
T_2 V_21 ,
T_3 V_22 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_23 , V_24 ) ;
if ( F_18 ( ! V_2 ) )
return NULL ;
V_22 &= ~ ( V_25 | V_26 | V_27 | V_28 ) ;
F_13 ( & V_2 -> V_12 , 1 ) ;
F_13 ( & V_2 -> V_18 , 1 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_20 ( & V_2 -> V_11 ) ;
F_20 ( & V_2 -> V_30 ) ;
F_21 ( & V_2 -> V_31 ) ;
F_22 ( & V_2 -> V_32 , 0 ) ;
F_23 ( V_2 ) ;
V_2 -> V_9 = V_19 ;
V_2 -> V_33 = V_21 ;
V_2 -> V_34 = V_21 ;
V_2 -> V_15 = V_22 ;
V_2 -> V_35 = V_20 ;
F_13 ( & V_2 -> V_36 , 0 ) ;
F_24 ( & V_2 -> V_37 ) ;
F_25 ( V_38 ) ;
F_26 ( V_2 , V_39 ) ;
return V_2 ;
}
STATIC int
F_27 (
T_4 * V_2 ,
int V_40 ,
T_3 V_22 )
{
if ( V_2 -> V_41 == NULL ) {
V_2 -> V_4 = V_40 ;
if ( V_40 <= V_42 ) {
V_2 -> V_41 = V_2 -> V_43 ;
} else {
V_2 -> V_41 = F_28 ( sizeof( struct V_44 * ) *
V_40 , V_24 ) ;
if ( V_2 -> V_41 == NULL )
return - V_45 ;
}
memset ( V_2 -> V_41 , 0 , sizeof( struct V_44 * ) * V_40 ) ;
}
return 0 ;
}
STATIC void
F_29 (
T_4 * V_2 )
{
if ( V_2 -> V_41 != V_2 -> V_43 ) {
F_30 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
}
void
F_31 (
T_4 * V_2 )
{
F_32 ( V_2 , V_39 ) ;
ASSERT ( F_5 ( & V_2 -> V_11 ) ) ;
if ( V_2 -> V_15 & V_46 ) {
T_5 V_47 ;
if ( F_1 ( V_2 ) )
F_33 ( V_2 -> V_3 - V_2 -> V_6 ,
V_2 -> V_4 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_4 ; V_47 ++ ) {
struct V_44 * V_44 = V_2 -> V_41 [ V_47 ] ;
F_34 ( V_44 ) ;
}
} else if ( V_2 -> V_15 & V_48 )
F_30 ( V_2 -> V_3 ) ;
F_29 ( V_2 ) ;
F_35 ( V_23 , V_2 ) ;
}
STATIC int
F_36 (
T_4 * V_2 ,
T_5 V_22 )
{
T_2 V_49 ;
T_2 V_50 , V_51 ;
T_6 V_52 = F_37 ( V_22 ) ;
unsigned short V_40 , V_47 ;
T_7 V_53 , V_54 ;
int error ;
V_49 = F_38 ( V_2 -> V_33 ) ;
if ( V_49 < V_5 ) {
V_2 -> V_3 = F_28 ( V_49 , V_24 ) ;
if ( ! V_2 -> V_3 ) {
goto V_55;
}
if ( ( ( unsigned long ) ( V_2 -> V_3 + V_49 - 1 ) & V_56 ) !=
( ( unsigned long ) V_2 -> V_3 & V_56 ) ) {
F_30 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_55;
}
V_2 -> V_6 = F_39 ( V_2 -> V_3 ) ;
V_2 -> V_41 = V_2 -> V_43 ;
V_2 -> V_41 [ 0 ] = F_40 ( V_2 -> V_3 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_15 |= V_48 ;
return 0 ;
}
V_55:
V_53 = F_38 ( V_2 -> V_35 ) >> V_57 ;
V_54 = ( F_38 ( V_2 -> V_35 + V_2 -> V_33 ) + V_5 - 1 ) >> V_57 ;
V_40 = V_54 - V_53 ;
error = F_27 ( V_2 , V_40 , V_22 ) ;
if ( F_18 ( error ) )
return error ;
V_51 = V_2 -> V_6 ;
V_2 -> V_15 |= V_46 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_4 ; V_47 ++ ) {
struct V_44 * V_44 ;
T_5 V_58 = 0 ;
V_59:
V_44 = F_41 ( V_52 ) ;
if ( F_18 ( V_44 == NULL ) ) {
if ( V_22 & V_28 ) {
V_2 -> V_4 = V_47 ;
error = V_45 ;
goto V_60;
}
if ( ! ( ++ V_58 % 100 ) )
F_42 ( NULL ,
L_1 ,
V_61 , V_52 ) ;
F_25 ( V_62 ) ;
F_43 ( V_63 , V_64 / 50 ) ;
goto V_59;
}
F_25 ( V_65 ) ;
V_50 = F_44 ( T_2 , V_49 , V_5 - V_51 ) ;
V_49 -= V_50 ;
V_2 -> V_41 [ V_47 ] = V_44 ;
V_51 = 0 ;
}
return 0 ;
V_60:
for ( V_47 = 0 ; V_47 < V_2 -> V_4 ; V_47 ++ )
F_34 ( V_2 -> V_41 [ V_47 ] ) ;
return error ;
}
STATIC int
F_45 (
T_4 * V_2 ,
T_5 V_22 )
{
ASSERT ( V_2 -> V_15 & V_46 ) ;
if ( V_2 -> V_4 == 1 ) {
V_2 -> V_3 = F_46 ( V_2 -> V_41 [ 0 ] ) + V_2 -> V_6 ;
} else if ( V_22 & V_25 ) {
V_2 -> V_3 = NULL ;
} else {
int V_66 = 0 ;
do {
V_2 -> V_3 = F_47 ( V_2 -> V_41 , V_2 -> V_4 ,
- 1 , V_67 ) ;
if ( V_2 -> V_3 )
break;
F_48 () ;
} while ( V_66 ++ <= 1 );
if ( ! V_2 -> V_3 )
return - V_45 ;
V_2 -> V_3 += V_2 -> V_6 ;
}
return 0 ;
}
T_4 *
F_49 (
struct V_7 * V_8 ,
T_1 V_20 ,
T_2 V_21 ,
T_3 V_22 ,
T_4 * V_68 )
{
T_2 V_69 ;
struct V_70 * V_71 ;
struct V_72 * * V_73 ;
struct V_72 * V_74 ;
T_4 * V_2 ;
V_69 = F_38 ( V_21 ) ;
ASSERT ( ! ( V_69 < ( 1 << V_8 -> V_75 ) ) ) ;
ASSERT ( ! ( F_38 ( V_20 ) & ( T_7 ) V_8 -> V_76 ) ) ;
V_71 = F_50 ( V_8 -> V_77 ,
F_51 ( V_8 -> V_77 , V_20 ) ) ;
F_4 ( & V_71 -> V_78 ) ;
V_73 = & V_71 -> V_79 . V_72 ;
V_74 = NULL ;
V_2 = NULL ;
while ( * V_73 ) {
V_74 = * V_73 ;
V_2 = F_52 ( V_74 , struct V_1 , V_31 ) ;
if ( V_20 < V_2 -> V_35 )
V_73 = & ( * V_73 ) -> V_80 ;
else if ( V_20 > V_2 -> V_35 )
V_73 = & ( * V_73 ) -> V_81 ;
else {
if ( V_2 -> V_33 != V_21 ) {
ASSERT ( V_2 -> V_15 & V_16 ) ;
V_73 = & ( * V_73 ) -> V_81 ;
continue;
}
F_6 ( & V_2 -> V_12 ) ;
goto V_82;
}
}
if ( V_68 ) {
F_53 ( & V_68 -> V_31 , V_74 , V_73 ) ;
F_54 ( & V_68 -> V_31 , & V_71 -> V_79 ) ;
V_68 -> V_83 = V_71 ;
F_8 ( & V_71 -> V_78 ) ;
} else {
F_25 ( V_84 ) ;
F_8 ( & V_71 -> V_78 ) ;
F_55 ( V_71 ) ;
}
return V_68 ;
V_82:
F_8 ( & V_71 -> V_78 ) ;
F_55 ( V_71 ) ;
if ( ! F_56 ( V_2 ) ) {
if ( V_22 & V_26 ) {
F_57 ( V_2 ) ;
F_25 ( V_85 ) ;
return NULL ;
}
F_58 ( V_2 ) ;
F_25 ( V_86 ) ;
}
if ( V_2 -> V_15 & V_16 ) {
ASSERT ( ( V_2 -> V_15 & V_17 ) == 0 ) ;
V_2 -> V_15 &= V_48 | V_46 ;
}
F_59 ( V_2 , V_22 , V_39 ) ;
F_25 ( V_87 ) ;
return V_2 ;
}
struct V_1 *
F_60 (
T_8 * V_19 ,
T_1 V_20 ,
T_2 V_21 ,
T_3 V_22 )
{
struct V_1 * V_2 ;
struct V_1 * V_68 ;
int error = 0 ;
V_2 = F_49 ( V_19 , V_20 , V_21 , V_22 , NULL ) ;
if ( F_61 ( V_2 ) )
goto V_82;
V_68 = F_16 ( V_19 , V_20 , V_21 , V_22 ) ;
if ( F_18 ( ! V_68 ) )
return NULL ;
error = F_36 ( V_68 , V_22 ) ;
if ( error ) {
F_35 ( V_23 , V_68 ) ;
return NULL ;
}
V_2 = F_49 ( V_19 , V_20 , V_21 , V_22 , V_68 ) ;
if ( ! V_2 ) {
F_31 ( V_68 ) ;
return NULL ;
}
if ( V_2 != V_68 )
F_31 ( V_68 ) ;
V_2 -> V_34 = V_2 -> V_33 ;
V_82:
if ( ! V_2 -> V_3 ) {
error = F_45 ( V_2 , V_22 ) ;
if ( F_18 ( error ) ) {
F_62 ( V_19 -> V_77 ,
L_2 , V_61 ) ;
F_63 ( V_2 ) ;
return NULL ;
}
}
F_25 ( V_88 ) ;
F_64 ( V_2 , V_22 , V_39 ) ;
return V_2 ;
}
STATIC int
F_65 (
T_4 * V_2 ,
T_3 V_22 )
{
ASSERT ( ! ( V_22 & V_89 ) ) ;
ASSERT ( V_2 -> V_35 != V_90 ) ;
V_2 -> V_15 &= ~ ( V_89 | V_27 | V_28 ) ;
V_2 -> V_15 |= V_22 & ( V_91 | V_27 | V_28 ) ;
F_66 ( V_2 ) ;
if ( V_22 & V_27 )
return 0 ;
return F_67 ( V_2 ) ;
}
T_4 *
F_68 (
T_8 * V_19 ,
T_1 V_20 ,
T_2 V_21 ,
T_3 V_22 )
{
T_4 * V_2 ;
V_22 |= V_91 ;
V_2 = F_60 ( V_19 , V_20 , V_21 , V_22 ) ;
if ( V_2 ) {
F_69 ( V_2 , V_22 , V_39 ) ;
if ( ! F_70 ( V_2 ) ) {
F_25 ( V_92 ) ;
F_65 ( V_2 , V_22 ) ;
} else if ( V_22 & V_27 ) {
F_63 ( V_2 ) ;
return NULL ;
} else {
V_2 -> V_15 &= ~ V_91 ;
}
}
return V_2 ;
}
void
F_71 (
T_8 * V_19 ,
T_1 V_20 ,
T_2 V_21 )
{
if ( F_72 ( V_19 -> V_93 ) )
return;
F_68 ( V_19 , V_20 , V_21 ,
V_26 | V_27 | V_28 ) ;
}
struct V_1 *
F_73 (
struct V_7 * V_19 ,
T_1 V_94 ,
T_2 V_21 ,
int V_22 )
{
T_4 * V_2 ;
int error ;
V_2 = F_74 ( V_19 , V_21 , V_22 ) ;
if ( ! V_2 )
return NULL ;
F_75 ( V_2 , V_94 ) ;
F_76 ( V_2 ) ;
F_77 ( V_19 -> V_77 , V_2 ) ;
error = F_67 ( V_2 ) ;
if ( error ) {
F_63 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void
F_78 (
struct V_1 * V_2 ,
T_2 V_21 )
{
if ( V_2 -> V_41 )
F_29 ( V_2 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_33 = V_21 ;
V_2 -> V_34 = V_21 ;
V_2 -> V_35 = V_90 ;
}
static inline struct V_44 *
F_79 (
void * V_95 )
{
if ( ( ! F_80 ( V_95 ) ) ) {
return F_40 ( V_95 ) ;
} else {
return F_81 ( V_95 ) ;
}
}
int
F_82 (
T_4 * V_2 ,
void * V_96 ,
T_2 V_97 )
{
int V_98 ;
int V_47 = 0 ;
unsigned long V_99 ;
unsigned long V_51 ;
T_2 V_100 ;
int V_40 ;
V_99 = ( unsigned long ) V_96 & V_56 ;
V_51 = ( unsigned long ) V_96 - V_99 ;
V_100 = F_83 ( V_97 + V_51 ) ;
V_40 = V_100 >> V_57 ;
if ( V_2 -> V_41 )
F_29 ( V_2 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_3 = V_96 ;
V_98 = F_27 ( V_2 , V_40 , 0 ) ;
if ( V_98 )
return V_98 ;
V_2 -> V_6 = V_51 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_4 ; V_47 ++ ) {
V_2 -> V_41 [ V_47 ] = F_79 ( ( void * ) V_99 ) ;
V_99 += V_5 ;
}
V_2 -> V_34 = F_84 ( V_97 ) ;
V_2 -> V_33 = F_84 ( V_100 ) ;
return 0 ;
}
T_4 *
F_74 (
struct V_7 * V_19 ,
T_2 V_21 ,
int V_22 )
{
unsigned long V_40 ;
int error , V_47 ;
T_4 * V_2 ;
V_2 = F_16 ( V_19 , V_90 , V_21 , 0 ) ;
if ( F_18 ( V_2 == NULL ) )
goto V_101;
V_40 = F_83 ( V_21 << V_102 ) >> V_57 ;
error = F_27 ( V_2 , V_40 , 0 ) ;
if ( error )
goto V_103;
for ( V_47 = 0 ; V_47 < V_40 ; V_47 ++ ) {
V_2 -> V_41 [ V_47 ] = F_41 ( F_37 ( V_22 ) ) ;
if ( ! V_2 -> V_41 [ V_47 ] )
goto V_104;
}
V_2 -> V_15 |= V_46 ;
error = F_45 ( V_2 , 0 ) ;
if ( F_18 ( error ) ) {
F_62 ( V_19 -> V_77 ,
L_2 , V_61 ) ;
goto V_104;
}
F_85 ( V_2 , V_39 ) ;
return V_2 ;
V_104:
while ( -- V_47 >= 0 )
F_34 ( V_2 -> V_41 [ V_47 ] ) ;
F_29 ( V_2 ) ;
V_103:
F_35 ( V_23 , V_2 ) ;
V_101:
return NULL ;
}
void
F_86 (
T_4 * V_2 )
{
F_87 ( V_2 , V_39 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
void
F_57 (
T_4 * V_2 )
{
struct V_70 * V_71 = V_2 -> V_83 ;
F_88 ( V_2 , V_39 ) ;
if ( ! V_71 ) {
ASSERT ( F_5 ( & V_2 -> V_11 ) ) ;
ASSERT ( F_89 ( & V_2 -> V_31 ) ) ;
if ( F_90 ( & V_2 -> V_12 ) )
F_31 ( V_2 ) ;
return;
}
ASSERT ( ! F_89 ( & V_2 -> V_31 ) ) ;
ASSERT ( F_15 ( & V_2 -> V_12 ) > 0 ) ;
if ( F_91 ( & V_2 -> V_12 , & V_71 -> V_78 ) ) {
if ( ! ( V_2 -> V_15 & V_16 ) &&
F_15 ( & V_2 -> V_18 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_71 -> V_78 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_15 & V_17 ) ) ;
F_92 ( & V_2 -> V_31 , & V_71 -> V_79 ) ;
F_8 ( & V_71 -> V_78 ) ;
F_55 ( V_71 ) ;
F_31 ( V_2 ) ;
}
}
}
int
F_56 (
struct V_1 * V_2 )
{
int V_105 ;
V_105 = F_93 ( & V_2 -> V_32 ) == 0 ;
if ( V_105 )
F_23 ( V_2 ) ;
else if ( F_15 ( & V_2 -> V_36 ) && ( V_2 -> V_15 & V_16 ) )
F_94 ( V_2 -> V_9 -> V_77 , 0 ) ;
F_95 ( V_2 , V_39 ) ;
return V_105 ;
}
void
F_58 (
struct V_1 * V_2 )
{
F_96 ( V_2 , V_39 ) ;
if ( F_15 ( & V_2 -> V_36 ) && ( V_2 -> V_15 & V_16 ) )
F_94 ( V_2 -> V_9 -> V_77 , 0 ) ;
F_97 ( & V_2 -> V_32 ) ;
F_23 ( V_2 ) ;
F_98 ( V_2 , V_39 ) ;
}
void
F_99 (
struct V_1 * V_2 )
{
F_100 ( V_2 ) ;
F_101 ( & V_2 -> V_32 ) ;
F_102 ( V_2 , V_39 ) ;
}
STATIC void
F_103 (
T_4 * V_2 )
{
F_104 ( V_106 , V_107 ) ;
if ( F_15 ( & V_2 -> V_36 ) == 0 )
return;
F_105 ( & V_2 -> V_37 , & V_106 ) ;
for (; ; ) {
F_106 ( V_108 ) ;
if ( F_15 ( & V_2 -> V_36 ) == 0 )
break;
F_107 () ;
}
F_108 ( & V_2 -> V_37 , & V_106 ) ;
F_106 ( V_109 ) ;
}
STATIC void
F_109 (
struct V_110 * V_111 )
{
T_4 * V_2 =
F_110 ( V_111 , T_4 , V_112 ) ;
if ( V_2 -> V_113 )
( * ( V_2 -> V_113 ) ) ( V_2 ) ;
else if ( V_2 -> V_15 & V_27 )
F_63 ( V_2 ) ;
}
void
F_111 (
T_4 * V_2 ,
int V_114 )
{
F_112 ( V_2 , V_39 ) ;
V_2 -> V_15 &= ~ ( V_91 | V_89 | V_28 ) ;
if ( V_2 -> V_115 == 0 )
V_2 -> V_15 |= V_116 ;
if ( ( V_2 -> V_113 ) || ( V_2 -> V_15 & V_27 ) ) {
if ( V_114 ) {
F_113 ( & V_2 -> V_112 , F_109 ) ;
F_114 ( V_117 , & V_2 -> V_112 ) ;
} else {
F_109 ( & V_2 -> V_112 ) ;
}
} else {
F_115 ( & V_2 -> V_29 ) ;
}
}
void
F_116 (
T_4 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_115 = ( unsigned short ) error ;
F_117 ( V_2 , error , V_39 ) ;
}
void
F_118 (
struct V_1 * V_2 ,
const char * V_118 )
{
F_119 ( V_2 -> V_9 -> V_77 ,
L_3 ,
( V_119 ) F_120 ( V_2 ) , V_118 , V_2 -> V_115 , V_2 -> V_33 ) ;
}
STATIC int
F_121 (
T_4 * V_2 )
{
#ifdef F_122
ASSERT ( F_123 ( V_2 ) || V_2 -> V_113 ) ;
#endif
F_116 ( V_2 , V_120 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_11 ( V_2 ) ;
F_111 ( V_2 , 0 ) ;
return V_120 ;
}
STATIC int
F_126 (
struct V_1 * V_2 )
{
T_9 V_121 = V_2 -> V_15 ;
F_124 ( V_2 ) ;
F_127 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_113 = NULL ;
if ( ! ( V_121 & V_27 ) ) {
F_116 ( V_2 , V_120 ) ;
F_115 ( & V_2 -> V_29 ) ;
} else {
F_63 ( V_2 ) ;
}
return V_120 ;
}
STATIC int
F_128 (
struct V_1 * V_2 )
{
if ( F_129 ( V_2 -> V_9 -> V_77 ) ) {
F_130 ( V_2 , V_39 ) ;
if ( ! V_2 -> V_113 && ! F_123 ( V_2 ) )
return F_126 ( V_2 ) ;
else
return F_121 ( V_2 ) ;
}
F_66 ( V_2 ) ;
return 0 ;
}
int
F_131 (
struct V_1 * V_2 )
{
int error ;
ASSERT ( F_12 ( V_2 ) ) ;
V_2 -> V_15 |= V_89 ;
V_2 -> V_15 &= ~ ( V_27 | V_91 | V_17 ) ;
F_128 ( V_2 ) ;
error = F_67 ( V_2 ) ;
if ( error ) {
F_132 ( V_2 -> V_9 -> V_77 ,
V_122 ) ;
}
return error ;
}
void
F_77 (
struct V_123 * V_124 ,
struct V_1 * V_2 )
{
if ( F_129 ( V_124 ) ) {
F_130 ( V_2 , V_39 ) ;
F_126 ( V_2 ) ;
return;
}
F_66 ( V_2 ) ;
}
STATIC void
F_133 (
T_4 * V_2 ,
int V_114 )
{
if ( F_90 ( & V_2 -> V_125 ) == 1 )
F_111 ( V_2 , V_114 ) ;
}
STATIC void
F_134 (
struct V_126 * V_126 ,
int error )
{
T_4 * V_2 = ( T_4 * ) V_126 -> V_127 ;
F_116 ( V_2 , - error ) ;
if ( ! error && F_1 ( V_2 ) && ( V_2 -> V_15 & V_91 ) )
F_135 ( V_2 -> V_3 , F_2 ( V_2 ) ) ;
F_133 ( V_2 , 1 ) ;
F_136 ( V_126 ) ;
}
STATIC void
F_137 (
T_4 * V_2 )
{
int V_128 , V_129 , V_130 , V_131 ;
struct V_126 * V_126 ;
int V_51 = V_2 -> V_6 ;
int V_49 = F_38 ( V_2 -> V_34 ) ;
T_10 V_132 = V_2 -> V_35 ;
V_130 = V_2 -> V_4 ;
V_129 = 0 ;
if ( V_2 -> V_15 & V_89 ) {
if ( V_2 -> V_15 & V_133 )
V_128 = V_134 ;
else
V_128 = V_135 ;
if ( V_2 -> V_15 & V_136 )
V_128 |= V_137 ;
if ( V_2 -> V_15 & V_138 )
V_128 |= V_139 ;
} else if ( V_2 -> V_15 & V_28 ) {
V_128 = V_140 ;
} else {
V_128 = V_141 ;
}
V_128 |= V_142 ;
V_143:
F_6 ( & V_2 -> V_125 ) ;
V_131 = V_144 >> ( V_57 - V_102 ) ;
if ( V_131 > V_130 )
V_131 = V_130 ;
V_126 = F_138 ( V_145 , V_131 ) ;
V_126 -> V_146 = V_2 -> V_9 -> V_147 ;
V_126 -> V_148 = V_132 ;
V_126 -> V_149 = F_134 ;
V_126 -> V_127 = V_2 ;
for (; V_49 && V_131 ; V_131 -- , V_129 ++ ) {
int V_150 , V_50 = V_5 - V_51 ;
if ( V_50 > V_49 )
V_50 = V_49 ;
V_150 = F_139 ( V_126 , V_2 -> V_41 [ V_129 ] , V_50 , V_51 ) ;
if ( V_150 < V_50 )
break;
V_51 = 0 ;
V_132 += F_84 ( V_50 ) ;
V_49 -= V_50 ;
V_130 -- ;
}
if ( F_61 ( V_126 -> V_151 ) ) {
if ( F_1 ( V_2 ) ) {
F_140 ( V_2 -> V_3 ,
F_2 ( V_2 ) ) ;
}
F_141 ( V_128 , V_126 ) ;
if ( V_49 )
goto V_143;
} else {
F_116 ( V_2 , V_120 ) ;
F_136 ( V_126 ) ;
}
}
void
F_66 (
T_4 * V_2 )
{
F_142 ( V_2 , V_39 ) ;
ASSERT ( ! ( V_2 -> V_15 & V_17 ) ) ;
if ( V_2 -> V_15 & V_89 )
F_103 ( V_2 ) ;
F_86 ( V_2 ) ;
F_13 ( & V_2 -> V_125 , 1 ) ;
F_137 ( V_2 ) ;
F_133 ( V_2 , 1 ) ;
F_57 ( V_2 ) ;
}
int
F_67 (
T_4 * V_2 )
{
F_143 ( V_2 , V_39 ) ;
if ( ! V_2 -> V_115 )
F_144 ( & V_2 -> V_29 ) ;
F_145 ( V_2 , V_39 ) ;
return V_2 -> V_115 ;
}
T_11
F_146 (
T_4 * V_2 ,
T_2 V_51 )
{
struct V_44 * V_44 ;
if ( V_2 -> V_3 )
return V_2 -> V_3 + V_51 ;
V_51 += V_2 -> V_6 ;
V_44 = V_2 -> V_41 [ V_51 >> V_57 ] ;
return ( T_11 ) F_46 ( V_44 ) + ( V_51 & ( V_5 - 1 ) ) ;
}
void
F_147 (
T_4 * V_2 ,
T_2 V_152 ,
T_2 V_153 ,
void * V_154 ,
T_12 V_155 )
{
T_2 V_156 ;
V_156 = V_152 + V_153 ;
while ( V_152 < V_156 ) {
struct V_44 * V_44 ;
int V_157 , V_158 , V_159 ;
V_157 = ( V_152 + V_2 -> V_6 ) >> V_57 ;
V_158 = ( V_152 + V_2 -> V_6 ) & ~ V_56 ;
V_44 = V_2 -> V_41 [ V_157 ] ;
V_159 = F_44 ( T_2 , V_5 - V_158 ,
F_38 ( V_2 -> V_34 ) - V_152 ) ;
ASSERT ( ( V_159 + V_158 ) <= V_5 ) ;
switch ( V_155 ) {
case V_160 :
memset ( F_46 ( V_44 ) + V_158 , 0 , V_159 ) ;
break;
case V_161 :
memcpy ( V_154 , F_46 ( V_44 ) + V_158 , V_159 ) ;
break;
case V_162 :
memcpy ( F_46 ( V_44 ) + V_158 , V_154 , V_159 ) ;
}
V_152 += V_159 ;
V_154 += V_159 ;
}
}
void
F_148 (
struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_163:
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
V_2 = F_149 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( F_15 ( & V_2 -> V_12 ) > 1 ) {
F_8 ( & V_8 -> V_10 ) ;
F_150 ( 100 ) ;
goto V_163;
}
F_13 ( & V_2 -> V_18 , 0 ) ;
F_8 ( & V_8 -> V_10 ) ;
F_57 ( V_2 ) ;
F_4 ( & V_8 -> V_10 ) ;
}
F_8 ( & V_8 -> V_10 ) ;
}
int
F_151 (
struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_7 * V_8 = F_110 ( V_165 ,
struct V_7 , V_168 ) ;
struct V_1 * V_2 ;
int V_169 = V_167 -> V_169 ;
F_152 ( V_170 ) ;
if ( ! V_169 )
return V_8 -> V_14 ;
F_4 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_8 -> V_13 ) ) {
if ( V_169 -- <= 0 )
break;
V_2 = F_149 ( & V_8 -> V_13 , struct V_1 , V_11 ) ;
if ( ! F_153 ( & V_2 -> V_18 , - 1 , 0 ) ) {
F_154 ( & V_2 -> V_11 , & V_8 -> V_13 ) ;
continue;
}
F_155 ( & V_2 -> V_11 , & V_170 ) ;
V_8 -> V_14 -- ;
}
F_8 ( & V_8 -> V_10 ) ;
while ( ! F_5 ( & V_170 ) ) {
V_2 = F_149 ( & V_170 , struct V_1 , V_11 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_57 ( V_2 ) ;
}
return V_8 -> V_14 ;
}
void
F_156 (
struct V_123 * V_124 ,
struct V_7 * V_8 )
{
F_157 ( & V_8 -> V_168 ) ;
if ( V_124 -> V_171 & V_172 )
F_158 ( V_8 ) ;
F_30 ( V_8 ) ;
}
STATIC int
F_159 (
T_8 * V_8 ,
unsigned int V_173 ,
unsigned int V_174 ,
int V_175 )
{
V_8 -> V_176 = V_173 ;
V_8 -> V_75 = F_160 ( V_174 ) - 1 ;
V_8 -> V_76 = V_174 - 1 ;
if ( F_161 ( V_8 -> V_147 , V_174 ) ) {
char V_177 [ V_178 ] ;
F_162 ( V_8 -> V_147 , V_177 ) ;
F_62 ( V_8 -> V_77 ,
L_4 ,
V_174 , V_177 ) ;
return V_179 ;
}
return 0 ;
}
STATIC int
F_163 (
T_8 * V_8 ,
struct V_180 * V_181 )
{
return F_159 ( V_8 ,
V_5 , F_164 ( V_181 ) , 0 ) ;
}
int
F_165 (
T_8 * V_8 ,
unsigned int V_173 ,
unsigned int V_174 )
{
return F_159 ( V_8 , V_173 , V_174 , 1 ) ;
}
T_8 *
F_166 (
struct V_123 * V_124 ,
struct V_180 * V_181 ,
int V_182 ,
const char * V_183 )
{
T_8 * V_8 ;
V_8 = F_167 ( sizeof( * V_8 ) , V_184 ) ;
V_8 -> V_77 = V_124 ;
V_8 -> V_185 = V_181 -> V_186 ;
V_8 -> V_147 = V_181 ;
V_8 -> V_93 = F_168 ( V_181 ) ;
if ( ! V_8 -> V_93 )
goto error;
F_20 ( & V_8 -> V_13 ) ;
F_169 ( & V_8 -> V_10 ) ;
if ( F_163 ( V_8 , V_181 ) )
goto error;
V_8 -> V_168 . V_165 = F_151 ;
V_8 -> V_168 . V_187 = V_188 ;
F_170 ( & V_8 -> V_168 ) ;
return V_8 ;
error:
F_30 ( V_8 ) ;
return NULL ;
}
bool
F_171 (
struct V_1 * V_2 ,
struct V_189 * V_190 )
{
ASSERT ( F_12 ( V_2 ) ) ;
ASSERT ( ! ( V_2 -> V_15 & V_91 ) ) ;
if ( V_2 -> V_15 & V_17 ) {
F_172 ( V_2 , V_39 ) ;
return false ;
}
F_173 ( V_2 , V_39 ) ;
V_2 -> V_15 |= V_17 ;
if ( F_5 ( & V_2 -> V_30 ) ) {
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_30 , V_190 ) ;
}
return true ;
}
static int
F_174 (
void * V_191 ,
struct V_189 * V_192 ,
struct V_189 * V_193 )
{
struct V_1 * V_194 = F_110 ( V_192 , struct V_1 , V_30 ) ;
struct V_1 * V_2 = F_110 ( V_193 , struct V_1 , V_30 ) ;
T_1 V_195 ;
V_195 = V_194 -> V_35 - V_2 -> V_35 ;
if ( V_195 < 0 )
return - 1 ;
if ( V_195 > 0 )
return 1 ;
return 0 ;
}
static int
F_175 (
struct V_189 * V_196 ,
struct V_189 * V_197 ,
bool V_106 )
{
struct V_198 V_199 ;
struct V_1 * V_2 , * V_200 ;
int V_201 = 0 ;
F_176 (bp, n, buffer_list, b_list) {
if ( ! V_106 ) {
if ( F_177 ( V_2 ) ) {
V_201 ++ ;
continue;
}
if ( ! F_56 ( V_2 ) )
continue;
} else {
F_58 ( V_2 ) ;
}
if ( ! ( V_2 -> V_15 & V_17 ) ) {
F_10 ( & V_2 -> V_30 ) ;
F_63 ( V_2 ) ;
continue;
}
F_154 ( & V_2 -> V_30 , V_197 ) ;
F_178 ( V_2 , V_39 ) ;
}
F_179 ( NULL , V_197 , F_174 ) ;
F_180 ( & V_199 ) ;
F_176 (bp, n, io_list, b_list) {
V_2 -> V_15 &= ~ ( V_17 | V_27 ) ;
V_2 -> V_15 |= V_89 ;
if ( ! V_106 ) {
V_2 -> V_15 |= V_27 ;
F_10 ( & V_2 -> V_30 ) ;
}
F_128 ( V_2 ) ;
}
F_181 ( & V_199 ) ;
return V_201 ;
}
int
F_182 (
struct V_189 * V_196 )
{
F_152 ( V_197 ) ;
return F_175 ( V_196 , & V_197 , false ) ;
}
int
F_183 (
struct V_189 * V_196 )
{
F_152 ( V_197 ) ;
int error = 0 , V_202 ;
struct V_1 * V_2 ;
F_175 ( V_196 , & V_197 , true ) ;
while ( ! F_5 ( & V_197 ) ) {
V_2 = F_149 ( & V_197 , struct V_1 , V_30 ) ;
F_10 ( & V_2 -> V_30 ) ;
V_202 = F_67 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( ! error )
error = V_202 ;
}
return error ;
}
int T_13
F_184 ( void )
{
V_23 = F_185 ( sizeof( T_4 ) , L_5 ,
V_203 , NULL ) ;
if ( ! V_23 )
goto V_204;
V_117 = F_186 ( L_6 ,
V_205 | V_206 , 1 ) ;
if ( ! V_117 )
goto V_207;
return 0 ;
V_207:
F_187 ( V_23 ) ;
V_204:
return - V_45 ;
}
void
F_188 ( void )
{
F_189 ( V_117 ) ;
F_187 ( V_23 ) ;
}
