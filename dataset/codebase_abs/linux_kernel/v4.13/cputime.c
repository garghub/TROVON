void F_1 ( void )
{
V_1 = 1 ;
}
void F_2 ( void )
{
V_1 = 0 ;
}
static void F_3 ( struct V_2 * V_2 , T_1 V_3 ,
enum V_4 V_5 )
{
T_1 * V_6 = V_7 -> V_6 ;
F_4 ( & V_2 -> V_8 ) ;
V_6 [ V_5 ] += V_3 ;
V_2 -> V_9 += V_3 ;
V_2 -> V_10 += V_3 ;
F_5 ( & V_2 -> V_8 ) ;
}
void F_6 ( struct V_11 * V_12 )
{
struct V_2 * V_2 = F_7 ( & V_13 ) ;
T_2 V_3 ;
int V_14 ;
if ( ! V_1 )
return;
V_14 = F_8 () ;
V_3 = F_9 ( V_14 ) - V_2 -> V_15 ;
V_2 -> V_15 += V_3 ;
if ( F_10 () )
F_3 ( V_2 , V_3 , V_16 ) ;
else if ( F_11 () && V_12 != F_12 () )
F_3 ( V_2 , V_3 , V_17 ) ;
}
static T_1 F_13 ( T_1 V_18 )
{
struct V_2 * V_2 = F_7 ( & V_13 ) ;
T_1 V_3 ;
V_3 = F_14 ( V_2 -> V_10 , V_18 ) ;
V_2 -> V_10 -= V_3 ;
return V_3 ;
}
static T_1 F_13 ( T_1 V_19 )
{
return 0 ;
}
static inline void F_15 ( struct V_11 * V_20 , int V_21 ,
T_1 V_22 )
{
F_16 ( V_23 . V_6 [ V_21 ] , V_22 ) ;
F_17 ( V_20 , V_21 , V_22 ) ;
}
void F_18 ( struct V_11 * V_20 , T_1 V_24 )
{
int V_21 ;
V_20 -> V_25 += V_24 ;
F_19 ( V_20 , V_24 ) ;
V_21 = ( F_20 ( V_20 ) > 0 ) ? V_26 : V_27 ;
F_15 ( V_20 , V_21 , V_24 ) ;
F_21 ( V_20 ) ;
}
void F_22 ( struct V_11 * V_20 , T_1 V_24 )
{
T_1 * V_6 = V_7 -> V_6 ;
V_20 -> V_25 += V_24 ;
F_19 ( V_20 , V_24 ) ;
V_20 -> V_28 += V_24 ;
if ( F_20 ( V_20 ) > 0 ) {
V_6 [ V_26 ] += V_24 ;
V_6 [ V_29 ] += V_24 ;
} else {
V_6 [ V_27 ] += V_24 ;
V_6 [ V_30 ] += V_24 ;
}
}
void F_23 ( struct V_11 * V_20 ,
T_1 V_24 , enum V_4 V_21 )
{
V_20 -> V_31 += V_24 ;
F_24 ( V_20 , V_24 ) ;
F_15 ( V_20 , V_21 , V_24 ) ;
F_21 ( V_20 ) ;
}
void F_25 ( struct V_11 * V_20 , int V_32 , T_1 V_24 )
{
int V_21 ;
if ( ( V_20 -> V_33 & V_34 ) && ( F_26 () - V_32 == 0 ) ) {
F_22 ( V_20 , V_24 ) ;
return;
}
if ( F_10 () - V_32 )
V_21 = V_16 ;
else if ( F_11 () )
V_21 = V_17 ;
else
V_21 = V_35 ;
F_23 ( V_20 , V_24 , V_21 ) ;
}
void F_27 ( T_1 V_24 )
{
T_1 * V_6 = V_7 -> V_6 ;
V_6 [ V_36 ] += V_24 ;
}
void F_28 ( T_1 V_24 )
{
T_1 * V_6 = V_7 -> V_6 ;
struct V_37 * V_37 = F_29 () ;
if ( F_30 ( & V_37 -> V_38 ) > 0 )
V_6 [ V_39 ] += V_24 ;
else
V_6 [ V_40 ] += V_24 ;
}
static T_3 T_1 F_31 ( T_1 V_18 )
{
#ifdef F_32
if ( F_33 ( & V_41 ) ) {
T_1 V_42 ;
V_42 = F_34 ( F_8 () ) ;
V_42 -= F_29 () -> V_43 ;
V_42 = F_14 ( V_42 , V_18 ) ;
F_27 ( V_42 ) ;
F_29 () -> V_43 += V_42 ;
return V_42 ;
}
#endif
return 0 ;
}
static inline T_1 F_35 ( T_1 V_44 )
{
T_1 V_45 ;
F_36 ( ! F_37 () ) ;
V_45 = F_31 ( V_44 ) ;
if ( V_45 < V_44 )
V_45 += F_13 ( V_44 - V_45 ) ;
return V_45 ;
}
static inline T_1 F_38 ( struct V_11 * V_46 )
{
return V_46 -> V_47 . V_48 ;
}
static T_1 F_38 ( struct V_11 * V_46 )
{
T_1 V_49 ;
struct V_50 V_51 ;
struct V_37 * V_37 ;
V_37 = F_39 ( V_46 , & V_51 ) ;
V_49 = V_46 -> V_47 . V_48 ;
F_40 ( V_37 , V_46 , & V_51 ) ;
return V_49 ;
}
void F_41 ( struct V_11 * V_52 , struct V_53 * V_54 )
{
struct V_55 * V_56 = V_52 -> signal ;
T_1 V_25 , V_31 ;
struct V_11 * V_46 ;
unsigned int V_57 , V_58 ;
unsigned long V_33 ;
if ( F_42 ( V_59 , V_52 ) )
( void ) F_43 ( V_59 ) ;
F_44 () ;
V_58 = 0 ;
do {
V_57 = V_58 ;
V_33 = F_45 ( & V_56 -> V_60 , & V_57 ) ;
V_54 -> V_25 = V_56 -> V_25 ;
V_54 -> V_31 = V_56 -> V_31 ;
V_54 -> V_48 = V_56 -> V_61 ;
F_46 (tsk, t) {
V_53 ( V_46 , & V_25 , & V_31 ) ;
V_54 -> V_25 += V_25 ;
V_54 -> V_31 += V_31 ;
V_54 -> V_48 += F_38 ( V_46 ) ;
}
V_58 = 1 ;
} while ( F_47 ( & V_56 -> V_60 , V_57 ) );
F_48 ( & V_56 -> V_60 , V_57 , V_33 ) ;
F_49 () ;
}
static void F_50 ( struct V_11 * V_20 , int V_62 ,
struct V_37 * V_37 , int V_63 )
{
T_1 V_64 , V_24 = V_65 * V_63 ;
V_64 = F_35 ( V_66 ) ;
if ( V_64 >= V_24 )
return;
V_24 -= V_64 ;
if ( F_12 () == V_20 ) {
F_23 ( V_20 , V_24 , V_17 ) ;
} else if ( V_62 ) {
F_18 ( V_20 , V_24 ) ;
} else if ( V_20 == V_37 -> V_67 ) {
F_28 ( V_24 ) ;
} else if ( V_20 -> V_33 & V_34 ) {
F_22 ( V_20 , V_24 ) ;
} else {
F_23 ( V_20 , V_24 , V_35 ) ;
}
}
static void F_51 ( int V_63 )
{
struct V_37 * V_37 = F_29 () ;
F_50 ( V_59 , 0 , V_37 , V_63 ) ;
}
static inline void F_51 ( int V_63 ) {}
static inline void F_50 ( struct V_11 * V_20 , int V_62 ,
struct V_37 * V_37 , int V_68 ) {}
void F_52 ( struct V_11 * V_69 )
{
if ( F_53 ( V_69 ) )
F_54 ( V_69 ) ;
else
F_55 ( V_69 ) ;
F_56 ( V_69 ) ;
F_57 ( V_69 ) ;
}
void F_58 ( struct V_11 * V_52 )
{
if ( ! F_59 () && F_53 ( V_52 ) )
F_54 ( V_52 ) ;
else
F_55 ( V_52 ) ;
}
void F_60 ( struct V_11 * V_20 , T_1 * V_70 , T_1 * V_71 )
{
* V_70 = V_20 -> V_25 ;
* V_71 = V_20 -> V_31 ;
}
void F_61 ( struct V_11 * V_20 , T_1 * V_70 , T_1 * V_71 )
{
struct V_53 V_24 ;
F_41 ( V_20 , & V_24 ) ;
* V_70 = V_24 . V_25 ;
* V_71 = V_24 . V_31 ;
}
void F_62 ( struct V_11 * V_20 , int V_62 )
{
T_1 V_24 , V_42 ;
struct V_37 * V_37 = F_29 () ;
if ( F_63 () )
return;
if ( V_1 ) {
F_50 ( V_20 , V_62 , V_37 , 1 ) ;
return;
}
V_24 = V_65 ;
V_42 = F_31 ( V_66 ) ;
if ( V_42 >= V_24 )
return;
V_24 -= V_42 ;
if ( V_62 )
F_18 ( V_20 , V_24 ) ;
else if ( ( V_20 != V_37 -> V_67 ) || ( F_26 () != V_72 ) )
F_25 ( V_20 , V_72 , V_24 ) ;
else
F_28 ( V_24 ) ;
}
void F_64 ( unsigned long V_63 )
{
T_1 V_24 , V_42 ;
if ( V_1 ) {
F_51 ( V_63 ) ;
return;
}
V_24 = V_63 * V_65 ;
V_42 = F_31 ( V_66 ) ;
if ( V_42 >= V_24 )
return;
V_24 -= V_42 ;
F_28 ( V_24 ) ;
}
static T_1 F_65 ( T_1 V_31 , T_1 V_73 , T_1 V_9 )
{
T_1 V_74 ;
for (; ; ) {
if ( V_31 > V_73 )
F_66 ( V_73 , V_31 ) ;
if ( V_9 >> 32 )
goto V_75;
if ( ! ( V_73 >> 32 ) )
break;
if ( V_31 >> 31 )
goto V_75;
V_31 <<= 1 ;
V_73 >>= 1 ;
continue;
V_75:
V_73 >>= 1 ;
V_9 >>= 1 ;
}
V_74 = F_67 ( ( T_1 ) ( V_76 ) V_31 * ( T_1 ) ( V_76 ) V_73 , ( V_76 ) V_9 ) ;
return V_74 ;
}
static void F_68 ( struct V_53 * V_12 ,
struct V_77 * V_69 ,
T_1 * V_70 , T_1 * V_71 )
{
T_1 V_73 , V_31 , V_25 ;
unsigned long V_33 ;
F_69 ( & V_69 -> V_78 , V_33 ) ;
V_73 = V_12 -> V_48 ;
if ( V_69 -> V_31 + V_69 -> V_25 >= V_73 )
goto V_79;
V_31 = V_12 -> V_31 ;
V_25 = V_12 -> V_25 ;
if ( V_31 == 0 ) {
V_25 = V_73 ;
goto V_80;
}
if ( V_25 == 0 ) {
V_31 = V_73 ;
goto V_80;
}
V_31 = F_65 ( V_31 , V_73 , V_31 + V_25 ) ;
V_80:
if ( V_31 < V_69 -> V_31 )
V_31 = V_69 -> V_31 ;
V_25 = V_73 - V_31 ;
if ( V_25 < V_69 -> V_25 ) {
V_25 = V_69 -> V_25 ;
V_31 = V_73 - V_25 ;
}
V_69 -> V_31 = V_31 ;
V_69 -> V_25 = V_25 ;
V_79:
* V_70 = V_69 -> V_25 ;
* V_71 = V_69 -> V_31 ;
F_70 ( & V_69 -> V_78 , V_33 ) ;
}
void F_60 ( struct V_11 * V_20 , T_1 * V_70 , T_1 * V_71 )
{
struct V_53 V_24 = {
. V_48 = V_20 -> V_47 . V_48 ,
} ;
V_53 ( V_20 , & V_24 . V_25 , & V_24 . V_31 ) ;
F_68 ( & V_24 , & V_20 -> V_77 , V_70 , V_71 ) ;
}
void F_61 ( struct V_11 * V_20 , T_1 * V_70 , T_1 * V_71 )
{
struct V_53 V_24 ;
F_41 ( V_20 , & V_24 ) ;
F_68 ( & V_24 , & V_20 -> signal -> V_77 , V_70 , V_71 ) ;
}
static T_1 F_71 ( struct V_81 * V_81 )
{
unsigned long long clock ;
clock = F_72 () ;
if ( clock < V_81 -> V_82 )
return 0 ;
return clock - V_81 -> V_82 ;
}
static T_1 F_73 ( struct V_81 * V_81 )
{
T_1 V_3 = F_71 ( V_81 ) ;
T_1 V_64 ;
V_64 = F_35 ( V_3 ) ;
F_36 ( V_81 -> V_83 == V_84 ) ;
V_81 -> V_82 += V_3 ;
return V_3 - V_64 ;
}
static void F_74 ( struct V_11 * V_52 ,
struct V_81 * V_81 )
{
V_81 -> V_31 += F_73 ( V_81 ) ;
if ( V_81 -> V_31 >= V_65 ) {
F_25 ( V_52 , F_26 () , V_81 -> V_31 ) ;
V_81 -> V_31 = 0 ;
}
}
static void F_75 ( struct V_11 * V_52 ,
struct V_81 * V_81 )
{
V_81 -> V_28 += F_73 ( V_81 ) ;
if ( V_81 -> V_28 >= V_65 ) {
F_22 ( V_52 , V_81 -> V_28 ) ;
V_81 -> V_28 = 0 ;
}
}
void F_55 ( struct V_11 * V_52 )
{
struct V_81 * V_81 = & V_52 -> V_81 ;
if ( ! F_71 ( V_81 ) )
return;
F_76 ( & V_81 -> V_85 ) ;
if ( V_59 -> V_33 & V_34 )
F_75 ( V_52 , V_81 ) ;
else
F_74 ( V_52 , V_81 ) ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_78 ( struct V_11 * V_52 )
{
struct V_81 * V_81 = & V_52 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
F_74 ( V_52 , V_81 ) ;
V_81 -> V_83 = V_86 ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_79 ( struct V_11 * V_52 )
{
struct V_81 * V_81 = & V_52 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
V_81 -> V_25 += F_73 ( V_81 ) ;
if ( V_81 -> V_25 >= V_65 ) {
F_18 ( V_52 , V_81 -> V_25 ) ;
V_81 -> V_25 = 0 ;
}
V_81 -> V_83 = V_87 ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_80 ( struct V_11 * V_52 )
{
struct V_81 * V_81 = & V_52 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
F_74 ( V_52 , V_81 ) ;
V_59 -> V_33 |= V_34 ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_81 ( struct V_11 * V_52 )
{
struct V_81 * V_81 = & V_52 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
F_75 ( V_52 , V_81 ) ;
V_59 -> V_33 &= ~ V_34 ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_54 ( struct V_11 * V_52 )
{
F_28 ( F_73 ( & V_52 -> V_81 ) ) ;
}
void F_57 ( struct V_11 * V_69 )
{
struct V_81 * V_81 = & V_69 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
V_81 -> V_83 = V_84 ;
F_77 ( & V_81 -> V_85 ) ;
V_81 = & V_59 -> V_81 ;
F_76 ( & V_81 -> V_85 ) ;
V_81 -> V_83 = V_87 ;
V_81 -> V_82 = F_72 () ;
F_77 ( & V_81 -> V_85 ) ;
}
void F_82 ( struct V_11 * V_46 , int V_14 )
{
struct V_81 * V_81 = & V_46 -> V_81 ;
unsigned long V_33 ;
F_83 ( V_33 ) ;
F_76 ( & V_81 -> V_85 ) ;
V_81 -> V_83 = V_87 ;
V_81 -> V_82 = F_72 () ;
F_77 ( & V_81 -> V_85 ) ;
F_84 ( V_33 ) ;
}
T_1 F_85 ( struct V_11 * V_46 )
{
struct V_81 * V_81 = & V_46 -> V_81 ;
unsigned int V_57 ;
T_1 V_28 ;
if ( ! F_86 () )
return V_46 -> V_28 ;
do {
V_57 = F_87 ( & V_81 -> V_85 ) ;
V_28 = V_46 -> V_28 ;
if ( V_81 -> V_83 == V_87 && V_46 -> V_33 & V_34 )
V_28 += V_81 -> V_28 + F_71 ( V_81 ) ;
} while ( F_88 ( & V_81 -> V_85 , V_57 ) );
return V_28 ;
}
void V_53 ( struct V_11 * V_46 , T_1 * V_25 , T_1 * V_31 )
{
struct V_81 * V_81 = & V_46 -> V_81 ;
unsigned int V_57 ;
T_1 V_3 ;
if ( ! F_86 () ) {
* V_25 = V_46 -> V_25 ;
* V_31 = V_46 -> V_31 ;
return;
}
do {
V_57 = F_87 ( & V_81 -> V_85 ) ;
* V_25 = V_46 -> V_25 ;
* V_31 = V_46 -> V_31 ;
if ( V_81 -> V_83 == V_84 || F_53 ( V_46 ) )
continue;
V_3 = F_71 ( V_81 ) ;
if ( V_81 -> V_83 == V_86 || V_46 -> V_33 & V_34 )
* V_25 += V_81 -> V_25 + V_3 ;
else if ( V_81 -> V_83 == V_87 )
* V_31 += V_81 -> V_31 + V_3 ;
} while ( F_88 ( & V_81 -> V_85 , V_57 ) );
}
