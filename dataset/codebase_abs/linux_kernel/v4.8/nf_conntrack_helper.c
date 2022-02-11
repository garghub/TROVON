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
if ( ! strcmp ( V_32 -> V_34 , V_34 ) &&
V_32 -> V_18 . V_19 . V_20 == V_20 &&
V_32 -> V_18 . V_21 . V_22 == V_22 )
return V_32 ;
}
}
return NULL ;
}
struct V_28 *
F_14 ( const char * V_34 , T_1 V_20 , T_2 V_22 )
{
struct V_28 * V_32 ;
V_32 = F_13 ( V_34 , V_20 , V_22 ) ;
#ifdef F_15
if ( V_32 == NULL ) {
if ( F_16 ( L_3 , V_34 ) == 0 )
V_32 = F_13 ( V_34 , V_20 , V_22 ) ;
}
#endif
if ( V_32 != NULL && ! F_17 ( V_32 -> V_36 ) )
V_32 = NULL ;
return V_32 ;
}
struct V_37 *
F_18 ( struct V_38 * V_8 ,
struct V_28 * V_29 , T_3 V_39 )
{
struct V_37 * V_40 ;
V_40 = F_19 ( V_8 , V_41 ,
V_29 -> V_42 , V_39 ) ;
if ( V_40 )
F_20 ( & V_40 -> V_43 ) ;
else
F_21 ( L_4 ) ;
return V_40 ;
}
int F_22 ( struct V_38 * V_8 , struct V_38 * V_44 ,
T_3 V_45 )
{
struct V_28 * V_29 = NULL ;
struct V_37 * V_40 ;
struct V_1 * V_1 = F_23 ( V_8 ) ;
int V_46 = 0 ;
if ( F_24 ( V_47 , & V_8 -> V_48 ) )
return 0 ;
if ( V_44 != NULL ) {
V_40 = F_25 ( V_44 ) ;
if ( V_40 != NULL ) {
V_29 = V_40 -> V_29 ;
F_26 ( V_47 , & V_8 -> V_48 ) ;
}
}
V_40 = F_25 ( V_8 ) ;
if ( V_1 -> V_8 . V_9 && V_29 == NULL ) {
V_29 = F_9 ( & V_8 -> V_49 [ V_50 ] . V_18 ) ;
if ( F_27 ( ! V_1 -> V_8 . V_51 && V_29 ) ) {
F_28 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_51 = true ;
}
}
if ( V_29 == NULL ) {
if ( V_40 )
F_29 ( V_40 -> V_29 , NULL ) ;
goto V_6;
}
if ( V_40 == NULL ) {
V_40 = F_18 ( V_8 , V_29 , V_45 ) ;
if ( V_40 == NULL ) {
V_46 = - V_15 ;
goto V_6;
}
} else {
struct V_28 * V_52 = F_30 ( V_40 -> V_29 ) ;
if ( V_52 && V_52 -> V_40 != V_29 -> V_40 ) {
F_29 ( V_40 -> V_29 , NULL ) ;
goto V_6;
}
}
F_31 ( V_40 -> V_29 , V_29 ) ;
V_6:
return V_46 ;
}
static inline int F_32 ( struct V_53 * V_35 ,
const struct V_28 * V_36 )
{
struct V_38 * V_8 = F_33 ( V_35 ) ;
struct V_37 * V_40 = F_25 ( V_8 ) ;
if ( V_40 && F_34 ( V_40 -> V_29 ) == V_36 ) {
F_35 ( V_54 , V_8 ) ;
F_29 ( V_40 -> V_29 , NULL ) ;
}
return 0 ;
}
void F_36 ( struct V_38 * V_8 )
{
struct V_37 * V_40 = F_25 ( V_8 ) ;
struct V_28 * V_29 ;
if ( V_40 ) {
F_37 () ;
V_29 = F_30 ( V_40 -> V_29 ) ;
if ( V_29 && V_29 -> V_55 )
V_29 -> V_55 ( V_8 ) ;
F_38 () ;
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
F_37 () ;
F_46 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_61 -> V_34 , V_34 ) ) {
V_62 = true ;
break;
}
}
F_38 () ;
return V_62 ? V_61 : NULL ;
}
struct V_56 *
F_47 ( const void * V_63 )
{
struct V_56 * V_61 ;
bool V_62 = false ;
F_37 () ;
F_46 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_61 -> V_64 == V_63 ) {
V_62 = true ;
break;
}
}
F_38 () ;
return V_62 ? V_61 : NULL ;
}
void F_48 ( struct V_65 * V_66 , const struct V_38 * V_8 ,
const char * V_67 , ... )
{
const struct V_37 * V_40 ;
const struct V_28 * V_29 ;
struct V_68 V_69 ;
T_4 args ;
va_start ( args , V_67 ) ;
V_69 . V_67 = V_67 ;
V_69 . V_70 = & args ;
V_40 = F_25 ( V_8 ) ;
V_29 = F_30 ( V_40 -> V_29 ) ;
F_49 ( F_23 ( V_8 ) , F_50 ( V_8 ) , 0 , V_66 , NULL , NULL , NULL ,
L_9 , V_29 -> V_34 , & V_69 ) ;
va_end ( args ) ;
}
int F_51 ( struct V_28 * V_36 )
{
struct V_30 V_31 = { . V_19 . V_25 . V_26 = F_10 ( 0xFFFF ) } ;
unsigned int V_32 = F_8 ( & V_36 -> V_18 ) ;
struct V_28 * V_61 ;
int V_46 = 0 ;
F_52 ( V_36 -> V_71 == NULL ) ;
F_52 ( V_36 -> V_72 >= V_73 ) ;
F_52 ( strlen ( V_36 -> V_34 ) > V_74 - 1 ) ;
F_53 ( & V_75 ) ;
F_54 (cur, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( & V_61 -> V_18 , & V_36 -> V_18 , & V_31 ) ) {
V_46 = - V_76 ;
goto V_6;
}
}
F_55 ( & V_36 -> V_77 , & V_78 [ V_32 ] ) ;
V_33 ++ ;
V_6:
F_56 ( & V_75 ) ;
return V_46 ;
}
static void F_57 ( struct V_28 * V_36 ,
struct V_1 * V_1 )
{
struct V_53 * V_32 ;
const struct V_79 * V_80 ;
int V_81 ;
F_58 (cpu) {
struct V_82 * V_83 = F_59 ( V_1 -> V_8 . V_84 , V_81 ) ;
F_40 ( & V_83 -> V_85 ) ;
F_60 (h, nn, &pcpu->unconfirmed, hnnode)
F_32 ( V_32 , V_36 ) ;
F_42 ( & V_83 -> V_85 ) ;
}
}
void F_61 ( struct V_28 * V_36 )
{
struct V_53 * V_32 ;
struct V_86 * exp ;
const struct V_87 * V_88 ;
const struct V_79 * V_80 ;
unsigned int V_89 ;
T_5 * V_85 ;
struct V_1 * V_1 ;
unsigned int V_35 ;
F_53 ( & V_75 ) ;
F_62 ( & V_36 -> V_77 ) ;
V_33 -- ;
F_56 ( & V_75 ) ;
F_63 () ;
F_40 ( & V_58 ) ;
for ( V_35 = 0 ; V_35 < V_90 ; V_35 ++ ) {
F_64 (exp, next,
&nf_ct_expect_hash[i], hnode) {
struct V_37 * V_40 = F_25 ( exp -> V_91 ) ;
if ( ( F_65 (
V_40 -> V_29 ,
F_66 ( & V_58 )
) == V_36 || exp -> V_29 == V_36 ) &&
F_67 ( & exp -> V_92 ) ) {
F_68 ( exp ) ;
F_69 ( exp ) ;
}
}
}
F_42 ( & V_58 ) ;
F_70 () ;
F_71 (net)
F_57 ( V_36 , V_1 ) ;
F_72 () ;
F_73 () ;
V_93:
V_89 = V_94 ;
for ( V_35 = 0 ; V_35 < V_89 ; V_35 ++ ) {
V_85 = & V_95 [ V_35 % V_96 ] ;
F_74 ( V_85 ) ;
if ( V_89 != V_94 ) {
F_75 ( V_85 ) ;
goto V_93;
}
F_60 (h, nn, &nf_conntrack_hash[i], hnnode)
F_32 ( V_32 , V_36 ) ;
F_75 ( V_85 ) ;
}
F_76 () ;
}
void F_77 ( struct V_28 * V_29 ,
T_1 V_20 , T_1 V_22 , const char * V_34 ,
T_1 V_97 , T_1 V_98 , T_6 V_99 ,
const struct V_100 * V_101 ,
T_6 V_72 , T_6 V_42 ,
int (* V_40)( struct V_65 * V_66 , unsigned int V_102 ,
struct V_38 * V_8 ,
enum V_103 V_104 ) ,
int (* F_78)( struct V_105 * V_106 ,
struct V_38 * V_8 ) ,
struct V_107 * V_107 )
{
V_29 -> V_18 . V_19 . V_20 = V_20 ;
V_29 -> V_18 . V_21 . V_22 = V_22 ;
V_29 -> V_18 . V_19 . V_25 . V_26 = F_10 ( V_98 ) ;
V_29 -> V_71 = V_101 ;
V_29 -> V_72 = V_72 ;
V_29 -> V_42 = V_42 ;
V_29 -> V_40 = V_40 ;
V_29 -> F_78 = F_78 ;
V_29 -> V_36 = V_107 ;
if ( V_98 == V_97 )
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_10 , V_34 ) ;
else
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_11 , V_34 , V_99 ) ;
}
int F_79 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
unsigned int V_35 ;
int V_108 = 0 ;
for ( V_35 = 0 ; V_35 < V_57 ; V_35 ++ ) {
V_108 = F_51 ( & V_29 [ V_35 ] ) ;
if ( V_108 < 0 )
goto V_108;
}
return V_108 ;
V_108:
if ( V_35 > 0 )
F_80 ( V_29 , V_35 ) ;
return V_108 ;
}
void F_80 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
while ( V_57 -- > 0 )
F_61 ( & V_29 [ V_57 ] ) ;
}
int F_81 ( struct V_1 * V_1 )
{
V_1 -> V_8 . V_51 = false ;
V_1 -> V_8 . V_9 = V_109 ;
return F_1 ( V_1 ) ;
}
void F_82 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
int F_83 ( void )
{
int V_46 ;
V_27 = 1 ;
V_78 =
F_84 ( & V_27 , 0 ) ;
if ( ! V_78 )
return - V_15 ;
V_46 = F_85 ( & V_110 ) ;
if ( V_46 < 0 ) {
F_4 ( L_12 ) ;
goto V_111;
}
return 0 ;
V_111:
F_86 ( V_78 , V_27 ) ;
return V_46 ;
}
void F_87 ( void )
{
F_88 ( & V_110 ) ;
F_86 ( V_78 , V_27 ) ;
}
