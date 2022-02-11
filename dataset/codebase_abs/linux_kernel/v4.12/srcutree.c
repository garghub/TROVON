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
F_4 ( & V_12 -> V_17 ) ;
F_5 ( F_6 ( V_12 -> V_18 ) !=
F_6 ( V_12 -> V_19 ) ) ;
for ( V_5 = 0 ; V_5 < F_6 ( V_12 -> V_18 ) ; V_5 ++ ) {
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
F_5 ( F_6 ( V_10 -> V_24 ) !=
F_6 ( V_10 -> V_25 ) ) ;
V_6 = V_15 - 1 ;
V_13 = V_2 -> V_6 [ V_6 ] ;
F_7 (cpu) {
V_10 = F_8 ( V_2 -> V_26 , V_4 ) ;
F_4 ( & V_10 -> V_17 ) ;
F_9 ( & V_10 -> V_27 ) ;
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
F_10 ( & V_10 -> V_32 , V_33 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_34 = 1 << ( V_4 - V_10 -> V_31 -> V_21 ) ;
if ( V_3 )
continue;
for ( V_5 = 0 ; V_5 < F_6 ( V_10 -> V_24 ) ; V_5 ++ ) {
V_10 -> V_24 [ V_5 ] = 0 ;
V_10 -> V_25 [ V_5 ] = 0 ;
}
}
}
static int F_11 ( struct V_1 * V_2 , bool V_3 )
{
F_12 ( & V_2 -> V_35 ) ;
F_12 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_30 = 0 ;
V_2 -> V_38 = 0 ;
F_12 ( & V_2 -> V_39 ) ;
F_13 ( & V_2 -> V_40 , 0 ) ;
F_10 ( & V_2 -> V_32 , V_41 ) ;
if ( ! V_3 )
V_2 -> V_26 = F_14 ( struct V_9 ) ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_20 = 0 ;
V_2 -> V_42 = F_15 () ;
F_16 ( & V_2 -> V_29 , 0 ) ;
return V_2 -> V_26 ? 0 : - V_43 ;
}
int F_17 ( struct V_1 * V_2 , const char * V_44 ,
struct V_45 * V_46 )
{
F_18 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_19 ( & V_2 -> V_47 , V_44 , V_46 , 0 ) ;
F_4 ( & V_2 -> V_48 ) ;
return F_11 ( V_2 , false ) ;
}
int F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_48 ) ;
return F_11 ( V_2 , false ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
F_5 ( V_50 == V_51 ) ;
if ( ! F_22 ( F_23 ( & V_2 -> V_29 ) ) )
return;
F_24 ( & V_2 -> V_48 , V_49 ) ;
if ( ! F_22 ( V_2 -> V_29 ) ) {
F_25 ( & V_2 -> V_48 , V_49 ) ;
return;
}
F_11 ( V_2 , true ) ;
F_25 ( & V_2 -> V_48 , V_49 ) ;
}
static unsigned long F_26 ( struct V_1 * V_2 , int V_52 )
{
int V_4 ;
unsigned long V_53 = 0 ;
F_7 (cpu) {
struct V_9 * V_54 = F_8 ( V_2 -> V_26 , V_4 ) ;
V_53 += F_27 ( V_54 -> V_24 [ V_52 ] ) ;
}
return V_53 ;
}
static unsigned long F_28 ( struct V_1 * V_2 , int V_52 )
{
int V_4 ;
unsigned long V_53 = 0 ;
F_7 (cpu) {
struct V_9 * V_54 = F_8 ( V_2 -> V_26 , V_4 ) ;
V_53 += F_27 ( V_54 -> V_25 [ V_52 ] ) ;
}
return V_53 ;
}
static bool F_29 ( struct V_1 * V_2 , int V_52 )
{
unsigned long V_55 ;
V_55 = F_28 ( V_2 , V_52 ) ;
F_30 () ;
return F_26 ( V_2 , V_52 ) == V_55 ;
}
static bool F_31 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned long V_53 = 0 ;
F_7 (cpu) {
struct V_9 * V_54 = F_8 ( V_2 -> V_26 , V_4 ) ;
V_53 += F_27 ( V_54 -> V_24 [ 0 ] ) ;
V_53 += F_27 ( V_54 -> V_24 [ 1 ] ) ;
V_53 -= F_27 ( V_54 -> V_25 [ 0 ] ) ;
V_53 -= F_27 ( V_54 -> V_25 [ 1 ] ) ;
}
return V_53 ;
}
static unsigned long F_32 ( struct V_1 * V_2 )
{
if ( F_33 ( F_27 ( V_2 -> V_30 ) ,
F_27 ( V_2 -> V_20 ) ) )
return 0 ;
return V_56 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_4 ;
if ( F_35 ( ! F_32 ( V_2 ) ) )
return;
if ( F_35 ( F_31 ( V_2 ) ) )
return;
F_36 ( & V_2 -> V_32 ) ;
F_7 (cpu)
F_36 ( & F_8 ( V_2 -> V_26 , V_4 ) -> V_32 ) ;
if ( F_35 ( F_22 ( F_27 ( V_2 -> V_30 ) ) != V_57 ) ||
F_35 ( F_31 ( V_2 ) ) ) {
F_37 ( L_1 , V_2 , F_22 ( F_27 ( V_2 -> V_30 ) ) ) ;
return;
}
F_38 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_27 ( V_2 -> V_37 ) & 0x1 ;
F_40 ( V_2 -> V_26 -> V_24 [ V_52 ] ) ;
F_30 () ;
return V_52 ;
}
void F_41 ( struct V_1 * V_2 , int V_52 )
{
F_30 () ;
F_40 ( V_2 -> V_26 -> V_25 [ V_52 ] ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_43 ( V_2 -> V_26 ) ;
int V_58 ;
F_44 ( ! F_45 ( & V_2 -> V_48 ) ,
L_2 ) ;
F_5 ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
( void ) F_49 ( & V_10 -> V_27 ,
F_50 ( & V_2 -> V_30 ) ) ;
F_30 () ;
F_51 ( & V_2 -> V_30 ) ;
V_58 = F_22 ( F_27 ( V_2 -> V_30 ) ) ;
F_5 ( V_58 != V_59 ) ;
}
void F_52 ( unsigned int V_4 )
{
F_53 ( F_54 ( V_60 , V_4 ) , true ) ;
}
void F_55 ( unsigned int V_4 )
{
F_53 ( F_54 ( V_60 , V_4 ) , false ) ;
}
static bool F_56 ( int V_4 , struct V_61 * V_62 ,
struct V_63 * V_64 ,
unsigned long V_65 )
{
bool V_66 ;
F_57 () ;
if ( F_27 ( F_54 ( V_60 , V_4 ) ) )
V_66 = F_58 ( V_4 , V_62 , V_64 , V_65 ) ;
else
V_66 = F_59 ( V_62 , V_64 , V_65 ) ;
F_60 () ;
return V_66 ;
}
static void F_61 ( struct V_9 * V_10 , unsigned long V_65 )
{
F_56 ( V_10 -> V_4 , V_67 ,
& V_10 -> V_32 , V_65 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_12 ,
unsigned long V_68 , unsigned long V_65 )
{
int V_4 ;
for ( V_4 = V_12 -> V_21 ; V_4 <= V_12 -> V_22 ; V_4 ++ ) {
if ( ! ( V_68 & ( 1 << ( V_4 - V_12 -> V_21 ) ) ) )
continue;
F_61 ( F_8 ( V_2 -> V_26 , V_4 ) , V_65 ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned long V_69 ;
bool V_70 ;
unsigned long V_71 ;
int V_52 ;
int V_72 ;
unsigned long V_68 ;
struct V_11 * V_12 ;
F_64 ( & V_2 -> V_35 ) ;
F_65 ( & V_2 -> V_48 ) ;
V_52 = F_22 ( V_2 -> V_30 ) ;
F_5 ( V_52 != V_73 ) ;
V_69 = F_32 ( V_2 ) ;
V_2 -> V_42 = F_15 () ;
F_66 ( & V_2 -> V_30 ) ;
V_71 = F_48 ( & V_2 -> V_30 ) ;
if ( F_33 ( V_2 -> V_20 , V_71 ) )
V_2 -> V_20 = V_71 ;
F_67 ( & V_2 -> V_48 ) ;
F_68 ( & V_2 -> V_36 ) ;
V_52 = F_69 ( V_71 ) % F_6 ( V_12 -> V_18 ) ;
V_72 = ( V_52 + 1 ) % F_6 ( V_12 -> V_18 ) ;
F_3 (sp, snp) {
F_65 ( & V_12 -> V_17 ) ;
V_70 = false ;
if ( V_12 >= V_2 -> V_6 [ V_15 - 1 ] )
V_70 = V_12 -> V_18 [ V_52 ] == V_71 ;
V_12 -> V_18 [ V_52 ] = V_71 ;
F_70 ( & V_12 -> V_18 [ V_52 ] , 1 ) ;
if ( F_33 ( V_12 -> V_20 , V_71 ) )
V_12 -> V_20 = V_71 ;
V_68 = V_12 -> V_19 [ V_52 ] ;
V_12 -> V_19 [ V_52 ] = 0 ;
F_67 ( & V_12 -> V_17 ) ;
if ( V_70 ) {
F_30 () ;
F_62 ( V_2 , V_12 , V_68 , V_69 ) ;
}
}
F_68 ( & V_2 -> V_35 ) ;
F_65 ( & V_2 -> V_48 ) ;
V_71 = F_48 ( & V_2 -> V_30 ) ;
if ( ! F_22 ( V_71 ) &&
F_33 ( V_71 , V_2 -> V_29 ) ) {
F_42 ( V_2 ) ;
F_67 ( & V_2 -> V_48 ) ;
F_71 ( V_2 , F_69 ( V_71 ) & 0x3ff
? 0 : V_56 ) ;
} else {
F_67 ( & V_2 -> V_48 ) ;
}
}
static void F_72 ( struct V_1 * V_2 , struct V_11 * V_12 ,
unsigned long V_74 )
{
unsigned long V_49 ;
for (; V_12 != NULL ; V_12 = V_12 -> V_23 ) {
if ( F_73 ( & V_2 -> V_30 , V_74 ) ||
F_46 ( F_27 ( V_12 -> V_20 ) , V_74 ) )
return;
F_24 ( & V_12 -> V_17 , V_49 ) ;
if ( F_46 ( V_12 -> V_20 , V_74 ) ) {
F_25 ( & V_12 -> V_17 , V_49 ) ;
return;
}
F_53 ( V_12 -> V_20 , V_74 ) ;
F_25 ( & V_12 -> V_17 , V_49 ) ;
}
F_24 ( & V_2 -> V_48 , V_49 ) ;
if ( ! F_33 ( V_2 -> V_20 , V_74 ) )
V_2 -> V_20 = V_74 ;
F_25 ( & V_2 -> V_48 , V_49 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned long V_74 , bool V_75 )
{
unsigned long V_49 ;
int V_52 = F_69 ( V_74 ) % F_6 ( V_10 -> V_31 -> V_18 ) ;
struct V_11 * V_12 = V_10 -> V_31 ;
unsigned long V_76 ;
for (; V_12 != NULL ; V_12 = V_12 -> V_23 ) {
if ( F_73 ( & V_2 -> V_30 , V_74 ) && V_12 != V_10 -> V_31 )
return;
F_24 ( & V_12 -> V_17 , V_49 ) ;
if ( F_46 ( V_12 -> V_18 [ V_52 ] , V_74 ) ) {
V_76 = V_12 -> V_18 [ V_52 ] ;
if ( V_12 == V_10 -> V_31 && V_76 == V_74 )
V_12 -> V_19 [ V_52 ] |= V_10 -> V_34 ;
F_25 ( & V_12 -> V_17 , V_49 ) ;
if ( V_12 == V_10 -> V_31 && V_76 != V_74 ) {
F_30 () ;
F_61 ( V_10 , V_75
? V_56
: 0 ) ;
return;
}
if ( ! V_75 )
F_72 ( V_2 , V_12 , V_74 ) ;
return;
}
V_12 -> V_18 [ V_52 ] = V_74 ;
if ( V_12 == V_10 -> V_31 )
V_12 -> V_19 [ V_52 ] |= V_10 -> V_34 ;
if ( ! V_75 && F_33 ( V_12 -> V_20 , V_74 ) )
V_12 -> V_20 = V_74 ;
F_25 ( & V_12 -> V_17 , V_49 ) ;
}
F_24 ( & V_2 -> V_48 , V_49 ) ;
if ( F_33 ( V_2 -> V_29 , V_74 ) ) {
F_16 ( & V_2 -> V_29 , V_74 ) ;
}
if ( ! V_75 && F_33 ( V_2 -> V_20 , V_74 ) )
V_2 -> V_20 = V_74 ;
if ( ! F_73 ( & V_2 -> V_30 , V_74 ) &&
F_22 ( V_2 -> V_30 ) == V_57 ) {
F_5 ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) ;
F_42 ( V_2 ) ;
F_59 ( V_67 , & V_2 -> V_32 ,
F_32 ( V_2 ) ) ;
}
F_25 ( & V_2 -> V_48 , V_49 ) ;
}
static bool F_75 ( struct V_1 * V_2 , int V_52 , int V_77 )
{
for (; ; ) {
if ( F_29 ( V_2 , V_52 ) )
return true ;
if ( -- V_77 + ! F_32 ( V_2 ) <= 0 )
return false ;
F_76 ( V_78 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
F_53 ( V_2 -> V_37 , V_2 -> V_37 + 1 ) ;
F_30 () ;
}
static bool F_78 ( struct V_1 * V_2 )
{
unsigned long V_79 ;
unsigned long V_49 ;
struct V_9 * V_10 ;
unsigned long V_80 ;
F_79 ( V_49 ) ;
V_10 = F_43 ( V_2 -> V_26 ) ;
if ( F_80 ( & V_10 -> V_27 ) ) {
F_81 ( V_49 ) ;
return false ;
}
F_81 ( V_49 ) ;
V_80 = F_15 () ;
if ( V_81 == 0 ||
F_82 ( V_80 , V_2 -> V_42 ,
V_2 -> V_42 + V_81 ) )
return false ;
V_79 = F_48 ( & V_2 -> V_30 ) ;
F_30 () ;
if ( F_33 ( V_79 , F_27 ( V_2 -> V_29 ) ) )
return false ;
F_30 () ;
if ( V_79 != F_48 ( & V_2 -> V_30 ) )
return false ;
return true ;
}
void F_83 ( struct V_1 * V_2 , struct V_82 * V_83 ,
T_1 V_84 , bool V_75 )
{
unsigned long V_49 ;
bool V_85 = false ;
bool V_86 = false ;
unsigned long V_74 ;
struct V_9 * V_10 ;
F_21 ( V_2 ) ;
V_83 -> V_84 = V_84 ;
F_79 ( V_49 ) ;
V_10 = F_43 ( V_2 -> V_26 ) ;
F_84 ( & V_10 -> V_17 ) ;
F_85 ( & V_10 -> V_27 , V_83 , false ) ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
V_74 = F_50 ( & V_2 -> V_30 ) ;
( void ) F_49 ( & V_10 -> V_27 , V_74 ) ;
if ( F_33 ( V_10 -> V_29 , V_74 ) ) {
V_10 -> V_29 = V_74 ;
V_86 = true ;
}
if ( ! V_75 && F_33 ( V_10 -> V_20 , V_74 ) ) {
V_10 -> V_20 = V_74 ;
V_85 = true ;
}
F_25 ( & V_10 -> V_17 , V_49 ) ;
if ( V_86 )
F_74 ( V_2 , V_10 , V_74 , V_75 ) ;
else if ( V_85 )
F_72 ( V_2 , V_10 -> V_31 , V_74 ) ;
}
void F_86 ( struct V_1 * V_2 , struct V_82 * V_83 ,
T_1 V_84 )
{
F_83 ( V_2 , V_83 , V_84 , true ) ;
}
static void F_87 ( struct V_1 * V_2 , bool V_75 )
{
struct V_87 V_88 ;
F_44 ( F_88 ( & V_2 -> V_47 ) ||
F_88 ( & V_89 ) ||
F_88 ( & V_90 ) ||
F_88 ( & V_91 ) ,
L_3 ) ;
if ( V_50 == V_92 )
return;
F_89 () ;
F_21 ( V_2 ) ;
F_90 ( & V_88 . V_93 ) ;
F_91 ( & V_88 . V_94 ) ;
F_83 ( V_2 , & V_88 . V_94 , V_95 , V_75 ) ;
F_92 ( & V_88 . V_93 ) ;
F_93 ( & V_88 . V_94 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_87 ( V_2 , F_95 () ) ;
}
void F_96 ( struct V_1 * V_2 )
{
if ( F_78 ( V_2 ) || F_97 () )
F_94 ( V_2 ) ;
else
F_87 ( V_2 , true ) ;
}
static void F_98 ( struct V_82 * V_83 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_99 ( V_83 , struct V_9 , V_96 ) ;
V_2 = V_10 -> V_2 ;
if ( F_100 ( & V_2 -> V_40 ) )
F_101 ( & V_2 -> V_97 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_9 * V_10 ;
unsigned long V_74 = F_50 ( & V_2 -> V_38 ) ;
F_21 ( V_2 ) ;
F_64 ( & V_2 -> V_39 ) ;
if ( F_73 ( & V_2 -> V_38 , V_74 ) ) {
F_30 () ;
F_68 ( & V_2 -> V_39 ) ;
return;
}
F_51 ( & V_2 -> V_38 ) ;
F_90 ( & V_2 -> V_97 ) ;
F_13 ( & V_2 -> V_40 , 1 ) ;
F_7 (cpu) {
V_10 = F_8 ( V_2 -> V_26 , V_4 ) ;
F_65 ( & V_10 -> V_17 ) ;
F_103 ( & V_2 -> V_40 ) ;
V_10 -> V_96 . V_84 = F_98 ;
if ( ! F_104 ( & V_10 -> V_27 ,
& V_10 -> V_96 , 0 ) )
F_105 ( & V_2 -> V_40 ) ;
F_67 ( & V_10 -> V_17 ) ;
}
if ( F_100 ( & V_2 -> V_40 ) )
F_101 ( & V_2 -> V_97 ) ;
F_92 ( & V_2 -> V_97 ) ;
F_66 ( & V_2 -> V_38 ) ;
F_68 ( & V_2 -> V_39 ) ;
}
unsigned long F_106 ( struct V_1 * V_2 )
{
return V_2 -> V_37 ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_52 ;
F_64 ( & V_2 -> V_36 ) ;
V_52 = F_22 ( F_23 ( & V_2 -> V_30 ) ) ;
if ( V_52 == V_57 ) {
F_65 ( & V_2 -> V_48 ) ;
if ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) {
F_5 ( F_22 ( V_2 -> V_30 ) ) ;
F_67 ( & V_2 -> V_48 ) ;
F_68 ( & V_2 -> V_36 ) ;
return;
}
V_52 = F_22 ( F_27 ( V_2 -> V_30 ) ) ;
if ( V_52 == V_57 )
F_42 ( V_2 ) ;
F_67 ( & V_2 -> V_48 ) ;
if ( V_52 != V_57 ) {
F_68 ( & V_2 -> V_36 ) ;
return;
}
}
if ( F_22 ( F_27 ( V_2 -> V_30 ) ) == V_59 ) {
V_52 = 1 ^ ( V_2 -> V_37 & 1 ) ;
if ( ! F_75 ( V_2 , V_52 , 1 ) ) {
F_68 ( & V_2 -> V_36 ) ;
return;
}
F_77 ( V_2 ) ;
F_70 ( & V_2 -> V_30 , V_73 ) ;
}
if ( F_22 ( F_27 ( V_2 -> V_30 ) ) == V_73 ) {
V_52 = 1 ^ ( V_2 -> V_37 & 1 ) ;
if ( ! F_75 ( V_2 , V_52 , 2 ) ) {
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
V_10 = F_99 ( V_32 , struct V_9 , V_32 . V_32 ) ;
V_2 = V_10 -> V_2 ;
F_108 ( & V_101 ) ;
F_65 ( & V_10 -> V_17 ) ;
F_30 () ;
F_47 ( & V_10 -> V_27 ,
F_48 ( & V_2 -> V_30 ) ) ;
if ( V_10 -> V_28 ||
! F_109 ( & V_10 -> V_27 ) ) {
F_67 ( & V_10 -> V_17 ) ;
return;
}
V_10 -> V_28 = true ;
F_110 ( & V_10 -> V_27 , & V_101 ) ;
F_67 ( & V_10 -> V_17 ) ;
V_83 = F_111 ( & V_101 ) ;
for (; V_83 != NULL ; V_83 = F_111 ( & V_101 ) ) {
F_112 () ;
V_83 -> V_84 ( V_83 ) ;
F_113 () ;
}
F_65 ( & V_10 -> V_17 ) ;
F_114 ( & V_10 -> V_27 , & V_101 ) ;
( void ) F_49 ( & V_10 -> V_27 ,
F_50 ( & V_2 -> V_30 ) ) ;
V_10 -> V_28 = false ;
V_99 = F_109 ( & V_10 -> V_27 ) ;
F_67 ( & V_10 -> V_17 ) ;
if ( V_99 )
F_61 ( V_10 , 0 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned long V_65 )
{
bool V_102 = true ;
F_65 ( & V_2 -> V_48 ) ;
if ( F_46 ( V_2 -> V_30 , V_2 -> V_29 ) ) {
if ( ! F_5 ( F_22 ( V_2 -> V_30 ) ) ) {
V_102 = false ;
}
} else if ( ! F_22 ( V_2 -> V_30 ) ) {
F_42 ( V_2 ) ;
}
F_67 ( & V_2 -> V_48 ) ;
if ( V_102 )
F_59 ( V_67 , & V_2 -> V_32 , V_65 ) ;
}
void V_41 ( struct V_98 * V_32 )
{
struct V_1 * V_2 ;
V_2 = F_99 ( V_32 , struct V_1 , V_32 . V_32 ) ;
F_107 ( V_2 ) ;
F_71 ( V_2 , F_32 ( V_2 ) ) ;
}
void F_115 ( enum V_103 V_104 ,
struct V_1 * V_2 , int * V_49 ,
unsigned long * V_105 , unsigned long * V_106 )
{
if ( V_104 != V_107 )
return;
* V_49 = 0 ;
* V_106 = F_69 ( V_2 -> V_30 ) ;
* V_105 = F_69 ( V_2 -> V_29 ) ;
}
