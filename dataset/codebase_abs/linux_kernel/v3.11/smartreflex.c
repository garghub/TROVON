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
int V_47 = 0 ;
if ( V_28 -> V_29 && V_28 -> V_48 && V_17 -> V_21 ) {
V_47 = F_22 ( & V_17 -> V_25 -> V_26 , V_17 -> V_21 ,
F_10 , 0 , V_17 -> V_49 , V_17 ) ;
if ( V_47 )
goto error;
F_23 ( V_17 -> V_21 ) ;
}
if ( V_45 && V_45 -> V_50 )
F_18 ( V_17 ) ;
return V_47 ;
error:
F_24 ( & V_17 -> V_51 ) ;
F_11 ( & V_17 -> V_25 -> V_26 , L_7
L_8
L_9 , V_18 ) ;
return V_47 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
int V_53 = V_54 | V_55 |
V_56 ;
F_3 ( V_2 , V_10 ,
V_57 , V_57 ) ;
F_3 ( V_2 , V_58 , V_59 , 0x0 ) ;
if ( F_5 ( V_2 , V_10 ) & V_60 )
V_53 |= V_60 ;
F_3 ( V_2 , V_10 ,
( V_61 | V_62 |
V_63 | V_64 ) ,
V_53 ) ;
F_26 ( ( F_5 ( V_2 , V_10 ) &
V_65 ) , V_66 ,
V_52 ) ;
if ( V_52 >= V_66 )
F_19 ( & V_2 -> V_25 -> V_26 , L_10 ,
V_18 ) ;
F_3 ( V_2 , V_10 , V_57 ,
V_65 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
F_1 ( V_2 , V_67 , V_68 ) ;
F_3 ( V_2 , V_58 , V_59 , 0x0 ) ;
if ( F_5 ( V_2 , V_13 ) & V_14 )
F_3 ( V_2 , V_13 , V_69 ,
V_14 ) ;
else
F_3 ( V_2 , V_13 , V_69 ,
0x0 ) ;
F_1 ( V_2 , V_70 , ( V_71 |
V_72 |
V_73 ) ) ;
F_1 ( V_2 , V_24 , ( V_74 |
V_75 |
V_76 ) ) ;
F_26 ( ( F_5 ( V_2 , V_24 ) &
V_77 ) , V_66 ,
V_52 ) ;
if ( V_52 >= V_66 )
F_19 ( & V_2 -> V_25 -> V_26 , L_10 ,
V_18 ) ;
F_1 ( V_2 , V_70 , V_68 ) ;
F_1 ( V_2 , V_24 , V_77 ) ;
}
static struct V_78 * F_28 (
struct V_1 * V_2 , T_1 V_79 )
{
int V_80 ;
if ( ! V_2 -> V_81 ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_11 ,
V_18 ) ;
return NULL ;
}
for ( V_80 = 0 ; V_80 < V_2 -> V_82 ; V_80 ++ ) {
if ( V_2 -> V_81 [ V_80 ] . V_79 == V_79 )
return & V_2 -> V_81 [ V_80 ] ;
}
return NULL ;
}
int F_29 ( struct V_1 * V_2 )
{
T_1 V_83 , V_84 , V_85 ;
T_1 V_86 , V_87 ;
T_1 V_88 = 0 , V_89 = 0 ;
T_3 V_90 , V_91 ;
if ( ! V_2 ) {
F_30 ( L_12 , V_18 ,
( void * ) V_92 ) ;
return - V_19 ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_88 = V_2 -> V_93 ;
V_89 = V_2 -> V_94 ;
V_83 = ( V_2 -> V_34 << V_95 ) |
V_96 | V_97 ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_83 |= V_98 ;
V_91 = V_99 ;
V_90 = V_100 ;
V_85 = V_10 ;
V_86 = V_64 ;
V_87 = V_60 ;
break;
case V_12 :
V_91 = V_101 ;
V_90 = V_102 ;
V_85 = V_13 ;
V_86 = V_69 ;
V_87 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
V_83 |= ( ( V_89 << V_91 ) | ( V_88 << V_90 ) ) ;
F_1 ( V_2 , V_58 , V_83 ) ;
V_84 = ( V_2 -> V_103 << V_104 ) |
( V_2 -> V_105 << V_106 ) |
( V_2 -> V_107 << V_108 ) ;
F_3 ( V_2 , V_85 , ( V_109 |
V_110 | V_111 ) ,
V_84 ) ;
F_3 ( V_2 , V_85 , ( V_86 | V_87 ) ,
V_86 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
T_1 V_85 ;
T_1 V_86 , V_87 ;
if ( ! V_2 ) {
F_30 ( L_12 , V_18 ,
( void * ) V_92 ) ;
return - V_19 ;
}
switch ( V_2 -> V_8 ) {
case V_9 :
V_85 = V_10 ;
V_86 = V_64 ;
V_87 = V_60 ;
break;
case V_12 :
V_85 = V_13 ;
V_86 = V_69 ;
V_87 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
F_3 ( V_2 , V_58 , V_96 | V_97 , 0 ) ;
F_3 ( V_2 , V_85 , V_86 | V_87 , 0 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
T_1 V_83 , V_112 ;
T_1 V_88 = 0 , V_89 = 0 ;
T_3 V_90 , V_91 ;
if ( ! V_2 ) {
F_30 ( L_12 , V_18 ,
( void * ) V_92 ) ;
return - V_19 ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_88 = V_2 -> V_93 ;
V_89 = V_2 -> V_94 ;
V_83 = ( V_2 -> V_34 << V_95 ) |
V_96 |
( V_2 -> V_113 << V_114 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_83 |= V_98 ;
V_91 = V_99 ;
V_90 = V_100 ;
break;
case V_12 :
V_91 = V_101 ;
V_90 = V_102 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
V_83 |= ( ( V_89 << V_91 ) | ( V_88 << V_90 ) ) ;
F_1 ( V_2 , V_58 , V_83 ) ;
V_112 = ( V_2 -> V_115 << V_116 ) |
( V_2 -> V_117 << V_118 ) ;
F_1 ( V_2 , V_119 , V_112 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
F_3 ( V_2 , V_10 ,
( V_61 | V_62 |
V_63 ) ,
( V_61 | V_54 |
V_62 | V_55 |
V_63 | V_56 ) ) ;
break;
case V_12 :
F_1 ( V_2 , V_24 ,
V_74 | V_75 |
V_76 | V_77 ) ;
F_1 ( V_2 , V_67 ,
V_71 | V_72 |
V_73 | V_68 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_13
L_14 , V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_120 )
{
struct V_121 * V_122 ;
struct V_78 * V_123 ;
int V_47 ;
if ( ! V_2 ) {
F_30 ( L_12 , V_18 ,
( void * ) V_92 ) ;
return - V_19 ;
}
V_122 = F_34 ( V_2 -> V_16 , V_120 ) ;
if ( F_14 ( V_122 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_15
L_16 , V_18 , V_120 ) ;
return F_35 ( V_122 ) ;
}
V_123 = F_28 ( V_2 , V_122 -> V_124 ) ;
if ( ! V_123 ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_17 ,
V_18 , V_120 ) ;
return - V_20 ;
}
V_2 -> V_107 = V_123 -> V_125 ;
F_36 ( & V_2 -> V_25 -> V_26 ) ;
if ( F_5 ( V_2 , V_58 ) & V_59 )
return 0 ;
V_47 = V_28 -> V_41 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_1 ( V_2 , V_126 , V_123 -> V_127 ) ;
F_3 ( V_2 , V_58 , V_59 , V_59 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
F_30 ( L_12 , V_18 ,
( void * ) V_92 ) ;
return;
}
if ( F_38 ( & V_2 -> V_25 -> V_26 ) )
return;
if ( F_5 ( V_2 , V_58 ) & V_59 ) {
switch ( V_2 -> V_8 ) {
case V_9 :
F_25 ( V_2 ) ;
break;
case V_12 :
F_27 ( V_2 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_2 ,
V_2 -> V_8 ) ;
}
}
F_39 ( & V_2 -> V_25 -> V_26 ) ;
}
int F_40 ( struct V_128 * V_129 )
{
struct V_1 * V_17 ;
if ( ! V_129 ) {
F_41 ( L_18 ,
V_18 ) ;
return - V_19 ;
}
if ( V_28 ) {
F_41 ( L_19 ,
V_18 ) ;
return - V_130 ;
}
V_28 = V_129 ;
F_9 (sr_info, &sr_list, node)
F_21 ( V_17 ) ;
return 0 ;
}
void F_42 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_41 ( L_20 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_40 ) || ! ( V_28 -> V_41 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_21
L_22 , V_18 ) ;
return;
}
V_28 -> V_40 ( V_2 ) ;
}
void F_43 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_41 ( L_20 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_43 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_21
L_22 , V_18 ) ;
return;
}
V_28 -> V_43 ( V_2 , 0 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_14 ( V_2 ) ) {
F_41 ( L_20 , V_18 ) ;
return;
}
if ( ! V_2 -> V_42 )
return;
if ( ! V_28 || ! ( V_28 -> V_43 ) ) {
F_19 ( & V_2 -> V_25 -> V_26 , L_21
L_22 , V_18 ) ;
return;
}
V_28 -> V_43 ( V_2 , 1 ) ;
}
void F_45 ( struct V_131 * V_132 )
{
if ( ! V_132 ) {
F_41 ( L_23
L_24 , V_18 ) ;
return;
}
V_133 = V_132 ;
}
static int F_46 ( void * V_22 , T_4 * V_134 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_41 ( L_25 , V_18 ) ;
return - V_19 ;
}
* V_134 = V_17 -> V_42 ;
return 0 ;
}
static int F_47 ( void * V_22 , T_4 V_134 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_41 ( L_25 , V_18 ) ;
return - V_19 ;
}
if ( V_134 > 1 ) {
F_41 ( L_26 , V_18 , V_134 ) ;
return - V_19 ;
}
if ( V_17 -> V_42 != V_134 ) {
if ( ! V_134 )
F_20 ( V_17 ) ;
else
F_18 ( V_17 ) ;
}
return 0 ;
}
static int T_5 F_48 ( struct V_135 * V_25 )
{
struct V_1 * V_17 ;
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_136 * V_137 , * V_21 ;
struct V_138 * V_139 ;
int V_80 , V_47 = 0 ;
V_17 = F_49 ( & V_25 -> V_26 , sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_17 ) {
F_11 ( & V_25 -> V_26 , L_27 ,
V_18 ) ;
return - V_141 ;
}
V_17 -> V_49 = F_49 ( & V_25 -> V_26 ,
V_142 , V_140 ) ;
if ( ! V_17 -> V_49 ) {
F_11 ( & V_25 -> V_26 , L_28 ,
V_18 ) ;
return - V_141 ;
}
F_50 ( V_25 , V_17 ) ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_29 , V_18 ) ;
return - V_19 ;
}
V_137 = F_51 ( V_25 , V_143 , 0 ) ;
V_17 -> V_5 = F_52 ( & V_25 -> V_26 , V_137 ) ;
if ( F_14 ( V_17 -> V_5 ) ) {
F_11 ( & V_25 -> V_26 , L_30 , V_18 ) ;
return F_35 ( V_17 -> V_5 ) ;
}
V_21 = F_51 ( V_25 , V_144 , 0 ) ;
F_53 ( & V_25 -> V_26 ) ;
F_54 ( & V_25 -> V_26 ) ;
snprintf ( V_17 -> V_49 , V_142 , L_31 , V_45 -> V_49 ) ;
V_17 -> V_25 = V_25 ;
V_17 -> V_145 = V_25 -> V_146 ;
V_17 -> V_16 = V_45 -> V_16 ;
V_17 -> V_81 = V_45 -> V_81 ;
V_17 -> V_82 = V_45 -> V_82 ;
V_17 -> V_94 = V_45 -> V_94 ;
V_17 -> V_93 = V_45 -> V_93 ;
V_17 -> V_103 = V_45 -> V_103 ;
V_17 -> V_105 = V_45 -> V_105 ;
V_17 -> V_113 = V_45 -> V_113 ;
V_17 -> V_117 = V_45 -> V_117 ;
V_17 -> V_115 = V_45 -> V_115 ;
V_17 -> V_42 = false ;
V_17 -> V_8 = V_45 -> V_8 ;
if ( V_21 )
V_17 -> V_21 = V_21 -> V_147 ;
F_12 ( V_17 ) ;
F_55 ( & V_17 -> V_51 , & V_148 ) ;
if ( V_28 ) {
V_47 = F_21 ( V_17 ) ;
if ( V_47 ) {
F_41 ( L_32 , V_18 ) ;
goto V_149;
}
}
F_56 ( & V_25 -> V_26 , L_33 , V_18 ) ;
if ( ! V_150 ) {
V_150 = F_57 ( L_34 , NULL ) ;
if ( F_58 ( V_150 ) ) {
V_47 = F_35 ( V_150 ) ;
F_7 ( L_35 ,
V_18 , V_47 ) ;
goto V_149;
}
}
V_17 -> V_151 = F_57 ( V_17 -> V_49 , V_150 ) ;
if ( F_58 ( V_17 -> V_151 ) ) {
F_11 ( & V_25 -> V_26 , L_36 ,
V_18 ) ;
V_47 = F_35 ( V_17 -> V_151 ) ;
goto V_152;
}
( void ) F_59 ( L_37 , V_153 | V_154 ,
V_17 -> V_151 , ( void * ) V_17 , & V_155 ) ;
( void ) F_60 ( L_38 , V_153 , V_17 -> V_151 ,
& V_17 -> V_103 ) ;
( void ) F_60 ( L_39 , V_153 , V_17 -> V_151 ,
& V_17 -> V_105 ) ;
V_139 = F_57 ( L_40 , V_17 -> V_151 ) ;
if ( F_58 ( V_139 ) ) {
F_11 ( & V_25 -> V_26 , L_41
L_42 , V_18 ) ;
V_47 = F_35 ( V_139 ) ;
goto V_152;
}
if ( V_17 -> V_82 == 0 || ! V_17 -> V_81 ) {
F_19 ( & V_25 -> V_26 , L_43 ,
V_18 , V_17 -> V_49 ) ;
V_47 = - V_20 ;
goto V_152;
}
for ( V_80 = 0 ; V_80 < V_17 -> V_82 ; V_80 ++ ) {
char V_49 [ V_156 + 1 ] ;
snprintf ( V_49 , sizeof( V_49 ) , L_44 ,
V_17 -> V_81 [ V_80 ] . V_157 ) ;
( void ) F_60 ( V_49 , V_153 | V_154 , V_139 ,
& ( V_17 -> V_81 [ V_80 ] . V_127 ) ) ;
snprintf ( V_49 , sizeof( V_49 ) , L_45 ,
V_17 -> V_81 [ V_80 ] . V_157 ) ;
( void ) F_60 ( V_49 , V_153 | V_154 , V_139 ,
& ( V_17 -> V_81 [ V_80 ] . V_125 ) ) ;
}
return V_47 ;
V_152:
F_61 ( V_17 -> V_151 ) ;
V_149:
F_24 ( & V_17 -> V_51 ) ;
return V_47 ;
}
static int F_62 ( struct V_135 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_1 * V_17 ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_29 , V_18 ) ;
return - V_19 ;
}
V_17 = F_6 ( V_45 -> V_16 ) ;
if ( F_14 ( V_17 ) ) {
F_19 ( & V_25 -> V_26 , L_25 ,
V_18 ) ;
return F_35 ( V_17 ) ;
}
if ( V_17 -> V_42 )
F_20 ( V_17 ) ;
if ( V_17 -> V_151 )
F_61 ( V_17 -> V_151 ) ;
F_63 ( & V_25 -> V_26 ) ;
F_24 ( & V_17 -> V_51 ) ;
return 0 ;
}
static void F_64 ( struct V_135 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_26 . V_46 ;
struct V_1 * V_17 ;
if ( ! V_45 ) {
F_11 ( & V_25 -> V_26 , L_29 , V_18 ) ;
return;
}
V_17 = F_6 ( V_45 -> V_16 ) ;
if ( F_14 ( V_17 ) ) {
F_19 ( & V_25 -> V_26 , L_25 ,
V_18 ) ;
return;
}
if ( V_17 -> V_42 )
F_20 ( V_17 ) ;
return;
}
static int T_5 F_65 ( void )
{
int V_47 = 0 ;
if ( V_133 && V_133 -> V_158 )
V_133 -> V_158 () ;
else
F_41 ( L_46 , V_18 ) ;
V_47 = F_66 ( & V_159 , F_48 ) ;
if ( V_47 ) {
F_7 ( L_47 ,
V_18 ) ;
return V_47 ;
}
return 0 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_159 ) ;
}
