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
F_100 ( V_103 ) ;
V_50 = F_101 ( V_103 , & V_104 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_112;
}
V_106 += V_113 ;
}
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_114;
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
V_50 = F_102 ( V_71 , V_103 ,
V_104 , V_110 , V_109 , 1 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_86:
F_92 ( V_28 , V_71 ) ;
V_114:
if ( V_103 ) {
F_103 ( V_103 , 1 ) ;
F_58 ( V_104 ) ;
}
V_112:
if ( V_103 ) {
F_104 ( V_103 ) ;
F_105 ( V_103 ) ;
}
V_17:
F_67 ( V_28 , V_101 , 1 ) ;
if ( V_65 )
F_43 ( V_101 ) ;
F_58 ( V_105 ) ;
return V_50 ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_7 * V_115 ,
T_1 V_116 , unsigned int V_117 ,
struct V_118 * V_119 ,
int * V_120 )
{
int V_121 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_118 * V_122 = NULL ;
for (; V_121 < F_97 ( V_11 -> V_95 . V_123 ) ; V_121 ++ ) {
V_122 = & V_11 -> V_95 . V_124 [ V_121 ] ;
if ( F_11 ( V_122 -> V_125 ) +
F_12 ( V_122 -> V_126 ) <= V_116 )
continue;
else if ( F_11 ( V_122 -> V_125 ) > V_116 )
break;
if ( V_119 )
* V_119 = * V_122 ;
goto V_17;
}
if ( V_119 ) {
V_119 -> V_125 = F_87 ( V_116 ) ;
V_119 -> V_127 = 0 ;
if ( V_121 < F_97 ( V_11 -> V_95 . V_123 ) &&
F_11 ( V_122 -> V_125 ) < V_116 + V_117 )
V_119 -> V_126 =
F_88 ( F_11 ( V_122 -> V_125 ) - V_116 ) ;
else
V_119 -> V_126 = F_88 ( V_117 ) ;
}
V_17:
* V_120 = V_121 ;
}
int F_107 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
F_64 ( & V_75 -> V_128 ) ;
F_64 ( & V_75 -> V_129 ) ;
if ( V_75 -> V_130 )
goto V_17;
if ( ( V_75 -> V_60 & V_131 ) && V_59 -> V_132 )
goto V_17;
if ( V_75 -> V_60 & V_133 &&
F_108 ( V_55 , V_59 ) )
goto V_17;
V_50 = F_96 ( V_55 , V_57 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_68 ( & V_75 -> V_129 ) ;
F_68 ( & V_75 -> V_128 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_134 * V_135 ,
struct V_136 * V_137 ,
int V_120 , T_2 * V_138 )
{
int V_50 , V_121 , V_139 ;
T_2 V_116 ;
T_1 V_29 ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_140 * V_141 = NULL , * V_142 = NULL ;
struct V_143 V_144 ;
struct V_136 * V_145 ;
if ( V_120 < F_97 ( V_137 -> V_146 ) - 1 ) {
* V_138 = F_12 ( V_137 -> V_147 [ V_120 + 1 ] . V_148 ) ;
return 0 ;
}
if ( ! V_135 || ( V_135 && ! V_135 -> V_149 ) ) {
* V_138 = V_150 ;
return 0 ;
}
F_111 ( & V_144 , V_3 , V_51 ) ;
V_141 = F_112 ( & V_144 ) ;
if ( ! V_141 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_116 = F_12 ( V_135 -> V_151 . V_147 [ V_120 ] . V_148 ) ;
V_50 = F_113 ( V_3 , V_141 , V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_142 = F_114 ( V_141 ) ;
if ( ! V_142 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_115 ( V_6 , V_141 , & V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_113 ( V_3 , V_142 , V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_139 = F_116 ( & V_144 , V_141 ,
V_142 ) ;
V_145 = V_141 -> V_152 [ V_139 ] . V_137 ;
V_29 = V_141 -> V_152 [ V_139 + 1 ] . V_8 -> V_13 ;
for ( V_121 = 0 ; V_121 < F_97 ( V_145 -> V_146 ) ; V_121 ++ ) {
if ( F_11 ( V_145 -> V_147 [ V_121 ] . V_153 ) == V_29 ) {
* V_138 = F_12 ( V_145 -> V_147 [ V_121 + 1 ] . V_148 ) ;
break;
}
}
F_5 ( V_121 == F_97 ( V_145 -> V_146 ) ) ;
V_17:
F_117 ( V_141 ) ;
F_117 ( V_142 ) ;
return V_50 ;
}
static int F_118 ( struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_116 , unsigned int V_117 ,
struct V_118 * V_119 ,
int * V_120 ,
struct V_7 * * V_154 )
{
int V_50 = 0 , V_121 , V_155 ;
T_2 V_156 , V_157 ( V_138 ) ;
struct V_136 * V_137 ;
struct V_158 * V_122 = NULL ;
struct V_134 * V_135 = NULL ;
struct V_7 * V_159 = NULL , * V_115 = NULL ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
if ( ! ( F_12 ( V_11 -> V_160 ) & V_161 ) ) {
F_106 ( V_3 , V_51 , V_116 , V_117 ,
V_119 , V_120 ) ;
* V_154 = V_51 ;
F_119 ( V_51 ) ;
return 0 ;
}
V_137 = & V_11 -> V_162 ;
V_156 = V_116 & V_163 ;
if ( V_137 -> V_164 ) {
V_50 = F_120 ( V_3 , V_137 , V_156 , & V_159 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_135 = (struct V_134 * ) V_159 -> V_12 ;
V_137 = & V_135 -> V_151 ;
if ( V_137 -> V_164 ) {
V_50 = F_10 ( V_6 ,
L_6 ,
( unsigned long long ) F_121 ( V_3 ) ,
( unsigned long long ) V_159 -> V_13 ) ;
goto V_17;
}
}
V_155 = 0 ;
for ( V_121 = F_97 ( V_137 -> V_146 ) - 1 ; V_121 >= 0 ; V_121 -- ) {
V_122 = & V_137 -> V_147 [ V_121 ] ;
if ( F_12 ( V_122 -> V_148 ) <= V_156 ) {
V_155 = 1 ;
break;
}
}
if ( V_155 ) {
V_50 = F_109 ( V_3 , V_51 ,
V_135 , V_137 , V_121 , & V_138 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_138 < V_156 + V_117 )
V_117 = V_138 - V_156 ;
}
V_50 = F_14 ( V_3 , F_11 ( V_122 -> V_153 ) ,
& V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_106 ( V_3 , V_115 , V_116 , V_117 ,
V_119 , V_120 ) ;
* V_154 = V_115 ;
V_17:
F_58 ( V_159 ) ;
return V_50 ;
}
static enum V_165
F_122 ( struct V_10 * V_11 ,
int V_120 )
{
if ( ( V_11 -> V_95 . V_124 [ V_120 ] . V_127 ==
V_11 -> V_95 . V_124 [ V_120 + 1 ] . V_127 ) &&
( F_11 ( V_11 -> V_95 . V_124 [ V_120 ] . V_125 ) +
F_12 ( V_11 -> V_95 . V_124 [ V_120 ] . V_126 ) ==
F_11 ( V_11 -> V_95 . V_124 [ V_120 + 1 ] . V_125 ) ) )
return V_166 ;
return V_167 ;
}
static enum V_165
F_123 ( struct V_10 * V_11 ,
int V_120 )
{
enum V_165 V_50 = V_167 ;
if ( V_120 < F_97 ( V_11 -> V_95 . V_123 ) - 1 )
V_50 = F_122 ( V_11 , V_120 ) ;
if ( V_120 > 0 ) {
enum V_165 V_22 ;
V_22 = F_122 ( V_11 , V_120 - 1 ) ;
if ( V_22 == V_166 ) {
if ( V_50 == V_166 )
V_50 = V_168 ;
else
V_50 = V_169 ;
}
}
return V_50 ;
}
static void F_124 ( struct V_10 * V_11 ,
int V_120 )
{
F_5 ( V_11 -> V_95 . V_124 [ V_120 ] . V_127 !=
V_11 -> V_95 . V_124 [ V_120 + 1 ] . V_127 ) ;
F_95 ( & V_11 -> V_95 . V_124 [ V_120 ] . V_126 ,
F_12 ( V_11 -> V_95 . V_124 [ V_120 + 1 ] . V_126 ) ) ;
if ( V_120 < F_97 ( V_11 -> V_95 . V_123 ) - 2 )
memmove ( & V_11 -> V_95 . V_124 [ V_120 + 1 ] ,
& V_11 -> V_95 . V_124 [ V_120 + 2 ] ,
sizeof( struct V_118 ) *
( F_97 ( V_11 -> V_95 . V_123 ) - V_120 - 2 ) ) ;
memset ( & V_11 -> V_95 . V_124 [ F_97 ( V_11 -> V_95 . V_123 ) - 1 ] ,
0 , sizeof( struct V_118 ) ) ;
F_125 ( & V_11 -> V_95 . V_123 , - 1 ) ;
}
static void F_126 ( struct V_10 * V_11 ,
int V_120 )
{
enum V_165 V_170 =
F_123 ( V_11 , V_120 ) ;
if ( V_170 == V_167 )
return;
if ( V_170 == V_169 || V_170 == V_168 ) {
F_5 ( V_120 == 0 ) ;
V_120 -- ;
}
F_124 ( V_11 , V_120 ) ;
if ( V_170 == V_168 )
F_124 ( V_11 , V_120 ) ;
}
static int F_127 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_115 ,
int V_120 , int V_171 , int V_172 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_173 * V_174 = & V_11 -> V_95 ;
struct V_118 * V_122 = & V_174 -> V_124 [ V_120 ] ;
V_50 = F_85 ( V_71 , V_3 , V_115 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_128 (
( unsigned long long ) F_121 ( V_3 ) ,
V_120 , F_12 ( V_122 -> V_127 ) , V_172 ) ;
F_95 ( & V_122 -> V_127 , V_172 ) ;
if ( ! V_122 -> V_127 ) {
if ( V_120 != F_97 ( V_174 -> V_123 ) - 1 ) {
memmove ( V_122 , V_122 + 1 ,
( F_97 ( V_174 -> V_123 ) - V_120 - 1 ) *
sizeof( struct V_118 ) ) ;
memset ( & V_174 -> V_124 [ F_97 ( V_174 -> V_123 ) - 1 ] ,
0 , sizeof( struct V_118 ) ) ;
}
F_125 ( & V_174 -> V_123 , - 1 ) ;
} else if ( V_171 )
F_126 ( V_11 , V_120 ) ;
F_90 ( V_71 , V_115 ) ;
V_17:
return V_50 ;
}
static int F_129 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * * V_115 ,
struct V_72 * V_73 )
{
int V_50 ;
T_4 V_79 ;
T_2 V_80 ;
T_1 V_81 , V_29 ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_7 * V_77 = NULL ;
struct V_10 * V_175 ;
struct V_10 * V_176 =
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
V_175 = (struct V_10 * ) V_77 -> V_12 ;
V_175 -> V_90 = F_86 ( V_73 -> V_91 ) ;
V_175 -> V_92 = F_87 ( V_81 ) ;
V_175 -> V_93 = F_86 ( V_79 ) ;
V_175 -> V_18 = F_87 ( V_29 ) ;
V_175 -> V_177 = F_88 ( 0 ) ;
V_175 -> V_178 = F_87 ( V_51 -> V_13 ) ;
V_175 -> V_160 = F_88 ( V_179 ) ;
F_90 ( V_71 , V_77 ) ;
memset ( & V_176 -> V_162 , 0 , V_6 -> V_88 -
F_130 ( struct V_10 , V_162 ) ) ;
V_176 -> V_162 . V_180 = F_86 ( F_131 ( V_6 ) ) ;
V_176 -> V_181 = F_88 ( 1 ) ;
V_176 -> V_162 . V_146 = F_86 ( 1 ) ;
V_176 -> V_162 . V_147 [ 0 ] . V_153 = F_87 ( V_29 ) ;
V_176 -> V_162 . V_147 [ 0 ] . V_182 = F_86 ( 1 ) ;
V_176 -> V_160 = F_88 ( V_161 ) ;
F_90 ( V_71 , V_51 ) ;
F_132 ( ( unsigned long long ) V_29 ,
F_97 ( V_175 -> V_95 . V_123 ) ) ;
* V_115 = V_77 ;
V_77 = NULL ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_133 ( struct V_118 * V_183 ,
struct V_118 * V_184 )
{
if ( F_134 ( V_183 ) + F_12 ( V_183 -> V_126 ) <=
F_134 ( V_184 ) )
return 1 ;
return 0 ;
}
static int F_135 ( const void * V_185 , const void * V_186 )
{
const struct V_118 * V_187 = V_185 , * V_188 = V_186 ;
T_2 V_189 = F_134 ( V_187 ) ;
T_2 V_125 = F_134 ( V_188 ) ;
if ( V_189 > V_125 )
return 1 ;
if ( V_189 < V_125 )
return - 1 ;
return 0 ;
}
static int F_136 ( const void * V_185 , const void * V_186 )
{
const struct V_118 * V_187 = V_185 , * V_188 = V_186 ;
T_1 V_189 = F_11 ( V_187 -> V_125 ) ;
T_1 V_125 = F_11 ( V_188 -> V_125 ) ;
if ( V_189 > V_125 )
return 1 ;
if ( V_189 < V_125 )
return - 1 ;
return 0 ;
}
static void F_137 ( void * V_185 , void * V_186 , int V_190 )
{
struct V_118 * V_187 = V_185 , * V_188 = V_186 ;
F_138 ( * V_187 , * V_188 ) ;
}
static int F_139 ( struct V_173 * V_174 ,
T_2 * V_191 , int * V_192 )
{
int V_193 = F_97 ( V_174 -> V_123 ) ;
int V_194 , V_195 = V_193 / 2 ;
for ( V_194 = 0 ; V_194 < V_195 ; V_194 ++ ) {
if ( F_133 (
& V_174 -> V_124 [ V_195 - V_194 - 1 ] ,
& V_174 -> V_124 [ V_195 - V_194 ] ) ) {
* V_192 = V_195 - V_194 ;
break;
}
if ( ( V_195 + V_194 + 1 ) == V_193 )
continue;
if ( F_133 (
& V_174 -> V_124 [ V_195 + V_194 ] ,
& V_174 -> V_124 [ V_195 + V_194 + 1 ] ) ) {
* V_192 = V_195 + V_194 + 1 ;
break;
}
}
if ( V_194 >= V_195 )
return - V_196 ;
* V_191 = F_134 ( & V_174 -> V_124 [ * V_192 ] ) ;
return 0 ;
}
static int F_140 ( struct V_7 * V_115 ,
struct V_7 * V_77 ,
T_2 * V_197 )
{
int V_192 = 0 , V_198 , V_50 ;
T_2 V_116 = 0 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_173 * V_174 = & V_11 -> V_95 ;
struct V_10 * V_175 =
(struct V_10 * ) V_77 -> V_12 ;
struct V_173 * V_199 = & V_175 -> V_95 ;
F_141 (
( unsigned long long ) V_115 -> V_13 ,
F_97 ( V_174 -> V_96 ) , F_97 ( V_174 -> V_123 ) ) ;
F_142 ( & V_174 -> V_124 , F_97 ( V_174 -> V_123 ) ,
sizeof( struct V_118 ) ,
F_135 , F_137 ) ;
V_50 = F_139 ( V_174 , & V_116 , & V_192 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
V_175 -> V_177 = F_88 ( V_116 ) ;
V_198 = F_97 ( V_174 -> V_123 ) - V_192 ;
memcpy ( V_199 -> V_124 , & V_174 -> V_124 [ V_192 ] ,
V_198 * sizeof( struct V_118 ) ) ;
memset ( & V_174 -> V_124 [ V_192 ] , 0 ,
V_198 * sizeof( struct V_118 ) ) ;
F_125 ( & V_174 -> V_123 , - V_198 ) ;
V_199 -> V_123 = F_86 ( V_198 ) ;
F_142 ( & V_174 -> V_124 , F_97 ( V_174 -> V_123 ) ,
sizeof( struct V_118 ) ,
F_136 , F_137 ) ;
F_142 ( & V_199 -> V_124 , F_97 ( V_199 -> V_123 ) ,
sizeof( struct V_118 ) ,
F_136 , F_137 ) ;
* V_197 = V_116 ;
return 0 ;
}
static int F_143 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_72 * V_73 )
{
int V_50 ;
T_4 V_79 ;
T_2 V_80 , V_200 ;
T_1 V_81 , V_29 ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_10 * V_176 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_7 * V_77 = NULL ;
struct V_10 * V_175 ;
struct V_143 V_201 ;
F_5 ( ! ( F_12 ( V_176 -> V_160 ) & V_161 ) ) ;
V_50 = F_85 ( V_71 , V_3 , V_51 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_85 ( V_71 , V_3 , V_115 ,
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
V_175 = (struct V_10 * ) V_77 -> V_12 ;
memset ( V_175 , 0 , V_6 -> V_88 ) ;
strcpy ( ( void * ) V_175 , V_89 ) ;
V_175 -> V_90 = F_86 ( V_73 -> V_91 ) ;
V_175 -> V_92 = F_87 ( V_81 ) ;
V_175 -> V_93 = F_86 ( V_79 ) ;
V_175 -> V_19 = F_88 ( F_13 ( V_6 ) -> V_20 ) ;
V_175 -> V_18 = F_87 ( V_29 ) ;
V_175 -> V_178 = F_87 ( V_51 -> V_13 ) ;
V_175 -> V_160 = F_88 ( V_179 ) ;
V_175 -> V_95 . V_96 =
F_86 ( F_89 ( V_6 ) ) ;
V_175 -> V_54 = V_176 -> V_54 ;
V_50 = F_140 ( V_115 , V_77 , & V_200 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_90 ( V_71 , V_115 ) ;
F_90 ( V_71 , V_77 ) ;
F_111 ( & V_201 , V_3 , V_51 ) ;
F_144 (
( unsigned long long ) V_77 -> V_13 , V_200 ) ;
V_50 = F_145 ( V_71 , & V_201 , V_200 , V_77 -> V_13 ,
1 , 0 , V_73 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_146 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_72 * V_73 )
{
int V_50 ;
struct V_7 * V_202 = NULL ;
if ( V_51 == V_115 ) {
V_50 = F_129 ( V_71 , V_3 , V_51 ,
& V_202 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else {
V_202 = V_115 ;
F_119 ( V_202 ) ;
}
V_50 = F_143 ( V_71 , V_3 , V_51 ,
V_202 , V_73 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_202 ) ;
return V_50 ;
}
static int F_147 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_118 * V_122 )
{
int V_50 = 0 , V_121 ;
T_2 V_200 , V_203 ;
struct V_140 * V_204 = NULL ;
struct V_143 V_144 ;
struct V_10 * V_11 =
(struct V_10 * ) V_51 -> V_12 ;
struct V_136 * V_137 ;
if ( ! ( F_12 ( V_11 -> V_160 ) & V_161 ) )
goto V_17;
V_11 = (struct V_10 * ) V_115 -> V_12 ;
V_203 = F_12 ( V_11 -> V_177 ) ;
V_200 = F_11 ( V_122 -> V_125 ) & V_163 ;
if ( V_203 <= V_200 )
goto V_17;
F_111 ( & V_144 , V_3 , V_51 ) ;
V_204 = F_112 ( & V_144 ) ;
if ( ! V_204 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_113 ( V_3 , V_204 , V_203 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_148 ( V_71 , 2 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_85 ( V_71 , V_3 , V_115 ,
V_85 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_149 ( V_71 , V_3 , F_150 ( V_204 ) ,
V_85 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_137 = F_151 ( V_204 ) ;
for ( V_121 = 0 ; V_121 < F_97 ( V_137 -> V_146 ) ; V_121 ++ )
if ( F_12 ( V_137 -> V_147 [ V_121 ] . V_148 ) == V_203 )
break;
F_5 ( V_121 == F_97 ( V_137 -> V_146 ) ) ;
V_137 -> V_147 [ V_121 ] . V_148 = F_88 ( V_200 ) ;
V_11 -> V_177 = F_88 ( V_200 ) ;
F_90 ( V_71 , F_150 ( V_204 ) ) ;
F_90 ( V_71 , V_115 ) ;
V_17:
F_117 ( V_204 ) ;
return V_50 ;
}
static int F_152 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_118 * V_122 ,
int V_120 , int V_171 ,
struct V_72 * V_73 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_173 * V_162 = & V_11 -> V_95 ;
struct V_7 * V_77 = NULL ;
F_5 ( F_12 ( V_11 -> V_160 ) & V_161 ) ;
if ( V_162 -> V_123 == V_162 -> V_96 ) {
T_1 V_116 = F_11 ( V_122 -> V_125 ) ;
T_2 V_117 = F_12 ( V_122 -> V_126 ) ;
V_50 = F_146 ( V_71 , V_3 , V_51 ,
V_115 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_118 ( V_3 , V_51 ,
V_116 , V_117 , NULL , & V_120 ,
& V_77 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_115 = V_77 ;
V_11 = (struct V_10 * ) V_115 -> V_12 ;
V_162 = & V_11 -> V_95 ;
}
V_50 = F_85 ( V_71 , V_3 , V_115 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_120 < F_97 ( V_162 -> V_123 ) )
memmove ( & V_162 -> V_124 [ V_120 + 1 ] ,
& V_162 -> V_124 [ V_120 ] ,
( F_97 ( V_162 -> V_123 ) - V_120 ) *
sizeof( struct V_118 ) ) ;
F_153 (
( unsigned long long ) V_115 -> V_13 , V_120 ,
( unsigned long long ) F_11 ( V_122 -> V_125 ) ,
F_12 ( V_122 -> V_126 ) , F_12 ( V_122 -> V_127 ) ) ;
V_162 -> V_124 [ V_120 ] = * V_122 ;
F_125 ( & V_162 -> V_123 , 1 ) ;
if ( V_171 )
F_126 ( V_11 , V_120 ) ;
F_90 ( V_71 , V_115 ) ;
if ( V_120 == 0 ) {
V_50 = F_147 ( V_71 , V_3 ,
V_51 ,
V_115 , V_122 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_154 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_118 * V_205 ,
int V_120 , int V_171 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 , V_208 ;
T_2 V_117 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_173 * V_162 = & V_11 -> V_95 ;
struct V_118 * V_209 = & V_162 -> V_124 [ V_120 ] ;
struct V_118 * V_210 = NULL ;
struct V_7 * V_77 = NULL ;
F_5 ( F_12 ( V_11 -> V_160 ) & V_161 ) ;
F_155 ( F_11 ( V_209 -> V_125 ) ,
F_12 ( V_209 -> V_126 ) ,
F_12 ( V_209 -> V_127 ) ,
F_11 ( V_205 -> V_125 ) ,
F_12 ( V_205 -> V_126 ) ,
F_12 ( V_205 -> V_127 ) ) ;
if ( ! V_205 -> V_127 &&
( V_205 -> V_125 == V_209 -> V_125 ||
F_11 ( V_205 -> V_125 ) +
F_12 ( V_205 -> V_126 ) ==
F_11 ( V_209 -> V_125 ) + F_12 ( V_209 -> V_126 ) ) )
V_208 = 0 ;
else
V_208 = 1 ;
if ( V_205 -> V_127 &&
( V_205 -> V_125 != V_209 -> V_125 &&
F_11 ( V_205 -> V_125 ) +
F_12 ( V_205 -> V_126 ) !=
F_11 ( V_209 -> V_125 ) + F_12 ( V_209 -> V_126 ) ) )
V_208 ++ ;
if ( F_97 ( V_162 -> V_123 ) + V_208 >
F_97 ( V_162 -> V_96 ) ) {
struct V_118 V_211 ;
T_1 V_116 = F_11 ( V_209 -> V_125 ) ;
V_117 = F_12 ( V_209 -> V_126 ) ;
V_50 = F_146 ( V_71 , V_3 , V_51 ,
V_115 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_118 ( V_3 , V_51 ,
V_116 , V_117 , & V_211 , & V_120 ,
& V_77 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_115 = V_77 ;
V_11 = (struct V_10 * ) V_115 -> V_12 ;
V_162 = & V_11 -> V_95 ;
V_209 = & V_162 -> V_124 [ V_120 ] ;
}
V_50 = F_85 ( V_71 , V_3 , V_115 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_120 != F_97 ( V_162 -> V_123 ) - 1 )
memmove ( & V_162 -> V_124 [ V_120 + 1 + V_208 ] ,
& V_162 -> V_124 [ V_120 + 1 ] ,
( F_97 ( V_162 -> V_123 ) - V_120 - 1 ) *
sizeof( struct V_118 ) ) ;
V_117 = ( F_11 ( V_209 -> V_125 ) +
F_12 ( V_209 -> V_126 ) ) -
( F_11 ( V_205 -> V_125 ) +
F_12 ( V_205 -> V_126 ) ) ;
if ( V_117 ) {
V_210 = & V_162 -> V_124 [ V_120 + V_208 ] ;
memcpy ( V_210 , V_209 , sizeof( struct V_118 ) ) ;
F_156 ( & V_210 -> V_125 ,
F_12 ( V_210 -> V_126 ) - V_117 ) ;
V_210 -> V_126 = F_88 ( V_117 ) ;
}
if ( V_205 -> V_125 != V_209 -> V_125 && V_210 != V_209 ) {
V_117 = F_11 ( V_205 -> V_125 ) -
F_11 ( V_209 -> V_125 ) ;
V_209 -> V_126 = F_88 ( V_117 ) ;
V_120 ++ ;
}
F_125 ( & V_162 -> V_123 , V_208 ) ;
if ( V_205 -> V_127 ) {
V_162 -> V_124 [ V_120 ] = * V_205 ;
F_157 (
( unsigned long long ) V_115 -> V_13 , V_120 ,
( unsigned long long ) F_11 ( V_205 -> V_125 ) ,
F_12 ( V_205 -> V_126 ) ,
F_12 ( V_205 -> V_127 ) ) ;
if ( V_171 )
F_126 ( V_11 , V_120 ) ;
}
F_90 ( V_71 , V_115 ) ;
V_17:
F_58 ( V_77 ) ;
return V_50 ;
}
static int F_158 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_116 , T_2 V_117 , int V_171 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 = 0 , V_120 ;
struct V_7 * V_115 = NULL ;
struct V_118 V_122 ;
unsigned int V_212 = 0 ;
F_159 (
( unsigned long long ) F_121 ( V_3 ) ,
( unsigned long long ) V_116 , V_117 ) ;
while ( V_117 ) {
V_50 = F_118 ( V_3 , V_51 ,
V_116 , V_117 , & V_122 , & V_120 ,
& V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_212 = F_12 ( V_122 . V_126 ) ;
if ( V_122 . V_127 && F_11 ( V_122 . V_125 ) == V_116 &&
V_212 <= V_117 ) {
F_160 (
( unsigned long long ) V_116 , V_212 ,
F_12 ( V_122 . V_127 ) ) ;
V_50 = F_127 ( V_71 , V_3 ,
V_115 , V_120 ,
V_171 , 1 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else if ( ! V_122 . V_127 ) {
V_122 . V_127 = F_88 ( 1 ) ;
F_161 (
( unsigned long long ) F_11 ( V_122 . V_125 ) ,
V_212 ) ;
V_50 = F_152 ( V_71 , V_3 , V_51 ,
V_115 ,
& V_122 , V_120 ,
V_171 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
} else {
V_212 = F_162 ( ( T_1 ) ( V_116 + V_117 ) ,
F_11 ( V_122 . V_125 ) + V_212 ) - V_116 ;
V_122 . V_125 = F_87 ( V_116 ) ;
V_122 . V_126 = F_88 ( V_212 ) ;
F_95 ( & V_122 . V_127 , 1 ) ;
F_163 (
( unsigned long long ) F_11 ( V_122 . V_125 ) ,
V_212 , F_12 ( V_122 . V_127 ) ) ;
V_50 = F_154 ( V_71 , V_3 ,
V_51 , V_115 ,
& V_122 , V_120 , V_171 ,
V_73 , V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_116 += V_212 ;
V_117 -= V_212 ;
F_58 ( V_115 ) ;
V_115 = NULL ;
}
V_17:
F_58 ( V_115 ) ;
return V_50 ;
}
static int F_164 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_143 V_144 ;
F_5 ( V_11 -> V_95 . V_123 ) ;
F_165 (
( unsigned long long ) F_121 ( V_3 ) ,
( unsigned long long ) V_115 -> V_13 ,
F_12 ( V_11 -> V_177 ) ) ;
F_111 ( & V_144 , V_3 , V_51 ) ;
V_50 = F_166 ( V_71 , & V_144 , F_12 ( V_11 -> V_177 ) ,
1 , V_73 , V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_167 ( V_3 , V_115 ) ;
V_50 = F_168 ( V_207 , V_111 ,
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
F_95 ( & V_11 -> V_181 , - 1 ) ;
if ( ! V_11 -> V_162 . V_146 ) {
F_5 ( V_11 -> V_181 ) ;
F_169 (
( unsigned long long ) V_51 -> V_13 ) ;
V_11 -> V_160 = 0 ;
V_11 -> V_178 = 0 ;
V_11 -> V_177 = 0 ;
memset ( & V_11 -> V_95 , 0 , V_6 -> V_88 -
F_130 ( struct V_10 , V_95 ) ) ;
V_11 -> V_95 . V_96 =
F_86 ( F_89 ( V_6 ) ) ;
}
F_90 ( V_71 , V_51 ) ;
V_17:
return V_50 ;
}
int F_170 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_116 , T_2 V_117 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
return F_158 ( V_71 , V_3 , V_51 ,
V_116 , V_117 , 1 ,
V_73 , V_207 ) ;
}
static int F_171 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
struct V_7 * V_115 ,
int V_120 , T_1 V_116 , unsigned int V_117 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 ;
struct V_10 * V_11 =
(struct V_10 * ) V_115 -> V_12 ;
struct V_118 * V_122 = & V_11 -> V_95 . V_124 [ V_120 ] ;
F_5 ( V_116 < F_11 ( V_122 -> V_125 ) ) ;
F_5 ( V_116 + V_117 >
F_11 ( V_122 -> V_125 ) + F_12 ( V_122 -> V_126 ) ) ;
F_172 (
( unsigned long long ) F_121 ( V_3 ) ,
( unsigned long long ) V_116 , V_117 ) ;
if ( V_116 == F_11 ( V_122 -> V_125 ) &&
V_117 == F_12 ( V_122 -> V_126 ) )
V_50 = F_127 ( V_71 , V_3 ,
V_115 , V_120 , 1 , - 1 ) ;
else {
struct V_118 V_213 = * V_122 ;
V_213 . V_125 = F_87 ( V_116 ) ;
V_213 . V_126 = F_88 ( V_117 ) ;
F_95 ( & V_213 . V_127 , - 1 ) ;
V_50 = F_154 ( V_71 , V_3 ,
V_51 , V_115 ,
& V_213 , V_120 , 1 ,
V_73 , V_207 ) ;
}
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( ! V_11 -> V_95 . V_123 && V_115 != V_51 ) {
V_50 = F_164 ( V_71 , V_3 , V_51 ,
V_115 , V_73 ,
V_207 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_17:
return V_50 ;
}
static int F_173 ( T_3 * V_71 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_116 , T_2 V_117 ,
struct V_72 * V_73 ,
struct V_206 * V_207 ,
int V_214 )
{
int V_50 = 0 , V_120 = 0 ;
struct V_118 V_122 ;
unsigned int V_215 = 0 , V_216 ;
struct V_5 * V_6 = F_110 ( V_3 ) ;
struct V_7 * V_115 = NULL ;
F_174 (
( unsigned long long ) F_121 ( V_3 ) ,
( unsigned long long ) V_116 , V_117 , V_214 ) ;
while ( V_117 ) {
V_50 = F_118 ( V_3 , V_51 ,
V_116 , V_117 , & V_122 , & V_120 ,
& V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_215 = F_12 ( V_122 . V_127 ) ;
F_5 ( V_215 == 0 ) ;
if ( ! V_214 )
F_5 ( V_215 > 1 ) ;
V_216 = F_162 ( ( T_1 ) ( V_116 + V_117 ) , F_11 ( V_122 . V_125 ) +
F_12 ( V_122 . V_126 ) ) - V_116 ;
V_50 = F_171 ( V_71 , V_3 , V_51 ,
V_115 , V_120 ,
V_116 , V_216 ,
V_73 , V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( F_12 ( V_122 . V_127 ) == 1 && V_214 ) {
V_50 = F_175 ( V_207 ,
F_176 ( V_6 , V_116 ) ,
V_216 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_116 += V_216 ;
V_117 -= V_216 ;
F_58 ( V_115 ) ;
V_115 = NULL ;
}
V_17:
F_58 ( V_115 ) ;
return V_50 ;
}
int F_177 ( struct V_55 * V_55 ,
T_3 * V_71 , T_2 V_116 , T_2 V_117 ,
struct V_72 * V_73 ,
struct V_206 * V_207 ,
int V_214 )
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
V_50 = F_173 ( V_71 , & V_33 -> V_4 , V_51 ,
V_116 , V_117 , V_73 , V_207 , V_214 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_58 ( V_51 ) ;
return V_50 ;
}
static int F_178 ( struct V_55 * V_55 ,
struct V_143 * V_144 ,
T_3 * V_71 , T_2 V_116 ,
T_2 V_117 , T_2 V_217 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 ;
F_179 ( F_61 ( V_55 ) -> V_83 ,
V_116 , V_117 , V_217 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
V_50 = F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_218 ) ;
goto V_17;
}
V_50 = F_180 ( V_71 , V_144 , V_116 ,
V_117 , V_217 , V_73 , V_207 ,
V_219 , 0 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
return V_50 ;
}
static int F_181 ( struct V_5 * V_6 ,
struct V_2 * V_3 ,
struct V_7 * V_51 ,
T_1 V_220 ,
T_2 V_221 ,
int * V_222 ,
int * V_106 )
{
int V_50 = 0 , V_120 , V_223 = 0 , V_224 = 0 ;
T_1 V_116 = V_220 ;
struct V_10 * V_11 ;
struct V_118 V_122 ;
struct V_7 * V_115 = NULL , * V_225 = NULL ;
T_2 V_117 ;
while ( V_221 ) {
V_50 = F_118 ( V_3 , V_51 ,
V_116 , V_221 , & V_122 ,
& V_120 , & V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_115 != V_225 ) {
if ( V_225 ) {
V_11 = (struct V_10 * )
V_225 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_123 ) +
V_224 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_223 ++ ;
}
V_224 = 0 ;
* V_106 += 1 ;
F_58 ( V_225 ) ;
V_225 = V_115 ;
F_119 ( V_225 ) ;
}
F_182 (
V_224 , ( unsigned long long ) V_116 , V_221 ,
( unsigned long long ) F_11 ( V_122 . V_125 ) ,
F_12 ( V_122 . V_126 ) ,
F_12 ( V_122 . V_127 ) , V_120 ) ;
V_117 = F_162 ( ( T_1 ) V_116 + V_221 , F_11 ( V_122 . V_125 ) +
F_12 ( V_122 . V_126 ) ) - V_116 ;
if ( V_122 . V_127 ) {
V_224 += 2 ;
if ( V_116 == V_220 &&
V_116 != F_11 ( V_122 . V_125 ) )
V_224 ++ ;
if ( V_116 + V_221 < F_11 ( V_122 . V_125 ) +
F_12 ( V_122 . V_126 ) )
V_224 ++ ;
} else
V_224 ++ ;
F_58 ( V_115 ) ;
V_115 = NULL ;
V_221 -= V_117 ;
V_116 += V_117 ;
}
if ( V_225 ) {
V_11 = (struct V_10 * ) V_225 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_123 ) + V_224 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_223 ++ ;
* V_106 += 1 ;
}
if ( ! V_223 )
goto V_17;
* V_222 += V_223 ;
* V_106 += V_223 ;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_160 ) & V_161 ) {
struct V_143 V_144 ;
F_111 ( & V_144 , V_3 , V_51 ) ;
* V_222 += F_183 ( V_144 . V_226 ) ;
* V_106 += F_184 ( V_6 ,
V_144 . V_226 ) ;
} else {
* V_106 += V_227 ;
* V_222 += 1 ;
}
V_17:
F_185 (
( unsigned long long ) V_220 , V_221 ,
* V_222 , * V_106 ) ;
F_58 ( V_115 ) ;
F_58 ( V_225 ) ;
return V_50 ;
}
int F_186 ( struct V_55 * V_55 ,
T_1 V_100 ,
T_1 V_228 ,
T_2 V_221 ,
int * V_106 ,
int * V_223 )
{
int V_50 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_33 ;
T_1 V_220 = F_187 ( V_55 -> V_76 , V_228 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
V_50 = F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_218 ) ;
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
V_50 = F_181 ( V_55 -> V_76 ,
& V_33 -> V_4 ,
V_51 ,
V_220 , V_221 ,
V_223 , V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_188 ( * V_223 , * V_106 ) ;
V_17:
F_58 ( V_51 ) ;
return V_50 ;
}
static inline unsigned int F_189 ( struct V_5 * V_6 )
{
return F_190 ( V_6 , V_229 ) ;
}
static inline unsigned int F_191 ( struct V_5 * V_6 )
{
return ~ ( F_189 ( V_6 ) - 1 ) ;
}
static inline unsigned int F_192 ( struct V_5 * V_6 ,
unsigned int V_230 ,
unsigned int V_116 )
{
F_5 ( V_230 > V_116 ) ;
return V_230 + ( ( V_116 - V_230 ) & F_191 ( V_6 ) ) ;
}
static inline unsigned int F_193 ( struct V_5 * V_6 ,
unsigned int V_117 )
{
unsigned int V_231 =
( V_117 + ( F_189 ( V_6 ) - 1 ) ) &
F_191 ( V_6 ) ;
if ( V_231 < V_117 )
V_231 = V_150 ;
return V_231 ;
}
static int F_194 ( struct V_55 * V_55 ,
struct V_136 * V_137 ,
T_2 V_116 ,
T_2 V_232 ,
T_2 V_233 ,
T_2 * V_234 ,
T_2 * V_235 )
{
int V_50 = 0 ;
int V_236 = F_97 ( V_137 -> V_164 ) , V_121 ;
struct V_7 * V_159 = NULL ;
struct V_134 * V_135 = NULL ;
struct V_158 * V_122 ;
unsigned int V_237 , V_238 = 0 ;
int V_239 = F_189 ( V_55 -> V_76 ) ;
int V_240 ;
F_5 ( V_116 + V_232 > V_233 ) ;
if ( V_236 > 0 ) {
V_50 = F_120 ( F_81 ( V_55 ) , V_137 , V_116 , & V_159 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_135 = (struct V_134 * ) V_159 -> V_12 ;
V_137 = & V_135 -> V_151 ;
if ( V_137 -> V_164 ) {
V_50 = F_10 ( V_55 -> V_76 ,
L_8 ,
V_55 -> V_218 ,
( unsigned long long ) V_159 -> V_13 ) ;
goto V_17;
}
}
* V_235 = 0 ;
for ( V_121 = 0 ; V_121 < F_97 ( V_137 -> V_146 ) ; V_121 ++ ) {
V_122 = & V_137 -> V_147 [ V_121 ] ;
if ( F_195 ( V_122 ) ) {
F_196 ( V_121 != 0 , L_9
L_10 , V_55 -> V_218 , V_121 ) ;
continue;
}
if ( F_12 ( V_122 -> V_148 ) +
F_97 ( V_122 -> V_182 ) <= V_116 )
continue;
if ( * V_235 == 0 ) {
F_5 ( ! ( V_122 -> V_241 & V_219 ) ) ;
* V_234 = F_12 ( V_122 -> V_148 ) ;
}
if ( ( ! ( V_122 -> V_241 & V_219 ) ) ||
( * V_235 && V_238 != F_12 ( V_122 -> V_148 ) ) ||
( V_233 <= F_12 ( V_122 -> V_148 ) ) )
break;
V_240 = F_97 ( V_122 -> V_182 ) ;
V_238 = F_12 ( V_122 -> V_148 ) + V_240 ;
if ( V_238 > V_233 ) {
V_238 = V_233 ;
V_240 = V_238 - F_12 ( V_122 -> V_148 ) ;
}
if ( ! * V_235 )
V_237 = V_232 ;
else
V_237 = ( V_116 + V_232 ) -
( * V_234 + * V_235 ) ;
if ( V_237 < V_239 )
V_237 = V_239 ;
if ( V_240 <= V_239 )
* V_235 += V_240 ;
else if ( * V_235 || ( * V_234 == V_116 ) ) {
V_237 = F_193 ( V_55 -> V_76 ,
V_237 ) ;
if ( V_240 < V_237 )
* V_235 += V_240 ;
else
* V_235 += V_237 ;
} else if ( ( * V_234 + V_239 ) >=
( V_116 + V_232 ) ) {
* V_235 = V_239 ;
} else if ( ( V_238 - V_116 ) <= V_239 ) {
* V_234 = V_238 - V_239 ;
* V_235 = V_239 ;
} else if ( ( V_238 - V_116 ) <= V_237 ) {
* V_234 = F_192 ( V_55 -> V_76 ,
* V_234 , V_116 ) ;
* V_235 = V_238 - * V_234 ;
} else {
* V_234 = F_192 ( V_55 -> V_76 ,
* V_234 , V_116 ) ;
V_237 = ( V_116 + V_232 ) - * V_234 ;
V_237 = F_193 ( V_55 -> V_76 ,
V_237 ) ;
if ( * V_234 + V_237 <= V_238 )
* V_235 = V_237 ;
else
* V_235 = V_238 - * V_234 ;
}
if ( ( * V_234 + * V_235 ) >= ( V_116 + V_232 ) )
break;
if ( V_121 + 1 == F_97 ( V_137 -> V_146 ) &&
V_135 && V_135 -> V_149 ) {
F_58 ( V_159 ) ;
V_159 = NULL ;
V_50 = F_197 ( F_81 ( V_55 ) ,
F_11 ( V_135 -> V_149 ) ,
& V_159 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_135 = (struct V_134 * ) V_159 -> V_12 ;
V_137 = & V_135 -> V_151 ;
V_121 = - 1 ;
}
}
V_17:
F_58 ( V_159 ) ;
return V_50 ;
}
static int F_198 ( struct V_5 * V_6 ,
T_2 V_242 , T_2 V_243 ,
struct V_143 * V_144 ,
struct V_2 * V_244 ,
struct V_7 * V_51 ,
struct V_72 * * V_73 ,
struct V_72 * * V_245 ,
int * V_106 )
{
int V_50 = 0 , V_222 = 0 ;
int V_246 = F_199 ( F_13 ( V_6 ) , V_144 ) ;
if ( V_246 < 0 ) {
V_50 = V_246 ;
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_246 < V_243 + 2 )
V_222 =
F_183 ( V_144 -> V_226 ) ;
* V_106 += F_184 ( V_6 , V_144 -> V_226 ) ;
V_50 = F_181 ( V_6 , V_244 , V_51 ,
V_242 , V_243 ,
& V_222 , V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_200 ( V_222 , * V_106 ) ;
V_50 = F_76 ( F_13 ( V_6 ) , V_222 ,
V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_245 ) {
V_50 = F_201 ( F_13 ( V_6 ) , V_243 ,
V_245 ) ;
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
static int F_202 ( T_3 * V_71 , struct V_7 * V_8 )
{
F_5 ( F_203 ( V_8 ) ) ;
F_204 ( V_8 ) ;
return 0 ;
}
int F_205 ( T_3 * V_71 ,
struct V_55 * V_55 ,
T_2 V_116 , T_2 V_247 ,
T_2 V_248 , T_2 V_249 )
{
int V_50 = 0 , V_250 ;
struct V_5 * V_6 = V_55 -> V_76 ;
T_1 V_251 = F_176 ( V_6 , V_248 ) ;
struct V_252 * V_252 ;
T_5 V_253 ;
unsigned int V_254 , V_255 ;
T_6 V_256 , V_257 , V_258 ;
struct V_259 * V_260 = V_55 -> V_261 ;
F_206 ( V_116 , V_247 ,
V_248 , V_249 ) ;
V_256 = ( ( T_6 ) V_116 ) << F_13 ( V_6 ) -> V_262 ;
V_257 = V_256 + ( V_249 << F_13 ( V_6 ) -> V_262 ) ;
if ( V_257 > F_207 ( V_55 ) )
V_257 = F_207 ( V_55 ) ;
while ( V_256 < V_257 ) {
V_253 = V_256 >> V_263 ;
V_258 = ( ( T_6 ) V_253 + 1 ) << V_263 ;
if ( V_258 > V_257 )
V_258 = V_257 ;
V_254 = V_256 & ( V_264 - 1 ) ;
V_255 = V_264 ;
if ( V_258 & ( V_264 - 1 ) )
V_255 = V_258 & ( V_264 - 1 ) ;
V_252 = F_208 ( V_260 , V_253 , V_48 ) ;
if ( ! V_252 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
break;
}
if ( V_264 <= F_13 ( V_6 ) -> V_265 )
F_5 ( F_209 ( V_252 ) ) ;
if ( ! F_210 ( V_252 ) ) {
V_50 = F_211 ( V_252 , V_266 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_267;
}
F_212 ( V_252 ) ;
}
if ( F_213 ( V_252 ) ) {
V_50 = F_214 ( V_71 , F_215 ( V_252 ) ,
V_254 , V_255 , & V_250 ,
F_202 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_267;
}
}
F_216 ( V_55 ,
V_71 , V_254 , V_255 ,
V_252 , 0 , & V_251 ) ;
F_217 ( V_252 ) ;
V_267:
F_218 ( V_252 ) ;
F_219 ( V_252 ) ;
V_252 = NULL ;
V_256 = V_258 ;
if ( V_50 )
break;
}
return V_50 ;
}
int F_220 ( T_3 * V_71 ,
struct V_55 * V_55 ,
T_2 V_116 , T_2 V_247 ,
T_2 V_248 , T_2 V_249 )
{
int V_50 = 0 ;
struct V_5 * V_6 = V_55 -> V_76 ;
struct V_2 * V_3 = F_81 ( V_55 ) ;
int V_121 , V_268 = F_176 ( V_6 , V_249 ) ;
T_1 V_269 = F_176 ( V_6 , V_247 ) ;
T_1 V_251 = F_176 ( V_6 , V_248 ) ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
struct V_7 * V_270 = NULL ;
struct V_7 * V_77 = NULL ;
F_206 ( V_116 , V_247 ,
V_248 , V_249 ) ;
for ( V_121 = 0 ; V_121 < V_268 ; V_121 ++ , V_269 ++ , V_251 ++ ) {
V_77 = F_83 ( V_28 -> V_6 , V_251 ) ;
if ( V_77 == NULL ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
break;
}
F_84 ( V_3 , V_77 ) ;
V_50 = F_15 ( V_3 , V_269 , & V_270 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_50 = F_221 ( V_71 , V_3 , V_77 ,
V_87 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
memcpy ( V_77 -> V_12 , V_270 -> V_12 , V_6 -> V_88 ) ;
F_90 ( V_71 , V_77 ) ;
F_58 ( V_77 ) ;
F_58 ( V_270 ) ;
V_77 = NULL ;
V_270 = NULL ;
}
F_58 ( V_77 ) ;
F_58 ( V_270 ) ;
return V_50 ;
}
static int F_222 ( T_3 * V_71 ,
struct V_143 * V_144 ,
T_2 V_116 , T_2 V_242 , T_2 V_117 ,
unsigned int V_271 ,
struct V_72 * V_73 ,
struct V_206 * V_207 )
{
int V_50 , V_120 ;
struct V_158 V_272 ;
struct V_140 * V_204 = NULL ;
struct V_136 * V_137 ;
struct V_5 * V_6 = F_110 ( V_144 -> V_273 ) ;
T_1 V_274 = F_121 ( V_144 -> V_273 ) ;
F_223 ( ( unsigned long long ) V_274 ,
V_116 , V_117 , V_242 , V_271 ) ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
V_272 . V_148 = F_88 ( V_116 ) ;
V_272 . V_182 = F_86 ( V_117 ) ;
V_272 . V_153 = F_87 ( F_176 ( V_6 ,
V_242 ) ) ;
V_272 . V_241 = V_271 ;
V_272 . V_241 &= ~ V_219 ;
V_204 = F_112 ( V_144 ) ;
if ( ! V_204 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_113 ( V_144 -> V_273 , V_204 , V_116 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_137 = F_151 ( V_204 ) ;
V_120 = F_224 ( V_137 , V_116 ) ;
if ( V_120 == - 1 ) {
V_50 = F_10 ( V_6 ,
L_11 ,
( unsigned long long ) V_274 , V_116 ) ;
goto V_17;
}
V_50 = F_225 ( V_71 , V_144 , V_204 , V_120 ,
& V_272 , V_73 , V_207 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_117 ( V_204 ) ;
return V_50 ;
}
static int F_226 ( T_3 * V_71 ,
struct V_275 * V_276 ,
T_2 V_116 , T_2 V_277 ,
T_2 V_37 , T_2 V_117 ,
unsigned int V_271 )
{
int V_50 ;
struct V_2 * V_3 = V_276 -> V_278 . V_273 ;
T_1 V_274 = F_121 ( V_3 ) ;
F_227 ( ( unsigned long long ) V_274 ,
V_116 , V_277 , V_37 , V_117 , V_271 ) ;
if ( ! ( V_271 & V_279 ) ) {
V_50 = V_276 -> V_280 ( V_71 , V_276 -> V_55 ,
V_116 , V_277 , V_37 , V_117 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_50 = F_222 ( V_71 , & V_276 -> V_278 ,
V_116 , V_37 , V_117 , V_271 ,
V_276 -> V_73 , & V_276 -> V_207 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
return V_50 ;
}
int F_228 ( struct V_5 * V_6 ,
struct V_55 * V_55 ,
T_2 V_116 , T_2 V_243 )
{
int V_50 = 0 ;
T_6 V_256 , V_257 , V_258 ;
T_5 V_253 ;
struct V_252 * V_252 ;
if ( F_229 ( V_55 ) )
return 0 ;
V_256 = ( ( T_6 ) V_116 ) << F_13 ( V_6 ) -> V_262 ;
V_257 = V_256 + ( V_243 << F_13 ( V_6 ) -> V_262 ) ;
V_50 = F_230 ( V_55 -> V_261 ,
V_256 , V_257 - 1 ) ;
if ( V_50 < 0 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
while ( V_256 < V_257 ) {
V_253 = V_256 >> V_263 ;
V_258 = ( ( T_6 ) V_253 + 1 ) << V_263 ;
if ( V_258 > V_257 )
V_258 = V_257 ;
V_252 = F_208 ( V_55 -> V_261 ,
V_253 , V_48 ) ;
F_5 ( ! V_252 ) ;
F_231 ( V_252 ) ;
if ( F_232 ( V_252 ) ) {
V_50 = - V_281 ;
F_56 ( V_50 ) ;
} else
F_217 ( V_252 ) ;
F_218 ( V_252 ) ;
F_219 ( V_252 ) ;
V_252 = NULL ;
V_256 = V_258 ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_233 ( struct V_275 * V_276 ,
T_2 V_282 , T_2 * V_242 ,
T_2 * V_243 ,
unsigned int * V_283 )
{
return F_234 ( V_276 -> V_55 , V_282 , V_242 ,
V_243 , V_283 ) ;
}
static int F_235 ( struct V_5 * V_6 ,
struct V_275 * V_276 ,
T_2 V_116 , T_2 V_242 ,
T_2 V_243 , unsigned int V_241 )
{
int V_50 , V_214 , V_120 , V_106 = 0 ;
T_2 V_284 , V_249 , V_285 ;
unsigned int V_212 ;
struct V_27 * V_28 = F_13 ( V_6 ) ;
T_3 * V_71 ;
struct V_7 * V_115 = NULL ;
struct V_2 * V_244 = & V_276 -> V_101 -> V_4 ;
struct V_118 V_122 ;
F_236 ( V_116 , V_242 ,
V_243 , V_241 ) ;
V_50 = F_198 ( V_6 , V_242 , V_243 ,
& V_276 -> V_278 ,
V_244 ,
V_276 -> V_51 ,
& V_276 -> V_73 ,
& V_276 -> V_245 , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
return V_50 ;
}
if ( V_276 -> V_286 )
V_106 += V_276 -> V_286 -> V_106 ;
V_106 += V_276 -> V_287 ;
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_285 = V_243 ;
while ( V_243 ) {
V_50 = F_118 ( V_244 , V_276 -> V_51 ,
V_242 , V_243 ,
& V_122 , & V_120 , & V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
F_5 ( ! V_122 . V_127 ) ;
V_212 = F_162 ( ( T_1 ) V_242 + V_243 ,
F_11 ( V_122 . V_125 ) +
F_12 ( V_122 . V_126 ) ) - V_242 ;
if ( F_12 ( V_122 . V_127 ) == 1 ) {
V_214 = 0 ;
V_50 = F_222 ( V_71 ,
& V_276 -> V_278 ,
V_116 , V_242 ,
V_212 , V_241 ,
V_276 -> V_73 ,
& V_276 -> V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
} else {
V_214 = 1 ;
V_50 = F_237 ( V_71 ,
V_276 -> V_245 ,
1 , V_212 ,
& V_284 , & V_249 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_226 ( V_71 , V_276 ,
V_116 , V_242 , V_284 ,
V_249 , V_241 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_212 = V_249 ;
}
V_50 = F_173 ( V_71 , V_244 ,
V_276 -> V_51 ,
V_242 , V_212 ,
V_276 -> V_73 ,
& V_276 -> V_207 , V_214 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_116 += V_212 ;
V_242 += V_212 ;
V_243 -= V_212 ;
F_58 ( V_115 ) ;
V_115 = NULL ;
}
if ( V_276 -> V_286 && V_276 -> V_286 -> V_288 ) {
V_50 = V_276 -> V_286 -> V_288 ( V_276 -> V_55 , V_71 ,
V_276 -> V_286 -> V_289 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
}
if ( V_276 -> V_290 == F_233 ) {
V_50 = F_228 ( V_6 , V_276 -> V_55 , V_116 ,
V_285 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_276 -> V_245 ) {
F_93 ( V_276 -> V_245 ) ;
V_276 -> V_245 = NULL ;
}
if ( V_276 -> V_73 ) {
F_93 ( V_276 -> V_73 ) ;
V_276 -> V_73 = NULL ;
}
F_58 ( V_115 ) ;
return V_50 ;
}
static int F_238 ( struct V_275 * V_276 )
{
int V_50 = 0 ;
struct V_55 * V_55 = V_276 -> V_55 ;
T_2 V_234 = V_276 -> V_234 , V_235 = V_276 -> V_235 ;
T_2 V_242 , V_243 ;
unsigned int V_271 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) ) {
return F_10 ( V_55 -> V_76 , L_7 ,
V_55 -> V_218 ) ;
}
F_239 ( & V_276 -> V_207 ) ;
while ( V_235 ) {
V_50 = V_276 -> V_290 ( V_276 , V_234 , & V_242 ,
& V_243 , & V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
F_5 ( ! ( V_271 & V_219 ) ) ;
if ( V_235 < V_243 )
V_243 = V_235 ;
V_50 = F_235 ( V_55 -> V_76 , V_276 ,
V_234 , V_242 ,
V_243 , V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
V_235 -= V_243 ;
V_234 += V_243 ;
}
if ( F_240 ( & V_276 -> V_207 ) ) {
F_241 ( V_28 , 1 ) ;
F_242 ( V_28 , & V_276 -> V_207 ) ;
}
return V_50 ;
}
static int F_243 ( struct V_55 * V_55 ,
struct V_7 * V_57 ,
T_2 V_116 , T_2 V_232 , T_2 V_233 )
{
int V_50 ;
T_2 V_234 = 0 , V_235 = 0 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_7 * V_51 = NULL ;
struct V_1 * V_101 ;
struct V_275 * V_276 = NULL ;
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_194 ( V_55 , & V_59 -> V_291 . V_292 ,
V_116 , V_232 , V_233 ,
& V_234 , & V_235 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_244 ( F_61 ( V_55 ) -> V_83 ,
V_116 , V_232 , V_233 ,
V_234 , V_235 ) ;
F_5 ( V_235 == 0 ) ;
V_276 = F_53 ( sizeof( struct V_275 ) , V_48 ) ;
if ( ! V_276 ) {
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
V_276 -> V_55 = V_55 ;
V_276 -> V_234 = V_234 ;
V_276 -> V_235 = V_235 ;
V_276 -> V_101 = V_101 ;
V_276 -> V_51 = V_51 ;
V_276 -> V_280 = F_205 ;
V_276 -> V_290 = F_233 ;
F_245 ( & V_276 -> V_278 ,
F_81 ( V_55 ) , V_57 ) ;
V_50 = F_238 ( V_276 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
F_246 ( V_55 , V_234 ) ;
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
V_17:
F_36 ( V_276 ) ;
return V_50 ;
}
int F_247 ( struct V_55 * V_55 ,
struct V_7 * V_57 ,
T_2 V_116 , T_2 V_232 , T_2 V_233 )
{
int V_50 = 0 ;
T_2 V_242 , V_243 ;
unsigned int V_271 ;
while ( V_232 ) {
V_50 = F_234 ( V_55 , V_116 , & V_242 ,
& V_243 , & V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
if ( V_232 < V_243 )
V_243 = V_232 ;
if ( V_271 & V_219 ) {
V_50 = F_243 ( V_55 , V_57 , V_116 ,
V_243 , V_233 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
break;
}
}
V_232 -= V_243 ;
V_116 += V_243 ;
}
return V_50 ;
}
static int F_248 ( struct V_275 * V_276 ,
T_2 V_282 , T_2 * V_242 ,
T_2 * V_243 ,
unsigned int * V_283 )
{
struct V_55 * V_55 = V_276 -> V_55 ;
struct V_293 * V_294 = V_276 -> V_295 ;
return F_249 ( V_55 , V_282 , V_242 ,
V_243 , & V_294 -> V_296 ,
V_283 ) ;
}
int F_250 ( struct V_55 * V_55 ,
struct V_2 * V_244 ,
struct V_7 * V_51 ,
struct V_293 * V_294 ,
int * V_222 , int * V_106 )
{
int V_50 = 0 , V_120 , V_223 = 0 ;
T_2 V_242 , V_243 ;
T_2 V_116 = 0 , V_221 = F_12 ( V_294 -> V_297 ) ;
struct V_10 * V_11 ;
struct V_118 V_122 ;
struct V_7 * V_115 = NULL ;
while ( V_116 < V_221 ) {
V_50 = F_249 ( V_55 , V_116 , & V_242 ,
& V_243 , & V_294 -> V_296 ,
NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_116 += V_243 ;
while ( V_243 ) {
V_50 = F_118 ( V_244 , V_51 ,
V_242 , V_243 ,
& V_122 , & V_120 ,
& V_115 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_5 ( ! V_122 . V_127 ) ;
V_11 = (struct V_10 * ) V_115 -> V_12 ;
if ( F_97 ( V_11 -> V_95 . V_123 ) + V_221 * 2 >
F_97 ( V_11 -> V_95 . V_96 ) )
V_223 ++ ;
* V_106 += 1 ;
F_58 ( V_115 ) ;
V_115 = NULL ;
if ( V_243 <= F_12 ( V_122 . V_126 ) )
break;
else
V_243 -= F_12 ( V_122 . V_126 ) ;
V_242 += V_243 ;
}
}
* V_222 += V_223 ;
if ( ! V_223 )
goto V_17;
V_11 = (struct V_10 * ) V_51 -> V_12 ;
if ( F_12 ( V_11 -> V_160 ) & V_161 )
* V_106 += V_227 ;
else {
struct V_143 V_144 ;
F_111 ( & V_144 , V_244 , V_51 ) ;
* V_106 += F_184 ( V_55 -> V_76 ,
V_144 . V_226 ) ;
}
V_17:
F_58 ( V_115 ) ;
return V_50 ;
}
int F_251 ( struct V_55 * V_55 ,
struct V_58 * V_59 ,
struct V_298 * V_299 ,
struct V_1 * V_101 ,
struct V_7 * V_51 ,
T_2 V_116 , T_2 V_232 ,
struct V_300 * V_301 )
{
int V_50 ;
struct V_293 * V_294 = V_299 -> V_302 ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_275 * V_276 = NULL ;
T_2 V_234 , V_235 ;
F_5 ( ! ( V_75 -> V_60 & V_61 ) ) ;
V_50 = F_194 ( V_55 , & V_294 -> V_296 ,
V_116 , V_232 , V_150 ,
& V_234 , & V_235 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_5 ( V_235 == 0 ) ;
V_276 = F_53 ( sizeof( struct V_275 ) , V_48 ) ;
if ( ! V_276 ) {
V_50 = - V_53 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_276 -> V_55 = V_55 ;
V_276 -> V_234 = V_234 ;
V_276 -> V_235 = V_235 ;
V_276 -> V_101 = V_101 ;
V_276 -> V_51 = V_51 ;
V_276 -> V_295 = V_294 ;
V_276 -> V_280 = F_220 ;
V_276 -> V_287 =
F_176 ( V_55 -> V_76 , 1 ) * V_235 ;
V_276 -> V_290 = F_248 ;
V_276 -> V_286 = V_301 ;
F_252 ( & V_276 -> V_278 ,
F_81 ( V_55 ) , V_299 ) ;
V_50 = F_238 ( V_276 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_17:
F_36 ( V_276 ) ;
return V_50 ;
}
int F_253 ( struct V_55 * V_55 ,
struct V_143 * V_278 ,
struct V_2 * V_244 ,
struct V_7 * V_51 ,
T_2 V_116 , T_2 V_242 , T_2 V_243 ,
struct V_206 * V_207 ,
struct V_300 * V_301 )
{
int V_50 ;
T_3 * V_71 ;
int V_106 = 1 , V_223 = 0 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_72 * V_73 = NULL ;
V_50 = F_181 ( V_55 -> V_76 ,
V_244 , V_51 ,
V_242 , V_243 ,
& V_223 , & V_106 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_254 ( V_223 , V_106 ) ;
if ( V_223 ) {
V_50 = F_76 ( F_13 ( V_55 -> V_76 ) ,
V_223 , & V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
if ( V_301 )
V_106 += V_301 -> V_106 ;
V_71 = F_77 ( V_28 , V_106 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_178 ( V_55 , V_278 , V_71 ,
V_116 , V_243 , V_242 ,
V_73 , V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_158 ( V_71 , V_244 , V_51 ,
V_242 , V_243 , 0 ,
V_73 , V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
if ( V_301 && V_301 -> V_288 ) {
V_50 = V_301 -> V_288 ( V_55 , V_71 , V_301 -> V_289 ) ;
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
static int F_255 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 ;
T_3 * V_71 ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
V_71 = F_77 ( F_13 ( V_55 -> V_76 ) ,
V_303 ) ;
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
V_55 -> V_304 = V_305 ;
V_59 -> V_304 = F_87 ( V_55 -> V_304 . V_306 ) ;
V_59 -> V_307 = F_88 ( V_55 -> V_304 . V_308 ) ;
F_90 ( V_71 , V_57 ) ;
V_86:
F_92 ( F_13 ( V_55 -> V_76 ) , V_71 ) ;
V_17:
return V_50 ;
}
static int F_256 ( struct V_55 * V_55 ,
struct V_7 * V_57 )
{
int V_50 , V_309 = 0 ;
struct V_7 * V_51 = NULL ;
struct V_74 * V_75 = F_61 ( V_55 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_57 -> V_12 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_1 * V_101 ;
unsigned int V_271 ;
T_6 V_190 ;
T_2 V_116 , V_243 , V_221 , V_242 ;
struct V_206 V_207 ;
struct V_143 V_310 ;
F_239 ( & V_207 ) ;
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
if ( V_75 -> V_60 & V_311 )
goto V_312;
F_245 ( & V_310 , F_81 ( V_55 ) , V_57 ) ;
V_190 = F_207 ( V_55 ) ;
V_221 = F_190 ( V_55 -> V_76 , V_190 ) ;
V_116 = 0 ;
while ( V_116 < V_221 ) {
V_50 = F_234 ( V_55 , V_116 , & V_242 ,
& V_243 , & V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_267;
}
if ( V_242 && ! ( V_271 & V_219 ) ) {
V_50 = F_253 ( V_55 , & V_310 ,
& V_101 -> V_4 ,
V_51 , V_116 ,
V_242 , V_243 ,
& V_207 , NULL ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_267;
}
V_309 = 1 ;
}
V_116 += V_243 ;
}
V_312:
if ( V_75 -> V_60 & V_131 ) {
V_50 = F_257 ( V_55 , V_57 ,
& V_101 -> V_4 ,
V_51 ,
& V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_267;
}
}
if ( V_309 ) {
V_50 = F_255 ( V_55 , V_57 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
V_267:
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
if ( ! V_50 && F_240 ( & V_207 ) ) {
F_241 ( V_28 , 1 ) ;
F_242 ( V_28 , & V_207 ) ;
}
V_17:
F_246 ( V_55 , 0 ) ;
return V_50 ;
}
static int F_258 ( struct V_55 * V_55 ,
struct V_143 * V_144 ,
struct V_2 * V_244 ,
struct V_7 * V_51 ,
T_2 V_116 , T_2 V_242 , T_2 V_243 ,
unsigned int V_271 ,
struct V_206 * V_207 )
{
int V_50 ;
T_3 * V_71 ;
int V_106 = 0 ;
struct V_27 * V_28 = F_13 ( V_55 -> V_76 ) ;
struct V_72 * V_73 = NULL ;
V_50 = F_198 ( V_55 -> V_76 ,
V_242 , V_243 ,
V_144 , V_244 ,
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
V_50 = F_145 ( V_71 , V_144 , V_116 ,
F_176 ( V_55 -> V_76 , V_242 ) ,
V_243 , V_271 , V_73 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_50 = F_170 ( V_71 , V_244 , V_51 ,
V_242 , V_243 ,
V_73 , V_207 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
if ( V_73 )
F_93 ( V_73 ) ;
return V_50 ;
}
static int F_259 ( struct V_55 * V_313 ,
struct V_7 * V_314 ,
struct V_55 * V_315 ,
struct V_7 * V_316 )
{
int V_50 ;
T_3 * V_71 ;
struct V_27 * V_28 = F_13 ( V_313 -> V_76 ) ;
struct V_58 * V_317 = (struct V_58 * ) V_314 -> V_12 ;
struct V_58 * V_318 = (struct V_58 * ) V_316 -> V_12 ;
F_5 ( ! ( F_61 ( V_313 ) -> V_60 & V_311 ) ) ;
V_71 = F_77 ( V_28 , V_303 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_80 ( V_71 , F_81 ( V_315 ) , V_316 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
V_318 -> V_291 . V_319 . V_320 = V_317 -> V_291 . V_319 . V_320 ;
memcpy ( V_318 -> V_291 . V_319 . V_321 , V_317 -> V_291 . V_319 . V_321 ,
F_97 ( V_317 -> V_291 . V_319 . V_320 ) ) ;
F_19 ( & F_61 ( V_315 ) -> V_98 ) ;
F_61 ( V_315 ) -> V_60 |= V_311 ;
V_318 -> V_99 = F_86 ( F_61 ( V_315 ) -> V_60 ) ;
F_21 ( & F_61 ( V_315 ) -> V_98 ) ;
F_90 ( V_71 , V_316 ) ;
V_86:
F_92 ( V_28 , V_71 ) ;
V_17:
return V_50 ;
}
static int F_260 ( struct V_55 * V_313 ,
struct V_55 * V_315 ,
struct V_7 * V_316 ,
struct V_2 * V_244 ,
struct V_7 * V_51 ,
struct V_206 * V_207 )
{
int V_50 = 0 ;
T_2 V_242 , V_243 , V_221 , V_116 ;
T_6 V_190 ;
unsigned int V_271 ;
struct V_143 V_144 ;
F_245 ( & V_144 , F_81 ( V_315 ) , V_316 ) ;
V_190 = F_207 ( V_313 ) ;
V_221 = F_190 ( V_313 -> V_76 , V_190 ) ;
V_116 = 0 ;
while ( V_116 < V_221 ) {
V_50 = F_234 ( V_313 , V_116 , & V_242 ,
& V_243 , & V_271 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( V_242 ) {
V_50 = F_258 ( V_315 , & V_144 ,
V_244 , V_51 ,
V_116 , V_242 ,
V_243 ,
V_271 ,
V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
}
V_116 += V_243 ;
}
V_17:
return V_50 ;
}
static int F_261 ( struct V_55 * V_313 ,
struct V_7 * V_314 ,
struct V_55 * V_315 ,
struct V_7 * V_316 ,
bool V_322 )
{
int V_50 ;
T_3 * V_71 ;
struct V_58 * V_317 = (struct V_58 * ) V_314 -> V_12 ;
struct V_58 * V_59 = (struct V_58 * ) V_316 -> V_12 ;
T_6 V_190 = F_207 ( V_313 ) ;
V_71 = F_77 ( F_13 ( V_315 -> V_76 ) ,
V_303 ) ;
if ( F_78 ( V_71 ) ) {
V_50 = F_79 ( V_71 ) ;
F_56 ( V_50 ) ;
return V_50 ;
}
V_50 = F_80 ( V_71 , F_81 ( V_315 ) , V_316 ,
V_85 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_86;
}
F_19 ( & F_61 ( V_315 ) -> V_98 ) ;
F_61 ( V_315 ) -> V_130 = F_61 ( V_313 ) -> V_130 ;
F_61 ( V_315 ) -> V_323 = F_61 ( V_313 ) -> V_323 ;
F_61 ( V_315 ) -> V_60 = F_61 ( V_313 ) -> V_60 ;
F_21 ( & F_61 ( V_315 ) -> V_98 ) ;
F_262 ( V_315 , V_190 ) ;
V_315 -> V_324 = V_313 -> V_324 ;
V_59 -> V_325 = V_317 -> V_325 ;
V_59 -> V_326 = V_317 -> V_326 ;
V_59 -> V_327 = V_317 -> V_327 ;
V_59 -> V_99 = V_317 -> V_99 ;
V_59 -> V_328 = V_317 -> V_328 ;
if ( V_322 ) {
V_315 -> V_329 = V_313 -> V_329 ;
V_315 -> V_330 = V_313 -> V_330 ;
V_315 -> V_331 = V_313 -> V_331 ;
V_59 -> V_329 = V_317 -> V_329 ;
V_59 -> V_330 = V_317 -> V_330 ;
V_59 -> V_331 = V_317 -> V_331 ;
V_315 -> V_304 = V_305 ;
V_59 -> V_304 = F_87 ( V_315 -> V_304 . V_306 ) ;
V_59 -> V_307 = F_88 ( V_315 -> V_304 . V_308 ) ;
V_315 -> V_332 = V_313 -> V_332 ;
V_59 -> V_332 = V_317 -> V_332 ;
V_59 -> V_333 = V_317 -> V_333 ;
}
F_90 ( V_71 , V_316 ) ;
V_86:
F_92 ( F_13 ( V_315 -> V_76 ) , V_71 ) ;
return V_50 ;
}
static int F_263 ( struct V_55 * V_313 ,
struct V_7 * V_314 ,
struct V_55 * V_315 ,
struct V_7 * V_316 ,
bool V_322 )
{
int V_50 ;
struct V_7 * V_51 = NULL ;
struct V_206 V_207 ;
struct V_27 * V_28 = F_13 ( V_313 -> V_76 ) ;
struct V_10 * V_11 ;
struct V_58 * V_59 = (struct V_58 * ) V_314 -> V_12 ;
struct V_1 * V_101 ;
F_239 ( & V_207 ) ;
V_50 = F_94 ( V_315 , V_316 ,
F_11 ( V_59 -> V_62 ) ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
if ( F_61 ( V_313 ) -> V_60 & V_311 ) {
V_50 = F_259 ( V_313 , V_314 ,
V_315 , V_316 ) ;
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
V_50 = F_260 ( V_313 , V_315 , V_316 ,
& V_101 -> V_4 , V_51 ,
& V_207 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_334;
}
V_334:
F_67 ( V_28 , V_101 , 1 ) ;
F_58 ( V_51 ) ;
V_17:
if ( F_240 ( & V_207 ) ) {
F_241 ( V_28 , 1 ) ;
F_242 ( V_28 , & V_207 ) ;
}
return V_50 ;
}
static int F_264 ( struct V_335 * V_336 ,
struct V_7 * V_270 ,
struct V_55 * V_337 ,
bool V_322 )
{
int V_50 ;
struct V_55 * V_55 = F_265 ( V_336 ) ;
struct V_7 * V_77 = NULL ;
if ( F_61 ( V_55 ) -> V_338 & V_339 ) {
V_50 = - V_340 ;
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_266 ( V_55 -> V_261 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
V_50 = F_256 ( V_55 , V_270 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_17;
}
F_267 ( V_337 , V_341 ) ;
V_50 = F_268 ( V_337 , & V_77 , 1 ,
V_342 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto V_114;
}
V_50 = F_263 ( V_55 , V_270 ,
V_337 , V_77 , V_322 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto F_104;
}
if ( F_61 ( V_55 ) -> V_60 & V_131 ) {
V_50 = F_269 ( V_55 , V_270 ,
V_337 , V_77 ,
V_322 ) ;
if ( V_50 ) {
F_56 ( V_50 ) ;
goto F_104;
}
}
V_50 = F_261 ( V_55 , V_270 ,
V_337 , V_77 , V_322 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
F_104:
F_103 ( V_337 , 1 ) ;
F_58 ( V_77 ) ;
V_114:
F_104 ( V_337 ) ;
V_17:
if ( ! V_50 ) {
V_50 = F_270 ( V_55 -> V_261 ) ;
if ( V_50 )
F_56 ( V_50 ) ;
}
return V_50 ;
}
static int F_271 ( struct V_335 * V_336 , struct V_55 * V_343 ,
struct V_335 * V_344 , bool V_322 )
{
int error ;
struct V_55 * V_55 = F_265 ( V_336 ) ;
struct V_7 * V_270 = NULL ;
struct V_55 * V_345 = NULL ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) )
return - V_346 ;
error = F_272 ( V_343 , V_55 -> V_331 ,
& V_345 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
error = F_273 ( V_55 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
error = F_101 ( V_55 , & V_270 , 1 ) ;
if ( error ) {
F_56 ( error ) ;
F_274 ( V_55 , 1 ) ;
goto V_17;
}
F_64 ( & F_61 ( V_55 ) -> V_128 ) ;
F_64 ( & F_61 ( V_55 ) -> V_129 ) ;
error = F_264 ( V_336 , V_270 ,
V_345 , V_322 ) ;
F_68 ( & F_61 ( V_55 ) -> V_129 ) ;
F_68 ( & F_61 ( V_55 ) -> V_128 ) ;
F_103 ( V_55 , 1 ) ;
F_274 ( V_55 , 1 ) ;
F_58 ( V_270 ) ;
if ( error ) {
F_56 ( error ) ;
goto V_17;
}
if ( ! V_322 ) {
error = F_275 ( V_343 , V_345 ,
& V_344 -> V_347 ) ;
if ( error )
F_56 ( error ) ;
}
V_17:
if ( ! error ) {
error = F_276 ( V_343 , V_345 ,
V_344 ) ;
if ( error )
F_56 ( error ) ;
}
if ( V_345 ) {
F_277 ( V_345 ) ;
if ( error )
F_105 ( V_345 ) ;
}
return error ;
}
static inline int F_278 ( struct V_55 * V_343 , struct V_335 * V_348 )
{
if ( F_279 ( V_348 ) )
return - V_349 ;
if ( F_280 ( V_343 ) )
return - V_350 ;
return F_281 ( V_343 , V_351 | V_352 ) ;
}
static int F_282 ( struct V_335 * V_336 , struct V_55 * V_343 ,
struct V_335 * V_344 , bool V_322 )
{
struct V_55 * V_55 = F_265 ( V_336 ) ;
int error ;
if ( ! V_55 )
return - V_350 ;
error = F_278 ( V_343 , V_344 ) ;
if ( error )
return error ;
if ( V_343 -> V_76 != V_55 -> V_76 )
return - V_353 ;
if ( F_283 ( V_55 ) || F_284 ( V_55 ) )
return - V_354 ;
if ( ! F_285 ( V_55 -> V_331 ) )
return - V_354 ;
if ( V_322 ) {
if ( ! F_286 ( F_287 () , V_55 -> V_329 ) && ! F_288 ( V_355 ) )
return - V_354 ;
if ( ! F_289 ( V_55 -> V_330 ) && ! F_288 ( V_355 ) )
return - V_354 ;
}
if ( ! V_322 ) {
error = F_281 ( V_55 , V_356 ) ;
if ( error )
return error ;
}
F_100 ( V_55 ) ;
error = F_290 ( V_343 ) ;
if ( ! error )
error = F_271 ( V_336 , V_343 , V_344 , V_322 ) ;
F_104 ( V_55 ) ;
if ( ! error )
F_291 ( V_343 , V_344 ) ;
return error ;
}
int F_292 ( struct V_55 * V_55 ,
const char T_7 * V_357 ,
const char T_7 * V_358 ,
bool V_322 )
{
struct V_335 * V_344 ;
struct V_204 V_359 , V_360 ;
int error ;
if ( ! V_1 ( F_13 ( V_55 -> V_76 ) ) )
return - V_346 ;
error = F_293 ( V_361 , V_357 , 0 , & V_359 ) ;
if ( error ) {
F_56 ( error ) ;
return error ;
}
V_344 = F_294 ( V_361 , V_358 , & V_360 , 0 ) ;
error = F_79 ( V_344 ) ;
if ( F_78 ( V_344 ) ) {
F_56 ( error ) ;
goto V_17;
}
error = - V_353 ;
if ( V_359 . V_362 != V_360 . V_362 ) {
F_56 ( error ) ;
goto V_363;
}
error = F_282 ( V_359 . V_335 ,
F_265 ( V_360 . V_335 ) ,
V_344 , V_322 ) ;
V_363:
F_295 ( & V_360 , V_344 ) ;
V_17:
F_296 ( & V_359 ) ;
return error ;
}
