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
F_17 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = F_18 ( V_47 , V_48 ) ;
F_19 ( V_49 , & V_2 -> V_50 ) ;
F_19 ( V_51 , & V_2 -> V_50 ) ;
return V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_21 ( V_35 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! V_2 -> V_52 )
V_2 -> V_52 = V_2 -> V_53 . V_54 ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = V_2 -> V_53 . V_56 ;
if ( ! V_2 -> V_57 )
V_2 -> V_57 = V_2 -> V_53 . V_58 ;
if ( ! V_2 -> V_59 )
V_2 -> V_59 = V_2 -> V_53 . V_60 ;
V_2 -> V_61 = F_24 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_61 = F_24 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_channel_count) ;
V_2 -> V_61 = F_24 (unsigned int, pdata->tx_ring_count,
pdata->tx_max_q_count) ;
V_2 -> V_62 = V_2 -> V_61 ;
V_2 -> V_63 = F_24 (unsigned int, num_online_cpus(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_63 = F_24 (unsigned int, pdata->rx_ring_count,
pdata->rx_max_channel_count) ;
V_2 -> V_64 = F_24 (unsigned int, pdata->hw_feat.rx_q_cnt,
pdata->rx_max_q_count) ;
if ( F_25 ( V_2 ) ) {
F_26 ( V_2 -> V_33 , L_4 ,
V_2 -> V_61 , V_2 -> V_63 ) ;
F_26 ( V_2 -> V_33 , L_5 ,
V_2 -> V_62 , V_2 -> V_64 ) ;
}
}
int F_27 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_32 * V_33 = V_2 -> V_33 ;
unsigned int V_65 ;
int V_66 ;
V_35 -> V_67 = V_2 -> V_68 ;
V_35 -> V_69 = ( unsigned long ) V_2 -> V_70 ;
memcpy ( V_35 -> V_71 , V_2 -> V_72 , V_35 -> V_73 ) ;
V_2 -> V_74 = V_75 ;
V_2 -> V_76 = V_75 ;
V_2 -> V_77 = V_75 ;
V_2 -> V_78 = V_75 ;
V_2 -> V_79 = V_75 ;
V_2 -> V_80 = V_75 ;
V_66 = V_2 -> V_26 . exit ( V_2 ) ;
if ( V_66 ) {
F_10 ( V_33 , L_6 ) ;
return V_66 ;
}
F_1 ( V_2 ) ;
V_66 = F_28 ( V_33 ,
F_29 ( V_2 -> V_53 . V_81 ) ) ;
if ( V_66 ) {
F_10 ( V_33 , L_7 ) ;
return V_66 ;
}
if ( ! V_2 -> V_82 )
V_2 -> V_82 = V_2 -> V_53 . V_83 ;
if ( ! V_2 -> V_84 )
V_2 -> V_84 = V_2 -> V_53 . V_85 ;
F_30 ( V_86 ) ;
V_2 -> V_87 = V_86 ;
F_30 ( V_88 ) ;
V_2 -> V_89 = V_88 ;
if ( V_2 -> V_90 ) {
V_2 -> V_61 = F_24 (unsigned int, pdata->tx_ring_count,
pdata->channel_irq_count) ;
V_2 -> V_63 = F_24 (unsigned int, pdata->rx_ring_count,
pdata->channel_irq_count) ;
if ( F_25 ( V_2 ) )
F_26 ( V_2 -> V_33 ,
L_8 ,
V_2 -> V_61 , V_2 -> V_63 ) ;
}
V_66 = F_31 ( V_35 , V_2 -> V_61 ) ;
if ( V_66 ) {
F_10 ( V_33 , L_9 ) ;
return V_66 ;
}
V_66 = F_32 ( V_35 , V_2 -> V_63 ) ;
if ( V_66 ) {
F_10 ( V_33 , L_10 ) ;
return V_66 ;
}
F_33 ( V_2 -> V_91 , sizeof( V_2 -> V_91 ) ) ;
for ( V_65 = 0 ; V_65 < V_92 ; V_65 ++ )
F_34 ( V_2 -> V_93 [ V_65 ] , V_94 , V_95 ,
V_65 % V_2 -> V_63 ) ;
F_34 ( V_2 -> V_96 , V_97 , V_98 , 1 ) ;
F_34 ( V_2 -> V_96 , V_97 , V_99 , 1 ) ;
F_34 ( V_2 -> V_96 , V_97 , V_100 , 1 ) ;
V_66 = V_2 -> V_27 . V_101 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_35 -> V_102 = F_35 () ;
V_35 -> V_103 = F_36 () ;
#ifdef F_37
V_35 -> V_104 = F_38 () ;
#endif
V_35 -> V_105 = V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
if ( V_2 -> V_53 . V_116 )
V_35 -> V_105 |= V_117 ;
if ( V_2 -> V_53 . V_118 ) {
V_35 -> V_119 = V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_120 |
V_121 |
V_122 ;
V_35 -> V_105 |= V_120 |
V_121 |
V_122 ;
V_2 -> V_123 = 1 ;
V_2 -> V_124 = V_120 |
V_121 |
V_122 ;
}
V_35 -> V_125 |= V_106 |
V_107 |
V_108 |
V_110 |
V_111 ;
V_35 -> V_126 |= V_35 -> V_105 ;
V_2 -> V_127 = V_35 -> V_126 ;
V_35 -> V_128 |= V_129 ;
V_35 -> V_130 = 0 ;
V_35 -> V_131 = V_132 ;
V_35 -> V_133 = 0 ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_35 ) ;
V_66 = F_42 ( V_35 ) ;
if ( V_66 ) {
F_10 ( V_33 , L_11 ) ;
return V_66 ;
}
if ( F_43 ( V_134 ) )
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 , V_135 , V_2 -> V_35 , L_12 ,
V_2 -> V_61 ) ;
F_46 ( V_2 , V_135 , V_2 -> V_35 , L_13 ,
V_2 -> V_63 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
F_48 ( V_2 ) ;
if ( F_43 ( V_134 ) )
F_49 ( V_2 ) ;
F_50 ( V_35 ) ;
V_2 -> V_27 . V_136 ( V_2 ) ;
}
static int F_51 ( struct V_137 * V_138 , unsigned long V_139 ,
void * V_140 )
{
struct V_34 * V_35 = F_52 ( V_140 ) ;
struct V_1 * V_2 = F_13 ( V_35 ) ;
if ( V_35 -> V_102 != F_35 () )
goto V_141;
switch ( V_139 ) {
case V_142 :
F_53 ( V_2 ) ;
break;
default:
break;
}
V_141:
return V_143 ;
}
static int T_1 F_54 ( void )
{
int V_66 ;
V_66 = F_55 ( & V_144 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_56 () ;
if ( V_66 )
return V_66 ;
V_66 = F_57 () ;
if ( V_66 )
return V_66 ;
return 0 ;
}
static void T_2 F_58 ( void )
{
F_59 () ;
F_60 () ;
F_61 ( & V_144 ) ;
}
