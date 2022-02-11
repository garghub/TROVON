static struct V_1 * T_1 F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
static struct V_3 * F_3 ( T_2 V_4 , T_2 V_5 )
{
struct V_3 * V_3 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_3 = F_2 ( sizeof( struct V_3 ) , V_2 ) ;
if ( ! V_3 )
goto error;
V_7 = F_4 ( V_4 , sizeof( struct V_6 ) , V_2 ) ;
if ( ! V_7 )
goto V_10;
V_3 -> V_7 = V_7 ;
V_9 = F_4 ( V_5 , sizeof( struct V_8 ) , V_2 ) ;
if ( ! V_9 )
goto V_11;
V_3 -> V_9 = V_9 ;
return V_3 ;
V_11:
F_5 ( V_3 -> V_7 ) ;
V_10:
F_5 ( V_3 ) ;
error:
return NULL ;
}
static void F_6 ( struct V_3 * V_3 )
{
F_5 ( V_3 -> V_7 ) ;
F_5 ( V_3 -> V_9 ) ;
F_5 ( V_3 ) ;
}
static struct V_12 * T_1 F_7 ( void )
{
return F_2 ( sizeof( struct V_12 ) , V_2 ) ;
}
static struct V_13 * F_8 ( void )
{
return F_2 ( sizeof( struct V_13 ) , V_2 ) ;
}
static void T_1 F_9 ( void )
{
struct V_14 * V_15 ;
F_10 (ptr, &bus_info_head, bus_info_list) {
F_11 ( L_1 , V_16 , V_15 -> V_17 ) ;
F_11 ( L_2 , V_16 , V_15 -> V_18 ) ;
F_11 ( L_3 , V_16 , V_15 -> V_4 ) ;
F_11 ( L_4 , V_16 , V_15 -> V_19 ) ;
F_11 ( L_5 , V_16 , V_15 -> V_20 ) ;
F_11 ( L_6 , V_16 , V_15 -> V_21 ) ;
F_11 ( L_7 , V_16 , V_15 -> V_22 ) ;
F_11 ( L_8 , V_16 , V_15 -> V_23 ) ;
F_11 ( L_9 , V_16 , V_15 -> V_24 ) ;
F_11 ( L_10 , V_16 , V_15 -> V_25 ) ;
F_11 ( L_11 , V_16 , V_15 -> V_26 ) ;
}
}
static void F_12 ( void )
{
struct V_27 * V_15 ;
F_11 ( L_12 ) ;
F_10 (ptr, &rio_lo_head, rio_detail_list) {
F_11 ( L_13 , V_16 , V_15 -> V_28 ) ;
F_11 ( L_14 , V_16 , V_15 -> V_29 ) ;
F_11 ( L_15 , V_16 , V_15 -> V_30 ) ;
F_11 ( L_16 , V_16 , V_15 -> V_31 ) ;
F_11 ( L_17 , V_16 , V_15 -> V_32 ) ;
F_11 ( L_18 , V_16 , V_15 -> V_33 ) ;
}
}
static void F_13 ( void )
{
struct V_27 * V_15 ;
F_11 ( L_19 , V_16 ) ;
F_10 (ptr, &rio_vg_head, rio_detail_list) {
F_11 ( L_13 , V_16 , V_15 -> V_28 ) ;
F_11 ( L_14 , V_16 , V_15 -> V_29 ) ;
F_11 ( L_15 , V_16 , V_15 -> V_30 ) ;
F_11 ( L_16 , V_16 , V_15 -> V_31 ) ;
F_11 ( L_17 , V_16 , V_15 -> V_32 ) ;
F_11 ( L_18 , V_16 , V_15 -> V_33 ) ;
}
}
static void T_1 F_14 ( void )
{
struct V_13 * V_15 ;
F_10 (ptr, &ibmphp_ebda_pci_rsrc_head, ebda_pci_rsrc_list) {
F_11 ( L_20 ,
V_16 , V_15 -> V_34 , V_15 -> V_35 , V_15 -> V_36 , V_15 -> V_37 , V_15 -> V_38 ) ;
}
}
static void T_1 F_15 ( void )
{
struct V_39 * V_15 ;
F_10 (ptr, &ibmphp_slot_head, ibm_slot_list) {
F_11 ( L_21 , V_16 , V_15 -> V_40 ) ;
}
}
static void T_1 F_16 ( void )
{
struct V_41 * V_15 ;
F_11 ( L_19 , V_16 ) ;
F_10 (ptr, &opt_vg_head, opt_rio_list) {
F_11 ( L_22 , V_16 , V_15 -> V_29 ) ;
F_11 ( L_23 , V_16 , V_15 -> V_33 ) ;
F_11 ( L_24 , V_16 , V_15 -> V_31 ) ;
F_11 ( L_25 , V_16 , V_15 -> V_42 ) ;
}
}
static void T_1 F_17 ( void )
{
struct V_3 * V_43 ;
T_3 V_44 ;
F_10 (hpc_ptr, &ebda_hpc_head, ebda_hpc_list) {
for ( V_44 = 0 ; V_44 < V_43 -> V_4 ; V_44 ++ ) {
F_11 ( L_26 , V_16 , V_43 -> V_7 [ V_44 ] . V_45 ) ;
F_11 ( L_27 , V_16 , V_43 -> V_7 [ V_44 ] . V_46 ) ;
F_11 ( L_28 , V_16 , V_43 -> V_7 [ V_44 ] . V_47 ) ;
F_11 ( L_29 , V_16 , V_43 -> V_7 [ V_44 ] . V_48 ) ;
}
for ( V_44 = 0 ; V_44 < V_43 -> V_5 ; V_44 ++ )
F_11 ( L_30 , V_16 , V_43 -> V_9 [ V_44 ] . V_35 ) ;
F_11 ( L_31 , V_16 , V_43 -> V_49 ) ;
switch ( V_43 -> V_49 ) {
case 1 :
F_11 ( L_32 , V_16 , V_43 -> V_50 . V_51 . V_52 ) ;
F_11 ( L_33 , V_16 , V_43 -> V_50 . V_51 . V_36 ) ;
F_11 ( L_34 , V_16 , V_43 -> V_53 ) ;
break;
case 0 :
F_11 ( L_35 , V_16 , V_43 -> V_50 . V_54 . V_55 ) ;
F_11 ( L_36 , V_16 , V_43 -> V_50 . V_54 . V_56 ) ;
F_11 ( L_34 , V_16 , V_43 -> V_53 ) ;
break;
case 2 :
case 4 :
F_11 ( L_37 , V_16 , V_43 -> V_50 . V_57 . V_58 ) ;
F_11 ( L_38 , V_16 , V_43 -> V_50 . V_57 . V_59 ) ;
F_11 ( L_34 , V_16 , V_43 -> V_53 ) ;
break;
}
}
}
int T_1 F_18 ( void )
{
T_4 V_60 , V_61 , V_62 , V_63 , V_64 ;
T_3 V_65 , V_66 , V_67 , V_68 , V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
int V_75 = 0 ;
V_62 = 0 ;
V_63 = 0 ;
V_76 = F_19 ( ( 0x40 << 4 ) + 0x0e , 2 ) ;
if ( ! V_76 )
return - V_77 ;
V_65 = F_20 ( V_76 ) ;
F_21 ( V_76 ) ;
F_11 ( L_39 , V_65 ) ;
V_76 = F_19 ( V_65 << 4 , 1 ) ;
if ( ! V_76 )
return - V_77 ;
V_64 = F_22 ( V_76 ) ;
F_21 ( V_76 ) ;
F_11 ( L_40 , V_64 ) ;
if ( V_64 == 0 )
return - V_77 ;
V_76 = F_19 ( V_65 << 4 , ( V_64 * 1024 ) ) ;
if ( ! V_76 )
return - V_77 ;
V_67 = 0x180 ;
for (; ; ) {
V_68 = V_67 ;
if ( F_23 ( V_68 > ( V_64 * 1024 - 4 ) ,
L_41 ) )
break;
V_67 = F_20 ( V_76 + V_68 ) ;
V_68 += 2 ;
if ( V_67 == 0 )
break;
V_69 = F_20 ( V_76 + V_68 ) ;
V_68 += 2 ;
if ( V_69 != 0x4853 && V_69 != 0x4752 )
continue;
if ( V_69 == 0x4853 ) {
F_11 ( L_42 ) ;
F_11 ( L_43 , V_69 ) ;
V_60 = F_22 ( V_76 + V_68 ) ;
V_68 += 1 ;
if ( V_60 != 4 )
goto V_78;
F_11 ( L_44 , V_60 ) ;
V_74 = V_68 ;
V_70 = V_74 ;
V_71 = F_20 ( V_76 + V_70 ) ;
V_70 += 2 ;
V_72 = F_20 ( V_76 + V_70 ) ;
V_70 += 2 ;
if ( V_72 != 0x5243 )
goto V_78;
V_61 = F_22 ( V_76 + V_70 ) ;
V_70 += 1 ;
V_79 = F_1 () ;
if ( ! V_79 ) {
V_75 = - V_77 ;
goto V_80;
}
V_79 -> V_60 = V_60 ;
V_79 -> V_61 = V_61 ;
V_79 -> V_81 = V_70 ;
F_11 ( L_45 ) ;
F_11 ( L_44 , V_60 ) ;
F_11 ( L_46 , V_61 ) ;
F_11 ( L_47 , V_70 ) ;
V_70 = V_74 + V_71 ;
V_75 = F_20 ( V_76 + V_70 ) ;
V_70 += 2 ;
V_73 = F_20 ( V_76 + V_70 ) ;
V_70 += 2 ;
if ( V_73 != 0x5245 )
goto V_78;
V_66 = F_20 ( V_76 + V_70 ) ;
V_70 += 2 ;
V_82 = F_7 () ;
if ( ! V_82 ) {
V_75 = - V_77 ;
goto V_80;
}
V_82 -> V_60 = V_60 ;
V_82 -> V_66 = V_66 ;
V_82 -> V_81 = V_70 ;
F_11 ( L_48 ) ;
F_11 ( L_49 , V_60 ) ;
F_11 ( L_50 , V_66 ) ;
F_11 ( L_51 , V_70 ) ;
V_63 = 1 ;
} else {
F_11 ( L_52 ) ;
F_11 ( L_53 , V_69 ) ;
V_83 = F_2 ( sizeof( struct V_84 ) , V_2 ) ;
if ( ! V_83 ) {
V_75 = - V_77 ;
goto V_80;
}
V_83 -> V_85 = F_22 ( V_76 + V_68 ) ;
V_83 -> V_86 = F_22 ( V_76 + V_68 + 1 ) ;
V_83 -> V_87 = F_22 ( V_76 + V_68 + 2 ) ;
V_83 -> V_68 = V_68 + 3 ;
F_11 ( L_54 ) ;
F_11 ( L_55 ,
V_83 -> V_85 , V_83 -> V_86 ,
V_83 -> V_87 , V_83 -> V_68 ) ;
V_62 = 1 ;
}
}
if ( ! V_63 && ! V_62 )
goto V_78;
if ( V_83 ) {
if ( V_62 && V_83 -> V_85 == 3 ) {
V_75 = F_24 () ;
if ( V_75 )
goto V_80;
}
}
V_75 = F_25 () ;
if ( V_75 )
goto V_80;
V_75 = F_26 () ;
goto V_80;
V_78:
V_75 = - V_88 ;
V_80:
F_21 ( V_76 ) ;
return V_75 ;
}
static int T_1 F_24 ( void )
{
T_3 V_68 ;
T_4 V_89 ;
struct V_27 * V_90 ;
V_68 = V_83 -> V_68 ;
V_68 += 12 * V_83 -> V_86 ;
for ( V_89 = 0 ; V_89 < V_83 -> V_87 ; V_89 ++ ) {
V_90 = F_2 ( sizeof( struct V_27 ) , V_2 ) ;
if ( ! V_90 )
return - V_77 ;
V_90 -> V_28 = F_22 ( V_76 + V_68 ) ;
V_90 -> V_91 = F_27 ( V_76 + V_68 + 1 ) ;
V_90 -> V_29 = F_22 ( V_76 + V_68 + 5 ) ;
V_90 -> V_30 = F_22 ( V_76 + V_68 + 6 ) ;
V_90 -> V_92 = F_22 ( V_76 + V_68 + 7 ) ;
V_90 -> V_93 = F_22 ( V_76 + V_68 + 8 ) ;
V_90 -> V_94 = F_22 ( V_76 + V_68 + 9 ) ;
V_90 -> V_95 = F_22 ( V_76 + V_68 + 10 ) ;
V_90 -> V_31 = F_22 ( V_76 + V_68 + 11 ) ;
V_90 -> V_96 = F_22 ( V_76 + V_68 + 12 ) ;
V_90 -> V_32 = F_22 ( V_76 + V_68 + 13 ) ;
V_90 -> V_33 = F_22 ( V_76 + V_68 + 14 ) ;
if ( V_90 -> V_29 == 4 || V_90 -> V_29 == 5 )
F_28 ( & V_90 -> V_97 , & V_98 ) ;
else if ( V_90 -> V_29 == 6 || V_90 -> V_29 == 7 )
F_28 ( & V_90 -> V_97 , & V_99 ) ;
else
F_5 ( V_90 ) ;
V_68 += 15 ;
}
F_12 () ;
F_13 () ;
return 0 ;
}
static struct V_41 * F_29 ( T_4 V_33 )
{
struct V_41 * V_15 ;
F_10 (ptr, &opt_vg_head, opt_rio_list) {
if ( V_15 -> V_33 == V_33 )
return V_15 ;
}
return NULL ;
}
static int T_1 F_30 ( void )
{
struct V_41 * V_100 = NULL ;
struct V_27 * V_90 = NULL ;
F_10 (rio_detail_ptr, &rio_vg_head, rio_detail_list) {
V_100 = F_29 ( V_90 -> V_33 ) ;
if ( ! V_100 ) {
V_100 = F_2 ( sizeof( struct V_41 ) , V_2 ) ;
if ( ! V_100 )
return - V_77 ;
V_100 -> V_29 = V_90 -> V_29 ;
V_100 -> V_33 = V_90 -> V_33 ;
V_100 -> V_31 = V_90 -> V_31 ;
V_100 -> V_42 = V_90 -> V_31 ;
F_28 ( & V_100 -> V_101 , & V_102 ) ;
} else {
V_100 -> V_31 = F_31 ( V_100 -> V_31 , V_90 -> V_31 ) ;
V_100 -> V_42 = F_32 ( V_100 -> V_42 , V_90 -> V_31 ) ;
}
}
F_16 () ;
return 0 ;
}
static struct V_103 * F_33 ( T_4 V_33 )
{
struct V_103 * V_15 ;
F_10 (ptr, &opt_lo_head, opt_rio_lo_list) {
if ( V_15 -> V_33 == V_33 )
return V_15 ;
}
return NULL ;
}
static int F_34 ( void )
{
struct V_103 * V_104 = NULL ;
struct V_27 * V_90 = NULL ;
F_10 (rio_detail_ptr, &rio_lo_head, rio_detail_list) {
V_104 = F_33 ( V_90 -> V_33 ) ;
if ( ! V_104 ) {
V_104 = F_2 ( sizeof( struct V_103 ) , V_2 ) ;
if ( ! V_104 )
return - V_77 ;
V_104 -> V_29 = V_90 -> V_29 ;
V_104 -> V_33 = V_90 -> V_33 ;
V_104 -> V_31 = V_90 -> V_31 ;
V_104 -> V_42 = V_90 -> V_31 ;
V_104 -> V_105 = 1 ;
F_28 ( & V_104 -> V_106 , & V_107 ) ;
} else {
V_104 -> V_31 = F_31 ( V_104 -> V_31 , V_90 -> V_31 ) ;
V_104 -> V_42 = F_32 ( V_104 -> V_42 , V_90 -> V_31 ) ;
V_104 -> V_105 = 2 ;
}
}
return 0 ;
}
static int V_31 ( T_4 V_45 , T_4 V_108 , T_4 V_109 )
{
struct V_41 * V_110 = NULL ;
struct V_103 * V_111 = NULL ;
int V_75 = 0 ;
if ( ! V_109 ) {
F_10 (opt_vg_ptr, &opt_vg_head, opt_rio_list) {
if ( ( V_108 < V_110 -> V_31 ) && ( V_45 >= V_110 -> V_31 ) ) {
V_75 = - V_88 ;
break;
}
}
} else {
F_10 (opt_lo_ptr, &opt_lo_head, opt_rio_lo_list) {
if ( ( V_108 < V_111 -> V_31 ) && ( V_45 >= V_111 -> V_31 ) ) {
V_75 = - V_88 ;
break;
}
}
}
return V_75 ;
}
static struct V_103 * F_35 ( T_4 V_45 )
{
struct V_103 * V_111 ;
F_10 (opt_lo_ptr, &opt_lo_head, opt_rio_lo_list) {
if ( ( V_45 >= V_111 -> V_31 ) && ( ! V_31 ( V_45 , V_111 -> V_31 , 1 ) ) )
return V_111 ;
}
return NULL ;
}
static struct V_41 * F_36 ( T_4 V_45 )
{
struct V_41 * V_110 ;
F_10 (opt_vg_ptr, &opt_vg_head, opt_rio_list) {
if ( ( V_45 >= V_110 -> V_31 ) && ( ! V_31 ( V_45 , V_110 -> V_31 , 0 ) ) )
return V_110 ;
}
return NULL ;
}
static T_4 F_37 ( T_4 V_45 )
{
T_4 V_108 = 1 ;
struct V_39 * V_112 ;
F_10 (slot_cur, &ibmphp_slot_head, ibm_slot_list) {
if ( V_112 -> V_113 ) {
if ( ( V_112 -> V_113 -> V_49 != 4 ) && ( V_112 -> V_113 -> V_114 > V_108 ) && ( V_45 > V_112 -> V_113 -> V_114 ) )
V_108 = V_112 -> V_113 -> V_114 ;
}
}
return V_108 + 1 ;
}
static char * F_38 ( struct V_39 * V_112 )
{
struct V_41 * V_110 = NULL ;
struct V_103 * V_111 = NULL ;
static char V_115 [ V_116 ] ;
int V_117 = 0 ;
T_4 V_40 = 1 ;
T_4 V_108 = 1 ;
T_4 V_45 ;
T_4 V_118 = 0 ;
if ( ! V_112 ) {
F_39 ( L_56 ) ;
return NULL ;
}
V_45 = V_112 -> V_40 ;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
if ( V_83 ) {
if ( V_83 -> V_85 == 3 ) {
V_110 = F_36 ( V_45 ) ;
V_111 = F_35 ( V_45 ) ;
}
}
if ( V_110 ) {
if ( V_111 ) {
if ( ( V_45 - V_110 -> V_31 ) > ( V_45 - V_111 -> V_31 ) ) {
V_40 = V_111 -> V_33 ;
V_108 = V_111 -> V_31 ;
V_117 = 1 ;
} else {
V_108 = V_110 -> V_31 ;
V_40 = V_110 -> V_33 ;
V_117 = 0 ;
}
} else {
V_108 = V_110 -> V_31 ;
V_40 = V_110 -> V_33 ;
V_117 = 0 ;
}
++ V_118 ;
} else if ( V_111 ) {
V_40 = V_111 -> V_33 ;
V_108 = V_111 -> V_31 ;
V_117 = 1 ;
++ V_118 ;
} else if ( V_83 ) {
if ( V_83 -> V_85 == 3 ) {
return NULL ;
}
}
if ( ! V_118 ) {
if ( V_112 -> V_113 -> V_49 == 4 ) {
V_108 = F_37 ( V_45 ) ;
V_117 = 1 ;
} else {
V_117 = 0 ;
}
}
sprintf ( V_115 , L_57 ,
V_117 == 0 ? L_58 : L_59 ,
V_40 , V_45 - V_108 + 1 ) ;
return V_115 ;
}
static int F_40 ( struct V_119 * V_119 )
{
struct V_39 * V_39 ;
int V_75 = 0 ;
if ( ! V_119 || ! V_119 -> V_120 )
return - V_121 ;
V_39 = V_119 -> V_120 ;
V_75 = F_41 ( V_39 , V_122 , NULL ) ;
if ( V_75 )
return V_75 ;
V_119 -> V_123 -> V_124 = F_42 ( V_39 -> V_96 ) ;
V_119 -> V_123 -> V_125 = F_43 ( V_39 -> V_96 , V_39 -> V_126 ) ;
V_119 -> V_123 -> V_127 = F_44 ( V_39 -> V_96 ) ;
if ( F_45 ( V_39 -> V_96 ) )
V_119 -> V_123 -> V_128 = 1 ;
else
V_119 -> V_123 -> V_128 = 0 ;
return V_75 ;
}
static void F_46 ( struct V_119 * V_119 )
{
struct V_39 * V_39 ;
if ( ! V_119 || ! V_119 -> V_120 )
return;
V_39 = V_119 -> V_120 ;
F_5 ( V_39 -> V_119 -> V_123 ) ;
F_5 ( V_39 -> V_119 ) ;
V_39 -> V_113 = NULL ;
V_39 -> V_129 = NULL ;
F_47 ( & V_39 , - 1 ) ;
F_5 ( V_39 ) ;
}
static int T_1 F_25 ( void )
{
T_3 V_130 , V_131 , V_132 ;
T_4 V_133 , V_134 , V_135 ;
T_3 V_136 , V_39 , V_52 ;
T_3 V_45 , V_35 , V_44 ;
struct V_119 * V_137 ;
struct V_3 * V_43 ;
struct V_8 * V_138 ;
struct V_6 * V_139 ;
struct V_14 * V_140 , * V_141 ;
int V_75 ;
struct V_39 * V_142 ;
char V_143 [ V_116 ] ;
V_130 = V_79 -> V_81 ;
for ( V_136 = 0 ; V_136 < V_79 -> V_61 ; V_136 ++ ) {
V_135 = 1 ;
V_133 = F_22 ( V_76 + V_130 ) ;
V_130 += 1 ;
V_45 = F_22 ( V_76 + V_130 ) ;
V_130 += 1 ;
V_131 = V_130 ;
V_130 += ( V_45 * 4 ) ;
V_35 = F_22 ( V_76 + V_130 ) ;
V_130 += 1 ;
V_132 = V_130 ;
V_130 += ( V_35 * 9 ) ;
V_134 = F_22 ( V_76 + V_130 ) ;
V_130 += 1 ;
V_43 = F_3 ( V_45 , V_35 ) ;
if ( ! V_43 ) {
V_75 = - V_77 ;
goto V_144;
}
V_43 -> V_133 = V_133 ;
V_43 -> V_145 = V_136 ;
V_43 -> V_4 = V_45 ;
V_43 -> V_5 = V_35 ;
F_11 ( L_60 ) ;
F_11 ( L_61 , V_133 ) ;
F_11 ( L_62 , V_43 -> V_145 ) ;
F_11 ( L_63 , V_45 ) ;
F_11 ( L_64 , V_35 ) ;
V_139 = V_43 -> V_7 ;
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ ) {
V_139 -> V_45 = F_22 ( V_76 + V_131 ) ;
V_139 -> V_46 = F_22 ( V_76 + V_131 + V_45 ) ;
V_139 -> V_47 = F_22 ( V_76 + V_131 + 2 * V_45 ) ;
V_139 -> V_48 = F_22 ( V_76 + V_131 + 3 * V_45 ) ;
V_141 = F_48 ( V_139 -> V_46 ) ;
if ( ! V_141 ) {
V_140 = F_2 ( sizeof( struct V_14 ) , V_2 ) ;
if ( ! V_140 ) {
V_75 = - V_77 ;
goto V_146;
}
V_140 -> V_17 = V_139 -> V_45 ;
V_140 -> V_18 = V_139 -> V_45 ;
V_140 -> V_4 += 1 ;
V_140 -> V_19 = V_139 -> V_46 ;
V_140 -> V_44 = V_135 ++ ;
V_140 -> V_20 = 0xff ;
V_140 -> V_147 = 0xff ;
V_140 -> V_21 = V_43 -> V_133 ;
F_49 ( & V_140 -> V_148 , & V_149 ) ;
} else {
V_141 -> V_17 = F_31 ( V_141 -> V_17 , V_139 -> V_45 ) ;
V_141 -> V_18 = F_32 ( V_141 -> V_18 , V_139 -> V_45 ) ;
V_141 -> V_4 += 1 ;
}
V_139 ++ ;
V_131 += 1 ;
}
V_138 = V_43 -> V_9 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
V_138 -> V_35 = F_22 ( V_76 + V_132 + V_52 ) ;
V_138 -> V_22 = F_22 ( V_76 + V_132 + V_35 + 8 * V_52 ) ;
V_138 -> V_23 = F_22 ( V_76 + V_132 + V_35 + 8 * V_52 + 1 ) ;
V_138 -> V_24 = F_22 ( V_76 + V_132 + V_35 + 8 * V_52 + 2 ) ;
V_138 -> V_25 = F_22 ( V_76 + V_132 + V_35 + 8 * V_52 + 3 ) ;
V_138 -> V_26 = F_22 ( V_76 + V_132 + V_35 + 8 * V_52 + 4 ) ;
V_141 = F_48 ( V_138 -> V_35 ) ;
if ( V_141 ) {
V_141 -> V_22 = V_138 -> V_22 ;
V_141 -> V_23 = V_138 -> V_23 ;
V_141 -> V_24 = V_138 -> V_24 ;
V_141 -> V_25 = V_138 -> V_25 ;
V_141 -> V_26 = V_138 -> V_26 ;
}
V_138 ++ ;
}
V_43 -> V_49 = V_134 ;
switch ( V_43 -> V_49 ) {
case 1 :
V_43 -> V_50 . V_51 . V_52 = F_22 ( V_76 + V_130 ) ;
V_43 -> V_50 . V_51 . V_36 = F_22 ( V_76 + V_130 + 1 ) ;
V_43 -> V_53 = F_22 ( V_76 + V_130 + 2 ) ;
V_130 += 3 ;
F_11 ( L_65 ,
V_43 -> V_50 . V_51 . V_52 ,
V_43 -> V_50 . V_51 . V_36 , V_43 -> V_53 ) ;
break;
case 0 :
V_43 -> V_50 . V_54 . V_55 = F_20 ( V_76 + V_130 ) ;
V_43 -> V_50 . V_54 . V_56 = F_20 ( V_76 + V_130 + 2 ) ;
if ( ! F_50 ( V_43 -> V_50 . V_54 . V_55 ,
( V_43 -> V_50 . V_54 . V_56 - V_43 -> V_50 . V_54 . V_55 + 1 ) ,
L_66 ) ) {
V_75 = - V_88 ;
goto V_146;
}
V_43 -> V_53 = F_22 ( V_76 + V_130 + 4 ) ;
V_130 += 5 ;
break;
case 2 :
case 4 :
V_43 -> V_50 . V_57 . V_58 = F_27 ( V_76 + V_130 ) ;
V_43 -> V_50 . V_57 . V_59 = F_22 ( V_76 + V_130 + 4 ) ;
V_43 -> V_53 = F_22 ( V_76 + V_130 + 5 ) ;
V_130 += 6 ;
break;
default:
V_75 = - V_88 ;
goto V_146;
}
F_30 () ;
F_34 () ;
V_43 -> V_150 = 0xff ;
V_43 -> V_151 = 0xff ;
V_43 -> V_152 = V_43 -> V_7 [ 0 ] . V_45 ;
V_43 -> V_114 = V_43 -> V_7 [ V_45 - 1 ] . V_45 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_4 ; V_44 ++ ) {
V_137 = F_2 ( sizeof( * V_137 ) , V_2 ) ;
if ( ! V_137 ) {
V_75 = - V_77 ;
goto V_146;
}
V_137 -> V_123 = F_2 ( sizeof( struct V_153 ) , V_2 ) ;
if ( ! V_137 -> V_123 ) {
V_75 = - V_77 ;
goto V_154;
}
V_142 = F_2 ( sizeof( * V_142 ) , V_2 ) ;
if ( ! V_142 ) {
V_75 = - V_77 ;
goto V_155;
}
V_142 -> V_118 = 1 ;
V_142 -> V_156 = V_43 -> V_7 [ V_44 ] . V_48 ;
if ( ( V_43 -> V_7 [ V_44 ] . V_48 & V_157 ) == V_157 )
V_142 -> V_158 = 3 ;
else if ( ( V_43 -> V_7 [ V_44 ] . V_48 & V_159 ) == V_159 )
V_142 -> V_158 = 2 ;
else if ( ( V_43 -> V_7 [ V_44 ] . V_48 & V_160 ) == V_160 )
V_142 -> V_158 = 1 ;
if ( ( V_43 -> V_7 [ V_44 ] . V_48 & V_161 ) == V_161 )
V_142 -> V_162 = 1 ;
else
V_142 -> V_162 = 0 ;
V_142 -> V_52 = V_43 -> V_7 [ V_44 ] . V_46 ;
V_140 = F_48 ( V_43 -> V_7 [ V_44 ] . V_46 ) ;
if ( ! V_140 ) {
F_5 ( V_142 ) ;
V_75 = - V_88 ;
goto error;
}
V_142 -> V_129 = V_140 ;
V_140 = NULL ;
V_142 -> V_113 = V_43 ;
V_142 -> V_163 = V_43 -> V_7 [ V_44 ] . V_47 ;
V_142 -> V_40 = V_43 -> V_7 [ V_44 ] . V_45 ;
V_142 -> V_119 = V_137 ;
V_137 -> V_120 = V_142 ;
V_137 -> V_164 = F_46 ;
V_75 = F_40 ( V_137 ) ;
if ( V_75 )
goto error;
V_75 = F_51 ( (struct V_39 * * ) & V_137 -> V_120 ) ;
if ( V_75 )
goto error;
V_137 -> V_165 = & V_166 ;
F_28 ( & ( (struct V_39 * ) ( V_137 -> V_120 ) ) -> V_167 , & V_168 ) ;
}
F_9 () ;
F_28 ( & V_43 -> V_1 , & V_169 ) ;
}
F_10 (tmp_slot, &ibmphp_slot_head, ibm_slot_list) {
snprintf ( V_143 , V_116 , L_67 , F_38 ( V_142 ) ) ;
F_52 ( V_142 -> V_119 ,
F_53 ( 0 , V_142 -> V_52 ) , V_142 -> V_170 , V_143 ) ;
}
F_17 () ;
F_15 () ;
return 0 ;
error:
F_5 ( V_137 -> V_120 ) ;
V_155:
F_5 ( V_137 -> V_123 ) ;
V_154:
F_5 ( V_137 ) ;
V_146:
F_6 ( V_43 ) ;
V_144:
F_21 ( V_76 ) ;
return V_75 ;
}
static int T_1 F_26 ( void )
{
T_3 V_130 ;
short V_171 ;
T_4 type , V_34 ;
struct V_13 * V_172 ;
V_130 = V_82 -> V_81 ;
F_11 ( L_68 ) ;
F_11 ( L_69 , V_82 -> V_81 ) ;
for ( V_171 = 0 ; V_171 < V_82 -> V_66 ; V_171 ++ ) {
type = F_22 ( V_76 + V_130 ) ;
V_130 += 1 ;
V_34 = type & V_173 ;
if ( V_34 == V_174 ) {
V_172 = F_8 () ;
if ( ! V_172 ) {
F_21 ( V_76 ) ;
return - V_77 ;
}
V_172 -> V_34 = type ;
V_172 -> V_35 = F_22 ( V_76 + V_130 ) ;
V_172 -> V_36 = F_22 ( V_76 + V_130 + 1 ) ;
V_172 -> V_37 = F_20 ( V_76 + V_130 + 2 ) ;
V_172 -> V_38 = F_20 ( V_76 + V_130 + 4 ) ;
V_130 += 6 ;
F_11 ( L_70 ) ;
F_11 ( L_71 ,
V_172 -> V_34 , V_172 -> V_35 , V_172 -> V_36 , V_172 -> V_37 , V_172 -> V_38 ) ;
F_28 ( & V_172 -> V_175 , & V_176 ) ;
}
if ( V_34 == V_177 || V_34 == V_178 ) {
V_172 = F_8 () ;
if ( ! V_172 ) {
F_21 ( V_76 ) ;
return - V_77 ;
}
V_172 -> V_34 = type ;
V_172 -> V_35 = F_22 ( V_76 + V_130 ) ;
V_172 -> V_36 = F_22 ( V_76 + V_130 + 1 ) ;
V_172 -> V_37 = F_27 ( V_76 + V_130 + 2 ) ;
V_172 -> V_38 = F_27 ( V_76 + V_130 + 6 ) ;
V_130 += 10 ;
F_11 ( L_72 ) ;
F_11 ( L_71 ,
V_172 -> V_34 , V_172 -> V_35 , V_172 -> V_36 , V_172 -> V_37 , V_172 -> V_38 ) ;
F_28 ( & V_172 -> V_175 , & V_176 ) ;
}
}
F_5 ( V_82 ) ;
V_82 = NULL ;
F_14 () ;
return 0 ;
}
T_3 F_54 ( void )
{
return V_79 -> V_61 ;
}
struct V_39 * F_55 ( T_4 V_179 )
{
struct V_39 * V_39 ;
F_10 (slot, &ibmphp_slot_head, ibm_slot_list) {
if ( V_39 -> V_40 == V_179 )
return V_39 ;
}
return NULL ;
}
struct V_14 * F_48 ( T_2 V_180 )
{
struct V_14 * V_15 ;
F_10 (ptr, &bus_info_head, bus_info_list) {
if ( V_15 -> V_19 == V_180 )
return V_15 ;
}
return NULL ;
}
int F_56 ( T_4 V_180 )
{
struct V_14 * V_15 ;
F_10 (ptr, &bus_info_head, bus_info_list) {
if ( V_15 -> V_19 == V_180 )
return V_15 -> V_44 ;
}
return - V_88 ;
}
void F_57 ( void )
{
struct V_14 * V_14 , * V_181 ;
F_58 (bus_info, next, &bus_info_head,
bus_info_list) {
F_5 ( V_14 ) ;
}
}
void F_59 ( void )
{
struct V_3 * V_3 = NULL , * V_181 ;
int V_182 = 0 ;
F_58 (controller, next, &ebda_hpc_head,
ebda_hpc_list) {
if ( V_3 -> V_49 == 0 )
F_60 ( V_3 -> V_50 . V_54 . V_55 , ( V_3 -> V_50 . V_54 . V_56 - V_3 -> V_50 . V_54 . V_55 + 1 ) ) ;
else if ( ( V_3 -> V_49 == 1 ) && ( ! V_182 ) ) {
++ V_182 ;
F_61 ( & V_183 ) ;
}
F_6 ( V_3 ) ;
}
}
void F_62 ( void )
{
struct V_13 * V_184 , * V_181 ;
F_58 (resource, next, &ibmphp_ebda_pci_rsrc_head,
ebda_pci_rsrc_list) {
F_5 ( V_184 ) ;
V_184 = NULL ;
}
}
int F_63 ( void )
{
struct V_3 * V_113 ;
int V_75 = 0 ;
F_10 (ctrl, &ebda_hpc_head, ebda_hpc_list) {
if ( V_113 -> V_49 == 1 ) {
V_75 = F_64 ( & V_183 ) ;
break;
}
}
return V_75 ;
}
static int F_65 ( struct V_185 * V_186 , const struct V_187 * V_188 )
{
struct V_3 * V_113 ;
F_11 ( L_73 ) ;
F_10 (ctrl, &ebda_hpc_head, ebda_hpc_list) {
if ( V_113 -> V_49 == 1 ) {
if ( ( V_186 -> V_189 == V_113 -> V_50 . V_51 . V_36 ) && ( V_186 -> V_52 -> V_40 == V_113 -> V_50 . V_51 . V_52 ) ) {
V_113 -> V_190 = V_186 ;
F_11 ( L_74 ) ;
F_11 ( L_75 , V_186 -> V_170 , V_186 -> V_191 ) ;
return 0 ;
}
}
}
return - V_88 ;
}
