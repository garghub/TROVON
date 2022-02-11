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
struct V_36 * V_37 ;
unsigned int V_38 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_38 = F_15 ( V_20 ) ;
F_21 (i, n, &net->ct.expect_hash[h], hnode) {
if ( F_22 ( V_20 , & V_35 -> V_20 , & V_35 -> V_39 ) &&
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
if ( V_35 && ! F_26 ( & V_35 -> V_40 ) )
V_35 = NULL ;
F_27 () ;
return V_35 ;
}
struct V_1 *
F_28 ( struct V_7 * V_7 , T_2 V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 , * exp = NULL ;
struct V_36 * V_37 ;
unsigned int V_38 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_38 = F_15 ( V_20 ) ;
F_29 (i, n, &net->ct.expect_hash[h], hnode) {
if ( ! ( V_35 -> V_41 & V_42 ) &&
F_22 ( V_20 , & V_35 -> V_20 , & V_35 -> V_39 ) &&
F_23 ( V_35 -> V_6 ) == V_34 ) {
exp = V_35 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_30 ( exp -> V_6 ) )
return NULL ;
if ( exp -> V_41 & V_43 ) {
F_31 ( & exp -> V_40 ) ;
return exp ;
} else if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
return exp ;
}
return NULL ;
}
void F_33 ( struct V_44 * V_10 )
{
struct V_4 * V_45 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_36 * V_37 , * V_46 ;
if ( ! V_45 )
return;
F_34 (exp, n, next, &help->expectations, lnode) {
if ( F_32 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
}
static inline int F_35 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
struct V_49 V_50 ;
int V_51 ;
V_50 . V_27 . V_31 . V_25 = V_47 -> V_39 . V_27 . V_31 . V_25 & V_48 -> V_39 . V_27 . V_31 . V_25 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_50 . V_27 . V_24 . V_25 [ V_51 ] =
V_47 -> V_39 . V_27 . V_24 . V_25 [ V_51 ] & V_48 -> V_39 . V_27 . V_24 . V_25 [ V_51 ] ;
}
return F_22 ( & V_47 -> V_20 , & V_48 -> V_20 , & V_50 ) ;
}
static inline int F_36 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
return V_47 -> V_6 == V_48 -> V_6 && V_47 -> V_14 == V_48 -> V_14 &&
F_37 ( & V_47 -> V_20 , & V_48 -> V_20 ) &&
F_38 ( & V_47 -> V_39 , & V_48 -> V_39 ) &&
F_23 ( V_47 -> V_6 ) == F_23 ( V_48 -> V_6 ) ;
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
struct V_1 * F_40 ( struct V_44 * V_53 )
{
struct V_1 * V_54 ;
V_54 = F_41 ( V_55 , V_56 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_6 = V_53 ;
F_42 ( & V_54 -> V_40 , 1 ) ;
return V_54 ;
}
void F_43 ( struct V_1 * exp , unsigned int V_14 ,
T_3 V_57 ,
const union V_58 * V_59 ,
const union V_58 * V_60 ,
T_3 V_61 , const T_4 * V_27 , const T_4 * V_23 )
{
int V_62 ;
if ( V_57 == V_63 )
V_62 = 4 ;
else
V_62 = 16 ;
exp -> V_41 = 0 ;
exp -> V_14 = V_14 ;
exp -> V_64 = NULL ;
exp -> V_65 = NULL ;
exp -> V_20 . V_27 . V_28 = V_57 ;
exp -> V_20 . V_23 . V_26 = V_61 ;
if ( V_59 ) {
memcpy ( & exp -> V_20 . V_27 . V_24 , V_59 , V_62 ) ;
if ( sizeof( exp -> V_20 . V_27 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_20 . V_27 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_20 . V_27 . V_24 ) - V_62 ) ;
memset ( & exp -> V_39 . V_27 . V_24 , 0xFF , V_62 ) ;
if ( sizeof( exp -> V_39 . V_27 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_39 . V_27 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_39 . V_27 . V_24 ) - V_62 ) ;
} else {
memset ( & exp -> V_20 . V_27 . V_24 , 0x00 , sizeof( exp -> V_20 . V_27 . V_24 ) ) ;
memset ( & exp -> V_39 . V_27 . V_24 , 0x00 , sizeof( exp -> V_39 . V_27 . V_24 ) ) ;
}
if ( V_27 ) {
exp -> V_20 . V_27 . V_31 . V_25 = * V_27 ;
exp -> V_39 . V_27 . V_31 . V_25 = F_44 ( 0xFFFF ) ;
} else {
exp -> V_20 . V_27 . V_31 . V_25 = 0 ;
exp -> V_39 . V_27 . V_31 . V_25 = 0 ;
}
memcpy ( & exp -> V_20 . V_23 . V_24 , V_60 , V_62 ) ;
if ( sizeof( exp -> V_20 . V_23 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_20 . V_23 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_20 . V_23 . V_24 ) - V_62 ) ;
exp -> V_20 . V_23 . V_31 . V_25 = * V_23 ;
}
static void F_45 ( struct V_66 * V_67 )
{
struct V_1 * exp ;
exp = F_46 ( V_67 , struct V_1 , V_68 ) ;
F_47 ( V_55 , exp ) ;
}
void F_9 ( struct V_1 * exp )
{
if ( F_48 ( & exp -> V_40 ) )
F_49 ( & exp -> V_68 , F_45 ) ;
}
static int F_50 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_69 * V_65 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_38 = F_15 ( & exp -> V_20 ) ;
F_51 ( 2 , & exp -> V_40 ) ;
F_52 ( & exp -> V_12 , & V_5 -> V_70 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_53 ( & exp -> V_9 , & V_7 -> V_10 . V_71 [ V_38 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_54 ( & exp -> V_8 , F_11 ,
( unsigned long ) exp ) ;
V_65 = F_55 ( V_5 -> V_65 ,
F_56 ( & V_18 ) ) ;
if ( V_65 ) {
exp -> V_8 . V_72 = V_73 +
V_65 -> V_74 [ exp -> V_14 ] . V_8 * V_75 ;
}
F_57 ( & exp -> V_8 ) ;
F_10 ( V_7 , V_76 ) ;
return 0 ;
}
static void F_58 ( struct V_44 * V_6 ,
struct V_1 * V_54 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_77 = NULL ;
struct V_36 * V_37 ;
F_29 (exp, n, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_54 -> V_14 )
V_77 = exp ;
}
if ( V_77 && F_32 ( & V_77 -> V_8 ) ) {
F_13 ( V_77 ) ;
F_9 ( V_77 ) ;
}
}
static inline int F_59 ( struct V_1 * V_78 )
{
const struct V_79 * V_80 ;
struct V_1 * V_35 ;
struct V_44 * V_6 = V_78 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_69 * V_65 ;
struct V_7 * V_7 = F_3 ( V_78 ) ;
struct V_36 * V_37 , * V_46 ;
unsigned int V_38 ;
int V_81 = 1 ;
if ( ! V_5 ) {
V_81 = - V_82 ;
goto V_83;
}
V_38 = F_15 ( & V_78 -> V_20 ) ;
F_34 (i, n, next, &net->ct.expect_hash[h], hnode) {
if ( F_36 ( V_35 , V_78 ) ) {
if ( F_32 ( & V_35 -> V_8 ) ) {
F_13 ( V_35 ) ;
F_9 ( V_35 ) ;
break;
}
} else if ( F_35 ( V_35 , V_78 ) ) {
V_81 = - V_84 ;
goto V_83;
}
}
V_65 = F_55 ( V_5 -> V_65 ,
F_56 ( & V_18 ) ) ;
if ( V_65 ) {
V_80 = & V_65 -> V_74 [ V_78 -> V_14 ] ;
if ( V_80 -> V_85 &&
V_5 -> V_13 [ V_78 -> V_14 ] >= V_80 -> V_85 ) {
F_58 ( V_6 , V_78 ) ;
if ( V_5 -> V_13 [ V_78 -> V_14 ]
>= V_80 -> V_85 ) {
V_81 = - V_86 ;
goto V_83;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_87 ) {
F_60 ( L_1 ) ;
V_81 = - V_86 ;
}
V_83:
return V_81 ;
}
int F_61 ( struct V_1 * V_78 ,
T_1 V_2 , int V_3 )
{
int V_81 ;
F_12 ( & V_18 ) ;
V_81 = F_59 ( V_78 ) ;
if ( V_81 <= 0 )
goto V_83;
V_81 = F_50 ( V_78 ) ;
if ( V_81 < 0 )
goto V_83;
F_14 ( & V_18 ) ;
F_8 ( V_88 , V_78 , V_2 , V_3 ) ;
return V_81 ;
V_83:
F_14 ( & V_18 ) ;
return V_81 ;
}
static struct V_36 * F_62 ( struct V_89 * V_90 )
{
struct V_7 * V_7 = F_63 ( V_90 ) ;
struct V_91 * V_92 = V_90 -> V_93 ;
struct V_36 * V_37 ;
for ( V_92 -> V_94 = 0 ; V_92 -> V_94 < V_33 ; V_92 -> V_94 ++ ) {
V_37 = F_64 ( F_65 ( & V_7 -> V_10 . V_71 [ V_92 -> V_94 ] ) ) ;
if ( V_37 )
return V_37 ;
}
return NULL ;
}
static struct V_36 * F_66 ( struct V_89 * V_90 ,
struct V_36 * V_67 )
{
struct V_7 * V_7 = F_63 ( V_90 ) ;
struct V_91 * V_92 = V_90 -> V_93 ;
V_67 = F_64 ( F_67 ( V_67 ) ) ;
while ( V_67 == NULL ) {
if ( ++ V_92 -> V_94 >= V_33 )
return NULL ;
V_67 = F_64 ( F_65 ( & V_7 -> V_10 . V_71 [ V_92 -> V_94 ] ) ) ;
}
return V_67 ;
}
static struct V_36 * F_68 ( struct V_89 * V_90 , T_5 V_95 )
{
struct V_36 * V_67 = F_62 ( V_90 ) ;
if ( V_67 )
while ( V_95 && ( V_67 = F_66 ( V_90 , V_67 ) ) )
V_95 -- ;
return V_95 ? NULL : V_67 ;
}
static void * F_69 ( struct V_89 * V_90 , T_5 * V_95 )
__acquires( T_6 )
{
F_25 () ;
return F_68 ( V_90 , * V_95 ) ;
}
static void * F_70 ( struct V_89 * V_90 , void * V_96 , T_5 * V_95 )
{
( * V_95 ) ++ ;
return F_66 ( V_90 , V_96 ) ;
}
static void F_71 ( struct V_89 * V_90 , void * V_96 )
__releases( T_6 )
{
F_27 () ;
}
static int F_72 ( struct V_89 * V_97 , void * V_96 )
{
struct V_1 * V_78 ;
struct V_69 * V_65 ;
struct V_36 * V_37 = V_96 ;
char * V_98 = L_2 ;
V_78 = F_73 ( V_37 , struct V_1 , V_9 ) ;
if ( V_78 -> V_8 . V_99 )
F_74 ( V_97 , L_3 , F_5 ( & V_78 -> V_8 )
? ( long ) ( V_78 -> V_8 . V_72 - V_73 ) / V_75 : 0 ) ;
else
F_74 ( V_97 , L_4 ) ;
F_74 ( V_97 , L_5 ,
V_78 -> V_20 . V_27 . V_28 ,
V_78 -> V_20 . V_23 . V_26 ) ;
F_75 ( V_97 , & V_78 -> V_20 ,
F_76 ( V_78 -> V_20 . V_27 . V_28 ) ,
F_77 ( V_78 -> V_20 . V_27 . V_28 ,
V_78 -> V_20 . V_23 . V_26 ) ) ;
if ( V_78 -> V_41 & V_43 ) {
F_74 ( V_97 , L_6 ) ;
V_98 = L_7 ;
}
if ( V_78 -> V_41 & V_42 ) {
F_74 ( V_97 , L_8 , V_98 ) ;
V_98 = L_7 ;
}
if ( V_78 -> V_41 & V_100 )
F_74 ( V_97 , L_9 , V_98 ) ;
V_65 = F_64 ( F_2 ( V_78 -> V_6 ) -> V_65 ) ;
if ( V_65 ) {
F_74 ( V_97 , L_10 , V_78 -> V_41 ? L_11 : L_2 , V_65 -> V_101 ) ;
if ( V_65 -> V_74 [ V_78 -> V_14 ] . V_101 )
F_74 ( V_97 , L_12 ,
V_65 -> V_74 [ V_78 -> V_14 ] . V_101 ) ;
}
return F_78 ( V_97 , '\n' ) ;
}
static int F_79 ( struct V_102 * V_102 , struct V_103 * V_103 )
{
return F_80 ( V_102 , V_103 , & V_104 ,
sizeof( struct V_91 ) ) ;
}
static int F_81 ( struct V_7 * V_7 )
{
#ifdef F_82
struct V_105 * V_106 ;
V_106 = F_83 ( V_7 , L_13 , 0440 , & V_107 ) ;
if ( ! V_106 )
return - V_108 ;
#endif
return 0 ;
}
static void F_84 ( struct V_7 * V_7 )
{
#ifdef F_82
F_85 ( V_7 , L_13 ) ;
#endif
}
int F_86 ( struct V_7 * V_7 )
{
int V_109 = - V_108 ;
if ( F_87 ( V_7 , & V_110 ) ) {
if ( ! V_33 ) {
V_33 = V_7 -> V_10 . V_111 / 256 ;
if ( ! V_33 )
V_33 = 1 ;
}
V_87 = V_33 * 4 ;
}
V_7 -> V_10 . V_11 = 0 ;
V_7 -> V_10 . V_71 = F_88 ( & V_33 , 0 ) ;
if ( V_7 -> V_10 . V_71 == NULL )
goto V_112;
if ( F_87 ( V_7 , & V_110 ) ) {
V_55 = F_89 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_55 )
goto V_113;
}
V_109 = F_81 ( V_7 ) ;
if ( V_109 < 0 )
goto V_114;
return 0 ;
V_114:
if ( F_87 ( V_7 , & V_110 ) )
F_90 ( V_55 ) ;
V_113:
F_91 ( V_7 -> V_10 . V_71 , V_33 ) ;
V_112:
return V_109 ;
}
void F_92 ( struct V_7 * V_7 )
{
F_84 ( V_7 ) ;
if ( F_87 ( V_7 , & V_110 ) ) {
F_93 () ;
F_90 ( V_55 ) ;
}
F_91 ( V_7 -> V_10 . V_71 , V_33 ) ;
}
