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
goto V_35;
if ( ! F_26 ( V_2 , V_36 ) ) {
if ( V_17 & V_37 )
goto V_35;
F_27 ( V_2 , V_36 ) ;
}
error = F_28 ( V_2 , 0 , - 1 , ( V_17 & V_38 ) ?
0 : V_39 , V_40 ) ;
F_29 ( V_2 , V_36 ) ;
V_35:
if ( V_17 & V_38 )
F_30 ( V_2 ) ;
return error ;
}
STATIC int
F_31 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 )
{
int error = 0 ;
F_27 ( V_2 , V_41 ) ;
if ( F_32 ( V_2 ) )
goto V_42;
if ( ! F_33 ( V_2 ) ) {
if ( ! ( V_17 & V_38 ) )
goto V_42;
F_34 ( V_2 ) ;
}
if ( F_32 ( V_2 ) ) {
F_35 ( V_2 ) ;
goto V_42;
}
error = F_36 ( V_2 , V_17 ) ;
if ( error == V_29 ) {
ASSERT ( ! ( V_17 & V_38 ) ) ;
error = 0 ;
}
V_42:
F_29 ( V_2 , V_41 ) ;
return error ;
}
STATIC int
F_37 (
struct V_13 * V_14 ,
int V_17 )
{
int error ;
ASSERT ( ( V_17 & ~ ( V_37 | V_38 ) ) == 0 ) ;
error = F_20 ( V_14 , F_24 , V_17 ) ;
if ( error )
return F_23 ( error ) ;
F_38 ( V_14 , ( V_17 & V_38 ) ? V_43 : 0 ) ;
return 0 ;
}
STATIC int
F_39 (
struct V_13 * V_14 ,
int V_17 )
{
ASSERT ( ( V_17 & ~ V_38 ) == 0 ) ;
return F_20 ( V_14 , F_31 , V_17 ) ;
}
STATIC int
F_40 (
struct V_13 * V_14 )
{
struct V_44 * V_45 ;
V_45 = F_41 ( V_14 , 0 ) ;
if ( F_42 ( V_45 ) )
F_38 ( V_14 , 0 ) ;
return F_43 ( V_14 , V_45 ) ;
}
int
F_44 (
struct V_13 * V_14 )
{
int error , V_46 = 0 ;
F_45 ( V_14 , V_37 ) ;
F_45 ( V_14 , V_38 ) ;
F_38 ( V_14 , V_43 ) ;
error = F_40 ( V_14 ) ;
F_46 ( V_14 -> V_47 , 1 ) ;
if ( F_47 ( V_14 ) )
V_46 = F_48 ( V_14 ) ;
if ( V_14 -> V_48 )
F_49 ( V_14 -> V_48 ) ;
return error ? error : V_46 ;
}
STATIC void
F_50 (
struct V_13 * V_14 )
{
int V_49 = 0 , V_50 ;
F_51 ( V_14 , 0 ) ;
F_46 ( V_14 -> V_47 , 0 ) ;
do {
F_51 ( V_14 , V_38 ) ;
F_39 ( V_14 , V_38 ) ;
V_50 = F_46 ( V_14 -> V_47 , 1 ) ;
if ( ! V_50 ) {
F_19 ( 50 ) ;
V_49 ++ ;
}
} while ( V_49 < 2 );
}
void
F_52 (
struct V_13 * V_14 )
{
int error = 0 ;
while ( F_53 ( & V_14 -> V_51 ) > 0 )
F_19 ( 100 ) ;
F_50 ( V_14 ) ;
F_54 ( F_53 ( & V_14 -> V_51 ) != 0 ) ;
error = F_55 ( V_14 ) ;
if ( error )
F_56 ( V_14 , L_1
L_2 ) ;
F_57 ( V_14 ) ;
F_58 ( V_14 ) ;
}
static void
F_59 (
struct V_13 * V_14 )
{
F_60 ( V_52 , & V_14 -> V_53 ,
F_61 ( V_54 * 10 ) ) ;
}
STATIC void
F_62 (
struct V_55 * V_56 )
{
struct V_13 * V_14 = F_63 ( F_64 ( V_56 ) ,
struct V_13 , V_53 ) ;
int error ;
if ( ! ( V_14 -> V_57 & V_58 ) ) {
if ( V_14 -> V_59 -> V_60 == V_61 &&
F_47 ( V_14 ) )
error = F_48 ( V_14 ) ;
else
F_38 ( V_14 , 0 ) ;
error = F_45 ( V_14 , V_37 ) ;
F_65 ( V_14 -> V_62 ) ;
}
F_59 ( V_14 ) ;
}
static void
F_66 (
struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_59 -> V_63 & V_64 ) )
return;
F_13 () ;
if ( F_67 ( & V_14 -> V_65 , V_66 ) ) {
F_60 ( V_52 , & V_14 -> V_67 ,
F_61 ( V_54 / 6 * 10 ) ) ;
}
F_15 () ;
}
STATIC void
F_68 (
struct V_55 * V_56 )
{
struct V_13 * V_14 = F_63 ( F_64 ( V_56 ) ,
struct V_13 , V_67 ) ;
F_51 ( V_14 , V_37 ) ;
F_66 ( V_14 ) ;
}
void
F_69 (
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
F_70 ( V_52 , & V_14 -> V_68 ) ;
F_71 ( & V_14 -> V_68 ) ;
}
STATIC void
F_72 (
struct V_55 * V_56 )
{
struct V_13 * V_14 = F_63 ( V_56 ,
struct V_13 , V_68 ) ;
F_37 ( V_14 , V_37 ) ;
F_37 ( V_14 , V_37 | V_38 ) ;
}
int
F_73 (
struct V_13 * V_14 )
{
F_74 ( & V_14 -> V_68 , F_72 ) ;
F_75 ( & V_14 -> V_53 , F_62 ) ;
F_75 ( & V_14 -> V_67 , F_68 ) ;
F_59 ( V_14 ) ;
F_66 ( V_14 ) ;
return 0 ;
}
void
F_76 (
struct V_13 * V_14 )
{
F_77 ( & V_14 -> V_53 ) ;
F_77 ( & V_14 -> V_67 ) ;
F_78 ( & V_14 -> V_68 ) ;
}
void
F_79 (
struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_80 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_66 ) ;
if ( ! V_16 -> V_69 ) {
F_4 ( & V_2 -> V_10 -> V_70 ) ;
F_80 ( & V_2 -> V_10 -> V_65 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_66 ) ;
F_6 ( & V_2 -> V_10 -> V_70 ) ;
F_66 ( V_2 -> V_10 ) ;
F_81 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_71 ) ;
}
V_16 -> V_69 ++ ;
}
void
F_82 (
T_3 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
struct V_15 * V_16 ;
V_16 = F_21 ( V_14 , F_16 ( V_14 , V_2 -> V_5 ) ) ;
F_4 ( & V_16 -> V_72 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_79 ( V_16 , V_2 ) ;
F_83 ( V_2 , V_8 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_6 ( & V_16 -> V_72 ) ;
F_22 ( V_16 ) ;
}
STATIC void
F_84 (
T_4 * V_16 ,
T_3 * V_2 )
{
V_16 -> V_69 -- ;
if ( ! V_16 -> V_69 ) {
F_4 ( & V_2 -> V_10 -> V_70 ) ;
F_85 ( & V_2 -> V_10 -> V_65 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_66 ) ;
F_6 ( & V_2 -> V_10 -> V_70 ) ;
F_86 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_71 ) ;
}
}
void
F_87 (
T_5 * V_14 ,
T_4 * V_16 ,
T_3 * V_2 )
{
F_85 ( & V_16 -> V_27 ,
F_17 ( V_14 , V_2 -> V_5 ) , V_66 ) ;
F_84 ( V_16 , V_2 ) ;
}
STATIC int
F_88 (
struct V_1 * V_2 ,
int V_17 )
{
ASSERT ( F_3 () ) ;
if ( ! V_2 -> V_5 )
return 1 ;
if ( ( V_17 & V_37 ) &&
( ! V_2 -> V_73 . V_21 || F_5 ( V_2 , V_9 ) ) ) {
return 1 ;
}
F_4 ( & V_2 -> V_4 ) ;
if ( ! F_5 ( V_2 , V_8 ) ||
F_5 ( V_2 , V_9 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return 1 ;
}
F_83 ( V_2 , V_9 ) ;
F_6 ( & V_2 -> V_4 ) ;
return 0 ;
}
STATIC int
F_89 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_74 )
{
int error ;
V_23:
error = 0 ;
F_27 ( V_2 , V_75 ) ;
if ( ! F_33 ( V_2 ) ) {
if ( ! ( V_74 & V_38 ) )
goto V_76;
F_34 ( V_2 ) ;
}
if ( F_9 ( F_2 ( V_2 ) ) )
goto V_77;
if ( F_7 ( V_2 -> V_10 ) ) {
F_90 ( V_2 ) ;
goto V_77;
}
if ( F_91 ( V_2 ) ) {
if ( ! ( V_74 & V_38 ) ) {
F_35 ( V_2 ) ;
goto V_76;
}
F_90 ( V_2 ) ;
}
if ( F_92 ( V_2 , V_78 ) )
goto V_77;
if ( F_32 ( V_2 ) )
goto V_77;
error = F_36 ( V_2 , V_37 | V_74 ) ;
if ( V_74 & V_38 ) {
if ( error == V_29 ) {
F_29 ( V_2 , V_75 ) ;
F_19 ( 2 ) ;
goto V_23;
}
F_34 ( V_2 ) ;
goto V_77;
}
if ( error && error != V_29 && ! F_7 ( V_2 -> V_10 ) ) {
F_56 ( V_2 -> V_10 ,
L_3 ,
( long long ) V_2 -> V_5 , error ) ;
}
V_76:
F_93 ( V_2 , V_9 ) ;
F_29 ( V_2 , V_75 ) ;
return 0 ;
V_77:
F_35 ( V_2 ) ;
F_29 ( V_2 , V_75 ) ;
F_94 ( V_79 ) ;
F_4 ( & V_16 -> V_72 ) ;
if ( ! F_95 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ) )
ASSERT ( 0 ) ;
F_84 ( V_16 , V_2 ) ;
F_6 ( & V_16 -> V_72 ) ;
F_27 ( V_2 , V_75 | V_80 ) ;
F_96 ( V_2 ) ;
F_29 ( V_2 , V_75 | V_80 ) ;
F_97 ( V_2 ) ;
return error ;
}
int
F_98 (
struct V_13 * V_14 ,
int V_17 ,
int * V_81 )
{
struct V_15 * V_16 ;
int error = 0 ;
int V_19 = 0 ;
T_2 V_30 ;
int V_82 = V_17 & V_37 ;
int V_20 ;
V_23:
V_30 = 0 ;
V_20 = 0 ;
while ( ( V_16 = F_99 ( V_14 , V_30 , V_66 ) ) ) {
unsigned long V_18 = 0 ;
int V_21 = 0 ;
int V_22 = 0 ;
V_30 = V_16 -> V_28 + 1 ;
if ( V_82 ) {
if ( ! F_100 ( & V_16 -> V_83 ) ) {
V_20 ++ ;
F_22 ( V_16 ) ;
continue;
}
V_18 = V_16 -> V_84 ;
} else
F_101 ( & V_16 -> V_83 ) ;
do {
struct V_1 * V_24 [ V_25 ] ;
int V_26 ;
F_13 () ;
V_22 = F_102 (
& V_16 -> V_27 ,
( void * * ) V_24 , V_18 ,
V_25 ,
V_66 ) ;
if ( ! V_22 ) {
V_21 = 1 ;
F_15 () ;
break;
}
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
struct V_1 * V_2 = V_24 [ V_26 ] ;
if ( V_21 || F_88 ( V_2 , V_17 ) )
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
error = F_89 ( V_24 [ V_26 ] , V_16 , V_17 ) ;
if ( error && V_19 != V_11 )
V_19 = error ;
}
* V_81 -= V_25 ;
F_18 () ;
} while ( V_22 && ! V_21 && * V_81 > 0 );
if ( V_82 && ! V_21 )
V_16 -> V_84 = V_18 ;
else
V_16 -> V_84 = 0 ;
F_103 ( & V_16 -> V_83 ) ;
F_22 ( V_16 ) ;
}
if ( V_20 && ( V_17 & V_38 ) && * V_81 > 0 ) {
V_82 = 0 ;
goto V_23;
}
return F_23 ( V_19 ) ;
}
int
F_51 (
T_5 * V_14 ,
int V_85 )
{
int V_81 = V_86 ;
return F_98 ( V_14 , V_85 , & V_81 ) ;
}
void
F_104 (
struct V_13 * V_14 ,
int V_81 )
{
F_66 ( V_14 ) ;
F_65 ( V_14 -> V_62 ) ;
F_98 ( V_14 , V_37 | V_38 , & V_81 ) ;
}
int
F_105 (
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
T_2 V_30 = 0 ;
int V_87 = 0 ;
while ( ( V_16 = F_99 ( V_14 , V_30 , V_66 ) ) ) {
V_30 = V_16 -> V_28 + 1 ;
V_87 += V_16 -> V_69 ;
F_22 ( V_16 ) ;
}
return V_87 ;
}
