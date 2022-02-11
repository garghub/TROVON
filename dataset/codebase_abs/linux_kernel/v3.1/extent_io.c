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
static void F_33 ( struct V_21 * V_17 ,
struct V_2 * V_9 )
{
struct V_2 * V_56 ;
struct V_37 * V_59 ;
if ( V_9 -> V_9 & ( V_60 | V_61 ) )
return;
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
V_9 -> V_16 = V_56 -> V_16 ;
V_56 -> V_17 = NULL ;
F_34 ( & V_56 -> V_37 , & V_17 -> V_9 ) ;
F_21 ( V_56 ) ;
}
}
}
static void F_35 ( struct V_21 * V_17 ,
struct V_2 * V_9 , int * V_62 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_63 )
V_17 -> V_27 -> V_63 ( V_17 -> V_23 -> V_58 , V_9 , V_62 ) ;
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
if ( V_16 < V_15 ) {
F_7 ( V_14 L_7 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_15 ) ;
F_23 ( 1 ) ;
}
V_9 -> V_15 = V_15 ;
V_9 -> V_16 = V_16 ;
F_38 ( V_17 , V_9 , V_62 ) ;
V_41 = F_24 ( & V_17 -> V_9 , V_16 , & V_9 -> V_37 ) ;
if ( V_41 ) {
struct V_2 * V_65 ;
V_65 = F_25 ( V_41 , struct V_2 , V_37 ) ;
F_7 ( V_14 L_8
L_9 , ( unsigned long long ) V_65 -> V_15 ,
( unsigned long long ) V_65 -> V_16 ,
( unsigned long long ) V_15 , ( unsigned long long ) V_16 ) ;
return - V_66 ;
}
V_9 -> V_17 = V_17 ;
F_33 ( V_17 , V_9 ) ;
return 0 ;
}
static void F_39 ( struct V_21 * V_17 , struct V_2 * V_67 ,
T_3 V_68 )
{
if ( V_17 -> V_27 && V_17 -> V_27 -> V_69 )
V_17 -> V_27 -> V_69 ( V_17 -> V_23 -> V_58 , V_67 , V_68 ) ;
}
static int F_40 ( struct V_21 * V_17 , struct V_2 * V_67 ,
struct V_2 * V_70 , T_3 V_68 )
{
struct V_37 * V_41 ;
F_39 ( V_17 , V_67 , V_68 ) ;
V_70 -> V_15 = V_67 -> V_15 ;
V_70 -> V_16 = V_68 - 1 ;
V_70 -> V_9 = V_67 -> V_9 ;
V_67 -> V_15 = V_68 ;
V_41 = F_24 ( & V_17 -> V_9 , V_70 -> V_16 , & V_70 -> V_37 ) ;
if ( V_41 ) {
F_21 ( V_70 ) ;
return - V_66 ;
}
V_70 -> V_17 = V_17 ;
return 0 ;
}
static int F_41 ( struct V_21 * V_17 ,
struct V_2 * V_9 ,
int * V_62 , int V_71 )
{
int V_72 = * V_62 & ~ V_73 ;
int V_54 = V_9 -> V_9 & V_72 ;
if ( ( V_72 & V_74 ) && ( V_9 -> V_9 & V_74 ) ) {
T_3 V_75 = V_9 -> V_16 - V_9 -> V_15 + 1 ;
F_23 ( V_75 > V_17 -> V_28 ) ;
V_17 -> V_28 -= V_75 ;
}
F_36 ( V_17 , V_9 , V_62 ) ;
V_9 -> V_9 &= ~ V_72 ;
if ( V_71 )
F_42 ( & V_9 -> V_36 ) ;
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
F_43 ( struct V_2 * V_70 )
{
if ( ! V_70 )
V_70 = F_14 ( V_26 ) ;
return V_70 ;
}
int F_44 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_71 , int V_76 ,
struct V_2 * * V_77 ,
T_2 V_31 )
{
struct V_2 * V_9 ;
struct V_2 * V_78 ;
struct V_2 * V_70 = NULL ;
struct V_37 * V_79 ;
struct V_37 * V_41 ;
T_3 V_80 ;
int V_81 ;
int V_82 = 0 ;
int V_83 = 0 ;
if ( V_76 )
V_62 |= ~ V_73 ;
V_62 |= V_84 ;
if ( V_62 & ( V_60 | V_61 ) )
V_83 = 1 ;
V_85:
if ( ! V_70 && ( V_31 & V_86 ) ) {
V_70 = F_14 ( V_31 ) ;
if ( ! V_70 )
return - V_5 ;
}
F_45 ( & V_17 -> V_29 ) ;
if ( V_77 ) {
V_78 = * V_77 ;
if ( V_83 ) {
* V_77 = NULL ;
V_77 = NULL ;
}
if ( V_78 && V_78 -> V_17 && V_78 -> V_15 <= V_15 &&
V_78 -> V_16 > V_15 ) {
if ( V_83 )
F_46 ( & V_78 -> V_18 ) ;
V_9 = V_78 ;
goto V_87;
}
if ( V_83 )
F_21 ( V_78 ) ;
}
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
goto V_88;
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
V_87:
if ( V_9 -> V_15 > V_16 )
goto V_88;
F_23 ( V_9 -> V_16 < V_15 ) ;
V_80 = V_9 -> V_16 ;
if ( V_9 -> V_15 < V_15 ) {
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_15 ) ;
F_47 ( V_81 == - V_66 ) ;
V_70 = NULL ;
if ( V_81 )
goto V_88;
if ( V_9 -> V_16 <= V_16 ) {
V_82 |= F_41 ( V_17 , V_9 , & V_62 , V_71 ) ;
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
}
goto V_89;
}
if ( V_9 -> V_15 <= V_16 && V_9 -> V_16 > V_16 ) {
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_16 + 1 ) ;
F_47 ( V_81 == - V_66 ) ;
if ( V_71 )
F_42 ( & V_9 -> V_36 ) ;
V_82 |= F_41 ( V_17 , V_70 , & V_62 , V_71 ) ;
V_70 = NULL ;
goto V_88;
}
if ( V_9 -> V_16 < V_16 && V_70 && ! F_48 () )
V_79 = F_29 ( & V_9 -> V_37 ) ;
else
V_79 = NULL ;
V_82 |= F_41 ( V_17 , V_9 , & V_62 , V_71 ) ;
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
if ( V_15 <= V_16 && V_79 ) {
V_9 = F_25 ( V_79 , struct V_2 ,
V_37 ) ;
if ( V_9 -> V_15 == V_15 )
goto V_87;
}
goto V_89;
V_88:
F_49 ( & V_17 -> V_29 ) ;
if ( V_70 )
F_21 ( V_70 ) ;
return V_82 ;
V_89:
if ( V_15 > V_16 )
goto V_88;
F_49 ( & V_17 -> V_29 ) ;
if ( V_31 & V_86 )
F_50 () ;
goto V_85;
}
static int F_51 ( struct V_21 * V_17 ,
struct V_2 * V_9 )
__releases( V_17 -> V_29 )
__acquires( V_17 -> V_29 )
{
F_52 ( V_90 ) ;
F_53 ( & V_9 -> V_36 , & V_90 , V_91 ) ;
F_49 ( & V_17 -> V_29 ) ;
F_54 () ;
F_45 ( & V_17 -> V_29 ) ;
F_55 ( & V_9 -> V_36 , & V_90 ) ;
return 0 ;
}
int F_56 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , int V_62 )
{
struct V_2 * V_9 ;
struct V_37 * V_41 ;
F_45 ( & V_17 -> V_29 ) ;
V_85:
while ( 1 ) {
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
break;
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 > V_16 )
goto V_88;
if ( V_9 -> V_9 & V_62 ) {
V_15 = V_9 -> V_15 ;
F_57 ( & V_9 -> V_18 ) ;
F_51 ( V_17 , V_9 ) ;
F_21 ( V_9 ) ;
goto V_85;
}
V_15 = V_9 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
F_58 ( & V_17 -> V_29 ) ;
}
V_88:
F_49 ( & V_17 -> V_29 ) ;
return 0 ;
}
static void F_38 ( struct V_21 * V_17 ,
struct V_2 * V_9 ,
int * V_62 )
{
int V_92 = * V_62 & ~ V_73 ;
F_35 ( V_17 , V_9 , V_62 ) ;
if ( ( V_92 & V_74 ) && ! ( V_9 -> V_9 & V_74 ) ) {
T_3 V_75 = V_9 -> V_16 - V_9 -> V_15 + 1 ;
V_17 -> V_28 += V_75 ;
}
V_9 -> V_9 |= V_92 ;
}
static void F_59 ( struct V_2 * V_9 ,
struct V_2 * * V_93 )
{
if ( V_93 && ! ( * V_93 ) ) {
if ( V_9 -> V_9 & ( V_60 | V_61 ) ) {
* V_93 = V_9 ;
F_57 ( & V_9 -> V_18 ) ;
}
}
}
static void F_60 ( struct V_2 * * V_93 )
{
if ( V_93 && ( * V_93 ) ) {
struct V_2 * V_9 = * V_93 ;
* V_93 = NULL ;
F_21 ( V_9 ) ;
}
}
int F_61 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_94 , T_3 * V_95 ,
struct V_2 * * V_77 , T_2 V_31 )
{
struct V_2 * V_9 ;
struct V_2 * V_70 = NULL ;
struct V_37 * V_41 ;
int V_81 = 0 ;
T_3 V_96 ;
T_3 V_80 ;
V_62 |= V_84 ;
V_85:
if ( ! V_70 && ( V_31 & V_86 ) ) {
V_70 = F_14 ( V_31 ) ;
F_47 ( ! V_70 ) ;
}
F_45 ( & V_17 -> V_29 ) ;
if ( V_77 && * V_77 ) {
V_9 = * V_77 ;
if ( V_9 -> V_15 <= V_15 && V_9 -> V_16 > V_15 &&
V_9 -> V_17 ) {
V_41 = & V_9 -> V_37 ;
goto V_87;
}
}
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_37 ( V_17 , V_70 , V_15 , V_16 , & V_62 ) ;
V_70 = NULL ;
F_47 ( V_81 == - V_66 ) ;
goto V_88;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
V_87:
V_96 = V_9 -> V_15 ;
V_80 = V_9 -> V_16 ;
if ( V_9 -> V_15 == V_15 && V_9 -> V_16 <= V_16 ) {
struct V_37 * V_79 ;
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_9 -> V_15 ;
V_81 = - V_66 ;
goto V_88;
}
F_38 ( V_17 , V_9 , & V_62 ) ;
F_59 ( V_9 , V_77 ) ;
F_33 ( V_17 , V_9 ) ;
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
V_79 = F_29 ( & V_9 -> V_37 ) ;
if ( V_79 && V_15 < V_16 && V_70 && ! F_48 () ) {
V_9 = F_25 ( V_79 , struct V_2 ,
V_37 ) ;
if ( V_9 -> V_15 == V_15 )
goto V_87;
}
goto V_89;
}
if ( V_9 -> V_15 < V_15 ) {
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_15 ;
V_81 = - V_66 ;
goto V_88;
}
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_15 ) ;
F_47 ( V_81 == - V_66 ) ;
V_70 = NULL ;
if ( V_81 )
goto V_88;
if ( V_9 -> V_16 <= V_16 ) {
F_38 ( V_17 , V_9 , & V_62 ) ;
F_59 ( V_9 , V_77 ) ;
F_33 ( V_17 , V_9 ) ;
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
}
goto V_89;
}
if ( V_9 -> V_15 > V_15 ) {
T_3 V_97 ;
if ( V_16 < V_96 )
V_97 = V_16 ;
else
V_97 = V_96 - 1 ;
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_37 ( V_17 , V_70 , V_15 , V_97 ,
& V_62 ) ;
F_47 ( V_81 == - V_66 ) ;
if ( V_81 ) {
F_21 ( V_70 ) ;
V_70 = NULL ;
goto V_88;
}
F_59 ( V_70 , V_77 ) ;
V_70 = NULL ;
V_15 = V_97 + 1 ;
goto V_89;
}
if ( V_9 -> V_15 <= V_16 && V_9 -> V_16 > V_16 ) {
if ( V_9 -> V_9 & V_94 ) {
* V_95 = V_15 ;
V_81 = - V_66 ;
goto V_88;
}
V_70 = F_43 ( V_70 ) ;
F_47 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_16 + 1 ) ;
F_47 ( V_81 == - V_66 ) ;
F_38 ( V_17 , V_70 , & V_62 ) ;
F_59 ( V_70 , V_77 ) ;
F_33 ( V_17 , V_70 ) ;
V_70 = NULL ;
goto V_88;
}
goto V_89;
V_88:
F_49 ( & V_17 -> V_29 ) ;
if ( V_70 )
F_21 ( V_70 ) ;
return V_81 ;
V_89:
if ( V_15 > V_16 )
goto V_88;
F_49 ( & V_17 -> V_29 ) ;
if ( V_31 & V_86 )
F_50 () ;
goto V_85;
}
int F_62 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_74 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_63 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_62 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_64 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_62 , 0 , 0 , NULL , V_31 ) ;
}
int F_65 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_77 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 ,
V_98 | V_74 | V_99 ,
0 , NULL , V_77 , V_31 ) ;
}
int F_66 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 ,
V_74 | V_98 |
V_100 , 0 , 0 , NULL , V_31 ) ;
}
int F_67 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_101 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_68 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_77 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_99 , 0 ,
NULL , V_77 , V_31 ) ;
}
static int F_69 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 V_16 , struct V_2 * * V_77 ,
T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_99 , 0 , 0 ,
V_77 , V_31 ) ;
}
int F_70 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , struct V_2 * * V_77 , T_2 V_31 )
{
int V_81 ;
T_3 V_95 ;
while ( 1 ) {
V_81 = F_61 ( V_17 , V_15 , V_16 , V_102 | V_62 ,
V_102 , & V_95 ,
V_77 , V_31 ) ;
if ( V_81 == - V_66 && ( V_31 & V_86 ) ) {
F_56 ( V_17 , V_95 , V_16 , V_102 ) ;
V_15 = V_95 ;
} else {
break;
}
F_23 ( V_15 > V_16 ) ;
}
return V_81 ;
}
int F_71 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_70 ( V_17 , V_15 , V_16 , 0 , NULL , V_31 ) ;
}
int F_72 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
int V_81 ;
T_3 V_95 ;
V_81 = F_61 ( V_17 , V_15 , V_16 , V_102 , V_102 ,
& V_95 , NULL , V_31 ) ;
if ( V_81 == - V_66 ) {
if ( V_95 > V_15 )
F_44 ( V_17 , V_15 , V_95 - 1 ,
V_102 , 1 , 0 , NULL , V_31 ) ;
return 0 ;
}
return 1 ;
}
int F_73 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_78 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_102 , 1 , 0 , V_78 ,
V_31 ) ;
}
int F_74 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_102 , 1 , 0 , NULL ,
V_31 ) ;
}
static int F_75 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_103 = V_15 >> V_104 ;
unsigned long V_105 = V_16 >> V_104 ;
struct V_106 * V_106 ;
while ( V_103 <= V_105 ) {
V_106 = F_76 ( V_17 -> V_23 , V_103 ) ;
F_47 ( ! V_106 ) ;
F_77 ( V_106 ) ;
F_78 ( V_106 ) ;
V_103 ++ ;
}
return 0 ;
}
struct V_2 * F_79 ( struct V_21 * V_17 ,
T_3 V_15 , int V_62 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 )
goto V_88;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_16 >= V_15 && ( V_9 -> V_9 & V_62 ) )
return V_9 ;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
}
V_88:
return NULL ;
}
int F_80 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 * V_107 , T_3 * V_108 , int V_62 )
{
struct V_2 * V_9 ;
int V_54 = 1 ;
F_45 ( & V_17 -> V_29 ) ;
V_9 = F_79 ( V_17 , V_15 , V_62 ) ;
if ( V_9 ) {
* V_107 = V_9 -> V_15 ;
* V_108 = V_9 -> V_16 ;
V_54 = 0 ;
}
F_49 ( & V_17 -> V_29 ) ;
return V_54 ;
}
static T_4 T_3 F_81 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 * V_16 , T_3 V_109 ,
struct V_2 * * V_77 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_110 = * V_15 ;
T_3 V_65 = 0 ;
T_3 V_111 = 0 ;
F_45 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_110 ) ;
if ( ! V_41 ) {
if ( ! V_65 )
* V_16 = ( T_3 ) - 1 ;
goto V_88;
}
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_65 && ( V_9 -> V_15 != V_110 ||
( V_9 -> V_9 & V_61 ) ) ) {
goto V_88;
}
if ( ! ( V_9 -> V_9 & V_98 ) ) {
if ( ! V_65 )
* V_16 = V_9 -> V_16 ;
goto V_88;
}
if ( ! V_65 ) {
* V_15 = V_9 -> V_15 ;
* V_77 = V_9 ;
F_57 ( & V_9 -> V_18 ) ;
}
V_65 ++ ;
* V_16 = V_9 -> V_16 ;
V_110 = V_9 -> V_16 + 1 ;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
V_111 += V_9 -> V_16 - V_9 -> V_15 + 1 ;
if ( V_111 >= V_109 )
break;
}
V_88:
F_49 ( & V_17 -> V_29 ) ;
return V_65 ;
}
static T_4 int F_82 ( struct V_112 * V_112 ,
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
V_54 = F_83 ( V_112 -> V_117 , V_103 ,
F_84 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_114 ) ;
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_114 [ V_116 ] != V_113 )
F_85 ( V_114 [ V_116 ] ) ;
F_78 ( V_114 [ V_116 ] ) ;
}
V_115 -= V_54 ;
V_103 += V_54 ;
F_50 () ;
}
return 0 ;
}
static T_4 int F_86 ( struct V_112 * V_112 ,
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
V_54 = F_83 ( V_112 -> V_117 , V_103 ,
F_84 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_114 ) ;
if ( V_54 == 0 ) {
V_54 = - V_123 ;
goto V_124;
}
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_114 [ V_116 ] != V_113 ) {
F_87 ( V_114 [ V_116 ] ) ;
if ( ! F_88 ( V_114 [ V_116 ] ) ||
V_114 [ V_116 ] -> V_23 != V_112 -> V_117 ) {
V_54 = - V_123 ;
F_85 ( V_114 [ V_116 ] ) ;
F_78 ( V_114 [ V_116 ] ) ;
goto V_124;
}
}
F_78 ( V_114 [ V_116 ] ) ;
V_121 ++ ;
}
V_122 -= V_54 ;
V_103 += V_54 ;
F_50 () ;
}
V_54 = 0 ;
V_124:
if ( V_54 && V_121 ) {
F_82 ( V_112 , V_113 ,
V_118 ,
( ( T_3 ) ( V_120 + V_121 - 1 ) ) <<
V_104 ) ;
}
return V_54 ;
}
static T_4 T_3 F_89 ( struct V_112 * V_112 ,
struct V_21 * V_17 ,
struct V_106 * V_113 ,
T_3 * V_15 , T_3 * V_16 ,
T_3 V_109 )
{
T_3 V_118 ;
T_3 V_119 ;
T_3 V_65 ;
struct V_2 * V_77 = NULL ;
int V_54 ;
int V_125 = 0 ;
V_85:
V_118 = * V_15 ;
V_119 = 0 ;
V_65 = F_81 ( V_17 , & V_118 , & V_119 ,
V_109 , & V_77 ) ;
if ( ! V_65 || V_119 <= * V_15 ) {
* V_15 = V_118 ;
* V_16 = V_119 ;
F_21 ( V_77 ) ;
return V_65 ;
}
if ( V_118 < * V_15 )
V_118 = * V_15 ;
if ( V_119 + 1 - V_118 > V_109 && V_125 )
V_119 = V_118 + V_126 - 1 ;
V_54 = F_86 ( V_112 , V_113 ,
V_118 , V_119 ) ;
if ( V_54 == - V_123 ) {
F_21 ( V_77 ) ;
if ( ! V_125 ) {
unsigned long V_40 = ( * V_15 ) & ( V_126 - 1 ) ;
V_109 = V_126 - V_40 ;
V_125 = 1 ;
goto V_85;
} else {
V_65 = 0 ;
goto V_127;
}
}
F_47 ( V_54 ) ;
F_70 ( V_17 , V_118 , V_119 ,
0 , & V_77 , V_128 ) ;
V_54 = F_90 ( V_17 , V_118 , V_119 ,
V_98 , 1 , V_77 ) ;
if ( ! V_54 ) {
F_73 ( V_17 , V_118 , V_119 ,
& V_77 , V_128 ) ;
F_82 ( V_112 , V_113 ,
V_118 , V_119 ) ;
F_50 () ;
goto V_85;
}
F_21 ( V_77 ) ;
* V_15 = V_118 ;
* V_16 = V_119 ;
V_127:
return V_65 ;
}
int F_91 ( struct V_112 * V_112 ,
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
V_130 |= V_74 ;
if ( V_129 & V_133 )
V_130 |= V_98 ;
F_44 ( V_17 , V_15 , V_16 , V_130 , 1 , 0 , NULL , V_128 ) ;
if ( ! ( V_129 & ( V_134 | V_132 |
V_135 | V_136 |
V_137 ) ) )
return 0 ;
while ( V_115 > 0 ) {
V_54 = F_83 ( V_112 -> V_117 , V_103 ,
F_84 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_114 ) ;
for ( V_116 = 0 ; V_116 < V_54 ; V_116 ++ ) {
if ( V_129 & V_137 )
F_92 ( V_114 [ V_116 ] ) ;
if ( V_114 [ V_116 ] == V_113 ) {
F_78 ( V_114 [ V_116 ] ) ;
continue;
}
if ( V_129 & V_132 )
F_93 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_135 )
F_77 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_136 )
F_94 ( V_114 [ V_116 ] ) ;
if ( V_129 & V_134 )
F_85 ( V_114 [ V_116 ] ) ;
F_78 ( V_114 [ V_116 ] ) ;
}
V_115 -= V_54 ;
V_103 += V_54 ;
F_50 () ;
}
return 0 ;
}
T_3 F_95 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 V_138 , T_3 V_109 ,
unsigned long V_62 , int V_139 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_110 = * V_15 ;
T_3 V_111 = 0 ;
T_3 V_140 = 0 ;
int V_65 = 0 ;
if ( V_138 <= V_110 ) {
F_23 ( 1 ) ;
return 0 ;
}
F_45 ( & V_17 -> V_29 ) ;
if ( V_110 == 0 && V_62 == V_74 ) {
V_111 = V_17 -> V_28 ;
goto V_88;
}
V_41 = F_31 ( V_17 , V_110 ) ;
if ( ! V_41 )
goto V_88;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 > V_138 )
break;
if ( V_139 && V_65 && V_9 -> V_15 > V_140 + 1 )
break;
if ( V_9 -> V_16 >= V_110 && ( V_9 -> V_9 & V_62 ) == V_62 ) {
V_111 += F_96 ( V_138 , V_9 -> V_16 ) + 1 -
F_97 ( V_110 , V_9 -> V_15 ) ;
if ( V_111 >= V_109 )
break;
if ( ! V_65 ) {
* V_15 = F_97 ( V_110 , V_9 -> V_15 ) ;
V_65 = 1 ;
}
V_140 = V_9 -> V_16 ;
} else if ( V_139 && V_65 ) {
break;
}
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
}
V_88:
F_49 ( & V_17 -> V_29 ) ;
return V_111 ;
}
int F_98 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_34 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
int V_54 = 0 ;
F_45 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_54 = - V_141 ;
goto V_88;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 != V_15 ) {
V_54 = - V_141 ;
goto V_88;
}
V_9 -> V_34 = V_34 ;
V_88:
F_49 ( & V_17 -> V_29 ) ;
return V_54 ;
}
int F_99 ( struct V_21 * V_17 , T_3 V_15 , T_3 * V_34 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
int V_54 = 0 ;
F_45 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_54 = - V_141 ;
goto V_88;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 != V_15 ) {
V_54 = - V_141 ;
goto V_88;
}
* V_34 = V_9 -> V_34 ;
V_88:
F_49 ( & V_17 -> V_29 ) ;
return V_54 ;
}
int F_90 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , int V_142 , struct V_2 * V_78 )
{
struct V_2 * V_9 = NULL ;
struct V_37 * V_41 ;
int V_143 = 0 ;
F_45 ( & V_17 -> V_29 ) ;
if ( V_78 && V_78 -> V_17 && V_78 -> V_15 <= V_15 &&
V_78 -> V_16 > V_15 )
V_41 = & V_78 -> V_37 ;
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
F_49 ( & V_17 -> V_29 ) ;
return V_143 ;
}
static int F_100 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( F_90 ( V_17 , V_15 , V_16 , V_99 , 1 , NULL ) )
F_101 ( V_106 ) ;
return 0 ;
}
static int F_102 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( ! F_90 ( V_17 , V_15 , V_16 , V_102 , 0 , NULL ) )
F_85 ( V_106 ) ;
return 0 ;
}
static int F_103 ( struct V_21 * V_17 ,
struct V_106 * V_106 )
{
F_94 ( V_106 ) ;
return 0 ;
}
static void F_104 ( struct V_144 * V_144 , int V_81 )
{
int V_145 = V_81 == 0 ;
struct V_146 * V_147 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_150 ;
int V_54 ;
do {
struct V_106 * V_106 = V_147 -> V_151 ;
V_17 = & F_105 ( V_106 -> V_23 -> V_58 ) -> V_152 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) +
V_147 -> V_153 ;
V_16 = V_15 + V_147 -> V_154 - 1 ;
if ( V_147 -> V_153 == 0 && V_147 -> V_154 == V_126 )
V_150 = 1 ;
else
V_150 = 0 ;
if ( -- V_147 >= V_144 -> V_148 )
F_106 ( & V_147 -> V_151 -> V_33 ) ;
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
V_145 = ( V_81 == 0 ) ;
continue;
}
}
if ( ! V_145 ) {
F_69 ( V_17 , V_15 , V_16 , NULL , V_128 ) ;
F_107 ( V_106 ) ;
F_108 ( V_106 ) ;
}
if ( V_150 )
F_94 ( V_106 ) ;
else
F_103 ( V_17 , V_106 ) ;
} while ( V_147 >= V_144 -> V_148 );
F_109 ( V_144 ) ;
}
static void F_110 ( struct V_144 * V_144 , int V_81 )
{
int V_145 = F_111 ( V_157 , & V_144 -> V_158 ) ;
struct V_146 * V_159 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_146 * V_147 = V_144 -> V_148 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_150 ;
int V_54 ;
if ( V_81 )
V_145 = 0 ;
do {
struct V_106 * V_106 = V_147 -> V_151 ;
struct V_2 * V_78 = NULL ;
struct V_2 * V_9 ;
V_17 = & F_105 ( V_106 -> V_23 -> V_58 ) -> V_152 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) +
V_147 -> V_153 ;
V_16 = V_15 + V_147 -> V_154 - 1 ;
if ( V_147 -> V_153 == 0 && V_147 -> V_154 == V_126 )
V_150 = 1 ;
else
V_150 = 0 ;
if ( ++ V_147 <= V_159 )
F_106 ( & V_147 -> V_151 -> V_33 ) ;
F_45 ( & V_17 -> V_29 ) ;
V_9 = F_79 ( V_17 , V_15 , V_102 ) ;
if ( V_9 && V_9 -> V_15 == V_15 ) {
F_59 ( V_9 , & V_78 ) ;
}
F_49 ( & V_17 -> V_29 ) ;
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
F_111 ( V_157 , & V_144 -> V_158 ) ;
if ( V_81 )
V_145 = 0 ;
F_60 ( & V_78 ) ;
continue;
}
}
if ( V_145 ) {
F_68 ( V_17 , V_15 , V_16 , & V_78 ,
V_26 ) ;
}
F_73 ( V_17 , V_15 , V_16 , & V_78 , V_26 ) ;
if ( V_150 ) {
if ( V_145 ) {
F_101 ( V_106 ) ;
} else {
F_107 ( V_106 ) ;
F_108 ( V_106 ) ;
}
F_85 ( V_106 ) ;
} else {
if ( V_145 ) {
F_100 ( V_17 , V_106 ) ;
} else {
F_107 ( V_106 ) ;
F_108 ( V_106 ) ;
}
F_102 ( V_17 , V_106 ) ;
}
} while ( V_147 <= V_159 );
F_109 ( V_144 ) ;
}
struct V_144 *
F_112 ( struct V_162 * V_163 , T_3 V_164 , int V_165 ,
T_2 V_166 )
{
struct V_144 * V_144 ;
V_144 = F_113 ( V_166 , V_165 ) ;
if ( V_144 == NULL && ( V_167 -> V_33 & V_168 ) ) {
while ( ! V_144 && ( V_165 /= 2 ) )
V_144 = F_113 ( V_166 , V_165 ) ;
}
if ( V_144 ) {
V_144 -> V_169 = 0 ;
V_144 -> V_170 = V_163 ;
V_144 -> V_171 = V_164 ;
}
return V_144 ;
}
static int F_114 ( int V_172 , struct V_144 * V_144 , int V_173 ,
unsigned long V_174 )
{
int V_54 = 0 ;
struct V_146 * V_147 = V_144 -> V_148 + V_144 -> V_149 - 1 ;
struct V_106 * V_106 = V_147 -> V_151 ;
struct V_21 * V_17 = V_144 -> V_175 ;
T_3 V_15 ;
V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) + V_147 -> V_153 ;
V_144 -> V_175 = NULL ;
F_115 ( V_144 ) ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_176 )
V_54 = V_17 -> V_27 -> V_176 ( V_106 -> V_23 -> V_58 , V_172 , V_144 ,
V_173 , V_174 , V_15 ) ;
else
F_116 ( V_172 , V_144 ) ;
if ( F_117 ( V_144 , V_177 ) )
V_54 = - V_178 ;
F_109 ( V_144 ) ;
return V_54 ;
}
static int F_118 ( int V_172 , struct V_21 * V_17 ,
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
T_6 V_189 = F_84 ( T_6 , V_180 , V_126 ) ;
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
F_119 ( V_144 , V_106 , V_189 , V_40 ) < V_189 ) {
V_54 = F_114 ( V_172 , V_144 , V_173 ,
V_184 ) ;
V_144 = NULL ;
} else {
return 0 ;
}
}
if ( V_186 )
V_185 = V_191 ;
else
V_185 = F_120 ( V_163 ) ;
V_144 = F_112 ( V_163 , V_179 , V_185 , V_128 | V_192 ) ;
if ( ! V_144 )
return - V_5 ;
F_119 ( V_144 , V_106 , V_189 , V_40 ) ;
V_144 -> V_193 = V_183 ;
V_144 -> V_175 = V_17 ;
if ( V_181 )
* V_181 = V_144 ;
else
V_54 = F_114 ( V_172 , V_144 , V_173 , V_174 ) ;
return V_54 ;
}
void F_121 ( struct V_106 * V_106 )
{
if ( ! F_122 ( V_106 ) ) {
F_123 ( V_106 ) ;
F_124 ( V_106 ) ;
F_125 ( V_106 , V_194 ) ;
}
}
static void F_126 ( struct V_106 * V_106 , unsigned long V_20 )
{
F_23 ( ! F_122 ( V_106 ) ) ;
F_125 ( V_106 , V_195 | V_20 << 2 ) ;
}
static int F_127 ( struct V_21 * V_17 ,
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
T_3 V_200 = F_128 ( V_112 ) ;
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
F_121 ( V_106 ) ;
if ( ! F_129 ( V_106 ) ) {
if ( F_130 ( V_106 ) == 0 ) {
F_47 ( V_210 != V_214 ) ;
goto V_88;
}
}
V_16 = V_197 ;
while ( 1 ) {
F_71 ( V_17 , V_15 , V_16 , V_128 ) ;
V_206 = F_131 ( V_112 , V_15 ) ;
if ( ! V_206 )
break;
F_74 ( V_17 , V_15 , V_16 , V_128 ) ;
F_132 ( V_112 , V_206 , 1 ) ;
F_133 ( V_206 ) ;
}
if ( V_106 -> V_103 == V_200 >> V_104 ) {
char * V_215 ;
T_6 V_216 = V_200 & ( V_126 - 1 ) ;
if ( V_216 ) {
V_208 = V_126 - V_216 ;
V_215 = F_134 ( V_106 , V_217 ) ;
memset ( V_215 + V_216 , 0 , V_208 ) ;
F_135 ( V_106 ) ;
F_136 ( V_215 , V_217 ) ;
}
}
while ( V_198 <= V_16 ) {
if ( V_198 >= V_200 ) {
char * V_215 ;
struct V_2 * V_78 = NULL ;
V_208 = V_126 - V_207 ;
V_215 = F_134 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 , V_208 ) ;
F_135 ( V_106 ) ;
F_136 ( V_215 , V_217 ) ;
F_68 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_78 , V_128 ) ;
F_73 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_78 , V_128 ) ;
break;
}
V_204 = V_196 ( V_112 , V_106 , V_207 , V_198 ,
V_16 - V_198 + 1 , 0 ) ;
if ( F_137 ( V_204 ) ) {
F_108 ( V_106 ) ;
F_74 ( V_17 , V_198 , V_16 , V_128 ) ;
break;
}
V_199 = V_198 - V_204 -> V_15 ;
F_47 ( F_138 ( V_204 ) <= V_198 ) ;
F_47 ( V_16 < V_198 ) ;
if ( F_111 ( V_218 , & V_204 -> V_33 ) ) {
V_213 = V_187 ;
F_139 ( & V_213 ,
V_204 -> V_219 ) ;
}
V_208 = F_96 ( F_138 ( V_204 ) - V_198 , V_16 - V_198 + 1 ) ;
V_202 = F_96 ( F_138 ( V_204 ) - 1 , V_16 ) ;
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
if ( F_111 ( V_221 , & V_204 -> V_33 ) )
V_201 = V_222 ;
F_140 ( V_204 ) ;
V_204 = NULL ;
if ( V_201 == V_222 ) {
char * V_215 ;
struct V_2 * V_78 = NULL ;
V_215 = F_134 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 , V_208 ) ;
F_135 ( V_106 ) ;
F_136 ( V_215 , V_217 ) ;
F_68 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_78 , V_128 ) ;
F_73 ( V_17 , V_198 , V_198 + V_208 - 1 ,
& V_78 , V_128 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
if ( F_90 ( V_17 , V_198 , V_202 ,
V_99 , 1 , NULL ) ) {
F_100 ( V_17 , V_106 ) ;
F_74 ( V_17 , V_198 , V_198 + V_208 - 1 , V_128 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
continue;
}
if ( V_201 == V_223 ) {
F_108 ( V_106 ) ;
F_74 ( V_17 , V_198 , V_198 + V_208 - 1 , V_128 ) ;
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
V_54 = F_118 ( V_226 , V_17 , V_106 ,
V_179 , V_209 , V_207 ,
V_163 , V_144 , V_225 ,
F_110 , V_173 ,
* V_174 ,
V_213 ) ;
V_185 ++ ;
* V_174 = V_213 ;
}
if ( V_54 )
F_108 ( V_106 ) ;
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
}
V_88:
if ( ! V_185 ) {
if ( ! F_141 ( V_106 ) )
F_101 ( V_106 ) ;
F_85 ( V_106 ) ;
}
return 0 ;
}
int F_142 ( struct V_21 * V_17 , struct V_106 * V_106 ,
T_8 * V_196 )
{
struct V_144 * V_144 = NULL ;
unsigned long V_174 = 0 ;
int V_54 ;
V_54 = F_127 ( V_17 , V_106 , V_196 , & V_144 , 0 ,
& V_174 ) ;
if ( V_144 )
V_54 = F_114 ( V_226 , V_144 , 0 , V_174 ) ;
return V_54 ;
}
static T_4 void F_143 ( struct V_106 * V_106 ,
struct V_227 * V_228 ,
unsigned long V_229 )
{
V_228 -> V_230 -= V_229 ;
if ( V_228 -> V_231 || ( V_228 -> V_230 > 0 &&
V_228 -> V_232 == 0 && V_228 -> V_233 == V_234 ) )
V_106 -> V_23 -> V_235 = V_106 -> V_103 + V_229 ;
}
static int F_144 ( struct V_106 * V_106 , struct V_227 * V_228 ,
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
T_3 V_200 = F_128 ( V_112 ) ;
T_3 V_201 ;
T_3 V_208 ;
T_5 V_179 ;
struct V_2 * V_77 = NULL ;
struct V_203 * V_204 ;
struct V_162 * V_163 ;
int V_54 ;
int V_185 = 0 ;
T_6 V_207 = 0 ;
T_6 V_210 ;
T_9 V_239 = F_128 ( V_112 ) ;
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
F_145 ( V_106 , V_112 , V_228 ) ;
F_23 ( ! F_146 ( V_106 ) ) ;
V_207 = V_239 & ( V_126 - 1 ) ;
if ( V_106 -> V_103 > V_105 ||
( V_106 -> V_103 == V_105 && ! V_207 ) ) {
V_106 -> V_23 -> V_248 -> V_249 ( V_106 , 0 ) ;
F_85 ( V_106 ) ;
return 0 ;
}
if ( V_106 -> V_103 == V_105 ) {
char * V_215 ;
V_215 = F_134 ( V_106 , V_217 ) ;
memset ( V_215 + V_207 , 0 ,
V_126 - V_207 ) ;
F_136 ( V_215 , V_217 ) ;
F_135 ( V_106 ) ;
}
V_207 = 0 ;
F_121 ( V_106 ) ;
V_118 = V_15 ;
V_119 = 0 ;
V_241 = 0 ;
if ( ! V_238 -> V_250 ) {
T_3 V_251 = 0 ;
F_143 ( V_106 , V_228 , 0 ) ;
while ( V_119 < V_197 ) {
V_240 = F_89 ( V_112 , V_17 ,
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
V_228 -> V_230 = F_84 ( T_3 , V_251 ,
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
F_147 ( V_228 , V_106 ) ;
F_143 ( V_106 , V_228 , V_229 ) ;
F_85 ( V_106 ) ;
V_54 = 0 ;
goto V_254;
}
}
F_143 ( V_106 , V_228 , V_229 + 1 ) ;
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
if ( F_137 ( V_204 ) ) {
F_108 ( V_106 ) ;
break;
}
V_199 = V_198 - V_204 -> V_15 ;
F_47 ( F_138 ( V_204 ) <= V_198 ) ;
F_47 ( V_16 < V_198 ) ;
V_208 = F_96 ( F_138 ( V_204 ) - V_198 , V_16 - V_198 + 1 ) ;
V_208 = ( V_208 + V_210 - 1 ) & ~ ( ( T_3 ) V_210 - 1 ) ;
V_179 = ( V_204 -> V_201 + V_199 ) >> 9 ;
V_163 = V_204 -> V_163 ;
V_201 = V_204 -> V_201 ;
V_242 = F_111 ( V_218 , & V_204 -> V_33 ) ;
F_140 ( V_204 ) ;
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
if ( 0 && ! F_90 ( V_17 , V_198 , V_198 + V_208 - 1 ,
V_74 , 0 , NULL ) ) {
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
F_108 ( V_106 ) ;
} else {
unsigned long V_257 = V_105 + 1 ;
F_75 ( V_17 , V_198 , V_198 + V_208 - 1 ) ;
if ( ! F_148 ( V_106 ) ) {
F_7 ( V_14 L_10
L_11 ,
V_106 -> V_103 , ( unsigned long long ) V_198 ,
( unsigned long long ) V_16 ) ;
}
V_54 = F_118 ( V_243 , V_17 , V_106 ,
V_179 , V_208 , V_207 ,
V_163 , & V_238 -> V_144 , V_257 ,
F_104 ,
0 , 0 , 0 ) ;
if ( V_54 )
F_108 ( V_106 ) ;
}
V_198 = V_198 + V_208 ;
V_207 += V_208 ;
V_185 ++ ;
}
V_124:
if ( V_185 == 0 ) {
F_77 ( V_106 ) ;
F_94 ( V_106 ) ;
}
F_85 ( V_106 ) ;
V_254:
F_21 ( V_77 ) ;
return 0 ;
}
static int F_149 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_227 * V_228 ,
T_10 V_258 , void * V_236 ,
void (* F_150)( void * ) )
{
int V_54 = 0 ;
int V_124 = 0 ;
int V_259 = 0 ;
struct V_260 V_261 ;
int V_115 ;
T_11 V_103 ;
T_11 V_16 ;
int V_262 = 0 ;
int V_263 ;
F_151 ( & V_261 , 0 ) ;
if ( V_228 -> V_231 ) {
V_103 = V_23 -> V_235 ;
V_16 = - 1 ;
} else {
V_103 = V_228 -> V_232 >> V_104 ;
V_16 = V_228 -> V_233 >> V_104 ;
V_262 = 1 ;
}
if ( V_228 -> V_244 == V_245 )
V_263 = V_264 ;
else
V_263 = V_265 ;
V_266:
if ( V_228 -> V_244 == V_245 )
F_152 ( V_23 , V_103 , V_16 ) ;
while ( ! V_124 && ! V_259 && ( V_103 <= V_16 ) &&
( V_115 = F_153 ( & V_261 , V_23 , & V_103 , V_263 ,
F_96 ( V_16 - V_103 , ( T_11 ) V_267 - 1 ) + 1 ) ) ) {
unsigned V_116 ;
V_262 = 1 ;
for ( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
struct V_106 * V_106 = V_261 . V_114 [ V_116 ] ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_268 )
V_17 -> V_27 -> V_268 ( V_106 ) ;
else
F_87 ( V_106 ) ;
if ( F_154 ( V_106 -> V_23 != V_23 ) ) {
F_85 ( V_106 ) ;
continue;
}
if ( ! V_228 -> V_231 && V_106 -> V_103 > V_16 ) {
V_124 = 1 ;
F_85 ( V_106 ) ;
continue;
}
if ( V_228 -> V_244 != V_269 ) {
if ( F_148 ( V_106 ) )
F_150 ( V_236 ) ;
F_155 ( V_106 ) ;
}
if ( F_148 ( V_106 ) ||
! F_93 ( V_106 ) ) {
F_85 ( V_106 ) ;
continue;
}
V_54 = (* V_258)( V_106 , V_228 , V_236 ) ;
if ( F_154 ( V_54 == V_270 ) ) {
F_85 ( V_106 ) ;
V_54 = 0 ;
}
if ( V_54 )
V_124 = 1 ;
V_259 = V_228 -> V_230 <= 0 ;
}
F_156 ( & V_261 ) ;
F_50 () ;
}
if ( ! V_262 && ! V_124 ) {
V_262 = 1 ;
V_103 = 0 ;
goto V_266;
}
return V_54 ;
}
static void F_157 ( struct V_237 * V_238 )
{
if ( V_238 -> V_144 ) {
if ( V_238 -> V_271 )
F_114 ( V_246 , V_238 -> V_144 , 0 , 0 ) ;
else
F_114 ( V_247 , V_238 -> V_144 , 0 , 0 ) ;
V_238 -> V_144 = NULL ;
}
}
static T_4 void F_158 ( void * V_236 )
{
struct V_237 * V_238 = V_236 ;
F_157 ( V_238 ) ;
}
int F_159 ( struct V_21 * V_17 , struct V_106 * V_106 ,
T_8 * V_196 ,
struct V_227 * V_228 )
{
int V_54 ;
struct V_237 V_238 = {
. V_144 = NULL ,
. V_17 = V_17 ,
. V_196 = V_196 ,
. V_250 = 0 ,
. V_271 = V_228 -> V_244 == V_245 ,
} ;
V_54 = F_144 ( V_106 , V_228 , & V_238 ) ;
F_157 ( & V_238 ) ;
return V_54 ;
}
int F_160 ( struct V_21 * V_17 , struct V_112 * V_112 ,
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
. V_271 = V_272 == V_245 ,
} ;
struct V_227 V_273 = {
. V_244 = V_272 ,
. V_230 = V_115 * 2 ,
. V_232 = V_15 ,
. V_233 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_106 = F_76 ( V_23 , V_15 >> V_104 ) ;
if ( F_93 ( V_106 ) )
V_54 = F_144 ( V_106 , & V_273 , & V_238 ) ;
else {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_155 )
V_17 -> V_27 -> V_155 ( V_106 , V_15 ,
V_15 + V_126 - 1 ,
NULL , 1 ) ;
F_85 ( V_106 ) ;
}
F_78 ( V_106 ) ;
V_15 += V_126 ;
}
F_157 ( & V_238 ) ;
return V_54 ;
}
int F_161 ( struct V_21 * V_17 ,
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
. V_271 = V_228 -> V_244 == V_245 ,
} ;
V_54 = F_149 ( V_17 , V_23 , V_228 ,
F_144 , & V_238 ,
F_158 ) ;
F_157 ( & V_238 ) ;
return V_54 ;
}
int F_162 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_274 * V_114 , unsigned V_115 ,
T_8 V_196 )
{
struct V_144 * V_144 = NULL ;
unsigned V_275 ;
unsigned long V_174 = 0 ;
for ( V_275 = 0 ; V_275 < V_115 ; V_275 ++ ) {
struct V_106 * V_106 = F_6 ( V_114 -> V_51 , struct V_106 , V_276 ) ;
F_106 ( & V_106 -> V_33 ) ;
F_9 ( & V_106 -> V_276 ) ;
if ( ! F_163 ( V_106 , V_23 ,
V_106 -> V_103 , V_128 ) ) {
F_127 ( V_17 , V_106 , V_196 ,
& V_144 , 0 , & V_174 ) ;
}
F_78 ( V_106 ) ;
}
F_47 ( ! F_5 ( V_114 ) ) ;
if ( V_144 )
F_114 ( V_226 , V_144 , 0 , V_174 ) ;
return 0 ;
}
int F_164 ( struct V_21 * V_17 ,
struct V_106 * V_106 , unsigned long V_40 )
{
struct V_2 * V_77 = NULL ;
T_3 V_15 = ( ( T_3 ) V_106 -> V_103 << V_104 ) ;
T_3 V_16 = V_15 + V_126 - 1 ;
T_6 V_210 = V_106 -> V_23 -> V_58 -> V_211 -> V_212 ;
V_15 += ( V_40 + V_210 - 1 ) & ~ ( V_210 - 1 ) ;
if ( V_15 > V_16 )
return 0 ;
F_70 ( V_17 , V_15 , V_16 , 0 , & V_77 , V_128 ) ;
F_155 ( V_106 ) ;
F_44 ( V_17 , V_15 , V_16 ,
V_102 | V_74 | V_98 |
V_100 ,
1 , 1 , & V_77 , V_128 ) ;
return 0 ;
}
int F_165 ( struct V_277 * V_278 ,
struct V_21 * V_17 , struct V_106 * V_106 ,
T_2 V_31 )
{
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
int V_54 = 1 ;
if ( F_90 ( V_17 , V_15 , V_16 ,
V_60 , 0 , NULL ) )
V_54 = 0 ;
else {
if ( ( V_31 & V_128 ) == V_128 )
V_31 = V_128 ;
V_54 = F_44 ( V_17 , V_15 , V_16 ,
~ ( V_102 | V_279 ) ,
0 , 0 , NULL , V_31 ) ;
if ( V_54 < 0 )
V_54 = 0 ;
else
V_54 = 1 ;
}
return V_54 ;
}
int F_166 ( struct V_277 * V_278 ,
struct V_21 * V_17 , struct V_106 * V_106 ,
T_2 V_31 )
{
struct V_203 * V_204 ;
T_3 V_15 = ( T_3 ) V_106 -> V_103 << V_104 ;
T_3 V_16 = V_15 + V_126 - 1 ;
if ( ( V_31 & V_86 ) &&
V_106 -> V_23 -> V_58 -> V_239 > 16 * 1024 * 1024 ) {
T_3 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_167 ( & V_278 -> V_29 ) ;
V_204 = F_168 ( V_278 , V_15 , V_20 ) ;
if ( F_137 ( V_204 ) ) {
F_169 ( & V_278 -> V_29 ) ;
break;
}
if ( F_111 ( V_280 , & V_204 -> V_33 ) ||
V_204 -> V_15 != V_15 ) {
F_169 ( & V_278 -> V_29 ) ;
F_140 ( V_204 ) ;
break;
}
if ( ! F_90 ( V_17 , V_204 -> V_15 ,
F_138 ( V_204 ) - 1 ,
V_102 | V_281 ,
0 , NULL ) ) {
F_170 ( V_278 , V_204 ) ;
F_140 ( V_204 ) ;
}
V_15 = F_138 ( V_204 ) ;
F_169 ( & V_278 -> V_29 ) ;
F_140 ( V_204 ) ;
}
}
return F_165 ( V_278 , V_17 , V_106 , V_31 ) ;
}
static struct V_203 * F_171 ( struct V_112 * V_112 ,
T_3 V_40 ,
T_3 V_140 ,
T_8 * V_196 )
{
T_3 V_282 = F_105 ( V_112 ) -> V_39 -> V_282 ;
struct V_203 * V_204 ;
T_3 V_20 ;
if ( V_40 >= V_140 )
return NULL ;
while( 1 ) {
V_20 = V_140 - V_40 ;
if ( V_20 == 0 )
break;
V_20 = ( V_20 + V_282 - 1 ) & ~ ( V_282 - 1 ) ;
V_204 = V_196 ( V_112 , NULL , 0 , V_40 , V_20 , 0 ) ;
if ( F_137 ( V_204 ) )
return V_204 ;
if ( ! F_111 ( V_283 , & V_204 -> V_33 ) &&
V_204 -> V_201 != V_222 ) {
return V_204 ;
}
V_40 = F_138 ( V_204 ) ;
F_140 ( V_204 ) ;
if ( V_40 >= V_140 )
break;
}
return NULL ;
}
int F_172 ( struct V_112 * V_112 , struct V_284 * V_285 ,
T_12 V_15 , T_12 V_20 , T_8 * V_196 )
{
int V_54 = 0 ;
T_3 V_286 = V_15 ;
T_3 F_97 = V_15 + V_20 ;
T_13 V_33 = 0 ;
T_13 V_287 ;
T_3 V_140 ;
T_3 V_288 = 0 ;
T_3 V_289 = 0 ;
T_3 V_290 = F_128 ( V_112 ) ;
struct V_291 V_292 ;
struct V_203 * V_204 = NULL ;
struct V_2 * V_77 = NULL ;
struct V_293 * V_294 ;
struct V_295 * V_296 ;
int V_16 = 0 ;
T_3 V_297 = 0 ;
T_3 V_298 = 0 ;
T_3 V_299 = 0 ;
unsigned long V_300 ;
if ( V_20 == 0 )
return - V_301 ;
V_294 = F_173 () ;
if ( ! V_294 )
return - V_5 ;
V_294 -> V_302 = 1 ;
V_54 = F_174 ( NULL , F_105 ( V_112 ) -> V_39 ,
V_294 , F_175 ( V_112 ) , - 1 , 0 ) ;
if ( V_54 < 0 ) {
F_176 ( V_294 ) ;
return V_54 ;
}
F_23 ( ! V_54 ) ;
V_294 -> V_303 [ 0 ] -- ;
V_296 = F_177 ( V_294 -> V_304 [ 0 ] , V_294 -> V_303 [ 0 ] ,
struct V_295 ) ;
F_178 ( V_294 -> V_304 [ 0 ] , & V_292 , V_294 -> V_303 [ 0 ] ) ;
V_287 = F_179 ( & V_292 ) ;
if ( V_292 . V_305 != F_175 ( V_112 ) ||
V_287 != V_306 ) {
V_140 = ( T_3 ) - 1 ;
V_288 = V_290 ;
} else {
V_140 = V_292 . V_40 ;
V_288 = V_140 + 1 ;
}
F_176 ( V_294 ) ;
if ( V_140 < V_290 ) {
V_140 = ( T_3 ) - 1 ;
V_288 = V_290 ;
}
F_70 ( & F_105 ( V_112 ) -> V_152 , V_15 , V_15 + V_20 , 0 ,
& V_77 , V_128 ) ;
V_204 = F_171 ( V_112 , V_286 , V_288 ,
V_196 ) ;
if ( ! V_204 )
goto V_88;
if ( F_180 ( V_204 ) ) {
V_54 = F_181 ( V_204 ) ;
goto V_88;
}
while ( ! V_16 ) {
T_3 V_307 ;
if ( V_204 -> V_15 >= F_97 || F_138 ( V_204 ) < V_286 )
break;
V_297 = F_97 ( V_204 -> V_15 , V_286 ) ;
V_307 = V_297 - V_204 -> V_15 ;
V_299 = F_138 ( V_204 ) ;
V_298 = V_299 - V_297 ;
V_300 = V_204 -> V_33 ;
V_289 = 0 ;
V_33 = 0 ;
V_286 = F_138 ( V_204 ) ;
if ( V_286 >= F_97 )
V_16 = 1 ;
if ( V_204 -> V_201 == V_308 ) {
V_16 = 1 ;
V_33 |= V_309 ;
} else if ( V_204 -> V_201 == V_223 ) {
V_33 |= ( V_310 |
V_311 ) ;
} else if ( V_204 -> V_201 == V_312 ) {
V_33 |= ( V_313 |
V_314 ) ;
} else {
V_289 = V_204 -> V_201 + V_307 ;
}
if ( F_111 ( V_218 , & V_204 -> V_33 ) )
V_33 |= V_315 ;
F_140 ( V_204 ) ;
V_204 = NULL ;
if ( ( V_297 >= V_140 ) || V_298 == ( T_3 ) - 1 ||
( V_140 == ( T_3 ) - 1 && V_290 <= V_299 ) ) {
V_33 |= V_309 ;
V_16 = 1 ;
}
V_204 = F_171 ( V_112 , V_286 , V_288 ,
V_196 ) ;
if ( F_180 ( V_204 ) ) {
V_54 = F_181 ( V_204 ) ;
goto V_88;
}
if ( ! V_204 ) {
V_33 |= V_309 ;
V_16 = 1 ;
}
V_54 = F_182 ( V_285 , V_297 , V_289 ,
V_298 , V_33 ) ;
if ( V_54 )
goto V_316;
}
V_316:
F_140 ( V_204 ) ;
V_88:
F_73 ( & F_105 ( V_112 ) -> V_152 , V_15 , V_15 + V_20 ,
& V_77 , V_128 ) ;
return V_54 ;
}
static inline struct V_106 * F_183 ( struct V_7 * V_10 ,
unsigned long V_116 )
{
struct V_106 * V_42 ;
struct V_22 * V_23 ;
if ( V_116 == 0 )
return V_10 -> V_317 ;
V_116 += V_10 -> V_15 >> V_104 ;
V_23 = V_10 -> V_317 -> V_23 ;
if ( ! V_23 )
return NULL ;
F_184 () ;
V_42 = F_185 ( & V_23 -> V_318 , V_116 ) ;
F_186 () ;
return V_42 ;
}
static inline unsigned long F_187 ( T_3 V_15 , T_3 V_20 )
{
return ( ( V_15 + V_20 + V_126 - 1 ) >> V_104 ) -
( V_15 >> V_104 ) ;
}
static struct V_7 * F_188 ( struct V_21 * V_17 ,
T_3 V_15 ,
unsigned long V_20 ,
T_2 V_31 )
{
struct V_7 * V_10 = NULL ;
#if V_32
unsigned long V_33 ;
#endif
V_10 = F_189 ( V_6 , V_31 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_20 = V_20 ;
F_190 ( & V_10 -> V_29 ) ;
F_19 ( & V_10 -> V_319 , 0 ) ;
F_19 ( & V_10 -> V_320 , 0 ) ;
F_19 ( & V_10 -> V_321 , 0 ) ;
F_19 ( & V_10 -> V_322 , 0 ) ;
F_19 ( & V_10 -> V_323 , 0 ) ;
F_19 ( & V_10 -> V_324 , 0 ) ;
F_20 ( & V_10 -> V_325 ) ;
F_20 ( & V_10 -> V_326 ) ;
#if V_32
F_16 ( & V_35 , V_33 ) ;
F_17 ( & V_10 -> V_13 , & V_19 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_19 ( & V_10 -> V_18 , 1 ) ;
return V_10 ;
}
static void F_191 ( struct V_7 * V_10 )
{
#if V_32
unsigned long V_33 ;
F_16 ( & V_35 , V_33 ) ;
F_9 ( & V_10 -> V_13 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_10 ( V_6 , V_10 ) ;
}
static void F_192 ( struct V_7 * V_10 ,
unsigned long V_327 )
{
unsigned long V_103 ;
struct V_106 * V_106 ;
if ( ! V_10 -> V_317 )
return;
V_103 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
if ( V_327 >= V_103 )
return;
do {
V_103 -- ;
V_106 = F_183 ( V_10 , V_103 ) ;
if ( V_106 )
F_78 ( V_106 ) ;
} while ( V_103 != V_327 );
}
static inline void F_193 ( struct V_7 * V_10 )
{
F_192 ( V_10 , 0 ) ;
F_191 ( V_10 ) ;
}
struct V_7 * F_194 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 ,
struct V_106 * V_328 )
{
unsigned long V_329 = F_187 ( V_15 , V_20 ) ;
unsigned long V_116 ;
unsigned long V_103 = V_15 >> V_104 ;
struct V_7 * V_10 ;
struct V_7 * V_330 = NULL ;
struct V_106 * V_42 ;
struct V_22 * V_23 = V_17 -> V_23 ;
int V_145 = 1 ;
int V_54 ;
F_184 () ;
V_10 = F_185 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( V_10 && F_195 ( & V_10 -> V_18 ) ) {
F_186 () ;
F_196 ( V_10 -> V_317 ) ;
return V_10 ;
}
F_186 () ;
V_10 = F_188 ( V_17 , V_15 , V_20 , V_128 ) ;
if ( ! V_10 )
return NULL ;
if ( V_328 ) {
V_10 -> V_317 = V_328 ;
V_116 = 1 ;
V_103 ++ ;
F_124 ( V_328 ) ;
F_196 ( V_328 ) ;
F_121 ( V_328 ) ;
F_126 ( V_328 , V_20 ) ;
V_145 = F_129 ( V_328 ) ;
} else {
V_116 = 0 ;
}
for (; V_116 < V_329 ; V_116 ++ , V_103 ++ ) {
V_42 = F_197 ( V_23 , V_103 , V_128 ) ;
if ( ! V_42 ) {
F_23 ( 1 ) ;
goto V_331;
}
F_121 ( V_42 ) ;
F_196 ( V_42 ) ;
if ( V_116 == 0 ) {
V_10 -> V_317 = V_42 ;
F_126 ( V_42 , V_20 ) ;
} else {
F_125 ( V_42 , V_194 ) ;
}
if ( ! F_129 ( V_42 ) )
V_145 = 0 ;
if ( V_116 != 0 )
F_85 ( V_42 ) ;
}
if ( V_145 )
F_198 ( V_332 , & V_10 -> V_333 ) ;
V_54 = F_199 ( V_128 & ~ V_334 ) ;
if ( V_54 )
goto V_331;
F_45 ( & V_17 -> V_30 ) ;
V_54 = F_200 ( & V_17 -> V_25 , V_15 >> V_104 , V_10 ) ;
if ( V_54 == - V_66 ) {
V_330 = F_185 ( & V_17 -> V_25 ,
V_15 >> V_104 ) ;
F_57 ( & V_330 -> V_18 ) ;
F_49 ( & V_17 -> V_30 ) ;
F_201 () ;
goto V_331;
}
F_57 ( & V_10 -> V_18 ) ;
F_49 ( & V_17 -> V_30 ) ;
F_201 () ;
F_121 ( V_10 -> V_317 ) ;
F_126 ( V_10 -> V_317 , V_10 -> V_20 ) ;
if ( ! V_328 )
F_85 ( V_10 -> V_317 ) ;
return V_10 ;
V_331:
if ( V_10 -> V_317 && ! V_328 )
F_85 ( V_10 -> V_317 ) ;
if ( ! F_22 ( & V_10 -> V_18 ) )
return V_330 ;
F_193 ( V_10 ) ;
return V_330 ;
}
struct V_7 * F_202 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 )
{
struct V_7 * V_10 ;
F_184 () ;
V_10 = F_185 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( V_10 && F_195 ( & V_10 -> V_18 ) ) {
F_186 () ;
F_196 ( V_10 -> V_317 ) ;
return V_10 ;
}
F_186 () ;
return NULL ;
}
void F_203 ( struct V_7 * V_10 )
{
if ( ! V_10 )
return;
if ( ! F_22 ( & V_10 -> V_18 ) )
return;
F_23 ( 1 ) ;
}
int F_204 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
unsigned long V_329 ;
struct V_106 * V_106 ;
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
if ( ! F_88 ( V_106 ) )
continue;
F_87 ( V_106 ) ;
F_23 ( ! F_122 ( V_106 ) ) ;
F_121 ( V_106 ) ;
if ( V_116 == 0 )
F_126 ( V_106 , V_10 -> V_20 ) ;
F_93 ( V_106 ) ;
F_205 ( & V_106 -> V_23 -> V_335 ) ;
if ( ! F_88 ( V_106 ) ) {
F_206 ( & V_106 -> V_23 -> V_318 ,
F_207 ( V_106 ) ,
V_265 ) ;
}
F_208 ( & V_106 -> V_23 -> V_335 ) ;
F_85 ( V_106 ) ;
}
return 0 ;
}
int F_209 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
unsigned long V_329 ;
int V_336 = 0 ;
V_336 = F_210 ( V_337 , & V_10 -> V_333 ) ;
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_329 ; V_116 ++ )
F_211 ( F_183 ( V_10 , V_116 ) ) ;
return V_336 ;
}
static int F_212 ( T_3 V_15 , T_3 V_20 )
{
if ( V_20 < V_126 )
return 1 ;
if ( V_15 & ( V_126 - 1 ) )
return 1 ;
if ( ( V_15 + V_20 ) & ( V_126 - 1 ) )
return 1 ;
return 0 ;
}
static int F_213 ( struct V_7 * V_10 )
{
return F_212 ( V_10 -> V_15 , V_10 -> V_20 ) ;
}
int F_214 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * * V_77 )
{
unsigned long V_116 ;
struct V_106 * V_106 ;
unsigned long V_329 ;
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
F_215 ( V_332 , & V_10 -> V_333 ) ;
if ( F_213 ( V_10 ) ) {
F_69 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_77 , V_128 ) ;
}
for ( V_116 = 0 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
if ( V_106 )
F_107 ( V_106 ) ;
}
return 0 ;
}
int F_216 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_116 ;
struct V_106 * V_106 ;
unsigned long V_329 ;
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
if ( F_213 ( V_10 ) ) {
F_68 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
NULL , V_128 ) ;
}
for ( V_116 = 0 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
if ( ( V_116 == 0 && ( V_10 -> V_15 & ( V_126 - 1 ) ) ) ||
( ( V_116 == V_329 - 1 ) &&
( ( V_10 -> V_15 + V_10 -> V_20 ) & ( V_126 - 1 ) ) ) ) {
F_100 ( V_17 , V_106 ) ;
continue;
}
F_101 ( V_106 ) ;
}
return 0 ;
}
int F_217 ( struct V_21 * V_17 ,
T_3 V_15 , T_3 V_16 )
{
struct V_106 * V_106 ;
int V_54 ;
int V_338 = 1 ;
int V_145 ;
unsigned long V_103 ;
if ( F_212 ( V_15 , V_16 - V_15 + 1 ) ) {
V_54 = F_90 ( V_17 , V_15 , V_16 ,
V_99 , 1 , NULL ) ;
if ( V_54 )
return 1 ;
}
while ( V_15 <= V_16 ) {
V_103 = V_15 >> V_104 ;
V_106 = F_76 ( V_17 -> V_23 , V_103 ) ;
V_145 = F_129 ( V_106 ) ;
F_78 ( V_106 ) ;
if ( ! V_145 ) {
V_338 = 0 ;
break;
}
V_15 += V_126 ;
}
return V_338 ;
}
int F_218 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * V_77 )
{
int V_54 = 0 ;
unsigned long V_329 ;
unsigned long V_116 ;
struct V_106 * V_106 ;
int V_338 = 1 ;
if ( F_111 ( V_332 , & V_10 -> V_333 ) )
return 1 ;
if ( F_213 ( V_10 ) ) {
V_54 = F_90 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_99 , 1 , V_77 ) ;
if ( V_54 )
return V_54 ;
}
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = 0 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
if ( ! F_129 ( V_106 ) ) {
V_338 = 0 ;
break;
}
}
return V_338 ;
}
int F_219 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
T_3 V_15 , int V_90 ,
T_8 * V_196 , int V_173 )
{
unsigned long V_116 ;
unsigned long V_339 ;
struct V_106 * V_106 ;
int V_81 ;
int V_54 = 0 ;
int V_340 = 0 ;
int V_341 = 1 ;
int V_342 = 0 ;
unsigned long V_329 ;
struct V_144 * V_144 = NULL ;
unsigned long V_174 = 0 ;
if ( F_111 ( V_332 , & V_10 -> V_333 ) )
return 0 ;
if ( F_213 ( V_10 ) ) {
if ( F_90 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_99 , 1 , NULL ) ) {
return 0 ;
}
}
if ( V_15 ) {
F_23 ( V_15 < V_10 -> V_15 ) ;
V_339 = ( V_15 >> V_104 ) -
( V_10 -> V_15 >> V_104 ) ;
} else {
V_339 = 0 ;
}
V_329 = F_187 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_116 = V_339 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
if ( ! V_90 ) {
if ( ! F_220 ( V_106 ) )
goto V_343;
} else {
F_87 ( V_106 ) ;
}
V_340 ++ ;
if ( ! F_129 ( V_106 ) )
V_341 = 0 ;
}
if ( V_341 ) {
if ( V_339 == 0 )
F_198 ( V_332 , & V_10 -> V_333 ) ;
goto V_343;
}
for ( V_116 = V_339 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
F_23 ( ! F_122 ( V_106 ) ) ;
F_121 ( V_106 ) ;
if ( V_116 == 0 )
F_126 ( V_106 , V_10 -> V_20 ) ;
if ( V_342 )
F_124 ( V_106 ) ;
if ( ! F_129 ( V_106 ) ) {
if ( V_339 == 0 )
V_342 = 1 ;
F_221 ( V_106 ) ;
V_81 = F_127 ( V_17 , V_106 ,
V_196 , & V_144 ,
V_173 , & V_174 ) ;
if ( V_81 )
V_54 = V_81 ;
} else {
F_85 ( V_106 ) ;
}
}
if ( V_144 )
F_114 ( V_226 , V_144 , V_173 , V_174 ) ;
if ( V_54 || ! V_90 )
return V_54 ;
for ( V_116 = V_339 ; V_116 < V_329 ; V_116 ++ ) {
V_106 = F_183 ( V_10 , V_116 ) ;
F_222 ( V_106 ) ;
if ( ! F_129 ( V_106 ) )
V_54 = - V_344 ;
}
if ( ! V_54 )
F_198 ( V_332 , & V_10 -> V_333 ) ;
return V_54 ;
V_343:
V_116 = V_339 ;
while ( V_340 > 0 ) {
V_106 = F_183 ( V_10 , V_116 ) ;
V_116 ++ ;
F_85 ( V_106 ) ;
V_340 -- ;
}
return V_54 ;
}
void F_223 ( struct V_7 * V_10 , void * V_345 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_346 ;
char * V_347 = ( char * ) V_345 ;
T_6 V_348 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_348 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_183 ( V_10 , V_116 ) ;
V_198 = F_96 ( V_20 , ( V_126 - V_40 ) ) ;
V_346 = F_224 ( V_106 ) ;
memcpy ( V_347 , V_346 + V_40 , V_198 ) ;
V_347 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
int F_225 ( struct V_7 * V_10 , unsigned long V_15 ,
unsigned long V_349 , char * * V_278 ,
unsigned long * V_350 ,
unsigned long * V_351 )
{
T_6 V_40 = V_15 & ( V_126 - 1 ) ;
char * V_346 ;
struct V_106 * V_42 ;
T_6 V_348 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_15 ) >> V_104 ;
unsigned long V_352 = ( V_348 + V_15 + V_349 - 1 ) >>
V_104 ;
if ( V_116 != V_352 )
return - V_301 ;
if ( V_116 == 0 ) {
V_40 = V_348 ;
* V_350 = 0 ;
} else {
V_40 = 0 ;
* V_350 = ( ( T_3 ) V_116 << V_104 ) - V_348 ;
}
if ( V_15 + V_349 > V_10 -> V_20 ) {
F_7 ( V_14 L_12
L_13 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_20 , V_15 , V_349 ) ;
F_23 ( 1 ) ;
return - V_301 ;
}
V_42 = F_183 ( V_10 , V_116 ) ;
V_346 = F_224 ( V_42 ) ;
* V_278 = V_346 + V_40 ;
* V_351 = V_126 - V_40 ;
return 0 ;
}
int F_226 ( struct V_7 * V_10 , const void * V_353 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_346 ;
char * V_354 = ( char * ) V_353 ;
T_6 V_348 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_15 ) >> V_104 ;
int V_54 = 0 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_348 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_183 ( V_10 , V_116 ) ;
V_198 = F_96 ( V_20 , ( V_126 - V_40 ) ) ;
V_346 = F_224 ( V_106 ) ;
V_54 = memcmp ( V_354 , V_346 + V_40 , V_198 ) ;
if ( V_54 )
break;
V_354 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
return V_54 ;
}
void F_227 ( struct V_7 * V_10 , const void * V_355 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_346 ;
char * V_356 = ( char * ) V_355 ;
T_6 V_348 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_348 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_183 ( V_10 , V_116 ) ;
F_23 ( ! F_129 ( V_106 ) ) ;
V_198 = F_96 ( V_20 , V_126 - V_40 ) ;
V_346 = F_224 ( V_106 ) ;
memcpy ( V_346 + V_40 , V_356 , V_198 ) ;
V_356 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
void F_228 ( struct V_7 * V_10 , char V_357 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_346 ;
T_6 V_348 = V_10 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_15 ) >> V_104 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_348 + V_15 ) & ( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_183 ( V_10 , V_116 ) ;
F_23 ( ! F_129 ( V_106 ) ) ;
V_198 = F_96 ( V_20 , V_126 - V_40 ) ;
V_346 = F_224 ( V_106 ) ;
memset ( V_346 + V_40 , V_357 , V_198 ) ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
void F_229 ( struct V_7 * V_347 , struct V_7 * V_356 ,
unsigned long V_358 , unsigned long V_359 ,
unsigned long V_20 )
{
T_3 V_360 = V_347 -> V_20 ;
T_6 V_198 ;
T_6 V_40 ;
struct V_106 * V_106 ;
char * V_346 ;
T_6 V_348 = V_347 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_116 = ( V_348 + V_358 ) >> V_104 ;
F_23 ( V_356 -> V_20 != V_360 ) ;
V_40 = ( V_348 + V_358 ) &
( ( unsigned long ) V_126 - 1 ) ;
while ( V_20 > 0 ) {
V_106 = F_183 ( V_347 , V_116 ) ;
F_23 ( ! F_129 ( V_106 ) ) ;
V_198 = F_96 ( V_20 , ( unsigned long ) ( V_126 - V_40 ) ) ;
V_346 = F_224 ( V_106 ) ;
F_223 ( V_356 , V_346 + V_40 , V_359 , V_198 ) ;
V_359 += V_198 ;
V_20 -= V_198 ;
V_40 = 0 ;
V_116 ++ ;
}
}
static void F_230 ( struct V_106 * V_361 , struct V_106 * V_362 ,
unsigned long V_363 , unsigned long V_364 ,
unsigned long V_20 )
{
char * V_365 = F_224 ( V_361 ) ;
if ( V_361 == V_362 ) {
memmove ( V_365 + V_363 , V_365 + V_364 , V_20 ) ;
} else {
char * V_366 = F_224 ( V_362 ) ;
char * V_42 = V_365 + V_363 + V_20 ;
char * V_367 = V_366 + V_364 + V_20 ;
while ( V_20 -- )
* -- V_42 = * -- V_367 ;
}
}
static inline bool F_231 ( unsigned long V_356 , unsigned long V_347 , unsigned long V_20 )
{
unsigned long V_368 = ( V_356 > V_347 ) ? V_356 - V_347 : V_347 - V_356 ;
return V_368 < V_20 ;
}
static void F_232 ( struct V_106 * V_361 , struct V_106 * V_362 ,
unsigned long V_363 , unsigned long V_364 ,
unsigned long V_20 )
{
char * V_365 = F_224 ( V_361 ) ;
char * V_366 ;
if ( V_361 != V_362 ) {
V_366 = F_224 ( V_362 ) ;
} else {
V_366 = V_365 ;
F_47 ( F_231 ( V_364 , V_363 , V_20 ) ) ;
}
memcpy ( V_365 + V_363 , V_366 + V_364 , V_20 ) ;
}
void F_233 ( struct V_7 * V_347 , unsigned long V_358 ,
unsigned long V_359 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_369 ;
T_6 V_370 ;
T_6 V_348 = V_347 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_371 ;
unsigned long V_372 ;
if ( V_359 + V_20 > V_347 -> V_20 ) {
F_7 ( V_14 L_14
L_15 , V_359 , V_20 , V_347 -> V_20 ) ;
F_47 ( 1 ) ;
}
if ( V_358 + V_20 > V_347 -> V_20 ) {
F_7 ( V_14 L_16
L_15 , V_358 , V_20 , V_347 -> V_20 ) ;
F_47 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_369 = ( V_348 + V_358 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_370 = ( V_348 + V_359 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_371 = ( V_348 + V_358 ) >> V_104 ;
V_372 = ( V_348 + V_359 ) >> V_104 ;
V_198 = F_96 ( V_20 , ( unsigned long ) ( V_126 -
V_370 ) ) ;
V_198 = F_84 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_232 ( F_183 ( V_347 , V_371 ) ,
F_183 ( V_347 , V_372 ) ,
V_369 , V_370 , V_198 ) ;
V_359 += V_198 ;
V_358 += V_198 ;
V_20 -= V_198 ;
}
}
void F_234 ( struct V_7 * V_347 , unsigned long V_358 ,
unsigned long V_359 , unsigned long V_20 )
{
T_6 V_198 ;
T_6 V_369 ;
T_6 V_370 ;
unsigned long V_373 = V_358 + V_20 - 1 ;
unsigned long V_374 = V_359 + V_20 - 1 ;
T_6 V_348 = V_347 -> V_15 & ( ( T_3 ) V_126 - 1 ) ;
unsigned long V_371 ;
unsigned long V_372 ;
if ( V_359 + V_20 > V_347 -> V_20 ) {
F_7 ( V_14 L_14
L_17 , V_359 , V_20 , V_347 -> V_20 ) ;
F_47 ( 1 ) ;
}
if ( V_358 + V_20 > V_347 -> V_20 ) {
F_7 ( V_14 L_16
L_17 , V_358 , V_20 , V_347 -> V_20 ) ;
F_47 ( 1 ) ;
}
if ( ! F_231 ( V_359 , V_358 , V_20 ) ) {
F_233 ( V_347 , V_358 , V_359 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_371 = ( V_348 + V_373 ) >> V_104 ;
V_372 = ( V_348 + V_374 ) >> V_104 ;
V_369 = ( V_348 + V_373 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_370 = ( V_348 + V_374 ) &
( ( unsigned long ) V_126 - 1 ) ;
V_198 = F_84 (unsigned long, len, src_off_in_page + 1 ) ;
V_198 = F_96 ( V_198 , V_369 + 1 ) ;
F_230 ( F_183 ( V_347 , V_371 ) ,
F_183 ( V_347 , V_372 ) ,
V_369 - V_198 + 1 ,
V_370 - V_198 + 1 , V_198 ) ;
V_373 -= V_198 ;
V_374 -= V_198 ;
V_20 -= V_198 ;
}
}
static inline void F_235 ( struct V_375 * V_376 )
{
struct V_7 * V_10 =
F_236 ( V_376 , struct V_7 , V_375 ) ;
F_193 ( V_10 ) ;
}
int F_237 ( struct V_21 * V_17 , struct V_106 * V_106 )
{
T_3 V_15 = F_238 ( V_106 ) ;
struct V_7 * V_10 ;
int V_54 = 1 ;
F_45 ( & V_17 -> V_30 ) ;
V_10 = F_185 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
if ( ! V_10 ) {
F_49 ( & V_17 -> V_30 ) ;
return V_54 ;
}
if ( F_111 ( V_337 , & V_10 -> V_333 ) ) {
V_54 = 0 ;
goto V_88;
}
if ( F_239 ( & V_10 -> V_18 , 1 , 0 ) != 1 ) {
V_54 = 0 ;
goto V_88;
}
F_240 ( & V_17 -> V_25 , V_15 >> V_104 ) ;
V_88:
F_49 ( & V_17 -> V_30 ) ;
if ( F_8 ( & V_10 -> V_18 ) == 0 )
F_241 ( & V_10 -> V_375 , F_235 ) ;
return V_54 ;
}
