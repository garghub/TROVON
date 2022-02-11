static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
long V_4 ;
int V_5 ;
V_3 = F_2 ( V_2 -> V_6 , L_1 ) ;
if ( ! V_3 )
return 0 ;
V_5 = F_3 ( V_3 , 0 , & V_4 ) ;
if ( V_5 < 0 )
return 0 ;
return V_4 == 15 ;
}
void F_4 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_5 ( V_8 ) ;
if ( ! V_10 ) {
F_6 ( V_8 -> V_11 ) ;
return;
}
F_7 ( V_8 -> V_11 -> V_12 , V_10 -> V_13 ) ;
F_7 ( V_8 -> V_11 -> V_14 , V_10 -> V_13 ) ;
}
static struct V_9 *
F_8 ( struct V_15 * V_16 , unsigned int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_16 && V_18 < V_16 -> V_19 ; V_18 ++ )
if ( V_16 -> V_20 [ V_18 ] . V_17 == V_17 )
return & V_16 -> V_20 [ V_18 ] ;
return NULL ;
}
static int
F_9 ( struct V_1 * V_2 , const char * V_21 ,
unsigned int V_22 )
{
char V_23 [ 256 ] ;
int V_5 = 0 ;
T_1 V_24 ;
snprintf ( V_23 , sizeof( V_23 ) , V_21 , F_10 ( V_2 -> V_25 ) ) ;
V_24 = F_11 ( V_2 -> V_26 , V_23 , & V_5 ) ;
if ( V_5 ) {
if ( V_5 == - V_27 )
return V_22 ;
F_12 ( V_2 -> V_25 , L_2 , V_23 ) ;
return V_5 ;
}
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , L_3 , 1 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , L_4 ,
V_28 ) ;
}
static T_2 T_3 *
F_15 ( struct V_1 * V_2 , const char * V_23 , const char * V_29 ,
unsigned int V_30 , struct V_31 * * V_32 )
{
char V_33 [ 256 ] ;
snprintf ( V_33 , sizeof( V_33 ) , V_29 ,
F_10 ( V_2 -> V_25 ) ) ;
return F_16 ( V_2 -> V_26 , V_33 , V_23 , V_30 , V_32 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
F_18 ( V_35 -> V_8 ) ;
F_19 ( & V_35 -> V_36 ) ;
V_2 -> V_37 -- ;
F_20 ( V_35 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_34 * V_35 , * V_38 ;
F_22 (nn, next, &pf->vnics, vnic_list)
if ( F_23 ( V_35 ) )
F_17 ( V_2 , V_35 ) ;
}
static struct V_34 *
F_24 ( struct V_1 * V_2 , bool V_39 ,
void T_3 * V_40 , void T_3 * V_41 ,
int V_42 , unsigned int V_43 )
{
T_4 V_44 , V_45 , V_46 , V_47 ;
struct V_34 * V_35 ;
int V_5 ;
V_44 = F_25 ( V_40 + V_48 ) ;
V_45 = F_25 ( V_40 + V_49 ) ;
V_46 = F_25 ( V_40 + V_50 ) ;
V_47 = F_25 ( V_40 + V_51 ) ;
V_35 = F_26 ( V_2 -> V_52 , V_39 , V_46 , V_47 ) ;
if ( F_27 ( V_35 ) )
return V_35 ;
V_35 -> V_53 = V_2 -> V_53 ;
F_28 ( & V_35 -> V_54 , V_40 ) ;
V_35 -> V_55 . V_40 = V_40 ;
V_35 -> V_56 = V_41 + V_44 * V_57 ;
V_35 -> V_58 = V_41 + V_45 * V_57 ;
V_35 -> V_55 . V_59 = 0 ;
V_35 -> V_60 = V_42 ;
V_35 -> V_61 = V_42 ;
if ( V_39 ) {
V_5 = F_29 ( V_2 -> V_53 , V_35 , V_43 ) ;
if ( V_5 ) {
F_20 ( V_35 ) ;
return F_30 ( V_5 ) ;
}
}
V_2 -> V_37 ++ ;
F_31 ( & V_35 -> V_36 , & V_2 -> V_62 ) ;
return V_35 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_34 * V_35 , unsigned int V_43 )
{
int V_5 ;
V_35 -> V_63 = 1200 ;
V_5 = F_33 ( V_35 ) ;
if ( V_5 )
return V_5 ;
F_34 ( V_35 , V_2 -> V_64 , V_43 ) ;
if ( V_35 -> V_8 ) {
V_5 = F_35 ( V_2 -> V_53 , V_35 -> V_8 ) ;
if ( V_5 )
goto V_65;
}
F_36 ( V_35 ) ;
return 0 ;
V_65:
F_37 ( & V_35 -> V_66 ) ;
F_38 ( V_35 ) ;
return V_5 ;
}
static int
F_39 ( struct V_1 * V_2 , void T_3 * V_40 ,
void T_3 * V_41 , int V_42 )
{
struct V_34 * V_35 ;
unsigned int V_18 ;
int V_5 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_67 ; V_18 ++ ) {
V_35 = F_24 ( V_2 , true , V_40 , V_41 ,
V_42 , V_18 ) ;
if ( F_27 ( V_35 ) ) {
V_5 = F_40 ( V_35 ) ;
goto V_68;
}
V_40 += V_69 ;
if ( V_35 -> V_8 && V_35 -> V_8 -> type == V_70 ) {
F_17 ( V_2 , V_35 ) ;
continue;
}
}
if ( F_41 ( & V_2 -> V_62 ) )
return - V_71 ;
return 0 ;
V_68:
F_21 ( V_2 ) ;
return V_5 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
if ( V_35 -> V_8 )
F_43 ( V_35 -> V_8 ) ;
F_37 ( & V_35 -> V_66 ) ;
F_38 ( V_35 ) ;
F_44 ( V_2 -> V_53 , V_35 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
unsigned int V_72 , V_73 , V_74 , V_75 ;
struct V_34 * V_35 ;
V_72 = 0 ;
F_46 (nn, &pf->vnics, vnic_list)
V_72 += V_76 + V_35 -> V_55 . V_77 ;
V_2 -> V_78 = F_47 ( V_72 , sizeof( * V_2 -> V_78 ) ,
V_79 ) ;
if ( ! V_2 -> V_78 )
return - V_80 ;
V_73 = F_48 ( V_2 -> V_52 , V_2 -> V_78 ,
V_81 * V_2 -> V_37 ,
V_72 ) ;
if ( ! V_73 ) {
F_49 ( V_2 -> V_25 , L_5 ) ;
F_50 ( V_2 -> V_78 ) ;
return - V_80 ;
}
V_75 = V_73 ;
V_74 = V_2 -> V_37 ;
F_46 (nn, &pf->vnics, vnic_list) {
unsigned int V_82 ;
V_82 = F_51 ( V_76 + V_35 -> V_55 . V_77 ,
F_52 ( V_75 , V_74 ) ) ;
F_53 ( V_35 , & V_2 -> V_78 [ V_73 - V_75 ] ,
V_82 ) ;
V_75 -= V_82 ;
V_74 -- ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_52 ) ;
F_50 ( V_2 -> V_78 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
unsigned int V_43 ;
int V_5 ;
V_43 = 0 ;
F_46 (nn, &pf->vnics, vnic_list) {
if ( ! F_23 ( V_35 ) )
continue;
V_5 = F_32 ( V_2 , V_35 , V_43 ) ;
if ( V_5 )
goto V_83;
V_43 ++ ;
}
return 0 ;
V_83:
F_57 (nn, &pf->vnics, vnic_list)
if ( F_23 ( V_35 ) )
F_42 ( V_2 , V_35 ) ;
return V_5 ;
}
static int
F_58 ( struct V_1 * V_2 , T_2 T_3 * V_41 , unsigned int V_42 )
{
T_2 T_3 * V_40 ;
int V_5 ;
V_2 -> V_53 = F_59 ( V_2 , F_14 ( V_2 ) ) ;
if ( F_27 ( V_2 -> V_53 ) )
return F_40 ( V_2 -> V_53 ) ;
V_5 = F_60 ( V_2 -> V_53 ) ;
if ( V_5 )
goto V_84;
if ( ! F_61 ( V_2 -> V_53 ) )
return 0 ;
V_40 = F_15 ( V_2 , L_6 , L_7 ,
V_69 ,
& V_2 -> V_85 ) ;
if ( F_27 ( V_40 ) ) {
F_12 ( V_2 -> V_25 , L_8 ) ;
V_5 = F_40 ( V_40 ) ;
goto V_86;
}
V_2 -> V_87 = F_24 ( V_2 , false , V_40 , V_41 ,
V_42 , 0 ) ;
if ( F_27 ( V_2 -> V_87 ) ) {
V_5 = F_40 ( V_2 -> V_87 ) ;
goto V_88;
}
return 0 ;
V_88:
F_62 ( V_2 -> V_85 ) ;
V_86:
F_63 ( V_2 -> V_53 ) ;
V_84:
F_64 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
return V_5 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_17 ( V_2 , V_2 -> V_87 ) ;
F_62 ( V_2 -> V_85 ) ;
}
F_63 ( V_2 -> V_53 ) ;
F_64 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! V_2 -> V_87 )
return 0 ;
V_5 = F_32 ( V_2 , V_2 -> V_87 , 0 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_67 ( V_2 -> V_87 ) ;
if ( V_5 )
goto V_89;
return 0 ;
V_89:
F_42 ( V_2 , V_2 -> V_87 ) ;
return V_5 ;
}
static void F_68 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_87 )
return;
F_69 ( V_2 -> V_87 ) ;
F_42 ( V_2 , V_2 -> V_87 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_71 ( V_2 -> V_53 , V_2 -> V_87 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_90 ) {
V_5 = F_72 ( V_2 -> V_53 , V_2 -> V_90 ) ;
if ( V_5 )
goto V_91;
}
return 0 ;
V_91:
F_73 ( V_2 -> V_53 ) ;
return V_5 ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 )
F_75 ( V_2 -> V_53 ) ;
F_73 ( V_2 -> V_53 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_92 )
F_62 ( V_2 -> V_92 ) ;
if ( V_2 -> V_93 )
F_62 ( V_2 -> V_93 ) ;
F_62 ( V_2 -> V_94 ) ;
F_62 ( V_2 -> V_95 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_2 T_3 * V_96 ;
T_4 V_30 ;
int V_5 ;
V_30 = V_2 -> V_67 * V_69 ;
V_96 = F_15 ( V_2 , L_6 , L_9 ,
V_30 , & V_2 -> V_95 ) ;
if ( F_27 ( V_96 ) ) {
F_12 ( V_2 -> V_25 , L_8 ) ;
return F_40 ( V_96 ) ;
}
V_30 = V_97 * ( V_2 -> V_16 -> V_98 + 1 ) ;
V_2 -> V_99 = F_16 ( V_2 -> V_26 , L_10 ,
L_11 , V_30 ,
& V_2 -> V_93 ) ;
if ( F_27 ( V_2 -> V_99 ) ) {
if ( F_40 ( V_2 -> V_99 ) != - V_27 ) {
V_5 = F_40 ( V_2 -> V_99 ) ;
goto V_100;
}
V_2 -> V_99 = NULL ;
}
V_2 -> V_101 = F_15 ( V_2 , L_12 ,
L_13 ,
V_102 *
V_2 -> V_103 , & V_2 -> V_92 ) ;
if ( F_27 ( V_2 -> V_101 ) ) {
if ( F_40 ( V_2 -> V_101 ) != - V_27 ) {
V_5 = F_40 ( V_2 -> V_101 ) ;
goto V_104;
}
V_2 -> V_101 = NULL ;
}
V_96 = F_78 ( V_2 -> V_25 , L_14 , 0 , 0 ,
F_79 ( 0 ) , V_105 ,
& V_2 -> V_94 ) ;
if ( F_27 ( V_96 ) ) {
F_12 ( V_2 -> V_25 , L_15 ) ;
V_5 = F_40 ( V_96 ) ;
goto V_106;
}
return 0 ;
V_106:
if ( V_2 -> V_92 )
F_62 ( V_2 -> V_92 ) ;
V_104:
if ( V_2 -> V_93 )
F_62 ( V_2 -> V_93 ) ;
V_100:
F_62 ( V_2 -> V_95 ) ;
return V_5 ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_37 ( & V_2 -> V_64 ) ;
F_54 ( V_2 ) ;
F_65 ( V_2 ) ;
F_76 ( V_2 ) ;
}
static int
F_81 ( struct V_107 * V_25 , struct V_7 * V_8 ,
struct V_15 * V_108 )
{
struct V_9 * V_10 ;
F_82 () ;
V_10 = F_8 ( V_108 , V_8 -> V_109 ) ;
if ( ! V_10 ) {
F_83 ( V_110 , & V_8 -> V_111 ) ;
F_49 ( V_25 , L_16 ,
V_8 -> V_109 ) ;
return - V_112 ;
}
if ( V_10 -> V_113 ) {
F_49 ( V_25 , L_17 , V_8 -> V_109 ) ;
V_8 -> type = V_70 ;
}
memcpy ( V_8 -> V_10 , V_10 , sizeof( * V_10 ) ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_15 * V_108 ;
struct V_34 * V_35 , * V_38 ;
struct V_7 * V_8 ;
F_85 ( & V_2 -> V_114 ) ;
if ( F_41 ( & V_2 -> V_62 ) )
return 0 ;
F_86 () ;
F_46 (port, &pf->ports, port_list)
F_87 ( V_110 , & V_8 -> V_111 ) ;
V_108 = F_88 ( V_2 -> V_25 ) ;
if ( ! V_108 ) {
F_46 (port, &pf->ports, port_list)
if ( F_5 ( V_8 ) )
F_83 ( V_110 , & V_8 -> V_111 ) ;
F_89 () ;
F_12 ( V_2 -> V_25 , L_18 ) ;
return - V_112 ;
}
F_46 (port, &pf->ports, port_list)
if ( F_5 ( V_8 ) )
F_81 ( V_2 -> V_25 , V_8 , V_108 ) ;
F_89 () ;
F_50 ( V_108 ) ;
F_22 (nn, next, &pf->vnics, vnic_list) {
if ( ! V_35 -> V_8 || V_35 -> V_8 -> type != V_70 )
continue;
F_42 ( V_2 , V_35 ) ;
F_17 ( V_2 , V_35 ) ;
}
if ( F_41 ( & V_2 -> V_62 ) )
F_80 ( V_2 ) ;
return 0 ;
}
static void F_90 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_91 ( V_116 , struct V_1 ,
V_117 ) ;
F_92 ( & V_2 -> V_114 ) ;
F_84 ( V_2 ) ;
F_93 ( & V_2 -> V_114 ) ;
}
void F_94 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_53 -> V_2 ;
F_83 ( V_110 , & V_8 -> V_111 ) ;
F_95 ( V_2 -> V_118 , & V_2 -> V_117 ) ;
}
int F_96 ( struct V_7 * V_8 )
{
struct V_107 * V_25 = V_8 -> V_53 -> V_25 ;
struct V_15 * V_108 ;
int V_119 ;
F_87 ( V_110 , & V_8 -> V_111 ) ;
V_108 = F_88 ( V_25 ) ;
if ( ! V_108 ) {
F_83 ( V_110 , & V_8 -> V_111 ) ;
F_12 ( V_25 , L_19 ) ;
return - V_112 ;
}
V_119 = F_81 ( V_25 , V_8 , V_108 ) ;
F_50 ( V_108 ) ;
return V_119 ;
}
int F_97 ( struct V_1 * V_2 )
{
struct V_120 V_54 ;
T_2 T_3 * V_40 , * V_41 ;
struct V_34 * V_35 ;
int V_42 ;
int V_5 ;
F_98 ( & V_2 -> V_117 , F_90 ) ;
if ( ! F_1 ( V_2 ) ) {
F_12 ( V_2 -> V_25 , L_20 ) ;
return - V_121 ;
}
if ( ! V_2 -> V_26 ) {
F_12 ( V_2 -> V_25 , L_21 ,
V_2 -> V_122 ? L_22 : L_23 ) ;
return - V_123 ;
}
F_92 ( & V_2 -> V_114 ) ;
V_2 -> V_67 = F_13 ( V_2 ) ;
if ( ( int ) V_2 -> V_67 < 0 ) {
V_5 = V_2 -> V_67 ;
goto V_124;
}
V_5 = F_77 ( V_2 ) ;
if ( V_5 )
goto V_124;
V_40 = F_99 ( V_2 -> V_95 ) ;
V_41 = F_99 ( V_2 -> V_94 ) ;
if ( ! V_40 || ! V_41 ) {
V_5 = - V_112 ;
goto V_88;
}
F_28 ( & V_54 , V_40 ) ;
if ( V_54 . V_125 || V_54 . V_126 != V_127 ) {
F_12 ( V_2 -> V_25 , L_24 ,
V_54 . V_125 , V_54 . V_126 , V_54 . V_128 , V_54 . V_129 ) ;
V_5 = - V_121 ;
goto V_88;
}
if ( F_100 ( & V_54 , 0 , 0 , 0 , 1 ) ) {
V_42 = 2 ;
F_49 ( V_2 -> V_25 , L_25 ) ;
} else {
switch ( V_54 . V_128 ) {
case 1 ... 5 :
V_42 = 4 ;
break;
default:
F_12 ( V_2 -> V_25 , L_26 ,
V_54 . V_125 , V_54 . V_126 ,
V_54 . V_128 , V_54 . V_129 ) ;
V_5 = - V_121 ;
goto V_88;
}
}
V_5 = F_58 ( V_2 , V_41 , V_42 ) ;
if ( V_5 )
goto V_88;
V_2 -> V_64 = F_101 ( V_2 -> V_52 ) ;
V_5 = F_39 ( V_2 , V_40 , V_41 , V_42 ) ;
if ( V_5 )
goto V_130;
V_5 = F_45 ( V_2 ) ;
if ( V_5 )
goto V_131;
V_5 = F_66 ( V_2 ) ;
if ( V_5 )
goto V_132;
V_5 = F_56 ( V_2 ) ;
if ( V_5 )
goto V_133;
V_5 = F_70 ( V_2 ) ;
if ( V_5 )
goto V_134;
F_93 ( & V_2 -> V_114 ) ;
return 0 ;
V_134:
F_46 (nn, &pf->vnics, vnic_list)
if ( F_23 ( V_35 ) )
F_42 ( V_2 , V_35 ) ;
V_133:
F_68 ( V_2 ) ;
V_132:
F_54 ( V_2 ) ;
V_131:
F_21 ( V_2 ) ;
V_130:
F_37 ( & V_2 -> V_64 ) ;
F_65 ( V_2 ) ;
V_88:
F_76 ( V_2 ) ;
V_124:
F_93 ( & V_2 -> V_114 ) ;
F_102 ( & V_2 -> V_117 ) ;
return V_5 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_92 ( & V_2 -> V_114 ) ;
if ( F_41 ( & V_2 -> V_62 ) )
goto V_135;
F_74 ( V_2 ) ;
F_46 (nn, &pf->vnics, vnic_list)
if ( F_23 ( V_35 ) )
F_42 ( V_2 , V_35 ) ;
F_21 ( V_2 ) ;
F_80 ( V_2 ) ;
V_135:
F_93 ( & V_2 -> V_114 ) ;
F_102 ( & V_2 -> V_117 ) ;
}
