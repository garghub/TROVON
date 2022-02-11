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
V_9 = F_10 ( V_6 ,
L_2 ,
( unsigned long long ) V_8 -> V_13 , 7 ,
V_11 -> V_16 ) ;
goto V_17;
}
if ( F_11 ( V_11 -> V_18 ) != V_8 -> V_13 ) {
V_9 = F_10 ( V_6 ,
L_3 ,
( unsigned long long ) V_8 -> V_13 ,
( unsigned long long ) F_11 ( V_11 -> V_18 ) ) ;
goto V_17;
}
if ( F_12 ( V_11 -> V_19 ) != F_13 ( V_6 ) -> V_20 ) {
V_9 = F_10 ( V_6 ,
L_4 ,
( unsigned long long ) V_8 -> V_13 ,
F_12 ( V_11 -> V_19 ) ) ;
goto V_17;
}
V_17:
return V_9 ;
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
F_8 ( V_15 , L_5 ,
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
goto V_17;
F_21 ( & V_28 -> V_42 ) ;
V_37 = F_52 ( V_28 , V_18 ) ;
if ( ! V_37 ) {
V_50 = - V_53 ;
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
V_37 -> V_54 = F_12 ( V_52 -> V_54 ) ;
F_49 ( V_28 , V_37 , V_18 ,
V_37 -> V_54 ) ;
F_57 ( & V_37 -> V_4 ) ;
F_19 ( & V_28 -> V_42 ) ;
V_33 = F_26 ( V_28 , V_18 ) ;
if ( V_33 )
goto V_17;
F_28 ( V_28 , V_37 ) ;
V_33 = V_37 ;
V_37 = NULL ;
V_17:
* V_49 = V_33 ;
V_28 -> V_41 = V_33 ;
F_21 ( & V_28 -> V_42 ) ;
if ( V_37 )
F_32 ( V_37 ) ;
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_59 ( struct V_55 * V_55 , T_1 * V_56 )
{
int V_50 ;
struct V_7 * V_57 = NULL ;
struct V_58 * V_59 ;
V_50 = F_60 ( V_55 , & V_57 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_5 ( ! ( F_61 ( V_55 ) -> V_60 & V_61 ) ) ;
V_59 = (struct V_58 * ) V_57 -> V_12 ;
* V_56 = F_11 ( V_59 -> V_62 ) ;
F_58 ( V_57 ) ;
V_17:
return V_50 ;
}
static int F_62 ( struct V_27 * V_28 ,
struct V_1 * V_33 , int V_63 )
{
int V_50 ;
V_50 = F_63 ( V_33 , V_63 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_63 )
F_64 ( & V_33 -> V_47 ) ;
else
F_65 ( & V_33 -> V_47 ) ;
V_17:
return V_50 ;
}
int F_66 ( struct V_27 * V_28 ,
T_1 V_56 , int V_63 ,
struct V_1 * * V_49 ,
struct V_7 * * V_64 )
{
int V_50 , V_65 = 0 ;
struct V_1 * V_33 = NULL ;
struct V_7 * V_51 = NULL ;
struct V_10 * V_11 ;
V_66:
V_50 = F_55 ( V_28 , V_56 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
F_41 ( V_33 ) ;
V_50 = F_62 ( V_28 , V_33 , V_63 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
F_43 ( V_33 ) ;
goto V_17;
}
V_50 = F_14 ( & V_33 -> V_4 , V_33 -> V_18 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
F_67 ( V_28 , V_33 , V_63 ) ;
F_43 ( V_33 ) ;
goto V_17;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( V_33 -> V_54 != F_12 ( V_11 -> V_54 ) ) {
if ( ! V_33 -> V_67 ) {
F_39 ( V_28 , V_33 ) ;
V_33 -> V_67 = 1 ;
V_65 = 1 ;
}
F_67 ( V_28 , V_33 , V_63 ) ;
if ( V_65 )
F_43 ( V_33 ) ;
F_58 ( V_51 ) ;
V_51 = NULL ;
goto V_66;
}
* V_49 = V_33 ;
if ( V_64 ) {
* V_64 = V_51 ;
V_51 = NULL ;
}
V_17:
F_58 ( V_51 ) ;
return V_50 ;
}
void F_67 ( struct V_27 * V_28 ,
struct V_1 * V_33 , int V_63 )
{
if ( V_63 )
F_68 ( & V_33 -> V_47 ) ;
else
F_69 ( & V_33 -> V_47 ) ;
F_70 ( V_33 , V_63 ) ;
F_43 ( V_33 ) ;
}
void F_71 ( struct V_27 * V_28 )
{
struct V_30 * V_68 ;
struct V_1 * V_33 ;
struct V_69 * V_70 = & V_28 -> V_32 ;
while ( ( V_68 = F_72 ( V_70 ) ) != NULL ) {
V_33 = F_27 ( V_68 , struct V_1 , V_34 ) ;
F_73 (
( unsigned long long ) V_33 -> V_18 ) ;
F_38 ( & V_33 -> V_34 , V_70 ) ;
F_32 ( V_33 ) ;
}
}
static int F_74 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 ;
T_3 * V_71 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_7 * V_77 = NULL ;
struct V_10 * V_11 ;
struct V_1 * V_78 = NULL , * V_33 = NULL ;
T_4 V_79 ;
T_2 V_80 ;
T_1 V_81 , V_82 ;
F_5 ( V_75 -> V_60 & V_61 ) ;
F_75 (
( unsigned long long ) F_61 ( V_55 ) -> V_83 ) ;
V_50 = F_76 ( V_28 , 1 , & V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_71 = F_77 ( V_28 , V_84 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_80 ( V_71 , F_81 ( V_55 ) , V_57 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_82 ( V_71 , V_73 , 1 , & V_81 ,
& V_79 , & V_80 ,
& V_82 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_78 = F_52 ( V_28 , V_82 ) ;
if ( ! V_78 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_86;
}
V_77 = F_83 ( V_55 -> V_76 , V_82 ) ;
if ( ! V_77 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_86;
}
F_84 ( & V_78 -> V_4 , V_77 ) ;
V_50 = F_85 ( V_71 , & V_78 -> V_4 , V_77 ,
V_87 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_11 = (struct V_10 * ) V_77 -> V_12 ;
memset ( V_11 , 0 , V_55 -> V_76 -> V_88 ) ;
strcpy ( ( void * ) V_11 , V_89 ) ;
V_11 -> V_90 = F_86 ( V_73 -> V_91 ) ;
V_11 -> V_92 = F_87 ( V_81 ) ;
V_11 -> V_93 = F_86 ( V_79 ) ;
V_11 -> V_19 = F_88 ( V_28 -> V_20 ) ;
V_11 -> V_18 = F_87 ( V_82 ) ;
V_11 -> V_94 = F_88 ( 1 ) ;
V_11 -> V_95 . V_96 =
F_86 ( F_89 ( V_28 -> V_6 ) ) ;
F_19 ( & V_28 -> V_42 ) ;
V_11 -> V_54 = V_28 -> V_97 ++ ;
F_21 ( & V_28 -> V_42 ) ;
F_90 ( V_71 , V_77 ) ;
F_19 ( & V_75 -> V_98 ) ;
V_75 -> V_60 |= V_61 ;
V_59 -> V_99 = F_86 ( V_75 -> V_60 ) ;
V_59 -> V_62 = F_87 ( V_82 ) ;
F_21 ( & V_75 -> V_98 ) ;
F_91 ( ( unsigned long long ) V_82 ) ;
F_90 ( V_71 , V_57 ) ;
V_78 -> V_54 = F_12 ( V_11 -> V_54 ) ;
F_49 ( V_28 , V_78 , V_82 ,
V_78 -> V_54 ) ;
F_19 ( & V_28 -> V_42 ) ;
V_33 = F_26 ( V_28 , V_82 ) ;
F_5 ( V_33 && V_33 -> V_54 == V_78 -> V_54 ) ;
if ( V_33 )
F_37 ( V_28 , V_33 ) ;
F_28 ( V_28 , V_78 ) ;
F_21 ( & V_28 -> V_42 ) ;
V_78 = NULL ;
if ( V_33 )
F_43 ( V_33 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_78 ) {
F_33 ( & V_78 -> V_4 ) ;
F_36 ( V_78 ) ;
}
F_58 ( V_77 ) ;
if ( V_73 )
F_93 ( V_73 ) ;
return V_50 ;
}
static int F_94 ( struct V_55 * V_55 ,
struct V_7 * V_57 ,
T_1 V_100 )
{
int V_50 ;
T_3 * V_71 = NULL ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_7 * V_51 = NULL ;
struct V_10 * V_11 ;
struct V_1 * V_101 ;
F_5 ( V_75 -> V_60 & V_61 ) ;
V_50 = F_66 ( V_28 , V_100 , 1 ,
& V_101 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_71 = F_77 ( V_28 , V_102 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_80 ( V_71 , F_81 ( V_55 ) , V_57 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_85 ( V_71 , & V_101 -> V_4 , V_51 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
F_95 ( & V_11 -> V_94 , 1 ) ;
F_90 ( V_71 , V_51 ) ;
F_19 ( & V_75 -> V_98 ) ;
V_75 -> V_60 |= V_61 ;
V_59 -> V_99 = F_86 ( V_75 -> V_60 ) ;
V_59 -> V_62 = F_87 ( V_100 ) ;
F_21 ( & V_75 -> V_98 ) ;
F_90 ( V_71 , V_57 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
return V_50 ;
}
int F_96 ( struct V_55 * V_55 , struct V_7 * V_57 )
{
int V_50 , V_65 = 0 ;
T_3 * V_71 = NULL ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_10 * V_11 ;
struct V_55 * V_103 = NULL ;
struct V_7 * V_104 = NULL ;
struct V_7 * V_105 = NULL ;
struct V_1 * V_101 ;
int V_106 = V_107 ;
T_1 V_108 = 0 , V_109 = 0 , V_56 = F_11 ( V_59 -> V_62 ) ;
T_4 V_110 = 0 ;
if ( ! ( V_75 -> V_60 & V_61 ) )
return 0 ;
F_5 ( ! V_56 ) ;
V_50 = F_66 ( V_28 , V_56 , 1 , & V_101 , & V_105 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_11 = (struct V_10 * ) V_105 -> V_12 ;
if ( F_12 ( V_11 -> V_94 ) == 1 ) {
V_108 = F_11 ( V_11 -> V_18 ) ;
V_110 = F_97 ( V_11 -> V_93 ) ;
if ( V_11 -> V_92 )
V_109 = F_11 ( V_11 -> V_92 ) ;
else
V_109 = F_98 ( V_108 , V_110 ) ;
V_103 = F_99 ( V_28 ,
V_111 ,
F_97 ( V_11 -> V_90 ) ) ;
if ( ! V_103 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
F_23 ( & V_103 -> V_112 ) ;
V_50 = F_100 ( V_103 , & V_104 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_113;
}
V_106 += V_114 ;
}
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_115;
}
V_50 = F_80 ( V_71 , F_81 ( V_55 ) , V_57 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_85 ( V_71 , & V_101 -> V_4 , V_105 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
F_19 ( & V_75 -> V_98 ) ;
V_75 -> V_60 &= ~ V_61 ;
V_59 -> V_99 = F_86 ( V_75 -> V_60 ) ;
V_59 -> V_62 = 0 ;
F_21 ( & V_75 -> V_98 ) ;
F_90 ( V_71 , V_57 ) ;
F_95 ( & V_11 -> V_94 , - 1 ) ;
F_90 ( V_71 , V_105 ) ;
if ( ! V_11 -> V_94 ) {
V_65 = 1 ;
F_39 ( V_28 , V_101 ) ;
V_50 = F_101 ( V_71 , V_103 ,
V_104 , V_110 , V_109 , 1 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_86:
F_92 ( V_28 , V_71 ) ;
V_115:
if ( V_103 ) {
F_102 ( V_103 , 1 ) ;
F_58 ( V_104 ) ;
}
V_113:
if ( V_103 ) {
F_25 ( & V_103 -> V_112 ) ;
F_103 ( V_103 ) ;
}
V_17:
F_67 ( V_28 , V_101 , 1 ) ;
if ( V_65 )
F_43 ( V_101 ) ;
F_58 ( V_105 ) ;
return V_50 ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_7 * V_116 ,
T_1 V_117 , unsigned int V_118 ,
struct V_119 * V_120 ,
int * V_121 )
{
int V_122 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_119 * V_123 = NULL ;
for (; V_122 < F_97 ( V_11 -> V_95 . V_124 ) ; V_122 ++ ) {
V_123 = & V_11 -> V_95 . V_125 [ V_122 ] ;
if ( F_11 ( V_123 -> V_126 ) +
F_12 ( V_123 -> V_127 ) <= V_117 )
continue;
else if ( F_11 ( V_123 -> V_126 ) > V_117 )
break;
if ( V_120 )
* V_120 = * V_123 ;
goto V_17;
}
if ( V_120 ) {
V_120 -> V_126 = F_87 ( V_117 ) ;
V_120 -> V_128 = 0 ;
if ( V_122 < F_97 ( V_11 -> V_95 . V_124 ) &&
F_11 ( V_123 -> V_126 ) < V_117 + V_118 )
V_120 -> V_127 =
F_88 ( F_11 ( V_123 -> V_126 ) - V_117 ) ;
else
V_120 -> V_127 = F_88 ( V_118 ) ;
}
V_17:
* V_121 = V_122 ;
}
int F_105 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
F_64 ( & V_75 -> V_129 ) ;
F_64 ( & V_75 -> V_130 ) ;
if ( V_75 -> V_131 )
goto V_17;
if ( ( V_75 -> V_60 & V_132 ) && V_59 -> V_133 )
goto V_17;
if ( V_75 -> V_60 & V_134 &&
F_106 ( V_55 , V_59 ) )
goto V_17;
V_50 = F_96 ( V_55 , V_57 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_68 ( & V_75 -> V_130 ) ;
F_68 ( & V_75 -> V_129 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_135 * V_136 ,
struct V_137 * V_138 ,
int V_121 , T_2 * V_139 )
{
int V_50 , V_122 , V_140 ;
T_2 V_117 ;
T_1 V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_141 * V_142 = NULL , * V_143 = NULL ;
struct V_144 V_145 ;
struct V_137 * V_146 ;
if ( V_121 < F_97 ( V_138 -> V_147 ) - 1 ) {
* V_139 = F_12 ( V_138 -> V_148 [ V_121 + 1 ] . V_149 ) ;
return 0 ;
}
if ( ! V_136 || ( V_136 && ! V_136 -> V_150 ) ) {
* V_139 = V_151 ;
return 0 ;
}
F_109 ( & V_145 , V_3 , V_51 ) ;
V_142 = F_110 ( & V_145 ) ;
if ( ! V_142 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_117 = F_12 ( V_136 -> V_152 . V_148 [ V_121 ] . V_149 ) ;
V_50 = F_111 ( V_3 , V_142 , V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_143 = F_112 ( V_142 ) ;
if ( ! V_143 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_113 ( V_6 , V_142 , & V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_111 ( V_3 , V_143 , V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_140 = F_114 ( & V_145 , V_142 ,
V_143 ) ;
V_146 = V_142 -> V_153 [ V_140 ] . V_138 ;
V_29 = V_142 -> V_153 [ V_140 + 1 ] . V_8 -> V_13 ;
for ( V_122 = 0 ; V_122 < F_97 ( V_146 -> V_147 ) ; V_122 ++ ) {
if ( F_11 ( V_146 -> V_148 [ V_122 ] . V_154 ) == V_29 ) {
* V_139 = F_12 ( V_146 -> V_148 [ V_122 + 1 ] . V_149 ) ;
break;
}
}
F_5 ( V_122 == F_97 ( V_146 -> V_147 ) ) ;
V_17:
F_115 ( V_142 ) ;
F_115 ( V_143 ) ;
return V_50 ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_117 , unsigned int V_118 ,
struct V_119 * V_120 ,
int * V_121 ,
struct V_7 * * V_155 )
{
int V_50 = 0 , V_122 , V_156 ;
T_2 V_157 , V_158 ( V_139 ) ;
struct V_137 * V_138 ;
struct V_159 * V_123 = NULL ;
struct V_135 * V_136 = NULL ;
struct V_7 * V_160 = NULL , * V_116 = NULL ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
if ( ! ( F_12 ( V_11 -> V_161 ) & V_162 ) ) {
F_104 ( V_3 , V_51 , V_117 , V_118 ,
V_120 , V_121 ) ;
* V_155 = V_51 ;
F_117 ( V_51 ) ;
return 0 ;
}
V_138 = & V_11 -> V_163 ;
V_157 = V_117 & V_164 ;
if ( V_138 -> V_165 ) {
V_50 = F_118 ( V_3 , V_138 , V_157 , & V_160 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_136 = (struct V_135 * ) V_160 -> V_12 ;
V_138 = & V_136 -> V_152 ;
if ( V_138 -> V_165 ) {
V_50 = F_10 ( V_6 ,
L_6 ,
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_160 -> V_13 ) ;
goto V_17;
}
}
V_156 = 0 ;
for ( V_122 = F_97 ( V_138 -> V_147 ) - 1 ; V_122 >= 0 ; V_122 -- ) {
V_123 = & V_138 -> V_148 [ V_122 ] ;
if ( F_12 ( V_123 -> V_149 ) <= V_157 ) {
V_156 = 1 ;
break;
}
}
if ( V_156 ) {
V_50 = F_107 ( V_3 , V_51 ,
V_136 , V_138 , V_122 , & V_139 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_139 < V_157 + V_118 )
V_118 = V_139 - V_157 ;
}
V_50 = F_14 ( V_3 , F_11 ( V_123 -> V_154 ) ,
& V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_104 ( V_3 , V_116 , V_117 , V_118 ,
V_120 , V_121 ) ;
* V_155 = V_116 ;
V_17:
F_58 ( V_160 ) ;
return V_50 ;
}
static enum V_166
F_120 ( struct V_10 * V_11 ,
int V_121 )
{
if ( ( V_11 -> V_95 . V_125 [ V_121 ] . V_128 ==
V_11 -> V_95 . V_125 [ V_121 + 1 ] . V_128 ) &&
( F_11 ( V_11 -> V_95 . V_125 [ V_121 ] . V_126 ) +
F_12 ( V_11 -> V_95 . V_125 [ V_121 ] . V_127 ) ==
F_11 ( V_11 -> V_95 . V_125 [ V_121 + 1 ] . V_126 ) ) )
return V_167 ;
return V_168 ;
}
static enum V_166
F_121 ( struct V_10 * V_11 ,
int V_121 )
{
enum V_166 V_50 = V_168 ;
if ( V_121 < F_97 ( V_11 -> V_95 . V_124 ) - 1 )
V_50 = F_120 ( V_11 , V_121 ) ;
if ( V_121 > 0 ) {
enum V_166 V_22 ;
V_22 = F_120 ( V_11 , V_121 - 1 ) ;
if ( V_22 == V_167 ) {
if ( V_50 == V_167 )
V_50 = V_169 ;
else
V_50 = V_170 ;
}
}
return V_50 ;
}
static void F_122 ( struct V_10 * V_11 ,
int V_121 )
{
F_5 ( V_11 -> V_95 . V_125 [ V_121 ] . V_128 !=
V_11 -> V_95 . V_125 [ V_121 + 1 ] . V_128 ) ;
F_95 ( & V_11 -> V_95 . V_125 [ V_121 ] . V_127 ,
F_12 ( V_11 -> V_95 . V_125 [ V_121 + 1 ] . V_127 ) ) ;
if ( V_121 < F_97 ( V_11 -> V_95 . V_124 ) - 2 )
memmove ( & V_11 -> V_95 . V_125 [ V_121 + 1 ] ,
& V_11 -> V_95 . V_125 [ V_121 + 2 ] ,
sizeof( struct V_119 ) *
( F_97 ( V_11 -> V_95 . V_124 ) - V_121 - 2 ) ) ;
memset ( & V_11 -> V_95 . V_125 [ F_97 ( V_11 -> V_95 . V_124 ) - 1 ] ,
0 , sizeof( struct V_119 ) ) ;
F_123 ( & V_11 -> V_95 . V_124 , - 1 ) ;
}
static void F_124 ( struct V_10 * V_11 ,
int V_121 )
{
enum V_166 V_171 =
F_121 ( V_11 , V_121 ) ;
if ( V_171 == V_168 )
return;
if ( V_171 == V_170 || V_171 == V_169 ) {
F_5 ( V_121 == 0 ) ;
V_121 -- ;
}
F_122 ( V_11 , V_121 ) ;
if ( V_171 == V_169 )
F_122 ( V_11 , V_121 ) ;
}
static int F_125 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_116 ,
int V_121 , int V_172 , int V_173 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_174 * V_175 = & V_11 -> V_95 ;
struct V_119 * V_123 = & V_175 -> V_125 [ V_121 ] ;
V_50 = F_85 ( V_71 , V_3 , V_116 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_126 (
( unsigned long long ) F_119 ( V_3 ) ,
V_121 , F_12 ( V_123 -> V_128 ) , V_173 ) ;
F_95 ( & V_123 -> V_128 , V_173 ) ;
if ( ! V_123 -> V_128 ) {
if ( V_121 != F_97 ( V_175 -> V_124 ) - 1 ) {
memmove ( V_123 , V_123 + 1 ,
( F_97 ( V_175 -> V_124 ) - V_121 - 1 ) *
sizeof( struct V_119 ) ) ;
memset ( & V_175 -> V_125 [ F_97 ( V_175 -> V_124 ) - 1 ] ,
0 , sizeof( struct V_119 ) ) ;
}
F_123 ( & V_175 -> V_124 , - 1 ) ;
} else if ( V_172 )
F_124 ( V_11 , V_121 ) ;
F_90 ( V_71 , V_116 ) ;
V_17:
return V_50 ;
}
static int F_127 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * * V_116 ,
struct V_72 * V_73 )
{
int V_50 ;
T_4 V_79 ;
T_2 V_80 ;
T_1 V_81 , V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_7 * V_77 = NULL ;
struct V_10 * V_176 ;
struct V_10 * V_177 =
(struct V_10 * ) V_51 -> V_12 ;
V_50 = F_85 ( V_71 , V_3 , V_51 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_82 ( V_71 , V_73 , 1 , & V_81 ,
& V_79 , & V_80 ,
& V_29 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_77 = F_83 ( V_6 , V_29 ) ;
if ( V_77 == NULL ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
F_84 ( V_3 , V_77 ) ;
V_50 = F_85 ( V_71 , V_3 , V_77 ,
V_87 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
memcpy ( V_77 -> V_12 , V_51 -> V_12 , V_6 -> V_88 ) ;
V_176 = (struct V_10 * ) V_77 -> V_12 ;
V_176 -> V_90 = F_86 ( V_73 -> V_91 ) ;
V_176 -> V_92 = F_87 ( V_81 ) ;
V_176 -> V_93 = F_86 ( V_79 ) ;
V_176 -> V_18 = F_87 ( V_29 ) ;
V_176 -> V_178 = F_88 ( 0 ) ;
V_176 -> V_179 = F_87 ( V_51 -> V_13 ) ;
V_176 -> V_161 = F_88 ( V_180 ) ;
F_90 ( V_71 , V_77 ) ;
memset ( & V_177 -> V_163 , 0 , V_6 -> V_88 -
F_128 ( struct V_10 , V_163 ) ) ;
V_177 -> V_163 . V_181 = F_86 ( F_129 ( V_6 ) ) ;
V_177 -> V_182 = F_88 ( 1 ) ;
V_177 -> V_163 . V_147 = F_86 ( 1 ) ;
V_177 -> V_163 . V_148 [ 0 ] . V_154 = F_87 ( V_29 ) ;
V_177 -> V_163 . V_148 [ 0 ] . V_183 = F_86 ( 1 ) ;
V_177 -> V_161 = F_88 ( V_162 ) ;
F_90 ( V_71 , V_51 ) ;
F_130 ( ( unsigned long long ) V_29 ,
F_97 ( V_176 -> V_95 . V_124 ) ) ;
* V_116 = V_77 ;
V_77 = NULL ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_131 ( struct V_119 * V_184 ,
struct V_119 * V_185 )
{
if ( F_132 ( V_184 ) + F_12 ( V_184 -> V_127 ) <=
F_132 ( V_185 ) )
return 1 ;
return 0 ;
}
static int F_133 ( const void * V_186 , const void * V_187 )
{
const struct V_119 * V_188 = V_186 , * V_189 = V_187 ;
T_2 V_190 = F_132 ( V_188 ) ;
T_2 V_126 = F_132 ( V_189 ) ;
if ( V_190 > V_126 )
return 1 ;
if ( V_190 < V_126 )
return - 1 ;
return 0 ;
}
static int F_134 ( const void * V_186 , const void * V_187 )
{
const struct V_119 * V_188 = V_186 , * V_189 = V_187 ;
T_1 V_190 = F_11 ( V_188 -> V_126 ) ;
T_1 V_126 = F_11 ( V_189 -> V_126 ) ;
if ( V_190 > V_126 )
return 1 ;
if ( V_190 < V_126 )
return - 1 ;
return 0 ;
}
static void F_135 ( void * V_186 , void * V_187 , int V_191 )
{
struct V_119 * V_188 = V_186 , * V_189 = V_187 ;
F_136 ( * V_188 , * V_189 ) ;
}
static int F_137 ( struct V_174 * V_175 ,
T_2 * V_192 , int * V_193 )
{
int V_194 = F_97 ( V_175 -> V_124 ) ;
int V_195 , V_196 = V_194 / 2 ;
for ( V_195 = 0 ; V_195 < V_196 ; V_195 ++ ) {
if ( F_131 (
& V_175 -> V_125 [ V_196 - V_195 - 1 ] ,
& V_175 -> V_125 [ V_196 - V_195 ] ) ) {
* V_193 = V_196 - V_195 ;
break;
}
if ( ( V_196 + V_195 + 1 ) == V_194 )
continue;
if ( F_131 (
& V_175 -> V_125 [ V_196 + V_195 ] ,
& V_175 -> V_125 [ V_196 + V_195 + 1 ] ) ) {
* V_193 = V_196 + V_195 + 1 ;
break;
}
}
if ( V_195 >= V_196 )
return - V_197 ;
* V_192 = F_132 ( & V_175 -> V_125 [ * V_193 ] ) ;
return 0 ;
}
static int F_138 ( struct V_7 * V_116 ,
struct V_7 * V_77 ,
T_2 * V_198 )
{
int V_193 = 0 , V_199 , V_50 ;
T_2 V_117 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_174 * V_175 = & V_11 -> V_95 ;
struct V_10 * V_176 =
(struct V_10 * ) V_77 -> V_12 ;
struct V_174 * V_200 = & V_176 -> V_95 ;
F_139 (
( unsigned long long ) V_116 -> V_13 ,
F_97 ( V_175 -> V_96 ) , F_97 ( V_175 -> V_124 ) ) ;
F_140 ( & V_175 -> V_125 , F_97 ( V_175 -> V_124 ) ,
sizeof( struct V_119 ) ,
F_133 , F_135 ) ;
V_50 = F_137 ( V_175 , & V_117 , & V_193 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_176 -> V_178 = F_88 ( V_117 ) ;
V_199 = F_97 ( V_175 -> V_124 ) - V_193 ;
memcpy ( V_200 -> V_125 , & V_175 -> V_125 [ V_193 ] ,
V_199 * sizeof( struct V_119 ) ) ;
memset ( & V_175 -> V_125 [ V_193 ] , 0 ,
V_199 * sizeof( struct V_119 ) ) ;
F_123 ( & V_175 -> V_124 , - V_199 ) ;
V_200 -> V_124 = F_86 ( V_199 ) ;
F_140 ( & V_175 -> V_125 , F_97 ( V_175 -> V_124 ) ,
sizeof( struct V_119 ) ,
F_134 , F_135 ) ;
F_140 ( & V_200 -> V_125 , F_97 ( V_200 -> V_124 ) ,
sizeof( struct V_119 ) ,
F_134 , F_135 ) ;
* V_198 = V_117 ;
return 0 ;
}
static int F_141 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_72 * V_73 )
{
int V_50 ;
T_4 V_79 ;
T_2 V_80 , V_201 ;
T_1 V_81 , V_29 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_177 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_7 * V_77 = NULL ;
struct V_10 * V_176 ;
struct V_144 V_202 ;
F_5 ( ! ( F_12 ( V_177 -> V_161 ) & V_162 ) ) ;
V_50 = F_85 ( V_71 , V_3 , V_51 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_85 ( V_71 , V_3 , V_116 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_82 ( V_71 , V_73 , 1 , & V_81 ,
& V_79 , & V_80 ,
& V_29 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_77 = F_83 ( V_6 , V_29 ) ;
if ( V_77 == NULL ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
F_84 ( V_3 , V_77 ) ;
V_50 = F_85 ( V_71 , V_3 , V_77 ,
V_87 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_176 = (struct V_10 * ) V_77 -> V_12 ;
memset ( V_176 , 0 , V_6 -> V_88 ) ;
strcpy ( ( void * ) V_176 , V_89 ) ;
V_176 -> V_90 = F_86 ( V_73 -> V_91 ) ;
V_176 -> V_92 = F_87 ( V_81 ) ;
V_176 -> V_93 = F_86 ( V_79 ) ;
V_176 -> V_19 = F_88 ( F_13 ( V_6 ) -> V_20 ) ;
V_176 -> V_18 = F_87 ( V_29 ) ;
V_176 -> V_179 = F_87 ( V_51 -> V_13 ) ;
V_176 -> V_161 = F_88 ( V_180 ) ;
V_176 -> V_95 . V_96 =
F_86 ( F_89 ( V_6 ) ) ;
V_176 -> V_54 = V_177 -> V_54 ;
V_50 = F_138 ( V_116 , V_77 , & V_201 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_90 ( V_71 , V_116 ) ;
F_90 ( V_71 , V_77 ) ;
F_109 ( & V_202 , V_3 , V_51 ) ;
F_142 (
( unsigned long long ) V_77 -> V_13 , V_201 ) ;
V_50 = F_143 ( V_71 , & V_202 , V_201 , V_77 -> V_13 ,
1 , 0 , V_73 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_144 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_72 * V_73 )
{
int V_50 ;
struct V_7 * V_203 = NULL ;
if ( V_51 == V_116 ) {
V_50 = F_127 ( V_71 , V_3 , V_51 ,
& V_203 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else {
V_203 = V_116 ;
F_117 ( V_203 ) ;
}
V_50 = F_141 ( V_71 , V_3 , V_51 ,
V_203 , V_73 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_203 ) ;
return V_50 ;
}
static int F_145 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_119 * V_123 )
{
int V_50 = 0 , V_122 ;
T_2 V_201 , V_204 ;
struct V_141 * V_205 = NULL ;
struct V_144 V_145 ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_137 * V_138 ;
if ( ! ( F_12 ( V_11 -> V_161 ) & V_162 ) )
goto V_17;
V_11 = (struct V_10 * ) V_116 -> V_12 ;
V_204 = F_12 ( V_11 -> V_178 ) ;
V_201 = F_11 ( V_123 -> V_126 ) & V_164 ;
if ( V_204 <= V_201 )
goto V_17;
F_109 ( & V_145 , V_3 , V_51 ) ;
V_205 = F_110 ( & V_145 ) ;
if ( ! V_205 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_111 ( V_3 , V_205 , V_204 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_146 ( V_71 , 2 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_85 ( V_71 , V_3 , V_116 ,
V_85 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_147 ( V_71 , V_3 , F_148 ( V_205 ) ,
V_85 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_138 = F_149 ( V_205 ) ;
for ( V_122 = 0 ; V_122 < F_97 ( V_138 -> V_147 ) ; V_122 ++ )
if ( F_12 ( V_138 -> V_148 [ V_122 ] . V_149 ) == V_204 )
break;
F_5 ( V_122 == F_97 ( V_138 -> V_147 ) ) ;
V_138 -> V_148 [ V_122 ] . V_149 = F_88 ( V_201 ) ;
V_11 -> V_178 = F_88 ( V_201 ) ;
F_90 ( V_71 , F_148 ( V_205 ) ) ;
F_90 ( V_71 , V_116 ) ;
V_17:
F_115 ( V_205 ) ;
return V_50 ;
}
static int F_150 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_119 * V_123 ,
int V_121 , int V_172 ,
struct V_72 * V_73 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_174 * V_163 = & V_11 -> V_95 ;
struct V_7 * V_77 = NULL ;
F_5 ( F_12 ( V_11 -> V_161 ) & V_162 ) ;
if ( V_163 -> V_124 == V_163 -> V_96 ) {
T_1 V_117 = F_11 ( V_123 -> V_126 ) ;
T_2 V_118 = F_12 ( V_123 -> V_127 ) ;
V_50 = F_144 ( V_71 , V_3 , V_51 ,
V_116 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_116 ( V_3 , V_51 ,
V_117 , V_118 , NULL , & V_121 ,
& V_77 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_116 = V_77 ;
V_11 = (struct V_10 * ) V_116 -> V_12 ;
V_163 = & V_11 -> V_95 ;
}
V_50 = F_85 ( V_71 , V_3 , V_116 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_121 < F_97 ( V_163 -> V_124 ) )
memmove ( & V_163 -> V_125 [ V_121 + 1 ] ,
& V_163 -> V_125 [ V_121 ] ,
( F_97 ( V_163 -> V_124 ) - V_121 ) *
sizeof( struct V_119 ) ) ;
F_151 (
( unsigned long long ) V_116 -> V_13 , V_121 ,
( unsigned long long ) F_11 ( V_123 -> V_126 ) ,
F_12 ( V_123 -> V_127 ) , F_12 ( V_123 -> V_128 ) ) ;
V_163 -> V_125 [ V_121 ] = * V_123 ;
F_123 ( & V_163 -> V_124 , 1 ) ;
if ( V_172 )
F_124 ( V_11 , V_121 ) ;
F_90 ( V_71 , V_116 ) ;
if ( V_121 == 0 ) {
V_50 = F_145 ( V_71 , V_3 ,
V_51 ,
V_116 , V_123 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_152 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_119 * V_206 ,
int V_121 , int V_172 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 , V_209 ;
T_2 V_118 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_174 * V_163 = & V_11 -> V_95 ;
struct V_119 * V_210 = & V_163 -> V_125 [ V_121 ] ;
struct V_119 * V_211 = NULL ;
struct V_7 * V_77 = NULL ;
F_5 ( F_12 ( V_11 -> V_161 ) & V_162 ) ;
F_153 ( F_11 ( V_210 -> V_126 ) ,
F_12 ( V_210 -> V_127 ) ,
F_12 ( V_210 -> V_128 ) ,
F_11 ( V_206 -> V_126 ) ,
F_12 ( V_206 -> V_127 ) ,
F_12 ( V_206 -> V_128 ) ) ;
if ( ! V_206 -> V_128 &&
( V_206 -> V_126 == V_210 -> V_126 ||
F_11 ( V_206 -> V_126 ) +
F_12 ( V_206 -> V_127 ) ==
F_11 ( V_210 -> V_126 ) + F_12 ( V_210 -> V_127 ) ) )
V_209 = 0 ;
else
V_209 = 1 ;
if ( V_206 -> V_128 &&
( V_206 -> V_126 != V_210 -> V_126 &&
F_11 ( V_206 -> V_126 ) +
F_12 ( V_206 -> V_127 ) !=
F_11 ( V_210 -> V_126 ) + F_12 ( V_210 -> V_127 ) ) )
V_209 ++ ;
if ( F_97 ( V_163 -> V_124 ) + V_209 >
F_97 ( V_163 -> V_96 ) ) {
struct V_119 V_212 ;
T_1 V_117 = F_11 ( V_210 -> V_126 ) ;
V_118 = F_12 ( V_210 -> V_127 ) ;
V_50 = F_144 ( V_71 , V_3 , V_51 ,
V_116 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_116 ( V_3 , V_51 ,
V_117 , V_118 , & V_212 , & V_121 ,
& V_77 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_116 = V_77 ;
V_11 = (struct V_10 * ) V_116 -> V_12 ;
V_163 = & V_11 -> V_95 ;
V_210 = & V_163 -> V_125 [ V_121 ] ;
}
V_50 = F_85 ( V_71 , V_3 , V_116 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_121 != F_97 ( V_163 -> V_124 ) - 1 )
memmove ( & V_163 -> V_125 [ V_121 + 1 + V_209 ] ,
& V_163 -> V_125 [ V_121 + 1 ] ,
( F_97 ( V_163 -> V_124 ) - V_121 - 1 ) *
sizeof( struct V_119 ) ) ;
V_118 = ( F_11 ( V_210 -> V_126 ) +
F_12 ( V_210 -> V_127 ) ) -
( F_11 ( V_206 -> V_126 ) +
F_12 ( V_206 -> V_127 ) ) ;
if ( V_118 ) {
V_211 = & V_163 -> V_125 [ V_121 + V_209 ] ;
memcpy ( V_211 , V_210 , sizeof( struct V_119 ) ) ;
F_154 ( & V_211 -> V_126 ,
F_12 ( V_211 -> V_127 ) - V_118 ) ;
V_211 -> V_127 = F_88 ( V_118 ) ;
}
if ( V_206 -> V_126 != V_210 -> V_126 && V_211 != V_210 ) {
V_118 = F_11 ( V_206 -> V_126 ) -
F_11 ( V_210 -> V_126 ) ;
V_210 -> V_127 = F_88 ( V_118 ) ;
V_121 ++ ;
}
F_123 ( & V_163 -> V_124 , V_209 ) ;
if ( V_206 -> V_128 ) {
V_163 -> V_125 [ V_121 ] = * V_206 ;
F_155 (
( unsigned long long ) V_116 -> V_13 , V_121 ,
( unsigned long long ) F_11 ( V_206 -> V_126 ) ,
F_12 ( V_206 -> V_127 ) ,
F_12 ( V_206 -> V_128 ) ) ;
if ( V_172 )
F_124 ( V_11 , V_121 ) ;
}
F_90 ( V_71 , V_116 ) ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_156 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_117 , T_2 V_118 , int V_172 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 = 0 , V_121 ;
struct V_7 * V_116 = NULL ;
struct V_119 V_123 ;
unsigned int V_213 = 0 ;
F_157 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_117 , V_118 ) ;
while ( V_118 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_117 , V_118 , & V_123 , & V_121 ,
& V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_213 = F_12 ( V_123 . V_127 ) ;
if ( V_123 . V_128 && F_11 ( V_123 . V_126 ) == V_117 &&
V_213 <= V_118 ) {
F_158 (
( unsigned long long ) V_117 , V_213 ,
F_12 ( V_123 . V_128 ) ) ;
V_50 = F_125 ( V_71 , V_3 ,
V_116 , V_121 ,
V_172 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else if ( ! V_123 . V_128 ) {
V_123 . V_128 = F_88 ( 1 ) ;
F_159 (
( unsigned long long ) F_11 ( V_123 . V_126 ) ,
V_213 ) ;
V_50 = F_150 ( V_71 , V_3 , V_51 ,
V_116 ,
& V_123 , V_121 ,
V_172 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else {
V_213 = F_160 ( ( T_1 ) ( V_117 + V_118 ) ,
F_11 ( V_123 . V_126 ) + V_213 ) - V_117 ;
V_123 . V_126 = F_87 ( V_117 ) ;
V_123 . V_127 = F_88 ( V_213 ) ;
F_95 ( & V_123 . V_128 , 1 ) ;
F_161 (
( unsigned long long ) F_11 ( V_123 . V_126 ) ,
V_213 , F_12 ( V_123 . V_128 ) ) ;
V_50 = F_152 ( V_71 , V_3 ,
V_51 , V_116 ,
& V_123 , V_121 , V_172 ,
V_73 , V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_117 += V_213 ;
V_118 -= V_213 ;
F_58 ( V_116 ) ;
V_116 = NULL ;
}
V_17:
F_58 ( V_116 ) ;
return V_50 ;
}
static int F_162 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_144 V_145 ;
F_5 ( V_11 -> V_95 . V_124 ) ;
F_163 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_116 -> V_13 ,
F_12 ( V_11 -> V_178 ) ) ;
F_109 ( & V_145 , V_3 , V_51 ) ;
V_50 = F_164 ( V_71 , & V_145 , F_12 ( V_11 -> V_178 ) ,
1 , V_73 , V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_165 ( V_3 , V_116 ) ;
V_50 = F_166 ( V_208 , V_111 ,
F_97 ( V_11 -> V_90 ) ,
F_11 ( V_11 -> V_92 ) ,
F_11 ( V_11 -> V_18 ) ,
F_97 ( V_11 -> V_93 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_85 ( V_71 , V_3 , V_51 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
F_95 ( & V_11 -> V_182 , - 1 ) ;
if ( ! V_11 -> V_163 . V_147 ) {
F_5 ( V_11 -> V_182 ) ;
F_167 (
( unsigned long long ) V_51 -> V_13 ) ;
V_11 -> V_161 = 0 ;
V_11 -> V_179 = 0 ;
V_11 -> V_178 = 0 ;
memset ( & V_11 -> V_95 , 0 , V_6 -> V_88 -
F_128 ( struct V_10 , V_95 ) ) ;
V_11 -> V_95 . V_96 =
F_86 ( F_89 ( V_6 ) ) ;
}
F_90 ( V_71 , V_51 ) ;
V_17:
return V_50 ;
}
int F_168 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_117 , T_2 V_118 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
return F_156 ( V_71 , V_3 , V_51 ,
V_117 , V_118 , 1 ,
V_73 , V_208 ) ;
}
static int F_169 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_116 ,
int V_121 , T_1 V_117 , unsigned int V_118 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_116 -> V_12 ;
struct V_119 * V_123 = & V_11 -> V_95 . V_125 [ V_121 ] ;
F_5 ( V_117 < F_11 ( V_123 -> V_126 ) ) ;
F_5 ( V_117 + V_118 >
F_11 ( V_123 -> V_126 ) + F_12 ( V_123 -> V_127 ) ) ;
F_170 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_117 , V_118 ) ;
if ( V_117 == F_11 ( V_123 -> V_126 ) &&
V_118 == F_12 ( V_123 -> V_127 ) )
V_50 = F_125 ( V_71 , V_3 ,
V_116 , V_121 , 1 , - 1 ) ;
else {
struct V_119 V_214 = * V_123 ;
V_214 . V_126 = F_87 ( V_117 ) ;
V_214 . V_127 = F_88 ( V_118 ) ;
F_95 ( & V_214 . V_128 , - 1 ) ;
V_50 = F_152 ( V_71 , V_3 ,
V_51 , V_116 ,
& V_214 , V_121 , 1 ,
V_73 , V_208 ) ;
}
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( ! V_11 -> V_95 . V_124 && V_116 != V_51 ) {
V_50 = F_162 ( V_71 , V_3 , V_51 ,
V_116 , V_73 ,
V_208 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_17:
return V_50 ;
}
static int F_171 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_117 , T_2 V_118 ,
struct V_72 * V_73 ,
struct V_207 * V_208 ,
int V_215 )
{
int V_50 = 0 , V_121 = 0 ;
struct V_119 V_123 ;
unsigned int V_216 = 0 , V_217 ;
struct V_5 * V_6 = F_108 ( V_3 ) ;
struct V_7 * V_116 = NULL ;
F_172 (
( unsigned long long ) F_119 ( V_3 ) ,
( unsigned long long ) V_117 , V_118 , V_215 ) ;
while ( V_118 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_117 , V_118 , & V_123 , & V_121 ,
& V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_216 = F_12 ( V_123 . V_128 ) ;
F_5 ( V_216 == 0 ) ;
if ( ! V_215 )
F_5 ( V_216 > 1 ) ;
V_217 = F_160 ( ( T_1 ) ( V_117 + V_118 ) , F_11 ( V_123 . V_126 ) +
F_12 ( V_123 . V_127 ) ) - V_117 ;
V_50 = F_169 ( V_71 , V_3 , V_51 ,
V_116 , V_121 ,
V_117 , V_217 ,
V_73 , V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( F_12 ( V_123 . V_128 ) == 1 && V_215 ) {
V_50 = F_173 ( V_208 ,
F_174 ( V_6 , V_117 ) ,
V_217 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_117 += V_217 ;
V_118 -= V_217 ;
F_58 ( V_116 ) ;
V_116 = NULL ;
}
V_17:
F_58 ( V_116 ) ;
return V_50 ;
}
int F_175 ( struct V_55 * V_55 ,
T_3 * V_71 , T_2 V_117 , T_2 V_118 ,
struct V_72 * V_73 ,
struct V_207 * V_208 ,
int V_215 )
{
int V_50 ;
T_1 V_56 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_59 ( V_55 , & V_56 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_55 ( F_13 ( V_55 -> V_76 ) , V_56 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_14 ( & V_33 -> V_4 , V_33 -> V_18 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_171 ( V_71 , & V_33 -> V_4 , V_51 ,
V_117 , V_118 , V_73 , V_208 , V_215 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_176 ( struct V_55 * V_55 ,
struct V_144 * V_145 ,
T_3 * V_71 , T_2 V_117 ,
T_2 V_118 , T_2 V_218 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 ;
F_177 ( F_61 ( V_55 ) -> V_83 ,
V_117 , V_118 , V_218 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
V_50 = F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_219 ) ;
goto V_17;
}
V_50 = F_178 ( V_71 , V_145 , V_117 ,
V_118 , V_218 , V_73 , V_208 ,
V_220 , 0 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
return V_50 ;
}
static int F_179 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_221 ,
T_2 V_222 ,
int * V_223 ,
int * V_106 )
{
int V_50 = 0 , V_121 , V_224 = 0 , V_225 = 0 ;
T_1 V_117 = V_221 ;
struct V_10 * V_11 ;
struct V_119 V_123 ;
struct V_7 * V_116 = NULL , * V_226 = NULL ;
T_2 V_118 ;
while ( V_222 ) {
V_50 = F_116 ( V_3 , V_51 ,
V_117 , V_222 , & V_123 ,
& V_121 , & V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_116 != V_226 ) {
if ( V_226 ) {
V_11 = (struct V_10 * )
V_226 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_124 ) +
V_225 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_224 ++ ;
}
V_225 = 0 ;
* V_106 += 1 ;
F_58 ( V_226 ) ;
V_226 = V_116 ;
F_117 ( V_226 ) ;
}
F_180 (
V_225 , ( unsigned long long ) V_117 , V_222 ,
( unsigned long long ) F_11 ( V_123 . V_126 ) ,
F_12 ( V_123 . V_127 ) ,
F_12 ( V_123 . V_128 ) , V_121 ) ;
V_118 = F_160 ( ( T_1 ) V_117 + V_222 , F_11 ( V_123 . V_126 ) +
F_12 ( V_123 . V_127 ) ) - V_117 ;
if ( V_123 . V_128 ) {
V_225 += 2 ;
if ( V_117 == V_221 &&
V_117 != F_11 ( V_123 . V_126 ) )
V_225 ++ ;
if ( V_117 + V_222 < F_11 ( V_123 . V_126 ) +
F_12 ( V_123 . V_127 ) )
V_225 ++ ;
} else
V_225 ++ ;
F_58 ( V_116 ) ;
V_116 = NULL ;
V_222 -= V_118 ;
V_117 += V_118 ;
}
if ( V_226 ) {
V_11 = (struct V_10 * ) V_226 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_124 ) + V_225 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_224 ++ ;
* V_106 += 1 ;
}
if ( ! V_224 )
goto V_17;
* V_223 += V_224 ;
* V_106 += V_224 ;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_161 ) & V_162 ) {
struct V_144 V_145 ;
F_109 ( & V_145 , V_3 , V_51 ) ;
* V_223 += F_181 ( V_145 . V_227 ) ;
* V_106 += F_182 ( V_6 ,
V_145 . V_227 ) ;
} else {
* V_106 += V_228 ;
* V_223 += 1 ;
}
V_17:
F_183 (
( unsigned long long ) V_221 , V_222 ,
* V_223 , * V_106 ) ;
F_58 ( V_116 ) ;
F_58 ( V_226 ) ;
return V_50 ;
}
int F_184 ( struct V_55 * V_55 ,
T_1 V_100 ,
T_1 V_229 ,
T_2 V_222 ,
int * V_106 ,
int * V_224 )
{
int V_50 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
T_1 V_221 = F_185 ( V_55 -> V_76 , V_229 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
V_50 = F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_219 ) ;
goto V_17;
}
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_55 ( F_13 ( V_55 -> V_76 ) ,
V_100 , & V_33 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_14 ( & V_33 -> V_4 , V_100 ,
& V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_179 ( V_55 -> V_76 ,
& V_33 -> V_4 ,
V_51 ,
V_221 , V_222 ,
V_224 , V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_186 ( * V_224 , * V_106 ) ;
V_17:
F_58 ( V_51 ) ;
return V_50 ;
}
static inline unsigned int F_187 ( struct V_5 * V_6 )
{
return F_188 ( V_6 , V_230 ) ;
}
static inline unsigned int F_189 ( struct V_5 * V_6 )
{
return ~ ( F_187 ( V_6 ) - 1 ) ;
}
static inline unsigned int F_190 ( struct V_5 * V_6 ,
unsigned int V_231 ,
unsigned int V_117 )
{
F_5 ( V_231 > V_117 ) ;
return V_231 + ( ( V_117 - V_231 ) & F_189 ( V_6 ) ) ;
}
static inline unsigned int F_191 ( struct V_5 * V_6 ,
unsigned int V_118 )
{
unsigned int V_232 =
( V_118 + ( F_187 ( V_6 ) - 1 ) ) &
F_189 ( V_6 ) ;
if ( V_232 < V_118 )
V_232 = V_151 ;
return V_232 ;
}
static int F_192 ( struct V_55 * V_55 ,
struct V_137 * V_138 ,
T_2 V_117 ,
T_2 V_233 ,
T_2 V_234 ,
T_2 * V_235 ,
T_2 * V_236 )
{
int V_50 = 0 ;
int V_237 = F_97 ( V_138 -> V_165 ) , V_122 ;
struct V_7 * V_160 = NULL ;
struct V_135 * V_136 = NULL ;
struct V_159 * V_123 ;
unsigned int V_238 , V_239 = 0 ;
int V_240 = F_187 ( V_55 -> V_76 ) ;
int V_241 ;
F_5 ( V_117 + V_233 > V_234 ) ;
if ( V_237 > 0 ) {
V_50 = F_118 ( F_81 ( V_55 ) , V_138 , V_117 , & V_160 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_136 = (struct V_135 * ) V_160 -> V_12 ;
V_138 = & V_136 -> V_152 ;
if ( V_138 -> V_165 ) {
V_50 = F_10 ( V_55 -> V_76 ,
L_8 ,
V_55 -> V_219 ,
( unsigned long long ) V_160 -> V_13 ) ;
goto V_17;
}
}
* V_236 = 0 ;
for ( V_122 = 0 ; V_122 < F_97 ( V_138 -> V_147 ) ; V_122 ++ ) {
V_123 = & V_138 -> V_148 [ V_122 ] ;
if ( F_193 ( V_123 ) ) {
F_194 ( V_122 != 0 , L_9
L_10 , V_55 -> V_219 , V_122 ) ;
continue;
}
if ( F_12 ( V_123 -> V_149 ) +
F_97 ( V_123 -> V_183 ) <= V_117 )
continue;
if ( * V_236 == 0 ) {
F_5 ( ! ( V_123 -> V_242 & V_220 ) ) ;
* V_235 = F_12 ( V_123 -> V_149 ) ;
}
if ( ( ! ( V_123 -> V_242 & V_220 ) ) ||
( * V_236 && V_239 != F_12 ( V_123 -> V_149 ) ) ||
( V_234 <= F_12 ( V_123 -> V_149 ) ) )
break;
V_241 = F_97 ( V_123 -> V_183 ) ;
V_239 = F_12 ( V_123 -> V_149 ) + V_241 ;
if ( V_239 > V_234 ) {
V_239 = V_234 ;
V_241 = V_239 - F_12 ( V_123 -> V_149 ) ;
}
if ( ! * V_236 )
V_238 = V_233 ;
else
V_238 = ( V_117 + V_233 ) -
( * V_235 + * V_236 ) ;
if ( V_238 < V_240 )
V_238 = V_240 ;
if ( V_241 <= V_240 )
* V_236 += V_241 ;
else if ( * V_236 || ( * V_235 == V_117 ) ) {
V_238 = F_191 ( V_55 -> V_76 ,
V_238 ) ;
if ( V_241 < V_238 )
* V_236 += V_241 ;
else
* V_236 += V_238 ;
} else if ( ( * V_235 + V_240 ) >=
( V_117 + V_233 ) ) {
* V_236 = V_240 ;
} else if ( ( V_239 - V_117 ) <= V_240 ) {
* V_235 = V_239 - V_240 ;
* V_236 = V_240 ;
} else if ( ( V_239 - V_117 ) <= V_238 ) {
* V_235 = F_190 ( V_55 -> V_76 ,
* V_235 , V_117 ) ;
* V_236 = V_239 - * V_235 ;
} else {
* V_235 = F_190 ( V_55 -> V_76 ,
* V_235 , V_117 ) ;
V_238 = ( V_117 + V_233 ) - * V_235 ;
V_238 = F_191 ( V_55 -> V_76 ,
V_238 ) ;
if ( * V_235 + V_238 <= V_239 )
* V_236 = V_238 ;
else
* V_236 = V_239 - * V_235 ;
}
if ( ( * V_235 + * V_236 ) >= ( V_117 + V_233 ) )
break;
if ( V_122 + 1 == F_97 ( V_138 -> V_147 ) &&
V_136 && V_136 -> V_150 ) {
F_58 ( V_160 ) ;
V_160 = NULL ;
V_50 = F_195 ( F_81 ( V_55 ) ,
F_11 ( V_136 -> V_150 ) ,
& V_160 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_136 = (struct V_135 * ) V_160 -> V_12 ;
V_138 = & V_136 -> V_152 ;
V_122 = - 1 ;
}
}
V_17:
F_58 ( V_160 ) ;
return V_50 ;
}
static int F_196 ( struct V_5 * V_6 ,
T_2 V_243 , T_2 V_244 ,
struct V_144 * V_145 ,
struct V_2 * V_245 ,
struct V_7 * V_51 ,
struct V_72 * * V_73 ,
struct V_72 * * V_246 ,
int * V_106 )
{
int V_50 = 0 , V_223 = 0 ;
int V_247 = F_197 ( F_13 ( V_6 ) , V_145 ) ;
if ( V_247 < 0 ) {
V_50 = V_247 ;
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_247 < V_244 + 2 )
V_223 =
F_181 ( V_145 -> V_227 ) ;
* V_106 += F_182 ( V_6 , V_145 -> V_227 ) ;
V_50 = F_179 ( V_6 , V_245 , V_51 ,
V_243 , V_244 ,
& V_223 , V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_198 ( V_223 , * V_106 ) ;
V_50 = F_76 ( F_13 ( V_6 ) , V_223 ,
V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_246 ) {
V_50 = F_199 ( F_13 ( V_6 ) , V_244 ,
V_246 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_17:
if ( V_50 ) {
if ( * V_73 ) {
F_93 ( * V_73 ) ;
* V_73 = NULL ;
}
}
return V_50 ;
}
static int F_200 ( T_3 * V_71 , struct V_7 * V_8 )
{
F_5 ( F_201 ( V_8 ) ) ;
F_202 ( V_8 ) ;
return 0 ;
}
int F_203 ( T_3 * V_71 ,
struct V_55 * V_55 ,
T_2 V_117 , T_2 V_248 ,
T_2 V_249 , T_2 V_250 )
{
int V_50 = 0 , V_251 ;
struct V_5 * V_6 = V_55 -> V_76 ;
T_1 V_252 = F_174 ( V_6 , V_249 ) ;
struct V_253 * V_253 ;
T_5 V_254 ;
unsigned int V_255 , V_256 ;
T_6 V_257 , V_258 , V_259 ;
struct V_260 * V_261 = V_55 -> V_262 ;
F_204 ( V_117 , V_248 ,
V_249 , V_250 ) ;
V_257 = ( ( T_6 ) V_117 ) << F_13 ( V_6 ) -> V_263 ;
V_258 = V_257 + ( V_250 << F_13 ( V_6 ) -> V_263 ) ;
if ( V_258 > F_205 ( V_55 ) )
V_258 = F_205 ( V_55 ) ;
while ( V_257 < V_258 ) {
V_254 = V_257 >> V_264 ;
V_259 = ( ( T_6 ) V_254 + 1 ) << V_264 ;
if ( V_259 > V_258 )
V_259 = V_258 ;
V_255 = V_257 & ( V_265 - 1 ) ;
V_256 = V_265 ;
if ( V_259 & ( V_265 - 1 ) )
V_256 = V_259 & ( V_265 - 1 ) ;
V_253 = F_206 ( V_261 , V_254 , V_48 ) ;
if ( ! V_253 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
break;
}
if ( V_265 <= F_13 ( V_6 ) -> V_266 )
F_5 ( F_207 ( V_253 ) ) ;
if ( ! F_208 ( V_253 ) ) {
V_50 = F_209 ( V_253 , V_267 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_268;
}
F_210 ( V_253 ) ;
}
if ( F_211 ( V_253 ) ) {
V_50 = F_212 ( V_71 , F_213 ( V_253 ) ,
V_255 , V_256 , & V_251 ,
F_200 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_268;
}
}
F_214 ( V_55 ,
V_71 , V_255 , V_256 ,
V_253 , 0 , & V_252 ) ;
F_215 ( V_253 ) ;
V_268:
F_216 ( V_253 ) ;
F_217 ( V_253 ) ;
V_253 = NULL ;
V_257 = V_259 ;
if ( V_50 )
break;
}
return V_50 ;
}
int F_218 ( T_3 * V_71 ,
struct V_55 * V_55 ,
T_2 V_117 , T_2 V_248 ,
T_2 V_249 , T_2 V_250 )
{
int V_50 = 0 ;
struct V_5 * V_6 = V_55 -> V_76 ;
struct V_2 * V_3 = F_81 ( V_55 ) ;
int V_122 , V_269 = F_174 ( V_6 , V_250 ) ;
T_1 V_270 = F_174 ( V_6 , V_248 ) ;
T_1 V_252 = F_174 ( V_6 , V_249 ) ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
struct V_7 * V_271 = NULL ;
struct V_7 * V_77 = NULL ;
F_204 ( V_117 , V_248 ,
V_249 , V_250 ) ;
for ( V_122 = 0 ; V_122 < V_269 ; V_122 ++ , V_270 ++ , V_252 ++ ) {
V_77 = F_83 ( V_28 -> V_6 , V_252 ) ;
if ( V_77 == NULL ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
break;
}
F_84 ( V_3 , V_77 ) ;
V_50 = F_15 ( V_3 , V_270 , & V_271 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_50 = F_219 ( V_71 , V_3 , V_77 ,
V_87 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
memcpy ( V_77 -> V_12 , V_271 -> V_12 , V_6 -> V_88 ) ;
F_90 ( V_71 , V_77 ) ;
F_58 ( V_77 ) ;
F_58 ( V_271 ) ;
V_77 = NULL ;
V_271 = NULL ;
}
F_58 ( V_77 ) ;
F_58 ( V_271 ) ;
return V_50 ;
}
static int F_220 ( T_3 * V_71 ,
struct V_144 * V_145 ,
T_2 V_117 , T_2 V_243 , T_2 V_118 ,
unsigned int V_272 ,
struct V_72 * V_73 ,
struct V_207 * V_208 )
{
int V_50 , V_121 ;
struct V_159 V_273 ;
struct V_141 * V_205 = NULL ;
struct V_137 * V_138 ;
struct V_5 * V_6 = F_108 ( V_145 -> V_274 ) ;
T_1 V_275 = F_119 ( V_145 -> V_274 ) ;
F_221 ( ( unsigned long long ) V_275 ,
V_117 , V_118 , V_243 , V_272 ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_149 = F_88 ( V_117 ) ;
V_273 . V_183 = F_86 ( V_118 ) ;
V_273 . V_154 = F_87 ( F_174 ( V_6 ,
V_243 ) ) ;
V_273 . V_242 = V_272 ;
V_273 . V_242 &= ~ V_220 ;
V_205 = F_110 ( V_145 ) ;
if ( ! V_205 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_111 ( V_145 -> V_274 , V_205 , V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_138 = F_149 ( V_205 ) ;
V_121 = F_222 ( V_138 , V_117 ) ;
if ( V_121 == - 1 ) {
V_50 = F_10 ( V_6 ,
L_11 ,
( unsigned long long ) V_275 , V_117 ) ;
goto V_17;
}
V_50 = F_223 ( V_71 , V_145 , V_205 , V_121 ,
& V_273 , V_73 , V_208 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_115 ( V_205 ) ;
return V_50 ;
}
static int F_224 ( T_3 * V_71 ,
struct V_276 * V_277 ,
T_2 V_117 , T_2 V_278 ,
T_2 V_37 , T_2 V_118 ,
unsigned int V_272 )
{
int V_50 ;
struct V_2 * V_3 = V_277 -> V_279 . V_274 ;
T_1 V_275 = F_119 ( V_3 ) ;
F_225 ( ( unsigned long long ) V_275 ,
V_117 , V_278 , V_37 , V_118 , V_272 ) ;
if ( ! ( V_272 & V_280 ) ) {
V_50 = V_277 -> V_281 ( V_71 , V_277 -> V_55 ,
V_117 , V_278 , V_37 , V_118 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_50 = F_220 ( V_71 , & V_277 -> V_279 ,
V_117 , V_37 , V_118 , V_272 ,
V_277 -> V_73 , & V_277 -> V_208 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
return V_50 ;
}
int F_226 ( struct V_5 * V_6 ,
struct V_55 * V_55 ,
T_2 V_117 , T_2 V_244 )
{
int V_50 = 0 ;
T_6 V_257 , V_258 , V_259 ;
T_5 V_254 ;
struct V_253 * V_253 ;
if ( F_227 ( V_55 ) )
return 0 ;
V_257 = ( ( T_6 ) V_117 ) << F_13 ( V_6 ) -> V_263 ;
V_258 = V_257 + ( V_244 << F_13 ( V_6 ) -> V_263 ) ;
V_50 = F_228 ( V_55 -> V_262 ,
V_257 , V_258 - 1 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
while ( V_257 < V_258 ) {
V_254 = V_257 >> V_264 ;
V_259 = ( ( T_6 ) V_254 + 1 ) << V_264 ;
if ( V_259 > V_258 )
V_259 = V_258 ;
V_253 = F_206 ( V_55 -> V_262 ,
V_254 , V_48 ) ;
F_5 ( ! V_253 ) ;
F_229 ( V_253 ) ;
if ( F_230 ( V_253 ) ) {
V_50 = - V_282 ;
F_56 ( V_50 ) ;
} else
F_215 ( V_253 ) ;
F_216 ( V_253 ) ;
F_217 ( V_253 ) ;
V_253 = NULL ;
V_257 = V_259 ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_231 ( struct V_276 * V_277 ,
T_2 V_283 , T_2 * V_243 ,
T_2 * V_244 ,
unsigned int * V_284 )
{
return F_232 ( V_277 -> V_55 , V_283 , V_243 ,
V_244 , V_284 ) ;
}
static int F_233 ( struct V_5 * V_6 ,
struct V_276 * V_277 ,
T_2 V_117 , T_2 V_243 ,
T_2 V_244 , unsigned int V_242 )
{
int V_50 , V_215 , V_121 , V_106 = 0 ;
T_2 V_285 , V_250 , V_286 ;
unsigned int V_213 ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
T_3 * V_71 ;
struct V_7 * V_116 = NULL ;
struct V_2 * V_245 = & V_277 -> V_101 -> V_4 ;
struct V_119 V_123 ;
F_234 ( V_117 , V_243 ,
V_244 , V_242 ) ;
V_50 = F_196 ( V_6 , V_243 , V_244 ,
& V_277 -> V_279 ,
V_245 ,
V_277 -> V_51 ,
& V_277 -> V_73 ,
& V_277 -> V_246 , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
if ( V_277 -> V_287 )
V_106 += V_277 -> V_287 -> V_106 ;
V_106 += V_277 -> V_288 ;
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_286 = V_244 ;
while ( V_244 ) {
V_50 = F_116 ( V_245 , V_277 -> V_51 ,
V_243 , V_244 ,
& V_123 , & V_121 , & V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
F_5 ( ! V_123 . V_128 ) ;
V_213 = F_160 ( ( T_1 ) V_243 + V_244 ,
F_11 ( V_123 . V_126 ) +
F_12 ( V_123 . V_127 ) ) - V_243 ;
if ( F_12 ( V_123 . V_128 ) == 1 ) {
V_215 = 0 ;
V_50 = F_220 ( V_71 ,
& V_277 -> V_279 ,
V_117 , V_243 ,
V_213 , V_242 ,
V_277 -> V_73 ,
& V_277 -> V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
} else {
V_215 = 1 ;
V_50 = F_235 ( V_71 ,
V_277 -> V_246 ,
1 , V_213 ,
& V_285 , & V_250 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_224 ( V_71 , V_277 ,
V_117 , V_243 , V_285 ,
V_250 , V_242 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_213 = V_250 ;
}
V_50 = F_171 ( V_71 , V_245 ,
V_277 -> V_51 ,
V_243 , V_213 ,
V_277 -> V_73 ,
& V_277 -> V_208 , V_215 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_117 += V_213 ;
V_243 += V_213 ;
V_244 -= V_213 ;
F_58 ( V_116 ) ;
V_116 = NULL ;
}
if ( V_277 -> V_287 && V_277 -> V_287 -> V_289 ) {
V_50 = V_277 -> V_287 -> V_289 ( V_277 -> V_55 , V_71 ,
V_277 -> V_287 -> V_290 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
}
if ( V_277 -> V_291 == F_231 ) {
V_50 = F_226 ( V_6 , V_277 -> V_55 , V_117 ,
V_286 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_277 -> V_246 ) {
F_93 ( V_277 -> V_246 ) ;
V_277 -> V_246 = NULL ;
}
if ( V_277 -> V_73 ) {
F_93 ( V_277 -> V_73 ) ;
V_277 -> V_73 = NULL ;
}
F_58 ( V_116 ) ;
return V_50 ;
}
static int F_236 ( struct V_276 * V_277 )
{
int V_50 = 0 ;
struct V_55 * V_55 = V_277 -> V_55 ;
T_2 V_235 = V_277 -> V_235 , V_236 = V_277 -> V_236 ;
T_2 V_243 , V_244 ;
unsigned int V_272 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
return F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_219 ) ;
}
F_237 ( & V_277 -> V_208 ) ;
while ( V_236 ) {
V_50 = V_277 -> V_291 ( V_277 , V_235 , & V_243 ,
& V_244 , & V_272 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
F_5 ( ! ( V_272 & V_220 ) ) ;
if ( V_236 < V_244 )
V_244 = V_236 ;
V_50 = F_233 ( V_55 -> V_76 , V_277 ,
V_235 , V_243 ,
V_244 , V_272 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_236 -= V_244 ;
V_235 += V_244 ;
}
if ( F_238 ( & V_277 -> V_208 ) ) {
F_239 ( V_28 , 1 ) ;
F_240 ( V_28 , & V_277 -> V_208 ) ;
}
return V_50 ;
}
static int F_241 ( struct V_55 * V_55 ,
struct V_7 * V_57 ,
T_2 V_117 , T_2 V_233 , T_2 V_234 )
{
int V_50 ;
T_2 V_235 = 0 , V_236 = 0 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_101 ;
struct V_276 * V_277 = NULL ;
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_192 ( V_55 , & V_59 -> V_292 . V_293 ,
V_117 , V_233 , V_234 ,
& V_235 , & V_236 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_242 ( F_61 ( V_55 ) -> V_83 ,
V_117 , V_233 , V_234 ,
V_235 , V_236 ) ;
F_5 ( V_236 == 0 ) ;
V_277 = F_53 ( sizeof( struct V_276 ) , V_48 ) ;
if ( ! V_277 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_66 ( V_28 , F_11 ( V_59 -> V_62 ) ,
1 , & V_101 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_277 -> V_55 = V_55 ;
V_277 -> V_235 = V_235 ;
V_277 -> V_236 = V_236 ;
V_277 -> V_101 = V_101 ;
V_277 -> V_51 = V_51 ;
V_277 -> V_281 = F_203 ;
V_277 -> V_291 = F_231 ;
F_243 ( & V_277 -> V_279 ,
F_81 ( V_55 ) , V_57 ) ;
V_50 = F_236 ( V_277 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
F_244 ( V_55 , V_235 ) ;
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
V_17:
F_36 ( V_277 ) ;
return V_50 ;
}
int F_245 ( struct V_55 * V_55 ,
struct V_7 * V_57 ,
T_2 V_117 , T_2 V_233 , T_2 V_234 )
{
int V_50 = 0 ;
T_2 V_243 , V_244 ;
unsigned int V_272 ;
while ( V_233 ) {
V_50 = F_232 ( V_55 , V_117 , & V_243 ,
& V_244 , & V_272 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
if ( V_233 < V_244 )
V_244 = V_233 ;
if ( V_272 & V_220 ) {
V_50 = F_241 ( V_55 , V_57 , V_117 ,
V_244 , V_234 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
}
V_233 -= V_244 ;
V_117 += V_244 ;
}
return V_50 ;
}
static int F_246 ( struct V_276 * V_277 ,
T_2 V_283 , T_2 * V_243 ,
T_2 * V_244 ,
unsigned int * V_284 )
{
struct V_55 * V_55 = V_277 -> V_55 ;
struct V_294 * V_295 = V_277 -> V_296 ;
return F_247 ( V_55 , V_283 , V_243 ,
V_244 , & V_295 -> V_297 ,
V_284 ) ;
}
int F_248 ( struct V_55 * V_55 ,
struct V_2 * V_245 ,
struct V_7 * V_51 ,
struct V_294 * V_295 ,
int * V_223 , int * V_106 )
{
int V_50 = 0 , V_121 , V_224 = 0 ;
T_2 V_243 , V_244 ;
T_2 V_117 = 0 , V_222 = F_12 ( V_295 -> V_298 ) ;
struct V_10 * V_11 ;
struct V_119 V_123 ;
struct V_7 * V_116 = NULL ;
while ( V_117 < V_222 ) {
V_50 = F_247 ( V_55 , V_117 , & V_243 ,
& V_244 , & V_295 -> V_297 ,
NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_117 += V_244 ;
while ( V_244 ) {
V_50 = F_116 ( V_245 , V_51 ,
V_243 , V_244 ,
& V_123 , & V_121 ,
& V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_5 ( ! V_123 . V_128 ) ;
V_11 = (struct V_10 * ) V_116 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_124 ) + V_222 * 2 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_224 ++ ;
* V_106 += 1 ;
F_58 ( V_116 ) ;
V_116 = NULL ;
if ( V_244 <= F_12 ( V_123 . V_127 ) )
break;
else
V_244 -= F_12 ( V_123 . V_127 ) ;
V_243 += V_244 ;
}
}
* V_223 += V_224 ;
if ( ! V_224 )
goto V_17;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_161 ) & V_162 )
* V_106 += V_228 ;
else {
struct V_144 V_145 ;
F_109 ( & V_145 , V_245 , V_51 ) ;
* V_106 += F_182 ( V_55 -> V_76 ,
V_145 . V_227 ) ;
}
V_17:
F_58 ( V_116 ) ;
return V_50 ;
}
int F_249 ( struct V_55 * V_55 ,
struct V_58 * V_59 ,
struct V_299 * V_300 ,
struct V_1 * V_101 ,
struct V_7 * V_51 ,
T_2 V_117 , T_2 V_233 ,
struct V_301 * V_302 )
{
int V_50 ;
struct V_294 * V_295 = V_300 -> V_303 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_276 * V_277 = NULL ;
T_2 V_235 , V_236 ;
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_192 ( V_55 , & V_295 -> V_297 ,
V_117 , V_233 , V_151 ,
& V_235 , & V_236 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_5 ( V_236 == 0 ) ;
V_277 = F_53 ( sizeof( struct V_276 ) , V_48 ) ;
if ( ! V_277 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_277 -> V_55 = V_55 ;
V_277 -> V_235 = V_235 ;
V_277 -> V_236 = V_236 ;
V_277 -> V_101 = V_101 ;
V_277 -> V_51 = V_51 ;
V_277 -> V_296 = V_295 ;
V_277 -> V_281 = F_218 ;
V_277 -> V_288 =
F_174 ( V_55 -> V_76 , 1 ) * V_236 ;
V_277 -> V_291 = F_246 ;
V_277 -> V_287 = V_302 ;
F_250 ( & V_277 -> V_279 ,
F_81 ( V_55 ) , V_300 ) ;
V_50 = F_236 ( V_277 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_36 ( V_277 ) ;
return V_50 ;
}
int F_251 ( struct V_55 * V_55 ,
struct V_144 * V_279 ,
struct V_2 * V_245 ,
struct V_7 * V_51 ,
T_2 V_117 , T_2 V_243 , T_2 V_244 ,
struct V_207 * V_208 ,
struct V_301 * V_302 )
{
int V_50 ;
T_3 * V_71 ;
int V_106 = 1 , V_224 = 0 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_72 * V_73 = NULL ;
V_50 = F_179 ( V_55 -> V_76 ,
V_245 , V_51 ,
V_243 , V_244 ,
& V_224 , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_252 ( V_224 , V_106 ) ;
if ( V_224 ) {
V_50 = F_76 ( F_13 ( V_55 -> V_76 ) ,
V_224 , & V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
if ( V_302 )
V_106 += V_302 -> V_106 ;
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_176 ( V_55 , V_279 , V_71 ,
V_117 , V_244 , V_243 ,
V_73 , V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_156 ( V_71 , V_245 , V_51 ,
V_243 , V_244 , 0 ,
V_73 , V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
if ( V_302 && V_302 -> V_289 ) {
V_50 = V_302 -> V_289 ( V_55 , V_71 , V_302 -> V_290 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_73 )
F_93 ( V_73 ) ;
return V_50 ;
}
static int F_253 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 ;
T_3 * V_71 ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
V_71 = F_77 ( F_13 ( V_55 -> V_76 ) ,
V_304 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_80 ( V_71 , F_81 ( V_55 ) , V_57 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_55 -> V_305 = V_306 ;
V_59 -> V_305 = F_87 ( V_55 -> V_305 . V_307 ) ;
V_59 -> V_308 = F_88 ( V_55 -> V_305 . V_309 ) ;
F_90 ( V_71 , V_57 ) ;
V_86:
F_92 ( F_13 ( V_55 -> V_76 ) , V_71 ) ;
V_17:
return V_50 ;
}
static int F_254 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 , V_310 = 0 ;
struct V_7 * V_51 = NULL ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_1 * V_101 ;
unsigned int V_272 ;
T_6 V_191 ;
T_2 V_117 , V_244 , V_222 , V_243 ;
struct V_207 V_208 ;
struct V_144 V_311 ;
F_237 ( & V_208 ) ;
if ( ! ( V_75 -> V_60 & V_61 ) ) {
V_50 = F_74 ( V_55 , V_57 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
F_5 ( ! V_59 -> V_62 ) ;
V_50 = F_66 ( V_28 ,
F_11 ( V_59 -> V_62 ) , 1 ,
& V_101 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_75 -> V_60 & V_312 )
goto V_313;
F_243 ( & V_311 , F_81 ( V_55 ) , V_57 ) ;
V_191 = F_205 ( V_55 ) ;
V_222 = F_188 ( V_55 -> V_76 , V_191 ) ;
V_117 = 0 ;
while ( V_117 < V_222 ) {
V_50 = F_232 ( V_55 , V_117 , & V_243 ,
& V_244 , & V_272 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_268;
}
if ( V_243 && ! ( V_272 & V_220 ) ) {
V_50 = F_251 ( V_55 , & V_311 ,
& V_101 -> V_4 ,
V_51 , V_117 ,
V_243 , V_244 ,
& V_208 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_268;
}
V_310 = 1 ;
}
V_117 += V_244 ;
}
V_313:
if ( V_75 -> V_60 & V_132 ) {
V_50 = F_255 ( V_55 , V_57 ,
& V_101 -> V_4 ,
V_51 ,
& V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_268;
}
}
if ( V_310 ) {
V_50 = F_253 ( V_55 , V_57 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_268:
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
if ( ! V_50 && F_238 ( & V_208 ) ) {
F_239 ( V_28 , 1 ) ;
F_240 ( V_28 , & V_208 ) ;
}
V_17:
F_244 ( V_55 , 0 ) ;
return V_50 ;
}
static int F_256 ( struct V_55 * V_55 ,
struct V_144 * V_145 ,
struct V_2 * V_245 ,
struct V_7 * V_51 ,
T_2 V_117 , T_2 V_243 , T_2 V_244 ,
unsigned int V_272 ,
struct V_207 * V_208 )
{
int V_50 ;
T_3 * V_71 ;
int V_106 = 0 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_72 * V_73 = NULL ;
V_50 = F_196 ( V_55 -> V_76 ,
V_243 , V_244 ,
V_145 , V_245 ,
V_51 , & V_73 ,
NULL , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_143 ( V_71 , V_145 , V_117 ,
F_174 ( V_55 -> V_76 , V_243 ) ,
V_244 , V_272 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_168 ( V_71 , V_245 , V_51 ,
V_243 , V_244 ,
V_73 , V_208 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_73 )
F_93 ( V_73 ) ;
return V_50 ;
}
static int F_257 ( struct V_55 * V_314 ,
struct V_7 * V_315 ,
struct V_55 * V_316 ,
struct V_7 * V_317 )
{
int V_50 ;
T_3 * V_71 ;
struct V_27 * V_28 = F_13 ( V_314 -> V_76 ) ;
struct V_58 * V_318 = (struct V_58 * ) V_315 -> V_12 ;
struct V_58 * V_319 = (struct V_58 * ) V_317 -> V_12 ;
F_5 ( ! ( F_61 ( V_314 ) -> V_60 & V_312 ) ) ;
V_71 = F_77 ( V_28 , V_304 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_80 ( V_71 , F_81 ( V_316 ) , V_317 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_319 -> V_292 . V_320 . V_321 = V_318 -> V_292 . V_320 . V_321 ;
memcpy ( V_319 -> V_292 . V_320 . V_322 , V_318 -> V_292 . V_320 . V_322 ,
F_97 ( V_318 -> V_292 . V_320 . V_321 ) ) ;
F_19 ( & F_61 ( V_316 ) -> V_98 ) ;
F_61 ( V_316 ) -> V_60 |= V_312 ;
V_319 -> V_99 = F_86 ( F_61 ( V_316 ) -> V_60 ) ;
F_21 ( & F_61 ( V_316 ) -> V_98 ) ;
F_90 ( V_71 , V_317 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
return V_50 ;
}
static int F_258 ( struct V_55 * V_314 ,
struct V_55 * V_316 ,
struct V_7 * V_317 ,
struct V_2 * V_245 ,
struct V_7 * V_51 ,
struct V_207 * V_208 )
{
int V_50 = 0 ;
T_2 V_243 , V_244 , V_222 , V_117 ;
T_6 V_191 ;
unsigned int V_272 ;
struct V_144 V_145 ;
F_243 ( & V_145 , F_81 ( V_316 ) , V_317 ) ;
V_191 = F_205 ( V_314 ) ;
V_222 = F_188 ( V_314 -> V_76 , V_191 ) ;
V_117 = 0 ;
while ( V_117 < V_222 ) {
V_50 = F_232 ( V_314 , V_117 , & V_243 ,
& V_244 , & V_272 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_243 ) {
V_50 = F_256 ( V_316 , & V_145 ,
V_245 , V_51 ,
V_117 , V_243 ,
V_244 ,
V_272 ,
V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_117 += V_244 ;
}
V_17:
return V_50 ;
}
static int F_259 ( struct V_55 * V_314 ,
struct V_7 * V_315 ,
struct V_55 * V_316 ,
struct V_7 * V_317 ,
bool V_323 )
{
int V_50 ;
T_3 * V_71 ;
struct V_58 * V_318 = (struct V_58 * ) V_315 -> V_12 ;
struct V_58 * V_59 = (struct V_58 * ) V_317 -> V_12 ;
T_6 V_191 = F_205 ( V_314 ) ;
V_71 = F_77 ( F_13 ( V_316 -> V_76 ) ,
V_304 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
return V_50 ;
}
V_50 = F_80 ( V_71 , F_81 ( V_316 ) , V_317 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
F_19 ( & F_61 ( V_316 ) -> V_98 ) ;
F_61 ( V_316 ) -> V_131 = F_61 ( V_314 ) -> V_131 ;
F_61 ( V_316 ) -> V_324 = F_61 ( V_314 ) -> V_324 ;
F_61 ( V_316 ) -> V_60 = F_61 ( V_314 ) -> V_60 ;
F_21 ( & F_61 ( V_316 ) -> V_98 ) ;
F_260 ( V_316 , V_191 ) ;
V_316 -> V_325 = V_314 -> V_325 ;
V_59 -> V_326 = V_318 -> V_326 ;
V_59 -> V_327 = V_318 -> V_327 ;
V_59 -> V_328 = V_318 -> V_328 ;
V_59 -> V_99 = V_318 -> V_99 ;
V_59 -> V_329 = V_318 -> V_329 ;
if ( V_323 ) {
V_316 -> V_330 = V_314 -> V_330 ;
V_316 -> V_331 = V_314 -> V_331 ;
V_316 -> V_332 = V_314 -> V_332 ;
V_59 -> V_330 = V_318 -> V_330 ;
V_59 -> V_331 = V_318 -> V_331 ;
V_59 -> V_332 = V_318 -> V_332 ;
V_316 -> V_305 = V_306 ;
V_59 -> V_305 = F_87 ( V_316 -> V_305 . V_307 ) ;
V_59 -> V_308 = F_88 ( V_316 -> V_305 . V_309 ) ;
V_316 -> V_333 = V_314 -> V_333 ;
V_59 -> V_333 = V_318 -> V_333 ;
V_59 -> V_334 = V_318 -> V_334 ;
}
F_90 ( V_71 , V_317 ) ;
V_86:
F_92 ( F_13 ( V_316 -> V_76 ) , V_71 ) ;
return V_50 ;
}
static int F_261 ( struct V_55 * V_314 ,
struct V_7 * V_315 ,
struct V_55 * V_316 ,
struct V_7 * V_317 ,
bool V_323 )
{
int V_50 ;
struct V_7 * V_51 = NULL ;
struct V_207 V_208 ;
struct V_27 * V_28 = F_13 ( V_314 -> V_76 ) ;
struct V_10 * V_11 ;
struct V_58 * V_59 = (struct V_58 * ) V_315 -> V_12 ;
struct V_1 * V_101 ;
F_237 ( & V_208 ) ;
V_50 = F_94 ( V_316 , V_317 ,
F_11 ( V_59 -> V_62 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( F_61 ( V_314 ) -> V_60 & V_312 ) {
V_50 = F_257 ( V_314 , V_315 ,
V_316 , V_317 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_66 ( V_28 , F_11 ( V_59 -> V_62 ) ,
1 , & V_101 , & V_51 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_11 = (struct V_10 * ) V_51 -> V_12 ;
V_50 = F_258 ( V_314 , V_316 , V_317 ,
& V_101 -> V_4 , V_51 ,
& V_208 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_335;
}
V_335:
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
V_17:
if ( F_238 ( & V_208 ) ) {
F_239 ( V_28 , 1 ) ;
F_240 ( V_28 , & V_208 ) ;
}
return V_50 ;
}
static int F_262 ( struct V_336 * V_337 ,
struct V_7 * V_271 ,
struct V_55 * V_338 ,
bool V_323 )
{
int V_50 ;
struct V_55 * V_55 = F_263 ( V_337 ) ;
struct V_7 * V_77 = NULL ;
if ( F_61 ( V_55 ) -> V_339 & V_340 ) {
V_50 = - V_341 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_264 ( V_55 -> V_262 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_254 ( V_55 , V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_265 ( & V_338 -> V_112 , V_342 ) ;
V_50 = F_266 ( V_338 , & V_77 , 1 ,
V_343 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_115;
}
V_50 = F_261 ( V_55 , V_271 ,
V_338 , V_77 , V_323 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_344;
}
if ( F_61 ( V_55 ) -> V_60 & V_132 ) {
V_50 = F_267 ( V_55 , V_271 ,
V_338 , V_77 ,
V_323 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_344;
}
}
V_50 = F_259 ( V_55 , V_271 ,
V_338 , V_77 , V_323 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_344:
F_102 ( V_338 , 1 ) ;
F_58 ( V_77 ) ;
V_115:
F_25 ( & V_338 -> V_112 ) ;
V_17:
if ( ! V_50 ) {
V_50 = F_268 ( V_55 -> V_262 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
return V_50 ;
}
static int F_269 ( struct V_336 * V_337 , struct V_55 * V_345 ,
struct V_336 * V_346 , bool V_323 )
{
int error ;
struct V_55 * V_55 = F_263 ( V_337 ) ;
struct V_7 * V_271 = NULL ;
struct V_55 * V_347 = NULL ;
struct V_348 * V_349 , * V_350 ;
T_7 V_351 ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) )
return - V_352 ;
V_351 = V_55 -> V_332 ;
error = F_270 ( V_345 , & V_351 , & V_349 , & V_350 ) ;
if ( error ) {
F_56 ( error ) ;
return error ;
}
error = F_271 ( V_345 , V_351 ,
& V_347 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
error = F_272 ( V_55 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
error = F_100 ( V_55 , & V_271 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
F_273 ( V_55 , 1 ) ;
goto V_17;
}
F_64 ( & F_61 ( V_55 ) -> V_129 ) ;
F_64 ( & F_61 ( V_55 ) -> V_130 ) ;
error = F_262 ( V_337 , V_271 ,
V_347 , V_323 ) ;
F_68 ( & F_61 ( V_55 ) -> V_130 ) ;
F_68 ( & F_61 ( V_55 ) -> V_129 ) ;
F_102 ( V_55 , 1 ) ;
F_273 ( V_55 , 1 ) ;
F_58 ( V_271 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
if ( ! V_323 ) {
error = F_274 ( V_345 , V_347 ,
& V_346 -> V_353 ,
V_349 , V_350 ) ;
if ( error )
F_56 ( error ) ;
}
V_17:
if ( V_349 )
F_275 ( V_349 ) ;
if ( V_350 )
F_275 ( V_350 ) ;
if ( ! error ) {
error = F_276 ( V_345 , V_347 ,
V_346 ) ;
if ( error )
F_56 ( error ) ;
}
if ( V_347 ) {
F_277 ( V_347 ) ;
if ( error )
F_103 ( V_347 ) ;
}
return error ;
}
static inline int F_278 ( struct V_55 * V_345 , struct V_336 * V_354 )
{
if ( F_279 ( V_354 ) )
return - V_355 ;
if ( F_280 ( V_345 ) )
return - V_356 ;
return F_281 ( V_345 , V_357 | V_358 ) ;
}
static int F_282 ( struct V_336 * V_337 , struct V_55 * V_345 ,
struct V_336 * V_346 , bool V_323 )
{
struct V_55 * V_55 = F_263 ( V_337 ) ;
int error ;
if ( ! V_55 )
return - V_356 ;
error = F_278 ( V_345 , V_346 ) ;
if ( error )
return error ;
if ( V_345 -> V_76 != V_55 -> V_76 )
return - V_359 ;
if ( F_283 ( V_55 ) || F_284 ( V_55 ) )
return - V_360 ;
if ( ! F_285 ( V_55 -> V_332 ) )
return - V_360 ;
if ( V_323 ) {
if ( ! F_286 ( F_287 () , V_55 -> V_330 ) && ! F_288 ( V_361 ) )
return - V_360 ;
if ( ! F_289 ( V_55 -> V_331 ) && ! F_288 ( V_361 ) )
return - V_360 ;
}
if ( ! V_323 ) {
error = F_281 ( V_55 , V_362 ) ;
if ( error )
return error ;
}
F_23 ( & V_55 -> V_112 ) ;
error = F_290 ( V_345 ) ;
if ( ! error )
error = F_269 ( V_337 , V_345 , V_346 , V_323 ) ;
F_25 ( & V_55 -> V_112 ) ;
if ( ! error )
F_291 ( V_345 , V_346 ) ;
return error ;
}
int F_292 ( struct V_55 * V_55 ,
const char T_8 * V_363 ,
const char T_8 * V_364 ,
bool V_323 )
{
struct V_336 * V_346 ;
struct V_205 V_365 , V_366 ;
int error ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) )
return - V_352 ;
error = F_293 ( V_367 , V_363 , 0 , & V_365 ) ;
if ( error ) {
F_56 ( error ) ;
return error ;
}
V_346 = F_294 ( V_367 , V_364 , & V_366 , 0 ) ;
error = F_79 ( V_346 ) ;
if ( F_78 ( V_346 ) ) {
F_56 ( error ) ;
goto V_17;
}
error = - V_359 ;
if ( V_365 . V_368 != V_366 . V_368 ) {
F_56 ( error ) ;
goto V_369;
}
error = F_282 ( V_365 . V_336 ,
F_263 ( V_366 . V_336 ) ,
V_346 , V_323 ) ;
V_369:
F_295 ( & V_366 , V_346 ) ;
V_17:
F_296 ( & V_365 ) ;
return error ;
}
