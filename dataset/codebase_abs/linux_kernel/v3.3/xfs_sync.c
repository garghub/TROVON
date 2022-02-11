STATIC int
F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
ASSERT ( F_3 () ) ;
F_4 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_5 )
goto V_6;
if ( F_5 ( V_2 , V_7 | V_8 | V_9 ) )
goto V_6;
F_6 ( & V_2 -> V_4 ) ;
if ( F_7 ( V_2 -> V_10 ) )
return V_11 ;
if ( ! F_8 ( V_3 ) )
return V_12 ;
if ( F_9 ( V_3 ) ) {
F_10 ( V_2 ) ;
return V_12 ;
}
return 0 ;
V_6:
F_6 ( & V_2 -> V_4 ) ;
return V_12 ;
}
STATIC int
F_11 (
struct V_13 * V_14 ,
struct V_15 * V_16 ,
int (* F_12)( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 ) ,
int V_17 )
{
T_1 V_18 ;
int V_19 = 0 ;
int V_20 ;
int V_21 ;
int V_22 ;
V_23:
V_21 = 0 ;
V_20 = 0 ;
V_18 = 0 ;
V_22 = 0 ;
do {
struct V_1 * V_24 [ V_25 ] ;
int error = 0 ;
int V_26 ;
F_13 () ;
V_22 = F_14 ( & V_16 -> V_27 ,
( void * * ) V_24 , V_18 ,
V_25 ) ;
if ( ! V_22 ) {
F_15 () ;
break;
}
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
struct V_1 * V_2 = V_24 [ V_26 ] ;
if ( V_21 || F_1 ( V_2 ) )
V_24 [ V_26 ] = NULL ;
if ( F_16 ( V_14 , V_2 -> V_5 ) != V_16 -> V_28 )
continue;
V_18 = F_17 ( V_14 , V_2 -> V_5 + 1 ) ;
if ( V_18 < F_17 ( V_14 , V_2 -> V_5 ) )
V_21 = 1 ;
}
F_15 () ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( ! V_24 [ V_26 ] )
continue;
error = F_12 ( V_24 [ V_26 ] , V_16 , V_17 ) ;
F_10 ( V_24 [ V_26 ] ) ;
if ( error == V_29 ) {
V_20 ++ ;
continue;
}
if ( error && V_19 != V_11 )
V_19 = error ;
}
if ( error == V_11 )
break;
F_18 () ;
} while ( V_22 && ! V_21 );
if ( V_20 ) {
F_19 ( 1 ) ;
goto V_23;
}
return V_19 ;
}
int
F_20 (
struct V_13 * V_14 ,
int (* F_12)( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 ) ,
int V_17 )
{
struct V_15 * V_16 ;
int error = 0 ;
int V_19 = 0 ;
T_2 V_30 ;
V_30 = 0 ;
while ( ( V_16 = F_21 ( V_14 , V_30 ) ) ) {
V_30 = V_16 -> V_28 + 1 ;
error = F_11 ( V_14 , V_16 , F_12 , V_17 ) ;
F_22 ( V_16 ) ;
if ( error ) {
V_19 = error ;
if ( error == V_11 )
break;
}
}
return F_23 ( V_19 ) ;
}
STATIC int
F_24 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_3 -> V_33 ;
int error = 0 ;
if ( ! F_25 ( V_32 , V_34 ) )
return 0 ;
if ( ! F_26 ( V_2 , V_35 ) ) {
if ( V_17 & V_36 )
return 0 ;
F_27 ( V_2 , V_35 ) ;
}
error = F_28 ( V_2 , 0 , - 1 , ( V_17 & V_37 ) ?
0 : V_38 , V_39 ) ;
F_29 ( V_2 , V_35 ) ;
return error ;
}
STATIC int
F_30 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 )
{
int error = 0 ;
F_27 ( V_2 , V_40 ) ;
if ( F_31 ( V_2 ) )
goto V_41;
if ( ! F_32 ( V_2 ) ) {
if ( ! ( V_17 & V_37 ) )
goto V_41;
F_33 ( V_2 ) ;
}
if ( F_31 ( V_2 ) ) {
F_34 ( V_2 ) ;
goto V_41;
}
error = F_35 ( V_2 , V_17 ) ;
if ( error == V_29 ) {
ASSERT ( ! ( V_17 & V_37 ) ) ;
error = 0 ;
}
V_41:
F_29 ( V_2 , V_40 ) ;
return error ;
}
STATIC int
F_36 (
struct V_13 * V_14 ,
int V_17 )
{
int error ;
ASSERT ( ( V_17 & ~ ( V_36 | V_37 ) ) == 0 ) ;
error = F_20 ( V_14 , F_24 , V_17 ) ;
if ( error )
return F_23 ( error ) ;
F_37 ( V_14 , ( V_17 & V_37 ) ? V_42 : 0 ) ;
return 0 ;
}
STATIC int
F_38 (
struct V_13 * V_14 ,
int V_17 )
{
ASSERT ( ( V_17 & ~ V_37 ) == 0 ) ;
return F_20 ( V_14 , F_30 , V_17 ) ;
}
STATIC int
F_39 (
struct V_13 * V_14 )
{
struct V_43 * V_44 ;
int error ;
V_44 = F_40 ( V_14 , 0 ) ;
if ( F_41 ( V_44 ) )
F_37 ( V_14 , 0 ) ;
error = F_42 ( V_44 ) ;
F_43 ( V_44 ) ;
return error ;
}
int
F_44 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
struct V_45 * V_46 ;
int error ;
if ( ! V_2 -> V_47 )
return 0 ;
V_46 = F_45 ( V_14 , V_48 ) ;
error = F_46 ( V_46 , 0 , F_47 ( V_14 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_48 ( V_46 , 0 ) ;
return error ;
}
F_27 ( V_2 , V_49 ) ;
F_49 ( V_46 , V_2 , V_49 ) ;
F_50 ( V_46 , V_2 , V_50 ) ;
return F_51 ( V_46 , 0 ) ;
}
int
F_52 (
struct V_13 * V_14 )
{
int error , V_51 = 0 ;
F_20 ( V_14 , F_44 , 0 ) ;
F_37 ( V_14 , V_42 ) ;
error = F_39 ( V_14 ) ;
F_53 ( V_14 -> V_52 , 1 ) ;
if ( F_54 ( V_14 ) )
V_51 = F_55 ( V_14 ) ;
if ( V_14 -> V_53 )
F_53 ( V_14 -> V_53 , 1 ) ;
return error ? error : V_51 ;
}
STATIC void
F_56 (
struct V_13 * V_14 )
{
int V_54 = 0 , V_55 ;
F_57 ( V_14 , 0 ) ;
F_53 ( V_14 -> V_52 , 0 ) ;
do {
F_57 ( V_14 , V_37 ) ;
F_38 ( V_14 , V_37 ) ;
V_55 = F_53 ( V_14 -> V_52 , 1 ) ;
if ( ! V_55 ) {
F_19 ( 50 ) ;
V_54 ++ ;
}
} while ( V_54 < 2 );
}
void
F_58 (
struct V_13 * V_14 )
{
int error = 0 ;
while ( F_59 ( & V_14 -> V_56 ) > 0 )
F_19 ( 100 ) ;
F_56 ( V_14 ) ;
F_60 ( F_59 ( & V_14 -> V_56 ) != 0 ) ;
error = F_61 ( V_14 ) ;
if ( error )
F_62 ( V_14 , L_1
L_2 ) ;
F_63 ( V_14 ) ;
F_64 ( V_14 ) ;
}
static void
F_65 (
struct V_13 * V_14 )
{
F_66 ( V_57 , & V_14 -> V_58 ,
F_67 ( V_59 * 10 ) ) ;
}
STATIC void
F_68 (
struct V_60 * V_61 )
{
struct V_13 * V_14 = F_69 ( F_70 ( V_61 ) ,
struct V_13 , V_58 ) ;
int error ;
if ( ! ( V_14 -> V_62 & V_63 ) ) {
if ( V_14 -> V_64 -> V_65 == V_66 &&
F_54 ( V_14 ) )
error = F_55 ( V_14 ) ;
else
F_37 ( V_14 , 0 ) ;
F_71 ( V_14 -> V_67 ) ;
}
F_65 ( V_14 ) ;
}
static void
F_72 (
struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_64 -> V_68 & V_69 ) )
return;
F_13 () ;
if ( F_73 ( & V_14 -> V_70 , V_71 ) ) {
F_66 ( V_57 , & V_14 -> V_72 ,
F_67 ( V_59 / 6 * 10 ) ) ;
}
F_15 () ;
}
STATIC void
F_74 (
struct V_60 * V_61 )
{
struct V_13 * V_14 = F_69 ( F_70 ( V_61 ) ,
struct V_13 , V_72 ) ;
F_57 ( V_14 , V_36 ) ;
F_72 ( V_14 ) ;
}
void
F_75 (
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
F_76 ( V_57 , & V_14 -> V_73 ) ;
F_77 ( & V_14 -> V_73 ) ;
}
STATIC void
F_78 (
struct V_60 * V_61 )
{
struct V_13 * V_14 = F_69 ( V_61 ,
struct V_13 , V_73 ) ;
F_36 ( V_14 , V_36 ) ;
F_36 ( V_14 , V_36 | V_37 ) ;
}
int
F_79 (
struct V_13 * V_14 )
{
F_80 ( & V_14 -> V_73 , F_78 ) ;
F_81 ( & V_14 -> V_58 , F_68 ) ;
F_81 ( & V_14 -> V_72 , F_74 ) ;
F_65 ( V_14 ) ;
F_72 ( V_14 ) ;
return 0 ;
}
void
F_82 (
struct V_13 * V_14 )
{
F_83 ( & V_14 -> V_58 ) ;
F_83 ( & V_14 -> V_72 ) ;
F_84 ( & V_14 -> V_73 ) ;
}
void
F_85 (
struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_86 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_71 ) ;
if ( ! V_16 -> V_74 ) {
F_4 ( & V_2 -> V_10 -> V_75 ) ;
F_86 ( & V_2 -> V_10 -> V_70 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_71 ) ;
F_6 ( & V_2 -> V_10 -> V_75 ) ;
F_72 ( V_2 -> V_10 ) ;
F_87 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_76 ) ;
}
V_16 -> V_74 ++ ;
}
void
F_88 (
T_3 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
struct V_15 * V_16 ;
V_16 = F_21 ( V_14 , F_16 ( V_14 , V_2 -> V_5 ) ) ;
F_4 ( & V_16 -> V_77 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_85 ( V_16 , V_2 ) ;
F_89 ( V_2 , V_8 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_6 ( & V_16 -> V_77 ) ;
F_22 ( V_16 ) ;
}
STATIC void
F_90 (
T_4 * V_16 ,
T_3 * V_2 )
{
V_16 -> V_74 -- ;
if ( ! V_16 -> V_74 ) {
F_4 ( & V_2 -> V_10 -> V_75 ) ;
F_91 ( & V_2 -> V_10 -> V_70 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_71 ) ;
F_6 ( & V_2 -> V_10 -> V_75 ) ;
F_92 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_76 ) ;
}
}
void
F_93 (
T_5 * V_14 ,
T_4 * V_16 ,
T_3 * V_2 )
{
F_91 ( & V_16 -> V_27 ,
F_17 ( V_14 , V_2 -> V_5 ) , V_71 ) ;
F_90 ( V_16 , V_2 ) ;
}
STATIC int
F_94 (
struct V_1 * V_2 ,
int V_17 )
{
ASSERT ( F_3 () ) ;
if ( ! V_2 -> V_5 )
return 1 ;
if ( ( V_17 & V_36 ) &&
F_5 ( V_2 , V_78 | V_9 ) )
return 1 ;
F_4 ( & V_2 -> V_4 ) ;
if ( ! F_5 ( V_2 , V_8 ) ||
F_5 ( V_2 , V_9 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return 1 ;
}
F_89 ( V_2 , V_9 ) ;
F_6 ( & V_2 -> V_4 ) ;
return 0 ;
}
STATIC int
F_95 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_79 )
{
int error ;
V_23:
error = 0 ;
F_27 ( V_2 , V_49 ) ;
if ( ! F_32 ( V_2 ) ) {
if ( ! ( V_79 & V_37 ) )
goto V_80;
F_96 ( V_2 ) ;
F_33 ( V_2 ) ;
}
if ( F_9 ( F_2 ( V_2 ) ) )
goto V_81;
if ( F_7 ( V_2 -> V_10 ) ) {
F_97 ( V_2 ) ;
goto V_81;
}
if ( F_98 ( V_2 ) ) {
if ( ! ( V_79 & V_37 ) ) {
F_34 ( V_2 ) ;
goto V_80;
}
F_97 ( V_2 ) ;
}
if ( F_99 ( V_2 , V_82 ) )
goto V_81;
if ( F_31 ( V_2 ) )
goto V_81;
error = F_35 ( V_2 , V_36 | V_79 ) ;
if ( V_79 & V_37 ) {
if ( error == V_29 ) {
F_29 ( V_2 , V_49 ) ;
F_19 ( 2 ) ;
goto V_23;
}
F_33 ( V_2 ) ;
goto V_81;
}
if ( error && error != V_29 && ! F_7 ( V_2 -> V_10 ) ) {
F_62 ( V_2 -> V_10 ,
L_3 ,
( long long ) V_2 -> V_5 , error ) ;
}
V_80:
F_100 ( V_2 , V_9 ) ;
F_29 ( V_2 , V_49 ) ;
return 0 ;
V_81:
F_34 ( V_2 ) ;
F_29 ( V_2 , V_49 ) ;
F_101 ( V_83 ) ;
F_4 ( & V_16 -> V_77 ) ;
if ( ! F_102 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ) )
ASSERT ( 0 ) ;
F_90 ( V_16 , V_2 ) ;
F_6 ( & V_16 -> V_77 ) ;
F_27 ( V_2 , V_49 | V_84 ) ;
F_103 ( V_2 ) ;
F_29 ( V_2 , V_49 | V_84 ) ;
F_104 ( V_2 ) ;
return error ;
}
int
F_105 (
struct V_13 * V_14 ,
int V_17 ,
int * V_85 )
{
struct V_15 * V_16 ;
int error = 0 ;
int V_19 = 0 ;
T_2 V_30 ;
int V_86 = V_17 & V_36 ;
int V_20 ;
V_23:
V_30 = 0 ;
V_20 = 0 ;
while ( ( V_16 = F_106 ( V_14 , V_30 , V_71 ) ) ) {
unsigned long V_18 = 0 ;
int V_21 = 0 ;
int V_22 = 0 ;
V_30 = V_16 -> V_28 + 1 ;
if ( V_86 ) {
if ( ! F_107 ( & V_16 -> V_87 ) ) {
V_20 ++ ;
F_22 ( V_16 ) ;
continue;
}
V_18 = V_16 -> V_88 ;
} else
F_108 ( & V_16 -> V_87 ) ;
do {
struct V_1 * V_24 [ V_25 ] ;
int V_26 ;
F_13 () ;
V_22 = F_109 (
& V_16 -> V_27 ,
( void * * ) V_24 , V_18 ,
V_25 ,
V_71 ) ;
if ( ! V_22 ) {
V_21 = 1 ;
F_15 () ;
break;
}
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
struct V_1 * V_2 = V_24 [ V_26 ] ;
if ( V_21 || F_94 ( V_2 , V_17 ) )
V_24 [ V_26 ] = NULL ;
if ( F_16 ( V_14 , V_2 -> V_5 ) !=
V_16 -> V_28 )
continue;
V_18 = F_17 ( V_14 , V_2 -> V_5 + 1 ) ;
if ( V_18 < F_17 ( V_14 , V_2 -> V_5 ) )
V_21 = 1 ;
}
F_15 () ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( ! V_24 [ V_26 ] )
continue;
error = F_95 ( V_24 [ V_26 ] , V_16 , V_17 ) ;
if ( error && V_19 != V_11 )
V_19 = error ;
}
* V_85 -= V_25 ;
F_18 () ;
} while ( V_22 && ! V_21 && * V_85 > 0 );
if ( V_86 && ! V_21 )
V_16 -> V_88 = V_18 ;
else
V_16 -> V_88 = 0 ;
F_110 ( & V_16 -> V_87 ) ;
F_22 ( V_16 ) ;
}
if ( V_20 && ( V_17 & V_37 ) && * V_85 > 0 ) {
V_86 = 0 ;
goto V_23;
}
return F_23 ( V_19 ) ;
}
int
F_57 (
T_5 * V_14 ,
int V_89 )
{
int V_85 = V_90 ;
return F_105 ( V_14 , V_89 , & V_85 ) ;
}
void
F_111 (
struct V_13 * V_14 ,
int V_85 )
{
F_72 ( V_14 ) ;
F_71 ( V_14 -> V_67 ) ;
F_105 ( V_14 , V_36 | V_37 , & V_85 ) ;
}
int
F_112 (
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
T_2 V_30 = 0 ;
int V_91 = 0 ;
while ( ( V_16 = F_106 ( V_14 , V_30 , V_71 ) ) ) {
V_30 = V_16 -> V_28 + 1 ;
V_91 += V_16 -> V_74 ;
F_22 ( V_16 ) ;
}
return V_91 ;
}
