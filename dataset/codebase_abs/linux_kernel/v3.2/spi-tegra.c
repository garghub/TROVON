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
V_5 |= F_7 ( V_2 -> V_8 . V_9 / 4 - 1 ) ;
F_3 ( V_2 , V_5 , V_6 ) ;
F_8 ( V_2 -> V_10 , & V_2 -> V_8 ) ;
V_5 |= V_7 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
unsigned V_13 = F_10 ( V_12 -> V_13 - V_2 -> V_14 , V_15 *
V_2 -> V_16 ) ;
T_1 * V_17 = ( T_1 * ) V_12 -> V_17 + V_2 -> V_14 ;
int V_18 , V_19 ;
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_20 ) ;
V_5 &= ~ F_11 ( ~ 0 ) ;
V_5 |= F_11 ( V_13 / V_2 -> V_16 - 1 ) ;
F_3 ( V_2 , V_5 , V_20 ) ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 += V_2 -> V_16 ) {
V_5 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_16 ; V_19 ++ )
V_5 |= V_17 [ V_18 + V_19 ] << V_19 * 8 ;
F_3 ( V_2 , V_5 , V_21 ) ;
}
V_2 -> V_8 . V_9 = V_13 / V_2 -> V_16 * 4 ;
return V_13 ;
}
static unsigned F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
unsigned V_13 = V_2 -> V_22 ;
T_1 * V_23 = ( T_1 * ) V_12 -> V_23 + V_2 -> V_14 ;
int V_18 , V_19 ;
unsigned long V_5 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 += V_2 -> V_16 ) {
V_5 = V_2 -> V_24 [ V_18 / V_2 -> V_16 ] ;
for ( V_19 = 0 ; V_19 < V_2 -> V_16 ; V_19 ++ )
V_23 [ V_18 + V_19 ] = ( V_5 >> ( V_19 * 8 ) ) & 0xff ;
}
return V_13 ;
}
static void F_13 ( struct V_25 * V_26 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_14 ( V_26 -> V_27 ) ;
T_2 V_28 ;
T_1 V_29 ;
unsigned long V_5 ;
V_28 = V_12 -> V_30 ? V_12 -> V_30 : V_26 -> V_31 ;
V_29 = V_12 -> V_29 ? V_12 -> V_29 :
V_26 -> V_29 ;
V_2 -> V_16 = ( V_29 - 1 ) / 8 + 1 ;
if ( V_28 != V_2 -> V_32 )
F_15 ( V_2 -> V_33 , V_28 ) ;
if ( V_2 -> V_32 == 0 )
F_16 ( V_2 -> V_33 ) ;
V_2 -> V_32 = V_28 ;
V_5 = F_1 ( V_2 , V_34 ) ;
V_5 &= ~ F_17 ( ~ 0 ) | V_35 | V_36 ;
if ( V_12 -> V_23 )
V_5 |= V_35 ;
if ( V_12 -> V_17 )
V_5 |= V_36 ;
V_5 |= F_17 ( V_26 -> V_37 ) ;
V_5 |= V_38 ;
F_3 ( V_2 , V_5 , V_34 ) ;
V_5 = F_1 ( V_2 , V_20 ) ;
V_5 &= ~ F_18 ( ~ 0 ) ;
V_5 |= F_18 ( V_29 - 1 ) ;
V_5 &= ~ V_39 & ~ V_40 & ~ V_41 ;
if ( V_26 -> V_42 & V_43 )
V_5 |= V_40 ;
if ( V_26 -> V_42 & V_44 )
V_5 |= V_45 ;
else
V_5 |= V_46 ;
V_5 |= V_47 ;
F_3 ( V_2 , V_5 , V_20 ) ;
F_3 ( V_2 , V_48 | V_49 , V_50 ) ;
V_2 -> V_51 = V_12 ;
V_2 -> V_14 = 0 ;
V_2 -> V_22 = F_9 ( V_2 , V_12 ) ;
F_5 ( V_2 ) ;
}
static void F_19 ( struct V_25 * V_26 ,
struct V_52 * V_53 )
{
struct V_11 * V_12 ;
V_53 -> V_54 = 0 ;
V_53 -> V_55 = 0 ;
V_12 = F_20 ( & V_53 -> V_56 , struct V_11 , V_57 ) ;
F_13 ( V_26 , V_12 ) ;
}
static void F_21 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
unsigned long V_61 ;
struct V_52 * V_53 ;
struct V_25 * V_26 ;
int V_62 = 0 ;
unsigned long V_5 ;
while ( V_62 ++ < 1000 ) {
if ( ! ( F_1 ( V_2 , V_50 ) & V_63 ) )
break;
}
F_22 ( & V_2 -> V_64 , V_61 ) ;
V_5 = F_1 ( V_2 , V_50 ) ;
V_5 |= V_65 ;
F_3 ( V_2 , V_5 , V_50 ) ;
V_53 = F_20 ( & V_2 -> V_66 , struct V_52 , V_66 ) ;
if ( V_62 >= 1000 )
V_53 -> V_55 = - V_67 ;
V_26 = V_53 -> V_68 ;
V_2 -> V_14 += F_12 ( V_2 , V_2 -> V_51 ) ;
V_53 -> V_54 += V_2 -> V_14 ;
if ( V_2 -> V_14 < V_2 -> V_51 -> V_13 ) {
V_2 -> V_22 = F_9 ( V_2 , V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
} else if ( ! F_23 ( & V_2 -> V_51 -> V_57 ,
& V_53 -> V_56 ) ) {
V_2 -> V_51 = F_20 ( & V_2 -> V_51 -> V_57 ,
struct V_11 ,
V_57 ) ;
F_13 ( V_26 , V_2 -> V_51 ) ;
} else {
F_24 ( & V_53 -> V_66 ) ;
V_53 -> V_69 ( V_53 -> V_70 ) ;
if ( ! F_25 ( & V_2 -> V_66 ) ) {
V_53 = F_20 ( & V_2 -> V_66 , struct V_52 ,
V_66 ) ;
V_26 = V_53 -> V_68 ;
F_19 ( V_26 , V_53 ) ;
} else {
F_26 ( V_2 -> V_33 ) ;
V_2 -> V_32 = 0 ;
}
}
F_27 ( & V_2 -> V_64 , V_61 ) ;
}
static int F_28 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_14 ( V_26 -> V_27 ) ;
unsigned long V_71 ;
unsigned long V_5 ;
unsigned long V_61 ;
F_29 ( & V_26 -> V_60 , L_1 ,
V_26 -> V_29 ,
V_26 -> V_42 & V_44 ? L_2 : L_3 ,
V_26 -> V_42 & V_43 ? L_2 : L_3 ,
V_26 -> V_31 ) ;
switch ( V_26 -> V_37 ) {
case 0 :
V_71 = V_72 ;
break;
case 1 :
V_71 = V_73 ;
break;
case 2 :
V_71 = V_74 ;
break;
case 4 :
V_71 = V_75 ;
break;
default:
return - V_76 ;
}
F_22 ( & V_2 -> V_64 , V_61 ) ;
V_5 = F_1 ( V_2 , V_20 ) ;
if ( V_26 -> V_42 & V_77 )
V_5 |= V_71 ;
else
V_5 &= ~ V_71 ;
F_3 ( V_2 , V_5 , V_20 ) ;
F_27 ( & V_2 -> V_64 , V_61 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_26 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_14 ( V_26 -> V_27 ) ;
struct V_11 * V_12 ;
unsigned long V_61 ;
int V_78 ;
if ( F_25 ( & V_53 -> V_56 ) || ! V_53 -> V_69 )
return - V_76 ;
F_31 (t, &m->transfers, transfer_list) {
if ( V_12 -> V_29 < 0 || V_12 -> V_29 > 32 )
return - V_76 ;
if ( V_12 -> V_13 == 0 )
return - V_76 ;
if ( ! V_12 -> V_23 && ! V_12 -> V_17 )
return - V_76 ;
}
V_53 -> V_68 = V_26 ;
F_22 ( & V_2 -> V_64 , V_61 ) ;
V_78 = F_25 ( & V_2 -> V_66 ) ;
F_32 ( & V_53 -> V_66 , & V_2 -> V_66 ) ;
if ( V_78 )
F_19 ( V_26 , V_53 ) ;
F_27 ( & V_2 -> V_64 , V_61 ) ;
return 0 ;
}
static int T_3 F_33 ( struct V_79 * V_80 )
{
struct V_81 * V_27 ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
int V_84 ;
V_27 = F_34 ( & V_80 -> V_60 , sizeof *V_2 ) ;
if ( V_27 == NULL ) {
F_35 ( & V_80 -> V_60 , L_4 ) ;
return - V_85 ;
}
V_27 -> V_86 = V_44 | V_43 | V_77 ;
V_27 -> V_87 = V_80 -> V_88 ;
V_27 -> V_89 = F_28 ;
V_27 -> V_90 = F_30 ;
V_27 -> V_91 = 4 ;
F_36 ( & V_80 -> V_60 , V_27 ) ;
V_2 = F_14 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_80 = V_80 ;
F_37 ( & V_2 -> V_64 ) ;
V_83 = F_38 ( V_80 , V_92 , 0 ) ;
if ( V_83 == NULL ) {
V_84 = - V_93 ;
goto V_94;
}
if ( ! F_39 ( V_83 -> V_95 , F_40 ( V_83 ) ,
F_41 ( & V_80 -> V_60 ) ) ) {
V_84 = - V_96 ;
goto V_94;
}
V_2 -> V_97 = V_83 -> V_95 ;
V_2 -> V_4 = F_42 ( V_83 -> V_95 , F_40 ( V_83 ) ) ;
if ( ! V_2 -> V_4 ) {
F_35 ( & V_80 -> V_60 , L_5 ) ;
V_84 = - V_85 ;
goto V_98;
}
V_2 -> V_33 = F_43 ( & V_80 -> V_60 , NULL ) ;
if ( F_44 ( V_2 -> V_33 ) ) {
F_35 ( & V_80 -> V_60 , L_6 ) ;
V_84 = F_45 ( V_2 -> V_33 ) ;
goto V_99;
}
F_46 ( & V_2 -> V_66 ) ;
V_2 -> V_10 = F_47 ( V_100 ) ;
if ( ! V_2 -> V_10 ) {
F_35 ( & V_80 -> V_60 , L_7 ) ;
V_84 = - V_93 ;
goto V_101;
}
V_2 -> V_24 = F_48 ( & V_80 -> V_60 , sizeof( T_2 ) * V_15 ,
& V_2 -> V_102 , V_103 ) ;
if ( ! V_2 -> V_24 ) {
F_35 ( & V_80 -> V_60 , L_8 ) ;
V_84 = - V_85 ;
goto V_104;
}
V_2 -> V_8 . V_69 = F_21 ;
V_2 -> V_8 . V_105 = 1 ;
V_2 -> V_8 . V_106 = V_2 -> V_102 ;
V_2 -> V_8 . V_107 = 32 ;
V_2 -> V_8 . V_108 = V_2 -> V_97 + V_109 ;
V_2 -> V_8 . V_110 = 32 ;
V_2 -> V_8 . V_111 = 4 ;
V_2 -> V_8 . V_112 = V_113 [ V_80 -> V_88 ] ;
V_2 -> V_8 . V_60 = V_2 ;
V_27 -> V_60 . V_114 = V_80 -> V_60 . V_114 ;
V_84 = F_49 ( V_27 ) ;
if ( V_84 < 0 )
goto V_115;
return V_84 ;
V_115:
F_50 ( & V_80 -> V_60 , sizeof( T_2 ) * V_15 ,
V_2 -> V_24 , V_2 -> V_102 ) ;
V_104:
F_51 ( V_2 -> V_10 ) ;
V_101:
F_52 ( V_2 -> V_33 ) ;
V_99:
F_53 ( V_2 -> V_4 ) ;
V_98:
F_54 ( V_83 -> V_95 , F_40 ( V_83 ) ) ;
V_94:
F_55 ( V_27 ) ;
return V_84 ;
}
static int T_4 F_56 ( struct V_79 * V_80 )
{
struct V_81 * V_27 ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
V_27 = F_57 ( & V_80 -> V_60 ) ;
V_2 = F_14 ( V_27 ) ;
F_58 ( V_27 ) ;
F_51 ( V_2 -> V_10 ) ;
F_50 ( & V_80 -> V_60 , sizeof( T_2 ) * V_15 ,
V_2 -> V_24 , V_2 -> V_102 ) ;
F_52 ( V_2 -> V_33 ) ;
F_53 ( V_2 -> V_4 ) ;
V_83 = F_38 ( V_80 , V_92 , 0 ) ;
F_54 ( V_83 -> V_95 , F_40 ( V_83 ) ) ;
return 0 ;
}
