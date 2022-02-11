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
V_15 = F_46 ( V_3 , V_15 , & V_65 , V_74 ) ;
goto V_18;
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
V_15 = F_45 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_55 () )
goto V_88;
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
V_15 = F_45 ( V_15 ) ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_55 () )
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
V_73 = F_48 ( V_73 ) ;
F_54 ( ! V_73 ) ;
V_79 = F_41 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
F_66 ( V_73 , V_81 ) ;
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
int V_65 , int V_99 , T_2 V_34 )
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
F_42 ( V_3 , V_15 , & V_65 ) ;
V_15 = F_46 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_55 () )
goto V_88;
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
V_15 = F_46 ( V_3 , V_15 , & V_99 , 0 ) ;
if ( V_83 == ( T_3 ) - 1 )
goto V_89;
V_21 = V_83 + 1 ;
if ( V_21 < V_22 && V_15 && V_15 -> V_21 == V_21 &&
! F_55 () )
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
V_73 = F_48 ( V_73 ) ;
if ( ! V_73 ) {
V_79 = - V_11 ;
goto V_89;
}
V_79 = F_41 ( V_3 , V_73 , V_21 , V_98 ,
& V_65 ) ;
if ( V_79 )
F_49 ( V_3 , V_79 ) ;
V_73 = NULL ;
V_21 = V_98 + 1 ;
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
F_46 ( V_3 , V_73 , & V_99 , 0 ) ;
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
V_100 | V_101 ,
NULL , V_81 , V_34 ) ;
}
int F_75 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 ,
V_77 | V_100 |
V_102 , 0 , 0 , NULL , V_34 ) ;
}
int F_76 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_103 , NULL ,
NULL , V_34 ) ;
}
int F_77 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_69 ( V_3 , V_21 , V_22 , V_101 , 0 ,
V_81 , V_34 ) ;
}
int F_78 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_81 , T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 , V_101 , 0 , 0 ,
V_81 , V_34 ) ;
}
int F_79 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , struct V_8 * * V_81 )
{
int V_79 ;
T_3 V_96 ;
while ( 1 ) {
V_79 = F_68 ( V_3 , V_21 , V_22 , V_104 | V_65 ,
V_104 , & V_96 ,
V_81 , V_105 ) ;
if ( V_79 == - V_69 ) {
F_63 ( V_3 , V_96 , V_22 , V_104 ) ;
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
V_79 = F_68 ( V_3 , V_21 , V_22 , V_104 , V_104 ,
& V_96 , NULL , V_105 ) ;
if ( V_79 == - V_69 ) {
if ( V_96 > V_21 )
F_51 ( V_3 , V_21 , V_96 - 1 ,
V_104 , 1 , 0 , NULL , V_105 ) ;
return 0 ;
}
return 1 ;
}
int F_82 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
struct V_8 * * V_82 , T_2 V_34 )
{
return F_51 ( V_3 , V_21 , V_22 , V_104 , 1 , 0 , V_82 ,
V_34 ) ;
}
int F_83 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
return F_51 ( V_3 , V_21 , V_22 , V_104 , 1 , 0 , NULL ,
V_105 ) ;
}
static int F_84 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 )
{
unsigned long V_106 = V_21 >> V_107 ;
unsigned long V_108 = V_22 >> V_107 ;
struct V_109 * V_109 ;
while ( V_106 <= V_108 ) {
V_109 = F_85 ( V_3 -> V_4 , V_106 ) ;
F_54 ( ! V_109 ) ;
F_86 ( V_109 ) ;
F_87 ( V_109 ) ;
V_106 ++ ;
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
T_3 * V_110 , T_3 * V_111 , int V_65 )
{
struct V_8 * V_15 ;
int V_58 = 1 ;
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_21 , V_65 ) ;
if ( V_15 ) {
* V_110 = V_15 -> V_21 ;
* V_111 = V_15 -> V_22 ;
V_58 = 0 ;
}
F_56 ( & V_3 -> V_32 ) ;
return V_58 ;
}
static T_5 T_3 F_90 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 * V_22 , T_3 V_112 ,
struct V_8 * * V_81 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_113 = * V_21 ;
T_3 V_68 = 0 ;
T_3 V_114 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_113 ) ;
if ( ! V_45 ) {
if ( ! V_68 )
* V_22 = ( T_3 ) - 1 ;
goto V_89;
}
while ( 1 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_68 && ( V_15 -> V_21 != V_113 ||
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
F_64 ( & V_15 -> V_23 ) ;
}
V_68 ++ ;
* V_22 = V_15 -> V_22 ;
V_113 = V_15 -> V_22 + 1 ;
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 )
break;
V_114 += V_15 -> V_22 - V_15 -> V_21 + 1 ;
if ( V_114 >= V_112 )
break;
}
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_68 ;
}
static T_5 void F_91 ( struct V_115 * V_115 ,
struct V_109 * V_116 ,
T_3 V_21 , T_3 V_22 )
{
int V_58 ;
struct V_109 * V_117 [ 16 ] ;
unsigned long V_106 = V_21 >> V_107 ;
unsigned long V_108 = V_22 >> V_107 ;
unsigned long V_118 = V_108 - V_106 + 1 ;
int V_119 ;
if ( V_106 == V_116 -> V_106 && V_108 == V_106 )
return;
while ( V_118 > 0 ) {
V_58 = F_92 ( V_115 -> V_120 , V_106 ,
F_93 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_117 ) ;
for ( V_119 = 0 ; V_119 < V_58 ; V_119 ++ ) {
if ( V_117 [ V_119 ] != V_116 )
F_94 ( V_117 [ V_119 ] ) ;
F_87 ( V_117 [ V_119 ] ) ;
}
V_118 -= V_58 ;
V_106 += V_58 ;
F_57 () ;
}
}
static T_5 int F_95 ( struct V_115 * V_115 ,
struct V_109 * V_116 ,
T_3 V_121 ,
T_3 V_122 )
{
unsigned long V_106 = V_121 >> V_107 ;
unsigned long V_123 = V_106 ;
unsigned long V_108 = V_122 >> V_107 ;
unsigned long V_124 = 0 ;
struct V_109 * V_117 [ 16 ] ;
unsigned long V_125 ;
int V_58 ;
int V_119 ;
if ( V_106 == V_116 -> V_106 && V_106 == V_108 )
return 0 ;
V_125 = V_108 - V_106 + 1 ;
while ( V_125 > 0 ) {
V_58 = F_92 ( V_115 -> V_120 , V_106 ,
F_93 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_117 ) ;
if ( V_58 == 0 ) {
V_58 = - V_126 ;
goto V_127;
}
for ( V_119 = 0 ; V_119 < V_58 ; V_119 ++ ) {
if ( V_117 [ V_119 ] != V_116 ) {
F_96 ( V_117 [ V_119 ] ) ;
if ( ! F_97 ( V_117 [ V_119 ] ) ||
V_117 [ V_119 ] -> V_4 != V_115 -> V_120 ) {
V_58 = - V_126 ;
F_94 ( V_117 [ V_119 ] ) ;
F_87 ( V_117 [ V_119 ] ) ;
goto V_127;
}
}
F_87 ( V_117 [ V_119 ] ) ;
V_124 ++ ;
}
V_125 -= V_58 ;
V_106 += V_58 ;
F_57 () ;
}
V_58 = 0 ;
V_127:
if ( V_58 && V_124 ) {
F_91 ( V_115 , V_116 ,
V_121 ,
( ( T_3 ) ( V_123 + V_124 - 1 ) ) <<
V_107 ) ;
}
return V_58 ;
}
static T_5 T_3 F_98 ( struct V_115 * V_115 ,
struct V_2 * V_3 ,
struct V_109 * V_116 ,
T_3 * V_21 , T_3 * V_22 ,
T_3 V_112 )
{
T_3 V_121 ;
T_3 V_122 ;
T_3 V_68 ;
struct V_8 * V_81 = NULL ;
int V_58 ;
int V_128 = 0 ;
V_86:
V_121 = * V_21 ;
V_122 = 0 ;
V_68 = F_90 ( V_3 , & V_121 , & V_122 ,
V_112 , & V_81 ) ;
if ( ! V_68 || V_122 <= * V_21 ) {
* V_21 = V_121 ;
* V_22 = V_122 ;
F_24 ( V_81 ) ;
return V_68 ;
}
if ( V_121 < * V_21 )
V_121 = * V_21 ;
if ( V_122 + 1 - V_121 > V_112 && V_128 )
V_122 = V_121 + V_129 - 1 ;
V_58 = F_95 ( V_115 , V_116 ,
V_121 , V_122 ) ;
if ( V_58 == - V_126 ) {
F_24 ( V_81 ) ;
if ( ! V_128 ) {
unsigned long V_44 = ( * V_21 ) & ( V_129 - 1 ) ;
V_112 = V_129 - V_44 ;
V_128 = 1 ;
goto V_86;
} else {
V_68 = 0 ;
goto V_130;
}
}
F_54 ( V_58 ) ;
F_79 ( V_3 , V_121 , V_122 , 0 , & V_81 ) ;
V_58 = F_99 ( V_3 , V_121 , V_122 ,
V_100 , 1 , V_81 ) ;
if ( ! V_58 ) {
F_82 ( V_3 , V_121 , V_122 ,
& V_81 , V_105 ) ;
F_91 ( V_115 , V_116 ,
V_121 , V_122 ) ;
F_57 () ;
goto V_86;
}
F_24 ( V_81 ) ;
* V_21 = V_121 ;
* V_22 = V_122 ;
V_130:
return V_68 ;
}
int F_100 ( struct V_115 * V_115 ,
struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 , struct V_109 * V_116 ,
unsigned long V_131 )
{
int V_58 ;
struct V_109 * V_117 [ 16 ] ;
unsigned long V_106 = V_21 >> V_107 ;
unsigned long V_108 = V_22 >> V_107 ;
unsigned long V_118 = V_108 - V_106 + 1 ;
int V_119 ;
int V_99 = 0 ;
if ( V_131 & V_132 )
V_99 |= V_104 ;
if ( V_131 & V_133 )
V_99 |= V_77 ;
if ( V_131 & V_134 )
V_99 |= V_100 ;
F_51 ( V_3 , V_21 , V_22 , V_99 , 1 , 0 , NULL , V_105 ) ;
if ( ! ( V_131 & ( V_135 | V_133 |
V_136 | V_137 |
V_138 ) ) )
return 0 ;
while ( V_118 > 0 ) {
V_58 = F_92 ( V_115 -> V_120 , V_106 ,
F_93 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_117 ) ;
for ( V_119 = 0 ; V_119 < V_58 ; V_119 ++ ) {
if ( V_131 & V_138 )
F_101 ( V_117 [ V_119 ] ) ;
if ( V_117 [ V_119 ] == V_116 ) {
F_87 ( V_117 [ V_119 ] ) ;
continue;
}
if ( V_131 & V_133 )
F_102 ( V_117 [ V_119 ] ) ;
if ( V_131 & V_136 )
F_86 ( V_117 [ V_119 ] ) ;
if ( V_131 & V_137 )
F_103 ( V_117 [ V_119 ] ) ;
if ( V_131 & V_135 )
F_94 ( V_117 [ V_119 ] ) ;
F_87 ( V_117 [ V_119 ] ) ;
}
V_118 -= V_58 ;
V_106 += V_58 ;
F_57 () ;
}
return 0 ;
}
T_3 F_104 ( struct V_2 * V_3 ,
T_3 * V_21 , T_3 V_139 , T_3 V_112 ,
unsigned long V_65 , int V_140 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
T_3 V_113 = * V_21 ;
T_3 V_114 = 0 ;
T_3 V_141 = 0 ;
int V_68 = 0 ;
if ( V_139 <= V_113 ) {
F_26 ( 1 ) ;
return 0 ;
}
F_52 ( & V_3 -> V_32 ) ;
if ( V_113 == 0 && V_65 == V_77 ) {
V_114 = V_3 -> V_31 ;
goto V_89;
}
V_45 = F_35 ( V_3 , V_113 ) ;
if ( ! V_45 )
goto V_89;
while ( 1 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 > V_139 )
break;
if ( V_140 && V_68 && V_15 -> V_21 > V_141 + 1 )
break;
if ( V_15 -> V_22 >= V_113 && ( V_15 -> V_15 & V_65 ) == V_65 ) {
V_114 += F_105 ( V_139 , V_15 -> V_22 ) + 1 -
F_106 ( V_113 , V_15 -> V_21 ) ;
if ( V_114 >= V_112 )
break;
if ( ! V_68 ) {
* V_21 = F_106 ( V_113 , V_15 -> V_21 ) ;
V_68 = 1 ;
}
V_141 = V_15 -> V_22 ;
} else if ( V_140 && V_68 ) {
break;
}
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 )
break;
}
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_114 ;
}
int F_107 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_37 )
{
struct V_41 * V_45 ;
struct V_8 * V_15 ;
int V_58 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
V_45 = F_35 ( V_3 , V_21 ) ;
if ( ! V_45 ) {
V_58 = - V_142 ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_142 ;
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
V_58 = - V_142 ;
goto V_89;
}
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_15 -> V_21 != V_21 ) {
V_58 = - V_142 ;
goto V_89;
}
* V_37 = V_15 -> V_37 ;
V_89:
F_56 ( & V_3 -> V_32 ) ;
return V_58 ;
}
int F_99 ( struct V_2 * V_3 , T_3 V_21 , T_3 V_22 ,
int V_65 , int V_143 , struct V_8 * V_82 )
{
struct V_8 * V_15 = NULL ;
struct V_41 * V_45 ;
int V_144 = 0 ;
F_52 ( & V_3 -> V_32 ) ;
if ( V_82 && V_82 -> V_3 && V_82 -> V_21 <= V_21 &&
V_82 -> V_22 > V_21 )
V_45 = & V_82 -> V_41 ;
else
V_45 = F_35 ( V_3 , V_21 ) ;
while ( V_45 && V_21 <= V_22 ) {
V_15 = F_29 ( V_45 , struct V_8 , V_41 ) ;
if ( V_143 && V_15 -> V_21 > V_21 ) {
V_144 = 0 ;
break;
}
if ( V_15 -> V_21 > V_22 )
break;
if ( V_15 -> V_15 & V_65 ) {
V_144 = 1 ;
if ( ! V_143 )
break;
} else if ( V_143 ) {
V_144 = 0 ;
break;
}
if ( V_15 -> V_22 == ( T_3 ) - 1 )
break;
V_21 = V_15 -> V_22 + 1 ;
if ( V_21 > V_22 )
break;
V_45 = F_33 ( V_45 ) ;
if ( ! V_45 ) {
if ( V_143 )
V_144 = 0 ;
break;
}
}
F_56 ( & V_3 -> V_32 ) ;
return V_144 ;
}
static void F_109 ( struct V_2 * V_3 , struct V_109 * V_109 )
{
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_22 = V_21 + V_129 - 1 ;
if ( F_99 ( V_3 , V_21 , V_22 , V_101 , 1 , NULL ) )
F_110 ( V_109 ) ;
}
static void F_111 ( struct V_2 * V_3 , struct V_109 * V_109 )
{
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_22 = V_21 + V_129 - 1 ;
if ( ! F_99 ( V_3 , V_21 , V_22 , V_104 , 0 , NULL ) )
F_94 ( V_109 ) ;
}
static void F_112 ( struct V_2 * V_3 ,
struct V_109 * V_109 )
{
F_103 ( V_109 ) ;
}
static int F_113 ( struct V_115 * V_115 , struct V_145 * V_146 ,
int V_147 )
{
int V_58 ;
int V_79 = 0 ;
struct V_2 * V_148 = & F_114 ( V_115 ) -> V_149 ;
F_107 ( V_148 , V_146 -> V_21 , 0 ) ;
V_58 = F_73 ( V_148 , V_146 -> V_21 ,
V_146 -> V_21 + V_146 -> V_25 - 1 ,
V_104 | V_77 , V_105 ) ;
if ( V_58 )
V_79 = V_58 ;
if ( V_147 ) {
V_58 = F_73 ( & F_114 ( V_115 ) -> V_150 , V_146 -> V_21 ,
V_146 -> V_21 + V_146 -> V_25 - 1 ,
V_151 , V_105 ) ;
if ( V_58 && ! V_79 )
V_79 = V_58 ;
}
F_115 ( V_146 ) ;
return V_79 ;
}
static void F_116 ( struct V_152 * V_152 , int V_79 )
{
F_117 ( V_152 -> V_153 ) ;
}
int F_118 ( struct V_154 * V_155 , T_3 V_21 ,
T_3 V_156 , T_3 V_157 , struct V_109 * V_109 ,
int V_158 )
{
struct V_152 * V_152 ;
struct V_159 * V_160 ;
F_119 ( V_161 ) ;
T_3 V_162 = 0 ;
T_3 V_163 ;
struct V_164 * V_165 = NULL ;
int V_58 ;
F_54 ( ! V_158 ) ;
V_152 = F_120 ( V_105 , 1 ) ;
if ( ! V_152 )
return - V_166 ;
V_152 -> V_153 = & V_161 ;
V_152 -> V_167 = F_116 ;
V_152 -> V_168 = 0 ;
V_162 = V_156 ;
V_58 = F_121 ( V_155 , V_169 , V_157 ,
& V_162 , & V_165 , V_158 ) ;
if ( V_58 ) {
F_122 ( V_152 ) ;
return - V_166 ;
}
F_54 ( V_158 != V_165 -> V_158 ) ;
V_163 = V_165 -> V_170 [ V_158 - 1 ] . V_171 >> 9 ;
V_152 -> V_172 = V_163 ;
V_160 = V_165 -> V_170 [ V_158 - 1 ] . V_160 ;
F_115 ( V_165 ) ;
if ( ! V_160 || ! V_160 -> V_173 || ! V_160 -> V_174 ) {
F_122 ( V_152 ) ;
return - V_166 ;
}
V_152 -> V_175 = V_160 -> V_173 ;
F_123 ( V_152 , V_109 , V_156 , V_21 - F_124 ( V_109 ) ) ;
F_125 ( V_176 , V_152 ) ;
F_126 ( & V_161 ) ;
if ( ! F_127 ( V_177 , & V_152 -> V_178 ) ) {
F_122 ( V_152 ) ;
F_128 ( V_160 , V_179 ) ;
return - V_166 ;
}
F_129 ( V_180 L_13
L_14 , V_109 -> V_4 -> V_5 -> V_181 ,
V_21 , F_130 ( V_160 -> V_182 ) , V_163 ) ;
F_122 ( V_152 ) ;
return 0 ;
}
int F_131 ( struct V_183 * V_43 , struct V_13 * V_16 ,
int V_158 )
{
struct V_154 * V_155 = & V_43 -> V_184 -> V_185 ;
T_3 V_21 = V_16 -> V_21 ;
unsigned long V_119 , V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
int V_58 = 0 ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
struct V_109 * V_46 = F_133 ( V_16 , V_119 ) ;
V_58 = F_118 ( V_155 , V_21 , V_129 ,
V_21 , V_46 , V_158 ) ;
if ( V_58 )
break;
V_21 += V_129 ;
}
return V_58 ;
}
static int F_134 ( T_3 V_21 , struct V_109 * V_109 )
{
T_3 V_37 ;
T_3 V_187 ;
struct V_145 * V_188 ;
struct V_154 * V_155 ;
struct V_8 * V_15 ;
int V_189 ;
int V_147 = 0 ;
int V_58 ;
struct V_115 * V_115 = V_109 -> V_4 -> V_5 ;
V_37 = 0 ;
V_58 = F_104 ( & F_114 ( V_115 ) -> V_149 , & V_37 ,
( T_3 ) - 1 , 1 , V_77 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_58 = F_108 ( & F_114 ( V_115 ) -> V_149 , V_21 ,
& V_187 ) ;
if ( V_58 )
return 0 ;
V_188 = (struct V_145 * ) ( unsigned long ) V_187 ;
F_54 ( ! V_188 -> V_190 ) ;
if ( V_188 -> V_191 ) {
F_135 ( L_15 ,
V_188 -> V_21 ) ;
V_147 = 1 ;
goto V_89;
}
F_52 ( & F_114 ( V_115 ) -> V_150 . V_32 ) ;
V_15 = F_88 ( & F_114 ( V_115 ) -> V_150 ,
V_188 -> V_21 ,
V_104 ) ;
F_56 ( & F_114 ( V_115 ) -> V_150 . V_32 ) ;
if ( V_15 && V_15 -> V_21 == V_188 -> V_21 ) {
V_155 = & F_114 ( V_115 ) -> V_43 -> V_184 -> V_185 ;
V_189 = F_136 ( V_155 , V_188 -> V_157 ,
V_188 -> V_25 ) ;
if ( V_189 > 1 ) {
V_58 = F_118 ( V_155 , V_21 , V_188 -> V_25 ,
V_188 -> V_157 , V_109 ,
V_188 -> V_192 ) ;
V_147 = ! V_58 ;
}
}
V_89:
if ( ! V_58 )
V_58 = F_113 ( V_115 , V_188 , V_147 ) ;
return V_58 ;
}
static int F_137 ( struct V_152 * V_193 , struct V_109 * V_109 ,
T_3 V_21 , T_3 V_22 , int V_192 ,
struct V_8 * V_15 )
{
struct V_145 * V_188 = NULL ;
T_3 V_37 ;
struct V_194 * V_195 ;
struct V_115 * V_115 = V_109 -> V_4 -> V_5 ;
struct V_2 * V_148 = & F_114 ( V_115 ) -> V_149 ;
struct V_2 * V_3 = & F_114 ( V_115 ) -> V_150 ;
struct V_196 * V_197 = & F_114 ( V_115 ) -> V_198 ;
struct V_152 * V_152 ;
int V_189 ;
int V_58 ;
int V_199 ;
T_3 V_157 ;
F_54 ( V_193 -> V_200 & V_201 ) ;
V_58 = F_108 ( V_148 , V_21 , & V_37 ) ;
if ( V_58 ) {
V_188 = F_138 ( sizeof( * V_188 ) , V_105 ) ;
if ( ! V_188 )
return - V_11 ;
V_188 -> V_21 = V_21 ;
V_188 -> V_25 = V_22 - V_21 + 1 ;
V_188 -> V_190 = 0 ;
V_188 -> V_202 = 0 ;
V_188 -> V_191 = 0 ;
F_139 ( & V_197 -> V_32 ) ;
V_195 = F_140 ( V_197 , V_21 , V_188 -> V_25 ) ;
if ( ! V_195 ) {
F_141 ( & V_197 -> V_32 ) ;
F_115 ( V_188 ) ;
return - V_166 ;
}
if ( V_195 -> V_21 > V_21 || V_195 -> V_21 + V_195 -> V_25 < V_21 ) {
F_142 ( V_195 ) ;
V_195 = NULL ;
}
F_141 ( & V_197 -> V_32 ) ;
if ( ! V_195 || F_143 ( V_195 ) ) {
F_115 ( V_188 ) ;
return - V_166 ;
}
V_157 = V_21 - V_195 -> V_21 ;
V_157 = V_195 -> V_203 + V_157 ;
if ( F_127 ( V_204 , & V_195 -> V_36 ) ) {
V_157 = V_195 -> V_203 ;
V_188 -> V_202 = V_205 ;
F_144 ( & V_188 -> V_202 ,
V_195 -> V_206 ) ;
}
F_135 ( L_16
L_17 , V_157 , V_21 , V_188 -> V_25 ) ;
V_188 -> V_157 = V_157 ;
F_142 ( V_195 ) ;
V_58 = F_72 ( V_148 , V_21 , V_22 ,
V_104 | V_77 , V_105 ) ;
if ( V_58 >= 0 )
V_58 = F_107 ( V_148 , V_21 ,
( T_3 ) ( unsigned long ) V_188 ) ;
if ( V_58 >= 0 )
V_58 = F_72 ( V_3 , V_21 , V_22 , V_151 ,
V_105 ) ;
if ( V_58 < 0 ) {
F_115 ( V_188 ) ;
return V_58 ;
}
} else {
V_188 = (struct V_145 * ) ( unsigned long ) V_37 ;
F_135 ( L_18
L_19 ,
V_188 -> V_157 , V_188 -> V_21 , V_188 -> V_25 ,
V_188 -> V_191 ) ;
}
V_189 = F_136 (
& F_114 ( V_115 ) -> V_43 -> V_184 -> V_185 ,
V_188 -> V_157 , V_188 -> V_25 ) ;
if ( V_189 == 1 ) {
F_135 ( L_20
L_21
L_22 , V_15 , V_189 ,
V_188 -> V_190 , V_192 ) ;
F_113 ( V_115 , V_188 , 0 ) ;
return - V_166 ;
}
if ( ! V_15 ) {
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_188 -> V_21 ,
V_104 ) ;
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
F_135 ( L_23
L_24 , V_15 ,
V_189 , V_188 -> V_190 , V_192 ) ;
F_113 ( V_115 , V_188 , 0 ) ;
return - V_166 ;
}
V_152 = F_120 ( V_105 , 1 ) ;
if ( ! V_152 ) {
F_113 ( V_115 , V_188 , 0 ) ;
return - V_166 ;
}
V_152 -> V_153 = V_15 ;
V_152 -> V_167 = V_193 -> V_167 ;
V_152 -> V_172 = V_188 -> V_157 >> 9 ;
V_152 -> V_175 = F_114 ( V_115 ) -> V_43 -> V_184 -> V_210 -> V_211 ;
V_152 -> V_168 = 0 ;
F_123 ( V_152 , V_109 , V_188 -> V_25 , V_21 - F_124 ( V_109 ) ) ;
F_135 ( L_25
L_26 , V_199 ,
V_188 -> V_190 , V_189 , V_188 -> V_191 ) ;
V_58 = V_3 -> V_30 -> V_212 ( V_115 , V_199 , V_152 ,
V_188 -> V_190 ,
V_188 -> V_202 , 0 ) ;
return V_58 ;
}
int F_145 ( struct V_109 * V_109 , int V_79 , T_3 V_21 , T_3 V_22 )
{
int V_213 = ( V_79 == 0 ) ;
struct V_2 * V_3 ;
int V_58 ;
V_3 = & F_114 ( V_109 -> V_4 -> V_5 ) -> V_150 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 ) {
V_58 = V_3 -> V_30 -> V_214 ( V_109 , V_21 ,
V_22 , NULL , V_213 ) ;
if ( V_58 )
V_213 = 0 ;
}
if ( ! V_213 ) {
F_146 ( V_109 ) ;
F_147 ( V_109 ) ;
}
return 0 ;
}
static void F_148 ( struct V_152 * V_152 , int V_79 )
{
struct V_215 * V_216 = V_152 -> V_217 + V_152 -> V_207 - 1 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_218 ;
do {
struct V_109 * V_109 = V_216 -> V_219 ;
V_3 = & F_114 ( V_109 -> V_4 -> V_5 ) -> V_150 ;
V_21 = ( ( T_3 ) V_109 -> V_106 << V_107 ) +
V_216 -> V_220 ;
V_22 = V_21 + V_216 -> V_221 - 1 ;
if ( V_216 -> V_220 == 0 && V_216 -> V_221 == V_129 )
V_218 = 1 ;
else
V_218 = 0 ;
if ( -- V_216 >= V_152 -> V_217 )
F_149 ( & V_216 -> V_219 -> V_36 ) ;
if ( F_145 ( V_109 , V_79 , V_21 , V_22 ) )
continue;
if ( V_218 )
F_103 ( V_109 ) ;
else
F_112 ( V_3 , V_109 ) ;
} while ( V_216 >= V_152 -> V_217 );
F_122 ( V_152 ) ;
}
static void F_150 ( struct V_152 * V_152 , int V_79 )
{
int V_213 = F_127 ( V_177 , & V_152 -> V_178 ) ;
struct V_215 * V_222 = V_152 -> V_217 + V_152 -> V_207 - 1 ;
struct V_215 * V_216 = V_152 -> V_217 ;
struct V_2 * V_3 ;
T_3 V_21 ;
T_3 V_22 ;
int V_218 ;
int V_223 ;
int V_58 ;
if ( V_79 )
V_213 = 0 ;
do {
struct V_109 * V_109 = V_216 -> V_219 ;
struct V_8 * V_82 = NULL ;
struct V_8 * V_15 ;
F_135 ( L_27
L_28 , V_152 -> V_207 , V_152 -> V_224 , V_79 ,
( long int ) V_152 -> V_175 ) ;
V_3 = & F_114 ( V_109 -> V_4 -> V_5 ) -> V_150 ;
V_21 = ( ( T_3 ) V_109 -> V_106 << V_107 ) +
V_216 -> V_220 ;
V_22 = V_21 + V_216 -> V_221 - 1 ;
if ( V_216 -> V_220 == 0 && V_216 -> V_221 == V_129 )
V_218 = 1 ;
else
V_218 = 0 ;
if ( ++ V_216 <= V_222 )
F_149 ( & V_216 -> V_219 -> V_36 ) ;
F_52 ( & V_3 -> V_32 ) ;
V_15 = F_88 ( V_3 , V_21 , V_104 ) ;
if ( V_15 && V_15 -> V_21 == V_21 ) {
F_66 ( V_15 , & V_82 ) ;
}
F_56 ( & V_3 -> V_32 ) ;
V_223 = ( int ) ( unsigned long ) V_152 -> V_175 ;
if ( V_213 && V_3 -> V_30 && V_3 -> V_30 -> V_225 ) {
V_58 = V_3 -> V_30 -> V_225 ( V_109 , V_21 , V_22 ,
V_15 , V_223 ) ;
if ( V_58 )
V_213 = 0 ;
else
F_134 ( V_21 , V_109 ) ;
}
if ( ! V_213 && V_3 -> V_30 && V_3 -> V_30 -> V_226 ) {
V_58 = V_3 -> V_30 -> V_226 ( V_109 , V_223 ) ;
if ( ! V_58 && ! V_79 &&
F_127 ( V_177 , & V_152 -> V_178 ) )
V_213 = 1 ;
} else if ( ! V_213 ) {
V_58 = F_137 ( V_152 , V_109 , V_21 , V_22 , V_223 , NULL ) ;
if ( V_58 == 0 ) {
V_213 =
F_127 ( V_177 , & V_152 -> V_178 ) ;
if ( V_79 )
V_213 = 0 ;
F_67 ( & V_82 ) ;
continue;
}
}
if ( V_213 && V_3 -> V_227 ) {
F_77 ( V_3 , V_21 , V_22 , & V_82 ,
V_29 ) ;
}
F_82 ( V_3 , V_21 , V_22 , & V_82 , V_29 ) ;
if ( V_218 ) {
if ( V_213 ) {
F_110 ( V_109 ) ;
} else {
F_146 ( V_109 ) ;
F_147 ( V_109 ) ;
}
F_94 ( V_109 ) ;
} else {
if ( V_213 ) {
F_109 ( V_3 , V_109 ) ;
} else {
F_146 ( V_109 ) ;
F_147 ( V_109 ) ;
}
F_111 ( V_3 , V_109 ) ;
}
} while ( V_216 <= V_222 );
F_122 ( V_152 ) ;
}
struct V_152 *
F_151 ( struct V_228 * V_173 , T_3 V_229 , int V_230 ,
T_2 V_231 )
{
struct V_152 * V_152 ;
V_152 = F_120 ( V_231 , V_230 ) ;
if ( V_152 == NULL && ( V_232 -> V_36 & V_233 ) ) {
while ( ! V_152 && ( V_230 /= 2 ) )
V_152 = F_120 ( V_231 , V_230 ) ;
}
if ( V_152 ) {
V_152 -> V_168 = 0 ;
V_152 -> V_175 = V_173 ;
V_152 -> V_172 = V_229 ;
}
return V_152 ;
}
static int T_4 F_152 ( int V_234 , struct V_152 * V_152 ,
int V_158 , unsigned long V_202 )
{
int V_58 = 0 ;
struct V_215 * V_216 = V_152 -> V_217 + V_152 -> V_207 - 1 ;
struct V_109 * V_109 = V_216 -> V_219 ;
struct V_2 * V_3 = V_152 -> V_153 ;
T_3 V_21 ;
V_21 = ( ( T_3 ) V_109 -> V_106 << V_107 ) + V_216 -> V_220 ;
V_152 -> V_153 = NULL ;
F_153 ( V_152 ) ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_212 )
V_58 = V_3 -> V_30 -> V_212 ( V_109 -> V_4 -> V_5 , V_234 , V_152 ,
V_158 , V_202 , V_21 ) ;
else
F_125 ( V_234 , V_152 ) ;
if ( F_154 ( V_152 , V_235 ) )
V_58 = - V_236 ;
F_122 ( V_152 ) ;
return V_58 ;
}
static int F_155 ( struct V_2 * V_3 , struct V_109 * V_109 ,
unsigned long V_44 , T_6 V_237 , struct V_152 * V_152 ,
unsigned long V_202 )
{
int V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_238 )
V_58 = V_3 -> V_30 -> V_238 ( V_109 , V_44 , V_237 , V_152 ,
V_202 ) ;
F_54 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_156 ( int V_234 , struct V_2 * V_3 ,
struct V_109 * V_109 , T_7 V_163 ,
T_6 V_237 , unsigned long V_44 ,
struct V_228 * V_173 ,
struct V_152 * * V_239 ,
unsigned long V_240 ,
T_8 V_241 ,
int V_158 ,
unsigned long V_242 ,
unsigned long V_202 )
{
int V_58 = 0 ;
struct V_152 * V_152 ;
int V_243 ;
int V_140 = 0 ;
int V_244 = V_202 & V_205 ;
int V_245 = V_242 & V_205 ;
T_6 V_246 = F_93 ( T_6 , V_237 , V_129 ) ;
if ( V_239 && * V_239 ) {
V_152 = * V_239 ;
if ( V_245 )
V_140 = V_152 -> V_172 == V_163 ;
else
V_140 = V_152 -> V_172 + ( V_152 -> V_168 >> 9 ) ==
V_163 ;
if ( V_242 != V_202 || ! V_140 ||
F_155 ( V_3 , V_109 , V_44 , V_246 , V_152 , V_202 ) ||
F_123 ( V_152 , V_109 , V_246 , V_44 ) < V_246 ) {
V_58 = F_152 ( V_234 , V_152 , V_158 ,
V_242 ) ;
if ( V_58 < 0 )
return V_58 ;
V_152 = NULL ;
} else {
return 0 ;
}
}
if ( V_244 )
V_243 = V_247 ;
else
V_243 = F_157 ( V_173 ) ;
V_152 = F_151 ( V_173 , V_163 , V_243 , V_105 | V_248 ) ;
if ( ! V_152 )
return - V_11 ;
F_123 ( V_152 , V_109 , V_246 , V_44 ) ;
V_152 -> V_167 = V_241 ;
V_152 -> V_153 = V_3 ;
if ( V_239 )
* V_239 = V_152 ;
else
V_58 = F_152 ( V_234 , V_152 , V_158 , V_202 ) ;
return V_58 ;
}
void F_158 ( struct V_13 * V_16 , struct V_109 * V_109 )
{
if ( ! F_159 ( V_109 ) ) {
F_160 ( V_109 ) ;
F_161 ( V_109 ) ;
F_162 ( V_109 , ( unsigned long ) V_16 ) ;
} else {
F_26 ( V_109 -> V_37 != ( unsigned long ) V_16 ) ;
}
}
void F_163 ( struct V_109 * V_109 )
{
if ( ! F_159 ( V_109 ) ) {
F_160 ( V_109 ) ;
F_161 ( V_109 ) ;
F_162 ( V_109 , V_249 ) ;
}
}
static int F_164 ( struct V_2 * V_3 ,
struct V_109 * V_109 ,
T_9 * V_250 ,
struct V_152 * * V_152 , int V_158 ,
unsigned long * V_202 )
{
struct V_115 * V_115 = V_109 -> V_4 -> V_5 ;
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_251 = V_21 + V_129 - 1 ;
T_3 V_22 ;
T_3 V_252 = V_21 ;
T_3 V_253 ;
T_3 V_254 = F_165 ( V_115 ) ;
T_3 V_203 ;
T_3 V_255 ;
T_7 V_163 ;
struct V_194 * V_195 ;
struct V_228 * V_173 ;
struct V_256 * V_257 ;
int V_58 ;
int V_243 = 0 ;
T_6 V_258 = 0 ;
T_6 V_259 ;
T_6 V_260 ;
T_6 V_261 = V_115 -> V_6 -> V_262 ;
unsigned long V_263 = 0 ;
F_163 ( V_109 ) ;
if ( ! F_166 ( V_109 ) ) {
if ( F_167 ( V_109 ) == 0 ) {
F_54 ( V_261 != V_264 ) ;
goto V_89;
}
}
V_22 = V_251 ;
while ( 1 ) {
F_80 ( V_3 , V_21 , V_22 ) ;
V_257 = F_168 ( V_115 , V_21 ) ;
if ( ! V_257 )
break;
F_83 ( V_3 , V_21 , V_22 ) ;
F_169 ( V_115 , V_257 , 1 ) ;
F_170 ( V_257 ) ;
}
if ( V_109 -> V_106 == V_254 >> V_107 ) {
char * V_265 ;
T_6 V_266 = V_254 & ( V_129 - 1 ) ;
if ( V_266 ) {
V_259 = V_129 - V_266 ;
V_265 = F_171 ( V_109 ) ;
memset ( V_265 + V_266 , 0 , V_259 ) ;
F_172 ( V_109 ) ;
F_173 ( V_265 ) ;
}
}
while ( V_252 <= V_22 ) {
if ( V_252 >= V_254 ) {
char * V_265 ;
struct V_8 * V_82 = NULL ;
V_259 = V_129 - V_258 ;
V_265 = F_171 ( V_109 ) ;
memset ( V_265 + V_258 , 0 , V_259 ) ;
F_172 ( V_109 ) ;
F_173 ( V_265 ) ;
F_77 ( V_3 , V_252 , V_252 + V_259 - 1 ,
& V_82 , V_105 ) ;
F_82 ( V_3 , V_252 , V_252 + V_259 - 1 ,
& V_82 , V_105 ) ;
break;
}
V_195 = V_250 ( V_115 , V_109 , V_258 , V_252 ,
V_22 - V_252 + 1 , 0 ) ;
if ( F_174 ( V_195 ) ) {
F_147 ( V_109 ) ;
F_83 ( V_3 , V_252 , V_22 ) ;
break;
}
V_253 = V_252 - V_195 -> V_21 ;
F_54 ( F_175 ( V_195 ) <= V_252 ) ;
F_54 ( V_22 < V_252 ) ;
if ( F_127 ( V_204 , & V_195 -> V_36 ) ) {
V_263 = V_205 ;
F_144 ( & V_263 ,
V_195 -> V_206 ) ;
}
V_259 = F_105 ( F_175 ( V_195 ) - V_252 , V_22 - V_252 + 1 ) ;
V_255 = F_105 ( F_175 ( V_195 ) - 1 , V_22 ) ;
V_259 = ( V_259 + V_261 - 1 ) & ~ ( ( T_3 ) V_261 - 1 ) ;
if ( V_263 & V_205 ) {
V_260 = V_195 -> V_267 ;
V_163 = V_195 -> V_203 >> 9 ;
} else {
V_163 = ( V_195 -> V_203 + V_253 ) >> 9 ;
V_260 = V_259 ;
}
V_173 = V_195 -> V_173 ;
V_203 = V_195 -> V_203 ;
if ( F_127 ( V_268 , & V_195 -> V_36 ) )
V_203 = V_269 ;
F_142 ( V_195 ) ;
V_195 = NULL ;
if ( V_203 == V_269 ) {
char * V_265 ;
struct V_8 * V_82 = NULL ;
V_265 = F_171 ( V_109 ) ;
memset ( V_265 + V_258 , 0 , V_259 ) ;
F_172 ( V_109 ) ;
F_173 ( V_265 ) ;
F_77 ( V_3 , V_252 , V_252 + V_259 - 1 ,
& V_82 , V_105 ) ;
F_82 ( V_3 , V_252 , V_252 + V_259 - 1 ,
& V_82 , V_105 ) ;
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
continue;
}
if ( F_99 ( V_3 , V_252 , V_255 ,
V_101 , 1 , NULL ) ) {
F_109 ( V_3 , V_109 ) ;
F_83 ( V_3 , V_252 , V_252 + V_259 - 1 ) ;
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
continue;
}
if ( V_203 == V_270 ) {
F_147 ( V_109 ) ;
F_83 ( V_3 , V_252 , V_252 + V_259 - 1 ) ;
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
continue;
}
V_58 = 0 ;
if ( V_3 -> V_30 && V_3 -> V_30 -> V_271 ) {
V_58 = V_3 -> V_30 -> V_271 ( V_109 , V_252 ,
V_252 + V_259 - 1 ) ;
}
if ( ! V_58 ) {
unsigned long V_272 = ( V_254 >> V_107 ) + 1 ;
V_272 -= V_109 -> V_106 ;
V_58 = F_156 ( V_273 , V_3 , V_109 ,
V_163 , V_260 , V_258 ,
V_173 , V_152 , V_272 ,
F_150 , V_158 ,
* V_202 ,
V_263 ) ;
F_54 ( V_58 == - V_11 ) ;
V_243 ++ ;
* V_202 = V_263 ;
}
if ( V_58 )
F_147 ( V_109 ) ;
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
}
V_89:
if ( ! V_243 ) {
if ( ! F_176 ( V_109 ) )
F_110 ( V_109 ) ;
F_94 ( V_109 ) ;
}
return 0 ;
}
int F_177 ( struct V_2 * V_3 , struct V_109 * V_109 ,
T_9 * V_250 , int V_158 )
{
struct V_152 * V_152 = NULL ;
unsigned long V_202 = 0 ;
int V_58 ;
V_58 = F_164 ( V_3 , V_109 , V_250 , & V_152 , V_158 ,
& V_202 ) ;
if ( V_152 )
V_58 = F_152 ( V_273 , V_152 , V_158 , V_202 ) ;
return V_58 ;
}
static T_5 void F_178 ( struct V_109 * V_109 ,
struct V_274 * V_275 ,
unsigned long V_276 )
{
V_275 -> V_277 -= V_276 ;
if ( V_275 -> V_278 || ( V_275 -> V_277 > 0 &&
V_275 -> V_279 == 0 && V_275 -> V_280 == V_281 ) )
V_109 -> V_4 -> V_282 = V_109 -> V_106 + V_276 ;
}
static int F_179 ( struct V_109 * V_109 , struct V_274 * V_275 ,
void * V_283 )
{
struct V_115 * V_115 = V_109 -> V_4 -> V_5 ;
struct V_284 * V_285 = V_283 ;
struct V_2 * V_3 = V_285 -> V_3 ;
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_121 ;
T_3 V_251 = V_21 + V_129 - 1 ;
T_3 V_22 ;
T_3 V_252 = V_21 ;
T_3 V_253 ;
T_3 V_254 = F_165 ( V_115 ) ;
T_3 V_203 ;
T_3 V_259 ;
T_7 V_163 ;
struct V_8 * V_81 = NULL ;
struct V_194 * V_195 ;
struct V_228 * V_173 ;
int V_58 ;
int V_243 = 0 ;
T_6 V_258 = 0 ;
T_6 V_261 ;
T_10 V_286 = F_165 ( V_115 ) ;
unsigned long V_108 = V_286 >> V_107 ;
T_3 V_287 ;
T_3 V_122 ;
int V_288 ;
int V_289 ;
int V_290 ;
unsigned long V_276 = 0 ;
bool V_291 = true ;
if ( V_275 -> V_292 == V_293 )
V_290 = V_176 ;
else
V_290 = V_169 ;
F_180 ( V_109 , V_115 , V_275 ) ;
F_26 ( ! F_181 ( V_109 ) ) ;
F_182 ( V_109 ) ;
V_258 = V_286 & ( V_129 - 1 ) ;
if ( V_109 -> V_106 > V_108 ||
( V_109 -> V_106 == V_108 && ! V_258 ) ) {
V_109 -> V_4 -> V_294 -> V_295 ( V_109 , 0 ) ;
F_94 ( V_109 ) ;
return 0 ;
}
if ( V_109 -> V_106 == V_108 ) {
char * V_265 ;
V_265 = F_171 ( V_109 ) ;
memset ( V_265 + V_258 , 0 ,
V_129 - V_258 ) ;
F_173 ( V_265 ) ;
F_172 ( V_109 ) ;
}
V_258 = 0 ;
F_163 ( V_109 ) ;
if ( ! V_3 -> V_30 || ! V_3 -> V_30 -> V_291 )
V_291 = false ;
V_121 = V_21 ;
V_122 = 0 ;
V_288 = 0 ;
if ( ! V_285 -> V_296 && V_291 ) {
T_3 V_297 = 0 ;
F_178 ( V_109 , V_275 , 0 ) ;
while ( V_122 < V_251 ) {
V_287 = F_98 ( V_115 , V_3 ,
V_109 ,
& V_121 ,
& V_122 ,
128 * 1024 * 1024 ) ;
if ( V_287 == 0 ) {
V_121 = V_122 + 1 ;
continue;
}
V_58 = V_3 -> V_30 -> V_291 ( V_115 , V_109 ,
V_121 ,
V_122 ,
& V_288 ,
& V_276 ) ;
if ( V_58 ) {
F_147 ( V_109 ) ;
goto V_127;
}
V_297 += ( V_122 - V_121 +
V_129 ) >>
V_107 ;
V_121 = V_122 + 1 ;
}
if ( V_275 -> V_277 < V_297 ) {
int V_298 = 8192 ;
if ( V_297 < V_298 * 2 )
V_298 = V_297 ;
V_275 -> V_277 = F_93 ( T_3 , V_297 ,
V_298 ) ;
}
if ( V_288 ) {
V_58 = 0 ;
V_275 -> V_277 -= V_276 ;
goto V_299;
}
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_300 ) {
V_58 = V_3 -> V_30 -> V_300 ( V_109 , V_21 ,
V_251 ) ;
if ( V_58 ) {
if ( V_58 == - V_301 )
V_275 -> V_302 ++ ;
else
F_183 ( V_275 , V_109 ) ;
F_178 ( V_109 , V_275 , V_276 ) ;
F_94 ( V_109 ) ;
V_58 = 0 ;
goto V_299;
}
}
F_178 ( V_109 , V_275 , V_276 + 1 ) ;
V_22 = V_251 ;
if ( V_254 <= V_21 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_109 , V_21 ,
V_251 , NULL , 1 ) ;
goto V_127;
}
V_261 = V_115 -> V_6 -> V_262 ;
while ( V_252 <= V_22 ) {
if ( V_252 >= V_254 ) {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_109 , V_252 ,
V_251 , NULL , 1 ) ;
break;
}
V_195 = V_285 -> V_250 ( V_115 , V_109 , V_258 , V_252 ,
V_22 - V_252 + 1 , 1 ) ;
if ( F_174 ( V_195 ) ) {
F_147 ( V_109 ) ;
break;
}
V_253 = V_252 - V_195 -> V_21 ;
F_54 ( F_175 ( V_195 ) <= V_252 ) ;
F_54 ( V_22 < V_252 ) ;
V_259 = F_105 ( F_175 ( V_195 ) - V_252 , V_22 - V_252 + 1 ) ;
V_259 = ( V_259 + V_261 - 1 ) & ~ ( ( T_3 ) V_261 - 1 ) ;
V_163 = ( V_195 -> V_203 + V_253 ) >> 9 ;
V_173 = V_195 -> V_173 ;
V_203 = V_195 -> V_203 ;
V_289 = F_127 ( V_204 , & V_195 -> V_36 ) ;
F_142 ( V_195 ) ;
V_195 = NULL ;
if ( V_289 || V_203 == V_269 ||
V_203 == V_270 ) {
if ( ! V_289 && V_3 -> V_30 &&
V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_109 , V_252 ,
V_252 + V_259 - 1 ,
NULL , 1 ) ;
else if ( V_289 ) {
V_243 ++ ;
}
V_252 += V_259 ;
V_258 += V_259 ;
continue;
}
if ( 0 && ! F_99 ( V_3 , V_252 , V_252 + V_259 - 1 ,
V_77 , 0 , NULL ) ) {
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
continue;
}
if ( V_3 -> V_30 && V_3 -> V_30 -> V_303 ) {
V_58 = V_3 -> V_30 -> V_303 ( V_109 , V_252 ,
V_252 + V_259 - 1 ) ;
} else {
V_58 = 0 ;
}
if ( V_58 ) {
F_147 ( V_109 ) ;
} else {
unsigned long V_304 = V_108 + 1 ;
F_84 ( V_3 , V_252 , V_252 + V_259 - 1 ) ;
if ( ! F_184 ( V_109 ) ) {
F_9 ( V_20 L_29
L_30 ,
V_109 -> V_106 , ( unsigned long long ) V_252 ,
( unsigned long long ) V_22 ) ;
}
V_58 = F_156 ( V_290 , V_3 , V_109 ,
V_163 , V_259 , V_258 ,
V_173 , & V_285 -> V_152 , V_304 ,
F_148 ,
0 , 0 , 0 ) ;
if ( V_58 )
F_147 ( V_109 ) ;
}
V_252 = V_252 + V_259 ;
V_258 += V_259 ;
V_243 ++ ;
}
V_127:
if ( V_243 == 0 ) {
F_86 ( V_109 ) ;
F_103 ( V_109 ) ;
}
F_94 ( V_109 ) ;
V_299:
F_24 ( V_81 ) ;
return 0 ;
}
static int F_185 ( void * V_305 )
{
F_186 () ;
return 0 ;
}
static void F_187 ( struct V_13 * V_16 )
{
F_188 ( & V_16 -> V_306 , V_307 , F_185 ,
V_92 ) ;
}
static int F_189 ( struct V_13 * V_16 ,
struct V_1 * V_184 ,
struct V_284 * V_285 )
{
unsigned long V_119 , V_186 ;
int V_308 = 0 ;
int V_58 = 0 ;
if ( ! F_190 ( V_16 ) ) {
V_308 = 1 ;
F_191 ( V_285 ) ;
F_192 ( V_16 ) ;
}
if ( F_127 ( V_307 , & V_16 -> V_306 ) ) {
F_193 ( V_16 ) ;
if ( ! V_285 -> V_309 )
return 0 ;
if ( ! V_308 ) {
F_191 ( V_285 ) ;
V_308 = 1 ;
}
while ( 1 ) {
F_187 ( V_16 ) ;
F_192 ( V_16 ) ;
if ( ! F_127 ( V_307 , & V_16 -> V_306 ) )
break;
F_193 ( V_16 ) ;
}
}
F_52 ( & V_16 -> V_310 ) ;
if ( F_194 ( V_311 , & V_16 -> V_306 ) ) {
F_195 ( V_307 , & V_16 -> V_306 ) ;
F_56 ( & V_16 -> V_310 ) ;
F_196 ( V_16 , V_312 ) ;
F_52 ( & V_184 -> V_313 ) ;
if ( V_184 -> V_314 >= V_16 -> V_25 )
V_184 -> V_314 -= V_16 -> V_25 ;
else
F_26 ( 1 ) ;
F_56 ( & V_184 -> V_313 ) ;
V_58 = 1 ;
} else {
F_56 ( & V_16 -> V_310 ) ;
}
F_193 ( V_16 ) ;
if ( ! V_58 )
return V_58 ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
struct V_109 * V_46 = F_133 ( V_16 , V_119 ) ;
if ( ! F_197 ( V_46 ) ) {
if ( ! V_308 ) {
F_191 ( V_285 ) ;
V_308 = 1 ;
}
F_96 ( V_46 ) ;
}
}
return V_58 ;
}
static void F_198 ( struct V_13 * V_16 )
{
F_199 ( V_307 , & V_16 -> V_306 ) ;
F_200 () ;
F_201 ( & V_16 -> V_306 , V_307 ) ;
}
static void F_202 ( struct V_152 * V_152 , int V_79 )
{
int V_213 = V_79 == 0 ;
struct V_215 * V_216 = V_152 -> V_217 + V_152 -> V_207 - 1 ;
struct V_13 * V_16 ;
int V_127 ;
do {
struct V_109 * V_109 = V_216 -> V_219 ;
V_216 -- ;
V_16 = (struct V_13 * ) V_109 -> V_37 ;
F_54 ( ! V_16 ) ;
V_127 = F_25 ( & V_16 -> V_315 ) ;
if ( ! V_213 || F_127 ( V_316 , & V_16 -> V_306 ) ) {
F_195 ( V_316 , & V_16 -> V_306 ) ;
F_146 ( V_109 ) ;
F_147 ( V_109 ) ;
}
F_103 ( V_109 ) ;
if ( ! V_127 )
continue;
F_198 ( V_16 ) ;
} while ( V_216 >= V_152 -> V_217 );
F_122 ( V_152 ) ;
}
static int F_203 ( struct V_13 * V_16 ,
struct V_1 * V_184 ,
struct V_274 * V_275 ,
struct V_284 * V_285 )
{
struct V_228 * V_173 = V_184 -> V_210 -> V_211 ;
T_3 V_44 = V_16 -> V_21 ;
unsigned long V_119 , V_186 ;
int V_234 = ( V_285 -> V_309 ? V_176 : V_169 ) ;
int V_58 = 0 ;
F_199 ( V_316 , & V_16 -> V_306 ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_21 ( & V_16 -> V_315 , V_186 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
struct V_109 * V_46 = F_133 ( V_16 , V_119 ) ;
F_102 ( V_46 ) ;
F_86 ( V_46 ) ;
V_58 = F_156 ( V_234 , V_16 -> V_3 , V_46 , V_44 >> 9 ,
V_129 , 0 , V_173 , & V_285 -> V_152 ,
- 1 , F_202 ,
0 , 0 , 0 ) ;
if ( V_58 ) {
F_195 ( V_316 , & V_16 -> V_306 ) ;
F_147 ( V_46 ) ;
if ( F_204 ( V_186 - V_119 , & V_16 -> V_315 ) )
F_198 ( V_16 ) ;
V_58 = - V_166 ;
break;
}
V_44 += V_129 ;
F_178 ( V_46 , V_275 , 1 ) ;
F_94 ( V_46 ) ;
}
if ( F_205 ( V_58 ) ) {
for (; V_119 < V_186 ; V_119 ++ ) {
struct V_109 * V_46 = F_133 ( V_16 , V_119 ) ;
F_94 ( V_46 ) ;
}
}
return V_58 ;
}
int F_206 ( struct V_26 * V_4 ,
struct V_274 * V_275 )
{
struct V_2 * V_3 = & F_114 ( V_4 -> V_5 ) -> V_150 ;
struct V_1 * V_184 = F_114 ( V_4 -> V_5 ) -> V_43 -> V_184 ;
struct V_13 * V_16 , * V_317 = NULL ;
struct V_284 V_285 = {
. V_152 = NULL ,
. V_3 = V_3 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
} ;
int V_58 = 0 ;
int V_127 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_118 ;
T_11 V_106 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
F_207 ( & V_320 , 0 ) ;
if ( V_275 -> V_278 ) {
V_106 = V_4 -> V_282 ;
V_22 = - 1 ;
} else {
V_106 = V_275 -> V_279 >> V_107 ;
V_22 = V_275 -> V_280 >> V_107 ;
V_321 = 1 ;
}
if ( V_275 -> V_292 == V_293 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_275 -> V_292 == V_293 )
F_208 ( V_4 , V_106 , V_22 ) ;
while ( ! V_127 && ! V_318 && ( V_106 <= V_22 ) &&
( V_118 = F_209 ( & V_320 , V_4 , & V_106 , V_322 ,
F_105 ( V_22 - V_106 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_119 ;
V_321 = 1 ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
struct V_109 * V_109 = V_320 . V_117 [ V_119 ] ;
if ( ! F_159 ( V_109 ) )
continue;
if ( ! V_275 -> V_278 && V_109 -> V_106 > V_22 ) {
V_127 = 1 ;
break;
}
V_16 = (struct V_13 * ) V_109 -> V_37 ;
if ( ! V_16 ) {
F_26 ( 1 ) ;
continue;
}
if ( V_16 == V_317 )
continue;
if ( ! F_210 ( & V_16 -> V_23 ) ) {
F_26 ( 1 ) ;
continue;
}
V_317 = V_16 ;
V_58 = F_189 ( V_16 , V_184 , & V_285 ) ;
if ( ! V_58 ) {
F_211 ( V_16 ) ;
continue;
}
V_58 = F_203 ( V_16 , V_184 , V_275 , & V_285 ) ;
if ( V_58 ) {
V_127 = 1 ;
F_211 ( V_16 ) ;
break;
}
F_211 ( V_16 ) ;
V_318 = V_275 -> V_277 <= 0 ;
}
F_212 ( & V_320 ) ;
F_57 () ;
}
if ( ! V_321 && ! V_127 ) {
V_321 = 1 ;
V_106 = 0 ;
goto V_325;
}
F_191 ( & V_285 ) ;
return V_58 ;
}
static int F_213 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_274 * V_275 ,
T_12 V_327 , void * V_283 ,
void (* F_214)( void * ) )
{
struct V_115 * V_115 = V_4 -> V_5 ;
int V_58 = 0 ;
int V_127 = 0 ;
int V_318 = 0 ;
struct V_319 V_320 ;
int V_118 ;
T_11 V_106 ;
T_11 V_22 ;
int V_321 = 0 ;
int V_322 ;
if ( ! F_215 ( V_115 ) )
return 0 ;
F_207 ( & V_320 , 0 ) ;
if ( V_275 -> V_278 ) {
V_106 = V_4 -> V_282 ;
V_22 = - 1 ;
} else {
V_106 = V_275 -> V_279 >> V_107 ;
V_22 = V_275 -> V_280 >> V_107 ;
V_321 = 1 ;
}
if ( V_275 -> V_292 == V_293 )
V_322 = V_323 ;
else
V_322 = V_324 ;
V_325:
if ( V_275 -> V_292 == V_293 )
F_208 ( V_4 , V_106 , V_22 ) ;
while ( ! V_127 && ! V_318 && ( V_106 <= V_22 ) &&
( V_118 = F_209 ( & V_320 , V_4 , & V_106 , V_322 ,
F_105 ( V_22 - V_106 , ( T_11 ) V_326 - 1 ) + 1 ) ) ) {
unsigned V_119 ;
V_321 = 1 ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
struct V_109 * V_109 = V_320 . V_117 [ V_119 ] ;
if ( V_3 -> V_30 &&
V_3 -> V_30 -> V_328 ) {
V_3 -> V_30 -> V_328 ( V_109 ,
V_283 , F_214 ) ;
} else {
if ( ! F_197 ( V_109 ) ) {
F_214 ( V_283 ) ;
F_96 ( V_109 ) ;
}
}
if ( F_205 ( V_109 -> V_4 != V_4 ) ) {
F_94 ( V_109 ) ;
continue;
}
if ( ! V_275 -> V_278 && V_109 -> V_106 > V_22 ) {
V_127 = 1 ;
F_94 ( V_109 ) ;
continue;
}
if ( V_275 -> V_292 != V_329 ) {
if ( F_184 ( V_109 ) )
F_214 ( V_283 ) ;
F_216 ( V_109 ) ;
}
if ( F_184 ( V_109 ) ||
! F_102 ( V_109 ) ) {
F_94 ( V_109 ) ;
continue;
}
V_58 = (* V_327)( V_109 , V_275 , V_283 ) ;
if ( F_205 ( V_58 == V_330 ) ) {
F_94 ( V_109 ) ;
V_58 = 0 ;
}
if ( V_58 )
V_127 = 1 ;
V_318 = V_275 -> V_277 <= 0 ;
}
F_212 ( & V_320 ) ;
F_57 () ;
}
if ( ! V_321 && ! V_127 ) {
V_321 = 1 ;
V_106 = 0 ;
goto V_325;
}
F_217 ( V_115 ) ;
return V_58 ;
}
static void F_218 ( struct V_284 * V_285 )
{
if ( V_285 -> V_152 ) {
int V_234 = V_169 ;
int V_58 ;
if ( V_285 -> V_309 )
V_234 = V_176 ;
V_58 = F_152 ( V_234 , V_285 -> V_152 , 0 , 0 ) ;
F_54 ( V_58 < 0 ) ;
V_285 -> V_152 = NULL ;
}
}
static T_5 void F_191 ( void * V_283 )
{
struct V_284 * V_285 = V_283 ;
F_218 ( V_285 ) ;
}
int F_219 ( struct V_2 * V_3 , struct V_109 * V_109 ,
T_9 * V_250 ,
struct V_274 * V_275 )
{
int V_58 ;
struct V_284 V_285 = {
. V_152 = NULL ,
. V_3 = V_3 ,
. V_250 = V_250 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
} ;
V_58 = F_179 ( V_109 , V_275 , & V_285 ) ;
F_218 ( & V_285 ) ;
return V_58 ;
}
int F_220 ( struct V_2 * V_3 , struct V_115 * V_115 ,
T_3 V_21 , T_3 V_22 , T_9 * V_250 ,
int V_331 )
{
int V_58 = 0 ;
struct V_26 * V_4 = V_115 -> V_120 ;
struct V_109 * V_109 ;
unsigned long V_118 = ( V_22 - V_21 + V_129 ) >>
V_107 ;
struct V_284 V_285 = {
. V_152 = NULL ,
. V_3 = V_3 ,
. V_250 = V_250 ,
. V_296 = 1 ,
. V_309 = V_331 == V_293 ,
} ;
struct V_274 V_332 = {
. V_292 = V_331 ,
. V_277 = V_118 * 2 ,
. V_279 = V_21 ,
. V_280 = V_22 + 1 ,
} ;
while ( V_21 <= V_22 ) {
V_109 = F_85 ( V_4 , V_21 >> V_107 ) ;
if ( F_102 ( V_109 ) )
V_58 = F_179 ( V_109 , & V_332 , & V_285 ) ;
else {
if ( V_3 -> V_30 && V_3 -> V_30 -> V_214 )
V_3 -> V_30 -> V_214 ( V_109 , V_21 ,
V_21 + V_129 - 1 ,
NULL , 1 ) ;
F_94 ( V_109 ) ;
}
F_87 ( V_109 ) ;
V_21 += V_129 ;
}
F_218 ( & V_285 ) ;
return V_58 ;
}
int F_221 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
T_9 * V_250 ,
struct V_274 * V_275 )
{
int V_58 = 0 ;
struct V_284 V_285 = {
. V_152 = NULL ,
. V_3 = V_3 ,
. V_250 = V_250 ,
. V_296 = 0 ,
. V_309 = V_275 -> V_292 == V_293 ,
} ;
V_58 = F_213 ( V_3 , V_4 , V_275 ,
F_179 , & V_285 ,
F_191 ) ;
F_218 ( & V_285 ) ;
return V_58 ;
}
int F_222 ( struct V_2 * V_3 ,
struct V_26 * V_4 ,
struct V_333 * V_117 , unsigned V_118 ,
T_9 V_250 )
{
struct V_152 * V_152 = NULL ;
unsigned V_334 ;
unsigned long V_202 = 0 ;
struct V_109 * V_335 [ 16 ] ;
struct V_109 * V_109 ;
int V_119 = 0 ;
int V_243 = 0 ;
for ( V_334 = 0 ; V_334 < V_118 ; V_334 ++ ) {
V_109 = F_8 ( V_117 -> V_55 , struct V_109 , V_336 ) ;
F_149 ( & V_109 -> V_36 ) ;
F_11 ( & V_109 -> V_336 ) ;
if ( F_223 ( V_109 , V_4 ,
V_109 -> V_106 , V_105 ) ) {
F_87 ( V_109 ) ;
continue;
}
V_335 [ V_243 ++ ] = V_109 ;
if ( V_243 < F_224 ( V_335 ) )
continue;
for ( V_119 = 0 ; V_119 < V_243 ; V_119 ++ ) {
F_164 ( V_3 , V_335 [ V_119 ] , V_250 ,
& V_152 , 0 , & V_202 ) ;
F_87 ( V_335 [ V_119 ] ) ;
}
V_243 = 0 ;
}
for ( V_119 = 0 ; V_119 < V_243 ; V_119 ++ ) {
F_164 ( V_3 , V_335 [ V_119 ] , V_250 ,
& V_152 , 0 , & V_202 ) ;
F_87 ( V_335 [ V_119 ] ) ;
}
F_54 ( ! F_7 ( V_117 ) ) ;
if ( V_152 )
return F_152 ( V_273 , V_152 , 0 , V_202 ) ;
return 0 ;
}
int F_225 ( struct V_2 * V_3 ,
struct V_109 * V_109 , unsigned long V_44 )
{
struct V_8 * V_81 = NULL ;
T_3 V_21 = ( ( T_3 ) V_109 -> V_106 << V_107 ) ;
T_3 V_22 = V_21 + V_129 - 1 ;
T_6 V_261 = V_109 -> V_4 -> V_5 -> V_6 -> V_262 ;
V_21 += ( V_44 + V_261 - 1 ) & ~ ( V_261 - 1 ) ;
if ( V_21 > V_22 )
return 0 ;
F_79 ( V_3 , V_21 , V_22 , 0 , & V_81 ) ;
F_216 ( V_109 ) ;
F_51 ( V_3 , V_21 , V_22 ,
V_104 | V_77 | V_100 |
V_102 ,
1 , 1 , & V_81 , V_105 ) ;
return 0 ;
}
int F_226 ( struct V_196 * V_337 ,
struct V_2 * V_3 , struct V_109 * V_109 ,
T_2 V_34 )
{
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_22 = V_21 + V_129 - 1 ;
int V_58 = 1 ;
if ( F_99 ( V_3 , V_21 , V_22 ,
V_63 , 0 , NULL ) )
V_58 = 0 ;
else {
if ( ( V_34 & V_105 ) == V_105 )
V_34 = V_105 ;
V_58 = F_51 ( V_3 , V_21 , V_22 ,
~ ( V_104 | V_338 ) ,
0 , 0 , NULL , V_34 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
else
V_58 = 1 ;
}
return V_58 ;
}
int F_227 ( struct V_196 * V_337 ,
struct V_2 * V_3 , struct V_109 * V_109 ,
T_2 V_34 )
{
struct V_194 * V_195 ;
T_3 V_21 = ( T_3 ) V_109 -> V_106 << V_107 ;
T_3 V_22 = V_21 + V_129 - 1 ;
if ( ( V_34 & V_87 ) &&
V_109 -> V_4 -> V_5 -> V_286 > 16 * 1024 * 1024 ) {
T_3 V_25 ;
while ( V_21 <= V_22 ) {
V_25 = V_22 - V_21 + 1 ;
F_228 ( & V_337 -> V_32 ) ;
V_195 = F_140 ( V_337 , V_21 , V_25 ) ;
if ( ! V_195 ) {
F_229 ( & V_337 -> V_32 ) ;
break;
}
if ( F_127 ( V_339 , & V_195 -> V_36 ) ||
V_195 -> V_21 != V_21 ) {
F_229 ( & V_337 -> V_32 ) ;
F_142 ( V_195 ) ;
break;
}
if ( ! F_99 ( V_3 , V_195 -> V_21 ,
F_175 ( V_195 ) - 1 ,
V_104 | V_340 ,
0 , NULL ) ) {
F_230 ( V_337 , V_195 ) ;
F_142 ( V_195 ) ;
}
V_21 = F_175 ( V_195 ) ;
F_229 ( & V_337 -> V_32 ) ;
F_142 ( V_195 ) ;
}
}
return F_226 ( V_337 , V_3 , V_109 , V_34 ) ;
}
static struct V_194 * F_231 ( struct V_115 * V_115 ,
T_3 V_44 ,
T_3 V_141 ,
T_9 * V_250 )
{
T_3 V_341 = F_114 ( V_115 ) -> V_43 -> V_341 ;
struct V_194 * V_195 ;
T_3 V_25 ;
if ( V_44 >= V_141 )
return NULL ;
while( 1 ) {
V_25 = V_141 - V_44 ;
if ( V_25 == 0 )
break;
V_25 = ( V_25 + V_341 - 1 ) & ~ ( V_341 - 1 ) ;
V_195 = V_250 ( V_115 , NULL , 0 , V_44 , V_25 , 0 ) ;
if ( F_174 ( V_195 ) )
return V_195 ;
if ( ! F_127 ( V_342 , & V_195 -> V_36 ) &&
V_195 -> V_203 != V_269 ) {
return V_195 ;
}
V_44 = F_175 ( V_195 ) ;
F_142 ( V_195 ) ;
if ( V_44 >= V_141 )
break;
}
return NULL ;
}
int F_232 ( struct V_115 * V_115 , struct V_343 * V_344 ,
T_13 V_21 , T_13 V_25 , T_9 * V_250 )
{
int V_58 = 0 ;
T_3 V_345 = V_21 ;
T_3 F_106 = V_21 + V_25 ;
T_14 V_36 = 0 ;
T_14 V_346 ;
T_3 V_141 ;
T_3 V_347 = 0 ;
T_3 V_348 = 0 ;
T_3 V_349 = F_165 ( V_115 ) ;
struct V_350 V_351 ;
struct V_194 * V_195 = NULL ;
struct V_8 * V_81 = NULL ;
struct V_352 * V_353 ;
struct V_354 * V_355 ;
int V_22 = 0 ;
T_3 V_356 = 0 ;
T_3 V_357 = 0 ;
T_3 V_358 = 0 ;
unsigned long V_359 ;
if ( V_25 == 0 )
return - V_360 ;
V_353 = F_233 () ;
if ( ! V_353 )
return - V_11 ;
V_353 -> V_361 = 1 ;
V_21 = F_234 ( V_21 , F_114 ( V_115 ) -> V_43 -> V_341 ) ;
V_25 = F_234 ( V_25 , F_114 ( V_115 ) -> V_43 -> V_341 ) ;
V_58 = F_235 ( NULL , F_114 ( V_115 ) -> V_43 ,
V_353 , F_236 ( V_115 ) , - 1 , 0 ) ;
if ( V_58 < 0 ) {
F_237 ( V_353 ) ;
return V_58 ;
}
F_26 ( ! V_58 ) ;
V_353 -> V_362 [ 0 ] -- ;
V_355 = F_238 ( V_353 -> V_363 [ 0 ] , V_353 -> V_362 [ 0 ] ,
struct V_354 ) ;
F_239 ( V_353 -> V_363 [ 0 ] , & V_351 , V_353 -> V_362 [ 0 ] ) ;
V_346 = F_240 ( & V_351 ) ;
if ( V_351 . V_364 != F_236 ( V_115 ) ||
V_346 != V_365 ) {
V_141 = ( T_3 ) - 1 ;
V_347 = V_349 ;
} else {
V_141 = V_351 . V_44 ;
V_347 = V_141 + 1 ;
}
F_237 ( V_353 ) ;
if ( V_141 < V_349 ) {
V_141 = ( T_3 ) - 1 ;
V_347 = V_349 ;
}
F_79 ( & F_114 ( V_115 ) -> V_150 , V_21 , V_21 + V_25 , 0 ,
& V_81 ) ;
V_195 = F_231 ( V_115 , V_21 , V_347 ,
V_250 ) ;
if ( ! V_195 )
goto V_89;
if ( F_143 ( V_195 ) ) {
V_58 = F_241 ( V_195 ) ;
goto V_89;
}
while ( ! V_22 ) {
T_3 V_366 ;
if ( V_195 -> V_21 >= F_106 || F_175 ( V_195 ) < V_345 )
break;
V_356 = F_106 ( V_195 -> V_21 , V_345 ) ;
V_366 = V_356 - V_195 -> V_21 ;
V_358 = F_175 ( V_195 ) ;
V_357 = V_358 - V_356 ;
V_359 = V_195 -> V_36 ;
V_348 = 0 ;
V_36 = 0 ;
V_345 = F_175 ( V_195 ) ;
if ( V_345 >= F_106 )
V_22 = 1 ;
if ( V_195 -> V_203 == V_367 ) {
V_22 = 1 ;
V_36 |= V_368 ;
} else if ( V_195 -> V_203 == V_270 ) {
V_36 |= ( V_369 |
V_370 ) ;
} else if ( V_195 -> V_203 == V_371 ) {
V_36 |= ( V_372 |
V_373 ) ;
} else {
V_348 = V_195 -> V_203 + V_366 ;
}
if ( F_127 ( V_204 , & V_195 -> V_36 ) )
V_36 |= V_374 ;
F_142 ( V_195 ) ;
V_195 = NULL ;
if ( ( V_356 >= V_141 ) || V_357 == ( T_3 ) - 1 ||
( V_141 == ( T_3 ) - 1 && V_349 <= V_358 ) ) {
V_36 |= V_368 ;
V_22 = 1 ;
}
V_195 = F_231 ( V_115 , V_345 , V_347 ,
V_250 ) ;
if ( F_143 ( V_195 ) ) {
V_58 = F_241 ( V_195 ) ;
goto V_89;
}
if ( ! V_195 ) {
V_36 |= V_368 ;
V_22 = 1 ;
}
V_58 = F_242 ( V_344 , V_356 , V_348 ,
V_357 , V_36 ) ;
if ( V_58 )
goto V_375;
}
V_375:
F_142 ( V_195 ) ;
V_89:
F_82 ( & F_114 ( V_115 ) -> V_150 , V_21 , V_21 + V_25 ,
& V_81 , V_105 ) ;
return V_58 ;
}
inline struct V_109 * F_133 ( struct V_13 * V_16 ,
unsigned long V_119 )
{
return V_16 -> V_117 [ V_119 ] ;
}
inline unsigned long F_132 ( T_3 V_21 , T_3 V_25 )
{
return ( ( V_21 + V_25 + V_129 - 1 ) >> V_107 ) -
( V_21 >> V_107 ) ;
}
static void F_243 ( struct V_13 * V_16 )
{
#if V_35
unsigned long V_36 ;
F_18 ( & V_38 , V_36 ) ;
F_11 ( & V_16 -> V_19 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
if ( V_16 -> V_117 && V_16 -> V_117 != V_16 -> V_376 )
F_115 ( V_16 -> V_117 ) ;
F_12 ( V_12 , V_16 ) ;
}
static struct V_13 * F_244 ( struct V_2 * V_3 ,
T_3 V_21 ,
unsigned long V_25 ,
T_2 V_34 )
{
struct V_13 * V_16 = NULL ;
#if V_35
unsigned long V_36 ;
#endif
V_16 = F_245 ( V_12 , V_34 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_21 = V_21 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_3 = V_3 ;
V_16 -> V_306 = 0 ;
F_246 ( & V_16 -> V_32 ) ;
F_21 ( & V_16 -> V_377 , 0 ) ;
F_21 ( & V_16 -> V_378 , 0 ) ;
F_21 ( & V_16 -> V_379 , 0 ) ;
F_21 ( & V_16 -> V_380 , 0 ) ;
F_21 ( & V_16 -> V_381 , 0 ) ;
F_21 ( & V_16 -> V_382 , 0 ) ;
V_16 -> V_383 = 0 ;
F_22 ( & V_16 -> V_384 ) ;
F_22 ( & V_16 -> V_385 ) ;
#if V_35
F_18 ( & V_38 , V_36 ) ;
F_19 ( & V_16 -> V_19 , & V_24 ) ;
F_20 ( & V_38 , V_36 ) ;
#endif
F_15 ( & V_16 -> V_310 ) ;
F_21 ( & V_16 -> V_23 , 1 ) ;
F_21 ( & V_16 -> V_315 , 0 ) ;
if ( V_25 > V_386 ) {
struct V_109 * * V_117 ;
int V_186 = ( V_25 + V_129 - 1 ) >>
V_107 ;
V_117 = F_138 ( V_186 , V_34 ) ;
if ( ! V_117 ) {
F_243 ( V_16 ) ;
return NULL ;
}
V_16 -> V_117 = V_117 ;
} else {
V_16 -> V_117 = V_16 -> V_376 ;
}
return V_16 ;
}
struct V_13 * F_247 ( struct V_13 * V_387 )
{
unsigned long V_119 ;
struct V_109 * V_46 ;
struct V_13 * V_59 ;
unsigned long V_186 = F_132 ( V_387 -> V_21 , V_387 -> V_25 ) ;
V_59 = F_244 ( NULL , V_387 -> V_21 , V_387 -> V_25 , V_29 ) ;
if ( V_59 == NULL )
return NULL ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
V_46 = F_248 ( V_29 ) ;
F_54 ( ! V_46 ) ;
F_158 ( V_59 , V_46 ) ;
F_26 ( F_97 ( V_46 ) ) ;
F_110 ( V_46 ) ;
V_59 -> V_117 [ V_119 ] = V_46 ;
}
F_249 ( V_59 , V_387 , 0 , 0 , V_387 -> V_25 ) ;
F_195 ( V_388 , & V_59 -> V_306 ) ;
F_195 ( V_389 , & V_59 -> V_306 ) ;
return V_59 ;
}
struct V_13 * F_250 ( T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
unsigned long V_186 = F_132 ( 0 , V_25 ) ;
unsigned long V_119 ;
V_16 = F_244 ( NULL , V_21 , V_25 , V_29 ) ;
if ( ! V_16 )
return NULL ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
V_16 -> V_117 [ V_119 ] = F_248 ( V_29 ) ;
if ( ! V_16 -> V_117 [ V_119 ] )
goto V_79;
}
F_251 ( V_16 ) ;
F_252 ( V_16 , 0 ) ;
F_195 ( V_389 , & V_16 -> V_306 ) ;
return V_16 ;
V_79:
for ( V_119 -- ; V_119 > 0 ; V_119 -- )
F_253 ( V_16 -> V_117 [ V_119 ] ) ;
F_243 ( V_16 ) ;
return NULL ;
}
static int F_254 ( struct V_13 * V_16 )
{
return ( F_10 ( & V_16 -> V_315 ) ||
F_127 ( V_307 , & V_16 -> V_306 ) ||
F_127 ( V_311 , & V_16 -> V_306 ) ) ;
}
static void F_255 ( struct V_13 * V_16 ,
unsigned long V_390 )
{
unsigned long V_106 ;
unsigned long V_186 ;
struct V_109 * V_109 ;
int V_391 = ! F_127 ( V_389 , & V_16 -> V_306 ) ;
F_54 ( F_254 ( V_16 ) ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
V_106 = V_390 + V_186 ;
if ( V_390 >= V_106 )
return;
do {
V_106 -- ;
V_109 = F_133 ( V_16 , V_106 ) ;
if ( V_109 && V_391 ) {
F_52 ( & V_109 -> V_4 -> V_392 ) ;
if ( F_159 ( V_109 ) &&
V_109 -> V_37 == ( unsigned long ) V_16 ) {
F_54 ( F_127 ( V_311 , & V_16 -> V_306 ) ) ;
F_54 ( F_97 ( V_109 ) ) ;
F_54 ( F_184 ( V_109 ) ) ;
F_256 ( V_109 ) ;
F_162 ( V_109 , 0 ) ;
F_87 ( V_109 ) ;
}
F_56 ( & V_109 -> V_4 -> V_392 ) ;
}
if ( V_109 ) {
F_87 ( V_109 ) ;
}
} while ( V_106 != V_390 );
}
static inline void F_257 ( struct V_13 * V_16 )
{
F_255 ( V_16 , 0 ) ;
F_243 ( V_16 ) ;
}
static void F_258 ( struct V_13 * V_16 )
{
F_52 ( & V_16 -> V_310 ) ;
if ( ! F_259 ( V_393 , & V_16 -> V_306 ) )
F_64 ( & V_16 -> V_23 ) ;
F_56 ( & V_16 -> V_310 ) ;
}
static void F_260 ( struct V_13 * V_16 )
{
unsigned long V_186 , V_119 ;
F_258 ( V_16 ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
struct V_109 * V_46 = F_133 ( V_16 , V_119 ) ;
F_261 ( V_46 ) ;
}
}
struct V_13 * F_262 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
unsigned long V_186 = F_132 ( V_21 , V_25 ) ;
unsigned long V_119 ;
unsigned long V_106 = V_21 >> V_107 ;
struct V_13 * V_16 ;
struct V_13 * V_394 = NULL ;
struct V_109 * V_46 ;
struct V_26 * V_4 = V_3 -> V_4 ;
int V_213 = 1 ;
int V_58 ;
F_263 () ;
V_16 = F_264 ( & V_3 -> V_28 , V_21 >> V_107 ) ;
if ( V_16 && F_210 ( & V_16 -> V_23 ) ) {
F_265 () ;
F_260 ( V_16 ) ;
return V_16 ;
}
F_265 () ;
V_16 = F_244 ( V_3 , V_21 , V_25 , V_105 ) ;
if ( ! V_16 )
return NULL ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ , V_106 ++ ) {
V_46 = F_266 ( V_4 , V_106 , V_105 ) ;
if ( ! V_46 ) {
F_26 ( 1 ) ;
goto V_395;
}
F_52 ( & V_4 -> V_392 ) ;
if ( F_159 ( V_46 ) ) {
V_394 = (struct V_13 * ) V_46 -> V_37 ;
if ( F_210 ( & V_394 -> V_23 ) ) {
F_56 ( & V_4 -> V_392 ) ;
F_94 ( V_46 ) ;
F_87 ( V_46 ) ;
F_260 ( V_394 ) ;
goto V_395;
}
F_256 ( V_46 ) ;
F_26 ( F_97 ( V_46 ) ) ;
F_87 ( V_46 ) ;
}
F_158 ( V_16 , V_46 ) ;
F_56 ( & V_4 -> V_392 ) ;
F_26 ( F_97 ( V_46 ) ) ;
F_261 ( V_46 ) ;
V_16 -> V_117 [ V_119 ] = V_46 ;
if ( ! F_166 ( V_46 ) )
V_213 = 0 ;
}
if ( V_213 )
F_195 ( V_388 , & V_16 -> V_306 ) ;
V_86:
V_58 = F_267 ( V_105 & ~ V_396 ) ;
if ( V_58 )
goto V_395;
F_52 ( & V_3 -> V_33 ) ;
V_58 = F_268 ( & V_3 -> V_28 , V_21 >> V_107 , V_16 ) ;
if ( V_58 == - V_69 ) {
V_394 = F_264 ( & V_3 -> V_28 ,
V_21 >> V_107 ) ;
if ( ! F_210 ( & V_394 -> V_23 ) ) {
F_56 ( & V_3 -> V_33 ) ;
F_269 () ;
V_394 = NULL ;
goto V_86;
}
F_56 ( & V_3 -> V_33 ) ;
F_269 () ;
F_260 ( V_394 ) ;
goto V_395;
}
F_258 ( V_16 ) ;
F_56 ( & V_3 -> V_33 ) ;
F_269 () ;
F_270 ( V_16 -> V_117 [ 0 ] ) ;
for ( V_119 = 1 ; V_119 < V_186 ; V_119 ++ ) {
V_46 = F_133 ( V_16 , V_119 ) ;
F_271 ( V_46 ) ;
F_94 ( V_46 ) ;
}
F_94 ( V_16 -> V_117 [ 0 ] ) ;
return V_16 ;
V_395:
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
if ( V_16 -> V_117 [ V_119 ] )
F_94 ( V_16 -> V_117 [ V_119 ] ) ;
}
F_26 ( ! F_25 ( & V_16 -> V_23 ) ) ;
F_257 ( V_16 ) ;
return V_394 ;
}
struct V_13 * F_272 ( struct V_2 * V_3 ,
T_3 V_21 , unsigned long V_25 )
{
struct V_13 * V_16 ;
F_263 () ;
V_16 = F_264 ( & V_3 -> V_28 , V_21 >> V_107 ) ;
if ( V_16 && F_210 ( & V_16 -> V_23 ) ) {
F_265 () ;
F_260 ( V_16 ) ;
return V_16 ;
}
F_265 () ;
return NULL ;
}
static inline void F_273 ( struct V_397 * V_398 )
{
struct V_13 * V_16 =
F_274 ( V_398 , struct V_13 , V_397 ) ;
F_243 ( V_16 ) ;
}
static int F_275 ( struct V_13 * V_16 , T_2 V_34 )
{
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
if ( F_25 ( & V_16 -> V_23 ) ) {
if ( F_127 ( V_389 , & V_16 -> V_306 ) ) {
F_56 ( & V_16 -> V_310 ) ;
} else {
struct V_2 * V_3 = V_16 -> V_3 ;
F_56 ( & V_16 -> V_310 ) ;
F_52 ( & V_3 -> V_33 ) ;
F_276 ( & V_3 -> V_28 ,
V_16 -> V_21 >> V_107 ) ;
F_56 ( & V_3 -> V_33 ) ;
}
F_255 ( V_16 , 0 ) ;
F_277 ( & V_16 -> V_397 , F_273 ) ;
return 1 ;
}
F_56 ( & V_16 -> V_310 ) ;
return 0 ;
}
void F_211 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_52 ( & V_16 -> V_310 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_127 ( V_389 , & V_16 -> V_306 ) )
F_53 ( & V_16 -> V_23 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 &&
F_127 ( V_399 , & V_16 -> V_306 ) &&
! F_254 ( V_16 ) &&
F_194 ( V_393 , & V_16 -> V_306 ) )
F_53 ( & V_16 -> V_23 ) ;
F_275 ( V_16 , V_29 ) ;
}
void F_278 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
F_52 ( & V_16 -> V_310 ) ;
F_195 ( V_399 , & V_16 -> V_306 ) ;
if ( F_10 ( & V_16 -> V_23 ) == 2 && ! F_254 ( V_16 ) &&
F_194 ( V_393 , & V_16 -> V_306 ) )
F_53 ( & V_16 -> V_23 ) ;
F_275 ( V_16 , V_105 ) ;
}
void F_279 ( struct V_13 * V_16 )
{
unsigned long V_119 ;
unsigned long V_186 ;
struct V_109 * V_109 ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
if ( ! F_97 ( V_109 ) )
continue;
F_96 ( V_109 ) ;
F_26 ( ! F_159 ( V_109 ) ) ;
F_102 ( V_109 ) ;
F_280 ( & V_109 -> V_4 -> V_400 ) ;
if ( ! F_97 ( V_109 ) ) {
F_281 ( & V_109 -> V_4 -> V_401 ,
F_282 ( V_109 ) ,
V_324 ) ;
}
F_283 ( & V_109 -> V_4 -> V_400 ) ;
F_182 ( V_109 ) ;
F_94 ( V_109 ) ;
}
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
}
int F_284 ( struct V_13 * V_16 )
{
unsigned long V_119 ;
unsigned long V_186 ;
int V_402 = 0 ;
F_258 ( V_16 ) ;
V_402 = F_259 ( V_311 , & V_16 -> V_306 ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
F_26 ( F_10 ( & V_16 -> V_23 ) == 0 ) ;
F_26 ( ! F_127 ( V_393 , & V_16 -> V_306 ) ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ )
F_285 ( F_133 ( V_16 , V_119 ) ) ;
return V_402 ;
}
static int F_286 ( T_3 V_21 , T_3 V_25 )
{
if ( V_25 < V_129 )
return 1 ;
if ( V_21 & ( V_129 - 1 ) )
return 1 ;
if ( ( V_21 + V_25 ) & ( V_129 - 1 ) )
return 1 ;
return 0 ;
}
int F_287 ( struct V_13 * V_16 )
{
unsigned long V_119 ;
struct V_109 * V_109 ;
unsigned long V_186 ;
F_199 ( V_388 , & V_16 -> V_306 ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
if ( V_109 )
F_146 ( V_109 ) ;
}
return 0 ;
}
int F_251 ( struct V_13 * V_16 )
{
unsigned long V_119 ;
struct V_109 * V_109 ;
unsigned long V_186 ;
F_195 ( V_388 , & V_16 -> V_306 ) ;
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = 0 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
F_110 ( V_109 ) ;
}
return 0 ;
}
int F_288 ( struct V_2 * V_3 ,
T_3 V_21 , T_3 V_22 )
{
struct V_109 * V_109 ;
int V_58 ;
int V_403 = 1 ;
int V_213 ;
unsigned long V_106 ;
if ( F_286 ( V_21 , V_22 - V_21 + 1 ) ) {
V_58 = F_99 ( V_3 , V_21 , V_22 ,
V_101 , 1 , NULL ) ;
if ( V_58 )
return 1 ;
}
while ( V_21 <= V_22 ) {
V_106 = V_21 >> V_107 ;
V_109 = F_85 ( V_3 -> V_4 , V_106 ) ;
if ( ! V_109 )
return 1 ;
V_213 = F_166 ( V_109 ) ;
F_87 ( V_109 ) ;
if ( ! V_213 ) {
V_403 = 0 ;
break;
}
V_21 += V_129 ;
}
return V_403 ;
}
int F_289 ( struct V_13 * V_16 )
{
return F_127 ( V_388 , & V_16 -> V_306 ) ;
}
int F_290 ( struct V_2 * V_3 ,
struct V_13 * V_16 , T_3 V_21 , int V_91 ,
T_9 * V_250 , int V_158 )
{
unsigned long V_119 ;
unsigned long V_404 ;
struct V_109 * V_109 ;
int V_79 ;
int V_58 = 0 ;
int V_405 = 0 ;
int V_406 = 1 ;
unsigned long V_186 ;
unsigned long V_407 = 0 ;
struct V_152 * V_152 = NULL ;
unsigned long V_202 = 0 ;
if ( F_127 ( V_388 , & V_16 -> V_306 ) )
return 0 ;
if ( V_21 ) {
F_26 ( V_21 < V_16 -> V_21 ) ;
V_404 = ( V_21 >> V_107 ) -
( V_16 -> V_21 >> V_107 ) ;
} else {
V_404 = 0 ;
}
V_186 = F_132 ( V_16 -> V_21 , V_16 -> V_25 ) ;
for ( V_119 = V_404 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
if ( V_91 == V_408 ) {
if ( ! F_197 ( V_109 ) )
goto V_409;
} else {
F_96 ( V_109 ) ;
}
V_405 ++ ;
if ( ! F_166 ( V_109 ) ) {
V_407 ++ ;
V_406 = 0 ;
}
}
if ( V_406 ) {
if ( V_404 == 0 )
F_195 ( V_388 , & V_16 -> V_306 ) ;
goto V_409;
}
F_199 ( V_316 , & V_16 -> V_306 ) ;
V_16 -> V_410 = 0 ;
F_21 ( & V_16 -> V_315 , V_407 ) ;
for ( V_119 = V_404 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
if ( ! F_166 ( V_109 ) ) {
F_182 ( V_109 ) ;
V_79 = F_164 ( V_3 , V_109 ,
V_250 , & V_152 ,
V_158 , & V_202 ) ;
if ( V_79 )
V_58 = V_79 ;
} else {
F_94 ( V_109 ) ;
}
}
if ( V_152 ) {
V_79 = F_152 ( V_273 , V_152 , V_158 , V_202 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_58 || V_91 != V_411 )
return V_58 ;
for ( V_119 = V_404 ; V_119 < V_186 ; V_119 ++ ) {
V_109 = F_133 ( V_16 , V_119 ) ;
F_291 ( V_109 ) ;
if ( ! F_166 ( V_109 ) )
V_58 = - V_166 ;
}
return V_58 ;
V_409:
V_119 = V_404 ;
while ( V_405 > 0 ) {
V_109 = F_133 ( V_16 , V_119 ) ;
V_119 ++ ;
F_94 ( V_109 ) ;
V_405 -- ;
}
return V_58 ;
}
void F_292 ( struct V_13 * V_16 , void * V_412 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_44 ;
struct V_109 * V_109 ;
char * V_413 ;
char * V_414 = ( char * ) V_412 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_21 ) >> V_107 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_129 - 1 ) ;
while ( V_25 > 0 ) {
V_109 = F_133 ( V_16 , V_119 ) ;
V_252 = F_105 ( V_25 , ( V_129 - V_44 ) ) ;
V_413 = F_293 ( V_109 ) ;
memcpy ( V_414 , V_413 + V_44 , V_252 ) ;
V_414 += V_252 ;
V_25 -= V_252 ;
V_44 = 0 ;
V_119 ++ ;
}
}
int F_294 ( struct V_13 * V_16 , unsigned long V_21 ,
unsigned long V_416 , char * * V_337 ,
unsigned long * V_417 ,
unsigned long * V_418 )
{
T_6 V_44 = V_21 & ( V_129 - 1 ) ;
char * V_413 ;
struct V_109 * V_46 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_21 ) >> V_107 ;
unsigned long V_419 = ( V_415 + V_21 + V_416 - 1 ) >>
V_107 ;
if ( V_119 != V_419 )
return - V_360 ;
if ( V_119 == 0 ) {
V_44 = V_415 ;
* V_417 = 0 ;
} else {
V_44 = 0 ;
* V_417 = ( ( T_3 ) V_119 << V_107 ) - V_415 ;
}
if ( V_21 + V_416 > V_16 -> V_25 ) {
F_9 ( V_20 L_31
L_32 , ( unsigned long long ) V_16 -> V_21 ,
V_16 -> V_25 , V_21 , V_416 ) ;
F_26 ( 1 ) ;
return - V_360 ;
}
V_46 = F_133 ( V_16 , V_119 ) ;
V_413 = F_293 ( V_46 ) ;
* V_337 = V_413 + V_44 ;
* V_418 = V_129 - V_44 ;
return 0 ;
}
int F_295 ( struct V_13 * V_16 , const void * V_420 ,
unsigned long V_21 ,
unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_44 ;
struct V_109 * V_109 ;
char * V_413 ;
char * V_421 = ( char * ) V_420 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_21 ) >> V_107 ;
int V_58 = 0 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_129 - 1 ) ;
while ( V_25 > 0 ) {
V_109 = F_133 ( V_16 , V_119 ) ;
V_252 = F_105 ( V_25 , ( V_129 - V_44 ) ) ;
V_413 = F_293 ( V_109 ) ;
V_58 = memcmp ( V_421 , V_413 + V_44 , V_252 ) ;
if ( V_58 )
break;
V_421 += V_252 ;
V_25 -= V_252 ;
V_44 = 0 ;
V_119 ++ ;
}
return V_58 ;
}
void F_296 ( struct V_13 * V_16 , const void * V_422 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_44 ;
struct V_109 * V_109 ;
char * V_413 ;
char * V_387 = ( char * ) V_422 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_21 ) >> V_107 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_129 - 1 ) ;
while ( V_25 > 0 ) {
V_109 = F_133 ( V_16 , V_119 ) ;
F_26 ( ! F_166 ( V_109 ) ) ;
V_252 = F_105 ( V_25 , V_129 - V_44 ) ;
V_413 = F_293 ( V_109 ) ;
memcpy ( V_413 + V_44 , V_387 , V_252 ) ;
V_387 += V_252 ;
V_25 -= V_252 ;
V_44 = 0 ;
V_119 ++ ;
}
}
void F_297 ( struct V_13 * V_16 , char V_423 ,
unsigned long V_21 , unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_44 ;
struct V_109 * V_109 ;
char * V_413 ;
T_6 V_415 = V_16 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_21 ) >> V_107 ;
F_26 ( V_21 > V_16 -> V_25 ) ;
F_26 ( V_21 + V_25 > V_16 -> V_21 + V_16 -> V_25 ) ;
V_44 = ( V_415 + V_21 ) & ( ( unsigned long ) V_129 - 1 ) ;
while ( V_25 > 0 ) {
V_109 = F_133 ( V_16 , V_119 ) ;
F_26 ( ! F_166 ( V_109 ) ) ;
V_252 = F_105 ( V_25 , V_129 - V_44 ) ;
V_413 = F_293 ( V_109 ) ;
memset ( V_413 + V_44 , V_423 , V_252 ) ;
V_25 -= V_252 ;
V_44 = 0 ;
V_119 ++ ;
}
}
void F_249 ( struct V_13 * V_414 , struct V_13 * V_387 ,
unsigned long V_424 , unsigned long V_425 ,
unsigned long V_25 )
{
T_3 V_426 = V_414 -> V_25 ;
T_6 V_252 ;
T_6 V_44 ;
struct V_109 * V_109 ;
char * V_413 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_119 = ( V_415 + V_424 ) >> V_107 ;
F_26 ( V_387 -> V_25 != V_426 ) ;
V_44 = ( V_415 + V_424 ) &
( ( unsigned long ) V_129 - 1 ) ;
while ( V_25 > 0 ) {
V_109 = F_133 ( V_414 , V_119 ) ;
F_26 ( ! F_166 ( V_109 ) ) ;
V_252 = F_105 ( V_25 , ( unsigned long ) ( V_129 - V_44 ) ) ;
V_413 = F_293 ( V_109 ) ;
F_292 ( V_387 , V_413 + V_44 , V_425 , V_252 ) ;
V_425 += V_252 ;
V_25 -= V_252 ;
V_44 = 0 ;
V_119 ++ ;
}
}
static void F_298 ( struct V_109 * V_427 , struct V_109 * V_428 ,
unsigned long V_429 , unsigned long V_430 ,
unsigned long V_25 )
{
char * V_431 = F_293 ( V_427 ) ;
if ( V_427 == V_428 ) {
memmove ( V_431 + V_429 , V_431 + V_430 , V_25 ) ;
} else {
char * V_432 = F_293 ( V_428 ) ;
char * V_46 = V_431 + V_429 + V_25 ;
char * V_433 = V_432 + V_430 + V_25 ;
while ( V_25 -- )
* -- V_46 = * -- V_433 ;
}
}
static inline bool F_299 ( unsigned long V_387 , unsigned long V_414 , unsigned long V_25 )
{
unsigned long V_434 = ( V_387 > V_414 ) ? V_387 - V_414 : V_414 - V_387 ;
return V_434 < V_25 ;
}
static void F_300 ( struct V_109 * V_427 , struct V_109 * V_428 ,
unsigned long V_429 , unsigned long V_430 ,
unsigned long V_25 )
{
char * V_431 = F_293 ( V_427 ) ;
char * V_432 ;
int V_435 = 0 ;
if ( V_427 != V_428 ) {
V_432 = F_293 ( V_428 ) ;
} else {
V_432 = V_431 ;
if ( F_299 ( V_430 , V_429 , V_25 ) )
V_435 = 1 ;
}
if ( V_435 )
memmove ( V_431 + V_429 , V_432 + V_430 , V_25 ) ;
else
memcpy ( V_431 + V_429 , V_432 + V_430 , V_25 ) ;
}
void F_301 ( struct V_13 * V_414 , unsigned long V_424 ,
unsigned long V_425 , unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_436 ;
T_6 V_437 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_438 ;
unsigned long V_439 ;
if ( V_425 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_33
L_34 , V_425 , V_25 , V_414 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_424 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_35
L_34 , V_424 , V_25 , V_414 -> V_25 ) ;
F_54 ( 1 ) ;
}
while ( V_25 > 0 ) {
V_436 = ( V_415 + V_424 ) &
( ( unsigned long ) V_129 - 1 ) ;
V_437 = ( V_415 + V_425 ) &
( ( unsigned long ) V_129 - 1 ) ;
V_438 = ( V_415 + V_424 ) >> V_107 ;
V_439 = ( V_415 + V_425 ) >> V_107 ;
V_252 = F_105 ( V_25 , ( unsigned long ) ( V_129 -
V_437 ) ) ;
V_252 = F_93 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_300 ( F_133 ( V_414 , V_438 ) ,
F_133 ( V_414 , V_439 ) ,
V_436 , V_437 , V_252 ) ;
V_425 += V_252 ;
V_424 += V_252 ;
V_25 -= V_252 ;
}
}
void F_302 ( struct V_13 * V_414 , unsigned long V_424 ,
unsigned long V_425 , unsigned long V_25 )
{
T_6 V_252 ;
T_6 V_436 ;
T_6 V_437 ;
unsigned long V_440 = V_424 + V_25 - 1 ;
unsigned long V_441 = V_425 + V_25 - 1 ;
T_6 V_415 = V_414 -> V_21 & ( ( T_3 ) V_129 - 1 ) ;
unsigned long V_438 ;
unsigned long V_439 ;
if ( V_425 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_33
L_36 , V_425 , V_25 , V_414 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_424 + V_25 > V_414 -> V_25 ) {
F_9 ( V_20 L_35
L_36 , V_424 , V_25 , V_414 -> V_25 ) ;
F_54 ( 1 ) ;
}
if ( V_424 < V_425 ) {
F_301 ( V_414 , V_424 , V_425 , V_25 ) ;
return;
}
while ( V_25 > 0 ) {
V_438 = ( V_415 + V_440 ) >> V_107 ;
V_439 = ( V_415 + V_441 ) >> V_107 ;
V_436 = ( V_415 + V_440 ) &
( ( unsigned long ) V_129 - 1 ) ;
V_437 = ( V_415 + V_441 ) &
( ( unsigned long ) V_129 - 1 ) ;
V_252 = F_93 (unsigned long, len, src_off_in_page + 1 ) ;
V_252 = F_105 ( V_252 , V_436 + 1 ) ;
F_298 ( F_133 ( V_414 , V_438 ) ,
F_133 ( V_414 , V_439 ) ,
V_436 - V_252 + 1 ,
V_437 - V_252 + 1 , V_252 ) ;
V_440 -= V_252 ;
V_441 -= V_252 ;
V_25 -= V_252 ;
}
}
int F_303 ( struct V_109 * V_109 , T_2 V_34 )
{
struct V_13 * V_16 ;
F_52 ( & V_109 -> V_4 -> V_392 ) ;
if ( ! F_159 ( V_109 ) ) {
F_56 ( & V_109 -> V_4 -> V_392 ) ;
return 1 ;
}
V_16 = (struct V_13 * ) V_109 -> V_37 ;
F_54 ( ! V_16 ) ;
F_52 ( & V_16 -> V_310 ) ;
if ( F_10 ( & V_16 -> V_23 ) != 1 || F_254 ( V_16 ) ) {
F_56 ( & V_16 -> V_310 ) ;
F_56 ( & V_109 -> V_4 -> V_392 ) ;
return 0 ;
}
F_56 ( & V_109 -> V_4 -> V_392 ) ;
if ( ( V_34 & V_105 ) == V_105 )
V_34 = V_105 ;
if ( ! F_194 ( V_393 , & V_16 -> V_306 ) ) {
F_56 ( & V_16 -> V_310 ) ;
return 0 ;
}
return F_275 ( V_16 , V_34 ) ;
}
