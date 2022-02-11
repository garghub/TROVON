static void
F_1 ( short * V_1 , const short * V_2 , unsigned V_3 , unsigned V_4 )
{
assert ( ( int ) V_3 >= 0 ) ;
assert ( ( int ) V_4 >= 0 ) ;
memcpy ( V_1 , V_2 , V_3 * sizeof( short ) ) ;
memset ( & V_1 [ V_3 ] , 0 , V_4 * sizeof( short ) ) ;
}
void F_2 (
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
unsigned V_10 = V_8 -> V_11 . V_10 * V_8 -> V_11 . V_12 ;
unsigned V_3 = V_8 -> V_11 . V_13 ;
int V_4 = V_10 - V_3 ;
unsigned V_14 = V_9 / V_15 / sizeof( short ) ;
unsigned V_16 = V_10 * V_15 * sizeof( short ) ;
short * V_2 = V_8 -> V_17 ;
short * V_1 = ( short * ) V_6 ;
unsigned type ;
assert ( V_4 >= 0 ) ;
assert ( V_16 <= V_9 ) ;
assert ( V_9 % ( V_15 * V_18 * sizeof( short ) ) == 0 ) ;
for ( type = 0 ; type < V_15 ; type ++ ) {
F_1 ( & V_1 [ type * V_14 ] , & V_2 [ type * V_3 ] , V_3 , V_4 ) ;
}
}
void F_3 (
struct V_19 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
unsigned V_20 = V_8 -> V_11 . V_20 * V_8 -> V_11 . V_12 ;
unsigned V_21 = V_8 -> V_11 . V_22 ;
int V_4 = V_20 - V_21 ;
unsigned V_14 = V_9 / V_15 / sizeof( short ) ;
unsigned V_16 = V_20 * V_15 * sizeof( short ) ;
short * V_2 = V_8 -> V_23 ;
short * V_1 = ( short * ) V_6 ;
unsigned type ;
assert ( V_4 >= 0 ) ;
assert ( V_16 <= V_9 ) ;
assert ( V_9 % ( V_15 * V_18 * sizeof( short ) ) == 0 ) ;
for ( type = 0 ; type < V_15 ; type ++ ) {
F_1 ( & V_1 [ type * V_14 ] , & V_2 [ type * V_21 ] , V_21 , V_4 ) ;
}
}
void F_4 (
struct V_24 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
( void ) V_6 ;
( void ) V_8 ;
( void ) V_9 ;
}
void F_5 (
struct V_25 * V_6 ,
const struct V_7 * V_8 ,
unsigned V_9 )
{
( void ) V_6 ;
( void ) V_8 ;
( void ) V_9 ;
}
void F_6 (
struct V_26 * V_27 ,
short * V_28 ,
short * V_29 )
{
struct V_30 * V_31 ;
unsigned int V_32 , V_33 ;
unsigned int V_34 , V_35 ;
int V_36 ;
struct V_37 * V_38 ;
F_7 ( L_1 ) ;
assert ( V_28 != NULL ) ;
assert ( V_29 != NULL ) ;
V_31 = V_27 -> V_39 ;
V_38 = F_8 ( V_27 ) ;
if ( ! V_38 )
return;
V_32 = V_38 -> V_40 . V_41 . V_42 . V_3 ;
V_33 = V_38 -> V_40 . V_41 . V_42 . V_21 ;
V_34 = V_38 -> V_40 . V_41 . V_43 . V_3 ;
V_35 = V_38 -> V_40 . V_41 . V_43 . V_21 ;
for ( V_36 = 0 ; V_36 < V_15 ; V_36 ++ ) {
F_1 ( & V_28 [ V_36 * V_32 ] ,
& V_31 -> V_44 . V_17 [ V_36 * V_34 ] , V_34 , V_32 - V_34 ) ;
}
for ( V_36 = 0 ; V_36 < F_9 ( V_38 ) ; V_36 ++ ) {
F_1 ( & V_29 [ V_36 * V_33 ] ,
& V_31 -> V_44 . V_23 [ V_36 * V_35 ] , V_35 , V_33 - V_35 ) ;
}
F_10 ( L_1 ) ;
}
T_1
F_11 (
const struct V_37 * V_45 )
{
if ( V_45 -> V_46 -> V_47 . V_48 . V_49 == 1 )
return sizeof( short ) * V_15 * V_45 -> V_40 . V_41 . V_42 . V_3 ;
else
return sizeof( short ) * V_50 * V_45 -> V_40 . V_41 . V_42 . V_3 ;
}
T_1
F_12 (
const struct V_37 * V_45 )
{
return sizeof( short ) * F_9 ( V_45 ) * V_45 -> V_40 . V_41 . V_42 . V_21 ;
}
void
F_13 (
struct V_51 * V_40 ,
unsigned V_52 ,
unsigned V_53 ,
unsigned V_54 ,
unsigned V_49 ,
unsigned V_55 )
{
if ( ! V_55 ) {
struct V_51 V_56 = V_57 ;
* V_40 = V_56 ;
return;
}
V_40 -> V_58 = V_59 ;
V_40 -> V_11 . V_43 . V_3 =
F_14 ( V_52 ) >> V_59 ;
V_40 -> V_11 . V_43 . V_21 =
F_14 ( V_54 ) >> V_59 ;
V_40 -> V_11 . V_42 . V_3 =
F_15 ( F_14 ( V_53 ) , V_59 ) ;
V_40 -> V_11 . V_42 . V_21 =
F_15 ( F_14 ( V_54 ) , V_59 ) ;
V_40 -> V_41 . V_43 . V_3 =
( F_14 ( V_52 ) >> V_59 ) << V_59 ;
V_40 -> V_41 . V_43 . V_21 =
( F_14 ( V_54 ) >> V_59 ) << V_59 ;
V_40 -> V_41 . V_42 . V_3 =
F_16 ( V_53 ) * V_18 ;
V_40 -> V_41 . V_42 . V_21 =
F_17 ( V_54 ) * V_18 ;
if ( V_49 == 1 ) {
V_40 -> V_60 . V_43 . V_3 =
F_14 ( V_54 ) >> V_59 ;
V_40 -> V_60 . V_43 . V_21 =
F_14 ( V_52 ) >> V_59 ;
} else {
V_40 -> V_60 . V_43 . V_3 =
( F_14 ( V_52 ) >> V_59 ) *
( F_14 ( V_54 ) >> V_59 ) ;
V_40 -> V_60 . V_43 . V_21 =
( F_14 ( V_52 ) >> V_59 ) *
( F_14 ( V_54 ) >> V_59 ) ;
}
V_40 -> V_60 . V_42 . V_3 =
F_18 ( V_53 ,
V_54 ,
V_59 ,
V_49 ) ;
V_40 -> V_60 . V_42 . V_21 =
F_19 ( V_53 ,
V_59 ) ;
}
void F_20 (
struct V_7 * V_44 )
{
V_44 -> V_17 = NULL ;
V_44 -> V_23 = NULL ;
}
enum V_61
F_21 (
struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_66 * V_67 ;
enum V_61 V_68 = V_69 ;
F_7 ( L_2 , V_63 , V_65 ) ;
assert ( V_63 != NULL ) ;
assert ( V_65 != NULL ) ;
V_67 = F_22 ( V_65 , NULL ) ;
if ( V_67 ) {
F_23 ( V_65 -> V_70 , V_67 -> V_70 , V_65 -> V_9 ) ;
F_24 ( V_63 , V_67 ) ;
F_25 ( V_67 ) ;
} else {
F_26 ( L_3 ) ;
V_68 = V_71 ;
}
F_27 ( V_68 ) ;
return V_68 ;
}
void
F_24 (
struct V_62 * V_63 ,
const struct V_66 * V_65 )
{
unsigned int V_32 , V_33 , V_72 , V_73 , V_36 ;
T_2 * V_74 , * V_75 , * V_76 , * V_77 ;
assert ( V_63 != NULL ) ;
assert ( V_63 -> V_78 != NULL ) ;
assert ( V_63 -> V_79 != NULL ) ;
assert ( V_65 != NULL ) ;
assert ( V_65 -> V_78 != NULL ) ;
assert ( V_65 -> V_79 != NULL ) ;
F_7 ( L_4 ,
V_63 -> V_78 , V_63 -> V_79 ,
V_65 -> V_78 , V_65 -> V_79 ) ;
V_32 = V_63 -> V_11 . V_20 ;
V_33 = V_63 -> V_11 . V_10 ;
V_76 = V_65 -> V_78 ;
V_77 = V_65 -> V_79 ;
V_72 = V_63 -> V_11 . V_21 ;
V_73 = V_63 -> V_11 . V_3 ;
V_74 = V_63 -> V_78 ;
V_75 = V_63 -> V_79 ;
for ( V_36 = 0 ; V_36 < V_15 ; V_36 ++ ) {
memcpy ( V_74 , V_76 , V_72 * sizeof( T_2 ) ) ;
V_76 += V_32 ;
V_74 += V_72 ;
memcpy ( V_75 , V_77 , V_73 * sizeof( T_2 ) ) ;
V_77 += V_33 ;
V_75 += V_73 ;
}
F_10 ( L_1 ) ;
}
struct V_64 *
F_28 (
const struct V_80 * V_11 )
{
struct V_64 * V_81 ;
int V_82 , V_83 ;
assert ( V_11 != NULL ) ;
F_7 ( L_5 , V_11 ) ;
if ( ! V_11 -> V_84 )
return NULL ;
V_81 = F_29 ( 1 , sizeof( * V_81 ) ) ;
if ( ! V_81 )
goto V_85;
V_82 = F_30 ( sizeof( int ) * V_15 * V_11 -> V_20 ,
V_86 ) ;
V_83 = F_30 ( sizeof( int ) * V_15 * V_11 -> V_10 ,
V_86 ) ;
V_81 -> V_9 = V_82 + V_83 ;
V_81 -> V_70 = F_31 ( V_81 -> V_9 ) ;
if ( V_81 -> V_70 == V_87 )
goto V_85;
V_81 -> V_82 = V_82 ;
V_81 -> V_78 = V_81 -> V_70 ;
V_81 -> V_83 = V_83 ;
V_81 -> V_79 = V_81 -> V_70 + V_82 ;
F_10 ( L_6 , V_81 ) ;
return V_81 ;
V_85:
F_32 ( V_81 ) ;
F_10 ( L_6 , NULL ) ;
return NULL ;
}
struct V_66 *
F_22 (
const struct V_64 * V_65 ,
void * V_70 )
{
struct V_66 * V_81 ;
char * V_88 ;
V_81 = F_33 ( sizeof( * V_81 ) ) ;
if ( ! V_81 ) {
F_34 ( L_7 ) ;
goto V_85;
}
V_81 -> V_70 = V_70 ;
V_81 -> V_89 = V_70 == NULL ;
if ( ! V_81 -> V_70 ) {
V_81 -> V_70 = F_33 ( V_65 -> V_9 ) ;
if ( ! V_81 -> V_70 ) {
F_34 ( L_7 ) ;
goto V_85;
}
}
V_88 = V_81 -> V_70 ;
V_81 -> V_9 = V_65 -> V_9 ;
V_81 -> V_78 = ( void * ) V_88 ;
V_81 -> V_79 = ( void * ) ( V_88 + V_65 -> V_82 ) ;
return V_81 ;
V_85:
if ( V_81 )
F_35 ( V_81 ) ;
return NULL ;
}
void
F_25 ( struct V_66 * V_81 )
{
if ( V_81 ) {
if ( V_81 -> V_89 )
F_35 ( V_81 -> V_70 ) ;
F_35 ( V_81 ) ;
}
}
void
F_32 ( struct V_64 * V_81 )
{
if ( V_81 != NULL ) {
F_36 ( V_81 -> V_70 ) ;
F_35 ( V_81 ) ;
}
}
void F_37 (
const struct V_7 * V_90 , unsigned V_91 )
{
( void ) V_90 ;
( void ) V_91 ;
}
void F_38 (
const struct V_7 * V_90 , unsigned V_91 )
{
( void ) V_90 ;
( void ) V_91 ;
}
void F_39 (
const struct V_7 * V_90 , unsigned V_91 )
{
( void ) V_90 ;
( void ) V_91 ;
}
void F_40 (
const struct V_7 * V_90 , unsigned V_91 )
{
( void ) V_90 ;
( void ) V_91 ;
}
