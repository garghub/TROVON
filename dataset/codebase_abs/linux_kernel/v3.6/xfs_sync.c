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
struct V_13 * V_14 ,
int V_17 )
{
int error ;
ASSERT ( ( V_17 & ~ ( V_36 | V_37 ) ) == 0 ) ;
error = F_20 ( V_14 , F_24 , V_17 ) ;
if ( error )
return F_23 ( error ) ;
F_31 ( V_14 , ( V_17 & V_37 ) ? V_40 : 0 ) ;
return 0 ;
}
STATIC int
F_32 (
struct V_13 * V_14 )
{
struct V_41 * V_42 ;
int error ;
V_42 = F_33 ( V_14 , 0 ) ;
if ( F_34 ( V_42 ) )
F_31 ( V_14 , 0 ) ;
error = F_35 ( V_42 ) ;
F_36 ( V_42 ) ;
return error ;
}
int
F_37 (
struct V_13 * V_14 )
{
int error , V_43 = 0 ;
F_31 ( V_14 , V_40 ) ;
error = F_32 ( V_14 ) ;
if ( F_38 ( V_14 ) )
V_43 = F_39 ( V_14 ) ;
return error ? error : V_43 ;
}
void
F_40 (
struct V_13 * V_14 )
{
int error = 0 ;
while ( F_41 ( & V_14 -> V_44 ) > 0 )
F_19 ( 100 ) ;
F_42 ( V_14 , 0 ) ;
F_42 ( V_14 , V_37 ) ;
F_43 ( V_14 -> V_45 ) ;
F_44 ( F_41 ( & V_14 -> V_44 ) != 0 ) ;
error = F_45 ( V_14 ) ;
if ( error )
F_46 ( V_14 , L_1
L_2 ) ;
F_47 ( V_14 ) ;
F_43 ( V_14 -> V_45 ) ;
F_48 ( V_14 -> V_46 ) ;
F_49 ( V_14 -> V_46 ) ;
}
static void
F_50 (
struct V_13 * V_14 )
{
F_51 ( V_47 , & V_14 -> V_48 ,
F_52 ( V_49 * 10 ) ) ;
}
STATIC void
F_53 (
struct V_50 * V_51 )
{
struct V_13 * V_14 = F_54 ( F_55 ( V_51 ) ,
struct V_13 , V_48 ) ;
int error ;
if ( ! ( V_14 -> V_52 -> V_53 & V_54 ) &&
! ( V_14 -> V_55 & V_56 ) ) {
if ( V_14 -> V_52 -> V_57 . V_58 == V_59 &&
F_38 ( V_14 ) )
error = F_39 ( V_14 ) ;
else
F_31 ( V_14 , 0 ) ;
F_56 ( V_14 -> V_45 ) ;
}
F_50 ( V_14 ) ;
}
static void
F_57 (
struct V_13 * V_14 )
{
F_13 () ;
if ( F_58 ( & V_14 -> V_60 , V_61 ) ) {
F_51 ( V_47 , & V_14 -> V_62 ,
F_52 ( V_49 / 6 * 10 ) ) ;
}
F_15 () ;
}
STATIC void
F_59 (
struct V_50 * V_51 )
{
struct V_13 * V_14 = F_54 ( F_55 ( V_51 ) ,
struct V_13 , V_62 ) ;
F_42 ( V_14 , V_36 ) ;
F_57 ( V_14 ) ;
}
void
F_60 (
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
F_61 ( V_47 , & V_14 -> V_63 ) ;
F_62 ( & V_14 -> V_63 ) ;
}
STATIC void
F_63 (
struct V_50 * V_51 )
{
struct V_13 * V_14 = F_54 ( V_51 ,
struct V_13 , V_63 ) ;
F_30 ( V_14 , V_36 ) ;
F_30 ( V_14 , V_36 | V_37 ) ;
}
int
F_64 (
struct V_13 * V_14 )
{
F_65 ( & V_14 -> V_63 , F_63 ) ;
F_66 ( & V_14 -> V_48 , F_53 ) ;
F_66 ( & V_14 -> V_62 , F_59 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
void
F_67 (
struct V_13 * V_14 )
{
F_68 ( & V_14 -> V_48 ) ;
F_68 ( & V_14 -> V_62 ) ;
F_69 ( & V_14 -> V_63 ) ;
}
void
F_70 (
struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_71 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_61 ) ;
if ( ! V_16 -> V_64 ) {
F_4 ( & V_2 -> V_10 -> V_65 ) ;
F_71 ( & V_2 -> V_10 -> V_60 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_61 ) ;
F_6 ( & V_2 -> V_10 -> V_65 ) ;
F_57 ( V_2 -> V_10 ) ;
F_72 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_66 ) ;
}
V_16 -> V_64 ++ ;
}
void
F_73 (
T_3 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
struct V_15 * V_16 ;
V_16 = F_21 ( V_14 , F_16 ( V_14 , V_2 -> V_5 ) ) ;
F_4 ( & V_16 -> V_67 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_70 ( V_16 , V_2 ) ;
F_74 ( V_2 , V_8 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_6 ( & V_16 -> V_67 ) ;
F_22 ( V_16 ) ;
}
STATIC void
F_75 (
T_4 * V_16 ,
T_3 * V_2 )
{
V_16 -> V_64 -- ;
if ( ! V_16 -> V_64 ) {
F_4 ( & V_2 -> V_10 -> V_65 ) ;
F_76 ( & V_2 -> V_10 -> V_60 ,
F_16 ( V_2 -> V_10 , V_2 -> V_5 ) ,
V_61 ) ;
F_6 ( & V_2 -> V_10 -> V_65 ) ;
F_77 ( V_2 -> V_10 , V_16 -> V_28 ,
- 1 , V_66 ) ;
}
}
void
F_78 (
T_5 * V_14 ,
T_4 * V_16 ,
T_3 * V_2 )
{
F_76 ( & V_16 -> V_27 ,
F_17 ( V_14 , V_2 -> V_5 ) , V_61 ) ;
F_75 ( V_16 , V_2 ) ;
}
STATIC int
F_79 (
struct V_1 * V_2 ,
int V_17 )
{
ASSERT ( F_3 () ) ;
if ( ! V_2 -> V_5 )
return 1 ;
if ( ( V_17 & V_36 ) &&
F_5 ( V_2 , V_68 | V_9 ) )
return 1 ;
F_4 ( & V_2 -> V_4 ) ;
if ( ! F_5 ( V_2 , V_8 ) ||
F_5 ( V_2 , V_9 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return 1 ;
}
F_74 ( V_2 , V_9 ) ;
F_6 ( & V_2 -> V_4 ) ;
return 0 ;
}
STATIC int
F_80 (
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_69 )
{
struct V_41 * V_42 = NULL ;
int error ;
V_23:
error = 0 ;
F_27 ( V_2 , V_70 ) ;
if ( ! F_81 ( V_2 ) ) {
if ( ! ( V_69 & V_37 ) )
goto V_71;
F_82 ( V_2 ) ;
}
if ( F_9 ( F_2 ( V_2 ) ) )
goto V_72;
if ( F_7 ( V_2 -> V_10 ) ) {
F_83 ( V_2 ) ;
F_84 ( V_2 , false ) ;
goto V_72;
}
if ( F_85 ( V_2 ) ) {
if ( ! ( V_69 & V_37 ) )
goto V_73;
F_83 ( V_2 ) ;
}
if ( F_86 ( V_2 , V_74 ) )
goto V_72;
if ( F_87 ( V_2 ) )
goto V_72;
if ( ! ( V_69 & V_37 ) )
goto V_73;
error = F_88 ( V_2 , & V_42 ) ;
if ( error == V_29 ) {
F_29 ( V_2 , V_70 ) ;
F_19 ( 2 ) ;
goto V_23;
}
if ( ! error ) {
error = F_35 ( V_42 ) ;
F_36 ( V_42 ) ;
}
F_82 ( V_2 ) ;
V_72:
F_89 ( V_2 ) ;
F_29 ( V_2 , V_70 ) ;
F_90 ( V_75 ) ;
F_4 ( & V_16 -> V_67 ) ;
if ( ! F_91 ( & V_16 -> V_27 ,
F_17 ( V_2 -> V_10 , V_2 -> V_5 ) ) )
ASSERT ( 0 ) ;
F_75 ( V_16 , V_2 ) ;
F_6 ( & V_16 -> V_67 ) ;
F_27 ( V_2 , V_70 ) ;
F_92 ( V_2 ) ;
F_29 ( V_2 , V_70 ) ;
F_93 ( V_2 ) ;
return error ;
V_73:
F_89 ( V_2 ) ;
V_71:
F_94 ( V_2 , V_9 ) ;
F_29 ( V_2 , V_70 ) ;
return 0 ;
}
int
F_95 (
struct V_13 * V_14 ,
int V_17 ,
int * V_76 )
{
struct V_15 * V_16 ;
int error = 0 ;
int V_19 = 0 ;
T_2 V_30 ;
int V_77 = V_17 & V_36 ;
int V_20 ;
V_23:
V_30 = 0 ;
V_20 = 0 ;
while ( ( V_16 = F_96 ( V_14 , V_30 , V_61 ) ) ) {
unsigned long V_18 = 0 ;
int V_21 = 0 ;
int V_22 = 0 ;
V_30 = V_16 -> V_28 + 1 ;
if ( V_77 ) {
if ( ! F_97 ( & V_16 -> V_78 ) ) {
V_20 ++ ;
F_22 ( V_16 ) ;
continue;
}
V_18 = V_16 -> V_79 ;
} else
F_98 ( & V_16 -> V_78 ) ;
do {
struct V_1 * V_24 [ V_25 ] ;
int V_26 ;
F_13 () ;
V_22 = F_99 (
& V_16 -> V_27 ,
( void * * ) V_24 , V_18 ,
V_25 ,
V_61 ) ;
if ( ! V_22 ) {
V_21 = 1 ;
F_15 () ;
break;
}
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
struct V_1 * V_2 = V_24 [ V_26 ] ;
if ( V_21 || F_79 ( V_2 , V_17 ) )
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
error = F_80 ( V_24 [ V_26 ] , V_16 , V_17 ) ;
if ( error && V_19 != V_11 )
V_19 = error ;
}
* V_76 -= V_25 ;
F_18 () ;
} while ( V_22 && ! V_21 && * V_76 > 0 );
if ( V_77 && ! V_21 )
V_16 -> V_79 = V_18 ;
else
V_16 -> V_79 = 0 ;
F_100 ( & V_16 -> V_78 ) ;
F_22 ( V_16 ) ;
}
if ( V_20 && ( V_17 & V_37 ) && * V_76 > 0 ) {
V_77 = 0 ;
goto V_23;
}
return F_23 ( V_19 ) ;
}
int
F_42 (
T_5 * V_14 ,
int V_80 )
{
int V_76 = V_81 ;
return F_95 ( V_14 , V_80 , & V_76 ) ;
}
void
F_101 (
struct V_13 * V_14 ,
int V_76 )
{
F_57 ( V_14 ) ;
F_56 ( V_14 -> V_45 ) ;
F_95 ( V_14 , V_36 | V_37 , & V_76 ) ;
}
int
F_102 (
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
T_2 V_30 = 0 ;
int V_82 = 0 ;
while ( ( V_16 = F_96 ( V_14 , V_30 , V_61 ) ) ) {
V_30 = V_16 -> V_28 + 1 ;
V_82 += V_16 -> V_64 ;
F_22 ( V_16 ) ;
}
return V_82 ;
}
