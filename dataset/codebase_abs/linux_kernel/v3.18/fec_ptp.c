static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_2 V_5 , V_6 ;
int V_7 ;
struct V_8 V_9 ;
T_3 V_10 ;
T_2 V_11 ;
V_5 = 0 ;
if ( ! ( V_2 -> V_12 || V_2 -> V_13 ) ) {
F_2 ( & V_2 -> V_14 -> V_15 , L_1 ) ;
return - V_16 ;
}
if ( V_2 -> V_17 == V_3 )
return 0 ;
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = V_21 ;
V_7 = V_2 -> V_22 ;
F_3 ( & V_2 -> V_23 , V_4 ) ;
if ( V_3 ) {
F_4 ( V_24 , V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
V_5 = F_6 ( V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
do {
V_5 &= ~ ( V_26 ) ;
F_4 ( V_5 , V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
V_5 = F_6 ( V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
} while ( V_5 & V_26 );
F_7 ( & V_2 -> V_27 ) ;
V_6 = F_6 ( V_2 -> V_25 + V_28 ) ;
V_6 |= V_29 ;
F_4 ( V_6 , V_2 -> V_25 + V_28 ) ;
V_6 = F_6 ( V_2 -> V_25 + V_30 ) ;
V_10 = F_8 ( & V_2 -> V_27 , V_6 ) ;
V_9 . V_31 = F_9 ( V_10 , 1000000000ULL , & V_11 ) ;
V_9 . V_32 = V_11 ;
V_5 = V_33 - ( T_2 ) V_9 . V_32 + V_6 ;
V_5 += V_33 ;
V_5 &= V_2 -> V_34 . V_35 ;
F_4 ( V_5 , V_2 -> V_25 + F_10 ( V_2 -> V_18 ) ) ;
V_2 -> V_36 = ( V_5 + V_2 -> V_20 ) & V_2 -> V_34 . V_35 ;
V_5 = F_6 ( V_2 -> V_25 + V_28 ) ;
V_5 |= V_37 ;
F_4 ( V_5 , V_2 -> V_25 + V_28 ) ;
V_5 = F_6 ( V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
V_5 |= ( 1 << V_38 | 1 << V_39 ) ;
V_5 &= ~ ( 1 << V_40 ) ;
V_5 &= ~ ( V_26 ) ;
V_5 |= ( V_41 << V_42 ) ;
F_4 ( V_5 , V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
F_4 ( V_2 -> V_36 , V_2 -> V_25 + F_10 ( V_2 -> V_18 ) ) ;
V_2 -> V_36 = ( V_2 -> V_36 + V_2 -> V_20 ) & V_2 -> V_34 . V_35 ;
} else {
F_4 ( 0 , V_2 -> V_25 + F_5 ( V_2 -> V_18 ) ) ;
}
V_2 -> V_17 = V_3 ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
return 0 ;
}
static T_4 F_12 ( const struct V_43 * V_34 )
{
struct V_1 * V_2 =
F_13 ( V_34 , struct V_1 , V_34 ) ;
const struct V_44 * V_45 =
F_14 ( V_2 -> V_14 ) ;
T_2 V_6 ;
V_6 = F_6 ( V_2 -> V_25 + V_28 ) ;
V_6 |= V_29 ;
F_4 ( V_6 , V_2 -> V_25 + V_28 ) ;
if ( V_45 -> V_46 & V_47 )
F_15 ( 1 ) ;
return F_6 ( V_2 -> V_25 + V_30 ) ;
}
void F_16 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_17 ( V_49 ) ;
unsigned long V_4 ;
int V_7 ;
V_7 = 1000000000 / V_2 -> V_50 ;
F_3 ( & V_2 -> V_23 , V_4 ) ;
F_4 ( V_7 << V_51 , V_2 -> V_25 + V_52 ) ;
F_4 ( V_53 , V_2 -> V_25 + V_54 ) ;
F_4 ( V_55 | V_56 ,
V_2 -> V_25 + V_28 ) ;
memset ( & V_2 -> V_34 , 0 , sizeof( V_2 -> V_34 ) ) ;
V_2 -> V_34 . V_57 = F_12 ;
V_2 -> V_34 . V_35 = F_18 ( 31 ) ;
V_2 -> V_34 . V_58 = 31 ;
V_2 -> V_34 . V_59 = V_60 ;
F_19 ( & V_2 -> V_27 , & V_2 -> V_34 , F_20 ( F_21 () ) ) ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
}
static int F_22 ( struct V_61 * V_62 , T_5 V_63 )
{
unsigned long V_4 ;
int V_64 = 0 ;
T_2 V_65 , V_66 ;
T_2 V_67 , V_68 ;
T_2 V_69 ;
T_3 V_70 , V_71 ;
struct V_1 * V_2 =
F_13 ( V_62 , struct V_1 , V_72 ) ;
if ( V_63 == 0 )
return 0 ;
if ( V_63 < 0 ) {
V_63 = - V_63 ;
V_64 = 1 ;
}
V_70 = V_33 ;
V_71 = ( T_3 ) V_63 * ( T_3 ) V_2 -> V_22 ;
for ( V_65 = 1 ; V_65 <= V_2 -> V_22 ; V_65 ++ ) {
if ( V_70 >= V_71 ) {
V_67 = V_65 ;
V_68 = F_23 ( V_70 , V_71 ) ;
break;
}
V_70 += V_33 ;
}
if ( V_65 > V_2 -> V_22 ) {
V_67 = V_2 -> V_22 ;
V_68 = 1 ;
}
if ( V_64 )
V_69 = V_2 -> V_22 - V_67 ;
else
V_69 = V_2 -> V_22 + V_67 ;
F_3 ( & V_2 -> V_23 , V_4 ) ;
V_66 = F_6 ( V_2 -> V_25 + V_52 ) & V_73 ;
V_66 |= V_69 << V_74 ;
F_4 ( V_66 , V_2 -> V_25 + V_52 ) ;
F_4 ( V_68 , V_2 -> V_25 + V_75 ) ;
F_7 ( & V_2 -> V_27 ) ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_61 * V_62 , T_6 V_76 )
{
struct V_1 * V_2 =
F_13 ( V_62 , struct V_1 , V_72 ) ;
unsigned long V_4 ;
T_3 V_77 ;
T_2 V_78 ;
F_3 ( & V_2 -> V_23 , V_4 ) ;
V_77 = F_7 ( & V_2 -> V_27 ) ;
V_77 += V_76 ;
V_78 = V_77 & V_2 -> V_34 . V_35 ;
F_4 ( V_78 , V_2 -> V_25 + V_30 ) ;
F_19 ( & V_2 -> V_27 , & V_2 -> V_34 , V_77 ) ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_61 * V_62 , struct V_8 * V_9 )
{
struct V_1 * V_79 =
F_13 ( V_62 , struct V_1 , V_72 ) ;
T_3 V_10 ;
T_2 V_11 ;
unsigned long V_4 ;
F_3 ( & V_79 -> V_23 , V_4 ) ;
V_10 = F_7 ( & V_79 -> V_27 ) ;
F_11 ( & V_79 -> V_23 , V_4 ) ;
V_9 -> V_31 = F_9 ( V_10 , 1000000000ULL , & V_11 ) ;
V_9 -> V_32 = V_11 ;
return 0 ;
}
static int F_26 ( struct V_61 * V_62 ,
const struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_13 ( V_62 , struct V_1 , V_72 ) ;
T_3 V_10 ;
unsigned long V_4 ;
T_2 V_78 ;
F_27 ( & V_2 -> V_80 ) ;
if ( ! V_2 -> V_81 ) {
F_28 ( & V_2 -> V_80 ) ;
return - V_16 ;
}
V_10 = V_9 -> V_31 * 1000000000ULL ;
V_10 += V_9 -> V_32 ;
V_78 = V_10 & V_2 -> V_34 . V_35 ;
F_3 ( & V_2 -> V_23 , V_4 ) ;
F_4 ( V_78 , V_2 -> V_25 + V_30 ) ;
F_19 ( & V_2 -> V_27 , & V_2 -> V_34 , V_10 ) ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
F_28 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_29 ( struct V_61 * V_62 ,
struct V_82 * V_83 , int V_84 )
{
struct V_1 * V_2 =
F_13 ( V_62 , struct V_1 , V_72 ) ;
int V_85 = 0 ;
if ( V_83 -> type == V_86 ) {
V_85 = F_1 ( V_2 , V_84 ) ;
return V_85 ;
}
return - V_87 ;
}
int F_30 ( struct V_48 * V_49 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_17 ( V_49 ) ;
struct V_90 V_91 ;
if ( F_31 ( & V_91 , V_89 -> V_92 , sizeof( V_91 ) ) )
return - V_93 ;
if ( V_91 . V_4 )
return - V_16 ;
switch ( V_91 . V_94 ) {
case V_95 :
V_2 -> V_12 = 0 ;
break;
case V_96 :
V_2 -> V_12 = 1 ;
break;
default:
return - V_97 ;
}
switch ( V_91 . V_98 ) {
case V_99 :
if ( V_2 -> V_13 )
V_2 -> V_13 = 0 ;
V_91 . V_98 = V_99 ;
break;
default:
V_2 -> V_13 = 1 ;
V_91 . V_98 = V_100 ;
break;
}
return F_32 ( V_89 -> V_92 , & V_91 , sizeof( V_91 ) ) ?
- V_93 : 0 ;
}
int F_33 ( struct V_48 * V_49 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_17 ( V_49 ) ;
struct V_90 V_91 ;
V_91 . V_4 = 0 ;
V_91 . V_94 = V_2 -> V_12 ? V_96 : V_95 ;
V_91 . V_98 = ( V_2 -> V_13 ?
V_100 : V_99 ) ;
return F_32 ( V_89 -> V_92 , & V_91 , sizeof( V_91 ) ) ?
- V_93 : 0 ;
}
static void F_34 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = F_35 ( V_102 ) ;
struct V_1 * V_2 = F_13 ( V_104 , struct V_1 , V_105 ) ;
T_3 V_10 ;
unsigned long V_4 ;
F_27 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_81 ) {
F_3 ( & V_2 -> V_23 , V_4 ) ;
V_10 = F_7 ( & V_2 -> V_27 ) ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
}
F_28 ( & V_2 -> V_80 ) ;
F_36 ( & V_2 -> V_105 , V_106 ) ;
}
void F_37 ( struct V_107 * V_14 )
{
struct V_48 * V_49 = F_38 ( V_14 ) ;
struct V_1 * V_2 = F_17 ( V_49 ) ;
V_2 -> V_72 . V_108 = V_109 ;
snprintf ( V_2 -> V_72 . V_110 , 16 , L_2 ) ;
V_2 -> V_72 . V_111 = 250000000 ;
V_2 -> V_72 . V_112 = 0 ;
V_2 -> V_72 . V_113 = 0 ;
V_2 -> V_72 . V_114 = 0 ;
V_2 -> V_72 . V_115 = 0 ;
V_2 -> V_72 . V_116 = 1 ;
V_2 -> V_72 . V_117 = F_22 ;
V_2 -> V_72 . V_118 = F_24 ;
V_2 -> V_72 . V_119 = F_25 ;
V_2 -> V_72 . V_120 = F_26 ;
V_2 -> V_72 . V_3 = F_29 ;
V_2 -> V_50 = F_39 ( V_2 -> V_121 ) ;
V_2 -> V_22 = V_33 / V_2 -> V_50 ;
F_40 ( & V_2 -> V_23 ) ;
F_16 ( V_49 ) ;
F_41 ( & V_2 -> V_105 , F_34 ) ;
V_2 -> V_122 = F_42 ( & V_2 -> V_72 , & V_14 -> V_15 ) ;
if ( F_43 ( V_2 -> V_122 ) ) {
V_2 -> V_122 = NULL ;
F_44 ( L_3 ) ;
}
F_36 ( & V_2 -> V_105 , V_106 ) ;
}
T_1 F_45 ( struct V_1 * V_2 )
{
T_2 V_5 ;
T_7 V_123 = V_2 -> V_18 ;
struct V_124 V_125 ;
V_5 = F_6 ( V_2 -> V_25 + F_5 ( V_123 ) ) ;
if ( V_5 & V_24 ) {
F_4 ( V_2 -> V_36 , V_2 -> V_25 + F_10 ( V_123 ) ) ;
do {
F_4 ( V_5 , V_2 -> V_25 + F_5 ( V_123 ) ) ;
} while ( F_6 ( V_2 -> V_25 + F_5 ( V_123 ) ) & V_24 );
V_2 -> V_36 = ( V_2 -> V_36 + V_2 -> V_20 ) & V_2 -> V_34 . V_35 ;
V_125 . type = V_126 ;
V_124 ( V_2 -> V_122 , & V_125 ) ;
return 1 ;
}
return 0 ;
}
