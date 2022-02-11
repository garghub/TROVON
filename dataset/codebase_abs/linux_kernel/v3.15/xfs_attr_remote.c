int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
if ( F_2 ( & V_2 -> V_4 ) ) {
int V_5 = F_3 ( V_2 , V_2 -> V_4 . V_6 ) ;
return ( V_3 + V_5 - 1 ) / V_5 ;
}
return F_4 ( V_2 , V_3 ) ;
}
static bool
F_5 (
struct V_1 * V_2 ,
void * V_7 ,
T_1 V_8 ,
T_2 V_9 ,
T_2 V_10 ,
T_3 V_11 )
{
struct V_12 * V_13 = V_7 ;
if ( V_11 != F_6 ( V_13 -> V_14 ) )
return false ;
if ( V_9 != F_7 ( V_13 -> V_15 ) )
return false ;
if ( V_10 != F_7 ( V_13 -> V_16 ) )
return false ;
if ( V_8 != F_6 ( V_13 -> V_17 ) )
return false ;
return true ;
}
static bool
F_8 (
struct V_1 * V_2 ,
void * V_7 ,
int V_18 ,
T_3 V_11 )
{
struct V_12 * V_13 = V_7 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return false ;
if ( V_13 -> V_19 != F_9 ( V_20 ) )
return false ;
if ( ! F_10 ( & V_13 -> V_21 , & V_2 -> V_4 . V_22 ) )
return false ;
if ( F_6 ( V_13 -> V_14 ) != V_11 )
return false ;
if ( F_7 ( V_13 -> V_16 ) > V_18 - sizeof( * V_13 ) )
return false ;
if ( F_7 ( V_13 -> V_15 ) +
F_7 ( V_13 -> V_16 ) > V_23 )
return false ;
if ( V_13 -> V_17 == 0 )
return false ;
return true ;
}
static void
F_11 (
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 -> V_27 ;
char * V_7 ;
int V_28 ;
T_3 V_11 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return;
V_7 = V_25 -> V_29 ;
V_11 = V_25 -> V_30 ;
V_28 = F_12 ( V_25 -> V_31 ) ;
ASSERT ( V_28 >= F_13 ( V_2 ) ) ;
while ( V_28 > 0 ) {
if ( ! F_14 ( V_7 , F_13 ( V_2 ) ,
V_32 ) ) {
F_15 ( V_25 , V_33 ) ;
break;
}
if ( ! F_8 ( V_2 , V_7 , F_13 ( V_2 ) , V_11 ) ) {
F_15 ( V_25 , V_34 ) ;
break;
}
V_28 -= F_13 ( V_2 ) ;
V_7 += F_13 ( V_2 ) ;
V_11 += V_2 -> V_35 ;
}
if ( V_25 -> V_36 )
F_16 ( V_25 ) ;
else
ASSERT ( V_28 == 0 ) ;
}
static void
F_17 (
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 -> V_27 ;
struct V_37 * V_38 = V_25 -> V_39 ;
char * V_7 ;
int V_28 ;
T_3 V_11 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return;
V_7 = V_25 -> V_29 ;
V_11 = V_25 -> V_30 ;
V_28 = F_12 ( V_25 -> V_31 ) ;
ASSERT ( V_28 >= F_13 ( V_2 ) ) ;
while ( V_28 > 0 ) {
if ( ! F_8 ( V_2 , V_7 , F_13 ( V_2 ) , V_11 ) ) {
F_15 ( V_25 , V_34 ) ;
F_16 ( V_25 ) ;
return;
}
if ( V_38 ) {
struct V_12 * V_13 ;
V_13 = (struct V_12 * ) V_7 ;
V_13 -> V_40 = F_18 ( V_38 -> V_41 . V_42 ) ;
}
F_19 ( V_7 , F_13 ( V_2 ) , V_32 ) ;
V_28 -= F_13 ( V_2 ) ;
V_7 += F_13 ( V_2 ) ;
V_11 += V_2 -> V_35 ;
}
ASSERT ( V_28 == 0 ) ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
void * V_7 ,
T_1 V_8 ,
T_2 V_9 ,
T_2 V_10 ,
T_3 V_11 )
{
struct V_12 * V_13 = V_7 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return 0 ;
V_13 -> V_19 = F_9 ( V_20 ) ;
V_13 -> V_15 = F_9 ( V_9 ) ;
V_13 -> V_16 = F_9 ( V_10 ) ;
F_21 ( & V_13 -> V_21 , & V_2 -> V_4 . V_22 ) ;
V_13 -> V_17 = F_18 ( V_8 ) ;
V_13 -> V_14 = F_18 ( V_11 ) ;
return sizeof( struct V_12 ) ;
}
STATIC int
F_22 (
struct V_1 * V_2 ,
struct V_24 * V_25 ,
T_1 V_8 ,
int * V_9 ,
int * V_43 ,
T_4 * * V_44 )
{
char * V_45 = V_25 -> V_29 ;
T_3 V_11 = V_25 -> V_30 ;
int V_28 = F_12 ( V_25 -> V_31 ) ;
ASSERT ( V_28 >= F_13 ( V_2 ) ) ;
while ( V_28 > 0 && * V_43 > 0 ) {
int V_46 = 0 ;
int V_47 = F_3 ( V_2 , F_13 ( V_2 ) ) ;
V_47 = F_23 ( * V_43 , V_47 ) ;
if ( F_2 ( & V_2 -> V_4 ) ) {
if ( ! F_5 ( V_2 , V_45 , V_8 , * V_9 ,
V_47 , V_11 ) ) {
F_24 ( V_2 ,
L_1 ,
V_11 , * V_9 , V_47 , V_8 ) ;
return V_34 ;
}
V_46 = sizeof( struct V_12 ) ;
}
memcpy ( * V_44 , V_45 + V_46 , V_47 ) ;
V_28 -= F_13 ( V_2 ) ;
V_45 += F_13 ( V_2 ) ;
V_11 += V_2 -> V_35 ;
* V_43 -= V_47 ;
* V_44 += V_47 ;
* V_9 += V_47 ;
}
return 0 ;
}
STATIC void
F_25 (
struct V_1 * V_2 ,
struct V_24 * V_25 ,
T_1 V_8 ,
int * V_9 ,
int * V_43 ,
T_4 * * V_45 )
{
char * V_44 = V_25 -> V_29 ;
T_3 V_11 = V_25 -> V_30 ;
int V_28 = F_12 ( V_25 -> V_31 ) ;
ASSERT ( V_28 >= F_13 ( V_2 ) ) ;
while ( V_28 > 0 && * V_43 > 0 ) {
int V_46 ;
int V_47 = F_3 ( V_2 , F_13 ( V_2 ) ) ;
V_47 = F_23 ( * V_43 , V_47 ) ;
V_46 = F_20 ( V_2 , V_44 , V_8 , * V_9 ,
V_47 , V_11 ) ;
memcpy ( V_44 + V_46 , * V_45 , V_47 ) ;
if ( V_47 + V_46 < F_13 ( V_2 ) ) {
ASSERT ( * V_43 - V_47 == 0 ) ;
ASSERT ( V_28 == F_13 ( V_2 ) ) ;
memset ( V_44 + V_46 + V_47 , 0 ,
F_13 ( V_2 ) - V_46 - V_47 ) ;
}
V_28 -= F_13 ( V_2 ) ;
V_44 += F_13 ( V_2 ) ;
V_11 += V_2 -> V_35 ;
* V_43 -= V_47 ;
* V_45 += V_47 ;
* V_9 += V_47 ;
}
}
int
F_26 (
struct V_48 * args )
{
struct V_49 V_50 [ V_51 ] ;
struct V_1 * V_2 = args -> V_52 -> V_53 ;
struct V_24 * V_25 ;
T_5 V_54 = args -> V_55 ;
T_4 * V_44 = args -> V_56 ;
int V_43 ;
int V_57 ;
int error ;
int V_58 = args -> V_59 ;
int V_60 ;
int V_9 = 0 ;
F_27 ( args ) ;
ASSERT ( ! ( args -> V_61 & V_62 ) ) ;
ASSERT ( args -> V_63 == args -> V_43 ) ;
V_43 = args -> V_63 ;
while ( V_43 > 0 ) {
V_57 = V_51 ;
error = F_28 ( args -> V_52 , ( V_64 ) V_54 ,
V_58 , V_50 , & V_57 ,
V_65 ) ;
if ( error )
return error ;
ASSERT ( V_57 >= 1 ) ;
for ( V_60 = 0 ; ( V_60 < V_57 ) && ( V_43 > 0 ) ; V_60 ++ ) {
T_3 V_66 ;
int V_67 ;
ASSERT ( ( V_50 [ V_60 ] . V_68 != V_69 ) &&
( V_50 [ V_60 ] . V_68 != V_70 ) ) ;
V_66 = F_29 ( V_2 , V_50 [ V_60 ] . V_68 ) ;
V_67 = F_30 ( V_2 , V_50 [ V_60 ] . V_71 ) ;
error = F_31 ( V_2 , NULL , V_2 -> V_72 ,
V_66 , V_67 , 0 , & V_25 ,
& V_73 ) ;
if ( error )
return error ;
error = F_22 ( V_2 , V_25 , args -> V_52 -> V_74 ,
& V_9 , & V_43 ,
& V_44 ) ;
F_32 ( V_25 ) ;
if ( error )
return error ;
V_54 += V_50 [ V_60 ] . V_71 ;
V_58 -= V_50 [ V_60 ] . V_71 ;
}
}
ASSERT ( V_43 == 0 ) ;
return 0 ;
}
int
F_33 (
struct V_48 * args )
{
struct V_75 * V_52 = args -> V_52 ;
struct V_1 * V_2 = V_52 -> V_53 ;
struct V_49 V_50 ;
T_5 V_54 ;
V_64 V_76 = 0 ;
T_4 * V_45 = args -> V_56 ;
int V_58 ;
int V_43 ;
int V_57 ;
int error ;
int V_9 = 0 ;
F_34 ( args ) ;
V_58 = F_1 ( V_2 , args -> V_63 ) ;
error = F_35 ( args -> V_77 , args -> V_52 , V_58 , & V_76 ,
V_78 ) ;
if ( error )
return error ;
args -> V_55 = V_54 = ( T_5 ) V_76 ;
args -> V_59 = V_58 ;
while ( V_58 > 0 ) {
int V_79 ;
F_36 ( args -> V_80 , args -> V_81 ) ;
V_57 = 1 ;
error = F_37 ( args -> V_77 , V_52 , ( V_64 ) V_54 ,
V_58 ,
V_65 | V_82 ,
args -> V_81 , args -> V_83 , & V_50 , & V_57 ,
args -> V_80 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_77 , args -> V_80 ,
& V_79 ) ;
}
if ( error ) {
ASSERT ( V_79 ) ;
args -> V_77 = NULL ;
F_39 ( args -> V_80 ) ;
return ( error ) ;
}
if ( V_79 )
F_40 ( args -> V_77 , V_52 , 0 ) ;
ASSERT ( V_57 == 1 ) ;
ASSERT ( ( V_50 . V_68 != V_69 ) &&
( V_50 . V_68 != V_70 ) ) ;
V_54 += V_50 . V_71 ;
V_58 -= V_50 . V_71 ;
error = F_41 ( & args -> V_77 , V_52 ) ;
if ( error )
return ( error ) ;
}
V_54 = args -> V_55 ;
V_58 = args -> V_59 ;
V_43 = args -> V_63 ;
while ( V_43 > 0 ) {
struct V_24 * V_25 ;
T_3 V_66 ;
int V_67 ;
ASSERT ( V_58 > 0 ) ;
F_36 ( args -> V_80 , args -> V_81 ) ;
V_57 = 1 ;
error = F_28 ( V_52 , ( V_64 ) V_54 ,
V_58 , & V_50 , & V_57 ,
V_65 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_57 == 1 ) ;
ASSERT ( ( V_50 . V_68 != V_69 ) &&
( V_50 . V_68 != V_70 ) ) ;
V_66 = F_29 ( V_2 , V_50 . V_68 ) ,
V_67 = F_30 ( V_2 , V_50 . V_71 ) ;
V_25 = F_42 ( V_2 -> V_72 , V_66 , V_67 , 0 ) ;
if ( ! V_25 )
return V_84 ;
V_25 -> V_85 = & V_73 ;
F_25 ( V_2 , V_25 , args -> V_52 -> V_74 , & V_9 ,
& V_43 , & V_45 ) ;
error = F_43 ( V_25 ) ;
F_32 ( V_25 ) ;
if ( error )
return error ;
V_54 += V_50 . V_71 ;
V_58 -= V_50 . V_71 ;
}
ASSERT ( V_43 == 0 ) ;
return 0 ;
}
int
F_44 (
struct V_48 * args )
{
struct V_1 * V_2 = args -> V_52 -> V_53 ;
T_5 V_54 ;
int V_58 ;
int error ;
int V_86 ;
F_45 ( args ) ;
V_54 = args -> V_55 ;
V_58 = args -> V_59 ;
while ( V_58 > 0 ) {
struct V_49 V_50 ;
struct V_24 * V_25 ;
T_3 V_66 ;
int V_67 ;
int V_57 ;
V_57 = 1 ;
error = F_28 ( args -> V_52 , ( V_64 ) V_54 ,
V_58 , & V_50 , & V_57 , V_65 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_57 == 1 ) ;
ASSERT ( ( V_50 . V_68 != V_69 ) &&
( V_50 . V_68 != V_70 ) ) ;
V_66 = F_29 ( V_2 , V_50 . V_68 ) ,
V_67 = F_30 ( V_2 , V_50 . V_71 ) ;
V_25 = F_46 ( V_2 -> V_72 , V_66 , V_67 , V_87 ) ;
if ( V_25 ) {
F_47 ( V_25 ) ;
F_32 ( V_25 ) ;
V_25 = NULL ;
}
V_54 += V_50 . V_71 ;
V_58 -= V_50 . V_71 ;
}
V_54 = args -> V_55 ;
V_58 = args -> V_59 ;
V_86 = 0 ;
while ( ! V_86 ) {
int V_79 ;
F_36 ( args -> V_80 , args -> V_81 ) ;
error = F_48 ( args -> V_77 , args -> V_52 , V_54 , V_58 ,
V_65 | V_82 ,
1 , args -> V_81 , args -> V_80 ,
& V_86 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_77 , args -> V_80 ,
& V_79 ) ;
}
if ( error ) {
ASSERT ( V_79 ) ;
args -> V_77 = NULL ;
F_39 ( args -> V_80 ) ;
return error ;
}
if ( V_79 )
F_40 ( args -> V_77 , args -> V_52 , 0 ) ;
error = F_41 ( & args -> V_77 , args -> V_52 ) ;
if ( error )
return ( error ) ;
}
return ( 0 ) ;
}
