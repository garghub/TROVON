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
F_2 ( V_9 , V_37 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
F_11 ( T_3 -> V_38 , V_39 , L_3 ,
F_12 ( F_13 () , V_1 , V_8 + 4 , V_7 , V_35 | V_13 ) ) ;
break;
case V_40 :
F_2 ( V_9 , V_41 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_42 :
F_2 ( V_9 , V_43 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_44 :
if ( V_7 >= 4 )
{
F_2 ( V_9 , V_45 , V_1 ,
V_8 + 4 , 4 , V_17 ) ;
}
if ( V_7 > 4 )
{
T_8 V_46 = F_14 ( V_1 , V_8 + 4 ) ;
switch ( V_46 )
{
case V_47 :
F_1 ( V_1 , T_3 , V_8 + 4 + 4 , V_9 , V_7 - 4 ) ;
break;
default:
F_2 ( V_9 , V_48 , V_1 ,
V_8 + 4 + 4 , V_7 - 4 , V_13 ) ;
}
}
break;
case V_49 :
if ( V_7 == 4 )
{
F_2 ( V_9 , V_50 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_51 , V_1 ,
V_8 + 6 , 2 , V_17 ) ;
} else {
F_2 ( V_9 , V_52 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
break;
case V_53 :
if ( V_7 == 10 )
{
V_29 = F_10 ( V_1 , V_8 + 4 ) ;
F_2 ( V_9 , V_54 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_55 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_56 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_57 , V_1 ,
V_8 + 6 , 1 , V_17 ) ;
F_2 ( V_9 , V_58 , V_1 ,
V_8 + 7 , 1 , V_17 ) ;
F_2 ( V_9 , V_59 , V_1 ,
V_8 + 8 , 2 , V_17 ) ;
V_10 = F_2 ( V_9 , V_60 , V_1 ,
V_8 + 10 , 2 , V_17 ) ;
switch ( ( V_29 & V_61 ) >> 1 )
{
case ( V_62 ) :
F_15 ( V_10 , L_4 ) ;
break;
case ( V_63 ) :
F_15 ( V_10 , L_5 ) ;
break;
case ( V_64 ) :
F_15 ( V_10 , L_6 ) ;
break;
case ( V_65 ) :
F_15 ( V_10 , L_7 ) ;
break;
}
V_10 = F_2 ( V_9 , V_66 , V_1 ,
V_8 + 12 , 2 , V_17 ) ;
switch ( ( V_29 & V_67 ) >> 3 )
{
case ( V_62 ) :
F_15 ( V_10 , L_4 ) ;
break;
case ( V_63 ) :
F_15 ( V_10 , L_5 ) ;
break;
case ( V_64 ) :
F_15 ( V_10 , L_6 ) ;
break;
case ( V_65 ) :
F_15 ( V_10 , L_7 ) ;
break;
}
} else {
F_2 ( V_9 , V_68 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
break;
case V_69 :
if ( V_7 == 2 ) {
F_2 ( V_9 , V_70 , V_1 ,
V_8 + 4 , V_7 , V_17 ) ;
} else {
if ( V_15 ) {
F_15 ( V_30 , L_8 ) ;
}
F_16 ( V_9 , T_3 , & V_21 , V_1 , V_8 + 4 , V_7 ,
L_9 , V_7 ) ;
}
break;
case V_71 :
if ( V_7 == 2 ) {
F_2 ( V_9 , V_72 , V_1 ,
V_8 + 4 , V_7 , V_17 ) ;
} else {
if ( V_15 ) {
F_15 ( V_30 , L_8 ) ;
}
F_16 ( V_9 , T_3 , & V_21 , V_1 , V_8 + 4 , V_7 ,
L_10 , V_7 ) ;
}
break;
case V_73 :
F_2 ( V_9 , V_74 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_75 :
F_2 ( V_9 , V_76 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_77 :
F_2 ( V_9 , V_78 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_79 :
F_2 ( V_9 , V_80 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_81 :
F_2 ( V_9 , V_82 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
break;
case V_83 :
F_2 ( V_9 , V_84 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_85 :
F_2 ( V_9 , V_86 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_87 :
F_2 ( V_9 , V_88 , V_1 ,
V_8 + 4 , V_7 , V_35 | V_13 ) ;
break;
case V_89 :
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
T_5 V_90 ;
T_6 V_91 ;
T_4 * V_9 = NULL ;
T_7 * V_10 ;
F_18 ( T_3 -> V_38 , V_92 , L_11 ) ;
F_19 ( T_3 -> V_38 , V_39 ) ;
V_90 = F_4 ( V_1 , 1 ) ;
F_20 ( T_3 -> V_38 , V_39 , F_8 ( V_90 , V_93 , L_2 ) ) ;
V_91 = F_10 ( V_1 , 4 ) ;
if ( V_4 )
{
V_10 = F_2 ( V_4 , V_94 , V_1 , 0 , V_91 + 6 , V_13 ) ;
V_9 = F_3 ( V_10 , V_95 ) ;
F_2 ( V_9 , V_96 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_97 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_98 , V_1 , 1 , 1 , V_17 ) ;
F_2 ( V_9 , V_99 , V_1 , 2 , 2 , V_17 ) ;
F_2 ( V_9 , V_100 , V_1 , 4 , 2 , V_17 ) ;
}
if ( V_91 > 0 )
{
F_9 ( V_1 , T_3 , 6 , V_9 , 6 + V_91 ) ;
}
return F_21 ( V_1 ) ;
}
void F_22 ( void )
{
static T_10 V_101 [] =
{
{ & V_31 ,
{ L_12 , L_13 , V_102 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_27 ,
{ L_14 , L_15 , V_105 , V_106 ,
F_23 ( V_107 ) , 0x0 , NULL , V_104
}
} ,
{ & V_32 ,
{ L_16 , L_17 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_18 ,
{ L_16 , L_18 , V_109 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_28 ,
{ L_19 , L_20 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_34 ,
{ L_21 , L_22 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_37 ,
{ L_23 , L_24 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_41 ,
{ L_25 , L_26 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_43 ,
{ L_27 , L_28 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_45 ,
{ L_29 , L_30 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_48 ,
{ L_31 , L_32 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_12 ,
{ L_33 , L_34 , V_102 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_16 ,
{ L_14 , L_35 , V_109 , V_106 ,
F_23 ( V_22 ) , 0x0 , NULL , V_104
}
} ,
{ & V_114 ,
{ L_36 , L_37 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_115 ,
{ L_38 , L_39 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_116 ,
{ L_40 , L_41 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_117 ,
{ L_42 , L_43 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_118 ,
{ L_44 , L_45 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_119 ,
{ L_46 , L_47 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_120 ,
{ L_48 , L_49 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_121 ,
{ L_50 , L_51 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_122 ,
{ L_52 , L_53 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_123 ,
{ L_54 , L_55 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_124 ,
{ L_56 , L_57 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_125 ,
{ L_58 , L_59 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_126 ,
{ L_60 , L_61 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_127 ,
{ L_62 , L_63 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_128 ,
{ L_64 , L_65 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_129 ,
{ L_66 , L_67 , V_113 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_20 ,
{ L_68 , L_69 , V_102 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_24 ,
{ L_70 , L_71 , V_109 , V_106 ,
F_23 ( V_130 ) , 0x0 , NULL , V_104
}
} ,
{ & V_25 ,
{ L_72 , L_73 , V_109 , V_106 ,
F_23 ( V_131 ) , 0x0 , NULL , V_104
}
} ,
{ & V_26 ,
{ L_72 , L_74 , V_109 , V_106 ,
F_23 ( V_132 ) , 0x0 , NULL , V_104
}
} ,
{ & V_52 ,
{ L_75 , L_76 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_50 ,
{ L_77 , L_78 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_51 ,
{ L_79 , L_80 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_68 ,
{ L_81 , L_82 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_56 ,
{ L_83 , L_84 , V_133 , 16 ,
NULL , V_134 , NULL , V_104
}
} ,
{ & V_54 ,
{ L_85 , L_86 , V_105 , V_106 ,
F_23 ( V_135 ) , V_67 , NULL , V_104
}
} ,
{ & V_55 ,
{ L_87 , L_88 , V_105 , V_106 ,
F_23 ( V_135 ) , V_61 , NULL , V_104
}
} ,
{ & V_57 ,
{ L_89 , L_90 , V_109 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_58 ,
{ L_91 , L_92 , V_109 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_59 ,
{ L_93 , L_94 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_60 ,
{ L_95 , L_96 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_66 ,
{ L_97 , L_98 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_70 ,
{ L_99 , L_100 , V_105 , V_106 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_72 ,
{ L_101 , L_102 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_74 ,
{ L_103 , L_104 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_76 ,
{ L_105 , L_106 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_78 ,
{ L_107 , L_108 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_80 ,
{ L_109 , L_110 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_82 ,
{ L_111 , L_112 , V_110 , V_103 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_84 ,
{ L_113 , L_114 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_86 ,
{ L_115 , L_116 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_88 ,
{ L_117 , L_118 , V_111 , V_112 ,
NULL , 0x0 , NULL , V_104
}
}
} ;
static T_11 * V_136 [] = {
& V_95 ,
& V_14 ,
& V_23
} ;
T_12 * V_137 ;
V_94 = F_24 ( L_119 ,
L_11 , L_120 ) ;
F_25 ( V_136 , F_26 ( V_136 ) ) ;
F_27 ( V_94 , V_101 , F_26 ( V_101 ) ) ;
V_137 = F_28 ( V_94 , NULL ) ;
F_29 ( V_137 , L_121 ,
L_122 ,
L_123 ,
& V_15 ) ;
}
void F_30 ( void )
{
T_13 V_138 ;
V_138 = F_31 ( F_17 , V_94 ) ;
F_32 ( L_124 , V_139 , V_138 ) ;
}
static int F_33 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_4 , void * T_9 V_2 )
{
T_5 V_90 ;
T_6 V_91 ;
T_6 V_7 ;
T_11 V_140 ;
T_11 V_141 , V_142 ;
T_11 V_143 = 0 , V_8 = 0 ;
T_6 V_144 ;
T_4 * V_9 ;
T_7 * V_10 = NULL ;
T_1 * V_145 ;
F_18 ( T_3 -> V_38 , V_92 , L_125 ) ;
F_19 ( T_3 -> V_38 , V_39 ) ;
V_90 = F_4 ( V_1 , 1 ) ;
F_18 ( T_3 -> V_38 , V_39 ,
F_8 ( V_90 , V_93 , L_2 ) ) ;
V_91 = F_10 ( V_1 , 4 ) ;
V_140 = F_34 ( V_1 , 6 ) ;
if ( V_4 )
{
V_10 = F_2 ( V_4 , V_146 , V_1 , 0 , 6 , V_13 ) ;
V_9 = F_3 ( V_10 , V_147 ) ;
F_2 ( V_9 , V_96 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_97 , V_1 , 0 , 1 , V_17 ) ;
F_2 ( V_9 , V_98 , V_1 , 1 , 1 , V_17 ) ;
F_2 ( V_9 , V_99 , V_1 , 2 , 2 , V_17 ) ;
V_10 = F_2 ( V_9 , V_100 , V_1 , 4 , 2 , V_17 ) ;
if ( V_49 == F_10 ( V_1 , 6 ) )
{
V_8 = 6 ;
V_7 = F_10 ( V_1 , V_8 + 2 ) ;
V_10 = F_2 ( V_9 , V_148 , V_1 , V_8 , 8 , V_13 ) ;
V_9 = F_3 ( V_10 , V_149 ) ;
if ( V_7 == 4 )
{
F_2 ( V_9 , V_150 , V_1 ,
V_8 + 4 , 2 , V_17 ) ;
F_2 ( V_9 , V_151 , V_1 ,
V_8 + 6 , 2 , V_17 ) ;
} else {
F_2 ( V_9 , V_52 , V_1 ,
V_8 + 4 , V_7 , V_13 ) ;
}
V_143 = 8 ;
}
}
if ( F_35 ( V_1 ) > 46 ) {
V_144 = F_10 ( V_1 , 6 ) ;
if ( ( V_144 != V_152 ) && ( V_144 != V_153 ) &&
( V_91 != V_140 ) &&
( ( V_91 + 4 ) != V_140 ) ) {
F_15 ( V_10 , L_126 ,
V_140 ) ;
F_7 ( T_3 , V_10 , & V_154 , L_127 , V_91 , V_140 ) ;
}
}
V_141 = F_36 ( V_1 , 6 ) ;
V_142 = F_34 ( V_1 , 6 ) ;
F_37 ( V_141 >= 0 ) ;
F_37 ( V_142 >= 0 ) ;
if ( V_141 > V_142 )
V_141 = V_142 ;
if ( ( V_155 ) V_141 > V_91 )
V_141 = V_91 ;
if ( ( V_155 ) V_142 > V_91 )
V_142 = V_91 ;
V_145 = F_38 ( V_1 , ( 6 + V_143 ) ,
( V_141 - V_143 ) ,
( V_142 - V_143 ) ) ;
F_39 ( V_156 , V_145 , T_3 , V_4 ) ;
return F_21 ( V_1 ) ;
}
void F_40 ( void )
{
static T_10 V_101 [] =
{
{ & V_148 ,
{ L_12 , L_128 , V_102 , V_103 ,
NULL , 0x0 , NULL , V_104
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
{ & V_150 ,
{ L_77 , L_129 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_151 ,
{ L_79 , L_130 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
}
} ;
static T_11 * V_136 [] = {
& V_157 ,
& V_149
} ;
V_146 = F_24 ( L_131 , L_125 , L_132 ) ;
F_25 ( V_136 , F_26 ( V_136 ) ) ;
F_27 ( V_146 , V_101 , F_26 ( V_101 ) ) ;
}
void F_41 ( void )
{
static T_10 V_101 [] =
{
{ & V_96 ,
{ L_133 , L_134 , V_109 , V_108 ,
NULL , 0xf0 , NULL , V_104
}
} ,
{ & V_97 ,
{ L_135 , L_136 , V_109 , V_108 ,
NULL , 0x0f , NULL , V_104
}
} ,
{ & V_98 ,
{ L_137 , L_138 , V_109 , V_106 ,
F_23 ( V_93 ) , 0x0 , NULL , V_104
}
} ,
{ & V_99 ,
{ L_139 , L_140 , V_105 , V_106 ,
NULL , 0x0 , NULL , V_104
}
} ,
{ & V_100 ,
{ L_141 , L_142 , V_105 , V_108 ,
NULL , 0x0 , NULL , V_104
}
}
} ;
static T_11 * V_136 [] = {
& V_147
} ;
static T_14 V_158 [] = {
{ & V_21 , { L_143 , V_159 , V_160 , L_144 , V_161 } } ,
{ & V_154 , { L_145 , V_159 , V_160 , L_146 , V_161 } } ,
} ;
T_15 * V_162 ;
V_163 = F_24 ( L_147 , L_148 , L_149 ) ;
F_25 ( V_136 , F_26 ( V_136 ) ) ;
F_27 ( V_163 , V_101 , F_26 ( V_101 ) ) ;
V_162 = F_42 ( V_163 ) ;
F_43 ( V_162 , V_158 , F_26 ( V_158 ) ) ;
}
void F_44 ( void )
{
T_13 V_164 =
F_31 ( F_33 , V_146 ) ;
F_32 ( L_124 , V_165 , V_164 ) ;
F_32 ( L_150 , V_166 , V_164 ) ;
V_156 = F_45 ( L_151 , V_146 ) ;
}
