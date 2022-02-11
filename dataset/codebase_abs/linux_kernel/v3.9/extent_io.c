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
int F_87 ( struct V_107 * V_107 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_108 = V_21 >> V_109 ;
unsigned long V_110 = V_22 >> V_109 ;
struct V_111 * V_111 ;
while ( V_108 <= V_110 ) {
V_111 = F_88 ( V_107 -> V_112 , V_108 ) ;
F_56 ( ! V_111 ) ;
F_89 ( V_111 ) ;
F_90 ( V_111 ) ;
V_108 ++ ;
}
return 0 ;
}
int F_91 ( struct V_107 * V_107 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_108 = V_21 >> V_109 ;
unsigned long V_110 = V_22 >> V_109 ;
struct V_111 * V_111 ;
while ( V_108 <= V_110 ) {
V_111 = F_88 ( V_107 -> V_112 , V_108 ) ;
F_56 ( ! V_111 ) ;
F_92 ( V_111 ) ;
F_93 ( V_111 ) ;
F_90 ( V_111 ) ;
V_108 ++ ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_108 = V_21 >> V_109 ;
unsigned long V_110 = V_22 >> V_109 ;
struct V_111 * V_111 ;
while ( V_108 <= V_110 ) {
V_111 = F_88 ( V_3 -> V_4 , V_108 ) ;
F_56 ( ! V_111 ) ;
F_95 ( V_111 ) ;
F_90 ( V_111 ) ;
V_108 ++ ;
}
return 0 ;
}
struct V_8 * F_96 ( struct V_2 * V_3 ,
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
int F_97 ( struct V_2 * V_3 , T_3 V_21 ,
T_3 * V_113 , T_3 * V_114 , int V_65 ,
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
goto V_115;
V_54 = F_34 ( V_54 ) ;
}
F_25 ( * V_81 ) ;
* V_81 = NULL ;
goto V_89;
}
F_25 ( * V_81 ) ;
* V_81 = NULL ;
}
V_15 = F_96 ( V_3 , V_21 , V_65 ) ;
V_115:
if ( V_15 ) {
F_68 ( V_15 , V_81 ) ;
* V_113 = V_15 -> V_21 ;
* V_114 = V_15 -> V_22 ;
V_58 = 0 ;
}
V_89:
F_58 ( & V_3 -> V_32 ) ;
return V_58 ;
}
static T_5 T_3 F_98 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 * V_22 , T_3 V_116 ,
struct V_8 * * V_81 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_117 = * V_21 ;
T_3 V_68 = 0 ;
T_3 V_118 = 0 ;
F_54 ( & V_3 -> V_32 ) ;
V_45 = F_36 ( V_3 , V_117 ) ;
if ( ! V_45 ) {
if ( ! V_68 )
* V_22 = ( T_3 ) - 1 ;
goto V_89;
}
while ( 1 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_68 && ( V_15 -> V_21 != V_117 ||
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
V_117 = V_15 -> V_22 + 1 ;
V_45 = F_34 ( V_45 ) ;
if ( ! V_45 )
break;
V_118 += V_15 -> V_22 - V_15 -> V_21 + 1 ;
if ( V_118 >= V_116 )
break;
}
V_89:
F_58 ( & V_3 -> V_32 ) ;
return V_68 ;
}
static T_5 void F_99 ( struct V_107 * V_107 ,
struct V_111 * V_119 ,
T_3 V_21 , T_3 V_22 )
{
int V_58 ;
struct V_111 * V_120 [ 16 ] ;
unsigned long V_108 = V_21 >> V_109 ;
unsigned long V_110 = V_22 >> V_109 ;
unsigned long V_121 = V_110 - V_108 + 1 ;
int V_122 ;
if ( V_108 == V_119 -> V_108 && V_110 == V_108 )
return;
while ( V_121 > 0 ) {
V_58 = F_100 ( V_107 -> V_112 , V_108 ,
F_101 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_120 ) ;
for ( V_122 = 0 ; V_122 < V_58 ; V_122 ++ ) {
if ( V_120 [ V_122 ] != V_119 )
F_102 ( V_120 [ V_122 ] ) ;
F_90 ( V_120 [ V_122 ] ) ;
}
V_121 -= V_58 ;
V_108 += V_58 ;
F_59 () ;
}
}
static T_5 int F_103 ( struct V_107 * V_107 ,
struct V_111 * V_119 ,
T_3 V_123 ,
T_3 V_124 )
{
unsigned long V_108 = V_123 >> V_109 ;
unsigned long V_125 = V_108 ;
unsigned long V_110 = V_124 >> V_109 ;
unsigned long V_126 = 0 ;
struct V_111 * V_120 [ 16 ] ;
unsigned long V_127 ;
int V_58 ;
int V_122 ;
if ( V_108 == V_119 -> V_108 && V_108 == V_110 )
return 0 ;
V_127 = V_110 - V_108 + 1 ;
while ( V_127 > 0 ) {
V_58 = F_100 ( V_107 -> V_112 , V_108 ,
F_101 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_120 ) ;
if ( V_58 == 0 ) {
V_58 = - V_128 ;
goto V_129;
}
for ( V_122 = 0 ; V_122 < V_58 ; V_122 ++ ) {
if ( V_120 [ V_122 ] != V_119 ) {
F_104 ( V_120 [ V_122 ] ) ;
if ( ! F_105 ( V_120 [ V_122 ] ) ||
V_120 [ V_122 ] -> V_4 != V_107 -> V_112 ) {
V_58 = - V_128 ;
F_102 ( V_120 [ V_122 ] ) ;
F_90 ( V_120 [ V_122 ] ) ;
goto V_129;
}
}
F_90 ( V_120 [ V_122 ] ) ;
V_126 ++ ;
}
V_127 -= V_58 ;
V_108 += V_58 ;
F_59 () ;
}
V_58 = 0 ;
V_129:
if ( V_58 && V_126 ) {
F_99 ( V_107 , V_119 ,
V_123 ,
( ( T_3 ) ( V_125 + V_126 - 1 ) ) <<
V_109 ) ;
}
return V_58 ;
}
static T_5 T_3 F_106 ( struct V_107 * V_107 ,
struct V_2 * V_3 ,
struct V_111 * V_119 ,
T_3 * V_21 , T_3 * V_22 ,
T_3 V_116 )
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
V_68 = F_98 ( V_3 , & V_123 , & V_124 ,
V_116 , & V_81 ) ;
if ( ! V_68 || V_124 <= * V_21 ) {
* V_21 = V_123 ;
* V_22 = V_124 ;
F_25 ( V_81 ) ;
return V_68 ;
}
if ( V_123 < * V_21 )
V_123 = * V_21 ;
if ( V_124 + 1 - V_123 > V_116 && V_130 )
V_124 = V_123 + V_131 - 1 ;
V_58 = F_103 ( V_107 , V_119 ,
V_123 , V_124 ) ;
if ( V_58 == - V_128 ) {
F_25 ( V_81 ) ;
if ( ! V_130 ) {
unsigned long V_44 = ( * V_21 ) & ( V_131 - 1 ) ;
V_116 = V_131 - V_44 ;
V_130 = 1 ;
goto V_86;
} else {
V_68 = 0 ;
goto V_132;
}
}
F_56 ( V_58 ) ;
F_82 ( V_3 , V_123 , V_124 , 0 , & V_81 ) ;
V_58 = F_107 ( V_3 , V_123 , V_124 ,
V_100 , 1 , V_81 ) ;
if ( ! V_58 ) {
F_85 ( V_3 , V_123 , V_124 ,
& V_81 , V_106 ) ;
F_99 ( V_107 , V_119 ,
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
int F_108 ( struct V_107 * V_107 ,
struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 , struct V_111 * V_119 ,
unsigned long V_133 )
{
int V_58 ;
struct V_111 * V_120 [ 16 ] ;
unsigned long V_108 = V_21 >> V_109 ;
unsigned long V_110 = V_22 >> V_109 ;
unsigned long V_121 = V_110 - V_108 + 1 ;
int V_122 ;
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
while ( V_121 > 0 ) {
V_58 = F_100 ( V_107 -> V_112 , V_108 ,
F_101 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_120 ) ;
for ( V_122 = 0 ; V_122 < V_58 ; V_122 ++ ) {
if ( V_133 & V_140 )
F_109 ( V_120 [ V_122 ] ) ;
if ( V_120 [ V_122 ] == V_119 ) {
F_90 ( V_120 [ V_122 ] ) ;
continue;
}
if ( V_133 & V_135 )
F_89 ( V_120 [ V_122 ] ) ;
if ( V_133 & V_138 )
F_95 ( V_120 [ V_122 ] ) ;
if ( V_133 & V_139 )
F_110 ( V_120 [ V_122 ] ) ;
if ( V_133 & V_137 )
F_102 ( V_120 [ V_122 ] ) ;
F_90 ( V_120 [ V_122 ] ) ;
}
V_121 -= V_58 ;
V_108 += V_58 ;
F_59 () ;
}
return 0 ;
}
T_3 F_111 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 V_141 , T_3 V_116 ,
unsigned long V_65 , int V_142 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_117 = * V_21 ;
T_3 V_118 = 0 ;
T_3 V_143 = 0 ;
int V_68 = 0 ;
if ( V_141 <= V_117 ) {
F_27 ( 1 ) ;
return 0 ;
}
F_54 ( & V_3 -> V_32 ) ;
if ( V_117 == 0 && V_65 == V_77 ) {
V_118 = V_3 -> V_31 ;
goto V_89;
}
V_45 = F_36 ( V_3 , V_117 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_30 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_141 )
break;
if ( V_142 && V_68 && V_15 -> V_21 > V_143 + 1 )
break;
if ( V_15 -> V_22 >= V_117 && ( V_15 -> V_15 & V_65 ) == V_65 ) {
V_118 += F_112 ( V_141 , V_15 -> V_22 ) + 1 -
F_113 ( V_117 , V_15 -> V_21 ) ;
if ( V_118 >= V_116 )
break;
if ( ! V_68 ) {
* V_21 = F_113 ( V_117 , V_15 -> V_21 ) ;
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
return V_118 ;
}
int F_114 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_37 )
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
int F_115 ( struct V_2 * V_3 , T_3 V_21 , T_3 * V_37 )
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
int F_107 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
static void F_116 ( struct V_2 * V_3 , struct V_111 * V_111 )
{
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( F_107 ( V_3 , V_21 , V_22 , V_101 , 1 , NULL ) )
F_118 ( V_111 ) ;
}
static void F_119 ( struct V_2 * V_3 , struct V_111 * V_111 )
{
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ! F_107 ( V_3 , V_21 , V_22 , V_105 , 0 , NULL ) )
F_102 ( V_111 ) ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_111 * V_111 )
{
F_110 ( V_111 ) ;
}
static int F_121 ( struct V_107 * V_107 , struct V_147 * V_148 ,
int V_149 )
{
int V_58 ;
int V_79 = 0 ;
struct V_2 * V_150 = & F_122 ( V_107 ) -> V_151 ;
F_114 ( V_150 , V_148 -> V_21 , 0 ) ;
V_58 = F_75 ( V_150 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 )
V_79 = V_58 ;
V_58 = F_75 ( & F_122 ( V_107 ) -> V_152 , V_148 -> V_21 ,
V_148 -> V_21 + V_148 -> V_25 - 1 ,
V_153 , V_106 ) ;
if ( V_58 && ! V_79 )
V_79 = V_58 ;
F_123 ( V_148 ) ;
return V_79 ;
}
static void F_124 ( struct V_154 * V_154 , int V_79 )
{
F_125 ( V_154 -> V_155 ) ;
}
int F_126 ( struct V_1 * V_156 , T_3 V_21 ,
T_3 V_157 , T_3 V_158 , struct V_111 * V_111 ,
int V_159 )
{
struct V_154 * V_154 ;
struct V_160 * V_161 ;
F_127 ( V_162 ) ;
T_3 V_163 = 0 ;
T_3 V_164 ;
struct V_165 * V_166 = NULL ;
struct V_167 * V_168 = & V_156 -> V_169 ;
int V_58 ;
F_56 ( ! V_159 ) ;
if ( F_128 ( V_168 , V_158 , V_157 , V_159 ) )
return 0 ;
V_154 = F_129 ( V_106 , 1 ) ;
if ( ! V_154 )
return - V_170 ;
V_154 -> V_155 = & V_162 ;
V_154 -> V_171 = F_124 ;
V_154 -> V_172 = 0 ;
V_163 = V_157 ;
V_58 = F_130 ( V_156 , V_173 , V_158 ,
& V_163 , & V_166 , V_159 ) ;
if ( V_58 ) {
F_131 ( V_154 ) ;
return - V_170 ;
}
F_56 ( V_159 != V_166 -> V_159 ) ;
V_164 = V_166 -> V_174 [ V_159 - 1 ] . V_175 >> 9 ;
V_154 -> V_176 = V_164 ;
V_161 = V_166 -> V_174 [ V_159 - 1 ] . V_161 ;
F_123 ( V_166 ) ;
if ( ! V_161 || ! V_161 -> V_177 || ! V_161 -> V_178 ) {
F_131 ( V_154 ) ;
return - V_170 ;
}
V_154 -> V_179 = V_161 -> V_177 ;
F_132 ( V_154 , V_111 , V_157 , V_21 - F_117 ( V_111 ) ) ;
F_133 ( V_180 , V_154 ) ;
F_134 ( & V_162 ) ;
if ( ! F_135 ( V_181 , & V_154 -> V_182 ) ) {
F_131 ( V_154 ) ;
F_136 ( V_161 , V_183 ) ;
return - V_170 ;
}
F_137 ( V_184 L_13
L_14 , V_111 -> V_4 -> V_5 -> V_185 ,
V_21 , F_138 ( V_161 -> V_186 ) , V_164 ) ;
F_131 ( V_154 ) ;
return 0 ;
}
int F_139 ( struct V_187 * V_43 , struct V_13 * V_16 ,
int V_159 )
{
T_3 V_21 = V_16 -> V_21 ;
unsigned long V_122 , V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
int V_58 = 0 ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
struct V_111 * V_46 = F_141 ( V_16 , V_122 ) ;
V_58 = F_126 ( V_43 -> V_156 , V_21 , V_131 ,
V_21 , V_46 , V_159 ) ;
if ( V_58 )
break;
V_21 += V_131 ;
}
return V_58 ;
}
static int F_142 ( T_3 V_21 , struct V_111 * V_111 )
{
T_3 V_37 ;
T_3 V_189 ;
struct V_147 * V_190 ;
struct V_1 * V_156 ;
struct V_8 * V_15 ;
int V_191 ;
int V_149 = 0 ;
int V_58 ;
struct V_107 * V_107 = V_111 -> V_4 -> V_5 ;
V_37 = 0 ;
V_58 = F_111 ( & F_122 ( V_107 ) -> V_151 , & V_37 ,
( T_3 ) - 1 , 1 , V_77 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_58 = F_115 ( & F_122 ( V_107 ) -> V_151 , V_21 ,
& V_189 ) ;
if ( V_58 )
return 0 ;
V_190 = (struct V_147 * ) ( unsigned long ) V_189 ;
F_56 ( ! V_190 -> V_192 ) ;
if ( V_190 -> V_193 ) {
F_143 ( L_15 ,
V_190 -> V_21 ) ;
V_149 = 1 ;
goto V_89;
}
F_54 ( & F_122 ( V_107 ) -> V_152 . V_32 ) ;
V_15 = F_96 ( & F_122 ( V_107 ) -> V_152 ,
V_190 -> V_21 ,
V_105 ) ;
F_58 ( & F_122 ( V_107 ) -> V_152 . V_32 ) ;
if ( V_15 && V_15 -> V_21 == V_190 -> V_21 ) {
V_156 = F_122 ( V_107 ) -> V_43 -> V_156 ;
V_191 = F_144 ( V_156 , V_190 -> V_158 ,
V_190 -> V_25 ) ;
if ( V_191 > 1 ) {
V_58 = F_126 ( V_156 , V_21 , V_190 -> V_25 ,
V_190 -> V_158 , V_111 ,
V_190 -> V_194 ) ;
V_149 = ! V_58 ;
}
V_58 = 0 ;
}
V_89:
if ( ! V_58 )
V_58 = F_121 ( V_107 , V_190 , V_149 ) ;
return V_58 ;
}
static int F_145 ( struct V_154 * V_195 , struct V_111 * V_111 ,
T_3 V_21 , T_3 V_22 , int V_194 ,
struct V_8 * V_15 )
{
struct V_147 * V_190 = NULL ;
T_3 V_37 ;
struct V_196 * V_197 ;
struct V_107 * V_107 = V_111 -> V_4 -> V_5 ;
struct V_2 * V_150 = & F_122 ( V_107 ) -> V_151 ;
struct V_2 * V_3 = & F_122 ( V_107 ) -> V_152 ;
struct V_198 * V_199 = & F_122 ( V_107 ) -> V_200 ;
struct V_154 * V_154 ;
int V_191 ;
int V_58 ;
int V_201 ;
T_3 V_158 ;
F_56 ( V_195 -> V_202 & V_203 ) ;
V_58 = F_115 ( V_150 , V_21 , & V_37 ) ;
if ( V_58 ) {
V_190 = F_146 ( sizeof( * V_190 ) , V_106 ) ;
if ( ! V_190 )
return - V_11 ;
V_190 -> V_21 = V_21 ;
V_190 -> V_25 = V_22 - V_21 + 1 ;
V_190 -> V_192 = 0 ;
V_190 -> V_204 = 0 ;
V_190 -> V_193 = 0 ;
F_147 ( & V_199 -> V_32 ) ;
V_197 = F_148 ( V_199 , V_21 , V_190 -> V_25 ) ;
if ( ! V_197 ) {
F_149 ( & V_199 -> V_32 ) ;
F_123 ( V_190 ) ;
return - V_170 ;
}
if ( V_197 -> V_21 > V_21 || V_197 -> V_21 + V_197 -> V_25 < V_21 ) {
F_150 ( V_197 ) ;
V_197 = NULL ;
}
F_149 ( & V_199 -> V_32 ) ;
if ( ! V_197 ) {
F_123 ( V_190 ) ;
return - V_170 ;
}
V_158 = V_21 - V_197 -> V_21 ;
V_158 = V_197 -> V_205 + V_158 ;
if ( F_135 ( V_206 , & V_197 -> V_36 ) ) {
V_158 = V_197 -> V_205 ;
V_190 -> V_204 = V_207 ;
F_151 ( & V_190 -> V_204 ,
V_197 -> V_208 ) ;
}
F_143 ( L_16
L_17 , V_158 , V_21 , V_190 -> V_25 ) ;
V_190 -> V_158 = V_158 ;
F_150 ( V_197 ) ;
V_58 = F_74 ( V_150 , V_21 , V_22 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 >= 0 )
V_58 = F_114 ( V_150 , V_21 ,
( T_3 ) ( unsigned long ) V_190 ) ;
if ( V_58 >= 0 )
V_58 = F_74 ( V_3 , V_21 , V_22 , V_153 ,
V_106 ) ;
if ( V_58 < 0 ) {
F_123 ( V_190 ) ;
return V_58 ;
}
} else {
V_190 = (struct V_147 * ) ( unsigned long ) V_37 ;
F_143 ( L_18
L_19 ,
V_190 -> V_158 , V_190 -> V_21 , V_190 -> V_25 ,
V_190 -> V_193 ) ;
}
V_191 = F_144 ( F_122 ( V_107 ) -> V_43 -> V_156 ,
V_190 -> V_158 , V_190 -> V_25 ) ;
if ( V_191 == 1 ) {
F_143 ( L_20
L_21
L_22 , V_15 , V_191 ,
V_190 -> V_192 , V_194 ) ;
F_121 ( V_107 , V_190 , 0 ) ;
return - V_170 ;
}
if ( ! V_15 ) {
F_54 ( & V_3 -> V_32 ) ;
V_15 = F_96 ( V_3 , V_190 -> V_21 ,
V_105 ) ;
if ( V_15 && V_15 -> V_21 != V_190 -> V_21 )
V_15 = NULL ;
F_58 ( & V_3 -> V_32 ) ;
}
if ( V_195 -> V_209 > 1 ) {
F_56 ( V_190 -> V_193 ) ;
V_190 -> V_193 = 1 ;
V_190 -> V_192 = V_194 ;
V_201 = V_210 | V_211 ;
} else {
if ( V_190 -> V_193 ) {
F_56 ( V_190 -> V_192 != V_194 ) ;
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
F_143 ( L_23
L_24 , V_15 ,
V_191 , V_190 -> V_192 , V_194 ) ;
F_121 ( V_107 , V_190 , 0 ) ;
return - V_170 ;
}
V_154 = F_129 ( V_106 , 1 ) ;
if ( ! V_154 ) {
F_121 ( V_107 , V_190 , 0 ) ;
return - V_170 ;
}
V_154 -> V_155 = V_15 ;
V_154 -> V_171 = V_195 -> V_171 ;
V_154 -> V_176 = V_190 -> V_158 >> 9 ;
V_154 -> V_179 = F_122 ( V_107 ) -> V_43 -> V_156 -> V_212 -> V_213 ;
V_154 -> V_172 = 0 ;
F_132 ( V_154 , V_111 , V_190 -> V_25 , V_21 - F_117 ( V_111 ) ) ;
F_143 ( L_25
L_26 , V_201 ,
V_190 -> V_192 , V_191 , V_190 -> V_193 ) ;
V_58 = V_3 -> V_30 -> V_214 ( V_107 , V_201 , V_154 ,
V_190 -> V_192 ,
V_190 -> V_204 , 0 ) ;
return V_58 ;
}
int F_152 ( struct V_111 * V_111 , int V_79 , T_3 V_21 , T_3 V_22 )
{
int V_215 = ( V_79 == 0 ) ;
struct V_2 * V_3 ;
int V_58 ;
V_3 = & F_122 ( V_111 -> V_4 -> V_5 ) -> V_152 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 ) {
V_58 = V_3 -> V_30 -> V_216 ( V_111 , V_21 ,
V_22 , NULL , V_215 ) ;
if ( V_58 )
V_215 = 0 ;
}
if ( ! V_215 ) {
F_153 ( V_111 ) ;
F_154 ( V_111 ) ;
}
return 0 ;
}
static void F_155 ( struct V_154 * V_154 , int V_79 )
{
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_220 ;
do {
struct V_111 * V_111 = V_218 -> V_221 ;
V_3 = & F_122 ( V_111 -> V_4 -> V_5 ) -> V_152 ;
V_21 = F_117 ( V_111 ) + V_218 -> V_222 ;
V_22 = V_21 + V_218 -> V_223 - 1 ;
if ( V_218 -> V_222 == 0 && V_218 -> V_223 == V_131 )
V_220 = 1 ;
else
V_220 = 0 ;
if ( -- V_218 >= V_154 -> V_219 )
F_156 ( & V_218 -> V_221 -> V_36 ) ;
if ( F_152 ( V_111 , V_79 , V_21 , V_22 ) )
continue;
if ( V_220 )
F_110 ( V_111 ) ;
else
F_120 ( V_3 , V_111 ) ;
} while ( V_218 >= V_154 -> V_219 );
F_131 ( V_154 ) ;
}
static void F_157 ( struct V_154 * V_154 , int V_79 )
{
int V_215 = F_135 ( V_181 , & V_154 -> V_182 ) ;
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
struct V_111 * V_111 = V_218 -> V_221 ;
struct V_8 * V_82 = NULL ;
struct V_8 * V_15 ;
F_143 ( L_27
L_28 , ( T_3 ) V_154 -> V_176 , V_79 ,
( long int ) V_154 -> V_179 ) ;
V_3 = & F_122 ( V_111 -> V_4 -> V_5 ) -> V_152 ;
V_21 = F_117 ( V_111 ) + V_218 -> V_222 ;
V_22 = V_21 + V_218 -> V_223 - 1 ;
if ( V_218 -> V_222 == 0 && V_218 -> V_223 == V_131 )
V_220 = 1 ;
else
V_220 = 0 ;
if ( ++ V_218 <= V_224 )
F_156 ( & V_218 -> V_221 -> V_36 ) ;
F_54 ( & V_3 -> V_32 ) ;
V_15 = F_96 ( V_3 , V_21 , V_105 ) ;
if ( V_15 && V_15 -> V_21 == V_21 ) {
F_68 ( V_15 , & V_82 ) ;
}
F_58 ( & V_3 -> V_32 ) ;
V_225 = ( int ) ( unsigned long ) V_154 -> V_179 ;
if ( V_215 && V_3 -> V_30 && V_3 -> V_30 -> V_226 ) {
V_58 = V_3 -> V_30 -> V_226 ( V_111 , V_21 , V_22 ,
V_15 , V_225 ) ;
if ( V_58 )
V_215 = 0 ;
else
F_142 ( V_21 , V_111 ) ;
}
if ( ! V_215 && V_3 -> V_30 && V_3 -> V_30 -> V_227 ) {
V_58 = V_3 -> V_30 -> V_227 ( V_111 , V_225 ) ;
if ( ! V_58 && ! V_79 &&
F_135 ( V_181 , & V_154 -> V_182 ) )
V_215 = 1 ;
} else if ( ! V_215 ) {
V_58 = F_145 ( V_154 , V_111 , V_21 , V_22 , V_225 , NULL ) ;
if ( V_58 == 0 ) {
V_215 =
F_135 ( V_181 , & V_154 -> V_182 ) ;
if ( V_79 )
V_215 = 0 ;
F_69 ( & V_82 ) ;
continue;
}
}
if ( V_215 && V_3 -> V_228 ) {
F_80 ( V_3 , V_21 , V_22 , & V_82 ,
V_29 ) ;
}
F_85 ( V_3 , V_21 , V_22 , & V_82 , V_29 ) ;
if ( V_220 ) {
if ( V_215 ) {
F_118 ( V_111 ) ;
} else {
F_153 ( V_111 ) ;
F_154 ( V_111 ) ;
}
F_102 ( V_111 ) ;
} else {
if ( V_215 ) {
F_116 ( V_3 , V_111 ) ;
} else {
F_153 ( V_111 ) ;
F_154 ( V_111 ) ;
}
F_119 ( V_3 , V_111 ) ;
}
} while ( V_218 <= V_224 );
F_131 ( V_154 ) ;
}
struct V_154 *
F_158 ( struct V_229 * V_177 , T_3 V_230 , int V_231 ,
T_2 V_232 )
{
struct V_154 * V_154 ;
V_154 = F_129 ( V_232 , V_231 ) ;
if ( V_154 == NULL && ( V_233 -> V_36 & V_234 ) ) {
while ( ! V_154 && ( V_231 /= 2 ) )
V_154 = F_129 ( V_232 , V_231 ) ;
}
if ( V_154 ) {
V_154 -> V_172 = 0 ;
V_154 -> V_179 = V_177 ;
V_154 -> V_176 = V_230 ;
}
return V_154 ;
}
static int T_4 F_159 ( int V_235 , struct V_154 * V_154 ,
int V_159 , unsigned long V_204 )
{
int V_58 = 0 ;
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_111 * V_111 = V_218 -> V_221 ;
struct V_2 * V_3 = V_154 -> V_155 ;
T_3 V_21 ;
V_21 = F_117 ( V_111 ) + V_218 -> V_222 ;
V_154 -> V_155 = NULL ;
F_160 ( V_154 ) ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_58 = V_3 -> V_30 -> V_214 ( V_111 -> V_4 -> V_5 , V_235 , V_154 ,
V_159 , V_204 , V_21 ) ;
else
F_133 ( V_235 , V_154 ) ;
if ( F_161 ( V_154 , V_236 ) )
V_58 = - V_237 ;
F_131 ( V_154 ) ;
return V_58 ;
}
static int F_162 ( int V_235 , struct V_2 * V_3 , struct V_111 * V_111 ,
unsigned long V_44 , T_6 V_238 , struct V_154 * V_154 ,
unsigned long V_204 )
{
int V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_239 )
V_58 = V_3 -> V_30 -> V_239 ( V_235 , V_111 , V_44 , V_238 , V_154 ,
V_204 ) ;
F_56 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_163 ( int V_235 , struct V_2 * V_3 ,
struct V_111 * V_111 , T_7 V_164 ,
T_6 V_238 , unsigned long V_44 ,
struct V_229 * V_177 ,
struct V_154 * * V_240 ,
unsigned long V_241 ,
T_8 V_242 ,
int V_159 ,
unsigned long V_243 ,
unsigned long V_204 )
{
int V_58 = 0 ;
struct V_154 * V_154 ;
int V_244 ;
int V_142 = 0 ;
int V_245 = V_204 & V_207 ;
int V_246 = V_243 & V_207 ;
T_6 V_247 = F_101 ( T_6 , V_238 , V_131 ) ;
if ( V_240 && * V_240 ) {
V_154 = * V_240 ;
if ( V_246 )
V_142 = V_154 -> V_176 == V_164 ;
else
V_142 = V_154 -> V_176 + ( V_154 -> V_172 >> 9 ) ==
V_164 ;
if ( V_243 != V_204 || ! V_142 ||
F_162 ( V_235 , V_3 , V_111 , V_44 , V_247 , V_154 , V_204 ) ||
F_132 ( V_154 , V_111 , V_247 , V_44 ) < V_247 ) {
V_58 = F_159 ( V_235 , V_154 , V_159 ,
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
V_244 = F_164 ( V_177 ) ;
V_154 = F_158 ( V_177 , V_164 , V_244 , V_106 | V_249 ) ;
if ( ! V_154 )
return - V_11 ;
F_132 ( V_154 , V_111 , V_247 , V_44 ) ;
V_154 -> V_171 = V_242 ;
V_154 -> V_155 = V_3 ;
if ( V_240 )
* V_240 = V_154 ;
else
V_58 = F_159 ( V_235 , V_154 , V_159 , V_204 ) ;
return V_58 ;
}
void F_165 ( struct V_13 * V_16 , struct V_111 * V_111 )
{
if ( ! F_166 ( V_111 ) ) {
F_167 ( V_111 ) ;
F_168 ( V_111 ) ;
F_169 ( V_111 , ( unsigned long ) V_16 ) ;
} else {
F_27 ( V_111 -> V_37 != ( unsigned long ) V_16 ) ;
}
}
void F_170 ( struct V_111 * V_111 )
{
if ( ! F_166 ( V_111 ) ) {
F_167 ( V_111 ) ;
F_168 ( V_111 ) ;
F_169 ( V_111 , V_250 ) ;
}
}
static int F_171 ( struct V_2 * V_3 ,
struct V_111 * V_111 ,
T_9 * V_251 ,
struct V_154 * * V_154 , int V_159 ,
unsigned long * V_204 )
{
struct V_107 * V_107 = V_111 -> V_4 -> V_5 ;
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_252 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_172 ( V_107 ) ;
T_3 V_205 ;
T_3 V_256 ;
T_7 V_164 ;
struct V_196 * V_197 ;
struct V_229 * V_177 ;
struct V_257 * V_258 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_260 ;
T_6 V_261 ;
T_6 V_262 = V_107 -> V_6 -> V_263 ;
unsigned long V_264 = 0 ;
F_170 ( V_111 ) ;
if ( ! F_173 ( V_111 ) ) {
if ( F_174 ( V_111 ) == 0 ) {
F_56 ( V_262 != V_265 ) ;
goto V_89;
}
}
V_22 = V_252 ;
while ( 1 ) {
F_83 ( V_3 , V_21 , V_22 ) ;
V_258 = F_175 ( V_107 , V_21 ) ;
if ( ! V_258 )
break;
F_86 ( V_3 , V_21 , V_22 ) ;
F_176 ( V_107 , V_258 , 1 ) ;
F_177 ( V_258 ) ;
}
if ( V_111 -> V_108 == V_255 >> V_109 ) {
char * V_266 ;
T_6 V_267 = V_255 & ( V_131 - 1 ) ;
if ( V_267 ) {
V_260 = V_131 - V_267 ;
V_266 = F_178 ( V_111 ) ;
memset ( V_266 + V_267 , 0 , V_260 ) ;
F_179 ( V_111 ) ;
F_180 ( V_266 ) ;
}
}
while ( V_253 <= V_22 ) {
unsigned long V_268 = ( V_255 >> V_109 ) + 1 ;
if ( V_253 >= V_255 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_260 = V_131 - V_259 ;
V_266 = F_178 ( V_111 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_179 ( V_111 ) ;
F_180 ( V_266 ) ;
F_80 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_85 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
break;
}
V_197 = V_251 ( V_107 , V_111 , V_259 , V_253 ,
V_22 - V_253 + 1 , 0 ) ;
if ( F_181 ( V_197 ) ) {
F_154 ( V_111 ) ;
F_86 ( V_3 , V_253 , V_22 ) ;
break;
}
V_254 = V_253 - V_197 -> V_21 ;
F_56 ( F_182 ( V_197 ) <= V_253 ) ;
F_56 ( V_22 < V_253 ) ;
if ( F_135 ( V_206 , & V_197 -> V_36 ) ) {
V_264 = V_207 ;
F_151 ( & V_264 ,
V_197 -> V_208 ) ;
}
V_260 = F_112 ( F_182 ( V_197 ) - V_253 , V_22 - V_253 + 1 ) ;
V_256 = F_112 ( F_182 ( V_197 ) - 1 , V_22 ) ;
V_260 = F_183 ( V_260 , V_262 ) ;
if ( V_264 & V_207 ) {
V_261 = V_197 -> V_269 ;
V_164 = V_197 -> V_205 >> 9 ;
} else {
V_164 = ( V_197 -> V_205 + V_254 ) >> 9 ;
V_261 = V_260 ;
}
V_177 = V_197 -> V_177 ;
V_205 = V_197 -> V_205 ;
if ( F_135 ( V_270 , & V_197 -> V_36 ) )
V_205 = V_271 ;
F_150 ( V_197 ) ;
V_197 = NULL ;
if ( V_205 == V_271 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_266 = F_178 ( V_111 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_179 ( V_111 ) ;
F_180 ( V_266 ) ;
F_80 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_85 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( F_107 ( V_3 , V_253 , V_256 ,
V_101 , 1 , NULL ) ) {
F_116 ( V_3 , V_111 ) ;
F_86 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( V_205 == V_272 ) {
F_154 ( V_111 ) ;
F_86 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
V_268 -= V_111 -> V_108 ;
V_58 = F_163 ( V_273 , V_3 , V_111 ,
V_164 , V_261 , V_259 ,
V_177 , V_154 , V_268 ,
F_157 , V_159 ,
* V_204 ,
V_264 ) ;
if ( ! V_58 ) {
V_244 ++ ;
* V_204 = V_264 ;
} else {
F_154 ( V_111 ) ;
F_86 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
}
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
}
V_89:
if ( ! V_244 ) {
if ( ! F_184 ( V_111 ) )
F_118 ( V_111 ) ;
F_102 ( V_111 ) ;
}
return 0 ;
}
int F_185 ( struct V_2 * V_3 , struct V_111 * V_111 ,
T_9 * V_251 , int V_159 )
{
struct V_154 * V_154 = NULL ;
unsigned long V_204 = 0 ;
int V_58 ;
V_58 = F_171 ( V_3 , V_111 , V_251 , & V_154 , V_159 ,
& V_204 ) ;
if ( V_154 )
V_58 = F_159 ( V_273 , V_154 , V_159 , V_204 ) ;
return V_58 ;
}
static T_5 void F_186 ( struct V_111 * V_111 ,
struct V_274 * V_275 ,
unsigned long V_276 )
{
V_275 -> V_277 -= V_276 ;
if ( V_275 -> V_278 || ( V_275 -> V_277 > 0 &&
V_275 -> V_279 == 0 && V_275 -> V_280 == V_281 ) )
V_111 -> V_4 -> V_282 = V_111 -> V_108 + V_276 ;
}
static int F_187 ( struct V_111 * V_111 , struct V_274 * V_275 ,
void * V_283 )
{
struct V_107 * V_107 = V_111 -> V_4 -> V_5 ;
struct V_284 * V_285 = V_283 ;
struct V_2 * V_3 = V_285 -> V_3 ;
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_123 ;
T_3 V_252 = V_21 + V_131 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_172 ( V_107 ) ;
T_3 V_205 ;
T_3 V_260 ;
T_7 V_164 ;
struct V_8 * V_81 = NULL ;
struct V_196 * V_197 ;
struct V_229 * V_177 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_262 ;
T_10 V_286 = F_172 ( V_107 ) ;
unsigned long V_110 = V_286 >> V_109 ;
T_3 V_287 ;
T_3 V_124 ;
int V_288 ;
int V_289 ;
int V_290 ;
unsigned long V_276 = 0 ;
bool V_291 = true ;
if ( V_275 -> V_292 == V_293 )
V_290 = V_180 ;
else
V_290 = V_173 ;
F_188 ( V_111 , V_107 , V_275 ) ;
F_27 ( ! F_189 ( V_111 ) ) ;
F_190 ( V_111 ) ;
V_259 = V_286 & ( V_131 - 1 ) ;
if ( V_111 -> V_108 > V_110 ||
( V_111 -> V_108 == V_110 && ! V_259 ) ) {
V_111 -> V_4 -> V_294 -> V_295 ( V_111 , 0 ) ;
F_102 ( V_111 ) ;
return 0 ;
}
if ( V_111 -> V_108 == V_110 ) {
char * V_266 ;
V_266 = F_178 ( V_111 ) ;
memset ( V_266 + V_259 , 0 ,
V_131 - V_259 ) ;
F_180 ( V_266 ) ;
F_179 ( V_111 ) ;
}
V_259 = 0 ;
F_170 ( V_111 ) ;
if ( ! V_3 -> V_30 || ! V_3 -> V_30 -> V_291 )
V_291 = false ;
V_123 = V_21 ;
V_124 = 0 ;
V_288 = 0 ;
if ( ! V_285 -> V_296 && V_291 ) {
T_3 V_297 = 0 ;
F_186 ( V_111 , V_275 , 0 ) ;
while ( V_124 < V_252 ) {
V_287 = F_106 ( V_107 , V_3 ,
V_111 ,
& V_123 ,
& V_124 ,
128 * 1024 * 1024 ) ;
if ( V_287 == 0 ) {
V_123 = V_124 + 1 ;
continue;
}
V_58 = V_3 -> V_30 -> V_291 ( V_107 , V_111 ,
V_123 ,
V_124 ,
& V_288 ,
& V_276 ) ;
if ( V_58 ) {
F_154 ( V_111 ) ;
goto V_129;
}
V_297 += ( V_124 - V_123 +
V_131 ) >>
V_109 ;
V_123 = V_124 + 1 ;
}
if ( V_275 -> V_277 < V_297 ) {
int V_298 = 8192 ;
if ( V_297 < V_298 * 2 )
V_298 = V_297 ;
V_275 -> V_277 = F_101 ( T_3 , V_297 ,
V_298 ) ;
}
if ( V_288 ) {
V_58 = 0 ;
V_275 -> V_277 -= V_276 ;
goto V_299;
}
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_300 ) {
V_58 = V_3 -> V_30 -> V_300 ( V_111 , V_21 ,
V_252 ) ;
if ( V_58 ) {
if ( V_58 == - V_301 )
V_275 -> V_302 ++ ;
else
F_191 ( V_275 , V_111 ) ;
F_186 ( V_111 , V_275 , V_276 ) ;
F_102 ( V_111 ) ;
V_58 = 0 ;
goto V_299;
}
}
F_186 ( V_111 , V_275 , V_276 + 1 ) ;
V_22 = V_252 ;
if ( V_255 <= V_21 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_111 , V_21 ,
V_252 , NULL , 1 ) ;
goto V_129;
}
V_262 = V_107 -> V_6 -> V_263 ;
while ( V_253 <= V_22 ) {
if ( V_253 >= V_255 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_111 , V_253 ,
V_252 , NULL , 1 ) ;
break;
}
V_197 = V_285 -> V_251 ( V_107 , V_111 , V_259 , V_253 ,
V_22 - V_253 + 1 , 1 ) ;
if ( F_181 ( V_197 ) ) {
F_154 ( V_111 ) ;
break;
}
V_254 = V_253 - V_197 -> V_21 ;
F_56 ( F_182 ( V_197 ) <= V_253 ) ;
F_56 ( V_22 < V_253 ) ;
V_260 = F_112 ( F_182 ( V_197 ) - V_253 , V_22 - V_253 + 1 ) ;
V_260 = F_183 ( V_260 , V_262 ) ;
V_164 = ( V_197 -> V_205 + V_254 ) >> 9 ;
V_177 = V_197 -> V_177 ;
V_205 = V_197 -> V_205 ;
V_289 = F_135 ( V_206 , & V_197 -> V_36 ) ;
F_150 ( V_197 ) ;
V_197 = NULL ;
if ( V_289 || V_205 == V_271 ||
V_205 == V_272 ) {
if ( ! V_289 && V_3 -> V_30 &&
V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_111 , V_253 ,
V_253 + V_260 - 1 ,
NULL , 1 ) ;
else if ( V_289 ) {
V_244 ++ ;
}
V_253 += V_260 ;
V_259 += V_260 ;
continue;
}
if ( 0 && ! F_107 ( V_3 , V_253 , V_253 + V_260 - 1 ,
V_77 , 0 , NULL ) ) {
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_303 ) {
V_58 = V_3 -> V_30 -> V_303 ( V_111 , V_253 ,
V_253 + V_260 - 1 ) ;
} else {
V_58 = 0 ;
}
if ( V_58 ) {
F_154 ( V_111 ) ;
} else {
unsigned long V_304 = V_110 + 1 ;
F_94 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
if ( ! F_192 ( V_111 ) ) {
F_9 ( V_20 L_29
L_30 ,
V_111 -> V_108 , ( unsigned long long ) V_253 ,
( unsigned long long ) V_22 ) ;
}
V_58 = F_163 ( V_290 , V_3 , V_111 ,
V_164 , V_260 , V_259 ,
V_177 , & V_285 -> V_154 , V_304 ,
F_155 ,
0 , 0 , 0 ) ;
if ( V_58 )
F_154 ( V_111 ) ;
}
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
V_244 ++ ;
}
V_129:
if ( V_244 == 0 ) {
F_95 ( V_111 ) ;
F_110 ( V_111 ) ;
}
F_102 ( V_111 ) ;
V_299:
F_25 ( V_81 ) ;
return 0 ;
}
static int F_193 ( void * V_305 )
{
F_194 () ;
return 0 ;
}
static void F_195 ( struct V_13 * V_16 )
{
F_196 ( & V_16 -> V_306 , V_307 , F_193 ,
V_92 ) ;
}
static int F_197 ( struct V_13 * V_16 ,
struct V_1 * V_156 ,
struct V_284 * V_285 )
{
unsigned long V_122 , V_188 ;
int V_308 = 0 ;
int V_58 = 0 ;
if ( ! F_198 ( V_16 ) ) {
V_308 = 1 ;
F_199 ( V_285 ) ;
F_200 ( V_16 ) ;
}
if ( F_135 ( V_307 , & V_16 -> V_306 ) ) {
F_201 ( V_16 ) ;
if ( ! V_285 -> V_309 )
return 0 ;
if ( ! V_308 ) {
F_199 ( V_285 ) ;
V_308 = 1 ;
}
while ( 1 ) {
F_195 ( V_16 ) ;
F_200 ( V_16 ) ;
if ( ! F_135 ( V_307 , & V_16 -> V_306 ) )
break;
F_201 ( V_16 ) ;
}
}
F_54 ( & V_16 -> V_310 ) ;
if ( F_202 ( V_311 , & V_16 -> V_306 ) ) {
F_203 ( V_307 , & V_16 -> V_306 ) ;
F_58 ( & V_16 -> V_310 ) ;
F_204 ( V_16 , V_312 ) ;
F_205 ( & V_156 -> V_313 ,
- V_16 -> V_25 ,
V_156 -> V_314 ) ;
V_58 = 1 ;
} else {
F_58 ( & V_16 -> V_310 ) ;
}
F_201 ( V_16 ) ;
if ( ! V_58 )
return V_58 ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
struct V_111 * V_46 = F_141 ( V_16 , V_122 ) ;
if ( ! F_206 ( V_46 ) ) {
if ( ! V_308 ) {
F_199 ( V_285 ) ;
V_308 = 1 ;
}
F_104 ( V_46 ) ;
}
}
return V_58 ;
}
static void F_207 ( struct V_13 * V_16 )
{
F_208 ( V_307 , & V_16 -> V_306 ) ;
F_209 () ;
F_210 ( & V_16 -> V_306 , V_307 ) ;
}
static void F_211 ( struct V_154 * V_154 , int V_79 )
{
int V_215 = V_79 == 0 ;
struct V_217 * V_218 = V_154 -> V_219 + V_154 -> V_209 - 1 ;
struct V_13 * V_16 ;
int V_129 ;
do {
struct V_111 * V_111 = V_218 -> V_221 ;
V_218 -- ;
V_16 = (struct V_13 * ) V_111 -> V_37 ;
F_56 ( ! V_16 ) ;
V_129 = F_26 ( & V_16 -> V_315 ) ;
if ( ! V_215 || F_135 ( V_316 , & V_16 -> V_306 ) ) {
F_203 ( V_316 , & V_16 -> V_306 ) ;
F_153 ( V_111 ) ;
F_154 ( V_111 ) ;
}
F_110 ( V_111 ) ;
if ( ! V_129 )
continue;
F_207 ( V_16 ) ;
} while ( V_218 >= V_154 -> V_219 );
F_131 ( V_154 ) ;
}
static int F_212 ( struct V_13 * V_16 ,
struct V_1 * V_156 ,
struct V_274 * V_275 ,
struct V_284 * V_285 )
{
struct V_229 * V_177 = V_156 -> V_212 -> V_213 ;
T_3 V_44 = V_16 -> V_21 ;
unsigned long V_122 , V_188 ;
unsigned long V_204 = 0 ;
int V_235 = ( V_285 -> V_309 ? V_180 : V_173 ) ;
int V_58 = 0 ;
F_208 ( V_316 , & V_16 -> V_306 ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_22 ( & V_16 -> V_315 , V_188 ) ;
if ( F_213 ( V_16 ) == V_317 )
V_204 = V_318 ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
struct V_111 * V_46 = F_141 ( V_16 , V_122 ) ;
F_89 ( V_46 ) ;
F_95 ( V_46 ) ;
V_58 = F_163 ( V_235 , V_16 -> V_3 , V_46 , V_44 >> 9 ,
V_131 , 0 , V_177 , & V_285 -> V_154 ,
- 1 , F_211 ,
0 , V_285 -> V_204 , V_204 ) ;
V_285 -> V_204 = V_204 ;
if ( V_58 ) {
F_203 ( V_316 , & V_16 -> V_306 ) ;
F_154 ( V_46 ) ;
if ( F_214 ( V_188 - V_122 , & V_16 -> V_315 ) )
F_207 ( V_16 ) ;
V_58 = - V_170 ;
break;
}
V_44 += V_131 ;
F_186 ( V_46 , V_275 , 1 ) ;
F_102 ( V_46 ) ;
}
if ( F_215 ( V_58 ) ) {
for (; V_122 < V_188 ; V_122 ++ ) {
struct V_111 * V_46 = F_141 ( V_16 , V_122 ) ;
F_102 ( V_46 ) ;
}
}
return V_58 ;
}
int F_216 ( struct V_26 * V_4 ,
struct V_274 * V_275 )
{
struct V_2 * V_3 = & F_122 ( V_4 -> V_5 ) -> V_152 ;
struct V_1 * V_156 = F_122 ( V_4 -> V_5 ) -> V_43 -> V_156 ;
struct V_13 * V_16 , * V_319 = NULL ;
struct V_284 V_285 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
. V_204 = 0 ,
} ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_320 = 0 ;
struct V_321 V_322 ;
int V_121 ;
T_11 V_108 ;
T_11 V_22 ;
int V_323 = 0 ;
int V_324 ;
F_217 ( & V_322 , 0 ) ;
if ( V_275 -> V_278 ) {
V_108 = V_4 -> V_282 ;
V_22 = - 1 ;
} else {
V_108 = V_275 -> V_279 >> V_109 ;
V_22 = V_275 -> V_280 >> V_109 ;
V_323 = 1 ;
}
if ( V_275 -> V_292 == V_293 )
V_324 = V_325 ;
else
V_324 = V_326 ;
V_327:
if ( V_275 -> V_292 == V_293 )
F_218 ( V_4 , V_108 , V_22 ) ;
while ( ! V_129 && ! V_320 && ( V_108 <= V_22 ) &&
( V_121 = F_219 ( & V_322 , V_4 , & V_108 , V_324 ,
F_112 ( V_22 - V_108 , ( T_11 ) V_328 - 1 ) + 1 ) ) ) {
unsigned V_122 ;
V_323 = 1 ;
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
struct V_111 * V_111 = V_322 . V_120 [ V_122 ] ;
if ( ! F_166 ( V_111 ) )
continue;
if ( ! V_275 -> V_278 && V_111 -> V_108 > V_22 ) {
V_129 = 1 ;
break;
}
F_54 ( & V_4 -> V_329 ) ;
if ( ! F_166 ( V_111 ) ) {
F_58 ( & V_4 -> V_329 ) ;
continue;
}
V_16 = (struct V_13 * ) V_111 -> V_37 ;
if ( ! V_16 ) {
F_58 ( & V_4 -> V_329 ) ;
F_27 ( 1 ) ;
continue;
}
if ( V_16 == V_319 ) {
F_58 ( & V_4 -> V_329 ) ;
continue;
}
V_58 = F_220 ( & V_16 -> V_23 ) ;
F_58 ( & V_4 -> V_329 ) ;
if ( ! V_58 )
continue;
V_319 = V_16 ;
V_58 = F_197 ( V_16 , V_156 , & V_285 ) ;
if ( ! V_58 ) {
F_221 ( V_16 ) ;
continue;
}
V_58 = F_212 ( V_16 , V_156 , V_275 , & V_285 ) ;
if ( V_58 ) {
V_129 = 1 ;
F_221 ( V_16 ) ;
break;
}
F_221 ( V_16 ) ;
V_320 = V_275 -> V_277 <= 0 ;
}
F_222 ( & V_322 ) ;
F_59 () ;
}
if ( ! V_323 && ! V_129 ) {
V_323 = 1 ;
V_108 = 0 ;
goto V_327;
}
F_199 ( & V_285 ) ;
return V_58 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_274 * V_275 ,
T_12 V_330 , void * V_283 ,
void (* F_224)( void * ) )
{
struct V_107 * V_107 = V_4 -> V_5 ;
int V_58 = 0 ;
int V_129 = 0 ;
int V_320 = 0 ;
struct V_321 V_322 ;
int V_121 ;
T_11 V_108 ;
T_11 V_22 ;
int V_323 = 0 ;
int V_324 ;
if ( ! F_225 ( V_107 ) )
return 0 ;
F_217 ( & V_322 , 0 ) ;
if ( V_275 -> V_278 ) {
V_108 = V_4 -> V_282 ;
V_22 = - 1 ;
} else {
V_108 = V_275 -> V_279 >> V_109 ;
V_22 = V_275 -> V_280 >> V_109 ;
V_323 = 1 ;
}
if ( V_275 -> V_292 == V_293 )
V_324 = V_325 ;
else
V_324 = V_326 ;
V_327:
if ( V_275 -> V_292 == V_293 )
F_218 ( V_4 , V_108 , V_22 ) ;
while ( ! V_129 && ! V_320 && ( V_108 <= V_22 ) &&
( V_121 = F_219 ( & V_322 , V_4 , & V_108 , V_324 ,
F_112 ( V_22 - V_108 , ( T_11 ) V_328 - 1 ) + 1 ) ) ) {
unsigned V_122 ;
V_323 = 1 ;
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
struct V_111 * V_111 = V_322 . V_120 [ V_122 ] ;
if ( ! F_206 ( V_111 ) ) {
F_224 ( V_283 ) ;
F_104 ( V_111 ) ;
}
if ( F_215 ( V_111 -> V_4 != V_4 ) ) {
F_102 ( V_111 ) ;
continue;
}
if ( ! V_275 -> V_278 && V_111 -> V_108 > V_22 ) {
V_129 = 1 ;
F_102 ( V_111 ) ;
continue;
}
if ( V_275 -> V_292 != V_331 ) {
if ( F_192 ( V_111 ) )
F_224 ( V_283 ) ;
F_226 ( V_111 ) ;
}
if ( F_192 ( V_111 ) ||
! F_89 ( V_111 ) ) {
F_102 ( V_111 ) ;
continue;
}
V_58 = (* V_330)( V_111 , V_275 , V_283 ) ;
if ( F_215 ( V_58 == V_332 ) ) {
F_102 ( V_111 ) ;
V_58 = 0 ;
}
if ( V_58 )
V_129 = 1 ;
V_320 = V_275 -> V_277 <= 0 ;
}
F_222 ( & V_322 ) ;
F_59 () ;
}
if ( ! V_323 && ! V_129 ) {
V_323 = 1 ;
V_108 = 0 ;
goto V_327;
}
F_227 ( V_107 ) ;
return V_58 ;
}
static void F_228 ( struct V_284 * V_285 )
{
if ( V_285 -> V_154 ) {
int V_235 = V_173 ;
int V_58 ;
if ( V_285 -> V_309 )
V_235 = V_180 ;
V_58 = F_159 ( V_235 , V_285 -> V_154 , 0 , V_285 -> V_204 ) ;
F_56 ( V_58 < 0 ) ;
V_285 -> V_154 = NULL ;
}
}
static T_5 void F_199 ( void * V_283 )
{
struct V_284 * V_285 = V_283 ;
F_228 ( V_285 ) ;
}
int F_229 ( struct V_2 * V_3 , struct V_111 * V_111 ,
T_9 * V_251 ,
struct V_274 * V_275 )
{
int V_58 ;
struct V_284 V_285 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
. V_204 = 0 ,
} ;
V_58 = F_187 ( V_111 , V_275 , & V_285 ) ;
F_228 ( & V_285 ) ;
return V_58 ;
}
int F_230 ( struct V_2 * V_3 , struct V_107 * V_107 ,
T_3 V_21 , T_3 V_22 , T_9 * V_251 ,
int V_333 )
{
int V_58 = 0 ;
struct V_26 * V_4 = V_107 -> V_112 ;
struct V_111 * V_111 ;
unsigned long V_121 = ( V_22 - V_21 + V_131 ) >>
V_109 ;
struct V_284 V_285 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_296 = 1 ,
. V_309 = V_333 == V_293 ,
. V_204 = 0 ,
} ;
struct V_274 V_334 = {
. V_292 = V_333 ,
. V_277 = V_121 * 2 ,
. V_279 = V_21 ,
. V_280 = V_22 + 1 ,
} ;
while ( V_21 <= V_22 ) {
V_111 = F_88 ( V_4 , V_21 >> V_109 ) ;
if ( F_89 ( V_111 ) )
V_58 = F_187 ( V_111 , & V_334 , & V_285 ) ;
else {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_216 )
V_3 -> V_30 -> V_216 ( V_111 , V_21 ,
V_21 + V_131 - 1 ,
NULL , 1 ) ;
F_102 ( V_111 ) ;
}
F_90 ( V_111 ) ;
V_21 += V_131 ;
}
F_228 ( & V_285 ) ;
return V_58 ;
}
int F_231 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
T_9 * V_251 ,
struct V_274 * V_275 )
{
int V_58 = 0 ;
struct V_284 V_285 = {
. V_154 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
. V_204 = 0 ,
} ;
V_58 = F_223 ( V_3 , V_4 , V_275 ,
F_187 , & V_285 ,
F_199 ) ;
F_228 ( & V_285 ) ;
return V_58 ;
}
int F_232 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_335 * V_120 , unsigned V_121 ,
T_9 V_251 )
{
struct V_154 * V_154 = NULL ;
unsigned V_336 ;
unsigned long V_204 = 0 ;
struct V_111 * V_337 [ 16 ] ;
struct V_111 * V_111 ;
int V_122 = 0 ;
int V_244 = 0 ;
for ( V_336 = 0 ; V_336 < V_121 ; V_336 ++ ) {
V_111 = F_8 ( V_120 -> V_55 , struct V_111 , V_338 ) ;
F_156 ( & V_111 -> V_36 ) ;
F_11 ( & V_111 -> V_338 ) ;
if ( F_233 ( V_111 , V_4 ,
V_111 -> V_108 , V_106 ) ) {
F_90 ( V_111 ) ;
continue;
}
V_337 [ V_244 ++ ] = V_111 ;
if ( V_244 < F_234 ( V_337 ) )
continue;
for ( V_122 = 0 ; V_122 < V_244 ; V_122 ++ ) {
F_171 ( V_3 , V_337 [ V_122 ] , V_251 ,
& V_154 , 0 , & V_204 ) ;
F_90 ( V_337 [ V_122 ] ) ;
}
V_244 = 0 ;
}
for ( V_122 = 0 ; V_122 < V_244 ; V_122 ++ ) {
F_171 ( V_3 , V_337 [ V_122 ] , V_251 ,
& V_154 , 0 , & V_204 ) ;
F_90 ( V_337 [ V_122 ] ) ;
}
F_56 ( ! F_7 ( V_120 ) ) ;
if ( V_154 )
return F_159 ( V_273 , V_154 , 0 , V_204 ) ;
return 0 ;
}
int F_235 ( struct V_2 * V_3 ,
struct V_111 * V_111 , unsigned long V_44 )
{
struct V_8 * V_81 = NULL ;
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
T_6 V_262 = V_111 -> V_4 -> V_5 -> V_6 -> V_263 ;
V_21 += F_183 ( V_44 , V_262 ) ;
if ( V_21 > V_22 )
return 0 ;
F_82 ( V_3 , V_21 , V_22 , 0 , & V_81 ) ;
F_226 ( V_111 ) ;
F_53 ( V_3 , V_21 , V_22 ,
V_105 | V_77 | V_100 |
V_103 ,
1 , 1 , & V_81 , V_106 ) ;
return 0 ;
}
int F_236 ( struct V_198 * V_339 ,
struct V_2 * V_3 , struct V_111 * V_111 ,
T_2 V_34 )
{
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
int V_58 = 1 ;
if ( F_107 ( V_3 , V_21 , V_22 ,
V_63 , 0 , NULL ) )
V_58 = 0 ;
else {
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
V_58 = F_53 ( V_3 , V_21 , V_22 ,
~ ( V_105 | V_340 ) ,
0 , 0 , NULL , V_34 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
else
V_58 = 1 ;
}
return V_58 ;
}
int F_237 ( struct V_198 * V_339 ,
struct V_2 * V_3 , struct V_111 * V_111 ,
T_2 V_34 )
{
struct V_196 * V_197 ;
T_3 V_21 = F_117 ( V_111 ) ;
T_3 V_22 = V_21 + V_131 - 1 ;
if ( ( V_34 & V_87 ) &&
V_111 -> V_4 -> V_5 -> V_286 > 16 * 1024 * 1024 ) {
T_3 V_25 ;
while ( V_21 <= V_22 ) {
V_25 = V_22 - V_21 + 1 ;
F_238 ( & V_339 -> V_32 ) ;
V_197 = F_148 ( V_339 , V_21 , V_25 ) ;
if ( ! V_197 ) {
F_239 ( & V_339 -> V_32 ) ;
break;
}
if ( F_135 ( V_341 , & V_197 -> V_36 ) ||
V_197 -> V_21 != V_21 ) {
F_239 ( & V_339 -> V_32 ) ;
F_150 ( V_197 ) ;
break;
}
if ( ! F_107 ( V_3 , V_197 -> V_21 ,
F_182 ( V_197 ) - 1 ,
V_105 | V_342 ,
0 , NULL ) ) {
F_240 ( V_339 , V_197 ) ;
F_150 ( V_197 ) ;
}
V_21 = F_182 ( V_197 ) ;
F_239 ( & V_339 -> V_32 ) ;
F_150 ( V_197 ) ;
}
}
return F_236 ( V_339 , V_3 , V_111 , V_34 ) ;
}
static struct V_196 * F_241 ( struct V_107 * V_107 ,
T_3 V_44 ,
T_3 V_143 ,
T_9 * V_251 )
{
T_3 V_343 = F_122 ( V_107 ) -> V_43 -> V_343 ;
struct V_196 * V_197 ;
T_3 V_25 ;
if ( V_44 >= V_143 )
return NULL ;
while( 1 ) {
V_25 = V_143 - V_44 ;
if ( V_25 == 0 )
break;
V_25 = F_183 ( V_25 , V_343 ) ;
V_197 = V_251 ( V_107 , NULL , 0 , V_44 , V_25 , 0 ) ;
if ( F_181 ( V_197 ) )
return V_197 ;
if ( ! F_135 ( V_344 , & V_197 -> V_36 ) &&
V_197 -> V_205 != V_271 ) {
return V_197 ;
}
V_44 = F_182 ( V_197 ) ;
F_150 ( V_197 ) ;
if ( V_44 >= V_143 )
break;
}
return NULL ;
}
int F_242 ( struct V_107 * V_107 , struct V_345 * V_346 ,
T_13 V_21 , T_13 V_25 , T_9 * V_251 )
{
int V_58 = 0 ;
T_3 V_347 = V_21 ;
T_3 F_113 = V_21 + V_25 ;
T_14 V_36 = 0 ;
T_14 V_348 ;
T_3 V_143 ;
T_3 V_349 = 0 ;
T_3 V_350 = 0 ;
T_3 V_351 = F_172 ( V_107 ) ;
struct V_352 V_353 ;
struct V_196 * V_197 = NULL ;
struct V_8 * V_81 = NULL ;
struct V_354 * V_355 ;
struct V_356 * V_357 ;
int V_22 = 0 ;
T_3 V_358 = 0 ;
T_3 V_359 = 0 ;
T_3 V_360 = 0 ;
unsigned long V_361 ;
if ( V_25 == 0 )
return - V_362 ;
V_355 = F_243 () ;
if ( ! V_355 )
return - V_11 ;
V_355 -> V_363 = 1 ;
V_21 = F_183 ( V_21 , F_122 ( V_107 ) -> V_43 -> V_343 ) ;
V_25 = F_183 ( V_25 , F_122 ( V_107 ) -> V_43 -> V_343 ) ;
V_58 = F_244 ( NULL , F_122 ( V_107 ) -> V_43 ,
V_355 , F_245 ( V_107 ) , - 1 , 0 ) ;
if ( V_58 < 0 ) {
F_246 ( V_355 ) ;
return V_58 ;
}
F_27 ( ! V_58 ) ;
V_355 -> V_364 [ 0 ] -- ;
V_357 = F_247 ( V_355 -> V_365 [ 0 ] , V_355 -> V_364 [ 0 ] ,
struct V_356 ) ;
F_248 ( V_355 -> V_365 [ 0 ] , & V_353 , V_355 -> V_364 [ 0 ] ) ;
V_348 = F_249 ( & V_353 ) ;
if ( V_353 . V_366 != F_245 ( V_107 ) ||
V_348 != V_367 ) {
V_143 = ( T_3 ) - 1 ;
V_349 = V_351 ;
} else {
V_143 = V_353 . V_44 ;
V_349 = V_143 + 1 ;
}
F_246 ( V_355 ) ;
if ( V_143 < V_351 ) {
V_143 = ( T_3 ) - 1 ;
V_349 = V_351 ;
}
F_82 ( & F_122 ( V_107 ) -> V_152 , V_21 , V_21 + V_25 , 0 ,
& V_81 ) ;
V_197 = F_241 ( V_107 , V_21 , V_349 ,
V_251 ) ;
if ( ! V_197 )
goto V_89;
if ( F_250 ( V_197 ) ) {
V_58 = F_251 ( V_197 ) ;
goto V_89;
}
while ( ! V_22 ) {
T_3 V_368 ;
if ( V_197 -> V_21 >= F_113 || F_182 ( V_197 ) < V_347 )
break;
V_358 = F_113 ( V_197 -> V_21 , V_347 ) ;
V_368 = V_358 - V_197 -> V_21 ;
V_360 = F_182 ( V_197 ) ;
V_359 = V_360 - V_358 ;
V_361 = V_197 -> V_36 ;
V_350 = 0 ;
V_36 = 0 ;
V_347 = F_182 ( V_197 ) ;
if ( V_347 >= F_113 )
V_22 = 1 ;
if ( V_197 -> V_205 == V_369 ) {
V_22 = 1 ;
V_36 |= V_370 ;
} else if ( V_197 -> V_205 == V_272 ) {
V_36 |= ( V_371 |
V_372 ) ;
} else if ( V_197 -> V_205 == V_373 ) {
V_36 |= ( V_374 |
V_375 ) ;
} else {
V_350 = V_197 -> V_205 + V_368 ;
}
if ( F_135 ( V_206 , & V_197 -> V_36 ) )
V_36 |= V_376 ;
F_150 ( V_197 ) ;
V_197 = NULL ;
if ( ( V_358 >= V_143 ) || V_359 == ( T_3 ) - 1 ||
( V_143 == ( T_3 ) - 1 && V_351 <= V_360 ) ) {
V_36 |= V_370 ;
V_22 = 1 ;
}
V_197 = F_241 ( V_107 , V_347 , V_349 ,
V_251 ) ;
if ( F_250 ( V_197 ) ) {
V_58 = F_251 ( V_197 ) ;
goto V_89;
}
if ( ! V_197 ) {
V_36 |= V_370 ;
V_22 = 1 ;
}
V_58 = F_252 ( V_346 , V_358 , V_350 ,
V_359 , V_36 ) ;
if ( V_58 )
goto V_377;
}
V_377:
F_150 ( V_197 ) ;
V_89:
F_85 ( & F_122 ( V_107 ) -> V_152 , V_21 , V_21 + V_25 ,
& V_81 , V_106 ) ;
return V_58 ;
}
static void F_253 ( struct V_13 * V_16 )
{
#if V_35
unsigned long V_36 ;
F_19 ( & V_38 , V_36 ) ;
F_11 ( & V_16 -> V_19 ) ;
F_21 ( & V_38 , V_36 ) ;
#endif
F_12 ( V_12 , V_16 ) ;
}
static struct V_13 * F_254 ( struct V_2 * V_3 ,
T_3 V_21 ,
unsigned long V_25 ,
T_2 V_34 )
{
struct V_13 * V_16 = NULL ;
#if V_35
unsigned long V_36 ;
#endif
V_16 = F_255 ( V_12 , V_34 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_21 = V_21 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_306 = 0 ;
F_256 ( & V_16 -> V_32 ) ;
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
F_16 ( & V_16 -> V_310 ) ;
F_22 ( & V_16 -> V_23 , 1 ) ;
F_22 ( & V_16 -> V_315 , 0 ) ;
F_257 ( V_387
> V_388 ) ;
F_56 ( V_25 > V_388 ) ;
return V_16 ;
}
struct V_13 * F_258 ( struct V_13 * V_389 )
{
unsigned long V_122 ;
struct V_111 * V_46 ;
struct V_13 * V_59 ;
unsigned long V_188 = F_140 ( V_389 -> V_21 , V_389 -> V_25 ) ;
V_59 = F_254 ( NULL , V_389 -> V_21 , V_389 -> V_25 , V_29 ) ;
if ( V_59 == NULL )
return NULL ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
V_46 = F_259 ( V_29 ) ;
F_56 ( ! V_46 ) ;
F_165 ( V_59 , V_46 ) ;
F_27 ( F_105 ( V_46 ) ) ;
F_118 ( V_46 ) ;
V_59 -> V_120 [ V_122 ] = V_46 ;
}
F_260 ( V_59 , V_389 , 0 , 0 , V_389 -> V_25 ) ;
F_203 ( V_390 , & V_59 -> V_306 ) ;
F_203 ( V_391 , & V_59 -> V_306 ) ;
return V_59 ;
}
struct V_13 * F_261 ( T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
unsigned long V_188 = F_140 ( 0 , V_25 ) ;
unsigned long V_122 ;
V_16 = F_254 ( NULL , V_21 , V_25 , V_29 ) ;
if ( ! V_16 )
return NULL ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
V_16 -> V_120 [ V_122 ] = F_259 ( V_29 ) ;
if ( ! V_16 -> V_120 [ V_122 ] )
goto V_79;
}
F_262 ( V_16 ) ;
F_263 ( V_16 , 0 ) ;
F_203 ( V_391 , & V_16 -> V_306 ) ;
return V_16 ;
V_79:
for (; V_122 > 0 ; V_122 -- )
F_264 ( V_16 -> V_120 [ V_122 - 1 ] ) ;
F_253 ( V_16 ) ;
return NULL ;
}
static int F_265 ( struct V_13 * V_16 )
{
return ( F_10 ( & V_16 -> V_315 ) ||
F_135 ( V_307 , & V_16 -> V_306 ) ||
F_135 ( V_311 , & V_16 -> V_306 ) ) ;
}
static void F_266 ( struct V_13 * V_16 ,
unsigned long V_392 )
{
unsigned long V_108 ;
unsigned long V_188 ;
struct V_111 * V_111 ;
int V_393 = ! F_135 ( V_391 , & V_16 -> V_306 ) ;
F_56 ( F_265 ( V_16 ) ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
V_108 = V_392 + V_188 ;
if ( V_392 >= V_108 )
return;
do {
V_108 -- ;
V_111 = F_141 ( V_16 , V_108 ) ;
if ( V_111 && V_393 ) {
F_54 ( & V_111 -> V_4 -> V_329 ) ;
if ( F_166 ( V_111 ) &&
V_111 -> V_37 == ( unsigned long ) V_16 ) {
F_56 ( F_135 ( V_311 , & V_16 -> V_306 ) ) ;
F_56 ( F_105 ( V_111 ) ) ;
F_56 ( F_192 ( V_111 ) ) ;
F_267 ( V_111 ) ;
F_169 ( V_111 , 0 ) ;
F_90 ( V_111 ) ;
}
F_58 ( & V_111 -> V_4 -> V_329 ) ;
}
if ( V_111 ) {
F_90 ( V_111 ) ;
}
} while ( V_108 != V_392 );
}
static inline void F_268 ( struct V_13 * V_16 )
{
F_266 ( V_16 , 0 ) ;
F_253 ( V_16 ) ;
}
static void F_269 ( struct V_13 * V_16 )
{
int V_23 ;
V_23 = F_10 ( & V_16 -> V_23 ) ;
if ( V_23 >= 2 && F_135 ( V_394 , & V_16 -> V_306 ) )
return;
F_54 ( & V_16 -> V_310 ) ;
if ( ! F_270 ( V_394 , & V_16 -> V_306 ) )
F_66 ( & V_16 -> V_23 ) ;
F_58 ( & V_16 -> V_310 ) ;
}
static void F_271 ( struct V_13 * V_16 )
{
unsigned long V_188 , V_122 ;
F_269 ( V_16 ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
struct V_111 * V_46 = F_141 ( V_16 , V_122 ) ;
F_272 ( V_46 ) ;
}
}
struct V_13 * F_273 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
unsigned long V_188 = F_140 ( V_21 , V_25 ) ;
unsigned long V_122 ;
unsigned long V_108 = V_21 >> V_109 ;
struct V_13 * V_16 ;
struct V_13 * V_395 = NULL ;
struct V_111 * V_46 ;
struct V_26 * V_4 = V_3 -> V_4 ;
int V_215 = 1 ;
int V_58 ;
F_274 () ;
V_16 = F_275 ( & V_3 -> V_28 , V_21 >> V_109 ) ;
if ( V_16 && F_220 ( & V_16 -> V_23 ) ) {
F_276 () ;
F_271 ( V_16 ) ;
return V_16 ;
}
F_276 () ;
V_16 = F_254 ( V_3 , V_21 , V_25 , V_106 ) ;
if ( ! V_16 )
return NULL ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ , V_108 ++ ) {
V_46 = F_277 ( V_4 , V_108 , V_106 ) ;
if ( ! V_46 )
goto V_396;
F_54 ( & V_4 -> V_329 ) ;
if ( F_166 ( V_46 ) ) {
V_395 = (struct V_13 * ) V_46 -> V_37 ;
if ( F_220 ( & V_395 -> V_23 ) ) {
F_58 ( & V_4 -> V_329 ) ;
F_102 ( V_46 ) ;
F_90 ( V_46 ) ;
F_271 ( V_395 ) ;
goto V_396;
}
F_267 ( V_46 ) ;
F_27 ( F_105 ( V_46 ) ) ;
F_90 ( V_46 ) ;
}
F_165 ( V_16 , V_46 ) ;
F_58 ( & V_4 -> V_329 ) ;
F_27 ( F_105 ( V_46 ) ) ;
F_272 ( V_46 ) ;
V_16 -> V_120 [ V_122 ] = V_46 ;
if ( ! F_173 ( V_46 ) )
V_215 = 0 ;
}
if ( V_215 )
F_203 ( V_390 , & V_16 -> V_306 ) ;
V_86:
V_58 = F_278 ( V_106 & ~ V_397 ) ;
if ( V_58 )
goto V_396;
F_54 ( & V_3 -> V_33 ) ;
V_58 = F_279 ( & V_3 -> V_28 , V_21 >> V_109 , V_16 ) ;
if ( V_58 == - V_69 ) {
V_395 = F_275 ( & V_3 -> V_28 ,
V_21 >> V_109 ) ;
if ( ! F_220 ( & V_395 -> V_23 ) ) {
F_58 ( & V_3 -> V_33 ) ;
F_280 () ;
V_395 = NULL ;
goto V_86;
}
F_58 ( & V_3 -> V_33 ) ;
F_280 () ;
F_271 ( V_395 ) ;
goto V_396;
}
F_269 ( V_16 ) ;
F_58 ( & V_3 -> V_33 ) ;
F_280 () ;
F_281 ( V_16 -> V_120 [ 0 ] ) ;
for ( V_122 = 1 ; V_122 < V_188 ; V_122 ++ ) {
V_46 = F_141 ( V_16 , V_122 ) ;
F_282 ( V_46 ) ;
F_102 ( V_46 ) ;
}
F_102 ( V_16 -> V_120 [ 0 ] ) ;
return V_16 ;
V_396:
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
if ( V_16 -> V_120 [ V_122 ] )
F_102 ( V_16 -> V_120 [ V_122 ] ) ;
}
F_27 ( ! F_26 ( & V_16 -> V_23 ) ) ;
F_268 ( V_16 ) ;
return V_395 ;
}
struct V_13 * F_283 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
F_274 () ;
V_16 = F_275 ( & V_3 -> V_28 , V_21 >> V_109 ) ;
if ( V_16 && F_220 ( & V_16 -> V_23 ) ) {
F_276 () ;
F_271 ( V_16 ) ;
return V_16 ;
}
F_276 () ;
return NULL ;
}
static inline void F_284 ( struct V_398 * V_399 )
{
struct V_13 * V_16 =
F_285 ( V_399 , struct V_13 , V_398 ) ;
F_253 ( V_16 ) ;
}
static int F_286 ( struct V_13 * V_16 , T_2 V_34 )
{
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
if ( F_26 ( & V_16 -> V_23 ) ) {
if ( F_135 ( V_391 , & V_16 -> V_306 ) ) {
F_58 ( & V_16 -> V_310 ) ;
} else {
struct V_2 * V_3 = V_16 -> V_3 ;
F_58 ( & V_16 -> V_310 ) ;
F_54 ( & V_3 -> V_33 ) ;
F_287 ( & V_3 -> V_28 ,
V_16 -> V_21 >> V_109 ) ;
F_58 ( & V_3 -> V_33 ) ;
}
F_266 ( V_16 , 0 ) ;
F_288 ( & V_16 -> V_398 , F_284 ) ;
return 1 ;
}
F_58 ( & V_16 -> V_310 ) ;
return 0 ;
}
void F_221 ( struct V_13 * V_16 )
{
int V_23 ;
int V_400 ;
if ( ! V_16 )
return;
while ( 1 ) {
V_23 = F_10 ( & V_16 -> V_23 ) ;
if ( V_23 <= 3 )
break;
V_400 = F_289 ( & V_16 -> V_23 , V_23 , V_23 - 1 ) ;
if ( V_400 == V_23 )
return;
}
F_54 ( & V_16 -> V_310 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_135 ( V_391 , & V_16 -> V_306 ) )
F_55 ( & V_16 -> V_23 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_135 ( V_401 , & V_16 -> V_306 ) &&
! F_265 ( V_16 ) &&
F_202 ( V_394 , & V_16 -> V_306 ) )
F_55 ( & V_16 -> V_23 ) ;
F_286 ( V_16 , V_29 ) ;
}
void F_290 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_54 ( & V_16 -> V_310 ) ;
F_203 ( V_401 , & V_16 -> V_306 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 && ! F_265 ( V_16 ) &&
F_202 ( V_394 , & V_16 -> V_306 ) )
F_55 ( & V_16 -> V_23 ) ;
F_286 ( V_16 , V_106 ) ;
}
void F_291 ( struct V_13 * V_16 )
{
unsigned long V_122 ;
unsigned long V_188 ;
struct V_111 * V_111 ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
if ( ! F_105 ( V_111 ) )
continue;
F_104 ( V_111 ) ;
F_27 ( ! F_166 ( V_111 ) ) ;
F_89 ( V_111 ) ;
F_292 ( & V_111 -> V_4 -> V_402 ) ;
if ( ! F_105 ( V_111 ) ) {
F_293 ( & V_111 -> V_4 -> V_403 ,
F_294 ( V_111 ) ,
V_326 ) ;
}
F_295 ( & V_111 -> V_4 -> V_402 ) ;
F_190 ( V_111 ) ;
F_102 ( V_111 ) ;
}
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
}
int F_296 ( struct V_13 * V_16 )
{
unsigned long V_122 ;
unsigned long V_188 ;
int V_404 = 0 ;
F_269 ( V_16 ) ;
V_404 = F_270 ( V_311 , & V_16 -> V_306 ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_27 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
F_27 ( ! F_135 ( V_394 , & V_16 -> V_306 ) ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ )
F_297 ( F_141 ( V_16 , V_122 ) ) ;
return V_404 ;
}
static int F_298 ( T_3 V_21 , T_3 V_25 )
{
if ( V_25 < V_131 )
return 1 ;
if ( V_21 & ( V_131 - 1 ) )
return 1 ;
if ( ( V_21 + V_25 ) & ( V_131 - 1 ) )
return 1 ;
return 0 ;
}
int F_299 ( struct V_13 * V_16 )
{
unsigned long V_122 ;
struct V_111 * V_111 ;
unsigned long V_188 ;
F_208 ( V_390 , & V_16 -> V_306 ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
if ( V_111 )
F_153 ( V_111 ) ;
}
return 0 ;
}
int F_262 ( struct V_13 * V_16 )
{
unsigned long V_122 ;
struct V_111 * V_111 ;
unsigned long V_188 ;
F_203 ( V_390 , & V_16 -> V_306 ) ;
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = 0 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
F_118 ( V_111 ) ;
}
return 0 ;
}
int F_300 ( struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 )
{
struct V_111 * V_111 ;
int V_58 ;
int V_405 = 1 ;
int V_215 ;
unsigned long V_108 ;
if ( F_298 ( V_21 , V_22 - V_21 + 1 ) ) {
V_58 = F_107 ( V_3 , V_21 , V_22 ,
V_101 , 1 , NULL ) ;
if ( V_58 )
return 1 ;
}
while ( V_21 <= V_22 ) {
V_108 = V_21 >> V_109 ;
V_111 = F_88 ( V_3 -> V_4 , V_108 ) ;
if ( ! V_111 )
return 1 ;
V_215 = F_173 ( V_111 ) ;
F_90 ( V_111 ) ;
if ( ! V_215 ) {
V_405 = 0 ;
break;
}
V_21 += V_131 ;
}
return V_405 ;
}
int F_301 ( struct V_13 * V_16 )
{
return F_135 ( V_390 , & V_16 -> V_306 ) ;
}
int F_302 ( struct V_2 * V_3 ,
struct V_13 * V_16 , T_3 V_21 , int V_91 ,
T_9 * V_251 , int V_159 )
{
unsigned long V_122 ;
unsigned long V_406 ;
struct V_111 * V_111 ;
int V_79 ;
int V_58 = 0 ;
int V_407 = 0 ;
int V_408 = 1 ;
unsigned long V_188 ;
unsigned long V_409 = 0 ;
struct V_154 * V_154 = NULL ;
unsigned long V_204 = 0 ;
if ( F_135 ( V_390 , & V_16 -> V_306 ) )
return 0 ;
if ( V_21 ) {
F_27 ( V_21 < V_16 -> V_21 ) ;
V_406 = ( V_21 >> V_109 ) -
( V_16 -> V_21 >> V_109 ) ;
} else {
V_406 = 0 ;
}
V_188 = F_140 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_122 = V_406 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
if ( V_91 == V_410 ) {
if ( ! F_206 ( V_111 ) )
goto V_411;
} else {
F_104 ( V_111 ) ;
}
V_407 ++ ;
if ( ! F_173 ( V_111 ) ) {
V_409 ++ ;
V_408 = 0 ;
}
}
if ( V_408 ) {
if ( V_406 == 0 )
F_203 ( V_390 , & V_16 -> V_306 ) ;
goto V_411;
}
F_208 ( V_316 , & V_16 -> V_306 ) ;
V_16 -> V_412 = 0 ;
F_22 ( & V_16 -> V_315 , V_409 ) ;
for ( V_122 = V_406 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
if ( ! F_173 ( V_111 ) ) {
F_190 ( V_111 ) ;
V_79 = F_171 ( V_3 , V_111 ,
V_251 , & V_154 ,
V_159 , & V_204 ) ;
if ( V_79 )
V_58 = V_79 ;
} else {
F_102 ( V_111 ) ;
}
}
if ( V_154 ) {
V_79 = F_159 ( V_273 , V_154 , V_159 , V_204 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_58 || V_91 != V_413 )
return V_58 ;
for ( V_122 = V_406 ; V_122 < V_188 ; V_122 ++ ) {
V_111 = F_141 ( V_16 , V_122 ) ;
F_303 ( V_111 ) ;
if ( ! F_173 ( V_111 ) )
V_58 = - V_170 ;
}
return V_58 ;
V_411:
V_122 = V_406 ;
while ( V_407 > 0 ) {
V_111 = F_141 ( V_16 , V_122 ) ;
V_122 ++ ;
F_102 ( V_111 ) ;
V_407 -- ;
}
return V_58 ;
}
void F_304 ( struct V_13 * V_16 , void * V_414 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_111 * V_111 ;
char * V_415 ;
char * V_416 = ( char * ) V_414 ;
T_6 V_417 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_21 ) >> V_109 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_417 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_111 = F_141 ( V_16 , V_122 ) ;
V_253 = F_112 ( V_25 , ( V_131 - V_44 ) ) ;
V_415 = F_305 ( V_111 ) ;
memcpy ( V_416 , V_415 + V_44 , V_253 ) ;
V_416 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_122 ++ ;
}
}
int F_306 ( struct V_13 * V_16 , unsigned long V_21 ,
unsigned long V_418 , char * * V_339 ,
unsigned long * V_419 ,
unsigned long * V_420 )
{
T_6 V_44 = V_21 & ( V_131 - 1 ) ;
char * V_415 ;
struct V_111 * V_46 ;
T_6 V_417 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_21 ) >> V_109 ;
unsigned long V_421 = ( V_417 + V_21 + V_418 - 1 ) >>
V_109 ;
if ( V_122 != V_421 )
return - V_362 ;
if ( V_122 == 0 ) {
V_44 = V_417 ;
* V_419 = 0 ;
} else {
V_44 = 0 ;
* V_419 = ( ( T_3 ) V_122 << V_109 ) - V_417 ;
}
if ( V_21 + V_418 > V_16 -> V_25 ) {
F_43 ( 1 , V_20 L_31
L_32 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , V_21 , V_418 ) ;
return - V_362 ;
}
V_46 = F_141 ( V_16 , V_122 ) ;
V_415 = F_305 ( V_46 ) ;
* V_339 = V_415 + V_44 ;
* V_420 = V_131 - V_44 ;
return 0 ;
}
int F_307 ( struct V_13 * V_16 , const void * V_422 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_111 * V_111 ;
char * V_415 ;
char * V_423 = ( char * ) V_422 ;
T_6 V_417 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_21 ) >> V_109 ;
int V_58 = 0 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_417 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_111 = F_141 ( V_16 , V_122 ) ;
V_253 = F_112 ( V_25 , ( V_131 - V_44 ) ) ;
V_415 = F_305 ( V_111 ) ;
V_58 = memcmp ( V_423 , V_415 + V_44 , V_253 ) ;
if ( V_58 )
break;
V_423 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_122 ++ ;
}
return V_58 ;
}
void F_308 ( struct V_13 * V_16 , const void * V_424 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_111 * V_111 ;
char * V_415 ;
char * V_389 = ( char * ) V_424 ;
T_6 V_417 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_21 ) >> V_109 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_417 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_111 = F_141 ( V_16 , V_122 ) ;
F_27 ( ! F_173 ( V_111 ) ) ;
V_253 = F_112 ( V_25 , V_131 - V_44 ) ;
V_415 = F_305 ( V_111 ) ;
memcpy ( V_415 + V_44 , V_389 , V_253 ) ;
V_389 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_122 ++ ;
}
}
void F_309 ( struct V_13 * V_16 , char V_425 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_111 * V_111 ;
char * V_415 ;
T_6 V_417 = V_16 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_21 ) >> V_109 ;
F_27 ( V_21 > V_16 -> V_25 ) ;
F_27 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_417 + V_21 ) & ( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_111 = F_141 ( V_16 , V_122 ) ;
F_27 ( ! F_173 ( V_111 ) ) ;
V_253 = F_112 ( V_25 , V_131 - V_44 ) ;
V_415 = F_305 ( V_111 ) ;
memset ( V_415 + V_44 , V_425 , V_253 ) ;
V_25 -= V_253 ;
V_44 = 0 ;
V_122 ++ ;
}
}
void F_260 ( struct V_13 * V_416 , struct V_13 * V_389 ,
unsigned long V_426 , unsigned long V_427 ,
unsigned long V_25 )
{
T_3 V_428 = V_416 -> V_25 ;
T_6 V_253 ;
T_6 V_44 ;
struct V_111 * V_111 ;
char * V_415 ;
T_6 V_417 = V_416 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_122 = ( V_417 + V_426 ) >> V_109 ;
F_27 ( V_389 -> V_25 != V_428 ) ;
V_44 = ( V_417 + V_426 ) &
( ( unsigned long ) V_131 - 1 ) ;
while ( V_25 > 0 ) {
V_111 = F_141 ( V_416 , V_122 ) ;
F_27 ( ! F_173 ( V_111 ) ) ;
V_253 = F_112 ( V_25 , ( unsigned long ) ( V_131 - V_44 ) ) ;
V_415 = F_305 ( V_111 ) ;
F_304 ( V_389 , V_415 + V_44 , V_427 , V_253 ) ;
V_427 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_122 ++ ;
}
}
static void F_310 ( struct V_111 * V_429 , struct V_111 * V_430 ,
unsigned long V_431 , unsigned long V_432 ,
unsigned long V_25 )
{
char * V_433 = F_305 ( V_429 ) ;
if ( V_429 == V_430 ) {
memmove ( V_433 + V_431 , V_433 + V_432 , V_25 ) ;
} else {
char * V_434 = F_305 ( V_430 ) ;
char * V_46 = V_433 + V_431 + V_25 ;
char * V_435 = V_434 + V_432 + V_25 ;
while ( V_25 -- )
* -- V_46 = * -- V_435 ;
}
}
static inline bool F_311 ( unsigned long V_389 , unsigned long V_416 , unsigned long V_25 )
{
unsigned long V_436 = ( V_389 > V_416 ) ? V_389 - V_416 : V_416 - V_389 ;
return V_436 < V_25 ;
}
static void F_312 ( struct V_111 * V_429 , struct V_111 * V_430 ,
unsigned long V_431 , unsigned long V_432 ,
unsigned long V_25 )
{
char * V_433 = F_305 ( V_429 ) ;
char * V_434 ;
int V_437 = 0 ;
if ( V_429 != V_430 ) {
V_434 = F_305 ( V_430 ) ;
} else {
V_434 = V_433 ;
if ( F_311 ( V_432 , V_431 , V_25 ) )
V_437 = 1 ;
}
if ( V_437 )
memmove ( V_433 + V_431 , V_434 + V_432 , V_25 ) ;
else
memcpy ( V_433 + V_431 , V_434 + V_432 , V_25 ) ;
}
void F_313 ( struct V_13 * V_416 , unsigned long V_426 ,
unsigned long V_427 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_438 ;
T_6 V_439 ;
T_6 V_417 = V_416 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_440 ;
unsigned long V_441 ;
if ( V_427 + V_25 > V_416 -> V_25 ) {
F_9 ( V_20 L_33
L_34 , V_427 , V_25 , V_416 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_426 + V_25 > V_416 -> V_25 ) {
F_9 ( V_20 L_35
L_34 , V_426 , V_25 , V_416 -> V_25 ) ;
F_56 ( 1 ) ;
}
while ( V_25 > 0 ) {
V_438 = ( V_417 + V_426 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_439 = ( V_417 + V_427 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_440 = ( V_417 + V_426 ) >> V_109 ;
V_441 = ( V_417 + V_427 ) >> V_109 ;
V_253 = F_112 ( V_25 , ( unsigned long ) ( V_131 -
V_439 ) ) ;
V_253 = F_101 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_312 ( F_141 ( V_416 , V_440 ) ,
F_141 ( V_416 , V_441 ) ,
V_438 , V_439 , V_253 ) ;
V_427 += V_253 ;
V_426 += V_253 ;
V_25 -= V_253 ;
}
}
void F_314 ( struct V_13 * V_416 , unsigned long V_426 ,
unsigned long V_427 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_438 ;
T_6 V_439 ;
unsigned long V_442 = V_426 + V_25 - 1 ;
unsigned long V_443 = V_427 + V_25 - 1 ;
T_6 V_417 = V_416 -> V_21 & ( ( T_3 ) V_131 - 1 ) ;
unsigned long V_440 ;
unsigned long V_441 ;
if ( V_427 + V_25 > V_416 -> V_25 ) {
F_9 ( V_20 L_33
L_36 , V_427 , V_25 , V_416 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_426 + V_25 > V_416 -> V_25 ) {
F_9 ( V_20 L_35
L_36 , V_426 , V_25 , V_416 -> V_25 ) ;
F_56 ( 1 ) ;
}
if ( V_426 < V_427 ) {
F_313 ( V_416 , V_426 , V_427 , V_25 ) ;
return;
}
while ( V_25 > 0 ) {
V_440 = ( V_417 + V_442 ) >> V_109 ;
V_441 = ( V_417 + V_443 ) >> V_109 ;
V_438 = ( V_417 + V_442 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_439 = ( V_417 + V_443 ) &
( ( unsigned long ) V_131 - 1 ) ;
V_253 = F_101 (unsigned long, len, src_off_in_page + 1 ) ;
V_253 = F_112 ( V_253 , V_438 + 1 ) ;
F_310 ( F_141 ( V_416 , V_440 ) ,
F_141 ( V_416 , V_441 ) ,
V_438 - V_253 + 1 ,
V_439 - V_253 + 1 , V_253 ) ;
V_442 -= V_253 ;
V_443 -= V_253 ;
V_25 -= V_253 ;
}
}
int F_315 ( struct V_111 * V_111 , T_2 V_34 )
{
struct V_13 * V_16 ;
F_54 ( & V_111 -> V_4 -> V_329 ) ;
if ( ! F_166 ( V_111 ) ) {
F_58 ( & V_111 -> V_4 -> V_329 ) ;
return 1 ;
}
V_16 = (struct V_13 * ) V_111 -> V_37 ;
F_56 ( ! V_16 ) ;
F_54 ( & V_16 -> V_310 ) ;
if ( F_10 ( & V_16 -> V_23 ) != 1 || F_265 ( V_16 ) ) {
F_58 ( & V_16 -> V_310 ) ;
F_58 ( & V_111 -> V_4 -> V_329 ) ;
return 0 ;
}
F_58 ( & V_111 -> V_4 -> V_329 ) ;
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
if ( ! F_202 ( V_394 , & V_16 -> V_306 ) ) {
F_58 ( & V_16 -> V_310 ) ;
return 0 ;
}
return F_286 ( V_16 , V_34 ) ;
}
