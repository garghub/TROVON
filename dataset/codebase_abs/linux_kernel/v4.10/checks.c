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
struct V_9 * V_9 )
{
const char * V_40 = F_18 ( V_9 ) ;
struct V_12 * V_13 = F_10 ( V_9 , L_16 ) ;
if ( ! V_13 ) {
V_13 = F_10 ( V_9 , L_17 ) ;
if ( V_13 && ! V_13 -> V_31 . V_32 )
V_13 = NULL ;
}
if ( V_13 ) {
if ( ! V_40 [ 0 ] )
F_8 ( V_2 , L_18 ,
V_9 -> V_14 ) ;
} else {
if ( V_40 [ 0 ] )
F_8 ( V_2 , L_19 ,
V_9 -> V_14 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
int V_39 = strspn ( V_13 -> V_8 , V_2 -> V_30 ) ;
if ( V_39 < strlen ( V_13 -> V_8 ) )
F_8 ( V_2 , L_20 ,
V_13 -> V_8 [ V_39 ] , V_13 -> V_8 , V_9 -> V_14 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
const char * V_41 , struct V_9 * V_9 ,
struct V_12 * V_13 , struct V_42 * V_43 )
{
struct V_9 * V_44 = NULL ;
struct V_12 * V_45 = NULL ;
struct V_42 * V_46 = NULL ;
V_44 = F_22 ( V_10 , V_41 ) ;
if ( ! V_44 )
V_45 = F_23 ( V_10 , V_41 , & V_44 ) ;
if ( ! V_44 )
V_46 = F_24 ( V_10 , V_41 , & V_44 ,
& V_45 ) ;
if ( ! V_44 )
return;
if ( ( V_44 != V_9 ) || ( V_45 != V_13 ) || ( V_46 != V_43 ) )
F_8 ( V_2 , L_21 V_47
L_22 V_47 ,
V_41 , F_25 ( V_9 , V_13 , V_43 ) ,
F_25 ( V_44 , V_45 , V_46 ) ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_41 * V_48 ;
F_27 (node->labels, l)
F_21 ( V_2 , V_10 , V_48 -> V_41 , V_9 , NULL , NULL ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_42 * V_49 = V_13 -> V_31 . V_50 ;
struct V_41 * V_48 ;
F_27 (prop->labels, l)
F_21 ( V_2 , V_10 , V_48 -> V_41 , V_9 , V_13 , NULL ) ;
F_29 (m, LABEL)
F_21 ( V_2 , V_10 , V_49 -> V_51 , V_9 , V_13 , V_49 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_42 * V_49 ;
struct V_9 * V_52 ;
V_33 V_53 ;
if ( ! F_14 ( V_13 -> V_8 , L_23 )
&& ! F_14 ( V_13 -> V_8 , L_24 ) )
return;
if ( V_13 -> V_31 . V_32 != sizeof( V_33 ) ) {
F_8 ( V_2 , L_25 ,
V_9 -> V_14 , V_13 -> V_31 . V_32 , V_13 -> V_8 ) ;
return;
}
V_49 = V_13 -> V_31 . V_50 ;
F_29 (m, REF_PHANDLE) {
assert ( V_49 -> V_54 == 0 ) ;
if ( V_9 != F_31 ( V_28 , V_49 -> V_51 ) )
{
F_8 ( V_2 , L_26 ,
V_13 -> V_8 , V_9 -> V_14 ) ;
return;
}
return;
}
V_53 = F_32 ( V_13 ) ;
if ( ( V_53 == 0 ) || ( V_53 == - 1 ) ) {
F_8 ( V_2 , L_27 ,
V_9 -> V_14 , V_53 , V_13 -> V_8 ) ;
return;
}
if ( V_9 -> V_53 && ( V_9 -> V_53 != V_53 ) )
F_8 ( V_2 , L_28 ,
V_9 -> V_14 , V_13 -> V_8 ) ;
V_52 = F_33 ( V_28 , V_53 ) ;
if ( V_52 && ( V_52 != V_9 ) ) {
F_8 ( V_2 , L_29 ,
V_9 -> V_14 , V_53 , V_52 -> V_14 ) ;
return;
}
V_9 -> V_53 = V_53 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_9 * V_28 ,
struct V_9 * V_9 )
{
struct V_12 * * V_55 , * V_13 = NULL ;
for ( V_55 = & V_9 -> V_56 ; * V_55 ; V_55 = & ( ( * V_55 ) -> V_37 ) )
if ( F_14 ( ( * V_55 ) -> V_8 , L_30 ) ) {
V_13 = * V_55 ;
break;
}
if ( ! V_13 )
return;
if ( ( V_13 -> V_31 . V_32 != V_9 -> V_57 + 1 )
|| ( memcmp ( V_13 -> V_31 . V_31 , V_9 -> V_8 , V_9 -> V_57 ) != 0 ) ) {
F_8 ( V_2 , L_31
L_32 , V_9 -> V_14 , V_13 -> V_31 . V_31 ) ;
} else {
* V_55 = V_13 -> V_37 ;
free ( V_13 -> V_8 ) ;
F_35 ( V_13 -> V_31 ) ;
free ( V_13 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_42 * V_49 = V_13 -> V_31 . V_50 ;
struct V_9 * V_58 ;
V_33 V_53 ;
F_29 (m, REF_PHANDLE) {
assert ( V_49 -> V_54 + sizeof( V_33 ) <= V_13 -> V_31 . V_32 ) ;
V_58 = F_31 ( V_10 , V_49 -> V_51 ) ;
if ( ! V_58 ) {
F_8 ( V_2 , L_33 ,
V_49 -> V_51 ) ;
continue;
}
V_53 = F_37 ( V_10 , V_58 ) ;
* ( ( V_33 * ) ( V_13 -> V_31 . V_31 + V_49 -> V_54 ) ) = F_38 ( V_53 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 , struct V_12 * V_13 )
{
struct V_42 * V_49 = V_13 -> V_31 . V_50 ;
struct V_9 * V_58 ;
char * V_59 ;
F_29 (m, REF_PATH) {
assert ( V_49 -> V_54 <= V_13 -> V_31 . V_32 ) ;
V_58 = F_31 ( V_10 , V_49 -> V_51 ) ;
if ( ! V_58 ) {
F_8 ( V_2 , L_33 ,
V_49 -> V_51 ) ;
continue;
}
V_59 = V_58 -> V_14 ;
V_13 -> V_31 = F_40 ( V_13 -> V_31 , V_49 , V_59 ,
strlen ( V_59 ) + 1 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
V_9 -> V_60 = - 1 ;
V_9 -> V_61 = - 1 ;
V_13 = F_10 ( V_9 , L_34 ) ;
if ( V_13 )
V_9 -> V_60 = F_32 ( V_13 ) ;
V_13 = F_10 ( V_9 , L_35 ) ;
if ( V_13 )
V_9 -> V_61 = F_32 ( V_13 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
int V_60 , V_61 , V_62 ;
V_13 = F_10 ( V_9 , L_16 ) ;
if ( ! V_13 )
return;
if ( ! V_9 -> V_63 ) {
F_8 ( V_2 , L_36 ) ;
return;
}
if ( V_13 -> V_31 . V_32 == 0 )
F_8 ( V_2 , L_37 , V_9 -> V_14 ) ;
V_60 = F_43 ( V_9 -> V_63 ) ;
V_61 = F_44 ( V_9 -> V_63 ) ;
V_62 = ( V_60 + V_61 ) * sizeof( V_33 ) ;
if ( ! V_62 || ( V_13 -> V_31 . V_32 % V_62 ) != 0 )
F_8 ( V_2 , L_38
L_39 ,
V_9 -> V_14 , V_13 -> V_31 . V_32 , V_60 , V_61 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 ;
int V_64 , V_65 , V_66 , V_67 , V_62 ;
V_13 = F_10 ( V_9 , L_17 ) ;
if ( ! V_13 )
return;
if ( ! V_9 -> V_63 ) {
F_8 ( V_2 , L_40 ) ;
return;
}
V_65 = F_43 ( V_9 -> V_63 ) ;
V_67 = F_44 ( V_9 -> V_63 ) ;
V_64 = F_43 ( V_9 ) ;
V_66 = F_44 ( V_9 ) ;
V_62 = ( V_65 + V_64 + V_66 ) * sizeof( V_33 ) ;
if ( V_13 -> V_31 . V_32 == 0 ) {
if ( V_65 != V_64 )
F_8 ( V_2 , L_41
L_42 ,
V_9 -> V_14 , V_64 , V_9 -> V_63 -> V_14 ,
V_65 ) ;
if ( V_67 != V_66 )
F_8 ( V_2 , L_41
L_43 ,
V_9 -> V_14 , V_66 , V_9 -> V_63 -> V_14 ,
V_67 ) ;
} else if ( ( V_13 -> V_31 . V_32 % V_62 ) != 0 ) {
F_8 ( V_2 , L_44
L_45
L_46 , V_9 -> V_14 , V_13 -> V_31 . V_32 ,
V_65 , V_64 , V_66 ) ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_9 * V_9 )
{
struct V_12 * V_68 , * V_69 ;
if ( ! V_9 -> V_63 )
return;
V_68 = F_10 ( V_9 , L_16 ) ;
V_69 = F_10 ( V_9 , L_17 ) ;
if ( ! V_68 && ! V_69 )
return;
if ( V_9 -> V_63 -> V_60 == - 1 )
F_8 ( V_2 , L_47 ,
V_9 -> V_14 ) ;
if ( V_9 -> V_63 -> V_61 == - 1 )
F_8 ( V_2 , L_48 ,
V_9 -> V_14 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_9 * V_70 ;
struct V_12 * V_13 ;
V_70 = F_48 ( V_10 , L_49 ) ;
if ( ! V_70 )
return;
V_13 = F_10 ( V_70 , L_50 ) ;
if ( V_13 )
F_8 ( V_2 , L_51
L_52 ) ;
}
static void F_49 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_17 ;
if ( ( V_5 && ! V_2 -> V_5 ) || ( error && ! V_2 -> error ) )
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ )
F_49 ( V_2 -> V_24 [ V_17 ] , V_5 , error ) ;
V_2 -> V_5 = V_2 -> V_5 || V_5 ;
V_2 -> error = V_2 -> error || error ;
}
static void F_50 ( struct V_1 * V_2 , bool V_5 , bool error )
{
int V_17 ;
if ( ( V_5 && V_2 -> V_5 ) || ( error && V_2 -> error ) ) {
for ( V_17 = 0 ; V_17 < F_51 ( V_71 ) ; V_17 ++ ) {
struct V_1 * V_72 = V_71 [ V_17 ] ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 -> V_22 ; V_73 ++ )
if ( V_72 -> V_24 [ V_73 ] == V_2 )
F_50 ( V_72 , V_5 , error ) ;
}
}
V_2 -> V_5 = V_2 -> V_5 && ! V_5 ;
V_2 -> error = V_2 -> error && ! error ;
}
void F_52 ( bool V_5 , bool error , const char * V_74 )
{
int V_17 ;
const char * V_8 = V_74 ;
bool V_75 = true ;
if ( ( strncmp ( V_74 , L_53 , 3 ) == 0 )
|| ( strncmp ( V_74 , L_54 , 3 ) == 0 ) ) {
V_8 = V_74 + 3 ;
V_75 = false ;
}
for ( V_17 = 0 ; V_17 < F_51 ( V_71 ) ; V_17 ++ ) {
struct V_1 * V_2 = V_71 [ V_17 ] ;
if ( F_14 ( V_2 -> V_8 , V_8 ) ) {
if ( V_75 )
F_49 ( V_2 , V_5 , error ) ;
else
F_50 ( V_2 , V_5 , error ) ;
return;
}
}
F_53 ( L_55 , V_8 ) ;
}
void F_54 ( bool V_76 , struct V_77 * V_78 )
{
struct V_9 * V_10 = V_78 -> V_10 ;
int V_17 ;
int error = 0 ;
for ( V_17 = 0 ; V_17 < F_51 ( V_71 ) ; V_17 ++ ) {
struct V_1 * V_2 = V_71 [ V_17 ] ;
if ( V_2 -> V_5 || V_2 -> error )
error = error || F_6 ( V_2 , V_10 ) ;
}
if ( error ) {
if ( ! V_76 ) {
fprintf ( V_7 , L_56
L_57 ) ;
exit ( 2 ) ;
} else if ( V_6 < 3 ) {
fprintf ( V_7 , L_58
L_59 ) ;
}
}
}
