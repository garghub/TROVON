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
int F_21 ( struct V_48 * V_49 )
{
struct V_16 * V_17 ;
struct V_18 * V_9 ;
struct V_50 V_51 ;
int V_52 = 0 ;
if ( ! F_22 ( & V_49 -> V_2 , F_21 , V_53 ) )
return - V_54 ;
V_17 = F_23 ( sizeof( * V_9 ) , L_16 ) ;
if ( ! V_17 )
return - V_54 ;
switch ( V_55 ) {
case V_56 :
case V_57 :
break;
default:
V_55 = V_57 ;
break;
}
V_9 = V_17 -> V_10 ;
V_9 -> V_58 = L_16 ;
V_9 -> V_43 = V_59 ;
if ( F_17 ( V_49 -> V_2 . V_60 ) > 0 )
V_9 -> V_46 = true ;
F_24 ( & V_49 -> V_2 , V_17 ) ;
V_17 -> V_2 = & V_49 -> V_2 ;
V_17 -> V_61 = V_62 ;
V_17 -> V_31 = V_9 -> V_58 ;
V_17 -> V_63 = V_63 ( & V_49 -> V_2 ) ;
if ( V_55 == V_56 ) {
if ( V_9 -> V_46 )
V_17 -> V_64 = F_15 ;
else
V_17 -> V_64 = F_11 ;
}
V_9 -> V_65 = V_66 ++ ;
V_52 = F_25 ( V_49 -> V_2 . V_60 , 0 , & V_51 ) ;
if ( V_52 ) {
F_12 ( V_24 L_17
L_18 , V_67 ) ;
goto V_68;
}
V_51 . V_69 += 0xe00 ;
if ( ! F_26 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ,
V_9 -> V_58 ) ) {
F_12 ( V_24 L_19 ,
V_67 ) ;
V_52 = - V_70 ;
goto V_68;
}
V_9 -> V_20 = F_28 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ) ;
if ( ! V_9 -> V_20 ) {
F_12 ( V_24 L_20 , V_67 ) ;
V_52 = - V_54 ;
goto V_68;
}
if ( V_9 -> V_46 ) {
V_71 =
F_3 ( V_9 -> V_20 + V_26 ) ;
F_7 ( V_9 -> V_20 + V_26 , ~ 0 ) ;
V_72 =
F_3 ( V_9 -> V_20 + V_73 ) ;
F_7 ( V_9 -> V_20 + V_73 , 0 ) ;
} else {
V_71 =
F_3 ( V_9 -> V_20 + V_74 ) ;
F_7 ( V_9 -> V_20 + V_74 , 0x40 ) ;
V_72 =
F_3 ( V_9 -> V_20 + V_73 ) ;
F_7 ( V_9 -> V_20 + V_73 , ~ 0x40 ) ;
}
F_7 ( V_9 -> V_20 + V_21 , ~ 0 ) ;
if ( F_29 ( V_17 , V_9 -> V_65 ) > 0 ) {
F_30 ( 3 , L_21 ) ;
goto V_68;
}
if ( V_55 == V_57 ) {
V_9 -> V_43 = F_31 ( V_49 -> V_2 . V_60 , 0 ) ;
V_52 = F_32 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_20 ,
V_75 ,
L_22 , V_17 ) ;
if ( V_52 < 0 ) {
F_12 ( V_24
L_23
L_24 , V_67 , V_9 -> V_43 ) ;
F_33 ( V_9 -> V_43 ) ;
V_52 = - V_76 ;
goto V_77;
}
F_12 (KERN_INFO EDAC_MOD_STR L_25 ,
pdata->irq) ;
}
if ( V_9 -> V_46 ) {
F_7 ( V_9 -> V_20 + V_73 , ~ 0
& ~ V_78 ) ;
F_7 ( V_9 -> V_20 + V_26 , 0
| V_79 ) ;
}
F_34 ( & V_49 -> V_2 , F_21 ) ;
F_30 ( 3 , L_26 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_27 ) ;
return 0 ;
V_77:
F_35 ( & V_49 -> V_2 ) ;
V_68:
F_36 ( V_17 ) ;
F_37 ( & V_49 -> V_2 , F_21 ) ;
return V_52 ;
}
static T_1 F_38 ( struct V_80
* V_81 , char * V_5 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_83 + V_84 ) ) ;
}
static T_1 F_39 ( struct V_80
* V_81 , char * V_5 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_83 + V_85 ) ) ;
}
static T_1 F_40 ( struct V_80
* V_81 , char * V_5 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
return sprintf ( V_5 , L_1 ,
F_3 ( V_9 -> V_83 + V_86 ) ) ;
}
static T_1 F_41 ( struct V_80
* V_81 , const char * V_5 ,
T_2 V_15 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_83 + V_84 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_42 ( struct V_80
* V_81 , const char * V_5 ,
T_2 V_15 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_83 + V_85 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_80
* V_81 , const char * V_5 ,
T_2 V_15 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
if ( isdigit ( * V_5 ) ) {
F_7 ( V_9 -> V_83 + V_86 ,
F_8 ( V_5 , NULL , 0 ) ) ;
return V_15 ;
}
return 0 ;
}
static void F_44 ( struct V_80
* V_81 )
{
V_81 -> V_87 = V_88 ;
}
static void F_45 ( struct V_80 * V_81 )
{
struct V_82 * V_9 = V_81 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_83 + V_89 ) ;
if ( ! ( V_19 & V_90 ) )
return;
F_12 ( V_24 L_28 ) ;
F_12 ( V_24 L_29 , V_19 ) ;
F_12 ( V_24 L_30 ,
F_3 ( V_9 -> V_83 + V_91 ) ) ;
F_12 ( V_24 L_31 ,
F_3 ( V_9 -> V_83 + V_92 ) ) ;
F_12 ( V_24 L_32 ,
F_3 ( V_9 -> V_83 + V_93 ) ) ;
F_12 ( V_24 L_33 ,
F_3 ( V_9 -> V_83 + V_94 ) ) ;
F_12 ( V_24 L_34 ,
F_3 ( V_9 -> V_83 + V_95 ) ) ;
F_7 ( V_9 -> V_83 + V_89 , V_19 ) ;
if ( V_19 & V_96 )
F_46 ( V_81 , 0 , 0 , V_81 -> V_31 ) ;
if ( V_19 & V_97 )
F_47 ( V_81 , 0 , 0 , V_81 -> V_31 ) ;
}
static T_4 F_48 ( int V_43 , void * V_44 )
{
struct V_80 * V_81 = V_44 ;
struct V_82 * V_9 = V_81 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_83 + V_89 ) ;
if ( ! ( V_19 & V_90 ) )
return V_45 ;
F_45 ( V_81 ) ;
return V_47 ;
}
static int F_49 ( struct V_48 * V_49 )
{
struct V_80 * V_81 ;
struct V_82 * V_9 ;
struct V_50 V_51 ;
int V_52 ;
if ( ! F_22 ( & V_49 -> V_2 , F_49 , V_53 ) )
return - V_54 ;
V_81 = F_50 ( sizeof( * V_9 ) ,
L_35 , 1 , L_36 , 1 , 2 , NULL , 0 ,
V_98 ) ;
if ( ! V_81 ) {
F_37 ( & V_49 -> V_2 , F_49 ) ;
return - V_54 ;
}
V_9 = V_81 -> V_10 ;
V_9 -> V_58 = L_37 ;
V_9 -> V_43 = V_59 ;
V_81 -> V_2 = & V_49 -> V_2 ;
F_24 ( V_81 -> V_2 , V_81 ) ;
V_81 -> V_31 = V_9 -> V_58 ;
V_81 -> V_63 = V_9 -> V_58 ;
V_52 = F_25 ( V_49 -> V_2 . V_60 , 0 , & V_51 ) ;
if ( V_52 ) {
F_12 ( V_24 L_17
L_38 , V_67 ) ;
goto V_68;
}
V_51 . V_69 += 0xe00 ;
if ( ! F_26 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ,
V_9 -> V_58 ) ) {
F_12 ( V_24 L_19 ,
V_67 ) ;
V_52 = - V_70 ;
goto V_68;
}
V_9 -> V_83 = F_28 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ) ;
if ( ! V_9 -> V_83 ) {
F_12 ( V_24 L_39 , V_67 ) ;
V_52 = - V_54 ;
goto V_68;
}
F_7 ( V_9 -> V_83 + V_89 , ~ 0 ) ;
V_99 = F_3 ( V_9 -> V_83 + V_100 ) ;
F_7 ( V_9 -> V_83 + V_100 , 0 ) ;
V_81 -> V_61 = V_62 ;
if ( V_55 == V_56 )
V_81 -> V_64 = F_45 ;
F_44 ( V_81 ) ;
V_9 -> V_65 = V_98 ++ ;
if ( F_51 ( V_81 ) > 0 ) {
F_30 ( 3 , L_40 ) ;
goto V_68;
}
if ( V_55 == V_57 ) {
V_9 -> V_43 = F_31 ( V_49 -> V_2 . V_60 , 0 ) ;
V_52 = F_32 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_48 , V_75 ,
L_41 , V_81 ) ;
if ( V_52 < 0 ) {
F_12 ( V_24
L_23
L_42 , V_67 , V_9 -> V_43 ) ;
F_33 ( V_9 -> V_43 ) ;
V_52 = - V_76 ;
goto V_77;
}
F_12 (KERN_INFO EDAC_MOD_STR L_43 ,
pdata->irq) ;
V_81 -> V_101 = V_102 ;
F_7 ( V_9 -> V_83 + V_103 , V_104 ) ;
}
F_34 ( & V_49 -> V_2 , F_49 ) ;
F_30 ( 3 , L_26 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_44 ) ;
return 0 ;
V_77:
F_52 ( & V_49 -> V_2 ) ;
V_68:
F_37 ( & V_49 -> V_2 , F_49 ) ;
F_53 ( V_81 ) ;
return V_52 ;
}
static int F_54 ( struct V_48 * V_49 )
{
struct V_80 * V_81 = F_55 ( & V_49 -> V_2 ) ;
struct V_82 * V_9 = V_81 -> V_10 ;
F_30 ( 0 , L_45 ) ;
if ( V_55 == V_57 ) {
F_7 ( V_9 -> V_83 + V_103 , 0 ) ;
F_33 ( V_9 -> V_43 ) ;
}
F_7 ( V_9 -> V_83 + V_100 , V_99 ) ;
F_52 ( & V_49 -> V_2 ) ;
F_53 ( V_81 ) ;
return 0 ;
}
static T_5 F_56 ( T_3 V_105 , T_3 V_106 )
{
T_3 V_107 ;
T_3 V_108 ;
int V_109 ;
T_5 V_110 = 0 ;
int V_111 ;
int V_112 ;
for ( V_111 = 0 ; V_111 < 8 ; V_111 ++ ) {
V_108 = V_113 [ V_111 * 2 ] ;
V_107 = V_113 [ V_111 * 2 + 1 ] ;
V_109 = 0 ;
for ( V_112 = 0 ; V_112 < 32 ; V_112 ++ ) {
if ( ( V_108 >> V_112 ) & 1 )
V_109 ^= ( V_105 >> V_112 ) & 1 ;
if ( ( V_107 >> V_112 ) & 1 )
V_109 ^= ( V_106 >> V_112 ) & 1 ;
}
V_110 |= V_109 << V_111 ;
}
return V_110 ;
}
static T_5 F_57 ( unsigned int V_114 ) {
int V_111 ;
T_5 V_115 = 0 ;
for ( V_111 = V_114 < 32 ; V_111 < 16 ; V_111 += 2 )
V_115 |= ( ( V_113 [ V_111 ] >> ( V_114 % 32 ) ) & 1 ) << ( V_111 / 2 ) ;
return V_115 ;
}
static void F_58 ( T_3 V_116 , T_3 V_117 , T_3 V_118 ,
int * V_119 , int * V_120 )
{
int V_111 ;
T_5 V_115 ;
* V_119 = - 1 ;
* V_120 = - 1 ;
V_115 = F_56 ( V_116 , V_117 ) ^ V_118 ;
for ( V_111 = 0 ; V_111 < 64 ; V_111 ++ ) {
if ( V_115 == F_57 ( V_111 ) ) {
* V_119 = V_111 ;
return;
}
}
for ( V_111 = 0 ; V_111 < 8 ; V_111 ++ ) {
if ( ( V_115 >> V_111 ) & 0x1 ) {
* V_120 = V_111 ;
return;
}
}
}
static void F_59 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_121 * V_122 ;
T_3 V_123 ;
T_3 V_19 ;
T_3 V_115 ;
T_3 V_124 ;
T_3 V_125 ;
int V_126 ;
T_3 V_116 ;
T_3 V_117 ;
int V_119 ;
int V_120 ;
V_19 = F_3 ( V_9 -> V_11 + V_127 ) ;
if ( ! V_19 )
return;
F_60 ( V_7 , V_24 , L_46 ,
V_19 ) ;
if ( ! ( V_19 & ( V_128 | V_129 ) ) ) {
F_7 ( V_9 -> V_11 + V_127 , V_19 ) ;
return;
}
V_115 = F_3 ( V_9 -> V_11 + V_130 ) ;
V_123 = ( F_3 ( V_9 -> V_11 + V_131 ) &
V_132 ) ? 32 : 64 ;
if ( V_123 == 64 )
V_115 &= 0xff ;
else
V_115 &= 0xffff ;
V_124 = F_3 ( V_9 -> V_11 + V_133 ) ;
V_125 = V_124 >> V_134 ;
for ( V_126 = 0 ; V_126 < V_7 -> V_135 ; V_126 ++ ) {
V_122 = V_7 -> V_136 [ V_126 ] ;
if ( ( V_125 >= V_122 -> V_137 ) && ( V_125 <= V_122 -> V_138 ) )
break;
}
V_116 = F_3 ( V_9 -> V_11 + V_139 ) ;
V_117 = F_3 ( V_9 -> V_11 + V_140 ) ;
if ( ( V_19 & V_128 ) && ( V_123 == 64 ) ) {
F_58 ( V_116 , V_117 , V_115 ,
& V_119 , & V_120 ) ;
if ( V_119 != - 1 )
F_60 ( V_7 , V_24 ,
L_47 , V_119 ) ;
if ( V_120 != - 1 )
F_60 ( V_7 , V_24 ,
L_48 , V_120 ) ;
F_60 ( V_7 , V_24 ,
L_49 ,
V_116 ^ ( 1 << ( V_119 - 32 ) ) ,
V_117 ^ ( 1 << V_119 ) ,
V_115 ^ ( 1 << V_120 ) ) ;
}
F_60 ( V_7 , V_24 ,
L_50 ,
V_116 , V_117 , V_115 ) ;
F_60 ( V_7 , V_24 , L_51 , V_124 ) ;
F_60 ( V_7 , V_24 , L_52 , V_125 ) ;
if ( V_126 == V_7 -> V_135 )
F_60 ( V_7 , V_24 , L_53 ) ;
if ( V_19 & V_128 )
F_61 ( V_141 , V_7 , 1 ,
V_125 , V_124 & ~ V_142 , V_115 ,
V_126 , 0 , - 1 ,
V_7 -> V_31 , L_54 ) ;
if ( V_19 & V_129 )
F_61 ( V_143 , V_7 , 1 ,
V_125 , V_124 & ~ V_142 , V_115 ,
V_126 , 0 , - 1 ,
V_7 -> V_31 , L_54 ) ;
F_7 ( V_9 -> V_11 + V_127 , V_19 ) ;
}
static T_4 F_62 ( int V_43 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_19 ;
V_19 = F_3 ( V_9 -> V_11 + V_127 ) ;
if ( ! V_19 )
return V_45 ;
F_59 ( V_7 ) ;
return V_47 ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_121 * V_122 ;
struct V_144 * V_145 ;
T_3 V_146 ;
T_3 V_147 ;
enum V_148 V_149 ;
T_3 V_150 ;
int V_151 ;
V_146 = F_3 ( V_9 -> V_11 + V_131 ) ;
V_147 = V_146 & V_152 ;
if ( V_146 & V_153 ) {
switch ( V_147 ) {
case V_154 :
V_149 = V_155 ;
break;
case V_156 :
V_149 = V_157 ;
break;
case V_158 :
V_149 = V_159 ;
break;
default:
V_149 = V_160 ;
break;
}
} else {
switch ( V_147 ) {
case V_154 :
V_149 = V_161 ;
break;
case V_156 :
V_149 = V_162 ;
break;
case V_158 :
V_149 = V_163 ;
break;
default:
V_149 = V_160 ;
break;
}
}
for ( V_151 = 0 ; V_151 < V_7 -> V_135 ; V_151 ++ ) {
T_3 V_69 ;
T_3 V_164 ;
V_122 = V_7 -> V_136 [ V_151 ] ;
V_145 = V_122 -> V_165 [ 0 ] -> V_145 ;
V_150 = F_3 ( V_9 -> V_11 + V_166 +
( V_151 * V_167 ) ) ;
V_69 = ( V_150 & 0xffff0000 ) >> 16 ;
V_164 = ( V_150 & 0x0000ffff ) ;
if ( V_69 == V_164 )
continue;
V_69 <<= ( 24 - V_134 ) ;
V_164 <<= ( 24 - V_134 ) ;
V_164 |= ( 1 << ( 24 - V_134 ) ) - 1 ;
V_122 -> V_137 = V_69 ;
V_122 -> V_138 = V_164 ;
V_145 -> V_168 = V_164 + 1 - V_69 ;
V_145 -> V_169 = 8 ;
V_145 -> V_149 = V_149 ;
V_145 -> V_170 = V_171 ;
if ( V_146 & V_172 )
V_145 -> V_170 = V_173 ;
V_145 -> V_174 = V_175 ;
}
}
static int F_64 ( struct V_48 * V_49 )
{
struct V_6 * V_7 ;
struct V_176 V_177 [ 2 ] ;
struct V_8 * V_9 ;
struct V_50 V_51 ;
T_3 V_146 ;
int V_52 ;
if ( ! F_22 ( & V_49 -> V_2 , F_64 , V_53 ) )
return - V_54 ;
V_177 [ 0 ] . type = V_178 ;
V_177 [ 0 ] . V_179 = 4 ;
V_177 [ 0 ] . V_180 = true ;
V_177 [ 1 ] . type = V_181 ;
V_177 [ 1 ] . V_179 = 1 ;
V_177 [ 1 ] . V_180 = false ;
V_7 = F_65 ( V_182 , F_66 ( V_177 ) , V_177 ,
sizeof( * V_9 ) ) ;
if ( ! V_7 ) {
F_37 ( & V_49 -> V_2 , F_64 ) ;
return - V_54 ;
}
V_9 = V_7 -> V_10 ;
V_9 -> V_58 = L_55 ;
V_9 -> V_43 = V_59 ;
V_7 -> V_183 = & V_49 -> V_2 ;
V_9 -> V_65 = V_182 ++ ;
F_24 ( V_7 -> V_183 , V_7 ) ;
V_7 -> V_31 = V_9 -> V_58 ;
V_7 -> V_63 = V_9 -> V_58 ;
V_52 = F_25 ( V_49 -> V_2 . V_60 , 0 , & V_51 ) ;
if ( V_52 ) {
F_12 ( V_24 L_56 ,
V_67 ) ;
goto V_68;
}
if ( ! F_26 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ,
V_9 -> V_58 ) ) {
F_12 ( V_24 L_19 ,
V_67 ) ;
V_52 = - V_70 ;
goto V_68;
}
V_9 -> V_11 = F_28 ( & V_49 -> V_2 , V_51 . V_69 , F_27 ( & V_51 ) ) ;
if ( ! V_9 -> V_11 ) {
F_12 ( V_24 L_57 , V_67 ) ;
V_52 = - V_54 ;
goto V_68;
}
V_146 = F_3 ( V_9 -> V_11 + V_131 ) ;
if ( ! ( V_146 & V_184 ) ) {
F_12 ( V_185 L_58 , V_67 ) ;
V_52 = - V_76 ;
goto V_68;
}
F_30 ( 3 , L_59 ) ;
V_7 -> V_186 = V_187 | V_188 |
V_189 | V_190 ;
V_7 -> V_191 = V_192 | V_193 ;
V_7 -> V_194 = V_193 ;
V_7 -> V_61 = V_62 ;
V_7 -> V_195 = V_196 ;
if ( V_55 == V_56 )
V_7 -> V_64 = F_59 ;
V_7 -> V_197 = NULL ;
V_7 -> V_198 = V_199 ;
F_63 ( V_7 ) ;
V_200 =
F_3 ( V_9 -> V_11 + V_201 ) ;
F_7 ( V_9 -> V_11 + V_201 , 0 ) ;
F_7 ( V_9 -> V_11 + V_127 , ~ 0 ) ;
if ( F_67 ( V_7 , V_202 ) ) {
F_30 ( 3 , L_60 ) ;
goto V_68;
}
if ( V_55 == V_57 ) {
F_7 ( V_9 -> V_11 + V_203 ,
V_204 | V_205 ) ;
V_206 = F_3 ( V_9 -> V_11 +
V_207 ) & 0xff0000 ;
F_7 ( V_9 -> V_11 + V_207 , 0x10000 ) ;
V_9 -> V_43 = F_31 ( V_49 -> V_2 . V_60 , 0 ) ;
V_52 = F_32 ( & V_49 -> V_2 , V_9 -> V_43 ,
F_62 ,
V_75 ,
L_61 , V_7 ) ;
if ( V_52 < 0 ) {
F_12 ( V_24 L_23
L_62 , V_67 , V_9 -> V_43 ) ;
F_33 ( V_9 -> V_43 ) ;
V_52 = - V_76 ;
goto V_77;
}
F_12 (KERN_INFO EDAC_MOD_STR L_63 ,
pdata->irq) ;
}
F_34 ( & V_49 -> V_2 , F_64 ) ;
F_30 ( 3 , L_26 ) ;
F_12 (KERN_INFO EDAC_MOD_STR L_64 ) ;
return 0 ;
V_77:
F_68 ( & V_49 -> V_2 ) ;
V_68:
F_37 ( & V_49 -> V_2 , F_64 ) ;
F_69 ( V_7 ) ;
return V_52 ;
}
static int F_70 ( struct V_48 * V_49 )
{
struct V_6 * V_7 = F_55 ( & V_49 -> V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_30 ( 0 , L_45 ) ;
if ( V_55 == V_57 ) {
F_7 ( V_9 -> V_11 + V_203 , 0 ) ;
F_33 ( V_9 -> V_43 ) ;
}
F_7 ( V_9 -> V_11 + V_201 ,
V_200 ) ;
F_7 ( V_9 -> V_11 + V_207 , V_206 ) ;
F_68 ( & V_49 -> V_2 ) ;
F_69 ( V_7 ) ;
return 0 ;
}
static void T_6 F_71 ( void * V_5 )
{
V_208 [ F_72 () ] = F_73 ( V_209 ) ;
F_74 ( V_209 , ( V_208 [ F_72 () ] & ~ V_210 ) ) ;
}
static int T_6 F_75 ( void )
{
int V_52 = 0 ;
T_3 V_211 = 0 ;
F_12 ( V_212 L_65
L_66 ) ;
switch ( V_55 ) {
case V_56 :
case V_57 :
break;
default:
V_55 = V_57 ;
break;
}
V_52 = F_76 ( & V_213 ) ;
if ( V_52 )
F_12 (KERN_WARNING EDAC_MOD_STR L_67 ) ;
V_52 = F_76 ( & V_214 ) ;
if ( V_52 )
F_12 (KERN_WARNING EDAC_MOD_STR L_68 ) ;
#ifdef F_77
V_211 = F_73 ( V_215 ) ;
if ( ( F_78 ( V_211 ) == V_216 ) ||
( F_78 ( V_211 ) == V_217 ) ) {
if ( V_55 == V_57 )
F_79 ( F_71 , NULL , 0 ) ;
}
#endif
return 0 ;
}
static void T_7 F_80 ( void * V_5 )
{
F_74 ( V_209 , V_208 [ F_72 () ] ) ;
}
static void T_7 F_81 ( void )
{
#ifdef F_77
T_3 V_211 = F_73 ( V_215 ) ;
if ( ( F_78 ( V_211 ) == V_216 ) ||
( F_78 ( V_211 ) == V_217 ) ) {
F_79 ( F_80 , NULL , 0 ) ;
}
#endif
F_82 ( & V_214 ) ;
F_82 ( & V_213 ) ;
}
