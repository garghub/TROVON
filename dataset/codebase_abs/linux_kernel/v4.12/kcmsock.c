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
V_14 -> V_27 . V_20 . V_26 -
V_14 -> V_28 ) ;
V_17 -> V_20 . V_29 +=
V_14 -> V_27 . V_20 . V_29 - V_14 -> V_30 ;
V_14 -> V_30 = V_14 -> V_27 . V_20 . V_29 ;
V_14 -> V_28 = V_14 -> V_27 . V_20 . V_26 ;
}
static void F_12 ( struct V_16 * V_17 ,
struct V_13 * V_14 )
{
F_13 ( V_17 -> V_20 . V_31 ,
V_14 -> V_20 . V_31 - V_14 -> V_32 ) ;
V_17 -> V_20 . V_33 +=
V_14 -> V_20 . V_33 - V_14 -> V_34 ;
V_14 -> V_34 = V_14 -> V_20 . V_33 ;
V_14 -> V_32 = V_14 -> V_20 . V_31 ;
}
static void F_14 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_13 * V_14 ;
struct V_5 * V_6 ;
if ( F_15 ( V_35 -> V_36 || V_35 -> V_37 || V_35 -> V_38 ) )
return;
while ( F_15 ( ( V_6 = F_16 ( & V_17 -> V_39 ) ) ) ) {
if ( F_17 ( & V_35 -> V_3 , V_6 ) ) {
F_18 ( & V_17 -> V_39 , V_6 ) ;
F_19 ( ! F_20 ( & V_35 -> V_3 ) ) ;
return;
}
}
while ( ! F_21 ( & V_17 -> V_40 ) ) {
V_14 = F_22 ( & V_17 -> V_40 , struct V_13 ,
V_41 ) ;
if ( F_17 ( & V_35 -> V_3 , V_14 -> V_42 ) ) {
F_19 ( ! F_20 ( & V_35 -> V_3 ) ) ;
return;
}
F_7 ( & V_14 -> V_41 ) ;
V_14 -> V_42 = NULL ;
F_8 () ;
F_23 ( & V_14 -> V_27 ) ;
F_24 ( & V_14 -> V_27 ) ;
}
F_25 ( & V_35 -> V_43 ,
& V_35 -> V_17 -> V_44 ) ;
V_35 -> V_36 = true ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_35 -> V_17 ;
unsigned int V_45 = V_6 -> V_46 ;
F_27 ( V_3 , V_45 ) ;
F_28 ( V_45 , & V_3 -> V_47 ) ;
F_29 () ;
if ( ! V_35 -> V_36 && ! V_35 -> V_37 &&
F_20 ( V_3 ) < V_3 -> V_48 ) {
F_4 ( & V_17 -> V_49 ) ;
F_14 ( V_35 ) ;
F_5 ( & V_17 -> V_49 ) ;
}
}
static int F_17 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_50 * V_51 = & V_3 -> V_52 ;
if ( F_30 ( & V_3 -> V_47 ) >= V_3 -> V_53 )
return - V_54 ;
if ( ! F_31 ( V_3 , V_6 , V_6 -> V_46 ) )
return - V_55 ;
V_6 -> V_56 = NULL ;
F_32 ( V_6 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_57 = F_26 ;
F_33 ( V_6 -> V_46 , & V_3 -> V_47 ) ;
F_34 ( V_3 , V_6 -> V_46 ) ;
F_35 ( V_51 , V_6 ) ;
if ( ! F_36 ( V_3 , V_58 ) )
V_3 -> V_59 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_16 * V_17 , struct V_50 * V_60 )
{
struct V_5 * V_6 ;
struct V_1 * V_35 ;
while ( ( V_6 = F_16 ( V_60 ) ) ) {
V_6 -> V_57 = V_61 ;
F_32 ( V_6 ) ;
V_62:
if ( F_21 ( & V_17 -> V_44 ) ) {
F_35 ( & V_17 -> V_39 , V_6 ) ;
continue;
}
V_35 = F_22 ( & V_17 -> V_44 ,
struct V_1 , V_43 ) ;
if ( F_17 ( & V_35 -> V_3 , V_6 ) ) {
F_7 ( & V_35 -> V_43 ) ;
V_35 -> V_36 = false ;
F_38 () ;
goto V_62;
}
}
}
static struct V_1 * F_39 ( struct V_13 * V_14 ,
struct V_5 * V_60 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_1 * V_35 ;
F_19 ( V_14 -> V_42 ) ;
if ( V_14 -> V_63 )
return V_14 -> V_63 ;
F_4 ( & V_17 -> V_49 ) ;
if ( V_14 -> V_63 ) {
F_5 ( & V_17 -> V_49 ) ;
return V_14 -> V_63 ;
}
F_10 ( V_17 , V_14 ) ;
if ( F_21 ( & V_17 -> V_44 ) ) {
V_14 -> V_42 = V_60 ;
F_40 ( & V_14 -> V_27 ) ;
F_25 ( & V_14 -> V_41 ,
& V_17 -> V_40 ) ;
F_5 ( & V_17 -> V_49 ) ;
return NULL ;
}
V_35 = F_22 ( & V_17 -> V_44 ,
struct V_1 , V_43 ) ;
F_7 ( & V_35 -> V_43 ) ;
V_35 -> V_36 = false ;
V_14 -> V_63 = V_35 ;
V_35 -> V_37 = V_14 ;
F_5 ( & V_17 -> V_49 ) ;
return V_35 ;
}
static void F_41 ( struct V_64 * V_65 )
{
F_42 ( F_43 ( V_65 , struct V_1 , V_66 ) ) ;
}
static void F_44 ( struct V_13 * V_14 ,
bool V_67 )
{
struct V_1 * V_35 = V_14 -> V_63 ;
struct V_16 * V_17 = V_14 -> V_17 ;
if ( ! V_35 )
return;
F_4 ( & V_17 -> V_49 ) ;
V_14 -> V_63 = NULL ;
V_35 -> V_37 = NULL ;
F_8 () ;
if ( F_15 ( V_35 -> V_68 ) ) {
F_5 ( & V_17 -> V_49 ) ;
F_45 ( & V_35 -> V_66 , F_41 ) ;
F_46 ( & V_35 -> V_66 ) ;
return;
}
if ( F_15 ( V_35 -> V_38 ) ) {
F_37 ( V_17 , & V_35 -> V_3 . V_52 ) ;
} else if ( V_67 || F_15 ( ! F_20 ( & V_35 -> V_3 ) ) ) {
F_14 ( V_35 ) ;
}
F_5 ( & V_17 -> V_49 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
F_48 ( & V_3 -> V_69 ) ;
V_14 = (struct V_13 * ) V_3 -> V_70 ;
if ( F_49 ( V_14 ) )
F_50 ( & V_14 -> V_27 ) ;
F_51 ( & V_3 -> V_69 ) ;
}
static void F_52 ( struct V_71 * V_27 , struct V_5 * V_6 )
{
struct V_13 * V_14 = F_43 ( V_27 , struct V_13 , V_27 ) ;
struct V_1 * V_35 ;
V_72:
V_35 = F_39 ( V_14 , V_6 ) ;
if ( ! V_35 ) {
return;
}
if ( F_17 ( & V_35 -> V_3 , V_6 ) ) {
F_44 ( V_14 , false ) ;
goto V_72;
}
}
static int F_53 ( struct V_71 * V_27 , struct V_5 * V_6 )
{
struct V_13 * V_14 = F_43 ( V_27 , struct V_13 , V_27 ) ;
struct V_73 * V_74 = V_14 -> V_73 ;
return (* V_74 -> V_75 )( V_6 , V_74 -> V_76 ) ;
}
static int F_54 ( struct V_71 * V_27 , int V_9 )
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
struct V_1 * V_35 ;
F_48 ( & V_3 -> V_69 ) ;
V_14 = (struct V_13 * ) V_3 -> V_70 ;
if ( F_15 ( ! V_14 ) )
goto V_77;
V_17 = V_14 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_35 = V_14 -> V_22 ;
if ( V_35 && ! F_15 ( V_35 -> V_19 ) )
F_9 ( V_24 , & V_35 -> V_25 ) ;
F_5 ( & V_17 -> V_18 ) ;
V_77:
F_51 ( & V_3 -> V_69 ) ;
}
static struct V_13 * F_57 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_13 * V_14 ;
V_14 = V_35 -> V_78 ;
F_58 () ;
if ( V_14 ) {
F_19 ( V_35 -> V_79 ) ;
if ( F_15 ( V_14 -> V_19 ) )
F_59 ( V_35 ) ;
else
return V_35 -> V_78 ;
}
F_4 ( & V_17 -> V_18 ) ;
V_14 = V_35 -> V_78 ;
if ( F_15 ( V_14 ) ) {
F_19 ( V_35 -> V_79 ) ;
F_5 ( & V_17 -> V_18 ) ;
return V_35 -> V_78 ;
}
if ( ! F_21 ( & V_17 -> V_80 ) ) {
V_14 = F_22 ( & V_17 -> V_80 ,
struct V_13 ,
V_23 ) ;
F_7 ( & V_14 -> V_23 ) ;
if ( V_35 -> V_79 ) {
F_7 ( & V_35 -> V_81 ) ;
V_35 -> V_79 = false ;
}
V_35 -> V_78 = V_14 ;
V_14 -> V_22 = V_35 ;
F_6 ( V_14 -> V_20 . V_82 ) ;
} else if ( ! V_35 -> V_79 ) {
F_25 ( & V_35 -> V_81 ,
& V_17 -> V_83 ) ;
V_35 -> V_79 = true ;
}
F_5 ( & V_17 -> V_18 ) ;
return V_14 ;
}
static void F_60 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_1 * V_35 ;
if ( F_21 ( & V_17 -> V_83 ) ) {
F_25 ( & V_14 -> V_23 ,
& V_17 -> V_80 ) ;
} else {
V_35 = F_22 ( & V_17 -> V_83 ,
struct V_1 ,
V_81 ) ;
F_7 ( & V_35 -> V_81 ) ;
V_35 -> V_79 = false ;
V_14 -> V_22 = V_35 ;
F_8 () ;
V_35 -> V_78 = V_14 ;
F_6 ( V_14 -> V_20 . V_82 ) ;
F_9 ( V_24 , & V_35 -> V_25 ) ;
}
}
static void F_59 ( struct V_1 * V_35 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 = V_35 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_14 = V_35 -> V_78 ;
if ( F_19 ( ! V_14 ) ) {
F_5 ( & V_17 -> V_18 ) ;
return;
}
F_58 () ;
F_12 ( V_17 , V_14 ) ;
F_19 ( V_35 -> V_79 ) ;
V_35 -> V_78 = NULL ;
V_14 -> V_22 = NULL ;
F_6 ( V_14 -> V_20 . V_84 ) ;
if ( F_15 ( V_14 -> V_19 ) ) {
if ( V_14 -> V_68 ) {
F_7 ( & V_14 -> V_85 ) ;
V_17 -> V_86 -- ;
F_61 ( V_14 -> V_3 ) ;
F_62 ( V_14 -> V_3 -> V_87 -> V_88 ) ;
F_63 ( V_89 , V_14 ) ;
}
F_5 ( & V_17 -> V_18 ) ;
return;
}
F_60 ( V_14 ) ;
F_5 ( & V_17 -> V_18 ) ;
}
static void F_64 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
F_4 ( & V_17 -> V_18 ) ;
F_6 ( V_17 -> V_20 . V_90 ) ;
F_5 ( & V_17 -> V_18 ) ;
}
static int F_65 ( struct V_1 * V_35 )
{
struct V_2 * V_3 = & V_35 -> V_3 ;
struct V_13 * V_14 ;
struct V_5 * V_6 , * V_60 ;
struct V_4 * V_91 ;
unsigned short V_92 , V_93 ;
unsigned int V_94 , V_95 = 0 ;
int V_96 = 0 ;
V_35 -> V_97 = false ;
V_14 = V_35 -> V_78 ;
if ( F_15 ( V_14 && V_14 -> V_19 ) ) {
F_59 ( V_35 ) ;
F_64 ( V_35 ) ;
if ( F_66 ( & V_3 -> V_98 ) )
return 0 ;
V_4 ( F_67 ( & V_3 -> V_98 ) ) -> V_94 = 0 ;
} else if ( F_66 ( & V_3 -> V_98 ) ) {
return 0 ;
}
V_60 = F_67 ( & V_3 -> V_98 ) ;
V_91 = V_4 ( V_60 ) ;
if ( V_91 -> V_94 ) {
if ( F_19 ( ! V_14 ) ) {
V_96 = - V_99 ;
goto V_77;
}
V_94 = V_91 -> V_94 ;
V_93 = V_91 -> V_93 ;
V_92 = V_91 -> V_92 ;
V_6 = V_91 -> V_100 ;
goto V_101;
}
V_62:
V_14 = F_57 ( V_35 ) ;
if ( ! V_14 )
goto V_77;
do {
V_6 = V_60 ;
V_91 = V_4 ( V_60 ) ;
V_94 = 0 ;
V_102:
if ( F_19 ( ! F_68 ( V_6 ) -> V_103 ) ) {
V_96 = - V_99 ;
goto V_77;
}
for ( V_92 = 0 ; V_92 < F_68 ( V_6 ) -> V_103 ;
V_92 ++ ) {
T_1 * V_104 ;
V_93 = 0 ;
V_101:
V_104 = & F_68 ( V_6 ) -> V_105 [ V_92 ] ;
if ( F_19 ( ! V_104 -> V_106 ) ) {
V_96 = - V_99 ;
goto V_77;
}
V_96 = F_69 ( V_14 -> V_3 -> V_87 ,
V_104 -> V_107 . V_108 ,
V_104 -> V_109 + V_93 ,
V_104 -> V_106 - V_93 ,
V_110 ) ;
if ( V_96 <= 0 ) {
if ( V_96 == - V_111 ) {
V_91 -> V_94 = V_94 ;
V_91 -> V_93 = V_93 ;
V_91 -> V_92 = V_92 ;
V_91 -> V_100 = V_6 ;
V_96 = 0 ;
goto V_77;
}
F_3 ( V_14 , V_96 ? - V_96 : V_11 ,
true ) ;
F_59 ( V_35 ) ;
V_91 -> V_94 = 0 ;
F_64 ( V_35 ) ;
V_96 = 0 ;
goto V_62;
}
V_94 += V_96 ;
V_93 += V_96 ;
F_13 ( V_14 -> V_20 . V_31 , V_96 ) ;
if ( V_93 < V_104 -> V_106 ) {
goto V_101;
}
}
if ( V_6 == V_60 ) {
if ( F_70 ( V_6 ) ) {
V_6 = F_68 ( V_6 ) -> V_112 ;
goto V_102;
}
} else if ( V_6 -> V_113 ) {
V_6 = V_6 -> V_113 ;
goto V_102;
}
F_71 ( & V_3 -> V_98 ) ;
F_72 ( V_60 ) ;
V_3 -> V_114 -= V_94 ;
V_95 += V_94 ;
F_6 ( V_14 -> V_20 . V_33 ) ;
} while ( ( V_60 = F_67 ( & V_3 -> V_98 ) ) );
V_77:
if ( ! V_60 ) {
F_19 ( ! F_66 ( & V_3 -> V_98 ) ) ;
F_59 ( V_35 ) ;
}
V_3 -> V_115 ( V_3 ) ;
return V_95 ? : V_96 ;
}
static void F_73 ( struct V_64 * V_65 )
{
struct V_1 * V_35 = F_43 ( V_65 , struct V_1 , V_25 ) ;
struct V_2 * V_3 = & V_35 -> V_3 ;
int V_9 ;
F_74 ( V_3 ) ;
V_9 = F_65 ( V_35 ) ;
if ( V_9 < 0 ) {
F_75 ( L_1 , V_9 ) ;
F_2 ( & V_35 -> V_3 , - V_9 ) ;
goto V_77;
}
if ( F_49 ( V_3 -> V_87 ) &&
F_76 ( V_116 , & V_3 -> V_87 -> V_117 ) ) {
F_77 ( V_116 , & V_3 -> V_87 -> V_117 ) ;
V_3 -> V_115 ( V_3 ) ;
}
V_77:
F_78 ( V_3 ) ;
}
static void F_79 ( struct V_1 * V_35 )
{
if ( V_35 -> V_97 )
F_65 ( V_35 ) ;
}
static T_2 F_80 ( struct V_118 * V_2 , struct V_107 * V_107 ,
int V_119 , T_3 V_106 , int V_117 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_60 = NULL ;
long V_120 = F_81 ( V_3 , V_117 & V_110 ) ;
bool V_121 ;
int V_9 = 0 ;
int V_122 ;
if ( V_117 & V_123 )
V_117 |= V_124 ;
V_121 = ! ( V_117 & V_124 ) ;
F_74 ( V_3 ) ;
F_82 ( V_125 , V_3 ) ;
V_9 = - V_11 ;
if ( V_3 -> V_10 )
goto V_126;
if ( V_35 -> V_127 ) {
V_60 = V_35 -> V_127 ;
V_6 = V_4 ( V_60 ) -> V_128 ;
V_122 = F_68 ( V_6 ) -> V_103 ;
if ( F_83 ( V_6 , V_122 , V_107 , V_119 ) ) {
F_84 ( & F_68 ( V_6 ) -> V_105 [ V_122 - 1 ] , V_106 ) ;
F_68 ( V_6 ) -> V_129 |= V_130 ;
goto V_131;
}
if ( V_122 >= V_132 ) {
struct V_5 * V_133 ;
V_133 = F_85 ( 0 , V_3 -> V_134 ) ;
while ( ! V_133 ) {
F_79 ( V_35 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
}
if ( V_60 == V_6 )
F_68 ( V_60 ) -> V_112 = V_133 ;
else
V_6 -> V_113 = V_133 ;
V_6 = V_133 ;
V_6 -> V_135 = V_136 ;
V_122 = 0 ;
}
} else {
if ( ! F_87 ( V_3 ) ) {
F_79 ( V_35 ) ;
F_88 ( V_116 , & V_3 -> V_87 -> V_117 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
}
V_60 = F_85 ( 0 , V_3 -> V_134 ) ;
while ( ! V_60 ) {
F_79 ( V_35 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
}
V_6 = V_60 ;
V_122 = 0 ;
}
F_89 ( V_107 ) ;
F_90 ( V_6 , V_122 , V_107 , V_119 , V_106 ) ;
F_68 ( V_6 ) -> V_129 |= V_130 ;
V_131:
V_6 -> V_45 += V_106 ;
V_6 -> V_137 += V_106 ;
V_6 -> V_46 += V_106 ;
V_3 -> V_114 += V_106 ;
F_34 ( V_3 , V_106 ) ;
if ( V_60 != V_6 ) {
V_60 -> V_45 += V_106 ;
V_60 -> V_137 += V_106 ;
V_60 -> V_46 += V_106 ;
}
if ( V_121 ) {
bool V_138 = F_66 ( & V_3 -> V_98 ) ;
F_91 ( & V_3 -> V_98 , V_60 ) ;
V_35 -> V_127 = NULL ;
F_6 ( V_35 -> V_20 . V_33 ) ;
if ( V_117 & V_139 ) {
V_35 -> V_97 = true ;
} else if ( V_35 -> V_97 || V_138 ) {
V_9 = F_65 ( V_35 ) ;
if ( V_9 < 0 ) {
F_75 ( L_2 ) ;
F_2 ( & V_35 -> V_3 , - V_9 ) ;
}
}
} else {
V_35 -> V_127 = V_60 ;
V_4 ( V_60 ) -> V_128 = V_6 ;
}
F_13 ( V_35 -> V_20 . V_31 , V_106 ) ;
F_78 ( V_3 ) ;
return V_106 ;
V_126:
F_79 ( V_35 ) ;
V_9 = F_92 ( V_3 , V_117 , V_9 ) ;
if ( F_15 ( F_93 ( & V_3 -> V_98 ) == 0 && V_9 == - V_111 ) )
V_3 -> V_115 ( V_3 ) ;
F_78 ( V_3 ) ;
return V_9 ;
}
static int F_94 ( struct V_118 * V_2 , struct V_140 * V_141 , T_3 V_45 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
struct V_5 * V_6 = NULL , * V_60 = NULL ;
T_3 V_142 , V_143 = 0 ;
long V_120 = F_81 ( V_3 , V_141 -> V_144 & V_110 ) ;
int V_121 = ( V_2 -> type == V_145 ) ?
! ( V_141 -> V_144 & V_124 ) : ! ! ( V_141 -> V_144 & V_146 ) ;
int V_9 = - V_11 ;
F_74 ( V_3 ) ;
F_82 ( V_125 , V_3 ) ;
if ( V_3 -> V_10 )
goto V_126;
if ( V_35 -> V_127 ) {
V_60 = V_35 -> V_127 ;
V_6 = V_4 ( V_60 ) -> V_128 ;
goto V_147;
}
if ( ! F_87 ( V_3 ) ) {
F_79 ( V_35 ) ;
F_88 ( V_116 , & V_3 -> V_87 -> V_117 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
}
if ( F_95 ( V_141 ) ) {
V_60 = F_85 ( 0 , V_3 -> V_134 ) ;
while ( ! V_60 ) {
F_79 ( V_35 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
V_60 = F_85 ( 0 , V_3 -> V_134 ) ;
}
V_6 = V_60 ;
V_6 -> V_135 = V_136 ;
}
V_147:
while ( F_95 ( V_141 ) ) {
bool V_148 = true ;
int V_122 = F_68 ( V_6 ) -> V_103 ;
struct V_149 * V_150 = F_96 ( V_3 ) ;
if ( ! F_97 ( V_3 , V_150 ) )
goto V_151;
if ( ! F_83 ( V_6 , V_122 , V_150 -> V_107 ,
V_150 -> V_119 ) ) {
if ( V_122 == V_132 ) {
struct V_5 * V_133 ;
V_133 = F_85 ( 0 , V_3 -> V_134 ) ;
if ( ! V_133 )
goto V_151;
if ( V_60 == V_6 )
F_68 ( V_60 ) -> V_112 = V_133 ;
else
V_6 -> V_113 = V_133 ;
V_6 = V_133 ;
V_6 -> V_135 = V_136 ;
continue;
}
V_148 = false ;
}
V_142 = F_98 ( int , F_95 ( V_141 ) ,
V_150 -> V_106 - V_150 -> V_119 ) ;
if ( ! F_99 ( V_3 , V_142 ) )
goto V_151;
V_9 = F_100 ( V_3 , & V_141 -> V_152 , V_6 ,
V_150 -> V_107 ,
V_150 -> V_119 ,
V_142 ) ;
if ( V_9 )
goto V_126;
if ( V_148 ) {
F_84 ( & F_68 ( V_6 ) -> V_105 [ V_122 - 1 ] , V_142 ) ;
} else {
F_90 ( V_6 , V_122 , V_150 -> V_107 ,
V_150 -> V_119 , V_142 ) ;
F_89 ( V_150 -> V_107 ) ;
}
V_150 -> V_119 += V_142 ;
V_143 += V_142 ;
if ( V_60 != V_6 ) {
V_60 -> V_45 += V_142 ;
V_60 -> V_137 += V_142 ;
}
continue;
V_151:
F_79 ( V_35 ) ;
V_9 = F_86 ( V_3 , & V_120 ) ;
if ( V_9 )
goto V_126;
}
if ( V_121 ) {
bool V_138 = F_66 ( & V_3 -> V_98 ) ;
if ( V_60 ) {
F_91 ( & V_3 -> V_98 , V_60 ) ;
V_35 -> V_127 = NULL ;
F_6 ( V_35 -> V_20 . V_33 ) ;
}
if ( V_141 -> V_144 & V_139 ) {
V_35 -> V_97 = true ;
} else if ( V_35 -> V_97 || V_138 ) {
V_9 = F_65 ( V_35 ) ;
if ( V_9 < 0 ) {
F_75 ( L_2 ) ;
F_2 ( & V_35 -> V_3 , - V_9 ) ;
}
}
} else {
V_153:
if ( V_60 ) {
V_35 -> V_127 = V_60 ;
V_4 ( V_60 ) -> V_128 = V_6 ;
}
}
F_13 ( V_35 -> V_20 . V_31 , V_143 ) ;
F_78 ( V_3 ) ;
return V_143 ;
V_126:
F_79 ( V_35 ) ;
if ( V_143 && V_2 -> type == V_154 ) {
goto V_153;
}
if ( V_60 != V_35 -> V_127 )
F_72 ( V_60 ) ;
V_9 = F_92 ( V_3 , V_141 -> V_144 , V_9 ) ;
if ( F_15 ( F_93 ( & V_3 -> V_98 ) == 0 && V_9 == - V_111 ) )
V_3 -> V_115 ( V_3 ) ;
F_78 ( V_3 ) ;
return V_9 ;
}
static struct V_5 * F_101 ( struct V_2 * V_3 , int V_117 ,
long V_120 , int * V_9 )
{
struct V_5 * V_6 ;
while ( ! ( V_6 = F_67 ( & V_3 -> V_52 ) ) ) {
if ( V_3 -> V_10 ) {
* V_9 = F_102 ( V_3 ) ;
return NULL ;
}
if ( F_36 ( V_3 , V_155 ) )
return NULL ;
if ( ( V_117 & V_110 ) || ! V_120 ) {
* V_9 = - V_111 ;
return NULL ;
}
F_103 ( V_3 , & V_120 , NULL ) ;
if ( F_104 ( V_156 ) ) {
* V_9 = F_105 ( V_120 ) ;
return NULL ;
}
}
return V_6 ;
}
static int F_106 ( struct V_118 * V_2 , struct V_140 * V_141 ,
T_3 V_45 , int V_117 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
int V_9 = 0 ;
long V_120 ;
struct V_157 * V_158 ;
int V_143 = 0 ;
struct V_5 * V_6 ;
V_120 = F_107 ( V_3 , V_117 & V_110 ) ;
F_74 ( V_3 ) ;
V_6 = F_101 ( V_3 , V_117 , V_120 , & V_9 ) ;
if ( ! V_6 )
goto V_77;
V_158 = V_157 ( V_6 ) ;
if ( V_45 > V_158 -> V_159 )
V_45 = V_158 -> V_159 ;
V_9 = F_108 ( V_6 , V_158 -> V_119 , V_141 , V_45 ) ;
if ( V_9 < 0 )
goto V_77;
V_143 = V_45 ;
if ( F_49 ( ! ( V_117 & V_160 ) ) ) {
F_13 ( V_35 -> V_20 . V_26 , V_143 ) ;
if ( V_143 < V_158 -> V_159 ) {
if ( V_2 -> type == V_145 ) {
V_141 -> V_144 |= V_161 ;
goto V_162;
}
V_158 -> V_119 += V_143 ;
V_158 -> V_159 -= V_143 ;
} else {
V_162:
V_141 -> V_144 |= V_146 ;
F_6 ( V_35 -> V_20 . V_29 ) ;
F_109 ( V_6 , & V_3 -> V_52 ) ;
F_72 ( V_6 ) ;
}
}
V_77:
F_78 ( V_3 ) ;
return V_143 ? : V_9 ;
}
static T_2 F_110 ( struct V_118 * V_2 , T_4 * V_163 ,
struct V_164 * V_165 , T_3 V_45 ,
unsigned int V_117 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_35 = F_1 ( V_3 ) ;
long V_120 ;
struct V_157 * V_158 ;
int V_9 = 0 ;
T_2 V_143 ;
struct V_5 * V_6 ;
V_120 = F_107 ( V_3 , V_117 & V_110 ) ;
F_74 ( V_3 ) ;
V_6 = F_101 ( V_3 , V_117 , V_120 , & V_9 ) ;
if ( ! V_6 )
goto V_166;
V_158 = V_157 ( V_6 ) ;
if ( V_45 > V_158 -> V_159 )
V_45 = V_158 -> V_159 ;
V_143 = F_111 ( V_6 , V_3 , V_158 -> V_119 , V_165 , V_45 , V_117 ) ;
if ( V_143 < 0 ) {
V_9 = V_143 ;
goto V_166;
}
F_13 ( V_35 -> V_20 . V_26 , V_143 ) ;
V_158 -> V_119 += V_143 ;
V_158 -> V_159 -= V_143 ;
F_78 ( V_3 ) ;
return V_143 ;
V_166:
F_78 ( V_3 ) ;
return V_9 ;
}
static void F_112 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
if ( V_35 -> V_38 )
return;
F_4 ( & V_17 -> V_49 ) ;
V_35 -> V_38 = 1 ;
if ( ! V_35 -> V_37 ) {
if ( V_35 -> V_36 ) {
F_7 ( & V_35 -> V_43 ) ;
V_35 -> V_36 = false ;
}
F_37 ( V_17 , & V_35 -> V_3 . V_52 ) ;
}
F_5 ( & V_17 -> V_49 ) ;
}
static void F_113 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
if ( ! V_35 -> V_38 )
return;
F_4 ( & V_17 -> V_49 ) ;
V_35 -> V_38 = 0 ;
F_14 ( V_35 ) ;
F_5 ( & V_17 -> V_49 ) ;
}
static int F_114 ( struct V_118 * V_2 , int V_167 , int V_168 ,
char T_5 * V_169 , unsigned int V_170 )
{
struct V_1 * V_35 = F_1 ( V_2 -> V_3 ) ;
int V_171 , V_172 ;
int V_9 = 0 ;
if ( V_167 != V_173 )
return - V_174 ;
if ( V_170 < sizeof( int ) )
return - V_99 ;
if ( F_115 ( V_171 , ( int T_5 * ) V_169 ) )
return - V_99 ;
V_172 = V_171 ? 1 : 0 ;
switch ( V_168 ) {
case V_175 :
F_74 ( & V_35 -> V_3 ) ;
if ( V_172 )
F_112 ( V_35 ) ;
else
F_113 ( V_35 ) ;
F_78 ( & V_35 -> V_3 ) ;
break;
default:
V_9 = - V_174 ;
}
return V_9 ;
}
static int F_116 ( struct V_118 * V_2 , int V_167 , int V_168 ,
char T_5 * V_169 , int T_5 * V_170 )
{
struct V_1 * V_35 = F_1 ( V_2 -> V_3 ) ;
int V_171 , V_45 ;
if ( V_167 != V_173 )
return - V_174 ;
if ( F_115 ( V_45 , V_170 ) )
return - V_176 ;
V_45 = F_98 (unsigned int, len, sizeof(int)) ;
if ( V_45 < 0 )
return - V_99 ;
switch ( V_168 ) {
case V_175 :
V_171 = V_35 -> V_38 ;
break;
default:
return - V_174 ;
}
if ( F_117 ( V_45 , V_170 ) )
return - V_176 ;
if ( F_118 ( V_169 , & V_171 , V_45 ) )
return - V_176 ;
return 0 ;
}
static void F_119 ( struct V_1 * V_35 , struct V_16 * V_17 )
{
struct V_1 * V_177 ;
struct V_178 * V_60 ;
int V_179 = 0 ;
V_35 -> V_3 . V_180 = V_181 ;
V_35 -> V_17 = V_17 ;
F_4 ( & V_17 -> V_18 ) ;
V_60 = & V_17 -> V_182 ;
F_120 (tkcm, &mux->kcm_socks, kcm_sock_list) {
if ( V_177 -> V_179 != V_179 )
break;
V_60 = & V_177 -> V_183 ;
V_179 ++ ;
}
F_121 ( & V_35 -> V_183 , V_60 ) ;
V_35 -> V_179 = V_179 ;
V_17 -> V_184 ++ ;
F_5 ( & V_17 -> V_18 ) ;
F_45 ( & V_35 -> V_25 , F_73 ) ;
F_4 ( & V_17 -> V_49 ) ;
F_14 ( V_35 ) ;
F_5 ( & V_17 -> V_49 ) ;
}
static int F_122 ( struct V_118 * V_2 , struct V_118 * V_185 ,
struct V_73 * V_74 )
{
struct V_1 * V_35 = F_1 ( V_2 -> V_3 ) ;
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_2 * V_8 ;
struct V_13 * V_14 = NULL , * V_186 ;
struct V_178 * V_60 ;
int V_179 = 0 ;
struct V_187 V_7 ;
int V_9 ;
V_8 = V_185 -> V_3 ;
if ( ! V_8 )
return - V_99 ;
V_14 = F_123 ( V_89 , V_188 ) ;
if ( ! V_14 )
return - V_54 ;
V_14 -> V_17 = V_17 ;
V_14 -> V_3 = V_8 ;
V_14 -> V_73 = V_74 ;
V_7 . V_189 = F_52 ;
V_7 . V_190 = NULL ;
V_7 . V_191 = F_53 ;
V_7 . V_192 = F_54 ;
V_9 = F_124 ( & V_14 -> V_27 , V_8 , & V_7 ) ;
if ( V_9 ) {
F_63 ( V_89 , V_14 ) ;
return V_9 ;
}
F_125 ( V_8 ) ;
F_126 ( & V_8 -> V_69 ) ;
V_14 -> V_193 = V_8 -> V_59 ;
V_14 -> V_194 = V_8 -> V_115 ;
V_14 -> V_195 = V_8 -> V_196 ;
V_8 -> V_70 = V_14 ;
V_8 -> V_59 = F_47 ;
V_8 -> V_115 = F_56 ;
V_8 -> V_196 = F_55 ;
F_127 ( & V_8 -> V_69 ) ;
F_4 ( & V_17 -> V_18 ) ;
V_60 = & V_17 -> V_197 ;
F_120 (tpsock, &mux->psocks, psock_list) {
if ( V_186 -> V_179 != V_179 )
break;
V_60 = & V_186 -> V_85 ;
V_179 ++ ;
}
F_121 ( & V_14 -> V_85 , V_60 ) ;
V_14 -> V_179 = V_179 ;
F_6 ( V_17 -> V_20 . V_198 ) ;
V_17 -> V_86 ++ ;
F_60 ( V_14 ) ;
F_5 ( & V_17 -> V_18 ) ;
F_24 ( & V_14 -> V_27 ) ;
return 0 ;
}
static int F_128 ( struct V_118 * V_2 , struct F_122 * V_199 )
{
struct V_118 * V_185 ;
struct V_73 * V_74 ;
int V_9 ;
V_185 = F_129 ( V_199 -> V_200 , & V_9 ) ;
if ( ! V_185 )
return - V_201 ;
V_74 = F_130 ( V_199 -> V_202 , V_203 ) ;
if ( F_131 ( V_74 ) ) {
V_9 = F_132 ( V_74 ) ;
goto V_77;
}
V_9 = F_122 ( V_2 , V_185 , V_74 ) ;
if ( V_9 ) {
F_133 ( V_74 ) ;
goto V_77;
}
return 0 ;
V_77:
F_62 ( V_185 -> V_88 ) ;
return V_9 ;
}
static void F_134 ( struct V_13 * V_14 )
{
struct V_2 * V_8 = V_14 -> V_3 ;
struct V_16 * V_17 = V_14 -> V_17 ;
F_74 ( V_8 ) ;
F_126 ( & V_8 -> V_69 ) ;
V_8 -> V_70 = NULL ;
V_8 -> V_59 = V_14 -> V_193 ;
V_8 -> V_115 = V_14 -> V_194 ;
V_8 -> V_196 = V_14 -> V_195 ;
F_135 ( & V_14 -> V_27 ) ;
if ( F_19 ( V_14 -> V_63 ) ) {
F_127 ( & V_8 -> V_69 ) ;
return;
}
F_4 ( & V_17 -> V_49 ) ;
if ( V_14 -> V_42 ) {
F_7 ( & V_14 -> V_41 ) ;
F_72 ( V_14 -> V_42 ) ;
V_14 -> V_42 = NULL ;
F_6 ( V_17 -> V_20 . V_204 ) ;
}
F_5 ( & V_17 -> V_49 ) ;
F_127 ( & V_8 -> V_69 ) ;
F_78 ( V_8 ) ;
F_136 ( & V_14 -> V_27 ) ;
F_74 ( V_8 ) ;
F_133 ( V_14 -> V_73 ) ;
F_4 ( & V_17 -> V_18 ) ;
F_137 ( & V_14 -> V_20 , & V_17 -> F_137 ) ;
F_138 ( & V_14 -> V_27 , & V_17 -> V_205 ) ;
F_6 ( V_17 -> V_20 . V_206 ) ;
if ( V_14 -> V_22 ) {
F_6 ( V_17 -> V_20 . V_207 ) ;
F_5 ( & V_17 -> V_18 ) ;
F_3 ( V_14 , V_11 , false ) ;
F_4 ( & V_17 -> V_18 ) ;
if ( ! V_14 -> V_22 ) {
goto V_208;
}
V_14 -> V_68 = 1 ;
F_8 () ;
F_9 ( V_24 , & V_14 -> V_22 -> V_25 ) ;
F_5 ( & V_17 -> V_18 ) ;
} else {
V_208:
if ( ! V_14 -> V_19 )
F_7 ( & V_14 -> V_23 ) ;
F_7 ( & V_14 -> V_85 ) ;
V_17 -> V_86 -- ;
F_5 ( & V_17 -> V_18 ) ;
F_61 ( V_8 ) ;
F_62 ( V_8 -> V_87 -> V_88 ) ;
F_63 ( V_89 , V_14 ) ;
}
F_78 ( V_8 ) ;
}
static int F_139 ( struct V_118 * V_2 , struct F_134 * V_199 )
{
struct V_1 * V_35 = F_1 ( V_2 -> V_3 ) ;
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_13 * V_14 ;
struct V_118 * V_185 ;
struct V_2 * V_8 ;
int V_9 ;
V_185 = F_129 ( V_199 -> V_200 , & V_9 ) ;
if ( ! V_185 )
return - V_201 ;
V_8 = V_185 -> V_3 ;
if ( ! V_8 ) {
V_9 = - V_99 ;
goto V_77;
}
V_9 = - V_201 ;
F_4 ( & V_17 -> V_18 ) ;
F_120 (psock, &mux->psocks, psock_list) {
if ( V_14 -> V_3 != V_8 )
continue;
if ( V_14 -> V_209 || F_19 ( V_14 -> V_68 ) ) {
V_9 = - V_210 ;
break;
}
V_14 -> V_209 = 1 ;
F_5 ( & V_17 -> V_18 ) ;
F_134 ( V_14 ) ;
V_9 = 0 ;
goto V_77;
}
F_5 ( & V_17 -> V_18 ) ;
V_77:
F_62 ( V_185 -> V_88 ) ;
return V_9 ;
}
static int F_140 ( struct V_118 * V_211 , struct F_140 * V_199 ,
struct V_118 * * V_212 )
{
struct V_118 * V_213 ;
struct V_2 * V_214 ;
struct V_88 * V_215 ;
int V_9 , V_216 ;
V_9 = - V_217 ;
V_213 = F_141 () ;
if ( ! V_213 )
goto V_77;
V_213 -> type = V_211 -> type ;
V_213 -> V_218 = V_211 -> V_218 ;
F_142 ( V_213 -> V_218 -> V_219 ) ;
V_216 = F_143 ( 0 ) ;
if ( F_15 ( V_216 < 0 ) ) {
V_9 = V_216 ;
goto V_220;
}
V_215 = F_144 ( V_213 , 0 , V_211 -> V_3 -> V_221 -> V_222 ) ;
if ( F_15 ( F_131 ( V_215 ) ) ) {
V_9 = F_132 ( V_215 ) ;
goto V_223;
}
V_214 = F_145 ( F_146 ( V_211 -> V_3 ) , V_224 , V_188 ,
& V_225 , true ) ;
if ( ! V_214 ) {
V_9 = - V_54 ;
goto V_226;
}
F_147 ( V_213 , V_214 ) ;
F_119 ( F_1 ( V_214 ) , F_1 ( V_211 -> V_3 ) -> V_17 ) ;
F_148 ( V_216 , V_215 ) ;
* V_212 = V_213 ;
V_199 -> V_200 = V_216 ;
return 0 ;
V_226:
F_62 ( V_215 ) ;
V_223:
F_149 ( V_216 ) ;
V_220:
F_150 ( V_213 ) ;
V_77:
return V_9 ;
}
static int F_151 ( struct V_118 * V_2 , unsigned int V_227 , unsigned long V_228 )
{
int V_9 ;
switch ( V_227 ) {
case V_229 : {
struct F_122 V_199 ;
if ( F_152 ( & V_199 , ( void T_5 * ) V_228 , sizeof( V_199 ) ) )
return - V_176 ;
V_9 = F_128 ( V_2 , & V_199 ) ;
break;
}
case V_230 : {
struct F_134 V_199 ;
if ( F_152 ( & V_199 , ( void T_5 * ) V_228 , sizeof( V_199 ) ) )
return - V_176 ;
V_9 = F_139 ( V_2 , & V_199 ) ;
break;
}
case V_231 : {
struct F_140 V_199 ;
struct V_118 * V_213 = NULL ;
V_9 = F_140 ( V_2 , & V_199 , & V_213 ) ;
if ( ! V_9 ) {
if ( F_118 ( ( void T_5 * ) V_228 , & V_199 ,
sizeof( V_199 ) ) ) {
V_9 = - V_176 ;
F_153 ( V_199 . V_200 ) ;
}
}
break;
}
default:
V_9 = - V_232 ;
break;
}
return V_9 ;
}
static void F_154 ( struct V_233 * V_234 )
{
struct V_16 * V_17 = F_43 ( V_234 ,
struct V_16 , V_234 ) ;
F_63 ( V_235 , V_17 ) ;
}
static void F_155 ( struct V_16 * V_17 )
{
struct V_236 * V_237 = V_17 -> V_237 ;
struct V_13 * V_14 , * V_238 ;
F_156 (psock, tmp_psock,
&mux->psocks, psock_list) {
if ( ! F_19 ( V_14 -> V_209 ) )
F_134 ( V_14 ) ;
}
if ( F_19 ( V_17 -> V_86 ) )
return;
F_157 ( & V_17 -> V_39 ) ;
F_158 ( & V_237 -> V_239 ) ;
F_159 ( & V_17 -> V_20 , & V_237 -> F_159 ) ;
F_137 ( & V_17 -> F_137 ,
& V_237 -> F_137 ) ;
V_205 ( & V_17 -> V_205 ,
& V_237 -> V_205 ) ;
F_160 ( & V_17 -> V_240 ) ;
V_237 -> V_241 -- ;
F_161 ( & V_237 -> V_239 ) ;
F_162 ( & V_17 -> V_234 , F_154 ) ;
}
static void F_42 ( struct V_1 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_17 ;
struct V_2 * V_3 = & V_35 -> V_3 ;
int V_242 ;
F_4 ( & V_17 -> V_49 ) ;
if ( V_35 -> V_37 ) {
F_19 ( V_35 -> V_68 ) ;
V_35 -> V_38 = 1 ;
V_35 -> V_68 = 1 ;
F_5 ( & V_17 -> V_49 ) ;
return;
}
if ( V_35 -> V_36 ) {
F_7 ( & V_35 -> V_43 ) ;
V_35 -> V_36 = false ;
}
F_37 ( V_17 , & V_3 -> V_52 ) ;
F_5 ( & V_17 -> V_49 ) ;
if ( F_19 ( F_20 ( V_3 ) ) )
return;
F_4 ( & V_17 -> V_18 ) ;
F_7 ( & V_35 -> V_183 ) ;
V_17 -> V_184 -- ;
V_242 = V_17 -> V_184 ;
F_5 ( & V_17 -> V_18 ) ;
if ( ! V_242 ) {
F_155 ( V_17 ) ;
}
F_19 ( V_35 -> V_36 ) ;
F_61 ( & V_35 -> V_3 ) ;
}
static int F_163 ( struct V_118 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_35 ;
struct V_16 * V_17 ;
struct V_13 * V_14 ;
if ( ! V_3 )
return 0 ;
V_35 = F_1 ( V_3 ) ;
V_17 = V_35 -> V_17 ;
F_164 ( V_3 ) ;
F_72 ( V_35 -> V_127 ) ;
F_74 ( V_3 ) ;
F_157 ( & V_3 -> V_98 ) ;
V_35 -> V_19 = 1 ;
F_78 ( V_3 ) ;
F_4 ( & V_17 -> V_18 ) ;
if ( V_35 -> V_79 ) {
F_7 ( & V_35 -> V_81 ) ;
V_35 -> V_79 = false ;
}
F_5 ( & V_17 -> V_18 ) ;
F_165 ( & V_35 -> V_25 ) ;
F_74 ( V_3 ) ;
V_14 = V_35 -> V_78 ;
if ( V_14 ) {
F_3 ( V_14 , V_11 , false ) ;
F_59 ( V_35 ) ;
}
F_78 ( V_3 ) ;
F_19 ( V_35 -> V_79 ) ;
F_19 ( V_35 -> V_78 ) ;
V_2 -> V_3 = NULL ;
F_42 ( V_35 ) ;
return 0 ;
}
static int F_166 ( struct V_243 * V_243 , struct V_118 * V_2 ,
int V_244 , int V_245 )
{
struct V_236 * V_237 = F_167 ( V_243 , V_246 ) ;
struct V_2 * V_3 ;
struct V_16 * V_17 ;
switch ( V_2 -> type ) {
case V_145 :
V_2 -> V_218 = & V_247 ;
break;
case V_154 :
V_2 -> V_218 = & V_248 ;
break;
default:
return - V_249 ;
}
if ( V_244 != V_250 )
return - V_251 ;
V_3 = F_145 ( V_243 , V_224 , V_188 , & V_225 , V_245 ) ;
if ( ! V_3 )
return - V_54 ;
V_17 = F_123 ( V_235 , V_188 ) ;
if ( ! V_17 ) {
F_168 ( V_3 ) ;
return - V_54 ;
}
F_169 ( & V_17 -> V_18 ) ;
F_169 ( & V_17 -> V_49 ) ;
F_170 ( & V_17 -> V_182 ) ;
F_170 ( & V_17 -> V_44 ) ;
F_170 ( & V_17 -> V_83 ) ;
F_170 ( & V_17 -> V_197 ) ;
F_170 ( & V_17 -> V_40 ) ;
F_170 ( & V_17 -> V_80 ) ;
V_17 -> V_237 = V_237 ;
F_158 ( & V_237 -> V_239 ) ;
F_171 ( & V_17 -> V_240 , & V_237 -> V_252 ) ;
V_237 -> V_241 ++ ;
F_161 ( & V_237 -> V_239 ) ;
F_172 ( & V_17 -> V_39 ) ;
F_147 ( V_2 , V_3 ) ;
F_119 ( F_1 ( V_3 ) , V_17 ) ;
return 0 ;
}
static T_6 int F_173 ( struct V_243 * V_243 )
{
struct V_236 * V_237 = F_167 ( V_243 , V_246 ) ;
F_174 ( & V_237 -> V_252 ) ;
F_175 ( & V_237 -> V_239 ) ;
return 0 ;
}
static T_7 void F_176 ( struct V_243 * V_243 )
{
struct V_236 * V_237 = F_167 ( V_243 , V_246 ) ;
F_19 ( ! F_21 ( & V_237 -> V_252 ) ) ;
}
static int T_8 F_177 ( void )
{
int V_9 = - V_54 ;
V_235 = F_178 ( L_3 ,
sizeof( struct V_16 ) , 0 ,
V_253 | V_254 , NULL ) ;
if ( ! V_235 )
goto V_255;
V_89 = F_178 ( L_4 ,
sizeof( struct V_13 ) , 0 ,
V_253 | V_254 , NULL ) ;
if ( ! V_89 )
goto V_255;
V_24 = F_179 ( L_5 ) ;
if ( ! V_24 )
goto V_255;
V_9 = F_180 ( & V_225 , 1 ) ;
if ( V_9 )
goto V_255;
V_9 = F_181 ( & V_256 ) ;
if ( V_9 )
goto V_257;
V_9 = F_182 ( & V_258 ) ;
if ( V_9 )
goto V_259;
V_9 = F_183 () ;
if ( V_9 )
goto V_260;
return 0 ;
V_260:
F_184 ( & V_258 ) ;
V_259:
F_185 ( V_224 ) ;
V_257:
F_186 ( & V_225 ) ;
V_255:
F_187 ( V_235 ) ;
F_187 ( V_89 ) ;
if ( V_24 )
F_188 ( V_24 ) ;
return V_9 ;
}
static void T_9 F_189 ( void )
{
F_190 () ;
F_184 ( & V_258 ) ;
F_185 ( V_224 ) ;
F_186 ( & V_225 ) ;
F_188 ( V_24 ) ;
F_187 ( V_235 ) ;
F_187 ( V_89 ) ;
}
