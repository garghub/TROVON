struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 V_9 [ 2 ] = {} ;
struct V_10 V_11 = { 0 } ;
struct V_12 * V_13 = NULL ;
struct V_1 * V_14 ;
void * V_15 ;
int V_16 = 0 ;
if ( V_3 -> V_17 != V_18 )
return F_2 ( - V_19 ) ;
V_11 . V_20 = V_7 -> V_20 & ~ ( V_21 | V_22 ) ;
if ( V_11 . V_20 & V_23 ) {
V_9 [ V_16 ] . type = V_24 ;
V_9 [ V_16 ] . V_25 = V_7 -> V_26 -> V_27 ;
V_16 ++ ;
}
if ( V_11 . V_20 & V_28 ) {
V_13 = F_3 ( V_3 -> V_29 , true ) ;
if ( F_4 ( V_13 ) )
return F_5 ( V_13 ) ;
V_9 [ V_16 ] . type = V_30 ;
V_9 [ V_16 ] . V_13 = V_13 ;
V_16 ++ ;
}
V_15 = F_6 ( V_31 , V_5 -> V_32 , V_33 ) ;
F_7 ( V_34 , V_15 , V_35 , V_7 -> V_36 -> V_27 ) ;
V_15 = F_6 ( V_31 , V_5 -> V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
V_5 -> V_38 = V_39 |
V_40 ;
if ( V_11 . V_20 & V_41 )
V_5 -> V_38 |= V_42 ;
if ( V_7 -> V_43 )
V_11 . V_44 = V_7 -> V_43 -> V_44 ;
V_14 = F_9 ( (struct V_45 * ) V_3 -> V_46 . V_47 ,
V_5 , & V_11 , V_9 , V_16 ) ;
if ( F_4 ( V_14 ) )
F_10 ( V_3 -> V_29 , V_13 ) ;
else
V_3 -> V_48 . V_49 ++ ;
return V_14 ;
}
void
F_11 ( struct V_2 * V_3 ,
struct V_1 * V_14 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
if ( ! F_4 ( V_14 ) ) {
V_13 = F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
F_10 ( V_3 -> V_29 , V_13 ) ;
V_3 -> V_48 . V_49 -- ;
}
}
static int F_14 ( struct V_2 * V_3 , T_1 V_50 )
{
struct V_51 * V_52 ;
int V_53 , V_54 = 0 ;
F_15 ( V_3 -> V_29 , L_1 , V_55 , V_50 ? L_2 : L_3 ) ;
for ( V_53 = 1 ; V_53 < V_3 -> V_56 ; V_53 ++ ) {
V_52 = & V_3 -> V_48 . V_57 [ V_53 ] ;
if ( ! V_52 -> V_58 )
continue;
V_54 = F_16 ( V_3 , V_52 -> V_27 , 0 , 0 , V_50 ) ;
if ( V_54 )
goto V_59;
}
V_59:
return V_54 ;
}
static struct V_51 *
F_17 ( struct V_6 * V_7 , bool V_60 , bool V_61 )
{
struct V_51 * V_36 , * V_26 , * V_27 = NULL ;
V_36 = V_7 -> V_36 ;
V_26 = V_7 -> V_26 ;
if ( V_60 )
V_27 = V_36 ;
else if ( V_61 )
V_27 = V_26 ;
else
V_27 = V_36 ;
return V_27 ;
}
static int F_18 ( struct V_6 * V_7 ,
bool V_60 , bool V_61 , bool V_62 )
{
struct V_51 * V_36 , * V_26 ;
if ( ( V_60 || V_61 ) && ! V_62 )
goto V_63;
V_36 = V_7 -> V_36 ;
V_26 = V_7 -> V_26 ;
if ( V_60 && V_36 -> V_27 == V_64 )
goto V_63;
if ( V_61 && V_26 -> V_27 == V_64 )
goto V_63;
if ( ! V_60 && ! V_61 && V_62 )
if ( V_36 -> V_65 && V_26 -> V_27 == V_64 )
goto V_63;
if ( V_60 && V_36 -> V_66 && ( V_36 -> V_65 != V_7 -> V_65 ) )
goto V_63;
return 0 ;
V_63:
return - V_19 ;
}
int F_19 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_67 * V_48 = & V_3 -> V_46 . V_48 ;
struct V_51 * V_27 = NULL ;
bool V_60 , V_61 , V_62 ;
int V_54 = 0 ;
V_60 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_61 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_62 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_54 = F_18 ( V_7 , V_60 , V_61 , V_62 ) ;
if ( V_54 )
return V_54 ;
V_7 -> V_68 = false ;
V_27 = F_17 ( V_7 , V_60 , V_61 ) ;
if ( ! V_60 && ! V_61 && V_62 ) {
if ( V_7 -> V_26 -> V_27 == V_64 ) {
V_27 -> V_66 ++ ;
V_7 -> V_68 = true ;
}
return 0 ;
}
if ( ! V_60 && ! V_61 )
return 0 ;
if ( ! ( V_48 -> V_69 ) ) {
V_54 = F_14 ( V_3 , V_70 ) ;
if ( V_54 )
goto V_59;
}
V_48 -> V_69 ++ ;
if ( V_60 ) {
if ( V_27 -> V_66 )
goto V_71;
V_54 = F_16 ( V_3 , V_27 -> V_27 , V_7 -> V_65 , 0 ,
V_72 | V_70 ) ;
if ( V_54 )
goto V_59;
V_27 -> V_65 = V_7 -> V_65 ;
V_71:
V_27 -> V_66 ++ ;
}
V_59:
if ( ! V_54 )
V_7 -> V_68 = true ;
return V_54 ;
}
int F_20 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_67 * V_48 = & V_3 -> V_46 . V_48 ;
struct V_51 * V_27 = NULL ;
bool V_60 , V_61 , V_62 ;
int V_54 = 0 ;
if ( ! V_7 -> V_68 )
return 0 ;
V_60 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_61 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_62 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_27 = F_17 ( V_7 , V_60 , V_61 ) ;
if ( ! V_60 && ! V_61 && V_62 ) {
if ( V_7 -> V_26 -> V_27 == V_64 )
V_27 -> V_66 -- ;
return 0 ;
}
if ( V_60 ) {
V_27 -> V_66 -- ;
if ( V_27 -> V_66 )
goto V_73;
V_27 -> V_65 = 0 ;
V_54 = F_16 ( V_3 , V_27 -> V_27 ,
0 , 0 , V_70 ) ;
if ( V_54 )
goto V_59;
}
V_73:
V_48 -> V_69 -- ;
if ( V_48 -> V_69 )
return 0 ;
V_54 = F_14 ( V_3 , 0 ) ;
V_59:
return V_54 ;
}
static struct V_1 *
F_21 ( struct V_2 * V_3 , int V_27 , T_2 V_74 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_75 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_4 ) ;
V_75 = F_2 ( - V_76 ) ;
goto V_59;
}
V_15 = F_6 ( V_31 , V_5 -> V_32 , V_33 ) ;
F_7 ( V_34 , V_15 , V_77 , V_74 ) ;
F_7 ( V_34 , V_15 , V_35 , 0x0 ) ;
V_15 = F_6 ( V_31 , V_5 -> V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_77 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
V_5 -> V_38 = V_40 ;
V_9 . type = V_24 ;
V_9 . V_25 = V_27 ;
V_11 . V_20 = V_23 ;
V_75 = F_9 ( V_3 -> V_46 . V_48 . V_47 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_75 ) )
F_23 ( V_3 -> V_29 , L_5 , F_24 ( V_75 ) ) ;
V_59:
F_25 ( V_5 ) ;
return V_75 ;
}
void F_26 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_78 * V_79 , * V_80 ;
if ( V_3 -> V_17 != V_18 )
return;
F_27 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_13 ( V_79 -> V_81 ) ;
F_28 ( & V_79 -> V_82 ) ;
F_29 ( V_79 ) ;
}
}
int F_30 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
T_3 * V_83 , int V_84 )
{
struct V_1 * V_75 ;
struct V_78 * V_79 ;
int V_54 ;
int V_16 ;
if ( V_3 -> V_17 != V_18 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_84 ; V_16 ++ ) {
V_79 = F_31 ( sizeof( * V_79 ) , V_85 ) ;
if ( ! V_79 ) {
V_54 = - V_76 ;
goto V_86;
}
V_75 = F_21 ( V_3 ,
V_52 -> V_27 ,
V_83 [ V_16 ] ) ;
if ( F_4 ( V_75 ) ) {
V_54 = F_24 ( V_75 ) ;
F_29 ( V_79 ) ;
goto V_86;
}
V_79 -> V_81 = V_75 ;
F_32 ( & V_79 -> V_82 , & V_52 -> V_87 ) ;
}
return 0 ;
V_86:
F_26 ( V_3 , V_52 ) ;
return V_54 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_75 = NULL ;
struct V_4 * V_5 ;
int V_54 = 0 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_4 ) ;
V_54 = - V_76 ;
goto V_59;
}
V_9 . type = V_24 ;
V_9 . V_25 = 0 ;
V_11 . V_20 = V_23 ;
V_75 = F_9 ( V_3 -> V_46 . V_48 . V_47 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_75 ) ) {
V_54 = F_24 ( V_75 ) ;
F_23 ( V_3 -> V_29 , L_6 , V_54 ) ;
goto V_59;
}
V_3 -> V_46 . V_48 . V_88 = V_75 ;
V_59:
F_25 ( V_5 ) ;
return V_54 ;
}
static int F_34 ( struct V_2 * V_3 , int V_89 )
{
int V_90 = F_35 ( V_91 ) ;
int V_92 , V_93 , V_94 , V_54 = 0 ;
struct V_95 * V_29 = V_3 -> V_29 ;
struct V_96 * V_97 ;
struct V_45 * V_47 = NULL ;
struct V_98 * V_99 ;
T_2 * V_100 ;
void * V_37 ;
T_2 V_101 = 0 ;
V_100 = F_22 ( V_90 ) ;
if ( ! V_100 )
return - V_76 ;
V_97 = F_36 ( V_29 , V_102 ) ;
if ( ! V_97 ) {
F_23 ( V_29 , L_7 ) ;
V_54 = - V_19 ;
goto V_103;
}
F_15 ( V_29 , L_8 ,
F_37 ( V_29 , V_104 ) ,
F_38 ( V_29 , V_105 ) , V_106 ) ;
V_94 = F_39 ( int , F_38 ( V_29 , V_105 ) * V_106 ,
1 << F_37 ( V_29 , V_104 ) ) ;
if ( F_37 ( V_29 , V_43 ) &&
F_37 ( V_29 , V_107 ) )
V_101 |= V_108 ;
V_47 = F_40 ( V_97 , V_109 ,
V_94 ,
V_106 , 0 ,
V_101 ) ;
if ( F_4 ( V_47 ) ) {
V_54 = F_24 ( V_47 ) ;
F_23 ( V_29 , L_9 , V_54 ) ;
goto V_110;
}
V_3 -> V_46 . V_47 = V_47 ;
V_92 = V_89 + V_111 + 1 ;
V_47 = F_41 ( V_97 , V_112 , V_92 , 0 , 0 ) ;
if ( F_4 ( V_47 ) ) {
V_54 = F_24 ( V_47 ) ;
F_23 ( V_29 , L_10 , V_54 ) ;
goto V_113;
}
V_3 -> V_46 . V_48 . V_47 = V_47 ;
memset ( V_100 , 0 , V_90 ) ;
F_7 ( V_91 , V_100 , V_38 ,
V_40 ) ;
V_37 = F_6 ( V_91 , V_100 , V_37 ) ;
F_8 ( V_31 , V_37 , V_33 . V_77 ) ;
F_8 ( V_31 , V_37 , V_33 . V_35 ) ;
V_93 = V_89 + V_111 ;
F_7 ( V_91 , V_100 , V_114 , 0 ) ;
F_7 ( V_91 , V_100 , V_115 , V_93 - 1 ) ;
V_99 = F_42 ( V_47 , V_100 ) ;
if ( F_4 ( V_99 ) ) {
V_54 = F_24 ( V_99 ) ;
F_23 ( V_29 , L_11 , V_54 ) ;
goto V_116;
}
V_3 -> V_46 . V_48 . V_117 = V_99 ;
memset ( V_100 , 0 , V_90 ) ;
F_7 ( V_91 , V_100 , V_38 , 0 ) ;
F_7 ( V_91 , V_100 , V_114 , V_93 ) ;
F_7 ( V_91 , V_100 , V_115 , V_93 + 1 ) ;
V_99 = F_42 ( V_47 , V_100 ) ;
if ( F_4 ( V_99 ) ) {
V_54 = F_24 ( V_99 ) ;
F_23 ( V_29 , L_12 , V_54 ) ;
goto V_118;
}
V_3 -> V_46 . V_48 . V_119 = V_99 ;
V_54 = F_33 ( V_3 ) ;
if ( V_54 )
goto V_120;
return 0 ;
V_120:
F_43 ( V_3 -> V_46 . V_48 . V_119 ) ;
V_118:
F_43 ( V_3 -> V_46 . V_48 . V_117 ) ;
V_116:
F_44 ( V_3 -> V_46 . V_48 . V_47 ) ;
V_113:
F_44 ( V_3 -> V_46 . V_47 ) ;
V_110:
V_103:
F_25 ( V_100 ) ;
return V_54 ;
}
static void F_45 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_46 . V_47 )
return;
F_15 ( V_3 -> V_29 , L_13 ) ;
F_13 ( V_3 -> V_46 . V_48 . V_88 ) ;
F_43 ( V_3 -> V_46 . V_48 . V_117 ) ;
F_43 ( V_3 -> V_46 . V_48 . V_119 ) ;
F_44 ( V_3 -> V_46 . V_48 . V_47 ) ;
F_44 ( V_3 -> V_46 . V_47 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_96 * V_121 ;
struct V_45 * V_122 ;
struct V_95 * V_29 = V_3 -> V_29 ;
int V_54 = 0 ;
V_121 = F_36 ( V_29 , V_123 ) ;
if ( ! V_121 ) {
F_23 ( V_3 -> V_29 , L_14 ) ;
return - V_19 ;
}
V_122 = F_41 ( V_121 , 0 , V_29 -> V_124 . V_125 . V_126 + 2 , 0 , 0 ) ;
if ( F_4 ( V_122 ) ) {
V_54 = F_24 ( V_122 ) ;
F_23 ( V_3 -> V_29 , L_15 , V_54 ) ;
return V_54 ;
}
V_3 -> V_48 . V_122 = V_122 ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_127 * V_48 = & V_3 -> V_48 ;
F_44 ( V_48 -> V_122 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_90 = F_35 ( V_91 ) ;
struct V_98 * V_99 ;
struct V_128 * V_124 = & V_3 -> V_29 -> V_124 ;
T_2 * V_100 ;
void * V_37 , * V_15 ;
int V_54 = 0 ;
int V_89 = V_124 -> V_125 . V_126 + 2 ;
V_100 = F_22 ( V_90 ) ;
if ( ! V_100 )
return - V_76 ;
memset ( V_100 , 0 , V_90 ) ;
F_7 ( V_91 , V_100 , V_38 ,
V_40 ) ;
V_37 = F_6 ( V_91 , V_100 , V_37 ) ;
V_15 = F_6 ( V_31 , V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
F_7 ( V_91 , V_100 , V_114 , 0 ) ;
F_7 ( V_91 , V_100 , V_115 , V_89 - 1 ) ;
V_99 = F_42 ( V_3 -> V_48 . V_122 , V_100 ) ;
if ( F_4 ( V_99 ) ) {
V_54 = F_24 ( V_99 ) ;
F_49 ( V_3 -> V_29 , L_16 , V_54 ) ;
goto V_59;
}
V_3 -> V_48 . V_129 = V_99 ;
V_59:
F_29 ( V_100 ) ;
return V_54 ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_43 ( V_3 -> V_48 . V_129 ) ;
}
struct V_1 *
F_51 ( struct V_2 * V_3 , int V_27 , T_2 V_130 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_75 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_22 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_23 ( V_3 -> V_29 , L_17 ) ;
V_75 = F_2 ( - V_76 ) ;
goto V_59;
}
V_15 = F_6 ( V_31 , V_5 -> V_32 , V_33 ) ;
F_7 ( V_34 , V_15 , V_35 , V_27 ) ;
V_15 = F_6 ( V_31 , V_5 -> V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
V_5 -> V_38 = V_40 ;
V_9 . type = V_131 ;
V_9 . V_132 = V_130 ;
V_11 . V_20 = V_23 ;
V_75 = F_9 ( V_3 -> V_48 . V_122 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_75 ) ) {
F_23 ( V_3 -> V_29 , L_18 , F_24 ( V_75 ) ) ;
goto V_59;
}
V_59:
F_25 ( V_5 ) ;
return V_75 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_54 , V_133 , V_126 = V_3 -> V_29 -> V_124 . V_125 . V_126 ;
if ( V_3 -> V_17 != V_134 ) {
F_23 ( V_3 -> V_29 , L_19 ) ;
return - V_135 ;
}
F_53 ( V_3 ) ;
V_54 = F_54 ( V_3 , V_126 , V_18 ) ;
if ( V_54 ) {
F_23 ( V_3 -> V_29 , L_20 , V_54 ) ;
V_133 = F_54 ( V_3 , V_126 , V_134 ) ;
if ( V_133 )
F_23 ( V_3 -> V_29 , L_21 , V_133 ) ;
}
if ( V_3 -> V_48 . V_136 == V_137 ) {
if ( F_55 ( V_3 ,
V_126 ,
& V_3 -> V_48 . V_136 ) ) {
V_3 -> V_48 . V_136 = V_138 ;
F_23 ( V_3 -> V_29 , L_22 ) ;
}
}
return V_54 ;
}
int F_56 ( struct V_2 * V_3 , int V_89 )
{
struct V_51 * V_52 ;
int V_27 ;
int V_54 ;
F_57 () ;
F_58 ( V_3 -> V_29 , V_139 ) ;
F_59 () ;
V_54 = F_34 ( V_3 , V_89 ) ;
if ( V_54 )
goto V_140;
V_54 = F_46 ( V_3 ) ;
if ( V_54 )
goto V_141;
V_54 = F_48 ( V_3 ) ;
if ( V_54 )
goto V_142;
for ( V_27 = 0 ; V_27 < V_89 ; V_27 ++ ) {
V_52 = & V_3 -> V_48 . V_57 [ V_27 ] ;
if ( ! V_52 -> V_58 )
continue;
V_54 = V_52 -> V_143 ( V_3 , V_52 ) ;
if ( V_54 )
goto V_144;
}
return 0 ;
V_144:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
V_52 = & V_3 -> V_48 . V_57 [ V_27 ] ;
if ( ! V_52 -> V_58 )
continue;
V_52 -> V_145 ( V_3 , V_52 ) ;
}
F_50 ( V_3 ) ;
V_142:
F_47 ( V_3 ) ;
V_141:
F_45 ( V_3 ) ;
V_140:
F_57 () ;
F_60 ( V_3 -> V_29 , V_139 ) ;
F_59 () ;
return V_54 ;
}
static int F_61 ( struct V_2 * V_3 )
{
int V_54 , V_133 , V_126 = V_3 -> V_29 -> V_124 . V_125 . V_126 ;
F_53 ( V_3 ) ;
V_54 = F_54 ( V_3 , V_126 , V_134 ) ;
if ( V_54 ) {
F_23 ( V_3 -> V_29 , L_23 , V_54 ) ;
V_133 = F_54 ( V_3 , V_126 , V_18 ) ;
if ( V_133 )
F_23 ( V_3 -> V_29 , L_24 , V_54 ) ;
}
F_57 () ;
F_60 ( V_3 -> V_29 , V_139 ) ;
F_59 () ;
return V_54 ;
}
void F_62 ( struct V_2 * V_3 , int V_89 )
{
struct V_51 * V_52 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_89 ; V_27 ++ ) {
V_52 = & V_3 -> V_48 . V_57 [ V_27 ] ;
if ( ! V_52 -> V_58 )
continue;
V_52 -> V_145 ( V_3 , V_52 ) ;
}
F_50 ( V_3 ) ;
F_47 ( V_3 ) ;
F_45 ( V_3 ) ;
}
static int F_63 ( T_3 V_17 , T_3 * V_146 )
{
switch ( V_17 ) {
case V_147 :
* V_146 = V_134 ;
break;
case V_148 :
* V_146 = V_18 ;
break;
default:
return - V_135 ;
}
return 0 ;
}
static int F_64 ( T_3 V_146 , T_3 * V_17 )
{
switch ( V_146 ) {
case V_134 :
* V_17 = V_147 ;
break;
case V_18 :
* V_17 = V_148 ;
break;
default:
return - V_135 ;
}
return 0 ;
}
static int F_65 ( T_1 V_17 , T_1 * V_146 )
{
switch ( V_17 ) {
case V_149 :
* V_146 = V_137 ;
break;
case V_150 :
* V_146 = V_138 ;
break;
case V_151 :
* V_146 = V_152 ;
break;
case V_153 :
* V_146 = V_154 ;
break;
default:
return - V_135 ;
}
return 0 ;
}
static int F_66 ( T_1 V_146 , T_1 * V_17 )
{
switch ( V_146 ) {
case V_137 :
* V_17 = V_149 ;
break;
case V_138 :
* V_17 = V_150 ;
break;
case V_152 :
* V_17 = V_151 ;
break;
case V_154 :
* V_17 = V_153 ;
break;
default:
return - V_135 ;
}
return 0 ;
}
int F_67 ( struct V_155 * V_155 , T_3 V_17 )
{
struct V_95 * V_29 ;
T_3 V_156 , V_146 = 0 ;
V_29 = F_68 ( V_155 ) ;
if ( ! F_38 ( V_29 , V_157 ) )
return - V_19 ;
V_156 = V_29 -> V_124 . V_158 -> V_17 ;
if ( V_156 == V_159 )
return - V_19 ;
if ( F_63 ( V_17 , & V_146 ) )
return - V_135 ;
if ( V_156 == V_146 )
return 0 ;
if ( V_17 == V_148 )
return F_52 ( V_29 -> V_124 . V_158 ) ;
else if ( V_17 == V_147 )
return F_61 ( V_29 -> V_124 . V_158 ) ;
else
return - V_135 ;
}
int F_69 ( struct V_155 * V_155 , T_3 * V_17 )
{
struct V_95 * V_29 ;
V_29 = F_68 ( V_155 ) ;
if ( ! F_38 ( V_29 , V_157 ) )
return - V_19 ;
if ( V_29 -> V_124 . V_158 -> V_17 == V_159 )
return - V_19 ;
return F_64 ( V_29 -> V_124 . V_158 -> V_17 , V_17 ) ;
}
int F_70 ( struct V_155 * V_155 , T_1 V_17 )
{
struct V_95 * V_29 = F_68 ( V_155 ) ;
struct V_2 * V_3 = V_29 -> V_124 . V_158 ;
int V_160 = V_3 -> V_56 ;
int V_54 , V_27 ;
T_1 V_146 ;
if ( ! F_38 ( V_29 , V_157 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_159 )
return - V_19 ;
switch ( F_71 ( V_29 , V_161 ) ) {
case V_162 :
if ( V_17 == V_149 )
return 0 ;
case V_163 :
F_23 ( V_29 , L_25 ) ;
return - V_19 ;
case V_164 :
break;
}
if ( V_3 -> V_48 . V_49 > 0 ) {
F_23 ( V_29 , L_26 ) ;
return - V_19 ;
}
V_54 = F_65 ( V_17 , & V_146 ) ;
if ( V_54 )
goto V_59;
for ( V_27 = 1 ; V_27 < V_160 ; V_27 ++ ) {
V_54 = F_72 ( V_29 , V_27 , V_146 ) ;
if ( V_54 ) {
F_23 ( V_29 , L_27 ,
V_27 ) ;
goto V_165;
}
}
V_3 -> V_48 . V_136 = V_146 ;
return 0 ;
V_165:
while ( -- V_27 > 0 )
F_72 ( V_29 ,
V_27 ,
V_3 -> V_48 . V_136 ) ;
V_59:
return V_54 ;
}
int F_73 ( struct V_155 * V_155 , T_1 * V_17 )
{
struct V_95 * V_29 = F_68 ( V_155 ) ;
struct V_2 * V_3 = V_29 -> V_124 . V_158 ;
if ( ! F_38 ( V_29 , V_157 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_159 )
return - V_19 ;
return F_66 ( V_3 -> V_48 . V_136 , V_17 ) ;
}
int F_55 ( struct V_2 * V_3 , int V_166 , T_1 * V_17 )
{
T_1 V_167 , V_146 = V_138 ;
struct V_95 * V_29 = V_3 -> V_29 ;
int V_27 ;
if ( ! F_38 ( V_29 , V_157 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_159 )
return - V_19 ;
switch ( F_71 ( V_29 , V_161 ) ) {
case V_162 :
V_146 = V_137 ;
goto V_59;
case V_163 :
V_146 = V_138 ;
goto V_59;
case V_164 :
goto V_168;
}
V_168:
for ( V_27 = 1 ; V_27 <= V_166 ; V_27 ++ ) {
F_74 ( V_29 , V_27 , & V_146 ) ;
if ( V_27 > 1 && V_167 != V_146 )
return - V_135 ;
V_167 = V_146 ;
}
V_59:
* V_17 = V_146 ;
return 0 ;
}
void F_75 ( struct V_2 * V_3 ,
int V_169 ,
struct V_51 * V_170 )
{
struct V_127 * V_48 = & V_3 -> V_48 ;
struct V_51 * V_52 ;
V_52 = & V_48 -> V_57 [ V_169 ] ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_143 = V_170 -> V_143 ;
V_52 -> V_145 = V_170 -> V_145 ;
V_52 -> V_27 = V_170 -> V_27 ;
V_52 -> V_171 = V_170 -> V_171 ;
F_76 ( V_52 -> V_172 , V_170 -> V_172 ) ;
F_77 ( & V_52 -> V_87 ) ;
V_52 -> V_58 = true ;
}
void F_78 ( struct V_2 * V_3 ,
int V_169 )
{
struct V_127 * V_48 = & V_3 -> V_48 ;
struct V_51 * V_52 ;
V_52 = & V_48 -> V_57 [ V_169 ] ;
if ( V_3 -> V_17 == V_18 && V_3 -> V_173 [ V_169 ] . V_174 )
V_52 -> V_145 ( V_3 , V_52 ) ;
V_52 -> V_58 = false ;
}
struct V_175 * F_79 ( struct V_2 * V_3 )
{
#define F_80 0
struct V_127 * V_48 = & V_3 -> V_48 ;
struct V_51 * V_52 ;
V_52 = & V_48 -> V_57 [ F_80 ] ;
return V_52 -> V_171 ;
}
