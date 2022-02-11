static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) &&
F_3 ( V_2 -> V_4 , V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 , struct V_6 * V_8 ,
T_1 V_9 , int V_10 )
{
int V_11 = 0 ;
T_1 V_12 ;
while ( V_9 && V_11 < V_10 ) {
V_12 = F_5 ( V_7 -> V_13 , V_9 ) ;
V_8 -> V_14 = V_7 -> V_14 ;
V_8 -> V_13 = V_12 ;
V_7 -> V_13 -= V_12 ;
V_7 -> V_14 += V_12 ;
V_9 -= V_12 ;
++ V_7 ;
++ V_8 ;
++ V_11 ;
}
return V_11 ;
}
static void F_6 ( const struct V_6 * V_7 , struct V_6 * V_8 ,
T_1 V_9 , int V_15 )
{
int V_11 = 0 ;
T_1 V_12 ;
while ( V_9 && V_11 < V_15 ) {
V_12 = F_5 ( V_7 -> V_13 , V_9 ) ;
V_8 -> V_14 = V_7 -> V_14 ;
V_8 -> V_13 = V_12 ;
V_9 -= V_12 ;
++ V_7 ;
++ V_8 ;
++ V_11 ;
}
}
static void F_7 ( struct V_16 * V_17 )
{
if ( F_8 ( V_17 -> V_18 != V_19 ) )
return;
F_9 ( V_17 -> V_20 + V_21 ) ;
V_17 -> V_18 = V_22 ;
}
static void F_10 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
if ( F_2 ( V_17 -> V_18 != V_22 ) )
return;
F_11 ( V_17 -> V_20 + V_21 , V_2 -> V_23 ) ;
V_17 -> V_18 = V_19 ;
}
static void F_12 ( struct V_16 * V_17 )
{
struct V_24 * V_25 = & V_17 -> V_26 . V_27 [ V_21 ] ;
unsigned V_28 , V_29 , V_30 ;
int V_31 ;
struct V_32 V_33 = {
. V_34 = NULL ,
. V_35 = 0 ,
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_25 -> V_39 ,
. V_40 = V_41 ,
} ;
T_1 V_9 , V_42 = 0 ;
int V_43 , V_44 ;
T_1 V_45 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ( V_48 ) ;
bool V_49 ;
V_2 = F_13 ( V_25 -> V_50 , 1 ) ;
if ( ! V_2 )
return;
V_44 = F_14 ( & V_2 -> V_4 -> V_51 ) ;
if ( V_44 >= V_2 -> V_4 -> V_52 ) {
F_15 ( & V_25 -> V_53 ) ;
F_10 ( V_17 , V_2 ) ;
F_16 ( & V_25 -> V_53 ) ;
return;
}
F_15 ( & V_25 -> V_53 ) ;
F_17 ( & V_17 -> V_26 , V_25 ) ;
if ( V_44 < V_2 -> V_4 -> V_52 / 2 )
F_7 ( V_17 ) ;
V_45 = V_25 -> V_54 ;
V_49 = V_25 -> V_48 ;
for (; ; ) {
if ( V_49 )
F_18 ( V_25 ) ;
V_31 = F_19 ( & V_17 -> V_26 , V_25 , V_25 -> V_39 ,
F_20 ( V_25 -> V_39 ) ,
& V_28 , & V_29 ,
NULL , NULL ) ;
if ( F_2 ( V_31 < 0 ) )
break;
if ( V_31 == V_25 -> V_55 ) {
int V_56 ;
V_44 = F_14 ( & V_2 -> V_4 -> V_51 ) ;
if ( V_44 >= V_2 -> V_4 -> V_52 * 3 / 4 ) {
F_10 ( V_17 , V_2 ) ;
F_21 ( V_57 , & V_2 -> V_58 ) ;
break;
}
V_56 = F_8 ( V_25 -> V_59 >= V_25 -> V_60 ) ?
( V_25 -> V_59 - V_25 -> V_60 ) :
( V_25 -> V_59 + V_61 - V_25 -> V_60 ) ;
if ( F_2 ( V_56 > V_62 ) ) {
F_10 ( V_17 , V_2 ) ;
F_21 ( V_57 , & V_2 -> V_58 ) ;
break;
}
if ( F_2 ( F_22 ( & V_17 -> V_26 , V_25 ) ) ) {
F_17 ( & V_17 -> V_26 , V_25 ) ;
continue;
}
break;
}
if ( V_29 ) {
F_23 ( V_25 , L_1
L_2 , V_28 , V_29 ) ;
break;
}
V_30 = F_4 ( V_25 -> V_39 , V_25 -> V_63 , V_45 , V_28 ) ;
V_33 . V_64 = V_28 ;
V_9 = F_24 ( V_25 -> V_39 , V_28 ) ;
if ( ! V_9 ) {
F_23 ( V_25 , L_3
L_4 ,
F_24 ( V_25 -> V_63 , V_30 ) , V_45 ) ;
break;
}
if ( V_49 ) {
V_25 -> V_65 [ V_25 -> V_59 ] . V_66 = V_31 ;
if ( V_9 < V_67 ) {
V_25 -> V_65 [ V_25 -> V_59 ] . V_9 =
V_68 ;
V_33 . V_36 = NULL ;
V_33 . V_37 = 0 ;
V_48 = NULL ;
} else {
struct V_69 * V_70 = & V_25 -> V_69 [ V_31 ] ;
V_25 -> V_65 [ V_25 -> V_59 ] . V_9 = V_9 ;
V_70 -> V_71 = V_72 ;
V_70 -> V_73 = V_25 -> V_48 ;
V_70 -> V_74 = V_25 -> V_59 ;
V_33 . V_36 = V_70 ;
V_33 . V_37 = sizeof( V_70 ) ;
V_48 = V_25 -> V_48 ;
F_25 ( & V_48 -> V_75 ) ;
}
V_25 -> V_59 = ( V_25 -> V_59 + 1 ) % V_61 ;
}
V_43 = V_2 -> V_76 -> V_77 ( NULL , V_2 , & V_33 , V_9 ) ;
if ( F_2 ( V_43 < 0 ) ) {
if ( V_49 ) {
if ( V_48 )
F_26 ( V_48 ) ;
V_25 -> V_59 = ( ( unsigned ) V_25 -> V_59 - 1 ) %
V_61 ;
}
F_27 ( V_25 , 1 ) ;
if ( V_43 == - V_78 || V_43 == - V_79 )
F_10 ( V_17 , V_2 ) ;
break;
}
if ( V_43 != V_9 )
F_28 ( L_5
L_6 , V_43 , V_9 ) ;
if ( ! V_49 )
F_29 ( & V_17 -> V_26 , V_25 , V_31 , 0 ) ;
else
F_18 ( V_25 ) ;
V_42 += V_9 ;
if ( F_2 ( V_42 >= V_80 ) ) {
F_30 ( & V_25 -> V_20 ) ;
break;
}
}
F_16 ( & V_25 -> V_53 ) ;
}
static int F_31 ( struct V_2 * V_4 )
{
struct V_81 * V_31 ;
int V_9 = 0 ;
unsigned long V_58 ;
F_32 ( & V_4 -> V_82 . V_83 , V_58 ) ;
V_31 = F_33 ( & V_4 -> V_82 ) ;
if ( F_8 ( V_31 ) ) {
V_9 = V_31 -> V_9 ;
if ( F_34 ( V_31 ) )
V_9 += V_84 ;
}
F_35 ( & V_4 -> V_82 . V_83 , V_58 ) ;
return V_9 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_85 * V_65 ,
int V_86 ,
unsigned * V_15 ,
struct V_87 * log ,
unsigned * V_88 ,
unsigned int V_89 )
{
unsigned int V_28 , V_29 ;
int V_11 = 0 ;
int V_90 = 0 ;
unsigned V_91 ;
int V_92 , V_93 = 0 ;
while ( V_86 > 0 && V_90 < V_89 ) {
if ( F_2 ( V_11 >= V_61 ) ) {
V_92 = - V_79 ;
goto V_43;
}
V_91 = F_19 ( V_25 -> V_26 , V_25 , V_25 -> V_39 + V_11 ,
F_20 ( V_25 -> V_39 ) - V_11 , & V_28 ,
& V_29 , log , V_88 ) ;
if ( V_91 == V_25 -> V_55 ) {
V_92 = 0 ;
goto V_43;
}
if ( F_2 ( V_28 || V_29 <= 0 ) ) {
F_23 ( V_25 , L_7
L_8 , V_28 , V_29 ) ;
V_92 = - V_94 ;
goto V_43;
}
if ( F_2 ( log ) ) {
V_93 += * V_88 ;
log += * V_88 ;
}
V_65 [ V_90 ] . V_66 = V_91 ;
V_65 [ V_90 ] . V_9 = F_24 ( V_25 -> V_39 + V_11 , V_29 ) ;
V_86 -= V_65 [ V_90 ] . V_9 ;
++ V_90 ;
V_11 += V_29 ;
}
V_65 [ V_90 - 1 ] . V_9 += V_86 ;
* V_15 = V_11 ;
if ( F_2 ( log ) )
* V_88 = V_93 ;
return V_90 ;
V_43:
F_27 ( V_25 , V_90 ) ;
return V_92 ;
}
static void F_37 ( struct V_16 * V_17 )
{
struct V_24 * V_25 = & V_17 -> V_26 . V_27 [ V_95 ] ;
unsigned V_47 ( V_29 ) , log ;
struct V_87 * V_96 ;
struct V_32 V_33 = {
. V_34 = NULL ,
. V_35 = 0 ,
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_25 -> V_39 ,
. V_40 = V_41 ,
} ;
struct V_97 V_63 = {
. V_63 . V_58 = 0 ,
. V_63 . V_98 = V_99
} ;
T_1 V_42 = 0 ;
int V_43 , V_100 ;
T_2 V_90 ;
T_1 V_54 , V_101 ;
T_1 V_102 , V_103 ;
struct V_1 * V_2 = F_13 ( V_25 -> V_50 , 1 ) ;
if ( ! V_2 )
return;
F_15 ( & V_25 -> V_53 ) ;
F_17 ( & V_17 -> V_26 , V_25 ) ;
V_54 = V_25 -> V_54 ;
V_101 = V_25 -> V_101 ;
V_96 = F_2 ( F_38 ( & V_17 -> V_26 , V_104 ) ) ?
V_25 -> log : NULL ;
V_100 = F_38 ( & V_17 -> V_26 , V_105 ) ;
while ( ( V_103 = F_31 ( V_2 -> V_4 ) ) ) {
V_103 += V_101 ;
V_102 = V_103 + V_54 ;
V_90 = F_36 ( V_25 , V_25 -> V_65 , V_102 ,
& V_29 , V_96 , & log ,
F_8 ( V_100 ) ? V_61 : 1 ) ;
if ( F_2 ( V_90 < 0 ) )
break;
if ( ! V_90 ) {
if ( F_2 ( F_22 ( & V_17 -> V_26 , V_25 ) ) ) {
F_17 ( & V_17 -> V_26 , V_25 ) ;
continue;
}
break;
}
if ( F_2 ( ( V_54 ) ) )
F_4 ( V_25 -> V_39 , V_25 -> V_63 , V_54 , V_29 ) ;
else
F_6 ( V_25 -> V_39 , V_25 -> V_63 , V_101 , V_29 ) ;
V_33 . V_64 = V_29 ;
V_43 = V_2 -> V_76 -> V_106 ( NULL , V_2 , & V_33 ,
V_103 , V_41 | V_107 ) ;
if ( F_2 ( V_43 != V_103 ) ) {
F_28 ( L_9
L_10 , V_43 , V_103 ) ;
F_27 ( V_25 , V_90 ) ;
continue;
}
if ( F_2 ( V_54 ) &&
F_39 ( V_25 -> V_63 , ( unsigned char * ) & V_63 , 0 ,
V_54 ) ) {
F_23 ( V_25 , L_11 ,
V_25 -> V_39 -> V_14 ) ;
break;
}
if ( F_8 ( V_100 ) &&
F_39 ( V_25 -> V_63 , ( unsigned char * ) & V_90 ,
F_40 ( F_41 ( V_63 ) , V_108 ) ,
sizeof V_63 . V_108 ) ) {
F_23 ( V_25 , L_12 ) ;
F_27 ( V_25 , V_90 ) ;
break;
}
F_42 ( & V_17 -> V_26 , V_25 , V_25 -> V_65 ,
V_90 ) ;
if ( F_2 ( V_96 ) )
F_43 ( V_25 , V_96 , log , V_102 ) ;
V_42 += V_102 ;
if ( F_2 ( V_42 >= V_80 ) ) {
F_30 ( & V_25 -> V_20 ) ;
break;
}
}
F_16 ( & V_25 -> V_53 ) ;
}
static void F_44 ( struct V_109 * V_110 )
{
struct V_24 * V_25 = F_45 ( V_110 , struct V_24 ,
V_20 . V_110 ) ;
struct V_16 * V_17 = F_45 ( V_25 -> V_26 , struct V_16 , V_26 ) ;
F_12 ( V_17 ) ;
}
static void F_46 ( struct V_109 * V_110 )
{
struct V_24 * V_25 = F_45 ( V_110 , struct V_24 ,
V_20 . V_110 ) ;
struct V_16 * V_17 = F_45 ( V_25 -> V_26 , struct V_16 , V_26 ) ;
F_37 ( V_17 ) ;
}
static void F_47 ( struct V_109 * V_110 )
{
struct V_16 * V_17 = F_45 ( V_110 , struct V_16 ,
V_20 [ V_21 ] . V_110 ) ;
F_12 ( V_17 ) ;
}
static void F_48 ( struct V_109 * V_110 )
{
struct V_16 * V_17 = F_45 ( V_110 , struct V_16 ,
V_20 [ V_95 ] . V_110 ) ;
F_37 ( V_17 ) ;
}
static int F_49 ( struct V_111 * V_111 , struct V_23 * V_112 )
{
struct V_16 * V_113 = F_50 ( sizeof *V_113 , V_114 ) ;
struct V_115 * V_26 ;
int V_92 ;
if ( ! V_113 )
return - V_116 ;
V_26 = & V_113 -> V_26 ;
V_113 -> V_27 [ V_21 ] . V_117 = F_44 ;
V_113 -> V_27 [ V_95 ] . V_117 = F_46 ;
V_92 = F_51 ( V_26 , V_113 -> V_27 , V_118 ) ;
if ( V_92 < 0 ) {
F_52 ( V_113 ) ;
return V_92 ;
}
F_53 ( V_113 -> V_20 + V_21 , F_47 , V_119 , V_26 ) ;
F_53 ( V_113 -> V_20 + V_95 , F_48 , V_120 , V_26 ) ;
V_113 -> V_18 = V_121 ;
V_112 -> V_50 = V_113 ;
return 0 ;
}
static void F_54 ( struct V_16 * V_113 ,
struct V_24 * V_25 )
{
if ( ! V_25 -> V_50 )
return;
if ( V_25 == V_113 -> V_27 + V_21 ) {
F_7 ( V_113 ) ;
V_113 -> V_18 = V_121 ;
} else
F_9 ( V_113 -> V_20 + V_95 ) ;
}
static void F_55 ( struct V_16 * V_113 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_25 -> V_50 ,
F_57 ( & V_25 -> V_53 ) ) ;
if ( ! V_2 )
return;
if ( V_25 == V_113 -> V_27 + V_21 ) {
V_113 -> V_18 = V_22 ;
F_10 ( V_113 , V_2 ) ;
} else
F_11 ( V_113 -> V_20 + V_95 , V_2 -> V_23 ) ;
}
static struct V_1 * F_58 ( struct V_16 * V_113 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 ;
F_15 ( & V_25 -> V_53 ) ;
V_2 = F_56 ( V_25 -> V_50 ,
F_57 ( & V_25 -> V_53 ) ) ;
F_54 ( V_113 , V_25 ) ;
F_59 ( V_25 -> V_50 , NULL ) ;
F_16 ( & V_25 -> V_53 ) ;
return V_2 ;
}
static void F_60 ( struct V_16 * V_113 , struct V_1 * * V_122 ,
struct V_1 * * V_123 )
{
* V_122 = F_58 ( V_113 , V_113 -> V_27 + V_21 ) ;
* V_123 = F_58 ( V_113 , V_113 -> V_27 + V_95 ) ;
}
static void F_61 ( struct V_16 * V_113 , int V_124 )
{
F_62 ( V_113 -> V_20 + V_124 ) ;
F_62 ( & V_113 -> V_26 . V_27 [ V_124 ] . V_20 ) ;
}
static void F_63 ( struct V_16 * V_113 )
{
F_61 ( V_113 , V_21 ) ;
F_61 ( V_113 , V_95 ) ;
}
static int F_64 ( struct V_111 * V_111 , struct V_23 * V_112 )
{
struct V_16 * V_113 = V_112 -> V_50 ;
struct V_1 * V_122 ;
struct V_1 * V_123 ;
F_60 ( V_113 , & V_122 , & V_123 ) ;
F_63 ( V_113 ) ;
F_65 ( & V_113 -> V_26 , false ) ;
if ( V_122 )
F_66 ( V_122 -> V_23 ) ;
if ( V_123 )
F_66 ( V_123 -> V_23 ) ;
F_63 ( V_113 ) ;
F_52 ( V_113 ) ;
return 0 ;
}
static struct V_1 * F_67 ( int V_125 )
{
struct {
struct V_126 V_127 ;
char V_128 [ V_129 ] ;
} V_130 ;
int V_131 = sizeof V_130 , V_92 ;
struct V_1 * V_2 = F_68 ( V_125 , & V_92 ) ;
if ( ! V_2 )
return F_69 ( - V_132 ) ;
if ( V_2 -> V_4 -> V_133 != V_134 ) {
V_92 = - V_135 ;
goto V_43;
}
V_92 = V_2 -> V_76 -> V_136 ( V_2 , (struct V_137 * ) & V_130 . V_127 ,
& V_131 , 0 ) ;
if ( V_92 )
goto V_43;
if ( V_130 . V_127 . V_138 != V_139 ) {
V_92 = - V_140 ;
goto V_43;
}
return V_2 ;
V_43:
F_66 ( V_2 -> V_23 ) ;
return F_69 ( V_92 ) ;
}
static struct V_1 * F_70 ( int V_125 )
{
struct V_23 * V_23 = F_71 ( V_125 ) ;
struct V_1 * V_2 ;
if ( ! V_23 )
return F_69 ( - V_141 ) ;
V_2 = F_72 ( V_23 ) ;
if ( ! F_73 ( V_2 ) )
return V_2 ;
V_2 = F_74 ( V_23 ) ;
if ( F_73 ( V_2 ) )
F_66 ( V_23 ) ;
return V_2 ;
}
static struct V_1 * F_75 ( int V_125 )
{
struct V_1 * V_2 ;
if ( V_125 == - 1 )
return NULL ;
V_2 = F_67 ( V_125 ) ;
if ( ! F_73 ( V_2 ) )
return V_2 ;
V_2 = F_70 ( V_125 ) ;
if ( ! F_73 ( V_2 ) )
return V_2 ;
return F_69 ( - V_132 ) ;
}
static long F_76 ( struct V_16 * V_113 , unsigned V_124 , int V_125 )
{
struct V_1 * V_2 , * V_142 ;
struct V_24 * V_25 ;
struct V_46 * V_48 , * V_143 = NULL ;
int V_92 ;
F_15 ( & V_113 -> V_26 . V_53 ) ;
V_92 = F_77 ( & V_113 -> V_26 ) ;
if ( V_92 )
goto V_43;
if ( V_124 >= V_118 ) {
V_92 = - V_79 ;
goto V_43;
}
V_25 = V_113 -> V_27 + V_124 ;
F_15 ( & V_25 -> V_53 ) ;
if ( ! F_78 ( V_25 ) ) {
V_92 = - V_144 ;
goto V_145;
}
V_2 = F_75 ( V_125 ) ;
if ( F_73 ( V_2 ) ) {
V_92 = F_79 ( V_2 ) ;
goto V_145;
}
V_142 = F_56 ( V_25 -> V_50 ,
F_57 ( & V_25 -> V_53 ) ) ;
if ( V_2 != V_142 ) {
V_48 = F_80 ( V_25 , V_2 && F_1 ( V_2 ) ) ;
if ( F_73 ( V_48 ) ) {
V_92 = F_79 ( V_48 ) ;
goto V_146;
}
V_143 = V_25 -> V_48 ;
V_25 -> V_48 = V_48 ;
F_54 ( V_113 , V_25 ) ;
F_59 ( V_25 -> V_50 , V_2 ) ;
F_55 ( V_113 , V_25 ) ;
V_92 = F_81 ( V_25 ) ;
if ( V_92 )
goto V_145;
}
F_16 ( & V_25 -> V_53 ) ;
if ( V_143 ) {
F_82 ( V_143 ) ;
F_15 ( & V_25 -> V_53 ) ;
F_18 ( V_25 ) ;
F_16 ( & V_25 -> V_53 ) ;
}
if ( V_142 ) {
F_61 ( V_113 , V_124 ) ;
F_66 ( V_142 -> V_23 ) ;
}
F_16 ( & V_113 -> V_26 . V_53 ) ;
return 0 ;
V_146:
F_66 ( V_2 -> V_23 ) ;
V_145:
F_16 ( & V_25 -> V_53 ) ;
V_43:
F_16 ( & V_113 -> V_26 . V_53 ) ;
return V_92 ;
}
static long F_83 ( struct V_16 * V_113 )
{
struct V_1 * V_122 = NULL ;
struct V_1 * V_123 = NULL ;
long V_43 ;
F_15 ( & V_113 -> V_26 . V_53 ) ;
V_43 = F_77 ( & V_113 -> V_26 ) ;
if ( V_43 )
goto V_147;
F_60 ( V_113 , & V_122 , & V_123 ) ;
F_63 ( V_113 ) ;
V_43 = F_84 ( & V_113 -> V_26 ) ;
V_147:
F_16 ( & V_113 -> V_26 . V_53 ) ;
if ( V_122 )
F_66 ( V_122 -> V_23 ) ;
if ( V_123 )
F_66 ( V_123 -> V_23 ) ;
return V_43 ;
}
static int F_85 ( struct V_16 * V_113 , T_3 V_148 )
{
T_1 V_54 , V_101 , V_149 ;
int V_150 ;
V_149 = ( V_148 & ( 1 << V_105 ) ) ?
sizeof( struct V_97 ) :
sizeof( struct V_151 ) ;
if ( V_148 & ( 1 << V_152 ) ) {
V_54 = V_149 ;
V_101 = 0 ;
} else {
V_54 = 0 ;
V_101 = V_149 ;
}
F_15 ( & V_113 -> V_26 . V_53 ) ;
if ( ( V_148 & ( 1 << V_104 ) ) &&
! F_86 ( & V_113 -> V_26 ) ) {
F_16 ( & V_113 -> V_26 . V_53 ) ;
return - V_144 ;
}
V_113 -> V_26 . V_153 = V_148 ;
F_87 () ;
for ( V_150 = 0 ; V_150 < V_118 ; ++ V_150 ) {
F_15 ( & V_113 -> V_27 [ V_150 ] . V_53 ) ;
V_113 -> V_27 [ V_150 ] . V_54 = V_54 ;
V_113 -> V_27 [ V_150 ] . V_101 = V_101 ;
F_16 ( & V_113 -> V_27 [ V_150 ] . V_53 ) ;
}
F_63 ( V_113 ) ;
F_16 ( & V_113 -> V_26 . V_53 ) ;
return 0 ;
}
static long F_88 ( struct V_23 * V_112 , unsigned int V_154 ,
unsigned long V_155 )
{
struct V_16 * V_113 = V_112 -> V_50 ;
void T_4 * V_156 = ( void T_4 * ) V_155 ;
T_3 T_4 * V_157 = V_156 ;
struct V_158 V_159 ;
T_3 V_148 ;
int V_92 ;
switch ( V_154 ) {
case V_160 :
if ( F_89 ( & V_159 , V_156 , sizeof V_159 ) )
return - V_144 ;
return F_76 ( V_113 , V_159 . V_124 , V_159 . V_125 ) ;
case V_161 :
V_148 = V_162 ;
if ( F_90 ( V_157 , & V_148 , sizeof V_148 ) )
return - V_144 ;
return 0 ;
case V_163 :
if ( F_89 ( & V_148 , V_157 , sizeof V_148 ) )
return - V_144 ;
if ( V_148 & ~ V_162 )
return - V_164 ;
return F_85 ( V_113 , V_148 ) ;
case V_165 :
return F_83 ( V_113 ) ;
default:
F_15 ( & V_113 -> V_26 . V_53 ) ;
V_92 = F_91 ( & V_113 -> V_26 , V_154 , V_155 ) ;
F_63 ( V_113 ) ;
F_16 ( & V_113 -> V_26 . V_53 ) ;
return V_92 ;
}
}
static long F_92 ( struct V_23 * V_112 , unsigned int V_154 ,
unsigned long V_155 )
{
return F_88 ( V_112 , V_154 , ( unsigned long ) F_93 ( V_155 ) ) ;
}
static int F_94 ( void )
{
if ( V_3 )
F_95 ( V_21 ) ;
return F_96 ( & V_166 ) ;
}
static void F_97 ( void )
{
F_98 ( & V_166 ) ;
}
