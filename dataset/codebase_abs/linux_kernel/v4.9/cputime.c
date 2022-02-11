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
struct V_4 * V_4 = F_4 ( & V_5 ) ;
T_1 V_6 ;
int V_7 ;
if ( ! V_1 )
return;
V_7 = F_5 () ;
V_6 = F_6 ( V_7 ) - V_4 -> V_8 ;
V_4 -> V_8 += V_6 ;
F_7 ( & V_4 -> V_9 ) ;
if ( F_8 () )
V_4 -> V_10 += V_6 ;
else if ( F_9 () && V_3 != F_10 () )
V_4 -> V_11 += V_6 ;
F_11 ( & V_4 -> V_9 ) ;
}
static T_2 F_12 ( T_3 V_4 , int V_12 , T_2 V_13 )
{
T_3 * V_14 = V_15 -> V_14 ;
T_2 V_16 ;
V_16 = F_13 ( V_4 ) - V_14 [ V_12 ] ;
V_16 = F_14 ( V_16 , V_13 ) ;
V_14 [ V_12 ] += V_16 ;
return V_16 ;
}
static T_2 F_15 ( T_2 V_13 )
{
return F_12 ( F_16 ( V_5 . V_10 ) ,
V_17 , V_13 ) ;
}
static T_2 F_17 ( T_2 V_13 )
{
return F_12 ( F_16 ( V_5 . V_11 ) ,
V_18 , V_13 ) ;
}
static T_2 F_15 ( T_2 V_19 )
{
return 0 ;
}
static T_2 F_17 ( T_2 V_19 )
{
return 0 ;
}
static inline void F_18 ( struct V_2 * V_20 , int V_21 ,
T_3 V_22 )
{
F_19 ( V_23 . V_14 [ V_21 ] , V_22 ) ;
F_20 ( V_20 , V_21 , V_22 ) ;
}
void F_21 ( struct V_2 * V_20 , T_2 V_24 ,
T_2 V_25 )
{
int V_21 ;
V_20 -> V_26 += V_24 ;
V_20 -> V_27 += V_25 ;
F_22 ( V_20 , V_24 ) ;
V_21 = ( F_23 ( V_20 ) > 0 ) ? V_28 : V_29 ;
F_18 ( V_20 , V_21 , ( V_30 T_3 ) V_24 ) ;
F_24 ( V_20 ) ;
}
static void F_25 ( struct V_2 * V_20 , T_2 V_24 ,
T_2 V_25 )
{
T_3 * V_14 = V_15 -> V_14 ;
V_20 -> V_26 += V_24 ;
V_20 -> V_27 += V_25 ;
F_22 ( V_20 , V_24 ) ;
V_20 -> V_31 += V_24 ;
if ( F_23 ( V_20 ) > 0 ) {
V_14 [ V_28 ] += ( V_30 T_3 ) V_24 ;
V_14 [ V_32 ] += ( V_30 T_3 ) V_24 ;
} else {
V_14 [ V_29 ] += ( V_30 T_3 ) V_24 ;
V_14 [ V_33 ] += ( V_30 T_3 ) V_24 ;
}
}
static inline
void F_26 ( struct V_2 * V_20 , T_2 V_24 ,
T_2 V_25 , int V_21 )
{
V_20 -> V_34 += V_24 ;
V_20 -> V_35 += V_25 ;
F_27 ( V_20 , V_24 ) ;
F_18 ( V_20 , V_21 , ( V_30 T_3 ) V_24 ) ;
F_24 ( V_20 ) ;
}
void F_28 ( struct V_2 * V_20 , int V_36 ,
T_2 V_24 , T_2 V_25 )
{
int V_21 ;
if ( ( V_20 -> V_37 & V_38 ) && ( F_29 () - V_36 == 0 ) ) {
F_25 ( V_20 , V_24 , V_25 ) ;
return;
}
if ( F_8 () - V_36 )
V_21 = V_17 ;
else if ( F_9 () )
V_21 = V_18 ;
else
V_21 = V_39 ;
F_26 ( V_20 , V_24 , V_25 , V_21 ) ;
}
void F_30 ( T_2 V_24 )
{
T_3 * V_14 = V_15 -> V_14 ;
V_14 [ V_40 ] += ( V_30 T_3 ) V_24 ;
}
void F_31 ( T_2 V_24 )
{
T_3 * V_14 = V_15 -> V_14 ;
struct V_41 * V_41 = F_32 () ;
if ( F_33 ( & V_41 -> V_42 ) > 0 )
V_14 [ V_43 ] += ( V_30 T_3 ) V_24 ;
else
V_14 [ V_44 ] += ( V_30 T_3 ) V_24 ;
}
static T_4 T_2 F_34 ( T_2 V_13 )
{
#ifdef F_35
if ( F_36 ( & V_45 ) ) {
T_2 V_46 ;
T_3 V_47 ;
V_47 = F_37 ( F_5 () ) ;
V_47 -= F_32 () -> V_48 ;
V_46 = F_14 ( F_38 ( V_47 ) , V_13 ) ;
F_30 ( V_46 ) ;
F_32 () -> V_48 += F_39 ( V_46 ) ;
return V_46 ;
}
#endif
return 0 ;
}
static inline T_2 F_40 ( T_2 V_49 )
{
T_2 V_50 ;
F_41 ( ! F_42 () ) ;
V_50 = F_34 ( V_49 ) ;
if ( V_50 < V_49 )
V_50 += F_15 ( V_49 - V_50 ) ;
if ( V_50 < V_49 )
V_50 += F_17 ( V_49 - V_50 ) ;
return V_50 ;
}
static inline T_3 F_43 ( struct V_2 * V_51 )
{
return V_51 -> V_52 . V_53 ;
}
static T_3 F_43 ( struct V_2 * V_51 )
{
T_3 V_54 ;
struct V_55 V_56 ;
struct V_41 * V_41 ;
V_41 = F_44 ( V_51 , & V_56 ) ;
V_54 = V_51 -> V_52 . V_53 ;
F_45 ( V_41 , V_51 , & V_56 ) ;
return V_54 ;
}
void F_46 ( struct V_2 * V_57 , struct V_58 * V_59 )
{
struct V_60 * V_61 = V_57 -> signal ;
T_2 V_26 , V_34 ;
struct V_2 * V_51 ;
unsigned int V_62 , V_63 ;
unsigned long V_37 ;
if ( F_47 ( V_64 , V_57 ) )
( void ) F_48 ( V_64 ) ;
F_49 () ;
V_63 = 0 ;
do {
V_62 = V_63 ;
V_37 = F_50 ( & V_61 -> V_65 , & V_62 ) ;
V_59 -> V_26 = V_61 -> V_26 ;
V_59 -> V_34 = V_61 -> V_34 ;
V_59 -> V_53 = V_61 -> V_66 ;
F_51 (tsk, t) {
V_58 ( V_51 , & V_26 , & V_34 ) ;
V_59 -> V_26 += V_26 ;
V_59 -> V_34 += V_34 ;
V_59 -> V_53 += F_43 ( V_51 ) ;
}
V_63 = 1 ;
} while ( F_52 ( & V_61 -> V_65 , V_62 ) );
F_53 ( & V_61 -> V_65 , V_62 , V_37 ) ;
F_54 () ;
}
static void F_55 ( struct V_2 * V_20 , int V_67 ,
struct V_41 * V_41 , int V_68 )
{
T_3 V_24 = ( V_30 T_3 ) V_69 * V_68 ;
T_2 V_70 , V_71 ;
V_71 = F_40 ( V_72 ) ;
if ( V_71 >= V_24 )
return;
V_24 -= V_71 ;
V_70 = F_56 ( V_24 ) ;
if ( F_10 () == V_20 ) {
F_26 ( V_20 , V_24 , V_70 , V_18 ) ;
} else if ( V_67 ) {
F_21 ( V_20 , V_24 , V_70 ) ;
} else if ( V_20 == V_41 -> V_73 ) {
F_31 ( V_24 ) ;
} else if ( V_20 -> V_37 & V_38 ) {
F_25 ( V_20 , V_24 , V_70 ) ;
} else {
F_26 ( V_20 , V_24 , V_70 , V_39 ) ;
}
}
static void F_57 ( int V_68 )
{
struct V_41 * V_41 = F_32 () ;
F_55 ( V_64 , 0 , V_41 , V_68 ) ;
}
static inline void F_57 ( int V_68 ) {}
static inline void F_55 ( struct V_2 * V_20 , int V_67 ,
struct V_41 * V_41 , int V_74 ) {}
void F_58 ( struct V_2 * V_75 )
{
if ( F_59 ( V_75 ) )
F_60 ( V_75 ) ;
else
F_61 ( V_75 ) ;
#ifdef F_62
F_63 ( V_75 ) ;
#endif
F_64 ( V_75 ) ;
}
void F_65 ( struct V_2 * V_57 )
{
if ( ! F_66 () && F_59 ( V_57 ) )
F_60 ( V_57 ) ;
else
F_61 ( V_57 ) ;
}
void F_67 ( struct V_2 * V_20 , T_2 * V_76 , T_2 * V_77 )
{
* V_76 = V_20 -> V_26 ;
* V_77 = V_20 -> V_34 ;
}
void F_68 ( struct V_2 * V_20 , T_2 * V_76 , T_2 * V_77 )
{
struct V_58 V_24 ;
F_46 ( V_20 , & V_24 ) ;
* V_76 = V_24 . V_26 ;
* V_77 = V_24 . V_34 ;
}
void F_69 ( struct V_2 * V_20 , int V_67 )
{
T_2 V_24 , V_70 , V_47 ;
struct V_41 * V_41 = F_32 () ;
if ( F_70 () )
return;
if ( V_1 ) {
F_55 ( V_20 , V_67 , V_41 , 1 ) ;
return;
}
V_24 = V_69 ;
V_47 = F_34 ( V_72 ) ;
if ( V_47 >= V_24 )
return;
V_24 -= V_47 ;
V_70 = F_56 ( V_24 ) ;
if ( V_67 )
F_21 ( V_20 , V_24 , V_70 ) ;
else if ( ( V_20 != V_41 -> V_73 ) || ( F_29 () != V_78 ) )
F_28 ( V_20 , V_78 , V_24 , V_70 ) ;
else
F_31 ( V_24 ) ;
}
void F_71 ( unsigned long V_68 )
{
T_2 V_24 , V_47 ;
if ( V_1 ) {
F_57 ( V_68 ) ;
return;
}
V_24 = F_72 ( V_68 ) ;
V_47 = F_34 ( V_72 ) ;
if ( V_47 >= V_24 )
return;
V_24 -= V_47 ;
F_31 ( V_24 ) ;
}
static T_2 F_73 ( T_3 V_34 , T_3 V_79 , T_3 V_80 )
{
T_3 V_70 ;
for (; ; ) {
if ( V_34 > V_79 )
F_74 ( V_79 , V_34 ) ;
if ( V_80 >> 32 )
goto V_81;
if ( ! ( V_79 >> 32 ) )
break;
if ( V_34 >> 31 )
goto V_81;
V_34 <<= 1 ;
V_79 >>= 1 ;
continue;
V_81:
V_79 >>= 1 ;
V_80 >>= 1 ;
}
V_70 = F_75 ( ( T_3 ) ( V_82 ) V_34 * ( T_3 ) ( V_82 ) V_79 , ( V_82 ) V_80 ) ;
return ( V_30 T_2 ) V_70 ;
}
static void F_76 ( struct V_58 * V_3 ,
struct V_83 * V_75 ,
T_2 * V_76 , T_2 * V_77 )
{
T_2 V_79 , V_34 , V_26 ;
unsigned long V_37 ;
F_77 ( & V_75 -> V_84 , V_37 ) ;
V_79 = F_38 ( V_3 -> V_53 ) ;
if ( V_75 -> V_34 + V_75 -> V_26 >= V_79 )
goto V_85;
V_34 = V_3 -> V_34 ;
V_26 = V_3 -> V_26 ;
if ( V_34 == 0 ) {
V_26 = V_79 ;
goto V_86;
}
if ( V_26 == 0 ) {
V_34 = V_79 ;
goto V_86;
}
V_34 = F_73 ( ( V_30 T_3 ) V_34 , ( V_30 T_3 ) V_79 ,
( V_30 T_3 ) ( V_34 + V_26 ) ) ;
V_86:
if ( V_34 < V_75 -> V_34 )
V_34 = V_75 -> V_34 ;
V_26 = V_79 - V_34 ;
if ( V_26 < V_75 -> V_26 ) {
V_26 = V_75 -> V_26 ;
V_34 = V_79 - V_26 ;
}
V_75 -> V_34 = V_34 ;
V_75 -> V_26 = V_26 ;
V_85:
* V_76 = V_75 -> V_26 ;
* V_77 = V_75 -> V_34 ;
F_78 ( & V_75 -> V_84 , V_37 ) ;
}
void F_67 ( struct V_2 * V_20 , T_2 * V_76 , T_2 * V_77 )
{
struct V_58 V_24 = {
. V_53 = V_20 -> V_52 . V_53 ,
} ;
V_58 ( V_20 , & V_24 . V_26 , & V_24 . V_34 ) ;
F_76 ( & V_24 , & V_20 -> V_83 , V_76 , V_77 ) ;
}
void F_68 ( struct V_2 * V_20 , T_2 * V_76 , T_2 * V_77 )
{
struct V_58 V_24 ;
F_46 ( V_20 , & V_24 ) ;
F_76 ( & V_24 , & V_20 -> signal -> V_83 , V_76 , V_77 ) ;
}
static T_2 F_79 ( struct V_2 * V_57 )
{
unsigned long V_87 = F_80 ( V_88 ) ;
if ( F_81 ( V_87 , ( unsigned long ) V_57 -> V_89 ) )
return 0 ;
return F_72 ( V_87 - V_57 -> V_89 ) ;
}
static T_2 F_82 ( struct V_2 * V_57 )
{
unsigned long V_87 = F_80 ( V_88 ) ;
T_2 V_6 , V_71 ;
V_6 = F_72 ( V_87 - V_57 -> V_89 ) ;
V_71 = F_40 ( V_6 ) ;
F_41 ( V_57 -> V_90 == V_91 ) ;
V_57 -> V_89 = V_87 ;
return V_6 - V_71 ;
}
static void F_83 ( struct V_2 * V_57 )
{
T_2 V_92 = F_82 ( V_57 ) ;
F_28 ( V_57 , F_29 () , V_92 , F_56 ( V_92 ) ) ;
}
void F_61 ( struct V_2 * V_57 )
{
if ( ! F_79 ( V_57 ) )
return;
F_84 ( & V_57 -> V_93 ) ;
F_83 ( V_57 ) ;
F_85 ( & V_57 -> V_93 ) ;
}
void F_63 ( struct V_2 * V_57 )
{
T_2 V_92 ;
F_84 ( & V_57 -> V_93 ) ;
V_57 -> V_90 = V_94 ;
if ( F_79 ( V_57 ) ) {
V_92 = F_82 ( V_57 ) ;
F_21 ( V_57 , V_92 , F_56 ( V_92 ) ) ;
}
F_85 ( & V_57 -> V_93 ) ;
}
void F_86 ( struct V_2 * V_57 )
{
F_84 ( & V_57 -> V_93 ) ;
if ( F_79 ( V_57 ) )
F_83 ( V_57 ) ;
V_57 -> V_90 = V_95 ;
F_85 ( & V_57 -> V_93 ) ;
}
void F_87 ( struct V_2 * V_57 )
{
F_84 ( & V_57 -> V_93 ) ;
if ( F_79 ( V_57 ) )
F_83 ( V_57 ) ;
V_64 -> V_37 |= V_38 ;
F_85 ( & V_57 -> V_93 ) ;
}
void F_88 ( struct V_2 * V_57 )
{
F_84 ( & V_57 -> V_93 ) ;
F_83 ( V_57 ) ;
V_64 -> V_37 &= ~ V_38 ;
F_85 ( & V_57 -> V_93 ) ;
}
void F_60 ( struct V_2 * V_57 )
{
T_2 V_92 = F_82 ( V_57 ) ;
F_31 ( V_92 ) ;
}
void F_64 ( struct V_2 * V_75 )
{
F_84 ( & V_75 -> V_93 ) ;
V_75 -> V_90 = V_91 ;
F_85 ( & V_75 -> V_93 ) ;
F_84 ( & V_64 -> V_93 ) ;
V_64 -> V_90 = V_94 ;
V_64 -> V_89 = V_88 ;
F_85 ( & V_64 -> V_93 ) ;
}
void F_89 ( struct V_2 * V_51 , int V_7 )
{
unsigned long V_37 ;
F_90 ( V_37 ) ;
F_84 ( & V_51 -> V_93 ) ;
V_51 -> V_90 = V_94 ;
V_51 -> V_89 = V_88 ;
F_85 ( & V_51 -> V_93 ) ;
F_91 ( V_37 ) ;
}
T_2 F_92 ( struct V_2 * V_51 )
{
unsigned int V_62 ;
T_2 V_31 ;
if ( ! F_93 () )
return V_51 -> V_31 ;
do {
V_62 = F_94 ( & V_51 -> V_93 ) ;
V_31 = V_51 -> V_31 ;
if ( V_51 -> V_90 == V_94 && V_51 -> V_37 & V_38 )
V_31 += F_79 ( V_51 ) ;
} while ( F_95 ( & V_51 -> V_93 , V_62 ) );
return V_31 ;
}
static void
F_96 ( struct V_2 * V_51 ,
T_2 * V_96 , T_2 * V_97 ,
T_2 * V_98 , T_2 * V_99 ,
T_2 * V_100 , T_2 * V_101 )
{
unsigned int V_62 ;
unsigned long long V_6 ;
do {
* V_100 = 0 ;
* V_101 = 0 ;
V_62 = F_94 ( & V_51 -> V_93 ) ;
if ( V_96 )
* V_96 = * V_98 ;
if ( V_97 )
* V_97 = * V_99 ;
if ( V_51 -> V_90 == V_91 ||
F_59 ( V_51 ) )
continue;
V_6 = F_79 ( V_51 ) ;
if ( V_51 -> V_90 == V_95 || V_51 -> V_37 & V_38 ) {
* V_100 = V_6 ;
} else {
if ( V_51 -> V_90 == V_94 )
* V_101 = V_6 ;
}
} while ( F_95 ( & V_51 -> V_93 , V_62 ) );
}
void V_58 ( struct V_2 * V_51 , T_2 * V_26 , T_2 * V_34 )
{
T_2 V_100 , V_101 ;
if ( ! F_93 () ) {
if ( V_26 )
* V_26 = V_51 -> V_26 ;
if ( V_34 )
* V_34 = V_51 -> V_34 ;
return;
}
F_96 ( V_51 , V_26 , V_34 , & V_51 -> V_26 ,
& V_51 -> V_34 , & V_100 , & V_101 ) ;
if ( V_26 )
* V_26 += V_100 ;
if ( V_34 )
* V_34 += V_101 ;
}
void F_97 ( struct V_2 * V_51 ,
T_2 * V_27 , T_2 * V_35 )
{
T_2 V_100 , V_101 ;
if ( ! F_93 () ) {
if ( V_27 )
* V_27 = V_51 -> V_27 ;
if ( V_35 )
* V_35 = V_51 -> V_35 ;
return;
}
F_96 ( V_51 , V_27 , V_35 ,
& V_51 -> V_27 , & V_51 -> V_35 , & V_100 , & V_101 ) ;
if ( V_27 )
* V_27 += F_56 ( V_100 ) ;
if ( V_35 )
* V_35 += F_56 ( V_101 ) ;
}
