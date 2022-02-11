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
return F_20 ( V_21 , V_32 ) ;
}
struct V_1 *
F_21 ( struct V_7 * V_7 ,
const struct V_33 * V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 ;
unsigned int V_36 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_36 = F_15 ( V_20 ) ;
F_22 (i, &net->ct.expect_hash[h], hnode) {
if ( F_23 ( V_20 , & V_35 -> V_20 , & V_35 -> V_37 ) &&
F_24 ( V_35 -> V_6 , V_34 ) )
return V_35 ;
}
return NULL ;
}
struct V_1 *
F_25 ( struct V_7 * V_7 ,
const struct V_33 * V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 ;
F_26 () ;
V_35 = F_21 ( V_7 , V_34 , V_20 ) ;
if ( V_35 && ! F_27 ( & V_35 -> V_38 ) )
V_35 = NULL ;
F_28 () ;
return V_35 ;
}
struct V_1 *
F_29 ( struct V_7 * V_7 ,
const struct V_33 * V_34 ,
const struct V_19 * V_20 )
{
struct V_1 * V_35 , * exp = NULL ;
unsigned int V_36 ;
if ( ! V_7 -> V_10 . V_11 )
return NULL ;
V_36 = F_15 ( V_20 ) ;
F_30 (i, &net->ct.expect_hash[h], hnode) {
if ( ! ( V_35 -> V_39 & V_40 ) &&
F_23 ( V_20 , & V_35 -> V_20 , & V_35 -> V_37 ) &&
F_24 ( V_35 -> V_6 , V_34 ) ) {
exp = V_35 ;
break;
}
}
if ( ! exp )
return NULL ;
if ( ! F_31 ( exp -> V_6 ) )
return NULL ;
if ( F_16 ( F_32 ( exp -> V_6 ) ||
! F_27 ( & exp -> V_6 -> V_41 . V_38 ) ) )
return NULL ;
if ( exp -> V_39 & V_42 ) {
F_33 ( & exp -> V_38 ) ;
return exp ;
} else if ( F_34 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
return exp ;
}
F_35 ( exp -> V_6 ) ;
return NULL ;
}
void F_36 ( struct V_43 * V_10 )
{
struct V_4 * V_44 = F_2 ( V_10 ) ;
struct V_1 * exp ;
struct V_45 * V_46 ;
if ( ! V_44 )
return;
F_12 ( & V_18 ) ;
F_37 (exp, next, &help->expectations, lnode) {
if ( F_34 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
}
F_14 ( & V_18 ) ;
}
static inline int F_38 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
struct V_49 V_50 ;
int V_51 ;
V_50 . V_27 . V_31 . V_25 = V_47 -> V_37 . V_27 . V_31 . V_25 & V_48 -> V_37 . V_27 . V_31 . V_25 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_50 . V_27 . V_24 . V_25 [ V_51 ] =
V_47 -> V_37 . V_27 . V_24 . V_25 [ V_51 ] & V_48 -> V_37 . V_27 . V_24 . V_25 [ V_51 ] ;
}
return F_23 ( & V_47 -> V_20 , & V_48 -> V_20 , & V_50 ) &&
F_24 ( V_47 -> V_6 , F_39 ( V_48 -> V_6 ) ) ;
}
static inline int F_40 ( const struct V_1 * V_47 ,
const struct V_1 * V_48 )
{
return V_47 -> V_6 == V_48 -> V_6 && V_47 -> V_14 == V_48 -> V_14 &&
F_41 ( & V_47 -> V_20 , & V_48 -> V_20 ) &&
F_42 ( & V_47 -> V_37 , & V_48 -> V_37 ) &&
F_24 ( V_47 -> V_6 , F_39 ( V_48 -> V_6 ) ) ;
}
void F_43 ( struct V_1 * exp )
{
F_12 ( & V_18 ) ;
if ( F_34 ( & exp -> V_8 ) ) {
F_13 ( exp ) ;
F_9 ( exp ) ;
}
F_14 ( & V_18 ) ;
}
struct V_1 * F_44 ( struct V_43 * V_53 )
{
struct V_1 * V_54 ;
V_54 = F_45 ( V_55 , V_56 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_6 = V_53 ;
F_46 ( & V_54 -> V_38 , 1 ) ;
return V_54 ;
}
void F_47 ( struct V_1 * exp , unsigned int V_14 ,
T_2 V_57 ,
const union V_58 * V_59 ,
const union V_58 * V_60 ,
T_2 V_61 , const T_3 * V_27 , const T_3 * V_23 )
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
exp -> V_37 . V_27 . V_31 . V_25 = F_48 ( 0xFFFF ) ;
} else {
exp -> V_20 . V_27 . V_31 . V_25 = 0 ;
exp -> V_37 . V_27 . V_31 . V_25 = 0 ;
}
memcpy ( & exp -> V_20 . V_23 . V_24 , V_60 , V_62 ) ;
if ( sizeof( exp -> V_20 . V_23 . V_24 ) > V_62 )
memset ( ( void * ) & exp -> V_20 . V_23 . V_24 + V_62 , 0x00 ,
sizeof( exp -> V_20 . V_23 . V_24 ) - V_62 ) ;
exp -> V_20 . V_23 . V_31 . V_25 = * V_23 ;
#ifdef F_49
memset ( & exp -> V_66 , 0 , sizeof( exp -> V_66 ) ) ;
memset ( & exp -> V_67 , 0 , sizeof( exp -> V_67 ) ) ;
#endif
}
static void F_50 ( struct V_68 * V_69 )
{
struct V_1 * exp ;
exp = F_51 ( V_69 , struct V_1 , V_70 ) ;
F_52 ( V_55 , exp ) ;
}
void F_9 ( struct V_1 * exp )
{
if ( F_53 ( & exp -> V_38 ) )
F_54 ( & exp -> V_70 , F_50 ) ;
}
static int F_55 ( struct V_1 * exp )
{
struct V_4 * V_5 = F_2 ( exp -> V_6 ) ;
struct V_71 * V_65 ;
struct V_7 * V_7 = F_3 ( exp ) ;
unsigned int V_36 = F_15 ( & exp -> V_20 ) ;
F_56 ( 2 , & exp -> V_38 ) ;
F_57 ( & exp -> V_12 , & V_5 -> V_72 ) ;
V_5 -> V_13 [ exp -> V_14 ] ++ ;
F_58 ( & exp -> V_9 , & V_7 -> V_10 . V_73 [ V_36 ] ) ;
V_7 -> V_10 . V_11 ++ ;
F_59 ( & exp -> V_8 , F_11 ,
( unsigned long ) exp ) ;
V_65 = F_60 ( V_5 -> V_65 ,
F_61 ( & V_18 ) ) ;
if ( V_65 ) {
exp -> V_8 . V_74 = V_75 +
V_65 -> V_76 [ exp -> V_14 ] . V_8 * V_77 ;
}
F_62 ( & exp -> V_8 ) ;
F_10 ( V_7 , V_78 ) ;
return 0 ;
}
static void F_63 ( struct V_43 * V_6 ,
struct V_1 * V_54 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
struct V_1 * exp , * V_79 = NULL ;
F_30 (exp, &master_help->expectations, lnode) {
if ( exp -> V_14 == V_54 -> V_14 )
V_79 = exp ;
}
if ( V_79 && F_34 ( & V_79 -> V_8 ) ) {
F_13 ( V_79 ) ;
F_9 ( V_79 ) ;
}
}
static inline int F_64 ( struct V_1 * V_80 )
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
F_37 (i, next, &net->ct.expect_hash[h], hnode) {
if ( F_40 ( V_35 , V_80 ) ) {
if ( F_34 ( & V_35 -> V_8 ) ) {
F_13 ( V_35 ) ;
F_9 ( V_35 ) ;
break;
}
} else if ( F_38 ( V_35 , V_80 ) ) {
V_83 = - V_86 ;
goto V_85;
}
}
V_65 = F_60 ( V_5 -> V_65 ,
F_61 ( & V_18 ) ) ;
if ( V_65 ) {
V_82 = & V_65 -> V_76 [ V_80 -> V_14 ] ;
if ( V_82 -> V_87 &&
V_5 -> V_13 [ V_80 -> V_14 ] >= V_82 -> V_87 ) {
F_63 ( V_6 , V_80 ) ;
if ( V_5 -> V_13 [ V_80 -> V_14 ]
>= V_82 -> V_87 ) {
V_83 = - V_88 ;
goto V_85;
}
}
}
if ( V_7 -> V_10 . V_11 >= V_89 ) {
F_65 ( L_1 ) ;
V_83 = - V_88 ;
}
V_85:
return V_83 ;
}
int F_66 ( struct V_1 * V_80 ,
T_1 V_2 , int V_3 )
{
int V_83 ;
F_12 ( & V_18 ) ;
V_83 = F_64 ( V_80 ) ;
if ( V_83 <= 0 )
goto V_85;
V_83 = F_55 ( V_80 ) ;
if ( V_83 < 0 )
goto V_85;
F_14 ( & V_18 ) ;
F_8 ( V_90 , V_80 , V_2 , V_3 ) ;
return V_83 ;
V_85:
F_14 ( & V_18 ) ;
return V_83 ;
}
static struct V_45 * F_67 ( struct V_91 * V_92 )
{
struct V_7 * V_7 = F_68 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
struct V_45 * V_96 ;
for ( V_94 -> V_97 = 0 ; V_94 -> V_97 < V_32 ; V_94 -> V_97 ++ ) {
V_96 = F_69 ( F_70 ( & V_7 -> V_10 . V_73 [ V_94 -> V_97 ] ) ) ;
if ( V_96 )
return V_96 ;
}
return NULL ;
}
static struct V_45 * F_71 ( struct V_91 * V_92 ,
struct V_45 * V_69 )
{
struct V_7 * V_7 = F_68 ( V_92 ) ;
struct V_93 * V_94 = V_92 -> V_95 ;
V_69 = F_69 ( F_72 ( V_69 ) ) ;
while ( V_69 == NULL ) {
if ( ++ V_94 -> V_97 >= V_32 )
return NULL ;
V_69 = F_69 ( F_70 ( & V_7 -> V_10 . V_73 [ V_94 -> V_97 ] ) ) ;
}
return V_69 ;
}
static struct V_45 * F_73 ( struct V_91 * V_92 , T_4 V_98 )
{
struct V_45 * V_69 = F_67 ( V_92 ) ;
if ( V_69 )
while ( V_98 && ( V_69 = F_71 ( V_92 , V_69 ) ) )
V_98 -- ;
return V_98 ? NULL : V_69 ;
}
static void * F_74 ( struct V_91 * V_92 , T_4 * V_98 )
__acquires( T_5 )
{
F_26 () ;
return F_73 ( V_92 , * V_98 ) ;
}
static void * F_75 ( struct V_91 * V_92 , void * V_99 , T_4 * V_98 )
{
( * V_98 ) ++ ;
return F_71 ( V_92 , V_99 ) ;
}
static void F_76 ( struct V_91 * V_92 , void * V_99 )
__releases( T_5 )
{
F_28 () ;
}
static int F_77 ( struct V_91 * V_100 , void * V_99 )
{
struct V_1 * V_80 ;
struct V_71 * V_65 ;
struct V_45 * V_96 = V_99 ;
char * V_101 = L_2 ;
V_80 = F_78 ( V_96 , struct V_1 , V_9 ) ;
if ( V_80 -> V_8 . V_102 )
F_79 ( V_100 , L_3 , F_5 ( & V_80 -> V_8 )
? ( long ) ( V_80 -> V_8 . V_74 - V_75 ) / V_77 : 0 ) ;
else
F_79 ( V_100 , L_4 ) ;
F_79 ( V_100 , L_5 ,
V_80 -> V_20 . V_27 . V_28 ,
V_80 -> V_20 . V_23 . V_26 ) ;
F_80 ( V_100 , & V_80 -> V_20 ,
F_81 ( V_80 -> V_20 . V_27 . V_28 ) ,
F_82 ( V_80 -> V_20 . V_27 . V_28 ,
V_80 -> V_20 . V_23 . V_26 ) ) ;
if ( V_80 -> V_39 & V_42 ) {
F_79 ( V_100 , L_6 ) ;
V_101 = L_7 ;
}
if ( V_80 -> V_39 & V_40 ) {
F_79 ( V_100 , L_8 , V_101 ) ;
V_101 = L_7 ;
}
if ( V_80 -> V_39 & V_103 )
F_79 ( V_100 , L_9 , V_101 ) ;
V_65 = F_69 ( F_2 ( V_80 -> V_6 ) -> V_65 ) ;
if ( V_65 ) {
F_79 ( V_100 , L_10 , V_80 -> V_39 ? L_11 : L_2 , V_65 -> V_104 ) ;
if ( V_65 -> V_76 [ V_80 -> V_14 ] . V_104 )
F_79 ( V_100 , L_12 ,
V_65 -> V_76 [ V_80 -> V_14 ] . V_104 ) ;
}
F_83 ( V_100 , '\n' ) ;
return 0 ;
}
static int F_84 ( struct V_105 * V_105 , struct V_106 * V_106 )
{
return F_85 ( V_105 , V_106 , & V_107 ,
sizeof( struct V_93 ) ) ;
}
static int F_86 ( struct V_7 * V_7 )
{
#ifdef F_87
struct V_108 * V_109 ;
T_6 V_110 ;
T_7 V_111 ;
V_109 = F_88 ( L_13 , 0440 , V_7 -> V_112 ,
& V_113 ) ;
if ( ! V_109 )
return - V_114 ;
V_110 = F_89 ( V_7 -> V_115 , 0 ) ;
V_111 = F_90 ( V_7 -> V_115 , 0 ) ;
if ( F_91 ( V_110 ) && F_92 ( V_111 ) )
F_93 ( V_109 , V_110 , V_111 ) ;
#endif
return 0 ;
}
static void F_94 ( struct V_7 * V_7 )
{
#ifdef F_87
F_95 ( L_13 , V_7 -> V_112 ) ;
#endif
}
int F_96 ( struct V_7 * V_7 )
{
int V_116 = - V_114 ;
V_7 -> V_10 . V_11 = 0 ;
V_7 -> V_10 . V_73 = F_97 ( & V_32 , 0 ) ;
if ( V_7 -> V_10 . V_73 == NULL )
goto V_117;
V_116 = F_86 ( V_7 ) ;
if ( V_116 < 0 )
goto V_118;
return 0 ;
V_118:
F_98 ( V_7 -> V_10 . V_73 , V_32 ) ;
V_117:
return V_116 ;
}
void F_99 ( struct V_7 * V_7 )
{
F_94 ( V_7 ) ;
F_98 ( V_7 -> V_10 . V_73 , V_32 ) ;
}
int F_100 ( void )
{
if ( ! V_32 ) {
V_32 = V_119 / 256 ;
if ( ! V_32 )
V_32 = 1 ;
}
V_89 = V_32 * 4 ;
V_55 = F_101 ( L_13 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_55 )
return - V_114 ;
return 0 ;
}
void F_102 ( void )
{
F_103 () ;
F_104 ( V_55 ) ;
}
