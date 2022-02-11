static unsigned int F_1 ( const struct V_1 * V_2 )
{
return ( ( ( V_2 -> V_3 . V_4 << 8 ) | V_2 -> V_5 . V_6 ) ^
( V_7 V_8 ) V_2 -> V_3 . V_9 . V_10 ) % V_11 ;
}
static struct V_12 *
F_2 ( const struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_14 V_15 = { . V_3 . V_9 . V_10 = F_3 ( 0xFFFF ) } ;
struct V_16 * V_17 ;
unsigned int V_18 ;
if ( ! V_19 )
return NULL ;
V_18 = F_1 ( V_2 ) ;
F_4 (helper, n, &nf_ct_helper_hash[h], hnode) {
if ( F_5 ( V_2 , & V_13 -> V_2 , & V_15 ) )
return V_13 ;
}
return NULL ;
}
struct V_12 *
F_6 ( const char * V_20 , T_1 V_4 , T_2 V_6 )
{
struct V_12 * V_18 ;
struct V_16 * V_17 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_11 ; V_21 ++ ) {
F_4 (h, n, &nf_ct_helper_hash[i], hnode) {
if ( ! strcmp ( V_18 -> V_20 , V_20 ) &&
V_18 -> V_2 . V_3 . V_4 == V_4 &&
V_18 -> V_2 . V_5 . V_6 == V_6 )
return V_18 ;
}
}
return NULL ;
}
struct V_12 *
F_7 ( const char * V_20 , T_1 V_4 , T_2 V_6 )
{
struct V_12 * V_18 ;
V_18 = F_6 ( V_20 , V_4 , V_6 ) ;
#ifdef F_8
if ( V_18 == NULL ) {
if ( F_9 ( L_1 , V_20 ) == 0 )
V_18 = F_6 ( V_20 , V_4 , V_6 ) ;
}
#endif
if ( V_18 != NULL && ! F_10 ( V_18 -> V_22 ) )
V_18 = NULL ;
return V_18 ;
}
struct V_23 * F_11 ( struct V_24 * V_25 , T_3 V_26 )
{
struct V_23 * V_27 ;
V_27 = F_12 ( V_25 , V_28 , V_26 ) ;
if ( V_27 )
F_13 ( & V_27 -> V_29 ) ;
else
F_14 ( L_2 ) ;
return V_27 ;
}
int F_15 ( struct V_24 * V_25 , struct V_24 * V_30 ,
T_3 V_31 )
{
struct V_12 * V_13 = NULL ;
struct V_23 * V_27 ;
int V_32 = 0 ;
if ( V_30 != NULL ) {
V_27 = F_16 ( V_30 ) ;
if ( V_27 != NULL )
V_13 = V_27 -> V_13 ;
}
V_27 = F_16 ( V_25 ) ;
if ( V_13 == NULL )
V_13 = F_2 ( & V_25 -> V_33 [ V_34 ] . V_2 ) ;
if ( V_13 == NULL ) {
if ( V_27 )
F_17 ( V_27 -> V_13 , NULL ) ;
goto V_35;
}
if ( V_27 == NULL ) {
V_27 = F_11 ( V_25 , V_31 ) ;
if ( V_27 == NULL ) {
V_32 = - V_36 ;
goto V_35;
}
} else {
memset ( & V_27 -> V_27 , 0 , sizeof( V_27 -> V_27 ) ) ;
}
F_18 ( V_27 -> V_13 , V_13 ) ;
V_35:
return V_32 ;
}
static inline int F_19 ( struct V_37 * V_21 ,
const struct V_12 * V_22 )
{
struct V_24 * V_25 = F_20 ( V_21 ) ;
struct V_23 * V_27 = F_16 ( V_25 ) ;
if ( V_27 && F_21 (
V_27 -> V_13 ,
F_22 ( & V_38 )
) == V_22 ) {
F_23 ( V_39 , V_25 ) ;
F_17 ( V_27 -> V_13 , NULL ) ;
}
return 0 ;
}
void F_24 ( struct V_24 * V_25 )
{
struct V_23 * V_27 = F_16 ( V_25 ) ;
struct V_12 * V_13 ;
if ( V_27 ) {
F_25 () ;
V_13 = F_26 ( V_27 -> V_13 ) ;
if ( V_13 && V_13 -> V_40 )
V_13 -> V_40 ( V_25 ) ;
F_27 () ;
}
}
void F_28 ( struct V_41 * V_17 )
{
F_29 ( & V_38 ) ;
F_30 ( & V_17 -> V_42 , & V_43 ) ;
F_31 ( & V_38 ) ;
}
void F_32 ( struct V_41 * V_17 )
{
F_29 ( & V_38 ) ;
F_33 ( & V_17 -> V_42 ) ;
F_31 ( & V_38 ) ;
}
struct V_41 *
F_34 ( const char * V_20 )
{
struct V_41 * V_44 ;
bool V_45 = false ;
F_25 () ;
F_35 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_44 -> V_20 , V_20 ) ) {
V_45 = true ;
break;
}
}
F_27 () ;
return V_45 ? V_44 : NULL ;
}
struct V_41 *
F_36 ( const void * V_46 )
{
struct V_41 * V_44 ;
bool V_45 = false ;
F_25 () ;
F_35 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_44 -> V_47 == V_46 ) {
V_45 = true ;
break;
}
}
F_27 () ;
return V_45 ? V_44 : NULL ;
}
int F_37 ( struct V_12 * V_22 )
{
unsigned int V_18 = F_1 ( & V_22 -> V_2 ) ;
F_38 ( V_22 -> V_48 == NULL ) ;
F_38 ( V_22 -> V_49 >= V_50 ) ;
F_38 ( strlen ( V_22 -> V_20 ) > V_51 - 1 ) ;
F_39 ( & V_52 ) ;
F_40 ( & V_22 -> V_53 , & V_54 [ V_18 ] ) ;
V_19 ++ ;
F_41 ( & V_52 ) ;
return 0 ;
}
static void F_42 ( struct V_12 * V_22 ,
struct V_55 * V_55 )
{
struct V_37 * V_18 ;
struct V_56 * exp ;
const struct V_16 * V_17 , * V_57 ;
const struct V_58 * V_59 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_60 ; V_21 ++ ) {
F_43 (exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct V_23 * V_27 = F_16 ( exp -> V_61 ) ;
if ( ( F_21 (
V_27 -> V_13 ,
F_22 ( & V_38 )
) == V_22 || exp -> V_13 == V_22 ) &&
F_44 ( & exp -> V_62 ) ) {
F_45 ( exp ) ;
F_46 ( exp ) ;
}
}
}
F_47 (h, nn, &net->ct.unconfirmed, hnnode)
F_19 ( V_18 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_55 -> V_25 . V_63 ; V_21 ++ ) {
F_47 (h, nn, &net->ct.hash[i], hnnode)
F_19 ( V_18 , V_22 ) ;
}
}
void F_48 ( struct V_12 * V_22 )
{
struct V_55 * V_55 ;
F_39 ( & V_52 ) ;
F_49 ( & V_22 -> V_53 ) ;
V_19 -- ;
F_41 ( & V_52 ) ;
F_50 () ;
F_51 () ;
F_29 ( & V_38 ) ;
F_52 (net)
F_42 ( V_22 , V_55 ) ;
F_31 ( & V_38 ) ;
F_53 () ;
}
int F_54 ( void )
{
int V_64 ;
V_11 = 1 ;
V_54 = F_55 ( & V_11 , 0 ) ;
if ( ! V_54 )
return - V_36 ;
V_64 = F_56 ( & V_65 ) ;
if ( V_64 < 0 )
goto V_66;
return 0 ;
V_66:
F_57 ( V_54 , V_11 ) ;
return V_64 ;
}
void F_58 ( void )
{
F_59 ( & V_65 ) ;
F_57 ( V_54 , V_11 ) ;
}
