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
T_3 V_42 ;
V_41 = F_37 ( F_5 () ) ;
V_41 -= F_32 () -> V_43 ;
V_42 = F_38 ( V_41 ) ;
F_32 () -> V_43 += F_39 ( V_42 ) ;
F_30 ( V_42 ) ;
return V_42 ;
}
#endif
return false ;
}
void F_40 ( struct V_2 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_44 -> signal ;
T_3 V_22 , V_30 ;
struct V_2 * V_49 ;
V_46 -> V_22 = V_48 -> V_22 ;
V_46 -> V_30 = V_48 -> V_30 ;
V_46 -> V_50 = V_48 -> V_51 ;
F_41 () ;
if ( ! F_42 ( F_43 ( V_44 ) ) )
goto V_52;
V_49 = V_44 ;
do {
V_45 ( V_49 , & V_22 , & V_30 ) ;
V_46 -> V_22 += V_22 ;
V_46 -> V_30 += V_30 ;
V_46 -> V_50 += F_44 ( V_49 ) ;
} while_each_thread(tsk, t) ;
void F_45 ( struct V_2 * V_16 , int V_53 ,
struct V_36 * V_36 , int V_54 )
{
T_3 V_55 = F_46 ( V_56 ) ;
T_2 V_20 = ( V_26 T_2 ) V_56 ;
T_2 * V_10 = V_11 -> V_10 ;
if ( F_34 () )
return;
V_20 *= V_54 ;
V_55 *= V_54 ;
if ( F_15 () ) {
V_10 [ V_14 ] += V_20 ;
} else if ( F_18 () ) {
V_10 [ V_15 ] += V_20 ;
} else if ( F_12 () == V_16 ) {
F_26 ( V_16 , V_20 , V_55 , V_15 ) ;
} else if ( V_53 ) {
F_21 ( V_16 , V_20 , V_55 ) ;
} else if ( V_16 == V_36 -> V_57 ) {
F_31 ( V_20 ) ;
} else if ( V_16 -> V_4 & V_33 ) {
F_25 ( V_16 , V_20 , V_55 ) ;
} else {
F_26 ( V_16 , V_20 , V_55 , V_34 ) ;
}
}
static void F_47 ( int V_54 )
{
struct V_36 * V_36 = F_32 () ;
F_45 ( V_58 , 0 , V_36 , V_54 ) ;
}
static inline void F_47 ( int V_54 ) {}
static inline void F_45 ( struct V_2 * V_16 , int V_53 ,
struct V_36 * V_36 , int V_59 ) {}
void F_48 ( struct V_2 * V_60 )
{
if ( F_49 ( V_60 ) )
F_50 ( V_60 ) ;
else
F_51 ( V_60 ) ;
#ifdef F_52
F_53 ( V_60 ) ;
#endif
F_54 ( V_60 ) ;
}
void F_55 ( struct V_2 * V_44 )
{
if ( ! F_56 () ) {
if ( F_57 () ) {
F_53 ( V_44 ) ;
return;
}
if ( F_49 ( V_44 ) ) {
F_50 ( V_44 ) ;
return;
}
}
F_51 ( V_44 ) ;
}
void F_58 ( struct V_2 * V_16 , T_3 * V_61 , T_3 * V_62 )
{
* V_61 = V_16 -> V_22 ;
* V_62 = V_16 -> V_30 ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_61 , T_3 * V_62 )
{
struct V_45 V_20 ;
F_40 ( V_16 , & V_20 ) ;
* V_61 = V_20 . V_22 ;
* V_62 = V_20 . V_30 ;
}
void F_60 ( struct V_2 * V_16 , int V_53 )
{
T_3 V_63 = F_46 ( V_56 ) ;
struct V_36 * V_36 = F_32 () ;
if ( F_61 () )
return;
if ( V_1 ) {
F_45 ( V_16 , V_53 , V_36 , 1 ) ;
return;
}
if ( F_34 () )
return;
if ( V_53 )
F_21 ( V_16 , V_56 , V_63 ) ;
else if ( ( V_16 != V_36 -> V_57 ) || ( F_29 () != V_64 ) )
F_28 ( V_16 , V_64 , V_56 ,
V_63 ) ;
else
F_31 ( V_56 ) ;
}
void F_62 ( unsigned long V_54 )
{
F_30 ( F_63 ( V_54 ) ) ;
}
void F_64 ( unsigned long V_54 )
{
if ( V_1 ) {
F_47 ( V_54 ) ;
return;
}
F_31 ( F_63 ( V_54 ) ) ;
}
static T_3 F_65 ( T_2 V_30 , T_2 V_65 , T_2 V_66 )
{
T_2 V_55 ;
for (; ; ) {
if ( V_30 > V_65 )
F_66 ( V_65 , V_30 ) ;
if ( V_66 >> 32 )
goto V_67;
if ( ! ( V_65 >> 32 ) )
break;
if ( V_30 >> 31 )
goto V_67;
V_30 <<= 1 ;
V_65 >>= 1 ;
continue;
V_67:
V_65 >>= 1 ;
V_66 >>= 1 ;
}
V_55 = F_67 ( ( T_2 ) ( V_68 ) V_30 * ( T_2 ) ( V_68 ) V_65 , ( V_68 ) V_66 ) ;
return ( V_26 T_3 ) V_55 ;
}
static void F_68 ( struct V_45 * V_3 ,
struct V_20 * V_60 ,
T_3 * V_61 , T_3 * V_62 )
{
T_3 V_65 , V_30 , V_22 ;
V_65 = F_38 ( V_3 -> V_50 ) ;
if ( V_60 -> V_30 + V_60 -> V_22 >= V_65 )
goto V_52;
V_30 = V_3 -> V_30 ;
V_22 = V_3 -> V_22 ;
if ( V_22 == 0 ) {
V_30 = V_65 ;
} else if ( V_30 == 0 ) {
V_22 = V_65 ;
} else {
T_3 V_66 = V_30 + V_22 ;
V_30 = F_65 ( ( V_26 T_2 ) V_30 ,
( V_26 T_2 ) V_65 , ( V_26 T_2 ) V_66 ) ;
V_22 = V_65 - V_30 ;
}
V_60 -> V_30 = F_69 ( V_60 -> V_30 , V_30 ) ;
V_60 -> V_22 = F_69 ( V_60 -> V_22 , V_22 ) ;
V_52:
* V_61 = V_60 -> V_22 ;
* V_62 = V_60 -> V_30 ;
}
void F_58 ( struct V_2 * V_16 , T_3 * V_61 , T_3 * V_62 )
{
struct V_45 V_20 = {
. V_50 = V_16 -> V_69 . V_50 ,
} ;
V_45 ( V_16 , & V_20 . V_22 , & V_20 . V_30 ) ;
F_68 ( & V_20 , & V_16 -> V_70 , V_61 , V_62 ) ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_61 , T_3 * V_62 )
{
struct V_45 V_20 ;
F_40 ( V_16 , & V_20 ) ;
F_68 ( & V_20 , & V_16 -> signal -> V_70 , V_61 , V_62 ) ;
}
static unsigned long long F_70 ( struct V_2 * V_44 )
{
unsigned long long clock ;
clock = F_71 () ;
if ( clock < V_44 -> V_71 )
return 0 ;
return clock - V_44 -> V_71 ;
}
static T_3 F_72 ( struct V_2 * V_44 )
{
unsigned long long V_5 = F_70 ( V_44 ) ;
F_73 ( V_44 -> V_72 == V_73 ) ;
V_44 -> V_71 += V_5 ;
return F_38 ( V_5 ) ;
}
static void F_74 ( struct V_2 * V_44 )
{
T_3 V_74 = F_72 ( V_44 ) ;
F_28 ( V_44 , F_29 () , V_74 , F_46 ( V_74 ) ) ;
}
void F_51 ( struct V_2 * V_44 )
{
F_75 ( & V_44 -> V_75 ) ;
F_74 ( V_44 ) ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_77 ( struct V_2 * V_44 )
{
F_75 ( & V_44 -> V_75 ) ;
F_74 ( V_44 ) ;
if ( F_57 () )
V_44 -> V_72 = V_76 ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_53 ( struct V_2 * V_44 )
{
T_3 V_74 ;
F_75 ( & V_44 -> V_75 ) ;
V_74 = F_72 ( V_44 ) ;
V_44 -> V_72 = V_77 ;
F_21 ( V_44 , V_74 , F_46 ( V_74 ) ) ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_78 ( struct V_2 * V_44 )
{
F_75 ( & V_44 -> V_75 ) ;
F_74 ( V_44 ) ;
V_44 -> V_72 = V_76 ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_79 ( struct V_2 * V_44 )
{
F_75 ( & V_44 -> V_75 ) ;
F_74 ( V_44 ) ;
V_58 -> V_4 |= V_33 ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_80 ( struct V_2 * V_44 )
{
F_75 ( & V_44 -> V_75 ) ;
F_74 ( V_44 ) ;
V_58 -> V_4 &= ~ V_33 ;
F_76 ( & V_44 -> V_75 ) ;
}
void F_50 ( struct V_2 * V_44 )
{
T_3 V_74 = F_72 ( V_44 ) ;
F_31 ( V_74 ) ;
}
void F_54 ( struct V_2 * V_60 )
{
F_75 ( & V_60 -> V_75 ) ;
V_60 -> V_72 = V_73 ;
F_76 ( & V_60 -> V_75 ) ;
F_75 ( & V_58 -> V_75 ) ;
V_58 -> V_72 = V_77 ;
V_58 -> V_71 = F_6 ( F_5 () ) ;
F_76 ( & V_58 -> V_75 ) ;
}
void F_81 ( struct V_2 * V_49 , int V_6 )
{
unsigned long V_4 ;
F_82 ( & V_49 -> V_75 , V_4 ) ;
V_49 -> V_72 = V_77 ;
V_49 -> V_71 = F_6 ( V_6 ) ;
F_83 ( & V_49 -> V_75 , V_4 ) ;
}
T_3 F_84 ( struct V_2 * V_49 )
{
unsigned int V_78 ;
T_3 V_27 ;
do {
V_78 = F_85 ( & V_49 -> V_75 ) ;
V_27 = V_49 -> V_27 ;
if ( V_49 -> V_4 & V_33 )
V_27 += F_70 ( V_49 ) ;
} while ( F_86 ( & V_49 -> V_75 , V_78 ) );
return V_27 ;
}
static void
F_87 ( struct V_2 * V_49 ,
T_3 * V_79 , T_3 * V_80 ,
T_3 * V_81 , T_3 * V_82 ,
T_3 * V_83 , T_3 * V_84 )
{
unsigned int V_78 ;
unsigned long long V_5 ;
do {
* V_83 = 0 ;
* V_84 = 0 ;
V_78 = F_85 ( & V_49 -> V_75 ) ;
if ( V_79 )
* V_79 = * V_81 ;
if ( V_80 )
* V_80 = * V_82 ;
if ( V_49 -> V_72 == V_73 ||
F_49 ( V_49 ) )
continue;
V_5 = F_70 ( V_49 ) ;
if ( V_49 -> V_72 == V_76 || V_49 -> V_4 & V_33 ) {
* V_83 = V_5 ;
} else {
if ( V_49 -> V_72 == V_77 )
* V_84 = V_5 ;
}
} while ( F_86 ( & V_49 -> V_75 , V_78 ) );
}
void V_45 ( struct V_2 * V_49 , T_3 * V_22 , T_3 * V_30 )
{
T_3 V_83 , V_84 ;
F_87 ( V_49 , V_22 , V_30 , & V_49 -> V_22 ,
& V_49 -> V_30 , & V_83 , & V_84 ) ;
if ( V_22 )
* V_22 += V_83 ;
if ( V_30 )
* V_30 += V_84 ;
}
void F_88 ( struct V_2 * V_49 ,
T_3 * V_23 , T_3 * V_31 )
{
T_3 V_83 , V_84 ;
F_87 ( V_49 , V_23 , V_31 ,
& V_49 -> V_23 , & V_49 -> V_31 , & V_83 , & V_84 ) ;
if ( V_23 )
* V_23 += F_46 ( V_83 ) ;
if ( V_31 )
* V_31 += F_46 ( V_84 ) ;
}
