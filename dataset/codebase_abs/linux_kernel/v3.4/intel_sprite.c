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
switch ( V_4 -> V_28 ) {
case V_29 :
V_22 |= V_30 ;
V_24 = 4 ;
break;
case V_31 :
V_22 |= V_30 | V_26 ;
V_24 = 4 ;
break;
case V_32 :
V_22 |= V_33 | V_34 ;
V_24 = 2 ;
break;
case V_35 :
V_22 |= V_33 | V_36 ;
V_24 = 2 ;
break;
case V_37 :
V_22 |= V_33 | V_38 ;
V_24 = 2 ;
break;
case V_39 :
V_22 |= V_33 | V_40 ;
V_24 = 2 ;
break;
default:
F_5 ( L_1 ) ;
V_22 |= V_41 ;
V_24 = 4 ;
break;
}
if ( V_6 -> V_42 != V_43 )
V_22 |= V_44 ;
V_22 |= V_45 ;
V_22 |= V_46 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_6 ( V_16 , V_21 , V_9 , V_24 ) ;
if ( V_9 != V_13 || V_10 != V_14 ) {
V_18 -> V_47 = true ;
F_7 ( V_16 ) ;
F_8 ( V_16 , V_21 ) ;
V_23 = V_48 | ( V_13 << 16 ) | V_14 ;
} else {
V_18 -> V_47 = false ;
F_7 ( V_16 ) ;
}
F_9 ( F_10 ( V_21 ) , V_4 -> V_49 [ 0 ] ) ;
F_9 ( F_11 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
if ( V_6 -> V_42 != V_43 ) {
F_9 ( F_12 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
} else {
unsigned long V_50 ;
V_50 = V_12 * V_4 -> V_49 [ 0 ] + V_11 * ( V_4 -> V_51 / 8 ) ;
F_9 ( F_13 ( V_21 ) , V_50 ) ;
}
F_9 ( F_14 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_9 ( F_15 ( V_21 ) , V_23 ) ;
F_9 ( F_4 ( V_21 ) , V_22 ) ;
F_9 ( F_16 ( V_21 ) , V_6 -> V_52 ) ;
F_17 ( F_16 ( V_21 ) ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_9 ( F_4 ( V_21 ) , F_3 ( F_4 ( V_21 ) ) & ~ V_46 ) ;
F_9 ( F_15 ( V_21 ) , 0 ) ;
F_9 ( F_16 ( V_21 ) , 0 ) ;
F_17 ( F_16 ( V_21 ) ) ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
int V_55 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_9 ( F_20 ( V_20 -> V_21 ) , V_54 -> V_56 ) ;
F_9 ( F_21 ( V_20 -> V_21 ) , V_54 -> V_57 ) ;
F_9 ( F_22 ( V_20 -> V_21 ) , V_54 -> V_58 ) ;
V_22 = F_3 ( F_4 ( V_20 -> V_21 ) ) ;
V_22 &= ~ ( V_59 | V_60 ) ;
if ( V_54 -> V_61 & V_62 )
V_22 |= V_60 ;
else if ( V_54 -> V_61 & V_63 )
V_22 |= V_59 ;
F_9 ( F_4 ( V_20 -> V_21 ) , V_22 ) ;
F_17 ( F_22 ( V_20 -> V_21 ) ) ;
return V_55 ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_22 ;
V_20 = F_2 ( V_2 ) ;
V_54 -> V_56 = F_3 ( F_20 ( V_20 -> V_21 ) ) ;
V_54 -> V_57 = F_3 ( F_21 ( V_20 -> V_21 ) ) ;
V_54 -> V_58 = F_3 ( F_22 ( V_20 -> V_21 ) ) ;
V_54 -> V_61 = 0 ;
V_22 = F_3 ( F_4 ( V_20 -> V_21 ) ) ;
if ( V_22 & V_60 )
V_54 -> V_61 = V_62 ;
else if ( V_22 & V_59 )
V_54 -> V_61 = V_63 ;
else
V_54 -> V_61 = V_64 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 , V_24 ;
T_2 V_65 , V_66 = 0 ;
V_65 = F_3 ( F_25 ( V_21 ) ) ;
V_65 &= ~ V_67 ;
V_65 &= ~ V_68 ;
V_65 &= ~ V_69 ;
switch ( V_4 -> V_28 ) {
case V_29 :
V_65 |= V_41 | V_68 ;
V_24 = 4 ;
break;
case V_31 :
V_65 |= V_41 ;
V_24 = 4 ;
break;
case V_32 :
V_65 |= V_70 | V_71 ;
V_24 = 2 ;
break;
case V_35 :
V_65 |= V_70 | V_72 ;
V_24 = 2 ;
break;
case V_37 :
V_65 |= V_70 | V_73 ;
V_24 = 2 ;
break;
case V_39 :
V_65 |= V_70 | V_74 ;
V_24 = 2 ;
break;
default:
F_5 ( L_1 ) ;
V_65 |= V_41 ;
V_24 = 4 ;
break;
}
if ( V_6 -> V_42 != V_43 )
V_65 |= V_75 ;
V_65 |= V_76 ;
V_65 |= V_77 ;
V_13 -- ;
V_14 -- ;
V_9 -- ;
V_10 -- ;
F_6 ( V_16 , V_21 , V_9 , V_24 ) ;
if ( V_9 != V_13 || V_10 != V_14 )
V_66 = V_78 | ( V_13 << 16 ) | V_14 ;
F_9 ( F_26 ( V_21 ) , V_4 -> V_49 [ 0 ] ) ;
F_9 ( F_27 ( V_21 ) , ( V_8 << 16 ) | V_7 ) ;
if ( V_6 -> V_42 != V_43 ) {
F_9 ( F_28 ( V_21 ) , ( V_12 << 16 ) | V_11 ) ;
} else {
unsigned long V_50 ;
V_50 = V_12 * V_4 -> V_49 [ 0 ] + V_11 * ( V_4 -> V_51 / 8 ) ;
F_9 ( F_29 ( V_21 ) , V_50 ) ;
}
F_9 ( F_30 ( V_21 ) , ( V_10 << 16 ) | V_9 ) ;
F_9 ( F_31 ( V_21 ) , V_66 ) ;
F_9 ( F_25 ( V_21 ) , V_65 ) ;
F_9 ( F_32 ( V_21 ) , V_6 -> V_52 ) ;
F_17 ( F_32 ( V_21 ) ) ;
}
static void
F_33 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_21 = V_20 -> V_21 ;
F_9 ( F_25 ( V_21 ) , F_3 ( F_25 ( V_21 ) ) & ~ V_77 ) ;
F_9 ( F_31 ( V_21 ) , 0 ) ;
F_9 ( F_32 ( V_21 ) , 0 ) ;
F_17 ( F_32 ( V_21 ) ) ;
}
static void
F_34 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = V_80 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_35 ( V_80 ) ;
int V_82 = F_36 ( V_81 -> V_2 ) ;
F_9 ( V_82 , F_3 ( V_82 ) | V_83 ) ;
}
static void
F_37 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = V_80 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_35 ( V_80 ) ;
int V_82 = F_36 ( V_81 -> V_2 ) ;
F_9 ( V_82 , F_3 ( V_82 ) & ~ V_83 ) ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_65 ;
int V_55 = 0 ;
V_20 = F_2 ( V_2 ) ;
F_9 ( F_39 ( V_20 -> V_21 ) , V_54 -> V_56 ) ;
F_9 ( F_40 ( V_20 -> V_21 ) , V_54 -> V_57 ) ;
F_9 ( F_41 ( V_20 -> V_21 ) , V_54 -> V_58 ) ;
V_65 = F_3 ( F_25 ( V_20 -> V_21 ) ) ;
V_65 &= ~ ( V_84 | V_85 ) ;
if ( V_54 -> V_61 & V_62 )
V_65 |= V_85 ;
else if ( V_54 -> V_61 & V_63 )
V_65 |= V_84 ;
F_9 ( F_25 ( V_20 -> V_21 ) , V_65 ) ;
F_17 ( F_41 ( V_20 -> V_21 ) ) ;
return V_55 ;
}
static void
F_42 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_20 ;
T_2 V_65 ;
V_20 = F_2 ( V_2 ) ;
V_54 -> V_56 = F_3 ( F_39 ( V_20 -> V_21 ) ) ;
V_54 -> V_57 = F_3 ( F_40 ( V_20 -> V_21 ) ) ;
V_54 -> V_58 = F_3 ( F_41 ( V_20 -> V_21 ) ) ;
V_54 -> V_61 = 0 ;
V_65 = F_3 ( F_25 ( V_20 -> V_21 ) ) ;
if ( V_65 & V_85 )
V_54 -> V_61 = V_62 ;
else if ( V_65 & V_84 )
V_54 -> V_61 = V_63 ;
else
V_54 -> V_61 = V_64 ;
}
static int
F_43 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_3 * V_4 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_86 , T_1 V_87 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_81 * V_81 = F_35 ( V_80 ) ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
struct V_88 * V_89 ;
struct V_5 * V_6 , * V_90 ;
int V_21 = V_20 -> V_21 ;
int V_55 = 0 ;
int V_11 = V_86 >> 16 , V_12 = V_87 >> 16 ;
int V_91 = V_80 -> V_92 . V_93 , V_94 = V_80 -> V_92 . V_95 ;
bool V_96 = false ;
V_89 = F_44 ( V_4 ) ;
V_6 = V_89 -> V_6 ;
V_90 = V_20 -> V_6 ;
V_13 = V_13 >> 16 ;
V_14 = V_14 >> 16 ;
if ( ! ( F_3 ( F_45 ( V_21 ) ) & V_97 ) )
return - V_98 ;
if ( V_7 >= V_91 || V_8 >= V_94 )
return - V_98 ;
if ( V_20 -> V_21 != V_81 -> V_21 )
return - V_98 ;
if ( ( V_7 < 0 ) && ( ( V_7 + V_9 ) > 0 ) ) {
V_9 += V_7 ;
V_7 = 0 ;
}
if ( ( V_7 + V_9 ) <= 0 )
goto V_99;
if ( ( V_7 + V_9 ) > V_91 )
V_9 = V_91 - V_7 ;
if ( ( V_8 < 0 ) && ( ( V_8 + V_10 ) > 0 ) ) {
V_10 += V_8 ;
V_8 = 0 ;
}
if ( ( V_8 + V_10 ) <= 0 )
goto V_99;
if ( V_8 + V_10 > V_94 )
V_10 = V_94 - V_8 ;
if ( ! V_9 || ! V_10 )
goto V_99;
if ( ( ( V_13 * V_14 ) / ( V_9 * V_10 ) ) > V_20 -> V_100 )
return - V_98 ;
if ( ( V_7 == 0 ) && ( V_8 == 0 ) &&
( V_9 == V_91 ) && ( V_10 == V_94 ) )
V_96 = true ;
F_46 ( & V_16 -> V_101 ) ;
V_55 = F_47 ( V_16 , V_6 , NULL ) ;
if ( V_55 )
goto V_102;
V_20 -> V_6 = V_6 ;
if ( ! V_96 && V_20 -> V_103 ) {
F_34 ( V_80 ) ;
V_20 -> V_103 = false ;
}
V_20 -> V_104 ( V_2 , V_4 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_96 ) {
F_37 ( V_80 ) ;
V_20 -> V_103 = true ;
}
if ( V_90 ) {
if ( V_90 != V_6 ) {
F_48 ( & V_16 -> V_101 ) ;
F_8 ( V_16 , F_35 ( V_80 ) -> V_21 ) ;
F_46 ( & V_16 -> V_101 ) ;
}
F_49 ( V_90 ) ;
}
V_102:
F_48 ( & V_16 -> V_101 ) ;
V_99:
return V_55 ;
}
static int
F_50 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_20 * V_20 = F_2 ( V_2 ) ;
int V_55 = 0 ;
if ( V_20 -> V_103 ) {
F_34 ( V_2 -> V_80 ) ;
V_20 -> V_103 = false ;
}
V_20 -> V_105 ( V_2 ) ;
if ( ! V_20 -> V_6 )
goto V_99;
F_46 ( & V_16 -> V_101 ) ;
F_49 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
F_48 ( & V_16 -> V_101 ) ;
V_99:
return V_55 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_2 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_20 ) ;
}
int F_54 ( struct V_15 * V_16 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_53 * V_109 = V_106 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_110 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_55 = 0 ;
if ( ! V_18 )
return - V_98 ;
if ( ( V_109 -> V_61 & ( V_62 | V_63 ) ) == ( V_62 | V_63 ) )
return - V_98 ;
F_46 ( & V_16 -> V_111 . V_112 ) ;
V_6 = F_55 ( V_16 , V_109 -> V_113 , V_114 ) ;
if ( ! V_6 ) {
V_55 = - V_98 ;
goto V_102;
}
V_2 = F_56 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_55 = V_20 -> V_115 ( V_2 , V_109 ) ;
V_102:
F_48 ( & V_16 -> V_111 . V_112 ) ;
return V_55 ;
}
int F_57 ( struct V_15 * V_16 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_53 * V_116 = V_106 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_110 * V_6 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_55 = 0 ;
if ( ! V_18 )
return - V_98 ;
F_46 ( & V_16 -> V_111 . V_112 ) ;
V_6 = F_55 ( V_16 , V_116 -> V_113 , V_114 ) ;
if ( ! V_6 ) {
V_55 = - V_98 ;
goto V_102;
}
V_2 = F_56 ( V_6 ) ;
V_20 = F_2 ( V_2 ) ;
V_20 -> V_117 ( V_2 , V_116 ) ;
V_102:
F_48 ( & V_16 -> V_111 . V_112 ) ;
return V_55 ;
}
int
F_58 ( struct V_15 * V_16 , enum V_21 V_21 )
{
struct V_20 * V_20 ;
unsigned long V_118 ;
int V_55 ;
if ( ! ( F_59 ( V_16 ) || F_60 ( V_16 ) ) )
return - V_119 ;
V_20 = F_61 ( sizeof( struct V_20 ) , V_120 ) ;
if ( ! V_20 )
return - V_121 ;
if ( F_59 ( V_16 ) ) {
V_20 -> V_100 = 16 ;
V_20 -> V_104 = F_24 ;
V_20 -> V_105 = F_33 ;
V_20 -> V_115 = F_38 ;
V_20 -> V_117 = F_42 ;
} else if ( F_60 ( V_16 ) ) {
V_20 -> V_100 = 2 ;
V_20 -> V_104 = F_1 ;
V_20 -> V_105 = F_18 ;
V_20 -> V_115 = F_19 ;
V_20 -> V_117 = F_23 ;
}
V_20 -> V_21 = V_21 ;
V_118 = ( 1 << V_21 ) ;
V_55 = F_62 ( V_16 , & V_20 -> V_122 , V_118 ,
& V_123 , V_124 ,
F_63 ( V_124 ) , false ) ;
if ( V_55 )
F_53 ( V_20 ) ;
return V_55 ;
}
