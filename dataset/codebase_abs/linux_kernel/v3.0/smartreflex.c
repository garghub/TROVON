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
F_5 ( V_19 , V_26 ) ;
F_1 ( V_19 , V_26 , V_25 ) ;
}
if ( V_27 -> V_28 == V_29 && V_27 -> V_30 )
V_27 -> V_30 ( V_19 -> V_18 , V_25 ) ;
return V_31 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
T_1 V_34 ;
if ( F_12 () )
V_33 = F_13 ( NULL , L_2 ) ;
else
V_33 = F_13 ( NULL , L_3 ) ;
if ( F_14 ( V_33 ) ) {
F_15 ( & V_2 -> V_35 -> V_36 , L_4 ,
V_20 ) ;
return;
}
V_34 = F_16 ( V_33 ) ;
F_17 ( V_33 ) ;
switch ( V_34 ) {
case 12000000 :
V_2 -> V_37 = V_38 ;
break;
case 13000000 :
V_2 -> V_37 = V_39 ;
break;
case 19200000 :
V_2 -> V_37 = V_40 ;
break;
case 26000000 :
V_2 -> V_37 = V_41 ;
break;
case 38400000 :
V_2 -> V_37 = V_42 ;
break;
default:
F_15 ( & V_2 -> V_35 -> V_36 , L_5 ,
V_20 , V_34 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( F_12 () || F_19 () ) {
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_48 ;
if ( ! ( strcmp ( V_2 -> V_18 -> V_49 , L_6 ) ) ) {
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = V_53 ;
} else {
V_2 -> V_50 = V_54 ;
V_2 -> V_52 = V_55 ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_27 || ! ( V_27 -> V_56 ) || ! ( V_27 -> V_57 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 ,
L_7 ,
V_20 ) ;
return;
}
if ( ! V_27 -> V_56 ( V_2 -> V_18 ) )
V_2 -> V_58 = true ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! V_27 || ! ( V_27 -> V_59 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 ,
L_7 ,
V_20 ) ;
return;
}
if ( V_2 -> V_58 ) {
V_27 -> V_59 ( V_2 -> V_18 , 1 ) ;
V_2 -> V_58 = false ;
}
}
static int F_23 ( struct V_1 * V_19 )
{
char * V_49 ;
struct V_60 * V_61 = V_19 -> V_35 -> V_36 . V_62 ;
struct V_63 * V_64 ;
int V_65 = 0 ;
if ( V_27 -> V_28 == V_29 &&
V_27 -> V_66 && V_19 -> V_23 ) {
V_49 = F_24 ( V_67 , L_8 , V_19 -> V_18 -> V_49 ) ;
if ( V_49 == NULL ) {
V_65 = - V_68 ;
goto error;
}
V_65 = F_25 ( V_19 -> V_23 , F_10 ,
0 , V_49 , ( void * ) V_19 ) ;
if ( V_65 )
goto error;
}
if ( V_61 && V_61 -> V_69 )
F_20 ( V_19 ) ;
return V_65 ;
error:
F_26 ( V_19 -> V_5 ) ;
V_64 = F_27 ( V_19 -> V_35 , V_70 , 0 ) ;
F_28 ( V_64 -> V_71 , F_29 ( V_64 ) ) ;
F_30 ( & V_19 -> V_72 ) ;
F_15 ( & V_19 -> V_35 -> V_36 , L_9
L_10
L_11 , V_20 ) ;
F_31 ( V_49 ) ;
F_31 ( V_19 ) ;
return V_65 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_73 = 0 ;
F_3 ( V_2 , V_12 ,
V_74 , V_74 ) ;
F_3 ( V_2 , V_75 , V_76 , 0x0 ) ;
F_3 ( V_2 , V_12 ,
( V_77 | V_78 |
V_79 | V_80 ) ,
( V_81 | V_82 |
V_83 |
V_84 ) ) ;
F_33 ( ( F_5 ( V_2 , V_12 ) &
V_85 ) , V_86 ,
V_73 ) ;
if ( V_73 >= V_86 )
F_21 ( & V_2 -> V_35 -> V_36 , L_12 ,
V_20 ) ;
F_3 ( V_2 , V_12 , V_74 ,
V_85 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_73 = 0 ;
F_1 ( V_2 , V_87 , V_88 ) ;
F_3 ( V_2 , V_75 , V_76 , 0x0 ) ;
F_3 ( V_2 , V_15 , V_89 ,
V_16 ) ;
F_1 ( V_2 , V_90 , ( V_91 |
V_92 |
V_93 ) ) ;
F_1 ( V_2 , V_26 , ( V_94 |
V_95 |
V_96 ) ) ;
F_33 ( ( F_5 ( V_2 , V_26 ) &
V_97 ) , V_86 ,
V_73 ) ;
if ( V_73 >= V_86 )
F_21 ( & V_2 -> V_35 -> V_36 , L_12 ,
V_20 ) ;
F_1 ( V_2 , V_90 , V_88 ) ;
F_1 ( V_2 , V_26 , V_97 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_1 V_98 )
{
int V_99 ;
if ( ! V_2 -> V_100 ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_13 ,
V_20 ) ;
return 0 ;
}
for ( V_99 = 0 ; V_99 < V_2 -> V_101 ; V_99 ++ ) {
if ( V_2 -> V_100 [ V_99 ] . V_98 == V_98 )
return V_2 -> V_100 [ V_99 ] . V_102 ;
}
return 0 ;
}
int F_36 ( struct V_17 * V_18 )
{
T_1 V_103 , V_104 , V_8 , V_105 ;
T_1 V_106 , V_107 = 0 , V_108 = 0 ;
T_3 V_109 , V_110 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_37 )
F_11 ( V_2 ) ;
V_107 = V_2 -> V_111 ;
V_108 = V_2 -> V_112 ;
V_103 = ( V_2 -> V_37 << V_113 ) |
V_114 | V_115 ;
if ( V_2 -> V_10 == V_11 ) {
V_103 |= V_116 ;
V_110 = V_117 ;
V_109 = V_118 ;
V_8 = V_12 ;
V_105 = V_80 ;
V_106 = V_84 ;
} else if ( V_2 -> V_10 == V_14 ) {
V_110 = V_119 ;
V_109 = V_120 ;
V_8 = V_15 ;
V_105 = V_89 ;
V_106 = V_16 ;
} else {
F_15 ( & V_2 -> V_35 -> V_36 , L_15
L_16 , V_20 ) ;
return - V_21 ;
}
V_103 |= ( ( V_108 << V_110 ) | ( V_107 << V_109 ) ) ;
F_1 ( V_2 , V_75 , V_103 ) ;
V_104 = ( V_2 -> V_43 << V_121 ) |
( V_2 -> V_45 << V_122 ) |
( V_2 -> V_123 << V_124 ) ;
F_3 ( V_2 , V_8 , ( V_125 |
V_126 | V_127 ) ,
V_104 ) ;
F_3 ( V_2 , V_8 ,
V_105 , ( V_105 | V_106 ) ) ;
return 0 ;
}
int F_38 ( struct V_17 * V_18 )
{
T_1 V_103 , V_128 ;
T_1 V_107 = 0 , V_108 = 0 ;
T_3 V_109 , V_110 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_37 )
F_11 ( V_2 ) ;
V_107 = V_2 -> V_111 ;
V_108 = V_2 -> V_112 ;
V_103 = ( V_2 -> V_37 << V_113 ) |
V_114 |
( V_2 -> V_47 << V_129 ) ;
if ( V_2 -> V_10 == V_11 ) {
V_103 |= V_116 ;
V_110 = V_117 ;
V_109 = V_118 ;
} else if ( V_2 -> V_10 == V_14 ) {
V_110 = V_119 ;
V_109 = V_120 ;
} else {
F_15 ( & V_2 -> V_35 -> V_36 , L_15
L_16 , V_20 ) ;
return - V_21 ;
}
V_103 |= ( ( V_108 << V_110 ) | ( V_107 << V_109 ) ) ;
F_1 ( V_2 , V_75 , V_103 ) ;
V_128 = ( V_2 -> V_52 << V_130 ) |
( V_2 -> V_50 << V_131 ) ;
F_1 ( V_2 , V_132 , V_128 ) ;
if ( V_2 -> V_10 == V_11 ) {
F_3 ( V_2 , V_12 ,
( V_77 | V_78 |
V_79 ) ,
( V_77 | V_81 |
V_78 | V_82 |
V_79 | V_83 ) ) ;
} else if ( V_2 -> V_10 == V_14 ) {
F_1 ( V_2 , V_26 ,
V_94 | V_95 |
V_96 | V_97 ) ;
F_1 ( V_2 , V_87 ,
V_91 | V_92 |
V_93 | V_88 ) ;
}
return 0 ;
}
int F_39 ( struct V_17 * V_18 , unsigned long V_133 )
{
T_1 V_134 ;
struct V_135 * V_136 ;
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_65 ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return - V_21 ;
}
V_136 = F_40 ( V_2 -> V_18 , V_133 ) ;
if ( F_14 ( V_136 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_17
L_18 , V_20 , V_133 ) ;
return - V_22 ;
}
V_134 = F_35 ( V_2 , V_136 -> V_137 ) ;
if ( ! V_134 ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_19 ,
V_20 , V_133 ) ;
return - V_22 ;
}
V_2 -> V_123 = V_136 -> V_138 ;
F_41 ( & V_2 -> V_35 -> V_36 ) ;
if ( F_5 ( V_2 , V_75 ) & V_76 )
return 0 ;
V_65 = V_27 -> V_57 ( V_18 ) ;
if ( V_65 )
return V_65 ;
F_1 ( V_2 , V_139 , V_134 ) ;
F_3 ( V_2 , V_75 , V_76 , V_76 ) ;
return 0 ;
}
void F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return;
}
if ( F_43 ( & V_2 -> V_35 -> V_36 ) )
return;
if ( F_5 ( V_2 , V_75 ) & V_76 ) {
if ( V_2 -> V_10 == V_11 )
F_32 ( V_2 ) ;
else if ( V_2 -> V_10 == V_14 )
F_34 ( V_2 ) ;
}
F_44 ( & V_2 -> V_35 -> V_36 ) ;
}
int F_45 ( struct V_140 * V_141 )
{
struct V_1 * V_19 ;
if ( ! V_141 ) {
F_37 ( L_20 ,
V_20 ) ;
return - V_21 ;
}
if ( V_27 ) {
F_37 ( L_21 ,
V_20 ) ;
return - V_142 ;
}
V_27 = V_141 ;
F_9 (sr_info, &sr_list, node)
F_23 ( V_19 ) ;
return 0 ;
}
void F_46 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return;
}
if ( ! V_2 -> V_58 )
return;
if ( ! V_27 || ! ( V_27 -> V_56 ) || ! ( V_27 -> V_57 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_56 ( V_18 ) ;
}
void F_47 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return;
}
if ( ! V_2 -> V_58 )
return;
if ( ! V_27 || ! ( V_27 -> V_59 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_59 ( V_18 , 0 ) ;
}
void F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_37 ( L_14 ,
V_20 , V_18 -> V_49 ) ;
return;
}
if ( ! V_2 -> V_58 )
return;
if ( ! V_27 || ! ( V_27 -> V_59 ) ) {
F_21 ( & V_2 -> V_35 -> V_36 , L_22
L_23 , V_20 ) ;
return;
}
V_27 -> V_59 ( V_18 , 1 ) ;
}
void F_49 ( struct V_143 * V_144 )
{
if ( ! V_144 ) {
F_37 ( L_24
L_25 , V_20 ) ;
return;
}
V_145 = V_144 ;
}
static int F_50 ( void * V_24 , T_4 * V_146 )
{
struct V_1 * V_19 = (struct V_1 * ) V_24 ;
if ( ! V_19 ) {
F_37 ( L_26 , V_20 ) ;
return - V_21 ;
}
* V_146 = V_19 -> V_58 ;
return 0 ;
}
static int F_51 ( void * V_24 , T_4 V_146 )
{
struct V_1 * V_19 = (struct V_1 * ) V_24 ;
if ( ! V_19 ) {
F_37 ( L_26 , V_20 ) ;
return - V_21 ;
}
if ( V_146 && ( V_146 != 1 ) ) {
F_37 ( L_27 , V_20 , V_146 ) ;
return - V_21 ;
}
if ( ! V_146 )
F_22 ( V_19 ) ;
else
F_20 ( V_19 ) ;
return 0 ;
}
static int T_5 F_52 ( struct V_147 * V_35 )
{
struct V_1 * V_19 = F_53 ( sizeof( struct V_1 ) , V_67 ) ;
struct V_60 * V_61 = V_35 -> V_36 . V_62 ;
struct V_63 * V_64 , * V_23 ;
struct V_148 * V_149 , * V_150 ;
struct V_135 * V_136 ;
int V_99 , V_65 = 0 ;
if ( ! V_19 ) {
F_15 ( & V_35 -> V_36 , L_28 ,
V_20 ) ;
return - V_68 ;
}
if ( ! V_61 ) {
F_15 ( & V_35 -> V_36 , L_29 , V_20 ) ;
V_65 = - V_21 ;
goto V_151;
}
V_64 = F_27 ( V_35 , V_70 , 0 ) ;
if ( ! V_64 ) {
F_15 ( & V_35 -> V_36 , L_30 , V_20 ) ;
V_65 = - V_152 ;
goto V_151;
}
V_64 = F_54 ( V_64 -> V_71 , F_29 ( V_64 ) ,
F_55 ( & V_35 -> V_36 ) ) ;
if ( ! V_64 ) {
F_15 ( & V_35 -> V_36 , L_31 , V_20 ) ;
V_65 = - V_142 ;
goto V_151;
}
V_23 = F_27 ( V_35 , V_153 , 0 ) ;
F_56 ( & V_35 -> V_36 ) ;
V_19 -> V_35 = V_35 ;
V_19 -> V_154 = V_35 -> V_155 ;
V_19 -> V_18 = V_61 -> V_18 ;
V_19 -> V_100 = V_61 -> V_100 ;
V_19 -> V_101 = V_61 -> V_101 ;
V_19 -> V_112 = V_61 -> V_112 ;
V_19 -> V_111 = V_61 -> V_111 ;
V_19 -> V_58 = false ;
V_19 -> V_10 = V_61 -> V_10 ;
V_19 -> V_5 = F_57 ( V_64 -> V_71 , F_29 ( V_64 ) ) ;
if ( ! V_19 -> V_5 ) {
F_15 ( & V_35 -> V_36 , L_32 , V_20 ) ;
V_65 = - V_68 ;
goto V_156;
}
if ( V_23 )
V_19 -> V_23 = V_23 -> V_71 ;
F_11 ( V_19 ) ;
F_18 ( V_19 ) ;
F_58 ( & V_19 -> V_72 , & V_157 ) ;
if ( V_27 ) {
V_65 = F_23 ( V_19 ) ;
if ( V_65 ) {
F_37 ( L_33 , V_20 ) ;
return V_65 ;
}
}
F_59 ( & V_35 -> V_36 , L_34 , V_20 ) ;
V_149 = F_60 ( V_19 -> V_18 ) ;
if ( ! V_149 ) {
V_65 = - V_21 ;
goto V_158;
}
V_19 -> V_159 = F_61 ( L_35 , V_149 ) ;
if ( F_14 ( V_19 -> V_159 ) ) {
F_15 ( & V_35 -> V_36 , L_36 ,
V_20 ) ;
V_65 = F_62 ( V_19 -> V_159 ) ;
goto V_158;
}
( void ) F_63 ( L_37 , V_160 | V_161 ,
V_19 -> V_159 , ( void * ) V_19 , & V_162 ) ;
( void ) F_64 ( L_38 , V_160 , V_19 -> V_159 ,
& V_19 -> V_43 ) ;
( void ) F_64 ( L_39 , V_160 , V_19 -> V_159 ,
& V_19 -> V_45 ) ;
( void ) F_64 ( L_40 , V_160 , V_19 -> V_159 ,
& V_19 -> V_123 ) ;
V_150 = F_61 ( L_41 , V_19 -> V_159 ) ;
if ( F_14 ( V_150 ) ) {
F_15 ( & V_35 -> V_36 , L_42
L_43 , V_20 ) ;
V_65 = F_62 ( V_150 ) ;
goto V_163;
}
F_65 ( V_19 -> V_18 , & V_136 ) ;
if ( ! V_136 ) {
F_21 ( & V_35 -> V_36 , L_44
L_45
L_46 ,
V_20 , V_19 -> V_18 -> V_49 ) ;
V_65 = - V_22 ;
goto V_163;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_101 ; V_99 ++ ) {
char V_49 [ V_164 + 1 ] ;
snprintf ( V_49 , sizeof( V_49 ) , L_47 ,
V_136 [ V_99 ] . V_165 ) ;
( void ) F_64 ( V_49 , V_160 | V_161 , V_150 ,
& ( V_19 -> V_100 [ V_99 ] . V_102 ) ) ;
}
return V_65 ;
V_163:
F_66 ( V_19 -> V_159 ) ;
V_158:
F_30 ( & V_19 -> V_72 ) ;
F_26 ( V_19 -> V_5 ) ;
V_156:
F_28 ( V_64 -> V_71 , F_29 ( V_64 ) ) ;
V_151:
F_31 ( V_19 ) ;
return V_65 ;
}
static int T_6 F_67 ( struct V_147 * V_35 )
{
struct V_60 * V_61 = V_35 -> V_36 . V_62 ;
struct V_1 * V_19 ;
struct V_63 * V_64 ;
if ( ! V_61 ) {
F_15 ( & V_35 -> V_36 , L_29 , V_20 ) ;
return - V_21 ;
}
V_19 = F_6 ( V_61 -> V_18 ) ;
if ( F_14 ( V_19 ) ) {
F_21 ( & V_35 -> V_36 , L_26 ,
V_20 ) ;
return - V_21 ;
}
if ( V_19 -> V_58 )
F_22 ( V_19 ) ;
if ( V_19 -> V_159 )
F_66 ( V_19 -> V_159 ) ;
F_30 ( & V_19 -> V_72 ) ;
F_26 ( V_19 -> V_5 ) ;
F_31 ( V_19 ) ;
V_64 = F_27 ( V_35 , V_70 , 0 ) ;
F_28 ( V_64 -> V_71 , F_29 ( V_64 ) ) ;
return 0 ;
}
static int T_5 F_68 ( void )
{
int V_65 = 0 ;
if ( V_145 && V_145 -> V_166 )
V_145 -> V_166 () ;
else
F_37 ( L_48 , V_20 ) ;
V_65 = F_69 ( & V_167 , F_52 ) ;
if ( V_65 ) {
F_7 ( L_49 ,
V_20 ) ;
return V_65 ;
}
return 0 ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_167 ) ;
}
