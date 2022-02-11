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
unsigned int V_32 ;
if ( ! V_33 )
return NULL ;
V_32 = F_8 ( V_18 ) ;
F_11 (helper, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( V_18 , & V_29 -> V_18 , & V_31 ) )
return V_29 ;
}
return NULL ;
}
struct V_28 *
F_13 ( const char * V_34 , T_1 V_20 , T_2 V_22 )
{
struct V_28 * V_32 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_27 ; V_35 ++ ) {
F_11 (h, &nf_ct_helper_hash[i], hnode) {
if ( strcmp ( V_32 -> V_34 , V_34 ) )
continue;
if ( V_32 -> V_18 . V_19 . V_20 != V_36 &&
V_32 -> V_18 . V_19 . V_20 != V_20 )
continue;
if ( V_32 -> V_18 . V_21 . V_22 == V_22 )
return V_32 ;
}
}
return NULL ;
}
struct V_28 *
F_14 ( const char * V_34 , T_1 V_20 , T_2 V_22 )
{
struct V_28 * V_32 ;
F_15 () ;
V_32 = F_13 ( V_34 , V_20 , V_22 ) ;
#ifdef F_16
if ( V_32 == NULL ) {
F_17 () ;
if ( F_18 ( L_3 , V_34 ) == 0 ) {
F_15 () ;
V_32 = F_13 ( V_34 , V_20 , V_22 ) ;
} else {
return V_32 ;
}
}
#endif
if ( V_32 != NULL && ! F_19 ( V_32 -> V_37 ) )
V_32 = NULL ;
F_17 () ;
return V_32 ;
}
struct V_38 *
F_20 ( struct V_39 * V_8 ,
struct V_28 * V_29 , T_3 V_40 )
{
struct V_38 * V_41 ;
V_41 = F_21 ( V_8 , V_42 ,
V_29 -> V_43 , V_40 ) ;
if ( V_41 )
F_22 ( & V_41 -> V_44 ) ;
else
F_23 ( L_4 ) ;
return V_41 ;
}
static struct V_28 *
F_24 ( struct V_39 * V_8 , struct V_1 * V_1 )
{
if ( ! V_1 -> V_8 . V_9 ) {
if ( V_1 -> V_8 . V_45 )
return NULL ;
if ( ! F_9 ( & V_8 -> V_46 [ V_47 ] . V_18 ) )
return NULL ;
F_25 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_45 = 1 ;
return NULL ;
}
return F_9 ( & V_8 -> V_46 [ V_47 ] . V_18 ) ;
}
int F_26 ( struct V_39 * V_8 , struct V_39 * V_48 ,
T_3 V_49 )
{
struct V_28 * V_29 = NULL ;
struct V_38 * V_41 ;
struct V_1 * V_1 = F_27 ( V_8 ) ;
if ( F_28 ( V_50 , & V_8 -> V_51 ) )
return 0 ;
if ( V_48 != NULL ) {
V_41 = F_29 ( V_48 ) ;
if ( V_41 != NULL ) {
V_29 = V_41 -> V_29 ;
F_30 ( V_50 , & V_8 -> V_51 ) ;
}
}
V_41 = F_29 ( V_8 ) ;
if ( V_29 == NULL ) {
V_29 = F_24 ( V_8 , V_1 ) ;
if ( V_29 == NULL ) {
if ( V_41 )
F_31 ( V_41 -> V_29 , NULL ) ;
return 0 ;
}
}
if ( V_41 == NULL ) {
V_41 = F_20 ( V_8 , V_29 , V_49 ) ;
if ( V_41 == NULL )
return - V_15 ;
} else {
struct V_28 * V_52 = F_32 ( V_41 -> V_29 ) ;
if ( V_52 && V_52 -> V_41 != V_29 -> V_41 ) {
F_31 ( V_41 -> V_29 , NULL ) ;
return 0 ;
}
}
F_33 ( V_41 -> V_29 , V_29 ) ;
return 0 ;
}
static inline int F_34 ( struct V_53 * V_35 ,
const struct V_28 * V_37 )
{
struct V_39 * V_8 = F_35 ( V_35 ) ;
struct V_38 * V_41 = F_29 ( V_8 ) ;
if ( V_41 && F_36 ( V_41 -> V_29 ) == V_37 ) {
F_37 ( V_54 , V_8 ) ;
F_31 ( V_41 -> V_29 , NULL ) ;
}
return 0 ;
}
void F_38 ( struct V_39 * V_8 )
{
struct V_38 * V_41 = F_29 ( V_8 ) ;
struct V_28 * V_29 ;
if ( V_41 ) {
F_15 () ;
V_29 = F_32 ( V_41 -> V_29 ) ;
if ( V_29 && V_29 -> V_55 )
V_29 -> V_55 ( V_8 ) ;
F_17 () ;
}
}
void F_39 ( struct V_56 * V_57 )
{
F_40 ( & V_58 ) ;
F_41 ( & V_57 -> V_59 , & V_60 ) ;
F_42 ( & V_58 ) ;
}
void F_43 ( struct V_56 * V_57 )
{
F_40 ( & V_58 ) ;
F_44 ( & V_57 -> V_59 ) ;
F_42 ( & V_58 ) ;
}
struct V_56 *
F_45 ( const char * V_34 )
{
struct V_56 * V_61 ;
bool V_62 = false ;
F_46 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_61 -> V_34 , V_34 ) ) {
V_62 = true ;
break;
}
}
return V_62 ? V_61 : NULL ;
}
struct V_56 *
F_47 ( const void * V_63 )
{
struct V_56 * V_61 ;
bool V_62 = false ;
F_46 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_61 -> V_64 == V_63 ) {
V_62 = true ;
break;
}
}
return V_62 ? V_61 : NULL ;
}
void F_48 ( struct V_65 * V_66 , const struct V_39 * V_8 ,
const char * V_67 , ... )
{
const struct V_38 * V_41 ;
const struct V_28 * V_29 ;
struct V_68 V_69 ;
T_4 args ;
va_start ( args , V_67 ) ;
V_69 . V_67 = V_67 ;
V_69 . V_70 = & args ;
V_41 = F_29 ( V_8 ) ;
V_29 = F_32 ( V_41 -> V_29 ) ;
F_49 ( F_27 ( V_8 ) , F_50 ( V_8 ) , 0 , V_66 , NULL , NULL , NULL ,
L_9 , V_29 -> V_34 , & V_69 ) ;
va_end ( args ) ;
}
int F_51 ( struct V_28 * V_37 )
{
struct V_30 V_31 = { . V_19 . V_25 . V_26 = F_10 ( 0xFFFF ) } ;
unsigned int V_32 = F_8 ( & V_37 -> V_18 ) ;
struct V_28 * V_61 ;
int V_71 = 0 ;
F_52 ( V_37 -> V_72 == NULL ) ;
F_52 ( V_37 -> V_73 >= V_74 ) ;
F_52 ( strlen ( V_37 -> V_34 ) > V_75 - 1 ) ;
F_53 ( & V_76 ) ;
F_54 (cur, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( & V_61 -> V_18 , & V_37 -> V_18 , & V_31 ) ) {
V_71 = - V_77 ;
goto V_6;
}
}
F_55 ( & V_37 -> V_78 , & V_79 [ V_32 ] ) ;
V_33 ++ ;
V_6:
F_56 ( & V_76 ) ;
return V_71 ;
}
static void F_57 ( struct V_28 * V_37 ,
struct V_1 * V_1 )
{
struct V_53 * V_32 ;
const struct V_80 * V_81 ;
int V_82 ;
F_58 (cpu) {
struct V_83 * V_84 = F_59 ( V_1 -> V_8 . V_85 , V_82 ) ;
F_40 ( & V_84 -> V_86 ) ;
F_60 (h, nn, &pcpu->unconfirmed, hnnode)
F_34 ( V_32 , V_37 ) ;
F_42 ( & V_84 -> V_86 ) ;
}
}
void F_61 ( struct V_28 * V_37 )
{
struct V_53 * V_32 ;
struct V_87 * exp ;
const struct V_88 * V_89 ;
const struct V_80 * V_81 ;
unsigned int V_90 ;
T_5 * V_86 ;
struct V_1 * V_1 ;
unsigned int V_35 ;
F_53 ( & V_76 ) ;
F_62 ( & V_37 -> V_78 ) ;
V_33 -- ;
F_56 ( & V_76 ) ;
F_63 () ;
F_40 ( & V_58 ) ;
for ( V_35 = 0 ; V_35 < V_91 ; V_35 ++ ) {
F_64 (exp, next,
&nf_ct_expect_hash[i], hnode) {
struct V_38 * V_41 = F_29 ( exp -> V_92 ) ;
if ( ( F_65 (
V_41 -> V_29 ,
F_66 ( & V_58 )
) == V_37 || exp -> V_29 == V_37 ) &&
F_67 ( & exp -> V_93 ) ) {
F_68 ( exp ) ;
F_69 ( exp ) ;
}
}
}
F_42 ( & V_58 ) ;
F_70 () ;
F_71 (net)
F_57 ( V_37 , V_1 ) ;
F_72 () ;
F_73 () ;
V_94:
V_90 = V_95 ;
for ( V_35 = 0 ; V_35 < V_90 ; V_35 ++ ) {
V_86 = & V_96 [ V_35 % V_97 ] ;
F_74 ( V_86 ) ;
if ( V_90 != V_95 ) {
F_75 ( V_86 ) ;
goto V_94;
}
F_60 (h, nn, &nf_conntrack_hash[i], hnnode)
F_34 ( V_32 , V_37 ) ;
F_75 ( V_86 ) ;
}
F_76 () ;
}
void F_77 ( struct V_28 * V_29 ,
T_1 V_20 , T_1 V_22 , const char * V_34 ,
T_1 V_98 , T_1 V_99 , T_6 V_100 ,
const struct V_101 * V_102 ,
T_6 V_73 , T_6 V_43 ,
int (* V_41)( struct V_65 * V_66 , unsigned int V_103 ,
struct V_39 * V_8 ,
enum V_104 V_105 ) ,
int (* F_78)( struct V_106 * V_107 ,
struct V_39 * V_8 ) ,
struct V_108 * V_108 )
{
V_29 -> V_18 . V_19 . V_20 = V_20 ;
V_29 -> V_18 . V_21 . V_22 = V_22 ;
V_29 -> V_18 . V_19 . V_25 . V_26 = F_10 ( V_99 ) ;
V_29 -> V_72 = V_102 ;
V_29 -> V_73 = V_73 ;
V_29 -> V_43 = V_43 ;
V_29 -> V_41 = V_41 ;
V_29 -> F_78 = F_78 ;
V_29 -> V_37 = V_108 ;
if ( V_99 == V_98 )
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_10 , V_34 ) ;
else
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_11 , V_34 , V_100 ) ;
}
int F_79 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
unsigned int V_35 ;
int V_109 = 0 ;
for ( V_35 = 0 ; V_35 < V_57 ; V_35 ++ ) {
V_109 = F_51 ( & V_29 [ V_35 ] ) ;
if ( V_109 < 0 )
goto V_109;
}
return V_109 ;
V_109:
if ( V_35 > 0 )
F_80 ( V_29 , V_35 ) ;
return V_109 ;
}
void F_80 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
while ( V_57 -- > 0 )
F_61 ( & V_29 [ V_57 ] ) ;
}
int F_81 ( struct V_1 * V_1 )
{
V_1 -> V_8 . V_45 = false ;
V_1 -> V_8 . V_9 = V_110 ;
return F_1 ( V_1 ) ;
}
void F_82 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
int F_83 ( void )
{
int V_71 ;
V_27 = 1 ;
V_79 =
F_84 ( & V_27 , 0 ) ;
if ( ! V_79 )
return - V_15 ;
V_71 = F_85 ( & V_111 ) ;
if ( V_71 < 0 ) {
F_4 ( L_12 ) ;
goto V_112;
}
return 0 ;
V_112:
F_86 ( V_79 , V_27 ) ;
return V_71 ;
}
void F_87 ( void )
{
F_88 ( & V_111 ) ;
F_86 ( V_79 , V_27 ) ;
}
