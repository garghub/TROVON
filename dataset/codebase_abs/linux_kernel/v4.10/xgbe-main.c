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
F_2 ( L_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_24 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_6 ( & V_2 -> V_26 ) ;
F_7 ( & V_2 -> V_27 ) ;
V_2 -> V_28 -> V_29 ( & V_2 -> V_25 ) ;
}
struct V_1 * F_8 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_33 = F_9 ( sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_33 ) {
F_10 ( V_31 , L_3 ) ;
return F_11 ( - V_35 ) ;
}
F_12 ( V_33 , V_31 ) ;
V_2 = F_13 ( V_33 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_31 = V_31 ;
F_14 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_38 ) ;
F_14 ( & V_2 -> V_39 ) ;
F_15 ( & V_2 -> V_40 ) ;
F_16 ( & V_2 -> V_41 ) ;
F_16 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = F_17 ( V_44 , V_45 ) ;
F_18 ( V_46 , & V_2 -> V_47 ) ;
F_18 ( V_48 , & V_2 -> V_47 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_20 ( V_33 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = V_2 -> V_50 . V_51 ;
if ( ! V_2 -> V_52 )
V_2 -> V_52 = V_2 -> V_50 . V_53 ;
if ( ! V_2 -> V_54 )
V_2 -> V_54 = V_2 -> V_50 . V_55 ;
if ( ! V_2 -> V_56 )
V_2 -> V_56 = V_2 -> V_50 . V_57 ;
V_2 -> V_58 = F_23 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_58 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_channel_count) ;
V_2 -> V_58 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_q_count) ;
V_2 -> V_59 = V_2 -> V_58 ;
V_2 -> V_60 = F_23 (unsigned int, num_online_cpus(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_60 = F_23 (unsigned int, pdata->rx_ring_count,
pdata->rx_max_channel_count) ;
V_2 -> V_61 = F_23 (unsigned int, pdata->hw_feat.rx_q_cnt,
pdata->rx_max_q_count) ;
if ( F_24 ( V_2 ) ) {
F_25 ( V_2 -> V_31 , L_4 ,
V_2 -> V_58 , V_2 -> V_60 ) ;
F_25 ( V_2 -> V_31 , L_5 ,
V_2 -> V_59 , V_2 -> V_61 ) ;
}
}
int F_26 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_30 * V_31 = V_2 -> V_31 ;
unsigned int V_62 ;
int V_63 ;
V_33 -> V_64 = V_2 -> V_65 ;
V_33 -> V_66 = ( unsigned long ) V_2 -> V_67 ;
memcpy ( V_33 -> V_68 , V_2 -> V_69 , V_33 -> V_70 ) ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_72 ;
V_2 -> V_74 = V_72 ;
V_2 -> V_75 = V_72 ;
V_2 -> V_76 = V_72 ;
V_2 -> V_77 = V_72 ;
V_2 -> V_24 . exit ( V_2 ) ;
F_1 ( V_2 ) ;
V_63 = F_27 ( V_31 ,
F_28 ( V_2 -> V_50 . V_78 ) ) ;
if ( V_63 ) {
F_10 ( V_31 , L_6 ) ;
return V_63 ;
}
if ( ! V_2 -> V_79 )
V_2 -> V_79 = V_2 -> V_50 . V_80 ;
if ( ! V_2 -> V_81 )
V_2 -> V_81 = V_2 -> V_50 . V_82 ;
F_29 ( V_83 ) ;
V_2 -> V_84 = V_83 ;
F_29 ( V_85 ) ;
V_2 -> V_86 = V_85 ;
if ( V_2 -> V_87 ) {
V_2 -> V_58 = F_23 (unsigned int, pdata->tx_ring_count,
pdata->channel_irq_count) ;
V_2 -> V_60 = F_23 (unsigned int, pdata->rx_ring_count,
pdata->channel_irq_count) ;
if ( F_24 ( V_2 ) )
F_25 ( V_2 -> V_31 ,
L_7 ,
V_2 -> V_58 , V_2 -> V_60 ) ;
}
V_63 = F_30 ( V_33 , V_2 -> V_58 ) ;
if ( V_63 ) {
F_10 ( V_31 , L_8 ) ;
return V_63 ;
}
V_63 = F_31 ( V_33 , V_2 -> V_60 ) ;
if ( V_63 ) {
F_10 ( V_31 , L_9 ) ;
return V_63 ;
}
F_32 ( V_2 -> V_88 , sizeof( V_2 -> V_88 ) ) ;
for ( V_62 = 0 ; V_62 < V_89 ; V_62 ++ )
F_33 ( V_2 -> V_90 [ V_62 ] , V_91 , V_92 ,
V_62 % V_2 -> V_60 ) ;
F_33 ( V_2 -> V_93 , V_94 , V_95 , 1 ) ;
F_33 ( V_2 -> V_93 , V_94 , V_96 , 1 ) ;
F_33 ( V_2 -> V_93 , V_94 , V_97 , 1 ) ;
V_63 = V_2 -> V_25 . V_98 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_33 -> V_99 = F_34 () ;
V_33 -> V_100 = F_35 () ;
#ifdef F_36
V_33 -> V_101 = F_37 () ;
#endif
V_33 -> V_102 = V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 ;
if ( V_2 -> V_50 . V_113 )
V_33 -> V_102 |= V_114 ;
V_33 -> V_115 |= V_103 |
V_104 |
V_105 |
V_107 |
V_108 ;
V_33 -> V_116 |= V_33 -> V_102 ;
V_2 -> V_117 = V_33 -> V_116 ;
V_33 -> V_118 |= V_119 ;
V_33 -> V_120 = 0 ;
V_33 -> V_121 = V_122 ;
V_33 -> V_123 = 0 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_33 ) ;
V_63 = F_41 ( V_33 ) ;
if ( V_63 ) {
F_10 ( V_31 , L_10 ) ;
return V_63 ;
}
snprintf ( V_2 -> V_124 , sizeof( V_2 -> V_124 ) - 1 , L_11 ,
F_42 ( V_33 ) ) ;
snprintf ( V_2 -> V_125 , sizeof( V_2 -> V_125 ) - 1 , L_12 ,
F_42 ( V_33 ) ) ;
snprintf ( V_2 -> V_126 , sizeof( V_2 -> V_126 ) - 1 , L_13 ,
F_42 ( V_33 ) ) ;
V_2 -> V_127 =
F_43 ( F_42 ( V_33 ) ) ;
if ( ! V_2 -> V_127 ) {
F_44 ( V_33 , L_14 ) ;
V_63 = - V_35 ;
goto V_128;
}
V_2 -> V_129 =
F_43 ( V_2 -> V_124 ) ;
if ( ! V_2 -> V_129 ) {
F_44 ( V_33 , L_15 ) ;
V_63 = - V_35 ;
goto V_130;
}
if ( F_45 ( V_131 ) )
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 , V_132 , V_2 -> V_33 , L_16 ,
V_2 -> V_58 ) ;
F_48 ( V_2 , V_132 , V_2 -> V_33 , L_17 ,
V_2 -> V_60 ) ;
return 0 ;
V_130:
F_49 ( V_2 -> V_127 ) ;
V_128:
F_50 ( V_33 ) ;
return V_63 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_52 ( V_2 ) ;
if ( F_45 ( V_131 ) )
F_53 ( V_2 ) ;
V_2 -> V_25 . V_133 ( V_2 ) ;
F_54 ( V_2 -> V_129 ) ;
F_49 ( V_2 -> V_129 ) ;
F_54 ( V_2 -> V_127 ) ;
F_49 ( V_2 -> V_127 ) ;
F_50 ( V_33 ) ;
}
static int T_1 F_55 ( void )
{
int V_63 ;
V_63 = F_56 () ;
if ( V_63 )
return V_63 ;
V_63 = F_57 () ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static void T_2 F_58 ( void )
{
F_59 () ;
F_60 () ;
}
