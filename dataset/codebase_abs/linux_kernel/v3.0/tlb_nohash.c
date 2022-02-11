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
F_19 ( V_14 ? V_14 -> V_15 : NULL , V_10 ,
F_1 ( V_16 ) , 0 ) ;
}
void F_25 ( unsigned long V_29 , unsigned long V_30 )
{
#ifdef F_26
F_3 () ;
F_27 ( F_14 , NULL , 1 ) ;
F_4 ( 0 ) ;
F_5 () ;
#else
F_4 ( 0 ) ;
#endif
}
void F_28 ( struct V_13 * V_14 , unsigned long V_29 ,
unsigned long V_30 )
{
F_16 ( V_14 -> V_15 ) ;
}
void F_29 ( struct V_31 * V_32 )
{
F_16 ( V_32 -> V_5 ) ;
}
void F_30 ( struct V_31 * V_32 , unsigned long V_33 )
{
int V_11 = V_2 [ V_34 ] . V_3 ;
if ( V_35 ) {
unsigned long V_29 = V_33 & V_36 ;
unsigned long V_30 = V_33 + V_37 ;
unsigned long V_38 = 1UL << V_2 [ V_34 ] . V_39 ;
while ( V_29 < V_30 ) {
F_19 ( V_32 -> V_5 , V_29 , V_11 , 1 ) ;
V_29 += V_38 ;
}
} else {
unsigned long V_40 = 0xf000000000000000ul ;
unsigned long V_41 = ( V_33 & V_40 ) | 0x1000000000000000ul ;
unsigned long V_42 = V_33 & ~ V_40 ;
#ifdef F_31
V_42 = ( V_42 >> ( V_43 - 4 ) ) & ~ 0xfffful ;
#else
V_42 = ( V_42 >> ( V_43 - 3 ) ) & ~ 0xffful ;
#endif
V_42 |= V_41 ;
F_19 ( V_32 -> V_5 , V_42 , V_11 , 0 ) ;
}
}
static void F_32 ( void )
{
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
int V_47 , V_1 ;
#ifdef F_33
unsigned int V_48 = F_34 ( V_49 ) ;
if ( ( ( V_48 & V_50 ) == V_51 ) &&
( F_20 ( V_52 ) ) ) {
unsigned int V_53 = F_34 ( V_54 ) ;
unsigned int V_55 , V_56 ;
V_55 = ( V_53 & V_57 ) >> V_58 ;
V_56 = ( V_53 & V_59 ) >> V_60 ;
for ( V_1 = 0 ; V_1 < V_61 ; ++ V_1 ) {
struct V_62 * V_63 ;
unsigned int V_39 ;
V_63 = & V_2 [ V_1 ] ;
V_39 = V_63 -> V_39 ;
if ( V_39 == 0 )
continue;
V_39 = ( V_39 - 10 ) >> 1 ;
if ( ( V_39 >= V_55 ) && ( V_39 <= V_56 ) )
V_63 -> V_64 |= V_65 ;
}
goto V_66;
}
#endif
V_44 = F_34 ( V_67 ) ;
V_45 = F_34 ( V_68 ) ;
V_46 = F_34 ( V_69 ) ;
for ( V_1 = 0 ; V_1 < V_61 ; ++ V_1 ) {
struct V_62 * V_63 = & V_2 [ V_1 ] ;
if ( V_45 & ( 1U << ( V_63 -> V_39 - 10 ) ) )
V_63 -> V_64 |= V_65 ;
}
if ( ( V_44 & V_70 ) == 0 )
goto V_66;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
unsigned int V_71 , V_72 ;
V_72 = V_46 & 0x1f ;
V_46 >>= 5 ;
V_71 = V_46 & 0x1f ;
V_46 >>= 5 ;
if ( ! V_71 || ! V_72 )
continue;
for ( V_1 = 0 ; V_1 < V_61 ; V_1 ++ ) {
struct V_62 * V_63 = & V_2 [ V_1 ] ;
if ( V_71 == ( V_63 -> V_39 - 10 ) )
V_63 -> V_64 |= V_73 ;
if ( V_72 == ( V_63 -> V_39 - 10 ) )
V_63 -> V_12 = V_71 + 10 ;
}
}
V_66:
F_35 ( L_1 ) ;
for ( V_1 = 0 ; V_1 < V_61 ; ++ V_1 ) {
struct V_62 * V_63 = & V_2 [ V_1 ] ;
const char * V_74 [] = {
L_2 ,
L_3 ,
L_4 ,
L_5
} ;
if ( V_63 -> V_64 == 0 ) {
V_63 -> V_39 = 0 ;
continue;
}
F_35 ( L_6 , 1ul << ( V_63 -> V_39 - 10 ) ,
V_74 [ V_63 -> V_64 & 0x3 ] ) ;
}
}
static void F_36 ( void )
{
extern unsigned int V_75 ;
extern unsigned int V_76 ;
extern unsigned int V_77 ;
unsigned int * V_78 = & V_75 ;
unsigned int V_44 = F_34 ( V_67 ) ;
if ( ( V_44 & V_70 ) &&
( V_44 & V_79 ) ) {
F_37 ( V_78 + ( 0x1c0 / 4 ) + 1 ,
( unsigned long ) & V_76 , 0 ) ;
F_37 ( V_78 + ( 0x1e0 / 4 ) + 1 ,
( unsigned long ) & V_77 , 0 ) ;
V_35 = 1 ;
}
F_35 ( L_7 ,
V_35 ? L_8 : L_9 ) ;
}
static void F_38 ( int V_80 )
{
unsigned int V_81 ;
V_82 = V_83 ;
V_84 = V_85 ;
if ( V_80 ) {
F_32 () ;
F_36 () ;
}
V_81 = 0x4 << V_86 ;
if ( V_35 ) {
V_81 |= V_81 | V_87 ;
#ifdef F_31
V_81 |= V_88 << V_89 ;
V_34 = V_90 ;
#else
V_81 |= V_91 << V_89 ;
V_34 = V_92 ;
#endif
} else {
#ifdef F_31
V_81 |= V_93 << V_89 ;
#else
V_81 |= V_94 << V_89 ;
#endif
V_34 = V_16 ;
}
F_39 ( V_95 , V_81 ) ;
V_96 = F_40 () ;
#ifdef F_33
if ( F_20 ( V_52 ) ) {
unsigned int V_97 ;
V_97 = ( F_34 ( V_54 ) & V_98 ) / 4 ;
V_96 = F_41 ( V_96 , V_97 ) ;
F_42 ( V_96 ) ;
F_43 () ;
}
#endif
F_44 () ;
F_45 ( V_96 ) ;
}
void T_1 F_46 ( void )
{
F_38 ( 1 ) ;
}
void T_2 F_47 ( void )
{
F_38 ( 0 ) ;
}
void F_48 ( T_3 V_99 ,
T_3 V_100 )
{
V_101 = F_49 ( V_102 , V_100 , 0x40000000 ) ;
F_45 ( V_99 + V_101 ) ;
}
