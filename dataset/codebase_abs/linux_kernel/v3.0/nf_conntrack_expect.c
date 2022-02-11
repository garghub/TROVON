void F_1 ( struct V_1 * exp ,
T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_7 * V_7 = F_3 ( exp ) ;
F_4 ( ! F_5 ( & exp -> V_8 ) ) ;
F_6 ( & exp -> V_9 ) ;
V_7 -> V_10 . V_11 -- ;
F_7 ( & exp -> V_12 ) ;
if ( ! ( exp -> V_13 & V_14 ) )
V_5 -> V_15 [ exp -> V_16 ] -- ;
F_8 ( V_17 , exp , V_2 , V_3 ) ;
F_9 ( exp ) ;
F_10 ( V_7 , V_18 ) ;
}
static void F_11 ( unsigned long V_19 )
{
struct V_1 * exp = ( void * ) V_19 ;
F_12 ( & V_20 ) ;
F_13 ( exp ) ;
F_14 ( & V_20 ) ;
F_9 ( exp ) ;
}
static unsigned int F_15 ( const struct V_21 * V_22 )
{
unsigned int V_23 ;
if ( F_16 ( ! V_24 ) ) {
F_17 () ;
}
V_23 = F_18 ( V_22 -> V_25 . V_26 . V_27 , F_19 ( V_22 -> V_25 . V_26 . V_27 ) ,
( ( ( V_22 -> V_25 . V_28 ^ V_22 -> V_29 . V_30 ) << 16 ) |
( V_31 V_32 ) V_22 -> V_25 . V_33 . V_27 ) ^ V_24 ) ;
return ( ( V_34 ) V_23 * V_35 ) >> 32 ;
}
struct V_1 *
F_20 ( struct V_7 * V_7 , T_2 V_36 ,
const struct V_21 * V_22 )
{
struct V_1 * V_37 ;
struct V_38 * V_39 ;
unsigned int V_40 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_40 = F_15 ( V_22 ) ;
F_21 (i, n, &net->ct.expect_hash[h], hnode) {
if ( F_22 ( V_22 , & V_37 -> V_22 , & V_37 -> V_41 ) &&
F_23 ( V_37 -> V_6 ) == V_36 )
return V_37 ;
}
return NULL ;
}
struct V_1 *
F_24 ( struct V_7 * V_7 , T_2 V_36 ,
const struct V_21 * V_22 )
{
struct V_1 * V_37 ;
F_25 () ;
V_37 = F_20 ( V_7 , V_36 , V_22 ) ;
if ( V_37 && ! F_26 ( & V_37 -> V_42 ) )
V_37 = NULL ;
F_27 () ;
return V_37 ;
}
struct V_1 *
F_28 ( struct V_7 * V_7 , T_2 V_36 ,
const struct V_21 * V_22 )
{
struct V_1 * V_37 , * exp = NULL ;
struct V_38 * V_39 ;
unsigned int V_40 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_40 = F_15 ( V_22 ) ;
F_29 (i, n, &net->ct.expect_hash[h], hnode) {
if ( ! ( V_37 -> V_13 & V_43 ) &&
F_22 ( V_22 , & V_37 -> V_22 , & V_37 -> V_41 ) &&
F_23 ( V_37 -> V_6 ) == V_36 ) {
exp = V_37 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_30 ( exp -> V_6 ) )
return NULL ;
if ( exp -> V_13 & V_44 ) {
F_31 ( & exp -> V_42 ) ;
return exp ;
} else if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
return exp ;
}
return NULL ;
}
void F_33 ( struct V_45 * V_10 )
{
struct V_4 * V_46 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_38 * V_39 , * V_47 ;
if ( ! V_46 )
return;
F_34 (exp, n, next, &help->expectations, lnode) {
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
}
static inline int F_35 ( const struct V_1 * V_48 ,
const struct V_1 * V_49 )
{
struct V_50 V_51 ;
int V_52 ;
V_51 . V_29 . V_33 . V_27 = V_48 -> V_41 . V_29 . V_33 . V_27 & V_49 -> V_41 . V_29 . V_33 . V_27 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_51 . V_29 . V_26 . V_27 [ V_52 ] =
V_48 -> V_41 . V_29 . V_26 . V_27 [ V_52 ] & V_49 -> V_41 . V_29 . V_26 . V_27 [ V_52 ] ;
}
return F_22 ( & V_48 -> V_22 , & V_49 -> V_22 , & V_51 ) ;
}
static inline int F_36 ( const struct V_1 * V_48 ,
const struct V_1 * V_49 )
{
return V_48 -> V_6 == V_49 -> V_6 && V_48 -> V_16 == V_49 -> V_16 &&
F_37 ( & V_48 -> V_22 , & V_49 -> V_22 ) &&
F_38 ( & V_48 -> V_41 , & V_49 -> V_41 ) &&
F_23 ( V_48 -> V_6 ) == F_23 ( V_49 -> V_6 ) ;
}
void F_39 ( struct V_1 * exp )
{
F_12 ( & V_20 ) ;
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
F_14 ( & V_20 ) ;
}
struct V_1 * F_40 ( struct V_45 * V_54 )
{
struct V_1 * V_55 ;
V_55 = F_41 ( V_56 , V_57 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_6 = V_54 ;
F_42 ( & V_55 -> V_42 , 1 ) ;
return V_55 ;
}
void F_43 ( struct V_1 * exp , unsigned int V_16 ,
T_3 V_58 ,
const union V_59 * V_60 ,
const union V_59 * V_61 ,
T_3 V_62 , const T_4 * V_29 , const T_4 * V_25 )
{
int V_63 ;
if ( V_58 == V_64 )
V_63 = 4 ;
else
V_63 = 16 ;
exp -> V_13 = 0 ;
exp -> V_16 = V_16 ;
exp -> V_65 = NULL ;
exp -> V_66 = NULL ;
exp -> V_22 . V_29 . V_30 = V_58 ;
exp -> V_22 . V_25 . V_28 = V_62 ;
if ( V_60 ) {
memcpy ( & exp -> V_22 . V_29 . V_26 , V_60 , V_63 ) ;
if ( sizeof( exp -> V_22 . V_29 . V_26 ) > V_63 )
memset ( ( void * ) & exp -> V_22 . V_29 . V_26 + V_63 , 0x00 ,
sizeof( exp -> V_22 . V_29 . V_26 ) - V_63 ) ;
memset ( & exp -> V_41 . V_29 . V_26 , 0xFF , V_63 ) ;
if ( sizeof( exp -> V_41 . V_29 . V_26 ) > V_63 )
memset ( ( void * ) & exp -> V_41 . V_29 . V_26 + V_63 , 0x00 ,
sizeof( exp -> V_41 . V_29 . V_26 ) - V_63 ) ;
} else {
memset ( & exp -> V_22 . V_29 . V_26 , 0x00 , sizeof( exp -> V_22 . V_29 . V_26 ) ) ;
memset ( & exp -> V_41 . V_29 . V_26 , 0x00 , sizeof( exp -> V_41 . V_29 . V_26 ) ) ;
}
if ( V_29 ) {
exp -> V_22 . V_29 . V_33 . V_27 = * V_29 ;
exp -> V_41 . V_29 . V_33 . V_27 = F_44 ( 0xFFFF ) ;
} else {
exp -> V_22 . V_29 . V_33 . V_27 = 0 ;
exp -> V_41 . V_29 . V_33 . V_27 = 0 ;
}
memcpy ( & exp -> V_22 . V_25 . V_26 , V_61 , V_63 ) ;
if ( sizeof( exp -> V_22 . V_25 . V_26 ) > V_63 )
memset ( ( void * ) & exp -> V_22 . V_25 . V_26 + V_63 , 0x00 ,
sizeof( exp -> V_22 . V_25 . V_26 ) - V_63 ) ;
exp -> V_22 . V_25 . V_33 . V_27 = * V_25 ;
}
static void F_45 ( struct V_67 * V_68 )
{
struct V_1 * exp ;
exp = F_46 ( V_68 , struct V_1 , V_69 ) ;
F_47 ( V_56 , exp ) ;
}
void F_9 ( struct V_1 * exp )
{
if ( F_48 ( & exp -> V_42 ) )
F_49 ( & exp -> V_69 , F_45 ) ;
}
static void F_50 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_7 * V_7 = F_3 ( exp ) ;
const struct V_70 * V_71 ;
unsigned int V_40 = F_15 ( & exp -> V_22 ) ;
F_51 ( 2 , & exp -> V_42 ) ;
if ( V_5 ) {
F_52 ( & exp -> V_12 , & V_5 -> V_72 ) ;
V_5 -> V_15 [ exp -> V_16 ] ++ ;
} else if ( exp -> V_13 & V_14 )
F_52 ( & exp -> V_12 , & V_73 ) ;
F_53 ( & exp -> V_9 , & V_7 -> V_10 . V_74 [ V_40 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_54 ( & exp -> V_8 , F_11 ,
( unsigned long ) exp ) ;
if ( V_5 ) {
V_71 = & F_55 (
V_5 -> V_66 ,
F_56 ( & V_20 )
) -> V_75 [ exp -> V_16 ] ;
exp -> V_8 . V_76 = V_77 + V_71 -> V_8 * V_78 ;
}
F_57 ( & exp -> V_8 ) ;
F_10 ( V_7 , V_79 ) ;
}
static void F_58 ( struct V_45 * V_6 ,
struct V_1 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_80 = NULL ;
struct V_38 * V_39 ;
F_29 (exp, n, &master_help->expectations, lnode) {
if ( exp -> V_16 == V_55 -> V_16 )
V_80 = exp ;
}
if ( V_80 && F_32 ( & V_80 -> V_8 ) ) {
F_13 ( V_80 ) ;
F_9 ( V_80 ) ;
}
}
static inline int F_59 ( struct V_1 * V_37 )
{
struct V_4 * V_5 = F_2 ( V_37 -> V_6 ) ;
const struct V_70 * V_71 ;
if ( ! F_32 ( & V_37 -> V_8 ) )
return 0 ;
V_71 = & F_55 (
V_5 -> V_66 ,
F_56 ( & V_20 )
) -> V_75 [ V_37 -> V_16 ] ;
V_37 -> V_8 . V_76 = V_77 + V_71 -> V_8 * V_78 ;
F_57 ( & V_37 -> V_8 ) ;
return 1 ;
}
static inline int F_60 ( struct V_1 * V_81 )
{
const struct V_70 * V_71 ;
struct V_1 * V_37 ;
struct V_45 * V_6 = V_81 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_7 * V_7 = F_3 ( V_81 ) ;
struct V_38 * V_39 ;
unsigned int V_40 ;
int V_82 = 1 ;
if ( ! ( V_81 -> V_13 & V_14 ) &&
( ! V_5 || ( V_5 && ! V_5 -> V_66 ) ) ) {
V_82 = - V_83 ;
goto V_84;
}
V_40 = F_15 ( & V_81 -> V_22 ) ;
F_29 (i, n, &net->ct.expect_hash[h], hnode) {
if ( F_36 ( V_37 , V_81 ) ) {
if ( F_59 ( V_37 ) ) {
V_82 = 0 ;
goto V_84;
}
} else if ( F_35 ( V_37 , V_81 ) ) {
V_82 = - V_85 ;
goto V_84;
}
}
if ( V_5 ) {
V_71 = & F_55 (
V_5 -> V_66 ,
F_56 ( & V_20 )
) -> V_75 [ V_81 -> V_16 ] ;
if ( V_71 -> V_86 &&
V_5 -> V_15 [ V_81 -> V_16 ] >= V_71 -> V_86 ) {
F_58 ( V_6 , V_81 ) ;
if ( V_5 -> V_15 [ V_81 -> V_16 ]
>= V_71 -> V_86 ) {
V_82 = - V_87 ;
goto V_84;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_88 ) {
if ( F_61 () )
F_62 ( V_89
L_1 ) ;
V_82 = - V_87 ;
}
V_84:
return V_82 ;
}
int F_63 ( struct V_1 * V_81 ,
T_1 V_2 , int V_3 )
{
int V_82 ;
F_12 ( & V_20 ) ;
V_82 = F_60 ( V_81 ) ;
if ( V_82 <= 0 )
goto V_84;
V_82 = 0 ;
F_50 ( V_81 ) ;
F_14 ( & V_20 ) ;
F_8 ( V_90 , V_81 , V_2 , V_3 ) ;
return V_82 ;
V_84:
F_14 ( & V_20 ) ;
return V_82 ;
}
void F_64 ( void )
{
struct V_1 * exp ;
struct V_38 * V_39 , * V_47 ;
F_34 (exp, n, next,
&nf_ct_userspace_expect_list, lnode) {
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
}
static struct V_38 * F_65 ( struct V_91 * V_92 )
{
struct V_7 * V_7 = F_66 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
struct V_38 * V_39 ;
for ( V_94 -> V_96 = 0 ; V_94 -> V_96 < V_35 ; V_94 -> V_96 ++ ) {
V_39 = F_67 ( F_68 ( & V_7 -> V_10 . V_74 [ V_94 -> V_96 ] ) ) ;
if ( V_39 )
return V_39 ;
}
return NULL ;
}
static struct V_38 * F_69 ( struct V_91 * V_92 ,
struct V_38 * V_68 )
{
struct V_7 * V_7 = F_66 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
V_68 = F_67 ( F_70 ( V_68 ) ) ;
while ( V_68 == NULL ) {
if ( ++ V_94 -> V_96 >= V_35 )
return NULL ;
V_68 = F_67 ( F_68 ( & V_7 -> V_10 . V_74 [ V_94 -> V_96 ] ) ) ;
}
return V_68 ;
}
static struct V_38 * F_71 ( struct V_91 * V_92 , T_5 V_97 )
{
struct V_38 * V_68 = F_65 ( V_92 ) ;
if ( V_68 )
while ( V_97 && ( V_68 = F_69 ( V_92 , V_68 ) ) )
V_97 -- ;
return V_97 ? NULL : V_68 ;
}
static void * F_72 ( struct V_91 * V_92 , T_5 * V_97 )
__acquires( T_6 )
{
F_25 () ;
return F_71 ( V_92 , * V_97 ) ;
}
static void * F_73 ( struct V_91 * V_92 , void * V_98 , T_5 * V_97 )
{
( * V_97 ) ++ ;
return F_69 ( V_92 , V_98 ) ;
}
static void F_74 ( struct V_91 * V_92 , void * V_98 )
__releases( T_6 )
{
F_27 () ;
}
static int F_75 ( struct V_91 * V_99 , void * V_98 )
{
struct V_1 * V_81 ;
struct V_100 * V_66 ;
struct V_38 * V_39 = V_98 ;
char * V_101 = L_2 ;
V_81 = F_76 ( V_39 , struct V_1 , V_9 ) ;
if ( V_81 -> V_8 . V_102 )
F_77 ( V_99 , L_3 , F_5 ( & V_81 -> V_8 )
? ( long ) ( V_81 -> V_8 . V_76 - V_77 ) / V_78 : 0 ) ;
else
F_77 ( V_99 , L_4 ) ;
F_77 ( V_99 , L_5 ,
V_81 -> V_22 . V_29 . V_30 ,
V_81 -> V_22 . V_25 . V_28 ) ;
F_78 ( V_99 , & V_81 -> V_22 ,
F_79 ( V_81 -> V_22 . V_29 . V_30 ) ,
F_80 ( V_81 -> V_22 . V_29 . V_30 ,
V_81 -> V_22 . V_25 . V_28 ) ) ;
if ( V_81 -> V_13 & V_44 ) {
F_77 ( V_99 , L_6 ) ;
V_101 = L_7 ;
}
if ( V_81 -> V_13 & V_43 ) {
F_77 ( V_99 , L_8 , V_101 ) ;
V_101 = L_7 ;
}
if ( V_81 -> V_13 & V_14 )
F_77 ( V_99 , L_9 , V_101 ) ;
V_66 = F_67 ( F_2 ( V_81 -> V_6 ) -> V_66 ) ;
if ( V_66 ) {
F_77 ( V_99 , L_10 , V_81 -> V_13 ? L_11 : L_2 , V_66 -> V_103 ) ;
if ( V_66 -> V_75 [ V_81 -> V_16 ] . V_103 )
F_77 ( V_99 , L_12 ,
V_66 -> V_75 [ V_81 -> V_16 ] . V_103 ) ;
}
return F_81 ( V_99 , '\n' ) ;
}
static int F_82 ( struct V_104 * V_104 , struct V_105 * V_105 )
{
return F_83 ( V_104 , V_105 , & V_106 ,
sizeof( struct V_93 ) ) ;
}
static int F_84 ( struct V_7 * V_7 )
{
#ifdef F_85
struct V_107 * V_108 ;
V_108 = F_86 ( V_7 , L_13 , 0440 , & V_109 ) ;
if ( ! V_108 )
return - V_110 ;
#endif
return 0 ;
}
static void F_87 ( struct V_7 * V_7 )
{
#ifdef F_85
F_88 ( V_7 , L_13 ) ;
#endif
}
int F_89 ( struct V_7 * V_7 )
{
int V_111 = - V_110 ;
if ( F_90 ( V_7 , & V_112 ) ) {
if ( ! V_35 ) {
V_35 = V_7 -> V_10 . V_113 / 256 ;
if ( ! V_35 )
V_35 = 1 ;
}
V_88 = V_35 * 4 ;
}
V_7 -> V_10 . V_11 = 0 ;
V_7 -> V_10 . V_74 = F_91 ( & V_35 , 0 ) ;
if ( V_7 -> V_10 . V_74 == NULL )
goto V_114;
if ( F_90 ( V_7 , & V_112 ) ) {
V_56 = F_92 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_56 )
goto V_115;
}
V_111 = F_84 ( V_7 ) ;
if ( V_111 < 0 )
goto V_116;
return 0 ;
V_116:
if ( F_90 ( V_7 , & V_112 ) )
F_93 ( V_56 ) ;
V_115:
F_94 ( V_7 -> V_10 . V_74 , V_35 ) ;
V_114:
return V_111 ;
}
void F_95 ( struct V_7 * V_7 )
{
F_87 ( V_7 ) ;
if ( F_90 ( V_7 , & V_112 ) ) {
F_96 () ;
F_93 ( V_56 ) ;
}
F_94 ( V_7 -> V_10 . V_74 , V_35 ) ;
}
