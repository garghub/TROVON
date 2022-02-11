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
F_17 ( V_27 -> V_13 , V_13 ) ;
V_35:
return V_32 ;
}
static inline int F_18 ( struct V_37 * V_21 ,
const struct V_12 * V_22 )
{
struct V_24 * V_25 = F_19 ( V_21 ) ;
struct V_23 * V_27 = F_16 ( V_25 ) ;
if ( V_27 && F_20 (
V_27 -> V_13 ,
F_21 ( & V_38 )
) == V_22 ) {
F_22 ( V_39 , V_25 ) ;
F_17 ( V_27 -> V_13 , NULL ) ;
}
return 0 ;
}
void F_23 ( struct V_24 * V_25 )
{
struct V_23 * V_27 = F_16 ( V_25 ) ;
struct V_12 * V_13 ;
if ( V_27 ) {
F_24 () ;
V_13 = F_25 ( V_27 -> V_13 ) ;
if ( V_13 && V_13 -> V_40 )
V_13 -> V_40 ( V_25 ) ;
F_26 () ;
}
}
int F_27 ( struct V_12 * V_22 )
{
unsigned int V_18 = F_1 ( & V_22 -> V_2 ) ;
F_28 ( V_22 -> V_41 == NULL ) ;
F_28 ( V_22 -> V_42 >= V_43 ) ;
F_28 ( strlen ( V_22 -> V_20 ) > V_44 - 1 ) ;
F_29 ( & V_45 ) ;
F_30 ( & V_22 -> V_46 , & V_47 [ V_18 ] ) ;
V_19 ++ ;
F_31 ( & V_45 ) ;
return 0 ;
}
static void F_32 ( struct V_12 * V_22 ,
struct V_48 * V_48 )
{
struct V_37 * V_18 ;
struct V_49 * exp ;
const struct V_16 * V_17 , * V_50 ;
const struct V_51 * V_52 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_53 ; V_21 ++ ) {
F_33 (exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct V_23 * V_27 = F_16 ( exp -> V_54 ) ;
if ( ( F_20 (
V_27 -> V_13 ,
F_21 ( & V_38 )
) == V_22 || exp -> V_13 == V_22 ) &&
F_34 ( & exp -> V_55 ) ) {
F_35 ( exp ) ;
F_36 ( exp ) ;
}
}
}
F_37 (h, nn, &net->ct.unconfirmed, hnnode)
F_18 ( V_18 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_48 -> V_25 . V_56 ; V_21 ++ ) {
F_37 (h, nn, &net->ct.hash[i], hnnode)
F_18 ( V_18 , V_22 ) ;
}
}
void F_38 ( struct V_12 * V_22 )
{
struct V_48 * V_48 ;
F_29 ( & V_45 ) ;
F_39 ( & V_22 -> V_46 ) ;
V_19 -- ;
F_31 ( & V_45 ) ;
F_40 () ;
F_41 () ;
F_42 ( & V_38 ) ;
F_43 (net)
F_32 ( V_22 , V_48 ) ;
F_44 ( & V_38 ) ;
F_45 () ;
}
int F_46 ( void )
{
int V_57 ;
V_11 = 1 ;
V_47 = F_47 ( & V_11 , 0 ) ;
if ( ! V_47 )
return - V_36 ;
V_57 = F_48 ( & V_58 ) ;
if ( V_57 < 0 )
goto V_59;
return 0 ;
V_59:
F_49 ( V_47 , V_11 ) ;
return V_57 ;
}
void F_50 ( void )
{
F_51 ( & V_58 ) ;
F_49 ( V_47 , V_11 ) ;
}
