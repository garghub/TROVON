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
static int F_11 ( struct V_6 * V_7 )
{
int V_16 ;
V_16 = F_12 ( & V_7 -> V_2 , & V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_12 ( & V_7 -> V_2 , & V_18 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_12 ( & V_7 -> V_2 , & V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_14 ( & V_7 -> V_2 , & V_17 ) ;
F_14 ( & V_7 -> V_2 , & V_18 ) ;
F_14 ( & V_7 -> V_2 , & V_19 ) ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_9 = V_21 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_24 + V_25 ) ;
if ( ! ( V_23 & ~ ( V_26 | V_27 ) ) ) {
F_7 ( V_9 -> V_24 + V_25 , V_23 ) ;
return;
}
F_16 ( V_28 L_2 ) ;
F_16 ( V_28 L_3 , V_23 ) ;
F_16 ( V_28 L_4 ,
F_3 ( V_9 -> V_24 + V_29 ) ) ;
F_16 ( V_28 L_5 ,
F_3 ( V_9 -> V_24 + V_30 ) ) ;
F_16 ( V_28 L_6 ,
F_3 ( V_9 -> V_24 + V_31 ) ) ;
F_16 ( V_28 L_7 ,
F_3 ( V_9 -> V_24 + V_32 ) ) ;
F_16 ( V_28 L_8 ,
F_3 ( V_9 -> V_24 + V_33 ) ) ;
F_7 ( V_9 -> V_24 + V_25 , V_23 ) ;
if ( V_23 & V_34 )
F_17 ( V_21 , V_21 -> V_35 ) ;
if ( ( V_23 & ~ V_26 ) & ~ V_34 )
F_18 ( V_21 , V_21 -> V_35 ) ;
}
static void F_19 ( struct V_20 * V_21 )
{
struct V_22 * V_9 = V_21 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_24 + V_25 ) ;
F_20 ( L_9 ) ;
F_20 ( L_10 , V_23 ) ;
F_20 ( L_11 ,
F_3 ( V_9 -> V_24 + V_36 ) ) ;
F_20 ( L_12 ,
F_3 ( V_9 -> V_24 + V_37 ) ) ;
F_20 ( L_13 ,
F_3 ( V_9 -> V_24 + V_38 ) ) ;
F_20 ( L_14 ,
F_3 ( V_9 -> V_24 + V_39 ) ) ;
F_20 ( L_15 ,
F_3 ( V_9 -> V_24 + V_40 ) ) ;
F_7 ( V_9 -> V_24 + V_25 , V_23 ) ;
}
static int F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
if ( ! V_42 )
return - V_45 ;
V_44 = F_22 ( V_42 ) ;
return F_23 ( V_44 , 0 , 0 , V_46 ) ;
}
static T_4 F_24 ( int V_47 , void * V_48 )
{
struct V_20 * V_21 = V_48 ;
struct V_22 * V_9 = V_21 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_24 + V_25 ) ;
if ( ! V_23 )
return V_49 ;
if ( V_9 -> V_50 )
F_19 ( V_21 ) ;
else
F_15 ( V_21 ) ;
return V_51 ;
}
int F_25 ( struct V_52 * V_53 )
{
struct V_20 * V_21 ;
struct V_22 * V_9 ;
struct V_54 V_55 ;
int V_56 = 0 ;
if ( ! F_26 ( & V_53 -> V_2 , F_25 , V_57 ) )
return - V_58 ;
V_21 = F_27 ( sizeof( * V_9 ) , L_16 ) ;
if ( ! V_21 )
return - V_58 ;
switch ( V_59 ) {
case V_60 :
case V_61 :
break;
default:
V_59 = V_61 ;
break;
}
V_9 = V_21 -> V_10 ;
V_9 -> V_62 = L_16 ;
V_9 -> V_47 = V_63 ;
if ( F_21 ( V_53 -> V_2 . V_64 ) > 0 )
V_9 -> V_50 = true ;
F_28 ( & V_53 -> V_2 , V_21 ) ;
V_21 -> V_2 = & V_53 -> V_2 ;
V_21 -> V_65 = V_66 ;
V_21 -> V_35 = V_9 -> V_62 ;
V_21 -> V_67 = V_67 ( & V_53 -> V_2 ) ;
if ( V_59 == V_60 ) {
if ( V_9 -> V_50 )
V_21 -> V_68 = F_19 ;
else
V_21 -> V_68 = F_15 ;
}
V_9 -> V_69 = V_70 ++ ;
V_56 = F_29 ( V_53 -> V_2 . V_64 , 0 , & V_55 ) ;
if ( V_56 ) {
F_16 ( V_28 L_17
L_18 , V_71 ) ;
goto V_72;
}
V_55 . V_73 += 0xe00 ;
if ( ! F_30 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ,
V_9 -> V_62 ) ) {
F_16 ( V_28 L_19 ,
V_71 ) ;
V_56 = - V_74 ;
goto V_72;
}
V_9 -> V_24 = F_32 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ) ;
if ( ! V_9 -> V_24 ) {
F_16 ( V_28 L_20 , V_71 ) ;
V_56 = - V_58 ;
goto V_72;
}
if ( V_9 -> V_50 ) {
V_75 =
F_3 ( V_9 -> V_24 + V_30 ) ;
F_7 ( V_9 -> V_24 + V_30 , ~ 0 ) ;
V_76 =
F_3 ( V_9 -> V_24 + V_77 ) ;
F_7 ( V_9 -> V_24 + V_77 , 0 ) ;
} else {
V_75 =
F_3 ( V_9 -> V_24 + V_78 ) ;
F_7 ( V_9 -> V_24 + V_78 , 0x40 ) ;
V_76 =
F_3 ( V_9 -> V_24 + V_77 ) ;
F_7 ( V_9 -> V_24 + V_77 , ~ 0x40 ) ;
}
F_7 ( V_9 -> V_24 + V_25 , ~ 0 ) ;
if ( F_33 ( V_21 , V_9 -> V_69 ) > 0 ) {
F_34 ( 3 , L_21 ) ;
goto V_72;
}
if ( V_59 == V_61 ) {
V_9 -> V_47 = F_35 ( V_53 -> V_2 . V_64 , 0 ) ;
V_56 = F_36 ( & V_53 -> V_2 , V_9 -> V_47 ,
F_24 ,
V_79 | V_80 ,
L_22 , V_21 ) ;
if ( V_56 < 0 ) {
F_16 ( V_28
L_23
L_24 , V_71 , V_9 -> V_47 ) ;
F_37 ( V_9 -> V_47 ) ;
V_56 = - V_81 ;
goto V_82;
}
F_16 (KERN_INFO EDAC_MOD_STR L_25 ,
pdata->irq) ;
}
if ( V_9 -> V_50 ) {
F_7 ( V_9 -> V_24 + V_77 , ~ 0
& ~ V_83 ) ;
F_7 ( V_9 -> V_24 + V_30 , 0
| V_84 ) ;
}
F_38 ( & V_53 -> V_2 , F_25 ) ;
F_34 ( 3 , L_26 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_27 ) ;
return 0 ;
V_82:
F_39 ( & V_53 -> V_2 ) ;
V_72:
F_40 ( V_21 ) ;
F_41 ( & V_53 -> V_2 , F_25 ) ;
return V_56 ;
}
static T_1 F_42 ( struct V_85
* V_86 , char * V_5 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_88 + V_89 ) ) ;
}
static T_1 F_43 ( struct V_85
* V_86 , char * V_5 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_88 + V_90 ) ) ;
}
static T_1 F_44 ( struct V_85
* V_86 , char * V_5 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_88 + V_91 ) ) ;
}
static T_1 F_45 ( struct V_85
* V_86 , const char * V_5 ,
T_2 V_15 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_88 + V_89 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_46 ( struct V_85
* V_86 , const char * V_5 ,
T_2 V_15 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_88 + V_90 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_47 ( struct V_85
* V_86 , const char * V_5 ,
T_2 V_15 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_88 + V_91 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static void F_48 ( struct V_85
* V_86 )
{
V_86 -> V_92 = V_93 ;
}
static void F_49 ( struct V_85 * V_86 )
{
struct V_87 * V_9 = V_86 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_88 + V_94 ) ;
if ( ! ( V_23 & V_95 ) )
return;
F_16 ( V_28 L_28 ) ;
F_16 ( V_28 L_29 , V_23 ) ;
F_16 ( V_28 L_30 ,
F_3 ( V_9 -> V_88 + V_96 ) ) ;
F_16 ( V_28 L_31 ,
F_3 ( V_9 -> V_88 + V_97 ) ) ;
F_16 ( V_28 L_32 ,
F_3 ( V_9 -> V_88 + V_98 ) ) ;
F_16 ( V_28 L_33 ,
F_3 ( V_9 -> V_88 + V_99 ) ) ;
F_16 ( V_28 L_34 ,
F_3 ( V_9 -> V_88 + V_100 ) ) ;
F_7 ( V_9 -> V_88 + V_94 , V_23 ) ;
if ( V_23 & V_101 )
F_50 ( V_86 , 0 , 0 , V_86 -> V_35 ) ;
if ( V_23 & V_102 )
F_51 ( V_86 , 0 , 0 , V_86 -> V_35 ) ;
}
static T_4 F_52 ( int V_47 , void * V_48 )
{
struct V_85 * V_86 = V_48 ;
struct V_87 * V_9 = V_86 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_88 + V_94 ) ;
if ( ! ( V_23 & V_95 ) )
return V_49 ;
F_49 ( V_86 ) ;
return V_51 ;
}
static int F_53 ( struct V_52 * V_53 )
{
struct V_85 * V_86 ;
struct V_87 * V_9 ;
struct V_54 V_55 ;
int V_56 ;
if ( ! F_26 ( & V_53 -> V_2 , F_53 , V_57 ) )
return - V_58 ;
V_86 = F_54 ( sizeof( * V_9 ) ,
L_35 , 1 , L_36 , 1 , 2 , NULL , 0 ,
V_103 ) ;
if ( ! V_86 ) {
F_41 ( & V_53 -> V_2 , F_53 ) ;
return - V_58 ;
}
V_9 = V_86 -> V_10 ;
V_9 -> V_62 = L_37 ;
V_9 -> V_47 = V_63 ;
V_86 -> V_2 = & V_53 -> V_2 ;
F_28 ( V_86 -> V_2 , V_86 ) ;
V_86 -> V_35 = V_9 -> V_62 ;
V_86 -> V_67 = V_9 -> V_62 ;
V_56 = F_29 ( V_53 -> V_2 . V_64 , 0 , & V_55 ) ;
if ( V_56 ) {
F_16 ( V_28 L_17
L_38 , V_71 ) ;
goto V_72;
}
V_55 . V_73 += 0xe00 ;
if ( ! F_30 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ,
V_9 -> V_62 ) ) {
F_16 ( V_28 L_19 ,
V_71 ) ;
V_56 = - V_74 ;
goto V_72;
}
V_9 -> V_88 = F_32 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ) ;
if ( ! V_9 -> V_88 ) {
F_16 ( V_28 L_39 , V_71 ) ;
V_56 = - V_58 ;
goto V_72;
}
F_7 ( V_9 -> V_88 + V_94 , ~ 0 ) ;
V_104 = F_3 ( V_9 -> V_88 + V_105 ) ;
F_7 ( V_9 -> V_88 + V_105 , 0 ) ;
V_86 -> V_65 = V_66 ;
if ( V_59 == V_60 )
V_86 -> V_68 = F_49 ;
F_48 ( V_86 ) ;
V_9 -> V_69 = V_103 ++ ;
if ( F_55 ( V_86 ) > 0 ) {
F_34 ( 3 , L_40 ) ;
goto V_72;
}
if ( V_59 == V_61 ) {
V_9 -> V_47 = F_35 ( V_53 -> V_2 . V_64 , 0 ) ;
V_56 = F_36 ( & V_53 -> V_2 , V_9 -> V_47 ,
F_52 , V_79 ,
L_41 , V_86 ) ;
if ( V_56 < 0 ) {
F_16 ( V_28
L_23
L_42 , V_71 , V_9 -> V_47 ) ;
F_37 ( V_9 -> V_47 ) ;
V_56 = - V_81 ;
goto V_82;
}
F_16 (KERN_INFO EDAC_MOD_STR L_43 ,
pdata->irq) ;
V_86 -> V_106 = V_107 ;
F_7 ( V_9 -> V_88 + V_108 , V_109 ) ;
}
F_38 ( & V_53 -> V_2 , F_53 ) ;
F_34 ( 3 , L_26 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_44 ) ;
return 0 ;
V_82:
F_56 ( & V_53 -> V_2 ) ;
V_72:
F_41 ( & V_53 -> V_2 , F_53 ) ;
F_57 ( V_86 ) ;
return V_56 ;
}
static int F_58 ( struct V_52 * V_53 )
{
struct V_85 * V_86 = F_59 ( & V_53 -> V_2 ) ;
struct V_87 * V_9 = V_86 -> V_10 ;
F_34 ( 0 , L_45 ) ;
if ( V_59 == V_61 ) {
F_7 ( V_9 -> V_88 + V_108 , 0 ) ;
F_37 ( V_9 -> V_47 ) ;
}
F_7 ( V_9 -> V_88 + V_105 , V_104 ) ;
F_56 ( & V_53 -> V_2 ) ;
F_57 ( V_86 ) ;
return 0 ;
}
static T_5 F_60 ( T_3 V_110 , T_3 V_111 )
{
T_3 V_112 ;
T_3 V_113 ;
int V_114 ;
T_5 V_115 = 0 ;
int V_116 ;
int V_117 ;
for ( V_116 = 0 ; V_116 < 8 ; V_116 ++ ) {
V_113 = V_118 [ V_116 * 2 ] ;
V_112 = V_118 [ V_116 * 2 + 1 ] ;
V_114 = 0 ;
for ( V_117 = 0 ; V_117 < 32 ; V_117 ++ ) {
if ( ( V_113 >> V_117 ) & 1 )
V_114 ^= ( V_110 >> V_117 ) & 1 ;
if ( ( V_112 >> V_117 ) & 1 )
V_114 ^= ( V_111 >> V_117 ) & 1 ;
}
V_115 |= V_114 << V_116 ;
}
return V_115 ;
}
static T_5 F_61 ( unsigned int V_119 ) {
int V_116 ;
T_5 V_120 = 0 ;
for ( V_116 = V_119 < 32 ; V_116 < 16 ; V_116 += 2 )
V_120 |= ( ( V_118 [ V_116 ] >> ( V_119 % 32 ) ) & 1 ) << ( V_116 / 2 ) ;
return V_120 ;
}
static void F_62 ( T_3 V_121 , T_3 V_122 , T_3 V_123 ,
int * V_124 , int * V_125 )
{
int V_116 ;
T_5 V_120 ;
* V_124 = - 1 ;
* V_125 = - 1 ;
V_120 = F_60 ( V_121 , V_122 ) ^ V_123 ;
for ( V_116 = 0 ; V_116 < 64 ; V_116 ++ ) {
if ( V_120 == F_61 ( V_116 ) ) {
* V_124 = V_116 ;
return;
}
}
for ( V_116 = 0 ; V_116 < 8 ; V_116 ++ ) {
if ( ( V_120 >> V_116 ) & 0x1 ) {
* V_125 = V_116 ;
return;
}
}
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_126 * V_127 ;
T_3 V_128 ;
T_3 V_23 ;
T_3 V_120 ;
T_3 V_129 ;
T_3 V_130 ;
int V_131 ;
T_3 V_121 ;
T_3 V_122 ;
int V_124 ;
int V_125 ;
V_23 = F_3 ( V_9 -> V_11 + V_132 ) ;
if ( ! V_23 )
return;
F_64 ( V_7 , V_28 , L_46 ,
V_23 ) ;
if ( ! ( V_23 & ( V_133 | V_134 ) ) ) {
F_7 ( V_9 -> V_11 + V_132 , V_23 ) ;
return;
}
V_120 = F_3 ( V_9 -> V_11 + V_135 ) ;
V_128 = ( F_3 ( V_9 -> V_11 + V_136 ) &
V_137 ) ? 32 : 64 ;
if ( V_128 == 64 )
V_120 &= 0xff ;
else
V_120 &= 0xffff ;
V_129 = F_3 ( V_9 -> V_11 + V_138 ) ;
V_130 = V_129 >> V_139 ;
for ( V_131 = 0 ; V_131 < V_7 -> V_140 ; V_131 ++ ) {
V_127 = V_7 -> V_141 [ V_131 ] ;
if ( ( V_130 >= V_127 -> V_142 ) && ( V_130 <= V_127 -> V_143 ) )
break;
}
V_121 = F_3 ( V_9 -> V_11 + V_144 ) ;
V_122 = F_3 ( V_9 -> V_11 + V_145 ) ;
if ( ( V_23 & V_133 ) && ( V_128 == 64 ) ) {
F_62 ( V_121 , V_122 , V_120 ,
& V_124 , & V_125 ) ;
if ( V_124 != - 1 )
F_64 ( V_7 , V_28 ,
L_47 , V_124 ) ;
if ( V_125 != - 1 )
F_64 ( V_7 , V_28 ,
L_48 , V_125 ) ;
F_64 ( V_7 , V_28 ,
L_49 ,
V_121 ^ ( 1 << ( V_124 - 32 ) ) ,
V_122 ^ ( 1 << V_124 ) ,
V_120 ^ ( 1 << V_125 ) ) ;
}
F_64 ( V_7 , V_28 ,
L_50 ,
V_121 , V_122 , V_120 ) ;
F_64 ( V_7 , V_28 , L_51 , V_129 ) ;
F_64 ( V_7 , V_28 , L_52 , V_130 ) ;
if ( V_131 == V_7 -> V_140 )
F_64 ( V_7 , V_28 , L_53 ) ;
if ( V_23 & V_133 )
F_65 ( V_146 , V_7 , 1 ,
V_130 , V_129 & ~ V_147 , V_120 ,
V_131 , 0 , - 1 ,
V_7 -> V_35 , L_54 ) ;
if ( V_23 & V_134 )
F_65 ( V_148 , V_7 , 1 ,
V_130 , V_129 & ~ V_147 , V_120 ,
V_131 , 0 , - 1 ,
V_7 -> V_35 , L_54 ) ;
F_7 ( V_9 -> V_11 + V_132 , V_23 ) ;
}
static T_4 F_66 ( int V_47 , void * V_48 )
{
struct V_6 * V_7 = V_48 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_11 + V_132 ) ;
if ( ! V_23 )
return V_49 ;
F_63 ( V_7 ) ;
return V_51 ;
}
static void F_67 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_126 * V_127 ;
struct V_149 * V_150 ;
T_3 V_151 ;
T_3 V_152 ;
enum V_153 V_154 ;
T_3 V_155 ;
int V_156 ;
V_151 = F_3 ( V_9 -> V_11 + V_136 ) ;
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
V_127 = V_7 -> V_141 [ V_156 ] ;
V_150 = V_127 -> V_170 [ 0 ] -> V_150 ;
V_155 = F_3 ( V_9 -> V_11 + V_171 +
( V_156 * V_172 ) ) ;
V_73 = ( V_155 & 0xffff0000 ) >> 16 ;
V_169 = ( V_155 & 0x0000ffff ) ;
if ( V_73 == V_169 )
continue;
V_73 <<= ( 24 - V_139 ) ;
V_169 <<= ( 24 - V_139 ) ;
V_169 |= ( 1 << ( 24 - V_139 ) ) - 1 ;
V_127 -> V_142 = V_73 ;
V_127 -> V_143 = V_169 ;
V_150 -> V_173 = V_169 + 1 - V_73 ;
V_150 -> V_174 = 8 ;
V_150 -> V_154 = V_154 ;
V_150 -> V_175 = V_176 ;
if ( V_151 & V_177 )
V_150 -> V_175 = V_178 ;
V_150 -> V_179 = V_180 ;
}
}
static int F_68 ( struct V_52 * V_53 )
{
struct V_6 * V_7 ;
struct V_181 V_182 [ 2 ] ;
struct V_8 * V_9 ;
struct V_54 V_55 ;
T_3 V_151 ;
int V_56 ;
if ( ! F_26 ( & V_53 -> V_2 , F_68 , V_57 ) )
return - V_58 ;
V_182 [ 0 ] . type = V_183 ;
V_182 [ 0 ] . V_184 = 4 ;
V_182 [ 0 ] . V_185 = true ;
V_182 [ 1 ] . type = V_186 ;
V_182 [ 1 ] . V_184 = 1 ;
V_182 [ 1 ] . V_185 = false ;
V_7 = F_69 ( V_187 , F_70 ( V_182 ) , V_182 ,
sizeof( * V_9 ) ) ;
if ( ! V_7 ) {
F_41 ( & V_53 -> V_2 , F_68 ) ;
return - V_58 ;
}
V_9 = V_7 -> V_10 ;
V_9 -> V_62 = L_55 ;
V_9 -> V_47 = V_63 ;
V_7 -> V_188 = & V_53 -> V_2 ;
V_9 -> V_69 = V_187 ++ ;
F_28 ( V_7 -> V_188 , V_7 ) ;
V_7 -> V_35 = V_9 -> V_62 ;
V_7 -> V_67 = V_9 -> V_62 ;
V_56 = F_29 ( V_53 -> V_2 . V_64 , 0 , & V_55 ) ;
if ( V_56 ) {
F_16 ( V_28 L_56 ,
V_71 ) ;
goto V_72;
}
if ( ! F_30 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ,
V_9 -> V_62 ) ) {
F_16 ( V_28 L_19 ,
V_71 ) ;
V_56 = - V_74 ;
goto V_72;
}
V_9 -> V_11 = F_32 ( & V_53 -> V_2 , V_55 . V_73 , F_31 ( & V_55 ) ) ;
if ( ! V_9 -> V_11 ) {
F_16 ( V_28 L_57 , V_71 ) ;
V_56 = - V_58 ;
goto V_72;
}
V_151 = F_3 ( V_9 -> V_11 + V_136 ) ;
if ( ! ( V_151 & V_189 ) ) {
F_16 ( V_190 L_58 , V_71 ) ;
V_56 = - V_81 ;
goto V_72;
}
F_34 ( 3 , L_59 ) ;
V_7 -> V_191 = V_192 | V_193 |
V_194 | V_195 ;
V_7 -> V_196 = V_197 | V_198 ;
V_7 -> V_199 = V_198 ;
V_7 -> V_65 = V_66 ;
V_7 -> V_200 = V_201 ;
if ( V_59 == V_60 )
V_7 -> V_68 = F_63 ;
V_7 -> V_202 = NULL ;
V_7 -> V_203 = V_204 ;
F_67 ( V_7 ) ;
V_205 =
F_3 ( V_9 -> V_11 + V_206 ) ;
F_7 ( V_9 -> V_11 + V_206 , 0 ) ;
F_7 ( V_9 -> V_11 + V_132 , ~ 0 ) ;
if ( F_71 ( V_7 ) ) {
F_34 ( 3 , L_60 ) ;
goto V_72;
}
if ( F_11 ( V_7 ) ) {
F_72 ( V_7 -> V_188 ) ;
F_34 ( 3 , L_60 ) ;
goto V_72;
}
if ( V_59 == V_61 ) {
F_7 ( V_9 -> V_11 + V_207 ,
V_208 | V_209 ) ;
V_210 = F_3 ( V_9 -> V_11 +
V_211 ) & 0xff0000 ;
F_7 ( V_9 -> V_11 + V_211 , 0x10000 ) ;
V_9 -> V_47 = F_35 ( V_53 -> V_2 . V_64 , 0 ) ;
V_56 = F_36 ( & V_53 -> V_2 , V_9 -> V_47 ,
F_66 ,
V_79 | V_80 ,
L_61 , V_7 ) ;
if ( V_56 < 0 ) {
F_16 ( V_28 L_23
L_62 , V_71 , V_9 -> V_47 ) ;
F_37 ( V_9 -> V_47 ) ;
V_56 = - V_81 ;
goto V_82;
}
F_16 (KERN_INFO EDAC_MOD_STR L_63 ,
pdata->irq) ;
}
F_38 ( & V_53 -> V_2 , F_68 ) ;
F_34 ( 3 , L_26 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_64 ) ;
return 0 ;
V_82:
F_72 ( & V_53 -> V_2 ) ;
V_72:
F_41 ( & V_53 -> V_2 , F_68 ) ;
F_73 ( V_7 ) ;
return V_56 ;
}
static int F_74 ( struct V_52 * V_53 )
{
struct V_6 * V_7 = F_59 ( & V_53 -> V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_34 ( 0 , L_45 ) ;
if ( V_59 == V_61 ) {
F_7 ( V_9 -> V_11 + V_207 , 0 ) ;
F_37 ( V_9 -> V_47 ) ;
}
F_7 ( V_9 -> V_11 + V_206 ,
V_205 ) ;
F_7 ( V_9 -> V_11 + V_211 , V_210 ) ;
F_13 ( V_7 ) ;
F_72 ( & V_53 -> V_2 ) ;
F_73 ( V_7 ) ;
return 0 ;
}
static void T_6 F_75 ( void * V_5 )
{
V_212 [ F_76 () ] = F_77 ( V_213 ) ;
F_78 ( V_213 , ( V_212 [ F_76 () ] & ~ V_214 ) ) ;
}
static int T_6 F_79 ( void )
{
int V_56 = 0 ;
T_3 V_215 = 0 ;
F_16 ( V_216 L_65
L_66 ) ;
switch ( V_59 ) {
case V_60 :
case V_61 :
break;
default:
V_59 = V_61 ;
break;
}
V_56 = F_80 ( & V_217 ) ;
if ( V_56 )
F_16 (KERN_WARNING EDAC_MOD_STR L_67 ) ;
V_56 = F_80 ( & V_218 ) ;
if ( V_56 )
F_16 (KERN_WARNING EDAC_MOD_STR L_68 ) ;
#ifdef F_81
V_215 = F_77 ( V_219 ) ;
if ( ( F_82 ( V_215 ) == V_220 ) ||
( F_82 ( V_215 ) == V_221 ) ) {
if ( V_59 == V_61 )
F_83 ( F_75 , NULL , 0 ) ;
}
#endif
return 0 ;
}
static void T_7 F_84 ( void * V_5 )
{
F_78 ( V_213 , V_212 [ F_76 () ] ) ;
}
static void T_7 F_85 ( void )
{
#ifdef F_81
T_3 V_215 = F_77 ( V_219 ) ;
if ( ( F_82 ( V_215 ) == V_220 ) ||
( F_82 ( V_215 ) == V_221 ) ) {
F_83 ( F_84 , NULL , 0 ) ;
}
#endif
F_86 ( & V_218 ) ;
F_86 ( & V_217 ) ;
}
