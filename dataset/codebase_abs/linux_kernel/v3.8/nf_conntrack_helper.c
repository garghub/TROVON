static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) ,
V_5 ) ;
if ( ! V_3 )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
if ( V_1 -> V_10 != & V_11 )
V_3 [ 0 ] . V_12 = NULL ;
V_1 -> V_8 . V_13 =
F_3 ( V_1 , L_1 , V_3 ) ;
if ( ! V_1 -> V_8 . V_13 ) {
F_4 ( L_2 ) ;
goto V_14;
}
return 0 ;
V_14:
F_5 ( V_3 ) ;
V_6:
return - V_15 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_13 -> V_16 ;
F_7 ( V_1 -> V_8 . V_13 ) ;
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
}
static unsigned int F_8 ( const struct V_17 * V_18 )
{
return ( ( ( V_18 -> V_19 . V_20 << 8 ) | V_18 -> V_21 . V_22 ) ^
( V_23 V_24 ) V_18 -> V_19 . V_25 . V_26 ) % V_27 ;
}
static struct V_28 *
F_9 ( const struct V_17 * V_18 )
{
struct V_28 * V_29 ;
struct V_30 V_31 = { . V_19 . V_25 . V_26 = F_10 ( 0xFFFF ) } ;
struct V_32 * V_33 ;
unsigned int V_34 ;
if ( ! V_35 )
return NULL ;
V_34 = F_8 ( V_18 ) ;
F_11 (helper, n, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( V_18 , & V_29 -> V_18 , & V_31 ) )
return V_29 ;
}
return NULL ;
}
struct V_28 *
F_13 ( const char * V_36 , T_1 V_20 , T_2 V_22 )
{
struct V_28 * V_34 ;
struct V_32 * V_33 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_27 ; V_37 ++ ) {
F_11 (h, n, &nf_ct_helper_hash[i], hnode) {
if ( ! strcmp ( V_34 -> V_36 , V_36 ) &&
V_34 -> V_18 . V_19 . V_20 == V_20 &&
V_34 -> V_18 . V_21 . V_22 == V_22 )
return V_34 ;
}
}
return NULL ;
}
struct V_28 *
F_14 ( const char * V_36 , T_1 V_20 , T_2 V_22 )
{
struct V_28 * V_34 ;
V_34 = F_13 ( V_36 , V_20 , V_22 ) ;
#ifdef F_15
if ( V_34 == NULL ) {
if ( F_16 ( L_3 , V_36 ) == 0 )
V_34 = F_13 ( V_36 , V_20 , V_22 ) ;
}
#endif
if ( V_34 != NULL && ! F_17 ( V_34 -> V_38 ) )
V_34 = NULL ;
return V_34 ;
}
struct V_39 *
F_18 ( struct V_40 * V_8 ,
struct V_28 * V_29 , T_3 V_41 )
{
struct V_39 * V_42 ;
V_42 = F_19 ( V_8 , V_43 ,
V_29 -> V_44 , V_41 ) ;
if ( V_42 )
F_20 ( & V_42 -> V_45 ) ;
else
F_21 ( L_4 ) ;
return V_42 ;
}
int F_22 ( struct V_40 * V_8 , struct V_40 * V_46 ,
T_3 V_47 )
{
struct V_28 * V_29 = NULL ;
struct V_39 * V_42 ;
struct V_1 * V_1 = F_23 ( V_8 ) ;
int V_48 = 0 ;
if ( F_24 ( V_49 , & V_8 -> V_50 ) )
return 0 ;
if ( V_46 != NULL ) {
V_42 = F_25 ( V_46 ) ;
if ( V_42 != NULL ) {
V_29 = V_42 -> V_29 ;
F_26 ( V_49 , & V_8 -> V_50 ) ;
}
}
V_42 = F_25 ( V_8 ) ;
if ( V_1 -> V_8 . V_9 && V_29 == NULL ) {
V_29 = F_9 ( & V_8 -> V_51 [ V_52 ] . V_18 ) ;
if ( F_27 ( ! V_1 -> V_8 . V_53 && V_29 ) ) {
F_28 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_53 = true ;
}
}
if ( V_29 == NULL ) {
if ( V_42 )
F_29 ( V_42 -> V_29 , NULL ) ;
goto V_6;
}
if ( V_42 == NULL ) {
V_42 = F_18 ( V_8 , V_29 , V_47 ) ;
if ( V_42 == NULL ) {
V_48 = - V_15 ;
goto V_6;
}
} else {
if ( V_42 -> V_29 != V_29 ) {
F_29 ( V_42 -> V_29 , NULL ) ;
goto V_6;
}
}
F_30 ( V_42 -> V_29 , V_29 ) ;
V_6:
return V_48 ;
}
static inline int F_31 ( struct V_54 * V_37 ,
const struct V_28 * V_38 )
{
struct V_40 * V_8 = F_32 ( V_37 ) ;
struct V_39 * V_42 = F_25 ( V_8 ) ;
if ( V_42 && F_33 (
V_42 -> V_29 ,
F_34 ( & V_55 )
) == V_38 ) {
F_35 ( V_56 , V_8 ) ;
F_29 ( V_42 -> V_29 , NULL ) ;
}
return 0 ;
}
void F_36 ( struct V_40 * V_8 )
{
struct V_39 * V_42 = F_25 ( V_8 ) ;
struct V_28 * V_29 ;
if ( V_42 ) {
F_37 () ;
V_29 = F_38 ( V_42 -> V_29 ) ;
if ( V_29 && V_29 -> V_57 )
V_29 -> V_57 ( V_8 ) ;
F_39 () ;
}
}
void F_40 ( struct V_58 * V_33 )
{
F_41 ( & V_55 ) ;
F_42 ( & V_33 -> V_59 , & V_60 ) ;
F_43 ( & V_55 ) ;
}
void F_44 ( struct V_58 * V_33 )
{
F_41 ( & V_55 ) ;
F_45 ( & V_33 -> V_59 ) ;
F_43 ( & V_55 ) ;
}
struct V_58 *
F_46 ( const char * V_36 )
{
struct V_58 * V_61 ;
bool V_62 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_61 -> V_36 , V_36 ) ) {
V_62 = true ;
break;
}
}
F_39 () ;
return V_62 ? V_61 : NULL ;
}
struct V_58 *
F_48 ( const void * V_63 )
{
struct V_58 * V_61 ;
bool V_62 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_61 -> V_64 == V_63 ) {
V_62 = true ;
break;
}
}
F_39 () ;
return V_62 ? V_61 : NULL ;
}
int F_49 ( struct V_28 * V_38 )
{
int V_48 = 0 ;
struct V_28 * V_61 ;
struct V_32 * V_33 ;
unsigned int V_34 = F_8 ( & V_38 -> V_18 ) ;
F_50 ( V_38 -> V_65 == NULL ) ;
F_50 ( V_38 -> V_66 >= V_67 ) ;
F_50 ( strlen ( V_38 -> V_36 ) > V_68 - 1 ) ;
F_51 ( & V_69 ) ;
F_52 (cur, n, &nf_ct_helper_hash[h], hnode) {
if ( strncmp ( V_61 -> V_36 , V_38 -> V_36 , V_68 ) == 0 &&
V_61 -> V_18 . V_19 . V_20 == V_38 -> V_18 . V_19 . V_20 &&
V_61 -> V_18 . V_21 . V_22 == V_38 -> V_18 . V_21 . V_22 ) {
V_48 = - V_70 ;
goto V_6;
}
}
F_53 ( & V_38 -> V_71 , & V_72 [ V_34 ] ) ;
V_35 ++ ;
V_6:
F_54 ( & V_69 ) ;
return V_48 ;
}
static void F_55 ( struct V_28 * V_38 ,
struct V_1 * V_1 )
{
struct V_54 * V_34 ;
struct V_73 * exp ;
const struct V_32 * V_33 , * V_74 ;
const struct V_75 * V_76 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_77 ; V_37 ++ ) {
F_56 (exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct V_39 * V_42 = F_25 ( exp -> V_78 ) ;
if ( ( F_33 (
V_42 -> V_29 ,
F_34 ( & V_55 )
) == V_38 || exp -> V_29 == V_38 ) &&
F_57 ( & exp -> V_79 ) ) {
F_58 ( exp ) ;
F_59 ( exp ) ;
}
}
}
F_60 (h, nn, &net->ct.unconfirmed, hnnode)
F_31 ( V_34 , V_38 ) ;
for ( V_37 = 0 ; V_37 < V_1 -> V_8 . V_80 ; V_37 ++ ) {
F_60 (h, nn, &net->ct.hash[i], hnnode)
F_31 ( V_34 , V_38 ) ;
}
}
void F_61 ( struct V_28 * V_38 )
{
struct V_1 * V_1 ;
F_51 ( & V_69 ) ;
F_62 ( & V_38 -> V_71 ) ;
V_35 -- ;
F_54 ( & V_69 ) ;
F_63 () ;
F_64 () ;
F_41 ( & V_55 ) ;
F_65 (net)
F_55 ( V_38 , V_1 ) ;
F_43 ( & V_55 ) ;
F_66 () ;
}
int F_67 ( struct V_1 * V_1 )
{
int V_81 ;
V_1 -> V_8 . V_53 = false ;
V_1 -> V_8 . V_9 = V_82 ;
if ( F_68 ( V_1 , & V_83 ) ) {
V_27 = 1 ;
V_72 =
F_69 ( & V_27 , 0 ) ;
if ( ! V_72 )
return - V_15 ;
V_81 = F_70 ( & V_84 ) ;
if ( V_81 < 0 )
goto V_85;
}
V_81 = F_1 ( V_1 ) ;
if ( V_81 < 0 )
goto V_86;
return 0 ;
V_86:
if ( F_68 ( V_1 , & V_83 ) )
F_71 ( & V_84 ) ;
V_85:
F_72 ( V_72 , V_27 ) ;
return V_81 ;
}
void F_73 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
if ( F_68 ( V_1 , & V_83 ) ) {
F_71 ( & V_84 ) ;
F_72 ( V_72 , V_27 ) ;
}
}
