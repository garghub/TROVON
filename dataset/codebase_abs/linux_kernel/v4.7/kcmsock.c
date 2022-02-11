static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static inline struct V_4 * V_4 ( struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 -> V_7 ;
}
static inline struct V_8 * V_8 ( struct V_5 * V_6 )
{
return (struct V_8 * ) ( ( void * ) V_6 -> V_7 +
F_2 ( struct V_9 , V_10 ) ) ;
}
static void F_3 ( struct V_2 * V_11 , int V_12 )
{
V_11 -> V_13 = V_14 ;
V_11 -> V_15 ( V_11 ) ;
}
static void F_4 ( struct V_16 * V_17 , int V_12 ,
struct V_5 * V_6 )
{
struct V_2 * V_11 = V_17 -> V_3 ;
F_5 ( & V_17 -> V_18 ) ;
if ( V_17 -> V_19 )
return;
V_17 -> V_19 = 1 ;
F_6 ( V_17 -> V_20 . V_21 ) ;
F_3 ( V_11 , V_12 ) ;
}
static void F_7 ( struct V_16 * V_17 , int V_12 ,
bool V_22 )
{
struct V_2 * V_11 = V_17 -> V_3 ;
struct V_23 * V_24 = V_17 -> V_24 ;
F_8 ( & V_24 -> V_25 ) ;
if ( V_17 -> V_26 ) {
F_9 ( & V_24 -> V_25 ) ;
return;
}
V_17 -> V_26 = 1 ;
F_6 ( V_17 -> V_20 . V_27 ) ;
if ( ! V_17 -> V_28 ) {
F_10 ( & V_17 -> V_29 ) ;
} else if ( V_22 ) {
F_11 () ;
F_12 ( V_30 , & V_17 -> V_28 -> V_31 ) ;
}
F_9 ( & V_24 -> V_25 ) ;
F_3 ( V_11 , V_12 ) ;
}
static void F_13 ( struct V_23 * V_24 ,
struct V_16 * V_17 )
{
F_14 ( V_24 -> V_20 . V_32 ,
V_17 -> V_20 . V_32 - V_17 -> V_33 ) ;
V_24 -> V_20 . V_34 +=
V_17 -> V_20 . V_34 - V_17 -> V_35 ;
V_17 -> V_35 = V_17 -> V_20 . V_34 ;
V_17 -> V_33 = V_17 -> V_20 . V_32 ;
}
static void F_15 ( struct V_23 * V_24 ,
struct V_16 * V_17 )
{
F_14 ( V_24 -> V_20 . V_36 ,
V_17 -> V_20 . V_36 - V_17 -> V_37 ) ;
V_24 -> V_20 . V_38 +=
V_17 -> V_20 . V_38 - V_17 -> V_39 ;
V_17 -> V_39 = V_17 -> V_20 . V_38 ;
V_17 -> V_37 = V_17 -> V_20 . V_36 ;
}
static void F_16 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_16 * V_17 ;
struct V_5 * V_6 ;
if ( F_17 ( V_40 -> V_41 || V_40 -> V_42 || V_40 -> V_43 ) )
return;
while ( F_17 ( ( V_6 = F_18 ( & V_24 -> V_44 ) ) ) ) {
if ( F_19 ( & V_40 -> V_3 , V_6 ) ) {
F_20 ( & V_24 -> V_44 , V_6 ) ;
F_21 ( ! F_22 ( & V_40 -> V_3 ) ) ;
return;
}
}
while ( ! F_23 ( & V_24 -> V_45 ) ) {
V_17 = F_24 ( & V_24 -> V_45 , struct V_16 ,
V_46 ) ;
if ( F_19 ( & V_40 -> V_3 , V_17 -> V_47 ) ) {
F_21 ( ! F_22 ( & V_40 -> V_3 ) ) ;
return;
}
F_10 ( & V_17 -> V_46 ) ;
V_17 -> V_47 = NULL ;
F_11 () ;
F_12 ( V_30 , & V_17 -> V_48 ) ;
}
F_25 ( & V_40 -> V_49 ,
& V_40 -> V_24 -> V_50 ) ;
V_40 -> V_41 = true ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_40 -> V_24 ;
unsigned int V_51 = V_6 -> V_52 ;
F_27 ( V_3 , V_51 ) ;
F_28 ( V_51 , & V_3 -> V_53 ) ;
F_29 () ;
if ( ! V_40 -> V_41 && ! V_40 -> V_42 &&
F_22 ( V_3 ) < V_3 -> V_54 ) {
F_8 ( & V_24 -> V_55 ) ;
F_16 ( V_40 ) ;
F_9 ( & V_24 -> V_55 ) ;
}
}
static int F_19 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_3 -> V_58 ;
if ( F_30 ( & V_3 -> V_53 ) >= V_3 -> V_59 )
return - V_60 ;
if ( ! F_31 ( V_3 , V_6 , V_6 -> V_52 ) )
return - V_61 ;
V_6 -> V_62 = NULL ;
F_32 ( V_6 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_63 = F_26 ;
F_33 ( V_6 -> V_52 , & V_3 -> V_53 ) ;
F_34 ( V_3 , V_6 -> V_52 ) ;
F_35 ( V_57 , V_6 ) ;
if ( ! F_36 ( V_3 , V_64 ) )
V_3 -> V_65 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_23 * V_24 , struct V_56 * V_66 )
{
struct V_5 * V_6 ;
struct V_1 * V_40 ;
while ( ( V_6 = F_18 ( V_66 ) ) ) {
V_6 -> V_63 = V_67 ;
F_32 ( V_6 ) ;
V_68:
if ( F_23 ( & V_24 -> V_50 ) ) {
F_35 ( & V_24 -> V_44 , V_6 ) ;
continue;
}
V_40 = F_24 ( & V_24 -> V_50 ,
struct V_1 , V_49 ) ;
if ( F_19 ( & V_40 -> V_3 , V_6 ) ) {
F_10 ( & V_40 -> V_49 ) ;
V_40 -> V_41 = false ;
F_38 () ;
goto V_68;
}
}
}
static struct V_1 * F_39 ( struct V_16 * V_17 ,
struct V_5 * V_66 )
{
struct V_23 * V_24 = V_17 -> V_24 ;
struct V_1 * V_40 ;
F_21 ( V_17 -> V_47 ) ;
if ( V_17 -> V_69 )
return V_17 -> V_69 ;
F_8 ( & V_24 -> V_55 ) ;
if ( V_17 -> V_69 ) {
F_9 ( & V_24 -> V_55 ) ;
return V_17 -> V_69 ;
}
F_13 ( V_24 , V_17 ) ;
if ( F_23 ( & V_24 -> V_50 ) ) {
V_17 -> V_47 = V_66 ;
F_25 ( & V_17 -> V_46 ,
& V_24 -> V_45 ) ;
F_9 ( & V_24 -> V_55 ) ;
return NULL ;
}
V_40 = F_24 ( & V_24 -> V_50 ,
struct V_1 , V_49 ) ;
F_10 ( & V_40 -> V_49 ) ;
V_40 -> V_41 = false ;
V_17 -> V_69 = V_40 ;
V_40 -> V_42 = V_17 ;
F_9 ( & V_24 -> V_55 ) ;
return V_40 ;
}
static void F_40 ( struct V_70 * V_71 )
{
F_41 ( F_42 ( V_71 , struct V_1 , V_72 ) ) ;
}
static void F_43 ( struct V_16 * V_17 ,
bool V_73 )
{
struct V_1 * V_40 = V_17 -> V_69 ;
struct V_23 * V_24 = V_17 -> V_24 ;
if ( ! V_40 )
return;
F_8 ( & V_24 -> V_55 ) ;
V_17 -> V_69 = NULL ;
V_40 -> V_42 = NULL ;
F_11 () ;
if ( F_17 ( V_40 -> V_74 ) ) {
F_9 ( & V_24 -> V_55 ) ;
F_44 ( & V_40 -> V_72 , F_40 ) ;
F_45 ( & V_40 -> V_72 ) ;
return;
}
if ( F_17 ( V_40 -> V_43 ) ) {
F_37 ( V_24 , & V_40 -> V_3 . V_58 ) ;
} else if ( V_73 || F_17 ( ! F_22 ( & V_40 -> V_3 ) ) ) {
F_16 ( V_40 ) ;
}
F_9 ( & V_24 -> V_55 ) ;
}
static void F_46 ( struct V_16 * V_17 )
{
if ( V_17 -> V_3 -> V_75 )
F_47 ( & V_17 -> V_18 , V_17 -> V_3 -> V_75 ) ;
}
static int F_48 ( T_1 * V_76 , struct V_5 * V_77 ,
unsigned int V_78 , T_2 V_79 )
{
struct V_16 * V_17 = (struct V_16 * ) V_76 -> V_80 . V_10 ;
struct V_8 * V_81 ;
struct V_1 * V_40 ;
struct V_5 * V_66 , * V_6 ;
T_2 V_82 = 0 , V_83 ;
T_3 V_84 ;
int V_12 ;
bool V_85 = false ;
if ( V_17 -> V_47 )
return 0 ;
V_66 = V_17 -> V_86 ;
if ( V_66 ) {
V_81 = V_8 ( V_66 ) ;
if ( F_17 ( V_81 -> V_87 ) ) {
V_82 = V_79 <= V_81 -> V_87 ?
V_79 : V_81 -> V_87 ;
V_81 -> V_87 -= V_82 ;
return V_82 ;
}
if ( F_17 ( V_78 ) ) {
V_77 = F_49 ( V_77 , V_88 ) ;
if ( ! V_77 ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
V_76 -> error = - V_60 ;
return 0 ;
}
if ( ! F_50 ( V_77 , V_78 ) ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
F_51 ( V_77 ) ;
V_76 -> error = - V_60 ;
return 0 ;
}
V_85 = true ;
V_78 = 0 ;
}
if ( ! V_17 -> V_90 ) {
V_12 = F_52 ( V_66 , V_88 ) ;
if ( V_12 ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
V_76 -> error = V_12 ;
return 0 ;
}
if ( F_17 ( F_53 ( V_66 ) -> V_91 ) ) {
if ( F_21 ( V_66 -> V_92 ) ) {
V_76 -> error = - V_93 ;
return 0 ;
}
V_6 = F_54 ( 0 , V_88 ) ;
if ( ! V_6 ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
V_76 -> error = - V_60 ;
return 0 ;
}
V_6 -> V_51 = V_66 -> V_51 ;
V_6 -> V_94 = V_66 -> V_51 ;
V_6 -> V_52 = V_66 -> V_52 ;
* V_8 ( V_6 ) = * V_8 ( V_66 ) ;
V_17 -> V_90 = & V_66 -> V_92 ;
F_53 ( V_6 ) -> V_91 = V_66 ;
V_17 -> V_86 = V_6 ;
V_66 = V_6 ;
} else {
V_17 -> V_90 =
& F_53 ( V_66 ) -> V_91 ;
}
}
}
while ( V_82 < V_79 ) {
V_6 = F_49 ( V_77 , V_88 ) ;
if ( ! V_6 ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
V_76 -> error = - V_60 ;
break;
}
V_83 = V_79 - V_82 ;
V_66 = V_17 -> V_86 ;
if ( ! V_66 ) {
V_66 = V_6 ;
V_17 -> V_86 = V_66 ;
V_17 -> V_90 = NULL ;
V_81 = V_8 ( V_66 ) ;
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
V_81 -> V_95 = V_78 + V_82 ;
} else {
V_12 = F_52 ( V_6 , V_88 ) ;
if ( V_12 ) {
F_6 ( V_17 -> V_20 . V_89 ) ;
V_76 -> error = V_12 ;
break;
}
V_81 = V_8 ( V_66 ) ;
* V_17 -> V_90 = V_6 ;
V_17 -> V_90 = & V_6 -> V_92 ;
V_66 -> V_94 += V_6 -> V_51 ;
V_66 -> V_51 += V_6 -> V_51 ;
V_66 -> V_52 += V_6 -> V_52 ;
}
if ( ! V_81 -> V_96 ) {
T_3 V_51 ;
V_51 = F_55 ( V_17 -> V_97 , V_66 ) ;
if ( ! V_51 ) {
if ( ! V_81 -> V_98 ) {
F_46 ( V_17 ) ;
}
V_81 -> V_98 += V_83 ;
V_82 += V_83 ;
F_6 ( V_17 -> V_20 . V_99 ) ;
F_21 ( V_82 != V_79 ) ;
break;
} else if ( V_51 > V_17 -> V_3 -> V_59 ) {
F_6 ( V_17 -> V_20 . V_100 ) ;
V_76 -> error = - V_101 ;
V_17 -> V_86 = NULL ;
F_4 ( V_17 , V_101 , V_66 ) ;
break;
} else if ( V_51 <= ( T_3 ) V_66 -> V_51 -
V_6 -> V_51 - V_81 -> V_95 ) {
F_6 ( V_17 -> V_20 . V_102 ) ;
V_76 -> error = - V_103 ;
V_17 -> V_86 = NULL ;
F_4 ( V_17 , V_103 , V_66 ) ;
break;
}
V_81 -> V_96 = V_51 ;
}
V_84 = ( T_3 ) ( V_81 -> V_98 + V_83 ) - V_81 -> V_96 ;
if ( V_84 < 0 ) {
if ( V_81 -> V_96 - V_81 -> V_98 >
F_56 ( V_17 -> V_3 ) ) {
if ( ! V_81 -> V_98 ) {
F_46 ( V_17 ) ;
}
V_17 -> V_104 = V_81 -> V_96 -
V_81 -> V_98 ;
V_81 -> V_98 += V_83 ;
V_81 -> V_87 = V_83 ;
F_14 ( V_17 -> V_20 . V_32 , V_83 ) ;
V_76 -> V_105 = 0 ;
break;
}
V_81 -> V_98 += V_83 ;
V_82 += V_83 ;
F_21 ( V_82 != V_79 ) ;
break;
}
F_21 ( V_84 > V_83 ) ;
V_82 += ( V_83 - V_84 ) ;
F_5 ( & V_17 -> V_18 ) ;
V_17 -> V_86 = NULL ;
F_6 ( V_17 -> V_20 . V_34 ) ;
V_106:
V_40 = F_39 ( V_17 , V_66 ) ;
if ( ! V_40 ) {
break;
}
if ( F_19 ( & V_40 -> V_3 , V_66 ) ) {
F_43 ( V_17 , false ) ;
goto V_106;
}
}
if ( V_85 )
F_51 ( V_77 ) ;
F_14 ( V_17 -> V_20 . V_32 , V_82 ) ;
return V_82 ;
}
static int F_57 ( struct V_16 * V_17 )
{
T_1 V_76 ;
V_76 . V_80 . V_10 = V_17 ;
V_76 . error = 0 ;
V_76 . V_105 = 1 ;
F_58 ( V_17 -> V_3 , & V_76 , F_48 ) ;
F_43 ( V_17 , true ) ;
return V_76 . error ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_16 * V_17 ;
F_60 ( & V_3 -> V_107 ) ;
V_17 = (struct V_16 * ) V_3 -> V_108 ;
if ( F_17 ( ! V_17 || V_17 -> V_19 ) )
goto V_109;
if ( V_17 -> V_47 )
goto V_109;
if ( V_17 -> V_104 ) {
if ( F_56 ( V_3 ) >= V_17 -> V_104 )
V_17 -> V_104 = 0 ;
else
goto V_109;
}
if ( F_57 ( V_17 ) == - V_60 )
F_61 ( V_30 , & V_17 -> V_110 , 0 ) ;
V_109:
F_62 ( & V_3 -> V_107 ) ;
}
static void F_63 ( struct V_16 * V_17 )
{
T_1 V_111 ;
struct V_2 * V_11 = V_17 -> V_3 ;
F_64 ( V_11 ) ;
F_60 ( & V_11 -> V_107 ) ;
if ( F_17 ( V_11 -> V_108 != V_17 ) )
goto V_109;
if ( F_17 ( V_17 -> V_19 ) )
goto V_109;
if ( V_17 -> V_47 )
goto V_109;
V_111 . V_80 . V_10 = V_17 ;
if ( F_57 ( V_17 ) == - V_60 )
F_61 ( V_30 , & V_17 -> V_110 , 0 ) ;
V_109:
F_62 ( & V_11 -> V_107 ) ;
F_65 ( V_11 ) ;
}
static void F_66 ( struct V_70 * V_71 )
{
F_63 ( F_42 ( V_71 , struct V_16 , V_48 ) ) ;
}
static void F_67 ( struct V_70 * V_71 )
{
F_63 ( F_42 ( V_71 , struct V_16 ,
V_110 . V_112 ) ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
F_3 ( V_3 , V_14 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_16 * V_17 ;
struct V_23 * V_24 ;
struct V_1 * V_40 ;
F_60 ( & V_3 -> V_107 ) ;
V_17 = (struct V_16 * ) V_3 -> V_108 ;
if ( F_17 ( ! V_17 ) )
goto V_109;
V_24 = V_17 -> V_24 ;
F_8 ( & V_24 -> V_25 ) ;
V_40 = V_17 -> V_28 ;
if ( V_40 )
F_12 ( V_30 , & V_40 -> V_31 ) ;
F_9 ( & V_24 -> V_25 ) ;
V_109:
F_62 ( & V_3 -> V_107 ) ;
}
static struct V_16 * F_70 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_16 * V_17 ;
V_17 = V_40 -> V_113 ;
F_71 () ;
if ( V_17 ) {
F_21 ( V_40 -> V_114 ) ;
if ( F_17 ( V_17 -> V_26 ) )
F_72 ( V_40 ) ;
else
return V_40 -> V_113 ;
}
F_8 ( & V_24 -> V_25 ) ;
V_17 = V_40 -> V_113 ;
if ( F_17 ( V_17 ) ) {
F_21 ( V_40 -> V_114 ) ;
F_9 ( & V_24 -> V_25 ) ;
return V_40 -> V_113 ;
}
if ( ! F_23 ( & V_24 -> V_115 ) ) {
V_17 = F_24 ( & V_24 -> V_115 ,
struct V_16 ,
V_29 ) ;
F_10 ( & V_17 -> V_29 ) ;
if ( V_40 -> V_114 ) {
F_10 ( & V_40 -> V_116 ) ;
V_40 -> V_114 = false ;
}
V_40 -> V_113 = V_17 ;
V_17 -> V_28 = V_40 ;
F_6 ( V_17 -> V_20 . V_117 ) ;
} else if ( ! V_40 -> V_114 ) {
F_25 ( & V_40 -> V_116 ,
& V_24 -> V_118 ) ;
V_40 -> V_114 = true ;
}
F_9 ( & V_24 -> V_25 ) ;
return V_17 ;
}
static void F_73 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = V_17 -> V_24 ;
struct V_1 * V_40 ;
if ( F_23 ( & V_24 -> V_118 ) ) {
F_25 ( & V_17 -> V_29 ,
& V_24 -> V_115 ) ;
} else {
V_40 = F_24 ( & V_24 -> V_118 ,
struct V_1 ,
V_116 ) ;
F_10 ( & V_40 -> V_116 ) ;
V_40 -> V_114 = false ;
V_17 -> V_28 = V_40 ;
F_11 () ;
V_40 -> V_113 = V_17 ;
F_6 ( V_17 -> V_20 . V_117 ) ;
F_12 ( V_30 , & V_40 -> V_31 ) ;
}
}
static void F_72 ( struct V_1 * V_40 )
{
struct V_16 * V_17 ;
struct V_23 * V_24 = V_40 -> V_24 ;
F_8 ( & V_24 -> V_25 ) ;
V_17 = V_40 -> V_113 ;
if ( F_21 ( ! V_17 ) ) {
F_9 ( & V_24 -> V_25 ) ;
return;
}
F_71 () ;
F_15 ( V_24 , V_17 ) ;
F_21 ( V_40 -> V_114 ) ;
V_40 -> V_113 = NULL ;
V_17 -> V_28 = NULL ;
F_6 ( V_17 -> V_20 . V_119 ) ;
if ( F_17 ( V_17 -> V_26 ) ) {
if ( V_17 -> V_74 ) {
F_10 ( & V_17 -> V_120 ) ;
V_24 -> V_121 -- ;
F_74 ( V_17 -> V_3 ) ;
F_75 ( V_17 -> V_3 -> V_122 -> V_123 ) ;
F_76 ( V_124 , V_17 ) ;
}
F_9 ( & V_24 -> V_25 ) ;
return;
}
F_73 ( V_17 ) ;
F_9 ( & V_24 -> V_25 ) ;
}
static void F_77 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
F_8 ( & V_24 -> V_25 ) ;
F_6 ( V_24 -> V_20 . V_125 ) ;
F_9 ( & V_24 -> V_25 ) ;
}
static int F_78 ( struct V_1 * V_40 )
{
struct V_2 * V_3 = & V_40 -> V_3 ;
struct V_16 * V_17 ;
struct V_5 * V_6 , * V_66 ;
struct V_4 * V_126 ;
unsigned short V_127 , V_128 ;
unsigned int V_129 , V_130 = 0 ;
int V_131 = 0 ;
V_40 -> V_132 = false ;
V_17 = V_40 -> V_113 ;
if ( F_17 ( V_17 && V_17 -> V_26 ) ) {
F_72 ( V_40 ) ;
F_77 ( V_40 ) ;
if ( F_79 ( & V_3 -> V_133 ) )
return 0 ;
V_4 ( F_80 ( & V_3 -> V_133 ) ) -> V_129 = 0 ;
} else if ( F_79 ( & V_3 -> V_133 ) ) {
return 0 ;
}
V_66 = F_80 ( & V_3 -> V_133 ) ;
V_126 = V_4 ( V_66 ) ;
if ( V_126 -> V_129 ) {
if ( F_21 ( ! V_17 ) ) {
V_131 = - V_93 ;
goto V_109;
}
V_129 = V_126 -> V_129 ;
V_128 = V_126 -> V_128 ;
V_127 = V_126 -> V_127 ;
V_6 = V_126 -> V_134 ;
goto V_135;
}
V_68:
V_17 = F_70 ( V_40 ) ;
if ( ! V_17 )
goto V_109;
do {
V_6 = V_66 ;
V_126 = V_4 ( V_66 ) ;
V_129 = 0 ;
V_136:
if ( F_21 ( ! F_53 ( V_6 ) -> V_137 ) ) {
V_131 = - V_93 ;
goto V_109;
}
for ( V_127 = 0 ; V_127 < F_53 ( V_6 ) -> V_137 ;
V_127 ++ ) {
T_4 * V_138 ;
V_128 = 0 ;
V_135:
V_138 = & F_53 ( V_6 ) -> V_139 [ V_127 ] ;
if ( F_21 ( ! V_138 -> V_140 ) ) {
V_131 = - V_93 ;
goto V_109;
}
V_131 = F_81 ( V_17 -> V_3 -> V_122 ,
V_138 -> V_141 . V_142 ,
V_138 -> V_143 + V_128 ,
V_138 -> V_140 - V_128 ,
V_144 ) ;
if ( V_131 <= 0 ) {
if ( V_131 == - V_145 ) {
V_126 -> V_129 = V_129 ;
V_126 -> V_128 = V_128 ;
V_126 -> V_127 = V_127 ;
V_126 -> V_134 = V_6 ;
V_131 = 0 ;
goto V_109;
}
F_7 ( V_17 , V_131 ? - V_131 : V_14 ,
true ) ;
F_72 ( V_40 ) ;
V_126 -> V_129 = 0 ;
F_77 ( V_40 ) ;
V_131 = 0 ;
goto V_68;
}
V_129 += V_131 ;
V_128 += V_131 ;
F_14 ( V_17 -> V_20 . V_36 , V_131 ) ;
if ( V_128 < V_138 -> V_140 ) {
goto V_135;
}
}
if ( V_6 == V_66 ) {
if ( F_82 ( V_6 ) ) {
V_6 = F_53 ( V_6 ) -> V_91 ;
goto V_136;
}
} else if ( V_6 -> V_92 ) {
V_6 = V_6 -> V_92 ;
goto V_136;
}
F_83 ( & V_3 -> V_133 ) ;
F_51 ( V_66 ) ;
V_3 -> V_146 -= V_129 ;
V_130 += V_129 ;
F_6 ( V_17 -> V_20 . V_38 ) ;
} while ( ( V_66 = F_80 ( & V_3 -> V_133 ) ) );
V_109:
if ( ! V_66 ) {
F_21 ( ! F_79 ( & V_3 -> V_133 ) ) ;
F_72 ( V_40 ) ;
}
V_3 -> V_147 ( V_3 ) ;
return V_130 ? : V_131 ;
}
static void F_84 ( struct V_70 * V_71 )
{
struct V_1 * V_40 = F_42 ( V_71 , struct V_1 , V_31 ) ;
struct V_2 * V_3 = & V_40 -> V_3 ;
int V_12 ;
F_64 ( V_3 ) ;
V_12 = F_78 ( V_40 ) ;
if ( V_12 < 0 ) {
F_85 ( L_1 , V_12 ) ;
F_3 ( & V_40 -> V_3 , - V_12 ) ;
goto V_109;
}
if ( F_86 ( V_3 -> V_122 ) &&
F_87 ( V_148 , & V_3 -> V_122 -> V_149 ) ) {
F_88 ( V_148 , & V_3 -> V_122 -> V_149 ) ;
V_3 -> V_147 ( V_3 ) ;
}
V_109:
F_65 ( V_3 ) ;
}
static void F_89 ( struct V_1 * V_40 )
{
if ( V_40 -> V_132 )
F_78 ( V_40 ) ;
}
static T_3 F_90 ( struct V_150 * V_2 , struct V_141 * V_141 ,
int V_95 , T_2 V_140 , int V_149 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_66 = NULL ;
long V_151 = F_91 ( V_3 , V_149 & V_144 ) ;
bool V_152 ;
int V_12 = 0 ;
int V_153 ;
if ( V_149 & V_154 )
V_149 |= V_155 ;
V_152 = ! ( V_149 & V_155 ) ;
F_64 ( V_3 ) ;
F_92 ( V_156 , V_3 ) ;
V_12 = - V_14 ;
if ( V_3 -> V_13 )
goto V_157;
if ( V_40 -> V_158 ) {
V_66 = V_40 -> V_158 ;
V_6 = V_4 ( V_66 ) -> V_159 ;
V_153 = F_53 ( V_6 ) -> V_137 ;
if ( F_93 ( V_6 , V_153 , V_141 , V_95 ) ) {
F_94 ( & F_53 ( V_6 ) -> V_139 [ V_153 - 1 ] , V_140 ) ;
F_53 ( V_6 ) -> V_160 |= V_161 ;
goto V_162;
}
if ( V_153 >= V_163 ) {
struct V_5 * V_164 ;
V_164 = F_54 ( 0 , V_3 -> V_165 ) ;
while ( ! V_164 ) {
F_89 ( V_40 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
}
if ( V_66 == V_6 )
F_53 ( V_66 ) -> V_91 = V_164 ;
else
V_6 -> V_92 = V_164 ;
V_6 = V_164 ;
V_6 -> V_166 = V_167 ;
V_153 = 0 ;
}
} else {
if ( ! F_96 ( V_3 ) ) {
F_89 ( V_40 ) ;
F_97 ( V_148 , & V_3 -> V_122 -> V_149 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
}
V_66 = F_54 ( 0 , V_3 -> V_165 ) ;
while ( ! V_66 ) {
F_89 ( V_40 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
}
V_6 = V_66 ;
V_153 = 0 ;
}
F_98 ( V_141 ) ;
F_99 ( V_6 , V_153 , V_141 , V_95 , V_140 ) ;
F_53 ( V_6 ) -> V_160 |= V_161 ;
V_162:
V_6 -> V_51 += V_140 ;
V_6 -> V_94 += V_140 ;
V_6 -> V_52 += V_140 ;
V_3 -> V_146 += V_140 ;
F_34 ( V_3 , V_140 ) ;
if ( V_66 != V_6 ) {
V_66 -> V_51 += V_140 ;
V_66 -> V_94 += V_140 ;
V_66 -> V_52 += V_140 ;
}
if ( V_152 ) {
bool V_168 = F_79 ( & V_3 -> V_133 ) ;
F_100 ( & V_3 -> V_133 , V_66 ) ;
V_40 -> V_158 = NULL ;
F_6 ( V_40 -> V_20 . V_38 ) ;
if ( V_149 & V_169 ) {
V_40 -> V_132 = true ;
} else if ( V_40 -> V_132 || V_168 ) {
V_12 = F_78 ( V_40 ) ;
if ( V_12 < 0 ) {
F_85 ( L_2 ) ;
F_3 ( & V_40 -> V_3 , - V_12 ) ;
}
}
} else {
V_40 -> V_158 = V_66 ;
V_4 ( V_66 ) -> V_159 = V_6 ;
}
F_14 ( V_40 -> V_20 . V_36 , V_140 ) ;
F_65 ( V_3 ) ;
return V_140 ;
V_157:
F_89 ( V_40 ) ;
V_12 = F_101 ( V_3 , V_149 , V_12 ) ;
if ( F_17 ( F_102 ( & V_3 -> V_133 ) == 0 && V_12 == - V_145 ) )
V_3 -> V_147 ( V_3 ) ;
F_65 ( V_3 ) ;
return V_12 ;
}
static int F_103 ( struct V_150 * V_2 , struct V_170 * V_171 , T_2 V_51 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_66 = NULL ;
T_2 V_172 , V_173 = 0 ;
long V_151 = F_91 ( V_3 , V_171 -> V_174 & V_144 ) ;
int V_152 = ( V_2 -> type == V_175 ) ?
! ( V_171 -> V_174 & V_155 ) : ! ! ( V_171 -> V_174 & V_176 ) ;
int V_12 = - V_14 ;
F_64 ( V_3 ) ;
F_92 ( V_156 , V_3 ) ;
if ( V_3 -> V_13 )
goto V_157;
if ( V_40 -> V_158 ) {
V_66 = V_40 -> V_158 ;
V_6 = V_4 ( V_66 ) -> V_159 ;
goto V_177;
}
if ( ! F_96 ( V_3 ) ) {
F_89 ( V_40 ) ;
F_97 ( V_148 , & V_3 -> V_122 -> V_149 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
}
V_66 = F_54 ( 0 , V_3 -> V_165 ) ;
while ( ! V_66 ) {
F_89 ( V_40 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
V_66 = F_54 ( 0 , V_3 -> V_165 ) ;
}
V_6 = V_66 ;
V_6 -> V_166 = V_167 ;
V_177:
while ( F_104 ( V_171 ) ) {
bool V_178 = true ;
int V_153 = F_53 ( V_6 ) -> V_137 ;
struct V_179 * V_180 = F_105 ( V_3 ) ;
if ( ! F_106 ( V_3 , V_180 ) )
goto V_181;
if ( ! F_93 ( V_6 , V_153 , V_180 -> V_141 ,
V_180 -> V_95 ) ) {
if ( V_153 == V_163 ) {
struct V_5 * V_164 ;
V_164 = F_54 ( 0 , V_3 -> V_165 ) ;
if ( ! V_164 )
goto V_181;
if ( V_66 == V_6 )
F_53 ( V_66 ) -> V_91 = V_164 ;
else
V_6 -> V_92 = V_164 ;
V_6 = V_164 ;
V_6 -> V_166 = V_167 ;
continue;
}
V_178 = false ;
}
V_172 = F_107 ( int , F_104 ( V_171 ) ,
V_180 -> V_140 - V_180 -> V_95 ) ;
if ( ! F_108 ( V_3 , V_172 ) )
goto V_181;
V_12 = F_109 ( V_3 , & V_171 -> V_182 , V_6 ,
V_180 -> V_141 ,
V_180 -> V_95 ,
V_172 ) ;
if ( V_12 )
goto V_157;
if ( V_178 ) {
F_94 ( & F_53 ( V_6 ) -> V_139 [ V_153 - 1 ] , V_172 ) ;
} else {
F_99 ( V_6 , V_153 , V_180 -> V_141 ,
V_180 -> V_95 , V_172 ) ;
F_98 ( V_180 -> V_141 ) ;
}
V_180 -> V_95 += V_172 ;
V_173 += V_172 ;
if ( V_66 != V_6 ) {
V_66 -> V_51 += V_172 ;
V_66 -> V_94 += V_172 ;
}
continue;
V_181:
F_89 ( V_40 ) ;
V_12 = F_95 ( V_3 , & V_151 ) ;
if ( V_12 )
goto V_157;
}
if ( V_152 ) {
bool V_168 = F_79 ( & V_3 -> V_133 ) ;
F_100 ( & V_3 -> V_133 , V_66 ) ;
V_40 -> V_158 = NULL ;
F_6 ( V_40 -> V_20 . V_38 ) ;
if ( V_171 -> V_174 & V_169 ) {
V_40 -> V_132 = true ;
} else if ( V_40 -> V_132 || V_168 ) {
V_12 = F_78 ( V_40 ) ;
if ( V_12 < 0 ) {
F_85 ( L_2 ) ;
F_3 ( & V_40 -> V_3 , - V_12 ) ;
}
}
} else {
V_183:
V_40 -> V_158 = V_66 ;
V_4 ( V_66 ) -> V_159 = V_6 ;
}
F_14 ( V_40 -> V_20 . V_36 , V_173 ) ;
F_65 ( V_3 ) ;
return V_173 ;
V_157:
F_89 ( V_40 ) ;
if ( V_173 && V_2 -> type == V_184 ) {
goto V_183;
}
if ( V_66 != V_40 -> V_158 )
F_51 ( V_66 ) ;
V_12 = F_101 ( V_3 , V_171 -> V_174 , V_12 ) ;
if ( F_17 ( F_102 ( & V_3 -> V_133 ) == 0 && V_12 == - V_145 ) )
V_3 -> V_147 ( V_3 ) ;
F_65 ( V_3 ) ;
return V_12 ;
}
static struct V_5 * F_110 ( struct V_2 * V_3 , int V_149 ,
long V_151 , int * V_12 )
{
struct V_5 * V_6 ;
while ( ! ( V_6 = F_80 ( & V_3 -> V_58 ) ) ) {
if ( V_3 -> V_13 ) {
* V_12 = F_111 ( V_3 ) ;
return NULL ;
}
if ( F_36 ( V_3 , V_185 ) )
return NULL ;
if ( ( V_149 & V_144 ) || ! V_151 ) {
* V_12 = - V_145 ;
return NULL ;
}
F_112 ( V_3 , & V_151 , NULL ) ;
if ( F_113 ( V_186 ) ) {
* V_12 = F_114 ( V_151 ) ;
return NULL ;
}
}
return V_6 ;
}
static int F_115 ( struct V_150 * V_2 , struct V_170 * V_171 ,
T_2 V_51 , int V_149 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
int V_12 = 0 ;
long V_151 ;
struct V_8 * V_81 ;
int V_173 = 0 ;
struct V_5 * V_6 ;
V_151 = F_116 ( V_3 , V_149 & V_144 ) ;
F_64 ( V_3 ) ;
V_6 = F_110 ( V_3 , V_149 , V_151 , & V_12 ) ;
if ( ! V_6 )
goto V_109;
V_81 = V_8 ( V_6 ) ;
if ( V_51 > V_81 -> V_96 )
V_51 = V_81 -> V_96 ;
V_12 = F_117 ( V_6 , V_81 -> V_95 , V_171 , V_51 ) ;
if ( V_12 < 0 )
goto V_109;
V_173 = V_51 ;
if ( F_86 ( ! ( V_149 & V_187 ) ) ) {
F_14 ( V_40 -> V_20 . V_32 , V_173 ) ;
if ( V_173 < V_81 -> V_96 ) {
if ( V_2 -> type == V_175 ) {
V_171 -> V_174 |= V_188 ;
goto V_189;
}
V_81 -> V_95 += V_173 ;
V_81 -> V_96 -= V_173 ;
} else {
V_189:
V_171 -> V_174 |= V_176 ;
F_6 ( V_40 -> V_20 . V_34 ) ;
F_118 ( V_6 , & V_3 -> V_58 ) ;
F_51 ( V_6 ) ;
}
}
V_109:
F_65 ( V_3 ) ;
return V_173 ? : V_12 ;
}
static T_3 F_119 ( struct V_2 * V_3 ,
struct V_190 * V_191 ,
struct V_192 * V_193 )
{
int V_131 ;
F_65 ( V_3 ) ;
V_131 = F_120 ( V_191 , V_193 ) ;
F_64 ( V_3 ) ;
return V_131 ;
}
static T_3 F_121 ( struct V_150 * V_2 , T_5 * V_194 ,
struct V_190 * V_191 , T_2 V_51 ,
unsigned int V_149 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
long V_151 ;
struct V_8 * V_81 ;
int V_12 = 0 ;
T_3 V_173 ;
struct V_5 * V_6 ;
V_151 = F_116 ( V_3 , V_149 & V_144 ) ;
F_64 ( V_3 ) ;
V_6 = F_110 ( V_3 , V_149 , V_151 , & V_12 ) ;
if ( ! V_6 )
goto V_195;
V_81 = V_8 ( V_6 ) ;
if ( V_51 > V_81 -> V_96 )
V_51 = V_81 -> V_96 ;
V_173 = F_122 ( V_6 , V_3 , V_81 -> V_95 , V_191 , V_51 , V_149 ,
F_119 ) ;
if ( V_173 < 0 ) {
V_12 = V_173 ;
goto V_195;
}
F_14 ( V_40 -> V_20 . V_32 , V_173 ) ;
V_81 -> V_95 += V_173 ;
V_81 -> V_96 -= V_173 ;
F_65 ( V_3 ) ;
return V_173 ;
V_195:
F_65 ( V_3 ) ;
return V_12 ;
}
static void F_123 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
if ( V_40 -> V_43 )
return;
F_8 ( & V_24 -> V_55 ) ;
V_40 -> V_43 = 1 ;
if ( ! V_40 -> V_42 ) {
if ( V_40 -> V_41 ) {
F_10 ( & V_40 -> V_49 ) ;
V_40 -> V_41 = false ;
}
F_37 ( V_24 , & V_40 -> V_3 . V_58 ) ;
}
F_9 ( & V_24 -> V_55 ) ;
}
static void F_124 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
if ( ! V_40 -> V_43 )
return;
F_8 ( & V_24 -> V_55 ) ;
V_40 -> V_43 = 0 ;
F_16 ( V_40 ) ;
F_9 ( & V_24 -> V_55 ) ;
}
static int F_125 ( struct V_150 * V_2 , int V_196 , int V_197 ,
char T_6 * V_198 , unsigned int V_199 )
{
struct V_1 * V_40 = F_1 ( V_2 -> V_3 ) ;
int V_200 , V_201 ;
int V_12 = 0 ;
if ( V_196 != V_202 )
return - V_203 ;
if ( V_199 < sizeof( int ) )
return - V_93 ;
if ( F_126 ( V_200 , ( int T_6 * ) V_198 ) )
return - V_93 ;
V_201 = V_200 ? 1 : 0 ;
switch ( V_197 ) {
case V_204 :
F_64 ( & V_40 -> V_3 ) ;
if ( V_201 )
F_123 ( V_40 ) ;
else
F_124 ( V_40 ) ;
F_65 ( & V_40 -> V_3 ) ;
break;
default:
V_12 = - V_203 ;
}
return V_12 ;
}
static int F_127 ( struct V_150 * V_2 , int V_196 , int V_197 ,
char T_6 * V_198 , int T_6 * V_199 )
{
struct V_1 * V_40 = F_1 ( V_2 -> V_3 ) ;
int V_200 , V_51 ;
if ( V_196 != V_202 )
return - V_203 ;
if ( F_126 ( V_51 , V_199 ) )
return - V_205 ;
V_51 = F_107 (unsigned int, len, sizeof(int)) ;
if ( V_51 < 0 )
return - V_93 ;
switch ( V_197 ) {
case V_204 :
V_200 = V_40 -> V_43 ;
break;
default:
return - V_203 ;
}
if ( F_128 ( V_51 , V_199 ) )
return - V_205 ;
if ( F_129 ( V_198 , & V_200 , V_51 ) )
return - V_205 ;
return 0 ;
}
static void F_130 ( struct V_1 * V_40 , struct V_23 * V_24 )
{
struct V_1 * V_206 ;
struct V_207 * V_66 ;
int V_208 = 0 ;
V_40 -> V_3 . V_209 = V_210 ;
V_40 -> V_24 = V_24 ;
F_8 ( & V_24 -> V_25 ) ;
V_66 = & V_24 -> V_211 ;
F_131 (tkcm, &mux->kcm_socks, kcm_sock_list) {
if ( V_206 -> V_208 != V_208 )
break;
V_66 = & V_206 -> V_212 ;
V_208 ++ ;
}
F_132 ( & V_40 -> V_212 , V_66 ) ;
V_40 -> V_208 = V_208 ;
V_24 -> V_213 ++ ;
F_9 ( & V_24 -> V_25 ) ;
F_44 ( & V_40 -> V_31 , F_84 ) ;
F_8 ( & V_24 -> V_55 ) ;
F_16 ( V_40 ) ;
F_9 ( & V_24 -> V_55 ) ;
}
static void F_133 ( unsigned long V_80 )
{
struct V_16 * V_17 = (struct V_16 * ) V_80 ;
F_6 ( V_17 -> V_20 . V_214 ) ;
F_4 ( V_17 , V_215 , NULL ) ;
}
static int F_134 ( struct V_150 * V_2 , struct V_150 * V_216 ,
struct V_97 * V_217 )
{
struct V_1 * V_40 = F_1 ( V_2 -> V_3 ) ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_2 * V_11 ;
struct V_16 * V_17 = NULL , * V_218 ;
struct V_207 * V_66 ;
int V_208 = 0 ;
if ( V_216 -> V_219 -> V_220 != V_221 &&
V_216 -> V_219 -> V_220 != V_222 )
return - V_93 ;
V_11 = V_216 -> V_3 ;
if ( ! V_11 )
return - V_93 ;
if ( V_11 -> V_223 != V_224 )
return - V_93 ;
V_17 = F_135 ( V_124 , V_225 ) ;
if ( ! V_17 )
return - V_60 ;
V_17 -> V_24 = V_24 ;
V_17 -> V_3 = V_11 ;
V_17 -> V_97 = V_217 ;
F_136 ( & V_17 -> V_18 , F_133 ,
( unsigned long ) V_17 ) ;
F_44 ( & V_17 -> V_48 , F_66 ) ;
F_137 ( & V_17 -> V_110 , F_67 ) ;
F_138 ( V_11 ) ;
F_139 ( & V_11 -> V_107 ) ;
V_17 -> V_226 = V_11 -> V_65 ;
V_17 -> V_227 = V_11 -> V_147 ;
V_17 -> V_228 = V_11 -> V_229 ;
V_11 -> V_108 = V_17 ;
V_11 -> V_65 = F_59 ;
V_11 -> V_147 = F_69 ;
V_11 -> V_229 = F_68 ;
F_140 ( & V_11 -> V_107 ) ;
F_8 ( & V_24 -> V_25 ) ;
V_66 = & V_24 -> V_230 ;
F_131 (tpsock, &mux->psocks, psock_list) {
if ( V_218 -> V_208 != V_208 )
break;
V_66 = & V_218 -> V_120 ;
V_208 ++ ;
}
F_132 ( & V_17 -> V_120 , V_66 ) ;
V_17 -> V_208 = V_208 ;
F_6 ( V_24 -> V_20 . V_231 ) ;
V_24 -> V_121 ++ ;
F_73 ( V_17 ) ;
F_9 ( & V_24 -> V_25 ) ;
F_12 ( V_30 , & V_17 -> V_48 ) ;
return 0 ;
}
static int F_141 ( struct V_150 * V_2 , struct F_134 * V_232 )
{
struct V_150 * V_216 ;
struct V_97 * V_217 ;
int V_12 ;
V_216 = F_142 ( V_232 -> V_233 , & V_12 ) ;
if ( ! V_216 )
return - V_234 ;
V_217 = F_143 ( V_232 -> V_235 ) ;
if ( F_144 ( V_217 ) ) {
V_12 = F_145 ( V_217 ) ;
goto V_109;
}
if ( V_217 -> type != V_236 ) {
F_146 ( V_217 ) ;
V_12 = - V_93 ;
goto V_109;
}
V_12 = F_134 ( V_2 , V_216 , V_217 ) ;
if ( V_12 ) {
F_146 ( V_217 ) ;
goto V_109;
}
return 0 ;
V_109:
F_75 ( V_216 -> V_123 ) ;
return V_12 ;
}
static void F_147 ( struct V_16 * V_17 )
{
struct V_2 * V_11 = V_17 -> V_3 ;
struct V_23 * V_24 = V_17 -> V_24 ;
F_139 ( & V_11 -> V_107 ) ;
V_11 -> V_108 = NULL ;
V_11 -> V_65 = V_17 -> V_226 ;
V_11 -> V_147 = V_17 -> V_227 ;
V_11 -> V_229 = V_17 -> V_228 ;
V_17 -> V_19 = 1 ;
if ( F_21 ( V_17 -> V_69 ) ) {
F_140 ( & V_11 -> V_107 ) ;
return;
}
F_8 ( & V_24 -> V_55 ) ;
if ( V_17 -> V_47 ) {
F_10 ( & V_17 -> V_46 ) ;
F_51 ( V_17 -> V_47 ) ;
V_17 -> V_47 = NULL ;
F_6 ( V_24 -> V_20 . V_237 ) ;
}
F_9 ( & V_24 -> V_55 ) ;
F_140 ( & V_11 -> V_107 ) ;
F_148 ( & V_17 -> V_18 ) ;
F_149 ( & V_17 -> V_48 ) ;
F_150 ( & V_17 -> V_110 ) ;
F_146 ( V_17 -> V_97 ) ;
F_51 ( V_17 -> V_86 ) ;
V_17 -> V_86 = NULL ;
F_8 ( & V_24 -> V_25 ) ;
F_151 ( & V_17 -> V_20 , & V_24 -> F_151 ) ;
F_6 ( V_24 -> V_20 . V_238 ) ;
if ( V_17 -> V_28 ) {
F_6 ( V_24 -> V_20 . V_239 ) ;
F_9 ( & V_24 -> V_25 ) ;
F_7 ( V_17 , V_14 , false ) ;
F_8 ( & V_24 -> V_25 ) ;
if ( ! V_17 -> V_28 ) {
goto V_240;
}
V_17 -> V_74 = 1 ;
F_11 () ;
F_12 ( V_30 , & V_17 -> V_28 -> V_31 ) ;
F_9 ( & V_24 -> V_25 ) ;
} else {
V_240:
if ( ! V_17 -> V_26 )
F_10 ( & V_17 -> V_29 ) ;
F_10 ( & V_17 -> V_120 ) ;
V_24 -> V_121 -- ;
F_9 ( & V_24 -> V_25 ) ;
F_74 ( V_11 ) ;
F_75 ( V_11 -> V_122 -> V_123 ) ;
F_76 ( V_124 , V_17 ) ;
}
}
static int F_152 ( struct V_150 * V_2 , struct F_147 * V_232 )
{
struct V_1 * V_40 = F_1 ( V_2 -> V_3 ) ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_16 * V_17 ;
struct V_150 * V_216 ;
struct V_2 * V_11 ;
int V_12 ;
V_216 = F_142 ( V_232 -> V_233 , & V_12 ) ;
if ( ! V_216 )
return - V_234 ;
V_11 = V_216 -> V_3 ;
if ( ! V_11 ) {
V_12 = - V_93 ;
goto V_109;
}
V_12 = - V_234 ;
F_8 ( & V_24 -> V_25 ) ;
F_131 (psock, &mux->psocks, psock_list) {
if ( V_17 -> V_3 != V_11 )
continue;
if ( V_17 -> V_241 || F_21 ( V_17 -> V_74 ) ) {
V_12 = - V_242 ;
break;
}
V_17 -> V_241 = 1 ;
F_9 ( & V_24 -> V_25 ) ;
F_147 ( V_17 ) ;
V_12 = 0 ;
goto V_109;
}
F_9 ( & V_24 -> V_25 ) ;
V_109:
F_75 ( V_216 -> V_123 ) ;
return V_12 ;
}
static int F_153 ( struct V_150 * V_243 , struct F_153 * V_232 ,
struct V_150 * * V_244 )
{
struct V_150 * V_245 ;
struct V_2 * V_246 ;
struct V_123 * V_247 ;
int V_12 , V_248 ;
V_12 = - V_249 ;
V_245 = F_154 () ;
if ( ! V_245 )
goto V_109;
V_245 -> type = V_243 -> type ;
V_245 -> V_219 = V_243 -> V_219 ;
F_155 ( V_245 -> V_219 -> V_250 ) ;
V_248 = F_156 ( 0 ) ;
if ( F_17 ( V_248 < 0 ) ) {
V_12 = V_248 ;
goto V_251;
}
V_247 = F_157 ( V_245 , 0 , V_243 -> V_3 -> V_252 -> V_253 ) ;
if ( F_17 ( F_144 ( V_247 ) ) ) {
V_12 = F_145 ( V_247 ) ;
goto V_254;
}
V_246 = F_158 ( F_159 ( V_243 -> V_3 ) , V_255 , V_225 ,
& V_256 , true ) ;
if ( ! V_246 ) {
V_12 = - V_60 ;
goto V_257;
}
F_160 ( V_245 , V_246 ) ;
F_130 ( F_1 ( V_246 ) , F_1 ( V_243 -> V_3 ) -> V_24 ) ;
F_161 ( V_248 , V_247 ) ;
* V_244 = V_245 ;
V_232 -> V_233 = V_248 ;
return 0 ;
V_257:
F_75 ( V_247 ) ;
V_254:
F_162 ( V_248 ) ;
V_251:
F_163 ( V_245 ) ;
V_109:
return V_12 ;
}
static int F_164 ( struct V_150 * V_2 , unsigned int V_258 , unsigned long V_80 )
{
int V_12 ;
switch ( V_258 ) {
case V_259 : {
struct F_134 V_232 ;
if ( F_165 ( & V_232 , ( void T_6 * ) V_80 , sizeof( V_232 ) ) )
V_12 = - V_205 ;
V_12 = F_141 ( V_2 , & V_232 ) ;
break;
}
case V_260 : {
struct F_147 V_232 ;
if ( F_165 ( & V_232 , ( void T_6 * ) V_80 , sizeof( V_232 ) ) )
V_12 = - V_205 ;
V_12 = F_152 ( V_2 , & V_232 ) ;
break;
}
case V_261 : {
struct F_153 V_232 ;
struct V_150 * V_245 = NULL ;
if ( F_165 ( & V_232 , ( void T_6 * ) V_80 , sizeof( V_232 ) ) )
V_12 = - V_205 ;
V_12 = F_153 ( V_2 , & V_232 , & V_245 ) ;
if ( ! V_12 ) {
if ( F_129 ( ( void T_6 * ) V_80 , & V_232 ,
sizeof( V_232 ) ) ) {
V_12 = - V_205 ;
F_163 ( V_245 ) ;
}
}
break;
}
default:
V_12 = - V_262 ;
break;
}
return V_12 ;
}
static void F_166 ( struct V_263 * V_264 )
{
struct V_23 * V_24 = F_42 ( V_264 ,
struct V_23 , V_264 ) ;
F_76 ( V_265 , V_24 ) ;
}
static void F_167 ( struct V_23 * V_24 )
{
struct V_266 * V_267 = V_24 -> V_267 ;
struct V_16 * V_17 , * V_268 ;
F_168 (psock, tmp_psock,
&mux->psocks, psock_list) {
if ( ! F_21 ( V_17 -> V_241 ) )
F_147 ( V_17 ) ;
}
if ( F_21 ( V_24 -> V_121 ) )
return;
F_169 ( & V_24 -> V_44 ) ;
F_170 ( & V_267 -> V_269 ) ;
F_171 ( & V_24 -> V_20 , & V_267 -> F_171 ) ;
F_151 ( & V_24 -> F_151 ,
& V_267 -> F_151 ) ;
F_172 ( & V_24 -> V_270 ) ;
V_267 -> V_105 -- ;
F_173 ( & V_267 -> V_269 ) ;
F_174 ( & V_24 -> V_264 , F_166 ) ;
}
static void F_41 ( struct V_1 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_2 * V_3 = & V_40 -> V_3 ;
int V_271 ;
F_8 ( & V_24 -> V_55 ) ;
if ( V_40 -> V_42 ) {
F_21 ( V_40 -> V_74 ) ;
V_40 -> V_43 = 1 ;
V_40 -> V_74 = 1 ;
F_9 ( & V_24 -> V_55 ) ;
return;
}
if ( V_40 -> V_41 ) {
F_10 ( & V_40 -> V_49 ) ;
V_40 -> V_41 = false ;
}
F_37 ( V_24 , & V_3 -> V_58 ) ;
F_9 ( & V_24 -> V_55 ) ;
if ( F_21 ( F_22 ( V_3 ) ) )
return;
F_8 ( & V_24 -> V_25 ) ;
F_10 ( & V_40 -> V_212 ) ;
V_24 -> V_213 -- ;
V_271 = V_24 -> V_213 ;
F_9 ( & V_24 -> V_25 ) ;
if ( ! V_271 ) {
F_167 ( V_24 ) ;
}
F_21 ( V_40 -> V_41 ) ;
F_74 ( & V_40 -> V_3 ) ;
}
static int F_175 ( struct V_150 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_40 ;
struct V_23 * V_24 ;
struct V_16 * V_17 ;
if ( ! V_3 )
return 0 ;
V_40 = F_1 ( V_3 ) ;
V_24 = V_40 -> V_24 ;
F_176 ( V_3 ) ;
F_51 ( V_40 -> V_158 ) ;
F_64 ( V_3 ) ;
F_169 ( & V_3 -> V_133 ) ;
F_65 ( V_3 ) ;
F_8 ( & V_24 -> V_25 ) ;
if ( V_40 -> V_114 ) {
F_10 ( & V_40 -> V_116 ) ;
V_40 -> V_114 = false ;
}
F_9 ( & V_24 -> V_25 ) ;
F_149 ( & V_40 -> V_31 ) ;
F_64 ( V_3 ) ;
V_17 = V_40 -> V_113 ;
if ( V_17 ) {
F_7 ( V_17 , V_14 , false ) ;
F_72 ( V_40 ) ;
}
F_65 ( V_3 ) ;
F_21 ( V_40 -> V_114 ) ;
F_21 ( V_40 -> V_113 ) ;
V_2 -> V_3 = NULL ;
F_41 ( V_40 ) ;
return 0 ;
}
static int F_177 ( struct V_272 * V_272 , struct V_150 * V_2 ,
int V_273 , int V_274 )
{
struct V_266 * V_267 = F_178 ( V_272 , V_275 ) ;
struct V_2 * V_3 ;
struct V_23 * V_24 ;
switch ( V_2 -> type ) {
case V_175 :
V_2 -> V_219 = & V_276 ;
break;
case V_184 :
V_2 -> V_219 = & V_277 ;
break;
default:
return - V_278 ;
}
if ( V_273 != V_279 )
return - V_280 ;
V_3 = F_158 ( V_272 , V_255 , V_225 , & V_256 , V_274 ) ;
if ( ! V_3 )
return - V_60 ;
V_24 = F_135 ( V_265 , V_225 ) ;
if ( ! V_24 ) {
F_179 ( V_3 ) ;
return - V_60 ;
}
F_180 ( & V_24 -> V_25 ) ;
F_180 ( & V_24 -> V_55 ) ;
F_181 ( & V_24 -> V_211 ) ;
F_181 ( & V_24 -> V_50 ) ;
F_181 ( & V_24 -> V_118 ) ;
F_181 ( & V_24 -> V_230 ) ;
F_181 ( & V_24 -> V_45 ) ;
F_181 ( & V_24 -> V_115 ) ;
V_24 -> V_267 = V_267 ;
F_170 ( & V_267 -> V_269 ) ;
F_182 ( & V_24 -> V_270 , & V_267 -> V_281 ) ;
V_267 -> V_105 ++ ;
F_173 ( & V_267 -> V_269 ) ;
F_183 ( & V_24 -> V_44 ) ;
F_160 ( V_2 , V_3 ) ;
F_130 ( F_1 ( V_3 ) , V_24 ) ;
return 0 ;
}
static T_7 int F_184 ( struct V_272 * V_272 )
{
struct V_266 * V_267 = F_178 ( V_272 , V_275 ) ;
F_185 ( & V_267 -> V_281 ) ;
F_186 ( & V_267 -> V_269 ) ;
return 0 ;
}
static T_8 void F_187 ( struct V_272 * V_272 )
{
struct V_266 * V_267 = F_178 ( V_272 , V_275 ) ;
F_21 ( ! F_23 ( & V_267 -> V_281 ) ) ;
}
static int T_9 F_188 ( void )
{
int V_12 = - V_60 ;
V_265 = F_189 ( L_3 ,
sizeof( struct V_23 ) , 0 ,
V_282 | V_283 , NULL ) ;
if ( ! V_265 )
goto V_284;
V_124 = F_189 ( L_4 ,
sizeof( struct V_16 ) , 0 ,
V_282 | V_283 , NULL ) ;
if ( ! V_124 )
goto V_284;
V_30 = F_190 ( L_5 ) ;
if ( ! V_30 )
goto V_284;
V_12 = F_191 ( & V_256 , 1 ) ;
if ( V_12 )
goto V_284;
V_12 = F_192 ( & V_285 ) ;
if ( V_12 )
goto V_286;
V_12 = F_193 ( & V_287 ) ;
if ( V_12 )
goto V_288;
V_12 = F_194 () ;
if ( V_12 )
goto V_289;
return 0 ;
V_289:
F_195 ( & V_287 ) ;
V_288:
F_196 ( V_255 ) ;
V_286:
F_197 ( & V_256 ) ;
V_284:
F_198 ( V_265 ) ;
F_198 ( V_124 ) ;
if ( V_30 )
F_199 ( V_30 ) ;
return V_12 ;
}
static void T_10 F_200 ( void )
{
F_201 () ;
F_195 ( & V_287 ) ;
F_196 ( V_255 ) ;
F_197 ( & V_256 ) ;
F_199 ( V_30 ) ;
F_198 ( V_265 ) ;
F_198 ( V_124 ) ;
}
