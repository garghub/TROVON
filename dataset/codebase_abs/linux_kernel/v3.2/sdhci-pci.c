static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == V_5 ||
V_2 -> V_3 -> V_4 == V_6 )
V_2 -> V_7 |= V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_12 =
( ( 0x21 << V_13 )
& V_14 ) |
( ( 0x21 << V_15 )
& V_16 ) |
V_17 |
V_18 |
V_19 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_21 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_22 = 1 ;
return 0 ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
struct V_27 * V_28 ;
int V_29 , V_30 ;
V_30 = F_8 ( V_26 , struct V_27 ) ;
V_28 = (struct V_27 * ) V_26 -> V_31 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ , V_28 ++ ) {
if ( ! strncmp ( V_28 -> V_32 , L_1 , V_33 ) )
V_34 = V_28 -> V_35 ;
else if ( ! strncmp ( V_28 -> V_32 , L_2 , V_33 ) )
V_36 = V_28 -> V_35 ;
}
return 0 ;
}
static T_1 F_9 ( int V_37 , void * V_38 )
{
struct V_9 * V_10 = V_38 ;
struct V_39 * V_11 = V_10 -> V_11 ;
F_10 ( V_11 -> V_20 , F_11 ( 200 ) ) ;
return V_40 ;
}
static int F_12 ( struct V_9 * V_10 )
{
int V_41 , V_37 , V_42 = V_43 ;
V_10 -> V_44 = - V_45 ;
V_10 -> V_46 = - V_45 ;
V_41 = F_13 ( V_42 , L_3 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_14 ( V_42 ) ;
if ( V_41 < 0 )
goto V_48;
V_37 = F_15 ( V_42 ) ;
if ( V_37 < 0 )
goto V_48;
V_41 = F_16 ( V_37 , F_9 , V_49 |
V_50 , L_3 , V_10 ) ;
if ( V_41 )
goto V_48;
V_10 -> V_44 = V_42 ;
V_10 -> V_46 = V_37 ;
V_10 -> V_11 -> V_51 |= V_52 ;
return 0 ;
V_48:
F_17 ( V_42 ) ;
V_47:
F_18 ( & V_10 -> V_2 -> V_3 -> V_53 , L_4 ) ;
return 0 ;
}
static void F_19 ( struct V_9 * V_10 , int V_54 )
{
if ( V_10 -> V_46 >= 0 )
F_20 ( V_10 -> V_46 , V_10 ) ;
F_17 ( V_10 -> V_44 ) ;
}
static int F_21 ( struct V_9 * V_10 )
{
const char * V_55 = NULL ;
int V_42 = - V_45 ;
F_22 ( V_56 , NULL , NULL , F_7 ) ;
switch ( V_10 -> V_2 -> V_3 -> V_57 ) {
case V_58 :
V_42 = V_34 ;
V_55 = L_5 ;
break;
case V_59 :
V_42 = V_36 ;
V_55 = L_6 ;
break;
}
if ( ! F_13 ( V_42 , V_55 ) ) {
F_23 ( V_42 , 1 ) ;
V_10 -> V_60 = V_42 ;
V_10 -> V_11 -> V_20 -> V_12 |= V_61 ;
}
V_10 -> V_11 -> V_20 -> V_12 |= V_21 | V_62 ;
V_10 -> V_11 -> V_20 -> V_63 = V_64 ;
return 0 ;
}
static void F_24 ( struct V_9 * V_10 , int V_54 )
{
F_17 ( V_10 -> V_60 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_65 ;
T_2 V_66 ;
switch ( V_2 -> V_3 -> V_57 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_65 = F_26 ( V_2 -> V_3 , V_71 , & V_66 ) ;
if ( V_65 )
return V_65 ;
V_66 &= 0x7f ;
F_27 ( V_2 -> V_3 , V_71 , V_66 ) ;
F_27 ( V_2 -> V_3 , V_72 , 0x08 ) ;
V_65 = F_26 ( V_2 -> V_3 , V_73 , & V_66 ) ;
if ( V_65 )
return V_65 ;
V_66 |= 0x20 ;
F_27 ( V_2 -> V_3 , V_73 , V_66 ) ;
V_65 = F_26 ( V_2 -> V_3 , V_74 , & V_66 ) ;
if ( V_65 )
return V_65 ;
V_66 |= 0x01 ;
F_27 ( V_2 -> V_3 , V_74 , V_66 ) ;
F_27 ( V_2 -> V_3 , V_74 , 0x73 ) ;
F_27 ( V_2 -> V_3 , V_75 , 0x39 ) ;
F_27 ( V_2 -> V_3 , V_76 , 0x08 ) ;
V_65 = F_26 ( V_2 -> V_3 , V_77 , & V_66 ) ;
if ( V_65 )
return V_65 ;
V_66 |= 0x08 ;
F_27 ( V_2 -> V_3 , V_77 , V_66 ) ;
V_65 = F_26 ( V_2 -> V_3 , V_71 , & V_66 ) ;
if ( V_65 )
return V_65 ;
V_66 |= 0x80 ;
F_27 ( V_2 -> V_3 , V_71 , V_66 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_78 )
{
T_2 V_66 ;
int V_65 ;
V_65 = F_26 ( V_2 -> V_3 , 0xAE , & V_66 ) ;
if ( V_65 )
return V_65 ;
if ( V_78 )
V_66 |= 0x47 ;
else
V_66 &= ~ 0x47 ;
V_65 = F_27 ( V_2 -> V_3 , 0xAE , V_66 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_65 ;
T_3 V_79 = 0 ;
if ( V_2 -> V_3 -> V_80 == 0 ) {
V_2 -> V_7 |= V_81 |
V_82 |
V_83 |
V_84 |
V_85 ;
}
if ( V_2 -> V_3 -> V_57 == V_86 )
V_79 = V_87 ;
else if ( V_2 -> V_3 -> V_57 == V_88 )
V_79 = V_89 ;
if ( V_79 ) {
struct V_90 * V_91 ;
V_91 = NULL ;
while ( ( V_91 = F_30 ( V_92 ,
V_79 , V_91 ) ) != NULL ) {
if ( ( F_31 ( V_2 -> V_3 -> V_93 ) ==
F_31 ( V_91 -> V_93 ) ) &&
( V_2 -> V_3 -> V_94 == V_91 -> V_94 ) )
break;
}
if ( V_91 ) {
F_32 ( V_91 ) ;
F_33 ( & V_2 -> V_3 -> V_53 , L_7
L_8 ) ;
return - V_95 ;
}
}
V_65 = F_28 ( V_2 , 1 ) ;
if ( V_65 ) {
F_34 ( & V_2 -> V_3 -> V_53 , L_9 ) ;
return V_65 ;
}
if ( V_2 -> V_3 -> V_57 == V_88 ||
V_2 -> V_3 -> V_57 == V_89 )
V_2 -> V_7 |= V_96 ;
return 0 ;
}
static void F_35 ( struct V_39 * V_11 , int V_78 )
{
T_2 V_66 ;
V_66 = F_36 ( V_11 -> V_97 + 0xC0 ) ;
if ( V_78 )
V_66 |= 0x01 ;
else
V_66 &= ~ 0x01 ;
F_37 ( V_66 , V_11 -> V_97 + 0xC0 ) ;
}
static int F_38 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_80 == 0 ) {
T_3 V_98 ;
V_98 = F_39 ( V_10 -> V_11 -> V_97 + V_99 ) ;
V_98 = ( V_98 & V_100 ) >>
V_101 ;
if ( V_98 < 0xAC )
V_10 -> V_11 -> V_7 |= V_102 ;
}
if ( V_10 -> V_2 -> V_3 -> V_57 == V_89 ) {
V_10 -> V_11 -> V_103 = V_104 | V_105 |
V_106 | V_107 |
V_108 ;
V_10 -> V_11 -> V_109 = V_104 | V_105 |
V_106 | V_107 ;
}
if ( V_10 -> V_2 -> V_3 -> V_57 == V_87 ||
V_10 -> V_2 -> V_3 -> V_57 == V_89 )
F_35 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_110 ;
return 0 ;
}
static void F_40 ( struct V_9 * V_10 , int V_54 )
{
if ( V_54 )
return;
if ( V_10 -> V_2 -> V_3 -> V_57 == V_87 ||
V_10 -> V_2 -> V_3 -> V_57 == V_89 )
F_35 ( V_10 -> V_11 , 0 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_29 ;
if ( V_2 -> V_3 -> V_57 == V_87 ||
V_2 -> V_3 -> V_57 == V_89 ) {
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ )
F_35 ( V_2 -> V_111 [ V_29 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_65 , V_29 ;
if ( V_2 -> V_3 -> V_57 == V_87 ||
V_2 -> V_3 -> V_57 == V_89 ) {
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ )
F_35 ( V_2 -> V_111 [ V_29 ] -> V_11 , 1 ) ;
}
V_65 = F_28 ( V_2 , 1 ) ;
if ( V_65 ) {
F_34 ( & V_2 -> V_3 -> V_53 , L_9 ) ;
return V_65 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_112 & 0x0000FF ) == V_113 ) {
V_2 -> V_3 -> V_112 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_112 |= V_114 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_115 , V_116 ;
T_2 V_117 = F_36 ( V_10 -> V_11 -> V_97 + V_118 ) ;
T_2 V_119 = F_36 ( V_10 -> V_11 -> V_97 + V_120 ) ;
F_33 ( & V_10 -> V_2 -> V_3 -> V_53 , L_10
L_11 ,
V_117 >> 4 , V_117 & 0xf ,
V_119 >> 4 , V_119 & 0xf ) ;
if ( V_119 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_121 ;
F_37 ( V_122 , V_10 -> V_11 -> V_97 + V_123 ) ;
F_37 ( V_124 , V_10 -> V_11 -> V_97 + V_125 ) ;
F_45 ( 50 ) ;
V_115 = 10 ;
do {
V_116 = F_46 ( V_10 -> V_11 -> V_97 + V_126 ) ;
if ( V_116 & V_127 )
break;
F_45 ( 100 ) ;
} while ( -- V_115 );
if ( ! V_115 ) {
F_34 ( & V_10 -> V_2 -> V_3 -> V_53 ,
L_12 ) ;
F_37 ( 0 , V_10 -> V_11 -> V_97 + V_125 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_80 == 0x10 )
V_2 -> V_7 |= V_128 ;
return 0 ;
}
static int F_48 ( struct V_39 * V_11 )
{
struct V_9 * V_10 ;
struct V_90 * V_3 ;
int V_65 ;
V_10 = F_49 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_112 & 0xFFFF00 ) == ( V_129 << 8 ) ) &&
( ( V_3 -> V_112 & 0x0000FF ) != V_114 ) &&
( V_11 -> V_130 & V_131 ) ) {
F_18 ( & V_3 -> V_53 , L_13
L_14 ) ;
}
V_65 = F_50 ( V_3 , F_51 ( 32 ) ) ;
if ( V_65 )
return V_65 ;
F_52 ( V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_39 * V_11 , int V_132 )
{
T_2 V_133 ;
V_133 = F_54 ( V_11 , V_134 ) ;
switch ( V_132 ) {
case V_135 :
V_133 |= V_136 ;
V_133 &= ~ V_137 ;
break;
case V_138 :
V_133 |= V_137 ;
V_133 &= ~ V_136 ;
break;
default:
V_133 &= ~ ( V_136 | V_137 ) ;
break;
}
F_55 ( V_11 , V_133 , V_134 ) ;
return 0 ;
}
static void F_56 ( struct V_39 * V_11 )
{
struct V_9 * V_10 = F_49 ( V_11 ) ;
int V_60 = V_10 -> V_60 ;
if ( ! F_57 ( V_60 ) )
return;
F_58 ( V_60 , 0 ) ;
F_45 ( 10 ) ;
F_58 ( V_60 , 1 ) ;
F_59 ( 300 , 1000 ) ;
}
static int F_60 ( struct V_57 * V_53 )
{
struct V_90 * V_3 = F_61 ( V_53 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_139 ;
T_4 V_140 = 0 ;
int V_29 , V_65 ;
V_2 = F_62 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ ) {
V_10 = V_2 -> V_111 [ V_29 ] ;
if ( ! V_10 )
continue;
V_65 = F_63 ( V_10 -> V_11 ) ;
if ( V_65 ) {
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_64 ( V_2 -> V_111 [ V_29 ] -> V_11 ) ;
return V_65 ;
}
V_139 = V_10 -> V_11 -> V_20 -> V_140 ;
if ( V_139 & V_141 )
F_65 ( V_10 -> V_11 ) ;
V_140 |= V_139 ;
}
if ( V_2 -> V_142 && V_2 -> V_142 -> V_143 ) {
V_65 = V_2 -> V_142 -> V_143 ( V_2 ) ;
if ( V_65 ) {
for ( V_29 = V_2 -> V_22 - 1 ; V_29 >= 0 ; V_29 -- )
F_64 ( V_2 -> V_111 [ V_29 ] -> V_11 ) ;
return V_65 ;
}
}
F_66 ( V_3 ) ;
if ( V_140 & V_144 ) {
if ( V_140 & V_141 ) {
F_67 ( V_3 , true ) ;
F_68 ( V_3 , V_145 , 1 ) ;
}
F_69 ( V_3 , V_145 ) ;
} else {
F_68 ( V_3 , V_145 , 0 ) ;
F_70 ( V_3 ) ;
F_69 ( V_3 , V_145 ) ;
}
return 0 ;
}
static int F_71 ( struct V_57 * V_53 )
{
struct V_90 * V_3 = F_61 ( V_53 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_29 , V_65 ;
V_2 = F_62 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_69 ( V_3 , V_146 ) ;
F_72 ( V_3 ) ;
V_65 = F_73 ( V_3 ) ;
if ( V_65 )
return V_65 ;
if ( V_2 -> V_142 && V_2 -> V_142 -> V_147 ) {
V_65 = V_2 -> V_142 -> V_147 ( V_2 ) ;
if ( V_65 )
return V_65 ;
}
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ ) {
V_10 = V_2 -> V_111 [ V_29 ] ;
if ( ! V_10 )
continue;
V_65 = F_64 ( V_10 -> V_11 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_74 ( struct V_57 * V_53 )
{
struct V_90 * V_3 = F_75 ( V_53 , struct V_90 , V_53 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_29 , V_65 ;
V_2 = F_62 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ ) {
V_10 = V_2 -> V_111 [ V_29 ] ;
if ( ! V_10 )
continue;
V_65 = F_76 ( V_10 -> V_11 ) ;
if ( V_65 ) {
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_77 ( V_2 -> V_111 [ V_29 ] -> V_11 ) ;
return V_65 ;
}
}
if ( V_2 -> V_142 && V_2 -> V_142 -> V_143 ) {
V_65 = V_2 -> V_142 -> V_143 ( V_2 ) ;
if ( V_65 ) {
for ( V_29 = V_2 -> V_22 - 1 ; V_29 >= 0 ; V_29 -- )
F_77 ( V_2 -> V_111 [ V_29 ] -> V_11 ) ;
return V_65 ;
}
}
return 0 ;
}
static int F_78 ( struct V_57 * V_53 )
{
struct V_90 * V_3 = F_75 ( V_53 , struct V_90 , V_53 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_29 , V_65 ;
V_2 = F_62 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_142 && V_2 -> V_142 -> V_147 ) {
V_65 = V_2 -> V_142 -> V_147 ( V_2 ) ;
if ( V_65 )
return V_65 ;
}
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ ) {
V_10 = V_2 -> V_111 [ V_29 ] ;
if ( ! V_10 )
continue;
V_65 = F_77 ( V_10 -> V_11 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_79 ( struct V_57 * V_53 )
{
return 0 ;
}
static struct V_9 * T_5 F_80 (
struct V_90 * V_3 , struct V_1 * V_2 , int V_148 )
{
struct V_9 * V_10 ;
struct V_39 * V_11 ;
int V_65 ;
if ( ! ( F_81 ( V_3 , V_148 ) & V_149 ) ) {
F_34 ( & V_3 -> V_53 , L_15 , V_148 ) ;
return F_82 ( - V_95 ) ;
}
if ( F_83 ( V_3 , V_148 ) != 0x100 ) {
F_34 ( & V_3 -> V_53 , L_16
L_17 ) ;
}
if ( ( V_3 -> V_112 & 0x0000FF ) == V_113 ) {
F_34 ( & V_3 -> V_53 , L_18 ) ;
return F_82 ( - V_95 ) ;
}
if ( ( V_3 -> V_112 & 0x0000FF ) > V_113 ) {
F_34 ( & V_3 -> V_53 , L_19 ) ;
return F_82 ( - V_95 ) ;
}
V_11 = F_84 ( & V_3 -> V_53 , sizeof( struct V_9 ) ) ;
if ( F_85 ( V_11 ) ) {
F_34 ( & V_3 -> V_53 , L_20 ) ;
return F_86 ( V_11 ) ;
}
V_10 = F_49 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_150 = V_148 ;
V_10 -> V_60 = - V_45 ;
V_11 -> V_151 = L_21 ;
V_11 -> V_152 = & V_153 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_37 = V_3 -> V_37 ;
V_65 = F_87 ( V_3 , V_148 , F_88 ( V_11 -> V_20 ) ) ;
if ( V_65 ) {
F_34 ( & V_3 -> V_53 , L_22 ) ;
goto free;
}
V_11 -> V_97 = F_89 ( V_3 , V_148 ) ;
if ( ! V_11 -> V_97 ) {
F_34 ( & V_3 -> V_53 , L_23 ) ;
V_65 = - V_154 ;
goto V_155;
}
if ( V_2 -> V_142 && V_2 -> V_142 -> V_156 ) {
V_65 = V_2 -> V_142 -> V_156 ( V_10 ) ;
if ( V_65 )
goto V_157;
}
V_11 -> V_20 -> V_158 = V_144 | V_141 ;
V_65 = F_90 ( V_11 ) ;
if ( V_65 )
goto remove;
return V_10 ;
remove:
if ( V_2 -> V_142 && V_2 -> V_142 -> V_159 )
V_2 -> V_142 -> V_159 ( V_10 , 0 ) ;
V_157:
F_91 ( V_11 -> V_97 ) ;
V_155:
F_92 ( V_3 , V_148 ) ;
free:
F_93 ( V_11 ) ;
return F_82 ( V_65 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
int V_54 ;
T_6 V_66 ;
V_54 = 0 ;
V_66 = F_39 ( V_10 -> V_11 -> V_97 + V_160 ) ;
if ( V_66 == ( T_6 ) - 1 )
V_54 = 1 ;
F_95 ( V_10 -> V_11 , V_54 ) ;
if ( V_10 -> V_2 -> V_142 && V_10 -> V_2 -> V_142 -> V_159 )
V_10 -> V_2 -> V_142 -> V_159 ( V_10 , V_54 ) ;
F_92 ( V_10 -> V_2 -> V_3 , V_10 -> V_150 ) ;
F_93 ( V_10 -> V_11 ) ;
}
static void T_5 F_96 ( struct V_57 * V_53 )
{
F_97 ( V_53 ) ;
F_98 ( V_53 ) ;
F_99 ( V_53 , 50 ) ;
F_100 ( V_53 ) ;
F_101 ( V_53 , 1 ) ;
}
static void T_7 F_102 ( struct V_57 * V_53 )
{
F_103 ( V_53 ) ;
F_104 ( V_53 ) ;
}
static int T_5 F_105 ( struct V_90 * V_3 ,
const struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_111 , V_163 ;
int V_65 , V_29 ;
F_106 ( V_3 == NULL ) ;
F_106 ( V_162 == NULL ) ;
F_33 ( & V_3 -> V_53 , L_24 ,
( int ) V_3 -> V_164 , ( int ) V_3 -> V_57 , ( int ) V_3 -> V_80 ) ;
V_65 = F_26 ( V_3 , V_165 , & V_111 ) ;
if ( V_65 )
return V_65 ;
V_111 = F_107 ( V_111 ) + 1 ;
F_108 ( & V_3 -> V_53 , L_25 , V_111 ) ;
if ( V_111 == 0 )
return - V_95 ;
F_106 ( V_111 > V_166 ) ;
V_65 = F_26 ( V_3 , V_165 , & V_163 ) ;
if ( V_65 )
return V_65 ;
V_163 &= V_167 ;
if ( V_163 > 5 ) {
F_34 ( & V_3 -> V_53 , L_26 ) ;
return - V_95 ;
}
V_65 = F_73 ( V_3 ) ;
if ( V_65 )
return V_65 ;
V_2 = F_109 ( sizeof( struct V_1 ) , V_168 ) ;
if ( ! V_2 ) {
V_65 = - V_154 ;
goto V_41;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_142 = ( const struct V_169 * ) V_162 -> V_170 ;
if ( V_2 -> V_142 ) {
V_2 -> V_7 = V_2 -> V_142 -> V_7 ;
V_2 -> V_171 = V_2 -> V_142 -> V_171 ;
}
V_2 -> V_22 = V_111 ;
F_110 ( V_3 , V_2 ) ;
if ( V_2 -> V_142 && V_2 -> V_142 -> V_172 ) {
V_65 = V_2 -> V_142 -> V_172 ( V_2 ) ;
if ( V_65 )
goto free;
}
V_111 = V_2 -> V_22 ;
for ( V_29 = 0 ; V_29 < V_111 ; V_29 ++ ) {
V_10 = F_80 ( V_3 , V_2 , V_163 + V_29 ) ;
if ( F_85 ( V_10 ) ) {
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_94 ( V_2 -> V_111 [ V_29 ] ) ;
V_65 = F_111 ( V_10 ) ;
goto free;
}
V_2 -> V_111 [ V_29 ] = V_10 ;
}
if ( V_2 -> V_171 )
F_96 ( & V_3 -> V_53 ) ;
return 0 ;
free:
F_110 ( V_3 , NULL ) ;
F_112 ( V_2 ) ;
V_41:
F_70 ( V_3 ) ;
return V_65 ;
}
static void T_7 F_113 ( struct V_90 * V_3 )
{
int V_29 ;
struct V_1 * V_2 ;
V_2 = F_62 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_171 )
F_102 ( & V_3 -> V_53 ) ;
for ( V_29 = 0 ; V_29 < V_2 -> V_22 ; V_29 ++ )
F_94 ( V_2 -> V_111 [ V_29 ] ) ;
F_110 ( V_3 , NULL ) ;
F_112 ( V_2 ) ;
}
F_70 ( V_3 ) ;
}
static int T_8 F_114 ( void )
{
return F_115 ( & V_173 ) ;
}
static void T_9 F_116 ( void )
{
F_117 ( & V_173 ) ;
}
