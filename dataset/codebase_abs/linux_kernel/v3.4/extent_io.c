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
if ( V_7 )
F_5 ( V_7 ) ;
if ( V_12 )
F_5 ( V_12 ) ;
}
void F_13 ( struct V_2 * V_3 ,
struct V_26 * V_4 )
{
V_3 -> V_15 = V_27 ;
F_14 ( & V_3 -> V_28 , V_29 ) ;
V_3 -> V_30 = NULL ;
V_3 -> V_31 = 0 ;
F_15 ( & V_3 -> V_32 ) ;
F_15 ( & V_3 -> V_33 ) ;
V_3 -> V_4 = V_4 ;
}
static struct V_8 * F_16 ( T_2 V_34 )
{
struct V_8 * V_15 ;
#if V_35
unsigned long V_36 ;
#endif
V_15 = F_17 ( V_7 , V_34 ) ;
if ( ! V_15 )
return V_15 ;
V_15 -> V_15 = 0 ;
V_15 -> V_37 = 0 ;
V_15 -> V_3 = NULL ;
#if V_35
F_18 ( & V_38 , V_36 ) ;
F_19 ( & V_15 -> V_19 , & V_17 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
F_21 ( & V_15 -> V_23 , 1 ) ;
F_22 ( & V_15 -> V_39 ) ;
F_23 ( V_15 , V_34 , V_40 ) ;
return V_15 ;
}
void F_24 ( struct V_8 * V_15 )
{
if ( ! V_15 )
return;
if ( F_25 ( & V_15 -> V_23 ) ) {
#if V_35
unsigned long V_36 ;
#endif
F_26 ( V_15 -> V_3 ) ;
#if V_35
F_18 ( & V_38 , V_36 ) ;
F_11 ( & V_15 -> V_19 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
F_27 ( V_15 , V_40 ) ;
F_12 ( V_7 , V_15 ) ;
}
}
static struct V_41 * F_28 ( struct V_42 * V_43 , T_3 V_44 ,
struct V_41 * V_45 )
{
struct V_41 * * V_46 = & V_43 -> V_41 ;
struct V_41 * V_47 = NULL ;
struct V_48 * V_49 ;
while ( * V_46 ) {
V_47 = * V_46 ;
V_49 = F_29 ( V_47 , struct V_48 , V_41 ) ;
if ( V_44 < V_49 -> V_21 )
V_46 = & ( * V_46 ) -> V_50 ;
else if ( V_44 > V_49 -> V_22 )
V_46 = & ( * V_46 ) -> V_51 ;
else
return V_47 ;
}
V_49 = F_29 ( V_45 , struct V_48 , V_41 ) ;
F_30 ( V_45 , V_47 , V_46 ) ;
F_31 ( V_45 , V_43 ) ;
return NULL ;
}
static struct V_41 * F_32 ( struct V_2 * V_3 , T_3 V_44 ,
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
V_49 = F_29 ( V_54 , struct V_48 , V_41 ) ;
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
V_55 = F_33 ( V_55 ) ;
V_57 = F_29 ( V_55 , struct V_48 , V_41 ) ;
}
* V_52 = V_55 ;
V_55 = V_56 ;
}
if ( V_53 ) {
V_57 = F_29 ( V_55 , struct V_48 , V_41 ) ;
while ( V_55 && V_44 < V_57 -> V_21 ) {
V_55 = F_34 ( V_55 ) ;
V_57 = F_29 ( V_55 , struct V_48 , V_41 ) ;
}
* V_53 = V_55 ;
}
return NULL ;
}
static inline struct V_41 * F_35 ( struct V_2 * V_3 ,
T_3 V_44 )
{
struct V_41 * V_55 = NULL ;
struct V_41 * V_58 ;
V_58 = F_32 ( V_3 , V_44 , & V_55 , NULL ) ;
if ( ! V_58 )
return V_55 ;
return V_58 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_8 * V_59 ,
struct V_8 * V_60 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_61 )
V_3 -> V_30 -> V_61 ( V_3 -> V_4 -> V_5 , V_59 ,
V_60 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_8 * V_15 )
{
struct V_8 * V_60 ;
struct V_41 * V_62 ;
if ( V_15 -> V_15 & ( V_63 | V_64 ) )
return;
V_62 = F_34 ( & V_15 -> V_41 ) ;
if ( V_62 ) {
V_60 = F_29 ( V_62 , struct V_8 , V_41 ) ;
if ( V_60 -> V_22 == V_15 -> V_21 - 1 &&
V_60 -> V_15 == V_15 -> V_15 ) {
F_36 ( V_3 , V_15 , V_60 ) ;
V_15 -> V_21 = V_60 -> V_21 ;
V_60 -> V_3 = NULL ;
F_38 ( & V_60 -> V_41 , & V_3 -> V_15 ) ;
F_24 ( V_60 ) ;
}
}
V_62 = F_33 ( & V_15 -> V_41 ) ;
if ( V_62 ) {
V_60 = F_29 ( V_62 , struct V_8 , V_41 ) ;
if ( V_60 -> V_21 == V_15 -> V_22 + 1 &&
V_60 -> V_15 == V_15 -> V_15 ) {
F_36 ( V_3 , V_15 , V_60 ) ;
V_15 -> V_22 = V_60 -> V_22 ;
V_60 -> V_3 = NULL ;
F_38 ( & V_60 -> V_41 , & V_3 -> V_15 ) ;
F_24 ( V_60 ) ;
}
}
}
static void F_39 ( struct V_2 * V_3 ,
struct V_8 * V_15 , int * V_65 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_66 )
V_3 -> V_30 -> V_66 ( V_3 -> V_4 -> V_5 , V_15 , V_65 ) ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_8 * V_15 , int * V_65 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_67 )
V_3 -> V_30 -> V_67 ( V_3 -> V_4 -> V_5 , V_15 , V_65 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_8 * V_15 , T_3 V_21 , T_3 V_22 ,
int * V_65 )
{
struct V_41 * V_45 ;
if ( V_22 < V_21 ) {
F_9 ( V_20 L_7 ,
( unsigned long long ) V_22 ,
( unsigned long long ) V_21 ) ;
F_26 ( 1 ) ;
}
V_15 -> V_21 = V_21 ;
V_15 -> V_22 = V_22 ;
F_42 ( V_3 , V_15 , V_65 ) ;
V_45 = F_28 ( & V_3 -> V_15 , V_22 , & V_15 -> V_41 ) ;
if ( V_45 ) {
struct V_8 * V_68 ;
V_68 = F_29 ( V_45 , struct V_8 , V_41 ) ;
F_9 ( V_20 L_8
L_9 , ( unsigned long long ) V_68 -> V_21 ,
( unsigned long long ) V_68 -> V_22 ,
( unsigned long long ) V_21 , ( unsigned long long ) V_22 ) ;
return - V_69 ;
}
V_15 -> V_3 = V_3 ;
F_37 ( V_3 , V_15 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 , struct V_8 * V_70 ,
T_3 V_71 )
{
if ( V_3 -> V_30 && V_3 -> V_30 -> V_72 )
V_3 -> V_30 -> V_72 ( V_3 -> V_4 -> V_5 , V_70 , V_71 ) ;
}
static int F_44 ( struct V_2 * V_3 , struct V_8 * V_70 ,
struct V_8 * V_73 , T_3 V_71 )
{
struct V_41 * V_45 ;
F_43 ( V_3 , V_70 , V_71 ) ;
V_73 -> V_21 = V_70 -> V_21 ;
V_73 -> V_22 = V_71 - 1 ;
V_73 -> V_15 = V_70 -> V_15 ;
V_70 -> V_21 = V_71 ;
V_45 = F_28 ( & V_3 -> V_15 , V_73 -> V_22 , & V_73 -> V_41 ) ;
if ( V_45 ) {
F_24 ( V_73 ) ;
return - V_69 ;
}
V_73 -> V_3 = V_3 ;
return 0 ;
}
static struct V_8 * F_45 ( struct V_8 * V_15 )
{
struct V_41 * V_18 = F_33 ( & V_15 -> V_41 ) ;
if ( V_18 )
return F_29 ( V_18 , struct V_8 , V_41 ) ;
else
return NULL ;
}
static struct V_8 * F_46 ( struct V_2 * V_3 ,
struct V_8 * V_15 ,
int * V_65 , int V_74 )
{
struct V_8 * V_18 ;
int V_75 = * V_65 & ~ V_76 ;
if ( ( V_75 & V_77 ) && ( V_15 -> V_15 & V_77 ) ) {
T_3 V_78 = V_15 -> V_22 - V_15 -> V_21 + 1 ;
F_26 ( V_78 > V_3 -> V_31 ) ;
V_3 -> V_31 -= V_78 ;
}
F_40 ( V_3 , V_15 , V_65 ) ;
V_15 -> V_15 &= ~ V_75 ;
if ( V_74 )
F_47 ( & V_15 -> V_39 ) ;
if ( V_15 -> V_15 == 0 ) {
V_18 = F_45 ( V_15 ) ;
if ( V_15 -> V_3 ) {
F_38 ( & V_15 -> V_41 , & V_3 -> V_15 ) ;
V_15 -> V_3 = NULL ;
F_24 ( V_15 ) ;
} else {
F_26 ( 1 ) ;
}
} else {
F_37 ( V_3 , V_15 ) ;
V_18 = F_45 ( V_15 ) ;
}
return V_18 ;
}
static struct V_8 *
F_48 ( struct V_8 * V_73 )
{
if ( ! V_73 )
V_73 = F_16 ( V_29 ) ;
return V_73 ;
}
void F_49 ( struct V_2 * V_3 , int V_79 )
{
F_50 ( F_1 ( V_3 ) , V_79 , L_10
L_11
L_12 ) ;
}
int F_51 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
V_73 = F_16 ( V_34 ) ;
if ( ! V_73 )
return - V_11 ;
}
F_52 ( & V_3 -> V_32 ) ;
if ( V_81 ) {
V_82 = * V_81 ;
if ( V_84 ) {
* V_81 = NULL ;
V_81 = NULL ;
}
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 ) {
if ( V_84 )
F_53 ( & V_82 -> V_23 ) ;
V_15 = V_82 ;
goto V_88;
}
if ( V_84 )
F_24 ( V_82 ) ;
}
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 )
goto V_89;
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
V_88:
if ( V_15 -> V_21 > V_22 )
goto V_89;
F_26 ( V_15 -> V_22 < V_21 ) ;
V_83 = V_15 -> V_22 ;
if ( ! ( V_15 -> V_15 & V_65 ) ) {
V_15 = F_45 ( V_15 ) ;
goto V_18;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_44 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_46 ( V_3 , V_15 , & V_65 , V_74 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
}
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_44 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
if ( V_74 )
F_47 ( & V_15 -> V_39 ) ;
F_46 ( V_3 , V_73 , & V_65 , V_74 ) ;
V_73 = NULL ;
goto V_89;
}
V_15 = F_46 ( V_3 , V_15 , & V_65 , V_74 ) ;
V_18:
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 <= V_22 && V_15 && ! F_55 () )
goto V_88;
goto V_90;
V_89:
F_56 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_24 ( V_73 ) ;
return 0 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_56 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_57 () ;
goto V_86;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_8 * V_15 )
__releases( V_3 -> V_32 )
__acquires( V_3 -> V_32 )
{
F_59 ( V_91 ) ;
F_60 ( & V_15 -> V_39 , & V_91 , V_92 ) ;
F_56 ( & V_3 -> V_32 ) ;
F_61 () ;
F_52 ( & V_3 -> V_32 ) ;
F_62 ( & V_15 -> V_39 , & V_91 ) ;
}
void F_63 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 )
{
struct V_8 * V_15 ;
struct V_41 * V_45 ;
F_52 ( & V_3 -> V_32 ) ;
V_86:
while ( 1 ) {
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 )
break;
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_22 )
goto V_89;
if ( V_15 -> V_15 & V_65 ) {
V_21 = V_15 -> V_21 ;
F_64 ( & V_15 -> V_23 ) ;
F_58 ( V_3 , V_15 ) ;
F_24 ( V_15 ) ;
goto V_86;
}
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
F_65 ( & V_3 -> V_32 ) ;
}
V_89:
F_56 ( & V_3 -> V_32 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_8 * V_15 ,
int * V_65 )
{
int V_93 = * V_65 & ~ V_76 ;
F_39 ( V_3 , V_15 , V_65 ) ;
if ( ( V_93 & V_77 ) && ! ( V_15 -> V_15 & V_77 ) ) {
T_3 V_78 = V_15 -> V_22 - V_15 -> V_21 + 1 ;
V_3 -> V_31 += V_78 ;
}
V_15 -> V_15 |= V_93 ;
}
static void F_66 ( struct V_8 * V_15 ,
struct V_8 * * V_94 )
{
if ( V_94 && ! ( * V_94 ) ) {
if ( V_15 -> V_15 & ( V_63 | V_64 ) ) {
* V_94 = V_15 ;
F_64 ( & V_15 -> V_23 ) ;
}
}
}
static void F_67 ( struct V_8 * * V_94 )
{
if ( V_94 && ( * V_94 ) ) {
struct V_8 * V_15 = * V_94 ;
* V_94 = NULL ;
F_24 ( V_15 ) ;
}
}
static int T_4
F_68 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
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
V_73 = F_16 ( V_34 ) ;
F_54 ( ! V_73 ) ;
}
F_52 ( & V_3 -> V_32 ) ;
if ( V_81 && * V_81 ) {
V_15 = * V_81 ;
if ( V_15 -> V_21 <= V_21 && V_15 -> V_22 > V_21 &&
V_15 -> V_3 ) {
V_45 = & V_15 -> V_41 ;
goto V_88;
}
}
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_41 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
V_88:
V_97 = V_15 -> V_21 ;
V_83 = V_15 -> V_22 ;
if ( V_15 -> V_21 == V_21 && V_15 -> V_22 <= V_22 ) {
struct V_41 * V_98 ;
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_15 -> V_21 ;
V_79 = - V_69 ;
goto V_89;
}
F_42 ( V_3 , V_15 , & V_65 ) ;
F_66 ( V_15 , V_81 ) ;
F_37 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_98 = F_33 ( & V_15 -> V_41 ) ;
if ( V_98 && V_21 < V_22 && V_73 && ! F_55 () ) {
V_15 = F_29 ( V_98 , struct V_8 ,
V_41 ) ;
if ( V_15 -> V_21 == V_21 )
goto V_88;
}
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_21 ;
V_79 = - V_69 ;
goto V_89;
}
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_44 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_42 ( V_3 , V_15 , & V_65 ) ;
F_66 ( V_15 , V_81 ) ;
F_37 ( V_3 , V_15 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
}
goto V_90;
}
if ( V_15 -> V_21 > V_21 ) {
T_3 V_99 ;
if ( V_22 < V_97 )
V_99 = V_22 ;
else
V_99 = V_97 - 1 ;
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_41 ( V_3 , V_73 , V_21 , V_99 ,
& V_65 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
F_66 ( V_73 , V_81 ) ;
V_73 = NULL ;
V_21 = V_99 + 1 ;
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
if ( V_15 -> V_15 & V_95 ) {
* V_96 = V_21 ;
V_79 = - V_69 ;
goto V_89;
}
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_44 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
F_42 ( V_3 , V_73 , & V_65 ) ;
F_66 ( V_73 , V_81 ) ;
F_37 ( V_3 , V_73 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_56 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_24 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_56 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_57 () ;
goto V_86;
}
int F_69 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 , int V_65 ,
T_3 * V_96 , struct V_8 * * V_81 ,
T_2 V_34 )
{
return F_68 ( V_3 , V_21 , V_22 , V_65 , 0 , V_96 ,
V_81 , V_34 ) ;
}
int F_70 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_100 , T_2 V_34 )
{
struct V_8 * V_15 ;
struct V_8 * V_73 = NULL ;
struct V_41 * V_45 ;
int V_79 = 0 ;
T_3 V_97 ;
T_3 V_83 ;
V_86:
if ( ! V_73 && ( V_34 & V_87 ) ) {
V_73 = F_16 ( V_34 ) ;
if ( ! V_73 )
return - V_11 ;
}
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_73 = F_48 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_41 ( V_3 , V_73 , V_21 , V_22 , & V_65 ) ;
V_73 = NULL ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
V_88:
V_97 = V_15 -> V_21 ;
V_83 = V_15 -> V_22 ;
if ( V_15 -> V_21 == V_21 && V_15 -> V_22 <= V_22 ) {
struct V_41 * V_98 ;
F_42 ( V_3 , V_15 , & V_65 ) ;
F_46 ( V_3 , V_15 , & V_100 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
V_98 = F_33 ( & V_15 -> V_41 ) ;
if ( V_98 && V_21 < V_22 && V_73 && ! F_55 () ) {
V_15 = F_29 ( V_98 , struct V_8 ,
V_41 ) ;
if ( V_15 -> V_21 == V_21 )
goto V_88;
}
goto V_90;
}
if ( V_15 -> V_21 < V_21 ) {
V_73 = F_48 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_44 ( V_3 , V_15 , V_73 , V_21 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
if ( V_79 )
goto V_89;
if ( V_15 -> V_22 <= V_22 ) {
F_42 ( V_3 , V_15 , & V_65 ) ;
F_46 ( V_3 , V_15 , & V_100 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
}
goto V_90;
}
if ( V_15 -> V_21 > V_21 ) {
T_3 V_99 ;
if ( V_22 < V_97 )
V_99 = V_22 ;
else
V_99 = V_97 - 1 ;
V_73 = F_48 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_41 ( V_3 , V_73 , V_21 , V_99 ,
& V_65 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
V_21 = V_99 + 1 ;
goto V_90;
}
if ( V_15 -> V_21 <= V_22 && V_15 -> V_22 > V_22 ) {
V_73 = F_48 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_44 ( V_3 , V_15 , V_73 , V_22 + 1 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
F_42 ( V_3 , V_73 , & V_65 ) ;
F_46 ( V_3 , V_73 , & V_100 , 0 ) ;
V_73 = NULL ;
goto V_89;
}
goto V_90;
V_89:
F_56 ( & V_3 -> V_32 ) ;
if ( V_73 )
F_24 ( V_73 ) ;
return V_79 ;
V_90:
if ( V_21 > V_22 )
goto V_89;
F_56 ( & V_3 -> V_32 ) ;
if ( V_34 & V_87 )
F_57 () ;
goto V_86;
}
int F_71 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_77 , NULL ,
NULL , V_34 ) ;
}
int F_72 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_65 , NULL ,
NULL , V_34 ) ;
}
int F_73 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 , V_65 , 0 , 0 , NULL , V_34 ) ;
}
int F_74 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 ,
V_101 | V_102 ,
NULL , V_81 , V_34 ) ;
}
int F_75 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 ,
V_77 | V_101 |
V_103 , 0 , 0 , NULL , V_34 ) ;
}
int F_76 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_104 , NULL ,
NULL , V_34 ) ;
}
int F_77 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_102 , 0 ,
V_81 , V_34 ) ;
}
static int F_78 ( struct V_2 * V_3 , T_3 V_21 ,
T_3 V_22 , struct V_8 * * V_81 ,
T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 , V_102 , 0 , 0 ,
V_81 , V_34 ) ;
}
int F_79 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , struct V_8 * * V_81 )
{
int V_79 ;
T_3 V_96 ;
while ( 1 ) {
V_79 = F_68 ( V_3 , V_21 , V_22 , V_105 | V_65 ,
V_105 , & V_96 ,
V_81 , V_106 ) ;
if ( V_79 == - V_69 ) {
F_63 ( V_3 , V_96 , V_22 , V_105 ) ;
V_21 = V_96 ;
} else
break;
F_26 ( V_21 > V_22 ) ;
}
return V_79 ;
}
int F_80 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_79 ( V_3 , V_21 , V_22 , 0 , NULL ) ;
}
int F_81 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
int V_79 ;
T_3 V_96 ;
V_79 = F_68 ( V_3 , V_21 , V_22 , V_105 , V_105 ,
& V_96 , NULL , V_106 ) ;
if ( V_79 == - V_69 ) {
if ( V_96 > V_21 )
F_51 ( V_3 , V_21 , V_96 - 1 ,
V_105 , 1 , 0 , NULL , V_106 ) ;
return 0 ;
}
return 1 ;
}
int F_82 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_82 , T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , V_82 ,
V_34 ) ;
}
int F_83 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_51 ( V_3 , V_21 , V_22 , V_105 , 1 , 0 , NULL ,
V_106 ) ;
}
static int F_84 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
struct V_110 * V_110 ;
while ( V_107 <= V_109 ) {
V_110 = F_85 ( V_3 -> V_4 , V_107 ) ;
F_54 ( ! V_110 ) ;
F_86 ( V_110 ) ;
F_87 ( V_110 ) ;
V_107 ++ ;
}
return 0 ;
}
struct V_8 * F_88 ( struct V_2 * V_3 ,
T_3 V_21 , int V_65 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_22 >= V_21 && ( V_15 -> V_15 & V_65 ) )
return V_15 ;
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 )
break;
}
V_89:
return NULL ;
}
int F_89 ( struct V_2 * V_3 , T_3 V_21 ,
T_3 * V_111 , T_3 * V_112 , int V_65 )
{
struct V_8 * V_15 ;
int V_58 = 1 ;
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_21 , V_65 ) ;
if ( V_15 ) {
* V_111 = V_15 -> V_21 ;
* V_112 = V_15 -> V_22 ;
V_58 = 0 ;
}
F_56 ( & V_3 -> V_32 ) ;
return V_58 ;
}
static T_5 T_3 F_90 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 * V_22 , T_3 V_113 ,
struct V_8 * * V_81 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_114 = * V_21 ;
T_3 V_68 = 0 ;
T_3 V_115 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_114 ) ;
if ( ! V_45 ) {
if ( ! V_68 )
* V_22 = ( T_3 ) - 1 ;
goto V_89;
}
while ( 1 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_68 && ( V_15 -> V_21 != V_114 ||
( V_15 -> V_15 & V_64 ) ) ) {
goto V_89;
}
if ( ! ( V_15 -> V_15 & V_101 ) ) {
if ( ! V_68 )
* V_22 = V_15 -> V_22 ;
goto V_89;
}
if ( ! V_68 ) {
* V_21 = V_15 -> V_21 ;
* V_81 = V_15 ;
F_64 ( & V_15 -> V_23 ) ;
}
V_68 ++ ;
* V_22 = V_15 -> V_22 ;
V_114 = V_15 -> V_22 + 1 ;
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 )
break;
V_115 += V_15 -> V_22 - V_15 -> V_21 + 1 ;
if ( V_115 >= V_113 )
break;
}
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_68 ;
}
static T_5 void F_91 ( struct V_116 * V_116 ,
struct V_110 * V_117 ,
T_3 V_21 , T_3 V_22 )
{
int V_58 ;
struct V_110 * V_118 [ 16 ] ;
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
unsigned long V_119 = V_109 - V_107 + 1 ;
int V_120 ;
if ( V_107 == V_117 -> V_107 && V_109 == V_107 )
return;
while ( V_119 > 0 ) {
V_58 = F_92 ( V_116 -> V_121 , V_107 ,
F_93 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_118 ) ;
for ( V_120 = 0 ; V_120 < V_58 ; V_120 ++ ) {
if ( V_118 [ V_120 ] != V_117 )
F_94 ( V_118 [ V_120 ] ) ;
F_87 ( V_118 [ V_120 ] ) ;
}
V_119 -= V_58 ;
V_107 += V_58 ;
F_57 () ;
}
}
static T_5 int F_95 ( struct V_116 * V_116 ,
struct V_110 * V_117 ,
T_3 V_122 ,
T_3 V_123 )
{
unsigned long V_107 = V_122 >> V_108 ;
unsigned long V_124 = V_107 ;
unsigned long V_109 = V_123 >> V_108 ;
unsigned long V_125 = 0 ;
struct V_110 * V_118 [ 16 ] ;
unsigned long V_126 ;
int V_58 ;
int V_120 ;
if ( V_107 == V_117 -> V_107 && V_107 == V_109 )
return 0 ;
V_126 = V_109 - V_107 + 1 ;
while ( V_126 > 0 ) {
V_58 = F_92 ( V_116 -> V_121 , V_107 ,
F_93 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_118 ) ;
if ( V_58 == 0 ) {
V_58 = - V_127 ;
goto V_128;
}
for ( V_120 = 0 ; V_120 < V_58 ; V_120 ++ ) {
if ( V_118 [ V_120 ] != V_117 ) {
F_96 ( V_118 [ V_120 ] ) ;
if ( ! F_97 ( V_118 [ V_120 ] ) ||
V_118 [ V_120 ] -> V_4 != V_116 -> V_121 ) {
V_58 = - V_127 ;
F_94 ( V_118 [ V_120 ] ) ;
F_87 ( V_118 [ V_120 ] ) ;
goto V_128;
}
}
F_87 ( V_118 [ V_120 ] ) ;
V_125 ++ ;
}
V_126 -= V_58 ;
V_107 += V_58 ;
F_57 () ;
}
V_58 = 0 ;
V_128:
if ( V_58 && V_125 ) {
F_91 ( V_116 , V_117 ,
V_122 ,
( ( T_3 ) ( V_124 + V_125 - 1 ) ) <<
V_108 ) ;
}
return V_58 ;
}
static T_5 T_3 F_98 ( struct V_116 * V_116 ,
struct V_2 * V_3 ,
struct V_110 * V_117 ,
T_3 * V_21 , T_3 * V_22 ,
T_3 V_113 )
{
T_3 V_122 ;
T_3 V_123 ;
T_3 V_68 ;
struct V_8 * V_81 = NULL ;
int V_58 ;
int V_129 = 0 ;
V_86:
V_122 = * V_21 ;
V_123 = 0 ;
V_68 = F_90 ( V_3 , & V_122 , & V_123 ,
V_113 , & V_81 ) ;
if ( ! V_68 || V_123 <= * V_21 ) {
* V_21 = V_122 ;
* V_22 = V_123 ;
F_24 ( V_81 ) ;
return V_68 ;
}
if ( V_122 < * V_21 )
V_122 = * V_21 ;
if ( V_123 + 1 - V_122 > V_113 && V_129 )
V_123 = V_122 + V_130 - 1 ;
V_58 = F_95 ( V_116 , V_117 ,
V_122 , V_123 ) ;
if ( V_58 == - V_127 ) {
F_24 ( V_81 ) ;
if ( ! V_129 ) {
unsigned long V_44 = ( * V_21 ) & ( V_130 - 1 ) ;
V_113 = V_130 - V_44 ;
V_129 = 1 ;
goto V_86;
} else {
V_68 = 0 ;
goto V_131;
}
}
F_54 ( V_58 ) ;
F_79 ( V_3 , V_122 , V_123 , 0 , & V_81 ) ;
V_58 = F_99 ( V_3 , V_122 , V_123 ,
V_101 , 1 , V_81 ) ;
if ( ! V_58 ) {
F_82 ( V_3 , V_122 , V_123 ,
& V_81 , V_106 ) ;
F_91 ( V_116 , V_117 ,
V_122 , V_123 ) ;
F_57 () ;
goto V_86;
}
F_24 ( V_81 ) ;
* V_21 = V_122 ;
* V_22 = V_123 ;
V_131:
return V_68 ;
}
int F_100 ( struct V_116 * V_116 ,
struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 , struct V_110 * V_117 ,
unsigned long V_132 )
{
int V_58 ;
struct V_110 * V_118 [ 16 ] ;
unsigned long V_107 = V_21 >> V_108 ;
unsigned long V_109 = V_22 >> V_108 ;
unsigned long V_119 = V_109 - V_107 + 1 ;
int V_120 ;
int V_100 = 0 ;
if ( V_132 & V_133 )
V_100 |= V_105 ;
if ( V_132 & V_134 )
V_100 |= V_77 ;
if ( V_132 & V_135 )
V_100 |= V_101 ;
F_51 ( V_3 , V_21 , V_22 , V_100 , 1 , 0 , NULL , V_106 ) ;
if ( ! ( V_132 & ( V_136 | V_134 |
V_137 | V_138 |
V_139 ) ) )
return 0 ;
while ( V_119 > 0 ) {
V_58 = F_92 ( V_116 -> V_121 , V_107 ,
F_93 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_118 ) ;
for ( V_120 = 0 ; V_120 < V_58 ; V_120 ++ ) {
if ( V_132 & V_139 )
F_101 ( V_118 [ V_120 ] ) ;
if ( V_118 [ V_120 ] == V_117 ) {
F_87 ( V_118 [ V_120 ] ) ;
continue;
}
if ( V_132 & V_134 )
F_102 ( V_118 [ V_120 ] ) ;
if ( V_132 & V_137 )
F_86 ( V_118 [ V_120 ] ) ;
if ( V_132 & V_138 )
F_103 ( V_118 [ V_120 ] ) ;
if ( V_132 & V_136 )
F_94 ( V_118 [ V_120 ] ) ;
F_87 ( V_118 [ V_120 ] ) ;
}
V_119 -= V_58 ;
V_107 += V_58 ;
F_57 () ;
}
return 0 ;
}
T_3 F_104 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 V_140 , T_3 V_113 ,
unsigned long V_65 , int V_141 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_114 = * V_21 ;
T_3 V_115 = 0 ;
T_3 V_142 = 0 ;
int V_68 = 0 ;
if ( V_140 <= V_114 ) {
F_26 ( 1 ) ;
return 0 ;
}
F_52 ( & V_3 -> V_32 ) ;
if ( V_114 == 0 && V_65 == V_77 ) {
V_115 = V_3 -> V_31 ;
goto V_89;
}
V_45 = F_35 ( V_3 , V_114 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_140 )
break;
if ( V_141 && V_68 && V_15 -> V_21 > V_142 + 1 )
break;
if ( V_15 -> V_22 >= V_114 && ( V_15 -> V_15 & V_65 ) == V_65 ) {
V_115 += F_105 ( V_140 , V_15 -> V_22 ) + 1 -
F_106 ( V_114 , V_15 -> V_21 ) ;
if ( V_115 >= V_113 )
break;
if ( ! V_68 ) {
* V_21 = F_106 ( V_114 , V_15 -> V_21 ) ;
V_68 = 1 ;
}
V_142 = V_15 -> V_22 ;
} else if ( V_141 && V_68 ) {
break;
}
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 )
break;
}
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_115 ;
}
int F_107 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_58 = - V_143 ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_143 ;
goto V_89;
}
V_15 -> V_37 = V_37 ;
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_108 ( struct V_2 * V_3 , T_3 V_21 , T_3 * V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_58 = - V_143 ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_143 ;
goto V_89;
}
* V_37 = V_15 -> V_37 ;
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_99 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_144 , struct V_8 * V_82 )
{
struct V_8 * V_15 = NULL ;
struct V_41 * V_45 ;
int V_145 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 )
V_45 = & V_82 -> V_41 ;
else
V_45 = F_35 ( V_3 , V_21 ) ;
while ( V_45 && V_21 <= V_22 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_144 && V_15 -> V_21 > V_21 ) {
V_145 = 0 ;
break;
}
if ( V_15 -> V_21 > V_22 )
break;
if ( V_15 -> V_15 & V_65 ) {
V_145 = 1 ;
if ( ! V_144 )
break;
} else if ( V_144 ) {
V_145 = 0 ;
break;
}
if ( V_15 -> V_22 == ( T_3 ) - 1 )
break;
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 ) {
if ( V_144 )
V_145 = 0 ;
break;
}
}
F_56 ( & V_3 -> V_32 ) ;
return V_145 ;
}
static void F_109 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_130 - 1 ;
if ( F_99 ( V_3 , V_21 , V_22 , V_102 , 1 , NULL ) )
F_110 ( V_110 ) ;
}
static void F_111 ( struct V_2 * V_3 , struct V_110 * V_110 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_130 - 1 ;
if ( ! F_99 ( V_3 , V_21 , V_22 , V_105 , 0 , NULL ) )
F_94 ( V_110 ) ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_110 * V_110 )
{
F_103 ( V_110 ) ;
}
static int F_113 ( struct V_116 * V_116 , struct V_146 * V_147 ,
int V_148 )
{
int V_58 ;
int V_79 = 0 ;
struct V_2 * V_149 = & F_114 ( V_116 ) -> V_150 ;
F_107 ( V_149 , V_147 -> V_21 , 0 ) ;
V_58 = F_73 ( V_149 , V_147 -> V_21 ,
V_147 -> V_21 + V_147 -> V_25 - 1 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 )
V_79 = V_58 ;
if ( V_148 ) {
V_58 = F_73 ( & F_114 ( V_116 ) -> V_151 , V_147 -> V_21 ,
V_147 -> V_21 + V_147 -> V_25 - 1 ,
V_152 , V_106 ) ;
if ( V_58 && ! V_79 )
V_79 = V_58 ;
}
F_115 ( V_147 ) ;
return V_79 ;
}
static void F_116 ( struct V_153 * V_153 , int V_79 )
{
F_117 ( V_153 -> V_154 ) ;
}
int F_118 ( struct V_155 * V_156 , T_3 V_21 ,
T_3 V_157 , T_3 V_158 , struct V_110 * V_110 ,
int V_159 )
{
struct V_153 * V_153 ;
struct V_160 * V_161 ;
F_119 ( V_162 ) ;
T_3 V_163 = 0 ;
T_3 V_164 ;
struct V_165 * V_166 = NULL ;
int V_58 ;
F_54 ( ! V_159 ) ;
V_153 = F_120 ( V_106 , 1 ) ;
if ( ! V_153 )
return - V_167 ;
V_153 -> V_154 = & V_162 ;
V_153 -> V_168 = F_116 ;
V_153 -> V_169 = 0 ;
V_163 = V_157 ;
V_58 = F_121 ( V_156 , V_170 , V_158 ,
& V_163 , & V_166 , V_159 ) ;
if ( V_58 ) {
F_122 ( V_153 ) ;
return - V_167 ;
}
F_54 ( V_159 != V_166 -> V_159 ) ;
V_164 = V_166 -> V_171 [ V_159 - 1 ] . V_172 >> 9 ;
V_153 -> V_173 = V_164 ;
V_161 = V_166 -> V_171 [ V_159 - 1 ] . V_161 ;
F_115 ( V_166 ) ;
if ( ! V_161 || ! V_161 -> V_174 || ! V_161 -> V_175 ) {
F_122 ( V_153 ) ;
return - V_167 ;
}
V_153 -> V_176 = V_161 -> V_174 ;
F_123 ( V_153 , V_110 , V_157 , V_21 - F_124 ( V_110 ) ) ;
F_125 ( V_177 , V_153 ) ;
F_126 ( & V_162 ) ;
if ( ! F_127 ( V_178 , & V_153 -> V_179 ) ) {
F_122 ( V_153 ) ;
return - V_167 ;
}
F_9 ( V_180 L_13
L_14 , V_110 -> V_4 -> V_5 -> V_181 , V_21 ,
V_161 -> V_182 , V_164 ) ;
F_122 ( V_153 ) ;
return 0 ;
}
int F_128 ( struct V_183 * V_43 , struct V_13 * V_16 ,
int V_159 )
{
struct V_155 * V_156 = & V_43 -> V_184 -> V_185 ;
T_3 V_21 = V_16 -> V_21 ;
unsigned long V_120 , V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
int V_58 = 0 ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
struct V_110 * V_46 = F_130 ( V_16 , V_120 ) ;
V_58 = F_118 ( V_156 , V_21 , V_130 ,
V_21 , V_46 , V_159 ) ;
if ( V_58 )
break;
V_21 += V_130 ;
}
return V_58 ;
}
static int F_131 ( T_3 V_21 , struct V_110 * V_110 )
{
T_3 V_37 ;
T_3 V_187 ;
struct V_146 * V_188 ;
struct V_155 * V_156 ;
struct V_8 * V_15 ;
int V_189 ;
int V_148 = 0 ;
int V_58 ;
struct V_116 * V_116 = V_110 -> V_4 -> V_5 ;
V_37 = 0 ;
V_58 = F_104 ( & F_114 ( V_116 ) -> V_150 , & V_37 ,
( T_3 ) - 1 , 1 , V_77 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_58 = F_108 ( & F_114 ( V_116 ) -> V_150 , V_21 ,
& V_187 ) ;
if ( V_58 )
return 0 ;
V_188 = (struct V_146 * ) ( unsigned long ) V_187 ;
F_54 ( ! V_188 -> V_190 ) ;
if ( V_188 -> V_191 ) {
F_132 ( L_15 ,
V_188 -> V_21 ) ;
V_148 = 1 ;
goto V_89;
}
F_52 ( & F_114 ( V_116 ) -> V_151 . V_32 ) ;
V_15 = F_88 ( & F_114 ( V_116 ) -> V_151 ,
V_188 -> V_21 ,
V_105 ) ;
F_56 ( & F_114 ( V_116 ) -> V_151 . V_32 ) ;
if ( V_15 && V_15 -> V_21 == V_188 -> V_21 ) {
V_156 = & F_114 ( V_116 ) -> V_43 -> V_184 -> V_185 ;
V_189 = F_133 ( V_156 , V_188 -> V_158 ,
V_188 -> V_25 ) ;
if ( V_189 > 1 ) {
V_58 = F_118 ( V_156 , V_21 , V_188 -> V_25 ,
V_188 -> V_158 , V_110 ,
V_188 -> V_192 ) ;
V_148 = ! V_58 ;
}
}
V_89:
if ( ! V_58 )
V_58 = F_113 ( V_116 , V_188 , V_148 ) ;
return V_58 ;
}
static int F_134 ( struct V_153 * V_193 , struct V_110 * V_110 ,
T_3 V_21 , T_3 V_22 , int V_192 ,
struct V_8 * V_15 )
{
struct V_146 * V_188 = NULL ;
T_3 V_37 ;
struct V_194 * V_195 ;
struct V_116 * V_116 = V_110 -> V_4 -> V_5 ;
struct V_2 * V_149 = & F_114 ( V_116 ) -> V_150 ;
struct V_2 * V_3 = & F_114 ( V_116 ) -> V_151 ;
struct V_196 * V_197 = & F_114 ( V_116 ) -> V_198 ;
struct V_153 * V_153 ;
int V_189 ;
int V_58 ;
int V_199 ;
T_3 V_158 ;
F_54 ( V_193 -> V_200 & V_201 ) ;
V_58 = F_108 ( V_149 , V_21 , & V_37 ) ;
if ( V_58 ) {
V_188 = F_135 ( sizeof( * V_188 ) , V_106 ) ;
if ( ! V_188 )
return - V_11 ;
V_188 -> V_21 = V_21 ;
V_188 -> V_25 = V_22 - V_21 + 1 ;
V_188 -> V_190 = 0 ;
V_188 -> V_202 = 0 ;
V_188 -> V_191 = 0 ;
F_136 ( & V_197 -> V_32 ) ;
V_195 = F_137 ( V_197 , V_21 , V_188 -> V_25 ) ;
if ( ! V_195 ) {
F_138 ( & V_197 -> V_32 ) ;
F_115 ( V_188 ) ;
return - V_167 ;
}
if ( V_195 -> V_21 > V_21 || V_195 -> V_21 + V_195 -> V_25 < V_21 ) {
F_139 ( V_195 ) ;
V_195 = NULL ;
}
F_138 ( & V_197 -> V_32 ) ;
if ( ! V_195 || F_140 ( V_195 ) ) {
F_115 ( V_188 ) ;
return - V_167 ;
}
V_158 = V_21 - V_195 -> V_21 ;
V_158 = V_195 -> V_203 + V_158 ;
if ( F_127 ( V_204 , & V_195 -> V_36 ) ) {
V_158 = V_195 -> V_203 ;
V_188 -> V_202 = V_205 ;
F_141 ( & V_188 -> V_202 ,
V_195 -> V_206 ) ;
}
F_132 ( L_16
L_17 , V_158 , V_21 , V_188 -> V_25 ) ;
V_188 -> V_158 = V_158 ;
F_139 ( V_195 ) ;
V_58 = F_72 ( V_149 , V_21 , V_22 ,
V_105 | V_77 , V_106 ) ;
if ( V_58 >= 0 )
V_58 = F_107 ( V_149 , V_21 ,
( T_3 ) ( unsigned long ) V_188 ) ;
if ( V_58 >= 0 )
V_58 = F_72 ( V_3 , V_21 , V_22 , V_152 ,
V_106 ) ;
if ( V_58 < 0 ) {
F_115 ( V_188 ) ;
return V_58 ;
}
} else {
V_188 = (struct V_146 * ) ( unsigned long ) V_37 ;
F_132 ( L_18
L_19 ,
V_188 -> V_158 , V_188 -> V_21 , V_188 -> V_25 ,
V_188 -> V_191 ) ;
}
V_189 = F_133 (
& F_114 ( V_116 ) -> V_43 -> V_184 -> V_185 ,
V_188 -> V_158 , V_188 -> V_25 ) ;
if ( V_189 == 1 ) {
F_132 ( L_20
L_21
L_22 , V_15 , V_189 ,
V_188 -> V_190 , V_192 ) ;
F_113 ( V_116 , V_188 , 0 ) ;
return - V_167 ;
}
if ( ! V_15 ) {
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_188 -> V_21 ,
V_105 ) ;
if ( V_15 && V_15 -> V_21 != V_188 -> V_21 )
V_15 = NULL ;
F_56 ( & V_3 -> V_32 ) ;
}
if ( V_193 -> V_207 > 1 ) {
F_54 ( V_188 -> V_191 ) ;
V_188 -> V_191 = 1 ;
V_188 -> V_190 = V_192 ;
V_199 = V_208 | V_209 ;
} else {
if ( V_188 -> V_191 ) {
F_54 ( V_188 -> V_190 != V_192 ) ;
V_188 -> V_191 = 0 ;
V_188 -> V_190 = 0 ;
}
V_188 -> V_192 = V_192 ;
V_188 -> V_190 ++ ;
if ( V_188 -> V_190 == V_192 )
V_188 -> V_190 ++ ;
V_199 = V_208 ;
}
if ( ! V_15 || V_188 -> V_190 > V_189 ) {
F_132 ( L_23
L_24 , V_15 ,
V_189 , V_188 -> V_190 , V_192 ) ;
F_113 ( V_116 , V_188 , 0 ) ;
return - V_167 ;
}
V_153 = F_120 ( V_106 , 1 ) ;
if ( ! V_153 ) {
F_113 ( V_116 , V_188 , 0 ) ;
return - V_167 ;
}
V_153 -> V_154 = V_15 ;
V_153 -> V_168 = V_193 -> V_168 ;
V_153 -> V_173 = V_188 -> V_158 >> 9 ;
V_153 -> V_176 = F_114 ( V_116 ) -> V_43 -> V_184 -> V_210 -> V_211 ;
V_153 -> V_169 = 0 ;
F_123 ( V_153 , V_110 , V_188 -> V_25 , V_21 - F_124 ( V_110 ) ) ;
F_132 ( L_25
L_26 , V_199 ,
V_188 -> V_190 , V_189 , V_188 -> V_191 ) ;
V_58 = V_3 -> V_30 -> V_212 ( V_116 , V_199 , V_153 ,
V_188 -> V_190 ,
V_188 -> V_202 , 0 ) ;
return V_58 ;
}
int F_142 ( struct V_110 * V_110 , int V_79 , T_3 V_21 , T_3 V_22 )
{
int V_213 = ( V_79 == 0 ) ;
struct V_2 * V_3 ;
int V_58 ;
V_3 = & F_114 ( V_110 -> V_4 -> V_5 ) -> V_151 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 ) {
V_58 = V_3 -> V_30 -> V_214 ( V_110 , V_21 ,
V_22 , NULL , V_213 ) ;
if ( V_58 )
V_213 = 0 ;
}
if ( ! V_213 && V_3 -> V_30 &&
V_3 -> V_30 -> V_215 ) {
V_58 = V_3 -> V_30 -> V_215 ( NULL , V_110 ,
V_21 , V_22 , NULL ) ;
if ( V_58 == 0 )
return 1 ;
}
if ( ! V_213 ) {
F_78 ( V_3 , V_21 , V_22 , NULL , V_106 ) ;
F_143 ( V_110 ) ;
F_144 ( V_110 ) ;
}
return 0 ;
}
static void F_145 ( struct V_153 * V_153 , int V_79 )
{
struct V_216 * V_217 = V_153 -> V_218 + V_153 -> V_207 - 1 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_219 ;
do {
struct V_110 * V_110 = V_217 -> V_220 ;
V_3 = & F_114 ( V_110 -> V_4 -> V_5 ) -> V_151 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_217 -> V_221 ;
V_22 = V_21 + V_217 -> V_222 - 1 ;
if ( V_217 -> V_221 == 0 && V_217 -> V_222 == V_130 )
V_219 = 1 ;
else
V_219 = 0 ;
if ( -- V_217 >= V_153 -> V_218 )
F_146 ( & V_217 -> V_220 -> V_36 ) ;
if ( F_142 ( V_110 , V_79 , V_21 , V_22 ) )
continue;
if ( V_219 )
F_103 ( V_110 ) ;
else
F_112 ( V_3 , V_110 ) ;
} while ( V_217 >= V_153 -> V_218 );
F_122 ( V_153 ) ;
}
static void F_147 ( struct V_153 * V_153 , int V_79 )
{
int V_213 = F_127 ( V_178 , & V_153 -> V_179 ) ;
struct V_216 * V_223 = V_153 -> V_218 + V_153 -> V_207 - 1 ;
struct V_216 * V_217 = V_153 -> V_218 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_219 ;
int V_224 ;
int V_58 ;
if ( V_79 )
V_213 = 0 ;
do {
struct V_110 * V_110 = V_217 -> V_220 ;
struct V_8 * V_82 = NULL ;
struct V_8 * V_15 ;
F_132 ( L_27
L_28 , V_153 -> V_207 , V_153 -> V_225 , V_79 ,
( long int ) V_153 -> V_176 ) ;
V_3 = & F_114 ( V_110 -> V_4 -> V_5 ) -> V_151 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) +
V_217 -> V_221 ;
V_22 = V_21 + V_217 -> V_222 - 1 ;
if ( V_217 -> V_221 == 0 && V_217 -> V_222 == V_130 )
V_219 = 1 ;
else
V_219 = 0 ;
if ( ++ V_217 <= V_223 )
F_146 ( & V_217 -> V_220 -> V_36 ) ;
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_21 , V_105 ) ;
if ( V_15 && V_15 -> V_21 == V_21 ) {
F_66 ( V_15 , & V_82 ) ;
}
F_56 ( & V_3 -> V_32 ) ;
V_224 = ( int ) ( unsigned long ) V_153 -> V_176 ;
if ( V_213 && V_3 -> V_30 && V_3 -> V_30 -> V_226 ) {
V_58 = V_3 -> V_30 -> V_226 ( V_110 , V_21 , V_22 ,
V_15 , V_224 ) ;
if ( V_58 )
V_213 = 0 ;
else
F_131 ( V_21 , V_110 ) ;
}
if ( ! V_213 && V_3 -> V_30 && V_3 -> V_30 -> V_227 ) {
V_58 = V_3 -> V_30 -> V_227 ( V_110 , V_224 ) ;
if ( ! V_58 && ! V_79 &&
F_127 ( V_178 , & V_153 -> V_179 ) )
V_213 = 1 ;
} else if ( ! V_213 ) {
V_58 = F_134 ( V_153 , V_110 , V_21 , V_22 , V_224 , NULL ) ;
if ( V_58 == 0 ) {
V_213 =
F_127 ( V_178 , & V_153 -> V_179 ) ;
if ( V_79 )
V_213 = 0 ;
F_67 ( & V_82 ) ;
continue;
}
}
if ( V_213 && V_3 -> V_228 ) {
F_77 ( V_3 , V_21 , V_22 , & V_82 ,
V_29 ) ;
}
F_82 ( V_3 , V_21 , V_22 , & V_82 , V_29 ) ;
if ( V_219 ) {
if ( V_213 ) {
F_110 ( V_110 ) ;
} else {
F_143 ( V_110 ) ;
F_144 ( V_110 ) ;
}
F_94 ( V_110 ) ;
} else {
if ( V_213 ) {
F_109 ( V_3 , V_110 ) ;
} else {
F_143 ( V_110 ) ;
F_144 ( V_110 ) ;
}
F_111 ( V_3 , V_110 ) ;
}
} while ( V_217 <= V_223 );
F_122 ( V_153 ) ;
}
struct V_153 *
F_148 ( struct V_229 * V_174 , T_3 V_230 , int V_231 ,
T_2 V_232 )
{
struct V_153 * V_153 ;
V_153 = F_120 ( V_232 , V_231 ) ;
if ( V_153 == NULL && ( V_233 -> V_36 & V_234 ) ) {
while ( ! V_153 && ( V_231 /= 2 ) )
V_153 = F_120 ( V_232 , V_231 ) ;
}
if ( V_153 ) {
V_153 -> V_169 = 0 ;
V_153 -> V_176 = V_174 ;
V_153 -> V_173 = V_230 ;
}
return V_153 ;
}
static int T_4 F_149 ( int V_235 , struct V_153 * V_153 ,
int V_159 , unsigned long V_202 )
{
int V_58 = 0 ;
struct V_216 * V_217 = V_153 -> V_218 + V_153 -> V_207 - 1 ;
struct V_110 * V_110 = V_217 -> V_220 ;
struct V_2 * V_3 = V_153 -> V_154 ;
T_3 V_21 ;
V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) + V_217 -> V_221 ;
V_153 -> V_154 = NULL ;
F_150 ( V_153 ) ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_212 )
V_58 = V_3 -> V_30 -> V_212 ( V_110 -> V_4 -> V_5 , V_235 , V_153 ,
V_159 , V_202 , V_21 ) ;
else
F_125 ( V_235 , V_153 ) ;
if ( F_151 ( V_153 , V_236 ) )
V_58 = - V_237 ;
F_122 ( V_153 ) ;
return V_58 ;
}
static int F_152 ( struct V_2 * V_3 , struct V_110 * V_110 ,
unsigned long V_44 , T_6 V_238 , struct V_153 * V_153 ,
unsigned long V_202 )
{
int V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_239 )
V_58 = V_3 -> V_30 -> V_239 ( V_110 , V_44 , V_238 , V_153 ,
V_202 ) ;
F_54 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_153 ( int V_235 , struct V_2 * V_3 ,
struct V_110 * V_110 , T_7 V_164 ,
T_6 V_238 , unsigned long V_44 ,
struct V_229 * V_174 ,
struct V_153 * * V_240 ,
unsigned long V_241 ,
T_8 V_242 ,
int V_159 ,
unsigned long V_243 ,
unsigned long V_202 )
{
int V_58 = 0 ;
struct V_153 * V_153 ;
int V_244 ;
int V_141 = 0 ;
int V_245 = V_202 & V_205 ;
int V_246 = V_243 & V_205 ;
T_6 V_247 = F_93 ( T_6 , V_238 , V_130 ) ;
if ( V_240 && * V_240 ) {
V_153 = * V_240 ;
if ( V_246 )
V_141 = V_153 -> V_173 == V_164 ;
else
V_141 = V_153 -> V_173 + ( V_153 -> V_169 >> 9 ) ==
V_164 ;
if ( V_243 != V_202 || ! V_141 ||
F_152 ( V_3 , V_110 , V_44 , V_247 , V_153 , V_202 ) ||
F_123 ( V_153 , V_110 , V_247 , V_44 ) < V_247 ) {
V_58 = F_149 ( V_235 , V_153 , V_159 ,
V_243 ) ;
if ( V_58 < 0 )
return V_58 ;
V_153 = NULL ;
} else {
return 0 ;
}
}
if ( V_245 )
V_244 = V_248 ;
else
V_244 = F_154 ( V_174 ) ;
V_153 = F_148 ( V_174 , V_164 , V_244 , V_106 | V_249 ) ;
if ( ! V_153 )
return - V_11 ;
F_123 ( V_153 , V_110 , V_247 , V_44 ) ;
V_153 -> V_168 = V_242 ;
V_153 -> V_154 = V_3 ;
if ( V_240 )
* V_240 = V_153 ;
else
V_58 = F_149 ( V_235 , V_153 , V_159 , V_202 ) ;
return V_58 ;
}
void F_155 ( struct V_13 * V_16 , struct V_110 * V_110 )
{
if ( ! F_156 ( V_110 ) ) {
F_157 ( V_110 ) ;
F_158 ( V_110 ) ;
F_159 ( V_110 , ( unsigned long ) V_16 ) ;
} else {
F_26 ( V_110 -> V_37 != ( unsigned long ) V_16 ) ;
}
}
void F_160 ( struct V_110 * V_110 )
{
if ( ! F_156 ( V_110 ) ) {
F_157 ( V_110 ) ;
F_158 ( V_110 ) ;
F_159 ( V_110 , V_250 ) ;
}
}
static int F_161 ( struct V_2 * V_3 ,
struct V_110 * V_110 ,
T_9 * V_251 ,
struct V_153 * * V_153 , int V_159 ,
unsigned long * V_202 )
{
struct V_116 * V_116 = V_110 -> V_4 -> V_5 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_252 = V_21 + V_130 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_162 ( V_116 ) ;
T_3 V_203 ;
T_3 V_256 ;
T_7 V_164 ;
struct V_194 * V_195 ;
struct V_229 * V_174 ;
struct V_257 * V_258 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_260 ;
T_6 V_261 ;
T_6 V_262 = V_116 -> V_6 -> V_263 ;
unsigned long V_264 = 0 ;
F_160 ( V_110 ) ;
if ( ! F_163 ( V_110 ) ) {
if ( F_164 ( V_110 ) == 0 ) {
F_54 ( V_262 != V_265 ) ;
goto V_89;
}
}
V_22 = V_252 ;
while ( 1 ) {
F_80 ( V_3 , V_21 , V_22 ) ;
V_258 = F_165 ( V_116 , V_21 ) ;
if ( ! V_258 )
break;
F_83 ( V_3 , V_21 , V_22 ) ;
F_166 ( V_116 , V_258 , 1 ) ;
F_167 ( V_258 ) ;
}
if ( V_110 -> V_107 == V_255 >> V_108 ) {
char * V_266 ;
T_6 V_267 = V_255 & ( V_130 - 1 ) ;
if ( V_267 ) {
V_260 = V_130 - V_267 ;
V_266 = F_168 ( V_110 ) ;
memset ( V_266 + V_267 , 0 , V_260 ) ;
F_169 ( V_110 ) ;
F_170 ( V_266 ) ;
}
}
while ( V_253 <= V_22 ) {
if ( V_253 >= V_255 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_260 = V_130 - V_259 ;
V_266 = F_168 ( V_110 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_169 ( V_110 ) ;
F_170 ( V_266 ) ;
F_77 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_82 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
break;
}
V_195 = V_251 ( V_116 , V_110 , V_259 , V_253 ,
V_22 - V_253 + 1 , 0 ) ;
if ( F_171 ( V_195 ) ) {
F_144 ( V_110 ) ;
F_83 ( V_3 , V_253 , V_22 ) ;
break;
}
V_254 = V_253 - V_195 -> V_21 ;
F_54 ( F_172 ( V_195 ) <= V_253 ) ;
F_54 ( V_22 < V_253 ) ;
if ( F_127 ( V_204 , & V_195 -> V_36 ) ) {
V_264 = V_205 ;
F_141 ( & V_264 ,
V_195 -> V_206 ) ;
}
V_260 = F_105 ( F_172 ( V_195 ) - V_253 , V_22 - V_253 + 1 ) ;
V_256 = F_105 ( F_172 ( V_195 ) - 1 , V_22 ) ;
V_260 = ( V_260 + V_262 - 1 ) & ~ ( ( T_3 ) V_262 - 1 ) ;
if ( V_264 & V_205 ) {
V_261 = V_195 -> V_268 ;
V_164 = V_195 -> V_203 >> 9 ;
} else {
V_164 = ( V_195 -> V_203 + V_254 ) >> 9 ;
V_261 = V_260 ;
}
V_174 = V_195 -> V_174 ;
V_203 = V_195 -> V_203 ;
if ( F_127 ( V_269 , & V_195 -> V_36 ) )
V_203 = V_270 ;
F_139 ( V_195 ) ;
V_195 = NULL ;
if ( V_203 == V_270 ) {
char * V_266 ;
struct V_8 * V_82 = NULL ;
V_266 = F_168 ( V_110 ) ;
memset ( V_266 + V_259 , 0 , V_260 ) ;
F_169 ( V_110 ) ;
F_170 ( V_266 ) ;
F_77 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
F_82 ( V_3 , V_253 , V_253 + V_260 - 1 ,
& V_82 , V_106 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( F_99 ( V_3 , V_253 , V_256 ,
V_102 , 1 , NULL ) ) {
F_109 ( V_3 , V_110 ) ;
F_83 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
continue;
}
if ( V_203 == V_271 ) {
F_144 ( V_110 ) ;
F_83 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
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
V_58 = F_153 ( V_274 , V_3 , V_110 ,
V_164 , V_261 , V_259 ,
V_174 , V_153 , V_273 ,
F_147 , V_159 ,
* V_202 ,
V_264 ) ;
F_54 ( V_58 == - V_11 ) ;
V_244 ++ ;
* V_202 = V_264 ;
}
if ( V_58 )
F_144 ( V_110 ) ;
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
}
V_89:
if ( ! V_244 ) {
if ( ! F_173 ( V_110 ) )
F_110 ( V_110 ) ;
F_94 ( V_110 ) ;
}
return 0 ;
}
int F_174 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_251 , int V_159 )
{
struct V_153 * V_153 = NULL ;
unsigned long V_202 = 0 ;
int V_58 ;
V_58 = F_161 ( V_3 , V_110 , V_251 , & V_153 , V_159 ,
& V_202 ) ;
if ( V_153 )
V_58 = F_149 ( V_274 , V_153 , V_159 , V_202 ) ;
return V_58 ;
}
static T_5 void F_175 ( struct V_110 * V_110 ,
struct V_275 * V_276 ,
unsigned long V_277 )
{
V_276 -> V_278 -= V_277 ;
if ( V_276 -> V_279 || ( V_276 -> V_278 > 0 &&
V_276 -> V_280 == 0 && V_276 -> V_281 == V_282 ) )
V_110 -> V_4 -> V_283 = V_110 -> V_107 + V_277 ;
}
static int F_176 ( struct V_110 * V_110 , struct V_275 * V_276 ,
void * V_284 )
{
struct V_116 * V_116 = V_110 -> V_4 -> V_5 ;
struct V_285 * V_286 = V_284 ;
struct V_2 * V_3 = V_286 -> V_3 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_122 ;
T_3 V_252 = V_21 + V_130 - 1 ;
T_3 V_22 ;
T_3 V_253 = V_21 ;
T_3 V_254 ;
T_3 V_255 = F_162 ( V_116 ) ;
T_3 V_203 ;
T_3 V_260 ;
T_7 V_164 ;
struct V_8 * V_81 = NULL ;
struct V_194 * V_195 ;
struct V_229 * V_174 ;
int V_58 ;
int V_244 = 0 ;
T_6 V_259 = 0 ;
T_6 V_262 ;
T_10 V_287 = F_162 ( V_116 ) ;
unsigned long V_109 = V_287 >> V_108 ;
T_3 V_288 ;
T_3 V_123 ;
int V_289 ;
int V_290 ;
int V_291 ;
unsigned long V_277 = 0 ;
bool V_292 = true ;
if ( V_276 -> V_293 == V_294 )
V_291 = V_177 ;
else
V_291 = V_170 ;
F_177 ( V_110 , V_116 , V_276 ) ;
F_26 ( ! F_178 ( V_110 ) ) ;
F_179 ( V_110 ) ;
V_259 = V_287 & ( V_130 - 1 ) ;
if ( V_110 -> V_107 > V_109 ||
( V_110 -> V_107 == V_109 && ! V_259 ) ) {
V_110 -> V_4 -> V_295 -> V_296 ( V_110 , 0 ) ;
F_94 ( V_110 ) ;
return 0 ;
}
if ( V_110 -> V_107 == V_109 ) {
char * V_266 ;
V_266 = F_168 ( V_110 ) ;
memset ( V_266 + V_259 , 0 ,
V_130 - V_259 ) ;
F_170 ( V_266 ) ;
F_169 ( V_110 ) ;
}
V_259 = 0 ;
F_160 ( V_110 ) ;
if ( ! V_3 -> V_30 || ! V_3 -> V_30 -> V_292 )
V_292 = false ;
V_122 = V_21 ;
V_123 = 0 ;
V_289 = 0 ;
if ( ! V_286 -> V_297 && V_292 ) {
T_3 V_298 = 0 ;
F_175 ( V_110 , V_276 , 0 ) ;
while ( V_123 < V_252 ) {
V_288 = F_98 ( V_116 , V_3 ,
V_110 ,
& V_122 ,
& V_123 ,
128 * 1024 * 1024 ) ;
if ( V_288 == 0 ) {
V_122 = V_123 + 1 ;
continue;
}
V_58 = V_3 -> V_30 -> V_292 ( V_116 , V_110 ,
V_122 ,
V_123 ,
& V_289 ,
& V_277 ) ;
if ( V_58 ) {
F_144 ( V_110 ) ;
goto V_128;
}
V_298 += ( V_123 - V_122 +
V_130 ) >>
V_108 ;
V_122 = V_123 + 1 ;
}
if ( V_276 -> V_278 < V_298 ) {
int V_299 = 8192 ;
if ( V_298 < V_299 * 2 )
V_299 = V_298 ;
V_276 -> V_278 = F_93 ( T_3 , V_298 ,
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
F_180 ( V_276 , V_110 ) ;
F_175 ( V_110 , V_276 , V_277 ) ;
F_94 ( V_110 ) ;
V_58 = 0 ;
goto V_300;
}
}
F_175 ( V_110 , V_276 , V_277 + 1 ) ;
V_22 = V_252 ;
if ( V_255 <= V_21 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_110 , V_21 ,
V_252 , NULL , 1 ) ;
goto V_128;
}
V_262 = V_116 -> V_6 -> V_263 ;
while ( V_253 <= V_22 ) {
if ( V_253 >= V_255 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_110 , V_253 ,
V_252 , NULL , 1 ) ;
break;
}
V_195 = V_286 -> V_251 ( V_116 , V_110 , V_259 , V_253 ,
V_22 - V_253 + 1 , 1 ) ;
if ( F_171 ( V_195 ) ) {
F_144 ( V_110 ) ;
break;
}
V_254 = V_253 - V_195 -> V_21 ;
F_54 ( F_172 ( V_195 ) <= V_253 ) ;
F_54 ( V_22 < V_253 ) ;
V_260 = F_105 ( F_172 ( V_195 ) - V_253 , V_22 - V_253 + 1 ) ;
V_260 = ( V_260 + V_262 - 1 ) & ~ ( ( T_3 ) V_262 - 1 ) ;
V_164 = ( V_195 -> V_203 + V_254 ) >> 9 ;
V_174 = V_195 -> V_174 ;
V_203 = V_195 -> V_203 ;
V_290 = F_127 ( V_204 , & V_195 -> V_36 ) ;
F_139 ( V_195 ) ;
V_195 = NULL ;
if ( V_290 || V_203 == V_270 ||
V_203 == V_271 ) {
if ( ! V_290 && V_3 -> V_30 &&
V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_110 , V_253 ,
V_253 + V_260 - 1 ,
NULL , 1 ) ;
else if ( V_290 ) {
V_244 ++ ;
}
V_253 += V_260 ;
V_259 += V_260 ;
continue;
}
if ( 0 && ! F_99 ( V_3 , V_253 , V_253 + V_260 - 1 ,
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
F_144 ( V_110 ) ;
} else {
unsigned long V_305 = V_109 + 1 ;
F_84 ( V_3 , V_253 , V_253 + V_260 - 1 ) ;
if ( ! F_181 ( V_110 ) ) {
F_9 ( V_20 L_29
L_30 ,
V_110 -> V_107 , ( unsigned long long ) V_253 ,
( unsigned long long ) V_22 ) ;
}
V_58 = F_153 ( V_291 , V_3 , V_110 ,
V_164 , V_260 , V_259 ,
V_174 , & V_286 -> V_153 , V_305 ,
F_145 ,
0 , 0 , 0 ) ;
if ( V_58 )
F_144 ( V_110 ) ;
}
V_253 = V_253 + V_260 ;
V_259 += V_260 ;
V_244 ++ ;
}
V_128:
if ( V_244 == 0 ) {
F_86 ( V_110 ) ;
F_103 ( V_110 ) ;
}
F_94 ( V_110 ) ;
V_300:
F_24 ( V_81 ) ;
return 0 ;
}
static int F_182 ( void * V_306 )
{
F_183 () ;
return 0 ;
}
static void F_184 ( struct V_13 * V_16 )
{
F_185 ( & V_16 -> V_307 , V_308 , F_182 ,
V_92 ) ;
}
static int F_186 ( struct V_13 * V_16 ,
struct V_1 * V_184 ,
struct V_285 * V_286 )
{
unsigned long V_120 , V_186 ;
int V_309 = 0 ;
int V_58 = 0 ;
if ( ! F_187 ( V_16 ) ) {
V_309 = 1 ;
F_188 ( V_286 ) ;
F_189 ( V_16 ) ;
}
if ( F_127 ( V_308 , & V_16 -> V_307 ) ) {
F_190 ( V_16 ) ;
if ( ! V_286 -> V_310 )
return 0 ;
if ( ! V_309 ) {
F_188 ( V_286 ) ;
V_309 = 1 ;
}
while ( 1 ) {
F_184 ( V_16 ) ;
F_189 ( V_16 ) ;
if ( ! F_127 ( V_308 , & V_16 -> V_307 ) )
break;
F_190 ( V_16 ) ;
}
}
if ( F_191 ( V_311 , & V_16 -> V_307 ) ) {
F_192 ( V_308 , & V_16 -> V_307 ) ;
F_193 ( V_16 , V_312 ) ;
F_52 ( & V_184 -> V_313 ) ;
if ( V_184 -> V_314 >= V_16 -> V_25 )
V_184 -> V_314 -= V_16 -> V_25 ;
else
F_26 ( 1 ) ;
F_56 ( & V_184 -> V_313 ) ;
V_58 = 1 ;
}
F_190 ( V_16 ) ;
if ( ! V_58 )
return V_58 ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
struct V_110 * V_46 = F_130 ( V_16 , V_120 ) ;
if ( ! F_194 ( V_46 ) ) {
if ( ! V_309 ) {
F_188 ( V_286 ) ;
V_309 = 1 ;
}
F_96 ( V_46 ) ;
}
}
return V_58 ;
}
static void F_195 ( struct V_13 * V_16 )
{
F_196 ( V_308 , & V_16 -> V_307 ) ;
F_197 () ;
F_198 ( & V_16 -> V_307 , V_308 ) ;
}
static void F_199 ( struct V_153 * V_153 , int V_79 )
{
int V_213 = V_79 == 0 ;
struct V_216 * V_217 = V_153 -> V_218 + V_153 -> V_207 - 1 ;
struct V_13 * V_16 ;
int V_128 ;
do {
struct V_110 * V_110 = V_217 -> V_220 ;
V_217 -- ;
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_54 ( ! V_16 ) ;
V_128 = F_25 ( & V_16 -> V_315 ) ;
if ( ! V_213 || F_127 ( V_316 , & V_16 -> V_307 ) ) {
F_192 ( V_316 , & V_16 -> V_307 ) ;
F_143 ( V_110 ) ;
F_144 ( V_110 ) ;
}
F_103 ( V_110 ) ;
if ( ! V_128 )
continue;
F_195 ( V_16 ) ;
} while ( V_217 >= V_153 -> V_218 );
F_122 ( V_153 ) ;
}
static int F_200 ( struct V_13 * V_16 ,
struct V_1 * V_184 ,
struct V_275 * V_276 ,
struct V_285 * V_286 )
{
struct V_229 * V_174 = V_184 -> V_210 -> V_211 ;
T_3 V_44 = V_16 -> V_21 ;
unsigned long V_120 , V_186 ;
int V_235 = ( V_286 -> V_310 ? V_177 : V_170 ) ;
int V_58 ;
F_196 ( V_316 , & V_16 -> V_307 ) ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_21 ( & V_16 -> V_315 , V_186 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
struct V_110 * V_46 = F_130 ( V_16 , V_120 ) ;
F_102 ( V_46 ) ;
F_86 ( V_46 ) ;
V_58 = F_153 ( V_235 , V_16 -> V_3 , V_46 , V_44 >> 9 ,
V_130 , 0 , V_174 , & V_286 -> V_153 ,
- 1 , F_199 ,
0 , 0 , 0 ) ;
if ( V_58 ) {
F_192 ( V_316 , & V_16 -> V_307 ) ;
F_144 ( V_46 ) ;
if ( F_201 ( V_186 - V_120 , & V_16 -> V_315 ) )
F_195 ( V_16 ) ;
V_58 = - V_167 ;
break;
}
V_44 += V_130 ;
F_175 ( V_46 , V_276 , 1 ) ;
F_94 ( V_46 ) ;
}
if ( F_202 ( V_58 ) ) {
for (; V_120 < V_186 ; V_120 ++ ) {
struct V_110 * V_46 = F_130 ( V_16 , V_120 ) ;
F_94 ( V_46 ) ;
}
}
return V_58 ;
}
int F_203 ( struct V_26 * V_4 ,
struct V_275 * V_276 )
{
struct V_2 * V_3 = & F_114 ( V_4 -> V_5 ) -> V_151 ;
struct V_1 * V_184 = F_114 ( V_4 -> V_5 ) -> V_43 -> V_184 ;
struct V_13 * V_16 , * V_317 = NULL ;
struct V_285 V_286 = {
. V_153 = NULL ,
. V_3 = V_3 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
} ;
int V_58 = 0 ;
int V_128 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_119 ;
T_11 V_107 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
F_204 ( & V_320 , 0 ) ;
if ( V_276 -> V_279 ) {
V_107 = V_4 -> V_283 ;
V_22 = - 1 ;
} else {
V_107 = V_276 -> V_280 >> V_108 ;
V_22 = V_276 -> V_281 >> V_108 ;
V_321 = 1 ;
}
if ( V_276 -> V_293 == V_294 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_276 -> V_293 == V_294 )
F_205 ( V_4 , V_107 , V_22 ) ;
while ( ! V_128 && ! V_318 && ( V_107 <= V_22 ) &&
( V_119 = F_206 ( & V_320 , V_4 , & V_107 , V_322 ,
F_105 ( V_22 - V_107 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_120 ;
V_321 = 1 ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
struct V_110 * V_110 = V_320 . V_118 [ V_120 ] ;
if ( ! F_156 ( V_110 ) )
continue;
if ( ! V_276 -> V_279 && V_110 -> V_107 > V_22 ) {
V_128 = 1 ;
break;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
if ( ! V_16 ) {
F_26 ( 1 ) ;
continue;
}
if ( V_16 == V_317 )
continue;
if ( ! F_207 ( & V_16 -> V_23 ) ) {
F_26 ( 1 ) ;
continue;
}
V_317 = V_16 ;
V_58 = F_186 ( V_16 , V_184 , & V_286 ) ;
if ( ! V_58 ) {
F_208 ( V_16 ) ;
continue;
}
V_58 = F_200 ( V_16 , V_184 , V_276 , & V_286 ) ;
if ( V_58 ) {
V_128 = 1 ;
F_208 ( V_16 ) ;
break;
}
F_208 ( V_16 ) ;
V_318 = V_276 -> V_278 <= 0 ;
}
F_209 ( & V_320 ) ;
F_57 () ;
}
if ( ! V_321 && ! V_128 ) {
V_321 = 1 ;
V_107 = 0 ;
goto V_325;
}
F_188 ( & V_286 ) ;
return V_58 ;
}
static int F_210 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_275 * V_276 ,
T_12 V_327 , void * V_284 ,
void (* F_211)( void * ) )
{
int V_58 = 0 ;
int V_128 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_119 ;
T_11 V_107 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
F_204 ( & V_320 , 0 ) ;
if ( V_276 -> V_279 ) {
V_107 = V_4 -> V_283 ;
V_22 = - 1 ;
} else {
V_107 = V_276 -> V_280 >> V_108 ;
V_22 = V_276 -> V_281 >> V_108 ;
V_321 = 1 ;
}
if ( V_276 -> V_293 == V_294 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_276 -> V_293 == V_294 )
F_205 ( V_4 , V_107 , V_22 ) ;
while ( ! V_128 && ! V_318 && ( V_107 <= V_22 ) &&
( V_119 = F_206 ( & V_320 , V_4 , & V_107 , V_322 ,
F_105 ( V_22 - V_107 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_120 ;
V_321 = 1 ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
struct V_110 * V_110 = V_320 . V_118 [ V_120 ] ;
if ( V_3 -> V_30 &&
V_3 -> V_30 -> V_328 ) {
V_3 -> V_30 -> V_328 ( V_110 ,
V_284 , F_211 ) ;
} else {
if ( ! F_194 ( V_110 ) ) {
F_211 ( V_284 ) ;
F_96 ( V_110 ) ;
}
}
if ( F_202 ( V_110 -> V_4 != V_4 ) ) {
F_94 ( V_110 ) ;
continue;
}
if ( ! V_276 -> V_279 && V_110 -> V_107 > V_22 ) {
V_128 = 1 ;
F_94 ( V_110 ) ;
continue;
}
if ( V_276 -> V_293 != V_329 ) {
if ( F_181 ( V_110 ) )
F_211 ( V_284 ) ;
F_212 ( V_110 ) ;
}
if ( F_181 ( V_110 ) ||
! F_102 ( V_110 ) ) {
F_94 ( V_110 ) ;
continue;
}
V_58 = (* V_327)( V_110 , V_276 , V_284 ) ;
if ( F_202 ( V_58 == V_330 ) ) {
F_94 ( V_110 ) ;
V_58 = 0 ;
}
if ( V_58 )
V_128 = 1 ;
V_318 = V_276 -> V_278 <= 0 ;
}
F_209 ( & V_320 ) ;
F_57 () ;
}
if ( ! V_321 && ! V_128 ) {
V_321 = 1 ;
V_107 = 0 ;
goto V_325;
}
return V_58 ;
}
static void F_213 ( struct V_285 * V_286 )
{
if ( V_286 -> V_153 ) {
int V_235 = V_170 ;
int V_58 ;
if ( V_286 -> V_310 )
V_235 = V_177 ;
V_58 = F_149 ( V_235 , V_286 -> V_153 , 0 , 0 ) ;
F_54 ( V_58 < 0 ) ;
V_286 -> V_153 = NULL ;
}
}
static T_5 void F_188 ( void * V_284 )
{
struct V_285 * V_286 = V_284 ;
F_213 ( V_286 ) ;
}
int F_214 ( struct V_2 * V_3 , struct V_110 * V_110 ,
T_9 * V_251 ,
struct V_275 * V_276 )
{
int V_58 ;
struct V_285 V_286 = {
. V_153 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
} ;
V_58 = F_176 ( V_110 , V_276 , & V_286 ) ;
F_213 ( & V_286 ) ;
return V_58 ;
}
int F_215 ( struct V_2 * V_3 , struct V_116 * V_116 ,
T_3 V_21 , T_3 V_22 , T_9 * V_251 ,
int V_331 )
{
int V_58 = 0 ;
struct V_26 * V_4 = V_116 -> V_121 ;
struct V_110 * V_110 ;
unsigned long V_119 = ( V_22 - V_21 + V_130 ) >>
V_108 ;
struct V_285 V_286 = {
. V_153 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 1 ,
. V_310 = V_331 == V_294 ,
} ;
struct V_275 V_332 = {
. V_293 = V_331 ,
. V_278 = V_119 * 2 ,
. V_280 = V_21 ,
. V_281 = V_22 + 1 ,
} ;
while ( V_21 <= V_22 ) {
V_110 = F_85 ( V_4 , V_21 >> V_108 ) ;
if ( F_102 ( V_110 ) )
V_58 = F_176 ( V_110 , & V_332 , & V_286 ) ;
else {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_110 , V_21 ,
V_21 + V_130 - 1 ,
NULL , 1 ) ;
F_94 ( V_110 ) ;
}
F_87 ( V_110 ) ;
V_21 += V_130 ;
}
F_213 ( & V_286 ) ;
return V_58 ;
}
int F_216 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
T_9 * V_251 ,
struct V_275 * V_276 )
{
int V_58 = 0 ;
struct V_285 V_286 = {
. V_153 = NULL ,
. V_3 = V_3 ,
. V_251 = V_251 ,
. V_297 = 0 ,
. V_310 = V_276 -> V_293 == V_294 ,
} ;
V_58 = F_210 ( V_3 , V_4 , V_276 ,
F_176 , & V_286 ,
F_188 ) ;
F_213 ( & V_286 ) ;
return V_58 ;
}
int F_217 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_333 * V_118 , unsigned V_119 ,
T_9 V_251 )
{
struct V_153 * V_153 = NULL ;
unsigned V_334 ;
unsigned long V_202 = 0 ;
for ( V_334 = 0 ; V_334 < V_119 ; V_334 ++ ) {
struct V_110 * V_110 = F_8 ( V_118 -> V_55 , struct V_110 , V_335 ) ;
F_146 ( & V_110 -> V_36 ) ;
F_11 ( & V_110 -> V_335 ) ;
if ( ! F_218 ( V_110 , V_4 ,
V_110 -> V_107 , V_106 ) ) {
F_161 ( V_3 , V_110 , V_251 ,
& V_153 , 0 , & V_202 ) ;
}
F_87 ( V_110 ) ;
}
F_54 ( ! F_7 ( V_118 ) ) ;
if ( V_153 )
return F_149 ( V_274 , V_153 , 0 , V_202 ) ;
return 0 ;
}
int F_219 ( struct V_2 * V_3 ,
struct V_110 * V_110 , unsigned long V_44 )
{
struct V_8 * V_81 = NULL ;
T_3 V_21 = ( ( T_3 ) V_110 -> V_107 << V_108 ) ;
T_3 V_22 = V_21 + V_130 - 1 ;
T_6 V_262 = V_110 -> V_4 -> V_5 -> V_6 -> V_263 ;
V_21 += ( V_44 + V_262 - 1 ) & ~ ( V_262 - 1 ) ;
if ( V_21 > V_22 )
return 0 ;
F_79 ( V_3 , V_21 , V_22 , 0 , & V_81 ) ;
F_212 ( V_110 ) ;
F_51 ( V_3 , V_21 , V_22 ,
V_105 | V_77 | V_101 |
V_103 ,
1 , 1 , & V_81 , V_106 ) ;
return 0 ;
}
int F_220 ( struct V_196 * V_336 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_130 - 1 ;
int V_58 = 1 ;
if ( F_99 ( V_3 , V_21 , V_22 ,
V_63 , 0 , NULL ) )
V_58 = 0 ;
else {
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
V_58 = F_51 ( V_3 , V_21 , V_22 ,
~ ( V_105 | V_337 ) ,
0 , 0 , NULL , V_34 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
else
V_58 = 1 ;
}
return V_58 ;
}
int F_221 ( struct V_196 * V_336 ,
struct V_2 * V_3 , struct V_110 * V_110 ,
T_2 V_34 )
{
struct V_194 * V_195 ;
T_3 V_21 = ( T_3 ) V_110 -> V_107 << V_108 ;
T_3 V_22 = V_21 + V_130 - 1 ;
if ( ( V_34 & V_87 ) &&
V_110 -> V_4 -> V_5 -> V_287 > 16 * 1024 * 1024 ) {
T_3 V_25 ;
while ( V_21 <= V_22 ) {
V_25 = V_22 - V_21 + 1 ;
F_222 ( & V_336 -> V_32 ) ;
V_195 = F_137 ( V_336 , V_21 , V_25 ) ;
if ( ! V_195 ) {
F_223 ( & V_336 -> V_32 ) ;
break;
}
if ( F_127 ( V_338 , & V_195 -> V_36 ) ||
V_195 -> V_21 != V_21 ) {
F_223 ( & V_336 -> V_32 ) ;
F_139 ( V_195 ) ;
break;
}
if ( ! F_99 ( V_3 , V_195 -> V_21 ,
F_172 ( V_195 ) - 1 ,
V_105 | V_339 ,
0 , NULL ) ) {
F_224 ( V_336 , V_195 ) ;
F_139 ( V_195 ) ;
}
V_21 = F_172 ( V_195 ) ;
F_223 ( & V_336 -> V_32 ) ;
F_139 ( V_195 ) ;
}
}
return F_220 ( V_336 , V_3 , V_110 , V_34 ) ;
}
static struct V_194 * F_225 ( struct V_116 * V_116 ,
T_3 V_44 ,
T_3 V_142 ,
T_9 * V_251 )
{
T_3 V_340 = F_114 ( V_116 ) -> V_43 -> V_340 ;
struct V_194 * V_195 ;
T_3 V_25 ;
if ( V_44 >= V_142 )
return NULL ;
while( 1 ) {
V_25 = V_142 - V_44 ;
if ( V_25 == 0 )
break;
V_25 = ( V_25 + V_340 - 1 ) & ~ ( V_340 - 1 ) ;
V_195 = V_251 ( V_116 , NULL , 0 , V_44 , V_25 , 0 ) ;
if ( F_171 ( V_195 ) )
return V_195 ;
if ( ! F_127 ( V_341 , & V_195 -> V_36 ) &&
V_195 -> V_203 != V_270 ) {
return V_195 ;
}
V_44 = F_172 ( V_195 ) ;
F_139 ( V_195 ) ;
if ( V_44 >= V_142 )
break;
}
return NULL ;
}
int F_226 ( struct V_116 * V_116 , struct V_342 * V_343 ,
T_13 V_21 , T_13 V_25 , T_9 * V_251 )
{
int V_58 = 0 ;
T_3 V_344 = V_21 ;
T_3 F_106 = V_21 + V_25 ;
T_14 V_36 = 0 ;
T_14 V_345 ;
T_3 V_142 ;
T_3 V_346 = 0 ;
T_3 V_347 = 0 ;
T_3 V_348 = F_162 ( V_116 ) ;
struct V_349 V_350 ;
struct V_194 * V_195 = NULL ;
struct V_8 * V_81 = NULL ;
struct V_351 * V_352 ;
struct V_353 * V_354 ;
int V_22 = 0 ;
T_3 V_355 = 0 ;
T_3 V_356 = 0 ;
T_3 V_357 = 0 ;
unsigned long V_358 ;
if ( V_25 == 0 )
return - V_359 ;
V_352 = F_227 () ;
if ( ! V_352 )
return - V_11 ;
V_352 -> V_360 = 1 ;
V_21 = F_228 ( V_21 , F_114 ( V_116 ) -> V_43 -> V_340 ) ;
V_25 = F_228 ( V_25 , F_114 ( V_116 ) -> V_43 -> V_340 ) ;
V_58 = F_229 ( NULL , F_114 ( V_116 ) -> V_43 ,
V_352 , F_230 ( V_116 ) , - 1 , 0 ) ;
if ( V_58 < 0 ) {
F_231 ( V_352 ) ;
return V_58 ;
}
F_26 ( ! V_58 ) ;
V_352 -> V_361 [ 0 ] -- ;
V_354 = F_232 ( V_352 -> V_362 [ 0 ] , V_352 -> V_361 [ 0 ] ,
struct V_353 ) ;
F_233 ( V_352 -> V_362 [ 0 ] , & V_350 , V_352 -> V_361 [ 0 ] ) ;
V_345 = F_234 ( & V_350 ) ;
if ( V_350 . V_363 != F_230 ( V_116 ) ||
V_345 != V_364 ) {
V_142 = ( T_3 ) - 1 ;
V_346 = V_348 ;
} else {
V_142 = V_350 . V_44 ;
V_346 = V_142 + 1 ;
}
F_231 ( V_352 ) ;
if ( V_142 < V_348 ) {
V_142 = ( T_3 ) - 1 ;
V_346 = V_348 ;
}
F_79 ( & F_114 ( V_116 ) -> V_151 , V_21 , V_21 + V_25 , 0 ,
& V_81 ) ;
V_195 = F_225 ( V_116 , V_21 , V_346 ,
V_251 ) ;
if ( ! V_195 )
goto V_89;
if ( F_140 ( V_195 ) ) {
V_58 = F_235 ( V_195 ) ;
goto V_89;
}
while ( ! V_22 ) {
T_3 V_365 ;
if ( V_195 -> V_21 >= F_106 || F_172 ( V_195 ) < V_344 )
break;
V_355 = F_106 ( V_195 -> V_21 , V_344 ) ;
V_365 = V_355 - V_195 -> V_21 ;
V_357 = F_172 ( V_195 ) ;
V_356 = V_357 - V_355 ;
V_358 = V_195 -> V_36 ;
V_347 = 0 ;
V_36 = 0 ;
V_344 = F_172 ( V_195 ) ;
if ( V_344 >= F_106 )
V_22 = 1 ;
if ( V_195 -> V_203 == V_366 ) {
V_22 = 1 ;
V_36 |= V_367 ;
} else if ( V_195 -> V_203 == V_271 ) {
V_36 |= ( V_368 |
V_369 ) ;
} else if ( V_195 -> V_203 == V_370 ) {
V_36 |= ( V_371 |
V_372 ) ;
} else {
V_347 = V_195 -> V_203 + V_365 ;
}
if ( F_127 ( V_204 , & V_195 -> V_36 ) )
V_36 |= V_373 ;
F_139 ( V_195 ) ;
V_195 = NULL ;
if ( ( V_355 >= V_142 ) || V_356 == ( T_3 ) - 1 ||
( V_142 == ( T_3 ) - 1 && V_348 <= V_357 ) ) {
V_36 |= V_367 ;
V_22 = 1 ;
}
V_195 = F_225 ( V_116 , V_344 , V_346 ,
V_251 ) ;
if ( F_140 ( V_195 ) ) {
V_58 = F_235 ( V_195 ) ;
goto V_89;
}
if ( ! V_195 ) {
V_36 |= V_367 ;
V_22 = 1 ;
}
V_58 = F_236 ( V_343 , V_355 , V_347 ,
V_356 , V_36 ) ;
if ( V_58 )
goto V_374;
}
V_374:
F_139 ( V_195 ) ;
V_89:
F_82 ( & F_114 ( V_116 ) -> V_151 , V_21 , V_21 + V_25 ,
& V_81 , V_106 ) ;
return V_58 ;
}
inline struct V_110 * F_130 ( struct V_13 * V_16 ,
unsigned long V_120 )
{
return V_16 -> V_118 [ V_120 ] ;
}
inline unsigned long F_129 ( T_3 V_21 , T_3 V_25 )
{
return ( ( V_21 + V_25 + V_130 - 1 ) >> V_108 ) -
( V_21 >> V_108 ) ;
}
static void F_237 ( struct V_13 * V_16 )
{
#if V_35
unsigned long V_36 ;
F_18 ( & V_38 , V_36 ) ;
F_11 ( & V_16 -> V_19 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
if ( V_16 -> V_118 && V_16 -> V_118 != V_16 -> V_375 )
F_115 ( V_16 -> V_118 ) ;
F_12 ( V_12 , V_16 ) ;
}
static struct V_13 * F_238 ( struct V_2 * V_3 ,
T_3 V_21 ,
unsigned long V_25 ,
T_2 V_34 )
{
struct V_13 * V_16 = NULL ;
#if V_35
unsigned long V_36 ;
#endif
V_16 = F_239 ( V_12 , V_34 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_21 = V_21 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_3 = V_3 ;
F_240 ( & V_16 -> V_32 ) ;
F_21 ( & V_16 -> V_376 , 0 ) ;
F_21 ( & V_16 -> V_377 , 0 ) ;
F_21 ( & V_16 -> V_378 , 0 ) ;
F_21 ( & V_16 -> V_379 , 0 ) ;
F_21 ( & V_16 -> V_380 , 0 ) ;
F_21 ( & V_16 -> V_381 , 0 ) ;
V_16 -> V_382 = 0 ;
F_22 ( & V_16 -> V_383 ) ;
F_22 ( & V_16 -> V_384 ) ;
#if V_35
F_18 ( & V_38 , V_36 ) ;
F_19 ( & V_16 -> V_19 , & V_24 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
F_15 ( & V_16 -> V_385 ) ;
F_21 ( & V_16 -> V_23 , 1 ) ;
F_21 ( & V_16 -> V_315 , 0 ) ;
if ( V_25 > V_386 ) {
struct V_110 * * V_118 ;
int V_186 = ( V_25 + V_130 - 1 ) >>
V_108 ;
V_118 = F_135 ( V_186 , V_34 ) ;
if ( ! V_118 ) {
F_237 ( V_16 ) ;
return NULL ;
}
V_16 -> V_118 = V_118 ;
} else {
V_16 -> V_118 = V_16 -> V_375 ;
}
return V_16 ;
}
static int F_241 ( struct V_13 * V_16 )
{
return ( F_10 ( & V_16 -> V_315 ) ||
F_127 ( V_308 , & V_16 -> V_307 ) ||
F_127 ( V_311 , & V_16 -> V_307 ) ) ;
}
static void F_242 ( struct V_13 * V_16 ,
unsigned long V_387 )
{
unsigned long V_107 ;
struct V_110 * V_110 ;
F_54 ( F_241 ( V_16 ) ) ;
V_107 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
if ( V_387 >= V_107 )
return;
do {
V_107 -- ;
V_110 = F_130 ( V_16 , V_107 ) ;
if ( V_110 ) {
F_52 ( & V_110 -> V_4 -> V_388 ) ;
if ( F_156 ( V_110 ) &&
V_110 -> V_37 == ( unsigned long ) V_16 ) {
F_54 ( F_127 ( V_311 , & V_16 -> V_307 ) ) ;
F_54 ( F_97 ( V_110 ) ) ;
F_54 ( F_181 ( V_110 ) ) ;
F_243 ( V_110 ) ;
F_159 ( V_110 , 0 ) ;
F_87 ( V_110 ) ;
}
F_56 ( & V_110 -> V_4 -> V_388 ) ;
F_87 ( V_110 ) ;
}
} while ( V_107 != V_387 );
}
static inline void F_244 ( struct V_13 * V_16 )
{
F_242 ( V_16 , 0 ) ;
F_237 ( V_16 ) ;
}
static void F_245 ( struct V_13 * V_16 )
{
if ( ! F_127 ( V_389 , & V_16 -> V_307 ) ) {
F_64 ( & V_16 -> V_23 ) ;
if ( F_246 ( V_389 , & V_16 -> V_307 ) )
F_53 ( & V_16 -> V_23 ) ;
}
}
static void F_247 ( struct V_13 * V_16 )
{
unsigned long V_186 , V_120 ;
F_245 ( V_16 ) ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
struct V_110 * V_46 = F_130 ( V_16 , V_120 ) ;
F_248 ( V_46 ) ;
}
}
struct V_13 * F_249 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
unsigned long V_186 = F_129 ( V_21 , V_25 ) ;
unsigned long V_120 ;
unsigned long V_107 = V_21 >> V_108 ;
struct V_13 * V_16 ;
struct V_13 * V_390 = NULL ;
struct V_110 * V_46 ;
struct V_26 * V_4 = V_3 -> V_4 ;
int V_213 = 1 ;
int V_58 ;
F_250 () ;
V_16 = F_251 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_207 ( & V_16 -> V_23 ) ) {
F_252 () ;
F_247 ( V_16 ) ;
return V_16 ;
}
F_252 () ;
V_16 = F_238 ( V_3 , V_21 , V_25 , V_106 ) ;
if ( ! V_16 )
return NULL ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ , V_107 ++ ) {
V_46 = F_253 ( V_4 , V_107 , V_106 ) ;
if ( ! V_46 ) {
F_26 ( 1 ) ;
goto V_391;
}
F_52 ( & V_4 -> V_388 ) ;
if ( F_156 ( V_46 ) ) {
V_390 = (struct V_13 * ) V_46 -> V_37 ;
if ( F_207 ( & V_390 -> V_23 ) ) {
F_56 ( & V_4 -> V_388 ) ;
F_94 ( V_46 ) ;
F_87 ( V_46 ) ;
F_247 ( V_390 ) ;
goto V_391;
}
F_243 ( V_46 ) ;
F_26 ( F_97 ( V_46 ) ) ;
F_87 ( V_46 ) ;
}
F_155 ( V_16 , V_46 ) ;
F_56 ( & V_4 -> V_388 ) ;
F_26 ( F_97 ( V_46 ) ) ;
F_248 ( V_46 ) ;
V_16 -> V_118 [ V_120 ] = V_46 ;
if ( ! F_163 ( V_46 ) )
V_213 = 0 ;
}
if ( V_213 )
F_192 ( V_392 , & V_16 -> V_307 ) ;
V_86:
V_58 = F_254 ( V_106 & ~ V_393 ) ;
if ( V_58 )
goto V_391;
F_52 ( & V_3 -> V_33 ) ;
V_58 = F_255 ( & V_3 -> V_28 , V_21 >> V_108 , V_16 ) ;
if ( V_58 == - V_69 ) {
V_390 = F_251 ( & V_3 -> V_28 ,
V_21 >> V_108 ) ;
if ( ! F_207 ( & V_390 -> V_23 ) ) {
F_56 ( & V_3 -> V_33 ) ;
F_256 () ;
V_390 = NULL ;
goto V_86;
}
F_56 ( & V_3 -> V_33 ) ;
F_256 () ;
F_247 ( V_390 ) ;
goto V_391;
}
F_52 ( & V_16 -> V_385 ) ;
F_245 ( V_16 ) ;
F_56 ( & V_16 -> V_385 ) ;
F_56 ( & V_3 -> V_33 ) ;
F_256 () ;
F_257 ( V_16 -> V_118 [ 0 ] ) ;
for ( V_120 = 1 ; V_120 < V_186 ; V_120 ++ ) {
V_46 = F_130 ( V_16 , V_120 ) ;
F_258 ( V_46 ) ;
F_94 ( V_46 ) ;
}
F_94 ( V_16 -> V_118 [ 0 ] ) ;
return V_16 ;
V_391:
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
if ( V_16 -> V_118 [ V_120 ] )
F_94 ( V_16 -> V_118 [ V_120 ] ) ;
}
F_26 ( ! F_25 ( & V_16 -> V_23 ) ) ;
F_244 ( V_16 ) ;
return V_390 ;
}
struct V_13 * F_259 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
F_250 () ;
V_16 = F_251 ( & V_3 -> V_28 , V_21 >> V_108 ) ;
if ( V_16 && F_207 ( & V_16 -> V_23 ) ) {
F_252 () ;
F_247 ( V_16 ) ;
return V_16 ;
}
F_252 () ;
return NULL ;
}
static inline void F_260 ( struct V_394 * V_395 )
{
struct V_13 * V_16 =
F_261 ( V_395 , struct V_13 , V_394 ) ;
F_237 ( V_16 ) ;
}
static void F_262 ( struct V_13 * V_16 , T_2 V_34 )
{
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
if ( F_25 ( & V_16 -> V_23 ) ) {
struct V_2 * V_3 = V_16 -> V_3 ;
F_56 ( & V_16 -> V_385 ) ;
F_52 ( & V_3 -> V_33 ) ;
F_263 ( & V_3 -> V_28 ,
V_16 -> V_21 >> V_108 ) ;
F_56 ( & V_3 -> V_33 ) ;
F_242 ( V_16 , 0 ) ;
F_264 ( & V_16 -> V_394 , F_260 ) ;
return;
}
F_56 ( & V_16 -> V_385 ) ;
}
void F_208 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_52 ( & V_16 -> V_385 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_127 ( V_396 , & V_16 -> V_307 ) &&
! F_241 ( V_16 ) &&
F_191 ( V_389 , & V_16 -> V_307 ) )
F_53 ( & V_16 -> V_23 ) ;
F_262 ( V_16 , V_29 ) ;
}
void F_265 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_52 ( & V_16 -> V_385 ) ;
F_192 ( V_396 , & V_16 -> V_307 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 && ! F_241 ( V_16 ) &&
F_191 ( V_389 , & V_16 -> V_307 ) )
F_53 ( & V_16 -> V_23 ) ;
F_262 ( V_16 , V_106 ) ;
}
void F_266 ( struct V_13 * V_16 )
{
unsigned long V_120 ;
unsigned long V_186 ;
struct V_110 * V_110 ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
if ( ! F_97 ( V_110 ) )
continue;
F_96 ( V_110 ) ;
F_26 ( ! F_156 ( V_110 ) ) ;
F_102 ( V_110 ) ;
F_267 ( & V_110 -> V_4 -> V_397 ) ;
if ( ! F_97 ( V_110 ) ) {
F_268 ( & V_110 -> V_4 -> V_398 ,
F_269 ( V_110 ) ,
V_324 ) ;
}
F_270 ( & V_110 -> V_4 -> V_397 ) ;
F_179 ( V_110 ) ;
F_94 ( V_110 ) ;
}
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
}
int F_271 ( struct V_13 * V_16 )
{
unsigned long V_120 ;
unsigned long V_186 ;
int V_399 = 0 ;
F_245 ( V_16 ) ;
V_399 = F_246 ( V_311 , & V_16 -> V_307 ) ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
F_26 ( ! F_127 ( V_389 , & V_16 -> V_307 ) ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ )
F_272 ( F_130 ( V_16 , V_120 ) ) ;
return V_399 ;
}
static int F_273 ( T_3 V_21 , T_3 V_25 )
{
if ( V_25 < V_130 )
return 1 ;
if ( V_21 & ( V_130 - 1 ) )
return 1 ;
if ( ( V_21 + V_25 ) & ( V_130 - 1 ) )
return 1 ;
return 0 ;
}
int F_274 ( struct V_13 * V_16 )
{
unsigned long V_120 ;
struct V_110 * V_110 ;
unsigned long V_186 ;
F_196 ( V_392 , & V_16 -> V_307 ) ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
if ( V_110 )
F_143 ( V_110 ) ;
}
return 0 ;
}
int F_275 ( struct V_13 * V_16 )
{
unsigned long V_120 ;
struct V_110 * V_110 ;
unsigned long V_186 ;
F_192 ( V_392 , & V_16 -> V_307 ) ;
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = 0 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
F_110 ( V_110 ) ;
}
return 0 ;
}
int F_276 ( struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 )
{
struct V_110 * V_110 ;
int V_58 ;
int V_400 = 1 ;
int V_213 ;
unsigned long V_107 ;
if ( F_273 ( V_21 , V_22 - V_21 + 1 ) ) {
V_58 = F_99 ( V_3 , V_21 , V_22 ,
V_102 , 1 , NULL ) ;
if ( V_58 )
return 1 ;
}
while ( V_21 <= V_22 ) {
V_107 = V_21 >> V_108 ;
V_110 = F_85 ( V_3 -> V_4 , V_107 ) ;
if ( ! V_110 )
return 1 ;
V_213 = F_163 ( V_110 ) ;
F_87 ( V_110 ) ;
if ( ! V_213 ) {
V_400 = 0 ;
break;
}
V_21 += V_130 ;
}
return V_400 ;
}
int F_277 ( struct V_13 * V_16 )
{
return F_127 ( V_392 , & V_16 -> V_307 ) ;
}
int F_278 ( struct V_2 * V_3 ,
struct V_13 * V_16 , T_3 V_21 , int V_91 ,
T_9 * V_251 , int V_159 )
{
unsigned long V_120 ;
unsigned long V_401 ;
struct V_110 * V_110 ;
int V_79 ;
int V_58 = 0 ;
int V_402 = 0 ;
int V_403 = 1 ;
unsigned long V_186 ;
unsigned long V_404 = 0 ;
struct V_153 * V_153 = NULL ;
unsigned long V_202 = 0 ;
if ( F_127 ( V_392 , & V_16 -> V_307 ) )
return 0 ;
if ( V_21 ) {
F_26 ( V_21 < V_16 -> V_21 ) ;
V_401 = ( V_21 >> V_108 ) -
( V_16 -> V_21 >> V_108 ) ;
} else {
V_401 = 0 ;
}
V_186 = F_129 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_120 = V_401 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
if ( V_91 == V_405 ) {
if ( ! F_194 ( V_110 ) )
goto V_406;
} else {
F_96 ( V_110 ) ;
}
V_402 ++ ;
if ( ! F_163 ( V_110 ) ) {
V_404 ++ ;
V_403 = 0 ;
}
}
if ( V_403 ) {
if ( V_401 == 0 )
F_192 ( V_392 , & V_16 -> V_307 ) ;
goto V_406;
}
F_196 ( V_316 , & V_16 -> V_307 ) ;
V_16 -> V_407 = 0 ;
F_21 ( & V_16 -> V_315 , V_404 ) ;
for ( V_120 = V_401 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
if ( ! F_163 ( V_110 ) ) {
F_179 ( V_110 ) ;
V_79 = F_161 ( V_3 , V_110 ,
V_251 , & V_153 ,
V_159 , & V_202 ) ;
if ( V_79 )
V_58 = V_79 ;
} else {
F_94 ( V_110 ) ;
}
}
if ( V_153 ) {
V_79 = F_149 ( V_274 , V_153 , V_159 , V_202 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_58 || V_91 != V_408 )
return V_58 ;
for ( V_120 = V_401 ; V_120 < V_186 ; V_120 ++ ) {
V_110 = F_130 ( V_16 , V_120 ) ;
F_279 ( V_110 ) ;
if ( ! F_163 ( V_110 ) )
V_58 = - V_167 ;
}
return V_58 ;
V_406:
V_120 = V_401 ;
while ( V_402 > 0 ) {
V_110 = F_130 ( V_16 , V_120 ) ;
V_120 ++ ;
F_94 ( V_110 ) ;
V_402 -- ;
}
return V_58 ;
}
void F_280 ( struct V_13 * V_16 , void * V_409 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_410 ;
char * V_411 = ( char * ) V_409 ;
T_6 V_412 = V_16 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_21 ) >> V_108 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_412 + V_21 ) & ( ( unsigned long ) V_130 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_130 ( V_16 , V_120 ) ;
V_253 = F_105 ( V_25 , ( V_130 - V_44 ) ) ;
V_410 = F_281 ( V_110 ) ;
memcpy ( V_411 , V_410 + V_44 , V_253 ) ;
V_411 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_120 ++ ;
}
}
int F_282 ( struct V_13 * V_16 , unsigned long V_21 ,
unsigned long V_413 , char * * V_336 ,
unsigned long * V_414 ,
unsigned long * V_415 )
{
T_6 V_44 = V_21 & ( V_130 - 1 ) ;
char * V_410 ;
struct V_110 * V_46 ;
T_6 V_412 = V_16 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_21 ) >> V_108 ;
unsigned long V_416 = ( V_412 + V_21 + V_413 - 1 ) >>
V_108 ;
if ( V_120 != V_416 )
return - V_359 ;
if ( V_120 == 0 ) {
V_44 = V_412 ;
* V_414 = 0 ;
} else {
V_44 = 0 ;
* V_414 = ( ( T_3 ) V_120 << V_108 ) - V_412 ;
}
if ( V_21 + V_413 > V_16 -> V_25 ) {
F_9 ( V_20 L_31
L_32 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , V_21 , V_413 ) ;
F_26 ( 1 ) ;
return - V_359 ;
}
V_46 = F_130 ( V_16 , V_120 ) ;
V_410 = F_281 ( V_46 ) ;
* V_336 = V_410 + V_44 ;
* V_415 = V_130 - V_44 ;
return 0 ;
}
int F_283 ( struct V_13 * V_16 , const void * V_417 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_410 ;
char * V_418 = ( char * ) V_417 ;
T_6 V_412 = V_16 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_21 ) >> V_108 ;
int V_58 = 0 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_412 + V_21 ) & ( ( unsigned long ) V_130 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_130 ( V_16 , V_120 ) ;
V_253 = F_105 ( V_25 , ( V_130 - V_44 ) ) ;
V_410 = F_281 ( V_110 ) ;
V_58 = memcmp ( V_418 , V_410 + V_44 , V_253 ) ;
if ( V_58 )
break;
V_418 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_120 ++ ;
}
return V_58 ;
}
void F_284 ( struct V_13 * V_16 , const void * V_419 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_410 ;
char * V_420 = ( char * ) V_419 ;
T_6 V_412 = V_16 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_21 ) >> V_108 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_412 + V_21 ) & ( ( unsigned long ) V_130 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_130 ( V_16 , V_120 ) ;
F_26 ( ! F_163 ( V_110 ) ) ;
V_253 = F_105 ( V_25 , V_130 - V_44 ) ;
V_410 = F_281 ( V_110 ) ;
memcpy ( V_410 + V_44 , V_420 , V_253 ) ;
V_420 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_120 ++ ;
}
}
void F_285 ( struct V_13 * V_16 , char V_421 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_410 ;
T_6 V_412 = V_16 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_21 ) >> V_108 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_412 + V_21 ) & ( ( unsigned long ) V_130 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_130 ( V_16 , V_120 ) ;
F_26 ( ! F_163 ( V_110 ) ) ;
V_253 = F_105 ( V_25 , V_130 - V_44 ) ;
V_410 = F_281 ( V_110 ) ;
memset ( V_410 + V_44 , V_421 , V_253 ) ;
V_25 -= V_253 ;
V_44 = 0 ;
V_120 ++ ;
}
}
void F_286 ( struct V_13 * V_411 , struct V_13 * V_420 ,
unsigned long V_422 , unsigned long V_423 ,
unsigned long V_25 )
{
T_3 V_424 = V_411 -> V_25 ;
T_6 V_253 ;
T_6 V_44 ;
struct V_110 * V_110 ;
char * V_410 ;
T_6 V_412 = V_411 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_120 = ( V_412 + V_422 ) >> V_108 ;
F_26 ( V_420 -> V_25 != V_424 ) ;
V_44 = ( V_412 + V_422 ) &
( ( unsigned long ) V_130 - 1 ) ;
while ( V_25 > 0 ) {
V_110 = F_130 ( V_411 , V_120 ) ;
F_26 ( ! F_163 ( V_110 ) ) ;
V_253 = F_105 ( V_25 , ( unsigned long ) ( V_130 - V_44 ) ) ;
V_410 = F_281 ( V_110 ) ;
F_280 ( V_420 , V_410 + V_44 , V_423 , V_253 ) ;
V_423 += V_253 ;
V_25 -= V_253 ;
V_44 = 0 ;
V_120 ++ ;
}
}
static void F_287 ( struct V_110 * V_425 , struct V_110 * V_426 ,
unsigned long V_427 , unsigned long V_428 ,
unsigned long V_25 )
{
char * V_429 = F_281 ( V_425 ) ;
if ( V_425 == V_426 ) {
memmove ( V_429 + V_427 , V_429 + V_428 , V_25 ) ;
} else {
char * V_430 = F_281 ( V_426 ) ;
char * V_46 = V_429 + V_427 + V_25 ;
char * V_431 = V_430 + V_428 + V_25 ;
while ( V_25 -- )
* -- V_46 = * -- V_431 ;
}
}
static inline bool F_288 ( unsigned long V_420 , unsigned long V_411 , unsigned long V_25 )
{
unsigned long V_432 = ( V_420 > V_411 ) ? V_420 - V_411 : V_411 - V_420 ;
return V_432 < V_25 ;
}
static void F_289 ( struct V_110 * V_425 , struct V_110 * V_426 ,
unsigned long V_427 , unsigned long V_428 ,
unsigned long V_25 )
{
char * V_429 = F_281 ( V_425 ) ;
char * V_430 ;
int V_433 = 0 ;
if ( V_425 != V_426 ) {
V_430 = F_281 ( V_426 ) ;
} else {
V_430 = V_429 ;
if ( F_288 ( V_428 , V_427 , V_25 ) )
V_433 = 1 ;
}
if ( V_433 )
memmove ( V_429 + V_427 , V_430 + V_428 , V_25 ) ;
else
memcpy ( V_429 + V_427 , V_430 + V_428 , V_25 ) ;
}
void F_290 ( struct V_13 * V_411 , unsigned long V_422 ,
unsigned long V_423 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_434 ;
T_6 V_435 ;
T_6 V_412 = V_411 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_436 ;
unsigned long V_437 ;
if ( V_423 + V_25 > V_411 -> V_25 ) {
F_9 ( V_20 L_33
L_34 , V_423 , V_25 , V_411 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_422 + V_25 > V_411 -> V_25 ) {
F_9 ( V_20 L_35
L_34 , V_422 , V_25 , V_411 -> V_25 ) ;
F_54 ( 1 ) ;
}
while ( V_25 > 0 ) {
V_434 = ( V_412 + V_422 ) &
( ( unsigned long ) V_130 - 1 ) ;
V_435 = ( V_412 + V_423 ) &
( ( unsigned long ) V_130 - 1 ) ;
V_436 = ( V_412 + V_422 ) >> V_108 ;
V_437 = ( V_412 + V_423 ) >> V_108 ;
V_253 = F_105 ( V_25 , ( unsigned long ) ( V_130 -
V_435 ) ) ;
V_253 = F_93 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_289 ( F_130 ( V_411 , V_436 ) ,
F_130 ( V_411 , V_437 ) ,
V_434 , V_435 , V_253 ) ;
V_423 += V_253 ;
V_422 += V_253 ;
V_25 -= V_253 ;
}
}
void F_291 ( struct V_13 * V_411 , unsigned long V_422 ,
unsigned long V_423 , unsigned long V_25 )
{
T_6 V_253 ;
T_6 V_434 ;
T_6 V_435 ;
unsigned long V_438 = V_422 + V_25 - 1 ;
unsigned long V_439 = V_423 + V_25 - 1 ;
T_6 V_412 = V_411 -> V_21 & ( ( T_3 ) V_130 - 1 ) ;
unsigned long V_436 ;
unsigned long V_437 ;
if ( V_423 + V_25 > V_411 -> V_25 ) {
F_9 ( V_20 L_33
L_36 , V_423 , V_25 , V_411 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_422 + V_25 > V_411 -> V_25 ) {
F_9 ( V_20 L_35
L_36 , V_422 , V_25 , V_411 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_422 < V_423 ) {
F_290 ( V_411 , V_422 , V_423 , V_25 ) ;
return;
}
while ( V_25 > 0 ) {
V_436 = ( V_412 + V_438 ) >> V_108 ;
V_437 = ( V_412 + V_439 ) >> V_108 ;
V_434 = ( V_412 + V_438 ) &
( ( unsigned long ) V_130 - 1 ) ;
V_435 = ( V_412 + V_439 ) &
( ( unsigned long ) V_130 - 1 ) ;
V_253 = F_93 (unsigned long, len, src_off_in_page + 1 ) ;
V_253 = F_105 ( V_253 , V_434 + 1 ) ;
F_287 ( F_130 ( V_411 , V_436 ) ,
F_130 ( V_411 , V_437 ) ,
V_434 - V_253 + 1 ,
V_435 - V_253 + 1 , V_253 ) ;
V_438 -= V_253 ;
V_439 -= V_253 ;
V_25 -= V_253 ;
}
}
int F_292 ( struct V_110 * V_110 , T_2 V_34 )
{
struct V_13 * V_16 ;
F_52 ( & V_110 -> V_4 -> V_388 ) ;
if ( ! F_156 ( V_110 ) ) {
F_56 ( & V_110 -> V_4 -> V_388 ) ;
return 1 ;
}
V_16 = (struct V_13 * ) V_110 -> V_37 ;
F_54 ( ! V_16 ) ;
F_52 ( & V_16 -> V_385 ) ;
if ( F_10 ( & V_16 -> V_23 ) != 1 || F_241 ( V_16 ) ) {
F_56 ( & V_16 -> V_385 ) ;
F_56 ( & V_110 -> V_4 -> V_388 ) ;
return 0 ;
}
F_56 ( & V_110 -> V_4 -> V_388 ) ;
if ( ( V_34 & V_106 ) == V_106 )
V_34 = V_106 ;
if ( ! F_191 ( V_389 , & V_16 -> V_307 ) ) {
F_56 ( & V_16 -> V_385 ) ;
return 0 ;
}
F_262 ( V_16 , V_34 ) ;
return 1 ;
}
