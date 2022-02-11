static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) ,
V_5 ) ;
if ( ! V_3 )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
V_1 -> V_8 . V_10 =
F_3 ( V_1 , L_1 , V_3 ) ;
if ( ! V_1 -> V_8 . V_10 ) {
F_4 ( L_2 ) ;
goto V_11;
}
return 0 ;
V_11:
F_5 ( V_3 ) ;
V_6:
return - V_12 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_10 -> V_13 ;
F_7 ( V_1 -> V_8 . V_10 ) ;
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
}
static unsigned int F_8 ( const struct V_14 * V_15 )
{
return ( ( ( V_15 -> V_16 . V_17 << 8 ) | V_15 -> V_18 . V_19 ) ^
( V_20 V_21 ) V_15 -> V_16 . V_22 . V_23 ) % V_24 ;
}
static struct V_25 *
F_9 ( const struct V_14 * V_15 )
{
struct V_25 * V_26 ;
struct V_27 V_28 = { . V_16 . V_22 . V_23 = F_10 ( 0xFFFF ) } ;
struct V_29 * V_30 ;
unsigned int V_31 ;
if ( ! V_32 )
return NULL ;
V_31 = F_8 ( V_15 ) ;
F_11 (helper, n, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( V_15 , & V_26 -> V_15 , & V_28 ) )
return V_26 ;
}
return NULL ;
}
struct V_25 *
F_13 ( const char * V_33 , T_1 V_17 , T_2 V_19 )
{
struct V_25 * V_31 ;
struct V_29 * V_30 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ ) {
F_11 (h, n, &nf_ct_helper_hash[i], hnode) {
if ( ! strcmp ( V_31 -> V_33 , V_33 ) &&
V_31 -> V_15 . V_16 . V_17 == V_17 &&
V_31 -> V_15 . V_18 . V_19 == V_19 )
return V_31 ;
}
}
return NULL ;
}
struct V_25 *
F_14 ( const char * V_33 , T_1 V_17 , T_2 V_19 )
{
struct V_25 * V_31 ;
V_31 = F_13 ( V_33 , V_17 , V_19 ) ;
#ifdef F_15
if ( V_31 == NULL ) {
if ( F_16 ( L_3 , V_33 ) == 0 )
V_31 = F_13 ( V_33 , V_17 , V_19 ) ;
}
#endif
if ( V_31 != NULL && ! F_17 ( V_31 -> V_35 ) )
V_31 = NULL ;
return V_31 ;
}
struct V_36 * F_18 ( struct V_37 * V_8 , T_3 V_38 )
{
struct V_36 * V_39 ;
V_39 = F_19 ( V_8 , V_40 , V_38 ) ;
if ( V_39 )
F_20 ( & V_39 -> V_41 ) ;
else
F_21 ( L_4 ) ;
return V_39 ;
}
int F_22 ( struct V_37 * V_8 , struct V_37 * V_42 ,
T_3 V_43 )
{
struct V_25 * V_26 = NULL ;
struct V_36 * V_39 ;
struct V_1 * V_1 = F_23 ( V_8 ) ;
int V_44 = 0 ;
if ( F_24 ( V_45 , & V_8 -> V_46 ) )
return 0 ;
if ( V_42 != NULL ) {
V_39 = F_25 ( V_42 ) ;
if ( V_39 != NULL ) {
V_26 = V_39 -> V_26 ;
F_26 ( V_45 , & V_8 -> V_46 ) ;
}
}
V_39 = F_25 ( V_8 ) ;
if ( V_1 -> V_8 . V_9 && V_26 == NULL ) {
V_26 = F_9 ( & V_8 -> V_47 [ V_48 ] . V_15 ) ;
if ( F_27 ( ! V_1 -> V_8 . V_49 && V_26 ) ) {
F_28 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_49 = true ;
}
}
if ( V_26 == NULL ) {
if ( V_39 )
F_29 ( V_39 -> V_26 , NULL ) ;
goto V_6;
}
if ( V_39 == NULL ) {
V_39 = F_18 ( V_8 , V_43 ) ;
if ( V_39 == NULL ) {
V_44 = - V_12 ;
goto V_6;
}
} else {
memset ( & V_39 -> V_39 , 0 , sizeof( V_39 -> V_39 ) ) ;
}
F_30 ( V_39 -> V_26 , V_26 ) ;
V_6:
return V_44 ;
}
static inline int F_31 ( struct V_50 * V_34 ,
const struct V_25 * V_35 )
{
struct V_37 * V_8 = F_32 ( V_34 ) ;
struct V_36 * V_39 = F_25 ( V_8 ) ;
if ( V_39 && F_33 (
V_39 -> V_26 ,
F_34 ( & V_51 )
) == V_35 ) {
F_35 ( V_52 , V_8 ) ;
F_29 ( V_39 -> V_26 , NULL ) ;
}
return 0 ;
}
void F_36 ( struct V_37 * V_8 )
{
struct V_36 * V_39 = F_25 ( V_8 ) ;
struct V_25 * V_26 ;
if ( V_39 ) {
F_37 () ;
V_26 = F_38 ( V_39 -> V_26 ) ;
if ( V_26 && V_26 -> V_53 )
V_26 -> V_53 ( V_8 ) ;
F_39 () ;
}
}
void F_40 ( struct V_54 * V_30 )
{
F_41 ( & V_51 ) ;
F_42 ( & V_30 -> V_55 , & V_56 ) ;
F_43 ( & V_51 ) ;
}
void F_44 ( struct V_54 * V_30 )
{
F_41 ( & V_51 ) ;
F_45 ( & V_30 -> V_55 ) ;
F_43 ( & V_51 ) ;
}
struct V_54 *
F_46 ( const char * V_33 )
{
struct V_54 * V_57 ;
bool V_58 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_57 -> V_33 , V_33 ) ) {
V_58 = true ;
break;
}
}
F_39 () ;
return V_58 ? V_57 : NULL ;
}
struct V_54 *
F_48 ( const void * V_59 )
{
struct V_54 * V_57 ;
bool V_58 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_57 -> V_60 == V_59 ) {
V_58 = true ;
break;
}
}
F_39 () ;
return V_58 ? V_57 : NULL ;
}
int F_49 ( struct V_25 * V_35 )
{
unsigned int V_31 = F_8 ( & V_35 -> V_15 ) ;
F_50 ( V_35 -> V_61 == NULL ) ;
F_50 ( V_35 -> V_62 >= V_63 ) ;
F_50 ( strlen ( V_35 -> V_33 ) > V_64 - 1 ) ;
F_51 ( & V_65 ) ;
F_52 ( & V_35 -> V_66 , & V_67 [ V_31 ] ) ;
V_32 ++ ;
F_53 ( & V_65 ) ;
return 0 ;
}
static void F_54 ( struct V_25 * V_35 ,
struct V_1 * V_1 )
{
struct V_50 * V_31 ;
struct V_68 * exp ;
const struct V_29 * V_30 , * V_69 ;
const struct V_70 * V_71 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_72 ; V_34 ++ ) {
F_55 (exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct V_36 * V_39 = F_25 ( exp -> V_73 ) ;
if ( ( F_33 (
V_39 -> V_26 ,
F_34 ( & V_51 )
) == V_35 || exp -> V_26 == V_35 ) &&
F_56 ( & exp -> V_74 ) ) {
F_57 ( exp ) ;
F_58 ( exp ) ;
}
}
}
F_59 (h, nn, &net->ct.unconfirmed, hnnode)
F_31 ( V_31 , V_35 ) ;
for ( V_34 = 0 ; V_34 < V_1 -> V_8 . V_75 ; V_34 ++ ) {
F_59 (h, nn, &net->ct.hash[i], hnnode)
F_31 ( V_31 , V_35 ) ;
}
}
void F_60 ( struct V_25 * V_35 )
{
struct V_1 * V_1 ;
F_51 ( & V_65 ) ;
F_61 ( & V_35 -> V_66 ) ;
V_32 -- ;
F_53 ( & V_65 ) ;
F_62 () ;
F_63 () ;
F_41 ( & V_51 ) ;
F_64 (net)
F_54 ( V_35 , V_1 ) ;
F_43 ( & V_51 ) ;
F_65 () ;
}
int F_66 ( struct V_1 * V_1 )
{
int V_76 ;
V_1 -> V_8 . V_49 = false ;
V_1 -> V_8 . V_9 = V_77 ;
if ( F_67 ( V_1 , & V_78 ) ) {
V_24 = 1 ;
V_67 =
F_68 ( & V_24 , 0 ) ;
if ( ! V_67 )
return - V_12 ;
V_76 = F_69 ( & V_79 ) ;
if ( V_76 < 0 )
goto V_80;
}
V_76 = F_1 ( V_1 ) ;
if ( V_76 < 0 )
goto V_81;
return 0 ;
V_81:
if ( F_67 ( V_1 , & V_78 ) )
F_70 ( & V_79 ) ;
V_80:
F_71 ( V_67 , V_24 ) ;
return V_76 ;
}
void F_72 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
if ( F_67 ( V_1 , & V_78 ) ) {
F_70 ( & V_79 ) ;
F_71 ( V_67 , V_24 ) ;
}
}
