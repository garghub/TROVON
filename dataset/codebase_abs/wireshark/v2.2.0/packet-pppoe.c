static void
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , int V_3 , T_4 * V_4 ,
int V_5 )
{
T_5 V_6 ;
T_5 V_7 ;
int V_8 ;
T_4 * V_9 , * V_10 , * V_11 ;
{
V_10 = F_2 ( V_4 , V_12 , V_1 , V_3 , V_5 , V_13 ) ;
V_9 = F_3 ( V_10 , V_14 ) ;
V_8 = V_3 ;
while ( V_8 <= V_3 + V_5 - 2 )
{
V_6 = F_4 ( V_1 , V_8 ) ;
V_7 = F_4 ( V_1 , V_8 + 1 ) ;
if ( V_15 )
{
F_2 ( V_9 , V_16 , V_1 , V_8 , 1 , V_17 ) ;
F_2 ( V_9 , V_18 , V_1 , V_8 + 1 , 1 , V_17 ) ;
}
switch ( V_6 )
{
F_5 (PPPOE_TAG_VSPEC_DSLF_CIRCUIT_ID, <=, 63 ,
hf_pppoed_tag_vspec_circuit_id)
F_5 (PPPOE_TAG_VSPEC_DSLF_REMOTE_ID, <=, 63 ,
hf_pppoed_tag_vspec_remote_id)
F_6 (PPPOE_TAG_VSPEC_DSLF_ACT_DATA_RATE_UP, ==, 4 ,
hf_pppoed_tag_vspec_act_data_rate_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_ACT_DATA_RATE_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_act_data_rate_down)
F_6 (PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_UP, ==, 4 ,
hf_pppoed_tag_vspec_min_data_rate_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_min_data_rate_down)
F_6 (PPPOE_TAG_VSPEC_DSLF_ATTAINABLE_DATA_RATE_UP, ==, 4 ,
hf_pppoed_tag_vspec_attainable_data_rate_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_ATTAINABLE_DATA_RATE_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_attainable_data_rate_down)
F_6 (PPPOE_TAG_VSPEC_DSLF_MAX_DATA_RATE_UP, ==, 4 ,
hf_pppoed_tag_vspec_max_data_rate_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_MAX_DATA_RATE_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_max_data_rate_down)
F_6 (PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_UP_LP, ==, 4 ,
hf_pppoed_tag_vspec_min_data_rate_up_lp)
F_6 (PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_DOWN_LP, ==, 4 ,
hf_pppoed_tag_vspec_min_data_rate_down_lp)
F_6 (PPPOE_TAG_VSPEC_DSLF_MAX_INT_DELAY_UP, ==, 4 ,
hf_pppoed_tag_vspec_max_int_delay_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_ACT_INT_DELAY_UP, ==, 4 ,
hf_pppoed_tag_vspec_act_int_delay_up)
F_6 (PPPOE_TAG_VSPEC_DSLF_MAX_INT_DELAY_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_max_int_delay_down)
F_6 (PPPOE_TAG_VSPEC_DSLF_ACT_INT_DELAY_DOWN, ==, 4 ,
hf_pppoed_tag_vspec_act_int_delay_down)
case V_19 :
V_10 = F_2 ( V_9 , V_20 , V_1 ,
V_8 + 2 , 3 , V_13 ) ;
if ( V_7 != 3 ) {
F_7 ( T_3 , V_10 , & V_21 , L_1 , F_8 ( V_6 , V_22 , L_2 ) , V_7 ) ;
}
V_11 = F_3 ( V_10 , V_23 ) ;
F_2 ( V_11 , V_24 ,
V_1 , V_8 + 2 , 1 , V_17 ) ;
F_2 ( V_11 , V_25 ,
V_1 , V_8 + 3 , 1 , V_17 ) ;
F_2 ( V_11 , V_26 ,
V_1 , V_8 + 4 , 1 , V_17 ) ;
break;
default:
if ( V_7 > 0 )
{
if ( ! V_15 )
{
F_2 ( V_9 , V_27 , V_1 , V_8 , 1 , V_17 ) ;
F_2 ( V_9 , V_18 , V_1 , V_8 + 1 , 1 , V_17 ) ;
}
F_2 ( V_9 , V_28 , V_1 ,
V_8 + 1 , V_7 , V_13 ) ;
}
}
V_8 += ( 2 + V_7 ) ;
}
}
}
static void
F_9 ( T_1 * V_1 , T_2 * T_3 , int V_3 , T_4 * V_4 ,
int V_5 )
{
T_6 V_6 ;
T_6 V_7 ;
int V_8 ;
T_6 V_29 = 0 ;
T_4 * V_9 ;
T_7 * V_10 ;
T_7 * V_30 = NULL ;
{
V_10 = F_2 ( V_4 , V_31 , V_1 , V_3 , V_5 - 6 , V_13 ) ;
V_9 = F_3 ( V_10 , V_14 ) ;
V_8 = V_3 ;
while ( V_8 <= V_5 - 2 )
{
V_6 = F_10 ( V_1 , V_8 ) ;
V_7 = F_10 ( V_1 , V_8 + 2 ) ;
if ( V_15 )
{
F_2 ( V_9 , V_27 , V_1 , V_8 , 2 , V_17 ) ;
V_30 =
F_2 ( V_9 , V_32 , V_1 , V_8 + 2 , 2 , V_17 ) ;
}
switch ( V_6 )
{
case V_33 :
if ( V_7 > 0 )
{
F_2 ( V_9 , V_34 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
}
break;
case V_36 :
{
const T_5 * V_37 ;
F_11 ( V_9 , V_38 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 , F_12 () , & V_37 ) ;
F_13 ( T_3 -> V_39 , V_40 , L_3 , V_37 ) ;
}
break;
case V_41 :
F_2 ( V_9 , V_42 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_43 :
F_2 ( V_9 , V_44 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_45 :
if ( V_7 >= 4 )
{
F_2 ( V_9 , V_46 , V_1 ,
V_8 + 4 , 4 , V_17 ) ;
}
if ( V_7 > 4 )
{
T_8 V_47 = F_14 ( V_1 , V_8 + 4 ) ;
switch ( V_47 )
{
case V_48 :
F_1 ( V_1 , T_3 , V_8 + 4 + 4 , V_9 , V_7 - 4 ) ;
break;
default:
F_2 ( V_9 , V_49 , V_1 ,
V_8 + 4 + 4 , V_7 - 4 , V_13 ) ;
}
}
break;
case V_50 :
if ( V_7 == 4 )
{
F_2 ( V_9 , V_51 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_52 , V_1 ,
V_8 + 6 , 2 , V_17 ) ;
} else {
F_2 ( V_9 , V_53 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
break;
case V_54 :
if ( V_7 == 10 )
{
V_29 = F_10 ( V_1 , V_8 + 4 ) ;
F_2 ( V_9 , V_55 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_56 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_57 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_58 , V_1 ,
V_8 + 6 , 1 , V_17 ) ;
F_2 ( V_9 , V_59 , V_1 ,
V_8 + 7 , 1 , V_17 ) ;
F_2 ( V_9 , V_60 , V_1 ,
V_8 + 8 , 2 , V_17 ) ;
V_10 = F_2 ( V_9 , V_61 , V_1 ,
V_8 + 10 , 2 , V_17 ) ;
switch ( ( V_29 & V_62 ) >> 1 )
{
case ( V_63 ) :
F_15 ( V_10 , L_4 ) ;
break;
case ( V_64 ) :
F_15 ( V_10 , L_5 ) ;
break;
case ( V_65 ) :
F_15 ( V_10 , L_6 ) ;
break;
case ( V_66 ) :
F_15 ( V_10 , L_7 ) ;
break;
}
V_10 = F_2 ( V_9 , V_67 , V_1 ,
V_8 + 12 , 2 , V_17 ) ;
switch ( ( V_29 & V_68 ) >> 3 )
{
case ( V_63 ) :
F_15 ( V_10 , L_4 ) ;
break;
case ( V_64 ) :
F_15 ( V_10 , L_5 ) ;
break;
case ( V_65 ) :
F_15 ( V_10 , L_6 ) ;
break;
case ( V_66 ) :
F_15 ( V_10 , L_7 ) ;
break;
}
} else {
F_2 ( V_9 , V_69 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
break;
case V_70 :
if ( V_7 == 2 ) {
F_2 ( V_9 , V_71 , V_1 ,
V_8 + 4 , V_7 , V_17 ) ;
} else {
if ( V_15 ) {
F_15 ( V_30 , L_8 ) ;
}
F_16 ( V_9 , T_3 , & V_21 , V_1 , V_8 + 4 , V_7 ,
L_9 , V_7 ) ;
}
break;
case V_72 :
if ( V_7 == 2 ) {
F_2 ( V_9 , V_73 , V_1 ,
V_8 + 4 , V_7 , V_17 ) ;
} else {
if ( V_15 ) {
F_15 ( V_30 , L_8 ) ;
}
F_16 ( V_9 , T_3 , & V_21 , V_1 , V_8 + 4 , V_7 ,
L_10 , V_7 ) ;
}
break;
case V_74 :
F_2 ( V_9 , V_75 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_76 :
F_2 ( V_9 , V_77 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_78 :
F_2 ( V_9 , V_79 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_80 :
F_2 ( V_9 , V_81 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_82 :
F_2 ( V_9 , V_83 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_84 :
F_2 ( V_9 , V_85 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_86 :
F_2 ( V_9 , V_87 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_88 :
F_2 ( V_9 , V_89 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_90 :
return;
default:
if ( V_7 > 0 )
{
if ( ! V_15 )
{
F_2 ( V_9 , V_27 , V_1 , V_8 , 2 , V_17 ) ;
F_2 ( V_9 , V_32 , V_1 , V_8 + 2 , 2 , V_17 ) ;
}
F_2 ( V_9 , V_28 , V_1 ,
V_8 + 2 , V_7 , V_13 ) ;
}
}
V_8 += ( 4 + V_7 ) ;
}
}
}
static int F_17 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_4 , void * T_9 V_2 )
{
T_5 V_91 ;
T_6 V_92 ;
T_4 * V_9 = NULL ;
T_7 * V_10 ;
F_18 ( T_3 -> V_39 , V_93 , L_11 ) ;
F_19 ( T_3 -> V_39 , V_40 ) ;
V_91 = F_4 ( V_1 , 1 ) ;
F_20 ( T_3 -> V_39 , V_40 , F_8 ( V_91 , V_94 , L_2 ) ) ;
V_92 = F_10 ( V_1 , 4 ) ;
if ( V_4 )
{
V_10 = F_2 ( V_4 , V_95 , V_1 , 0 , V_92 + 6 , V_13 ) ;
V_9 = F_3 ( V_10 , V_96 ) ;
F_2 ( V_9 , V_97 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_98 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_99 , V_1 , 1 , 1 , V_17 ) ;
F_2 ( V_9 , V_100 , V_1 , 2 , 2 , V_17 ) ;
F_2 ( V_9 , V_101 , V_1 , 4 , 2 , V_17 ) ;
}
if ( V_92 > 0 )
{
F_9 ( V_1 , T_3 , 6 , V_9 , 6 + V_92 ) ;
}
return F_21 ( V_1 ) ;
}
void F_22 ( void )
{
static T_10 V_102 [] =
{
{ & V_31 ,
{ L_12 , L_13 , V_103 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_27 ,
{ L_14 , L_15 , V_106 , V_107 ,
F_23 ( V_108 ) , 0x0 , NULL , V_105
}
} ,
{ & V_32 ,
{ L_16 , L_17 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_18 ,
{ L_16 , L_18 , V_110 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_28 ,
{ L_19 , L_20 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_34 ,
{ L_21 , L_22 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_38 ,
{ L_23 , L_24 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_42 ,
{ L_25 , L_26 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_44 ,
{ L_27 , L_28 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_46 ,
{ L_29 , L_30 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_49 ,
{ L_31 , L_32 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_12 ,
{ L_33 , L_34 , V_103 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_16 ,
{ L_14 , L_35 , V_110 , V_107 ,
F_23 ( V_22 ) , 0x0 , NULL , V_105
}
} ,
{ & V_115 ,
{ L_36 , L_37 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_116 ,
{ L_38 , L_39 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_117 ,
{ L_40 , L_41 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_118 ,
{ L_42 , L_43 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_119 ,
{ L_44 , L_45 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_120 ,
{ L_46 , L_47 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_121 ,
{ L_48 , L_49 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_122 ,
{ L_50 , L_51 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_123 ,
{ L_52 , L_53 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_124 ,
{ L_54 , L_55 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_125 ,
{ L_56 , L_57 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_126 ,
{ L_58 , L_59 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_127 ,
{ L_60 , L_61 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_128 ,
{ L_62 , L_63 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_129 ,
{ L_64 , L_65 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_130 ,
{ L_66 , L_67 , V_114 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_20 ,
{ L_68 , L_69 , V_103 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_24 ,
{ L_70 , L_71 , V_110 , V_107 ,
F_23 ( V_131 ) , 0x0 , NULL , V_105
}
} ,
{ & V_25 ,
{ L_72 , L_73 , V_110 , V_107 ,
F_23 ( V_132 ) , 0x0 , NULL , V_105
}
} ,
{ & V_26 ,
{ L_72 , L_74 , V_110 , V_107 ,
F_23 ( V_133 ) , 0x0 , NULL , V_105
}
} ,
{ & V_53 ,
{ L_75 , L_76 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_51 ,
{ L_77 , L_78 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_52 ,
{ L_79 , L_80 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_69 ,
{ L_81 , L_82 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_57 ,
{ L_83 , L_84 , V_134 , 16 ,
NULL , V_135 , NULL , V_105
}
} ,
{ & V_55 ,
{ L_85 , L_86 , V_106 , V_107 ,
F_23 ( V_136 ) , V_68 , NULL , V_105
}
} ,
{ & V_56 ,
{ L_87 , L_88 , V_106 , V_107 ,
F_23 ( V_136 ) , V_62 , NULL , V_105
}
} ,
{ & V_58 ,
{ L_89 , L_90 , V_110 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_59 ,
{ L_91 , L_92 , V_110 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_60 ,
{ L_93 , L_94 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_61 ,
{ L_95 , L_96 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_67 ,
{ L_97 , L_98 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_71 ,
{ L_99 , L_100 , V_106 , V_107 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_73 ,
{ L_101 , L_102 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_75 ,
{ L_103 , L_104 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_77 ,
{ L_105 , L_106 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_79 ,
{ L_107 , L_108 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_81 ,
{ L_109 , L_110 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_83 ,
{ L_111 , L_112 , V_111 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_85 ,
{ L_113 , L_114 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_87 ,
{ L_115 , L_116 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_89 ,
{ L_117 , L_118 , V_112 , V_113 ,
NULL , 0x0 , NULL , V_105
}
}
} ;
static T_11 * V_137 [] = {
& V_96 ,
& V_14 ,
& V_23
} ;
T_12 * V_138 ;
V_95 = F_24 ( L_119 ,
L_11 , L_120 ) ;
F_25 ( V_137 , F_26 ( V_137 ) ) ;
F_27 ( V_95 , V_102 , F_26 ( V_102 ) ) ;
V_138 = F_28 ( V_95 , NULL ) ;
F_29 ( V_138 , L_121 ,
L_122 ,
L_123 ,
& V_15 ) ;
}
void F_30 ( void )
{
T_13 V_139 ;
V_139 = F_31 ( F_17 , V_95 ) ;
F_32 ( L_124 , V_140 , V_139 ) ;
}
static int F_33 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_4 , void * T_9 V_2 )
{
T_5 V_91 ;
T_6 V_92 ;
T_6 V_7 ;
T_11 V_141 ;
T_11 V_142 , V_143 ;
T_11 V_144 = 0 , V_8 = 0 ;
T_6 V_145 ;
T_4 * V_9 ;
T_7 * V_10 = NULL ;
T_1 * V_146 ;
F_18 ( T_3 -> V_39 , V_93 , L_125 ) ;
F_19 ( T_3 -> V_39 , V_40 ) ;
V_91 = F_4 ( V_1 , 1 ) ;
F_18 ( T_3 -> V_39 , V_40 ,
F_8 ( V_91 , V_94 , L_2 ) ) ;
V_92 = F_10 ( V_1 , 4 ) ;
V_141 = F_34 ( V_1 , 6 ) ;
if ( V_4 )
{
V_10 = F_2 ( V_4 , V_147 , V_1 , 0 , 6 , V_13 ) ;
V_9 = F_3 ( V_10 , V_148 ) ;
F_2 ( V_9 , V_97 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_98 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_99 , V_1 , 1 , 1 , V_17 ) ;
F_2 ( V_9 , V_100 , V_1 , 2 , 2 , V_17 ) ;
V_10 = F_2 ( V_9 , V_101 , V_1 , 4 , 2 , V_17 ) ;
if ( V_50 == F_10 ( V_1 , 6 ) )
{
V_8 = 6 ;
V_7 = F_10 ( V_1 , V_8 + 2 ) ;
V_10 = F_2 ( V_9 , V_149 , V_1 , V_8 , 8 , V_13 ) ;
V_9 = F_3 ( V_10 , V_150 ) ;
if ( V_7 == 4 )
{
F_2 ( V_9 , V_151 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_152 , V_1 ,
V_8 + 6 , 2 , V_17 ) ;
} else {
F_2 ( V_9 , V_53 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
V_144 = 8 ;
}
}
if ( F_35 ( V_1 ) > 46 ) {
V_145 = F_10 ( V_1 , 6 ) ;
if ( ( V_145 != V_153 ) && ( V_145 != V_154 ) &&
( V_92 != V_141 ) &&
( ( V_92 + 4 ) != V_141 ) ) {
F_15 ( V_10 , L_126 ,
V_141 ) ;
F_7 ( T_3 , V_10 , & V_155 , L_127 , V_92 , V_141 ) ;
}
}
V_142 = F_36 ( V_1 , 6 ) ;
V_143 = F_34 ( V_1 , 6 ) ;
F_37 ( V_142 >= 0 ) ;
F_37 ( V_143 >= 0 ) ;
if ( V_142 > V_143 )
V_142 = V_143 ;
if ( ( V_156 ) V_142 > V_92 )
V_142 = V_92 ;
if ( ( V_156 ) V_143 > V_92 )
V_143 = V_92 ;
V_146 = F_38 ( V_1 , ( 6 + V_144 ) ,
( V_142 - V_144 ) ,
( V_143 - V_144 ) ) ;
F_39 ( V_157 , V_146 , T_3 , V_4 ) ;
return F_21 ( V_1 ) ;
}
void F_40 ( void )
{
static T_10 V_102 [] =
{
{ & V_149 ,
{ L_12 , L_128 , V_103 , V_104 ,
NULL , 0x0 , NULL , V_105
}
} ,
#if 0
{ &hf_pppoes_tag,
{ "Tag", "pppoes.tag", FT_UINT16, BASE_HEX,
VALS(tag_vals), 0x0, NULL, HFILL
}
},
#endif
#if 0
{ &hf_pppoes_tag_credits,
{ "Credits", "pppoes.tags.credits", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
#endif
{ & V_151 ,
{ L_77 , L_129 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_152 ,
{ L_79 , L_130 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
}
} ;
static T_11 * V_137 [] = {
& V_158 ,
& V_150
} ;
V_147 = F_24 ( L_131 , L_125 , L_132 ) ;
F_25 ( V_137 , F_26 ( V_137 ) ) ;
F_27 ( V_147 , V_102 , F_26 ( V_102 ) ) ;
}
void F_41 ( void )
{
static T_10 V_102 [] =
{
{ & V_97 ,
{ L_133 , L_134 , V_110 , V_109 ,
NULL , 0xf0 , NULL , V_105
}
} ,
{ & V_98 ,
{ L_135 , L_136 , V_110 , V_109 ,
NULL , 0x0f , NULL , V_105
}
} ,
{ & V_99 ,
{ L_137 , L_138 , V_110 , V_107 ,
F_23 ( V_94 ) , 0x0 , NULL , V_105
}
} ,
{ & V_100 ,
{ L_139 , L_140 , V_106 , V_107 ,
NULL , 0x0 , NULL , V_105
}
} ,
{ & V_101 ,
{ L_141 , L_142 , V_106 , V_109 ,
NULL , 0x0 , NULL , V_105
}
}
} ;
static T_11 * V_137 [] = {
& V_148
} ;
static T_14 V_159 [] = {
{ & V_21 , { L_143 , V_160 , V_161 , L_144 , V_162 } } ,
{ & V_155 , { L_145 , V_160 , V_161 , L_146 , V_162 } } ,
} ;
T_15 * V_163 ;
V_164 = F_24 ( L_147 , L_148 , L_149 ) ;
F_25 ( V_137 , F_26 ( V_137 ) ) ;
F_27 ( V_164 , V_102 , F_26 ( V_102 ) ) ;
V_163 = F_42 ( V_164 ) ;
F_43 ( V_163 , V_159 , F_26 ( V_159 ) ) ;
}
void F_44 ( void )
{
T_13 V_165 =
F_31 ( F_33 , V_147 ) ;
F_32 ( L_124 , V_166 , V_165 ) ;
F_32 ( L_150 , V_167 , V_165 ) ;
V_157 = F_45 ( L_151 , V_147 ) ;
}
