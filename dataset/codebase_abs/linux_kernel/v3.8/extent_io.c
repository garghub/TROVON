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
if ( V_22 < V_21 )
F_43 ( 1 , V_20 L_7 ,
( unsigned long long ) V_22 ,
( unsigned long long ) V_21 ) ;
V_15 -> V_21 = V_21 ;
V_15 -> V_22 = V_22 ;
F_44 ( V_3 , V_15 , V_65 ) ;
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
static void F_45 ( struct V_2 * V_3 , struct V_8 * V_70 ,
T_3 V_71 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_72 )
V_3 -> V_30 -> V_72 ( V_3 -> V_4 -> V_5 , V_70 , V_71 ) ;
}
static int F_46 ( struct V_2 * V_3 , struct V_8 * V_70 ,
struct V_8 * V_73 , T_3 V_71 )
{
struct V_41 * V_45 ;
F_45 ( V_3 , V_70 , V_71 ) ;
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
static struct V_8 * F_47 ( struct V_8 * V_15 )
{
struct V_41 * V_18 = F_34 ( & V_15 -> V_41 ) ;
if ( V_18 )
return F_30 ( V_18 , struct V_8 , V_41 ) ;
else
return NULL ;
}
static struct V_8 * F_48 ( struct V_2 * V_3 ,
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
F_49 ( & V_15 -> V_39 ) ;
if ( V_15 -> V_15 == 0 ) {
V_18 = F_47 ( V_15 ) ;
if ( V_15 -> V_3 ) {
F_39 ( & V_15 -> V_41 , & V_3 -> V_15 ) ;
V_15 -> V_3 = NULL ;
F_25 ( V_15 ) ;
} else {
F_27 ( 1 ) ;
}
} else {
F_38 ( V_3 , V_15 ) ;
V_18 = F_47 ( V_15 ) ;
}
return V_18 ;
}
static struct V_8 *
F_50 ( struct V_8 * V_73 )
{
if ( ! V_73 )
V_73 = F_17 ( V_29 ) ;
return V_73 ;
}
void F_51 ( struct V_2 * V_3 , int V_79 )
{
F_52 ( F_1 ( V_3 ) , V_79 , L_10
L_11
L_12 ) ;
}
int F_53 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
F_54 ( & V_3 -> V_32 ) ;
if ( V_81 ) {
V_82 = * V_81 ;
if ( V_84 ) {
* V_81 = NULL ;
V_81 = NULL ;
}
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 ) {
if ( V_84 )
F_55 ( & V_82 -> V_23 ) ;
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
V_15 = F_47 ( V_15 ) ;
goto V_18;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_46 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
V_15 = F_48 ( V_3 , V_15 , & V_65 , V_74 ) ;
goto V_18;
}
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_46 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
if ( V_74 )
F_49 ( & V_15 -> V_39 ) ;
F_48 ( V_3 , V_73 , & V_65 , V_74 ) ;
V_73 = NULL ;
goto V_89;
}
V_15 = F_48 ( V_3 , V_15 , & V_65 , V_74 ) ;
V_18:
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 <= V_22 && V_15 && ! F_57 () )
goto V_88;
goto V_90;
V_89:
F_58 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return 0 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_58 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_59 () ;
goto V_86;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_8 * V_15 )
__releases( V_3 -> V_32 )
__acquires( V_3 -> V_32 )
{
F_61 ( V_91 ) ;
F_62 ( & V_15 -> V_39 , & V_91 , V_92 ) ;
F_58 ( & V_3 -> V_32 ) ;
F_63 () ;
F_54 ( & V_3 -> V_32 ) ;
F_64 ( & V_15 -> V_39 , & V_91 ) ;
}
void F_65 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 )
{
struct V_8 * V_15 ;
struct V_41 * V_45 ;
F_54 ( & V_3 -> V_32 ) ;
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
F_66 ( & V_15 -> V_23 ) ;
F_60 ( V_3 , V_15 ) ;
F_25 ( V_15 ) ;
goto V_86;
}
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
F_67 ( & V_3 -> V_32 ) ;
}
V_89:
F_58 ( & V_3 -> V_32 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
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
static void F_68 ( struct V_8 * V_15 ,
struct V_8 * * V_94 )
{
if ( V_94 && ! ( * V_94 ) ) {
if ( V_15 -> V_15 & ( V_63 | V_64 ) ) {
* V_94 = V_15 ;
F_66 ( & V_15 -> V_23 ) ;
}
}
}
static void F_69 ( struct V_8 * * V_94 )
{
if ( V_94 && ( * V_94 ) ) {
struct V_8 * V_15 = * V_94 ;
* V_94 = NULL ;
F_25 ( V_15 ) ;
}
}
static int T_4
F_70 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
F_56 ( ! V_73 ) ;
}
F_54 ( & V_3 -> V_32 ) ;
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
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_42 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
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
F_44 ( V_3 , V_15 , & V_65 ) ;
F_68 ( V_15 , V_81 ) ;
F_38 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_15 = F_47 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_57 () )
goto V_88;
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_21 ;
V_79 = - V_69 ;
goto V_89;
}
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_46 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_44 ( V_3 , V_15 , & V_65 ) ;
F_68 ( V_15 , V_81 ) ;
F_38 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_15 = F_47 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_57 () )
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
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_42 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
F_68 ( V_73 , V_81 ) ;
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
V_73 = F_50 ( V_73 ) ;
F_56 ( ! V_73 ) ;
V_79 = F_46 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
F_44 ( V_3 , V_73 , & V_65 ) ;
F_68 ( V_73 , V_81 ) ;
F_38 ( V_3 , V_73 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_58 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_58 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_59 () ;
goto V_86;
}
int F_71 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 ,
T_3 * V_96 , struct V_8 * * V_81 ,
T_2 V_34 )
{
return F_70 ( V_3 , V_21 , V_22 , V_65 , 0 , V_96 ,
V_81 , V_34 ) ;
}
int F_72 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
F_54 ( & V_3 -> V_32 ) ;
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
V_73 = F_50 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_42 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
V_73 = NULL ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
goto V_89;
}
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
V_88:
V_97 = V_15 -> V_21 ;
V_83 = V_15 -> V_22 ;
if ( V_15 -> V_21 == V_21 && V_15 -> V_22 <= V_22 ) {
F_44 ( V_3 , V_15 , & V_65 ) ;
F_68 ( V_15 , V_81 ) ;
V_15 = F_48 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_57 () )
goto V_88;
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_50 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_46 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_44 ( V_3 , V_15 , & V_65 ) ;
F_68 ( V_15 , V_81 ) ;
V_15 = F_48 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_57 () )
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
V_73 = F_50 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_42 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
F_68 ( V_73 , V_81 ) ;
V_73 = NULL ;
V_21 = V_98 + 1 ;
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_50 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_46 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_51 ( V_3 , V_79 ) ;
F_44 ( V_3 , V_73 , & V_65 ) ;
F_68 ( V_73 , V_81 ) ;
F_48 ( V_3 , V_73 , & V_99 , 0 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_58 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_58 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_59 () ;
goto V_86;
}
int F_73 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 , V_77 , NULL ,
NULL , V_34 ) ;
}
int F_74 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 , V_65 , NULL ,
NULL , V_34 ) ;
}
int F_75 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_53 ( V_3 , V_21 , V_22 , V_65 , 0 , 0 , NULL , V_34 ) ;
}
int F_76 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 ,
V_100 | V_101 ,
NULL , V_81 , V_34 ) ;
}
int F_77 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 ,
V_100 | V_101 | V_102 ,
NULL , V_81 , V_34 ) ;
}
int F_78 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_53 ( V_3 , V_21 , V_22 ,
V_77 | V_100 |
V_103 , 0 , 0 , NULL , V_34 ) ;
}
int F_79 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 , V_104 , NULL ,
NULL , V_34 ) ;
}
int F_80 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_71 ( V_3 , V_21 , V_22 , V_101 , 0 ,
V_81 , V_34 ) ;
}
int F_81 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_53 ( V_3 , V_21 , V_22 , V_101 , 0 , 0 ,
V_81 , V_34 ) ;
}
int F_82 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , struct V_8 * * V_81 )
{
int V_79 ;
T_3 V_96 ;
while ( 1 ) {
V_79 = F_70 ( V_3 , V_21 , V_22 , V_105 | V_65 ,
V_105 , & V_96 ,
V_81 , V_106 ) ;
if ( V_79 == - V_69 ) {
F_65 ( V_3 , V_96 , V_22 , V_105 ) ;
V_21 = V_96 ;
} else
break;
F_27 ( V_21 > V_22 ) ;
}
return V_79 ;
}
int F_83 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_82 ( V_3 , V_21 , V_22 , 0 , NULL ) ;
}
int F_84 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
int V_79 ;
T_3 V_96 ;
V_79 = F_70 ( V_3 , V_21 , V_22 , V_105 , V_105 ,
& V_96 , NULL , V_106 ) ;
if ( V_79 == - V_69 ) {
if ( V_96 > V_21 )
F_53 ( V_3 , V_21 , V_96 - 1 ,
V_105 , 1 , 0 , NULL , V_106 ) ;
return 0 ;
}
return 1 ;
}
int F_85 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_82 , T_2 V_34 )
{
return F_53 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , V_82 ,
V_34 ) ;
}
int F_86 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_53 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , NULL ,
V_106 ) ;
}
static int F_87 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
struct V_110 * V_110 ;
while ( V_107 <= V_109 ) {
V_110 = F_88 ( V_3 -> V_4 , V_107 ) ;
F_56 ( ! V_110 ) ;
F_89 ( V_110 ) ;
F_90 ( V_110 ) ;
V_107 ++ ;
}
return 0 ;
}
struct V_8 * F_91 ( struct V_2 * V_3 ,
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
int F_92 ( struct V_2 * V_3 , T_3 V_21 ,
T_3 * V_111 , T_3 * V_112 , int V_65 ,
struct V_8 * * V_81 )
{
struct V_8 * V_15 ;
struct V_41 * V_54 ;
int V_58 = 1 ;
F_54 ( & V_3 -> V_32 ) ;
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
V_15 = F_91 ( V_3 , V_21 , V_65 ) ;
V_113:
if ( V_15 ) {
F_68 ( V_15 , V_81 ) ;
* V_111 = V_15 -> V_21 ;
* V_112 = V_15 -> V_22 ;
V_58 = 0 ;
}
V_89:
F_58 ( & V_3 -> V_32 ) ;
return V_58 ;
}
static T_5 T_3 F_93 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 * V_22 , T_3 V_114 ,
struct V_8 * * V_81 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_115 = * V_21 ;
T_3 V_68 = 0 ;
T_3 V_116 = 0 ;
F_54 ( & V_3 -> V_32 ) ;
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
F_66 ( & V_15 -> V_23 ) ;
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
F_58 ( & V_3 -> V_32 ) ;
return V_68 ;
}
static T_5 void F_94 ( struct V_117 * V_117 ,
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
V_58 = F_95 ( V_117 -> V_122 , V_107 ,
F_96 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_119 ) ;
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_119 [ V_121 ] != V_118 )
F_97 ( V_119 [ V_121 ] ) ;
F_90 ( V_119 [ V_121 ] ) ;
}
V_120 -= V_58 ;
V_107 += V_58 ;
F_59 () ;
}
}
static T_5 int F_98 ( struct V_117 * V_117 ,
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
V_58 = F_95 ( V_117 -> V_122 , V_107 ,
F_96 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_119 ) ;
if ( V_58 == 0 ) {
V_58 = - V_128 ;
goto V_129;
}
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_119 [ V_121 ] != V_118 ) {
F_99 ( V_119 [ V_121 ] ) ;
if ( ! F_100 ( V_119 [ V_121 ] ) ||
V_119 [ V_121 ] -> V_4 != V_117 -> V_122 ) {
V_58 = - V_128 ;
F_97 ( V_119 [ V_121 ] ) ;
F_90 ( V_119 [ V_121 ] ) ;
goto V_129;
}
}
F_90 ( V_119 [ V_121 ] ) ;
V_126 ++ ;
}
V_127 -= V_58 ;
V_107 += V_58 ;
F_59 () ;
}
V_58 = 0 ;
V_129:
if ( V_58 && V_126 ) {
F_94 ( V_117 , V_118 ,
V_123 ,
( ( T_3 ) ( V_125 + V_126 - 1 ) ) <<
V_108 ) ;
}
return V_58 ;
}
static T_5 T_3 F_101 ( struct V_117 * V_117 ,
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
V_68 = F_93 ( V_3 , & V_123 , & V_124 ,
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
V_58 = F_98 ( V_117 , V_118 ,
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
F_56 ( V_58 ) ;
F_82 ( V_3 , V_123 , V_124 , 0 , & V_81 ) ;
V_58 = F_102 ( V_3 , V_123 , V_124 ,
V_100 , 1 , V_81 ) ;
if ( ! V_58 ) {
F_85 ( V_3 , V_123 , V_124 ,
& V_81 , V_106 ) ;
F_94 ( V_117 , V_118 ,
V_123 , V_124 ) ;
F_59 () ;
goto V_86;
}
F_25 ( V_81 ) ;
* V_21 = V_123 ;
* V_22 = V_124 ;
V_132:
return V_68 ;
}
int F_103 ( struct V_117 * V_117 ,
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
F_53 ( V_3 , V_21 , V_22 , V_99 , 1 , 0 , NULL , V_106 ) ;
if ( ! ( V_133 & ( V_137 | V_135 |
V_138 | V_139 |
V_140 ) ) )
return 0 ;
while ( V_120 > 0 ) {
V_58 = F_95 ( V_117 -> V_122 , V_107 ,
F_96 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_119 ) ;
for ( V_121 = 0 ; V_121 < V_58 ; V_121 ++ ) {
if ( V_133 & V_140 )
F_104 ( V_119 [ V_121 ] ) ;
if ( V_119 [ V_121 ] == V_118 ) {
F_90 ( V_119 [ V_121 ] ) ;
continue;
}
if ( V_133 & V_135 )
F_105 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_138 )
F_89 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_139 )
F_106 ( V_119 [ V_121 ] ) ;
if ( V_133 & V_137 )
F_97 ( V_119 [ V_121 ] ) ;
F_90 ( V_119 [ V_121 ] ) ;
}
V_120 -= V_58 ;
V_107 += V_58 ;
F_59 () ;
}
return 0 ;
}
T_3 F_107 ( struct V_2 * V_3 ,
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
F_54 ( & V_3 -> V_32 ) ;
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
V_116 += F_108 ( V_141 , V_15 -> V_22 ) + 1 -
F_109 ( V_115 , V_15 -> V_21 ) ;
if ( V_116 >= V_114 )
break;
if ( ! V_68 ) {
* V_21 = F_109 ( V_115 , V_15 -> V_21 ) ;
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
F_58 ( & V_3 -> V_32 ) ;
return V_116 ;
}
int F_110 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_54 ( & V_3 -> V_32 ) ;
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
F_58 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_111 ( struct V_2 * V_3 , T_3 V_21 , T_3 * V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_54 ( & V_3 -> V_32 ) ;
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
F_58 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_102 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_145 , struct V_8 * V_82 )
{
struct V_8 * V_15 = NULL ;
struct V_41 * V_45 ;
int V_146 = 0 ;
F_54 ( & V_3 -> V_32 ) ;
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
F_58 ( & V_3 -> V_32 ) ;
return V_146 ;
}
static void F_112 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( F_102 ( V_3 , V_21 , V_22 , V_101 , 1 , NULL ) )
F_113 ( V_110 ) ;
}
static void F_114 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ! F_102 ( V_3 , V_21 , V_22 , V_105 , 0 , NULL ) )
F_97 ( V_110 ) ;
}
static void F_115 ( struct V_2 * V_3 ,
struct V_110 * V_110 )
{
F_106 ( V_110 ) ;
}
static int F_116 ( struct V_117 * V_117 , struct V_147 * V_148 ,
int V_149 )
{
int V_58 ;
int V_79 = 0 ;
struct V_2 * V_150 = & F_117 ( V_117 ) -> V_151 ;
F_110 ( V_150 , V_148 -> V_21 , 0 ) ;
V_58 = F_75 ( V_150 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 )
V_79 = V_58 ;
if ( V_149 ) {
V_58 = F_75 ( & F_117 ( V_117 ) -> V_152 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_153 , V_106 ) ;
if ( V_58 && ! V_79 )
V_79 = V_58 ;
}
F_118 ( V_148 ) ;
return V_79 ;
}
static void F_119 ( struct V_154 * V_154 , int V_79 )
{
F_120 ( V_154 -> V_155 ) ;
}
int F_121 ( struct V_1 * V_156 , T_3 V_21 ,
T_3 V_157 , T_3 V_158 , struct V_110 * V_110 ,
int V_159 )
{
struct V_154 * V_154 ;
struct V_160 * V_161 ;
F_122 ( V_162 ) ;
T_3 V_163 = 0 ;
T_3 V_164 ;
struct V_165 * V_166 = NULL ;
int V_58 ;
F_56 ( ! V_159 ) ;
V_154 = F_123 ( V_106 , 1 ) ;
if ( ! V_154 )
return - V_167 ;
V_154 -> V_155 = & V_162 ;
V_154 -> V_168 = F_119 ;
V_154 -> V_169 = 0 ;
V_163 = V_157 ;
V_58 = F_124 ( V_156 , V_170 , V_158 ,
& V_163 , & V_166 , V_159 ) ;
if ( V_58 ) {
F_125 ( V_154 ) ;
return - V_167 ;
}
F_56 ( V_159 != V_166 -> V_159 ) ;
V_164 = V_166 -> V_171 [ V_159 - 1 ] . V_172 >> 9 ;
V_154 -> V_173 = V_164 ;
V_161 = V_166 -> V_171 [ V_159 - 1 ] . V_161 ;
F_118 ( V_166 ) ;
if ( ! V_161 || ! V_161 -> V_174 || ! V_161 -> V_175 ) {
F_125 ( V_154 ) ;
return - V_167 ;
}
V_154 -> V_176 = V_161 -> V_174 ;
F_126 ( V_154 , V_110 , V_157 , V_21 - F_127 ( V_110 ) ) ;
F_128 ( V_177 , V_154 ) ;
F_129 ( & V_162 ) ;
if ( ! F_130 ( V_178 , & V_154 -> V_179 ) ) {
F_125 ( V_154 ) ;
F_131 ( V_161 , V_180 ) ;
return - V_167 ;
}
F_132 ( V_181 L_13
L_14 , V_110 -> V_4 -> V_5 -> V_182 ,
V_21 , F_133 ( V_161 -> V_183 ) , V_164 ) ;
F_125 ( V_154 ) ;
return 0 ;
}
int F_134 ( struct V_184 * V_43 , struct V_13 * V_16 ,
int V_159 )
{
T_3 V_21 = V_16 -> V_21 ;
unsigned long V_121 , V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
int V_58 = 0 ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
struct V_110 * V_46 = F_136 ( V_16 , V_121 ) ;
V_58 = F_121 ( V_43 -> V_156 , V_21 , V_131 ,
V_21 , V_46 , V_159 ) ;
if ( V_58 )
break;
V_21 += V_131 ;
}
return V_58 ;
}
static int F_137 ( T_3 V_21 , struct V_110 * V_110 )
{
T_3 V_37 ;
T_3 V_186 ;
struct V_147 * V_187 ;
struct V_1 * V_156 ;
struct V_8 * V_15 ;
int V_188 ;
int V_149 = 0 ;
int V_58 ;
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
V_37 = 0 ;
V_58 = F_107 ( & F_117 ( V_117 ) -> V_151 , & V_37 ,
( T_3 ) - 1 , 1 , V_77 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_58 = F_111 ( & F_117 ( V_117 ) -> V_151 , V_21 ,
& V_186 ) ;
if ( V_58 )
return 0 ;
V_187 = (struct V_147 * ) ( unsigned long ) V_186 ;
F_56 ( ! V_187 -> V_189 ) ;
if ( V_187 -> V_190 ) {
F_138 ( L_15 ,
V_187 -> V_21 ) ;
V_149 = 1 ;
goto V_89;
}
F_54 ( & F_117 ( V_117 ) -> V_152 . V_32 ) ;
V_15 = F_91 ( & F_117 ( V_117 ) -> V_152 ,
V_187 -> V_21 ,
V_105 ) ;
F_58 ( & F_117 ( V_117 ) -> V_152 . V_32 ) ;
if ( V_15 && V_15 -> V_21 == V_187 -> V_21 ) {
V_156 = F_117 ( V_117 ) -> V_43 -> V_156 ;
V_188 = F_139 ( V_156 , V_187 -> V_158 ,
V_187 -> V_25 ) ;
if ( V_188 > 1 ) {
V_58 = F_121 ( V_156 , V_21 , V_187 -> V_25 ,
V_187 -> V_158 , V_110 ,
V_187 -> V_191 ) ;
V_149 = ! V_58 ;
}
}
V_89:
if ( ! V_58 )
V_58 = F_116 ( V_117 , V_187 , V_149 ) ;
return V_58 ;
}
static int F_140 ( struct V_154 * V_192 , struct V_110 * V_110 ,
T_3 V_21 , T_3 V_22 , int V_191 ,
struct V_8 * V_15 )
{
struct V_147 * V_187 = NULL ;
T_3 V_37 ;
struct V_193 * V_194 ;
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
struct V_2 * V_150 = & F_117 ( V_117 ) -> V_151 ;
struct V_2 * V_3 = & F_117 ( V_117 ) -> V_152 ;
struct V_195 * V_196 = & F_117 ( V_117 ) -> V_197 ;
struct V_154 * V_154 ;
int V_188 ;
int V_58 ;
int V_198 ;
T_3 V_158 ;
F_56 ( V_192 -> V_199 & V_200 ) ;
V_58 = F_111 ( V_150 , V_21 , & V_37 ) ;
if ( V_58 ) {
V_187 = F_141 ( sizeof( * V_187 ) , V_106 ) ;
if ( ! V_187 )
return - V_11 ;
V_187 -> V_21 = V_21 ;
V_187 -> V_25 = V_22 - V_21 + 1 ;
V_187 -> V_189 = 0 ;
V_187 -> V_201 = 0 ;
V_187 -> V_190 = 0 ;
F_142 ( & V_196 -> V_32 ) ;
V_194 = F_143 ( V_196 , V_21 , V_187 -> V_25 ) ;
if ( ! V_194 ) {
F_144 ( & V_196 -> V_32 ) ;
F_118 ( V_187 ) ;
return - V_167 ;
}
if ( V_194 -> V_21 > V_21 || V_194 -> V_21 + V_194 -> V_25 < V_21 ) {
F_145 ( V_194 ) ;
V_194 = NULL ;
}
F_144 ( & V_196 -> V_32 ) ;
if ( ! V_194 ) {
F_118 ( V_187 ) ;
return - V_167 ;
}
V_158 = V_21 - V_194 -> V_21 ;
V_158 = V_194 -> V_202 + V_158 ;
if ( F_130 ( V_203 , & V_194 -> V_36 ) ) {
V_158 = V_194 -> V_202 ;
V_187 -> V_201 = V_204 ;
F_146 ( & V_187 -> V_201 ,
V_194 -> V_205 ) ;
}
F_138 ( L_16
L_17 , V_158 , V_21 , V_187 -> V_25 ) ;
V_187 -> V_158 = V_158 ;
F_145 ( V_194 ) ;
V_58 = F_74 ( V_150 , V_21 , V_22 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 >= 0 )
V_58 = F_110 ( V_150 , V_21 ,
( T_3 ) ( unsigned long ) V_187 ) ;
if ( V_58 >= 0 )
V_58 = F_74 ( V_3 , V_21 , V_22 , V_153 ,
V_106 ) ;
if ( V_58 < 0 ) {
F_118 ( V_187 ) ;
return V_58 ;
}
} else {
V_187 = (struct V_147 * ) ( unsigned long ) V_37 ;
F_138 ( L_18
L_19 ,
V_187 -> V_158 , V_187 -> V_21 , V_187 -> V_25 ,
V_187 -> V_190 ) ;
}
V_188 = F_139 ( F_117 ( V_117 ) -> V_43 -> V_156 ,
V_187 -> V_158 , V_187 -> V_25 ) ;
if ( V_188 == 1 ) {
F_138 ( L_20
L_21
L_22 , V_15 , V_188 ,
V_187 -> V_189 , V_191 ) ;
F_116 ( V_117 , V_187 , 0 ) ;
return - V_167 ;
}
if ( ! V_15 ) {
F_54 ( & V_3 -> V_32 ) ;
V_15 = F_91 ( V_3 , V_187 -> V_21 ,
V_105 ) ;
if ( V_15 && V_15 -> V_21 != V_187 -> V_21 )
V_15 = NULL ;
F_58 ( & V_3 -> V_32 ) ;
}
if ( V_192 -> V_206 > 1 ) {
F_56 ( V_187 -> V_190 ) ;
V_187 -> V_190 = 1 ;
V_187 -> V_189 = V_191 ;
V_198 = V_207 | V_208 ;
} else {
if ( V_187 -> V_190 ) {
F_56 ( V_187 -> V_189 != V_191 ) ;
V_187 -> V_190 = 0 ;
V_187 -> V_189 = 0 ;
}
V_187 -> V_191 = V_191 ;
V_187 -> V_189 ++ ;
if ( V_187 -> V_189 == V_191 )
V_187 -> V_189 ++ ;
V_198 = V_207 ;
}
if ( ! V_15 || V_187 -> V_189 > V_188 ) {
F_138 ( L_23
L_24 , V_15 ,
V_188 , V_187 -> V_189 , V_191 ) ;
F_116 ( V_117 , V_187 , 0 ) ;
return - V_167 ;
}
V_154 = F_123 ( V_106 , 1 ) ;
if ( ! V_154 ) {
F_116 ( V_117 , V_187 , 0 ) ;
return - V_167 ;
}
V_154 -> V_155 = V_15 ;
V_154 -> V_168 = V_192 -> V_168 ;
V_154 -> V_173 = V_187 -> V_158 >> 9 ;
V_154 -> V_176 = F_117 ( V_117 ) -> V_43 -> V_156 -> V_209 -> V_210 ;
V_154 -> V_169 = 0 ;
F_126 ( V_154 , V_110 , V_187 -> V_25 , V_21 - F_127 ( V_110 ) ) ;
F_138 ( L_25
L_26 , V_198 ,
V_187 -> V_189 , V_188 , V_187 -> V_190 ) ;
V_58 = V_3 -> V_30 -> V_211 ( V_117 , V_198 , V_154 ,
V_187 -> V_189 ,
V_187 -> V_201 , 0 ) ;
return V_58 ;
}
int F_147 ( struct V_110 * V_110 , int V_79 , T_3 V_21 , T_3 V_22 )
{
int V_212 = ( V_79 == 0 ) ;
struct V_2 * V_3 ;
int V_58 ;
V_3 = & F_117 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_213 ) {
V_58 = V_3 -> V_30 -> V_213 ( V_110 , V_21 ,
V_22 , NULL , V_212 ) ;
if ( V_58 )
V_212 = 0 ;
}
if ( ! V_212 ) {
F_148 ( V_110 ) ;
F_149 ( V_110 ) ;
}
return 0 ;
}
static void F_150 ( struct V_154 * V_154 , int V_79 )
{
struct V_214 * V_215 = V_154 -> V_216 + V_154 -> V_206 - 1 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_217 ;
do {
struct V_110 * V_110 = V_215 -> V_218 ;
V_3 = & F_117 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_215 -> V_219 ;
V_22 = V_21 + V_215 -> V_220 - 1 ;
if ( V_215 -> V_219 == 0 && V_215 -> V_220 == V_131 )
V_217 = 1 ;
else
V_217 = 0 ;
if ( -- V_215 >= V_154 -> V_216 )
F_151 ( & V_215 -> V_218 -> V_36 ) ;
if ( F_147 ( V_110 , V_79 , V_21 , V_22 ) )
continue;
if ( V_217 )
F_106 ( V_110 ) ;
else
F_115 ( V_3 , V_110 ) ;
} while ( V_215 >= V_154 -> V_216 );
F_125 ( V_154 ) ;
}
static void F_152 ( struct V_154 * V_154 , int V_79 )
{
int V_212 = F_130 ( V_178 , & V_154 -> V_179 ) ;
struct V_214 * V_221 = V_154 -> V_216 + V_154 -> V_206 - 1 ;
struct V_214 * V_215 = V_154 -> V_216 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_217 ;
int V_222 ;
int V_58 ;
if ( V_79 )
V_212 = 0 ;
do {
struct V_110 * V_110 = V_215 -> V_218 ;
struct V_8 * V_82 = NULL ;
struct V_8 * V_15 ;
F_138 ( L_27
L_28 , ( T_3 ) V_154 -> V_173 , V_79 ,
( long int ) V_154 -> V_176 ) ;
V_3 = & F_117 ( V_110 -> V_4 -> V_5 ) -> V_152 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_215 -> V_219 ;
V_22 = V_21 + V_215 -> V_220 - 1 ;
if ( V_215 -> V_219 == 0 && V_215 -> V_220 == V_131 )
V_217 = 1 ;
else
V_217 = 0 ;
if ( ++ V_215 <= V_221 )
F_151 ( & V_215 -> V_218 -> V_36 ) ;
F_54 ( & V_3 -> V_32 ) ;
V_15 = F_91 ( V_3 , V_21 , V_105 ) ;
if ( V_15 && V_15 -> V_21 == V_21 ) {
F_68 ( V_15 , & V_82 ) ;
}
F_58 ( & V_3 -> V_32 ) ;
V_222 = ( int ) ( unsigned long ) V_154 -> V_176 ;
if ( V_212 && V_3 -> V_30 && V_3 -> V_30 -> V_223 ) {
V_58 = V_3 -> V_30 -> V_223 ( V_110 , V_21 , V_22 ,
V_15 , V_222 ) ;
if ( V_58 )
V_212 = 0 ;
else
F_137 ( V_21 , V_110 ) ;
}
if ( ! V_212 && V_3 -> V_30 && V_3 -> V_30 -> V_224 ) {
V_58 = V_3 -> V_30 -> V_224 ( V_110 , V_222 ) ;
if ( ! V_58 && ! V_79 &&
F_130 ( V_178 , & V_154 -> V_179 ) )
V_212 = 1 ;
} else if ( ! V_212 ) {
V_58 = F_140 ( V_154 , V_110 , V_21 , V_22 , V_222 , NULL ) ;
if ( V_58 == 0 ) {
V_212 =
F_130 ( V_178 , & V_154 -> V_179 ) ;
if ( V_79 )
V_212 = 0 ;
F_69 ( & V_82 ) ;
continue;
}
}
if ( V_212 && V_3 -> V_225 ) {
F_80 ( V_3 , V_21 , V_22 , & V_82 ,
V_29 ) ;
}
F_85 ( V_3 , V_21 , V_22 , & V_82 , V_29 ) ;
if ( V_217 ) {
if ( V_212 ) {
F_113 ( V_110 ) ;
} else {
F_148 ( V_110 ) ;
F_149 ( V_110 ) ;
}
F_97 ( V_110 ) ;
} else {
if ( V_212 ) {
F_112 ( V_3 , V_110 ) ;
} else {
F_148 ( V_110 ) ;
F_149 ( V_110 ) ;
}
F_114 ( V_3 , V_110 ) ;
}
} while ( V_215 <= V_221 );
F_125 ( V_154 ) ;
}
struct V_154 *
F_153 ( struct V_226 * V_174 , T_3 V_227 , int V_228 ,
T_2 V_229 )
{
struct V_154 * V_154 ;
V_154 = F_123 ( V_229 , V_228 ) ;
if ( V_154 == NULL && ( V_230 -> V_36 & V_231 ) ) {
while ( ! V_154 && ( V_228 /= 2 ) )
V_154 = F_123 ( V_229 , V_228 ) ;
}
if ( V_154 ) {
V_154 -> V_169 = 0 ;
V_154 -> V_176 = V_174 ;
V_154 -> V_173 = V_227 ;
}
return V_154 ;
}
static int T_4 F_154 ( int V_232 , struct V_154 * V_154 ,
int V_159 , unsigned long V_201 )
{
int V_58 = 0 ;
struct V_214 * V_215 = V_154 -> V_216 + V_154 -> V_206 - 1 ;
struct V_110 * V_110 = V_215 -> V_218 ;
struct V_2 * V_3 = V_154 -> V_155 ;
T_3 V_21 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) + V_215 -> V_219 ;
V_154 -> V_155 = NULL ;
F_155 ( V_154 ) ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_211 )
V_58 = V_3 -> V_30 -> V_211 ( V_110 -> V_4 -> V_5 , V_232 , V_154 ,
V_159 , V_201 , V_21 ) ;
else
F_128 ( V_232 , V_154 ) ;
if ( F_156 ( V_154 , V_233 ) )
V_58 = - V_234 ;
F_125 ( V_154 ) ;
return V_58 ;
}
static int F_157 ( struct V_2 * V_3 , struct V_110 * V_110 ,
unsigned long V_44 , T_6 V_235 , struct V_154 * V_154 ,
unsigned long V_201 )
{
int V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_236 )
V_58 = V_3 -> V_30 -> V_236 ( V_110 , V_44 , V_235 , V_154 ,
V_201 ) ;
F_56 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_158 ( int V_232 , struct V_2 * V_3 ,
struct V_110 * V_110 , T_7 V_164 ,
T_6 V_235 , unsigned long V_44 ,
struct V_226 * V_174 ,
struct V_154 * * V_237 ,
unsigned long V_238 ,
T_8 V_239 ,
int V_159 ,
unsigned long V_240 ,
unsigned long V_201 )
{
int V_58 = 0 ;
struct V_154 * V_154 ;
int V_241 ;
int V_142 = 0 ;
int V_242 = V_201 & V_204 ;
int V_243 = V_240 & V_204 ;
T_6 V_244 = F_96 ( T_6 , V_235 , V_131 ) ;
if ( V_237 && * V_237 ) {
V_154 = * V_237 ;
if ( V_243 )
V_142 = V_154 -> V_173 == V_164 ;
else
V_142 = V_154 -> V_173 + ( V_154 -> V_169 >> 9 ) ==
V_164 ;
if ( V_240 != V_201 || ! V_142 ||
F_157 ( V_3 , V_110 , V_44 , V_244 , V_154 , V_201 ) ||
F_126 ( V_154 , V_110 , V_244 , V_44 ) < V_244 ) {
V_58 = F_154 ( V_232 , V_154 , V_159 ,
V_240 ) ;
if ( V_58 < 0 )
return V_58 ;
V_154 = NULL ;
} else {
return 0 ;
}
}
if ( V_242 )
V_241 = V_245 ;
else
V_241 = F_159 ( V_174 ) ;
V_154 = F_153 ( V_174 , V_164 , V_241 , V_106 | V_246 ) ;
if ( ! V_154 )
return - V_11 ;
F_126 ( V_154 , V_110 , V_244 , V_44 ) ;
V_154 -> V_168 = V_239 ;
V_154 -> V_155 = V_3 ;
if ( V_237 )
* V_237 = V_154 ;
else
V_58 = F_154 ( V_232 , V_154 , V_159 , V_201 ) ;
return V_58 ;
}
void F_160 ( struct V_13 * V_16 , struct V_110 * V_110 )
{
if ( ! F_161 ( V_110 ) ) {
F_162 ( V_110 ) ;
F_163 ( V_110 ) ;
F_164 ( V_110 , ( unsigned long ) V_16 ) ;
} else {
F_27 ( V_110 -> V_37 != ( unsigned long ) V_16 ) ;
}
}
void F_165 ( struct V_110 * V_110 )
{
if ( ! F_161 ( V_110 ) ) {
F_162 ( V_110 ) ;
F_163 ( V_110 ) ;
F_164 ( V_110 , V_247 ) ;
}
}
static int F_166 ( struct V_2 * V_3 ,
struct V_110 * V_110 ,
T_9 * V_248 ,
struct V_154 * * V_154 , int V_159 ,
unsigned long * V_201 )
{
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_249 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_250 = V_21 ;
T_3 V_251 ;
T_3 V_252 = F_167 ( V_117 ) ;
T_3 V_202 ;
T_3 V_253 ;
T_7 V_164 ;
struct V_193 * V_194 ;
struct V_226 * V_174 ;
struct V_254 * V_255 ;
int V_58 ;
int V_241 = 0 ;
T_6 V_256 = 0 ;
T_6 V_257 ;
T_6 V_258 ;
T_6 V_259 = V_117 -> V_6 -> V_260 ;
unsigned long V_261 = 0 ;
F_165 ( V_110 ) ;
if ( ! F_168 ( V_110 ) ) {
if ( F_169 ( V_110 ) == 0 ) {
F_56 ( V_259 != V_262 ) ;
goto V_89;
}
}
V_22 = V_249 ;
while ( 1 ) {
F_83 ( V_3 , V_21 , V_22 ) ;
V_255 = F_170 ( V_117 , V_21 ) ;
if ( ! V_255 )
break;
F_86 ( V_3 , V_21 , V_22 ) ;
F_171 ( V_117 , V_255 , 1 ) ;
F_172 ( V_255 ) ;
}
if ( V_110 -> V_107 == V_252 >> V_108 ) {
char * V_263 ;
T_6 V_264 = V_252 & ( V_131 - 1 ) ;
if ( V_264 ) {
V_257 = V_131 - V_264 ;
V_263 = F_173 ( V_110 ) ;
memset ( V_263 + V_264 , 0 , V_257 ) ;
F_174 ( V_110 ) ;
F_175 ( V_263 ) ;
}
}
while ( V_250 <= V_22 ) {
if ( V_250 >= V_252 ) {
char * V_263 ;
struct V_8 * V_82 = NULL ;
V_257 = V_131 - V_256 ;
V_263 = F_173 ( V_110 ) ;
memset ( V_263 + V_256 , 0 , V_257 ) ;
F_174 ( V_110 ) ;
F_175 ( V_263 ) ;
F_80 ( V_3 , V_250 , V_250 + V_257 - 1 ,
& V_82 , V_106 ) ;
F_85 ( V_3 , V_250 , V_250 + V_257 - 1 ,
& V_82 , V_106 ) ;
break;
}
V_194 = V_248 ( V_117 , V_110 , V_256 , V_250 ,
V_22 - V_250 + 1 , 0 ) ;
if ( F_176 ( V_194 ) ) {
F_149 ( V_110 ) ;
F_86 ( V_3 , V_250 , V_22 ) ;
break;
}
V_251 = V_250 - V_194 -> V_21 ;
F_56 ( F_177 ( V_194 ) <= V_250 ) ;
F_56 ( V_22 < V_250 ) ;
if ( F_130 ( V_203 , & V_194 -> V_36 ) ) {
V_261 = V_204 ;
F_146 ( & V_261 ,
V_194 -> V_205 ) ;
}
V_257 = F_108 ( F_177 ( V_194 ) - V_250 , V_22 - V_250 + 1 ) ;
V_253 = F_108 ( F_177 ( V_194 ) - 1 , V_22 ) ;
V_257 = ( V_257 + V_259 - 1 ) & ~ ( ( T_3 ) V_259 - 1 ) ;
if ( V_261 & V_204 ) {
V_258 = V_194 -> V_265 ;
V_164 = V_194 -> V_202 >> 9 ;
} else {
V_164 = ( V_194 -> V_202 + V_251 ) >> 9 ;
V_258 = V_257 ;
}
V_174 = V_194 -> V_174 ;
V_202 = V_194 -> V_202 ;
if ( F_130 ( V_266 , & V_194 -> V_36 ) )
V_202 = V_267 ;
F_145 ( V_194 ) ;
V_194 = NULL ;
if ( V_202 == V_267 ) {
char * V_263 ;
struct V_8 * V_82 = NULL ;
V_263 = F_173 ( V_110 ) ;
memset ( V_263 + V_256 , 0 , V_257 ) ;
F_174 ( V_110 ) ;
F_175 ( V_263 ) ;
F_80 ( V_3 , V_250 , V_250 + V_257 - 1 ,
& V_82 , V_106 ) ;
F_85 ( V_3 , V_250 , V_250 + V_257 - 1 ,
& V_82 , V_106 ) ;
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
continue;
}
if ( F_102 ( V_3 , V_250 , V_253 ,
V_101 , 1 , NULL ) ) {
F_112 ( V_3 , V_110 ) ;
F_86 ( V_3 , V_250 , V_250 + V_257 - 1 ) ;
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
continue;
}
if ( V_202 == V_268 ) {
F_149 ( V_110 ) ;
F_86 ( V_3 , V_250 , V_250 + V_257 - 1 ) ;
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
continue;
}
V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_269 ) {
V_58 = V_3 -> V_30 -> V_269 ( V_110 , V_250 ,
V_250 + V_257 - 1 ) ;
}
if ( ! V_58 ) {
unsigned long V_270 = ( V_252 >> V_108 ) + 1 ;
V_270 -= V_110 -> V_107 ;
V_58 = F_158 ( V_271 , V_3 , V_110 ,
V_164 , V_258 , V_256 ,
V_174 , V_154 , V_270 ,
F_152 , V_159 ,
* V_201 ,
V_261 ) ;
if ( ! V_58 ) {
V_241 ++ ;
* V_201 = V_261 ;
}
}
if ( V_58 ) {
F_149 ( V_110 ) ;
F_86 ( V_3 , V_250 , V_250 + V_257 - 1 ) ;
}
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
}
V_89:
if ( ! V_241 ) {
if ( ! F_178 ( V_110 ) )
F_113 ( V_110 ) ;
F_97 ( V_110 ) ;
}
return 0 ;
}
int F_179 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_248 , int V_159 )
{
struct V_154 * V_154 = NULL ;
unsigned long V_201 = 0 ;
int V_58 ;
V_58 = F_166 ( V_3 , V_110 , V_248 , & V_154 , V_159 ,
& V_201 ) ;
if ( V_154 )
V_58 = F_154 ( V_271 , V_154 , V_159 , V_201 ) ;
return V_58 ;
}
static T_5 void F_180 ( struct V_110 * V_110 ,
struct V_272 * V_273 ,
unsigned long V_274 )
{
V_273 -> V_275 -= V_274 ;
if ( V_273 -> V_276 || ( V_273 -> V_275 > 0 &&
V_273 -> V_277 == 0 && V_273 -> V_278 == V_279 ) )
V_110 -> V_4 -> V_280 = V_110 -> V_107 + V_274 ;
}
static int F_181 ( struct V_110 * V_110 , struct V_272 * V_273 ,
void * V_281 )
{
struct V_117 * V_117 = V_110 -> V_4 -> V_5 ;
struct V_282 * V_283 = V_281 ;
struct V_2 * V_3 = V_283 -> V_3 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_123 ;
T_3 V_249 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_250 = V_21 ;
T_3 V_251 ;
T_3 V_252 = F_167 ( V_117 ) ;
T_3 V_202 ;
T_3 V_257 ;
T_7 V_164 ;
struct V_8 * V_81 = NULL ;
struct V_193 * V_194 ;
struct V_226 * V_174 ;
int V_58 ;
int V_241 = 0 ;
T_6 V_256 = 0 ;
T_6 V_259 ;
T_10 V_284 = F_167 ( V_117 ) ;
unsigned long V_109 = V_284 >> V_108 ;
T_3 V_285 ;
T_3 V_124 ;
int V_286 ;
int V_287 ;
int V_288 ;
unsigned long V_274 = 0 ;
bool V_289 = true ;
if ( V_273 -> V_290 == V_291 )
V_288 = V_177 ;
else
V_288 = V_170 ;
F_182 ( V_110 , V_117 , V_273 ) ;
F_27 ( ! F_183 ( V_110 ) ) ;
F_184 ( V_110 ) ;
V_256 = V_284 & ( V_131 - 1 ) ;
if ( V_110 -> V_107 > V_109 ||
( V_110 -> V_107 == V_109 && ! V_256 ) ) {
V_110 -> V_4 -> V_292 -> V_293 ( V_110 , 0 ) ;
F_97 ( V_110 ) ;
return 0 ;
}
if ( V_110 -> V_107 == V_109 ) {
char * V_263 ;
V_263 = F_173 ( V_110 ) ;
memset ( V_263 + V_256 , 0 ,
V_131 - V_256 ) ;
F_175 ( V_263 ) ;
F_174 ( V_110 ) ;
}
V_256 = 0 ;
F_165 ( V_110 ) ;
if ( ! V_3 -> V_30 || ! V_3 -> V_30 -> V_289 )
V_289 = false ;
V_123 = V_21 ;
V_124 = 0 ;
V_286 = 0 ;
if ( ! V_283 -> V_294 && V_289 ) {
T_3 V_295 = 0 ;
F_180 ( V_110 , V_273 , 0 ) ;
while ( V_124 < V_249 ) {
V_285 = F_101 ( V_117 , V_3 ,
V_110 ,
& V_123 ,
& V_124 ,
128 * 1024 * 1024 ) ;
if ( V_285 == 0 ) {
V_123 = V_124 + 1 ;
continue;
}
V_58 = V_3 -> V_30 -> V_289 ( V_117 , V_110 ,
V_123 ,
V_124 ,
& V_286 ,
& V_274 ) ;
if ( V_58 ) {
F_149 ( V_110 ) ;
goto V_129;
}
V_295 += ( V_124 - V_123 +
V_131 ) >>
V_108 ;
V_123 = V_124 + 1 ;
}
if ( V_273 -> V_275 < V_295 ) {
int V_296 = 8192 ;
if ( V_295 < V_296 * 2 )
V_296 = V_295 ;
V_273 -> V_275 = F_96 ( T_3 , V_295 ,
V_296 ) ;
}
if ( V_286 ) {
V_58 = 0 ;
V_273 -> V_275 -= V_274 ;
goto V_297;
}
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_298 ) {
V_58 = V_3 -> V_30 -> V_298 ( V_110 , V_21 ,
V_249 ) ;
if ( V_58 ) {
if ( V_58 == - V_299 )
V_273 -> V_300 ++ ;
else
F_185 ( V_273 , V_110 ) ;
F_180 ( V_110 , V_273 , V_274 ) ;
F_97 ( V_110 ) ;
V_58 = 0 ;
goto V_297;
}
}
F_180 ( V_110 , V_273 , V_274 + 1 ) ;
V_22 = V_249 ;
if ( V_252 <= V_21 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_213 )
V_3 -> V_30 -> V_213 ( V_110 , V_21 ,
V_249 , NULL , 1 ) ;
goto V_129;
}
V_259 = V_117 -> V_6 -> V_260 ;
while ( V_250 <= V_22 ) {
if ( V_250 >= V_252 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_213 )
V_3 -> V_30 -> V_213 ( V_110 , V_250 ,
V_249 , NULL , 1 ) ;
break;
}
V_194 = V_283 -> V_248 ( V_117 , V_110 , V_256 , V_250 ,
V_22 - V_250 + 1 , 1 ) ;
if ( F_176 ( V_194 ) ) {
F_149 ( V_110 ) ;
break;
}
V_251 = V_250 - V_194 -> V_21 ;
F_56 ( F_177 ( V_194 ) <= V_250 ) ;
F_56 ( V_22 < V_250 ) ;
V_257 = F_108 ( F_177 ( V_194 ) - V_250 , V_22 - V_250 + 1 ) ;
V_257 = ( V_257 + V_259 - 1 ) & ~ ( ( T_3 ) V_259 - 1 ) ;
V_164 = ( V_194 -> V_202 + V_251 ) >> 9 ;
V_174 = V_194 -> V_174 ;
V_202 = V_194 -> V_202 ;
V_287 = F_130 ( V_203 , & V_194 -> V_36 ) ;
F_145 ( V_194 ) ;
V_194 = NULL ;
if ( V_287 || V_202 == V_267 ||
V_202 == V_268 ) {
if ( ! V_287 && V_3 -> V_30 &&
V_3 -> V_30 -> V_213 )
V_3 -> V_30 -> V_213 ( V_110 , V_250 ,
V_250 + V_257 - 1 ,
NULL , 1 ) ;
else if ( V_287 ) {
V_241 ++ ;
}
V_250 += V_257 ;
V_256 += V_257 ;
continue;
}
if ( 0 && ! F_102 ( V_3 , V_250 , V_250 + V_257 - 1 ,
V_77 , 0 , NULL ) ) {
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
continue;
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_301 ) {
V_58 = V_3 -> V_30 -> V_301 ( V_110 , V_250 ,
V_250 + V_257 - 1 ) ;
} else {
V_58 = 0 ;
}
if ( V_58 ) {
F_149 ( V_110 ) ;
} else {
unsigned long V_302 = V_109 + 1 ;
F_87 ( V_3 , V_250 , V_250 + V_257 - 1 ) ;
if ( ! F_186 ( V_110 ) ) {
F_9 ( V_20 L_29
L_30 ,
V_110 -> V_107 , ( unsigned long long ) V_250 ,
( unsigned long long ) V_22 ) ;
}
V_58 = F_158 ( V_288 , V_3 , V_110 ,
V_164 , V_257 , V_256 ,
V_174 , & V_283 -> V_154 , V_302 ,
F_150 ,
0 , 0 , 0 ) ;
if ( V_58 )
F_149 ( V_110 ) ;
}
V_250 = V_250 + V_257 ;
V_256 += V_257 ;
V_241 ++ ;
}
V_129:
if ( V_241 == 0 ) {
F_89 ( V_110 ) ;
F_106 ( V_110 ) ;
}
F_97 ( V_110 ) ;
V_297:
F_25 ( V_81 ) ;
return 0 ;
}
static int F_187 ( void * V_303 )
{
F_188 () ;
return 0 ;
}
static void F_189 ( struct V_13 * V_16 )
{
F_190 ( & V_16 -> V_304 , V_305 , F_187 ,
V_92 ) ;
}
static int F_191 ( struct V_13 * V_16 ,
struct V_1 * V_156 ,
struct V_282 * V_283 )
{
unsigned long V_121 , V_185 ;
int V_306 = 0 ;
int V_58 = 0 ;
if ( ! F_192 ( V_16 ) ) {
V_306 = 1 ;
F_193 ( V_283 ) ;
F_194 ( V_16 ) ;
}
if ( F_130 ( V_305 , & V_16 -> V_304 ) ) {
F_195 ( V_16 ) ;
if ( ! V_283 -> V_307 )
return 0 ;
if ( ! V_306 ) {
F_193 ( V_283 ) ;
V_306 = 1 ;
}
while ( 1 ) {
F_189 ( V_16 ) ;
F_194 ( V_16 ) ;
if ( ! F_130 ( V_305 , & V_16 -> V_304 ) )
break;
F_195 ( V_16 ) ;
}
}
F_54 ( & V_16 -> V_308 ) ;
if ( F_196 ( V_309 , & V_16 -> V_304 ) ) {
F_197 ( V_305 , & V_16 -> V_304 ) ;
F_58 ( & V_16 -> V_308 ) ;
F_198 ( V_16 , V_310 ) ;
F_54 ( & V_156 -> V_311 ) ;
if ( V_156 -> V_312 >= V_16 -> V_25 )
V_156 -> V_312 -= V_16 -> V_25 ;
else
F_27 ( 1 ) ;
F_58 ( & V_156 -> V_311 ) ;
V_58 = 1 ;
} else {
F_58 ( & V_16 -> V_308 ) ;
}
F_195 ( V_16 ) ;
if ( ! V_58 )
return V_58 ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
struct V_110 * V_46 = F_136 ( V_16 , V_121 ) ;
if ( ! F_199 ( V_46 ) ) {
if ( ! V_306 ) {
F_193 ( V_283 ) ;
V_306 = 1 ;
}
F_99 ( V_46 ) ;
}
}
return V_58 ;
}
static void F_200 ( struct V_13 * V_16 )
{
F_201 ( V_305 , & V_16 -> V_304 ) ;
F_202 () ;
F_203 ( & V_16 -> V_304 , V_305 ) ;
}
static void F_204 ( struct V_154 * V_154 , int V_79 )
{
int V_212 = V_79 == 0 ;
struct V_214 * V_215 = V_154 -> V_216 + V_154 -> V_206 - 1 ;
struct V_13 * V_16 ;
int V_129 ;
do {
struct V_110 * V_110 = V_215 -> V_218 ;
V_215 -- ;
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_56 ( ! V_16 ) ;
V_129 = F_26 ( & V_16 -> V_313 ) ;
if ( ! V_212 || F_130 ( V_314 , & V_16 -> V_304 ) ) {
F_197 ( V_314 , & V_16 -> V_304 ) ;
F_148 ( V_110 ) ;
F_149 ( V_110 ) ;
}
F_106 ( V_110 ) ;
if ( ! V_129 )
continue;
F_200 ( V_16 ) ;
} while ( V_215 >= V_154 -> V_216 );
F_125 ( V_154 ) ;
}
static int F_205 ( struct V_13 * V_16 ,
struct V_1 * V_156 ,
struct V_272 * V_273 ,
struct V_282 * V_283 )
{
struct V_226 * V_174 = V_156 -> V_209 -> V_210 ;
T_3 V_44 = V_16 -> V_21 ;
unsigned long V_121 , V_185 ;
unsigned long V_201 = 0 ;
int V_232 = ( V_283 -> V_307 ? V_177 : V_170 ) ;
int V_58 = 0 ;
F_201 ( V_314 , & V_16 -> V_304 ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_22 ( & V_16 -> V_313 , V_185 ) ;
if ( F_206 ( V_16 ) == V_315 )
V_201 = V_316 ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
struct V_110 * V_46 = F_136 ( V_16 , V_121 ) ;
F_105 ( V_46 ) ;
F_89 ( V_46 ) ;
V_58 = F_158 ( V_232 , V_16 -> V_3 , V_46 , V_44 >> 9 ,
V_131 , 0 , V_174 , & V_283 -> V_154 ,
- 1 , F_204 ,
0 , V_283 -> V_201 , V_201 ) ;
V_283 -> V_201 = V_201 ;
if ( V_58 ) {
F_197 ( V_314 , & V_16 -> V_304 ) ;
F_149 ( V_46 ) ;
if ( F_207 ( V_185 - V_121 , & V_16 -> V_313 ) )
F_200 ( V_16 ) ;
V_58 = - V_167 ;
break;
}
V_44 += V_131 ;
F_180 ( V_46 , V_273 , 1 ) ;
F_97 ( V_46 ) ;
}
if ( F_208 ( V_58 ) ) {
for (; V_121 < V_185 ; V_121 ++ ) {
struct V_110 * V_46 = F_136 ( V_16 , V_121 ) ;
F_97 ( V_46 ) ;
}
}
return V_58 ;
}
int F_209 ( struct V_26 * V_4 ,
struct V_272 * V_273 )
{
struct V_2 * V_3 = & F_117 ( V_4 -> V_5 ) -> V_152 ;
struct V_1 * V_156 = F_117 ( V_4 -> V_5 ) -> V_43 -> V_156 ;
struct V_13 * V_16 , * V_317 = NULL ;
struct V_282 V_283 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_294 = 0 ,
. V_307 = V_273 -> V_290 == V_291 ,
. V_201 = 0 ,
} ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_120 ;
T_11 V_107 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
F_210 ( & V_320 , 0 ) ;
if ( V_273 -> V_276 ) {
V_107 = V_4 -> V_280 ;
V_22 = - 1 ;
} else {
V_107 = V_273 -> V_277 >> V_108 ;
V_22 = V_273 -> V_278 >> V_108 ;
V_321 = 1 ;
}
if ( V_273 -> V_290 == V_291 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_273 -> V_290 == V_291 )
F_211 ( V_4 , V_107 , V_22 ) ;
while ( ! V_129 && ! V_318 && ( V_107 <= V_22 ) &&
( V_120 = F_212 ( & V_320 , V_4 , & V_107 , V_322 ,
F_108 ( V_22 - V_107 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_121 ;
V_321 = 1 ;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
struct V_110 * V_110 = V_320 . V_119 [ V_121 ] ;
if ( ! F_161 ( V_110 ) )
continue;
if ( ! V_273 -> V_276 && V_110 -> V_107 > V_22 ) {
V_129 = 1 ;
break;
}
F_54 ( & V_4 -> V_327 ) ;
if ( ! F_161 ( V_110 ) ) {
F_58 ( & V_4 -> V_327 ) ;
continue;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
if ( ! V_16 ) {
F_58 ( & V_4 -> V_327 ) ;
F_27 ( 1 ) ;
continue;
}
if ( V_16 == V_317 ) {
F_58 ( & V_4 -> V_327 ) ;
continue;
}
V_58 = F_213 ( & V_16 -> V_23 ) ;
F_58 ( & V_4 -> V_327 ) ;
if ( ! V_58 )
continue;
V_317 = V_16 ;
V_58 = F_191 ( V_16 , V_156 , & V_283 ) ;
if ( ! V_58 ) {
F_214 ( V_16 ) ;
continue;
}
V_58 = F_205 ( V_16 , V_156 , V_273 , & V_283 ) ;
if ( V_58 ) {
V_129 = 1 ;
F_214 ( V_16 ) ;
break;
}
F_214 ( V_16 ) ;
V_318 = V_273 -> V_275 <= 0 ;
}
F_215 ( & V_320 ) ;
F_59 () ;
}
if ( ! V_321 && ! V_129 ) {
V_321 = 1 ;
V_107 = 0 ;
goto V_325;
}
F_193 ( & V_283 ) ;
return V_58 ;
}
static int F_216 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_272 * V_273 ,
T_12 V_328 , void * V_281 ,
void (* F_217)( void * ) )
{
struct V_117 * V_117 = V_4 -> V_5 ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_120 ;
T_11 V_107 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
if ( ! F_218 ( V_117 ) )
return 0 ;
F_210 ( & V_320 , 0 ) ;
if ( V_273 -> V_276 ) {
V_107 = V_4 -> V_280 ;
V_22 = - 1 ;
} else {
V_107 = V_273 -> V_277 >> V_108 ;
V_22 = V_273 -> V_278 >> V_108 ;
V_321 = 1 ;
}
if ( V_273 -> V_290 == V_291 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_273 -> V_290 == V_291 )
F_211 ( V_4 , V_107 , V_22 ) ;
while ( ! V_129 && ! V_318 && ( V_107 <= V_22 ) &&
( V_120 = F_212 ( & V_320 , V_4 , & V_107 , V_322 ,
F_108 ( V_22 - V_107 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_121 ;
V_321 = 1 ;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
struct V_110 * V_110 = V_320 . V_119 [ V_121 ] ;
if ( V_3 -> V_30 &&
V_3 -> V_30 -> V_329 ) {
V_3 -> V_30 -> V_329 ( V_110 ,
V_281 , F_217 ) ;
} else {
if ( ! F_199 ( V_110 ) ) {
F_217 ( V_281 ) ;
F_99 ( V_110 ) ;
}
}
if ( F_208 ( V_110 -> V_4 != V_4 ) ) {
F_97 ( V_110 ) ;
continue;
}
if ( ! V_273 -> V_276 && V_110 -> V_107 > V_22 ) {
V_129 = 1 ;
F_97 ( V_110 ) ;
continue;
}
if ( V_273 -> V_290 != V_330 ) {
if ( F_186 ( V_110 ) )
F_217 ( V_281 ) ;
F_219 ( V_110 ) ;
}
if ( F_186 ( V_110 ) ||
! F_105 ( V_110 ) ) {
F_97 ( V_110 ) ;
continue;
}
V_58 = (* V_328)( V_110 , V_273 , V_281 ) ;
if ( F_208 ( V_58 == V_331 ) ) {
F_97 ( V_110 ) ;
V_58 = 0 ;
}
if ( V_58 )
V_129 = 1 ;
V_318 = V_273 -> V_275 <= 0 ;
}
F_215 ( & V_320 ) ;
F_59 () ;
}
if ( ! V_321 && ! V_129 ) {
V_321 = 1 ;
V_107 = 0 ;
goto V_325;
}
F_220 ( V_117 ) ;
return V_58 ;
}
static void F_221 ( struct V_282 * V_283 )
{
if ( V_283 -> V_154 ) {
int V_232 = V_170 ;
int V_58 ;
if ( V_283 -> V_307 )
V_232 = V_177 ;
V_58 = F_154 ( V_232 , V_283 -> V_154 , 0 , V_283 -> V_201 ) ;
F_56 ( V_58 < 0 ) ;
V_283 -> V_154 = NULL ;
}
}
static T_5 void F_193 ( void * V_281 )
{
struct V_282 * V_283 = V_281 ;
F_221 ( V_283 ) ;
}
int F_222 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_248 ,
struct V_272 * V_273 )
{
int V_58 ;
struct V_282 V_283 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_248 = V_248 ,
. V_294 = 0 ,
. V_307 = V_273 -> V_290 == V_291 ,
. V_201 = 0 ,
} ;
V_58 = F_181 ( V_110 , V_273 , & V_283 ) ;
F_221 ( & V_283 ) ;
return V_58 ;
}
int F_223 ( struct V_2 * V_3 , struct V_117 * V_117 ,
T_3 V_21 , T_3 V_22 , T_9 * V_248 ,
int V_332 )
{
int V_58 = 0 ;
struct V_26 * V_4 = V_117 -> V_122 ;
struct V_110 * V_110 ;
unsigned long V_120 = ( V_22 - V_21 + V_131 ) >>
V_108 ;
struct V_282 V_283 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_248 = V_248 ,
. V_294 = 1 ,
. V_307 = V_332 == V_291 ,
. V_201 = 0 ,
} ;
struct V_272 V_333 = {
. V_290 = V_332 ,
. V_275 = V_120 * 2 ,
. V_277 = V_21 ,
. V_278 = V_22 + 1 ,
} ;
while ( V_21 <= V_22 ) {
V_110 = F_88 ( V_4 , V_21 >> V_108 ) ;
if ( F_105 ( V_110 ) )
V_58 = F_181 ( V_110 , & V_333 , & V_283 ) ;
else {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_213 )
V_3 -> V_30 -> V_213 ( V_110 , V_21 ,
V_21 + V_131 - 1 ,
NULL , 1 ) ;
F_97 ( V_110 ) ;
}
F_90 ( V_110 ) ;
V_21 += V_131 ;
}
F_221 ( & V_283 ) ;
return V_58 ;
}
int F_224 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
T_9 * V_248 ,
struct V_272 * V_273 )
{
int V_58 = 0 ;
struct V_282 V_283 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_248 = V_248 ,
. V_294 = 0 ,
. V_307 = V_273 -> V_290 == V_291 ,
. V_201 = 0 ,
} ;
V_58 = F_216 ( V_3 , V_4 , V_273 ,
F_181 , & V_283 ,
F_193 ) ;
F_221 ( & V_283 ) ;
return V_58 ;
}
int F_225 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_334 * V_119 , unsigned V_120 ,
T_9 V_248 )
{
struct V_154 * V_154 = NULL ;
unsigned V_335 ;
unsigned long V_201 = 0 ;
struct V_110 * V_336 [ 16 ] ;
struct V_110 * V_110 ;
int V_121 = 0 ;
int V_241 = 0 ;
for ( V_335 = 0 ; V_335 < V_120 ; V_335 ++ ) {
V_110 = F_8 ( V_119 -> V_55 , struct V_110 , V_337 ) ;
F_151 ( & V_110 -> V_36 ) ;
F_11 ( & V_110 -> V_337 ) ;
if ( F_226 ( V_110 , V_4 ,
V_110 -> V_107 , V_106 ) ) {
F_90 ( V_110 ) ;
continue;
}
V_336 [ V_241 ++ ] = V_110 ;
if ( V_241 < F_227 ( V_336 ) )
continue;
for ( V_121 = 0 ; V_121 < V_241 ; V_121 ++ ) {
F_166 ( V_3 , V_336 [ V_121 ] , V_248 ,
& V_154 , 0 , & V_201 ) ;
F_90 ( V_336 [ V_121 ] ) ;
}
V_241 = 0 ;
}
for ( V_121 = 0 ; V_121 < V_241 ; V_121 ++ ) {
F_166 ( V_3 , V_336 [ V_121 ] , V_248 ,
& V_154 , 0 , & V_201 ) ;
F_90 ( V_336 [ V_121 ] ) ;
}
F_56 ( ! F_7 ( V_119 ) ) ;
if ( V_154 )
return F_154 ( V_271 , V_154 , 0 , V_201 ) ;
return 0 ;
}
int F_228 ( struct V_2 * V_3 ,
struct V_110 * V_110 , unsigned long V_44 )
{
struct V_8 * V_81 = NULL ;
T_3 V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
T_6 V_259 = V_110 -> V_4 -> V_5 -> V_6 -> V_260 ;
V_21 += ( V_44 + V_259 - 1 ) & ~ ( V_259 - 1 ) ;
if ( V_21 > V_22 )
return 0 ;
F_82 ( V_3 , V_21 , V_22 , 0 , & V_81 ) ;
F_219 ( V_110 ) ;
F_53 ( V_3 , V_21 , V_22 ,
V_105 | V_77 | V_100 |
V_103 ,
1 , 1 , & V_81 , V_106 ) ;
return 0 ;
}
int F_229 ( struct V_195 * V_338 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
int V_58 = 1 ;
if ( F_102 ( V_3 , V_21 , V_22 ,
V_63 , 0 , NULL ) )
V_58 = 0 ;
else {
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
V_58 = F_53 ( V_3 , V_21 , V_22 ,
~ ( V_105 | V_339 ) ,
0 , 0 , NULL , V_34 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
else
V_58 = 1 ;
}
return V_58 ;
}
int F_230 ( struct V_195 * V_338 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
struct V_193 * V_194 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ( V_34 & V_87 ) &&
V_110 -> V_4 -> V_5 -> V_284 > 16 * 1024 * 1024 ) {
T_3 V_25 ;
while ( V_21 <= V_22 ) {
V_25 = V_22 - V_21 + 1 ;
F_231 ( & V_338 -> V_32 ) ;
V_194 = F_143 ( V_338 , V_21 , V_25 ) ;
if ( ! V_194 ) {
F_232 ( & V_338 -> V_32 ) ;
break;
}
if ( F_130 ( V_340 , & V_194 -> V_36 ) ||
V_194 -> V_21 != V_21 ) {
F_232 ( & V_338 -> V_32 ) ;
F_145 ( V_194 ) ;
break;
}
if ( ! F_102 ( V_3 , V_194 -> V_21 ,
F_177 ( V_194 ) - 1 ,
V_105 | V_341 ,
0 , NULL ) ) {
F_233 ( V_338 , V_194 ) ;
F_145 ( V_194 ) ;
}
V_21 = F_177 ( V_194 ) ;
F_232 ( & V_338 -> V_32 ) ;
F_145 ( V_194 ) ;
}
}
return F_229 ( V_338 , V_3 , V_110 , V_34 ) ;
}
static struct V_193 * F_234 ( struct V_117 * V_117 ,
T_3 V_44 ,
T_3 V_143 ,
T_9 * V_248 )
{
T_3 V_342 = F_117 ( V_117 ) -> V_43 -> V_342 ;
struct V_193 * V_194 ;
T_3 V_25 ;
if ( V_44 >= V_143 )
return NULL ;
while( 1 ) {
V_25 = V_143 - V_44 ;
if ( V_25 == 0 )
break;
V_25 = ( V_25 + V_342 - 1 ) & ~ ( V_342 - 1 ) ;
V_194 = V_248 ( V_117 , NULL , 0 , V_44 , V_25 , 0 ) ;
if ( F_176 ( V_194 ) )
return V_194 ;
if ( ! F_130 ( V_343 , & V_194 -> V_36 ) &&
V_194 -> V_202 != V_267 ) {
return V_194 ;
}
V_44 = F_177 ( V_194 ) ;
F_145 ( V_194 ) ;
if ( V_44 >= V_143 )
break;
}
return NULL ;
}
int F_235 ( struct V_117 * V_117 , struct V_344 * V_345 ,
T_13 V_21 , T_13 V_25 , T_9 * V_248 )
{
int V_58 = 0 ;
T_3 V_346 = V_21 ;
T_3 F_109 = V_21 + V_25 ;
T_14 V_36 = 0 ;
T_14 V_347 ;
T_3 V_143 ;
T_3 V_348 = 0 ;
T_3 V_349 = 0 ;
T_3 V_350 = F_167 ( V_117 ) ;
struct V_351 V_352 ;
struct V_193 * V_194 = NULL ;
struct V_8 * V_81 = NULL ;
struct V_353 * V_354 ;
struct V_355 * V_356 ;
int V_22 = 0 ;
T_3 V_357 = 0 ;
T_3 V_358 = 0 ;
T_3 V_359 = 0 ;
unsigned long V_360 ;
if ( V_25 == 0 )
return - V_361 ;
V_354 = F_236 () ;
if ( ! V_354 )
return - V_11 ;
V_354 -> V_362 = 1 ;
V_21 = F_237 ( V_21 , F_117 ( V_117 ) -> V_43 -> V_342 ) ;
V_25 = F_237 ( V_25 , F_117 ( V_117 ) -> V_43 -> V_342 ) ;
V_58 = F_238 ( NULL , F_117 ( V_117 ) -> V_43 ,
V_354 , F_239 ( V_117 ) , - 1 , 0 ) ;
if ( V_58 < 0 ) {
F_240 ( V_354 ) ;
return V_58 ;
}
F_27 ( ! V_58 ) ;
V_354 -> V_363 [ 0 ] -- ;
V_356 = F_241 ( V_354 -> V_364 [ 0 ] , V_354 -> V_363 [ 0 ] ,
struct V_355 ) ;
F_242 ( V_354 -> V_364 [ 0 ] , & V_352 , V_354 -> V_363 [ 0 ] ) ;
V_347 = F_243 ( & V_352 ) ;
if ( V_352 . V_365 != F_239 ( V_117 ) ||
V_347 != V_366 ) {
V_143 = ( T_3 ) - 1 ;
V_348 = V_350 ;
} else {
V_143 = V_352 . V_44 ;
V_348 = V_143 + 1 ;
}
F_240 ( V_354 ) ;
if ( V_143 < V_350 ) {
V_143 = ( T_3 ) - 1 ;
V_348 = V_350 ;
}
F_82 ( & F_117 ( V_117 ) -> V_152 , V_21 , V_21 + V_25 , 0 ,
& V_81 ) ;
V_194 = F_234 ( V_117 , V_21 , V_348 ,
V_248 ) ;
if ( ! V_194 )
goto V_89;
if ( F_244 ( V_194 ) ) {
V_58 = F_245 ( V_194 ) ;
goto V_89;
}
while ( ! V_22 ) {
T_3 V_367 ;
if ( V_194 -> V_21 >= F_109 || F_177 ( V_194 ) < V_346 )
break;
V_357 = F_109 ( V_194 -> V_21 , V_346 ) ;
V_367 = V_357 - V_194 -> V_21 ;
V_359 = F_177 ( V_194 ) ;
V_358 = V_359 - V_357 ;
V_360 = V_194 -> V_36 ;
V_349 = 0 ;
V_36 = 0 ;
V_346 = F_177 ( V_194 ) ;
if ( V_346 >= F_109 )
V_22 = 1 ;
if ( V_194 -> V_202 == V_368 ) {
V_22 = 1 ;
V_36 |= V_369 ;
} else if ( V_194 -> V_202 == V_268 ) {
V_36 |= ( V_370 |
V_371 ) ;
} else if ( V_194 -> V_202 == V_372 ) {
V_36 |= ( V_373 |
V_374 ) ;
} else {
V_349 = V_194 -> V_202 + V_367 ;
}
if ( F_130 ( V_203 , & V_194 -> V_36 ) )
V_36 |= V_375 ;
F_145 ( V_194 ) ;
V_194 = NULL ;
if ( ( V_357 >= V_143 ) || V_358 == ( T_3 ) - 1 ||
( V_143 == ( T_3 ) - 1 && V_350 <= V_359 ) ) {
V_36 |= V_369 ;
V_22 = 1 ;
}
V_194 = F_234 ( V_117 , V_346 , V_348 ,
V_248 ) ;
if ( F_244 ( V_194 ) ) {
V_58 = F_245 ( V_194 ) ;
goto V_89;
}
if ( ! V_194 ) {
V_36 |= V_369 ;
V_22 = 1 ;
}
V_58 = F_246 ( V_345 , V_357 , V_349 ,
V_358 , V_36 ) ;
if ( V_58 )
goto V_376;
}
V_376:
F_145 ( V_194 ) ;
V_89:
F_85 ( & F_117 ( V_117 ) -> V_152 , V_21 , V_21 + V_25 ,
& V_81 , V_106 ) ;
return V_58 ;
}
static void F_247 ( struct V_13 * V_16 )
{
#if V_35
unsigned long V_36 ;
F_19 ( & V_38 , V_36 ) ;
F_11 ( & V_16 -> V_19 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
if ( V_16 -> V_119 && V_16 -> V_119 != V_16 -> V_377 )
F_118 ( V_16 -> V_119 ) ;
F_12 ( V_12 , V_16 ) ;
}
static struct V_13 * F_248 ( struct V_2 * V_3 ,
T_3 V_21 ,
unsigned long V_25 ,
T_2 V_34 )
{
struct V_13 * V_16 = NULL ;
#if V_35
unsigned long V_36 ;
#endif
V_16 = F_249 ( V_12 , V_34 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_21 = V_21 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_304 = 0 ;
F_250 ( & V_16 -> V_32 ) ;
F_22 ( & V_16 -> V_378 , 0 ) ;
F_22 ( & V_16 -> V_379 , 0 ) ;
F_22 ( & V_16 -> V_380 , 0 ) ;
F_22 ( & V_16 -> V_381 , 0 ) ;
F_22 ( & V_16 -> V_382 , 0 ) ;
F_22 ( & V_16 -> V_383 , 0 ) ;
V_16 -> V_384 = 0 ;
F_23 ( & V_16 -> V_385 ) ;
F_23 ( & V_16 -> V_386 ) ;
#if V_35
F_19 ( & V_38 , V_36 ) ;
F_20 ( & V_16 -> V_19 , & V_24 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
F_16 ( & V_16 -> V_308 ) ;
F_22 ( & V_16 -> V_23 , 1 ) ;
F_22 ( & V_16 -> V_313 , 0 ) ;
if ( V_25 > V_387 ) {
struct V_110 * * V_119 ;
int V_185 = ( V_25 + V_131 - 1 ) >>
V_108 ;
V_119 = F_141 ( V_185 , V_34 ) ;
if ( ! V_119 ) {
F_247 ( V_16 ) ;
return NULL ;
}
V_16 -> V_119 = V_119 ;
} else {
V_16 -> V_119 = V_16 -> V_377 ;
}
return V_16 ;
}
struct V_13 * F_251 ( struct V_13 * V_388 )
{
unsigned long V_121 ;
struct V_110 * V_46 ;
struct V_13 * V_59 ;
unsigned long V_185 = F_135 ( V_388 -> V_21 , V_388 -> V_25 ) ;
V_59 = F_248 ( NULL , V_388 -> V_21 , V_388 -> V_25 , V_29 ) ;
if ( V_59 == NULL )
return NULL ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
V_46 = F_252 ( V_29 ) ;
F_56 ( ! V_46 ) ;
F_160 ( V_59 , V_46 ) ;
F_27 ( F_100 ( V_46 ) ) ;
F_113 ( V_46 ) ;
V_59 -> V_119 [ V_121 ] = V_46 ;
}
F_253 ( V_59 , V_388 , 0 , 0 , V_388 -> V_25 ) ;
F_197 ( V_389 , & V_59 -> V_304 ) ;
F_197 ( V_390 , & V_59 -> V_304 ) ;
return V_59 ;
}
struct V_13 * F_254 ( T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
unsigned long V_185 = F_135 ( 0 , V_25 ) ;
unsigned long V_121 ;
V_16 = F_248 ( NULL , V_21 , V_25 , V_29 ) ;
if ( ! V_16 )
return NULL ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
V_16 -> V_119 [ V_121 ] = F_252 ( V_29 ) ;
if ( ! V_16 -> V_119 [ V_121 ] )
goto V_79;
}
F_255 ( V_16 ) ;
F_256 ( V_16 , 0 ) ;
F_197 ( V_390 , & V_16 -> V_304 ) ;
return V_16 ;
V_79:
for (; V_121 > 0 ; V_121 -- )
F_257 ( V_16 -> V_119 [ V_121 - 1 ] ) ;
F_247 ( V_16 ) ;
return NULL ;
}
static int F_258 ( struct V_13 * V_16 )
{
return ( F_10 ( & V_16 -> V_313 ) ||
F_130 ( V_305 , & V_16 -> V_304 ) ||
F_130 ( V_309 , & V_16 -> V_304 ) ) ;
}
static void F_259 ( struct V_13 * V_16 ,
unsigned long V_391 )
{
unsigned long V_107 ;
unsigned long V_185 ;
struct V_110 * V_110 ;
int V_392 = ! F_130 ( V_390 , & V_16 -> V_304 ) ;
F_56 ( F_258 ( V_16 ) ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
V_107 = V_391 + V_185 ;
if ( V_391 >= V_107 )
return;
do {
V_107 -- ;
V_110 = F_136 ( V_16 , V_107 ) ;
if ( V_110 && V_392 ) {
F_54 ( & V_110 -> V_4 -> V_327 ) ;
if ( F_161 ( V_110 ) &&
V_110 -> V_37 == ( unsigned long ) V_16 ) {
F_56 ( F_130 ( V_309 , & V_16 -> V_304 ) ) ;
F_56 ( F_100 ( V_110 ) ) ;
F_56 ( F_186 ( V_110 ) ) ;
F_260 ( V_110 ) ;
F_164 ( V_110 , 0 ) ;
F_90 ( V_110 ) ;
}
F_58 ( & V_110 -> V_4 -> V_327 ) ;
}
if ( V_110 ) {
F_90 ( V_110 ) ;
}
} while ( V_107 != V_391 );
}
static inline void F_261 ( struct V_13 * V_16 )
{
F_259 ( V_16 , 0 ) ;
F_247 ( V_16 ) ;
}
static void F_262 ( struct V_13 * V_16 )
{
F_54 ( & V_16 -> V_308 ) ;
if ( ! F_263 ( V_393 , & V_16 -> V_304 ) )
F_66 ( & V_16 -> V_23 ) ;
F_58 ( & V_16 -> V_308 ) ;
}
static void F_264 ( struct V_13 * V_16 )
{
unsigned long V_185 , V_121 ;
F_262 ( V_16 ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
struct V_110 * V_46 = F_136 ( V_16 , V_121 ) ;
F_265 ( V_46 ) ;
}
}
struct V_13 * F_266 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
unsigned long V_185 = F_135 ( V_21 , V_25 ) ;
unsigned long V_121 ;
unsigned long V_107 = V_21 >> V_108 ;
struct V_13 * V_16 ;
struct V_13 * V_394 = NULL ;
struct V_110 * V_46 ;
struct V_26 * V_4 = V_3 -> V_4 ;
int V_212 = 1 ;
int V_58 ;
F_267 () ;
V_16 = F_268 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_213 ( & V_16 -> V_23 ) ) {
F_269 () ;
F_264 ( V_16 ) ;
return V_16 ;
}
F_269 () ;
V_16 = F_248 ( V_3 , V_21 , V_25 , V_106 ) ;
if ( ! V_16 )
return NULL ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ , V_107 ++ ) {
V_46 = F_270 ( V_4 , V_107 , V_106 ) ;
if ( ! V_46 )
goto V_395;
F_54 ( & V_4 -> V_327 ) ;
if ( F_161 ( V_46 ) ) {
V_394 = (struct V_13 * ) V_46 -> V_37 ;
if ( F_213 ( & V_394 -> V_23 ) ) {
F_58 ( & V_4 -> V_327 ) ;
F_97 ( V_46 ) ;
F_90 ( V_46 ) ;
F_264 ( V_394 ) ;
goto V_395;
}
F_260 ( V_46 ) ;
F_27 ( F_100 ( V_46 ) ) ;
F_90 ( V_46 ) ;
}
F_160 ( V_16 , V_46 ) ;
F_58 ( & V_4 -> V_327 ) ;
F_27 ( F_100 ( V_46 ) ) ;
F_265 ( V_46 ) ;
V_16 -> V_119 [ V_121 ] = V_46 ;
if ( ! F_168 ( V_46 ) )
V_212 = 0 ;
}
if ( V_212 )
F_197 ( V_389 , & V_16 -> V_304 ) ;
V_86:
V_58 = F_271 ( V_106 & ~ V_396 ) ;
if ( V_58 )
goto V_395;
F_54 ( & V_3 -> V_33 ) ;
V_58 = F_272 ( & V_3 -> V_28 , V_21 >> V_108 , V_16 ) ;
if ( V_58 == - V_69 ) {
V_394 = F_268 ( & V_3 -> V_28 ,
V_21 >> V_108 ) ;
if ( ! F_213 ( & V_394 -> V_23 ) ) {
F_58 ( & V_3 -> V_33 ) ;
F_273 () ;
V_394 = NULL ;
goto V_86;
}
F_58 ( & V_3 -> V_33 ) ;
F_273 () ;
F_264 ( V_394 ) ;
goto V_395;
}
F_262 ( V_16 ) ;
F_58 ( & V_3 -> V_33 ) ;
F_273 () ;
F_274 ( V_16 -> V_119 [ 0 ] ) ;
for ( V_121 = 1 ; V_121 < V_185 ; V_121 ++ ) {
V_46 = F_136 ( V_16 , V_121 ) ;
F_275 ( V_46 ) ;
F_97 ( V_46 ) ;
}
F_97 ( V_16 -> V_119 [ 0 ] ) ;
return V_16 ;
V_395:
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
if ( V_16 -> V_119 [ V_121 ] )
F_97 ( V_16 -> V_119 [ V_121 ] ) ;
}
F_27 ( ! F_26 ( & V_16 -> V_23 ) ) ;
F_261 ( V_16 ) ;
return V_394 ;
}
struct V_13 * F_276 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
F_267 () ;
V_16 = F_268 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_213 ( & V_16 -> V_23 ) ) {
F_269 () ;
F_264 ( V_16 ) ;
return V_16 ;
}
F_269 () ;
return NULL ;
}
static inline void F_277 ( struct V_397 * V_398 )
{
struct V_13 * V_16 =
F_278 ( V_398 , struct V_13 , V_397 ) ;
F_247 ( V_16 ) ;
}
static int F_279 ( struct V_13 * V_16 , T_2 V_34 )
{
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
if ( F_26 ( & V_16 -> V_23 ) ) {
if ( F_130 ( V_390 , & V_16 -> V_304 ) ) {
F_58 ( & V_16 -> V_308 ) ;
} else {
struct V_2 * V_3 = V_16 -> V_3 ;
F_58 ( & V_16 -> V_308 ) ;
F_54 ( & V_3 -> V_33 ) ;
F_280 ( & V_3 -> V_28 ,
V_16 -> V_21 >> V_108 ) ;
F_58 ( & V_3 -> V_33 ) ;
}
F_259 ( V_16 , 0 ) ;
F_281 ( & V_16 -> V_397 , F_277 ) ;
return 1 ;
}
F_58 ( & V_16 -> V_308 ) ;
return 0 ;
}
void F_214 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_54 ( & V_16 -> V_308 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_130 ( V_390 , & V_16 -> V_304 ) )
F_55 ( & V_16 -> V_23 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_130 ( V_399 , & V_16 -> V_304 ) &&
! F_258 ( V_16 ) &&
F_196 ( V_393 , & V_16 -> V_304 ) )
F_55 ( & V_16 -> V_23 ) ;
F_279 ( V_16 , V_29 ) ;
}
void F_282 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_54 ( & V_16 -> V_308 ) ;
F_197 ( V_399 , & V_16 -> V_304 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 && ! F_258 ( V_16 ) &&
F_196 ( V_393 , & V_16 -> V_304 ) )
F_55 ( & V_16 -> V_23 ) ;
F_279 ( V_16 , V_106 ) ;
}
void F_283 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
unsigned long V_185 ;
struct V_110 * V_110 ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
if ( ! F_100 ( V_110 ) )
continue;
F_99 ( V_110 ) ;
F_27 ( ! F_161 ( V_110 ) ) ;
F_105 ( V_110 ) ;
F_284 ( & V_110 -> V_4 -> V_400 ) ;
if ( ! F_100 ( V_110 ) ) {
F_285 ( & V_110 -> V_4 -> V_401 ,
F_286 ( V_110 ) ,
V_324 ) ;
}
F_287 ( & V_110 -> V_4 -> V_400 ) ;
F_184 ( V_110 ) ;
F_97 ( V_110 ) ;
}
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
}
int F_288 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
unsigned long V_185 ;
int V_402 = 0 ;
F_262 ( V_16 ) ;
V_402 = F_263 ( V_309 , & V_16 -> V_304 ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
F_27 ( ! F_130 ( V_393 , & V_16 -> V_304 ) ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ )
F_289 ( F_136 ( V_16 , V_121 ) ) ;
return V_402 ;
}
static int F_290 ( T_3 V_21 , T_3 V_25 )
{
if ( V_25 < V_131 )
return 1 ;
if ( V_21 & ( V_131 - 1 ) )
return 1 ;
if ( ( V_21 + V_25 ) & ( V_131 - 1 ) )
return 1 ;
return 0 ;
}
int F_291 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
struct V_110 * V_110 ;
unsigned long V_185 ;
F_201 ( V_389 , & V_16 -> V_304 ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
if ( V_110 )
F_148 ( V_110 ) ;
}
return 0 ;
}
int F_255 ( struct V_13 * V_16 )
{
unsigned long V_121 ;
struct V_110 * V_110 ;
unsigned long V_185 ;
F_197 ( V_389 , & V_16 -> V_304 ) ;
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = 0 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
F_113 ( V_110 ) ;
}
return 0 ;
}
int F_292 ( struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 )
{
struct V_110 * V_110 ;
int V_58 ;
int V_403 = 1 ;
int V_212 ;
unsigned long V_107 ;
if ( F_290 ( V_21 , V_22 - V_21 + 1 ) ) {
V_58 = F_102 ( V_3 , V_21 , V_22 ,
V_101 , 1 , NULL ) ;
if ( V_58 )
return 1 ;
}
while ( V_21 <= V_22 ) {
V_107 = V_21 >> V_108 ;
V_110 = F_88 ( V_3 -> V_4 , V_107 ) ;
if ( ! V_110 )
return 1 ;
V_212 = F_168 ( V_110 ) ;
F_90 ( V_110 ) ;
if ( ! V_212 ) {
V_403 = 0 ;
break;
}
V_21 += V_131 ;
}
return V_403 ;
}
int F_293 ( struct V_13 * V_16 )
{
return F_130 ( V_389 , & V_16 -> V_304 ) ;
}
int F_294 ( struct V_2 * V_3 ,
struct V_13 * V_16 , T_3 V_21 , int V_91 ,
T_9 * V_248 , int V_159 )
{
unsigned long V_121 ;
unsigned long V_404 ;
struct V_110 * V_110 ;
int V_79 ;
int V_58 = 0 ;
int V_405 = 0 ;
int V_406 = 1 ;
unsigned long V_185 ;
unsigned long V_407 = 0 ;
struct V_154 * V_154 = NULL ;
unsigned long V_201 = 0 ;
if ( F_130 ( V_389 , & V_16 -> V_304 ) )
return 0 ;
if ( V_21 ) {
F_27 ( V_21 < V_16 -> V_21 ) ;
V_404 = ( V_21 >> V_108 ) -
( V_16 -> V_21 >> V_108 ) ;
} else {
V_404 = 0 ;
}
V_185 = F_135 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_121 = V_404 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
if ( V_91 == V_408 ) {
if ( ! F_199 ( V_110 ) )
goto V_409;
} else {
F_99 ( V_110 ) ;
}
V_405 ++ ;
if ( ! F_168 ( V_110 ) ) {
V_407 ++ ;
V_406 = 0 ;
}
}
if ( V_406 ) {
if ( V_404 == 0 )
F_197 ( V_389 , & V_16 -> V_304 ) ;
goto V_409;
}
F_201 ( V_314 , & V_16 -> V_304 ) ;
V_16 -> V_410 = 0 ;
F_22 ( & V_16 -> V_313 , V_407 ) ;
for ( V_121 = V_404 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
if ( ! F_168 ( V_110 ) ) {
F_184 ( V_110 ) ;
V_79 = F_166 ( V_3 , V_110 ,
V_248 , & V_154 ,
V_159 , & V_201 ) ;
if ( V_79 )
V_58 = V_79 ;
} else {
F_97 ( V_110 ) ;
}
}
if ( V_154 ) {
V_79 = F_154 ( V_271 , V_154 , V_159 , V_201 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_58 || V_91 != V_411 )
return V_58 ;
for ( V_121 = V_404 ; V_121 < V_185 ; V_121 ++ ) {
V_110 = F_136 ( V_16 , V_121 ) ;
F_295 ( V_110 ) ;
if ( ! F_168 ( V_110 ) )
V_58 = - V_167 ;
}
return V_58 ;
V_409:
V_121 = V_404 ;
while ( V_405 > 0 ) {
V_110 = F_136 ( V_16 , V_121 ) ;
V_121 ++ ;
F_97 ( V_110 ) ;
V_405 -- ;
}
return V_58 ;
}
void F_296 ( struct V_13 * V_16 , void * V_412 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_413 ;
char * V_414 = ( char * ) V_412 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_136 ( V_16 , V_121 ) ;
V_250 = F_108 ( V_25 , ( V_131 - V_44 ) ) ;
V_413 = F_297 ( V_110 ) ;
memcpy ( V_414 , V_413 + V_44 , V_250 ) ;
V_414 += V_250 ;
V_25 -= V_250 ;
V_44 = 0 ;
V_121 ++ ;
}
}
int F_298 ( struct V_13 * V_16 , unsigned long V_21 ,
unsigned long V_416 , char * * V_338 ,
unsigned long * V_417 ,
unsigned long * V_418 )
{
T_6 V_44 = V_21 & ( V_131 - 1 ) ;
char * V_413 ;
struct V_110 * V_46 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_21 ) >> V_108 ;
unsigned long V_419 = ( V_415 + V_21 + V_416 - 1 ) >>
V_108 ;
if ( V_121 != V_419 )
return - V_361 ;
if ( V_121 == 0 ) {
V_44 = V_415 ;
* V_417 = 0 ;
} else {
V_44 = 0 ;
* V_417 = ( ( T_3 ) V_121 << V_108 ) - V_415 ;
}
if ( V_21 + V_416 > V_16 -> V_25 ) {
F_43 ( 1 , V_20 L_31
L_32 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , V_21 , V_416 ) ;
return - V_361 ;
}
V_46 = F_136 ( V_16 , V_121 ) ;
V_413 = F_297 ( V_46 ) ;
* V_338 = V_413 + V_44 ;
* V_418 = V_131 - V_44 ;
return 0 ;
}
int F_299 ( struct V_13 * V_16 , const void * V_420 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_413 ;
char * V_421 = ( char * ) V_420 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_21 ) >> V_108 ;
int V_58 = 0 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_136 ( V_16 , V_121 ) ;
V_250 = F_108 ( V_25 , ( V_131 - V_44 ) ) ;
V_413 = F_297 ( V_110 ) ;
V_58 = memcmp ( V_421 , V_413 + V_44 , V_250 ) ;
if ( V_58 )
break;
V_421 += V_250 ;
V_25 -= V_250 ;
V_44 = 0 ;
V_121 ++ ;
}
return V_58 ;
}
void F_300 ( struct V_13 * V_16 , const void * V_422 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_413 ;
char * V_388 = ( char * ) V_422 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_136 ( V_16 , V_121 ) ;
F_27 ( ! F_168 ( V_110 ) ) ;
V_250 = F_108 ( V_25 , V_131 - V_44 ) ;
V_413 = F_297 ( V_110 ) ;
memcpy ( V_413 + V_44 , V_388 , V_250 ) ;
V_388 += V_250 ;
V_25 -= V_250 ;
V_44 = 0 ;
V_121 ++ ;
}
}
void F_301 ( struct V_13 * V_16 , char V_423 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_413 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_21 ) >> V_108 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_136 ( V_16 , V_121 ) ;
F_27 ( ! F_168 ( V_110 ) ) ;
V_250 = F_108 ( V_25 , V_131 - V_44 ) ;
V_413 = F_297 ( V_110 ) ;
memset ( V_413 + V_44 , V_423 , V_250 ) ;
V_25 -= V_250 ;
V_44 = 0 ;
V_121 ++ ;
}
}
void F_253 ( struct V_13 * V_414 , struct V_13 * V_388 ,
unsigned long V_424 , unsigned long V_425 ,
unsigned long V_25 )
{
T_3 V_426 = V_414 -> V_25 ;
T_6 V_250 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_413 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_121 = ( V_415 + V_424 ) >> V_108 ;
F_27 ( V_388 -> V_25 != V_426 ) ;
V_44 = ( V_415 + V_424 ) &
( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_136 ( V_414 , V_121 ) ;
F_27 ( ! F_168 ( V_110 ) ) ;
V_250 = F_108 ( V_25 , ( unsigned long ) ( V_131 - V_44 ) ) ;
V_413 = F_297 ( V_110 ) ;
F_296 ( V_388 , V_413 + V_44 , V_425 , V_250 ) ;
V_425 += V_250 ;
V_25 -= V_250 ;
V_44 = 0 ;
V_121 ++ ;
}
}
static void F_302 ( struct V_110 * V_427 , struct V_110 * V_428 ,
unsigned long V_429 , unsigned long V_430 ,
unsigned long V_25 )
{
char * V_431 = F_297 ( V_427 ) ;
if ( V_427 == V_428 ) {
memmove ( V_431 + V_429 , V_431 + V_430 , V_25 ) ;
} else {
char * V_432 = F_297 ( V_428 ) ;
char * V_46 = V_431 + V_429 + V_25 ;
char * V_433 = V_432 + V_430 + V_25 ;
while ( V_25 -- )
* -- V_46 = * -- V_433 ;
}
}
static inline bool F_303 ( unsigned long V_388 , unsigned long V_414 , unsigned long V_25 )
{
unsigned long V_434 = ( V_388 > V_414 ) ? V_388 - V_414 : V_414 - V_388 ;
return V_434 < V_25 ;
}
static void F_304 ( struct V_110 * V_427 , struct V_110 * V_428 ,
unsigned long V_429 , unsigned long V_430 ,
unsigned long V_25 )
{
char * V_431 = F_297 ( V_427 ) ;
char * V_432 ;
int V_435 = 0 ;
if ( V_427 != V_428 ) {
V_432 = F_297 ( V_428 ) ;
} else {
V_432 = V_431 ;
if ( F_303 ( V_430 , V_429 , V_25 ) )
V_435 = 1 ;
}
if ( V_435 )
memmove ( V_431 + V_429 , V_432 + V_430 , V_25 ) ;
else
memcpy ( V_431 + V_429 , V_432 + V_430 , V_25 ) ;
}
void F_305 ( struct V_13 * V_414 , unsigned long V_424 ,
unsigned long V_425 , unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_436 ;
T_6 V_437 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_438 ;
unsigned long V_439 ;
if ( V_425 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_33
L_34 , V_425 , V_25 , V_414 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_424 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_35
L_34 , V_424 , V_25 , V_414 -> V_25 ) ;
F_56 ( 1 ) ;
}
while ( V_25 > 0 ) {
V_436 = ( V_415 + V_424 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_437 = ( V_415 + V_425 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_438 = ( V_415 + V_424 ) >> V_108 ;
V_439 = ( V_415 + V_425 ) >> V_108 ;
V_250 = F_108 ( V_25 , ( unsigned long ) ( V_131 -
V_437 ) ) ;
V_250 = F_96 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_304 ( F_136 ( V_414 , V_438 ) ,
F_136 ( V_414 , V_439 ) ,
V_436 , V_437 , V_250 ) ;
V_425 += V_250 ;
V_424 += V_250 ;
V_25 -= V_250 ;
}
}
void F_306 ( struct V_13 * V_414 , unsigned long V_424 ,
unsigned long V_425 , unsigned long V_25 )
{
T_6 V_250 ;
T_6 V_436 ;
T_6 V_437 ;
unsigned long V_440 = V_424 + V_25 - 1 ;
unsigned long V_441 = V_425 + V_25 - 1 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_438 ;
unsigned long V_439 ;
if ( V_425 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_33
L_36 , V_425 , V_25 , V_414 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_424 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_35
L_36 , V_424 , V_25 , V_414 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_424 < V_425 ) {
F_305 ( V_414 , V_424 , V_425 , V_25 ) ;
return;
}
while ( V_25 > 0 ) {
V_438 = ( V_415 + V_440 ) >> V_108 ;
V_439 = ( V_415 + V_441 ) >> V_108 ;
V_436 = ( V_415 + V_440 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_437 = ( V_415 + V_441 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_250 = F_96 (unsigned long, len, src_off_in_page + 1 ) ;
V_250 = F_108 ( V_250 , V_436 + 1 ) ;
F_302 ( F_136 ( V_414 , V_438 ) ,
F_136 ( V_414 , V_439 ) ,
V_436 - V_250 + 1 ,
V_437 - V_250 + 1 , V_250 ) ;
V_440 -= V_250 ;
V_441 -= V_250 ;
V_25 -= V_250 ;
}
}
int F_307 ( struct V_110 * V_110 , T_2 V_34 )
{
struct V_13 * V_16 ;
F_54 ( & V_110 -> V_4 -> V_327 ) ;
if ( ! F_161 ( V_110 ) ) {
F_58 ( & V_110 -> V_4 -> V_327 ) ;
return 1 ;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_56 ( ! V_16 ) ;
F_54 ( & V_16 -> V_308 ) ;
if ( F_10 ( & V_16 -> V_23 ) != 1 || F_258 ( V_16 ) ) {
F_58 ( & V_16 -> V_308 ) ;
F_58 ( & V_110 -> V_4 -> V_327 ) ;
return 0 ;
}
F_58 ( & V_110 -> V_4 -> V_327 ) ;
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
if ( ! F_196 ( V_393 , & V_16 -> V_304 ) ) {
F_58 ( & V_16 -> V_308 ) ;
return 0 ;
}
return F_279 ( V_16 , V_34 ) ;
}
