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
if ( F_16 ( F_31 ( exp -> V_6 ) ||
! F_26 ( & exp -> V_6 -> V_41 . V_38 ) ) )
return NULL ;
if ( exp -> V_39 & V_42 ) {
F_32 ( & exp -> V_38 ) ;
return exp ;
} else if ( F_33 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
return exp ;
}
F_34 ( exp -> V_6 ) ;
return NULL ;
}
void F_35 ( struct V_43 * V_10 )
{
struct V_4 * V_44 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_45 * V_46 ;
if ( ! V_44 )
return;
F_12 ( & V_18 ) ;
F_36 (exp, next, &help->expectations, lnode) {
if ( F_33 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
F_14 ( & V_18 ) ;
}
static inline int F_37 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
struct V_49 V_50 ;
int V_51 ;
V_50 . V_27 . V_31 . V_25 = V_47 -> V_37 . V_27 . V_31 . V_25 & V_48 -> V_37 . V_27 . V_31 . V_25 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_50 . V_27 . V_24 . V_25 [ V_51 ] =
V_47 -> V_37 . V_27 . V_24 . V_25 [ V_51 ] & V_48 -> V_37 . V_27 . V_24 . V_25 [ V_51 ] ;
}
return F_22 ( & V_47 -> V_20 , & V_48 -> V_20 , & V_50 ) ;
}
static inline int F_38 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
return V_47 -> V_6 == V_48 -> V_6 && V_47 -> V_14 == V_48 -> V_14 &&
F_39 ( & V_47 -> V_20 , & V_48 -> V_20 ) &&
F_40 ( & V_47 -> V_37 , & V_48 -> V_37 ) &&
F_23 ( V_47 -> V_6 ) == F_23 ( V_48 -> V_6 ) ;
}
void F_41 ( struct V_1 * exp )
{
F_12 ( & V_18 ) ;
if ( F_33 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
F_14 ( & V_18 ) ;
}
struct V_1 * F_42 ( struct V_43 * V_53 )
{
struct V_1 * V_54 ;
V_54 = F_43 ( V_55 , V_56 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_6 = V_53 ;
F_44 ( & V_54 -> V_38 , 1 ) ;
return V_54 ;
}
void F_45 ( struct V_1 * exp , unsigned int V_14 ,
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
exp -> V_39 = 0 ;
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
memset ( & exp -> V_37 . V_27 . V_24 , 0xFF , V_62 ) ;
if ( sizeof( exp -> V_37 . V_27 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_37 . V_27 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_37 . V_27 . V_24 ) - V_62 ) ;
} else {
memset ( & exp -> V_20 . V_27 . V_24 , 0x00 , sizeof( exp -> V_20 . V_27 . V_24 ) ) ;
memset ( & exp -> V_37 . V_27 . V_24 , 0x00 , sizeof( exp -> V_37 . V_27 . V_24 ) ) ;
}
if ( V_27 ) {
exp -> V_20 . V_27 . V_31 . V_25 = * V_27 ;
exp -> V_37 . V_27 . V_31 . V_25 = F_46 ( 0xFFFF ) ;
} else {
exp -> V_20 . V_27 . V_31 . V_25 = 0 ;
exp -> V_37 . V_27 . V_31 . V_25 = 0 ;
}
memcpy ( & exp -> V_20 . V_23 . V_24 , V_60 , V_62 ) ;
if ( sizeof( exp -> V_20 . V_23 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_20 . V_23 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_20 . V_23 . V_24 ) - V_62 ) ;
exp -> V_20 . V_23 . V_31 . V_25 = * V_23 ;
#ifdef F_47
memset ( & exp -> V_66 , 0 , sizeof( exp -> V_66 ) ) ;
memset ( & exp -> V_67 , 0 , sizeof( exp -> V_67 ) ) ;
#endif
}
static void F_48 ( struct V_68 * V_69 )
{
struct V_1 * exp ;
exp = F_49 ( V_69 , struct V_1 , V_70 ) ;
F_50 ( V_55 , exp ) ;
}
void F_9 ( struct V_1 * exp )
{
if ( F_51 ( & exp -> V_38 ) )
F_52 ( & exp -> V_70 , F_48 ) ;
}
static int F_53 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_71 * V_65 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_36 = F_15 ( & exp -> V_20 ) ;
F_54 ( 2 , & exp -> V_38 ) ;
F_55 ( & exp -> V_12 , & V_5 -> V_72 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_56 ( & exp -> V_9 , & V_7 -> V_10 . V_73 [ V_36 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_57 ( & exp -> V_8 , F_11 ,
( unsigned long ) exp ) ;
V_65 = F_58 ( V_5 -> V_65 ,
F_59 ( & V_18 ) ) ;
if ( V_65 ) {
exp -> V_8 . V_74 = V_75 +
V_65 -> V_76 [ exp -> V_14 ] . V_8 * V_77 ;
}
F_60 ( & exp -> V_8 ) ;
F_10 ( V_7 , V_78 ) ;
return 0 ;
}
static void F_61 ( struct V_43 * V_6 ,
struct V_1 * V_54 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_79 = NULL ;
F_29 (exp, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_54 -> V_14 )
V_79 = exp ;
}
if ( V_79 && F_33 ( & V_79 -> V_8 ) ) {
F_13 ( V_79 ) ;
F_9 ( V_79 ) ;
}
}
static inline int F_62 ( struct V_1 * V_80 )
{
const struct V_81 * V_82 ;
struct V_1 * V_35 ;
struct V_43 * V_6 = V_80 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_71 * V_65 ;
struct V_7 * V_7 = F_3 ( V_80 ) ;
struct V_45 * V_46 ;
unsigned int V_36 ;
int V_83 = 1 ;
if ( ! V_5 ) {
V_83 = - V_84 ;
goto V_85;
}
V_36 = F_15 ( & V_80 -> V_20 ) ;
F_36 (i, next, &net->ct.expect_hash[h], hnode) {
if ( F_38 ( V_35 , V_80 ) ) {
if ( F_33 ( & V_35 -> V_8 ) ) {
F_13 ( V_35 ) ;
F_9 ( V_35 ) ;
break;
}
} else if ( F_37 ( V_35 , V_80 ) ) {
V_83 = - V_86 ;
goto V_85;
}
}
V_65 = F_58 ( V_5 -> V_65 ,
F_59 ( & V_18 ) ) ;
if ( V_65 ) {
V_82 = & V_65 -> V_76 [ V_80 -> V_14 ] ;
if ( V_82 -> V_87 &&
V_5 -> V_13 [ V_80 -> V_14 ] >= V_82 -> V_87 ) {
F_61 ( V_6 , V_80 ) ;
if ( V_5 -> V_13 [ V_80 -> V_14 ]
>= V_82 -> V_87 ) {
V_83 = - V_88 ;
goto V_85;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_89 ) {
F_63 ( L_1 ) ;
V_83 = - V_88 ;
}
V_85:
return V_83 ;
}
int F_64 ( struct V_1 * V_80 ,
T_1 V_2 , int V_3 )
{
int V_83 ;
F_12 ( & V_18 ) ;
V_83 = F_62 ( V_80 ) ;
if ( V_83 <= 0 )
goto V_85;
V_83 = F_53 ( V_80 ) ;
if ( V_83 < 0 )
goto V_85;
F_14 ( & V_18 ) ;
F_8 ( V_90 , V_80 , V_2 , V_3 ) ;
return V_83 ;
V_85:
F_14 ( & V_18 ) ;
return V_83 ;
}
static struct V_45 * F_65 ( struct V_91 * V_92 )
{
struct V_7 * V_7 = F_66 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
struct V_45 * V_96 ;
for ( V_94 -> V_97 = 0 ; V_94 -> V_97 < V_33 ; V_94 -> V_97 ++ ) {
V_96 = F_67 ( F_68 ( & V_7 -> V_10 . V_73 [ V_94 -> V_97 ] ) ) ;
if ( V_96 )
return V_96 ;
}
return NULL ;
}
static struct V_45 * F_69 ( struct V_91 * V_92 ,
struct V_45 * V_69 )
{
struct V_7 * V_7 = F_66 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
V_69 = F_67 ( F_70 ( V_69 ) ) ;
while ( V_69 == NULL ) {
if ( ++ V_94 -> V_97 >= V_33 )
return NULL ;
V_69 = F_67 ( F_68 ( & V_7 -> V_10 . V_73 [ V_94 -> V_97 ] ) ) ;
}
return V_69 ;
}
static struct V_45 * F_71 ( struct V_91 * V_92 , T_5 V_98 )
{
struct V_45 * V_69 = F_65 ( V_92 ) ;
if ( V_69 )
while ( V_98 && ( V_69 = F_69 ( V_92 , V_69 ) ) )
V_98 -- ;
return V_98 ? NULL : V_69 ;
}
static void * F_72 ( struct V_91 * V_92 , T_5 * V_98 )
__acquires( T_6 )
{
F_25 () ;
return F_71 ( V_92 , * V_98 ) ;
}
static void * F_73 ( struct V_91 * V_92 , void * V_99 , T_5 * V_98 )
{
( * V_98 ) ++ ;
return F_69 ( V_92 , V_99 ) ;
}
static void F_74 ( struct V_91 * V_92 , void * V_99 )
__releases( T_6 )
{
F_27 () ;
}
static int F_75 ( struct V_91 * V_100 , void * V_99 )
{
struct V_1 * V_80 ;
struct V_71 * V_65 ;
struct V_45 * V_96 = V_99 ;
char * V_101 = L_2 ;
V_80 = F_76 ( V_96 , struct V_1 , V_9 ) ;
if ( V_80 -> V_8 . V_102 )
F_77 ( V_100 , L_3 , F_5 ( & V_80 -> V_8 )
? ( long ) ( V_80 -> V_8 . V_74 - V_75 ) / V_77 : 0 ) ;
else
F_77 ( V_100 , L_4 ) ;
F_77 ( V_100 , L_5 ,
V_80 -> V_20 . V_27 . V_28 ,
V_80 -> V_20 . V_23 . V_26 ) ;
F_78 ( V_100 , & V_80 -> V_20 ,
F_79 ( V_80 -> V_20 . V_27 . V_28 ) ,
F_80 ( V_80 -> V_20 . V_27 . V_28 ,
V_80 -> V_20 . V_23 . V_26 ) ) ;
if ( V_80 -> V_39 & V_42 ) {
F_77 ( V_100 , L_6 ) ;
V_101 = L_7 ;
}
if ( V_80 -> V_39 & V_40 ) {
F_77 ( V_100 , L_8 , V_101 ) ;
V_101 = L_7 ;
}
if ( V_80 -> V_39 & V_103 )
F_77 ( V_100 , L_9 , V_101 ) ;
V_65 = F_67 ( F_2 ( V_80 -> V_6 ) -> V_65 ) ;
if ( V_65 ) {
F_77 ( V_100 , L_10 , V_80 -> V_39 ? L_11 : L_2 , V_65 -> V_104 ) ;
if ( V_65 -> V_76 [ V_80 -> V_14 ] . V_104 )
F_77 ( V_100 , L_12 ,
V_65 -> V_76 [ V_80 -> V_14 ] . V_104 ) ;
}
return F_81 ( V_100 , '\n' ) ;
}
static int F_82 ( struct V_105 * V_105 , struct V_106 * V_106 )
{
return F_83 ( V_105 , V_106 , & V_107 ,
sizeof( struct V_93 ) ) ;
}
static int F_84 ( struct V_7 * V_7 )
{
#ifdef F_85
struct V_108 * V_109 ;
V_109 = F_86 ( L_13 , 0440 , V_7 -> V_110 ,
& V_111 ) ;
if ( ! V_109 )
return - V_112 ;
#endif
return 0 ;
}
static void F_87 ( struct V_7 * V_7 )
{
#ifdef F_85
F_88 ( L_13 , V_7 -> V_110 ) ;
#endif
}
int F_89 ( struct V_7 * V_7 )
{
int V_113 = - V_112 ;
V_7 -> V_10 . V_11 = 0 ;
V_7 -> V_10 . V_73 = F_90 ( & V_33 , 0 ) ;
if ( V_7 -> V_10 . V_73 == NULL )
goto V_114;
V_113 = F_84 ( V_7 ) ;
if ( V_113 < 0 )
goto V_115;
return 0 ;
V_115:
F_91 ( V_7 -> V_10 . V_73 , V_33 ) ;
V_114:
return V_113 ;
}
void F_92 ( struct V_7 * V_7 )
{
F_87 ( V_7 ) ;
F_91 ( V_7 -> V_10 . V_73 , V_33 ) ;
}
int F_93 ( void )
{
if ( ! V_33 ) {
V_33 = V_116 / 256 ;
if ( ! V_33 )
V_33 = 1 ;
}
V_89 = V_33 * 4 ;
V_55 = F_94 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_55 )
return - V_112 ;
return 0 ;
}
void F_95 ( void )
{
F_96 () ;
F_97 ( V_55 ) ;
}
