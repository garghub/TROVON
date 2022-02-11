void F_1 ( struct V_1 * exp ,
T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_7 * V_7 = F_3 ( exp ) ;
F_4 ( ! V_5 ) ;
F_4 ( F_5 ( & exp -> V_8 ) ) ;
F_6 ( & exp -> V_9 ) ;
V_7 -> V_10 . V_11 -- ;
F_6 ( & exp -> V_12 ) ;
V_5 -> V_13 [ exp -> V_14 ] -- ;
F_7 ( V_15 , exp , V_2 , V_3 ) ;
F_8 ( exp ) ;
F_9 ( V_7 , V_16 ) ;
}
static void F_10 ( unsigned long V_17 )
{
struct V_1 * exp = ( void * ) V_17 ;
F_11 ( & V_18 ) ;
F_12 ( exp ) ;
F_13 ( & V_18 ) ;
F_8 ( exp ) ;
}
static unsigned int F_14 ( const struct V_7 * V_19 , const struct V_20 * V_21 )
{
unsigned int V_22 , V_23 ;
F_15 ( & V_24 , sizeof( V_24 ) ) ;
V_23 = V_24 ^ F_16 ( V_19 ) ;
V_22 = F_17 ( V_21 -> V_25 . V_26 . V_27 , F_18 ( V_21 -> V_25 . V_26 . V_27 ) ,
( ( ( V_21 -> V_25 . V_28 ^ V_21 -> V_29 . V_30 ) << 16 ) |
( V_31 V_32 ) V_21 -> V_25 . V_33 . V_27 ) ^ V_23 ) ;
return F_19 ( V_22 , V_34 ) ;
}
static bool
F_20 ( const struct V_20 * V_21 ,
const struct V_1 * V_35 ,
const struct V_36 * V_37 ,
const struct V_7 * V_7 )
{
return F_21 ( V_21 , & V_35 -> V_21 , & V_35 -> V_38 ) &&
F_22 ( V_7 , F_23 ( V_35 -> V_6 ) ) &&
F_24 ( V_35 -> V_6 , V_37 ) ;
}
bool F_25 ( struct V_1 * exp )
{
if ( F_26 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
F_8 ( exp ) ;
return true ;
}
return false ;
}
struct V_1 *
F_27 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 ;
unsigned int V_39 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_39 = F_14 ( V_7 , V_21 ) ;
F_28 (i, &nf_ct_expect_hash[h], hnode) {
if ( F_20 ( V_21 , V_35 , V_37 , V_7 ) )
return V_35 ;
}
return NULL ;
}
struct V_1 *
F_29 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 ;
F_30 () ;
V_35 = F_27 ( V_7 , V_37 , V_21 ) ;
if ( V_35 && ! F_31 ( & V_35 -> V_40 ) )
V_35 = NULL ;
F_32 () ;
return V_35 ;
}
struct V_1 *
F_33 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 , * exp = NULL ;
unsigned int V_39 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_39 = F_14 ( V_7 , V_21 ) ;
F_34 (i, &nf_ct_expect_hash[h], hnode) {
if ( ! ( V_35 -> V_41 & V_42 ) &&
F_20 ( V_21 , V_35 , V_37 , V_7 ) ) {
exp = V_35 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_35 ( exp -> V_6 ) )
return NULL ;
if ( F_36 ( F_37 ( exp -> V_6 ) ||
! F_38 ( & exp -> V_6 -> V_43 . V_40 ) ) )
return NULL ;
if ( exp -> V_41 & V_44 ) {
F_39 ( & exp -> V_40 ) ;
return exp ;
} else if ( F_26 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
return exp ;
}
F_40 ( exp -> V_6 ) ;
return NULL ;
}
void F_41 ( struct V_45 * V_10 )
{
struct V_4 * V_46 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_47 * V_48 ;
if ( ! V_46 )
return;
F_11 ( & V_18 ) ;
F_42 (exp, next, &help->expectations, lnode) {
F_25 ( exp ) ;
}
F_13 ( & V_18 ) ;
}
static inline int F_43 ( const struct V_1 * V_49 ,
const struct V_1 * V_50 )
{
struct V_51 V_52 ;
int V_53 ;
V_52 . V_29 . V_33 . V_27 = V_49 -> V_38 . V_29 . V_33 . V_27 & V_50 -> V_38 . V_29 . V_33 . V_27 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_52 . V_29 . V_26 . V_27 [ V_53 ] =
V_49 -> V_38 . V_29 . V_26 . V_27 [ V_53 ] & V_50 -> V_38 . V_29 . V_26 . V_27 [ V_53 ] ;
}
return F_21 ( & V_49 -> V_21 , & V_50 -> V_21 , & V_52 ) &&
F_22 ( F_23 ( V_49 -> V_6 ) , F_23 ( V_50 -> V_6 ) ) &&
F_24 ( V_49 -> V_6 , F_44 ( V_50 -> V_6 ) ) ;
}
static inline int F_45 ( const struct V_1 * V_49 ,
const struct V_1 * V_50 )
{
return V_49 -> V_6 == V_50 -> V_6 && V_49 -> V_14 == V_50 -> V_14 &&
F_46 ( & V_49 -> V_21 , & V_50 -> V_21 ) &&
F_47 ( & V_49 -> V_38 , & V_50 -> V_38 ) &&
F_22 ( F_23 ( V_49 -> V_6 ) , F_23 ( V_50 -> V_6 ) ) &&
F_24 ( V_49 -> V_6 , F_44 ( V_50 -> V_6 ) ) ;
}
void F_48 ( struct V_1 * exp )
{
F_11 ( & V_18 ) ;
F_25 ( exp ) ;
F_13 ( & V_18 ) ;
}
struct V_1 * F_49 ( struct V_45 * V_55 )
{
struct V_1 * V_56 ;
V_56 = F_50 ( V_57 , V_58 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_6 = V_55 ;
F_51 ( & V_56 -> V_40 , 1 ) ;
return V_56 ;
}
void F_52 ( struct V_1 * exp , unsigned int V_14 ,
T_2 V_59 ,
const union V_60 * V_61 ,
const union V_60 * V_62 ,
T_2 V_63 , const T_3 * V_29 , const T_3 * V_25 )
{
int V_64 ;
if ( V_59 == V_65 )
V_64 = 4 ;
else
V_64 = 16 ;
exp -> V_41 = 0 ;
exp -> V_14 = V_14 ;
exp -> V_66 = NULL ;
exp -> V_67 = NULL ;
exp -> V_21 . V_29 . V_30 = V_59 ;
exp -> V_21 . V_25 . V_28 = V_63 ;
if ( V_61 ) {
memcpy ( & exp -> V_21 . V_29 . V_26 , V_61 , V_64 ) ;
if ( sizeof( exp -> V_21 . V_29 . V_26 ) > V_64 )
memset ( ( void * ) & exp -> V_21 . V_29 . V_26 + V_64 , 0x00 ,
sizeof( exp -> V_21 . V_29 . V_26 ) - V_64 ) ;
memset ( & exp -> V_38 . V_29 . V_26 , 0xFF , V_64 ) ;
if ( sizeof( exp -> V_38 . V_29 . V_26 ) > V_64 )
memset ( ( void * ) & exp -> V_38 . V_29 . V_26 + V_64 , 0x00 ,
sizeof( exp -> V_38 . V_29 . V_26 ) - V_64 ) ;
} else {
memset ( & exp -> V_21 . V_29 . V_26 , 0x00 , sizeof( exp -> V_21 . V_29 . V_26 ) ) ;
memset ( & exp -> V_38 . V_29 . V_26 , 0x00 , sizeof( exp -> V_38 . V_29 . V_26 ) ) ;
}
if ( V_29 ) {
exp -> V_21 . V_29 . V_33 . V_27 = * V_29 ;
exp -> V_38 . V_29 . V_33 . V_27 = F_53 ( 0xFFFF ) ;
} else {
exp -> V_21 . V_29 . V_33 . V_27 = 0 ;
exp -> V_38 . V_29 . V_33 . V_27 = 0 ;
}
memcpy ( & exp -> V_21 . V_25 . V_26 , V_62 , V_64 ) ;
if ( sizeof( exp -> V_21 . V_25 . V_26 ) > V_64 )
memset ( ( void * ) & exp -> V_21 . V_25 . V_26 + V_64 , 0x00 ,
sizeof( exp -> V_21 . V_25 . V_26 ) - V_64 ) ;
exp -> V_21 . V_25 . V_33 . V_27 = * V_25 ;
#ifdef F_54
memset ( & exp -> V_68 , 0 , sizeof( exp -> V_68 ) ) ;
memset ( & exp -> V_69 , 0 , sizeof( exp -> V_69 ) ) ;
#endif
}
static void F_55 ( struct V_70 * V_71 )
{
struct V_1 * exp ;
exp = F_56 ( V_71 , struct V_1 , V_72 ) ;
F_57 ( V_57 , exp ) ;
}
void F_8 ( struct V_1 * exp )
{
if ( F_58 ( & exp -> V_40 ) )
F_59 ( & exp -> V_72 , F_55 ) ;
}
static void F_60 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_73 * V_67 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_39 = F_14 ( V_7 , & exp -> V_21 ) ;
F_61 ( 2 , & exp -> V_40 ) ;
F_62 ( & exp -> V_8 , F_10 ,
( unsigned long ) exp ) ;
V_67 = F_63 ( V_5 -> V_67 ,
F_64 ( & V_18 ) ) ;
if ( V_67 ) {
exp -> V_8 . V_74 = V_75 +
V_67 -> V_76 [ exp -> V_14 ] . V_8 * V_77 ;
}
F_65 ( & exp -> V_8 ) ;
F_66 ( & exp -> V_12 , & V_5 -> V_78 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_66 ( & exp -> V_9 , & V_79 [ V_39 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_9 ( V_7 , V_80 ) ;
}
static void F_67 ( struct V_45 * V_6 ,
struct V_1 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_81 = NULL ;
F_34 (exp, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_56 -> V_14 )
V_81 = exp ;
}
if ( V_81 )
F_25 ( V_81 ) ;
}
static inline int F_68 ( struct V_1 * V_82 )
{
const struct V_83 * V_84 ;
struct V_1 * V_35 ;
struct V_45 * V_6 = V_82 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_73 * V_67 ;
struct V_7 * V_7 = F_3 ( V_82 ) ;
struct V_47 * V_48 ;
unsigned int V_39 ;
int V_85 = 0 ;
if ( ! V_5 ) {
V_85 = - V_86 ;
goto V_87;
}
V_39 = F_14 ( V_7 , & V_82 -> V_21 ) ;
F_42 (i, next, &nf_ct_expect_hash[h], hnode) {
if ( F_45 ( V_35 , V_82 ) ) {
if ( F_25 ( V_35 ) )
break;
} else if ( F_43 ( V_35 , V_82 ) ) {
V_85 = - V_88 ;
goto V_87;
}
}
V_67 = F_63 ( V_5 -> V_67 ,
F_64 ( & V_18 ) ) ;
if ( V_67 ) {
V_84 = & V_67 -> V_76 [ V_82 -> V_14 ] ;
if ( V_84 -> V_89 &&
V_5 -> V_13 [ V_82 -> V_14 ] >= V_84 -> V_89 ) {
F_67 ( V_6 , V_82 ) ;
if ( V_5 -> V_13 [ V_82 -> V_14 ]
>= V_84 -> V_89 ) {
V_85 = - V_90 ;
goto V_87;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_91 ) {
F_69 ( L_1 ) ;
V_85 = - V_90 ;
}
V_87:
return V_85 ;
}
int F_70 ( struct V_1 * V_82 ,
T_1 V_2 , int V_3 )
{
int V_85 ;
F_11 ( & V_18 ) ;
V_85 = F_68 ( V_82 ) ;
if ( V_85 < 0 )
goto V_87;
F_60 ( V_82 ) ;
F_13 ( & V_18 ) ;
F_7 ( V_92 , V_82 , V_2 , V_3 ) ;
return 0 ;
V_87:
F_13 ( & V_18 ) ;
return V_85 ;
}
void F_71 ( bool (* F_72)( struct V_1 * V_93 , void * V_94 ) ,
void * V_94 )
{
struct V_1 * exp ;
const struct V_47 * V_48 ;
unsigned int V_35 ;
F_11 ( & V_18 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
F_42 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( F_72 ( exp , V_94 ) && F_26 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
F_8 ( exp ) ;
}
}
}
F_13 ( & V_18 ) ;
}
void F_73 ( struct V_7 * V_7 ,
bool (* F_72)( struct V_1 * V_93 , void * V_94 ) ,
void * V_94 ,
T_1 V_2 , int V_3 )
{
struct V_1 * exp ;
const struct V_47 * V_48 ;
unsigned int V_35 ;
F_11 ( & V_18 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
F_42 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_22 ( F_3 ( exp ) , V_7 ) )
continue;
if ( F_72 ( exp , V_94 ) && F_26 ( & exp -> V_8 ) ) {
F_1 ( exp , V_2 , V_3 ) ;
F_8 ( exp ) ;
}
}
}
F_13 ( & V_18 ) ;
}
static struct V_47 * F_74 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_99 ;
struct V_47 * V_19 ;
for ( V_98 -> V_100 = 0 ; V_98 -> V_100 < V_34 ; V_98 -> V_100 ++ ) {
V_19 = F_75 ( F_76 ( & V_79 [ V_98 -> V_100 ] ) ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
static struct V_47 * F_77 ( struct V_95 * V_96 ,
struct V_47 * V_71 )
{
struct V_97 * V_98 = V_96 -> V_99 ;
V_71 = F_75 ( F_78 ( V_71 ) ) ;
while ( V_71 == NULL ) {
if ( ++ V_98 -> V_100 >= V_34 )
return NULL ;
V_71 = F_75 ( F_76 ( & V_79 [ V_98 -> V_100 ] ) ) ;
}
return V_71 ;
}
static struct V_47 * F_79 ( struct V_95 * V_96 , T_4 V_101 )
{
struct V_47 * V_71 = F_74 ( V_96 ) ;
if ( V_71 )
while ( V_101 && ( V_71 = F_77 ( V_96 , V_71 ) ) )
V_101 -- ;
return V_101 ? NULL : V_71 ;
}
static void * F_80 ( struct V_95 * V_96 , T_4 * V_101 )
__acquires( T_5 )
{
F_30 () ;
return F_79 ( V_96 , * V_101 ) ;
}
static void * F_81 ( struct V_95 * V_96 , void * V_102 , T_4 * V_101 )
{
( * V_101 ) ++ ;
return F_77 ( V_96 , V_102 ) ;
}
static void F_82 ( struct V_95 * V_96 , void * V_102 )
__releases( T_5 )
{
F_32 () ;
}
static int F_83 ( struct V_95 * V_103 , void * V_102 )
{
struct V_1 * V_82 ;
struct V_73 * V_67 ;
struct V_47 * V_19 = V_102 ;
char * V_104 = L_2 ;
V_82 = F_84 ( V_19 , struct V_1 , V_9 ) ;
if ( V_82 -> V_8 . V_105 )
F_85 ( V_103 , L_3 , F_5 ( & V_82 -> V_8 )
? ( long ) ( V_82 -> V_8 . V_74 - V_75 ) / V_77 : 0 ) ;
else
F_86 ( V_103 , L_4 ) ;
F_85 ( V_103 , L_5 ,
V_82 -> V_21 . V_29 . V_30 ,
V_82 -> V_21 . V_25 . V_28 ) ;
F_87 ( V_103 , & V_82 -> V_21 ,
F_88 ( V_82 -> V_21 . V_29 . V_30 ) ,
F_89 ( V_82 -> V_21 . V_29 . V_30 ,
V_82 -> V_21 . V_25 . V_28 ) ) ;
if ( V_82 -> V_41 & V_44 ) {
F_86 ( V_103 , L_6 ) ;
V_104 = L_7 ;
}
if ( V_82 -> V_41 & V_42 ) {
F_85 ( V_103 , L_8 , V_104 ) ;
V_104 = L_7 ;
}
if ( V_82 -> V_41 & V_106 )
F_85 ( V_103 , L_9 , V_104 ) ;
V_67 = F_75 ( F_2 ( V_82 -> V_6 ) -> V_67 ) ;
if ( V_67 ) {
F_85 ( V_103 , L_10 , V_82 -> V_41 ? L_11 : L_2 , V_67 -> V_107 ) ;
if ( V_67 -> V_76 [ V_82 -> V_14 ] . V_107 [ 0 ] )
F_85 ( V_103 , L_12 ,
V_67 -> V_76 [ V_82 -> V_14 ] . V_107 ) ;
}
F_90 ( V_103 , '\n' ) ;
return 0 ;
}
static int F_91 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_92 ( V_108 , V_109 , & V_110 ,
sizeof( struct V_97 ) ) ;
}
static int F_93 ( struct V_7 * V_7 )
{
#ifdef F_94
struct V_111 * V_112 ;
T_6 V_113 ;
T_7 V_114 ;
V_112 = F_95 ( L_13 , 0440 , V_7 -> V_115 ,
& V_116 ) ;
if ( ! V_112 )
return - V_117 ;
V_113 = F_96 ( V_7 -> V_118 , 0 ) ;
V_114 = F_97 ( V_7 -> V_118 , 0 ) ;
if ( F_98 ( V_113 ) && F_99 ( V_114 ) )
F_100 ( V_112 , V_113 , V_114 ) ;
#endif
return 0 ;
}
static void F_101 ( struct V_7 * V_7 )
{
#ifdef F_94
F_102 ( L_13 , V_7 -> V_115 ) ;
#endif
}
int F_103 ( struct V_7 * V_7 )
{
V_7 -> V_10 . V_11 = 0 ;
return F_93 ( V_7 ) ;
}
void F_104 ( struct V_7 * V_7 )
{
F_101 ( V_7 ) ;
}
int F_105 ( void )
{
if ( ! V_34 ) {
V_34 = V_119 / 256 ;
if ( ! V_34 )
V_34 = 1 ;
}
V_91 = V_34 * 4 ;
V_57 = F_106 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_57 )
return - V_117 ;
V_79 = F_107 ( & V_34 , 0 ) ;
if ( ! V_79 ) {
F_108 ( V_57 ) ;
return - V_117 ;
}
return 0 ;
}
void F_109 ( void )
{
F_110 () ;
F_108 ( V_57 ) ;
F_111 ( V_79 , V_34 ) ;
}
