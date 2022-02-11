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
T_1 F_22 = 0 , F_23 = 0 ;
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
T_1 F_22 = 0 , F_23 = 0 ;
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
if ( V_65 [ V_63 ] . V_48 < 87500 )
V_2 -> V_41 |= V_67 ;
else
V_2 -> V_41 &= ~ V_67 ;
V_24 = F_1 ( V_2 , V_43 ,
V_2 -> V_41 ) ;
if ( V_24 ) {
F_11 ( & V_2 -> V_25 ) ;
goto V_68;
}
F_11 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_46 < V_65 [ V_63 ] . V_48 ||
V_2 -> V_46 > V_65 [ V_63 ] . V_49 )
V_64 = V_65 [ V_63 ] . V_48 ;
if ( V_64 > 0 ) {
V_24 = F_21 ( V_2 , V_64 ) ;
if ( V_24 )
goto V_68;
}
V_24 = F_28 ( V_2 ,
V_65 [ V_63 ] . V_57 ) ;
V_68:
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
static int F_33 ( struct V_1 * V_2 , T_3 V_69 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_60 &= ~ ( V_70 | V_71 ) ;
if ( V_69 )
V_2 -> V_60 |= ( V_70 |
V_71 ) ;
V_24 = F_1 ( V_2 , V_61 ,
V_2 -> V_60 ) ;
if ( ! V_24 )
V_2 -> V_72 = V_69 ;
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
V_24 = V_4 & ( V_70 | V_71 ) ;
} else {
V_24 = V_2 -> V_72 ;
}
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_73 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_73 &= ( V_74 | V_75 ) ;
V_2 -> V_60 &= ~ ( V_74 |
V_75 ) ;
V_2 -> V_60 |= V_73 ;
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
return V_4 & ( V_74 |
V_75 ) ;
return V_24 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_76 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_60 &= ~ ( V_77 |
V_78 ) ;
V_2 -> V_60 |= V_76 ;
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
return V_4 & ( V_77 |
V_78 ) ;
return V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
T_1 V_79 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_79 &= V_80 ;
V_2 -> V_81 &= ~ V_80 ;
V_2 -> V_81 |= V_79 ;
V_24 = F_1 ( V_2 , V_82 ,
V_2 -> V_81 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_82 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & V_80 ;
return V_24 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_1 V_83 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_81 &= ~ V_84 ;
if ( V_83 )
V_2 -> V_81 |= V_84 ;
V_24 = F_1 ( V_2 , V_82 ,
V_2 -> V_81 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_82 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_84 ) )
return V_85 ;
return V_24 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_1 V_86 )
{
int V_24 , V_87 , V_88 = 0 ;
T_1 V_4 , V_19 ;
V_4 = V_86 & V_89 ;
V_19 = V_90 |
V_91 ;
F_9 ( & V_2 -> V_25 ) ;
if ( F_14 ( V_2 ) ) {
V_24 = F_13 ( V_2 , 0 ) ;
if ( V_24 )
goto V_92;
V_88 = 1 ;
}
V_24 = F_1 ( V_2 , V_93 , V_19 ) ;
if ( V_24 )
goto V_92;
F_1 ( V_2 , V_94 , V_4 ) ;
if ( V_86 != V_95 )
V_87 = V_96 ;
else
V_87 = V_97 ;
if ( ! F_44 ( & V_2 -> V_98 ,
F_45 ( V_87 ) ) )
F_2 ( & V_2 -> V_6 -> V_9 , L_4 ) ;
if ( V_4 )
if ( ! V_2 -> V_99 )
V_24 = - V_10 ;
V_92:
if ( V_88 )
V_24 |= F_13 ( V_2 , 1 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_94 ,
& V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 & V_89 ;
return V_24 ;
}
static int F_47 ( struct V_1 * V_2 , T_3 V_100 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_101 ,
F_22 ( V_100 ) ) ;
V_24 |= F_1 ( V_2 , V_102 ,
F_23 ( V_100 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 = 0 , F_23 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_101 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_102 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_3 V_103 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_104 ,
F_22 ( V_103 ) ) ;
V_24 |= F_1 ( V_2 , V_105 ,
F_23 ( V_103 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 = 0 , F_23 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_104 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_105 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_51 ( struct V_1 * V_2 , T_3 V_100 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_106 , F_22 ( V_100 ) ) ;
V_24 |= F_1 ( V_2 , V_107 , F_23 ( V_100 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 = 0 , F_23 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_106 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_107 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_53 ( struct V_1 * V_2 , T_3 V_103 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_108 ,
F_22 ( V_103 ) ) ;
V_24 |= F_1 ( V_2 , V_109 ,
F_23 ( V_103 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 F_22 = 0 , F_23 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_108 , & F_22 ) ;
V_24 |= F_4 ( V_2 , V_109 , & F_23 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( F_23 , F_22 ) ;
return V_24 ;
}
static int F_55 ( struct V_1 * V_2 , T_3 V_100 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_93 , F_22 ( V_100 ) ) ;
V_24 |= F_1 ( V_2 , V_36 , F_23 ( V_100 ) ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_110 = 0 , V_111 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_93 , & V_110 ) ;
V_24 |= F_4 ( V_2 , V_36 , & V_111 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( V_111 , V_110 ) ;
return V_24 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_110 = 0 , V_111 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_112 , & V_110 ) ;
V_24 |= F_4 ( V_2 , V_113 , & V_111 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return F_25 ( V_111 , V_110 ) ;
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
static int F_60 ( struct V_1 * V_2 , T_1 V_86 )
{
int V_24 ;
T_1 V_4 = 0 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_114 ,
& V_4 ) ;
V_4 &= ~ V_115 ;
if ( V_86 )
V_4 |= V_115 ;
V_24 |= F_1 ( V_2 , V_114 ,
V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_114 ,
& V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 && ( V_4 & V_115 ) )
return V_38 ;
return V_24 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
T_4 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_116 , & V_4 ) ;
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
V_24 = F_4 ( V_2 , V_117 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 )
return V_4 ;
return V_24 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 V_118 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_119 , V_118 ) ;
if ( ! V_24 )
V_2 -> V_120 = V_118 ;
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_4 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_119 , & V_4 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 ) {
V_2 -> V_120 = V_4 ;
return V_4 ;
}
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_121 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_4 ( V_2 , V_122 , & V_121 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ! V_24 ) {
F_67 ( & V_2 -> V_6 -> V_9 , L_5 ,
V_121 ) ;
return V_121 ;
}
return V_24 ;
}
static int F_68 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_123 , V_124 = 0 , V_125 = 0 , V_126 = 0 ;
char V_127 [ V_128 + 1 ] ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_129 ) {
V_24 = - V_66 ;
goto V_92;
}
for ( V_123 = 0 ; V_123 < V_128 ; V_123 ++ ) {
if ( V_2 -> V_37 . V_130 [ V_123 ] ) {
V_125 = V_123 ;
if ( V_2 -> V_37 . V_130 [ V_123 ] != 0x0d ) {
V_127 [ V_124 ++ ] = V_2 -> V_37 . V_130 [ V_123 ] ;
} else {
V_126 = V_123 ;
break;
}
}
}
if ( V_124 <= V_128 )
V_127 [ V_124 ] = 0 ;
for ( V_123 = 0 ; V_123 < V_128 ; V_123 ++ ) {
if ( ! V_2 -> V_37 . V_130 [ V_123 ] ) {
if ( V_126 && ( V_123 < V_126 ) ) {
V_24 = - V_131 ;
goto V_92;
}
if ( V_123 < V_125 ) {
if ( V_126 && ( V_123 >= V_126 ) )
break;
V_24 = - V_131 ;
goto V_92;
}
}
}
memcpy ( V_7 , V_127 , sizeof( V_127 ) ) ;
V_92:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_69 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_123 , V_124 = 0 ;
char V_127 [ V_132 + 1 ] ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_129 ) {
V_24 = - V_66 ;
goto V_92;
}
for ( V_123 = 0 ; V_123 < V_132 ; V_123 ++ ) {
if ( V_2 -> V_37 . V_133 [ V_123 ] ) {
V_127 [ V_124 ++ ] = V_2 -> V_37 . V_133 [ V_123 ] ;
} else {
if ( V_123 < ( V_132 - 1 ) ) {
V_24 = - V_131 ;
goto V_92;
}
}
}
if ( V_124 <= V_132 )
V_127 [ V_124 ] = 0 ;
memcpy ( V_7 , V_127 , sizeof( V_127 ) ) ;
V_92:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_123 , V_134 = 0 ;
T_3 V_135 ;
for ( V_123 = 0 ; V_123 < V_2 -> V_120 ; V_123 += V_136 ) {
if ( V_2 -> V_37 . V_137 [ V_123 ] == V_138 ) {
V_135 = ( V_2 -> V_37 . V_137 [ V_123 + 1 ] << 8 ) +
V_2 -> V_37 . V_137 [ V_123 + 2 ] ;
if ( ! V_2 -> V_37 . V_39 ) {
V_2 -> V_37 . V_39 = V_135 ;
return;
}
if ( V_135 != V_2 -> V_37 . V_39 ) {
V_134 ++ ;
if ( V_134 > 3 ) {
V_2 -> V_37 . V_39 = V_135 ;
V_134 = 0 ;
}
} else {
V_134 = 0 ;
}
}
}
}
static int F_71 ( struct V_1 * V_2 , int V_123 )
{
return V_2 -> V_37 . V_137 [ V_123 ] & V_139 ;
}
static void F_72 ( struct V_1 * V_2 , int V_123 ,
int V_140 , int V_141 )
{
if ( V_141 ) {
if ( ! V_2 -> V_37 . V_130 [ V_140 ] )
V_2 -> V_37 . V_130 [ V_140 ] =
V_2 -> V_37 . V_137 [ V_123 + 1 ] ;
if ( ! V_2 -> V_37 . V_130 [ V_140 + 1 ] )
V_2 -> V_37 . V_130 [ V_140 + 1 ] =
V_2 -> V_37 . V_137 [ V_123 + 2 ] ;
} else {
V_2 -> V_37 . V_130 [ V_140 ] =
V_2 -> V_37 . V_137 [ V_123 + 1 ] ;
V_2 -> V_37 . V_130 [ V_140 + 1 ] =
V_2 -> V_37 . V_137 [ V_123 + 2 ] ;
}
}
static int F_73 ( struct V_1 * V_2 , int V_123 )
{
int V_141 , V_142 , V_143 , V_144 , V_140 = 0 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return - V_10 ;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_147 ) {
V_142 = V_2 -> V_37 . V_137 [ V_123 + 1 ] &
V_146 ;
V_143 = V_2 -> V_37 . V_137 [ V_123 + 1 ] &
V_148 ;
V_144 = V_2 -> V_37 . V_137 [ V_123 + 2 ] &
V_149 ;
if ( V_143 != V_2 -> V_37 . V_150 ) {
memset ( V_2 -> V_37 . V_130 , 0 ,
sizeof( V_2 -> V_37 . V_130 ) ) ;
V_2 -> V_37 . V_150 = V_143 ;
}
if ( V_142 == V_151 ) {
if ( V_144 != V_2 -> V_37 . V_152 ) {
memset ( V_2 -> V_37 . V_130 , 0 ,
sizeof( V_2 -> V_37 . V_130 ) ) ;
V_2 -> V_37 . V_152 = V_144 ;
}
V_140 = V_2 -> V_37 . V_137 [ V_123 + 2 ] &
V_153 ;
if ( V_2 -> V_37 . V_150 )
V_140 <<= 1 ;
else
V_140 <<= 2 ;
return V_140 ;
}
}
return - V_10 ;
}
static int F_74 ( struct V_1 * V_2 , int V_123 ,
int V_140 )
{
int V_141 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return 0 ;
F_75 ( ( V_140 + 2 ) >= V_128 ) ;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_154 ) {
if ( V_2 -> V_37 . V_150 )
return 1 ;
F_72 ( V_2 , V_123 , V_140 , V_141 ) ;
return 1 ;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , int V_123 ,
int V_140 )
{
int V_141 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return;
F_75 ( ( V_140 + 4 ) >= V_128 ) ;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_155 )
F_72 ( V_2 , V_123 , V_140 + 2 , V_141 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
int V_123 , V_140 = 0 , V_141 , V_156 = 0 , V_157 = 0 , V_158 = 0 ;
for ( V_123 = 0 ; V_123 < V_2 -> V_120 ; V_123 += V_136 ) {
if ( V_156 ) {
V_156 = 0 ;
V_140 = F_73 ( V_2 , V_123 ) ;
if ( V_140 >= 0 && V_140 <= ( V_128 - 5 ) )
V_157 = 1 ;
continue;
} else if ( V_157 ) {
V_157 = 0 ;
if ( F_74 ( V_2 , V_123 , V_140 ) )
V_158 = 1 ;
continue;
} else if ( V_158 ) {
V_158 = 0 ;
F_76 ( V_2 , V_123 , V_140 ) ;
continue;
}
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_138 ) {
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
continue;
if ( ( ( V_2 -> V_37 . V_137 [ V_123 + 1 ] << 8 ) +
V_2 -> V_37 . V_137 [ V_123 + 2 ] ) ==
V_2 -> V_37 . V_39 )
V_156 = 1 ;
}
}
}
static void F_78 ( struct V_1 * V_2 , int V_123 ,
int V_140 , int V_141 )
{
if ( V_141 ) {
if ( ! V_2 -> V_37 . V_133 [ V_140 ] )
V_2 -> V_37 . V_133 [ V_140 ] =
V_2 -> V_37 . V_137 [ V_123 + 1 ] ;
if ( ! V_2 -> V_37 . V_133 [ V_140 + 1 ] )
V_2 -> V_37 . V_133 [ V_140 + 1 ] =
V_2 -> V_37 . V_137 [ V_123 + 2 ] ;
} else {
V_2 -> V_37 . V_133 [ V_140 ] =
V_2 -> V_37 . V_137 [ V_123 + 1 ] ;
V_2 -> V_37 . V_133 [ V_140 + 1 ] =
V_2 -> V_37 . V_137 [ V_123 + 2 ] ;
}
}
static int F_79 ( struct V_1 * V_2 , int V_123 ,
int V_140 )
{
int V_141 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return 0 ;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_154 )
return 1 ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 , int V_123 ,
int V_140 )
{
int V_141 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_155 )
F_78 ( V_2 , V_123 , V_140 , V_141 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_123 )
{
int V_141 , V_140 , V_159 , V_160 ;
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
return - V_10 ;
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_147 ) {
V_159 = V_2 -> V_37 . V_137 [ V_123 + 1 ] &
V_146 ;
V_160 = V_2 -> V_37 . V_137 [ V_123 + 1 ] &
V_148 ;
if ( V_160 != V_2 -> V_37 . V_161 ) {
if ( V_141 == V_162 ) {
V_2 -> V_37 . V_163 ++ ;
if ( V_2 -> V_37 . V_163 > 2 ) {
V_2 -> V_37 . V_161 = V_160 ;
V_2 -> V_37 . V_163 = 0 ;
F_2 ( & V_2 -> V_6 -> V_9 ,
L_6 ) ;
} else {
return - V_10 ;
}
} else {
V_2 -> V_37 . V_163 = 0 ;
}
}
if ( V_159 == V_164 ) {
V_140 = V_2 -> V_37 . V_137 [ V_123 + 2 ] &
V_165 ;
V_140 <<= 1 ;
return V_140 ;
}
}
return - V_10 ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_123 , V_140 = 0 , V_141 , V_156 = 0 , V_157 = 0 , V_158 = 0 ;
for ( V_123 = 0 ; V_123 < V_2 -> V_120 ; V_123 += V_136 ) {
if ( V_156 ) {
V_156 = 0 ;
V_140 = F_81 ( V_2 , V_123 ) ;
if ( V_140 >= 0 && V_140 < ( V_132 - 1 ) )
V_157 = 1 ;
continue;
} else if ( V_157 ) {
V_157 = 0 ;
if ( F_79 ( V_2 , V_123 , V_140 ) )
V_158 = 1 ;
continue;
} else if ( V_158 ) {
V_158 = 0 ;
F_80 ( V_2 , V_123 , V_140 ) ;
continue;
}
if ( ( V_2 -> V_37 . V_137 [ V_123 ] & V_146 ) ==
V_138 ) {
V_141 = F_71 ( V_2 , V_123 ) ;
if ( V_141 == V_145 )
continue;
if ( ( ( V_2 -> V_37 . V_137 [ V_123 + 1 ] << 8 ) +
V_2 -> V_37 . V_137 [ V_123 + 2 ] ) ==
V_2 -> V_37 . V_39 )
V_156 = 1 ;
}
}
}
static void F_83 ( struct V_1 * V_2 )
{
int V_24 ;
F_9 ( & V_2 -> V_25 ) ;
V_24 = F_6 ( V_2 , V_166 ,
V_2 -> V_37 . V_137 , V_2 -> V_120 ) ;
if ( V_24 != 2 ) {
F_2 ( & V_2 -> V_6 -> V_9 , L_7 ) ;
F_11 ( & V_2 -> V_25 ) ;
return;
}
V_2 -> V_37 . V_129 = V_2 -> V_120 ;
F_70 ( V_2 ) ;
F_77 ( V_2 ) ;
F_82 ( V_2 ) ;
F_11 ( & V_2 -> V_25 ) ;
F_84 ( & V_2 -> V_167 ) ;
}
static int F_85 ( struct V_1 * V_2 , char * V_7 )
{
int V_24 = 0 , V_123 , V_168 = 0 ;
char * V_127 ;
F_9 ( & V_2 -> V_25 ) ;
if ( ! V_2 -> V_37 . V_129 ) {
V_24 = - V_66 ;
goto V_92;
}
V_127 = F_86 ( V_169 , 5 , V_170 ) ;
if ( ! V_127 ) {
V_24 = - V_171 ;
goto V_92;
}
for ( V_123 = 0 ; V_123 < V_2 -> V_37 . V_129 ; V_123 ++ ) {
V_168 += sprintf ( V_127 + V_168 , L_8 ,
V_2 -> V_37 . V_137 [ V_123 ] ) ;
}
memcpy ( V_7 , V_127 , V_168 ) ;
F_87 ( V_127 ) ;
V_92:
F_11 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_8 ( V_2 , V_26 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_35 ( V_2 , V_74 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_37 ( V_2 , V_77 |
V_78 ) ;
exit:
return V_24 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_35 ( V_2 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_37 ( V_2 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_8 ( V_2 , V_31 ) ;
return V_24 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_8 ( V_2 , V_26 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_66 ( V_2 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_33 ( V_2 , V_172 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_30 ( V_2 , V_173 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_39 ( V_2 ,
V_174 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_18 ( V_2 , V_38 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_65 ( V_2 ) ;
if ( V_24 < V_175 )
V_24 = F_64 ( V_2 , V_175 ) ;
if ( V_24 < 0 )
goto V_92;
V_24 = F_8 ( V_2 , V_31 ) ;
F_91 ( & V_2 -> V_167 ) ;
V_2 -> V_176 = 0 ;
V_2 -> V_177 = 0 ;
V_2 -> V_178 = 0 ;
V_92:
return V_24 ;
}
static void F_92 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
T_1 V_181 = 0 , V_182 = 0 , V_19 ;
V_2 = F_93 ( V_180 , struct V_1 , V_180 ) ;
F_4 ( V_2 , V_112 , & V_181 ) ;
F_4 ( V_2 , V_113 , & V_182 ) ;
if ( V_181 & ( V_90 |
V_91 ) ) {
if ( V_181 & V_91 )
V_2 -> V_99 = V_183 ;
else
V_2 -> V_99 = V_184 ;
F_94 ( & V_2 -> V_98 ) ;
}
if ( V_182 & V_35 ) {
F_83 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_19 = V_35 ;
F_1 ( V_2 , V_36 ,
V_19 ) ;
}
V_2 -> V_176 = 1 ;
V_2 -> V_177 = 0 ;
}
}
static T_5 F_95 ( int V_185 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
F_96 ( & V_2 -> V_6 -> V_9 , L_9 ) ;
if ( V_2 -> V_8 )
F_97 ( & V_2 -> V_180 ) ;
return V_186 ;
}
static int F_98 ( struct V_1 * V_2 ,
int V_187 )
{
int V_123 ;
for ( V_123 = 0 ; V_123 < V_187 ; V_123 ++ )
F_99 ( & V_2 -> V_6 -> V_9 , & V_188 [ V_123 ] ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < F_31 ( V_188 ) ; V_123 ++ ) {
if ( F_101 ( & V_2 -> V_6 -> V_9 , & V_188 [ V_123 ] ) != 0 ) {
F_2 ( & V_2 -> V_6 -> V_9 ,
L_10 ) ;
V_24 = - V_131 ;
F_98 ( V_2 , V_123 ) ;
break;
}
}
return V_24 ;
}
static int F_102 ( struct V_189 * V_189 )
{
struct V_1 * V_2 = F_103 ( V_189 ) ;
V_2 -> V_178 ++ ;
V_2 -> V_177 = 0 ;
V_2 -> V_176 = 0 ;
return 0 ;
}
static int F_104 ( struct V_189 * V_189 )
{
struct V_1 * V_2 = F_103 ( V_189 ) ;
V_2 -> V_178 -- ;
return 0 ;
}
static unsigned int F_105 ( struct V_189 * V_189 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 = F_103 ( V_189 ) ;
int V_192 = 0 ;
F_106 ( V_189 , & V_2 -> V_167 , V_191 ) ;
if ( V_2 -> V_176 )
V_192 = V_193 | V_194 ;
return V_192 ;
}
static T_6 F_107 ( struct V_189 * V_189 , char T_7 * V_17 ,
T_8 V_195 , T_9 * V_196 )
{
struct V_1 * V_2 = F_103 ( V_189 ) ;
int V_123 ;
int V_192 = 0 ;
V_195 = ( V_195 / 3 ) * 3 ;
if ( V_195 < 3 )
return - V_197 ;
while ( ! V_2 -> V_176 ) {
if ( V_189 -> V_198 & V_199 ) {
V_192 = - V_200 ;
goto V_68;
}
if ( F_108 ( V_2 -> V_167 ,
V_2 -> V_176 ) < 0 ) {
V_192 = - V_201 ;
goto V_68;
}
}
F_9 ( & V_2 -> V_25 ) ;
V_123 = V_2 -> V_120 - V_2 -> V_177 ;
if ( V_195 > V_123 )
V_195 = ( V_123 / 3 ) * 3 ;
V_123 = 0 ;
while ( V_123 < V_195 ) {
unsigned char V_202 [ 3 ] ;
V_202 [ V_123 ] = V_2 -> V_37 . V_137 [ V_2 -> V_177 + V_123 + 2 ] ;
V_202 [ V_123 + 1 ] =
V_2 -> V_37 . V_137 [ V_2 -> V_177 + V_123 + 1 ] ;
V_202 [ V_123 + 2 ] =
( V_2 -> V_37 . V_137 [ V_2 -> V_177 + V_123 ] &
0xf0 ) >> 4 ;
if ( ( V_2 -> V_37 . V_137 [ V_2 -> V_177 + V_123 ] &
V_139 ) == V_145 )
V_202 [ V_123 + 2 ] |= 0x80 ;
if ( F_109 ( V_17 + V_123 , V_202 , 3 ) ) {
V_192 = - V_203 ;
break;
}
V_123 += 3 ;
}
V_2 -> V_177 += V_123 ;
if ( V_2 -> V_177 >= V_2 -> V_120 )
V_2 -> V_176 = 0 ;
F_11 ( & V_2 -> V_25 ) ;
if ( V_192 == 0 )
V_192 = V_123 ;
V_68:
return V_192 ;
}
static int F_110 ( struct V_189 * V_189 , void * V_204 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
F_113 ( V_206 -> V_207 , V_208 ,
sizeof( V_206 -> V_207 ) ) ;
F_113 ( V_206 -> V_209 , V_210 ,
sizeof( V_206 -> V_209 ) ) ;
snprintf ( V_206 -> V_211 , 32 , L_11 , V_2 -> V_6 -> V_18 ) ;
V_206 -> V_212 = V_213 | V_214 |
V_215 ;
V_206 -> V_216 = V_206 -> V_212 |
V_217 ;
return 0 ;
}
static int F_114 ( struct V_189 * V_218 , void * V_204 ,
unsigned int * V_123 )
{
* V_123 = 0 ;
return 0 ;
}
static int F_115 ( struct V_189 * V_218 , void * V_204 ,
unsigned int V_123 )
{
if ( V_123 )
return - V_66 ;
return 0 ;
}
static int F_116 ( struct V_189 * V_189 , void * V_204 ,
struct V_219 * V_220 )
{
int V_123 ;
for ( V_123 = 0 ; V_123 < F_31 ( V_221 ) ; V_123 ++ ) {
if ( V_220 -> V_222 && V_220 -> V_222 == V_221 [ V_123 ] . V_222 ) {
* V_220 = V_221 [ V_123 ] ;
return 0 ;
}
}
return - V_66 ;
}
static int F_117 ( struct V_189 * V_189 , void * V_204 ,
struct V_223 * V_224 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
int V_24 = 0 ;
if ( ! V_2 )
return - V_225 ;
switch ( V_224 -> V_222 ) {
case V_226 :
V_24 = F_34 ( V_2 ) ;
if ( V_24 >= 0 )
V_224 -> V_4 = V_24 ;
break;
}
return V_24 ;
}
static int F_118 ( struct V_189 * V_189 , void * V_204 ,
struct V_223 * V_224 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
int V_24 = 0 ;
if ( ! V_2 )
return - V_225 ;
switch ( V_224 -> V_222 ) {
case V_226 :
if ( V_224 -> V_4 ) {
if ( V_2 -> V_8 ) {
V_24 = F_33 ( V_2 , V_224 -> V_4 ) ;
V_24 |= F_89 ( V_2 ) ;
}
} else {
if ( ! V_2 -> V_8 ) {
V_24 = F_88 ( V_2 ) ;
V_24 |= F_33 ( V_2 , V_224 -> V_4 ) ;
}
}
break;
}
return V_24 ;
}
static int F_119 ( struct V_189 * V_189 , void * V_204 ,
struct V_227 * V_228 )
{
if ( V_228 -> V_140 > 1 )
return - V_66 ;
strncpy ( V_228 -> V_229 , L_12 , 32 ) ;
V_228 -> V_206 = V_230 ;
return 0 ;
}
static int F_120 ( struct V_189 * V_189 , void * V_204 ,
const struct V_227 * V_228 )
{
if ( V_228 -> V_140 != 0 )
return - V_66 ;
return 0 ;
}
static int F_121 ( struct V_189 * V_189 , void * V_204 ,
struct V_231 * V_232 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
T_4 V_233 ;
T_4 V_234 ;
if ( ! V_2 )
return - V_225 ;
if ( V_232 -> V_140 > 0 )
return - V_66 ;
strncpy ( V_232 -> V_229 , L_13 , 32 ) ;
V_232 -> type = V_235 ;
V_232 -> V_236 =
F_122 ( F_58 ( V_2 ) ) ;
V_232 -> V_237 =
F_122 ( F_59 ( V_2 ) ) ;
V_232 -> V_238 = V_239 ;
V_232 -> V_206 = V_240 | V_241 ;
V_232 -> V_242 = V_243 ;
V_232 -> V_244 = 0 ;
if ( V_2 -> V_8 ) {
V_233 = F_62 ( V_2 ) ;
if ( V_233 < V_245 ||
V_233 > V_246 ) {
V_232 -> signal = 0 ;
} else {
V_234 = F_63 ( V_2 ) ;
if ( V_234 >= V_247 ) {
V_232 -> signal = 0xFFFF ;
} else if ( V_234 > V_248 ) {
V_232 -> signal = ( V_234 +
V_249 )
* V_250 ;
} else {
V_232 -> signal = 0 ;
}
}
} else {
V_232 -> signal = 0 ;
}
return 0 ;
}
static int F_123 ( struct V_189 * V_189 , void * V_204 ,
const struct V_231 * V_232 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
if ( ! V_2 )
return - V_225 ;
if ( V_232 -> V_140 > 0 )
return - V_66 ;
return 0 ;
}
static int F_124 ( struct V_189 * V_189 , void * V_204 ,
struct V_251 * V_252 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
int V_24 = 0 ;
int V_253 ;
if ( ! V_2 -> V_8 )
return - V_225 ;
V_252 -> type = V_235 ;
V_253 = F_24 ( V_2 ) ;
if ( V_253 < 0 )
V_24 = V_253 ;
else
V_252 -> V_46 = F_122 ( V_253 ) ;
return V_24 ;
}
static int F_125 ( struct V_189 * V_189 , void * V_204 ,
const struct V_251 * V_252 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
int V_24 ;
if ( V_252 -> type != V_235 )
return - V_66 ;
if ( ! V_2 -> V_8 )
return - V_225 ;
V_24 = F_21 ( V_2 , F_126 ( V_252 -> V_46 ) ) ;
V_24 |= F_43 ( V_2 , V_254 ) ;
return V_24 ;
}
static int F_127 ( struct V_189 * V_189 , void * V_204 ,
const struct V_255 * V_256 )
{
struct V_1 * V_2 = F_111 ( F_112 ( V_189 ) ) ;
int V_24 ;
if ( ! V_2 -> V_8 )
return - V_225 ;
if ( ( V_256 -> V_232 != 0 ) || ( V_256 -> type != V_235 ) )
return - V_66 ;
V_24 = F_41 ( V_2 , V_256 -> V_257 ) ;
V_24 |= F_43 ( V_2 ,
V_95 ) ;
return V_24 ;
}
static int F_128 ( struct V_5 * V_6 ,
const struct V_258 * V_222 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_129 ( sizeof( * V_2 ) , V_170 ) ;
if ( ! V_2 ) {
V_24 = - V_171 ;
goto exit;
}
V_2 -> V_6 = V_6 ;
F_130 ( V_6 , V_2 ) ;
F_131 ( & V_2 -> V_25 ) ;
F_132 ( & V_2 -> V_98 ) ;
F_133 ( & V_2 -> V_180 , F_92 ) ;
if ( V_6 -> V_185 ) {
V_24 = F_134 ( V_6 -> V_185 ,
F_95 , V_259 ,
V_6 -> V_229 , V_2 ) ;
if ( V_24 < 0 ) {
F_2 ( & V_6 -> V_9 , L_14 ) ;
goto V_260;
}
F_96 ( & V_6 -> V_9 , L_15 ) ;
} else {
F_96 ( & V_6 -> V_9 , L_16 ) ;
}
V_2 -> V_261 = V_262 ;
F_135 ( & V_2 -> V_261 , V_2 ) ;
if ( F_136 ( & V_2 -> V_261 , V_263 , V_264 ) ) {
F_96 ( & V_6 -> V_9 , L_17 ) ;
V_24 = - V_10 ;
goto V_265;
}
V_24 = F_100 ( V_2 ) ;
if ( V_24 < 0 ) {
F_96 ( & V_6 -> V_9 , L_18 ) ;
goto V_266;
}
V_24 = F_90 ( V_2 ) ;
if ( V_24 < 0 ) {
F_96 ( & V_6 -> V_9 , L_19 ) ;
goto V_267;
}
return 0 ;
V_267:
F_98 ( V_2 , F_31 ( V_188 ) ) ;
V_266:
F_137 ( & V_2 -> V_261 ) ;
V_265:
if ( V_6 -> V_185 )
V_265 ( V_6 -> V_185 , V_2 ) ;
V_260:
F_130 ( V_6 , NULL ) ;
F_87 ( V_2 ) ;
exit:
return V_24 ;
}
static int T_10 F_138 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_139 ( V_6 ) ;
if ( ! V_6 -> V_14 )
return - V_225 ;
if ( V_2 ) {
F_98 ( V_2 , F_31 ( V_188 ) ) ;
F_137 ( & V_2 -> V_261 ) ;
if ( V_2 -> V_8 )
F_8 ( V_2 , V_31 ) ;
if ( V_6 -> V_185 > 0 )
V_265 ( V_6 -> V_185 , V_2 ) ;
F_140 ( & V_2 -> V_180 ) ;
F_87 ( V_2 ) ;
}
return 0 ;
}
