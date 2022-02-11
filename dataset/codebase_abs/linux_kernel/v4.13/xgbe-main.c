static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = 8 ;
V_2 -> V_9 = 8 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = 0 ;
F_2 ( L_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_27 ) ;
F_6 ( & V_2 -> V_28 ) ;
F_7 ( & V_2 -> V_29 ) ;
V_2 -> V_30 -> V_31 ( & V_2 -> V_27 ) ;
}
struct V_1 * F_8 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_9 ( sizeof( struct V_1 ) ,
V_36 ) ;
if ( ! V_35 ) {
F_10 ( V_33 , L_3 ) ;
return F_11 ( - V_37 ) ;
}
F_12 ( V_35 , V_33 ) ;
V_2 = F_13 ( V_35 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_33 = V_33 ;
F_14 ( & V_2 -> V_38 ) ;
F_14 ( & V_2 -> V_39 ) ;
F_15 ( & V_2 -> V_40 ) ;
F_14 ( & V_2 -> V_41 ) ;
F_15 ( & V_2 -> V_42 ) ;
F_16 ( & V_2 -> V_43 ) ;
F_16 ( & V_2 -> V_44 ) ;
V_2 -> V_45 = F_17 ( V_46 , V_47 ) ;
F_18 ( V_48 , & V_2 -> V_49 ) ;
F_18 ( V_50 , & V_2 -> V_49 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_20 ( V_35 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( ! V_2 -> V_51 )
V_2 -> V_51 = V_2 -> V_52 . V_53 ;
if ( ! V_2 -> V_54 )
V_2 -> V_54 = V_2 -> V_52 . V_55 ;
if ( ! V_2 -> V_56 )
V_2 -> V_56 = V_2 -> V_52 . V_57 ;
if ( ! V_2 -> V_58 )
V_2 -> V_58 = V_2 -> V_52 . V_59 ;
V_2 -> V_60 = F_23 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_60 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_channel_count) ;
V_2 -> V_60 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_q_count) ;
V_2 -> V_61 = V_2 -> V_60 ;
V_2 -> V_62 = F_23 (unsigned int, num_online_cpus(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_62 = F_23 (unsigned int, pdata->rx_ring_count,
pdata->rx_max_channel_count) ;
V_2 -> V_63 = F_23 (unsigned int, pdata->hw_feat.rx_q_cnt,
pdata->rx_max_q_count) ;
if ( F_24 ( V_2 ) ) {
F_25 ( V_2 -> V_33 , L_4 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
F_25 ( V_2 -> V_33 , L_5 ,
V_2 -> V_61 , V_2 -> V_63 ) ;
}
}
int F_26 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_32 * V_33 = V_2 -> V_33 ;
unsigned int V_64 ;
int V_65 ;
V_35 -> V_66 = V_2 -> V_67 ;
V_35 -> V_68 = ( unsigned long ) V_2 -> V_69 ;
memcpy ( V_35 -> V_70 , V_2 -> V_71 , V_35 -> V_72 ) ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_74 ;
V_2 -> V_76 = V_74 ;
V_2 -> V_77 = V_74 ;
V_2 -> V_78 = V_74 ;
V_2 -> V_79 = V_74 ;
V_65 = V_2 -> V_26 . exit ( V_2 ) ;
if ( V_65 ) {
F_10 ( V_33 , L_6 ) ;
return V_65 ;
}
F_1 ( V_2 ) ;
V_65 = F_27 ( V_33 ,
F_28 ( V_2 -> V_52 . V_80 ) ) ;
if ( V_65 ) {
F_10 ( V_33 , L_7 ) ;
return V_65 ;
}
if ( ! V_2 -> V_81 )
V_2 -> V_81 = V_2 -> V_52 . V_82 ;
if ( ! V_2 -> V_83 )
V_2 -> V_83 = V_2 -> V_52 . V_84 ;
F_29 ( V_85 ) ;
V_2 -> V_86 = V_85 ;
F_29 ( V_87 ) ;
V_2 -> V_88 = V_87 ;
if ( V_2 -> V_89 ) {
V_2 -> V_60 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->channel_irq_count) ;
V_2 -> V_62 = F_23 (unsigned int, pdata->rx_ring_count,
pdata->channel_irq_count) ;
if ( F_24 ( V_2 ) )
F_25 ( V_2 -> V_33 ,
L_8 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
}
V_65 = F_30 ( V_35 , V_2 -> V_60 ) ;
if ( V_65 ) {
F_10 ( V_33 , L_9 ) ;
return V_65 ;
}
V_65 = F_31 ( V_35 , V_2 -> V_62 ) ;
if ( V_65 ) {
F_10 ( V_33 , L_10 ) ;
return V_65 ;
}
F_32 ( V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) ;
for ( V_64 = 0 ; V_64 < V_91 ; V_64 ++ )
F_33 ( V_2 -> V_92 [ V_64 ] , V_93 , V_94 ,
V_64 % V_2 -> V_62 ) ;
F_33 ( V_2 -> V_95 , V_96 , V_97 , 1 ) ;
F_33 ( V_2 -> V_95 , V_96 , V_98 , 1 ) ;
F_33 ( V_2 -> V_95 , V_96 , V_99 , 1 ) ;
V_65 = V_2 -> V_27 . V_100 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_35 -> V_101 = F_34 () ;
V_35 -> V_102 = F_35 () ;
#ifdef F_36
V_35 -> V_103 = F_37 () ;
#endif
V_35 -> V_104 = V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 ;
if ( V_2 -> V_52 . V_115 )
V_35 -> V_104 |= V_116 ;
V_35 -> V_117 |= V_105 |
V_106 |
V_107 |
V_109 |
V_110 ;
V_35 -> V_118 |= V_35 -> V_104 ;
V_2 -> V_119 = V_35 -> V_118 ;
V_35 -> V_120 |= V_121 ;
V_35 -> V_122 = 0 ;
V_35 -> V_123 = V_124 ;
V_35 -> V_125 = 0 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_35 ) ;
V_65 = F_41 ( V_35 ) ;
if ( V_65 ) {
F_10 ( V_33 , L_11 ) ;
return V_65 ;
}
snprintf ( V_2 -> V_126 , sizeof( V_2 -> V_126 ) - 1 , L_12 ,
F_42 ( V_35 ) ) ;
snprintf ( V_2 -> V_127 , sizeof( V_2 -> V_127 ) - 1 , L_13 ,
F_42 ( V_35 ) ) ;
snprintf ( V_2 -> V_128 , sizeof( V_2 -> V_128 ) - 1 , L_14 ,
F_42 ( V_35 ) ) ;
V_2 -> V_129 =
F_43 ( F_42 ( V_35 ) ) ;
if ( ! V_2 -> V_129 ) {
F_44 ( V_35 , L_15 ) ;
V_65 = - V_37 ;
goto V_130;
}
V_2 -> V_131 =
F_43 ( V_2 -> V_126 ) ;
if ( ! V_2 -> V_131 ) {
F_44 ( V_35 , L_16 ) ;
V_65 = - V_37 ;
goto V_132;
}
if ( F_45 ( V_133 ) )
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 , V_134 , V_2 -> V_35 , L_17 ,
V_2 -> V_60 ) ;
F_48 ( V_2 , V_134 , V_2 -> V_35 , L_18 ,
V_2 -> V_62 ) ;
return 0 ;
V_132:
F_49 ( V_2 -> V_129 ) ;
V_130:
F_50 ( V_35 ) ;
return V_65 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_52 ( V_2 ) ;
if ( F_45 ( V_133 ) )
F_53 ( V_2 ) ;
V_2 -> V_27 . V_135 ( V_2 ) ;
F_54 ( V_2 -> V_131 ) ;
F_49 ( V_2 -> V_131 ) ;
F_54 ( V_2 -> V_129 ) ;
F_49 ( V_2 -> V_129 ) ;
F_50 ( V_35 ) ;
}
static int T_1 F_55 ( void )
{
int V_65 ;
V_65 = F_56 () ;
if ( V_65 )
return V_65 ;
V_65 = F_57 () ;
if ( V_65 )
return V_65 ;
return 0 ;
}
static void T_2 F_58 ( void )
{
F_59 () ;
F_60 () ;
}
