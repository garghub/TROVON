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
if ( V_32 != NULL && ! F_20 ( & V_32 -> V_38 ) ) {
F_21 ( V_32 -> V_37 ) ;
V_32 = NULL ;
}
F_17 () ;
return V_32 ;
}
void F_22 ( struct V_28 * V_29 )
{
F_23 ( & V_29 -> V_38 ) ;
F_21 ( V_29 -> V_37 ) ;
}
struct V_39 *
F_24 ( struct V_40 * V_8 ,
struct V_28 * V_29 , T_3 V_41 )
{
struct V_39 * V_42 ;
V_42 = F_25 ( V_8 , V_43 , V_41 ) ;
if ( V_42 )
F_26 ( & V_42 -> V_44 ) ;
else
F_27 ( L_4 ) ;
return V_42 ;
}
static struct V_28 *
F_28 ( struct V_40 * V_8 , struct V_1 * V_1 )
{
if ( ! V_1 -> V_8 . V_9 ) {
if ( V_1 -> V_8 . V_45 )
return NULL ;
if ( ! F_9 ( & V_8 -> V_46 [ V_47 ] . V_18 ) )
return NULL ;
F_29 ( L_5
L_6
L_7
L_8 ) ;
V_1 -> V_8 . V_45 = 1 ;
return NULL ;
}
return F_9 ( & V_8 -> V_46 [ V_47 ] . V_18 ) ;
}
int F_30 ( struct V_40 * V_8 , struct V_40 * V_48 ,
T_3 V_49 )
{
struct V_28 * V_29 = NULL ;
struct V_39 * V_42 ;
struct V_1 * V_1 = F_31 ( V_8 ) ;
if ( F_32 ( V_50 , & V_8 -> V_51 ) )
return 0 ;
if ( V_48 != NULL ) {
V_42 = F_33 ( V_48 ) ;
if ( V_42 != NULL ) {
V_29 = V_42 -> V_29 ;
F_34 ( V_50 , & V_8 -> V_51 ) ;
}
}
V_42 = F_33 ( V_8 ) ;
if ( V_29 == NULL ) {
V_29 = F_28 ( V_8 , V_1 ) ;
if ( V_29 == NULL ) {
if ( V_42 )
F_35 ( V_42 -> V_29 , NULL ) ;
return 0 ;
}
}
if ( V_42 == NULL ) {
V_42 = F_24 ( V_8 , V_29 , V_49 ) ;
if ( V_42 == NULL )
return - V_15 ;
} else {
struct V_28 * V_52 = F_36 ( V_42 -> V_29 ) ;
if ( V_52 && V_52 -> V_42 != V_29 -> V_42 ) {
F_35 ( V_42 -> V_29 , NULL ) ;
return 0 ;
}
}
F_37 ( V_42 -> V_29 , V_29 ) ;
return 0 ;
}
static inline int F_38 ( struct V_53 * V_35 ,
const struct V_28 * V_37 )
{
struct V_40 * V_8 = F_39 ( V_35 ) ;
struct V_39 * V_42 = F_33 ( V_8 ) ;
if ( V_42 && F_40 ( V_42 -> V_29 ) == V_37 ) {
F_41 ( V_54 , V_8 ) ;
F_35 ( V_42 -> V_29 , NULL ) ;
}
return 0 ;
}
void F_42 ( struct V_40 * V_8 )
{
struct V_39 * V_42 = F_33 ( V_8 ) ;
struct V_28 * V_29 ;
if ( V_42 ) {
F_15 () ;
V_29 = F_36 ( V_42 -> V_29 ) ;
if ( V_29 && V_29 -> V_55 )
V_29 -> V_55 ( V_8 ) ;
F_17 () ;
}
}
void F_43 ( struct V_56 * V_57 )
{
F_44 ( & V_58 ) ;
F_45 ( & V_57 -> V_59 , & V_60 ) ;
F_46 ( & V_58 ) ;
}
void F_47 ( struct V_56 * V_57 )
{
F_44 ( & V_58 ) ;
F_48 ( & V_57 -> V_59 ) ;
F_46 ( & V_58 ) ;
}
struct V_56 *
F_49 ( const char * V_34 )
{
struct V_56 * V_61 ;
bool V_62 = false ;
F_50 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_61 -> V_34 , V_34 ) ) {
V_62 = true ;
break;
}
}
return V_62 ? V_61 : NULL ;
}
struct V_56 *
F_51 ( const void * V_63 )
{
struct V_56 * V_61 ;
bool V_62 = false ;
F_50 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_61 -> V_64 == V_63 ) {
V_62 = true ;
break;
}
}
return V_62 ? V_61 : NULL ;
}
void F_52 ( struct V_65 * V_66 , const struct V_40 * V_8 ,
const char * V_67 , ... )
{
const struct V_39 * V_42 ;
const struct V_28 * V_29 ;
struct V_68 V_69 ;
T_4 args ;
va_start ( args , V_67 ) ;
V_69 . V_67 = V_67 ;
V_69 . V_70 = & args ;
V_42 = F_33 ( V_8 ) ;
V_29 = F_36 ( V_42 -> V_29 ) ;
F_53 ( F_31 ( V_8 ) , F_54 ( V_8 ) , 0 , V_66 , NULL , NULL , NULL ,
L_9 , V_29 -> V_34 , & V_69 ) ;
va_end ( args ) ;
}
int F_55 ( struct V_28 * V_37 )
{
struct V_30 V_31 = { . V_19 . V_25 . V_26 = F_10 ( 0xFFFF ) } ;
unsigned int V_32 = F_8 ( & V_37 -> V_18 ) ;
struct V_28 * V_61 ;
int V_71 = 0 , V_35 ;
F_56 ( V_37 -> V_72 == NULL ) ;
F_56 ( V_37 -> V_73 >= V_74 ) ;
F_56 ( strlen ( V_37 -> V_34 ) > V_75 - 1 ) ;
if ( V_37 -> V_72 -> V_76 > V_77 )
return - V_78 ;
F_57 ( & V_79 ) ;
for ( V_35 = 0 ; V_35 < V_27 ; V_35 ++ ) {
F_58 (cur, &nf_ct_helper_hash[i], hnode) {
if ( ! strcmp ( V_61 -> V_34 , V_37 -> V_34 ) &&
( V_61 -> V_18 . V_19 . V_20 == V_36 ||
V_61 -> V_18 . V_19 . V_20 == V_37 -> V_18 . V_19 . V_20 ) &&
V_61 -> V_18 . V_21 . V_22 == V_37 -> V_18 . V_21 . V_22 ) {
V_71 = - V_80 ;
goto V_6;
}
}
}
if ( ! ( V_37 -> V_49 & V_81 ) ) {
F_58 (cur, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( & V_61 -> V_18 , & V_37 -> V_18 ,
& V_31 ) ) {
V_71 = - V_80 ;
goto V_6;
}
}
}
F_59 ( & V_37 -> V_38 , 1 ) ;
F_60 ( & V_37 -> V_82 , & V_83 [ V_32 ] ) ;
V_33 ++ ;
V_6:
F_61 ( & V_79 ) ;
return V_71 ;
}
static void F_62 ( struct V_28 * V_37 ,
struct V_1 * V_1 )
{
struct V_53 * V_32 ;
const struct V_84 * V_85 ;
int V_86 ;
F_63 (cpu) {
struct V_87 * V_88 = F_64 ( V_1 -> V_8 . V_89 , V_86 ) ;
F_44 ( & V_88 -> V_90 ) ;
F_65 (h, nn, &pcpu->unconfirmed, hnnode)
F_38 ( V_32 , V_37 ) ;
F_46 ( & V_88 -> V_90 ) ;
}
}
void F_66 ( struct V_28 * V_37 )
{
struct V_53 * V_32 ;
struct V_91 * exp ;
const struct V_92 * V_93 ;
const struct V_84 * V_85 ;
unsigned int V_94 ;
T_5 * V_90 ;
struct V_1 * V_1 ;
unsigned int V_35 ;
F_57 ( & V_79 ) ;
F_67 ( & V_37 -> V_82 ) ;
V_33 -- ;
F_61 ( & V_79 ) ;
F_68 () ;
F_44 ( & V_58 ) ;
for ( V_35 = 0 ; V_35 < V_95 ; V_35 ++ ) {
F_69 (exp, next,
&nf_ct_expect_hash[i], hnode) {
struct V_39 * V_42 = F_33 ( exp -> V_96 ) ;
if ( ( F_70 (
V_42 -> V_29 ,
F_71 ( & V_58 )
) == V_37 || exp -> V_29 == V_37 ) )
F_72 ( exp ) ;
}
}
F_46 ( & V_58 ) ;
F_73 () ;
F_74 (net)
F_62 ( V_37 , V_1 ) ;
F_75 () ;
F_76 () ;
V_97:
V_94 = V_98 ;
for ( V_35 = 0 ; V_35 < V_94 ; V_35 ++ ) {
V_90 = & V_99 [ V_35 % V_100 ] ;
F_77 ( V_90 ) ;
if ( V_94 != V_98 ) {
F_78 ( V_90 ) ;
goto V_97;
}
F_65 (h, nn, &nf_conntrack_hash[i], hnnode)
F_38 ( V_32 , V_37 ) ;
F_78 ( V_90 ) ;
}
F_79 () ;
}
void F_80 ( struct V_28 * V_29 ,
T_1 V_20 , T_1 V_22 , const char * V_34 ,
T_1 V_101 , T_1 V_102 , T_6 V_103 ,
const struct V_104 * V_105 ,
T_6 V_73 ,
int (* V_42)( struct V_65 * V_66 , unsigned int V_106 ,
struct V_40 * V_8 ,
enum V_107 V_108 ) ,
int (* F_81)( struct V_109 * V_110 ,
struct V_40 * V_8 ) ,
struct V_111 * V_111 )
{
V_29 -> V_18 . V_19 . V_20 = V_20 ;
V_29 -> V_18 . V_21 . V_22 = V_22 ;
V_29 -> V_18 . V_19 . V_25 . V_26 = F_10 ( V_102 ) ;
V_29 -> V_72 = V_105 ;
V_29 -> V_73 = V_73 ;
V_29 -> V_42 = V_42 ;
V_29 -> F_81 = F_81 ;
V_29 -> V_37 = V_111 ;
if ( V_102 == V_101 )
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_10 , V_34 ) ;
else
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_11 , V_34 , V_103 ) ;
}
int F_82 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
unsigned int V_35 ;
int V_112 = 0 ;
for ( V_35 = 0 ; V_35 < V_57 ; V_35 ++ ) {
V_112 = F_55 ( & V_29 [ V_35 ] ) ;
if ( V_112 < 0 )
goto V_112;
}
return V_112 ;
V_112:
if ( V_35 > 0 )
F_83 ( V_29 , V_35 ) ;
return V_112 ;
}
void F_83 ( struct V_28 * V_29 ,
unsigned int V_57 )
{
while ( V_57 -- > 0 )
F_66 ( & V_29 [ V_57 ] ) ;
}
int F_84 ( struct V_1 * V_1 )
{
V_1 -> V_8 . V_45 = false ;
V_1 -> V_8 . V_9 = V_113 ;
return F_1 ( V_1 ) ;
}
void F_85 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
int F_86 ( void )
{
int V_71 ;
V_27 = 1 ;
V_83 =
F_87 ( & V_27 , 0 ) ;
if ( ! V_83 )
return - V_15 ;
V_71 = F_88 ( & V_114 ) ;
if ( V_71 < 0 ) {
F_4 ( L_12 ) ;
goto V_115;
}
return 0 ;
V_115:
F_89 ( V_83 , V_27 ) ;
return V_71 ;
}
void F_90 ( void )
{
F_91 ( & V_114 ) ;
F_89 ( V_83 , V_27 ) ;
}
