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
struct V_36 *
F_18 ( struct V_37 * V_8 ,
struct V_25 * V_26 , T_3 V_38 )
{
struct V_36 * V_39 ;
V_39 = F_19 ( V_8 , V_40 ,
V_26 -> V_41 , V_38 ) ;
if ( V_39 )
F_20 ( & V_39 -> V_42 ) ;
else
F_21 ( L_4 ) ;
return V_39 ;
}
int F_22 ( struct V_37 * V_8 , struct V_37 * V_43 ,
T_3 V_44 )
{
struct V_25 * V_26 = NULL ;
struct V_36 * V_39 ;
struct V_1 * V_1 = F_23 ( V_8 ) ;
int V_45 = 0 ;
if ( F_24 ( V_46 , & V_8 -> V_47 ) )
return 0 ;
if ( V_43 != NULL ) {
V_39 = F_25 ( V_43 ) ;
if ( V_39 != NULL ) {
V_26 = V_39 -> V_26 ;
F_26 ( V_46 , & V_8 -> V_47 ) ;
}
}
V_39 = F_25 ( V_8 ) ;
if ( V_1 -> V_8 . V_9 && V_26 == NULL ) {
V_26 = F_9 ( & V_8 -> V_48 [ V_49 ] . V_15 ) ;
if ( F_27 ( ! V_1 -> V_8 . V_50 && V_26 ) ) {
F_28 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_50 = true ;
}
}
if ( V_26 == NULL ) {
if ( V_39 )
F_29 ( V_39 -> V_26 , NULL ) ;
goto V_6;
}
if ( V_39 == NULL ) {
V_39 = F_18 ( V_8 , V_26 , V_44 ) ;
if ( V_39 == NULL ) {
V_45 = - V_12 ;
goto V_6;
}
} else {
if ( V_39 -> V_26 != V_26 ) {
F_29 ( V_39 -> V_26 , NULL ) ;
goto V_6;
}
}
F_30 ( V_39 -> V_26 , V_26 ) ;
V_6:
return V_45 ;
}
static inline int F_31 ( struct V_51 * V_34 ,
const struct V_25 * V_35 )
{
struct V_37 * V_8 = F_32 ( V_34 ) ;
struct V_36 * V_39 = F_25 ( V_8 ) ;
if ( V_39 && F_33 (
V_39 -> V_26 ,
F_34 ( & V_52 )
) == V_35 ) {
F_35 ( V_53 , V_8 ) ;
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
if ( V_26 && V_26 -> V_54 )
V_26 -> V_54 ( V_8 ) ;
F_39 () ;
}
}
void F_40 ( struct V_55 * V_30 )
{
F_41 ( & V_52 ) ;
F_42 ( & V_30 -> V_56 , & V_57 ) ;
F_43 ( & V_52 ) ;
}
void F_44 ( struct V_55 * V_30 )
{
F_41 ( & V_52 ) ;
F_45 ( & V_30 -> V_56 ) ;
F_43 ( & V_52 ) ;
}
struct V_55 *
F_46 ( const char * V_33 )
{
struct V_55 * V_58 ;
bool V_59 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_58 -> V_33 , V_33 ) ) {
V_59 = true ;
break;
}
}
F_39 () ;
return V_59 ? V_58 : NULL ;
}
struct V_55 *
F_48 ( const void * V_60 )
{
struct V_55 * V_58 ;
bool V_59 = false ;
F_37 () ;
F_47 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_58 -> V_61 == V_60 ) {
V_59 = true ;
break;
}
}
F_39 () ;
return V_59 ? V_58 : NULL ;
}
int F_49 ( struct V_25 * V_35 )
{
int V_45 = 0 ;
struct V_25 * V_58 ;
struct V_29 * V_30 ;
unsigned int V_31 = F_8 ( & V_35 -> V_15 ) ;
F_50 ( V_35 -> V_62 == NULL ) ;
F_50 ( V_35 -> V_63 >= V_64 ) ;
F_50 ( strlen ( V_35 -> V_33 ) > V_65 - 1 ) ;
F_51 ( & V_66 ) ;
F_52 (cur, n, &nf_ct_helper_hash[h], hnode) {
if ( strncmp ( V_58 -> V_33 , V_35 -> V_33 , V_65 ) == 0 &&
V_58 -> V_15 . V_16 . V_17 == V_35 -> V_15 . V_16 . V_17 &&
V_58 -> V_15 . V_18 . V_19 == V_35 -> V_15 . V_18 . V_19 ) {
V_45 = - V_67 ;
goto V_6;
}
}
F_53 ( & V_35 -> V_68 , & V_69 [ V_31 ] ) ;
V_32 ++ ;
V_6:
F_54 ( & V_66 ) ;
return V_45 ;
}
static void F_55 ( struct V_25 * V_35 ,
struct V_1 * V_1 )
{
struct V_51 * V_31 ;
struct V_70 * exp ;
const struct V_29 * V_30 , * V_71 ;
const struct V_72 * V_73 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ ) {
F_56 (exp, n, next,
&net->ct.expect_hash[i], hnode) {
struct V_36 * V_39 = F_25 ( exp -> V_75 ) ;
if ( ( F_33 (
V_39 -> V_26 ,
F_34 ( & V_52 )
) == V_35 || exp -> V_26 == V_35 ) &&
F_57 ( & exp -> V_76 ) ) {
F_58 ( exp ) ;
F_59 ( exp ) ;
}
}
}
F_60 (h, nn, &net->ct.unconfirmed, hnnode)
F_31 ( V_31 , V_35 ) ;
for ( V_34 = 0 ; V_34 < V_1 -> V_8 . V_77 ; V_34 ++ ) {
F_60 (h, nn, &net->ct.hash[i], hnnode)
F_31 ( V_31 , V_35 ) ;
}
}
void F_61 ( struct V_25 * V_35 )
{
struct V_1 * V_1 ;
F_51 ( & V_66 ) ;
F_62 ( & V_35 -> V_68 ) ;
V_32 -- ;
F_54 ( & V_66 ) ;
F_63 () ;
F_64 () ;
F_41 ( & V_52 ) ;
F_65 (net)
F_55 ( V_35 , V_1 ) ;
F_43 ( & V_52 ) ;
F_66 () ;
}
int F_67 ( struct V_1 * V_1 )
{
int V_78 ;
V_1 -> V_8 . V_50 = false ;
V_1 -> V_8 . V_9 = V_79 ;
if ( F_68 ( V_1 , & V_80 ) ) {
V_24 = 1 ;
V_69 =
F_69 ( & V_24 , 0 ) ;
if ( ! V_69 )
return - V_12 ;
V_78 = F_70 ( & V_81 ) ;
if ( V_78 < 0 )
goto V_82;
}
V_78 = F_1 ( V_1 ) ;
if ( V_78 < 0 )
goto V_83;
return 0 ;
V_83:
if ( F_68 ( V_1 , & V_80 ) )
F_71 ( & V_81 ) ;
V_82:
F_72 ( V_69 , V_24 ) ;
return V_78 ;
}
void F_73 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
if ( F_68 ( V_1 , & V_80 ) ) {
F_71 ( & V_81 ) ;
F_72 ( V_69 , V_24 ) ;
}
}
