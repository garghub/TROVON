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
static T_4 F_19 ( int V_36 , void * V_37 )
{
struct V_20 * V_21 = V_37 ;
struct V_22 * V_9 = V_21 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_24 + V_25 ) ;
if ( ! V_23 )
return V_38 ;
F_15 ( V_21 ) ;
return V_39 ;
}
int F_20 ( struct V_40 * V_41 )
{
struct V_20 * V_21 ;
struct V_22 * V_9 ;
struct V_42 V_43 ;
int V_44 = 0 ;
if ( ! F_21 ( & V_41 -> V_2 , F_20 , V_45 ) )
return - V_46 ;
V_21 = F_22 ( sizeof( * V_9 ) , L_9 ) ;
if ( ! V_21 )
return - V_46 ;
switch ( V_47 ) {
case V_48 :
case V_49 :
break;
default:
V_47 = V_49 ;
break;
}
V_9 = V_21 -> V_10 ;
V_9 -> V_50 = L_9 ;
V_9 -> V_36 = V_51 ;
F_23 ( & V_41 -> V_2 , V_21 ) ;
V_21 -> V_2 = & V_41 -> V_2 ;
V_21 -> V_52 = V_53 ;
V_21 -> V_35 = V_9 -> V_50 ;
V_21 -> V_54 = V_54 ( & V_41 -> V_2 ) ;
if ( V_47 == V_48 )
V_21 -> V_55 = F_15 ;
V_9 -> V_56 = V_57 ++ ;
V_44 = F_24 ( V_41 -> V_2 . V_58 , 0 , & V_43 ) ;
if ( V_44 ) {
F_16 ( V_28 L_10
L_11 , V_59 ) ;
goto V_60;
}
V_43 . V_61 += 0xe00 ;
if ( ! F_25 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ,
V_9 -> V_50 ) ) {
F_16 ( V_28 L_12 ,
V_59 ) ;
V_44 = - V_62 ;
goto V_60;
}
V_9 -> V_24 = F_27 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ) ;
if ( ! V_9 -> V_24 ) {
F_16 ( V_28 L_13 , V_59 ) ;
V_44 = - V_46 ;
goto V_60;
}
V_63 =
F_3 ( V_9 -> V_24 + V_64 ) ;
F_7 ( V_9 -> V_24 + V_64 , 0x40 ) ;
V_65 = F_3 ( V_9 -> V_24 + V_66 ) ;
F_7 ( V_9 -> V_24 + V_66 , ~ 0x40 ) ;
F_7 ( V_9 -> V_24 + V_25 , ~ 0 ) ;
if ( F_28 ( V_21 , V_9 -> V_56 ) > 0 ) {
F_29 ( 3 , L_14 ) ;
goto V_60;
}
if ( V_47 == V_49 ) {
V_9 -> V_36 = F_30 ( V_41 -> V_2 . V_58 , 0 ) ;
V_44 = F_31 ( & V_41 -> V_2 , V_9 -> V_36 ,
F_19 , V_67 ,
L_15 , V_21 ) ;
if ( V_44 < 0 ) {
F_16 ( V_28
L_16
L_17 , V_59 , V_9 -> V_36 ) ;
F_32 ( V_9 -> V_36 ) ;
V_44 = - V_68 ;
goto V_69;
}
F_16 (KERN_INFO EDAC_MOD_STR L_18 ,
pdata->irq) ;
}
F_33 ( & V_41 -> V_2 , F_20 ) ;
F_29 ( 3 , L_19 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_20 ) ;
return 0 ;
V_69:
F_34 ( & V_41 -> V_2 ) ;
V_60:
F_35 ( V_21 ) ;
F_36 ( & V_41 -> V_2 , F_20 ) ;
return V_44 ;
}
static int F_37 ( struct V_40 * V_41 )
{
struct V_20 * V_21 = F_38 ( & V_41 -> V_2 ) ;
struct V_22 * V_9 = V_21 -> V_10 ;
F_29 ( 0 , L_21 ) ;
F_7 ( V_9 -> V_24 + V_64 ,
V_63 ) ;
F_7 ( V_9 -> V_24 + V_66 , V_65 ) ;
F_34 ( V_21 -> V_2 ) ;
if ( V_47 == V_49 )
F_32 ( V_9 -> V_36 ) ;
F_35 ( V_21 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_70
* V_71 , char * V_5 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_73 + V_74 ) ) ;
}
static T_1 F_40 ( struct V_70
* V_71 , char * V_5 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_73 + V_75 ) ) ;
}
static T_1 F_41 ( struct V_70
* V_71 , char * V_5 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_73 + V_76 ) ) ;
}
static T_1 F_42 ( struct V_70
* V_71 , const char * V_5 ,
T_2 V_15 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_73 + V_74 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_70
* V_71 , const char * V_5 ,
T_2 V_15 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_73 + V_75 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_44 ( struct V_70
* V_71 , const char * V_5 ,
T_2 V_15 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_73 + V_76 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static void F_45 ( struct V_70
* V_71 )
{
V_71 -> V_77 = V_78 ;
}
static void F_46 ( struct V_70 * V_71 )
{
struct V_72 * V_9 = V_71 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_73 + V_79 ) ;
if ( ! ( V_23 & V_80 ) )
return;
F_16 ( V_28 L_22 ) ;
F_16 ( V_28 L_23 , V_23 ) ;
F_16 ( V_28 L_24 ,
F_3 ( V_9 -> V_73 + V_81 ) ) ;
F_16 ( V_28 L_25 ,
F_3 ( V_9 -> V_73 + V_82 ) ) ;
F_16 ( V_28 L_26 ,
F_3 ( V_9 -> V_73 + V_83 ) ) ;
F_16 ( V_28 L_27 ,
F_3 ( V_9 -> V_73 + V_84 ) ) ;
F_16 ( V_28 L_28 ,
F_3 ( V_9 -> V_73 + V_85 ) ) ;
F_7 ( V_9 -> V_73 + V_79 , V_23 ) ;
if ( V_23 & V_86 )
F_47 ( V_71 , 0 , 0 , V_71 -> V_35 ) ;
if ( V_23 & V_87 )
F_48 ( V_71 , 0 , 0 , V_71 -> V_35 ) ;
}
static T_4 F_49 ( int V_36 , void * V_37 )
{
struct V_70 * V_71 = V_37 ;
struct V_72 * V_9 = V_71 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_73 + V_79 ) ;
if ( ! ( V_23 & V_80 ) )
return V_38 ;
F_46 ( V_71 ) ;
return V_39 ;
}
static int F_50 ( struct V_40 * V_41 )
{
struct V_70 * V_71 ;
struct V_72 * V_9 ;
struct V_42 V_43 ;
int V_44 ;
if ( ! F_21 ( & V_41 -> V_2 , F_50 , V_45 ) )
return - V_46 ;
V_71 = F_51 ( sizeof( * V_9 ) ,
L_29 , 1 , L_30 , 1 , 2 , NULL , 0 ,
V_88 ) ;
if ( ! V_71 ) {
F_36 ( & V_41 -> V_2 , F_50 ) ;
return - V_46 ;
}
V_9 = V_71 -> V_10 ;
V_9 -> V_50 = L_31 ;
V_9 -> V_36 = V_51 ;
V_71 -> V_2 = & V_41 -> V_2 ;
F_23 ( V_71 -> V_2 , V_71 ) ;
V_71 -> V_35 = V_9 -> V_50 ;
V_71 -> V_54 = V_9 -> V_50 ;
V_44 = F_24 ( V_41 -> V_2 . V_58 , 0 , & V_43 ) ;
if ( V_44 ) {
F_16 ( V_28 L_10
L_32 , V_59 ) ;
goto V_60;
}
V_43 . V_61 += 0xe00 ;
if ( ! F_25 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ,
V_9 -> V_50 ) ) {
F_16 ( V_28 L_12 ,
V_59 ) ;
V_44 = - V_62 ;
goto V_60;
}
V_9 -> V_73 = F_27 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ) ;
if ( ! V_9 -> V_73 ) {
F_16 ( V_28 L_33 , V_59 ) ;
V_44 = - V_46 ;
goto V_60;
}
F_7 ( V_9 -> V_73 + V_79 , ~ 0 ) ;
V_89 = F_3 ( V_9 -> V_73 + V_90 ) ;
F_7 ( V_9 -> V_73 + V_90 , 0 ) ;
V_71 -> V_52 = V_53 ;
if ( V_47 == V_48 )
V_71 -> V_55 = F_46 ;
F_45 ( V_71 ) ;
V_9 -> V_56 = V_88 ++ ;
if ( F_52 ( V_71 ) > 0 ) {
F_29 ( 3 , L_34 ) ;
goto V_60;
}
if ( V_47 == V_49 ) {
V_9 -> V_36 = F_30 ( V_41 -> V_2 . V_58 , 0 ) ;
V_44 = F_31 ( & V_41 -> V_2 , V_9 -> V_36 ,
F_49 , V_67 ,
L_35 , V_71 ) ;
if ( V_44 < 0 ) {
F_16 ( V_28
L_16
L_36 , V_59 , V_9 -> V_36 ) ;
F_32 ( V_9 -> V_36 ) ;
V_44 = - V_68 ;
goto V_69;
}
F_16 (KERN_INFO EDAC_MOD_STR L_37 ,
pdata->irq) ;
V_71 -> V_91 = V_92 ;
F_7 ( V_9 -> V_73 + V_93 , V_94 ) ;
}
F_33 ( & V_41 -> V_2 , F_50 ) ;
F_29 ( 3 , L_19 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_38 ) ;
return 0 ;
V_69:
F_53 ( & V_41 -> V_2 ) ;
V_60:
F_36 ( & V_41 -> V_2 , F_50 ) ;
F_54 ( V_71 ) ;
return V_44 ;
}
static int F_55 ( struct V_40 * V_41 )
{
struct V_70 * V_71 = F_38 ( & V_41 -> V_2 ) ;
struct V_72 * V_9 = V_71 -> V_10 ;
F_29 ( 0 , L_21 ) ;
if ( V_47 == V_49 ) {
F_7 ( V_9 -> V_73 + V_93 , 0 ) ;
F_32 ( V_9 -> V_36 ) ;
}
F_7 ( V_9 -> V_73 + V_90 , V_89 ) ;
F_53 ( & V_41 -> V_2 ) ;
F_54 ( V_71 ) ;
return 0 ;
}
static T_5 F_56 ( T_3 V_95 , T_3 V_96 )
{
T_3 V_97 ;
T_3 V_98 ;
int V_99 ;
T_5 V_100 = 0 ;
int V_101 ;
int V_102 ;
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ ) {
V_98 = V_103 [ V_101 * 2 ] ;
V_97 = V_103 [ V_101 * 2 + 1 ] ;
V_99 = 0 ;
for ( V_102 = 0 ; V_102 < 32 ; V_102 ++ ) {
if ( ( V_98 >> V_102 ) & 1 )
V_99 ^= ( V_95 >> V_102 ) & 1 ;
if ( ( V_97 >> V_102 ) & 1 )
V_99 ^= ( V_96 >> V_102 ) & 1 ;
}
V_100 |= V_99 << V_101 ;
}
return V_100 ;
}
static T_5 F_57 ( unsigned int V_104 ) {
int V_101 ;
T_5 V_105 = 0 ;
for ( V_101 = V_104 < 32 ; V_101 < 16 ; V_101 += 2 )
V_105 |= ( ( V_103 [ V_101 ] >> ( V_104 % 32 ) ) & 1 ) << ( V_101 / 2 ) ;
return V_105 ;
}
static void F_58 ( T_3 V_106 , T_3 V_107 , T_3 V_108 ,
int * V_109 , int * V_110 )
{
int V_101 ;
T_5 V_105 ;
* V_109 = - 1 ;
* V_110 = - 1 ;
V_105 = F_56 ( V_106 , V_107 ) ^ V_108 ;
for ( V_101 = 0 ; V_101 < 64 ; V_101 ++ ) {
if ( V_105 == F_57 ( V_101 ) ) {
* V_109 = V_101 ;
return;
}
}
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ ) {
if ( ( V_105 >> V_101 ) & 0x1 ) {
* V_110 = V_101 ;
return;
}
}
}
static void F_59 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_111 * V_112 ;
T_3 V_113 ;
T_3 V_23 ;
T_3 V_105 ;
T_3 V_114 ;
T_3 V_115 ;
int V_116 ;
T_3 V_106 ;
T_3 V_107 ;
int V_109 ;
int V_110 ;
V_23 = F_3 ( V_9 -> V_11 + V_117 ) ;
if ( ! V_23 )
return;
F_60 ( V_7 , V_28 , L_39 ,
V_23 ) ;
if ( ! ( V_23 & ( V_118 | V_119 ) ) ) {
F_7 ( V_9 -> V_11 + V_117 , V_23 ) ;
return;
}
V_105 = F_3 ( V_9 -> V_11 + V_120 ) ;
V_113 = ( F_3 ( V_9 -> V_11 + V_121 ) &
V_122 ) ? 32 : 64 ;
if ( V_113 == 64 )
V_105 &= 0xff ;
else
V_105 &= 0xffff ;
V_114 = F_3 ( V_9 -> V_11 + V_123 ) ;
V_115 = V_114 >> V_124 ;
for ( V_116 = 0 ; V_116 < V_7 -> V_125 ; V_116 ++ ) {
V_112 = V_7 -> V_126 [ V_116 ] ;
if ( ( V_115 >= V_112 -> V_127 ) && ( V_115 <= V_112 -> V_128 ) )
break;
}
V_106 = F_3 ( V_9 -> V_11 + V_129 ) ;
V_107 = F_3 ( V_9 -> V_11 + V_130 ) ;
if ( ( V_23 & V_118 ) && ( V_113 == 64 ) ) {
F_58 ( V_106 , V_107 , V_105 ,
& V_109 , & V_110 ) ;
if ( V_109 != - 1 )
F_60 ( V_7 , V_28 ,
L_40 , V_109 ) ;
if ( V_110 != - 1 )
F_60 ( V_7 , V_28 ,
L_41 , V_110 ) ;
F_60 ( V_7 , V_28 ,
L_42 ,
V_106 ^ ( 1 << ( V_109 - 32 ) ) ,
V_107 ^ ( 1 << V_109 ) ,
V_105 ^ ( 1 << V_110 ) ) ;
}
F_60 ( V_7 , V_28 ,
L_43 ,
V_106 , V_107 , V_105 ) ;
F_60 ( V_7 , V_28 , L_44 , V_114 ) ;
F_60 ( V_7 , V_28 , L_45 , V_115 ) ;
if ( V_116 == V_7 -> V_125 )
F_60 ( V_7 , V_28 , L_46 ) ;
if ( V_23 & V_118 )
F_61 ( V_131 , V_7 , 1 ,
V_115 , V_114 & ~ V_132 , V_105 ,
V_116 , 0 , - 1 ,
V_7 -> V_35 , L_47 ) ;
if ( V_23 & V_119 )
F_61 ( V_133 , V_7 , 1 ,
V_115 , V_114 & ~ V_132 , V_105 ,
V_116 , 0 , - 1 ,
V_7 -> V_35 , L_47 ) ;
F_7 ( V_9 -> V_11 + V_117 , V_23 ) ;
}
static T_4 F_62 ( int V_36 , void * V_37 )
{
struct V_6 * V_7 = V_37 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_23 ;
V_23 = F_3 ( V_9 -> V_11 + V_117 ) ;
if ( ! V_23 )
return V_38 ;
F_59 ( V_7 ) ;
return V_39 ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_111 * V_112 ;
struct V_134 * V_135 ;
T_3 V_136 ;
T_3 V_137 ;
enum V_138 V_139 ;
T_3 V_140 ;
int V_141 ;
V_136 = F_3 ( V_9 -> V_11 + V_121 ) ;
V_137 = V_136 & V_142 ;
if ( V_136 & V_143 ) {
switch ( V_137 ) {
case V_144 :
V_139 = V_145 ;
break;
case V_146 :
V_139 = V_147 ;
break;
case V_148 :
V_139 = V_149 ;
break;
default:
V_139 = V_150 ;
break;
}
} else {
switch ( V_137 ) {
case V_144 :
V_139 = V_151 ;
break;
case V_146 :
V_139 = V_152 ;
break;
case V_148 :
V_139 = V_153 ;
break;
default:
V_139 = V_150 ;
break;
}
}
for ( V_141 = 0 ; V_141 < V_7 -> V_125 ; V_141 ++ ) {
T_3 V_61 ;
T_3 V_154 ;
V_112 = V_7 -> V_126 [ V_141 ] ;
V_135 = V_112 -> V_155 [ 0 ] -> V_135 ;
V_140 = F_3 ( V_9 -> V_11 + V_156 +
( V_141 * V_157 ) ) ;
V_61 = ( V_140 & 0xffff0000 ) >> 16 ;
V_154 = ( V_140 & 0x0000ffff ) ;
if ( V_61 == V_154 )
continue;
V_61 <<= ( 24 - V_124 ) ;
V_154 <<= ( 24 - V_124 ) ;
V_154 |= ( 1 << ( 24 - V_124 ) ) - 1 ;
V_112 -> V_127 = V_61 ;
V_112 -> V_128 = V_154 ;
V_135 -> V_158 = V_154 + 1 - V_61 ;
V_135 -> V_159 = 8 ;
V_135 -> V_139 = V_139 ;
V_135 -> V_160 = V_161 ;
if ( V_136 & V_162 )
V_135 -> V_160 = V_163 ;
V_135 -> V_164 = V_165 ;
}
}
static int F_64 ( struct V_40 * V_41 )
{
struct V_6 * V_7 ;
struct V_166 V_167 [ 2 ] ;
struct V_8 * V_9 ;
struct V_42 V_43 ;
T_3 V_136 ;
int V_44 ;
if ( ! F_21 ( & V_41 -> V_2 , F_64 , V_45 ) )
return - V_46 ;
V_167 [ 0 ] . type = V_168 ;
V_167 [ 0 ] . V_169 = 4 ;
V_167 [ 0 ] . V_170 = true ;
V_167 [ 1 ] . type = V_171 ;
V_167 [ 1 ] . V_169 = 1 ;
V_167 [ 1 ] . V_170 = false ;
V_7 = F_65 ( V_172 , F_66 ( V_167 ) , V_167 ,
sizeof( * V_9 ) ) ;
if ( ! V_7 ) {
F_36 ( & V_41 -> V_2 , F_64 ) ;
return - V_46 ;
}
V_9 = V_7 -> V_10 ;
V_9 -> V_50 = L_48 ;
V_9 -> V_36 = V_51 ;
V_7 -> V_173 = & V_41 -> V_2 ;
V_9 -> V_56 = V_172 ++ ;
F_23 ( V_7 -> V_173 , V_7 ) ;
V_7 -> V_35 = V_9 -> V_50 ;
V_7 -> V_54 = V_9 -> V_50 ;
V_44 = F_24 ( V_41 -> V_2 . V_58 , 0 , & V_43 ) ;
if ( V_44 ) {
F_16 ( V_28 L_49 ,
V_59 ) ;
goto V_60;
}
if ( ! F_25 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ,
V_9 -> V_50 ) ) {
F_16 ( V_28 L_12 ,
V_59 ) ;
V_44 = - V_62 ;
goto V_60;
}
V_9 -> V_11 = F_27 ( & V_41 -> V_2 , V_43 . V_61 , F_26 ( & V_43 ) ) ;
if ( ! V_9 -> V_11 ) {
F_16 ( V_28 L_50 , V_59 ) ;
V_44 = - V_46 ;
goto V_60;
}
V_136 = F_3 ( V_9 -> V_11 + V_121 ) ;
if ( ! ( V_136 & V_174 ) ) {
F_16 ( V_175 L_51 , V_59 ) ;
V_44 = - V_68 ;
goto V_60;
}
F_29 ( 3 , L_52 ) ;
V_7 -> V_176 = V_177 | V_178 |
V_179 | V_180 ;
V_7 -> V_181 = V_182 | V_183 ;
V_7 -> V_184 = V_183 ;
V_7 -> V_52 = V_53 ;
V_7 -> V_185 = V_186 ;
if ( V_47 == V_48 )
V_7 -> V_55 = F_59 ;
V_7 -> V_187 = NULL ;
V_7 -> V_188 = V_189 ;
F_63 ( V_7 ) ;
V_190 =
F_3 ( V_9 -> V_11 + V_191 ) ;
F_7 ( V_9 -> V_11 + V_191 , 0 ) ;
F_7 ( V_9 -> V_11 + V_117 , ~ 0 ) ;
if ( F_67 ( V_7 ) ) {
F_29 ( 3 , L_53 ) ;
goto V_60;
}
if ( F_11 ( V_7 ) ) {
F_68 ( V_7 -> V_173 ) ;
F_29 ( 3 , L_53 ) ;
goto V_60;
}
if ( V_47 == V_49 ) {
F_7 ( V_9 -> V_11 + V_192 ,
V_193 | V_194 ) ;
V_195 = F_3 ( V_9 -> V_11 +
V_196 ) & 0xff0000 ;
F_7 ( V_9 -> V_11 + V_196 , 0x10000 ) ;
V_9 -> V_36 = F_30 ( V_41 -> V_2 . V_58 , 0 ) ;
V_44 = F_31 ( & V_41 -> V_2 , V_9 -> V_36 ,
F_62 ,
V_67 | V_197 ,
L_54 , V_7 ) ;
if ( V_44 < 0 ) {
F_16 ( V_28 L_16
L_55 , V_59 , V_9 -> V_36 ) ;
F_32 ( V_9 -> V_36 ) ;
V_44 = - V_68 ;
goto V_69;
}
F_16 (KERN_INFO EDAC_MOD_STR L_56 ,
pdata->irq) ;
}
F_33 ( & V_41 -> V_2 , F_64 ) ;
F_29 ( 3 , L_19 ) ;
F_16 (KERN_INFO EDAC_MOD_STR L_57 ) ;
return 0 ;
V_69:
F_68 ( & V_41 -> V_2 ) ;
V_60:
F_36 ( & V_41 -> V_2 , F_64 ) ;
F_69 ( V_7 ) ;
return V_44 ;
}
static int F_70 ( struct V_40 * V_41 )
{
struct V_6 * V_7 = F_38 ( & V_41 -> V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_29 ( 0 , L_21 ) ;
if ( V_47 == V_49 ) {
F_7 ( V_9 -> V_11 + V_192 , 0 ) ;
F_32 ( V_9 -> V_36 ) ;
}
F_7 ( V_9 -> V_11 + V_191 ,
V_190 ) ;
F_7 ( V_9 -> V_11 + V_196 , V_195 ) ;
F_13 ( V_7 ) ;
F_68 ( & V_41 -> V_2 ) ;
F_69 ( V_7 ) ;
return 0 ;
}
static void T_6 F_71 ( void * V_5 )
{
V_198 [ F_72 () ] = F_73 ( V_199 ) ;
F_74 ( V_199 , ( V_198 [ F_72 () ] & ~ V_200 ) ) ;
}
static int T_6 F_75 ( void )
{
int V_44 = 0 ;
T_3 V_201 = 0 ;
F_16 ( V_202 L_58
L_59 ) ;
switch ( V_47 ) {
case V_48 :
case V_49 :
break;
default:
V_47 = V_49 ;
break;
}
V_44 = F_76 ( & V_203 ) ;
if ( V_44 )
F_16 (KERN_WARNING EDAC_MOD_STR L_60 ) ;
V_44 = F_76 ( & V_204 ) ;
if ( V_44 )
F_16 (KERN_WARNING EDAC_MOD_STR L_61 ) ;
#ifdef F_77
V_201 = F_73 ( V_205 ) ;
if ( ( F_78 ( V_201 ) == V_206 ) ||
( F_78 ( V_201 ) == V_207 ) ) {
if ( V_47 == V_49 )
F_79 ( F_71 , NULL , 0 ) ;
}
#endif
return 0 ;
}
static void T_7 F_80 ( void * V_5 )
{
F_74 ( V_199 , V_198 [ F_72 () ] ) ;
}
static void T_7 F_81 ( void )
{
#ifdef F_77
T_3 V_201 = F_73 ( V_205 ) ;
if ( ( F_78 ( V_201 ) == V_206 ) ||
( F_78 ( V_201 ) == V_207 ) ) {
F_79 ( F_80 , NULL , 0 ) ;
}
#endif
F_82 ( & V_204 ) ;
F_82 ( & V_203 ) ;
}
