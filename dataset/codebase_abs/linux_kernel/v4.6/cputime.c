void F_1 ( void )
{
V_1 = 1 ;
}
void F_2 ( void )
{
V_1 = 0 ;
}
void F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
int V_6 ;
if ( ! V_1 )
return;
F_4 ( V_4 ) ;
V_6 = F_5 () ;
V_5 = F_6 ( V_6 ) - F_7 ( V_7 ) ;
F_8 ( V_7 , V_5 ) ;
F_9 () ;
if ( F_10 () )
F_8 ( V_8 , V_5 ) ;
else if ( F_11 () && V_3 != F_12 () )
F_8 ( V_9 , V_5 ) ;
F_13 () ;
F_14 ( V_4 ) ;
}
static int F_15 ( void )
{
T_2 * V_10 = V_11 -> V_10 ;
unsigned long V_4 ;
T_2 V_12 ;
int V_13 = 0 ;
F_4 ( V_4 ) ;
V_12 = F_16 ( V_8 ) ;
if ( F_17 ( V_12 ) > V_10 [ V_14 ] )
V_13 = 1 ;
F_14 ( V_4 ) ;
return V_13 ;
}
static int F_18 ( void )
{
T_2 * V_10 = V_11 -> V_10 ;
unsigned long V_4 ;
T_2 V_12 ;
int V_13 = 0 ;
F_4 ( V_4 ) ;
V_12 = F_16 ( V_9 ) ;
if ( F_17 ( V_12 ) > V_10 [ V_15 ] )
V_13 = 1 ;
F_14 ( V_4 ) ;
return V_13 ;
}
static inline void F_19 ( struct V_2 * V_16 , int V_17 ,
T_2 V_18 )
{
F_8 ( V_19 . V_10 [ V_17 ] , V_18 ) ;
F_20 ( V_16 , V_17 , V_18 ) ;
}
void F_21 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 )
{
int V_17 ;
V_16 -> V_22 += V_20 ;
V_16 -> V_23 += V_21 ;
F_22 ( V_16 , V_20 ) ;
V_17 = ( F_23 ( V_16 ) > 0 ) ? V_24 : V_25 ;
F_19 ( V_16 , V_17 , ( V_26 T_2 ) V_20 ) ;
F_24 ( V_16 ) ;
}
static void F_25 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_16 -> V_22 += V_20 ;
V_16 -> V_23 += V_21 ;
F_22 ( V_16 , V_20 ) ;
V_16 -> V_27 += V_20 ;
if ( F_23 ( V_16 ) > 0 ) {
V_10 [ V_24 ] += ( V_26 T_2 ) V_20 ;
V_10 [ V_28 ] += ( V_26 T_2 ) V_20 ;
} else {
V_10 [ V_25 ] += ( V_26 T_2 ) V_20 ;
V_10 [ V_29 ] += ( V_26 T_2 ) V_20 ;
}
}
static inline
void F_26 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 , int V_17 )
{
V_16 -> V_30 += V_20 ;
V_16 -> V_31 += V_21 ;
F_27 ( V_16 , V_20 ) ;
F_19 ( V_16 , V_17 , ( V_26 T_2 ) V_20 ) ;
F_24 ( V_16 ) ;
}
void F_28 ( struct V_2 * V_16 , int V_32 ,
T_3 V_20 , T_3 V_21 )
{
int V_17 ;
if ( ( V_16 -> V_4 & V_33 ) && ( F_29 () - V_32 == 0 ) ) {
F_25 ( V_16 , V_20 , V_21 ) ;
return;
}
if ( F_10 () - V_32 )
V_17 = V_14 ;
else if ( F_11 () )
V_17 = V_15 ;
else
V_17 = V_34 ;
F_26 ( V_16 , V_20 , V_21 , V_17 ) ;
}
void F_30 ( T_3 V_20 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_10 [ V_35 ] += ( V_26 T_2 ) V_20 ;
}
void F_31 ( T_3 V_20 )
{
T_2 * V_10 = V_11 -> V_10 ;
struct V_36 * V_36 = F_32 () ;
if ( F_33 ( & V_36 -> V_37 ) > 0 )
V_10 [ V_38 ] += ( V_26 T_2 ) V_20 ;
else
V_10 [ V_39 ] += ( V_26 T_2 ) V_20 ;
}
static T_4 bool F_34 ( void )
{
#ifdef F_35
if ( F_36 ( & V_40 ) ) {
T_2 V_41 ;
unsigned long V_42 ;
V_41 = F_37 ( F_5 () ) ;
V_41 -= F_32 () -> V_43 ;
V_42 = F_38 ( V_41 ) ;
F_32 () -> V_43 += F_39 ( V_42 ) ;
F_30 ( F_40 ( V_42 ) ) ;
return V_42 ;
}
#endif
return false ;
}
void F_41 ( struct V_2 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_44 -> signal ;
T_3 V_22 , V_30 ;
struct V_2 * V_49 ;
unsigned int V_50 , V_51 ;
unsigned long V_4 ;
F_42 () ;
V_51 = 0 ;
do {
V_50 = V_51 ;
V_4 = F_43 ( & V_48 -> V_52 , & V_50 ) ;
V_46 -> V_22 = V_48 -> V_22 ;
V_46 -> V_30 = V_48 -> V_30 ;
V_46 -> V_53 = V_48 -> V_54 ;
F_44 (tsk, t) {
V_45 ( V_49 , & V_22 , & V_30 ) ;
V_46 -> V_22 += V_22 ;
V_46 -> V_30 += V_30 ;
V_46 -> V_53 += F_45 ( V_49 ) ;
}
V_51 = 1 ;
} while ( F_46 ( & V_48 -> V_52 , V_50 ) );
F_47 ( & V_48 -> V_52 , V_50 , V_4 ) ;
F_48 () ;
}
static void F_49 ( struct V_2 * V_16 , int V_55 ,
struct V_36 * V_36 , int V_56 )
{
T_3 V_57 = F_50 ( V_58 ) ;
T_2 V_20 = ( V_26 T_2 ) V_58 ;
T_2 * V_10 = V_11 -> V_10 ;
if ( F_34 () )
return;
V_20 *= V_56 ;
V_57 *= V_56 ;
if ( F_15 () ) {
V_10 [ V_14 ] += V_20 ;
} else if ( F_18 () ) {
V_10 [ V_15 ] += V_20 ;
} else if ( F_12 () == V_16 ) {
F_26 ( V_16 , V_20 , V_57 , V_15 ) ;
} else if ( V_55 ) {
F_21 ( V_16 , V_20 , V_57 ) ;
} else if ( V_16 == V_36 -> V_59 ) {
F_31 ( V_20 ) ;
} else if ( V_16 -> V_4 & V_33 ) {
F_25 ( V_16 , V_20 , V_57 ) ;
} else {
F_26 ( V_16 , V_20 , V_57 , V_34 ) ;
}
}
static void F_51 ( int V_56 )
{
struct V_36 * V_36 = F_32 () ;
F_49 ( V_60 , 0 , V_36 , V_56 ) ;
}
static inline void F_51 ( int V_56 ) {}
static inline void F_49 ( struct V_2 * V_16 , int V_55 ,
struct V_36 * V_36 , int V_61 ) {}
void F_52 ( struct V_2 * V_62 )
{
if ( F_53 ( V_62 ) )
F_54 ( V_62 ) ;
else
F_55 ( V_62 ) ;
#ifdef F_56
F_57 ( V_62 ) ;
#endif
F_58 ( V_62 ) ;
}
void F_59 ( struct V_2 * V_44 )
{
if ( ! F_60 () ) {
if ( F_61 () ) {
F_57 ( V_44 ) ;
return;
}
if ( F_53 ( V_44 ) ) {
F_54 ( V_44 ) ;
return;
}
}
F_55 ( V_44 ) ;
}
void F_62 ( struct V_2 * V_16 , T_3 * V_63 , T_3 * V_64 )
{
* V_63 = V_16 -> V_22 ;
* V_64 = V_16 -> V_30 ;
}
void F_63 ( struct V_2 * V_16 , T_3 * V_63 , T_3 * V_64 )
{
struct V_45 V_20 ;
F_41 ( V_16 , & V_20 ) ;
* V_63 = V_20 . V_22 ;
* V_64 = V_20 . V_30 ;
}
void F_64 ( struct V_2 * V_16 , int V_55 )
{
T_3 V_65 = F_50 ( V_58 ) ;
struct V_36 * V_36 = F_32 () ;
if ( F_65 () )
return;
if ( V_1 ) {
F_49 ( V_16 , V_55 , V_36 , 1 ) ;
return;
}
if ( F_34 () )
return;
if ( V_55 )
F_21 ( V_16 , V_58 , V_65 ) ;
else if ( ( V_16 != V_36 -> V_59 ) || ( F_29 () != V_66 ) )
F_28 ( V_16 , V_66 , V_58 ,
V_65 ) ;
else
F_31 ( V_58 ) ;
}
void F_66 ( unsigned long V_56 )
{
F_30 ( F_40 ( V_56 ) ) ;
}
void F_67 ( unsigned long V_56 )
{
if ( V_1 ) {
F_51 ( V_56 ) ;
return;
}
F_31 ( F_40 ( V_56 ) ) ;
}
static T_3 F_68 ( T_2 V_30 , T_2 V_67 , T_2 V_68 )
{
T_2 V_57 ;
for (; ; ) {
if ( V_30 > V_67 )
F_69 ( V_67 , V_30 ) ;
if ( V_68 >> 32 )
goto V_69;
if ( ! ( V_67 >> 32 ) )
break;
if ( V_30 >> 31 )
goto V_69;
V_30 <<= 1 ;
V_67 >>= 1 ;
continue;
V_69:
V_67 >>= 1 ;
V_68 >>= 1 ;
}
V_57 = F_70 ( ( T_2 ) ( V_70 ) V_30 * ( T_2 ) ( V_70 ) V_67 , ( V_70 ) V_68 ) ;
return ( V_26 T_3 ) V_57 ;
}
static void F_71 ( struct V_45 * V_3 ,
struct V_71 * V_62 ,
T_3 * V_63 , T_3 * V_64 )
{
T_3 V_67 , V_30 , V_22 ;
unsigned long V_4 ;
F_72 ( & V_62 -> V_72 , V_4 ) ;
V_67 = F_73 ( V_3 -> V_53 ) ;
if ( V_62 -> V_30 + V_62 -> V_22 >= V_67 )
goto V_73;
V_30 = V_3 -> V_30 ;
V_22 = V_3 -> V_22 ;
if ( V_22 == 0 ) {
V_30 = V_67 ;
goto V_74;
}
if ( V_30 == 0 ) {
V_22 = V_67 ;
goto V_74;
}
V_30 = F_68 ( ( V_26 T_2 ) V_30 , ( V_26 T_2 ) V_67 ,
( V_26 T_2 ) ( V_30 + V_22 ) ) ;
if ( V_30 < V_62 -> V_30 )
V_30 = V_62 -> V_30 ;
V_22 = V_67 - V_30 ;
if ( V_22 < V_62 -> V_22 ) {
V_22 = V_62 -> V_22 ;
V_30 = V_67 - V_22 ;
}
V_74:
V_62 -> V_30 = V_30 ;
V_62 -> V_22 = V_22 ;
V_73:
* V_63 = V_62 -> V_22 ;
* V_64 = V_62 -> V_30 ;
F_74 ( & V_62 -> V_72 , V_4 ) ;
}
void F_62 ( struct V_2 * V_16 , T_3 * V_63 , T_3 * V_64 )
{
struct V_45 V_20 = {
. V_53 = V_16 -> V_75 . V_53 ,
} ;
V_45 ( V_16 , & V_20 . V_22 , & V_20 . V_30 ) ;
F_71 ( & V_20 , & V_16 -> V_71 , V_63 , V_64 ) ;
}
void F_63 ( struct V_2 * V_16 , T_3 * V_63 , T_3 * V_64 )
{
struct V_45 V_20 ;
F_41 ( V_16 , & V_20 ) ;
F_71 ( & V_20 , & V_16 -> signal -> V_71 , V_63 , V_64 ) ;
}
static T_3 F_75 ( struct V_2 * V_44 )
{
unsigned long V_76 = F_76 ( V_77 ) ;
if ( F_77 ( V_76 , ( unsigned long ) V_44 -> V_78 ) )
return 0 ;
return F_40 ( V_76 - V_44 -> V_78 ) ;
}
static T_3 F_78 ( struct V_2 * V_44 )
{
unsigned long V_76 = F_76 ( V_77 ) ;
unsigned long V_5 = V_76 - V_44 -> V_78 ;
F_79 ( V_44 -> V_79 == V_80 ) ;
V_44 -> V_78 = V_76 ;
return F_40 ( V_5 ) ;
}
static void F_80 ( struct V_2 * V_44 )
{
T_3 V_81 = F_78 ( V_44 ) ;
F_28 ( V_44 , F_29 () , V_81 , F_50 ( V_81 ) ) ;
}
void F_55 ( struct V_2 * V_44 )
{
if ( ! F_75 ( V_44 ) )
return;
F_81 ( & V_44 -> V_82 ) ;
F_80 ( V_44 ) ;
F_82 ( & V_44 -> V_82 ) ;
}
void F_83 ( struct V_2 * V_44 )
{
F_81 ( & V_44 -> V_82 ) ;
if ( F_75 ( V_44 ) )
F_80 ( V_44 ) ;
if ( F_61 () )
V_44 -> V_79 = V_83 ;
F_82 ( & V_44 -> V_82 ) ;
}
void F_57 ( struct V_2 * V_44 )
{
T_3 V_81 ;
F_81 ( & V_44 -> V_82 ) ;
V_44 -> V_79 = V_84 ;
if ( F_75 ( V_44 ) ) {
V_81 = F_78 ( V_44 ) ;
F_21 ( V_44 , V_81 , F_50 ( V_81 ) ) ;
}
F_82 ( & V_44 -> V_82 ) ;
}
void F_84 ( struct V_2 * V_44 )
{
F_81 ( & V_44 -> V_82 ) ;
if ( F_75 ( V_44 ) )
F_80 ( V_44 ) ;
V_44 -> V_79 = V_83 ;
F_82 ( & V_44 -> V_82 ) ;
}
void F_85 ( struct V_2 * V_44 )
{
F_81 ( & V_44 -> V_82 ) ;
if ( F_75 ( V_44 ) )
F_80 ( V_44 ) ;
V_60 -> V_4 |= V_33 ;
F_82 ( & V_44 -> V_82 ) ;
}
void F_86 ( struct V_2 * V_44 )
{
F_81 ( & V_44 -> V_82 ) ;
F_80 ( V_44 ) ;
V_60 -> V_4 &= ~ V_33 ;
F_82 ( & V_44 -> V_82 ) ;
}
void F_54 ( struct V_2 * V_44 )
{
T_3 V_81 = F_78 ( V_44 ) ;
F_31 ( V_81 ) ;
}
void F_58 ( struct V_2 * V_62 )
{
F_81 ( & V_62 -> V_82 ) ;
V_62 -> V_79 = V_80 ;
F_82 ( & V_62 -> V_82 ) ;
F_81 ( & V_60 -> V_82 ) ;
V_60 -> V_79 = V_84 ;
V_60 -> V_78 = V_77 ;
F_82 ( & V_60 -> V_82 ) ;
}
void F_87 ( struct V_2 * V_49 , int V_6 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
F_81 ( & V_49 -> V_82 ) ;
V_49 -> V_79 = V_84 ;
V_49 -> V_78 = V_77 ;
F_82 ( & V_49 -> V_82 ) ;
F_14 ( V_4 ) ;
}
T_3 F_88 ( struct V_2 * V_49 )
{
unsigned int V_50 ;
T_3 V_27 ;
if ( ! F_89 () )
return V_49 -> V_27 ;
do {
V_50 = F_90 ( & V_49 -> V_82 ) ;
V_27 = V_49 -> V_27 ;
if ( V_49 -> V_79 == V_84 && V_49 -> V_4 & V_33 )
V_27 += F_75 ( V_49 ) ;
} while ( F_91 ( & V_49 -> V_82 , V_50 ) );
return V_27 ;
}
static void
F_92 ( struct V_2 * V_49 ,
T_3 * V_85 , T_3 * V_86 ,
T_3 * V_87 , T_3 * V_88 ,
T_3 * V_89 , T_3 * V_90 )
{
unsigned int V_50 ;
unsigned long long V_5 ;
do {
* V_89 = 0 ;
* V_90 = 0 ;
V_50 = F_90 ( & V_49 -> V_82 ) ;
if ( V_85 )
* V_85 = * V_87 ;
if ( V_86 )
* V_86 = * V_88 ;
if ( V_49 -> V_79 == V_80 ||
F_53 ( V_49 ) )
continue;
V_5 = F_75 ( V_49 ) ;
if ( V_49 -> V_79 == V_83 || V_49 -> V_4 & V_33 ) {
* V_89 = V_5 ;
} else {
if ( V_49 -> V_79 == V_84 )
* V_90 = V_5 ;
}
} while ( F_91 ( & V_49 -> V_82 , V_50 ) );
}
void V_45 ( struct V_2 * V_49 , T_3 * V_22 , T_3 * V_30 )
{
T_3 V_89 , V_90 ;
if ( ! F_89 () ) {
if ( V_22 )
* V_22 = V_49 -> V_22 ;
if ( V_30 )
* V_30 = V_49 -> V_30 ;
return;
}
F_92 ( V_49 , V_22 , V_30 , & V_49 -> V_22 ,
& V_49 -> V_30 , & V_89 , & V_90 ) ;
if ( V_22 )
* V_22 += V_89 ;
if ( V_30 )
* V_30 += V_90 ;
}
void F_93 ( struct V_2 * V_49 ,
T_3 * V_23 , T_3 * V_31 )
{
T_3 V_89 , V_90 ;
if ( ! F_89 () ) {
if ( V_23 )
* V_23 = V_49 -> V_23 ;
if ( V_31 )
* V_31 = V_49 -> V_31 ;
return;
}
F_92 ( V_49 , V_23 , V_31 ,
& V_49 -> V_23 , & V_49 -> V_31 , & V_89 , & V_90 ) ;
if ( V_23 )
* V_23 += F_50 ( V_89 ) ;
if ( V_31 )
* V_31 += F_50 ( V_90 ) ;
}
