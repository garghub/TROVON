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
int V_24 ;
V_22 = F_3 ( F_4 ( V_21 ) ) ;
V_22 &= ~ V_25 ;
V_22 &= ~ V_26 ;
V_22 &= ~ V_27 ;
V_22 &= ~ V_28 ;
switch ( V_4 -> V_29 ) {
case V_30 :
V_22 |= V_31 | V_26 ;
V_24 = 4 ;
break;
case V_32 :
V_22 |= V_31 ;
V_24 = 4 ;
break;
case V_33 :
V_22 |= V_34 | V_35 ;
V_24 = 2 ;
break;
case V_36 :
V_22 |= V_34 | V_37 ;
V_24 = 2 ;
break;
case V_38 :
V_22 |= V_34 | V_39 ;
V_24 = 2 ;
break;
case V_40 :
V_22 |= V_34 | V_41 ;
V_24 = 2 ;
break;
default:
F_5 ( L_1 ) ;
V_22 |= V_31 ;
V_24 = 4 ;
break;
}
if ( V_6 -> V_42 != V_43 )
V_22 |= V_28 ;
V_22 |= V_44 ;
V_22 |= V_45 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_6 ( V_16 , V_21 , V_9 , V_24 ) ;
if ( V_9 != V_13 || V_10 != V_14 ) {
if ( ! V_18 -> V_46 ) {
V_18 -> V_46 = true ;
F_7 ( V_16 ) ;
F_8 ( V_16 , V_21 ) ;
}
V_23 = V_47 | ( V_13 << 16 ) | V_14 ;
} else {
if ( V_18 -> V_46 ) {
V_18 -> V_46 = false ;
F_7 ( V_16 ) ;
}
}
F_9 ( F_10 ( V_21 ) , V_4 -> V_48 [ 0 ] ) ;
F_9 ( F_11 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
if ( V_6 -> V_42 != V_43 ) {
F_9 ( F_12 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
} else {
unsigned long V_49 ;
V_49 = V_12 * V_4 -> V_48 [ 0 ] + V_11 * ( V_4 -> V_50 / 8 ) ;
F_9 ( F_13 ( V_21 ) , V_49 ) ;
}
F_9 ( F_14 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_9 ( F_15 ( V_21 ) , V_23 ) ;
F_9 ( F_4 ( V_21 ) , V_22 ) ;
F_16 ( F_17 ( V_21 ) , V_6 -> V_51 ) ;
F_18 ( F_17 ( V_21 ) ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_9 ( F_4 ( V_21 ) , F_3 ( F_4 ( V_21 ) ) & ~ V_45 ) ;
F_9 ( F_15 ( V_21 ) , 0 ) ;
F_16 ( F_17 ( V_21 ) , 0 ) ;
F_18 ( F_17 ( V_21 ) ) ;
V_18 -> V_46 = false ;
F_7 ( V_16 ) ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
int V_54 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_9 ( F_21 ( V_20 -> V_21 ) , V_53 -> V_55 ) ;
F_9 ( F_22 ( V_20 -> V_21 ) , V_53 -> V_56 ) ;
F_9 ( F_23 ( V_20 -> V_21 ) , V_53 -> V_57 ) ;
V_22 = F_3 ( F_4 ( V_20 -> V_21 ) ) ;
V_22 &= ~ ( V_58 | V_59 ) ;
if ( V_53 -> V_60 & V_61 )
V_22 |= V_59 ;
else if ( V_53 -> V_60 & V_62 )
V_22 |= V_58 ;
F_9 ( F_4 ( V_20 -> V_21 ) , V_22 ) ;
F_18 ( F_23 ( V_20 -> V_21 ) ) ;
return V_54 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
V_20 = F_2 ( V_2 ) ;
V_53 -> V_55 = F_3 ( F_21 ( V_20 -> V_21 ) ) ;
V_53 -> V_56 = F_3 ( F_22 ( V_20 -> V_21 ) ) ;
V_53 -> V_57 = F_3 ( F_23 ( V_20 -> V_21 ) ) ;
V_53 -> V_60 = 0 ;
V_22 = F_3 ( F_4 ( V_20 -> V_21 ) ) ;
if ( V_22 & V_59 )
V_53 -> V_60 = V_61 ;
else if ( V_22 & V_58 )
V_53 -> V_60 = V_62 ;
else
V_53 -> V_60 = V_63 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 , V_24 ;
T_2 V_64 , V_65 ;
V_64 = F_3 ( F_26 ( V_21 ) ) ;
V_64 &= ~ V_66 ;
V_64 &= ~ V_67 ;
V_64 &= ~ V_68 ;
V_64 &= ~ V_69 ;
switch ( V_4 -> V_29 ) {
case V_30 :
V_64 |= V_70 | V_67 ;
V_24 = 4 ;
break;
case V_32 :
V_64 |= V_70 ;
V_24 = 4 ;
break;
case V_33 :
V_64 |= V_71 | V_72 ;
V_24 = 2 ;
break;
case V_36 :
V_64 |= V_71 | V_73 ;
V_24 = 2 ;
break;
case V_38 :
V_64 |= V_71 | V_74 ;
V_24 = 2 ;
break;
case V_40 :
V_64 |= V_71 | V_75 ;
V_24 = 2 ;
break;
default:
F_5 ( L_1 ) ;
V_64 |= V_70 ;
V_24 = 4 ;
break;
}
if ( V_6 -> V_42 != V_43 )
V_64 |= V_69 ;
if ( F_27 ( V_16 ) )
V_64 |= V_76 ;
V_64 |= V_77 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_6 ( V_16 , V_21 , V_9 , V_24 ) ;
V_65 = 0 ;
if ( F_28 ( V_16 ) || V_9 != V_13 || V_10 != V_14 )
V_65 = V_78 | ( V_13 << 16 ) | V_14 ;
F_9 ( F_29 ( V_21 ) , V_4 -> V_48 [ 0 ] ) ;
F_9 ( F_30 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
if ( V_6 -> V_42 != V_43 ) {
F_9 ( F_31 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
} else {
unsigned long V_49 ;
V_49 = V_12 * V_4 -> V_48 [ 0 ] + V_11 * ( V_4 -> V_50 / 8 ) ;
F_9 ( F_32 ( V_21 ) , V_49 ) ;
}
F_9 ( F_33 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_9 ( F_34 ( V_21 ) , V_65 ) ;
F_9 ( F_26 ( V_21 ) , V_64 ) ;
F_16 ( F_35 ( V_21 ) , V_6 -> V_51 ) ;
F_18 ( F_35 ( V_21 ) ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_9 ( F_26 ( V_21 ) , F_3 ( F_26 ( V_21 ) ) & ~ V_77 ) ;
F_9 ( F_34 ( V_21 ) , 0 ) ;
F_16 ( F_35 ( V_21 ) , 0 ) ;
F_18 ( F_35 ( V_21 ) ) ;
}
static void
F_37 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = V_80 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_38 ( V_80 ) ;
int V_82 = F_39 ( V_81 -> V_2 ) ;
if ( ! V_81 -> V_83 )
return;
V_81 -> V_83 = false ;
F_40 ( V_16 ) ;
F_9 ( V_82 , F_3 ( V_82 ) | V_84 ) ;
}
static void
F_41 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = V_80 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_38 ( V_80 ) ;
int V_82 = F_39 ( V_81 -> V_2 ) ;
if ( V_81 -> V_83 )
return;
F_9 ( V_82 , F_3 ( V_82 ) & ~ V_84 ) ;
V_81 -> V_83 = true ;
F_40 ( V_16 ) ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_64 ;
int V_54 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_9 ( F_43 ( V_20 -> V_21 ) , V_53 -> V_55 ) ;
F_9 ( F_44 ( V_20 -> V_21 ) , V_53 -> V_56 ) ;
F_9 ( F_45 ( V_20 -> V_21 ) , V_53 -> V_57 ) ;
V_64 = F_3 ( F_26 ( V_20 -> V_21 ) ) ;
V_64 &= ~ ( V_85 | V_86 ) ;
if ( V_53 -> V_60 & V_61 )
V_64 |= V_86 ;
else if ( V_53 -> V_60 & V_62 )
V_64 |= V_85 ;
F_9 ( F_26 ( V_20 -> V_21 ) , V_64 ) ;
F_18 ( F_45 ( V_20 -> V_21 ) ) ;
return V_54 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_64 ;
V_20 = F_2 ( V_2 ) ;
V_53 -> V_55 = F_3 ( F_43 ( V_20 -> V_21 ) ) ;
V_53 -> V_56 = F_3 ( F_44 ( V_20 -> V_21 ) ) ;
V_53 -> V_57 = F_3 ( F_45 ( V_20 -> V_21 ) ) ;
V_53 -> V_60 = 0 ;
V_64 = F_3 ( F_26 ( V_20 -> V_21 ) ) ;
if ( V_64 & V_86 )
V_53 -> V_60 = V_61 ;
else if ( V_64 & V_85 )
V_53 -> V_60 = V_62 ;
else
V_53 -> V_60 = V_63 ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_87 , T_1 V_88 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_38 ( V_80 ) ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
struct V_89 * V_90 ;
struct V_5 * V_6 , * V_91 ;
int V_21 = V_20 -> V_21 ;
int V_54 = 0 ;
int V_11 = V_87 >> 16 , V_12 = V_88 >> 16 ;
int V_92 = V_80 -> V_93 . V_94 , V_95 = V_80 -> V_93 . V_96 ;
bool V_97 = false ;
V_90 = F_48 ( V_4 ) ;
V_6 = V_90 -> V_6 ;
V_91 = V_20 -> V_6 ;
V_13 = V_13 >> 16 ;
V_14 = V_14 >> 16 ;
if ( ! ( F_3 ( F_49 ( V_21 ) ) & V_98 ) )
return - V_99 ;
if ( V_7 >= V_92 || V_8 >= V_95 )
return - V_99 ;
if ( V_20 -> V_21 != V_81 -> V_21 )
return - V_99 ;
if ( ( V_7 < 0 ) && ( ( V_7 + V_9 ) > 0 ) ) {
V_9 += V_7 ;
V_7 = 0 ;
}
if ( ( V_7 + V_9 ) <= 0 )
goto V_100;
if ( ( V_7 + V_9 ) > V_92 )
V_9 = V_92 - V_7 ;
if ( ( V_8 < 0 ) && ( ( V_8 + V_10 ) > 0 ) ) {
V_10 += V_8 ;
V_8 = 0 ;
}
if ( ( V_8 + V_10 ) <= 0 )
goto V_100;
if ( V_8 + V_10 > V_95 )
V_10 = V_95 - V_8 ;
if ( ! V_9 || ! V_10 )
goto V_100;
if ( ( ( V_13 * V_14 ) / ( V_9 * V_10 ) ) > V_20 -> V_101 )
return - V_99 ;
if ( ( V_7 == 0 ) && ( V_8 == 0 ) &&
( V_9 == V_92 ) && ( V_10 == V_95 ) )
V_97 = true ;
F_50 ( & V_16 -> V_102 ) ;
V_54 = F_51 ( V_16 , V_6 , NULL ) ;
if ( V_54 )
goto V_103;
V_20 -> V_6 = V_6 ;
if ( ! V_97 )
F_37 ( V_80 ) ;
V_20 -> V_104 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_97 )
F_41 ( V_80 ) ;
if ( V_91 ) {
if ( V_91 != V_6 ) {
F_52 ( & V_16 -> V_102 ) ;
F_8 ( V_16 , F_38 ( V_80 ) -> V_21 ) ;
F_50 ( & V_16 -> V_102 ) ;
}
F_53 ( V_91 ) ;
}
V_103:
F_52 ( & V_16 -> V_102 ) ;
V_100:
return V_54 ;
}
static int
F_54 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_54 = 0 ;
if ( V_2 -> V_80 )
F_37 ( V_2 -> V_80 ) ;
V_20 -> V_105 ( V_2 ) ;
if ( ! V_20 -> V_6 )
goto V_100;
F_50 ( & V_16 -> V_102 ) ;
F_53 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_52 ( & V_16 -> V_102 ) ;
V_100:
return V_54 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_2 ( V_2 ) ;
F_54 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_20 ) ;
}
int F_58 ( struct V_15 * V_16 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_52 * V_109 = V_106 ;
struct V_110 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_54 = 0 ;
if ( ! F_59 ( V_16 , V_111 ) )
return - V_112 ;
if ( ( V_109 -> V_60 & ( V_61 | V_62 ) ) == ( V_61 | V_62 ) )
return - V_99 ;
F_50 ( & V_16 -> V_113 . V_114 ) ;
V_6 = F_60 ( V_16 , V_109 -> V_115 , V_116 ) ;
if ( ! V_6 ) {
V_54 = - V_99 ;
goto V_103;
}
V_2 = F_61 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_54 = V_20 -> V_117 ( V_2 , V_109 ) ;
V_103:
F_52 ( & V_16 -> V_113 . V_114 ) ;
return V_54 ;
}
int F_62 ( struct V_15 * V_16 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_52 * V_118 = V_106 ;
struct V_110 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_54 = 0 ;
if ( ! F_59 ( V_16 , V_111 ) )
return - V_112 ;
F_50 ( & V_16 -> V_113 . V_114 ) ;
V_6 = F_60 ( V_16 , V_118 -> V_115 , V_116 ) ;
if ( ! V_6 ) {
V_54 = - V_99 ;
goto V_103;
}
V_2 = F_61 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_20 -> V_119 ( V_2 , V_118 ) ;
V_103:
F_52 ( & V_16 -> V_113 . V_114 ) ;
return V_54 ;
}
int
F_63 ( struct V_15 * V_16 , enum V_21 V_21 )
{
struct V_20 * V_20 ;
unsigned long V_120 ;
const T_1 * V_121 ;
int V_122 ;
int V_54 ;
if ( F_64 ( V_16 ) -> V_123 < 5 )
return - V_112 ;
V_20 = F_65 ( sizeof( struct V_20 ) , V_124 ) ;
if ( ! V_20 )
return - V_125 ;
switch ( F_64 ( V_16 ) -> V_123 ) {
case 5 :
case 6 :
V_20 -> V_101 = 16 ;
V_20 -> V_104 = F_25 ;
V_20 -> V_105 = F_36 ;
V_20 -> V_117 = F_42 ;
V_20 -> V_119 = F_46 ;
if ( F_27 ( V_16 ) ) {
V_121 = V_126 ;
V_122 = F_66 ( V_126 ) ;
} else {
V_121 = V_127 ;
V_122 = F_66 ( V_127 ) ;
}
break;
case 7 :
V_20 -> V_101 = 2 ;
V_20 -> V_104 = F_1 ;
V_20 -> V_105 = F_19 ;
V_20 -> V_117 = F_20 ;
V_20 -> V_119 = F_24 ;
V_121 = V_126 ;
V_122 = F_66 ( V_126 ) ;
break;
default:
F_57 ( V_20 ) ;
return - V_112 ;
}
V_20 -> V_21 = V_21 ;
V_120 = ( 1 << V_21 ) ;
V_54 = F_67 ( V_16 , & V_20 -> V_128 , V_120 ,
& V_129 ,
V_121 , V_122 ,
false ) ;
if ( V_54 )
F_57 ( V_20 ) ;
return V_54 ;
}
