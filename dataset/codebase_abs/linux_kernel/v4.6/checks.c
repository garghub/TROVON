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
static void F_2 ( struct V_1 * V_2 , struct V_9 * V_10 , struct V_9 * V_9 )
{
struct V_9 * V_11 ;
struct V_12 * V_13 ;
F_3 ( V_2 , L_5 , V_9 -> V_14 ) ;
if ( V_2 -> V_15 )
V_2 -> V_15 ( V_2 , V_10 , V_9 ) ;
if ( V_2 -> V_16 )
F_4 (node, prop) {
F_3 ( V_2 , L_6 , V_9 -> V_14 , V_13 -> V_8 ) ;
V_2 -> V_16 ( V_2 , V_10 , V_9 , V_13 ) ;
}
F_5 (node, child)
F_2 ( V_2 , V_10 , V_11 ) ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
bool error = false ;
int V_17 ;
assert ( ! V_2 -> V_18 ) ;
if ( V_2 -> V_19 != V_20 )
goto V_21;
V_2 -> V_18 = true ;
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
struct V_1 * V_23 = V_2 -> V_24 [ V_17 ] ;
error = error || F_6 ( V_23 , V_10 ) ;
if ( V_23 -> V_19 != V_25 ) {
V_2 -> V_19 = V_26 ;
F_1 ( V_2 , L_7 ,
V_2 -> V_24 [ V_17 ] -> V_8 ) ;
}
}
if ( V_2 -> V_19 != V_20 )
goto V_21;
if ( V_2 -> V_15 || V_2 -> V_16 )
F_2 ( V_2 , V_10 , V_10 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 , V_10 ) ;
if ( V_2 -> V_19 == V_20 )
V_2 -> V_19 = V_25 ;
F_3 ( V_2 , L_8 , V_2 -> V_19 ) ;
V_21:
V_2 -> V_18 = false ;
if ( ( V_2 -> V_19 != V_25 ) && ( V_2 -> error ) )
error = true ;
return error ;
}
static inline void F_7 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_8 ( V_2 , L_9 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
char * V_29 = V_2 -> V_30 ;
V_13 = F_10 ( V_9 , V_29 ) ;
if ( ! V_13 )
return;
if ( ! F_11 ( V_13 -> V_31 ) )
F_8 ( V_2 , L_10 ,
V_29 , V_9 -> V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
char * V_29 = V_2 -> V_30 ;
V_13 = F_10 ( V_9 , V_29 ) ;
if ( ! V_13 )
return;
if ( V_13 -> V_31 . V_32 != sizeof( V_33 ) )
F_8 ( V_2 , L_11 ,
V_29 , V_9 -> V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_9 * V_11 , * V_34 ;
F_5 (node, child)
for ( V_34 = V_11 -> V_35 ;
V_34 ;
V_34 = V_34 -> V_35 )
if ( F_14 ( V_11 -> V_8 , V_34 -> V_8 ) )
F_8 ( V_2 , L_12 ,
V_11 -> V_14 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 , * V_36 ;
F_4 (node, prop) {
for ( V_36 = V_13 -> V_37 ; V_36 ; V_36 = V_36 -> V_37 ) {
if ( V_36 -> V_38 )
continue;
if ( F_14 ( V_13 -> V_8 , V_36 -> V_8 ) )
F_8 ( V_2 , L_13 ,
V_13 -> V_8 , V_9 -> V_14 ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
int V_39 = strspn ( V_9 -> V_8 , V_2 -> V_30 ) ;
if ( V_39 < strlen ( V_9 -> V_8 ) )
F_8 ( V_2 , L_14 ,
V_9 -> V_8 [ V_39 ] , V_9 -> V_14 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
if ( strchr ( F_18 ( V_9 ) , '@' ) )
F_8 ( V_2 , L_15 ,
V_9 -> V_14 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
int V_39 = strspn ( V_13 -> V_8 , V_2 -> V_30 ) ;
if ( V_39 < strlen ( V_13 -> V_8 ) )
F_8 ( V_2 , L_16 ,
V_13 -> V_8 [ V_39 ] , V_13 -> V_8 , V_9 -> V_14 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_9 * V_10 ,
const char * V_40 , struct V_9 * V_9 ,
struct V_12 * V_13 , struct V_41 * V_42 )
{
struct V_9 * V_43 = NULL ;
struct V_12 * V_44 = NULL ;
struct V_41 * V_45 = NULL ;
V_43 = F_21 ( V_10 , V_40 ) ;
if ( ! V_43 )
V_44 = F_22 ( V_10 , V_40 , & V_43 ) ;
if ( ! V_43 )
V_45 = F_23 ( V_10 , V_40 , & V_43 ,
& V_44 ) ;
if ( ! V_43 )
return;
if ( ( V_43 != V_9 ) || ( V_44 != V_13 ) || ( V_45 != V_42 ) )
F_8 ( V_2 , L_17 V_46
L_18 V_46 ,
V_40 , F_24 ( V_9 , V_13 , V_42 ) ,
F_24 ( V_43 , V_44 , V_45 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_40 * V_47 ;
F_26 (node->labels, l)
F_20 ( V_2 , V_10 , V_47 -> V_40 , V_9 , NULL , NULL ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_41 * V_48 = V_13 -> V_31 . V_49 ;
struct V_40 * V_47 ;
F_26 (prop->labels, l)
F_20 ( V_2 , V_10 , V_47 -> V_40 , V_9 , V_13 , NULL ) ;
F_28 (m, LABEL)
F_20 ( V_2 , V_10 , V_48 -> V_50 , V_9 , V_13 , V_48 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_41 * V_48 ;
struct V_9 * V_51 ;
V_33 V_52 ;
if ( ! F_14 ( V_13 -> V_8 , L_19 )
&& ! F_14 ( V_13 -> V_8 , L_20 ) )
return;
if ( V_13 -> V_31 . V_32 != sizeof( V_33 ) ) {
F_8 ( V_2 , L_21 ,
V_9 -> V_14 , V_13 -> V_31 . V_32 , V_13 -> V_8 ) ;
return;
}
V_48 = V_13 -> V_31 . V_49 ;
F_28 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 == 0 ) ;
if ( V_9 != F_30 ( V_28 , V_48 -> V_50 ) )
{
F_8 ( V_2 , L_22 ,
V_13 -> V_8 , V_9 -> V_14 ) ;
return;
}
return;
}
V_52 = F_31 ( V_13 ) ;
if ( ( V_52 == 0 ) || ( V_52 == - 1 ) ) {
F_8 ( V_2 , L_23 ,
V_9 -> V_14 , V_52 , V_13 -> V_8 ) ;
return;
}
if ( V_9 -> V_52 && ( V_9 -> V_52 != V_52 ) )
F_8 ( V_2 , L_24 ,
V_9 -> V_14 , V_13 -> V_8 ) ;
V_51 = F_32 ( V_28 , V_52 ) ;
if ( V_51 && ( V_51 != V_9 ) ) {
F_8 ( V_2 , L_25 ,
V_9 -> V_14 , V_52 , V_51 -> V_14 ) ;
return;
}
V_9 -> V_52 = V_52 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 )
{
struct V_12 * * V_54 , * V_13 = NULL ;
for ( V_54 = & V_9 -> V_55 ; * V_54 ; V_54 = & ( ( * V_54 ) -> V_37 ) )
if ( F_14 ( ( * V_54 ) -> V_8 , L_26 ) ) {
V_13 = * V_54 ;
break;
}
if ( ! V_13 )
return;
if ( ( V_13 -> V_31 . V_32 != V_9 -> V_56 + 1 )
|| ( memcmp ( V_13 -> V_31 . V_31 , V_9 -> V_8 , V_9 -> V_56 ) != 0 ) ) {
F_8 ( V_2 , L_27
L_28 , V_9 -> V_14 , V_13 -> V_31 . V_31 ) ;
} else {
* V_54 = V_13 -> V_37 ;
free ( V_13 -> V_8 ) ;
F_34 ( V_13 -> V_31 ) ;
free ( V_13 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_41 * V_48 = V_13 -> V_31 . V_49 ;
struct V_9 * V_57 ;
V_33 V_52 ;
F_28 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 + sizeof( V_33 ) <= V_13 -> V_31 . V_32 ) ;
V_57 = F_30 ( V_10 , V_48 -> V_50 ) ;
if ( ! V_57 ) {
F_8 ( V_2 , L_29 ,
V_48 -> V_50 ) ;
continue;
}
V_52 = F_36 ( V_10 , V_57 ) ;
* ( ( V_33 * ) ( V_13 -> V_31 . V_31 + V_48 -> V_53 ) ) = F_37 ( V_52 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_41 * V_48 = V_13 -> V_31 . V_49 ;
struct V_9 * V_57 ;
char * V_58 ;
F_28 (m, REF_PATH) {
assert ( V_48 -> V_53 <= V_13 -> V_31 . V_32 ) ;
V_57 = F_30 ( V_10 , V_48 -> V_50 ) ;
if ( ! V_57 ) {
F_8 ( V_2 , L_29 ,
V_48 -> V_50 ) ;
continue;
}
V_58 = V_57 -> V_14 ;
V_13 -> V_31 = F_39 ( V_13 -> V_31 , V_48 , V_58 ,
strlen ( V_58 ) + 1 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
V_9 -> V_59 = - 1 ;
V_9 -> V_60 = - 1 ;
V_13 = F_10 ( V_9 , L_30 ) ;
if ( V_13 )
V_9 -> V_59 = F_31 ( V_13 ) ;
V_13 = F_10 ( V_9 , L_31 ) ;
if ( V_13 )
V_9 -> V_60 = F_31 ( V_13 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
int V_59 , V_60 , V_61 ;
V_13 = F_10 ( V_9 , L_32 ) ;
if ( ! V_13 )
return;
if ( ! V_9 -> V_62 ) {
F_8 ( V_2 , L_33 ) ;
return;
}
if ( V_13 -> V_31 . V_32 == 0 )
F_8 ( V_2 , L_34 , V_9 -> V_14 ) ;
V_59 = F_42 ( V_9 -> V_62 ) ;
V_60 = F_43 ( V_9 -> V_62 ) ;
V_61 = ( V_59 + V_60 ) * sizeof( V_33 ) ;
if ( ! V_61 || ( V_13 -> V_31 . V_32 % V_61 ) != 0 )
F_8 ( V_2 , L_35
L_36 ,
V_9 -> V_14 , V_13 -> V_31 . V_32 , V_59 , V_60 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
int V_63 , V_64 , V_65 , V_66 , V_61 ;
V_13 = F_10 ( V_9 , L_37 ) ;
if ( ! V_13 )
return;
if ( ! V_9 -> V_62 ) {
F_8 ( V_2 , L_38 ) ;
return;
}
V_64 = F_42 ( V_9 -> V_62 ) ;
V_66 = F_43 ( V_9 -> V_62 ) ;
V_63 = F_42 ( V_9 ) ;
V_65 = F_43 ( V_9 ) ;
V_61 = ( V_64 + V_63 + V_65 ) * sizeof( V_33 ) ;
if ( V_13 -> V_31 . V_32 == 0 ) {
if ( V_64 != V_63 )
F_8 ( V_2 , L_39
L_40 ,
V_9 -> V_14 , V_63 , V_9 -> V_62 -> V_14 ,
V_64 ) ;
if ( V_66 != V_65 )
F_8 ( V_2 , L_39
L_41 ,
V_9 -> V_14 , V_65 , V_9 -> V_62 -> V_14 ,
V_66 ) ;
} else if ( ( V_13 -> V_31 . V_32 % V_61 ) != 0 ) {
F_8 ( V_2 , L_42
L_43
L_44 , V_9 -> V_14 , V_13 -> V_31 . V_32 ,
V_64 , V_63 , V_65 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_67 , * V_68 ;
if ( ! V_9 -> V_62 )
return;
V_67 = F_10 ( V_9 , L_32 ) ;
V_68 = F_10 ( V_9 , L_37 ) ;
if ( ! V_67 && ! V_68 )
return;
if ( V_9 -> V_62 -> V_59 == - 1 )
F_8 ( V_2 , L_45 ,
V_9 -> V_14 ) ;
if ( V_9 -> V_62 -> V_60 == - 1 )
F_8 ( V_2 , L_46 ,
V_9 -> V_14 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_9 * V_69 ;
struct V_12 * V_13 ;
V_69 = F_47 ( V_10 , L_47 ) ;
if ( ! V_69 )
return;
V_13 = F_10 ( V_69 , L_48 ) ;
if ( V_13 )
F_8 ( V_2 , L_49
L_50 ) ;
}
static void F_48 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_17 ;
if ( ( V_5 && ! V_2 -> V_5 ) || ( error && ! V_2 -> error ) )
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ )
F_48 ( V_2 -> V_24 [ V_17 ] , V_5 , error ) ;
V_2 -> V_5 = V_2 -> V_5 || V_5 ;
V_2 -> error = V_2 -> error || error ;
}
static void F_49 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_17 ;
if ( ( V_5 && V_2 -> V_5 ) || ( error && V_2 -> error ) ) {
for ( V_17 = 0 ; V_17 < F_50 ( V_70 ) ; V_17 ++ ) {
struct V_1 * V_71 = V_70 [ V_17 ] ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 -> V_22 ; V_72 ++ )
if ( V_71 -> V_24 [ V_72 ] == V_2 )
F_49 ( V_71 , V_5 , error ) ;
}
}
V_2 -> V_5 = V_2 -> V_5 && ! V_5 ;
V_2 -> error = V_2 -> error && ! error ;
}
void F_51 ( bool V_5 , bool error , const char * V_73 )
{
int V_17 ;
const char * V_8 = V_73 ;
bool V_74 = true ;
if ( ( strncmp ( V_73 , L_51 , 3 ) == 0 )
|| ( strncmp ( V_73 , L_52 , 3 ) == 0 ) ) {
V_8 = V_73 + 3 ;
V_74 = false ;
}
for ( V_17 = 0 ; V_17 < F_50 ( V_70 ) ; V_17 ++ ) {
struct V_1 * V_2 = V_70 [ V_17 ] ;
if ( F_14 ( V_2 -> V_8 , V_8 ) ) {
if ( V_74 )
F_48 ( V_2 , V_5 , error ) ;
else
F_49 ( V_2 , V_5 , error ) ;
return;
}
}
F_52 ( L_53 , V_8 ) ;
}
void F_53 ( bool V_75 , struct V_76 * V_77 )
{
struct V_9 * V_10 = V_77 -> V_10 ;
int V_17 ;
int error = 0 ;
for ( V_17 = 0 ; V_17 < F_50 ( V_70 ) ; V_17 ++ ) {
struct V_1 * V_2 = V_70 [ V_17 ] ;
if ( V_2 -> V_5 || V_2 -> error )
error = error || F_6 ( V_2 , V_10 ) ;
}
if ( error ) {
if ( ! V_75 ) {
fprintf ( V_7 , L_54
L_55 ) ;
exit ( 2 ) ;
} else if ( V_6 < 3 ) {
fprintf ( V_7 , L_56
L_57 ) ;
}
}
}
