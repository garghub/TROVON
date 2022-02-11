static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
struct V_5 * V_6 ;
F_2 ( V_2 , L_1 , V_5 -> V_7 ) ;
if ( V_2 -> V_8 )
V_2 -> V_8 ( V_2 , V_4 , V_5 ) ;
F_3 (node, child)
F_1 ( V_2 , V_4 , V_6 ) ;
}
static bool F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_9 = V_4 -> V_9 ;
bool error = false ;
int V_10 ;
assert ( ! V_2 -> V_11 ) ;
if ( V_2 -> V_12 != V_13 )
goto V_14;
V_2 -> V_11 = true ;
for ( V_10 = 0 ; V_10 < V_2 -> V_15 ; V_10 ++ ) {
struct V_1 * V_16 = V_2 -> V_17 [ V_10 ] ;
error = error || F_4 ( V_16 , V_4 ) ;
if ( V_16 -> V_12 != V_18 ) {
V_2 -> V_12 = V_19 ;
F_5 ( V_2 , V_4 , L_2 ,
V_2 -> V_17 [ V_10 ] -> V_20 ) ;
}
}
if ( V_2 -> V_12 != V_13 )
goto V_14;
F_1 ( V_2 , V_4 , V_9 ) ;
if ( V_2 -> V_12 == V_13 )
V_2 -> V_12 = V_18 ;
F_2 ( V_2 , L_3 , V_2 -> V_12 ) ;
V_14:
V_2 -> V_11 = false ;
if ( ( V_2 -> V_12 != V_18 ) && ( V_2 -> error ) )
error = true ;
return error ;
}
static inline void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
F_7 ( V_2 , V_4 , L_4 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
char * V_23 = V_2 -> V_24 ;
V_22 = F_9 ( V_5 , V_23 ) ;
if ( ! V_22 )
return;
if ( ! F_10 ( V_22 -> V_25 ) )
F_7 ( V_2 , V_4 , L_5 ,
V_23 , V_5 -> V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
char * V_23 = V_2 -> V_24 ;
V_22 = F_9 ( V_5 , V_23 ) ;
if ( ! V_22 )
return;
if ( V_22 -> V_25 . V_26 != sizeof( V_27 ) )
F_7 ( V_2 , V_4 , L_6 ,
V_23 , V_5 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * V_6 , * V_28 ;
F_3 (node, child)
for ( V_28 = V_6 -> V_29 ;
V_28 ;
V_28 = V_28 -> V_29 )
if ( F_13 ( V_6 -> V_20 , V_28 -> V_20 ) )
F_7 ( V_2 , V_4 , L_7 ,
V_6 -> V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 , * V_30 ;
F_15 (node, prop) {
for ( V_30 = V_22 -> V_31 ; V_30 ; V_30 = V_30 -> V_31 ) {
if ( V_30 -> V_32 )
continue;
if ( F_13 ( V_22 -> V_20 , V_30 -> V_20 ) )
F_7 ( V_2 , V_4 , L_8 ,
V_22 -> V_20 , V_5 -> V_7 ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
int V_33 = strspn ( V_5 -> V_20 , V_2 -> V_24 ) ;
if ( V_33 < strlen ( V_5 -> V_20 ) )
F_7 ( V_2 , V_4 , L_9 ,
V_5 -> V_20 [ V_33 ] , V_5 -> V_7 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
int V_33 = strspn ( V_5 -> V_20 , V_2 -> V_24 ) ;
if ( V_33 < V_5 -> V_34 )
F_7 ( V_2 , V_4 , L_10 ,
V_5 -> V_20 [ V_33 ] , V_5 -> V_7 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
if ( strchr ( F_19 ( V_5 ) , '@' ) )
F_7 ( V_2 , V_4 , L_11 ,
V_5 -> V_7 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
const char * V_35 = F_19 ( V_5 ) ;
struct V_21 * V_22 = F_9 ( V_5 , L_12 ) ;
if ( ! V_22 ) {
V_22 = F_9 ( V_5 , L_13 ) ;
if ( V_22 && ! V_22 -> V_25 . V_26 )
V_22 = NULL ;
}
if ( V_22 ) {
if ( ! V_35 [ 0 ] )
F_7 ( V_2 , V_4 , L_14 ,
V_5 -> V_7 ) ;
} else {
if ( V_35 [ 0 ] )
F_7 ( V_2 , V_4 , L_15 ,
V_5 -> V_7 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
F_15 (node, prop) {
int V_33 = strspn ( V_22 -> V_20 , V_2 -> V_24 ) ;
if ( V_33 < strlen ( V_22 -> V_20 ) )
F_7 ( V_2 , V_4 , L_16 ,
V_22 -> V_20 [ V_33 ] , V_22 -> V_20 , V_5 -> V_7 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
F_15 (node, prop) {
const char * V_20 = V_22 -> V_20 ;
int V_33 = strspn ( V_20 , V_2 -> V_24 ) ;
if ( V_33 == strlen ( V_22 -> V_20 ) )
continue;
if ( F_13 ( V_20 , L_17 ) )
continue;
if ( V_20 [ V_33 ] == '#' && ( ( V_33 == 0 ) || ( V_20 [ V_33 - 1 ] == ',' ) ) ) {
V_20 += V_33 + 1 ;
V_33 = strspn ( V_20 , V_2 -> V_24 ) ;
}
if ( V_33 < strlen ( V_20 ) )
F_7 ( V_2 , V_4 , L_18 ,
V_20 [ V_33 ] , V_22 -> V_20 , V_5 -> V_7 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_36 , struct V_5 * V_5 ,
struct V_21 * V_22 , struct V_37 * V_38 )
{
struct V_5 * V_9 = V_4 -> V_9 ;
struct V_5 * V_39 = NULL ;
struct V_21 * V_40 = NULL ;
struct V_37 * V_41 = NULL ;
V_39 = F_24 ( V_9 , V_36 ) ;
if ( ! V_39 )
V_40 = F_25 ( V_9 , V_36 , & V_39 ) ;
if ( ! V_39 )
V_41 = F_26 ( V_9 , V_36 , & V_39 ,
& V_40 ) ;
if ( ! V_39 )
return;
if ( ( V_39 != V_5 ) || ( V_40 != V_22 ) || ( V_41 != V_38 ) )
F_7 ( V_2 , V_4 , L_19 V_42
L_20 V_42 ,
V_36 , F_27 ( V_5 , V_22 , V_38 ) ,
F_27 ( V_39 , V_40 , V_41 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_36 * V_43 ;
struct V_21 * V_22 ;
F_29 (node->labels, l)
F_23 ( V_2 , V_4 , V_43 -> V_36 , V_5 , NULL , NULL ) ;
F_15 (node, prop) {
struct V_37 * V_44 = V_22 -> V_25 . V_45 ;
F_29 (prop->labels, l)
F_23 ( V_2 , V_4 , V_43 -> V_36 , V_5 , V_22 , NULL ) ;
F_30 (m, LABEL)
F_23 ( V_2 , V_4 , V_44 -> V_46 , V_5 , V_22 , V_44 ) ;
}
}
static V_27 F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 , const char * V_23 )
{
struct V_5 * V_47 = V_4 -> V_9 ;
struct V_21 * V_22 ;
struct V_37 * V_44 ;
V_27 V_48 ;
V_22 = F_9 ( V_5 , V_23 ) ;
if ( ! V_22 )
return 0 ;
if ( V_22 -> V_25 . V_26 != sizeof( V_27 ) ) {
F_7 ( V_2 , V_4 , L_21 ,
V_5 -> V_7 , V_22 -> V_25 . V_26 , V_22 -> V_20 ) ;
return 0 ;
}
V_44 = V_22 -> V_25 . V_45 ;
F_30 (m, REF_PHANDLE) {
assert ( V_44 -> V_49 == 0 ) ;
if ( V_5 != F_32 ( V_47 , V_44 -> V_46 ) )
{
F_7 ( V_2 , V_4 , L_22 ,
V_22 -> V_20 , V_5 -> V_7 ) ;
}
return 0 ;
}
V_48 = F_33 ( V_22 ) ;
if ( ( V_48 == 0 ) || ( V_48 == - 1 ) ) {
F_7 ( V_2 , V_4 , L_23 ,
V_5 -> V_7 , V_48 , V_22 -> V_20 ) ;
return 0 ;
}
return V_48 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * V_47 = V_4 -> V_9 ;
struct V_5 * V_50 ;
V_27 V_48 , V_51 ;
assert ( ! V_5 -> V_48 ) ;
V_48 = F_31 ( V_2 , V_4 , V_5 , L_24 ) ;
V_51 = F_31 ( V_2 , V_4 , V_5 , L_25 ) ;
if ( ! V_48 && ! V_51 )
return;
if ( V_51 && V_48 && ( V_48 != V_51 ) )
F_7 ( V_2 , V_4 , L_26
L_27 , V_5 -> V_7 ) ;
if ( V_51 && ! V_48 )
V_48 = V_51 ;
V_50 = F_35 ( V_47 , V_48 ) ;
if ( V_50 && ( V_50 != V_5 ) ) {
F_7 ( V_2 , V_4 , L_28 ,
V_5 -> V_7 , V_48 , V_50 -> V_7 ) ;
return;
}
V_5 -> V_48 = V_48 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * * V_52 , * V_22 = NULL ;
for ( V_52 = & V_5 -> V_53 ; * V_52 ; V_52 = & ( ( * V_52 ) -> V_31 ) )
if ( F_13 ( ( * V_52 ) -> V_20 , L_29 ) ) {
V_22 = * V_52 ;
break;
}
if ( ! V_22 )
return;
if ( ( V_22 -> V_25 . V_26 != V_5 -> V_34 + 1 )
|| ( memcmp ( V_22 -> V_25 . V_25 , V_5 -> V_20 , V_5 -> V_34 ) != 0 ) ) {
F_7 ( V_2 , V_4 , L_30
L_31 , V_5 -> V_7 , V_22 -> V_25 . V_25 ) ;
} else {
* V_52 = V_22 -> V_31 ;
free ( V_22 -> V_20 ) ;
F_37 ( V_22 -> V_25 ) ;
free ( V_22 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * V_9 = V_4 -> V_9 ;
struct V_21 * V_22 ;
F_15 (node, prop) {
struct V_37 * V_44 = V_22 -> V_25 . V_45 ;
struct V_5 * V_54 ;
V_27 V_48 ;
F_30 (m, REF_PHANDLE) {
assert ( V_44 -> V_49 + sizeof( V_27 ) <= V_22 -> V_25 . V_26 ) ;
V_54 = F_32 ( V_9 , V_44 -> V_46 ) ;
if ( ! V_54 ) {
if ( ! ( V_4 -> V_55 & V_56 ) )
F_7 ( V_2 , V_4 , L_32
L_33 , V_44 -> V_46 ) ;
else
* ( ( V_57 * ) ( V_22 -> V_25 . V_25 + V_44 -> V_49 ) ) =
F_39 ( 0xffffffff ) ;
continue;
}
V_48 = F_40 ( V_9 , V_54 ) ;
* ( ( V_57 * ) ( V_22 -> V_25 . V_25 + V_44 -> V_49 ) ) = F_39 ( V_48 ) ;
}
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * V_9 = V_4 -> V_9 ;
struct V_21 * V_22 ;
F_15 (node, prop) {
struct V_37 * V_44 = V_22 -> V_25 . V_45 ;
struct V_5 * V_54 ;
char * V_58 ;
F_30 (m, REF_PATH) {
assert ( V_44 -> V_49 <= V_22 -> V_25 . V_26 ) ;
V_54 = F_32 ( V_9 , V_44 -> V_46 ) ;
if ( ! V_54 ) {
F_7 ( V_2 , V_4 , L_34 ,
V_44 -> V_46 ) ;
continue;
}
V_58 = V_54 -> V_7 ;
V_22 -> V_25 = F_42 ( V_22 -> V_25 , V_44 , V_58 ,
strlen ( V_58 ) + 1 ) ;
}
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
V_5 -> V_59 = - 1 ;
V_5 -> V_60 = - 1 ;
V_22 = F_9 ( V_5 , L_35 ) ;
if ( V_22 )
V_5 -> V_59 = F_33 ( V_22 ) ;
V_22 = F_9 ( V_5 , L_36 ) ;
if ( V_22 )
V_5 -> V_60 = F_33 ( V_22 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
int V_59 , V_60 , V_61 ;
V_22 = F_9 ( V_5 , L_12 ) ;
if ( ! V_22 )
return;
if ( ! V_5 -> V_62 ) {
F_7 ( V_2 , V_4 , L_37 ) ;
return;
}
if ( V_22 -> V_25 . V_26 == 0 )
F_7 ( V_2 , V_4 , L_38 , V_5 -> V_7 ) ;
V_59 = F_45 ( V_5 -> V_62 ) ;
V_60 = F_46 ( V_5 -> V_62 ) ;
V_61 = ( V_59 + V_60 ) * sizeof( V_27 ) ;
if ( ! V_61 || ( V_22 -> V_25 . V_26 % V_61 ) != 0 )
F_7 ( V_2 , V_4 , L_39
L_40 ,
V_5 -> V_7 , V_22 -> V_25 . V_26 , V_59 , V_60 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_22 ;
int V_63 , V_64 , V_65 , V_66 , V_61 ;
V_22 = F_9 ( V_5 , L_13 ) ;
if ( ! V_22 )
return;
if ( ! V_5 -> V_62 ) {
F_7 ( V_2 , V_4 , L_41 ) ;
return;
}
V_64 = F_45 ( V_5 -> V_62 ) ;
V_66 = F_46 ( V_5 -> V_62 ) ;
V_63 = F_45 ( V_5 ) ;
V_65 = F_46 ( V_5 ) ;
V_61 = ( V_64 + V_63 + V_65 ) * sizeof( V_27 ) ;
if ( V_22 -> V_25 . V_26 == 0 ) {
if ( V_64 != V_63 )
F_7 ( V_2 , V_4 , L_42
L_43 ,
V_5 -> V_7 , V_63 , V_5 -> V_62 -> V_7 ,
V_64 ) ;
if ( V_66 != V_65 )
F_7 ( V_2 , V_4 , L_42
L_44 ,
V_5 -> V_7 , V_65 , V_5 -> V_62 -> V_7 ,
V_66 ) ;
} else if ( ( V_22 -> V_25 . V_26 % V_61 ) != 0 ) {
F_7 ( V_2 , V_4 , L_45
L_46
L_47 , V_5 -> V_7 , V_22 -> V_25 . V_26 ,
V_64 , V_63 , V_65 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
struct V_21 * V_22 ;
V_27 * V_67 ;
V_22 = F_9 ( V_5 , L_17 ) ;
if ( ! V_22 || ! F_13 ( V_22 -> V_25 . V_25 , L_48 ) )
return;
V_5 -> V_68 = & V_69 ;
if ( ! F_49 ( V_5 -> V_20 , L_48 , V_5 -> V_34 ) &&
! F_49 ( V_5 -> V_20 , L_49 , V_5 -> V_34 ) )
F_7 ( V_2 , V_4 , L_50 ,
V_5 -> V_7 ) ;
V_22 = F_9 ( V_5 , L_13 ) ;
if ( ! V_22 )
F_7 ( V_2 , V_4 , L_51 ,
V_5 -> V_7 ) ;
if ( F_45 ( V_5 ) != 3 )
F_7 ( V_2 , V_4 , L_52 ,
V_5 -> V_7 ) ;
if ( F_46 ( V_5 ) != 2 )
F_7 ( V_2 , V_4 , L_53 ,
V_5 -> V_7 ) ;
V_22 = F_9 ( V_5 , L_54 ) ;
if ( ! V_22 ) {
F_7 ( V_2 , V_4 , L_55 ,
V_5 -> V_7 ) ;
return;
}
if ( V_22 -> V_25 . V_26 != ( sizeof( V_27 ) * 2 ) ) {
F_7 ( V_2 , V_4 , L_56 ,
V_5 -> V_7 ) ;
return;
}
V_67 = ( V_27 * ) V_22 -> V_25 . V_25 ;
if ( F_50 ( V_67 [ 0 ] ) > F_50 ( V_67 [ 1 ] ) )
F_7 ( V_2 , V_4 , L_57 ,
V_5 -> V_7 ) ;
if ( F_50 ( V_67 [ 1 ] ) > 0xff )
F_7 ( V_2 , V_4 , L_58 ,
V_5 -> V_7 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
struct V_21 * V_22 ;
unsigned int V_70 , V_71 , V_72 ;
V_27 * V_67 ;
if ( ! V_5 -> V_62 || ( V_5 -> V_62 -> V_68 != & V_69 ) )
return;
V_22 = F_9 ( V_5 , L_12 ) ;
if ( ! V_22 )
return;
V_67 = ( V_27 * ) V_22 -> V_25 . V_25 ;
V_70 = ( F_50 ( V_67 [ 0 ] ) & 0x00ff0000 ) >> 16 ;
V_22 = F_9 ( V_5 -> V_62 , L_54 ) ;
if ( ! V_22 ) {
V_71 = V_72 = 0 ;
} else {
V_67 = ( V_27 * ) V_22 -> V_25 . V_25 ;
V_71 = F_50 ( V_67 [ 0 ] ) ;
V_72 = F_50 ( V_67 [ 0 ] ) ;
}
if ( ( V_70 < V_71 ) || ( V_70 > V_72 ) )
F_7 ( V_2 , V_4 , L_59 ,
V_5 -> V_7 , V_70 , V_71 , V_72 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
struct V_21 * V_22 ;
const char * V_35 = F_19 ( V_5 ) ;
char V_73 [ 5 ] ;
unsigned int V_74 , V_75 , V_76 ;
V_27 * V_67 ;
if ( ! V_5 -> V_62 || ( V_5 -> V_62 -> V_68 != & V_69 ) )
return;
V_22 = F_9 ( V_5 , L_12 ) ;
if ( ! V_22 ) {
F_7 ( V_2 , V_4 , L_60 , V_5 -> V_7 ) ;
return;
}
V_67 = ( V_27 * ) V_22 -> V_25 . V_25 ;
if ( V_67 [ 1 ] || V_67 [ 2 ] )
F_7 ( V_2 , V_4 , L_61 ,
V_5 -> V_7 ) ;
V_76 = F_50 ( V_67 [ 0 ] ) ;
V_74 = ( V_76 & 0xf800 ) >> 11 ;
V_75 = ( V_76 & 0x700 ) >> 8 ;
if ( V_76 & 0xff000000 )
F_7 ( V_2 , V_4 , L_62 ,
V_5 -> V_7 ) ;
if ( V_76 & 0x000000ff )
F_7 ( V_2 , V_4 , L_63 ,
V_5 -> V_7 ) ;
if ( V_75 == 0 ) {
snprintf ( V_73 , sizeof( V_73 ) , L_64 , V_74 ) ;
if ( F_13 ( V_35 , V_73 ) )
return;
}
snprintf ( V_73 , sizeof( V_73 ) , L_65 , V_74 , V_75 ) ;
if ( F_13 ( V_35 , V_73 ) )
return;
F_7 ( V_2 , V_4 , L_66 ,
V_5 -> V_7 , V_73 ) ;
}
static bool F_53 ( struct V_5 * V_5 , const char * V_77 )
{
struct V_21 * V_22 ;
const char * V_78 , * V_79 ;
V_22 = F_9 ( V_5 , L_67 ) ;
if ( ! V_22 )
return false ;
for ( V_78 = V_22 -> V_25 . V_25 , V_79 = V_78 + V_22 -> V_25 . V_26 ; V_78 < V_79 ;
V_78 += F_54 ( V_78 , V_79 - V_78 ) + 1 ) {
if ( F_49 ( V_78 , V_77 , V_79 - V_78 ) )
return true ;
}
return false ;
}
static void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
if ( F_53 ( V_5 , L_68 ) )
V_5 -> V_68 = & V_80 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
struct V_21 * V_22 ;
const char * V_35 = F_19 ( V_5 ) ;
char V_73 [ 17 ] ;
unsigned int V_81 ;
T_1 V_76 = 0 ;
V_27 * V_67 = NULL ;
if ( ! V_5 -> V_62 || ( V_5 -> V_62 -> V_68 != & V_80 ) )
return;
V_22 = F_9 ( V_5 , L_12 ) ;
if ( V_22 )
V_67 = ( V_27 * ) V_22 -> V_25 . V_25 ;
else {
V_22 = F_9 ( V_5 , L_13 ) ;
if ( V_22 && V_22 -> V_25 . V_26 )
V_67 = ( ( V_27 * ) V_22 -> V_25 . V_25 ) + F_45 ( V_5 ) ;
}
if ( ! V_67 ) {
if ( V_5 -> V_62 -> V_62 && ! ( V_5 -> V_68 == & V_80 ) )
F_7 ( V_2 , V_4 , L_69 , V_5 -> V_7 ) ;
return;
}
V_81 = F_45 ( V_5 -> V_62 ) ;
while ( V_81 -- )
V_76 = ( V_76 << 32 ) | F_50 ( * ( V_67 ++ ) ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_70 , V_76 ) ;
if ( ! F_13 ( V_35 , V_73 ) )
F_7 ( V_2 , V_4 , L_71 ,
V_5 -> V_7 , V_73 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
const char * V_35 = F_19 ( V_5 ) ;
if ( V_5 -> V_62 && V_5 -> V_62 -> V_68 )
return;
if ( ! V_35 [ 0 ] )
return;
if ( ! strncmp ( V_35 , L_72 , 2 ) ) {
F_7 ( V_2 , V_4 , L_73 ,
V_5 -> V_7 ) ;
V_35 += 2 ;
}
if ( V_35 [ 0 ] == '0' && isxdigit ( V_35 [ 1 ] ) )
F_7 ( V_2 , V_4 , L_74 ,
V_5 -> V_7 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_21 * V_76 , * V_82 ;
if ( ! V_5 -> V_62 )
return;
V_76 = F_9 ( V_5 , L_12 ) ;
V_82 = F_9 ( V_5 , L_13 ) ;
if ( ! V_76 && ! V_82 )
return;
if ( V_5 -> V_62 -> V_59 == - 1 )
F_7 ( V_2 , V_4 , L_75 ,
V_5 -> V_7 ) ;
if ( V_5 -> V_62 -> V_60 == - 1 )
F_7 ( V_2 , V_4 , L_76 ,
V_5 -> V_7 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * V_9 = V_4 -> V_9 ;
struct V_5 * V_83 ;
struct V_21 * V_22 ;
if ( V_5 != V_9 )
return;
V_83 = F_60 ( V_9 , L_77 ) ;
if ( ! V_83 )
return;
V_22 = F_9 ( V_83 , L_78 ) ;
if ( V_22 )
F_7 ( V_2 , V_4 , L_79
L_80 ) ;
}
static void F_61 ( struct V_1 * V_2 , bool V_84 , bool error )
{
int V_10 ;
if ( ( V_84 && ! V_2 -> V_84 ) || ( error && ! V_2 -> error ) )
for ( V_10 = 0 ; V_10 < V_2 -> V_15 ; V_10 ++ )
F_61 ( V_2 -> V_17 [ V_10 ] , V_84 , error ) ;
V_2 -> V_84 = V_2 -> V_84 || V_84 ;
V_2 -> error = V_2 -> error || error ;
}
static void F_62 ( struct V_1 * V_2 , bool V_84 , bool error )
{
int V_10 ;
if ( ( V_84 && V_2 -> V_84 ) || ( error && V_2 -> error ) ) {
for ( V_10 = 0 ; V_10 < F_63 ( V_85 ) ; V_10 ++ ) {
struct V_1 * V_86 = V_85 [ V_10 ] ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_86 -> V_15 ; V_87 ++ )
if ( V_86 -> V_17 [ V_87 ] == V_2 )
F_62 ( V_86 , V_84 , error ) ;
}
}
V_2 -> V_84 = V_2 -> V_84 && ! V_84 ;
V_2 -> error = V_2 -> error && ! error ;
}
void F_64 ( bool V_84 , bool error , const char * V_88 )
{
int V_10 ;
const char * V_20 = V_88 ;
bool V_89 = true ;
if ( ( strncmp ( V_88 , L_81 , 3 ) == 0 )
|| ( strncmp ( V_88 , L_82 , 3 ) == 0 ) ) {
V_20 = V_88 + 3 ;
V_89 = false ;
}
for ( V_10 = 0 ; V_10 < F_63 ( V_85 ) ; V_10 ++ ) {
struct V_1 * V_2 = V_85 [ V_10 ] ;
if ( F_13 ( V_2 -> V_20 , V_20 ) ) {
if ( V_89 )
F_61 ( V_2 , V_84 , error ) ;
else
F_62 ( V_2 , V_84 , error ) ;
return;
}
}
F_65 ( L_83 , V_20 ) ;
}
void F_66 ( bool V_90 , struct V_3 * V_4 )
{
int V_10 ;
int error = 0 ;
for ( V_10 = 0 ; V_10 < F_63 ( V_85 ) ; V_10 ++ ) {
struct V_1 * V_2 = V_85 [ V_10 ] ;
if ( V_2 -> V_84 || V_2 -> error )
error = error || F_4 ( V_2 , V_4 ) ;
}
if ( error ) {
if ( ! V_90 ) {
fprintf ( V_91 , L_84
L_85 ) ;
exit ( 2 ) ;
} else if ( V_92 < 3 ) {
fprintf ( V_91 , L_86
L_87 ) ;
}
}
}
