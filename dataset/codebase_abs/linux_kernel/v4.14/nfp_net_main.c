void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 ) ;
if ( ! V_6 ) {
F_3 ( V_4 -> V_7 ) ;
return;
}
F_4 ( V_4 -> V_7 -> V_8 , V_6 -> V_9 ) ;
F_4 ( V_4 -> V_7 -> V_10 , V_6 -> V_9 ) ;
}
static struct V_5 *
F_5 ( struct V_11 * V_12 , unsigned int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_12 && V_14 < V_12 -> V_15 ; V_14 ++ )
if ( V_12 -> V_16 [ V_14 ] . V_13 == V_13 )
return & V_12 -> V_16 [ V_14 ] ;
return NULL ;
}
static int
F_6 ( struct V_1 * V_2 , const char * V_17 ,
unsigned int V_18 )
{
char V_19 [ 256 ] ;
int V_20 = 0 ;
T_1 V_21 ;
snprintf ( V_19 , sizeof( V_19 ) , V_17 , F_7 ( V_2 -> V_22 ) ) ;
V_21 = F_8 ( V_2 -> V_23 , V_19 , & V_20 ) ;
if ( V_20 ) {
if ( V_20 == - V_24 )
return V_18 ;
F_9 ( V_2 -> V_22 , L_1 , V_19 ) ;
return V_20 ;
}
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , L_2 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , L_3 ,
V_25 ) ;
}
static T_2 T_3 *
F_12 ( struct V_1 * V_2 , const char * V_19 , const char * V_26 ,
unsigned int V_27 , struct V_28 * * V_29 )
{
char V_30 [ 256 ] ;
snprintf ( V_30 , sizeof( V_30 ) , V_26 ,
F_7 ( V_2 -> V_22 ) ) ;
return F_13 ( V_2 -> V_23 , V_30 , V_19 , V_27 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
if ( F_15 ( V_32 ) )
F_16 ( V_2 -> V_33 , V_32 ) ;
F_17 ( V_32 -> V_4 ) ;
F_18 ( & V_32 -> V_34 ) ;
V_2 -> V_35 -- ;
F_19 ( V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_31 * V_32 , * V_36 ;
F_21 (nn, next, &pf->vnics, vnic_list)
if ( F_15 ( V_32 ) )
F_14 ( V_2 , V_32 ) ;
}
static struct V_31 *
F_22 ( struct V_1 * V_2 , bool V_37 ,
void T_3 * V_38 , void T_3 * V_39 ,
int V_40 , unsigned int V_41 )
{
T_4 V_42 , V_43 , V_44 , V_45 ;
struct V_31 * V_32 ;
int V_20 ;
V_42 = F_23 ( V_38 + V_46 ) ;
V_43 = F_23 ( V_38 + V_47 ) ;
V_44 = F_23 ( V_38 + V_48 ) ;
V_45 = F_23 ( V_38 + V_49 ) ;
V_32 = F_24 ( V_2 -> V_50 , V_37 , V_44 , V_45 ) ;
if ( F_25 ( V_32 ) )
return V_32 ;
V_32 -> V_33 = V_2 -> V_33 ;
F_26 ( & V_32 -> V_51 , V_38 ) ;
V_32 -> V_52 . V_38 = V_38 ;
V_32 -> V_53 = V_39 + V_42 * V_54 ;
V_32 -> V_55 = V_39 + V_43 * V_54 ;
V_32 -> V_52 . V_56 = 0 ;
V_32 -> V_57 = V_40 ;
V_32 -> V_58 = V_40 ;
if ( V_37 ) {
V_20 = F_27 ( V_2 -> V_33 , V_32 , V_41 ) ;
if ( V_20 ) {
F_19 ( V_32 ) ;
return F_28 ( V_20 ) ;
}
}
V_2 -> V_35 ++ ;
F_29 ( & V_32 -> V_34 , & V_2 -> V_59 ) ;
return V_32 ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_31 * V_32 , unsigned int V_41 )
{
int V_20 ;
V_32 -> V_60 = 1200 ;
V_20 = F_31 ( V_32 ) ;
if ( V_20 )
return V_20 ;
F_32 ( V_32 , V_2 -> V_61 , V_41 ) ;
if ( V_32 -> V_4 ) {
V_20 = F_33 ( V_2 -> V_33 , V_32 -> V_4 ) ;
if ( V_20 )
goto V_62;
}
F_34 ( V_32 ) ;
if ( F_15 ( V_32 ) ) {
V_20 = F_35 ( V_2 -> V_33 , V_32 ) ;
if ( V_20 )
goto V_63;
}
return 0 ;
V_63:
if ( V_32 -> V_4 )
F_36 ( V_32 -> V_4 ) ;
V_62:
F_37 ( & V_32 -> V_64 ) ;
F_38 ( V_32 ) ;
return V_20 ;
}
static int
F_39 ( struct V_1 * V_2 , void T_3 * V_38 ,
void T_3 * V_39 , int V_40 )
{
struct V_31 * V_32 ;
unsigned int V_14 ;
int V_20 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_65 ; V_14 ++ ) {
V_32 = F_22 ( V_2 , true , V_38 , V_39 ,
V_40 , V_14 ) ;
if ( F_25 ( V_32 ) ) {
V_20 = F_40 ( V_32 ) ;
goto V_66;
}
V_38 += V_67 ;
if ( V_32 -> V_4 && V_32 -> V_4 -> type == V_68 ) {
F_14 ( V_2 , V_32 ) ;
continue;
}
}
if ( F_41 ( & V_2 -> V_59 ) )
return - V_69 ;
return 0 ;
V_66:
F_20 ( V_2 ) ;
return V_20 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
if ( F_15 ( V_32 ) )
F_43 ( V_2 -> V_33 , V_32 ) ;
if ( V_32 -> V_4 )
F_36 ( V_32 -> V_4 ) ;
F_37 ( & V_32 -> V_64 ) ;
F_38 ( V_32 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
unsigned int V_70 , V_71 , V_72 , V_73 ;
struct V_31 * V_32 ;
V_70 = 0 ;
F_45 (nn, &pf->vnics, vnic_list)
V_70 += V_74 + V_32 -> V_52 . V_75 ;
V_2 -> V_76 = F_46 ( V_70 , sizeof( * V_2 -> V_76 ) ,
V_77 ) ;
if ( ! V_2 -> V_76 )
return - V_78 ;
V_71 = F_47 ( V_2 -> V_50 , V_2 -> V_76 ,
V_79 * V_2 -> V_35 ,
V_70 ) ;
if ( ! V_71 ) {
F_48 ( V_2 -> V_22 , L_4 ) ;
F_49 ( V_2 -> V_76 ) ;
return - V_78 ;
}
V_73 = V_71 ;
V_72 = V_2 -> V_35 ;
F_45 (nn, &pf->vnics, vnic_list) {
unsigned int V_80 ;
V_80 = F_50 ( V_74 + V_32 -> V_52 . V_75 ,
F_51 ( V_73 , V_72 ) ) ;
F_52 ( V_32 , & V_2 -> V_76 [ V_71 - V_73 ] ,
V_80 ) ;
V_73 -= V_80 ;
V_72 -- ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_50 ) ;
F_49 ( V_2 -> V_76 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
unsigned int V_41 ;
int V_20 ;
V_41 = 0 ;
F_45 (nn, &pf->vnics, vnic_list) {
if ( ! F_15 ( V_32 ) )
continue;
V_20 = F_30 ( V_2 , V_32 , V_41 ) ;
if ( V_20 )
goto V_81;
V_41 ++ ;
}
return 0 ;
V_81:
F_56 (nn, &pf->vnics, vnic_list)
if ( F_15 ( V_32 ) )
F_42 ( V_2 , V_32 ) ;
return V_20 ;
}
static int
F_57 ( struct V_1 * V_2 , T_2 T_3 * V_39 , unsigned int V_40 )
{
T_2 T_3 * V_38 ;
int V_20 ;
V_2 -> V_33 = F_58 ( V_2 , F_11 ( V_2 ) ) ;
if ( F_25 ( V_2 -> V_33 ) )
return F_40 ( V_2 -> V_33 ) ;
V_20 = F_59 ( V_2 -> V_33 ) ;
if ( V_20 )
goto V_82;
if ( ! F_60 ( V_2 -> V_33 ) )
return 0 ;
V_38 = F_12 ( V_2 , L_5 , L_6 ,
V_67 ,
& V_2 -> V_83 ) ;
if ( F_25 ( V_38 ) ) {
F_9 ( V_2 -> V_22 , L_7 ) ;
V_20 = F_40 ( V_38 ) ;
goto V_84;
}
V_2 -> V_85 = F_22 ( V_2 , false , V_38 , V_39 ,
V_40 , 0 ) ;
if ( F_25 ( V_2 -> V_85 ) ) {
V_20 = F_40 ( V_2 -> V_85 ) ;
goto V_86;
}
return 0 ;
V_86:
F_61 ( V_2 -> V_83 ) ;
V_84:
F_62 ( V_2 -> V_33 ) ;
V_82:
F_63 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
return V_20 ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 ) {
F_14 ( V_2 , V_2 -> V_85 ) ;
F_61 ( V_2 -> V_83 ) ;
}
F_62 ( V_2 -> V_33 ) ;
F_63 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_20 ;
if ( ! V_2 -> V_85 )
return 0 ;
V_20 = F_30 ( V_2 , V_2 -> V_85 , 0 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_66 ( V_2 -> V_85 ) ;
if ( V_20 )
goto V_87;
return 0 ;
V_87:
F_42 ( V_2 , V_2 -> V_85 ) ;
return V_20 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_85 )
return;
F_68 ( V_2 -> V_85 ) ;
F_42 ( V_2 , V_2 -> V_85 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_65 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_70 ( V_2 -> V_33 , V_2 -> V_85 ) ;
if ( V_20 )
goto V_88;
if ( V_2 -> V_89 ) {
V_20 = F_71 ( V_2 -> V_33 , V_2 -> V_89 ) ;
if ( V_20 )
goto V_90;
}
return 0 ;
V_90:
F_72 ( V_2 -> V_33 ) ;
V_88:
F_67 ( V_2 ) ;
return V_20 ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 )
F_74 ( V_2 -> V_33 ) ;
F_72 ( V_2 -> V_33 ) ;
F_67 ( V_2 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 )
F_61 ( V_2 -> V_91 ) ;
if ( V_2 -> V_92 )
F_61 ( V_2 -> V_92 ) ;
if ( V_2 -> V_93 )
F_61 ( V_2 -> V_93 ) ;
F_61 ( V_2 -> V_94 ) ;
F_61 ( V_2 -> V_95 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
T_2 T_3 * V_96 ;
T_4 V_27 ;
int V_20 ;
V_27 = V_2 -> V_65 * V_67 ;
V_96 = F_12 ( V_2 , L_8 , L_9 ,
V_27 , & V_2 -> V_95 ) ;
if ( F_25 ( V_96 ) ) {
F_9 ( V_2 -> V_22 , L_10 ) ;
return F_40 ( V_96 ) ;
}
V_27 = V_97 * ( V_2 -> V_12 -> V_98 + 1 ) ;
V_2 -> V_99 = F_13 ( V_2 -> V_23 , L_11 ,
L_12 , V_27 ,
& V_2 -> V_93 ) ;
if ( F_25 ( V_2 -> V_99 ) ) {
if ( F_40 ( V_2 -> V_99 ) != - V_24 ) {
V_20 = F_40 ( V_2 -> V_99 ) ;
goto V_100;
}
V_2 -> V_99 = NULL ;
}
V_2 -> V_101 = F_12 ( V_2 , L_13 ,
L_14 ,
V_102 *
V_2 -> V_103 , & V_2 -> V_92 ) ;
if ( F_25 ( V_2 -> V_101 ) ) {
if ( F_40 ( V_2 -> V_101 ) != - V_24 ) {
V_20 = F_40 ( V_2 -> V_101 ) ;
goto V_104;
}
V_2 -> V_101 = NULL ;
}
V_27 = V_105 * V_2 -> V_103 + V_106 ;
V_2 -> V_107 = F_12 ( V_2 , L_15 ,
L_16 ,
V_27 , & V_2 -> V_91 ) ;
if ( F_25 ( V_2 -> V_107 ) ) {
if ( F_40 ( V_2 -> V_107 ) != - V_24 ) {
V_20 = F_40 ( V_2 -> V_107 ) ;
goto V_108;
}
V_2 -> V_107 = NULL ;
}
V_96 = F_77 ( V_2 -> V_22 , L_17 , 0 , 0 ,
F_78 ( 0 ) , V_109 ,
& V_2 -> V_94 ) ;
if ( F_25 ( V_96 ) ) {
F_9 ( V_2 -> V_22 , L_18 ) ;
V_20 = F_40 ( V_96 ) ;
goto V_110;
}
return 0 ;
V_110:
if ( V_2 -> V_91 )
F_61 ( V_2 -> V_91 ) ;
V_108:
if ( V_2 -> V_92 )
F_61 ( V_2 -> V_92 ) ;
V_104:
if ( V_2 -> V_93 )
F_61 ( V_2 -> V_93 ) ;
V_100:
F_61 ( V_2 -> V_95 ) ;
return V_20 ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
F_37 ( & V_2 -> V_61 ) ;
F_53 ( V_2 ) ;
F_64 ( V_2 ) ;
F_75 ( V_2 ) ;
}
static int
F_80 ( struct V_111 * V_22 , struct V_3 * V_4 ,
struct V_11 * V_112 )
{
struct V_5 * V_6 ;
F_81 () ;
V_6 = F_5 ( V_112 , V_4 -> V_113 ) ;
if ( ! V_6 ) {
F_82 ( V_114 , & V_4 -> V_115 ) ;
F_48 ( V_22 , L_19 ,
V_4 -> V_113 ) ;
return - V_116 ;
}
if ( V_6 -> V_117 ) {
F_48 ( V_22 , L_20 , V_4 -> V_113 ) ;
V_4 -> type = V_68 ;
}
memcpy ( V_4 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
struct V_11 * V_112 ;
struct V_31 * V_32 , * V_36 ;
struct V_3 * V_4 ;
F_84 ( & V_2 -> V_118 ) ;
if ( F_41 ( & V_2 -> V_59 ) )
return 0 ;
F_85 () ;
F_45 (port, &pf->ports, port_list)
F_86 ( V_114 , & V_4 -> V_115 ) ;
V_112 = F_87 ( V_2 -> V_22 ) ;
if ( ! V_112 ) {
F_45 (port, &pf->ports, port_list)
if ( F_2 ( V_4 ) )
F_82 ( V_114 , & V_4 -> V_115 ) ;
F_88 () ;
F_9 ( V_2 -> V_22 , L_21 ) ;
return - V_116 ;
}
F_45 (port, &pf->ports, port_list)
if ( F_2 ( V_4 ) )
F_80 ( V_2 -> V_22 , V_4 , V_112 ) ;
F_88 () ;
F_49 ( V_112 ) ;
F_21 (nn, next, &pf->vnics, vnic_list) {
if ( ! V_32 -> V_4 || V_32 -> V_4 -> type != V_68 )
continue;
F_42 ( V_2 , V_32 ) ;
F_14 ( V_2 , V_32 ) ;
}
if ( F_41 ( & V_2 -> V_59 ) )
F_79 ( V_2 ) ;
return 0 ;
}
static void F_89 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_90 ( V_120 , struct V_1 ,
V_121 ) ;
F_91 ( & V_2 -> V_118 ) ;
F_83 ( V_2 ) ;
F_92 ( & V_2 -> V_118 ) ;
}
void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_33 -> V_2 ;
F_82 ( V_114 , & V_4 -> V_115 ) ;
F_94 ( V_2 -> V_122 , & V_2 -> V_121 ) ;
}
int F_95 ( struct V_3 * V_4 )
{
struct V_111 * V_22 = V_4 -> V_33 -> V_22 ;
struct V_11 * V_112 ;
int V_123 ;
F_86 ( V_114 , & V_4 -> V_115 ) ;
V_112 = F_87 ( V_22 ) ;
if ( ! V_112 ) {
F_82 ( V_114 , & V_4 -> V_115 ) ;
F_9 ( V_22 , L_22 ) ;
return - V_116 ;
}
V_123 = F_80 ( V_22 , V_4 , V_112 ) ;
F_49 ( V_112 ) ;
return V_123 ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_124 V_51 ;
T_2 T_3 * V_38 , * V_39 ;
int V_40 ;
int V_20 ;
F_97 ( & V_2 -> V_121 , F_89 ) ;
if ( ! V_2 -> V_23 ) {
F_9 ( V_2 -> V_22 , L_23 ,
V_2 -> V_125 ? L_24 : L_25 ) ;
return - V_126 ;
}
F_91 ( & V_2 -> V_118 ) ;
V_2 -> V_65 = F_10 ( V_2 ) ;
if ( ( int ) V_2 -> V_65 < 0 ) {
V_20 = V_2 -> V_65 ;
goto V_127;
}
V_20 = F_76 ( V_2 ) ;
if ( V_20 )
goto V_127;
V_38 = F_98 ( V_2 -> V_95 ) ;
V_39 = F_98 ( V_2 -> V_94 ) ;
if ( ! V_38 || ! V_39 ) {
V_20 = - V_116 ;
goto V_86;
}
F_26 ( & V_51 , V_38 ) ;
if ( V_51 . V_128 || V_51 . V_129 != V_130 ) {
F_9 ( V_2 -> V_22 , L_26 ,
V_51 . V_128 , V_51 . V_129 , V_51 . V_131 , V_51 . V_132 ) ;
V_20 = - V_126 ;
goto V_86;
}
if ( F_99 ( & V_51 , 0 , 0 , 0 , 1 ) ) {
V_40 = 2 ;
F_48 ( V_2 -> V_22 , L_27 ) ;
} else {
switch ( V_51 . V_131 ) {
case 1 ... 5 :
V_40 = 4 ;
break;
default:
F_9 ( V_2 -> V_22 , L_28 ,
V_51 . V_128 , V_51 . V_129 ,
V_51 . V_131 , V_51 . V_132 ) ;
V_20 = - V_126 ;
goto V_86;
}
}
V_20 = F_57 ( V_2 , V_39 , V_40 ) ;
if ( V_20 )
goto V_86;
V_2 -> V_61 = F_100 ( V_2 -> V_50 ) ;
V_20 = F_39 ( V_2 , V_38 , V_39 , V_40 ) ;
if ( V_20 )
goto V_133;
V_20 = F_44 ( V_2 ) ;
if ( V_20 )
goto V_134;
V_20 = F_69 ( V_2 ) ;
if ( V_20 )
goto V_135;
V_20 = F_55 ( V_2 ) ;
if ( V_20 )
goto V_136;
F_92 ( & V_2 -> V_118 ) ;
return 0 ;
V_136:
F_73 ( V_2 ) ;
V_135:
F_53 ( V_2 ) ;
V_134:
F_20 ( V_2 ) ;
V_133:
F_37 ( & V_2 -> V_61 ) ;
F_64 ( V_2 ) ;
V_86:
F_75 ( V_2 ) ;
V_127:
F_92 ( & V_2 -> V_118 ) ;
F_101 ( & V_2 -> V_121 ) ;
return V_20 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
F_91 ( & V_2 -> V_118 ) ;
if ( F_41 ( & V_2 -> V_59 ) )
goto V_137;
F_45 (nn, &pf->vnics, vnic_list)
if ( F_15 ( V_32 ) )
F_42 ( V_2 , V_32 ) ;
F_20 ( V_2 ) ;
F_79 ( V_2 ) ;
V_137:
F_92 ( & V_2 -> V_118 ) ;
F_101 ( & V_2 -> V_121 ) ;
}
