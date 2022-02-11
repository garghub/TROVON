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
int V_29 = V_2 -> V_30 -> V_29 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return;
V_7 = V_25 -> V_31 ;
V_11 = V_25 -> V_32 ;
V_28 = F_12 ( V_25 -> V_33 ) ;
ASSERT ( V_28 >= V_29 ) ;
while ( V_28 > 0 ) {
if ( ! F_13 ( V_7 , V_29 , V_34 ) ) {
F_14 ( V_25 , - V_35 ) ;
break;
}
if ( ! F_8 ( V_2 , V_7 , V_29 , V_11 ) ) {
F_14 ( V_25 , - V_36 ) ;
break;
}
V_28 -= V_29 ;
V_7 += V_29 ;
V_11 += F_15 ( V_29 ) ;
}
if ( V_25 -> V_37 )
F_16 ( V_25 ) ;
else
ASSERT ( V_28 == 0 ) ;
}
static void
F_17 (
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 -> V_27 ;
int V_29 = V_2 -> V_30 -> V_29 ;
char * V_7 ;
int V_28 ;
T_3 V_11 ;
if ( ! F_2 ( & V_2 -> V_4 ) )
return;
V_7 = V_25 -> V_31 ;
V_11 = V_25 -> V_32 ;
V_28 = F_12 ( V_25 -> V_33 ) ;
ASSERT ( V_28 >= V_29 ) ;
while ( V_28 > 0 ) {
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
if ( ! F_8 ( V_2 , V_7 , V_29 , V_11 ) ) {
F_14 ( V_25 , - V_36 ) ;
F_16 ( V_25 ) ;
return;
}
if ( V_13 -> V_38 != F_18 ( V_39 ) ) {
F_14 ( V_25 , - V_36 ) ;
F_16 ( V_25 ) ;
return;
}
F_19 ( V_7 , V_29 , V_34 ) ;
V_28 -= V_29 ;
V_7 += V_29 ;
V_11 += F_15 ( V_29 ) ;
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
V_13 -> V_38 = F_18 ( V_39 ) ;
return sizeof( struct V_12 ) ;
}
STATIC int
F_22 (
struct V_1 * V_2 ,
struct V_24 * V_25 ,
T_1 V_8 ,
int * V_9 ,
int * V_40 ,
T_4 * * V_41 )
{
char * V_42 = V_25 -> V_31 ;
T_3 V_11 = V_25 -> V_32 ;
int V_28 = F_12 ( V_25 -> V_33 ) ;
int V_29 = V_2 -> V_30 -> V_29 ;
ASSERT ( V_28 >= V_29 ) ;
while ( V_28 > 0 && * V_40 > 0 ) {
int V_43 = 0 ;
int V_44 = F_3 ( V_2 , V_29 ) ;
V_44 = F_23 ( * V_40 , V_44 ) ;
if ( F_2 ( & V_2 -> V_4 ) ) {
if ( ! F_5 ( V_42 , V_8 , * V_9 ,
V_44 , V_11 ) ) {
F_24 ( V_2 ,
L_1 ,
V_11 , * V_9 , V_44 , V_8 ) ;
return - V_36 ;
}
V_43 = sizeof( struct V_12 ) ;
}
memcpy ( * V_41 , V_42 + V_43 , V_44 ) ;
V_28 -= V_29 ;
V_42 += V_29 ;
V_11 += F_15 ( V_29 ) ;
* V_40 -= V_44 ;
* V_41 += V_44 ;
* V_9 += V_44 ;
}
return 0 ;
}
STATIC void
F_25 (
struct V_1 * V_2 ,
struct V_24 * V_25 ,
T_1 V_8 ,
int * V_9 ,
int * V_40 ,
T_4 * * V_42 )
{
char * V_41 = V_25 -> V_31 ;
T_3 V_11 = V_25 -> V_32 ;
int V_28 = F_12 ( V_25 -> V_33 ) ;
int V_29 = V_2 -> V_30 -> V_29 ;
ASSERT ( V_28 >= V_29 ) ;
while ( V_28 > 0 && * V_40 > 0 ) {
int V_43 ;
int V_44 = F_3 ( V_2 , V_29 ) ;
V_44 = F_23 ( * V_40 , V_44 ) ;
V_43 = F_20 ( V_2 , V_41 , V_8 , * V_9 ,
V_44 , V_11 ) ;
memcpy ( V_41 + V_43 , * V_42 , V_44 ) ;
if ( V_44 + V_43 < V_29 ) {
ASSERT ( * V_40 - V_44 == 0 ) ;
ASSERT ( V_28 == V_29 ) ;
memset ( V_41 + V_43 + V_44 , 0 ,
V_29 - V_43 - V_44 ) ;
}
V_28 -= V_29 ;
V_41 += V_29 ;
V_11 += F_15 ( V_29 ) ;
* V_40 -= V_44 ;
* V_42 += V_44 ;
* V_9 += V_44 ;
}
}
int
F_26 (
struct V_45 * args )
{
struct V_46 V_47 [ V_48 ] ;
struct V_1 * V_2 = args -> V_49 -> V_50 ;
struct V_24 * V_25 ;
T_5 V_51 = args -> V_52 ;
T_4 * V_41 = args -> V_53 ;
int V_40 ;
int V_54 ;
int error ;
int V_55 = args -> V_56 ;
int V_57 ;
int V_9 = 0 ;
F_27 ( args ) ;
ASSERT ( ! ( args -> V_58 & V_59 ) ) ;
ASSERT ( args -> V_60 == args -> V_40 ) ;
V_40 = args -> V_60 ;
while ( V_40 > 0 ) {
V_54 = V_48 ;
error = F_28 ( args -> V_49 , ( V_61 ) V_51 ,
V_55 , V_47 , & V_54 ,
V_62 ) ;
if ( error )
return error ;
ASSERT ( V_54 >= 1 ) ;
for ( V_57 = 0 ; ( V_57 < V_54 ) && ( V_40 > 0 ) ; V_57 ++ ) {
T_3 V_63 ;
int V_64 ;
ASSERT ( ( V_47 [ V_57 ] . V_65 != V_66 ) &&
( V_47 [ V_57 ] . V_65 != V_67 ) ) ;
V_63 = F_29 ( V_2 , V_47 [ V_57 ] . V_65 ) ;
V_64 = F_30 ( V_2 , V_47 [ V_57 ] . V_68 ) ;
error = F_31 ( V_2 , NULL , V_2 -> V_69 ,
V_63 , V_64 , 0 , & V_25 ,
& V_70 ) ;
if ( error )
return error ;
error = F_22 ( V_2 , V_25 , args -> V_49 -> V_71 ,
& V_9 , & V_40 ,
& V_41 ) ;
F_32 ( V_25 ) ;
if ( error )
return error ;
V_51 += V_47 [ V_57 ] . V_68 ;
V_55 -= V_47 [ V_57 ] . V_68 ;
}
}
ASSERT ( V_40 == 0 ) ;
return 0 ;
}
int
F_33 (
struct V_45 * args )
{
struct V_72 * V_49 = args -> V_49 ;
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_46 V_47 ;
T_5 V_51 ;
V_61 V_73 = 0 ;
T_4 * V_42 = args -> V_53 ;
int V_55 ;
int V_40 ;
int V_54 ;
int error ;
int V_9 = 0 ;
F_34 ( args ) ;
V_55 = F_1 ( V_2 , args -> V_60 ) ;
error = F_35 ( args -> V_74 , args -> V_49 , V_55 , & V_73 ,
V_75 ) ;
if ( error )
return error ;
args -> V_52 = V_51 = ( T_5 ) V_73 ;
args -> V_56 = V_55 ;
while ( V_55 > 0 ) {
int V_76 ;
F_36 ( args -> V_77 , args -> V_78 ) ;
V_54 = 1 ;
error = F_37 ( args -> V_74 , V_49 , ( V_61 ) V_51 ,
V_55 , V_62 , args -> V_78 ,
args -> V_79 , & V_47 , & V_54 , args -> V_77 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_74 , args -> V_77 ,
& V_76 ) ;
}
if ( error ) {
ASSERT ( V_76 ) ;
args -> V_74 = NULL ;
F_39 ( args -> V_77 ) ;
return error ;
}
if ( V_76 )
F_40 ( args -> V_74 , V_49 , 0 ) ;
ASSERT ( V_54 == 1 ) ;
ASSERT ( ( V_47 . V_65 != V_66 ) &&
( V_47 . V_65 != V_67 ) ) ;
V_51 += V_47 . V_68 ;
V_55 -= V_47 . V_68 ;
error = F_41 ( & args -> V_74 , V_49 ) ;
if ( error )
return error ;
}
V_51 = args -> V_52 ;
V_55 = args -> V_56 ;
V_40 = args -> V_60 ;
while ( V_40 > 0 ) {
struct V_24 * V_25 ;
T_3 V_63 ;
int V_64 ;
ASSERT ( V_55 > 0 ) ;
F_36 ( args -> V_77 , args -> V_78 ) ;
V_54 = 1 ;
error = F_28 ( V_49 , ( V_61 ) V_51 ,
V_55 , & V_47 , & V_54 ,
V_62 ) ;
if ( error )
return error ;
ASSERT ( V_54 == 1 ) ;
ASSERT ( ( V_47 . V_65 != V_66 ) &&
( V_47 . V_65 != V_67 ) ) ;
V_63 = F_29 ( V_2 , V_47 . V_65 ) ,
V_64 = F_30 ( V_2 , V_47 . V_68 ) ;
V_25 = F_42 ( V_2 -> V_69 , V_63 , V_64 , 0 ) ;
if ( ! V_25 )
return - V_80 ;
V_25 -> V_81 = & V_70 ;
F_25 ( V_2 , V_25 , args -> V_49 -> V_71 , & V_9 ,
& V_40 , & V_42 ) ;
error = F_43 ( V_25 ) ;
F_32 ( V_25 ) ;
if ( error )
return error ;
V_51 += V_47 . V_68 ;
V_55 -= V_47 . V_68 ;
}
ASSERT ( V_40 == 0 ) ;
return 0 ;
}
int
F_44 (
struct V_45 * args )
{
struct V_1 * V_2 = args -> V_49 -> V_50 ;
T_5 V_51 ;
int V_55 ;
int error ;
int V_82 ;
F_45 ( args ) ;
V_51 = args -> V_52 ;
V_55 = args -> V_56 ;
while ( V_55 > 0 ) {
struct V_46 V_47 ;
struct V_24 * V_25 ;
T_3 V_63 ;
int V_64 ;
int V_54 ;
V_54 = 1 ;
error = F_28 ( args -> V_49 , ( V_61 ) V_51 ,
V_55 , & V_47 , & V_54 , V_62 ) ;
if ( error )
return error ;
ASSERT ( V_54 == 1 ) ;
ASSERT ( ( V_47 . V_65 != V_66 ) &&
( V_47 . V_65 != V_67 ) ) ;
V_63 = F_29 ( V_2 , V_47 . V_65 ) ,
V_64 = F_30 ( V_2 , V_47 . V_68 ) ;
V_25 = F_46 ( V_2 -> V_69 , V_63 , V_64 , V_83 ) ;
if ( V_25 ) {
F_47 ( V_25 ) ;
F_32 ( V_25 ) ;
V_25 = NULL ;
}
V_51 += V_47 . V_68 ;
V_55 -= V_47 . V_68 ;
}
V_51 = args -> V_52 ;
V_55 = args -> V_56 ;
V_82 = 0 ;
while ( ! V_82 ) {
int V_76 ;
F_36 ( args -> V_77 , args -> V_78 ) ;
error = F_48 ( args -> V_74 , args -> V_49 , V_51 , V_55 ,
V_62 , 1 , args -> V_78 ,
args -> V_77 , & V_82 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_74 , args -> V_77 ,
& V_76 ) ;
}
if ( error ) {
ASSERT ( V_76 ) ;
args -> V_74 = NULL ;
F_39 ( args -> V_77 ) ;
return error ;
}
if ( V_76 )
F_40 ( args -> V_74 , args -> V_49 , 0 ) ;
error = F_41 ( & args -> V_74 , args -> V_49 ) ;
if ( error )
return error ;
}
return 0 ;
}
