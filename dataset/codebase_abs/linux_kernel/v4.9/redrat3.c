static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 )
F_3 ( V_2 -> V_6 ,
L_1 ,
V_7 , V_3 , V_2 -> V_4 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_9 )
{
if ( ! V_2 -> V_10 && ( V_9 != 0x40 ) )
F_5 ( V_2 -> V_6 , L_2 , V_9 ) ;
switch ( V_9 ) {
case 0x00 :
F_6 ( L_3 ) ;
break;
case 0x20 :
F_6 ( L_4
L_5 ) ;
break;
case 0x21 :
F_6 ( L_6 ) ;
break;
case 0x22 :
F_6 ( L_7 ) ;
break;
case 0x23 :
F_6 ( L_8 ) ;
break;
case 0x28 :
F_6 ( L_9
L_10 ) ;
break;
case 0x29 :
F_6 ( L_11
L_12 ) ;
break;
case 0x30 :
F_6 ( L_13
L_14 ) ;
break;
case 0x40 :
if ( ! V_2 -> V_10 )
F_6 ( L_15 ) ;
break;
case 0x41 :
F_6 ( L_16
L_17 ) ;
break;
case 0x42 :
F_6 ( L_18 ) ;
break;
default:
F_6 ( L_19 ) ;
break;
}
}
static T_1 F_7 ( struct V_11 * V_12 )
{
T_1 V_13 = 0 ;
T_2 V_14 = F_8 ( V_12 -> V_14 ) ;
if ( V_14 != 0 )
V_13 = ( V_15 * F_8 ( V_12 -> V_16 ) ) /
( V_14 * V_17 ) ;
return V_13 ;
}
static T_1 F_9 ( T_1 V_18 )
{
T_1 V_19 = V_18 * 1000 ;
T_1 V_20 = ( V_21 ) / 1000 ;
T_1 V_22 = ( T_1 ) ( V_19 / V_20 ) ;
return V_22 ? V_22 : 1 ;
}
static T_1 F_10 ( T_1 V_23 )
{
T_1 V_22 ;
T_1 V_20 ;
V_23 = ( V_23 > V_24 ) ? V_24 : V_23 ;
V_20 = ( V_21 / 1000 ) ;
V_22 = ( T_1 ) ( V_23 * V_20 ) / 1000 ;
return V_22 ? V_22 : 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_25 ) ;
struct V_26 * V_6 ;
unsigned int V_27 , V_28 , V_29 , V_30 , V_31 ;
T_1 V_13 ;
if ( ! V_2 ) {
F_13 ( L_20 , V_7 ) ;
return;
}
V_6 = V_2 -> V_6 ;
V_13 = F_7 ( & V_2 -> V_12 ) ;
F_3 ( V_6 , L_21 , V_13 ) ;
V_28 = F_8 ( V_2 -> V_12 . V_28 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_30 = V_2 -> V_12 . V_32 [ V_27 ] ;
V_31 = F_14 ( & V_2 -> V_12 . V_33 [ V_30 ] ) ;
V_29 = F_9 ( V_31 ) ;
if ( V_27 % 2 )
V_25 . V_34 = false ;
else
V_25 . V_34 = true ;
V_25 . V_35 = F_15 ( V_29 ) ;
V_25 . V_35 = ( V_25 . V_35 > V_24 ) ?
V_24 : V_25 . V_35 ;
F_3 ( V_6 , L_22 ,
V_25 . V_34 ? L_23 : L_24 , V_25 . V_35 , V_27 ) ;
F_16 ( V_2 -> V_36 , & V_25 ) ;
}
V_25 . V_34 = false ;
V_25 . V_37 = true ;
V_25 . V_35 = V_2 -> V_36 -> V_37 ;
F_3 ( V_6 , L_25 ,
V_25 . V_35 ) ;
F_16 ( V_2 -> V_36 , & V_25 ) ;
F_3 ( V_6 , L_26 ) ;
F_17 ( V_2 -> V_36 ) ;
}
static int F_18 ( int V_38 , struct V_1 * V_2 )
{
struct V_39 * V_40 ;
T_3 * V_41 ;
int V_3 ;
V_41 = F_19 ( sizeof( T_3 ) , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
V_40 = V_2 -> V_40 ;
V_3 = F_20 ( V_40 , F_21 ( V_40 , 0 ) , V_38 ,
V_44 | V_45 | V_46 ,
0x0000 , 0x0000 , V_41 , sizeof( T_3 ) , V_47 * 10 ) ;
if ( V_3 < 0 ) {
F_22 ( V_2 -> V_6 , L_27 ,
V_7 , V_3 , * V_41 ) ;
V_3 = - V_48 ;
} else
V_3 = V_41 [ 0 ] ;
F_23 ( V_41 ) ;
return V_3 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
T_3 V_49 ;
V_49 = F_18 ( V_50 , V_2 ) ;
if ( V_49 != 0 )
F_3 ( V_6 , L_28 ,
V_7 , V_49 ) ;
V_49 = F_18 ( V_51 , V_2 ) ;
if ( V_49 != 1 ) {
F_22 ( V_6 , L_29 ,
V_7 , V_49 ) ;
return - V_48 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
F_26 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_52 ) ;
F_27 ( V_2 -> V_4 ) ;
F_27 ( V_2 -> V_52 ) ;
F_28 ( V_40 , F_29 ( V_2 -> V_53 -> V_54 ) ,
V_2 -> V_55 , V_2 -> V_56 ) ;
F_23 ( V_2 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
T_4 * V_57 ;
T_1 V_37 = F_31 ( 150 ) ;
int V_58 , V_49 , V_59 ;
V_58 = sizeof( * V_57 ) ;
V_57 = F_19 ( V_58 , V_42 ) ;
if ( ! V_57 ) {
F_32 ( V_2 -> V_6 , L_30 ) ;
return V_37 ;
}
V_59 = F_21 ( V_2 -> V_40 , 0 ) ;
V_49 = F_20 ( V_2 -> V_40 , V_59 , V_60 ,
V_44 | V_45 | V_46 ,
V_61 , 0 , V_57 , V_58 , V_47 * 5 ) ;
if ( V_49 != V_58 )
F_32 ( V_2 -> V_6 , L_31 ) ;
else {
V_37 = F_9 ( F_33 ( V_57 ) ) ;
F_3 ( V_2 -> V_6 , L_32 , V_37 / 1000 ) ;
}
F_23 ( V_57 ) ;
return V_37 ;
}
static int F_34 ( struct V_62 * V_62 , unsigned int V_63 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_26 * V_6 = V_2 -> V_6 ;
T_4 * V_37 ;
int V_49 ;
V_37 = F_35 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 )
return - V_43 ;
* V_37 = F_36 ( F_10 ( V_63 / 1000 ) ) ;
V_49 = F_20 ( V_40 , F_37 ( V_40 , 0 ) , V_65 ,
V_44 | V_45 | V_66 ,
V_61 , 0 , V_37 , sizeof( * V_37 ) ,
V_47 * 25 ) ;
F_3 ( V_6 , L_33 ,
F_38 ( * V_37 ) , V_49 ) ;
if ( V_49 == sizeof( * V_37 ) )
V_49 = 0 ;
else if ( V_49 >= 0 )
V_49 = - V_48 ;
F_23 ( V_37 ) ;
return V_49 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_26 * V_6 = V_2 -> V_6 ;
int V_36 , V_67 , V_68 ;
T_3 * V_31 ;
int V_58 = sizeof( T_3 ) ;
V_67 = F_21 ( V_40 , 0 ) ;
V_68 = F_37 ( V_40 , 0 ) ;
V_31 = F_35 ( V_58 , V_42 ) ;
if ( ! V_31 ) {
F_22 ( V_6 , L_34 ) ;
return;
}
* V_31 = 0x01 ;
V_36 = F_20 ( V_40 , V_67 , V_69 ,
V_44 | V_45 | V_46 ,
V_70 , 0 , V_31 , V_58 , V_47 * 25 ) ;
F_3 ( V_6 , L_35 , V_36 ) ;
* V_31 = V_71 ;
V_36 = F_20 ( V_40 , V_68 , V_65 ,
V_44 | V_45 | V_66 ,
V_72 , 0 , V_31 , V_58 , V_47 * 25 ) ;
F_3 ( V_6 , L_36 , * V_31 , V_36 ) ;
* V_31 = ( 65536 - ( V_73 * 2000 ) ) / 256 ;
V_36 = F_20 ( V_40 , V_68 , V_65 ,
V_44 | V_45 | V_66 ,
V_74 , 0 , V_31 , V_58 , V_47 * 25 ) ;
F_3 ( V_6 , L_37 , * V_31 , V_36 ) ;
* V_31 = V_75 ;
V_36 = F_20 ( V_40 , V_68 , V_65 ,
V_44 | V_45 | V_66 ,
V_76 , 0 , V_31 , V_58 , V_47 * 25 ) ;
F_3 ( V_6 , L_38 , * V_31 ,
V_36 ) ;
* V_31 = V_77 ;
V_36 = F_20 ( V_40 , V_68 , V_65 ,
V_44 | V_45 | V_66 ,
V_78 , 0 , V_31 , V_58 , V_47 * 25 ) ;
F_3 ( V_6 , L_39 , * V_31 , V_36 ) ;
F_23 ( V_31 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
char * V_79 ;
V_79 = F_19 ( sizeof( char ) * ( V_80 + 1 ) , V_42 ) ;
if ( ! V_79 ) {
F_22 ( V_2 -> V_6 , L_34 ) ;
return;
}
V_36 = F_20 ( V_2 -> V_40 , F_21 ( V_2 -> V_40 , 0 ) ,
V_81 ,
V_44 | V_45 | V_46 ,
0 , 0 , V_79 , V_80 , V_47 * 5 ) ;
if ( V_36 >= 0 )
F_5 ( V_2 -> V_6 , L_40 , V_79 ) ;
else
F_22 ( V_2 -> V_6 , L_41 ) ;
F_23 ( V_79 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_58 )
{
struct V_82 * V_83 = V_2 -> V_55 ;
unsigned V_84 , V_85 ;
V_84 = F_8 ( V_83 -> V_18 ) ;
V_85 = F_8 ( V_83 -> V_86 ) ;
if ( V_84 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_6 , L_42 , V_84 ) ;
return;
}
switch ( V_85 ) {
case V_87 :
if ( V_58 >= sizeof( struct V_88 ) ) {
struct V_88 * error = V_2 -> V_55 ;
unsigned V_89 = F_8 ( error -> V_89 ) ;
F_4 ( V_2 , V_89 ) ;
}
break;
case V_90 :
memcpy ( & V_2 -> V_12 , V_2 -> V_55 , V_58 ) ;
V_2 -> V_91 = V_58 ;
F_3 ( V_2 -> V_6 , L_43 ,
V_2 -> V_91 , V_84 ) ;
break;
default:
F_3 ( V_2 -> V_6 , L_44 ,
V_85 , V_58 , V_84 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , unsigned V_58 )
{
void * V_12 = & V_2 -> V_12 ;
if ( V_58 + V_2 -> V_91 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_6 , L_45 ) ;
V_2 -> V_91 = 0 ;
return;
}
memcpy ( V_12 + V_2 -> V_91 , V_2 -> V_55 , V_58 ) ;
V_2 -> V_91 += V_58 ;
F_3 ( V_2 -> V_6 , L_43 , V_2 -> V_91 ,
F_8 ( V_2 -> V_12 . V_83 . V_18 ) ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned V_58 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
unsigned V_85 ;
int V_49 = 0 ;
if ( V_2 -> V_91 == 0 && V_58 >= sizeof( struct V_82 ) ) {
F_41 ( V_2 , V_58 ) ;
} else if ( V_2 -> V_91 != 0 ) {
F_42 ( V_2 , V_58 ) ;
} else if ( V_2 -> V_91 == 0 ) {
F_22 ( V_6 , L_46 ) ;
V_49 = - V_92 ;
goto V_93;
}
if ( V_2 -> V_91 < F_8 ( V_2 -> V_12 . V_83 . V_18 ) +
sizeof( struct V_82 ) )
return 0 ;
V_85 = F_8 ( V_2 -> V_12 . V_83 . V_86 ) ;
if ( V_85 == V_90 )
F_11 ( V_2 ) ;
else
F_3 ( V_6 , L_47 ,
V_85 ) ;
V_93:
V_2 -> V_91 = 0 ;
return V_49 ;
}
static void F_44 ( struct V_94 * V_94 )
{
struct V_1 * V_2 ;
int V_49 ;
if ( ! V_94 )
return;
V_2 = V_94 -> V_95 ;
if ( ! V_2 ) {
F_13 ( L_48 , V_7 ) ;
F_45 ( V_94 ) ;
return;
}
switch ( V_94 -> V_96 ) {
case 0 :
V_49 = F_43 ( V_2 , V_94 -> V_97 ) ;
if ( ! V_49 ) {
F_1 ( V_2 ) ;
}
break;
case - V_98 :
case - V_99 :
case - V_100 :
F_45 ( V_94 ) ;
return;
case - V_101 :
default:
F_32 ( V_2 -> V_6 , L_49 , V_94 -> V_96 ) ;
V_2 -> V_91 = 0 ;
break;
}
}
static T_2 F_46 ( unsigned int V_13 )
{
int V_102 = 6000000 ;
return 65536 - ( V_102 / V_13 ) ;
}
static int F_47 ( struct V_62 * V_103 , T_1 V_104 )
{
struct V_1 * V_2 = V_103 -> V_64 ;
struct V_26 * V_6 = V_2 -> V_6 ;
F_3 ( V_6 , L_50 , V_104 ) ;
if ( V_104 == 0 )
return - V_105 ;
V_2 -> V_104 = V_104 ;
return 0 ;
}
static int F_48 ( struct V_62 * V_103 , unsigned * V_106 ,
unsigned V_107 )
{
struct V_1 * V_2 = V_103 -> V_64 ;
struct V_26 * V_6 = V_2 -> V_6 ;
struct V_11 * V_12 = NULL ;
int V_49 , V_108 ;
int V_109 , V_110 , V_59 ;
int * V_111 = NULL ;
T_3 V_112 = 0 ;
unsigned V_27 , V_113 ;
if ( V_2 -> V_10 ) {
F_32 ( V_6 , L_51 , V_7 ) ;
return - V_114 ;
}
if ( V_107 > V_115 - V_116 )
return - V_105 ;
V_2 -> V_10 = true ;
V_111 = F_19 ( sizeof( int ) * V_77 , V_42 ) ;
if ( ! V_111 ) {
V_49 = - V_43 ;
goto V_93;
}
V_12 = F_19 ( sizeof( * V_12 ) , V_42 ) ;
if ( ! V_12 ) {
V_49 = - V_43 ;
goto V_93;
}
for ( V_27 = 0 ; V_27 < V_107 ; V_27 ++ ) {
V_110 = F_10 ( V_106 [ V_27 ] ) ;
if ( V_110 > 0xffff ) {
F_32 ( V_6 , L_52 ,
V_106 [ V_27 ] , F_9 ( 0xffff ) ) ;
V_110 = 0xffff ;
}
for ( V_109 = 0 ; V_109 < V_112 ; V_109 ++ ) {
if ( V_111 [ V_109 ] == V_110 )
break;
}
if ( V_109 == V_112 ) {
F_3 ( V_6 , L_53 ,
V_27 , V_106 [ V_27 ] , V_112 , V_110 ) ;
if ( V_112 < V_77 ) {
V_111 [ V_112 ] = V_110 ;
F_49 ( V_110 ,
& V_12 -> V_33 [ V_112 ] ) ;
V_112 ++ ;
} else {
V_49 = - V_105 ;
goto V_93;
}
}
V_12 -> V_32 [ V_27 ] = V_109 ;
}
V_12 -> V_32 [ V_107 ] = V_117 ;
V_12 -> V_32 [ V_107 + 1 ] = V_117 ;
V_113 = F_50 ( struct V_11 ,
V_32 [ V_107 + V_116 ] ) ;
V_12 -> V_83 . V_18 = F_51 ( V_113 -
sizeof( struct V_82 ) ) ;
V_12 -> V_83 . V_86 = F_51 ( V_118 ) ;
V_12 -> V_119 = F_36 ( F_9 ( 100 ) ) ;
V_12 -> V_14 = F_51 ( F_46 ( V_2 -> V_104 ) ) ;
V_12 -> V_120 = V_112 ;
V_12 -> V_28 = F_51 ( V_107 + V_116 ) ;
V_59 = F_52 ( V_2 -> V_40 , V_2 -> V_121 -> V_122 ) ;
V_49 = F_53 ( V_2 -> V_40 , V_59 , V_12 ,
V_113 , & V_108 , 10 * V_47 ) ;
F_3 ( V_6 , L_54 , V_108 , V_49 ) ;
V_59 = F_21 ( V_2 -> V_40 , 0 ) ;
V_49 = F_20 ( V_2 -> V_40 , V_59 , V_123 ,
V_44 | V_45 | V_46 ,
0 , 0 , V_12 , 2 , V_47 * 10 ) ;
if ( V_49 < 0 )
F_22 ( V_6 , L_55 , V_49 ) ;
else
V_49 = V_107 ;
V_93:
F_23 ( V_111 ) ;
F_23 ( V_12 ) ;
V_2 -> V_10 = false ;
return V_49 ;
}
static void F_54 ( struct V_124 * V_125 , enum
V_126 V_127 )
{
struct V_1 * V_2 = F_55 ( V_125 , struct V_1 ,
V_128 ) ;
if ( V_127 != V_129 && F_56 ( & V_2 -> V_130 , 0 , 1 ) == 0 ) {
int V_49 = F_2 ( V_2 -> V_52 , V_5 ) ;
if ( V_49 != 0 ) {
F_3 ( V_2 -> V_6 , L_28 ,
V_7 , V_49 ) ;
F_57 ( & V_2 -> V_130 , 0 ) ;
}
}
}
static void F_58 ( struct V_94 * V_94 )
{
struct V_1 * V_2 = V_94 -> V_95 ;
switch ( V_94 -> V_96 ) {
case 0 :
break;
case - V_98 :
case - V_99 :
case - V_100 :
F_45 ( V_94 ) ;
return;
case - V_101 :
default:
F_3 ( V_2 -> V_6 , L_49 , V_94 -> V_96 ) ;
break;
}
V_2 -> V_128 . V_127 = V_129 ;
F_59 ( & V_2 -> V_130 ) ;
}
static struct V_62 * F_60 ( struct V_1 * V_2 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
struct V_62 * V_36 ;
int V_49 = - V_131 ;
T_2 V_132 = F_29 ( V_2 -> V_40 -> V_133 . V_134 ) ;
V_36 = F_61 () ;
if ( ! V_36 ) {
F_22 ( V_6 , L_56 ) ;
goto V_93;
}
snprintf ( V_2 -> V_135 , sizeof( V_2 -> V_135 ) , L_57
L_58 ,
V_132 == V_136 ? L_59 : L_60 ,
F_29 ( V_2 -> V_40 -> V_133 . V_137 ) , V_132 ) ;
F_62 ( V_2 -> V_40 , V_2 -> V_138 , sizeof( V_2 -> V_138 ) ) ;
V_36 -> V_139 = V_2 -> V_135 ;
V_36 -> V_140 = V_2 -> V_138 ;
F_63 ( V_2 -> V_40 , & V_36 -> V_141 ) ;
V_36 -> V_6 . V_142 = V_6 ;
V_36 -> V_64 = V_2 ;
V_36 -> V_143 = V_144 ;
V_36 -> V_145 = V_146 ;
V_36 -> V_147 = F_64 ( V_148 ) ;
V_36 -> V_149 = F_64 ( V_150 ) ;
V_36 -> V_37 = F_15 ( F_30 ( V_2 ) ) ;
V_36 -> V_151 = F_34 ;
V_36 -> V_152 = F_48 ;
V_36 -> V_153 = F_47 ;
V_36 -> V_154 = V_155 ;
V_36 -> V_156 = F_15 ( 2 ) ;
V_36 -> V_157 = V_158 ;
V_49 = F_65 ( V_36 ) ;
if ( V_49 < 0 ) {
F_22 ( V_6 , L_61 ) ;
goto V_93;
}
return V_36 ;
V_93:
F_66 ( V_36 ) ;
return NULL ;
}
static int F_67 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
struct V_39 * V_40 = F_68 ( V_160 ) ;
struct V_26 * V_6 = & V_160 -> V_6 ;
struct V_163 * V_164 ;
struct V_1 * V_2 ;
struct V_165 * V_166 ;
struct V_165 * V_53 = NULL ;
struct V_165 * V_121 = NULL ;
T_3 V_167 , V_168 ;
int V_59 , V_27 ;
int V_169 = - V_43 ;
V_164 = V_160 -> V_170 ;
for ( V_27 = 0 ; V_27 < V_164 -> V_171 . V_172 ; ++ V_27 ) {
V_166 = & V_164 -> V_173 [ V_27 ] . V_171 ;
V_167 = V_166 -> V_122 ;
V_168 = V_166 -> V_174 ;
if ( ( V_53 == NULL ) &&
( ( V_167 & V_175 ) == V_46 ) &&
( ( V_168 & V_176 ) ==
V_177 ) ) {
F_3 ( V_6 , L_62 ,
V_166 -> V_122 ) ;
if ( V_166 -> V_122 == V_178 )
V_53 = V_166 ;
}
if ( ( V_121 == NULL ) &&
( ( V_167 & V_175 ) == V_66 ) &&
( ( V_168 & V_176 ) ==
V_177 ) ) {
F_3 ( V_6 , L_63 ,
V_166 -> V_122 ) ;
V_121 = V_166 ;
}
}
if ( ! V_53 || ! V_121 ) {
F_22 ( V_6 , L_64 ) ;
V_169 = - V_131 ;
goto V_179;
}
V_2 = F_19 ( sizeof( * V_2 ) , V_42 ) ;
if ( V_2 == NULL ) {
F_22 ( V_6 , L_34 ) ;
goto V_179;
}
V_2 -> V_6 = & V_160 -> V_6 ;
V_2 -> V_4 = F_69 ( 0 , V_42 ) ;
if ( ! V_2 -> V_4 )
goto error;
V_2 -> V_53 = V_53 ;
V_2 -> V_55 = F_70 ( V_40 ,
F_29 ( V_53 -> V_54 ) , V_42 , & V_2 -> V_56 ) ;
if ( ! V_2 -> V_55 ) {
F_22 ( V_6 , L_65 ) ;
goto error;
}
V_59 = F_71 ( V_40 , V_53 -> V_122 ) ;
F_72 ( V_2 -> V_4 , V_40 , V_59 , V_2 -> V_55 ,
F_29 ( V_53 -> V_54 ) , F_44 , V_2 ) ;
V_2 -> V_4 -> V_180 = V_2 -> V_56 ;
V_2 -> V_4 -> V_181 |= V_182 ;
V_2 -> V_121 = V_121 ;
V_2 -> V_40 = V_40 ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
V_169 = F_24 ( V_2 ) ;
if ( V_169 < 0 )
goto error;
V_2 -> V_104 = 38000 ;
V_2 -> V_128 . V_135 = L_66 ;
V_2 -> V_128 . V_183 = L_67 ;
V_2 -> V_128 . V_184 = F_54 ;
V_169 = F_73 ( & V_160 -> V_6 , & V_2 -> V_128 ) ;
if ( V_169 )
goto error;
F_57 ( & V_2 -> V_130 , 0 ) ;
V_2 -> V_52 = F_69 ( 0 , V_42 ) ;
if ( ! V_2 -> V_52 ) {
V_169 = - V_43 ;
goto V_185;
}
V_2 -> V_186 . V_187 = 0xc0 ;
V_2 -> V_186 . V_188 = V_189 ;
V_2 -> V_186 . V_190 = F_74 ( 1 ) ;
F_75 ( V_2 -> V_52 , V_40 , F_21 ( V_40 , 0 ) ,
( unsigned char * ) & V_2 -> V_186 ,
& V_2 -> V_191 , sizeof( V_2 -> V_191 ) ,
F_58 , V_2 ) ;
V_2 -> V_36 = F_60 ( V_2 ) ;
if ( ! V_2 -> V_36 ) {
V_169 = - V_43 ;
goto V_185;
}
F_76 ( V_160 , V_2 ) ;
return 0 ;
V_185:
F_77 ( & V_2 -> V_128 ) ;
error:
F_25 ( V_2 , V_2 -> V_40 ) ;
V_179:
F_22 ( V_6 , L_68 , V_7 , V_169 ) ;
return V_169 ;
}
static void F_78 ( struct V_159 * V_160 )
{
struct V_39 * V_40 = F_68 ( V_160 ) ;
struct V_1 * V_2 = F_79 ( V_160 ) ;
if ( ! V_2 )
return;
F_76 ( V_160 , NULL ) ;
F_80 ( V_2 -> V_36 ) ;
F_77 ( & V_2 -> V_128 ) ;
F_25 ( V_2 , V_40 ) ;
}
static int F_81 ( struct V_159 * V_160 , T_5 V_192 )
{
struct V_1 * V_2 = F_79 ( V_160 ) ;
F_82 ( & V_2 -> V_128 ) ;
F_26 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_52 ) ;
return 0 ;
}
static int F_83 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_79 ( V_160 ) ;
if ( F_2 ( V_2 -> V_4 , V_5 ) )
return - V_48 ;
F_84 ( & V_2 -> V_128 ) ;
return 0 ;
}
