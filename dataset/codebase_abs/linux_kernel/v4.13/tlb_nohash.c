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
static void F_9 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_4 ( V_19 ? V_19 -> V_6 : 0 ) ;
}
static void F_10 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_7 ( V_19 -> V_20 , V_19 -> V_6 , V_19 -> V_11 , V_19 -> V_12 ) ;
}
void F_11 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
F_3 () ;
V_6 = V_5 -> V_7 . V_8 ;
if ( F_12 ( V_6 == V_9 ) )
goto V_21;
if ( ! F_13 ( V_5 ) ) {
struct V_18 V_19 = { . V_6 = V_6 } ;
F_14 ( F_15 ( V_5 ) ,
F_9 , & V_19 , 1 ) ;
}
F_4 ( V_6 ) ;
V_21:
F_5 () ;
}
void F_16 ( struct V_4 * V_5 , unsigned long V_10 ,
int V_11 , int V_12 )
{
struct V_22 * V_23 ;
unsigned int V_6 ;
if ( F_12 ( F_17 ( ! V_5 ) ) )
return;
F_3 () ;
V_6 = V_5 -> V_7 . V_8 ;
if ( F_12 ( V_6 == V_9 ) )
goto V_24;
V_23 = F_15 ( V_5 ) ;
if ( ! F_13 ( V_5 ) ) {
if ( F_18 ( V_25 ) ) {
int V_26 = F_18 ( V_27 ) ;
if ( V_26 )
F_19 ( & V_28 ) ;
F_20 ( V_10 , V_6 , V_11 , V_12 ) ;
if ( V_26 )
F_21 ( & V_28 ) ;
goto V_24;
} else {
struct V_18 V_19 = {
. V_6 = V_6 ,
. V_20 = V_10 ,
. V_11 = V_11 ,
. V_12 = V_12 ,
} ;
F_14 ( V_23 ,
F_10 , & V_19 , 1 ) ;
}
}
F_7 ( V_10 , V_6 , V_11 , V_12 ) ;
V_24:
F_5 () ;
}
void F_22 ( struct V_13 * V_14 , unsigned long V_10 )
{
#ifdef F_23
if ( V_14 && F_24 ( V_14 ) )
F_25 ( V_14 , V_10 ) ;
#endif
F_16 ( V_14 ? V_14 -> V_15 : NULL , V_10 ,
F_1 ( V_16 ) , 0 ) ;
}
void T_1 F_26 ( void )
{
#ifdef F_27
unsigned long V_29 = F_28 () ;
if ( F_29 ( V_29 , L_1 , NULL ) )
F_30 ( V_25 ) ;
#endif
}
void F_31 ( unsigned long V_30 , unsigned long V_31 )
{
#ifdef F_27
F_3 () ;
F_32 ( F_9 , NULL , 1 ) ;
F_4 ( 0 ) ;
F_5 () ;
#else
F_4 ( 0 ) ;
#endif
}
void F_33 ( struct V_13 * V_14 , unsigned long V_30 ,
unsigned long V_31 )
{
F_11 ( V_14 -> V_15 ) ;
}
void F_34 ( struct V_32 * V_33 )
{
F_11 ( V_33 -> V_5 ) ;
}
void F_35 ( struct V_32 * V_33 , unsigned long V_34 )
{
int V_11 = V_2 [ V_35 ] . V_3 ;
if ( V_36 != V_37 ) {
unsigned long V_30 = V_34 & V_38 ;
unsigned long V_31 = V_34 + V_39 ;
unsigned long V_40 = 1UL << V_2 [ V_35 ] . V_41 ;
while ( V_30 < V_31 ) {
F_16 ( V_33 -> V_5 , V_30 , V_11 , 1 ) ;
V_30 += V_40 ;
}
} else {
unsigned long V_42 = 0xf000000000000000ul ;
unsigned long V_43 = ( V_34 & V_42 ) | 0x1000000000000000ul ;
unsigned long V_44 = V_34 & ~ V_42 ;
#ifdef F_36
V_44 = ( V_44 >> ( V_45 - 4 ) ) & ~ 0xfffful ;
#else
V_44 = ( V_44 >> ( V_45 - 3 ) ) & ~ 0xffful ;
#endif
V_44 |= V_43 ;
F_16 ( V_33 -> V_5 , V_44 , V_11 , 0 ) ;
}
}
static void F_37 ( void )
{
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
int V_49 , V_1 ;
#ifdef F_38
unsigned int V_50 = F_39 ( V_51 ) ;
int V_52 = F_18 ( V_53 ) ;
if ( V_52 && ( V_50 & V_54 ) == V_55 ) {
unsigned int V_56 = F_39 ( V_57 ) ;
unsigned int V_58 , V_59 ;
V_58 = ( V_56 & V_60 ) >> V_61 ;
V_59 = ( V_56 & V_62 ) >> V_63 ;
for ( V_1 = 0 ; V_1 < V_64 ; ++ V_1 ) {
struct V_65 * V_66 ;
unsigned int V_41 ;
V_66 = & V_2 [ V_1 ] ;
V_41 = V_66 -> V_41 ;
if ( V_41 == 0 || V_41 & 1 )
continue;
V_41 = ( V_41 - 10 ) >> 1 ;
if ( ( V_41 >= V_58 ) && ( V_41 <= V_59 ) )
V_66 -> V_67 |= V_68 ;
}
goto V_69;
}
if ( V_52 && ( V_50 & V_54 ) == V_70 ) {
T_2 V_56 , V_71 ;
V_46 = F_39 ( V_72 ) ;
V_56 = F_39 ( V_57 ) ;
V_71 = F_39 ( V_73 ) ;
V_48 = F_39 ( V_74 ) ;
if ( ( V_56 & V_75 ) && ( V_46 & V_76 ) )
V_36 = V_77 ;
if ( V_48 != 2 )
V_36 = V_37 ;
for ( V_1 = 0 ; V_1 < V_64 ; ++ V_1 ) {
struct V_65 * V_66 = & V_2 [ V_1 ] ;
if ( V_71 & ( 1U << ( V_66 -> V_41 - 10 ) ) ) {
V_66 -> V_67 |= V_68 ;
if ( V_36 && V_1 == V_78 )
V_66 -> V_67 |= V_79 ;
}
}
goto V_69;
}
#endif
V_46 = F_39 ( V_72 ) ;
V_47 = F_39 ( V_80 ) ;
V_48 = F_39 ( V_74 ) ;
for ( V_1 = 0 ; V_1 < V_64 ; ++ V_1 ) {
struct V_65 * V_66 = & V_2 [ V_1 ] ;
if ( V_47 & ( 1U << ( V_66 -> V_41 - 10 ) ) )
V_66 -> V_67 |= V_68 ;
}
if ( ( V_46 & V_75 ) == 0 ||
( V_46 & V_76 ) == 0 )
goto V_69;
V_36 = V_81 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
unsigned int V_82 , V_83 ;
V_83 = V_48 & 0x1f ;
V_48 >>= 5 ;
V_82 = V_48 & 0x1f ;
V_48 >>= 5 ;
if ( ! V_82 || ! V_83 )
continue;
for ( V_1 = 0 ; V_1 < V_64 ; V_1 ++ ) {
struct V_65 * V_66 = & V_2 [ V_1 ] ;
if ( V_82 == ( V_66 -> V_41 - 10 ) )
V_66 -> V_67 |= V_79 ;
if ( V_83 == ( V_66 -> V_41 - 10 ) )
V_66 -> V_12 = V_82 + 10 ;
}
}
V_69:
F_40 ( L_2 ) ;
for ( V_1 = 0 ; V_1 < V_64 ; ++ V_1 ) {
struct V_65 * V_66 = & V_2 [ V_1 ] ;
const char * V_84 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
if ( V_66 -> V_67 == 0 ) {
V_66 -> V_41 = 0 ;
continue;
}
F_40 ( L_7 , 1ul << ( V_66 -> V_41 - 10 ) ,
V_84 [ V_66 -> V_67 & 0x3 ] ) ;
}
}
static void F_41 ( void )
{
switch ( V_36 ) {
case V_81 :
F_42 ( 0x1c0 , V_85 ) ;
F_42 ( 0x1e0 , V_86 ) ;
break;
#ifdef F_38
case V_77 :
V_87 = V_88 ;
F_42 ( 0x1c0 , V_89 ) ;
F_42 ( 0x1e0 , V_90 ) ;
break;
#endif
}
F_40 ( L_8 ,
V_36 != V_37 ? L_9 : L_10 ) ;
}
static void F_43 ( void )
{
unsigned int V_91 ;
V_91 = 0x4 << V_92 ;
switch ( V_36 ) {
case V_77 :
V_91 |= V_93 ;
V_91 |= V_94 << V_95 ;
V_91 |= F_44 ( 1 ) ;
V_35 = V_78 ;
break;
case V_81 :
V_91 |= V_93 ;
#ifdef F_36
V_91 |= V_96 << V_95 ;
V_35 = V_97 ;
#else
V_91 |= V_98 << V_95 ;
V_35 = V_99 ;
#endif
break;
case V_37 :
#ifdef F_36
V_91 |= V_100 << V_95 ;
#else
V_91 |= V_101 << V_95 ;
#endif
V_35 = V_16 ;
break;
}
F_45 ( V_102 , V_91 ) ;
#ifdef F_38
if ( F_18 ( V_53 ) ) {
unsigned int V_103 ;
int T_3 V_104 = F_46 () ;
bool V_105 = true ;
V_103 = ( F_39 ( V_57 ) & V_106 ) / 4 ;
#ifdef F_27
if ( F_47 ( F_48 () ) > 1 )
V_105 = false ;
#endif
if ( V_105 )
V_107 = F_49 ( V_107 ,
V_103 , false ) ;
}
#endif
F_50 () ;
}
static void T_1 F_51 ( void )
{
V_108 = V_109 ;
if ( F_18 ( V_53 ) )
V_110 = V_111 ;
else
V_110 = V_112 ;
F_37 () ;
F_41 () ;
#ifdef F_38
if ( F_18 ( V_53 ) ) {
if ( V_36 == V_37 ) {
V_87 = V_88 ;
F_42 ( 0x1c0 , V_113 ) ;
F_42 ( 0x1e0 ,
V_114 ) ;
}
}
#endif
V_107 = F_52 () ;
}
static void T_1 F_53 ( void )
{
#ifdef F_38
if ( F_18 ( V_53 ) ) {
F_54 ( V_107 ) ;
}
#endif
F_55 ( V_107 ) ;
}
void T_1 F_56 ( void )
{
F_51 () ;
F_43 () ;
F_53 () ;
}
void F_57 ( void )
{
F_43 () ;
}
void F_58 ( T_4 V_115 ,
T_4 V_116 )
{
#ifdef F_38
if ( F_59 ( V_53 ) ) {
unsigned long V_117 ;
unsigned int V_103 ;
V_103 = ( F_39 ( V_57 ) & V_106 ) / 4 ;
V_117 = F_49 ( V_116 , V_103 ,
true ) ;
V_118 = F_60 ( V_119 , V_117 , 0x40000000 ) ;
} else
#endif
V_118 = F_60 ( V_119 , V_116 , 0x40000000 ) ;
F_55 ( V_115 + V_118 ) ;
}
void T_1 F_56 ( void )
{
#ifdef F_61
F_26 () ;
#endif
}
