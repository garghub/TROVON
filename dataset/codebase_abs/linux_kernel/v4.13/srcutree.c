static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
int V_5 ;
int V_6 = 0 ;
int V_7 [ V_8 ] ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_11 * V_13 ;
V_2 -> V_6 [ 0 ] = & V_2 -> V_14 [ 0 ] ;
for ( V_5 = 1 ; V_5 < V_15 ; V_5 ++ )
V_2 -> V_6 [ V_5 ] = V_2 -> V_6 [ V_5 - 1 ] + V_16 [ V_5 - 1 ] ;
F_2 ( V_7 , V_16 ) ;
F_3 (sp, snp) {
F_4 ( & F_5 ( V_12 , V_17 ) ) ;
F_6 ( F_7 ( V_12 -> V_18 ) !=
F_7 ( V_12 -> V_19 ) ) ;
for ( V_5 = 0 ; V_5 < F_7 ( V_12 -> V_18 ) ; V_5 ++ ) {
V_12 -> V_18 [ V_5 ] = 0 ;
V_12 -> V_19 [ V_5 ] = 0 ;
}
V_12 -> V_20 = 0 ;
V_12 -> V_21 = - 1 ;
V_12 -> V_22 = - 1 ;
if ( V_12 == & V_2 -> V_14 [ 0 ] ) {
V_12 -> V_23 = NULL ;
continue;
}
if ( V_12 == V_2 -> V_6 [ V_6 + 1 ] )
V_6 ++ ;
V_12 -> V_23 = V_2 -> V_6 [ V_6 - 1 ] +
( V_12 - V_2 -> V_6 [ V_6 ] ) /
V_7 [ V_6 - 1 ] ;
}
F_6 ( F_7 ( V_10 -> V_24 ) !=
F_7 ( V_10 -> V_25 ) ) ;
V_6 = V_15 - 1 ;
V_13 = V_2 -> V_6 [ V_6 ] ;
F_8 (cpu) {
V_10 = F_9 ( V_2 -> V_26 , V_4 ) ;
F_4 ( & F_5 ( V_10 , V_17 ) ) ;
F_10 ( & V_10 -> V_27 ) ;
V_10 -> V_28 = false ;
V_10 -> V_29 = V_2 -> V_30 ;
V_10 -> V_20 = V_2 -> V_30 ;
V_10 -> V_31 = & V_13 [ V_4 / V_7 [ V_6 ] ] ;
for ( V_12 = V_10 -> V_31 ; V_12 != NULL ; V_12 = V_12 -> V_23 ) {
if ( V_12 -> V_21 < 0 )
V_12 -> V_21 = V_4 ;
V_12 -> V_22 = V_4 ;
}
V_10 -> V_4 = V_4 ;
F_11 ( & V_10 -> V_32 , V_33 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_34 = 1 << ( V_4 - V_10 -> V_31 -> V_21 ) ;
if ( V_3 )
continue;
for ( V_5 = 0 ; V_5 < F_7 ( V_10 -> V_24 ) ; V_5 ++ ) {
V_10 -> V_24 [ V_5 ] = 0 ;
V_10 -> V_25 [ V_5 ] = 0 ;
}
}
}
static int F_12 ( struct V_1 * V_2 , bool V_3 )
{
F_13 ( & V_2 -> V_35 ) ;
F_13 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_30 = 0 ;
V_2 -> V_38 = 0 ;
F_13 ( & V_2 -> V_39 ) ;
F_14 ( & V_2 -> V_40 , 0 ) ;
F_11 ( & V_2 -> V_32 , V_41 ) ;
if ( ! V_3 )
V_2 -> V_26 = F_15 ( struct V_9 ) ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_20 = 0 ;
V_2 -> V_42 = F_16 () ;
F_17 ( & V_2 -> V_29 , 0 ) ;
return V_2 -> V_26 ? 0 : - V_43 ;
}
int F_18 ( struct V_1 * V_2 , const char * V_44 ,
struct V_45 * V_46 )
{
F_19 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_20 ( & V_2 -> V_47 , V_44 , V_46 , 0 ) ;
F_4 ( & F_5 ( V_2 , V_17 ) ) ;
return F_12 ( V_2 , false ) ;
}
int F_21 ( struct V_1 * V_2 )
{
F_4 ( & F_5 ( V_2 , V_17 ) ) ;
return F_12 ( V_2 , false ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_48 ;
F_6 ( V_49 == V_50 ) ;
if ( ! F_23 ( F_24 ( & V_2 -> V_29 ) ) )
return;
F_25 ( V_2 , V_48 ) ;
if ( ! F_23 ( V_2 -> V_29 ) ) {
F_26 ( V_2 , V_48 ) ;
return;
}
F_12 ( V_2 , true ) ;
F_26 ( V_2 , V_48 ) ;
}
static unsigned long F_27 ( struct V_1 * V_2 , int V_51 )
{
int V_4 ;
unsigned long V_52 = 0 ;
F_8 (cpu) {
struct V_9 * V_53 = F_9 ( V_2 -> V_26 , V_4 ) ;
V_52 += F_28 ( V_53 -> V_24 [ V_51 ] ) ;
}
return V_52 ;
}
static unsigned long F_29 ( struct V_1 * V_2 , int V_51 )
{
int V_4 ;
unsigned long V_52 = 0 ;
F_8 (cpu) {
struct V_9 * V_53 = F_9 ( V_2 -> V_26 , V_4 ) ;
V_52 += F_28 ( V_53 -> V_25 [ V_51 ] ) ;
}
return V_52 ;
}
static bool F_30 ( struct V_1 * V_2 , int V_51 )
{
unsigned long V_54 ;
V_54 = F_29 ( V_2 , V_51 ) ;
F_31 () ;
return F_27 ( V_2 , V_51 ) == V_54 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned long V_52 = 0 ;
F_8 (cpu) {
struct V_9 * V_53 = F_9 ( V_2 -> V_26 , V_4 ) ;
V_52 += F_28 ( V_53 -> V_24 [ 0 ] ) ;
V_52 += F_28 ( V_53 -> V_24 [ 1 ] ) ;
V_52 -= F_28 ( V_53 -> V_25 [ 0 ] ) ;
V_52 -= F_28 ( V_53 -> V_25 [ 1 ] ) ;
}
return V_52 ;
}
static unsigned long F_33 ( struct V_1 * V_2 )
{
if ( F_34 ( F_28 ( V_2 -> V_30 ) ,
F_28 ( V_2 -> V_20 ) ) )
return 0 ;
return V_55 ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_4 ;
if ( F_36 ( ! F_33 ( V_2 ) ) )
return;
if ( F_36 ( F_32 ( V_2 ) ) )
return;
F_37 ( & V_2 -> V_32 ) ;
F_8 (cpu)
F_37 ( & F_9 ( V_2 -> V_26 , V_4 ) -> V_32 ) ;
if ( F_36 ( F_23 ( F_28 ( V_2 -> V_30 ) ) != V_56 ) ||
F_36 ( F_32 ( V_2 ) ) ) {
F_38 ( L_1 , V_2 , F_23 ( F_28 ( V_2 -> V_30 ) ) ) ;
return;
}
F_39 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_28 ( V_2 -> V_37 ) & 0x1 ;
F_41 ( V_2 -> V_26 -> V_24 [ V_51 ] ) ;
F_31 () ;
return V_51 ;
}
void F_42 ( struct V_1 * V_2 , int V_51 )
{
F_31 () ;
F_41 ( V_2 -> V_26 -> V_25 [ V_51 ] ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_44 ( V_2 -> V_26 ) ;
int V_57 ;
F_45 ( & V_2 -> V_17 ) ;
F_6 ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
( void ) F_49 ( & V_10 -> V_27 ,
F_50 ( & V_2 -> V_30 ) ) ;
F_31 () ;
F_51 ( & V_2 -> V_30 ) ;
V_57 = F_23 ( F_28 ( V_2 -> V_30 ) ) ;
F_6 ( V_57 != V_58 ) ;
}
void F_52 ( unsigned int V_4 )
{
F_53 ( F_54 ( V_59 , V_4 ) , true ) ;
}
void F_55 ( unsigned int V_4 )
{
F_53 ( F_54 ( V_59 , V_4 ) , false ) ;
}
static bool F_56 ( int V_4 , struct V_60 * V_61 ,
struct V_62 * V_63 ,
unsigned long V_64 )
{
bool V_65 ;
F_57 () ;
if ( F_28 ( F_54 ( V_59 , V_4 ) ) )
V_65 = F_58 ( V_4 , V_61 , V_63 , V_64 ) ;
else
V_65 = F_59 ( V_61 , V_63 , V_64 ) ;
F_60 () ;
return V_65 ;
}
static void F_61 ( struct V_9 * V_10 , unsigned long V_64 )
{
F_56 ( V_10 -> V_4 , V_66 ,
& V_10 -> V_32 , V_64 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_12 ,
unsigned long V_67 , unsigned long V_64 )
{
int V_4 ;
for ( V_4 = V_12 -> V_21 ; V_4 <= V_12 -> V_22 ; V_4 ++ ) {
if ( ! ( V_67 & ( 1 << ( V_4 - V_12 -> V_21 ) ) ) )
continue;
F_61 ( F_9 ( V_2 -> V_26 , V_4 ) , V_64 ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
bool V_69 ;
int V_4 ;
unsigned long V_48 ;
unsigned long V_70 ;
int V_51 ;
int V_71 ;
unsigned long V_67 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
F_64 ( & V_2 -> V_35 ) ;
F_65 ( V_2 ) ;
V_51 = F_23 ( V_2 -> V_30 ) ;
F_6 ( V_51 != V_72 ) ;
V_68 = F_33 ( V_2 ) ;
V_2 -> V_42 = F_16 () ;
F_66 ( & V_2 -> V_30 ) ;
V_70 = F_48 ( & V_2 -> V_30 ) ;
if ( F_34 ( V_2 -> V_20 , V_70 ) )
V_2 -> V_20 = V_70 ;
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_36 ) ;
V_51 = F_69 ( V_70 ) % F_7 ( V_12 -> V_18 ) ;
V_71 = ( V_51 + 1 ) % F_7 ( V_12 -> V_18 ) ;
F_3 (sp, snp) {
F_65 ( V_12 ) ;
V_69 = false ;
if ( V_12 >= V_2 -> V_6 [ V_15 - 1 ] )
V_69 = V_12 -> V_18 [ V_51 ] == V_70 ;
V_12 -> V_18 [ V_51 ] = V_70 ;
F_70 ( & V_12 -> V_18 [ V_51 ] , 1 ) ;
if ( F_34 ( V_12 -> V_20 , V_70 ) )
V_12 -> V_20 = V_70 ;
V_67 = V_12 -> V_19 [ V_51 ] ;
V_12 -> V_19 [ V_51 ] = 0 ;
F_67 ( V_12 ) ;
if ( V_69 )
F_62 ( V_2 , V_12 , V_67 , V_68 ) ;
if ( ! ( V_70 & V_73 ) )
for ( V_4 = V_12 -> V_21 ; V_4 <= V_12 -> V_22 ; V_4 ++ ) {
V_10 = F_9 ( V_2 -> V_26 , V_4 ) ;
F_25 ( V_10 , V_48 ) ;
if ( F_46 ( V_70 ,
V_10 -> V_29 + 100 ) )
V_10 -> V_29 = V_70 ;
F_26 ( V_10 , V_48 ) ;
}
}
F_68 ( & V_2 -> V_35 ) ;
F_65 ( V_2 ) ;
V_70 = F_48 ( & V_2 -> V_30 ) ;
if ( ! F_23 ( V_70 ) &&
F_34 ( V_70 , V_2 -> V_29 ) ) {
F_43 ( V_2 ) ;
F_67 ( V_2 ) ;
F_71 ( V_2 , F_69 ( V_70 ) & 0x3ff
? 0 : V_55 ) ;
} else {
F_67 ( V_2 ) ;
}
}
static void F_72 ( struct V_1 * V_2 , struct V_11 * V_12 ,
unsigned long V_74 )
{
unsigned long V_48 ;
for (; V_12 != NULL ; V_12 = V_12 -> V_23 ) {
if ( F_73 ( & V_2 -> V_30 , V_74 ) ||
F_46 ( F_28 ( V_12 -> V_20 ) , V_74 ) )
return;
F_25 ( V_12 , V_48 ) ;
if ( F_46 ( V_12 -> V_20 , V_74 ) ) {
F_26 ( V_12 , V_48 ) ;
return;
}
F_53 ( V_12 -> V_20 , V_74 ) ;
F_26 ( V_12 , V_48 ) ;
}
F_25 ( V_2 , V_48 ) ;
if ( ! F_34 ( V_2 -> V_20 , V_74 ) )
V_2 -> V_20 = V_74 ;
F_26 ( V_2 , V_48 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned long V_74 , bool V_75 )
{
unsigned long V_48 ;
int V_51 = F_69 ( V_74 ) % F_7 ( V_10 -> V_31 -> V_18 ) ;
struct V_11 * V_12 = V_10 -> V_31 ;
unsigned long V_76 ;
for (; V_12 != NULL ; V_12 = V_12 -> V_23 ) {
if ( F_73 ( & V_2 -> V_30 , V_74 ) && V_12 != V_10 -> V_31 )
return;
F_25 ( V_12 , V_48 ) ;
if ( F_46 ( V_12 -> V_18 [ V_51 ] , V_74 ) ) {
V_76 = V_12 -> V_18 [ V_51 ] ;
if ( V_12 == V_10 -> V_31 && V_76 == V_74 )
V_12 -> V_19 [ V_51 ] |= V_10 -> V_34 ;
F_26 ( V_12 , V_48 ) ;
if ( V_12 == V_10 -> V_31 && V_76 != V_74 ) {
F_61 ( V_10 , V_75
? V_55
: 0 ) ;
return;
}
if ( ! V_75 )
F_72 ( V_2 , V_12 , V_74 ) ;
return;
}
V_12 -> V_18 [ V_51 ] = V_74 ;
if ( V_12 == V_10 -> V_31 )
V_12 -> V_19 [ V_51 ] |= V_10 -> V_34 ;
if ( ! V_75 && F_34 ( V_12 -> V_20 , V_74 ) )
V_12 -> V_20 = V_74 ;
F_26 ( V_12 , V_48 ) ;
}
F_25 ( V_2 , V_48 ) ;
if ( F_34 ( V_2 -> V_29 , V_74 ) ) {
F_17 ( & V_2 -> V_29 , V_74 ) ;
}
if ( ! V_75 && F_34 ( V_2 -> V_20 , V_74 ) )
V_2 -> V_20 = V_74 ;
if ( ! F_73 ( & V_2 -> V_30 , V_74 ) &&
F_23 ( V_2 -> V_30 ) == V_56 ) {
F_6 ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) ;
F_43 ( V_2 ) ;
F_59 ( V_66 , & V_2 -> V_32 ,
F_33 ( V_2 ) ) ;
}
F_26 ( V_2 , V_48 ) ;
}
static bool F_75 ( struct V_1 * V_2 , int V_51 , int V_77 )
{
for (; ; ) {
if ( F_30 ( V_2 , V_51 ) )
return true ;
if ( -- V_77 + ! F_33 ( V_2 ) <= 0 )
return false ;
F_76 ( V_78 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
F_31 () ;
F_53 ( V_2 -> V_37 , V_2 -> V_37 + 1 ) ;
F_31 () ;
}
static bool F_78 ( struct V_1 * V_2 )
{
unsigned long V_79 ;
unsigned long V_48 ;
struct V_9 * V_10 ;
unsigned long V_80 ;
F_79 ( V_48 ) ;
V_10 = F_44 ( V_2 -> V_26 ) ;
if ( F_80 ( & V_10 -> V_27 ) ) {
F_81 ( V_48 ) ;
return false ;
}
F_81 ( V_48 ) ;
V_80 = F_16 () ;
if ( V_81 == 0 ||
F_82 ( V_80 , V_2 -> V_42 ,
V_2 -> V_42 + V_81 ) )
return false ;
V_79 = F_48 ( & V_2 -> V_30 ) ;
F_31 () ;
if ( F_34 ( V_79 , F_28 ( V_2 -> V_29 ) ) )
return false ;
F_31 () ;
if ( V_79 != F_48 ( & V_2 -> V_30 ) )
return false ;
return true ;
}
static void F_83 ( struct V_82 * V_83 )
{
}
void F_84 ( struct V_1 * V_2 , struct V_82 * V_83 ,
T_1 V_84 , bool V_75 )
{
unsigned long V_48 ;
bool V_85 = false ;
bool V_86 = false ;
unsigned long V_74 ;
struct V_9 * V_10 ;
F_22 ( V_2 ) ;
if ( F_85 ( V_83 ) ) {
F_53 ( V_83 -> V_84 , F_83 ) ;
F_86 ( 1 , L_2 ) ;
return;
}
V_83 -> V_84 = V_84 ;
F_79 ( V_48 ) ;
V_10 = F_44 ( V_2 -> V_26 ) ;
F_87 ( V_10 ) ;
F_88 ( & V_10 -> V_27 , V_83 , false ) ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
V_74 = F_50 ( & V_2 -> V_30 ) ;
( void ) F_49 ( & V_10 -> V_27 , V_74 ) ;
if ( F_34 ( V_10 -> V_29 , V_74 ) ) {
V_10 -> V_29 = V_74 ;
V_86 = true ;
}
if ( ! V_75 && F_34 ( V_10 -> V_20 , V_74 ) ) {
V_10 -> V_20 = V_74 ;
V_85 = true ;
}
F_26 ( V_10 , V_48 ) ;
if ( V_86 )
F_74 ( V_2 , V_10 , V_74 , V_75 ) ;
else if ( V_85 )
F_72 ( V_2 , V_10 -> V_31 , V_74 ) ;
}
void F_89 ( struct V_1 * V_2 , struct V_82 * V_83 ,
T_1 V_84 )
{
F_84 ( V_2 , V_83 , V_84 , true ) ;
}
static void F_90 ( struct V_1 * V_2 , bool V_75 )
{
struct V_87 V_88 ;
F_91 ( F_92 ( & V_2 -> V_47 ) ||
F_92 ( & V_89 ) ||
F_92 ( & V_90 ) ||
F_92 ( & V_91 ) ,
L_3 ) ;
if ( V_49 == V_92 )
return;
F_93 () ;
F_22 ( V_2 ) ;
F_94 ( & V_88 . V_93 ) ;
F_95 ( & V_88 . V_94 ) ;
F_84 ( V_2 , & V_88 . V_94 , V_95 , V_75 ) ;
F_96 ( & V_88 . V_93 ) ;
F_97 ( & V_88 . V_94 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
F_90 ( V_2 , F_99 () ) ;
}
void F_100 ( struct V_1 * V_2 )
{
if ( F_78 ( V_2 ) || F_101 () )
F_98 ( V_2 ) ;
else
F_90 ( V_2 , true ) ;
}
static void F_102 ( struct V_82 * V_83 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_103 ( V_83 , struct V_9 , V_96 ) ;
V_2 = V_10 -> V_2 ;
if ( F_104 ( & V_2 -> V_40 ) )
F_105 ( & V_2 -> V_97 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_9 * V_10 ;
unsigned long V_74 = F_50 ( & V_2 -> V_38 ) ;
F_22 ( V_2 ) ;
F_64 ( & V_2 -> V_39 ) ;
if ( F_73 ( & V_2 -> V_38 , V_74 ) ) {
F_31 () ;
F_68 ( & V_2 -> V_39 ) ;
return;
}
F_51 ( & V_2 -> V_38 ) ;
F_94 ( & V_2 -> V_97 ) ;
F_14 ( & V_2 -> V_40 , 1 ) ;
F_8 (cpu) {
V_10 = F_9 ( V_2 -> V_26 , V_4 ) ;
F_65 ( V_10 ) ;
F_107 ( & V_2 -> V_40 ) ;
V_10 -> V_96 . V_84 = F_102 ;
F_85 ( & V_10 -> V_96 ) ;
if ( ! F_108 ( & V_10 -> V_27 ,
& V_10 -> V_96 , 0 ) ) {
F_109 ( & V_10 -> V_96 ) ;
F_110 ( & V_2 -> V_40 ) ;
}
F_67 ( V_10 ) ;
}
if ( F_104 ( & V_2 -> V_40 ) )
F_105 ( & V_2 -> V_97 ) ;
F_96 ( & V_2 -> V_97 ) ;
F_66 ( & V_2 -> V_38 ) ;
F_68 ( & V_2 -> V_39 ) ;
}
unsigned long F_111 ( struct V_1 * V_2 )
{
return V_2 -> V_37 ;
}
static void F_112 ( struct V_1 * V_2 )
{
int V_51 ;
F_64 ( & V_2 -> V_36 ) ;
V_51 = F_23 ( F_24 ( & V_2 -> V_30 ) ) ;
if ( V_51 == V_56 ) {
F_65 ( V_2 ) ;
if ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) {
F_6 ( F_23 ( V_2 -> V_30 ) ) ;
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_36 ) ;
return;
}
V_51 = F_23 ( F_28 ( V_2 -> V_30 ) ) ;
if ( V_51 == V_56 )
F_43 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( V_51 != V_56 ) {
F_68 ( & V_2 -> V_36 ) ;
return;
}
}
if ( F_23 ( F_28 ( V_2 -> V_30 ) ) == V_58 ) {
V_51 = 1 ^ ( V_2 -> V_37 & 1 ) ;
if ( ! F_75 ( V_2 , V_51 , 1 ) ) {
F_68 ( & V_2 -> V_36 ) ;
return;
}
F_77 ( V_2 ) ;
F_70 ( & V_2 -> V_30 , V_72 ) ;
}
if ( F_23 ( F_28 ( V_2 -> V_30 ) ) == V_72 ) {
V_51 = 1 ^ ( V_2 -> V_37 & 1 ) ;
if ( ! F_75 ( V_2 , V_51 , 2 ) ) {
F_68 ( & V_2 -> V_36 ) ;
return;
}
F_63 ( V_2 ) ;
}
}
static void V_33 ( struct V_98 * V_32 )
{
bool V_99 ;
struct V_100 V_101 ;
struct V_82 * V_83 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_103 ( V_32 , struct V_9 , V_32 . V_32 ) ;
V_2 = V_10 -> V_2 ;
F_113 ( & V_101 ) ;
F_65 ( V_10 ) ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
if ( V_10 -> V_28 ||
! F_114 ( & V_10 -> V_27 ) ) {
F_67 ( V_10 ) ;
return;
}
V_10 -> V_28 = true ;
F_115 ( & V_10 -> V_27 , & V_101 ) ;
F_67 ( V_10 ) ;
V_83 = F_116 ( & V_101 ) ;
for (; V_83 != NULL ; V_83 = F_116 ( & V_101 ) ) {
F_109 ( V_83 ) ;
F_117 () ;
V_83 -> V_84 ( V_83 ) ;
F_118 () ;
}
F_65 ( V_10 ) ;
F_119 ( & V_10 -> V_27 , & V_101 ) ;
( void ) F_49 ( & V_10 -> V_27 ,
F_50 ( & V_2 -> V_30 ) ) ;
V_10 -> V_28 = false ;
V_99 = F_114 ( & V_10 -> V_27 ) ;
F_67 ( V_10 ) ;
if ( V_99 )
F_61 ( V_10 , 0 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned long V_64 )
{
bool V_102 = true ;
F_65 ( V_2 ) ;
if ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) {
if ( ! F_6 ( F_23 ( V_2 -> V_30 ) ) ) {
V_102 = false ;
}
} else if ( ! F_23 ( V_2 -> V_30 ) ) {
F_43 ( V_2 ) ;
}
F_67 ( V_2 ) ;
if ( V_102 )
F_59 ( V_66 , & V_2 -> V_32 , V_64 ) ;
}
void V_41 ( struct V_98 * V_32 )
{
struct V_1 * V_2 ;
V_2 = F_103 ( V_32 , struct V_1 , V_32 . V_32 ) ;
F_112 ( V_2 ) ;
F_71 ( V_2 , F_33 ( V_2 ) ) ;
}
void F_120 ( enum V_103 V_104 ,
struct V_1 * V_2 , int * V_48 ,
unsigned long * V_105 , unsigned long * V_106 )
{
if ( V_104 != V_107 )
return;
* V_48 = 0 ;
* V_106 = F_69 ( V_2 -> V_30 ) ;
* V_105 = F_69 ( V_2 -> V_29 ) ;
}
static int T_2 F_121 ( void )
{
F_38 ( L_4 ) ;
if ( V_81 != V_108 )
F_38 ( L_5 , V_81 ) ;
return 0 ;
}
