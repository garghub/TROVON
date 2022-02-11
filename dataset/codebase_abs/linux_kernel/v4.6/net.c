static void F_1 ( int V_1 )
{
V_2 |= 0x1 << V_1 ;
}
static struct V_3 *
F_2 ( struct V_4 * V_1 , bool V_5 )
{
struct V_3 * V_6 ;
if ( ! V_5 )
return NULL ;
V_6 = F_3 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return F_4 ( - V_8 ) ;
F_5 ( & V_6 -> V_9 , 1 ) ;
F_6 ( & V_6 -> V_10 ) ;
V_6 -> V_1 = V_1 ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_6 )
{
int V_11 = F_8 ( 1 , & V_6 -> V_9 ) ;
if ( F_9 ( ! V_11 ) )
F_10 ( & V_6 -> V_10 ) ;
return V_11 ;
}
static void F_11 ( struct V_3 * V_6 )
{
F_7 ( V_6 ) ;
F_12 ( V_6 -> V_10 , ! F_13 ( & V_6 -> V_9 ) ) ;
}
static void F_14 ( struct V_3 * V_6 )
{
F_11 ( V_6 ) ;
F_15 ( V_6 ) ;
}
static void F_16 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_15 ( V_13 -> V_16 [ V_14 ] . V_17 ) ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
}
}
static int F_17 ( struct V_12 * V_13 )
{
bool V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
V_5 = V_2 & ( 0x1 << V_14 ) ;
if ( ! V_5 )
continue;
V_13 -> V_16 [ V_14 ] . V_17 = F_3 ( sizeof( * V_13 -> V_16 [ V_14 ] . V_17 ) *
V_18 , V_7 ) ;
if ( ! V_13 -> V_16 [ V_14 ] . V_17 )
goto V_19;
}
return 0 ;
V_19:
F_16 ( V_13 ) ;
return - V_8 ;
}
static void F_18 ( struct V_12 * V_13 )
{
int V_14 ;
F_16 ( V_13 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
}
static void F_19 ( struct V_12 * V_24 )
{
++ V_24 -> V_25 ;
if ( V_24 -> V_25 < 1024 )
return;
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
}
static void F_20 ( struct V_12 * V_24 )
{
++ V_24 -> V_26 ;
}
static bool F_21 ( struct V_12 * V_24 )
{
return ! V_24 -> V_27 &&
V_24 -> V_25 / 64 >= V_24 -> V_26 ;
}
static bool F_22 ( struct V_28 * V_29 )
{
return F_9 ( V_30 ) &&
F_23 ( V_29 -> V_31 , V_32 ) ;
}
static void F_24 ( struct V_12 * V_24 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
int V_14 , V_35 ;
int V_36 = 0 ;
for ( V_14 = V_34 -> V_20 ; V_14 != V_34 -> V_21 ; V_14 = ( V_14 + 1 ) % V_18 ) {
if ( V_1 -> V_37 [ V_14 ] . V_38 == V_39 )
F_20 ( V_24 ) ;
if ( F_26 ( V_1 -> V_37 [ V_14 ] . V_38 ) ) {
V_1 -> V_37 [ V_14 ] . V_38 = V_40 ;
++ V_36 ;
} else
break;
}
while ( V_36 ) {
V_35 = F_27 ( V_18 - V_34 -> V_20 , V_36 ) ;
F_28 ( V_1 -> V_41 , V_1 ,
& V_1 -> V_37 [ V_34 -> V_20 ] , V_35 ) ;
V_34 -> V_20 = ( V_34 -> V_20 + V_35 ) % V_18 ;
V_36 -= V_35 ;
}
}
static void F_29 ( struct V_17 * V_42 , bool V_43 )
{
struct V_3 * V_6 = V_42 -> V_44 ;
struct V_4 * V_1 = V_6 -> V_1 ;
int V_45 ;
F_30 () ;
V_1 -> V_37 [ V_42 -> V_46 ] . V_38 = V_43 ?
V_47 : V_39 ;
V_45 = F_7 ( V_6 ) ;
if ( V_45 <= 1 || ! ( V_45 % 16 ) )
F_31 ( & V_1 -> V_48 ) ;
F_32 () ;
}
static inline unsigned long F_33 ( void )
{
return F_34 () >> 10 ;
}
static bool F_35 ( struct V_49 * V_41 ,
unsigned long V_50 )
{
return F_36 ( ! F_37 () ) &&
F_36 ( ! F_38 ( F_33 () , V_50 ) ) &&
F_36 ( ! F_39 ( V_51 ) ) &&
! F_40 ( V_41 ) ;
}
static int F_41 ( struct V_12 * V_24 ,
struct V_4 * V_1 ,
struct V_52 V_53 [] , unsigned int V_54 ,
unsigned int * V_55 , unsigned int * V_56 )
{
unsigned long V_57 ( V_50 ) ;
int V_11 = F_42 ( V_1 , V_1 -> V_53 , F_43 ( V_1 -> V_53 ) ,
V_55 , V_56 , NULL , NULL ) ;
if ( V_11 == V_1 -> V_58 && V_1 -> V_59 ) {
F_44 () ;
V_50 = F_33 () + V_1 -> V_59 ;
while ( F_35 ( V_1 -> V_41 , V_50 ) &&
F_45 ( V_1 -> V_41 , V_1 ) )
F_46 () ;
F_47 () ;
V_11 = F_42 ( V_1 , V_1 -> V_53 , F_43 ( V_1 -> V_53 ) ,
V_55 , V_56 , NULL , NULL ) ;
}
return V_11 ;
}
static void F_48 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_60 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_61 , V_62 ;
int V_63 ;
struct V_64 V_65 = {
. V_66 = NULL ,
. V_67 = 0 ,
. V_68 = NULL ,
. V_69 = 0 ,
. V_70 = V_71 ,
} ;
T_1 V_38 , V_72 = 0 ;
int V_19 ;
T_1 V_73 ;
struct V_28 * V_29 ;
struct V_3 * V_57 ( V_6 ) ;
bool V_5 , V_74 ;
F_49 ( & V_1 -> V_75 ) ;
V_29 = V_1 -> V_76 ;
if ( ! V_29 )
goto V_61;
F_50 ( & V_24 -> V_41 , V_1 ) ;
V_73 = V_34 -> V_22 ;
V_5 = V_34 -> V_6 ;
for (; ; ) {
if ( V_5 )
F_24 ( V_24 , V_1 ) ;
if ( F_9 ( ( V_34 -> V_21 + V_1 -> V_58 - V_77 )
% V_18 == V_34 -> V_20 ) )
break;
V_63 = F_41 ( V_24 , V_1 , V_1 -> V_53 ,
F_43 ( V_1 -> V_53 ) ,
& V_61 , & V_62 ) ;
if ( F_9 ( V_63 < 0 ) )
break;
if ( V_63 == V_1 -> V_58 ) {
if ( F_9 ( F_51 ( & V_24 -> V_41 , V_1 ) ) ) {
F_50 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
if ( V_62 ) {
F_52 ( V_1 , L_1
L_2 , V_61 , V_62 ) ;
break;
}
V_38 = F_53 ( V_1 -> V_53 , V_61 ) ;
F_54 ( & V_65 . V_78 , V_79 , V_1 -> V_53 , V_61 , V_38 ) ;
F_55 ( & V_65 . V_78 , V_73 ) ;
if ( ! F_56 ( & V_65 ) ) {
F_52 ( V_1 , L_3
L_4 ,
V_38 , V_73 ) ;
break;
}
V_38 = F_56 ( & V_65 ) ;
V_74 = V_5 && V_38 >= V_80
&& ( V_34 -> V_21 + 1 ) % V_18 !=
V_34 -> V_20
&& F_21 ( V_24 ) ;
if ( V_74 ) {
struct V_17 * V_42 ;
V_42 = V_34 -> V_17 + V_34 -> V_21 ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_81 = F_57 ( V_1 , V_63 ) ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_38 = V_82 ;
V_42 -> V_83 = F_29 ;
V_42 -> V_44 = V_34 -> V_6 ;
V_42 -> V_46 = V_34 -> V_21 ;
V_65 . V_68 = V_42 ;
V_65 . V_69 = sizeof( V_42 ) ;
V_6 = V_34 -> V_6 ;
F_58 ( & V_6 -> V_9 ) ;
V_34 -> V_21 = ( V_34 -> V_21 + 1 ) % V_18 ;
} else {
V_65 . V_68 = NULL ;
V_6 = NULL ;
}
V_19 = V_29 -> V_84 -> V_85 ( V_29 , & V_65 , V_38 ) ;
if ( F_9 ( V_19 < 0 ) ) {
if ( V_74 ) {
F_7 ( V_6 ) ;
V_34 -> V_21 = ( ( unsigned ) V_34 -> V_21 - 1 )
% V_18 ;
}
F_59 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_38 )
F_60 ( L_5
L_6 , V_19 , V_38 ) ;
if ( ! V_74 )
F_61 ( & V_24 -> V_41 , V_1 , V_63 , 0 ) ;
else
F_24 ( V_24 , V_1 ) ;
V_72 += V_38 ;
F_19 ( V_24 ) ;
if ( F_9 ( V_72 >= V_86 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_61:
F_62 ( & V_1 -> V_75 ) ;
}
static int F_63 ( struct V_29 * V_31 )
{
struct V_87 * V_63 ;
int V_38 = 0 ;
unsigned long V_88 ;
F_64 ( & V_31 -> V_89 . V_90 , V_88 ) ;
V_63 = F_65 ( & V_31 -> V_89 ) ;
if ( F_36 ( V_63 ) ) {
V_38 = V_63 -> V_38 ;
if ( F_66 ( V_63 ) )
V_38 += V_91 ;
}
F_67 ( & V_31 -> V_89 . V_90 , V_88 ) ;
return V_38 ;
}
static int F_68 ( struct V_12 * V_24 , struct V_29 * V_31 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_60 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned long V_57 ( V_50 ) ;
int V_38 = F_63 ( V_31 ) ;
if ( ! V_38 && V_1 -> V_59 ) {
F_49 ( & V_1 -> V_75 ) ;
F_50 ( & V_24 -> V_41 , V_1 ) ;
F_44 () ;
V_50 = F_33 () + V_1 -> V_59 ;
while ( F_35 ( & V_24 -> V_41 , V_50 ) &&
F_69 ( & V_31 -> V_89 ) &&
F_45 ( & V_24 -> V_41 , V_1 ) )
F_46 () ;
F_47 () ;
if ( F_51 ( & V_24 -> V_41 , V_1 ) )
F_31 ( & V_1 -> V_48 ) ;
F_62 ( & V_1 -> V_75 ) ;
V_38 = F_63 ( V_31 ) ;
}
return V_38 ;
}
static int F_70 ( struct V_4 * V_1 ,
struct V_92 * V_37 ,
int V_93 ,
unsigned * V_94 ,
struct V_95 * log ,
unsigned * V_96 ,
unsigned int V_97 )
{
unsigned int V_61 , V_62 ;
int V_98 = 0 ;
int V_99 = 0 ;
unsigned V_100 ;
int V_11 , V_101 = 0 ;
T_2 V_57 ( V_38 ) ;
while ( V_93 > 0 && V_99 < V_97 ) {
if ( F_9 ( V_98 >= V_18 ) ) {
V_11 = - V_102 ;
goto V_19;
}
V_11 = F_42 ( V_1 , V_1 -> V_53 + V_98 ,
F_43 ( V_1 -> V_53 ) - V_98 , & V_61 ,
& V_62 , log , V_96 ) ;
if ( F_9 ( V_11 < 0 ) )
goto V_19;
V_100 = V_11 ;
if ( V_100 == V_1 -> V_58 ) {
V_11 = 0 ;
goto V_19;
}
if ( F_9 ( V_61 || V_62 <= 0 ) ) {
F_52 ( V_1 , L_7
L_8 , V_61 , V_62 ) ;
V_11 = - V_103 ;
goto V_19;
}
if ( F_9 ( log ) ) {
V_101 += * V_96 ;
log += * V_96 ;
}
V_37 [ V_99 ] . V_81 = F_57 ( V_1 , V_100 ) ;
V_38 = F_53 ( V_1 -> V_53 + V_98 , V_62 ) ;
V_37 [ V_99 ] . V_38 = F_57 ( V_1 , V_38 ) ;
V_93 -= V_38 ;
++ V_99 ;
V_98 += V_62 ;
}
V_37 [ V_99 - 1 ] . V_38 = F_57 ( V_1 , V_38 + V_93 ) ;
* V_94 = V_98 ;
if ( F_9 ( log ) )
* V_96 = V_101 ;
if ( F_9 ( V_93 > 0 ) ) {
V_11 = V_18 + 1 ;
goto V_19;
}
return V_99 ;
V_19:
F_59 ( V_1 , V_99 ) ;
return V_11 ;
}
static void F_71 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_104 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_57 ( V_62 ) , log ;
struct V_95 * V_105 ;
struct V_64 V_65 = {
. V_66 = NULL ,
. V_67 = 0 ,
. V_68 = NULL ,
. V_69 = 0 ,
. V_70 = V_71 ,
} ;
struct V_106 V_107 = {
. V_88 = 0 ,
. V_108 = V_109
} ;
T_1 V_72 = 0 ;
int V_19 , V_110 ;
T_3 V_99 ;
T_1 V_22 , V_23 ;
T_1 V_111 , V_112 ;
struct V_28 * V_29 ;
struct V_113 V_114 ;
T_4 V_115 ;
F_49 ( & V_1 -> V_75 ) ;
V_29 = V_1 -> V_76 ;
if ( ! V_29 )
goto V_61;
F_50 ( & V_24 -> V_41 , V_1 ) ;
V_22 = V_34 -> V_22 ;
V_23 = V_34 -> V_23 ;
V_105 = F_9 ( F_72 ( V_1 , V_116 ) ) ?
V_1 -> log : NULL ;
V_110 = F_72 ( V_1 , V_117 ) ;
while ( ( V_112 = F_68 ( V_24 , V_29 -> V_31 ) ) ) {
V_112 += V_23 ;
V_111 = V_112 + V_22 ;
V_99 = F_70 ( V_1 , V_1 -> V_37 , V_111 ,
& V_62 , V_105 , & log ,
F_36 ( V_110 ) ? V_18 : 1 ) ;
if ( F_9 ( V_99 < 0 ) )
break;
if ( F_9 ( V_99 > V_18 ) ) {
F_54 ( & V_65 . V_78 , V_118 , V_1 -> V_53 , 1 , 1 ) ;
V_19 = V_29 -> V_84 -> V_119 ( V_29 , & V_65 ,
1 , V_71 | V_120 ) ;
F_60 ( L_9 , V_112 ) ;
continue;
}
if ( ! V_99 ) {
if ( F_9 ( F_51 ( & V_24 -> V_41 , V_1 ) ) ) {
F_50 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
F_54 ( & V_65 . V_78 , V_118 , V_1 -> V_53 , V_62 , V_111 ) ;
V_114 = V_65 . V_78 ;
if ( F_9 ( ( V_22 ) ) ) {
F_55 ( & V_65 . V_78 , V_22 ) ;
}
V_19 = V_29 -> V_84 -> V_119 ( V_29 , & V_65 ,
V_112 , V_71 | V_120 ) ;
if ( F_9 ( V_19 != V_112 ) ) {
F_60 ( L_10
L_11 , V_19 , V_112 ) ;
F_59 ( V_1 , V_99 ) ;
continue;
}
if ( F_9 ( V_22 ) ) {
if ( F_73 ( & V_107 , sizeof( V_107 ) ,
& V_114 ) != sizeof( V_107 ) ) {
F_52 ( V_1 , L_12
L_13 , V_1 -> V_53 -> V_121 ) ;
break;
}
} else {
F_55 ( & V_114 , sizeof( V_107 ) ) ;
}
V_115 = F_74 ( V_1 , V_99 ) ;
if ( F_36 ( V_110 ) &&
F_73 ( & V_115 , sizeof V_115 ,
& V_114 ) != sizeof V_115 ) {
F_52 ( V_1 , L_14 ) ;
F_59 ( V_1 , V_99 ) ;
break;
}
F_28 ( & V_24 -> V_41 , V_1 , V_1 -> V_37 ,
V_99 ) ;
if ( F_9 ( V_105 ) )
F_75 ( V_1 , V_105 , log , V_111 ) ;
V_72 += V_111 ;
if ( F_9 ( V_72 >= V_86 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_61:
F_62 ( & V_1 -> V_75 ) ;
}
static void F_76 ( struct V_122 * V_123 )
{
struct V_4 * V_1 = F_25 ( V_123 , struct V_4 ,
V_48 . V_123 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_48 ( V_24 ) ;
}
static void F_77 ( struct V_122 * V_123 )
{
struct V_4 * V_1 = F_25 ( V_123 , struct V_4 ,
V_48 . V_123 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_71 ( V_24 ) ;
}
static void F_78 ( struct V_122 * V_123 )
{
struct V_12 * V_24 = F_25 ( V_123 , struct V_12 ,
V_48 [ V_60 ] . V_123 ) ;
F_48 ( V_24 ) ;
}
static void F_79 ( struct V_122 * V_123 )
{
struct V_12 * V_24 = F_25 ( V_123 , struct V_12 ,
V_48 [ V_104 ] . V_123 ) ;
F_71 ( V_24 ) ;
}
static int F_80 ( struct V_124 * V_124 , struct V_125 * V_126 )
{
struct V_12 * V_13 ;
struct V_49 * V_41 ;
struct V_4 * * V_16 ;
int V_14 ;
V_13 = F_3 ( sizeof *V_13 , V_7 | V_127 | V_128 ) ;
if ( ! V_13 ) {
V_13 = F_81 ( sizeof *V_13 ) ;
if ( ! V_13 )
return - V_8 ;
}
V_16 = F_3 ( V_15 * sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 ) {
F_82 ( V_13 ) ;
return - V_8 ;
}
V_41 = & V_13 -> V_41 ;
V_16 [ V_60 ] = & V_13 -> V_16 [ V_60 ] . V_1 ;
V_16 [ V_104 ] = & V_13 -> V_16 [ V_104 ] . V_1 ;
V_13 -> V_16 [ V_60 ] . V_1 . V_129 = F_76 ;
V_13 -> V_16 [ V_104 ] . V_1 . V_129 = F_77 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
F_83 ( V_41 , V_16 , V_15 ) ;
F_84 ( V_13 -> V_48 + V_60 , F_78 , V_130 , V_41 ) ;
F_84 ( V_13 -> V_48 + V_104 , F_79 , V_131 , V_41 ) ;
V_126 -> V_76 = V_13 ;
return 0 ;
}
static void F_85 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_132 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
if ( ! V_1 -> V_76 )
return;
F_86 ( V_48 ) ;
}
static int F_87 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_132 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
struct V_28 * V_29 ;
V_29 = V_1 -> V_76 ;
if ( ! V_29 )
return 0 ;
return F_88 ( V_48 , V_29 -> V_125 ) ;
}
static struct V_28 * F_89 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_28 * V_29 ;
F_49 ( & V_1 -> V_75 ) ;
V_29 = V_1 -> V_76 ;
F_85 ( V_13 , V_1 ) ;
V_1 -> V_76 = NULL ;
F_62 ( & V_1 -> V_75 ) ;
return V_29 ;
}
static void F_90 ( struct V_12 * V_13 , struct V_28 * * V_133 ,
struct V_28 * * V_134 )
{
* V_133 = F_89 ( V_13 , & V_13 -> V_16 [ V_60 ] . V_1 ) ;
* V_134 = F_89 ( V_13 , & V_13 -> V_16 [ V_104 ] . V_1 ) ;
}
static void F_91 ( struct V_12 * V_13 , int V_135 )
{
F_92 ( V_13 -> V_48 + V_135 ) ;
F_92 ( & V_13 -> V_16 [ V_135 ] . V_1 . V_48 ) ;
}
static void F_93 ( struct V_12 * V_13 )
{
F_91 ( V_13 , V_60 ) ;
F_91 ( V_13 , V_104 ) ;
if ( V_13 -> V_16 [ V_60 ] . V_6 ) {
F_49 ( & V_13 -> V_16 [ V_60 ] . V_1 . V_75 ) ;
V_13 -> V_27 = true ;
F_62 ( & V_13 -> V_16 [ V_60 ] . V_1 . V_75 ) ;
F_11 ( V_13 -> V_16 [ V_60 ] . V_6 ) ;
F_49 ( & V_13 -> V_16 [ V_60 ] . V_1 . V_75 ) ;
V_13 -> V_27 = false ;
F_5 ( & V_13 -> V_16 [ V_60 ] . V_6 -> V_9 , 1 ) ;
F_62 ( & V_13 -> V_16 [ V_60 ] . V_1 . V_75 ) ;
}
}
static int F_94 ( struct V_124 * V_124 , struct V_125 * V_126 )
{
struct V_12 * V_13 = V_126 -> V_76 ;
struct V_28 * V_133 ;
struct V_28 * V_134 ;
F_90 ( V_13 , & V_133 , & V_134 ) ;
F_93 ( V_13 ) ;
F_95 ( & V_13 -> V_41 ) ;
F_96 ( & V_13 -> V_41 , false ) ;
F_18 ( V_13 ) ;
if ( V_133 )
F_97 ( V_133 ) ;
if ( V_134 )
F_97 ( V_134 ) ;
F_98 () ;
F_93 ( V_13 ) ;
F_15 ( V_13 -> V_41 . V_16 ) ;
F_82 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_99 ( int V_136 )
{
struct {
struct V_137 V_138 ;
char V_139 [ V_140 ] ;
} V_141 ;
int V_142 = sizeof V_141 , V_11 ;
struct V_28 * V_29 = F_100 ( V_136 , & V_11 ) ;
if ( ! V_29 )
return F_4 ( - V_143 ) ;
if ( V_29 -> V_31 -> V_144 != V_145 ) {
V_11 = - V_146 ;
goto V_19;
}
V_11 = V_29 -> V_84 -> V_147 ( V_29 , (struct V_148 * ) & V_141 . V_138 ,
& V_142 , 0 ) ;
if ( V_11 )
goto V_19;
if ( V_141 . V_138 . V_149 != V_150 ) {
V_11 = - V_151 ;
goto V_19;
}
return V_29 ;
V_19:
F_97 ( V_29 ) ;
return F_4 ( V_11 ) ;
}
static struct V_28 * F_101 ( int V_136 )
{
struct V_125 * V_125 = F_102 ( V_136 ) ;
struct V_28 * V_29 ;
if ( ! V_125 )
return F_4 ( - V_152 ) ;
V_29 = F_103 ( V_125 ) ;
if ( ! F_104 ( V_29 ) )
return V_29 ;
V_29 = F_105 ( V_125 ) ;
if ( F_104 ( V_29 ) )
F_106 ( V_125 ) ;
return V_29 ;
}
static struct V_28 * F_107 ( int V_136 )
{
struct V_28 * V_29 ;
if ( V_136 == - 1 )
return NULL ;
V_29 = F_99 ( V_136 ) ;
if ( ! F_104 ( V_29 ) )
return V_29 ;
V_29 = F_101 ( V_136 ) ;
if ( ! F_104 ( V_29 ) )
return V_29 ;
return F_4 ( - V_143 ) ;
}
static long F_108 ( struct V_12 * V_13 , unsigned V_135 , int V_136 )
{
struct V_28 * V_29 , * V_153 ;
struct V_4 * V_1 ;
struct V_33 * V_34 ;
struct V_3 * V_6 , * V_154 = NULL ;
int V_11 ;
F_49 ( & V_13 -> V_41 . V_75 ) ;
V_11 = F_109 ( & V_13 -> V_41 ) ;
if ( V_11 )
goto V_19;
if ( V_135 >= V_15 ) {
V_11 = - V_102 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_135 ] . V_1 ;
V_34 = & V_13 -> V_16 [ V_135 ] ;
F_49 ( & V_1 -> V_75 ) ;
if ( ! F_110 ( V_1 ) ) {
V_11 = - V_155 ;
goto V_156;
}
V_29 = F_107 ( V_136 ) ;
if ( F_104 ( V_29 ) ) {
V_11 = F_111 ( V_29 ) ;
goto V_156;
}
V_153 = V_1 -> V_76 ;
if ( V_29 != V_153 ) {
V_6 = F_2 ( V_1 ,
V_29 && F_22 ( V_29 ) ) ;
if ( F_104 ( V_6 ) ) {
V_11 = F_111 ( V_6 ) ;
goto V_157;
}
F_85 ( V_13 , V_1 ) ;
V_1 -> V_76 = V_29 ;
V_11 = F_112 ( V_1 ) ;
if ( V_11 )
goto V_158;
V_11 = F_87 ( V_13 , V_1 ) ;
if ( V_11 )
goto V_158;
V_154 = V_34 -> V_6 ;
V_34 -> V_6 = V_6 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
V_13 -> V_27 = false ;
}
F_62 ( & V_1 -> V_75 ) ;
if ( V_154 ) {
F_14 ( V_154 ) ;
F_49 ( & V_1 -> V_75 ) ;
F_24 ( V_13 , V_1 ) ;
F_62 ( & V_1 -> V_75 ) ;
}
if ( V_153 ) {
F_91 ( V_13 , V_135 ) ;
F_97 ( V_153 ) ;
}
F_62 ( & V_13 -> V_41 . V_75 ) ;
return 0 ;
V_158:
V_1 -> V_76 = V_153 ;
F_87 ( V_13 , V_1 ) ;
if ( V_6 )
F_14 ( V_6 ) ;
V_157:
F_97 ( V_29 ) ;
V_156:
F_62 ( & V_1 -> V_75 ) ;
V_19:
F_62 ( & V_13 -> V_41 . V_75 ) ;
return V_11 ;
}
static long F_113 ( struct V_12 * V_13 )
{
struct V_28 * V_133 = NULL ;
struct V_28 * V_134 = NULL ;
long V_19 ;
struct V_159 * V_160 ;
F_49 ( & V_13 -> V_41 . V_75 ) ;
V_19 = F_109 ( & V_13 -> V_41 ) ;
if ( V_19 )
goto V_161;
V_160 = F_114 () ;
if ( ! V_160 ) {
V_19 = - V_8 ;
goto V_161;
}
F_90 ( V_13 , & V_133 , & V_134 ) ;
F_93 ( V_13 ) ;
F_115 ( & V_13 -> V_41 , V_160 ) ;
F_18 ( V_13 ) ;
V_161:
F_62 ( & V_13 -> V_41 . V_75 ) ;
if ( V_133 )
F_97 ( V_133 ) ;
if ( V_134 )
F_97 ( V_134 ) ;
return V_19 ;
}
static int F_116 ( struct V_12 * V_13 , T_5 V_162 )
{
T_1 V_22 , V_23 , V_163 ;
int V_14 ;
V_163 = ( V_162 & ( ( 1ULL << V_117 ) |
( 1ULL << V_164 ) ) ) ?
sizeof( struct V_165 ) :
sizeof( struct V_106 ) ;
if ( V_162 & ( 1 << V_166 ) ) {
V_22 = V_163 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_163 ;
}
F_49 ( & V_13 -> V_41 . V_75 ) ;
if ( ( V_162 & ( 1 << V_116 ) ) &&
! F_117 ( & V_13 -> V_41 ) ) {
F_62 ( & V_13 -> V_41 . V_75 ) ;
return - V_155 ;
}
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_49 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_75 ) ;
V_13 -> V_16 [ V_14 ] . V_1 . V_167 = V_162 ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_62 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_75 ) ;
}
F_62 ( & V_13 -> V_41 . V_75 ) ;
return 0 ;
}
static long F_118 ( struct V_12 * V_13 )
{
int V_11 ;
F_49 ( & V_13 -> V_41 . V_75 ) ;
if ( F_119 ( & V_13 -> V_41 ) ) {
V_11 = - V_168 ;
goto V_61;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 )
goto V_61;
V_11 = F_120 ( & V_13 -> V_41 ) ;
if ( V_11 )
F_16 ( V_13 ) ;
F_93 ( V_13 ) ;
V_61:
F_62 ( & V_13 -> V_41 . V_75 ) ;
return V_11 ;
}
static long F_121 ( struct V_125 * V_126 , unsigned int V_169 ,
unsigned long V_170 )
{
struct V_12 * V_13 = V_126 -> V_76 ;
void T_6 * V_171 = ( void T_6 * ) V_170 ;
T_5 T_6 * V_172 = V_171 ;
struct V_173 V_174 ;
T_5 V_162 ;
int V_11 ;
switch ( V_169 ) {
case V_175 :
if ( F_122 ( & V_174 , V_171 , sizeof V_174 ) )
return - V_155 ;
return F_108 ( V_13 , V_174 . V_135 , V_174 . V_136 ) ;
case V_176 :
V_162 = V_177 ;
if ( F_123 ( V_172 , & V_162 , sizeof V_162 ) )
return - V_155 ;
return 0 ;
case V_178 :
if ( F_122 ( & V_162 , V_172 , sizeof V_162 ) )
return - V_155 ;
if ( V_162 & ~ V_177 )
return - V_179 ;
return F_116 ( V_13 , V_162 ) ;
case V_180 :
return F_113 ( V_13 ) ;
case V_181 :
return F_118 ( V_13 ) ;
default:
F_49 ( & V_13 -> V_41 . V_75 ) ;
V_11 = F_124 ( & V_13 -> V_41 , V_169 , V_171 ) ;
if ( V_11 == - V_182 )
V_11 = F_125 ( & V_13 -> V_41 , V_169 , V_171 ) ;
else
F_93 ( V_13 ) ;
F_62 ( & V_13 -> V_41 . V_75 ) ;
return V_11 ;
}
}
static long F_126 ( struct V_125 * V_126 , unsigned int V_169 ,
unsigned long V_170 )
{
return F_121 ( V_126 , V_169 , ( unsigned long ) F_127 ( V_170 ) ) ;
}
static int F_128 ( void )
{
if ( V_30 )
F_1 ( V_60 ) ;
return F_129 ( & V_183 ) ;
}
static void F_130 ( void )
{
F_131 ( & V_183 ) ;
}
