static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 -> V_5 -> V_6 ) ;
}
int T_1 F_3 ( void )
{
V_7 = F_4 ( L_1 ,
sizeof( struct V_8 ) , 0 ,
V_9 | V_10 , NULL ) ;
if ( ! V_7 )
return - V_11 ;
V_12 = F_4 ( L_2 ,
sizeof( struct V_13 ) , 0 ,
V_9 | V_10 , NULL ) ;
if ( ! V_12 )
goto V_14;
return 0 ;
V_14:
F_5 ( V_7 ) ;
return - V_11 ;
}
void F_6 ( void )
{
struct V_8 * V_15 ;
struct V_13 * V_16 ;
while ( ! F_7 ( & V_17 ) ) {
V_15 = F_8 ( V_17 . V_18 , struct V_8 , V_19 ) ;
F_9 ( V_20 L_3
L_4 ,
( unsigned long long ) V_15 -> V_21 ,
( unsigned long long ) V_15 -> V_22 ,
V_15 -> V_15 , V_15 -> V_3 , F_10 ( & V_15 -> V_23 ) ) ;
F_11 ( & V_15 -> V_19 ) ;
F_12 ( V_7 , V_15 ) ;
}
while ( ! F_7 ( & V_24 ) ) {
V_16 = F_8 ( V_24 . V_18 , struct V_13 , V_19 ) ;
F_9 ( V_20 L_5
L_6 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , F_10 ( & V_16 -> V_23 ) ) ;
F_11 ( & V_16 -> V_19 ) ;
F_12 ( V_12 , V_16 ) ;
}
F_13 () ;
if ( V_7 )
F_5 ( V_7 ) ;
if ( V_12 )
F_5 ( V_12 ) ;
}
void F_14 ( struct V_2 * V_3 ,
struct V_26 * V_4 )
{
V_3 -> V_15 = V_27 ;
F_15 ( & V_3 -> V_28 , V_29 ) ;
V_3 -> V_30 = NULL ;
V_3 -> V_31 = 0 ;
F_16 ( & V_3 -> V_32 ) ;
F_16 ( & V_3 -> V_33 ) ;
V_3 -> V_4 = V_4 ;
}
static struct V_8 * F_17 ( T_2 V_34 )
{
struct V_8 * V_15 ;
#if V_35
unsigned long V_36 ;
#endif
V_15 = F_18 ( V_7 , V_34 ) ;
if ( ! V_15 )
return V_15 ;
V_15 -> V_15 = 0 ;
V_15 -> V_37 = 0 ;
V_15 -> V_3 = NULL ;
#if V_35
F_19 ( & V_38 , V_36 ) ;
F_20 ( & V_15 -> V_19 , & V_17 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
F_22 ( & V_15 -> V_23 , 1 ) ;
F_23 ( & V_15 -> V_39 ) ;
F_24 ( V_15 , V_34 , V_40 ) ;
return V_15 ;
}
void F_25 ( struct V_8 * V_15 )
{
if ( ! V_15 )
return;
if ( F_26 ( & V_15 -> V_23 ) ) {
#if V_35
unsigned long V_36 ;
#endif
F_27 ( V_15 -> V_3 ) ;
#if V_35
F_19 ( & V_38 , V_36 ) ;
F_11 ( & V_15 -> V_19 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
F_28 ( V_15 , V_40 ) ;
F_12 ( V_7 , V_15 ) ;
}
}
static struct V_41 * F_29 ( struct V_42 * V_43 , T_3 V_44 ,
struct V_41 * V_45 )
{
struct V_41 * * V_46 = & V_43 -> V_41 ;
struct V_41 * V_47 = NULL ;
struct V_48 * V_49 ;
while ( * V_46 ) {
V_47 = * V_46 ;
V_49 = F_30 ( V_47 , struct V_48 , V_41 ) ;
if ( V_44 < V_49 -> V_21 )
V_46 = & ( * V_46 ) -> V_50 ;
else if ( V_44 > V_49 -> V_22 )
V_46 = & ( * V_46 ) -> V_51 ;
else
return V_47 ;
}
F_31 ( V_45 , V_47 , V_46 ) ;
F_32 ( V_45 , V_43 ) ;
return NULL ;
}
static struct V_41 * F_33 ( struct V_2 * V_3 , T_3 V_44 ,
struct V_41 * * V_52 ,
struct V_41 * * V_53 )
{
struct V_42 * V_43 = & V_3 -> V_15 ;
struct V_41 * V_54 = V_43 -> V_41 ;
struct V_41 * V_55 = NULL ;
struct V_41 * V_56 = NULL ;
struct V_48 * V_49 ;
struct V_48 * V_57 = NULL ;
while ( V_54 ) {
V_49 = F_30 ( V_54 , struct V_48 , V_41 ) ;
V_55 = V_54 ;
V_57 = V_49 ;
if ( V_44 < V_49 -> V_21 )
V_54 = V_54 -> V_50 ;
else if ( V_44 > V_49 -> V_22 )
V_54 = V_54 -> V_51 ;
else
return V_54 ;
}
if ( V_52 ) {
V_56 = V_55 ;
while ( V_55 && V_44 > V_57 -> V_22 ) {
V_55 = F_34 ( V_55 ) ;
V_57 = F_30 ( V_55 , struct V_48 , V_41 ) ;
}
* V_52 = V_55 ;
V_55 = V_56 ;
}
if ( V_53 ) {
V_57 = F_30 ( V_55 , struct V_48 , V_41 ) ;
while ( V_55 && V_44 < V_57 -> V_21 ) {
V_55 = F_35 ( V_55 ) ;
V_57 = F_30 ( V_55 , struct V_48 , V_41 ) ;
}
* V_53 = V_55 ;
}
return NULL ;
}
static inline struct V_41 * F_36 ( struct V_2 * V_3 ,
T_3 V_44 )
{
struct V_41 * V_55 = NULL ;
struct V_41 * V_58 ;
V_58 = F_33 ( V_3 , V_44 , & V_55 , NULL ) ;
if ( ! V_58 )
return V_55 ;
return V_58 ;
}
static void F_37 ( struct V_2 * V_3 , struct V_8 * V_59 ,
struct V_8 * V_60 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_61 )
V_3 -> V_30 -> V_61 ( V_3 -> V_4 -> V_5 , V_59 ,
V_60 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_8 * V_15 )
{
struct V_8 * V_60 ;
struct V_41 * V_62 ;
if ( V_15 -> V_15 & ( V_63 | V_64 ) )
return;
V_62 = F_35 ( & V_15 -> V_41 ) ;
if ( V_62 ) {
V_60 = F_30 ( V_62 , struct V_8 , V_41 ) ;
if ( V_60 -> V_22 == V_15 -> V_21 - 1 &&
V_60 -> V_15 == V_15 -> V_15 ) {
F_37 ( V_3 , V_15 , V_60 ) ;
V_15 -> V_21 = V_60 -> V_21 ;
V_60 -> V_3 = NULL ;
F_39 ( & V_60 -> V_41 , & V_3 -> V_15 ) ;
F_25 ( V_60 ) ;
}
}
V_62 = F_34 ( & V_15 -> V_41 ) ;
if ( V_62 ) {
V_60 = F_30 ( V_62 , struct V_8 , V_41 ) ;
if ( V_60 -> V_21 == V_15 -> V_22 + 1 &&
V_60 -> V_15 == V_15 -> V_15 ) {
F_37 ( V_3 , V_15 , V_60 ) ;
V_15 -> V_22 = V_60 -> V_22 ;
V_60 -> V_3 = NULL ;
F_39 ( & V_60 -> V_41 , & V_3 -> V_15 ) ;
F_25 ( V_60 ) ;
}
}
}
static void F_40 ( struct V_2 * V_3 ,
struct V_8 * V_15 , int * V_65 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_66 )
V_3 -> V_30 -> V_66 ( V_3 -> V_4 -> V_5 , V_15 , V_65 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_8 * V_15 , int * V_65 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_67 )
V_3 -> V_30 -> V_67 ( V_3 -> V_4 -> V_5 , V_15 , V_65 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_8 * V_15 , T_3 V_21 , T_3 V_22 ,
int * V_65 )
{
struct V_41 * V_45 ;
if ( V_22 < V_21 ) {
F_9 ( V_20 L_7 ,
( unsigned long long ) V_22 ,
( unsigned long long ) V_21 ) ;
F_27 ( 1 ) ;
}
V_15 -> V_21 = V_21 ;
V_15 -> V_22 = V_22 ;
F_43 ( V_3 , V_15 , V_65 ) ;
V_45 = F_29 ( & V_3 -> V_15 , V_22 , & V_15 -> V_41 ) ;
if ( V_45 ) {
struct V_8 * V_68 ;
V_68 = F_30 ( V_45 , struct V_8 , V_41 ) ;
F_9 ( V_20 L_8
L_9 , ( unsigned long long ) V_68 -> V_21 ,
( unsigned long long ) V_68 -> V_22 ,
( unsigned long long ) V_21 , ( unsigned long long ) V_22 ) ;
return - V_69 ;
}
V_15 -> V_3 = V_3 ;
F_38 ( V_3 , V_15 ) ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 , struct V_8 * V_70 ,
T_3 V_71 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_72 )
V_3 -> V_30 -> V_72 ( V_3 -> V_4 -> V_5 , V_70 , V_71 ) ;
}
static int F_45 ( struct V_2 * V_3 , struct V_8 * V_70 ,
struct V_8 * V_73 , T_3 V_71 )
{
struct V_41 * V_45 ;
F_44 ( V_3 , V_70 , V_71 ) ;
V_73 -> V_21 = V_70 -> V_21 ;
V_73 -> V_22 = V_71 - 1 ;
V_73 -> V_15 = V_70 -> V_15 ;
V_70 -> V_21 = V_71 ;
V_45 = F_29 ( & V_3 -> V_15 , V_73 -> V_22 , & V_73 -> V_41 ) ;
if ( V_45 ) {
F_25 ( V_73 ) ;
return - V_69 ;
}
V_73 -> V_3 = V_3 ;
return 0 ;
}
static struct V_8 * F_46 ( struct V_8 * V_15 )
{
struct V_41 * V_18 = F_34 ( & V_15 -> V_41 ) ;
if ( V_18 )
return F_30 ( V_18 , struct V_8 , V_41 ) ;
else
return NULL ;
}
static struct V_8 * F_47 ( struct V_2 * V_3 ,
struct V_8 * V_15 ,
int * V_65 , int V_74 )
{
struct V_8 * V_18 ;
int V_75 = * V_65 & ~ V_76 ;
if ( ( V_75 & V_77 ) && ( V_15 -> V_15 & V_77 ) ) {
T_3 V_78 = V_15 -> V_22 - V_15 -> V_21 + 1 ;
F_27 ( V_78 > V_3 -> V_31 ) ;
V_3 -> V_31 -= V_78 ;
}
F_41 ( V_3 , V_15 , V_65 ) ;
V_15 -> V_15 &= ~ V_75 ;
if ( V_74 )
F_48 ( & V_15 -> V_39 ) ;
if ( V_15 -> V_15 == 0 ) {
V_18 = F_46 ( V_15 ) ;
if ( V_15 -> V_3 ) {
F_39 ( & V_15 -> V_41 , & V_3 -> V_15 ) ;
V_15 -> V_3 = NULL ;
F_25 ( V_15 ) ;
} else {
F_27 ( 1 ) ;
}
} else {
F_38 ( V_3 , V_15 ) ;
V_18 = F_46 ( V_15 ) ;
}
return V_18 ;
}
static struct V_8 *
F_49 ( struct V_8 * V_73 )
{
if ( ! V_73 )
V_73 = F_17 ( V_29 ) ;
return V_73 ;
}
void F_50 ( struct V_2 * V_3 , int V_79 )
{
F_51 ( F_1 ( V_3 ) , V_79 , L_10
L_11
L_12 ) ;
}
int F_52 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_74 , int V_80 ,
struct V_8 * * V_81 ,
T_2 V_34 )
{
struct V_8 * V_15 ;
struct V_8 * V_82 ;
struct V_8 * V_73 = NULL ;
struct V_41 * V_45 ;
T_3 V_83 ;
int V_79 ;
int V_84 = 0 ;
if ( V_80 )
V_65 |= ~ V_76 ;
V_65 |= V_85 ;
if ( V_65 & ( V_63 | V_64 ) )
V_84 = 1 ;
V_86:
if ( ! V_73 && ( V_34 & V_87 ) ) {
V_73 = F_17 ( V_34 ) ;
if ( ! V_73 )
return - V_11 ;
}
F_53 ( & V_3 -> V_32 ) ;
if ( V_81 ) {
V_82 = * V_81 ;
if ( V_84 ) {
* V_81 = NULL ;
V_81 = NULL ;
}
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 ) {
if ( V_84 )
F_54 ( & V_82 -> V_23 ) ;
V_15 = V_82 ;
goto V_88;
}
if ( V_84 )
F_25 ( V_82 ) ;
}
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 )
goto V_89;
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
V_88:
if ( V_15 -> V_21 > V_22 )
goto V_89;
F_27 ( V_15 -> V_22 < V_21 ) ;
V_83 = V_15 -> V_22 ;
if ( ! ( V_15 -> V_15 & V_65 ) ) {
V_15 = F_46 ( V_15 ) ;
goto V_18;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_45 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
V_15 = F_47 ( V_3 , V_15 , & V_65 , V_74 ) ;
goto V_18;
}
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_45 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
if ( V_74 )
F_48 ( & V_15 -> V_39 ) ;
F_47 ( V_3 , V_73 , & V_65 , V_74 ) ;
V_73 = NULL ;
goto V_89;
}
V_15 = F_47 ( V_3 , V_15 , & V_65 , V_74 ) ;
V_18:
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 <= V_22 && V_15 && ! F_56 () )
goto V_88;
goto V_90;
V_89:
F_57 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return 0 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_57 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_58 () ;
goto V_86;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_8 * V_15 )
__releases( V_3 -> V_32 )
__acquires( V_3 -> V_32 )
{
F_60 ( V_91 ) ;
F_61 ( & V_15 -> V_39 , & V_91 , V_92 ) ;
F_57 ( & V_3 -> V_32 ) ;
F_62 () ;
F_53 ( & V_3 -> V_32 ) ;
F_63 ( & V_15 -> V_39 , & V_91 ) ;
}
void F_64 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 )
{
struct V_8 * V_15 ;
struct V_41 * V_45 ;
F_53 ( & V_3 -> V_32 ) ;
V_86:
while ( 1 ) {
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 )
break;
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_22 )
goto V_89;
if ( V_15 -> V_15 & V_65 ) {
V_21 = V_15 -> V_21 ;
F_65 ( & V_15 -> V_23 ) ;
F_59 ( V_3 , V_15 ) ;
F_25 ( V_15 ) ;
goto V_86;
}
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
F_66 ( & V_3 -> V_32 ) ;
}
V_89:
F_57 ( & V_3 -> V_32 ) ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_8 * V_15 ,
int * V_65 )
{
int V_93 = * V_65 & ~ V_76 ;
F_40 ( V_3 , V_15 , V_65 ) ;
if ( ( V_93 & V_77 ) && ! ( V_15 -> V_15 & V_77 ) ) {
T_3 V_78 = V_15 -> V_22 - V_15 -> V_21 + 1 ;
V_3 -> V_31 += V_78 ;
}
V_15 -> V_15 |= V_93 ;
}
static void F_67 ( struct V_8 * V_15 ,
struct V_8 * * V_94 )
{
if ( V_94 && ! ( * V_94 ) ) {
if ( V_15 -> V_15 & ( V_63 | V_64 ) ) {
* V_94 = V_15 ;
F_65 ( & V_15 -> V_23 ) ;
}
}
}
static void F_68 ( struct V_8 * * V_94 )
{
if ( V_94 && ( * V_94 ) ) {
struct V_8 * V_15 = * V_94 ;
* V_94 = NULL ;
F_25 ( V_15 ) ;
}
}
static int T_4
F_69 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_95 , T_3 * V_96 ,
struct V_8 * * V_81 , T_2 V_34 )
{
struct V_8 * V_15 ;
struct V_8 * V_73 = NULL ;
struct V_41 * V_45 ;
int V_79 = 0 ;
T_3 V_97 ;
T_3 V_83 ;
V_65 |= V_85 ;
V_86:
if ( ! V_73 && ( V_34 & V_87 ) ) {
V_73 = F_17 ( V_34 ) ;
F_55 ( ! V_73 ) ;
}
F_53 ( & V_3 -> V_32 ) ;
if ( V_81 && * V_81 ) {
V_15 = * V_81 ;
if ( V_15 -> V_21 <= V_21 && V_15 -> V_22 > V_21 &&
V_15 -> V_3 ) {
V_45 = & V_15 -> V_41 ;
goto V_88;
}
}
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_42 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
V_73 = NULL ;
goto V_89;
}
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
V_88:
V_97 = V_15 -> V_21 ;
V_83 = V_15 -> V_22 ;
if ( V_15 -> V_21 == V_21 && V_15 -> V_22 <= V_22 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_15 -> V_21 ;
V_79 = - V_69 ;
goto V_89;
}
F_43 ( V_3 , V_15 , & V_65 ) ;
F_67 ( V_15 , V_81 ) ;
F_38 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_15 = F_46 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_56 () )
goto V_88;
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_21 ;
V_79 = - V_69 ;
goto V_89;
}
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_45 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_43 ( V_3 , V_15 , & V_65 ) ;
F_67 ( V_15 , V_81 ) ;
F_38 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_15 = F_46 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_56 () )
goto V_88;
}
goto V_90;
}
if ( V_15 -> V_21 > V_21 ) {
T_3 V_98 ;
if ( V_22 < V_97 )
V_98 = V_22 ;
else
V_98 = V_97 - 1 ;
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_42 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
F_67 ( V_73 , V_81 ) ;
V_73 = NULL ;
V_21 = V_98 + 1 ;
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_21 ;
V_79 = - V_69 ;
goto V_89;
}
V_73 = F_49 ( V_73 ) ;
F_55 ( ! V_73 ) ;
V_79 = F_45 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
F_43 ( V_3 , V_73 , & V_65 ) ;
F_67 ( V_73 , V_81 ) ;
F_38 ( V_3 , V_73 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_57 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_57 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_58 () ;
goto V_86;
}
int F_70 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 ,
T_3 * V_96 , struct V_8 * * V_81 ,
T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_65 , 0 , V_96 ,
V_81 , V_34 ) ;
}
int F_71 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_99 ,
struct V_8 * * V_81 , T_2 V_34 )
{
struct V_8 * V_15 ;
struct V_8 * V_73 = NULL ;
struct V_41 * V_45 ;
int V_79 = 0 ;
T_3 V_97 ;
T_3 V_83 ;
V_86:
if ( ! V_73 && ( V_34 & V_87 ) ) {
V_73 = F_17 ( V_34 ) ;
if ( ! V_73 )
return - V_11 ;
}
F_53 ( & V_3 -> V_32 ) ;
if ( V_81 && * V_81 ) {
V_15 = * V_81 ;
if ( V_15 -> V_21 <= V_21 && V_15 -> V_22 > V_21 &&
V_15 -> V_3 ) {
V_45 = & V_15 -> V_41 ;
goto V_88;
}
}
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_73 = F_49 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_42 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
V_73 = NULL ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
goto V_89;
}
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
V_88:
V_97 = V_15 -> V_21 ;
V_83 = V_15 -> V_22 ;
if ( V_15 -> V_21 == V_21 && V_15 -> V_22 <= V_22 ) {
F_43 ( V_3 , V_15 , & V_65 ) ;
F_67 ( V_15 , V_81 ) ;
V_15 = F_47 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_56 () )
goto V_88;
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_49 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_45 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_43 ( V_3 , V_15 , & V_65 ) ;
F_67 ( V_15 , V_81 ) ;
V_15 = F_47 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_56 () )
goto V_88;
}
goto V_90;
}
if ( V_15 -> V_21 > V_21 ) {
T_3 V_98 ;
if ( V_22 < V_97 )
V_98 = V_22 ;
else
V_98 = V_97 - 1 ;
V_73 = F_49 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_42 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
F_67 ( V_73 , V_81 ) ;
V_73 = NULL ;
V_21 = V_98 + 1 ;
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_49 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_45 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_50 ( V_3 , V_79 ) ;
F_43 ( V_3 , V_73 , & V_65 ) ;
F_67 ( V_73 , V_81 ) ;
F_47 ( V_3 , V_73 , & V_99 , 0 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_57 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_57 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_58 () ;
goto V_86;
}
int F_72 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 , V_77 , NULL ,
NULL , V_34 ) ;
}
int F_73 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 , V_65 , NULL ,
NULL , V_34 ) ;
}
int F_74 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_52 ( V_3 , V_21 , V_22 , V_65 , 0 , 0 , NULL , V_34 ) ;
}
int F_75 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 ,
V_100 | V_101 ,
NULL , V_81 , V_34 ) ;
}
int F_76 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 ,
V_100 | V_101 | V_102 ,
NULL , V_81 , V_34 ) ;
}
int F_77 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_52 ( V_3 , V_21 , V_22 ,
V_77 | V_100 |
V_103 , 0 , 0 , NULL , V_34 ) ;
}
int F_78 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 , V_104 , NULL ,
NULL , V_34 ) ;
}
int F_79 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 , V_101 , 0 ,
V_81 , V_34 ) ;
}
int F_80 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_52 ( V_3 , V_21 , V_22 , V_101 , 0 , 0 ,
V_81 , V_34 ) ;
}
int F_81 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , struct V_8 * * V_81 )
{
int V_79 ;
T_3 V_96 ;
while ( 1 ) {
V_79 = F_69 ( V_3 , V_21 , V_22 , V_105 | V_65 ,
V_105 , & V_96 ,
V_81 , V_106 ) ;
if ( V_79 == - V_69 ) {
F_64 ( V_3 , V_96 , V_22 , V_105 ) ;
V_21 = V_96 ;
} else
break;
F_27 ( V_21 > V_22 ) ;
}
return V_79 ;
}
int F_82 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_81 ( V_3 , V_21 , V_22 , 0 , NULL ) ;
}
int F_83 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
int V_79 ;
T_3 V_96 ;
V_79 = F_69 ( V_3 , V_21 , V_22 , V_105 , V_105 ,
& V_96 , NULL , V_106 ) ;
if ( V_79 == - V_69 ) {
if ( V_96 > V_21 )
F_52 ( V_3 , V_21 , V_96 - 1 ,
V_105 , 1 , 0 , NULL , V_106 ) ;
return 0 ;
}
return 1 ;
}
int F_84 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_82 , T_2 V_34 )
{
return F_52 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , V_82 ,
V_34 ) ;
}
int F_85 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_52 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , NULL ,
V_106 ) ;
}
static int F_86 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
struct V_110 * V_110 ;
while ( V_107 <= V_109 ) {
V_110 = F_87 ( V_3 -> V_4 , V_107 ) ;
F_55 ( ! V_110 ) ;
F_88 ( V_110 ) ;
F_89 ( V_110 ) ;
V_107 ++ ;
}
return 0 ;
}
struct V_8 * F_90 ( struct V_2 * V_3 ,
T_3 V_21 , int V_65 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_22 >= V_21 && ( V_15 -> V_15 & V_65 ) )
return V_15 ;
V_45 = F_34 ( V_45 ) ;
if ( ! V_45 )
break;
}
V_89:
return NULL ;
}
int F_91 ( struct V_2 * V_3 , T_3 V_21 ,
T_3 * V_111 , T_3 * V_112 , int V_65 ,
struct V_8 * * V_81 )
{
struct V_8 * V_15 ;
struct V_41 * V_54 ;
int V_58 = 1 ;
F_53 ( & V_3 -> V_32 ) ;
if ( V_81 && * V_81 ) {
V_15 = * V_81 ;
if ( V_15 -> V_22 == V_21 - 1 && V_15 -> V_3 ) {
V_54 = F_34 ( & V_15 -> V_41 ) ;
while ( V_54 ) {
V_15 = F_30 ( V_54 , struct V_8 ,
V_41 ) ;
if ( V_15 -> V_15 & V_65 )
goto V_113;
V_54 = F_34 ( V_54 ) ;
}
F_25 ( * V_81 ) ;
* V_81 = NULL ;
goto V_89;
}
F_25 ( * V_81 ) ;
* V_81 = NULL ;
}
V_15 = F_90 ( V_3 , V_21 , V_65 ) ;
V_113:
if ( V_15 ) {
F_67 ( V_15 , V_81 ) ;
* V_111 = V_15 -> V_21 ;
* V_112 = V_15 -> V_22 ;
V_58 = 0 ;
}
V_89:
F_57 ( & V_3 -> V_32 ) ;
return V_58 ;
}
static T_5 T_3 F_92 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 * V_22 , T_3 V_114 ,
struct V_8 * * V_81 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_115 = * V_21 ;
T_3 V_68 = 0 ;
T_3 V_116 = 0 ;
F_53 ( & V_3 -> V_32 ) ;
V_45 = F_36 ( V_3 , V_115 ) ;
if ( ! V_45 ) {
if ( ! V_68 )
* V_22 = ( T_3 ) - 1 ;
goto V_89;
}
while ( 1 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_68 && ( V_15 -> V_21 != V_115 ||
( V_15 -> V_15 & V_64 ) ) ) {
goto V_89;
}
if ( ! ( V_15 -> V_15 & V_100 ) ) {
if ( ! V_68 )
* V_22 = V_15 -> V_22 ;
goto V_89;
}
if ( ! V_68 ) {
* V_21 = V_15 -> V_21 ;
* V_81 = V_15 ;
F_65 ( & V_15 -> V_23 ) ;
}
V_68 ++ ;
* V_22 = V_15 -> V_22 ;
V_115 = V_15 -> V_22 + 1 ;
V_45 = F_34 ( V_45 ) ;
if ( ! V_45 )
break;
V_116 += V_15 -> V_22 - V_15 -> V_21 + 1 ;
if ( V_116 >= V_114 )
break;
}
V_89:
F_57 ( & V_3 -> V_32 ) ;
return V_68 ;
}
static T_5 void F_93 ( struct V_117 * V_117 ,
struct V_110 * V_118 ,
T_3 V_21 , T_3 V_22 )
{
int V_58 ;
struct V_110 * V_119 [ 16 ] ;
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
unsigned long V_120 = V_109 - V_107 + 1 ;
int V_121 ;
if ( V_107 == V_118 -> V_107 && V_109 == V_107 )
return;
while ( V_120 > 0 ) {
V_58 = F_94 ( V_117 -> V_122 , V_107 ,
F_95 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_119 ) ;
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_119 [ V_121 ] != V_118 )
F_96 ( V_119 [ V_121 ] ) ;
F_89 ( V_119 [ V_121 ] ) ;
}
V_120 -= V_58 ;
V_107 += V_58 ;
F_58 () ;
}
}
static T_5 int F_97 ( struct V_117 * V_117 ,
struct V_110 * V_118 ,
T_3 V_123 ,
T_3 V_124 )
{
unsigned long V_107 = V_123 >> V_108 ;
unsigned long V_125 = V_107 ;
unsigned long V_109 = V_124 >> V_108 ;
unsigned long V_126 = 0 ;
struct V_110 * V_119 [ 16 ] ;
unsigned long V_127 ;
int V_58 ;
int V_121 ;
if ( V_107 == V_118 -> V_107 && V_107 == V_109 )
return 0 ;
V_127 = V_109 - V_107 + 1 ;
while ( V_127 > 0 ) {
V_58 = F_94 ( V_117 -> V_122 , V_107 ,
F_95 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_119 ) ;
if ( V_58 == 0 ) {
V_58 = - V_128 ;
goto V_129;
}
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_119 [ V_121 ] != V_118 ) {
F_98 ( V_119 [ V_121 ] ) ;
if ( ! F_99 ( V_119 [ V_121 ] ) ||
V_119 [ V_121 ] -> V_4 != V_117 -> V_122 ) {
V_58 = - V_128 ;
F_96 ( V_119 [ V_121 ] ) ;
F_89 ( V_119 [ V_121 ] ) ;
goto V_129;
}
}
F_89 ( V_119 [ V_121 ] ) ;
V_126 ++ ;
}
V_127 -= V_58 ;
V_107 += V_58 ;
F_58 () ;
}
V_58 = 0 ;
V_129:
if ( V_58 && V_126 ) {
F_93 ( V_117 , V_118 ,
V_123 ,
( ( T_3 ) ( V_125 + V_126 - 1 ) ) <<
V_108 ) ;
}
return V_58 ;
}
static T_5 T_3 F_100 ( struct V_117 * V_117 ,
struct V_2 * V_3 ,
struct V_110 * V_118 ,
T_3 * V_21 , T_3 * V_22 ,
T_3 V_114 )
{
T_3 V_123 ;
T_3 V_124 ;
T_3 V_68 ;
struct V_8 * V_81 = NULL ;
int V_58 ;
int V_130 = 0 ;
V_86:
V_123 = * V_21 ;
V_124 = 0 ;
V_68 = F_92 ( V_3 , & V_123 , & V_124 ,
V_114 , & V_81 ) ;
if ( ! V_68 || V_124 <= * V_21 ) {
* V_21 = V_123 ;
* V_22 = V_124 ;
F_25 ( V_81 ) ;
return V_68 ;
}
if ( V_123 < * V_21 )
V_123 = * V_21 ;
if ( V_124 + 1 - V_123 > V_114 && V_130 )
V_124 = V_123 + V_131 - 1 ;
V_58 = F_97 ( V_117 , V_118 ,
V_123 , V_124 ) ;
if ( V_58 == - V_128 ) {
F_25 ( V_81 ) ;
if ( ! V_130 ) {
unsigned long V_44 = ( * V_21 ) & ( V_131 - 1 ) ;
V_114 = V_131 - V_44 ;
V_130 = 1 ;
goto V_86;
} else {
V_68 = 0 ;
goto V_132;
}
}
F_55 ( V_58 ) ;
F_81 ( V_3 , V_123 , V_124 , 0 , & V_81 ) ;
V_58 = F_101 ( V_3 , V_123 , V_124 ,
V_100 , 1 , V_81 ) ;
if ( ! V_58 ) {
F_84 ( V_3 , V_123 , V_124 ,
& V_81 , V_106 ) ;
F_93 ( V_117 , V_118 ,
V_123 , V_124 ) ;
F_58 () ;
goto V_86;
}
F_25 ( V_81 ) ;
* V_21 = V_123 ;
* V_22 = V_124 ;
V_132:
return V_68 ;
}
int F_102 ( struct V_117 * V_117 ,
struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 , struct V_110 * V_118 ,
unsigned long V_133 )
{
int V_58 ;
struct V_110 * V_119 [ 16 ] ;
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
unsigned long V_120 = V_109 - V_107 + 1 ;
int V_121 ;
int V_99 = 0 ;
if ( V_133 & V_134 )
V_99 |= V_105 ;
if ( V_133 & V_135 )
V_99 |= V_77 ;
if ( V_133 & V_136 )
V_99 |= V_100 ;
F_52 ( V_3 , V_21 , V_22 , V_99 , 1 , 0 , NULL , V_106 ) ;
if ( ! ( V_133 & ( V_137 | V_135 |
V_138 | V_139 |
V_140 ) ) )
return 0 ;
while ( V_120 > 0 ) {
V_58 = F_94 ( V_117 -> V_122 , V_107 ,
F_95 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_119 ) ;
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_133 & V_140 )
F_103 ( V_119 [ V_121 ] ) ;
if ( V_119 [ V_121 ] == V_118 ) {
F_89 ( V_119 [ V_121 ] ) ;
continue;
}
if ( V_133 & V_135 )
F_104 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_138 )
F_88 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_139 )
F_105 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_137 )
F_96 ( V_119 [ V_121 ] ) ;
F_89 ( V_119 [ V_121 ] ) ;
}
V_120 -= V_58 ;
V_107 += V_58 ;
F_58 () ;
}
return 0 ;
}
T_3 F_106 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 V_141 , T_3 V_114 ,
unsigned long V_65 , int V_142 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_115 = * V_21 ;
T_3 V_116 = 0 ;
T_3 V_143 = 0 ;
int V_68 = 0 ;
if ( V_141 <= V_115 ) {
F_27 ( 1 ) ;
return 0 ;
}
F_53 ( & V_3 -> V_32 ) ;
if ( V_115 == 0 && V_65 == V_77 ) {
V_116 = V_3 -> V_31 ;
goto V_89;
}
V_45 = F_36 ( V_3 , V_115 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_141 )
break;
if ( V_142 && V_68 && V_15 -> V_21 > V_143 + 1 )
break;
if ( V_15 -> V_22 >= V_115 && ( V_15 -> V_15 & V_65 ) == V_65 ) {
V_116 += F_107 ( V_141 , V_15 -> V_22 ) + 1 -
F_108 ( V_115 , V_15 -> V_21 ) ;
if ( V_116 >= V_114 )
break;
if ( ! V_68 ) {
* V_21 = F_108 ( V_115 , V_15 -> V_21 ) ;
V_68 = 1 ;
}
V_143 = V_15 -> V_22 ;
} else if ( V_142 && V_68 ) {
break;
}
V_45 = F_34 ( V_45 ) ;
if ( ! V_45 )
break;
}
V_89:
F_57 ( & V_3 -> V_32 ) ;
return V_116 ;
}
int F_109 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_53 ( & V_3 -> V_32 ) ;
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_58 = - V_144 ;
goto V_89;
}
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_144 ;
goto V_89;
}
V_15 -> V_37 = V_37 ;
V_89:
F_57 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_110 ( struct V_2 * V_3 , T_3 V_21 , T_3 * V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_53 ( & V_3 -> V_32 ) ;
V_45 = F_36 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_58 = - V_144 ;
goto V_89;
}
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_144 ;
goto V_89;
}
* V_37 = V_15 -> V_37 ;
V_89:
F_57 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_101 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_145 , struct V_8 * V_82 )
{
struct V_8 * V_15 = NULL ;
struct V_41 * V_45 ;
int V_146 = 0 ;
F_53 ( & V_3 -> V_32 ) ;
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 )
V_45 = & V_82 -> V_41 ;
else
V_45 = F_36 ( V_3 , V_21 ) ;
while ( V_45 && V_21 <= V_22 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_145 && V_15 -> V_21 > V_21 ) {
V_146 = 0 ;
break;
}
if ( V_15 -> V_21 > V_22 )
break;
if ( V_15 -> V_15 & V_65 ) {
V_146 = 1 ;
if ( ! V_145 )
break;
} else if ( V_145 ) {
V_146 = 0 ;
break;
}
if ( V_15 -> V_22 == ( T_3 ) - 1 )
break;
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
V_45 = F_34 ( V_45 ) ;
if ( ! V_45 ) {
if ( V_145 )
V_146 = 0 ;
break;
}
}
F_57 ( & V_3 -> V_32 ) ;
return V_146 ;
}
static void F_111 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( F_101 ( V_3 , V_21 , V_22 , V_101 , 1 , NULL ) )
F_112 ( V_110 ) ;
}
static void F_113 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ! F_101 ( V_3 , V_21 , V_22 , V_105 , 0 , NULL ) )
F_96 ( V_110 ) ;
}
static void F_114 ( struct V_2 * V_3 ,
struct V_110 * V_110 )
{
F_105 ( V_110 ) ;
}
static int F_115 ( struct V_117 * V_117 , struct V_147 * V_148 ,
int V_149 )
{
int V_58 ;
int V_79 = 0 ;
struct V_2 * V_150 = & F_116 ( V_117 ) -> V_151 ;
F_109 ( V_150 , V_148 -> V_21 , 0 ) ;
V_58 = F_74 ( V_150 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 )
V_79 = V_58 ;
if ( V_149 ) {
V_58 = F_74 ( & F_116 ( V_117 ) -> V_152 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_153 , V_106 ) ;
if ( V_58 && ! V_79 )
V_79 = V_58 ;
}
F_117 ( V_148 ) ;
return V_79 ;
}
static void F_118 ( struct V_154 * V_154 , int V_79 )
{
F_119 ( V_154 -> V_155 ) ;
}
int F_120 ( struct V_156 * V_157 , T_3 V_21 ,
T_3 V_158 , T_3 V_159 , struct V_110 * V_110 ,
int V_160 )
{
struct V_154 * V_154 ;
struct V_161 * V_162 ;
F_121 ( V_163 ) ;
T_3 V_164 = 0 ;
T_3 V_165 ;
struct V_166 * V_167 = NULL ;
int V_58 ;
F_55 ( ! V_160 ) ;
V_154 = F_122 ( V_106 , 1 ) ;
if ( ! V_154 )
return - V_168 ;
V_154 -> V_155 = & V_163 ;
V_154 -> V_169 = F_118 ;
V_154 -> V_170 = 0 ;
V_164 = V_158 ;
V_58 = F_123 ( V_157 , V_171 , V_159 ,
& V_164 , & V_167 , V_160 ) ;
if ( V_58 ) {
F_124 ( V_154 ) ;
return - V_168 ;
}
F_55 ( V_160 != V_167 -> V_160 ) ;
V_165 = V_167 -> V_172 [ V_160 - 1 ] . V_173 >> 9 ;
V_154 -> V_174 = V_165 ;
V_162 = V_167 -> V_172 [ V_160 - 1 ] . V_162 ;
F_117 ( V_167 ) ;
if ( ! V_162 || ! V_162 -> V_175 || ! V_162 -> V_176 ) {
F_124 ( V_154 ) ;
return - V_168 ;
}
V_154 -> V_177 = V_162 -> V_175 ;
F_125 ( V_154 , V_110 , V_158 , V_21 - F_126 ( V_110 ) ) ;
F_127 ( V_178 , V_154 ) ;
F_128 ( & V_163 ) ;
if ( ! F_129 ( V_179 , & V_154 -> V_180 ) ) {
F_124 ( V_154 ) ;
F_130 ( V_162 , V_181 ) ;
return - V_168 ;
}
F_131 ( V_182 L_13
L_14 , V_110 -> V_4 -> V_5 -> V_183 ,
V_21 , F_132 ( V_162 -> V_184 ) , V_165 ) ;
F_124 ( V_154 ) ;
return 0 ;
}
int F_133 ( struct V_185 * V_43 , struct V_13 * V_16 ,
int V_160 )
{
struct V_156 * V_157 = & V_43 -> V_186 -> V_187 ;
T_3 V_21 = V_16 -> V_21 ;
unsigned long V_121 , V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
int V_58 = 0 ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
struct V_110 * V_46 = F_135 ( V_16 , V_121 ) ;
V_58 = F_120 ( V_157 , V_21 , V_131 ,
V_21 , V_46 , V_160 ) ;
if ( V_58 )
break;
V_21 += V_131 ;
}
return V_58 ;
}
static int F_136 ( T_3 V_21 , struct V_110 * V_110 )
{
T_3 V_37 ;
T_3 V_189 ;
struct V_147 * V_190 ;
struct V_156 * V_157 ;
struct V_8 * V_15 ;
int V_191 ;
int V_149 = 0 ;
int V_58 ;
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
V_37 = 0 ;
V_58 = F_106 ( & F_116 ( V_117 ) -> V_151 , & V_37 ,
( T_3 ) - 1 , 1 , V_77 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_58 = F_110 ( & F_116 ( V_117 ) -> V_151 , V_21 ,
& V_189 ) ;
if ( V_58 )
return 0 ;
V_190 = (struct V_147 * ) ( unsigned long ) V_189 ;
F_55 ( ! V_190 -> V_192 ) ;
if ( V_190 -> V_193 ) {
F_137 ( L_15 ,
V_190 -> V_21 ) ;
V_149 = 1 ;
goto V_89;
}
F_53 ( & F_116 ( V_117 ) -> V_152 . V_32 ) ;
V_15 = F_90 ( & F_116 ( V_117 ) -> V_152 ,
V_190 -> V_21 ,
V_105 ) ;
F_57 ( & F_116 ( V_117 ) -> V_152 . V_32 ) ;
if ( V_15 && V_15 -> V_21 == V_190 -> V_21 ) {
V_157 = & F_116 ( V_117 ) -> V_43 -> V_186 -> V_187 ;
V_191 = F_138 ( V_157 , V_190 -> V_159 ,
V_190 -> V_25 ) ;
if ( V_191 > 1 ) {
V_58 = F_120 ( V_157 , V_21 , V_190 -> V_25 ,
V_190 -> V_159 , V_110 ,
V_190 -> V_194 ) ;
V_149 = ! V_58 ;
}
}
V_89:
if ( ! V_58 )
V_58 = F_115 ( V_117 , V_190 , V_149 ) ;
return V_58 ;
}
static int F_139 ( struct V_154 * V_195 , struct V_110 * V_110 ,
T_3 V_21 , T_3 V_22 , int V_194 ,
struct V_8 * V_15 )
{
struct V_147 * V_190 = NULL ;
T_3 V_37 ;
struct V_196 * V_197 ;
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
struct V_2 * V_150 = & F_116 ( V_117 ) -> V_151 ;
struct V_2 * V_3 = & F_116 ( V_117 ) -> V_152 ;
struct V_198 * V_199 = & F_116 ( V_117 ) -> V_200 ;
struct V_154 * V_154 ;
int V_191 ;
int V_58 ;
int V_201 ;
T_3 V_159 ;
F_55 ( V_195 -> V_202 & V_203 ) ;
V_58 = F_110 ( V_150 , V_21 , & V_37 ) ;
if ( V_58 ) {
V_190 = F_140 ( sizeof( * V_190 ) , V_106 ) ;
if ( ! V_190 )
return - V_11 ;
V_190 -> V_21 = V_21 ;
V_190 -> V_25 = V_22 - V_21 + 1 ;
V_190 -> V_192 = 0 ;
V_190 -> V_204 = 0 ;
V_190 -> V_193 = 0 ;
F_141 ( & V_199 -> V_32 ) ;
V_197 = F_142 ( V_199 , V_21 , V_190 -> V_25 ) ;
if ( ! V_197 ) {
F_143 ( & V_199 -> V_32 ) ;
F_117 ( V_190 ) ;
return - V_168 ;
}
if ( V_197 -> V_21 > V_21 || V_197 -> V_21 + V_197 -> V_25 < V_21 ) {
F_144 ( V_197 ) ;
V_197 = NULL ;
}
F_143 ( & V_199 -> V_32 ) ;
if ( ! V_197 ) {
F_117 ( V_190 ) ;
return - V_168 ;
}
V_159 = V_21 - V_197 -> V_21 ;
V_159 = V_197 -> V_205 + V_159 ;
if ( F_129 ( V_206 , & V_197 -> V_36 ) ) {
V_159 = V_197 -> V_205 ;
V_190 -> V_204 = V_207 ;
F_145 ( & V_190 -> V_204 ,
V_197 -> V_208 ) ;
}
F_137 ( L_16
L_17 , V_159 , V_21 , V_190 -> V_25 ) ;
V_190 -> V_159 = V_159 ;
F_144 ( V_197 ) ;
V_58 = F_73 ( V_150 , V_21 , V_22 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 >= 0 )
V_58 = F_109 ( V_150 , V_21 ,
( T_3 ) ( unsigned long ) V_190 ) ;
if ( V_58 >= 0 )
V_58 = F_73 ( V_3 , V_21 , V_22 , V_153 ,
V_106 ) ;
if ( V_58 < 0 ) {
F_117 ( V_190 ) ;
return V_58 ;
}
} else {
V_190 = (struct V_147 * ) ( unsigned long ) V_37 ;
F_137 ( L_18
L_19 ,
V_190 -> V_159 , V_190 -> V_21 , V_190 -> V_25 ,
V_190 -> V_193 ) ;
}
V_191 = F_138 (
& F_116 ( V_117 ) -> V_43 -> V_186 -> V_187 ,
V_190 -> V_159 , V_190 -> V_25 ) ;
if ( V_191 == 1 ) {
F_137 ( L_20
L_21
L_22 , V_15 , V_191 ,
V_190 -> V_192 , V_194 ) ;
F_115 ( V_117 , V_190 , 0 ) ;
return - V_168 ;
}
if ( ! V_15 ) {
F_53 ( & V_3 -> V_32 ) ;
V_15 = F_90 ( V_3 , V_190 -> V_21 ,
V_105 ) ;
if ( V_15 && V_15 -> V_21 != V_190 -> V_21 )
V_15 = NULL ;
F_57 ( & V_3 -> V_32 ) ;
}
if ( V_195 -> V_209 > 1 ) {
F_55 ( V_190 -> V_193 ) ;
V_190 -> V_193 = 1 ;
V_190 -> V_192 = V_194 ;
V_201 = V_210 | V_211 ;
} else {
if ( V_190 -> V_193 ) {
F_55 ( V_190 -> V_192 != V_194 ) ;
V_190 -> V_193 = 0 ;
V_190 -> V_192 = 0 ;
}
V_190 -> V_194 = V_194 ;
V_190 -> V_192 ++ ;
if ( V_190 -> V_192 == V_194 )
V_190 -> V_192 ++ ;
V_201 = V_210 ;
}
if ( ! V_15 || V_190 -> V_192 > V_191 ) {
F_137 ( L_23
L_24 , V_15 ,
V_191 , V_190 -> V_192 , V_194 ) ;
F_115 ( V_117 , V_190 , 0 ) ;
return - V_168 ;
}
V_154 = F_122 ( V_106 , 1 ) ;
if ( ! V_154 ) {
F_115 ( V_117 , V_190 , 0 ) ;
return - V_168 ;
}
V_154 -> V_155 = V_15 ;
V_154 -> V_169 = V_195 -> V_169 ;
V_154 -> V_174 = V_190 -> V_159 >> 9 ;
V_154 -> V_177 = F_116 ( V_117 ) -> V_43 -> V_186 -> V_212 -> V_213 ;
V_154 -> V_170 = 0 ;
F_125 ( V_154 , V_110 , V_190 -> V_25 , V_21 - F_126 ( V_110 ) ) ;
F_137 ( L_25
L_26 , V_201 ,
V_190 -> V_192 , V_191 , V_190 -> V_193 ) ;
V_58 = V_3 -> V_30 -> V_214 ( V_117 , V_201 , V_154 ,
V_190 -> V_192 ,
V_190 -> V_204 , 0 ) ;
return V_58 ;
}
int F_146 ( struct V_110 * V_110 , int V_79 , T_3 V_21 , T_3 V_22 )
{
int V_215 = ( V_79 == 0 ) ;
struct V_2 * V_3 ;
int V_58 ;
V_3 = & F_116 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 ) {
V_58 = V_3 -> V_30 -> V_216 ( V_110 , V_21 ,
V_22 , NULL , V_215 ) ;
if ( V_58 )
V_215 = 0 ;
}
if ( ! V_215 ) {
F_147 ( V_110 ) ;
F_148 ( V_110 ) ;
}
return 0 ;
}
static void F_149 ( struct V_154 * V_154 , int V_79 )
{
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_220 ;
do {
struct V_110 * V_110 = V_218 -> V_221 ;
V_3 = & F_116 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_218 -> V_222 ;
V_22 = V_21 + V_218 -> V_223 - 1 ;
if ( V_218 -> V_222 == 0 && V_218 -> V_223 == V_131 )
V_220 = 1 ;
else
V_220 = 0 ;
if ( -- V_218 >= V_154 -> V_219 )
F_150 ( & V_218 -> V_221 -> V_36 ) ;
if ( F_146 ( V_110 , V_79 , V_21 , V_22 ) )
continue;
if ( V_220 )
F_105 ( V_110 ) ;
else
F_114 ( V_3 , V_110 ) ;
} while ( V_218 >= V_154 -> V_219 );
F_124 ( V_154 ) ;
}
static void F_151 ( struct V_154 * V_154 , int V_79 )
{
int V_215 = F_129 ( V_179 , & V_154 -> V_180 ) ;
struct V_217 * V_224 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_217 * V_218 = V_154 -> V_219 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_220 ;
int V_225 ;
int V_58 ;
if ( V_79 )
V_215 = 0 ;
do {
struct V_110 * V_110 = V_218 -> V_221 ;
struct V_8 * V_82 = NULL ;
struct V_8 * V_15 ;
F_137 ( L_27
L_28 , ( T_3 ) V_154 -> V_174 , V_79 ,
( long int ) V_154 -> V_177 ) ;
V_3 = & F_116 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_218 -> V_222 ;
V_22 = V_21 + V_218 -> V_223 - 1 ;
if ( V_218 -> V_222 == 0 && V_218 -> V_223 == V_131 )
V_220 = 1 ;
else
V_220 = 0 ;
if ( ++ V_218 <= V_224 )
F_150 ( & V_218 -> V_221 -> V_36 ) ;
F_53 ( & V_3 -> V_32 ) ;
V_15 = F_90 ( V_3 , V_21 , V_105 ) ;
if ( V_15 && V_15 -> V_21 == V_21 ) {
F_67 ( V_15 , & V_82 ) ;
}
F_57 ( & V_3 -> V_32 ) ;
V_225 = ( int ) ( unsigned long ) V_154 -> V_177 ;
if ( V_215 && V_3 -> V_30 && V_3 -> V_30 -> V_226 ) {
V_58 = V_3 -> V_30 -> V_226 ( V_110 , V_21 , V_22 ,
V_15 , V_225 ) ;
if ( V_58 )
V_215 = 0 ;
else
F_136 ( V_21 , V_110 ) ;
}
if ( ! V_215 && V_3 -> V_30 && V_3 -> V_30 -> V_227 ) {
V_58 = V_3 -> V_30 -> V_227 ( V_110 , V_225 ) ;
if ( ! V_58 && ! V_79 &&
F_129 ( V_179 , & V_154 -> V_180 ) )
V_215 = 1 ;
} else if ( ! V_215 ) {
V_58 = F_139 ( V_154 , V_110 , V_21 , V_22 , V_225 , NULL ) ;
if ( V_58 == 0 ) {
V_215 =
F_129 ( V_179 , & V_154 -> V_180 ) ;
if ( V_79 )
V_215 = 0 ;
F_68 ( & V_82 ) ;
continue;
}
}
if ( V_215 && V_3 -> V_228 ) {
F_79 ( V_3 , V_21 , V_22 , & V_82 ,
V_29 ) ;
}
F_84 ( V_3 , V_21 , V_22 , & V_82 , V_29 ) ;
if ( V_220 ) {
if ( V_215 ) {
F_112 ( V_110 ) ;
} else {
F_147 ( V_110 ) ;
F_148 ( V_110 ) ;
}
F_96 ( V_110 ) ;
} else {
if ( V_215 ) {
F_111 ( V_3 , V_110 ) ;
} else {
F_147 ( V_110 ) ;
F_148 ( V_110 ) ;
}
F_113 ( V_3 , V_110 ) ;
}
} while ( V_218 <= V_224 );
F_124 ( V_154 ) ;
}
struct V_154 *
F_152 ( struct V_229 * V_175 , T_3 V_230 , int V_231 ,
T_2 V_232 )
{
struct V_154 * V_154 ;
V_154 = F_122 ( V_232 , V_231 ) ;
if ( V_154 == NULL && ( V_233 -> V_36 & V_234 ) ) {
while ( ! V_154 && ( V_231 /= 2 ) )
V_154 = F_122 ( V_232 , V_231 ) ;
}
if ( V_154 ) {
V_154 -> V_170 = 0 ;
V_154 -> V_177 = V_175 ;
V_154 -> V_174 = V_230 ;
}
return V_154 ;
}
static int T_4 F_153 ( int V_235 , struct V_154 * V_154 ,
int V_160 , unsigned long V_204 )
{
int V_58 = 0 ;
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_110 * V_110 = V_218 -> V_221 ;
struct V_2 * V_3 = V_154 -> V_155 ;
T_3 V_21 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) + V_218 -> V_222 ;
V_154 -> V_155 = NULL ;
F_154 ( V_154 ) ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_58 = V_3 -> V_30 -> V_214 ( V_110 -> V_4 -> V_5 , V_235 , V_154 ,
V_160 , V_204 , V_21 ) ;
else
F_127 ( V_235 , V_154 ) ;
if ( F_155 ( V_154 , V_236 ) )
V_58 = - V_237 ;
F_124 ( V_154 ) ;
return V_58 ;
}
static int F_156 ( struct V_2 * V_3 , struct V_110 * V_110 ,
unsigned long V_44 , T_6 V_238 , struct V_154 * V_154 ,
unsigned long V_204 )
{
int V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_239 )
V_58 = V_3 -> V_30 -> V_239 ( V_110 , V_44 , V_238 , V_154 ,
V_204 ) ;
F_55 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_157 ( int V_235 , struct V_2 * V_3 ,
struct V_110 * V_110 , T_7 V_165 ,
T_6 V_238 , unsigned long V_44 ,
struct V_229 * V_175 ,
struct V_154 * * V_240 ,
unsigned long V_241 ,
T_8 V_242 ,
int V_160 ,
unsigned long V_243 ,
unsigned long V_204 )
{
int V_58 = 0 ;
struct V_154 * V_154 ;
int V_244 ;
int V_142 = 0 ;
int V_245 = V_204 & V_207 ;
int V_246 = V_243 & V_207 ;
T_6 V_247 = F_95 ( T_6 , V_238 , V_131 ) ;
if ( V_240 && * V_240 ) {
V_154 = * V_240 ;
if ( V_246 )
V_142 = V_154 -> V_174 == V_165 ;
else
V_142 = V_154 -> V_174 + ( V_154 -> V_170 >> 9 ) ==
V_165 ;
if ( V_243 != V_204 || ! V_142 ||
F_156 ( V_3 , V_110 , V_44 , V_247 , V_154 , V_204 ) ||
F_125 ( V_154 , V_110 , V_247 , V_44 ) < V_247 ) {
V_58 = F_153 ( V_235 , V_154 , V_160 ,
V_243 ) ;
if ( V_58 < 0 )
return V_58 ;
V_154 = NULL ;
} else {
return 0 ;
}
}
if ( V_245 )
V_244 = V_248 ;
else
V_244 = F_158 ( V_175 ) ;
V_154 = F_152 ( V_175 , V_165 , V_244 , V_106 | V_249 ) ;
if ( ! V_154 )
return - V_11 ;
F_125 ( V_154 , V_110 , V_247 , V_44 ) ;
V_154 -> V_169 = V_242 ;
V_154 -> V_155 = V_3 ;
if ( V_240 )
* V_240 = V_154 ;
else
V_58 = F_153 ( V_235 , V_154 , V_160 , V_204 ) ;
return V_58 ;
}
void F_159 ( struct V_13 * V_16 , struct V_110 * V_110 )
{
if ( ! F_160 ( V_110 ) ) {
F_161 ( V_110 ) ;
F_162 ( V_110 ) ;
F_163 ( V_110 , ( unsigned long ) V_16 ) ;
} else {
F_27 ( V_110 -> V_37 != ( unsigned long ) V_16 ) ;
}
}
void F_164 ( struct V_110 * V_110 )
{
if ( ! F_160 ( V_110 ) ) {
F_161 ( V_110 ) ;
F_162 ( V_110 ) ;
F_163 ( V_110 , V_250 ) ;
}
}
static int F_165 ( struct V_2 * V_3 ,
struct V_110 * V_110 ,
T_9 * V_251 ,
struct V_154 * * V_154 , int V_160 ,
unsigned long * V_204 )
{
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_252 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_166 ( V_117 ) ;
T_3 V_205 ;
T_3 V_256 ;
T_7 V_165 ;
struct V_196 * V_197 ;
struct V_229 * V_175 ;
struct V_257 * V_258 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_260 ;
T_6 V_261 ;
T_6 V_262 = V_117 -> V_6 -> V_263 ;
unsigned long V_264 = 0 ;
F_164 ( V_110 ) ;
if ( ! F_167 ( V_110 ) ) {
if ( F_168 ( V_110 ) == 0 ) {
F_55 ( V_262 != V_265 ) ;
goto V_89;
}
}
V_22 = V_252 ;
while ( 1 ) {
F_82 ( V_3 , V_21 , V_22 ) ;
V_258 = F_169 ( V_117 , V_21 ) ;
if ( ! V_258 )
break;
F_85 ( V_3 , V_21 , V_22 ) ;
F_170 ( V_117 , V_258 , 1 ) ;
F_171 ( V_258 ) ;
}
if ( V_110 -> V_107 == V_255 >> V_108 ) {
char * V_266 ;
T_6 V_267 = V_255 & ( V_131 - 1 ) ;
if ( V_267 ) {
V_260 = V_131 - V_267 ;
V_266 = F_172 ( V_110 ) ;
memset ( V_266 + V_267 , 0 , V_260 ) ;
F_173 ( V_110 ) ;
F_174 ( V_266 ) ;
}
}
while ( V_253 <= V_22 ) {
if ( V_253 >= V_255 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_260 = V_131 - V_259 ;
V_266 = F_172 ( V_110 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_173 ( V_110 ) ;
F_174 ( V_266 ) ;
F_79 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_84 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
break;
}
V_197 = V_251 ( V_117 , V_110 , V_259 , V_253 ,
V_22 - V_253 + 1 , 0 ) ;
if ( F_175 ( V_197 ) ) {
F_148 ( V_110 ) ;
F_85 ( V_3 , V_253 , V_22 ) ;
break;
}
V_254 = V_253 - V_197 -> V_21 ;
F_55 ( F_176 ( V_197 ) <= V_253 ) ;
F_55 ( V_22 < V_253 ) ;
if ( F_129 ( V_206 , & V_197 -> V_36 ) ) {
V_264 = V_207 ;
F_145 ( & V_264 ,
V_197 -> V_208 ) ;
}
V_260 = F_107 ( F_176 ( V_197 ) - V_253 , V_22 - V_253 + 1 ) ;
V_256 = F_107 ( F_176 ( V_197 ) - 1 , V_22 ) ;
V_260 = ( V_260 + V_262 - 1 ) & ~ ( ( T_3 ) V_262 - 1 ) ;
if ( V_264 & V_207 ) {
V_261 = V_197 -> V_268 ;
V_165 = V_197 -> V_205 >> 9 ;
} else {
V_165 = ( V_197 -> V_205 + V_254 ) >> 9 ;
V_261 = V_260 ;
}
V_175 = V_197 -> V_175 ;
V_205 = V_197 -> V_205 ;
if ( F_129 ( V_269 , & V_197 -> V_36 ) )
V_205 = V_270 ;
F_144 ( V_197 ) ;
V_197 = NULL ;
if ( V_205 == V_270 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_266 = F_172 ( V_110 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_173 ( V_110 ) ;
F_174 ( V_266 ) ;
F_79 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_84 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( F_101 ( V_3 , V_253 , V_256 ,
V_101 , 1 , NULL ) ) {
F_111 ( V_3 , V_110 ) ;
F_85 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( V_205 == V_271 ) {
F_148 ( V_110 ) ;
F_85 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_272 ) {
V_58 = V_3 -> V_30 -> V_272 ( V_110 , V_253 ,
V_253 + V_260 - 1 ) ;
}
if ( ! V_58 ) {
unsigned long V_273 = ( V_255 >> V_108 ) + 1 ;
V_273 -= V_110 -> V_107 ;
V_58 = F_157 ( V_274 , V_3 , V_110 ,
V_165 , V_261 , V_259 ,
V_175 , V_154 , V_273 ,
F_151 , V_160 ,
* V_204 ,
V_264 ) ;
if ( ! V_58 ) {
V_244 ++ ;
* V_204 = V_264 ;
}
}
if ( V_58 ) {
F_148 ( V_110 ) ;
F_85 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
}
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
}
V_89:
if ( ! V_244 ) {
if ( ! F_177 ( V_110 ) )
F_112 ( V_110 ) ;
F_96 ( V_110 ) ;
}
return 0 ;
}
int F_178 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_251 , int V_160 )
{
struct V_154 * V_154 = NULL ;
unsigned long V_204 = 0 ;
int V_58 ;
V_58 = F_165 ( V_3 , V_110 , V_251 , & V_154 , V_160 ,
& V_204 ) ;
if ( V_154 )
V_58 = F_153 ( V_274 , V_154 , V_160 , V_204 ) ;
return V_58 ;
}
static T_5 void F_179 ( struct V_110 * V_110 ,
struct V_275 * V_276 ,
unsigned long V_277 )
{
V_276 -> V_278 -= V_277 ;
if ( V_276 -> V_279 || ( V_276 -> V_278 > 0 &&
V_276 -> V_280 == 0 && V_276 -> V_281 == V_282 ) )
V_110 -> V_4 -> V_283 = V_110 -> V_107 + V_277 ;
}
static int F_180 ( struct V_110 * V_110 , struct V_275 * V_276 ,
void * V_284 )
{
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
struct V_285 * V_286 = V_284 ;
struct V_2 * V_3 = V_286 -> V_3 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_123 ;
T_3 V_252 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_166 ( V_117 ) ;
T_3 V_205 ;
T_3 V_260 ;
T_7 V_165 ;
struct V_8 * V_81 = NULL ;
struct V_196 * V_197 ;
struct V_229 * V_175 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_262 ;
T_10 V_287 = F_166 ( V_117 ) ;
unsigned long V_109 = V_287 >> V_108 ;
T_3 V_288 ;
T_3 V_124 ;
int V_289 ;
int V_290 ;
int V_291 ;
unsigned long V_277 = 0 ;
bool V_292 = true ;
if ( V_276 -> V_293 == V_294 )
V_291 = V_178 ;
else
V_291 = V_171 ;
F_181 ( V_110 , V_117 , V_276 ) ;
F_27 ( ! F_182 ( V_110 ) ) ;
F_183 ( V_110 ) ;
V_259 = V_287 & ( V_131 - 1 ) ;
if ( V_110 -> V_107 > V_109 ||
( V_110 -> V_107 == V_109 && ! V_259 ) ) {
V_110 -> V_4 -> V_295 -> V_296 ( V_110 , 0 ) ;
F_96 ( V_110 ) ;
return 0 ;
}
if ( V_110 -> V_107 == V_109 ) {
char * V_266 ;
V_266 = F_172 ( V_110 ) ;
memset ( V_266 + V_259 , 0 ,
V_131 - V_259 ) ;
F_174 ( V_266 ) ;
F_173 ( V_110 ) ;
}
V_259 = 0 ;
F_164 ( V_110 ) ;
if ( ! V_3 -> V_30 || ! V_3 -> V_30 -> V_292 )
V_292 = false ;
V_123 = V_21 ;
V_124 = 0 ;
V_289 = 0 ;
if ( ! V_286 -> V_297 && V_292 ) {
T_3 V_298 = 0 ;
F_179 ( V_110 , V_276 , 0 ) ;
while ( V_124 < V_252 ) {
V_288 = F_100 ( V_117 , V_3 ,
V_110 ,
& V_123 ,
& V_124 ,
128 * 1024 * 1024 ) ;
if ( V_288 == 0 ) {
V_123 = V_124 + 1 ;
continue;
}
V_58 = V_3 -> V_30 -> V_292 ( V_117 , V_110 ,
V_123 ,
V_124 ,
& V_289 ,
& V_277 ) ;
if ( V_58 ) {
F_148 ( V_110 ) ;
goto V_129;
}
V_298 += ( V_124 - V_123 +
V_131 ) >>
V_108 ;
V_123 = V_124 + 1 ;
}
if ( V_276 -> V_278 < V_298 ) {
int V_299 = 8192 ;
if ( V_298 < V_299 * 2 )
V_299 = V_298 ;
V_276 -> V_278 = F_95 ( T_3 , V_298 ,
V_299 ) ;
}
if ( V_289 ) {
V_58 = 0 ;
V_276 -> V_278 -= V_277 ;
goto V_300;
}
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_301 ) {
V_58 = V_3 -> V_30 -> V_301 ( V_110 , V_21 ,
V_252 ) ;
if ( V_58 ) {
if ( V_58 == - V_302 )
V_276 -> V_303 ++ ;
else
F_184 ( V_276 , V_110 ) ;
F_179 ( V_110 , V_276 , V_277 ) ;
F_96 ( V_110 ) ;
V_58 = 0 ;
goto V_300;
}
}
F_179 ( V_110 , V_276 , V_277 + 1 ) ;
V_22 = V_252 ;
if ( V_255 <= V_21 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_110 , V_21 ,
V_252 , NULL , 1 ) ;
goto V_129;
}
V_262 = V_117 -> V_6 -> V_263 ;
while ( V_253 <= V_22 ) {
if ( V_253 >= V_255 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_110 , V_253 ,
V_252 , NULL , 1 ) ;
break;
}
V_197 = V_286 -> V_251 ( V_117 , V_110 , V_259 , V_253 ,
V_22 - V_253 + 1 , 1 ) ;
if ( F_175 ( V_197 ) ) {
F_148 ( V_110 ) ;
break;
}
V_254 = V_253 - V_197 -> V_21 ;
F_55 ( F_176 ( V_197 ) <= V_253 ) ;
F_55 ( V_22 < V_253 ) ;
V_260 = F_107 ( F_176 ( V_197 ) - V_253 , V_22 - V_253 + 1 ) ;
V_260 = ( V_260 + V_262 - 1 ) & ~ ( ( T_3 ) V_262 - 1 ) ;
V_165 = ( V_197 -> V_205 + V_254 ) >> 9 ;
V_175 = V_197 -> V_175 ;
V_205 = V_197 -> V_205 ;
V_290 = F_129 ( V_206 , & V_197 -> V_36 ) ;
F_144 ( V_197 ) ;
V_197 = NULL ;
if ( V_290 || V_205 == V_270 ||
V_205 == V_271 ) {
if ( ! V_290 && V_3 -> V_30 &&
V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_110 , V_253 ,
V_253 + V_260 - 1 ,
NULL , 1 ) ;
else if ( V_290 ) {
V_244 ++ ;
}
V_253 += V_260 ;
V_259 += V_260 ;
continue;
}
if ( 0 && ! F_101 ( V_3 , V_253 , V_253 + V_260 - 1 ,
V_77 , 0 , NULL ) ) {
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_304 ) {
V_58 = V_3 -> V_30 -> V_304 ( V_110 , V_253 ,
V_253 + V_260 - 1 ) ;
} else {
V_58 = 0 ;
}
if ( V_58 ) {
F_148 ( V_110 ) ;
} else {
unsigned long V_305 = V_109 + 1 ;
F_86 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
if ( ! F_185 ( V_110 ) ) {
F_9 ( V_20 L_29
L_30 ,
V_110 -> V_107 , ( unsigned long long ) V_253 ,
( unsigned long long ) V_22 ) ;
}
V_58 = F_157 ( V_291 , V_3 , V_110 ,
V_165 , V_260 , V_259 ,
V_175 , & V_286 -> V_154 , V_305 ,
F_149 ,
0 , 0 , 0 ) ;
if ( V_58 )
F_148 ( V_110 ) ;
}
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
V_244 ++ ;
}
V_129:
if ( V_244 == 0 ) {
F_88 ( V_110 ) ;
F_105 ( V_110 ) ;
}
F_96 ( V_110 ) ;
V_300:
F_25 ( V_81 ) ;
return 0 ;
}
static int F_186 ( void * V_306 )
{
F_187 () ;
return 0 ;
}
static void F_188 ( struct V_13 * V_16 )
{
F_189 ( & V_16 -> V_307 , V_308 , F_186 ,
V_92 ) ;
}
static int F_190 ( struct V_13 * V_16 ,
struct V_1 * V_186 ,
struct V_285 * V_286 )
{
unsigned long V_121 , V_188 ;
int V_309 = 0 ;
int V_58 = 0 ;
if ( ! F_191 ( V_16 ) ) {
V_309 = 1 ;
F_192 ( V_286 ) ;
F_193 ( V_16 ) ;
}
if ( F_129 ( V_308 , & V_16 -> V_307 ) ) {
F_194 ( V_16 ) ;
if ( ! V_286 -> V_310 )
return 0 ;
if ( ! V_309 ) {
F_192 ( V_286 ) ;
V_309 = 1 ;
}
while ( 1 ) {
F_188 ( V_16 ) ;
F_193 ( V_16 ) ;
if ( ! F_129 ( V_308 , & V_16 -> V_307 ) )
break;
F_194 ( V_16 ) ;
}
}
F_53 ( & V_16 -> V_311 ) ;
if ( F_195 ( V_312 , & V_16 -> V_307 ) ) {
F_196 ( V_308 , & V_16 -> V_307 ) ;
F_57 ( & V_16 -> V_311 ) ;
F_197 ( V_16 , V_313 ) ;
F_53 ( & V_186 -> V_314 ) ;
if ( V_186 -> V_315 >= V_16 -> V_25 )
V_186 -> V_315 -= V_16 -> V_25 ;
else
F_27 ( 1 ) ;
F_57 ( & V_186 -> V_314 ) ;
V_58 = 1 ;
} else {
F_57 ( & V_16 -> V_311 ) ;
}
F_194 ( V_16 ) ;
if ( ! V_58 )
return V_58 ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
struct V_110 * V_46 = F_135 ( V_16 , V_121 ) ;
if ( ! F_198 ( V_46 ) ) {
if ( ! V_309 ) {
F_192 ( V_286 ) ;
V_309 = 1 ;
}
F_98 ( V_46 ) ;
}
}
return V_58 ;
}
static void F_199 ( struct V_13 * V_16 )
{
F_200 ( V_308 , & V_16 -> V_307 ) ;
F_201 () ;
F_202 ( & V_16 -> V_307 , V_308 ) ;
}
static void F_203 ( struct V_154 * V_154 , int V_79 )
{
int V_215 = V_79 == 0 ;
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_13 * V_16 ;
int V_129 ;
do {
struct V_110 * V_110 = V_218 -> V_221 ;
V_218 -- ;
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_55 ( ! V_16 ) ;
V_129 = F_26 ( & V_16 -> V_316 ) ;
if ( ! V_215 || F_129 ( V_317 , & V_16 -> V_307 ) ) {
F_196 ( V_317 , & V_16 -> V_307 ) ;
F_147 ( V_110 ) ;
F_148 ( V_110 ) ;
}
F_105 ( V_110 ) ;
if ( ! V_129 )
continue;
F_199 ( V_16 ) ;
} while ( V_218 >= V_154 -> V_219 );
F_124 ( V_154 ) ;
}
static int F_204 ( struct V_13 * V_16 ,
struct V_1 * V_186 ,
struct V_275 * V_276 ,
struct V_285 * V_286 )
{
struct V_229 * V_175 = V_186 -> V_212 -> V_213 ;
T_3 V_44 = V_16 -> V_21 ;
unsigned long V_121 , V_188 ;
unsigned long V_204 = 0 ;
int V_235 = ( V_286 -> V_310 ? V_178 : V_171 ) ;
int V_58 = 0 ;
F_200 ( V_317 , & V_16 -> V_307 ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_22 ( & V_16 -> V_316 , V_188 ) ;
if ( F_205 ( V_16 ) == V_318 )
V_204 = V_319 ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
struct V_110 * V_46 = F_135 ( V_16 , V_121 ) ;
F_104 ( V_46 ) ;
F_88 ( V_46 ) ;
V_58 = F_157 ( V_235 , V_16 -> V_3 , V_46 , V_44 >> 9 ,
V_131 , 0 , V_175 , & V_286 -> V_154 ,
- 1 , F_203 ,
0 , V_286 -> V_204 , V_204 ) ;
V_286 -> V_204 = V_204 ;
if ( V_58 ) {
F_196 ( V_317 , & V_16 -> V_307 ) ;
F_148 ( V_46 ) ;
if ( F_206 ( V_188 - V_121 , & V_16 -> V_316 ) )
F_199 ( V_16 ) ;
V_58 = - V_168 ;
break;
}
V_44 += V_131 ;
F_179 ( V_46 , V_276 , 1 ) ;
F_96 ( V_46 ) ;
}
if ( F_207 ( V_58 ) ) {
for (; V_121 < V_188 ; V_121 ++ ) {
struct V_110 * V_46 = F_135 ( V_16 , V_121 ) ;
F_96 ( V_46 ) ;
}
}
return V_58 ;
}
int F_208 ( struct V_26 * V_4 ,
struct V_275 * V_276 )
{
struct V_2 * V_3 = & F_116 ( V_4 -> V_5 ) -> V_152 ;
struct V_1 * V_186 = F_116 ( V_4 -> V_5 ) -> V_43 -> V_186 ;
struct V_13 * V_16 , * V_320 = NULL ;
struct V_285 V_286 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
. V_204 = 0 ,
} ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_321 = 0 ;
struct V_322 V_323 ;
int V_120 ;
T_11 V_107 ;
T_11 V_22 ;
int V_324 = 0 ;
int V_325 ;
F_209 ( & V_323 , 0 ) ;
if ( V_276 -> V_279 ) {
V_107 = V_4 -> V_283 ;
V_22 = - 1 ;
} else {
V_107 = V_276 -> V_280 >> V_108 ;
V_22 = V_276 -> V_281 >> V_108 ;
V_324 = 1 ;
}
if ( V_276 -> V_293 == V_294 )
V_325 = V_326 ;
else
V_325 = V_327 ;
V_328:
if ( V_276 -> V_293 == V_294 )
F_210 ( V_4 , V_107 , V_22 ) ;
while ( ! V_129 && ! V_321 && ( V_107 <= V_22 ) &&
( V_120 = F_211 ( & V_323 , V_4 , & V_107 , V_325 ,
F_107 ( V_22 - V_107 , ( T_11 ) V_329 - 1 ) + 1 ) ) ) {
unsigned V_121 ;
V_324 = 1 ;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
struct V_110 * V_110 = V_323 . V_119 [ V_121 ] ;
if ( ! F_160 ( V_110 ) )
continue;
if ( ! V_276 -> V_279 && V_110 -> V_107 > V_22 ) {
V_129 = 1 ;
break;
}
F_53 ( & V_4 -> V_330 ) ;
if ( ! F_160 ( V_110 ) ) {
F_57 ( & V_4 -> V_330 ) ;
continue;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
if ( ! V_16 ) {
F_57 ( & V_4 -> V_330 ) ;
F_27 ( 1 ) ;
continue;
}
if ( V_16 == V_320 ) {
F_57 ( & V_4 -> V_330 ) ;
continue;
}
V_58 = F_212 ( & V_16 -> V_23 ) ;
F_57 ( & V_4 -> V_330 ) ;
if ( ! V_58 )
continue;
V_320 = V_16 ;
V_58 = F_190 ( V_16 , V_186 , & V_286 ) ;
if ( ! V_58 ) {
F_213 ( V_16 ) ;
continue;
}
V_58 = F_204 ( V_16 , V_186 , V_276 , & V_286 ) ;
if ( V_58 ) {
V_129 = 1 ;
F_213 ( V_16 ) ;
break;
}
F_213 ( V_16 ) ;
V_321 = V_276 -> V_278 <= 0 ;
}
F_214 ( & V_323 ) ;
F_58 () ;
}
if ( ! V_324 && ! V_129 ) {
V_324 = 1 ;
V_107 = 0 ;
goto V_328;
}
F_192 ( & V_286 ) ;
return V_58 ;
}
static int F_215 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_275 * V_276 ,
T_12 V_331 , void * V_284 ,
void (* F_216)( void * ) )
{
struct V_117 * V_117 = V_4 -> V_5 ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_321 = 0 ;
struct V_322 V_323 ;
int V_120 ;
T_11 V_107 ;
T_11 V_22 ;
int V_324 = 0 ;
int V_325 ;
if ( ! F_217 ( V_117 ) )
return 0 ;
F_209 ( & V_323 , 0 ) ;
if ( V_276 -> V_279 ) {
V_107 = V_4 -> V_283 ;
V_22 = - 1 ;
} else {
V_107 = V_276 -> V_280 >> V_108 ;
V_22 = V_276 -> V_281 >> V_108 ;
V_324 = 1 ;
}
if ( V_276 -> V_293 == V_294 )
V_325 = V_326 ;
else
V_325 = V_327 ;
V_328:
if ( V_276 -> V_293 == V_294 )
F_210 ( V_4 , V_107 , V_22 ) ;
while ( ! V_129 && ! V_321 && ( V_107 <= V_22 ) &&
( V_120 = F_211 ( & V_323 , V_4 , & V_107 , V_325 ,
F_107 ( V_22 - V_107 , ( T_11 ) V_329 - 1 ) + 1 ) ) ) {
unsigned V_121 ;
V_324 = 1 ;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
struct V_110 * V_110 = V_323 . V_119 [ V_121 ] ;
if ( V_3 -> V_30 &&
V_3 -> V_30 -> V_332 ) {
V_3 -> V_30 -> V_332 ( V_110 ,
V_284 , F_216 ) ;
} else {
if ( ! F_198 ( V_110 ) ) {
F_216 ( V_284 ) ;
F_98 ( V_110 ) ;
}
}
if ( F_207 ( V_110 -> V_4 != V_4 ) ) {
F_96 ( V_110 ) ;
continue;
}
if ( ! V_276 -> V_279 && V_110 -> V_107 > V_22 ) {
V_129 = 1 ;
F_96 ( V_110 ) ;
continue;
}
if ( V_276 -> V_293 != V_333 ) {
if ( F_185 ( V_110 ) )
F_216 ( V_284 ) ;
F_218 ( V_110 ) ;
}
if ( F_185 ( V_110 ) ||
! F_104 ( V_110 ) ) {
F_96 ( V_110 ) ;
continue;
}
V_58 = (* V_331)( V_110 , V_276 , V_284 ) ;
if ( F_207 ( V_58 == V_334 ) ) {
F_96 ( V_110 ) ;
V_58 = 0 ;
}
if ( V_58 )
V_129 = 1 ;
V_321 = V_276 -> V_278 <= 0 ;
}
F_214 ( & V_323 ) ;
F_58 () ;
}
if ( ! V_324 && ! V_129 ) {
V_324 = 1 ;
V_107 = 0 ;
goto V_328;
}
F_219 ( V_117 ) ;
return V_58 ;
}
static void F_220 ( struct V_285 * V_286 )
{
if ( V_286 -> V_154 ) {
int V_235 = V_171 ;
int V_58 ;
if ( V_286 -> V_310 )
V_235 = V_178 ;
V_58 = F_153 ( V_235 , V_286 -> V_154 , 0 , V_286 -> V_204 ) ;
F_55 ( V_58 < 0 ) ;
V_286 -> V_154 = NULL ;
}
}
static T_5 void F_192 ( void * V_284 )
{
struct V_285 * V_286 = V_284 ;
F_220 ( V_286 ) ;
}
int F_221 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_251 ,
struct V_275 * V_276 )
{
int V_58 ;
struct V_285 V_286 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
. V_204 = 0 ,
} ;
V_58 = F_180 ( V_110 , V_276 , & V_286 ) ;
F_220 ( & V_286 ) ;
return V_58 ;
}
int F_222 ( struct V_2 * V_3 , struct V_117 * V_117 ,
T_3 V_21 , T_3 V_22 , T_9 * V_251 ,
int V_335 )
{
int V_58 = 0 ;
struct V_26 * V_4 = V_117 -> V_122 ;
struct V_110 * V_110 ;
unsigned long V_120 = ( V_22 - V_21 + V_131 ) >>
V_108 ;
struct V_285 V_286 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 1 ,
. V_310 = V_335 == V_294 ,
. V_204 = 0 ,
} ;
struct V_275 V_336 = {
. V_293 = V_335 ,
. V_278 = V_120 * 2 ,
. V_280 = V_21 ,
. V_281 = V_22 + 1 ,
} ;
while ( V_21 <= V_22 ) {
V_110 = F_87 ( V_4 , V_21 >> V_108 ) ;
if ( F_104 ( V_110 ) )
V_58 = F_180 ( V_110 , & V_336 , & V_286 ) ;
else {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_110 , V_21 ,
V_21 + V_131 - 1 ,
NULL , 1 ) ;
F_96 ( V_110 ) ;
}
F_89 ( V_110 ) ;
V_21 += V_131 ;
}
F_220 ( & V_286 ) ;
return V_58 ;
}
int F_223 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
T_9 * V_251 ,
struct V_275 * V_276 )
{
int V_58 = 0 ;
struct V_285 V_286 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
. V_204 = 0 ,
} ;
V_58 = F_215 ( V_3 , V_4 , V_276 ,
F_180 , & V_286 ,
F_192 ) ;
F_220 ( & V_286 ) ;
return V_58 ;
}
int F_224 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_337 * V_119 , unsigned V_120 ,
T_9 V_251 )
{
struct V_154 * V_154 = NULL ;
unsigned V_338 ;
unsigned long V_204 = 0 ;
struct V_110 * V_339 [ 16 ] ;
struct V_110 * V_110 ;
int V_121 = 0 ;
int V_244 = 0 ;
for ( V_338 = 0 ; V_338 < V_120 ; V_338 ++ ) {
V_110 = F_8 ( V_119 -> V_55 , struct V_110 , V_340 ) ;
F_150 ( & V_110 -> V_36 ) ;
F_11 ( & V_110 -> V_340 ) ;
if ( F_225 ( V_110 , V_4 ,
V_110 -> V_107 , V_106 ) ) {
F_89 ( V_110 ) ;
continue;
}
V_339 [ V_244 ++ ] = V_110 ;
if ( V_244 < F_226 ( V_339 ) )
continue;
for ( V_121 = 0 ; V_121 < V_244 ; V_121 ++ ) {
F_165 ( V_3 , V_339 [ V_121 ] , V_251 ,
& V_154 , 0 , & V_204 ) ;
F_89 ( V_339 [ V_121 ] ) ;
}
V_244 = 0 ;
}
for ( V_121 = 0 ; V_121 < V_244 ; V_121 ++ ) {
F_165 ( V_3 , V_339 [ V_121 ] , V_251 ,
& V_154 , 0 , & V_204 ) ;
F_89 ( V_339 [ V_121 ] ) ;
}
F_55 ( ! F_7 ( V_119 ) ) ;
if ( V_154 )
return F_153 ( V_274 , V_154 , 0 , V_204 ) ;
return 0 ;
}
int F_227 ( struct V_2 * V_3 ,
struct V_110 * V_110 , unsigned long V_44 )
{
struct V_8 * V_81 = NULL ;
T_3 V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
T_6 V_262 = V_110 -> V_4 -> V_5 -> V_6 -> V_263 ;
V_21 += ( V_44 + V_262 - 1 ) & ~ ( V_262 - 1 ) ;
if ( V_21 > V_22 )
return 0 ;
F_81 ( V_3 , V_21 , V_22 , 0 , & V_81 ) ;
F_218 ( V_110 ) ;
F_52 ( V_3 , V_21 , V_22 ,
V_105 | V_77 | V_100 |
V_103 ,
1 , 1 , & V_81 , V_106 ) ;
return 0 ;
}
int F_228 ( struct V_198 * V_341 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
int V_58 = 1 ;
if ( F_101 ( V_3 , V_21 , V_22 ,
V_63 , 0 , NULL ) )
V_58 = 0 ;
else {
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
V_58 = F_52 ( V_3 , V_21 , V_22 ,
~ ( V_105 | V_342 ) ,
0 , 0 , NULL , V_34 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
else
V_58 = 1 ;
}
return V_58 ;
}
int F_229 ( struct V_198 * V_341 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
struct V_196 * V_197 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ( V_34 & V_87 ) &&
V_110 -> V_4 -> V_5 -> V_287 > 16 * 1024 * 1024 ) {
T_3 V_25 ;
while ( V_21 <= V_22 ) {
V_25 = V_22 - V_21 + 1 ;
F_230 ( & V_341 -> V_32 ) ;
V_197 = F_142 ( V_341 , V_21 , V_25 ) ;
if ( ! V_197 ) {
F_231 ( & V_341 -> V_32 ) ;
break;
}
if ( F_129 ( V_343 , & V_197 -> V_36 ) ||
V_197 -> V_21 != V_21 ) {
F_231 ( & V_341 -> V_32 ) ;
F_144 ( V_197 ) ;
break;
}
if ( ! F_101 ( V_3 , V_197 -> V_21 ,
F_176 ( V_197 ) - 1 ,
V_105 | V_344 ,
0 , NULL ) ) {
F_232 ( V_341 , V_197 ) ;
F_144 ( V_197 ) ;
}
V_21 = F_176 ( V_197 ) ;
F_231 ( & V_341 -> V_32 ) ;
F_144 ( V_197 ) ;
}
}
return F_228 ( V_341 , V_3 , V_110 , V_34 ) ;
}
static struct V_196 * F_233 ( struct V_117 * V_117 ,
T_3 V_44 ,
T_3 V_143 ,
T_9 * V_251 )
{
T_3 V_345 = F_116 ( V_117 ) -> V_43 -> V_345 ;
struct V_196 * V_197 ;
T_3 V_25 ;
if ( V_44 >= V_143 )
return NULL ;
while( 1 ) {
V_25 = V_143 - V_44 ;
if ( V_25 == 0 )
break;
V_25 = ( V_25 + V_345 - 1 ) & ~ ( V_345 - 1 ) ;
V_197 = V_251 ( V_117 , NULL , 0 , V_44 , V_25 , 0 ) ;
if ( F_175 ( V_197 ) )
return V_197 ;
if ( ! F_129 ( V_346 , & V_197 -> V_36 ) &&
V_197 -> V_205 != V_270 ) {
return V_197 ;
}
V_44 = F_176 ( V_197 ) ;
F_144 ( V_197 ) ;
if ( V_44 >= V_143 )
break;
}
return NULL ;
}
int F_234 ( struct V_117 * V_117 , struct V_347 * V_348 ,
T_13 V_21 , T_13 V_25 , T_9 * V_251 )
{
int V_58 = 0 ;
T_3 V_349 = V_21 ;
T_3 F_108 = V_21 + V_25 ;
T_14 V_36 = 0 ;
T_14 V_350 ;
T_3 V_143 ;
T_3 V_351 = 0 ;
T_3 V_352 = 0 ;
T_3 V_353 = F_166 ( V_117 ) ;
struct V_354 V_355 ;
struct V_196 * V_197 = NULL ;
struct V_8 * V_81 = NULL ;
struct V_356 * V_357 ;
struct V_358 * V_359 ;
int V_22 = 0 ;
T_3 V_360 = 0 ;
T_3 V_361 = 0 ;
T_3 V_362 = 0 ;
unsigned long V_363 ;
if ( V_25 == 0 )
return - V_364 ;
V_357 = F_235 () ;
if ( ! V_357 )
return - V_11 ;
V_357 -> V_365 = 1 ;
V_21 = F_236 ( V_21 , F_116 ( V_117 ) -> V_43 -> V_345 ) ;
V_25 = F_236 ( V_25 , F_116 ( V_117 ) -> V_43 -> V_345 ) ;
V_58 = F_237 ( NULL , F_116 ( V_117 ) -> V_43 ,
V_357 , F_238 ( V_117 ) , - 1 , 0 ) ;
if ( V_58 < 0 ) {
F_239 ( V_357 ) ;
return V_58 ;
}
F_27 ( ! V_58 ) ;
V_357 -> V_366 [ 0 ] -- ;
V_359 = F_240 ( V_357 -> V_367 [ 0 ] , V_357 -> V_366 [ 0 ] ,
struct V_358 ) ;
F_241 ( V_357 -> V_367 [ 0 ] , & V_355 , V_357 -> V_366 [ 0 ] ) ;
V_350 = F_242 ( & V_355 ) ;
if ( V_355 . V_368 != F_238 ( V_117 ) ||
V_350 != V_369 ) {
V_143 = ( T_3 ) - 1 ;
V_351 = V_353 ;
} else {
V_143 = V_355 . V_44 ;
V_351 = V_143 + 1 ;
}
F_239 ( V_357 ) ;
if ( V_143 < V_353 ) {
V_143 = ( T_3 ) - 1 ;
V_351 = V_353 ;
}
F_81 ( & F_116 ( V_117 ) -> V_152 , V_21 , V_21 + V_25 , 0 ,
& V_81 ) ;
V_197 = F_233 ( V_117 , V_21 , V_351 ,
V_251 ) ;
if ( ! V_197 )
goto V_89;
if ( F_243 ( V_197 ) ) {
V_58 = F_244 ( V_197 ) ;
goto V_89;
}
while ( ! V_22 ) {
T_3 V_370 ;
if ( V_197 -> V_21 >= F_108 || F_176 ( V_197 ) < V_349 )
break;
V_360 = F_108 ( V_197 -> V_21 , V_349 ) ;
V_370 = V_360 - V_197 -> V_21 ;
V_362 = F_176 ( V_197 ) ;
V_361 = V_362 - V_360 ;
V_363 = V_197 -> V_36 ;
V_352 = 0 ;
V_36 = 0 ;
V_349 = F_176 ( V_197 ) ;
if ( V_349 >= F_108 )
V_22 = 1 ;
if ( V_197 -> V_205 == V_371 ) {
V_22 = 1 ;
V_36 |= V_372 ;
} else if ( V_197 -> V_205 == V_271 ) {
V_36 |= ( V_373 |
V_374 ) ;
} else if ( V_197 -> V_205 == V_375 ) {
V_36 |= ( V_376 |
V_377 ) ;
} else {
V_352 = V_197 -> V_205 + V_370 ;
}
if ( F_129 ( V_206 , & V_197 -> V_36 ) )
V_36 |= V_378 ;
F_144 ( V_197 ) ;
V_197 = NULL ;
if ( ( V_360 >= V_143 ) || V_361 == ( T_3 ) - 1 ||
( V_143 == ( T_3 ) - 1 && V_353 <= V_362 ) ) {
V_36 |= V_372 ;
V_22 = 1 ;
}
V_197 = F_233 ( V_117 , V_349 , V_351 ,
V_251 ) ;
if ( F_243 ( V_197 ) ) {
V_58 = F_244 ( V_197 ) ;
goto V_89;
}
if ( ! V_197 ) {
V_36 |= V_372 ;
V_22 = 1 ;
}
V_58 = F_245 ( V_348 , V_360 , V_352 ,
V_361 , V_36 ) ;
if ( V_58 )
goto V_379;
}
V_379:
F_144 ( V_197 ) ;
V_89:
F_84 ( & F_116 ( V_117 ) -> V_152 , V_21 , V_21 + V_25 ,
& V_81 , V_106 ) ;
return V_58 ;
}
static void F_246 ( struct V_13 * V_16 )
{
#if V_35
unsigned long V_36 ;
F_19 ( & V_38 , V_36 ) ;
F_11 ( & V_16 -> V_19 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
if ( V_16 -> V_119 && V_16 -> V_119 != V_16 -> V_380 )
F_117 ( V_16 -> V_119 ) ;
F_12 ( V_12 , V_16 ) ;
}
static struct V_13 * F_247 ( struct V_2 * V_3 ,
T_3 V_21 ,
unsigned long V_25 ,
T_2 V_34 )
{
struct V_13 * V_16 = NULL ;
#if V_35
unsigned long V_36 ;
#endif
V_16 = F_248 ( V_12 , V_34 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_21 = V_21 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_307 = 0 ;
F_249 ( & V_16 -> V_32 ) ;
F_22 ( & V_16 -> V_381 , 0 ) ;
F_22 ( & V_16 -> V_382 , 0 ) ;
F_22 ( & V_16 -> V_383 , 0 ) ;
F_22 ( & V_16 -> V_384 , 0 ) ;
F_22 ( & V_16 -> V_385 , 0 ) ;
F_22 ( & V_16 -> V_386 , 0 ) ;
V_16 -> V_387 = 0 ;
F_23 ( & V_16 -> V_388 ) ;
F_23 ( & V_16 -> V_389 ) ;
#if V_35
F_19 ( & V_38 , V_36 ) ;
F_20 ( & V_16 -> V_19 , & V_24 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
F_16 ( & V_16 -> V_311 ) ;
F_22 ( & V_16 -> V_23 , 1 ) ;
F_22 ( & V_16 -> V_316 , 0 ) ;
if ( V_25 > V_390 ) {
struct V_110 * * V_119 ;
int V_188 = ( V_25 + V_131 - 1 ) >>
V_108 ;
V_119 = F_140 ( V_188 , V_34 ) ;
if ( ! V_119 ) {
F_246 ( V_16 ) ;
return NULL ;
}
V_16 -> V_119 = V_119 ;
} else {
V_16 -> V_119 = V_16 -> V_380 ;
}
return V_16 ;
}
struct V_13 * F_250 ( struct V_13 * V_391 )
{
unsigned long V_121 ;
struct V_110 * V_46 ;
struct V_13 * V_59 ;
unsigned long V_188 = F_134 ( V_391 -> V_21 , V_391 -> V_25 ) ;
V_59 = F_247 ( NULL , V_391 -> V_21 , V_391 -> V_25 , V_29 ) ;
if ( V_59 == NULL )
return NULL ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
V_46 = F_251 ( V_29 ) ;
F_55 ( ! V_46 ) ;
F_159 ( V_59 , V_46 ) ;
F_27 ( F_99 ( V_46 ) ) ;
F_112 ( V_46 ) ;
V_59 -> V_119 [ V_121 ] = V_46 ;
}
F_252 ( V_59 , V_391 , 0 , 0 , V_391 -> V_25 ) ;
F_196 ( V_392 , & V_59 -> V_307 ) ;
F_196 ( V_393 , & V_59 -> V_307 ) ;
return V_59 ;
}
struct V_13 * F_253 ( T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
unsigned long V_188 = F_134 ( 0 , V_25 ) ;
unsigned long V_121 ;
V_16 = F_247 ( NULL , V_21 , V_25 , V_29 ) ;
if ( ! V_16 )
return NULL ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
V_16 -> V_119 [ V_121 ] = F_251 ( V_29 ) ;
if ( ! V_16 -> V_119 [ V_121 ] )
goto V_79;
}
F_254 ( V_16 ) ;
F_255 ( V_16 , 0 ) ;
F_196 ( V_393 , & V_16 -> V_307 ) ;
return V_16 ;
V_79:
for (; V_121 > 0 ; V_121 -- )
F_256 ( V_16 -> V_119 [ V_121 - 1 ] ) ;
F_246 ( V_16 ) ;
return NULL ;
}
static int F_257 ( struct V_13 * V_16 )
{
return ( F_10 ( & V_16 -> V_316 ) ||
F_129 ( V_308 , & V_16 -> V_307 ) ||
F_129 ( V_312 , & V_16 -> V_307 ) ) ;
}
static void F_258 ( struct V_13 * V_16 ,
unsigned long V_394 )
{
unsigned long V_107 ;
unsigned long V_188 ;
struct V_110 * V_110 ;
int V_395 = ! F_129 ( V_393 , & V_16 -> V_307 ) ;
F_55 ( F_257 ( V_16 ) ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
V_107 = V_394 + V_188 ;
if ( V_394 >= V_107 )
return;
do {
V_107 -- ;
V_110 = F_135 ( V_16 , V_107 ) ;
if ( V_110 && V_395 ) {
F_53 ( & V_110 -> V_4 -> V_330 ) ;
if ( F_160 ( V_110 ) &&
V_110 -> V_37 == ( unsigned long ) V_16 ) {
F_55 ( F_129 ( V_312 , & V_16 -> V_307 ) ) ;
F_55 ( F_99 ( V_110 ) ) ;
F_55 ( F_185 ( V_110 ) ) ;
F_259 ( V_110 ) ;
F_163 ( V_110 , 0 ) ;
F_89 ( V_110 ) ;
}
F_57 ( & V_110 -> V_4 -> V_330 ) ;
}
if ( V_110 ) {
F_89 ( V_110 ) ;
}
} while ( V_107 != V_394 );
}
static inline void F_260 ( struct V_13 * V_16 )
{
F_258 ( V_16 , 0 ) ;
F_246 ( V_16 ) ;
}
static void F_261 ( struct V_13 * V_16 )
{
F_53 ( & V_16 -> V_311 ) ;
if ( ! F_262 ( V_396 , & V_16 -> V_307 ) )
F_65 ( & V_16 -> V_23 ) ;
F_57 ( & V_16 -> V_311 ) ;
}
static void F_263 ( struct V_13 * V_16 )
{
unsigned long V_188 , V_121 ;
F_261 ( V_16 ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
struct V_110 * V_46 = F_135 ( V_16 , V_121 ) ;
F_264 ( V_46 ) ;
}
}
struct V_13 * F_265 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
unsigned long V_188 = F_134 ( V_21 , V_25 ) ;
unsigned long V_121 ;
unsigned long V_107 = V_21 >> V_108 ;
struct V_13 * V_16 ;
struct V_13 * V_397 = NULL ;
struct V_110 * V_46 ;
struct V_26 * V_4 = V_3 -> V_4 ;
int V_215 = 1 ;
int V_58 ;
F_266 () ;
V_16 = F_267 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_212 ( & V_16 -> V_23 ) ) {
F_268 () ;
F_263 ( V_16 ) ;
return V_16 ;
}
F_268 () ;
V_16 = F_247 ( V_3 , V_21 , V_25 , V_106 ) ;
if ( ! V_16 )
return NULL ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ , V_107 ++ ) {
V_46 = F_269 ( V_4 , V_107 , V_106 ) ;
if ( ! V_46 )
goto V_398;
F_53 ( & V_4 -> V_330 ) ;
if ( F_160 ( V_46 ) ) {
V_397 = (struct V_13 * ) V_46 -> V_37 ;
if ( F_212 ( & V_397 -> V_23 ) ) {
F_57 ( & V_4 -> V_330 ) ;
F_96 ( V_46 ) ;
F_89 ( V_46 ) ;
F_263 ( V_397 ) ;
goto V_398;
}
F_259 ( V_46 ) ;
F_27 ( F_99 ( V_46 ) ) ;
F_89 ( V_46 ) ;
}
F_159 ( V_16 , V_46 ) ;
F_57 ( & V_4 -> V_330 ) ;
F_27 ( F_99 ( V_46 ) ) ;
F_264 ( V_46 ) ;
V_16 -> V_119 [ V_121 ] = V_46 ;
if ( ! F_167 ( V_46 ) )
V_215 = 0 ;
}
if ( V_215 )
F_196 ( V_392 , & V_16 -> V_307 ) ;
V_86:
V_58 = F_270 ( V_106 & ~ V_399 ) ;
if ( V_58 )
goto V_398;
F_53 ( & V_3 -> V_33 ) ;
V_58 = F_271 ( & V_3 -> V_28 , V_21 >> V_108 , V_16 ) ;
if ( V_58 == - V_69 ) {
V_397 = F_267 ( & V_3 -> V_28 ,
V_21 >> V_108 ) ;
if ( ! F_212 ( & V_397 -> V_23 ) ) {
F_57 ( & V_3 -> V_33 ) ;
F_272 () ;
V_397 = NULL ;
goto V_86;
}
F_57 ( & V_3 -> V_33 ) ;
F_272 () ;
F_263 ( V_397 ) ;
goto V_398;
}
F_261 ( V_16 ) ;
F_57 ( & V_3 -> V_33 ) ;
F_272 () ;
F_273 ( V_16 -> V_119 [ 0 ] ) ;
for ( V_121 = 1 ; V_121 < V_188 ; V_121 ++ ) {
V_46 = F_135 ( V_16 , V_121 ) ;
F_274 ( V_46 ) ;
F_96 ( V_46 ) ;
}
F_96 ( V_16 -> V_119 [ 0 ] ) ;
return V_16 ;
V_398:
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
if ( V_16 -> V_119 [ V_121 ] )
F_96 ( V_16 -> V_119 [ V_121 ] ) ;
}
F_27 ( ! F_26 ( & V_16 -> V_23 ) ) ;
F_260 ( V_16 ) ;
return V_397 ;
}
struct V_13 * F_275 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
F_266 () ;
V_16 = F_267 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_212 ( & V_16 -> V_23 ) ) {
F_268 () ;
F_263 ( V_16 ) ;
return V_16 ;
}
F_268 () ;
return NULL ;
}
static inline void F_276 ( struct V_400 * V_401 )
{
struct V_13 * V_16 =
F_277 ( V_401 , struct V_13 , V_400 ) ;
F_246 ( V_16 ) ;
}
static int F_278 ( struct V_13 * V_16 , T_2 V_34 )
{
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
if ( F_26 ( & V_16 -> V_23 ) ) {
if ( F_129 ( V_393 , & V_16 -> V_307 ) ) {
F_57 ( & V_16 -> V_311 ) ;
} else {
struct V_2 * V_3 = V_16 -> V_3 ;
F_57 ( & V_16 -> V_311 ) ;
F_53 ( & V_3 -> V_33 ) ;
F_279 ( & V_3 -> V_28 ,
V_16 -> V_21 >> V_108 ) ;
F_57 ( & V_3 -> V_33 ) ;
}
F_258 ( V_16 , 0 ) ;
F_280 ( & V_16 -> V_400 , F_276 ) ;
return 1 ;
}
F_57 ( & V_16 -> V_311 ) ;
return 0 ;
}
void F_213 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_53 ( & V_16 -> V_311 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_129 ( V_393 , & V_16 -> V_307 ) )
F_54 ( & V_16 -> V_23 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_129 ( V_402 , & V_16 -> V_307 ) &&
! F_257 ( V_16 ) &&
F_195 ( V_396 , & V_16 -> V_307 ) )
F_54 ( & V_16 -> V_23 ) ;
F_278 ( V_16 , V_29 ) ;
}
void F_281 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_53 ( & V_16 -> V_311 ) ;
F_196 ( V_402 , & V_16 -> V_307 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 && ! F_257 ( V_16 ) &&
F_195 ( V_396 , & V_16 -> V_307 ) )
F_54 ( & V_16 -> V_23 ) ;
F_278 ( V_16 , V_106 ) ;
}
void F_282 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
unsigned long V_188 ;
struct V_110 * V_110 ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
if ( ! F_99 ( V_110 ) )
continue;
F_98 ( V_110 ) ;
F_27 ( ! F_160 ( V_110 ) ) ;
F_104 ( V_110 ) ;
F_283 ( & V_110 -> V_4 -> V_403 ) ;
if ( ! F_99 ( V_110 ) ) {
F_284 ( & V_110 -> V_4 -> V_404 ,
F_285 ( V_110 ) ,
V_327 ) ;
}
F_286 ( & V_110 -> V_4 -> V_403 ) ;
F_183 ( V_110 ) ;
F_96 ( V_110 ) ;
}
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
}
int F_287 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
unsigned long V_188 ;
int V_405 = 0 ;
F_261 ( V_16 ) ;
V_405 = F_262 ( V_312 , & V_16 -> V_307 ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
F_27 ( ! F_129 ( V_396 , & V_16 -> V_307 ) ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ )
F_288 ( F_135 ( V_16 , V_121 ) ) ;
return V_405 ;
}
static int F_289 ( T_3 V_21 , T_3 V_25 )
{
if ( V_25 < V_131 )
return 1 ;
if ( V_21 & ( V_131 - 1 ) )
return 1 ;
if ( ( V_21 + V_25 ) & ( V_131 - 1 ) )
return 1 ;
return 0 ;
}
int F_290 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
struct V_110 * V_110 ;
unsigned long V_188 ;
F_200 ( V_392 , & V_16 -> V_307 ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
if ( V_110 )
F_147 ( V_110 ) ;
}
return 0 ;
}
int F_254 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
struct V_110 * V_110 ;
unsigned long V_188 ;
F_196 ( V_392 , & V_16 -> V_307 ) ;
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
F_112 ( V_110 ) ;
}
return 0 ;
}
int F_291 ( struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 )
{
struct V_110 * V_110 ;
int V_58 ;
int V_406 = 1 ;
int V_215 ;
unsigned long V_107 ;
if ( F_289 ( V_21 , V_22 - V_21 + 1 ) ) {
V_58 = F_101 ( V_3 , V_21 , V_22 ,
V_101 , 1 , NULL ) ;
if ( V_58 )
return 1 ;
}
while ( V_21 <= V_22 ) {
V_107 = V_21 >> V_108 ;
V_110 = F_87 ( V_3 -> V_4 , V_107 ) ;
if ( ! V_110 )
return 1 ;
V_215 = F_167 ( V_110 ) ;
F_89 ( V_110 ) ;
if ( ! V_215 ) {
V_406 = 0 ;
break;
}
V_21 += V_131 ;
}
return V_406 ;
}
int F_292 ( struct V_13 * V_16 )
{
return F_129 ( V_392 , & V_16 -> V_307 ) ;
}
int F_293 ( struct V_2 * V_3 ,
struct V_13 * V_16 , T_3 V_21 , int V_91 ,
T_9 * V_251 , int V_160 )
{
unsigned long V_121 ;
unsigned long V_407 ;
struct V_110 * V_110 ;
int V_79 ;
int V_58 = 0 ;
int V_408 = 0 ;
int V_409 = 1 ;
unsigned long V_188 ;
unsigned long V_410 = 0 ;
struct V_154 * V_154 = NULL ;
unsigned long V_204 = 0 ;
if ( F_129 ( V_392 , & V_16 -> V_307 ) )
return 0 ;
if ( V_21 ) {
F_27 ( V_21 < V_16 -> V_21 ) ;
V_407 = ( V_21 >> V_108 ) -
( V_16 -> V_21 >> V_108 ) ;
} else {
V_407 = 0 ;
}
V_188 = F_134 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = V_407 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
if ( V_91 == V_411 ) {
if ( ! F_198 ( V_110 ) )
goto V_412;
} else {
F_98 ( V_110 ) ;
}
V_408 ++ ;
if ( ! F_167 ( V_110 ) ) {
V_410 ++ ;
V_409 = 0 ;
}
}
if ( V_409 ) {
if ( V_407 == 0 )
F_196 ( V_392 , & V_16 -> V_307 ) ;
goto V_412;
}
F_200 ( V_317 , & V_16 -> V_307 ) ;
V_16 -> V_413 = 0 ;
F_22 ( & V_16 -> V_316 , V_410 ) ;
for ( V_121 = V_407 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
if ( ! F_167 ( V_110 ) ) {
F_183 ( V_110 ) ;
V_79 = F_165 ( V_3 , V_110 ,
V_251 , & V_154 ,
V_160 , & V_204 ) ;
if ( V_79 )
V_58 = V_79 ;
} else {
F_96 ( V_110 ) ;
}
}
if ( V_154 ) {
V_79 = F_153 ( V_274 , V_154 , V_160 , V_204 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_58 || V_91 != V_414 )
return V_58 ;
for ( V_121 = V_407 ; V_121 < V_188 ; V_121 ++ ) {
V_110 = F_135 ( V_16 , V_121 ) ;
F_294 ( V_110 ) ;
if ( ! F_167 ( V_110 ) )
V_58 = - V_168 ;
}
return V_58 ;
V_412:
V_121 = V_407 ;
while ( V_408 > 0 ) {
V_110 = F_135 ( V_16 , V_121 ) ;
V_121 ++ ;
F_96 ( V_110 ) ;
V_408 -- ;
}
return V_58 ;
}
void F_295 ( struct V_13 * V_16 , void * V_415 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_416 ;
char * V_417 = ( char * ) V_415 ;
T_6 V_418 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_418 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_135 ( V_16 , V_121 ) ;
V_253 = F_107 ( V_25 , ( V_131 - V_44 ) ) ;
V_416 = F_296 ( V_110 ) ;
memcpy ( V_417 , V_416 + V_44 , V_253 ) ;
V_417 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_121 ++ ;
}
}
int F_297 ( struct V_13 * V_16 , unsigned long V_21 ,
unsigned long V_419 , char * * V_341 ,
unsigned long * V_420 ,
unsigned long * V_421 )
{
T_6 V_44 = V_21 & ( V_131 - 1 ) ;
char * V_416 ;
struct V_110 * V_46 ;
T_6 V_418 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_21 ) >> V_108 ;
unsigned long V_422 = ( V_418 + V_21 + V_419 - 1 ) >>
V_108 ;
if ( V_121 != V_422 )
return - V_364 ;
if ( V_121 == 0 ) {
V_44 = V_418 ;
* V_420 = 0 ;
} else {
V_44 = 0 ;
* V_420 = ( ( T_3 ) V_121 << V_108 ) - V_418 ;
}
if ( V_21 + V_419 > V_16 -> V_25 ) {
F_9 ( V_20 L_31
L_32 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , V_21 , V_419 ) ;
F_27 ( 1 ) ;
return - V_364 ;
}
V_46 = F_135 ( V_16 , V_121 ) ;
V_416 = F_296 ( V_46 ) ;
* V_341 = V_416 + V_44 ;
* V_421 = V_131 - V_44 ;
return 0 ;
}
int F_298 ( struct V_13 * V_16 , const void * V_423 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_416 ;
char * V_424 = ( char * ) V_423 ;
T_6 V_418 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_21 ) >> V_108 ;
int V_58 = 0 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_418 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_135 ( V_16 , V_121 ) ;
V_253 = F_107 ( V_25 , ( V_131 - V_44 ) ) ;
V_416 = F_296 ( V_110 ) ;
V_58 = memcmp ( V_424 , V_416 + V_44 , V_253 ) ;
if ( V_58 )
break;
V_424 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_121 ++ ;
}
return V_58 ;
}
void F_299 ( struct V_13 * V_16 , const void * V_425 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_416 ;
char * V_391 = ( char * ) V_425 ;
T_6 V_418 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_418 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_135 ( V_16 , V_121 ) ;
F_27 ( ! F_167 ( V_110 ) ) ;
V_253 = F_107 ( V_25 , V_131 - V_44 ) ;
V_416 = F_296 ( V_110 ) ;
memcpy ( V_416 + V_44 , V_391 , V_253 ) ;
V_391 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_121 ++ ;
}
}
void F_300 ( struct V_13 * V_16 , char V_426 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_416 ;
T_6 V_418 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_418 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_135 ( V_16 , V_121 ) ;
F_27 ( ! F_167 ( V_110 ) ) ;
V_253 = F_107 ( V_25 , V_131 - V_44 ) ;
V_416 = F_296 ( V_110 ) ;
memset ( V_416 + V_44 , V_426 , V_253 ) ;
V_25 -= V_253 ;
V_44 = 0 ;
V_121 ++ ;
}
}
void F_252 ( struct V_13 * V_417 , struct V_13 * V_391 ,
unsigned long V_427 , unsigned long V_428 ,
unsigned long V_25 )
{
T_3 V_429 = V_417 -> V_25 ;
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_416 ;
T_6 V_418 = V_417 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_418 + V_427 ) >> V_108 ;
F_27 ( V_391 -> V_25 != V_429 ) ;
V_44 = ( V_418 + V_427 ) &
( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_135 ( V_417 , V_121 ) ;
F_27 ( ! F_167 ( V_110 ) ) ;
V_253 = F_107 ( V_25 , ( unsigned long ) ( V_131 - V_44 ) ) ;
V_416 = F_296 ( V_110 ) ;
F_295 ( V_391 , V_416 + V_44 , V_428 , V_253 ) ;
V_428 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_121 ++ ;
}
}
static void F_301 ( struct V_110 * V_430 , struct V_110 * V_431 ,
unsigned long V_432 , unsigned long V_433 ,
unsigned long V_25 )
{
char * V_434 = F_296 ( V_430 ) ;
if ( V_430 == V_431 ) {
memmove ( V_434 + V_432 , V_434 + V_433 , V_25 ) ;
} else {
char * V_435 = F_296 ( V_431 ) ;
char * V_46 = V_434 + V_432 + V_25 ;
char * V_436 = V_435 + V_433 + V_25 ;
while ( V_25 -- )
* -- V_46 = * -- V_436 ;
}
}
static inline bool F_302 ( unsigned long V_391 , unsigned long V_417 , unsigned long V_25 )
{
unsigned long V_437 = ( V_391 > V_417 ) ? V_391 - V_417 : V_417 - V_391 ;
return V_437 < V_25 ;
}
static void F_303 ( struct V_110 * V_430 , struct V_110 * V_431 ,
unsigned long V_432 , unsigned long V_433 ,
unsigned long V_25 )
{
char * V_434 = F_296 ( V_430 ) ;
char * V_435 ;
int V_438 = 0 ;
if ( V_430 != V_431 ) {
V_435 = F_296 ( V_431 ) ;
} else {
V_435 = V_434 ;
if ( F_302 ( V_433 , V_432 , V_25 ) )
V_438 = 1 ;
}
if ( V_438 )
memmove ( V_434 + V_432 , V_435 + V_433 , V_25 ) ;
else
memcpy ( V_434 + V_432 , V_435 + V_433 , V_25 ) ;
}
void F_304 ( struct V_13 * V_417 , unsigned long V_427 ,
unsigned long V_428 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_439 ;
T_6 V_440 ;
T_6 V_418 = V_417 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_441 ;
unsigned long V_442 ;
if ( V_428 + V_25 > V_417 -> V_25 ) {
F_9 ( V_20 L_33
L_34 , V_428 , V_25 , V_417 -> V_25 ) ;
F_55 ( 1 ) ;
}
if ( V_427 + V_25 > V_417 -> V_25 ) {
F_9 ( V_20 L_35
L_34 , V_427 , V_25 , V_417 -> V_25 ) ;
F_55 ( 1 ) ;
}
while ( V_25 > 0 ) {
V_439 = ( V_418 + V_427 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_440 = ( V_418 + V_428 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_441 = ( V_418 + V_427 ) >> V_108 ;
V_442 = ( V_418 + V_428 ) >> V_108 ;
V_253 = F_107 ( V_25 , ( unsigned long ) ( V_131 -
V_440 ) ) ;
V_253 = F_95 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_303 ( F_135 ( V_417 , V_441 ) ,
F_135 ( V_417 , V_442 ) ,
V_439 , V_440 , V_253 ) ;
V_428 += V_253 ;
V_427 += V_253 ;
V_25 -= V_253 ;
}
}
void F_305 ( struct V_13 * V_417 , unsigned long V_427 ,
unsigned long V_428 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_439 ;
T_6 V_440 ;
unsigned long V_443 = V_427 + V_25 - 1 ;
unsigned long V_444 = V_428 + V_25 - 1 ;
T_6 V_418 = V_417 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_441 ;
unsigned long V_442 ;
if ( V_428 + V_25 > V_417 -> V_25 ) {
F_9 ( V_20 L_33
L_36 , V_428 , V_25 , V_417 -> V_25 ) ;
F_55 ( 1 ) ;
}
if ( V_427 + V_25 > V_417 -> V_25 ) {
F_9 ( V_20 L_35
L_36 , V_427 , V_25 , V_417 -> V_25 ) ;
F_55 ( 1 ) ;
}
if ( V_427 < V_428 ) {
F_304 ( V_417 , V_427 , V_428 , V_25 ) ;
return;
}
while ( V_25 > 0 ) {
V_441 = ( V_418 + V_443 ) >> V_108 ;
V_442 = ( V_418 + V_444 ) >> V_108 ;
V_439 = ( V_418 + V_443 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_440 = ( V_418 + V_444 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_253 = F_95 (unsigned long, len, src_off_in_page + 1 ) ;
V_253 = F_107 ( V_253 , V_439 + 1 ) ;
F_301 ( F_135 ( V_417 , V_441 ) ,
F_135 ( V_417 , V_442 ) ,
V_439 - V_253 + 1 ,
V_440 - V_253 + 1 , V_253 ) ;
V_443 -= V_253 ;
V_444 -= V_253 ;
V_25 -= V_253 ;
}
}
int F_306 ( struct V_110 * V_110 , T_2 V_34 )
{
struct V_13 * V_16 ;
F_53 ( & V_110 -> V_4 -> V_330 ) ;
if ( ! F_160 ( V_110 ) ) {
F_57 ( & V_110 -> V_4 -> V_330 ) ;
return 1 ;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_55 ( ! V_16 ) ;
F_53 ( & V_16 -> V_311 ) ;
if ( F_10 ( & V_16 -> V_23 ) != 1 || F_257 ( V_16 ) ) {
F_57 ( & V_16 -> V_311 ) ;
F_57 ( & V_110 -> V_4 -> V_330 ) ;
return 0 ;
}
F_57 ( & V_110 -> V_4 -> V_330 ) ;
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
if ( ! F_195 ( V_396 , & V_16 -> V_307 ) ) {
F_57 ( & V_16 -> V_311 ) ;
return 0 ;
}
return F_278 ( V_16 , V_34 ) ;
}
