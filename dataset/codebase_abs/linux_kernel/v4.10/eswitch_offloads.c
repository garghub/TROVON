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
return V_14 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_48 )
{
struct V_49 * V_50 ;
int V_51 , V_52 = 0 ;
F_12 ( V_3 -> V_29 , L_1 , V_53 , V_48 ? L_2 : L_3 ) ;
for ( V_51 = 1 ; V_51 < V_3 -> V_54 ; V_51 ++ ) {
V_50 = & V_3 -> V_55 . V_56 [ V_51 ] ;
if ( ! V_50 -> V_57 )
continue;
V_52 = F_13 ( V_3 , V_50 -> V_27 , 0 , 0 , V_48 ) ;
if ( V_52 )
goto V_58;
}
V_58:
return V_52 ;
}
static struct V_49 *
F_14 ( struct V_6 * V_7 , bool V_59 , bool V_60 )
{
struct V_49 * V_36 , * V_26 , * V_27 = NULL ;
V_36 = V_7 -> V_36 ;
V_26 = V_7 -> V_26 ;
if ( V_59 )
V_27 = V_36 ;
else if ( V_60 )
V_27 = V_26 ;
else
V_27 = V_36 ;
return V_27 ;
}
static int F_15 ( struct V_6 * V_7 ,
bool V_59 , bool V_60 , bool V_61 )
{
struct V_49 * V_36 , * V_26 ;
if ( ( V_59 || V_60 ) && ! V_61 )
goto V_62;
V_36 = V_7 -> V_36 ;
V_26 = V_7 -> V_26 ;
if ( V_59 && V_36 -> V_27 == V_63 )
goto V_62;
if ( V_60 && V_26 -> V_27 == V_63 )
goto V_62;
if ( ! V_59 && ! V_60 && V_61 )
if ( V_36 -> V_64 && V_26 -> V_27 == V_63 )
goto V_62;
if ( V_59 && V_36 -> V_65 && ( V_36 -> V_64 != V_7 -> V_64 ) )
goto V_62;
return 0 ;
V_62:
return - V_19 ;
}
int F_16 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_66 * V_55 = & V_3 -> V_46 . V_55 ;
struct V_49 * V_27 = NULL ;
bool V_59 , V_60 , V_61 ;
int V_52 = 0 ;
V_59 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_60 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_61 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_52 = F_15 ( V_7 , V_59 , V_60 , V_61 ) ;
if ( V_52 )
return V_52 ;
V_7 -> V_67 = false ;
V_27 = F_14 ( V_7 , V_59 , V_60 ) ;
if ( ! V_59 && ! V_60 && V_61 ) {
if ( V_7 -> V_26 -> V_27 == V_63 ) {
V_27 -> V_65 ++ ;
V_7 -> V_67 = true ;
}
return 0 ;
}
if ( ! V_59 && ! V_60 )
return 0 ;
if ( ! ( V_55 -> V_68 ) ) {
V_52 = F_11 ( V_3 , V_69 ) ;
if ( V_52 )
goto V_58;
}
V_55 -> V_68 ++ ;
if ( V_59 ) {
if ( V_27 -> V_65 )
goto V_70;
V_52 = F_13 ( V_3 , V_27 -> V_27 , V_7 -> V_64 , 0 ,
V_71 | V_69 ) ;
if ( V_52 )
goto V_58;
V_27 -> V_64 = V_7 -> V_64 ;
V_70:
V_27 -> V_65 ++ ;
}
V_58:
if ( ! V_52 )
V_7 -> V_67 = true ;
return V_52 ;
}
int F_17 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_66 * V_55 = & V_3 -> V_46 . V_55 ;
struct V_49 * V_27 = NULL ;
bool V_59 , V_60 , V_61 ;
int V_52 = 0 ;
if ( ! V_7 -> V_67 )
return 0 ;
V_59 = ! ! ( V_7 -> V_20 & V_21 ) ;
V_60 = ! ! ( V_7 -> V_20 & V_22 ) ;
V_61 = ! ! ( V_7 -> V_20 & V_23 ) ;
V_27 = F_14 ( V_7 , V_59 , V_60 ) ;
if ( ! V_59 && ! V_60 && V_61 ) {
if ( V_7 -> V_26 -> V_27 == V_63 )
V_27 -> V_65 -- ;
return 0 ;
}
if ( V_59 ) {
V_27 -> V_65 -- ;
if ( V_27 -> V_65 )
goto V_72;
V_27 -> V_64 = 0 ;
V_52 = F_13 ( V_3 , V_27 -> V_27 ,
0 , 0 , V_69 ) ;
if ( V_52 )
goto V_58;
}
V_72:
V_55 -> V_68 -- ;
if ( V_55 -> V_68 )
return 0 ;
V_52 = F_11 ( V_3 , 0 ) ;
V_58:
return V_52 ;
}
static struct V_1 *
F_18 ( struct V_2 * V_3 , int V_27 , T_2 V_73 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_74 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_29 , L_4 ) ;
V_74 = F_2 ( - V_75 ) ;
goto V_58;
}
V_15 = F_6 ( V_31 , V_5 -> V_32 , V_33 ) ;
F_7 ( V_34 , V_15 , V_76 , V_73 ) ;
F_7 ( V_34 , V_15 , V_35 , 0x0 ) ;
V_15 = F_6 ( V_31 , V_5 -> V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_76 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
V_5 -> V_38 = V_40 ;
V_9 . type = V_24 ;
V_9 . V_25 = V_27 ;
V_11 . V_20 = V_23 ;
V_74 = F_9 ( V_3 -> V_46 . V_55 . V_47 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_74 ) )
F_20 ( V_3 -> V_29 , L_5 , F_21 ( V_74 ) ) ;
V_58:
F_22 ( V_5 ) ;
return V_74 ;
}
void F_23 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
struct V_77 * V_78 , * V_79 ;
if ( V_3 -> V_17 != V_18 )
return;
F_24 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_25 ( V_78 -> V_80 ) ;
F_26 ( & V_78 -> V_81 ) ;
F_27 ( V_78 ) ;
}
}
int F_28 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
T_3 * V_82 , int V_83 )
{
struct V_1 * V_74 ;
struct V_77 * V_78 ;
int V_52 ;
int V_16 ;
if ( V_3 -> V_17 != V_18 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_83 ; V_16 ++ ) {
V_78 = F_29 ( sizeof( * V_78 ) , V_84 ) ;
if ( ! V_78 ) {
V_52 = - V_75 ;
goto V_85;
}
V_74 = F_18 ( V_3 ,
V_50 -> V_27 ,
V_82 [ V_16 ] ) ;
if ( F_4 ( V_74 ) ) {
V_52 = F_21 ( V_74 ) ;
F_27 ( V_78 ) ;
goto V_85;
}
V_78 -> V_80 = V_74 ;
F_30 ( & V_78 -> V_81 , & V_50 -> V_86 ) ;
}
return 0 ;
V_85:
F_23 ( V_3 , V_50 ) ;
return V_52 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_74 = NULL ;
struct V_4 * V_5 ;
int V_52 = 0 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_29 , L_4 ) ;
V_52 = - V_75 ;
goto V_58;
}
V_9 . type = V_24 ;
V_9 . V_25 = 0 ;
V_11 . V_20 = V_23 ;
V_74 = F_9 ( V_3 -> V_46 . V_55 . V_47 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_74 ) ) {
V_52 = F_21 ( V_74 ) ;
F_20 ( V_3 -> V_29 , L_6 , V_52 ) ;
goto V_58;
}
V_3 -> V_46 . V_55 . V_87 = V_74 ;
V_58:
F_22 ( V_5 ) ;
return V_52 ;
}
static int F_32 ( struct V_2 * V_3 , int V_88 )
{
int V_89 = F_33 ( V_90 ) ;
struct V_91 * V_29 = V_3 -> V_29 ;
struct V_92 * V_93 ;
struct V_45 * V_47 = NULL ;
struct V_94 * V_95 ;
T_2 * V_96 ;
void * V_37 ;
int V_97 , V_98 , V_52 = 0 ;
T_2 V_99 = 0 ;
V_96 = F_19 ( V_89 ) ;
if ( ! V_96 )
return - V_75 ;
V_93 = F_34 ( V_29 , V_100 ) ;
if ( ! V_93 ) {
F_20 ( V_29 , L_7 ) ;
V_52 = - V_19 ;
goto V_101;
}
F_12 ( V_29 , L_8 ,
F_35 ( V_29 , V_102 ) ) ;
if ( F_35 ( V_29 , V_43 ) &&
F_35 ( V_29 , V_103 ) )
V_99 |= V_104 ;
V_47 = F_36 ( V_93 , V_105 ,
V_106 ,
V_107 , 0 ,
V_99 ) ;
if ( F_4 ( V_47 ) ) {
V_52 = F_21 ( V_47 ) ;
F_20 ( V_29 , L_9 , V_52 ) ;
goto V_108;
}
V_3 -> V_46 . V_47 = V_47 ;
V_97 = V_88 + V_109 + 1 ;
V_47 = F_37 ( V_93 , V_110 , V_97 , 0 , 0 ) ;
if ( F_4 ( V_47 ) ) {
V_52 = F_21 ( V_47 ) ;
F_20 ( V_29 , L_10 , V_52 ) ;
goto V_111;
}
V_3 -> V_46 . V_55 . V_47 = V_47 ;
memset ( V_96 , 0 , V_89 ) ;
F_7 ( V_90 , V_96 , V_38 ,
V_40 ) ;
V_37 = F_6 ( V_90 , V_96 , V_37 ) ;
F_8 ( V_31 , V_37 , V_33 . V_76 ) ;
F_8 ( V_31 , V_37 , V_33 . V_35 ) ;
V_98 = V_88 + V_109 ;
F_7 ( V_90 , V_96 , V_112 , 0 ) ;
F_7 ( V_90 , V_96 , V_113 , V_98 - 1 ) ;
V_95 = F_38 ( V_47 , V_96 ) ;
if ( F_4 ( V_95 ) ) {
V_52 = F_21 ( V_95 ) ;
F_20 ( V_29 , L_11 , V_52 ) ;
goto V_114;
}
V_3 -> V_46 . V_55 . V_115 = V_95 ;
memset ( V_96 , 0 , V_89 ) ;
F_7 ( V_90 , V_96 , V_38 , 0 ) ;
F_7 ( V_90 , V_96 , V_112 , V_98 ) ;
F_7 ( V_90 , V_96 , V_113 , V_98 + 1 ) ;
V_95 = F_38 ( V_47 , V_96 ) ;
if ( F_4 ( V_95 ) ) {
V_52 = F_21 ( V_95 ) ;
F_20 ( V_29 , L_12 , V_52 ) ;
goto V_116;
}
V_3 -> V_46 . V_55 . V_117 = V_95 ;
V_52 = F_31 ( V_3 ) ;
if ( V_52 )
goto V_118;
return 0 ;
V_118:
F_39 ( V_3 -> V_46 . V_55 . V_117 ) ;
V_116:
F_39 ( V_3 -> V_46 . V_55 . V_115 ) ;
V_114:
F_40 ( V_3 -> V_46 . V_55 . V_47 ) ;
V_111:
F_40 ( V_3 -> V_46 . V_47 ) ;
V_108:
V_101:
F_22 ( V_96 ) ;
return V_52 ;
}
static void F_41 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_46 . V_47 )
return;
F_12 ( V_3 -> V_29 , L_13 ) ;
F_25 ( V_3 -> V_46 . V_55 . V_87 ) ;
F_39 ( V_3 -> V_46 . V_55 . V_115 ) ;
F_39 ( V_3 -> V_46 . V_55 . V_117 ) ;
F_40 ( V_3 -> V_46 . V_55 . V_47 ) ;
F_40 ( V_3 -> V_46 . V_47 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_92 * V_119 ;
struct V_45 * V_120 ;
struct V_91 * V_29 = V_3 -> V_29 ;
int V_52 = 0 ;
V_119 = F_34 ( V_29 , V_121 ) ;
if ( ! V_119 ) {
F_20 ( V_3 -> V_29 , L_14 ) ;
return - V_19 ;
}
V_120 = F_37 ( V_119 , 0 , V_29 -> V_122 . V_123 . V_124 + 2 , 0 , 0 ) ;
if ( F_4 ( V_120 ) ) {
V_52 = F_21 ( V_120 ) ;
F_20 ( V_3 -> V_29 , L_15 , V_52 ) ;
return V_52 ;
}
V_3 -> V_55 . V_120 = V_120 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_125 * V_55 = & V_3 -> V_55 ;
F_40 ( V_55 -> V_120 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_89 = F_33 ( V_90 ) ;
struct V_94 * V_95 ;
struct V_126 * V_122 = & V_3 -> V_29 -> V_122 ;
T_2 * V_96 ;
void * V_37 , * V_15 ;
int V_52 = 0 ;
int V_88 = V_122 -> V_123 . V_124 + 2 ;
V_96 = F_19 ( V_89 ) ;
if ( ! V_96 )
return - V_75 ;
memset ( V_96 , 0 , V_89 ) ;
F_7 ( V_90 , V_96 , V_38 ,
V_40 ) ;
V_37 = F_6 ( V_90 , V_96 , V_37 ) ;
V_15 = F_6 ( V_31 , V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
F_7 ( V_90 , V_96 , V_112 , 0 ) ;
F_7 ( V_90 , V_96 , V_113 , V_88 - 1 ) ;
V_95 = F_38 ( V_3 -> V_55 . V_120 , V_96 ) ;
if ( F_4 ( V_95 ) ) {
V_52 = F_21 ( V_95 ) ;
F_45 ( V_3 -> V_29 , L_16 , V_52 ) ;
goto V_58;
}
V_3 -> V_55 . V_127 = V_95 ;
V_58:
F_27 ( V_96 ) ;
return V_52 ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_39 ( V_3 -> V_55 . V_127 ) ;
}
struct V_1 *
F_47 ( struct V_2 * V_3 , int V_27 , T_2 V_128 )
{
struct V_10 V_11 = { 0 } ;
struct V_8 V_9 ;
struct V_1 * V_74 ;
struct V_4 * V_5 ;
void * V_15 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_29 , L_17 ) ;
V_74 = F_2 ( - V_75 ) ;
goto V_58;
}
V_15 = F_6 ( V_31 , V_5 -> V_32 , V_33 ) ;
F_7 ( V_34 , V_15 , V_35 , V_27 ) ;
V_15 = F_6 ( V_31 , V_5 -> V_37 , V_33 ) ;
F_8 ( V_34 , V_15 , V_35 ) ;
V_5 -> V_38 = V_40 ;
V_9 . type = V_129 ;
V_9 . V_130 = V_128 ;
V_11 . V_20 = V_23 ;
V_74 = F_9 ( V_3 -> V_55 . V_120 , V_5 ,
& V_11 , & V_9 , 1 ) ;
if ( F_4 ( V_74 ) ) {
F_20 ( V_3 -> V_29 , L_18 , F_21 ( V_74 ) ) ;
goto V_58;
}
V_58:
F_22 ( V_5 ) ;
return V_74 ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_52 , V_131 , V_124 = V_3 -> V_29 -> V_122 . V_123 . V_124 ;
if ( V_3 -> V_17 != V_132 ) {
F_20 ( V_3 -> V_29 , L_19 ) ;
return - V_133 ;
}
F_49 ( V_3 ) ;
V_52 = F_50 ( V_3 , V_124 , V_18 ) ;
if ( V_52 ) {
F_20 ( V_3 -> V_29 , L_20 , V_52 ) ;
V_131 = F_50 ( V_3 , V_124 , V_132 ) ;
if ( V_131 )
F_20 ( V_3 -> V_29 , L_21 , V_131 ) ;
}
if ( V_3 -> V_55 . V_134 == V_135 ) {
if ( F_51 ( V_3 ,
V_124 ,
& V_3 -> V_55 . V_134 ) ) {
V_3 -> V_55 . V_134 = V_136 ;
F_20 ( V_3 -> V_29 , L_22 ) ;
}
}
return V_52 ;
}
int F_52 ( struct V_2 * V_3 , int V_88 )
{
struct V_49 * V_50 ;
int V_27 ;
int V_52 ;
F_53 () ;
F_54 ( V_3 -> V_29 , V_137 ) ;
F_55 () ;
V_52 = F_32 ( V_3 , V_88 ) ;
if ( V_52 )
goto V_138;
V_52 = F_42 ( V_3 ) ;
if ( V_52 )
goto V_139;
V_52 = F_44 ( V_3 ) ;
if ( V_52 )
goto V_140;
for ( V_27 = 0 ; V_27 < V_88 ; V_27 ++ ) {
V_50 = & V_3 -> V_55 . V_56 [ V_27 ] ;
if ( ! V_50 -> V_57 )
continue;
V_52 = V_50 -> V_141 ( V_3 , V_50 ) ;
if ( V_52 )
goto V_142;
}
return 0 ;
V_142:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
V_50 = & V_3 -> V_55 . V_56 [ V_27 ] ;
if ( ! V_50 -> V_57 )
continue;
V_50 -> V_143 ( V_3 , V_50 ) ;
}
F_46 ( V_3 ) ;
V_140:
F_43 ( V_3 ) ;
V_139:
F_41 ( V_3 ) ;
V_138:
F_53 () ;
F_56 ( V_3 -> V_29 , V_137 ) ;
F_55 () ;
return V_52 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_52 , V_131 , V_124 = V_3 -> V_29 -> V_122 . V_123 . V_124 ;
F_49 ( V_3 ) ;
V_52 = F_50 ( V_3 , V_124 , V_132 ) ;
if ( V_52 ) {
F_20 ( V_3 -> V_29 , L_23 , V_52 ) ;
V_131 = F_50 ( V_3 , V_124 , V_18 ) ;
if ( V_131 )
F_20 ( V_3 -> V_29 , L_24 , V_52 ) ;
}
F_53 () ;
F_56 ( V_3 -> V_29 , V_137 ) ;
F_55 () ;
return V_52 ;
}
void F_58 ( struct V_2 * V_3 , int V_88 )
{
struct V_49 * V_50 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_88 ; V_27 ++ ) {
V_50 = & V_3 -> V_55 . V_56 [ V_27 ] ;
if ( ! V_50 -> V_57 )
continue;
V_50 -> V_143 ( V_3 , V_50 ) ;
}
F_46 ( V_3 ) ;
F_43 ( V_3 ) ;
F_41 ( V_3 ) ;
}
static int F_59 ( T_3 V_17 , T_3 * V_144 )
{
switch ( V_17 ) {
case V_145 :
* V_144 = V_132 ;
break;
case V_146 :
* V_144 = V_18 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_60 ( T_3 V_144 , T_3 * V_17 )
{
switch ( V_144 ) {
case V_132 :
* V_17 = V_145 ;
break;
case V_18 :
* V_17 = V_146 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_61 ( T_1 V_17 , T_1 * V_144 )
{
switch ( V_17 ) {
case V_147 :
* V_144 = V_135 ;
break;
case V_148 :
* V_144 = V_136 ;
break;
case V_149 :
* V_144 = V_150 ;
break;
case V_151 :
* V_144 = V_152 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_62 ( T_1 V_144 , T_1 * V_17 )
{
switch ( V_144 ) {
case V_135 :
* V_17 = V_147 ;
break;
case V_136 :
* V_17 = V_148 ;
break;
case V_150 :
* V_17 = V_149 ;
break;
case V_152 :
* V_17 = V_151 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
int F_63 ( struct V_153 * V_153 , T_3 V_17 )
{
struct V_91 * V_29 ;
T_3 V_154 , V_144 = 0 ;
V_29 = F_64 ( V_153 ) ;
if ( ! F_65 ( V_29 , V_155 ) )
return - V_19 ;
V_154 = V_29 -> V_122 . V_156 -> V_17 ;
if ( V_154 == V_157 )
return - V_19 ;
if ( F_59 ( V_17 , & V_144 ) )
return - V_133 ;
if ( V_154 == V_144 )
return 0 ;
if ( V_17 == V_146 )
return F_48 ( V_29 -> V_122 . V_156 ) ;
else if ( V_17 == V_145 )
return F_57 ( V_29 -> V_122 . V_156 ) ;
else
return - V_133 ;
}
int F_66 ( struct V_153 * V_153 , T_3 * V_17 )
{
struct V_91 * V_29 ;
V_29 = F_64 ( V_153 ) ;
if ( ! F_65 ( V_29 , V_155 ) )
return - V_19 ;
if ( V_29 -> V_122 . V_156 -> V_17 == V_157 )
return - V_19 ;
return F_60 ( V_29 -> V_122 . V_156 -> V_17 , V_17 ) ;
}
int F_67 ( struct V_153 * V_153 , T_1 V_17 )
{
struct V_91 * V_29 = F_64 ( V_153 ) ;
struct V_2 * V_3 = V_29 -> V_122 . V_156 ;
int V_158 = V_3 -> V_54 ;
int V_52 ;
int V_27 ;
T_1 V_144 ;
if ( ! F_65 ( V_29 , V_155 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_157 )
return - V_19 ;
if ( F_68 ( V_29 , V_159 ) !=
V_160 )
return - V_19 ;
V_52 = F_61 ( V_17 , & V_144 ) ;
if ( V_52 )
goto V_58;
for ( V_27 = 1 ; V_27 < V_158 ; V_27 ++ ) {
V_52 = F_69 ( V_29 , V_27 , V_144 ) ;
if ( V_52 ) {
F_20 ( V_29 , L_25 ,
V_27 ) ;
goto V_161;
}
}
V_3 -> V_55 . V_134 = V_144 ;
return 0 ;
V_161:
while ( -- V_27 > 0 )
F_69 ( V_29 ,
V_27 ,
V_3 -> V_55 . V_134 ) ;
V_58:
return V_52 ;
}
int F_70 ( struct V_153 * V_153 , T_1 * V_17 )
{
struct V_91 * V_29 = F_64 ( V_153 ) ;
struct V_2 * V_3 = V_29 -> V_122 . V_156 ;
if ( ! F_65 ( V_29 , V_155 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_157 )
return - V_19 ;
if ( F_68 ( V_29 , V_159 ) !=
V_160 )
return - V_19 ;
return F_62 ( V_3 -> V_55 . V_134 , V_17 ) ;
}
int F_51 ( struct V_2 * V_3 , int V_162 , T_1 * V_17 )
{
struct V_91 * V_29 = V_3 -> V_29 ;
int V_27 ;
T_1 V_163 , V_144 = V_136 ;
if ( ! F_65 ( V_29 , V_155 ) )
return - V_19 ;
if ( V_3 -> V_17 == V_157 )
return - V_19 ;
if ( F_68 ( V_29 , V_159 ) !=
V_160 )
return - V_19 ;
for ( V_27 = 1 ; V_27 <= V_162 ; V_27 ++ ) {
F_71 ( V_29 , V_27 , & V_144 ) ;
if ( V_27 > 1 && V_163 != V_144 )
return - V_133 ;
V_163 = V_144 ;
}
* V_17 = V_144 ;
return 0 ;
}
void F_72 ( struct V_2 * V_3 ,
int V_164 ,
struct V_49 * V_165 )
{
struct V_125 * V_55 = & V_3 -> V_55 ;
struct V_49 * V_50 ;
V_50 = & V_55 -> V_56 [ V_164 ] ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_141 = V_165 -> V_141 ;
V_50 -> V_143 = V_165 -> V_143 ;
V_50 -> V_27 = V_165 -> V_27 ;
V_50 -> V_166 = V_165 -> V_166 ;
F_73 ( V_50 -> V_167 , V_165 -> V_167 ) ;
F_74 ( & V_50 -> V_86 ) ;
V_50 -> V_57 = true ;
}
void F_75 ( struct V_2 * V_3 ,
int V_164 )
{
struct V_125 * V_55 = & V_3 -> V_55 ;
struct V_49 * V_50 ;
V_50 = & V_55 -> V_56 [ V_164 ] ;
if ( V_3 -> V_17 == V_18 && V_3 -> V_168 [ V_164 ] . V_169 )
V_50 -> V_143 ( V_3 , V_50 ) ;
V_50 -> V_57 = false ;
}
struct V_170 * F_76 ( struct V_2 * V_3 )
{
#define F_77 0
struct V_125 * V_55 = & V_3 -> V_55 ;
struct V_49 * V_50 ;
V_50 = & V_55 -> V_56 [ F_77 ] ;
return V_50 -> V_166 ;
}
