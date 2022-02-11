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
static inline struct V_23 *
F_13 ( struct V_24 * V_17 )
{
return F_14 ( V_17 -> V_25 -> V_26 -> V_27 ) ;
}
int T_1 F_15 ( void )
{
V_19 = F_16 ( L_5 ,
sizeof( struct V_7 ) , 0 ,
V_28 | V_29 , NULL ) ;
if ( ! V_19 )
return - V_30 ;
V_22 = F_16 ( L_6 ,
sizeof( struct V_9 ) , 0 ,
V_28 | V_29 , NULL ) ;
if ( ! V_22 )
goto V_31;
V_32 = F_17 ( V_33 ,
F_18 ( struct V_34 , V_35 ) ) ;
if ( ! V_32 )
goto V_36;
return 0 ;
V_36:
F_19 ( V_22 ) ;
V_22 = NULL ;
V_31:
F_19 ( V_19 ) ;
V_19 = NULL ;
return - V_30 ;
}
void F_20 ( void )
{
F_7 () ;
F_21 () ;
if ( V_19 )
F_19 ( V_19 ) ;
if ( V_22 )
F_19 ( V_22 ) ;
if ( V_32 )
F_22 ( V_32 ) ;
}
void F_23 ( struct V_24 * V_17 ,
struct V_37 * V_25 )
{
V_17 -> V_8 = V_38 ;
F_24 ( & V_17 -> V_39 , V_40 ) ;
V_17 -> V_41 = NULL ;
V_17 -> V_42 = 0 ;
F_25 ( & V_17 -> V_43 ) ;
F_25 ( & V_17 -> V_44 ) ;
V_17 -> V_25 = V_25 ;
}
static struct V_7 * F_26 ( T_2 V_45 )
{
struct V_7 * V_8 ;
V_8 = F_27 ( V_19 , V_45 ) ;
if ( ! V_8 )
return V_8 ;
V_8 -> V_8 = 0 ;
V_8 -> V_46 = 0 ;
V_8 -> V_17 = NULL ;
F_1 ( & V_8 -> V_13 , & V_11 ) ;
F_28 ( & V_8 -> V_18 , 1 ) ;
F_29 ( & V_8 -> V_47 ) ;
F_30 ( V_8 , V_45 , V_48 ) ;
return V_8 ;
}
void F_31 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return;
if ( F_32 ( & V_8 -> V_18 ) ) {
F_33 ( V_8 -> V_17 ) ;
F_5 ( & V_8 -> V_13 ) ;
F_34 ( V_8 , V_48 ) ;
F_12 ( V_19 , V_8 ) ;
}
}
static struct V_49 * F_35 ( struct V_50 * V_51 , T_3 V_52 ,
struct V_49 * V_53 )
{
struct V_49 * * V_54 = & V_51 -> V_49 ;
struct V_49 * V_55 = NULL ;
struct V_56 * V_6 ;
while ( * V_54 ) {
V_55 = * V_54 ;
V_6 = F_36 ( V_55 , struct V_56 , V_49 ) ;
if ( V_52 < V_6 -> V_15 )
V_54 = & ( * V_54 ) -> V_57 ;
else if ( V_52 > V_6 -> V_16 )
V_54 = & ( * V_54 ) -> V_58 ;
else
return V_55 ;
}
F_37 ( V_53 , V_55 , V_54 ) ;
F_38 ( V_53 , V_51 ) ;
return NULL ;
}
static struct V_49 * F_39 ( struct V_24 * V_17 , T_3 V_52 ,
struct V_49 * * V_59 ,
struct V_49 * * V_60 )
{
struct V_50 * V_51 = & V_17 -> V_8 ;
struct V_49 * V_61 = V_51 -> V_49 ;
struct V_49 * V_62 = NULL ;
struct V_49 * V_63 = NULL ;
struct V_56 * V_6 ;
struct V_56 * V_64 = NULL ;
while ( V_61 ) {
V_6 = F_36 ( V_61 , struct V_56 , V_49 ) ;
V_62 = V_61 ;
V_64 = V_6 ;
if ( V_52 < V_6 -> V_15 )
V_61 = V_61 -> V_57 ;
else if ( V_52 > V_6 -> V_16 )
V_61 = V_61 -> V_58 ;
else
return V_61 ;
}
if ( V_59 ) {
V_63 = V_62 ;
while ( V_62 && V_52 > V_64 -> V_16 ) {
V_62 = F_40 ( V_62 ) ;
V_64 = F_36 ( V_62 , struct V_56 , V_49 ) ;
}
* V_59 = V_62 ;
V_62 = V_63 ;
}
if ( V_60 ) {
V_64 = F_36 ( V_62 , struct V_56 , V_49 ) ;
while ( V_62 && V_52 < V_64 -> V_15 ) {
V_62 = F_41 ( V_62 ) ;
V_64 = F_36 ( V_62 , struct V_56 , V_49 ) ;
}
* V_60 = V_62 ;
}
return NULL ;
}
static inline struct V_49 * F_42 ( struct V_24 * V_17 ,
T_3 V_52 )
{
struct V_49 * V_62 = NULL ;
struct V_49 * V_65 ;
V_65 = F_39 ( V_17 , V_52 , & V_62 , NULL ) ;
if ( ! V_65 )
return V_62 ;
return V_65 ;
}
static void F_43 ( struct V_24 * V_17 , struct V_7 * V_2 ,
struct V_7 * V_66 )
{
if ( V_17 -> V_41 && V_17 -> V_41 -> V_67 )
V_17 -> V_41 -> V_67 ( V_17 -> V_25 -> V_26 , V_2 ,
V_66 ) ;
}
static void F_44 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
{
struct V_7 * V_66 ;
struct V_49 * V_68 ;
if ( V_8 -> V_8 & ( V_69 | V_70 ) )
return;
V_68 = F_41 ( & V_8 -> V_49 ) ;
if ( V_68 ) {
V_66 = F_36 ( V_68 , struct V_7 , V_49 ) ;
if ( V_66 -> V_16 == V_8 -> V_15 - 1 &&
V_66 -> V_8 == V_8 -> V_8 ) {
F_43 ( V_17 , V_8 , V_66 ) ;
V_8 -> V_15 = V_66 -> V_15 ;
V_66 -> V_17 = NULL ;
F_45 ( & V_66 -> V_49 , & V_17 -> V_8 ) ;
F_31 ( V_66 ) ;
}
}
V_68 = F_40 ( & V_8 -> V_49 ) ;
if ( V_68 ) {
V_66 = F_36 ( V_68 , struct V_7 , V_49 ) ;
if ( V_66 -> V_15 == V_8 -> V_16 + 1 &&
V_66 -> V_8 == V_8 -> V_8 ) {
F_43 ( V_17 , V_8 , V_66 ) ;
V_8 -> V_16 = V_66 -> V_16 ;
V_66 -> V_17 = NULL ;
F_45 ( & V_66 -> V_49 , & V_17 -> V_8 ) ;
F_31 ( V_66 ) ;
}
}
}
static void F_46 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_71 )
{
if ( V_17 -> V_41 && V_17 -> V_41 -> V_72 )
V_17 -> V_41 -> V_72 ( V_17 -> V_25 -> V_26 , V_8 , V_71 ) ;
}
static void F_47 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_71 )
{
if ( V_17 -> V_41 && V_17 -> V_41 -> V_73 )
V_17 -> V_41 -> V_73 ( V_17 -> V_25 -> V_26 , V_8 , V_71 ) ;
}
static int F_48 ( struct V_24 * V_17 ,
struct V_7 * V_8 , T_3 V_15 , T_3 V_16 ,
unsigned long * V_71 )
{
struct V_49 * V_53 ;
if ( V_16 < V_15 )
F_49 ( 1 , V_14 L_7 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_15 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
F_50 ( V_17 , V_8 , V_71 ) ;
V_53 = F_35 ( & V_17 -> V_8 , V_16 , & V_8 -> V_49 ) ;
if ( V_53 ) {
struct V_7 * V_74 ;
V_74 = F_36 ( V_53 , struct V_7 , V_49 ) ;
F_10 ( V_14 L_8
L_9 , ( unsigned long long ) V_74 -> V_15 ,
( unsigned long long ) V_74 -> V_16 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 ) ;
return - V_75 ;
}
V_8 -> V_17 = V_17 ;
F_44 ( V_17 , V_8 ) ;
return 0 ;
}
static void F_51 ( struct V_24 * V_17 , struct V_7 * V_76 ,
T_3 V_77 )
{
if ( V_17 -> V_41 && V_17 -> V_41 -> V_78 )
V_17 -> V_41 -> V_78 ( V_17 -> V_25 -> V_26 , V_76 , V_77 ) ;
}
static int F_52 ( struct V_24 * V_17 , struct V_7 * V_76 ,
struct V_7 * V_79 , T_3 V_77 )
{
struct V_49 * V_53 ;
F_51 ( V_17 , V_76 , V_77 ) ;
V_79 -> V_15 = V_76 -> V_15 ;
V_79 -> V_16 = V_77 - 1 ;
V_79 -> V_8 = V_76 -> V_8 ;
V_76 -> V_15 = V_77 ;
V_53 = F_35 ( & V_17 -> V_8 , V_79 -> V_16 , & V_79 -> V_49 ) ;
if ( V_53 ) {
F_31 ( V_79 ) ;
return - V_75 ;
}
V_79 -> V_17 = V_17 ;
return 0 ;
}
static struct V_7 * F_53 ( struct V_7 * V_8 )
{
struct V_49 * V_12 = F_40 ( & V_8 -> V_49 ) ;
if ( V_12 )
return F_36 ( V_12 , struct V_7 , V_49 ) ;
else
return NULL ;
}
static struct V_7 * F_54 ( struct V_24 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_71 , int V_80 )
{
struct V_7 * V_12 ;
unsigned long V_81 = * V_71 & ~ V_82 ;
if ( ( V_81 & V_83 ) && ( V_8 -> V_8 & V_83 ) ) {
T_3 V_84 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
F_33 ( V_84 > V_17 -> V_42 ) ;
V_17 -> V_42 -= V_84 ;
}
F_47 ( V_17 , V_8 , V_71 ) ;
V_8 -> V_8 &= ~ V_81 ;
if ( V_80 )
F_55 ( & V_8 -> V_47 ) ;
if ( V_8 -> V_8 == 0 ) {
V_12 = F_53 ( V_8 ) ;
if ( V_8 -> V_17 ) {
F_45 ( & V_8 -> V_49 , & V_17 -> V_8 ) ;
V_8 -> V_17 = NULL ;
F_31 ( V_8 ) ;
} else {
F_33 ( 1 ) ;
}
} else {
F_44 ( V_17 , V_8 ) ;
V_12 = F_53 ( V_8 ) ;
}
return V_12 ;
}
static struct V_7 *
F_56 ( struct V_7 * V_79 )
{
if ( ! V_79 )
V_79 = F_26 ( V_40 ) ;
return V_79 ;
}
static void F_57 ( struct V_24 * V_17 , int V_85 )
{
F_58 ( F_13 ( V_17 ) , V_85 , L_10
L_11
L_12 ) ;
}
int F_59 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , int V_80 , int V_86 ,
struct V_7 * * V_87 ,
T_2 V_45 )
{
struct V_7 * V_8 ;
struct V_7 * V_88 ;
struct V_7 * V_79 = NULL ;
struct V_49 * V_53 ;
T_3 V_89 ;
int V_85 ;
int V_90 = 0 ;
if ( V_86 )
V_71 |= ~ V_82 ;
V_71 |= V_91 ;
if ( V_71 & ( V_69 | V_70 ) )
V_90 = 1 ;
V_92:
if ( ! V_79 && ( V_45 & V_93 ) ) {
V_79 = F_26 ( V_45 ) ;
if ( ! V_79 )
return - V_30 ;
}
F_60 ( & V_17 -> V_43 ) ;
if ( V_87 ) {
V_88 = * V_87 ;
if ( V_90 ) {
* V_87 = NULL ;
V_87 = NULL ;
}
if ( V_88 && V_88 -> V_17 && V_88 -> V_15 <= V_15 &&
V_88 -> V_16 > V_15 ) {
if ( V_90 )
F_61 ( & V_88 -> V_18 ) ;
V_8 = V_88 ;
goto V_94;
}
if ( V_90 )
F_31 ( V_88 ) ;
}
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 )
goto V_95;
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
V_94:
if ( V_8 -> V_15 > V_16 )
goto V_95;
F_33 ( V_8 -> V_16 < V_15 ) ;
V_89 = V_8 -> V_16 ;
if ( ! ( V_8 -> V_8 & V_71 ) ) {
V_8 = F_53 ( V_8 ) ;
goto V_12;
}
if ( V_8 -> V_15 < V_15 ) {
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_52 ( V_17 , V_8 , V_79 , V_15 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
V_79 = NULL ;
if ( V_85 )
goto V_95;
if ( V_8 -> V_16 <= V_16 ) {
V_8 = F_54 ( V_17 , V_8 , & V_71 , V_80 ) ;
goto V_12;
}
goto V_96;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_52 ( V_17 , V_8 , V_79 , V_16 + 1 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
if ( V_80 )
F_55 ( & V_8 -> V_47 ) ;
F_54 ( V_17 , V_79 , & V_71 , V_80 ) ;
V_79 = NULL ;
goto V_95;
}
V_8 = F_54 ( V_17 , V_8 , & V_71 , V_80 ) ;
V_12:
if ( V_89 == ( T_3 ) - 1 )
goto V_95;
V_15 = V_89 + 1 ;
if ( V_15 <= V_16 && V_8 && ! F_63 () )
goto V_94;
goto V_96;
V_95:
F_64 ( & V_17 -> V_43 ) ;
if ( V_79 )
F_31 ( V_79 ) ;
return 0 ;
V_96:
if ( V_15 > V_16 )
goto V_95;
F_64 ( & V_17 -> V_43 ) ;
if ( V_45 & V_93 )
F_65 () ;
goto V_92;
}
static void F_66 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
__releases( V_17 -> V_43 )
__acquires( V_17 -> V_43 )
{
F_67 ( V_97 ) ;
F_68 ( & V_8 -> V_47 , & V_97 , V_98 ) ;
F_64 ( & V_17 -> V_43 ) ;
F_69 () ;
F_60 ( & V_17 -> V_43 ) ;
F_70 ( & V_8 -> V_47 , & V_97 ) ;
}
static void F_71 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 )
{
struct V_7 * V_8 ;
struct V_49 * V_53 ;
F_60 ( & V_17 -> V_43 ) ;
V_92:
while ( 1 ) {
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 )
break;
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_8 -> V_15 > V_16 )
goto V_95;
if ( V_8 -> V_8 & V_71 ) {
V_15 = V_8 -> V_15 ;
F_72 ( & V_8 -> V_18 ) ;
F_66 ( V_17 , V_8 ) ;
F_31 ( V_8 ) ;
goto V_92;
}
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
F_73 ( & V_17 -> V_43 ) ;
}
V_95:
F_64 ( & V_17 -> V_43 ) ;
}
static void F_50 ( struct V_24 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_71 )
{
unsigned long V_99 = * V_71 & ~ V_82 ;
F_46 ( V_17 , V_8 , V_71 ) ;
if ( ( V_99 & V_83 ) && ! ( V_8 -> V_8 & V_83 ) ) {
T_3 V_84 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
V_17 -> V_42 += V_84 ;
}
V_8 -> V_8 |= V_99 ;
}
static void F_74 ( struct V_7 * V_8 ,
struct V_7 * * V_100 )
{
if ( V_100 && ! ( * V_100 ) ) {
if ( V_8 -> V_8 & ( V_69 | V_70 ) ) {
* V_100 = V_8 ;
F_72 ( & V_8 -> V_18 ) ;
}
}
}
static void F_75 ( struct V_7 * * V_100 )
{
if ( V_100 && ( * V_100 ) ) {
struct V_7 * V_8 = * V_100 ;
* V_100 = NULL ;
F_31 ( V_8 ) ;
}
}
static int T_4
F_76 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , unsigned long V_101 ,
T_3 * V_102 , struct V_7 * * V_87 ,
T_2 V_45 )
{
struct V_7 * V_8 ;
struct V_7 * V_79 = NULL ;
struct V_49 * V_53 ;
int V_85 = 0 ;
T_3 V_103 ;
T_3 V_89 ;
V_71 |= V_91 ;
V_92:
if ( ! V_79 && ( V_45 & V_93 ) ) {
V_79 = F_26 ( V_45 ) ;
F_62 ( ! V_79 ) ;
}
F_60 ( & V_17 -> V_43 ) ;
if ( V_87 && * V_87 ) {
V_8 = * V_87 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_53 = & V_8 -> V_49 ;
goto V_94;
}
}
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 ) {
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_48 ( V_17 , V_79 , V_15 , V_16 , & V_71 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
V_79 = NULL ;
goto V_95;
}
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
V_94:
V_103 = V_8 -> V_15 ;
V_89 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
if ( V_8 -> V_8 & V_101 ) {
* V_102 = V_8 -> V_15 ;
V_85 = - V_75 ;
goto V_95;
}
F_50 ( V_17 , V_8 , & V_71 ) ;
F_74 ( V_8 , V_87 ) ;
F_44 ( V_17 , V_8 ) ;
if ( V_89 == ( T_3 ) - 1 )
goto V_95;
V_15 = V_89 + 1 ;
V_8 = F_53 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_63 () )
goto V_94;
goto V_96;
}
if ( V_8 -> V_15 < V_15 ) {
if ( V_8 -> V_8 & V_101 ) {
* V_102 = V_15 ;
V_85 = - V_75 ;
goto V_95;
}
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_52 ( V_17 , V_8 , V_79 , V_15 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
V_79 = NULL ;
if ( V_85 )
goto V_95;
if ( V_8 -> V_16 <= V_16 ) {
F_50 ( V_17 , V_8 , & V_71 ) ;
F_74 ( V_8 , V_87 ) ;
F_44 ( V_17 , V_8 ) ;
if ( V_89 == ( T_3 ) - 1 )
goto V_95;
V_15 = V_89 + 1 ;
V_8 = F_53 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_63 () )
goto V_94;
}
goto V_96;
}
if ( V_8 -> V_15 > V_15 ) {
T_3 V_104 ;
if ( V_16 < V_103 )
V_104 = V_16 ;
else
V_104 = V_103 - 1 ;
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_48 ( V_17 , V_79 , V_15 , V_104 ,
& V_71 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
F_74 ( V_79 , V_87 ) ;
V_79 = NULL ;
V_15 = V_104 + 1 ;
goto V_96;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
if ( V_8 -> V_8 & V_101 ) {
* V_102 = V_15 ;
V_85 = - V_75 ;
goto V_95;
}
V_79 = F_56 ( V_79 ) ;
F_62 ( ! V_79 ) ;
V_85 = F_52 ( V_17 , V_8 , V_79 , V_16 + 1 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
F_50 ( V_17 , V_79 , & V_71 ) ;
F_74 ( V_79 , V_87 ) ;
F_44 ( V_17 , V_79 ) ;
V_79 = NULL ;
goto V_95;
}
goto V_96;
V_95:
F_64 ( & V_17 -> V_43 ) ;
if ( V_79 )
F_31 ( V_79 ) ;
return V_85 ;
V_96:
if ( V_15 > V_16 )
goto V_95;
F_64 ( & V_17 -> V_43 ) ;
if ( V_45 & V_93 )
F_65 () ;
goto V_92;
}
int F_77 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , T_3 * V_102 ,
struct V_7 * * V_87 , T_2 V_45 )
{
return F_76 ( V_17 , V_15 , V_16 , V_71 , 0 , V_102 ,
V_87 , V_45 ) ;
}
int F_78 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , unsigned long V_105 ,
struct V_7 * * V_87 , T_2 V_45 )
{
struct V_7 * V_8 ;
struct V_7 * V_79 = NULL ;
struct V_49 * V_53 ;
int V_85 = 0 ;
T_3 V_103 ;
T_3 V_89 ;
V_92:
if ( ! V_79 && ( V_45 & V_93 ) ) {
V_79 = F_26 ( V_45 ) ;
if ( ! V_79 )
return - V_30 ;
}
F_60 ( & V_17 -> V_43 ) ;
if ( V_87 && * V_87 ) {
V_8 = * V_87 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_53 = & V_8 -> V_49 ;
goto V_94;
}
}
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 ) {
V_79 = F_56 ( V_79 ) ;
if ( ! V_79 ) {
V_85 = - V_30 ;
goto V_95;
}
V_85 = F_48 ( V_17 , V_79 , V_15 , V_16 , & V_71 ) ;
V_79 = NULL ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
goto V_95;
}
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
V_94:
V_103 = V_8 -> V_15 ;
V_89 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
F_50 ( V_17 , V_8 , & V_71 ) ;
F_74 ( V_8 , V_87 ) ;
V_8 = F_54 ( V_17 , V_8 , & V_105 , 0 ) ;
if ( V_89 == ( T_3 ) - 1 )
goto V_95;
V_15 = V_89 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_63 () )
goto V_94;
goto V_96;
}
if ( V_8 -> V_15 < V_15 ) {
V_79 = F_56 ( V_79 ) ;
if ( ! V_79 ) {
V_85 = - V_30 ;
goto V_95;
}
V_85 = F_52 ( V_17 , V_8 , V_79 , V_15 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
V_79 = NULL ;
if ( V_85 )
goto V_95;
if ( V_8 -> V_16 <= V_16 ) {
F_50 ( V_17 , V_8 , & V_71 ) ;
F_74 ( V_8 , V_87 ) ;
V_8 = F_54 ( V_17 , V_8 , & V_105 , 0 ) ;
if ( V_89 == ( T_3 ) - 1 )
goto V_95;
V_15 = V_89 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_63 () )
goto V_94;
}
goto V_96;
}
if ( V_8 -> V_15 > V_15 ) {
T_3 V_104 ;
if ( V_16 < V_103 )
V_104 = V_16 ;
else
V_104 = V_103 - 1 ;
V_79 = F_56 ( V_79 ) ;
if ( ! V_79 ) {
V_85 = - V_30 ;
goto V_95;
}
V_85 = F_48 ( V_17 , V_79 , V_15 , V_104 ,
& V_71 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
F_74 ( V_79 , V_87 ) ;
V_79 = NULL ;
V_15 = V_104 + 1 ;
goto V_96;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_79 = F_56 ( V_79 ) ;
if ( ! V_79 ) {
V_85 = - V_30 ;
goto V_95;
}
V_85 = F_52 ( V_17 , V_8 , V_79 , V_16 + 1 ) ;
if ( V_85 )
F_57 ( V_17 , V_85 ) ;
F_50 ( V_17 , V_79 , & V_71 ) ;
F_74 ( V_79 , V_87 ) ;
F_54 ( V_17 , V_79 , & V_105 , 0 ) ;
V_79 = NULL ;
goto V_95;
}
goto V_96;
V_95:
F_64 ( & V_17 -> V_43 ) ;
if ( V_79 )
F_31 ( V_79 ) ;
return V_85 ;
V_96:
if ( V_15 > V_16 )
goto V_95;
F_64 ( & V_17 -> V_43 ) ;
if ( V_45 & V_93 )
F_65 () ;
goto V_92;
}
int F_79 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 , V_83 , NULL ,
NULL , V_45 ) ;
}
int F_80 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 , V_71 , NULL ,
NULL , V_45 ) ;
}
int F_81 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , T_2 V_45 )
{
return F_59 ( V_17 , V_15 , V_16 , V_71 , 0 , 0 , NULL , V_45 ) ;
}
int F_82 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_7 * * V_87 , T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 ,
V_106 | V_107 ,
NULL , V_87 , V_45 ) ;
}
int F_83 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_7 * * V_87 , T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 ,
V_106 | V_107 | V_108 ,
NULL , V_87 , V_45 ) ;
}
int F_84 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_45 )
{
return F_59 ( V_17 , V_15 , V_16 ,
V_83 | V_106 |
V_109 , 0 , 0 , NULL , V_45 ) ;
}
int F_85 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 , V_110 , NULL ,
NULL , V_45 ) ;
}
int F_86 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_7 * * V_87 , T_2 V_45 )
{
return F_77 ( V_17 , V_15 , V_16 , V_107 , NULL ,
V_87 , V_45 ) ;
}
int F_87 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_7 * * V_87 , T_2 V_45 )
{
return F_59 ( V_17 , V_15 , V_16 , V_107 , 0 , 0 ,
V_87 , V_45 ) ;
}
int F_88 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , struct V_7 * * V_87 )
{
int V_85 ;
T_3 V_102 ;
while ( 1 ) {
V_85 = F_76 ( V_17 , V_15 , V_16 , V_111 | V_71 ,
V_111 , & V_102 ,
V_87 , V_112 ) ;
if ( V_85 == - V_75 ) {
F_71 ( V_17 , V_102 , V_16 , V_111 ) ;
V_15 = V_102 ;
} else
break;
F_33 ( V_15 > V_16 ) ;
}
return V_85 ;
}
int F_89 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 )
{
return F_88 ( V_17 , V_15 , V_16 , 0 , NULL ) ;
}
int F_90 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 )
{
int V_85 ;
T_3 V_102 ;
V_85 = F_76 ( V_17 , V_15 , V_16 , V_111 , V_111 ,
& V_102 , NULL , V_112 ) ;
if ( V_85 == - V_75 ) {
if ( V_102 > V_15 )
F_59 ( V_17 , V_15 , V_102 - 1 ,
V_111 , 1 , 0 , NULL , V_112 ) ;
return 0 ;
}
return 1 ;
}
int F_91 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_7 * * V_88 , T_2 V_45 )
{
return F_59 ( V_17 , V_15 , V_16 , V_111 , 1 , 0 , V_88 ,
V_45 ) ;
}
int F_92 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 )
{
return F_59 ( V_17 , V_15 , V_16 , V_111 , 1 , 0 , NULL ,
V_112 ) ;
}
int F_93 ( struct V_113 * V_113 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_114 = V_15 >> V_115 ;
unsigned long V_116 = V_16 >> V_115 ;
struct V_117 * V_117 ;
while ( V_114 <= V_116 ) {
V_117 = F_94 ( V_113 -> V_118 , V_114 ) ;
F_62 ( ! V_117 ) ;
F_95 ( V_117 ) ;
F_96 ( V_117 ) ;
V_114 ++ ;
}
return 0 ;
}
int F_97 ( struct V_113 * V_113 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_114 = V_15 >> V_115 ;
unsigned long V_116 = V_16 >> V_115 ;
struct V_117 * V_117 ;
while ( V_114 <= V_116 ) {
V_117 = F_94 ( V_113 -> V_118 , V_114 ) ;
F_62 ( ! V_117 ) ;
F_98 ( V_117 ) ;
F_99 ( V_117 ) ;
F_96 ( V_117 ) ;
V_114 ++ ;
}
return 0 ;
}
static int F_100 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_114 = V_15 >> V_115 ;
unsigned long V_116 = V_16 >> V_115 ;
struct V_117 * V_117 ;
while ( V_114 <= V_116 ) {
V_117 = F_94 ( V_17 -> V_25 , V_114 ) ;
F_62 ( ! V_117 ) ;
F_101 ( V_117 ) ;
F_96 ( V_117 ) ;
V_114 ++ ;
}
return 0 ;
}
static struct V_7 *
F_102 ( struct V_24 * V_17 ,
T_3 V_15 , unsigned long V_71 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 )
goto V_95;
while ( 1 ) {
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_8 -> V_16 >= V_15 && ( V_8 -> V_8 & V_71 ) )
return V_8 ;
V_53 = F_40 ( V_53 ) ;
if ( ! V_53 )
break;
}
V_95:
return NULL ;
}
int F_103 ( struct V_24 * V_17 , T_3 V_15 ,
T_3 * V_119 , T_3 * V_120 , unsigned long V_71 ,
struct V_7 * * V_87 )
{
struct V_7 * V_8 ;
struct V_49 * V_61 ;
int V_65 = 1 ;
F_60 ( & V_17 -> V_43 ) ;
if ( V_87 && * V_87 ) {
V_8 = * V_87 ;
if ( V_8 -> V_16 == V_15 - 1 && V_8 -> V_17 ) {
V_61 = F_40 ( & V_8 -> V_49 ) ;
while ( V_61 ) {
V_8 = F_36 ( V_61 , struct V_7 ,
V_49 ) ;
if ( V_8 -> V_8 & V_71 )
goto V_121;
V_61 = F_40 ( V_61 ) ;
}
F_31 ( * V_87 ) ;
* V_87 = NULL ;
goto V_95;
}
F_31 ( * V_87 ) ;
* V_87 = NULL ;
}
V_8 = F_102 ( V_17 , V_15 , V_71 ) ;
V_121:
if ( V_8 ) {
F_74 ( V_8 , V_87 ) ;
* V_119 = V_8 -> V_15 ;
* V_120 = V_8 -> V_16 ;
V_65 = 0 ;
}
V_95:
F_64 ( & V_17 -> V_43 ) ;
return V_65 ;
}
static T_5 T_3 F_104 ( struct V_24 * V_17 ,
T_3 * V_15 , T_3 * V_16 , T_3 V_122 ,
struct V_7 * * V_87 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
T_3 V_123 = * V_15 ;
T_3 V_74 = 0 ;
T_3 V_124 = 0 ;
F_60 ( & V_17 -> V_43 ) ;
V_53 = F_42 ( V_17 , V_123 ) ;
if ( ! V_53 ) {
if ( ! V_74 )
* V_16 = ( T_3 ) - 1 ;
goto V_95;
}
while ( 1 ) {
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_74 && ( V_8 -> V_15 != V_123 ||
( V_8 -> V_8 & V_70 ) ) ) {
goto V_95;
}
if ( ! ( V_8 -> V_8 & V_106 ) ) {
if ( ! V_74 )
* V_16 = V_8 -> V_16 ;
goto V_95;
}
if ( ! V_74 ) {
* V_15 = V_8 -> V_15 ;
* V_87 = V_8 ;
F_72 ( & V_8 -> V_18 ) ;
}
V_74 ++ ;
* V_16 = V_8 -> V_16 ;
V_123 = V_8 -> V_16 + 1 ;
V_53 = F_40 ( V_53 ) ;
if ( ! V_53 )
break;
V_124 += V_8 -> V_16 - V_8 -> V_15 + 1 ;
if ( V_124 >= V_122 )
break;
}
V_95:
F_64 ( & V_17 -> V_43 ) ;
return V_74 ;
}
static T_5 void F_105 ( struct V_113 * V_113 ,
struct V_117 * V_125 ,
T_3 V_15 , T_3 V_16 )
{
int V_65 ;
struct V_117 * V_126 [ 16 ] ;
unsigned long V_114 = V_15 >> V_115 ;
unsigned long V_116 = V_16 >> V_115 ;
unsigned long V_127 = V_116 - V_114 + 1 ;
int V_128 ;
if ( V_114 == V_125 -> V_114 && V_116 == V_114 )
return;
while ( V_127 > 0 ) {
V_65 = F_106 ( V_113 -> V_118 , V_114 ,
F_107 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_126 ) ;
for ( V_128 = 0 ; V_128 < V_65 ; V_128 ++ ) {
if ( V_126 [ V_128 ] != V_125 )
F_108 ( V_126 [ V_128 ] ) ;
F_96 ( V_126 [ V_128 ] ) ;
}
V_127 -= V_65 ;
V_114 += V_65 ;
F_65 () ;
}
}
static T_5 int F_109 ( struct V_113 * V_113 ,
struct V_117 * V_125 ,
T_3 V_129 ,
T_3 V_130 )
{
unsigned long V_114 = V_129 >> V_115 ;
unsigned long V_131 = V_114 ;
unsigned long V_116 = V_130 >> V_115 ;
unsigned long V_132 = 0 ;
struct V_117 * V_126 [ 16 ] ;
unsigned long V_133 ;
int V_65 ;
int V_128 ;
if ( V_114 == V_125 -> V_114 && V_114 == V_116 )
return 0 ;
V_133 = V_116 - V_114 + 1 ;
while ( V_133 > 0 ) {
V_65 = F_106 ( V_113 -> V_118 , V_114 ,
F_107 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_126 ) ;
if ( V_65 == 0 ) {
V_65 = - V_134 ;
goto V_135;
}
for ( V_128 = 0 ; V_128 < V_65 ; V_128 ++ ) {
if ( V_126 [ V_128 ] != V_125 ) {
F_110 ( V_126 [ V_128 ] ) ;
if ( ! F_111 ( V_126 [ V_128 ] ) ||
V_126 [ V_128 ] -> V_25 != V_113 -> V_118 ) {
V_65 = - V_134 ;
F_108 ( V_126 [ V_128 ] ) ;
F_96 ( V_126 [ V_128 ] ) ;
goto V_135;
}
}
F_96 ( V_126 [ V_128 ] ) ;
V_132 ++ ;
}
V_133 -= V_65 ;
V_114 += V_65 ;
F_65 () ;
}
V_65 = 0 ;
V_135:
if ( V_65 && V_132 ) {
F_105 ( V_113 , V_125 ,
V_129 ,
( ( T_3 ) ( V_131 + V_132 - 1 ) ) <<
V_115 ) ;
}
return V_65 ;
}
static T_5 T_3 F_112 ( struct V_113 * V_113 ,
struct V_24 * V_17 ,
struct V_117 * V_125 ,
T_3 * V_15 , T_3 * V_16 ,
T_3 V_122 )
{
T_3 V_129 ;
T_3 V_130 ;
T_3 V_74 ;
struct V_7 * V_87 = NULL ;
int V_65 ;
int V_136 = 0 ;
V_92:
V_129 = * V_15 ;
V_130 = 0 ;
V_74 = F_104 ( V_17 , & V_129 , & V_130 ,
V_122 , & V_87 ) ;
if ( ! V_74 || V_130 <= * V_15 ) {
* V_15 = V_129 ;
* V_16 = V_130 ;
F_31 ( V_87 ) ;
return V_74 ;
}
if ( V_129 < * V_15 )
V_129 = * V_15 ;
if ( V_130 + 1 - V_129 > V_122 && V_136 )
V_130 = V_129 + V_137 - 1 ;
V_65 = F_109 ( V_113 , V_125 ,
V_129 , V_130 ) ;
if ( V_65 == - V_134 ) {
F_31 ( V_87 ) ;
if ( ! V_136 ) {
unsigned long V_52 = ( * V_15 ) & ( V_137 - 1 ) ;
V_122 = V_137 - V_52 ;
V_136 = 1 ;
goto V_92;
} else {
V_74 = 0 ;
goto V_138;
}
}
F_62 ( V_65 ) ;
F_88 ( V_17 , V_129 , V_130 , 0 , & V_87 ) ;
V_65 = F_113 ( V_17 , V_129 , V_130 ,
V_106 , 1 , V_87 ) ;
if ( ! V_65 ) {
F_91 ( V_17 , V_129 , V_130 ,
& V_87 , V_112 ) ;
F_105 ( V_113 , V_125 ,
V_129 , V_130 ) ;
F_65 () ;
goto V_92;
}
F_31 ( V_87 ) ;
* V_15 = V_129 ;
* V_16 = V_130 ;
V_138:
return V_74 ;
}
int F_114 ( struct V_113 * V_113 ,
struct V_24 * V_17 ,
T_3 V_15 , T_3 V_16 , struct V_117 * V_125 ,
unsigned long V_139 )
{
int V_65 ;
struct V_117 * V_126 [ 16 ] ;
unsigned long V_114 = V_15 >> V_115 ;
unsigned long V_116 = V_16 >> V_115 ;
unsigned long V_127 = V_116 - V_114 + 1 ;
int V_128 ;
unsigned long V_105 = 0 ;
if ( V_139 & V_140 )
V_105 |= V_111 ;
if ( V_139 & V_141 )
V_105 |= V_83 ;
if ( V_139 & V_142 )
V_105 |= V_106 ;
F_59 ( V_17 , V_15 , V_16 , V_105 , 1 , 0 , NULL , V_112 ) ;
if ( ! ( V_139 & ( V_143 | V_141 |
V_144 | V_145 |
V_146 ) ) )
return 0 ;
while ( V_127 > 0 ) {
V_65 = F_106 ( V_113 -> V_118 , V_114 ,
F_107 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_126 ) ;
for ( V_128 = 0 ; V_128 < V_65 ; V_128 ++ ) {
if ( V_139 & V_146 )
F_115 ( V_126 [ V_128 ] ) ;
if ( V_126 [ V_128 ] == V_125 ) {
F_96 ( V_126 [ V_128 ] ) ;
continue;
}
if ( V_139 & V_141 )
F_95 ( V_126 [ V_128 ] ) ;
if ( V_139 & V_144 )
F_101 ( V_126 [ V_128 ] ) ;
if ( V_139 & V_145 )
F_116 ( V_126 [ V_128 ] ) ;
if ( V_139 & V_143 )
F_108 ( V_126 [ V_128 ] ) ;
F_96 ( V_126 [ V_128 ] ) ;
}
V_127 -= V_65 ;
V_114 += V_65 ;
F_65 () ;
}
return 0 ;
}
T_3 F_117 ( struct V_24 * V_17 ,
T_3 * V_15 , T_3 V_147 , T_3 V_122 ,
unsigned long V_71 , int V_148 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
T_3 V_123 = * V_15 ;
T_3 V_124 = 0 ;
T_3 V_149 = 0 ;
int V_74 = 0 ;
if ( V_147 <= V_123 ) {
F_33 ( 1 ) ;
return 0 ;
}
F_60 ( & V_17 -> V_43 ) ;
if ( V_123 == 0 && V_71 == V_83 ) {
V_124 = V_17 -> V_42 ;
goto V_95;
}
V_53 = F_42 ( V_17 , V_123 ) ;
if ( ! V_53 )
goto V_95;
while ( 1 ) {
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_8 -> V_15 > V_147 )
break;
if ( V_148 && V_74 && V_8 -> V_15 > V_149 + 1 )
break;
if ( V_8 -> V_16 >= V_123 && ( V_8 -> V_8 & V_71 ) == V_71 ) {
V_124 += F_118 ( V_147 , V_8 -> V_16 ) + 1 -
F_119 ( V_123 , V_8 -> V_15 ) ;
if ( V_124 >= V_122 )
break;
if ( ! V_74 ) {
* V_15 = F_119 ( V_123 , V_8 -> V_15 ) ;
V_74 = 1 ;
}
V_149 = V_8 -> V_16 ;
} else if ( V_148 && V_74 ) {
break;
}
V_53 = F_40 ( V_53 ) ;
if ( ! V_53 )
break;
}
V_95:
F_64 ( & V_17 -> V_43 ) ;
return V_124 ;
}
int F_120 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_46 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
int V_65 = 0 ;
F_60 ( & V_17 -> V_43 ) ;
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 ) {
V_65 = - V_150 ;
goto V_95;
}
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_65 = - V_150 ;
goto V_95;
}
V_8 -> V_46 = V_46 ;
V_95:
F_64 ( & V_17 -> V_43 ) ;
return V_65 ;
}
void F_121 ( struct V_24 * V_17 , T_3 V_15 , T_6 V_151 [] ,
int V_152 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
F_60 ( & V_17 -> V_43 ) ;
V_53 = F_42 ( V_17 , V_15 ) ;
F_62 ( ! V_53 ) ;
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
F_62 ( V_8 -> V_15 != V_15 ) ;
while ( V_152 ) {
V_8 -> V_46 = * V_151 ++ ;
V_152 -- ;
V_8 = F_53 ( V_8 ) ;
}
F_64 ( & V_17 -> V_43 ) ;
}
static inline T_3 F_122 ( struct V_35 * V_35 , int V_153 )
{
struct V_154 * V_155 = V_35 -> V_156 + V_153 ;
return F_123 ( V_155 -> V_157 ) + V_155 -> V_158 ;
}
void F_124 ( struct V_24 * V_17 , struct V_35 * V_35 , int V_153 ,
T_6 V_151 [] , int V_152 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 = NULL ;
T_3 V_15 ;
F_60 ( & V_17 -> V_43 ) ;
do {
V_15 = F_122 ( V_35 , V_153 ) ;
if ( V_8 == NULL || V_8 -> V_15 != V_15 ) {
V_53 = F_42 ( V_17 , V_15 ) ;
F_62 ( ! V_53 ) ;
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
F_62 ( V_8 -> V_15 != V_15 ) ;
}
V_8 -> V_46 = * V_151 ++ ;
V_152 -- ;
V_153 ++ ;
V_8 = F_53 ( V_8 ) ;
} while ( V_152 );
F_64 ( & V_17 -> V_43 ) ;
}
int F_125 ( struct V_24 * V_17 , T_3 V_15 , T_3 * V_46 )
{
struct V_49 * V_53 ;
struct V_7 * V_8 ;
int V_65 = 0 ;
F_60 ( & V_17 -> V_43 ) ;
V_53 = F_42 ( V_17 , V_15 ) ;
if ( ! V_53 ) {
V_65 = - V_150 ;
goto V_95;
}
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_65 = - V_150 ;
goto V_95;
}
* V_46 = V_8 -> V_46 ;
V_95:
F_64 ( & V_17 -> V_43 ) ;
return V_65 ;
}
int F_113 ( struct V_24 * V_17 , T_3 V_15 , T_3 V_16 ,
unsigned long V_71 , int V_159 , struct V_7 * V_88 )
{
struct V_7 * V_8 = NULL ;
struct V_49 * V_53 ;
int V_160 = 0 ;
F_60 ( & V_17 -> V_43 ) ;
if ( V_88 && V_88 -> V_17 && V_88 -> V_15 <= V_15 &&
V_88 -> V_16 > V_15 )
V_53 = & V_88 -> V_49 ;
else
V_53 = F_42 ( V_17 , V_15 ) ;
while ( V_53 && V_15 <= V_16 ) {
V_8 = F_36 ( V_53 , struct V_7 , V_49 ) ;
if ( V_159 && V_8 -> V_15 > V_15 ) {
V_160 = 0 ;
break;
}
if ( V_8 -> V_15 > V_16 )
break;
if ( V_8 -> V_8 & V_71 ) {
V_160 = 1 ;
if ( ! V_159 )
break;
} else if ( V_159 ) {
V_160 = 0 ;
break;
}
if ( V_8 -> V_16 == ( T_3 ) - 1 )
break;
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_53 = F_40 ( V_53 ) ;
if ( ! V_53 ) {
if ( V_159 )
V_160 = 0 ;
break;
}
}
F_64 ( & V_17 -> V_43 ) ;
return V_160 ;
}
static void F_126 ( struct V_24 * V_17 , struct V_117 * V_117 )
{
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_16 = V_15 + V_137 - 1 ;
if ( F_113 ( V_17 , V_15 , V_16 , V_107 , 1 , NULL ) )
F_127 ( V_117 ) ;
}
static int F_128 ( struct V_113 * V_113 , struct V_161 * V_162 ,
int V_163 )
{
int V_65 ;
int V_85 = 0 ;
struct V_24 * V_164 = & F_129 ( V_113 ) -> V_165 ;
F_120 ( V_164 , V_162 -> V_15 , 0 ) ;
V_65 = F_81 ( V_164 , V_162 -> V_15 ,
V_162 -> V_15 + V_162 -> V_21 - 1 ,
V_111 | V_83 , V_112 ) ;
if ( V_65 )
V_85 = V_65 ;
V_65 = F_81 ( & F_129 ( V_113 ) -> V_166 , V_162 -> V_15 ,
V_162 -> V_15 + V_162 -> V_21 - 1 ,
V_167 , V_112 ) ;
if ( V_65 && ! V_85 )
V_85 = V_65 ;
F_130 ( V_162 ) ;
return V_85 ;
}
static void F_131 ( struct V_35 * V_35 , int V_85 )
{
F_132 ( V_35 -> V_168 ) ;
}
int F_133 ( struct V_23 * V_169 , T_3 V_15 ,
T_3 V_170 , T_3 V_171 , struct V_117 * V_117 ,
int V_172 )
{
struct V_35 * V_35 ;
struct V_173 * V_174 ;
F_134 ( V_175 ) ;
T_3 V_176 = 0 ;
T_3 V_177 ;
struct V_178 * V_179 = NULL ;
struct V_180 * V_181 = & V_169 -> V_182 ;
int V_65 ;
F_62 ( ! V_172 ) ;
if ( F_135 ( V_181 , V_171 , V_170 , V_172 ) )
return 0 ;
V_35 = F_136 ( V_112 , 1 ) ;
if ( ! V_35 )
return - V_183 ;
V_35 -> V_168 = & V_175 ;
V_35 -> V_184 = F_131 ;
V_35 -> V_185 = 0 ;
V_176 = V_170 ;
V_65 = F_137 ( V_169 , V_186 , V_171 ,
& V_176 , & V_179 , V_172 ) ;
if ( V_65 ) {
F_138 ( V_35 ) ;
return - V_183 ;
}
F_62 ( V_172 != V_179 -> V_172 ) ;
V_177 = V_179 -> V_187 [ V_172 - 1 ] . V_188 >> 9 ;
V_35 -> V_189 = V_177 ;
V_174 = V_179 -> V_187 [ V_172 - 1 ] . V_174 ;
F_130 ( V_179 ) ;
if ( ! V_174 || ! V_174 -> V_190 || ! V_174 -> V_191 ) {
F_138 ( V_35 ) ;
return - V_183 ;
}
V_35 -> V_192 = V_174 -> V_190 ;
F_139 ( V_35 , V_117 , V_170 , V_15 - F_123 ( V_117 ) ) ;
F_140 ( V_193 , V_35 ) ;
F_141 ( & V_175 ) ;
if ( ! F_142 ( V_194 , & V_35 -> V_195 ) ) {
F_138 ( V_35 ) ;
F_143 ( V_174 , V_196 ) ;
return - V_183 ;
}
F_144 ( V_197 L_13
L_14 , V_117 -> V_25 -> V_26 -> V_198 ,
V_15 , F_145 ( V_174 -> V_199 ) , V_177 ) ;
F_138 ( V_35 ) ;
return 0 ;
}
int F_146 ( struct V_200 * V_51 , struct V_9 * V_10 ,
int V_172 )
{
T_3 V_15 = V_10 -> V_15 ;
unsigned long V_128 , V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
int V_65 = 0 ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
struct V_117 * V_54 = F_148 ( V_10 , V_128 ) ;
V_65 = F_133 ( V_51 -> V_169 , V_15 , V_137 ,
V_15 , V_54 , V_172 ) ;
if ( V_65 )
break;
V_15 += V_137 ;
}
return V_65 ;
}
static int F_149 ( T_3 V_15 , struct V_117 * V_117 )
{
T_3 V_46 ;
T_3 V_202 ;
struct V_161 * V_203 ;
struct V_23 * V_169 ;
struct V_7 * V_8 ;
int V_204 ;
int V_163 = 0 ;
int V_65 ;
struct V_113 * V_113 = V_117 -> V_25 -> V_26 ;
V_46 = 0 ;
V_65 = F_117 ( & F_129 ( V_113 ) -> V_165 , & V_46 ,
( T_3 ) - 1 , 1 , V_83 , 0 ) ;
if ( ! V_65 )
return 0 ;
V_65 = F_125 ( & F_129 ( V_113 ) -> V_165 , V_15 ,
& V_202 ) ;
if ( V_65 )
return 0 ;
V_203 = (struct V_161 * ) ( unsigned long ) V_202 ;
F_62 ( ! V_203 -> V_205 ) ;
if ( V_203 -> V_206 ) {
F_150 ( L_15 ,
V_203 -> V_15 ) ;
V_163 = 1 ;
goto V_95;
}
F_60 ( & F_129 ( V_113 ) -> V_166 . V_43 ) ;
V_8 = F_102 ( & F_129 ( V_113 ) -> V_166 ,
V_203 -> V_15 ,
V_111 ) ;
F_64 ( & F_129 ( V_113 ) -> V_166 . V_43 ) ;
if ( V_8 && V_8 -> V_15 == V_203 -> V_15 ) {
V_169 = F_129 ( V_113 ) -> V_51 -> V_169 ;
V_204 = F_151 ( V_169 , V_203 -> V_171 ,
V_203 -> V_21 ) ;
if ( V_204 > 1 ) {
V_65 = F_133 ( V_169 , V_15 , V_203 -> V_21 ,
V_203 -> V_171 , V_117 ,
V_203 -> V_207 ) ;
V_163 = ! V_65 ;
}
V_65 = 0 ;
}
V_95:
if ( ! V_65 )
V_65 = F_128 ( V_113 , V_203 , V_163 ) ;
return V_65 ;
}
static int F_152 ( struct V_35 * V_208 , struct V_117 * V_117 ,
T_3 V_15 , T_3 V_16 , int V_207 ,
struct V_7 * V_8 )
{
struct V_161 * V_203 = NULL ;
T_3 V_46 ;
struct V_209 * V_210 ;
struct V_113 * V_113 = V_117 -> V_25 -> V_26 ;
struct V_24 * V_164 = & F_129 ( V_113 ) -> V_165 ;
struct V_24 * V_17 = & F_129 ( V_113 ) -> V_166 ;
struct V_211 * V_212 = & F_129 ( V_113 ) -> V_213 ;
struct V_35 * V_35 ;
int V_204 ;
int V_65 ;
int V_214 ;
T_3 V_171 ;
F_62 ( V_208 -> V_215 & V_216 ) ;
V_65 = F_125 ( V_164 , V_15 , & V_46 ) ;
if ( V_65 ) {
V_203 = F_153 ( sizeof( * V_203 ) , V_112 ) ;
if ( ! V_203 )
return - V_30 ;
V_203 -> V_15 = V_15 ;
V_203 -> V_21 = V_16 - V_15 + 1 ;
V_203 -> V_205 = 0 ;
V_203 -> V_217 = 0 ;
V_203 -> V_206 = 0 ;
F_154 ( & V_212 -> V_43 ) ;
V_210 = F_155 ( V_212 , V_15 , V_203 -> V_21 ) ;
if ( ! V_210 ) {
F_156 ( & V_212 -> V_43 ) ;
F_130 ( V_203 ) ;
return - V_183 ;
}
if ( V_210 -> V_15 > V_15 || V_210 -> V_15 + V_210 -> V_21 < V_15 ) {
F_157 ( V_210 ) ;
V_210 = NULL ;
}
F_156 ( & V_212 -> V_43 ) ;
if ( ! V_210 ) {
F_130 ( V_203 ) ;
return - V_183 ;
}
V_171 = V_15 - V_210 -> V_15 ;
V_171 = V_210 -> V_218 + V_171 ;
if ( F_142 ( V_219 , & V_210 -> V_4 ) ) {
V_171 = V_210 -> V_218 ;
V_203 -> V_217 = V_220 ;
F_158 ( & V_203 -> V_217 ,
V_210 -> V_221 ) ;
}
F_150 ( L_16
L_17 , V_171 , V_15 , V_203 -> V_21 ) ;
V_203 -> V_171 = V_171 ;
F_157 ( V_210 ) ;
V_65 = F_80 ( V_164 , V_15 , V_16 ,
V_111 | V_83 , V_112 ) ;
if ( V_65 >= 0 )
V_65 = F_120 ( V_164 , V_15 ,
( T_3 ) ( unsigned long ) V_203 ) ;
if ( V_65 >= 0 )
V_65 = F_80 ( V_17 , V_15 , V_16 , V_167 ,
V_112 ) ;
if ( V_65 < 0 ) {
F_130 ( V_203 ) ;
return V_65 ;
}
} else {
V_203 = (struct V_161 * ) ( unsigned long ) V_46 ;
F_150 ( L_18
L_19 ,
V_203 -> V_171 , V_203 -> V_15 , V_203 -> V_21 ,
V_203 -> V_206 ) ;
}
V_204 = F_151 ( F_129 ( V_113 ) -> V_51 -> V_169 ,
V_203 -> V_171 , V_203 -> V_21 ) ;
if ( V_204 == 1 ) {
F_150 ( L_20
L_21
L_22 , V_8 , V_204 ,
V_203 -> V_205 , V_207 ) ;
F_128 ( V_113 , V_203 , 0 ) ;
return - V_183 ;
}
if ( ! V_8 ) {
F_60 ( & V_17 -> V_43 ) ;
V_8 = F_102 ( V_17 , V_203 -> V_15 ,
V_111 ) ;
if ( V_8 && V_8 -> V_15 != V_203 -> V_15 )
V_8 = NULL ;
F_64 ( & V_17 -> V_43 ) ;
}
if ( V_208 -> V_222 > 1 ) {
F_62 ( V_203 -> V_206 ) ;
V_203 -> V_206 = 1 ;
V_203 -> V_205 = V_207 ;
V_214 = V_223 | V_224 ;
} else {
if ( V_203 -> V_206 ) {
F_62 ( V_203 -> V_205 != V_207 ) ;
V_203 -> V_206 = 0 ;
V_203 -> V_205 = 0 ;
}
V_203 -> V_207 = V_207 ;
V_203 -> V_205 ++ ;
if ( V_203 -> V_205 == V_207 )
V_203 -> V_205 ++ ;
V_214 = V_223 ;
}
if ( ! V_8 || V_203 -> V_205 > V_204 ) {
F_150 ( L_23
L_24 , V_8 ,
V_204 , V_203 -> V_205 , V_207 ) ;
F_128 ( V_113 , V_203 , 0 ) ;
return - V_183 ;
}
V_35 = F_136 ( V_112 , 1 ) ;
if ( ! V_35 ) {
F_128 ( V_113 , V_203 , 0 ) ;
return - V_183 ;
}
V_35 -> V_168 = V_8 ;
V_35 -> V_184 = V_208 -> V_184 ;
V_35 -> V_189 = V_203 -> V_171 >> 9 ;
V_35 -> V_192 = F_129 ( V_113 ) -> V_51 -> V_169 -> V_225 -> V_226 ;
V_35 -> V_185 = 0 ;
F_139 ( V_35 , V_117 , V_203 -> V_21 , V_15 - F_123 ( V_117 ) ) ;
F_150 ( L_25
L_26 , V_214 ,
V_203 -> V_205 , V_204 , V_203 -> V_206 ) ;
V_65 = V_17 -> V_41 -> V_227 ( V_113 , V_214 , V_35 ,
V_203 -> V_205 ,
V_203 -> V_217 , 0 ) ;
return V_65 ;
}
int F_159 ( struct V_117 * V_117 , int V_85 , T_3 V_15 , T_3 V_16 )
{
int V_228 = ( V_85 == 0 ) ;
struct V_24 * V_17 ;
int V_65 ;
V_17 = & F_129 ( V_117 -> V_25 -> V_26 ) -> V_166 ;
if ( V_17 -> V_41 && V_17 -> V_41 -> V_229 ) {
V_65 = V_17 -> V_41 -> V_229 ( V_117 , V_15 ,
V_16 , NULL , V_228 ) ;
if ( V_65 )
V_228 = 0 ;
}
if ( ! V_228 ) {
F_160 ( V_117 ) ;
F_161 ( V_117 ) ;
}
return 0 ;
}
static void F_162 ( struct V_35 * V_35 , int V_85 )
{
struct V_154 * V_155 = V_35 -> V_156 + V_35 -> V_222 - 1 ;
struct V_24 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
do {
struct V_117 * V_117 = V_155 -> V_157 ;
V_17 = & F_129 ( V_117 -> V_25 -> V_26 ) -> V_166 ;
if ( V_155 -> V_158 || V_155 -> V_230 != V_137 )
F_10 ( L_27 ,
V_155 -> V_158 + V_155 -> V_230 != V_137
? V_14 L_28 : V_197 L_29 ,
V_155 -> V_158 , V_155 -> V_230 ) ;
V_15 = F_123 ( V_117 ) ;
V_16 = V_15 + V_155 -> V_158 + V_155 -> V_230 - 1 ;
if ( -- V_155 >= V_35 -> V_156 )
F_163 ( & V_155 -> V_157 -> V_4 ) ;
if ( F_159 ( V_117 , V_85 , V_15 , V_16 ) )
continue;
F_116 ( V_117 ) ;
} while ( V_155 >= V_35 -> V_156 );
F_138 ( V_35 ) ;
}
static void F_164 ( struct V_35 * V_35 , int V_85 )
{
int V_228 = F_142 ( V_194 , & V_35 -> V_195 ) ;
struct V_154 * V_231 = V_35 -> V_156 + V_35 -> V_222 - 1 ;
struct V_154 * V_155 = V_35 -> V_156 ;
struct V_24 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_232 ;
int V_65 ;
if ( V_85 )
V_228 = 0 ;
do {
struct V_117 * V_117 = V_155 -> V_157 ;
struct V_7 * V_88 = NULL ;
struct V_7 * V_8 ;
struct V_34 * V_233 = V_34 ( V_35 ) ;
F_150 ( L_30
L_31 , ( T_3 ) V_35 -> V_189 , V_85 ,
V_233 -> V_172 ) ;
V_17 = & F_129 ( V_117 -> V_25 -> V_26 ) -> V_166 ;
if ( V_155 -> V_158 || V_155 -> V_230 != V_137 )
F_10 ( L_32 ,
V_155 -> V_158 + V_155 -> V_230 != V_137
? V_14 L_28 : V_197 L_29 ,
V_155 -> V_158 , V_155 -> V_230 ) ;
V_15 = F_123 ( V_117 ) ;
V_16 = V_15 + V_155 -> V_158 + V_155 -> V_230 - 1 ;
if ( ++ V_155 <= V_231 )
F_163 ( & V_155 -> V_157 -> V_4 ) ;
F_60 ( & V_17 -> V_43 ) ;
V_8 = F_102 ( V_17 , V_15 , V_111 ) ;
if ( V_8 && V_8 -> V_15 == V_15 ) {
F_74 ( V_8 , & V_88 ) ;
}
F_64 ( & V_17 -> V_43 ) ;
V_232 = V_233 -> V_172 ;
if ( V_228 && V_17 -> V_41 && V_17 -> V_41 -> V_234 ) {
V_65 = V_17 -> V_41 -> V_234 ( V_117 , V_15 , V_16 ,
V_8 , V_232 ) ;
if ( V_65 )
V_228 = 0 ;
else
F_149 ( V_15 , V_117 ) ;
}
if ( ! V_228 && V_17 -> V_41 && V_17 -> V_41 -> V_235 ) {
V_65 = V_17 -> V_41 -> V_235 ( V_117 , V_232 ) ;
if ( ! V_65 && ! V_85 &&
F_142 ( V_194 , & V_35 -> V_195 ) )
V_228 = 1 ;
} else if ( ! V_228 ) {
V_65 = F_152 ( V_35 , V_117 , V_15 , V_16 , V_232 , NULL ) ;
if ( V_65 == 0 ) {
V_228 =
F_142 ( V_194 , & V_35 -> V_195 ) ;
if ( V_85 )
V_228 = 0 ;
F_75 ( & V_88 ) ;
continue;
}
}
if ( V_228 && V_17 -> V_236 ) {
F_86 ( V_17 , V_15 , V_16 , & V_88 ,
V_40 ) ;
}
F_91 ( V_17 , V_15 , V_16 , & V_88 , V_40 ) ;
if ( V_228 ) {
F_127 ( V_117 ) ;
} else {
F_160 ( V_117 ) ;
F_161 ( V_117 ) ;
}
F_108 ( V_117 ) ;
} while ( V_155 <= V_231 );
F_138 ( V_35 ) ;
}
struct V_35 *
F_165 ( struct V_237 * V_190 , T_3 V_238 , int V_239 ,
T_2 V_240 )
{
struct V_35 * V_35 ;
V_35 = F_166 ( V_240 , V_239 , V_32 ) ;
if ( V_35 == NULL && ( V_241 -> V_4 & V_242 ) ) {
while ( ! V_35 && ( V_239 /= 2 ) ) {
V_35 = F_166 ( V_240 ,
V_239 , V_32 ) ;
}
}
if ( V_35 ) {
V_35 -> V_185 = 0 ;
V_35 -> V_192 = V_190 ;
V_35 -> V_189 = V_238 ;
}
return V_35 ;
}
struct V_35 * F_167 ( struct V_35 * V_35 , T_2 V_243 )
{
return F_168 ( V_35 , V_243 , V_32 ) ;
}
struct V_35 * F_136 ( T_2 V_243 , unsigned int V_244 )
{
return F_166 ( V_243 , V_244 , V_32 ) ;
}
static int T_4 F_169 ( int V_245 , struct V_35 * V_35 ,
int V_172 , unsigned long V_217 )
{
int V_65 = 0 ;
struct V_154 * V_155 = V_35 -> V_156 + V_35 -> V_222 - 1 ;
struct V_117 * V_117 = V_155 -> V_157 ;
struct V_24 * V_17 = V_35 -> V_168 ;
T_3 V_15 ;
V_15 = F_123 ( V_117 ) + V_155 -> V_158 ;
V_35 -> V_168 = NULL ;
F_170 ( V_35 ) ;
if ( V_17 -> V_41 && V_17 -> V_41 -> V_227 )
V_65 = V_17 -> V_41 -> V_227 ( V_117 -> V_25 -> V_26 , V_245 , V_35 ,
V_172 , V_217 , V_15 ) ;
else
F_140 ( V_245 , V_35 ) ;
if ( F_171 ( V_35 , V_246 ) )
V_65 = - V_247 ;
F_138 ( V_35 ) ;
return V_65 ;
}
static int F_172 ( int V_245 , struct V_24 * V_17 , struct V_117 * V_117 ,
unsigned long V_52 , T_7 V_248 , struct V_35 * V_35 ,
unsigned long V_217 )
{
int V_65 = 0 ;
if ( V_17 -> V_41 && V_17 -> V_41 -> V_249 )
V_65 = V_17 -> V_41 -> V_249 ( V_245 , V_117 , V_52 , V_248 , V_35 ,
V_217 ) ;
F_62 ( V_65 < 0 ) ;
return V_65 ;
}
static int F_173 ( int V_245 , struct V_24 * V_17 ,
struct V_117 * V_117 , T_8 V_177 ,
T_7 V_248 , unsigned long V_52 ,
struct V_237 * V_190 ,
struct V_35 * * V_250 ,
unsigned long V_251 ,
T_9 V_252 ,
int V_172 ,
unsigned long V_253 ,
unsigned long V_217 )
{
int V_65 = 0 ;
struct V_35 * V_35 ;
int V_254 ;
int V_148 = 0 ;
int V_255 = V_217 & V_220 ;
int V_256 = V_253 & V_220 ;
T_7 V_257 = F_107 ( T_7 , V_248 , V_137 ) ;
if ( V_250 && * V_250 ) {
V_35 = * V_250 ;
if ( V_256 )
V_148 = V_35 -> V_189 == V_177 ;
else
V_148 = F_174 ( V_35 ) == V_177 ;
if ( V_253 != V_217 || ! V_148 ||
F_172 ( V_245 , V_17 , V_117 , V_52 , V_257 , V_35 , V_217 ) ||
F_139 ( V_35 , V_117 , V_257 , V_52 ) < V_257 ) {
V_65 = F_169 ( V_245 , V_35 , V_172 ,
V_253 ) ;
if ( V_65 < 0 )
return V_65 ;
V_35 = NULL ;
} else {
return 0 ;
}
}
if ( V_255 )
V_254 = V_258 ;
else
V_254 = F_175 ( V_190 ) ;
V_35 = F_165 ( V_190 , V_177 , V_254 , V_112 | V_259 ) ;
if ( ! V_35 )
return - V_30 ;
F_139 ( V_35 , V_117 , V_257 , V_52 ) ;
V_35 -> V_184 = V_252 ;
V_35 -> V_168 = V_17 ;
if ( V_250 )
* V_250 = V_35 ;
else
V_65 = F_169 ( V_245 , V_35 , V_172 , V_217 ) ;
return V_65 ;
}
static void F_176 ( struct V_9 * V_10 ,
struct V_117 * V_117 )
{
if ( ! F_177 ( V_117 ) ) {
F_178 ( V_117 ) ;
F_179 ( V_117 ) ;
F_180 ( V_117 , ( unsigned long ) V_10 ) ;
} else {
F_33 ( V_117 -> V_46 != ( unsigned long ) V_10 ) ;
}
}
void F_181 ( struct V_117 * V_117 )
{
if ( ! F_177 ( V_117 ) ) {
F_178 ( V_117 ) ;
F_179 ( V_117 ) ;
F_180 ( V_117 , V_260 ) ;
}
}
static int F_182 ( struct V_24 * V_17 ,
struct V_117 * V_117 ,
T_10 * V_261 ,
struct V_35 * * V_35 , int V_172 ,
unsigned long * V_217 , int V_245 )
{
struct V_113 * V_113 = V_117 -> V_25 -> V_26 ;
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_262 = V_15 + V_137 - 1 ;
T_3 V_16 ;
T_3 V_263 = V_15 ;
T_3 V_264 ;
T_3 V_265 = F_183 ( V_113 ) ;
T_3 V_218 ;
T_3 V_266 ;
T_8 V_177 ;
struct V_209 * V_210 ;
struct V_237 * V_190 ;
struct V_267 * V_268 ;
int V_65 ;
int V_254 = 0 ;
T_7 V_269 = 0 ;
T_7 V_270 ;
T_7 V_271 ;
T_7 V_272 = V_113 -> V_27 -> V_273 ;
unsigned long V_274 = 0 ;
F_181 ( V_117 ) ;
if ( ! F_184 ( V_117 ) ) {
if ( F_185 ( V_117 ) == 0 ) {
F_62 ( V_272 != V_275 ) ;
goto V_95;
}
}
V_16 = V_262 ;
while ( 1 ) {
F_89 ( V_17 , V_15 , V_16 ) ;
V_268 = F_186 ( V_113 , V_15 ) ;
if ( ! V_268 )
break;
F_92 ( V_17 , V_15 , V_16 ) ;
F_187 ( V_113 , V_268 , 1 ) ;
F_188 ( V_268 ) ;
}
if ( V_117 -> V_114 == V_265 >> V_115 ) {
char * V_276 ;
T_7 V_277 = V_265 & ( V_137 - 1 ) ;
if ( V_277 ) {
V_270 = V_137 - V_277 ;
V_276 = F_189 ( V_117 ) ;
memset ( V_276 + V_277 , 0 , V_270 ) ;
F_190 ( V_117 ) ;
F_191 ( V_276 ) ;
}
}
while ( V_263 <= V_16 ) {
unsigned long V_278 = ( V_265 >> V_115 ) + 1 ;
if ( V_263 >= V_265 ) {
char * V_276 ;
struct V_7 * V_88 = NULL ;
V_270 = V_137 - V_269 ;
V_276 = F_189 ( V_117 ) ;
memset ( V_276 + V_269 , 0 , V_270 ) ;
F_190 ( V_117 ) ;
F_191 ( V_276 ) ;
F_86 ( V_17 , V_263 , V_263 + V_270 - 1 ,
& V_88 , V_112 ) ;
F_91 ( V_17 , V_263 , V_263 + V_270 - 1 ,
& V_88 , V_112 ) ;
break;
}
V_210 = V_261 ( V_113 , V_117 , V_269 , V_263 ,
V_16 - V_263 + 1 , 0 ) ;
if ( F_192 ( V_210 ) ) {
F_161 ( V_117 ) ;
F_92 ( V_17 , V_263 , V_16 ) ;
break;
}
V_264 = V_263 - V_210 -> V_15 ;
F_62 ( F_193 ( V_210 ) <= V_263 ) ;
F_62 ( V_16 < V_263 ) ;
if ( F_142 ( V_219 , & V_210 -> V_4 ) ) {
V_274 = V_220 ;
F_158 ( & V_274 ,
V_210 -> V_221 ) ;
}
V_270 = F_118 ( F_193 ( V_210 ) - V_263 , V_16 - V_263 + 1 ) ;
V_266 = F_118 ( F_193 ( V_210 ) - 1 , V_16 ) ;
V_270 = F_194 ( V_270 , V_272 ) ;
if ( V_274 & V_220 ) {
V_271 = V_210 -> V_279 ;
V_177 = V_210 -> V_218 >> 9 ;
} else {
V_177 = ( V_210 -> V_218 + V_264 ) >> 9 ;
V_271 = V_270 ;
}
V_190 = V_210 -> V_190 ;
V_218 = V_210 -> V_218 ;
if ( F_142 ( V_280 , & V_210 -> V_4 ) )
V_218 = V_281 ;
F_157 ( V_210 ) ;
V_210 = NULL ;
if ( V_218 == V_281 ) {
char * V_276 ;
struct V_7 * V_88 = NULL ;
V_276 = F_189 ( V_117 ) ;
memset ( V_276 + V_269 , 0 , V_270 ) ;
F_190 ( V_117 ) ;
F_191 ( V_276 ) ;
F_86 ( V_17 , V_263 , V_263 + V_270 - 1 ,
& V_88 , V_112 ) ;
F_91 ( V_17 , V_263 , V_263 + V_270 - 1 ,
& V_88 , V_112 ) ;
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
continue;
}
if ( F_113 ( V_17 , V_263 , V_266 ,
V_107 , 1 , NULL ) ) {
F_126 ( V_17 , V_117 ) ;
F_92 ( V_17 , V_263 , V_263 + V_270 - 1 ) ;
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
continue;
}
if ( V_218 == V_282 ) {
F_161 ( V_117 ) ;
F_92 ( V_17 , V_263 , V_263 + V_270 - 1 ) ;
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
continue;
}
V_278 -= V_117 -> V_114 ;
V_65 = F_173 ( V_245 , V_17 , V_117 ,
V_177 , V_271 , V_269 ,
V_190 , V_35 , V_278 ,
F_164 , V_172 ,
* V_217 ,
V_274 ) ;
if ( ! V_65 ) {
V_254 ++ ;
* V_217 = V_274 ;
} else {
F_161 ( V_117 ) ;
F_92 ( V_17 , V_263 , V_263 + V_270 - 1 ) ;
}
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
}
V_95:
if ( ! V_254 ) {
if ( ! F_195 ( V_117 ) )
F_127 ( V_117 ) ;
F_108 ( V_117 ) ;
}
return 0 ;
}
int F_196 ( struct V_24 * V_17 , struct V_117 * V_117 ,
T_10 * V_261 , int V_172 )
{
struct V_35 * V_35 = NULL ;
unsigned long V_217 = 0 ;
int V_65 ;
V_65 = F_182 ( V_17 , V_117 , V_261 , & V_35 , V_172 ,
& V_217 , V_283 ) ;
if ( V_35 )
V_65 = F_169 ( V_283 , V_35 , V_172 , V_217 ) ;
return V_65 ;
}
static T_5 void F_197 ( struct V_117 * V_117 ,
struct V_284 * V_285 ,
unsigned long V_286 )
{
V_285 -> V_287 -= V_286 ;
if ( V_285 -> V_288 || ( V_285 -> V_287 > 0 &&
V_285 -> V_289 == 0 && V_285 -> V_290 == V_291 ) )
V_117 -> V_25 -> V_292 = V_117 -> V_114 + V_286 ;
}
static int F_198 ( struct V_117 * V_117 , struct V_284 * V_285 ,
void * V_293 )
{
struct V_113 * V_113 = V_117 -> V_25 -> V_26 ;
struct V_294 * V_295 = V_293 ;
struct V_24 * V_17 = V_295 -> V_17 ;
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_129 ;
T_3 V_262 = V_15 + V_137 - 1 ;
T_3 V_16 ;
T_3 V_263 = V_15 ;
T_3 V_264 ;
T_3 V_265 = F_183 ( V_113 ) ;
T_3 V_218 ;
T_3 V_270 ;
T_8 V_177 ;
struct V_7 * V_87 = NULL ;
struct V_209 * V_210 ;
struct V_237 * V_190 ;
int V_65 ;
int V_254 = 0 ;
T_7 V_269 = 0 ;
T_7 V_272 ;
T_11 V_296 = F_183 ( V_113 ) ;
unsigned long V_116 = V_296 >> V_115 ;
T_3 V_297 ;
T_3 V_130 ;
int V_298 ;
int V_299 ;
int V_300 ;
unsigned long V_286 = 0 ;
bool V_301 = true ;
if ( V_285 -> V_302 == V_303 )
V_300 = V_193 ;
else
V_300 = V_186 ;
F_199 ( V_117 , V_113 , V_285 ) ;
F_33 ( ! F_200 ( V_117 ) ) ;
F_201 ( V_117 ) ;
V_269 = V_296 & ( V_137 - 1 ) ;
if ( V_117 -> V_114 > V_116 ||
( V_117 -> V_114 == V_116 && ! V_269 ) ) {
V_117 -> V_25 -> V_304 -> V_305 ( V_117 , 0 ) ;
F_108 ( V_117 ) ;
return 0 ;
}
if ( V_117 -> V_114 == V_116 ) {
char * V_276 ;
V_276 = F_189 ( V_117 ) ;
memset ( V_276 + V_269 , 0 ,
V_137 - V_269 ) ;
F_191 ( V_276 ) ;
F_190 ( V_117 ) ;
}
V_269 = 0 ;
F_181 ( V_117 ) ;
if ( ! V_17 -> V_41 || ! V_17 -> V_41 -> V_301 )
V_301 = false ;
V_129 = V_15 ;
V_130 = 0 ;
V_298 = 0 ;
if ( ! V_295 -> V_306 && V_301 ) {
T_3 V_307 = 0 ;
F_197 ( V_117 , V_285 , 0 ) ;
while ( V_130 < V_262 ) {
V_297 = F_112 ( V_113 , V_17 ,
V_117 ,
& V_129 ,
& V_130 ,
128 * 1024 * 1024 ) ;
if ( V_297 == 0 ) {
V_129 = V_130 + 1 ;
continue;
}
V_65 = V_17 -> V_41 -> V_301 ( V_113 , V_117 ,
V_129 ,
V_130 ,
& V_298 ,
& V_286 ) ;
if ( V_65 ) {
F_161 ( V_117 ) ;
goto V_135;
}
V_307 += ( V_130 - V_129 +
V_137 ) >>
V_115 ;
V_129 = V_130 + 1 ;
}
if ( V_285 -> V_287 < V_307 ) {
int V_308 = 8192 ;
if ( V_307 < V_308 * 2 )
V_308 = V_307 ;
V_285 -> V_287 = F_107 ( T_3 , V_307 ,
V_308 ) ;
}
if ( V_298 ) {
V_65 = 0 ;
V_285 -> V_287 -= V_286 ;
goto V_309;
}
}
if ( V_17 -> V_41 && V_17 -> V_41 -> V_310 ) {
V_65 = V_17 -> V_41 -> V_310 ( V_117 , V_15 ,
V_262 ) ;
if ( V_65 ) {
if ( V_65 == - V_311 )
V_285 -> V_312 ++ ;
else
F_202 ( V_285 , V_117 ) ;
F_197 ( V_117 , V_285 , V_286 ) ;
F_108 ( V_117 ) ;
V_65 = 0 ;
goto V_309;
}
}
F_197 ( V_117 , V_285 , V_286 + 1 ) ;
V_16 = V_262 ;
if ( V_265 <= V_15 ) {
if ( V_17 -> V_41 && V_17 -> V_41 -> V_229 )
V_17 -> V_41 -> V_229 ( V_117 , V_15 ,
V_262 , NULL , 1 ) ;
goto V_135;
}
V_272 = V_113 -> V_27 -> V_273 ;
while ( V_263 <= V_16 ) {
if ( V_263 >= V_265 ) {
if ( V_17 -> V_41 && V_17 -> V_41 -> V_229 )
V_17 -> V_41 -> V_229 ( V_117 , V_263 ,
V_262 , NULL , 1 ) ;
break;
}
V_210 = V_295 -> V_261 ( V_113 , V_117 , V_269 , V_263 ,
V_16 - V_263 + 1 , 1 ) ;
if ( F_192 ( V_210 ) ) {
F_161 ( V_117 ) ;
break;
}
V_264 = V_263 - V_210 -> V_15 ;
F_62 ( F_193 ( V_210 ) <= V_263 ) ;
F_62 ( V_16 < V_263 ) ;
V_270 = F_118 ( F_193 ( V_210 ) - V_263 , V_16 - V_263 + 1 ) ;
V_270 = F_194 ( V_270 , V_272 ) ;
V_177 = ( V_210 -> V_218 + V_264 ) >> 9 ;
V_190 = V_210 -> V_190 ;
V_218 = V_210 -> V_218 ;
V_299 = F_142 ( V_219 , & V_210 -> V_4 ) ;
F_157 ( V_210 ) ;
V_210 = NULL ;
if ( V_299 || V_218 == V_281 ||
V_218 == V_282 ) {
if ( ! V_299 && V_17 -> V_41 &&
V_17 -> V_41 -> V_229 )
V_17 -> V_41 -> V_229 ( V_117 , V_263 ,
V_263 + V_270 - 1 ,
NULL , 1 ) ;
else if ( V_299 ) {
V_254 ++ ;
}
V_263 += V_270 ;
V_269 += V_270 ;
continue;
}
if ( 0 && ! F_113 ( V_17 , V_263 , V_263 + V_270 - 1 ,
V_83 , 0 , NULL ) ) {
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
continue;
}
if ( V_17 -> V_41 && V_17 -> V_41 -> V_313 ) {
V_65 = V_17 -> V_41 -> V_313 ( V_117 , V_263 ,
V_263 + V_270 - 1 ) ;
} else {
V_65 = 0 ;
}
if ( V_65 ) {
F_161 ( V_117 ) ;
} else {
unsigned long V_314 = V_116 + 1 ;
F_100 ( V_17 , V_263 , V_263 + V_270 - 1 ) ;
if ( ! F_203 ( V_117 ) ) {
F_10 ( V_14 L_33
L_34 ,
V_117 -> V_114 , ( unsigned long long ) V_263 ,
( unsigned long long ) V_16 ) ;
}
V_65 = F_173 ( V_300 , V_17 , V_117 ,
V_177 , V_270 , V_269 ,
V_190 , & V_295 -> V_35 , V_314 ,
F_162 ,
0 , 0 , 0 ) ;
if ( V_65 )
F_161 ( V_117 ) ;
}
V_263 = V_263 + V_270 ;
V_269 += V_270 ;
V_254 ++ ;
}
V_135:
if ( V_254 == 0 ) {
F_101 ( V_117 ) ;
F_116 ( V_117 ) ;
}
F_108 ( V_117 ) ;
V_309:
F_31 ( V_87 ) ;
return 0 ;
}
static int F_204 ( void * V_315 )
{
F_205 () ;
return 0 ;
}
void F_206 ( struct V_9 * V_10 )
{
F_207 ( & V_10 -> V_316 , V_317 , F_204 ,
V_98 ) ;
}
static int F_208 ( struct V_9 * V_10 ,
struct V_23 * V_169 ,
struct V_294 * V_295 )
{
unsigned long V_128 , V_201 ;
int V_318 = 0 ;
int V_65 = 0 ;
if ( ! F_209 ( V_10 ) ) {
V_318 = 1 ;
F_210 ( V_295 ) ;
F_211 ( V_10 ) ;
}
if ( F_142 ( V_317 , & V_10 -> V_316 ) ) {
F_212 ( V_10 ) ;
if ( ! V_295 -> V_319 )
return 0 ;
if ( ! V_318 ) {
F_210 ( V_295 ) ;
V_318 = 1 ;
}
while ( 1 ) {
F_206 ( V_10 ) ;
F_211 ( V_10 ) ;
if ( ! F_142 ( V_317 , & V_10 -> V_316 ) )
break;
F_212 ( V_10 ) ;
}
}
F_60 ( & V_10 -> V_320 ) ;
if ( F_213 ( V_321 , & V_10 -> V_316 ) ) {
F_214 ( V_317 , & V_10 -> V_316 ) ;
F_64 ( & V_10 -> V_320 ) ;
F_215 ( V_10 , V_322 ) ;
F_216 ( & V_169 -> V_323 ,
- V_10 -> V_21 ,
V_169 -> V_324 ) ;
V_65 = 1 ;
} else {
F_64 ( & V_10 -> V_320 ) ;
}
F_212 ( V_10 ) ;
if ( ! V_65 )
return V_65 ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
struct V_117 * V_54 = F_148 ( V_10 , V_128 ) ;
if ( ! F_217 ( V_54 ) ) {
if ( ! V_318 ) {
F_210 ( V_295 ) ;
V_318 = 1 ;
}
F_110 ( V_54 ) ;
}
}
return V_65 ;
}
static void F_218 ( struct V_9 * V_10 )
{
F_219 ( V_317 , & V_10 -> V_316 ) ;
F_220 () ;
F_221 ( & V_10 -> V_316 , V_317 ) ;
}
static void F_222 ( struct V_35 * V_35 , int V_85 )
{
int V_228 = V_85 == 0 ;
struct V_154 * V_155 = V_35 -> V_156 + V_35 -> V_222 - 1 ;
struct V_9 * V_10 ;
int V_135 ;
do {
struct V_117 * V_117 = V_155 -> V_157 ;
V_155 -- ;
V_10 = (struct V_9 * ) V_117 -> V_46 ;
F_62 ( ! V_10 ) ;
V_135 = F_32 ( & V_10 -> V_325 ) ;
if ( ! V_228 || F_142 ( V_326 , & V_10 -> V_316 ) ) {
F_214 ( V_326 , & V_10 -> V_316 ) ;
F_160 ( V_117 ) ;
F_161 ( V_117 ) ;
}
F_116 ( V_117 ) ;
if ( ! V_135 )
continue;
F_218 ( V_10 ) ;
} while ( V_155 >= V_35 -> V_156 );
F_138 ( V_35 ) ;
}
static int F_223 ( struct V_9 * V_10 ,
struct V_23 * V_169 ,
struct V_284 * V_285 ,
struct V_294 * V_295 )
{
struct V_237 * V_190 = V_169 -> V_225 -> V_226 ;
T_3 V_52 = V_10 -> V_15 ;
unsigned long V_128 , V_201 ;
unsigned long V_217 = 0 ;
int V_245 = ( V_295 -> V_319 ? V_193 : V_186 ) | V_327 ;
int V_65 = 0 ;
F_219 ( V_326 , & V_10 -> V_316 ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_28 ( & V_10 -> V_325 , V_201 ) ;
if ( F_224 ( V_10 ) == V_328 )
V_217 = V_329 ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
struct V_117 * V_54 = F_148 ( V_10 , V_128 ) ;
F_95 ( V_54 ) ;
F_101 ( V_54 ) ;
V_65 = F_173 ( V_245 , V_10 -> V_17 , V_54 , V_52 >> 9 ,
V_137 , 0 , V_190 , & V_295 -> V_35 ,
- 1 , F_222 ,
0 , V_295 -> V_217 , V_217 ) ;
V_295 -> V_217 = V_217 ;
if ( V_65 ) {
F_214 ( V_326 , & V_10 -> V_316 ) ;
F_161 ( V_54 ) ;
if ( F_225 ( V_201 - V_128 , & V_10 -> V_325 ) )
F_218 ( V_10 ) ;
V_65 = - V_183 ;
break;
}
V_52 += V_137 ;
F_197 ( V_54 , V_285 , 1 ) ;
F_108 ( V_54 ) ;
}
if ( F_226 ( V_65 ) ) {
for (; V_128 < V_201 ; V_128 ++ ) {
struct V_117 * V_54 = F_148 ( V_10 , V_128 ) ;
F_108 ( V_54 ) ;
}
}
return V_65 ;
}
int F_227 ( struct V_37 * V_25 ,
struct V_284 * V_285 )
{
struct V_24 * V_17 = & F_129 ( V_25 -> V_26 ) -> V_166 ;
struct V_23 * V_169 = F_129 ( V_25 -> V_26 ) -> V_51 -> V_169 ;
struct V_9 * V_10 , * V_330 = NULL ;
struct V_294 V_295 = {
. V_35 = NULL ,
. V_17 = V_17 ,
. V_306 = 0 ,
. V_319 = V_285 -> V_302 == V_303 ,
. V_217 = 0 ,
} ;
int V_65 = 0 ;
int V_135 = 0 ;
int V_331 = 0 ;
struct V_332 V_333 ;
int V_127 ;
T_12 V_114 ;
T_12 V_16 ;
int V_334 = 0 ;
int V_335 ;
F_228 ( & V_333 , 0 ) ;
if ( V_285 -> V_288 ) {
V_114 = V_25 -> V_292 ;
V_16 = - 1 ;
} else {
V_114 = V_285 -> V_289 >> V_115 ;
V_16 = V_285 -> V_290 >> V_115 ;
V_334 = 1 ;
}
if ( V_285 -> V_302 == V_303 )
V_335 = V_336 ;
else
V_335 = V_337 ;
V_338:
if ( V_285 -> V_302 == V_303 )
F_229 ( V_25 , V_114 , V_16 ) ;
while ( ! V_135 && ! V_331 && ( V_114 <= V_16 ) &&
( V_127 = F_230 ( & V_333 , V_25 , & V_114 , V_335 ,
F_118 ( V_16 - V_114 , ( T_12 ) V_339 - 1 ) + 1 ) ) ) {
unsigned V_128 ;
V_334 = 1 ;
for ( V_128 = 0 ; V_128 < V_127 ; V_128 ++ ) {
struct V_117 * V_117 = V_333 . V_126 [ V_128 ] ;
if ( ! F_177 ( V_117 ) )
continue;
if ( ! V_285 -> V_288 && V_117 -> V_114 > V_16 ) {
V_135 = 1 ;
break;
}
F_60 ( & V_25 -> V_340 ) ;
if ( ! F_177 ( V_117 ) ) {
F_64 ( & V_25 -> V_340 ) ;
continue;
}
V_10 = (struct V_9 * ) V_117 -> V_46 ;
if ( ! V_10 ) {
F_64 ( & V_25 -> V_340 ) ;
F_33 ( 1 ) ;
continue;
}
if ( V_10 == V_330 ) {
F_64 ( & V_25 -> V_340 ) ;
continue;
}
V_65 = F_231 ( & V_10 -> V_18 ) ;
F_64 ( & V_25 -> V_340 ) ;
if ( ! V_65 )
continue;
V_330 = V_10 ;
V_65 = F_208 ( V_10 , V_169 , & V_295 ) ;
if ( ! V_65 ) {
F_232 ( V_10 ) ;
continue;
}
V_65 = F_223 ( V_10 , V_169 , V_285 , & V_295 ) ;
if ( V_65 ) {
V_135 = 1 ;
F_232 ( V_10 ) ;
break;
}
F_232 ( V_10 ) ;
V_331 = V_285 -> V_287 <= 0 ;
}
F_233 ( & V_333 ) ;
F_65 () ;
}
if ( ! V_334 && ! V_135 ) {
V_334 = 1 ;
V_114 = 0 ;
goto V_338;
}
F_210 ( & V_295 ) ;
return V_65 ;
}
static int F_234 ( struct V_24 * V_17 ,
struct V_37 * V_25 ,
struct V_284 * V_285 ,
T_13 V_341 , void * V_293 ,
void (* F_235)( void * ) )
{
struct V_113 * V_113 = V_25 -> V_26 ;
int V_65 = 0 ;
int V_135 = 0 ;
int V_331 = 0 ;
struct V_332 V_333 ;
int V_127 ;
T_12 V_114 ;
T_12 V_16 ;
int V_334 = 0 ;
int V_335 ;
if ( ! F_236 ( V_113 ) )
return 0 ;
F_228 ( & V_333 , 0 ) ;
if ( V_285 -> V_288 ) {
V_114 = V_25 -> V_292 ;
V_16 = - 1 ;
} else {
V_114 = V_285 -> V_289 >> V_115 ;
V_16 = V_285 -> V_290 >> V_115 ;
V_334 = 1 ;
}
if ( V_285 -> V_302 == V_303 )
V_335 = V_336 ;
else
V_335 = V_337 ;
V_338:
if ( V_285 -> V_302 == V_303 )
F_229 ( V_25 , V_114 , V_16 ) ;
while ( ! V_135 && ! V_331 && ( V_114 <= V_16 ) &&
( V_127 = F_230 ( & V_333 , V_25 , & V_114 , V_335 ,
F_118 ( V_16 - V_114 , ( T_12 ) V_339 - 1 ) + 1 ) ) ) {
unsigned V_128 ;
V_334 = 1 ;
for ( V_128 = 0 ; V_128 < V_127 ; V_128 ++ ) {
struct V_117 * V_117 = V_333 . V_126 [ V_128 ] ;
if ( ! F_217 ( V_117 ) ) {
F_235 ( V_293 ) ;
F_110 ( V_117 ) ;
}
if ( F_226 ( V_117 -> V_25 != V_25 ) ) {
F_108 ( V_117 ) ;
continue;
}
if ( ! V_285 -> V_288 && V_117 -> V_114 > V_16 ) {
V_135 = 1 ;
F_108 ( V_117 ) ;
continue;
}
if ( V_285 -> V_302 != V_342 ) {
if ( F_203 ( V_117 ) )
F_235 ( V_293 ) ;
F_237 ( V_117 ) ;
}
if ( F_203 ( V_117 ) ||
! F_95 ( V_117 ) ) {
F_108 ( V_117 ) ;
continue;
}
V_65 = (* V_341)( V_117 , V_285 , V_293 ) ;
if ( F_226 ( V_65 == V_343 ) ) {
F_108 ( V_117 ) ;
V_65 = 0 ;
}
if ( V_65 )
V_135 = 1 ;
V_331 = V_285 -> V_287 <= 0 ;
}
F_233 ( & V_333 ) ;
F_65 () ;
}
if ( ! V_334 && ! V_135 ) {
V_334 = 1 ;
V_114 = 0 ;
goto V_338;
}
F_238 ( V_113 ) ;
return V_65 ;
}
static void F_239 ( struct V_294 * V_295 )
{
if ( V_295 -> V_35 ) {
int V_245 = V_186 ;
int V_65 ;
if ( V_295 -> V_319 )
V_245 = V_193 ;
V_65 = F_169 ( V_245 , V_295 -> V_35 , 0 , V_295 -> V_217 ) ;
F_62 ( V_65 < 0 ) ;
V_295 -> V_35 = NULL ;
}
}
static T_5 void F_210 ( void * V_293 )
{
struct V_294 * V_295 = V_293 ;
F_239 ( V_295 ) ;
}
int F_240 ( struct V_24 * V_17 , struct V_117 * V_117 ,
T_10 * V_261 ,
struct V_284 * V_285 )
{
int V_65 ;
struct V_294 V_295 = {
. V_35 = NULL ,
. V_17 = V_17 ,
. V_261 = V_261 ,
. V_306 = 0 ,
. V_319 = V_285 -> V_302 == V_303 ,
. V_217 = 0 ,
} ;
V_65 = F_198 ( V_117 , V_285 , & V_295 ) ;
F_239 ( & V_295 ) ;
return V_65 ;
}
int F_241 ( struct V_24 * V_17 , struct V_113 * V_113 ,
T_3 V_15 , T_3 V_16 , T_10 * V_261 ,
int V_344 )
{
int V_65 = 0 ;
struct V_37 * V_25 = V_113 -> V_118 ;
struct V_117 * V_117 ;
unsigned long V_127 = ( V_16 - V_15 + V_137 ) >>
V_115 ;
struct V_294 V_295 = {
. V_35 = NULL ,
. V_17 = V_17 ,
. V_261 = V_261 ,
. V_306 = 1 ,
. V_319 = V_344 == V_303 ,
. V_217 = 0 ,
} ;
struct V_284 V_345 = {
. V_302 = V_344 ,
. V_287 = V_127 * 2 ,
. V_289 = V_15 ,
. V_290 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_117 = F_94 ( V_25 , V_15 >> V_115 ) ;
if ( F_95 ( V_117 ) )
V_65 = F_198 ( V_117 , & V_345 , & V_295 ) ;
else {
if ( V_17 -> V_41 && V_17 -> V_41 -> V_229 )
V_17 -> V_41 -> V_229 ( V_117 , V_15 ,
V_15 + V_137 - 1 ,
NULL , 1 ) ;
F_108 ( V_117 ) ;
}
F_96 ( V_117 ) ;
V_15 += V_137 ;
}
F_239 ( & V_295 ) ;
return V_65 ;
}
int F_242 ( struct V_24 * V_17 ,
struct V_37 * V_25 ,
T_10 * V_261 ,
struct V_284 * V_285 )
{
int V_65 = 0 ;
struct V_294 V_295 = {
. V_35 = NULL ,
. V_17 = V_17 ,
. V_261 = V_261 ,
. V_306 = 0 ,
. V_319 = V_285 -> V_302 == V_303 ,
. V_217 = 0 ,
} ;
V_65 = F_234 ( V_17 , V_25 , V_285 ,
F_198 , & V_295 ,
F_210 ) ;
F_239 ( & V_295 ) ;
return V_65 ;
}
int F_243 ( struct V_24 * V_17 ,
struct V_37 * V_25 ,
struct V_1 * V_126 , unsigned V_127 ,
T_10 V_261 )
{
struct V_35 * V_35 = NULL ;
unsigned V_346 ;
unsigned long V_217 = 0 ;
struct V_117 * V_347 [ 16 ] ;
struct V_117 * V_117 ;
int V_128 = 0 ;
int V_254 = 0 ;
for ( V_346 = 0 ; V_346 < V_127 ; V_346 ++ ) {
V_117 = F_9 ( V_126 -> V_62 , struct V_117 , V_348 ) ;
F_163 ( & V_117 -> V_4 ) ;
F_6 ( & V_117 -> V_348 ) ;
if ( F_244 ( V_117 , V_25 ,
V_117 -> V_114 , V_112 ) ) {
F_96 ( V_117 ) ;
continue;
}
V_347 [ V_254 ++ ] = V_117 ;
if ( V_254 < F_245 ( V_347 ) )
continue;
for ( V_128 = 0 ; V_128 < V_254 ; V_128 ++ ) {
F_182 ( V_17 , V_347 [ V_128 ] , V_261 ,
& V_35 , 0 , & V_217 , V_283 ) ;
F_96 ( V_347 [ V_128 ] ) ;
}
V_254 = 0 ;
}
for ( V_128 = 0 ; V_128 < V_254 ; V_128 ++ ) {
F_182 ( V_17 , V_347 [ V_128 ] , V_261 ,
& V_35 , 0 , & V_217 , V_283 ) ;
F_96 ( V_347 [ V_128 ] ) ;
}
F_62 ( ! F_8 ( V_126 ) ) ;
if ( V_35 )
return F_169 ( V_283 , V_35 , 0 , V_217 ) ;
return 0 ;
}
int F_246 ( struct V_24 * V_17 ,
struct V_117 * V_117 , unsigned long V_52 )
{
struct V_7 * V_87 = NULL ;
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_16 = V_15 + V_137 - 1 ;
T_7 V_272 = V_117 -> V_25 -> V_26 -> V_27 -> V_273 ;
V_15 += F_194 ( V_52 , V_272 ) ;
if ( V_15 > V_16 )
return 0 ;
F_88 ( V_17 , V_15 , V_16 , 0 , & V_87 ) ;
F_237 ( V_117 ) ;
F_59 ( V_17 , V_15 , V_16 ,
V_111 | V_83 | V_106 |
V_109 ,
1 , 1 , & V_87 , V_112 ) ;
return 0 ;
}
static int F_247 ( struct V_211 * V_349 ,
struct V_24 * V_17 ,
struct V_117 * V_117 , T_2 V_45 )
{
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_16 = V_15 + V_137 - 1 ;
int V_65 = 1 ;
if ( F_113 ( V_17 , V_15 , V_16 ,
V_69 , 0 , NULL ) )
V_65 = 0 ;
else {
if ( ( V_45 & V_112 ) == V_112 )
V_45 = V_112 ;
V_65 = F_59 ( V_17 , V_15 , V_16 ,
~ ( V_111 | V_350 ) ,
0 , 0 , NULL , V_45 ) ;
if ( V_65 < 0 )
V_65 = 0 ;
else
V_65 = 1 ;
}
return V_65 ;
}
int F_248 ( struct V_211 * V_349 ,
struct V_24 * V_17 , struct V_117 * V_117 ,
T_2 V_45 )
{
struct V_209 * V_210 ;
T_3 V_15 = F_123 ( V_117 ) ;
T_3 V_16 = V_15 + V_137 - 1 ;
if ( ( V_45 & V_93 ) &&
V_117 -> V_25 -> V_26 -> V_296 > 16 * 1024 * 1024 ) {
T_3 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_249 ( & V_349 -> V_43 ) ;
V_210 = F_155 ( V_349 , V_15 , V_21 ) ;
if ( ! V_210 ) {
F_250 ( & V_349 -> V_43 ) ;
break;
}
if ( F_142 ( V_351 , & V_210 -> V_4 ) ||
V_210 -> V_15 != V_15 ) {
F_250 ( & V_349 -> V_43 ) ;
F_157 ( V_210 ) ;
break;
}
if ( ! F_113 ( V_17 , V_210 -> V_15 ,
F_193 ( V_210 ) - 1 ,
V_111 | V_352 ,
0 , NULL ) ) {
F_251 ( V_349 , V_210 ) ;
F_157 ( V_210 ) ;
}
V_15 = F_193 ( V_210 ) ;
F_250 ( & V_349 -> V_43 ) ;
F_157 ( V_210 ) ;
}
}
return F_247 ( V_349 , V_17 , V_117 , V_45 ) ;
}
static struct V_209 * F_252 ( struct V_113 * V_113 ,
T_3 V_52 ,
T_3 V_149 ,
T_10 * V_261 )
{
T_3 V_353 = F_129 ( V_113 ) -> V_51 -> V_353 ;
struct V_209 * V_210 ;
T_3 V_21 ;
if ( V_52 >= V_149 )
return NULL ;
while( 1 ) {
V_21 = V_149 - V_52 ;
if ( V_21 == 0 )
break;
V_21 = F_194 ( V_21 , V_353 ) ;
V_210 = V_261 ( V_113 , NULL , 0 , V_52 , V_21 , 0 ) ;
if ( F_192 ( V_210 ) )
return V_210 ;
if ( ! F_142 ( V_354 , & V_210 -> V_4 ) &&
V_210 -> V_218 != V_281 ) {
return V_210 ;
}
V_52 = F_193 ( V_210 ) ;
F_157 ( V_210 ) ;
if ( V_52 >= V_149 )
break;
}
return NULL ;
}
int F_253 ( struct V_113 * V_113 , struct V_355 * V_356 ,
T_14 V_15 , T_14 V_21 , T_10 * V_261 )
{
int V_65 = 0 ;
T_3 V_357 = V_15 ;
T_3 F_119 = V_15 + V_21 ;
T_6 V_4 = 0 ;
T_6 V_358 ;
T_3 V_149 ;
T_3 V_359 = 0 ;
T_3 V_360 = 0 ;
T_3 V_361 = F_183 ( V_113 ) ;
struct V_362 V_363 ;
struct V_209 * V_210 = NULL ;
struct V_7 * V_87 = NULL ;
struct V_364 * V_365 ;
struct V_366 * V_367 ;
int V_16 = 0 ;
T_3 V_368 = 0 ;
T_3 V_369 = 0 ;
T_3 V_370 = 0 ;
unsigned long V_371 ;
if ( V_21 == 0 )
return - V_372 ;
V_365 = F_254 () ;
if ( ! V_365 )
return - V_30 ;
V_365 -> V_373 = 1 ;
V_15 = F_194 ( V_15 , F_129 ( V_113 ) -> V_51 -> V_353 ) ;
V_21 = F_194 ( V_21 , F_129 ( V_113 ) -> V_51 -> V_353 ) ;
V_65 = F_255 ( NULL , F_129 ( V_113 ) -> V_51 ,
V_365 , F_256 ( V_113 ) , - 1 , 0 ) ;
if ( V_65 < 0 ) {
F_257 ( V_365 ) ;
return V_65 ;
}
F_33 ( ! V_65 ) ;
V_365 -> V_374 [ 0 ] -- ;
V_367 = F_258 ( V_365 -> V_375 [ 0 ] , V_365 -> V_374 [ 0 ] ,
struct V_366 ) ;
F_259 ( V_365 -> V_375 [ 0 ] , & V_363 , V_365 -> V_374 [ 0 ] ) ;
V_358 = F_260 ( & V_363 ) ;
if ( V_363 . V_376 != F_256 ( V_113 ) ||
V_358 != V_377 ) {
V_149 = ( T_3 ) - 1 ;
V_359 = V_361 ;
} else {
V_149 = V_363 . V_52 ;
V_359 = V_149 + 1 ;
}
F_257 ( V_365 ) ;
if ( V_149 < V_361 ) {
V_149 = ( T_3 ) - 1 ;
V_359 = V_361 ;
}
F_88 ( & F_129 ( V_113 ) -> V_166 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_87 ) ;
V_210 = F_252 ( V_113 , V_15 , V_359 ,
V_261 ) ;
if ( ! V_210 )
goto V_95;
if ( F_261 ( V_210 ) ) {
V_65 = F_262 ( V_210 ) ;
goto V_95;
}
while ( ! V_16 ) {
T_3 V_378 ;
if ( V_210 -> V_15 >= F_119 || F_193 ( V_210 ) < V_357 )
break;
V_368 = F_119 ( V_210 -> V_15 , V_357 ) ;
V_378 = V_368 - V_210 -> V_15 ;
V_370 = F_193 ( V_210 ) ;
V_369 = V_370 - V_368 ;
V_371 = V_210 -> V_4 ;
V_360 = 0 ;
V_4 = 0 ;
V_357 = F_193 ( V_210 ) ;
if ( V_357 >= F_119 )
V_16 = 1 ;
if ( V_210 -> V_218 == V_379 ) {
V_16 = 1 ;
V_4 |= V_380 ;
} else if ( V_210 -> V_218 == V_282 ) {
V_4 |= ( V_381 |
V_382 ) ;
} else if ( V_210 -> V_218 == V_383 ) {
V_4 |= ( V_384 |
V_385 ) ;
} else {
V_360 = V_210 -> V_218 + V_378 ;
}
if ( F_142 ( V_219 , & V_210 -> V_4 ) )
V_4 |= V_386 ;
F_157 ( V_210 ) ;
V_210 = NULL ;
if ( ( V_368 >= V_149 ) || V_369 == ( T_3 ) - 1 ||
( V_149 == ( T_3 ) - 1 && V_361 <= V_370 ) ) {
V_4 |= V_380 ;
V_16 = 1 ;
}
V_210 = F_252 ( V_113 , V_357 , V_359 ,
V_261 ) ;
if ( F_261 ( V_210 ) ) {
V_65 = F_262 ( V_210 ) ;
goto V_95;
}
if ( ! V_210 ) {
V_4 |= V_380 ;
V_16 = 1 ;
}
V_65 = F_263 ( V_356 , V_368 , V_360 ,
V_369 , V_4 ) ;
if ( V_65 )
goto V_387;
}
V_387:
F_157 ( V_210 ) ;
V_95:
F_91 ( & F_129 ( V_113 ) -> V_166 , V_15 , V_15 + V_21 - 1 ,
& V_87 , V_112 ) ;
return V_65 ;
}
static void F_264 ( struct V_9 * V_10 )
{
F_5 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
static struct V_9 * F_265 ( struct V_24 * V_17 ,
T_3 V_15 ,
unsigned long V_21 ,
T_2 V_45 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_266 ( V_22 , V_45 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_316 = 0 ;
F_267 ( & V_10 -> V_43 ) ;
F_28 ( & V_10 -> V_388 , 0 ) ;
F_28 ( & V_10 -> V_389 , 0 ) ;
F_28 ( & V_10 -> V_390 , 0 ) ;
F_28 ( & V_10 -> V_391 , 0 ) ;
F_28 ( & V_10 -> V_392 , 0 ) ;
F_28 ( & V_10 -> V_393 , 0 ) ;
V_10 -> V_394 = 0 ;
F_29 ( & V_10 -> V_395 ) ;
F_29 ( & V_10 -> V_396 ) ;
F_1 ( & V_10 -> V_13 , & V_20 ) ;
F_25 ( & V_10 -> V_320 ) ;
F_28 ( & V_10 -> V_18 , 1 ) ;
F_28 ( & V_10 -> V_325 , 0 ) ;
F_268 ( V_397
> V_398 ) ;
F_62 ( V_21 > V_398 ) ;
return V_10 ;
}
struct V_9 * F_269 ( struct V_9 * V_399 )
{
unsigned long V_128 ;
struct V_117 * V_54 ;
struct V_9 * V_2 ;
unsigned long V_201 = F_147 ( V_399 -> V_15 , V_399 -> V_21 ) ;
V_2 = F_265 ( NULL , V_399 -> V_15 , V_399 -> V_21 , V_40 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
V_54 = F_270 ( V_40 ) ;
F_62 ( ! V_54 ) ;
F_176 ( V_2 , V_54 ) ;
F_33 ( F_111 ( V_54 ) ) ;
F_127 ( V_54 ) ;
V_2 -> V_126 [ V_128 ] = V_54 ;
}
F_271 ( V_2 , V_399 , 0 , 0 , V_399 -> V_21 ) ;
F_214 ( V_400 , & V_2 -> V_316 ) ;
F_214 ( V_401 , & V_2 -> V_316 ) ;
return V_2 ;
}
struct V_9 * F_272 ( T_3 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
unsigned long V_201 = F_147 ( 0 , V_21 ) ;
unsigned long V_128 ;
V_10 = F_265 ( NULL , V_15 , V_21 , V_40 ) ;
if ( ! V_10 )
return NULL ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
V_10 -> V_126 [ V_128 ] = F_270 ( V_40 ) ;
if ( ! V_10 -> V_126 [ V_128 ] )
goto V_85;
}
F_273 ( V_10 ) ;
F_274 ( V_10 , 0 ) ;
F_214 ( V_401 , & V_10 -> V_316 ) ;
return V_10 ;
V_85:
for (; V_128 > 0 ; V_128 -- )
F_275 ( V_10 -> V_126 [ V_128 - 1 ] ) ;
F_264 ( V_10 ) ;
return NULL ;
}
static int F_276 ( struct V_9 * V_10 )
{
return ( F_11 ( & V_10 -> V_325 ) ||
F_142 ( V_317 , & V_10 -> V_316 ) ||
F_142 ( V_321 , & V_10 -> V_316 ) ) ;
}
static void F_277 ( struct V_9 * V_10 ,
unsigned long V_402 )
{
unsigned long V_114 ;
unsigned long V_201 ;
struct V_117 * V_117 ;
int V_403 = ! F_142 ( V_401 , & V_10 -> V_316 ) ;
F_62 ( F_276 ( V_10 ) ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
V_114 = V_402 + V_201 ;
if ( V_402 >= V_114 )
return;
do {
V_114 -- ;
V_117 = F_148 ( V_10 , V_114 ) ;
if ( V_117 && V_403 ) {
F_60 ( & V_117 -> V_25 -> V_340 ) ;
if ( F_177 ( V_117 ) &&
V_117 -> V_46 == ( unsigned long ) V_10 ) {
F_62 ( F_142 ( V_321 , & V_10 -> V_316 ) ) ;
F_62 ( F_111 ( V_117 ) ) ;
F_62 ( F_203 ( V_117 ) ) ;
F_278 ( V_117 ) ;
F_180 ( V_117 , 0 ) ;
F_96 ( V_117 ) ;
}
F_64 ( & V_117 -> V_25 -> V_340 ) ;
}
if ( V_117 ) {
F_96 ( V_117 ) ;
}
} while ( V_114 != V_402 );
}
static inline void F_279 ( struct V_9 * V_10 )
{
F_277 ( V_10 , 0 ) ;
F_264 ( V_10 ) ;
}
static void F_280 ( struct V_9 * V_10 )
{
int V_18 ;
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 >= 2 && F_142 ( V_404 , & V_10 -> V_316 ) )
return;
F_60 ( & V_10 -> V_320 ) ;
if ( ! F_281 ( V_404 , & V_10 -> V_316 ) )
F_72 ( & V_10 -> V_18 ) ;
F_64 ( & V_10 -> V_320 ) ;
}
static void F_282 ( struct V_9 * V_10 )
{
unsigned long V_201 , V_128 ;
F_280 ( V_10 ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
struct V_117 * V_54 = F_148 ( V_10 , V_128 ) ;
F_283 ( V_54 ) ;
}
}
struct V_9 * F_284 ( struct V_24 * V_17 ,
T_3 V_15 , unsigned long V_21 )
{
unsigned long V_201 = F_147 ( V_15 , V_21 ) ;
unsigned long V_128 ;
unsigned long V_114 = V_15 >> V_115 ;
struct V_9 * V_10 ;
struct V_9 * V_405 = NULL ;
struct V_117 * V_54 ;
struct V_37 * V_25 = V_17 -> V_25 ;
int V_228 = 1 ;
int V_65 ;
F_285 () ;
V_10 = F_286 ( & V_17 -> V_39 , V_15 >> V_115 ) ;
if ( V_10 && F_231 ( & V_10 -> V_18 ) ) {
F_287 () ;
F_282 ( V_10 ) ;
return V_10 ;
}
F_287 () ;
V_10 = F_265 ( V_17 , V_15 , V_21 , V_112 ) ;
if ( ! V_10 )
return NULL ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ , V_114 ++ ) {
V_54 = F_288 ( V_25 , V_114 , V_112 ) ;
if ( ! V_54 )
goto V_406;
F_60 ( & V_25 -> V_340 ) ;
if ( F_177 ( V_54 ) ) {
V_405 = (struct V_9 * ) V_54 -> V_46 ;
if ( F_231 ( & V_405 -> V_18 ) ) {
F_64 ( & V_25 -> V_340 ) ;
F_108 ( V_54 ) ;
F_96 ( V_54 ) ;
F_282 ( V_405 ) ;
goto V_406;
}
F_278 ( V_54 ) ;
F_33 ( F_111 ( V_54 ) ) ;
F_96 ( V_54 ) ;
}
F_176 ( V_10 , V_54 ) ;
F_64 ( & V_25 -> V_340 ) ;
F_33 ( F_111 ( V_54 ) ) ;
F_283 ( V_54 ) ;
V_10 -> V_126 [ V_128 ] = V_54 ;
if ( ! F_184 ( V_54 ) )
V_228 = 0 ;
}
if ( V_228 )
F_214 ( V_400 , & V_10 -> V_316 ) ;
V_92:
V_65 = F_289 ( V_112 & ~ V_407 ) ;
if ( V_65 )
goto V_406;
F_60 ( & V_17 -> V_44 ) ;
V_65 = F_290 ( & V_17 -> V_39 , V_15 >> V_115 , V_10 ) ;
if ( V_65 == - V_75 ) {
V_405 = F_286 ( & V_17 -> V_39 ,
V_15 >> V_115 ) ;
if ( ! F_231 ( & V_405 -> V_18 ) ) {
F_64 ( & V_17 -> V_44 ) ;
F_291 () ;
V_405 = NULL ;
goto V_92;
}
F_64 ( & V_17 -> V_44 ) ;
F_291 () ;
F_282 ( V_405 ) ;
goto V_406;
}
F_280 ( V_10 ) ;
F_64 ( & V_17 -> V_44 ) ;
F_291 () ;
F_292 ( V_10 -> V_126 [ 0 ] ) ;
for ( V_128 = 1 ; V_128 < V_201 ; V_128 ++ ) {
V_54 = F_148 ( V_10 , V_128 ) ;
F_293 ( V_54 ) ;
F_108 ( V_54 ) ;
}
F_108 ( V_10 -> V_126 [ 0 ] ) ;
return V_10 ;
V_406:
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
if ( V_10 -> V_126 [ V_128 ] )
F_108 ( V_10 -> V_126 [ V_128 ] ) ;
}
F_33 ( ! F_32 ( & V_10 -> V_18 ) ) ;
F_279 ( V_10 ) ;
return V_405 ;
}
struct V_9 * F_294 ( struct V_24 * V_17 ,
T_3 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
F_285 () ;
V_10 = F_286 ( & V_17 -> V_39 , V_15 >> V_115 ) ;
if ( V_10 && F_231 ( & V_10 -> V_18 ) ) {
F_287 () ;
F_282 ( V_10 ) ;
return V_10 ;
}
F_287 () ;
return NULL ;
}
static inline void F_295 ( struct V_408 * V_3 )
{
struct V_9 * V_10 =
F_296 ( V_3 , struct V_9 , V_408 ) ;
F_264 ( V_10 ) ;
}
static int F_297 ( struct V_9 * V_10 )
{
F_33 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
if ( F_32 ( & V_10 -> V_18 ) ) {
if ( F_142 ( V_401 , & V_10 -> V_316 ) ) {
F_64 ( & V_10 -> V_320 ) ;
} else {
struct V_24 * V_17 = V_10 -> V_17 ;
F_64 ( & V_10 -> V_320 ) ;
F_60 ( & V_17 -> V_44 ) ;
F_298 ( & V_17 -> V_39 ,
V_10 -> V_15 >> V_115 ) ;
F_64 ( & V_17 -> V_44 ) ;
}
F_277 ( V_10 , 0 ) ;
F_299 ( & V_10 -> V_408 , F_295 ) ;
return 1 ;
}
F_64 ( & V_10 -> V_320 ) ;
return 0 ;
}
void F_232 ( struct V_9 * V_10 )
{
int V_18 ;
int V_409 ;
if ( ! V_10 )
return;
while ( 1 ) {
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 <= 3 )
break;
V_409 = F_300 ( & V_10 -> V_18 , V_18 , V_18 - 1 ) ;
if ( V_409 == V_18 )
return;
}
F_60 ( & V_10 -> V_320 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_142 ( V_401 , & V_10 -> V_316 ) )
F_61 ( & V_10 -> V_18 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_142 ( V_410 , & V_10 -> V_316 ) &&
! F_276 ( V_10 ) &&
F_213 ( V_404 , & V_10 -> V_316 ) )
F_61 ( & V_10 -> V_18 ) ;
F_297 ( V_10 ) ;
}
void F_301 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_60 ( & V_10 -> V_320 ) ;
F_214 ( V_410 , & V_10 -> V_316 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 && ! F_276 ( V_10 ) &&
F_213 ( V_404 , & V_10 -> V_316 ) )
F_61 ( & V_10 -> V_18 ) ;
F_297 ( V_10 ) ;
}
void F_302 ( struct V_9 * V_10 )
{
unsigned long V_128 ;
unsigned long V_201 ;
struct V_117 * V_117 ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
if ( ! F_111 ( V_117 ) )
continue;
F_110 ( V_117 ) ;
F_33 ( ! F_177 ( V_117 ) ) ;
F_95 ( V_117 ) ;
F_303 ( & V_117 -> V_25 -> V_411 ) ;
if ( ! F_111 ( V_117 ) ) {
F_304 ( & V_117 -> V_25 -> V_412 ,
F_305 ( V_117 ) ,
V_337 ) ;
}
F_306 ( & V_117 -> V_25 -> V_411 ) ;
F_201 ( V_117 ) ;
F_108 ( V_117 ) ;
}
F_33 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
}
int F_307 ( struct V_9 * V_10 )
{
unsigned long V_128 ;
unsigned long V_201 ;
int V_413 = 0 ;
F_280 ( V_10 ) ;
V_413 = F_281 ( V_321 , & V_10 -> V_316 ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_33 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
F_33 ( ! F_142 ( V_404 , & V_10 -> V_316 ) ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ )
F_308 ( F_148 ( V_10 , V_128 ) ) ;
return V_413 ;
}
int F_309 ( struct V_9 * V_10 )
{
unsigned long V_128 ;
struct V_117 * V_117 ;
unsigned long V_201 ;
F_219 ( V_400 , & V_10 -> V_316 ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
if ( V_117 )
F_160 ( V_117 ) ;
}
return 0 ;
}
int F_273 ( struct V_9 * V_10 )
{
unsigned long V_128 ;
struct V_117 * V_117 ;
unsigned long V_201 ;
F_214 ( V_400 , & V_10 -> V_316 ) ;
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = 0 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
F_127 ( V_117 ) ;
}
return 0 ;
}
int F_310 ( struct V_9 * V_10 )
{
return F_142 ( V_400 , & V_10 -> V_316 ) ;
}
int F_311 ( struct V_24 * V_17 ,
struct V_9 * V_10 , T_3 V_15 , int V_97 ,
T_10 * V_261 , int V_172 )
{
unsigned long V_128 ;
unsigned long V_414 ;
struct V_117 * V_117 ;
int V_85 ;
int V_65 = 0 ;
int V_415 = 0 ;
int V_416 = 1 ;
unsigned long V_201 ;
unsigned long V_417 = 0 ;
struct V_35 * V_35 = NULL ;
unsigned long V_217 = 0 ;
if ( F_142 ( V_400 , & V_10 -> V_316 ) )
return 0 ;
if ( V_15 ) {
F_33 ( V_15 < V_10 -> V_15 ) ;
V_414 = ( V_15 >> V_115 ) -
( V_10 -> V_15 >> V_115 ) ;
} else {
V_414 = 0 ;
}
V_201 = F_147 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_128 = V_414 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
if ( V_97 == V_418 ) {
if ( ! F_217 ( V_117 ) )
goto V_419;
} else {
F_110 ( V_117 ) ;
}
V_415 ++ ;
if ( ! F_184 ( V_117 ) ) {
V_417 ++ ;
V_416 = 0 ;
}
}
if ( V_416 ) {
if ( V_414 == 0 )
F_214 ( V_400 , & V_10 -> V_316 ) ;
goto V_419;
}
F_219 ( V_326 , & V_10 -> V_316 ) ;
V_10 -> V_420 = 0 ;
F_28 ( & V_10 -> V_325 , V_417 ) ;
for ( V_128 = V_414 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
if ( ! F_184 ( V_117 ) ) {
F_201 ( V_117 ) ;
V_85 = F_182 ( V_17 , V_117 ,
V_261 , & V_35 ,
V_172 , & V_217 ,
V_283 | V_327 ) ;
if ( V_85 )
V_65 = V_85 ;
} else {
F_108 ( V_117 ) ;
}
}
if ( V_35 ) {
V_85 = F_169 ( V_283 | V_327 , V_35 , V_172 ,
V_217 ) ;
if ( V_85 )
return V_85 ;
}
if ( V_65 || V_97 != V_421 )
return V_65 ;
for ( V_128 = V_414 ; V_128 < V_201 ; V_128 ++ ) {
V_117 = F_148 ( V_10 , V_128 ) ;
F_312 ( V_117 ) ;
if ( ! F_184 ( V_117 ) )
V_65 = - V_183 ;
}
return V_65 ;
V_419:
V_128 = V_414 ;
while ( V_415 > 0 ) {
V_117 = F_148 ( V_10 , V_128 ) ;
V_128 ++ ;
F_108 ( V_117 ) ;
V_415 -- ;
}
return V_65 ;
}
void F_313 ( struct V_9 * V_10 , void * V_422 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_52 ;
struct V_117 * V_117 ;
char * V_423 ;
char * V_424 = ( char * ) V_422 ;
T_7 V_425 = V_10 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_15 ) >> V_115 ;
F_33 ( V_15 > V_10 -> V_21 ) ;
F_33 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_52 = ( V_425 + V_15 ) & ( ( unsigned long ) V_137 - 1 ) ;
while ( V_21 > 0 ) {
V_117 = F_148 ( V_10 , V_128 ) ;
V_263 = F_118 ( V_21 , ( V_137 - V_52 ) ) ;
V_423 = F_314 ( V_117 ) ;
memcpy ( V_424 , V_423 + V_52 , V_263 ) ;
V_424 += V_263 ;
V_21 -= V_263 ;
V_52 = 0 ;
V_128 ++ ;
}
}
int F_315 ( struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_426 , char * * V_349 ,
unsigned long * V_427 ,
unsigned long * V_428 )
{
T_7 V_52 = V_15 & ( V_137 - 1 ) ;
char * V_423 ;
struct V_117 * V_54 ;
T_7 V_425 = V_10 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_15 ) >> V_115 ;
unsigned long V_429 = ( V_425 + V_15 + V_426 - 1 ) >>
V_115 ;
if ( V_128 != V_429 )
return - V_372 ;
if ( V_128 == 0 ) {
V_52 = V_425 ;
* V_427 = 0 ;
} else {
V_52 = 0 ;
* V_427 = ( ( T_3 ) V_128 << V_115 ) - V_425 ;
}
if ( V_15 + V_426 > V_10 -> V_21 ) {
F_49 ( 1 , V_14 L_35
L_36 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_21 , V_15 , V_426 ) ;
return - V_372 ;
}
V_54 = F_148 ( V_10 , V_128 ) ;
V_423 = F_314 ( V_54 ) ;
* V_349 = V_423 + V_52 ;
* V_428 = V_137 - V_52 ;
return 0 ;
}
int F_316 ( struct V_9 * V_10 , const void * V_430 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_52 ;
struct V_117 * V_117 ;
char * V_423 ;
char * V_431 = ( char * ) V_430 ;
T_7 V_425 = V_10 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_15 ) >> V_115 ;
int V_65 = 0 ;
F_33 ( V_15 > V_10 -> V_21 ) ;
F_33 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_52 = ( V_425 + V_15 ) & ( ( unsigned long ) V_137 - 1 ) ;
while ( V_21 > 0 ) {
V_117 = F_148 ( V_10 , V_128 ) ;
V_263 = F_118 ( V_21 , ( V_137 - V_52 ) ) ;
V_423 = F_314 ( V_117 ) ;
V_65 = memcmp ( V_431 , V_423 + V_52 , V_263 ) ;
if ( V_65 )
break;
V_431 += V_263 ;
V_21 -= V_263 ;
V_52 = 0 ;
V_128 ++ ;
}
return V_65 ;
}
void F_317 ( struct V_9 * V_10 , const void * V_432 ,
unsigned long V_15 , unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_52 ;
struct V_117 * V_117 ;
char * V_423 ;
char * V_399 = ( char * ) V_432 ;
T_7 V_425 = V_10 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_15 ) >> V_115 ;
F_33 ( V_15 > V_10 -> V_21 ) ;
F_33 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_52 = ( V_425 + V_15 ) & ( ( unsigned long ) V_137 - 1 ) ;
while ( V_21 > 0 ) {
V_117 = F_148 ( V_10 , V_128 ) ;
F_33 ( ! F_184 ( V_117 ) ) ;
V_263 = F_118 ( V_21 , V_137 - V_52 ) ;
V_423 = F_314 ( V_117 ) ;
memcpy ( V_423 + V_52 , V_399 , V_263 ) ;
V_399 += V_263 ;
V_21 -= V_263 ;
V_52 = 0 ;
V_128 ++ ;
}
}
void F_318 ( struct V_9 * V_10 , char V_433 ,
unsigned long V_15 , unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_52 ;
struct V_117 * V_117 ;
char * V_423 ;
T_7 V_425 = V_10 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_15 ) >> V_115 ;
F_33 ( V_15 > V_10 -> V_21 ) ;
F_33 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_52 = ( V_425 + V_15 ) & ( ( unsigned long ) V_137 - 1 ) ;
while ( V_21 > 0 ) {
V_117 = F_148 ( V_10 , V_128 ) ;
F_33 ( ! F_184 ( V_117 ) ) ;
V_263 = F_118 ( V_21 , V_137 - V_52 ) ;
V_423 = F_314 ( V_117 ) ;
memset ( V_423 + V_52 , V_433 , V_263 ) ;
V_21 -= V_263 ;
V_52 = 0 ;
V_128 ++ ;
}
}
void F_271 ( struct V_9 * V_424 , struct V_9 * V_399 ,
unsigned long V_434 , unsigned long V_435 ,
unsigned long V_21 )
{
T_3 V_436 = V_424 -> V_21 ;
T_7 V_263 ;
T_7 V_52 ;
struct V_117 * V_117 ;
char * V_423 ;
T_7 V_425 = V_424 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_128 = ( V_425 + V_434 ) >> V_115 ;
F_33 ( V_399 -> V_21 != V_436 ) ;
V_52 = ( V_425 + V_434 ) &
( ( unsigned long ) V_137 - 1 ) ;
while ( V_21 > 0 ) {
V_117 = F_148 ( V_424 , V_128 ) ;
F_33 ( ! F_184 ( V_117 ) ) ;
V_263 = F_118 ( V_21 , ( unsigned long ) ( V_137 - V_52 ) ) ;
V_423 = F_314 ( V_117 ) ;
F_313 ( V_399 , V_423 + V_52 , V_435 , V_263 ) ;
V_435 += V_263 ;
V_21 -= V_263 ;
V_52 = 0 ;
V_128 ++ ;
}
}
static void F_319 ( struct V_117 * V_437 , struct V_117 * V_438 ,
unsigned long V_439 , unsigned long V_440 ,
unsigned long V_21 )
{
char * V_441 = F_314 ( V_437 ) ;
if ( V_437 == V_438 ) {
memmove ( V_441 + V_439 , V_441 + V_440 , V_21 ) ;
} else {
char * V_442 = F_314 ( V_438 ) ;
char * V_54 = V_441 + V_439 + V_21 ;
char * V_443 = V_442 + V_440 + V_21 ;
while ( V_21 -- )
* -- V_54 = * -- V_443 ;
}
}
static inline bool F_320 ( unsigned long V_399 , unsigned long V_424 , unsigned long V_21 )
{
unsigned long V_444 = ( V_399 > V_424 ) ? V_399 - V_424 : V_424 - V_399 ;
return V_444 < V_21 ;
}
static void F_321 ( struct V_117 * V_437 , struct V_117 * V_438 ,
unsigned long V_439 , unsigned long V_440 ,
unsigned long V_21 )
{
char * V_441 = F_314 ( V_437 ) ;
char * V_442 ;
int V_445 = 0 ;
if ( V_437 != V_438 ) {
V_442 = F_314 ( V_438 ) ;
} else {
V_442 = V_441 ;
if ( F_320 ( V_440 , V_439 , V_21 ) )
V_445 = 1 ;
}
if ( V_445 )
memmove ( V_441 + V_439 , V_442 + V_440 , V_21 ) ;
else
memcpy ( V_441 + V_439 , V_442 + V_440 , V_21 ) ;
}
void F_322 ( struct V_9 * V_424 , unsigned long V_434 ,
unsigned long V_435 , unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_446 ;
T_7 V_447 ;
T_7 V_425 = V_424 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_448 ;
unsigned long V_449 ;
if ( V_435 + V_21 > V_424 -> V_21 ) {
F_10 ( V_14 L_37
L_38 , V_435 , V_21 , V_424 -> V_21 ) ;
F_62 ( 1 ) ;
}
if ( V_434 + V_21 > V_424 -> V_21 ) {
F_10 ( V_14 L_39
L_38 , V_434 , V_21 , V_424 -> V_21 ) ;
F_62 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_446 = ( V_425 + V_434 ) &
( ( unsigned long ) V_137 - 1 ) ;
V_447 = ( V_425 + V_435 ) &
( ( unsigned long ) V_137 - 1 ) ;
V_448 = ( V_425 + V_434 ) >> V_115 ;
V_449 = ( V_425 + V_435 ) >> V_115 ;
V_263 = F_118 ( V_21 , ( unsigned long ) ( V_137 -
V_447 ) ) ;
V_263 = F_107 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_321 ( F_148 ( V_424 , V_448 ) ,
F_148 ( V_424 , V_449 ) ,
V_446 , V_447 , V_263 ) ;
V_435 += V_263 ;
V_434 += V_263 ;
V_21 -= V_263 ;
}
}
void F_323 ( struct V_9 * V_424 , unsigned long V_434 ,
unsigned long V_435 , unsigned long V_21 )
{
T_7 V_263 ;
T_7 V_446 ;
T_7 V_447 ;
unsigned long V_450 = V_434 + V_21 - 1 ;
unsigned long V_451 = V_435 + V_21 - 1 ;
T_7 V_425 = V_424 -> V_15 & ( ( T_3 ) V_137 - 1 ) ;
unsigned long V_448 ;
unsigned long V_449 ;
if ( V_435 + V_21 > V_424 -> V_21 ) {
F_10 ( V_14 L_37
L_40 , V_435 , V_21 , V_424 -> V_21 ) ;
F_62 ( 1 ) ;
}
if ( V_434 + V_21 > V_424 -> V_21 ) {
F_10 ( V_14 L_39
L_40 , V_434 , V_21 , V_424 -> V_21 ) ;
F_62 ( 1 ) ;
}
if ( V_434 < V_435 ) {
F_322 ( V_424 , V_434 , V_435 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_448 = ( V_425 + V_450 ) >> V_115 ;
V_449 = ( V_425 + V_451 ) >> V_115 ;
V_446 = ( V_425 + V_450 ) &
( ( unsigned long ) V_137 - 1 ) ;
V_447 = ( V_425 + V_451 ) &
( ( unsigned long ) V_137 - 1 ) ;
V_263 = F_107 (unsigned long, len, src_off_in_page + 1 ) ;
V_263 = F_118 ( V_263 , V_446 + 1 ) ;
F_319 ( F_148 ( V_424 , V_448 ) ,
F_148 ( V_424 , V_449 ) ,
V_446 - V_263 + 1 ,
V_447 - V_263 + 1 , V_263 ) ;
V_450 -= V_263 ;
V_451 -= V_263 ;
V_21 -= V_263 ;
}
}
int F_324 ( struct V_117 * V_117 )
{
struct V_9 * V_10 ;
F_60 ( & V_117 -> V_25 -> V_340 ) ;
if ( ! F_177 ( V_117 ) ) {
F_64 ( & V_117 -> V_25 -> V_340 ) ;
return 1 ;
}
V_10 = (struct V_9 * ) V_117 -> V_46 ;
F_62 ( ! V_10 ) ;
F_60 ( & V_10 -> V_320 ) ;
if ( F_11 ( & V_10 -> V_18 ) != 1 || F_276 ( V_10 ) ) {
F_64 ( & V_10 -> V_320 ) ;
F_64 ( & V_117 -> V_25 -> V_340 ) ;
return 0 ;
}
F_64 ( & V_117 -> V_25 -> V_340 ) ;
if ( ! F_213 ( V_404 , & V_10 -> V_316 ) ) {
F_64 ( & V_10 -> V_320 ) ;
return 0 ;
}
return F_297 ( V_10 ) ;
}
