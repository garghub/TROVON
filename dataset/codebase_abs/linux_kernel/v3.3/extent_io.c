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
if ( V_9 -> V_16 < V_16 && ! F_47 () )
V_79 = F_29 ( & V_9 -> V_37 ) ;
else
V_79 = NULL ;
if ( ! ( V_9 -> V_9 & V_62 ) )
goto V_12;
if ( V_9 -> V_15 < V_15 ) {
V_70 = F_43 ( V_70 ) ;
F_48 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_15 ) ;
F_48 ( V_81 == - V_66 ) ;
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
F_48 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_16 + 1 ) ;
F_48 ( V_81 == - V_66 ) ;
if ( V_71 )
F_42 ( & V_9 -> V_36 ) ;
V_82 |= F_41 ( V_17 , V_70 , & V_62 , V_71 ) ;
V_70 = NULL ;
goto V_88;
}
V_82 |= F_41 ( V_17 , V_9 , & V_62 , V_71 ) ;
V_12:
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
if ( V_15 <= V_16 && V_79 ) {
V_9 = F_25 ( V_79 , struct V_2 ,
V_37 ) ;
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
F_48 ( ! V_70 ) ;
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
F_48 ( ! V_70 ) ;
V_81 = F_37 ( V_17 , V_70 , V_15 , V_16 , & V_62 ) ;
V_70 = NULL ;
F_48 ( V_81 == - V_66 ) ;
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
if ( V_79 && V_15 < V_16 && V_70 && ! F_47 () ) {
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
F_48 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_15 ) ;
F_48 ( V_81 == - V_66 ) ;
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
F_48 ( ! V_70 ) ;
V_81 = F_37 ( V_17 , V_70 , V_15 , V_97 ,
& V_62 ) ;
F_48 ( V_81 == - V_66 ) ;
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
F_48 ( ! V_70 ) ;
V_81 = F_40 ( V_17 , V_9 , V_70 , V_16 + 1 ) ;
F_48 ( V_81 == - V_66 ) ;
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
int V_62 , int V_98 , T_2 V_31 )
{
struct V_2 * V_9 ;
struct V_2 * V_70 = NULL ;
struct V_37 * V_41 ;
int V_81 = 0 ;
T_3 V_96 ;
T_3 V_80 ;
V_85:
if ( ! V_70 && ( V_31 & V_86 ) ) {
V_70 = F_14 ( V_31 ) ;
if ( ! V_70 )
return - V_5 ;
}
F_45 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_15 ) ;
if ( ! V_41 ) {
V_70 = F_43 ( V_70 ) ;
if ( ! V_70 ) {
V_81 = - V_5 ;
goto V_88;
}
V_81 = F_37 ( V_17 , V_70 , V_15 , V_16 , & V_62 ) ;
V_70 = NULL ;
F_48 ( V_81 == - V_66 ) ;
goto V_88;
}
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
V_87:
V_96 = V_9 -> V_15 ;
V_80 = V_9 -> V_16 ;
if ( V_9 -> V_15 == V_15 && V_9 -> V_16 <= V_16 ) {
struct V_37 * V_79 ;
F_38 ( V_17 , V_9 , & V_62 ) ;
F_41 ( V_17 , V_9 , & V_98 , 0 ) ;
if ( V_80 == ( T_3 ) - 1 )
goto V_88;
V_15 = V_80 + 1 ;
V_79 = F_29 ( & V_9 -> V_37 ) ;
if ( V_79 && V_15 < V_16 && V_70 && ! F_47 () ) {
V_9 = F_25 ( V_79 , struct V_2 ,
V_37 ) ;
if ( V_9 -> V_15 == V_15 )
goto V_87;
}
goto V_89;
}
if ( V_9 -> V_15 < V_15 ) {
V_70 = F_43 ( V_70 ) ;
if ( ! V_70 ) {
V_81 = - V_5 ;
goto V_88;
}
V_81 = F_40 ( V_17 , V_9 , V_70 , V_15 ) ;
F_48 ( V_81 == - V_66 ) ;
V_70 = NULL ;
if ( V_81 )
goto V_88;
if ( V_9 -> V_16 <= V_16 ) {
F_38 ( V_17 , V_9 , & V_62 ) ;
F_41 ( V_17 , V_9 , & V_98 , 0 ) ;
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
if ( ! V_70 ) {
V_81 = - V_5 ;
goto V_88;
}
V_81 = F_37 ( V_17 , V_70 , V_15 , V_97 ,
& V_62 ) ;
F_48 ( V_81 == - V_66 ) ;
if ( V_81 ) {
F_21 ( V_70 ) ;
V_70 = NULL ;
goto V_88;
}
V_70 = NULL ;
V_15 = V_97 + 1 ;
goto V_89;
}
if ( V_9 -> V_15 <= V_16 && V_9 -> V_16 > V_16 ) {
V_70 = F_43 ( V_70 ) ;
if ( ! V_70 ) {
V_81 = - V_5 ;
goto V_88;
}
V_81 = F_40 ( V_17 , V_9 , V_70 , V_16 + 1 ) ;
F_48 ( V_81 == - V_66 ) ;
F_38 ( V_17 , V_70 , & V_62 ) ;
F_41 ( V_17 , V_70 , & V_98 , 0 ) ;
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
int F_63 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_74 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_64 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_62 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_65 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_62 , 0 , 0 , NULL , V_31 ) ;
}
int F_66 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_77 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 ,
V_99 | V_100 ,
0 , NULL , V_77 , V_31 ) ;
}
int F_67 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 ,
V_74 | V_99 |
V_101 , 0 , 0 , NULL , V_31 ) ;
}
int F_68 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_102 , 0 , NULL ,
NULL , V_31 ) ;
}
int F_69 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_77 , T_2 V_31 )
{
return F_61 ( V_17 , V_15 , V_16 , V_100 , 0 ,
NULL , V_77 , V_31 ) ;
}
static int F_70 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 V_16 , struct V_2 * * V_77 ,
T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_100 , 0 , 0 ,
V_77 , V_31 ) ;
}
int F_71 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
int V_62 , struct V_2 * * V_77 , T_2 V_31 )
{
int V_81 ;
T_3 V_95 ;
while ( 1 ) {
V_81 = F_61 ( V_17 , V_15 , V_16 , V_103 | V_62 ,
V_103 , & V_95 ,
V_77 , V_31 ) ;
if ( V_81 == - V_66 && ( V_31 & V_86 ) ) {
F_56 ( V_17 , V_95 , V_16 , V_103 ) ;
V_15 = V_95 ;
} else {
break;
}
F_23 ( V_15 > V_16 ) ;
}
return V_81 ;
}
int F_72 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_71 ( V_17 , V_15 , V_16 , 0 , NULL , V_31 ) ;
}
int F_73 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
T_2 V_31 )
{
int V_81 ;
T_3 V_95 ;
V_81 = F_61 ( V_17 , V_15 , V_16 , V_103 , V_103 ,
& V_95 , NULL , V_31 ) ;
if ( V_81 == - V_66 ) {
if ( V_95 > V_15 )
F_44 ( V_17 , V_15 , V_95 - 1 ,
V_103 , 1 , 0 , NULL , V_31 ) ;
return 0 ;
}
return 1 ;
}
int F_74 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
struct V_2 * * V_78 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_103 , 1 , 0 , V_78 ,
V_31 ) ;
}
int F_75 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 , T_2 V_31 )
{
return F_44 ( V_17 , V_15 , V_16 , V_103 , 1 , 0 , NULL ,
V_31 ) ;
}
static int F_76 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 )
{
unsigned long V_104 = V_15 >> V_105 ;
unsigned long V_106 = V_16 >> V_105 ;
struct V_107 * V_107 ;
while ( V_104 <= V_106 ) {
V_107 = F_77 ( V_17 -> V_23 , V_104 ) ;
F_48 ( ! V_107 ) ;
F_78 ( V_107 ) ;
F_79 ( V_107 ) ;
V_104 ++ ;
}
return 0 ;
}
struct V_2 * F_80 ( struct V_21 * V_17 ,
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
int F_81 ( struct V_21 * V_17 , T_3 V_15 ,
T_3 * V_108 , T_3 * V_109 , int V_62 )
{
struct V_2 * V_9 ;
int V_54 = 1 ;
F_45 ( & V_17 -> V_29 ) ;
V_9 = F_80 ( V_17 , V_15 , V_62 ) ;
if ( V_9 ) {
* V_108 = V_9 -> V_15 ;
* V_109 = V_9 -> V_16 ;
V_54 = 0 ;
}
F_49 ( & V_17 -> V_29 ) ;
return V_54 ;
}
static T_4 T_3 F_82 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 * V_16 , T_3 V_110 ,
struct V_2 * * V_77 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_111 = * V_15 ;
T_3 V_65 = 0 ;
T_3 V_112 = 0 ;
F_45 ( & V_17 -> V_29 ) ;
V_41 = F_31 ( V_17 , V_111 ) ;
if ( ! V_41 ) {
if ( ! V_65 )
* V_16 = ( T_3 ) - 1 ;
goto V_88;
}
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_65 && ( V_9 -> V_15 != V_111 ||
( V_9 -> V_9 & V_61 ) ) ) {
goto V_88;
}
if ( ! ( V_9 -> V_9 & V_99 ) ) {
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
V_111 = V_9 -> V_16 + 1 ;
V_41 = F_29 ( V_41 ) ;
if ( ! V_41 )
break;
V_112 += V_9 -> V_16 - V_9 -> V_15 + 1 ;
if ( V_112 >= V_110 )
break;
}
V_88:
F_49 ( & V_17 -> V_29 ) ;
return V_65 ;
}
static T_4 int F_83 ( struct V_113 * V_113 ,
struct V_107 * V_114 ,
T_3 V_15 , T_3 V_16 )
{
int V_54 ;
struct V_107 * V_115 [ 16 ] ;
unsigned long V_104 = V_15 >> V_105 ;
unsigned long V_106 = V_16 >> V_105 ;
unsigned long V_116 = V_106 - V_104 + 1 ;
int V_117 ;
if ( V_104 == V_114 -> V_104 && V_106 == V_104 )
return 0 ;
while ( V_116 > 0 ) {
V_54 = F_84 ( V_113 -> V_118 , V_104 ,
F_85 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_115 ) ;
for ( V_117 = 0 ; V_117 < V_54 ; V_117 ++ ) {
if ( V_115 [ V_117 ] != V_114 )
F_86 ( V_115 [ V_117 ] ) ;
F_79 ( V_115 [ V_117 ] ) ;
}
V_116 -= V_54 ;
V_104 += V_54 ;
F_50 () ;
}
return 0 ;
}
static T_4 int F_87 ( struct V_113 * V_113 ,
struct V_107 * V_114 ,
T_3 V_119 ,
T_3 V_120 )
{
unsigned long V_104 = V_119 >> V_105 ;
unsigned long V_121 = V_104 ;
unsigned long V_106 = V_120 >> V_105 ;
unsigned long V_122 = 0 ;
struct V_107 * V_115 [ 16 ] ;
unsigned long V_123 ;
int V_54 ;
int V_117 ;
if ( V_104 == V_114 -> V_104 && V_104 == V_106 )
return 0 ;
V_123 = V_106 - V_104 + 1 ;
while ( V_123 > 0 ) {
V_54 = F_84 ( V_113 -> V_118 , V_104 ,
F_85 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_115 ) ;
if ( V_54 == 0 ) {
V_54 = - V_124 ;
goto V_125;
}
for ( V_117 = 0 ; V_117 < V_54 ; V_117 ++ ) {
if ( V_115 [ V_117 ] != V_114 ) {
F_88 ( V_115 [ V_117 ] ) ;
if ( ! F_89 ( V_115 [ V_117 ] ) ||
V_115 [ V_117 ] -> V_23 != V_113 -> V_118 ) {
V_54 = - V_124 ;
F_86 ( V_115 [ V_117 ] ) ;
F_79 ( V_115 [ V_117 ] ) ;
goto V_125;
}
}
F_79 ( V_115 [ V_117 ] ) ;
V_122 ++ ;
}
V_123 -= V_54 ;
V_104 += V_54 ;
F_50 () ;
}
V_54 = 0 ;
V_125:
if ( V_54 && V_122 ) {
F_83 ( V_113 , V_114 ,
V_119 ,
( ( T_3 ) ( V_121 + V_122 - 1 ) ) <<
V_105 ) ;
}
return V_54 ;
}
static T_4 T_3 F_90 ( struct V_113 * V_113 ,
struct V_21 * V_17 ,
struct V_107 * V_114 ,
T_3 * V_15 , T_3 * V_16 ,
T_3 V_110 )
{
T_3 V_119 ;
T_3 V_120 ;
T_3 V_65 ;
struct V_2 * V_77 = NULL ;
int V_54 ;
int V_126 = 0 ;
V_85:
V_119 = * V_15 ;
V_120 = 0 ;
V_65 = F_82 ( V_17 , & V_119 , & V_120 ,
V_110 , & V_77 ) ;
if ( ! V_65 || V_120 <= * V_15 ) {
* V_15 = V_119 ;
* V_16 = V_120 ;
F_21 ( V_77 ) ;
return V_65 ;
}
if ( V_119 < * V_15 )
V_119 = * V_15 ;
if ( V_120 + 1 - V_119 > V_110 && V_126 )
V_120 = V_119 + V_127 - 1 ;
V_54 = F_87 ( V_113 , V_114 ,
V_119 , V_120 ) ;
if ( V_54 == - V_124 ) {
F_21 ( V_77 ) ;
if ( ! V_126 ) {
unsigned long V_40 = ( * V_15 ) & ( V_127 - 1 ) ;
V_110 = V_127 - V_40 ;
V_126 = 1 ;
goto V_85;
} else {
V_65 = 0 ;
goto V_128;
}
}
F_48 ( V_54 ) ;
F_71 ( V_17 , V_119 , V_120 ,
0 , & V_77 , V_129 ) ;
V_54 = F_91 ( V_17 , V_119 , V_120 ,
V_99 , 1 , V_77 ) ;
if ( ! V_54 ) {
F_74 ( V_17 , V_119 , V_120 ,
& V_77 , V_129 ) ;
F_83 ( V_113 , V_114 ,
V_119 , V_120 ) ;
F_50 () ;
goto V_85;
}
F_21 ( V_77 ) ;
* V_15 = V_119 ;
* V_16 = V_120 ;
V_128:
return V_65 ;
}
int F_92 ( struct V_113 * V_113 ,
struct V_21 * V_17 ,
T_3 V_15 , T_3 V_16 , struct V_107 * V_114 ,
unsigned long V_130 )
{
int V_54 ;
struct V_107 * V_115 [ 16 ] ;
unsigned long V_104 = V_15 >> V_105 ;
unsigned long V_106 = V_16 >> V_105 ;
unsigned long V_116 = V_106 - V_104 + 1 ;
int V_117 ;
int V_98 = 0 ;
if ( V_130 & V_131 )
V_98 |= V_103 ;
if ( V_130 & V_132 )
V_98 |= V_74 ;
if ( V_130 & V_133 )
V_98 |= V_99 ;
F_44 ( V_17 , V_15 , V_16 , V_98 , 1 , 0 , NULL , V_129 ) ;
if ( ! ( V_130 & ( V_134 | V_132 |
V_135 | V_136 |
V_137 ) ) )
return 0 ;
while ( V_116 > 0 ) {
V_54 = F_84 ( V_113 -> V_118 , V_104 ,
F_85 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_115 ) ;
for ( V_117 = 0 ; V_117 < V_54 ; V_117 ++ ) {
if ( V_130 & V_137 )
F_93 ( V_115 [ V_117 ] ) ;
if ( V_115 [ V_117 ] == V_114 ) {
F_79 ( V_115 [ V_117 ] ) ;
continue;
}
if ( V_130 & V_132 )
F_94 ( V_115 [ V_117 ] ) ;
if ( V_130 & V_135 )
F_78 ( V_115 [ V_117 ] ) ;
if ( V_130 & V_136 )
F_95 ( V_115 [ V_117 ] ) ;
if ( V_130 & V_134 )
F_86 ( V_115 [ V_117 ] ) ;
F_79 ( V_115 [ V_117 ] ) ;
}
V_116 -= V_54 ;
V_104 += V_54 ;
F_50 () ;
}
return 0 ;
}
T_3 F_96 ( struct V_21 * V_17 ,
T_3 * V_15 , T_3 V_138 , T_3 V_110 ,
unsigned long V_62 , int V_139 )
{
struct V_37 * V_41 ;
struct V_2 * V_9 ;
T_3 V_111 = * V_15 ;
T_3 V_112 = 0 ;
T_3 V_140 = 0 ;
int V_65 = 0 ;
if ( V_138 <= V_111 ) {
F_23 ( 1 ) ;
return 0 ;
}
F_45 ( & V_17 -> V_29 ) ;
if ( V_111 == 0 && V_62 == V_74 ) {
V_112 = V_17 -> V_28 ;
goto V_88;
}
V_41 = F_31 ( V_17 , V_111 ) ;
if ( ! V_41 )
goto V_88;
while ( 1 ) {
V_9 = F_25 ( V_41 , struct V_2 , V_37 ) ;
if ( V_9 -> V_15 > V_138 )
break;
if ( V_139 && V_65 && V_9 -> V_15 > V_140 + 1 )
break;
if ( V_9 -> V_16 >= V_111 && ( V_9 -> V_9 & V_62 ) == V_62 ) {
V_112 += F_97 ( V_138 , V_9 -> V_16 ) + 1 -
F_98 ( V_111 , V_9 -> V_15 ) ;
if ( V_112 >= V_110 )
break;
if ( ! V_65 ) {
* V_15 = F_98 ( V_111 , V_9 -> V_15 ) ;
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
return V_112 ;
}
int F_99 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_34 )
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
int F_100 ( struct V_21 * V_17 , T_3 V_15 , T_3 * V_34 )
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
int F_91 ( struct V_21 * V_17 , T_3 V_15 , T_3 V_16 ,
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
static int F_101 ( struct V_21 * V_17 ,
struct V_107 * V_107 )
{
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_16 = V_15 + V_127 - 1 ;
if ( F_91 ( V_17 , V_15 , V_16 , V_100 , 1 , NULL ) )
F_102 ( V_107 ) ;
return 0 ;
}
static int F_103 ( struct V_21 * V_17 ,
struct V_107 * V_107 )
{
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_16 = V_15 + V_127 - 1 ;
if ( ! F_91 ( V_17 , V_15 , V_16 , V_103 , 0 , NULL ) )
F_86 ( V_107 ) ;
return 0 ;
}
static int F_104 ( struct V_21 * V_17 ,
struct V_107 * V_107 )
{
F_95 ( V_107 ) ;
return 0 ;
}
static int F_105 ( struct V_113 * V_113 , struct V_144 * V_145 ,
int V_146 )
{
int V_54 ;
int V_81 = 0 ;
struct V_21 * V_147 = & F_106 ( V_113 ) -> V_148 ;
F_99 ( V_147 , V_145 -> V_15 , 0 ) ;
V_54 = F_65 ( V_147 , V_145 -> V_15 ,
V_145 -> V_15 + V_145 -> V_20 - 1 ,
V_103 | V_74 , V_129 ) ;
if ( V_54 )
V_81 = V_54 ;
if ( V_146 ) {
V_54 = F_65 ( & F_106 ( V_113 ) -> V_149 , V_145 -> V_15 ,
V_145 -> V_15 + V_145 -> V_20 - 1 ,
V_150 , V_129 ) ;
if ( V_54 && ! V_81 )
V_81 = V_54 ;
}
F_107 ( V_145 ) ;
return V_81 ;
}
static void F_108 ( struct V_151 * V_151 , int V_81 )
{
F_109 ( V_151 -> V_152 ) ;
}
int F_110 ( struct V_153 * V_154 , T_3 V_15 ,
T_3 V_155 , T_3 V_156 , struct V_107 * V_107 ,
int V_157 )
{
struct V_151 * V_151 ;
struct V_158 * V_159 ;
F_111 ( V_160 ) ;
T_3 V_161 = 0 ;
T_3 V_162 ;
struct V_163 * V_164 = NULL ;
int V_54 ;
F_48 ( ! V_157 ) ;
V_151 = F_112 ( V_129 , 1 ) ;
if ( ! V_151 )
return - V_165 ;
V_151 -> V_152 = & V_160 ;
V_151 -> V_166 = F_108 ;
V_151 -> V_167 = 0 ;
V_161 = V_155 ;
V_54 = F_113 ( V_154 , V_168 , V_156 ,
& V_161 , & V_164 , V_157 ) ;
if ( V_54 ) {
F_114 ( V_151 ) ;
return - V_165 ;
}
F_48 ( V_157 != V_164 -> V_157 ) ;
V_162 = V_164 -> V_169 [ V_157 - 1 ] . V_170 >> 9 ;
V_151 -> V_171 = V_162 ;
V_159 = V_164 -> V_169 [ V_157 - 1 ] . V_159 ;
F_107 ( V_164 ) ;
if ( ! V_159 || ! V_159 -> V_172 || ! V_159 -> V_173 ) {
F_114 ( V_151 ) ;
return - V_165 ;
}
V_151 -> V_174 = V_159 -> V_172 ;
F_115 ( V_151 , V_107 , V_155 , V_15 - F_116 ( V_107 ) ) ;
F_117 ( V_175 , V_151 ) ;
F_118 ( & V_160 ) ;
if ( ! F_119 ( V_176 , & V_151 -> V_177 ) ) {
F_114 ( V_151 ) ;
return - V_165 ;
}
F_7 ( V_178 L_10
L_11 , V_107 -> V_23 -> V_58 -> V_179 , V_15 ,
V_159 -> V_180 , V_162 ) ;
F_114 ( V_151 ) ;
return 0 ;
}
static int F_120 ( T_3 V_15 , struct V_107 * V_107 )
{
T_3 V_34 ;
T_3 V_181 ;
struct V_144 * V_182 ;
struct V_153 * V_154 ;
struct V_2 * V_9 ;
int V_183 ;
int V_146 = 0 ;
int V_54 ;
struct V_113 * V_113 = V_107 -> V_23 -> V_58 ;
V_34 = 0 ;
V_54 = F_96 ( & F_106 ( V_113 ) -> V_148 , & V_34 ,
( T_3 ) - 1 , 1 , V_74 , 0 ) ;
if ( ! V_54 )
return 0 ;
V_54 = F_100 ( & F_106 ( V_113 ) -> V_148 , V_15 ,
& V_181 ) ;
if ( V_54 )
return 0 ;
V_182 = (struct V_144 * ) ( unsigned long ) V_181 ;
F_48 ( ! V_182 -> V_184 ) ;
if ( V_182 -> V_185 ) {
F_121 ( L_12 ,
V_182 -> V_15 ) ;
V_146 = 1 ;
goto V_88;
}
F_45 ( & F_106 ( V_113 ) -> V_149 . V_29 ) ;
V_9 = F_80 ( & F_106 ( V_113 ) -> V_149 ,
V_182 -> V_15 ,
V_103 ) ;
F_49 ( & F_106 ( V_113 ) -> V_149 . V_29 ) ;
if ( V_9 && V_9 -> V_15 == V_182 -> V_15 ) {
V_154 = & F_106 ( V_113 ) -> V_39 -> V_186 -> V_187 ;
V_183 = F_122 ( V_154 , V_182 -> V_156 ,
V_182 -> V_20 ) ;
if ( V_183 > 1 ) {
V_54 = F_110 ( V_154 , V_15 , V_182 -> V_20 ,
V_182 -> V_156 , V_107 ,
V_182 -> V_188 ) ;
V_146 = ! V_54 ;
}
}
V_88:
if ( ! V_54 )
V_54 = F_105 ( V_113 , V_182 , V_146 ) ;
return V_54 ;
}
static int F_123 ( struct V_151 * V_189 , struct V_107 * V_107 ,
T_3 V_15 , T_3 V_16 , int V_188 ,
struct V_2 * V_9 )
{
struct V_144 * V_182 = NULL ;
T_3 V_34 ;
struct V_190 * V_191 ;
struct V_113 * V_113 = V_107 -> V_23 -> V_58 ;
struct V_21 * V_147 = & F_106 ( V_113 ) -> V_148 ;
struct V_21 * V_17 = & F_106 ( V_113 ) -> V_149 ;
struct V_192 * V_193 = & F_106 ( V_113 ) -> V_194 ;
struct V_151 * V_151 ;
int V_183 ;
int V_54 ;
int V_195 ;
T_3 V_156 ;
F_48 ( V_189 -> V_196 & V_197 ) ;
V_54 = F_100 ( V_147 , V_15 , & V_34 ) ;
if ( V_54 ) {
V_182 = F_124 ( sizeof( * V_182 ) , V_129 ) ;
if ( ! V_182 )
return - V_5 ;
V_182 -> V_15 = V_15 ;
V_182 -> V_20 = V_16 - V_15 + 1 ;
V_182 -> V_184 = 0 ;
V_182 -> V_198 = 0 ;
V_182 -> V_185 = 0 ;
F_125 ( & V_193 -> V_29 ) ;
V_191 = F_126 ( V_193 , V_15 , V_182 -> V_20 ) ;
if ( ! V_191 ) {
F_127 ( & V_193 -> V_29 ) ;
F_107 ( V_182 ) ;
return - V_165 ;
}
if ( V_191 -> V_15 > V_15 || V_191 -> V_15 + V_191 -> V_20 < V_15 ) {
F_128 ( V_191 ) ;
V_191 = NULL ;
}
F_127 ( & V_193 -> V_29 ) ;
if ( ! V_191 || F_129 ( V_191 ) ) {
F_107 ( V_182 ) ;
return - V_165 ;
}
V_156 = V_15 - V_191 -> V_15 ;
V_156 = V_191 -> V_199 + V_156 ;
if ( F_119 ( V_200 , & V_191 -> V_33 ) ) {
V_156 = V_191 -> V_199 ;
V_182 -> V_198 = V_201 ;
F_130 ( & V_182 -> V_198 ,
V_191 -> V_202 ) ;
}
F_121 ( L_13
L_14 , V_156 , V_15 , V_182 -> V_20 ) ;
V_182 -> V_156 = V_156 ;
F_128 ( V_191 ) ;
V_54 = F_64 ( V_147 , V_15 , V_16 ,
V_103 | V_74 , V_129 ) ;
if ( V_54 >= 0 )
V_54 = F_99 ( V_147 , V_15 ,
( T_3 ) ( unsigned long ) V_182 ) ;
if ( V_54 >= 0 )
V_54 = F_64 ( V_17 , V_15 , V_16 , V_150 ,
V_129 ) ;
if ( V_54 < 0 ) {
F_107 ( V_182 ) ;
return V_54 ;
}
} else {
V_182 = (struct V_144 * ) ( unsigned long ) V_34 ;
F_121 ( L_15
L_16 ,
V_182 -> V_156 , V_182 -> V_15 , V_182 -> V_20 ,
V_182 -> V_185 ) ;
}
V_183 = F_122 (
& F_106 ( V_113 ) -> V_39 -> V_186 -> V_187 ,
V_182 -> V_156 , V_182 -> V_20 ) ;
if ( V_183 == 1 ) {
F_121 ( L_17
L_18
L_19 , V_9 , V_183 ,
V_182 -> V_184 , V_188 ) ;
F_105 ( V_113 , V_182 , 0 ) ;
return - V_165 ;
}
if ( ! V_9 ) {
F_45 ( & V_17 -> V_29 ) ;
V_9 = F_80 ( V_17 , V_182 -> V_15 ,
V_103 ) ;
if ( V_9 && V_9 -> V_15 != V_182 -> V_15 )
V_9 = NULL ;
F_49 ( & V_17 -> V_29 ) ;
}
if ( V_189 -> V_203 > 1 ) {
F_48 ( V_182 -> V_185 ) ;
V_182 -> V_185 = 1 ;
V_182 -> V_184 = V_188 ;
V_195 = V_204 | V_205 ;
} else {
if ( V_182 -> V_185 ) {
F_48 ( V_182 -> V_184 != V_188 ) ;
V_182 -> V_185 = 0 ;
V_182 -> V_184 = 0 ;
}
V_182 -> V_188 = V_188 ;
V_182 -> V_184 ++ ;
if ( V_182 -> V_184 == V_188 )
V_182 -> V_184 ++ ;
V_195 = V_204 ;
}
if ( ! V_9 || V_182 -> V_184 > V_183 ) {
F_121 ( L_20
L_21 , V_9 ,
V_183 , V_182 -> V_184 , V_188 ) ;
F_105 ( V_113 , V_182 , 0 ) ;
return - V_165 ;
}
V_151 = F_112 ( V_129 , 1 ) ;
V_151 -> V_152 = V_9 ;
V_151 -> V_166 = V_189 -> V_166 ;
V_151 -> V_171 = V_182 -> V_156 >> 9 ;
V_151 -> V_174 = F_106 ( V_113 ) -> V_39 -> V_186 -> V_206 -> V_207 ;
V_151 -> V_167 = 0 ;
F_115 ( V_151 , V_107 , V_182 -> V_20 , V_15 - F_116 ( V_107 ) ) ;
F_121 ( L_22
L_23 , V_195 ,
V_182 -> V_184 , V_183 , V_182 -> V_185 ) ;
V_54 = V_17 -> V_27 -> V_208 ( V_113 , V_195 , V_151 ,
V_182 -> V_184 ,
V_182 -> V_198 , 0 ) ;
return V_54 ;
}
int F_131 ( struct V_107 * V_107 , int V_81 , T_3 V_15 , T_3 V_16 )
{
int V_209 = ( V_81 == 0 ) ;
struct V_21 * V_17 ;
int V_54 ;
V_17 = & F_106 ( V_107 -> V_23 -> V_58 ) -> V_149 ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_210 ) {
V_54 = V_17 -> V_27 -> V_210 ( V_107 , V_15 ,
V_16 , NULL , V_209 ) ;
if ( V_54 )
V_209 = 0 ;
}
if ( ! V_209 && V_17 -> V_27 &&
V_17 -> V_27 -> V_211 ) {
V_54 = V_17 -> V_27 -> V_211 ( NULL , V_107 ,
V_15 , V_16 , NULL ) ;
if ( V_54 == 0 )
return 1 ;
}
if ( ! V_209 ) {
F_70 ( V_17 , V_15 , V_16 , NULL , V_129 ) ;
F_132 ( V_107 ) ;
F_133 ( V_107 ) ;
}
return 0 ;
}
static void F_134 ( struct V_151 * V_151 , int V_81 )
{
struct V_212 * V_213 = V_151 -> V_214 + V_151 -> V_203 - 1 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_215 ;
do {
struct V_107 * V_107 = V_213 -> V_216 ;
V_17 = & F_106 ( V_107 -> V_23 -> V_58 ) -> V_149 ;
V_15 = ( ( T_3 ) V_107 -> V_104 << V_105 ) +
V_213 -> V_217 ;
V_16 = V_15 + V_213 -> V_218 - 1 ;
if ( V_213 -> V_217 == 0 && V_213 -> V_218 == V_127 )
V_215 = 1 ;
else
V_215 = 0 ;
if ( -- V_213 >= V_151 -> V_214 )
F_135 ( & V_213 -> V_216 -> V_33 ) ;
if ( F_131 ( V_107 , V_81 , V_15 , V_16 ) )
continue;
if ( V_215 )
F_95 ( V_107 ) ;
else
F_104 ( V_17 , V_107 ) ;
} while ( V_213 >= V_151 -> V_214 );
F_114 ( V_151 ) ;
}
static void F_136 ( struct V_151 * V_151 , int V_81 )
{
int V_209 = F_119 ( V_176 , & V_151 -> V_177 ) ;
struct V_212 * V_219 = V_151 -> V_214 + V_151 -> V_203 - 1 ;
struct V_212 * V_213 = V_151 -> V_214 ;
struct V_21 * V_17 ;
T_3 V_15 ;
T_3 V_16 ;
int V_215 ;
int V_54 ;
if ( V_81 )
V_209 = 0 ;
do {
struct V_107 * V_107 = V_213 -> V_216 ;
struct V_2 * V_78 = NULL ;
struct V_2 * V_9 ;
F_121 ( L_24
L_25 , V_151 -> V_203 , V_151 -> V_220 , V_81 ,
( long int ) V_151 -> V_174 ) ;
V_17 = & F_106 ( V_107 -> V_23 -> V_58 ) -> V_149 ;
V_15 = ( ( T_3 ) V_107 -> V_104 << V_105 ) +
V_213 -> V_217 ;
V_16 = V_15 + V_213 -> V_218 - 1 ;
if ( V_213 -> V_217 == 0 && V_213 -> V_218 == V_127 )
V_215 = 1 ;
else
V_215 = 0 ;
if ( ++ V_213 <= V_219 )
F_135 ( & V_213 -> V_216 -> V_33 ) ;
F_45 ( & V_17 -> V_29 ) ;
V_9 = F_80 ( V_17 , V_15 , V_103 ) ;
if ( V_9 && V_9 -> V_15 == V_15 ) {
F_59 ( V_9 , & V_78 ) ;
}
F_49 ( & V_17 -> V_29 ) ;
if ( V_209 && V_17 -> V_27 && V_17 -> V_27 -> V_221 ) {
V_54 = V_17 -> V_27 -> V_221 ( V_107 , V_15 , V_16 ,
V_9 ) ;
if ( V_54 )
V_209 = 0 ;
else
F_120 ( V_15 , V_107 ) ;
}
if ( ! V_209 ) {
int V_188 ;
V_188 = ( int ) ( unsigned long ) V_151 -> V_174 ;
V_54 = F_123 ( V_151 , V_107 , V_15 , V_16 ,
V_188 , NULL ) ;
if ( V_54 == 0 ) {
V_222:
V_209 =
F_119 ( V_176 , & V_151 -> V_177 ) ;
if ( V_81 )
V_209 = 0 ;
F_60 ( & V_78 ) ;
continue;
}
if ( V_17 -> V_27 && V_17 -> V_27 -> V_223 ) {
V_54 = V_17 -> V_27 -> V_223 (
V_151 , V_107 , V_15 , V_16 ,
V_188 , V_9 ) ;
if ( V_54 == 0 )
goto V_222;
}
}
if ( V_209 ) {
F_69 ( V_17 , V_15 , V_16 , & V_78 ,
V_26 ) ;
}
F_74 ( V_17 , V_15 , V_16 , & V_78 , V_26 ) ;
if ( V_215 ) {
if ( V_209 ) {
F_102 ( V_107 ) ;
} else {
F_132 ( V_107 ) ;
F_133 ( V_107 ) ;
}
F_86 ( V_107 ) ;
} else {
if ( V_209 ) {
F_101 ( V_17 , V_107 ) ;
} else {
F_132 ( V_107 ) ;
F_133 ( V_107 ) ;
}
F_103 ( V_17 , V_107 ) ;
}
} while ( V_213 <= V_219 );
F_114 ( V_151 ) ;
}
struct V_151 *
F_137 ( struct V_224 * V_172 , T_3 V_225 , int V_226 ,
T_2 V_227 )
{
struct V_151 * V_151 ;
V_151 = F_112 ( V_227 , V_226 ) ;
if ( V_151 == NULL && ( V_228 -> V_33 & V_229 ) ) {
while ( ! V_151 && ( V_226 /= 2 ) )
V_151 = F_112 ( V_227 , V_226 ) ;
}
if ( V_151 ) {
V_151 -> V_167 = 0 ;
V_151 -> V_174 = V_172 ;
V_151 -> V_171 = V_225 ;
}
return V_151 ;
}
static int F_138 ( int V_230 , struct V_151 * V_151 , int V_157 ,
unsigned long V_198 )
{
int V_54 = 0 ;
struct V_212 * V_213 = V_151 -> V_214 + V_151 -> V_203 - 1 ;
struct V_107 * V_107 = V_213 -> V_216 ;
struct V_21 * V_17 = V_151 -> V_152 ;
T_3 V_15 ;
V_15 = ( ( T_3 ) V_107 -> V_104 << V_105 ) + V_213 -> V_217 ;
V_151 -> V_152 = NULL ;
F_139 ( V_151 ) ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_208 )
V_54 = V_17 -> V_27 -> V_208 ( V_107 -> V_23 -> V_58 , V_230 , V_151 ,
V_157 , V_198 , V_15 ) ;
else
F_117 ( V_230 , V_151 ) ;
if ( F_140 ( V_151 , V_231 ) )
V_54 = - V_232 ;
F_114 ( V_151 ) ;
return V_54 ;
}
static int F_141 ( int V_230 , struct V_21 * V_17 ,
struct V_107 * V_107 , T_5 V_162 ,
T_6 V_233 , unsigned long V_40 ,
struct V_224 * V_172 ,
struct V_151 * * V_234 ,
unsigned long V_235 ,
T_7 V_236 ,
int V_157 ,
unsigned long V_237 ,
unsigned long V_198 )
{
int V_54 = 0 ;
struct V_151 * V_151 ;
int V_238 ;
int V_139 = 0 ;
int V_239 = V_198 & V_201 ;
int V_240 = V_237 & V_201 ;
T_6 V_241 = F_85 ( T_6 , V_233 , V_127 ) ;
if ( V_234 && * V_234 ) {
V_151 = * V_234 ;
if ( V_240 )
V_139 = V_151 -> V_171 == V_162 ;
else
V_139 = V_151 -> V_171 + ( V_151 -> V_167 >> 9 ) ==
V_162 ;
if ( V_237 != V_198 || ! V_139 ||
( V_17 -> V_27 && V_17 -> V_27 -> V_242 &&
V_17 -> V_27 -> V_242 ( V_107 , V_40 , V_241 , V_151 ,
V_198 ) ) ||
F_115 ( V_151 , V_107 , V_241 , V_40 ) < V_241 ) {
V_54 = F_138 ( V_230 , V_151 , V_157 ,
V_237 ) ;
V_151 = NULL ;
} else {
return 0 ;
}
}
if ( V_239 )
V_238 = V_243 ;
else
V_238 = F_142 ( V_172 ) ;
V_151 = F_137 ( V_172 , V_162 , V_238 , V_129 | V_244 ) ;
if ( ! V_151 )
return - V_5 ;
F_115 ( V_151 , V_107 , V_241 , V_40 ) ;
V_151 -> V_166 = V_236 ;
V_151 -> V_152 = V_17 ;
if ( V_234 )
* V_234 = V_151 ;
else
V_54 = F_138 ( V_230 , V_151 , V_157 , V_198 ) ;
return V_54 ;
}
void F_143 ( struct V_107 * V_107 )
{
if ( ! F_144 ( V_107 ) ) {
F_145 ( V_107 ) ;
F_146 ( V_107 ) ;
F_147 ( V_107 , V_245 ) ;
}
}
static void F_148 ( struct V_107 * V_107 , unsigned long V_20 )
{
F_23 ( ! F_144 ( V_107 ) ) ;
F_147 ( V_107 , V_246 | V_20 << 2 ) ;
}
static int F_149 ( struct V_21 * V_17 ,
struct V_107 * V_107 ,
T_8 * V_247 ,
struct V_151 * * V_151 , int V_157 ,
unsigned long * V_198 )
{
struct V_113 * V_113 = V_107 -> V_23 -> V_58 ;
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_248 = V_15 + V_127 - 1 ;
T_3 V_16 ;
T_3 V_249 = V_15 ;
T_3 V_250 ;
T_3 V_251 = F_150 ( V_113 ) ;
T_3 V_199 ;
T_3 V_252 ;
T_5 V_162 ;
struct V_190 * V_191 ;
struct V_224 * V_172 ;
struct V_253 * V_254 ;
int V_54 ;
int V_238 = 0 ;
T_6 V_255 = 0 ;
T_6 V_256 ;
T_6 V_257 ;
T_6 V_258 = V_113 -> V_259 -> V_260 ;
unsigned long V_261 = 0 ;
F_143 ( V_107 ) ;
if ( ! F_151 ( V_107 ) ) {
if ( F_152 ( V_107 ) == 0 ) {
F_48 ( V_258 != V_262 ) ;
goto V_88;
}
}
V_16 = V_248 ;
while ( 1 ) {
F_72 ( V_17 , V_15 , V_16 , V_129 ) ;
V_254 = F_153 ( V_113 , V_15 ) ;
if ( ! V_254 )
break;
F_75 ( V_17 , V_15 , V_16 , V_129 ) ;
F_154 ( V_113 , V_254 , 1 ) ;
F_155 ( V_254 ) ;
}
if ( V_107 -> V_104 == V_251 >> V_105 ) {
char * V_263 ;
T_6 V_264 = V_251 & ( V_127 - 1 ) ;
if ( V_264 ) {
V_256 = V_127 - V_264 ;
V_263 = F_156 ( V_107 , V_265 ) ;
memset ( V_263 + V_264 , 0 , V_256 ) ;
F_157 ( V_107 ) ;
F_158 ( V_263 , V_265 ) ;
}
}
while ( V_249 <= V_16 ) {
if ( V_249 >= V_251 ) {
char * V_263 ;
struct V_2 * V_78 = NULL ;
V_256 = V_127 - V_255 ;
V_263 = F_156 ( V_107 , V_265 ) ;
memset ( V_263 + V_255 , 0 , V_256 ) ;
F_157 ( V_107 ) ;
F_158 ( V_263 , V_265 ) ;
F_69 ( V_17 , V_249 , V_249 + V_256 - 1 ,
& V_78 , V_129 ) ;
F_74 ( V_17 , V_249 , V_249 + V_256 - 1 ,
& V_78 , V_129 ) ;
break;
}
V_191 = V_247 ( V_113 , V_107 , V_255 , V_249 ,
V_16 - V_249 + 1 , 0 ) ;
if ( F_159 ( V_191 ) ) {
F_133 ( V_107 ) ;
F_75 ( V_17 , V_249 , V_16 , V_129 ) ;
break;
}
V_250 = V_249 - V_191 -> V_15 ;
F_48 ( F_160 ( V_191 ) <= V_249 ) ;
F_48 ( V_16 < V_249 ) ;
if ( F_119 ( V_200 , & V_191 -> V_33 ) ) {
V_261 = V_201 ;
F_130 ( & V_261 ,
V_191 -> V_202 ) ;
}
V_256 = F_97 ( F_160 ( V_191 ) - V_249 , V_16 - V_249 + 1 ) ;
V_252 = F_97 ( F_160 ( V_191 ) - 1 , V_16 ) ;
V_256 = ( V_256 + V_258 - 1 ) & ~ ( ( T_3 ) V_258 - 1 ) ;
if ( V_261 & V_201 ) {
V_257 = V_191 -> V_266 ;
V_162 = V_191 -> V_199 >> 9 ;
} else {
V_162 = ( V_191 -> V_199 + V_250 ) >> 9 ;
V_257 = V_256 ;
}
V_172 = V_191 -> V_172 ;
V_199 = V_191 -> V_199 ;
if ( F_119 ( V_267 , & V_191 -> V_33 ) )
V_199 = V_268 ;
F_128 ( V_191 ) ;
V_191 = NULL ;
if ( V_199 == V_268 ) {
char * V_263 ;
struct V_2 * V_78 = NULL ;
V_263 = F_156 ( V_107 , V_265 ) ;
memset ( V_263 + V_255 , 0 , V_256 ) ;
F_157 ( V_107 ) ;
F_158 ( V_263 , V_265 ) ;
F_69 ( V_17 , V_249 , V_249 + V_256 - 1 ,
& V_78 , V_129 ) ;
F_74 ( V_17 , V_249 , V_249 + V_256 - 1 ,
& V_78 , V_129 ) ;
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
continue;
}
if ( F_91 ( V_17 , V_249 , V_252 ,
V_100 , 1 , NULL ) ) {
F_101 ( V_17 , V_107 ) ;
F_75 ( V_17 , V_249 , V_249 + V_256 - 1 , V_129 ) ;
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
continue;
}
if ( V_199 == V_269 ) {
F_133 ( V_107 ) ;
F_75 ( V_17 , V_249 , V_249 + V_256 - 1 , V_129 ) ;
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
continue;
}
V_54 = 0 ;
if ( V_17 -> V_27 && V_17 -> V_27 -> V_270 ) {
V_54 = V_17 -> V_27 -> V_270 ( V_107 , V_249 ,
V_249 + V_256 - 1 ) ;
}
if ( ! V_54 ) {
unsigned long V_271 = ( V_251 >> V_105 ) + 1 ;
V_271 -= V_107 -> V_104 ;
V_54 = F_141 ( V_272 , V_17 , V_107 ,
V_162 , V_257 , V_255 ,
V_172 , V_151 , V_271 ,
F_136 , V_157 ,
* V_198 ,
V_261 ) ;
V_238 ++ ;
* V_198 = V_261 ;
}
if ( V_54 )
F_133 ( V_107 ) ;
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
}
V_88:
if ( ! V_238 ) {
if ( ! F_161 ( V_107 ) )
F_102 ( V_107 ) ;
F_86 ( V_107 ) ;
}
return 0 ;
}
int F_162 ( struct V_21 * V_17 , struct V_107 * V_107 ,
T_8 * V_247 , int V_157 )
{
struct V_151 * V_151 = NULL ;
unsigned long V_198 = 0 ;
int V_54 ;
V_54 = F_149 ( V_17 , V_107 , V_247 , & V_151 , V_157 ,
& V_198 ) ;
if ( V_151 )
V_54 = F_138 ( V_272 , V_151 , V_157 , V_198 ) ;
return V_54 ;
}
static T_4 void F_163 ( struct V_107 * V_107 ,
struct V_273 * V_274 ,
unsigned long V_275 )
{
V_274 -> V_276 -= V_275 ;
if ( V_274 -> V_277 || ( V_274 -> V_276 > 0 &&
V_274 -> V_278 == 0 && V_274 -> V_279 == V_280 ) )
V_107 -> V_23 -> V_281 = V_107 -> V_104 + V_275 ;
}
static int F_164 ( struct V_107 * V_107 , struct V_273 * V_274 ,
void * V_282 )
{
struct V_113 * V_113 = V_107 -> V_23 -> V_58 ;
struct V_283 * V_284 = V_282 ;
struct V_21 * V_17 = V_284 -> V_17 ;
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_119 ;
T_3 V_248 = V_15 + V_127 - 1 ;
T_3 V_16 ;
T_3 V_249 = V_15 ;
T_3 V_250 ;
T_3 V_251 = F_150 ( V_113 ) ;
T_3 V_199 ;
T_3 V_256 ;
T_5 V_162 ;
struct V_2 * V_77 = NULL ;
struct V_190 * V_191 ;
struct V_224 * V_172 ;
int V_54 ;
int V_238 = 0 ;
T_6 V_255 = 0 ;
T_6 V_258 ;
T_9 V_285 = F_150 ( V_113 ) ;
unsigned long V_106 = V_285 >> V_105 ;
T_3 V_286 ;
T_3 V_120 ;
int V_287 ;
int V_288 ;
int V_289 ;
unsigned long V_275 = 0 ;
bool V_290 = true ;
if ( V_274 -> V_291 == V_292 )
V_289 = V_175 ;
else
V_289 = V_168 ;
F_165 ( V_107 , V_113 , V_274 ) ;
F_23 ( ! F_166 ( V_107 ) ) ;
F_167 ( V_107 ) ;
V_255 = V_285 & ( V_127 - 1 ) ;
if ( V_107 -> V_104 > V_106 ||
( V_107 -> V_104 == V_106 && ! V_255 ) ) {
V_107 -> V_23 -> V_293 -> V_294 ( V_107 , 0 ) ;
F_86 ( V_107 ) ;
return 0 ;
}
if ( V_107 -> V_104 == V_106 ) {
char * V_263 ;
V_263 = F_156 ( V_107 , V_265 ) ;
memset ( V_263 + V_255 , 0 ,
V_127 - V_255 ) ;
F_158 ( V_263 , V_265 ) ;
F_157 ( V_107 ) ;
}
V_255 = 0 ;
F_143 ( V_107 ) ;
if ( ! V_17 -> V_27 || ! V_17 -> V_27 -> V_290 )
V_290 = false ;
V_119 = V_15 ;
V_120 = 0 ;
V_287 = 0 ;
if ( ! V_284 -> V_295 && V_290 ) {
T_3 V_296 = 0 ;
F_163 ( V_107 , V_274 , 0 ) ;
while ( V_120 < V_248 ) {
V_286 = F_90 ( V_113 , V_17 ,
V_107 ,
& V_119 ,
& V_120 ,
128 * 1024 * 1024 ) ;
if ( V_286 == 0 ) {
V_119 = V_120 + 1 ;
continue;
}
V_54 = V_17 -> V_27 -> V_290 ( V_113 , V_107 ,
V_119 ,
V_120 ,
& V_287 ,
& V_275 ) ;
F_48 ( V_54 ) ;
V_296 += ( V_120 - V_119 +
V_127 ) >>
V_105 ;
V_119 = V_120 + 1 ;
}
if ( V_274 -> V_276 < V_296 ) {
int V_297 = 8192 ;
if ( V_296 < V_297 * 2 )
V_297 = V_296 ;
V_274 -> V_276 = F_85 ( T_3 , V_296 ,
V_297 ) ;
}
if ( V_287 ) {
V_54 = 0 ;
V_274 -> V_276 -= V_275 ;
goto V_298;
}
}
if ( V_17 -> V_27 && V_17 -> V_27 -> V_299 ) {
V_54 = V_17 -> V_27 -> V_299 ( V_107 , V_15 ,
V_248 ) ;
if ( V_54 ) {
if ( V_54 == - V_300 )
V_274 -> V_301 ++ ;
else
F_168 ( V_274 , V_107 ) ;
F_163 ( V_107 , V_274 , V_275 ) ;
F_86 ( V_107 ) ;
V_54 = 0 ;
goto V_298;
}
}
F_163 ( V_107 , V_274 , V_275 + 1 ) ;
V_16 = V_248 ;
if ( V_251 <= V_15 ) {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_210 )
V_17 -> V_27 -> V_210 ( V_107 , V_15 ,
V_248 , NULL , 1 ) ;
goto V_125;
}
V_258 = V_113 -> V_259 -> V_260 ;
while ( V_249 <= V_16 ) {
if ( V_249 >= V_251 ) {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_210 )
V_17 -> V_27 -> V_210 ( V_107 , V_249 ,
V_248 , NULL , 1 ) ;
break;
}
V_191 = V_284 -> V_247 ( V_113 , V_107 , V_255 , V_249 ,
V_16 - V_249 + 1 , 1 ) ;
if ( F_159 ( V_191 ) ) {
F_133 ( V_107 ) ;
break;
}
V_250 = V_249 - V_191 -> V_15 ;
F_48 ( F_160 ( V_191 ) <= V_249 ) ;
F_48 ( V_16 < V_249 ) ;
V_256 = F_97 ( F_160 ( V_191 ) - V_249 , V_16 - V_249 + 1 ) ;
V_256 = ( V_256 + V_258 - 1 ) & ~ ( ( T_3 ) V_258 - 1 ) ;
V_162 = ( V_191 -> V_199 + V_250 ) >> 9 ;
V_172 = V_191 -> V_172 ;
V_199 = V_191 -> V_199 ;
V_288 = F_119 ( V_200 , & V_191 -> V_33 ) ;
F_128 ( V_191 ) ;
V_191 = NULL ;
if ( V_288 || V_199 == V_268 ||
V_199 == V_269 ) {
if ( ! V_288 && V_17 -> V_27 &&
V_17 -> V_27 -> V_210 )
V_17 -> V_27 -> V_210 ( V_107 , V_249 ,
V_249 + V_256 - 1 ,
NULL , 1 ) ;
else if ( V_288 ) {
V_238 ++ ;
}
V_249 += V_256 ;
V_255 += V_256 ;
continue;
}
if ( 0 && ! F_91 ( V_17 , V_249 , V_249 + V_256 - 1 ,
V_74 , 0 , NULL ) ) {
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
continue;
}
if ( V_17 -> V_27 && V_17 -> V_27 -> V_302 ) {
V_54 = V_17 -> V_27 -> V_302 ( V_107 , V_249 ,
V_249 + V_256 - 1 ) ;
} else {
V_54 = 0 ;
}
if ( V_54 ) {
F_133 ( V_107 ) ;
} else {
unsigned long V_303 = V_106 + 1 ;
F_76 ( V_17 , V_249 , V_249 + V_256 - 1 ) ;
if ( ! F_169 ( V_107 ) ) {
F_7 ( V_14 L_26
L_27 ,
V_107 -> V_104 , ( unsigned long long ) V_249 ,
( unsigned long long ) V_16 ) ;
}
V_54 = F_141 ( V_289 , V_17 , V_107 ,
V_162 , V_256 , V_255 ,
V_172 , & V_284 -> V_151 , V_303 ,
F_134 ,
0 , 0 , 0 ) ;
if ( V_54 )
F_133 ( V_107 ) ;
}
V_249 = V_249 + V_256 ;
V_255 += V_256 ;
V_238 ++ ;
}
V_125:
if ( V_238 == 0 ) {
F_78 ( V_107 ) ;
F_95 ( V_107 ) ;
}
F_86 ( V_107 ) ;
V_298:
F_21 ( V_77 ) ;
return 0 ;
}
static int F_170 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_273 * V_274 ,
T_10 V_304 , void * V_282 ,
void (* F_171)( void * ) )
{
int V_54 = 0 ;
int V_125 = 0 ;
int V_305 = 0 ;
struct V_306 V_307 ;
int V_116 ;
T_11 V_104 ;
T_11 V_16 ;
int V_308 = 0 ;
int V_309 ;
F_172 ( & V_307 , 0 ) ;
if ( V_274 -> V_277 ) {
V_104 = V_23 -> V_281 ;
V_16 = - 1 ;
} else {
V_104 = V_274 -> V_278 >> V_105 ;
V_16 = V_274 -> V_279 >> V_105 ;
V_308 = 1 ;
}
if ( V_274 -> V_291 == V_292 )
V_309 = V_310 ;
else
V_309 = V_311 ;
V_312:
if ( V_274 -> V_291 == V_292 )
F_173 ( V_23 , V_104 , V_16 ) ;
while ( ! V_125 && ! V_305 && ( V_104 <= V_16 ) &&
( V_116 = F_174 ( & V_307 , V_23 , & V_104 , V_309 ,
F_97 ( V_16 - V_104 , ( T_11 ) V_313 - 1 ) + 1 ) ) ) {
unsigned V_117 ;
V_308 = 1 ;
for ( V_117 = 0 ; V_117 < V_116 ; V_117 ++ ) {
struct V_107 * V_107 = V_307 . V_115 [ V_117 ] ;
if ( V_17 -> V_27 &&
V_17 -> V_27 -> V_314 ) {
V_17 -> V_27 -> V_314 ( V_107 ,
V_282 , F_171 ) ;
} else {
if ( ! F_175 ( V_107 ) ) {
F_171 ( V_282 ) ;
F_88 ( V_107 ) ;
}
}
if ( F_176 ( V_107 -> V_23 != V_23 ) ) {
F_86 ( V_107 ) ;
continue;
}
if ( ! V_274 -> V_277 && V_107 -> V_104 > V_16 ) {
V_125 = 1 ;
F_86 ( V_107 ) ;
continue;
}
if ( V_274 -> V_291 != V_315 ) {
if ( F_169 ( V_107 ) )
F_171 ( V_282 ) ;
F_177 ( V_107 ) ;
}
if ( F_169 ( V_107 ) ||
! F_94 ( V_107 ) ) {
F_86 ( V_107 ) ;
continue;
}
V_54 = (* V_304)( V_107 , V_274 , V_282 ) ;
if ( F_176 ( V_54 == V_316 ) ) {
F_86 ( V_107 ) ;
V_54 = 0 ;
}
if ( V_54 )
V_125 = 1 ;
V_305 = V_274 -> V_276 <= 0 ;
}
F_178 ( & V_307 ) ;
F_50 () ;
}
if ( ! V_308 && ! V_125 ) {
V_308 = 1 ;
V_104 = 0 ;
goto V_312;
}
return V_54 ;
}
static void F_179 ( struct V_283 * V_284 )
{
if ( V_284 -> V_151 ) {
if ( V_284 -> V_317 )
F_138 ( V_175 , V_284 -> V_151 , 0 , 0 ) ;
else
F_138 ( V_168 , V_284 -> V_151 , 0 , 0 ) ;
V_284 -> V_151 = NULL ;
}
}
static T_4 void F_180 ( void * V_282 )
{
struct V_283 * V_284 = V_282 ;
F_179 ( V_284 ) ;
}
int F_181 ( struct V_21 * V_17 , struct V_107 * V_107 ,
T_8 * V_247 ,
struct V_273 * V_274 )
{
int V_54 ;
struct V_283 V_284 = {
. V_151 = NULL ,
. V_17 = V_17 ,
. V_247 = V_247 ,
. V_295 = 0 ,
. V_317 = V_274 -> V_291 == V_292 ,
} ;
V_54 = F_164 ( V_107 , V_274 , & V_284 ) ;
F_179 ( & V_284 ) ;
return V_54 ;
}
int F_182 ( struct V_21 * V_17 , struct V_113 * V_113 ,
T_3 V_15 , T_3 V_16 , T_8 * V_247 ,
int V_318 )
{
int V_54 = 0 ;
struct V_22 * V_23 = V_113 -> V_118 ;
struct V_107 * V_107 ;
unsigned long V_116 = ( V_16 - V_15 + V_127 ) >>
V_105 ;
struct V_283 V_284 = {
. V_151 = NULL ,
. V_17 = V_17 ,
. V_247 = V_247 ,
. V_295 = 1 ,
. V_317 = V_318 == V_292 ,
} ;
struct V_273 V_319 = {
. V_291 = V_318 ,
. V_276 = V_116 * 2 ,
. V_278 = V_15 ,
. V_279 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_107 = F_77 ( V_23 , V_15 >> V_105 ) ;
if ( F_94 ( V_107 ) )
V_54 = F_164 ( V_107 , & V_319 , & V_284 ) ;
else {
if ( V_17 -> V_27 && V_17 -> V_27 -> V_210 )
V_17 -> V_27 -> V_210 ( V_107 , V_15 ,
V_15 + V_127 - 1 ,
NULL , 1 ) ;
F_86 ( V_107 ) ;
}
F_79 ( V_107 ) ;
V_15 += V_127 ;
}
F_179 ( & V_284 ) ;
return V_54 ;
}
int F_183 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
T_8 * V_247 ,
struct V_273 * V_274 )
{
int V_54 = 0 ;
struct V_283 V_284 = {
. V_151 = NULL ,
. V_17 = V_17 ,
. V_247 = V_247 ,
. V_295 = 0 ,
. V_317 = V_274 -> V_291 == V_292 ,
} ;
V_54 = F_170 ( V_17 , V_23 , V_274 ,
F_164 , & V_284 ,
F_180 ) ;
F_179 ( & V_284 ) ;
return V_54 ;
}
int F_184 ( struct V_21 * V_17 ,
struct V_22 * V_23 ,
struct V_320 * V_115 , unsigned V_116 ,
T_8 V_247 )
{
struct V_151 * V_151 = NULL ;
unsigned V_321 ;
unsigned long V_198 = 0 ;
for ( V_321 = 0 ; V_321 < V_116 ; V_321 ++ ) {
struct V_107 * V_107 = F_6 ( V_115 -> V_51 , struct V_107 , V_322 ) ;
F_135 ( & V_107 -> V_33 ) ;
F_9 ( & V_107 -> V_322 ) ;
if ( ! F_185 ( V_107 , V_23 ,
V_107 -> V_104 , V_129 ) ) {
F_149 ( V_17 , V_107 , V_247 ,
& V_151 , 0 , & V_198 ) ;
}
F_79 ( V_107 ) ;
}
F_48 ( ! F_5 ( V_115 ) ) ;
if ( V_151 )
F_138 ( V_272 , V_151 , 0 , V_198 ) ;
return 0 ;
}
int F_186 ( struct V_21 * V_17 ,
struct V_107 * V_107 , unsigned long V_40 )
{
struct V_2 * V_77 = NULL ;
T_3 V_15 = ( ( T_3 ) V_107 -> V_104 << V_105 ) ;
T_3 V_16 = V_15 + V_127 - 1 ;
T_6 V_258 = V_107 -> V_23 -> V_58 -> V_259 -> V_260 ;
V_15 += ( V_40 + V_258 - 1 ) & ~ ( V_258 - 1 ) ;
if ( V_15 > V_16 )
return 0 ;
F_71 ( V_17 , V_15 , V_16 , 0 , & V_77 , V_129 ) ;
F_177 ( V_107 ) ;
F_44 ( V_17 , V_15 , V_16 ,
V_103 | V_74 | V_99 |
V_101 ,
1 , 1 , & V_77 , V_129 ) ;
return 0 ;
}
int F_187 ( struct V_192 * V_323 ,
struct V_21 * V_17 , struct V_107 * V_107 ,
T_2 V_31 )
{
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_16 = V_15 + V_127 - 1 ;
int V_54 = 1 ;
if ( F_91 ( V_17 , V_15 , V_16 ,
V_60 , 0 , NULL ) )
V_54 = 0 ;
else {
if ( ( V_31 & V_129 ) == V_129 )
V_31 = V_129 ;
V_54 = F_44 ( V_17 , V_15 , V_16 ,
~ ( V_103 | V_324 ) ,
0 , 0 , NULL , V_31 ) ;
if ( V_54 < 0 )
V_54 = 0 ;
else
V_54 = 1 ;
}
return V_54 ;
}
int F_188 ( struct V_192 * V_323 ,
struct V_21 * V_17 , struct V_107 * V_107 ,
T_2 V_31 )
{
struct V_190 * V_191 ;
T_3 V_15 = ( T_3 ) V_107 -> V_104 << V_105 ;
T_3 V_16 = V_15 + V_127 - 1 ;
if ( ( V_31 & V_86 ) &&
V_107 -> V_23 -> V_58 -> V_285 > 16 * 1024 * 1024 ) {
T_3 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_189 ( & V_323 -> V_29 ) ;
V_191 = F_126 ( V_323 , V_15 , V_20 ) ;
if ( ! V_191 ) {
F_190 ( & V_323 -> V_29 ) ;
break;
}
if ( F_119 ( V_325 , & V_191 -> V_33 ) ||
V_191 -> V_15 != V_15 ) {
F_190 ( & V_323 -> V_29 ) ;
F_128 ( V_191 ) ;
break;
}
if ( ! F_91 ( V_17 , V_191 -> V_15 ,
F_160 ( V_191 ) - 1 ,
V_103 | V_326 ,
0 , NULL ) ) {
F_191 ( V_323 , V_191 ) ;
F_128 ( V_191 ) ;
}
V_15 = F_160 ( V_191 ) ;
F_190 ( & V_323 -> V_29 ) ;
F_128 ( V_191 ) ;
}
}
return F_187 ( V_323 , V_17 , V_107 , V_31 ) ;
}
static struct V_190 * F_192 ( struct V_113 * V_113 ,
T_3 V_40 ,
T_3 V_140 ,
T_8 * V_247 )
{
T_3 V_327 = F_106 ( V_113 ) -> V_39 -> V_327 ;
struct V_190 * V_191 ;
T_3 V_20 ;
if ( V_40 >= V_140 )
return NULL ;
while( 1 ) {
V_20 = V_140 - V_40 ;
if ( V_20 == 0 )
break;
V_20 = ( V_20 + V_327 - 1 ) & ~ ( V_327 - 1 ) ;
V_191 = V_247 ( V_113 , NULL , 0 , V_40 , V_20 , 0 ) ;
if ( F_159 ( V_191 ) )
return V_191 ;
if ( ! F_119 ( V_328 , & V_191 -> V_33 ) &&
V_191 -> V_199 != V_268 ) {
return V_191 ;
}
V_40 = F_160 ( V_191 ) ;
F_128 ( V_191 ) ;
if ( V_40 >= V_140 )
break;
}
return NULL ;
}
int F_193 ( struct V_113 * V_113 , struct V_329 * V_330 ,
T_12 V_15 , T_12 V_20 , T_8 * V_247 )
{
int V_54 = 0 ;
T_3 V_331 = V_15 ;
T_3 F_98 = V_15 + V_20 ;
T_13 V_33 = 0 ;
T_13 V_332 ;
T_3 V_140 ;
T_3 V_333 = 0 ;
T_3 V_334 = 0 ;
T_3 V_335 = F_150 ( V_113 ) ;
struct V_336 V_337 ;
struct V_190 * V_191 = NULL ;
struct V_2 * V_77 = NULL ;
struct V_338 * V_339 ;
struct V_340 * V_341 ;
int V_16 = 0 ;
T_3 V_342 = 0 ;
T_3 V_343 = 0 ;
T_3 V_344 = 0 ;
unsigned long V_345 ;
if ( V_20 == 0 )
return - V_346 ;
V_339 = F_194 () ;
if ( ! V_339 )
return - V_5 ;
V_339 -> V_347 = 1 ;
V_15 = F_195 ( V_15 , F_106 ( V_113 ) -> V_39 -> V_327 ) ;
V_20 = F_195 ( V_20 , F_106 ( V_113 ) -> V_39 -> V_327 ) ;
V_54 = F_196 ( NULL , F_106 ( V_113 ) -> V_39 ,
V_339 , F_197 ( V_113 ) , - 1 , 0 ) ;
if ( V_54 < 0 ) {
F_198 ( V_339 ) ;
return V_54 ;
}
F_23 ( ! V_54 ) ;
V_339 -> V_348 [ 0 ] -- ;
V_341 = F_199 ( V_339 -> V_349 [ 0 ] , V_339 -> V_348 [ 0 ] ,
struct V_340 ) ;
F_200 ( V_339 -> V_349 [ 0 ] , & V_337 , V_339 -> V_348 [ 0 ] ) ;
V_332 = F_201 ( & V_337 ) ;
if ( V_337 . V_350 != F_197 ( V_113 ) ||
V_332 != V_351 ) {
V_140 = ( T_3 ) - 1 ;
V_333 = V_335 ;
} else {
V_140 = V_337 . V_40 ;
V_333 = V_140 + 1 ;
}
F_198 ( V_339 ) ;
if ( V_140 < V_335 ) {
V_140 = ( T_3 ) - 1 ;
V_333 = V_335 ;
}
F_71 ( & F_106 ( V_113 ) -> V_149 , V_15 , V_15 + V_20 , 0 ,
& V_77 , V_129 ) ;
V_191 = F_192 ( V_113 , V_15 , V_333 ,
V_247 ) ;
if ( ! V_191 )
goto V_88;
if ( F_129 ( V_191 ) ) {
V_54 = F_202 ( V_191 ) ;
goto V_88;
}
while ( ! V_16 ) {
T_3 V_352 ;
if ( V_191 -> V_15 >= F_98 || F_160 ( V_191 ) < V_331 )
break;
V_342 = F_98 ( V_191 -> V_15 , V_331 ) ;
V_352 = V_342 - V_191 -> V_15 ;
V_344 = F_160 ( V_191 ) ;
V_343 = V_344 - V_342 ;
V_345 = V_191 -> V_33 ;
V_334 = 0 ;
V_33 = 0 ;
V_331 = F_160 ( V_191 ) ;
if ( V_331 >= F_98 )
V_16 = 1 ;
if ( V_191 -> V_199 == V_353 ) {
V_16 = 1 ;
V_33 |= V_354 ;
} else if ( V_191 -> V_199 == V_269 ) {
V_33 |= ( V_355 |
V_356 ) ;
} else if ( V_191 -> V_199 == V_357 ) {
V_33 |= ( V_358 |
V_359 ) ;
} else {
V_334 = V_191 -> V_199 + V_352 ;
}
if ( F_119 ( V_200 , & V_191 -> V_33 ) )
V_33 |= V_360 ;
F_128 ( V_191 ) ;
V_191 = NULL ;
if ( ( V_342 >= V_140 ) || V_343 == ( T_3 ) - 1 ||
( V_140 == ( T_3 ) - 1 && V_335 <= V_344 ) ) {
V_33 |= V_354 ;
V_16 = 1 ;
}
V_191 = F_192 ( V_113 , V_331 , V_333 ,
V_247 ) ;
if ( F_129 ( V_191 ) ) {
V_54 = F_202 ( V_191 ) ;
goto V_88;
}
if ( ! V_191 ) {
V_33 |= V_354 ;
V_16 = 1 ;
}
V_54 = F_203 ( V_330 , V_342 , V_334 ,
V_343 , V_33 ) ;
if ( V_54 )
goto V_361;
}
V_361:
F_128 ( V_191 ) ;
V_88:
F_74 ( & F_106 ( V_113 ) -> V_149 , V_15 , V_15 + V_20 ,
& V_77 , V_129 ) ;
return V_54 ;
}
inline struct V_107 * F_204 ( struct V_7 * V_10 ,
unsigned long V_117 )
{
struct V_107 * V_42 ;
struct V_22 * V_23 ;
if ( V_117 == 0 )
return V_10 -> V_362 ;
V_117 += V_10 -> V_15 >> V_105 ;
V_23 = V_10 -> V_362 -> V_23 ;
if ( ! V_23 )
return NULL ;
F_205 () ;
V_42 = F_206 ( & V_23 -> V_363 , V_117 ) ;
F_207 () ;
return V_42 ;
}
inline unsigned long F_208 ( T_3 V_15 , T_3 V_20 )
{
return ( ( V_15 + V_20 + V_127 - 1 ) >> V_105 ) -
( V_15 >> V_105 ) ;
}
static struct V_7 * F_209 ( struct V_21 * V_17 ,
T_3 V_15 ,
unsigned long V_20 ,
T_2 V_31 )
{
struct V_7 * V_10 = NULL ;
#if V_32
unsigned long V_33 ;
#endif
V_10 = F_210 ( V_6 , V_31 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_20 = V_20 ;
F_211 ( & V_10 -> V_29 ) ;
F_19 ( & V_10 -> V_364 , 0 ) ;
F_19 ( & V_10 -> V_365 , 0 ) ;
F_19 ( & V_10 -> V_366 , 0 ) ;
F_19 ( & V_10 -> V_367 , 0 ) ;
F_19 ( & V_10 -> V_368 , 0 ) ;
F_19 ( & V_10 -> V_369 , 0 ) ;
V_10 -> V_370 = 0 ;
F_20 ( & V_10 -> V_371 ) ;
F_20 ( & V_10 -> V_372 ) ;
#if V_32
F_16 ( & V_35 , V_33 ) ;
F_17 ( & V_10 -> V_13 , & V_19 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_19 ( & V_10 -> V_18 , 1 ) ;
return V_10 ;
}
static void F_212 ( struct V_7 * V_10 )
{
#if V_32
unsigned long V_33 ;
F_16 ( & V_35 , V_33 ) ;
F_9 ( & V_10 -> V_13 ) ;
F_18 ( & V_35 , V_33 ) ;
#endif
F_10 ( V_6 , V_10 ) ;
}
static void F_213 ( struct V_7 * V_10 ,
unsigned long V_373 )
{
unsigned long V_104 ;
struct V_107 * V_107 ;
if ( ! V_10 -> V_362 )
return;
V_104 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
if ( V_373 >= V_104 )
return;
do {
V_104 -- ;
V_107 = F_204 ( V_10 , V_104 ) ;
if ( V_107 )
F_79 ( V_107 ) ;
} while ( V_104 != V_373 );
}
static inline void F_214 ( struct V_7 * V_10 )
{
F_213 ( V_10 , 0 ) ;
F_212 ( V_10 ) ;
}
struct V_7 * F_215 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 ,
struct V_107 * V_374 )
{
unsigned long V_375 = F_208 ( V_15 , V_20 ) ;
unsigned long V_117 ;
unsigned long V_104 = V_15 >> V_105 ;
struct V_7 * V_10 ;
struct V_7 * V_376 = NULL ;
struct V_107 * V_42 ;
struct V_22 * V_23 = V_17 -> V_23 ;
int V_209 = 1 ;
int V_54 ;
F_205 () ;
V_10 = F_206 ( & V_17 -> V_25 , V_15 >> V_105 ) ;
if ( V_10 && F_216 ( & V_10 -> V_18 ) ) {
F_207 () ;
F_217 ( V_10 -> V_362 ) ;
return V_10 ;
}
F_207 () ;
V_10 = F_209 ( V_17 , V_15 , V_20 , V_129 ) ;
if ( ! V_10 )
return NULL ;
if ( V_374 ) {
V_10 -> V_362 = V_374 ;
V_117 = 1 ;
V_104 ++ ;
F_146 ( V_374 ) ;
F_217 ( V_374 ) ;
F_143 ( V_374 ) ;
F_148 ( V_374 , V_20 ) ;
V_209 = F_151 ( V_374 ) ;
} else {
V_117 = 0 ;
}
for (; V_117 < V_375 ; V_117 ++ , V_104 ++ ) {
V_42 = F_218 ( V_23 , V_104 , V_129 ) ;
if ( ! V_42 ) {
F_23 ( 1 ) ;
goto V_377;
}
F_143 ( V_42 ) ;
F_217 ( V_42 ) ;
if ( V_117 == 0 ) {
V_10 -> V_362 = V_42 ;
F_148 ( V_42 , V_20 ) ;
} else {
F_147 ( V_42 , V_245 ) ;
}
if ( ! F_151 ( V_42 ) )
V_209 = 0 ;
if ( V_117 != 0 )
F_86 ( V_42 ) ;
}
if ( V_209 )
F_219 ( V_378 , & V_10 -> V_379 ) ;
V_54 = F_220 ( V_129 & ~ V_380 ) ;
if ( V_54 )
goto V_377;
F_45 ( & V_17 -> V_30 ) ;
V_54 = F_221 ( & V_17 -> V_25 , V_15 >> V_105 , V_10 ) ;
if ( V_54 == - V_66 ) {
V_376 = F_206 ( & V_17 -> V_25 ,
V_15 >> V_105 ) ;
F_57 ( & V_376 -> V_18 ) ;
F_49 ( & V_17 -> V_30 ) ;
F_222 () ;
goto V_377;
}
F_57 ( & V_10 -> V_18 ) ;
F_49 ( & V_17 -> V_30 ) ;
F_222 () ;
F_143 ( V_10 -> V_362 ) ;
F_148 ( V_10 -> V_362 , V_10 -> V_20 ) ;
if ( ! V_374 )
F_86 ( V_10 -> V_362 ) ;
return V_10 ;
V_377:
if ( V_10 -> V_362 && ! V_374 )
F_86 ( V_10 -> V_362 ) ;
if ( ! F_22 ( & V_10 -> V_18 ) )
return V_376 ;
F_214 ( V_10 ) ;
return V_376 ;
}
struct V_7 * F_223 ( struct V_21 * V_17 ,
T_3 V_15 , unsigned long V_20 )
{
struct V_7 * V_10 ;
F_205 () ;
V_10 = F_206 ( & V_17 -> V_25 , V_15 >> V_105 ) ;
if ( V_10 && F_216 ( & V_10 -> V_18 ) ) {
F_207 () ;
F_217 ( V_10 -> V_362 ) ;
return V_10 ;
}
F_207 () ;
return NULL ;
}
void F_224 ( struct V_7 * V_10 )
{
if ( ! V_10 )
return;
if ( ! F_22 ( & V_10 -> V_18 ) )
return;
F_23 ( 1 ) ;
}
int F_225 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_117 ;
unsigned long V_375 ;
struct V_107 * V_107 ;
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_117 = 0 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
if ( ! F_89 ( V_107 ) )
continue;
F_88 ( V_107 ) ;
F_23 ( ! F_144 ( V_107 ) ) ;
F_143 ( V_107 ) ;
if ( V_117 == 0 )
F_148 ( V_107 , V_10 -> V_20 ) ;
F_94 ( V_107 ) ;
F_226 ( & V_107 -> V_23 -> V_381 ) ;
if ( ! F_89 ( V_107 ) ) {
F_227 ( & V_107 -> V_23 -> V_363 ,
F_228 ( V_107 ) ,
V_311 ) ;
}
F_229 ( & V_107 -> V_23 -> V_381 ) ;
F_167 ( V_107 ) ;
F_86 ( V_107 ) ;
}
return 0 ;
}
int F_230 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_117 ;
unsigned long V_375 ;
int V_382 = 0 ;
V_382 = F_231 ( V_383 , & V_10 -> V_379 ) ;
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_117 = 0 ; V_117 < V_375 ; V_117 ++ )
F_232 ( F_204 ( V_10 , V_117 ) ) ;
return V_382 ;
}
static int F_233 ( T_3 V_15 , T_3 V_20 )
{
if ( V_20 < V_127 )
return 1 ;
if ( V_15 & ( V_127 - 1 ) )
return 1 ;
if ( ( V_15 + V_20 ) & ( V_127 - 1 ) )
return 1 ;
return 0 ;
}
static int F_234 ( struct V_7 * V_10 )
{
return F_233 ( V_10 -> V_15 , V_10 -> V_20 ) ;
}
int F_235 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * * V_77 )
{
unsigned long V_117 ;
struct V_107 * V_107 ;
unsigned long V_375 ;
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
F_236 ( V_378 , & V_10 -> V_379 ) ;
F_70 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_77 , V_129 ) ;
for ( V_117 = 0 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
if ( V_107 )
F_132 ( V_107 ) ;
}
return 0 ;
}
int F_237 ( struct V_21 * V_17 ,
struct V_7 * V_10 )
{
unsigned long V_117 ;
struct V_107 * V_107 ;
unsigned long V_375 ;
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
if ( F_234 ( V_10 ) ) {
F_69 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
NULL , V_129 ) ;
}
for ( V_117 = 0 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
if ( ( V_117 == 0 && ( V_10 -> V_15 & ( V_127 - 1 ) ) ) ||
( ( V_117 == V_375 - 1 ) &&
( ( V_10 -> V_15 + V_10 -> V_20 ) & ( V_127 - 1 ) ) ) ) {
F_101 ( V_17 , V_107 ) ;
continue;
}
F_102 ( V_107 ) ;
}
return 0 ;
}
int F_238 ( struct V_21 * V_17 ,
T_3 V_15 , T_3 V_16 )
{
struct V_107 * V_107 ;
int V_54 ;
int V_384 = 1 ;
int V_209 ;
unsigned long V_104 ;
if ( F_233 ( V_15 , V_16 - V_15 + 1 ) ) {
V_54 = F_91 ( V_17 , V_15 , V_16 ,
V_100 , 1 , NULL ) ;
if ( V_54 )
return 1 ;
}
while ( V_15 <= V_16 ) {
V_104 = V_15 >> V_105 ;
V_107 = F_77 ( V_17 -> V_23 , V_104 ) ;
if ( ! V_107 )
return 1 ;
V_209 = F_151 ( V_107 ) ;
F_79 ( V_107 ) ;
if ( ! V_209 ) {
V_384 = 0 ;
break;
}
V_15 += V_127 ;
}
return V_384 ;
}
int F_239 ( struct V_21 * V_17 ,
struct V_7 * V_10 ,
struct V_2 * V_77 )
{
int V_54 = 0 ;
unsigned long V_375 ;
unsigned long V_117 ;
struct V_107 * V_107 ;
int V_384 = 1 ;
if ( F_119 ( V_378 , & V_10 -> V_379 ) )
return 1 ;
if ( F_234 ( V_10 ) ) {
V_54 = F_91 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_100 , 1 , V_77 ) ;
if ( V_54 )
return V_54 ;
}
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_117 = 0 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
if ( ! F_151 ( V_107 ) ) {
V_384 = 0 ;
break;
}
}
return V_384 ;
}
int F_240 ( struct V_21 * V_17 ,
struct V_7 * V_10 , T_3 V_15 , int V_90 ,
T_8 * V_247 , int V_157 )
{
unsigned long V_117 ;
unsigned long V_385 ;
struct V_107 * V_107 ;
int V_81 ;
int V_54 = 0 ;
int V_386 = 0 ;
int V_387 = 1 ;
int V_388 = 0 ;
unsigned long V_375 ;
struct V_151 * V_151 = NULL ;
unsigned long V_198 = 0 ;
if ( F_119 ( V_378 , & V_10 -> V_379 ) )
return 0 ;
if ( F_234 ( V_10 ) ) {
if ( F_91 ( V_17 , V_10 -> V_15 , V_10 -> V_15 + V_10 -> V_20 - 1 ,
V_100 , 1 , NULL ) ) {
return 0 ;
}
}
if ( V_15 ) {
F_23 ( V_15 < V_10 -> V_15 ) ;
V_385 = ( V_15 >> V_105 ) -
( V_10 -> V_15 >> V_105 ) ;
} else {
V_385 = 0 ;
}
V_375 = F_208 ( V_10 -> V_15 , V_10 -> V_20 ) ;
for ( V_117 = V_385 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
if ( V_90 == V_389 ) {
if ( ! F_175 ( V_107 ) )
goto V_390;
} else {
F_88 ( V_107 ) ;
}
V_386 ++ ;
if ( ! F_151 ( V_107 ) )
V_387 = 0 ;
}
if ( V_387 ) {
if ( V_385 == 0 )
F_219 ( V_378 , & V_10 -> V_379 ) ;
goto V_390;
}
for ( V_117 = V_385 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
F_23 ( ! F_144 ( V_107 ) ) ;
F_143 ( V_107 ) ;
if ( V_117 == 0 )
F_148 ( V_107 , V_10 -> V_20 ) ;
if ( V_388 )
F_146 ( V_107 ) ;
if ( ! F_151 ( V_107 ) ) {
if ( V_385 == 0 )
V_388 = 1 ;
F_167 ( V_107 ) ;
V_81 = F_149 ( V_17 , V_107 ,
V_247 , & V_151 ,
V_157 , & V_198 ) ;
if ( V_81 )
V_54 = V_81 ;
} else {
F_86 ( V_107 ) ;
}
}
if ( V_151 )
F_138 ( V_272 , V_151 , V_157 , V_198 ) ;
if ( V_54 || V_90 != V_391 )
return V_54 ;
for ( V_117 = V_385 ; V_117 < V_375 ; V_117 ++ ) {
V_107 = F_204 ( V_10 , V_117 ) ;
F_241 ( V_107 ) ;
if ( ! F_151 ( V_107 ) )
V_54 = - V_165 ;
}
if ( ! V_54 )
F_219 ( V_378 , & V_10 -> V_379 ) ;
return V_54 ;
V_390:
V_117 = V_385 ;
while ( V_386 > 0 ) {
V_107 = F_204 ( V_10 , V_117 ) ;
V_117 ++ ;
F_86 ( V_107 ) ;
V_386 -- ;
}
return V_54 ;
}
void F_242 ( struct V_7 * V_10 , void * V_392 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_40 ;
struct V_107 * V_107 ;
char * V_393 ;
char * V_394 = ( char * ) V_392 ;
T_6 V_395 = V_10 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_15 ) >> V_105 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_395 + V_15 ) & ( ( unsigned long ) V_127 - 1 ) ;
while ( V_20 > 0 ) {
V_107 = F_204 ( V_10 , V_117 ) ;
V_249 = F_97 ( V_20 , ( V_127 - V_40 ) ) ;
V_393 = F_243 ( V_107 ) ;
memcpy ( V_394 , V_393 + V_40 , V_249 ) ;
V_394 += V_249 ;
V_20 -= V_249 ;
V_40 = 0 ;
V_117 ++ ;
}
}
int F_244 ( struct V_7 * V_10 , unsigned long V_15 ,
unsigned long V_396 , char * * V_323 ,
unsigned long * V_397 ,
unsigned long * V_398 )
{
T_6 V_40 = V_15 & ( V_127 - 1 ) ;
char * V_393 ;
struct V_107 * V_42 ;
T_6 V_395 = V_10 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_15 ) >> V_105 ;
unsigned long V_399 = ( V_395 + V_15 + V_396 - 1 ) >>
V_105 ;
if ( V_117 != V_399 )
return - V_346 ;
if ( V_117 == 0 ) {
V_40 = V_395 ;
* V_397 = 0 ;
} else {
V_40 = 0 ;
* V_397 = ( ( T_3 ) V_117 << V_105 ) - V_395 ;
}
if ( V_15 + V_396 > V_10 -> V_20 ) {
F_7 ( V_14 L_28
L_29 , ( unsigned long long ) V_10 -> V_15 ,
V_10 -> V_20 , V_15 , V_396 ) ;
F_23 ( 1 ) ;
return - V_346 ;
}
V_42 = F_204 ( V_10 , V_117 ) ;
V_393 = F_243 ( V_42 ) ;
* V_323 = V_393 + V_40 ;
* V_398 = V_127 - V_40 ;
return 0 ;
}
int F_245 ( struct V_7 * V_10 , const void * V_400 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_40 ;
struct V_107 * V_107 ;
char * V_393 ;
char * V_401 = ( char * ) V_400 ;
T_6 V_395 = V_10 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_15 ) >> V_105 ;
int V_54 = 0 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_395 + V_15 ) & ( ( unsigned long ) V_127 - 1 ) ;
while ( V_20 > 0 ) {
V_107 = F_204 ( V_10 , V_117 ) ;
V_249 = F_97 ( V_20 , ( V_127 - V_40 ) ) ;
V_393 = F_243 ( V_107 ) ;
V_54 = memcmp ( V_401 , V_393 + V_40 , V_249 ) ;
if ( V_54 )
break;
V_401 += V_249 ;
V_20 -= V_249 ;
V_40 = 0 ;
V_117 ++ ;
}
return V_54 ;
}
void F_246 ( struct V_7 * V_10 , const void * V_402 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_40 ;
struct V_107 * V_107 ;
char * V_393 ;
char * V_403 = ( char * ) V_402 ;
T_6 V_395 = V_10 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_15 ) >> V_105 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_395 + V_15 ) & ( ( unsigned long ) V_127 - 1 ) ;
while ( V_20 > 0 ) {
V_107 = F_204 ( V_10 , V_117 ) ;
F_23 ( ! F_151 ( V_107 ) ) ;
V_249 = F_97 ( V_20 , V_127 - V_40 ) ;
V_393 = F_243 ( V_107 ) ;
memcpy ( V_393 + V_40 , V_403 , V_249 ) ;
V_403 += V_249 ;
V_20 -= V_249 ;
V_40 = 0 ;
V_117 ++ ;
}
}
void F_247 ( struct V_7 * V_10 , char V_404 ,
unsigned long V_15 , unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_40 ;
struct V_107 * V_107 ;
char * V_393 ;
T_6 V_395 = V_10 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_15 ) >> V_105 ;
F_23 ( V_15 > V_10 -> V_20 ) ;
F_23 ( V_15 + V_20 > V_10 -> V_15 + V_10 -> V_20 ) ;
V_40 = ( V_395 + V_15 ) & ( ( unsigned long ) V_127 - 1 ) ;
while ( V_20 > 0 ) {
V_107 = F_204 ( V_10 , V_117 ) ;
F_23 ( ! F_151 ( V_107 ) ) ;
V_249 = F_97 ( V_20 , V_127 - V_40 ) ;
V_393 = F_243 ( V_107 ) ;
memset ( V_393 + V_40 , V_404 , V_249 ) ;
V_20 -= V_249 ;
V_40 = 0 ;
V_117 ++ ;
}
}
void F_248 ( struct V_7 * V_394 , struct V_7 * V_403 ,
unsigned long V_405 , unsigned long V_406 ,
unsigned long V_20 )
{
T_3 V_407 = V_394 -> V_20 ;
T_6 V_249 ;
T_6 V_40 ;
struct V_107 * V_107 ;
char * V_393 ;
T_6 V_395 = V_394 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_117 = ( V_395 + V_405 ) >> V_105 ;
F_23 ( V_403 -> V_20 != V_407 ) ;
V_40 = ( V_395 + V_405 ) &
( ( unsigned long ) V_127 - 1 ) ;
while ( V_20 > 0 ) {
V_107 = F_204 ( V_394 , V_117 ) ;
F_23 ( ! F_151 ( V_107 ) ) ;
V_249 = F_97 ( V_20 , ( unsigned long ) ( V_127 - V_40 ) ) ;
V_393 = F_243 ( V_107 ) ;
F_242 ( V_403 , V_393 + V_40 , V_406 , V_249 ) ;
V_406 += V_249 ;
V_20 -= V_249 ;
V_40 = 0 ;
V_117 ++ ;
}
}
static void F_249 ( struct V_107 * V_408 , struct V_107 * V_409 ,
unsigned long V_410 , unsigned long V_411 ,
unsigned long V_20 )
{
char * V_412 = F_243 ( V_408 ) ;
if ( V_408 == V_409 ) {
memmove ( V_412 + V_410 , V_412 + V_411 , V_20 ) ;
} else {
char * V_413 = F_243 ( V_409 ) ;
char * V_42 = V_412 + V_410 + V_20 ;
char * V_414 = V_413 + V_411 + V_20 ;
while ( V_20 -- )
* -- V_42 = * -- V_414 ;
}
}
static inline bool F_250 ( unsigned long V_403 , unsigned long V_394 , unsigned long V_20 )
{
unsigned long V_415 = ( V_403 > V_394 ) ? V_403 - V_394 : V_394 - V_403 ;
return V_415 < V_20 ;
}
static void F_251 ( struct V_107 * V_408 , struct V_107 * V_409 ,
unsigned long V_410 , unsigned long V_411 ,
unsigned long V_20 )
{
char * V_412 = F_243 ( V_408 ) ;
char * V_413 ;
if ( V_408 != V_409 ) {
V_413 = F_243 ( V_409 ) ;
} else {
V_413 = V_412 ;
F_48 ( F_250 ( V_411 , V_410 , V_20 ) ) ;
}
memcpy ( V_412 + V_410 , V_413 + V_411 , V_20 ) ;
}
void F_252 ( struct V_7 * V_394 , unsigned long V_405 ,
unsigned long V_406 , unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_416 ;
T_6 V_417 ;
T_6 V_395 = V_394 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_418 ;
unsigned long V_419 ;
if ( V_406 + V_20 > V_394 -> V_20 ) {
F_7 ( V_14 L_30
L_31 , V_406 , V_20 , V_394 -> V_20 ) ;
F_48 ( 1 ) ;
}
if ( V_405 + V_20 > V_394 -> V_20 ) {
F_7 ( V_14 L_32
L_31 , V_405 , V_20 , V_394 -> V_20 ) ;
F_48 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_416 = ( V_395 + V_405 ) &
( ( unsigned long ) V_127 - 1 ) ;
V_417 = ( V_395 + V_406 ) &
( ( unsigned long ) V_127 - 1 ) ;
V_418 = ( V_395 + V_405 ) >> V_105 ;
V_419 = ( V_395 + V_406 ) >> V_105 ;
V_249 = F_97 ( V_20 , ( unsigned long ) ( V_127 -
V_417 ) ) ;
V_249 = F_85 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_251 ( F_204 ( V_394 , V_418 ) ,
F_204 ( V_394 , V_419 ) ,
V_416 , V_417 , V_249 ) ;
V_406 += V_249 ;
V_405 += V_249 ;
V_20 -= V_249 ;
}
}
void F_253 ( struct V_7 * V_394 , unsigned long V_405 ,
unsigned long V_406 , unsigned long V_20 )
{
T_6 V_249 ;
T_6 V_416 ;
T_6 V_417 ;
unsigned long V_420 = V_405 + V_20 - 1 ;
unsigned long V_421 = V_406 + V_20 - 1 ;
T_6 V_395 = V_394 -> V_15 & ( ( T_3 ) V_127 - 1 ) ;
unsigned long V_418 ;
unsigned long V_419 ;
if ( V_406 + V_20 > V_394 -> V_20 ) {
F_7 ( V_14 L_30
L_33 , V_406 , V_20 , V_394 -> V_20 ) ;
F_48 ( 1 ) ;
}
if ( V_405 + V_20 > V_394 -> V_20 ) {
F_7 ( V_14 L_32
L_33 , V_405 , V_20 , V_394 -> V_20 ) ;
F_48 ( 1 ) ;
}
if ( ! F_250 ( V_406 , V_405 , V_20 ) ) {
F_252 ( V_394 , V_405 , V_406 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_418 = ( V_395 + V_420 ) >> V_105 ;
V_419 = ( V_395 + V_421 ) >> V_105 ;
V_416 = ( V_395 + V_420 ) &
( ( unsigned long ) V_127 - 1 ) ;
V_417 = ( V_395 + V_421 ) &
( ( unsigned long ) V_127 - 1 ) ;
V_249 = F_85 (unsigned long, len, src_off_in_page + 1 ) ;
V_249 = F_97 ( V_249 , V_416 + 1 ) ;
F_249 ( F_204 ( V_394 , V_418 ) ,
F_204 ( V_394 , V_419 ) ,
V_416 - V_249 + 1 ,
V_417 - V_249 + 1 , V_249 ) ;
V_420 -= V_249 ;
V_421 -= V_249 ;
V_20 -= V_249 ;
}
}
static inline void F_254 ( struct V_422 * V_423 )
{
struct V_7 * V_10 =
F_255 ( V_423 , struct V_7 , V_422 ) ;
F_214 ( V_10 ) ;
}
int F_256 ( struct V_21 * V_17 , struct V_107 * V_107 )
{
T_3 V_15 = F_116 ( V_107 ) ;
struct V_7 * V_10 ;
int V_54 = 1 ;
F_45 ( & V_17 -> V_30 ) ;
V_10 = F_206 ( & V_17 -> V_25 , V_15 >> V_105 ) ;
if ( ! V_10 ) {
F_49 ( & V_17 -> V_30 ) ;
return V_54 ;
}
if ( F_119 ( V_383 , & V_10 -> V_379 ) ) {
V_54 = 0 ;
goto V_88;
}
if ( F_257 ( & V_10 -> V_18 , 1 , 0 ) != 1 ) {
V_54 = 0 ;
goto V_88;
}
F_258 ( & V_17 -> V_25 , V_15 >> V_105 ) ;
V_88:
F_49 ( & V_17 -> V_30 ) ;
if ( F_8 ( & V_10 -> V_18 ) == 0 )
F_259 ( & V_10 -> V_422 , F_254 ) ;
return V_54 ;
}
