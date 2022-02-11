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
static int F_38 ( struct V_40 * V_8 , void * V_37 )
{
struct V_39 * V_42 = F_33 ( V_8 ) ;
if ( V_42 && F_39 ( V_42 -> V_29 ) == V_37 ) {
F_40 ( V_53 , V_8 ) ;
F_35 ( V_42 -> V_29 , NULL ) ;
}
return 0 ;
}
void F_41 ( struct V_40 * V_8 )
{
struct V_39 * V_42 = F_33 ( V_8 ) ;
struct V_28 * V_29 ;
if ( V_42 ) {
F_15 () ;
V_29 = F_36 ( V_42 -> V_29 ) ;
if ( V_29 && V_29 -> V_54 )
V_29 -> V_54 ( V_8 ) ;
F_17 () ;
}
}
void F_42 ( struct V_55 * V_56 )
{
F_43 ( & V_57 ) ;
F_44 ( & V_56 -> V_58 , & V_59 ) ;
F_45 ( & V_57 ) ;
}
void F_46 ( struct V_55 * V_56 )
{
F_43 ( & V_57 ) ;
F_47 ( & V_56 -> V_58 ) ;
F_45 ( & V_57 ) ;
}
struct V_55 *
F_48 ( const char * V_34 )
{
struct V_55 * V_60 ;
bool V_61 = false ;
F_49 (cur, &nf_ct_helper_expectfn_list, head) {
if ( ! strcmp ( V_60 -> V_34 , V_34 ) ) {
V_61 = true ;
break;
}
}
return V_61 ? V_60 : NULL ;
}
struct V_55 *
F_50 ( const void * V_62 )
{
struct V_55 * V_60 ;
bool V_61 = false ;
F_49 (cur, &nf_ct_helper_expectfn_list, head) {
if ( V_60 -> V_63 == V_62 ) {
V_61 = true ;
break;
}
}
return V_61 ? V_60 : NULL ;
}
void F_51 ( struct V_64 * V_65 , const struct V_40 * V_8 ,
const char * V_66 , ... )
{
const struct V_39 * V_42 ;
const struct V_28 * V_29 ;
struct V_67 V_68 ;
T_4 args ;
va_start ( args , V_66 ) ;
V_68 . V_66 = V_66 ;
V_68 . V_69 = & args ;
V_42 = F_33 ( V_8 ) ;
V_29 = F_36 ( V_42 -> V_29 ) ;
F_52 ( F_31 ( V_8 ) , F_53 ( V_8 ) , 0 , V_65 , NULL , NULL , NULL ,
L_9 , V_29 -> V_34 , & V_68 ) ;
va_end ( args ) ;
}
int F_54 ( struct V_28 * V_37 )
{
struct V_30 V_31 = { . V_19 . V_25 . V_26 = F_10 ( 0xFFFF ) } ;
unsigned int V_32 = F_8 ( & V_37 -> V_18 ) ;
struct V_28 * V_60 ;
int V_70 = 0 , V_35 ;
F_55 ( V_37 -> V_71 == NULL ) ;
F_55 ( V_37 -> V_72 >= V_73 ) ;
F_55 ( strlen ( V_37 -> V_34 ) > V_74 - 1 ) ;
if ( V_37 -> V_71 -> V_75 > V_76 )
return - V_77 ;
F_56 ( & V_78 ) ;
for ( V_35 = 0 ; V_35 < V_27 ; V_35 ++ ) {
F_57 (cur, &nf_ct_helper_hash[i], hnode) {
if ( ! strcmp ( V_60 -> V_34 , V_37 -> V_34 ) &&
( V_60 -> V_18 . V_19 . V_20 == V_36 ||
V_60 -> V_18 . V_19 . V_20 == V_37 -> V_18 . V_19 . V_20 ) &&
V_60 -> V_18 . V_21 . V_22 == V_37 -> V_18 . V_21 . V_22 ) {
V_70 = - V_79 ;
goto V_6;
}
}
}
if ( ! ( V_37 -> V_49 & V_80 ) ) {
F_57 (cur, &nf_ct_helper_hash[h], hnode) {
if ( F_12 ( & V_60 -> V_18 , & V_37 -> V_18 ,
& V_31 ) ) {
V_70 = - V_79 ;
goto V_6;
}
}
}
F_58 ( & V_37 -> V_38 , 1 ) ;
F_59 ( & V_37 -> V_81 , & V_82 [ V_32 ] ) ;
V_33 ++ ;
V_6:
F_60 ( & V_78 ) ;
return V_70 ;
}
static bool F_61 ( struct V_83 * exp , void * V_7 )
{
struct V_39 * V_42 = F_33 ( exp -> V_84 ) ;
const struct V_28 * V_37 = V_7 ;
const struct V_28 * V_85 ;
if ( exp -> V_29 == V_37 )
return true ;
V_85 = F_62 ( V_42 -> V_29 ,
F_63 ( & V_57 ) ) ;
return V_85 == V_37 ;
}
void F_64 ( struct V_28 * V_37 )
{
F_56 ( & V_78 ) ;
F_65 ( & V_37 -> V_81 ) ;
V_33 -- ;
F_60 ( & V_78 ) ;
F_66 () ;
F_67 ( F_61 , NULL ) ;
F_68 ( F_38 , V_37 ) ;
}
void F_69 ( struct V_28 * V_29 ,
T_1 V_20 , T_1 V_22 , const char * V_34 ,
T_1 V_86 , T_1 V_87 , T_5 V_88 ,
const struct V_89 * V_90 ,
T_5 V_72 ,
int (* V_42)( struct V_64 * V_65 , unsigned int V_91 ,
struct V_40 * V_8 ,
enum V_92 V_93 ) ,
int (* F_70)( struct V_94 * V_95 ,
struct V_40 * V_8 ) ,
struct V_96 * V_96 )
{
V_29 -> V_18 . V_19 . V_20 = V_20 ;
V_29 -> V_18 . V_21 . V_22 = V_22 ;
V_29 -> V_18 . V_19 . V_25 . V_26 = F_10 ( V_87 ) ;
V_29 -> V_71 = V_90 ;
V_29 -> V_72 = V_72 ;
V_29 -> V_42 = V_42 ;
V_29 -> F_70 = F_70 ;
V_29 -> V_37 = V_96 ;
if ( V_87 == V_86 )
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_10 , V_34 ) ;
else
snprintf ( V_29 -> V_34 , sizeof( V_29 -> V_34 ) , L_11 , V_34 , V_88 ) ;
}
int F_71 ( struct V_28 * V_29 ,
unsigned int V_56 )
{
unsigned int V_35 ;
int V_97 = 0 ;
for ( V_35 = 0 ; V_35 < V_56 ; V_35 ++ ) {
V_97 = F_54 ( & V_29 [ V_35 ] ) ;
if ( V_97 < 0 )
goto V_97;
}
return V_97 ;
V_97:
if ( V_35 > 0 )
F_72 ( V_29 , V_35 ) ;
return V_97 ;
}
void F_72 ( struct V_28 * V_29 ,
unsigned int V_56 )
{
while ( V_56 -- > 0 )
F_64 ( & V_29 [ V_56 ] ) ;
}
int F_73 ( struct V_1 * V_1 )
{
V_1 -> V_8 . V_45 = false ;
V_1 -> V_8 . V_9 = V_98 ;
return F_1 ( V_1 ) ;
}
void F_74 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
}
int F_75 ( void )
{
int V_70 ;
V_27 = 1 ;
V_82 =
F_76 ( & V_27 , 0 ) ;
if ( ! V_82 )
return - V_15 ;
V_70 = F_77 ( & V_99 ) ;
if ( V_70 < 0 ) {
F_4 ( L_12 ) ;
goto V_100;
}
return 0 ;
V_100:
F_78 ( V_82 , V_27 ) ;
return V_70 ;
}
void F_79 ( void )
{
F_80 ( & V_99 ) ;
F_78 ( V_82 , V_27 ) ;
}
