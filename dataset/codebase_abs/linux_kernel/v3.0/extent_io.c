int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , 0 ,
V_3 | V_4 , NULL ) ;
if ( ! V_1 )
return - V_5 ;
V_6 = F_2 ( L_2 ,
sizeof( struct V_7 ) , 0 ,
V_3 | V_4 , NULL ) ;
if ( ! V_6 )
goto V_8;
return 0 ;
V_8:
F_3 ( V_1 ) ;
return - V_5 ;
}
void F_4 ( void )
{
struct V_2 * V_9 ;
struct V_7 * V_10 ;
while ( ! F_5 ( & V_11 ) ) {
V_9 = F_6 ( V_11 . V_12 , struct V_2 , V_13 ) ;
F_7 ( V_14 L_3
L_4 ,
( unsigned long long ) V_9 -> V_15 ,
( unsigned long long ) V_9 -> V_16 ,
V_9 -> V_9 , V_9 -> V_17 , F_8 ( & V_9 -> V_18 ) ) ;
F_9 ( & V_9 -> V_13 ) ;
F_10 ( V_1 , V_9 ) ;
}
while ( ! F_5 ( & V_19 ) ) {
V_10 = F_6 ( V_19 . V_12 , struct V_7 , V_13 ) ;
F_7 ( V_14 L_5
L_6 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_20 , F_8 ( & V_10 -> V_18 ) ) ;
F_9 ( & V_10 -> V_13 ) ;
F_10 ( V_6 , V_10 ) ;
}
if ( V_1 )
F_3 ( V_1 ) ;
if ( V_6 )
F_3 ( V_6 ) ;
}
void F_11 ( struct V_21 * V_17 ,
struct V_22 * V_23 )
{
V_17 -> V_9 = V_24 ;
F_12 ( & V_17 -> V_25 , V_26 ) ;
V_17 -> V_27 = NULL ;
V_17 -> V_28 = 0 ;
F_13 ( & V_17 -> V_29 ) ;
F_13 ( & V_17 -> V_30 ) ;
V_17 -> V_23 = V_23 ;
}
static struct V_2 * F_14 ( T_2 V_31 )
{
struct V_2 * V_9 ;
#if V_32
unsigned long V_33 ;
#endif
V_9 = F_15 ( V_1 , V_31 ) ;
if ( ! V_9 )
return V_9 ;
V_9 -> V_9 = 0 ;
V_9 -> V_34 = 0 ;
V_9 -> V_17 = NULL ;
#if V_32
F_16 ( & V_35 , V_33 ) ;
F_17 ( & V_9 -> V_13 , & V_11 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_19 ( & V_9 -> V_18 , 1 ) ;
F_20 ( & V_9 -> V_36 ) ;
return V_9 ;
}
void F_21 ( struct V_2 * V_9 )
{
if ( ! V_9 )
return;
if ( F_22 ( & V_9 -> V_18 ) ) {
#if V_32
unsigned long V_33 ;
#endif
F_23 ( V_9 -> V_17 ) ;
#if V_32
F_16 ( & V_35 , V_33 ) ;
F_9 ( & V_9 -> V_13 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_10 ( V_1 , V_9 ) ;
}
}
static struct V_37 * F_24 ( struct V_38 * V_39 , T_3 V_40 ,
struct V_37 * V_41 )
{
struct V_37 * * V_42 = & V_39 -> V_37 ;
struct V_37 * V_43 = NULL ;
struct V_44 * V_45 ;
while ( * V_42 ) {
V_43 = * V_42 ;
V_45 = F_25 ( V_43 , struct V_44 , V_37 ) ;
if ( V_40 < V_45 -> V_15 )
V_42 = & ( * V_42 ) -> V_46 ;
else if ( V_40 > V_45 -> V_16 )
V_42 = & ( * V_42 ) -> V_47 ;
else
return V_43 ;
}
V_45 = F_25 ( V_41 , struct V_44 , V_37 ) ;
F_26 ( V_41 , V_43 , V_42 ) ;
F_27 ( V_41 , V_39 ) ;
return NULL ;
}
static struct V_37 * F_28 ( struct V_21 * V_17 , T_3 V_40 ,
struct V_37 * * V_48 ,
struct V_37 * * V_49 )
{
struct V_38 * V_39 = & V_17 -> V_9 ;
struct V_37 * V_50 = V_39 -> V_37 ;
struct V_37 * V_51 = NULL ;
struct V_37 * V_52 = NULL ;
struct V_44 * V_45 ;
struct V_44 * V_53 = NULL ;
while ( V_50 ) {
V_45 = F_25 ( V_50 , struct V_44 , V_37 ) ;
V_51 = V_50 ;
V_53 = V_45 ;
if ( V_40 < V_45 -> V_15 )
V_50 = V_50 -> V_46 ;
else if ( V_40 > V_45 -> V_16 )
V_50 = V_50 -> V_47 ;
else
return V_50 ;
}
if ( V_48 ) {
V_52 = V_51 ;
while ( V_51 && V_40 > V_53 -> V_16 ) {
V_51 = F_29 ( V_51 ) ;
V_53 = F_25 ( V_51 , struct V_44 , V_37 ) ;
}
* V_48 = V_51 ;
V_51 = V_52 ;
}
if ( V_49 ) {
V_53 = F_25 ( V_51 , struct V_44 , V_37 ) ;
while ( V_51 && V_40 < V_53 -> V_15 ) {
V_51 = F_30 ( V_51 ) ;
V_53 = F_25 ( V_51 , struct V_44 , V_37 ) ;
}
* V_49 = V_51 ;
}
return NULL ;
}
static inline struct V_37 * F_31 ( struct V_21 * V_17 ,
T_3 V_40 )
{
struct V_37 * V_51 = NULL ;
struct V_37 * V_54 ;
V_54 = F_28 ( V_17 , V_40 , & V_51 , NULL ) ;
if ( ! V_54 )
return V_51 ;
return V_54 ;
}
static void F_32 ( struct V_21 * V_17 , struct V_2 * V_55 ,
struct V_2 * V_56 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_57 )
V_17 -> V_27 -> V_57 ( V_17 -> V_23 -> V_58 , V_55 ,
V_56 ) ;
}
static int F_33 ( struct V_21 * V_17 ,
struct V_2 * V_9 )
{
struct V_2 * V_56 ;
struct V_37 * V_59 ;
if ( V_9 -> V_9 & ( V_60 | V_61 ) )
return 0 ;
V_59 = F_30 ( & V_9 -> V_37 ) ;
if ( V_59 ) {
V_56 = F_25 ( V_59 , struct V_2 , V_37 ) ;
if ( V_56 -> V_16 == V_9 -> V_15 - 1 &&
V_56 -> V_9 == V_9 -> V_9 ) {
F_32 ( V_17 , V_9 , V_56 ) ;
V_9 -> V_15 = V_56 -> V_15 ;
V_56 -> V_17 = NULL ;
F_34 ( & V_56 -> V_37 , & V_17 -> V_9 ) ;
F_21 ( V_56 ) ;
}
}
V_59 = F_29 ( & V_9 -> V_37 ) ;
if ( V_59 ) {
V_56 = F_25 ( V_59 , struct V_2 , V_37 ) ;
if ( V_56 -> V_15 == V_9 -> V_16 + 1 &&
V_56 -> V_9 == V_9 -> V_9 ) {
F_32 ( V_17 , V_9 , V_56 ) ;
V_56 -> V_15 = V_9 -> V_15 ;
V_9 -> V_17 = NULL ;
F_34 ( & V_9 -> V_37 , & V_17 -> V_9 ) ;
F_21 ( V_9 ) ;
V_9 = NULL ;
}
}
return 0 ;
}
static int F_35 ( struct V_21 * V_17 ,
struct V_2 * V_9 , int * V_62 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_63 ) {
return V_17 -> V_27 -> V_63 ( V_17 -> V_23 -> V_58 ,
V_9 , V_62 ) ;
}
return 0 ;
}
static void F_36 ( struct V_21 * V_17 ,
struct V_2 * V_9 , int * V_62 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_64 )
V_17 -> V_27 -> V_64 ( V_17 -> V_23 -> V_58 , V_9 , V_62 ) ;
}
static int F_37 ( struct V_21 * V_17 ,
struct V_2 * V_9 , T_3 V_15 , T_3 V_16 ,
int * V_62 )
{
struct V_37 * V_41 ;
int V_65 = * V_62 & ~ V_66 ;
int V_54 ;
if ( V_16 < V_15 ) {
F_7 ( V_14 L_7 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_15 ) ;
F_23 ( 1 ) ;
}
V_9 -> V_15 = V_15 ;
V_9 -> V_16 = V_16 ;
V_54 = F_35 ( V_17 , V_9 , V_62 ) ;
if ( V_54 )
return V_54 ;
if ( V_65 & V_67 )
V_17 -> V_28 += V_16 - V_15 + 1 ;
V_9 -> V_9 |= V_65 ;
V_41 = F_24 ( & V_17 -> V_9 , V_16 , & V_9 -> V_37 ) ;
if ( V_41 ) {
struct V_2 * V_68 ;
V_68 = F_25 ( V_41 , struct V_2 , V_37 ) ;
F_7 ( V_14 L_8
L_9 , ( unsigned long long ) V_68 -> V_15 ,
( unsigned long long ) V_68 -> V_16 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 ) ;
F_21 ( V_9 ) ;
return - V_69 ;
}
V_9 -> V_17 = V_17 ;
F_33 ( V_17 , V_9 ) ;
return 0 ;
}
static int F_38 ( struct V_21 * V_17 , struct V_2 * V_70 ,
T_3 V_71 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_72 )
return V_17 -> V_27 -> V_72 ( V_17 -> V_23 -> V_58 ,
V_70 , V_71 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_17 , struct V_2 * V_70 ,
struct V_2 * V_73 , T_3 V_71 )
{
struct V_37 * V_41 ;
F_38 ( V_17 , V_70 , V_71 ) ;
V_73 -> V_15 = V_70 -> V_15 ;
V_73 -> V_16 = V_71 - 1 ;
V_73 -> V_9 = V_70 -> V_9 ;
V_70 -> V_15 = V_71 ;
V_41 = F_24 ( & V_17 -> V_9 , V_73 -> V_16 , & V_73 -> V_37 ) ;
if ( V_41 ) {
F_21 ( V_73 ) ;
return - V_69 ;
}
V_73 -> V_17 = V_17 ;
return 0 ;
}
static int F_40 ( struct V_21 * V_17 ,
struct V_2 * V_9 ,
int * V_62 , int V_74 )
{
int V_75 = * V_62 & ~ V_66 ;
int V_54 = V_9 -> V_9 & V_75 ;
if ( ( V_75 & V_67 ) && ( V_9 -> V_9 & V_67 ) ) {
T_3 V_76 = V_9 -> V_16 - V_9 -> V_15 + 1 ;
F_23 ( V_76 > V_17 -> V_28 ) ;
V_17 -> V_28 -= V_76 ;
}
F_36 ( V_17 , V_9 , V_62 ) ;
V_9 -> V_9 &= ~ V_75 ;
if ( V_74 )
F_41 ( & V_9 -> V_36 ) ;
if ( V_9 -> V_9 == 0 ) {
if ( V_9 -> V_17 ) {
F_34 ( & V_9 -> V_37 , & V_17 -> V_9 ) ;
V_9 -> V_17 = NULL ;
F_21 ( V_9 ) ;
} else {
F_23 ( 1 ) ;
}
} else {
F_33 ( V_17 , V_9 ) ;
}
return V_54 ;
}
static struct V_2 *
F_42 ( struct V_2 * V_73 )
{
if ( ! V_73 )
V_73 = F_14 ( V_26 ) ;
return V_73 ;
}
int F_43 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_74 , int V_77 ,
struct V_2 * * V_78 ,
T_2 V_31 )
{
struct V_2 * V_9 ;
struct V_2 * V_79 ;
struct V_2 * V_73 = NULL ;
struct V_37 * V_80 ;
struct V_37 * V_41 ;
T_3 V_81 ;
int V_82 ;
int V_83 = 0 ;
int V_84 = 0 ;
if ( V_77 )
V_62 |= ~ V_66 ;
V_62 |= V_85 ;
if ( V_62 & ( V_60 | V_61 ) )
V_84 = 1 ;
V_86:
if ( ! V_73 && ( V_31 & V_87 ) ) {
V_73 = F_14 ( V_31 ) ;
if ( ! V_73 )
return - V_5 ;
}
F_44 ( & V_17 -> V_29 ) ;
if ( V_78 ) {
V_79 = * V_78 ;
if ( V_84 ) {
* V_78 = NULL ;
V_78 = NULL ;
}
if ( V_79 && V_79 -> V_17 && V_79 -> V_15 == V_15 ) {
if ( V_84 )
F_45 ( & V_79 -> V_18 ) ;
V_9 = V_79 ;
goto V_88;
}
if ( V_84 )
F_21 ( V_79 ) ;
}
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
goto V_89;
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
V_88:
if ( V_9 -> V_15 > V_16 )
goto V_89;
F_23 ( V_9 -> V_16 < V_15 ) ;
V_81 = V_9 -> V_16 ;
if ( V_9 -> V_15 < V_15 ) {
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
V_82 = F_39 ( V_17 , V_9 , V_73 , V_15 ) ;
F_46 ( V_82 == - V_69 ) ;
V_73 = NULL ;
if ( V_82 )
goto V_89;
if ( V_9 -> V_16 <= V_16 ) {
V_83 |= F_40 ( V_17 , V_9 , & V_62 , V_74 ) ;
if ( V_81 == ( T_3 ) - 1 )
goto V_89;
V_15 = V_81 + 1 ;
}
goto V_90;
}
if ( V_9 -> V_15 <= V_16 && V_9 -> V_16 > V_16 ) {
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
V_82 = F_39 ( V_17 , V_9 , V_73 , V_16 + 1 ) ;
F_46 ( V_82 == - V_69 ) ;
if ( V_74 )
F_41 ( & V_9 -> V_36 ) ;
V_83 |= F_40 ( V_17 , V_73 , & V_62 , V_74 ) ;
V_73 = NULL ;
goto V_89;
}
if ( V_9 -> V_16 < V_16 && V_73 && ! F_47 () )
V_80 = F_29 ( & V_9 -> V_37 ) ;
else
V_80 = NULL ;
V_83 |= F_40 ( V_17 , V_9 , & V_62 , V_74 ) ;
if ( V_81 == ( T_3 ) - 1 )
goto V_89;
V_15 = V_81 + 1 ;
if ( V_15 <= V_16 && V_80 ) {
V_9 = F_25 ( V_80 , struct V_2 ,
V_37 ) ;
if ( V_9 -> V_15 == V_15 )
goto V_88;
}
goto V_90;
V_89:
F_48 ( & V_17 -> V_29 ) ;
if ( V_73 )
F_21 ( V_73 ) ;
return V_83 ;
V_90:
if ( V_15 > V_16 )
goto V_89;
F_48 ( & V_17 -> V_29 ) ;
if ( V_31 & V_87 )
F_49 () ;
goto V_86;
}
static int F_50 ( struct V_21 * V_17 ,
struct V_2 * V_9 )
__releases( V_17 -> V_29 )
__acquires( V_17 -> V_29 )
{
F_51 ( V_91 ) ;
F_52 ( & V_9 -> V_36 , & V_91 , V_92 ) ;
F_48 ( & V_17 -> V_29 ) ;
F_53 () ;
F_44 ( & V_17 -> V_29 ) ;
F_54 ( & V_9 -> V_36 , & V_91 ) ;
return 0 ;
}
int F_55 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , int V_62 )
{
struct V_2 * V_9 ;
struct V_37 * V_41 ;
F_44 ( & V_17 -> V_29 ) ;
V_86:
while ( 1 ) {
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
break;
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 > V_16 )
goto V_89;
if ( V_9 -> V_9 & V_62 ) {
V_15 = V_9 -> V_15 ;
F_56 ( & V_9 -> V_18 ) ;
F_50 ( V_17 , V_9 ) ;
F_21 ( V_9 ) ;
goto V_86;
}
V_15 = V_9 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( F_47 () ) {
F_48 ( & V_17 -> V_29 ) ;
F_49 () ;
F_44 ( & V_17 -> V_29 ) ;
}
}
V_89:
F_48 ( & V_17 -> V_29 ) ;
return 0 ;
}
static int F_57 ( struct V_21 * V_17 ,
struct V_2 * V_9 ,
int * V_62 )
{
int V_54 ;
int V_65 = * V_62 & ~ V_66 ;
V_54 = F_35 ( V_17 , V_9 , V_62 ) ;
if ( V_54 )
return V_54 ;
if ( ( V_65 & V_67 ) && ! ( V_9 -> V_9 & V_67 ) ) {
T_3 V_76 = V_9 -> V_16 - V_9 -> V_15 + 1 ;
V_17 -> V_28 += V_76 ;
}
V_9 -> V_9 |= V_65 ;
return 0 ;
}
static void F_58 ( struct V_2 * V_9 ,
struct V_2 * * V_93 )
{
if ( V_93 && ! ( * V_93 ) ) {
if ( V_9 -> V_9 & ( V_60 | V_61 ) ) {
* V_93 = V_9 ;
F_56 ( & V_9 -> V_18 ) ;
}
}
}
static void F_59 ( struct V_2 * * V_93 )
{
if ( V_93 && ( * V_93 ) ) {
struct V_2 * V_9 = * V_93 ;
* V_93 = NULL ;
F_21 ( V_9 ) ;
}
}
int F_60 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_94 , T_3 * V_95 ,
struct V_2 * * V_78 , T_2 V_31 )
{
struct V_2 * V_9 ;
struct V_2 * V_73 = NULL ;
struct V_37 * V_41 ;
int V_82 = 0 ;
T_3 V_96 ;
T_3 V_81 ;
V_62 |= V_85 ;
V_86:
if ( ! V_73 && ( V_31 & V_87 ) ) {
V_73 = F_14 ( V_31 ) ;
F_46 ( ! V_73 ) ;
}
F_44 ( & V_17 -> V_29 ) ;
if ( V_78 && * V_78 ) {
V_9 = * V_78 ;
if ( V_9 -> V_15 == V_15 && V_9 -> V_17 ) {
V_41 = & V_9 -> V_37 ;
goto V_88;
}
}
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
V_82 = F_37 ( V_17 , V_73 , V_15 , V_16 , & V_62 ) ;
V_73 = NULL ;
F_46 ( V_82 == - V_69 ) ;
goto V_89;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
V_88:
V_96 = V_9 -> V_15 ;
V_81 = V_9 -> V_16 ;
if ( V_9 -> V_15 == V_15 && V_9 -> V_16 <= V_16 ) {
struct V_37 * V_80 ;
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_9 -> V_15 ;
V_82 = - V_69 ;
goto V_89;
}
V_82 = F_57 ( V_17 , V_9 , & V_62 ) ;
if ( V_82 )
goto V_89;
V_80 = F_29 ( V_41 ) ;
F_58 ( V_9 , V_78 ) ;
F_33 ( V_17 , V_9 ) ;
if ( V_81 == ( T_3 ) - 1 )
goto V_89;
V_15 = V_81 + 1 ;
if ( V_80 && V_15 < V_16 && V_73 && ! F_47 () ) {
V_9 = F_25 ( V_80 , struct V_2 ,
V_37 ) ;
if ( V_9 -> V_15 == V_15 )
goto V_88;
}
goto V_90;
}
if ( V_9 -> V_15 < V_15 ) {
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_15 ;
V_82 = - V_69 ;
goto V_89;
}
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
V_82 = F_39 ( V_17 , V_9 , V_73 , V_15 ) ;
F_46 ( V_82 == - V_69 ) ;
V_73 = NULL ;
if ( V_82 )
goto V_89;
if ( V_9 -> V_16 <= V_16 ) {
V_82 = F_57 ( V_17 , V_9 , & V_62 ) ;
if ( V_82 )
goto V_89;
F_58 ( V_9 , V_78 ) ;
F_33 ( V_17 , V_9 ) ;
if ( V_81 == ( T_3 ) - 1 )
goto V_89;
V_15 = V_81 + 1 ;
}
goto V_90;
}
if ( V_9 -> V_15 > V_15 ) {
T_3 V_97 ;
if ( V_16 < V_96 )
V_97 = V_16 ;
else
V_97 = V_96 - 1 ;
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
F_56 ( & V_73 -> V_18 ) ;
V_82 = F_37 ( V_17 , V_73 , V_15 , V_97 ,
& V_62 ) ;
F_46 ( V_82 == - V_69 ) ;
if ( V_82 ) {
F_21 ( V_73 ) ;
V_73 = NULL ;
goto V_89;
}
F_58 ( V_73 , V_78 ) ;
F_21 ( V_73 ) ;
V_73 = NULL ;
V_15 = V_97 + 1 ;
goto V_90;
}
if ( V_9 -> V_15 <= V_16 && V_9 -> V_16 > V_16 ) {
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_15 ;
V_82 = - V_69 ;
goto V_89;
}
V_73 = F_42 ( V_73 ) ;
F_46 ( ! V_73 ) ;
V_82 = F_39 ( V_17 , V_9 , V_73 , V_16 + 1 ) ;
F_46 ( V_82 == - V_69 ) ;
V_82 = F_57 ( V_17 , V_73 , & V_62 ) ;
if ( V_82 ) {
V_73 = NULL ;
goto V_89;
}
F_58 ( V_73 , V_78 ) ;
F_33 ( V_17 , V_73 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_48 ( & V_17 -> V_29 ) ;
if ( V_73 )
F_21 ( V_73 ) ;
return V_82 ;
V_90:
if ( V_15 > V_16 )
goto V_89;
F_48 ( & V_17 -> V_29 ) ;
if ( V_31 & V_87 )
F_49 () ;
goto V_86;
}
int F_61 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_60 ( V_17 , V_15 , V_16 , V_67 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_62 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_60 ( V_17 , V_15 , V_16 , V_62 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_63 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_43 ( V_17 , V_15 , V_16 , V_62 , 0 , 0 , NULL , V_31 ) ;
}
int F_64 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_78 , T_2 V_31 )
{
return F_60 ( V_17 , V_15 , V_16 ,
V_98 | V_67 | V_99 ,
0 , NULL , V_78 , V_31 ) ;
}
int F_65 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_43 ( V_17 , V_15 , V_16 ,
V_67 | V_98 |
V_100 , 0 , 0 , NULL , V_31 ) ;
}
int F_66 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_60 ( V_17 , V_15 , V_16 , V_101 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_67 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_78 , T_2 V_31 )
{
return F_60 ( V_17 , V_15 , V_16 , V_99 , 0 ,
NULL , V_78 , V_31 ) ;
}
static int F_68 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 V_16 , struct V_2 * * V_78 ,
T_2 V_31 )
{
return F_43 ( V_17 , V_15 , V_16 , V_99 , 0 , 0 ,
V_78 , V_31 ) ;
}
int F_69 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , struct V_2 * * V_78 , T_2 V_31 )
{
int V_82 ;
T_3 V_95 ;
while ( 1 ) {
V_82 = F_60 ( V_17 , V_15 , V_16 , V_102 | V_62 ,
V_102 , & V_95 ,
V_78 , V_31 ) ;
if ( V_82 == - V_69 && ( V_31 & V_87 ) ) {
F_55 ( V_17 , V_95 , V_16 , V_102 ) ;
V_15 = V_95 ;
} else {
break;
}
F_23 ( V_15 > V_16 ) ;
}
return V_82 ;
}
int F_70 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_69 ( V_17 , V_15 , V_16 , 0 , NULL , V_31 ) ;
}
int F_71 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
int V_82 ;
T_3 V_95 ;
V_82 = F_60 ( V_17 , V_15 , V_16 , V_102 , V_102 ,
& V_95 , NULL , V_31 ) ;
if ( V_82 == - V_69 ) {
if ( V_95 > V_15 )
F_43 ( V_17 , V_15 , V_95 - 1 ,
V_102 , 1 , 0 , NULL , V_31 ) ;
return 0 ;
}
return 1 ;
}
int F_72 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_79 , T_2 V_31 )
{
return F_43 ( V_17 , V_15 , V_16 , V_102 , 1 , 0 , V_79 ,
V_31 ) ;
}
int F_73 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_43 ( V_17 , V_15 , V_16 , V_102 , 1 , 0 , NULL ,
V_31 ) ;
}
static int F_74 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_103 = V_15 >> V_104 ;
unsigned long V_105 = V_16 >> V_104 ;
struct V_106 * V_106 ;
while ( V_103 <= V_105 ) {
V_106 = F_75 ( V_17 -> V_23 , V_103 ) ;
F_46 ( ! V_106 ) ;
F_76 ( V_106 ) ;
F_77 ( V_106 ) ;
V_103 ++ ;
}
return 0 ;
}
int F_78 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 * V_107 , T_3 * V_108 , int V_62 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
int V_54 = 1 ;
F_44 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
goto V_89;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_16 >= V_15 && ( V_9 -> V_9 & V_62 ) ) {
* V_107 = V_9 -> V_15 ;
* V_108 = V_9 -> V_16 ;
V_54 = 0 ;
break;
}
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
}
V_89:
F_48 ( & V_17 -> V_29 ) ;
return V_54 ;
}
struct V_2 * F_79 ( struct V_21 * V_17 ,
T_3 V_15 , int V_62 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
goto V_89;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_16 >= V_15 && ( V_9 -> V_9 & V_62 ) )
return V_9 ;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
}
V_89:
return NULL ;
}
static T_4 T_3 F_80 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 * V_16 , T_3 V_109 ,
struct V_2 * * V_78 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_110 = * V_15 ;
T_3 V_68 = 0 ;
T_3 V_111 = 0 ;
F_44 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_110 ) ;
if ( ! V_41 ) {
if ( ! V_68 )
* V_16 = ( T_3 ) - 1 ;
goto V_89;
}
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_68 && ( V_9 -> V_15 != V_110 ||
( V_9 -> V_9 & V_61 ) ) ) {
goto V_89;
}
if ( ! ( V_9 -> V_9 & V_98 ) ) {
if ( ! V_68 )
* V_16 = V_9 -> V_16 ;
goto V_89;
}
if ( ! V_68 ) {
* V_15 = V_9 -> V_15 ;
* V_78 = V_9 ;
F_56 ( & V_9 -> V_18 ) ;
}
V_68 ++ ;
* V_16 = V_9 -> V_16 ;
V_110 = V_9 -> V_16 + 1 ;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
V_111 += V_9 -> V_16 - V_9 -> V_15 + 1 ;
if ( V_111 >= V_109 )
break;
}
V_89:
F_48 ( & V_17 -> V_29 ) ;
return V_68 ;
}
static T_4 int F_81 ( struct V_112 * V_112 ,
struct V_106 * V_113 ,
T_3 V_15 , T_3 V_16 )
{
int V_54 ;
struct V_106 * V_114 [ 16 ] ;
unsigned long V_103 = V_15 >> V_104 ;
unsigned long V_105 = V_16 >> V_104 ;
unsigned long V_115 = V_105 - V_103 + 1 ;
int V_116 ;
if ( V_103 == V_113 -> V_103 && V_105 == V_103 )
return 0 ;
while ( V_115 > 0 ) {
V_54 = F_82 ( V_112 -> V_117 , V_103 ,
F_83 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_114 ) ;
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_114 [ V_116 ] != V_113 )
F_84 ( V_114 [ V_116 ] ) ;
F_77 ( V_114 [ V_116 ] ) ;
}
V_115 -= V_54 ;
V_103 += V_54 ;
F_49 () ;
}
return 0 ;
}
static T_4 int F_85 ( struct V_112 * V_112 ,
struct V_106 * V_113 ,
T_3 V_118 ,
T_3 V_119 )
{
unsigned long V_103 = V_118 >> V_104 ;
unsigned long V_120 = V_103 ;
unsigned long V_105 = V_119 >> V_104 ;
unsigned long V_121 = 0 ;
struct V_106 * V_114 [ 16 ] ;
unsigned long V_122 ;
int V_54 ;
int V_116 ;
if ( V_103 == V_113 -> V_103 && V_103 == V_105 )
return 0 ;
V_122 = V_105 - V_103 + 1 ;
while ( V_122 > 0 ) {
V_54 = F_82 ( V_112 -> V_117 , V_103 ,
F_83 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_114 ) ;
if ( V_54 == 0 ) {
V_54 = - V_123 ;
goto V_124;
}
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_114 [ V_116 ] != V_113 ) {
F_86 ( V_114 [ V_116 ] ) ;
if ( ! F_87 ( V_114 [ V_116 ] ) ||
V_114 [ V_116 ] -> V_23 != V_112 -> V_117 ) {
V_54 = - V_123 ;
F_84 ( V_114 [ V_116 ] ) ;
F_77 ( V_114 [ V_116 ] ) ;
goto V_124;
}
}
F_77 ( V_114 [ V_116 ] ) ;
V_121 ++ ;
}
V_122 -= V_54 ;
V_103 += V_54 ;
F_49 () ;
}
V_54 = 0 ;
V_124:
if ( V_54 && V_121 ) {
F_81 ( V_112 , V_113 ,
V_118 ,
( ( T_3 ) ( V_120 + V_121 - 1 ) ) <<
V_104 ) ;
}
return V_54 ;
}
static T_4 T_3 F_88 ( struct V_112 * V_112 ,
struct V_21 * V_17 ,
struct V_106 * V_113 ,
T_3 * V_15 , T_3 * V_16 ,
T_3 V_109 )
{
T_3 V_118 ;
T_3 V_119 ;
T_3 V_68 ;
struct V_2 * V_78 = NULL ;
int V_54 ;
int V_125 = 0 ;
V_86:
V_118 = * V_15 ;
V_119 = 0 ;
V_68 = F_80 ( V_17 , & V_118 , & V_119 ,
V_109 , & V_78 ) ;
if ( ! V_68 || V_119 <= * V_15 ) {
* V_15 = V_118 ;
* V_16 = V_119 ;
F_21 ( V_78 ) ;
return V_68 ;
}
if ( V_118 < * V_15 )
V_118 = * V_15 ;
if ( V_119 + 1 - V_118 > V_109 && V_125 )
V_119 = V_118 + V_126 - 1 ;
V_54 = F_85 ( V_112 , V_113 ,
V_118 , V_119 ) ;
if ( V_54 == - V_123 ) {
F_21 ( V_78 ) ;
if ( ! V_125 ) {
unsigned long V_40 = ( * V_15 ) & ( V_126 - 1 ) ;
V_109 = V_126 - V_40 ;
V_125 = 1 ;
goto V_86;
} else {
V_68 = 0 ;
goto V_127;
}
}
F_46 ( V_54 ) ;
F_69 ( V_17 , V_118 , V_119 ,
0 , & V_78 , V_128 ) ;
V_54 = F_89 ( V_17 , V_118 , V_119 ,
V_98 , 1 , V_78 ) ;
if ( ! V_54 ) {
F_72 ( V_17 , V_118 , V_119 ,
& V_78 , V_128 ) ;
F_81 ( V_112 , V_113 ,
V_118 , V_119 ) ;
F_49 () ;
goto V_86;
}
F_21 ( V_78 ) ;
* V_15 = V_118 ;
* V_16 = V_119 ;
V_127:
return V_68 ;
}
int F_90 ( struct V_112 * V_112 ,
struct V_21 * V_17 ,
T_3 V_15 , T_3 V_16 , struct V_106 * V_113 ,
unsigned long V_129 )
{
int V_54 ;
struct V_106 * V_114 [ 16 ] ;
unsigned long V_103 = V_15 >> V_104 ;
unsigned long V_105 = V_16 >> V_104 ;
unsigned long V_115 = V_105 - V_103 + 1 ;
int V_116 ;
int V_130 = 0 ;
if ( V_129 & V_131 )
V_130 |= V_102 ;
if ( V_129 & V_132 )
V_130 |= V_67 ;
if ( V_129 & V_133 )
V_130 |= V_98 ;
F_43 ( V_17 , V_15 , V_16 , V_130 , 1 , 0 , NULL , V_128 ) ;
if ( ! ( V_129 & ( V_134 | V_132 |
V_135 | V_136 |
V_137 ) ) )
return 0 ;
while ( V_115 > 0 ) {
V_54 = F_82 ( V_112 -> V_117 , V_103 ,
F_83 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_114 ) ;
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_129 & V_137 )
F_91 ( V_114 [ V_116 ] ) ;
if ( V_114 [ V_116 ] == V_113 ) {
F_77 ( V_114 [ V_116 ] ) ;
continue;
}
if ( V_129 & V_132 )
F_92 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_135 )
F_76 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_136 )
F_93 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_134 )
F_84 ( V_114 [ V_116 ] ) ;
F_77 ( V_114 [ V_116 ] ) ;
}
V_115 -= V_54 ;
V_103 += V_54 ;
F_49 () ;
}
return 0 ;
}
T_3 F_94 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 V_138 , T_3 V_109 ,
unsigned long V_62 , int V_139 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_110 = * V_15 ;
T_3 V_111 = 0 ;
T_3 V_140 = 0 ;
int V_68 = 0 ;
if ( V_138 <= V_110 ) {
F_23 ( 1 ) ;
return 0 ;
}
F_44 ( & V_17 -> V_29 ) ;
if ( V_110 == 0 && V_62 == V_67 ) {
V_111 = V_17 -> V_28 ;
goto V_89;
}
V_41 = F_31 ( V_17 , V_110 ) ;
if ( ! V_41 )
goto V_89;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 > V_138 )
break;
if ( V_139 && V_68 && V_9 -> V_15 > V_140 + 1 )
break;
if ( V_9 -> V_16 >= V_110 && ( V_9 -> V_9 & V_62 ) == V_62 ) {
V_111 += F_95 ( V_138 , V_9 -> V_16 ) + 1 -
F_96 ( V_110 , V_9 -> V_15 ) ;
if ( V_111 >= V_109 )
break;
if ( ! V_68 ) {
* V_15 = F_96 ( V_110 , V_9 -> V_15 ) ;
V_68 = 1 ;
}
V_140 = V_9 -> V_16 ;
} else if ( V_139 && V_68 ) {
break;
}
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
}
V_89:
F_48 ( & V_17 -> V_29 ) ;
return V_111 ;
}
int F_97 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_34 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
int V_54 = 0 ;
F_44 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_54 = - V_141 ;
goto V_89;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 != V_15 ) {
V_54 = - V_141 ;
goto V_89;
}
V_9 -> V_34 = V_34 ;
V_89:
F_48 ( & V_17 -> V_29 ) ;
return V_54 ;
}
int F_98 ( struct V_21 * V_17 , T_3 V_15 , T_3 * V_34 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
int V_54 = 0 ;
F_44 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_54 = - V_141 ;
goto V_89;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 != V_15 ) {
V_54 = - V_141 ;
goto V_89;
}
* V_34 = V_9 -> V_34 ;
V_89:
F_48 ( & V_17 -> V_29 ) ;
return V_54 ;
}
int F_89 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_142 , struct V_2 * V_79 )
{
struct V_2 * V_9 = NULL ;
struct V_37 * V_41 ;
int V_143 = 0 ;
F_44 ( & V_17 -> V_29 ) ;
if ( V_79 && V_79 -> V_17 && V_79 -> V_15 == V_15 )
V_41 = & V_79 -> V_37 ;
else
V_41 = F_31 ( V_17 , V_15 ) ;
while ( V_41 && V_15 <= V_16 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_142 && V_9 -> V_15 > V_15 ) {
V_143 = 0 ;
break;
}
if ( V_9 -> V_15 > V_16 )
break;
if ( V_9 -> V_9 & V_62 ) {
V_143 = 1 ;
if ( ! V_142 )
break;
} else if ( V_142 ) {
V_143 = 0 ;
break;
}
if ( V_9 -> V_16 == ( T_3 ) - 1 )
break;
V_15 = V_9 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 ) {
if ( V_142 )
V_143 = 0 ;
break;
}
}
F_48 ( & V_17 -> V_29 ) ;
return V_143 ;
}
static int F_99 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( F_89 ( V_17 , V_15 , V_16 , V_99 , 1 , NULL ) )
F_100 ( V_106 ) ;
return 0 ;
}
static int F_101 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( ! F_89 ( V_17 , V_15 , V_16 , V_102 , 0 , NULL ) )
F_84 ( V_106 ) ;
return 0 ;
}
static int F_102 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
F_93 ( V_106 ) ;
return 0 ;
}
static void F_103 ( struct V_144 * V_144 , int V_82 )
{
int V_145 = V_82 == 0 ;
struct V_146 * V_147 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_150 ;
int V_54 ;
do {
struct V_106 * V_106 = V_147 -> V_151 ;
V_17 = & F_104 ( V_106 -> V_23 -> V_58 ) -> V_152 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) +
V_147 -> V_153 ;
V_16 = V_15 + V_147 -> V_154 - 1 ;
if ( V_147 -> V_153 == 0 && V_147 -> V_154 == V_126 )
V_150 = 1 ;
else
V_150 = 0 ;
if ( -- V_147 >= V_144 -> V_148 )
F_105 ( & V_147 -> V_151 -> V_33 ) ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_155 ) {
V_54 = V_17 -> V_27 -> V_155 ( V_106 , V_15 ,
V_16 , NULL , V_145 ) ;
if ( V_54 )
V_145 = 0 ;
}
if ( ! V_145 && V_17 -> V_27 &&
V_17 -> V_27 -> V_156 ) {
V_54 = V_17 -> V_27 -> V_156 ( V_144 , V_106 ,
V_15 , V_16 , NULL ) ;
if ( V_54 == 0 ) {
V_145 = ( V_82 == 0 ) ;
continue;
}
}
if ( ! V_145 ) {
F_68 ( V_17 , V_15 , V_16 , NULL , V_128 ) ;
F_106 ( V_106 ) ;
F_107 ( V_106 ) ;
}
if ( V_150 )
F_93 ( V_106 ) ;
else
F_102 ( V_17 , V_106 ) ;
} while ( V_147 >= V_144 -> V_148 );
F_108 ( V_144 ) ;
}
static void F_109 ( struct V_144 * V_144 , int V_82 )
{
int V_145 = F_110 ( V_157 , & V_144 -> V_158 ) ;
struct V_146 * V_159 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_146 * V_147 = V_144 -> V_148 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_150 ;
int V_54 ;
if ( V_82 )
V_145 = 0 ;
do {
struct V_106 * V_106 = V_147 -> V_151 ;
struct V_2 * V_79 = NULL ;
struct V_2 * V_9 ;
V_17 = & F_104 ( V_106 -> V_23 -> V_58 ) -> V_152 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) +
V_147 -> V_153 ;
V_16 = V_15 + V_147 -> V_154 - 1 ;
if ( V_147 -> V_153 == 0 && V_147 -> V_154 == V_126 )
V_150 = 1 ;
else
V_150 = 0 ;
if ( ++ V_147 <= V_159 )
F_105 ( & V_147 -> V_151 -> V_33 ) ;
F_44 ( & V_17 -> V_29 ) ;
V_9 = F_79 ( V_17 , V_15 , V_102 ) ;
if ( V_9 && V_9 -> V_15 == V_15 ) {
F_58 ( V_9 , & V_79 ) ;
}
F_48 ( & V_17 -> V_29 ) ;
if ( V_145 && V_17 -> V_27 && V_17 -> V_27 -> V_160 ) {
V_54 = V_17 -> V_27 -> V_160 ( V_106 , V_15 , V_16 ,
V_9 ) ;
if ( V_54 )
V_145 = 0 ;
}
if ( ! V_145 && V_17 -> V_27 &&
V_17 -> V_27 -> V_161 ) {
V_54 = V_17 -> V_27 -> V_161 ( V_144 , V_106 ,
V_15 , V_16 , NULL ) ;
if ( V_54 == 0 ) {
V_145 =
F_110 ( V_157 , & V_144 -> V_158 ) ;
if ( V_82 )
V_145 = 0 ;
F_59 ( & V_79 ) ;
continue;
}
}
if ( V_145 ) {
F_67 ( V_17 , V_15 , V_16 , & V_79 ,
V_26 ) ;
}
F_72 ( V_17 , V_15 , V_16 , & V_79 , V_26 ) ;
if ( V_150 ) {
if ( V_145 ) {
F_100 ( V_106 ) ;
} else {
F_106 ( V_106 ) ;
F_107 ( V_106 ) ;
}
F_84 ( V_106 ) ;
} else {
if ( V_145 ) {
F_99 ( V_17 , V_106 ) ;
} else {
F_106 ( V_106 ) ;
F_107 ( V_106 ) ;
}
F_101 ( V_17 , V_106 ) ;
}
} while ( V_147 <= V_159 );
F_108 ( V_144 ) ;
}
struct V_144 *
F_111 ( struct V_162 * V_163 , T_3 V_164 , int V_165 ,
T_2 V_166 )
{
struct V_144 * V_144 ;
V_144 = F_112 ( V_166 , V_165 ) ;
if ( V_144 == NULL && ( V_167 -> V_33 & V_168 ) ) {
while ( ! V_144 && ( V_165 /= 2 ) )
V_144 = F_112 ( V_166 , V_165 ) ;
}
if ( V_144 ) {
V_144 -> V_169 = 0 ;
V_144 -> V_170 = V_163 ;
V_144 -> V_171 = V_164 ;
}
return V_144 ;
}
static int F_113 ( int V_172 , struct V_144 * V_144 , int V_173 ,
unsigned long V_174 )
{
int V_54 = 0 ;
struct V_146 * V_147 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_106 * V_106 = V_147 -> V_151 ;
struct V_21 * V_17 = V_144 -> V_175 ;
T_3 V_15 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) + V_147 -> V_153 ;
V_144 -> V_175 = NULL ;
F_114 ( V_144 ) ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_176 )
V_54 = V_17 -> V_27 -> V_176 ( V_106 -> V_23 -> V_58 , V_172 , V_144 ,
V_173 , V_174 , V_15 ) ;
else
F_115 ( V_172 , V_144 ) ;
if ( F_116 ( V_144 , V_177 ) )
V_54 = - V_178 ;
F_108 ( V_144 ) ;
return V_54 ;
}
static int F_117 ( int V_172 , struct V_21 * V_17 ,
struct V_106 * V_106 , T_5 V_179 ,
T_6 V_180 , unsigned long V_40 ,
struct V_162 * V_163 ,
struct V_144 * * V_181 ,
unsigned long V_182 ,
T_7 V_183 ,
int V_173 ,
unsigned long V_184 ,
unsigned long V_174 )
{
int V_54 = 0 ;
struct V_144 * V_144 ;
int V_185 ;
int V_139 = 0 ;
int V_186 = V_174 & V_187 ;
int V_188 = V_184 & V_187 ;
T_6 V_189 = F_83 ( T_6 , V_180 , V_126 ) ;
if ( V_181 && * V_181 ) {
V_144 = * V_181 ;
if ( V_188 )
V_139 = V_144 -> V_171 == V_179 ;
else
V_139 = V_144 -> V_171 + ( V_144 -> V_169 >> 9 ) ==
V_179 ;
if ( V_184 != V_174 || ! V_139 ||
( V_17 -> V_27 && V_17 -> V_27 -> V_190 &&
V_17 -> V_27 -> V_190 ( V_106 , V_40 , V_189 , V_144 ,
V_174 ) ) ||
F_118 ( V_144 , V_106 , V_189 , V_40 ) < V_189 ) {
V_54 = F_113 ( V_172 , V_144 , V_173 ,
V_184 ) ;
V_144 = NULL ;
} else {
return 0 ;
}
}
if ( V_186 )
V_185 = V_191 ;
else
V_185 = F_119 ( V_163 ) ;
V_144 = F_111 ( V_163 , V_179 , V_185 , V_128 | V_192 ) ;
if ( ! V_144 )
return - V_5 ;
F_118 ( V_144 , V_106 , V_189 , V_40 ) ;
V_144 -> V_193 = V_183 ;
V_144 -> V_175 = V_17 ;
if ( V_181 )
* V_181 = V_144 ;
else
V_54 = F_113 ( V_172 , V_144 , V_173 , V_174 ) ;
return V_54 ;
}
void F_120 ( struct V_106 * V_106 )
{
if ( ! F_121 ( V_106 ) ) {
F_122 ( V_106 ) ;
F_123 ( V_106 ) ;
F_124 ( V_106 , V_194 ) ;
}
}
static void F_125 ( struct V_106 * V_106 , unsigned long V_20 )
{
F_23 ( ! F_121 ( V_106 ) ) ;
F_124 ( V_106 , V_195 | V_20 << 2 ) ;
}
static int F_126 ( struct V_21 * V_17 ,
struct V_106 * V_106 ,
T_8 * V_196 ,
struct V_144 * * V_144 , int V_173 ,
unsigned long * V_174 )
{
struct V_112 * V_112 = V_106 -> V_23 -> V_58 ;
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_197 = V_15 + V_126 - 1 ;
T_3 V_16 ;
T_3 V_198 = V_15 ;
T_3 V_199 ;
T_3 V_200 = F_127 ( V_112 ) ;
T_3 V_201 ;
T_3 V_202 ;
T_5 V_179 ;
struct V_203 * V_204 ;
struct V_162 * V_163 ;
struct V_205 * V_206 ;
int V_54 ;
int V_185 = 0 ;
T_6 V_207 = 0 ;
T_6 V_208 ;
T_6 V_209 ;
T_6 V_210 = V_112 -> V_211 -> V_212 ;
unsigned long V_213 = 0 ;
F_120 ( V_106 ) ;
if ( ! F_128 ( V_106 ) ) {
if ( F_129 ( V_106 ) == 0 ) {
F_46 ( V_210 != V_214 ) ;
goto V_89;
}
}
V_16 = V_197 ;
while ( 1 ) {
F_70 ( V_17 , V_15 , V_16 , V_128 ) ;
V_206 = F_130 ( V_112 , V_15 ) ;
if ( ! V_206 )
break;
F_73 ( V_17 , V_15 , V_16 , V_128 ) ;
F_131 ( V_112 , V_206 , 1 ) ;
F_132 ( V_206 ) ;
}
if ( V_106 -> V_103 == V_200 >> V_104 ) {
char * V_215 ;
T_6 V_216 = V_200 & ( V_126 - 1 ) ;
if ( V_216 ) {
V_208 = V_126 - V_216 ;
V_215 = F_133 ( V_106 , V_217 ) ;
memset ( V_215 + V_216 , 0 , V_208 ) ;
F_134 ( V_106 ) ;
F_135 ( V_215 , V_217 ) ;
}
}
while ( V_198 <= V_16 ) {
if ( V_198 >= V_200 ) {
char * V_215 ;
struct V_2 * V_79 = NULL ;
V_208 = V_126 - V_207 ;
V_215 = F_133 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 , V_208 ) ;
F_134 ( V_106 ) ;
F_135 ( V_215 , V_217 ) ;
F_67 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_79 , V_128 ) ;
F_72 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_79 , V_128 ) ;
break;
}
V_204 = V_196 ( V_112 , V_106 , V_207 , V_198 ,
V_16 - V_198 + 1 , 0 ) ;
if ( F_136 ( V_204 ) ) {
F_107 ( V_106 ) ;
F_73 ( V_17 , V_198 , V_16 , V_128 ) ;
break;
}
V_199 = V_198 - V_204 -> V_15 ;
F_46 ( F_137 ( V_204 ) <= V_198 ) ;
F_46 ( V_16 < V_198 ) ;
if ( F_110 ( V_218 , & V_204 -> V_33 ) ) {
V_213 = V_187 ;
F_138 ( & V_213 ,
V_204 -> V_219 ) ;
}
V_208 = F_95 ( F_137 ( V_204 ) - V_198 , V_16 - V_198 + 1 ) ;
V_202 = F_95 ( F_137 ( V_204 ) - 1 , V_16 ) ;
V_208 = ( V_208 + V_210 - 1 ) & ~ ( ( T_3 ) V_210 - 1 ) ;
if ( V_213 & V_187 ) {
V_209 = V_204 -> V_220 ;
V_179 = V_204 -> V_201 >> 9 ;
} else {
V_179 = ( V_204 -> V_201 + V_199 ) >> 9 ;
V_209 = V_208 ;
}
V_163 = V_204 -> V_163 ;
V_201 = V_204 -> V_201 ;
if ( F_110 ( V_221 , & V_204 -> V_33 ) )
V_201 = V_222 ;
F_139 ( V_204 ) ;
V_204 = NULL ;
if ( V_201 == V_222 ) {
char * V_215 ;
struct V_2 * V_79 = NULL ;
V_215 = F_133 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 , V_208 ) ;
F_134 ( V_106 ) ;
F_135 ( V_215 , V_217 ) ;
F_67 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_79 , V_128 ) ;
F_72 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_79 , V_128 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
if ( F_89 ( V_17 , V_198 , V_202 ,
V_99 , 1 , NULL ) ) {
F_99 ( V_17 , V_106 ) ;
F_73 ( V_17 , V_198 , V_198 + V_208 - 1 , V_128 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
if ( V_201 == V_223 ) {
F_107 ( V_106 ) ;
F_73 ( V_17 , V_198 , V_198 + V_208 - 1 , V_128 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
V_54 = 0 ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_224 ) {
V_54 = V_17 -> V_27 -> V_224 ( V_106 , V_198 ,
V_198 + V_208 - 1 ) ;
}
if ( ! V_54 ) {
unsigned long V_225 = ( V_200 >> V_104 ) + 1 ;
V_225 -= V_106 -> V_103 ;
V_54 = F_117 ( V_226 , V_17 , V_106 ,
V_179 , V_209 , V_207 ,
V_163 , V_144 , V_225 ,
F_109 , V_173 ,
* V_174 ,
V_213 ) ;
V_185 ++ ;
* V_174 = V_213 ;
}
if ( V_54 )
F_107 ( V_106 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
}
V_89:
if ( ! V_185 ) {
if ( ! F_140 ( V_106 ) )
F_100 ( V_106 ) ;
F_84 ( V_106 ) ;
}
return 0 ;
}
int F_141 ( struct V_21 * V_17 , struct V_106 * V_106 ,
T_8 * V_196 )
{
struct V_144 * V_144 = NULL ;
unsigned long V_174 = 0 ;
int V_54 ;
V_54 = F_126 ( V_17 , V_106 , V_196 , & V_144 , 0 ,
& V_174 ) ;
if ( V_144 )
V_54 = F_113 ( V_226 , V_144 , 0 , V_174 ) ;
return V_54 ;
}
static T_4 void F_142 ( struct V_106 * V_106 ,
struct V_227 * V_228 ,
unsigned long V_229 )
{
V_228 -> V_230 -= V_229 ;
if ( V_228 -> V_231 || ( V_228 -> V_230 > 0 &&
V_228 -> V_232 == 0 && V_228 -> V_233 == V_234 ) )
V_106 -> V_23 -> V_235 = V_106 -> V_103 + V_229 ;
}
static int F_143 ( struct V_106 * V_106 , struct V_227 * V_228 ,
void * V_236 )
{
struct V_112 * V_112 = V_106 -> V_23 -> V_58 ;
struct V_237 * V_238 = V_236 ;
struct V_21 * V_17 = V_238 -> V_17 ;
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_118 ;
T_3 V_197 = V_15 + V_126 - 1 ;
T_3 V_16 ;
T_3 V_198 = V_15 ;
T_3 V_199 ;
T_3 V_200 = F_127 ( V_112 ) ;
T_3 V_201 ;
T_3 V_208 ;
T_5 V_179 ;
struct V_2 * V_78 = NULL ;
struct V_203 * V_204 ;
struct V_162 * V_163 ;
int V_54 ;
int V_185 = 0 ;
T_6 V_207 = 0 ;
T_6 V_210 ;
T_9 V_239 = F_127 ( V_112 ) ;
unsigned long V_105 = V_239 >> V_104 ;
T_3 V_240 ;
T_3 V_119 ;
int V_241 ;
int V_242 ;
int V_243 ;
unsigned long V_229 = 0 ;
if ( V_228 -> V_244 == V_245 )
V_243 = V_246 ;
else
V_243 = V_247 ;
F_144 ( V_106 , V_112 , V_228 ) ;
F_23 ( ! F_145 ( V_106 ) ) ;
V_207 = V_239 & ( V_126 - 1 ) ;
if ( V_106 -> V_103 > V_105 ||
( V_106 -> V_103 == V_105 && ! V_207 ) ) {
V_106 -> V_23 -> V_248 -> V_249 ( V_106 , 0 ) ;
F_84 ( V_106 ) ;
return 0 ;
}
if ( V_106 -> V_103 == V_105 ) {
char * V_215 ;
V_215 = F_133 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 ,
V_126 - V_207 ) ;
F_135 ( V_215 , V_217 ) ;
F_134 ( V_106 ) ;
}
V_207 = 0 ;
F_120 ( V_106 ) ;
V_118 = V_15 ;
V_119 = 0 ;
V_241 = 0 ;
if ( ! V_238 -> V_250 ) {
T_3 V_251 = 0 ;
F_142 ( V_106 , V_228 , 0 ) ;
while ( V_119 < V_197 ) {
V_240 = F_88 ( V_112 , V_17 ,
V_106 ,
& V_118 ,
& V_119 ,
128 * 1024 * 1024 ) ;
if ( V_240 == 0 ) {
V_118 = V_119 + 1 ;
continue;
}
V_17 -> V_27 -> V_252 ( V_112 , V_106 , V_118 ,
V_119 , & V_241 ,
& V_229 ) ;
V_251 += ( V_119 - V_118 +
V_126 ) >>
V_104 ;
V_118 = V_119 + 1 ;
}
if ( V_228 -> V_230 < V_251 ) {
int V_253 = 8192 ;
if ( V_251 < V_253 * 2 )
V_253 = V_251 ;
V_228 -> V_230 = F_83 ( T_3 , V_251 ,
V_253 ) ;
}
if ( V_241 ) {
V_54 = 0 ;
V_228 -> V_230 -= V_229 ;
goto V_254;
}
}
if ( V_17 -> V_27 && V_17 -> V_27 -> V_255 ) {
V_54 = V_17 -> V_27 -> V_255 ( V_106 , V_15 ,
V_197 ) ;
if ( V_54 == - V_123 ) {
F_146 ( V_228 , V_106 ) ;
F_142 ( V_106 , V_228 , V_229 ) ;
F_84 ( V_106 ) ;
V_54 = 0 ;
goto V_254;
}
}
F_142 ( V_106 , V_228 , V_229 + 1 ) ;
V_16 = V_197 ;
if ( V_200 <= V_15 ) {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_155 )
V_17 -> V_27 -> V_155 ( V_106 , V_15 ,
V_197 , NULL , 1 ) ;
goto V_124;
}
V_210 = V_112 -> V_211 -> V_212 ;
while ( V_198 <= V_16 ) {
if ( V_198 >= V_200 ) {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_155 )
V_17 -> V_27 -> V_155 ( V_106 , V_198 ,
V_197 , NULL , 1 ) ;
break;
}
V_204 = V_238 -> V_196 ( V_112 , V_106 , V_207 , V_198 ,
V_16 - V_198 + 1 , 1 ) ;
if ( F_136 ( V_204 ) ) {
F_107 ( V_106 ) ;
break;
}
V_199 = V_198 - V_204 -> V_15 ;
F_46 ( F_137 ( V_204 ) <= V_198 ) ;
F_46 ( V_16 < V_198 ) ;
V_208 = F_95 ( F_137 ( V_204 ) - V_198 , V_16 - V_198 + 1 ) ;
V_208 = ( V_208 + V_210 - 1 ) & ~ ( ( T_3 ) V_210 - 1 ) ;
V_179 = ( V_204 -> V_201 + V_199 ) >> 9 ;
V_163 = V_204 -> V_163 ;
V_201 = V_204 -> V_201 ;
V_242 = F_110 ( V_218 , & V_204 -> V_33 ) ;
F_139 ( V_204 ) ;
V_204 = NULL ;
if ( V_242 || V_201 == V_222 ||
V_201 == V_223 ) {
if ( ! V_242 && V_17 -> V_27 &&
V_17 -> V_27 -> V_155 )
V_17 -> V_27 -> V_155 ( V_106 , V_198 ,
V_198 + V_208 - 1 ,
NULL , 1 ) ;
else if ( V_242 ) {
V_185 ++ ;
}
V_198 += V_208 ;
V_207 += V_208 ;
continue;
}
if ( 0 && ! F_89 ( V_17 , V_198 , V_198 + V_208 - 1 ,
V_67 , 0 , NULL ) ) {
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
if ( V_17 -> V_27 && V_17 -> V_27 -> V_256 ) {
V_54 = V_17 -> V_27 -> V_256 ( V_106 , V_198 ,
V_198 + V_208 - 1 ) ;
} else {
V_54 = 0 ;
}
if ( V_54 ) {
F_107 ( V_106 ) ;
} else {
unsigned long V_257 = V_105 + 1 ;
F_74 ( V_17 , V_198 , V_198 + V_208 - 1 ) ;
if ( ! F_147 ( V_106 ) ) {
F_7 ( V_14 L_10
L_11 ,
V_106 -> V_103 , ( unsigned long long ) V_198 ,
( unsigned long long ) V_16 ) ;
}
V_54 = F_117 ( V_243 , V_17 , V_106 ,
V_179 , V_208 , V_207 ,
V_163 , & V_238 -> V_144 , V_257 ,
F_103 ,
0 , 0 , 0 ) ;
if ( V_54 )
F_107 ( V_106 ) ;
}
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
V_185 ++ ;
}
V_124:
if ( V_185 == 0 ) {
F_76 ( V_106 ) ;
F_93 ( V_106 ) ;
}
F_84 ( V_106 ) ;
V_254:
F_21 ( V_78 ) ;
return 0 ;
}
static int F_148 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_227 * V_228 ,
T_10 V_258 , void * V_236 ,
void (* F_149)( void * ) )
{
int V_54 = 0 ;
int V_124 = 0 ;
int V_259 = 0 ;
struct V_260 V_261 ;
int V_115 ;
T_11 V_103 ;
T_11 V_16 ;
int V_262 = 0 ;
F_150 ( & V_261 , 0 ) ;
if ( V_228 -> V_231 ) {
V_103 = V_23 -> V_235 ;
V_16 = - 1 ;
} else {
V_103 = V_228 -> V_232 >> V_104 ;
V_16 = V_228 -> V_233 >> V_104 ;
V_262 = 1 ;
}
V_263:
while ( ! V_124 && ! V_259 && ( V_103 <= V_16 ) &&
( V_115 = F_151 ( & V_261 , V_23 , & V_103 ,
V_264 , F_95 ( V_16 - V_103 ,
( T_11 ) V_265 - 1 ) + 1 ) ) ) {
unsigned V_116 ;
V_262 = 1 ;
for ( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
struct V_106 * V_106 = V_261 . V_114 [ V_116 ] ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_266 )
V_17 -> V_27 -> V_266 ( V_106 ) ;
else
F_86 ( V_106 ) ;
if ( F_152 ( V_106 -> V_23 != V_23 ) ) {
F_84 ( V_106 ) ;
continue;
}
if ( ! V_228 -> V_231 && V_106 -> V_103 > V_16 ) {
V_124 = 1 ;
F_84 ( V_106 ) ;
continue;
}
if ( V_228 -> V_244 != V_267 ) {
if ( F_147 ( V_106 ) )
F_149 ( V_236 ) ;
F_153 ( V_106 ) ;
}
if ( F_147 ( V_106 ) ||
! F_92 ( V_106 ) ) {
F_84 ( V_106 ) ;
continue;
}
V_54 = (* V_258)( V_106 , V_228 , V_236 ) ;
if ( F_152 ( V_54 == V_268 ) ) {
F_84 ( V_106 ) ;
V_54 = 0 ;
}
if ( V_54 )
V_124 = 1 ;
V_259 = V_228 -> V_230 <= 0 ;
}
F_154 ( & V_261 ) ;
F_49 () ;
}
if ( ! V_262 && ! V_124 ) {
V_262 = 1 ;
V_103 = 0 ;
goto V_263;
}
return V_54 ;
}
static void F_155 ( struct V_237 * V_238 )
{
if ( V_238 -> V_144 ) {
if ( V_238 -> V_269 )
F_113 ( V_246 , V_238 -> V_144 , 0 , 0 ) ;
else
F_113 ( V_247 , V_238 -> V_144 , 0 , 0 ) ;
V_238 -> V_144 = NULL ;
}
}
static T_4 void F_156 ( void * V_236 )
{
struct V_237 * V_238 = V_236 ;
F_155 ( V_238 ) ;
}
int F_157 ( struct V_21 * V_17 , struct V_106 * V_106 ,
T_8 * V_196 ,
struct V_227 * V_228 )
{
int V_54 ;
struct V_22 * V_23 = V_106 -> V_23 ;
struct V_237 V_238 = {
. V_144 = NULL ,
. V_17 = V_17 ,
. V_196 = V_196 ,
. V_250 = 0 ,
. V_269 = V_228 -> V_244 == V_245 ,
} ;
struct V_227 V_270 = {
. V_244 = V_228 -> V_244 ,
. V_271 = NULL ,
. V_230 = 64 ,
. V_232 = F_158 ( V_106 ) + V_126 ,
. V_233 = ( T_9 ) - 1 ,
} ;
V_54 = F_143 ( V_106 , V_228 , & V_238 ) ;
F_148 ( V_17 , V_23 , & V_270 ,
F_143 , & V_238 , F_156 ) ;
F_155 ( & V_238 ) ;
return V_54 ;
}
int F_159 ( struct V_21 * V_17 , struct V_112 * V_112 ,
T_3 V_15 , T_3 V_16 , T_8 * V_196 ,
int V_272 )
{
int V_54 = 0 ;
struct V_22 * V_23 = V_112 -> V_117 ;
struct V_106 * V_106 ;
unsigned long V_115 = ( V_16 - V_15 + V_126 ) >>
V_104 ;
struct V_237 V_238 = {
. V_144 = NULL ,
. V_17 = V_17 ,
. V_196 = V_196 ,
. V_250 = 1 ,
. V_269 = V_272 == V_245 ,
} ;
struct V_227 V_270 = {
. V_244 = V_272 ,
. V_271 = NULL ,
. V_230 = V_115 * 2 ,
. V_232 = V_15 ,
. V_233 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_106 = F_75 ( V_23 , V_15 >> V_104 ) ;
if ( F_92 ( V_106 ) )
V_54 = F_143 ( V_106 , & V_270 , & V_238 ) ;
else {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_155 )
V_17 -> V_27 -> V_155 ( V_106 , V_15 ,
V_15 + V_126 - 1 ,
NULL , 1 ) ;
F_84 ( V_106 ) ;
}
F_77 ( V_106 ) ;
V_15 += V_126 ;
}
F_155 ( & V_238 ) ;
return V_54 ;
}
int F_160 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
T_8 * V_196 ,
struct V_227 * V_228 )
{
int V_54 = 0 ;
struct V_237 V_238 = {
. V_144 = NULL ,
. V_17 = V_17 ,
. V_196 = V_196 ,
. V_250 = 0 ,
. V_269 = V_228 -> V_244 == V_245 ,
} ;
V_54 = F_148 ( V_17 , V_23 , V_228 ,
F_143 , & V_238 ,
F_156 ) ;
F_155 ( & V_238 ) ;
return V_54 ;
}
int F_161 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_273 * V_114 , unsigned V_115 ,
T_8 V_196 )
{
struct V_144 * V_144 = NULL ;
unsigned V_274 ;
unsigned long V_174 = 0 ;
for ( V_274 = 0 ; V_274 < V_115 ; V_274 ++ ) {
struct V_106 * V_106 = F_6 ( V_114 -> V_51 , struct V_106 , V_275 ) ;
F_105 ( & V_106 -> V_33 ) ;
F_9 ( & V_106 -> V_275 ) ;
if ( ! F_162 ( V_106 , V_23 ,
V_106 -> V_103 , V_128 ) ) {
F_126 ( V_17 , V_106 , V_196 ,
& V_144 , 0 , & V_174 ) ;
}
F_77 ( V_106 ) ;
}
F_46 ( ! F_5 ( V_114 ) ) ;
if ( V_144 )
F_113 ( V_226 , V_144 , 0 , V_174 ) ;
return 0 ;
}
int F_163 ( struct V_21 * V_17 ,
struct V_106 * V_106 , unsigned long V_40 )
{
struct V_2 * V_78 = NULL ;
T_3 V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) ;
T_3 V_16 = V_15 + V_126 - 1 ;
T_6 V_210 = V_106 -> V_23 -> V_58 -> V_211 -> V_212 ;
V_15 += ( V_40 + V_210 - 1 ) & ~ ( V_210 - 1 ) ;
if ( V_15 > V_16 )
return 0 ;
F_69 ( V_17 , V_15 , V_16 , 0 , & V_78 , V_128 ) ;
F_153 ( V_106 ) ;
F_43 ( V_17 , V_15 , V_16 ,
V_102 | V_67 | V_98 |
V_100 ,
1 , 1 , & V_78 , V_128 ) ;
return 0 ;
}
int F_164 ( struct V_276 * V_277 ,
struct V_21 * V_17 , struct V_106 * V_106 ,
T_2 V_31 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
int V_54 = 1 ;
if ( F_89 ( V_17 , V_15 , V_16 ,
V_60 , 0 , NULL ) )
V_54 = 0 ;
else {
if ( ( V_31 & V_128 ) == V_128 )
V_31 = V_128 ;
V_54 = F_43 ( V_17 , V_15 , V_16 ,
~ ( V_102 | V_278 ) ,
0 , 0 , NULL , V_31 ) ;
if ( V_54 < 0 )
V_54 = 0 ;
else
V_54 = 1 ;
}
return V_54 ;
}
int F_165 ( struct V_276 * V_277 ,
struct V_21 * V_17 , struct V_106 * V_106 ,
T_2 V_31 )
{
struct V_203 * V_204 ;
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( ( V_31 & V_87 ) &&
V_106 -> V_23 -> V_58 -> V_239 > 16 * 1024 * 1024 ) {
T_3 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_166 ( & V_277 -> V_29 ) ;
V_204 = F_167 ( V_277 , V_15 , V_20 ) ;
if ( F_136 ( V_204 ) ) {
F_168 ( & V_277 -> V_29 ) ;
break;
}
if ( F_110 ( V_279 , & V_204 -> V_33 ) ||
V_204 -> V_15 != V_15 ) {
F_168 ( & V_277 -> V_29 ) ;
F_139 ( V_204 ) ;
break;
}
if ( ! F_89 ( V_17 , V_204 -> V_15 ,
F_137 ( V_204 ) - 1 ,
V_102 | V_280 ,
0 , NULL ) ) {
F_169 ( V_277 , V_204 ) ;
F_139 ( V_204 ) ;
}
V_15 = F_137 ( V_204 ) ;
F_168 ( & V_277 -> V_29 ) ;
F_139 ( V_204 ) ;
}
}
return F_164 ( V_277 , V_17 , V_106 , V_31 ) ;
}
static struct V_203 * F_170 ( struct V_112 * V_112 ,
T_3 V_40 ,
T_3 V_140 ,
T_8 * V_196 )
{
T_3 V_281 = F_104 ( V_112 ) -> V_39 -> V_281 ;
struct V_203 * V_204 ;
T_3 V_20 ;
if ( V_40 >= V_140 )
return NULL ;
while( 1 ) {
V_20 = V_140 - V_40 ;
if ( V_20 == 0 )
break;
V_20 = ( V_20 + V_281 - 1 ) & ~ ( V_281 - 1 ) ;
V_204 = V_196 ( V_112 , NULL , 0 , V_40 , V_20 , 0 ) ;
if ( F_136 ( V_204 ) )
return V_204 ;
if ( ! F_110 ( V_282 , & V_204 -> V_33 ) &&
V_204 -> V_201 != V_222 ) {
return V_204 ;
}
V_40 = F_137 ( V_204 ) ;
F_139 ( V_204 ) ;
if ( V_40 >= V_140 )
break;
}
return NULL ;
}
int F_171 ( struct V_112 * V_112 , struct V_283 * V_284 ,
T_12 V_15 , T_12 V_20 , T_8 * V_196 )
{
int V_54 = 0 ;
T_3 V_285 = V_15 ;
T_3 F_96 = V_15 + V_20 ;
T_13 V_33 = 0 ;
T_13 V_286 ;
T_3 V_140 ;
T_3 V_287 = 0 ;
T_3 V_288 = 0 ;
T_3 V_289 = F_127 ( V_112 ) ;
struct V_290 V_291 ;
struct V_203 * V_204 = NULL ;
struct V_2 * V_78 = NULL ;
struct V_292 * V_293 ;
struct V_294 * V_295 ;
int V_16 = 0 ;
T_3 V_296 = 0 ;
T_3 V_297 = 0 ;
T_3 V_298 = 0 ;
unsigned long V_299 ;
if ( V_20 == 0 )
return - V_300 ;
V_293 = F_172 () ;
if ( ! V_293 )
return - V_5 ;
V_293 -> V_301 = 1 ;
V_54 = F_173 ( NULL , F_104 ( V_112 ) -> V_39 ,
V_293 , F_174 ( V_112 ) , - 1 , 0 ) ;
if ( V_54 < 0 ) {
F_175 ( V_293 ) ;
return V_54 ;
}
F_23 ( ! V_54 ) ;
V_293 -> V_302 [ 0 ] -- ;
V_295 = F_176 ( V_293 -> V_303 [ 0 ] , V_293 -> V_302 [ 0 ] ,
struct V_294 ) ;
F_177 ( V_293 -> V_303 [ 0 ] , & V_291 , V_293 -> V_302 [ 0 ] ) ;
V_286 = F_178 ( & V_291 ) ;
if ( V_291 . V_304 != F_174 ( V_112 ) ||
V_286 != V_305 ) {
V_140 = ( T_3 ) - 1 ;
V_287 = V_289 ;
} else {
V_140 = V_291 . V_40 ;
V_287 = V_140 + 1 ;
}
F_175 ( V_293 ) ;
if ( V_140 < V_289 ) {
V_140 = ( T_3 ) - 1 ;
V_287 = V_289 ;
}
F_69 ( & F_104 ( V_112 ) -> V_152 , V_15 , V_15 + V_20 , 0 ,
& V_78 , V_128 ) ;
V_204 = F_170 ( V_112 , V_285 , V_287 ,
V_196 ) ;
if ( ! V_204 )
goto V_89;
if ( F_179 ( V_204 ) ) {
V_54 = F_180 ( V_204 ) ;
goto V_89;
}
while ( ! V_16 ) {
T_3 V_306 ;
if ( V_204 -> V_15 >= F_96 || F_137 ( V_204 ) < V_285 )
break;
V_296 = F_96 ( V_204 -> V_15 , V_285 ) ;
V_306 = V_296 - V_204 -> V_15 ;
V_298 = F_137 ( V_204 ) ;
V_297 = V_298 - V_296 ;
V_299 = V_204 -> V_33 ;
V_288 = 0 ;
V_33 = 0 ;
V_285 = F_137 ( V_204 ) ;
if ( V_285 >= F_96 )
V_16 = 1 ;
if ( V_204 -> V_201 == V_307 ) {
V_16 = 1 ;
V_33 |= V_308 ;
} else if ( V_204 -> V_201 == V_223 ) {
V_33 |= ( V_309 |
V_310 ) ;
} else if ( V_204 -> V_201 == V_311 ) {
V_33 |= ( V_312 |
V_313 ) ;
} else {
V_288 = V_204 -> V_201 + V_306 ;
}
if ( F_110 ( V_218 , & V_204 -> V_33 ) )
V_33 |= V_314 ;
F_139 ( V_204 ) ;
V_204 = NULL ;
if ( ( V_296 >= V_140 ) || V_297 == ( T_3 ) - 1 ||
( V_140 == ( T_3 ) - 1 && V_289 <= V_298 ) ) {
V_33 |= V_308 ;
V_16 = 1 ;
}
V_204 = F_170 ( V_112 , V_285 , V_287 ,
V_196 ) ;
if ( F_179 ( V_204 ) ) {
V_54 = F_180 ( V_204 ) ;
goto V_89;
}
if ( ! V_204 ) {
V_33 |= V_308 ;
V_16 = 1 ;
}
V_54 = F_181 ( V_284 , V_296 , V_288 ,
V_297 , V_33 ) ;
if ( V_54 )
goto V_315;
}
V_315:
F_139 ( V_204 ) ;
V_89:
F_72 ( & F_104 ( V_112 ) -> V_152 , V_15 , V_15 + V_20 ,
& V_78 , V_128 ) ;
return V_54 ;
}
static inline struct V_106 * F_182 ( struct V_7 * V_10 ,
unsigned long V_116 )
{
struct V_106 * V_42 ;
struct V_22 * V_23 ;
if ( V_116 == 0 )
return V_10 -> V_316 ;
V_116 += V_10 -> V_15 >> V_104 ;
V_23 = V_10 -> V_316 -> V_23 ;
if ( ! V_23 )
return NULL ;
F_183 () ;
V_42 = F_184 ( & V_23 -> V_317 , V_116 ) ;
F_185 () ;
return V_42 ;
}
static inline unsigned long F_186 ( T_3 V_15 , T_3 V_20 )
{
return ( ( V_15 + V_20 + V_126 - 1 ) >> V_104 ) -
( V_15 >> V_104 ) ;
}
static struct V_7 * F_187 ( struct V_21 * V_17 ,
T_3 V_15 ,
unsigned long V_20 ,
T_2 V_31 )
{
struct V_7 * V_10 = NULL ;
#if V_32
unsigned long V_33 ;
#endif
V_10 = F_188 ( V_6 , V_31 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_20 = V_20 ;
F_13 ( & V_10 -> V_29 ) ;
F_20 ( & V_10 -> V_318 ) ;
#if V_32
F_16 ( & V_35 , V_33 ) ;
F_17 ( & V_10 -> V_13 , & V_19 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_19 ( & V_10 -> V_18 , 1 ) ;
return V_10 ;
}
static void F_189 ( struct V_7 * V_10 )
{
#if V_32
unsigned long V_33 ;
F_16 ( & V_35 , V_33 ) ;
F_9 ( & V_10 -> V_13 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_10 ( V_6 , V_10 ) ;
}
static void F_190 ( struct V_7 * V_10 ,
unsigned long V_319 )
{
unsigned long V_103 ;
struct V_106 * V_106 ;
if ( ! V_10 -> V_316 )
return;
V_103 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
if ( V_319 >= V_103 )
return;
do {
V_103 -- ;
V_106 = F_182 ( V_10 , V_103 ) ;
if ( V_106 )
F_77 ( V_106 ) ;
} while ( V_103 != V_319 );
}
static inline void F_191 ( struct V_7 * V_10 )
{
F_190 ( V_10 , 0 ) ;
F_189 ( V_10 ) ;
}
struct V_7 * F_192 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 ,
struct V_106 * V_320 )
{
unsigned long V_321 = F_186 ( V_15 , V_20 ) ;
unsigned long V_116 ;
unsigned long V_103 = V_15 >> V_104 ;
struct V_7 * V_10 ;
struct V_7 * V_322 = NULL ;
struct V_106 * V_42 ;
struct V_22 * V_23 = V_17 -> V_23 ;
int V_145 = 1 ;
int V_54 ;
F_183 () ;
V_10 = F_184 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( V_10 && F_193 ( & V_10 -> V_18 ) ) {
F_185 () ;
F_194 ( V_10 -> V_316 ) ;
return V_10 ;
}
F_185 () ;
V_10 = F_187 ( V_17 , V_15 , V_20 , V_128 ) ;
if ( ! V_10 )
return NULL ;
if ( V_320 ) {
V_10 -> V_316 = V_320 ;
V_116 = 1 ;
V_103 ++ ;
F_123 ( V_320 ) ;
F_194 ( V_320 ) ;
F_120 ( V_320 ) ;
F_125 ( V_320 , V_20 ) ;
V_145 = F_128 ( V_320 ) ;
} else {
V_116 = 0 ;
}
for (; V_116 < V_321 ; V_116 ++ , V_103 ++ ) {
V_42 = F_195 ( V_23 , V_103 , V_128 | V_323 ) ;
if ( ! V_42 ) {
F_23 ( 1 ) ;
goto V_324;
}
F_120 ( V_42 ) ;
F_194 ( V_42 ) ;
if ( V_116 == 0 ) {
V_10 -> V_316 = V_42 ;
F_125 ( V_42 , V_20 ) ;
} else {
F_124 ( V_42 , V_194 ) ;
}
if ( ! F_128 ( V_42 ) )
V_145 = 0 ;
if ( V_116 != 0 )
F_84 ( V_42 ) ;
}
if ( V_145 )
F_196 ( V_325 , & V_10 -> V_326 ) ;
V_54 = F_197 ( V_128 & ~ V_323 ) ;
if ( V_54 )
goto V_324;
F_44 ( & V_17 -> V_30 ) ;
V_54 = F_198 ( & V_17 -> V_25 , V_15 >> V_104 , V_10 ) ;
if ( V_54 == - V_69 ) {
V_322 = F_184 ( & V_17 -> V_25 ,
V_15 >> V_104 ) ;
F_56 ( & V_322 -> V_18 ) ;
F_48 ( & V_17 -> V_30 ) ;
F_199 () ;
goto V_324;
}
F_56 ( & V_10 -> V_18 ) ;
F_48 ( & V_17 -> V_30 ) ;
F_199 () ;
F_120 ( V_10 -> V_316 ) ;
F_125 ( V_10 -> V_316 , V_10 -> V_20 ) ;
if ( ! V_320 )
F_84 ( V_10 -> V_316 ) ;
return V_10 ;
V_324:
if ( V_10 -> V_316 && ! V_320 )
F_84 ( V_10 -> V_316 ) ;
if ( ! F_22 ( & V_10 -> V_18 ) )
return V_322 ;
F_191 ( V_10 ) ;
return V_322 ;
}
struct V_7 * F_200 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 )
{
struct V_7 * V_10 ;
F_183 () ;
V_10 = F_184 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( V_10 && F_193 ( & V_10 -> V_18 ) ) {
F_185 () ;
F_194 ( V_10 -> V_316 ) ;
return V_10 ;
}
F_185 () ;
return NULL ;
}
void F_201 ( struct V_7 * V_10 )
{
if ( ! V_10 )
return;
if ( ! F_22 ( & V_10 -> V_18 ) )
return;
F_23 ( 1 ) ;
}
int F_202 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
unsigned long V_321 ;
struct V_106 * V_106 ;
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
if ( ! F_87 ( V_106 ) )
continue;
F_86 ( V_106 ) ;
F_23 ( ! F_121 ( V_106 ) ) ;
F_120 ( V_106 ) ;
if ( V_116 == 0 )
F_125 ( V_106 , V_10 -> V_20 ) ;
F_92 ( V_106 ) ;
F_203 ( & V_106 -> V_23 -> V_327 ) ;
if ( ! F_87 ( V_106 ) ) {
F_204 ( & V_106 -> V_23 -> V_317 ,
F_205 ( V_106 ) ,
V_264 ) ;
}
F_206 ( & V_106 -> V_23 -> V_327 ) ;
F_84 ( V_106 ) ;
}
return 0 ;
}
int F_207 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
unsigned long V_321 ;
int V_328 = 0 ;
V_328 = F_208 ( V_329 , & V_10 -> V_326 ) ;
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_321 ; V_116 ++ )
F_209 ( F_182 ( V_10 , V_116 ) ) ;
return V_328 ;
}
int F_210 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * * V_78 )
{
unsigned long V_116 ;
struct V_106 * V_106 ;
unsigned long V_321 ;
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
F_211 ( V_325 , & V_10 -> V_326 ) ;
F_68 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_78 , V_128 ) ;
for ( V_116 = 0 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
if ( V_106 )
F_106 ( V_106 ) ;
}
return 0 ;
}
int F_212 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
struct V_106 * V_106 ;
unsigned long V_321 ;
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
F_67 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
NULL , V_128 ) ;
for ( V_116 = 0 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
if ( ( V_116 == 0 && ( V_10 -> V_15 & ( V_126 - 1 ) ) ) ||
( ( V_116 == V_321 - 1 ) &&
( ( V_10 -> V_15 + V_10 -> V_20 ) & ( V_126 - 1 ) ) ) ) {
F_99 ( V_17 , V_106 ) ;
continue;
}
F_100 ( V_106 ) ;
}
return 0 ;
}
int F_213 ( struct V_21 * V_17 ,
T_3 V_15 , T_3 V_16 )
{
struct V_106 * V_106 ;
int V_54 ;
int V_330 = 1 ;
int V_145 ;
unsigned long V_103 ;
V_54 = F_89 ( V_17 , V_15 , V_16 , V_99 , 1 , NULL ) ;
if ( V_54 )
return 1 ;
while ( V_15 <= V_16 ) {
V_103 = V_15 >> V_104 ;
V_106 = F_75 ( V_17 -> V_23 , V_103 ) ;
V_145 = F_128 ( V_106 ) ;
F_77 ( V_106 ) ;
if ( ! V_145 ) {
V_330 = 0 ;
break;
}
V_15 += V_126 ;
}
return V_330 ;
}
int F_214 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * V_78 )
{
int V_54 = 0 ;
unsigned long V_321 ;
unsigned long V_116 ;
struct V_106 * V_106 ;
int V_330 = 1 ;
if ( F_110 ( V_325 , & V_10 -> V_326 ) )
return 1 ;
V_54 = F_89 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_99 , 1 , V_78 ) ;
if ( V_54 )
return V_54 ;
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
if ( ! F_128 ( V_106 ) ) {
V_330 = 0 ;
break;
}
}
return V_330 ;
}
int F_215 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
T_3 V_15 , int V_91 ,
T_8 * V_196 , int V_173 )
{
unsigned long V_116 ;
unsigned long V_331 ;
struct V_106 * V_106 ;
int V_82 ;
int V_54 = 0 ;
int V_332 = 0 ;
int V_333 = 1 ;
int V_334 = 0 ;
unsigned long V_321 ;
struct V_144 * V_144 = NULL ;
unsigned long V_174 = 0 ;
if ( F_110 ( V_325 , & V_10 -> V_326 ) )
return 0 ;
if ( F_89 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_99 , 1 , NULL ) ) {
return 0 ;
}
if ( V_15 ) {
F_23 ( V_15 < V_10 -> V_15 ) ;
V_331 = ( V_15 >> V_104 ) -
( V_10 -> V_15 >> V_104 ) ;
} else {
V_331 = 0 ;
}
V_321 = F_186 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = V_331 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
if ( ! V_91 ) {
if ( ! F_216 ( V_106 ) )
goto V_335;
} else {
F_86 ( V_106 ) ;
}
V_332 ++ ;
if ( ! F_128 ( V_106 ) )
V_333 = 0 ;
}
if ( V_333 ) {
if ( V_331 == 0 )
F_196 ( V_325 , & V_10 -> V_326 ) ;
goto V_335;
}
for ( V_116 = V_331 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
F_23 ( ! F_121 ( V_106 ) ) ;
F_120 ( V_106 ) ;
if ( V_116 == 0 )
F_125 ( V_106 , V_10 -> V_20 ) ;
if ( V_334 )
F_123 ( V_106 ) ;
if ( ! F_128 ( V_106 ) ) {
if ( V_331 == 0 )
V_334 = 1 ;
F_217 ( V_106 ) ;
V_82 = F_126 ( V_17 , V_106 ,
V_196 , & V_144 ,
V_173 , & V_174 ) ;
if ( V_82 )
V_54 = V_82 ;
} else {
F_84 ( V_106 ) ;
}
}
if ( V_144 )
F_113 ( V_226 , V_144 , V_173 , V_174 ) ;
if ( V_54 || ! V_91 )
return V_54 ;
for ( V_116 = V_331 ; V_116 < V_321 ; V_116 ++ ) {
V_106 = F_182 ( V_10 , V_116 ) ;
F_218 ( V_106 ) ;
if ( ! F_128 ( V_106 ) )
V_54 = - V_336 ;
}
if ( ! V_54 )
F_196 ( V_325 , & V_10 -> V_326 ) ;
return V_54 ;
V_335:
V_116 = V_331 ;
while ( V_332 > 0 ) {
V_106 = F_182 ( V_10 , V_116 ) ;
V_116 ++ ;
F_84 ( V_106 ) ;
V_332 -- ;
}
return V_54 ;
}
void F_219 ( struct V_7 * V_10 , void * V_337 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_338 ;
char * V_339 = ( char * ) V_337 ;
T_6 V_340 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_340 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_182 ( V_10 , V_116 ) ;
V_198 = F_95 ( V_20 , ( V_126 - V_40 ) ) ;
V_338 = F_133 ( V_106 , V_341 ) ;
memcpy ( V_339 , V_338 + V_40 , V_198 ) ;
F_135 ( V_338 , V_341 ) ;
V_339 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
int F_220 ( struct V_7 * V_10 , unsigned long V_15 ,
unsigned long V_342 , char * * V_343 , char * * V_277 ,
unsigned long * V_344 ,
unsigned long * V_345 , int V_346 )
{
T_6 V_40 = V_15 & ( V_126 - 1 ) ;
char * V_338 ;
struct V_106 * V_42 ;
T_6 V_340 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_15 ) >> V_104 ;
unsigned long V_347 = ( V_340 + V_15 + V_342 - 1 ) >>
V_104 ;
if ( V_116 != V_347 )
return - V_300 ;
if ( V_116 == 0 ) {
V_40 = V_340 ;
* V_344 = 0 ;
} else {
V_40 = 0 ;
* V_344 = ( ( T_3 ) V_116 << V_104 ) - V_340 ;
}
if ( V_15 + V_342 > V_10 -> V_20 ) {
F_7 ( V_14 L_12
L_13 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_20 , V_15 , V_342 ) ;
F_23 ( 1 ) ;
return - V_300 ;
}
V_42 = F_182 ( V_10 , V_116 ) ;
V_338 = F_133 ( V_42 , V_346 ) ;
* V_343 = V_338 ;
* V_277 = V_338 + V_40 ;
* V_345 = V_126 - V_40 ;
return 0 ;
}
int F_221 ( struct V_7 * V_10 , unsigned long V_15 ,
unsigned long V_342 ,
char * * V_343 , char * * V_277 ,
unsigned long * V_344 ,
unsigned long * V_345 , int V_346 )
{
int V_82 ;
int V_348 = 0 ;
if ( V_10 -> V_349 ) {
F_222 ( V_10 , V_10 -> V_349 , V_346 ) ;
V_10 -> V_349 = NULL ;
V_348 = 1 ;
}
V_82 = F_220 ( V_10 , V_15 , V_342 , V_343 , V_277 ,
V_344 , V_345 , V_346 ) ;
if ( ! V_82 && V_348 ) {
V_10 -> V_349 = * V_343 ;
V_10 -> V_338 = * V_277 ;
V_10 -> V_344 = * V_344 ;
V_10 -> V_345 = * V_345 ;
}
return V_82 ;
}
void F_222 ( struct V_7 * V_10 , char * V_343 , int V_346 )
{
F_135 ( V_343 , V_346 ) ;
}
int F_223 ( struct V_7 * V_10 , const void * V_350 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_338 ;
char * V_351 = ( char * ) V_350 ;
T_6 V_340 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_15 ) >> V_104 ;
int V_54 = 0 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_340 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_182 ( V_10 , V_116 ) ;
V_198 = F_95 ( V_20 , ( V_126 - V_40 ) ) ;
V_338 = F_133 ( V_106 , V_217 ) ;
V_54 = memcmp ( V_351 , V_338 + V_40 , V_198 ) ;
F_135 ( V_338 , V_217 ) ;
if ( V_54 )
break;
V_351 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
return V_54 ;
}
void F_224 ( struct V_7 * V_10 , const void * V_352 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_338 ;
char * V_353 = ( char * ) V_352 ;
T_6 V_340 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_340 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_182 ( V_10 , V_116 ) ;
F_23 ( ! F_128 ( V_106 ) ) ;
V_198 = F_95 ( V_20 , V_126 - V_40 ) ;
V_338 = F_133 ( V_106 , V_341 ) ;
memcpy ( V_338 + V_40 , V_353 , V_198 ) ;
F_135 ( V_338 , V_341 ) ;
V_353 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
void F_225 ( struct V_7 * V_10 , char V_354 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_338 ;
T_6 V_340 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_340 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_182 ( V_10 , V_116 ) ;
F_23 ( ! F_128 ( V_106 ) ) ;
V_198 = F_95 ( V_20 , V_126 - V_40 ) ;
V_338 = F_133 ( V_106 , V_217 ) ;
memset ( V_338 + V_40 , V_354 , V_198 ) ;
F_135 ( V_338 , V_217 ) ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
void F_226 ( struct V_7 * V_339 , struct V_7 * V_353 ,
unsigned long V_355 , unsigned long V_356 ,
unsigned long V_20 )
{
T_3 V_357 = V_339 -> V_20 ;
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_338 ;
T_6 V_340 = V_339 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_340 + V_355 ) >> V_104 ;
F_23 ( V_353 -> V_20 != V_357 ) ;
V_40 = ( V_340 + V_355 ) &
( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_182 ( V_339 , V_116 ) ;
F_23 ( ! F_128 ( V_106 ) ) ;
V_198 = F_95 ( V_20 , ( unsigned long ) ( V_126 - V_40 ) ) ;
V_338 = F_133 ( V_106 , V_217 ) ;
F_219 ( V_353 , V_338 + V_40 , V_356 , V_198 ) ;
F_135 ( V_338 , V_217 ) ;
V_356 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
static void F_227 ( struct V_106 * V_358 , struct V_106 * V_359 ,
unsigned long V_360 , unsigned long V_361 ,
unsigned long V_20 )
{
char * V_362 = F_133 ( V_358 , V_217 ) ;
if ( V_358 == V_359 ) {
memmove ( V_362 + V_360 , V_362 + V_361 , V_20 ) ;
} else {
char * V_363 = F_133 ( V_359 , V_341 ) ;
char * V_42 = V_362 + V_360 + V_20 ;
char * V_364 = V_363 + V_361 + V_20 ;
while ( V_20 -- )
* -- V_42 = * -- V_364 ;
F_135 ( V_363 , V_341 ) ;
}
F_135 ( V_362 , V_217 ) ;
}
static inline bool F_228 ( unsigned long V_353 , unsigned long V_339 , unsigned long V_20 )
{
unsigned long V_365 = ( V_353 > V_339 ) ? V_353 - V_339 : V_339 - V_353 ;
return V_365 < V_20 ;
}
static void F_229 ( struct V_106 * V_358 , struct V_106 * V_359 ,
unsigned long V_360 , unsigned long V_361 ,
unsigned long V_20 )
{
char * V_362 = F_133 ( V_358 , V_217 ) ;
char * V_363 ;
if ( V_358 != V_359 ) {
V_363 = F_133 ( V_359 , V_341 ) ;
} else {
V_363 = V_362 ;
F_46 ( F_228 ( V_361 , V_360 , V_20 ) ) ;
}
memcpy ( V_362 + V_360 , V_363 + V_361 , V_20 ) ;
F_135 ( V_362 , V_217 ) ;
if ( V_358 != V_359 )
F_135 ( V_363 , V_341 ) ;
}
void F_230 ( struct V_7 * V_339 , unsigned long V_355 ,
unsigned long V_356 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_366 ;
T_6 V_367 ;
T_6 V_340 = V_339 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_368 ;
unsigned long V_369 ;
if ( V_356 + V_20 > V_339 -> V_20 ) {
F_7 ( V_14 L_14
L_15 , V_356 , V_20 , V_339 -> V_20 ) ;
F_46 ( 1 ) ;
}
if ( V_355 + V_20 > V_339 -> V_20 ) {
F_7 ( V_14 L_16
L_15 , V_355 , V_20 , V_339 -> V_20 ) ;
F_46 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_366 = ( V_340 + V_355 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_367 = ( V_340 + V_356 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_368 = ( V_340 + V_355 ) >> V_104 ;
V_369 = ( V_340 + V_356 ) >> V_104 ;
V_198 = F_95 ( V_20 , ( unsigned long ) ( V_126 -
V_367 ) ) ;
V_198 = F_83 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_229 ( F_182 ( V_339 , V_368 ) ,
F_182 ( V_339 , V_369 ) ,
V_366 , V_367 , V_198 ) ;
V_356 += V_198 ;
V_355 += V_198 ;
V_20 -= V_198 ;
}
}
void F_231 ( struct V_7 * V_339 , unsigned long V_355 ,
unsigned long V_356 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_366 ;
T_6 V_367 ;
unsigned long V_370 = V_355 + V_20 - 1 ;
unsigned long V_371 = V_356 + V_20 - 1 ;
T_6 V_340 = V_339 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_368 ;
unsigned long V_369 ;
if ( V_356 + V_20 > V_339 -> V_20 ) {
F_7 ( V_14 L_14
L_17 , V_356 , V_20 , V_339 -> V_20 ) ;
F_46 ( 1 ) ;
}
if ( V_355 + V_20 > V_339 -> V_20 ) {
F_7 ( V_14 L_16
L_17 , V_355 , V_20 , V_339 -> V_20 ) ;
F_46 ( 1 ) ;
}
if ( ! F_228 ( V_356 , V_355 , V_20 ) ) {
F_230 ( V_339 , V_355 , V_356 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_368 = ( V_340 + V_370 ) >> V_104 ;
V_369 = ( V_340 + V_371 ) >> V_104 ;
V_366 = ( V_340 + V_370 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_367 = ( V_340 + V_371 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_198 = F_83 (unsigned long, len, src_off_in_page + 1 ) ;
V_198 = F_95 ( V_198 , V_366 + 1 ) ;
F_227 ( F_182 ( V_339 , V_368 ) ,
F_182 ( V_339 , V_369 ) ,
V_366 - V_198 + 1 ,
V_367 - V_198 + 1 , V_198 ) ;
V_370 -= V_198 ;
V_371 -= V_198 ;
V_20 -= V_198 ;
}
}
static inline void F_232 ( struct V_372 * V_373 )
{
struct V_7 * V_10 =
F_233 ( V_373 , struct V_7 , V_372 ) ;
F_191 ( V_10 ) ;
}
int F_234 ( struct V_21 * V_17 , struct V_106 * V_106 )
{
T_3 V_15 = F_158 ( V_106 ) ;
struct V_7 * V_10 ;
int V_54 = 1 ;
F_44 ( & V_17 -> V_30 ) ;
V_10 = F_184 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( ! V_10 ) {
F_48 ( & V_17 -> V_30 ) ;
return V_54 ;
}
if ( F_110 ( V_329 , & V_10 -> V_326 ) ) {
V_54 = 0 ;
goto V_89;
}
if ( F_235 ( & V_10 -> V_18 , 1 , 0 ) != 1 ) {
V_54 = 0 ;
goto V_89;
}
F_236 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
V_89:
F_48 ( & V_17 -> V_30 ) ;
if ( F_8 ( & V_10 -> V_18 ) == 0 )
F_237 ( & V_10 -> V_372 , F_232 ) ;
return V_54 ;
}
