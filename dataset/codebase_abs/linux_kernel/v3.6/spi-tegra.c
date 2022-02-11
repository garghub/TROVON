static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 ,
unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
F_6 () ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ F_7 ( ~ 0 ) & ~ V_7 ;
V_5 |= F_7 ( V_2 -> V_8 / 4 - 1 ) ;
F_3 ( V_2 , V_5 , V_6 ) ;
#if F_8 ( V_9 )
V_2 -> V_10 . V_11 = V_2 -> V_8 ;
F_9 ( V_2 -> V_12 , & V_2 -> V_10 ) ;
#else
V_2 -> V_13 = F_10 ( V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_8 ,
V_15 , V_16 ) ;
if ( ! V_2 -> V_13 ) {
F_11 ( & V_2 -> V_17 -> V_18 , L_1 ) ;
return;
}
V_2 -> V_13 -> V_19 = V_20 ;
V_2 -> V_13 -> V_21 = V_2 ;
V_2 -> V_22 = F_12 ( V_2 -> V_13 ) ;
F_13 ( V_2 -> V_12 ) ;
#endif
V_5 |= V_7 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static unsigned F_14 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
unsigned V_25 = F_15 ( V_24 -> V_25 - V_2 -> V_26 , V_27 *
V_2 -> V_28 ) ;
T_1 * V_29 = ( T_1 * ) V_24 -> V_29 + V_2 -> V_26 ;
int V_30 , V_31 ;
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_32 ) ;
V_5 &= ~ F_16 ( ~ 0 ) ;
V_5 |= F_16 ( V_25 / V_2 -> V_28 - 1 ) ;
F_3 ( V_2 , V_5 , V_32 ) ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 += V_2 -> V_28 ) {
V_5 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_28 ; V_31 ++ )
V_5 |= V_29 [ V_30 + V_31 ] << V_31 * 8 ;
F_3 ( V_2 , V_5 , V_33 ) ;
}
V_2 -> V_8 = V_25 / V_2 -> V_28 * 4 ;
return V_25 ;
}
static unsigned F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
unsigned V_25 = V_2 -> V_34 ;
T_1 * V_35 = ( T_1 * ) V_24 -> V_35 + V_2 -> V_26 ;
int V_30 , V_31 ;
unsigned long V_5 ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 += V_2 -> V_28 ) {
V_5 = V_2 -> V_36 [ V_30 / V_2 -> V_28 ] ;
for ( V_31 = 0 ; V_31 < V_2 -> V_28 ; V_31 ++ )
V_35 [ V_30 + V_31 ] = ( V_5 >> ( V_31 * 8 ) ) & 0xff ;
}
return V_25 ;
}
static void F_18 ( struct V_37 * V_38 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_19 ( V_38 -> V_39 ) ;
T_2 V_40 ;
T_1 V_41 ;
unsigned long V_5 ;
V_40 = V_24 -> V_42 ? V_24 -> V_42 : V_38 -> V_43 ;
V_41 = V_24 -> V_41 ? V_24 -> V_41 :
V_38 -> V_41 ;
V_2 -> V_28 = ( V_41 - 1 ) / 8 + 1 ;
if ( V_40 != V_2 -> V_44 )
F_20 ( V_2 -> V_45 , V_40 ) ;
if ( V_2 -> V_44 == 0 )
F_21 ( V_2 -> V_45 ) ;
V_2 -> V_44 = V_40 ;
V_5 = F_1 ( V_2 , V_46 ) ;
V_5 &= ~ F_22 ( ~ 0 ) | V_47 | V_48 ;
if ( V_24 -> V_35 )
V_5 |= V_47 ;
if ( V_24 -> V_29 )
V_5 |= V_48 ;
V_5 |= F_22 ( V_38 -> V_49 ) ;
V_5 |= V_50 ;
F_3 ( V_2 , V_5 , V_46 ) ;
V_5 = F_1 ( V_2 , V_32 ) ;
V_5 &= ~ F_23 ( ~ 0 ) ;
V_5 |= F_23 ( V_41 - 1 ) ;
V_5 &= ~ V_51 & ~ V_52 & ~ V_53 ;
if ( V_38 -> V_54 & V_55 )
V_5 |= V_52 ;
if ( V_38 -> V_54 & V_56 )
V_5 |= V_57 ;
else
V_5 |= V_58 ;
V_5 |= V_59 ;
F_3 ( V_2 , V_5 , V_32 ) ;
F_3 ( V_2 , V_60 | V_61 , V_62 ) ;
V_2 -> V_63 = V_24 ;
V_2 -> V_26 = 0 ;
V_2 -> V_34 = F_14 ( V_2 , V_24 ) ;
F_5 ( V_2 ) ;
}
static void F_24 ( struct V_37 * V_38 ,
struct V_64 * V_65 )
{
struct V_23 * V_24 ;
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
V_24 = F_25 ( & V_65 -> V_68 , struct V_23 , V_69 ) ;
F_18 ( V_38 , V_24 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_70 ;
struct V_64 * V_65 ;
struct V_37 * V_38 ;
int V_71 = 0 ;
unsigned long V_5 ;
while ( V_71 ++ < 1000 ) {
if ( ! ( F_1 ( V_2 , V_62 ) & V_72 ) )
break;
}
F_27 ( & V_2 -> V_73 , V_70 ) ;
V_5 = F_1 ( V_2 , V_62 ) ;
V_5 |= V_74 ;
F_3 ( V_2 , V_5 , V_62 ) ;
V_65 = F_25 ( & V_2 -> V_75 , struct V_64 , V_75 ) ;
if ( V_71 >= 1000 )
V_65 -> V_67 = - V_76 ;
V_38 = V_65 -> V_77 ;
V_2 -> V_26 += F_17 ( V_2 , V_2 -> V_63 ) ;
V_65 -> V_66 += V_2 -> V_26 ;
if ( V_2 -> V_26 < V_2 -> V_63 -> V_25 ) {
V_2 -> V_34 = F_14 ( V_2 , V_2 -> V_63 ) ;
F_5 ( V_2 ) ;
} else if ( ! F_28 ( & V_2 -> V_63 -> V_69 ,
& V_65 -> V_68 ) ) {
V_2 -> V_63 = F_25 ( & V_2 -> V_63 -> V_69 ,
struct V_23 ,
V_69 ) ;
F_18 ( V_38 , V_2 -> V_63 ) ;
} else {
F_29 ( & V_65 -> V_75 ) ;
V_65 -> V_78 ( V_65 -> V_79 ) ;
if ( ! F_30 ( & V_2 -> V_75 ) ) {
V_65 = F_25 ( & V_2 -> V_75 , struct V_64 ,
V_75 ) ;
V_38 = V_65 -> V_77 ;
F_24 ( V_38 , V_65 ) ;
} else {
F_31 ( V_2 -> V_45 ) ;
V_2 -> V_44 = 0 ;
}
}
F_32 ( & V_2 -> V_73 , V_70 ) ;
}
static void V_20 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_18 ;
F_26 ( V_2 ) ;
}
static void V_20 ( void * args )
{
struct V_1 * V_2 = args ;
F_26 ( V_2 ) ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_19 ( V_38 -> V_39 ) ;
unsigned long V_82 ;
unsigned long V_5 ;
unsigned long V_70 ;
F_34 ( & V_38 -> V_18 , L_2 ,
V_38 -> V_41 ,
V_38 -> V_54 & V_56 ? L_3 : L_4 ,
V_38 -> V_54 & V_55 ? L_3 : L_4 ,
V_38 -> V_43 ) ;
switch ( V_38 -> V_49 ) {
case 0 :
V_82 = V_83 ;
break;
case 1 :
V_82 = V_84 ;
break;
case 2 :
V_82 = V_85 ;
break;
case 4 :
V_82 = V_86 ;
break;
default:
return - V_87 ;
}
F_27 ( & V_2 -> V_73 , V_70 ) ;
V_5 = F_1 ( V_2 , V_32 ) ;
if ( V_38 -> V_54 & V_88 )
V_5 |= V_82 ;
else
V_5 &= ~ V_82 ;
F_3 ( V_2 , V_5 , V_32 ) ;
F_32 ( & V_2 -> V_73 , V_70 ) ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 , struct V_64 * V_65 )
{
struct V_1 * V_2 = F_19 ( V_38 -> V_39 ) ;
struct V_23 * V_24 ;
unsigned long V_70 ;
int V_89 ;
if ( F_30 ( & V_65 -> V_68 ) || ! V_65 -> V_78 )
return - V_87 ;
F_36 (t, &m->transfers, transfer_list) {
if ( V_24 -> V_41 < 0 || V_24 -> V_41 > 32 )
return - V_87 ;
if ( V_24 -> V_25 == 0 )
return - V_87 ;
if ( ! V_24 -> V_35 && ! V_24 -> V_29 )
return - V_87 ;
}
V_65 -> V_77 = V_38 ;
F_27 ( & V_2 -> V_73 , V_70 ) ;
V_89 = F_30 ( & V_2 -> V_75 ) ;
F_37 ( & V_65 -> V_75 , & V_2 -> V_75 ) ;
if ( V_89 )
F_24 ( V_38 , V_65 ) ;
F_32 ( & V_2 -> V_73 , V_70 ) ;
return 0 ;
}
static int T_3 F_38 ( struct V_90 * V_17 )
{
struct V_91 * V_39 ;
struct V_1 * V_2 ;
struct V_92 * V_93 ;
int V_94 ;
#if ! F_8 ( V_9 )
T_4 V_95 ;
#endif
V_39 = F_39 ( & V_17 -> V_18 , sizeof *V_2 ) ;
if ( V_39 == NULL ) {
F_11 ( & V_17 -> V_18 , L_5 ) ;
return - V_96 ;
}
V_39 -> V_97 = V_56 | V_55 | V_88 ;
V_39 -> V_98 = V_17 -> V_99 ;
V_39 -> V_100 = F_33 ;
V_39 -> V_101 = F_35 ;
V_39 -> V_102 = 4 ;
F_40 ( & V_17 -> V_18 , V_39 ) ;
V_2 = F_19 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_17 = V_17 ;
F_41 ( & V_2 -> V_73 ) ;
V_93 = F_42 ( V_17 , V_103 , 0 ) ;
if ( V_93 == NULL ) {
V_94 = - V_104 ;
goto V_105;
}
if ( ! F_43 ( V_93 -> V_106 , F_44 ( V_93 ) ,
F_45 ( & V_17 -> V_18 ) ) ) {
V_94 = - V_107 ;
goto V_105;
}
V_2 -> V_108 = V_93 -> V_106 ;
V_2 -> V_4 = F_46 ( V_93 -> V_106 , F_44 ( V_93 ) ) ;
if ( ! V_2 -> V_4 ) {
F_11 ( & V_17 -> V_18 , L_6 ) ;
V_94 = - V_96 ;
goto V_109;
}
V_2 -> V_45 = F_47 ( & V_17 -> V_18 , NULL ) ;
if ( F_48 ( V_2 -> V_45 ) ) {
F_11 ( & V_17 -> V_18 , L_7 ) ;
V_94 = F_49 ( V_2 -> V_45 ) ;
goto V_110;
}
F_50 ( & V_2 -> V_75 ) ;
#if F_8 ( V_9 )
V_2 -> V_12 = F_51 ( V_111 ) ;
if ( ! V_2 -> V_12 ) {
F_11 ( & V_17 -> V_18 , L_8 ) ;
V_94 = - V_104 ;
goto V_112;
}
#else
F_52 ( V_95 ) ;
F_53 ( V_113 , V_95 ) ;
V_2 -> V_12 = F_54 ( V_95 , NULL , NULL ) ;
if ( ! V_2 -> V_12 ) {
F_11 ( & V_17 -> V_18 , L_8 ) ;
V_94 = - V_104 ;
goto V_112;
}
#endif
V_2 -> V_36 = F_55 ( & V_17 -> V_18 , sizeof( T_2 ) * V_27 ,
& V_2 -> V_14 , V_114 ) ;
if ( ! V_2 -> V_36 ) {
F_11 ( & V_17 -> V_18 , L_9 ) ;
V_94 = - V_96 ;
goto V_115;
}
#if F_8 ( V_9 )
V_2 -> V_10 . V_78 = V_20 ;
V_2 -> V_10 . V_116 = 1 ;
V_2 -> V_10 . V_117 = V_2 -> V_14 ;
V_2 -> V_10 . V_118 = 32 ;
V_2 -> V_10 . V_119 = V_2 -> V_108 + V_120 ;
V_2 -> V_10 . V_121 = 32 ;
V_2 -> V_10 . V_122 = 4 ;
V_2 -> V_10 . V_123 = V_124 [ V_17 -> V_99 ] ;
V_2 -> V_10 . V_18 = V_2 ;
#else
V_2 -> V_125 . V_126 = V_2 -> V_108 + V_120 ;
V_2 -> V_125 . V_127 = V_2 -> V_108 + V_120 ;
V_2 -> V_125 . V_128 = V_129 ;
V_2 -> V_125 . V_130 = V_129 ;
V_2 -> V_125 . V_131 = V_124 [ V_17 -> V_99 ] ;
V_2 -> V_125 . V_132 = 1 ;
V_2 -> V_125 . V_133 = 1 ;
V_94 = F_56 ( V_2 -> V_12 ,
V_134 , ( unsigned long ) & V_2 -> V_125 ) ;
if ( V_94 < 0 ) {
F_11 ( & V_17 -> V_18 , L_10 ,
V_94 ) ;
goto V_115;
}
#endif
V_39 -> V_18 . V_135 = V_17 -> V_18 . V_135 ;
V_94 = F_57 ( V_39 ) ;
if ( V_94 < 0 )
goto V_136;
return V_94 ;
V_136:
F_58 ( & V_17 -> V_18 , sizeof( T_2 ) * V_27 ,
V_2 -> V_36 , V_2 -> V_14 ) ;
V_115:
#if F_8 ( V_9 )
F_59 ( V_2 -> V_12 ) ;
#else
F_60 ( V_2 -> V_12 ) ;
#endif
V_112:
F_61 ( V_2 -> V_45 ) ;
V_110:
F_62 ( V_2 -> V_4 ) ;
V_109:
F_63 ( V_93 -> V_106 , F_44 ( V_93 ) ) ;
V_105:
F_64 ( V_39 ) ;
return V_94 ;
}
static int T_5 F_65 ( struct V_90 * V_17 )
{
struct V_91 * V_39 ;
struct V_1 * V_2 ;
struct V_92 * V_93 ;
V_39 = F_66 ( & V_17 -> V_18 ) ;
V_2 = F_19 ( V_39 ) ;
F_67 ( V_39 ) ;
#if F_8 ( V_9 )
F_59 ( V_2 -> V_12 ) ;
#else
F_60 ( V_2 -> V_12 ) ;
#endif
F_58 ( & V_17 -> V_18 , sizeof( T_2 ) * V_27 ,
V_2 -> V_36 , V_2 -> V_14 ) ;
F_61 ( V_2 -> V_45 ) ;
F_62 ( V_2 -> V_4 ) ;
V_93 = F_42 ( V_17 , V_103 , 0 ) ;
F_63 ( V_93 -> V_106 , F_44 ( V_93 ) ) ;
return 0 ;
}
