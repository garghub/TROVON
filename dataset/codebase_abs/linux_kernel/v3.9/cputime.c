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
#ifdef F_20
struct V_19 * V_20 ;
struct V_21 * V_22 ;
#endif
F_21 ( V_19 ) . V_10 [ V_17 ] += V_18 ;
#ifdef F_20
if ( F_22 ( ! V_23 . V_24 ) )
return;
F_23 () ;
V_22 = F_24 ( V_16 ) ;
while ( V_22 && ( V_22 != & V_25 ) ) {
V_20 = F_25 ( V_22 -> V_10 ) ;
V_20 -> V_10 [ V_17 ] += V_18 ;
V_22 = F_26 ( V_22 ) ;
}
F_27 () ;
#endif
}
void F_28 ( struct V_2 * V_16 , T_3 V_26 ,
T_3 V_27 )
{
int V_17 ;
V_16 -> V_28 += V_26 ;
V_16 -> V_29 += V_27 ;
F_29 ( V_16 , V_26 ) ;
V_17 = ( F_30 ( V_16 ) > 0 ) ? V_30 : V_31 ;
F_19 ( V_16 , V_17 , ( V_32 T_2 ) V_26 ) ;
F_31 ( V_16 ) ;
}
static void F_32 ( struct V_2 * V_16 , T_3 V_26 ,
T_3 V_27 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_16 -> V_28 += V_26 ;
V_16 -> V_29 += V_27 ;
F_29 ( V_16 , V_26 ) ;
V_16 -> V_33 += V_26 ;
if ( F_30 ( V_16 ) > 0 ) {
V_10 [ V_30 ] += ( V_32 T_2 ) V_26 ;
V_10 [ V_34 ] += ( V_32 T_2 ) V_26 ;
} else {
V_10 [ V_31 ] += ( V_32 T_2 ) V_26 ;
V_10 [ V_35 ] += ( V_32 T_2 ) V_26 ;
}
}
static inline
void F_33 ( struct V_2 * V_16 , T_3 V_26 ,
T_3 V_27 , int V_17 )
{
V_16 -> V_36 += V_26 ;
V_16 -> V_37 += V_27 ;
F_34 ( V_16 , V_26 ) ;
F_19 ( V_16 , V_17 , ( V_32 T_2 ) V_26 ) ;
F_31 ( V_16 ) ;
}
void F_35 ( struct V_2 * V_16 , int V_38 ,
T_3 V_26 , T_3 V_27 )
{
int V_17 ;
if ( ( V_16 -> V_4 & V_39 ) && ( F_36 () - V_38 == 0 ) ) {
F_32 ( V_16 , V_26 , V_27 ) ;
return;
}
if ( F_10 () - V_38 )
V_17 = V_14 ;
else if ( F_11 () )
V_17 = V_15 ;
else
V_17 = V_40 ;
F_33 ( V_16 , V_26 , V_27 , V_17 ) ;
}
void F_37 ( T_3 V_26 )
{
T_2 * V_10 = V_11 -> V_10 ;
V_10 [ V_41 ] += ( V_32 T_2 ) V_26 ;
}
void F_38 ( T_3 V_26 )
{
T_2 * V_10 = V_11 -> V_10 ;
struct V_42 * V_42 = F_39 () ;
if ( F_40 ( & V_42 -> V_43 ) > 0 )
V_10 [ V_44 ] += ( V_32 T_2 ) V_26 ;
else
V_10 [ V_45 ] += ( V_32 T_2 ) V_26 ;
}
static T_4 bool F_41 ( void )
{
#ifdef F_42
if ( F_43 ( & V_46 ) ) {
T_2 V_47 , V_48 = 0 ;
V_47 = F_44 ( F_5 () ) ;
V_47 -= F_39 () -> V_49 ;
V_48 = F_45 ( V_47 ) ;
F_39 () -> V_49 += V_48 * V_50 ;
F_37 ( V_48 ) ;
return V_48 ;
}
#endif
return false ;
}
void F_46 ( struct V_2 * V_51 , struct V_52 * V_53 )
{
struct V_54 * V_55 = V_51 -> signal ;
T_3 V_28 , V_36 ;
struct V_2 * V_56 ;
V_53 -> V_28 = V_55 -> V_28 ;
V_53 -> V_36 = V_55 -> V_36 ;
V_53 -> V_57 = V_55 -> V_58 ;
F_23 () ;
if ( ! F_47 ( F_48 ( V_51 ) ) )
goto V_59;
V_56 = V_51 ;
do {
V_52 ( V_56 , & V_28 , & V_36 ) ;
V_53 -> V_28 += V_28 ;
V_53 -> V_36 += V_36 ;
V_53 -> V_57 += F_49 ( V_56 ) ;
} while_each_thread(tsk, t) ;
void F_50 ( struct V_2 * V_16 , int V_60 ,
struct V_42 * V_42 )
{
T_3 V_61 = F_51 ( V_62 ) ;
T_2 * V_10 = V_11 -> V_10 ;
if ( F_41 () )
return;
if ( F_15 () ) {
V_10 [ V_14 ] += ( V_32 T_2 ) V_62 ;
} else if ( F_18 () ) {
V_10 [ V_15 ] += ( V_32 T_2 ) V_62 ;
} else if ( F_12 () == V_16 ) {
F_33 ( V_16 , V_62 , V_61 ,
V_15 ) ;
} else if ( V_60 ) {
F_28 ( V_16 , V_62 , V_61 ) ;
} else if ( V_16 == V_42 -> V_63 ) {
F_38 ( V_62 ) ;
} else if ( V_16 -> V_4 & V_39 ) {
F_32 ( V_16 , V_62 , V_61 ) ;
} else {
F_33 ( V_16 , V_62 , V_61 ,
V_40 ) ;
}
}
static void F_52 ( int V_64 )
{
int V_65 ;
struct V_42 * V_42 = F_39 () ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
F_50 ( V_66 , 0 , V_42 ) ;
}
static inline void F_52 ( int V_64 ) {}
static inline void F_50 ( struct V_2 * V_16 , int V_60 ,
struct V_42 * V_42 ) {}
void F_53 ( struct V_2 * V_16 , int V_60 )
{
T_3 V_61 = F_51 ( V_62 ) ;
struct V_42 * V_42 = F_39 () ;
if ( F_54 () )
return;
if ( V_1 ) {
F_50 ( V_16 , V_60 , V_42 ) ;
return;
}
if ( F_41 () )
return;
if ( V_60 )
F_28 ( V_16 , V_62 , V_61 ) ;
else if ( ( V_16 != V_42 -> V_63 ) || ( F_36 () != V_67 ) )
F_35 ( V_16 , V_67 , V_62 ,
V_61 ) ;
else
F_38 ( V_62 ) ;
}
void F_55 ( unsigned long V_64 )
{
F_37 ( F_56 ( V_64 ) ) ;
}
void F_57 ( unsigned long V_64 )
{
if ( V_1 ) {
F_52 ( V_64 ) ;
return;
}
F_38 ( F_56 ( V_64 ) ) ;
}
void F_58 ( struct V_2 * V_16 , T_3 * V_68 , T_3 * V_48 )
{
* V_68 = V_16 -> V_28 ;
* V_48 = V_16 -> V_36 ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_68 , T_3 * V_48 )
{
struct V_52 V_26 ;
F_46 ( V_16 , & V_26 ) ;
* V_68 = V_26 . V_28 ;
* V_48 = V_26 . V_36 ;
}
void F_60 ( struct V_2 * V_69 )
{
if ( ! F_54 () )
return;
if ( F_61 ( V_69 ) )
F_62 ( V_69 ) ;
else
F_63 ( V_69 ) ;
#ifdef F_64
F_65 ( V_69 ) ;
#endif
F_66 ( V_69 ) ;
}
void F_67 ( struct V_2 * V_51 )
{
if ( ! F_54 () )
return;
if ( ! F_68 () ) {
if ( F_69 () ) {
F_65 ( V_51 ) ;
return;
}
if ( F_61 ( V_51 ) ) {
F_62 ( V_51 ) ;
return;
}
}
F_63 ( V_51 ) ;
}
static T_3 F_70 ( T_3 V_36 , T_3 V_70 , T_3 V_71 )
{
T_2 V_72 = ( V_32 T_2 ) V_70 ;
V_72 *= ( V_32 T_2 ) V_36 ;
if ( sizeof( T_3 ) == 4 )
V_72 = F_71 ( V_72 , ( V_32 V_73 ) V_71 ) ;
else
V_72 = F_72 ( V_72 , ( V_32 T_2 ) V_71 ) ;
return ( V_32 T_3 ) V_72 ;
}
static void F_73 ( struct V_52 * V_3 ,
struct V_26 * V_69 ,
T_3 * V_68 , T_3 * V_48 )
{
T_3 V_70 , V_36 , V_71 ;
V_36 = V_3 -> V_36 ;
V_71 = V_36 + V_3 -> V_28 ;
V_70 = F_74 ( V_3 -> V_57 ) ;
if ( V_71 )
V_36 = F_70 ( V_36 , V_70 , V_71 ) ;
else
V_36 = V_70 ;
V_69 -> V_36 = F_75 ( V_69 -> V_36 , V_36 ) ;
V_69 -> V_28 = F_75 ( V_69 -> V_28 , V_70 - V_69 -> V_36 ) ;
* V_68 = V_69 -> V_28 ;
* V_48 = V_69 -> V_36 ;
}
void F_58 ( struct V_2 * V_16 , T_3 * V_68 , T_3 * V_48 )
{
struct V_52 V_26 = {
. V_57 = V_16 -> V_74 . V_57 ,
} ;
V_52 ( V_16 , & V_26 . V_28 , & V_26 . V_36 ) ;
F_73 ( & V_26 , & V_16 -> V_75 , V_68 , V_48 ) ;
}
void F_59 ( struct V_2 * V_16 , T_3 * V_68 , T_3 * V_48 )
{
struct V_52 V_26 ;
F_46 ( V_16 , & V_26 ) ;
F_73 ( & V_26 , & V_16 -> signal -> V_75 , V_68 , V_48 ) ;
}
static unsigned long long F_76 ( struct V_2 * V_51 )
{
unsigned long long clock ;
clock = F_77 () ;
if ( clock < V_51 -> V_76 )
return 0 ;
return clock - V_51 -> V_76 ;
}
static T_3 F_78 ( struct V_2 * V_51 )
{
unsigned long long V_5 = F_76 ( V_51 ) ;
F_79 ( V_51 -> V_77 == V_78 ) ;
V_51 -> V_76 += V_5 ;
return F_74 ( V_5 ) ;
}
static void F_80 ( struct V_2 * V_51 )
{
T_3 V_79 = F_78 ( V_51 ) ;
F_35 ( V_51 , F_36 () , V_79 , F_51 ( V_79 ) ) ;
}
void F_63 ( struct V_2 * V_51 )
{
if ( ! F_54 () )
return;
F_81 ( & V_51 -> V_80 ) ;
F_80 ( V_51 ) ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_83 ( struct V_2 * V_51 )
{
if ( ! F_54 () )
return;
F_81 ( & V_51 -> V_80 ) ;
if ( F_69 () )
V_51 -> V_77 = V_81 ;
F_80 ( V_51 ) ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_65 ( struct V_2 * V_51 )
{
T_3 V_79 ;
if ( ! F_54 () )
return;
V_79 = F_78 ( V_51 ) ;
F_81 ( & V_51 -> V_80 ) ;
V_51 -> V_77 = V_82 ;
F_28 ( V_51 , V_79 , F_51 ( V_79 ) ) ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_84 ( struct V_2 * V_51 )
{
if ( ! F_54 () )
return;
F_81 ( & V_51 -> V_80 ) ;
V_51 -> V_77 = V_81 ;
F_80 ( V_51 ) ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_85 ( struct V_2 * V_51 )
{
F_81 ( & V_51 -> V_80 ) ;
F_80 ( V_51 ) ;
V_66 -> V_4 |= V_39 ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_86 ( struct V_2 * V_51 )
{
F_81 ( & V_51 -> V_80 ) ;
F_80 ( V_51 ) ;
V_66 -> V_4 &= ~ V_39 ;
F_82 ( & V_51 -> V_80 ) ;
}
void F_62 ( struct V_2 * V_51 )
{
T_3 V_79 = F_78 ( V_51 ) ;
F_38 ( V_79 ) ;
}
bool F_54 ( void )
{
return F_87 () ;
}
void F_66 ( struct V_2 * V_69 )
{
F_81 ( & V_69 -> V_80 ) ;
V_69 -> V_77 = V_78 ;
F_82 ( & V_69 -> V_80 ) ;
F_81 ( & V_66 -> V_80 ) ;
V_66 -> V_77 = V_82 ;
V_66 -> V_76 = F_88 () ;
F_82 ( & V_66 -> V_80 ) ;
}
void F_89 ( struct V_2 * V_56 )
{
unsigned long V_4 ;
F_90 ( & V_56 -> V_80 , V_4 ) ;
V_56 -> V_77 = V_82 ;
V_56 -> V_76 = F_88 () ;
F_91 ( & V_56 -> V_80 , V_4 ) ;
}
T_3 F_92 ( struct V_2 * V_56 )
{
unsigned int V_83 ;
T_3 V_33 ;
do {
V_83 = F_93 ( & V_56 -> V_80 ) ;
V_33 = V_56 -> V_33 ;
if ( V_56 -> V_4 & V_39 )
V_33 += F_76 ( V_56 ) ;
} while ( F_94 ( & V_56 -> V_80 , V_83 ) );
return V_33 ;
}
static void
F_95 ( struct V_2 * V_56 ,
T_3 * V_84 , T_3 * V_85 ,
T_3 * V_86 , T_3 * V_87 ,
T_3 * V_88 , T_3 * V_89 )
{
unsigned int V_83 ;
unsigned long long V_5 ;
do {
* V_88 = 0 ;
* V_89 = 0 ;
V_83 = F_93 ( & V_56 -> V_80 ) ;
if ( V_84 )
* V_84 = * V_86 ;
if ( V_85 )
* V_85 = * V_87 ;
if ( V_56 -> V_77 == V_78 ||
F_61 ( V_56 ) )
continue;
V_5 = F_76 ( V_56 ) ;
if ( V_56 -> V_77 == V_81 || V_56 -> V_4 & V_39 ) {
* V_88 = V_5 ;
} else {
if ( V_56 -> V_77 == V_82 )
* V_89 = V_5 ;
}
} while ( F_94 ( & V_56 -> V_80 , V_83 ) );
}
void V_52 ( struct V_2 * V_56 , T_3 * V_28 , T_3 * V_36 )
{
T_3 V_88 , V_89 ;
F_95 ( V_56 , V_28 , V_36 , & V_56 -> V_28 ,
& V_56 -> V_36 , & V_88 , & V_89 ) ;
if ( V_28 )
* V_28 += V_88 ;
if ( V_36 )
* V_36 += V_89 ;
}
void F_96 ( struct V_2 * V_56 ,
T_3 * V_29 , T_3 * V_37 )
{
T_3 V_88 , V_89 ;
F_95 ( V_56 , V_29 , V_37 ,
& V_56 -> V_29 , & V_56 -> V_37 , & V_88 , & V_89 ) ;
if ( V_29 )
* V_29 += F_51 ( V_88 ) ;
if ( V_37 )
* V_37 += F_51 ( V_89 ) ;
}
