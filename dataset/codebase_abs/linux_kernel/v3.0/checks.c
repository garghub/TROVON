static inline void F_1 ( struct V_1 * V_2 , const char * V_3 , ... )
{
T_1 V_4 ;
va_start ( V_4 , V_3 ) ;
if ( ( V_2 -> V_5 < V_6 ) || ( V_2 -> V_5 <= V_7 ) )
return;
fprintf ( V_8 , L_1 ,
( V_2 -> V_5 == ERROR ) ? L_2 : L_3 , V_2 -> V_9 ) ;
vfprintf ( V_8 , V_3 , V_4 ) ;
fprintf ( V_8 , L_4 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_10 * V_11 , struct V_10 * V_10 )
{
struct V_10 * V_12 ;
struct V_13 * V_14 ;
F_3 ( V_2 , L_5 , V_10 -> V_15 ) ;
if ( V_2 -> V_16 )
V_2 -> V_16 ( V_2 , V_11 , V_10 ) ;
if ( V_2 -> V_17 )
F_4 (node, prop) {
F_3 ( V_2 , L_6 , V_10 -> V_15 , V_14 -> V_9 ) ;
V_2 -> V_17 ( V_2 , V_11 , V_10 , V_14 ) ;
}
F_5 (node, child)
F_2 ( V_2 , V_11 , V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int error = 0 ;
int V_18 ;
assert ( ! V_2 -> V_19 ) ;
if ( V_2 -> V_20 != V_21 )
goto V_22;
V_2 -> V_19 = 1 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_23 ; V_18 ++ ) {
struct V_1 * V_24 = V_2 -> V_25 [ V_18 ] ;
error |= F_6 ( V_24 , V_11 ) ;
if ( V_24 -> V_20 != V_26 ) {
V_2 -> V_20 = V_27 ;
F_1 ( V_2 , L_7 ,
V_2 -> V_25 [ V_18 ] -> V_9 ) ;
}
}
if ( V_2 -> V_20 != V_21 )
goto V_22;
if ( V_2 -> V_16 || V_2 -> V_17 )
F_2 ( V_2 , V_11 , V_11 ) ;
if ( V_2 -> V_28 )
V_2 -> V_28 ( V_2 , V_11 ) ;
if ( V_2 -> V_20 == V_21 )
V_2 -> V_20 = V_26 ;
F_3 ( V_2 , L_8 , V_2 -> V_20 ) ;
V_22:
V_2 -> V_19 = 0 ;
if ( ( V_2 -> V_20 != V_26 ) && ( V_2 -> V_5 == ERROR ) )
error = 1 ;
return error ;
}
static void F_7 ( struct V_1 * V_2 , struct V_10 * V_29 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 ;
char * V_30 = V_2 -> V_31 ;
V_14 = F_8 ( V_10 , V_30 ) ;
if ( ! V_14 )
return;
if ( ! F_9 ( V_14 -> V_32 ) )
F_10 ( V_2 , L_9 ,
V_30 , V_10 -> V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_10 * V_29 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 ;
char * V_30 = V_2 -> V_31 ;
V_14 = F_8 ( V_10 , V_30 ) ;
if ( ! V_14 )
return;
if ( V_14 -> V_32 . V_33 != sizeof( V_34 ) )
F_10 ( V_2 , L_10 ,
V_30 , V_10 -> V_15 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_10 * V_12 , * V_35 ;
F_5 (node, child)
for ( V_35 = V_12 -> V_36 ;
V_35 ;
V_35 = V_35 -> V_36 )
if ( F_13 ( V_12 -> V_9 , V_35 -> V_9 ) )
F_10 ( V_2 , L_11 ,
V_12 -> V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 , * V_37 ;
F_4 (node, prop)
for ( V_37 = V_14 -> V_38 ; V_37 ; V_37 = V_37 -> V_38 )
if ( F_13 ( V_14 -> V_9 , V_37 -> V_9 ) )
F_10 ( V_2 , L_12 ,
V_14 -> V_9 , V_10 -> V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
int V_39 = strspn ( V_10 -> V_9 , V_2 -> V_31 ) ;
if ( V_39 < strlen ( V_10 -> V_9 ) )
F_10 ( V_2 , L_13 ,
V_10 -> V_9 [ V_39 ] , V_10 -> V_15 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
if ( strchr ( F_17 ( V_10 ) , '@' ) )
F_10 ( V_2 , L_14 ,
V_10 -> V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 , struct V_13 * V_14 )
{
int V_39 = strspn ( V_14 -> V_9 , V_2 -> V_31 ) ;
if ( V_39 < strlen ( V_14 -> V_9 ) )
F_10 ( V_2 , L_15 ,
V_14 -> V_9 [ V_39 ] , V_14 -> V_9 , V_10 -> V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_10 * V_11 ,
const char * V_40 , struct V_10 * V_10 ,
struct V_13 * V_14 , struct V_41 * V_42 )
{
struct V_10 * V_43 = NULL ;
struct V_13 * V_44 = NULL ;
struct V_41 * V_45 = NULL ;
V_43 = F_20 ( V_11 , V_40 ) ;
if ( ! V_43 )
V_44 = F_21 ( V_11 , V_40 , & V_43 ) ;
if ( ! V_43 )
V_45 = F_22 ( V_11 , V_40 , & V_43 ,
& V_44 ) ;
if ( ! V_43 )
return;
if ( ( V_43 != V_10 ) || ( V_44 != V_14 ) || ( V_45 != V_42 ) )
F_10 ( V_2 , L_16 V_46
L_17 V_46 ,
V_40 , F_23 ( V_10 , V_14 , V_42 ) ,
F_23 ( V_43 , V_44 , V_45 ) ) ;
}
static void F_24 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_40 * V_47 ;
F_25 (node->labels, l)
F_19 ( V_2 , V_11 , V_47 -> V_40 , V_10 , NULL , NULL ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 , struct V_13 * V_14 )
{
struct V_41 * V_48 = V_14 -> V_32 . V_49 ;
struct V_40 * V_47 ;
F_25 (prop->labels, l)
F_19 ( V_2 , V_11 , V_47 -> V_40 , V_10 , V_14 , NULL ) ;
F_27 (m, LABEL)
F_19 ( V_2 , V_11 , V_48 -> V_50 , V_10 , V_14 , V_48 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_10 * V_29 ,
struct V_10 * V_10 , struct V_13 * V_14 )
{
struct V_41 * V_48 ;
struct V_10 * V_51 ;
V_34 V_52 ;
if ( ! F_13 ( V_14 -> V_9 , L_18 )
&& ! F_13 ( V_14 -> V_9 , L_19 ) )
return;
if ( V_14 -> V_32 . V_33 != sizeof( V_34 ) ) {
F_10 ( V_2 , L_20 ,
V_10 -> V_15 , V_14 -> V_32 . V_33 , V_14 -> V_9 ) ;
return;
}
V_48 = V_14 -> V_32 . V_49 ;
F_27 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 == 0 ) ;
if ( V_10 != F_29 ( V_29 , V_48 -> V_50 ) )
{
F_10 ( V_2 , L_21 ,
V_14 -> V_9 , V_10 -> V_15 ) ;
return;
}
return;
}
V_52 = F_30 ( V_14 ) ;
if ( ( V_52 == 0 ) || ( V_52 == - 1 ) ) {
F_10 ( V_2 , L_22 ,
V_10 -> V_15 , V_52 , V_14 -> V_9 ) ;
return;
}
if ( V_10 -> V_52 && ( V_10 -> V_52 != V_52 ) )
F_10 ( V_2 , L_23 ,
V_10 -> V_15 , V_14 -> V_9 ) ;
V_51 = F_31 ( V_29 , V_52 ) ;
if ( V_51 && ( V_51 != V_10 ) ) {
F_10 ( V_2 , L_24 ,
V_10 -> V_15 , V_52 , V_51 -> V_15 ) ;
return;
}
V_10 -> V_52 = V_52 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_10 * V_29 ,
struct V_10 * V_10 )
{
struct V_13 * * V_54 , * V_14 = NULL ;
for ( V_54 = & V_10 -> V_55 ; * V_54 ; V_54 = & ( ( * V_54 ) -> V_38 ) )
if ( F_13 ( ( * V_54 ) -> V_9 , L_25 ) ) {
V_14 = * V_54 ;
break;
}
if ( ! V_14 )
return;
if ( ( V_14 -> V_32 . V_33 != V_10 -> V_56 + 1 )
|| ( memcmp ( V_14 -> V_32 . V_32 , V_10 -> V_9 , V_10 -> V_56 ) != 0 ) ) {
F_10 ( V_2 , L_26
L_27 , V_10 -> V_15 , V_14 -> V_32 . V_32 ) ;
} else {
* V_54 = V_14 -> V_38 ;
free ( V_14 -> V_9 ) ;
F_33 ( V_14 -> V_32 ) ;
free ( V_14 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 , struct V_13 * V_14 )
{
struct V_41 * V_48 = V_14 -> V_32 . V_49 ;
struct V_10 * V_57 ;
V_34 V_52 ;
F_27 (m, REF_PHANDLE) {
assert ( V_48 -> V_53 + sizeof( V_34 ) <= V_14 -> V_32 . V_33 ) ;
V_57 = F_29 ( V_11 , V_48 -> V_50 ) ;
if ( ! V_57 ) {
F_10 ( V_2 , L_28 ,
V_48 -> V_50 ) ;
continue;
}
V_52 = F_35 ( V_11 , V_57 ) ;
* ( ( V_34 * ) ( V_14 -> V_32 . V_32 + V_48 -> V_53 ) ) = F_36 ( V_52 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 , struct V_13 * V_14 )
{
struct V_41 * V_48 = V_14 -> V_32 . V_49 ;
struct V_10 * V_57 ;
char * V_58 ;
F_27 (m, REF_PATH) {
assert ( V_48 -> V_53 <= V_14 -> V_32 . V_33 ) ;
V_57 = F_29 ( V_11 , V_48 -> V_50 ) ;
if ( ! V_57 ) {
F_10 ( V_2 , L_28 ,
V_48 -> V_50 ) ;
continue;
}
V_58 = V_57 -> V_15 ;
V_14 -> V_32 = F_38 ( V_14 -> V_32 , V_48 , V_58 ,
strlen ( V_58 ) + 1 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 ;
V_10 -> V_59 = - 1 ;
V_10 -> V_60 = - 1 ;
V_14 = F_8 ( V_10 , L_29 ) ;
if ( V_14 )
V_10 -> V_59 = F_30 ( V_14 ) ;
V_14 = F_8 ( V_10 , L_30 ) ;
if ( V_14 )
V_10 -> V_60 = F_30 ( V_14 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 ;
int V_59 , V_60 , V_61 ;
V_14 = F_8 ( V_10 , L_31 ) ;
if ( ! V_14 )
return;
if ( ! V_10 -> V_62 ) {
F_10 ( V_2 , L_32 ) ;
return;
}
if ( V_14 -> V_32 . V_33 == 0 )
F_10 ( V_2 , L_33 , V_10 -> V_15 ) ;
V_59 = F_41 ( V_10 -> V_62 ) ;
V_60 = F_42 ( V_10 -> V_62 ) ;
V_61 = ( V_59 + V_60 ) * sizeof( V_34 ) ;
if ( ( V_14 -> V_32 . V_33 % V_61 ) != 0 )
F_10 ( V_2 , L_34
L_35 ,
V_10 -> V_15 , V_14 -> V_32 . V_33 , V_59 , V_60 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_13 * V_14 ;
int V_63 , V_64 , V_65 , V_66 , V_61 ;
V_14 = F_8 ( V_10 , L_36 ) ;
if ( ! V_14 )
return;
if ( ! V_10 -> V_62 ) {
F_10 ( V_2 , L_37 ) ;
return;
}
V_64 = F_41 ( V_10 -> V_62 ) ;
V_66 = F_42 ( V_10 -> V_62 ) ;
V_63 = F_41 ( V_10 ) ;
V_65 = F_42 ( V_10 ) ;
V_61 = ( V_64 + V_63 + V_65 ) * sizeof( V_34 ) ;
if ( V_14 -> V_32 . V_33 == 0 ) {
if ( V_64 != V_63 )
F_10 ( V_2 , L_38
L_39 ,
V_10 -> V_15 , V_63 , V_10 -> V_62 -> V_15 ,
V_64 ) ;
if ( V_66 != V_65 )
F_10 ( V_2 , L_38
L_40 ,
V_10 -> V_15 , V_65 , V_10 -> V_62 -> V_15 ,
V_66 ) ;
} else if ( ( V_14 -> V_32 . V_33 % V_61 ) != 0 ) {
F_10 ( V_2 , L_41
L_42
L_43 , V_10 -> V_15 , V_14 -> V_32 . V_33 ,
V_64 , V_63 , V_65 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_10 * V_10 )
{
struct V_13 * V_67 , * V_68 ;
if ( ! V_10 -> V_62 )
return;
V_67 = F_8 ( V_10 , L_31 ) ;
V_68 = F_8 ( V_10 , L_36 ) ;
if ( ! V_67 && ! V_68 )
return;
if ( ( V_10 -> V_62 -> V_59 == - 1 ) )
F_10 ( V_2 , L_44 ,
V_10 -> V_15 ) ;
if ( ( V_10 -> V_62 -> V_60 == - 1 ) )
F_10 ( V_2 , L_45 ,
V_10 -> V_15 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_10 * V_69 ;
struct V_13 * V_14 ;
V_69 = F_46 ( V_11 , L_46 ) ;
if ( ! V_69 )
return;
V_14 = F_8 ( V_69 , L_47 ) ;
if ( V_14 )
F_10 ( V_2 , L_48
L_49 ) ;
}
void F_47 ( int V_70 , struct V_71 * V_72 )
{
struct V_10 * V_11 = V_72 -> V_11 ;
int V_18 ;
int error = 0 ;
for ( V_18 = 0 ; V_18 < F_48 ( V_73 ) ; V_18 ++ ) {
struct V_1 * V_2 = V_73 [ V_18 ] ;
if ( V_2 -> V_5 != V_74 )
error = error || F_6 ( V_2 , V_11 ) ;
}
if ( error ) {
if ( ! V_70 ) {
fprintf ( V_8 , L_50
L_51 ) ;
exit ( 2 ) ;
} else if ( V_7 < 3 ) {
fprintf ( V_8 , L_52
L_53 ) ;
}
}
}
