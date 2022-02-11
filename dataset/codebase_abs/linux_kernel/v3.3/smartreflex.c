static inline void F_1 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_4 )
{
F_2 ( V_4 , ( V_2 -> V_5 + V_3 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_6 ,
T_1 V_4 )
{
T_1 V_7 ;
T_1 V_8 = 0 , V_9 = 0 ;
V_7 = F_4 ( V_2 -> V_5 + V_3 ) ;
V_7 &= ~ V_6 ;
if ( V_2 -> V_10 == V_11 ) {
V_8 = V_12 ;
V_9 = V_13 ;
} else if ( V_2 -> V_10 == V_14 ) {
V_8 = V_15 ;
V_9 = V_16 ;
}
if ( V_3 == V_8 )
V_7 &= ~ V_9 ;
V_7 |= V_4 ;
F_2 ( V_7 , ( V_2 -> V_5 + V_3 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static struct V_1 * F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_19 ;
if ( ! V_18 ) {
F_7 ( L_1 , V_20 ) ;
return F_8 ( - V_21 ) ;
}
F_9 (sr_info, &sr_list, node) {
if ( V_18 == V_19 -> V_18 )
return V_19 ;
}
return F_8 ( - V_22 ) ;
}
static T_2 F_10 ( int V_23 , void * V_24 )
{
struct V_1 * V_19 = (struct V_1 * ) V_24 ;
T_1 V_25 = 0 ;
if ( V_19 -> V_10 == V_11 ) {
V_25 = F_5 ( V_19 , V_12 ) ;
F_1 ( V_19 , V_12 , V_25 ) ;
} else if ( V_19 -> V_10 == V_14 ) {
V_25 = F_5 ( V_19 , V_26 ) ;
F_1 ( V_19 , V_26 , V_25 ) ;
}
if ( V_27 -> V_28 )
V_27 -> V_28 ( V_19 -> V_18 , V_25 ) ;
return V_29 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
T_1 V_32 ;
if ( F_12 () )
V_31 = F_13 ( NULL , L_2 ) ;
else
V_31 = F_13 ( NULL , L_3 ) ;
if ( F_14 ( V_31 ) ) {
F_15 ( & V_2 -> V_33 -> V_34 , L_4 ,
V_20 ) ;
return;
}
V_32 = F_16 ( V_31 ) ;
F_17 ( V_31 ) ;
switch ( V_32 ) {
case 12000000 :
V_2 -> V_35 = V_36 ;
break;
case 13000000 :
V_2 -> V_35 = V_37 ;
break;
case 19200000 :
V_2 -> V_35 = V_38 ;
break;
case 26000000 :
V_2 -> V_35 = V_39 ;
break;
case 38400000 :
V_2 -> V_35 = V_40 ;
break;
default:
F_15 ( & V_2 -> V_33 -> V_34 , L_5 ,
V_20 , V_32 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( F_12 () || F_19 () ) {
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
if ( ! ( strcmp ( V_2 -> V_18 -> V_47 , L_6 ) ) ) {
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_51 ;
} else {
V_2 -> V_48 = V_52 ;
V_2 -> V_50 = V_53 ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_27 || ! ( V_27 -> V_54 ) || ! ( V_27 -> V_55 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_7 ,
V_20 ) ;
return;
}
if ( ! V_27 -> V_54 ( V_2 -> V_18 ) )
V_2 -> V_56 = true ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! V_27 || ! ( V_27 -> V_57 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 ,
L_7 ,
V_20 ) ;
return;
}
if ( V_2 -> V_56 ) {
V_27 -> V_57 ( V_2 -> V_18 , 1 ) ;
V_2 -> V_56 = false ;
}
}
static int F_23 ( struct V_1 * V_19 )
{
char * V_47 ;
struct V_58 * V_59 = V_19 -> V_33 -> V_34 . V_60 ;
struct V_61 * V_62 ;
int V_63 = 0 ;
if ( V_27 -> V_28 && V_27 -> V_64 && V_19 -> V_23 ) {
V_47 = F_24 ( V_65 , L_8 , V_19 -> V_18 -> V_47 ) ;
if ( V_47 == NULL ) {
V_63 = - V_66 ;
goto error;
}
V_63 = F_25 ( V_19 -> V_23 , F_10 ,
0 , V_47 , ( void * ) V_19 ) ;
if ( V_63 )
goto error;
F_26 ( V_19 -> V_23 ) ;
}
if ( V_59 && V_59 -> V_67 )
F_20 ( V_19 ) ;
return V_63 ;
error:
F_27 ( V_19 -> V_5 ) ;
V_62 = F_28 ( V_19 -> V_33 , V_68 , 0 ) ;
F_29 ( V_62 -> V_69 , F_30 ( V_62 ) ) ;
F_31 ( & V_19 -> V_70 ) ;
F_15 ( & V_19 -> V_33 -> V_34 , L_9
L_10
L_11 , V_20 ) ;
F_32 ( V_47 ) ;
F_32 ( V_19 ) ;
return V_63 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
F_3 ( V_2 , V_12 ,
V_72 , V_72 ) ;
F_3 ( V_2 , V_73 , V_74 , 0x0 ) ;
F_3 ( V_2 , V_12 ,
( V_75 | V_76 |
V_77 | V_78 ) ,
( V_79 | V_80 |
V_81 |
V_82 ) ) ;
F_34 ( ( F_5 ( V_2 , V_12 ) &
V_83 ) , V_84 ,
V_71 ) ;
if ( V_71 >= V_84 )
F_21 ( & V_2 -> V_33 -> V_34 , L_12 ,
V_20 ) ;
F_3 ( V_2 , V_12 , V_72 ,
V_83 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
F_1 ( V_2 , V_85 , V_86 ) ;
F_3 ( V_2 , V_73 , V_74 , 0x0 ) ;
F_3 ( V_2 , V_15 , V_87 ,
V_16 ) ;
F_1 ( V_2 , V_88 , ( V_89 |
V_90 |
V_91 ) ) ;
F_1 ( V_2 , V_26 , ( V_92 |
V_93 |
V_94 ) ) ;
F_34 ( ( F_5 ( V_2 , V_26 ) &
V_95 ) , V_84 ,
V_71 ) ;
if ( V_71 >= V_84 )
F_21 ( & V_2 -> V_33 -> V_34 , L_12 ,
V_20 ) ;
F_1 ( V_2 , V_88 , V_86 ) ;
F_1 ( V_2 , V_26 , V_95 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , T_1 V_96 )
{
int V_97 ;
if ( ! V_2 -> V_98 ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_13 ,
V_20 ) ;
return 0 ;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_99 ; V_97 ++ ) {
if ( V_2 -> V_98 [ V_97 ] . V_96 == V_96 )
return V_2 -> V_98 [ V_97 ] . V_100 ;
}
return 0 ;
}
int F_37 ( struct V_17 * V_18 )
{
T_1 V_101 , V_102 , V_8 , V_103 ;
T_1 V_104 , V_105 = 0 , V_106 = 0 ;
T_3 V_107 , V_108 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_35 )
F_11 ( V_2 ) ;
V_105 = V_2 -> V_109 ;
V_106 = V_2 -> V_110 ;
V_101 = ( V_2 -> V_35 << V_111 ) |
V_112 | V_113 ;
if ( V_2 -> V_10 == V_11 ) {
V_101 |= V_114 ;
V_108 = V_115 ;
V_107 = V_116 ;
V_8 = V_12 ;
V_103 = V_78 ;
V_104 = V_82 ;
} else if ( V_2 -> V_10 == V_14 ) {
V_108 = V_117 ;
V_107 = V_118 ;
V_8 = V_15 ;
V_103 = V_87 ;
V_104 = V_16 ;
} else {
F_15 ( & V_2 -> V_33 -> V_34 , L_15
L_16 , V_20 ) ;
return - V_21 ;
}
V_101 |= ( ( V_106 << V_108 ) | ( V_105 << V_107 ) ) ;
F_1 ( V_2 , V_73 , V_101 ) ;
V_102 = ( V_2 -> V_41 << V_119 ) |
( V_2 -> V_43 << V_120 ) |
( V_2 -> V_121 << V_122 ) ;
F_3 ( V_2 , V_8 , ( V_123 |
V_124 | V_125 ) ,
V_102 ) ;
F_3 ( V_2 , V_8 ,
V_103 , ( V_103 | V_104 ) ) ;
return 0 ;
}
int F_39 ( struct V_17 * V_18 )
{
T_1 V_101 , V_126 ;
T_1 V_105 = 0 , V_106 = 0 ;
T_3 V_107 , V_108 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_35 )
F_11 ( V_2 ) ;
V_105 = V_2 -> V_109 ;
V_106 = V_2 -> V_110 ;
V_101 = ( V_2 -> V_35 << V_111 ) |
V_112 |
( V_2 -> V_45 << V_127 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_101 |= V_114 ;
V_108 = V_115 ;
V_107 = V_116 ;
} else if ( V_2 -> V_10 == V_14 ) {
V_108 = V_117 ;
V_107 = V_118 ;
} else {
F_15 ( & V_2 -> V_33 -> V_34 , L_15
L_16 , V_20 ) ;
return - V_21 ;
}
V_101 |= ( ( V_106 << V_108 ) | ( V_105 << V_107 ) ) ;
F_1 ( V_2 , V_73 , V_101 ) ;
V_126 = ( V_2 -> V_50 << V_128 ) |
( V_2 -> V_48 << V_129 ) ;
F_1 ( V_2 , V_130 , V_126 ) ;
if ( V_2 -> V_10 == V_11 ) {
F_3 ( V_2 , V_12 ,
( V_75 | V_76 |
V_77 ) ,
( V_75 | V_79 |
V_76 | V_80 |
V_77 | V_81 ) ) ;
} else if ( V_2 -> V_10 == V_14 ) {
F_1 ( V_2 , V_26 ,
V_92 | V_93 |
V_94 | V_95 ) ;
F_1 ( V_2 , V_85 ,
V_89 | V_90 |
V_91 | V_86 ) ;
}
return 0 ;
}
int F_40 ( struct V_17 * V_18 , unsigned long V_131 )
{
T_1 V_132 ;
struct V_133 * V_134 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_63 ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return - V_21 ;
}
V_134 = F_41 ( V_2 -> V_18 , V_131 ) ;
if ( F_14 ( V_134 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_17
L_18 , V_20 , V_131 ) ;
return - V_22 ;
}
V_132 = F_36 ( V_2 , V_134 -> V_135 ) ;
if ( ! V_132 ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_19 ,
V_20 , V_131 ) ;
return - V_22 ;
}
V_2 -> V_121 = V_134 -> V_136 ;
F_42 ( & V_2 -> V_33 -> V_34 ) ;
if ( F_5 ( V_2 , V_73 ) & V_74 )
return 0 ;
V_63 = V_27 -> V_55 ( V_18 ) ;
if ( V_63 )
return V_63 ;
F_1 ( V_2 , V_137 , V_132 ) ;
F_3 ( V_2 , V_73 , V_74 , V_74 ) ;
return 0 ;
}
void F_43 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return;
}
if ( F_44 ( & V_2 -> V_33 -> V_34 ) )
return;
if ( F_5 ( V_2 , V_73 ) & V_74 ) {
if ( V_2 -> V_10 == V_11 )
F_33 ( V_2 ) ;
else if ( V_2 -> V_10 == V_14 )
F_35 ( V_2 ) ;
}
F_45 ( & V_2 -> V_33 -> V_34 ) ;
}
int F_46 ( struct V_138 * V_139 )
{
struct V_1 * V_19 ;
if ( ! V_139 ) {
F_38 ( L_20 ,
V_20 ) ;
return - V_21 ;
}
if ( V_27 ) {
F_38 ( L_21 ,
V_20 ) ;
return - V_140 ;
}
V_27 = V_139 ;
F_9 (sr_info, &sr_list, node)
F_23 ( V_19 ) ;
return 0 ;
}
void F_47 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return;
}
if ( ! V_2 -> V_56 )
return;
if ( ! V_27 || ! ( V_27 -> V_54 ) || ! ( V_27 -> V_55 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_54 ( V_18 ) ;
}
void F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return;
}
if ( ! V_2 -> V_56 )
return;
if ( ! V_27 || ! ( V_27 -> V_57 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_57 ( V_18 , 0 ) ;
}
void F_49 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_38 ( L_14 ,
V_20 , V_18 -> V_47 ) ;
return;
}
if ( ! V_2 -> V_56 )
return;
if ( ! V_27 || ! ( V_27 -> V_57 ) ) {
F_21 ( & V_2 -> V_33 -> V_34 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_57 ( V_18 , 1 ) ;
}
void F_50 ( struct V_141 * V_142 )
{
if ( ! V_142 ) {
F_38 ( L_24
L_25 , V_20 ) ;
return;
}
V_143 = V_142 ;
}
static int F_51 ( void * V_24 , T_4 * V_144 )
{
struct V_1 * V_19 = (struct V_1 * ) V_24 ;
if ( ! V_19 ) {
F_38 ( L_26 , V_20 ) ;
return - V_21 ;
}
* V_144 = V_19 -> V_56 ;
return 0 ;
}
static int F_52 ( void * V_24 , T_4 V_144 )
{
struct V_1 * V_19 = (struct V_1 * ) V_24 ;
if ( ! V_19 ) {
F_38 ( L_26 , V_20 ) ;
return - V_21 ;
}
if ( V_144 && ( V_144 != 1 ) ) {
F_38 ( L_27 , V_20 , V_144 ) ;
return - V_21 ;
}
if ( V_19 -> V_56 != V_144 ) {
if ( ! V_144 )
F_22 ( V_19 ) ;
else
F_20 ( V_19 ) ;
}
return 0 ;
}
static int T_5 F_53 ( struct V_145 * V_33 )
{
struct V_1 * V_19 = F_54 ( sizeof( struct V_1 ) , V_65 ) ;
struct V_58 * V_59 = V_33 -> V_34 . V_60 ;
struct V_61 * V_62 , * V_23 ;
struct V_146 * V_147 ;
struct V_133 * V_134 ;
int V_97 , V_63 = 0 ;
char * V_47 ;
if ( ! V_19 ) {
F_15 ( & V_33 -> V_34 , L_28 ,
V_20 ) ;
return - V_66 ;
}
if ( ! V_59 ) {
F_15 ( & V_33 -> V_34 , L_29 , V_20 ) ;
V_63 = - V_21 ;
goto V_148;
}
V_62 = F_28 ( V_33 , V_68 , 0 ) ;
if ( ! V_62 ) {
F_15 ( & V_33 -> V_34 , L_30 , V_20 ) ;
V_63 = - V_149 ;
goto V_148;
}
V_62 = F_55 ( V_62 -> V_69 , F_30 ( V_62 ) ,
F_56 ( & V_33 -> V_34 ) ) ;
if ( ! V_62 ) {
F_15 ( & V_33 -> V_34 , L_31 , V_20 ) ;
V_63 = - V_140 ;
goto V_148;
}
V_23 = F_28 ( V_33 , V_150 , 0 ) ;
F_57 ( & V_33 -> V_34 ) ;
F_58 ( & V_33 -> V_34 ) ;
V_19 -> V_33 = V_33 ;
V_19 -> V_151 = V_33 -> V_152 ;
V_19 -> V_18 = V_59 -> V_18 ;
V_19 -> V_98 = V_59 -> V_98 ;
V_19 -> V_99 = V_59 -> V_99 ;
V_19 -> V_110 = V_59 -> V_110 ;
V_19 -> V_109 = V_59 -> V_109 ;
V_19 -> V_56 = false ;
V_19 -> V_10 = V_59 -> V_10 ;
V_19 -> V_5 = F_59 ( V_62 -> V_69 , F_30 ( V_62 ) ) ;
if ( ! V_19 -> V_5 ) {
F_15 ( & V_33 -> V_34 , L_32 , V_20 ) ;
V_63 = - V_66 ;
goto V_153;
}
if ( V_23 )
V_19 -> V_23 = V_23 -> V_69 ;
F_11 ( V_19 ) ;
F_18 ( V_19 ) ;
F_60 ( & V_19 -> V_70 , & V_154 ) ;
if ( V_27 ) {
V_63 = F_23 ( V_19 ) ;
if ( V_63 ) {
F_38 ( L_33 , V_20 ) ;
goto V_155;
}
}
F_61 ( & V_33 -> V_34 , L_34 , V_20 ) ;
if ( ! V_156 ) {
V_156 = F_62 ( L_35 , NULL ) ;
if ( ! V_156 ) {
V_63 = F_63 ( V_156 ) ;
F_7 ( L_36 ,
V_20 , V_63 ) ;
goto V_155;
}
}
V_47 = F_24 ( V_65 , L_8 , V_19 -> V_18 -> V_47 ) ;
if ( ! V_47 ) {
F_15 ( & V_33 -> V_34 , L_37 ,
V_20 ) ;
V_63 = - V_66 ;
goto V_155;
}
V_19 -> V_157 = F_62 ( V_47 , V_156 ) ;
F_32 ( V_47 ) ;
if ( F_14 ( V_19 -> V_157 ) ) {
F_15 ( & V_33 -> V_34 , L_38 ,
V_20 ) ;
V_63 = F_63 ( V_19 -> V_157 ) ;
goto V_155;
}
( void ) F_64 ( L_39 , V_158 | V_159 ,
V_19 -> V_157 , ( void * ) V_19 , & V_160 ) ;
( void ) F_65 ( L_40 , V_158 , V_19 -> V_157 ,
& V_19 -> V_41 ) ;
( void ) F_65 ( L_41 , V_158 , V_19 -> V_157 ,
& V_19 -> V_43 ) ;
( void ) F_65 ( L_42 , V_158 , V_19 -> V_157 ,
& V_19 -> V_121 ) ;
V_147 = F_62 ( L_43 , V_19 -> V_157 ) ;
if ( F_14 ( V_147 ) ) {
F_15 ( & V_33 -> V_34 , L_44
L_45 , V_20 ) ;
V_63 = F_63 ( V_147 ) ;
goto V_161;
}
F_66 ( V_19 -> V_18 , & V_134 ) ;
if ( ! V_134 ) {
F_21 ( & V_33 -> V_34 , L_46
L_47
L_48 ,
V_20 , V_19 -> V_18 -> V_47 ) ;
V_63 = - V_22 ;
goto V_161;
}
for ( V_97 = 0 ; V_97 < V_19 -> V_99 ; V_97 ++ ) {
char V_47 [ V_162 + 1 ] ;
snprintf ( V_47 , sizeof( V_47 ) , L_49 ,
V_134 [ V_97 ] . V_163 ) ;
( void ) F_65 ( V_47 , V_158 | V_159 , V_147 ,
& ( V_19 -> V_98 [ V_97 ] . V_100 ) ) ;
}
return V_63 ;
V_161:
F_67 ( V_19 -> V_157 ) ;
V_155:
F_31 ( & V_19 -> V_70 ) ;
F_27 ( V_19 -> V_5 ) ;
V_153:
F_29 ( V_62 -> V_69 , F_30 ( V_62 ) ) ;
V_148:
F_32 ( V_19 ) ;
return V_63 ;
}
static int T_6 F_68 ( struct V_145 * V_33 )
{
struct V_58 * V_59 = V_33 -> V_34 . V_60 ;
struct V_1 * V_19 ;
struct V_61 * V_62 ;
if ( ! V_59 ) {
F_15 ( & V_33 -> V_34 , L_29 , V_20 ) ;
return - V_21 ;
}
V_19 = F_6 ( V_59 -> V_18 ) ;
if ( F_14 ( V_19 ) ) {
F_21 ( & V_33 -> V_34 , L_26 ,
V_20 ) ;
return - V_21 ;
}
if ( V_19 -> V_56 )
F_22 ( V_19 ) ;
if ( V_19 -> V_157 )
F_67 ( V_19 -> V_157 ) ;
F_31 ( & V_19 -> V_70 ) ;
F_27 ( V_19 -> V_5 ) ;
F_32 ( V_19 ) ;
V_62 = F_28 ( V_33 , V_68 , 0 ) ;
F_29 ( V_62 -> V_69 , F_30 ( V_62 ) ) ;
return 0 ;
}
static int T_5 F_69 ( void )
{
int V_63 = 0 ;
if ( V_143 && V_143 -> V_164 )
V_143 -> V_164 () ;
else
F_38 ( L_50 , V_20 ) ;
V_63 = F_70 ( & V_165 , F_53 ) ;
if ( V_63 ) {
F_7 ( L_51 ,
V_20 ) ;
return V_63 ;
}
return 0 ;
}
static void T_7 F_71 ( void )
{
F_72 ( & V_165 ) ;
}
