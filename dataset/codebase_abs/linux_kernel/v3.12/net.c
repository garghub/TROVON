static void F_1 ( int V_1 )
{
V_2 |= 0x1 << V_1 ;
}
static void F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_3 ( V_3 , struct V_4 , V_3 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
static struct V_4 *
F_5 ( struct V_7 * V_1 , bool V_8 )
{
struct V_4 * V_5 ;
if ( ! V_8 )
return NULL ;
V_5 = F_6 ( sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
return F_7 ( - V_10 ) ;
F_8 ( & V_5 -> V_3 ) ;
F_9 ( & V_5 -> V_6 ) ;
V_5 -> V_1 = V_1 ;
return V_5 ;
}
static void F_10 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_3 , F_2 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_3 , F_2 ) ;
F_13 ( V_5 -> V_6 , ! F_14 ( & V_5 -> V_3 . V_11 ) ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_12 ( V_5 ) ;
F_16 ( V_5 ) ;
}
static void F_17 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_16 ( V_13 -> V_16 [ V_14 ] . V_17 ) ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
}
}
static int F_18 ( struct V_12 * V_13 )
{
bool V_8 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
V_8 = V_2 & ( 0x1 << V_14 ) ;
if ( ! V_8 )
continue;
V_13 -> V_16 [ V_14 ] . V_17 = F_6 ( sizeof( * V_13 -> V_16 [ V_14 ] . V_17 ) *
V_18 , V_9 ) ;
if ( ! V_13 -> V_16 [ V_14 ] . V_17 )
goto V_19;
}
return 0 ;
V_19:
F_17 ( V_13 ) ;
return - V_10 ;
}
static void F_19 ( struct V_12 * V_13 )
{
int V_14 ;
F_17 ( V_13 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_5 = NULL ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
}
static void F_20 ( struct V_12 * V_24 )
{
++ V_24 -> V_25 ;
if ( V_24 -> V_25 < 1024 )
return;
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
}
static void F_21 ( struct V_12 * V_24 )
{
++ V_24 -> V_26 ;
}
static bool F_22 ( struct V_12 * V_24 )
{
return ! V_24 -> V_27 &&
V_24 -> V_25 / 64 >= V_24 -> V_26 ;
}
static bool F_23 ( struct V_28 * V_29 )
{
return F_24 ( V_30 ) &&
F_25 ( V_29 -> V_31 , V_32 ) ;
}
static int F_26 ( struct V_33 * V_34 , struct V_33 * V_35 ,
T_1 V_36 , int V_37 )
{
int V_38 = 0 ;
T_1 V_39 ;
while ( V_36 && V_38 < V_37 ) {
V_39 = F_27 ( V_34 -> V_40 , V_36 ) ;
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
static void F_28 ( const struct V_33 * V_34 , struct V_33 * V_35 ,
T_1 V_36 , int V_42 )
{
int V_38 = 0 ;
T_1 V_39 ;
while ( V_36 && V_38 < V_42 ) {
V_39 = F_27 ( V_34 -> V_40 , V_36 ) ;
V_35 -> V_41 = V_34 -> V_41 ;
V_35 -> V_40 = V_39 ;
V_36 -= V_39 ;
++ V_34 ;
++ V_35 ;
++ V_38 ;
}
}
static void F_29 ( struct V_12 * V_24 ,
struct V_7 * V_1 )
{
struct V_43 * V_44 =
F_3 ( V_1 , struct V_43 , V_1 ) ;
int V_14 , V_45 ;
int V_46 = 0 ;
for ( V_14 = V_44 -> V_20 ; V_14 != V_44 -> V_21 ; V_14 = ( V_14 + 1 ) % V_18 ) {
if ( V_1 -> V_47 [ V_14 ] . V_36 == V_48 )
F_21 ( V_24 ) ;
if ( F_30 ( V_1 -> V_47 [ V_14 ] . V_36 ) ) {
V_1 -> V_47 [ V_14 ] . V_36 = V_49 ;
++ V_46 ;
} else
break;
}
while ( V_46 ) {
V_45 = F_27 ( V_18 - V_44 -> V_20 , V_46 ) ;
F_31 ( V_1 -> V_50 , V_1 ,
& V_1 -> V_47 [ V_44 -> V_20 ] , V_45 ) ;
V_44 -> V_20 = ( V_44 -> V_20 + V_45 ) % V_18 ;
V_46 -= V_45 ;
}
}
static void F_32 ( struct V_17 * V_51 , bool V_52 )
{
struct V_4 * V_5 = V_51 -> V_53 ;
struct V_7 * V_1 = V_5 -> V_1 ;
int V_54 = F_14 ( & V_5 -> V_3 . V_11 ) ;
V_1 -> V_47 [ V_51 -> V_55 ] . V_36 = V_52 ?
V_56 : V_48 ;
F_10 ( V_5 ) ;
if ( V_54 <= 2 || ! ( V_54 % 16 ) )
F_33 ( & V_1 -> V_57 ) ;
}
static void F_34 ( struct V_12 * V_24 )
{
struct V_43 * V_44 = & V_24 -> V_16 [ V_58 ] ;
struct V_7 * V_1 = & V_44 -> V_1 ;
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
struct V_4 * V_75 ( V_5 ) ;
bool V_8 , V_76 ;
F_35 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
goto V_59;
F_36 ( & V_24 -> V_50 , V_1 ) ;
V_74 = V_44 -> V_22 ;
V_8 = V_44 -> V_5 ;
for (; ; ) {
if ( V_8 )
F_29 ( V_24 , V_1 ) ;
if ( F_24 ( ( V_44 -> V_21 + V_1 -> V_79 - V_80 )
% V_18 == V_44 -> V_20 ) )
break;
V_62 = F_37 ( & V_24 -> V_50 , V_1 , V_1 -> V_70 ,
F_38 ( V_1 -> V_70 ) ,
& V_59 , & V_60 ,
NULL , NULL ) ;
if ( F_24 ( V_62 < 0 ) )
break;
if ( V_62 == V_1 -> V_79 ) {
if ( F_24 ( F_39 ( & V_24 -> V_50 , V_1 ) ) ) {
F_36 ( & V_24 -> V_50 , V_1 ) ;
continue;
}
break;
}
if ( V_60 ) {
F_40 ( V_1 , L_1
L_2 , V_59 , V_60 ) ;
break;
}
V_61 = F_26 ( V_1 -> V_70 , V_44 -> V_81 , V_74 , V_59 ) ;
V_64 . V_82 = V_59 ;
V_36 = F_41 ( V_1 -> V_70 , V_59 ) ;
if ( ! V_36 ) {
F_40 ( V_1 , L_3
L_4 ,
F_41 ( V_44 -> V_81 , V_61 ) , V_74 ) ;
break;
}
V_76 = V_8 && V_36 >= V_83
&& ( V_44 -> V_21 + 1 ) % V_18 !=
V_44 -> V_20
&& F_22 ( V_24 ) ;
if ( V_76 ) {
struct V_17 * V_51 ;
V_51 = V_44 -> V_17 + V_44 -> V_21 ;
V_1 -> V_47 [ V_44 -> V_21 ] . V_84 = V_62 ;
V_1 -> V_47 [ V_44 -> V_21 ] . V_36 = V_85 ;
V_51 -> V_86 = F_32 ;
V_51 -> V_53 = V_44 -> V_5 ;
V_51 -> V_55 = V_44 -> V_21 ;
V_64 . V_67 = V_51 ;
V_64 . V_68 = sizeof( V_51 ) ;
V_5 = V_44 -> V_5 ;
F_42 ( & V_5 -> V_3 ) ;
V_44 -> V_21 = ( V_44 -> V_21 + 1 ) % V_18 ;
} else {
V_64 . V_67 = NULL ;
V_5 = NULL ;
}
V_19 = V_29 -> V_87 -> V_88 ( NULL , V_29 , & V_64 , V_36 ) ;
if ( F_24 ( V_19 < 0 ) ) {
if ( V_76 ) {
F_10 ( V_5 ) ;
V_44 -> V_21 = ( ( unsigned ) V_44 -> V_21 - 1 )
% V_18 ;
}
F_43 ( V_1 , 1 ) ;
break;
}
if ( V_19 != V_36 )
F_44 ( L_5
L_6 , V_19 , V_36 ) ;
if ( ! V_76 )
F_45 ( & V_24 -> V_50 , V_1 , V_62 , 0 ) ;
else
F_29 ( V_24 , V_1 ) ;
V_73 += V_36 ;
F_20 ( V_24 ) ;
if ( F_24 ( V_73 >= V_89 ) ) {
F_33 ( & V_1 -> V_57 ) ;
break;
}
}
V_59:
F_46 ( & V_1 -> V_77 ) ;
}
static int F_47 ( struct V_29 * V_31 )
{
struct V_90 * V_62 ;
int V_36 = 0 ;
unsigned long V_91 ;
F_48 ( & V_31 -> V_92 . V_93 , V_91 ) ;
V_62 = F_49 ( & V_31 -> V_92 ) ;
if ( F_50 ( V_62 ) ) {
V_36 = V_62 -> V_36 ;
if ( F_51 ( V_62 ) )
V_36 += V_94 ;
}
F_52 ( & V_31 -> V_92 . V_93 , V_91 ) ;
return V_36 ;
}
static int F_53 ( struct V_7 * V_1 ,
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
int V_102 , V_103 = 0 ;
while ( V_96 > 0 && V_100 < V_99 ) {
if ( F_24 ( V_38 >= V_18 ) ) {
V_102 = - V_104 ;
goto V_19;
}
V_101 = F_37 ( V_1 -> V_50 , V_1 , V_1 -> V_70 + V_38 ,
F_38 ( V_1 -> V_70 ) - V_38 , & V_59 ,
& V_60 , log , V_98 ) ;
if ( V_101 == V_1 -> V_79 ) {
V_102 = 0 ;
goto V_19;
}
if ( F_24 ( V_59 || V_60 <= 0 ) ) {
F_40 ( V_1 , L_7
L_8 , V_59 , V_60 ) ;
V_102 = - V_105 ;
goto V_19;
}
if ( F_24 ( log ) ) {
V_103 += * V_98 ;
log += * V_98 ;
}
V_47 [ V_100 ] . V_84 = V_101 ;
V_47 [ V_100 ] . V_36 = F_41 ( V_1 -> V_70 + V_38 , V_60 ) ;
V_96 -= V_47 [ V_100 ] . V_36 ;
++ V_100 ;
V_38 += V_60 ;
}
V_47 [ V_100 - 1 ] . V_36 += V_96 ;
* V_42 = V_38 ;
if ( F_24 ( log ) )
* V_98 = V_103 ;
return V_100 ;
V_19:
F_43 ( V_1 , V_100 ) ;
return V_102 ;
}
static void F_54 ( struct V_12 * V_24 )
{
struct V_43 * V_44 = & V_24 -> V_16 [ V_106 ] ;
struct V_7 * V_1 = & V_44 -> V_1 ;
unsigned V_75 ( V_60 ) , log ;
struct V_97 * V_107 ;
struct V_63 V_64 = {
. V_65 = NULL ,
. V_66 = 0 ,
. V_67 = NULL ,
. V_68 = 0 ,
. V_69 = V_1 -> V_70 ,
. V_71 = V_72 ,
} ;
struct V_108 V_81 = {
. V_81 . V_91 = 0 ,
. V_81 . V_109 = V_110
} ;
T_1 V_73 = 0 ;
int V_19 , V_111 ;
T_2 V_100 ;
T_1 V_22 , V_23 ;
T_1 V_112 , V_113 ;
struct V_28 * V_29 ;
F_35 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
goto V_59;
F_36 ( & V_24 -> V_50 , V_1 ) ;
V_22 = V_44 -> V_22 ;
V_23 = V_44 -> V_23 ;
V_107 = F_24 ( F_55 ( & V_24 -> V_50 , V_114 ) ) ?
V_1 -> log : NULL ;
V_111 = F_55 ( & V_24 -> V_50 , V_115 ) ;
while ( ( V_113 = F_47 ( V_29 -> V_31 ) ) ) {
V_113 += V_23 ;
V_112 = V_113 + V_22 ;
V_100 = F_53 ( V_1 , V_1 -> V_47 , V_112 ,
& V_60 , V_107 , & log ,
F_50 ( V_111 ) ? V_18 : 1 ) ;
if ( F_24 ( V_100 < 0 ) )
break;
if ( ! V_100 ) {
if ( F_24 ( F_39 ( & V_24 -> V_50 , V_1 ) ) ) {
F_36 ( & V_24 -> V_50 , V_1 ) ;
continue;
}
break;
}
if ( F_24 ( ( V_22 ) ) )
F_26 ( V_1 -> V_70 , V_44 -> V_81 , V_22 , V_60 ) ;
else
F_28 ( V_1 -> V_70 , V_44 -> V_81 , V_23 , V_60 ) ;
V_64 . V_82 = V_60 ;
V_19 = V_29 -> V_87 -> V_116 ( NULL , V_29 , & V_64 ,
V_113 , V_72 | V_117 ) ;
if ( F_24 ( V_19 != V_113 ) ) {
F_44 ( L_9
L_10 , V_19 , V_113 ) ;
F_43 ( V_1 , V_100 ) ;
continue;
}
if ( F_24 ( V_22 ) &&
F_56 ( V_44 -> V_81 , ( unsigned char * ) & V_81 , 0 ,
V_22 ) ) {
F_40 ( V_1 , L_11 ,
V_1 -> V_70 -> V_41 ) ;
break;
}
if ( F_50 ( V_111 ) &&
F_56 ( V_44 -> V_81 , ( unsigned char * ) & V_100 ,
F_57 ( F_58 ( V_81 ) , V_118 ) ,
sizeof V_81 . V_118 ) ) {
F_40 ( V_1 , L_12 ) ;
F_43 ( V_1 , V_100 ) ;
break;
}
F_31 ( & V_24 -> V_50 , V_1 , V_1 -> V_47 ,
V_100 ) ;
if ( F_24 ( V_107 ) )
F_59 ( V_1 , V_107 , log , V_112 ) ;
V_73 += V_112 ;
if ( F_24 ( V_73 >= V_89 ) ) {
F_33 ( & V_1 -> V_57 ) ;
break;
}
}
V_59:
F_46 ( & V_1 -> V_77 ) ;
}
static void F_60 ( struct V_119 * V_120 )
{
struct V_7 * V_1 = F_3 ( V_120 , struct V_7 ,
V_57 . V_120 ) ;
struct V_12 * V_24 = F_3 ( V_1 -> V_50 , struct V_12 , V_50 ) ;
F_34 ( V_24 ) ;
}
static void F_61 ( struct V_119 * V_120 )
{
struct V_7 * V_1 = F_3 ( V_120 , struct V_7 ,
V_57 . V_120 ) ;
struct V_12 * V_24 = F_3 ( V_1 -> V_50 , struct V_12 , V_50 ) ;
F_54 ( V_24 ) ;
}
static void F_62 ( struct V_119 * V_120 )
{
struct V_12 * V_24 = F_3 ( V_120 , struct V_12 ,
V_57 [ V_58 ] . V_120 ) ;
F_34 ( V_24 ) ;
}
static void F_63 ( struct V_119 * V_120 )
{
struct V_12 * V_24 = F_3 ( V_120 , struct V_12 ,
V_57 [ V_106 ] . V_120 ) ;
F_54 ( V_24 ) ;
}
static int F_64 ( struct V_121 * V_121 , struct V_122 * V_123 )
{
struct V_12 * V_13 = F_6 ( sizeof *V_13 , V_9 ) ;
struct V_124 * V_50 ;
struct V_7 * * V_16 ;
int V_102 , V_14 ;
if ( ! V_13 )
return - V_10 ;
V_16 = F_6 ( V_15 * sizeof( * V_16 ) , V_9 ) ;
if ( ! V_16 ) {
F_16 ( V_13 ) ;
return - V_10 ;
}
V_50 = & V_13 -> V_50 ;
V_16 [ V_58 ] = & V_13 -> V_16 [ V_58 ] . V_1 ;
V_16 [ V_106 ] = & V_13 -> V_16 [ V_106 ] . V_1 ;
V_13 -> V_16 [ V_58 ] . V_1 . V_125 = F_60 ;
V_13 -> V_16 [ V_106 ] . V_1 . V_125 = F_61 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 -> V_16 [ V_14 ] . V_5 = NULL ;
V_13 -> V_16 [ V_14 ] . V_17 = NULL ;
V_13 -> V_16 [ V_14 ] . V_21 = 0 ;
V_13 -> V_16 [ V_14 ] . V_20 = 0 ;
V_13 -> V_16 [ V_14 ] . V_22 = 0 ;
V_13 -> V_16 [ V_14 ] . V_23 = 0 ;
}
V_102 = F_65 ( V_50 , V_16 , V_15 ) ;
if ( V_102 < 0 ) {
F_16 ( V_13 ) ;
F_16 ( V_16 ) ;
return V_102 ;
}
F_66 ( V_13 -> V_57 + V_58 , F_62 , V_126 , V_50 ) ;
F_66 ( V_13 -> V_57 + V_106 , F_63 , V_127 , V_50 ) ;
V_123 -> V_78 = V_13 ;
return 0 ;
}
static void F_67 ( struct V_12 * V_13 ,
struct V_7 * V_1 )
{
struct V_43 * V_44 =
F_3 ( V_1 , struct V_43 , V_1 ) ;
struct V_128 * V_57 = V_13 -> V_57 + ( V_44 - V_13 -> V_16 ) ;
if ( ! V_1 -> V_78 )
return;
F_68 ( V_57 ) ;
}
static int F_69 ( struct V_12 * V_13 ,
struct V_7 * V_1 )
{
struct V_43 * V_44 =
F_3 ( V_1 , struct V_43 , V_1 ) ;
struct V_128 * V_57 = V_13 -> V_57 + ( V_44 - V_13 -> V_16 ) ;
struct V_28 * V_29 ;
V_29 = V_1 -> V_78 ;
if ( ! V_29 )
return 0 ;
return F_70 ( V_57 , V_29 -> V_122 ) ;
}
static struct V_28 * F_71 ( struct V_12 * V_13 ,
struct V_7 * V_1 )
{
struct V_28 * V_29 ;
F_35 ( & V_1 -> V_77 ) ;
V_29 = V_1 -> V_78 ;
F_67 ( V_13 , V_1 ) ;
V_1 -> V_78 = NULL ;
F_46 ( & V_1 -> V_77 ) ;
return V_29 ;
}
static void F_72 ( struct V_12 * V_13 , struct V_28 * * V_129 ,
struct V_28 * * V_130 )
{
* V_129 = F_71 ( V_13 , & V_13 -> V_16 [ V_58 ] . V_1 ) ;
* V_130 = F_71 ( V_13 , & V_13 -> V_16 [ V_106 ] . V_1 ) ;
}
static void F_73 ( struct V_12 * V_13 , int V_131 )
{
F_74 ( V_13 -> V_57 + V_131 ) ;
F_74 ( & V_13 -> V_16 [ V_131 ] . V_1 . V_57 ) ;
}
static void F_75 ( struct V_12 * V_13 )
{
F_73 ( V_13 , V_58 ) ;
F_73 ( V_13 , V_106 ) ;
if ( V_13 -> V_16 [ V_58 ] . V_5 ) {
F_35 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
V_13 -> V_27 = true ;
F_46 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
F_12 ( V_13 -> V_16 [ V_58 ] . V_5 ) ;
F_35 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
V_13 -> V_27 = false ;
F_8 ( & V_13 -> V_16 [ V_58 ] . V_5 -> V_3 ) ;
F_46 ( & V_13 -> V_16 [ V_58 ] . V_1 . V_77 ) ;
}
}
static int F_76 ( struct V_121 * V_121 , struct V_122 * V_123 )
{
struct V_12 * V_13 = V_123 -> V_78 ;
struct V_28 * V_129 ;
struct V_28 * V_130 ;
F_72 ( V_13 , & V_129 , & V_130 ) ;
F_75 ( V_13 ) ;
F_77 ( & V_13 -> V_50 ) ;
F_78 ( & V_13 -> V_50 , false ) ;
F_19 ( V_13 ) ;
if ( V_129 )
F_79 ( V_129 -> V_122 ) ;
if ( V_130 )
F_79 ( V_130 -> V_122 ) ;
F_75 ( V_13 ) ;
F_16 ( V_13 -> V_50 . V_16 ) ;
F_16 ( V_13 ) ;
return 0 ;
}
static struct V_28 * F_80 ( int V_132 )
{
struct {
struct V_133 V_134 ;
char V_135 [ V_136 ] ;
} V_137 ;
int V_138 = sizeof V_137 , V_102 ;
struct V_28 * V_29 = F_81 ( V_132 , & V_102 ) ;
if ( ! V_29 )
return F_7 ( - V_139 ) ;
if ( V_29 -> V_31 -> V_140 != V_141 ) {
V_102 = - V_142 ;
goto V_19;
}
V_102 = V_29 -> V_87 -> V_143 ( V_29 , (struct V_144 * ) & V_137 . V_134 ,
& V_138 , 0 ) ;
if ( V_102 )
goto V_19;
if ( V_137 . V_134 . V_145 != V_146 ) {
V_102 = - V_147 ;
goto V_19;
}
return V_29 ;
V_19:
F_79 ( V_29 -> V_122 ) ;
return F_7 ( V_102 ) ;
}
static struct V_28 * F_82 ( int V_132 )
{
struct V_122 * V_122 = F_83 ( V_132 ) ;
struct V_28 * V_29 ;
if ( ! V_122 )
return F_7 ( - V_148 ) ;
V_29 = F_84 ( V_122 ) ;
if ( ! F_85 ( V_29 ) )
return V_29 ;
V_29 = F_86 ( V_122 ) ;
if ( F_85 ( V_29 ) )
F_79 ( V_122 ) ;
return V_29 ;
}
static struct V_28 * F_87 ( int V_132 )
{
struct V_28 * V_29 ;
if ( V_132 == - 1 )
return NULL ;
V_29 = F_80 ( V_132 ) ;
if ( ! F_85 ( V_29 ) )
return V_29 ;
V_29 = F_82 ( V_132 ) ;
if ( ! F_85 ( V_29 ) )
return V_29 ;
return F_7 ( - V_139 ) ;
}
static long F_88 ( struct V_12 * V_13 , unsigned V_131 , int V_132 )
{
struct V_28 * V_29 , * V_149 ;
struct V_7 * V_1 ;
struct V_43 * V_44 ;
struct V_4 * V_5 , * V_150 = NULL ;
int V_102 ;
F_35 ( & V_13 -> V_50 . V_77 ) ;
V_102 = F_89 ( & V_13 -> V_50 ) ;
if ( V_102 )
goto V_19;
if ( V_131 >= V_15 ) {
V_102 = - V_104 ;
goto V_19;
}
V_1 = & V_13 -> V_16 [ V_131 ] . V_1 ;
V_44 = & V_13 -> V_16 [ V_131 ] ;
F_35 ( & V_1 -> V_77 ) ;
if ( ! F_90 ( V_1 ) ) {
V_102 = - V_151 ;
goto V_152;
}
V_29 = F_87 ( V_132 ) ;
if ( F_85 ( V_29 ) ) {
V_102 = F_91 ( V_29 ) ;
goto V_152;
}
V_149 = V_1 -> V_78 ;
if ( V_29 != V_149 ) {
V_5 = F_5 ( V_1 ,
V_29 && F_23 ( V_29 ) ) ;
if ( F_85 ( V_5 ) ) {
V_102 = F_91 ( V_5 ) ;
goto V_153;
}
F_67 ( V_13 , V_1 ) ;
V_1 -> V_78 = V_29 ;
V_102 = F_92 ( V_1 ) ;
if ( V_102 )
goto V_154;
V_102 = F_69 ( V_13 , V_1 ) ;
if ( V_102 )
goto V_154;
V_150 = V_44 -> V_5 ;
V_44 -> V_5 = V_5 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
V_13 -> V_27 = false ;
}
F_46 ( & V_1 -> V_77 ) ;
if ( V_150 ) {
F_15 ( V_150 ) ;
F_35 ( & V_1 -> V_77 ) ;
F_29 ( V_13 , V_1 ) ;
F_46 ( & V_1 -> V_77 ) ;
}
if ( V_149 ) {
F_73 ( V_13 , V_131 ) ;
F_79 ( V_149 -> V_122 ) ;
}
F_46 ( & V_13 -> V_50 . V_77 ) ;
return 0 ;
V_154:
V_1 -> V_78 = V_149 ;
F_69 ( V_13 , V_1 ) ;
if ( V_5 )
F_15 ( V_5 ) ;
V_153:
F_79 ( V_29 -> V_122 ) ;
V_152:
F_46 ( & V_1 -> V_77 ) ;
V_19:
F_46 ( & V_13 -> V_50 . V_77 ) ;
return V_102 ;
}
static long F_93 ( struct V_12 * V_13 )
{
struct V_28 * V_129 = NULL ;
struct V_28 * V_130 = NULL ;
long V_19 ;
struct V_155 * V_156 ;
F_35 ( & V_13 -> V_50 . V_77 ) ;
V_19 = F_89 ( & V_13 -> V_50 ) ;
if ( V_19 )
goto V_157;
V_156 = F_94 () ;
if ( ! V_156 ) {
V_19 = - V_10 ;
goto V_157;
}
F_72 ( V_13 , & V_129 , & V_130 ) ;
F_75 ( V_13 ) ;
F_95 ( & V_13 -> V_50 , V_156 ) ;
F_19 ( V_13 ) ;
V_157:
F_46 ( & V_13 -> V_50 . V_77 ) ;
if ( V_129 )
F_79 ( V_129 -> V_122 ) ;
if ( V_130 )
F_79 ( V_130 -> V_122 ) ;
return V_19 ;
}
static int F_96 ( struct V_12 * V_13 , T_3 V_158 )
{
T_1 V_22 , V_23 , V_159 ;
int V_14 ;
V_159 = ( V_158 & ( 1 << V_115 ) ) ?
sizeof( struct V_108 ) :
sizeof( struct V_160 ) ;
if ( V_158 & ( 1 << V_161 ) ) {
V_22 = V_159 ;
V_23 = 0 ;
} else {
V_22 = 0 ;
V_23 = V_159 ;
}
F_35 ( & V_13 -> V_50 . V_77 ) ;
if ( ( V_158 & ( 1 << V_114 ) ) &&
! F_97 ( & V_13 -> V_50 ) ) {
F_46 ( & V_13 -> V_50 . V_77 ) ;
return - V_151 ;
}
V_13 -> V_50 . V_162 = V_158 ;
F_98 () ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
F_35 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_77 ) ;
V_13 -> V_16 [ V_14 ] . V_22 = V_22 ;
V_13 -> V_16 [ V_14 ] . V_23 = V_23 ;
F_46 ( & V_13 -> V_16 [ V_14 ] . V_1 . V_77 ) ;
}
F_75 ( V_13 ) ;
F_46 ( & V_13 -> V_50 . V_77 ) ;
return 0 ;
}
static long F_99 ( struct V_12 * V_13 )
{
int V_102 ;
F_35 ( & V_13 -> V_50 . V_77 ) ;
if ( F_100 ( & V_13 -> V_50 ) ) {
V_102 = - V_163 ;
goto V_59;
}
V_102 = F_18 ( V_13 ) ;
if ( V_102 )
goto V_59;
V_102 = F_101 ( & V_13 -> V_50 ) ;
if ( V_102 )
F_17 ( V_13 ) ;
F_75 ( V_13 ) ;
V_59:
F_46 ( & V_13 -> V_50 . V_77 ) ;
return V_102 ;
}
static long F_102 ( struct V_122 * V_123 , unsigned int V_164 ,
unsigned long V_165 )
{
struct V_12 * V_13 = V_123 -> V_78 ;
void T_4 * V_166 = ( void T_4 * ) V_165 ;
T_3 T_4 * V_167 = V_166 ;
struct V_168 V_169 ;
T_3 V_158 ;
int V_102 ;
switch ( V_164 ) {
case V_170 :
if ( F_103 ( & V_169 , V_166 , sizeof V_169 ) )
return - V_151 ;
return F_88 ( V_13 , V_169 . V_131 , V_169 . V_132 ) ;
case V_171 :
V_158 = V_172 ;
if ( F_104 ( V_167 , & V_158 , sizeof V_158 ) )
return - V_151 ;
return 0 ;
case V_173 :
if ( F_103 ( & V_158 , V_167 , sizeof V_158 ) )
return - V_151 ;
if ( V_158 & ~ V_172 )
return - V_174 ;
return F_96 ( V_13 , V_158 ) ;
case V_175 :
return F_93 ( V_13 ) ;
case V_176 :
return F_99 ( V_13 ) ;
default:
F_35 ( & V_13 -> V_50 . V_77 ) ;
V_102 = F_105 ( & V_13 -> V_50 , V_164 , V_166 ) ;
if ( V_102 == - V_177 )
V_102 = F_106 ( & V_13 -> V_50 , V_164 , V_166 ) ;
else
F_75 ( V_13 ) ;
F_46 ( & V_13 -> V_50 . V_77 ) ;
return V_102 ;
}
}
static long F_107 ( struct V_122 * V_123 , unsigned int V_164 ,
unsigned long V_165 )
{
return F_102 ( V_123 , V_164 , ( unsigned long ) F_108 ( V_165 ) ) ;
}
static int F_109 ( void )
{
if ( V_30 )
F_1 ( V_58 ) ;
return F_110 ( & V_178 ) ;
}
static void F_111 ( void )
{
F_112 ( & V_178 ) ;
}
