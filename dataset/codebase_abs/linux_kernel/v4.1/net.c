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
static void F_33 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_49 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_50 , V_51 ;
int V_52 ;
struct V_53 V_54 = {
. V_55 = NULL ,
. V_56 = 0 ,
. V_57 = NULL ,
. V_58 = 0 ,
. V_59 = V_60 ,
} ;
T_1 V_38 , V_61 = 0 ;
int V_19 ;
T_1 V_62 ;
struct V_28 * V_29 ;
struct V_3 * V_63 ( V_6 ) ;
bool V_5 , V_64 ;
F_34 ( & V_1 -> V_65 ) ;
V_29 = V_1 -> V_66 ;
if ( ! V_29 )
goto V_50;
F_35 ( & V_24 -> V_41 , V_1 ) ;
V_62 = V_34 -> V_22 ;
V_5 = V_34 -> V_6 ;
for (; ; ) {
if ( V_5 )
F_24 ( V_24 , V_1 ) ;
if ( F_9 ( ( V_34 -> V_21 + V_1 -> V_67 - V_68 )
% V_18 == V_34 -> V_20 ) )
break;
V_52 = F_36 ( V_1 , V_1 -> V_69 ,
F_37 ( V_1 -> V_69 ) ,
& V_50 , & V_51 ,
NULL , NULL ) ;
if ( F_9 ( V_52 < 0 ) )
break;
if ( V_52 == V_1 -> V_67 ) {
if ( F_9 ( F_38 ( & V_24 -> V_41 , V_1 ) ) ) {
F_35 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
if ( V_51 ) {
F_39 ( V_1 , L_1
L_2 , V_50 , V_51 ) ;
break;
}
V_38 = F_40 ( V_1 -> V_69 , V_50 ) ;
F_41 ( & V_54 . V_70 , V_71 , V_1 -> V_69 , V_50 , V_38 ) ;
F_42 ( & V_54 . V_70 , V_62 ) ;
if ( ! F_43 ( & V_54 ) ) {
F_39 ( V_1 , L_3
L_4 ,
V_38 , V_62 ) ;
break;
}
V_38 = F_43 ( & V_54 ) ;
V_64 = V_5 && V_38 >= V_72
&& ( V_34 -> V_21 + 1 ) % V_18 !=
V_34 -> V_20
&& F_21 ( V_24 ) ;
if ( V_64 ) {
struct V_17 * V_42 ;
V_42 = V_34 -> V_17 + V_34 -> V_21 ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_73 = F_44 ( V_1 , V_52 ) ;
V_1 -> V_37 [ V_34 -> V_21 ] . V_38 = V_74 ;
V_42 -> V_75 = F_29 ;
V_42 -> V_44 = V_34 -> V_6 ;
V_42 -> V_46 = V_34 -> V_21 ;
V_54 . V_57 = V_42 ;
V_54 . V_58 = sizeof( V_42 ) ;
V_6 = V_34 -> V_6 ;
F_45 ( & V_6 -> V_9 ) ;
V_34 -> V_21 = ( V_34 -> V_21 + 1 ) % V_18 ;
} else {
V_54 . V_57 = NULL ;
V_6 = NULL ;
}
V_19 = V_29 -> V_76 -> V_77 ( V_29 , & V_54 , V_38 ) ;
if ( F_9 ( V_19 < 0 ) ) {
if ( V_64 ) {
F_7 ( V_6 ) ;
V_34 -> V_21 = ( ( unsigned ) V_34 -> V_21 - 1 )
% V_18 ;
}
F_46 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_38 )
F_47 ( L_5
L_6 , V_19 , V_38 ) ;
if ( ! V_64 )
F_48 ( & V_24 -> V_41 , V_1 , V_52 , 0 ) ;
else
F_24 ( V_24 , V_1 ) ;
V_61 += V_38 ;
F_19 ( V_24 ) ;
if ( F_9 ( V_61 >= V_78 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_50:
F_49 ( & V_1 -> V_65 ) ;
}
static int F_50 ( struct V_29 * V_31 )
{
struct V_79 * V_52 ;
int V_38 = 0 ;
unsigned long V_80 ;
F_51 ( & V_31 -> V_81 . V_82 , V_80 ) ;
V_52 = F_52 ( & V_31 -> V_81 ) ;
if ( F_53 ( V_52 ) ) {
V_38 = V_52 -> V_38 ;
if ( F_54 ( V_52 ) )
V_38 += V_83 ;
}
F_55 ( & V_31 -> V_81 . V_82 , V_80 ) ;
return V_38 ;
}
static int F_56 ( struct V_4 * V_1 ,
struct V_84 * V_37 ,
int V_85 ,
unsigned * V_86 ,
struct V_87 * log ,
unsigned * V_88 ,
unsigned int V_89 )
{
unsigned int V_50 , V_51 ;
int V_90 = 0 ;
int V_91 = 0 ;
unsigned V_92 ;
int V_11 , V_93 = 0 ;
T_2 V_63 ( V_38 ) ;
while ( V_85 > 0 && V_91 < V_89 ) {
if ( F_9 ( V_90 >= V_18 ) ) {
V_11 = - V_94 ;
goto V_19;
}
V_11 = F_36 ( V_1 , V_1 -> V_69 + V_90 ,
F_37 ( V_1 -> V_69 ) - V_90 , & V_50 ,
& V_51 , log , V_88 ) ;
if ( F_9 ( V_11 < 0 ) )
goto V_19;
V_92 = V_11 ;
if ( V_92 == V_1 -> V_67 ) {
V_11 = 0 ;
goto V_19;
}
if ( F_9 ( V_50 || V_51 <= 0 ) ) {
F_39 ( V_1 , L_7
L_8 , V_50 , V_51 ) ;
V_11 = - V_95 ;
goto V_19;
}
if ( F_9 ( log ) ) {
V_93 += * V_88 ;
log += * V_88 ;
}
V_37 [ V_91 ] . V_73 = F_44 ( V_1 , V_92 ) ;
V_38 = F_40 ( V_1 -> V_69 + V_90 , V_51 ) ;
V_37 [ V_91 ] . V_38 = F_44 ( V_1 , V_38 ) ;
V_85 -= V_38 ;
++ V_91 ;
V_90 += V_51 ;
}
V_37 [ V_91 - 1 ] . V_38 = F_44 ( V_1 , V_38 + V_85 ) ;
* V_86 = V_90 ;
if ( F_9 ( log ) )
* V_88 = V_93 ;
if ( F_9 ( V_85 > 0 ) ) {
V_11 = V_18 + 1 ;
goto V_19;
}
return V_91 ;
V_19:
F_46 ( V_1 , V_91 ) ;
return V_11 ;
}
static void F_57 ( struct V_12 * V_24 )
{
struct V_33 * V_34 = & V_24 -> V_16 [ V_96 ] ;
struct V_4 * V_1 = & V_34 -> V_1 ;
unsigned V_63 ( V_51 ) , log ;
struct V_87 * V_97 ;
struct V_53 V_54 = {
. V_55 = NULL ,
. V_56 = 0 ,
. V_57 = NULL ,
. V_58 = 0 ,
. V_59 = V_60 ,
} ;
struct V_98 V_99 = {
. V_80 = 0 ,
. V_100 = V_101
} ;
T_1 V_61 = 0 ;
int V_19 , V_102 ;
T_3 V_91 ;
T_1 V_22 , V_23 ;
T_1 V_103 , V_104 ;
struct V_28 * V_29 ;
struct V_105 V_106 ;
T_4 V_107 ;
F_34 ( & V_1 -> V_65 ) ;
V_29 = V_1 -> V_66 ;
if ( ! V_29 )
goto V_50;
F_35 ( & V_24 -> V_41 , V_1 ) ;
V_22 = V_34 -> V_22 ;
V_23 = V_34 -> V_23 ;
V_97 = F_9 ( F_58 ( V_1 , V_108 ) ) ?
V_1 -> log : NULL ;
V_102 = F_58 ( V_1 , V_109 ) ;
while ( ( V_104 = F_50 ( V_29 -> V_31 ) ) ) {
V_104 += V_23 ;
V_103 = V_104 + V_22 ;
V_91 = F_56 ( V_1 , V_1 -> V_37 , V_103 ,
& V_51 , V_97 , & log ,
F_53 ( V_102 ) ? V_18 : 1 ) ;
if ( F_9 ( V_91 < 0 ) )
break;
if ( F_9 ( V_91 > V_18 ) ) {
F_41 ( & V_54 . V_70 , V_110 , V_1 -> V_69 , 1 , 1 ) ;
V_19 = V_29 -> V_76 -> V_111 ( V_29 , & V_54 ,
1 , V_60 | V_112 ) ;
F_47 ( L_9 , V_104 ) ;
continue;
}
if ( ! V_91 ) {
if ( F_9 ( F_38 ( & V_24 -> V_41 , V_1 ) ) ) {
F_35 ( & V_24 -> V_41 , V_1 ) ;
continue;
}
break;
}
F_41 ( & V_54 . V_70 , V_110 , V_1 -> V_69 , V_51 , V_103 ) ;
V_106 = V_54 . V_70 ;
if ( F_9 ( ( V_22 ) ) ) {
F_42 ( & V_54 . V_70 , V_22 ) ;
}
V_19 = V_29 -> V_76 -> V_111 ( V_29 , & V_54 ,
V_104 , V_60 | V_112 ) ;
if ( F_9 ( V_19 != V_104 ) ) {
F_47 ( L_10
L_11 , V_19 , V_104 ) ;
F_46 ( V_1 , V_91 ) ;
continue;
}
if ( F_9 ( V_22 ) ) {
if ( F_59 ( & V_99 , sizeof( V_99 ) ,
& V_106 ) != sizeof( V_99 ) ) {
F_39 ( V_1 , L_12
L_13 , V_1 -> V_69 -> V_113 ) ;
break;
}
} else {
F_42 ( & V_106 , sizeof( V_99 ) ) ;
}
V_107 = F_60 ( V_1 , V_91 ) ;
if ( F_53 ( V_102 ) &&
F_59 ( & V_107 , sizeof V_107 ,
& V_106 ) != sizeof V_107 ) {
F_39 ( V_1 , L_14 ) ;
F_46 ( V_1 , V_91 ) ;
break;
}
F_28 ( & V_24 -> V_41 , V_1 , V_1 -> V_37 ,
V_91 ) ;
if ( F_9 ( V_97 ) )
F_61 ( V_1 , V_97 , log , V_103 ) ;
V_61 += V_103 ;
if ( F_9 ( V_61 >= V_78 ) ) {
F_31 ( & V_1 -> V_48 ) ;
break;
}
}
V_50:
F_49 ( & V_1 -> V_65 ) ;
}
static void F_62 ( struct V_114 * V_115 )
{
struct V_4 * V_1 = F_25 ( V_115 , struct V_4 ,
V_48 . V_115 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_33 ( V_24 ) ;
}
static void F_63 ( struct V_114 * V_115 )
{
struct V_4 * V_1 = F_25 ( V_115 , struct V_4 ,
V_48 . V_115 ) ;
struct V_12 * V_24 = F_25 ( V_1 -> V_41 , struct V_12 , V_41 ) ;
F_57 ( V_24 ) ;
}
static void F_64 ( struct V_114 * V_115 )
{
struct V_12 * V_24 = F_25 ( V_115 , struct V_12 ,
V_48 [ V_49 ] . V_115 ) ;
F_33 ( V_24 ) ;
}
static void F_65 ( struct V_114 * V_115 )
{
struct V_12 * V_24 = F_25 ( V_115 , struct V_12 ,
V_48 [ V_96 ] . V_115 ) ;
F_57 ( V_24 ) ;
}
static int F_66 ( struct V_116 * V_116 , struct V_117 * V_118 )
{
struct V_12 * V_13 ;
struct V_119 * V_41 ;
struct V_4 * * V_16 ;
int V_14 ;
V_13 = F_3 ( sizeof *V_13 , V_7 | V_120 | V_121 ) ;
if ( ! V_13 ) {
V_13 = F_67 ( sizeof *V_13 ) ;
if ( ! V_13 )
return - V_8 ;
}
V_16 = F_3 ( V_15 * sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 ) {
F_68 ( V_13 ) ;
return - V_8 ;
}
V_41 = & V_13 -> V_41 ;
V_16 [ V_49 ] = & V_13 -> V_16 [ V_49 ] . V_1 ;
V_16 [ V_96 ] = & V_13 -> V_16 [ V_96 ] . V_1 ;
V_13 -> V_16 [ V_49 ] . V_1 . V_122 = F_62 ;
V_13 -> V_16 [ V_96 ] . V_1 . V_122 = F_63 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
F_69 ( V_41 , V_16 , V_15 ) ;
F_70 ( V_13 -> V_48 + V_49 , F_64 , V_123 , V_41 ) ;
F_70 ( V_13 -> V_48 + V_96 , F_65 , V_124 , V_41 ) ;
V_118 -> V_66 = V_13 ;
return 0 ;
}
static void F_71 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_125 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
if ( ! V_1 -> V_66 )
return;
F_72 ( V_48 ) ;
}
static int F_73 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_33 * V_34 =
F_25 ( V_1 , struct V_33 , V_1 ) ;
struct V_125 * V_48 = V_13 -> V_48 + ( V_34 - V_13 -> V_16 ) ;
struct V_28 * V_29 ;
V_29 = V_1 -> V_66 ;
if ( ! V_29 )
return 0 ;
return F_74 ( V_48 , V_29 -> V_117 ) ;
}
static struct V_28 * F_75 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_28 * V_29 ;
F_34 ( & V_1 -> V_65 ) ;
V_29 = V_1 -> V_66 ;
F_71 ( V_13 , V_1 ) ;
V_1 -> V_66 = NULL ;
F_49 ( & V_1 -> V_65 ) ;
return V_29 ;
}
static void F_76 ( struct V_12 * V_13 , struct V_28 * * V_126 ,
struct V_28 * * V_127 )
{
* V_126 = F_75 ( V_13 , & V_13 -> V_16 [ V_49 ] . V_1 ) ;
* V_127 = F_75 ( V_13 , & V_13 -> V_16 [ V_96 ] . V_1 ) ;
}
static void F_77 ( struct V_12 * V_13 , int V_128 )
{
F_78 ( V_13 -> V_48 + V_128 ) ;
F_78 ( & V_13 -> V_16 [ V_128 ] . V_1 . V_48 ) ;
}
static void F_79 ( struct V_12 * V_13 )
{
F_77 ( V_13 , V_49 ) ;
F_77 ( V_13 , V_96 ) ;
if ( V_13 -> V_16 [ V_49 ] . V_6 ) {
F_34 ( & V_13 -> V_16 [ V_49 ] . V_1 . V_65 ) ;
V_13 -> V_27 = true ;
F_49 ( & V_13 -> V_16 [ V_49 ] . V_1 . V_65 ) ;
F_11 ( V_13 -> V_16 [ V_49 ] . V_6 ) ;
F_34 ( & V_13 -> V_16 [ V_49 ] . V_1 . V_65 ) ;
V_13 -> V_27 = false ;
F_5 ( & V_13 -> V_16 [ V_49 ] . V_6 -> V_9 , 1 ) ;
F_49 ( & V_13 -> V_16 [ V_49 ] . V_1 . V_65 ) ;
}
}
static int F_80 ( struct V_116 * V_116 , struct V_117 * V_118 )
{
struct V_12 * V_13 = V_118 -> V_66 ;
struct V_28 * V_126 ;
struct V_28 * V_127 ;
F_76 ( V_13 , & V_126 , & V_127 ) ;
F_79 ( V_13 ) ;
F_81 ( & V_13 -> V_41 ) ;
F_82 ( & V_13 -> V_41 , false ) ;
F_18 ( V_13 ) ;
if ( V_126 )
F_83 ( V_126 ) ;
if ( V_127 )
F_83 ( V_127 ) ;
F_84 () ;
F_79 ( V_13 ) ;
F_15 ( V_13 -> V_41 . V_16 ) ;
F_68 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_85 ( int V_129 )
{
struct {
struct V_130 V_131 ;
char V_132 [ V_133 ] ;
} V_134 ;
int V_135 = sizeof V_134 , V_11 ;
struct V_28 * V_29 = F_86 ( V_129 , & V_11 ) ;
if ( ! V_29 )
return F_4 ( - V_136 ) ;
if ( V_29 -> V_31 -> V_137 != V_138 ) {
V_11 = - V_139 ;
goto V_19;
}
V_11 = V_29 -> V_76 -> V_140 ( V_29 , (struct V_141 * ) & V_134 . V_131 ,
& V_135 , 0 ) ;
if ( V_11 )
goto V_19;
if ( V_134 . V_131 . V_142 != V_143 ) {
V_11 = - V_144 ;
goto V_19;
}
return V_29 ;
V_19:
F_83 ( V_29 ) ;
return F_4 ( V_11 ) ;
}
static struct V_28 * F_87 ( int V_129 )
{
struct V_117 * V_117 = F_88 ( V_129 ) ;
struct V_28 * V_29 ;
if ( ! V_117 )
return F_4 ( - V_145 ) ;
V_29 = F_89 ( V_117 ) ;
if ( ! F_90 ( V_29 ) )
return V_29 ;
V_29 = F_91 ( V_117 ) ;
if ( F_90 ( V_29 ) )
F_92 ( V_117 ) ;
return V_29 ;
}
static struct V_28 * F_93 ( int V_129 )
{
struct V_28 * V_29 ;
if ( V_129 == - 1 )
return NULL ;
V_29 = F_85 ( V_129 ) ;
if ( ! F_90 ( V_29 ) )
return V_29 ;
V_29 = F_87 ( V_129 ) ;
if ( ! F_90 ( V_29 ) )
return V_29 ;
return F_4 ( - V_136 ) ;
}
static long F_94 ( struct V_12 * V_13 , unsigned V_128 , int V_129 )
{
struct V_28 * V_29 , * V_146 ;
struct V_4 * V_1 ;
struct V_33 * V_34 ;
struct V_3 * V_6 , * V_147 = NULL ;
int V_11 ;
F_34 ( & V_13 -> V_41 . V_65 ) ;
V_11 = F_95 ( & V_13 -> V_41 ) ;
if ( V_11 )
goto V_19;
if ( V_128 >= V_15 ) {
V_11 = - V_94 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_128 ] . V_1 ;
V_34 = & V_13 -> V_16 [ V_128 ] ;
F_34 ( & V_1 -> V_65 ) ;
if ( ! F_96 ( V_1 ) ) {
V_11 = - V_148 ;
goto V_149;
}
V_29 = F_93 ( V_129 ) ;
if ( F_90 ( V_29 ) ) {
V_11 = F_97 ( V_29 ) ;
goto V_149;
}
V_146 = V_1 -> V_66 ;
if ( V_29 != V_146 ) {
V_6 = F_2 ( V_1 ,
V_29 && F_22 ( V_29 ) ) ;
if ( F_90 ( V_6 ) ) {
V_11 = F_97 ( V_6 ) ;
goto V_150;
}
F_71 ( V_13 , V_1 ) ;
V_1 -> V_66 = V_29 ;
V_11 = F_98 ( V_1 ) ;
if ( V_11 )
goto V_151;
V_11 = F_73 ( V_13 , V_1 ) ;
if ( V_11 )
goto V_151;
V_147 = V_34 -> V_6 ;
V_34 -> V_6 = V_6 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
V_13 -> V_27 = false ;
}
F_49 ( & V_1 -> V_65 ) ;
if ( V_147 ) {
F_14 ( V_147 ) ;
F_34 ( & V_1 -> V_65 ) ;
F_24 ( V_13 , V_1 ) ;
F_49 ( & V_1 -> V_65 ) ;
}
if ( V_146 ) {
F_77 ( V_13 , V_128 ) ;
F_83 ( V_146 ) ;
}
F_49 ( & V_13 -> V_41 . V_65 ) ;
return 0 ;
V_151:
V_1 -> V_66 = V_146 ;
F_73 ( V_13 , V_1 ) ;
if ( V_6 )
F_14 ( V_6 ) ;
V_150:
F_83 ( V_29 ) ;
V_149:
F_49 ( & V_1 -> V_65 ) ;
V_19:
F_49 ( & V_13 -> V_41 . V_65 ) ;
return V_11 ;
}
static long F_99 ( struct V_12 * V_13 )
{
struct V_28 * V_126 = NULL ;
struct V_28 * V_127 = NULL ;
long V_19 ;
struct V_152 * V_153 ;
F_34 ( & V_13 -> V_41 . V_65 ) ;
V_19 = F_95 ( & V_13 -> V_41 ) ;
if ( V_19 )
goto V_154;
V_153 = F_100 () ;
if ( ! V_153 ) {
V_19 = - V_8 ;
goto V_154;
}
F_76 ( V_13 , & V_126 , & V_127 ) ;
F_79 ( V_13 ) ;
F_101 ( & V_13 -> V_41 , V_153 ) ;
F_18 ( V_13 ) ;
V_154:
F_49 ( & V_13 -> V_41 . V_65 ) ;
if ( V_126 )
F_83 ( V_126 ) ;
if ( V_127 )
F_83 ( V_127 ) ;
return V_19 ;
}
static int F_102 ( struct V_12 * V_13 , T_5 V_155 )
{
T_1 V_22 , V_23 , V_156 ;
int V_14 ;
V_156 = ( V_155 & ( ( 1ULL << V_109 ) |
( 1ULL << V_157 ) ) ) ?
sizeof( struct V_158 ) :
sizeof( struct V_98 ) ;
if ( V_155 & ( 1 << V_159 ) ) {
V_22 = V_156 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_156 ;
}
F_34 ( & V_13 -> V_41 . V_65 ) ;
if ( ( V_155 & ( 1 << V_108 ) ) &&
! F_103 ( & V_13 -> V_41 ) ) {
F_49 ( & V_13 -> V_41 . V_65 ) ;
return - V_148 ;
}
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_34 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_65 ) ;
V_13 -> V_16 [ V_14 ] . V_1 . V_160 = V_155 ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_49 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_65 ) ;
}
F_49 ( & V_13 -> V_41 . V_65 ) ;
return 0 ;
}
static long F_104 ( struct V_12 * V_13 )
{
int V_11 ;
F_34 ( & V_13 -> V_41 . V_65 ) ;
if ( F_105 ( & V_13 -> V_41 ) ) {
V_11 = - V_161 ;
goto V_50;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 )
goto V_50;
V_11 = F_106 ( & V_13 -> V_41 ) ;
if ( V_11 )
F_16 ( V_13 ) ;
F_79 ( V_13 ) ;
V_50:
F_49 ( & V_13 -> V_41 . V_65 ) ;
return V_11 ;
}
static long F_107 ( struct V_117 * V_118 , unsigned int V_162 ,
unsigned long V_163 )
{
struct V_12 * V_13 = V_118 -> V_66 ;
void T_6 * V_164 = ( void T_6 * ) V_163 ;
T_5 T_6 * V_165 = V_164 ;
struct V_166 V_167 ;
T_5 V_155 ;
int V_11 ;
switch ( V_162 ) {
case V_168 :
if ( F_108 ( & V_167 , V_164 , sizeof V_167 ) )
return - V_148 ;
return F_94 ( V_13 , V_167 . V_128 , V_167 . V_129 ) ;
case V_169 :
V_155 = V_170 ;
if ( F_109 ( V_165 , & V_155 , sizeof V_155 ) )
return - V_148 ;
return 0 ;
case V_171 :
if ( F_108 ( & V_155 , V_165 , sizeof V_155 ) )
return - V_148 ;
if ( V_155 & ~ V_170 )
return - V_172 ;
return F_102 ( V_13 , V_155 ) ;
case V_173 :
return F_99 ( V_13 ) ;
case V_174 :
return F_104 ( V_13 ) ;
default:
F_34 ( & V_13 -> V_41 . V_65 ) ;
V_11 = F_110 ( & V_13 -> V_41 , V_162 , V_164 ) ;
if ( V_11 == - V_175 )
V_11 = F_111 ( & V_13 -> V_41 , V_162 , V_164 ) ;
else
F_79 ( V_13 ) ;
F_49 ( & V_13 -> V_41 . V_65 ) ;
return V_11 ;
}
}
static long F_112 ( struct V_117 * V_118 , unsigned int V_162 ,
unsigned long V_163 )
{
return F_107 ( V_118 , V_162 , ( unsigned long ) F_113 ( V_163 ) ) ;
}
static int F_114 ( void )
{
if ( V_30 )
F_1 ( V_49 ) ;
return F_115 ( & V_176 ) ;
}
static void F_116 ( void )
{
F_117 ( & V_176 ) ;
}
