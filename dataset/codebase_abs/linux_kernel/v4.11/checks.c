static inline void F_1 ( struct V_1 * V_2 , const char * V_3 , ... )
{
T_1 V_4 ;
va_start ( V_4 , V_3 ) ;
if ( ( V_2 -> V_5 && ( V_6 < 1 ) )
|| ( V_2 -> error && ( V_6 < 2 ) ) ) {
fprintf ( V_7 , L_1 ,
( V_2 -> error ) ? L_2 : L_3 , V_2 -> V_8 ) ;
vfprintf ( V_7 , V_3 , V_4 ) ;
fprintf ( V_7 , L_4 ) ;
}
va_end ( V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_9 * V_10 , struct V_11 * V_11 )
{
struct V_11 * V_12 ;
F_3 ( V_2 , L_5 , V_11 -> V_13 ) ;
if ( V_2 -> V_14 )
V_2 -> V_14 ( V_2 , V_10 , V_11 ) ;
F_4 (node, child)
F_2 ( V_2 , V_10 , V_12 ) ;
}
static bool F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_15 = V_10 -> V_15 ;
bool error = false ;
int V_16 ;
assert ( ! V_2 -> V_17 ) ;
if ( V_2 -> V_18 != V_19 )
goto V_20;
V_2 -> V_17 = true ;
for ( V_16 = 0 ; V_16 < V_2 -> V_21 ; V_16 ++ ) {
struct V_1 * V_22 = V_2 -> V_23 [ V_16 ] ;
error = error || F_5 ( V_22 , V_10 ) ;
if ( V_22 -> V_18 != V_24 ) {
V_2 -> V_18 = V_25 ;
F_1 ( V_2 , L_6 ,
V_2 -> V_23 [ V_16 ] -> V_8 ) ;
}
}
if ( V_2 -> V_18 != V_19 )
goto V_20;
F_2 ( V_2 , V_10 , V_15 ) ;
if ( V_2 -> V_18 == V_19 )
V_2 -> V_18 = V_24 ;
F_3 ( V_2 , L_7 , V_2 -> V_18 ) ;
V_20:
V_2 -> V_17 = false ;
if ( ( V_2 -> V_18 != V_24 ) && ( V_2 -> error ) )
error = true ;
return error ;
}
static inline void F_6 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
F_7 ( V_2 , L_8 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
char * V_28 = V_2 -> V_29 ;
V_27 = F_9 ( V_11 , V_28 ) ;
if ( ! V_27 )
return;
if ( ! F_10 ( V_27 -> V_30 ) )
F_7 ( V_2 , L_9 ,
V_28 , V_11 -> V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
char * V_28 = V_2 -> V_29 ;
V_27 = F_9 ( V_11 , V_28 ) ;
if ( ! V_27 )
return;
if ( V_27 -> V_30 . V_31 != sizeof( V_32 ) )
F_7 ( V_2 , L_10 ,
V_28 , V_11 -> V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_11 * V_12 , * V_33 ;
F_4 (node, child)
for ( V_33 = V_12 -> V_34 ;
V_33 ;
V_33 = V_33 -> V_34 )
if ( F_13 ( V_12 -> V_8 , V_33 -> V_8 ) )
F_7 ( V_2 , L_11 ,
V_12 -> V_13 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 , * V_35 ;
F_15 (node, prop) {
for ( V_35 = V_27 -> V_36 ; V_35 ; V_35 = V_35 -> V_36 ) {
if ( V_35 -> V_37 )
continue;
if ( F_13 ( V_27 -> V_8 , V_35 -> V_8 ) )
F_7 ( V_2 , L_12 ,
V_27 -> V_8 , V_11 -> V_13 ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
int V_38 = strspn ( V_11 -> V_8 , V_2 -> V_29 ) ;
if ( V_38 < strlen ( V_11 -> V_8 ) )
F_7 ( V_2 , L_13 ,
V_11 -> V_8 [ V_38 ] , V_11 -> V_13 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
if ( strchr ( F_18 ( V_11 ) , '@' ) )
F_7 ( V_2 , L_14 ,
V_11 -> V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
const char * V_39 = F_18 ( V_11 ) ;
struct V_26 * V_27 = F_9 ( V_11 , L_15 ) ;
if ( ! V_27 ) {
V_27 = F_9 ( V_11 , L_16 ) ;
if ( V_27 && ! V_27 -> V_30 . V_31 )
V_27 = NULL ;
}
if ( V_27 ) {
if ( ! V_39 [ 0 ] )
F_7 ( V_2 , L_17 ,
V_11 -> V_13 ) ;
} else {
if ( V_39 [ 0 ] )
F_7 ( V_2 , L_18 ,
V_11 -> V_13 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
F_15 (node, prop) {
int V_38 = strspn ( V_27 -> V_8 , V_2 -> V_29 ) ;
if ( V_38 < strlen ( V_27 -> V_8 ) )
F_7 ( V_2 , L_19 ,
V_27 -> V_8 [ V_38 ] , V_27 -> V_8 , V_11 -> V_13 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
const char * V_40 , struct V_11 * V_11 ,
struct V_26 * V_27 , struct V_41 * V_42 )
{
struct V_11 * V_15 = V_10 -> V_15 ;
struct V_11 * V_43 = NULL ;
struct V_26 * V_44 = NULL ;
struct V_41 * V_45 = NULL ;
V_43 = F_22 ( V_15 , V_40 ) ;
if ( ! V_43 )
V_44 = F_23 ( V_15 , V_40 , & V_43 ) ;
if ( ! V_43 )
V_45 = F_24 ( V_15 , V_40 , & V_43 ,
& V_44 ) ;
if ( ! V_43 )
return;
if ( ( V_43 != V_11 ) || ( V_44 != V_27 ) || ( V_45 != V_42 ) )
F_7 ( V_2 , L_20 V_46
L_21 V_46 ,
V_40 , F_25 ( V_11 , V_27 , V_42 ) ,
F_25 ( V_43 , V_44 , V_45 ) ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_40 * V_47 ;
struct V_26 * V_27 ;
F_27 (node->labels, l)
F_21 ( V_2 , V_10 , V_47 -> V_40 , V_11 , NULL , NULL ) ;
F_15 (node, prop) {
struct V_41 * V_48 = V_27 -> V_30 . V_49 ;
F_27 (prop->labels, l)
F_21 ( V_2 , V_10 , V_47 -> V_40 , V_11 , V_27 , NULL ) ;
F_28 (m, LABEL)
F_21 ( V_2 , V_10 , V_48 -> V_50 , V_11 , V_27 , V_48 ) ;
}
}
static V_32 F_29 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 , const char * V_28 )
{
struct V_11 * V_51 = V_10 -> V_15 ;
struct V_26 * V_27 ;
struct V_41 * V_48 ;
V_32 V_52 ;
V_27 = F_9 ( V_11 , V_28 ) ;
if ( ! V_27 )
return 0 ;
if ( V_27 -> V_30 . V_31 != sizeof( V_32 ) ) {
F_7 ( V_2 , L_22 ,
V_11 -> V_13 , V_27 -> V_30 . V_31 , V_27 -> V_8 ) ;
return 0 ;
}
V_48 = V_27 -> V_30 . V_49 ;
F_28 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 == 0 ) ;
if ( V_11 != F_30 ( V_51 , V_48 -> V_50 ) )
{
F_7 ( V_2 , L_23 ,
V_27 -> V_8 , V_11 -> V_13 ) ;
}
return 0 ;
}
V_52 = F_31 ( V_27 ) ;
if ( ( V_52 == 0 ) || ( V_52 == - 1 ) ) {
F_7 ( V_2 , L_24 ,
V_11 -> V_13 , V_52 , V_27 -> V_8 ) ;
return 0 ;
}
return V_52 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_11 * V_51 = V_10 -> V_15 ;
struct V_11 * V_54 ;
V_32 V_52 , V_55 ;
assert ( ! V_11 -> V_52 ) ;
V_52 = F_29 ( V_2 , V_10 , V_11 , L_25 ) ;
V_55 = F_29 ( V_2 , V_10 , V_11 , L_26 ) ;
if ( ! V_52 && ! V_55 )
return;
if ( V_55 && V_52 && ( V_52 != V_55 ) )
F_7 ( V_2 , L_27
L_28 , V_11 -> V_13 ) ;
if ( V_55 && ! V_52 )
V_52 = V_55 ;
V_54 = F_33 ( V_51 , V_52 ) ;
if ( V_54 && ( V_54 != V_11 ) ) {
F_7 ( V_2 , L_29 ,
V_11 -> V_13 , V_52 , V_54 -> V_13 ) ;
return;
}
V_11 -> V_52 = V_52 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * * V_56 , * V_27 = NULL ;
for ( V_56 = & V_11 -> V_57 ; * V_56 ; V_56 = & ( ( * V_56 ) -> V_36 ) )
if ( F_13 ( ( * V_56 ) -> V_8 , L_30 ) ) {
V_27 = * V_56 ;
break;
}
if ( ! V_27 )
return;
if ( ( V_27 -> V_30 . V_31 != V_11 -> V_58 + 1 )
|| ( memcmp ( V_27 -> V_30 . V_30 , V_11 -> V_8 , V_11 -> V_58 ) != 0 ) ) {
F_7 ( V_2 , L_31
L_32 , V_11 -> V_13 , V_27 -> V_30 . V_30 ) ;
} else {
* V_56 = V_27 -> V_36 ;
free ( V_27 -> V_8 ) ;
F_35 ( V_27 -> V_30 ) ;
free ( V_27 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_11 * V_15 = V_10 -> V_15 ;
struct V_26 * V_27 ;
F_15 (node, prop) {
struct V_41 * V_48 = V_27 -> V_30 . V_49 ;
struct V_11 * V_59 ;
V_32 V_52 ;
F_28 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 + sizeof( V_32 ) <= V_27 -> V_30 . V_31 ) ;
V_59 = F_30 ( V_15 , V_48 -> V_50 ) ;
if ( ! V_59 ) {
if ( ! ( V_10 -> V_60 & V_61 ) )
F_7 ( V_2 , L_33
L_34 , V_48 -> V_50 ) ;
else
* ( ( V_32 * ) ( V_27 -> V_30 . V_30 + V_48 -> V_53 ) ) =
F_37 ( 0xffffffff ) ;
continue;
}
V_52 = F_38 ( V_15 , V_59 ) ;
* ( ( V_32 * ) ( V_27 -> V_30 . V_30 + V_48 -> V_53 ) ) = F_37 ( V_52 ) ;
}
}
}
static void F_39 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_11 * V_15 = V_10 -> V_15 ;
struct V_26 * V_27 ;
F_15 (node, prop) {
struct V_41 * V_48 = V_27 -> V_30 . V_49 ;
struct V_11 * V_59 ;
char * V_62 ;
F_28 (m, REF_PATH) {
assert ( V_48 -> V_53 <= V_27 -> V_30 . V_31 ) ;
V_59 = F_30 ( V_15 , V_48 -> V_50 ) ;
if ( ! V_59 ) {
F_7 ( V_2 , L_35 ,
V_48 -> V_50 ) ;
continue;
}
V_62 = V_59 -> V_13 ;
V_27 -> V_30 = F_40 ( V_27 -> V_30 , V_48 , V_62 ,
strlen ( V_62 ) + 1 ) ;
}
}
}
static void F_41 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
V_11 -> V_63 = - 1 ;
V_11 -> V_64 = - 1 ;
V_27 = F_9 ( V_11 , L_36 ) ;
if ( V_27 )
V_11 -> V_63 = F_31 ( V_27 ) ;
V_27 = F_9 ( V_11 , L_37 ) ;
if ( V_27 )
V_11 -> V_64 = F_31 ( V_27 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
int V_63 , V_64 , V_65 ;
V_27 = F_9 ( V_11 , L_15 ) ;
if ( ! V_27 )
return;
if ( ! V_11 -> V_66 ) {
F_7 ( V_2 , L_38 ) ;
return;
}
if ( V_27 -> V_30 . V_31 == 0 )
F_7 ( V_2 , L_39 , V_11 -> V_13 ) ;
V_63 = F_43 ( V_11 -> V_66 ) ;
V_64 = F_44 ( V_11 -> V_66 ) ;
V_65 = ( V_63 + V_64 ) * sizeof( V_32 ) ;
if ( ! V_65 || ( V_27 -> V_30 . V_31 % V_65 ) != 0 )
F_7 ( V_2 , L_40
L_41 ,
V_11 -> V_13 , V_27 -> V_30 . V_31 , V_63 , V_64 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_27 ;
int V_67 , V_68 , V_69 , V_70 , V_65 ;
V_27 = F_9 ( V_11 , L_16 ) ;
if ( ! V_27 )
return;
if ( ! V_11 -> V_66 ) {
F_7 ( V_2 , L_42 ) ;
return;
}
V_68 = F_43 ( V_11 -> V_66 ) ;
V_70 = F_44 ( V_11 -> V_66 ) ;
V_67 = F_43 ( V_11 ) ;
V_69 = F_44 ( V_11 ) ;
V_65 = ( V_68 + V_67 + V_69 ) * sizeof( V_32 ) ;
if ( V_27 -> V_30 . V_31 == 0 ) {
if ( V_68 != V_67 )
F_7 ( V_2 , L_43
L_44 ,
V_11 -> V_13 , V_67 , V_11 -> V_66 -> V_13 ,
V_68 ) ;
if ( V_70 != V_69 )
F_7 ( V_2 , L_43
L_45 ,
V_11 -> V_13 , V_69 , V_11 -> V_66 -> V_13 ,
V_70 ) ;
} else if ( ( V_27 -> V_30 . V_31 % V_65 ) != 0 ) {
F_7 ( V_2 , L_46
L_47
L_48 , V_11 -> V_13 , V_27 -> V_30 . V_31 ,
V_68 , V_67 , V_69 ) ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_26 * V_71 , * V_72 ;
if ( ! V_11 -> V_66 )
return;
V_71 = F_9 ( V_11 , L_15 ) ;
V_72 = F_9 ( V_11 , L_16 ) ;
if ( ! V_71 && ! V_72 )
return;
if ( V_11 -> V_66 -> V_63 == - 1 )
F_7 ( V_2 , L_49 ,
V_11 -> V_13 ) ;
if ( V_11 -> V_66 -> V_64 == - 1 )
F_7 ( V_2 , L_50 ,
V_11 -> V_13 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_11 )
{
struct V_11 * V_15 = V_10 -> V_15 ;
struct V_11 * V_73 ;
struct V_26 * V_27 ;
if ( V_11 != V_15 )
return;
V_73 = F_48 ( V_15 , L_51 ) ;
if ( ! V_73 )
return;
V_27 = F_9 ( V_73 , L_52 ) ;
if ( V_27 )
F_7 ( V_2 , L_53
L_54 ) ;
}
static void F_49 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_16 ;
if ( ( V_5 && ! V_2 -> V_5 ) || ( error && ! V_2 -> error ) )
for ( V_16 = 0 ; V_16 < V_2 -> V_21 ; V_16 ++ )
F_49 ( V_2 -> V_23 [ V_16 ] , V_5 , error ) ;
V_2 -> V_5 = V_2 -> V_5 || V_5 ;
V_2 -> error = V_2 -> error || error ;
}
static void F_50 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_16 ;
if ( ( V_5 && V_2 -> V_5 ) || ( error && V_2 -> error ) ) {
for ( V_16 = 0 ; V_16 < F_51 ( V_74 ) ; V_16 ++ ) {
struct V_1 * V_75 = V_74 [ V_16 ] ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_75 -> V_21 ; V_76 ++ )
if ( V_75 -> V_23 [ V_76 ] == V_2 )
F_50 ( V_75 , V_5 , error ) ;
}
}
V_2 -> V_5 = V_2 -> V_5 && ! V_5 ;
V_2 -> error = V_2 -> error && ! error ;
}
void F_52 ( bool V_5 , bool error , const char * V_77 )
{
int V_16 ;
const char * V_8 = V_77 ;
bool V_78 = true ;
if ( ( strncmp ( V_77 , L_55 , 3 ) == 0 )
|| ( strncmp ( V_77 , L_56 , 3 ) == 0 ) ) {
V_8 = V_77 + 3 ;
V_78 = false ;
}
for ( V_16 = 0 ; V_16 < F_51 ( V_74 ) ; V_16 ++ ) {
struct V_1 * V_2 = V_74 [ V_16 ] ;
if ( F_13 ( V_2 -> V_8 , V_8 ) ) {
if ( V_78 )
F_49 ( V_2 , V_5 , error ) ;
else
F_50 ( V_2 , V_5 , error ) ;
return;
}
}
F_53 ( L_57 , V_8 ) ;
}
void F_54 ( bool V_79 , struct V_9 * V_10 )
{
int V_16 ;
int error = 0 ;
for ( V_16 = 0 ; V_16 < F_51 ( V_74 ) ; V_16 ++ ) {
struct V_1 * V_2 = V_74 [ V_16 ] ;
if ( V_2 -> V_5 || V_2 -> error )
error = error || F_5 ( V_2 , V_10 ) ;
}
if ( error ) {
if ( ! V_79 ) {
fprintf ( V_7 , L_58
L_59 ) ;
exit ( 2 ) ;
} else if ( V_6 < 3 ) {
fprintf ( V_7 , L_60
L_61 ) ;
}
}
}
