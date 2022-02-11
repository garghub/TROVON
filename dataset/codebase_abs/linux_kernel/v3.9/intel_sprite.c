static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
T_2 V_22 , V_23 = 0 ;
unsigned long V_24 , V_25 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
bool V_28 = V_18 -> V_29 ;
V_22 = F_4 ( F_5 ( V_21 ) ) ;
V_22 &= ~ V_30 ;
V_22 &= ~ V_31 ;
V_22 &= ~ V_32 ;
V_22 &= ~ V_33 ;
switch ( V_4 -> V_27 ) {
case V_34 :
V_22 |= V_35 | V_31 ;
break;
case V_36 :
V_22 |= V_35 ;
break;
case V_37 :
V_22 |= V_38 | V_39 ;
break;
case V_40 :
V_22 |= V_38 | V_41 ;
break;
case V_42 :
V_22 |= V_38 | V_43 ;
break;
case V_44 :
V_22 |= V_38 | V_45 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_46 != V_47 )
V_22 |= V_33 ;
V_22 |= V_48 ;
V_22 |= V_49 ;
if ( F_7 ( V_16 ) )
V_22 |= V_50 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_8 ( V_16 , V_21 , V_9 , V_26 ) ;
if ( V_9 != V_13 || V_10 != V_14 ) {
V_18 -> V_29 |= 1 << V_21 ;
if ( ! V_28 ) {
F_9 ( V_16 ) ;
F_10 ( V_16 , V_21 ) ;
}
V_23 = V_51 | ( V_13 << 16 ) | V_14 ;
} else
V_18 -> V_29 &= ~ ( 1 << V_21 ) ;
F_11 ( F_12 ( V_21 ) , V_4 -> V_52 [ 0 ] ) ;
F_11 ( F_13 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_52 [ 0 ] + V_11 * V_26 ;
V_24 =
F_14 ( & V_11 , & V_12 , V_6 -> V_46 ,
V_26 , V_4 -> V_52 [ 0 ] ) ;
V_25 -= V_24 ;
if ( F_7 ( V_16 ) )
F_11 ( F_15 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else if ( V_6 -> V_46 != V_47 )
F_11 ( F_16 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_11 ( F_17 ( V_21 ) , V_25 ) ;
F_11 ( F_18 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
if ( V_20 -> V_53 )
F_11 ( F_19 ( V_21 ) , V_23 ) ;
F_11 ( F_5 ( V_21 ) , V_22 ) ;
F_20 ( F_21 ( V_21 ) , V_6 -> V_54 + V_24 ) ;
F_22 ( F_21 ( V_21 ) ) ;
if ( V_28 && ! V_18 -> V_29 )
F_9 ( V_16 ) ;
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
bool V_28 = V_18 -> V_29 ;
F_11 ( F_5 ( V_21 ) , F_4 ( F_5 ( V_21 ) ) & ~ V_49 ) ;
if ( V_20 -> V_53 )
F_11 ( F_19 ( V_21 ) , 0 ) ;
F_20 ( F_21 ( V_21 ) , 0 ) ;
F_22 ( F_21 ( V_21 ) ) ;
V_18 -> V_29 &= ~ ( 1 << V_21 ) ;
if ( V_28 && ! V_18 -> V_29 )
F_9 ( V_16 ) ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
int V_57 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_11 ( F_25 ( V_20 -> V_21 ) , V_56 -> V_58 ) ;
F_11 ( F_26 ( V_20 -> V_21 ) , V_56 -> V_59 ) ;
F_11 ( F_27 ( V_20 -> V_21 ) , V_56 -> V_60 ) ;
V_22 = F_4 ( F_5 ( V_20 -> V_21 ) ) ;
V_22 &= ~ ( V_61 | V_62 ) ;
if ( V_56 -> V_63 & V_64 )
V_22 |= V_62 ;
else if ( V_56 -> V_63 & V_65 )
V_22 |= V_61 ;
F_11 ( F_5 ( V_20 -> V_21 ) , V_22 ) ;
F_22 ( F_27 ( V_20 -> V_21 ) ) ;
return V_57 ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
V_20 = F_2 ( V_2 ) ;
V_56 -> V_58 = F_4 ( F_25 ( V_20 -> V_21 ) ) ;
V_56 -> V_59 = F_4 ( F_26 ( V_20 -> V_21 ) ) ;
V_56 -> V_60 = F_4 ( F_27 ( V_20 -> V_21 ) ) ;
V_56 -> V_63 = 0 ;
V_22 = F_4 ( F_5 ( V_20 -> V_21 ) ) ;
if ( V_22 & V_62 )
V_56 -> V_63 = V_64 ;
else if ( V_22 & V_61 )
V_56 -> V_63 = V_65 ;
else
V_56 -> V_63 = V_66 ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
unsigned long V_67 , V_25 ;
T_2 V_68 , V_69 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
V_68 = F_4 ( F_30 ( V_21 ) ) ;
V_68 &= ~ V_70 ;
V_68 &= ~ V_71 ;
V_68 &= ~ V_72 ;
V_68 &= ~ V_73 ;
switch ( V_4 -> V_27 ) {
case V_34 :
V_68 |= V_74 | V_71 ;
break;
case V_36 :
V_68 |= V_74 ;
break;
case V_37 :
V_68 |= V_75 | V_76 ;
break;
case V_40 :
V_68 |= V_75 | V_77 ;
break;
case V_42 :
V_68 |= V_75 | V_78 ;
break;
case V_44 :
V_68 |= V_75 | V_79 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_46 != V_47 )
V_68 |= V_73 ;
if ( F_31 ( V_16 ) )
V_68 |= V_80 ;
V_68 |= V_81 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_8 ( V_16 , V_21 , V_9 , V_26 ) ;
V_69 = 0 ;
if ( F_32 ( V_16 ) || V_9 != V_13 || V_10 != V_14 )
V_69 = V_82 | ( V_13 << 16 ) | V_14 ;
F_11 ( F_33 ( V_21 ) , V_4 -> V_52 [ 0 ] ) ;
F_11 ( F_34 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_52 [ 0 ] + V_11 * V_26 ;
V_67 =
F_14 ( & V_11 , & V_12 , V_6 -> V_46 ,
V_26 , V_4 -> V_52 [ 0 ] ) ;
V_25 -= V_67 ;
if ( V_6 -> V_46 != V_47 )
F_11 ( F_35 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_11 ( F_36 ( V_21 ) , V_25 ) ;
F_11 ( F_37 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_11 ( F_38 ( V_21 ) , V_69 ) ;
F_11 ( F_30 ( V_21 ) , V_68 ) ;
F_20 ( F_39 ( V_21 ) , V_6 -> V_54 + V_67 ) ;
F_22 ( F_39 ( V_21 ) ) ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_11 ( F_30 ( V_21 ) , F_4 ( F_30 ( V_21 ) ) & ~ V_81 ) ;
F_11 ( F_38 ( V_21 ) , 0 ) ;
F_20 ( F_39 ( V_21 ) , 0 ) ;
F_22 ( F_39 ( V_21 ) ) ;
}
static void
F_41 ( struct V_83 * V_84 )
{
struct V_15 * V_16 = V_84 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_85 * V_85 = F_42 ( V_84 ) ;
int V_86 = F_43 ( V_85 -> V_2 ) ;
if ( ! V_85 -> V_87 )
return;
V_85 -> V_87 = false ;
F_44 ( V_16 ) ;
F_11 ( V_86 , F_4 ( V_86 ) | V_88 ) ;
}
static void
F_45 ( struct V_83 * V_84 )
{
struct V_15 * V_16 = V_84 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_85 * V_85 = F_42 ( V_84 ) ;
int V_86 = F_43 ( V_85 -> V_2 ) ;
if ( V_85 -> V_87 )
return;
F_11 ( V_86 , F_4 ( V_86 ) & ~ V_88 ) ;
V_85 -> V_87 = true ;
F_44 ( V_16 ) ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_68 ;
int V_57 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_11 ( F_47 ( V_20 -> V_21 ) , V_56 -> V_58 ) ;
F_11 ( F_48 ( V_20 -> V_21 ) , V_56 -> V_59 ) ;
F_11 ( F_49 ( V_20 -> V_21 ) , V_56 -> V_60 ) ;
V_68 = F_4 ( F_30 ( V_20 -> V_21 ) ) ;
V_68 &= ~ ( V_89 | V_90 ) ;
if ( V_56 -> V_63 & V_64 )
V_68 |= V_90 ;
else if ( V_56 -> V_63 & V_65 )
V_68 |= V_89 ;
F_11 ( F_30 ( V_20 -> V_21 ) , V_68 ) ;
F_22 ( F_49 ( V_20 -> V_21 ) ) ;
return V_57 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_68 ;
V_20 = F_2 ( V_2 ) ;
V_56 -> V_58 = F_4 ( F_47 ( V_20 -> V_21 ) ) ;
V_56 -> V_59 = F_4 ( F_48 ( V_20 -> V_21 ) ) ;
V_56 -> V_60 = F_4 ( F_49 ( V_20 -> V_21 ) ) ;
V_56 -> V_63 = 0 ;
V_68 = F_4 ( F_30 ( V_20 -> V_21 ) ) ;
if ( V_68 & V_90 )
V_56 -> V_63 = V_64 ;
else if ( V_68 & V_89 )
V_56 -> V_63 = V_65 ;
else
V_56 -> V_63 = V_66 ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_91 , T_1 V_92 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_85 * V_85 = F_42 ( V_84 ) ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
struct V_93 * V_94 ;
struct V_5 * V_6 , * V_95 ;
int V_21 = V_20 -> V_21 ;
enum V_96 V_97 = F_52 ( V_18 ,
V_21 ) ;
int V_57 = 0 ;
int V_11 = V_91 >> 16 , V_12 = V_92 >> 16 ;
int V_98 = V_84 -> V_99 . V_100 , V_101 = V_84 -> V_99 . V_102 ;
bool V_103 = false ;
V_94 = F_53 ( V_4 ) ;
V_6 = V_94 -> V_6 ;
V_95 = V_20 -> V_6 ;
V_13 = V_13 >> 16 ;
V_14 = V_14 >> 16 ;
if ( ! ( F_4 ( F_54 ( V_97 ) ) & V_104 ) )
return - V_105 ;
if ( V_7 >= V_98 || V_8 >= V_101 )
return - V_105 ;
if ( V_20 -> V_21 != V_85 -> V_21 )
return - V_105 ;
switch ( V_6 -> V_46 ) {
case V_47 :
case V_106 :
break;
default:
return - V_105 ;
}
if ( ( V_7 < 0 ) && ( ( V_7 + V_9 ) > 0 ) ) {
V_9 += V_7 ;
V_7 = 0 ;
}
if ( ( V_7 + V_9 ) <= 0 )
goto V_107;
if ( ( V_7 + V_9 ) > V_98 )
V_9 = V_98 - V_7 ;
if ( ( V_8 < 0 ) && ( ( V_8 + V_10 ) > 0 ) ) {
V_10 += V_8 ;
V_8 = 0 ;
}
if ( ( V_8 + V_10 ) <= 0 )
goto V_107;
if ( V_8 + V_10 > V_101 )
V_10 = V_101 - V_8 ;
if ( ! V_9 || ! V_10 )
goto V_107;
if ( ! V_20 -> V_53 && ( V_9 != V_13 || V_10 != V_14 ) )
return - V_105 ;
if ( ( ( V_13 * V_14 ) / ( V_9 * V_10 ) ) > V_20 -> V_108 )
return - V_105 ;
if ( ( V_7 == 0 ) && ( V_8 == 0 ) &&
( V_9 == V_98 ) && ( V_10 == V_101 ) )
V_103 = true ;
F_55 ( & V_16 -> V_109 ) ;
V_57 = F_56 ( V_16 , V_6 , NULL ) ;
if ( V_57 )
goto V_110;
V_20 -> V_6 = V_6 ;
if ( ! V_103 )
F_41 ( V_84 ) ;
V_20 -> V_111 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_103 )
F_45 ( V_84 ) ;
if ( V_95 ) {
if ( V_95 != V_6 ) {
F_57 ( & V_16 -> V_109 ) ;
F_10 ( V_16 , F_42 ( V_84 ) -> V_21 ) ;
F_55 ( & V_16 -> V_109 ) ;
}
F_58 ( V_95 ) ;
}
V_110:
F_57 ( & V_16 -> V_109 ) ;
V_107:
return V_57 ;
}
static int
F_59 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_57 = 0 ;
if ( V_2 -> V_84 )
F_41 ( V_2 -> V_84 ) ;
V_20 -> V_112 ( V_2 ) ;
if ( ! V_20 -> V_6 )
goto V_107;
F_55 ( & V_16 -> V_109 ) ;
F_58 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_57 ( & V_16 -> V_109 ) ;
V_107:
return V_57 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_2 ( V_2 ) ;
F_59 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_20 ) ;
}
int F_63 ( struct V_15 * V_16 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_55 * V_116 = V_113 ;
struct V_117 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_57 = 0 ;
if ( ! F_64 ( V_16 , V_118 ) )
return - V_119 ;
if ( ( V_116 -> V_63 & ( V_64 | V_65 ) ) == ( V_64 | V_65 ) )
return - V_105 ;
F_65 ( V_16 ) ;
V_6 = F_66 ( V_16 , V_116 -> V_120 , V_121 ) ;
if ( ! V_6 ) {
V_57 = - V_105 ;
goto V_110;
}
V_2 = F_67 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_57 = V_20 -> V_122 ( V_2 , V_116 ) ;
V_110:
F_68 ( V_16 ) ;
return V_57 ;
}
int F_69 ( struct V_15 * V_16 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_55 * V_123 = V_113 ;
struct V_117 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_57 = 0 ;
if ( ! F_64 ( V_16 , V_118 ) )
return - V_119 ;
F_65 ( V_16 ) ;
V_6 = F_66 ( V_16 , V_123 -> V_120 , V_121 ) ;
if ( ! V_6 ) {
V_57 = - V_105 ;
goto V_110;
}
V_2 = F_67 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_20 -> V_124 ( V_2 , V_123 ) ;
V_110:
F_68 ( V_16 ) ;
return V_57 ;
}
int
F_70 ( struct V_15 * V_16 , enum V_21 V_21 )
{
struct V_20 * V_20 ;
unsigned long V_125 ;
const T_1 * V_126 ;
int V_127 ;
int V_57 ;
if ( F_71 ( V_16 ) -> V_128 < 5 )
return - V_119 ;
V_20 = F_72 ( sizeof( struct V_20 ) , V_129 ) ;
if ( ! V_20 )
return - V_130 ;
switch ( F_71 ( V_16 ) -> V_128 ) {
case 5 :
case 6 :
V_20 -> V_53 = true ;
V_20 -> V_108 = 16 ;
V_20 -> V_111 = F_29 ;
V_20 -> V_112 = F_40 ;
V_20 -> V_122 = F_46 ;
V_20 -> V_124 = F_50 ;
if ( F_31 ( V_16 ) ) {
V_126 = V_131 ;
V_127 = F_73 ( V_131 ) ;
} else {
V_126 = V_132 ;
V_127 = F_73 ( V_132 ) ;
}
break;
case 7 :
if ( F_7 ( V_16 ) || F_74 ( V_16 ) )
V_20 -> V_53 = false ;
else
V_20 -> V_53 = true ;
V_20 -> V_108 = 2 ;
V_20 -> V_111 = F_1 ;
V_20 -> V_112 = F_23 ;
V_20 -> V_122 = F_24 ;
V_20 -> V_124 = F_28 ;
V_126 = V_131 ;
V_127 = F_73 ( V_131 ) ;
break;
default:
F_62 ( V_20 ) ;
return - V_119 ;
}
V_20 -> V_21 = V_21 ;
V_125 = ( 1 << V_21 ) ;
V_57 = F_75 ( V_16 , & V_20 -> V_133 , V_125 ,
& V_134 ,
V_126 , V_127 ,
false ) ;
if ( V_57 )
F_62 ( V_20 ) ;
return V_57 ;
}
