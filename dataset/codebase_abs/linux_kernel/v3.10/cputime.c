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
F_20 ( V_19 ) . V_10 [ V_17 ] += V_18 ;
F_21 ( V_16 , V_17 , V_18 ) ;
}
void F_22 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 )
{
int V_17 ;
V_16 -> V_22 += V_20 ;
V_16 -> V_23 += V_21 ;
F_23 ( V_16 , V_20 ) ;
V_17 = ( F_24 ( V_16 ) > 0 ) ? V_24 : V_25 ;
F_19 ( V_16 , V_17 , ( V_26 T_2 ) V_20 ) ;
F_25 ( V_16 ) ;
}
static void F_26 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_16 -> V_22 += V_20 ;
V_16 -> V_23 += V_21 ;
F_23 ( V_16 , V_20 ) ;
V_16 -> V_27 += V_20 ;
if ( F_24 ( V_16 ) > 0 ) {
V_10 [ V_24 ] += ( V_26 T_2 ) V_20 ;
V_10 [ V_28 ] += ( V_26 T_2 ) V_20 ;
} else {
V_10 [ V_25 ] += ( V_26 T_2 ) V_20 ;
V_10 [ V_29 ] += ( V_26 T_2 ) V_20 ;
}
}
static inline
void F_27 ( struct V_2 * V_16 , T_3 V_20 ,
T_3 V_21 , int V_17 )
{
V_16 -> V_30 += V_20 ;
V_16 -> V_31 += V_21 ;
F_28 ( V_16 , V_20 ) ;
F_19 ( V_16 , V_17 , ( V_26 T_2 ) V_20 ) ;
F_25 ( V_16 ) ;
}
void F_29 ( struct V_2 * V_16 , int V_32 ,
T_3 V_20 , T_3 V_21 )
{
int V_17 ;
if ( ( V_16 -> V_4 & V_33 ) && ( F_30 () - V_32 == 0 ) ) {
F_26 ( V_16 , V_20 , V_21 ) ;
return;
}
if ( F_10 () - V_32 )
V_17 = V_14 ;
else if ( F_11 () )
V_17 = V_15 ;
else
V_17 = V_34 ;
F_27 ( V_16 , V_20 , V_21 , V_17 ) ;
}
void F_31 ( T_3 V_20 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_10 [ V_35 ] += ( V_26 T_2 ) V_20 ;
}
void F_32 ( T_3 V_20 )
{
T_2 * V_10 = V_11 -> V_10 ;
struct V_36 * V_36 = F_33 () ;
if ( F_34 ( & V_36 -> V_37 ) > 0 )
V_10 [ V_38 ] += ( V_26 T_2 ) V_20 ;
else
V_10 [ V_39 ] += ( V_26 T_2 ) V_20 ;
}
static T_4 bool F_35 ( void )
{
#ifdef F_36
if ( F_37 ( & V_40 ) ) {
T_2 V_41 , V_42 = 0 ;
V_41 = F_38 ( F_5 () ) ;
V_41 -= F_33 () -> V_43 ;
V_42 = F_39 ( V_41 ) ;
F_33 () -> V_43 += V_42 * V_44 ;
F_31 ( V_42 ) ;
return V_42 ;
}
#endif
return false ;
}
void F_40 ( struct V_2 * V_45 , struct V_46 * V_47 )
{
struct V_48 * V_49 = V_45 -> signal ;
T_3 V_22 , V_30 ;
struct V_2 * V_50 ;
V_47 -> V_22 = V_49 -> V_22 ;
V_47 -> V_30 = V_49 -> V_30 ;
V_47 -> V_51 = V_49 -> V_52 ;
F_41 () ;
if ( ! F_42 ( F_43 ( V_45 ) ) )
goto V_53;
V_50 = V_45 ;
do {
V_46 ( V_50 , & V_22 , & V_30 ) ;
V_47 -> V_22 += V_22 ;
V_47 -> V_30 += V_30 ;
V_47 -> V_51 += F_44 ( V_50 ) ;
} while_each_thread(tsk, t) ;
void F_45 ( struct V_2 * V_16 , int V_54 ,
struct V_36 * V_36 )
{
T_3 V_55 = F_46 ( V_56 ) ;
T_2 * V_10 = V_11 -> V_10 ;
if ( F_35 () )
return;
if ( F_15 () ) {
V_10 [ V_14 ] += ( V_26 T_2 ) V_56 ;
} else if ( F_18 () ) {
V_10 [ V_15 ] += ( V_26 T_2 ) V_56 ;
} else if ( F_12 () == V_16 ) {
F_27 ( V_16 , V_56 , V_55 ,
V_15 ) ;
} else if ( V_54 ) {
F_22 ( V_16 , V_56 , V_55 ) ;
} else if ( V_16 == V_36 -> V_57 ) {
F_32 ( V_56 ) ;
} else if ( V_16 -> V_4 & V_33 ) {
F_26 ( V_16 , V_56 , V_55 ) ;
} else {
F_27 ( V_16 , V_56 , V_55 ,
V_34 ) ;
}
}
static void F_47 ( int V_58 )
{
int V_59 ;
struct V_36 * V_36 = F_33 () ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ )
F_45 ( V_60 , 0 , V_36 ) ;
}
static inline void F_47 ( int V_58 ) {}
static inline void F_45 ( struct V_2 * V_16 , int V_54 ,
struct V_36 * V_36 ) {}
void F_48 ( struct V_2 * V_61 )
{
if ( ! F_49 () )
return;
if ( F_50 ( V_61 ) )
F_51 ( V_61 ) ;
else
F_52 ( V_61 ) ;
#ifdef F_53
F_54 ( V_61 ) ;
#endif
F_55 ( V_61 ) ;
}
void F_56 ( struct V_2 * V_45 )
{
if ( ! F_49 () )
return;
if ( ! F_57 () ) {
if ( F_58 () ) {
F_54 ( V_45 ) ;
return;
}
if ( F_50 ( V_45 ) ) {
F_51 ( V_45 ) ;
return;
}
}
F_52 ( V_45 ) ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_62 , T_3 * V_42 )
{
* V_62 = V_16 -> V_22 ;
* V_42 = V_16 -> V_30 ;
}
void F_60 ( struct V_2 * V_16 , T_3 * V_62 , T_3 * V_42 )
{
struct V_46 V_20 ;
F_40 ( V_16 , & V_20 ) ;
* V_62 = V_20 . V_22 ;
* V_42 = V_20 . V_30 ;
}
void F_61 ( struct V_2 * V_16 , int V_54 )
{
T_3 V_55 = F_46 ( V_56 ) ;
struct V_36 * V_36 = F_33 () ;
if ( F_49 () )
return;
if ( V_1 ) {
F_45 ( V_16 , V_54 , V_36 ) ;
return;
}
if ( F_35 () )
return;
if ( V_54 )
F_22 ( V_16 , V_56 , V_55 ) ;
else if ( ( V_16 != V_36 -> V_57 ) || ( F_30 () != V_63 ) )
F_29 ( V_16 , V_63 , V_56 ,
V_55 ) ;
else
F_32 ( V_56 ) ;
}
void F_62 ( unsigned long V_58 )
{
F_31 ( F_63 ( V_58 ) ) ;
}
void F_64 ( unsigned long V_58 )
{
if ( V_1 ) {
F_47 ( V_58 ) ;
return;
}
F_32 ( F_63 ( V_58 ) ) ;
}
static T_3 F_65 ( T_2 V_30 , T_2 V_64 , T_2 V_65 )
{
T_2 V_66 ;
for (; ; ) {
if ( V_30 > V_64 ) {
T_2 V_18 = V_64 ; V_64 = V_30 ; V_30 = V_18 ;
}
if ( V_65 >> 32 )
goto V_67;
if ( ! ( V_64 >> 32 ) )
break;
if ( V_30 >> 31 )
goto V_67;
V_30 <<= 1 ;
V_64 >>= 1 ;
continue;
V_67:
V_64 >>= 1 ;
V_65 >>= 1 ;
}
V_66 = F_66 ( ( T_2 ) ( V_68 ) V_30 * ( T_2 ) ( V_68 ) V_64 , ( V_68 ) V_65 ) ;
return ( V_26 T_3 ) V_66 ;
}
static void F_67 ( struct V_46 * V_3 ,
struct V_20 * V_61 ,
T_3 * V_62 , T_3 * V_42 )
{
T_3 V_64 , V_30 , V_22 , V_65 ;
if ( F_49 () ) {
* V_62 = V_3 -> V_22 ;
* V_42 = V_3 -> V_30 ;
return;
}
V_30 = V_3 -> V_30 ;
V_65 = V_30 + V_3 -> V_22 ;
V_64 = F_68 ( V_3 -> V_51 ) ;
if ( V_61 -> V_30 + V_61 -> V_22 >= V_64 )
goto V_53;
if ( V_65 ) {
V_30 = F_65 ( ( V_26 T_2 ) V_30 ,
( V_26 T_2 ) V_64 , ( V_26 T_2 ) V_65 ) ;
V_22 = V_64 - V_30 ;
} else {
V_30 = V_64 ;
V_22 = 0 ;
}
V_61 -> V_30 = F_69 ( V_61 -> V_30 , V_30 ) ;
V_61 -> V_22 = F_69 ( V_61 -> V_22 , V_22 ) ;
V_53:
* V_62 = V_61 -> V_22 ;
* V_42 = V_61 -> V_30 ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_62 , T_3 * V_42 )
{
struct V_46 V_20 = {
. V_51 = V_16 -> V_69 . V_51 ,
} ;
V_46 ( V_16 , & V_20 . V_22 , & V_20 . V_30 ) ;
F_67 ( & V_20 , & V_16 -> V_70 , V_62 , V_42 ) ;
}
void F_60 ( struct V_2 * V_16 , T_3 * V_62 , T_3 * V_42 )
{
struct V_46 V_20 ;
F_40 ( V_16 , & V_20 ) ;
F_67 ( & V_20 , & V_16 -> signal -> V_70 , V_62 , V_42 ) ;
}
static unsigned long long F_70 ( struct V_2 * V_45 )
{
unsigned long long clock ;
clock = F_71 () ;
if ( clock < V_45 -> V_71 )
return 0 ;
return clock - V_45 -> V_71 ;
}
static T_3 F_72 ( struct V_2 * V_45 )
{
unsigned long long V_5 = F_70 ( V_45 ) ;
F_73 ( V_45 -> V_72 == V_73 ) ;
V_45 -> V_71 += V_5 ;
return F_68 ( V_5 ) ;
}
static void F_74 ( struct V_2 * V_45 )
{
T_3 V_74 = F_72 ( V_45 ) ;
F_29 ( V_45 , F_30 () , V_74 , F_46 ( V_74 ) ) ;
}
void F_52 ( struct V_2 * V_45 )
{
if ( ! F_49 () )
return;
F_75 ( & V_45 -> V_75 ) ;
F_74 ( V_45 ) ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_77 ( struct V_2 * V_45 )
{
if ( ! F_49 () )
return;
F_75 ( & V_45 -> V_75 ) ;
if ( F_58 () )
V_45 -> V_72 = V_76 ;
F_74 ( V_45 ) ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_54 ( struct V_2 * V_45 )
{
T_3 V_74 ;
if ( ! F_49 () )
return;
V_74 = F_72 ( V_45 ) ;
F_75 ( & V_45 -> V_75 ) ;
V_45 -> V_72 = V_77 ;
F_22 ( V_45 , V_74 , F_46 ( V_74 ) ) ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_78 ( struct V_2 * V_45 )
{
if ( ! F_49 () )
return;
F_75 ( & V_45 -> V_75 ) ;
V_45 -> V_72 = V_76 ;
F_74 ( V_45 ) ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_79 ( struct V_2 * V_45 )
{
F_75 ( & V_45 -> V_75 ) ;
F_74 ( V_45 ) ;
V_60 -> V_4 |= V_33 ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_80 ( struct V_2 * V_45 )
{
F_75 ( & V_45 -> V_75 ) ;
F_74 ( V_45 ) ;
V_60 -> V_4 &= ~ V_33 ;
F_76 ( & V_45 -> V_75 ) ;
}
void F_51 ( struct V_2 * V_45 )
{
T_3 V_74 = F_72 ( V_45 ) ;
F_32 ( V_74 ) ;
}
bool F_49 ( void )
{
return F_81 () ;
}
void F_55 ( struct V_2 * V_61 )
{
F_75 ( & V_61 -> V_75 ) ;
V_61 -> V_72 = V_73 ;
F_76 ( & V_61 -> V_75 ) ;
F_75 ( & V_60 -> V_75 ) ;
V_60 -> V_72 = V_77 ;
V_60 -> V_71 = F_6 ( F_5 () ) ;
F_76 ( & V_60 -> V_75 ) ;
}
void F_82 ( struct V_2 * V_50 , int V_6 )
{
unsigned long V_4 ;
F_83 ( & V_50 -> V_75 , V_4 ) ;
V_50 -> V_72 = V_77 ;
V_50 -> V_71 = F_6 ( V_6 ) ;
F_84 ( & V_50 -> V_75 , V_4 ) ;
}
T_3 F_85 ( struct V_2 * V_50 )
{
unsigned int V_78 ;
T_3 V_27 ;
do {
V_78 = F_86 ( & V_50 -> V_75 ) ;
V_27 = V_50 -> V_27 ;
if ( V_50 -> V_4 & V_33 )
V_27 += F_70 ( V_50 ) ;
} while ( F_87 ( & V_50 -> V_75 , V_78 ) );
return V_27 ;
}
static void
F_88 ( struct V_2 * V_50 ,
T_3 * V_79 , T_3 * V_80 ,
T_3 * V_81 , T_3 * V_82 ,
T_3 * V_83 , T_3 * V_84 )
{
unsigned int V_78 ;
unsigned long long V_5 ;
do {
* V_83 = 0 ;
* V_84 = 0 ;
V_78 = F_86 ( & V_50 -> V_75 ) ;
if ( V_79 )
* V_79 = * V_81 ;
if ( V_80 )
* V_80 = * V_82 ;
if ( V_50 -> V_72 == V_73 ||
F_50 ( V_50 ) )
continue;
V_5 = F_70 ( V_50 ) ;
if ( V_50 -> V_72 == V_76 || V_50 -> V_4 & V_33 ) {
* V_83 = V_5 ;
} else {
if ( V_50 -> V_72 == V_77 )
* V_84 = V_5 ;
}
} while ( F_87 ( & V_50 -> V_75 , V_78 ) );
}
void V_46 ( struct V_2 * V_50 , T_3 * V_22 , T_3 * V_30 )
{
T_3 V_83 , V_84 ;
F_88 ( V_50 , V_22 , V_30 , & V_50 -> V_22 ,
& V_50 -> V_30 , & V_83 , & V_84 ) ;
if ( V_22 )
* V_22 += V_83 ;
if ( V_30 )
* V_30 += V_84 ;
}
void F_89 ( struct V_2 * V_50 ,
T_3 * V_23 , T_3 * V_31 )
{
T_3 V_83 , V_84 ;
F_88 ( V_50 , V_23 , V_31 ,
& V_50 -> V_23 , & V_50 -> V_31 , & V_83 , & V_84 ) ;
if ( V_23 )
* V_23 += F_46 ( V_83 ) ;
if ( V_31 )
* V_31 += F_46 ( V_84 ) ;
}
