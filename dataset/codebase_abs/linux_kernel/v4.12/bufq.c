void F_1 ( void )
{
unsigned int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
V_5 [ V_1 ] [ V_2 ] = true ;
}
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ )
V_7 [ V_1 ] [ V_2 ] = V_8 ;
}
}
void F_2 (
unsigned int V_9 ,
enum V_10 V_11 ,
bool V_12 )
{
assert ( V_11 < V_6 ) ;
assert ( V_9 < V_3 ) ;
F_3 ( V_13 ,
L_1 , V_11 , V_9 ) ;
if ( V_12 )
F_4 ( V_9 , V_11 ) ;
else
F_5 ( V_9 , V_11 ) ;
}
bool F_6 (
enum V_10 V_11 ,
unsigned int V_9 ,
enum V_14 * V_15 )
{
F_7 ( L_2 , V_11 , V_9 , V_15 ) ;
if ( ( V_15 == NULL ) || ( V_9 >= V_3 ) || ( V_11 >= V_6 ) ) {
F_8 ( L_3 ) ;
return false ;
}
* V_15 = V_7 [ V_9 ] [ V_11 ] ;
if ( ( * V_15 == V_8 ) || ( * V_15 >= V_4 ) ) {
F_9 ( L_4 , * V_15 ) ;
F_8 ( L_3 ) ;
return false ;
}
F_8 ( L_5 ) ;
return true ;
}
static void F_4 (
unsigned int V_9 ,
enum V_10 V_11 )
{
unsigned int V_1 ;
assert ( V_9 < V_3 ) ;
assert ( V_11 < V_6 ) ;
assert ( V_7 [ V_9 ] [ V_11 ] == V_8 ) ;
if ( V_11 == V_16 ) {
assert ( V_5 [ V_9 ] [ V_17 ] ) ;
V_5 [ V_9 ] [ V_17 ] = false ;
V_7 [ V_9 ] [ V_11 ] = V_17 ;
return;
}
if ( V_11 == V_18 ) {
assert ( V_5 [ V_9 ] [ V_19 ] ) ;
V_5 [ V_9 ] [ V_19 ] = false ;
V_7 [ V_9 ] [ V_11 ] = V_19 ;
return;
}
for ( V_1 = V_20 ; V_1 < V_4 ; V_1 ++ ) {
if ( V_5 [ V_9 ] [ V_1 ] == true ) {
V_5 [ V_9 ] [ V_1 ] = false ;
V_7 [ V_9 ] [ V_11 ] = V_1 ;
break;
}
}
assert ( V_1 != V_4 ) ;
return;
}
static void F_5 (
unsigned int V_9 ,
enum V_10 V_11 )
{
int V_21 ;
assert ( V_9 < V_3 ) ;
assert ( V_11 < V_6 ) ;
assert ( V_7 [ V_9 ] [ V_11 ] != V_8 ) ;
V_21 = V_7 [ V_9 ] [ V_11 ] ;
V_7 [ V_9 ] [ V_11 ] = V_8 ;
V_5 [ V_9 ] [ V_21 ] = true ;
}
static T_1 * F_10 (
enum V_22 type ,
enum V_14 V_23 ,
int V_24 )
{
T_1 * V_25 = 0 ;
switch ( type ) {
case V_26 :
if ( ( V_24 >= V_3 ) || ( V_24 < 0 ) ||
( V_23 == V_8 ) )
break;
V_25 = & V_27 . V_28 [ V_24 ] [ V_23 ] ;
break;
case V_29 :
if ( V_23 == V_8 )
break;
V_25 = & V_27 . V_30 [ V_23 ] ;
break;
case V_31 :
V_25 = & V_27 . V_32 ;
break;
case V_33 :
V_25 = & V_27 . V_34 ;
break;
#if ! F_11 ( V_35 )
case V_36 :
V_25 = & V_27 . V_37 ;
break;
case V_38 :
V_25 = & V_27 . V_39 ;
break;
#endif
case V_40 :
V_25 = & V_27 . V_41 ;
break;
default:
break;
}
return V_25 ;
}
T_2 void
F_12 ( unsigned int V_42 ,
unsigned int V_43 ,
T_1 * V_44 )
{
const struct V_45 * V_46 ;
unsigned int V_47 ;
T_3 V_48 ;
V_46 = & V_49 ;
V_47 = V_46 -> V_50 . V_51 . V_52 ;
V_48 . V_53 = V_54 ;
V_48 . V_55 = V_56 ;
V_48 . V_57 = V_47 + V_42 ;
V_48 . V_58 = V_47 + V_43 ;
F_13 ( V_44 , & V_48 ) ;
}
void F_14 ( void )
{
int V_1 , V_2 ;
F_15 ( L_6 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_61 [ V_1 ] [ V_2 ] ) ,
( V_59 ) F_16 ( struct V_60 , V_62 [ V_1 ] [ V_2 ] ) ,
& V_27 . V_28 [ V_1 ] [ V_2 ] ) ;
}
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
F_12 ( F_16 ( struct V_60 , V_63 [ V_1 ] ) ,
F_16 ( struct V_60 , V_64 [ V_1 ] ) ,
& V_27 . V_30 [ V_1 ] ) ;
}
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_65 ) ,
( V_59 ) F_16 ( struct V_60 , V_66 ) ,
& V_27 . V_32 ) ;
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_67 ) ,
( V_59 ) F_16 ( struct V_60 , V_68 ) ,
& V_27 . V_34 ) ;
#if ! F_11 ( V_35 )
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_69 ) ,
( V_59 ) F_16 ( struct V_60 , V_70 ) ,
& V_27 . V_37 ) ;
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_71 ) ,
( V_59 ) F_16 ( struct V_60 , V_72 ) ,
& V_27 . V_39 ) ;
F_12 ( ( V_59 ) F_16 ( struct V_60 , V_73 ) ,
( V_59 ) F_16 ( struct V_60 , V_74 ) ,
& V_27 . V_41 ) ;
#endif
F_17 ( L_6 ) ;
}
enum V_75 F_18 (
int V_76 ,
int V_21 ,
V_59 V_77 )
{
enum V_75 V_78 = V_79 ;
T_1 * V_25 ;
int error ;
F_15 ( L_7 , V_21 ) ;
if ( ( V_76 >= V_3 ) || ( V_76 < 0 ) ||
( V_21 == V_8 ) )
return V_80 ;
V_25 = F_10 ( V_26 ,
V_21 ,
V_76 ) ;
if ( V_25 != NULL ) {
error = F_19 ( V_25 , V_77 ) ;
V_78 = F_20 ( error ) ;
} else {
F_21 ( L_8 ) ;
V_78 = V_81 ;
}
F_22 ( V_78 ) ;
return V_78 ;
}
enum V_75 F_23 (
int V_21 ,
V_59 * V_77 )
{
enum V_75 V_78 ;
int error = 0 ;
T_1 * V_25 ;
F_15 ( L_7 , V_21 ) ;
if ( ( V_77 == NULL ) ||
( V_21 <= V_8 ) ||
( V_21 >= V_4 )
)
return V_80 ;
V_25 = F_10 ( V_29 ,
V_21 ,
- 1 ) ;
if ( V_25 != NULL ) {
error = F_24 ( V_25 , V_77 ) ;
V_78 = F_20 ( error ) ;
} else {
F_21 ( L_8 ) ;
V_78 = V_81 ;
}
F_22 ( V_78 ) ;
return V_78 ;
}
enum V_75 F_25 (
T_4 V_82 ,
T_4 V_83 ,
T_4 V_84 ,
T_4 V_85 )
{
enum V_75 V_78 ;
int error = 0 ;
T_1 * V_25 ;
F_15 ( L_9 , V_82 ) ;
V_25 = F_10 ( V_31 , - 1 , - 1 ) ;
if ( NULL == V_25 ) {
F_21 ( L_8 ) ;
return V_81 ;
}
error = F_26 ( V_25 ,
V_82 , V_83 , V_84 , V_85 ) ;
V_78 = F_20 ( error ) ;
F_22 ( V_78 ) ;
return V_78 ;
}
enum V_75 F_27 (
T_4 V_77 [ V_86 ] )
{
enum V_75;
int error = 0 ;
T_1 * V_25 ;
if ( V_77 == NULL )
return V_80 ;
V_25 = F_10 ( V_33 , - 1 , - 1 ) ;
if ( NULL == V_25 ) {
F_21 ( L_8 ) ;
return V_81 ;
}
error = F_28 ( V_25 , V_77 ) ;
return F_20 ( error ) ;
}
enum V_75 F_29 (
T_4 V_77 [ V_86 ] )
{
#if ! F_11 ( V_35 )
enum V_75;
int error = 0 ;
T_1 * V_25 ;
if ( V_77 == NULL )
return V_80 ;
V_25 = F_10 ( V_38 , - 1 , - 1 ) ;
if ( V_25 == NULL ) {
F_21 ( L_8 ) ;
return V_81 ;
}
error = F_28 ( V_25 , V_77 ) ;
return F_20 ( error ) ;
#else
( void ) V_77 ;
return V_81 ;
#endif
}
enum V_75 F_30 ( T_4 V_82 )
{
#if ! F_11 ( V_35 )
enum V_75 V_78 ;
int error = 0 ;
T_1 * V_25 ;
F_15 ( L_10 , V_82 ) ;
V_25 = F_10 ( V_36 , - 1 , - 1 ) ;
if ( V_25 == NULL ) {
F_21 ( L_8 ) ;
return V_81 ;
}
error = F_26 ( V_25 , V_82 , 0 , 0 , 0 ) ;
V_78 = F_20 ( error ) ;
F_22 ( V_78 ) ;
return V_78 ;
#else
( void ) V_82 ;
return V_81 ;
#endif
}
enum V_75 F_31 (
V_59 V_77 )
{
#if ! F_11 ( V_35 )
enum V_75 V_78 ;
int error = 0 ;
T_1 * V_25 ;
F_15 ( L_11 , V_77 ) ;
V_25 = F_10 ( V_40 , - 1 , - 1 ) ;
if ( NULL == V_25 ) {
F_21 ( L_8 ) ;
return V_81 ;
}
error = F_19 ( V_25 , V_77 ) ;
V_78 = F_20 ( error ) ;
F_22 ( V_78 ) ;
return V_78 ;
#else
( void ) V_77 ;
return V_81 ;
#endif
}
enum V_75 F_32 ( void )
{
return V_79 ;
}
static void F_33 ( const char * V_87 , T_1 * V_88 )
{
V_59 free = 0 , V_89 = 0 ;
assert ( V_87 != NULL && V_88 != NULL ) ;
F_34 ( V_88 , & V_89 ) ;
F_35 ( V_88 , & free ) ;
F_3 ( V_13 , L_12 ,
V_87 , V_89 , free ) ;
}
void F_36 ( void )
{
int V_1 , V_2 ;
F_3 ( V_13 , L_13 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
snprintf ( V_87 , V_90 ,
L_14 , V_1 , V_2 ) ;
F_33 ( V_87 ,
& V_27 . V_28 [ V_1 ] [ V_2 ] ) ;
}
}
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
snprintf ( V_87 , V_90 ,
L_15 , V_1 ) ;
F_33 ( V_87 ,
& V_27 . V_30 [ V_1 ] ) ;
}
F_33 ( L_16 ,
& V_27 . V_32 ) ;
F_33 ( L_17 ,
& V_27 . V_34 ) ;
#if ! F_11 ( V_35 )
F_33 ( L_18 ,
& V_27 . V_37 ) ;
F_33 ( L_19 ,
& V_27 . V_39 ) ;
F_33 ( L_20 ,
& V_27 . V_41 ) ;
#endif
}
