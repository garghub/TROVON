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
static bool F_52 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_63 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
return ( V_34 -> V_21 + V_1 -> V_61 - V_64 ) % V_18
== V_34 -> V_20 ;
}
static void F_53 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_63 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_65 , V_66 ;
int V_67 ;
struct V_68 V_69 = {
. V_70 = NULL ,
. V_71 = 0 ,
. V_72 = NULL ,
. V_73 = 0 ,
. V_74 = V_75 ,
} ;
T_1 V_38 , V_76 = 0 ;
int V_19 ;
T_1 V_77 ;
struct V_28 * V_29 ;
struct V_3 * V_60 ( V_6 ) ;
bool V_5 , V_78 ;
F_54 ( & V_1 -> V_79 ) ;
V_29 = V_1 -> V_53 ;
if ( ! V_29 )
goto V_65;
if ( ! F_55 ( V_1 ) )
goto V_65;
F_56 ( & V_24 -> V_41 , V_1 ) ;
V_77 = V_34 -> V_22 ;
V_5 = V_34 -> V_6 ;
for (; ; ) {
if ( V_5 )
F_24 ( V_24 , V_1 ) ;
if ( F_9 ( F_52 ( V_24 ) ) )
break;
V_67 = F_45 ( V_24 , V_1 , V_1 -> V_56 ,
F_47 ( V_1 -> V_56 ) ,
& V_65 , & V_66 ) ;
if ( F_9 ( V_67 < 0 ) )
break;
if ( V_67 == V_1 -> V_61 ) {
if ( F_9 ( F_57 ( & V_24 -> V_41 , V_1 ) ) ) {
F_56 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
if ( V_66 ) {
F_58 ( V_1 , L_1
L_2 , V_65 , V_66 ) ;
break;
}
V_38 = F_59 ( V_1 -> V_56 , V_65 ) ;
F_60 ( & V_69 . V_80 , V_81 , V_1 -> V_56 , V_65 , V_38 ) ;
F_61 ( & V_69 . V_80 , V_77 ) ;
if ( ! F_62 ( & V_69 ) ) {
F_58 ( V_1 , L_3
L_4 ,
V_38 , V_77 ) ;
break;
}
V_38 = F_62 ( & V_69 ) ;
V_78 = V_5 && V_38 >= V_82
&& ( V_34 -> V_21 + 1 ) % V_18 !=
V_34 -> V_20
&& F_21 ( V_24 ) ;
if ( V_78 ) {
struct V_17 * V_42 ;
V_42 = V_34 -> V_17 + V_34 -> V_21 ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_83 = F_63 ( V_1 , V_67 ) ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_38 = V_84 ;
V_42 -> V_85 = F_29 ;
V_42 -> V_44 = V_34 -> V_6 ;
V_42 -> V_46 = V_34 -> V_21 ;
V_69 . V_72 = V_42 ;
V_69 . V_73 = sizeof( V_42 ) ;
V_6 = V_34 -> V_6 ;
F_64 ( & V_6 -> V_9 ) ;
V_34 -> V_21 = ( V_34 -> V_21 + 1 ) % V_18 ;
} else {
V_69 . V_72 = NULL ;
V_6 = NULL ;
}
V_76 += V_38 ;
if ( V_76 < V_86 &&
! F_49 ( & V_24 -> V_41 , V_1 ) &&
F_36 ( ! F_52 ( V_24 ) ) ) {
V_69 . V_74 |= V_87 ;
} else {
V_69 . V_74 &= ~ V_87 ;
}
V_19 = V_29 -> V_88 -> V_89 ( V_29 , & V_69 , V_38 ) ;
if ( F_9 ( V_19 < 0 ) ) {
if ( V_78 ) {
F_7 ( V_6 ) ;
V_34 -> V_21 = ( ( unsigned ) V_34 -> V_21 - 1 )
% V_18 ;
}
F_65 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_38 )
F_66 ( L_5
L_6 , V_19 , V_38 ) ;
if ( ! V_78 )
F_67 ( & V_24 -> V_41 , V_1 , V_67 , 0 ) ;
else
F_24 ( V_24 , V_1 ) ;
F_19 ( V_24 ) ;
if ( F_9 ( V_76 >= V_86 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_65:
F_68 ( & V_1 -> V_79 ) ;
}
static int F_69 ( struct V_29 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_90 ;
struct V_91 * V_67 ;
int V_38 = 0 ;
unsigned long V_92 ;
if ( V_29 -> V_88 -> V_93 )
return V_29 -> V_88 -> V_93 ( V_29 ) ;
F_70 ( & V_31 -> V_94 . V_95 , V_92 ) ;
V_67 = F_71 ( & V_31 -> V_94 ) ;
if ( F_36 ( V_67 ) ) {
V_38 = V_67 -> V_38 ;
if ( F_72 ( V_67 ) )
V_38 += V_96 ;
}
F_73 ( & V_31 -> V_94 . V_95 , V_92 ) ;
return V_38 ;
}
static int F_74 ( struct V_29 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_90 ;
if ( V_29 -> V_88 -> V_93 )
return V_29 -> V_88 -> V_93 ( V_29 ) ;
return F_75 ( & V_31 -> V_94 ) ;
}
static int F_76 ( struct V_12 * V_24 , struct V_29 * V_31 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_63 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned long V_60 ( V_50 ) ;
int V_38 = F_69 ( V_31 ) ;
if ( ! V_38 && V_1 -> V_62 ) {
F_54 ( & V_1 -> V_79 ) ;
F_56 ( & V_24 -> V_41 , V_1 ) ;
F_48 () ;
V_50 = F_33 () + V_1 -> V_62 ;
while ( F_35 ( & V_24 -> V_41 , V_50 ) &&
! F_74 ( V_31 ) &&
F_49 ( & V_24 -> V_41 , V_1 ) )
F_50 () ;
F_51 () ;
if ( F_57 ( & V_24 -> V_41 , V_1 ) )
F_31 ( & V_1 -> V_48 ) ;
F_68 ( & V_1 -> V_79 ) ;
V_38 = F_69 ( V_31 ) ;
}
return V_38 ;
}
static int F_77 ( struct V_4 * V_1 ,
struct V_97 * V_37 ,
int V_98 ,
unsigned * V_99 ,
struct V_100 * log ,
unsigned * V_101 ,
unsigned int V_102 )
{
unsigned int V_65 , V_66 ;
int V_103 = 0 ;
int V_104 = 0 ;
unsigned V_105 ;
int V_11 , V_106 = 0 ;
T_2 V_60 ( V_38 ) ;
while ( V_98 > 0 && V_104 < V_102 ) {
if ( F_9 ( V_103 >= V_18 ) ) {
V_11 = - V_107 ;
goto V_19;
}
V_11 = F_46 ( V_1 , V_1 -> V_56 + V_103 ,
F_47 ( V_1 -> V_56 ) - V_103 , & V_65 ,
& V_66 , log , V_101 ) ;
if ( F_9 ( V_11 < 0 ) )
goto V_19;
V_105 = V_11 ;
if ( V_105 == V_1 -> V_61 ) {
V_11 = 0 ;
goto V_19;
}
if ( F_9 ( V_65 || V_66 <= 0 ) ) {
F_58 ( V_1 , L_7
L_8 , V_65 , V_66 ) ;
V_11 = - V_108 ;
goto V_19;
}
if ( F_9 ( log ) ) {
V_106 += * V_101 ;
log += * V_101 ;
}
V_37 [ V_104 ] . V_83 = F_63 ( V_1 , V_105 ) ;
V_38 = F_59 ( V_1 -> V_56 + V_103 , V_66 ) ;
V_37 [ V_104 ] . V_38 = F_63 ( V_1 , V_38 ) ;
V_98 -= V_38 ;
++ V_104 ;
V_103 += V_66 ;
}
V_37 [ V_104 - 1 ] . V_38 = F_63 ( V_1 , V_38 + V_98 ) ;
* V_99 = V_103 ;
if ( F_9 ( log ) )
* V_101 = V_106 ;
if ( F_9 ( V_98 > 0 ) ) {
V_11 = V_18 + 1 ;
goto V_19;
}
return V_104 ;
V_19:
F_65 ( V_1 , V_104 ) ;
return V_11 ;
}
static void F_78 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_109 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_60 ( V_66 ) , log ;
struct V_100 * V_110 ;
struct V_68 V_69 = {
. V_70 = NULL ,
. V_71 = 0 ,
. V_72 = NULL ,
. V_73 = 0 ,
. V_74 = V_75 ,
} ;
struct V_111 V_112 = {
. V_92 = 0 ,
. V_113 = V_114
} ;
T_1 V_76 = 0 ;
int V_19 , V_115 ;
T_3 V_104 ;
T_1 V_22 , V_23 ;
T_1 V_116 , V_117 ;
struct V_28 * V_29 ;
struct V_118 V_119 ;
T_4 V_120 ;
F_54 ( & V_1 -> V_79 ) ;
V_29 = V_1 -> V_53 ;
if ( ! V_29 )
goto V_65;
if ( ! F_55 ( V_1 ) )
goto V_65;
F_56 ( & V_24 -> V_41 , V_1 ) ;
F_41 ( V_24 , V_1 ) ;
V_22 = V_34 -> V_22 ;
V_23 = V_34 -> V_23 ;
V_110 = F_9 ( F_79 ( V_1 , V_121 ) ) ?
V_1 -> log : NULL ;
V_115 = F_79 ( V_1 , V_122 ) ;
while ( ( V_117 = F_76 ( V_24 , V_29 -> V_31 ) ) ) {
V_117 += V_23 ;
V_116 = V_117 + V_22 ;
V_104 = F_77 ( V_1 , V_1 -> V_37 , V_116 ,
& V_66 , V_110 , & log ,
F_36 ( V_115 ) ? V_18 : 1 ) ;
if ( F_9 ( V_104 < 0 ) )
goto V_65;
if ( F_9 ( V_104 > V_18 ) ) {
F_60 ( & V_69 . V_80 , V_123 , V_1 -> V_56 , 1 , 1 ) ;
V_19 = V_29 -> V_88 -> V_124 ( V_29 , & V_69 ,
1 , V_75 | V_125 ) ;
F_66 ( L_9 , V_117 ) ;
continue;
}
if ( ! V_104 ) {
if ( F_9 ( F_57 ( & V_24 -> V_41 , V_1 ) ) ) {
F_56 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
goto V_65;
}
F_60 ( & V_69 . V_80 , V_123 , V_1 -> V_56 , V_66 , V_116 ) ;
V_119 = V_69 . V_80 ;
if ( F_9 ( ( V_22 ) ) ) {
F_61 ( & V_69 . V_80 , V_22 ) ;
}
V_19 = V_29 -> V_88 -> V_124 ( V_29 , & V_69 ,
V_117 , V_75 | V_125 ) ;
if ( F_9 ( V_19 != V_117 ) ) {
F_66 ( L_10
L_11 , V_19 , V_117 ) ;
F_65 ( V_1 , V_104 ) ;
continue;
}
if ( F_9 ( V_22 ) ) {
if ( F_80 ( & V_112 , sizeof( V_112 ) ,
& V_119 ) != sizeof( V_112 ) ) {
F_58 ( V_1 , L_12
L_13 , V_1 -> V_56 -> V_126 ) ;
goto V_65;
}
} else {
F_61 ( & V_119 , sizeof( V_112 ) ) ;
}
V_120 = F_81 ( V_1 , V_104 ) ;
if ( F_36 ( V_115 ) &&
F_80 ( & V_120 , sizeof V_120 ,
& V_119 ) != sizeof V_120 ) {
F_58 ( V_1 , L_14 ) ;
F_65 ( V_1 , V_104 ) ;
goto V_65;
}
F_28 ( & V_24 -> V_41 , V_1 , V_1 -> V_37 ,
V_104 ) ;
if ( F_9 ( V_110 ) )
F_82 ( V_1 , V_110 , log , V_116 ) ;
V_76 += V_116 ;
if ( F_9 ( V_76 >= V_86 ) ) {
F_31 ( & V_1 -> V_48 ) ;
goto V_65;
}
}
F_43 ( V_24 , V_1 ) ;
V_65:
F_68 ( & V_1 -> V_79 ) ;
}
static void F_83 ( struct V_127 * V_128 )
{
struct V_4 * V_1 = F_25 ( V_128 , struct V_4 ,
V_48 . V_128 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_53 ( V_24 ) ;
}
static void F_84 ( struct V_127 * V_128 )
{
struct V_4 * V_1 = F_25 ( V_128 , struct V_4 ,
V_48 . V_128 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_78 ( V_24 ) ;
}
static void F_85 ( struct V_127 * V_128 )
{
struct V_12 * V_24 = F_25 ( V_128 , struct V_12 ,
V_48 [ V_63 ] . V_128 ) ;
F_53 ( V_24 ) ;
}
static void F_86 ( struct V_127 * V_128 )
{
struct V_12 * V_24 = F_25 ( V_128 , struct V_12 ,
V_48 [ V_109 ] . V_128 ) ;
F_78 ( V_24 ) ;
}
static int F_87 ( struct V_129 * V_129 , struct V_54 * V_130 )
{
struct V_12 * V_13 ;
struct V_49 * V_41 ;
struct V_4 * * V_16 ;
int V_14 ;
V_13 = F_88 ( sizeof *V_13 , V_7 | V_131 ) ;
if ( ! V_13 )
return - V_8 ;
V_16 = F_3 ( V_15 * sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 ) {
F_89 ( V_13 ) ;
return - V_8 ;
}
V_41 = & V_13 -> V_41 ;
V_16 [ V_63 ] = & V_13 -> V_16 [ V_63 ] . V_1 ;
V_16 [ V_109 ] = & V_13 -> V_16 [ V_109 ] . V_1 ;
V_13 -> V_16 [ V_63 ] . V_1 . V_132 = F_83 ;
V_13 -> V_16 [ V_109 ] . V_1 . V_132 = F_84 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
F_90 ( V_41 , V_16 , V_15 ) ;
F_91 ( V_13 -> V_48 + V_63 , F_85 , V_133 , V_41 ) ;
F_91 ( V_13 -> V_48 + V_109 , F_86 , V_134 , V_41 ) ;
V_130 -> V_53 = V_13 ;
return 0 ;
}
static struct V_28 * F_92 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_28 * V_29 ;
F_54 ( & V_1 -> V_79 ) ;
V_29 = V_1 -> V_53 ;
F_41 ( V_13 , V_1 ) ;
V_1 -> V_53 = NULL ;
F_68 ( & V_1 -> V_79 ) ;
return V_29 ;
}
static void F_93 ( struct V_12 * V_13 , struct V_28 * * V_135 ,
struct V_28 * * V_136 )
{
* V_135 = F_92 ( V_13 , & V_13 -> V_16 [ V_63 ] . V_1 ) ;
* V_136 = F_92 ( V_13 , & V_13 -> V_16 [ V_109 ] . V_1 ) ;
}
static void F_94 ( struct V_12 * V_13 , int V_137 )
{
F_95 ( V_13 -> V_48 + V_137 ) ;
F_95 ( & V_13 -> V_16 [ V_137 ] . V_1 . V_48 ) ;
}
static void F_96 ( struct V_12 * V_13 )
{
F_94 ( V_13 , V_63 ) ;
F_94 ( V_13 , V_109 ) ;
if ( V_13 -> V_16 [ V_63 ] . V_6 ) {
F_54 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_79 ) ;
V_13 -> V_27 = true ;
F_68 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_79 ) ;
F_11 ( V_13 -> V_16 [ V_63 ] . V_6 ) ;
F_54 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_79 ) ;
V_13 -> V_27 = false ;
F_5 ( & V_13 -> V_16 [ V_63 ] . V_6 -> V_9 , 1 ) ;
F_68 ( & V_13 -> V_16 [ V_63 ] . V_1 . V_79 ) ;
}
}
static int F_97 ( struct V_129 * V_129 , struct V_54 * V_130 )
{
struct V_12 * V_13 = V_130 -> V_53 ;
struct V_28 * V_135 ;
struct V_28 * V_136 ;
F_93 ( V_13 , & V_135 , & V_136 ) ;
F_96 ( V_13 ) ;
F_98 ( & V_13 -> V_41 ) ;
F_99 ( & V_13 -> V_41 , false ) ;
F_18 ( V_13 ) ;
if ( V_135 )
F_100 ( V_135 ) ;
if ( V_136 )
F_100 ( V_136 ) ;
F_101 () ;
F_96 ( V_13 ) ;
F_15 ( V_13 -> V_41 . V_16 ) ;
F_89 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_102 ( int V_138 )
{
struct {
struct V_139 V_140 ;
char V_141 [ V_142 ] ;
} V_143 ;
int V_144 = sizeof V_143 , V_11 ;
struct V_28 * V_29 = F_103 ( V_138 , & V_11 ) ;
if ( ! V_29 )
return F_4 ( - V_145 ) ;
if ( V_29 -> V_31 -> V_146 != V_147 ) {
V_11 = - V_148 ;
goto V_19;
}
V_11 = V_29 -> V_88 -> V_149 ( V_29 , (struct V_150 * ) & V_143 . V_140 ,
& V_144 , 0 ) ;
if ( V_11 )
goto V_19;
if ( V_143 . V_140 . V_151 != V_152 ) {
V_11 = - V_153 ;
goto V_19;
}
return V_29 ;
V_19:
F_100 ( V_29 ) ;
return F_4 ( V_11 ) ;
}
static struct V_28 * F_104 ( int V_138 )
{
struct V_54 * V_54 = F_105 ( V_138 ) ;
struct V_28 * V_29 ;
if ( ! V_54 )
return F_4 ( - V_154 ) ;
V_29 = F_106 ( V_54 ) ;
if ( ! F_107 ( V_29 ) )
return V_29 ;
V_29 = F_108 ( V_54 ) ;
if ( F_107 ( V_29 ) )
F_109 ( V_54 ) ;
return V_29 ;
}
static struct V_28 * F_110 ( int V_138 )
{
struct V_28 * V_29 ;
if ( V_138 == - 1 )
return NULL ;
V_29 = F_102 ( V_138 ) ;
if ( ! F_107 ( V_29 ) )
return V_29 ;
V_29 = F_104 ( V_138 ) ;
if ( ! F_107 ( V_29 ) )
return V_29 ;
return F_4 ( - V_145 ) ;
}
static long F_111 ( struct V_12 * V_13 , unsigned V_137 , int V_138 )
{
struct V_28 * V_29 , * V_155 ;
struct V_4 * V_1 ;
struct V_33 * V_34 ;
struct V_3 * V_6 , * V_156 = NULL ;
int V_11 ;
F_54 ( & V_13 -> V_41 . V_79 ) ;
V_11 = F_112 ( & V_13 -> V_41 ) ;
if ( V_11 )
goto V_19;
if ( V_137 >= V_15 ) {
V_11 = - V_107 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_137 ] . V_1 ;
V_34 = & V_13 -> V_16 [ V_137 ] ;
F_54 ( & V_1 -> V_79 ) ;
if ( ! F_113 ( V_1 ) ) {
V_11 = - V_157 ;
goto V_158;
}
V_29 = F_110 ( V_138 ) ;
if ( F_107 ( V_29 ) ) {
V_11 = F_114 ( V_29 ) ;
goto V_158;
}
V_155 = V_1 -> V_53 ;
if ( V_29 != V_155 ) {
V_6 = F_2 ( V_1 ,
V_29 && F_22 ( V_29 ) ) ;
if ( F_107 ( V_6 ) ) {
V_11 = F_114 ( V_6 ) ;
goto V_159;
}
F_41 ( V_13 , V_1 ) ;
V_1 -> V_53 = V_29 ;
V_11 = F_115 ( V_1 ) ;
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
F_68 ( & V_1 -> V_79 ) ;
if ( V_156 ) {
F_14 ( V_156 ) ;
F_54 ( & V_1 -> V_79 ) ;
F_24 ( V_13 , V_1 ) ;
F_68 ( & V_1 -> V_79 ) ;
}
if ( V_155 ) {
F_94 ( V_13 , V_137 ) ;
F_100 ( V_155 ) ;
}
F_68 ( & V_13 -> V_41 . V_79 ) ;
return 0 ;
V_160:
V_1 -> V_53 = V_155 ;
F_43 ( V_13 , V_1 ) ;
if ( V_6 )
F_14 ( V_6 ) ;
V_159:
F_100 ( V_29 ) ;
V_158:
F_68 ( & V_1 -> V_79 ) ;
V_19:
F_68 ( & V_13 -> V_41 . V_79 ) ;
return V_11 ;
}
static long F_116 ( struct V_12 * V_13 )
{
struct V_28 * V_135 = NULL ;
struct V_28 * V_136 = NULL ;
long V_19 ;
struct V_161 * V_162 ;
F_54 ( & V_13 -> V_41 . V_79 ) ;
V_19 = F_112 ( & V_13 -> V_41 ) ;
if ( V_19 )
goto V_163;
V_162 = F_117 () ;
if ( ! V_162 ) {
V_19 = - V_8 ;
goto V_163;
}
F_93 ( V_13 , & V_135 , & V_136 ) ;
F_96 ( V_13 ) ;
F_118 ( & V_13 -> V_41 , V_162 ) ;
F_18 ( V_13 ) ;
V_163:
F_68 ( & V_13 -> V_41 . V_79 ) ;
if ( V_135 )
F_100 ( V_135 ) ;
if ( V_136 )
F_100 ( V_136 ) ;
return V_19 ;
}
static int F_119 ( struct V_12 * V_13 , T_5 V_164 )
{
T_1 V_22 , V_23 , V_165 ;
int V_14 ;
V_165 = ( V_164 & ( ( 1ULL << V_122 ) |
( 1ULL << V_166 ) ) ) ?
sizeof( struct V_167 ) :
sizeof( struct V_111 ) ;
if ( V_164 & ( 1 << V_168 ) ) {
V_22 = V_165 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_165 ;
}
F_54 ( & V_13 -> V_41 . V_79 ) ;
if ( ( V_164 & ( 1 << V_121 ) ) &&
! F_120 ( & V_13 -> V_41 ) )
goto V_169;
if ( ( V_164 & ( 1ULL << V_170 ) ) ) {
if ( F_121 ( & V_13 -> V_41 , true ) )
goto V_169;
}
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_54 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_79 ) ;
V_13 -> V_16 [ V_14 ] . V_1 . V_171 = V_164 ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_68 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_79 ) ;
}
F_68 ( & V_13 -> V_41 . V_79 ) ;
return 0 ;
V_169:
F_68 ( & V_13 -> V_41 . V_79 ) ;
return - V_157 ;
}
static long F_122 ( struct V_12 * V_13 )
{
int V_11 ;
F_54 ( & V_13 -> V_41 . V_79 ) ;
if ( F_123 ( & V_13 -> V_41 ) ) {
V_11 = - V_172 ;
goto V_65;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 )
goto V_65;
V_11 = F_124 ( & V_13 -> V_41 ) ;
if ( V_11 )
F_16 ( V_13 ) ;
F_96 ( V_13 ) ;
V_65:
F_68 ( & V_13 -> V_41 . V_79 ) ;
return V_11 ;
}
static long F_125 ( struct V_54 * V_130 , unsigned int V_173 ,
unsigned long V_174 )
{
struct V_12 * V_13 = V_130 -> V_53 ;
void T_6 * V_175 = ( void T_6 * ) V_174 ;
T_5 T_6 * V_176 = V_175 ;
struct V_177 V_178 ;
T_5 V_164 ;
int V_11 ;
switch ( V_173 ) {
case V_179 :
if ( F_126 ( & V_178 , V_175 , sizeof V_178 ) )
return - V_157 ;
return F_111 ( V_13 , V_178 . V_137 , V_178 . V_138 ) ;
case V_180 :
V_164 = V_181 ;
if ( F_127 ( V_176 , & V_164 , sizeof V_164 ) )
return - V_157 ;
return 0 ;
case V_182 :
if ( F_126 ( & V_164 , V_176 , sizeof V_164 ) )
return - V_157 ;
if ( V_164 & ~ V_181 )
return - V_183 ;
return F_119 ( V_13 , V_164 ) ;
case V_184 :
return F_116 ( V_13 ) ;
case V_185 :
return F_122 ( V_13 ) ;
default:
F_54 ( & V_13 -> V_41 . V_79 ) ;
V_11 = F_128 ( & V_13 -> V_41 , V_173 , V_175 ) ;
if ( V_11 == - V_186 )
V_11 = F_129 ( & V_13 -> V_41 , V_173 , V_175 ) ;
else
F_96 ( V_13 ) ;
F_68 ( & V_13 -> V_41 . V_79 ) ;
return V_11 ;
}
}
static long F_130 ( struct V_54 * V_130 , unsigned int V_173 ,
unsigned long V_174 )
{
return F_125 ( V_130 , V_173 , ( unsigned long ) F_131 ( V_174 ) ) ;
}
static T_7 F_132 ( struct V_187 * V_188 , struct V_118 * V_189 )
{
struct V_54 * V_54 = V_188 -> V_190 ;
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
int V_191 = V_54 -> V_192 & V_193 ;
return F_133 ( V_41 , V_189 , V_191 ) ;
}
static T_7 F_134 ( struct V_187 * V_188 ,
struct V_118 * V_194 )
{
struct V_54 * V_54 = V_188 -> V_190 ;
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
return F_135 ( V_41 , V_194 ) ;
}
static unsigned int F_136 ( struct V_54 * V_54 , T_8 * V_10 )
{
struct V_12 * V_13 = V_54 -> V_53 ;
struct V_49 * V_41 = & V_13 -> V_41 ;
return F_137 ( V_54 , V_41 , V_10 ) ;
}
static int F_138 ( void )
{
if ( V_30 )
F_1 ( V_63 ) ;
return F_139 ( & V_195 ) ;
}
static void F_140 ( void )
{
F_141 ( & V_195 ) ;
}
