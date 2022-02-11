static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_6 != - V_7 && V_6 != - V_8 )
break;
F_3 ( V_9 ) ;
V_6 = - V_10 ;
} while ( ! F_4 ( V_11 ) );
return V_6 ;
}
static int
F_5 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
if ( V_13 -> V_15 != - V_7 && V_13 -> V_15 != - V_8 )
return 0 ;
if ( V_13 -> V_15 == - V_7 )
F_6 ( V_14 , V_16 ) ;
V_13 -> V_15 = 0 ;
F_7 ( V_13 ) ;
F_8 ( V_13 , V_9 ) ;
return 1 ;
}
static int
F_9 ( struct V_1 * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_3 V_4 = {
. V_22 = & V_23 [ V_24 ] ,
. V_25 = V_19 ,
. V_26 = V_21 ,
} ;
int V_27 ;
F_10 ( L_1 , V_28 ) ;
F_11 ( V_21 -> V_29 ) ;
V_27 = F_2 ( V_17 , & V_4 , 0 ) ;
F_10 ( L_2 , V_28 , V_27 ) ;
if ( ! ( V_21 -> V_29 -> V_30 & V_31 ) ) {
V_4 . V_22 = & V_23 [ V_32 ] ;
V_4 . V_26 = V_21 -> V_29 ;
V_27 = F_2 ( V_17 , & V_4 , 0 ) ;
F_10 ( L_3 , V_28 , V_27 ) ;
}
return V_27 ;
}
static int
F_12 ( struct V_33 * V_34 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
int V_27 ;
V_27 = F_9 ( V_34 -> V_17 , V_19 , V_21 ) ;
if ( V_27 && V_34 -> V_35 -> V_36 != V_34 -> V_17 )
V_27 = F_9 ( V_34 -> V_35 -> V_36 , V_19 , V_21 ) ;
return V_27 ;
}
static int
F_13 ( struct V_33 * V_34 , struct V_18 * V_19 ,
struct V_37 * V_29 )
{
struct V_3 V_4 = {
. V_22 = & V_23 [ V_32 ] ,
. V_25 = V_19 ,
. V_26 = V_29 ,
} ;
int V_27 ;
F_10 ( L_4 ) ;
F_11 ( V_29 ) ;
V_27 = F_2 ( V_34 -> V_17 , & V_4 , 0 ) ;
F_10 ( L_5 , V_27 ) ;
return V_27 ;
}
static int
F_14 ( struct V_38 * V_38 , struct V_37 * V_29 ,
struct V_39 * V_40 )
{
struct V_14 * V_14 = V_38 -> V_41 ;
struct V_42 V_43 = {
. V_44 = F_15 ( V_14 ) ,
. V_40 = V_40 ,
} ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_45 ] ,
. V_25 = & V_43 ,
. V_26 = V_29 ,
} ;
int V_27 ;
F_10 ( L_6 ) ;
if ( V_40 -> V_46 & V_47 )
V_4 . V_48 = F_16 ( V_40 -> V_49 ) ;
F_11 ( V_29 ) ;
V_27 = F_2 ( F_17 ( V_14 ) , & V_4 , 0 ) ;
if ( V_27 == 0 )
F_18 ( V_14 , V_40 ) ;
F_10 ( L_7 , V_27 ) ;
return V_27 ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_14 * V_50 , struct V_51 * V_52 ,
struct V_18 * V_19 , struct V_37 * V_29 )
{
struct V_53 V_43 = {
. V_44 = F_15 ( V_50 ) ,
. V_52 = V_52 -> V_52 ,
. V_54 = V_52 -> V_54
} ;
struct V_55 V_6 = {
. V_44 = V_19 ,
. V_29 = V_29
} ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_56 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
} ;
int V_27 ;
F_10 ( L_8 , V_52 -> V_52 ) ;
V_6 . V_57 = F_20 () ;
if ( V_6 . V_57 == NULL )
return - V_58 ;
F_11 ( V_29 ) ;
V_27 = F_2 ( F_17 ( V_50 ) , & V_4 , 0 ) ;
F_21 ( V_50 , V_6 . V_57 ) ;
if ( V_27 >= 0 && ! ( V_29 -> V_30 & V_31 ) ) {
V_4 . V_22 = & V_23 [ V_32 ] ;
V_4 . V_25 = V_19 ;
V_4 . V_26 = V_29 ;
V_27 = F_2 ( F_17 ( V_50 ) , & V_4 , 0 ) ;
}
F_22 ( V_6 . V_57 ) ;
F_10 ( L_9 , V_27 ) ;
return V_27 ;
}
static int F_23 ( struct V_14 * V_14 , struct V_59 * V_60 )
{
struct V_61 V_43 = {
. V_44 = F_15 ( V_14 ) ,
} ;
struct V_62 V_6 ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_63 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
. V_48 = V_60 -> V_64 ,
} ;
int V_65 = V_60 -> V_66 ;
int V_27 = - V_58 ;
F_10 ( L_10 ) ;
if ( V_65 & V_67 )
V_43 . V_68 |= V_69 ;
if ( F_24 ( V_14 -> V_70 ) ) {
if ( V_65 & V_71 )
V_43 . V_68 |= V_72 | V_73 | V_74 ;
if ( V_65 & V_75 )
V_43 . V_68 |= V_76 ;
} else {
if ( V_65 & V_71 )
V_43 . V_68 |= V_72 | V_73 ;
if ( V_65 & V_75 )
V_43 . V_68 |= V_77 ;
}
V_6 . V_29 = F_20 () ;
if ( V_6 . V_29 == NULL )
goto V_78;
V_27 = F_2 ( F_17 ( V_14 ) , & V_4 , 0 ) ;
F_21 ( V_14 , V_6 . V_29 ) ;
if ( V_27 == 0 ) {
V_60 -> V_66 = 0 ;
if ( V_6 . V_68 & V_69 )
V_60 -> V_66 |= V_67 ;
if ( V_6 . V_68 & ( V_72 | V_73 | V_74 ) )
V_60 -> V_66 |= V_71 ;
if ( V_6 . V_68 & ( V_76 | V_77 ) )
V_60 -> V_66 |= V_75 ;
}
F_22 ( V_6 . V_29 ) ;
V_78:
F_10 ( L_11 , V_27 ) ;
return V_27 ;
}
static int F_25 ( struct V_14 * V_14 , struct V_79 * V_79 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_37 * V_29 ;
struct V_82 args = {
. V_44 = F_15 ( V_14 ) ,
. V_80 = V_80 ,
. V_81 = V_81 ,
. V_83 = & V_79
} ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_84 ] ,
. V_25 = & args ,
} ;
int V_27 = - V_58 ;
F_10 ( L_12 ) ;
V_29 = F_20 () ;
if ( V_29 == NULL )
goto V_78;
V_4 . V_26 = V_29 ;
V_27 = F_2 ( F_17 ( V_14 ) , & V_4 , 0 ) ;
F_21 ( V_14 , V_29 ) ;
F_22 ( V_29 ) ;
V_78:
F_10 ( L_13 , V_27 ) ;
return V_27 ;
}
static struct V_85 * F_26 ( void )
{
struct V_85 * V_86 ;
V_86 = F_27 ( sizeof( * V_86 ) , V_87 ) ;
if ( V_86 != NULL ) {
V_86 -> V_4 . V_25 = & V_86 -> V_43 ;
V_86 -> V_4 . V_26 = & V_86 -> V_6 ;
V_86 -> V_6 . V_44 = & V_86 -> V_44 ;
V_86 -> V_6 . V_29 = & V_86 -> V_29 ;
V_86 -> V_6 . V_57 = & V_86 -> V_57 ;
F_11 ( V_86 -> V_6 . V_29 ) ;
F_11 ( V_86 -> V_6 . V_57 ) ;
}
return V_86 ;
}
static int F_28 ( struct V_14 * V_50 , struct V_38 * V_38 , struct V_85 * V_86 )
{
int V_27 ;
V_27 = F_2 ( F_17 ( V_50 ) , & V_86 -> V_4 , 0 ) ;
F_29 ( V_50 , V_86 -> V_6 . V_57 ) ;
if ( V_27 == 0 )
V_27 = F_30 ( V_38 , V_86 -> V_6 . V_44 , V_86 -> V_6 . V_29 ) ;
return V_27 ;
}
static void F_31 ( struct V_85 * V_86 )
{
F_32 ( V_86 ) ;
}
static int
F_33 ( struct V_14 * V_50 , struct V_38 * V_38 , struct V_39 * V_40 ,
int V_5 , struct V_88 * V_89 )
{
struct V_85 * V_86 ;
T_1 V_65 = V_40 -> V_90 ;
int V_27 = - V_58 ;
F_10 ( L_14 , V_38 -> V_91 . V_52 ) ;
V_86 = F_26 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_22 = & V_23 [ V_92 ] ;
V_86 -> V_43 . V_93 . V_44 = F_15 ( V_50 ) ;
V_86 -> V_43 . V_93 . V_52 = V_38 -> V_91 . V_52 ;
V_86 -> V_43 . V_93 . V_54 = V_38 -> V_91 . V_54 ;
V_86 -> V_43 . V_93 . V_40 = V_40 ;
V_86 -> V_43 . V_93 . V_94 = V_95 ;
if ( V_5 & V_96 ) {
V_86 -> V_43 . V_93 . V_94 = V_97 ;
V_86 -> V_43 . V_93 . V_98 [ 0 ] = V_99 ;
V_86 -> V_43 . V_93 . V_98 [ 1 ] = V_11 -> V_100 ;
}
V_40 -> V_90 &= ~ F_34 () ;
for (; ; ) {
V_27 = F_28 ( V_50 , V_38 , V_86 ) ;
if ( V_27 != - V_101 )
break;
switch ( V_86 -> V_43 . V_93 . V_94 ) {
case V_97 :
V_86 -> V_43 . V_93 . V_94 = V_102 ;
break;
case V_102 :
V_86 -> V_43 . V_93 . V_94 = V_95 ;
break;
case V_95 :
goto V_78;
}
F_11 ( V_86 -> V_6 . V_57 ) ;
F_11 ( V_86 -> V_6 . V_29 ) ;
}
if ( V_27 != 0 )
goto V_78;
if ( V_86 -> V_43 . V_93 . V_94 == V_97 ) {
F_10 ( L_15 ) ;
if ( ! ( V_40 -> V_46 & V_103 ) )
V_40 -> V_46 |= V_104 ;
if ( ! ( V_40 -> V_46 & V_105 ) )
V_40 -> V_46 |= V_106 ;
V_27 = F_14 ( V_38 , V_86 -> V_6 . V_29 , V_40 ) ;
F_29 ( V_38 -> V_41 , V_86 -> V_6 . V_29 ) ;
F_10 ( L_16 , V_27 ) ;
if ( V_27 != 0 )
goto V_78;
}
V_27 = F_35 ( V_50 , V_38 -> V_41 , V_65 ) ;
V_78:
F_31 ( V_86 ) ;
F_10 ( L_17 , V_27 ) ;
return V_27 ;
}
static int
F_36 ( struct V_14 * V_50 , struct V_51 * V_52 )
{
struct V_107 V_43 = {
. V_44 = F_15 ( V_50 ) ,
. V_52 . V_54 = V_52 -> V_54 ,
. V_52 . V_52 = V_52 -> V_52 ,
} ;
struct V_108 V_6 ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_109 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
} ;
int V_27 = - V_58 ;
F_10 ( L_18 , V_52 -> V_52 ) ;
V_6 . V_57 = F_20 () ;
if ( V_6 . V_57 == NULL )
goto V_78;
V_27 = F_2 ( F_17 ( V_50 ) , & V_4 , 0 ) ;
F_29 ( V_50 , V_6 . V_57 ) ;
F_22 ( V_6 . V_57 ) ;
V_78:
F_10 ( L_19 , V_27 ) ;
return V_27 ;
}
static void
F_37 ( struct V_3 * V_4 , struct V_14 * V_50 )
{
V_4 -> V_22 = & V_23 [ V_109 ] ;
}
static void F_38 ( struct V_12 * V_13 , struct V_110 * V_86 )
{
F_39 ( V_13 ) ;
}
static int
F_40 ( struct V_12 * V_13 , struct V_14 * V_50 )
{
struct V_108 * V_6 ;
if ( F_5 ( V_13 , V_50 ) )
return 0 ;
V_6 = V_13 -> V_111 . V_26 ;
F_29 ( V_50 , V_6 -> V_57 ) ;
return 1 ;
}
static void
F_41 ( struct V_3 * V_4 , struct V_14 * V_50 )
{
V_4 -> V_22 = & V_23 [ V_112 ] ;
}
static void F_42 ( struct V_12 * V_13 , struct V_113 * V_86 )
{
F_39 ( V_13 ) ;
}
static int
F_43 ( struct V_12 * V_13 , struct V_14 * V_114 ,
struct V_14 * V_115 )
{
struct V_116 * V_6 ;
if ( F_5 ( V_13 , V_114 ) )
return 0 ;
V_6 = V_13 -> V_111 . V_26 ;
F_29 ( V_114 , V_6 -> V_117 ) ;
F_29 ( V_115 , V_6 -> V_118 ) ;
return 1 ;
}
static int
F_44 ( struct V_14 * V_114 , struct V_51 * V_119 ,
struct V_14 * V_115 , struct V_51 * V_120 )
{
struct V_121 V_43 = {
. V_114 = F_15 ( V_114 ) ,
. V_119 = V_119 ,
. V_115 = F_15 ( V_115 ) ,
. V_120 = V_120 ,
} ;
struct V_116 V_6 ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_112 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
} ;
int V_27 = - V_58 ;
F_10 ( L_20 , V_119 -> V_52 , V_120 -> V_52 ) ;
V_6 . V_117 = F_20 () ;
V_6 . V_118 = F_20 () ;
if ( V_6 . V_117 == NULL || V_6 . V_118 == NULL )
goto V_78;
V_27 = F_2 ( F_17 ( V_114 ) , & V_4 , 0 ) ;
F_29 ( V_114 , V_6 . V_117 ) ;
F_29 ( V_115 , V_6 . V_118 ) ;
V_78:
F_22 ( V_6 . V_117 ) ;
F_22 ( V_6 . V_118 ) ;
F_10 ( L_21 , V_27 ) ;
return V_27 ;
}
static int
F_45 ( struct V_14 * V_14 , struct V_14 * V_50 , struct V_51 * V_52 )
{
struct V_122 V_43 = {
. V_123 = F_15 ( V_14 ) ,
. V_124 = F_15 ( V_50 ) ,
. V_125 = V_52 -> V_52 ,
. V_126 = V_52 -> V_54
} ;
struct V_127 V_6 ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_128 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
} ;
int V_27 = - V_58 ;
F_10 ( L_22 , V_52 -> V_52 ) ;
V_6 . V_29 = F_20 () ;
V_6 . V_57 = F_20 () ;
if ( V_6 . V_29 == NULL || V_6 . V_57 == NULL )
goto V_78;
V_27 = F_2 ( F_17 ( V_14 ) , & V_4 , 0 ) ;
F_29 ( V_50 , V_6 . V_57 ) ;
F_29 ( V_14 , V_6 . V_29 ) ;
V_78:
F_22 ( V_6 . V_57 ) ;
F_22 ( V_6 . V_29 ) ;
F_10 ( L_23 , V_27 ) ;
return V_27 ;
}
static int
F_46 ( struct V_14 * V_50 , struct V_38 * V_38 , struct V_79 * V_79 ,
unsigned int V_54 , struct V_39 * V_40 )
{
struct V_85 * V_86 ;
int V_27 = - V_58 ;
if ( V_54 > V_129 )
return - V_130 ;
F_10 ( L_24 , V_38 -> V_91 . V_52 ) ;
V_86 = F_26 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_22 = & V_23 [ V_131 ] ;
V_86 -> V_43 . V_132 . V_123 = F_15 ( V_50 ) ;
V_86 -> V_43 . V_132 . V_133 = V_38 -> V_91 . V_52 ;
V_86 -> V_43 . V_132 . V_134 = V_38 -> V_91 . V_54 ;
V_86 -> V_43 . V_132 . V_83 = & V_79 ;
V_86 -> V_43 . V_132 . V_135 = V_54 ;
V_86 -> V_43 . V_132 . V_40 = V_40 ;
V_27 = F_28 ( V_50 , V_38 , V_86 ) ;
F_31 ( V_86 ) ;
V_78:
F_10 ( L_25 , V_27 ) ;
return V_27 ;
}
static int
F_47 ( struct V_14 * V_50 , struct V_38 * V_38 , struct V_39 * V_40 )
{
struct V_85 * V_86 ;
T_1 V_65 = V_40 -> V_90 ;
int V_27 = - V_58 ;
F_10 ( L_26 , V_38 -> V_91 . V_52 ) ;
V_40 -> V_90 &= ~ F_34 () ;
V_86 = F_26 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_22 = & V_23 [ V_136 ] ;
V_86 -> V_43 . V_137 . V_44 = F_15 ( V_50 ) ;
V_86 -> V_43 . V_137 . V_52 = V_38 -> V_91 . V_52 ;
V_86 -> V_43 . V_137 . V_54 = V_38 -> V_91 . V_54 ;
V_86 -> V_43 . V_137 . V_40 = V_40 ;
V_27 = F_28 ( V_50 , V_38 , V_86 ) ;
if ( V_27 != 0 )
goto V_78;
V_27 = F_35 ( V_50 , V_38 -> V_41 , V_65 ) ;
V_78:
F_31 ( V_86 ) ;
F_10 ( L_27 , V_27 ) ;
return V_27 ;
}
static int
F_48 ( struct V_14 * V_50 , struct V_51 * V_52 )
{
struct V_37 * V_57 ;
struct V_53 V_43 = {
. V_44 = F_15 ( V_50 ) ,
. V_52 = V_52 -> V_52 ,
. V_54 = V_52 -> V_54
} ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_138 ] ,
. V_25 = & V_43 ,
} ;
int V_27 = - V_58 ;
F_10 ( L_28 , V_52 -> V_52 ) ;
V_57 = F_20 () ;
if ( V_57 == NULL )
goto V_78;
V_4 . V_26 = V_57 ;
V_27 = F_2 ( F_17 ( V_50 ) , & V_4 , 0 ) ;
F_29 ( V_50 , V_57 ) ;
F_22 ( V_57 ) ;
V_78:
F_10 ( L_29 , V_27 ) ;
return V_27 ;
}
static int
F_49 ( struct V_38 * V_38 , struct V_48 * V_64 ,
T_2 V_139 , struct V_79 * * V_83 , unsigned int V_140 , int V_141 )
{
struct V_14 * V_50 = V_38 -> V_41 ;
T_3 * V_142 = F_50 ( V_50 ) ;
struct V_143 V_43 = {
. V_44 = F_15 ( V_50 ) ,
. V_139 = V_139 ,
. V_142 = { V_142 [ 0 ] , V_142 [ 1 ] } ,
. V_141 = V_141 ,
. V_140 = V_140 ,
. V_83 = V_83
} ;
struct V_144 V_6 = {
. V_142 = V_142 ,
. V_141 = V_141
} ;
struct V_3 V_4 = {
. V_22 = & V_23 [ V_145 ] ,
. V_25 = & V_43 ,
. V_26 = & V_6 ,
. V_48 = V_64
} ;
int V_27 = - V_58 ;
if ( V_141 )
V_4 . V_22 = & V_23 [ V_146 ] ;
F_10 ( L_30 ,
V_141 ? L_31 : L_32 , ( unsigned int ) V_139 ) ;
V_6 . V_57 = F_20 () ;
if ( V_6 . V_57 == NULL )
goto V_78;
V_27 = F_2 ( F_17 ( V_50 ) , & V_4 , 0 ) ;
F_51 ( V_50 ) ;
F_21 ( V_50 , V_6 . V_57 ) ;
F_22 ( V_6 . V_57 ) ;
V_78:
F_10 ( L_33 ,
V_141 ? L_31 : L_32 , V_27 ) ;
return V_27 ;
}
static int
F_52 ( struct V_14 * V_50 , struct V_38 * V_38 , struct V_39 * V_40 ,
T_4 V_147 )
{
struct V_85 * V_86 ;
T_1 V_65 = V_40 -> V_90 ;
int V_27 = - V_58 ;
F_10 ( L_34 , V_38 -> V_91 . V_52 ,
F_53 ( V_147 ) , F_54 ( V_147 ) ) ;
V_40 -> V_90 &= ~ F_34 () ;
V_86 = F_26 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_22 = & V_23 [ V_148 ] ;
V_86 -> V_43 . V_149 . V_44 = F_15 ( V_50 ) ;
V_86 -> V_43 . V_149 . V_52 = V_38 -> V_91 . V_52 ;
V_86 -> V_43 . V_149 . V_54 = V_38 -> V_91 . V_54 ;
V_86 -> V_43 . V_149 . V_40 = V_40 ;
V_86 -> V_43 . V_149 . V_147 = V_147 ;
switch ( V_40 -> V_90 & V_150 ) {
case V_151 :
V_86 -> V_43 . V_149 . type = V_152 ;
break;
case V_153 :
V_86 -> V_43 . V_149 . type = V_154 ;
break;
case V_155 :
V_86 -> V_43 . V_149 . type = V_156 ;
break;
case V_157 :
V_86 -> V_43 . V_149 . type = V_158 ;
break;
default:
V_27 = - V_159 ;
goto V_78;
}
V_27 = F_28 ( V_50 , V_38 , V_86 ) ;
if ( V_27 != 0 )
goto V_78;
V_27 = F_35 ( V_50 , V_38 -> V_41 , V_65 ) ;
V_78:
F_31 ( V_86 ) ;
F_10 ( L_35 , V_27 ) ;
return V_27 ;
}
static int
F_55 ( struct V_33 * V_34 , struct V_18 * V_19 ,
struct V_160 * V_161 )
{
struct V_3 V_4 = {
. V_22 = & V_23 [ V_162 ] ,
. V_25 = V_19 ,
. V_26 = V_161 ,
} ;
int V_27 ;
F_10 ( L_36 ) ;
F_11 ( V_161 -> V_29 ) ;
V_27 = F_2 ( V_34 -> V_17 , & V_4 , 0 ) ;
F_10 ( L_37 , V_27 ) ;
return V_27 ;
}
static int
F_56 ( struct V_1 * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_3 V_4 = {
. V_22 = & V_23 [ V_24 ] ,
. V_25 = V_19 ,
. V_26 = V_21 ,
} ;
int V_27 ;
F_10 ( L_38 ) ;
F_11 ( V_21 -> V_29 ) ;
V_27 = F_2 ( V_17 , & V_4 , 0 ) ;
F_10 ( L_39 , V_27 ) ;
return V_27 ;
}
static int
F_57 ( struct V_33 * V_34 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
int V_27 ;
V_27 = F_56 ( V_34 -> V_17 , V_19 , V_21 ) ;
if ( V_27 && V_34 -> V_35 -> V_36 != V_34 -> V_17 )
V_27 = F_56 ( V_34 -> V_35 -> V_36 , V_19 , V_21 ) ;
return V_27 ;
}
static int
F_58 ( struct V_33 * V_34 , struct V_18 * V_19 ,
struct V_163 * V_21 )
{
struct V_3 V_4 = {
. V_22 = & V_23 [ V_164 ] ,
. V_25 = V_19 ,
. V_26 = V_21 ,
} ;
int V_27 ;
F_10 ( L_40 ) ;
F_11 ( V_21 -> V_29 ) ;
V_27 = F_2 ( V_34 -> V_17 , & V_4 , 0 ) ;
F_10 ( L_41 , V_27 ) ;
return V_27 ;
}
static int F_59 ( struct V_12 * V_13 , struct V_165 * V_86 )
{
if ( F_5 ( V_13 , V_86 -> V_14 ) )
return - V_166 ;
F_51 ( V_86 -> V_14 ) ;
F_21 ( V_86 -> V_14 , & V_86 -> V_29 ) ;
return 0 ;
}
static void F_60 ( struct V_165 * V_86 , struct V_3 * V_4 )
{
V_4 -> V_22 = & V_23 [ V_167 ] ;
}
static void F_61 ( struct V_12 * V_13 , struct V_165 * V_86 )
{
F_39 ( V_13 ) ;
}
static int F_62 ( struct V_12 * V_13 , struct V_168 * V_86 )
{
if ( F_5 ( V_13 , V_86 -> V_14 ) )
return - V_166 ;
if ( V_13 -> V_15 >= 0 )
F_63 ( V_86 -> V_14 , V_86 -> V_6 . V_29 ) ;
return 0 ;
}
static void F_64 ( struct V_168 * V_86 , struct V_3 * V_4 )
{
V_4 -> V_22 = & V_23 [ V_169 ] ;
}
static void F_65 ( struct V_12 * V_13 , struct V_168 * V_86 )
{
F_39 ( V_13 ) ;
}
static int F_66 ( struct V_12 * V_13 , struct V_168 * V_86 )
{
if ( F_5 ( V_13 , V_86 -> V_14 ) )
return - V_166 ;
F_21 ( V_86 -> V_14 , V_86 -> V_6 . V_29 ) ;
return 0 ;
}
static void F_67 ( struct V_168 * V_86 , struct V_3 * V_4 )
{
V_4 -> V_22 = & V_23 [ V_170 ] ;
}
static int
F_68 ( struct V_171 * V_172 , int V_173 , struct V_174 * V_175 )
{
struct V_14 * V_14 = V_172 -> V_176 . V_38 -> V_41 ;
return F_69 ( F_70 ( V_14 ) -> V_177 , V_173 , V_175 ) ;
}
