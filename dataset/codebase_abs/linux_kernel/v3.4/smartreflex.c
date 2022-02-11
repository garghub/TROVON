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
V_28 -> V_29 ( V_17 -> V_16 , V_23 ) ;
return V_30 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
T_1 V_33 ;
if ( F_13 () )
V_32 = F_14 ( NULL , L_3 ) ;
else
V_32 = F_14 ( NULL , L_4 ) ;
if ( F_15 ( V_32 ) ) {
F_11 ( & V_2 -> V_25 -> V_26 , L_5 ,
V_18 ) ;
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
F_11 ( & V_2 -> V_25 -> V_26 , L_6 ,
V_18 , V_33 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( F_13 () || F_19 () ) {
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_45 ;
if ( ! ( strcmp ( V_2 -> V_16 -> V_46 , L_7 ) ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = V_50 ;
} else {
V_2 -> V_47 = V_51 ;
V_2 -> V_49 = V_52 ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_28 || ! ( V_28 -> V_53 ) || ! ( V_28 -> V_54 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 ,
L_8 ,
V_18 ) ;
return;
}
if ( ! V_28 -> V_53 ( V_2 -> V_16 ) )
V_2 -> V_55 = true ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! V_28 || ! ( V_28 -> V_56 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 ,
L_8 ,
V_18 ) ;
return;
}
if ( V_2 -> V_55 ) {
V_28 -> V_56 ( V_2 -> V_16 , 1 ) ;
V_2 -> V_55 = false ;
}
}
static int F_23 ( struct V_1 * V_17 )
{
char * V_46 ;
struct V_57 * V_58 = V_17 -> V_25 -> V_26 . V_59 ;
struct V_60 * V_61 ;
int V_62 = 0 ;
if ( V_28 -> V_29 && V_28 -> V_63 && V_17 -> V_21 ) {
V_46 = F_24 ( V_64 , L_9 , V_17 -> V_16 -> V_46 ) ;
if ( V_46 == NULL ) {
V_62 = - V_65 ;
goto error;
}
V_62 = F_25 ( V_17 -> V_21 , F_10 ,
0 , V_46 , V_17 ) ;
if ( V_62 )
goto error;
F_26 ( V_17 -> V_21 ) ;
}
if ( V_58 && V_58 -> V_66 )
F_20 ( V_17 ) ;
return V_62 ;
error:
F_27 ( V_17 -> V_5 ) ;
V_61 = F_28 ( V_17 -> V_25 , V_67 , 0 ) ;
F_29 ( V_61 -> V_68 , F_30 ( V_61 ) ) ;
F_31 ( & V_17 -> V_69 ) ;
F_11 ( & V_17 -> V_25 -> V_26 , L_10
L_11
L_12 , V_18 ) ;
F_32 ( V_46 ) ;
F_32 ( V_17 ) ;
return V_62 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_70 = 0 ;
int V_71 = V_72 | V_73 |
V_74 ;
F_3 ( V_2 , V_10 ,
V_75 , V_75 ) ;
F_3 ( V_2 , V_76 , V_77 , 0x0 ) ;
if ( F_5 ( V_2 , V_10 ) & V_78 )
V_71 |= V_78 ;
F_3 ( V_2 , V_10 ,
( V_79 | V_80 |
V_81 | V_82 ) ,
V_71 ) ;
F_34 ( ( F_5 ( V_2 , V_10 ) &
V_83 ) , V_84 ,
V_70 ) ;
if ( V_70 >= V_84 )
F_21 ( & V_2 -> V_25 -> V_26 , L_13 ,
V_18 ) ;
F_3 ( V_2 , V_10 , V_75 ,
V_83 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_70 = 0 ;
F_1 ( V_2 , V_85 , V_86 ) ;
F_3 ( V_2 , V_76 , V_77 , 0x0 ) ;
if ( F_5 ( V_2 , V_13 ) & V_14 )
F_3 ( V_2 , V_13 , V_87 ,
V_14 ) ;
else
F_3 ( V_2 , V_13 , V_87 ,
0x0 ) ;
F_1 ( V_2 , V_88 , ( V_89 |
V_90 |
V_91 ) ) ;
F_1 ( V_2 , V_24 , ( V_92 |
V_93 |
V_94 ) ) ;
F_34 ( ( F_5 ( V_2 , V_24 ) &
V_95 ) , V_84 ,
V_70 ) ;
if ( V_70 >= V_84 )
F_21 ( & V_2 -> V_25 -> V_26 , L_13 ,
V_18 ) ;
F_1 ( V_2 , V_88 , V_86 ) ;
F_1 ( V_2 , V_24 , V_95 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_1 V_96 )
{
int V_97 ;
if ( ! V_2 -> V_98 ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_14 ,
V_18 ) ;
return 0 ;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_99 ; V_97 ++ ) {
if ( V_2 -> V_98 [ V_97 ] . V_96 == V_96 )
return V_2 -> V_98 [ V_97 ] . V_100 ;
}
return 0 ;
}
int F_37 ( struct V_15 * V_16 )
{
T_1 V_101 , V_102 , V_103 ;
T_1 V_104 , V_105 ;
T_1 V_106 = 0 , V_107 = 0 ;
T_3 V_108 , V_109 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return F_39 ( V_2 ) ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_106 = V_2 -> V_110 ;
V_107 = V_2 -> V_111 ;
V_101 = ( V_2 -> V_34 << V_112 ) |
V_113 | V_114 ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_101 |= V_115 ;
V_109 = V_116 ;
V_108 = V_117 ;
V_103 = V_10 ;
V_104 = V_82 ;
V_105 = V_78 ;
break;
case V_12 :
V_109 = V_118 ;
V_108 = V_119 ;
V_103 = V_13 ;
V_104 = V_87 ;
V_105 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_16
L_17 , V_18 ) ;
return - V_19 ;
}
V_101 |= ( ( V_107 << V_109 ) | ( V_106 << V_108 ) ) ;
F_1 ( V_2 , V_76 , V_101 ) ;
V_102 = ( V_2 -> V_40 << V_120 ) |
( V_2 -> V_42 << V_121 ) |
( V_2 -> V_122 << V_123 ) ;
F_3 ( V_2 , V_103 , ( V_124 |
V_125 | V_126 ) ,
V_102 ) ;
F_3 ( V_2 , V_103 , ( V_104 | V_105 ) ,
V_104 ) ;
return 0 ;
}
int F_40 ( struct V_15 * V_16 )
{
T_1 V_103 ;
T_1 V_104 , V_105 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return F_39 ( V_2 ) ;
}
switch ( V_2 -> V_8 ) {
case V_9 :
V_103 = V_10 ;
V_104 = V_82 ;
V_105 = V_78 ;
break;
case V_12 :
V_103 = V_13 ;
V_104 = V_87 ;
V_105 = V_14 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_16
L_17 , V_18 ) ;
return - V_19 ;
}
F_3 ( V_2 , V_103 , V_104 | V_105 , 0 ) ;
F_3 ( V_2 , V_76 , V_113 | V_114 , 0 ) ;
return 0 ;
}
int F_41 ( struct V_15 * V_16 )
{
T_1 V_101 , V_127 ;
T_1 V_106 = 0 , V_107 = 0 ;
T_3 V_108 , V_109 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return F_39 ( V_2 ) ;
}
if ( ! V_2 -> V_34 )
F_12 ( V_2 ) ;
V_106 = V_2 -> V_110 ;
V_107 = V_2 -> V_111 ;
V_101 = ( V_2 -> V_34 << V_112 ) |
V_113 |
( V_2 -> V_44 << V_128 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_101 |= V_115 ;
V_109 = V_116 ;
V_108 = V_117 ;
break;
case V_12 :
V_109 = V_118 ;
V_108 = V_119 ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_16
L_17 , V_18 ) ;
return - V_19 ;
}
V_101 |= ( ( V_107 << V_109 ) | ( V_106 << V_108 ) ) ;
F_1 ( V_2 , V_76 , V_101 ) ;
V_127 = ( V_2 -> V_49 << V_129 ) |
( V_2 -> V_47 << V_130 ) ;
F_1 ( V_2 , V_131 , V_127 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
F_3 ( V_2 , V_10 ,
( V_79 | V_80 |
V_81 ) ,
( V_79 | V_72 |
V_80 | V_73 |
V_81 | V_74 ) ) ;
break;
case V_12 :
F_1 ( V_2 , V_24 ,
V_92 | V_93 |
V_94 | V_95 ) ;
F_1 ( V_2 , V_85 ,
V_89 | V_90 |
V_91 | V_86 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_16
L_17 , V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int F_42 ( struct V_15 * V_16 , unsigned long V_132 )
{
struct V_133 * V_134 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
T_1 V_135 ;
int V_62 ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return F_39 ( V_2 ) ;
}
V_134 = F_43 ( V_2 -> V_16 , V_132 ) ;
if ( F_15 ( V_134 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_18
L_19 , V_18 , V_132 ) ;
return F_39 ( V_134 ) ;
}
V_135 = F_36 ( V_2 , V_134 -> V_136 ) ;
if ( ! V_135 ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_20 ,
V_18 , V_132 ) ;
return - V_20 ;
}
V_2 -> V_122 = V_134 -> V_137 ;
F_44 ( & V_2 -> V_25 -> V_26 ) ;
if ( F_5 ( V_2 , V_76 ) & V_77 )
return 0 ;
V_62 = V_28 -> V_54 ( V_16 ) ;
if ( V_62 )
return V_62 ;
F_1 ( V_2 , V_138 , V_135 ) ;
F_3 ( V_2 , V_76 , V_77 , V_77 ) ;
return 0 ;
}
void F_45 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return;
}
if ( F_46 ( & V_2 -> V_25 -> V_26 ) )
return;
if ( F_5 ( V_2 , V_76 ) & V_77 ) {
switch ( V_2 -> V_8 ) {
case V_9 :
F_33 ( V_2 ) ;
break;
case V_12 :
F_35 ( V_2 ) ;
break;
default:
F_11 ( & V_2 -> V_25 -> V_26 , L_2 ,
V_2 -> V_8 ) ;
}
}
F_47 ( & V_2 -> V_25 -> V_26 ) ;
}
int F_48 ( struct V_139 * V_140 )
{
struct V_1 * V_17 ;
if ( ! V_140 ) {
F_38 ( L_21 ,
V_18 ) ;
return - V_19 ;
}
if ( V_28 ) {
F_38 ( L_22 ,
V_18 ) ;
return - V_141 ;
}
V_28 = V_140 ;
F_9 (sr_info, &sr_list, node)
F_23 ( V_17 ) ;
return 0 ;
}
void F_49 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return;
}
if ( ! V_2 -> V_55 )
return;
if ( ! V_28 || ! ( V_28 -> V_53 ) || ! ( V_28 -> V_54 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_23
L_24 , V_18 ) ;
return;
}
V_28 -> V_53 ( V_16 ) ;
}
void F_50 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return;
}
if ( ! V_2 -> V_55 )
return;
if ( ! V_28 || ! ( V_28 -> V_56 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_23
L_24 , V_18 ) ;
return;
}
V_28 -> V_56 ( V_16 , 0 ) ;
}
void F_51 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
if ( F_15 ( V_2 ) ) {
F_38 ( L_15 ,
V_18 , V_16 -> V_46 ) ;
return;
}
if ( ! V_2 -> V_55 )
return;
if ( ! V_28 || ! ( V_28 -> V_56 ) ) {
F_21 ( & V_2 -> V_25 -> V_26 , L_23
L_24 , V_18 ) ;
return;
}
V_28 -> V_56 ( V_16 , 1 ) ;
}
void F_52 ( struct V_142 * V_143 )
{
if ( ! V_143 ) {
F_38 ( L_25
L_26 , V_18 ) ;
return;
}
V_144 = V_143 ;
}
static int F_53 ( void * V_22 , T_4 * V_145 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_38 ( L_27 , V_18 ) ;
return - V_19 ;
}
* V_145 = V_17 -> V_55 ;
return 0 ;
}
static int F_54 ( void * V_22 , T_4 V_145 )
{
struct V_1 * V_17 = V_22 ;
if ( ! V_17 ) {
F_38 ( L_27 , V_18 ) ;
return - V_19 ;
}
if ( V_145 > 1 ) {
F_38 ( L_28 , V_18 , V_145 ) ;
return - V_19 ;
}
if ( V_17 -> V_55 != V_145 ) {
if ( ! V_145 )
F_22 ( V_17 ) ;
else
F_20 ( V_17 ) ;
}
return 0 ;
}
static int T_5 F_55 ( struct V_146 * V_25 )
{
struct V_1 * V_17 ;
struct V_57 * V_58 = V_25 -> V_26 . V_59 ;
struct V_60 * V_61 , * V_21 ;
struct V_147 * V_148 ;
struct V_133 * V_134 ;
int V_97 , V_62 = 0 ;
char * V_46 ;
V_17 = F_56 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_17 ) {
F_11 ( & V_25 -> V_26 , L_29 ,
V_18 ) ;
return - V_65 ;
}
F_57 ( V_25 , V_17 ) ;
if ( ! V_58 ) {
F_11 ( & V_25 -> V_26 , L_30 , V_18 ) ;
V_62 = - V_19 ;
goto V_149;
}
V_61 = F_28 ( V_25 , V_67 , 0 ) ;
if ( ! V_61 ) {
F_11 ( & V_25 -> V_26 , L_31 , V_18 ) ;
V_62 = - V_150 ;
goto V_149;
}
V_61 = F_58 ( V_61 -> V_68 , F_30 ( V_61 ) ,
F_59 ( & V_25 -> V_26 ) ) ;
if ( ! V_61 ) {
F_11 ( & V_25 -> V_26 , L_32 , V_18 ) ;
V_62 = - V_141 ;
goto V_149;
}
V_21 = F_28 ( V_25 , V_151 , 0 ) ;
F_60 ( & V_25 -> V_26 ) ;
F_61 ( & V_25 -> V_26 ) ;
V_17 -> V_25 = V_25 ;
V_17 -> V_152 = V_25 -> V_153 ;
V_17 -> V_16 = V_58 -> V_16 ;
V_17 -> V_98 = V_58 -> V_98 ;
V_17 -> V_99 = V_58 -> V_99 ;
V_17 -> V_111 = V_58 -> V_111 ;
V_17 -> V_110 = V_58 -> V_110 ;
V_17 -> V_55 = false ;
V_17 -> V_8 = V_58 -> V_8 ;
V_17 -> V_5 = F_62 ( V_61 -> V_68 , F_30 ( V_61 ) ) ;
if ( ! V_17 -> V_5 ) {
F_11 ( & V_25 -> V_26 , L_33 , V_18 ) ;
V_62 = - V_65 ;
goto V_154;
}
if ( V_21 )
V_17 -> V_21 = V_21 -> V_68 ;
F_12 ( V_17 ) ;
F_18 ( V_17 ) ;
F_63 ( & V_17 -> V_69 , & V_155 ) ;
if ( V_28 ) {
V_62 = F_23 ( V_17 ) ;
if ( V_62 ) {
F_38 ( L_34 , V_18 ) ;
goto V_156;
}
}
F_64 ( & V_25 -> V_26 , L_35 , V_18 ) ;
if ( ! V_157 ) {
V_157 = F_65 ( L_36 , NULL ) ;
if ( F_66 ( V_157 ) ) {
V_62 = F_39 ( V_157 ) ;
F_7 ( L_37 ,
V_18 , V_62 ) ;
goto V_156;
}
}
V_46 = F_24 ( V_64 , L_9 , V_17 -> V_16 -> V_46 ) ;
if ( ! V_46 ) {
F_11 ( & V_25 -> V_26 , L_38 ,
V_18 ) ;
V_62 = - V_65 ;
goto V_156;
}
V_17 -> V_158 = F_65 ( V_46 , V_157 ) ;
F_32 ( V_46 ) ;
if ( F_66 ( V_17 -> V_158 ) ) {
F_11 ( & V_25 -> V_26 , L_39 ,
V_18 ) ;
V_62 = F_39 ( V_17 -> V_158 ) ;
goto V_156;
}
( void ) F_67 ( L_40 , V_159 | V_160 ,
V_17 -> V_158 , ( void * ) V_17 , & V_161 ) ;
( void ) F_68 ( L_41 , V_159 , V_17 -> V_158 ,
& V_17 -> V_40 ) ;
( void ) F_68 ( L_42 , V_159 , V_17 -> V_158 ,
& V_17 -> V_42 ) ;
( void ) F_68 ( L_43 , V_159 , V_17 -> V_158 ,
& V_17 -> V_122 ) ;
V_148 = F_65 ( L_44 , V_17 -> V_158 ) ;
if ( F_66 ( V_148 ) ) {
F_11 ( & V_25 -> V_26 , L_45
L_46 , V_18 ) ;
V_62 = F_39 ( V_148 ) ;
goto V_162;
}
F_69 ( V_17 -> V_16 , & V_134 ) ;
if ( ! V_134 ) {
F_21 ( & V_25 -> V_26 , L_47
L_48
L_49 ,
V_18 , V_17 -> V_16 -> V_46 ) ;
V_62 = - V_20 ;
goto V_162;
}
for ( V_97 = 0 ; V_97 < V_17 -> V_99 ; V_97 ++ ) {
char V_46 [ V_163 + 1 ] ;
snprintf ( V_46 , sizeof( V_46 ) , L_50 ,
V_134 [ V_97 ] . V_164 ) ;
( void ) F_68 ( V_46 , V_159 | V_160 , V_148 ,
& ( V_17 -> V_98 [ V_97 ] . V_100 ) ) ;
}
return V_62 ;
V_162:
F_70 ( V_17 -> V_158 ) ;
V_156:
F_31 ( & V_17 -> V_69 ) ;
F_27 ( V_17 -> V_5 ) ;
V_154:
F_29 ( V_61 -> V_68 , F_30 ( V_61 ) ) ;
V_149:
F_32 ( V_17 ) ;
return V_62 ;
}
static int T_6 F_71 ( struct V_146 * V_25 )
{
struct V_57 * V_58 = V_25 -> V_26 . V_59 ;
struct V_1 * V_17 ;
struct V_60 * V_61 ;
if ( ! V_58 ) {
F_11 ( & V_25 -> V_26 , L_30 , V_18 ) ;
return - V_19 ;
}
V_17 = F_6 ( V_58 -> V_16 ) ;
if ( F_15 ( V_17 ) ) {
F_21 ( & V_25 -> V_26 , L_27 ,
V_18 ) ;
return F_39 ( V_17 ) ;
}
if ( V_17 -> V_55 )
F_22 ( V_17 ) ;
if ( V_17 -> V_158 )
F_70 ( V_17 -> V_158 ) ;
F_31 ( & V_17 -> V_69 ) ;
F_27 ( V_17 -> V_5 ) ;
F_32 ( V_17 ) ;
V_61 = F_28 ( V_25 , V_67 , 0 ) ;
F_29 ( V_61 -> V_68 , F_30 ( V_61 ) ) ;
return 0 ;
}
static void T_6 F_72 ( struct V_146 * V_25 )
{
struct V_57 * V_58 = V_25 -> V_26 . V_59 ;
struct V_1 * V_17 ;
if ( ! V_58 ) {
F_11 ( & V_25 -> V_26 , L_30 , V_18 ) ;
return;
}
V_17 = F_6 ( V_58 -> V_16 ) ;
if ( F_15 ( V_17 ) ) {
F_21 ( & V_25 -> V_26 , L_27 ,
V_18 ) ;
return;
}
if ( V_17 -> V_55 )
F_22 ( V_17 ) ;
return;
}
static int T_5 F_73 ( void )
{
int V_62 = 0 ;
if ( V_144 && V_144 -> V_165 )
V_144 -> V_165 () ;
else
F_38 ( L_51 , V_18 ) ;
V_62 = F_74 ( & V_166 , F_55 ) ;
if ( V_62 ) {
F_7 ( L_52 ,
V_18 ) ;
return V_62 ;
}
return 0 ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_166 ) ;
}
