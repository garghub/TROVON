static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static inline struct V_4 * V_4 ( struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 -> V_7 ;
}
static void F_2 ( struct V_2 * V_8 , int V_9 )
{
V_8 -> V_10 = V_11 ;
V_8 -> V_12 ( V_8 ) ;
}
static void F_3 ( struct V_13 * V_14 , int V_9 ,
bool V_15 )
{
struct V_2 * V_8 = V_14 -> V_3 ;
struct V_16 * V_17 = V_14 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
if ( V_14 -> V_19 ) {
F_5 ( & V_17 -> V_18 ) ;
return;
}
V_14 -> V_19 = 1 ;
F_6 ( V_14 -> V_20 . V_21 ) ;
if ( ! V_14 -> V_22 ) {
F_7 ( & V_14 -> V_23 ) ;
} else if ( V_15 ) {
F_8 () ;
F_9 ( V_24 , & V_14 -> V_22 -> V_25 ) ;
}
F_5 ( & V_17 -> V_18 ) ;
F_2 ( V_8 , V_9 ) ;
}
static void F_10 ( struct V_16 * V_17 ,
struct V_13 * V_14 )
{
F_11 ( V_17 -> V_20 . V_26 ,
V_14 -> V_27 . V_20 . V_28 -
V_14 -> V_29 ) ;
V_17 -> V_20 . V_30 +=
V_14 -> V_27 . V_20 . V_31 - V_14 -> V_32 ;
V_14 -> V_32 = V_14 -> V_27 . V_20 . V_31 ;
V_14 -> V_29 = V_14 -> V_27 . V_20 . V_28 ;
}
static void F_12 ( struct V_16 * V_17 ,
struct V_13 * V_14 )
{
F_13 ( V_17 -> V_20 . V_33 ,
V_14 -> V_20 . V_33 - V_14 -> V_34 ) ;
V_17 -> V_20 . V_35 +=
V_14 -> V_20 . V_35 - V_14 -> V_36 ;
V_14 -> V_36 = V_14 -> V_20 . V_35 ;
V_14 -> V_34 = V_14 -> V_20 . V_33 ;
}
static void F_14 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
struct V_13 * V_14 ;
struct V_5 * V_6 ;
if ( F_15 ( V_37 -> V_38 || V_37 -> V_39 || V_37 -> V_40 ) )
return;
while ( F_15 ( ( V_6 = F_16 ( & V_17 -> V_41 ) ) ) ) {
if ( F_17 ( & V_37 -> V_3 , V_6 ) ) {
F_18 ( & V_17 -> V_41 , V_6 ) ;
F_19 ( ! F_20 ( & V_37 -> V_3 ) ) ;
return;
}
}
while ( ! F_21 ( & V_17 -> V_42 ) ) {
V_14 = F_22 ( & V_17 -> V_42 , struct V_13 ,
V_43 ) ;
if ( F_17 ( & V_37 -> V_3 , V_14 -> V_44 ) ) {
F_19 ( ! F_20 ( & V_37 -> V_3 ) ) ;
return;
}
F_7 ( & V_14 -> V_43 ) ;
V_14 -> V_44 = NULL ;
F_8 () ;
F_23 ( & V_14 -> V_27 ) ;
F_24 ( & V_14 -> V_27 ) ;
}
F_25 ( & V_37 -> V_45 ,
& V_37 -> V_17 -> V_46 ) ;
V_37 -> V_38 = true ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_37 -> V_17 ;
unsigned int V_47 = V_6 -> V_48 ;
F_27 ( V_3 , V_47 ) ;
F_28 ( V_47 , & V_3 -> V_49 ) ;
F_29 () ;
if ( ! V_37 -> V_38 && ! V_37 -> V_39 &&
F_20 ( V_3 ) < V_3 -> V_50 ) {
F_4 ( & V_17 -> V_51 ) ;
F_14 ( V_37 ) ;
F_5 ( & V_17 -> V_51 ) ;
}
}
static int F_17 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_52 * V_53 = & V_3 -> V_54 ;
if ( F_30 ( & V_3 -> V_49 ) >= V_3 -> V_55 )
return - V_56 ;
if ( ! F_31 ( V_3 , V_6 , V_6 -> V_48 ) )
return - V_57 ;
V_6 -> V_58 = NULL ;
F_32 ( V_6 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_59 = F_26 ;
F_33 ( V_6 -> V_48 , & V_3 -> V_49 ) ;
F_34 ( V_3 , V_6 -> V_48 ) ;
F_35 ( V_53 , V_6 ) ;
if ( ! F_36 ( V_3 , V_60 ) )
V_3 -> V_61 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_16 * V_17 , struct V_52 * V_62 )
{
struct V_5 * V_6 ;
struct V_1 * V_37 ;
while ( ( V_6 = F_16 ( V_62 ) ) ) {
V_6 -> V_59 = V_63 ;
F_32 ( V_6 ) ;
V_64:
if ( F_21 ( & V_17 -> V_46 ) ) {
F_35 ( & V_17 -> V_41 , V_6 ) ;
continue;
}
V_37 = F_22 ( & V_17 -> V_46 ,
struct V_1 , V_45 ) ;
if ( F_17 ( & V_37 -> V_3 , V_6 ) ) {
F_7 ( & V_37 -> V_45 ) ;
V_37 -> V_38 = false ;
F_38 () ;
goto V_64;
}
}
}
static struct V_1 * F_39 ( struct V_13 * V_14 ,
struct V_5 * V_62 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_1 * V_37 ;
F_19 ( V_14 -> V_44 ) ;
if ( V_14 -> V_65 )
return V_14 -> V_65 ;
F_4 ( & V_17 -> V_51 ) ;
if ( V_14 -> V_65 ) {
F_5 ( & V_17 -> V_51 ) ;
return V_14 -> V_65 ;
}
F_10 ( V_17 , V_14 ) ;
if ( F_21 ( & V_17 -> V_46 ) ) {
V_14 -> V_44 = V_62 ;
F_40 ( & V_14 -> V_27 ) ;
F_25 ( & V_14 -> V_43 ,
& V_17 -> V_42 ) ;
F_5 ( & V_17 -> V_51 ) ;
return NULL ;
}
V_37 = F_22 ( & V_17 -> V_46 ,
struct V_1 , V_45 ) ;
F_7 ( & V_37 -> V_45 ) ;
V_37 -> V_38 = false ;
V_14 -> V_65 = V_37 ;
V_37 -> V_39 = V_14 ;
F_5 ( & V_17 -> V_51 ) ;
return V_37 ;
}
static void F_41 ( struct V_66 * V_67 )
{
F_42 ( F_43 ( V_67 , struct V_1 , V_68 ) ) ;
}
static void F_44 ( struct V_13 * V_14 ,
bool V_69 )
{
struct V_1 * V_37 = V_14 -> V_65 ;
struct V_16 * V_17 = V_14 -> V_17 ;
if ( ! V_37 )
return;
F_4 ( & V_17 -> V_51 ) ;
V_14 -> V_65 = NULL ;
V_37 -> V_39 = NULL ;
F_8 () ;
if ( F_15 ( V_37 -> V_70 ) ) {
F_5 ( & V_17 -> V_51 ) ;
F_45 ( & V_37 -> V_68 , F_41 ) ;
F_46 ( & V_37 -> V_68 ) ;
return;
}
if ( F_15 ( V_37 -> V_40 ) ) {
F_37 ( V_17 , & V_37 -> V_3 . V_54 ) ;
} else if ( V_69 || F_15 ( ! F_20 ( & V_37 -> V_3 ) ) ) {
F_14 ( V_37 ) ;
}
F_5 ( & V_17 -> V_51 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
F_48 ( & V_3 -> V_71 ) ;
V_14 = (struct V_13 * ) V_3 -> V_72 ;
if ( F_49 ( V_14 ) )
F_50 ( & V_14 -> V_27 ) ;
F_51 ( & V_3 -> V_71 ) ;
}
static void F_52 ( struct V_73 * V_27 , struct V_5 * V_6 )
{
struct V_13 * V_14 = F_43 ( V_27 , struct V_13 , V_27 ) ;
struct V_1 * V_37 ;
V_74:
V_37 = F_39 ( V_14 , V_6 ) ;
if ( ! V_37 ) {
return;
}
if ( F_17 ( & V_37 -> V_3 , V_6 ) ) {
F_44 ( V_14 , false ) ;
goto V_74;
}
}
static int F_53 ( struct V_73 * V_27 , struct V_5 * V_6 )
{
struct V_13 * V_14 = F_43 ( V_27 , struct V_13 , V_27 ) ;
struct V_75 * V_76 = V_14 -> V_75 ;
return (* V_76 -> V_77 )( V_6 , V_76 -> V_78 ) ;
}
static int F_54 ( struct V_73 * V_27 , int V_9 )
{
struct V_13 * V_14 = F_43 ( V_27 , struct V_13 , V_27 ) ;
F_44 ( V_14 , true ) ;
return V_9 ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_2 ( V_3 , V_11 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 ;
struct V_1 * V_37 ;
F_48 ( & V_3 -> V_71 ) ;
V_14 = (struct V_13 * ) V_3 -> V_72 ;
if ( F_15 ( ! V_14 ) )
goto V_79;
V_17 = V_14 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_37 = V_14 -> V_22 ;
if ( V_37 && ! F_15 ( V_37 -> V_19 ) )
F_9 ( V_24 , & V_37 -> V_25 ) ;
F_5 ( & V_17 -> V_18 ) ;
V_79:
F_51 ( & V_3 -> V_71 ) ;
}
static struct V_13 * F_57 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
struct V_13 * V_14 ;
V_14 = V_37 -> V_80 ;
F_58 () ;
if ( V_14 ) {
F_19 ( V_37 -> V_81 ) ;
if ( F_15 ( V_14 -> V_19 ) )
F_59 ( V_37 ) ;
else
return V_37 -> V_80 ;
}
F_4 ( & V_17 -> V_18 ) ;
V_14 = V_37 -> V_80 ;
if ( F_15 ( V_14 ) ) {
F_19 ( V_37 -> V_81 ) ;
F_5 ( & V_17 -> V_18 ) ;
return V_37 -> V_80 ;
}
if ( ! F_21 ( & V_17 -> V_82 ) ) {
V_14 = F_22 ( & V_17 -> V_82 ,
struct V_13 ,
V_23 ) ;
F_7 ( & V_14 -> V_23 ) ;
if ( V_37 -> V_81 ) {
F_7 ( & V_37 -> V_83 ) ;
V_37 -> V_81 = false ;
}
V_37 -> V_80 = V_14 ;
V_14 -> V_22 = V_37 ;
F_6 ( V_14 -> V_20 . V_84 ) ;
} else if ( ! V_37 -> V_81 ) {
F_25 ( & V_37 -> V_83 ,
& V_17 -> V_85 ) ;
V_37 -> V_81 = true ;
}
F_5 ( & V_17 -> V_18 ) ;
return V_14 ;
}
static void F_60 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_1 * V_37 ;
if ( F_21 ( & V_17 -> V_85 ) ) {
F_25 ( & V_14 -> V_23 ,
& V_17 -> V_82 ) ;
} else {
V_37 = F_22 ( & V_17 -> V_85 ,
struct V_1 ,
V_83 ) ;
F_7 ( & V_37 -> V_83 ) ;
V_37 -> V_81 = false ;
V_14 -> V_22 = V_37 ;
F_8 () ;
V_37 -> V_80 = V_14 ;
F_6 ( V_14 -> V_20 . V_84 ) ;
F_9 ( V_24 , & V_37 -> V_25 ) ;
}
}
static void F_59 ( struct V_1 * V_37 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 = V_37 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_14 = V_37 -> V_80 ;
if ( F_19 ( ! V_14 ) ) {
F_5 ( & V_17 -> V_18 ) ;
return;
}
F_58 () ;
F_12 ( V_17 , V_14 ) ;
F_19 ( V_37 -> V_81 ) ;
V_37 -> V_80 = NULL ;
V_14 -> V_22 = NULL ;
F_6 ( V_14 -> V_20 . V_86 ) ;
if ( F_15 ( V_14 -> V_19 ) ) {
if ( V_14 -> V_70 ) {
F_7 ( & V_14 -> V_87 ) ;
V_17 -> V_88 -- ;
F_61 ( V_14 -> V_3 ) ;
F_62 ( V_14 -> V_3 -> V_89 -> V_90 ) ;
F_63 ( V_91 , V_14 ) ;
}
F_5 ( & V_17 -> V_18 ) ;
return;
}
F_60 ( V_14 ) ;
F_5 ( & V_17 -> V_18 ) ;
}
static void F_64 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
F_6 ( V_17 -> V_20 . V_92 ) ;
F_5 ( & V_17 -> V_18 ) ;
}
static int F_65 ( struct V_1 * V_37 )
{
struct V_2 * V_3 = & V_37 -> V_3 ;
struct V_13 * V_14 ;
struct V_5 * V_6 , * V_62 ;
struct V_4 * V_93 ;
unsigned short V_94 , V_95 ;
unsigned int V_96 , V_97 = 0 ;
int V_98 = 0 ;
V_37 -> V_99 = false ;
V_14 = V_37 -> V_80 ;
if ( F_15 ( V_14 && V_14 -> V_19 ) ) {
F_59 ( V_37 ) ;
F_64 ( V_37 ) ;
if ( F_66 ( & V_3 -> V_100 ) )
return 0 ;
V_4 ( F_67 ( & V_3 -> V_100 ) ) -> V_96 = 0 ;
} else if ( F_66 ( & V_3 -> V_100 ) ) {
return 0 ;
}
V_62 = F_67 ( & V_3 -> V_100 ) ;
V_93 = V_4 ( V_62 ) ;
if ( V_93 -> V_96 ) {
if ( F_19 ( ! V_14 ) ) {
V_98 = - V_101 ;
goto V_79;
}
V_96 = V_93 -> V_96 ;
V_95 = V_93 -> V_95 ;
V_94 = V_93 -> V_94 ;
V_6 = V_93 -> V_102 ;
goto V_103;
}
V_64:
V_14 = F_57 ( V_37 ) ;
if ( ! V_14 )
goto V_79;
do {
V_6 = V_62 ;
V_93 = V_4 ( V_62 ) ;
V_96 = 0 ;
V_104:
if ( F_19 ( ! F_68 ( V_6 ) -> V_105 ) ) {
V_98 = - V_101 ;
goto V_79;
}
for ( V_94 = 0 ; V_94 < F_68 ( V_6 ) -> V_105 ;
V_94 ++ ) {
T_1 * V_106 ;
V_95 = 0 ;
V_103:
V_106 = & F_68 ( V_6 ) -> V_107 [ V_94 ] ;
if ( F_19 ( ! V_106 -> V_108 ) ) {
V_98 = - V_101 ;
goto V_79;
}
V_98 = F_69 ( V_14 -> V_3 -> V_89 ,
V_106 -> V_109 . V_110 ,
V_106 -> V_111 + V_95 ,
V_106 -> V_108 - V_95 ,
V_112 ) ;
if ( V_98 <= 0 ) {
if ( V_98 == - V_113 ) {
V_93 -> V_96 = V_96 ;
V_93 -> V_95 = V_95 ;
V_93 -> V_94 = V_94 ;
V_93 -> V_102 = V_6 ;
V_98 = 0 ;
goto V_79;
}
F_3 ( V_14 , V_98 ? - V_98 : V_11 ,
true ) ;
F_59 ( V_37 ) ;
V_93 -> V_96 = 0 ;
F_64 ( V_37 ) ;
V_98 = 0 ;
goto V_64;
}
V_96 += V_98 ;
V_95 += V_98 ;
F_13 ( V_14 -> V_20 . V_33 , V_98 ) ;
if ( V_95 < V_106 -> V_108 ) {
goto V_103;
}
}
if ( V_6 == V_62 ) {
if ( F_70 ( V_6 ) ) {
V_6 = F_68 ( V_6 ) -> V_114 ;
goto V_104;
}
} else if ( V_6 -> V_115 ) {
V_6 = V_6 -> V_115 ;
goto V_104;
}
F_71 ( & V_3 -> V_100 ) ;
F_72 ( V_62 ) ;
V_3 -> V_116 -= V_96 ;
V_97 += V_96 ;
F_6 ( V_14 -> V_20 . V_35 ) ;
} while ( ( V_62 = F_67 ( & V_3 -> V_100 ) ) );
V_79:
if ( ! V_62 ) {
F_19 ( ! F_66 ( & V_3 -> V_100 ) ) ;
F_59 ( V_37 ) ;
}
V_3 -> V_117 ( V_3 ) ;
return V_97 ? : V_98 ;
}
static void F_73 ( struct V_66 * V_67 )
{
struct V_1 * V_37 = F_43 ( V_67 , struct V_1 , V_25 ) ;
struct V_2 * V_3 = & V_37 -> V_3 ;
int V_9 ;
F_74 ( V_3 ) ;
V_9 = F_65 ( V_37 ) ;
if ( V_9 < 0 ) {
F_75 ( L_1 , V_9 ) ;
F_2 ( & V_37 -> V_3 , - V_9 ) ;
goto V_79;
}
if ( F_49 ( V_3 -> V_89 ) &&
F_76 ( V_118 , & V_3 -> V_89 -> V_119 ) ) {
F_77 ( V_118 , & V_3 -> V_89 -> V_119 ) ;
V_3 -> V_117 ( V_3 ) ;
}
V_79:
F_78 ( V_3 ) ;
}
static void F_79 ( struct V_1 * V_37 )
{
if ( V_37 -> V_99 )
F_65 ( V_37 ) ;
}
static T_2 F_80 ( struct V_120 * V_2 , struct V_109 * V_109 ,
int V_121 , T_3 V_108 , int V_119 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_62 = NULL ;
long V_122 = F_81 ( V_3 , V_119 & V_112 ) ;
bool V_123 ;
int V_9 = 0 ;
int V_124 ;
if ( V_119 & V_125 )
V_119 |= V_126 ;
V_123 = ! ( V_119 & V_126 ) ;
F_74 ( V_3 ) ;
F_82 ( V_127 , V_3 ) ;
V_9 = - V_11 ;
if ( V_3 -> V_10 )
goto V_128;
if ( V_37 -> V_129 ) {
V_62 = V_37 -> V_129 ;
V_6 = V_4 ( V_62 ) -> V_130 ;
V_124 = F_68 ( V_6 ) -> V_105 ;
if ( F_83 ( V_6 , V_124 , V_109 , V_121 ) ) {
F_84 ( & F_68 ( V_6 ) -> V_107 [ V_124 - 1 ] , V_108 ) ;
F_68 ( V_6 ) -> V_131 |= V_132 ;
goto V_133;
}
if ( V_124 >= V_134 ) {
struct V_5 * V_135 ;
V_135 = F_85 ( 0 , V_3 -> V_136 ) ;
while ( ! V_135 ) {
F_79 ( V_37 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
}
if ( V_62 == V_6 )
F_68 ( V_62 ) -> V_114 = V_135 ;
else
V_6 -> V_115 = V_135 ;
V_6 = V_135 ;
V_6 -> V_137 = V_138 ;
V_124 = 0 ;
}
} else {
if ( ! F_87 ( V_3 ) ) {
F_79 ( V_37 ) ;
F_88 ( V_118 , & V_3 -> V_89 -> V_119 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
}
V_62 = F_85 ( 0 , V_3 -> V_136 ) ;
while ( ! V_62 ) {
F_79 ( V_37 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
}
V_6 = V_62 ;
V_124 = 0 ;
}
F_89 ( V_109 ) ;
F_90 ( V_6 , V_124 , V_109 , V_121 , V_108 ) ;
F_68 ( V_6 ) -> V_131 |= V_132 ;
V_133:
V_6 -> V_47 += V_108 ;
V_6 -> V_139 += V_108 ;
V_6 -> V_48 += V_108 ;
V_3 -> V_116 += V_108 ;
F_34 ( V_3 , V_108 ) ;
if ( V_62 != V_6 ) {
V_62 -> V_47 += V_108 ;
V_62 -> V_139 += V_108 ;
V_62 -> V_48 += V_108 ;
}
if ( V_123 ) {
bool V_140 = F_66 ( & V_3 -> V_100 ) ;
F_91 ( & V_3 -> V_100 , V_62 ) ;
V_37 -> V_129 = NULL ;
F_6 ( V_37 -> V_20 . V_35 ) ;
if ( V_119 & V_141 ) {
V_37 -> V_99 = true ;
} else if ( V_37 -> V_99 || V_140 ) {
V_9 = F_65 ( V_37 ) ;
if ( V_9 < 0 ) {
F_75 ( L_2 ) ;
F_2 ( & V_37 -> V_3 , - V_9 ) ;
}
}
} else {
V_37 -> V_129 = V_62 ;
V_4 ( V_62 ) -> V_130 = V_6 ;
}
F_13 ( V_37 -> V_20 . V_33 , V_108 ) ;
F_78 ( V_3 ) ;
return V_108 ;
V_128:
F_79 ( V_37 ) ;
V_9 = F_92 ( V_3 , V_119 , V_9 ) ;
if ( F_15 ( F_93 ( & V_3 -> V_100 ) == 0 && V_9 == - V_113 ) )
V_3 -> V_117 ( V_3 ) ;
F_78 ( V_3 ) ;
return V_9 ;
}
static int F_94 ( struct V_120 * V_2 , struct V_142 * V_143 , T_3 V_47 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_62 = NULL ;
T_3 V_144 , V_145 = 0 ;
long V_122 = F_81 ( V_3 , V_143 -> V_146 & V_112 ) ;
int V_123 = ( V_2 -> type == V_147 ) ?
! ( V_143 -> V_146 & V_126 ) : ! ! ( V_143 -> V_146 & V_148 ) ;
int V_9 = - V_11 ;
F_74 ( V_3 ) ;
F_82 ( V_127 , V_3 ) ;
if ( V_3 -> V_10 )
goto V_128;
if ( V_37 -> V_129 ) {
V_62 = V_37 -> V_129 ;
V_6 = V_4 ( V_62 ) -> V_130 ;
goto V_149;
}
if ( ! F_87 ( V_3 ) ) {
F_79 ( V_37 ) ;
F_88 ( V_118 , & V_3 -> V_89 -> V_119 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
}
if ( F_95 ( V_143 ) ) {
V_62 = F_85 ( 0 , V_3 -> V_136 ) ;
while ( ! V_62 ) {
F_79 ( V_37 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
V_62 = F_85 ( 0 , V_3 -> V_136 ) ;
}
V_6 = V_62 ;
V_6 -> V_137 = V_138 ;
}
V_149:
while ( F_95 ( V_143 ) ) {
bool V_150 = true ;
int V_124 = F_68 ( V_6 ) -> V_105 ;
struct V_151 * V_152 = F_96 ( V_3 ) ;
if ( ! F_97 ( V_3 , V_152 ) )
goto V_153;
if ( ! F_83 ( V_6 , V_124 , V_152 -> V_109 ,
V_152 -> V_121 ) ) {
if ( V_124 == V_134 ) {
struct V_5 * V_135 ;
V_135 = F_85 ( 0 , V_3 -> V_136 ) ;
if ( ! V_135 )
goto V_153;
if ( V_62 == V_6 )
F_68 ( V_62 ) -> V_114 = V_135 ;
else
V_6 -> V_115 = V_135 ;
V_6 = V_135 ;
V_6 -> V_137 = V_138 ;
continue;
}
V_150 = false ;
}
V_144 = F_98 ( int , F_95 ( V_143 ) ,
V_152 -> V_108 - V_152 -> V_121 ) ;
if ( ! F_99 ( V_3 , V_144 ) )
goto V_153;
V_9 = F_100 ( V_3 , & V_143 -> V_154 , V_6 ,
V_152 -> V_109 ,
V_152 -> V_121 ,
V_144 ) ;
if ( V_9 )
goto V_128;
if ( V_150 ) {
F_84 ( & F_68 ( V_6 ) -> V_107 [ V_124 - 1 ] , V_144 ) ;
} else {
F_90 ( V_6 , V_124 , V_152 -> V_109 ,
V_152 -> V_121 , V_144 ) ;
F_89 ( V_152 -> V_109 ) ;
}
V_152 -> V_121 += V_144 ;
V_145 += V_144 ;
if ( V_62 != V_6 ) {
V_62 -> V_47 += V_144 ;
V_62 -> V_139 += V_144 ;
}
continue;
V_153:
F_79 ( V_37 ) ;
V_9 = F_86 ( V_3 , & V_122 ) ;
if ( V_9 )
goto V_128;
}
if ( V_123 ) {
bool V_140 = F_66 ( & V_3 -> V_100 ) ;
if ( V_62 ) {
F_91 ( & V_3 -> V_100 , V_62 ) ;
V_37 -> V_129 = NULL ;
F_6 ( V_37 -> V_20 . V_35 ) ;
}
if ( V_143 -> V_146 & V_141 ) {
V_37 -> V_99 = true ;
} else if ( V_37 -> V_99 || V_140 ) {
V_9 = F_65 ( V_37 ) ;
if ( V_9 < 0 ) {
F_75 ( L_2 ) ;
F_2 ( & V_37 -> V_3 , - V_9 ) ;
}
}
} else {
V_155:
if ( V_62 ) {
V_37 -> V_129 = V_62 ;
V_4 ( V_62 ) -> V_130 = V_6 ;
}
}
F_13 ( V_37 -> V_20 . V_33 , V_145 ) ;
F_78 ( V_3 ) ;
return V_145 ;
V_128:
F_79 ( V_37 ) ;
if ( V_145 && V_2 -> type == V_156 ) {
goto V_155;
}
if ( V_62 != V_37 -> V_129 )
F_72 ( V_62 ) ;
V_9 = F_92 ( V_3 , V_143 -> V_146 , V_9 ) ;
if ( F_15 ( F_93 ( & V_3 -> V_100 ) == 0 && V_9 == - V_113 ) )
V_3 -> V_117 ( V_3 ) ;
F_78 ( V_3 ) ;
return V_9 ;
}
static struct V_5 * F_101 ( struct V_2 * V_3 , int V_119 ,
long V_122 , int * V_9 )
{
struct V_5 * V_6 ;
while ( ! ( V_6 = F_67 ( & V_3 -> V_54 ) ) ) {
if ( V_3 -> V_10 ) {
* V_9 = F_102 ( V_3 ) ;
return NULL ;
}
if ( F_36 ( V_3 , V_157 ) )
return NULL ;
if ( ( V_119 & V_112 ) || ! V_122 ) {
* V_9 = - V_113 ;
return NULL ;
}
F_103 ( V_3 , & V_122 , NULL ) ;
if ( F_104 ( V_158 ) ) {
* V_9 = F_105 ( V_122 ) ;
return NULL ;
}
}
return V_6 ;
}
static int F_106 ( struct V_120 * V_2 , struct V_142 * V_143 ,
T_3 V_47 , int V_119 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
int V_9 = 0 ;
long V_122 ;
struct V_159 * V_160 ;
int V_145 = 0 ;
struct V_5 * V_6 ;
V_122 = F_107 ( V_3 , V_119 & V_112 ) ;
F_74 ( V_3 ) ;
V_6 = F_101 ( V_3 , V_119 , V_122 , & V_9 ) ;
if ( ! V_6 )
goto V_79;
V_160 = V_159 ( V_6 ) ;
if ( V_47 > V_160 -> V_161 )
V_47 = V_160 -> V_161 ;
V_9 = F_108 ( V_6 , V_160 -> V_121 , V_143 , V_47 ) ;
if ( V_9 < 0 )
goto V_79;
V_145 = V_47 ;
if ( F_49 ( ! ( V_119 & V_162 ) ) ) {
F_13 ( V_37 -> V_20 . V_26 , V_145 ) ;
if ( V_145 < V_160 -> V_161 ) {
if ( V_2 -> type == V_147 ) {
V_143 -> V_146 |= V_163 ;
goto V_164;
}
V_160 -> V_121 += V_145 ;
V_160 -> V_161 -= V_145 ;
} else {
V_164:
V_143 -> V_146 |= V_148 ;
F_6 ( V_37 -> V_20 . V_30 ) ;
F_109 ( V_6 , & V_3 -> V_54 ) ;
F_72 ( V_6 ) ;
}
}
V_79:
F_78 ( V_3 ) ;
return V_145 ? : V_9 ;
}
static T_2 F_110 ( struct V_120 * V_2 , T_4 * V_165 ,
struct V_166 * V_167 , T_3 V_47 ,
unsigned int V_119 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
long V_122 ;
struct V_159 * V_160 ;
int V_9 = 0 ;
T_2 V_145 ;
struct V_5 * V_6 ;
V_122 = F_107 ( V_3 , V_119 & V_112 ) ;
F_74 ( V_3 ) ;
V_6 = F_101 ( V_3 , V_119 , V_122 , & V_9 ) ;
if ( ! V_6 )
goto V_168;
V_160 = V_159 ( V_6 ) ;
if ( V_47 > V_160 -> V_161 )
V_47 = V_160 -> V_161 ;
V_145 = F_111 ( V_6 , V_3 , V_160 -> V_121 , V_167 , V_47 , V_119 ) ;
if ( V_145 < 0 ) {
V_9 = V_145 ;
goto V_168;
}
F_13 ( V_37 -> V_20 . V_26 , V_145 ) ;
V_160 -> V_121 += V_145 ;
V_160 -> V_161 -= V_145 ;
F_78 ( V_3 ) ;
return V_145 ;
V_168:
F_78 ( V_3 ) ;
return V_9 ;
}
static void F_112 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
if ( V_37 -> V_40 )
return;
F_4 ( & V_17 -> V_51 ) ;
V_37 -> V_40 = 1 ;
if ( ! V_37 -> V_39 ) {
if ( V_37 -> V_38 ) {
F_7 ( & V_37 -> V_45 ) ;
V_37 -> V_38 = false ;
}
F_37 ( V_17 , & V_37 -> V_3 . V_54 ) ;
}
F_5 ( & V_17 -> V_51 ) ;
}
static void F_113 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
if ( ! V_37 -> V_40 )
return;
F_4 ( & V_17 -> V_51 ) ;
V_37 -> V_40 = 0 ;
F_14 ( V_37 ) ;
F_5 ( & V_17 -> V_51 ) ;
}
static int F_114 ( struct V_120 * V_2 , int V_169 , int V_170 ,
char T_5 * V_171 , unsigned int V_172 )
{
struct V_1 * V_37 = F_1 ( V_2 -> V_3 ) ;
int V_173 , V_174 ;
int V_9 = 0 ;
if ( V_169 != V_175 )
return - V_176 ;
if ( V_172 < sizeof( int ) )
return - V_101 ;
if ( F_115 ( V_173 , ( int T_5 * ) V_171 ) )
return - V_101 ;
V_174 = V_173 ? 1 : 0 ;
switch ( V_170 ) {
case V_177 :
F_74 ( & V_37 -> V_3 ) ;
if ( V_174 )
F_112 ( V_37 ) ;
else
F_113 ( V_37 ) ;
F_78 ( & V_37 -> V_3 ) ;
break;
default:
V_9 = - V_176 ;
}
return V_9 ;
}
static int F_116 ( struct V_120 * V_2 , int V_169 , int V_170 ,
char T_5 * V_171 , int T_5 * V_172 )
{
struct V_1 * V_37 = F_1 ( V_2 -> V_3 ) ;
int V_173 , V_47 ;
if ( V_169 != V_175 )
return - V_176 ;
if ( F_115 ( V_47 , V_172 ) )
return - V_178 ;
V_47 = F_98 (unsigned int, len, sizeof(int)) ;
if ( V_47 < 0 )
return - V_101 ;
switch ( V_170 ) {
case V_177 :
V_173 = V_37 -> V_40 ;
break;
default:
return - V_176 ;
}
if ( F_117 ( V_47 , V_172 ) )
return - V_178 ;
if ( F_118 ( V_171 , & V_173 , V_47 ) )
return - V_178 ;
return 0 ;
}
static void F_119 ( struct V_1 * V_37 , struct V_16 * V_17 )
{
struct V_1 * V_179 ;
struct V_180 * V_62 ;
int V_181 = 0 ;
V_37 -> V_3 . V_182 = V_183 ;
V_37 -> V_17 = V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_62 = & V_17 -> V_184 ;
F_120 (tkcm, &mux->kcm_socks, kcm_sock_list) {
if ( V_179 -> V_181 != V_181 )
break;
V_62 = & V_179 -> V_185 ;
V_181 ++ ;
}
F_121 ( & V_37 -> V_185 , V_62 ) ;
V_37 -> V_181 = V_181 ;
V_17 -> V_186 ++ ;
F_5 ( & V_17 -> V_18 ) ;
F_45 ( & V_37 -> V_25 , F_73 ) ;
F_4 ( & V_17 -> V_51 ) ;
F_14 ( V_37 ) ;
F_5 ( & V_17 -> V_51 ) ;
}
static int F_122 ( struct V_120 * V_2 , struct V_120 * V_187 ,
struct V_75 * V_76 )
{
struct V_1 * V_37 = F_1 ( V_2 -> V_3 ) ;
struct V_16 * V_17 = V_37 -> V_17 ;
struct V_2 * V_8 ;
struct V_13 * V_14 = NULL , * V_188 ;
struct V_180 * V_62 ;
int V_181 = 0 ;
static const struct V_189 V_7 = {
. V_190 = F_52 ,
. V_191 = F_53 ,
. V_192 = F_54 ,
} ;
int V_9 ;
V_8 = V_187 -> V_3 ;
if ( ! V_8 )
return - V_101 ;
if ( V_8 -> V_193 == V_194 )
return - V_195 ;
V_14 = F_123 ( V_91 , V_196 ) ;
if ( ! V_14 )
return - V_56 ;
V_14 -> V_17 = V_17 ;
V_14 -> V_3 = V_8 ;
V_14 -> V_75 = V_76 ;
V_9 = F_124 ( & V_14 -> V_27 , V_8 , & V_7 ) ;
if ( V_9 ) {
F_63 ( V_91 , V_14 ) ;
return V_9 ;
}
F_125 ( V_8 ) ;
F_126 ( & V_8 -> V_71 ) ;
V_14 -> V_197 = V_8 -> V_61 ;
V_14 -> V_198 = V_8 -> V_117 ;
V_14 -> V_199 = V_8 -> V_200 ;
V_8 -> V_72 = V_14 ;
V_8 -> V_61 = F_47 ;
V_8 -> V_117 = F_56 ;
V_8 -> V_200 = F_55 ;
F_127 ( & V_8 -> V_71 ) ;
F_4 ( & V_17 -> V_18 ) ;
V_62 = & V_17 -> V_201 ;
F_120 (tpsock, &mux->psocks, psock_list) {
if ( V_188 -> V_181 != V_181 )
break;
V_62 = & V_188 -> V_87 ;
V_181 ++ ;
}
F_121 ( & V_14 -> V_87 , V_62 ) ;
V_14 -> V_181 = V_181 ;
F_6 ( V_17 -> V_20 . V_202 ) ;
V_17 -> V_88 ++ ;
F_60 ( V_14 ) ;
F_5 ( & V_17 -> V_18 ) ;
F_24 ( & V_14 -> V_27 ) ;
return 0 ;
}
static int F_128 ( struct V_120 * V_2 , struct F_122 * V_203 )
{
struct V_120 * V_187 ;
struct V_75 * V_76 ;
int V_9 ;
V_187 = F_129 ( V_203 -> V_204 , & V_9 ) ;
if ( ! V_187 )
return - V_205 ;
V_76 = F_130 ( V_203 -> V_206 , V_207 ) ;
if ( F_131 ( V_76 ) ) {
V_9 = F_132 ( V_76 ) ;
goto V_79;
}
V_9 = F_122 ( V_2 , V_187 , V_76 ) ;
if ( V_9 ) {
F_133 ( V_76 ) ;
goto V_79;
}
return 0 ;
V_79:
F_62 ( V_187 -> V_90 ) ;
return V_9 ;
}
static void F_134 ( struct V_13 * V_14 )
{
struct V_2 * V_8 = V_14 -> V_3 ;
struct V_16 * V_17 = V_14 -> V_17 ;
F_74 ( V_8 ) ;
F_126 ( & V_8 -> V_71 ) ;
V_8 -> V_72 = NULL ;
V_8 -> V_61 = V_14 -> V_197 ;
V_8 -> V_117 = V_14 -> V_198 ;
V_8 -> V_200 = V_14 -> V_199 ;
F_135 ( & V_14 -> V_27 ) ;
if ( F_19 ( V_14 -> V_65 ) ) {
F_127 ( & V_8 -> V_71 ) ;
return;
}
F_4 ( & V_17 -> V_51 ) ;
if ( V_14 -> V_44 ) {
F_7 ( & V_14 -> V_43 ) ;
F_72 ( V_14 -> V_44 ) ;
V_14 -> V_44 = NULL ;
F_6 ( V_17 -> V_20 . V_208 ) ;
}
F_5 ( & V_17 -> V_51 ) ;
F_127 ( & V_8 -> V_71 ) ;
F_78 ( V_8 ) ;
F_136 ( & V_14 -> V_27 ) ;
F_74 ( V_8 ) ;
F_133 ( V_14 -> V_75 ) ;
F_4 ( & V_17 -> V_18 ) ;
F_137 ( & V_14 -> V_20 , & V_17 -> F_137 ) ;
F_138 ( & V_14 -> V_27 , & V_17 -> V_209 ) ;
F_6 ( V_17 -> V_20 . V_210 ) ;
if ( V_14 -> V_22 ) {
F_6 ( V_17 -> V_20 . V_211 ) ;
F_5 ( & V_17 -> V_18 ) ;
F_3 ( V_14 , V_11 , false ) ;
F_4 ( & V_17 -> V_18 ) ;
if ( ! V_14 -> V_22 ) {
goto V_212;
}
V_14 -> V_70 = 1 ;
F_8 () ;
F_9 ( V_24 , & V_14 -> V_22 -> V_25 ) ;
F_5 ( & V_17 -> V_18 ) ;
} else {
V_212:
if ( ! V_14 -> V_19 )
F_7 ( & V_14 -> V_23 ) ;
F_7 ( & V_14 -> V_87 ) ;
V_17 -> V_88 -- ;
F_5 ( & V_17 -> V_18 ) ;
F_61 ( V_8 ) ;
F_62 ( V_8 -> V_89 -> V_90 ) ;
F_63 ( V_91 , V_14 ) ;
}
F_78 ( V_8 ) ;
}
static int F_139 ( struct V_120 * V_2 , struct F_134 * V_203 )
{
struct V_1 * V_37 = F_1 ( V_2 -> V_3 ) ;
struct V_16 * V_17 = V_37 -> V_17 ;
struct V_13 * V_14 ;
struct V_120 * V_187 ;
struct V_2 * V_8 ;
int V_9 ;
V_187 = F_129 ( V_203 -> V_204 , & V_9 ) ;
if ( ! V_187 )
return - V_205 ;
V_8 = V_187 -> V_3 ;
if ( ! V_8 ) {
V_9 = - V_101 ;
goto V_79;
}
V_9 = - V_205 ;
F_4 ( & V_17 -> V_18 ) ;
F_120 (psock, &mux->psocks, psock_list) {
if ( V_14 -> V_3 != V_8 )
continue;
if ( V_14 -> V_213 || F_19 ( V_14 -> V_70 ) ) {
V_9 = - V_214 ;
break;
}
V_14 -> V_213 = 1 ;
F_5 ( & V_17 -> V_18 ) ;
F_134 ( V_14 ) ;
V_9 = 0 ;
goto V_79;
}
F_5 ( & V_17 -> V_18 ) ;
V_79:
F_62 ( V_187 -> V_90 ) ;
return V_9 ;
}
static int F_140 ( struct V_120 * V_215 , struct F_140 * V_203 ,
struct V_120 * * V_216 )
{
struct V_120 * V_217 ;
struct V_2 * V_218 ;
struct V_90 * V_219 ;
int V_9 , V_220 ;
V_9 = - V_221 ;
V_217 = F_141 () ;
if ( ! V_217 )
goto V_79;
V_217 -> type = V_215 -> type ;
V_217 -> V_222 = V_215 -> V_222 ;
F_142 ( V_217 -> V_222 -> V_223 ) ;
V_220 = F_143 ( 0 ) ;
if ( F_15 ( V_220 < 0 ) ) {
V_9 = V_220 ;
goto V_224;
}
V_219 = F_144 ( V_217 , 0 , V_215 -> V_3 -> V_225 -> V_226 ) ;
if ( F_15 ( F_131 ( V_219 ) ) ) {
V_9 = F_132 ( V_219 ) ;
goto V_227;
}
V_218 = F_145 ( F_146 ( V_215 -> V_3 ) , V_194 , V_196 ,
& V_228 , true ) ;
if ( ! V_218 ) {
V_9 = - V_56 ;
goto V_229;
}
F_147 ( V_217 , V_218 ) ;
F_119 ( F_1 ( V_218 ) , F_1 ( V_215 -> V_3 ) -> V_17 ) ;
F_148 ( V_220 , V_219 ) ;
* V_216 = V_217 ;
V_203 -> V_204 = V_220 ;
return 0 ;
V_229:
F_62 ( V_219 ) ;
V_227:
F_149 ( V_220 ) ;
V_224:
F_150 ( V_217 ) ;
V_79:
return V_9 ;
}
static int F_151 ( struct V_120 * V_2 , unsigned int V_230 , unsigned long V_231 )
{
int V_9 ;
switch ( V_230 ) {
case V_232 : {
struct F_122 V_203 ;
if ( F_152 ( & V_203 , ( void T_5 * ) V_231 , sizeof( V_203 ) ) )
return - V_178 ;
V_9 = F_128 ( V_2 , & V_203 ) ;
break;
}
case V_233 : {
struct F_134 V_203 ;
if ( F_152 ( & V_203 , ( void T_5 * ) V_231 , sizeof( V_203 ) ) )
return - V_178 ;
V_9 = F_139 ( V_2 , & V_203 ) ;
break;
}
case V_234 : {
struct F_140 V_203 ;
struct V_120 * V_217 = NULL ;
V_9 = F_140 ( V_2 , & V_203 , & V_217 ) ;
if ( ! V_9 ) {
if ( F_118 ( ( void T_5 * ) V_231 , & V_203 ,
sizeof( V_203 ) ) ) {
V_9 = - V_178 ;
F_153 ( V_203 . V_204 ) ;
}
}
break;
}
default:
V_9 = - V_235 ;
break;
}
return V_9 ;
}
static void F_154 ( struct V_236 * V_237 )
{
struct V_16 * V_17 = F_43 ( V_237 ,
struct V_16 , V_237 ) ;
F_63 ( V_238 , V_17 ) ;
}
static void F_155 ( struct V_16 * V_17 )
{
struct V_239 * V_240 = V_17 -> V_240 ;
struct V_13 * V_14 , * V_241 ;
F_156 (psock, tmp_psock,
&mux->psocks, psock_list) {
if ( ! F_19 ( V_14 -> V_213 ) )
F_134 ( V_14 ) ;
}
if ( F_19 ( V_17 -> V_88 ) )
return;
F_157 ( & V_17 -> V_41 ) ;
F_158 ( & V_240 -> V_242 ) ;
F_159 ( & V_17 -> V_20 , & V_240 -> F_159 ) ;
F_137 ( & V_17 -> F_137 ,
& V_240 -> F_137 ) ;
V_209 ( & V_17 -> V_209 ,
& V_240 -> V_209 ) ;
F_160 ( & V_17 -> V_243 ) ;
V_240 -> V_244 -- ;
F_161 ( & V_240 -> V_242 ) ;
F_162 ( & V_17 -> V_237 , F_154 ) ;
}
static void F_42 ( struct V_1 * V_37 )
{
struct V_16 * V_17 = V_37 -> V_17 ;
struct V_2 * V_3 = & V_37 -> V_3 ;
int V_245 ;
F_4 ( & V_17 -> V_51 ) ;
if ( V_37 -> V_39 ) {
F_19 ( V_37 -> V_70 ) ;
V_37 -> V_40 = 1 ;
V_37 -> V_70 = 1 ;
F_5 ( & V_17 -> V_51 ) ;
return;
}
if ( V_37 -> V_38 ) {
F_7 ( & V_37 -> V_45 ) ;
V_37 -> V_38 = false ;
}
F_37 ( V_17 , & V_3 -> V_54 ) ;
F_5 ( & V_17 -> V_51 ) ;
if ( F_19 ( F_20 ( V_3 ) ) )
return;
F_4 ( & V_17 -> V_18 ) ;
F_7 ( & V_37 -> V_185 ) ;
V_17 -> V_186 -- ;
V_245 = V_17 -> V_186 ;
F_5 ( & V_17 -> V_18 ) ;
if ( ! V_245 ) {
F_155 ( V_17 ) ;
}
F_19 ( V_37 -> V_38 ) ;
F_61 ( & V_37 -> V_3 ) ;
}
static int F_163 ( struct V_120 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_37 ;
struct V_16 * V_17 ;
struct V_13 * V_14 ;
if ( ! V_3 )
return 0 ;
V_37 = F_1 ( V_3 ) ;
V_17 = V_37 -> V_17 ;
F_164 ( V_3 ) ;
F_72 ( V_37 -> V_129 ) ;
F_74 ( V_3 ) ;
F_157 ( & V_3 -> V_100 ) ;
V_37 -> V_19 = 1 ;
F_78 ( V_3 ) ;
F_4 ( & V_17 -> V_18 ) ;
if ( V_37 -> V_81 ) {
F_7 ( & V_37 -> V_83 ) ;
V_37 -> V_81 = false ;
}
F_5 ( & V_17 -> V_18 ) ;
F_165 ( & V_37 -> V_25 ) ;
F_74 ( V_3 ) ;
V_14 = V_37 -> V_80 ;
if ( V_14 ) {
F_3 ( V_14 , V_11 , false ) ;
F_59 ( V_37 ) ;
}
F_78 ( V_3 ) ;
F_19 ( V_37 -> V_81 ) ;
F_19 ( V_37 -> V_80 ) ;
V_2 -> V_3 = NULL ;
F_42 ( V_37 ) ;
return 0 ;
}
static int F_166 ( struct V_246 * V_246 , struct V_120 * V_2 ,
int V_247 , int V_248 )
{
struct V_239 * V_240 = F_167 ( V_246 , V_249 ) ;
struct V_2 * V_3 ;
struct V_16 * V_17 ;
switch ( V_2 -> type ) {
case V_147 :
V_2 -> V_222 = & V_250 ;
break;
case V_156 :
V_2 -> V_222 = & V_251 ;
break;
default:
return - V_252 ;
}
if ( V_247 != V_253 )
return - V_254 ;
V_3 = F_145 ( V_246 , V_194 , V_196 , & V_228 , V_248 ) ;
if ( ! V_3 )
return - V_56 ;
V_17 = F_123 ( V_238 , V_196 ) ;
if ( ! V_17 ) {
F_168 ( V_3 ) ;
return - V_56 ;
}
F_169 ( & V_17 -> V_18 ) ;
F_169 ( & V_17 -> V_51 ) ;
F_170 ( & V_17 -> V_184 ) ;
F_170 ( & V_17 -> V_46 ) ;
F_170 ( & V_17 -> V_85 ) ;
F_170 ( & V_17 -> V_201 ) ;
F_170 ( & V_17 -> V_42 ) ;
F_170 ( & V_17 -> V_82 ) ;
V_17 -> V_240 = V_240 ;
F_158 ( & V_240 -> V_242 ) ;
F_171 ( & V_17 -> V_243 , & V_240 -> V_255 ) ;
V_240 -> V_244 ++ ;
F_161 ( & V_240 -> V_242 ) ;
F_172 ( & V_17 -> V_41 ) ;
F_147 ( V_2 , V_3 ) ;
F_119 ( F_1 ( V_3 ) , V_17 ) ;
return 0 ;
}
static T_6 int F_173 ( struct V_246 * V_246 )
{
struct V_239 * V_240 = F_167 ( V_246 , V_249 ) ;
F_174 ( & V_240 -> V_255 ) ;
F_175 ( & V_240 -> V_242 ) ;
return 0 ;
}
static T_7 void F_176 ( struct V_246 * V_246 )
{
struct V_239 * V_240 = F_167 ( V_246 , V_249 ) ;
F_19 ( ! F_21 ( & V_240 -> V_255 ) ) ;
}
static int T_8 F_177 ( void )
{
int V_9 = - V_56 ;
V_238 = F_178 ( L_3 ,
sizeof( struct V_16 ) , 0 ,
V_256 | V_257 , NULL ) ;
if ( ! V_238 )
goto V_258;
V_91 = F_178 ( L_4 ,
sizeof( struct V_13 ) , 0 ,
V_256 | V_257 , NULL ) ;
if ( ! V_91 )
goto V_258;
V_24 = F_179 ( L_5 ) ;
if ( ! V_24 )
goto V_258;
V_9 = F_180 ( & V_228 , 1 ) ;
if ( V_9 )
goto V_258;
V_9 = F_181 ( & V_259 ) ;
if ( V_9 )
goto V_260;
V_9 = F_182 ( & V_261 ) ;
if ( V_9 )
goto V_262;
V_9 = F_183 () ;
if ( V_9 )
goto V_263;
return 0 ;
V_263:
F_184 ( & V_261 ) ;
V_262:
F_185 ( V_194 ) ;
V_260:
F_186 ( & V_228 ) ;
V_258:
F_187 ( V_238 ) ;
F_187 ( V_91 ) ;
if ( V_24 )
F_188 ( V_24 ) ;
return V_9 ;
}
static void T_9 F_189 ( void )
{
F_190 () ;
F_184 ( & V_261 ) ;
F_185 ( V_194 ) ;
F_186 ( & V_228 ) ;
F_188 ( V_24 ) ;
F_187 ( V_238 ) ;
F_187 ( V_91 ) ;
}
