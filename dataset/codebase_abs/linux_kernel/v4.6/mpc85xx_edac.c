static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_11 +
V_12 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_11 +
V_13 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_11 + V_14 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_11 + V_12 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_11 + V_13 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_11 + V_14 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static void F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_9 = V_17 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_20 + V_21 ) ;
if ( ! ( V_19 & ~ ( V_22 | V_23 ) ) ) {
F_7 ( V_9 -> V_20 + V_21 , V_19 ) ;
return;
}
F_12 ( V_24 L_2 ) ;
F_12 ( V_24 L_3 , V_19 ) ;
F_12 ( V_24 L_4 ,
F_3 ( V_9 -> V_20 + V_25 ) ) ;
F_12 ( V_24 L_5 ,
F_3 ( V_9 -> V_20 + V_26 ) ) ;
F_12 ( V_24 L_6 ,
F_3 ( V_9 -> V_20 + V_27 ) ) ;
F_12 ( V_24 L_7 ,
F_3 ( V_9 -> V_20 + V_28 ) ) ;
F_12 ( V_24 L_8 ,
F_3 ( V_9 -> V_20 + V_29 ) ) ;
F_7 ( V_9 -> V_20 + V_21 , V_19 ) ;
if ( V_19 & V_30 )
F_13 ( V_17 , V_17 -> V_31 ) ;
if ( ( V_19 & ~ V_22 ) & ~ V_30 )
F_14 ( V_17 , V_17 -> V_31 ) ;
}
static void F_15 ( struct V_16 * V_17 )
{
struct V_18 * V_9 = V_17 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_20 + V_21 ) ;
F_16 ( L_9 ) ;
F_16 ( L_10 , V_19 ) ;
F_16 ( L_11 ,
F_3 ( V_9 -> V_20 + V_32 ) ) ;
F_16 ( L_12 ,
F_3 ( V_9 -> V_20 + V_33 ) ) ;
F_16 ( L_13 ,
F_3 ( V_9 -> V_20 + V_34 ) ) ;
F_16 ( L_14 ,
F_3 ( V_9 -> V_20 + V_35 ) ) ;
F_16 ( L_15 ,
F_3 ( V_9 -> V_20 + V_36 ) ) ;
F_7 ( V_9 -> V_20 + V_21 , V_19 ) ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
if ( ! V_38 )
return - V_41 ;
V_40 = F_18 ( V_38 ) ;
return F_19 ( V_40 , 0 , 0 , V_42 ) ;
}
static T_4 F_20 ( int V_43 , void * V_44 )
{
struct V_16 * V_17 = V_44 ;
struct V_18 * V_9 = V_17 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_20 + V_21 ) ;
if ( ! V_19 )
return V_45 ;
if ( V_9 -> V_46 )
F_15 ( V_17 ) ;
else
F_11 ( V_17 ) ;
return V_47 ;
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_16 * V_17 ;
struct V_18 * V_9 ;
struct V_50 * V_51 ;
struct V_37 * V_52 ;
struct V_53 V_54 ;
int V_55 = 0 ;
if ( ! F_22 ( & V_49 -> V_2 , F_21 , V_56 ) )
return - V_57 ;
V_17 = F_23 ( sizeof( * V_9 ) , L_16 ) ;
if ( ! V_17 )
return - V_57 ;
switch ( V_58 ) {
case V_59 :
case V_60 :
break;
default:
V_58 = V_60 ;
break;
}
V_9 = V_17 -> V_10 ;
V_9 -> V_61 = L_16 ;
V_9 -> V_43 = V_62 ;
V_51 = V_49 -> V_2 . V_63 ;
if ( ! V_51 ) {
F_24 ( & V_49 -> V_2 , L_17 ) ;
V_55 = - V_64 ;
goto V_65;
}
V_52 = V_51 -> V_52 ;
if ( F_17 ( V_52 ) > 0 )
V_9 -> V_46 = true ;
F_25 ( & V_49 -> V_2 , V_17 ) ;
V_17 -> V_2 = & V_49 -> V_2 ;
V_17 -> V_66 = V_67 ;
V_17 -> V_31 = V_9 -> V_61 ;
V_17 -> V_68 = V_68 ( & V_49 -> V_2 ) ;
if ( V_58 == V_59 ) {
if ( V_9 -> V_46 )
V_17 -> V_69 = F_15 ;
else
V_17 -> V_69 = F_11 ;
}
V_9 -> V_70 = V_71 ++ ;
V_55 = F_26 ( V_52 , 0 , & V_54 ) ;
if ( V_55 ) {
F_12 ( V_24 L_18
L_19 , V_72 ) ;
goto V_65;
}
V_54 . V_73 += 0xe00 ;
if ( ! F_27 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ,
V_9 -> V_61 ) ) {
F_12 ( V_24 L_20 ,
V_72 ) ;
V_55 = - V_74 ;
goto V_65;
}
V_9 -> V_20 = F_29 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ) ;
if ( ! V_9 -> V_20 ) {
F_12 ( V_24 L_21 , V_72 ) ;
V_55 = - V_57 ;
goto V_65;
}
if ( V_9 -> V_46 ) {
V_75 =
F_3 ( V_9 -> V_20 + V_26 ) ;
F_7 ( V_9 -> V_20 + V_26 , ~ 0 ) ;
V_76 =
F_3 ( V_9 -> V_20 + V_77 ) ;
F_7 ( V_9 -> V_20 + V_77 , 0 ) ;
} else {
V_75 =
F_3 ( V_9 -> V_20 + V_78 ) ;
F_7 ( V_9 -> V_20 + V_78 , 0x40 ) ;
V_76 =
F_3 ( V_9 -> V_20 + V_77 ) ;
F_7 ( V_9 -> V_20 + V_77 , ~ 0x40 ) ;
}
F_7 ( V_9 -> V_20 + V_21 , ~ 0 ) ;
if ( F_30 ( V_17 , V_9 -> V_70 ) > 0 ) {
F_31 ( 3 , L_22 ) ;
goto V_65;
}
if ( V_58 == V_60 ) {
V_9 -> V_43 = F_32 ( V_52 , 0 ) ;
V_55 = F_33 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_20 ,
V_79 ,
L_23 , V_17 ) ;
if ( V_55 < 0 ) {
F_12 ( V_24
L_24
L_25 , V_72 , V_9 -> V_43 ) ;
F_34 ( V_9 -> V_43 ) ;
V_55 = - V_80 ;
goto V_81;
}
F_12 (KERN_INFO EDAC_MOD_STR L_26 ,
pdata->irq) ;
}
if ( V_9 -> V_46 ) {
F_7 ( V_9 -> V_20 + V_77 , ~ 0
& ~ V_82 ) ;
F_7 ( V_9 -> V_20 + V_26 , 0
| V_83 ) ;
}
F_35 ( & V_49 -> V_2 , F_21 ) ;
F_31 ( 3 , L_27 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_28 ) ;
return 0 ;
V_81:
F_36 ( & V_49 -> V_2 ) ;
V_65:
F_37 ( V_17 ) ;
F_38 ( & V_49 -> V_2 , F_21 ) ;
return V_55 ;
}
static T_1 F_39 ( struct V_84
* V_85 , char * V_5 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_87 + V_88 ) ) ;
}
static T_1 F_40 ( struct V_84
* V_85 , char * V_5 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_87 + V_89 ) ) ;
}
static T_1 F_41 ( struct V_84
* V_85 , char * V_5 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_87 + V_90 ) ) ;
}
static T_1 F_42 ( struct V_84
* V_85 , const char * V_5 ,
T_2 V_15 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_87 + V_88 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_84
* V_85 , const char * V_5 ,
T_2 V_15 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_87 + V_89 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_44 ( struct V_84
* V_85 , const char * V_5 ,
T_2 V_15 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_87 + V_90 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static void F_45 ( struct V_84
* V_85 )
{
V_85 -> V_91 = V_92 ;
}
static void F_46 ( struct V_84 * V_85 )
{
struct V_86 * V_9 = V_85 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_87 + V_93 ) ;
if ( ! ( V_19 & V_94 ) )
return;
F_12 ( V_24 L_29 ) ;
F_12 ( V_24 L_30 , V_19 ) ;
F_12 ( V_24 L_31 ,
F_3 ( V_9 -> V_87 + V_95 ) ) ;
F_12 ( V_24 L_32 ,
F_3 ( V_9 -> V_87 + V_96 ) ) ;
F_12 ( V_24 L_33 ,
F_3 ( V_9 -> V_87 + V_97 ) ) ;
F_12 ( V_24 L_34 ,
F_3 ( V_9 -> V_87 + V_98 ) ) ;
F_12 ( V_24 L_35 ,
F_3 ( V_9 -> V_87 + V_99 ) ) ;
F_7 ( V_9 -> V_87 + V_93 , V_19 ) ;
if ( V_19 & V_100 )
F_47 ( V_85 , 0 , 0 , V_85 -> V_31 ) ;
if ( V_19 & V_101 )
F_48 ( V_85 , 0 , 0 , V_85 -> V_31 ) ;
}
static T_4 F_49 ( int V_43 , void * V_44 )
{
struct V_84 * V_85 = V_44 ;
struct V_86 * V_9 = V_85 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_87 + V_93 ) ;
if ( ! ( V_19 & V_94 ) )
return V_45 ;
F_46 ( V_85 ) ;
return V_47 ;
}
static int F_50 ( struct V_48 * V_49 )
{
struct V_84 * V_85 ;
struct V_86 * V_9 ;
struct V_53 V_54 ;
int V_55 ;
if ( ! F_22 ( & V_49 -> V_2 , F_50 , V_56 ) )
return - V_57 ;
V_85 = F_51 ( sizeof( * V_9 ) ,
L_36 , 1 , L_37 , 1 , 2 , NULL , 0 ,
V_102 ) ;
if ( ! V_85 ) {
F_38 ( & V_49 -> V_2 , F_50 ) ;
return - V_57 ;
}
V_9 = V_85 -> V_10 ;
V_9 -> V_61 = L_38 ;
V_9 -> V_43 = V_62 ;
V_85 -> V_2 = & V_49 -> V_2 ;
F_25 ( V_85 -> V_2 , V_85 ) ;
V_85 -> V_31 = V_9 -> V_61 ;
V_85 -> V_68 = V_9 -> V_61 ;
V_55 = F_26 ( V_49 -> V_2 . V_52 , 0 , & V_54 ) ;
if ( V_55 ) {
F_12 ( V_24 L_18
L_39 , V_72 ) ;
goto V_65;
}
V_54 . V_73 += 0xe00 ;
if ( ! F_27 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ,
V_9 -> V_61 ) ) {
F_12 ( V_24 L_20 ,
V_72 ) ;
V_55 = - V_74 ;
goto V_65;
}
V_9 -> V_87 = F_29 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ) ;
if ( ! V_9 -> V_87 ) {
F_12 ( V_24 L_40 , V_72 ) ;
V_55 = - V_57 ;
goto V_65;
}
F_7 ( V_9 -> V_87 + V_93 , ~ 0 ) ;
V_103 = F_3 ( V_9 -> V_87 + V_104 ) ;
F_7 ( V_9 -> V_87 + V_104 , 0 ) ;
V_85 -> V_66 = V_67 ;
if ( V_58 == V_59 )
V_85 -> V_69 = F_46 ;
F_45 ( V_85 ) ;
V_9 -> V_70 = V_102 ++ ;
if ( F_52 ( V_85 ) > 0 ) {
F_31 ( 3 , L_41 ) ;
goto V_65;
}
if ( V_58 == V_60 ) {
V_9 -> V_43 = F_32 ( V_49 -> V_2 . V_52 , 0 ) ;
V_55 = F_33 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_49 , V_79 ,
L_42 , V_85 ) ;
if ( V_55 < 0 ) {
F_12 ( V_24
L_24
L_43 , V_72 , V_9 -> V_43 ) ;
F_34 ( V_9 -> V_43 ) ;
V_55 = - V_80 ;
goto V_81;
}
F_12 (KERN_INFO EDAC_MOD_STR L_44 ,
pdata->irq) ;
V_85 -> V_105 = V_106 ;
F_7 ( V_9 -> V_87 + V_107 , V_108 ) ;
}
F_35 ( & V_49 -> V_2 , F_50 ) ;
F_31 ( 3 , L_27 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_45 ) ;
return 0 ;
V_81:
F_53 ( & V_49 -> V_2 ) ;
V_65:
F_38 ( & V_49 -> V_2 , F_50 ) ;
F_54 ( V_85 ) ;
return V_55 ;
}
static int F_55 ( struct V_48 * V_49 )
{
struct V_84 * V_85 = F_56 ( & V_49 -> V_2 ) ;
struct V_86 * V_9 = V_85 -> V_10 ;
F_31 ( 0 , L_46 ) ;
if ( V_58 == V_60 ) {
F_7 ( V_9 -> V_87 + V_107 , 0 ) ;
F_34 ( V_9 -> V_43 ) ;
}
F_7 ( V_9 -> V_87 + V_104 , V_103 ) ;
F_53 ( & V_49 -> V_2 ) ;
F_54 ( V_85 ) ;
return 0 ;
}
static T_5 F_57 ( T_3 V_109 , T_3 V_110 )
{
T_3 V_111 ;
T_3 V_112 ;
int V_113 ;
T_5 V_114 = 0 ;
int V_115 ;
int V_116 ;
for ( V_115 = 0 ; V_115 < 8 ; V_115 ++ ) {
V_112 = V_117 [ V_115 * 2 ] ;
V_111 = V_117 [ V_115 * 2 + 1 ] ;
V_113 = 0 ;
for ( V_116 = 0 ; V_116 < 32 ; V_116 ++ ) {
if ( ( V_112 >> V_116 ) & 1 )
V_113 ^= ( V_109 >> V_116 ) & 1 ;
if ( ( V_111 >> V_116 ) & 1 )
V_113 ^= ( V_110 >> V_116 ) & 1 ;
}
V_114 |= V_113 << V_115 ;
}
return V_114 ;
}
static T_5 F_58 ( unsigned int V_118 ) {
int V_115 ;
T_5 V_119 = 0 ;
for ( V_115 = V_118 < 32 ; V_115 < 16 ; V_115 += 2 )
V_119 |= ( ( V_117 [ V_115 ] >> ( V_118 % 32 ) ) & 1 ) << ( V_115 / 2 ) ;
return V_119 ;
}
static void F_59 ( T_3 V_120 , T_3 V_121 , T_3 V_122 ,
int * V_123 , int * V_124 )
{
int V_115 ;
T_5 V_119 ;
* V_123 = - 1 ;
* V_124 = - 1 ;
V_119 = F_57 ( V_120 , V_121 ) ^ V_122 ;
for ( V_115 = 0 ; V_115 < 64 ; V_115 ++ ) {
if ( V_119 == F_58 ( V_115 ) ) {
* V_123 = V_115 ;
return;
}
}
for ( V_115 = 0 ; V_115 < 8 ; V_115 ++ ) {
if ( ( V_119 >> V_115 ) & 0x1 ) {
* V_124 = V_115 ;
return;
}
}
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_125 * V_126 ;
T_3 V_127 ;
T_3 V_19 ;
T_3 V_119 ;
T_6 V_128 ;
T_3 V_129 ;
int V_130 ;
T_3 V_120 ;
T_3 V_121 ;
int V_123 ;
int V_124 ;
V_19 = F_3 ( V_9 -> V_11 + V_131 ) ;
if ( ! V_19 )
return;
F_61 ( V_7 , V_24 , L_47 ,
V_19 ) ;
if ( ! ( V_19 & ( V_132 | V_133 ) ) ) {
F_7 ( V_9 -> V_11 + V_131 , V_19 ) ;
return;
}
V_119 = F_3 ( V_9 -> V_11 + V_134 ) ;
V_127 = ( F_3 ( V_9 -> V_11 + V_135 ) &
V_136 ) ? 32 : 64 ;
if ( V_127 == 64 )
V_119 &= 0xff ;
else
V_119 &= 0xffff ;
V_128 = F_62 (
F_3 ( V_9 -> V_11 + V_137 ) ,
F_3 ( V_9 -> V_11 + V_138 ) ) ;
V_129 = V_128 >> V_139 ;
for ( V_130 = 0 ; V_130 < V_7 -> V_140 ; V_130 ++ ) {
V_126 = V_7 -> V_141 [ V_130 ] ;
if ( ( V_129 >= V_126 -> V_142 ) && ( V_129 <= V_126 -> V_143 ) )
break;
}
V_120 = F_3 ( V_9 -> V_11 + V_144 ) ;
V_121 = F_3 ( V_9 -> V_11 + V_145 ) ;
if ( ( V_19 & V_132 ) && ( V_127 == 64 ) ) {
F_59 ( V_120 , V_121 , V_119 ,
& V_123 , & V_124 ) ;
if ( V_123 != - 1 )
F_61 ( V_7 , V_24 ,
L_48 , V_123 ) ;
if ( V_124 != - 1 )
F_61 ( V_7 , V_24 ,
L_49 , V_124 ) ;
F_61 ( V_7 , V_24 ,
L_50 ,
V_120 ^ ( 1 << ( V_123 - 32 ) ) ,
V_121 ^ ( 1 << V_123 ) ,
V_119 ^ ( 1 << V_124 ) ) ;
}
F_61 ( V_7 , V_24 ,
L_51 ,
V_120 , V_121 , V_119 ) ;
F_61 ( V_7 , V_24 , L_52 , V_128 ) ;
F_61 ( V_7 , V_24 , L_53 , V_129 ) ;
if ( V_130 == V_7 -> V_140 )
F_61 ( V_7 , V_24 , L_54 ) ;
if ( V_19 & V_132 )
F_63 ( V_146 , V_7 , 1 ,
V_129 , V_128 & ~ V_147 , V_119 ,
V_130 , 0 , - 1 ,
V_7 -> V_31 , L_55 ) ;
if ( V_19 & V_133 )
F_63 ( V_148 , V_7 , 1 ,
V_129 , V_128 & ~ V_147 , V_119 ,
V_130 , 0 , - 1 ,
V_7 -> V_31 , L_55 ) ;
F_7 ( V_9 -> V_11 + V_131 , V_19 ) ;
}
static T_4 F_64 ( int V_43 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_11 + V_131 ) ;
if ( ! V_19 )
return V_45 ;
F_60 ( V_7 ) ;
return V_47 ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_125 * V_126 ;
struct V_149 * V_150 ;
T_3 V_151 ;
T_3 V_152 ;
enum V_153 V_154 ;
T_3 V_155 ;
int V_156 ;
V_151 = F_3 ( V_9 -> V_11 + V_135 ) ;
V_152 = V_151 & V_157 ;
if ( V_151 & V_158 ) {
switch ( V_152 ) {
case V_159 :
V_154 = V_160 ;
break;
case V_161 :
V_154 = V_162 ;
break;
case V_163 :
V_154 = V_164 ;
break;
default:
V_154 = V_165 ;
break;
}
} else {
switch ( V_152 ) {
case V_159 :
V_154 = V_166 ;
break;
case V_161 :
V_154 = V_167 ;
break;
case V_163 :
V_154 = V_168 ;
break;
default:
V_154 = V_165 ;
break;
}
}
for ( V_156 = 0 ; V_156 < V_7 -> V_140 ; V_156 ++ ) {
T_3 V_73 ;
T_3 V_169 ;
V_126 = V_7 -> V_141 [ V_156 ] ;
V_150 = V_126 -> V_170 [ 0 ] -> V_150 ;
V_155 = F_3 ( V_9 -> V_11 + V_171 +
( V_156 * V_172 ) ) ;
V_73 = ( V_155 & 0xffff0000 ) >> 16 ;
V_169 = ( V_155 & 0x0000ffff ) ;
if ( V_73 == V_169 )
continue;
V_73 <<= ( 24 - V_139 ) ;
V_169 <<= ( 24 - V_139 ) ;
V_169 |= ( 1 << ( 24 - V_139 ) ) - 1 ;
V_126 -> V_142 = V_73 ;
V_126 -> V_143 = V_169 ;
V_150 -> V_173 = V_169 + 1 - V_73 ;
V_150 -> V_174 = 8 ;
V_150 -> V_154 = V_154 ;
V_150 -> V_175 = V_176 ;
if ( V_151 & V_177 )
V_150 -> V_175 = V_178 ;
V_150 -> V_179 = V_180 ;
}
}
static int F_66 ( struct V_48 * V_49 )
{
struct V_6 * V_7 ;
struct V_181 V_182 [ 2 ] ;
struct V_8 * V_9 ;
struct V_53 V_54 ;
T_3 V_151 ;
int V_55 ;
if ( ! F_22 ( & V_49 -> V_2 , F_66 , V_56 ) )
return - V_57 ;
V_182 [ 0 ] . type = V_183 ;
V_182 [ 0 ] . V_184 = 4 ;
V_182 [ 0 ] . V_185 = true ;
V_182 [ 1 ] . type = V_186 ;
V_182 [ 1 ] . V_184 = 1 ;
V_182 [ 1 ] . V_185 = false ;
V_7 = F_67 ( V_187 , F_68 ( V_182 ) , V_182 ,
sizeof( * V_9 ) ) ;
if ( ! V_7 ) {
F_38 ( & V_49 -> V_2 , F_66 ) ;
return - V_57 ;
}
V_9 = V_7 -> V_10 ;
V_9 -> V_61 = L_56 ;
V_9 -> V_43 = V_62 ;
V_7 -> V_188 = & V_49 -> V_2 ;
V_9 -> V_70 = V_187 ++ ;
F_25 ( V_7 -> V_188 , V_7 ) ;
V_7 -> V_31 = V_9 -> V_61 ;
V_7 -> V_68 = V_9 -> V_61 ;
V_55 = F_26 ( V_49 -> V_2 . V_52 , 0 , & V_54 ) ;
if ( V_55 ) {
F_12 ( V_24 L_57 ,
V_72 ) ;
goto V_65;
}
if ( ! F_27 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ,
V_9 -> V_61 ) ) {
F_12 ( V_24 L_20 ,
V_72 ) ;
V_55 = - V_74 ;
goto V_65;
}
V_9 -> V_11 = F_29 ( & V_49 -> V_2 , V_54 . V_73 , F_28 ( & V_54 ) ) ;
if ( ! V_9 -> V_11 ) {
F_12 ( V_24 L_58 , V_72 ) ;
V_55 = - V_57 ;
goto V_65;
}
V_151 = F_3 ( V_9 -> V_11 + V_135 ) ;
if ( ! ( V_151 & V_189 ) ) {
F_12 ( V_190 L_59 , V_72 ) ;
V_55 = - V_80 ;
goto V_65;
}
F_31 ( 3 , L_60 ) ;
V_7 -> V_191 = V_192 | V_193 |
V_194 | V_195 ;
V_7 -> V_196 = V_197 | V_198 ;
V_7 -> V_199 = V_198 ;
V_7 -> V_66 = V_67 ;
V_7 -> V_200 = V_201 ;
if ( V_58 == V_59 )
V_7 -> V_69 = F_60 ;
V_7 -> V_202 = NULL ;
V_7 -> V_203 = V_204 ;
F_65 ( V_7 ) ;
V_205 =
F_3 ( V_9 -> V_11 + V_206 ) ;
F_7 ( V_9 -> V_11 + V_206 , 0 ) ;
F_7 ( V_9 -> V_11 + V_131 , ~ 0 ) ;
if ( F_69 ( V_7 , V_207 ) ) {
F_31 ( 3 , L_61 ) ;
goto V_65;
}
if ( V_58 == V_60 ) {
F_7 ( V_9 -> V_11 + V_208 ,
V_209 | V_210 ) ;
V_211 = F_3 ( V_9 -> V_11 +
V_212 ) & 0xff0000 ;
F_7 ( V_9 -> V_11 + V_212 , 0x10000 ) ;
V_9 -> V_43 = F_32 ( V_49 -> V_2 . V_52 , 0 ) ;
V_55 = F_33 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_64 ,
V_79 ,
L_62 , V_7 ) ;
if ( V_55 < 0 ) {
F_12 ( V_24 L_24
L_63 , V_72 , V_9 -> V_43 ) ;
F_34 ( V_9 -> V_43 ) ;
V_55 = - V_80 ;
goto V_81;
}
F_12 (KERN_INFO EDAC_MOD_STR L_64 ,
pdata->irq) ;
}
F_35 ( & V_49 -> V_2 , F_66 ) ;
F_31 ( 3 , L_27 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_65 ) ;
return 0 ;
V_81:
F_70 ( & V_49 -> V_2 ) ;
V_65:
F_38 ( & V_49 -> V_2 , F_66 ) ;
F_71 ( V_7 ) ;
return V_55 ;
}
static int F_72 ( struct V_48 * V_49 )
{
struct V_6 * V_7 = F_56 ( & V_49 -> V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_31 ( 0 , L_46 ) ;
if ( V_58 == V_60 ) {
F_7 ( V_9 -> V_11 + V_208 , 0 ) ;
F_34 ( V_9 -> V_43 ) ;
}
F_7 ( V_9 -> V_11 + V_206 ,
V_205 ) ;
F_7 ( V_9 -> V_11 + V_212 , V_211 ) ;
F_70 ( & V_49 -> V_2 ) ;
F_71 ( V_7 ) ;
return 0 ;
}
static void T_7 F_73 ( void * V_5 )
{
V_213 [ F_74 () ] = F_75 ( V_214 ) ;
F_76 ( V_214 , ( V_213 [ F_74 () ] & ~ V_215 ) ) ;
}
static int T_7 F_77 ( void )
{
int V_55 = 0 ;
T_3 T_8 V_216 = 0 ;
F_12 ( V_217 L_66
L_67 ) ;
switch ( V_58 ) {
case V_59 :
case V_60 :
break;
default:
V_58 = V_60 ;
break;
}
V_55 = F_78 ( V_218 , F_68 ( V_218 ) ) ;
if ( V_55 )
F_12 (KERN_WARNING EDAC_MOD_STR L_68 ) ;
#ifdef F_79
V_216 = F_75 ( V_219 ) ;
if ( ( F_80 ( V_216 ) == V_220 ) ||
( F_80 ( V_216 ) == V_221 ) ) {
if ( V_58 == V_60 )
F_81 ( F_73 , NULL , 0 ) ;
}
#endif
return 0 ;
}
static void T_9 F_82 ( void * V_5 )
{
F_76 ( V_214 , V_213 [ F_74 () ] ) ;
}
static void T_9 F_83 ( void )
{
#ifdef F_79
T_3 V_216 = F_75 ( V_219 ) ;
if ( ( F_80 ( V_216 ) == V_220 ) ||
( F_80 ( V_216 ) == V_221 ) ) {
F_81 ( F_82 , NULL , 0 ) ;
}
#endif
F_84 ( V_218 , F_68 ( V_218 ) ) ;
}
