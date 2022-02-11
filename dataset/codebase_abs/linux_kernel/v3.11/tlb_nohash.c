static inline int F_1 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 ;
}
static inline int F_1 ( int V_1 )
{
return 0 ;
}
void F_2 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
F_3 () ;
V_6 = V_5 -> V_7 . V_8 ;
if ( V_6 != V_9 )
F_4 ( V_6 ) ;
F_5 () ;
}
void F_6 ( struct V_4 * V_5 , unsigned long V_10 ,
int V_11 , int V_12 )
{
unsigned int V_6 ;
F_3 () ;
V_6 = V_5 ? V_5 -> V_7 . V_8 : 0 ;
if ( V_6 != V_9 )
F_7 ( V_10 , V_6 , V_11 , V_12 ) ;
F_5 () ;
}
void F_8 ( struct V_13 * V_14 , unsigned long V_10 )
{
F_6 ( V_14 ? V_14 -> V_15 : NULL , V_10 ,
F_1 ( V_16 ) , 0 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
return F_10 ( F_11 ( V_5 ) ,
F_12 ( F_13 () ) ) ;
}
static void F_14 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_4 ( V_19 ? V_19 -> V_6 : 0 ) ;
}
static void F_15 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_7 ( V_19 -> V_20 , V_19 -> V_6 , V_19 -> V_11 , V_19 -> V_12 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
F_3 () ;
V_6 = V_5 -> V_7 . V_8 ;
if ( F_17 ( V_6 == V_9 ) )
goto V_21;
if ( ! F_9 ( V_5 ) ) {
struct V_18 V_19 = { . V_6 = V_6 } ;
F_18 ( F_11 ( V_5 ) ,
F_14 , & V_19 , 1 ) ;
}
F_4 ( V_6 ) ;
V_21:
F_5 () ;
}
void F_19 ( struct V_4 * V_5 , unsigned long V_10 ,
int V_11 , int V_12 )
{
struct V_22 * V_23 ;
unsigned int V_6 ;
F_3 () ;
V_6 = V_5 ? V_5 -> V_7 . V_8 : 0 ;
if ( F_17 ( V_6 == V_9 ) )
goto V_24;
V_23 = F_11 ( V_5 ) ;
if ( ! F_9 ( V_5 ) ) {
if ( F_20 ( V_25 ) ) {
int V_26 = F_20 ( V_27 ) ;
if ( V_26 )
F_21 ( & V_28 ) ;
F_22 ( V_10 , V_6 , V_11 , V_12 ) ;
if ( V_26 )
F_23 ( & V_28 ) ;
goto V_24;
} else {
struct V_18 V_19 = {
. V_6 = V_6 ,
. V_20 = V_10 ,
. V_11 = V_11 ,
. V_12 = V_12 ,
} ;
F_18 ( V_23 ,
F_15 , & V_19 , 1 ) ;
}
}
F_7 ( V_10 , V_6 , V_11 , V_12 ) ;
V_24:
F_5 () ;
}
void F_24 ( struct V_13 * V_14 , unsigned long V_10 )
{
#ifdef F_25
if ( F_26 ( V_14 ) )
F_27 ( V_14 , V_10 ) ;
#endif
F_19 ( V_14 ? V_14 -> V_15 : NULL , V_10 ,
F_1 ( V_16 ) , 0 ) ;
}
void T_1 F_28 ( void )
{
#ifdef F_29
unsigned long V_29 = F_30 () ;
if ( F_31 ( V_29 , L_1 , NULL ) )
F_32 ( V_25 ) ;
#endif
}
void F_33 ( unsigned long V_30 , unsigned long V_31 )
{
#ifdef F_29
F_3 () ;
F_34 ( F_14 , NULL , 1 ) ;
F_4 ( 0 ) ;
F_5 () ;
#else
F_4 ( 0 ) ;
#endif
}
void F_35 ( struct V_13 * V_14 , unsigned long V_30 ,
unsigned long V_31 )
{
F_16 ( V_14 -> V_15 ) ;
}
void F_36 ( struct V_32 * V_33 )
{
F_16 ( V_33 -> V_5 ) ;
}
void F_37 ( struct V_32 * V_33 , unsigned long V_34 )
{
int V_11 = V_2 [ V_35 ] . V_3 ;
if ( V_36 ) {
unsigned long V_30 = V_34 & V_37 ;
unsigned long V_31 = V_34 + V_38 ;
unsigned long V_39 = 1UL << V_2 [ V_35 ] . V_40 ;
while ( V_30 < V_31 ) {
F_19 ( V_33 -> V_5 , V_30 , V_11 , 1 ) ;
V_30 += V_39 ;
}
} else {
unsigned long V_41 = 0xf000000000000000ul ;
unsigned long V_42 = ( V_34 & V_41 ) | 0x1000000000000000ul ;
unsigned long V_43 = V_34 & ~ V_41 ;
#ifdef F_38
V_43 = ( V_43 >> ( V_44 - 4 ) ) & ~ 0xfffful ;
#else
V_43 = ( V_43 >> ( V_44 - 3 ) ) & ~ 0xffful ;
#endif
V_43 |= V_42 ;
F_19 ( V_33 -> V_5 , V_43 , V_11 , 0 ) ;
}
}
static void F_39 ( void )
{
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
int V_48 , V_1 ;
#ifdef F_40
unsigned int V_49 = F_41 ( V_50 ) ;
int V_51 = F_20 ( V_52 ) ;
if ( V_51 && ( V_49 & V_53 ) == V_54 ) {
unsigned int V_55 = F_41 ( V_56 ) ;
unsigned int V_57 , V_58 ;
V_57 = ( V_55 & V_59 ) >> V_60 ;
V_58 = ( V_55 & V_61 ) >> V_62 ;
for ( V_1 = 0 ; V_1 < V_63 ; ++ V_1 ) {
struct V_64 * V_65 ;
unsigned int V_40 ;
V_65 = & V_2 [ V_1 ] ;
V_40 = V_65 -> V_40 ;
if ( V_40 == 0 )
continue;
V_40 = ( V_40 - 10 ) >> 1 ;
if ( ( V_40 >= V_57 ) && ( V_40 <= V_58 ) )
V_65 -> V_66 |= V_67 ;
}
goto V_68;
}
if ( V_51 && ( V_49 & V_53 ) == V_69 ) {
T_2 V_70 = F_41 ( V_71 ) ;
for ( V_1 = 0 ; V_1 < V_63 ; ++ V_1 ) {
struct V_64 * V_65 = & V_2 [ V_1 ] ;
if ( V_70 & ( 1U << ( V_65 -> V_40 - 10 ) ) ) {
V_65 -> V_66 |= V_67 ;
}
}
goto V_68;
}
#endif
V_45 = F_41 ( V_72 ) ;
V_46 = F_41 ( V_73 ) ;
V_47 = F_41 ( V_74 ) ;
for ( V_1 = 0 ; V_1 < V_63 ; ++ V_1 ) {
struct V_64 * V_65 = & V_2 [ V_1 ] ;
if ( V_46 & ( 1U << ( V_65 -> V_40 - 10 ) ) )
V_65 -> V_66 |= V_67 ;
}
if ( ( V_45 & V_75 ) == 0 )
goto V_68;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
unsigned int V_76 , V_77 ;
V_77 = V_47 & 0x1f ;
V_47 >>= 5 ;
V_76 = V_47 & 0x1f ;
V_47 >>= 5 ;
if ( ! V_76 || ! V_77 )
continue;
for ( V_1 = 0 ; V_1 < V_63 ; V_1 ++ ) {
struct V_64 * V_65 = & V_2 [ V_1 ] ;
if ( V_76 == ( V_65 -> V_40 - 10 ) )
V_65 -> V_66 |= V_78 ;
if ( V_77 == ( V_65 -> V_40 - 10 ) )
V_65 -> V_12 = V_76 + 10 ;
}
}
V_68:
F_42 ( L_2 ) ;
for ( V_1 = 0 ; V_1 < V_63 ; ++ V_1 ) {
struct V_64 * V_65 = & V_2 [ V_1 ] ;
const char * V_79 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
if ( V_65 -> V_66 == 0 ) {
V_65 -> V_40 = 0 ;
continue;
}
F_42 ( L_7 , 1ul << ( V_65 -> V_40 - 10 ) ,
V_79 [ V_65 -> V_66 & 0x3 ] ) ;
}
}
static void F_43 ( int V_80 , unsigned long V_20 )
{
extern unsigned int V_81 ;
unsigned int * V_82 = & V_81 ;
F_44 ( V_82 + ( V_80 / 4 ) + 1 , V_20 , 0 ) ;
}
static void F_45 ( void )
{
unsigned int V_45 = F_41 ( V_72 ) ;
if ( ( V_45 & V_75 ) &&
( V_45 & V_83 ) ) {
F_46 ( 0x1c0 , V_84 ) ;
F_46 ( 0x1e0 , V_85 ) ;
V_36 = 1 ;
}
F_42 ( L_8 ,
V_36 ? L_9 : L_10 ) ;
}
static void F_47 ( int V_86 )
{
unsigned int V_87 ;
V_88 = V_89 ;
V_90 = V_91 ;
if ( V_86 ) {
F_39 () ;
F_45 () ;
}
V_87 = 0x4 << V_92 ;
if ( V_36 ) {
V_87 |= V_87 | V_93 ;
#ifdef F_38
V_87 |= V_94 << V_95 ;
V_35 = V_96 ;
#else
V_87 |= V_97 << V_95 ;
V_35 = V_98 ;
#endif
} else {
#ifdef F_38
V_87 |= V_99 << V_95 ;
#else
V_87 |= V_100 << V_95 ;
#endif
V_35 = V_16 ;
}
F_48 ( V_101 , V_87 ) ;
V_102 = F_49 () ;
#ifdef F_40
if ( F_20 ( V_52 ) ) {
unsigned int V_103 ;
V_103 = ( F_41 ( V_56 ) & V_104 ) / 4 ;
V_102 = F_50 ( V_102 , V_103 ) ;
F_51 ( V_102 ) ;
F_46 ( 0x1c0 , V_105 ) ;
F_46 ( 0x1e0 , V_106 ) ;
}
#endif
F_52 () ;
F_53 ( V_102 ) ;
}
void T_1 F_54 ( void )
{
F_47 ( 1 ) ;
}
void F_55 ( void )
{
F_47 ( 0 ) ;
}
void F_56 ( T_3 V_107 ,
T_3 V_108 )
{
#ifdef F_40
if ( F_20 ( V_52 ) ) {
unsigned long V_109 ;
V_109 = F_57 ( V_108 , V_110 ,
V_107 ) ;
V_111 = F_58 ( V_112 , V_109 , 0x40000000 ) ;
} else
#endif
V_111 = F_58 ( V_112 , V_108 , 0x40000000 ) ;
F_53 ( V_107 + V_111 ) ;
}
void T_1 F_54 ( void )
{
#ifdef F_59
F_28 () ;
#endif
}
