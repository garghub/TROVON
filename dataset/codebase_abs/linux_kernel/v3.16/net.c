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
static int F_24 ( struct V_33 * V_34 , struct V_33 * V_35 ,
T_1 V_36 , int V_37 )
{
int V_38 = 0 ;
T_1 V_39 ;
while ( V_36 && V_38 < V_37 ) {
V_39 = F_25 ( V_34 -> V_40 , V_36 ) ;
V_35 -> V_41 = V_34 -> V_41 ;
V_35 -> V_40 = V_39 ;
V_34 -> V_40 -= V_39 ;
V_34 -> V_41 += V_39 ;
V_36 -= V_39 ;
++ V_34 ;
++ V_35 ;
++ V_38 ;
}
return V_38 ;
}
static void F_26 ( const struct V_33 * V_34 , struct V_33 * V_35 ,
T_1 V_36 , int V_42 )
{
int V_38 = 0 ;
T_1 V_39 ;
while ( V_36 && V_38 < V_42 ) {
V_39 = F_25 ( V_34 -> V_40 , V_36 ) ;
V_35 -> V_41 = V_34 -> V_41 ;
V_35 -> V_40 = V_39 ;
V_36 -= V_39 ;
++ V_34 ;
++ V_35 ;
++ V_38 ;
}
}
static void F_27 ( struct V_12 * V_24 ,
struct V_4 * V_1 )
{
struct V_43 * V_44 =
F_28 ( V_1 , struct V_43 , V_1 ) ;
int V_14 , V_45 ;
int V_46 = 0 ;
for ( V_14 = V_44 -> V_20 ; V_14 != V_44 -> V_21 ; V_14 = ( V_14 + 1 ) % V_18 ) {
if ( V_1 -> V_47 [ V_14 ] . V_36 == V_48 )
F_20 ( V_24 ) ;
if ( F_29 ( V_1 -> V_47 [ V_14 ] . V_36 ) ) {
V_1 -> V_47 [ V_14 ] . V_36 = V_49 ;
++ V_46 ;
} else
break;
}
while ( V_46 ) {
V_45 = F_25 ( V_18 - V_44 -> V_20 , V_46 ) ;
F_30 ( V_1 -> V_50 , V_1 ,
& V_1 -> V_47 [ V_44 -> V_20 ] , V_45 ) ;
V_44 -> V_20 = ( V_44 -> V_20 + V_45 ) % V_18 ;
V_46 -= V_45 ;
}
}
static void F_31 ( struct V_17 * V_51 , bool V_52 )
{
struct V_3 * V_6 = V_51 -> V_53 ;
struct V_4 * V_1 = V_6 -> V_1 ;
int V_54 ;
F_32 () ;
V_1 -> V_47 [ V_51 -> V_55 ] . V_36 = V_52 ?
V_56 : V_48 ;
V_54 = F_7 ( V_6 ) ;
if ( V_54 <= 1 || ! ( V_54 % 16 ) )
F_33 ( & V_1 -> V_57 ) ;
F_34 () ;
}
static void F_35 ( struct V_12 * V_24 )
{
struct V_43 * V_44 = & V_24 -> V_16 [ V_58 ] ;
struct V_4 * V_1 = & V_44 -> V_1 ;
unsigned V_59 , V_60 , V_61 ;
int V_62 ;
struct V_63 V_64 = {
. V_65 = NULL ,
. V_66 = 0 ,
. V_67 = NULL ,
. V_68 = 0 ,
. V_69 = V_1 -> V_70 ,
. V_71 = V_72 ,
} ;
T_1 V_36 , V_73 = 0 ;
int V_19 ;
T_1 V_74 ;
struct V_28 * V_29 ;
struct V_3 * V_75 ( V_6 ) ;
bool V_5 , V_76 ;
F_36 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
goto V_59;
F_37 ( & V_24 -> V_50 , V_1 ) ;
V_74 = V_44 -> V_22 ;
V_5 = V_44 -> V_6 ;
for (; ; ) {
if ( V_5 )
F_27 ( V_24 , V_1 ) ;
if ( F_9 ( ( V_44 -> V_21 + V_1 -> V_79 - V_80 )
% V_18 == V_44 -> V_20 ) )
break;
V_62 = F_38 ( V_1 , V_1 -> V_70 ,
F_39 ( V_1 -> V_70 ) ,
& V_59 , & V_60 ,
NULL , NULL ) ;
if ( F_9 ( V_62 < 0 ) )
break;
if ( V_62 == V_1 -> V_79 ) {
if ( F_9 ( F_40 ( & V_24 -> V_50 , V_1 ) ) ) {
F_37 ( & V_24 -> V_50 , V_1 ) ;
continue;
}
break;
}
if ( V_60 ) {
F_41 ( V_1 , L_1
L_2 , V_59 , V_60 ) ;
break;
}
V_61 = F_24 ( V_1 -> V_70 , V_44 -> V_81 , V_74 , V_59 ) ;
V_64 . V_82 = V_59 ;
V_36 = F_42 ( V_1 -> V_70 , V_59 ) ;
if ( ! V_36 ) {
F_41 ( V_1 , L_3
L_4 ,
F_42 ( V_44 -> V_81 , V_61 ) , V_74 ) ;
break;
}
V_76 = V_5 && V_36 >= V_83
&& ( V_44 -> V_21 + 1 ) % V_18 !=
V_44 -> V_20
&& F_21 ( V_24 ) ;
if ( V_76 ) {
struct V_17 * V_51 ;
V_51 = V_44 -> V_17 + V_44 -> V_21 ;
V_1 -> V_47 [ V_44 -> V_21 ] . V_84 = V_62 ;
V_1 -> V_47 [ V_44 -> V_21 ] . V_36 = V_85 ;
V_51 -> V_86 = F_31 ;
V_51 -> V_53 = V_44 -> V_6 ;
V_51 -> V_55 = V_44 -> V_21 ;
V_64 . V_67 = V_51 ;
V_64 . V_68 = sizeof( V_51 ) ;
V_6 = V_44 -> V_6 ;
F_43 ( & V_6 -> V_9 ) ;
V_44 -> V_21 = ( V_44 -> V_21 + 1 ) % V_18 ;
} else {
V_64 . V_67 = NULL ;
V_6 = NULL ;
}
V_19 = V_29 -> V_87 -> V_88 ( NULL , V_29 , & V_64 , V_36 ) ;
if ( F_9 ( V_19 < 0 ) ) {
if ( V_76 ) {
F_7 ( V_6 ) ;
V_44 -> V_21 = ( ( unsigned ) V_44 -> V_21 - 1 )
% V_18 ;
}
F_44 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_36 )
F_45 ( L_5
L_6 , V_19 , V_36 ) ;
if ( ! V_76 )
F_46 ( & V_24 -> V_50 , V_1 , V_62 , 0 ) ;
else
F_27 ( V_24 , V_1 ) ;
V_73 += V_36 ;
F_19 ( V_24 ) ;
if ( F_9 ( V_73 >= V_89 ) ) {
F_33 ( & V_1 -> V_57 ) ;
break;
}
}
V_59:
F_47 ( & V_1 -> V_77 ) ;
}
static int F_48 ( struct V_29 * V_31 )
{
struct V_90 * V_62 ;
int V_36 = 0 ;
unsigned long V_91 ;
F_49 ( & V_31 -> V_92 . V_93 , V_91 ) ;
V_62 = F_50 ( & V_31 -> V_92 ) ;
if ( F_51 ( V_62 ) ) {
V_36 = V_62 -> V_36 ;
if ( F_52 ( V_62 ) )
V_36 += V_94 ;
}
F_53 ( & V_31 -> V_92 . V_93 , V_91 ) ;
return V_36 ;
}
static int F_54 ( struct V_4 * V_1 ,
struct V_95 * V_47 ,
int V_96 ,
unsigned * V_42 ,
struct V_97 * log ,
unsigned * V_98 ,
unsigned int V_99 )
{
unsigned int V_59 , V_60 ;
int V_38 = 0 ;
int V_100 = 0 ;
unsigned V_101 ;
int V_11 , V_102 = 0 ;
while ( V_96 > 0 && V_100 < V_99 ) {
if ( F_9 ( V_38 >= V_18 ) ) {
V_11 = - V_103 ;
goto V_19;
}
V_11 = F_38 ( V_1 , V_1 -> V_70 + V_38 ,
F_39 ( V_1 -> V_70 ) - V_38 , & V_59 ,
& V_60 , log , V_98 ) ;
if ( F_9 ( V_11 < 0 ) )
goto V_19;
V_101 = V_11 ;
if ( V_101 == V_1 -> V_79 ) {
V_11 = 0 ;
goto V_19;
}
if ( F_9 ( V_59 || V_60 <= 0 ) ) {
F_41 ( V_1 , L_7
L_8 , V_59 , V_60 ) ;
V_11 = - V_104 ;
goto V_19;
}
if ( F_9 ( log ) ) {
V_102 += * V_98 ;
log += * V_98 ;
}
V_47 [ V_100 ] . V_84 = V_101 ;
V_47 [ V_100 ] . V_36 = F_42 ( V_1 -> V_70 + V_38 , V_60 ) ;
V_96 -= V_47 [ V_100 ] . V_36 ;
++ V_100 ;
V_38 += V_60 ;
}
V_47 [ V_100 - 1 ] . V_36 += V_96 ;
* V_42 = V_38 ;
if ( F_9 ( log ) )
* V_98 = V_102 ;
if ( F_9 ( V_96 > 0 ) ) {
V_11 = V_18 + 1 ;
goto V_19;
}
return V_100 ;
V_19:
F_44 ( V_1 , V_100 ) ;
return V_11 ;
}
static void F_55 ( struct V_12 * V_24 )
{
struct V_43 * V_44 = & V_24 -> V_16 [ V_105 ] ;
struct V_4 * V_1 = & V_44 -> V_1 ;
unsigned V_75 ( V_60 ) , log ;
struct V_97 * V_106 ;
struct V_63 V_64 = {
. V_65 = NULL ,
. V_66 = 0 ,
. V_67 = NULL ,
. V_68 = 0 ,
. V_69 = V_1 -> V_70 ,
. V_71 = V_72 ,
} ;
struct V_107 V_81 = {
. V_81 . V_91 = 0 ,
. V_81 . V_108 = V_109
} ;
T_1 V_73 = 0 ;
int V_19 , V_110 ;
T_2 V_100 ;
T_1 V_22 , V_23 ;
T_1 V_111 , V_112 ;
struct V_28 * V_29 ;
F_36 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
goto V_59;
F_37 ( & V_24 -> V_50 , V_1 ) ;
V_22 = V_44 -> V_22 ;
V_23 = V_44 -> V_23 ;
V_106 = F_9 ( F_56 ( V_1 , V_113 ) ) ?
V_1 -> log : NULL ;
V_110 = F_56 ( V_1 , V_114 ) ;
while ( ( V_112 = F_48 ( V_29 -> V_31 ) ) ) {
V_112 += V_23 ;
V_111 = V_112 + V_22 ;
V_100 = F_54 ( V_1 , V_1 -> V_47 , V_111 ,
& V_60 , V_106 , & log ,
F_51 ( V_110 ) ? V_18 : 1 ) ;
if ( F_9 ( V_100 < 0 ) )
break;
if ( F_9 ( V_100 > V_18 ) ) {
V_64 . V_82 = 1 ;
V_19 = V_29 -> V_87 -> V_115 ( NULL , V_29 , & V_64 ,
1 , V_72 | V_116 ) ;
F_45 ( L_9 , V_112 ) ;
continue;
}
if ( ! V_100 ) {
if ( F_9 ( F_40 ( & V_24 -> V_50 , V_1 ) ) ) {
F_37 ( & V_24 -> V_50 , V_1 ) ;
continue;
}
break;
}
if ( F_9 ( ( V_22 ) ) )
F_24 ( V_1 -> V_70 , V_44 -> V_81 , V_22 , V_60 ) ;
else
F_26 ( V_1 -> V_70 , V_44 -> V_81 , V_23 , V_60 ) ;
V_64 . V_82 = V_60 ;
V_19 = V_29 -> V_87 -> V_115 ( NULL , V_29 , & V_64 ,
V_112 , V_72 | V_116 ) ;
if ( F_9 ( V_19 != V_112 ) ) {
F_45 ( L_10
L_11 , V_19 , V_112 ) ;
F_44 ( V_1 , V_100 ) ;
continue;
}
if ( F_9 ( V_22 ) &&
F_57 ( V_44 -> V_81 , ( unsigned char * ) & V_81 , 0 ,
V_22 ) ) {
F_41 ( V_1 , L_12 ,
V_1 -> V_70 -> V_41 ) ;
break;
}
if ( F_51 ( V_110 ) &&
F_57 ( V_44 -> V_81 , ( unsigned char * ) & V_100 ,
F_58 ( F_59 ( V_81 ) , V_117 ) ,
sizeof V_81 . V_117 ) ) {
F_41 ( V_1 , L_13 ) ;
F_44 ( V_1 , V_100 ) ;
break;
}
F_30 ( & V_24 -> V_50 , V_1 , V_1 -> V_47 ,
V_100 ) ;
if ( F_9 ( V_106 ) )
F_60 ( V_1 , V_106 , log , V_111 ) ;
V_73 += V_111 ;
if ( F_9 ( V_73 >= V_89 ) ) {
F_33 ( & V_1 -> V_57 ) ;
break;
}
}
V_59:
F_47 ( & V_1 -> V_77 ) ;
}
static void F_61 ( struct V_118 * V_119 )
{
struct V_4 * V_1 = F_28 ( V_119 , struct V_4 ,
V_57 . V_119 ) ;
struct V_12 * V_24 = F_28 ( V_1 -> V_50 , struct V_12 , V_50 ) ;
F_35 ( V_24 ) ;
}
static void F_62 ( struct V_118 * V_119 )
{
struct V_4 * V_1 = F_28 ( V_119 , struct V_4 ,
V_57 . V_119 ) ;
struct V_12 * V_24 = F_28 ( V_1 -> V_50 , struct V_12 , V_50 ) ;
F_55 ( V_24 ) ;
}
static void F_63 ( struct V_118 * V_119 )
{
struct V_12 * V_24 = F_28 ( V_119 , struct V_12 ,
V_57 [ V_58 ] . V_119 ) ;
F_35 ( V_24 ) ;
}
static void F_64 ( struct V_118 * V_119 )
{
struct V_12 * V_24 = F_28 ( V_119 , struct V_12 ,
V_57 [ V_105 ] . V_119 ) ;
F_55 ( V_24 ) ;
}
static int F_65 ( struct V_120 * V_120 , struct V_121 * V_122 )
{
struct V_12 * V_13 ;
struct V_123 * V_50 ;
struct V_4 * * V_16 ;
int V_14 ;
V_13 = F_3 ( sizeof *V_13 , V_7 | V_124 | V_125 ) ;
if ( ! V_13 ) {
V_13 = F_66 ( sizeof *V_13 ) ;
if ( ! V_13 )
return - V_8 ;
}
V_16 = F_3 ( V_15 * sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 ) {
F_67 ( V_13 ) ;
return - V_8 ;
}
V_50 = & V_13 -> V_50 ;
V_16 [ V_58 ] = & V_13 -> V_16 [ V_58 ] . V_1 ;
V_16 [ V_105 ] = & V_13 -> V_16 [ V_105 ] . V_1 ;
V_13 -> V_16 [ V_58 ] . V_1 . V_126 = F_61 ;
V_13 -> V_16 [ V_105 ] . V_1 . V_126 = F_62 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_6 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
F_68 ( V_50 , V_16 , V_15 ) ;
F_69 ( V_13 -> V_57 + V_58 , F_63 , V_127 , V_50 ) ;
F_69 ( V_13 -> V_57 + V_105 , F_64 , V_128 , V_50 ) ;
V_122 -> V_78 = V_13 ;
return 0 ;
}
static void F_70 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_43 * V_44 =
F_28 ( V_1 , struct V_43 , V_1 ) ;
struct V_129 * V_57 = V_13 -> V_57 + ( V_44 - V_13 -> V_16 ) ;
if ( ! V_1 -> V_78 )
return;
F_71 ( V_57 ) ;
}
static int F_72 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_43 * V_44 =
F_28 ( V_1 , struct V_43 , V_1 ) ;
struct V_129 * V_57 = V_13 -> V_57 + ( V_44 - V_13 -> V_16 ) ;
struct V_28 * V_29 ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
return 0 ;
return F_73 ( V_57 , V_29 -> V_121 ) ;
}
static struct V_28 * F_74 ( struct V_12 * V_13 ,
struct V_4 * V_1 )
{
struct V_28 * V_29 ;
F_36 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
F_70 ( V_13 , V_1 ) ;
V_1 -> V_78 = NULL ;
F_47 ( & V_1 -> V_77 ) ;
return V_29 ;
}
static void F_75 ( struct V_12 * V_13 , struct V_28 * * V_130 ,
struct V_28 * * V_131 )
{
* V_130 = F_74 ( V_13 , & V_13 -> V_16 [ V_58 ] . V_1 ) ;
* V_131 = F_74 ( V_13 , & V_13 -> V_16 [ V_105 ] . V_1 ) ;
}
static void F_76 ( struct V_12 * V_13 , int V_132 )
{
F_77 ( V_13 -> V_57 + V_132 ) ;
F_77 ( & V_13 -> V_16 [ V_132 ] . V_1 . V_57 ) ;
}
static void F_78 ( struct V_12 * V_13 )
{
F_76 ( V_13 , V_58 ) ;
F_76 ( V_13 , V_105 ) ;
if ( V_13 -> V_16 [ V_58 ] . V_6 ) {
F_36 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
V_13 -> V_27 = true ;
F_47 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
F_11 ( V_13 -> V_16 [ V_58 ] . V_6 ) ;
F_36 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
V_13 -> V_27 = false ;
F_5 ( & V_13 -> V_16 [ V_58 ] . V_6 -> V_9 , 1 ) ;
F_47 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
}
}
static int F_79 ( struct V_120 * V_120 , struct V_121 * V_122 )
{
struct V_12 * V_13 = V_122 -> V_78 ;
struct V_28 * V_130 ;
struct V_28 * V_131 ;
F_75 ( V_13 , & V_130 , & V_131 ) ;
F_78 ( V_13 ) ;
F_80 ( & V_13 -> V_50 ) ;
F_81 ( & V_13 -> V_50 , false ) ;
F_18 ( V_13 ) ;
if ( V_130 )
F_82 ( V_130 ) ;
if ( V_131 )
F_82 ( V_131 ) ;
F_83 () ;
F_78 ( V_13 ) ;
F_15 ( V_13 -> V_50 . V_16 ) ;
F_67 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_84 ( int V_133 )
{
struct {
struct V_134 V_135 ;
char V_136 [ V_137 ] ;
} V_138 ;
int V_139 = sizeof V_138 , V_11 ;
struct V_28 * V_29 = F_85 ( V_133 , & V_11 ) ;
if ( ! V_29 )
return F_4 ( - V_140 ) ;
if ( V_29 -> V_31 -> V_141 != V_142 ) {
V_11 = - V_143 ;
goto V_19;
}
V_11 = V_29 -> V_87 -> V_144 ( V_29 , (struct V_145 * ) & V_138 . V_135 ,
& V_139 , 0 ) ;
if ( V_11 )
goto V_19;
if ( V_138 . V_135 . V_146 != V_147 ) {
V_11 = - V_148 ;
goto V_19;
}
return V_29 ;
V_19:
F_82 ( V_29 ) ;
return F_4 ( V_11 ) ;
}
static struct V_28 * F_86 ( int V_133 )
{
struct V_121 * V_121 = F_87 ( V_133 ) ;
struct V_28 * V_29 ;
if ( ! V_121 )
return F_4 ( - V_149 ) ;
V_29 = F_88 ( V_121 ) ;
if ( ! F_89 ( V_29 ) )
return V_29 ;
V_29 = F_90 ( V_121 ) ;
if ( F_89 ( V_29 ) )
F_91 ( V_121 ) ;
return V_29 ;
}
static struct V_28 * F_92 ( int V_133 )
{
struct V_28 * V_29 ;
if ( V_133 == - 1 )
return NULL ;
V_29 = F_84 ( V_133 ) ;
if ( ! F_89 ( V_29 ) )
return V_29 ;
V_29 = F_86 ( V_133 ) ;
if ( ! F_89 ( V_29 ) )
return V_29 ;
return F_4 ( - V_140 ) ;
}
static long F_93 ( struct V_12 * V_13 , unsigned V_132 , int V_133 )
{
struct V_28 * V_29 , * V_150 ;
struct V_4 * V_1 ;
struct V_43 * V_44 ;
struct V_3 * V_6 , * V_151 = NULL ;
int V_11 ;
F_36 ( & V_13 -> V_50 . V_77 ) ;
V_11 = F_94 ( & V_13 -> V_50 ) ;
if ( V_11 )
goto V_19;
if ( V_132 >= V_15 ) {
V_11 = - V_103 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_132 ] . V_1 ;
V_44 = & V_13 -> V_16 [ V_132 ] ;
F_36 ( & V_1 -> V_77 ) ;
if ( ! F_95 ( V_1 ) ) {
V_11 = - V_152 ;
goto V_153;
}
V_29 = F_92 ( V_133 ) ;
if ( F_89 ( V_29 ) ) {
V_11 = F_96 ( V_29 ) ;
goto V_153;
}
V_150 = V_1 -> V_78 ;
if ( V_29 != V_150 ) {
V_6 = F_2 ( V_1 ,
V_29 && F_22 ( V_29 ) ) ;
if ( F_89 ( V_6 ) ) {
V_11 = F_96 ( V_6 ) ;
goto V_154;
}
F_70 ( V_13 , V_1 ) ;
V_1 -> V_78 = V_29 ;
V_11 = F_97 ( V_1 ) ;
if ( V_11 )
goto V_155;
V_11 = F_72 ( V_13 , V_1 ) ;
if ( V_11 )
goto V_155;
V_151 = V_44 -> V_6 ;
V_44 -> V_6 = V_6 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
V_13 -> V_27 = false ;
}
F_47 ( & V_1 -> V_77 ) ;
if ( V_151 ) {
F_14 ( V_151 ) ;
F_36 ( & V_1 -> V_77 ) ;
F_27 ( V_13 , V_1 ) ;
F_47 ( & V_1 -> V_77 ) ;
}
if ( V_150 ) {
F_76 ( V_13 , V_132 ) ;
F_82 ( V_150 ) ;
}
F_47 ( & V_13 -> V_50 . V_77 ) ;
return 0 ;
V_155:
V_1 -> V_78 = V_150 ;
F_72 ( V_13 , V_1 ) ;
if ( V_6 )
F_14 ( V_6 ) ;
V_154:
F_82 ( V_29 ) ;
V_153:
F_47 ( & V_1 -> V_77 ) ;
V_19:
F_47 ( & V_13 -> V_50 . V_77 ) ;
return V_11 ;
}
static long F_98 ( struct V_12 * V_13 )
{
struct V_28 * V_130 = NULL ;
struct V_28 * V_131 = NULL ;
long V_19 ;
struct V_156 * V_157 ;
F_36 ( & V_13 -> V_50 . V_77 ) ;
V_19 = F_94 ( & V_13 -> V_50 ) ;
if ( V_19 )
goto V_158;
V_157 = F_99 () ;
if ( ! V_157 ) {
V_19 = - V_8 ;
goto V_158;
}
F_75 ( V_13 , & V_130 , & V_131 ) ;
F_78 ( V_13 ) ;
F_100 ( & V_13 -> V_50 , V_157 ) ;
F_18 ( V_13 ) ;
V_158:
F_47 ( & V_13 -> V_50 . V_77 ) ;
if ( V_130 )
F_82 ( V_130 ) ;
if ( V_131 )
F_82 ( V_131 ) ;
return V_19 ;
}
static int F_101 ( struct V_12 * V_13 , T_3 V_159 )
{
T_1 V_22 , V_23 , V_160 ;
int V_14 ;
V_160 = ( V_159 & ( 1 << V_114 ) ) ?
sizeof( struct V_107 ) :
sizeof( struct V_161 ) ;
if ( V_159 & ( 1 << V_162 ) ) {
V_22 = V_160 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_160 ;
}
F_36 ( & V_13 -> V_50 . V_77 ) ;
if ( ( V_159 & ( 1 << V_113 ) ) &&
! F_102 ( & V_13 -> V_50 ) ) {
F_47 ( & V_13 -> V_50 . V_77 ) ;
return - V_152 ;
}
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_36 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_77 ) ;
V_13 -> V_16 [ V_14 ] . V_1 . V_163 = V_159 ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_47 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_77 ) ;
}
F_47 ( & V_13 -> V_50 . V_77 ) ;
return 0 ;
}
static long F_103 ( struct V_12 * V_13 )
{
int V_11 ;
F_36 ( & V_13 -> V_50 . V_77 ) ;
if ( F_104 ( & V_13 -> V_50 ) ) {
V_11 = - V_164 ;
goto V_59;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 )
goto V_59;
V_11 = F_105 ( & V_13 -> V_50 ) ;
if ( V_11 )
F_16 ( V_13 ) ;
F_78 ( V_13 ) ;
V_59:
F_47 ( & V_13 -> V_50 . V_77 ) ;
return V_11 ;
}
static long F_106 ( struct V_121 * V_122 , unsigned int V_165 ,
unsigned long V_166 )
{
struct V_12 * V_13 = V_122 -> V_78 ;
void T_4 * V_167 = ( void T_4 * ) V_166 ;
T_3 T_4 * V_168 = V_167 ;
struct V_169 V_170 ;
T_3 V_159 ;
int V_11 ;
switch ( V_165 ) {
case V_171 :
if ( F_107 ( & V_170 , V_167 , sizeof V_170 ) )
return - V_152 ;
return F_93 ( V_13 , V_170 . V_132 , V_170 . V_133 ) ;
case V_172 :
V_159 = V_173 ;
if ( F_108 ( V_168 , & V_159 , sizeof V_159 ) )
return - V_152 ;
return 0 ;
case V_174 :
if ( F_107 ( & V_159 , V_168 , sizeof V_159 ) )
return - V_152 ;
if ( V_159 & ~ V_173 )
return - V_175 ;
return F_101 ( V_13 , V_159 ) ;
case V_176 :
return F_98 ( V_13 ) ;
case V_177 :
return F_103 ( V_13 ) ;
default:
F_36 ( & V_13 -> V_50 . V_77 ) ;
V_11 = F_109 ( & V_13 -> V_50 , V_165 , V_167 ) ;
if ( V_11 == - V_178 )
V_11 = F_110 ( & V_13 -> V_50 , V_165 , V_167 ) ;
else
F_78 ( V_13 ) ;
F_47 ( & V_13 -> V_50 . V_77 ) ;
return V_11 ;
}
}
static long F_111 ( struct V_121 * V_122 , unsigned int V_165 ,
unsigned long V_166 )
{
return F_106 ( V_122 , V_165 , ( unsigned long ) F_112 ( V_166 ) ) ;
}
static int F_113 ( void )
{
if ( V_30 )
F_1 ( V_58 ) ;
return F_114 ( & V_179 ) ;
}
static void F_115 ( void )
{
F_116 ( & V_179 ) ;
}
