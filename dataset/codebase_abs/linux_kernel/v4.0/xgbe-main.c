static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_10 ;
V_2 -> V_18 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
F_2 ( L_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_28 ) ;
F_5 ( & V_2 -> V_29 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_33 = V_2 -> V_33 ;
T_1 V_34 ;
T_2 V_35 ;
T_3 V_36 ;
unsigned long long V_37 ;
int V_38 ;
int V_39 ;
V_39 = F_7 ( V_33 , V_40 , & V_34 ) ;
if ( V_39 ) {
F_8 ( V_33 , L_3 ,
V_40 ) ;
return V_39 ;
}
V_2 -> V_41 = V_34 ;
V_39 = F_7 ( V_33 , V_42 , & V_34 ) ;
if ( V_39 ) {
F_8 ( V_33 , L_3 ,
V_42 ) ;
return V_39 ;
}
V_2 -> V_43 = V_34 ;
V_35 = V_31 -> V_35 ;
do {
V_36 = F_9 ( V_35 , L_4 , NULL , & V_37 ) ;
if ( ! F_10 ( V_36 ) ) {
V_38 = V_37 ;
break;
}
V_36 = F_11 ( V_35 , & V_35 ) ;
} while ( ! F_10 ( V_36 ) );
if ( F_10 ( V_36 ) ) {
F_8 ( V_33 , L_5 ) ;
return - V_44 ;
}
V_2 -> V_45 = ! ! V_38 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return - V_44 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
V_2 -> V_46 = F_13 ( V_33 , V_47 ) ;
if ( F_14 ( V_2 -> V_46 ) ) {
F_8 ( V_33 , L_6 ) ;
return F_15 ( V_2 -> V_46 ) ;
}
V_2 -> V_41 = F_16 ( V_2 -> V_46 ) ;
V_2 -> V_48 = F_13 ( V_33 , V_49 ) ;
if ( F_14 ( V_2 -> V_48 ) ) {
F_8 ( V_33 , L_7 ) ;
return F_15 ( V_2 -> V_48 ) ;
}
V_2 -> V_43 = F_16 ( V_2 -> V_48 ) ;
V_2 -> V_45 = F_17 ( V_33 -> V_50 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return - V_44 ;
}
static int F_18 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_28 ;
struct V_54 * V_29 ;
struct V_55 * V_56 ;
struct V_32 * V_33 = & V_52 -> V_33 ;
struct V_57 * V_58 ;
const char * V_59 ;
unsigned int V_60 ;
int V_39 ;
F_2 ( L_8 ) ;
V_56 = F_19 ( sizeof( struct V_1 ) ,
V_61 ) ;
if ( ! V_56 ) {
F_8 ( V_33 , L_9 ) ;
V_39 = - V_62 ;
goto V_63;
}
F_20 ( V_56 , V_33 ) ;
V_2 = F_21 ( V_56 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_31 = F_22 ( V_33 ) ;
V_2 -> V_33 = V_33 ;
F_23 ( V_52 , V_56 ) ;
F_24 ( & V_2 -> V_64 ) ;
F_25 ( & V_2 -> V_65 ) ;
F_25 ( & V_2 -> V_66 ) ;
F_24 ( & V_2 -> V_67 ) ;
V_2 -> V_68 = ( ! V_2 -> V_31 || V_69 ) ? 0 : 1 ;
F_26 ( V_70 ) ;
V_2 -> V_71 = V_70 ;
if ( V_2 -> V_71 & ( V_2 -> V_71 - 1 ) ) {
F_8 ( V_33 , L_10 ,
V_2 -> V_71 ) ;
V_39 = - V_44 ;
goto V_72;
}
F_26 ( V_73 ) ;
V_2 -> V_74 = V_73 ;
if ( V_2 -> V_74 & ( V_2 -> V_74 - 1 ) ) {
F_8 ( V_33 , L_11 ,
V_2 -> V_74 ) ;
V_39 = - V_44 ;
goto V_72;
}
V_58 = F_27 ( V_52 , V_75 , 0 ) ;
V_2 -> V_76 = F_28 ( V_33 , V_58 ) ;
if ( F_14 ( V_2 -> V_76 ) ) {
F_8 ( V_33 , L_12 ) ;
V_39 = F_15 ( V_2 -> V_76 ) ;
goto V_72;
}
F_2 ( L_13 , V_2 -> V_76 ) ;
V_58 = F_27 ( V_52 , V_75 , 1 ) ;
V_2 -> V_77 = F_28 ( V_33 , V_58 ) ;
if ( F_14 ( V_2 -> V_77 ) ) {
F_8 ( V_33 , L_14 ) ;
V_39 = F_15 ( V_2 -> V_77 ) ;
goto V_72;
}
F_2 ( L_15 , V_2 -> V_77 ) ;
V_39 = F_29 ( V_33 , V_78 ,
V_2 -> V_79 ,
sizeof( V_2 -> V_79 ) ) ;
if ( V_39 || ! F_30 ( V_2 -> V_79 ) ) {
F_8 ( V_33 , L_16 , V_78 ) ;
if ( ! V_39 )
V_39 = - V_44 ;
goto V_72;
}
V_39 = F_31 ( V_33 , V_80 ,
& V_59 ) ;
if ( V_39 || strcmp ( V_59 , F_32 ( V_81 ) ) ) {
F_8 ( V_33 , L_16 , V_80 ) ;
if ( ! V_39 )
V_39 = - V_44 ;
goto V_72;
}
V_2 -> V_59 = V_81 ;
if ( F_33 ( V_33 , V_82 ) )
V_2 -> V_83 = 1 ;
if ( V_2 -> V_68 )
V_39 = F_6 ( V_2 ) ;
else
V_39 = F_12 ( V_2 ) ;
if ( V_39 )
goto V_72;
if ( V_2 -> V_45 ) {
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_89 ;
} else {
V_2 -> V_84 = V_90 ;
V_2 -> V_86 = V_91 ;
V_2 -> V_88 = V_92 ;
}
if ( ! V_33 -> V_93 )
V_33 -> V_93 = & V_33 -> V_94 ;
V_39 = F_34 ( V_33 , F_35 ( 40 ) ) ;
if ( V_39 ) {
F_8 ( V_33 , L_17 ) ;
goto V_72;
}
V_39 = F_36 ( V_52 , 0 ) ;
if ( V_39 < 0 ) {
F_8 ( V_33 , L_18 ) ;
goto V_72;
}
V_2 -> V_95 = V_39 ;
V_56 -> V_96 = V_2 -> V_95 ;
V_56 -> V_97 = ( unsigned long ) V_2 -> V_76 ;
memcpy ( V_56 -> V_98 , V_2 -> V_79 , V_56 -> V_99 ) ;
F_3 ( V_2 ) ;
V_28 = & V_2 -> V_28 ;
V_29 = & V_2 -> V_29 ;
V_28 -> exit ( V_2 ) ;
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_100 = F_38 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_101 = V_2 -> V_100 ;
V_39 = F_39 ( V_56 , V_2 -> V_100 ) ;
if ( V_39 ) {
F_8 ( V_33 , L_19 ) ;
goto V_72;
}
V_2 -> V_102 = F_38 (unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_103 = V_2 -> V_104 . V_105 ;
V_39 = F_40 ( V_56 , V_2 -> V_102 ) ;
if ( V_39 ) {
F_8 ( V_33 , L_20 ) ;
goto V_72;
}
F_41 ( V_2 -> V_106 , sizeof( V_2 -> V_106 ) ) ;
for ( V_60 = 0 ; V_60 < V_107 ; V_60 ++ )
F_42 ( V_2 -> V_108 [ V_60 ] , V_109 , V_110 ,
V_60 % V_2 -> V_102 ) ;
F_42 ( V_2 -> V_111 , V_112 , V_113 , 1 ) ;
F_42 ( V_2 -> V_111 , V_112 , V_114 , 1 ) ;
F_42 ( V_2 -> V_111 , V_112 , V_115 , 1 ) ;
V_2 -> V_116 = F_43 ( V_117 , L_21 , V_52 -> V_118 ) ;
if ( ! V_2 -> V_116 ) {
F_8 ( V_33 , L_22 ) ;
V_39 = - V_62 ;
goto V_72;
}
V_39 = F_44 ( V_2 ) ;
if ( V_39 )
goto V_119;
V_56 -> V_120 = F_45 () ;
V_56 -> V_121 = F_46 () ;
#ifdef F_47
V_56 -> V_122 = F_48 () ;
#endif
V_56 -> V_123 = V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 ;
if ( V_2 -> V_104 . V_134 )
V_56 -> V_123 |= V_135 ;
V_56 -> V_136 |= V_124 |
V_125 |
V_126 |
V_128 |
V_129 ;
V_56 -> V_137 |= V_56 -> V_123 ;
V_2 -> V_138 = V_56 -> V_137 ;
V_56 -> V_139 |= V_140 ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_56 ) ;
V_39 = F_52 ( V_56 ) ;
if ( V_39 ) {
F_8 ( V_33 , L_23 ) ;
goto V_141;
}
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_56 , L_24 ) ;
F_2 ( L_25 ) ;
return 0 ;
V_141:
F_56 ( V_2 ) ;
V_119:
F_57 ( V_2 -> V_116 ) ;
V_72:
F_58 ( V_56 ) ;
V_63:
F_59 ( V_33 , L_26 ) ;
return V_39 ;
}
static int F_60 ( struct V_51 * V_52 )
{
struct V_55 * V_56 = F_61 ( V_52 ) ;
struct V_1 * V_2 = F_21 ( V_56 ) ;
F_2 ( L_27 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_56 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 -> V_116 ) ;
F_58 ( V_56 ) ;
F_2 ( L_28 ) ;
return 0 ;
}
static int F_65 ( struct V_32 * V_33 )
{
struct V_55 * V_56 = F_66 ( V_33 ) ;
int V_39 ;
F_2 ( L_29 ) ;
if ( ! F_67 ( V_56 ) ) {
F_2 ( L_30 ) ;
return - V_44 ;
}
V_39 = F_68 ( V_56 , V_142 ) ;
F_2 ( L_31 ) ;
return V_39 ;
}
static int F_69 ( struct V_32 * V_33 )
{
struct V_55 * V_56 = F_66 ( V_33 ) ;
int V_39 ;
F_2 ( L_32 ) ;
if ( ! F_67 ( V_56 ) ) {
F_2 ( L_33 ) ;
return - V_44 ;
}
V_39 = F_70 ( V_56 , V_142 ) ;
F_2 ( L_34 ) ;
return V_39 ;
}
