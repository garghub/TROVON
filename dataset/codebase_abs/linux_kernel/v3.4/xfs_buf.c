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
F_12 ( V_2 ) ;
F_13 ( & ( V_2 ) -> V_17 , 0 ) ;
if ( ! F_5 ( & V_2 -> V_12 ) ) {
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( & V_9 -> V_11 ) ;
if ( ! F_5 ( & V_2 -> V_12 ) ) {
F_10 ( & V_2 -> V_12 ) ;
V_9 -> V_15 -- ;
F_14 ( & V_2 -> V_13 ) ;
}
F_8 ( & V_9 -> V_11 ) ;
}
ASSERT ( F_15 ( & V_2 -> V_13 ) >= 1 ) ;
}
struct V_1 *
F_16 (
struct V_8 * V_18 ,
T_1 V_19 ,
T_2 V_20 ,
T_3 V_21 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_22 , F_18 ( V_21 ) ) ;
if ( F_19 ( ! V_2 ) )
return NULL ;
V_21 &= ~ ( V_23 | V_4 | V_24 | V_25 ) ;
memset ( V_2 , 0 , sizeof( V_26 ) ) ;
F_13 ( & V_2 -> V_13 , 1 ) ;
F_13 ( & V_2 -> V_17 , 1 ) ;
F_20 ( & V_2 -> V_27 ) ;
F_21 ( & V_2 -> V_12 ) ;
F_21 ( & V_2 -> V_28 ) ;
F_22 ( & V_2 -> V_29 ) ;
F_23 ( & V_2 -> V_30 , 0 ) ;
F_24 ( V_2 ) ;
V_2 -> V_10 = V_18 ;
V_2 -> V_31 = V_19 ;
V_2 -> V_32 = V_2 -> V_33 = V_20 ;
V_2 -> V_3 = V_21 ;
V_2 -> V_34 = V_35 ;
F_13 ( & V_2 -> V_36 , 0 ) ;
F_25 ( & V_2 -> V_37 ) ;
F_26 ( V_38 ) ;
F_27 ( V_2 , V_39 ) ;
return V_2 ;
}
STATIC int
F_28 (
V_26 * V_2 ,
int V_40 ,
T_3 V_21 )
{
if ( V_2 -> V_41 == NULL ) {
V_2 -> V_7 = F_29 ( V_2 -> V_31 ) ;
V_2 -> V_5 = V_40 ;
if ( V_40 <= V_42 ) {
V_2 -> V_41 = V_2 -> V_43 ;
} else {
V_2 -> V_41 = F_30 ( sizeof( struct V_44 * ) *
V_40 , F_18 ( V_21 ) ) ;
if ( V_2 -> V_41 == NULL )
return - V_45 ;
}
memset ( V_2 -> V_41 , 0 , sizeof( struct V_44 * ) * V_40 ) ;
}
return 0 ;
}
STATIC void
F_31 (
V_26 * V_2 )
{
if ( V_2 -> V_41 != V_2 -> V_43 ) {
F_32 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
}
void
F_33 (
V_26 * V_2 )
{
F_34 ( V_2 , V_39 ) ;
ASSERT ( F_5 ( & V_2 -> V_12 ) ) ;
if ( V_2 -> V_3 & V_46 ) {
T_4 V_47 ;
if ( F_1 ( V_2 ) )
F_35 ( V_2 -> V_48 - V_2 -> V_7 ,
V_2 -> V_5 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 ; V_47 ++ ) {
struct V_44 * V_44 = V_2 -> V_41 [ V_47 ] ;
F_36 ( V_44 ) ;
}
} else if ( V_2 -> V_3 & V_49 )
F_32 ( V_2 -> V_48 ) ;
F_31 ( V_2 ) ;
F_37 ( V_22 , V_2 ) ;
}
STATIC int
F_38 (
V_26 * V_2 ,
T_4 V_21 )
{
T_2 V_50 = V_2 -> V_33 ;
T_2 V_51 , V_52 ;
T_5 V_53 = F_39 ( V_21 ) ;
unsigned short V_40 , V_47 ;
T_1 V_54 ;
int error ;
if ( V_2 -> V_32 < V_6 ) {
V_2 -> V_48 = F_30 ( V_2 -> V_32 , F_18 ( V_21 ) ) ;
if ( ! V_2 -> V_48 ) {
goto V_55;
}
if ( ( ( unsigned long ) ( V_2 -> V_48 + V_2 -> V_32 - 1 ) &
V_56 ) !=
( ( unsigned long ) V_2 -> V_48 & V_56 ) ) {
F_32 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
goto V_55;
}
V_2 -> V_7 = F_40 ( V_2 -> V_48 ) ;
V_2 -> V_41 = V_2 -> V_43 ;
V_2 -> V_41 [ 0 ] = F_41 ( V_2 -> V_48 ) ;
V_2 -> V_5 = 1 ;
V_2 -> V_3 |= V_4 | V_49 ;
return 0 ;
}
V_55:
V_54 = V_2 -> V_31 + V_2 -> V_32 ;
V_40 = F_42 ( V_54 ) - F_43 ( V_2 -> V_31 ) ;
error = F_28 ( V_2 , V_40 , V_21 ) ;
if ( F_19 ( error ) )
return error ;
V_52 = V_2 -> V_7 ;
V_2 -> V_3 |= V_46 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 ; V_47 ++ ) {
struct V_44 * V_44 ;
T_4 V_57 = 0 ;
V_58:
V_44 = F_44 ( V_53 ) ;
if ( F_19 ( V_44 == NULL ) ) {
if ( V_21 & V_25 ) {
V_2 -> V_5 = V_47 ;
error = V_45 ;
goto V_59;
}
if ( ! ( ++ V_57 % 100 ) )
F_45 ( NULL ,
L_1 ,
V_60 , V_53 ) ;
F_26 ( V_61 ) ;
F_46 ( V_62 , V_63 / 50 ) ;
goto V_58;
}
F_26 ( V_64 ) ;
V_51 = F_47 ( T_2 , V_50 , V_6 - V_52 ) ;
V_50 -= V_51 ;
V_2 -> V_41 [ V_47 ] = V_44 ;
V_52 = 0 ;
}
return 0 ;
V_59:
for ( V_47 = 0 ; V_47 < V_2 -> V_5 ; V_47 ++ )
F_36 ( V_2 -> V_41 [ V_47 ] ) ;
return error ;
}
STATIC int
F_48 (
V_26 * V_2 ,
T_4 V_21 )
{
ASSERT ( V_2 -> V_3 & V_46 ) ;
if ( V_2 -> V_5 == 1 ) {
V_2 -> V_48 = F_49 ( V_2 -> V_41 [ 0 ] ) + V_2 -> V_7 ;
V_2 -> V_3 |= V_4 ;
} else if ( V_21 & V_4 ) {
int V_65 = 0 ;
do {
V_2 -> V_48 = F_50 ( V_2 -> V_41 , V_2 -> V_5 ,
- 1 , V_66 ) ;
if ( V_2 -> V_48 )
break;
F_51 () ;
} while ( V_65 ++ <= 1 );
if ( ! V_2 -> V_48 )
return - V_45 ;
V_2 -> V_48 += V_2 -> V_7 ;
V_2 -> V_3 |= V_4 ;
}
return 0 ;
}
V_26 *
F_52 (
T_6 * V_9 ,
T_1 V_67 ,
T_2 V_68 ,
T_3 V_21 ,
V_26 * V_69 )
{
T_1 V_19 ;
T_2 V_20 ;
struct V_70 * V_71 ;
struct V_72 * * V_73 ;
struct V_72 * V_74 ;
V_26 * V_2 ;
V_19 = ( V_67 << V_75 ) ;
V_20 = ( V_68 << V_75 ) ;
ASSERT ( ! ( V_20 < ( 1 << V_9 -> V_76 ) ) ) ;
ASSERT ( ! ( V_19 & ( T_1 ) V_9 -> V_77 ) ) ;
V_71 = F_53 ( V_9 -> V_78 ,
F_54 ( V_9 -> V_78 , V_67 ) ) ;
F_4 ( & V_71 -> V_79 ) ;
V_73 = & V_71 -> V_80 . V_72 ;
V_74 = NULL ;
V_2 = NULL ;
while ( * V_73 ) {
V_74 = * V_73 ;
V_2 = F_55 ( V_74 , struct V_1 , V_29 ) ;
if ( V_19 < V_2 -> V_31 )
V_73 = & ( * V_73 ) -> V_81 ;
else if ( V_19 > V_2 -> V_31 )
V_73 = & ( * V_73 ) -> V_82 ;
else {
if ( V_2 -> V_32 != V_20 ) {
ASSERT ( V_2 -> V_3 & V_16 ) ;
V_73 = & ( * V_73 ) -> V_82 ;
continue;
}
F_6 ( & V_2 -> V_13 ) ;
goto V_83;
}
}
if ( V_69 ) {
F_56 ( & V_69 -> V_29 , V_74 , V_73 ) ;
F_57 ( & V_69 -> V_29 , & V_71 -> V_80 ) ;
V_69 -> V_84 = V_71 ;
F_8 ( & V_71 -> V_79 ) ;
} else {
F_26 ( V_85 ) ;
F_8 ( & V_71 -> V_79 ) ;
F_58 ( V_71 ) ;
}
return V_69 ;
V_83:
F_8 ( & V_71 -> V_79 ) ;
F_58 ( V_71 ) ;
if ( ! F_59 ( V_2 ) ) {
if ( V_21 & V_86 ) {
F_60 ( V_2 ) ;
F_26 ( V_87 ) ;
return NULL ;
}
F_61 ( V_2 ) ;
F_26 ( V_88 ) ;
}
if ( V_2 -> V_3 & V_16 ) {
ASSERT ( ( V_2 -> V_3 & V_89 ) == 0 ) ;
V_2 -> V_3 &= V_4 | V_49 | V_46 ;
}
F_62 ( V_2 , V_21 , V_39 ) ;
F_26 ( V_90 ) ;
return V_2 ;
}
struct V_1 *
F_63 (
T_6 * V_18 ,
T_1 V_67 ,
T_2 V_68 ,
T_3 V_21 )
{
struct V_1 * V_2 ;
struct V_1 * V_69 ;
int error = 0 ;
V_2 = F_52 ( V_18 , V_67 , V_68 , V_21 , NULL ) ;
if ( F_64 ( V_2 ) )
goto V_83;
V_69 = F_16 ( V_18 , V_67 << V_75 , V_68 << V_75 ,
V_21 ) ;
if ( F_19 ( ! V_69 ) )
return NULL ;
V_2 = F_52 ( V_18 , V_67 , V_68 , V_21 , V_69 ) ;
if ( ! V_2 ) {
F_37 ( V_22 , V_69 ) ;
return NULL ;
}
if ( V_2 == V_69 ) {
error = F_38 ( V_2 , V_21 ) ;
if ( error )
goto V_91;
} else
F_37 ( V_22 , V_69 ) ;
V_2 -> V_34 = V_67 ;
V_2 -> V_33 = V_2 -> V_32 ;
V_83:
if ( ! ( V_2 -> V_3 & V_4 ) ) {
error = F_48 ( V_2 , V_21 ) ;
if ( F_19 ( error ) ) {
F_65 ( V_18 -> V_78 ,
L_2 , V_60 ) ;
goto V_91;
}
}
F_26 ( V_92 ) ;
F_66 ( V_2 , V_21 , V_39 ) ;
return V_2 ;
V_91:
if ( V_21 & ( V_23 | V_86 ) )
F_67 ( V_2 ) ;
F_60 ( V_2 ) ;
return NULL ;
}
STATIC int
F_68 (
V_26 * V_2 ,
T_3 V_21 )
{
int V_93 ;
ASSERT ( ! ( V_21 & ( V_94 | V_95 ) ) ) ;
ASSERT ( V_2 -> V_34 != V_35 ) ;
V_2 -> V_3 &= ~ ( V_95 | V_96 | V_94 | V_25 ) ;
V_2 -> V_3 |= V_21 & ( V_97 | V_96 | V_25 ) ;
V_93 = F_69 ( V_2 ) ;
if ( V_93 || V_2 -> V_98 || ( V_21 & V_96 ) )
return V_93 ;
return F_70 ( V_2 ) ;
}
V_26 *
F_71 (
T_6 * V_18 ,
T_1 V_67 ,
T_2 V_68 ,
T_3 V_21 )
{
V_26 * V_2 ;
V_21 |= V_97 ;
V_2 = F_63 ( V_18 , V_67 , V_68 , V_21 ) ;
if ( V_2 ) {
F_72 ( V_2 , V_21 , V_39 ) ;
if ( ! F_73 ( V_2 ) ) {
F_26 ( V_99 ) ;
F_68 ( V_2 , V_21 ) ;
} else if ( V_21 & V_96 ) {
goto V_91;
} else {
V_2 -> V_3 &= ~ V_97 ;
}
}
return V_2 ;
V_91:
if ( V_21 & ( V_23 | V_86 ) )
F_67 ( V_2 ) ;
F_60 ( V_2 ) ;
return NULL ;
}
void
F_74 (
T_6 * V_18 ,
T_1 V_67 ,
T_2 V_68 )
{
if ( F_75 ( V_18 -> V_100 ) )
return;
F_71 ( V_18 , V_67 , V_68 ,
V_86 | V_96 | V_25 | V_24 ) ;
}
struct V_1 *
F_76 (
struct V_101 * V_102 ,
struct V_8 * V_18 ,
T_7 V_103 ,
T_2 V_104 ,
int V_21 )
{
V_26 * V_2 ;
int error ;
V_2 = F_77 ( V_18 , V_104 , V_21 ) ;
if ( ! V_2 )
return NULL ;
F_78 ( V_2 , V_103 ) ;
F_79 ( V_2 ) ;
F_80 ( V_102 , V_2 ) ;
error = F_70 ( V_2 ) ;
if ( error || V_2 -> V_98 ) {
F_81 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void
F_82 (
struct V_1 * V_2 ,
T_2 V_105 )
{
if ( V_2 -> V_41 )
F_31 ( V_2 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_5 = 0 ;
V_2 -> V_48 = NULL ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = V_2 -> V_33 = V_105 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_3 &= ~ V_4 ;
}
static inline struct V_44 *
F_83 (
void * V_106 )
{
if ( ( ! F_84 ( V_106 ) ) ) {
return F_41 ( V_106 ) ;
} else {
return F_85 ( V_106 ) ;
}
}
int
F_86 (
V_26 * V_2 ,
void * V_107 ,
T_2 V_105 )
{
int V_108 ;
int V_47 = 0 ;
unsigned long V_109 ;
unsigned long V_52 ;
T_2 V_110 ;
int V_40 ;
V_109 = ( unsigned long ) V_107 & V_56 ;
V_52 = ( unsigned long ) V_107 - V_109 ;
V_110 = F_87 ( V_105 + V_52 ) ;
V_40 = V_110 >> V_111 ;
if ( V_2 -> V_41 )
F_31 ( V_2 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_48 = V_107 ;
V_108 = F_28 ( V_2 , V_40 , V_24 ) ;
if ( V_108 )
return V_108 ;
V_2 -> V_7 = V_52 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 ; V_47 ++ ) {
V_2 -> V_41 [ V_47 ] = F_83 ( ( void * ) V_109 ) ;
V_109 += V_6 ;
}
V_2 -> V_33 = V_105 ;
V_2 -> V_32 = V_110 ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
V_26 *
F_77 (
struct V_8 * V_18 ,
T_2 V_105 ,
int V_21 )
{
unsigned long V_40 = F_87 ( V_105 ) >> V_111 ;
int error , V_47 ;
V_26 * V_2 ;
V_2 = F_16 ( V_18 , 0 , V_105 , 0 ) ;
if ( F_19 ( V_2 == NULL ) )
goto V_112;
error = F_28 ( V_2 , V_40 , 0 ) ;
if ( error )
goto V_113;
for ( V_47 = 0 ; V_47 < V_40 ; V_47 ++ ) {
V_2 -> V_41 [ V_47 ] = F_44 ( F_39 ( V_21 ) ) ;
if ( ! V_2 -> V_41 [ V_47 ] )
goto V_114;
}
V_2 -> V_3 |= V_46 ;
error = F_48 ( V_2 , V_4 ) ;
if ( F_19 ( error ) ) {
F_65 ( V_18 -> V_78 ,
L_2 , V_60 ) ;
goto V_114;
}
F_88 ( V_2 , V_39 ) ;
return V_2 ;
V_114:
while ( -- V_47 >= 0 )
F_36 ( V_2 -> V_41 [ V_47 ] ) ;
F_31 ( V_2 ) ;
V_113:
F_37 ( V_22 , V_2 ) ;
V_112:
return NULL ;
}
void
F_89 (
V_26 * V_2 )
{
F_90 ( V_2 , V_39 ) ;
F_6 ( & V_2 -> V_13 ) ;
}
void
F_60 (
V_26 * V_2 )
{
struct V_70 * V_71 = V_2 -> V_84 ;
F_91 ( V_2 , V_39 ) ;
if ( ! V_71 ) {
ASSERT ( F_5 ( & V_2 -> V_12 ) ) ;
ASSERT ( F_92 ( & V_2 -> V_29 ) ) ;
if ( F_93 ( & V_2 -> V_13 ) )
F_33 ( V_2 ) ;
return;
}
ASSERT ( ! F_92 ( & V_2 -> V_29 ) ) ;
ASSERT ( F_15 ( & V_2 -> V_13 ) > 0 ) ;
if ( F_94 ( & V_2 -> V_13 , & V_71 -> V_79 ) ) {
if ( ! ( V_2 -> V_3 & V_16 ) &&
F_15 ( & V_2 -> V_17 ) ) {
F_3 ( V_2 ) ;
F_8 ( & V_71 -> V_79 ) ;
} else {
F_9 ( V_2 ) ;
ASSERT ( ! ( V_2 -> V_3 & ( V_94 | V_89 ) ) ) ;
F_95 ( & V_2 -> V_29 , & V_71 -> V_80 ) ;
F_8 ( & V_71 -> V_79 ) ;
F_58 ( V_71 ) ;
F_33 ( V_2 ) ;
}
}
}
int
F_59 (
struct V_1 * V_2 )
{
int V_115 ;
V_115 = F_96 ( & V_2 -> V_30 ) == 0 ;
if ( V_115 )
F_24 ( V_2 ) ;
else if ( F_15 ( & V_2 -> V_36 ) && ( V_2 -> V_3 & V_16 ) )
F_97 ( V_2 -> V_10 -> V_78 , 0 ) ;
F_98 ( V_2 , V_39 ) ;
return V_115 ;
}
void
F_61 (
struct V_1 * V_2 )
{
F_99 ( V_2 , V_39 ) ;
if ( F_15 ( & V_2 -> V_36 ) && ( V_2 -> V_3 & V_16 ) )
F_97 ( V_2 -> V_10 -> V_78 , 0 ) ;
F_100 ( & V_2 -> V_30 ) ;
F_24 ( V_2 ) ;
F_101 ( V_2 , V_39 ) ;
}
void
F_67 (
struct V_1 * V_2 )
{
F_102 ( V_2 ) ;
F_103 ( & V_2 -> V_30 ) ;
F_104 ( V_2 , V_39 ) ;
}
STATIC void
F_105 (
V_26 * V_2 )
{
F_106 ( V_116 , V_117 ) ;
if ( F_15 ( & V_2 -> V_36 ) == 0 )
return;
F_107 ( & V_2 -> V_37 , & V_116 ) ;
for (; ; ) {
F_108 ( V_118 ) ;
if ( F_15 ( & V_2 -> V_36 ) == 0 )
break;
F_109 () ;
}
F_110 ( & V_2 -> V_37 , & V_116 ) ;
F_108 ( V_119 ) ;
}
STATIC void
F_111 (
struct V_120 * V_121 )
{
V_26 * V_2 =
F_112 ( V_121 , V_26 , V_122 ) ;
if ( V_2 -> V_123 )
( * ( V_2 -> V_123 ) ) ( V_2 ) ;
else if ( V_2 -> V_3 & V_96 )
F_81 ( V_2 ) ;
}
void
F_113 (
V_26 * V_2 ,
int V_124 )
{
F_114 ( V_2 , V_39 ) ;
V_2 -> V_3 &= ~ ( V_97 | V_95 | V_25 ) ;
if ( V_2 -> V_98 == 0 )
V_2 -> V_3 |= V_125 ;
if ( ( V_2 -> V_123 ) || ( V_2 -> V_3 & V_96 ) ) {
if ( V_124 ) {
F_115 ( & V_2 -> V_122 , F_111 ) ;
F_116 ( V_126 , & V_2 -> V_122 ) ;
} else {
F_111 ( & V_2 -> V_122 ) ;
}
} else {
F_117 ( & V_2 -> V_27 ) ;
}
}
void
F_118 (
V_26 * V_2 ,
int error )
{
ASSERT ( error >= 0 && error <= 0xffff ) ;
V_2 -> V_98 = ( unsigned short ) error ;
F_119 ( V_2 , error , V_39 ) ;
}
void
F_120 (
struct V_1 * V_2 ,
const char * V_127 )
{
F_121 ( V_2 -> V_10 -> V_78 ,
L_3 ,
( V_128 ) F_122 ( V_2 ) , V_127 ,
V_2 -> V_98 , F_123 ( V_2 ) ) ;
}
int
F_124 (
struct V_1 * V_2 )
{
int error ;
V_2 -> V_3 |= V_95 ;
V_2 -> V_3 &= ~ ( V_96 | V_97 ) ;
F_12 ( V_2 ) ;
F_125 ( V_2 ) ;
error = F_70 ( V_2 ) ;
if ( error ) {
F_126 ( V_2 -> V_10 -> V_78 ,
V_129 ) ;
}
return error ;
}
STATIC int
F_127 (
V_26 * V_2 )
{
#ifdef F_128
ASSERT ( F_129 ( V_2 ) || V_2 -> V_123 ) ;
#endif
F_118 ( V_2 , V_130 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_11 ( V_2 ) ;
F_113 ( V_2 , 0 ) ;
return V_130 ;
}
STATIC int
F_132 (
struct V_1 * V_2 )
{
T_8 V_131 = V_2 -> V_3 ;
F_130 ( V_2 ) ;
F_133 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_123 = NULL ;
if ( ! ( V_131 & V_96 ) ) {
F_118 ( V_2 , V_130 ) ;
F_117 ( & V_2 -> V_27 ) ;
} else {
F_81 ( V_2 ) ;
}
return V_130 ;
}
int
F_125 (
struct V_1 * V_2 )
{
if ( F_134 ( V_2 -> V_10 -> V_78 ) ) {
F_135 ( V_2 , V_39 ) ;
if ( ! V_2 -> V_123 && ! F_129 ( V_2 ) )
return F_132 ( V_2 ) ;
else
return F_127 ( V_2 ) ;
}
F_69 ( V_2 ) ;
return 0 ;
}
void
F_80 (
struct V_101 * V_102 ,
struct V_1 * V_2 )
{
if ( F_134 ( V_102 ) ) {
F_135 ( V_2 , V_39 ) ;
F_132 ( V_2 ) ;
return;
}
F_69 ( V_2 ) ;
}
STATIC void
F_136 (
V_26 * V_2 ,
int V_124 )
{
if ( F_93 ( & V_2 -> V_132 ) == 1 )
F_113 ( V_2 , V_124 ) ;
}
STATIC void
F_137 (
struct V_133 * V_133 ,
int error )
{
V_26 * V_2 = ( V_26 * ) V_133 -> V_134 ;
F_118 ( V_2 , - error ) ;
if ( ! error && F_1 ( V_2 ) && ( V_2 -> V_3 & V_97 ) )
F_138 ( V_2 -> V_48 , F_2 ( V_2 ) ) ;
F_136 ( V_2 , 1 ) ;
F_139 ( V_133 ) ;
}
STATIC void
F_140 (
V_26 * V_2 )
{
int V_135 , V_136 , V_137 , V_138 ;
struct V_133 * V_133 ;
int V_52 = V_2 -> V_7 ;
int V_50 = V_2 -> V_33 ;
T_9 V_139 = V_2 -> V_34 ;
V_137 = V_2 -> V_5 ;
V_136 = 0 ;
if ( V_2 -> V_3 & V_95 ) {
if ( V_2 -> V_3 & V_140 )
V_135 = V_141 ;
else
V_135 = V_142 ;
if ( V_2 -> V_3 & V_143 )
V_135 |= V_144 ;
if ( V_2 -> V_3 & V_145 )
V_135 |= V_146 ;
} else if ( V_2 -> V_3 & V_25 ) {
V_135 = V_147 ;
} else {
V_135 = V_148 ;
}
V_135 |= V_149 ;
V_150:
F_6 ( & V_2 -> V_132 ) ;
V_138 = V_151 >> ( V_111 - V_75 ) ;
if ( V_138 > V_137 )
V_138 = V_137 ;
V_133 = F_141 ( V_152 , V_138 ) ;
V_133 -> V_153 = V_2 -> V_10 -> V_154 ;
V_133 -> V_155 = V_139 ;
V_133 -> V_156 = F_137 ;
V_133 -> V_134 = V_2 ;
for (; V_50 && V_138 ; V_138 -- , V_136 ++ ) {
int V_157 , V_51 = V_6 - V_52 ;
if ( V_51 > V_50 )
V_51 = V_50 ;
V_157 = F_142 ( V_133 , V_2 -> V_41 [ V_136 ] , V_51 , V_52 ) ;
if ( V_157 < V_51 )
break;
V_52 = 0 ;
V_139 += V_51 >> V_75 ;
V_50 -= V_51 ;
V_137 -- ;
}
if ( F_64 ( V_133 -> V_158 ) ) {
if ( F_1 ( V_2 ) ) {
F_143 ( V_2 -> V_48 ,
F_2 ( V_2 ) ) ;
}
F_144 ( V_135 , V_133 ) ;
if ( V_50 )
goto V_150;
} else {
F_118 ( V_2 , V_130 ) ;
F_139 ( V_133 ) ;
}
}
int
F_69 (
V_26 * V_2 )
{
F_145 ( V_2 , V_39 ) ;
ASSERT ( ! ( V_2 -> V_3 & V_94 ) ) ;
if ( V_2 -> V_3 & V_95 )
F_105 ( V_2 ) ;
F_89 ( V_2 ) ;
F_13 ( & V_2 -> V_132 , 1 ) ;
F_140 ( V_2 ) ;
F_136 ( V_2 , 0 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
int
F_70 (
V_26 * V_2 )
{
F_146 ( V_2 , V_39 ) ;
F_147 ( & V_2 -> V_27 ) ;
F_148 ( V_2 , V_39 ) ;
return V_2 -> V_98 ;
}
T_10
F_149 (
V_26 * V_2 ,
T_2 V_52 )
{
struct V_44 * V_44 ;
if ( V_2 -> V_3 & V_4 )
return V_2 -> V_48 + V_52 ;
V_52 += V_2 -> V_7 ;
V_44 = V_2 -> V_41 [ V_52 >> V_111 ] ;
return ( T_10 ) F_49 ( V_44 ) + ( V_52 & ( V_6 - 1 ) ) ;
}
void
F_150 (
V_26 * V_2 ,
T_2 V_159 ,
T_2 V_160 ,
void * V_161 ,
T_11 V_162 )
{
T_2 V_163 , V_164 , V_165 ;
struct V_44 * V_44 ;
V_163 = V_159 + V_160 ;
while ( V_159 < V_163 ) {
V_44 = V_2 -> V_41 [ F_43 ( V_159 + V_2 -> V_7 ) ] ;
V_164 = F_29 ( V_159 + V_2 -> V_7 ) ;
V_165 = F_47 ( T_2 ,
V_6 - V_164 , V_2 -> V_33 - V_159 ) ;
ASSERT ( ( ( V_165 + V_164 ) <= V_6 ) ) ;
switch ( V_162 ) {
case V_166 :
memset ( F_49 ( V_44 ) + V_164 , 0 , V_165 ) ;
break;
case V_167 :
memcpy ( V_161 , F_49 ( V_44 ) + V_164 , V_165 ) ;
break;
case V_168 :
memcpy ( F_49 ( V_44 ) + V_164 , V_161 , V_165 ) ;
}
V_159 += V_165 ;
V_161 += V_165 ;
}
}
void
F_151 (
struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_169:
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
V_2 = F_152 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( F_15 ( & V_2 -> V_13 ) > 1 ) {
F_8 ( & V_9 -> V_11 ) ;
F_153 ( 100 ) ;
goto V_169;
}
F_13 ( & V_2 -> V_17 , 0 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_60 ( V_2 ) ;
F_4 ( & V_9 -> V_11 ) ;
}
F_8 ( & V_9 -> V_11 ) ;
}
int
F_154 (
struct V_170 * V_171 ,
struct V_172 * V_173 )
{
struct V_8 * V_9 = F_112 ( V_171 ,
struct V_8 , V_174 ) ;
struct V_1 * V_2 ;
int V_175 = V_173 -> V_175 ;
F_155 ( V_176 ) ;
if ( ! V_175 )
return V_9 -> V_15 ;
F_4 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_9 -> V_14 ) ) {
if ( V_175 -- <= 0 )
break;
V_2 = F_152 ( & V_9 -> V_14 , struct V_1 , V_12 ) ;
if ( ! F_156 ( & V_2 -> V_17 , - 1 , 0 ) ) {
F_157 ( & V_2 -> V_12 , & V_9 -> V_14 ) ;
continue;
}
F_158 ( & V_2 -> V_12 , & V_176 ) ;
V_9 -> V_15 -- ;
}
F_8 ( & V_9 -> V_11 ) ;
while ( ! F_5 ( & V_176 ) ) {
V_2 = F_152 ( & V_176 , struct V_1 , V_12 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_60 ( V_2 ) ;
}
return V_9 -> V_15 ;
}
void
F_159 (
struct V_101 * V_102 ,
struct V_8 * V_9 )
{
F_160 ( & V_9 -> V_174 ) ;
F_161 ( V_9 , 1 ) ;
if ( V_102 -> V_177 & V_178 )
F_162 ( V_9 ) ;
F_163 ( V_9 -> V_179 ) ;
F_32 ( V_9 ) ;
}
STATIC int
F_164 (
T_6 * V_9 ,
unsigned int V_180 ,
unsigned int V_181 ,
int V_182 )
{
V_9 -> V_183 = V_180 ;
V_9 -> V_76 = F_165 ( V_181 ) - 1 ;
V_9 -> V_77 = V_181 - 1 ;
if ( F_166 ( V_9 -> V_154 , V_181 ) ) {
char V_184 [ V_185 ] ;
F_167 ( V_9 -> V_154 , V_184 ) ;
F_65 ( V_9 -> V_78 ,
L_4 ,
V_181 , V_184 ) ;
return V_186 ;
}
return 0 ;
}
STATIC int
F_168 (
T_6 * V_9 ,
struct V_187 * V_188 )
{
return F_164 ( V_9 ,
V_6 , F_169 ( V_188 ) , 0 ) ;
}
int
F_170 (
T_6 * V_9 ,
unsigned int V_180 ,
unsigned int V_181 )
{
return F_164 ( V_9 , V_180 , V_181 , 1 ) ;
}
STATIC int
F_171 (
T_6 * V_9 ,
const char * V_189 )
{
F_21 ( & V_9 -> V_190 ) ;
F_172 ( & V_9 -> V_191 ) ;
V_9 -> V_192 = 0 ;
V_9 -> V_179 = F_173 ( V_193 , V_9 , L_5 , V_189 ) ;
if ( F_174 ( V_9 -> V_179 ) )
return F_175 ( V_9 -> V_179 ) ;
return 0 ;
}
T_6 *
F_176 (
struct V_101 * V_102 ,
struct V_187 * V_188 ,
int V_194 ,
const char * V_189 )
{
T_6 * V_9 ;
V_9 = F_177 ( sizeof( * V_9 ) , V_195 ) ;
V_9 -> V_78 = V_102 ;
V_9 -> V_196 = V_188 -> V_197 ;
V_9 -> V_154 = V_188 ;
V_9 -> V_100 = F_178 ( V_188 ) ;
if ( ! V_9 -> V_100 )
goto error;
F_21 ( & V_9 -> V_14 ) ;
F_172 ( & V_9 -> V_11 ) ;
if ( F_168 ( V_9 , V_188 ) )
goto error;
if ( F_171 ( V_9 , V_189 ) )
goto error;
V_9 -> V_174 . V_171 = F_154 ;
V_9 -> V_174 . V_198 = V_199 ;
F_179 ( & V_9 -> V_174 ) ;
return V_9 ;
error:
F_32 ( V_9 ) ;
return NULL ;
}
void
F_180 (
V_26 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_181 ( V_2 , V_39 ) ;
ASSERT ( ! ( V_2 -> V_3 & V_97 ) ) ;
F_4 ( & V_9 -> V_191 ) ;
if ( ! F_5 ( & V_2 -> V_28 ) ) {
ASSERT ( V_2 -> V_3 & V_89 ) ;
F_157 ( & V_2 -> V_28 , & V_9 -> V_190 ) ;
} else {
if ( F_5 ( & V_9 -> V_190 ) )
F_182 ( V_2 -> V_10 -> V_179 ) ;
F_6 ( & V_2 -> V_13 ) ;
V_2 -> V_3 |= V_94 | V_89 | V_96 ;
F_7 ( & V_2 -> V_28 , & V_9 -> V_190 ) ;
}
V_2 -> V_200 = V_201 ;
F_8 ( & V_9 -> V_191 ) ;
}
void
F_12 (
V_26 * V_2 )
{
int V_202 = 0 ;
F_4 ( & V_2 -> V_10 -> V_191 ) ;
if ( ( V_2 -> V_3 & V_94 ) && ! F_5 ( & V_2 -> V_28 ) ) {
ASSERT ( V_2 -> V_3 & V_89 ) ;
F_10 ( & V_2 -> V_28 ) ;
V_202 = 1 ;
}
V_2 -> V_3 &= ~ ( V_94 | V_89 ) ;
F_8 ( & V_2 -> V_10 -> V_191 ) ;
if ( V_202 )
F_60 ( V_2 ) ;
F_183 ( V_2 , V_39 ) ;
}
void
F_184 (
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
long V_203 = V_204 * F_185 ( 10 ) + 1 ;
ASSERT ( V_2 -> V_3 & V_94 ) ;
ASSERT ( V_2 -> V_3 & V_89 ) ;
if ( V_2 -> V_200 < V_201 - V_203 )
return;
V_2 -> V_200 = V_201 - V_203 ;
F_4 ( & V_9 -> V_191 ) ;
F_158 ( & V_2 -> V_28 , & V_9 -> V_190 ) ;
F_8 ( & V_9 -> V_191 ) ;
}
STATIC int
F_186 (
T_6 * V_18 ,
struct V_205 * V_206 ,
unsigned long V_203 )
{
V_26 * V_2 , * V_207 ;
int V_208 = 0 ;
int V_209 ;
V_209 = F_187 ( V_210 , & V_18 -> V_192 ) ;
F_21 ( V_206 ) ;
F_4 ( & V_18 -> V_191 ) ;
F_188 (bp, n, &target->bt_delwri_queue, b_list) {
ASSERT ( V_2 -> V_3 & V_94 ) ;
if ( ! F_189 ( V_2 ) && F_59 ( V_2 ) ) {
if ( ! V_209 &&
F_190 ( V_201 , V_2 -> V_200 + V_203 ) ) {
F_67 ( V_2 ) ;
break;
}
V_2 -> V_3 &= ~ ( V_94 | V_89 ) ;
V_2 -> V_3 |= V_95 ;
F_157 ( & V_2 -> V_28 , V_206 ) ;
F_191 ( V_2 , V_39 ) ;
} else
V_208 ++ ;
}
F_8 ( & V_18 -> V_191 ) ;
return V_208 ;
}
static int
F_192 (
void * V_211 ,
struct V_205 * V_212 ,
struct V_205 * V_213 )
{
struct V_1 * V_214 = F_112 ( V_212 , struct V_1 , V_28 ) ;
struct V_1 * V_2 = F_112 ( V_213 , struct V_1 , V_28 ) ;
T_7 V_215 ;
V_215 = V_214 -> V_34 - V_2 -> V_34 ;
if ( V_215 < 0 )
return - 1 ;
if ( V_215 > 0 )
return 1 ;
return 0 ;
}
STATIC int
V_193 (
void * V_161 )
{
T_6 * V_18 = ( T_6 * ) V_161 ;
V_117 -> V_21 |= V_216 ;
F_193 () ;
do {
long V_203 = V_204 * F_185 ( 10 ) ;
long V_217 = V_218 * F_185 ( 10 ) ;
struct V_205 V_219 ;
struct V_220 V_221 ;
if ( F_19 ( F_194 ( V_117 ) ) )
F_195 () ;
if ( F_5 ( & V_18 -> V_190 ) )
V_217 = V_222 ;
F_196 ( V_217 ) ;
F_186 ( V_18 , & V_219 , V_203 ) ;
F_197 ( NULL , & V_219 , F_192 ) ;
F_198 ( & V_221 ) ;
while ( ! F_5 ( & V_219 ) ) {
struct V_1 * V_2 ;
V_2 = F_152 ( & V_219 , struct V_1 , V_28 ) ;
F_10 ( & V_2 -> V_28 ) ;
F_125 ( V_2 ) ;
}
F_199 ( & V_221 ) ;
} while ( ! F_200 () );
return 0 ;
}
int
F_161 (
T_6 * V_18 ,
int V_116 )
{
V_26 * V_2 ;
int V_223 = 0 ;
F_155 ( V_224 ) ;
F_155 ( V_225 ) ;
struct V_220 V_221 ;
F_201 ( V_126 ) ;
F_202 ( V_210 , & V_18 -> V_192 ) ;
V_223 = F_186 ( V_18 , & V_224 , 0 ) ;
F_197 ( NULL , & V_224 , F_192 ) ;
F_198 ( & V_221 ) ;
while ( ! F_5 ( & V_224 ) ) {
V_2 = F_152 ( & V_224 , struct V_1 , V_28 ) ;
ASSERT ( V_18 == V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_28 ) ;
if ( V_116 ) {
V_2 -> V_3 &= ~ V_96 ;
F_203 ( & V_2 -> V_28 , & V_225 ) ;
}
F_125 ( V_2 ) ;
}
F_199 ( & V_221 ) ;
if ( V_116 ) {
while ( ! F_5 ( & V_225 ) ) {
V_2 = F_152 ( & V_225 , struct V_1 , V_28 ) ;
F_10 ( & V_2 -> V_28 ) ;
F_70 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
return V_223 ;
}
int T_12
F_204 ( void )
{
V_22 = F_205 ( sizeof( V_26 ) , L_6 ,
V_226 , NULL ) ;
if ( ! V_22 )
goto V_227;
V_126 = F_206 ( L_7 ,
V_228 | V_229 , 1 ) ;
if ( ! V_126 )
goto V_230;
return 0 ;
V_230:
F_207 ( V_22 ) ;
V_227:
return - V_45 ;
}
void
F_208 ( void )
{
F_209 ( V_126 ) ;
F_207 ( V_22 ) ;
}
