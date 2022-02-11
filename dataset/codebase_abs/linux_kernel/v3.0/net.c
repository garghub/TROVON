static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_1 V_4 , int V_5 )
{
int V_6 = 0 ;
T_1 V_7 ;
while ( V_4 && V_6 < V_5 ) {
V_7 = F_2 ( V_2 -> V_8 , V_4 ) ;
V_3 -> V_9 = V_2 -> V_9 ;
V_3 -> V_8 = V_7 ;
V_2 -> V_8 -= V_7 ;
V_2 -> V_9 += V_7 ;
V_4 -= V_7 ;
++ V_2 ;
++ V_3 ;
++ V_6 ;
}
return V_6 ;
}
static void F_3 ( const struct V_1 * V_2 , struct V_1 * V_3 ,
T_1 V_4 , int V_10 )
{
int V_6 = 0 ;
T_1 V_7 ;
while ( V_4 && V_6 < V_10 ) {
V_7 = F_2 ( V_2 -> V_8 , V_4 ) ;
V_3 -> V_9 = V_2 -> V_9 ;
V_3 -> V_8 = V_7 ;
V_4 -= V_7 ;
++ V_2 ;
++ V_3 ;
++ V_6 ;
}
}
static void F_4 ( struct V_11 * V_12 )
{
if ( F_5 ( V_12 -> V_13 != V_14 ) )
return;
F_6 ( V_12 -> V_15 + V_16 ) ;
V_12 -> V_13 = V_17 ;
}
static void F_7 ( struct V_11 * V_12 , struct V_18 * V_19 )
{
if ( F_8 ( V_12 -> V_13 != V_17 ) )
return;
F_9 ( V_12 -> V_15 + V_16 , V_19 -> V_20 ) ;
V_12 -> V_13 = V_14 ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_21 * V_22 = & V_12 -> V_23 . V_24 [ V_16 ] ;
unsigned V_25 , V_26 , V_27 ;
int V_28 ;
struct V_29 V_30 = {
. V_31 = NULL ,
. V_32 = 0 ,
. V_33 = NULL ,
. V_34 = 0 ,
. V_35 = V_22 -> V_36 ,
. V_37 = V_38 ,
} ;
T_1 V_4 , V_39 = 0 ;
int V_40 , V_41 ;
T_1 V_42 ;
struct V_18 * V_19 ;
V_19 = F_11 ( V_22 -> V_43 , 1 ) ;
if ( ! V_19 )
return;
V_41 = F_12 ( & V_19 -> V_44 -> V_45 ) ;
if ( V_41 >= V_19 -> V_44 -> V_46 ) {
F_13 ( & V_22 -> V_47 ) ;
F_7 ( V_12 , V_19 ) ;
F_14 ( & V_22 -> V_47 ) ;
return;
}
F_13 ( & V_22 -> V_47 ) ;
F_15 ( & V_12 -> V_23 , V_22 ) ;
if ( V_41 < V_19 -> V_44 -> V_46 / 2 )
F_4 ( V_12 ) ;
V_42 = V_22 -> V_48 ;
for (; ; ) {
V_28 = F_16 ( & V_12 -> V_23 , V_22 , V_22 -> V_36 ,
F_17 ( V_22 -> V_36 ) ,
& V_25 , & V_26 ,
NULL , NULL ) ;
if ( F_8 ( V_28 < 0 ) )
break;
if ( V_28 == V_22 -> V_49 ) {
V_41 = F_12 ( & V_19 -> V_44 -> V_45 ) ;
if ( V_41 >= V_19 -> V_44 -> V_46 * 3 / 4 ) {
F_7 ( V_12 , V_19 ) ;
F_18 ( V_50 , & V_19 -> V_51 ) ;
break;
}
if ( F_8 ( F_19 ( & V_12 -> V_23 , V_22 ) ) ) {
F_15 ( & V_12 -> V_23 , V_22 ) ;
continue;
}
break;
}
if ( V_26 ) {
F_20 ( V_22 , L_1
L_2 , V_25 , V_26 ) ;
break;
}
V_27 = F_1 ( V_22 -> V_36 , V_22 -> V_52 , V_42 , V_25 ) ;
V_30 . V_53 = V_25 ;
V_4 = F_21 ( V_22 -> V_36 , V_25 ) ;
if ( ! V_4 ) {
F_20 ( V_22 , L_3
L_4 ,
F_21 ( V_22 -> V_52 , V_27 ) , V_42 ) ;
break;
}
V_40 = V_19 -> V_54 -> V_55 ( NULL , V_19 , & V_30 , V_4 ) ;
if ( F_8 ( V_40 < 0 ) ) {
F_22 ( V_22 , 1 ) ;
F_7 ( V_12 , V_19 ) ;
break;
}
if ( V_40 != V_4 )
F_23 ( L_5
L_6 , V_40 , V_4 ) ;
F_24 ( & V_12 -> V_23 , V_22 , V_28 , 0 ) ;
V_39 += V_4 ;
if ( F_8 ( V_39 >= V_56 ) ) {
F_25 ( & V_22 -> V_15 ) ;
break;
}
}
F_14 ( & V_22 -> V_47 ) ;
}
static int F_26 ( struct V_19 * V_44 )
{
struct V_57 * V_28 ;
int V_4 = 0 ;
unsigned long V_51 ;
F_27 ( & V_44 -> V_58 . V_59 , V_51 ) ;
V_28 = F_28 ( & V_44 -> V_58 ) ;
if ( F_5 ( V_28 ) )
V_4 = V_28 -> V_4 ;
F_29 ( & V_44 -> V_58 . V_59 , V_51 ) ;
return V_4 ;
}
static int F_30 ( struct V_21 * V_22 ,
struct V_60 * V_61 ,
int V_62 ,
unsigned * V_10 ,
struct V_63 * log ,
unsigned * V_64 ,
unsigned int V_65 )
{
unsigned int V_25 , V_26 ;
int V_6 = 0 ;
int V_66 = 0 ;
unsigned V_67 ;
int V_68 , V_69 = 0 ;
while ( V_62 > 0 && V_66 < V_65 ) {
if ( F_8 ( V_6 >= V_70 ) ) {
V_68 = - V_71 ;
goto V_40;
}
V_67 = F_16 ( V_22 -> V_23 , V_22 , V_22 -> V_36 + V_6 ,
F_17 ( V_22 -> V_36 ) - V_6 , & V_25 ,
& V_26 , log , V_64 ) ;
if ( V_67 == V_22 -> V_49 ) {
V_68 = 0 ;
goto V_40;
}
if ( F_8 ( V_25 || V_26 <= 0 ) ) {
F_20 ( V_22 , L_7
L_8 , V_25 , V_26 ) ;
V_68 = - V_72 ;
goto V_40;
}
if ( F_8 ( log ) ) {
V_69 += * V_64 ;
log += * V_64 ;
}
V_61 [ V_66 ] . V_73 = V_67 ;
V_61 [ V_66 ] . V_4 = F_21 ( V_22 -> V_36 + V_6 , V_26 ) ;
V_62 -= V_61 [ V_66 ] . V_4 ;
++ V_66 ;
V_6 += V_26 ;
}
V_61 [ V_66 - 1 ] . V_4 += V_62 ;
* V_10 = V_6 ;
if ( F_8 ( log ) )
* V_64 = V_69 ;
return V_66 ;
V_40:
F_22 ( V_22 , V_66 ) ;
return V_68 ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_21 * V_22 = & V_12 -> V_23 . V_24 [ V_74 ] ;
unsigned V_75 ( V_26 ) , log ;
struct V_63 * V_76 ;
struct V_29 V_30 = {
. V_31 = NULL ,
. V_32 = 0 ,
. V_33 = NULL ,
. V_34 = 0 ,
. V_35 = V_22 -> V_36 ,
. V_37 = V_38 ,
} ;
struct V_77 V_52 = {
. V_52 . V_51 = 0 ,
. V_52 . V_78 = V_79
} ;
T_1 V_39 = 0 ;
int V_40 , V_66 , V_80 ;
T_1 V_48 , V_81 ;
T_1 V_82 , V_83 ;
struct V_18 * V_19 = F_11 ( V_22 -> V_43 , 1 ) ;
if ( ! V_19 )
return;
F_13 ( & V_22 -> V_47 ) ;
F_15 ( & V_12 -> V_23 , V_22 ) ;
V_48 = V_22 -> V_48 ;
V_81 = V_22 -> V_81 ;
V_76 = F_8 ( F_32 ( & V_12 -> V_23 , V_84 ) ) ?
V_22 -> log : NULL ;
V_80 = F_32 ( & V_12 -> V_23 , V_85 ) ;
while ( ( V_83 = F_26 ( V_19 -> V_44 ) ) ) {
V_83 += V_81 ;
V_82 = V_83 + V_48 ;
V_66 = F_30 ( V_22 , V_22 -> V_61 , V_82 ,
& V_26 , V_76 , & log ,
F_5 ( V_80 ) ? V_70 : 1 ) ;
if ( F_8 ( V_66 < 0 ) )
break;
if ( ! V_66 ) {
if ( F_8 ( F_19 ( & V_12 -> V_23 , V_22 ) ) ) {
F_15 ( & V_12 -> V_23 , V_22 ) ;
continue;
}
break;
}
if ( F_8 ( ( V_48 ) ) )
F_1 ( V_22 -> V_36 , V_22 -> V_52 , V_48 , V_26 ) ;
else
F_3 ( V_22 -> V_36 , V_22 -> V_52 , V_81 , V_26 ) ;
V_30 . V_53 = V_26 ;
V_40 = V_19 -> V_54 -> V_86 ( NULL , V_19 , & V_30 ,
V_83 , V_38 | V_87 ) ;
if ( F_8 ( V_40 != V_83 ) ) {
F_23 ( L_9
L_10 , V_40 , V_83 ) ;
F_22 ( V_22 , V_66 ) ;
continue;
}
if ( F_8 ( V_48 ) &&
F_33 ( V_22 -> V_52 , ( unsigned char * ) & V_52 , 0 ,
V_48 ) ) {
F_20 ( V_22 , L_11 ,
V_22 -> V_36 -> V_9 ) ;
break;
}
if ( F_5 ( V_80 ) &&
F_33 ( V_22 -> V_52 , ( unsigned char * ) & V_66 ,
F_34 ( F_35 ( V_52 ) , V_88 ) ,
sizeof V_52 . V_88 ) ) {
F_20 ( V_22 , L_12 ) ;
F_22 ( V_22 , V_66 ) ;
break;
}
F_36 ( & V_12 -> V_23 , V_22 , V_22 -> V_61 ,
V_66 ) ;
if ( F_8 ( V_76 ) )
F_37 ( V_22 , V_76 , log , V_82 ) ;
V_39 += V_82 ;
if ( F_8 ( V_39 >= V_56 ) ) {
F_25 ( & V_22 -> V_15 ) ;
break;
}
}
F_14 ( & V_22 -> V_47 ) ;
}
static void F_38 ( struct V_89 * V_90 )
{
struct V_21 * V_22 = F_39 ( V_90 , struct V_21 ,
V_15 . V_90 ) ;
struct V_11 * V_12 = F_39 ( V_22 -> V_23 , struct V_11 , V_23 ) ;
F_10 ( V_12 ) ;
}
static void F_40 ( struct V_89 * V_90 )
{
struct V_21 * V_22 = F_39 ( V_90 , struct V_21 ,
V_15 . V_90 ) ;
struct V_11 * V_12 = F_39 ( V_22 -> V_23 , struct V_11 , V_23 ) ;
F_31 ( V_12 ) ;
}
static void F_41 ( struct V_89 * V_90 )
{
struct V_11 * V_12 = F_39 ( V_90 , struct V_11 ,
V_15 [ V_16 ] . V_90 ) ;
F_10 ( V_12 ) ;
}
static void F_42 ( struct V_89 * V_90 )
{
struct V_11 * V_12 = F_39 ( V_90 , struct V_11 ,
V_15 [ V_74 ] . V_90 ) ;
F_31 ( V_12 ) ;
}
static int F_43 ( struct V_91 * V_91 , struct V_20 * V_92 )
{
struct V_11 * V_93 = F_44 ( sizeof *V_93 , V_94 ) ;
struct V_95 * V_23 ;
int V_68 ;
if ( ! V_93 )
return - V_96 ;
V_23 = & V_93 -> V_23 ;
V_93 -> V_24 [ V_16 ] . V_97 = F_38 ;
V_93 -> V_24 [ V_74 ] . V_97 = F_40 ;
V_68 = F_45 ( V_23 , V_93 -> V_24 , V_98 ) ;
if ( V_68 < 0 ) {
F_46 ( V_93 ) ;
return V_68 ;
}
F_47 ( V_93 -> V_15 + V_16 , F_41 , V_99 , V_23 ) ;
F_47 ( V_93 -> V_15 + V_74 , F_42 , V_100 , V_23 ) ;
V_93 -> V_13 = V_101 ;
V_92 -> V_43 = V_93 ;
return 0 ;
}
static void F_48 ( struct V_11 * V_93 ,
struct V_21 * V_22 )
{
if ( ! V_22 -> V_43 )
return;
if ( V_22 == V_93 -> V_24 + V_16 ) {
F_4 ( V_93 ) ;
V_93 -> V_13 = V_101 ;
} else
F_6 ( V_93 -> V_15 + V_74 ) ;
}
static void F_49 ( struct V_11 * V_93 ,
struct V_21 * V_22 )
{
struct V_18 * V_19 ;
V_19 = F_50 ( V_22 -> V_43 ,
F_51 ( & V_22 -> V_47 ) ) ;
if ( ! V_19 )
return;
if ( V_22 == V_93 -> V_24 + V_16 ) {
V_93 -> V_13 = V_17 ;
F_7 ( V_93 , V_19 ) ;
} else
F_9 ( V_93 -> V_15 + V_74 , V_19 -> V_20 ) ;
}
static struct V_18 * F_52 ( struct V_11 * V_93 ,
struct V_21 * V_22 )
{
struct V_18 * V_19 ;
F_13 ( & V_22 -> V_47 ) ;
V_19 = F_50 ( V_22 -> V_43 ,
F_51 ( & V_22 -> V_47 ) ) ;
F_48 ( V_93 , V_22 ) ;
F_53 ( V_22 -> V_43 , NULL ) ;
F_14 ( & V_22 -> V_47 ) ;
return V_19 ;
}
static void F_54 ( struct V_11 * V_93 , struct V_18 * * V_102 ,
struct V_18 * * V_103 )
{
* V_102 = F_52 ( V_93 , V_93 -> V_24 + V_16 ) ;
* V_103 = F_52 ( V_93 , V_93 -> V_24 + V_74 ) ;
}
static void F_55 ( struct V_11 * V_93 , int V_104 )
{
F_56 ( V_93 -> V_15 + V_104 ) ;
F_56 ( & V_93 -> V_23 . V_24 [ V_104 ] . V_15 ) ;
}
static void F_57 ( struct V_11 * V_93 )
{
F_55 ( V_93 , V_16 ) ;
F_55 ( V_93 , V_74 ) ;
}
static int F_58 ( struct V_91 * V_91 , struct V_20 * V_92 )
{
struct V_11 * V_93 = V_92 -> V_43 ;
struct V_18 * V_102 ;
struct V_18 * V_103 ;
F_54 ( V_93 , & V_102 , & V_103 ) ;
F_57 ( V_93 ) ;
F_59 ( & V_93 -> V_23 ) ;
if ( V_102 )
F_60 ( V_102 -> V_20 ) ;
if ( V_103 )
F_60 ( V_103 -> V_20 ) ;
F_57 ( V_93 ) ;
F_46 ( V_93 ) ;
return 0 ;
}
static struct V_18 * F_61 ( int V_105 )
{
struct {
struct V_106 V_107 ;
char V_108 [ V_109 ] ;
} V_110 ;
int V_111 = sizeof V_110 , V_68 ;
struct V_18 * V_19 = F_62 ( V_105 , & V_68 ) ;
if ( ! V_19 )
return F_63 ( - V_112 ) ;
if ( V_19 -> V_44 -> V_113 != V_114 ) {
V_68 = - V_115 ;
goto V_40;
}
V_68 = V_19 -> V_54 -> V_116 ( V_19 , (struct V_117 * ) & V_110 . V_107 ,
& V_111 , 0 ) ;
if ( V_68 )
goto V_40;
if ( V_110 . V_107 . V_118 != V_119 ) {
V_68 = - V_120 ;
goto V_40;
}
return V_19 ;
V_40:
F_60 ( V_19 -> V_20 ) ;
return F_63 ( V_68 ) ;
}
static struct V_18 * F_64 ( int V_105 )
{
struct V_20 * V_20 = F_65 ( V_105 ) ;
struct V_18 * V_19 ;
if ( ! V_20 )
return F_63 ( - V_121 ) ;
V_19 = F_66 ( V_20 ) ;
if ( ! F_67 ( V_19 ) )
return V_19 ;
V_19 = F_68 ( V_20 ) ;
if ( F_67 ( V_19 ) )
F_60 ( V_20 ) ;
return V_19 ;
}
static struct V_18 * F_69 ( int V_105 )
{
struct V_18 * V_19 ;
if ( V_105 == - 1 )
return NULL ;
V_19 = F_61 ( V_105 ) ;
if ( ! F_67 ( V_19 ) )
return V_19 ;
V_19 = F_64 ( V_105 ) ;
if ( ! F_67 ( V_19 ) )
return V_19 ;
return F_63 ( - V_112 ) ;
}
static long F_70 ( struct V_11 * V_93 , unsigned V_104 , int V_105 )
{
struct V_18 * V_19 , * V_122 ;
struct V_21 * V_22 ;
int V_68 ;
F_13 ( & V_93 -> V_23 . V_47 ) ;
V_68 = F_71 ( & V_93 -> V_23 ) ;
if ( V_68 )
goto V_40;
if ( V_104 >= V_98 ) {
V_68 = - V_71 ;
goto V_40;
}
V_22 = V_93 -> V_24 + V_104 ;
F_13 ( & V_22 -> V_47 ) ;
if ( ! F_72 ( V_22 ) ) {
V_68 = - V_123 ;
goto V_124;
}
V_19 = F_69 ( V_105 ) ;
if ( F_67 ( V_19 ) ) {
V_68 = F_73 ( V_19 ) ;
goto V_124;
}
V_122 = F_50 ( V_22 -> V_43 ,
F_51 ( & V_22 -> V_47 ) ) ;
if ( V_19 != V_122 ) {
F_48 ( V_93 , V_22 ) ;
F_53 ( V_22 -> V_43 , V_19 ) ;
F_49 ( V_93 , V_22 ) ;
}
F_14 ( & V_22 -> V_47 ) ;
if ( V_122 ) {
F_55 ( V_93 , V_104 ) ;
F_60 ( V_122 -> V_20 ) ;
}
F_14 ( & V_93 -> V_23 . V_47 ) ;
return 0 ;
V_124:
F_14 ( & V_22 -> V_47 ) ;
V_40:
F_14 ( & V_93 -> V_23 . V_47 ) ;
return V_68 ;
}
static long F_74 ( struct V_11 * V_93 )
{
struct V_18 * V_102 = NULL ;
struct V_18 * V_103 = NULL ;
long V_40 ;
F_13 ( & V_93 -> V_23 . V_47 ) ;
V_40 = F_71 ( & V_93 -> V_23 ) ;
if ( V_40 )
goto V_125;
F_54 ( V_93 , & V_102 , & V_103 ) ;
F_57 ( V_93 ) ;
V_40 = F_75 ( & V_93 -> V_23 ) ;
V_125:
F_14 ( & V_93 -> V_23 . V_47 ) ;
if ( V_102 )
F_60 ( V_102 -> V_20 ) ;
if ( V_103 )
F_60 ( V_103 -> V_20 ) ;
return V_40 ;
}
static int F_76 ( struct V_11 * V_93 , T_2 V_126 )
{
T_1 V_48 , V_81 , V_127 ;
int V_128 ;
V_127 = ( V_126 & ( 1 << V_85 ) ) ?
sizeof( struct V_77 ) :
sizeof( struct V_129 ) ;
if ( V_126 & ( 1 << V_130 ) ) {
V_48 = V_127 ;
V_81 = 0 ;
} else {
V_48 = 0 ;
V_81 = V_127 ;
}
F_13 ( & V_93 -> V_23 . V_47 ) ;
if ( ( V_126 & ( 1 << V_84 ) ) &&
! F_77 ( & V_93 -> V_23 ) ) {
F_14 ( & V_93 -> V_23 . V_47 ) ;
return - V_123 ;
}
V_93 -> V_23 . V_131 = V_126 ;
F_78 () ;
for ( V_128 = 0 ; V_128 < V_98 ; ++ V_128 ) {
F_13 ( & V_93 -> V_24 [ V_128 ] . V_47 ) ;
V_93 -> V_24 [ V_128 ] . V_48 = V_48 ;
V_93 -> V_24 [ V_128 ] . V_81 = V_81 ;
F_14 ( & V_93 -> V_24 [ V_128 ] . V_47 ) ;
}
F_57 ( V_93 ) ;
F_14 ( & V_93 -> V_23 . V_47 ) ;
return 0 ;
}
static long F_79 ( struct V_20 * V_92 , unsigned int V_132 ,
unsigned long V_133 )
{
struct V_11 * V_93 = V_92 -> V_43 ;
void T_3 * V_134 = ( void T_3 * ) V_133 ;
T_2 T_3 * V_135 = V_134 ;
struct V_136 V_137 ;
T_2 V_126 ;
int V_68 ;
switch ( V_132 ) {
case V_138 :
if ( F_80 ( & V_137 , V_134 , sizeof V_137 ) )
return - V_123 ;
return F_70 ( V_93 , V_137 . V_104 , V_137 . V_105 ) ;
case V_139 :
V_126 = V_140 ;
if ( F_81 ( V_135 , & V_126 , sizeof V_126 ) )
return - V_123 ;
return 0 ;
case V_141 :
if ( F_80 ( & V_126 , V_135 , sizeof V_126 ) )
return - V_123 ;
if ( V_126 & ~ V_140 )
return - V_142 ;
return F_76 ( V_93 , V_126 ) ;
case V_143 :
return F_74 ( V_93 ) ;
default:
F_13 ( & V_93 -> V_23 . V_47 ) ;
V_68 = F_82 ( & V_93 -> V_23 , V_132 , V_133 ) ;
F_57 ( V_93 ) ;
F_14 ( & V_93 -> V_23 . V_47 ) ;
return V_68 ;
}
}
static long F_83 ( struct V_20 * V_92 , unsigned int V_132 ,
unsigned long V_133 )
{
return F_79 ( V_92 , V_132 , ( unsigned long ) F_84 ( V_133 ) ) ;
}
static int F_85 ( void )
{
return F_86 ( & V_144 ) ;
}
static void F_87 ( void )
{
F_88 ( & V_144 ) ;
}
