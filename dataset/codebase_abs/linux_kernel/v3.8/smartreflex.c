static inline void F_1 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_4 )
{
F_2 ( V_4 , ( V_2 -> V_5 + V_3 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_6 ,
T_1 V_4 )
{
T_1 V_7 ;
if ( V_2 -> V_8 == V_9 && V_3 == V_10 )
V_6 |= V_11 ;
else if ( V_2 -> V_8 == V_12 && V_3 == V_13 )
V_6 |= V_14 ;
V_7 = F_4 ( V_2 -> V_5 + V_3 ) ;
V_7 &= ~ V_6 ;
V_4 &= V_6 ;
V_7 |= V_4 ;
F_2 ( V_7 , ( V_2 -> V_5 + V_3 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static struct V_1 * F_6 ( struct V_15 * V_16 )
{
struct V_1 * V_17 ;
if ( ! V_16 ) {
F_7 ( L_1 , V_18 ) ;
return F_8 ( - V_19 ) ;
}
F_9 (sr_info, &sr_list, node) {
if ( V_16 == V_17 -> V_16 )
return V_17 ;
}
return F_8 ( - V_20 ) ;
}
static T_2 F_10 ( int V_21 , void * V_22 )
{
struct V_1 * V_17 = V_22 ;
T_1 V_23 = 0 ;
switch ( V_17 -> V_8 ) {
case V_9 :
V_23 = F_5 ( V_17 , V_10 ) ;
F_1 ( V_17 , V_10 , V_23 ) ;
break;
case V_12 :
V_23 = F_5 ( V_17 , V_24 ) ;
F_1 ( V_17 , V_24 , V_23 ) ;
break;
default:
F_11 ( & V_17 -> V_25 -> V_26 , L_2 ,
V_17 -> V_8 ) ;
return V_27 ;
}
if ( V_28 -> V_29 )
V_28 -> V_29 ( V_17 , V_23 ) ;
return V_30 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_1 V_33 ;
V_32 = F_13 ( & V_2 -> V_25 -> V_26 , L_3 ) ;
if ( F_14 ( V_32 ) ) {
F_11 ( & V_2 -> V_25 -> V_26 , L_4 ,
V_18 , F_15 ( & V_2 -> V_25 -> V_26 ) ) ;
return;
}
V_33 = F_16 ( V_32 ) ;
F_17 ( V_32 ) ;
switch ( V_33 ) {
case 12000000 :
V_2 -> V_34 = V_35 ;
break;
case 13000000 :
V_2 -> V_34 = V_36 ;
break;
case 19200000 :
V_2 -> V_34 = V_37 ;
break;
case 26000000 :
V_2 -> V_34 = V_38 ;
break;
case 38400000 :
V_2 -> V_34 = V_39 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_5 ,
V_18 , V_33 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_28 || ! ( V_28 -> V_40 ) || ! ( V_28 -> V_41 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 ,
L_6 ,
V_18 ) ;
return;
}
if ( ! V_28 -> V_40 ( V_2 ) )
V_2 -> V_42 = true ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_28 || ! ( V_28 -> V_43 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 ,
L_6 ,
V_18 ) ;
return;
}
if ( V_2 -> V_42 ) {
V_28 -> V_43 ( V_2 , 1 ) ;
V_2 -> V_42 = false ;
}
}
static int F_21 ( struct V_1 * V_17 )
{
struct V_44 * V_45 = V_17 -> V_25 -> V_26 . V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 ;
if ( V_28 -> V_29 && V_28 -> V_50 && V_17 -> V_21 ) {
V_49 = F_22 ( V_17 -> V_21 , F_10 ,
0 , V_17 -> V_51 , V_17 ) ;
if ( V_49 )
goto error;
F_23 ( V_17 -> V_21 ) ;
}
if ( V_45 && V_45 -> V_52 )
F_18 ( V_17 ) ;
return V_49 ;
error:
F_24 ( V_17 -> V_5 ) ;
V_48 = F_25 ( V_17 -> V_25 , V_53 , 0 ) ;
F_26 ( V_48 -> V_54 , F_27 ( V_48 ) ) ;
F_28 ( & V_17 -> V_55 ) ;
F_11 ( & V_17 -> V_25 -> V_26 , L_7
L_8
L_9 , V_18 ) ;
F_29 ( V_17 ) ;
return V_49 ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
int V_57 = V_58 | V_59 |
V_60 ;
F_3 ( V_2 , V_10 ,
V_61 , V_61 ) ;
F_3 ( V_2 , V_62 , V_63 , 0x0 ) ;
if ( F_5 ( V_2 , V_10 ) & V_64 )
V_57 |= V_64 ;
F_3 ( V_2 , V_10 ,
( V_65 | V_66 |
V_67 | V_68 ) ,
V_57 ) ;
F_31 ( ( F_5 ( V_2 , V_10 ) &
V_69 ) , V_70 ,
V_56 ) ;
if ( V_56 >= V_70 )
F_19 ( & V_2 -> V_25 -> V_26 , L_10 ,
V_18 ) ;
F_3 ( V_2 , V_10 , V_61 ,
V_69 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
F_1 ( V_2 , V_71 , V_72 ) ;
F_3 ( V_2 , V_62 , V_63 , 0x0 ) ;
if ( F_5 ( V_2 , V_13 ) & V_14 )
F_3 ( V_2 , V_13 , V_73 ,
V_14 ) ;
else
F_3 ( V_2 , V_13 , V_73 ,
0x0 ) ;
F_1 ( V_2 , V_74 , ( V_75 |
V_76 |
V_77 ) ) ;
F_1 ( V_2 , V_24 , ( V_78 |
V_79 |
V_80 ) ) ;
F_31 ( ( F_5 ( V_2 , V_24 ) &
V_81 ) , V_70 ,
V_56 ) ;
if ( V_56 >= V_70 )
F_19 ( & V_2 -> V_25 -> V_26 , L_10 ,
V_18 ) ;
F_1 ( V_2 , V_74 , V_72 ) ;
F_1 ( V_2 , V_24 , V_81 ) ;
}
static struct V_82 * F_33 (
struct V_1 * V_2 , T_1 V_83 )
{
int V_84 ;
if ( ! V_2 -> V_85 ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_11 ,
V_18 ) ;
return NULL ;
}
for ( V_84 = 0 ; V_84 < V_2 -> V_86 ; V_84 ++ ) {
if ( V_2 -> V_85 [ V_84 ] . V_83 == V_83 )
return & V_2 -> V_85 [ V_84 ] ;
}
return NULL ;
}
int F_34 ( struct V_15 * V_16 )
{
T_1 V_87 , V_88 , V_89 ;
T_1 V_90 , V_91 ;
T_1 V_92 = 0 , V_93 = 0 ;
T_3 V_94 , V_95 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return F_36 ( V_2 ) ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_92 = V_2 -> V_96 ;
V_93 = V_2 -> V_97 ;
V_87 = ( V_2 -> V_34 << V_98 ) |
V_99 | V_100 ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_87 |= V_101 ;
V_95 = V_102 ;
V_94 = V_103 ;
V_89 = V_10 ;
V_90 = V_68 ;
V_91 = V_64 ;
break;
case V_12 :
V_95 = V_104 ;
V_94 = V_105 ;
V_89 = V_13 ;
V_90 = V_73 ;
V_91 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
V_87 |= ( ( V_93 << V_95 ) | ( V_92 << V_94 ) ) ;
F_1 ( V_2 , V_62 , V_87 ) ;
V_88 = ( V_2 -> V_106 << V_107 ) |
( V_2 -> V_108 << V_109 ) |
( V_2 -> V_110 << V_111 ) ;
F_3 ( V_2 , V_89 , ( V_112 |
V_113 | V_114 ) ,
V_88 ) ;
F_3 ( V_2 , V_89 , ( V_90 | V_91 ) ,
V_90 ) ;
return 0 ;
}
int F_37 ( struct V_15 * V_16 )
{
T_1 V_89 ;
T_1 V_90 , V_91 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return F_36 ( V_2 ) ;
}
switch ( V_2 -> V_8 ) {
case V_9 :
V_89 = V_10 ;
V_90 = V_68 ;
V_91 = V_64 ;
break;
case V_12 :
V_89 = V_13 ;
V_90 = V_73 ;
V_91 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
F_3 ( V_2 , V_89 , V_90 | V_91 , 0 ) ;
F_3 ( V_2 , V_62 , V_99 | V_100 , 0 ) ;
return 0 ;
}
int F_38 ( struct V_15 * V_16 )
{
T_1 V_87 , V_115 ;
T_1 V_92 = 0 , V_93 = 0 ;
T_3 V_94 , V_95 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return F_36 ( V_2 ) ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_92 = V_2 -> V_96 ;
V_93 = V_2 -> V_97 ;
V_87 = ( V_2 -> V_34 << V_98 ) |
V_99 |
( V_2 -> V_116 << V_117 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_87 |= V_101 ;
V_95 = V_102 ;
V_94 = V_103 ;
break;
case V_12 :
V_95 = V_104 ;
V_94 = V_105 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
V_87 |= ( ( V_93 << V_95 ) | ( V_92 << V_94 ) ) ;
F_1 ( V_2 , V_62 , V_87 ) ;
V_115 = ( V_2 -> V_118 << V_119 ) |
( V_2 -> V_120 << V_121 ) ;
F_1 ( V_2 , V_122 , V_115 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
F_3 ( V_2 , V_10 ,
( V_65 | V_66 |
V_67 ) ,
( V_65 | V_58 |
V_66 | V_59 |
V_67 | V_60 ) ) ;
break;
case V_12 :
F_1 ( V_2 , V_24 ,
V_78 | V_79 |
V_80 | V_81 ) ;
F_1 ( V_2 , V_71 ,
V_75 | V_76 |
V_77 | V_72 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int F_39 ( struct V_15 * V_16 , unsigned long V_123 )
{
struct V_124 * V_125 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
struct V_82 * V_126 ;
int V_49 ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return F_36 ( V_2 ) ;
}
V_125 = F_40 ( V_2 -> V_16 , V_123 ) ;
if ( F_14 ( V_125 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_15
L_16 , V_18 , V_123 ) ;
return F_36 ( V_125 ) ;
}
V_126 = F_33 ( V_2 , V_125 -> V_127 ) ;
if ( ! V_126 ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_17 ,
V_18 , V_123 ) ;
return - V_20 ;
}
V_2 -> V_110 = V_126 -> V_128 ;
F_41 ( & V_2 -> V_25 -> V_26 ) ;
if ( F_5 ( V_2 , V_62 ) & V_63 )
return 0 ;
V_49 = V_28 -> V_41 ( V_2 ) ;
if ( V_49 )
return V_49 ;
F_1 ( V_2 , V_129 , V_126 -> V_130 ) ;
F_3 ( V_2 , V_62 , V_63 , V_63 ) ;
return 0 ;
}
void F_42 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return;
}
if ( F_43 ( & V_2 -> V_25 -> V_26 ) )
return;
if ( F_5 ( V_2 , V_62 ) & V_63 ) {
switch ( V_2 -> V_8 ) {
case V_9 :
F_30 ( V_2 ) ;
break;
case V_12 :
F_32 ( V_2 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_2 ,
V_2 -> V_8 ) ;
}
}
F_44 ( & V_2 -> V_25 -> V_26 ) ;
}
int F_45 ( struct V_131 * V_132 )
{
struct V_1 * V_17 ;
if ( ! V_132 ) {
F_35 ( L_18 ,
V_18 ) ;
return - V_19 ;
}
if ( V_28 ) {
F_35 ( L_19 ,
V_18 ) ;
return - V_133 ;
}
V_28 = V_132 ;
F_9 (sr_info, &sr_list, node)
F_21 ( V_17 ) ;
return 0 ;
}
void F_46 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_40 ) || ! ( V_28 -> V_41 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_20
L_21 , V_18 ) ;
return;
}
V_28 -> V_40 ( V_2 ) ;
}
void F_47 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_43 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_20
L_21 , V_18 ) ;
return;
}
V_28 -> V_43 ( V_2 , 0 ) ;
}
void F_48 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_35 ( L_12 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_43 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_20
L_21 , V_18 ) ;
return;
}
V_28 -> V_43 ( V_2 , 1 ) ;
}
void F_49 ( struct V_134 * V_135 )
{
if ( ! V_135 ) {
F_35 ( L_22
L_23 , V_18 ) ;
return;
}
V_136 = V_135 ;
}
static int F_50 ( void * V_22 , T_4 * V_137 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_35 ( L_24 , V_18 ) ;
return - V_19 ;
}
* V_137 = V_17 -> V_42 ;
return 0 ;
}
static int F_51 ( void * V_22 , T_4 V_137 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_35 ( L_24 , V_18 ) ;
return - V_19 ;
}
if ( V_137 > 1 ) {
F_35 ( L_25 , V_18 , V_137 ) ;
return - V_19 ;
}
if ( V_17 -> V_42 != V_137 ) {
if ( ! V_137 )
F_20 ( V_17 ) ;
else
F_18 ( V_17 ) ;
}
return 0 ;
}
static int T_5 F_52 ( struct V_138 * V_25 )
{
struct V_1 * V_17 ;
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_47 * V_48 , * V_21 ;
struct V_139 * V_140 ;
int V_84 , V_49 = 0 ;
V_17 = F_53 ( sizeof( struct V_1 ) , V_141 ) ;
if ( ! V_17 ) {
F_11 ( & V_25 -> V_26 , L_26 ,
V_18 ) ;
return - V_142 ;
}
F_54 ( V_25 , V_17 ) ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_27 , V_18 ) ;
V_49 = - V_19 ;
goto V_143;
}
V_48 = F_25 ( V_25 , V_53 , 0 ) ;
if ( ! V_48 ) {
F_11 ( & V_25 -> V_26 , L_28 , V_18 ) ;
V_49 = - V_144 ;
goto V_143;
}
V_48 = F_55 ( V_48 -> V_54 , F_27 ( V_48 ) ,
F_15 ( & V_25 -> V_26 ) ) ;
if ( ! V_48 ) {
F_11 ( & V_25 -> V_26 , L_29 , V_18 ) ;
V_49 = - V_133 ;
goto V_143;
}
V_21 = F_25 ( V_25 , V_145 , 0 ) ;
F_56 ( & V_25 -> V_26 ) ;
F_57 ( & V_25 -> V_26 ) ;
V_17 -> V_51 = F_58 ( V_141 , L_30 , V_45 -> V_51 ) ;
if ( ! V_17 -> V_51 ) {
F_11 ( & V_25 -> V_26 , L_31 ,
V_18 ) ;
V_49 = - V_142 ;
goto V_146;
}
V_17 -> V_25 = V_25 ;
V_17 -> V_147 = V_25 -> V_148 ;
V_17 -> V_16 = V_45 -> V_16 ;
V_17 -> V_85 = V_45 -> V_85 ;
V_17 -> V_86 = V_45 -> V_86 ;
V_17 -> V_97 = V_45 -> V_97 ;
V_17 -> V_96 = V_45 -> V_96 ;
V_17 -> V_106 = V_45 -> V_106 ;
V_17 -> V_108 = V_45 -> V_108 ;
V_17 -> V_116 = V_45 -> V_116 ;
V_17 -> V_120 = V_45 -> V_120 ;
V_17 -> V_118 = V_45 -> V_118 ;
V_17 -> V_42 = false ;
V_17 -> V_8 = V_45 -> V_8 ;
V_17 -> V_5 = F_59 ( V_48 -> V_54 , F_27 ( V_48 ) ) ;
if ( ! V_17 -> V_5 ) {
F_11 ( & V_25 -> V_26 , L_32 , V_18 ) ;
V_49 = - V_142 ;
goto V_149;
}
if ( V_21 )
V_17 -> V_21 = V_21 -> V_54 ;
F_12 ( V_17 ) ;
F_60 ( & V_17 -> V_55 , & V_150 ) ;
if ( V_28 ) {
V_49 = F_21 ( V_17 ) ;
if ( V_49 ) {
F_35 ( L_33 , V_18 ) ;
goto V_151;
}
}
F_61 ( & V_25 -> V_26 , L_34 , V_18 ) ;
if ( ! V_152 ) {
V_152 = F_62 ( L_35 , NULL ) ;
if ( F_63 ( V_152 ) ) {
V_49 = F_36 ( V_152 ) ;
F_7 ( L_36 ,
V_18 , V_49 ) ;
goto V_151;
}
}
V_17 -> V_153 = F_62 ( V_17 -> V_51 , V_152 ) ;
if ( F_63 ( V_17 -> V_153 ) ) {
F_11 ( & V_25 -> V_26 , L_37 ,
V_18 ) ;
V_49 = F_36 ( V_17 -> V_153 ) ;
goto V_154;
}
( void ) F_64 ( L_38 , V_155 | V_156 ,
V_17 -> V_153 , ( void * ) V_17 , & V_157 ) ;
( void ) F_65 ( L_39 , V_155 , V_17 -> V_153 ,
& V_17 -> V_106 ) ;
( void ) F_65 ( L_40 , V_155 , V_17 -> V_153 ,
& V_17 -> V_108 ) ;
V_140 = F_62 ( L_41 , V_17 -> V_153 ) ;
if ( F_63 ( V_140 ) ) {
F_11 ( & V_25 -> V_26 , L_42
L_43 , V_18 ) ;
V_49 = F_36 ( V_140 ) ;
goto V_154;
}
if ( V_17 -> V_86 == 0 || ! V_17 -> V_85 ) {
F_19 ( & V_25 -> V_26 , L_44 ,
V_18 , V_17 -> V_51 ) ;
V_49 = - V_20 ;
goto V_154;
}
for ( V_84 = 0 ; V_84 < V_17 -> V_86 ; V_84 ++ ) {
char V_51 [ V_158 + 1 ] ;
snprintf ( V_51 , sizeof( V_51 ) , L_45 ,
V_17 -> V_85 [ V_84 ] . V_159 ) ;
( void ) F_65 ( V_51 , V_155 | V_156 , V_140 ,
& ( V_17 -> V_85 [ V_84 ] . V_130 ) ) ;
snprintf ( V_51 , sizeof( V_51 ) , L_46 ,
V_17 -> V_85 [ V_84 ] . V_159 ) ;
( void ) F_65 ( V_51 , V_155 | V_156 , V_140 ,
& ( V_17 -> V_85 [ V_84 ] . V_128 ) ) ;
}
return V_49 ;
V_154:
F_66 ( V_17 -> V_153 ) ;
V_151:
F_28 ( & V_17 -> V_55 ) ;
F_24 ( V_17 -> V_5 ) ;
V_149:
F_29 ( V_17 -> V_51 ) ;
V_146:
F_26 ( V_48 -> V_54 , F_27 ( V_48 ) ) ;
V_143:
F_29 ( V_17 ) ;
return V_49 ;
}
static int F_67 ( struct V_138 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_1 * V_17 ;
struct V_47 * V_48 ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_27 , V_18 ) ;
return - V_19 ;
}
V_17 = F_6 ( V_45 -> V_16 ) ;
if ( F_14 ( V_17 ) ) {
F_19 ( & V_25 -> V_26 , L_24 ,
V_18 ) ;
return F_36 ( V_17 ) ;
}
if ( V_17 -> V_42 )
F_20 ( V_17 ) ;
if ( V_17 -> V_153 )
F_66 ( V_17 -> V_153 ) ;
F_28 ( & V_17 -> V_55 ) ;
F_24 ( V_17 -> V_5 ) ;
F_29 ( V_17 -> V_51 ) ;
F_29 ( V_17 ) ;
V_48 = F_25 ( V_25 , V_53 , 0 ) ;
F_26 ( V_48 -> V_54 , F_27 ( V_48 ) ) ;
return 0 ;
}
static void F_68 ( struct V_138 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_1 * V_17 ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_27 , V_18 ) ;
return;
}
V_17 = F_6 ( V_45 -> V_16 ) ;
if ( F_14 ( V_17 ) ) {
F_19 ( & V_25 -> V_26 , L_24 ,
V_18 ) ;
return;
}
if ( V_17 -> V_42 )
F_20 ( V_17 ) ;
return;
}
static int T_5 F_69 ( void )
{
int V_49 = 0 ;
if ( V_136 && V_136 -> V_160 )
V_136 -> V_160 () ;
else
F_35 ( L_47 , V_18 ) ;
V_49 = F_70 ( & V_161 , F_52 ) ;
if ( V_49 ) {
F_7 ( L_48 ,
V_18 ) ;
return V_49 ;
}
return 0 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_161 ) ;
}
