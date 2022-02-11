static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 , V_10 ;
F_2 ( L_1 ) ;
V_9 = F_3 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
V_4 = F_4 ( V_3 -> V_11 , V_9 ,
sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_4 )
return NULL ;
V_7 = F_4 ( V_3 -> V_11 , V_3 -> V_13 ,
sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_7 )
return NULL ;
V_8 = F_4 ( V_3 -> V_11 , V_3 -> V_14 ,
sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_8 )
return NULL ;
for ( V_10 = 0 , V_5 = V_4 ; V_10 < V_9 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_15 , sizeof( V_5 -> V_15 ) , L_2 , V_10 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_16 = V_10 ;
V_5 -> V_17 = V_3 -> V_18 + V_19 +
( V_20 * V_10 ) ;
if ( V_10 < V_3 -> V_13 ) {
F_5 ( & V_7 -> V_21 ) ;
V_5 -> V_7 = V_7 ++ ;
}
if ( V_10 < V_3 -> V_14 ) {
F_5 ( & V_8 -> V_21 ) ;
V_5 -> V_8 = V_8 ++ ;
}
F_2 ( L_3 ,
V_5 -> V_15 , V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
V_3 -> V_22 = V_9 ;
F_2 ( L_4 ) ;
return V_4 ;
}
static void F_6 ( struct V_2 * V_3 )
{
F_2 ( L_5 ) ;
V_3 -> V_23 = V_24 ;
V_3 -> V_25 = V_26 ;
V_3 -> V_27 = V_28 ;
V_3 -> V_29 = V_30 ;
V_3 -> V_31 = V_32 ;
V_3 -> V_33 = V_34 ;
V_3 -> V_35 = V_36 ;
V_3 -> V_37 = V_30 ;
V_3 -> V_38 = 1 ;
V_3 -> V_39 = 1 ;
V_3 -> V_40 = 1 ;
V_3 -> V_41 = 0 ;
V_3 -> V_42 = V_43 ;
V_3 -> V_44 = V_45 ;
F_2 ( L_6 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_46 ) ;
F_9 ( & V_3 -> V_47 ) ;
}
static int F_10 ( struct V_48 * V_49 )
{
struct V_2 * V_3 ;
struct V_50 * V_46 ;
struct V_51 * V_47 ;
struct V_52 * V_53 ;
struct V_54 * V_11 = & V_49 -> V_11 ;
struct V_55 * V_56 ;
const T_1 * V_57 ;
int V_58 ;
F_2 ( L_7 ) ;
V_53 = F_11 ( sizeof( struct V_2 ) ,
V_59 ) ;
if ( ! V_53 ) {
F_12 ( V_11 , L_8 ) ;
V_58 = - V_60 ;
goto V_61;
}
F_13 ( V_53 , V_11 ) ;
V_3 = F_14 ( V_53 ) ;
V_3 -> V_53 = V_53 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_11 = V_11 ;
F_15 ( V_49 , V_53 ) ;
F_5 ( & V_3 -> V_21 ) ;
F_16 ( & V_3 -> V_62 ) ;
F_5 ( & V_3 -> V_63 ) ;
F_17 ( V_64 ) ;
V_3 -> V_65 = V_64 ;
if ( V_3 -> V_65 & ( V_3 -> V_65 - 1 ) ) {
F_12 ( V_11 , L_9 ,
V_3 -> V_65 ) ;
V_58 = - V_66 ;
goto V_67;
}
F_17 ( V_68 ) ;
V_3 -> V_69 = V_68 ;
if ( V_3 -> V_69 & ( V_3 -> V_69 - 1 ) ) {
F_12 ( V_11 , L_10 ,
V_3 -> V_69 ) ;
V_58 = - V_66 ;
goto V_67;
}
V_3 -> V_70 = F_18 ( V_11 , V_71 ) ;
if ( F_19 ( V_3 -> V_70 ) ) {
F_12 ( V_11 , L_11 ) ;
V_58 = F_20 ( V_3 -> V_70 ) ;
goto V_67;
}
V_3 -> V_72 = F_18 ( V_11 , V_73 ) ;
if ( F_19 ( V_3 -> V_72 ) ) {
F_12 ( V_11 , L_12 ) ;
V_58 = F_20 ( V_3 -> V_72 ) ;
goto V_67;
}
V_56 = F_21 ( V_49 , V_74 , 0 ) ;
V_3 -> V_18 = F_22 ( V_11 , V_56 ) ;
if ( F_19 ( V_3 -> V_18 ) ) {
F_12 ( V_11 , L_13 ) ;
V_58 = F_20 ( V_3 -> V_18 ) ;
goto V_67;
}
F_2 ( L_14 , V_3 -> V_18 ) ;
V_56 = F_21 ( V_49 , V_74 , 1 ) ;
V_3 -> V_75 = F_22 ( V_11 , V_56 ) ;
if ( F_19 ( V_3 -> V_75 ) ) {
F_12 ( V_11 , L_15 ) ;
V_58 = F_20 ( V_3 -> V_75 ) ;
goto V_67;
}
F_2 ( L_16 , V_3 -> V_75 ) ;
if ( ! V_11 -> V_76 )
V_11 -> V_76 = & V_11 -> V_77 ;
V_58 = F_23 ( V_11 , F_24 ( 40 ) ) ;
if ( V_58 ) {
F_12 ( V_11 , L_17 ) ;
goto V_67;
}
if ( F_25 ( V_11 -> V_78 , L_18 ) ) {
V_3 -> V_79 = V_80 ;
V_3 -> V_81 = V_82 ;
V_3 -> V_83 = V_84 ;
} else {
V_3 -> V_79 = V_85 ;
V_3 -> V_81 = V_86 ;
V_3 -> V_83 = V_87 ;
}
V_58 = F_26 ( V_49 , 0 ) ;
if ( V_58 < 0 ) {
F_12 ( V_11 , L_19 ) ;
goto V_67;
}
V_53 -> V_88 = V_58 ;
V_53 -> V_89 = ( unsigned long ) V_3 -> V_18 ;
F_7 ( V_3 ) ;
V_46 = & V_3 -> V_46 ;
V_47 = & V_3 -> V_47 ;
V_46 -> exit ( V_3 ) ;
F_27 ( V_3 ) ;
V_57 = F_28 ( V_11 -> V_78 ) ;
if ( ! V_57 ) {
F_12 ( V_11 , L_20 ) ;
V_58 = - V_66 ;
goto V_67;
}
memcpy ( V_53 -> V_90 , V_57 , V_53 -> V_91 ) ;
V_3 -> V_92 = F_29 ( V_11 -> V_78 ) ;
if ( V_3 -> V_92 != V_93 ) {
F_12 ( V_11 , L_21 ) ;
V_58 = - V_66 ;
goto V_67;
}
F_6 ( V_3 ) ;
V_3 -> V_13 = F_30 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_3 -> V_94 = V_3 -> V_13 ;
V_58 = F_31 ( V_53 , V_3 -> V_13 ) ;
if ( V_58 ) {
F_12 ( V_11 , L_22 ) ;
goto V_67;
}
V_3 -> V_14 = F_30 (unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt) ;
V_3 -> V_95 = V_3 -> V_96 . V_97 ;
V_58 = F_32 ( V_53 , V_3 -> V_14 ) ;
if ( V_58 ) {
F_12 ( V_11 , L_23 ) ;
goto V_67;
}
V_3 -> V_5 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_5 ) {
F_12 ( V_11 , L_24 ) ;
V_58 = - V_60 ;
goto V_67;
}
V_3 -> V_98 = F_33 ( V_12 , L_25 , V_49 -> V_15 ) ;
if ( ! V_3 -> V_98 ) {
F_12 ( V_11 , L_26 ) ;
V_58 = - V_60 ;
goto V_67;
}
V_58 = F_34 ( V_3 ) ;
if ( V_58 )
goto V_99;
V_53 -> V_100 = F_35 () ;
V_53 -> V_101 = F_36 () ;
#ifdef F_37
V_53 -> V_102 = F_38 () ;
#endif
V_53 -> V_103 = V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
V_53 -> V_114 |= V_104 |
V_105 |
V_106 |
V_108 |
V_109 ;
V_53 -> V_115 |= V_53 -> V_103 ;
V_3 -> V_116 = V_53 -> V_115 ;
V_53 -> V_117 |= V_118 ;
F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
F_41 ( V_53 ) ;
V_58 = F_42 ( V_53 ) ;
if ( V_58 ) {
F_12 ( V_11 , L_27 ) ;
goto V_119;
}
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_53 , L_28 ) ;
F_2 ( L_29 ) ;
return 0 ;
V_119:
F_46 ( V_3 ) ;
V_99:
F_47 ( V_3 -> V_98 ) ;
V_67:
F_48 ( V_53 ) ;
V_61:
F_49 ( V_11 , L_30 ) ;
return V_58 ;
}
static int F_50 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = F_51 ( V_49 ) ;
struct V_2 * V_3 = F_14 ( V_53 ) ;
F_2 ( L_31 ) ;
F_52 ( V_3 ) ;
F_53 ( V_3 ) ;
F_54 ( V_53 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 -> V_98 ) ;
F_48 ( V_53 ) ;
F_2 ( L_32 ) ;
return 0 ;
}
static int F_55 ( struct V_54 * V_11 )
{
struct V_52 * V_53 = F_56 ( V_11 ) ;
int V_58 ;
F_2 ( L_33 ) ;
if ( ! F_57 ( V_53 ) ) {
F_2 ( L_34 ) ;
return - V_66 ;
}
V_58 = F_58 ( V_53 , V_120 ) ;
F_2 ( L_35 ) ;
return V_58 ;
}
static int F_59 ( struct V_54 * V_11 )
{
struct V_52 * V_53 = F_56 ( V_11 ) ;
int V_58 ;
F_2 ( L_36 ) ;
if ( ! F_57 ( V_53 ) ) {
F_2 ( L_37 ) ;
return - V_66 ;
}
V_58 = F_60 ( V_53 , V_120 ) ;
F_2 ( L_38 ) ;
return V_58 ;
}
