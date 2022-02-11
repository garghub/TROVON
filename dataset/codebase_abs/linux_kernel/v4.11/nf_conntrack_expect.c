void F_1 ( struct V_1 * exp ,
T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_7 * V_7 = F_3 ( exp ) ;
F_4 ( V_5 ) ;
F_4 ( ! F_5 ( & exp -> V_8 ) ) ;
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
struct V_1 *
F_25 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 ;
unsigned int V_39 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_39 = F_14 ( V_7 , V_21 ) ;
F_26 (i, &nf_ct_expect_hash[h], hnode) {
if ( F_20 ( V_21 , V_35 , V_37 , V_7 ) )
return V_35 ;
}
return NULL ;
}
struct V_1 *
F_27 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 ;
F_28 () ;
V_35 = F_25 ( V_7 , V_37 , V_21 ) ;
if ( V_35 && ! F_29 ( & V_35 -> V_40 ) )
V_35 = NULL ;
F_30 () ;
return V_35 ;
}
struct V_1 *
F_31 ( struct V_7 * V_7 ,
const struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
struct V_1 * V_35 , * exp = NULL ;
unsigned int V_39 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_39 = F_14 ( V_7 , V_21 ) ;
F_32 (i, &nf_ct_expect_hash[h], hnode) {
if ( ! ( V_35 -> V_41 & V_42 ) &&
F_20 ( V_21 , V_35 , V_37 , V_7 ) ) {
exp = V_35 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_33 ( exp -> V_6 ) )
return NULL ;
if ( F_34 ( F_35 ( exp -> V_6 ) ||
! F_29 ( & exp -> V_6 -> V_43 . V_40 ) ) )
return NULL ;
if ( exp -> V_41 & V_44 ) {
F_36 ( & exp -> V_40 ) ;
return exp ;
} else if ( F_37 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
return exp ;
}
F_38 ( exp -> V_6 ) ;
return NULL ;
}
void F_39 ( struct V_45 * V_10 )
{
struct V_4 * V_46 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_47 * V_48 ;
if ( ! V_46 )
return;
F_11 ( & V_18 ) ;
F_40 (exp, next, &help->expectations, lnode) {
if ( F_37 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
F_8 ( exp ) ;
}
}
F_13 ( & V_18 ) ;
}
static inline int F_41 ( const struct V_1 * V_49 ,
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
F_24 ( V_49 -> V_6 , F_42 ( V_50 -> V_6 ) ) ;
}
static inline int F_43 ( const struct V_1 * V_49 ,
const struct V_1 * V_50 )
{
return V_49 -> V_6 == V_50 -> V_6 && V_49 -> V_14 == V_50 -> V_14 &&
F_44 ( & V_49 -> V_21 , & V_50 -> V_21 ) &&
F_45 ( & V_49 -> V_38 , & V_50 -> V_38 ) &&
F_22 ( F_23 ( V_49 -> V_6 ) , F_23 ( V_50 -> V_6 ) ) &&
F_24 ( V_49 -> V_6 , F_42 ( V_50 -> V_6 ) ) ;
}
void F_46 ( struct V_1 * exp )
{
F_11 ( & V_18 ) ;
if ( F_37 ( & exp -> V_8 ) ) {
F_12 ( exp ) ;
F_8 ( exp ) ;
}
F_13 ( & V_18 ) ;
}
struct V_1 * F_47 ( struct V_45 * V_55 )
{
struct V_1 * V_56 ;
V_56 = F_48 ( V_57 , V_58 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_6 = V_55 ;
F_49 ( & V_56 -> V_40 , 1 ) ;
return V_56 ;
}
void F_50 ( struct V_1 * exp , unsigned int V_14 ,
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
exp -> V_38 . V_29 . V_33 . V_27 = F_51 ( 0xFFFF ) ;
} else {
exp -> V_21 . V_29 . V_33 . V_27 = 0 ;
exp -> V_38 . V_29 . V_33 . V_27 = 0 ;
}
memcpy ( & exp -> V_21 . V_25 . V_26 , V_62 , V_64 ) ;
if ( sizeof( exp -> V_21 . V_25 . V_26 ) > V_64 )
memset ( ( void * ) & exp -> V_21 . V_25 . V_26 + V_64 , 0x00 ,
sizeof( exp -> V_21 . V_25 . V_26 ) - V_64 ) ;
exp -> V_21 . V_25 . V_33 . V_27 = * V_25 ;
#ifdef F_52
memset ( & exp -> V_68 , 0 , sizeof( exp -> V_68 ) ) ;
memset ( & exp -> V_69 , 0 , sizeof( exp -> V_69 ) ) ;
#endif
}
static void F_53 ( struct V_70 * V_71 )
{
struct V_1 * exp ;
exp = F_54 ( V_71 , struct V_1 , V_72 ) ;
F_55 ( V_57 , exp ) ;
}
void F_8 ( struct V_1 * exp )
{
if ( F_56 ( & exp -> V_40 ) )
F_57 ( & exp -> V_72 , F_53 ) ;
}
static void F_58 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_73 * V_67 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_39 = F_14 ( V_7 , & exp -> V_21 ) ;
F_59 ( 2 , & exp -> V_40 ) ;
F_60 ( & exp -> V_12 , & V_5 -> V_74 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_60 ( & exp -> V_9 , & V_75 [ V_39 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_61 ( & exp -> V_8 , F_10 ,
( unsigned long ) exp ) ;
V_67 = F_62 ( V_5 -> V_67 ,
F_63 ( & V_18 ) ) ;
if ( V_67 ) {
exp -> V_8 . V_76 = V_77 +
V_67 -> V_78 [ exp -> V_14 ] . V_8 * V_79 ;
}
F_64 ( & exp -> V_8 ) ;
F_9 ( V_7 , V_80 ) ;
}
static void F_65 ( struct V_45 * V_6 ,
struct V_1 * V_56 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_81 = NULL ;
F_32 (exp, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_56 -> V_14 )
V_81 = exp ;
}
if ( V_81 && F_37 ( & V_81 -> V_8 ) ) {
F_12 ( V_81 ) ;
F_8 ( V_81 ) ;
}
}
static inline int F_66 ( struct V_1 * V_82 )
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
F_40 (i, next, &nf_ct_expect_hash[h], hnode) {
if ( F_43 ( V_35 , V_82 ) ) {
if ( F_37 ( & V_35 -> V_8 ) ) {
F_12 ( V_35 ) ;
F_8 ( V_35 ) ;
break;
}
} else if ( F_41 ( V_35 , V_82 ) ) {
V_85 = - V_88 ;
goto V_87;
}
}
V_67 = F_62 ( V_5 -> V_67 ,
F_63 ( & V_18 ) ) ;
if ( V_67 ) {
V_84 = & V_67 -> V_78 [ V_82 -> V_14 ] ;
if ( V_84 -> V_89 &&
V_5 -> V_13 [ V_82 -> V_14 ] >= V_84 -> V_89 ) {
F_65 ( V_6 , V_82 ) ;
if ( V_5 -> V_13 [ V_82 -> V_14 ]
>= V_84 -> V_89 ) {
V_85 = - V_90 ;
goto V_87;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_91 ) {
F_67 ( L_1 ) ;
V_85 = - V_90 ;
}
V_87:
return V_85 ;
}
int F_68 ( struct V_1 * V_82 ,
T_1 V_2 , int V_3 )
{
int V_85 ;
F_11 ( & V_18 ) ;
V_85 = F_66 ( V_82 ) ;
if ( V_85 < 0 )
goto V_87;
F_58 ( V_82 ) ;
F_13 ( & V_18 ) ;
F_7 ( V_92 , V_82 , V_2 , V_3 ) ;
return 0 ;
V_87:
F_13 ( & V_18 ) ;
return V_85 ;
}
static struct V_47 * F_69 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
struct V_47 * V_19 ;
for ( V_96 -> V_98 = 0 ; V_96 -> V_98 < V_34 ; V_96 -> V_98 ++ ) {
V_19 = F_70 ( F_71 ( & V_75 [ V_96 -> V_98 ] ) ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
static struct V_47 * F_72 ( struct V_93 * V_94 ,
struct V_47 * V_71 )
{
struct V_95 * V_96 = V_94 -> V_97 ;
V_71 = F_70 ( F_73 ( V_71 ) ) ;
while ( V_71 == NULL ) {
if ( ++ V_96 -> V_98 >= V_34 )
return NULL ;
V_71 = F_70 ( F_71 ( & V_75 [ V_96 -> V_98 ] ) ) ;
}
return V_71 ;
}
static struct V_47 * F_74 ( struct V_93 * V_94 , T_4 V_99 )
{
struct V_47 * V_71 = F_69 ( V_94 ) ;
if ( V_71 )
while ( V_99 && ( V_71 = F_72 ( V_94 , V_71 ) ) )
V_99 -- ;
return V_99 ? NULL : V_71 ;
}
static void * F_75 ( struct V_93 * V_94 , T_4 * V_99 )
__acquires( T_5 )
{
F_28 () ;
return F_74 ( V_94 , * V_99 ) ;
}
static void * F_76 ( struct V_93 * V_94 , void * V_100 , T_4 * V_99 )
{
( * V_99 ) ++ ;
return F_72 ( V_94 , V_100 ) ;
}
static void F_77 ( struct V_93 * V_94 , void * V_100 )
__releases( T_5 )
{
F_30 () ;
}
static int F_78 ( struct V_93 * V_101 , void * V_100 )
{
struct V_1 * V_82 ;
struct V_73 * V_67 ;
struct V_47 * V_19 = V_100 ;
char * V_102 = L_2 ;
V_82 = F_79 ( V_19 , struct V_1 , V_9 ) ;
if ( V_82 -> V_8 . V_103 )
F_80 ( V_101 , L_3 , F_5 ( & V_82 -> V_8 )
? ( long ) ( V_82 -> V_8 . V_76 - V_77 ) / V_79 : 0 ) ;
else
F_80 ( V_101 , L_4 ) ;
F_80 ( V_101 , L_5 ,
V_82 -> V_21 . V_29 . V_30 ,
V_82 -> V_21 . V_25 . V_28 ) ;
F_81 ( V_101 , & V_82 -> V_21 ,
F_82 ( V_82 -> V_21 . V_29 . V_30 ) ,
F_83 ( V_82 -> V_21 . V_29 . V_30 ,
V_82 -> V_21 . V_25 . V_28 ) ) ;
if ( V_82 -> V_41 & V_44 ) {
F_80 ( V_101 , L_6 ) ;
V_102 = L_7 ;
}
if ( V_82 -> V_41 & V_42 ) {
F_80 ( V_101 , L_8 , V_102 ) ;
V_102 = L_7 ;
}
if ( V_82 -> V_41 & V_104 )
F_80 ( V_101 , L_9 , V_102 ) ;
V_67 = F_70 ( F_2 ( V_82 -> V_6 ) -> V_67 ) ;
if ( V_67 ) {
F_80 ( V_101 , L_10 , V_82 -> V_41 ? L_11 : L_2 , V_67 -> V_105 ) ;
if ( V_67 -> V_78 [ V_82 -> V_14 ] . V_105 [ 0 ] )
F_80 ( V_101 , L_12 ,
V_67 -> V_78 [ V_82 -> V_14 ] . V_105 ) ;
}
F_84 ( V_101 , '\n' ) ;
return 0 ;
}
static int F_85 ( struct V_106 * V_106 , struct V_107 * V_107 )
{
return F_86 ( V_106 , V_107 , & V_108 ,
sizeof( struct V_95 ) ) ;
}
static int F_87 ( struct V_7 * V_7 )
{
#ifdef F_88
struct V_109 * V_110 ;
T_6 V_111 ;
T_7 V_112 ;
V_110 = F_89 ( L_13 , 0440 , V_7 -> V_113 ,
& V_114 ) ;
if ( ! V_110 )
return - V_115 ;
V_111 = F_90 ( V_7 -> V_116 , 0 ) ;
V_112 = F_91 ( V_7 -> V_116 , 0 ) ;
if ( F_92 ( V_111 ) && F_93 ( V_112 ) )
F_94 ( V_110 , V_111 , V_112 ) ;
#endif
return 0 ;
}
static void F_95 ( struct V_7 * V_7 )
{
#ifdef F_88
F_96 ( L_13 , V_7 -> V_113 ) ;
#endif
}
int F_97 ( struct V_7 * V_7 )
{
V_7 -> V_10 . V_11 = 0 ;
return F_87 ( V_7 ) ;
}
void F_98 ( struct V_7 * V_7 )
{
F_95 ( V_7 ) ;
}
int F_99 ( void )
{
if ( ! V_34 ) {
V_34 = V_117 / 256 ;
if ( ! V_34 )
V_34 = 1 ;
}
V_91 = V_34 * 4 ;
V_57 = F_100 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_57 )
return - V_115 ;
V_75 = F_101 ( & V_34 , 0 ) ;
if ( ! V_75 ) {
F_102 ( V_57 ) ;
return - V_115 ;
}
return 0 ;
}
void F_103 ( void )
{
F_104 () ;
F_102 ( V_57 ) ;
F_105 ( V_75 , V_34 ) ;
}
