void F_1 ( struct V_1 * exp ,
T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_7 * V_7 = F_3 ( exp ) ;
F_4 ( V_5 ) ;
F_4 ( ! F_5 ( & exp -> V_8 ) ) ;
F_6 ( & exp -> V_9 ) ;
V_7 -> V_10 . V_11 -- ;
F_7 ( & exp -> V_12 ) ;
V_5 -> V_13 [ exp -> V_14 ] -- ;
F_8 ( V_15 , exp , V_2 , V_3 ) ;
F_9 ( exp ) ;
F_10 ( V_7 , V_16 ) ;
}
static void F_11 ( unsigned long V_17 )
{
struct V_1 * exp = ( void * ) V_17 ;
F_12 ( & V_18 ) ;
F_13 ( exp ) ;
F_14 ( & V_18 ) ;
F_9 ( exp ) ;
}
static unsigned int F_15 ( const struct V_19 * V_20 )
{
unsigned int V_21 ;
if ( F_16 ( ! V_22 ) ) {
F_17 () ;
}
V_21 = F_18 ( V_20 -> V_23 . V_24 . V_25 , F_19 ( V_20 -> V_23 . V_24 . V_25 ) ,
( ( ( V_20 -> V_23 . V_26 ^ V_20 -> V_27 . V_28 ) << 16 ) |
( V_29 V_30 ) V_20 -> V_23 . V_31 . V_25 ) ^ V_22 ) ;
return ( ( V_32 ) V_21 * V_33 ) >> 32 ;
}
struct V_1 *
F_20 ( struct V_7 * V_7 , T_2 V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 ;
unsigned int V_36 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_36 = F_15 ( V_20 ) ;
F_21 (i, &net->ct.expect_hash[h], hnode) {
if ( F_22 ( V_20 , & V_35 -> V_20 , & V_35 -> V_37 ) &&
F_23 ( V_35 -> V_6 ) == V_34 )
return V_35 ;
}
return NULL ;
}
struct V_1 *
F_24 ( struct V_7 * V_7 , T_2 V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 ;
F_25 () ;
V_35 = F_20 ( V_7 , V_34 , V_20 ) ;
if ( V_35 && ! F_26 ( & V_35 -> V_38 ) )
V_35 = NULL ;
F_27 () ;
return V_35 ;
}
struct V_1 *
F_28 ( struct V_7 * V_7 , T_2 V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 , * exp = NULL ;
unsigned int V_36 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_36 = F_15 ( V_20 ) ;
F_29 (i, &net->ct.expect_hash[h], hnode) {
if ( ! ( V_35 -> V_39 & V_40 ) &&
F_22 ( V_20 , & V_35 -> V_20 , & V_35 -> V_37 ) &&
F_23 ( V_35 -> V_6 ) == V_34 ) {
exp = V_35 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_30 ( exp -> V_6 ) )
return NULL ;
if ( exp -> V_39 & V_41 ) {
F_31 ( & exp -> V_38 ) ;
return exp ;
} else if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
return exp ;
}
return NULL ;
}
void F_33 ( struct V_42 * V_10 )
{
struct V_4 * V_43 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_44 * V_45 ;
if ( ! V_43 )
return;
F_34 (exp, next, &help->expectations, lnode) {
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
}
static inline int F_35 ( const struct V_1 * V_46 ,
const struct V_1 * V_47 )
{
struct V_48 V_49 ;
int V_50 ;
V_49 . V_27 . V_31 . V_25 = V_46 -> V_37 . V_27 . V_31 . V_25 & V_47 -> V_37 . V_27 . V_31 . V_25 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_49 . V_27 . V_24 . V_25 [ V_50 ] =
V_46 -> V_37 . V_27 . V_24 . V_25 [ V_50 ] & V_47 -> V_37 . V_27 . V_24 . V_25 [ V_50 ] ;
}
return F_22 ( & V_46 -> V_20 , & V_47 -> V_20 , & V_49 ) ;
}
static inline int F_36 ( const struct V_1 * V_46 ,
const struct V_1 * V_47 )
{
return V_46 -> V_6 == V_47 -> V_6 && V_46 -> V_14 == V_47 -> V_14 &&
F_37 ( & V_46 -> V_20 , & V_47 -> V_20 ) &&
F_38 ( & V_46 -> V_37 , & V_47 -> V_37 ) &&
F_23 ( V_46 -> V_6 ) == F_23 ( V_47 -> V_6 ) ;
}
void F_39 ( struct V_1 * exp )
{
F_12 ( & V_18 ) ;
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
F_14 ( & V_18 ) ;
}
struct V_1 * F_40 ( struct V_42 * V_52 )
{
struct V_1 * V_53 ;
V_53 = F_41 ( V_54 , V_55 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_6 = V_52 ;
F_42 ( & V_53 -> V_38 , 1 ) ;
return V_53 ;
}
void F_43 ( struct V_1 * exp , unsigned int V_14 ,
T_3 V_56 ,
const union V_57 * V_58 ,
const union V_57 * V_59 ,
T_3 V_60 , const T_4 * V_27 , const T_4 * V_23 )
{
int V_61 ;
if ( V_56 == V_62 )
V_61 = 4 ;
else
V_61 = 16 ;
exp -> V_39 = 0 ;
exp -> V_14 = V_14 ;
exp -> V_63 = NULL ;
exp -> V_64 = NULL ;
exp -> V_20 . V_27 . V_28 = V_56 ;
exp -> V_20 . V_23 . V_26 = V_60 ;
if ( V_58 ) {
memcpy ( & exp -> V_20 . V_27 . V_24 , V_58 , V_61 ) ;
if ( sizeof( exp -> V_20 . V_27 . V_24 ) > V_61 )
memset ( ( void * ) & exp -> V_20 . V_27 . V_24 + V_61 , 0x00 ,
sizeof( exp -> V_20 . V_27 . V_24 ) - V_61 ) ;
memset ( & exp -> V_37 . V_27 . V_24 , 0xFF , V_61 ) ;
if ( sizeof( exp -> V_37 . V_27 . V_24 ) > V_61 )
memset ( ( void * ) & exp -> V_37 . V_27 . V_24 + V_61 , 0x00 ,
sizeof( exp -> V_37 . V_27 . V_24 ) - V_61 ) ;
} else {
memset ( & exp -> V_20 . V_27 . V_24 , 0x00 , sizeof( exp -> V_20 . V_27 . V_24 ) ) ;
memset ( & exp -> V_37 . V_27 . V_24 , 0x00 , sizeof( exp -> V_37 . V_27 . V_24 ) ) ;
}
if ( V_27 ) {
exp -> V_20 . V_27 . V_31 . V_25 = * V_27 ;
exp -> V_37 . V_27 . V_31 . V_25 = F_44 ( 0xFFFF ) ;
} else {
exp -> V_20 . V_27 . V_31 . V_25 = 0 ;
exp -> V_37 . V_27 . V_31 . V_25 = 0 ;
}
memcpy ( & exp -> V_20 . V_23 . V_24 , V_59 , V_61 ) ;
if ( sizeof( exp -> V_20 . V_23 . V_24 ) > V_61 )
memset ( ( void * ) & exp -> V_20 . V_23 . V_24 + V_61 , 0x00 ,
sizeof( exp -> V_20 . V_23 . V_24 ) - V_61 ) ;
exp -> V_20 . V_23 . V_31 . V_25 = * V_23 ;
#ifdef F_45
memset ( & exp -> V_65 , 0 , sizeof( exp -> V_65 ) ) ;
memset ( & exp -> V_66 , 0 , sizeof( exp -> V_66 ) ) ;
#endif
}
static void F_46 ( struct V_67 * V_68 )
{
struct V_1 * exp ;
exp = F_47 ( V_68 , struct V_1 , V_69 ) ;
F_48 ( V_54 , exp ) ;
}
void F_9 ( struct V_1 * exp )
{
if ( F_49 ( & exp -> V_38 ) )
F_50 ( & exp -> V_69 , F_46 ) ;
}
static int F_51 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_70 * V_64 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_36 = F_15 ( & exp -> V_20 ) ;
F_52 ( 2 , & exp -> V_38 ) ;
F_53 ( & exp -> V_12 , & V_5 -> V_71 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_54 ( & exp -> V_9 , & V_7 -> V_10 . V_72 [ V_36 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_55 ( & exp -> V_8 , F_11 ,
( unsigned long ) exp ) ;
V_64 = F_56 ( V_5 -> V_64 ,
F_57 ( & V_18 ) ) ;
if ( V_64 ) {
exp -> V_8 . V_73 = V_74 +
V_64 -> V_75 [ exp -> V_14 ] . V_8 * V_76 ;
}
F_58 ( & exp -> V_8 ) ;
F_10 ( V_7 , V_77 ) ;
return 0 ;
}
static void F_59 ( struct V_42 * V_6 ,
struct V_1 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_78 = NULL ;
F_29 (exp, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_53 -> V_14 )
V_78 = exp ;
}
if ( V_78 && F_32 ( & V_78 -> V_8 ) ) {
F_13 ( V_78 ) ;
F_9 ( V_78 ) ;
}
}
static inline int F_60 ( struct V_1 * V_79 )
{
const struct V_80 * V_81 ;
struct V_1 * V_35 ;
struct V_42 * V_6 = V_79 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_70 * V_64 ;
struct V_7 * V_7 = F_3 ( V_79 ) ;
struct V_44 * V_45 ;
unsigned int V_36 ;
int V_82 = 1 ;
if ( ! V_5 ) {
V_82 = - V_83 ;
goto V_84;
}
V_36 = F_15 ( & V_79 -> V_20 ) ;
F_34 (i, next, &net->ct.expect_hash[h], hnode) {
if ( F_36 ( V_35 , V_79 ) ) {
if ( F_32 ( & V_35 -> V_8 ) ) {
F_13 ( V_35 ) ;
F_9 ( V_35 ) ;
break;
}
} else if ( F_35 ( V_35 , V_79 ) ) {
V_82 = - V_85 ;
goto V_84;
}
}
V_64 = F_56 ( V_5 -> V_64 ,
F_57 ( & V_18 ) ) ;
if ( V_64 ) {
V_81 = & V_64 -> V_75 [ V_79 -> V_14 ] ;
if ( V_81 -> V_86 &&
V_5 -> V_13 [ V_79 -> V_14 ] >= V_81 -> V_86 ) {
F_59 ( V_6 , V_79 ) ;
if ( V_5 -> V_13 [ V_79 -> V_14 ]
>= V_81 -> V_86 ) {
V_82 = - V_87 ;
goto V_84;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_88 ) {
F_61 ( L_1 ) ;
V_82 = - V_87 ;
}
V_84:
return V_82 ;
}
int F_62 ( struct V_1 * V_79 ,
T_1 V_2 , int V_3 )
{
int V_82 ;
F_12 ( & V_18 ) ;
V_82 = F_60 ( V_79 ) ;
if ( V_82 <= 0 )
goto V_84;
V_82 = F_51 ( V_79 ) ;
if ( V_82 < 0 )
goto V_84;
F_14 ( & V_18 ) ;
F_8 ( V_89 , V_79 , V_2 , V_3 ) ;
return V_82 ;
V_84:
F_14 ( & V_18 ) ;
return V_82 ;
}
static struct V_44 * F_63 ( struct V_90 * V_91 )
{
struct V_7 * V_7 = F_64 ( V_91 ) ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_44 * V_95 ;
for ( V_93 -> V_96 = 0 ; V_93 -> V_96 < V_33 ; V_93 -> V_96 ++ ) {
V_95 = F_65 ( F_66 ( & V_7 -> V_10 . V_72 [ V_93 -> V_96 ] ) ) ;
if ( V_95 )
return V_95 ;
}
return NULL ;
}
static struct V_44 * F_67 ( struct V_90 * V_91 ,
struct V_44 * V_68 )
{
struct V_7 * V_7 = F_64 ( V_91 ) ;
struct V_92 * V_93 = V_91 -> V_94 ;
V_68 = F_65 ( F_68 ( V_68 ) ) ;
while ( V_68 == NULL ) {
if ( ++ V_93 -> V_96 >= V_33 )
return NULL ;
V_68 = F_65 ( F_66 ( & V_7 -> V_10 . V_72 [ V_93 -> V_96 ] ) ) ;
}
return V_68 ;
}
static struct V_44 * F_69 ( struct V_90 * V_91 , T_5 V_97 )
{
struct V_44 * V_68 = F_63 ( V_91 ) ;
if ( V_68 )
while ( V_97 && ( V_68 = F_67 ( V_91 , V_68 ) ) )
V_97 -- ;
return V_97 ? NULL : V_68 ;
}
static void * F_70 ( struct V_90 * V_91 , T_5 * V_97 )
__acquires( T_6 )
{
F_25 () ;
return F_69 ( V_91 , * V_97 ) ;
}
static void * F_71 ( struct V_90 * V_91 , void * V_98 , T_5 * V_97 )
{
( * V_97 ) ++ ;
return F_67 ( V_91 , V_98 ) ;
}
static void F_72 ( struct V_90 * V_91 , void * V_98 )
__releases( T_6 )
{
F_27 () ;
}
static int F_73 ( struct V_90 * V_99 , void * V_98 )
{
struct V_1 * V_79 ;
struct V_70 * V_64 ;
struct V_44 * V_95 = V_98 ;
char * V_100 = L_2 ;
V_79 = F_74 ( V_95 , struct V_1 , V_9 ) ;
if ( V_79 -> V_8 . V_101 )
F_75 ( V_99 , L_3 , F_5 ( & V_79 -> V_8 )
? ( long ) ( V_79 -> V_8 . V_73 - V_74 ) / V_76 : 0 ) ;
else
F_75 ( V_99 , L_4 ) ;
F_75 ( V_99 , L_5 ,
V_79 -> V_20 . V_27 . V_28 ,
V_79 -> V_20 . V_23 . V_26 ) ;
F_76 ( V_99 , & V_79 -> V_20 ,
F_77 ( V_79 -> V_20 . V_27 . V_28 ) ,
F_78 ( V_79 -> V_20 . V_27 . V_28 ,
V_79 -> V_20 . V_23 . V_26 ) ) ;
if ( V_79 -> V_39 & V_41 ) {
F_75 ( V_99 , L_6 ) ;
V_100 = L_7 ;
}
if ( V_79 -> V_39 & V_40 ) {
F_75 ( V_99 , L_8 , V_100 ) ;
V_100 = L_7 ;
}
if ( V_79 -> V_39 & V_102 )
F_75 ( V_99 , L_9 , V_100 ) ;
V_64 = F_65 ( F_2 ( V_79 -> V_6 ) -> V_64 ) ;
if ( V_64 ) {
F_75 ( V_99 , L_10 , V_79 -> V_39 ? L_11 : L_2 , V_64 -> V_103 ) ;
if ( V_64 -> V_75 [ V_79 -> V_14 ] . V_103 )
F_75 ( V_99 , L_12 ,
V_64 -> V_75 [ V_79 -> V_14 ] . V_103 ) ;
}
return F_79 ( V_99 , '\n' ) ;
}
static int F_80 ( struct V_104 * V_104 , struct V_105 * V_105 )
{
return F_81 ( V_104 , V_105 , & V_106 ,
sizeof( struct V_92 ) ) ;
}
static int F_82 ( struct V_7 * V_7 )
{
#ifdef F_83
struct V_107 * V_108 ;
V_108 = F_84 ( L_13 , 0440 , V_7 -> V_109 ,
& V_110 ) ;
if ( ! V_108 )
return - V_111 ;
#endif
return 0 ;
}
static void F_85 ( struct V_7 * V_7 )
{
#ifdef F_83
F_86 ( L_13 , V_7 -> V_109 ) ;
#endif
}
int F_87 ( struct V_7 * V_7 )
{
int V_112 = - V_111 ;
V_7 -> V_10 . V_11 = 0 ;
V_7 -> V_10 . V_72 = F_88 ( & V_33 , 0 ) ;
if ( V_7 -> V_10 . V_72 == NULL )
goto V_113;
V_112 = F_82 ( V_7 ) ;
if ( V_112 < 0 )
goto V_114;
return 0 ;
V_114:
F_89 ( V_7 -> V_10 . V_72 , V_33 ) ;
V_113:
return V_112 ;
}
void F_90 ( struct V_7 * V_7 )
{
F_85 ( V_7 ) ;
F_89 ( V_7 -> V_10 . V_72 , V_33 ) ;
}
int F_91 ( void )
{
if ( ! V_33 ) {
V_33 = V_115 / 256 ;
if ( ! V_33 )
V_33 = 1 ;
}
V_88 = V_33 * 4 ;
V_54 = F_92 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_54 )
return - V_111 ;
return 0 ;
}
void F_93 ( void )
{
F_94 () ;
F_95 ( V_54 ) ;
}
