static inline
void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_5 , V_4 ) ;
F_3 ( V_2 , V_3 ) ;
F_4 ( & V_5 , V_4 ) ;
}
static inline
void F_5 ( struct V_1 * V_6 )
{
unsigned long V_4 ;
F_2 ( & V_5 , V_4 ) ;
F_6 ( V_6 ) ;
F_4 ( & V_5 , V_4 ) ;
}
static inline
void F_7 ( void )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
while ( ! F_8 ( & V_11 ) ) {
V_8 = F_9 ( V_11 . V_12 , struct V_7 , V_13 ) ;
F_10 ( V_14 L_1
L_2 ,
( unsigned long long ) V_8 -> V_15 ,
( unsigned long long ) V_8 -> V_16 ,
V_8 -> V_8 , V_8 -> V_17 , F_11 ( & V_8 -> V_18 ) ) ;
F_6 ( & V_8 -> V_13 ) ;
F_12 ( V_19 , V_8 ) ;
}
while ( ! F_8 ( & V_20 ) ) {
V_10 = F_9 ( V_20 . V_12 , struct V_9 , V_13 ) ;
F_10 ( V_14 L_3
L_4 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_21 , F_11 ( & V_10 -> V_18 ) ) ;
F_6 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
}
static inline void F_13 ( const char * V_23 ,
struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
T_1 V_25 = F_14 ( V_24 ) ;
if ( V_16 >= V_26 && ( V_16 % 2 ) == 0 && V_16 != V_25 - 1 ) {
F_15 ( V_27
L_5 ,
V_23 ,
( unsigned long long ) F_16 ( V_24 ) ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_15 ,
( unsigned long long ) V_16 ) ;
}
}
static inline struct V_28 *
F_17 ( struct V_29 * V_17 )
{
return F_18 ( V_17 -> V_30 -> V_31 -> V_32 ) ;
}
int T_2 F_19 ( void )
{
V_19 = F_20 ( L_6 ,
sizeof( struct V_7 ) , 0 ,
V_33 | V_34 , NULL ) ;
if ( ! V_19 )
return - V_35 ;
V_22 = F_20 ( L_7 ,
sizeof( struct V_9 ) , 0 ,
V_33 | V_34 , NULL ) ;
if ( ! V_22 )
goto V_36;
V_37 = F_21 ( V_38 ,
F_22 ( struct V_39 , V_40 ) ) ;
if ( ! V_37 )
goto V_41;
return 0 ;
V_41:
F_23 ( V_22 ) ;
V_22 = NULL ;
V_36:
F_23 ( V_19 ) ;
V_19 = NULL ;
return - V_35 ;
}
void F_24 ( void )
{
F_7 () ;
F_25 () ;
if ( V_19 )
F_23 ( V_19 ) ;
if ( V_22 )
F_23 ( V_22 ) ;
if ( V_37 )
F_26 ( V_37 ) ;
}
void F_27 ( struct V_29 * V_17 ,
struct V_42 * V_30 )
{
V_17 -> V_8 = V_43 ;
F_28 ( & V_17 -> V_44 , V_45 ) ;
V_17 -> V_46 = NULL ;
V_17 -> V_47 = 0 ;
F_29 ( & V_17 -> V_48 ) ;
F_29 ( & V_17 -> V_49 ) ;
V_17 -> V_30 = V_30 ;
}
static struct V_7 * F_30 ( T_3 V_50 )
{
struct V_7 * V_8 ;
V_8 = F_31 ( V_19 , V_50 ) ;
if ( ! V_8 )
return V_8 ;
V_8 -> V_8 = 0 ;
V_8 -> V_51 = 0 ;
V_8 -> V_17 = NULL ;
F_1 ( & V_8 -> V_13 , & V_11 ) ;
F_32 ( & V_8 -> V_18 , 1 ) ;
F_33 ( & V_8 -> V_52 ) ;
F_34 ( V_8 , V_50 , V_53 ) ;
return V_8 ;
}
void F_35 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return;
if ( F_36 ( & V_8 -> V_18 ) ) {
F_37 ( V_8 -> V_17 ) ;
F_5 ( & V_8 -> V_13 ) ;
F_38 ( V_8 , V_53 ) ;
F_12 ( V_19 , V_8 ) ;
}
}
static struct V_54 * F_39 ( struct V_55 * V_56 , T_1 V_57 ,
struct V_54 * V_58 )
{
struct V_54 * * V_59 = & V_56 -> V_54 ;
struct V_54 * V_60 = NULL ;
struct V_61 * V_6 ;
while ( * V_59 ) {
V_60 = * V_59 ;
V_6 = F_40 ( V_60 , struct V_61 , V_54 ) ;
if ( V_57 < V_6 -> V_15 )
V_59 = & ( * V_59 ) -> V_62 ;
else if ( V_57 > V_6 -> V_16 )
V_59 = & ( * V_59 ) -> V_63 ;
else
return V_60 ;
}
F_41 ( V_58 , V_60 , V_59 ) ;
F_42 ( V_58 , V_56 ) ;
return NULL ;
}
static struct V_54 * F_43 ( struct V_29 * V_17 , T_1 V_57 ,
struct V_54 * * V_64 ,
struct V_54 * * V_65 )
{
struct V_55 * V_56 = & V_17 -> V_8 ;
struct V_54 * V_66 = V_56 -> V_54 ;
struct V_54 * V_67 = NULL ;
struct V_54 * V_68 = NULL ;
struct V_61 * V_6 ;
struct V_61 * V_69 = NULL ;
while ( V_66 ) {
V_6 = F_40 ( V_66 , struct V_61 , V_54 ) ;
V_67 = V_66 ;
V_69 = V_6 ;
if ( V_57 < V_6 -> V_15 )
V_66 = V_66 -> V_62 ;
else if ( V_57 > V_6 -> V_16 )
V_66 = V_66 -> V_63 ;
else
return V_66 ;
}
if ( V_64 ) {
V_68 = V_67 ;
while ( V_67 && V_57 > V_69 -> V_16 ) {
V_67 = F_44 ( V_67 ) ;
V_69 = F_40 ( V_67 , struct V_61 , V_54 ) ;
}
* V_64 = V_67 ;
V_67 = V_68 ;
}
if ( V_65 ) {
V_69 = F_40 ( V_67 , struct V_61 , V_54 ) ;
while ( V_67 && V_57 < V_69 -> V_15 ) {
V_67 = F_45 ( V_67 ) ;
V_69 = F_40 ( V_67 , struct V_61 , V_54 ) ;
}
* V_65 = V_67 ;
}
return NULL ;
}
static inline struct V_54 * F_46 ( struct V_29 * V_17 ,
T_1 V_57 )
{
struct V_54 * V_67 = NULL ;
struct V_54 * V_70 ;
V_70 = F_43 ( V_17 , V_57 , & V_67 , NULL ) ;
if ( ! V_70 )
return V_67 ;
return V_70 ;
}
static void F_47 ( struct V_29 * V_17 , struct V_7 * V_2 ,
struct V_7 * V_71 )
{
if ( V_17 -> V_46 && V_17 -> V_46 -> V_72 )
V_17 -> V_46 -> V_72 ( V_17 -> V_30 -> V_31 , V_2 ,
V_71 ) ;
}
static void F_48 ( struct V_29 * V_17 ,
struct V_7 * V_8 )
{
struct V_7 * V_71 ;
struct V_54 * V_73 ;
if ( V_8 -> V_8 & ( V_74 | V_75 ) )
return;
V_73 = F_45 ( & V_8 -> V_54 ) ;
if ( V_73 ) {
V_71 = F_40 ( V_73 , struct V_7 , V_54 ) ;
if ( V_71 -> V_16 == V_8 -> V_15 - 1 &&
V_71 -> V_8 == V_8 -> V_8 ) {
F_47 ( V_17 , V_8 , V_71 ) ;
V_8 -> V_15 = V_71 -> V_15 ;
V_71 -> V_17 = NULL ;
F_49 ( & V_71 -> V_54 , & V_17 -> V_8 ) ;
F_35 ( V_71 ) ;
}
}
V_73 = F_44 ( & V_8 -> V_54 ) ;
if ( V_73 ) {
V_71 = F_40 ( V_73 , struct V_7 , V_54 ) ;
if ( V_71 -> V_15 == V_8 -> V_16 + 1 &&
V_71 -> V_8 == V_8 -> V_8 ) {
F_47 ( V_17 , V_8 , V_71 ) ;
V_8 -> V_16 = V_71 -> V_16 ;
V_71 -> V_17 = NULL ;
F_49 ( & V_71 -> V_54 , & V_17 -> V_8 ) ;
F_35 ( V_71 ) ;
}
}
}
static void F_50 ( struct V_29 * V_17 ,
struct V_7 * V_8 , unsigned long * V_76 )
{
if ( V_17 -> V_46 && V_17 -> V_46 -> V_77 )
V_17 -> V_46 -> V_77 ( V_17 -> V_30 -> V_31 , V_8 , V_76 ) ;
}
static void F_51 ( struct V_29 * V_17 ,
struct V_7 * V_8 , unsigned long * V_76 )
{
if ( V_17 -> V_46 && V_17 -> V_46 -> V_78 )
V_17 -> V_46 -> V_78 ( V_17 -> V_30 -> V_31 , V_8 , V_76 ) ;
}
static int F_52 ( struct V_29 * V_17 ,
struct V_7 * V_8 , T_1 V_15 , T_1 V_16 ,
unsigned long * V_76 )
{
struct V_54 * V_58 ;
if ( V_16 < V_15 )
F_53 ( 1 , V_14 L_8 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_15 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
F_54 ( V_17 , V_8 , V_76 ) ;
V_58 = F_39 ( & V_17 -> V_8 , V_16 , & V_8 -> V_54 ) ;
if ( V_58 ) {
struct V_7 * V_79 ;
V_79 = F_40 ( V_58 , struct V_7 , V_54 ) ;
F_10 ( V_14 L_9
L_10 , ( unsigned long long ) V_79 -> V_15 ,
( unsigned long long ) V_79 -> V_16 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 ) ;
return - V_80 ;
}
V_8 -> V_17 = V_17 ;
F_48 ( V_17 , V_8 ) ;
return 0 ;
}
static void F_55 ( struct V_29 * V_17 , struct V_7 * V_81 ,
T_1 V_82 )
{
if ( V_17 -> V_46 && V_17 -> V_46 -> V_83 )
V_17 -> V_46 -> V_83 ( V_17 -> V_30 -> V_31 , V_81 , V_82 ) ;
}
static int F_56 ( struct V_29 * V_17 , struct V_7 * V_81 ,
struct V_7 * V_84 , T_1 V_82 )
{
struct V_54 * V_58 ;
F_55 ( V_17 , V_81 , V_82 ) ;
V_84 -> V_15 = V_81 -> V_15 ;
V_84 -> V_16 = V_82 - 1 ;
V_84 -> V_8 = V_81 -> V_8 ;
V_81 -> V_15 = V_82 ;
V_58 = F_39 ( & V_17 -> V_8 , V_84 -> V_16 , & V_84 -> V_54 ) ;
if ( V_58 ) {
F_35 ( V_84 ) ;
return - V_80 ;
}
V_84 -> V_17 = V_17 ;
return 0 ;
}
static struct V_7 * F_57 ( struct V_7 * V_8 )
{
struct V_54 * V_12 = F_44 ( & V_8 -> V_54 ) ;
if ( V_12 )
return F_40 ( V_12 , struct V_7 , V_54 ) ;
else
return NULL ;
}
static struct V_7 * F_58 ( struct V_29 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_76 , int V_85 )
{
struct V_7 * V_12 ;
unsigned long V_86 = * V_76 & ~ V_87 ;
if ( ( V_86 & V_88 ) && ( V_8 -> V_8 & V_88 ) ) {
T_1 V_89 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
F_37 ( V_89 > V_17 -> V_47 ) ;
V_17 -> V_47 -= V_89 ;
}
F_51 ( V_17 , V_8 , V_76 ) ;
V_8 -> V_8 &= ~ V_86 ;
if ( V_85 )
F_59 ( & V_8 -> V_52 ) ;
if ( V_8 -> V_8 == 0 ) {
V_12 = F_57 ( V_8 ) ;
if ( V_8 -> V_17 ) {
F_49 ( & V_8 -> V_54 , & V_17 -> V_8 ) ;
V_8 -> V_17 = NULL ;
F_35 ( V_8 ) ;
} else {
F_37 ( 1 ) ;
}
} else {
F_48 ( V_17 , V_8 ) ;
V_12 = F_57 ( V_8 ) ;
}
return V_12 ;
}
static struct V_7 *
F_60 ( struct V_7 * V_84 )
{
if ( ! V_84 )
V_84 = F_30 ( V_45 ) ;
return V_84 ;
}
static void F_61 ( struct V_29 * V_17 , int V_90 )
{
F_62 ( F_17 ( V_17 ) , V_90 , L_11
L_12
L_13 ) ;
}
int F_63 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , int V_85 , int V_91 ,
struct V_7 * * V_92 ,
T_3 V_50 )
{
struct V_7 * V_8 ;
struct V_7 * V_93 ;
struct V_7 * V_84 = NULL ;
struct V_54 * V_58 ;
T_1 V_94 ;
int V_90 ;
int V_95 = 0 ;
F_64 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
if ( V_76 & V_96 )
V_76 |= V_97 ;
if ( V_91 )
V_76 |= ~ V_87 ;
V_76 |= V_98 ;
if ( V_76 & ( V_74 | V_75 ) )
V_95 = 1 ;
V_99:
if ( ! V_84 && ( V_50 & V_100 ) ) {
V_84 = F_30 ( V_50 ) ;
if ( ! V_84 )
return - V_35 ;
}
F_65 ( & V_17 -> V_48 ) ;
if ( V_92 ) {
V_93 = * V_92 ;
if ( V_95 ) {
* V_92 = NULL ;
V_92 = NULL ;
}
if ( V_93 && V_93 -> V_17 && V_93 -> V_15 <= V_15 &&
V_93 -> V_16 > V_15 ) {
if ( V_95 )
F_66 ( & V_93 -> V_18 ) ;
V_8 = V_93 ;
goto V_101;
}
if ( V_95 )
F_35 ( V_93 ) ;
}
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 )
goto V_102;
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
V_101:
if ( V_8 -> V_15 > V_16 )
goto V_102;
F_37 ( V_8 -> V_16 < V_15 ) ;
V_94 = V_8 -> V_16 ;
if ( ! ( V_8 -> V_8 & V_76 ) ) {
V_8 = F_57 ( V_8 ) ;
goto V_12;
}
if ( V_8 -> V_15 < V_15 ) {
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_56 ( V_17 , V_8 , V_84 , V_15 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
V_84 = NULL ;
if ( V_90 )
goto V_102;
if ( V_8 -> V_16 <= V_16 ) {
V_8 = F_58 ( V_17 , V_8 , & V_76 , V_85 ) ;
goto V_12;
}
goto V_103;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_56 ( V_17 , V_8 , V_84 , V_16 + 1 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
if ( V_85 )
F_59 ( & V_8 -> V_52 ) ;
F_58 ( V_17 , V_84 , & V_76 , V_85 ) ;
V_84 = NULL ;
goto V_102;
}
V_8 = F_58 ( V_17 , V_8 , & V_76 , V_85 ) ;
V_12:
if ( V_94 == ( T_1 ) - 1 )
goto V_102;
V_15 = V_94 + 1 ;
if ( V_15 <= V_16 && V_8 && ! F_68 () )
goto V_101;
goto V_103;
V_102:
F_69 ( & V_17 -> V_48 ) ;
if ( V_84 )
F_35 ( V_84 ) ;
return 0 ;
V_103:
if ( V_15 > V_16 )
goto V_102;
F_69 ( & V_17 -> V_48 ) ;
if ( V_50 & V_100 )
F_70 () ;
goto V_99;
}
static void F_71 ( struct V_29 * V_17 ,
struct V_7 * V_8 )
__releases( V_17 -> V_48 )
__acquires( V_17 -> V_48 )
{
F_72 ( V_104 ) ;
F_73 ( & V_8 -> V_52 , & V_104 , V_105 ) ;
F_69 ( & V_17 -> V_48 ) ;
F_74 () ;
F_65 ( & V_17 -> V_48 ) ;
F_75 ( & V_8 -> V_52 , & V_104 ) ;
}
static void F_76 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 )
{
struct V_7 * V_8 ;
struct V_54 * V_58 ;
F_64 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
F_65 ( & V_17 -> V_48 ) ;
V_99:
while ( 1 ) {
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 )
break;
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_8 -> V_15 > V_16 )
goto V_102;
if ( V_8 -> V_8 & V_76 ) {
V_15 = V_8 -> V_15 ;
F_77 ( & V_8 -> V_18 ) ;
F_71 ( V_17 , V_8 ) ;
F_35 ( V_8 ) ;
goto V_99;
}
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
F_78 ( & V_17 -> V_48 ) ;
}
V_102:
F_69 ( & V_17 -> V_48 ) ;
}
static void F_54 ( struct V_29 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_76 )
{
unsigned long V_106 = * V_76 & ~ V_87 ;
F_50 ( V_17 , V_8 , V_76 ) ;
if ( ( V_106 & V_88 ) && ! ( V_8 -> V_8 & V_88 ) ) {
T_1 V_89 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
V_17 -> V_47 += V_89 ;
}
V_8 -> V_8 |= V_106 ;
}
static void F_79 ( struct V_7 * V_8 ,
struct V_7 * * V_107 )
{
if ( V_107 && ! ( * V_107 ) ) {
if ( V_8 -> V_8 & ( V_74 | V_75 ) ) {
* V_107 = V_8 ;
F_77 ( & V_8 -> V_18 ) ;
}
}
}
static void F_80 ( struct V_7 * * V_107 )
{
if ( V_107 && ( * V_107 ) ) {
struct V_7 * V_8 = * V_107 ;
* V_107 = NULL ;
F_35 ( V_8 ) ;
}
}
static int T_4
F_81 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , unsigned long V_108 ,
T_1 * V_109 , struct V_7 * * V_92 ,
T_3 V_50 )
{
struct V_7 * V_8 ;
struct V_7 * V_84 = NULL ;
struct V_54 * V_58 ;
int V_90 = 0 ;
T_1 V_110 ;
T_1 V_94 ;
F_64 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
V_76 |= V_98 ;
V_99:
if ( ! V_84 && ( V_50 & V_100 ) ) {
V_84 = F_30 ( V_50 ) ;
F_67 ( ! V_84 ) ;
}
F_65 ( & V_17 -> V_48 ) ;
if ( V_92 && * V_92 ) {
V_8 = * V_92 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_58 = & V_8 -> V_54 ;
goto V_101;
}
}
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 ) {
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_52 ( V_17 , V_84 , V_15 , V_16 , & V_76 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
V_84 = NULL ;
goto V_102;
}
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
V_101:
V_110 = V_8 -> V_15 ;
V_94 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
if ( V_8 -> V_8 & V_108 ) {
* V_109 = V_8 -> V_15 ;
V_90 = - V_80 ;
goto V_102;
}
F_54 ( V_17 , V_8 , & V_76 ) ;
F_79 ( V_8 , V_92 ) ;
F_48 ( V_17 , V_8 ) ;
if ( V_94 == ( T_1 ) - 1 )
goto V_102;
V_15 = V_94 + 1 ;
V_8 = F_57 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_68 () )
goto V_101;
goto V_103;
}
if ( V_8 -> V_15 < V_15 ) {
if ( V_8 -> V_8 & V_108 ) {
* V_109 = V_15 ;
V_90 = - V_80 ;
goto V_102;
}
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_56 ( V_17 , V_8 , V_84 , V_15 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
V_84 = NULL ;
if ( V_90 )
goto V_102;
if ( V_8 -> V_16 <= V_16 ) {
F_54 ( V_17 , V_8 , & V_76 ) ;
F_79 ( V_8 , V_92 ) ;
F_48 ( V_17 , V_8 ) ;
if ( V_94 == ( T_1 ) - 1 )
goto V_102;
V_15 = V_94 + 1 ;
V_8 = F_57 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_68 () )
goto V_101;
}
goto V_103;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_111 ;
if ( V_16 < V_110 )
V_111 = V_16 ;
else
V_111 = V_110 - 1 ;
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_52 ( V_17 , V_84 , V_15 , V_111 ,
& V_76 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
F_79 ( V_84 , V_92 ) ;
V_84 = NULL ;
V_15 = V_111 + 1 ;
goto V_103;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
if ( V_8 -> V_8 & V_108 ) {
* V_109 = V_15 ;
V_90 = - V_80 ;
goto V_102;
}
V_84 = F_60 ( V_84 ) ;
F_67 ( ! V_84 ) ;
V_90 = F_56 ( V_17 , V_8 , V_84 , V_16 + 1 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
F_54 ( V_17 , V_84 , & V_76 ) ;
F_79 ( V_84 , V_92 ) ;
F_48 ( V_17 , V_84 ) ;
V_84 = NULL ;
goto V_102;
}
goto V_103;
V_102:
F_69 ( & V_17 -> V_48 ) ;
if ( V_84 )
F_35 ( V_84 ) ;
return V_90 ;
V_103:
if ( V_15 > V_16 )
goto V_102;
F_69 ( & V_17 -> V_48 ) ;
if ( V_50 & V_100 )
F_70 () ;
goto V_99;
}
int F_82 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , T_1 * V_109 ,
struct V_7 * * V_92 , T_3 V_50 )
{
return F_81 ( V_17 , V_15 , V_16 , V_76 , 0 , V_109 ,
V_92 , V_50 ) ;
}
int F_83 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , unsigned long V_112 ,
struct V_7 * * V_92 , T_3 V_50 )
{
struct V_7 * V_8 ;
struct V_7 * V_84 = NULL ;
struct V_54 * V_58 ;
int V_90 = 0 ;
T_1 V_110 ;
T_1 V_94 ;
F_64 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
V_99:
if ( ! V_84 && ( V_50 & V_100 ) ) {
V_84 = F_30 ( V_50 ) ;
if ( ! V_84 )
return - V_35 ;
}
F_65 ( & V_17 -> V_48 ) ;
if ( V_92 && * V_92 ) {
V_8 = * V_92 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_58 = & V_8 -> V_54 ;
goto V_101;
}
}
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 ) {
V_84 = F_60 ( V_84 ) ;
if ( ! V_84 ) {
V_90 = - V_35 ;
goto V_102;
}
V_90 = F_52 ( V_17 , V_84 , V_15 , V_16 , & V_76 ) ;
V_84 = NULL ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
goto V_102;
}
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
V_101:
V_110 = V_8 -> V_15 ;
V_94 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
F_54 ( V_17 , V_8 , & V_76 ) ;
F_79 ( V_8 , V_92 ) ;
V_8 = F_58 ( V_17 , V_8 , & V_112 , 0 ) ;
if ( V_94 == ( T_1 ) - 1 )
goto V_102;
V_15 = V_94 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_68 () )
goto V_101;
goto V_103;
}
if ( V_8 -> V_15 < V_15 ) {
V_84 = F_60 ( V_84 ) ;
if ( ! V_84 ) {
V_90 = - V_35 ;
goto V_102;
}
V_90 = F_56 ( V_17 , V_8 , V_84 , V_15 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
V_84 = NULL ;
if ( V_90 )
goto V_102;
if ( V_8 -> V_16 <= V_16 ) {
F_54 ( V_17 , V_8 , & V_76 ) ;
F_79 ( V_8 , V_92 ) ;
V_8 = F_58 ( V_17 , V_8 , & V_112 , 0 ) ;
if ( V_94 == ( T_1 ) - 1 )
goto V_102;
V_15 = V_94 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_68 () )
goto V_101;
}
goto V_103;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_111 ;
if ( V_16 < V_110 )
V_111 = V_16 ;
else
V_111 = V_110 - 1 ;
V_84 = F_60 ( V_84 ) ;
if ( ! V_84 ) {
V_90 = - V_35 ;
goto V_102;
}
V_90 = F_52 ( V_17 , V_84 , V_15 , V_111 ,
& V_76 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
F_79 ( V_84 , V_92 ) ;
V_84 = NULL ;
V_15 = V_111 + 1 ;
goto V_103;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_84 = F_60 ( V_84 ) ;
if ( ! V_84 ) {
V_90 = - V_35 ;
goto V_102;
}
V_90 = F_56 ( V_17 , V_8 , V_84 , V_16 + 1 ) ;
if ( V_90 )
F_61 ( V_17 , V_90 ) ;
F_54 ( V_17 , V_84 , & V_76 ) ;
F_79 ( V_84 , V_92 ) ;
F_58 ( V_17 , V_84 , & V_112 , 0 ) ;
V_84 = NULL ;
goto V_102;
}
goto V_103;
V_102:
F_69 ( & V_17 -> V_48 ) ;
if ( V_84 )
F_35 ( V_84 ) ;
return V_90 ;
V_103:
if ( V_15 > V_16 )
goto V_102;
F_69 ( & V_17 -> V_48 ) ;
if ( V_50 & V_100 )
F_70 () ;
goto V_99;
}
int F_84 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 , V_88 , NULL ,
NULL , V_50 ) ;
}
int F_85 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 , V_76 , NULL ,
NULL , V_50 ) ;
}
int F_86 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , T_3 V_50 )
{
return F_63 ( V_17 , V_15 , V_16 , V_76 , 0 , 0 , NULL , V_50 ) ;
}
int F_87 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_92 , T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_96 | V_113 ,
NULL , V_92 , V_50 ) ;
}
int F_88 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_92 , T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_96 | V_113 | V_114 ,
NULL , V_92 , V_50 ) ;
}
int F_89 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_50 )
{
return F_63 ( V_17 , V_15 , V_16 ,
V_88 | V_96 |
V_115 , 0 , 0 , NULL , V_50 ) ;
}
int F_90 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 , V_116 , NULL ,
NULL , V_50 ) ;
}
int F_91 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_92 , T_3 V_50 )
{
return F_82 ( V_17 , V_15 , V_16 , V_113 , NULL ,
V_92 , V_50 ) ;
}
int F_92 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_92 , T_3 V_50 )
{
return F_63 ( V_17 , V_15 , V_16 , V_113 , 0 , 0 ,
V_92 , V_50 ) ;
}
int F_93 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , struct V_7 * * V_92 )
{
int V_90 ;
T_1 V_109 ;
while ( 1 ) {
V_90 = F_81 ( V_17 , V_15 , V_16 , V_117 | V_76 ,
V_117 , & V_109 ,
V_92 , V_118 ) ;
if ( V_90 == - V_80 ) {
F_76 ( V_17 , V_109 , V_16 , V_117 ) ;
V_15 = V_109 ;
} else
break;
F_37 ( V_15 > V_16 ) ;
}
return V_90 ;
}
int F_94 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_93 ( V_17 , V_15 , V_16 , 0 , NULL ) ;
}
int F_95 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
int V_90 ;
T_1 V_109 ;
V_90 = F_81 ( V_17 , V_15 , V_16 , V_117 , V_117 ,
& V_109 , NULL , V_118 ) ;
if ( V_90 == - V_80 ) {
if ( V_109 > V_15 )
F_63 ( V_17 , V_15 , V_109 - 1 ,
V_117 , 1 , 0 , NULL , V_118 ) ;
return 0 ;
}
return 1 ;
}
int F_96 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_93 , T_3 V_50 )
{
return F_63 ( V_17 , V_15 , V_16 , V_117 , 1 , 0 , V_93 ,
V_50 ) ;
}
int F_97 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_63 ( V_17 , V_15 , V_16 , V_117 , 1 , 0 , NULL ,
V_118 ) ;
}
int F_98 ( struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_119 = V_15 >> V_120 ;
unsigned long V_121 = V_16 >> V_120 ;
struct V_122 * V_122 ;
while ( V_119 <= V_121 ) {
V_122 = F_99 ( V_24 -> V_123 , V_119 ) ;
F_67 ( ! V_122 ) ;
F_100 ( V_122 ) ;
F_101 ( V_122 ) ;
V_119 ++ ;
}
return 0 ;
}
int F_102 ( struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_119 = V_15 >> V_120 ;
unsigned long V_121 = V_16 >> V_120 ;
struct V_122 * V_122 ;
while ( V_119 <= V_121 ) {
V_122 = F_99 ( V_24 -> V_123 , V_119 ) ;
F_67 ( ! V_122 ) ;
F_103 ( V_122 ) ;
F_104 ( V_122 ) ;
F_101 ( V_122 ) ;
V_119 ++ ;
}
return 0 ;
}
static int F_105 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_119 = V_15 >> V_120 ;
unsigned long V_121 = V_16 >> V_120 ;
struct V_122 * V_122 ;
while ( V_119 <= V_121 ) {
V_122 = F_99 ( V_17 -> V_30 , V_119 ) ;
F_67 ( ! V_122 ) ;
F_106 ( V_122 ) ;
F_101 ( V_122 ) ;
V_119 ++ ;
}
return 0 ;
}
static struct V_7 *
F_107 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_76 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 )
goto V_102;
while ( 1 ) {
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_8 -> V_16 >= V_15 && ( V_8 -> V_8 & V_76 ) )
return V_8 ;
V_58 = F_44 ( V_58 ) ;
if ( ! V_58 )
break;
}
V_102:
return NULL ;
}
int F_108 ( struct V_29 * V_17 , T_1 V_15 ,
T_1 * V_124 , T_1 * V_125 , unsigned long V_76 ,
struct V_7 * * V_92 )
{
struct V_7 * V_8 ;
struct V_54 * V_66 ;
int V_70 = 1 ;
F_65 ( & V_17 -> V_48 ) ;
if ( V_92 && * V_92 ) {
V_8 = * V_92 ;
if ( V_8 -> V_16 == V_15 - 1 && V_8 -> V_17 ) {
V_66 = F_44 ( & V_8 -> V_54 ) ;
while ( V_66 ) {
V_8 = F_40 ( V_66 , struct V_7 ,
V_54 ) ;
if ( V_8 -> V_8 & V_76 )
goto V_126;
V_66 = F_44 ( V_66 ) ;
}
F_35 ( * V_92 ) ;
* V_92 = NULL ;
goto V_102;
}
F_35 ( * V_92 ) ;
* V_92 = NULL ;
}
V_8 = F_107 ( V_17 , V_15 , V_76 ) ;
V_126:
if ( V_8 ) {
F_79 ( V_8 , V_92 ) ;
* V_124 = V_8 -> V_15 ;
* V_125 = V_8 -> V_16 ;
V_70 = 0 ;
}
V_102:
F_69 ( & V_17 -> V_48 ) ;
return V_70 ;
}
static T_5 T_1 F_109 ( struct V_29 * V_17 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_127 ,
struct V_7 * * V_92 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
T_1 V_128 = * V_15 ;
T_1 V_79 = 0 ;
T_1 V_129 = 0 ;
F_65 ( & V_17 -> V_48 ) ;
V_58 = F_46 ( V_17 , V_128 ) ;
if ( ! V_58 ) {
if ( ! V_79 )
* V_16 = ( T_1 ) - 1 ;
goto V_102;
}
while ( 1 ) {
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_79 && ( V_8 -> V_15 != V_128 ||
( V_8 -> V_8 & V_75 ) ) ) {
goto V_102;
}
if ( ! ( V_8 -> V_8 & V_96 ) ) {
if ( ! V_79 )
* V_16 = V_8 -> V_16 ;
goto V_102;
}
if ( ! V_79 ) {
* V_15 = V_8 -> V_15 ;
* V_92 = V_8 ;
F_77 ( & V_8 -> V_18 ) ;
}
V_79 ++ ;
* V_16 = V_8 -> V_16 ;
V_128 = V_8 -> V_16 + 1 ;
V_58 = F_44 ( V_58 ) ;
if ( ! V_58 )
break;
V_129 += V_8 -> V_16 - V_8 -> V_15 + 1 ;
if ( V_129 >= V_127 )
break;
}
V_102:
F_69 ( & V_17 -> V_48 ) ;
return V_79 ;
}
static T_5 void F_110 ( struct V_24 * V_24 ,
struct V_122 * V_130 ,
T_1 V_15 , T_1 V_16 )
{
int V_70 ;
struct V_122 * V_131 [ 16 ] ;
unsigned long V_119 = V_15 >> V_120 ;
unsigned long V_121 = V_16 >> V_120 ;
unsigned long V_132 = V_121 - V_119 + 1 ;
int V_133 ;
if ( V_119 == V_130 -> V_119 && V_121 == V_119 )
return;
while ( V_132 > 0 ) {
V_70 = F_111 ( V_24 -> V_123 , V_119 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_131 ) ;
for ( V_133 = 0 ; V_133 < V_70 ; V_133 ++ ) {
if ( V_131 [ V_133 ] != V_130 )
F_113 ( V_131 [ V_133 ] ) ;
F_101 ( V_131 [ V_133 ] ) ;
}
V_132 -= V_70 ;
V_119 += V_70 ;
F_70 () ;
}
}
static T_5 int F_114 ( struct V_24 * V_24 ,
struct V_122 * V_130 ,
T_1 V_134 ,
T_1 V_135 )
{
unsigned long V_119 = V_134 >> V_120 ;
unsigned long V_136 = V_119 ;
unsigned long V_121 = V_135 >> V_120 ;
unsigned long V_137 = 0 ;
struct V_122 * V_131 [ 16 ] ;
unsigned long V_138 ;
int V_70 ;
int V_133 ;
if ( V_119 == V_130 -> V_119 && V_119 == V_121 )
return 0 ;
V_138 = V_121 - V_119 + 1 ;
while ( V_138 > 0 ) {
V_70 = F_111 ( V_24 -> V_123 , V_119 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_131 ) ;
if ( V_70 == 0 ) {
V_70 = - V_139 ;
goto V_140;
}
for ( V_133 = 0 ; V_133 < V_70 ; V_133 ++ ) {
if ( V_131 [ V_133 ] != V_130 ) {
F_115 ( V_131 [ V_133 ] ) ;
if ( ! F_116 ( V_131 [ V_133 ] ) ||
V_131 [ V_133 ] -> V_30 != V_24 -> V_123 ) {
V_70 = - V_139 ;
F_113 ( V_131 [ V_133 ] ) ;
F_101 ( V_131 [ V_133 ] ) ;
goto V_140;
}
}
F_101 ( V_131 [ V_133 ] ) ;
V_137 ++ ;
}
V_138 -= V_70 ;
V_119 += V_70 ;
F_70 () ;
}
V_70 = 0 ;
V_140:
if ( V_70 && V_137 ) {
F_110 ( V_24 , V_130 ,
V_134 ,
( ( T_1 ) ( V_136 + V_137 - 1 ) ) <<
V_120 ) ;
}
return V_70 ;
}
static T_5 T_1 F_117 ( struct V_24 * V_24 ,
struct V_29 * V_17 ,
struct V_122 * V_130 ,
T_1 * V_15 , T_1 * V_16 ,
T_1 V_127 )
{
T_1 V_134 ;
T_1 V_135 ;
T_1 V_79 ;
struct V_7 * V_92 = NULL ;
int V_70 ;
int V_141 = 0 ;
V_99:
V_134 = * V_15 ;
V_135 = 0 ;
V_79 = F_109 ( V_17 , & V_134 , & V_135 ,
V_127 , & V_92 ) ;
if ( ! V_79 || V_135 <= * V_15 ) {
* V_15 = V_134 ;
* V_16 = V_135 ;
F_35 ( V_92 ) ;
return V_79 ;
}
if ( V_134 < * V_15 )
V_134 = * V_15 ;
if ( V_135 + 1 - V_134 > V_127 && V_141 )
V_135 = V_134 + V_142 - 1 ;
V_70 = F_114 ( V_24 , V_130 ,
V_134 , V_135 ) ;
if ( V_70 == - V_139 ) {
F_35 ( V_92 ) ;
if ( ! V_141 ) {
unsigned long V_57 = ( * V_15 ) & ( V_142 - 1 ) ;
V_127 = V_142 - V_57 ;
V_141 = 1 ;
goto V_99;
} else {
V_79 = 0 ;
goto V_143;
}
}
F_67 ( V_70 ) ;
F_93 ( V_17 , V_134 , V_135 , 0 , & V_92 ) ;
V_70 = F_118 ( V_17 , V_134 , V_135 ,
V_96 , 1 , V_92 ) ;
if ( ! V_70 ) {
F_96 ( V_17 , V_134 , V_135 ,
& V_92 , V_118 ) ;
F_110 ( V_24 , V_130 ,
V_134 , V_135 ) ;
F_70 () ;
goto V_99;
}
F_35 ( V_92 ) ;
* V_15 = V_134 ;
* V_16 = V_135 ;
V_143:
return V_79 ;
}
int F_119 ( struct V_24 * V_24 ,
struct V_29 * V_17 ,
T_1 V_15 , T_1 V_16 , struct V_122 * V_130 ,
unsigned long V_144 )
{
int V_70 ;
struct V_122 * V_131 [ 16 ] ;
unsigned long V_119 = V_15 >> V_120 ;
unsigned long V_121 = V_16 >> V_120 ;
unsigned long V_132 = V_121 - V_119 + 1 ;
int V_133 ;
unsigned long V_112 = 0 ;
if ( V_144 & V_145 )
V_112 |= V_117 ;
if ( V_144 & V_146 )
V_112 |= V_88 ;
if ( V_144 & V_147 )
V_112 |= V_96 ;
F_63 ( V_17 , V_15 , V_16 , V_112 , 1 , 0 , NULL , V_118 ) ;
if ( ! ( V_144 & ( V_148 | V_146 |
V_149 | V_150 |
V_151 ) ) )
return 0 ;
while ( V_132 > 0 ) {
V_70 = F_111 ( V_24 -> V_123 , V_119 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_131 ) ;
for ( V_133 = 0 ; V_133 < V_70 ; V_133 ++ ) {
if ( V_144 & V_151 )
F_120 ( V_131 [ V_133 ] ) ;
if ( V_131 [ V_133 ] == V_130 ) {
F_101 ( V_131 [ V_133 ] ) ;
continue;
}
if ( V_144 & V_146 )
F_100 ( V_131 [ V_133 ] ) ;
if ( V_144 & V_149 )
F_106 ( V_131 [ V_133 ] ) ;
if ( V_144 & V_150 )
F_121 ( V_131 [ V_133 ] ) ;
if ( V_144 & V_148 )
F_113 ( V_131 [ V_133 ] ) ;
F_101 ( V_131 [ V_133 ] ) ;
}
V_132 -= V_70 ;
V_119 += V_70 ;
F_70 () ;
}
return 0 ;
}
T_1 F_122 ( struct V_29 * V_17 ,
T_1 * V_15 , T_1 V_152 , T_1 V_127 ,
unsigned long V_76 , int V_153 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
T_1 V_128 = * V_15 ;
T_1 V_129 = 0 ;
T_1 V_154 = 0 ;
int V_79 = 0 ;
if ( V_152 <= V_128 ) {
F_37 ( 1 ) ;
return 0 ;
}
F_65 ( & V_17 -> V_48 ) ;
if ( V_128 == 0 && V_76 == V_88 ) {
V_129 = V_17 -> V_47 ;
goto V_102;
}
V_58 = F_46 ( V_17 , V_128 ) ;
if ( ! V_58 )
goto V_102;
while ( 1 ) {
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_8 -> V_15 > V_152 )
break;
if ( V_153 && V_79 && V_8 -> V_15 > V_154 + 1 )
break;
if ( V_8 -> V_16 >= V_128 && ( V_8 -> V_8 & V_76 ) == V_76 ) {
V_129 += F_123 ( V_152 , V_8 -> V_16 ) + 1 -
F_124 ( V_128 , V_8 -> V_15 ) ;
if ( V_129 >= V_127 )
break;
if ( ! V_79 ) {
* V_15 = F_124 ( V_128 , V_8 -> V_15 ) ;
V_79 = 1 ;
}
V_154 = V_8 -> V_16 ;
} else if ( V_153 && V_79 ) {
break;
}
V_58 = F_44 ( V_58 ) ;
if ( ! V_58 )
break;
}
V_102:
F_69 ( & V_17 -> V_48 ) ;
return V_129 ;
}
int F_125 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_51 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
int V_70 = 0 ;
F_65 ( & V_17 -> V_48 ) ;
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 ) {
V_70 = - V_155 ;
goto V_102;
}
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_70 = - V_155 ;
goto V_102;
}
V_8 -> V_51 = V_51 ;
V_102:
F_69 ( & V_17 -> V_48 ) ;
return V_70 ;
}
void F_126 ( struct V_29 * V_17 , T_1 V_15 , T_6 V_156 [] ,
int V_157 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
F_65 ( & V_17 -> V_48 ) ;
V_58 = F_46 ( V_17 , V_15 ) ;
F_67 ( ! V_58 ) ;
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
F_67 ( V_8 -> V_15 != V_15 ) ;
while ( V_157 ) {
V_8 -> V_51 = * V_156 ++ ;
V_157 -- ;
V_8 = F_57 ( V_8 ) ;
}
F_69 ( & V_17 -> V_48 ) ;
}
static inline T_1 F_127 ( struct V_40 * V_40 , int V_158 )
{
struct V_159 * V_160 = V_40 -> V_161 + V_158 ;
return F_128 ( V_160 -> V_162 ) + V_160 -> V_163 ;
}
void F_129 ( struct V_29 * V_17 , struct V_40 * V_40 , int V_158 ,
T_6 V_156 [] , int V_157 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 = NULL ;
T_1 V_15 ;
F_65 ( & V_17 -> V_48 ) ;
do {
V_15 = F_127 ( V_40 , V_158 ) ;
if ( V_8 == NULL || V_8 -> V_15 != V_15 ) {
V_58 = F_46 ( V_17 , V_15 ) ;
F_67 ( ! V_58 ) ;
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
F_67 ( V_8 -> V_15 != V_15 ) ;
}
V_8 -> V_51 = * V_156 ++ ;
V_157 -- ;
V_158 ++ ;
V_8 = F_57 ( V_8 ) ;
} while ( V_157 );
F_69 ( & V_17 -> V_48 ) ;
}
int F_130 ( struct V_29 * V_17 , T_1 V_15 , T_1 * V_51 )
{
struct V_54 * V_58 ;
struct V_7 * V_8 ;
int V_70 = 0 ;
F_65 ( & V_17 -> V_48 ) ;
V_58 = F_46 ( V_17 , V_15 ) ;
if ( ! V_58 ) {
V_70 = - V_155 ;
goto V_102;
}
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_70 = - V_155 ;
goto V_102;
}
* V_51 = V_8 -> V_51 ;
V_102:
F_69 ( & V_17 -> V_48 ) ;
return V_70 ;
}
int F_118 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_76 , int V_164 , struct V_7 * V_93 )
{
struct V_7 * V_8 = NULL ;
struct V_54 * V_58 ;
int V_165 = 0 ;
F_65 ( & V_17 -> V_48 ) ;
if ( V_93 && V_93 -> V_17 && V_93 -> V_15 <= V_15 &&
V_93 -> V_16 > V_15 )
V_58 = & V_93 -> V_54 ;
else
V_58 = F_46 ( V_17 , V_15 ) ;
while ( V_58 && V_15 <= V_16 ) {
V_8 = F_40 ( V_58 , struct V_7 , V_54 ) ;
if ( V_164 && V_8 -> V_15 > V_15 ) {
V_165 = 0 ;
break;
}
if ( V_8 -> V_15 > V_16 )
break;
if ( V_8 -> V_8 & V_76 ) {
V_165 = 1 ;
if ( ! V_164 )
break;
} else if ( V_164 ) {
V_165 = 0 ;
break;
}
if ( V_8 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_58 = F_44 ( V_58 ) ;
if ( ! V_58 ) {
if ( V_164 )
V_165 = 0 ;
break;
}
}
F_69 ( & V_17 -> V_48 ) ;
return V_165 ;
}
static void F_131 ( struct V_29 * V_17 , struct V_122 * V_122 )
{
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
if ( F_118 ( V_17 , V_15 , V_16 , V_113 , 1 , NULL ) )
F_132 ( V_122 ) ;
}
static int F_133 ( struct V_24 * V_24 , struct V_166 * V_167 ,
int V_168 )
{
int V_70 ;
int V_90 = 0 ;
struct V_29 * V_169 = & F_134 ( V_24 ) -> V_170 ;
F_125 ( V_169 , V_167 -> V_15 , 0 ) ;
V_70 = F_86 ( V_169 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_117 | V_88 , V_118 ) ;
if ( V_70 )
V_90 = V_70 ;
V_70 = F_86 ( & F_134 ( V_24 ) -> V_171 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_172 , V_118 ) ;
if ( V_70 && ! V_90 )
V_90 = V_70 ;
F_135 ( V_167 ) ;
return V_90 ;
}
static void F_136 ( struct V_40 * V_40 , int V_90 )
{
F_137 ( V_40 -> V_173 ) ;
}
int F_138 ( struct V_28 * V_174 , T_1 V_15 ,
T_1 V_175 , T_1 V_176 , struct V_122 * V_122 ,
int V_177 )
{
struct V_40 * V_40 ;
struct V_178 * V_179 ;
F_139 ( V_180 ) ;
T_1 V_181 = 0 ;
T_1 V_182 ;
struct V_183 * V_184 = NULL ;
struct V_185 * V_186 = & V_174 -> V_187 ;
int V_70 ;
F_67 ( ! V_177 ) ;
if ( F_140 ( V_186 , V_176 , V_175 , V_177 ) )
return 0 ;
V_40 = F_141 ( V_118 , 1 ) ;
if ( ! V_40 )
return - V_188 ;
V_40 -> V_173 = & V_180 ;
V_40 -> V_189 = F_136 ;
V_40 -> V_190 = 0 ;
V_181 = V_175 ;
V_70 = F_142 ( V_174 , V_191 , V_176 ,
& V_181 , & V_184 , V_177 ) ;
if ( V_70 ) {
F_143 ( V_40 ) ;
return - V_188 ;
}
F_67 ( V_177 != V_184 -> V_177 ) ;
V_182 = V_184 -> V_192 [ V_177 - 1 ] . V_193 >> 9 ;
V_40 -> V_194 = V_182 ;
V_179 = V_184 -> V_192 [ V_177 - 1 ] . V_179 ;
F_135 ( V_184 ) ;
if ( ! V_179 || ! V_179 -> V_195 || ! V_179 -> V_196 ) {
F_143 ( V_40 ) ;
return - V_188 ;
}
V_40 -> V_197 = V_179 -> V_195 ;
F_144 ( V_40 , V_122 , V_175 , V_15 - F_128 ( V_122 ) ) ;
F_145 ( V_198 , V_40 ) ;
F_146 ( & V_180 ) ;
if ( ! F_147 ( V_199 , & V_40 -> V_200 ) ) {
F_143 ( V_40 ) ;
F_148 ( V_179 , V_201 ) ;
return - V_188 ;
}
F_149 ( V_202 L_14
L_15 , V_122 -> V_30 -> V_31 -> V_203 ,
V_15 , F_150 ( V_179 -> V_204 ) , V_182 ) ;
F_143 ( V_40 ) ;
return 0 ;
}
int F_151 ( struct V_205 * V_56 , struct V_9 * V_10 ,
int V_177 )
{
T_1 V_15 = V_10 -> V_15 ;
unsigned long V_133 , V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
int V_70 = 0 ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
struct V_122 * V_59 = F_153 ( V_10 , V_133 ) ;
V_70 = F_138 ( V_56 -> V_174 , V_15 , V_142 ,
V_15 , V_59 , V_177 ) ;
if ( V_70 )
break;
V_15 += V_142 ;
}
return V_70 ;
}
static int F_154 ( T_1 V_15 , struct V_122 * V_122 )
{
T_1 V_51 ;
T_1 V_207 ;
struct V_166 * V_208 ;
struct V_28 * V_174 ;
struct V_7 * V_8 ;
int V_209 ;
int V_168 = 0 ;
int V_70 ;
struct V_24 * V_24 = V_122 -> V_30 -> V_31 ;
V_51 = 0 ;
V_70 = F_122 ( & F_134 ( V_24 ) -> V_170 , & V_51 ,
( T_1 ) - 1 , 1 , V_88 , 0 ) ;
if ( ! V_70 )
return 0 ;
V_70 = F_130 ( & F_134 ( V_24 ) -> V_170 , V_15 ,
& V_207 ) ;
if ( V_70 )
return 0 ;
V_208 = (struct V_166 * ) ( unsigned long ) V_207 ;
F_67 ( ! V_208 -> V_210 ) ;
if ( V_208 -> V_211 ) {
F_155 ( L_16 ,
V_208 -> V_15 ) ;
V_168 = 1 ;
goto V_102;
}
F_65 ( & F_134 ( V_24 ) -> V_171 . V_48 ) ;
V_8 = F_107 ( & F_134 ( V_24 ) -> V_171 ,
V_208 -> V_15 ,
V_117 ) ;
F_69 ( & F_134 ( V_24 ) -> V_171 . V_48 ) ;
if ( V_8 && V_8 -> V_15 == V_208 -> V_15 ) {
V_174 = F_134 ( V_24 ) -> V_56 -> V_174 ;
V_209 = F_156 ( V_174 , V_208 -> V_176 ,
V_208 -> V_21 ) ;
if ( V_209 > 1 ) {
V_70 = F_138 ( V_174 , V_15 , V_208 -> V_21 ,
V_208 -> V_176 , V_122 ,
V_208 -> V_212 ) ;
V_168 = ! V_70 ;
}
V_70 = 0 ;
}
V_102:
if ( ! V_70 )
V_70 = F_133 ( V_24 , V_208 , V_168 ) ;
return V_70 ;
}
static int F_157 ( struct V_40 * V_213 , struct V_122 * V_122 ,
T_1 V_15 , T_1 V_16 , int V_212 ,
struct V_7 * V_8 )
{
struct V_166 * V_208 = NULL ;
T_1 V_51 ;
struct V_214 * V_215 ;
struct V_24 * V_24 = V_122 -> V_30 -> V_31 ;
struct V_29 * V_169 = & F_134 ( V_24 ) -> V_170 ;
struct V_29 * V_17 = & F_134 ( V_24 ) -> V_171 ;
struct V_216 * V_217 = & F_134 ( V_24 ) -> V_218 ;
struct V_40 * V_40 ;
int V_209 ;
int V_70 ;
int V_219 ;
T_1 V_176 ;
F_67 ( V_213 -> V_220 & V_221 ) ;
V_70 = F_130 ( V_169 , V_15 , & V_51 ) ;
if ( V_70 ) {
V_208 = F_158 ( sizeof( * V_208 ) , V_118 ) ;
if ( ! V_208 )
return - V_35 ;
V_208 -> V_15 = V_15 ;
V_208 -> V_21 = V_16 - V_15 + 1 ;
V_208 -> V_210 = 0 ;
V_208 -> V_222 = 0 ;
V_208 -> V_211 = 0 ;
F_159 ( & V_217 -> V_48 ) ;
V_215 = F_160 ( V_217 , V_15 , V_208 -> V_21 ) ;
if ( ! V_215 ) {
F_161 ( & V_217 -> V_48 ) ;
F_135 ( V_208 ) ;
return - V_188 ;
}
if ( V_215 -> V_15 > V_15 || V_215 -> V_15 + V_215 -> V_21 < V_15 ) {
F_162 ( V_215 ) ;
V_215 = NULL ;
}
F_161 ( & V_217 -> V_48 ) ;
if ( ! V_215 ) {
F_135 ( V_208 ) ;
return - V_188 ;
}
V_176 = V_15 - V_215 -> V_15 ;
V_176 = V_215 -> V_223 + V_176 ;
if ( F_147 ( V_224 , & V_215 -> V_4 ) ) {
V_176 = V_215 -> V_223 ;
V_208 -> V_222 = V_225 ;
F_163 ( & V_208 -> V_222 ,
V_215 -> V_226 ) ;
}
F_155 ( L_17
L_18 , V_176 , V_15 , V_208 -> V_21 ) ;
V_208 -> V_176 = V_176 ;
F_162 ( V_215 ) ;
V_70 = F_85 ( V_169 , V_15 , V_16 ,
V_117 | V_88 , V_118 ) ;
if ( V_70 >= 0 )
V_70 = F_125 ( V_169 , V_15 ,
( T_1 ) ( unsigned long ) V_208 ) ;
if ( V_70 >= 0 )
V_70 = F_85 ( V_17 , V_15 , V_16 , V_172 ,
V_118 ) ;
if ( V_70 < 0 ) {
F_135 ( V_208 ) ;
return V_70 ;
}
} else {
V_208 = (struct V_166 * ) ( unsigned long ) V_51 ;
F_155 ( L_19
L_20 ,
V_208 -> V_176 , V_208 -> V_15 , V_208 -> V_21 ,
V_208 -> V_211 ) ;
}
V_209 = F_156 ( F_134 ( V_24 ) -> V_56 -> V_174 ,
V_208 -> V_176 , V_208 -> V_21 ) ;
if ( V_209 == 1 ) {
F_155 ( L_21
L_22
L_23 , V_8 , V_209 ,
V_208 -> V_210 , V_212 ) ;
F_133 ( V_24 , V_208 , 0 ) ;
return - V_188 ;
}
if ( ! V_8 ) {
F_65 ( & V_17 -> V_48 ) ;
V_8 = F_107 ( V_17 , V_208 -> V_15 ,
V_117 ) ;
if ( V_8 && V_8 -> V_15 != V_208 -> V_15 )
V_8 = NULL ;
F_69 ( & V_17 -> V_48 ) ;
}
if ( V_213 -> V_227 > 1 ) {
F_67 ( V_208 -> V_211 ) ;
V_208 -> V_211 = 1 ;
V_208 -> V_210 = V_212 ;
V_219 = V_228 | V_229 ;
} else {
if ( V_208 -> V_211 ) {
F_67 ( V_208 -> V_210 != V_212 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_210 = 0 ;
}
V_208 -> V_212 = V_212 ;
V_208 -> V_210 ++ ;
if ( V_208 -> V_210 == V_212 )
V_208 -> V_210 ++ ;
V_219 = V_228 ;
}
if ( ! V_8 || V_208 -> V_210 > V_209 ) {
F_155 ( L_24
L_25 , V_8 ,
V_209 , V_208 -> V_210 , V_212 ) ;
F_133 ( V_24 , V_208 , 0 ) ;
return - V_188 ;
}
V_40 = F_141 ( V_118 , 1 ) ;
if ( ! V_40 ) {
F_133 ( V_24 , V_208 , 0 ) ;
return - V_188 ;
}
V_40 -> V_173 = V_8 ;
V_40 -> V_189 = V_213 -> V_189 ;
V_40 -> V_194 = V_208 -> V_176 >> 9 ;
V_40 -> V_197 = F_134 ( V_24 ) -> V_56 -> V_174 -> V_230 -> V_231 ;
V_40 -> V_190 = 0 ;
F_144 ( V_40 , V_122 , V_208 -> V_21 , V_15 - F_128 ( V_122 ) ) ;
F_155 ( L_26
L_27 , V_219 ,
V_208 -> V_210 , V_209 , V_208 -> V_211 ) ;
V_70 = V_17 -> V_46 -> V_232 ( V_24 , V_219 , V_40 ,
V_208 -> V_210 ,
V_208 -> V_222 , 0 ) ;
return V_70 ;
}
int F_164 ( struct V_122 * V_122 , int V_90 , T_1 V_15 , T_1 V_16 )
{
int V_233 = ( V_90 == 0 ) ;
struct V_29 * V_17 ;
int V_70 ;
V_17 = & F_134 ( V_122 -> V_30 -> V_31 ) -> V_171 ;
if ( V_17 -> V_46 && V_17 -> V_46 -> V_234 ) {
V_70 = V_17 -> V_46 -> V_234 ( V_122 , V_15 ,
V_16 , NULL , V_233 ) ;
if ( V_70 )
V_233 = 0 ;
}
if ( ! V_233 ) {
F_165 ( V_122 ) ;
F_166 ( V_122 ) ;
}
return 0 ;
}
static void F_167 ( struct V_40 * V_40 , int V_90 )
{
struct V_159 * V_160 = V_40 -> V_161 + V_40 -> V_227 - 1 ;
struct V_29 * V_17 ;
T_1 V_15 ;
T_1 V_16 ;
do {
struct V_122 * V_122 = V_160 -> V_162 ;
V_17 = & F_134 ( V_122 -> V_30 -> V_31 ) -> V_171 ;
if ( V_160 -> V_163 || V_160 -> V_235 != V_142 )
F_10 ( L_28 ,
V_160 -> V_163 + V_160 -> V_235 != V_142
? V_14 L_29 : V_202 L_30 ,
V_160 -> V_163 , V_160 -> V_235 ) ;
V_15 = F_128 ( V_122 ) ;
V_16 = V_15 + V_160 -> V_163 + V_160 -> V_235 - 1 ;
if ( -- V_160 >= V_40 -> V_161 )
F_168 ( & V_160 -> V_162 -> V_4 ) ;
if ( F_164 ( V_122 , V_90 , V_15 , V_16 ) )
continue;
F_121 ( V_122 ) ;
} while ( V_160 >= V_40 -> V_161 );
F_143 ( V_40 ) ;
}
static void F_169 ( struct V_40 * V_40 , int V_90 )
{
int V_233 = F_147 ( V_199 , & V_40 -> V_200 ) ;
struct V_159 * V_236 = V_40 -> V_161 + V_40 -> V_227 - 1 ;
struct V_159 * V_160 = V_40 -> V_161 ;
struct V_29 * V_17 ;
T_1 V_15 ;
T_1 V_16 ;
int V_237 ;
int V_70 ;
if ( V_90 )
V_233 = 0 ;
do {
struct V_122 * V_122 = V_160 -> V_162 ;
struct V_7 * V_93 = NULL ;
struct V_7 * V_8 ;
struct V_39 * V_238 = V_39 ( V_40 ) ;
struct V_24 * V_24 = V_122 -> V_30 -> V_31 ;
F_155 ( L_31
L_32 , ( T_1 ) V_40 -> V_194 , V_90 ,
V_238 -> V_177 ) ;
V_17 = & F_134 ( V_24 ) -> V_171 ;
if ( V_160 -> V_163 || V_160 -> V_235 != V_142 )
F_10 ( L_33 ,
V_160 -> V_163 + V_160 -> V_235 != V_142
? V_14 L_29 : V_202 L_30 ,
V_160 -> V_163 , V_160 -> V_235 ) ;
V_15 = F_128 ( V_122 ) ;
V_16 = V_15 + V_160 -> V_163 + V_160 -> V_235 - 1 ;
if ( ++ V_160 <= V_236 )
F_168 ( & V_160 -> V_162 -> V_4 ) ;
F_65 ( & V_17 -> V_48 ) ;
V_8 = F_107 ( V_17 , V_15 , V_117 ) ;
if ( V_8 && V_8 -> V_15 == V_15 ) {
F_79 ( V_8 , & V_93 ) ;
}
F_69 ( & V_17 -> V_48 ) ;
V_237 = V_238 -> V_177 ;
if ( V_233 && V_17 -> V_46 && V_17 -> V_46 -> V_239 ) {
V_70 = V_17 -> V_46 -> V_239 ( V_122 , V_15 , V_16 ,
V_8 , V_237 ) ;
if ( V_70 )
V_233 = 0 ;
else
F_154 ( V_15 , V_122 ) ;
}
if ( ! V_233 && V_17 -> V_46 && V_17 -> V_46 -> V_240 ) {
V_70 = V_17 -> V_46 -> V_240 ( V_122 , V_237 ) ;
if ( ! V_70 && ! V_90 &&
F_147 ( V_199 , & V_40 -> V_200 ) )
V_233 = 1 ;
} else if ( ! V_233 ) {
V_70 = F_157 ( V_40 , V_122 , V_15 , V_16 , V_237 , NULL ) ;
if ( V_70 == 0 ) {
V_233 =
F_147 ( V_199 , & V_40 -> V_200 ) ;
if ( V_90 )
V_233 = 0 ;
F_80 ( & V_93 ) ;
continue;
}
}
if ( V_233 && V_17 -> V_241 ) {
F_91 ( V_17 , V_15 , V_16 , & V_93 ,
V_45 ) ;
}
F_96 ( V_17 , V_15 , V_16 , & V_93 , V_45 ) ;
if ( V_233 ) {
T_7 V_242 = F_14 ( V_24 ) ;
T_8 V_121 = V_242 >> V_120 ;
unsigned V_57 ;
V_57 = V_242 & ( V_142 - 1 ) ;
if ( V_122 -> V_119 == V_121 && V_57 )
F_170 ( V_122 , V_57 , V_142 ) ;
F_132 ( V_122 ) ;
} else {
F_165 ( V_122 ) ;
F_166 ( V_122 ) ;
}
F_113 ( V_122 ) ;
} while ( V_160 <= V_236 );
F_143 ( V_40 ) ;
}
struct V_40 *
F_171 ( struct V_243 * V_195 , T_1 V_244 , int V_245 ,
T_3 V_246 )
{
struct V_40 * V_40 ;
V_40 = F_172 ( V_246 , V_245 , V_37 ) ;
if ( V_40 == NULL && ( V_247 -> V_4 & V_248 ) ) {
while ( ! V_40 && ( V_245 /= 2 ) ) {
V_40 = F_172 ( V_246 ,
V_245 , V_37 ) ;
}
}
if ( V_40 ) {
V_40 -> V_190 = 0 ;
V_40 -> V_197 = V_195 ;
V_40 -> V_194 = V_244 ;
}
return V_40 ;
}
struct V_40 * F_173 ( struct V_40 * V_40 , T_3 V_249 )
{
return F_174 ( V_40 , V_249 , V_37 ) ;
}
struct V_40 * F_141 ( T_3 V_249 , unsigned int V_250 )
{
return F_172 ( V_249 , V_250 , V_37 ) ;
}
static int T_4 F_175 ( int V_251 , struct V_40 * V_40 ,
int V_177 , unsigned long V_222 )
{
int V_70 = 0 ;
struct V_159 * V_160 = V_40 -> V_161 + V_40 -> V_227 - 1 ;
struct V_122 * V_122 = V_160 -> V_162 ;
struct V_29 * V_17 = V_40 -> V_173 ;
T_1 V_15 ;
V_15 = F_128 ( V_122 ) + V_160 -> V_163 ;
V_40 -> V_173 = NULL ;
F_176 ( V_40 ) ;
if ( V_17 -> V_46 && V_17 -> V_46 -> V_232 )
V_70 = V_17 -> V_46 -> V_232 ( V_122 -> V_30 -> V_31 , V_251 , V_40 ,
V_177 , V_222 , V_15 ) ;
else
F_145 ( V_251 , V_40 ) ;
if ( F_177 ( V_40 , V_252 ) )
V_70 = - V_253 ;
F_143 ( V_40 ) ;
return V_70 ;
}
static int F_178 ( int V_251 , struct V_29 * V_17 , struct V_122 * V_122 ,
unsigned long V_57 , T_9 V_254 , struct V_40 * V_40 ,
unsigned long V_222 )
{
int V_70 = 0 ;
if ( V_17 -> V_46 && V_17 -> V_46 -> V_255 )
V_70 = V_17 -> V_46 -> V_255 ( V_251 , V_122 , V_57 , V_254 , V_40 ,
V_222 ) ;
F_67 ( V_70 < 0 ) ;
return V_70 ;
}
static int F_179 ( int V_251 , struct V_29 * V_17 ,
struct V_122 * V_122 , T_10 V_182 ,
T_9 V_254 , unsigned long V_57 ,
struct V_243 * V_195 ,
struct V_40 * * V_256 ,
unsigned long V_257 ,
T_11 V_258 ,
int V_177 ,
unsigned long V_259 ,
unsigned long V_222 )
{
int V_70 = 0 ;
struct V_40 * V_40 ;
int V_260 ;
int V_153 = 0 ;
int V_261 = V_222 & V_225 ;
int V_262 = V_259 & V_225 ;
T_9 V_263 = F_112 ( T_9 , V_254 , V_142 ) ;
if ( V_256 && * V_256 ) {
V_40 = * V_256 ;
if ( V_262 )
V_153 = V_40 -> V_194 == V_182 ;
else
V_153 = F_180 ( V_40 ) == V_182 ;
if ( V_259 != V_222 || ! V_153 ||
F_178 ( V_251 , V_17 , V_122 , V_57 , V_263 , V_40 , V_222 ) ||
F_144 ( V_40 , V_122 , V_263 , V_57 ) < V_263 ) {
V_70 = F_175 ( V_251 , V_40 , V_177 ,
V_259 ) ;
if ( V_70 < 0 )
return V_70 ;
V_40 = NULL ;
} else {
return 0 ;
}
}
if ( V_261 )
V_260 = V_264 ;
else
V_260 = F_181 ( V_195 ) ;
V_40 = F_171 ( V_195 , V_182 , V_260 , V_118 | V_265 ) ;
if ( ! V_40 )
return - V_35 ;
F_144 ( V_40 , V_122 , V_263 , V_57 ) ;
V_40 -> V_189 = V_258 ;
V_40 -> V_173 = V_17 ;
if ( V_256 )
* V_256 = V_40 ;
else
V_70 = F_175 ( V_251 , V_40 , V_177 , V_222 ) ;
return V_70 ;
}
static void F_182 ( struct V_9 * V_10 ,
struct V_122 * V_122 )
{
if ( ! F_183 ( V_122 ) ) {
F_184 ( V_122 ) ;
F_185 ( V_122 ) ;
F_186 ( V_122 , ( unsigned long ) V_10 ) ;
} else {
F_37 ( V_122 -> V_51 != ( unsigned long ) V_10 ) ;
}
}
void F_187 ( struct V_122 * V_122 )
{
if ( ! F_183 ( V_122 ) ) {
F_184 ( V_122 ) ;
F_185 ( V_122 ) ;
F_186 ( V_122 , V_266 ) ;
}
}
static int F_188 ( struct V_29 * V_17 ,
struct V_122 * V_122 ,
T_12 * V_267 ,
struct V_40 * * V_40 , int V_177 ,
unsigned long * V_222 , int V_251 )
{
struct V_24 * V_24 = V_122 -> V_30 -> V_31 ;
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_268 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_269 = V_15 ;
T_1 V_270 ;
T_1 V_271 = F_14 ( V_24 ) ;
T_1 V_223 ;
T_1 V_272 ;
T_10 V_182 ;
struct V_214 * V_215 ;
struct V_243 * V_195 ;
struct V_273 * V_274 ;
int V_70 ;
int V_260 = 0 ;
T_9 V_275 = 0 ;
T_9 V_276 ;
T_9 V_277 ;
T_9 V_278 = V_24 -> V_32 -> V_279 ;
unsigned long V_280 = 0 ;
F_187 ( V_122 ) ;
if ( ! F_189 ( V_122 ) ) {
if ( F_190 ( V_122 ) == 0 ) {
F_67 ( V_278 != V_26 ) ;
goto V_102;
}
}
V_16 = V_268 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_274 = F_191 ( V_24 , V_15 ) ;
if ( ! V_274 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_192 ( V_24 , V_274 , 1 ) ;
F_193 ( V_274 ) ;
}
if ( V_122 -> V_119 == V_271 >> V_120 ) {
char * V_281 ;
T_9 V_282 = V_271 & ( V_142 - 1 ) ;
if ( V_282 ) {
V_276 = V_142 - V_282 ;
V_281 = F_194 ( V_122 ) ;
memset ( V_281 + V_282 , 0 , V_276 ) ;
F_195 ( V_122 ) ;
F_196 ( V_281 ) ;
}
}
while ( V_269 <= V_16 ) {
unsigned long V_283 = ( V_271 >> V_120 ) + 1 ;
if ( V_269 >= V_271 ) {
char * V_281 ;
struct V_7 * V_93 = NULL ;
V_276 = V_142 - V_275 ;
V_281 = F_194 ( V_122 ) ;
memset ( V_281 + V_275 , 0 , V_276 ) ;
F_195 ( V_122 ) ;
F_196 ( V_281 ) ;
F_91 ( V_17 , V_269 , V_269 + V_276 - 1 ,
& V_93 , V_118 ) ;
F_96 ( V_17 , V_269 , V_269 + V_276 - 1 ,
& V_93 , V_118 ) ;
break;
}
V_215 = V_267 ( V_24 , V_122 , V_275 , V_269 ,
V_16 - V_269 + 1 , 0 ) ;
if ( F_197 ( V_215 ) ) {
F_166 ( V_122 ) ;
F_97 ( V_17 , V_269 , V_16 ) ;
break;
}
V_270 = V_269 - V_215 -> V_15 ;
F_67 ( F_198 ( V_215 ) <= V_269 ) ;
F_67 ( V_16 < V_269 ) ;
if ( F_147 ( V_224 , & V_215 -> V_4 ) ) {
V_280 = V_225 ;
F_163 ( & V_280 ,
V_215 -> V_226 ) ;
}
V_276 = F_123 ( F_198 ( V_215 ) - V_269 , V_16 - V_269 + 1 ) ;
V_272 = F_123 ( F_198 ( V_215 ) - 1 , V_16 ) ;
V_276 = F_199 ( V_276 , V_278 ) ;
if ( V_280 & V_225 ) {
V_277 = V_215 -> V_284 ;
V_182 = V_215 -> V_223 >> 9 ;
} else {
V_182 = ( V_215 -> V_223 + V_270 ) >> 9 ;
V_277 = V_276 ;
}
V_195 = V_215 -> V_195 ;
V_223 = V_215 -> V_223 ;
if ( F_147 ( V_285 , & V_215 -> V_4 ) )
V_223 = V_286 ;
F_162 ( V_215 ) ;
V_215 = NULL ;
if ( V_223 == V_286 ) {
char * V_281 ;
struct V_7 * V_93 = NULL ;
V_281 = F_194 ( V_122 ) ;
memset ( V_281 + V_275 , 0 , V_276 ) ;
F_195 ( V_122 ) ;
F_196 ( V_281 ) ;
F_91 ( V_17 , V_269 , V_269 + V_276 - 1 ,
& V_93 , V_118 ) ;
F_96 ( V_17 , V_269 , V_269 + V_276 - 1 ,
& V_93 , V_118 ) ;
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
continue;
}
if ( F_118 ( V_17 , V_269 , V_272 ,
V_113 , 1 , NULL ) ) {
F_131 ( V_17 , V_122 ) ;
F_97 ( V_17 , V_269 , V_269 + V_276 - 1 ) ;
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
continue;
}
if ( V_223 == V_287 ) {
F_166 ( V_122 ) ;
F_97 ( V_17 , V_269 , V_269 + V_276 - 1 ) ;
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
continue;
}
V_283 -= V_122 -> V_119 ;
V_70 = F_179 ( V_251 , V_17 , V_122 ,
V_182 , V_277 , V_275 ,
V_195 , V_40 , V_283 ,
F_169 , V_177 ,
* V_222 ,
V_280 ) ;
if ( ! V_70 ) {
V_260 ++ ;
* V_222 = V_280 ;
} else {
F_166 ( V_122 ) ;
F_97 ( V_17 , V_269 , V_269 + V_276 - 1 ) ;
}
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
}
V_102:
if ( ! V_260 ) {
if ( ! F_200 ( V_122 ) )
F_132 ( V_122 ) ;
F_113 ( V_122 ) ;
}
return 0 ;
}
int F_201 ( struct V_29 * V_17 , struct V_122 * V_122 ,
T_12 * V_267 , int V_177 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_222 = 0 ;
int V_70 ;
V_70 = F_188 ( V_17 , V_122 , V_267 , & V_40 , V_177 ,
& V_222 , V_288 ) ;
if ( V_40 )
V_70 = F_175 ( V_288 , V_40 , V_177 , V_222 ) ;
return V_70 ;
}
static T_5 void F_202 ( struct V_122 * V_122 ,
struct V_289 * V_290 ,
unsigned long V_291 )
{
V_290 -> V_292 -= V_291 ;
if ( V_290 -> V_293 || ( V_290 -> V_292 > 0 &&
V_290 -> V_294 == 0 && V_290 -> V_295 == V_296 ) )
V_122 -> V_30 -> V_297 = V_122 -> V_119 + V_291 ;
}
static int F_203 ( struct V_122 * V_122 , struct V_289 * V_290 ,
void * V_298 )
{
struct V_24 * V_24 = V_122 -> V_30 -> V_31 ;
struct V_299 * V_300 = V_298 ;
struct V_29 * V_17 = V_300 -> V_17 ;
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_134 ;
T_1 V_268 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_269 = V_15 ;
T_1 V_270 ;
T_1 V_271 = F_14 ( V_24 ) ;
T_1 V_223 ;
T_1 V_276 ;
T_10 V_182 ;
struct V_7 * V_92 = NULL ;
struct V_214 * V_215 ;
struct V_243 * V_195 ;
int V_70 ;
int V_260 = 0 ;
T_9 V_275 = 0 ;
T_9 V_278 ;
T_7 V_242 = F_14 ( V_24 ) ;
unsigned long V_121 = V_242 >> V_120 ;
T_1 V_301 ;
T_1 V_135 ;
int V_302 ;
int V_303 ;
int V_304 ;
unsigned long V_291 = 0 ;
bool V_305 = true ;
if ( V_290 -> V_306 == V_307 )
V_304 = V_198 ;
else
V_304 = V_191 ;
F_204 ( V_122 , V_24 , V_290 ) ;
F_37 ( ! F_205 ( V_122 ) ) ;
F_206 ( V_122 ) ;
V_275 = V_242 & ( V_142 - 1 ) ;
if ( V_122 -> V_119 > V_121 ||
( V_122 -> V_119 == V_121 && ! V_275 ) ) {
V_122 -> V_30 -> V_308 -> V_309 ( V_122 , 0 , V_142 ) ;
F_113 ( V_122 ) ;
return 0 ;
}
if ( V_122 -> V_119 == V_121 ) {
char * V_281 ;
V_281 = F_194 ( V_122 ) ;
memset ( V_281 + V_275 , 0 ,
V_142 - V_275 ) ;
F_196 ( V_281 ) ;
F_195 ( V_122 ) ;
}
V_275 = 0 ;
F_187 ( V_122 ) ;
if ( ! V_17 -> V_46 || ! V_17 -> V_46 -> V_305 )
V_305 = false ;
V_134 = V_15 ;
V_135 = 0 ;
V_302 = 0 ;
if ( ! V_300 -> V_310 && V_305 ) {
T_1 V_311 = 0 ;
F_202 ( V_122 , V_290 , 0 ) ;
while ( V_135 < V_268 ) {
V_301 = F_117 ( V_24 , V_17 ,
V_122 ,
& V_134 ,
& V_135 ,
128 * 1024 * 1024 ) ;
if ( V_301 == 0 ) {
V_134 = V_135 + 1 ;
continue;
}
V_70 = V_17 -> V_46 -> V_305 ( V_24 , V_122 ,
V_134 ,
V_135 ,
& V_302 ,
& V_291 ) ;
if ( V_70 ) {
F_166 ( V_122 ) ;
goto V_140;
}
V_311 += ( V_135 - V_134 +
V_142 ) >>
V_120 ;
V_134 = V_135 + 1 ;
}
if ( V_290 -> V_292 < V_311 ) {
int V_312 = 8192 ;
if ( V_311 < V_312 * 2 )
V_312 = V_311 ;
V_290 -> V_292 = F_112 ( T_1 , V_311 ,
V_312 ) ;
}
if ( V_302 ) {
V_70 = 0 ;
V_290 -> V_292 -= V_291 ;
goto V_313;
}
}
if ( V_17 -> V_46 && V_17 -> V_46 -> V_314 ) {
V_70 = V_17 -> V_46 -> V_314 ( V_122 , V_15 ,
V_268 ) ;
if ( V_70 ) {
if ( V_70 == - V_315 )
V_290 -> V_316 ++ ;
else
F_207 ( V_290 , V_122 ) ;
F_202 ( V_122 , V_290 , V_291 ) ;
F_113 ( V_122 ) ;
V_70 = 0 ;
goto V_313;
}
}
F_202 ( V_122 , V_290 , V_291 + 1 ) ;
V_16 = V_268 ;
if ( V_271 <= V_15 ) {
if ( V_17 -> V_46 && V_17 -> V_46 -> V_234 )
V_17 -> V_46 -> V_234 ( V_122 , V_15 ,
V_268 , NULL , 1 ) ;
goto V_140;
}
V_278 = V_24 -> V_32 -> V_279 ;
while ( V_269 <= V_16 ) {
if ( V_269 >= V_271 ) {
if ( V_17 -> V_46 && V_17 -> V_46 -> V_234 )
V_17 -> V_46 -> V_234 ( V_122 , V_269 ,
V_268 , NULL , 1 ) ;
break;
}
V_215 = V_300 -> V_267 ( V_24 , V_122 , V_275 , V_269 ,
V_16 - V_269 + 1 , 1 ) ;
if ( F_197 ( V_215 ) ) {
F_166 ( V_122 ) ;
break;
}
V_270 = V_269 - V_215 -> V_15 ;
F_67 ( F_198 ( V_215 ) <= V_269 ) ;
F_67 ( V_16 < V_269 ) ;
V_276 = F_123 ( F_198 ( V_215 ) - V_269 , V_16 - V_269 + 1 ) ;
V_276 = F_199 ( V_276 , V_278 ) ;
V_182 = ( V_215 -> V_223 + V_270 ) >> 9 ;
V_195 = V_215 -> V_195 ;
V_223 = V_215 -> V_223 ;
V_303 = F_147 ( V_224 , & V_215 -> V_4 ) ;
F_162 ( V_215 ) ;
V_215 = NULL ;
if ( V_303 || V_223 == V_286 ||
V_223 == V_287 ) {
if ( ! V_303 && V_17 -> V_46 &&
V_17 -> V_46 -> V_234 )
V_17 -> V_46 -> V_234 ( V_122 , V_269 ,
V_269 + V_276 - 1 ,
NULL , 1 ) ;
else if ( V_303 ) {
V_260 ++ ;
}
V_269 += V_276 ;
V_275 += V_276 ;
continue;
}
if ( 0 && ! F_118 ( V_17 , V_269 , V_269 + V_276 - 1 ,
V_88 , 0 , NULL ) ) {
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
continue;
}
if ( V_17 -> V_46 && V_17 -> V_46 -> V_317 ) {
V_70 = V_17 -> V_46 -> V_317 ( V_122 , V_269 ,
V_269 + V_276 - 1 ) ;
} else {
V_70 = 0 ;
}
if ( V_70 ) {
F_166 ( V_122 ) ;
} else {
unsigned long V_318 = V_121 + 1 ;
F_105 ( V_17 , V_269 , V_269 + V_276 - 1 ) ;
if ( ! F_208 ( V_122 ) ) {
F_10 ( V_14 L_34
L_35 ,
V_122 -> V_119 , ( unsigned long long ) V_269 ,
( unsigned long long ) V_16 ) ;
}
V_70 = F_179 ( V_304 , V_17 , V_122 ,
V_182 , V_276 , V_275 ,
V_195 , & V_300 -> V_40 , V_318 ,
F_167 ,
0 , 0 , 0 ) ;
if ( V_70 )
F_166 ( V_122 ) ;
}
V_269 = V_269 + V_276 ;
V_275 += V_276 ;
V_260 ++ ;
}
V_140:
if ( V_260 == 0 ) {
F_106 ( V_122 ) ;
F_121 ( V_122 ) ;
}
F_113 ( V_122 ) ;
V_313:
F_35 ( V_92 ) ;
return 0 ;
}
static int F_209 ( void * V_319 )
{
F_210 () ;
return 0 ;
}
void F_211 ( struct V_9 * V_10 )
{
F_212 ( & V_10 -> V_320 , V_321 , F_209 ,
V_105 ) ;
}
static int F_213 ( struct V_9 * V_10 ,
struct V_28 * V_174 ,
struct V_299 * V_300 )
{
unsigned long V_133 , V_206 ;
int V_322 = 0 ;
int V_70 = 0 ;
if ( ! F_214 ( V_10 ) ) {
V_322 = 1 ;
F_215 ( V_300 ) ;
F_216 ( V_10 ) ;
}
if ( F_147 ( V_321 , & V_10 -> V_320 ) ) {
F_217 ( V_10 ) ;
if ( ! V_300 -> V_323 )
return 0 ;
if ( ! V_322 ) {
F_215 ( V_300 ) ;
V_322 = 1 ;
}
while ( 1 ) {
F_211 ( V_10 ) ;
F_216 ( V_10 ) ;
if ( ! F_147 ( V_321 , & V_10 -> V_320 ) )
break;
F_217 ( V_10 ) ;
}
}
F_65 ( & V_10 -> V_324 ) ;
if ( F_218 ( V_325 , & V_10 -> V_320 ) ) {
F_219 ( V_321 , & V_10 -> V_320 ) ;
F_69 ( & V_10 -> V_324 ) ;
F_220 ( V_10 , V_326 ) ;
F_221 ( & V_174 -> V_327 ,
- V_10 -> V_21 ,
V_174 -> V_328 ) ;
V_70 = 1 ;
} else {
F_69 ( & V_10 -> V_324 ) ;
}
F_217 ( V_10 ) ;
if ( ! V_70 )
return V_70 ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
struct V_122 * V_59 = F_153 ( V_10 , V_133 ) ;
if ( ! F_222 ( V_59 ) ) {
if ( ! V_322 ) {
F_215 ( V_300 ) ;
V_322 = 1 ;
}
F_115 ( V_59 ) ;
}
}
return V_70 ;
}
static void F_223 ( struct V_9 * V_10 )
{
F_224 ( V_321 , & V_10 -> V_320 ) ;
F_225 () ;
F_226 ( & V_10 -> V_320 , V_321 ) ;
}
static void F_227 ( struct V_40 * V_40 , int V_90 )
{
int V_233 = V_90 == 0 ;
struct V_159 * V_160 = V_40 -> V_161 + V_40 -> V_227 - 1 ;
struct V_9 * V_10 ;
int V_140 ;
do {
struct V_122 * V_122 = V_160 -> V_162 ;
V_160 -- ;
V_10 = (struct V_9 * ) V_122 -> V_51 ;
F_67 ( ! V_10 ) ;
V_140 = F_36 ( & V_10 -> V_329 ) ;
if ( ! V_233 || F_147 ( V_330 , & V_10 -> V_320 ) ) {
F_219 ( V_330 , & V_10 -> V_320 ) ;
F_165 ( V_122 ) ;
F_166 ( V_122 ) ;
}
F_121 ( V_122 ) ;
if ( ! V_140 )
continue;
F_223 ( V_10 ) ;
} while ( V_160 >= V_40 -> V_161 );
F_143 ( V_40 ) ;
}
static int F_228 ( struct V_9 * V_10 ,
struct V_28 * V_174 ,
struct V_289 * V_290 ,
struct V_299 * V_300 )
{
struct V_243 * V_195 = V_174 -> V_230 -> V_231 ;
T_1 V_57 = V_10 -> V_15 ;
unsigned long V_133 , V_206 ;
unsigned long V_222 = 0 ;
int V_251 = ( V_300 -> V_323 ? V_198 : V_191 ) | V_331 ;
int V_70 = 0 ;
F_224 ( V_330 , & V_10 -> V_320 ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_32 ( & V_10 -> V_329 , V_206 ) ;
if ( F_229 ( V_10 ) == V_332 )
V_222 = V_333 ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
struct V_122 * V_59 = F_153 ( V_10 , V_133 ) ;
F_100 ( V_59 ) ;
F_106 ( V_59 ) ;
V_70 = F_179 ( V_251 , V_10 -> V_17 , V_59 , V_57 >> 9 ,
V_142 , 0 , V_195 , & V_300 -> V_40 ,
- 1 , F_227 ,
0 , V_300 -> V_222 , V_222 ) ;
V_300 -> V_222 = V_222 ;
if ( V_70 ) {
F_219 ( V_330 , & V_10 -> V_320 ) ;
F_166 ( V_59 ) ;
if ( F_230 ( V_206 - V_133 , & V_10 -> V_329 ) )
F_223 ( V_10 ) ;
V_70 = - V_188 ;
break;
}
V_57 += V_142 ;
F_202 ( V_59 , V_290 , 1 ) ;
F_113 ( V_59 ) ;
}
if ( F_231 ( V_70 ) ) {
for (; V_133 < V_206 ; V_133 ++ ) {
struct V_122 * V_59 = F_153 ( V_10 , V_133 ) ;
F_113 ( V_59 ) ;
}
}
return V_70 ;
}
int F_232 ( struct V_42 * V_30 ,
struct V_289 * V_290 )
{
struct V_29 * V_17 = & F_134 ( V_30 -> V_31 ) -> V_171 ;
struct V_28 * V_174 = F_134 ( V_30 -> V_31 ) -> V_56 -> V_174 ;
struct V_9 * V_10 , * V_334 = NULL ;
struct V_299 V_300 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_310 = 0 ,
. V_323 = V_290 -> V_306 == V_307 ,
. V_222 = 0 ,
} ;
int V_70 = 0 ;
int V_140 = 0 ;
int V_335 = 0 ;
struct V_336 V_337 ;
int V_132 ;
T_8 V_119 ;
T_8 V_16 ;
int V_338 = 0 ;
int V_339 ;
F_233 ( & V_337 , 0 ) ;
if ( V_290 -> V_293 ) {
V_119 = V_30 -> V_297 ;
V_16 = - 1 ;
} else {
V_119 = V_290 -> V_294 >> V_120 ;
V_16 = V_290 -> V_295 >> V_120 ;
V_338 = 1 ;
}
if ( V_290 -> V_306 == V_307 )
V_339 = V_340 ;
else
V_339 = V_341 ;
V_342:
if ( V_290 -> V_306 == V_307 )
F_234 ( V_30 , V_119 , V_16 ) ;
while ( ! V_140 && ! V_335 && ( V_119 <= V_16 ) &&
( V_132 = F_235 ( & V_337 , V_30 , & V_119 , V_339 ,
F_123 ( V_16 - V_119 , ( T_8 ) V_343 - 1 ) + 1 ) ) ) {
unsigned V_133 ;
V_338 = 1 ;
for ( V_133 = 0 ; V_133 < V_132 ; V_133 ++ ) {
struct V_122 * V_122 = V_337 . V_131 [ V_133 ] ;
if ( ! F_183 ( V_122 ) )
continue;
if ( ! V_290 -> V_293 && V_122 -> V_119 > V_16 ) {
V_140 = 1 ;
break;
}
F_65 ( & V_30 -> V_344 ) ;
if ( ! F_183 ( V_122 ) ) {
F_69 ( & V_30 -> V_344 ) ;
continue;
}
V_10 = (struct V_9 * ) V_122 -> V_51 ;
if ( ! V_10 ) {
F_69 ( & V_30 -> V_344 ) ;
F_37 ( 1 ) ;
continue;
}
if ( V_10 == V_334 ) {
F_69 ( & V_30 -> V_344 ) ;
continue;
}
V_70 = F_236 ( & V_10 -> V_18 ) ;
F_69 ( & V_30 -> V_344 ) ;
if ( ! V_70 )
continue;
V_334 = V_10 ;
V_70 = F_213 ( V_10 , V_174 , & V_300 ) ;
if ( ! V_70 ) {
F_237 ( V_10 ) ;
continue;
}
V_70 = F_228 ( V_10 , V_174 , V_290 , & V_300 ) ;
if ( V_70 ) {
V_140 = 1 ;
F_237 ( V_10 ) ;
break;
}
F_237 ( V_10 ) ;
V_335 = V_290 -> V_292 <= 0 ;
}
F_238 ( & V_337 ) ;
F_70 () ;
}
if ( ! V_338 && ! V_140 ) {
V_338 = 1 ;
V_119 = 0 ;
goto V_342;
}
F_215 ( & V_300 ) ;
return V_70 ;
}
static int F_239 ( struct V_29 * V_17 ,
struct V_42 * V_30 ,
struct V_289 * V_290 ,
T_13 V_345 , void * V_298 ,
void (* F_240)( void * ) )
{
struct V_24 * V_24 = V_30 -> V_31 ;
int V_70 = 0 ;
int V_140 = 0 ;
int V_335 = 0 ;
struct V_336 V_337 ;
int V_132 ;
T_8 V_119 ;
T_8 V_16 ;
int V_338 = 0 ;
int V_339 ;
if ( ! F_241 ( V_24 ) )
return 0 ;
F_233 ( & V_337 , 0 ) ;
if ( V_290 -> V_293 ) {
V_119 = V_30 -> V_297 ;
V_16 = - 1 ;
} else {
V_119 = V_290 -> V_294 >> V_120 ;
V_16 = V_290 -> V_295 >> V_120 ;
V_338 = 1 ;
}
if ( V_290 -> V_306 == V_307 )
V_339 = V_340 ;
else
V_339 = V_341 ;
V_342:
if ( V_290 -> V_306 == V_307 )
F_234 ( V_30 , V_119 , V_16 ) ;
while ( ! V_140 && ! V_335 && ( V_119 <= V_16 ) &&
( V_132 = F_235 ( & V_337 , V_30 , & V_119 , V_339 ,
F_123 ( V_16 - V_119 , ( T_8 ) V_343 - 1 ) + 1 ) ) ) {
unsigned V_133 ;
V_338 = 1 ;
for ( V_133 = 0 ; V_133 < V_132 ; V_133 ++ ) {
struct V_122 * V_122 = V_337 . V_131 [ V_133 ] ;
if ( ! F_222 ( V_122 ) ) {
F_240 ( V_298 ) ;
F_115 ( V_122 ) ;
}
if ( F_231 ( V_122 -> V_30 != V_30 ) ) {
F_113 ( V_122 ) ;
continue;
}
if ( ! V_290 -> V_293 && V_122 -> V_119 > V_16 ) {
V_140 = 1 ;
F_113 ( V_122 ) ;
continue;
}
if ( V_290 -> V_306 != V_346 ) {
if ( F_208 ( V_122 ) )
F_240 ( V_298 ) ;
F_242 ( V_122 ) ;
}
if ( F_208 ( V_122 ) ||
! F_100 ( V_122 ) ) {
F_113 ( V_122 ) ;
continue;
}
V_70 = (* V_345)( V_122 , V_290 , V_298 ) ;
if ( F_231 ( V_70 == V_347 ) ) {
F_113 ( V_122 ) ;
V_70 = 0 ;
}
if ( V_70 )
V_140 = 1 ;
V_335 = V_290 -> V_292 <= 0 ;
}
F_238 ( & V_337 ) ;
F_70 () ;
}
if ( ! V_338 && ! V_140 ) {
V_338 = 1 ;
V_119 = 0 ;
goto V_342;
}
F_243 ( V_24 ) ;
return V_70 ;
}
static void F_244 ( struct V_299 * V_300 )
{
if ( V_300 -> V_40 ) {
int V_251 = V_191 ;
int V_70 ;
if ( V_300 -> V_323 )
V_251 = V_198 ;
V_70 = F_175 ( V_251 , V_300 -> V_40 , 0 , V_300 -> V_222 ) ;
F_67 ( V_70 < 0 ) ;
V_300 -> V_40 = NULL ;
}
}
static T_5 void F_215 ( void * V_298 )
{
struct V_299 * V_300 = V_298 ;
F_244 ( V_300 ) ;
}
int F_245 ( struct V_29 * V_17 , struct V_122 * V_122 ,
T_12 * V_267 ,
struct V_289 * V_290 )
{
int V_70 ;
struct V_299 V_300 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_267 = V_267 ,
. V_310 = 0 ,
. V_323 = V_290 -> V_306 == V_307 ,
. V_222 = 0 ,
} ;
V_70 = F_203 ( V_122 , V_290 , & V_300 ) ;
F_244 ( & V_300 ) ;
return V_70 ;
}
int F_246 ( struct V_29 * V_17 , struct V_24 * V_24 ,
T_1 V_15 , T_1 V_16 , T_12 * V_267 ,
int V_348 )
{
int V_70 = 0 ;
struct V_42 * V_30 = V_24 -> V_123 ;
struct V_122 * V_122 ;
unsigned long V_132 = ( V_16 - V_15 + V_142 ) >>
V_120 ;
struct V_299 V_300 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_267 = V_267 ,
. V_310 = 1 ,
. V_323 = V_348 == V_307 ,
. V_222 = 0 ,
} ;
struct V_289 V_349 = {
. V_306 = V_348 ,
. V_292 = V_132 * 2 ,
. V_294 = V_15 ,
. V_295 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_122 = F_99 ( V_30 , V_15 >> V_120 ) ;
if ( F_100 ( V_122 ) )
V_70 = F_203 ( V_122 , & V_349 , & V_300 ) ;
else {
if ( V_17 -> V_46 && V_17 -> V_46 -> V_234 )
V_17 -> V_46 -> V_234 ( V_122 , V_15 ,
V_15 + V_142 - 1 ,
NULL , 1 ) ;
F_113 ( V_122 ) ;
}
F_101 ( V_122 ) ;
V_15 += V_142 ;
}
F_244 ( & V_300 ) ;
return V_70 ;
}
int F_247 ( struct V_29 * V_17 ,
struct V_42 * V_30 ,
T_12 * V_267 ,
struct V_289 * V_290 )
{
int V_70 = 0 ;
struct V_299 V_300 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_267 = V_267 ,
. V_310 = 0 ,
. V_323 = V_290 -> V_306 == V_307 ,
. V_222 = 0 ,
} ;
V_70 = F_239 ( V_17 , V_30 , V_290 ,
F_203 , & V_300 ,
F_215 ) ;
F_244 ( & V_300 ) ;
return V_70 ;
}
int F_248 ( struct V_29 * V_17 ,
struct V_42 * V_30 ,
struct V_1 * V_131 , unsigned V_132 ,
T_12 V_267 )
{
struct V_40 * V_40 = NULL ;
unsigned V_350 ;
unsigned long V_222 = 0 ;
struct V_122 * V_351 [ 16 ] ;
struct V_122 * V_122 ;
int V_133 = 0 ;
int V_260 = 0 ;
for ( V_350 = 0 ; V_350 < V_132 ; V_350 ++ ) {
V_122 = F_9 ( V_131 -> V_67 , struct V_122 , V_352 ) ;
F_168 ( & V_122 -> V_4 ) ;
F_6 ( & V_122 -> V_352 ) ;
if ( F_249 ( V_122 , V_30 ,
V_122 -> V_119 , V_118 ) ) {
F_101 ( V_122 ) ;
continue;
}
V_351 [ V_260 ++ ] = V_122 ;
if ( V_260 < F_250 ( V_351 ) )
continue;
for ( V_133 = 0 ; V_133 < V_260 ; V_133 ++ ) {
F_188 ( V_17 , V_351 [ V_133 ] , V_267 ,
& V_40 , 0 , & V_222 , V_288 ) ;
F_101 ( V_351 [ V_133 ] ) ;
}
V_260 = 0 ;
}
for ( V_133 = 0 ; V_133 < V_260 ; V_133 ++ ) {
F_188 ( V_17 , V_351 [ V_133 ] , V_267 ,
& V_40 , 0 , & V_222 , V_288 ) ;
F_101 ( V_351 [ V_133 ] ) ;
}
F_67 ( ! F_8 ( V_131 ) ) ;
if ( V_40 )
return F_175 ( V_288 , V_40 , 0 , V_222 ) ;
return 0 ;
}
int F_251 ( struct V_29 * V_17 ,
struct V_122 * V_122 , unsigned long V_57 )
{
struct V_7 * V_92 = NULL ;
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
T_9 V_278 = V_122 -> V_30 -> V_31 -> V_32 -> V_279 ;
V_15 += F_199 ( V_57 , V_278 ) ;
if ( V_15 > V_16 )
return 0 ;
F_93 ( V_17 , V_15 , V_16 , 0 , & V_92 ) ;
F_242 ( V_122 ) ;
F_63 ( V_17 , V_15 , V_16 ,
V_117 | V_88 | V_96 |
V_115 ,
1 , 1 , & V_92 , V_118 ) ;
return 0 ;
}
static int F_252 ( struct V_216 * V_353 ,
struct V_29 * V_17 ,
struct V_122 * V_122 , T_3 V_50 )
{
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
int V_70 = 1 ;
if ( F_118 ( V_17 , V_15 , V_16 ,
V_74 , 0 , NULL ) )
V_70 = 0 ;
else {
if ( ( V_50 & V_118 ) == V_118 )
V_50 = V_118 ;
V_70 = F_63 ( V_17 , V_15 , V_16 ,
~ ( V_117 | V_354 ) ,
0 , 0 , NULL , V_50 ) ;
if ( V_70 < 0 )
V_70 = 0 ;
else
V_70 = 1 ;
}
return V_70 ;
}
int F_253 ( struct V_216 * V_353 ,
struct V_29 * V_17 , struct V_122 * V_122 ,
T_3 V_50 )
{
struct V_214 * V_215 ;
T_1 V_15 = F_128 ( V_122 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
if ( ( V_50 & V_100 ) &&
V_122 -> V_30 -> V_31 -> V_242 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_254 ( & V_353 -> V_48 ) ;
V_215 = F_160 ( V_353 , V_15 , V_21 ) ;
if ( ! V_215 ) {
F_255 ( & V_353 -> V_48 ) ;
break;
}
if ( F_147 ( V_355 , & V_215 -> V_4 ) ||
V_215 -> V_15 != V_15 ) {
F_255 ( & V_353 -> V_48 ) ;
F_162 ( V_215 ) ;
break;
}
if ( ! F_118 ( V_17 , V_215 -> V_15 ,
F_198 ( V_215 ) - 1 ,
V_117 | V_356 ,
0 , NULL ) ) {
F_256 ( V_353 , V_215 ) ;
F_162 ( V_215 ) ;
}
V_15 = F_198 ( V_215 ) ;
F_255 ( & V_353 -> V_48 ) ;
F_162 ( V_215 ) ;
}
}
return F_252 ( V_353 , V_17 , V_122 , V_50 ) ;
}
static struct V_214 * F_257 ( struct V_24 * V_24 ,
T_1 V_57 ,
T_1 V_154 ,
T_12 * V_267 )
{
T_1 V_357 = F_134 ( V_24 ) -> V_56 -> V_357 ;
struct V_214 * V_215 ;
T_1 V_21 ;
if ( V_57 >= V_154 )
return NULL ;
while( 1 ) {
V_21 = V_154 - V_57 ;
if ( V_21 == 0 )
break;
V_21 = F_199 ( V_21 , V_357 ) ;
V_215 = V_267 ( V_24 , NULL , 0 , V_57 , V_21 , 0 ) ;
if ( F_197 ( V_215 ) )
return V_215 ;
if ( ! F_147 ( V_358 , & V_215 -> V_4 ) &&
V_215 -> V_223 != V_286 ) {
return V_215 ;
}
V_57 = F_198 ( V_215 ) ;
F_162 ( V_215 ) ;
if ( V_57 >= V_154 )
break;
}
return NULL ;
}
int F_258 ( struct V_24 * V_24 , struct V_359 * V_360 ,
T_14 V_15 , T_14 V_21 , T_12 * V_267 )
{
int V_70 = 0 ;
T_1 V_361 = V_15 ;
T_1 F_124 = V_15 + V_21 ;
T_6 V_4 = 0 ;
T_6 V_362 ;
T_1 V_154 ;
T_1 V_363 = 0 ;
T_1 V_364 = 0 ;
T_1 V_25 = F_14 ( V_24 ) ;
struct V_365 V_366 ;
struct V_214 * V_215 = NULL ;
struct V_7 * V_92 = NULL ;
struct V_367 * V_368 ;
struct V_369 * V_370 ;
int V_16 = 0 ;
T_1 V_371 = 0 ;
T_1 V_372 = 0 ;
T_1 V_373 = 0 ;
unsigned long V_374 ;
if ( V_21 == 0 )
return - V_375 ;
V_368 = F_259 () ;
if ( ! V_368 )
return - V_35 ;
V_368 -> V_376 = 1 ;
V_15 = F_199 ( V_15 , F_134 ( V_24 ) -> V_56 -> V_357 ) ;
V_21 = F_199 ( V_21 , F_134 ( V_24 ) -> V_56 -> V_357 ) ;
V_70 = F_260 ( NULL , F_134 ( V_24 ) -> V_56 ,
V_368 , F_16 ( V_24 ) , - 1 , 0 ) ;
if ( V_70 < 0 ) {
F_261 ( V_368 ) ;
return V_70 ;
}
F_37 ( ! V_70 ) ;
V_368 -> V_377 [ 0 ] -- ;
V_370 = F_262 ( V_368 -> V_378 [ 0 ] , V_368 -> V_377 [ 0 ] ,
struct V_369 ) ;
F_263 ( V_368 -> V_378 [ 0 ] , & V_366 , V_368 -> V_377 [ 0 ] ) ;
V_362 = F_264 ( & V_366 ) ;
if ( V_366 . V_379 != F_16 ( V_24 ) ||
V_362 != V_380 ) {
V_154 = ( T_1 ) - 1 ;
V_363 = V_25 ;
} else {
V_154 = V_366 . V_57 ;
V_363 = V_154 + 1 ;
}
F_261 ( V_368 ) ;
if ( V_154 < V_25 ) {
V_154 = ( T_1 ) - 1 ;
V_363 = V_25 ;
}
F_93 ( & F_134 ( V_24 ) -> V_171 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_92 ) ;
V_215 = F_257 ( V_24 , V_15 , V_363 ,
V_267 ) ;
if ( ! V_215 )
goto V_102;
if ( F_265 ( V_215 ) ) {
V_70 = F_266 ( V_215 ) ;
goto V_102;
}
while ( ! V_16 ) {
T_1 V_381 = 0 ;
if ( V_215 -> V_15 >= F_124 || F_198 ( V_215 ) < V_361 )
break;
V_371 = F_124 ( V_215 -> V_15 , V_361 ) ;
if ( ! F_147 ( V_224 , & V_215 -> V_4 ) )
V_381 = V_371 - V_215 -> V_15 ;
V_373 = F_198 ( V_215 ) ;
V_372 = V_373 - V_371 ;
V_374 = V_215 -> V_4 ;
V_364 = 0 ;
V_4 = 0 ;
V_361 = F_198 ( V_215 ) ;
if ( V_361 >= F_124 )
V_16 = 1 ;
if ( V_215 -> V_223 == V_382 ) {
V_16 = 1 ;
V_4 |= V_383 ;
} else if ( V_215 -> V_223 == V_287 ) {
V_4 |= ( V_384 |
V_385 ) ;
} else if ( V_215 -> V_223 == V_386 ) {
V_4 |= ( V_387 |
V_388 ) ;
} else {
V_364 = V_215 -> V_223 + V_381 ;
}
if ( F_147 ( V_224 , & V_215 -> V_4 ) )
V_4 |= V_389 ;
F_162 ( V_215 ) ;
V_215 = NULL ;
if ( ( V_371 >= V_154 ) || V_372 == ( T_1 ) - 1 ||
( V_154 == ( T_1 ) - 1 && V_25 <= V_373 ) ) {
V_4 |= V_383 ;
V_16 = 1 ;
}
V_215 = F_257 ( V_24 , V_361 , V_363 ,
V_267 ) ;
if ( F_265 ( V_215 ) ) {
V_70 = F_266 ( V_215 ) ;
goto V_102;
}
if ( ! V_215 ) {
V_4 |= V_383 ;
V_16 = 1 ;
}
V_70 = F_267 ( V_360 , V_371 , V_364 ,
V_372 , V_4 ) ;
if ( V_70 )
goto V_390;
}
V_390:
F_162 ( V_215 ) ;
V_102:
F_96 ( & F_134 ( V_24 ) -> V_171 , V_15 , V_15 + V_21 - 1 ,
& V_92 , V_118 ) ;
return V_70 ;
}
static void F_268 ( struct V_9 * V_10 )
{
F_5 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
static struct V_9 * F_269 ( struct V_29 * V_17 ,
T_1 V_15 ,
unsigned long V_21 ,
T_3 V_50 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_270 ( V_22 , V_50 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_320 = 0 ;
F_271 ( & V_10 -> V_48 ) ;
F_32 ( & V_10 -> V_391 , 0 ) ;
F_32 ( & V_10 -> V_392 , 0 ) ;
F_32 ( & V_10 -> V_393 , 0 ) ;
F_32 ( & V_10 -> V_394 , 0 ) ;
F_32 ( & V_10 -> V_395 , 0 ) ;
F_32 ( & V_10 -> V_396 , 0 ) ;
V_10 -> V_397 = 0 ;
F_33 ( & V_10 -> V_398 ) ;
F_33 ( & V_10 -> V_399 ) ;
F_1 ( & V_10 -> V_13 , & V_20 ) ;
F_29 ( & V_10 -> V_324 ) ;
F_32 ( & V_10 -> V_18 , 1 ) ;
F_32 ( & V_10 -> V_329 , 0 ) ;
F_272 ( V_400
> V_401 ) ;
F_67 ( V_21 > V_401 ) ;
return V_10 ;
}
struct V_9 * F_273 ( struct V_9 * V_402 )
{
unsigned long V_133 ;
struct V_122 * V_59 ;
struct V_9 * V_2 ;
unsigned long V_206 = F_152 ( V_402 -> V_15 , V_402 -> V_21 ) ;
V_2 = F_269 ( NULL , V_402 -> V_15 , V_402 -> V_21 , V_45 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
V_59 = F_274 ( V_45 ) ;
F_67 ( ! V_59 ) ;
F_182 ( V_2 , V_59 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_132 ( V_59 ) ;
V_2 -> V_131 [ V_133 ] = V_59 ;
}
F_275 ( V_2 , V_402 , 0 , 0 , V_402 -> V_21 ) ;
F_219 ( V_403 , & V_2 -> V_320 ) ;
F_219 ( V_404 , & V_2 -> V_320 ) ;
return V_2 ;
}
struct V_9 * F_276 ( T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
unsigned long V_206 = F_152 ( 0 , V_21 ) ;
unsigned long V_133 ;
V_10 = F_269 ( NULL , V_15 , V_21 , V_45 ) ;
if ( ! V_10 )
return NULL ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
V_10 -> V_131 [ V_133 ] = F_274 ( V_45 ) ;
if ( ! V_10 -> V_131 [ V_133 ] )
goto V_90;
}
F_277 ( V_10 ) ;
F_278 ( V_10 , 0 ) ;
F_219 ( V_404 , & V_10 -> V_320 ) ;
return V_10 ;
V_90:
for (; V_133 > 0 ; V_133 -- )
F_279 ( V_10 -> V_131 [ V_133 - 1 ] ) ;
F_268 ( V_10 ) ;
return NULL ;
}
static int F_280 ( struct V_9 * V_10 )
{
return ( F_11 ( & V_10 -> V_329 ) ||
F_147 ( V_321 , & V_10 -> V_320 ) ||
F_147 ( V_325 , & V_10 -> V_320 ) ) ;
}
static void F_281 ( struct V_9 * V_10 ,
unsigned long V_405 )
{
unsigned long V_119 ;
unsigned long V_206 ;
struct V_122 * V_122 ;
int V_406 = ! F_147 ( V_404 , & V_10 -> V_320 ) ;
F_67 ( F_280 ( V_10 ) ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
V_119 = V_405 + V_206 ;
if ( V_405 >= V_119 )
return;
do {
V_119 -- ;
V_122 = F_153 ( V_10 , V_119 ) ;
if ( V_122 && V_406 ) {
F_65 ( & V_122 -> V_30 -> V_344 ) ;
if ( F_183 ( V_122 ) &&
V_122 -> V_51 == ( unsigned long ) V_10 ) {
F_67 ( F_147 ( V_325 , & V_10 -> V_320 ) ) ;
F_67 ( F_116 ( V_122 ) ) ;
F_67 ( F_208 ( V_122 ) ) ;
F_282 ( V_122 ) ;
F_186 ( V_122 , 0 ) ;
F_101 ( V_122 ) ;
}
F_69 ( & V_122 -> V_30 -> V_344 ) ;
}
if ( V_122 ) {
F_101 ( V_122 ) ;
}
} while ( V_119 != V_405 );
}
static inline void F_283 ( struct V_9 * V_10 )
{
F_281 ( V_10 , 0 ) ;
F_268 ( V_10 ) ;
}
static void F_284 ( struct V_9 * V_10 )
{
int V_18 ;
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 >= 2 && F_147 ( V_407 , & V_10 -> V_320 ) )
return;
F_65 ( & V_10 -> V_324 ) ;
if ( ! F_285 ( V_407 , & V_10 -> V_320 ) )
F_77 ( & V_10 -> V_18 ) ;
F_69 ( & V_10 -> V_324 ) ;
}
static void F_286 ( struct V_9 * V_10 )
{
unsigned long V_206 , V_133 ;
F_284 ( V_10 ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
struct V_122 * V_59 = F_153 ( V_10 , V_133 ) ;
F_287 ( V_59 ) ;
}
}
struct V_9 * F_288 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_21 )
{
unsigned long V_206 = F_152 ( V_15 , V_21 ) ;
unsigned long V_133 ;
unsigned long V_119 = V_15 >> V_120 ;
struct V_9 * V_10 ;
struct V_9 * V_408 = NULL ;
struct V_122 * V_59 ;
struct V_42 * V_30 = V_17 -> V_30 ;
int V_233 = 1 ;
int V_70 ;
F_289 () ;
V_10 = F_290 ( & V_17 -> V_44 , V_15 >> V_120 ) ;
if ( V_10 && F_236 ( & V_10 -> V_18 ) ) {
F_291 () ;
F_286 ( V_10 ) ;
return V_10 ;
}
F_291 () ;
V_10 = F_269 ( V_17 , V_15 , V_21 , V_118 ) ;
if ( ! V_10 )
return NULL ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ , V_119 ++ ) {
V_59 = F_292 ( V_30 , V_119 , V_118 ) ;
if ( ! V_59 )
goto V_409;
F_65 ( & V_30 -> V_344 ) ;
if ( F_183 ( V_59 ) ) {
V_408 = (struct V_9 * ) V_59 -> V_51 ;
if ( F_236 ( & V_408 -> V_18 ) ) {
F_69 ( & V_30 -> V_344 ) ;
F_113 ( V_59 ) ;
F_101 ( V_59 ) ;
F_286 ( V_408 ) ;
goto V_409;
}
F_282 ( V_59 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_101 ( V_59 ) ;
}
F_182 ( V_10 , V_59 ) ;
F_69 ( & V_30 -> V_344 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_287 ( V_59 ) ;
V_10 -> V_131 [ V_133 ] = V_59 ;
if ( ! F_189 ( V_59 ) )
V_233 = 0 ;
}
if ( V_233 )
F_219 ( V_403 , & V_10 -> V_320 ) ;
V_99:
V_70 = F_293 ( V_118 & ~ V_410 ) ;
if ( V_70 )
goto V_409;
F_65 ( & V_17 -> V_49 ) ;
V_70 = F_294 ( & V_17 -> V_44 , V_15 >> V_120 , V_10 ) ;
if ( V_70 == - V_80 ) {
V_408 = F_290 ( & V_17 -> V_44 ,
V_15 >> V_120 ) ;
if ( ! F_236 ( & V_408 -> V_18 ) ) {
F_69 ( & V_17 -> V_49 ) ;
F_295 () ;
V_408 = NULL ;
goto V_99;
}
F_69 ( & V_17 -> V_49 ) ;
F_295 () ;
F_286 ( V_408 ) ;
goto V_409;
}
F_284 ( V_10 ) ;
F_69 ( & V_17 -> V_49 ) ;
F_295 () ;
F_296 ( V_10 -> V_131 [ 0 ] ) ;
for ( V_133 = 1 ; V_133 < V_206 ; V_133 ++ ) {
V_59 = F_153 ( V_10 , V_133 ) ;
F_297 ( V_59 ) ;
F_113 ( V_59 ) ;
}
F_113 ( V_10 -> V_131 [ 0 ] ) ;
return V_10 ;
V_409:
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
if ( V_10 -> V_131 [ V_133 ] )
F_113 ( V_10 -> V_131 [ V_133 ] ) ;
}
F_37 ( ! F_36 ( & V_10 -> V_18 ) ) ;
F_283 ( V_10 ) ;
return V_408 ;
}
struct V_9 * F_298 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
F_289 () ;
V_10 = F_290 ( & V_17 -> V_44 , V_15 >> V_120 ) ;
if ( V_10 && F_236 ( & V_10 -> V_18 ) ) {
F_291 () ;
F_286 ( V_10 ) ;
return V_10 ;
}
F_291 () ;
return NULL ;
}
static inline void F_299 ( struct V_411 * V_3 )
{
struct V_9 * V_10 =
F_300 ( V_3 , struct V_9 , V_411 ) ;
F_268 ( V_10 ) ;
}
static int F_301 ( struct V_9 * V_10 )
{
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
if ( F_36 ( & V_10 -> V_18 ) ) {
if ( F_147 ( V_404 , & V_10 -> V_320 ) ) {
F_69 ( & V_10 -> V_324 ) ;
} else {
struct V_29 * V_17 = V_10 -> V_17 ;
F_69 ( & V_10 -> V_324 ) ;
F_65 ( & V_17 -> V_49 ) ;
F_302 ( & V_17 -> V_44 ,
V_10 -> V_15 >> V_120 ) ;
F_69 ( & V_17 -> V_49 ) ;
}
F_281 ( V_10 , 0 ) ;
F_303 ( & V_10 -> V_411 , F_299 ) ;
return 1 ;
}
F_69 ( & V_10 -> V_324 ) ;
return 0 ;
}
void F_237 ( struct V_9 * V_10 )
{
int V_18 ;
int V_412 ;
if ( ! V_10 )
return;
while ( 1 ) {
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 <= 3 )
break;
V_412 = F_304 ( & V_10 -> V_18 , V_18 , V_18 - 1 ) ;
if ( V_412 == V_18 )
return;
}
F_65 ( & V_10 -> V_324 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_147 ( V_404 , & V_10 -> V_320 ) )
F_66 ( & V_10 -> V_18 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_147 ( V_413 , & V_10 -> V_320 ) &&
! F_280 ( V_10 ) &&
F_218 ( V_407 , & V_10 -> V_320 ) )
F_66 ( & V_10 -> V_18 ) ;
F_301 ( V_10 ) ;
}
void F_305 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_65 ( & V_10 -> V_324 ) ;
F_219 ( V_413 , & V_10 -> V_320 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 && ! F_280 ( V_10 ) &&
F_218 ( V_407 , & V_10 -> V_320 ) )
F_66 ( & V_10 -> V_18 ) ;
F_301 ( V_10 ) ;
}
void F_306 ( struct V_9 * V_10 )
{
unsigned long V_133 ;
unsigned long V_206 ;
struct V_122 * V_122 ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
if ( ! F_116 ( V_122 ) )
continue;
F_115 ( V_122 ) ;
F_37 ( ! F_183 ( V_122 ) ) ;
F_100 ( V_122 ) ;
F_307 ( & V_122 -> V_30 -> V_414 ) ;
if ( ! F_116 ( V_122 ) ) {
F_308 ( & V_122 -> V_30 -> V_415 ,
F_309 ( V_122 ) ,
V_341 ) ;
}
F_310 ( & V_122 -> V_30 -> V_414 ) ;
F_206 ( V_122 ) ;
F_113 ( V_122 ) ;
}
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
}
int F_311 ( struct V_9 * V_10 )
{
unsigned long V_133 ;
unsigned long V_206 ;
int V_416 = 0 ;
F_284 ( V_10 ) ;
V_416 = F_285 ( V_325 , & V_10 -> V_320 ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
F_37 ( ! F_147 ( V_407 , & V_10 -> V_320 ) ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ )
F_312 ( F_153 ( V_10 , V_133 ) ) ;
return V_416 ;
}
int F_313 ( struct V_9 * V_10 )
{
unsigned long V_133 ;
struct V_122 * V_122 ;
unsigned long V_206 ;
F_224 ( V_403 , & V_10 -> V_320 ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
if ( V_122 )
F_165 ( V_122 ) ;
}
return 0 ;
}
int F_277 ( struct V_9 * V_10 )
{
unsigned long V_133 ;
struct V_122 * V_122 ;
unsigned long V_206 ;
F_219 ( V_403 , & V_10 -> V_320 ) ;
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = 0 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
F_132 ( V_122 ) ;
}
return 0 ;
}
int F_314 ( struct V_9 * V_10 )
{
return F_147 ( V_403 , & V_10 -> V_320 ) ;
}
int F_315 ( struct V_29 * V_17 ,
struct V_9 * V_10 , T_1 V_15 , int V_104 ,
T_12 * V_267 , int V_177 )
{
unsigned long V_133 ;
unsigned long V_417 ;
struct V_122 * V_122 ;
int V_90 ;
int V_70 = 0 ;
int V_418 = 0 ;
int V_419 = 1 ;
unsigned long V_206 ;
unsigned long V_420 = 0 ;
struct V_40 * V_40 = NULL ;
unsigned long V_222 = 0 ;
if ( F_147 ( V_403 , & V_10 -> V_320 ) )
return 0 ;
if ( V_15 ) {
F_37 ( V_15 < V_10 -> V_15 ) ;
V_417 = ( V_15 >> V_120 ) -
( V_10 -> V_15 >> V_120 ) ;
} else {
V_417 = 0 ;
}
V_206 = F_152 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_133 = V_417 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
if ( V_104 == V_421 ) {
if ( ! F_222 ( V_122 ) )
goto V_422;
} else {
F_115 ( V_122 ) ;
}
V_418 ++ ;
if ( ! F_189 ( V_122 ) ) {
V_420 ++ ;
V_419 = 0 ;
}
}
if ( V_419 ) {
if ( V_417 == 0 )
F_219 ( V_403 , & V_10 -> V_320 ) ;
goto V_422;
}
F_224 ( V_330 , & V_10 -> V_320 ) ;
V_10 -> V_423 = 0 ;
F_32 ( & V_10 -> V_329 , V_420 ) ;
for ( V_133 = V_417 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
if ( ! F_189 ( V_122 ) ) {
F_206 ( V_122 ) ;
V_90 = F_188 ( V_17 , V_122 ,
V_267 , & V_40 ,
V_177 , & V_222 ,
V_288 | V_331 ) ;
if ( V_90 )
V_70 = V_90 ;
} else {
F_113 ( V_122 ) ;
}
}
if ( V_40 ) {
V_90 = F_175 ( V_288 | V_331 , V_40 , V_177 ,
V_222 ) ;
if ( V_90 )
return V_90 ;
}
if ( V_70 || V_104 != V_424 )
return V_70 ;
for ( V_133 = V_417 ; V_133 < V_206 ; V_133 ++ ) {
V_122 = F_153 ( V_10 , V_133 ) ;
F_316 ( V_122 ) ;
if ( ! F_189 ( V_122 ) )
V_70 = - V_188 ;
}
return V_70 ;
V_422:
V_133 = V_417 ;
while ( V_418 > 0 ) {
V_122 = F_153 ( V_10 , V_133 ) ;
V_133 ++ ;
F_113 ( V_122 ) ;
V_418 -- ;
}
return V_70 ;
}
void F_317 ( struct V_9 * V_10 , void * V_425 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_57 ;
struct V_122 * V_122 ;
char * V_426 ;
char * V_427 = ( char * ) V_425 ;
T_9 V_428 = V_10 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_15 ) >> V_120 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_57 = ( V_428 + V_15 ) & ( ( unsigned long ) V_142 - 1 ) ;
while ( V_21 > 0 ) {
V_122 = F_153 ( V_10 , V_133 ) ;
V_269 = F_123 ( V_21 , ( V_142 - V_57 ) ) ;
V_426 = F_318 ( V_122 ) ;
memcpy ( V_427 , V_426 + V_57 , V_269 ) ;
V_427 += V_269 ;
V_21 -= V_269 ;
V_57 = 0 ;
V_133 ++ ;
}
}
int F_319 ( struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_429 , char * * V_353 ,
unsigned long * V_430 ,
unsigned long * V_431 )
{
T_9 V_57 = V_15 & ( V_142 - 1 ) ;
char * V_426 ;
struct V_122 * V_59 ;
T_9 V_428 = V_10 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_15 ) >> V_120 ;
unsigned long V_432 = ( V_428 + V_15 + V_429 - 1 ) >>
V_120 ;
if ( V_133 != V_432 )
return - V_375 ;
if ( V_133 == 0 ) {
V_57 = V_428 ;
* V_430 = 0 ;
} else {
V_57 = 0 ;
* V_430 = ( ( T_1 ) V_133 << V_120 ) - V_428 ;
}
if ( V_15 + V_429 > V_10 -> V_21 ) {
F_53 ( 1 , V_14 L_36
L_37 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_21 , V_15 , V_429 ) ;
return - V_375 ;
}
V_59 = F_153 ( V_10 , V_133 ) ;
V_426 = F_318 ( V_59 ) ;
* V_353 = V_426 + V_57 ;
* V_431 = V_142 - V_57 ;
return 0 ;
}
int F_320 ( struct V_9 * V_10 , const void * V_433 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_57 ;
struct V_122 * V_122 ;
char * V_426 ;
char * V_434 = ( char * ) V_433 ;
T_9 V_428 = V_10 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_15 ) >> V_120 ;
int V_70 = 0 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_57 = ( V_428 + V_15 ) & ( ( unsigned long ) V_142 - 1 ) ;
while ( V_21 > 0 ) {
V_122 = F_153 ( V_10 , V_133 ) ;
V_269 = F_123 ( V_21 , ( V_142 - V_57 ) ) ;
V_426 = F_318 ( V_122 ) ;
V_70 = memcmp ( V_434 , V_426 + V_57 , V_269 ) ;
if ( V_70 )
break;
V_434 += V_269 ;
V_21 -= V_269 ;
V_57 = 0 ;
V_133 ++ ;
}
return V_70 ;
}
void F_321 ( struct V_9 * V_10 , const void * V_435 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_57 ;
struct V_122 * V_122 ;
char * V_426 ;
char * V_402 = ( char * ) V_435 ;
T_9 V_428 = V_10 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_15 ) >> V_120 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_57 = ( V_428 + V_15 ) & ( ( unsigned long ) V_142 - 1 ) ;
while ( V_21 > 0 ) {
V_122 = F_153 ( V_10 , V_133 ) ;
F_37 ( ! F_189 ( V_122 ) ) ;
V_269 = F_123 ( V_21 , V_142 - V_57 ) ;
V_426 = F_318 ( V_122 ) ;
memcpy ( V_426 + V_57 , V_402 , V_269 ) ;
V_402 += V_269 ;
V_21 -= V_269 ;
V_57 = 0 ;
V_133 ++ ;
}
}
void F_322 ( struct V_9 * V_10 , char V_436 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_57 ;
struct V_122 * V_122 ;
char * V_426 ;
T_9 V_428 = V_10 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_15 ) >> V_120 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_57 = ( V_428 + V_15 ) & ( ( unsigned long ) V_142 - 1 ) ;
while ( V_21 > 0 ) {
V_122 = F_153 ( V_10 , V_133 ) ;
F_37 ( ! F_189 ( V_122 ) ) ;
V_269 = F_123 ( V_21 , V_142 - V_57 ) ;
V_426 = F_318 ( V_122 ) ;
memset ( V_426 + V_57 , V_436 , V_269 ) ;
V_21 -= V_269 ;
V_57 = 0 ;
V_133 ++ ;
}
}
void F_275 ( struct V_9 * V_427 , struct V_9 * V_402 ,
unsigned long V_437 , unsigned long V_438 ,
unsigned long V_21 )
{
T_1 V_439 = V_427 -> V_21 ;
T_9 V_269 ;
T_9 V_57 ;
struct V_122 * V_122 ;
char * V_426 ;
T_9 V_428 = V_427 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_133 = ( V_428 + V_437 ) >> V_120 ;
F_37 ( V_402 -> V_21 != V_439 ) ;
V_57 = ( V_428 + V_437 ) &
( ( unsigned long ) V_142 - 1 ) ;
while ( V_21 > 0 ) {
V_122 = F_153 ( V_427 , V_133 ) ;
F_37 ( ! F_189 ( V_122 ) ) ;
V_269 = F_123 ( V_21 , ( unsigned long ) ( V_142 - V_57 ) ) ;
V_426 = F_318 ( V_122 ) ;
F_317 ( V_402 , V_426 + V_57 , V_438 , V_269 ) ;
V_438 += V_269 ;
V_21 -= V_269 ;
V_57 = 0 ;
V_133 ++ ;
}
}
static void F_323 ( struct V_122 * V_440 , struct V_122 * V_441 ,
unsigned long V_442 , unsigned long V_443 ,
unsigned long V_21 )
{
char * V_444 = F_318 ( V_440 ) ;
if ( V_440 == V_441 ) {
memmove ( V_444 + V_442 , V_444 + V_443 , V_21 ) ;
} else {
char * V_445 = F_318 ( V_441 ) ;
char * V_59 = V_444 + V_442 + V_21 ;
char * V_446 = V_445 + V_443 + V_21 ;
while ( V_21 -- )
* -- V_59 = * -- V_446 ;
}
}
static inline bool F_324 ( unsigned long V_402 , unsigned long V_427 , unsigned long V_21 )
{
unsigned long V_447 = ( V_402 > V_427 ) ? V_402 - V_427 : V_427 - V_402 ;
return V_447 < V_21 ;
}
static void F_325 ( struct V_122 * V_440 , struct V_122 * V_441 ,
unsigned long V_442 , unsigned long V_443 ,
unsigned long V_21 )
{
char * V_444 = F_318 ( V_440 ) ;
char * V_445 ;
int V_448 = 0 ;
if ( V_440 != V_441 ) {
V_445 = F_318 ( V_441 ) ;
} else {
V_445 = V_444 ;
if ( F_324 ( V_443 , V_442 , V_21 ) )
V_448 = 1 ;
}
if ( V_448 )
memmove ( V_444 + V_442 , V_445 + V_443 , V_21 ) ;
else
memcpy ( V_444 + V_442 , V_445 + V_443 , V_21 ) ;
}
void F_326 ( struct V_9 * V_427 , unsigned long V_437 ,
unsigned long V_438 , unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_449 ;
T_9 V_450 ;
T_9 V_428 = V_427 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_451 ;
unsigned long V_452 ;
if ( V_438 + V_21 > V_427 -> V_21 ) {
F_10 ( V_14 L_38
L_39 , V_438 , V_21 , V_427 -> V_21 ) ;
F_67 ( 1 ) ;
}
if ( V_437 + V_21 > V_427 -> V_21 ) {
F_10 ( V_14 L_40
L_39 , V_437 , V_21 , V_427 -> V_21 ) ;
F_67 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_449 = ( V_428 + V_437 ) &
( ( unsigned long ) V_142 - 1 ) ;
V_450 = ( V_428 + V_438 ) &
( ( unsigned long ) V_142 - 1 ) ;
V_451 = ( V_428 + V_437 ) >> V_120 ;
V_452 = ( V_428 + V_438 ) >> V_120 ;
V_269 = F_123 ( V_21 , ( unsigned long ) ( V_142 -
V_450 ) ) ;
V_269 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_325 ( F_153 ( V_427 , V_451 ) ,
F_153 ( V_427 , V_452 ) ,
V_449 , V_450 , V_269 ) ;
V_438 += V_269 ;
V_437 += V_269 ;
V_21 -= V_269 ;
}
}
void F_327 ( struct V_9 * V_427 , unsigned long V_437 ,
unsigned long V_438 , unsigned long V_21 )
{
T_9 V_269 ;
T_9 V_449 ;
T_9 V_450 ;
unsigned long V_453 = V_437 + V_21 - 1 ;
unsigned long V_454 = V_438 + V_21 - 1 ;
T_9 V_428 = V_427 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_451 ;
unsigned long V_452 ;
if ( V_438 + V_21 > V_427 -> V_21 ) {
F_10 ( V_14 L_38
L_41 , V_438 , V_21 , V_427 -> V_21 ) ;
F_67 ( 1 ) ;
}
if ( V_437 + V_21 > V_427 -> V_21 ) {
F_10 ( V_14 L_40
L_41 , V_437 , V_21 , V_427 -> V_21 ) ;
F_67 ( 1 ) ;
}
if ( V_437 < V_438 ) {
F_326 ( V_427 , V_437 , V_438 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_451 = ( V_428 + V_453 ) >> V_120 ;
V_452 = ( V_428 + V_454 ) >> V_120 ;
V_449 = ( V_428 + V_453 ) &
( ( unsigned long ) V_142 - 1 ) ;
V_450 = ( V_428 + V_454 ) &
( ( unsigned long ) V_142 - 1 ) ;
V_269 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_269 = F_123 ( V_269 , V_449 + 1 ) ;
F_323 ( F_153 ( V_427 , V_451 ) ,
F_153 ( V_427 , V_452 ) ,
V_449 - V_269 + 1 ,
V_450 - V_269 + 1 , V_269 ) ;
V_453 -= V_269 ;
V_454 -= V_269 ;
V_21 -= V_269 ;
}
}
int F_328 ( struct V_122 * V_122 )
{
struct V_9 * V_10 ;
F_65 ( & V_122 -> V_30 -> V_344 ) ;
if ( ! F_183 ( V_122 ) ) {
F_69 ( & V_122 -> V_30 -> V_344 ) ;
return 1 ;
}
V_10 = (struct V_9 * ) V_122 -> V_51 ;
F_67 ( ! V_10 ) ;
F_65 ( & V_10 -> V_324 ) ;
if ( F_11 ( & V_10 -> V_18 ) != 1 || F_280 ( V_10 ) ) {
F_69 ( & V_10 -> V_324 ) ;
F_69 ( & V_122 -> V_30 -> V_344 ) ;
return 0 ;
}
F_69 ( & V_122 -> V_30 -> V_344 ) ;
if ( ! F_218 ( V_407 , & V_10 -> V_320 ) ) {
F_69 ( & V_10 -> V_324 ) ;
return 0 ;
}
return F_301 ( V_10 ) ;
}
