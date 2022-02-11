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
static void F_41 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_52 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
if ( ! V_1 -> V_53 )
return;
F_42 ( V_48 ) ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_52 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
struct V_28 * V_29 ;
V_29 = V_1 -> V_53 ;
if ( ! V_29 )
return 0 ;
return F_44 ( V_48 , V_29 -> V_54 ) ;
}
static int F_45 ( struct V_12 * V_24 ,
struct V_4 * V_1 ,
struct V_55 V_56 [] , unsigned int V_57 ,
unsigned int * V_58 , unsigned int * V_59 )
{
unsigned long V_60 ( V_50 ) ;
int V_11 = F_46 ( V_1 , V_1 -> V_56 , F_47 ( V_1 -> V_56 ) ,
V_58 , V_59 , NULL , NULL ) ;
if ( V_11 == V_1 -> V_61 && V_1 -> V_62 ) {
F_48 () ;
V_50 = F_33 () + V_1 -> V_62 ;
while ( F_35 ( V_1 -> V_41 , V_50 ) &&
F_49 ( V_1 -> V_41 , V_1 ) )
F_50 () ;
F_51 () ;
V_11 = F_46 ( V_1 , V_1 -> V_56 , F_47 ( V_1 -> V_56 ) ,
V_58 , V_59 , NULL , NULL ) ;
}
return V_11 ;
}
static void F_52 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_63 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_64 , V_65 ;
int V_66 ;
struct V_67 V_68 = {
. V_69 = NULL ,
. V_70 = 0 ,
. V_71 = NULL ,
. V_72 = 0 ,
. V_73 = V_74 ,
} ;
T_1 V_38 , V_75 = 0 ;
int V_19 ;
T_1 V_76 ;
struct V_28 * V_29 ;
struct V_3 * V_60 ( V_6 ) ;
bool V_5 , V_77 ;
F_53 ( & V_1 -> V_78 ) ;
V_29 = V_1 -> V_53 ;
if ( ! V_29 )
goto V_64;
if ( ! F_54 ( V_1 ) )
goto V_64;
F_55 ( & V_24 -> V_41 , V_1 ) ;
V_76 = V_34 -> V_22 ;
V_5 = V_34 -> V_6 ;
for (; ; ) {
if ( V_5 )
F_24 ( V_24 , V_1 ) ;
if ( F_9 ( ( V_34 -> V_21 + V_1 -> V_61 - V_79 )
% V_18 == V_34 -> V_20 ) )
break;
V_66 = F_45 ( V_24 , V_1 , V_1 -> V_56 ,
F_47 ( V_1 -> V_56 ) ,
& V_64 , & V_65 ) ;
if ( F_9 ( V_66 < 0 ) )
break;
if ( V_66 == V_1 -> V_61 ) {
if ( F_9 ( F_56 ( & V_24 -> V_41 , V_1 ) ) ) {
F_55 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
if ( V_65 ) {
F_57 ( V_1 , L_1
L_2 , V_64 , V_65 ) ;
break;
}
V_38 = F_58 ( V_1 -> V_56 , V_64 ) ;
F_59 ( & V_68 . V_80 , V_81 , V_1 -> V_56 , V_64 , V_38 ) ;
F_60 ( & V_68 . V_80 , V_76 ) ;
if ( ! F_61 ( & V_68 ) ) {
F_57 ( V_1 , L_3
L_4 ,
V_38 , V_76 ) ;
break;
}
V_38 = F_61 ( & V_68 ) ;
V_77 = V_5 && V_38 >= V_82
&& ( V_34 -> V_21 + 1 ) % V_18 !=
V_34 -> V_20
&& F_21 ( V_24 ) ;
if ( V_77 ) {
struct V_17 * V_42 ;
V_42 = V_34 -> V_17 + V_34 -> V_21 ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_83 = F_62 ( V_1 , V_66 ) ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_38 = V_84 ;
V_42 -> V_85 = F_29 ;
V_42 -> V_44 = V_34 -> V_6 ;
V_42 -> V_46 = V_34 -> V_21 ;
V_68 . V_71 = V_42 ;
V_68 . V_72 = sizeof( V_42 ) ;
V_6 = V_34 -> V_6 ;
F_63 ( & V_6 -> V_9 ) ;
V_34 -> V_21 = ( V_34 -> V_21 + 1 ) % V_18 ;
} else {
V_68 . V_71 = NULL ;
V_6 = NULL ;
}
V_19 = V_29 -> V_86 -> V_87 ( V_29 , & V_68 , V_38 ) ;
if ( F_9 ( V_19 < 0 ) ) {
if ( V_77 ) {
F_7 ( V_6 ) ;
V_34 -> V_21 = ( ( unsigned ) V_34 -> V_21 - 1 )
% V_18 ;
}
F_64 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_38 )
F_65 ( L_5
L_6 , V_19 , V_38 ) ;
if ( ! V_77 )
F_66 ( & V_24 -> V_41 , V_1 , V_66 , 0 ) ;
else
F_24 ( V_24 , V_1 ) ;
V_75 += V_38 ;
F_19 ( V_24 ) ;
if ( F_9 ( V_75 >= V_88 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_64:
F_67 ( & V_1 -> V_78 ) ;
}
static int F_68 ( struct V_29 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_89 ;
struct V_90 * V_66 ;
int V_38 = 0 ;
unsigned long V_91 ;
if ( V_29 -> V_86 -> V_92 )
return V_29 -> V_86 -> V_92 ( V_29 ) ;
F_69 ( & V_31 -> V_93 . V_94 , V_91 ) ;
V_66 = F_70 ( & V_31 -> V_93 ) ;
if ( F_36 ( V_66 ) ) {
V_38 = V_66 -> V_38 ;
if ( F_71 ( V_66 ) )
V_38 += V_95 ;
}
F_72 ( & V_31 -> V_93 . V_94 , V_91 ) ;
return V_38 ;
}
static int F_73 ( struct V_29 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_89 ;
if ( V_29 -> V_86 -> V_92 )
return V_29 -> V_86 -> V_92 ( V_29 ) ;
return F_74 ( & V_31 -> V_93 ) ;
}
static int F_75 ( struct V_12 * V_24 , struct V_29 * V_31 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_63 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned long V_60 ( V_50 ) ;
int V_38 = F_68 ( V_31 ) ;
if ( ! V_38 && V_1 -> V_62 ) {
F_53 ( & V_1 -> V_78 ) ;
F_55 ( & V_24 -> V_41 , V_1 ) ;
F_48 () ;
V_50 = F_33 () + V_1 -> V_62 ;
while ( F_35 ( & V_24 -> V_41 , V_50 ) &&
! F_73 ( V_31 ) &&
F_49 ( & V_24 -> V_41 , V_1 ) )
F_50 () ;
F_51 () ;
if ( F_56 ( & V_24 -> V_41 , V_1 ) )
F_31 ( & V_1 -> V_48 ) ;
F_67 ( & V_1 -> V_78 ) ;
V_38 = F_68 ( V_31 ) ;
}
return V_38 ;
}
static int F_76 ( struct V_4 * V_1 ,
struct V_96 * V_37 ,
int V_97 ,
unsigned * V_98 ,
struct V_99 * log ,
unsigned * V_100 ,
unsigned int V_101 )
{
unsigned int V_64 , V_65 ;
int V_102 = 0 ;
int V_103 = 0 ;
unsigned V_104 ;
int V_11 , V_105 = 0 ;
T_2 V_60 ( V_38 ) ;
while ( V_97 > 0 && V_103 < V_101 ) {
if ( F_9 ( V_102 >= V_18 ) ) {
V_11 = - V_106 ;
goto V_19;
}
V_11 = F_46 ( V_1 , V_1 -> V_56 + V_102 ,
F_47 ( V_1 -> V_56 ) - V_102 , & V_64 ,
& V_65 , log , V_100 ) ;
if ( F_9 ( V_11 < 0 ) )
goto V_19;
V_104 = V_11 ;
if ( V_104 == V_1 -> V_61 ) {
V_11 = 0 ;
goto V_19;
}
if ( F_9 ( V_64 || V_65 <= 0 ) ) {
F_57 ( V_1 , L_7
L_8 , V_64 , V_65 ) ;
V_11 = - V_107 ;
goto V_19;
}
if ( F_9 ( log ) ) {
V_105 += * V_100 ;
log += * V_100 ;
}
V_37 [ V_103 ] . V_83 = F_62 ( V_1 , V_104 ) ;
V_38 = F_58 ( V_1 -> V_56 + V_102 , V_65 ) ;
V_37 [ V_103 ] . V_38 = F_62 ( V_1 , V_38 ) ;
V_97 -= V_38 ;
++ V_103 ;
V_102 += V_65 ;
}
V_37 [ V_103 - 1 ] . V_38 = F_62 ( V_1 , V_38 + V_97 ) ;
* V_98 = V_102 ;
if ( F_9 ( log ) )
* V_100 = V_105 ;
if ( F_9 ( V_97 > 0 ) ) {
V_11 = V_18 + 1 ;
goto V_19;
}
return V_103 ;
V_19:
F_64 ( V_1 , V_103 ) ;
return V_11 ;
}
static void F_77 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_108 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_60 ( V_65 ) , log ;
struct V_99 * V_109 ;
struct V_67 V_68 = {
. V_69 = NULL ,
. V_70 = 0 ,
. V_71 = NULL ,
. V_72 = 0 ,
. V_73 = V_74 ,
} ;
struct V_110 V_111 = {
. V_91 = 0 ,
. V_112 = V_113
} ;
T_1 V_75 = 0 ;
int V_19 , V_114 ;
T_3 V_103 ;
T_1 V_22 , V_23 ;
T_1 V_115 , V_116 ;
struct V_28 * V_29 ;
struct V_117 V_118 ;
T_4 V_119 ;
F_53 ( & V_1 -> V_78 ) ;
V_29 = V_1 -> V_53 ;
if ( ! V_29 )
goto V_64;
if ( ! F_54 ( V_1 ) )
goto V_64;
F_55 ( & V_24 -> V_41 , V_1 ) ;
F_41 ( V_24 , V_1 ) ;
V_22 = V_34 -> V_22 ;
V_23 = V_34 -> V_23 ;
V_109 = F_9 ( F_78 ( V_1 , V_120 ) ) ?
V_1 -> log : NULL ;
V_114 = F_78 ( V_1 , V_121 ) ;
while ( ( V_116 = F_75 ( V_24 , V_29 -> V_31 ) ) ) {
V_116 += V_23 ;
V_115 = V_116 + V_22 ;
V_103 = F_76 ( V_1 , V_1 -> V_37 , V_115 ,
& V_65 , V_109 , & log ,
F_36 ( V_114 ) ? V_18 : 1 ) ;
if ( F_9 ( V_103 < 0 ) )
goto V_64;
if ( F_9 ( V_103 > V_18 ) ) {
F_59 ( & V_68 . V_80 , V_122 , V_1 -> V_56 , 1 , 1 ) ;
V_19 = V_29 -> V_86 -> V_123 ( V_29 , & V_68 ,
1 , V_74 | V_124 ) ;
F_65 ( L_9 , V_116 ) ;
continue;
}
if ( ! V_103 ) {
if ( F_9 ( F_56 ( & V_24 -> V_41 , V_1 ) ) ) {
F_55 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
goto V_64;
}
F_59 ( & V_68 . V_80 , V_122 , V_1 -> V_56 , V_65 , V_115 ) ;
V_118 = V_68 . V_80 ;
if ( F_9 ( ( V_22 ) ) ) {
F_60 ( & V_68 . V_80 , V_22 ) ;
}
V_19 = V_29 -> V_86 -> V_123 ( V_29 , & V_68 ,
V_116 , V_74 | V_124 ) ;
if ( F_9 ( V_19 != V_116 ) ) {
F_65 ( L_10
L_11 , V_19 , V_116 ) ;
F_64 ( V_1 , V_103 ) ;
continue;
}
if ( F_9 ( V_22 ) ) {
if ( F_79 ( & V_111 , sizeof( V_111 ) ,
& V_118 ) != sizeof( V_111 ) ) {
F_57 ( V_1 , L_12
L_13 , V_1 -> V_56 -> V_125 ) ;
goto V_64;
}
} else {
F_60 ( & V_118 , sizeof( V_111 ) ) ;
}
V_119 = F_80 ( V_1 , V_103 ) ;
if ( F_36 ( V_114 ) &&
F_79 ( & V_119 , sizeof V_119 ,
& V_118 ) != sizeof V_119 ) {
F_57 ( V_1 , L_14 ) ;
F_64 ( V_1 , V_103 ) ;
goto V_64;
}
F_28 ( & V_24 -> V_41 , V_1 , V_1 -> V_37 ,
V_103 ) ;
if ( F_9 ( V_109 ) )
F_81 ( V_1 , V_109 , log , V_115 ) ;
V_75 += V_115 ;
if ( F_9 ( V_75 >= V_88 ) ) {
F_31 ( & V_1 -> V_48 ) ;
goto V_64;
}
}
F_43 ( V_24 , V_1 ) ;
V_64:
F_67 ( & V_1 -> V_78 ) ;
}
static void F_82 ( struct V_126 * V_127 )
{
struct V_4 * V_1 = F_25 ( V_127 , struct V_4 ,
V_48 . V_127 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_52 ( V_24 ) ;
}
static void F_83 ( struct V_126 * V_127 )
{
struct V_4 * V_1 = F_25 ( V_127 , struct V_4 ,
V_48 . V_127 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_77 ( V_24 ) ;
}
static void F_84 ( struct V_126 * V_127 )
{
struct V_12 * V_24 = F_25 ( V_127 , struct V_12 ,
V_48 [ V_63 ] . V_127 ) ;
F_52 ( V_24 ) ;
}
static void F_85 ( struct V_126 * V_127 )
{
struct V_12 * V_24 = F_25 ( V_127 , struct V_12 ,
V_48 [ V_108 ] . V_127 ) ;
F_77 ( V_24 ) ;
}
static int F_86 ( struct V_128 * V_128 , struct V_54 * V_129 )
{
struct V_12 * V_13 ;
struct V_49 * V_41 ;
struct V_4 * * V_16 ;
int V_14 ;
V_13 = F_3 ( sizeof *V_13 , V_7 | V_130 | V_131 ) ;
if ( ! V_13 ) {
V_13 = F_87 ( sizeof *V_13 ) ;
if ( ! V_13 )
return - V_8 ;
}
V_16 = F_3 ( V_15 * sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 ) {
F_88 ( V_13 ) ;
return - V_8 ;
}
V_41 = & V_13 -> V_41 ;
V_16 [ V_63 ] = & V_13 -> V_16 [ V_63 ] . V_1 ;
V_16 [ V_108 ] = & V_13 -> V_16 [ V_108 ] . V_1 ;
V_13 -> V_16 [ V_63 ] . V_1 . V_132 = F_82 ;
V_13 -> V_16 [ V_108 ] . V_1 . V_132 = F_83 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
F_89 ( V_41 , V_16 , V_15 ) ;
F_90 ( V_13 -> V_48 + V_63 , F_84 , V_133 , V_41 ) ;
F_90 ( V_13 -> V_48 + V_108 , F_85 , V_134 , V_41 ) ;
V_129 -> V_53 = V_13 ;
return 0 ;
}
static struct V_28 * F_91 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_28 * V_29 ;
F_53 ( & V_1 -> V_78 ) ;
V_29 = V_1 -> V_53 ;
F_41 ( V_13 , V_1 ) ;
V_1 -> V_53 = NULL ;
F_67 ( & V_1 -> V_78 ) ;
return V_29 ;
}
static void F_92 ( struct V_12 * V_13 , struct V_28 * * V_135 ,
struct V_28 * * V_136 )
{
* V_135 = F_91 ( V_13 , & V_13 -> V_16 [ V_63 ] . V_1 ) ;
* V_136 = F_91 ( V_13 , & V_13 -> V_16 [ V_108 ] . V_1 ) ;
}
static void F_93 ( struct V_12 * V_13 , int V_137 )
{
F_94 ( V_13 -> V_48 + V_137 ) ;
F_94 ( & V_13 -> V_16 [ V_137 ] . V_1 . V_48 ) ;
}
static void F_95 ( struct V_12 * V_13 )
{
F_93 ( V_13 , V_63 ) ;
F_93 ( V_13 , V_108 ) ;
if ( V_13 -> V_16 [ V_63 ] . V_6 ) {
F_53 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_78 ) ;
V_13 -> V_27 = true ;
F_67 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_78 ) ;
F_11 ( V_13 -> V_16 [ V_63 ] . V_6 ) ;
F_53 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_78 ) ;
V_13 -> V_27 = false ;
F_5 ( & V_13 -> V_16 [ V_63 ] . V_6 -> V_9 , 1 ) ;
F_67 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_78 ) ;
}
}
static int F_96 ( struct V_128 * V_128 , struct V_54 * V_129 )
{
struct V_12 * V_13 = V_129 -> V_53 ;
struct V_28 * V_135 ;
struct V_28 * V_136 ;
F_92 ( V_13 , & V_135 , & V_136 ) ;
F_95 ( V_13 ) ;
F_97 ( & V_13 -> V_41 ) ;
F_98 ( & V_13 -> V_41 , false ) ;
F_18 ( V_13 ) ;
if ( V_135 )
F_99 ( V_135 ) ;
if ( V_136 )
F_99 ( V_136 ) ;
F_100 () ;
F_95 ( V_13 ) ;
F_15 ( V_13 -> V_41 . V_16 ) ;
F_88 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_101 ( int V_138 )
{
struct {
struct V_139 V_140 ;
char V_141 [ V_142 ] ;
} V_143 ;
int V_144 = sizeof V_143 , V_11 ;
struct V_28 * V_29 = F_102 ( V_138 , & V_11 ) ;
if ( ! V_29 )
return F_4 ( - V_145 ) ;
if ( V_29 -> V_31 -> V_146 != V_147 ) {
V_11 = - V_148 ;
goto V_19;
}
V_11 = V_29 -> V_86 -> V_149 ( V_29 , (struct V_150 * ) & V_143 . V_140 ,
& V_144 , 0 ) ;
if ( V_11 )
goto V_19;
if ( V_143 . V_140 . V_151 != V_152 ) {
V_11 = - V_153 ;
goto V_19;
}
return V_29 ;
V_19:
F_99 ( V_29 ) ;
return F_4 ( V_11 ) ;
}
static struct V_28 * F_103 ( int V_138 )
{
struct V_54 * V_54 = F_104 ( V_138 ) ;
struct V_28 * V_29 ;
if ( ! V_54 )
return F_4 ( - V_154 ) ;
V_29 = F_105 ( V_54 ) ;
if ( ! F_106 ( V_29 ) )
return V_29 ;
V_29 = F_107 ( V_54 ) ;
if ( F_106 ( V_29 ) )
F_108 ( V_54 ) ;
return V_29 ;
}
static struct V_28 * F_109 ( int V_138 )
{
struct V_28 * V_29 ;
if ( V_138 == - 1 )
return NULL ;
V_29 = F_101 ( V_138 ) ;
if ( ! F_106 ( V_29 ) )
return V_29 ;
V_29 = F_103 ( V_138 ) ;
if ( ! F_106 ( V_29 ) )
return V_29 ;
return F_4 ( - V_145 ) ;
}
static long F_110 ( struct V_12 * V_13 , unsigned V_137 , int V_138 )
{
struct V_28 * V_29 , * V_155 ;
struct V_4 * V_1 ;
struct V_33 * V_34 ;
struct V_3 * V_6 , * V_156 = NULL ;
int V_11 ;
F_53 ( & V_13 -> V_41 . V_78 ) ;
V_11 = F_111 ( & V_13 -> V_41 ) ;
if ( V_11 )
goto V_19;
if ( V_137 >= V_15 ) {
V_11 = - V_106 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_137 ] . V_1 ;
V_34 = & V_13 -> V_16 [ V_137 ] ;
F_53 ( & V_1 -> V_78 ) ;
if ( ! F_112 ( V_1 ) ) {
V_11 = - V_157 ;
goto V_158;
}
V_29 = F_109 ( V_138 ) ;
if ( F_106 ( V_29 ) ) {
V_11 = F_113 ( V_29 ) ;
goto V_158;
}
V_155 = V_1 -> V_53 ;
if ( V_29 != V_155 ) {
V_6 = F_2 ( V_1 ,
V_29 && F_22 ( V_29 ) ) ;
if ( F_106 ( V_6 ) ) {
V_11 = F_113 ( V_6 ) ;
goto V_159;
}
F_41 ( V_13 , V_1 ) ;
V_1 -> V_53 = V_29 ;
V_11 = F_114 ( V_1 ) ;
if ( V_11 )
goto V_160;
V_11 = F_43 ( V_13 , V_1 ) ;
if ( V_11 )
goto V_160;
V_156 = V_34 -> V_6 ;
V_34 -> V_6 = V_6 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
V_13 -> V_27 = false ;
}
F_67 ( & V_1 -> V_78 ) ;
if ( V_156 ) {
F_14 ( V_156 ) ;
F_53 ( & V_1 -> V_78 ) ;
F_24 ( V_13 , V_1 ) ;
F_67 ( & V_1 -> V_78 ) ;
}
if ( V_155 ) {
F_93 ( V_13 , V_137 ) ;
F_99 ( V_155 ) ;
}
F_67 ( & V_13 -> V_41 . V_78 ) ;
return 0 ;
V_160:
V_1 -> V_53 = V_155 ;
F_43 ( V_13 , V_1 ) ;
if ( V_6 )
F_14 ( V_6 ) ;
V_159:
F_99 ( V_29 ) ;
V_158:
F_67 ( & V_1 -> V_78 ) ;
V_19:
F_67 ( & V_13 -> V_41 . V_78 ) ;
return V_11 ;
}
static long F_115 ( struct V_12 * V_13 )
{
struct V_28 * V_135 = NULL ;
struct V_28 * V_136 = NULL ;
long V_19 ;
struct V_161 * V_162 ;
F_53 ( & V_13 -> V_41 . V_78 ) ;
V_19 = F_111 ( & V_13 -> V_41 ) ;
if ( V_19 )
goto V_163;
V_162 = F_116 () ;
if ( ! V_162 ) {
V_19 = - V_8 ;
goto V_163;
}
F_92 ( V_13 , & V_135 , & V_136 ) ;
F_95 ( V_13 ) ;
F_117 ( & V_13 -> V_41 , V_162 ) ;
F_18 ( V_13 ) ;
V_163:
F_67 ( & V_13 -> V_41 . V_78 ) ;
if ( V_135 )
F_99 ( V_135 ) ;
if ( V_136 )
F_99 ( V_136 ) ;
return V_19 ;
}
static int F_118 ( struct V_12 * V_13 , T_5 V_164 )
{
T_1 V_22 , V_23 , V_165 ;
int V_14 ;
V_165 = ( V_164 & ( ( 1ULL << V_121 ) |
( 1ULL << V_166 ) ) ) ?
sizeof( struct V_167 ) :
sizeof( struct V_110 ) ;
if ( V_164 & ( 1 << V_168 ) ) {
V_22 = V_165 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_165 ;
}
F_53 ( & V_13 -> V_41 . V_78 ) ;
if ( ( V_164 & ( 1 << V_120 ) ) &&
! F_119 ( & V_13 -> V_41 ) )
goto V_169;
if ( ( V_164 & ( 1ULL << V_170 ) ) ) {
if ( F_120 ( & V_13 -> V_41 , true ) )
goto V_169;
}
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_53 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_78 ) ;
V_13 -> V_16 [ V_14 ] . V_1 . V_171 = V_164 ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_67 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_78 ) ;
}
F_67 ( & V_13 -> V_41 . V_78 ) ;
return 0 ;
V_169:
F_67 ( & V_13 -> V_41 . V_78 ) ;
return - V_157 ;
}
static long F_121 ( struct V_12 * V_13 )
{
int V_11 ;
F_53 ( & V_13 -> V_41 . V_78 ) ;
if ( F_122 ( & V_13 -> V_41 ) ) {
V_11 = - V_172 ;
goto V_64;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 )
goto V_64;
V_11 = F_123 ( & V_13 -> V_41 ) ;
if ( V_11 )
F_16 ( V_13 ) ;
F_95 ( V_13 ) ;
V_64:
F_67 ( & V_13 -> V_41 . V_78 ) ;
return V_11 ;
}
static long F_124 ( struct V_54 * V_129 , unsigned int V_173 ,
unsigned long V_174 )
{
struct V_12 * V_13 = V_129 -> V_53 ;
void T_6 * V_175 = ( void T_6 * ) V_174 ;
T_5 T_6 * V_176 = V_175 ;
struct V_177 V_178 ;
T_5 V_164 ;
int V_11 ;
switch ( V_173 ) {
case V_179 :
if ( F_125 ( & V_178 , V_175 , sizeof V_178 ) )
return - V_157 ;
return F_110 ( V_13 , V_178 . V_137 , V_178 . V_138 ) ;
case V_180 :
V_164 = V_181 ;
if ( F_126 ( V_176 , & V_164 , sizeof V_164 ) )
return - V_157 ;
return 0 ;
case V_182 :
if ( F_125 ( & V_164 , V_176 , sizeof V_164 ) )
return - V_157 ;
if ( V_164 & ~ V_181 )
return - V_183 ;
return F_118 ( V_13 , V_164 ) ;
case V_184 :
return F_115 ( V_13 ) ;
case V_185 :
return F_121 ( V_13 ) ;
default:
F_53 ( & V_13 -> V_41 . V_78 ) ;
V_11 = F_127 ( & V_13 -> V_41 , V_173 , V_175 ) ;
if ( V_11 == - V_186 )
V_11 = F_128 ( & V_13 -> V_41 , V_173 , V_175 ) ;
else
F_95 ( V_13 ) ;
F_67 ( & V_13 -> V_41 . V_78 ) ;
return V_11 ;
}
}
static long F_129 ( struct V_54 * V_129 , unsigned int V_173 ,
unsigned long V_174 )
{
return F_124 ( V_129 , V_173 , ( unsigned long ) F_130 ( V_174 ) ) ;
}
static T_7 F_131 ( struct V_187 * V_188 , struct V_117 * V_189 )
{
struct V_54 * V_54 = V_188 -> V_190 ;
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
int V_191 = V_54 -> V_192 & V_193 ;
return F_132 ( V_41 , V_189 , V_191 ) ;
}
static T_7 F_133 ( struct V_187 * V_188 ,
struct V_117 * V_194 )
{
struct V_54 * V_54 = V_188 -> V_190 ;
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
return F_134 ( V_41 , V_194 ) ;
}
static unsigned int F_135 ( struct V_54 * V_54 , T_8 * V_10 )
{
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
return F_136 ( V_54 , V_41 , V_10 ) ;
}
static int F_137 ( void )
{
if ( V_30 )
F_1 ( V_63 ) ;
return F_138 ( & V_195 ) ;
}
static void F_139 ( void )
{
F_140 ( & V_195 ) ;
}
