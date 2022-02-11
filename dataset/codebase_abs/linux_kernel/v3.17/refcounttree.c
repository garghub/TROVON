static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 =
(struct V_10 * ) V_8 -> V_12 ;
F_4 ( ( unsigned long long ) V_8 -> V_13 ) ;
F_5 ( ! F_6 ( V_8 ) ) ;
V_9 = F_7 ( V_6 , V_8 -> V_12 , & V_11 -> V_14 ) ;
if ( V_9 ) {
F_8 ( V_15 , L_1 ,
( unsigned long long ) V_8 -> V_13 ) ;
return V_9 ;
}
if ( ! F_9 ( V_11 ) ) {
F_10 ( V_6 ,
L_2 ,
( unsigned long long ) V_8 -> V_13 , 7 ,
V_11 -> V_16 ) ;
return - V_17 ;
}
if ( F_11 ( V_11 -> V_18 ) != V_8 -> V_13 ) {
F_10 ( V_6 ,
L_3
L_4 ,
( unsigned long long ) V_8 -> V_13 ,
( unsigned long long ) F_11 ( V_11 -> V_18 ) ) ;
return - V_17 ;
}
if ( F_12 ( V_11 -> V_19 ) != F_13 ( V_6 ) -> V_20 ) {
F_10 ( V_6 ,
L_5
L_6 ,
( unsigned long long ) V_8 -> V_13 ,
F_12 ( V_11 -> V_19 ) ) ;
return - V_17 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
T_1 V_21 ,
struct V_7 * * V_8 )
{
int V_9 ;
struct V_7 * V_22 = * V_8 ;
V_9 = F_15 ( V_3 , V_21 , & V_22 ,
F_3 ) ;
if ( ! V_9 && ! * V_8 )
* V_8 = V_22 ;
return V_9 ;
}
static T_1 F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
return V_23 -> V_18 ;
}
static struct V_5 *
F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
return V_23 -> V_24 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_19 ( & V_23 -> V_25 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_21 ( & V_23 -> V_25 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_23 ( & V_23 -> V_26 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_25 ( & V_23 -> V_26 ) ;
}
static struct V_1 *
F_26 ( struct V_27 * V_28 , T_1 V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 . V_30 ;
struct V_1 * V_33 = NULL ;
while ( V_31 ) {
V_33 = F_27 ( V_31 , struct V_1 , V_34 ) ;
if ( V_29 < V_33 -> V_18 )
V_31 = V_31 -> V_35 ;
else if ( V_29 > V_33 -> V_18 )
V_31 = V_31 -> V_36 ;
else
return V_33 ;
}
return NULL ;
}
static void F_28 ( struct V_27 * V_28 ,
struct V_1 * V_37 )
{
T_1 V_18 = V_37 -> V_18 ;
struct V_30 * V_38 = NULL ;
struct V_30 * * V_39 = & V_28 -> V_32 . V_30 ;
struct V_1 * V_22 ;
while ( * V_39 ) {
V_38 = * V_39 ;
V_22 = F_27 ( V_38 , struct V_1 ,
V_34 ) ;
if ( V_18 < V_22 -> V_18 )
V_39 = & ( * V_39 ) -> V_35 ;
else if ( V_18 > V_22 -> V_18 )
V_39 = & ( * V_39 ) -> V_36 ;
else {
F_8 ( V_15 , L_7 ,
( unsigned long long ) V_18 ) ;
F_29 () ;
}
}
F_30 ( & V_37 -> V_34 , V_38 , V_39 ) ;
F_31 ( & V_37 -> V_34 , & V_28 -> V_32 ) ;
}
static void F_32 ( struct V_1 * V_33 )
{
F_33 ( & V_33 -> V_4 ) ;
F_34 ( F_13 ( V_33 -> V_24 ) , & V_33 -> V_40 ) ;
F_35 ( & V_33 -> V_40 ) ;
F_36 ( V_33 ) ;
}
static inline void
F_37 ( struct V_27 * V_28 ,
struct V_1 * V_33 )
{
F_38 ( & V_33 -> V_34 , & V_28 -> V_32 ) ;
if ( V_28 -> V_41 && V_28 -> V_41 == V_33 )
V_28 -> V_41 = NULL ;
}
static void F_39 ( struct V_27 * V_28 ,
struct V_1 * V_33 )
{
F_19 ( & V_28 -> V_42 ) ;
F_37 ( V_28 , V_33 ) ;
F_21 ( & V_28 -> V_42 ) ;
}
static void F_40 ( struct V_43 * V_43 )
{
struct V_1 * V_33 =
F_2 ( V_43 , struct V_1 , V_44 ) ;
F_32 ( V_33 ) ;
}
static inline void
F_41 ( struct V_1 * V_33 )
{
F_42 ( & V_33 -> V_44 ) ;
}
static inline void
F_43 ( struct V_1 * V_33 )
{
F_44 ( & V_33 -> V_44 , F_40 ) ;
}
static inline void F_45 ( struct V_1 * V_37 ,
struct V_5 * V_6 )
{
F_46 ( & V_37 -> V_4 , & V_45 ) ;
F_47 ( & V_37 -> V_26 ) ;
V_37 -> V_24 = V_6 ;
F_48 ( & V_37 -> V_25 ) ;
}
static inline void F_49 ( struct V_27 * V_28 ,
struct V_1 * V_37 ,
T_1 V_18 , T_2 V_46 )
{
F_50 ( & V_37 -> V_47 ) ;
F_51 ( & V_37 -> V_40 , V_28 ,
V_18 , V_46 ) ;
}
static struct V_1 *
F_52 ( struct V_27 * V_28 , T_1 V_18 )
{
struct V_1 * V_37 ;
V_37 = F_53 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_18 = V_18 ;
F_54 ( & V_37 -> V_44 ) ;
F_45 ( V_37 , V_28 -> V_6 ) ;
return V_37 ;
}
static int F_55 ( struct V_27 * V_28 , T_1 V_18 ,
struct V_1 * * V_49 )
{
int V_50 = 0 ;
struct V_1 * V_33 , * V_37 = NULL ;
struct V_7 * V_51 = NULL ;
struct V_10 * V_52 ;
F_19 ( & V_28 -> V_42 ) ;
if ( V_28 -> V_41 &&
V_28 -> V_41 -> V_18 == V_18 )
V_33 = V_28 -> V_41 ;
else
V_33 = F_26 ( V_28 , V_18 ) ;
if ( V_33 )
goto V_53;
F_21 ( & V_28 -> V_42 ) ;
V_37 = F_52 ( V_28 , V_18 ) ;
if ( ! V_37 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
return V_50 ;
}
V_50 = F_14 ( & V_37 -> V_4 , V_18 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
F_33 ( & V_37 -> V_4 ) ;
F_36 ( V_37 ) ;
return V_50 ;
}
V_52 = (struct V_10 * ) V_51 -> V_12 ;
V_37 -> V_55 = F_12 ( V_52 -> V_55 ) ;
F_49 ( V_28 , V_37 , V_18 ,
V_37 -> V_55 ) ;
F_57 ( & V_37 -> V_4 ) ;
F_19 ( & V_28 -> V_42 ) ;
V_33 = F_26 ( V_28 , V_18 ) ;
if ( V_33 )
goto V_53;
F_28 ( V_28 , V_37 ) ;
V_33 = V_37 ;
V_37 = NULL ;
V_53:
* V_49 = V_33 ;
V_28 -> V_41 = V_33 ;
F_21 ( & V_28 -> V_42 ) ;
if ( V_37 )
F_32 ( V_37 ) ;
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_59 ( struct V_56 * V_56 , T_1 * V_57 )
{
int V_50 ;
struct V_7 * V_58 = NULL ;
struct V_59 * V_60 ;
V_50 = F_60 ( V_56 , & V_58 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_5 ( ! ( F_61 ( V_56 ) -> V_61 & V_62 ) ) ;
V_60 = (struct V_59 * ) V_58 -> V_12 ;
* V_57 = F_11 ( V_60 -> V_63 ) ;
F_58 ( V_58 ) ;
V_53:
return V_50 ;
}
static int F_62 ( struct V_27 * V_28 ,
struct V_1 * V_33 , int V_64 )
{
int V_50 ;
V_50 = F_63 ( V_33 , V_64 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_64 )
F_64 ( & V_33 -> V_47 ) ;
else
F_65 ( & V_33 -> V_47 ) ;
V_53:
return V_50 ;
}
int F_66 ( struct V_27 * V_28 ,
T_1 V_57 , int V_64 ,
struct V_1 * * V_49 ,
struct V_7 * * V_65 )
{
int V_50 , V_66 = 0 ;
struct V_1 * V_33 = NULL ;
struct V_7 * V_51 = NULL ;
struct V_10 * V_11 ;
V_67:
V_50 = F_55 ( V_28 , V_57 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
F_41 ( V_33 ) ;
V_50 = F_62 ( V_28 , V_33 , V_64 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
F_43 ( V_33 ) ;
goto V_53;
}
V_50 = F_14 ( & V_33 -> V_4 , V_33 -> V_18 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
F_67 ( V_28 , V_33 , V_64 ) ;
F_43 ( V_33 ) ;
goto V_53;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( V_33 -> V_55 != F_12 ( V_11 -> V_55 ) ) {
if ( ! V_33 -> V_68 ) {
F_39 ( V_28 , V_33 ) ;
V_33 -> V_68 = 1 ;
V_66 = 1 ;
}
F_67 ( V_28 , V_33 , V_64 ) ;
if ( V_66 )
F_43 ( V_33 ) ;
F_58 ( V_51 ) ;
V_51 = NULL ;
goto V_67;
}
* V_49 = V_33 ;
if ( V_65 ) {
* V_65 = V_51 ;
V_51 = NULL ;
}
V_53:
F_58 ( V_51 ) ;
return V_50 ;
}
void F_67 ( struct V_27 * V_28 ,
struct V_1 * V_33 , int V_64 )
{
if ( V_64 )
F_68 ( & V_33 -> V_47 ) ;
else
F_69 ( & V_33 -> V_47 ) ;
F_70 ( V_33 , V_64 ) ;
F_43 ( V_33 ) ;
}
void F_71 ( struct V_27 * V_28 )
{
struct V_30 * V_69 ;
struct V_1 * V_33 ;
struct V_70 * V_71 = & V_28 -> V_32 ;
while ( ( V_69 = F_72 ( V_71 ) ) != NULL ) {
V_33 = F_27 ( V_69 , struct V_1 , V_34 ) ;
F_73 (
( unsigned long long ) V_33 -> V_18 ) ;
F_38 ( & V_33 -> V_34 , V_71 ) ;
F_32 ( V_33 ) ;
}
}
static int F_74 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 ;
T_3 * V_72 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_7 * V_78 = NULL ;
struct V_10 * V_11 ;
struct V_1 * V_79 = NULL , * V_33 = NULL ;
T_4 V_80 ;
T_2 V_81 ;
T_1 V_82 , V_83 ;
F_5 ( V_76 -> V_61 & V_62 ) ;
F_75 (
( unsigned long long ) F_61 ( V_56 ) -> V_84 ) ;
V_50 = F_76 ( V_28 , 1 , & V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_72 = F_77 ( V_28 , V_85 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_80 ( V_72 , F_81 ( V_56 ) , V_58 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_82 ( V_72 , V_74 , 1 , & V_82 ,
& V_80 , & V_81 ,
& V_83 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_79 = F_52 ( V_28 , V_83 ) ;
if ( ! V_79 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_87;
}
V_78 = F_83 ( V_56 -> V_77 , V_83 ) ;
if ( ! V_78 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_87;
}
F_84 ( & V_79 -> V_4 , V_78 ) ;
V_50 = F_85 ( V_72 , & V_79 -> V_4 , V_78 ,
V_88 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_11 = (struct V_10 * ) V_78 -> V_12 ;
memset ( V_11 , 0 , V_56 -> V_77 -> V_89 ) ;
strcpy ( ( void * ) V_11 , V_90 ) ;
V_11 -> V_91 = F_86 ( V_74 -> V_92 ) ;
V_11 -> V_93 = F_87 ( V_82 ) ;
V_11 -> V_94 = F_86 ( V_80 ) ;
V_11 -> V_19 = F_88 ( V_28 -> V_20 ) ;
V_11 -> V_18 = F_87 ( V_83 ) ;
V_11 -> V_95 = F_88 ( 1 ) ;
V_11 -> V_96 . V_97 =
F_86 ( F_89 ( V_28 -> V_6 ) ) ;
F_19 ( & V_28 -> V_42 ) ;
V_11 -> V_55 = V_28 -> V_98 ++ ;
F_21 ( & V_28 -> V_42 ) ;
F_90 ( V_72 , V_78 ) ;
F_19 ( & V_76 -> V_99 ) ;
V_76 -> V_61 |= V_62 ;
V_60 -> V_100 = F_86 ( V_76 -> V_61 ) ;
V_60 -> V_63 = F_87 ( V_83 ) ;
F_21 ( & V_76 -> V_99 ) ;
F_91 ( ( unsigned long long ) V_83 ) ;
F_90 ( V_72 , V_58 ) ;
V_79 -> V_55 = F_12 ( V_11 -> V_55 ) ;
F_49 ( V_28 , V_79 , V_83 ,
V_79 -> V_55 ) ;
F_19 ( & V_28 -> V_42 ) ;
V_33 = F_26 ( V_28 , V_83 ) ;
F_5 ( V_33 && V_33 -> V_55 == V_79 -> V_55 ) ;
if ( V_33 )
F_37 ( V_28 , V_33 ) ;
F_28 ( V_28 , V_79 ) ;
F_21 ( & V_28 -> V_42 ) ;
V_79 = NULL ;
if ( V_33 )
F_43 ( V_33 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_79 ) {
F_33 ( & V_79 -> V_4 ) ;
F_36 ( V_79 ) ;
}
F_58 ( V_78 ) ;
if ( V_74 )
F_93 ( V_74 ) ;
return V_50 ;
}
static int F_94 ( struct V_56 * V_56 ,
struct V_7 * V_58 ,
T_1 V_101 )
{
int V_50 ;
T_3 * V_72 = NULL ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_7 * V_51 = NULL ;
struct V_10 * V_11 ;
struct V_1 * V_102 ;
F_5 ( V_76 -> V_61 & V_62 ) ;
V_50 = F_66 ( V_28 , V_101 , 1 ,
& V_102 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_72 = F_77 ( V_28 , V_103 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_80 ( V_72 , F_81 ( V_56 ) , V_58 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_85 ( V_72 , & V_102 -> V_4 , V_51 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
F_95 ( & V_11 -> V_95 , 1 ) ;
F_90 ( V_72 , V_51 ) ;
F_19 ( & V_76 -> V_99 ) ;
V_76 -> V_61 |= V_62 ;
V_60 -> V_100 = F_86 ( V_76 -> V_61 ) ;
V_60 -> V_63 = F_87 ( V_101 ) ;
F_21 ( & V_76 -> V_99 ) ;
F_90 ( V_72 , V_58 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
return V_50 ;
}
int F_96 ( struct V_56 * V_56 , struct V_7 * V_58 )
{
int V_50 , V_66 = 0 ;
T_3 * V_72 = NULL ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_10 * V_11 ;
struct V_56 * V_104 = NULL ;
struct V_7 * V_105 = NULL ;
struct V_7 * V_106 = NULL ;
struct V_1 * V_102 ;
int V_107 = V_108 ;
T_1 V_109 = 0 , V_110 = 0 , V_57 = F_11 ( V_60 -> V_63 ) ;
T_4 V_111 = 0 ;
if ( ! ( V_76 -> V_61 & V_62 ) )
return 0 ;
F_5 ( ! V_57 ) ;
V_50 = F_66 ( V_28 , V_57 , 1 , & V_102 , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_11 = (struct V_10 * ) V_106 -> V_12 ;
if ( F_12 ( V_11 -> V_95 ) == 1 ) {
V_109 = F_11 ( V_11 -> V_18 ) ;
V_111 = F_97 ( V_11 -> V_94 ) ;
if ( V_11 -> V_93 )
V_110 = F_11 ( V_11 -> V_93 ) ;
else
V_110 = F_98 ( V_109 , V_111 ) ;
V_104 = F_99 ( V_28 ,
V_112 ,
F_97 ( V_11 -> V_91 ) ) ;
if ( ! V_104 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
F_23 ( & V_104 -> V_113 ) ;
V_50 = F_100 ( V_104 , & V_105 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_114;
}
V_107 += V_115 ;
}
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_116;
}
V_50 = F_80 ( V_72 , F_81 ( V_56 ) , V_58 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_85 ( V_72 , & V_102 -> V_4 , V_106 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
F_19 ( & V_76 -> V_99 ) ;
V_76 -> V_61 &= ~ V_62 ;
V_60 -> V_100 = F_86 ( V_76 -> V_61 ) ;
V_60 -> V_63 = 0 ;
F_21 ( & V_76 -> V_99 ) ;
F_90 ( V_72 , V_58 ) ;
F_95 ( & V_11 -> V_95 , - 1 ) ;
F_90 ( V_72 , V_106 ) ;
if ( ! V_11 -> V_95 ) {
V_66 = 1 ;
F_39 ( V_28 , V_102 ) ;
V_50 = F_101 ( V_72 , V_104 ,
V_105 , V_111 , V_110 , 1 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_87:
F_92 ( V_28 , V_72 ) ;
V_116:
if ( V_104 ) {
F_102 ( V_104 , 1 ) ;
F_58 ( V_105 ) ;
}
V_114:
if ( V_104 ) {
F_25 ( & V_104 -> V_113 ) ;
F_103 ( V_104 ) ;
}
V_53:
F_67 ( V_28 , V_102 , 1 ) ;
if ( V_66 )
F_43 ( V_102 ) ;
F_58 ( V_106 ) ;
return V_50 ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_7 * V_117 ,
T_1 V_118 , unsigned int V_119 ,
struct V_120 * V_121 ,
int * V_122 )
{
int V_123 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_120 * V_124 = NULL ;
for (; V_123 < F_97 ( V_11 -> V_96 . V_125 ) ; V_123 ++ ) {
V_124 = & V_11 -> V_96 . V_126 [ V_123 ] ;
if ( F_11 ( V_124 -> V_127 ) +
F_12 ( V_124 -> V_128 ) <= V_118 )
continue;
else if ( F_11 ( V_124 -> V_127 ) > V_118 )
break;
if ( V_121 )
* V_121 = * V_124 ;
goto V_53;
}
if ( V_121 ) {
V_121 -> V_127 = F_87 ( V_118 ) ;
V_121 -> V_129 = 0 ;
if ( V_123 < F_97 ( V_11 -> V_96 . V_125 ) &&
F_11 ( V_124 -> V_127 ) < V_118 + V_119 )
V_121 -> V_128 =
F_88 ( F_11 ( V_124 -> V_127 ) - V_118 ) ;
else
V_121 -> V_128 = F_88 ( V_119 ) ;
}
V_53:
* V_122 = V_123 ;
}
int F_105 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
F_64 ( & V_76 -> V_130 ) ;
F_64 ( & V_76 -> V_131 ) ;
if ( V_76 -> V_132 )
goto V_53;
if ( ( V_76 -> V_61 & V_133 ) && V_60 -> V_134 )
goto V_53;
if ( V_76 -> V_61 & V_135 &&
F_106 ( V_56 , V_60 ) )
goto V_53;
V_50 = F_96 ( V_56 , V_58 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_68 ( & V_76 -> V_131 ) ;
F_68 ( & V_76 -> V_130 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_136 * V_137 ,
struct V_138 * V_139 ,
int V_122 , T_2 * V_140 )
{
int V_50 , V_123 , V_141 ;
T_2 V_118 ;
T_1 V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_142 * V_143 = NULL , * V_144 = NULL ;
struct V_145 V_146 ;
struct V_138 * V_147 ;
if ( V_122 < F_97 ( V_139 -> V_148 ) - 1 ) {
* V_140 = F_12 ( V_139 -> V_149 [ V_122 + 1 ] . V_150 ) ;
return 0 ;
}
if ( ! V_137 || ( V_137 && ! V_137 -> V_151 ) ) {
* V_140 = V_152 ;
return 0 ;
}
F_109 ( & V_146 , V_3 , V_51 ) ;
V_143 = F_110 ( & V_146 ) ;
if ( ! V_143 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_118 = F_12 ( V_137 -> V_153 . V_149 [ V_122 ] . V_150 ) ;
V_50 = F_111 ( V_3 , V_143 , V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_144 = F_112 ( V_143 ) ;
if ( ! V_144 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_113 ( V_6 , V_143 , & V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_111 ( V_3 , V_144 , V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_141 = F_114 ( & V_146 , V_143 ,
V_144 ) ;
V_147 = V_143 -> V_154 [ V_141 ] . V_139 ;
V_29 = V_143 -> V_154 [ V_141 + 1 ] . V_8 -> V_13 ;
for ( V_123 = 0 ; V_123 < F_97 ( V_147 -> V_148 ) ; V_123 ++ ) {
if ( F_11 ( V_147 -> V_149 [ V_123 ] . V_155 ) == V_29 ) {
* V_140 = F_12 ( V_147 -> V_149 [ V_123 + 1 ] . V_150 ) ;
break;
}
}
F_5 ( V_123 == F_97 ( V_147 -> V_148 ) ) ;
V_53:
F_115 ( V_143 ) ;
F_115 ( V_144 ) ;
return V_50 ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_118 , unsigned int V_119 ,
struct V_120 * V_121 ,
int * V_122 ,
struct V_7 * * V_156 )
{
int V_50 = 0 , V_123 , V_157 ;
T_2 V_158 , V_159 ( V_140 ) ;
struct V_138 * V_139 ;
struct V_160 * V_124 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_7 * V_161 = NULL , * V_117 = NULL ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
if ( ! ( F_12 ( V_11 -> V_162 ) & V_163 ) ) {
F_104 ( V_3 , V_51 , V_118 , V_119 ,
V_121 , V_122 ) ;
* V_156 = V_51 ;
F_117 ( V_51 ) ;
return 0 ;
}
V_139 = & V_11 -> V_164 ;
V_158 = V_118 & V_165 ;
if ( V_139 -> V_166 ) {
V_50 = F_118 ( V_3 , V_139 , V_158 , & V_161 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_137 = (struct V_136 * ) V_161 -> V_12 ;
V_139 = & V_137 -> V_153 ;
if ( V_139 -> V_166 ) {
F_10 ( V_6 ,
L_8
L_9 ,
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_161 -> V_13 ) ;
V_50 = - V_167 ;
goto V_53;
}
}
V_157 = 0 ;
for ( V_123 = F_97 ( V_139 -> V_148 ) - 1 ; V_123 >= 0 ; V_123 -- ) {
V_124 = & V_139 -> V_149 [ V_123 ] ;
if ( F_12 ( V_124 -> V_150 ) <= V_158 ) {
V_157 = 1 ;
break;
}
}
if ( V_157 ) {
V_50 = F_107 ( V_3 , V_51 ,
V_137 , V_139 , V_123 , & V_140 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_140 < V_158 + V_119 )
V_119 = V_140 - V_158 ;
}
V_50 = F_14 ( V_3 , F_11 ( V_124 -> V_155 ) ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_104 ( V_3 , V_117 , V_118 , V_119 ,
V_121 , V_122 ) ;
* V_156 = V_117 ;
V_53:
F_58 ( V_161 ) ;
return V_50 ;
}
static enum V_168
F_120 ( struct V_10 * V_11 ,
int V_122 )
{
if ( ( V_11 -> V_96 . V_126 [ V_122 ] . V_129 ==
V_11 -> V_96 . V_126 [ V_122 + 1 ] . V_129 ) &&
( F_11 ( V_11 -> V_96 . V_126 [ V_122 ] . V_127 ) +
F_12 ( V_11 -> V_96 . V_126 [ V_122 ] . V_128 ) ==
F_11 ( V_11 -> V_96 . V_126 [ V_122 + 1 ] . V_127 ) ) )
return V_169 ;
return V_170 ;
}
static enum V_168
F_121 ( struct V_10 * V_11 ,
int V_122 )
{
enum V_168 V_50 = V_170 ;
if ( V_122 < F_97 ( V_11 -> V_96 . V_125 ) - 1 )
V_50 = F_120 ( V_11 , V_122 ) ;
if ( V_122 > 0 ) {
enum V_168 V_22 ;
V_22 = F_120 ( V_11 , V_122 - 1 ) ;
if ( V_22 == V_169 ) {
if ( V_50 == V_169 )
V_50 = V_171 ;
else
V_50 = V_172 ;
}
}
return V_50 ;
}
static void F_122 ( struct V_10 * V_11 ,
int V_122 )
{
F_5 ( V_11 -> V_96 . V_126 [ V_122 ] . V_129 !=
V_11 -> V_96 . V_126 [ V_122 + 1 ] . V_129 ) ;
F_95 ( & V_11 -> V_96 . V_126 [ V_122 ] . V_128 ,
F_12 ( V_11 -> V_96 . V_126 [ V_122 + 1 ] . V_128 ) ) ;
if ( V_122 < F_97 ( V_11 -> V_96 . V_125 ) - 2 )
memmove ( & V_11 -> V_96 . V_126 [ V_122 + 1 ] ,
& V_11 -> V_96 . V_126 [ V_122 + 2 ] ,
sizeof( struct V_120 ) *
( F_97 ( V_11 -> V_96 . V_125 ) - V_122 - 2 ) ) ;
memset ( & V_11 -> V_96 . V_126 [ F_97 ( V_11 -> V_96 . V_125 ) - 1 ] ,
0 , sizeof( struct V_120 ) ) ;
F_123 ( & V_11 -> V_96 . V_125 , - 1 ) ;
}
static void F_124 ( struct V_10 * V_11 ,
int V_122 )
{
enum V_168 V_173 =
F_121 ( V_11 , V_122 ) ;
if ( V_173 == V_170 )
return;
if ( V_173 == V_172 || V_173 == V_171 ) {
F_5 ( V_122 == 0 ) ;
V_122 -- ;
}
F_122 ( V_11 , V_122 ) ;
if ( V_173 == V_171 )
F_122 ( V_11 , V_122 ) ;
}
static int F_125 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_117 ,
int V_122 , int V_174 , int V_175 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_177 = & V_11 -> V_96 ;
struct V_120 * V_124 = & V_177 -> V_126 [ V_122 ] ;
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_126 (
( unsigned long long ) F_119 ( V_3 ) ,
V_122 , F_12 ( V_124 -> V_129 ) , V_175 ) ;
F_95 ( & V_124 -> V_129 , V_175 ) ;
if ( ! V_124 -> V_129 ) {
if ( V_122 != F_97 ( V_177 -> V_125 ) - 1 ) {
memmove ( V_124 , V_124 + 1 ,
( F_97 ( V_177 -> V_125 ) - V_122 - 1 ) *
sizeof( struct V_120 ) ) ;
memset ( & V_177 -> V_126 [ F_97 ( V_177 -> V_125 ) - 1 ] ,
0 , sizeof( struct V_120 ) ) ;
}
F_123 ( & V_177 -> V_125 , - 1 ) ;
} else if ( V_174 )
F_124 ( V_11 , V_122 ) ;
F_90 ( V_72 , V_117 ) ;
V_53:
return V_50 ;
}
static int F_127 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * * V_117 ,
struct V_73 * V_74 )
{
int V_50 ;
T_4 V_80 ;
T_2 V_81 ;
T_1 V_82 , V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_7 * V_78 = NULL ;
struct V_10 * V_178 ;
struct V_10 * V_179 =
(struct V_10 * ) V_51 -> V_12 ;
V_50 = F_85 ( V_72 , V_3 , V_51 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_82 ( V_72 , V_74 , 1 , & V_82 ,
& V_80 , & V_81 ,
& V_29 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_78 = F_83 ( V_6 , V_29 ) ;
if ( V_78 == NULL ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
F_84 ( V_3 , V_78 ) ;
V_50 = F_85 ( V_72 , V_3 , V_78 ,
V_88 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
memcpy ( V_78 -> V_12 , V_51 -> V_12 , V_6 -> V_89 ) ;
V_178 = (struct V_10 * ) V_78 -> V_12 ;
V_178 -> V_91 = F_86 ( V_74 -> V_92 ) ;
V_178 -> V_93 = F_87 ( V_82 ) ;
V_178 -> V_94 = F_86 ( V_80 ) ;
V_178 -> V_18 = F_87 ( V_29 ) ;
V_178 -> V_180 = F_88 ( 0 ) ;
V_178 -> V_181 = F_87 ( V_51 -> V_13 ) ;
V_178 -> V_162 = F_88 ( V_182 ) ;
F_90 ( V_72 , V_78 ) ;
memset ( & V_179 -> V_164 , 0 , V_6 -> V_89 -
F_128 ( struct V_10 , V_164 ) ) ;
V_179 -> V_164 . V_183 = F_86 ( F_129 ( V_6 ) ) ;
V_179 -> V_184 = F_88 ( 1 ) ;
V_179 -> V_164 . V_148 = F_86 ( 1 ) ;
V_179 -> V_164 . V_149 [ 0 ] . V_155 = F_87 ( V_29 ) ;
V_179 -> V_164 . V_149 [ 0 ] . V_185 = F_86 ( 1 ) ;
V_179 -> V_162 = F_88 ( V_163 ) ;
F_90 ( V_72 , V_51 ) ;
F_130 ( ( unsigned long long ) V_29 ,
F_97 ( V_178 -> V_96 . V_125 ) ) ;
* V_117 = V_78 ;
V_78 = NULL ;
V_53:
F_58 ( V_78 ) ;
return V_50 ;
}
static int F_131 ( struct V_120 * V_186 ,
struct V_120 * V_187 )
{
if ( F_132 ( V_186 ) + F_12 ( V_186 -> V_128 ) <=
F_132 ( V_187 ) )
return 1 ;
return 0 ;
}
static int F_133 ( const void * V_188 , const void * V_189 )
{
const struct V_120 * V_190 = V_188 , * V_191 = V_189 ;
T_2 V_192 = F_132 ( V_190 ) ;
T_2 V_127 = F_132 ( V_191 ) ;
if ( V_192 > V_127 )
return 1 ;
if ( V_192 < V_127 )
return - 1 ;
return 0 ;
}
static int F_134 ( const void * V_188 , const void * V_189 )
{
const struct V_120 * V_190 = V_188 , * V_191 = V_189 ;
T_1 V_192 = F_11 ( V_190 -> V_127 ) ;
T_1 V_127 = F_11 ( V_191 -> V_127 ) ;
if ( V_192 > V_127 )
return 1 ;
if ( V_192 < V_127 )
return - 1 ;
return 0 ;
}
static void F_135 ( void * V_188 , void * V_189 , int V_193 )
{
struct V_120 * V_190 = V_188 , * V_191 = V_189 , V_22 ;
V_22 = * V_190 ;
* V_190 = * V_191 ;
* V_191 = V_22 ;
}
static int F_136 ( struct V_176 * V_177 ,
T_2 * V_194 , int * V_195 )
{
int V_196 = F_97 ( V_177 -> V_125 ) ;
int V_197 , V_198 = V_196 / 2 ;
for ( V_197 = 0 ; V_197 < V_198 ; V_197 ++ ) {
if ( F_131 (
& V_177 -> V_126 [ V_198 - V_197 - 1 ] ,
& V_177 -> V_126 [ V_198 - V_197 ] ) ) {
* V_195 = V_198 - V_197 ;
break;
}
if ( ( V_198 + V_197 + 1 ) == V_196 )
continue;
if ( F_131 (
& V_177 -> V_126 [ V_198 + V_197 ] ,
& V_177 -> V_126 [ V_198 + V_197 + 1 ] ) ) {
* V_195 = V_198 + V_197 + 1 ;
break;
}
}
if ( V_197 >= V_198 )
return - V_199 ;
* V_194 = F_132 ( & V_177 -> V_126 [ * V_195 ] ) ;
return 0 ;
}
static int F_137 ( struct V_7 * V_117 ,
struct V_7 * V_78 ,
T_2 * V_200 )
{
int V_195 = 0 , V_201 , V_50 ;
T_2 V_118 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_177 = & V_11 -> V_96 ;
struct V_10 * V_178 =
(struct V_10 * ) V_78 -> V_12 ;
struct V_176 * V_202 = & V_178 -> V_96 ;
F_138 (
( unsigned long long ) V_117 -> V_13 ,
F_97 ( V_177 -> V_97 ) , F_97 ( V_177 -> V_125 ) ) ;
F_139 ( & V_177 -> V_126 , F_97 ( V_177 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_133 , F_135 ) ;
V_50 = F_136 ( V_177 , & V_118 , & V_195 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_178 -> V_180 = F_88 ( V_118 ) ;
V_201 = F_97 ( V_177 -> V_125 ) - V_195 ;
memcpy ( V_202 -> V_126 , & V_177 -> V_126 [ V_195 ] ,
V_201 * sizeof( struct V_120 ) ) ;
memset ( & V_177 -> V_126 [ V_195 ] , 0 ,
V_201 * sizeof( struct V_120 ) ) ;
F_123 ( & V_177 -> V_125 , - V_201 ) ;
V_202 -> V_125 = F_86 ( V_201 ) ;
F_139 ( & V_177 -> V_126 , F_97 ( V_177 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_134 , F_135 ) ;
F_139 ( & V_202 -> V_126 , F_97 ( V_202 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_134 , F_135 ) ;
* V_200 = V_118 ;
return 0 ;
}
static int F_140 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_73 * V_74 )
{
int V_50 ;
T_4 V_80 ;
T_2 V_81 , V_203 ;
T_1 V_82 , V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_179 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_7 * V_78 = NULL ;
struct V_10 * V_178 ;
struct V_145 V_204 ;
F_5 ( ! ( F_12 ( V_179 -> V_162 ) & V_163 ) ) ;
V_50 = F_85 ( V_72 , V_3 , V_51 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_82 ( V_72 , V_74 , 1 , & V_82 ,
& V_80 , & V_81 ,
& V_29 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_78 = F_83 ( V_6 , V_29 ) ;
if ( V_78 == NULL ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
F_84 ( V_3 , V_78 ) ;
V_50 = F_85 ( V_72 , V_3 , V_78 ,
V_88 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_178 = (struct V_10 * ) V_78 -> V_12 ;
memset ( V_178 , 0 , V_6 -> V_89 ) ;
strcpy ( ( void * ) V_178 , V_90 ) ;
V_178 -> V_91 = F_86 ( V_74 -> V_92 ) ;
V_178 -> V_93 = F_87 ( V_82 ) ;
V_178 -> V_94 = F_86 ( V_80 ) ;
V_178 -> V_19 = F_88 ( F_13 ( V_6 ) -> V_20 ) ;
V_178 -> V_18 = F_87 ( V_29 ) ;
V_178 -> V_181 = F_87 ( V_51 -> V_13 ) ;
V_178 -> V_162 = F_88 ( V_182 ) ;
V_178 -> V_96 . V_97 =
F_86 ( F_89 ( V_6 ) ) ;
V_178 -> V_55 = V_179 -> V_55 ;
V_50 = F_137 ( V_117 , V_78 , & V_203 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_90 ( V_72 , V_117 ) ;
F_90 ( V_72 , V_78 ) ;
F_109 ( & V_204 , V_3 , V_51 ) ;
F_141 (
( unsigned long long ) V_78 -> V_13 , V_203 ) ;
V_50 = F_142 ( V_72 , & V_204 , V_203 , V_78 -> V_13 ,
1 , 0 , V_74 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_58 ( V_78 ) ;
return V_50 ;
}
static int F_143 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_73 * V_74 )
{
int V_50 ;
struct V_7 * V_205 = NULL ;
if ( V_51 == V_117 ) {
V_50 = F_127 ( V_72 , V_3 , V_51 ,
& V_205 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
} else {
V_205 = V_117 ;
F_117 ( V_205 ) ;
}
V_50 = F_140 ( V_72 , V_3 , V_51 ,
V_205 , V_74 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_58 ( V_205 ) ;
return V_50 ;
}
static int F_144 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_120 * V_124 )
{
int V_50 = 0 , V_123 ;
T_2 V_203 , V_206 ;
struct V_142 * V_207 = NULL ;
struct V_145 V_146 ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_138 * V_139 ;
if ( ! ( F_12 ( V_11 -> V_162 ) & V_163 ) )
goto V_53;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
V_206 = F_12 ( V_11 -> V_180 ) ;
V_203 = F_11 ( V_124 -> V_127 ) & V_165 ;
if ( V_206 <= V_203 )
goto V_53;
F_109 ( & V_146 , V_3 , V_51 ) ;
V_207 = F_110 ( & V_146 ) ;
if ( ! V_207 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_111 ( V_3 , V_207 , V_206 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_145 ( V_72 , 2 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_146 ( V_72 , V_3 , F_147 ( V_207 ) ,
V_86 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_139 = F_148 ( V_207 ) ;
for ( V_123 = 0 ; V_123 < F_97 ( V_139 -> V_148 ) ; V_123 ++ )
if ( F_12 ( V_139 -> V_149 [ V_123 ] . V_150 ) == V_206 )
break;
F_5 ( V_123 == F_97 ( V_139 -> V_148 ) ) ;
V_139 -> V_149 [ V_123 ] . V_150 = F_88 ( V_203 ) ;
V_11 -> V_180 = F_88 ( V_203 ) ;
F_90 ( V_72 , F_147 ( V_207 ) ) ;
F_90 ( V_72 , V_117 ) ;
V_53:
F_115 ( V_207 ) ;
return V_50 ;
}
static int F_149 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_120 * V_124 ,
int V_122 , int V_174 ,
struct V_73 * V_74 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_164 = & V_11 -> V_96 ;
struct V_7 * V_78 = NULL ;
F_5 ( F_12 ( V_11 -> V_162 ) & V_163 ) ;
if ( V_164 -> V_125 == V_164 -> V_97 ) {
T_1 V_118 = F_11 ( V_124 -> V_127 ) ;
T_2 V_119 = F_12 ( V_124 -> V_128 ) ;
V_50 = F_143 ( V_72 , V_3 , V_51 ,
V_117 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , NULL , & V_122 ,
& V_78 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_117 = V_78 ;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
V_164 = & V_11 -> V_96 ;
}
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_122 < F_97 ( V_164 -> V_125 ) )
memmove ( & V_164 -> V_126 [ V_122 + 1 ] ,
& V_164 -> V_126 [ V_122 ] ,
( F_97 ( V_164 -> V_125 ) - V_122 ) *
sizeof( struct V_120 ) ) ;
F_150 (
( unsigned long long ) V_117 -> V_13 , V_122 ,
( unsigned long long ) F_11 ( V_124 -> V_127 ) ,
F_12 ( V_124 -> V_128 ) , F_12 ( V_124 -> V_129 ) ) ;
V_164 -> V_126 [ V_122 ] = * V_124 ;
F_123 ( & V_164 -> V_125 , 1 ) ;
if ( V_174 )
F_124 ( V_11 , V_122 ) ;
F_90 ( V_72 , V_117 ) ;
if ( V_122 == 0 ) {
V_50 = F_144 ( V_72 , V_3 ,
V_51 ,
V_117 , V_124 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_53:
F_58 ( V_78 ) ;
return V_50 ;
}
static int F_151 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_120 * V_208 ,
int V_122 , int V_174 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 , V_211 ;
T_2 V_119 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_164 = & V_11 -> V_96 ;
struct V_120 * V_212 = & V_164 -> V_126 [ V_122 ] ;
struct V_120 * V_213 = NULL ;
struct V_7 * V_78 = NULL ;
F_5 ( F_12 ( V_11 -> V_162 ) & V_163 ) ;
F_152 ( F_11 ( V_212 -> V_127 ) ,
F_12 ( V_212 -> V_128 ) ,
F_12 ( V_212 -> V_129 ) ,
F_11 ( V_208 -> V_127 ) ,
F_12 ( V_208 -> V_128 ) ,
F_12 ( V_208 -> V_129 ) ) ;
if ( ! V_208 -> V_129 &&
( V_208 -> V_127 == V_212 -> V_127 ||
F_11 ( V_208 -> V_127 ) +
F_12 ( V_208 -> V_128 ) ==
F_11 ( V_212 -> V_127 ) + F_12 ( V_212 -> V_128 ) ) )
V_211 = 0 ;
else
V_211 = 1 ;
if ( V_208 -> V_129 &&
( V_208 -> V_127 != V_212 -> V_127 &&
F_11 ( V_208 -> V_127 ) +
F_12 ( V_208 -> V_128 ) !=
F_11 ( V_212 -> V_127 ) + F_12 ( V_212 -> V_128 ) ) )
V_211 ++ ;
if ( F_97 ( V_164 -> V_125 ) + V_211 >
F_97 ( V_164 -> V_97 ) ) {
struct V_120 V_214 ;
T_1 V_118 = F_11 ( V_212 -> V_127 ) ;
V_119 = F_12 ( V_212 -> V_128 ) ;
V_50 = F_143 ( V_72 , V_3 , V_51 ,
V_117 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , & V_214 , & V_122 ,
& V_78 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_117 = V_78 ;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
V_164 = & V_11 -> V_96 ;
V_212 = & V_164 -> V_126 [ V_122 ] ;
}
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_122 != F_97 ( V_164 -> V_125 ) - 1 )
memmove ( & V_164 -> V_126 [ V_122 + 1 + V_211 ] ,
& V_164 -> V_126 [ V_122 + 1 ] ,
( F_97 ( V_164 -> V_125 ) - V_122 - 1 ) *
sizeof( struct V_120 ) ) ;
V_119 = ( F_11 ( V_212 -> V_127 ) +
F_12 ( V_212 -> V_128 ) ) -
( F_11 ( V_208 -> V_127 ) +
F_12 ( V_208 -> V_128 ) ) ;
if ( V_119 ) {
V_213 = & V_164 -> V_126 [ V_122 + V_211 ] ;
memcpy ( V_213 , V_212 , sizeof( struct V_120 ) ) ;
F_153 ( & V_213 -> V_127 ,
F_12 ( V_213 -> V_128 ) - V_119 ) ;
V_213 -> V_128 = F_88 ( V_119 ) ;
}
if ( V_208 -> V_127 != V_212 -> V_127 && V_213 != V_212 ) {
V_119 = F_11 ( V_208 -> V_127 ) -
F_11 ( V_212 -> V_127 ) ;
V_212 -> V_128 = F_88 ( V_119 ) ;
V_122 ++ ;
}
F_123 ( & V_164 -> V_125 , V_211 ) ;
if ( V_208 -> V_129 ) {
V_164 -> V_126 [ V_122 ] = * V_208 ;
F_154 (
( unsigned long long ) V_117 -> V_13 , V_122 ,
( unsigned long long ) F_11 ( V_208 -> V_127 ) ,
F_12 ( V_208 -> V_128 ) ,
F_12 ( V_208 -> V_129 ) ) ;
if ( V_174 )
F_124 ( V_11 , V_122 ) ;
}
F_90 ( V_72 , V_117 ) ;
V_53:
F_58 ( V_78 ) ;
return V_50 ;
}
static int F_155 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_118 , T_2 V_119 , int V_174 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 = 0 , V_122 ;
struct V_7 * V_117 = NULL ;
struct V_120 V_124 ;
unsigned int V_215 = 0 ;
F_156 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_118 , V_119 ) ;
while ( V_119 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , & V_124 , & V_122 ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_215 = F_12 ( V_124 . V_128 ) ;
if ( V_124 . V_129 && F_11 ( V_124 . V_127 ) == V_118 &&
V_215 <= V_119 ) {
F_157 (
( unsigned long long ) V_118 , V_215 ,
F_12 ( V_124 . V_129 ) ) ;
V_50 = F_125 ( V_72 , V_3 ,
V_117 , V_122 ,
V_174 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
} else if ( ! V_124 . V_129 ) {
V_124 . V_129 = F_88 ( 1 ) ;
F_158 (
( unsigned long long ) F_11 ( V_124 . V_127 ) ,
V_215 ) ;
V_50 = F_149 ( V_72 , V_3 , V_51 ,
V_117 ,
& V_124 , V_122 ,
V_174 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
} else {
V_215 = F_159 ( ( T_1 ) ( V_118 + V_119 ) ,
F_11 ( V_124 . V_127 ) + V_215 ) - V_118 ;
V_124 . V_127 = F_87 ( V_118 ) ;
V_124 . V_128 = F_88 ( V_215 ) ;
F_95 ( & V_124 . V_129 , 1 ) ;
F_160 (
( unsigned long long ) F_11 ( V_124 . V_127 ) ,
V_215 , F_12 ( V_124 . V_129 ) ) ;
V_50 = F_151 ( V_72 , V_3 ,
V_51 , V_117 ,
& V_124 , V_122 , V_174 ,
V_74 , V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_215 ;
V_119 -= V_215 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
}
V_53:
F_58 ( V_117 ) ;
return V_50 ;
}
static int F_161 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_145 V_146 ;
F_5 ( V_11 -> V_96 . V_125 ) ;
F_162 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_117 -> V_13 ,
F_12 ( V_11 -> V_180 ) ) ;
F_109 ( & V_146 , V_3 , V_51 ) ;
V_50 = F_163 ( V_72 , & V_146 , F_12 ( V_11 -> V_180 ) ,
1 , V_74 , V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_164 ( V_3 , V_117 ) ;
V_50 = F_165 ( V_210 , V_112 ,
F_97 ( V_11 -> V_91 ) ,
F_11 ( V_11 -> V_93 ) ,
F_11 ( V_11 -> V_18 ) ,
F_97 ( V_11 -> V_94 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_85 ( V_72 , V_3 , V_51 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
F_95 ( & V_11 -> V_184 , - 1 ) ;
if ( ! V_11 -> V_164 . V_148 ) {
F_5 ( V_11 -> V_184 ) ;
F_166 (
( unsigned long long ) V_51 -> V_13 ) ;
V_11 -> V_162 = 0 ;
V_11 -> V_181 = 0 ;
V_11 -> V_180 = 0 ;
memset ( & V_11 -> V_96 , 0 , V_6 -> V_89 -
F_128 ( struct V_10 , V_96 ) ) ;
V_11 -> V_96 . V_97 =
F_86 ( F_89 ( V_6 ) ) ;
}
F_90 ( V_72 , V_51 ) ;
V_53:
return V_50 ;
}
int F_167 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_118 , T_2 V_119 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
return F_155 ( V_72 , V_3 , V_51 ,
V_118 , V_119 , 1 ,
V_74 , V_210 ) ;
}
static int F_168 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
int V_122 , T_1 V_118 , unsigned int V_119 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_120 * V_124 = & V_11 -> V_96 . V_126 [ V_122 ] ;
F_5 ( V_118 < F_11 ( V_124 -> V_127 ) ) ;
F_5 ( V_118 + V_119 >
F_11 ( V_124 -> V_127 ) + F_12 ( V_124 -> V_128 ) ) ;
F_169 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_118 , V_119 ) ;
if ( V_118 == F_11 ( V_124 -> V_127 ) &&
V_119 == F_12 ( V_124 -> V_128 ) )
V_50 = F_125 ( V_72 , V_3 ,
V_117 , V_122 , 1 , - 1 ) ;
else {
struct V_120 V_216 = * V_124 ;
V_216 . V_127 = F_87 ( V_118 ) ;
V_216 . V_128 = F_88 ( V_119 ) ;
F_95 ( & V_216 . V_129 , - 1 ) ;
V_50 = F_151 ( V_72 , V_3 ,
V_51 , V_117 ,
& V_216 , V_122 , 1 ,
V_74 , V_210 ) ;
}
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( ! V_11 -> V_96 . V_125 && V_117 != V_51 ) {
V_50 = F_161 ( V_72 , V_3 , V_51 ,
V_117 , V_74 ,
V_210 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_53:
return V_50 ;
}
static int F_170 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_118 , T_2 V_119 ,
struct V_73 * V_74 ,
struct V_209 * V_210 ,
int V_217 )
{
int V_50 = 0 , V_122 = 0 ;
struct V_120 V_124 ;
unsigned int V_218 = 0 , V_219 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_7 * V_117 = NULL ;
F_171 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_118 , V_119 , V_217 ) ;
while ( V_119 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , & V_124 , & V_122 ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_218 = F_12 ( V_124 . V_129 ) ;
F_5 ( V_218 == 0 ) ;
if ( ! V_217 )
F_5 ( V_218 > 1 ) ;
V_219 = F_159 ( ( T_1 ) ( V_118 + V_119 ) , F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_118 ;
V_50 = F_168 ( V_72 , V_3 , V_51 ,
V_117 , V_122 ,
V_118 , V_219 ,
V_74 , V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( F_12 ( V_124 . V_129 ) == 1 && V_217 ) {
V_50 = F_172 ( V_210 ,
F_173 ( V_6 , V_118 ) ,
V_219 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_219 ;
V_119 -= V_219 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
}
V_53:
F_58 ( V_117 ) ;
return V_50 ;
}
int F_174 ( struct V_56 * V_56 ,
T_3 * V_72 , T_2 V_118 , T_2 V_119 ,
struct V_73 * V_74 ,
struct V_209 * V_210 ,
int V_217 )
{
int V_50 ;
T_1 V_57 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_59 ( V_56 , & V_57 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_55 ( F_13 ( V_56 -> V_77 ) , V_57 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_14 ( & V_33 -> V_4 , V_33 -> V_18 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_170 ( V_72 , & V_33 -> V_4 , V_51 ,
V_118 , V_119 , V_74 , V_210 , V_217 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_175 ( struct V_56 * V_56 ,
struct V_145 * V_146 ,
T_3 * V_72 , T_2 V_118 ,
T_2 V_119 , T_2 V_220 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 ;
F_176 ( F_61 ( V_56 ) -> V_84 ,
V_118 , V_119 , V_220 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_221 ) ;
V_50 = - V_167 ;
goto V_53;
}
V_50 = F_177 ( V_72 , V_146 , V_118 ,
V_119 , V_220 , V_74 , V_210 ,
V_222 , 0 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
return V_50 ;
}
static int F_178 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_223 ,
T_2 V_224 ,
int * V_225 ,
int * V_107 )
{
int V_50 = 0 , V_122 , V_226 = 0 , V_227 = 0 ;
T_1 V_118 = V_223 ;
struct V_10 * V_11 ;
struct V_120 V_124 ;
struct V_7 * V_117 = NULL , * V_228 = NULL ;
T_2 V_119 ;
while ( V_224 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_224 , & V_124 ,
& V_122 , & V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_117 != V_228 ) {
if ( V_228 ) {
V_11 = (struct V_10 * )
V_228 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) +
V_227 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_226 ++ ;
}
V_227 = 0 ;
* V_107 += 1 ;
F_58 ( V_228 ) ;
V_228 = V_117 ;
F_117 ( V_228 ) ;
}
V_11 = (struct V_10 * ) V_117 -> V_12 ;
F_179 (
V_227 , ( unsigned long long ) V_118 , V_224 ,
( unsigned long long ) F_11 ( V_124 . V_127 ) ,
F_12 ( V_124 . V_128 ) ,
F_12 ( V_124 . V_129 ) , V_122 ) ;
V_119 = F_159 ( ( T_1 ) V_118 + V_224 , F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_118 ;
if ( V_124 . V_129 ) {
V_227 += 2 ;
if ( V_118 == V_223 &&
V_118 != F_11 ( V_124 . V_127 ) )
V_227 ++ ;
if ( V_118 + V_224 < F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) )
V_227 ++ ;
} else
V_227 ++ ;
F_58 ( V_117 ) ;
V_117 = NULL ;
V_224 -= V_119 ;
V_118 += V_119 ;
}
if ( V_228 ) {
V_11 = (struct V_10 * ) V_228 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) + V_227 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_226 ++ ;
* V_107 += 1 ;
}
if ( ! V_226 )
goto V_53;
* V_225 += V_226 ;
* V_107 += V_226 ;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_162 ) & V_163 ) {
struct V_145 V_146 ;
F_109 ( & V_146 , V_3 , V_51 ) ;
* V_225 += F_180 ( V_146 . V_229 ) ;
* V_107 += F_181 ( V_6 ,
V_146 . V_229 ) ;
} else {
* V_107 += V_230 ;
* V_225 += 1 ;
}
V_53:
F_182 (
( unsigned long long ) V_223 , V_224 ,
* V_225 , * V_107 ) ;
F_58 ( V_117 ) ;
F_58 ( V_228 ) ;
return V_50 ;
}
int F_183 ( struct V_56 * V_56 ,
T_1 V_101 ,
T_1 V_231 ,
T_2 V_224 ,
int * V_107 ,
int * V_226 )
{
int V_50 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
T_1 V_223 = F_184 ( V_56 -> V_77 , V_231 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_221 ) ;
V_50 = - V_167 ;
goto V_53;
}
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_55 ( F_13 ( V_56 -> V_77 ) ,
V_101 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_14 ( & V_33 -> V_4 , V_101 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_178 ( V_56 -> V_77 ,
& V_33 -> V_4 ,
V_51 ,
V_223 , V_224 ,
V_226 , V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_185 ( * V_226 , * V_107 ) ;
V_53:
F_58 ( V_51 ) ;
return V_50 ;
}
static inline unsigned int F_186 ( struct V_5 * V_6 )
{
return F_187 ( V_6 , V_232 ) ;
}
static inline unsigned int F_188 ( struct V_5 * V_6 )
{
return ~ ( F_186 ( V_6 ) - 1 ) ;
}
static inline unsigned int F_189 ( struct V_5 * V_6 ,
unsigned int V_233 ,
unsigned int V_118 )
{
F_5 ( V_233 > V_118 ) ;
return V_233 + ( ( V_118 - V_233 ) & F_188 ( V_6 ) ) ;
}
static inline unsigned int F_190 ( struct V_5 * V_6 ,
unsigned int V_119 )
{
unsigned int V_234 =
( V_119 + ( F_186 ( V_6 ) - 1 ) ) &
F_188 ( V_6 ) ;
if ( V_234 < V_119 )
V_234 = V_152 ;
return V_234 ;
}
static int F_191 ( struct V_56 * V_56 ,
struct V_138 * V_139 ,
T_2 V_118 ,
T_2 V_235 ,
T_2 V_236 ,
T_2 * V_237 ,
T_2 * V_238 )
{
int V_50 = 0 ;
int V_239 = F_97 ( V_139 -> V_166 ) , V_123 ;
struct V_7 * V_161 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_160 * V_124 ;
unsigned int V_240 , V_241 = 0 ;
int V_242 = F_186 ( V_56 -> V_77 ) ;
int V_243 ;
F_5 ( V_118 + V_235 > V_236 ) ;
if ( V_239 > 0 ) {
V_50 = F_118 ( F_81 ( V_56 ) , V_139 , V_118 , & V_161 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_137 = (struct V_136 * ) V_161 -> V_12 ;
V_139 = & V_137 -> V_153 ;
if ( V_139 -> V_166 ) {
F_10 ( V_56 -> V_77 ,
L_13
L_14 , V_56 -> V_221 ,
( unsigned long long ) V_161 -> V_13 ) ;
V_50 = - V_167 ;
goto V_53;
}
}
* V_238 = 0 ;
for ( V_123 = 0 ; V_123 < F_97 ( V_139 -> V_148 ) ; V_123 ++ ) {
V_124 = & V_139 -> V_149 [ V_123 ] ;
if ( F_192 ( V_124 ) ) {
F_193 ( V_123 != 0 , L_15
L_16 , V_56 -> V_221 , V_123 ) ;
continue;
}
if ( F_12 ( V_124 -> V_150 ) +
F_97 ( V_124 -> V_185 ) <= V_118 )
continue;
if ( * V_238 == 0 ) {
F_5 ( ! ( V_124 -> V_244 & V_222 ) ) ;
* V_237 = F_12 ( V_124 -> V_150 ) ;
}
if ( ( ! ( V_124 -> V_244 & V_222 ) ) ||
( * V_238 && V_241 != F_12 ( V_124 -> V_150 ) ) ||
( V_236 <= F_12 ( V_124 -> V_150 ) ) )
break;
V_243 = F_97 ( V_124 -> V_185 ) ;
V_241 = F_12 ( V_124 -> V_150 ) + V_243 ;
if ( V_241 > V_236 ) {
V_241 = V_236 ;
V_243 = V_241 - F_12 ( V_124 -> V_150 ) ;
}
if ( ! * V_238 )
V_240 = V_235 ;
else
V_240 = ( V_118 + V_235 ) -
( * V_237 + * V_238 ) ;
if ( V_240 < V_242 )
V_240 = V_242 ;
if ( V_243 <= V_242 )
* V_238 += V_243 ;
else if ( * V_238 || ( * V_237 == V_118 ) ) {
V_240 = F_190 ( V_56 -> V_77 ,
V_240 ) ;
if ( V_243 < V_240 )
* V_238 += V_243 ;
else
* V_238 += V_240 ;
} else if ( ( * V_237 + V_242 ) >=
( V_118 + V_235 ) ) {
* V_238 = V_242 ;
} else if ( ( V_241 - V_118 ) <= V_242 ) {
* V_237 = V_241 - V_242 ;
* V_238 = V_242 ;
} else if ( ( V_241 - V_118 ) <= V_240 ) {
* V_237 = F_189 ( V_56 -> V_77 ,
* V_237 , V_118 ) ;
* V_238 = V_241 - * V_237 ;
} else {
* V_237 = F_189 ( V_56 -> V_77 ,
* V_237 , V_118 ) ;
V_240 = ( V_118 + V_235 ) - * V_237 ;
V_240 = F_190 ( V_56 -> V_77 ,
V_240 ) ;
if ( * V_237 + V_240 <= V_241 )
* V_238 = V_240 ;
else
* V_238 = V_241 - * V_237 ;
}
if ( ( * V_237 + * V_238 ) >= ( V_118 + V_235 ) )
break;
if ( V_123 + 1 == F_97 ( V_139 -> V_148 ) &&
V_137 && V_137 -> V_151 ) {
F_58 ( V_161 ) ;
V_161 = NULL ;
V_50 = F_194 ( F_81 ( V_56 ) ,
F_11 ( V_137 -> V_151 ) ,
& V_161 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_137 = (struct V_136 * ) V_161 -> V_12 ;
V_139 = & V_137 -> V_153 ;
V_123 = - 1 ;
}
}
V_53:
F_58 ( V_161 ) ;
return V_50 ;
}
static int F_195 ( struct V_5 * V_6 ,
T_2 V_245 , T_2 V_246 ,
struct V_145 * V_146 ,
struct V_2 * V_247 ,
struct V_7 * V_51 ,
struct V_73 * * V_74 ,
struct V_73 * * V_248 ,
int * V_107 )
{
int V_50 = 0 , V_225 = 0 ;
int V_249 = F_196 ( F_13 ( V_6 ) , V_146 ) ;
if ( V_249 < 0 ) {
V_50 = V_249 ;
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_249 < V_246 + 2 )
V_225 =
F_180 ( V_146 -> V_229 ) ;
* V_107 += F_181 ( V_6 , V_146 -> V_229 ) ;
V_50 = F_178 ( V_6 , V_247 , V_51 ,
V_245 , V_246 ,
& V_225 , V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_197 ( V_225 , * V_107 ) ;
V_50 = F_76 ( F_13 ( V_6 ) , V_225 ,
V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_248 ) {
V_50 = F_198 ( F_13 ( V_6 ) , V_246 ,
V_248 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_53:
if ( V_50 ) {
if ( * V_74 ) {
F_93 ( * V_74 ) ;
* V_74 = NULL ;
}
}
return V_50 ;
}
static int F_199 ( T_3 * V_72 , struct V_7 * V_8 )
{
F_5 ( F_200 ( V_8 ) ) ;
F_201 ( V_8 ) ;
return 0 ;
}
int F_202 ( T_3 * V_72 ,
struct V_56 * V_56 ,
T_2 V_118 , T_2 V_250 ,
T_2 V_251 , T_2 V_252 )
{
int V_50 = 0 , V_253 ;
struct V_5 * V_6 = V_56 -> V_77 ;
T_1 V_254 = F_173 ( V_6 , V_251 ) ;
struct V_255 * V_255 ;
T_5 V_256 ;
unsigned int V_257 , V_258 , V_259 ;
T_6 V_260 , V_261 , V_262 ;
struct V_263 * V_264 = V_56 -> V_265 ;
F_203 ( V_118 , V_250 ,
V_251 , V_252 ) ;
V_259 =
( F_186 ( V_6 ) <<
F_13 ( V_6 ) -> V_266 ) >> V_267 ;
V_260 = ( ( T_6 ) V_118 ) << F_13 ( V_6 ) -> V_266 ;
V_261 = V_260 + ( V_252 << F_13 ( V_6 ) -> V_266 ) ;
if ( V_261 > F_204 ( V_56 ) )
V_261 = F_204 ( V_56 ) ;
while ( V_260 < V_261 ) {
V_256 = V_260 >> V_267 ;
V_262 = ( ( T_6 ) V_256 + 1 ) << V_267 ;
if ( V_262 > V_261 )
V_262 = V_261 ;
V_257 = V_260 & ( V_268 - 1 ) ;
V_258 = V_268 ;
if ( V_262 & ( V_268 - 1 ) )
V_258 = V_262 & ( V_268 - 1 ) ;
V_255 = F_205 ( V_264 , V_256 , V_48 ) ;
if ( ! V_255 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
break;
}
if ( V_268 <= F_13 ( V_6 ) -> V_269 )
F_5 ( F_206 ( V_255 ) ) ;
if ( ! F_207 ( V_255 ) ) {
V_50 = F_208 ( V_255 , V_270 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_271;
}
F_209 ( V_255 ) ;
}
if ( F_210 ( V_255 ) ) {
V_50 = F_211 ( V_72 , F_212 ( V_255 ) ,
V_257 , V_258 , & V_253 ,
F_199 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_271;
}
}
F_213 ( V_56 ,
V_72 , V_257 , V_258 ,
V_255 , 0 , & V_254 ) ;
F_214 ( V_255 ) ;
V_271:
F_215 ( V_255 ) ;
F_216 ( V_255 ) ;
V_255 = NULL ;
V_260 = V_262 ;
if ( V_50 )
break;
}
return V_50 ;
}
int F_217 ( T_3 * V_72 ,
struct V_56 * V_56 ,
T_2 V_118 , T_2 V_250 ,
T_2 V_251 , T_2 V_252 )
{
int V_50 = 0 ;
struct V_5 * V_6 = V_56 -> V_77 ;
struct V_2 * V_3 = F_81 ( V_56 ) ;
int V_123 , V_272 = F_173 ( V_6 , V_252 ) ;
T_1 V_273 = F_173 ( V_6 , V_250 ) ;
T_1 V_254 = F_173 ( V_6 , V_251 ) ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
struct V_7 * V_274 = NULL ;
struct V_7 * V_78 = NULL ;
F_203 ( V_118 , V_250 ,
V_251 , V_252 ) ;
for ( V_123 = 0 ; V_123 < V_272 ; V_123 ++ , V_273 ++ , V_254 ++ ) {
V_78 = F_83 ( V_28 -> V_6 , V_254 ) ;
if ( V_78 == NULL ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
break;
}
F_84 ( V_3 , V_78 ) ;
V_50 = F_15 ( V_3 , V_273 , & V_274 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_50 = F_218 ( V_72 , V_3 , V_78 ,
V_88 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
memcpy ( V_78 -> V_12 , V_274 -> V_12 , V_6 -> V_89 ) ;
F_90 ( V_72 , V_78 ) ;
F_58 ( V_78 ) ;
F_58 ( V_274 ) ;
V_78 = NULL ;
V_274 = NULL ;
}
F_58 ( V_78 ) ;
F_58 ( V_274 ) ;
return V_50 ;
}
static int F_219 ( T_3 * V_72 ,
struct V_145 * V_146 ,
T_2 V_118 , T_2 V_245 , T_2 V_119 ,
unsigned int V_275 ,
struct V_73 * V_74 ,
struct V_209 * V_210 )
{
int V_50 , V_122 ;
struct V_160 V_276 ;
struct V_142 * V_207 = NULL ;
struct V_138 * V_139 ;
struct V_5 * V_6 = F_108 ( V_146 -> V_277 ) ;
T_1 V_278 = F_119 ( V_146 -> V_277 ) ;
F_220 ( ( unsigned long long ) V_278 ,
V_118 , V_119 , V_245 , V_275 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_276 . V_150 = F_88 ( V_118 ) ;
V_276 . V_185 = F_86 ( V_119 ) ;
V_276 . V_155 = F_87 ( F_173 ( V_6 ,
V_245 ) ) ;
V_276 . V_244 = V_275 ;
V_276 . V_244 &= ~ V_222 ;
V_207 = F_110 ( V_146 ) ;
if ( ! V_207 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_111 ( V_146 -> V_277 , V_207 , V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_139 = F_148 ( V_207 ) ;
V_122 = F_221 ( V_139 , V_118 ) ;
if ( V_122 == - 1 ) {
F_10 ( V_6 ,
L_17
L_18 ,
( unsigned long long ) V_278 , V_118 ) ;
V_50 = - V_167 ;
goto V_53;
}
V_50 = F_222 ( V_72 , V_146 , V_207 , V_122 ,
& V_276 , V_74 , V_210 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_115 ( V_207 ) ;
return V_50 ;
}
static int F_223 ( T_3 * V_72 ,
struct V_279 * V_280 ,
T_2 V_118 , T_2 V_281 ,
T_2 V_37 , T_2 V_119 ,
unsigned int V_275 )
{
int V_50 ;
struct V_2 * V_3 = V_280 -> V_282 . V_277 ;
T_1 V_278 = F_119 ( V_3 ) ;
F_224 ( ( unsigned long long ) V_278 ,
V_118 , V_281 , V_37 , V_119 , V_275 ) ;
if ( ! ( V_275 & V_283 ) ) {
V_50 = V_280 -> V_284 ( V_72 , V_280 -> V_56 ,
V_118 , V_281 , V_37 , V_119 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_50 = F_219 ( V_72 , & V_280 -> V_282 ,
V_118 , V_37 , V_119 , V_275 ,
V_280 -> V_74 , & V_280 -> V_210 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
return V_50 ;
}
int F_225 ( struct V_5 * V_6 ,
struct V_56 * V_56 ,
T_2 V_118 , T_2 V_246 )
{
int V_50 = 0 ;
T_6 V_260 , V_261 , V_262 ;
T_5 V_256 ;
struct V_255 * V_255 ;
if ( F_226 ( V_56 ) )
return 0 ;
V_260 = ( ( T_6 ) V_118 ) << F_13 ( V_6 ) -> V_266 ;
V_261 = V_260 + ( V_246 << F_13 ( V_6 ) -> V_266 ) ;
V_50 = F_227 ( V_56 -> V_265 ,
V_260 , V_261 - 1 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
while ( V_260 < V_261 ) {
V_256 = V_260 >> V_267 ;
V_262 = ( ( T_6 ) V_256 + 1 ) << V_267 ;
if ( V_262 > V_261 )
V_262 = V_261 ;
V_255 = F_205 ( V_56 -> V_265 ,
V_256 , V_48 ) ;
F_5 ( ! V_255 ) ;
F_228 ( V_255 ) ;
if ( F_229 ( V_255 ) ) {
V_50 = - V_285 ;
F_56 ( V_50 ) ;
} else
F_214 ( V_255 ) ;
F_215 ( V_255 ) ;
F_216 ( V_255 ) ;
V_255 = NULL ;
V_260 = V_262 ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_230 ( struct V_279 * V_280 ,
T_2 V_286 , T_2 * V_245 ,
T_2 * V_246 ,
unsigned int * V_287 )
{
return F_231 ( V_280 -> V_56 , V_286 , V_245 ,
V_246 , V_287 ) ;
}
static int F_232 ( struct V_5 * V_6 ,
struct V_279 * V_280 ,
T_2 V_118 , T_2 V_245 ,
T_2 V_246 , unsigned int V_244 )
{
int V_50 , V_217 , V_122 , V_107 = 0 ;
T_2 V_288 , V_252 , V_289 ;
unsigned int V_215 ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
T_3 * V_72 ;
struct V_7 * V_117 = NULL ;
struct V_2 * V_247 = & V_280 -> V_102 -> V_4 ;
struct V_120 V_124 ;
F_233 ( V_118 , V_245 ,
V_246 , V_244 ) ;
V_50 = F_195 ( V_6 , V_245 , V_246 ,
& V_280 -> V_282 ,
V_247 ,
V_280 -> V_51 ,
& V_280 -> V_74 ,
& V_280 -> V_248 , & V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
if ( V_280 -> V_290 )
V_107 += V_280 -> V_290 -> V_107 ;
V_107 += V_280 -> V_291 ;
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_289 = V_246 ;
while ( V_246 ) {
V_50 = F_116 ( V_247 , V_280 -> V_51 ,
V_245 , V_246 ,
& V_124 , & V_122 , & V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
F_5 ( ! V_124 . V_129 ) ;
V_215 = F_159 ( ( T_1 ) V_245 + V_246 ,
F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_245 ;
if ( F_12 ( V_124 . V_129 ) == 1 ) {
V_217 = 0 ;
V_50 = F_219 ( V_72 ,
& V_280 -> V_282 ,
V_118 , V_245 ,
V_215 , V_244 ,
V_280 -> V_74 ,
& V_280 -> V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
} else {
V_217 = 1 ;
V_50 = F_234 ( V_72 ,
V_280 -> V_248 ,
1 , V_215 ,
& V_288 , & V_252 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_223 ( V_72 , V_280 ,
V_118 , V_245 , V_288 ,
V_252 , V_244 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_215 = V_252 ;
}
V_50 = F_170 ( V_72 , V_247 ,
V_280 -> V_51 ,
V_245 , V_215 ,
V_280 -> V_74 ,
& V_280 -> V_210 , V_217 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_118 += V_215 ;
V_245 += V_215 ;
V_246 -= V_215 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
}
if ( V_280 -> V_290 && V_280 -> V_290 -> V_292 ) {
V_50 = V_280 -> V_290 -> V_292 ( V_280 -> V_56 , V_72 ,
V_280 -> V_290 -> V_293 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
}
if ( V_280 -> V_294 == F_230 ) {
V_50 = F_225 ( V_6 , V_280 -> V_56 , V_118 ,
V_289 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_280 -> V_248 ) {
F_93 ( V_280 -> V_248 ) ;
V_280 -> V_248 = NULL ;
}
if ( V_280 -> V_74 ) {
F_93 ( V_280 -> V_74 ) ;
V_280 -> V_74 = NULL ;
}
F_58 ( V_117 ) ;
return V_50 ;
}
static int F_235 ( struct V_279 * V_280 )
{
int V_50 = 0 ;
struct V_56 * V_56 = V_280 -> V_56 ;
T_2 V_237 = V_280 -> V_237 , V_238 = V_280 -> V_238 ;
T_2 V_245 , V_246 ;
unsigned int V_275 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_221 ) ;
return - V_167 ;
}
F_236 ( & V_280 -> V_210 ) ;
while ( V_238 ) {
V_50 = V_280 -> V_294 ( V_280 , V_237 , & V_245 ,
& V_246 , & V_275 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
F_5 ( ! ( V_275 & V_222 ) ) ;
if ( V_238 < V_246 )
V_246 = V_238 ;
V_50 = F_232 ( V_56 -> V_77 , V_280 ,
V_237 , V_245 ,
V_246 , V_275 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_238 -= V_246 ;
V_237 += V_246 ;
}
if ( F_237 ( & V_280 -> V_210 ) ) {
F_238 ( V_28 , 1 ) ;
F_239 ( V_28 , & V_280 -> V_210 ) ;
}
return V_50 ;
}
static int F_240 ( struct V_56 * V_56 ,
struct V_7 * V_58 ,
T_2 V_118 , T_2 V_235 , T_2 V_236 )
{
int V_50 ;
T_2 V_237 = 0 , V_238 = 0 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_102 ;
struct V_279 * V_280 = NULL ;
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_191 ( V_56 , & V_60 -> V_295 . V_296 ,
V_118 , V_235 , V_236 ,
& V_237 , & V_238 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_241 ( F_61 ( V_56 ) -> V_84 ,
V_118 , V_235 , V_236 ,
V_237 , V_238 ) ;
F_5 ( V_238 == 0 ) ;
V_280 = F_53 ( sizeof( struct V_279 ) , V_48 ) ;
if ( ! V_280 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_66 ( V_28 , F_11 ( V_60 -> V_63 ) ,
1 , & V_102 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_280 -> V_56 = V_56 ;
V_280 -> V_237 = V_237 ;
V_280 -> V_238 = V_238 ;
V_280 -> V_102 = V_102 ;
V_280 -> V_51 = V_51 ;
V_280 -> V_284 = F_202 ;
V_280 -> V_294 = F_230 ;
F_242 ( & V_280 -> V_282 ,
F_81 ( V_56 ) , V_58 ) ;
V_50 = F_235 ( V_280 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
F_243 ( V_56 , V_237 ) ;
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
V_53:
F_36 ( V_280 ) ;
return V_50 ;
}
int F_244 ( struct V_56 * V_56 ,
struct V_7 * V_58 ,
T_2 V_118 , T_2 V_235 , T_2 V_236 )
{
int V_50 = 0 ;
T_2 V_245 , V_246 ;
unsigned int V_275 ;
while ( V_235 ) {
V_50 = F_231 ( V_56 , V_118 , & V_245 ,
& V_246 , & V_275 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
if ( V_235 < V_246 )
V_246 = V_235 ;
if ( V_275 & V_222 ) {
V_50 = F_240 ( V_56 , V_58 , V_118 ,
V_246 , V_236 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
}
V_235 -= V_246 ;
V_118 += V_246 ;
}
return V_50 ;
}
static int F_245 ( struct V_279 * V_280 ,
T_2 V_286 , T_2 * V_245 ,
T_2 * V_246 ,
unsigned int * V_287 )
{
struct V_56 * V_56 = V_280 -> V_56 ;
struct V_297 * V_298 = V_280 -> V_299 ;
return F_246 ( V_56 , V_286 , V_245 ,
V_246 , & V_298 -> V_300 ,
V_287 ) ;
}
int F_247 ( struct V_56 * V_56 ,
struct V_2 * V_247 ,
struct V_7 * V_51 ,
struct V_297 * V_298 ,
int * V_225 , int * V_107 )
{
int V_50 = 0 , V_122 , V_226 = 0 ;
T_2 V_245 , V_246 ;
T_2 V_118 = 0 , V_224 = F_12 ( V_298 -> V_301 ) ;
struct V_10 * V_11 ;
struct V_120 V_124 ;
struct V_7 * V_117 = NULL ;
while ( V_118 < V_224 ) {
V_50 = F_246 ( V_56 , V_118 , & V_245 ,
& V_246 , & V_298 -> V_300 ,
NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_118 += V_246 ;
while ( V_246 ) {
V_50 = F_116 ( V_247 , V_51 ,
V_245 , V_246 ,
& V_124 , & V_122 ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_5 ( ! V_124 . V_129 ) ;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) + V_224 * 2 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_226 ++ ;
* V_107 += 1 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
if ( V_246 <= F_12 ( V_124 . V_128 ) )
break;
else
V_246 -= F_12 ( V_124 . V_128 ) ;
V_245 += V_246 ;
}
}
* V_225 += V_226 ;
if ( ! V_226 )
goto V_53;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_162 ) & V_163 )
* V_107 += V_230 ;
else {
struct V_145 V_146 ;
F_109 ( & V_146 , V_247 , V_51 ) ;
* V_107 += F_181 ( V_56 -> V_77 ,
V_146 . V_229 ) ;
}
V_53:
F_58 ( V_117 ) ;
return V_50 ;
}
int F_248 ( struct V_56 * V_56 ,
struct V_59 * V_60 ,
struct V_302 * V_303 ,
struct V_1 * V_102 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_235 ,
struct V_304 * V_305 )
{
int V_50 ;
struct V_297 * V_298 = V_303 -> V_306 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_279 * V_280 = NULL ;
T_2 V_237 , V_238 ;
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_191 ( V_56 , & V_298 -> V_300 ,
V_118 , V_235 , V_152 ,
& V_237 , & V_238 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_5 ( V_238 == 0 ) ;
V_280 = F_53 ( sizeof( struct V_279 ) , V_48 ) ;
if ( ! V_280 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_280 -> V_56 = V_56 ;
V_280 -> V_237 = V_237 ;
V_280 -> V_238 = V_238 ;
V_280 -> V_102 = V_102 ;
V_280 -> V_51 = V_51 ;
V_280 -> V_299 = V_298 ;
V_280 -> V_284 = F_217 ;
V_280 -> V_291 =
F_173 ( V_56 -> V_77 , 1 ) * V_238 ;
V_280 -> V_294 = F_245 ;
V_280 -> V_290 = V_305 ;
F_249 ( & V_280 -> V_282 ,
F_81 ( V_56 ) , V_303 ) ;
V_50 = F_235 ( V_280 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_36 ( V_280 ) ;
return V_50 ;
}
int F_250 ( struct V_56 * V_56 ,
struct V_145 * V_282 ,
struct V_2 * V_247 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_245 , T_2 V_246 ,
struct V_209 * V_210 ,
struct V_304 * V_305 )
{
int V_50 ;
T_3 * V_72 ;
int V_107 = 1 , V_226 = 0 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_73 * V_74 = NULL ;
V_50 = F_178 ( V_56 -> V_77 ,
V_247 , V_51 ,
V_245 , V_246 ,
& V_226 , & V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_251 ( V_226 , V_107 ) ;
if ( V_226 ) {
V_50 = F_76 ( F_13 ( V_56 -> V_77 ) ,
V_226 , & V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
if ( V_305 )
V_107 += V_305 -> V_107 ;
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_175 ( V_56 , V_282 , V_72 ,
V_118 , V_246 , V_245 ,
V_74 , V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_155 ( V_72 , V_247 , V_51 ,
V_245 , V_246 , 0 ,
V_74 , V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
if ( V_305 && V_305 -> V_292 ) {
V_50 = V_305 -> V_292 ( V_56 , V_72 , V_305 -> V_293 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_74 )
F_93 ( V_74 ) ;
return V_50 ;
}
static int F_252 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 ;
T_3 * V_72 ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
V_72 = F_77 ( F_13 ( V_56 -> V_77 ) ,
V_307 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_80 ( V_72 , F_81 ( V_56 ) , V_58 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_56 -> V_308 = V_309 ;
V_60 -> V_308 = F_87 ( V_56 -> V_308 . V_310 ) ;
V_60 -> V_311 = F_88 ( V_56 -> V_308 . V_312 ) ;
F_90 ( V_72 , V_58 ) ;
V_87:
F_92 ( F_13 ( V_56 -> V_77 ) , V_72 ) ;
V_53:
return V_50 ;
}
static int F_253 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 , V_313 = 0 ;
struct V_7 * V_51 = NULL ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_1 * V_102 ;
unsigned int V_275 ;
T_6 V_193 ;
T_2 V_118 , V_246 , V_224 , V_245 ;
struct V_209 V_210 ;
struct V_145 V_314 ;
F_236 ( & V_210 ) ;
if ( ! ( V_76 -> V_61 & V_62 ) ) {
V_50 = F_74 ( V_56 , V_58 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
F_5 ( ! V_60 -> V_63 ) ;
V_50 = F_66 ( V_28 ,
F_11 ( V_60 -> V_63 ) , 1 ,
& V_102 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_76 -> V_61 & V_315 )
goto V_316;
F_242 ( & V_314 , F_81 ( V_56 ) , V_58 ) ;
V_193 = F_204 ( V_56 ) ;
V_224 = F_187 ( V_56 -> V_77 , V_193 ) ;
V_118 = 0 ;
while ( V_118 < V_224 ) {
V_50 = F_231 ( V_56 , V_118 , & V_245 ,
& V_246 , & V_275 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_271;
}
if ( V_245 && ! ( V_275 & V_222 ) ) {
V_50 = F_250 ( V_56 , & V_314 ,
& V_102 -> V_4 ,
V_51 , V_118 ,
V_245 , V_246 ,
& V_210 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_271;
}
V_313 = 1 ;
}
V_118 += V_246 ;
}
V_316:
if ( V_76 -> V_61 & V_133 ) {
V_50 = F_254 ( V_56 , V_58 ,
& V_102 -> V_4 ,
V_51 ,
& V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_271;
}
}
if ( V_313 ) {
V_50 = F_252 ( V_56 , V_58 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_271:
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
if ( ! V_50 && F_237 ( & V_210 ) ) {
F_238 ( V_28 , 1 ) ;
F_239 ( V_28 , & V_210 ) ;
}
V_53:
F_243 ( V_56 , 0 ) ;
return V_50 ;
}
static int F_255 ( struct V_56 * V_56 ,
struct V_145 * V_146 ,
struct V_2 * V_247 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_245 , T_2 V_246 ,
unsigned int V_275 ,
struct V_209 * V_210 )
{
int V_50 ;
T_3 * V_72 ;
int V_107 = 0 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_73 * V_74 = NULL ;
V_50 = F_195 ( V_56 -> V_77 ,
V_245 , V_246 ,
V_146 , V_247 ,
V_51 , & V_74 ,
NULL , & V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_142 ( V_72 , V_146 , V_118 ,
F_173 ( V_56 -> V_77 , V_245 ) ,
V_246 , V_275 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_167 ( V_72 , V_247 , V_51 ,
V_245 , V_246 ,
V_74 , V_210 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_74 )
F_93 ( V_74 ) ;
return V_50 ;
}
static int F_256 ( struct V_56 * V_317 ,
struct V_7 * V_318 ,
struct V_56 * V_319 ,
struct V_7 * V_320 )
{
int V_50 ;
T_3 * V_72 ;
struct V_27 * V_28 = F_13 ( V_317 -> V_77 ) ;
struct V_59 * V_321 = (struct V_59 * ) V_318 -> V_12 ;
struct V_59 * V_322 = (struct V_59 * ) V_320 -> V_12 ;
F_5 ( ! ( F_61 ( V_317 ) -> V_61 & V_315 ) ) ;
V_72 = F_77 ( V_28 , V_307 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_80 ( V_72 , F_81 ( V_319 ) , V_320 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_322 -> V_295 . V_323 . V_324 = V_321 -> V_295 . V_323 . V_324 ;
memcpy ( V_322 -> V_295 . V_323 . V_325 , V_321 -> V_295 . V_323 . V_325 ,
F_97 ( V_321 -> V_295 . V_323 . V_324 ) ) ;
F_19 ( & F_61 ( V_319 ) -> V_99 ) ;
F_61 ( V_319 ) -> V_61 |= V_315 ;
V_322 -> V_100 = F_86 ( F_61 ( V_319 ) -> V_61 ) ;
F_21 ( & F_61 ( V_319 ) -> V_99 ) ;
F_90 ( V_72 , V_320 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
return V_50 ;
}
static int F_257 ( struct V_56 * V_317 ,
struct V_56 * V_319 ,
struct V_7 * V_320 ,
struct V_2 * V_247 ,
struct V_7 * V_51 ,
struct V_209 * V_210 )
{
int V_50 = 0 ;
T_2 V_245 , V_246 , V_224 , V_118 ;
T_6 V_193 ;
unsigned int V_275 ;
struct V_145 V_146 ;
F_242 ( & V_146 , F_81 ( V_319 ) , V_320 ) ;
V_193 = F_204 ( V_317 ) ;
V_224 = F_187 ( V_317 -> V_77 , V_193 ) ;
V_118 = 0 ;
while ( V_118 < V_224 ) {
V_50 = F_231 ( V_317 , V_118 , & V_245 ,
& V_246 , & V_275 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_245 ) {
V_50 = F_255 ( V_319 , & V_146 ,
V_247 , V_51 ,
V_118 , V_245 ,
V_246 ,
V_275 ,
V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_246 ;
}
V_53:
return V_50 ;
}
static int F_258 ( struct V_56 * V_317 ,
struct V_7 * V_318 ,
struct V_56 * V_319 ,
struct V_7 * V_320 ,
bool V_326 )
{
int V_50 ;
T_3 * V_72 ;
struct V_59 * V_321 = (struct V_59 * ) V_318 -> V_12 ;
struct V_59 * V_60 = (struct V_59 * ) V_320 -> V_12 ;
T_6 V_193 = F_204 ( V_317 ) ;
V_72 = F_77 ( F_13 ( V_319 -> V_77 ) ,
V_307 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
return V_50 ;
}
V_50 = F_80 ( V_72 , F_81 ( V_319 ) , V_320 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
F_19 ( & F_61 ( V_319 ) -> V_99 ) ;
F_61 ( V_319 ) -> V_132 = F_61 ( V_317 ) -> V_132 ;
F_61 ( V_319 ) -> V_327 = F_61 ( V_317 ) -> V_327 ;
F_61 ( V_319 ) -> V_61 = F_61 ( V_317 ) -> V_61 ;
F_21 ( & F_61 ( V_319 ) -> V_99 ) ;
F_259 ( V_319 , V_193 ) ;
V_319 -> V_328 = V_317 -> V_328 ;
V_60 -> V_329 = V_321 -> V_329 ;
V_60 -> V_330 = V_321 -> V_330 ;
V_60 -> V_331 = V_321 -> V_331 ;
V_60 -> V_100 = V_321 -> V_100 ;
V_60 -> V_332 = V_321 -> V_332 ;
if ( V_326 ) {
V_319 -> V_333 = V_317 -> V_333 ;
V_319 -> V_334 = V_317 -> V_334 ;
V_319 -> V_335 = V_317 -> V_335 ;
V_60 -> V_333 = V_321 -> V_333 ;
V_60 -> V_334 = V_321 -> V_334 ;
V_60 -> V_335 = V_321 -> V_335 ;
V_319 -> V_308 = V_309 ;
V_60 -> V_308 = F_87 ( V_319 -> V_308 . V_310 ) ;
V_60 -> V_311 = F_88 ( V_319 -> V_308 . V_312 ) ;
V_319 -> V_336 = V_317 -> V_336 ;
V_60 -> V_336 = V_321 -> V_336 ;
V_60 -> V_337 = V_321 -> V_337 ;
}
F_90 ( V_72 , V_320 ) ;
V_87:
F_92 ( F_13 ( V_319 -> V_77 ) , V_72 ) ;
return V_50 ;
}
static int F_260 ( struct V_56 * V_317 ,
struct V_7 * V_318 ,
struct V_56 * V_319 ,
struct V_7 * V_320 ,
bool V_326 )
{
int V_50 ;
struct V_7 * V_51 = NULL ;
struct V_209 V_210 ;
struct V_27 * V_28 = F_13 ( V_317 -> V_77 ) ;
struct V_10 * V_11 ;
struct V_59 * V_60 = (struct V_59 * ) V_318 -> V_12 ;
struct V_1 * V_102 ;
F_236 ( & V_210 ) ;
V_50 = F_94 ( V_319 , V_320 ,
F_11 ( V_60 -> V_63 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( F_61 ( V_317 ) -> V_61 & V_315 ) {
V_50 = F_256 ( V_317 , V_318 ,
V_319 , V_320 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_66 ( V_28 , F_11 ( V_60 -> V_63 ) ,
1 , & V_102 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
V_50 = F_257 ( V_317 , V_319 , V_320 ,
& V_102 -> V_4 , V_51 ,
& V_210 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_338;
}
V_338:
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
V_53:
if ( F_237 ( & V_210 ) ) {
F_238 ( V_28 , 1 ) ;
F_239 ( V_28 , & V_210 ) ;
}
return V_50 ;
}
static int F_261 ( struct V_339 * V_340 ,
struct V_7 * V_274 ,
struct V_56 * V_341 ,
bool V_326 )
{
int V_50 ;
struct V_56 * V_56 = V_340 -> V_342 ;
struct V_7 * V_78 = NULL ;
if ( F_61 ( V_56 ) -> V_343 & V_344 ) {
V_50 = - V_17 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_262 ( V_56 -> V_265 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_253 ( V_56 , V_274 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_263 ( & V_341 -> V_113 , V_345 ) ;
V_50 = F_264 ( V_341 , & V_78 , 1 ,
V_346 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_116;
}
V_50 = F_260 ( V_56 , V_274 ,
V_341 , V_78 , V_326 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_347;
}
if ( F_61 ( V_56 ) -> V_61 & V_133 ) {
V_50 = F_265 ( V_56 , V_274 ,
V_341 , V_78 ,
V_326 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_347;
}
}
V_50 = F_258 ( V_56 , V_274 ,
V_341 , V_78 , V_326 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_347:
F_102 ( V_341 , 1 ) ;
F_58 ( V_78 ) ;
V_116:
F_25 ( & V_341 -> V_113 ) ;
V_53:
if ( ! V_50 ) {
V_50 = F_266 ( V_56 -> V_265 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
return V_50 ;
}
static int F_267 ( struct V_339 * V_340 , struct V_56 * V_348 ,
struct V_339 * V_349 , bool V_326 )
{
int error ;
struct V_56 * V_56 = V_340 -> V_342 ;
struct V_7 * V_274 = NULL ;
struct V_56 * V_350 = NULL ;
struct V_351 * V_352 , * V_353 ;
T_7 V_354 ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) )
return - V_355 ;
V_354 = V_56 -> V_335 ;
error = F_268 ( V_348 , & V_354 , & V_352 , & V_353 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
error = F_269 ( V_348 , V_354 ,
& V_350 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
error = F_270 ( V_56 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
error = F_100 ( V_56 , & V_274 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
F_271 ( V_56 , 1 ) ;
goto V_53;
}
F_64 ( & F_61 ( V_56 ) -> V_130 ) ;
F_64 ( & F_61 ( V_56 ) -> V_131 ) ;
error = F_261 ( V_340 , V_274 ,
V_350 , V_326 ) ;
F_68 ( & F_61 ( V_56 ) -> V_131 ) ;
F_68 ( & F_61 ( V_56 ) -> V_130 ) ;
F_102 ( V_56 , 1 ) ;
F_271 ( V_56 , 1 ) ;
F_58 ( V_274 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
if ( ! V_326 ) {
error = F_272 ( V_348 , V_350 ,
& V_349 -> V_356 ,
V_352 , V_353 ) ;
if ( error )
F_56 ( error ) ;
}
V_53:
if ( V_352 )
F_273 ( V_352 ) ;
if ( V_353 )
F_273 ( V_353 ) ;
if ( ! error ) {
error = F_274 ( V_348 , V_350 ,
V_349 ) ;
if ( error )
F_56 ( error ) ;
}
if ( V_350 ) {
F_275 ( V_350 ) ;
if ( error )
F_103 ( V_350 ) ;
}
return error ;
}
static inline int F_276 ( struct V_56 * V_348 , struct V_339 * V_357 )
{
if ( V_357 -> V_342 )
return - V_358 ;
if ( F_277 ( V_348 ) )
return - V_359 ;
return F_278 ( V_348 , V_360 | V_361 ) ;
}
static int F_279 ( struct V_339 * V_340 , struct V_56 * V_348 ,
struct V_339 * V_349 , bool V_326 )
{
struct V_56 * V_56 = V_340 -> V_342 ;
int error ;
if ( ! V_56 )
return - V_359 ;
error = F_276 ( V_348 , V_349 ) ;
if ( error )
return error ;
if ( V_348 -> V_77 != V_56 -> V_77 )
return - V_362 ;
if ( F_280 ( V_56 ) || F_281 ( V_56 ) )
return - V_363 ;
if ( ! F_282 ( V_56 -> V_335 ) )
return - V_363 ;
if ( V_326 ) {
if ( ! F_283 ( F_284 () , V_56 -> V_333 ) && ! F_285 ( V_364 ) )
return - V_363 ;
if ( ! F_286 ( V_56 -> V_334 ) && ! F_285 ( V_364 ) )
return - V_363 ;
}
if ( ! V_326 ) {
error = F_278 ( V_56 , V_365 ) ;
if ( error )
return error ;
}
F_23 ( & V_56 -> V_113 ) ;
F_287 ( V_348 ) ;
error = F_267 ( V_340 , V_348 , V_349 , V_326 ) ;
F_25 ( & V_56 -> V_113 ) ;
if ( ! error )
F_288 ( V_348 , V_349 ) ;
return error ;
}
int F_289 ( struct V_56 * V_56 ,
const char T_8 * V_366 ,
const char T_8 * V_367 ,
bool V_326 )
{
struct V_339 * V_349 ;
struct V_207 V_368 , V_369 ;
int error ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) )
return - V_355 ;
error = F_290 ( V_370 , V_366 , 0 , & V_368 ) ;
if ( error ) {
F_56 ( error ) ;
return error ;
}
V_349 = F_291 ( V_370 , V_367 , & V_369 , 0 ) ;
error = F_79 ( V_349 ) ;
if ( F_78 ( V_349 ) ) {
F_56 ( error ) ;
goto V_53;
}
error = - V_362 ;
if ( V_368 . V_371 != V_369 . V_371 ) {
F_56 ( error ) ;
goto V_372;
}
error = F_279 ( V_368 . V_339 ,
V_369 . V_339 -> V_342 ,
V_349 , V_326 ) ;
V_372:
F_292 ( & V_369 , V_349 ) ;
V_53:
F_293 ( & V_368 ) ;
return error ;
}
