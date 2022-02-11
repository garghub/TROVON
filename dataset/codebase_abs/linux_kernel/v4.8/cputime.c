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
T_1 V_4 ;
int V_5 ;
if ( ! V_1 )
return;
V_5 = F_4 () ;
V_4 = F_5 ( V_5 ) - F_6 ( V_6 ) ;
F_7 ( V_6 , V_4 ) ;
F_8 () ;
if ( F_9 () )
F_7 ( V_7 , V_4 ) ;
else if ( F_10 () && V_3 != F_11 () )
F_7 ( V_8 , V_4 ) ;
F_12 () ;
}
static T_2 F_13 ( T_2 V_9 )
{
T_3 * V_10 = V_11 -> V_10 ;
unsigned long V_12 ;
T_2 V_13 ;
F_14 ( V_12 ) ;
V_13 = F_15 ( F_16 ( V_7 ) ) -
V_10 [ V_14 ] ;
V_13 = F_17 ( V_13 , V_9 ) ;
V_10 [ V_14 ] += V_13 ;
F_18 ( V_12 ) ;
return V_13 ;
}
static T_2 F_19 ( T_2 V_9 )
{
T_3 * V_10 = V_11 -> V_10 ;
unsigned long V_12 ;
T_2 V_15 ;
F_14 ( V_12 ) ;
V_15 = F_15 ( F_16 ( V_8 ) ) -
V_10 [ V_16 ] ;
V_15 = F_17 ( V_15 , V_9 ) ;
V_10 [ V_16 ] += V_15 ;
F_18 ( V_12 ) ;
return V_15 ;
}
static T_2 F_13 ( T_2 V_17 )
{
return 0 ;
}
static T_2 F_19 ( T_2 V_17 )
{
return 0 ;
}
static inline void F_20 ( struct V_2 * V_18 , int V_19 ,
T_3 V_20 )
{
F_7 ( V_21 . V_10 [ V_19 ] , V_20 ) ;
F_21 ( V_18 , V_19 , V_20 ) ;
}
void F_22 ( struct V_2 * V_18 , T_2 V_22 ,
T_2 V_23 )
{
int V_19 ;
V_18 -> V_24 += V_22 ;
V_18 -> V_25 += V_23 ;
F_23 ( V_18 , V_22 ) ;
V_19 = ( F_24 ( V_18 ) > 0 ) ? V_26 : V_27 ;
F_20 ( V_18 , V_19 , ( V_28 T_3 ) V_22 ) ;
F_25 ( V_18 ) ;
}
static void F_26 ( struct V_2 * V_18 , T_2 V_22 ,
T_2 V_23 )
{
T_3 * V_10 = V_11 -> V_10 ;
V_18 -> V_24 += V_22 ;
V_18 -> V_25 += V_23 ;
F_23 ( V_18 , V_22 ) ;
V_18 -> V_29 += V_22 ;
if ( F_24 ( V_18 ) > 0 ) {
V_10 [ V_26 ] += ( V_28 T_3 ) V_22 ;
V_10 [ V_30 ] += ( V_28 T_3 ) V_22 ;
} else {
V_10 [ V_27 ] += ( V_28 T_3 ) V_22 ;
V_10 [ V_31 ] += ( V_28 T_3 ) V_22 ;
}
}
static inline
void F_27 ( struct V_2 * V_18 , T_2 V_22 ,
T_2 V_23 , int V_19 )
{
V_18 -> V_32 += V_22 ;
V_18 -> V_33 += V_23 ;
F_28 ( V_18 , V_22 ) ;
F_20 ( V_18 , V_19 , ( V_28 T_3 ) V_22 ) ;
F_25 ( V_18 ) ;
}
void F_29 ( struct V_2 * V_18 , int V_34 ,
T_2 V_22 , T_2 V_23 )
{
int V_19 ;
if ( ( V_18 -> V_12 & V_35 ) && ( F_30 () - V_34 == 0 ) ) {
F_26 ( V_18 , V_22 , V_23 ) ;
return;
}
if ( F_9 () - V_34 )
V_19 = V_14 ;
else if ( F_10 () )
V_19 = V_16 ;
else
V_19 = V_36 ;
F_27 ( V_18 , V_22 , V_23 , V_19 ) ;
}
void F_31 ( T_2 V_22 )
{
T_3 * V_10 = V_11 -> V_10 ;
V_10 [ V_37 ] += ( V_28 T_3 ) V_22 ;
}
void F_32 ( T_2 V_22 )
{
T_3 * V_10 = V_11 -> V_10 ;
struct V_38 * V_38 = F_33 () ;
if ( F_34 ( & V_38 -> V_39 ) > 0 )
V_10 [ V_40 ] += ( V_28 T_3 ) V_22 ;
else
V_10 [ V_41 ] += ( V_28 T_3 ) V_22 ;
}
static T_4 T_2 F_35 ( T_2 V_9 )
{
#ifdef F_36
if ( F_37 ( & V_42 ) ) {
T_2 V_43 ;
T_3 V_44 ;
V_44 = F_38 ( F_4 () ) ;
V_44 -= F_33 () -> V_45 ;
V_43 = F_17 ( F_39 ( V_44 ) , V_9 ) ;
F_31 ( V_43 ) ;
F_33 () -> V_45 += F_40 ( V_43 ) ;
return V_43 ;
}
#endif
return 0 ;
}
static inline T_2 F_41 ( T_2 V_46 )
{
T_2 V_47 ;
V_47 = F_35 ( V_46 ) ;
if ( V_47 < V_46 )
V_47 += F_13 ( V_46 - V_47 ) ;
if ( V_47 < V_46 )
V_47 += F_19 ( V_46 - V_47 ) ;
return V_47 ;
}
void F_42 ( struct V_2 * V_48 , struct V_49 * V_50 )
{
struct V_51 * V_52 = V_48 -> signal ;
T_2 V_24 , V_32 ;
struct V_2 * V_53 ;
unsigned int V_54 , V_55 ;
unsigned long V_12 ;
F_43 () ;
V_55 = 0 ;
do {
V_54 = V_55 ;
V_12 = F_44 ( & V_52 -> V_56 , & V_54 ) ;
V_50 -> V_24 = V_52 -> V_24 ;
V_50 -> V_32 = V_52 -> V_32 ;
V_50 -> V_57 = V_52 -> V_58 ;
F_45 (tsk, t) {
V_49 ( V_53 , & V_24 , & V_32 ) ;
V_50 -> V_24 += V_24 ;
V_50 -> V_32 += V_32 ;
V_50 -> V_57 += F_46 ( V_53 ) ;
}
V_55 = 1 ;
} while ( F_47 ( & V_52 -> V_56 , V_54 ) );
F_48 ( & V_52 -> V_56 , V_54 , V_12 ) ;
F_49 () ;
}
static void F_50 ( struct V_2 * V_18 , int V_59 ,
struct V_38 * V_38 , int V_60 )
{
T_3 V_22 = ( V_28 T_3 ) V_61 * V_60 ;
T_2 V_62 , V_63 ;
V_63 = F_41 ( V_64 ) ;
if ( V_63 >= V_22 )
return;
V_22 -= V_63 ;
V_62 = F_51 ( V_22 ) ;
if ( F_11 () == V_18 ) {
F_27 ( V_18 , V_22 , V_62 , V_16 ) ;
} else if ( V_59 ) {
F_22 ( V_18 , V_22 , V_62 ) ;
} else if ( V_18 == V_38 -> V_65 ) {
F_32 ( V_22 ) ;
} else if ( V_18 -> V_12 & V_35 ) {
F_26 ( V_18 , V_22 , V_62 ) ;
} else {
F_27 ( V_18 , V_22 , V_62 , V_36 ) ;
}
}
static void F_52 ( int V_60 )
{
struct V_38 * V_38 = F_33 () ;
F_50 ( V_66 , 0 , V_38 , V_60 ) ;
}
static inline void F_52 ( int V_60 ) {}
static inline void F_50 ( struct V_2 * V_18 , int V_59 ,
struct V_38 * V_38 , int V_67 ) {}
void F_53 ( struct V_2 * V_68 )
{
if ( F_54 ( V_68 ) )
F_55 ( V_68 ) ;
else
F_56 ( V_68 ) ;
#ifdef F_57
F_58 ( V_68 ) ;
#endif
F_59 ( V_68 ) ;
}
void F_60 ( struct V_2 * V_48 )
{
if ( ! F_61 () && F_54 ( V_48 ) )
F_55 ( V_48 ) ;
else
F_56 ( V_48 ) ;
}
void F_62 ( struct V_2 * V_18 , T_2 * V_69 , T_2 * V_70 )
{
* V_69 = V_18 -> V_24 ;
* V_70 = V_18 -> V_32 ;
}
void F_63 ( struct V_2 * V_18 , T_2 * V_69 , T_2 * V_70 )
{
struct V_49 V_22 ;
F_42 ( V_18 , & V_22 ) ;
* V_69 = V_22 . V_24 ;
* V_70 = V_22 . V_32 ;
}
void F_64 ( struct V_2 * V_18 , int V_59 )
{
T_2 V_22 , V_62 , V_44 ;
struct V_38 * V_38 = F_33 () ;
if ( F_65 () )
return;
if ( V_1 ) {
F_50 ( V_18 , V_59 , V_38 , 1 ) ;
return;
}
V_22 = V_61 ;
V_44 = F_35 ( V_64 ) ;
if ( V_44 >= V_22 )
return;
V_22 -= V_44 ;
V_62 = F_51 ( V_22 ) ;
if ( V_59 )
F_22 ( V_18 , V_22 , V_62 ) ;
else if ( ( V_18 != V_38 -> V_65 ) || ( F_30 () != V_71 ) )
F_29 ( V_18 , V_71 , V_22 , V_62 ) ;
else
F_32 ( V_22 ) ;
}
void F_66 ( unsigned long V_60 )
{
T_2 V_22 , V_44 ;
if ( V_1 ) {
F_52 ( V_60 ) ;
return;
}
V_22 = F_67 ( V_60 ) ;
V_44 = F_35 ( V_64 ) ;
if ( V_44 >= V_22 )
return;
V_22 -= V_44 ;
F_32 ( V_22 ) ;
}
static T_2 F_68 ( T_3 V_32 , T_3 V_72 , T_3 V_73 )
{
T_3 V_62 ;
for (; ; ) {
if ( V_32 > V_72 )
F_69 ( V_72 , V_32 ) ;
if ( V_73 >> 32 )
goto V_74;
if ( ! ( V_72 >> 32 ) )
break;
if ( V_32 >> 31 )
goto V_74;
V_32 <<= 1 ;
V_72 >>= 1 ;
continue;
V_74:
V_72 >>= 1 ;
V_73 >>= 1 ;
}
V_62 = F_70 ( ( T_3 ) ( V_75 ) V_32 * ( T_3 ) ( V_75 ) V_72 , ( V_75 ) V_73 ) ;
return ( V_28 T_2 ) V_62 ;
}
static void F_71 ( struct V_49 * V_3 ,
struct V_76 * V_68 ,
T_2 * V_69 , T_2 * V_70 )
{
T_2 V_72 , V_32 , V_24 ;
unsigned long V_12 ;
F_72 ( & V_68 -> V_77 , V_12 ) ;
V_72 = F_39 ( V_3 -> V_57 ) ;
if ( V_68 -> V_32 + V_68 -> V_24 >= V_72 )
goto V_78;
V_32 = V_3 -> V_32 ;
V_24 = V_3 -> V_24 ;
if ( V_32 == 0 ) {
V_24 = V_72 ;
goto V_79;
}
if ( V_24 == 0 ) {
V_32 = V_72 ;
goto V_79;
}
V_32 = F_68 ( ( V_28 T_3 ) V_32 , ( V_28 T_3 ) V_72 ,
( V_28 T_3 ) ( V_32 + V_24 ) ) ;
V_79:
if ( V_32 < V_68 -> V_32 )
V_32 = V_68 -> V_32 ;
V_24 = V_72 - V_32 ;
if ( V_24 < V_68 -> V_24 ) {
V_24 = V_68 -> V_24 ;
V_32 = V_72 - V_24 ;
}
V_68 -> V_32 = V_32 ;
V_68 -> V_24 = V_24 ;
V_78:
* V_69 = V_68 -> V_24 ;
* V_70 = V_68 -> V_32 ;
F_73 ( & V_68 -> V_77 , V_12 ) ;
}
void F_62 ( struct V_2 * V_18 , T_2 * V_69 , T_2 * V_70 )
{
struct V_49 V_22 = {
. V_57 = V_18 -> V_80 . V_57 ,
} ;
V_49 ( V_18 , & V_22 . V_24 , & V_22 . V_32 ) ;
F_71 ( & V_22 , & V_18 -> V_76 , V_69 , V_70 ) ;
}
void F_63 ( struct V_2 * V_18 , T_2 * V_69 , T_2 * V_70 )
{
struct V_49 V_22 ;
F_42 ( V_18 , & V_22 ) ;
F_71 ( & V_22 , & V_18 -> signal -> V_76 , V_69 , V_70 ) ;
}
static T_2 F_74 ( struct V_2 * V_48 )
{
unsigned long V_81 = F_75 ( V_82 ) ;
if ( F_76 ( V_81 , ( unsigned long ) V_48 -> V_83 ) )
return 0 ;
return F_67 ( V_81 - V_48 -> V_83 ) ;
}
static T_2 F_77 ( struct V_2 * V_48 )
{
unsigned long V_81 = F_75 ( V_82 ) ;
T_2 V_4 , V_63 ;
V_4 = F_67 ( V_81 - V_48 -> V_83 ) ;
V_63 = F_41 ( V_4 ) ;
F_78 ( V_48 -> V_84 == V_85 ) ;
V_48 -> V_83 = V_81 ;
return V_4 - V_63 ;
}
static void F_79 ( struct V_2 * V_48 )
{
T_2 V_86 = F_77 ( V_48 ) ;
F_29 ( V_48 , F_30 () , V_86 , F_51 ( V_86 ) ) ;
}
void F_56 ( struct V_2 * V_48 )
{
if ( ! F_74 ( V_48 ) )
return;
F_80 ( & V_48 -> V_87 ) ;
F_79 ( V_48 ) ;
F_81 ( & V_48 -> V_87 ) ;
}
void F_58 ( struct V_2 * V_48 )
{
T_2 V_86 ;
F_80 ( & V_48 -> V_87 ) ;
V_48 -> V_84 = V_88 ;
if ( F_74 ( V_48 ) ) {
V_86 = F_77 ( V_48 ) ;
F_22 ( V_48 , V_86 , F_51 ( V_86 ) ) ;
}
F_81 ( & V_48 -> V_87 ) ;
}
void F_82 ( struct V_2 * V_48 )
{
F_80 ( & V_48 -> V_87 ) ;
if ( F_74 ( V_48 ) )
F_79 ( V_48 ) ;
V_48 -> V_84 = V_89 ;
F_81 ( & V_48 -> V_87 ) ;
}
void F_83 ( struct V_2 * V_48 )
{
F_80 ( & V_48 -> V_87 ) ;
if ( F_74 ( V_48 ) )
F_79 ( V_48 ) ;
V_66 -> V_12 |= V_35 ;
F_81 ( & V_48 -> V_87 ) ;
}
void F_84 ( struct V_2 * V_48 )
{
F_80 ( & V_48 -> V_87 ) ;
F_79 ( V_48 ) ;
V_66 -> V_12 &= ~ V_35 ;
F_81 ( & V_48 -> V_87 ) ;
}
void F_55 ( struct V_2 * V_48 )
{
T_2 V_86 = F_77 ( V_48 ) ;
F_32 ( V_86 ) ;
}
void F_59 ( struct V_2 * V_68 )
{
F_80 ( & V_68 -> V_87 ) ;
V_68 -> V_84 = V_85 ;
F_81 ( & V_68 -> V_87 ) ;
F_80 ( & V_66 -> V_87 ) ;
V_66 -> V_84 = V_88 ;
V_66 -> V_83 = V_82 ;
F_81 ( & V_66 -> V_87 ) ;
}
void F_85 ( struct V_2 * V_53 , int V_5 )
{
unsigned long V_12 ;
F_14 ( V_12 ) ;
F_80 ( & V_53 -> V_87 ) ;
V_53 -> V_84 = V_88 ;
V_53 -> V_83 = V_82 ;
F_81 ( & V_53 -> V_87 ) ;
F_18 ( V_12 ) ;
}
T_2 F_86 ( struct V_2 * V_53 )
{
unsigned int V_54 ;
T_2 V_29 ;
if ( ! F_87 () )
return V_53 -> V_29 ;
do {
V_54 = F_88 ( & V_53 -> V_87 ) ;
V_29 = V_53 -> V_29 ;
if ( V_53 -> V_84 == V_88 && V_53 -> V_12 & V_35 )
V_29 += F_74 ( V_53 ) ;
} while ( F_89 ( & V_53 -> V_87 , V_54 ) );
return V_29 ;
}
static void
F_90 ( struct V_2 * V_53 ,
T_2 * V_90 , T_2 * V_91 ,
T_2 * V_92 , T_2 * V_93 ,
T_2 * V_94 , T_2 * V_95 )
{
unsigned int V_54 ;
unsigned long long V_4 ;
do {
* V_94 = 0 ;
* V_95 = 0 ;
V_54 = F_88 ( & V_53 -> V_87 ) ;
if ( V_90 )
* V_90 = * V_92 ;
if ( V_91 )
* V_91 = * V_93 ;
if ( V_53 -> V_84 == V_85 ||
F_54 ( V_53 ) )
continue;
V_4 = F_74 ( V_53 ) ;
if ( V_53 -> V_84 == V_89 || V_53 -> V_12 & V_35 ) {
* V_94 = V_4 ;
} else {
if ( V_53 -> V_84 == V_88 )
* V_95 = V_4 ;
}
} while ( F_89 ( & V_53 -> V_87 , V_54 ) );
}
void V_49 ( struct V_2 * V_53 , T_2 * V_24 , T_2 * V_32 )
{
T_2 V_94 , V_95 ;
if ( ! F_87 () ) {
if ( V_24 )
* V_24 = V_53 -> V_24 ;
if ( V_32 )
* V_32 = V_53 -> V_32 ;
return;
}
F_90 ( V_53 , V_24 , V_32 , & V_53 -> V_24 ,
& V_53 -> V_32 , & V_94 , & V_95 ) ;
if ( V_24 )
* V_24 += V_94 ;
if ( V_32 )
* V_32 += V_95 ;
}
void F_91 ( struct V_2 * V_53 ,
T_2 * V_25 , T_2 * V_33 )
{
T_2 V_94 , V_95 ;
if ( ! F_87 () ) {
if ( V_25 )
* V_25 = V_53 -> V_25 ;
if ( V_33 )
* V_33 = V_53 -> V_33 ;
return;
}
F_90 ( V_53 , V_25 , V_33 ,
& V_53 -> V_25 , & V_53 -> V_33 , & V_94 , & V_95 ) ;
if ( V_25 )
* V_25 += F_51 ( V_94 ) ;
if ( V_33 )
* V_33 += F_51 ( V_95 ) ;
}
