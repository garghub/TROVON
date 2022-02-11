static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_3 = F_3 ( V_2 -> V_6 , V_7 ) ;
if ( V_3 )
F_4 ( V_2 -> V_4 , L_2
L_3 , V_5 , V_3 ,
V_2 -> V_6 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_9 )
{
if ( ! V_2 -> V_10 && ( V_9 != 0x40 ) )
F_6 ( V_2 -> V_4 , L_4 , V_9 ) ;
switch ( V_9 ) {
case 0x00 :
F_7 ( L_5 ) ;
break;
case 0x20 :
F_7 ( L_6
L_7 ) ;
break;
case 0x21 :
F_7 ( L_8 ) ;
break;
case 0x22 :
F_7 ( L_9 ) ;
break;
case 0x23 :
F_7 ( L_10 ) ;
break;
case 0x28 :
F_7 ( L_11
L_12 ) ;
break;
case 0x29 :
F_7 ( L_13
L_14 ) ;
break;
case 0x30 :
F_7 ( L_15
L_16 ) ;
break;
case 0x40 :
if ( ! V_2 -> V_10 )
F_7 ( L_17 ) ;
break;
case 0x41 :
F_7 ( L_18
L_19 ) ;
break;
case 0x42 :
F_7 ( L_20 ) ;
break;
default:
F_7 ( L_21 ) ;
break;
}
}
static T_1 F_8 ( struct V_11 * V_12 )
{
T_1 V_13 = 0 ;
T_2 V_14 = F_9 ( V_12 -> V_14 ) ;
if ( V_14 != 0 )
V_13 = ( V_15 * F_9 ( V_12 -> V_16 ) ) /
( V_14 * V_17 ) ;
return V_13 ;
}
static T_1 F_10 ( T_1 V_18 )
{
T_1 V_19 = V_18 * 1000 ;
T_1 V_20 = ( V_21 ) / 1000 ;
T_1 V_22 = ( T_1 ) ( V_19 / V_20 ) ;
return V_22 ? V_22 : 1 ;
}
static T_1 F_11 ( T_1 V_23 )
{
T_1 V_22 ;
T_1 V_20 ;
V_23 &= V_24 ;
V_20 = ( V_21 / 1000 ) ;
V_22 = ( T_1 ) ( V_23 * V_20 ) / 1000 ;
return V_22 ? V_22 : 1 ;
}
static void F_12 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
F_4 ( V_2 -> V_4 , L_22 ) ;
F_13 ( V_2 -> V_26 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_27 ) ;
struct V_28 * V_4 ;
unsigned V_29 , V_30 = 0 ;
unsigned V_31 , V_32 , V_33 , V_34 ;
unsigned long V_35 ;
T_1 V_13 ;
if ( ! V_2 ) {
F_16 ( L_23 , V_5 ) ;
return;
}
F_2 ( V_2 -> V_4 , L_24 , V_5 ) ;
V_4 = V_2 -> V_4 ;
V_35 = F_17 ( V_2 -> V_36 ) ;
F_18 ( & V_2 -> V_37 , V_38 + V_35 ) ;
V_13 = F_8 ( & V_2 -> V_12 ) ;
F_4 ( V_4 , L_25 , V_13 ) ;
V_31 = F_9 ( V_2 -> V_12 . V_31 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_33 = V_2 -> V_12 . V_39 [ V_29 ] ;
V_34 = F_19 ( & V_2 -> V_12 . V_40 [ V_33 ] ) ;
V_32 = F_10 ( V_34 ) ;
if ( V_29 % 2 )
V_27 . V_41 = false ;
else
V_27 . V_41 = true ;
V_27 . V_42 = F_20 ( V_32 ) ;
if ( V_29 == 0 )
V_30 = V_27 . V_42 ;
V_27 . V_42 &= V_24 ;
F_4 ( V_4 , L_26 ,
V_27 . V_41 ? L_27 : L_28 , V_27 . V_42 , V_29 ) ;
F_21 ( V_2 -> V_26 , & V_27 ) ;
}
if ( V_29 % 2 ) {
V_27 . V_41 = false ;
if ( V_30 < F_20 ( 1000 ) )
V_27 . V_42 = F_20 ( 2800 ) ;
else
V_27 . V_42 = V_30 ;
F_4 ( V_4 , L_29 ,
V_27 . V_42 ) ;
F_21 ( V_2 -> V_26 , & V_27 ) ;
}
F_4 ( V_4 , L_30 ) ;
F_22 ( V_2 -> V_26 ) ;
}
static T_3 F_23 ( int V_43 , struct V_1 * V_2 )
{
struct V_44 * V_45 ;
T_3 * V_25 ;
int V_3 ;
V_25 = F_24 ( sizeof( T_3 ) , V_46 ) ;
if ( ! V_25 )
return - V_47 ;
V_45 = V_2 -> V_45 ;
V_3 = F_25 ( V_45 , F_26 ( V_45 , 0 ) , V_43 ,
V_48 | V_49 | V_50 ,
0x0000 , 0x0000 , V_25 , sizeof( T_3 ) , V_51 * 10 ) ;
if ( V_3 < 0 ) {
F_27 ( V_2 -> V_4 , L_31 ,
V_5 , V_3 , * V_25 ) ;
V_3 = - V_52 ;
} else
V_3 = V_25 [ 0 ] ;
F_28 ( V_25 ) ;
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
T_3 V_53 ;
F_2 ( V_4 , L_1 , V_5 ) ;
V_53 = F_23 ( V_54 , V_2 ) ;
if ( V_53 != 0 )
F_30 ( V_4 , L_32 ,
V_5 , V_53 ) ;
V_53 = F_23 ( V_55 , V_2 ) ;
if ( V_53 != 1 ) {
F_27 ( V_4 , L_33 ,
V_5 , V_53 ) ;
return - V_52 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
F_2 ( V_2 -> V_4 , L_34 , V_5 ) ;
F_32 ( V_2 -> V_6 ) ;
F_32 ( V_2 -> V_56 ) ;
F_33 ( V_2 -> V_6 ) ;
F_33 ( V_2 -> V_56 ) ;
F_34 ( V_45 , F_35 ( V_2 -> V_57 -> V_58 ) ,
V_2 -> V_59 , V_2 -> V_60 ) ;
F_28 ( V_2 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_4 * V_61 ;
T_1 V_62 = F_37 ( 150 ) ;
int V_63 , V_53 , V_64 ;
V_63 = sizeof( * V_61 ) ;
V_61 = F_24 ( V_63 , V_46 ) ;
if ( ! V_61 ) {
F_38 ( V_2 -> V_4 , L_35 ) ;
return V_62 ;
}
V_64 = F_26 ( V_2 -> V_45 , 0 ) ;
V_53 = F_25 ( V_2 -> V_45 , V_64 , V_65 ,
V_48 | V_49 | V_50 ,
V_66 , 0 , V_61 , V_63 , V_51 * 5 ) ;
if ( V_53 != V_63 )
F_38 ( V_2 -> V_4 , L_36 ) ;
else {
V_62 = F_10 ( F_39 ( V_61 ) ) ;
F_4 ( V_2 -> V_4 , L_37 , V_62 / 1000 ) ;
}
F_28 ( V_61 ) ;
return V_62 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_28 * V_4 = V_2 -> V_4 ;
int V_26 , V_67 , V_68 ;
T_3 * V_34 ;
int V_63 = sizeof( T_3 ) ;
F_2 ( V_4 , L_1 , V_5 ) ;
V_67 = F_26 ( V_45 , 0 ) ;
V_68 = F_41 ( V_45 , 0 ) ;
V_34 = F_42 ( V_63 , V_46 ) ;
if ( ! V_34 ) {
F_27 ( V_4 , L_38 ) ;
return;
}
* V_34 = 0x01 ;
V_26 = F_25 ( V_45 , V_67 , V_69 ,
V_48 | V_49 | V_50 ,
V_70 , 0 , V_34 , V_63 , V_51 * 25 ) ;
F_4 ( V_4 , L_39 , V_26 ) ;
* V_34 = 5 ;
V_26 = F_25 ( V_45 , V_68 , V_71 ,
V_48 | V_49 | V_72 ,
V_73 , 0 , V_34 , V_63 , V_51 * 25 ) ;
F_4 ( V_4 , L_40 , * V_34 , V_26 ) ;
* V_34 = V_74 ;
V_26 = F_25 ( V_45 , V_68 , V_71 ,
V_48 | V_49 | V_72 ,
V_75 , 0 , V_34 , V_63 , V_51 * 25 ) ;
F_4 ( V_4 , L_41 , * V_34 , V_26 ) ;
F_28 ( V_34 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
char * V_76 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_76 = F_24 ( sizeof( char ) * ( V_77 + 1 ) , V_46 ) ;
if ( ! V_76 ) {
F_27 ( V_2 -> V_4 , L_38 ) ;
return;
}
V_26 = F_25 ( V_2 -> V_45 , F_26 ( V_2 -> V_45 , 0 ) ,
V_78 ,
V_48 | V_49 | V_50 ,
0 , 0 , V_76 , V_77 , V_51 * 5 ) ;
if ( V_26 >= 0 )
F_6 ( V_2 -> V_4 , L_42 , V_76 ) ;
else
F_27 ( V_2 -> V_4 , L_43 ) ;
F_28 ( V_76 ) ;
F_2 ( V_2 -> V_4 , L_44 , V_5 ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned V_63 )
{
struct V_79 * V_80 = V_2 -> V_59 ;
unsigned V_81 , V_82 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_81 = F_9 ( V_80 -> V_18 ) ;
V_82 = F_9 ( V_80 -> V_83 ) ;
if ( V_81 > sizeof( V_2 -> V_12 ) ) {
F_38 ( V_2 -> V_4 , L_45 , V_81 ) ;
return;
}
switch ( V_82 ) {
case V_84 :
if ( V_63 >= sizeof( struct V_85 ) ) {
struct V_85 * error = V_2 -> V_59 ;
unsigned V_86 = F_9 ( error -> V_86 ) ;
F_5 ( V_2 , V_86 ) ;
}
break;
case V_87 :
memcpy ( & V_2 -> V_12 , V_2 -> V_59 , V_63 ) ;
V_2 -> V_88 = V_63 ;
F_4 ( V_2 -> V_4 , L_46 ,
V_2 -> V_88 , V_81 ) ;
break;
default:
F_4 ( V_2 -> V_4 , L_47 ,
V_82 , V_63 , V_81 ) ;
break;
}
}
static void F_45 ( struct V_1 * V_2 , unsigned V_63 )
{
void * V_12 = & V_2 -> V_12 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
if ( V_63 + V_2 -> V_88 > sizeof( V_2 -> V_12 ) ) {
F_38 ( V_2 -> V_4 , L_48 ) ;
V_2 -> V_88 = 0 ;
return;
}
memcpy ( V_12 + V_2 -> V_88 , V_2 -> V_59 , V_63 ) ;
V_2 -> V_88 += V_63 ;
F_4 ( V_2 -> V_4 , L_46 , V_2 -> V_88 ,
F_9 ( V_2 -> V_12 . V_80 . V_18 ) ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned V_63 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
unsigned V_82 ;
int V_53 = 0 ;
F_2 ( V_4 , L_1 , V_5 ) ;
if ( V_2 -> V_88 == 0 && V_63 >= sizeof( struct V_79 ) ) {
F_44 ( V_2 , V_63 ) ;
} else if ( V_2 -> V_88 != 0 ) {
F_45 ( V_2 , V_63 ) ;
} else if ( V_2 -> V_88 == 0 ) {
F_27 ( V_4 , L_49 ) ;
V_53 = - V_89 ;
goto V_90;
}
if ( V_2 -> V_88 < F_9 ( V_2 -> V_12 . V_80 . V_18 ) +
sizeof( struct V_79 ) )
return 0 ;
V_82 = F_9 ( V_2 -> V_12 . V_80 . V_83 ) ;
if ( V_82 == V_87 )
F_14 ( V_2 ) ;
else
F_4 ( V_4 , L_50 ,
V_82 ) ;
V_90:
V_2 -> V_88 = 0 ;
return V_53 ;
}
static void F_47 ( struct V_91 * V_91 )
{
struct V_1 * V_2 ;
int V_53 ;
if ( ! V_91 )
return;
V_2 = V_91 -> V_92 ;
if ( ! V_2 ) {
F_16 ( L_51 , V_5 ) ;
F_48 ( V_91 ) ;
return;
}
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
switch ( V_91 -> V_93 ) {
case 0 :
V_53 = F_46 ( V_2 , V_91 -> V_94 ) ;
if ( ! V_53 ) {
F_1 ( V_2 ) ;
}
break;
case - V_95 :
case - V_96 :
case - V_97 :
F_48 ( V_91 ) ;
return;
case - V_98 :
default:
F_38 ( V_2 -> V_4 , L_52 , V_91 -> V_93 ) ;
V_2 -> V_88 = 0 ;
break;
}
}
static T_2 F_49 ( unsigned int V_13 )
{
int V_99 = 6000000 ;
return 65536 - ( V_99 / V_13 ) ;
}
static int F_50 ( struct V_100 * V_101 , T_1 V_102 )
{
struct V_1 * V_2 = V_101 -> V_103 ;
struct V_28 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , L_53 , V_102 ) ;
if ( V_102 == 0 )
return - V_104 ;
V_2 -> V_102 = V_102 ;
return V_102 ;
}
static int F_51 ( struct V_100 * V_101 , unsigned * V_105 ,
unsigned V_106 )
{
struct V_1 * V_2 = V_101 -> V_103 ;
struct V_28 * V_4 = V_2 -> V_4 ;
struct V_11 * V_12 = NULL ;
int V_53 , V_107 ;
int V_108 , V_109 , V_64 ;
int * V_110 = NULL ;
T_3 V_111 = 0 ;
unsigned V_29 , V_112 ;
F_2 ( V_4 , L_1 , V_5 ) ;
if ( V_2 -> V_10 ) {
F_38 ( V_4 , L_54 , V_5 ) ;
return - V_113 ;
}
if ( V_106 > V_114 - V_115 )
return - V_104 ;
V_2 -> V_10 = true ;
V_110 = F_24 ( sizeof( int ) * V_74 , V_46 ) ;
if ( ! V_110 ) {
V_53 = - V_47 ;
goto V_90;
}
V_12 = F_24 ( sizeof( * V_12 ) , V_46 ) ;
if ( ! V_12 ) {
V_53 = - V_47 ;
goto V_90;
}
for ( V_29 = 0 ; V_29 < V_106 ; V_29 ++ ) {
V_109 = F_11 ( V_105 [ V_29 ] ) ;
if ( V_109 > 0xffff ) {
F_38 ( V_4 , L_55 ,
V_105 [ V_29 ] , F_10 ( 0xffff ) ) ;
V_109 = 0xffff ;
}
for ( V_108 = 0 ; V_108 < V_111 ; V_108 ++ ) {
if ( V_110 [ V_108 ] == V_109 )
break;
}
if ( V_108 == V_111 ) {
F_4 ( V_4 , L_56 ,
V_29 , V_105 [ V_29 ] , V_111 , V_109 ) ;
if ( V_111 < V_74 ) {
V_110 [ V_111 ] = V_109 ;
F_52 ( V_109 ,
& V_12 -> V_40 [ V_111 ] ) ;
V_111 ++ ;
} else {
V_53 = - V_104 ;
goto V_90;
}
}
V_12 -> V_39 [ V_29 ] = V_108 ;
}
V_12 -> V_39 [ V_106 ] = V_116 ;
V_12 -> V_39 [ V_106 + 1 ] = V_116 ;
V_112 = F_53 ( struct V_11 ,
V_39 [ V_106 + V_115 ] ) ;
V_12 -> V_80 . V_18 = F_54 ( V_112 -
sizeof( struct V_79 ) ) ;
V_12 -> V_80 . V_83 = F_54 ( V_117 ) ;
V_12 -> V_118 = F_55 ( F_10 ( 100 ) ) ;
V_12 -> V_14 = F_54 ( F_49 ( V_2 -> V_102 ) ) ;
V_12 -> V_119 = V_111 ;
V_12 -> V_31 = F_54 ( V_106 + V_115 ) ;
V_64 = F_56 ( V_2 -> V_45 , V_2 -> V_120 -> V_121 ) ;
V_53 = F_57 ( V_2 -> V_45 , V_64 , V_12 ,
V_112 , & V_107 , 10 * V_51 ) ;
F_4 ( V_4 , L_57 , V_107 , V_53 ) ;
V_64 = F_26 ( V_2 -> V_45 , 0 ) ;
V_53 = F_25 ( V_2 -> V_45 , V_64 , V_122 ,
V_48 | V_49 | V_50 ,
0 , 0 , V_12 , 2 , V_51 * 10 ) ;
if ( V_53 < 0 )
F_27 ( V_4 , L_58 , V_53 ) ;
else
V_53 = V_106 ;
V_90:
F_28 ( V_110 ) ;
F_28 ( V_12 ) ;
V_2 -> V_10 = false ;
return V_53 ;
}
static void F_58 ( struct V_123 * V_124 , enum
V_125 V_126 )
{
struct V_1 * V_2 = F_59 ( V_124 , struct V_1 ,
V_127 ) ;
if ( V_126 != V_128 && F_60 ( & V_2 -> V_129 , 0 , 1 ) == 0 ) {
int V_53 = F_3 ( V_2 -> V_56 , V_7 ) ;
if ( V_53 != 0 ) {
F_30 ( V_2 -> V_4 , L_32 ,
V_5 , V_53 ) ;
F_61 ( & V_2 -> V_129 , 0 ) ;
}
}
}
static void F_62 ( struct V_91 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
switch ( V_91 -> V_93 ) {
case 0 :
break;
case - V_95 :
case - V_96 :
case - V_97 :
F_48 ( V_91 ) ;
return;
case - V_98 :
default:
F_30 ( V_2 -> V_4 , L_52 , V_91 -> V_93 ) ;
break;
}
V_2 -> V_127 . V_126 = V_128 ;
F_63 ( & V_2 -> V_129 ) ;
}
static struct V_100 * F_64 ( struct V_1 * V_2 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
struct V_100 * V_26 ;
int V_53 = - V_130 ;
T_2 V_131 = F_35 ( V_2 -> V_45 -> V_132 . V_133 ) ;
V_26 = F_65 () ;
if ( ! V_26 ) {
F_27 ( V_4 , L_59 ) ;
goto V_90;
}
snprintf ( V_2 -> V_134 , sizeof( V_2 -> V_134 ) , L_60
L_61 ,
V_131 == V_135 ? L_62 : L_63 ,
F_35 ( V_2 -> V_45 -> V_132 . V_136 ) , V_131 ) ;
F_66 ( V_2 -> V_45 , V_2 -> V_137 , sizeof( V_2 -> V_137 ) ) ;
V_26 -> V_138 = V_2 -> V_134 ;
V_26 -> V_139 = V_2 -> V_137 ;
F_67 ( V_2 -> V_45 , & V_26 -> V_140 ) ;
V_26 -> V_4 . V_141 = V_4 ;
V_26 -> V_103 = V_2 ;
V_26 -> V_142 = V_143 ;
V_26 -> V_144 = V_145 ;
V_26 -> V_62 = F_20 ( 2750 ) ;
V_26 -> V_146 = F_51 ;
V_26 -> V_147 = F_50 ;
V_26 -> V_148 = V_149 ;
V_26 -> V_150 = F_20 ( 2 ) ;
V_26 -> V_151 = V_152 ;
V_53 = F_68 ( V_26 ) ;
if ( V_53 < 0 ) {
F_27 ( V_4 , L_64 ) ;
goto V_90;
}
return V_26 ;
V_90:
F_69 ( V_26 ) ;
return NULL ;
}
static int F_70 ( struct V_153 * V_154 ,
const struct V_155 * V_156 )
{
struct V_44 * V_45 = F_71 ( V_154 ) ;
struct V_28 * V_4 = & V_154 -> V_4 ;
struct V_157 * V_158 ;
struct V_1 * V_2 ;
struct V_159 * V_160 ;
struct V_159 * V_57 = NULL ;
struct V_159 * V_120 = NULL ;
T_3 V_161 , V_162 ;
int V_64 , V_29 ;
int V_163 = - V_47 ;
F_2 ( V_4 , L_65 , V_5 ) ;
V_158 = V_154 -> V_164 ;
for ( V_29 = 0 ; V_29 < V_158 -> V_165 . V_166 ; ++ V_29 ) {
V_160 = & V_158 -> V_167 [ V_29 ] . V_165 ;
V_161 = V_160 -> V_121 ;
V_162 = V_160 -> V_168 ;
if ( ( V_57 == NULL ) &&
( ( V_161 & V_169 ) == V_50 ) &&
( ( V_162 & V_170 ) ==
V_171 ) ) {
F_4 ( V_4 , L_66 ,
V_160 -> V_121 ) ;
if ( V_160 -> V_121 == V_172 )
V_57 = V_160 ;
}
if ( ( V_120 == NULL ) &&
( ( V_161 & V_169 ) == V_72 ) &&
( ( V_162 & V_170 ) ==
V_171 ) ) {
F_4 ( V_4 , L_67 ,
V_160 -> V_121 ) ;
V_120 = V_160 ;
}
}
if ( ! V_57 || ! V_120 ) {
F_27 ( V_4 , L_68 ) ;
V_163 = - V_130 ;
goto V_173;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_46 ) ;
if ( V_2 == NULL ) {
F_27 ( V_4 , L_38 ) ;
goto V_173;
}
V_2 -> V_4 = & V_154 -> V_4 ;
V_2 -> V_6 = F_72 ( 0 , V_46 ) ;
if ( ! V_2 -> V_6 ) {
F_27 ( V_4 , L_69 ) ;
goto error;
}
V_2 -> V_57 = V_57 ;
V_2 -> V_59 = F_73 ( V_45 ,
F_35 ( V_57 -> V_58 ) , V_7 , & V_2 -> V_60 ) ;
if ( ! V_2 -> V_59 ) {
F_27 ( V_4 , L_70 ) ;
goto error;
}
V_64 = F_74 ( V_45 , V_57 -> V_121 ) ;
F_75 ( V_2 -> V_6 , V_45 , V_64 , V_2 -> V_59 ,
F_35 ( V_57 -> V_58 ) , F_47 , V_2 ) ;
V_2 -> V_120 = V_120 ;
V_2 -> V_45 = V_45 ;
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
V_163 = F_29 ( V_2 ) ;
if ( V_163 < 0 )
goto error;
V_2 -> V_36 = F_36 ( V_2 ) ;
V_2 -> V_102 = 38000 ;
V_2 -> V_127 . V_134 = L_71 ;
V_2 -> V_127 . V_174 = L_72 ;
V_2 -> V_127 . V_175 = F_58 ;
V_163 = F_76 ( & V_154 -> V_4 , & V_2 -> V_127 ) ;
if ( V_163 )
goto error;
F_61 ( & V_2 -> V_129 , 0 ) ;
V_2 -> V_56 = F_72 ( 0 , V_46 ) ;
if ( ! V_2 -> V_56 ) {
V_163 = - V_47 ;
goto V_176;
}
V_2 -> V_177 . V_178 = 0xc0 ;
V_2 -> V_177 . V_179 = V_180 ;
V_2 -> V_177 . V_181 = F_77 ( 1 ) ;
F_78 ( V_2 -> V_56 , V_45 , F_26 ( V_45 , 0 ) ,
( unsigned char * ) & V_2 -> V_177 ,
& V_2 -> V_182 , sizeof( V_2 -> V_182 ) ,
F_62 , V_2 ) ;
V_2 -> V_26 = F_64 ( V_2 ) ;
if ( ! V_2 -> V_26 ) {
V_163 = - V_47 ;
goto V_176;
}
F_79 ( & V_2 -> V_37 , F_12 , ( unsigned long ) V_2 ) ;
F_80 ( V_154 , V_2 ) ;
F_2 ( V_4 , L_44 , V_5 ) ;
return 0 ;
V_176:
F_81 ( & V_2 -> V_127 ) ;
error:
F_31 ( V_2 , V_2 -> V_45 ) ;
V_173:
F_27 ( V_4 , L_73 , V_5 , V_163 ) ;
return V_163 ;
}
static void F_82 ( struct V_153 * V_154 )
{
struct V_44 * V_45 = F_71 ( V_154 ) ;
struct V_1 * V_2 = F_83 ( V_154 ) ;
F_2 ( & V_154 -> V_4 , L_1 , V_5 ) ;
if ( ! V_2 )
return;
F_80 ( V_154 , NULL ) ;
F_84 ( V_2 -> V_26 ) ;
F_81 ( & V_2 -> V_127 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_31 ( V_2 , V_45 ) ;
F_2 ( & V_154 -> V_4 , L_74 ) ;
}
static int F_86 ( struct V_153 * V_154 , T_5 V_183 )
{
struct V_1 * V_2 = F_83 ( V_154 ) ;
F_2 ( V_2 -> V_4 , L_75 ) ;
F_87 ( & V_2 -> V_127 ) ;
F_32 ( V_2 -> V_6 ) ;
F_32 ( V_2 -> V_56 ) ;
return 0 ;
}
static int F_88 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_83 ( V_154 ) ;
F_2 ( V_2 -> V_4 , L_76 ) ;
if ( F_3 ( V_2 -> V_6 , V_7 ) )
return - V_52 ;
F_89 ( & V_2 -> V_127 ) ;
return 0 ;
}
