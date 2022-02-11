static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_2 V_5 , V_6 ;
int V_7 ;
struct V_8 V_9 ;
T_3 V_10 ;
V_5 = 0 ;
if ( ! ( V_2 -> V_11 || V_2 -> V_12 ) ) {
F_2 ( & V_2 -> V_13 -> V_14 , L_1 ) ;
return - V_15 ;
}
if ( V_2 -> V_16 == V_3 )
return 0 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_7 = V_2 -> V_21 ;
F_3 ( & V_2 -> V_22 , V_4 ) ;
if ( V_3 ) {
F_4 ( V_23 , V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
V_5 = F_6 ( V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
do {
V_5 &= ~ ( V_25 ) ;
F_4 ( V_5 , V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
V_5 = F_6 ( V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
} while ( V_5 & V_25 );
F_7 ( & V_2 -> V_26 ) ;
V_6 = F_6 ( V_2 -> V_24 + V_27 ) ;
V_6 |= V_28 ;
F_4 ( V_6 , V_2 -> V_24 + V_27 ) ;
V_6 = F_6 ( V_2 -> V_24 + V_29 ) ;
V_10 = F_8 ( & V_2 -> V_26 , V_6 ) ;
V_9 = F_9 ( V_10 ) ;
V_5 = V_30 - ( T_2 ) V_9 . V_31 + V_6 ;
V_5 += V_30 ;
V_5 &= V_2 -> V_32 . V_33 ;
F_4 ( V_5 , V_2 -> V_24 + F_10 ( V_2 -> V_17 ) ) ;
V_2 -> V_34 = ( V_5 + V_2 -> V_19 ) & V_2 -> V_32 . V_33 ;
V_5 = F_6 ( V_2 -> V_24 + V_27 ) ;
V_5 |= V_35 ;
F_4 ( V_5 , V_2 -> V_24 + V_27 ) ;
V_5 = F_6 ( V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
V_5 |= ( 1 << V_36 | 1 << V_37 ) ;
V_5 &= ~ ( 1 << V_38 ) ;
V_5 &= ~ ( V_25 ) ;
V_5 |= ( V_39 << V_40 ) ;
F_4 ( V_5 , V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
F_4 ( V_2 -> V_34 , V_2 -> V_24 + F_10 ( V_2 -> V_17 ) ) ;
V_2 -> V_34 = ( V_2 -> V_34 + V_2 -> V_19 ) & V_2 -> V_32 . V_33 ;
} else {
F_4 ( 0 , V_2 -> V_24 + F_5 ( V_2 -> V_17 ) ) ;
}
V_2 -> V_16 = V_3 ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
return 0 ;
}
static T_3 F_12 ( const struct V_41 * V_32 )
{
struct V_1 * V_2 =
F_13 ( V_32 , struct V_1 , V_32 ) ;
const struct V_42 * V_43 =
F_14 ( V_2 -> V_13 ) ;
T_2 V_6 ;
V_6 = F_6 ( V_2 -> V_24 + V_27 ) ;
V_6 |= V_28 ;
F_4 ( V_6 , V_2 -> V_24 + V_27 ) ;
if ( V_43 -> V_44 & V_45 )
F_15 ( 1 ) ;
return F_6 ( V_2 -> V_24 + V_29 ) ;
}
void F_16 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_17 ( V_47 ) ;
unsigned long V_4 ;
int V_7 ;
V_7 = 1000000000 / V_2 -> V_48 ;
F_3 ( & V_2 -> V_22 , V_4 ) ;
F_4 ( V_7 << V_49 , V_2 -> V_24 + V_50 ) ;
F_4 ( V_51 , V_2 -> V_24 + V_52 ) ;
F_4 ( V_53 | V_54 ,
V_2 -> V_24 + V_27 ) ;
memset ( & V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
V_2 -> V_32 . V_55 = F_12 ;
V_2 -> V_32 . V_33 = F_18 ( 31 ) ;
V_2 -> V_32 . V_56 = 31 ;
V_2 -> V_32 . V_57 = V_58 ;
F_19 ( & V_2 -> V_26 , & V_2 -> V_32 , F_20 ( F_21 () ) ) ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
}
static int F_22 ( struct V_59 * V_60 , T_4 V_61 )
{
unsigned long V_4 ;
int V_62 = 0 ;
T_2 V_63 , V_64 ;
T_2 V_65 , V_66 ;
T_2 V_67 ;
T_3 V_68 , V_69 ;
struct V_1 * V_2 =
F_13 ( V_60 , struct V_1 , V_70 ) ;
if ( V_61 == 0 )
return 0 ;
if ( V_61 < 0 ) {
V_61 = - V_61 ;
V_62 = 1 ;
}
V_68 = V_30 ;
V_69 = ( T_3 ) V_61 * ( T_3 ) V_2 -> V_21 ;
for ( V_63 = 1 ; V_63 <= V_2 -> V_21 ; V_63 ++ ) {
if ( V_68 >= V_69 ) {
V_65 = V_63 ;
V_66 = F_23 ( V_68 , V_69 ) ;
break;
}
V_68 += V_30 ;
}
if ( V_63 > V_2 -> V_21 ) {
V_65 = V_2 -> V_21 ;
V_66 = 1 ;
}
if ( V_62 )
V_67 = V_2 -> V_21 - V_65 ;
else
V_67 = V_2 -> V_21 + V_65 ;
F_3 ( & V_2 -> V_22 , V_4 ) ;
V_64 = F_6 ( V_2 -> V_24 + V_50 ) & V_71 ;
V_64 |= V_67 << V_72 ;
F_4 ( V_64 , V_2 -> V_24 + V_50 ) ;
V_66 = V_66 > 1 ? V_66 - 1 : V_66 ;
F_4 ( V_66 , V_2 -> V_24 + V_73 ) ;
F_7 ( & V_2 -> V_26 ) ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_59 * V_60 , T_5 V_74 )
{
struct V_1 * V_2 =
F_13 ( V_60 , struct V_1 , V_70 ) ;
unsigned long V_4 ;
F_3 ( & V_2 -> V_22 , V_4 ) ;
F_25 ( & V_2 -> V_26 , V_74 ) ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_59 * V_60 , struct V_8 * V_9 )
{
struct V_1 * V_75 =
F_13 ( V_60 , struct V_1 , V_70 ) ;
T_3 V_10 ;
unsigned long V_4 ;
F_3 ( & V_75 -> V_22 , V_4 ) ;
V_10 = F_7 ( & V_75 -> V_26 ) ;
F_11 ( & V_75 -> V_22 , V_4 ) ;
* V_9 = F_9 ( V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_59 * V_60 ,
const struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_13 ( V_60 , struct V_1 , V_70 ) ;
T_3 V_10 ;
unsigned long V_4 ;
T_2 V_76 ;
F_28 ( & V_2 -> V_77 ) ;
if ( ! V_2 -> V_78 ) {
F_29 ( & V_2 -> V_77 ) ;
return - V_15 ;
}
V_10 = F_30 ( V_9 ) ;
V_76 = V_10 & V_2 -> V_32 . V_33 ;
F_3 ( & V_2 -> V_22 , V_4 ) ;
F_4 ( V_76 , V_2 -> V_24 + V_29 ) ;
F_19 ( & V_2 -> V_26 , & V_2 -> V_32 , V_10 ) ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
F_29 ( & V_2 -> V_77 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_60 ,
struct V_79 * V_80 , int V_81 )
{
struct V_1 * V_2 =
F_13 ( V_60 , struct V_1 , V_70 ) ;
int V_82 = 0 ;
if ( V_80 -> type == V_83 ) {
V_82 = F_1 ( V_2 , V_81 ) ;
return V_82 ;
}
return - V_84 ;
}
int F_32 ( struct V_46 * V_47 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_87 V_88 ;
if ( F_33 ( & V_88 , V_86 -> V_89 , sizeof( V_88 ) ) )
return - V_90 ;
if ( V_88 . V_4 )
return - V_15 ;
switch ( V_88 . V_91 ) {
case V_92 :
V_2 -> V_11 = 0 ;
break;
case V_93 :
V_2 -> V_11 = 1 ;
break;
default:
return - V_94 ;
}
switch ( V_88 . V_95 ) {
case V_96 :
if ( V_2 -> V_12 )
V_2 -> V_12 = 0 ;
V_88 . V_95 = V_96 ;
break;
default:
V_2 -> V_12 = 1 ;
V_88 . V_95 = V_97 ;
break;
}
return F_34 ( V_86 -> V_89 , & V_88 , sizeof( V_88 ) ) ?
- V_90 : 0 ;
}
int F_35 ( struct V_46 * V_47 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_87 V_88 ;
V_88 . V_4 = 0 ;
V_88 . V_91 = V_2 -> V_11 ? V_93 : V_92 ;
V_88 . V_95 = ( V_2 -> V_12 ?
V_97 : V_96 ) ;
return F_34 ( V_86 -> V_89 , & V_88 , sizeof( V_88 ) ) ?
- V_90 : 0 ;
}
static void F_36 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_37 ( V_99 ) ;
struct V_1 * V_2 = F_13 ( V_101 , struct V_1 , V_102 ) ;
T_3 V_10 ;
unsigned long V_4 ;
F_28 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 ) {
F_3 ( & V_2 -> V_22 , V_4 ) ;
V_10 = F_7 ( & V_2 -> V_26 ) ;
F_11 ( & V_2 -> V_22 , V_4 ) ;
}
F_29 ( & V_2 -> V_77 ) ;
F_38 ( & V_2 -> V_102 , V_103 ) ;
}
void F_39 ( struct V_104 * V_13 )
{
struct V_46 * V_47 = F_40 ( V_13 ) ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
V_2 -> V_70 . V_105 = V_106 ;
snprintf ( V_2 -> V_70 . V_107 , 16 , L_2 ) ;
V_2 -> V_70 . V_108 = 250000000 ;
V_2 -> V_70 . V_109 = 0 ;
V_2 -> V_70 . V_110 = 0 ;
V_2 -> V_70 . V_111 = 0 ;
V_2 -> V_70 . V_112 = 0 ;
V_2 -> V_70 . V_113 = 1 ;
V_2 -> V_70 . V_114 = F_22 ;
V_2 -> V_70 . V_115 = F_24 ;
V_2 -> V_70 . V_116 = F_26 ;
V_2 -> V_70 . V_117 = F_27 ;
V_2 -> V_70 . V_3 = F_31 ;
V_2 -> V_48 = F_41 ( V_2 -> V_118 ) ;
V_2 -> V_21 = V_30 / V_2 -> V_48 ;
F_42 ( & V_2 -> V_22 ) ;
F_16 ( V_47 ) ;
F_43 ( & V_2 -> V_102 , F_36 ) ;
V_2 -> V_119 = F_44 ( & V_2 -> V_70 , & V_13 -> V_14 ) ;
if ( F_45 ( V_2 -> V_119 ) ) {
V_2 -> V_119 = NULL ;
F_46 ( L_3 ) ;
}
F_38 ( & V_2 -> V_102 , V_103 ) ;
}
void F_47 ( struct V_104 * V_13 )
{
struct V_46 * V_47 = F_40 ( V_13 ) ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
F_48 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_119 )
F_49 ( V_2 -> V_119 ) ;
}
T_1 F_50 ( struct V_1 * V_2 )
{
T_2 V_5 ;
T_6 V_120 = V_2 -> V_17 ;
struct V_121 V_122 ;
V_5 = F_6 ( V_2 -> V_24 + F_5 ( V_120 ) ) ;
if ( V_5 & V_23 ) {
F_4 ( V_2 -> V_34 , V_2 -> V_24 + F_10 ( V_120 ) ) ;
do {
F_4 ( V_5 , V_2 -> V_24 + F_5 ( V_120 ) ) ;
} while ( F_6 ( V_2 -> V_24 + F_5 ( V_120 ) ) & V_23 );
V_2 -> V_34 = ( V_2 -> V_34 + V_2 -> V_19 ) & V_2 -> V_32 . V_33 ;
V_122 . type = V_123 ;
V_121 ( V_2 -> V_119 , & V_122 ) ;
return 1 ;
}
return 0 ;
}
