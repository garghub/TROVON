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
V_2 -> V_56 = true ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
T_3 V_53 ;
F_2 ( V_4 , L_1 , V_5 ) ;
V_53 = F_23 ( V_57 , V_2 ) ;
if ( V_53 != 0 )
F_27 ( V_4 , L_34 , V_5 ) ;
V_53 = F_23 ( V_55 , V_2 ) ;
if ( V_53 != 0 )
F_32 ( V_4 , L_35 ,
V_5 , V_53 ) ;
V_2 -> V_56 = false ;
}
static inline void F_33 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
F_2 ( V_2 -> V_4 , L_36 , V_5 ) ;
F_34 ( V_2 -> V_6 ) ;
F_35 ( V_2 -> V_6 ) ;
F_36 ( V_45 , F_37 ( V_2 -> V_58 -> V_59 ) ,
V_2 -> V_60 , V_2 -> V_61 ) ;
F_28 ( V_2 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
T_4 * V_62 ;
T_1 V_63 = F_39 ( 150 ) ;
int V_64 , V_53 , V_65 ;
V_64 = sizeof( * V_62 ) ;
V_62 = F_24 ( V_64 , V_46 ) ;
if ( ! V_62 ) {
F_32 ( V_2 -> V_4 , L_37 ) ;
return V_63 ;
}
V_65 = F_26 ( V_2 -> V_45 , 0 ) ;
V_53 = F_25 ( V_2 -> V_45 , V_65 , V_66 ,
V_48 | V_49 | V_50 ,
V_67 , 0 , V_62 , V_64 , V_51 * 5 ) ;
if ( V_53 != V_64 )
F_32 ( V_2 -> V_4 , L_38 ) ;
else {
V_63 = F_10 ( F_40 ( V_62 ) ) ;
F_4 ( V_2 -> V_4 , L_39 , V_63 / 1000 ) ;
}
F_28 ( V_62 ) ;
return V_63 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_28 * V_4 = V_2 -> V_4 ;
int V_26 , V_68 , V_69 ;
T_3 * V_34 ;
int V_64 = sizeof( T_3 ) ;
F_2 ( V_4 , L_1 , V_5 ) ;
V_68 = F_26 ( V_45 , 0 ) ;
V_69 = F_42 ( V_45 , 0 ) ;
V_34 = F_43 ( V_64 , V_46 ) ;
if ( ! V_34 ) {
F_27 ( V_4 , L_40 ) ;
return;
}
* V_34 = 0x01 ;
V_26 = F_25 ( V_45 , V_68 , V_70 ,
V_48 | V_49 | V_50 ,
V_71 , 0 , V_34 , V_64 , V_51 * 25 ) ;
F_4 ( V_4 , L_41 , V_26 ) ;
* V_34 = 5 ;
V_26 = F_25 ( V_45 , V_69 , V_72 ,
V_48 | V_49 | V_73 ,
V_74 , 0 , V_34 , V_64 , V_51 * 25 ) ;
F_4 ( V_4 , L_42 , * V_34 , V_26 ) ;
* V_34 = V_75 ;
V_26 = F_25 ( V_45 , V_69 , V_72 ,
V_48 | V_49 | V_73 ,
V_76 , 0 , V_34 , V_64 , V_51 * 25 ) ;
F_4 ( V_4 , L_43 , * V_34 , V_26 ) ;
F_28 ( V_34 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
char * V_77 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_77 = F_24 ( sizeof( char ) * ( V_78 + 1 ) , V_46 ) ;
if ( ! V_77 ) {
F_27 ( V_2 -> V_4 , L_40 ) ;
return;
}
V_26 = F_25 ( V_2 -> V_45 , F_26 ( V_2 -> V_45 , 0 ) ,
V_79 ,
V_48 | V_49 | V_50 ,
0 , 0 , V_77 , V_78 , V_51 * 5 ) ;
if ( V_26 >= 0 )
F_6 ( V_2 -> V_4 , L_44 , V_77 ) ;
else
F_27 ( V_2 -> V_4 , L_45 ) ;
F_28 ( V_77 ) ;
F_2 ( V_2 -> V_4 , L_46 , V_5 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned V_64 )
{
struct V_80 * V_81 = V_2 -> V_60 ;
unsigned V_82 , V_83 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
V_82 = F_9 ( V_81 -> V_18 ) ;
V_83 = F_9 ( V_81 -> V_84 ) ;
if ( V_82 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_4 , L_47 , V_82 ) ;
return;
}
switch ( V_83 ) {
case V_85 :
if ( V_64 >= sizeof( struct V_86 ) ) {
struct V_86 * error = V_2 -> V_60 ;
unsigned V_87 = F_9 ( error -> V_87 ) ;
F_5 ( V_2 , V_87 ) ;
}
break;
case V_88 :
memcpy ( & V_2 -> V_12 , V_2 -> V_60 , V_64 ) ;
V_2 -> V_89 = V_64 ;
F_4 ( V_2 -> V_4 , L_48 ,
V_2 -> V_89 , V_82 ) ;
break;
default:
F_4 ( V_2 -> V_4 , L_49 ,
V_83 , V_64 , V_82 ) ;
break;
}
}
static void F_46 ( struct V_1 * V_2 , unsigned V_64 )
{
void * V_12 = & V_2 -> V_12 ;
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
if ( V_64 + V_2 -> V_89 > sizeof( V_2 -> V_12 ) ) {
F_32 ( V_2 -> V_4 , L_50 ) ;
V_2 -> V_89 = 0 ;
return;
}
memcpy ( V_12 + V_2 -> V_89 , V_2 -> V_60 , V_64 ) ;
V_2 -> V_89 += V_64 ;
F_4 ( V_2 -> V_4 , L_48 , V_2 -> V_89 ,
F_9 ( V_2 -> V_12 . V_81 . V_18 ) ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned V_64 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
unsigned V_83 ;
int V_53 = 0 ;
F_2 ( V_4 , L_1 , V_5 ) ;
if ( V_2 -> V_89 == 0 && V_64 >= sizeof( struct V_80 ) ) {
F_45 ( V_2 , V_64 ) ;
} else if ( V_2 -> V_89 != 0 ) {
F_46 ( V_2 , V_64 ) ;
} else if ( V_2 -> V_89 == 0 ) {
F_27 ( V_4 , L_51 ) ;
V_53 = - V_90 ;
goto V_91;
}
if ( V_2 -> V_89 < F_9 ( V_2 -> V_12 . V_81 . V_18 ) )
return 0 ;
V_83 = F_9 ( V_2 -> V_12 . V_81 . V_84 ) ;
if ( V_83 == V_88 )
F_14 ( V_2 ) ;
else
F_4 ( V_4 , L_52 ,
V_83 ) ;
V_91:
V_2 -> V_89 = 0 ;
return V_53 ;
}
static void F_48 ( struct V_92 * V_92 )
{
struct V_1 * V_2 ;
int V_53 ;
if ( ! V_92 )
return;
V_2 = V_92 -> V_93 ;
if ( ! V_2 ) {
F_16 ( L_53 , V_5 ) ;
F_49 ( V_92 ) ;
return;
}
F_2 ( V_2 -> V_4 , L_1 , V_5 ) ;
switch ( V_92 -> V_94 ) {
case 0 :
V_53 = F_47 ( V_2 , V_92 -> V_95 ) ;
if ( ! V_53 ) {
F_1 ( V_2 ) ;
}
break;
case - V_96 :
case - V_97 :
case - V_98 :
F_49 ( V_92 ) ;
return;
case - V_99 :
default:
F_32 ( V_2 -> V_4 , L_54 , V_92 -> V_94 ) ;
V_2 -> V_89 = 0 ;
break;
}
}
static T_2 F_50 ( unsigned int V_13 )
{
int V_100 = 6000000 ;
return 65536 - ( V_100 / V_13 ) ;
}
static int F_51 ( struct V_101 * V_102 , T_1 V_103 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
struct V_28 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , L_55 , V_103 ) ;
if ( V_103 == 0 )
return - V_105 ;
V_2 -> V_103 = V_103 ;
return V_103 ;
}
static int F_52 ( struct V_101 * V_102 , unsigned * V_106 ,
unsigned V_107 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
struct V_28 * V_4 = V_2 -> V_4 ;
struct V_11 * V_12 = NULL ;
int V_53 , V_108 ;
int V_109 , V_110 , V_65 ;
int * V_111 = NULL ;
T_3 V_112 = 0 ;
unsigned V_29 , V_113 ;
F_2 ( V_4 , L_1 , V_5 ) ;
if ( V_2 -> V_10 ) {
F_32 ( V_4 , L_56 , V_5 ) ;
return - V_114 ;
}
V_107 = F_53 ( unsigned , V_107 , V_115 - V_116 ) ;
V_2 -> V_56 = false ;
V_2 -> V_10 = true ;
V_111 = F_24 ( sizeof( int ) * V_75 , V_46 ) ;
if ( ! V_111 ) {
V_53 = - V_47 ;
goto V_91;
}
V_12 = F_24 ( sizeof( * V_12 ) , V_46 ) ;
if ( ! V_12 ) {
V_53 = - V_47 ;
goto V_91;
}
for ( V_29 = 0 ; V_29 < V_107 ; V_29 ++ ) {
V_110 = F_11 ( V_106 [ V_29 ] ) ;
if ( V_110 > 0xffff ) {
F_32 ( V_4 , L_57 ,
V_106 [ V_29 ] , F_10 ( 0xffff ) ) ;
V_110 = 0xffff ;
}
for ( V_109 = 0 ; V_109 < V_112 ; V_109 ++ ) {
if ( V_111 [ V_109 ] == V_110 )
break;
}
if ( V_109 == V_112 ) {
F_4 ( V_4 , L_58 ,
V_29 , V_106 [ V_29 ] , V_112 , V_110 ) ;
if ( V_112 < V_75 ) {
V_111 [ V_112 ] = V_110 ;
F_54 ( V_110 ,
& V_12 -> V_40 [ V_112 ] ) ;
V_112 ++ ;
} else {
V_107 = V_29 - 1 ;
break;
}
}
V_12 -> V_39 [ V_29 ] = V_109 ;
}
V_12 -> V_39 [ V_107 ] = V_117 ;
V_12 -> V_39 [ V_107 + 1 ] = V_117 ;
V_113 = F_55 ( struct V_11 ,
V_39 [ V_107 + V_116 ] ) ;
V_12 -> V_81 . V_18 = F_56 ( V_113 -
sizeof( struct V_80 ) ) ;
V_12 -> V_81 . V_84 = F_56 ( V_118 ) ;
V_12 -> V_119 = F_57 ( F_10 ( 100 ) ) ;
V_12 -> V_14 = F_56 ( F_50 ( V_2 -> V_103 ) ) ;
V_12 -> V_120 = V_112 ;
V_12 -> V_31 = F_56 ( V_107 + V_116 ) ;
V_65 = F_58 ( V_2 -> V_45 , V_2 -> V_121 -> V_122 ) ;
V_53 = F_59 ( V_2 -> V_45 , V_65 , V_12 ,
V_113 , & V_108 , 10 * V_51 ) ;
F_4 ( V_4 , L_59 , V_108 , V_53 ) ;
V_65 = F_26 ( V_2 -> V_45 , 0 ) ;
V_53 = F_25 ( V_2 -> V_45 , V_65 , V_123 ,
V_48 | V_49 | V_50 ,
0 , 0 , V_12 , 2 , V_51 * 10 ) ;
if ( V_53 < 0 )
F_27 ( V_4 , L_60 , V_53 ) ;
else
V_53 = V_107 ;
V_91:
F_28 ( V_111 ) ;
F_28 ( V_12 ) ;
V_2 -> V_10 = false ;
V_2 -> V_56 = true ;
return V_53 ;
}
static struct V_101 * F_60 ( struct V_1 * V_2 )
{
struct V_28 * V_4 = V_2 -> V_4 ;
struct V_101 * V_26 ;
int V_53 = - V_124 ;
T_2 V_125 = F_37 ( V_2 -> V_45 -> V_126 . V_127 ) ;
V_26 = F_61 () ;
if ( ! V_26 ) {
F_27 ( V_4 , L_61 ) ;
goto V_91;
}
snprintf ( V_2 -> V_128 , sizeof( V_2 -> V_128 ) , L_62
L_63 ,
V_125 == V_129 ? L_64 : L_65 ,
F_37 ( V_2 -> V_45 -> V_126 . V_130 ) , V_125 ) ;
F_62 ( V_2 -> V_45 , V_2 -> V_131 , sizeof( V_2 -> V_131 ) ) ;
V_26 -> V_132 = V_2 -> V_128 ;
V_26 -> V_133 = V_2 -> V_131 ;
F_63 ( V_2 -> V_45 , & V_26 -> V_134 ) ;
V_26 -> V_4 . V_135 = V_4 ;
V_26 -> V_104 = V_2 ;
V_26 -> V_136 = V_137 ;
V_26 -> V_138 = V_139 ;
V_26 -> V_63 = F_20 ( 2750 ) ;
V_26 -> V_140 = F_52 ;
V_26 -> V_141 = F_51 ;
V_26 -> V_142 = V_143 ;
V_26 -> V_144 = F_20 ( 2 ) ;
V_26 -> V_145 = V_146 ;
V_53 = F_64 ( V_26 ) ;
if ( V_53 < 0 ) {
F_27 ( V_4 , L_66 ) ;
goto V_91;
}
return V_26 ;
V_91:
F_65 ( V_26 ) ;
return NULL ;
}
static int F_66 ( struct V_147 * V_148 ,
const struct V_149 * V_150 )
{
struct V_44 * V_45 = F_67 ( V_148 ) ;
struct V_28 * V_4 = & V_148 -> V_4 ;
struct V_151 * V_152 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
struct V_153 * V_58 = NULL ;
struct V_153 * V_121 = NULL ;
T_3 V_155 , V_156 ;
int V_65 , V_29 ;
int V_157 = - V_47 ;
F_2 ( V_4 , L_67 , V_5 ) ;
V_152 = V_148 -> V_158 ;
for ( V_29 = 0 ; V_29 < V_152 -> V_159 . V_160 ; ++ V_29 ) {
V_154 = & V_152 -> V_161 [ V_29 ] . V_159 ;
V_155 = V_154 -> V_122 ;
V_156 = V_154 -> V_162 ;
if ( ( V_58 == NULL ) &&
( ( V_155 & V_163 ) == V_50 ) &&
( ( V_156 & V_164 ) ==
V_165 ) ) {
F_4 ( V_4 , L_68 ,
V_154 -> V_122 ) ;
if ( V_154 -> V_122 == V_166 )
V_58 = V_154 ;
}
if ( ( V_121 == NULL ) &&
( ( V_155 & V_163 ) == V_73 ) &&
( ( V_156 & V_164 ) ==
V_165 ) ) {
F_4 ( V_4 , L_69 ,
V_154 -> V_122 ) ;
V_121 = V_154 ;
}
}
if ( ! V_58 || ! V_121 ) {
F_27 ( V_4 , L_70 ) ;
V_157 = - V_124 ;
goto V_167;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_46 ) ;
if ( V_2 == NULL ) {
F_27 ( V_4 , L_40 ) ;
goto V_167;
}
V_2 -> V_4 = & V_148 -> V_4 ;
V_2 -> V_6 = F_68 ( 0 , V_46 ) ;
if ( ! V_2 -> V_6 ) {
F_27 ( V_4 , L_71 ) ;
goto error;
}
V_2 -> V_58 = V_58 ;
V_2 -> V_60 = F_69 ( V_45 ,
F_37 ( V_58 -> V_59 ) , V_7 , & V_2 -> V_61 ) ;
if ( ! V_2 -> V_60 ) {
F_27 ( V_4 , L_72 ) ;
goto error;
}
V_65 = F_70 ( V_45 , V_58 -> V_122 ) ;
F_71 ( V_2 -> V_6 , V_45 , V_65 , V_2 -> V_60 ,
F_37 ( V_58 -> V_59 ) , F_48 , V_2 ) ;
V_2 -> V_121 = V_121 ;
V_2 -> V_45 = V_45 ;
F_41 ( V_2 ) ;
F_44 ( V_2 ) ;
V_157 = F_29 ( V_2 ) ;
if ( V_157 < 0 )
goto error;
V_2 -> V_36 = F_38 ( V_2 ) ;
V_2 -> V_103 = 38000 ;
V_2 -> V_26 = F_60 ( V_2 ) ;
if ( ! V_2 -> V_26 ) {
V_157 = - V_47 ;
goto error;
}
F_72 ( & V_2 -> V_37 , F_12 , ( unsigned long ) V_2 ) ;
F_73 ( V_148 , V_2 ) ;
F_2 ( V_4 , L_46 , V_5 ) ;
return 0 ;
error:
F_33 ( V_2 , V_2 -> V_45 ) ;
V_167:
F_27 ( V_4 , L_73 , V_5 , V_157 ) ;
return V_157 ;
}
static void F_74 ( struct V_147 * V_148 )
{
struct V_44 * V_45 = F_67 ( V_148 ) ;
struct V_1 * V_2 = F_75 ( V_148 ) ;
F_2 ( & V_148 -> V_4 , L_1 , V_5 ) ;
if ( ! V_2 )
return;
F_31 ( V_2 ) ;
F_73 ( V_148 , NULL ) ;
F_76 ( V_2 -> V_26 ) ;
F_77 ( & V_2 -> V_37 ) ;
F_33 ( V_2 , V_45 ) ;
F_2 ( & V_148 -> V_4 , L_74 ) ;
}
static int F_78 ( struct V_147 * V_148 , T_5 V_168 )
{
struct V_1 * V_2 = F_75 ( V_148 ) ;
F_2 ( V_2 -> V_4 , L_75 ) ;
F_34 ( V_2 -> V_6 ) ;
return 0 ;
}
static int F_79 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_75 ( V_148 ) ;
F_2 ( V_2 -> V_4 , L_76 ) ;
if ( F_3 ( V_2 -> V_6 , V_7 ) )
return - V_52 ;
return 0 ;
}
