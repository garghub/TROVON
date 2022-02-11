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
void F_21 ( struct V_2 * V_20 , T_2 V_24 )
{
int V_21 ;
V_20 -> V_25 += V_24 ;
F_22 ( V_20 , V_24 ) ;
V_21 = ( F_23 ( V_20 ) > 0 ) ? V_26 : V_27 ;
F_18 ( V_20 , V_21 , ( V_28 T_3 ) V_24 ) ;
F_24 ( V_20 ) ;
}
static void F_25 ( struct V_2 * V_20 , T_2 V_24 )
{
T_3 * V_14 = V_15 -> V_14 ;
V_20 -> V_25 += V_24 ;
F_22 ( V_20 , V_24 ) ;
V_20 -> V_29 += V_24 ;
if ( F_23 ( V_20 ) > 0 ) {
V_14 [ V_26 ] += ( V_28 T_3 ) V_24 ;
V_14 [ V_30 ] += ( V_28 T_3 ) V_24 ;
} else {
V_14 [ V_27 ] += ( V_28 T_3 ) V_24 ;
V_14 [ V_31 ] += ( V_28 T_3 ) V_24 ;
}
}
static inline
void F_26 ( struct V_2 * V_20 , T_2 V_24 , int V_21 )
{
V_20 -> V_32 += V_24 ;
F_27 ( V_20 , V_24 ) ;
F_18 ( V_20 , V_21 , ( V_28 T_3 ) V_24 ) ;
F_24 ( V_20 ) ;
}
void F_28 ( struct V_2 * V_20 , int V_33 ,
T_2 V_24 )
{
int V_21 ;
if ( ( V_20 -> V_34 & V_35 ) && ( F_29 () - V_33 == 0 ) ) {
F_25 ( V_20 , V_24 ) ;
return;
}
if ( F_8 () - V_33 )
V_21 = V_17 ;
else if ( F_9 () )
V_21 = V_18 ;
else
V_21 = V_36 ;
F_26 ( V_20 , V_24 , V_21 ) ;
}
void F_30 ( T_2 V_24 )
{
T_3 * V_14 = V_15 -> V_14 ;
V_14 [ V_37 ] += ( V_28 T_3 ) V_24 ;
}
void F_31 ( T_2 V_24 )
{
T_3 * V_14 = V_15 -> V_14 ;
struct V_38 * V_38 = F_32 () ;
if ( F_33 ( & V_38 -> V_39 ) > 0 )
V_14 [ V_40 ] += ( V_28 T_3 ) V_24 ;
else
V_14 [ V_41 ] += ( V_28 T_3 ) V_24 ;
}
static T_4 T_2 F_34 ( T_2 V_13 )
{
#ifdef F_35
if ( F_36 ( & V_42 ) ) {
T_2 V_43 ;
T_3 V_44 ;
V_44 = F_37 ( F_5 () ) ;
V_44 -= F_32 () -> V_45 ;
V_43 = F_14 ( F_38 ( V_44 ) , V_13 ) ;
F_30 ( V_43 ) ;
F_32 () -> V_45 += F_39 ( V_43 ) ;
return V_43 ;
}
#endif
return 0 ;
}
static inline T_2 F_40 ( T_2 V_46 )
{
T_2 V_47 ;
F_41 ( ! F_42 () ) ;
V_47 = F_34 ( V_46 ) ;
if ( V_47 < V_46 )
V_47 += F_15 ( V_46 - V_47 ) ;
if ( V_47 < V_46 )
V_47 += F_17 ( V_46 - V_47 ) ;
return V_47 ;
}
static inline T_3 F_43 ( struct V_2 * V_48 )
{
return V_48 -> V_49 . V_50 ;
}
static T_3 F_43 ( struct V_2 * V_48 )
{
T_3 V_51 ;
struct V_52 V_53 ;
struct V_38 * V_38 ;
V_38 = F_44 ( V_48 , & V_53 ) ;
V_51 = V_48 -> V_49 . V_50 ;
F_45 ( V_38 , V_48 , & V_53 ) ;
return V_51 ;
}
void F_46 ( struct V_2 * V_54 , struct V_55 * V_56 )
{
struct V_57 * V_58 = V_54 -> signal ;
T_2 V_25 , V_32 ;
struct V_2 * V_48 ;
unsigned int V_59 , V_60 ;
unsigned long V_34 ;
if ( F_47 ( V_61 , V_54 ) )
( void ) F_48 ( V_61 ) ;
F_49 () ;
V_60 = 0 ;
do {
V_59 = V_60 ;
V_34 = F_50 ( & V_58 -> V_62 , & V_59 ) ;
V_56 -> V_25 = V_58 -> V_25 ;
V_56 -> V_32 = V_58 -> V_32 ;
V_56 -> V_50 = V_58 -> V_63 ;
F_51 (tsk, t) {
V_55 ( V_48 , & V_25 , & V_32 ) ;
V_56 -> V_25 += V_25 ;
V_56 -> V_32 += V_32 ;
V_56 -> V_50 += F_43 ( V_48 ) ;
}
V_60 = 1 ;
} while ( F_52 ( & V_58 -> V_62 , V_59 ) );
F_53 ( & V_58 -> V_62 , V_59 , V_34 ) ;
F_54 () ;
}
static void F_55 ( struct V_2 * V_20 , int V_64 ,
struct V_38 * V_38 , int V_65 )
{
T_3 V_24 = ( V_28 T_3 ) V_66 * V_65 ;
T_2 V_67 ;
V_67 = F_40 ( V_68 ) ;
if ( V_67 >= V_24 )
return;
V_24 -= V_67 ;
if ( F_10 () == V_20 ) {
F_26 ( V_20 , V_24 , V_18 ) ;
} else if ( V_64 ) {
F_21 ( V_20 , V_24 ) ;
} else if ( V_20 == V_38 -> V_69 ) {
F_31 ( V_24 ) ;
} else if ( V_20 -> V_34 & V_35 ) {
F_25 ( V_20 , V_24 ) ;
} else {
F_26 ( V_20 , V_24 , V_36 ) ;
}
}
static void F_56 ( int V_65 )
{
struct V_38 * V_38 = F_32 () ;
F_55 ( V_61 , 0 , V_38 , V_65 ) ;
}
static inline void F_56 ( int V_65 ) {}
static inline void F_55 ( struct V_2 * V_20 , int V_64 ,
struct V_38 * V_38 , int V_70 ) {}
void F_57 ( struct V_2 * V_71 )
{
if ( F_58 ( V_71 ) )
F_59 ( V_71 ) ;
else
F_60 ( V_71 ) ;
#ifdef F_61
F_62 ( V_71 ) ;
#endif
F_63 ( V_71 ) ;
}
void F_64 ( struct V_2 * V_54 )
{
if ( ! F_65 () && F_58 ( V_54 ) )
F_59 ( V_54 ) ;
else
F_60 ( V_54 ) ;
}
void F_66 ( struct V_2 * V_20 , T_2 * V_72 , T_2 * V_73 )
{
* V_72 = V_20 -> V_25 ;
* V_73 = V_20 -> V_32 ;
}
void F_67 ( struct V_2 * V_20 , T_2 * V_72 , T_2 * V_73 )
{
struct V_55 V_24 ;
F_46 ( V_20 , & V_24 ) ;
* V_72 = V_24 . V_25 ;
* V_73 = V_24 . V_32 ;
}
void F_68 ( struct V_2 * V_20 , int V_64 )
{
T_2 V_24 , V_44 ;
struct V_38 * V_38 = F_32 () ;
if ( F_69 () )
return;
if ( V_1 ) {
F_55 ( V_20 , V_64 , V_38 , 1 ) ;
return;
}
V_24 = V_66 ;
V_44 = F_34 ( V_68 ) ;
if ( V_44 >= V_24 )
return;
V_24 -= V_44 ;
if ( V_64 )
F_21 ( V_20 , V_24 ) ;
else if ( ( V_20 != V_38 -> V_69 ) || ( F_29 () != V_74 ) )
F_28 ( V_20 , V_74 , V_24 ) ;
else
F_31 ( V_24 ) ;
}
void F_70 ( unsigned long V_65 )
{
T_2 V_24 , V_44 ;
if ( V_1 ) {
F_56 ( V_65 ) ;
return;
}
V_24 = F_71 ( V_65 ) ;
V_44 = F_34 ( V_68 ) ;
if ( V_44 >= V_24 )
return;
V_24 -= V_44 ;
F_31 ( V_24 ) ;
}
static T_2 F_72 ( T_3 V_32 , T_3 V_75 , T_3 V_76 )
{
T_3 V_77 ;
for (; ; ) {
if ( V_32 > V_75 )
F_73 ( V_75 , V_32 ) ;
if ( V_76 >> 32 )
goto V_78;
if ( ! ( V_75 >> 32 ) )
break;
if ( V_32 >> 31 )
goto V_78;
V_32 <<= 1 ;
V_75 >>= 1 ;
continue;
V_78:
V_75 >>= 1 ;
V_76 >>= 1 ;
}
V_77 = F_74 ( ( T_3 ) ( V_79 ) V_32 * ( T_3 ) ( V_79 ) V_75 , ( V_79 ) V_76 ) ;
return ( V_28 T_2 ) V_77 ;
}
static void F_75 ( struct V_55 * V_3 ,
struct V_80 * V_71 ,
T_2 * V_72 , T_2 * V_73 )
{
T_2 V_75 , V_32 , V_25 ;
unsigned long V_34 ;
F_76 ( & V_71 -> V_81 , V_34 ) ;
V_75 = F_38 ( V_3 -> V_50 ) ;
if ( V_71 -> V_32 + V_71 -> V_25 >= V_75 )
goto V_82;
V_32 = V_3 -> V_32 ;
V_25 = V_3 -> V_25 ;
if ( V_32 == 0 ) {
V_25 = V_75 ;
goto V_83;
}
if ( V_25 == 0 ) {
V_32 = V_75 ;
goto V_83;
}
V_32 = F_72 ( ( V_28 T_3 ) V_32 , ( V_28 T_3 ) V_75 ,
( V_28 T_3 ) ( V_32 + V_25 ) ) ;
V_83:
if ( V_32 < V_71 -> V_32 )
V_32 = V_71 -> V_32 ;
V_25 = V_75 - V_32 ;
if ( V_25 < V_71 -> V_25 ) {
V_25 = V_71 -> V_25 ;
V_32 = V_75 - V_25 ;
}
V_71 -> V_32 = V_32 ;
V_71 -> V_25 = V_25 ;
V_82:
* V_72 = V_71 -> V_25 ;
* V_73 = V_71 -> V_32 ;
F_77 ( & V_71 -> V_81 , V_34 ) ;
}
void F_66 ( struct V_2 * V_20 , T_2 * V_72 , T_2 * V_73 )
{
struct V_55 V_24 = {
. V_50 = V_20 -> V_49 . V_50 ,
} ;
V_55 ( V_20 , & V_24 . V_25 , & V_24 . V_32 ) ;
F_75 ( & V_24 , & V_20 -> V_80 , V_72 , V_73 ) ;
}
void F_67 ( struct V_2 * V_20 , T_2 * V_72 , T_2 * V_73 )
{
struct V_55 V_24 ;
F_46 ( V_20 , & V_24 ) ;
F_75 ( & V_24 , & V_20 -> signal -> V_80 , V_72 , V_73 ) ;
}
static T_2 F_78 ( struct V_2 * V_54 )
{
unsigned long V_84 = F_79 ( V_85 ) ;
if ( F_80 ( V_84 , ( unsigned long ) V_54 -> V_86 ) )
return 0 ;
return F_71 ( V_84 - V_54 -> V_86 ) ;
}
static T_2 F_81 ( struct V_2 * V_54 )
{
unsigned long V_84 = F_79 ( V_85 ) ;
T_2 V_6 , V_67 ;
V_6 = F_71 ( V_84 - V_54 -> V_86 ) ;
V_67 = F_40 ( V_6 ) ;
F_41 ( V_54 -> V_87 == V_88 ) ;
V_54 -> V_86 = V_84 ;
return V_6 - V_67 ;
}
static void F_82 ( struct V_2 * V_54 )
{
T_2 V_89 = F_81 ( V_54 ) ;
F_28 ( V_54 , F_29 () , V_89 ) ;
}
void F_60 ( struct V_2 * V_54 )
{
if ( ! F_78 ( V_54 ) )
return;
F_83 ( & V_54 -> V_90 ) ;
F_82 ( V_54 ) ;
F_84 ( & V_54 -> V_90 ) ;
}
void F_62 ( struct V_2 * V_54 )
{
T_2 V_89 ;
F_83 ( & V_54 -> V_90 ) ;
V_54 -> V_87 = V_91 ;
if ( F_78 ( V_54 ) ) {
V_89 = F_81 ( V_54 ) ;
F_21 ( V_54 , V_89 ) ;
}
F_84 ( & V_54 -> V_90 ) ;
}
void F_85 ( struct V_2 * V_54 )
{
F_83 ( & V_54 -> V_90 ) ;
if ( F_78 ( V_54 ) )
F_82 ( V_54 ) ;
V_54 -> V_87 = V_92 ;
F_84 ( & V_54 -> V_90 ) ;
}
void F_86 ( struct V_2 * V_54 )
{
F_83 ( & V_54 -> V_90 ) ;
if ( F_78 ( V_54 ) )
F_82 ( V_54 ) ;
V_61 -> V_34 |= V_35 ;
F_84 ( & V_54 -> V_90 ) ;
}
void F_87 ( struct V_2 * V_54 )
{
F_83 ( & V_54 -> V_90 ) ;
F_82 ( V_54 ) ;
V_61 -> V_34 &= ~ V_35 ;
F_84 ( & V_54 -> V_90 ) ;
}
void F_59 ( struct V_2 * V_54 )
{
T_2 V_89 = F_81 ( V_54 ) ;
F_31 ( V_89 ) ;
}
void F_63 ( struct V_2 * V_71 )
{
F_83 ( & V_71 -> V_90 ) ;
V_71 -> V_87 = V_88 ;
F_84 ( & V_71 -> V_90 ) ;
F_83 ( & V_61 -> V_90 ) ;
V_61 -> V_87 = V_91 ;
V_61 -> V_86 = V_85 ;
F_84 ( & V_61 -> V_90 ) ;
}
void F_88 ( struct V_2 * V_48 , int V_7 )
{
unsigned long V_34 ;
F_89 ( V_34 ) ;
F_83 ( & V_48 -> V_90 ) ;
V_48 -> V_87 = V_91 ;
V_48 -> V_86 = V_85 ;
F_84 ( & V_48 -> V_90 ) ;
F_90 ( V_34 ) ;
}
T_2 F_91 ( struct V_2 * V_48 )
{
unsigned int V_59 ;
T_2 V_29 ;
if ( ! F_92 () )
return V_48 -> V_29 ;
do {
V_59 = F_93 ( & V_48 -> V_90 ) ;
V_29 = V_48 -> V_29 ;
if ( V_48 -> V_87 == V_91 && V_48 -> V_34 & V_35 )
V_29 += F_78 ( V_48 ) ;
} while ( F_94 ( & V_48 -> V_90 , V_59 ) );
return V_29 ;
}
void V_55 ( struct V_2 * V_48 , T_2 * V_25 , T_2 * V_32 )
{
T_2 V_6 ;
unsigned int V_59 ;
if ( ! F_92 () ) {
* V_25 = V_48 -> V_25 ;
* V_32 = V_48 -> V_32 ;
return;
}
do {
V_59 = F_93 ( & V_48 -> V_90 ) ;
* V_25 = V_48 -> V_25 ;
* V_32 = V_48 -> V_32 ;
if ( V_48 -> V_87 == V_88 || F_58 ( V_48 ) )
continue;
V_6 = F_78 ( V_48 ) ;
if ( V_48 -> V_87 == V_92 || V_48 -> V_34 & V_35 )
* V_25 += V_6 ;
else if ( V_48 -> V_87 == V_91 )
* V_32 += V_6 ;
} while ( F_94 ( & V_48 -> V_90 , V_59 ) );
}
