static void F_1 ( struct V_1 * V_2 )
{
++ V_2 -> V_3 ;
if ( V_2 -> V_3 < 1024 )
return;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
++ V_2 -> V_4 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return ! V_2 -> V_5 &&
V_2 -> V_3 / 64 >= V_2 -> V_4 ;
}
static bool F_4 ( struct V_6 * V_7 )
{
return F_5 ( V_8 ) &&
F_6 ( V_7 -> V_9 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 , struct V_11 * V_13 ,
T_1 V_14 , int V_15 )
{
int V_16 = 0 ;
T_1 V_17 ;
while ( V_14 && V_16 < V_15 ) {
V_17 = F_8 ( V_12 -> V_18 , V_14 ) ;
V_13 -> V_19 = V_12 -> V_19 ;
V_13 -> V_18 = V_17 ;
V_12 -> V_18 -= V_17 ;
V_12 -> V_19 += V_17 ;
V_14 -= V_17 ;
++ V_12 ;
++ V_13 ;
++ V_16 ;
}
return V_16 ;
}
static void F_9 ( const struct V_11 * V_12 , struct V_11 * V_13 ,
T_1 V_14 , int V_20 )
{
int V_16 = 0 ;
T_1 V_17 ;
while ( V_14 && V_16 < V_20 ) {
V_17 = F_8 ( V_12 -> V_18 , V_14 ) ;
V_13 -> V_19 = V_12 -> V_19 ;
V_13 -> V_18 = V_17 ;
V_14 -= V_17 ;
++ V_12 ;
++ V_13 ;
++ V_16 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 -> V_21 != V_22 ) )
return;
F_12 ( V_2 -> V_23 + V_24 ) ;
V_2 -> V_21 = V_25 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_26 ;
if ( F_5 ( V_2 -> V_21 != V_25 ) )
return 0 ;
V_26 = F_14 ( V_2 -> V_23 + V_24 , V_7 -> V_27 ) ;
if ( ! V_26 )
V_2 -> V_21 = V_22 ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_30 ;
int V_31 = 0 ;
for ( V_30 = V_29 -> V_32 ; V_30 != V_29 -> V_33 ; V_30 = ( V_30 + 1 ) % V_34 ) {
if ( V_29 -> V_35 [ V_30 ] . V_14 == V_36 )
F_2 ( V_2 ) ;
if ( F_16 ( V_29 -> V_35 [ V_30 ] . V_14 ) ) {
V_29 -> V_35 [ V_30 ] . V_14 = V_37 ;
F_17 ( V_29 -> V_38 , V_29 ,
V_29 -> V_35 [ V_30 ] . V_39 , 0 ) ;
++ V_31 ;
} else
break;
}
if ( V_31 )
V_29 -> V_32 = V_30 ;
return V_31 ;
}
static void F_18 ( struct V_40 * V_41 , bool V_42 )
{
struct V_43 * V_44 = V_41 -> V_45 ;
struct V_28 * V_29 = V_44 -> V_29 ;
int V_46 = F_19 ( & V_44 -> V_47 . V_48 ) ;
if ( V_46 <= 2 || ! ( V_46 % 16 ) )
F_20 ( & V_29 -> V_23 ) ;
V_29 -> V_35 [ V_41 -> V_49 ] . V_14 = V_42 ?
V_50 : V_36 ;
F_21 ( V_44 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = & V_2 -> V_38 . V_51 [ V_24 ] ;
unsigned V_52 , V_53 , V_54 ;
int V_55 ;
struct V_56 V_57 = {
. V_58 = NULL ,
. V_59 = 0 ,
. V_60 = NULL ,
. V_61 = 0 ,
. V_62 = V_29 -> V_63 ,
. V_64 = V_65 ,
} ;
T_1 V_14 , V_66 = 0 ;
int V_67 , V_68 ;
T_1 V_69 ;
struct V_6 * V_7 ;
struct V_43 * V_70 ( V_44 ) ;
bool V_71 , V_72 ;
V_7 = F_23 ( V_29 -> V_73 , 1 ) ;
if ( ! V_7 )
return;
V_68 = F_19 ( & V_7 -> V_9 -> V_74 ) ;
if ( V_68 >= V_7 -> V_9 -> V_75 ) {
F_24 ( & V_29 -> V_76 ) ;
F_13 ( V_2 , V_7 ) ;
F_25 ( & V_29 -> V_76 ) ;
return;
}
F_24 ( & V_29 -> V_76 ) ;
F_26 ( & V_2 -> V_38 , V_29 ) ;
if ( V_68 < V_7 -> V_9 -> V_75 / 2 )
F_10 ( V_2 ) ;
V_69 = V_29 -> V_77 ;
V_71 = V_29 -> V_44 ;
for (; ; ) {
if ( V_71 )
F_15 ( V_2 , V_29 ) ;
V_55 = F_27 ( & V_2 -> V_38 , V_29 , V_29 -> V_63 ,
F_28 ( V_29 -> V_63 ) ,
& V_52 , & V_53 ,
NULL , NULL ) ;
if ( F_5 ( V_55 < 0 ) )
break;
if ( V_55 == V_29 -> V_78 ) {
int V_79 ;
V_68 = F_19 ( & V_7 -> V_9 -> V_74 ) ;
if ( V_68 >= V_7 -> V_9 -> V_75 * 3 / 4 ) {
F_13 ( V_2 , V_7 ) ;
F_29 ( V_80 , & V_7 -> V_81 ) ;
break;
}
V_79 = F_11 ( V_29 -> V_33 >= V_29 -> V_32 ) ?
( V_29 -> V_33 - V_29 -> V_32 ) :
( V_29 -> V_33 + V_34 - V_29 -> V_32 ) ;
if ( F_5 ( V_79 > V_82 ) ) {
F_13 ( V_2 , V_7 ) ;
F_29 ( V_80 , & V_7 -> V_81 ) ;
break;
}
if ( F_5 ( F_30 ( & V_2 -> V_38 , V_29 ) ) ) {
F_26 ( & V_2 -> V_38 , V_29 ) ;
continue;
}
break;
}
if ( V_53 ) {
F_31 ( V_29 , L_1
L_2 , V_52 , V_53 ) ;
break;
}
V_54 = F_7 ( V_29 -> V_63 , V_29 -> V_83 , V_69 , V_52 ) ;
V_57 . V_84 = V_52 ;
V_14 = F_32 ( V_29 -> V_63 , V_52 ) ;
if ( ! V_14 ) {
F_31 ( V_29 , L_3
L_4 ,
F_32 ( V_29 -> V_83 , V_54 ) , V_69 ) ;
break;
}
V_72 = V_71 && ( V_14 >= V_85 ||
V_29 -> V_33 != V_29 -> V_32 ) ;
if ( V_72 ) {
V_29 -> V_35 [ V_29 -> V_33 ] . V_39 = V_55 ;
if ( ! F_3 ( V_2 ) ||
V_14 < V_85 ) {
V_29 -> V_35 [ V_29 -> V_33 ] . V_14 =
V_50 ;
V_57 . V_60 = NULL ;
V_57 . V_61 = 0 ;
V_44 = NULL ;
} else {
struct V_40 * V_41 = & V_29 -> V_40 [ V_55 ] ;
V_29 -> V_35 [ V_29 -> V_33 ] . V_14 =
V_86 ;
V_41 -> V_87 = F_18 ;
V_41 -> V_45 = V_29 -> V_44 ;
V_41 -> V_49 = V_29 -> V_33 ;
V_57 . V_60 = V_41 ;
V_57 . V_61 = sizeof( V_41 ) ;
V_44 = V_29 -> V_44 ;
F_33 ( & V_44 -> V_47 ) ;
}
V_29 -> V_33 = ( V_29 -> V_33 + 1 ) % V_34 ;
}
V_67 = V_7 -> V_88 -> V_89 ( NULL , V_7 , & V_57 , V_14 ) ;
if ( F_5 ( V_67 < 0 ) ) {
if ( V_72 ) {
if ( V_44 )
F_21 ( V_44 ) ;
V_29 -> V_33 = ( ( unsigned ) V_29 -> V_33 - 1 ) %
V_34 ;
}
F_34 ( V_29 , 1 ) ;
if ( V_67 == - V_90 || V_67 == - V_91 )
F_13 ( V_2 , V_7 ) ;
break;
}
if ( V_67 != V_14 )
F_35 ( L_5
L_6 , V_67 , V_14 ) ;
if ( ! V_72 )
F_17 ( & V_2 -> V_38 , V_29 , V_55 , 0 ) ;
else
F_15 ( V_2 , V_29 ) ;
V_66 += V_14 ;
F_1 ( V_2 ) ;
if ( F_5 ( V_66 >= V_92 ) ) {
F_20 ( & V_29 -> V_23 ) ;
break;
}
}
F_25 ( & V_29 -> V_76 ) ;
}
static int F_36 ( struct V_7 * V_9 )
{
struct V_93 * V_55 ;
int V_14 = 0 ;
unsigned long V_81 ;
F_37 ( & V_9 -> V_94 . V_95 , V_81 ) ;
V_55 = F_38 ( & V_9 -> V_94 ) ;
if ( F_11 ( V_55 ) ) {
V_14 = V_55 -> V_14 ;
if ( F_39 ( V_55 ) )
V_14 += V_96 ;
}
F_40 ( & V_9 -> V_94 . V_95 , V_81 ) ;
return V_14 ;
}
static int F_41 ( struct V_28 * V_29 ,
struct V_97 * V_35 ,
int V_98 ,
unsigned * V_20 ,
struct V_99 * log ,
unsigned * V_100 ,
unsigned int V_101 )
{
unsigned int V_52 , V_53 ;
int V_16 = 0 ;
int V_102 = 0 ;
unsigned V_103 ;
int V_104 , V_105 = 0 ;
while ( V_98 > 0 && V_102 < V_101 ) {
if ( F_5 ( V_16 >= V_34 ) ) {
V_104 = - V_91 ;
goto V_67;
}
V_103 = F_27 ( V_29 -> V_38 , V_29 , V_29 -> V_63 + V_16 ,
F_28 ( V_29 -> V_63 ) - V_16 , & V_52 ,
& V_53 , log , V_100 ) ;
if ( V_103 == V_29 -> V_78 ) {
V_104 = 0 ;
goto V_67;
}
if ( F_5 ( V_52 || V_53 <= 0 ) ) {
F_31 ( V_29 , L_7
L_8 , V_52 , V_53 ) ;
V_104 = - V_106 ;
goto V_67;
}
if ( F_5 ( log ) ) {
V_105 += * V_100 ;
log += * V_100 ;
}
V_35 [ V_102 ] . V_39 = V_103 ;
V_35 [ V_102 ] . V_14 = F_32 ( V_29 -> V_63 + V_16 , V_53 ) ;
V_98 -= V_35 [ V_102 ] . V_14 ;
++ V_102 ;
V_16 += V_53 ;
}
V_35 [ V_102 - 1 ] . V_14 += V_98 ;
* V_20 = V_16 ;
if ( F_5 ( log ) )
* V_100 = V_105 ;
return V_102 ;
V_67:
F_34 ( V_29 , V_102 ) ;
return V_104 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = & V_2 -> V_38 . V_51 [ V_107 ] ;
unsigned V_70 ( V_53 ) , log ;
struct V_99 * V_108 ;
struct V_56 V_57 = {
. V_58 = NULL ,
. V_59 = 0 ,
. V_60 = NULL ,
. V_61 = 0 ,
. V_62 = V_29 -> V_63 ,
. V_64 = V_65 ,
} ;
struct V_109 V_83 = {
. V_83 . V_81 = 0 ,
. V_83 . V_110 = V_111
} ;
T_1 V_66 = 0 ;
int V_67 , V_112 ;
T_2 V_102 ;
T_1 V_77 , V_113 ;
T_1 V_114 , V_115 ;
struct V_6 * V_7 = F_23 ( V_29 -> V_73 , 1 ) ;
if ( ! V_7 )
return;
F_24 ( & V_29 -> V_76 ) ;
F_26 ( & V_2 -> V_38 , V_29 ) ;
V_77 = V_29 -> V_77 ;
V_113 = V_29 -> V_113 ;
V_108 = F_5 ( F_43 ( & V_2 -> V_38 , V_116 ) ) ?
V_29 -> log : NULL ;
V_112 = F_43 ( & V_2 -> V_38 , V_117 ) ;
while ( ( V_115 = F_36 ( V_7 -> V_9 ) ) ) {
V_115 += V_113 ;
V_114 = V_115 + V_77 ;
V_102 = F_41 ( V_29 , V_29 -> V_35 , V_114 ,
& V_53 , V_108 , & log ,
F_11 ( V_112 ) ? V_34 : 1 ) ;
if ( F_5 ( V_102 < 0 ) )
break;
if ( ! V_102 ) {
if ( F_5 ( F_30 ( & V_2 -> V_38 , V_29 ) ) ) {
F_26 ( & V_2 -> V_38 , V_29 ) ;
continue;
}
break;
}
if ( F_5 ( ( V_77 ) ) )
F_7 ( V_29 -> V_63 , V_29 -> V_83 , V_77 , V_53 ) ;
else
F_9 ( V_29 -> V_63 , V_29 -> V_83 , V_113 , V_53 ) ;
V_57 . V_84 = V_53 ;
V_67 = V_7 -> V_88 -> V_118 ( NULL , V_7 , & V_57 ,
V_115 , V_65 | V_119 ) ;
if ( F_5 ( V_67 != V_115 ) ) {
F_35 ( L_9
L_10 , V_67 , V_115 ) ;
F_34 ( V_29 , V_102 ) ;
continue;
}
if ( F_5 ( V_77 ) &&
F_44 ( V_29 -> V_83 , ( unsigned char * ) & V_83 , 0 ,
V_77 ) ) {
F_31 ( V_29 , L_11 ,
V_29 -> V_63 -> V_19 ) ;
break;
}
if ( F_11 ( V_112 ) &&
F_44 ( V_29 -> V_83 , ( unsigned char * ) & V_102 ,
F_45 ( F_46 ( V_83 ) , V_120 ) ,
sizeof V_83 . V_120 ) ) {
F_31 ( V_29 , L_12 ) ;
F_34 ( V_29 , V_102 ) ;
break;
}
F_47 ( & V_2 -> V_38 , V_29 , V_29 -> V_35 ,
V_102 ) ;
if ( F_5 ( V_108 ) )
F_48 ( V_29 , V_108 , log , V_114 ) ;
V_66 += V_114 ;
if ( F_5 ( V_66 >= V_92 ) ) {
F_20 ( & V_29 -> V_23 ) ;
break;
}
}
F_25 ( & V_29 -> V_76 ) ;
}
static void F_49 ( struct V_121 * V_122 )
{
struct V_28 * V_29 = F_50 ( V_122 , struct V_28 ,
V_23 . V_122 ) ;
struct V_1 * V_2 = F_50 ( V_29 -> V_38 , struct V_1 , V_38 ) ;
F_22 ( V_2 ) ;
}
static void F_51 ( struct V_121 * V_122 )
{
struct V_28 * V_29 = F_50 ( V_122 , struct V_28 ,
V_23 . V_122 ) ;
struct V_1 * V_2 = F_50 ( V_29 -> V_38 , struct V_1 , V_38 ) ;
F_42 ( V_2 ) ;
}
static void F_52 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_50 ( V_122 , struct V_1 ,
V_23 [ V_24 ] . V_122 ) ;
F_22 ( V_2 ) ;
}
static void F_53 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_50 ( V_122 , struct V_1 ,
V_23 [ V_107 ] . V_122 ) ;
F_42 ( V_2 ) ;
}
static int F_54 ( struct V_123 * V_123 , struct V_27 * V_124 )
{
struct V_1 * V_125 = F_55 ( sizeof *V_125 , V_126 ) ;
struct V_127 * V_38 ;
int V_104 ;
if ( ! V_125 )
return - V_128 ;
V_38 = & V_125 -> V_38 ;
V_125 -> V_51 [ V_24 ] . V_129 = F_49 ;
V_125 -> V_51 [ V_107 ] . V_129 = F_51 ;
V_104 = F_56 ( V_38 , V_125 -> V_51 , V_130 ) ;
if ( V_104 < 0 ) {
F_57 ( V_125 ) ;
return V_104 ;
}
F_58 ( V_125 -> V_23 + V_24 , F_52 , V_131 , V_38 ) ;
F_58 ( V_125 -> V_23 + V_107 , F_53 , V_132 , V_38 ) ;
V_125 -> V_21 = V_133 ;
V_124 -> V_73 = V_125 ;
return 0 ;
}
static void F_59 ( struct V_1 * V_125 ,
struct V_28 * V_29 )
{
if ( ! V_29 -> V_73 )
return;
if ( V_29 == V_125 -> V_51 + V_24 ) {
F_10 ( V_125 ) ;
V_125 -> V_21 = V_133 ;
} else
F_12 ( V_125 -> V_23 + V_107 ) ;
}
static int F_60 ( struct V_1 * V_125 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
int V_26 ;
V_7 = F_61 ( V_29 -> V_73 ,
F_62 ( & V_29 -> V_76 ) ) ;
if ( ! V_7 )
return 0 ;
if ( V_29 == V_125 -> V_51 + V_24 ) {
V_125 -> V_21 = V_25 ;
V_26 = F_13 ( V_125 , V_7 ) ;
} else
V_26 = F_14 ( V_125 -> V_23 + V_107 , V_7 -> V_27 ) ;
return V_26 ;
}
static struct V_6 * F_63 ( struct V_1 * V_125 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_24 ( & V_29 -> V_76 ) ;
V_7 = F_61 ( V_29 -> V_73 ,
F_62 ( & V_29 -> V_76 ) ) ;
F_59 ( V_125 , V_29 ) ;
F_64 ( V_29 -> V_73 , NULL ) ;
F_25 ( & V_29 -> V_76 ) ;
return V_7 ;
}
static void F_65 ( struct V_1 * V_125 , struct V_6 * * V_134 ,
struct V_6 * * V_135 )
{
* V_134 = F_63 ( V_125 , V_125 -> V_51 + V_24 ) ;
* V_135 = F_63 ( V_125 , V_125 -> V_51 + V_107 ) ;
}
static void F_66 ( struct V_1 * V_125 , int V_136 )
{
F_67 ( V_125 -> V_23 + V_136 ) ;
F_67 ( & V_125 -> V_38 . V_51 [ V_136 ] . V_23 ) ;
}
static void F_68 ( struct V_1 * V_125 )
{
F_66 ( V_125 , V_24 ) ;
F_66 ( V_125 , V_107 ) ;
if ( V_125 -> V_38 . V_51 [ V_24 ] . V_44 ) {
F_24 ( & V_125 -> V_38 . V_51 [ V_24 ] . V_76 ) ;
V_125 -> V_5 = true ;
F_25 ( & V_125 -> V_38 . V_51 [ V_24 ] . V_76 ) ;
F_69 ( V_125 -> V_38 . V_51 [ V_24 ] . V_44 ) ;
F_24 ( & V_125 -> V_38 . V_51 [ V_24 ] . V_76 ) ;
V_125 -> V_5 = false ;
F_70 ( & V_125 -> V_38 . V_51 [ V_24 ] . V_44 -> V_47 ) ;
F_25 ( & V_125 -> V_38 . V_51 [ V_24 ] . V_76 ) ;
}
}
static int F_71 ( struct V_123 * V_123 , struct V_27 * V_124 )
{
struct V_1 * V_125 = V_124 -> V_73 ;
struct V_6 * V_134 ;
struct V_6 * V_135 ;
F_65 ( V_125 , & V_134 , & V_135 ) ;
F_68 ( V_125 ) ;
F_72 ( & V_125 -> V_38 ) ;
F_73 ( & V_125 -> V_38 , false ) ;
if ( V_134 )
F_74 ( V_134 -> V_27 ) ;
if ( V_135 )
F_74 ( V_135 -> V_27 ) ;
F_68 ( V_125 ) ;
F_57 ( V_125 ) ;
return 0 ;
}
static struct V_6 * F_75 ( int V_137 )
{
struct {
struct V_138 V_139 ;
char V_140 [ V_141 ] ;
} V_142 ;
int V_143 = sizeof V_142 , V_104 ;
struct V_6 * V_7 = F_76 ( V_137 , & V_104 ) ;
if ( ! V_7 )
return F_77 ( - V_144 ) ;
if ( V_7 -> V_9 -> V_145 != V_146 ) {
V_104 = - V_147 ;
goto V_67;
}
V_104 = V_7 -> V_88 -> V_148 ( V_7 , (struct V_149 * ) & V_142 . V_139 ,
& V_143 , 0 ) ;
if ( V_104 )
goto V_67;
if ( V_142 . V_139 . V_150 != V_151 ) {
V_104 = - V_152 ;
goto V_67;
}
return V_7 ;
V_67:
F_74 ( V_7 -> V_27 ) ;
return F_77 ( V_104 ) ;
}
static struct V_6 * F_78 ( int V_137 )
{
struct V_27 * V_27 = F_79 ( V_137 ) ;
struct V_6 * V_7 ;
if ( ! V_27 )
return F_77 ( - V_153 ) ;
V_7 = F_80 ( V_27 ) ;
if ( ! F_81 ( V_7 ) )
return V_7 ;
V_7 = F_82 ( V_27 ) ;
if ( F_81 ( V_7 ) )
F_74 ( V_27 ) ;
return V_7 ;
}
static struct V_6 * F_83 ( int V_137 )
{
struct V_6 * V_7 ;
if ( V_137 == - 1 )
return NULL ;
V_7 = F_75 ( V_137 ) ;
if ( ! F_81 ( V_7 ) )
return V_7 ;
V_7 = F_78 ( V_137 ) ;
if ( ! F_81 ( V_7 ) )
return V_7 ;
return F_77 ( - V_144 ) ;
}
static long F_84 ( struct V_1 * V_125 , unsigned V_136 , int V_137 )
{
struct V_6 * V_7 , * V_154 ;
struct V_28 * V_29 ;
struct V_43 * V_44 , * V_155 = NULL ;
int V_104 ;
F_24 ( & V_125 -> V_38 . V_76 ) ;
V_104 = F_85 ( & V_125 -> V_38 ) ;
if ( V_104 )
goto V_67;
if ( V_136 >= V_130 ) {
V_104 = - V_91 ;
goto V_67;
}
V_29 = V_125 -> V_51 + V_136 ;
F_24 ( & V_29 -> V_76 ) ;
if ( ! F_86 ( V_29 ) ) {
V_104 = - V_156 ;
goto V_157;
}
V_7 = F_83 ( V_137 ) ;
if ( F_81 ( V_7 ) ) {
V_104 = F_87 ( V_7 ) ;
goto V_157;
}
V_154 = F_61 ( V_29 -> V_73 ,
F_62 ( & V_29 -> V_76 ) ) ;
if ( V_7 != V_154 ) {
V_44 = F_88 ( V_29 , V_7 && F_4 ( V_7 ) ) ;
if ( F_81 ( V_44 ) ) {
V_104 = F_87 ( V_44 ) ;
goto V_158;
}
F_59 ( V_125 , V_29 ) ;
F_64 ( V_29 -> V_73 , V_7 ) ;
V_104 = F_89 ( V_29 ) ;
if ( V_104 )
goto V_159;
V_104 = F_60 ( V_125 , V_29 ) ;
if ( V_104 )
goto V_159;
V_155 = V_29 -> V_44 ;
V_29 -> V_44 = V_44 ;
V_125 -> V_3 = 0 ;
V_125 -> V_4 = 0 ;
V_125 -> V_5 = false ;
}
F_25 ( & V_29 -> V_76 ) ;
if ( V_155 ) {
F_69 ( V_155 ) ;
F_24 ( & V_29 -> V_76 ) ;
F_15 ( V_125 , V_29 ) ;
F_25 ( & V_29 -> V_76 ) ;
}
if ( V_154 ) {
F_66 ( V_125 , V_136 ) ;
F_74 ( V_154 -> V_27 ) ;
}
F_25 ( & V_125 -> V_38 . V_76 ) ;
return 0 ;
V_159:
F_64 ( V_29 -> V_73 , V_154 ) ;
F_60 ( V_125 , V_29 ) ;
if ( V_44 )
F_69 ( V_44 ) ;
V_158:
F_74 ( V_7 -> V_27 ) ;
V_157:
F_25 ( & V_29 -> V_76 ) ;
V_67:
F_25 ( & V_125 -> V_38 . V_76 ) ;
return V_104 ;
}
static long F_90 ( struct V_1 * V_125 )
{
struct V_6 * V_134 = NULL ;
struct V_6 * V_135 = NULL ;
long V_67 ;
F_24 ( & V_125 -> V_38 . V_76 ) ;
V_67 = F_85 ( & V_125 -> V_38 ) ;
if ( V_67 )
goto V_160;
F_65 ( V_125 , & V_134 , & V_135 ) ;
F_68 ( V_125 ) ;
V_67 = F_91 ( & V_125 -> V_38 ) ;
V_160:
F_25 ( & V_125 -> V_38 . V_76 ) ;
if ( V_134 )
F_74 ( V_134 -> V_27 ) ;
if ( V_135 )
F_74 ( V_135 -> V_27 ) ;
return V_67 ;
}
static int F_92 ( struct V_1 * V_125 , T_3 V_161 )
{
T_1 V_77 , V_113 , V_162 ;
int V_30 ;
V_162 = ( V_161 & ( 1 << V_117 ) ) ?
sizeof( struct V_109 ) :
sizeof( struct V_163 ) ;
if ( V_161 & ( 1 << V_164 ) ) {
V_77 = V_162 ;
V_113 = 0 ;
} else {
V_77 = 0 ;
V_113 = V_162 ;
}
F_24 ( & V_125 -> V_38 . V_76 ) ;
if ( ( V_161 & ( 1 << V_116 ) ) &&
! F_93 ( & V_125 -> V_38 ) ) {
F_25 ( & V_125 -> V_38 . V_76 ) ;
return - V_156 ;
}
V_125 -> V_38 . V_165 = V_161 ;
F_94 () ;
for ( V_30 = 0 ; V_30 < V_130 ; ++ V_30 ) {
F_24 ( & V_125 -> V_51 [ V_30 ] . V_76 ) ;
V_125 -> V_51 [ V_30 ] . V_77 = V_77 ;
V_125 -> V_51 [ V_30 ] . V_113 = V_113 ;
F_25 ( & V_125 -> V_51 [ V_30 ] . V_76 ) ;
}
F_68 ( V_125 ) ;
F_25 ( & V_125 -> V_38 . V_76 ) ;
return 0 ;
}
static long F_95 ( struct V_27 * V_124 , unsigned int V_166 ,
unsigned long V_167 )
{
struct V_1 * V_125 = V_124 -> V_73 ;
void T_4 * V_168 = ( void T_4 * ) V_167 ;
T_3 T_4 * V_169 = V_168 ;
struct V_170 V_171 ;
T_3 V_161 ;
int V_104 ;
switch ( V_166 ) {
case V_172 :
if ( F_96 ( & V_171 , V_168 , sizeof V_171 ) )
return - V_156 ;
return F_84 ( V_125 , V_171 . V_136 , V_171 . V_137 ) ;
case V_173 :
V_161 = V_174 ;
if ( F_97 ( V_169 , & V_161 , sizeof V_161 ) )
return - V_156 ;
return 0 ;
case V_175 :
if ( F_96 ( & V_161 , V_169 , sizeof V_161 ) )
return - V_156 ;
if ( V_161 & ~ V_174 )
return - V_176 ;
return F_92 ( V_125 , V_161 ) ;
case V_177 :
return F_90 ( V_125 ) ;
default:
F_24 ( & V_125 -> V_38 . V_76 ) ;
V_104 = F_98 ( & V_125 -> V_38 , V_166 , V_168 ) ;
if ( V_104 == - V_178 )
V_104 = F_99 ( & V_125 -> V_38 , V_166 , V_168 ) ;
else
F_68 ( V_125 ) ;
F_25 ( & V_125 -> V_38 . V_76 ) ;
return V_104 ;
}
}
static long F_100 ( struct V_27 * V_124 , unsigned int V_166 ,
unsigned long V_167 )
{
return F_95 ( V_124 , V_166 , ( unsigned long ) F_101 ( V_167 ) ) ;
}
static int F_102 ( void )
{
if ( V_8 )
F_103 ( V_24 ) ;
return F_104 ( & V_179 ) ;
}
static void F_105 ( void )
{
F_106 ( & V_179 ) ;
}
