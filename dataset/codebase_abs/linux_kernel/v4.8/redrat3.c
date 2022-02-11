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
V_25 . V_35 = F_15 ( V_2 -> V_38 ) ;
F_3 ( V_6 , L_25 ,
V_25 . V_35 ) ;
F_16 ( V_2 -> V_36 , & V_25 ) ;
F_3 ( V_6 , L_26 ) ;
F_17 ( V_2 -> V_36 ) ;
}
static int F_18 ( int V_39 , struct V_1 * V_2 )
{
struct V_40 * V_41 ;
T_3 * V_42 ;
int V_3 ;
V_42 = F_19 ( sizeof( T_3 ) , V_43 ) ;
if ( ! V_42 )
return - V_44 ;
V_41 = V_2 -> V_41 ;
V_3 = F_20 ( V_41 , F_21 ( V_41 , 0 ) , V_39 ,
V_45 | V_46 | V_47 ,
0x0000 , 0x0000 , V_42 , sizeof( T_3 ) , V_48 * 10 ) ;
if ( V_3 < 0 ) {
F_22 ( V_2 -> V_6 , L_27 ,
V_7 , V_3 , * V_42 ) ;
V_3 = - V_49 ;
} else
V_3 = V_42 [ 0 ] ;
F_23 ( V_42 ) ;
return V_3 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
T_3 V_50 ;
V_50 = F_18 ( V_51 , V_2 ) ;
if ( V_50 != 0 )
F_3 ( V_6 , L_28 ,
V_7 , V_50 ) ;
V_50 = F_18 ( V_52 , V_2 ) ;
if ( V_50 != 1 ) {
F_22 ( V_6 , L_29 ,
V_7 , V_50 ) ;
return - V_49 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
F_26 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_53 ) ;
F_27 ( V_2 -> V_4 ) ;
F_27 ( V_2 -> V_53 ) ;
F_28 ( V_41 , F_29 ( V_2 -> V_54 -> V_55 ) ,
V_2 -> V_56 , V_2 -> V_57 ) ;
F_23 ( V_2 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
T_4 * V_58 ;
T_1 V_37 = F_31 ( 150 ) ;
int V_59 , V_50 , V_60 ;
V_59 = sizeof( * V_58 ) ;
V_58 = F_19 ( V_59 , V_43 ) ;
if ( ! V_58 ) {
F_32 ( V_2 -> V_6 , L_30 ) ;
return V_37 ;
}
V_60 = F_21 ( V_2 -> V_41 , 0 ) ;
V_50 = F_20 ( V_2 -> V_41 , V_60 , V_61 ,
V_45 | V_46 | V_47 ,
V_62 , 0 , V_58 , V_59 , V_48 * 5 ) ;
if ( V_50 != V_59 )
F_32 ( V_2 -> V_6 , L_31 ) ;
else {
V_37 = F_9 ( F_33 ( V_58 ) ) ;
F_3 ( V_2 -> V_6 , L_32 , V_37 / 1000 ) ;
}
F_23 ( V_58 ) ;
return V_37 ;
}
static int F_34 ( struct V_63 * V_63 , unsigned int V_64 )
{
struct V_1 * V_2 = V_63 -> V_65 ;
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_26 * V_6 = V_2 -> V_6 ;
T_1 * V_37 ;
int V_50 ;
V_37 = F_35 ( sizeof( * V_37 ) , V_43 ) ;
if ( ! V_37 )
return - V_44 ;
* V_37 = F_36 ( F_10 ( V_64 / 1000 ) ) ;
V_50 = F_20 ( V_41 , F_37 ( V_41 , 0 ) , V_66 ,
V_45 | V_46 | V_67 ,
V_62 , 0 , V_37 , sizeof( * V_37 ) ,
V_48 * 25 ) ;
F_3 ( V_6 , L_33 ,
F_38 ( * V_37 ) , V_50 ) ;
if ( V_50 == sizeof( * V_37 ) ) {
V_2 -> V_38 = V_64 / 1000 ;
V_50 = 0 ;
} else if ( V_50 >= 0 )
V_50 = - V_49 ;
F_23 ( V_37 ) ;
return V_50 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_26 * V_6 = V_2 -> V_6 ;
int V_36 , V_68 , V_69 ;
T_3 * V_31 ;
int V_59 = sizeof( T_3 ) ;
V_68 = F_21 ( V_41 , 0 ) ;
V_69 = F_37 ( V_41 , 0 ) ;
V_31 = F_35 ( V_59 , V_43 ) ;
if ( ! V_31 ) {
F_22 ( V_6 , L_34 ) ;
return;
}
* V_31 = 0x01 ;
V_36 = F_20 ( V_41 , V_68 , V_70 ,
V_45 | V_46 | V_47 ,
V_71 , 0 , V_31 , V_59 , V_48 * 25 ) ;
F_3 ( V_6 , L_35 , V_36 ) ;
* V_31 = 5 ;
V_36 = F_20 ( V_41 , V_69 , V_66 ,
V_45 | V_46 | V_67 ,
V_72 , 0 , V_31 , V_59 , V_48 * 25 ) ;
F_3 ( V_6 , L_36 , * V_31 , V_36 ) ;
* V_31 = V_73 ;
V_36 = F_20 ( V_41 , V_69 , V_66 ,
V_45 | V_46 | V_67 ,
V_74 , 0 , V_31 , V_59 , V_48 * 25 ) ;
F_3 ( V_6 , L_37 , * V_31 , V_36 ) ;
F_23 ( V_31 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
char * V_75 ;
V_75 = F_19 ( sizeof( char ) * ( V_76 + 1 ) , V_43 ) ;
if ( ! V_75 ) {
F_22 ( V_2 -> V_6 , L_34 ) ;
return;
}
V_36 = F_20 ( V_2 -> V_41 , F_21 ( V_2 -> V_41 , 0 ) ,
V_77 ,
V_45 | V_46 | V_47 ,
0 , 0 , V_75 , V_76 , V_48 * 5 ) ;
if ( V_36 >= 0 )
F_5 ( V_2 -> V_6 , L_38 , V_75 ) ;
else
F_22 ( V_2 -> V_6 , L_39 ) ;
F_23 ( V_75 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_59 )
{
struct V_78 * V_79 = V_2 -> V_56 ;
unsigned V_80 , V_81 ;
V_80 = F_8 ( V_79 -> V_18 ) ;
V_81 = F_8 ( V_79 -> V_82 ) ;
if ( V_80 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_6 , L_40 , V_80 ) ;
return;
}
switch ( V_81 ) {
case V_83 :
if ( V_59 >= sizeof( struct V_84 ) ) {
struct V_84 * error = V_2 -> V_56 ;
unsigned V_85 = F_8 ( error -> V_85 ) ;
F_4 ( V_2 , V_85 ) ;
}
break;
case V_86 :
memcpy ( & V_2 -> V_12 , V_2 -> V_56 , V_59 ) ;
V_2 -> V_87 = V_59 ;
F_3 ( V_2 -> V_6 , L_41 ,
V_2 -> V_87 , V_80 ) ;
break;
default:
F_3 ( V_2 -> V_6 , L_42 ,
V_81 , V_59 , V_80 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , unsigned V_59 )
{
void * V_12 = & V_2 -> V_12 ;
if ( V_59 + V_2 -> V_87 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_6 , L_43 ) ;
V_2 -> V_87 = 0 ;
return;
}
memcpy ( V_12 + V_2 -> V_87 , V_2 -> V_56 , V_59 ) ;
V_2 -> V_87 += V_59 ;
F_3 ( V_2 -> V_6 , L_41 , V_2 -> V_87 ,
F_8 ( V_2 -> V_12 . V_79 . V_18 ) ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned V_59 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
unsigned V_81 ;
int V_50 = 0 ;
if ( V_2 -> V_87 == 0 && V_59 >= sizeof( struct V_78 ) ) {
F_41 ( V_2 , V_59 ) ;
} else if ( V_2 -> V_87 != 0 ) {
F_42 ( V_2 , V_59 ) ;
} else if ( V_2 -> V_87 == 0 ) {
F_22 ( V_6 , L_44 ) ;
V_50 = - V_88 ;
goto V_89;
}
if ( V_2 -> V_87 < F_8 ( V_2 -> V_12 . V_79 . V_18 ) +
sizeof( struct V_78 ) )
return 0 ;
V_81 = F_8 ( V_2 -> V_12 . V_79 . V_82 ) ;
if ( V_81 == V_86 )
F_11 ( V_2 ) ;
else
F_3 ( V_6 , L_45 ,
V_81 ) ;
V_89:
V_2 -> V_87 = 0 ;
return V_50 ;
}
static void F_44 ( struct V_90 * V_90 )
{
struct V_1 * V_2 ;
int V_50 ;
if ( ! V_90 )
return;
V_2 = V_90 -> V_91 ;
if ( ! V_2 ) {
F_13 ( L_46 , V_7 ) ;
F_45 ( V_90 ) ;
return;
}
switch ( V_90 -> V_92 ) {
case 0 :
V_50 = F_43 ( V_2 , V_90 -> V_93 ) ;
if ( ! V_50 ) {
F_1 ( V_2 ) ;
}
break;
case - V_94 :
case - V_95 :
case - V_96 :
F_45 ( V_90 ) ;
return;
case - V_97 :
default:
F_32 ( V_2 -> V_6 , L_47 , V_90 -> V_92 ) ;
V_2 -> V_87 = 0 ;
break;
}
}
static T_2 F_46 ( unsigned int V_13 )
{
int V_98 = 6000000 ;
return 65536 - ( V_98 / V_13 ) ;
}
static int F_47 ( struct V_63 * V_99 , T_1 V_100 )
{
struct V_1 * V_2 = V_99 -> V_65 ;
struct V_26 * V_6 = V_2 -> V_6 ;
F_3 ( V_6 , L_48 , V_100 ) ;
if ( V_100 == 0 )
return - V_101 ;
V_2 -> V_100 = V_100 ;
return 0 ;
}
static int F_48 ( struct V_63 * V_99 , unsigned * V_102 ,
unsigned V_103 )
{
struct V_1 * V_2 = V_99 -> V_65 ;
struct V_26 * V_6 = V_2 -> V_6 ;
struct V_11 * V_12 = NULL ;
int V_50 , V_104 ;
int V_105 , V_106 , V_60 ;
int * V_107 = NULL ;
T_3 V_108 = 0 ;
unsigned V_27 , V_109 ;
if ( V_2 -> V_10 ) {
F_32 ( V_6 , L_49 , V_7 ) ;
return - V_110 ;
}
if ( V_103 > V_111 - V_112 )
return - V_101 ;
V_2 -> V_10 = true ;
V_107 = F_19 ( sizeof( int ) * V_73 , V_43 ) ;
if ( ! V_107 ) {
V_50 = - V_44 ;
goto V_89;
}
V_12 = F_19 ( sizeof( * V_12 ) , V_43 ) ;
if ( ! V_12 ) {
V_50 = - V_44 ;
goto V_89;
}
for ( V_27 = 0 ; V_27 < V_103 ; V_27 ++ ) {
V_106 = F_10 ( V_102 [ V_27 ] ) ;
if ( V_106 > 0xffff ) {
F_32 ( V_6 , L_50 ,
V_102 [ V_27 ] , F_9 ( 0xffff ) ) ;
V_106 = 0xffff ;
}
for ( V_105 = 0 ; V_105 < V_108 ; V_105 ++ ) {
if ( V_107 [ V_105 ] == V_106 )
break;
}
if ( V_105 == V_108 ) {
F_3 ( V_6 , L_51 ,
V_27 , V_102 [ V_27 ] , V_108 , V_106 ) ;
if ( V_108 < V_73 ) {
V_107 [ V_108 ] = V_106 ;
F_49 ( V_106 ,
& V_12 -> V_33 [ V_108 ] ) ;
V_108 ++ ;
} else {
V_50 = - V_101 ;
goto V_89;
}
}
V_12 -> V_32 [ V_27 ] = V_105 ;
}
V_12 -> V_32 [ V_103 ] = V_113 ;
V_12 -> V_32 [ V_103 + 1 ] = V_113 ;
V_109 = F_50 ( struct V_11 ,
V_32 [ V_103 + V_112 ] ) ;
V_12 -> V_79 . V_18 = F_51 ( V_109 -
sizeof( struct V_78 ) ) ;
V_12 -> V_79 . V_82 = F_51 ( V_114 ) ;
V_12 -> V_115 = F_36 ( F_9 ( 100 ) ) ;
V_12 -> V_14 = F_51 ( F_46 ( V_2 -> V_100 ) ) ;
V_12 -> V_116 = V_108 ;
V_12 -> V_28 = F_51 ( V_103 + V_112 ) ;
V_60 = F_52 ( V_2 -> V_41 , V_2 -> V_117 -> V_118 ) ;
V_50 = F_53 ( V_2 -> V_41 , V_60 , V_12 ,
V_109 , & V_104 , 10 * V_48 ) ;
F_3 ( V_6 , L_52 , V_104 , V_50 ) ;
V_60 = F_21 ( V_2 -> V_41 , 0 ) ;
V_50 = F_20 ( V_2 -> V_41 , V_60 , V_119 ,
V_45 | V_46 | V_47 ,
0 , 0 , V_12 , 2 , V_48 * 10 ) ;
if ( V_50 < 0 )
F_22 ( V_6 , L_53 , V_50 ) ;
else
V_50 = V_103 ;
V_89:
F_23 ( V_107 ) ;
F_23 ( V_12 ) ;
V_2 -> V_10 = false ;
return V_50 ;
}
static void F_54 ( struct V_120 * V_121 , enum
V_122 V_123 )
{
struct V_1 * V_2 = F_55 ( V_121 , struct V_1 ,
V_124 ) ;
if ( V_123 != V_125 && F_56 ( & V_2 -> V_126 , 0 , 1 ) == 0 ) {
int V_50 = F_2 ( V_2 -> V_53 , V_5 ) ;
if ( V_50 != 0 ) {
F_3 ( V_2 -> V_6 , L_28 ,
V_7 , V_50 ) ;
F_57 ( & V_2 -> V_126 , 0 ) ;
}
}
}
static void F_58 ( struct V_90 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_91 ;
switch ( V_90 -> V_92 ) {
case 0 :
break;
case - V_94 :
case - V_95 :
case - V_96 :
F_45 ( V_90 ) ;
return;
case - V_97 :
default:
F_3 ( V_2 -> V_6 , L_47 , V_90 -> V_92 ) ;
break;
}
V_2 -> V_124 . V_123 = V_125 ;
F_59 ( & V_2 -> V_126 ) ;
}
static struct V_63 * F_60 ( struct V_1 * V_2 )
{
struct V_26 * V_6 = V_2 -> V_6 ;
struct V_63 * V_36 ;
int V_50 = - V_127 ;
T_2 V_128 = F_29 ( V_2 -> V_41 -> V_129 . V_130 ) ;
V_36 = F_61 () ;
if ( ! V_36 ) {
F_22 ( V_6 , L_54 ) ;
goto V_89;
}
snprintf ( V_2 -> V_131 , sizeof( V_2 -> V_131 ) , L_55
L_56 ,
V_128 == V_132 ? L_57 : L_58 ,
F_29 ( V_2 -> V_41 -> V_129 . V_133 ) , V_128 ) ;
F_62 ( V_2 -> V_41 , V_2 -> V_134 , sizeof( V_2 -> V_134 ) ) ;
V_36 -> V_135 = V_2 -> V_131 ;
V_36 -> V_136 = V_2 -> V_134 ;
F_63 ( V_2 -> V_41 , & V_36 -> V_137 ) ;
V_36 -> V_6 . V_138 = V_6 ;
V_36 -> V_65 = V_2 ;
V_36 -> V_139 = V_140 ;
V_36 -> V_141 = V_142 ;
V_36 -> V_143 = F_64 ( V_144 ) ;
V_36 -> V_145 = F_64 ( V_146 ) ;
V_36 -> V_37 = F_15 ( V_2 -> V_38 ) ;
V_36 -> V_147 = F_34 ;
V_36 -> V_148 = F_48 ;
V_36 -> V_149 = F_47 ;
V_36 -> V_150 = V_151 ;
V_36 -> V_152 = F_15 ( 2 ) ;
V_36 -> V_153 = V_154 ;
V_50 = F_65 ( V_36 ) ;
if ( V_50 < 0 ) {
F_22 ( V_6 , L_59 ) ;
goto V_89;
}
return V_36 ;
V_89:
F_66 ( V_36 ) ;
return NULL ;
}
static int F_67 ( struct V_155 * V_156 ,
const struct V_157 * V_158 )
{
struct V_40 * V_41 = F_68 ( V_156 ) ;
struct V_26 * V_6 = & V_156 -> V_6 ;
struct V_159 * V_160 ;
struct V_1 * V_2 ;
struct V_161 * V_162 ;
struct V_161 * V_54 = NULL ;
struct V_161 * V_117 = NULL ;
T_3 V_163 , V_164 ;
int V_60 , V_27 ;
int V_165 = - V_44 ;
V_160 = V_156 -> V_166 ;
for ( V_27 = 0 ; V_27 < V_160 -> V_167 . V_168 ; ++ V_27 ) {
V_162 = & V_160 -> V_169 [ V_27 ] . V_167 ;
V_163 = V_162 -> V_118 ;
V_164 = V_162 -> V_170 ;
if ( ( V_54 == NULL ) &&
( ( V_163 & V_171 ) == V_47 ) &&
( ( V_164 & V_172 ) ==
V_173 ) ) {
F_3 ( V_6 , L_60 ,
V_162 -> V_118 ) ;
if ( V_162 -> V_118 == V_174 )
V_54 = V_162 ;
}
if ( ( V_117 == NULL ) &&
( ( V_163 & V_171 ) == V_67 ) &&
( ( V_164 & V_172 ) ==
V_173 ) ) {
F_3 ( V_6 , L_61 ,
V_162 -> V_118 ) ;
V_117 = V_162 ;
}
}
if ( ! V_54 || ! V_117 ) {
F_22 ( V_6 , L_62 ) ;
V_165 = - V_127 ;
goto V_175;
}
V_2 = F_19 ( sizeof( * V_2 ) , V_43 ) ;
if ( V_2 == NULL ) {
F_22 ( V_6 , L_34 ) ;
goto V_175;
}
V_2 -> V_6 = & V_156 -> V_6 ;
V_2 -> V_4 = F_69 ( 0 , V_43 ) ;
if ( ! V_2 -> V_4 ) {
F_22 ( V_6 , L_63 ) ;
goto error;
}
V_2 -> V_54 = V_54 ;
V_2 -> V_56 = F_70 ( V_41 ,
F_29 ( V_54 -> V_55 ) , V_43 , & V_2 -> V_57 ) ;
if ( ! V_2 -> V_56 ) {
F_22 ( V_6 , L_64 ) ;
goto error;
}
V_60 = F_71 ( V_41 , V_54 -> V_118 ) ;
F_72 ( V_2 -> V_4 , V_41 , V_60 , V_2 -> V_56 ,
F_29 ( V_54 -> V_55 ) , F_44 , V_2 ) ;
V_2 -> V_4 -> V_176 = V_2 -> V_57 ;
V_2 -> V_4 -> V_177 |= V_178 ;
V_2 -> V_117 = V_117 ;
V_2 -> V_41 = V_41 ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
V_165 = F_24 ( V_2 ) ;
if ( V_165 < 0 )
goto error;
V_2 -> V_38 = F_30 ( V_2 ) ;
V_2 -> V_100 = 38000 ;
V_2 -> V_124 . V_131 = L_65 ;
V_2 -> V_124 . V_179 = L_66 ;
V_2 -> V_124 . V_180 = F_54 ;
V_165 = F_73 ( & V_156 -> V_6 , & V_2 -> V_124 ) ;
if ( V_165 )
goto error;
F_57 ( & V_2 -> V_126 , 0 ) ;
V_2 -> V_53 = F_69 ( 0 , V_43 ) ;
if ( ! V_2 -> V_53 ) {
V_165 = - V_44 ;
goto V_181;
}
V_2 -> V_182 . V_183 = 0xc0 ;
V_2 -> V_182 . V_184 = V_185 ;
V_2 -> V_182 . V_186 = F_74 ( 1 ) ;
F_75 ( V_2 -> V_53 , V_41 , F_21 ( V_41 , 0 ) ,
( unsigned char * ) & V_2 -> V_182 ,
& V_2 -> V_187 , sizeof( V_2 -> V_187 ) ,
F_58 , V_2 ) ;
V_2 -> V_36 = F_60 ( V_2 ) ;
if ( ! V_2 -> V_36 ) {
V_165 = - V_44 ;
goto V_181;
}
F_76 ( V_156 , V_2 ) ;
return 0 ;
V_181:
F_77 ( & V_2 -> V_124 ) ;
error:
F_25 ( V_2 , V_2 -> V_41 ) ;
V_175:
F_22 ( V_6 , L_67 , V_7 , V_165 ) ;
return V_165 ;
}
static void F_78 ( struct V_155 * V_156 )
{
struct V_40 * V_41 = F_68 ( V_156 ) ;
struct V_1 * V_2 = F_79 ( V_156 ) ;
if ( ! V_2 )
return;
F_76 ( V_156 , NULL ) ;
F_80 ( V_2 -> V_36 ) ;
F_77 ( & V_2 -> V_124 ) ;
F_25 ( V_2 , V_41 ) ;
}
static int F_81 ( struct V_155 * V_156 , T_5 V_188 )
{
struct V_1 * V_2 = F_79 ( V_156 ) ;
F_82 ( & V_2 -> V_124 ) ;
F_26 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_53 ) ;
return 0 ;
}
static int F_83 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = F_79 ( V_156 ) ;
if ( F_2 ( V_2 -> V_4 , V_5 ) )
return - V_49 ;
F_84 ( & V_2 -> V_124 ) ;
return 0 ;
}
