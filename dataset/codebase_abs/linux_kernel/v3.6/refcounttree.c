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
V_50 = - V_180 ;
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
V_178 -> V_181 = F_88 ( 0 ) ;
V_178 -> V_182 = F_87 ( V_51 -> V_13 ) ;
V_178 -> V_162 = F_88 ( V_183 ) ;
F_90 ( V_72 , V_78 ) ;
memset ( & V_179 -> V_164 , 0 , V_6 -> V_89 -
F_128 ( struct V_10 , V_164 ) ) ;
V_179 -> V_164 . V_184 = F_86 ( F_129 ( V_6 ) ) ;
V_179 -> V_185 = F_88 ( 1 ) ;
V_179 -> V_164 . V_148 = F_86 ( 1 ) ;
V_179 -> V_164 . V_149 [ 0 ] . V_155 = F_87 ( V_29 ) ;
V_179 -> V_164 . V_149 [ 0 ] . V_186 = F_86 ( 1 ) ;
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
static int F_131 ( struct V_120 * V_187 ,
struct V_120 * V_188 )
{
if ( F_132 ( V_187 ) + F_12 ( V_187 -> V_128 ) <=
F_132 ( V_188 ) )
return 1 ;
return 0 ;
}
static int F_133 ( const void * V_189 , const void * V_190 )
{
const struct V_120 * V_191 = V_189 , * V_192 = V_190 ;
T_2 V_193 = F_132 ( V_191 ) ;
T_2 V_127 = F_132 ( V_192 ) ;
if ( V_193 > V_127 )
return 1 ;
if ( V_193 < V_127 )
return - 1 ;
return 0 ;
}
static int F_134 ( const void * V_189 , const void * V_190 )
{
const struct V_120 * V_191 = V_189 , * V_192 = V_190 ;
T_1 V_193 = F_11 ( V_191 -> V_127 ) ;
T_1 V_127 = F_11 ( V_192 -> V_127 ) ;
if ( V_193 > V_127 )
return 1 ;
if ( V_193 < V_127 )
return - 1 ;
return 0 ;
}
static void F_135 ( void * V_189 , void * V_190 , int V_194 )
{
struct V_120 * V_191 = V_189 , * V_192 = V_190 , V_22 ;
V_22 = * (struct V_120 * ) V_191 ;
* (struct V_120 * ) V_191 =
* (struct V_120 * ) V_192 ;
* (struct V_120 * ) V_192 = V_22 ;
}
static int F_136 ( struct V_176 * V_177 ,
T_2 * V_195 , int * V_196 )
{
int V_197 = F_97 ( V_177 -> V_125 ) ;
int V_198 , V_199 = V_197 / 2 ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ ) {
if ( F_131 (
& V_177 -> V_126 [ V_199 - V_198 - 1 ] ,
& V_177 -> V_126 [ V_199 - V_198 ] ) ) {
* V_196 = V_199 - V_198 ;
break;
}
if ( ( V_199 + V_198 + 1 ) == V_197 )
continue;
if ( F_131 (
& V_177 -> V_126 [ V_199 + V_198 ] ,
& V_177 -> V_126 [ V_199 + V_198 + 1 ] ) ) {
* V_196 = V_199 + V_198 + 1 ;
break;
}
}
if ( V_198 >= V_199 )
return - V_200 ;
* V_195 = F_132 ( & V_177 -> V_126 [ * V_196 ] ) ;
return 0 ;
}
static int F_137 ( struct V_7 * V_117 ,
struct V_7 * V_78 ,
T_2 * V_201 )
{
int V_196 = 0 , V_202 , V_50 ;
T_2 V_118 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_177 = & V_11 -> V_96 ;
struct V_10 * V_178 =
(struct V_10 * ) V_78 -> V_12 ;
struct V_176 * V_203 = & V_178 -> V_96 ;
F_138 (
( unsigned long long ) V_117 -> V_13 ,
F_97 ( V_177 -> V_97 ) , F_97 ( V_177 -> V_125 ) ) ;
F_139 ( & V_177 -> V_126 , F_97 ( V_177 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_133 , F_135 ) ;
V_50 = F_136 ( V_177 , & V_118 , & V_196 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_178 -> V_181 = F_88 ( V_118 ) ;
V_202 = F_97 ( V_177 -> V_125 ) - V_196 ;
memcpy ( V_203 -> V_126 , & V_177 -> V_126 [ V_196 ] ,
V_202 * sizeof( struct V_120 ) ) ;
memset ( & V_177 -> V_126 [ V_196 ] , 0 ,
V_202 * sizeof( struct V_120 ) ) ;
F_123 ( & V_177 -> V_125 , - V_202 ) ;
V_203 -> V_125 = F_86 ( V_202 ) ;
F_139 ( & V_177 -> V_126 , F_97 ( V_177 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_134 , F_135 ) ;
F_139 ( & V_203 -> V_126 , F_97 ( V_203 -> V_125 ) ,
sizeof( struct V_120 ) ,
F_134 , F_135 ) ;
* V_201 = V_118 ;
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
T_2 V_81 , V_204 ;
T_1 V_82 , V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_179 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_7 * V_78 = NULL ;
struct V_10 * V_178 ;
struct V_145 V_205 ;
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
V_50 = - V_180 ;
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
V_178 -> V_182 = F_87 ( V_51 -> V_13 ) ;
V_178 -> V_162 = F_88 ( V_183 ) ;
V_178 -> V_96 . V_97 =
F_86 ( F_89 ( V_6 ) ) ;
V_178 -> V_55 = V_179 -> V_55 ;
V_50 = F_137 ( V_117 , V_78 , & V_204 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_90 ( V_72 , V_117 ) ;
F_90 ( V_72 , V_78 ) ;
F_109 ( & V_205 , V_3 , V_51 ) ;
F_141 (
( unsigned long long ) V_78 -> V_13 , V_204 ) ;
V_50 = F_142 ( V_72 , & V_205 , V_204 , V_78 -> V_13 ,
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
struct V_7 * V_206 = NULL ;
if ( V_51 == V_117 ) {
V_50 = F_127 ( V_72 , V_3 , V_51 ,
& V_206 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
} else {
V_206 = V_117 ;
F_117 ( V_206 ) ;
}
V_50 = F_140 ( V_72 , V_3 , V_51 ,
V_206 , V_74 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_58 ( V_206 ) ;
return V_50 ;
}
static int F_144 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
struct V_120 * V_124 )
{
int V_50 = 0 , V_123 ;
T_2 V_204 , V_207 ;
struct V_142 * V_208 = NULL ;
struct V_145 V_146 ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_138 * V_139 ;
if ( ! ( F_12 ( V_11 -> V_162 ) & V_163 ) )
goto V_53;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
V_207 = F_12 ( V_11 -> V_181 ) ;
V_204 = F_11 ( V_124 -> V_127 ) & V_165 ;
if ( V_207 <= V_204 )
goto V_53;
F_109 ( & V_146 , V_3 , V_51 ) ;
V_208 = F_110 ( & V_146 ) ;
if ( ! V_208 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_111 ( V_3 , V_208 , V_207 ) ;
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
V_50 = F_146 ( V_72 , V_3 , F_147 ( V_208 ) ,
V_86 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_139 = F_148 ( V_208 ) ;
for ( V_123 = 0 ; V_123 < F_97 ( V_139 -> V_148 ) ; V_123 ++ )
if ( F_12 ( V_139 -> V_149 [ V_123 ] . V_150 ) == V_207 )
break;
F_5 ( V_123 == F_97 ( V_139 -> V_148 ) ) ;
V_139 -> V_149 [ V_123 ] . V_150 = F_88 ( V_204 ) ;
V_11 -> V_181 = F_88 ( V_204 ) ;
F_90 ( V_72 , F_147 ( V_208 ) ) ;
F_90 ( V_72 , V_117 ) ;
V_53:
F_115 ( V_208 ) ;
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
struct V_120 * V_209 ,
int V_122 , int V_174 ,
struct V_73 * V_74 ,
struct V_210 * V_211 )
{
int V_50 , V_212 ;
T_2 V_119 ;
struct V_10 * V_11 =
(struct V_10 * ) V_117 -> V_12 ;
struct V_176 * V_164 = & V_11 -> V_96 ;
struct V_120 * V_213 = & V_164 -> V_126 [ V_122 ] ;
struct V_120 * V_214 = NULL ;
struct V_7 * V_78 = NULL ;
F_5 ( F_12 ( V_11 -> V_162 ) & V_163 ) ;
F_152 ( F_11 ( V_213 -> V_127 ) ,
F_12 ( V_213 -> V_128 ) ,
F_12 ( V_213 -> V_129 ) ,
F_11 ( V_209 -> V_127 ) ,
F_12 ( V_209 -> V_128 ) ,
F_12 ( V_209 -> V_129 ) ) ;
if ( ! V_209 -> V_129 &&
( V_209 -> V_127 == V_213 -> V_127 ||
F_11 ( V_209 -> V_127 ) +
F_12 ( V_209 -> V_128 ) ==
F_11 ( V_213 -> V_127 ) + F_12 ( V_213 -> V_128 ) ) )
V_212 = 0 ;
else
V_212 = 1 ;
if ( V_209 -> V_129 &&
( V_209 -> V_127 != V_213 -> V_127 &&
F_11 ( V_209 -> V_127 ) +
F_12 ( V_209 -> V_128 ) !=
F_11 ( V_213 -> V_127 ) + F_12 ( V_213 -> V_128 ) ) )
V_212 ++ ;
if ( F_97 ( V_164 -> V_125 ) + V_212 >
F_97 ( V_164 -> V_97 ) ) {
struct V_120 V_215 ;
T_1 V_118 = F_11 ( V_213 -> V_127 ) ;
V_119 = F_12 ( V_213 -> V_128 ) ;
V_50 = F_143 ( V_72 , V_3 , V_51 ,
V_117 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , & V_215 , & V_122 ,
& V_78 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_117 = V_78 ;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
V_164 = & V_11 -> V_96 ;
V_213 = & V_164 -> V_126 [ V_122 ] ;
}
V_50 = F_85 ( V_72 , V_3 , V_117 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_122 != F_97 ( V_164 -> V_125 ) - 1 )
memmove ( & V_164 -> V_126 [ V_122 + 1 + V_212 ] ,
& V_164 -> V_126 [ V_122 + 1 ] ,
( F_97 ( V_164 -> V_125 ) - V_122 - 1 ) *
sizeof( struct V_120 ) ) ;
V_119 = ( F_11 ( V_213 -> V_127 ) +
F_12 ( V_213 -> V_128 ) ) -
( F_11 ( V_209 -> V_127 ) +
F_12 ( V_209 -> V_128 ) ) ;
if ( V_119 ) {
V_214 = & V_164 -> V_126 [ V_122 + V_212 ] ;
memcpy ( V_214 , V_213 , sizeof( struct V_120 ) ) ;
F_153 ( & V_214 -> V_127 ,
F_12 ( V_214 -> V_128 ) - V_119 ) ;
V_214 -> V_128 = F_88 ( V_119 ) ;
}
if ( V_209 -> V_127 != V_213 -> V_127 && V_214 != V_213 ) {
V_119 = F_11 ( V_209 -> V_127 ) -
F_11 ( V_213 -> V_127 ) ;
V_213 -> V_128 = F_88 ( V_119 ) ;
V_122 ++ ;
}
F_123 ( & V_164 -> V_125 , V_212 ) ;
if ( V_209 -> V_129 ) {
V_164 -> V_126 [ V_122 ] = * V_209 ;
F_154 (
( unsigned long long ) V_117 -> V_13 , V_122 ,
( unsigned long long ) F_11 ( V_209 -> V_127 ) ,
F_12 ( V_209 -> V_128 ) ,
F_12 ( V_209 -> V_129 ) ) ;
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
struct V_210 * V_211 )
{
int V_50 = 0 , V_122 ;
struct V_7 * V_117 = NULL ;
struct V_120 V_124 ;
unsigned int V_216 = 0 ;
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
V_216 = F_12 ( V_124 . V_128 ) ;
if ( V_124 . V_129 && F_11 ( V_124 . V_127 ) == V_118 &&
V_216 <= V_119 ) {
F_157 (
( unsigned long long ) V_118 , V_216 ,
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
V_216 ) ;
V_50 = F_149 ( V_72 , V_3 , V_51 ,
V_117 ,
& V_124 , V_122 ,
V_174 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
} else {
V_216 = F_159 ( ( T_1 ) ( V_118 + V_119 ) ,
F_11 ( V_124 . V_127 ) + V_216 ) - V_118 ;
V_124 . V_127 = F_87 ( V_118 ) ;
V_124 . V_128 = F_88 ( V_216 ) ;
F_95 ( & V_124 . V_129 , 1 ) ;
F_160 (
( unsigned long long ) F_11 ( V_124 . V_127 ) ,
V_216 , F_12 ( V_124 . V_129 ) ) ;
V_50 = F_151 ( V_72 , V_3 ,
V_51 , V_117 ,
& V_124 , V_122 , V_174 ,
V_74 , V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_216 ;
V_119 -= V_216 ;
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
struct V_210 * V_211 )
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
F_12 ( V_11 -> V_181 ) ) ;
F_109 ( & V_146 , V_3 , V_51 ) ;
V_50 = F_163 ( V_72 , & V_146 , F_12 ( V_11 -> V_181 ) ,
1 , V_74 , V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_164 ( V_3 , V_117 ) ;
V_50 = F_165 ( V_211 , V_112 ,
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
F_95 ( & V_11 -> V_185 , - 1 ) ;
if ( ! V_11 -> V_164 . V_148 ) {
F_5 ( V_11 -> V_185 ) ;
F_166 (
( unsigned long long ) V_51 -> V_13 ) ;
V_11 -> V_162 = 0 ;
V_11 -> V_182 = 0 ;
V_11 -> V_181 = 0 ;
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
struct V_210 * V_211 )
{
return F_155 ( V_72 , V_3 , V_51 ,
V_118 , V_119 , 1 ,
V_74 , V_211 ) ;
}
static int F_168 ( T_3 * V_72 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_117 ,
int V_122 , T_1 V_118 , unsigned int V_119 ,
struct V_73 * V_74 ,
struct V_210 * V_211 )
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
struct V_120 V_217 = * V_124 ;
V_217 . V_127 = F_87 ( V_118 ) ;
V_217 . V_128 = F_88 ( V_119 ) ;
F_95 ( & V_217 . V_129 , - 1 ) ;
V_50 = F_151 ( V_72 , V_3 ,
V_51 , V_117 ,
& V_217 , V_122 , 1 ,
V_74 , V_211 ) ;
}
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( ! V_11 -> V_96 . V_125 && V_117 != V_51 ) {
V_50 = F_161 ( V_72 , V_3 , V_51 ,
V_117 , V_74 ,
V_211 ) ;
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
struct V_210 * V_211 ,
int V_218 )
{
int V_50 = 0 , V_122 = 0 ;
struct V_120 V_124 ;
unsigned int V_219 = 0 , V_220 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_7 * V_117 = NULL ;
F_171 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_118 , V_119 , V_218 ) ;
while ( V_119 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_119 , & V_124 , & V_122 ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_219 = F_12 ( V_124 . V_129 ) ;
F_5 ( V_219 == 0 ) ;
if ( ! V_218 )
F_5 ( V_219 > 1 ) ;
V_220 = F_159 ( ( T_1 ) ( V_118 + V_119 ) , F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_118 ;
V_50 = F_168 ( V_72 , V_3 , V_51 ,
V_117 , V_122 ,
V_118 , V_220 ,
V_74 , V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( F_12 ( V_124 . V_129 ) == 1 && V_218 ) {
V_50 = F_172 ( V_211 ,
F_173 ( V_6 , V_118 ) ,
V_220 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_220 ;
V_119 -= V_220 ;
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
struct V_210 * V_211 ,
int V_218 )
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
V_118 , V_119 , V_74 , V_211 , V_218 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_175 ( struct V_56 * V_56 ,
struct V_145 * V_146 ,
T_3 * V_72 , T_2 V_118 ,
T_2 V_119 , T_2 V_221 ,
struct V_73 * V_74 ,
struct V_210 * V_211 )
{
int V_50 ;
F_176 ( F_61 ( V_56 ) -> V_84 ,
V_118 , V_119 , V_221 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_222 ) ;
V_50 = - V_167 ;
goto V_53;
}
V_50 = F_177 ( V_72 , V_146 , V_118 ,
V_119 , V_221 , V_74 , V_211 ,
V_223 , 0 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
return V_50 ;
}
static int F_178 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_224 ,
T_2 V_225 ,
int * V_226 ,
int * V_107 )
{
int V_50 = 0 , V_122 , V_227 = 0 , V_228 = 0 ;
T_1 V_118 = V_224 ;
struct V_10 * V_11 ;
struct V_120 V_124 ;
struct V_7 * V_117 = NULL , * V_229 = NULL ;
T_2 V_119 ;
while ( V_225 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_118 , V_225 , & V_124 ,
& V_122 , & V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_117 != V_229 ) {
if ( V_229 ) {
V_11 = (struct V_10 * )
V_229 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) +
V_228 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_227 ++ ;
}
V_228 = 0 ;
* V_107 += 1 ;
F_58 ( V_229 ) ;
V_229 = V_117 ;
F_117 ( V_229 ) ;
}
V_11 = (struct V_10 * ) V_117 -> V_12 ;
F_179 (
V_228 , ( unsigned long long ) V_118 , V_225 ,
( unsigned long long ) F_11 ( V_124 . V_127 ) ,
F_12 ( V_124 . V_128 ) ,
F_12 ( V_124 . V_129 ) , V_122 ) ;
V_119 = F_159 ( ( T_1 ) V_118 + V_225 , F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_118 ;
if ( V_124 . V_129 ) {
V_228 += 2 ;
if ( V_118 == V_224 &&
V_118 != F_11 ( V_124 . V_127 ) )
V_228 ++ ;
if ( V_118 + V_225 < F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) )
V_228 ++ ;
} else
V_228 ++ ;
F_58 ( V_117 ) ;
V_117 = NULL ;
V_225 -= V_119 ;
V_118 += V_119 ;
}
if ( V_229 ) {
V_11 = (struct V_10 * ) V_229 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) + V_228 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_227 ++ ;
* V_107 += 1 ;
}
if ( ! V_227 )
goto V_53;
* V_226 += V_227 ;
* V_107 += V_227 ;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_162 ) & V_163 ) {
struct V_145 V_146 ;
F_109 ( & V_146 , V_3 , V_51 ) ;
* V_226 += F_180 ( V_146 . V_230 ) ;
* V_107 += F_181 ( V_6 ,
V_146 . V_230 ,
V_227 ) ;
} else {
* V_107 += V_231 ;
* V_226 += 1 ;
}
V_53:
F_182 (
( unsigned long long ) V_224 , V_225 ,
* V_226 , * V_107 ) ;
F_58 ( V_117 ) ;
F_58 ( V_229 ) ;
return V_50 ;
}
int F_183 ( struct V_56 * V_56 ,
T_1 V_101 ,
T_1 V_232 ,
T_2 V_225 ,
int * V_107 ,
int * V_227 )
{
int V_50 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
T_1 V_224 = F_184 ( V_56 -> V_77 , V_232 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_222 ) ;
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
V_224 , V_225 ,
V_227 , V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_185 ( * V_227 , * V_107 ) ;
V_53:
F_58 ( V_51 ) ;
return V_50 ;
}
static inline unsigned int F_186 ( struct V_5 * V_6 )
{
return F_187 ( V_6 , V_233 ) ;
}
static inline unsigned int F_188 ( struct V_5 * V_6 )
{
return ~ ( F_186 ( V_6 ) - 1 ) ;
}
static inline unsigned int F_189 ( struct V_5 * V_6 ,
unsigned int V_234 ,
unsigned int V_118 )
{
F_5 ( V_234 > V_118 ) ;
return V_234 + ( ( V_118 - V_234 ) & F_188 ( V_6 ) ) ;
}
static inline unsigned int F_190 ( struct V_5 * V_6 ,
unsigned int V_119 )
{
unsigned int V_235 =
( V_119 + ( F_186 ( V_6 ) - 1 ) ) &
F_188 ( V_6 ) ;
if ( V_235 < V_119 )
V_235 = V_152 ;
return V_235 ;
}
static int F_191 ( struct V_56 * V_56 ,
struct V_138 * V_139 ,
T_2 V_118 ,
T_2 V_236 ,
T_2 V_237 ,
T_2 * V_238 ,
T_2 * V_239 )
{
int V_50 = 0 ;
int V_240 = F_97 ( V_139 -> V_166 ) , V_123 ;
struct V_7 * V_161 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_160 * V_124 ;
unsigned int V_241 , V_242 = 0 ;
int V_243 = F_186 ( V_56 -> V_77 ) ;
int V_244 ;
F_5 ( V_118 + V_236 > V_237 ) ;
if ( V_240 > 0 ) {
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
L_14 , V_56 -> V_222 ,
( unsigned long long ) V_161 -> V_13 ) ;
V_50 = - V_167 ;
goto V_53;
}
}
* V_239 = 0 ;
for ( V_123 = 0 ; V_123 < F_97 ( V_139 -> V_148 ) ; V_123 ++ ) {
V_124 = & V_139 -> V_149 [ V_123 ] ;
if ( F_192 ( V_124 ) ) {
F_193 ( V_123 != 0 , L_15
L_16 , V_56 -> V_222 , V_123 ) ;
continue;
}
if ( F_12 ( V_124 -> V_150 ) +
F_97 ( V_124 -> V_186 ) <= V_118 )
continue;
if ( * V_239 == 0 ) {
F_5 ( ! ( V_124 -> V_245 & V_223 ) ) ;
* V_238 = F_12 ( V_124 -> V_150 ) ;
}
if ( ( ! ( V_124 -> V_245 & V_223 ) ) ||
( * V_239 && V_242 != F_12 ( V_124 -> V_150 ) ) ||
( V_237 <= F_12 ( V_124 -> V_150 ) ) )
break;
V_244 = F_97 ( V_124 -> V_186 ) ;
V_242 = F_12 ( V_124 -> V_150 ) + V_244 ;
if ( V_242 > V_237 ) {
V_242 = V_237 ;
V_244 = V_242 - F_12 ( V_124 -> V_150 ) ;
}
if ( ! * V_239 )
V_241 = V_236 ;
else
V_241 = ( V_118 + V_236 ) -
( * V_238 + * V_239 ) ;
if ( V_241 < V_243 )
V_241 = V_243 ;
if ( V_244 <= V_243 )
* V_239 += V_244 ;
else if ( * V_239 || ( * V_238 == V_118 ) ) {
V_241 = F_190 ( V_56 -> V_77 ,
V_241 ) ;
if ( V_244 < V_241 )
* V_239 += V_244 ;
else
* V_239 += V_241 ;
} else if ( ( * V_238 + V_243 ) >=
( V_118 + V_236 ) ) {
* V_239 = V_243 ;
} else if ( ( V_242 - V_118 ) <= V_243 ) {
* V_238 = V_242 - V_243 ;
* V_239 = V_243 ;
} else if ( ( V_242 - V_118 ) <= V_241 ) {
* V_238 = F_189 ( V_56 -> V_77 ,
* V_238 , V_118 ) ;
* V_239 = V_242 - * V_238 ;
} else {
* V_238 = F_189 ( V_56 -> V_77 ,
* V_238 , V_118 ) ;
V_241 = ( V_118 + V_236 ) - * V_238 ;
V_241 = F_190 ( V_56 -> V_77 ,
V_241 ) ;
if ( * V_238 + V_241 <= V_242 )
* V_239 = V_241 ;
else
* V_239 = V_242 - * V_238 ;
}
if ( ( * V_238 + * V_239 ) >= ( V_118 + V_236 ) )
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
T_2 V_246 , T_2 V_247 ,
struct V_145 * V_146 ,
struct V_2 * V_248 ,
struct V_7 * V_51 ,
struct V_73 * * V_74 ,
struct V_73 * * V_249 ,
int * V_107 )
{
int V_50 = 0 , V_226 = 0 ;
int V_250 = F_196 ( F_13 ( V_6 ) , V_146 ) ;
if ( V_250 < 0 ) {
V_50 = V_250 ;
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_250 < V_247 + 2 )
V_226 =
F_180 ( V_146 -> V_230 ) ;
* V_107 += F_181 ( V_6 , V_146 -> V_230 ,
V_247 + 2 ) ;
V_50 = F_178 ( V_6 , V_248 , V_51 ,
V_246 , V_247 ,
& V_226 , V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_197 ( V_226 , * V_107 ) ;
V_50 = F_76 ( F_13 ( V_6 ) , V_226 ,
V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( V_249 ) {
V_50 = F_198 ( F_13 ( V_6 ) , V_247 ,
V_249 ) ;
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
struct V_251 * V_251 ,
T_2 V_118 , T_2 V_252 ,
T_2 V_253 , T_2 V_254 )
{
int V_50 = 0 , V_255 ;
struct V_56 * V_56 = V_251 -> V_256 . V_257 -> V_258 ;
struct V_2 * V_3 = F_81 ( V_56 ) ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
T_1 V_259 = F_173 ( V_6 , V_253 ) ;
struct V_260 * V_260 ;
T_5 V_261 ;
unsigned int V_262 , V_263 , V_264 ;
T_6 V_265 , V_266 , V_267 ;
struct V_268 * V_269 = V_56 -> V_270 ;
F_203 ( V_118 , V_252 ,
V_253 , V_254 ) ;
V_264 =
( F_186 ( V_6 ) <<
F_13 ( V_6 ) -> V_271 ) >> V_272 ;
V_265 = ( ( T_6 ) V_118 ) << F_13 ( V_6 ) -> V_271 ;
V_266 = V_265 + ( V_254 << F_13 ( V_6 ) -> V_271 ) ;
if ( V_266 > F_204 ( V_56 ) )
V_266 = F_204 ( V_56 ) ;
while ( V_265 < V_266 ) {
V_261 = V_265 >> V_272 ;
V_267 = ( ( T_6 ) V_261 + 1 ) << V_272 ;
if ( V_267 > V_266 )
V_267 = V_266 ;
V_262 = V_265 & ( V_273 - 1 ) ;
V_263 = V_273 ;
if ( V_267 & ( V_273 - 1 ) )
V_263 = V_267 & ( V_273 - 1 ) ;
V_260 = F_205 ( V_269 , V_261 , V_48 ) ;
if ( V_273 <= F_13 ( V_6 ) -> V_274 )
F_5 ( F_206 ( V_260 ) ) ;
if ( F_207 ( V_260 ) ) {
F_208 ( V_269 ,
& V_251 -> V_275 , V_251 ,
V_260 , V_261 ,
V_264 ) ;
}
if ( ! F_209 ( V_260 ) ) {
V_50 = F_210 ( V_260 , V_276 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_277;
}
F_211 ( V_260 ) ;
}
if ( F_212 ( V_260 ) ) {
V_50 = F_213 ( V_72 , F_214 ( V_260 ) ,
V_262 , V_263 , & V_255 ,
F_199 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_277;
}
}
F_215 ( V_56 , V_72 , V_262 , V_263 ,
V_260 , 0 , & V_259 ) ;
F_216 ( V_260 ) ;
V_277:
F_217 ( V_260 ) ;
F_218 ( V_260 ) ;
V_260 = NULL ;
V_265 = V_267 ;
if ( V_50 )
break;
}
return V_50 ;
}
int F_219 ( T_3 * V_72 ,
struct V_251 * V_251 ,
T_2 V_118 , T_2 V_252 ,
T_2 V_253 , T_2 V_254 )
{
int V_50 = 0 ;
struct V_56 * V_56 = V_251 -> V_256 . V_257 -> V_258 ;
struct V_5 * V_6 = V_56 -> V_77 ;
struct V_2 * V_3 = F_81 ( V_56 ) ;
int V_123 , V_278 = F_173 ( V_6 , V_254 ) ;
T_1 V_279 = F_173 ( V_6 , V_252 ) ;
T_1 V_259 = F_173 ( V_6 , V_253 ) ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
struct V_7 * V_280 = NULL ;
struct V_7 * V_78 = NULL ;
F_203 ( V_118 , V_252 ,
V_253 , V_254 ) ;
for ( V_123 = 0 ; V_123 < V_278 ; V_123 ++ , V_279 ++ , V_259 ++ ) {
V_78 = F_83 ( V_28 -> V_6 , V_259 ) ;
if ( V_78 == NULL ) {
V_50 = - V_180 ;
F_56 ( V_50 ) ;
break;
}
F_84 ( V_3 , V_78 ) ;
V_50 = F_15 ( V_3 , V_279 , & V_280 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_50 = F_220 ( V_72 , V_3 , V_78 ,
V_88 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
memcpy ( V_78 -> V_12 , V_280 -> V_12 , V_6 -> V_89 ) ;
F_90 ( V_72 , V_78 ) ;
F_58 ( V_78 ) ;
F_58 ( V_280 ) ;
V_78 = NULL ;
V_280 = NULL ;
}
F_58 ( V_78 ) ;
F_58 ( V_280 ) ;
return V_50 ;
}
static int F_221 ( T_3 * V_72 ,
struct V_145 * V_146 ,
T_2 V_118 , T_2 V_246 , T_2 V_119 ,
unsigned int V_281 ,
struct V_73 * V_74 ,
struct V_210 * V_211 )
{
int V_50 , V_122 ;
struct V_160 V_282 ;
struct V_142 * V_208 = NULL ;
struct V_138 * V_139 ;
struct V_5 * V_6 = F_108 ( V_146 -> V_283 ) ;
T_1 V_284 = F_119 ( V_146 -> V_283 ) ;
F_222 ( ( unsigned long long ) V_284 ,
V_118 , V_119 , V_246 , V_281 ) ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_150 = F_88 ( V_118 ) ;
V_282 . V_186 = F_86 ( V_119 ) ;
V_282 . V_155 = F_87 ( F_173 ( V_6 ,
V_246 ) ) ;
V_282 . V_245 = V_281 ;
V_282 . V_245 &= ~ V_223 ;
V_208 = F_110 ( V_146 ) ;
if ( ! V_208 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_111 ( V_146 -> V_283 , V_208 , V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_139 = F_148 ( V_208 ) ;
V_122 = F_223 ( V_139 , V_118 ) ;
if ( V_122 == - 1 || V_122 >= F_97 ( V_139 -> V_148 ) ) {
F_10 ( V_6 ,
L_17
L_18 ,
( unsigned long long ) V_284 , V_118 ) ;
V_50 = - V_167 ;
goto V_53;
}
V_50 = F_224 ( V_72 , V_146 , V_208 , V_122 ,
& V_282 , V_74 , V_211 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_115 ( V_208 ) ;
return V_50 ;
}
static int F_225 ( T_3 * V_72 ,
struct V_285 * V_286 ,
T_2 V_118 , T_2 V_287 ,
T_2 V_37 , T_2 V_119 ,
unsigned int V_281 )
{
int V_50 ;
struct V_2 * V_3 = V_286 -> V_288 . V_283 ;
T_1 V_284 = F_119 ( V_3 ) ;
F_226 ( ( unsigned long long ) V_284 ,
V_118 , V_287 , V_37 , V_119 , V_281 ) ;
if ( ! ( V_281 & V_289 ) ) {
V_50 = V_286 -> V_290 ( V_72 , V_286 -> V_251 ,
V_118 , V_287 , V_37 , V_119 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_50 = F_221 ( V_72 , & V_286 -> V_288 ,
V_118 , V_37 , V_119 , V_281 ,
V_286 -> V_74 , & V_286 -> V_211 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
return V_50 ;
}
int F_227 ( struct V_5 * V_6 ,
struct V_56 * V_56 ,
T_2 V_118 , T_2 V_247 )
{
int V_50 = 0 ;
T_6 V_265 , V_266 , V_267 ;
T_5 V_261 ;
struct V_260 * V_260 ;
if ( F_228 ( V_56 ) )
return 0 ;
V_265 = ( ( T_6 ) V_118 ) << F_13 ( V_6 ) -> V_271 ;
V_266 = V_265 + ( V_247 << F_13 ( V_6 ) -> V_271 ) ;
V_50 = F_229 ( V_56 -> V_270 ,
V_265 , V_266 - 1 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
while ( V_265 < V_266 ) {
V_261 = V_265 >> V_272 ;
V_267 = ( ( T_6 ) V_261 + 1 ) << V_272 ;
if ( V_267 > V_266 )
V_267 = V_266 ;
V_260 = F_205 ( V_56 -> V_270 ,
V_261 , V_48 ) ;
F_5 ( ! V_260 ) ;
F_230 ( V_260 ) ;
if ( F_231 ( V_260 ) ) {
V_50 = - V_180 ;
F_56 ( V_50 ) ;
} else
F_216 ( V_260 ) ;
F_217 ( V_260 ) ;
F_218 ( V_260 ) ;
V_260 = NULL ;
V_265 = V_267 ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_232 ( struct V_285 * V_286 ,
T_2 V_291 , T_2 * V_246 ,
T_2 * V_247 ,
unsigned int * V_292 )
{
return F_233 ( V_286 -> V_56 , V_291 , V_246 ,
V_247 , V_292 ) ;
}
static int F_234 ( struct V_5 * V_6 ,
struct V_285 * V_286 ,
T_2 V_118 , T_2 V_246 ,
T_2 V_247 , unsigned int V_245 )
{
int V_50 , V_218 , V_122 , V_107 = 0 ;
T_2 V_293 , V_254 , V_294 ;
unsigned int V_216 ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
T_3 * V_72 ;
struct V_7 * V_117 = NULL ;
struct V_2 * V_248 = & V_286 -> V_102 -> V_4 ;
struct V_120 V_124 ;
F_235 ( V_118 , V_246 ,
V_247 , V_245 ) ;
V_50 = F_195 ( V_6 , V_246 , V_247 ,
& V_286 -> V_288 ,
V_248 ,
V_286 -> V_51 ,
& V_286 -> V_74 ,
& V_286 -> V_249 , & V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
if ( V_286 -> V_295 )
V_107 += V_286 -> V_295 -> V_107 ;
V_107 += V_286 -> V_296 ;
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_294 = V_247 ;
while ( V_247 ) {
V_50 = F_116 ( V_248 , V_286 -> V_51 ,
V_246 , V_247 ,
& V_124 , & V_122 , & V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
F_5 ( ! V_124 . V_129 ) ;
V_216 = F_159 ( ( T_1 ) V_246 + V_247 ,
F_11 ( V_124 . V_127 ) +
F_12 ( V_124 . V_128 ) ) - V_246 ;
if ( F_12 ( V_124 . V_129 ) == 1 ) {
V_218 = 0 ;
V_50 = F_221 ( V_72 ,
& V_286 -> V_288 ,
V_118 , V_246 ,
V_216 , V_245 ,
V_286 -> V_74 ,
& V_286 -> V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
} else {
V_218 = 1 ;
V_50 = F_236 ( V_72 ,
V_286 -> V_249 ,
1 , V_216 ,
& V_293 , & V_254 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_225 ( V_72 , V_286 ,
V_118 , V_246 , V_293 ,
V_254 , V_245 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_216 = V_254 ;
}
V_50 = F_170 ( V_72 , V_248 ,
V_286 -> V_51 ,
V_246 , V_216 ,
V_286 -> V_74 ,
& V_286 -> V_211 , V_218 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_118 += V_216 ;
V_246 += V_216 ;
V_247 -= V_216 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
}
if ( V_286 -> V_295 && V_286 -> V_295 -> V_297 ) {
V_50 = V_286 -> V_295 -> V_297 ( V_286 -> V_56 , V_72 ,
V_286 -> V_295 -> V_298 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
}
if ( V_286 -> V_299 == F_232 ) {
V_50 = F_227 ( V_6 , V_286 -> V_56 , V_118 ,
V_294 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_286 -> V_249 ) {
F_93 ( V_286 -> V_249 ) ;
V_286 -> V_249 = NULL ;
}
if ( V_286 -> V_74 ) {
F_93 ( V_286 -> V_74 ) ;
V_286 -> V_74 = NULL ;
}
F_58 ( V_117 ) ;
return V_50 ;
}
static int F_237 ( struct V_285 * V_286 )
{
int V_50 = 0 ;
struct V_56 * V_56 = V_286 -> V_56 ;
T_2 V_238 = V_286 -> V_238 , V_239 = V_286 -> V_239 ;
T_2 V_246 , V_247 ;
unsigned int V_281 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) ) {
F_10 ( V_56 -> V_77 , L_10
L_11
L_12 , V_56 -> V_222 ) ;
return - V_167 ;
}
F_238 ( & V_286 -> V_211 ) ;
while ( V_239 ) {
V_50 = V_286 -> V_299 ( V_286 , V_238 , & V_246 ,
& V_247 , & V_281 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
F_5 ( ! ( V_281 & V_223 ) ) ;
if ( V_239 < V_247 )
V_247 = V_239 ;
V_50 = F_234 ( V_56 -> V_77 , V_286 ,
V_238 , V_246 ,
V_247 , V_281 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_239 -= V_247 ;
V_238 += V_247 ;
}
if ( F_239 ( & V_286 -> V_211 ) ) {
F_240 ( V_28 , 1 ) ;
F_241 ( V_28 , & V_286 -> V_211 ) ;
}
return V_50 ;
}
static void F_242 ( struct V_56 * V_56 ,
struct V_251 * V_251 ,
T_2 V_234 , T_2 V_119 )
{
struct V_268 * V_269 ;
T_5 V_122 ;
unsigned long V_300 ;
int V_301 = F_13 ( V_56 -> V_77 ) -> V_271 ;
if ( ! V_251 )
return;
V_269 = V_251 -> V_302 ;
V_300 = ( V_119 << V_301 ) >> V_272 ;
if ( ! V_300 )
V_300 = 1 ;
V_122 = ( ( T_6 ) V_234 << V_301 ) >> V_272 ;
F_243 ( V_269 , & V_251 -> V_275 , V_251 ,
V_122 , V_300 ) ;
}
static int F_244 ( struct V_56 * V_56 ,
struct V_251 * V_251 ,
struct V_7 * V_58 ,
T_2 V_118 , T_2 V_236 , T_2 V_237 )
{
int V_50 ;
T_2 V_238 = 0 , V_239 = 0 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_102 ;
struct V_285 * V_286 = NULL ;
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_191 ( V_56 , & V_60 -> V_303 . V_304 ,
V_118 , V_236 , V_237 ,
& V_238 , & V_239 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_245 ( F_61 ( V_56 ) -> V_84 ,
V_118 , V_236 , V_237 ,
V_238 , V_239 ) ;
F_5 ( V_239 == 0 ) ;
F_242 ( V_56 , V_251 , V_238 , V_239 ) ;
V_286 = F_53 ( sizeof( struct V_285 ) , V_48 ) ;
if ( ! V_286 ) {
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
V_286 -> V_56 = V_56 ;
V_286 -> V_238 = V_238 ;
V_286 -> V_239 = V_239 ;
V_286 -> V_102 = V_102 ;
V_286 -> V_51 = V_51 ;
V_286 -> V_290 = F_202 ;
V_286 -> V_299 = F_232 ;
V_286 -> V_251 = V_251 ;
F_246 ( & V_286 -> V_288 ,
F_81 ( V_56 ) , V_58 ) ;
V_50 = F_237 ( V_286 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
F_247 ( V_56 , V_238 ) ;
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
V_53:
F_36 ( V_286 ) ;
return V_50 ;
}
int F_248 ( struct V_56 * V_56 ,
struct V_251 * V_251 ,
struct V_7 * V_58 ,
T_2 V_118 , T_2 V_236 , T_2 V_237 )
{
int V_50 = 0 ;
T_2 V_246 , V_247 ;
unsigned int V_281 ;
while ( V_236 ) {
V_50 = F_233 ( V_56 , V_118 , & V_246 ,
& V_247 , & V_281 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
if ( V_236 < V_247 )
V_247 = V_236 ;
if ( V_281 & V_223 ) {
V_50 = F_244 ( V_56 , V_251 , V_58 , V_118 ,
V_247 , V_237 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
}
V_236 -= V_247 ;
V_118 += V_247 ;
}
return V_50 ;
}
static int F_249 ( struct V_285 * V_286 ,
T_2 V_291 , T_2 * V_246 ,
T_2 * V_247 ,
unsigned int * V_292 )
{
struct V_56 * V_56 = V_286 -> V_56 ;
struct V_305 * V_306 = V_286 -> V_307 ;
return F_250 ( V_56 , V_291 , V_246 ,
V_247 , & V_306 -> V_308 ,
V_292 ) ;
}
int F_251 ( struct V_56 * V_56 ,
struct V_2 * V_248 ,
struct V_7 * V_51 ,
struct V_305 * V_306 ,
int * V_226 , int * V_107 )
{
int V_50 = 0 , V_122 , V_227 = 0 ;
T_2 V_246 , V_247 ;
T_2 V_118 = 0 , V_225 = F_12 ( V_306 -> V_309 ) ;
struct V_10 * V_11 ;
struct V_120 V_124 ;
struct V_7 * V_117 = NULL ;
while ( V_118 < V_225 ) {
V_50 = F_250 ( V_56 , V_118 , & V_246 ,
& V_247 , & V_306 -> V_308 ,
NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_118 += V_247 ;
while ( V_247 ) {
V_50 = F_116 ( V_248 , V_51 ,
V_246 , V_247 ,
& V_124 , & V_122 ,
& V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_5 ( ! V_124 . V_129 ) ;
V_11 = (struct V_10 * ) V_117 -> V_12 ;
if ( F_97 ( V_11 -> V_96 . V_125 ) + V_225 * 2 >
F_97 ( V_11 -> V_96 . V_97 ) )
V_227 ++ ;
* V_107 += 1 ;
F_58 ( V_117 ) ;
V_117 = NULL ;
if ( V_247 <= F_12 ( V_124 . V_128 ) )
break;
else
V_247 -= F_12 ( V_124 . V_128 ) ;
V_246 += V_247 ;
}
}
* V_226 += V_227 ;
if ( ! V_227 )
goto V_53;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_162 ) & V_163 )
* V_107 += V_231 ;
else {
struct V_145 V_146 ;
F_109 ( & V_146 , V_248 , V_51 ) ;
* V_107 += F_181 ( V_56 -> V_77 ,
V_146 . V_230 ,
V_227 ) ;
}
V_53:
F_58 ( V_117 ) ;
return V_50 ;
}
int F_252 ( struct V_56 * V_56 ,
struct V_59 * V_60 ,
struct V_310 * V_311 ,
struct V_1 * V_102 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_236 ,
struct V_312 * V_313 )
{
int V_50 ;
struct V_305 * V_306 = V_311 -> V_314 ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_285 * V_286 = NULL ;
T_2 V_238 , V_239 ;
F_5 ( ! ( V_76 -> V_61 & V_62 ) ) ;
V_50 = F_191 ( V_56 , & V_306 -> V_308 ,
V_118 , V_236 , V_152 ,
& V_238 , & V_239 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_5 ( V_239 == 0 ) ;
V_286 = F_53 ( sizeof( struct V_285 ) , V_48 ) ;
if ( ! V_286 ) {
V_50 = - V_54 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_286 -> V_56 = V_56 ;
V_286 -> V_238 = V_238 ;
V_286 -> V_239 = V_239 ;
V_286 -> V_102 = V_102 ;
V_286 -> V_51 = V_51 ;
V_286 -> V_307 = V_306 ;
V_286 -> V_290 = F_219 ;
V_286 -> V_296 =
F_173 ( V_56 -> V_77 , 1 ) * V_239 ;
V_286 -> V_299 = F_249 ;
V_286 -> V_295 = V_313 ;
F_253 ( & V_286 -> V_288 ,
F_81 ( V_56 ) , V_311 ) ;
V_50 = F_237 ( V_286 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_53:
F_36 ( V_286 ) ;
return V_50 ;
}
int F_254 ( struct V_56 * V_56 ,
struct V_145 * V_288 ,
struct V_2 * V_248 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_246 , T_2 V_247 ,
struct V_210 * V_211 ,
struct V_312 * V_313 )
{
int V_50 ;
T_3 * V_72 ;
int V_107 = 1 , V_227 = 0 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_73 * V_74 = NULL ;
V_50 = F_178 ( V_56 -> V_77 ,
V_248 , V_51 ,
V_246 , V_247 ,
& V_227 , & V_107 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_255 ( V_227 , V_107 ) ;
if ( V_227 ) {
V_50 = F_76 ( F_13 ( V_56 -> V_77 ) ,
V_227 , & V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
if ( V_313 )
V_107 += V_313 -> V_107 ;
V_72 = F_77 ( V_28 , V_107 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_175 ( V_56 , V_288 , V_72 ,
V_118 , V_247 , V_246 ,
V_74 , V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_155 ( V_72 , V_248 , V_51 ,
V_246 , V_247 , 0 ,
V_74 , V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
if ( V_313 && V_313 -> V_297 ) {
V_50 = V_313 -> V_297 ( V_56 , V_72 , V_313 -> V_298 ) ;
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
static int F_256 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 ;
T_3 * V_72 ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
V_72 = F_77 ( F_13 ( V_56 -> V_77 ) ,
V_315 ) ;
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
V_56 -> V_316 = V_317 ;
V_60 -> V_316 = F_87 ( V_56 -> V_316 . V_318 ) ;
V_60 -> V_319 = F_88 ( V_56 -> V_316 . V_320 ) ;
F_90 ( V_72 , V_58 ) ;
V_87:
F_92 ( F_13 ( V_56 -> V_77 ) , V_72 ) ;
V_53:
return V_50 ;
}
static int F_257 ( struct V_56 * V_56 ,
struct V_7 * V_58 )
{
int V_50 , V_321 = 0 ;
struct V_7 * V_51 = NULL ;
struct V_75 * V_76 = F_61 ( V_56 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_12 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_1 * V_102 ;
unsigned int V_281 ;
T_6 V_194 ;
T_2 V_118 , V_247 , V_225 , V_246 ;
struct V_210 V_211 ;
struct V_145 V_322 ;
F_238 ( & V_211 ) ;
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
if ( V_76 -> V_61 & V_323 )
goto V_324;
F_246 ( & V_322 , F_81 ( V_56 ) , V_58 ) ;
V_194 = F_204 ( V_56 ) ;
V_225 = F_187 ( V_56 -> V_77 , V_194 ) ;
V_118 = 0 ;
while ( V_118 < V_225 ) {
V_50 = F_233 ( V_56 , V_118 , & V_246 ,
& V_247 , & V_281 ) ;
if ( V_246 && ! ( V_281 & V_223 ) ) {
V_50 = F_254 ( V_56 , & V_322 ,
& V_102 -> V_4 ,
V_51 , V_118 ,
V_246 , V_247 ,
& V_211 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_277;
}
V_321 = 1 ;
}
V_118 += V_247 ;
}
V_324:
if ( V_76 -> V_61 & V_133 ) {
V_50 = F_258 ( V_56 , V_58 ,
& V_102 -> V_4 ,
V_51 ,
& V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_277;
}
}
if ( V_321 ) {
V_50 = F_256 ( V_56 , V_58 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_277:
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
if ( ! V_50 && F_239 ( & V_211 ) ) {
F_240 ( V_28 , 1 ) ;
F_241 ( V_28 , & V_211 ) ;
}
V_53:
F_247 ( V_56 , 0 ) ;
return V_50 ;
}
static int F_259 ( struct V_56 * V_56 ,
struct V_145 * V_146 ,
struct V_2 * V_248 ,
struct V_7 * V_51 ,
T_2 V_118 , T_2 V_246 , T_2 V_247 ,
unsigned int V_281 ,
struct V_210 * V_211 )
{
int V_50 ;
T_3 * V_72 ;
int V_107 = 0 ;
struct V_27 * V_28 = F_13 ( V_56 -> V_77 ) ;
struct V_73 * V_74 = NULL ;
V_50 = F_195 ( V_56 -> V_77 ,
V_246 , V_247 ,
V_146 , V_248 ,
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
F_173 ( V_56 -> V_77 , V_246 ) ,
V_247 , V_281 , V_74 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_50 = F_167 ( V_72 , V_248 , V_51 ,
V_246 , V_247 ,
V_74 , V_211 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
if ( V_74 )
F_93 ( V_74 ) ;
return V_50 ;
}
static int F_260 ( struct V_56 * V_325 ,
struct V_7 * V_326 ,
struct V_56 * V_327 ,
struct V_7 * V_328 )
{
int V_50 ;
T_3 * V_72 ;
struct V_27 * V_28 = F_13 ( V_325 -> V_77 ) ;
struct V_59 * V_329 = (struct V_59 * ) V_326 -> V_12 ;
struct V_59 * V_330 = (struct V_59 * ) V_328 -> V_12 ;
F_5 ( ! ( F_61 ( V_325 ) -> V_61 & V_323 ) ) ;
V_72 = F_77 ( V_28 , V_315 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_80 ( V_72 , F_81 ( V_327 ) , V_328 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
V_330 -> V_303 . V_331 . V_332 = V_329 -> V_303 . V_331 . V_332 ;
memcpy ( V_330 -> V_303 . V_331 . V_333 , V_329 -> V_303 . V_331 . V_333 ,
F_97 ( V_329 -> V_303 . V_331 . V_332 ) ) ;
F_19 ( & F_61 ( V_327 ) -> V_99 ) ;
F_61 ( V_327 ) -> V_61 |= V_323 ;
V_330 -> V_100 = F_86 ( F_61 ( V_327 ) -> V_61 ) ;
F_21 ( & F_61 ( V_327 ) -> V_99 ) ;
F_90 ( V_72 , V_328 ) ;
V_87:
F_92 ( V_28 , V_72 ) ;
V_53:
return V_50 ;
}
static int F_261 ( struct V_56 * V_325 ,
struct V_56 * V_327 ,
struct V_7 * V_328 ,
struct V_2 * V_248 ,
struct V_7 * V_51 ,
struct V_210 * V_211 )
{
int V_50 = 0 ;
T_2 V_246 , V_247 , V_225 , V_118 ;
T_6 V_194 ;
unsigned int V_281 ;
struct V_145 V_146 ;
F_246 ( & V_146 , F_81 ( V_327 ) , V_328 ) ;
V_194 = F_204 ( V_325 ) ;
V_225 = F_187 ( V_325 -> V_77 , V_194 ) ;
V_118 = 0 ;
while ( V_118 < V_225 ) {
V_50 = F_233 ( V_325 , V_118 , & V_246 ,
& V_247 , & V_281 ) ;
if ( V_246 ) {
V_50 = F_259 ( V_327 , & V_146 ,
V_248 , V_51 ,
V_118 , V_246 ,
V_247 ,
V_281 ,
V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
}
V_118 += V_247 ;
}
V_53:
return V_50 ;
}
static int F_262 ( struct V_56 * V_325 ,
struct V_7 * V_326 ,
struct V_56 * V_327 ,
struct V_7 * V_328 ,
bool V_334 )
{
int V_50 ;
T_3 * V_72 ;
struct V_59 * V_329 = (struct V_59 * ) V_326 -> V_12 ;
struct V_59 * V_60 = (struct V_59 * ) V_328 -> V_12 ;
T_6 V_194 = F_204 ( V_325 ) ;
V_72 = F_77 ( F_13 ( V_327 -> V_77 ) ,
V_315 ) ;
if ( F_78 ( V_72 ) ) {
V_50 = F_79 ( V_72 ) ;
F_56 ( V_50 ) ;
return V_50 ;
}
V_50 = F_80 ( V_72 , F_81 ( V_327 ) , V_328 ,
V_86 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_87;
}
F_19 ( & F_61 ( V_327 ) -> V_99 ) ;
F_61 ( V_327 ) -> V_132 = F_61 ( V_325 ) -> V_132 ;
F_61 ( V_327 ) -> V_335 = F_61 ( V_325 ) -> V_335 ;
F_61 ( V_327 ) -> V_61 = F_61 ( V_325 ) -> V_61 ;
F_21 ( & F_61 ( V_327 ) -> V_99 ) ;
F_263 ( V_327 , V_194 ) ;
V_327 -> V_336 = V_325 -> V_336 ;
V_60 -> V_337 = V_329 -> V_337 ;
V_60 -> V_338 = V_329 -> V_338 ;
V_60 -> V_339 = V_329 -> V_339 ;
V_60 -> V_100 = V_329 -> V_100 ;
V_60 -> V_340 = V_329 -> V_340 ;
if ( V_334 ) {
V_327 -> V_341 = V_325 -> V_341 ;
V_327 -> V_342 = V_325 -> V_342 ;
V_327 -> V_343 = V_325 -> V_343 ;
V_60 -> V_341 = V_329 -> V_341 ;
V_60 -> V_342 = V_329 -> V_342 ;
V_60 -> V_343 = V_329 -> V_343 ;
V_327 -> V_316 = V_317 ;
V_60 -> V_316 = F_87 ( V_327 -> V_316 . V_318 ) ;
V_60 -> V_319 = F_88 ( V_327 -> V_316 . V_320 ) ;
V_327 -> V_344 = V_325 -> V_344 ;
V_60 -> V_344 = V_329 -> V_344 ;
V_60 -> V_345 = V_329 -> V_345 ;
}
F_90 ( V_72 , V_328 ) ;
V_87:
F_92 ( F_13 ( V_327 -> V_77 ) , V_72 ) ;
return V_50 ;
}
static int F_264 ( struct V_56 * V_325 ,
struct V_7 * V_326 ,
struct V_56 * V_327 ,
struct V_7 * V_328 ,
bool V_334 )
{
int V_50 ;
struct V_7 * V_51 = NULL ;
struct V_210 V_211 ;
struct V_27 * V_28 = F_13 ( V_325 -> V_77 ) ;
struct V_10 * V_11 ;
struct V_59 * V_60 = (struct V_59 * ) V_326 -> V_12 ;
struct V_1 * V_102 ;
F_238 ( & V_211 ) ;
V_50 = F_94 ( V_327 , V_328 ,
F_11 ( V_60 -> V_63 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
if ( F_61 ( V_325 ) -> V_61 & V_323 ) {
V_50 = F_260 ( V_325 , V_326 ,
V_327 , V_328 ) ;
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
V_50 = F_261 ( V_325 , V_327 , V_328 ,
& V_102 -> V_4 , V_51 ,
& V_211 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_346;
}
V_346:
F_67 ( V_28 , V_102 , 1 ) ;
F_58 ( V_51 ) ;
V_53:
if ( F_239 ( & V_211 ) ) {
F_240 ( V_28 , 1 ) ;
F_241 ( V_28 , & V_211 ) ;
}
return V_50 ;
}
static int F_265 ( struct V_257 * V_347 ,
struct V_7 * V_280 ,
struct V_56 * V_348 ,
bool V_334 )
{
int V_50 ;
struct V_56 * V_56 = V_347 -> V_258 ;
struct V_7 * V_78 = NULL ;
if ( F_61 ( V_56 ) -> V_349 & V_350 ) {
V_50 = - V_17 ;
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_266 ( V_56 -> V_270 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
V_50 = F_257 ( V_56 , V_280 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_53;
}
F_267 ( & V_348 -> V_113 , V_351 ) ;
V_50 = F_268 ( V_348 , & V_78 , 1 ,
V_352 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_116;
}
V_50 = F_264 ( V_56 , V_280 ,
V_348 , V_78 , V_334 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_353;
}
if ( F_61 ( V_56 ) -> V_61 & V_133 ) {
V_50 = F_269 ( V_56 , V_280 ,
V_348 , V_78 ,
V_334 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_353;
}
}
V_50 = F_262 ( V_56 , V_280 ,
V_348 , V_78 , V_334 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_353:
F_102 ( V_348 , 1 ) ;
F_58 ( V_78 ) ;
V_116:
F_25 ( & V_348 -> V_113 ) ;
V_53:
if ( ! V_50 ) {
V_50 = F_270 ( V_56 -> V_270 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
return V_50 ;
}
static int F_271 ( struct V_257 * V_347 , struct V_56 * V_354 ,
struct V_257 * V_355 , bool V_334 )
{
int error ;
struct V_56 * V_56 = V_347 -> V_258 ;
struct V_7 * V_280 = NULL ;
struct V_56 * V_356 = NULL ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) )
return - V_357 ;
error = F_272 ( V_354 , V_56 -> V_343 ,
& V_356 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
error = F_100 ( V_56 , & V_280 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
F_64 ( & F_61 ( V_56 ) -> V_130 ) ;
F_64 ( & F_61 ( V_56 ) -> V_131 ) ;
error = F_265 ( V_347 , V_280 ,
V_356 , V_334 ) ;
F_68 ( & F_61 ( V_56 ) -> V_131 ) ;
F_68 ( & F_61 ( V_56 ) -> V_130 ) ;
F_102 ( V_56 , 1 ) ;
F_58 ( V_280 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_53;
}
if ( ! V_334 ) {
error = F_273 ( V_354 , V_356 ,
& V_355 -> V_358 ) ;
if ( error )
F_56 ( error ) ;
}
V_53:
if ( ! error ) {
error = F_274 ( V_354 , V_356 ,
V_355 ) ;
if ( error )
F_56 ( error ) ;
}
if ( V_356 ) {
F_275 ( V_356 ) ;
if ( error )
F_103 ( V_356 ) ;
}
return error ;
}
static inline int F_276 ( struct V_56 * V_354 , struct V_257 * V_359 )
{
if ( V_359 -> V_258 )
return - V_360 ;
if ( F_277 ( V_354 ) )
return - V_361 ;
return F_278 ( V_354 , V_362 | V_363 ) ;
}
static int F_279 ( struct V_257 * V_347 , struct V_56 * V_354 ,
struct V_257 * V_355 , bool V_334 )
{
struct V_56 * V_56 = V_347 -> V_258 ;
int error ;
if ( ! V_56 )
return - V_361 ;
error = F_276 ( V_354 , V_355 ) ;
if ( error )
return error ;
if ( V_354 -> V_77 != V_56 -> V_77 )
return - V_364 ;
if ( F_280 ( V_56 ) || F_281 ( V_56 ) )
return - V_365 ;
if ( ! F_282 ( V_56 -> V_343 ) )
return - V_365 ;
if ( V_334 ) {
if ( ( F_283 () != V_56 -> V_341 ) && ! F_284 ( V_366 ) )
return - V_365 ;
if ( ! F_285 ( V_56 -> V_342 ) && ! F_284 ( V_366 ) )
return - V_365 ;
}
if ( ! V_334 ) {
error = F_278 ( V_56 , V_367 ) ;
if ( error )
return error ;
}
F_23 ( & V_56 -> V_113 ) ;
F_286 ( V_354 ) ;
error = F_271 ( V_347 , V_354 , V_355 , V_334 ) ;
F_25 ( & V_56 -> V_113 ) ;
if ( ! error )
F_287 ( V_354 , V_355 ) ;
return error ;
}
int F_288 ( struct V_56 * V_56 ,
const char T_7 * V_368 ,
const char T_7 * V_369 ,
bool V_334 )
{
struct V_257 * V_355 ;
struct V_208 V_370 , V_371 ;
int error ;
if ( ! V_1 ( F_13 ( V_56 -> V_77 ) ) )
return - V_357 ;
error = F_289 ( V_372 , V_368 , 0 , & V_370 ) ;
if ( error ) {
F_56 ( error ) ;
return error ;
}
V_355 = F_290 ( V_372 , V_369 , & V_371 , 0 ) ;
error = F_79 ( V_355 ) ;
if ( F_78 ( V_355 ) ) {
F_56 ( error ) ;
goto V_53;
}
error = - V_364 ;
if ( V_370 . V_373 != V_371 . V_373 ) {
F_56 ( error ) ;
goto V_374;
}
error = F_279 ( V_370 . V_257 ,
V_371 . V_257 -> V_258 ,
V_355 , V_334 ) ;
V_374:
F_291 ( & V_371 , V_355 ) ;
V_53:
F_292 ( & V_370 ) ;
return error ;
}
