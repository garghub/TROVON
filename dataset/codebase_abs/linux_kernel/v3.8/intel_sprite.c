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
V_22 = F_4 ( F_5 ( V_21 ) ) ;
V_22 &= ~ V_28 ;
V_22 &= ~ V_29 ;
V_22 &= ~ V_30 ;
V_22 &= ~ V_31 ;
switch ( V_4 -> V_27 ) {
case V_32 :
V_22 |= V_33 | V_29 ;
break;
case V_34 :
V_22 |= V_33 ;
break;
case V_35 :
V_22 |= V_36 | V_37 ;
break;
case V_38 :
V_22 |= V_36 | V_39 ;
break;
case V_40 :
V_22 |= V_36 | V_41 ;
break;
case V_42 :
V_22 |= V_36 | V_43 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_44 != V_45 )
V_22 |= V_31 ;
V_22 |= V_46 ;
V_22 |= V_47 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_7 ( V_16 , V_21 , V_9 , V_26 ) ;
if ( V_9 != V_13 || V_10 != V_14 ) {
if ( ! V_18 -> V_48 ) {
V_18 -> V_48 = true ;
F_8 ( V_16 ) ;
F_9 ( V_16 , V_21 ) ;
}
V_23 = V_49 | ( V_13 << 16 ) | V_14 ;
} else {
if ( V_18 -> V_48 ) {
V_18 -> V_48 = false ;
F_8 ( V_16 ) ;
}
}
F_10 ( F_11 ( V_21 ) , V_4 -> V_50 [ 0 ] ) ;
F_10 ( F_12 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_50 [ 0 ] + V_11 * V_26 ;
V_24 =
F_13 ( & V_11 , & V_12 ,
V_26 , V_4 -> V_50 [ 0 ] ) ;
V_25 -= V_24 ;
if ( F_14 ( V_16 ) )
F_10 ( F_15 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else if ( V_6 -> V_44 != V_45 )
F_10 ( F_16 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_10 ( F_17 ( V_21 ) , V_25 ) ;
F_10 ( F_18 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
if ( V_20 -> V_51 )
F_10 ( F_19 ( V_21 ) , V_23 ) ;
F_10 ( F_5 ( V_21 ) , V_22 ) ;
F_20 ( F_21 ( V_21 ) , V_6 -> V_52 + V_24 ) ;
F_22 ( F_21 ( V_21 ) ) ;
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_10 ( F_5 ( V_21 ) , F_4 ( F_5 ( V_21 ) ) & ~ V_47 ) ;
if ( V_20 -> V_51 )
F_10 ( F_19 ( V_21 ) , 0 ) ;
F_20 ( F_21 ( V_21 ) , 0 ) ;
F_22 ( F_21 ( V_21 ) ) ;
V_18 -> V_48 = false ;
F_8 ( V_16 ) ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
int V_55 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_10 ( F_25 ( V_20 -> V_21 ) , V_54 -> V_56 ) ;
F_10 ( F_26 ( V_20 -> V_21 ) , V_54 -> V_57 ) ;
F_10 ( F_27 ( V_20 -> V_21 ) , V_54 -> V_58 ) ;
V_22 = F_4 ( F_5 ( V_20 -> V_21 ) ) ;
V_22 &= ~ ( V_59 | V_60 ) ;
if ( V_54 -> V_61 & V_62 )
V_22 |= V_60 ;
else if ( V_54 -> V_61 & V_63 )
V_22 |= V_59 ;
F_10 ( F_5 ( V_20 -> V_21 ) , V_22 ) ;
F_22 ( F_27 ( V_20 -> V_21 ) ) ;
return V_55 ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
V_20 = F_2 ( V_2 ) ;
V_54 -> V_56 = F_4 ( F_25 ( V_20 -> V_21 ) ) ;
V_54 -> V_57 = F_4 ( F_26 ( V_20 -> V_21 ) ) ;
V_54 -> V_58 = F_4 ( F_27 ( V_20 -> V_21 ) ) ;
V_54 -> V_61 = 0 ;
V_22 = F_4 ( F_5 ( V_20 -> V_21 ) ) ;
if ( V_22 & V_60 )
V_54 -> V_61 = V_62 ;
else if ( V_22 & V_59 )
V_54 -> V_61 = V_63 ;
else
V_54 -> V_61 = V_64 ;
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
unsigned long V_65 , V_25 ;
T_2 V_66 , V_67 ;
int V_26 = F_3 ( V_4 -> V_27 , 0 ) ;
V_66 = F_4 ( F_30 ( V_21 ) ) ;
V_66 &= ~ V_68 ;
V_66 &= ~ V_69 ;
V_66 &= ~ V_70 ;
V_66 &= ~ V_71 ;
switch ( V_4 -> V_27 ) {
case V_32 :
V_66 |= V_72 | V_69 ;
break;
case V_34 :
V_66 |= V_72 ;
break;
case V_35 :
V_66 |= V_73 | V_74 ;
break;
case V_38 :
V_66 |= V_73 | V_75 ;
break;
case V_40 :
V_66 |= V_73 | V_76 ;
break;
case V_42 :
V_66 |= V_73 | V_77 ;
break;
default:
F_6 () ;
}
if ( V_6 -> V_44 != V_45 )
V_66 |= V_71 ;
if ( F_31 ( V_16 ) )
V_66 |= V_78 ;
V_66 |= V_79 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_7 ( V_16 , V_21 , V_9 , V_26 ) ;
V_67 = 0 ;
if ( F_32 ( V_16 ) || V_9 != V_13 || V_10 != V_14 )
V_67 = V_80 | ( V_13 << 16 ) | V_14 ;
F_10 ( F_33 ( V_21 ) , V_4 -> V_50 [ 0 ] ) ;
F_10 ( F_34 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
V_25 = V_12 * V_4 -> V_50 [ 0 ] + V_11 * V_26 ;
V_65 =
F_13 ( & V_11 , & V_12 ,
V_26 , V_4 -> V_50 [ 0 ] ) ;
V_25 -= V_65 ;
if ( V_6 -> V_44 != V_45 )
F_10 ( F_35 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
else
F_10 ( F_36 ( V_21 ) , V_25 ) ;
F_10 ( F_37 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_10 ( F_38 ( V_21 ) , V_67 ) ;
F_10 ( F_30 ( V_21 ) , V_66 ) ;
F_20 ( F_39 ( V_21 ) , V_6 -> V_52 + V_65 ) ;
F_22 ( F_39 ( V_21 ) ) ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_10 ( F_30 ( V_21 ) , F_4 ( F_30 ( V_21 ) ) & ~ V_79 ) ;
F_10 ( F_38 ( V_21 ) , 0 ) ;
F_20 ( F_39 ( V_21 ) , 0 ) ;
F_22 ( F_39 ( V_21 ) ) ;
}
static void
F_41 ( struct V_81 * V_82 )
{
struct V_15 * V_16 = V_82 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_83 * V_83 = F_42 ( V_82 ) ;
int V_84 = F_43 ( V_83 -> V_2 ) ;
if ( ! V_83 -> V_85 )
return;
V_83 -> V_85 = false ;
F_44 ( V_16 ) ;
F_10 ( V_84 , F_4 ( V_84 ) | V_86 ) ;
}
static void
F_45 ( struct V_81 * V_82 )
{
struct V_15 * V_16 = V_82 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_83 * V_83 = F_42 ( V_82 ) ;
int V_84 = F_43 ( V_83 -> V_2 ) ;
if ( V_83 -> V_85 )
return;
F_10 ( V_84 , F_4 ( V_84 ) & ~ V_86 ) ;
V_83 -> V_85 = true ;
F_44 ( V_16 ) ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_66 ;
int V_55 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_10 ( F_47 ( V_20 -> V_21 ) , V_54 -> V_56 ) ;
F_10 ( F_48 ( V_20 -> V_21 ) , V_54 -> V_57 ) ;
F_10 ( F_49 ( V_20 -> V_21 ) , V_54 -> V_58 ) ;
V_66 = F_4 ( F_30 ( V_20 -> V_21 ) ) ;
V_66 &= ~ ( V_87 | V_88 ) ;
if ( V_54 -> V_61 & V_62 )
V_66 |= V_88 ;
else if ( V_54 -> V_61 & V_63 )
V_66 |= V_87 ;
F_10 ( F_30 ( V_20 -> V_21 ) , V_66 ) ;
F_22 ( F_49 ( V_20 -> V_21 ) ) ;
return V_55 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_66 ;
V_20 = F_2 ( V_2 ) ;
V_54 -> V_56 = F_4 ( F_47 ( V_20 -> V_21 ) ) ;
V_54 -> V_57 = F_4 ( F_48 ( V_20 -> V_21 ) ) ;
V_54 -> V_58 = F_4 ( F_49 ( V_20 -> V_21 ) ) ;
V_54 -> V_61 = 0 ;
V_66 = F_4 ( F_30 ( V_20 -> V_21 ) ) ;
if ( V_66 & V_88 )
V_54 -> V_61 = V_62 ;
else if ( V_66 & V_87 )
V_54 -> V_61 = V_63 ;
else
V_54 -> V_61 = V_64 ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_81 * V_82 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_89 , T_1 V_90 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_83 * V_83 = F_42 ( V_82 ) ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
struct V_91 * V_92 ;
struct V_5 * V_6 , * V_93 ;
int V_21 = V_20 -> V_21 ;
enum V_94 V_95 = F_52 ( V_18 ,
V_21 ) ;
int V_55 = 0 ;
int V_11 = V_89 >> 16 , V_12 = V_90 >> 16 ;
int V_96 = V_82 -> V_97 . V_98 , V_99 = V_82 -> V_97 . V_100 ;
bool V_101 = false ;
V_92 = F_53 ( V_4 ) ;
V_6 = V_92 -> V_6 ;
V_93 = V_20 -> V_6 ;
V_13 = V_13 >> 16 ;
V_14 = V_14 >> 16 ;
if ( ! ( F_4 ( F_54 ( V_95 ) ) & V_102 ) )
return - V_103 ;
if ( V_7 >= V_96 || V_8 >= V_99 )
return - V_103 ;
if ( V_20 -> V_21 != V_83 -> V_21 )
return - V_103 ;
switch ( V_6 -> V_44 ) {
case V_45 :
case V_104 :
break;
default:
return - V_103 ;
}
if ( ( V_7 < 0 ) && ( ( V_7 + V_9 ) > 0 ) ) {
V_9 += V_7 ;
V_7 = 0 ;
}
if ( ( V_7 + V_9 ) <= 0 )
goto V_105;
if ( ( V_7 + V_9 ) > V_96 )
V_9 = V_96 - V_7 ;
if ( ( V_8 < 0 ) && ( ( V_8 + V_10 ) > 0 ) ) {
V_10 += V_8 ;
V_8 = 0 ;
}
if ( ( V_8 + V_10 ) <= 0 )
goto V_105;
if ( V_8 + V_10 > V_99 )
V_10 = V_99 - V_8 ;
if ( ! V_9 || ! V_10 )
goto V_105;
if ( ! V_20 -> V_51 && ( V_9 != V_13 || V_10 != V_14 ) )
return - V_103 ;
if ( ( ( V_13 * V_14 ) / ( V_9 * V_10 ) ) > V_20 -> V_106 )
return - V_103 ;
if ( ( V_7 == 0 ) && ( V_8 == 0 ) &&
( V_9 == V_96 ) && ( V_10 == V_99 ) )
V_101 = true ;
F_55 ( & V_16 -> V_107 ) ;
V_55 = F_56 ( V_16 , V_6 , NULL ) ;
if ( V_55 )
goto V_108;
V_20 -> V_6 = V_6 ;
if ( ! V_101 )
F_41 ( V_82 ) ;
V_20 -> V_109 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_101 )
F_45 ( V_82 ) ;
if ( V_93 ) {
if ( V_93 != V_6 ) {
F_57 ( & V_16 -> V_107 ) ;
F_9 ( V_16 , F_42 ( V_82 ) -> V_21 ) ;
F_55 ( & V_16 -> V_107 ) ;
}
F_58 ( V_93 ) ;
}
V_108:
F_57 ( & V_16 -> V_107 ) ;
V_105:
return V_55 ;
}
static int
F_59 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_55 = 0 ;
if ( V_2 -> V_82 )
F_41 ( V_2 -> V_82 ) ;
V_20 -> V_110 ( V_2 ) ;
if ( ! V_20 -> V_6 )
goto V_105;
F_55 ( & V_16 -> V_107 ) ;
F_58 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_57 ( & V_16 -> V_107 ) ;
V_105:
return V_55 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_2 ( V_2 ) ;
F_59 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_20 ) ;
}
int F_63 ( struct V_15 * V_16 , void * V_111 ,
struct V_112 * V_113 )
{
struct V_53 * V_114 = V_111 ;
struct V_115 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_55 = 0 ;
if ( ! F_64 ( V_16 , V_116 ) )
return - V_117 ;
if ( ( V_114 -> V_61 & ( V_62 | V_63 ) ) == ( V_62 | V_63 ) )
return - V_103 ;
F_55 ( & V_16 -> V_118 . V_119 ) ;
V_6 = F_65 ( V_16 , V_114 -> V_120 , V_121 ) ;
if ( ! V_6 ) {
V_55 = - V_103 ;
goto V_108;
}
V_2 = F_66 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_55 = V_20 -> V_122 ( V_2 , V_114 ) ;
V_108:
F_57 ( & V_16 -> V_118 . V_119 ) ;
return V_55 ;
}
int F_67 ( struct V_15 * V_16 , void * V_111 ,
struct V_112 * V_113 )
{
struct V_53 * V_123 = V_111 ;
struct V_115 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_55 = 0 ;
if ( ! F_64 ( V_16 , V_116 ) )
return - V_117 ;
F_55 ( & V_16 -> V_118 . V_119 ) ;
V_6 = F_65 ( V_16 , V_123 -> V_120 , V_121 ) ;
if ( ! V_6 ) {
V_55 = - V_103 ;
goto V_108;
}
V_2 = F_66 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_20 -> V_124 ( V_2 , V_123 ) ;
V_108:
F_57 ( & V_16 -> V_118 . V_119 ) ;
return V_55 ;
}
int
F_68 ( struct V_15 * V_16 , enum V_21 V_21 )
{
struct V_20 * V_20 ;
unsigned long V_125 ;
const T_1 * V_126 ;
int V_127 ;
int V_55 ;
if ( F_69 ( V_16 ) -> V_128 < 5 )
return - V_117 ;
V_20 = F_70 ( sizeof( struct V_20 ) , V_129 ) ;
if ( ! V_20 )
return - V_130 ;
switch ( F_69 ( V_16 ) -> V_128 ) {
case 5 :
case 6 :
V_20 -> V_51 = true ;
V_20 -> V_106 = 16 ;
V_20 -> V_109 = F_29 ;
V_20 -> V_110 = F_40 ;
V_20 -> V_122 = F_46 ;
V_20 -> V_124 = F_50 ;
if ( F_31 ( V_16 ) ) {
V_126 = V_131 ;
V_127 = F_71 ( V_131 ) ;
} else {
V_126 = V_132 ;
V_127 = F_71 ( V_132 ) ;
}
break;
case 7 :
if ( F_14 ( V_16 ) || F_72 ( V_16 ) )
V_20 -> V_51 = false ;
else
V_20 -> V_51 = true ;
V_20 -> V_106 = 2 ;
V_20 -> V_109 = F_1 ;
V_20 -> V_110 = F_23 ;
V_20 -> V_122 = F_24 ;
V_20 -> V_124 = F_28 ;
V_126 = V_131 ;
V_127 = F_71 ( V_131 ) ;
break;
default:
F_62 ( V_20 ) ;
return - V_117 ;
}
V_20 -> V_21 = V_21 ;
V_125 = ( 1 << V_21 ) ;
V_55 = F_73 ( V_16 , & V_20 -> V_133 , V_125 ,
& V_134 ,
V_126 , V_127 ,
false ) ;
if ( V_55 )
F_62 ( V_20 ) ;
return V_55 ;
}
