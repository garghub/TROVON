static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 [ 2 ] ;
if ( ! V_2 -> V_8 ) {
F_2 ( & V_2 -> V_6 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_7 [ 0 ] = V_3 & 0xff ;
V_7 [ 1 ] = V_4 & 0xff ;
if ( F_3 ( V_6 , V_7 , 2 ) == 2 )
return 0 ;
F_2 ( & V_2 -> V_6 -> V_9 , L_2 ) ;
F_2 ( & V_2 -> V_6 -> V_9 , L_3 ) ;
return - V_10 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! V_2 -> V_8 ) {
F_2 ( & V_2 -> V_6 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_4 [ 0 ] = F_5 ( V_6 , V_3 & 0xff ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 * V_4 , T_1 V_11 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_14 ;
struct V_15 V_16 [ 2 ] ;
T_1 V_17 ;
if ( ! V_2 -> V_8 ) {
F_2 ( & V_2 -> V_6 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_17 = V_3 & 0xff ;
V_16 [ 0 ] . V_18 = V_6 -> V_18 ;
V_16 [ 0 ] . V_19 = V_6 -> V_19 & V_20 ;
V_16 [ 0 ] . V_21 = 1 ;
V_16 [ 0 ] . V_17 = & V_17 ;
V_16 [ 1 ] . V_18 = V_6 -> V_18 ;
V_16 [ 1 ] . V_19 = V_6 -> V_19 & V_20 ;
V_16 [ 1 ] . V_19 |= V_22 ;
V_16 [ 1 ] . V_21 = V_11 ;
V_16 [ 1 ] . V_17 = V_4 ;
return F_7 ( V_13 , V_16 , 2 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_23 )
{
int V_24 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
if ( V_23 ) {
V_2 -> V_8 = V_26 ;
V_2 -> V_27 |= V_28 ;
} else {
V_2 -> V_27 &= ~ V_28 ;
}
if ( V_23 )
V_24 = F_1 ( V_2 , V_29 ,
V_2 -> V_27 ) ;
F_10 ( V_30 ) ;
if ( ! V_23 )
V_2 -> V_8 = V_31 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_29 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_28 ) )
return V_26 ;
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_32 )
{
int V_24 ;
T_1 V_19 ;
V_2 -> V_27 &= ~ V_33 ;
if ( V_32 ) {
V_2 -> V_27 |= V_33 ;
V_2 -> V_34 = V_33 ;
V_19 = V_35 ;
V_24 = F_1 ( V_2 , V_36 ,
V_19 ) ;
} else {
V_19 = 0 ;
V_2 -> V_34 = 0 ;
V_24 = F_1 ( V_2 , V_36 ,
V_19 ) ;
memset ( & V_2 -> V_37 , 0 , sizeof( V_2 -> V_37 ) ) ;
}
V_24 = F_1 ( V_2 , V_29 ,
V_2 -> V_27 ) ;
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
V_24 = F_4 ( V_2 , V_29 , & V_4 ) ;
if ( ! V_24 && ( V_4 & V_33 ) )
return V_38 ;
return V_24 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_32 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_13 ( V_2 , V_32 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_14 ( V_2 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_37 . V_39 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_40 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_41 &= ~ V_42 ;
if ( V_40 )
V_2 -> V_41 |= V_42 ;
V_24 = F_1 ( V_2 , V_43 ,
V_2 -> V_41 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_44 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_41 &= ~ V_45 ;
if ( V_44 )
V_2 -> V_41 |= V_45 ;
V_24 = F_1 ( V_2 , V_43 ,
V_2 -> V_41 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_43 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_45 ) )
return V_38 ;
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_46 )
{
int V_24 ;
if ( V_46 < V_2 -> V_47 . V_48 ||
V_46 > V_2 -> V_47 . V_49 )
return - V_50 ;
V_46 -= V_51 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_52 , F_22 ( V_46 ) ) ;
V_24 |= F_1 ( V_2 , V_53 ,
F_23 ( V_46 ) ) ;
if ( ! V_24 )
V_2 -> V_46 = V_46 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_52 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_53 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_25 ( F_23 , F_22 ) ;
V_24 += V_51 ;
return V_24 ;
}
static int F_26 ( struct V_1 * V_2 ,
T_2 V_46 )
{
int V_24 ;
if ( V_46 < V_2 -> V_47 . V_48 ||
V_46 > V_2 -> V_47 . V_49 )
return - V_50 ;
V_46 -= V_51 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_54 ,
F_22 ( V_46 ) ) ;
V_24 |= F_1 ( V_2 , V_55 ,
F_23 ( V_46 ) ) ;
if ( ! V_24 )
V_2 -> V_46 = V_46 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_54 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_55 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_25 ( F_23 , F_22 ) ;
V_24 += V_51 ;
return V_24 ;
}
static int F_28 ( struct V_1 * V_2 , int V_56 )
{
int V_24 ;
T_1 V_57 ;
if ( V_56 == V_58 )
V_57 = V_59 ;
else
V_57 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_60 &= ~ V_59 ;
V_2 -> V_60 |= V_57 ;
V_24 = F_1 ( V_2 , V_61 ,
V_2 -> V_60 ) ;
if ( ! V_24 )
V_2 -> V_47 . V_57 = V_56 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_61 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 ) {
if ( V_4 & V_59 )
return V_58 ;
return V_62 ;
}
return V_24 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_63 )
{
int V_24 ;
T_2 V_64 = 0 ;
if ( V_63 >= F_31 ( V_65 ) )
return - V_66 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_47 = V_65 [ V_63 ] ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_46 < V_65 [ V_63 ] . V_48 ||
V_2 -> V_46 > V_65 [ V_63 ] . V_49 )
V_64 = V_65 [ V_63 ] . V_48 ;
if ( V_64 > 0 ) {
V_24 = F_21 ( V_2 , V_64 ) ;
if ( V_24 )
goto V_67;
}
V_24 = F_28 ( V_2 ,
V_65 [ V_63 ] . V_57 ) ;
V_67:
return V_24 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = V_2 -> V_47 . V_63 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_68 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_60 &= ~ ( V_69 | V_70 ) ;
if ( V_68 )
V_2 -> V_60 |= ( V_69 |
V_70 ) ;
V_24 = F_1 ( V_2 , V_61 ,
V_2 -> V_60 ) ;
if ( ! V_24 )
V_2 -> V_71 = V_68 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_8 ) {
V_24 = F_4 ( V_2 , V_61 ,
& V_4 ) ;
if ( ! V_24 )
V_24 = V_4 & ( V_69 | V_70 ) ;
} else {
V_24 = V_2 -> V_71 ;
}
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_72 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_72 &= ( V_73 | V_74 ) ;
V_2 -> V_60 &= ~ ( V_73 |
V_74 ) ;
V_2 -> V_60 |= V_72 ;
V_24 = F_1 ( V_2 , V_61 ,
V_2 -> V_60 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_61 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & ( V_73 |
V_74 ) ;
return V_24 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_75 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_60 &= ~ ( V_76 |
V_77 ) ;
V_2 -> V_60 |= V_75 ;
V_24 = F_1 ( V_2 , V_61 ,
V_2 -> V_60 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_61 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & ( V_76 |
V_77 ) ;
return V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
T_1 V_78 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_78 &= V_79 ;
V_2 -> V_80 &= ~ V_79 ;
V_2 -> V_80 |= V_78 ;
V_24 = F_1 ( V_2 , V_81 ,
V_2 -> V_80 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_81 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & V_79 ;
return V_24 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_1 V_82 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_80 &= ~ V_83 ;
if ( V_82 )
V_2 -> V_80 |= V_83 ;
V_24 = F_1 ( V_2 , V_81 ,
V_2 -> V_80 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_81 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_83 ) )
return V_84 ;
return V_24 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_1 V_85 )
{
int V_24 , V_86 , V_87 = 0 ;
T_1 V_4 , V_19 ;
V_4 = V_85 & V_88 ;
V_19 = V_89 |
V_90 ;
F_9 ( & V_2 -> V_25 ) ;
if ( F_14 ( V_2 ) ) {
V_24 = F_13 ( V_2 , 0 ) ;
if ( V_24 )
goto V_91;
V_87 = 1 ;
}
V_24 = F_1 ( V_2 , V_92 , V_19 ) ;
if ( V_24 )
goto V_91;
F_1 ( V_2 , V_93 , V_4 ) ;
if ( V_85 != V_94 )
V_86 = V_95 ;
else
V_86 = V_96 ;
if ( ! F_44 ( & V_2 -> V_97 ,
F_45 ( V_86 ) ) )
F_2 ( & V_2 -> V_6 -> V_9 , L_4 ) ;
if ( V_4 )
if ( ! V_2 -> V_98 )
V_24 = - V_10 ;
V_91:
if ( V_87 )
V_24 |= F_13 ( V_2 , 1 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_93 ,
& V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & V_88 ;
return V_24 ;
}
static int F_47 ( struct V_1 * V_2 , T_3 V_99 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 ,
V_100 , F_22 ( V_99 ) ) ;
V_24 |= F_1 ( V_2 ,
V_101 , F_23 ( V_99 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 ,
V_100 , & F_22 ) ;
V_24 |= F_4 ( V_2 ,
V_101 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_3 V_102 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 ,
V_103 , F_22 ( V_102 ) ) ;
V_24 |= F_1 ( V_2 ,
V_104 , F_23 ( V_102 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 ,
V_103 , & F_22 ) ;
V_24 |= F_4 ( V_2 ,
V_104 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_51 ( struct V_1 * V_2 , T_3 V_99 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 ,
V_105 , F_22 ( V_99 ) ) ;
V_24 |= F_1 ( V_2 ,
V_106 , F_23 ( V_99 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 ,
V_105 , & F_22 ) ;
V_24 |= F_4 ( V_2 ,
V_106 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_53 ( struct V_1 * V_2 , T_3 V_102 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 ,
V_107 , F_22 ( V_102 ) ) ;
V_24 |= F_1 ( V_2 ,
V_108 , F_23 ( V_102 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 , F_23 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 ,
V_107 , & F_22 ) ;
V_24 |= F_4 ( V_2 ,
V_108 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_55 ( struct V_1 * V_2 , T_3 V_99 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 ,
V_92 , F_22 ( V_99 ) ) ;
V_24 |= F_1 ( V_2 ,
V_36 , F_23 ( V_99 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_109 , V_110 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_92 , & V_109 ) ;
V_24 |= F_4 ( V_2 , V_36 , & V_110 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( V_110 , V_109 ) ;
return V_24 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_109 , V_110 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_111 , & V_109 ) ;
V_24 |= F_4 ( V_2 , V_112 , & V_110 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( V_110 , V_109 ) ;
return V_24 ;
}
static int F_58 ( struct V_1 * V_2 )
{
return V_2 -> V_47 . V_48 ;
}
static int F_59 ( struct V_1 * V_2 )
{
return V_2 -> V_47 . V_49 ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_85 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_113 ,
& V_4 ) ;
V_4 &= ~ V_114 ;
if ( V_85 )
V_4 |= V_114 ;
V_24 |= F_1 ( V_2 , V_113 ,
V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_113 ,
& V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_114 ) )
return V_38 ;
return V_24 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
T_4 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_115 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 ;
return V_24 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_24 ;
T_4 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_116 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 ;
return V_24 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 V_117 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_118 , V_117 ) ;
if ( ! V_24 )
V_2 -> V_119 = V_117 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_118 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 ) {
V_2 -> V_119 = V_4 ;
return V_4 ;
}
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_120 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_121 , & V_120 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 ) {
F_67 ( & V_2 -> V_6 -> V_9 , L_5 ,
V_120 ) ;
return V_120 ;
}
return V_24 ;
}
static int F_68 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_122 , V_123 = 0 , V_124 = 0 , V_125 = 0 ;
char V_126 [ V_127 + 1 ] ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_128 ) {
V_24 = - V_66 ;
goto V_91;
}
for ( V_122 = 0 ; V_122 < V_127 ; V_122 ++ ) {
if ( V_2 -> V_37 . V_129 [ V_122 ] ) {
V_124 = V_122 ;
if ( V_2 -> V_37 . V_129 [ V_122 ] != 0x0d ) {
V_126 [ V_123 ++ ] = V_2 -> V_37 . V_129 [ V_122 ] ;
} else {
V_125 = V_122 ;
break;
}
}
}
if ( V_123 <= V_127 )
V_126 [ V_123 ] = 0 ;
for ( V_122 = 0 ; V_122 < V_127 ; V_122 ++ ) {
if ( ! V_2 -> V_37 . V_129 [ V_122 ] ) {
if ( V_125 && ( V_122 < V_125 ) ) {
V_24 = - V_130 ;
goto V_91;
}
if ( V_122 < V_124 ) {
if ( V_125 && ( V_122 >= V_125 ) )
break;
V_24 = - V_130 ;
goto V_91;
}
}
}
memcpy ( V_7 , V_126 , sizeof( V_126 ) ) ;
V_91:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_69 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_122 , V_123 = 0 ;
char V_126 [ V_131 + 1 ] ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_128 ) {
V_24 = - V_66 ;
goto V_91;
}
for ( V_122 = 0 ; V_122 < V_131 ; V_122 ++ ) {
if ( V_2 -> V_37 . V_132 [ V_122 ] ) {
V_126 [ V_123 ++ ] = V_2 -> V_37 . V_132 [ V_122 ] ;
} else {
if ( V_122 < ( V_131 - 1 ) ) {
V_24 = - V_130 ;
goto V_91;
}
}
}
if ( V_123 <= V_131 )
V_126 [ V_123 ] = 0 ;
memcpy ( V_7 , V_126 , sizeof( V_126 ) ) ;
V_91:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_122 , V_133 = 0 ;
T_3 V_134 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_119 ; V_122 += V_135 ) {
if ( V_2 -> V_37 . V_136 [ V_122 ] == V_137 ) {
V_134 = ( ( V_2 -> V_37 . V_136 [ V_122 + 1 ] << 8 ) +
V_2 -> V_37 . V_136 [ V_122 + 2 ] ) ;
if ( ! V_2 -> V_37 . V_39 ) {
V_2 -> V_37 . V_39 = V_134 ;
return;
}
if ( V_134 != V_2 -> V_37 . V_39 ) {
V_133 ++ ;
if ( V_133 > 3 ) {
V_2 -> V_37 . V_39 = V_134 ;
V_133 = 0 ;
}
} else {
V_133 = 0 ;
}
}
}
}
static int F_71 ( struct V_1 * V_2 , int V_122 )
{
return V_2 -> V_37 . V_136 [ V_122 ] & V_138 ;
}
static void F_72 ( struct V_1 * V_2 , int V_122 ,
int V_139 , int V_140 )
{
if ( V_140 ) {
if ( ! V_2 -> V_37 . V_129 [ V_139 ] )
V_2 -> V_37 . V_129 [ V_139 ] =
V_2 -> V_37 . V_136 [ V_122 + 1 ] ;
if ( ! V_2 -> V_37 . V_129 [ V_139 + 1 ] )
V_2 -> V_37 . V_129 [ V_139 + 1 ] =
V_2 -> V_37 . V_136 [ V_122 + 2 ] ;
} else {
V_2 -> V_37 . V_129 [ V_139 ] = V_2 -> V_37 . V_136 [ V_122 + 1 ] ;
V_2 -> V_37 . V_129 [ V_139 + 1 ] =
V_2 -> V_37 . V_136 [ V_122 + 2 ] ;
}
}
static int F_73 ( struct V_1 * V_2 , int V_122 )
{
int V_140 , V_141 , V_142 , V_143 , V_139 = 0 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return - V_10 ;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_146 ) {
V_141 = ( V_2 -> V_37 . V_136 [ V_122 + 1 ] &
V_145 ) ;
V_142 = V_2 -> V_37 . V_136 [ V_122 + 1 ] &
V_147 ;
V_143 = V_2 -> V_37 . V_136 [ V_122 + 2 ] &
V_148 ;
if ( V_142 != V_2 -> V_37 . V_149 ) {
memset ( V_2 -> V_37 . V_129 , 0 ,
sizeof( V_2 -> V_37 . V_129 ) ) ;
V_2 -> V_37 . V_149 = V_142 ;
}
if ( V_141 == V_150 ) {
if ( V_143 != V_2 -> V_37 . V_151 ) {
memset ( V_2 -> V_37 . V_129 , 0 ,
sizeof( V_2 -> V_37 . V_129 ) ) ;
V_2 -> V_37 . V_151 = V_143 ;
}
V_139 = V_2 -> V_37 . V_136 [ V_122 + 2 ] &
V_152 ;
if ( V_2 -> V_37 . V_149 )
V_139 <<= 1 ;
else
V_139 <<= 2 ;
return V_139 ;
}
}
return - V_10 ;
}
static int F_74 ( struct V_1 * V_2 , int V_122 ,
int V_139 )
{
int V_140 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return 0 ;
F_75 ( ( V_139 + 2 ) >= V_127 ) ;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_153 ) {
if ( V_2 -> V_37 . V_149 )
return 1 ;
F_72 ( V_2 , V_122 , V_139 , V_140 ) ;
return 1 ;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , int V_122 ,
int V_139 )
{
int V_140 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return;
F_75 ( ( V_139 + 4 ) >= V_127 ) ;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_154 )
F_72 ( V_2 , V_122 , V_139 + 2 , V_140 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_122 , V_139 = 0 , V_140 , V_155 = 0 , V_156 = 0 , V_157 = 0 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_119 ; V_122 += V_135 ) {
if ( V_155 ) {
V_155 = 0 ;
V_139 = F_73 ( V_2 , V_122 ) ;
if ( V_139 >= 0 && V_139 <= ( V_127 - 5 ) )
V_156 = 1 ;
continue;
} else if ( V_156 ) {
V_156 = 0 ;
if ( F_74 ( V_2 , V_122 , V_139 ) )
V_157 = 1 ;
continue;
} else if ( V_157 ) {
V_157 = 0 ;
F_76 ( V_2 , V_122 , V_139 ) ;
continue;
}
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 )
== V_137 ) {
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
continue;
if ( ( ( V_2 -> V_37 . V_136 [ V_122 + 1 ] << 8 ) +
V_2 -> V_37 . V_136 [ V_122 + 2 ] ) ==
V_2 -> V_37 . V_39 )
V_155 = 1 ;
}
}
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , int V_122 ,
int V_139 , int V_140 )
{
if ( V_140 ) {
if ( ! V_2 -> V_37 . V_132 [ V_139 ] )
V_2 -> V_37 . V_132 [ V_139 ] =
V_2 -> V_37 . V_136 [ V_122 + 1 ] ;
if ( ! V_2 -> V_37 . V_132 [ V_139 + 1 ] )
V_2 -> V_37 . V_132 [ V_139 + 1 ] =
V_2 -> V_37 . V_136 [ V_122 + 2 ] ;
} else {
V_2 -> V_37 . V_132 [ V_139 ] = V_2 -> V_37 . V_136 [ V_122 + 1 ] ;
V_2 -> V_37 . V_132 [ V_139 + 1 ] =
V_2 -> V_37 . V_136 [ V_122 + 2 ] ;
}
}
static int F_79 ( struct V_1 * V_2 , int V_122 ,
int V_139 )
{
int V_140 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return 0 ;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_153 )
return 1 ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 , int V_122 ,
int V_139 )
{
int V_140 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_154 )
F_78 ( V_2 , V_122 , V_139 , V_140 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_122 )
{
int V_140 , V_139 , V_158 , V_159 ;
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
return - V_10 ;
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 ) ==
V_146 ) {
V_158 = V_2 -> V_37 . V_136 [ V_122 + 1 ] &
V_145 ;
V_159 = V_2 -> V_37 . V_136 [ V_122 + 1 ] &
V_147 ;
if ( V_159 != V_2 -> V_37 . V_160 ) {
if ( V_140 == V_161 ) {
V_2 -> V_37 . V_162 ++ ;
if ( V_2 -> V_37 . V_162 > 2 ) {
V_2 -> V_37 . V_160 = V_159 ;
V_2 -> V_37 . V_162 = 0 ;
F_2 ( & V_2 -> V_6 -> V_9 ,
L_6 ) ;
} else {
return - V_10 ;
}
} else {
V_2 -> V_37 . V_162 = 0 ;
}
}
if ( V_158 == V_163 ) {
V_139 = V_2 -> V_37 . V_136 [ V_122 + 2 ] &
V_164 ;
V_139 <<= 1 ;
return V_139 ;
}
}
return - V_10 ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_122 , V_139 = 0 , V_140 , V_155 = 0 , V_156 = 0 , V_157 = 0 ;
for ( V_122 = 0 ; V_122 < V_2 -> V_119 ; V_122 += V_135 ) {
if ( V_155 ) {
V_155 = 0 ;
V_139 = F_81 ( V_2 , V_122 ) ;
if ( V_139 >= 0 && V_139 < ( V_131 - 1 ) )
V_156 = 1 ;
continue;
} else if ( V_156 ) {
V_156 = 0 ;
if ( F_79 ( V_2 , V_122 , V_139 ) )
V_157 = 1 ;
continue;
} else if ( V_157 ) {
V_157 = 0 ;
F_80 ( V_2 , V_122 , V_139 ) ;
continue;
}
if ( ( V_2 -> V_37 . V_136 [ V_122 ] & V_145 )
== V_137 ) {
V_140 = F_71 ( V_2 , V_122 ) ;
if ( V_140 == V_144 )
continue;
if ( ( ( V_2 -> V_37 . V_136 [ V_122 + 1 ] << 8 ) +
V_2 -> V_37 . V_136 [ V_122 + 2 ] ) ==
V_2 -> V_37 . V_39 )
V_155 = 1 ;
}
}
}
static void F_83 ( struct V_1 * V_2 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_6 ( V_2 , V_165 ,
V_2 -> V_37 . V_136 , V_2 -> V_119 ) ;
if ( V_24 != 2 ) {
F_2 ( & V_2 -> V_6 -> V_9 , L_7 ) ;
F_11 ( & V_2 -> V_25 ) ;
return;
}
V_2 -> V_37 . V_128 = V_2 -> V_119 ;
F_70 ( V_2 ) ;
F_77 ( V_2 ) ;
F_82 ( V_2 ) ;
F_11 ( & V_2 -> V_25 ) ;
F_84 ( & V_2 -> V_166 ) ;
}
static int F_85 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_122 , V_167 = 0 ;
char * V_126 ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_128 ) {
V_24 = - V_66 ;
goto V_91;
}
V_126 = F_86 ( V_168 * 5 , V_169 ) ;
if ( ! V_126 ) {
V_24 = - V_170 ;
goto V_91;
}
for ( V_122 = 0 ; V_122 < V_2 -> V_37 . V_128 ; V_122 ++ ) {
V_167 += sprintf ( V_126 + V_167 , L_8 ,
V_2 -> V_37 . V_136 [ V_122 ] ) ;
}
memcpy ( V_7 , V_126 , V_167 ) ;
F_87 ( V_126 ) ;
V_91:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_8 ( V_2 , V_26 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_35 ( V_2 , V_73 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_37 ( V_2 , V_76 |
V_77 ) ;
exit:
return V_24 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_35 ( V_2 , 0 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_37 ( V_2 , 0 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_8 ( V_2 , V_31 ) ;
if ( V_24 < 0 )
goto exit;
exit:
return V_24 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_8 ( V_2 , V_26 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_66 ( V_2 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_33 ( V_2 , V_171 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_30 ( V_2 , V_172 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_39 ( V_2 ,
V_173 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_18 ( V_2 , V_38 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_65 ( V_2 ) ;
if ( V_24 < V_174 )
V_24 = F_64 ( V_2 , V_174 ) ;
if ( V_24 < 0 )
goto V_91;
V_24 = F_8 ( V_2 , V_31 ) ;
F_91 ( & V_2 -> V_166 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_177 = 0 ;
V_91:
return V_24 ;
}
static void F_92 ( struct V_178 * V_179 )
{
struct V_1 * V_2 ;
T_1 V_180 , V_181 , V_19 ;
V_2 = F_93 ( V_179 , struct V_1 , V_179 ) ;
F_4 ( V_2 , V_111 , & V_180 ) ;
F_4 ( V_2 , V_112 , & V_181 ) ;
if ( V_180 & ( V_89 |
V_90 ) ) {
if ( V_180 & V_90 )
V_2 -> V_98 = V_182 ;
else
V_2 -> V_98 = V_183 ;
F_94 ( & V_2 -> V_97 ) ;
}
if ( V_181 & V_35 ) {
F_83 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_19 = V_35 ;
F_1 ( V_2 , V_36 ,
V_19 ) ;
}
V_2 -> V_175 = 1 ;
V_2 -> V_176 = 0 ;
}
}
static T_5 F_95 ( int V_184 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
F_96 ( & V_2 -> V_6 -> V_9 , L_9 ) ;
if ( V_2 -> V_8 )
F_97 ( & V_2 -> V_179 ) ;
return V_185 ;
}
static int F_98 ( struct V_1 * V_2 ,
int V_186 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_186 ; V_122 ++ )
F_99 ( & V_2 -> V_6 -> V_9 , & V_187 [ V_122 ] ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < F_31 ( V_187 ) ; V_122 ++ ) {
if ( F_101 ( & V_2 -> V_6 -> V_9 , & V_187 [ V_122 ] ) != 0 ) {
F_2 ( & V_2 -> V_6 -> V_9 ,
L_10 ) ;
V_24 = - V_130 ;
F_98 ( V_2 , V_122 ) ;
break;
}
}
return V_24 ;
}
static int F_102 ( struct V_188 * V_188 )
{
struct V_1 * V_2 = F_103 ( V_188 ) ;
V_2 -> V_177 ++ ;
V_2 -> V_176 = 0 ;
V_2 -> V_175 = 0 ;
return 0 ;
}
static int F_104 ( struct V_188 * V_188 )
{
struct V_1 * V_2 = F_103 ( V_188 ) ;
V_2 -> V_177 -- ;
return 0 ;
}
static unsigned int F_105 ( struct V_188 * V_188 ,
struct V_189 * V_190 )
{
struct V_1 * V_2 = F_103 ( V_188 ) ;
int V_191 = 0 ;
F_106 ( V_188 , & V_2 -> V_166 , V_190 ) ;
if ( V_2 -> V_175 )
V_191 = V_192 | V_193 ;
return V_191 ;
}
static T_6 F_107 ( struct V_188 * V_188 , char T_7 * V_17 ,
T_8 V_194 , T_9 * V_195 )
{
struct V_1 * V_2 = F_103 ( V_188 ) ;
int V_122 ;
int V_191 = 0 ;
V_194 = ( V_194 / 3 ) * 3 ;
if ( V_194 < 3 )
return - V_196 ;
while ( ! V_2 -> V_175 ) {
if ( V_188 -> V_197 & V_198 ) {
V_191 = - V_199 ;
goto V_67;
}
if ( F_108 ( V_2 -> V_166 ,
V_2 -> V_175 ) < 0 ) {
V_191 = - V_200 ;
goto V_67;
}
}
F_9 ( & V_2 -> V_25 ) ;
V_122 = V_2 -> V_119 - V_2 -> V_176 ;
if ( V_194 > V_122 )
V_194 = ( V_122 / 3 ) * 3 ;
V_122 = 0 ;
while ( V_122 < V_194 ) {
unsigned char V_201 [ 3 ] ;
V_201 [ V_122 ] = V_2 -> V_37 . V_136 [ V_2 -> V_176 + V_122 + 2 ] ;
V_201 [ V_122 + 1 ] = V_2 -> V_37 . V_136 [ V_2 -> V_176 + V_122 + 1 ] ;
V_201 [ V_122 + 2 ] = ( ( V_2 -> V_37 . V_136 [ V_2 -> V_176 + V_122 ]
& 0xf0 ) >> 4 ) ;
if ( ( V_2 -> V_37 . V_136 [ V_2 -> V_176 + V_122 ] &
V_138 ) == V_144 )
V_201 [ V_122 + 2 ] |= 0x80 ;
if ( F_109 ( V_17 + V_122 , V_201 , 3 ) ) {
V_191 = - V_202 ;
break;
}
V_122 += 3 ;
}
V_2 -> V_176 += V_122 ;
if ( V_2 -> V_176 >= V_2 -> V_119 )
V_2 -> V_175 = 0 ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_191 == 0 )
V_191 = V_122 ;
V_67:
return V_191 ;
}
static int F_110 ( struct V_188 * V_188 , void * V_203 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
F_113 ( V_205 -> V_206 , V_207 ,
sizeof( V_205 -> V_206 ) ) ;
F_113 ( V_205 -> V_208 , V_209 ,
sizeof( V_205 -> V_208 ) ) ;
snprintf ( V_205 -> V_210 , 32 , L_11 , V_2 -> V_6 -> V_18 ) ;
V_205 -> V_120 = V_211 ;
V_205 -> V_212 = V_213 | V_214 |
V_215 ;
return 0 ;
}
static int F_114 ( struct V_188 * V_216 , void * V_203 ,
unsigned int * V_122 )
{
* V_122 = 0 ;
return 0 ;
}
static int F_115 ( struct V_188 * V_216 , void * V_203 ,
unsigned int V_122 )
{
if ( V_122 )
return - V_66 ;
return 0 ;
}
static int F_116 ( struct V_188 * V_188 , void * V_203 ,
struct V_217 * V_218 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < F_31 ( V_219 ) ; V_122 ++ ) {
if ( V_218 -> V_220 && V_218 -> V_220 == V_219 [ V_122 ] . V_220 ) {
* V_218 = V_219 [ V_122 ] ;
return 0 ;
}
}
return - V_66 ;
}
static int F_117 ( struct V_188 * V_188 , void * V_203 ,
struct V_221 * V_222 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
int V_24 = 0 ;
if ( ! V_2 )
return - V_223 ;
switch ( V_222 -> V_220 ) {
case V_224 :
V_24 = F_34 ( V_2 ) ;
if ( V_24 >= 0 )
V_222 -> V_4 = V_24 ;
break;
}
return V_24 ;
}
static int F_118 ( struct V_188 * V_188 , void * V_203 ,
struct V_221 * V_222 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
int V_24 = 0 ;
if ( ! V_2 )
return - V_223 ;
switch ( V_222 -> V_220 ) {
case V_224 :
if ( V_222 -> V_4 ) {
if ( V_2 -> V_8 ) {
V_24 = F_33 ( V_2 , V_222 -> V_4 ) ;
V_24 |= F_89 ( V_2 ) ;
}
} else {
if ( ! V_2 -> V_8 ) {
V_24 = F_88 ( V_2 ) ;
V_24 |= F_33 ( V_2 , V_222 -> V_4 ) ;
}
}
break;
}
return V_24 ;
}
static int F_119 ( struct V_188 * V_188 , void * V_203 ,
struct V_225 * V_226 )
{
if ( V_226 -> V_139 > 1 )
return - V_66 ;
strncpy ( V_226 -> V_227 , L_12 , 32 ) ;
V_226 -> V_205 = V_228 ;
return 0 ;
}
static int F_120 ( struct V_188 * V_188 , void * V_203 ,
const struct V_225 * V_226 )
{
if ( V_226 -> V_139 != 0 )
return - V_66 ;
return 0 ;
}
static int F_121 ( struct V_188 * V_188 , void * V_203 ,
struct V_229 * V_230 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
T_4 V_231 ;
T_4 V_232 ;
if ( ! V_2 )
return - V_223 ;
if ( V_230 -> V_139 > 0 )
return - V_66 ;
strncpy ( V_230 -> V_227 , L_13 , 32 ) ;
V_230 -> type = V_233 ;
V_230 -> V_234 =
F_122 ( F_58 ( V_2 ) ) ;
V_230 -> V_235 =
F_122 ( F_59 ( V_2 ) ) ;
V_230 -> V_236 = V_237 ;
V_230 -> V_205 = V_238 | V_239 ;
V_230 -> V_240 = V_241 ;
V_230 -> V_242 = 0 ;
if ( V_2 -> V_8 ) {
V_231 = F_62 ( V_2 ) ;
if ( V_231 < V_243 ||
V_231 > V_244 ) {
V_230 -> signal = 0 ;
} else {
V_232 = F_63 ( V_2 ) ;
if ( V_232 >= V_245 ) {
V_230 -> signal = 0xFFFF ;
} else if ( V_232 > V_246 ) {
V_230 -> signal = ( V_232 +
V_247 )
* V_248 ;
} else {
V_230 -> signal = 0 ;
}
}
} else {
V_230 -> signal = 0 ;
}
return 0 ;
}
static int F_123 ( struct V_188 * V_188 , void * V_203 ,
const struct V_229 * V_230 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
if ( ! V_2 )
return - V_223 ;
if ( V_230 -> V_139 > 0 )
return - V_66 ;
return 0 ;
}
static int F_124 ( struct V_188 * V_188 , void * V_203 ,
struct V_249 * V_250 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
int V_24 = 0 ;
int V_251 ;
if ( ! V_2 -> V_8 )
return - V_223 ;
V_250 -> type = V_233 ;
V_251 = F_24 ( V_2 ) ;
if ( V_251 < 0 )
V_24 = V_251 ;
else
V_250 -> V_46 = F_122 ( V_251 ) ;
return V_24 ;
}
static int F_125 ( struct V_188 * V_188 , void * V_203 ,
const struct V_249 * V_250 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
int V_24 ;
if ( V_250 -> type != V_233 )
return - V_66 ;
if ( ! V_2 -> V_8 )
return - V_223 ;
V_24 = F_21 ( V_2 , F_126 ( V_250 -> V_46 ) ) ;
V_24 |= F_43 ( V_2 , V_252 ) ;
return V_24 ;
}
static int F_127 ( struct V_188 * V_188 , void * V_203 ,
const struct V_253 * V_254 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_188 ) ) ;
int V_24 ;
if ( ! V_2 -> V_8 )
return - V_223 ;
if ( ( V_254 -> V_230 != 0 ) || ( V_254 -> type != V_233 ) )
return - V_66 ;
V_24 = F_41 ( V_2 , V_254 -> V_255 ) ;
V_24 |= F_43 ( V_2 ,
V_94 ) ;
return V_24 ;
}
static int F_128 ( struct V_5 * V_6 ,
const struct V_256 * V_220 )
{
struct V_1 * V_2 ;
int V_24 , V_257 = 0 ;
V_2 = F_86 ( sizeof( * V_2 ) , V_169 ) ;
if ( ! V_2 ) {
V_24 = - V_170 ;
goto exit;
}
V_2 -> V_258 = F_129 () ;
if ( ! V_2 -> V_258 ) {
F_96 ( & V_6 -> V_9 , L_14 ) ;
V_24 = - V_170 ;
goto V_259;
}
V_2 -> V_6 = V_6 ;
F_130 ( V_6 , V_2 ) ;
F_131 ( & V_2 -> V_25 ) ;
F_132 ( & V_2 -> V_97 ) ;
F_133 ( & V_2 -> V_179 , F_92 ) ;
if ( V_6 -> V_184 ) {
V_24 = F_134 ( V_6 -> V_184 ,
F_95 , V_260 ,
V_6 -> V_227 , V_2 ) ;
if ( V_24 < 0 ) {
F_2 ( & V_6 -> V_9 , L_15 ) ;
goto V_261;
}
F_96 ( & V_6 -> V_9 , L_16 ) ;
} else {
F_96 ( & V_6 -> V_9 , L_17 ) ;
}
* V_2 -> V_258 = V_262 ;
F_135 ( V_2 -> V_258 , V_2 ) ;
if ( F_136 ( V_2 -> V_258 , V_263 , V_264 ) ) {
F_96 ( & V_6 -> V_9 , L_18 ) ;
V_24 = - V_10 ;
goto V_265;
}
V_24 = F_100 ( V_2 ) ;
if ( V_24 < 0 ) {
F_96 ( & V_6 -> V_9 , L_19 ) ;
goto V_266;
}
V_24 = F_90 ( V_2 ) ;
if ( V_24 < 0 ) {
F_96 ( & V_6 -> V_9 , L_20 ) ;
goto V_267;
}
return 0 ;
V_267:
F_98 ( V_2 , F_31 ( V_187 ) ) ;
V_266:
F_137 ( V_2 -> V_258 ) ;
V_2 -> V_258 = NULL ;
V_257 = 1 ;
V_265:
if ( V_6 -> V_184 )
V_265 ( V_6 -> V_184 , V_2 ) ;
V_261:
if ( ! V_257 )
F_138 ( V_2 -> V_258 ) ;
F_130 ( V_6 , NULL ) ;
V_259:
F_87 ( V_2 ) ;
exit:
return V_24 ;
}
static int T_10 F_139 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_140 ( V_6 ) ;
struct V_268 * V_269 ;
if ( ! V_6 -> V_14 )
return - V_223 ;
if ( V_2 ) {
V_269 = V_2 -> V_258 ;
F_98 ( V_2 , F_31 ( V_187 ) ) ;
if ( V_269 )
F_137 ( V_269 ) ;
if ( V_2 -> V_8 )
F_8 ( V_2 , V_31 ) ;
if ( V_6 -> V_184 > 0 )
V_265 ( V_6 -> V_184 , V_2 ) ;
F_141 ( & V_2 -> V_179 ) ;
F_87 ( V_2 ) ;
}
F_130 ( V_6 , NULL ) ;
return 0 ;
}
static int T_11 F_142 ( void )
{
F_143 ( V_270 L_21 ) ;
return F_144 ( & V_271 ) ;
}
static void T_10 F_145 ( void )
{
F_146 ( & V_271 ) ;
}
