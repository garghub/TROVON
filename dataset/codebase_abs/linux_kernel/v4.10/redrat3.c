static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 -> V_4 && ( V_3 != 0x40 ) )
F_2 ( V_2 -> V_5 , L_1 , V_3 ) ;
switch ( V_3 ) {
case 0x00 :
F_3 ( L_2 ) ;
break;
case 0x20 :
F_3 ( L_3 ) ;
break;
case 0x21 :
F_3 ( L_4 ) ;
break;
case 0x22 :
F_3 ( L_5 ) ;
break;
case 0x23 :
F_3 ( L_6 ) ;
break;
case 0x28 :
F_3 ( L_7 ) ;
break;
case 0x29 :
F_3 ( L_8 ) ;
break;
case 0x30 :
F_3 ( L_9 ) ;
break;
case 0x40 :
if ( ! V_2 -> V_4 )
F_3 ( L_10 ) ;
break;
case 0x41 :
F_3 ( L_11 ) ;
break;
case 0x42 :
F_3 ( L_12 ) ;
break;
default:
F_3 ( L_13 ) ;
break;
}
}
static T_1 F_4 ( struct V_6 * V_7 )
{
T_1 V_8 = 0 ;
T_2 V_9 = F_5 ( V_7 -> V_9 ) ;
if ( V_9 != 0 )
V_8 = ( V_10 * F_5 ( V_7 -> V_11 ) ) /
( V_9 * V_12 ) ;
return V_8 ;
}
static T_1 F_6 ( T_1 V_13 )
{
T_1 V_14 = V_13 * 1000 ;
T_1 V_15 = ( V_16 ) / 1000 ;
T_1 V_17 = ( T_1 ) ( V_14 / V_15 ) ;
return V_17 ? V_17 : 1 ;
}
static T_1 F_7 ( T_1 V_18 )
{
T_1 V_17 ;
T_1 V_15 ;
V_18 = ( V_18 > V_19 ) ? V_19 : V_18 ;
V_15 = ( V_16 / 1000 ) ;
V_17 = ( T_1 ) ( V_18 * V_15 ) / 1000 ;
return V_17 ? V_17 : 1 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_20 ) ;
struct V_21 * V_5 ;
unsigned int V_22 , V_23 , V_24 , V_25 , V_26 ;
T_1 V_8 ;
V_5 = V_2 -> V_5 ;
V_8 = F_4 ( & V_2 -> V_7 ) ;
F_10 ( V_5 , L_14 , V_8 ) ;
if ( V_8 && V_2 -> V_27 ) {
F_9 ( V_28 ) ;
V_28 . V_29 = 1 ;
V_28 . V_30 = V_8 ;
F_11 ( V_2 -> V_31 , & V_28 ) ;
}
V_23 = F_5 ( V_2 -> V_7 . V_23 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_25 = V_2 -> V_7 . V_32 [ V_22 ] ;
V_26 = F_12 ( & V_2 -> V_7 . V_33 [ V_25 ] ) ;
V_24 = F_6 ( V_26 ) ;
if ( V_22 % 2 )
V_20 . V_34 = false ;
else
V_20 . V_34 = true ;
V_20 . V_35 = F_13 ( V_24 ) ;
V_20 . V_35 = ( V_20 . V_35 > V_19 ) ?
V_19 : V_20 . V_35 ;
F_10 ( V_5 , L_15 ,
V_20 . V_34 ? L_16 : L_17 , V_20 . V_35 , V_22 ) ;
F_14 ( V_2 -> V_31 , & V_20 ) ;
}
V_20 . V_34 = false ;
V_20 . V_36 = true ;
V_20 . V_35 = V_2 -> V_31 -> V_36 ;
F_10 ( V_5 , L_18 ,
V_20 . V_35 ) ;
F_14 ( V_2 -> V_31 , & V_20 ) ;
F_10 ( V_5 , L_19 ) ;
F_15 ( V_2 -> V_31 ) ;
}
static int F_16 ( int V_37 , struct V_1 * V_2 )
{
struct V_38 * V_39 ;
T_3 * V_40 ;
int V_41 ;
V_40 = F_17 ( sizeof( T_3 ) , V_42 ) ;
if ( ! V_40 )
return - V_43 ;
V_39 = V_2 -> V_39 ;
V_41 = F_18 ( V_39 , F_19 ( V_39 , 0 ) , V_37 ,
V_44 | V_45 | V_46 ,
0x0000 , 0x0000 , V_40 , sizeof( T_3 ) , V_47 * 10 ) ;
if ( V_41 < 0 ) {
F_20 ( V_2 -> V_5 , L_20 ,
V_48 , V_41 , * V_40 ) ;
V_41 = - V_49 ;
} else
V_41 = V_40 [ 0 ] ;
F_21 ( V_40 ) ;
return V_41 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_21 * V_5 = V_2 -> V_5 ;
T_3 V_50 ;
V_50 = F_16 ( V_51 , V_2 ) ;
if ( V_50 != 0 )
F_10 ( V_5 , L_21 ,
V_48 , V_50 ) ;
V_50 = F_16 ( V_52 , V_2 ) ;
if ( V_50 != 1 ) {
F_20 ( V_5 , L_22 ,
V_48 , V_50 ) ;
return - V_49 ;
}
V_50 = F_23 ( V_2 -> V_53 , V_42 ) ;
if ( V_50 ) {
F_20 ( V_2 -> V_5 , L_23 , V_50 ) ;
return V_50 ;
}
V_50 = F_23 ( V_2 -> V_54 , V_42 ) ;
if ( V_50 )
F_20 ( V_2 -> V_5 , L_24 , V_50 ) ;
return V_50 ;
}
static inline void F_24 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
F_25 ( V_2 -> V_53 ) ;
F_25 ( V_2 -> V_54 ) ;
F_25 ( V_2 -> V_55 ) ;
F_25 ( V_2 -> V_56 ) ;
F_26 ( V_2 -> V_53 ) ;
F_26 ( V_2 -> V_54 ) ;
F_26 ( V_2 -> V_55 ) ;
F_26 ( V_2 -> V_56 ) ;
F_27 ( V_39 , F_28 ( V_2 -> V_57 -> V_58 ) ,
V_2 -> V_59 , V_2 -> V_60 ) ;
F_21 ( V_2 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
T_4 * V_61 ;
T_1 V_36 = F_30 ( 150 ) ;
int V_62 , V_50 , V_63 ;
V_62 = sizeof( * V_61 ) ;
V_61 = F_17 ( V_62 , V_42 ) ;
if ( ! V_61 )
return V_36 ;
V_63 = F_19 ( V_2 -> V_39 , 0 ) ;
V_50 = F_18 ( V_2 -> V_39 , V_63 , V_64 ,
V_44 | V_45 | V_46 ,
V_65 , 0 , V_61 , V_62 , V_47 * 5 ) ;
if ( V_50 != V_62 )
F_31 ( V_2 -> V_5 , L_25 ) ;
else {
V_36 = F_6 ( F_32 ( V_61 ) ) ;
F_10 ( V_2 -> V_5 , L_26 , V_36 / 1000 ) ;
}
F_21 ( V_61 ) ;
return V_36 ;
}
static int F_33 ( struct V_66 * V_66 , unsigned int V_67 )
{
struct V_1 * V_2 = V_66 -> V_68 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_21 * V_5 = V_2 -> V_5 ;
T_4 * V_36 ;
int V_50 ;
V_36 = F_34 ( sizeof( * V_36 ) , V_42 ) ;
if ( ! V_36 )
return - V_43 ;
* V_36 = F_35 ( F_7 ( V_67 / 1000 ) ) ;
V_50 = F_18 ( V_39 , F_36 ( V_39 , 0 ) , V_69 ,
V_44 | V_45 | V_70 ,
V_65 , 0 , V_36 , sizeof( * V_36 ) ,
V_47 * 25 ) ;
F_10 ( V_5 , L_27 ,
F_37 ( * V_36 ) , V_50 ) ;
if ( V_50 == sizeof( * V_36 ) )
V_50 = 0 ;
else if ( V_50 >= 0 )
V_50 = - V_49 ;
F_21 ( V_36 ) ;
return V_50 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_21 * V_5 = V_2 -> V_5 ;
int V_31 , V_71 , V_72 ;
T_3 * V_26 ;
T_5 const V_62 = sizeof( * V_26 ) ;
V_71 = F_19 ( V_39 , 0 ) ;
V_72 = F_36 ( V_39 , 0 ) ;
V_26 = F_34 ( V_62 , V_42 ) ;
if ( ! V_26 )
return;
* V_26 = 0x01 ;
V_31 = F_18 ( V_39 , V_71 , V_73 ,
V_44 | V_45 | V_46 ,
V_74 , 0 , V_26 , V_62 , V_47 * 25 ) ;
F_10 ( V_5 , L_28 , V_31 ) ;
* V_26 = V_75 ;
V_31 = F_18 ( V_39 , V_72 , V_69 ,
V_44 | V_45 | V_70 ,
V_76 , 0 , V_26 , V_62 , V_47 * 25 ) ;
F_10 ( V_5 , L_29 , * V_26 , V_31 ) ;
* V_26 = ( 65536 - ( V_77 * 2000 ) ) / 256 ;
V_31 = F_18 ( V_39 , V_72 , V_69 ,
V_44 | V_45 | V_70 ,
V_78 , 0 , V_26 , V_62 , V_47 * 25 ) ;
F_10 ( V_5 , L_30 , * V_26 , V_31 ) ;
* V_26 = V_79 ;
V_31 = F_18 ( V_39 , V_72 , V_69 ,
V_44 | V_45 | V_70 ,
V_80 , 0 , V_26 , V_62 , V_47 * 25 ) ;
F_10 ( V_5 , L_31 , * V_26 ,
V_31 ) ;
* V_26 = V_81 ;
V_31 = F_18 ( V_39 , V_72 , V_69 ,
V_44 | V_45 | V_70 ,
V_82 , 0 , V_26 , V_62 , V_47 * 25 ) ;
F_10 ( V_5 , L_32 , * V_26 , V_31 ) ;
F_21 ( V_26 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_31 ;
char * V_83 ;
V_83 = F_40 ( V_84 + 1 , sizeof( * V_83 ) , V_42 ) ;
if ( ! V_83 )
return;
V_31 = F_18 ( V_2 -> V_39 , F_19 ( V_2 -> V_39 , 0 ) ,
V_85 ,
V_44 | V_45 | V_46 ,
0 , 0 , V_83 , V_84 , V_47 * 5 ) ;
if ( V_31 >= 0 )
F_2 ( V_2 -> V_5 , L_33 , V_83 ) ;
else
F_20 ( V_2 -> V_5 , L_34 ) ;
F_21 ( V_83 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_62 )
{
struct V_86 * V_87 = V_2 -> V_59 ;
unsigned V_88 , V_89 ;
V_88 = F_5 ( V_87 -> V_13 ) ;
V_89 = F_5 ( V_87 -> V_90 ) ;
if ( V_88 > sizeof( V_2 -> V_7 ) ) {
F_31 ( V_2 -> V_5 , L_35 , V_88 ) ;
return;
}
switch ( V_89 ) {
case V_91 :
if ( V_62 >= sizeof( struct V_92 ) ) {
struct V_92 * error = V_2 -> V_59 ;
unsigned V_93 = F_5 ( error -> V_93 ) ;
F_1 ( V_2 , V_93 ) ;
}
break;
case V_94 :
memcpy ( & V_2 -> V_7 , V_2 -> V_59 , V_62 ) ;
V_2 -> V_95 = V_62 ;
F_10 ( V_2 -> V_5 , L_36 ,
V_2 -> V_95 , V_88 ) ;
break;
default:
F_10 ( V_2 -> V_5 , L_37 ,
V_89 , V_62 , V_88 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , unsigned V_62 )
{
void * V_7 = & V_2 -> V_7 ;
if ( V_62 + V_2 -> V_95 > sizeof( V_2 -> V_7 ) ) {
F_31 ( V_2 -> V_5 , L_38 ) ;
V_2 -> V_95 = 0 ;
return;
}
memcpy ( V_7 + V_2 -> V_95 , V_2 -> V_59 , V_62 ) ;
V_2 -> V_95 += V_62 ;
F_10 ( V_2 -> V_5 , L_36 , V_2 -> V_95 ,
F_5 ( V_2 -> V_7 . V_87 . V_13 ) ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned V_62 )
{
struct V_21 * V_5 = V_2 -> V_5 ;
unsigned V_89 ;
int V_50 = 0 ;
if ( V_2 -> V_95 == 0 && V_62 >= sizeof( struct V_86 ) ) {
F_41 ( V_2 , V_62 ) ;
} else if ( V_2 -> V_95 != 0 ) {
F_42 ( V_2 , V_62 ) ;
} else if ( V_2 -> V_95 == 0 ) {
F_20 ( V_5 , L_39 ) ;
V_50 = - V_96 ;
goto V_97;
}
if ( V_2 -> V_95 < F_5 ( V_2 -> V_7 . V_87 . V_13 ) +
sizeof( struct V_86 ) )
return 0 ;
V_89 = F_5 ( V_2 -> V_7 . V_87 . V_90 ) ;
if ( V_89 == V_94 )
F_8 ( V_2 ) ;
else
F_10 ( V_5 , L_40 ,
V_89 ) ;
V_97:
V_2 -> V_95 = 0 ;
return V_50 ;
}
static void F_44 ( struct V_98 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
int V_50 ;
switch ( V_98 -> V_100 ) {
case 0 :
V_50 = F_43 ( V_2 , V_98 -> V_101 ) ;
if ( ! V_50 && V_2 -> V_27 && ! V_2 -> V_56 -> V_102 ) {
V_50 = F_23 ( V_2 -> V_56 , V_103 ) ;
if ( V_50 )
F_20 ( V_2 -> V_5 , L_41 ,
V_50 ) ;
}
if ( ! V_50 ) {
V_50 = F_23 ( V_98 , V_103 ) ;
if ( V_50 )
F_20 ( V_2 -> V_5 , L_42 ,
V_50 ) ;
}
break;
case - V_104 :
case - V_105 :
case - V_106 :
F_45 ( V_98 ) ;
return;
case - V_107 :
default:
F_31 ( V_2 -> V_5 , L_43 , V_98 -> V_100 ) ;
V_2 -> V_95 = 0 ;
break;
}
}
static T_2 F_46 ( unsigned int V_8 )
{
int V_108 = 6000000 ;
return 65536 - ( V_108 / V_8 ) ;
}
static int F_47 ( struct V_66 * V_109 , T_1 V_30 )
{
struct V_1 * V_2 = V_109 -> V_68 ;
struct V_21 * V_5 = V_2 -> V_5 ;
F_10 ( V_5 , L_44 , V_30 ) ;
if ( V_30 == 0 )
return - V_110 ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
static int F_48 ( struct V_66 * V_109 , unsigned * V_111 ,
unsigned V_112 )
{
struct V_1 * V_2 = V_109 -> V_68 ;
struct V_21 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = NULL ;
int V_50 , V_113 ;
int V_114 , V_115 , V_63 ;
int * V_116 = NULL ;
T_3 V_117 = 0 ;
unsigned V_22 , V_118 ;
if ( V_2 -> V_4 ) {
F_31 ( V_5 , L_45 , V_48 ) ;
return - V_119 ;
}
if ( V_112 > V_120 - V_121 )
return - V_110 ;
V_2 -> V_4 = true ;
V_116 = F_40 ( V_81 ,
sizeof( * V_116 ) ,
V_42 ) ;
if ( ! V_116 )
return - V_43 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 ) {
V_50 = - V_43 ;
goto V_97;
}
for ( V_22 = 0 ; V_22 < V_112 ; V_22 ++ ) {
V_115 = F_7 ( V_111 [ V_22 ] ) ;
if ( V_115 > 0xffff ) {
F_31 ( V_5 , L_46 ,
V_111 [ V_22 ] , F_6 ( 0xffff ) ) ;
V_115 = 0xffff ;
}
for ( V_114 = 0 ; V_114 < V_117 ; V_114 ++ ) {
if ( V_116 [ V_114 ] == V_115 )
break;
}
if ( V_114 == V_117 ) {
F_10 ( V_5 , L_47 ,
V_22 , V_111 [ V_22 ] , V_117 , V_115 ) ;
if ( V_117 < V_81 ) {
V_116 [ V_117 ] = V_115 ;
F_49 ( V_115 ,
& V_7 -> V_33 [ V_117 ] ) ;
V_117 ++ ;
} else {
V_50 = - V_110 ;
goto V_97;
}
}
V_7 -> V_32 [ V_22 ] = V_114 ;
}
V_7 -> V_32 [ V_112 ] = V_122 ;
V_7 -> V_32 [ V_112 + 1 ] = V_122 ;
V_118 = F_50 ( struct V_6 ,
V_32 [ V_112 + V_121 ] ) ;
V_7 -> V_87 . V_13 = F_51 ( V_118 -
sizeof( struct V_86 ) ) ;
V_7 -> V_87 . V_90 = F_51 ( V_123 ) ;
V_7 -> V_124 = F_35 ( F_6 ( 100 ) ) ;
V_7 -> V_9 = F_51 ( F_46 ( V_2 -> V_30 ) ) ;
V_7 -> V_125 = V_117 ;
V_7 -> V_23 = F_51 ( V_112 + V_121 ) ;
V_63 = F_52 ( V_2 -> V_39 , V_2 -> V_126 -> V_127 ) ;
V_50 = F_53 ( V_2 -> V_39 , V_63 , V_7 ,
V_118 , & V_113 , 10 * V_47 ) ;
F_10 ( V_5 , L_48 , V_113 , V_50 ) ;
V_63 = F_19 ( V_2 -> V_39 , 0 ) ;
V_50 = F_18 ( V_2 -> V_39 , V_63 , V_128 ,
V_44 | V_45 | V_46 ,
0 , 0 , V_7 , 2 , V_47 * 10 ) ;
if ( V_50 < 0 )
F_20 ( V_5 , L_49 , V_50 ) ;
else
V_50 = V_112 ;
V_97:
F_21 ( V_7 ) ;
F_21 ( V_116 ) ;
V_2 -> V_4 = false ;
return V_50 ;
}
static void F_54 ( struct V_129 * V_130 , enum
V_131 V_132 )
{
struct V_1 * V_2 = F_55 ( V_130 , struct V_1 ,
V_133 ) ;
if ( V_132 != V_134 && F_56 ( & V_2 -> V_135 , 0 , 1 ) == 0 ) {
int V_50 = F_23 ( V_2 -> V_55 , V_103 ) ;
if ( V_50 != 0 ) {
F_10 ( V_2 -> V_5 , L_21 ,
V_48 , V_50 ) ;
F_57 ( & V_2 -> V_135 , 0 ) ;
}
}
}
static int F_58 ( struct V_66 * V_109 , int V_136 )
{
struct V_1 * V_2 = V_109 -> V_68 ;
int V_50 = 0 ;
V_2 -> V_27 = V_136 != 0 ;
if ( V_136 ) {
V_50 = F_23 ( V_2 -> V_56 , V_42 ) ;
if ( V_50 )
F_20 ( V_2 -> V_5 , L_41 ,
V_50 ) ;
}
return V_50 ;
}
static void F_59 ( struct V_98 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
switch ( V_98 -> V_100 ) {
case 0 :
break;
case - V_104 :
case - V_105 :
case - V_106 :
F_45 ( V_98 ) ;
return;
case - V_107 :
default:
F_20 ( V_2 -> V_5 , L_50 , V_98 -> V_100 ) ;
break;
}
}
static void F_60 ( struct V_98 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
switch ( V_98 -> V_100 ) {
case 0 :
break;
case - V_104 :
case - V_105 :
case - V_106 :
F_45 ( V_98 ) ;
return;
case - V_107 :
default:
F_10 ( V_2 -> V_5 , L_43 , V_98 -> V_100 ) ;
break;
}
V_2 -> V_133 . V_132 = V_134 ;
F_61 ( & V_2 -> V_135 ) ;
}
static struct V_66 * F_62 ( struct V_1 * V_2 )
{
struct V_21 * V_5 = V_2 -> V_5 ;
struct V_66 * V_31 ;
int V_50 ;
T_2 V_137 = F_28 ( V_2 -> V_39 -> V_138 . V_139 ) ;
V_31 = F_63 () ;
if ( ! V_31 )
return NULL ;
snprintf ( V_2 -> V_140 , sizeof( V_2 -> V_140 ) ,
L_51 ,
V_137 == V_141 ? L_52 : L_53 ) ;
F_64 ( V_2 -> V_39 , V_2 -> V_142 , sizeof( V_2 -> V_142 ) ) ;
V_31 -> V_143 = V_2 -> V_140 ;
V_31 -> V_144 = V_2 -> V_142 ;
F_65 ( V_2 -> V_39 , & V_31 -> V_145 ) ;
V_31 -> V_5 . V_146 = V_5 ;
V_31 -> V_68 = V_2 ;
V_31 -> V_147 = V_148 ;
V_31 -> V_149 = V_150 ;
V_31 -> V_151 = F_66 ( V_152 ) ;
V_31 -> V_153 = F_66 ( V_154 ) ;
V_31 -> V_36 = F_13 ( F_29 ( V_2 ) ) ;
V_31 -> V_155 = F_33 ;
V_31 -> V_156 = F_48 ;
V_31 -> V_157 = F_47 ;
V_31 -> V_158 = F_58 ;
V_31 -> V_159 = V_160 ;
V_31 -> V_161 = F_13 ( 2 ) ;
V_31 -> V_162 = V_163 ;
V_50 = F_67 ( V_31 ) ;
if ( V_50 < 0 ) {
F_20 ( V_5 , L_54 ) ;
goto V_97;
}
return V_31 ;
V_97:
F_68 ( V_31 ) ;
return NULL ;
}
static int F_69 ( struct V_164 * V_165 ,
const struct V_166 * V_167 )
{
struct V_38 * V_39 = F_70 ( V_165 ) ;
struct V_21 * V_5 = & V_165 -> V_5 ;
struct V_168 * V_169 ;
struct V_1 * V_2 ;
struct V_170 * V_171 ;
struct V_170 * V_57 = NULL ;
struct V_170 * V_172 = NULL ;
struct V_170 * V_126 = NULL ;
T_3 V_173 , V_174 ;
int V_63 , V_22 ;
int V_175 = - V_43 ;
V_169 = V_165 -> V_176 ;
for ( V_22 = 0 ; V_22 < V_169 -> V_177 . V_178 ; ++ V_22 ) {
V_171 = & V_169 -> V_179 [ V_22 ] . V_177 ;
V_173 = V_171 -> V_127 ;
V_174 = V_171 -> V_180 ;
if ( ( ( V_173 & V_181 ) == V_46 ) &&
( ( V_174 & V_182 ) ==
V_183 ) ) {
F_10 ( V_5 , L_55 ,
V_171 -> V_127 ) ;
if ( V_171 -> V_127 == V_184 )
V_57 = V_171 ;
if ( V_171 -> V_127 == V_185 )
V_172 = V_171 ;
}
if ( ( V_126 == NULL ) &&
( ( V_173 & V_181 ) == V_70 ) &&
( ( V_174 & V_182 ) ==
V_183 ) ) {
F_10 ( V_5 , L_56 ,
V_171 -> V_127 ) ;
V_126 = V_171 ;
}
}
if ( ! V_57 || ! V_126 || ! V_172 ) {
F_20 ( V_5 , L_57 ) ;
V_175 = - V_186 ;
goto V_187;
}
V_2 = F_17 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
goto V_187;
V_2 -> V_5 = & V_165 -> V_5 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_126 = V_126 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_53 = F_71 ( 0 , V_42 ) ;
if ( ! V_2 -> V_53 )
goto V_188;
V_2 -> V_54 = F_71 ( 0 , V_42 ) ;
if ( ! V_2 -> V_54 )
goto V_188;
V_2 -> V_59 = F_72 ( V_39 ,
F_28 ( V_57 -> V_58 ) ,
V_42 , & V_2 -> V_60 ) ;
if ( ! V_2 -> V_59 )
goto V_188;
V_63 = F_73 ( V_39 , V_57 -> V_127 ) ;
F_74 ( V_2 -> V_53 , V_39 , V_63 , V_2 -> V_59 ,
F_28 ( V_57 -> V_58 ) ,
F_44 , V_2 ) ;
V_2 -> V_53 -> V_189 = V_2 -> V_60 ;
V_2 -> V_53 -> V_190 |= V_191 ;
V_63 = F_73 ( V_39 , V_172 -> V_127 ) ;
F_74 ( V_2 -> V_54 , V_39 , V_63 , V_2 -> V_59 ,
F_28 ( V_57 -> V_58 ) ,
F_44 , V_2 ) ;
V_2 -> V_54 -> V_189 = V_2 -> V_60 ;
V_2 -> V_54 -> V_190 |= V_191 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_2 -> V_30 = 38000 ;
F_57 ( & V_2 -> V_135 , 0 ) ;
V_2 -> V_55 = F_71 ( 0 , V_42 ) ;
if ( ! V_2 -> V_55 )
goto V_188;
V_2 -> V_56 = F_71 ( 0 , V_42 ) ;
if ( ! V_2 -> V_56 )
goto V_188;
V_2 -> V_192 . V_193 = 0xc0 ;
V_2 -> V_192 . V_194 = V_195 ;
V_2 -> V_192 . V_196 = F_75 ( 1 ) ;
F_76 ( V_2 -> V_56 , V_39 , F_19 ( V_39 , 0 ) ,
( unsigned char * ) & V_2 -> V_192 ,
& V_2 -> V_197 , sizeof( V_2 -> V_197 ) ,
F_59 , V_2 ) ;
V_2 -> V_198 . V_193 = 0xc0 ;
V_2 -> V_198 . V_194 = V_199 ;
V_2 -> V_198 . V_196 = F_75 ( 1 ) ;
F_76 ( V_2 -> V_55 , V_39 , F_19 ( V_39 , 0 ) ,
( unsigned char * ) & V_2 -> V_198 ,
& V_2 -> V_200 , sizeof( V_2 -> V_200 ) ,
F_60 , V_2 ) ;
V_2 -> V_133 . V_140 = L_58 ;
V_2 -> V_133 . V_201 = L_59 ;
V_2 -> V_133 . V_202 = F_54 ;
V_175 = F_77 ( & V_165 -> V_5 , & V_2 -> V_133 ) ;
if ( V_175 )
goto V_188;
V_2 -> V_31 = F_62 ( V_2 ) ;
if ( ! V_2 -> V_31 ) {
V_175 = - V_43 ;
goto V_203;
}
V_175 = F_22 ( V_2 ) ;
if ( V_175 < 0 )
goto V_203;
F_78 ( V_165 , V_2 ) ;
return 0 ;
V_203:
F_79 ( & V_2 -> V_133 ) ;
V_188:
F_24 ( V_2 , V_2 -> V_39 ) ;
V_187:
return V_175 ;
}
static void F_80 ( struct V_164 * V_165 )
{
struct V_38 * V_39 = F_70 ( V_165 ) ;
struct V_1 * V_2 = F_81 ( V_165 ) ;
F_78 ( V_165 , NULL ) ;
F_82 ( V_2 -> V_31 ) ;
F_79 ( & V_2 -> V_133 ) ;
F_24 ( V_2 , V_39 ) ;
}
static int F_83 ( struct V_164 * V_165 , T_6 V_204 )
{
struct V_1 * V_2 = F_81 ( V_165 ) ;
F_84 ( & V_2 -> V_133 ) ;
F_25 ( V_2 -> V_53 ) ;
F_25 ( V_2 -> V_54 ) ;
F_25 ( V_2 -> V_55 ) ;
return 0 ;
}
static int F_85 ( struct V_164 * V_165 )
{
struct V_1 * V_2 = F_81 ( V_165 ) ;
if ( F_23 ( V_2 -> V_53 , V_103 ) )
return - V_49 ;
if ( F_23 ( V_2 -> V_54 , V_103 ) )
return - V_49 ;
F_86 ( & V_2 -> V_133 ) ;
return 0 ;
}
