static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 * V_5 )
{
struct V_6 * V_7 ;
if ( V_2 -> V_8 -> V_9 )
return V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 , V_5 ) ;
V_7 = F_2 ( V_2 ) ;
return F_3 ( V_7 -> V_10 + V_3 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
if ( V_2 -> V_8 -> V_11 )
return V_2 -> V_8 -> V_11 ( V_2 , V_3 , V_4 , V_5 ) ;
V_7 = F_2 ( V_2 ) ;
return F_5 ( V_7 -> V_10 + V_3 , V_4 , V_5 ) ;
}
T_2 F_6 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_12 , V_13 , V_14 ;
T_2 V_15 = V_16 ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
F_1 ( V_2 , V_18 + V_12 * 12 , 4 ,
& V_5 ) ;
if ( ! V_5 )
continue;
V_15 = V_19 ;
V_13 = 0 ;
while ( ( V_13 = F_7 ( ( unsigned long * ) & V_5 , 32 ,
V_13 ) ) != 32 ) {
V_14 = F_8 ( V_2 -> V_20 , V_12 * 32 + V_13 ) ;
F_9 ( V_14 ) ;
F_4 ( V_2 , V_18 + V_12 * 12 ,
4 , 1 << V_13 ) ;
V_13 ++ ;
}
}
return V_15 ;
}
void F_10 ( struct V_1 * V_2 )
{
T_3 V_21 ;
V_2 -> V_22 = F_11 ( V_23 , 0 ) ;
V_21 = F_12 ( ( void * ) V_2 -> V_22 ) ;
F_4 ( V_2 , V_24 , 4 ,
( T_1 ) ( V_21 & 0xffffffff ) ) ;
F_4 ( V_2 , V_25 , 4 ,
( T_1 ) ( V_21 >> 32 & 0xffffffff ) ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_14 )
{
unsigned int V_26 , V_27 , V_5 ;
V_26 = ( V_14 / 32 ) * 12 ;
V_27 = V_14 % 32 ;
F_1 ( V_2 , V_28 + V_26 , 4 , & V_5 ) ;
V_5 &= ~ ( 1 << V_27 ) ;
F_4 ( V_2 , V_28 + V_26 , 4 , V_5 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned int V_30 , unsigned int V_13 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ ) {
F_15 ( V_29 , V_12 , NULL ) ;
if ( V_2 -> V_8 -> V_31 )
V_2 -> V_8 -> V_31 ( V_2 , V_13 + V_12 ) ;
else
F_13 ( V_2 , V_13 + V_12 ) ;
}
F_16 ( V_2 -> V_32 , V_13 , F_17 ( V_30 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_14 )
{
unsigned int V_26 , V_27 , V_5 ;
V_26 = ( V_14 / 32 ) * 12 ;
V_27 = V_14 % 32 ;
F_1 ( V_2 , V_28 + V_26 , 4 , & V_5 ) ;
V_5 |= 1 << V_27 ;
F_4 ( V_2 , V_28 + V_26 , 4 , V_5 ) ;
}
static int F_19 ( int V_33 , struct V_34 * V_35 , int * V_13 )
{
int V_14 , V_36 , V_12 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_20 ( V_35 ) ;
V_36 = F_21 ( V_2 -> V_32 , V_37 ,
F_17 ( V_33 ) ) ;
if ( V_36 < 0 )
goto V_38;
V_14 = F_8 ( V_2 -> V_20 , V_36 ) ;
if ( ! V_14 )
goto V_38;
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
if ( F_15 ( V_14 , V_12 , V_35 ) != 0 ) {
F_14 ( V_2 , V_14 , V_12 , V_36 ) ;
goto V_38;
}
if ( V_2 -> V_8 -> V_39 )
V_2 -> V_8 -> V_39 ( V_2 , V_36 + V_12 ) ;
else
F_18 ( V_2 , V_36 + V_12 ) ;
}
* V_13 = V_36 ;
V_35 -> V_40 = V_33 ;
V_35 -> V_41 . V_42 = F_17 ( V_33 ) ;
return V_14 ;
V_38:
* V_13 = V_36 ;
return - V_43 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_14 , T_1 V_13 )
{
struct V_44 V_45 ;
T_3 V_21 ;
if ( V_2 -> V_8 -> V_46 )
V_21 = V_2 -> V_8 -> V_46 ( V_2 ) ;
else
V_21 = F_12 ( ( void * ) V_2 -> V_22 ) ;
V_45 . V_47 = ( T_1 ) ( V_21 & 0xffffffff ) ;
V_45 . V_48 = ( T_1 ) ( V_21 >> 32 & 0xffffffff ) ;
if ( V_2 -> V_8 -> V_49 )
V_45 . V_50 = V_2 -> V_8 -> V_49 ( V_2 , V_13 ) ;
else
V_45 . V_50 = V_13 ;
F_23 ( V_14 , & V_45 ) ;
}
static int F_24 ( struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_34 * V_35 )
{
int V_14 , V_13 ;
struct V_1 * V_2 = V_54 -> V_55 -> V_56 ;
if ( V_35 -> V_41 . V_57 )
return - V_58 ;
V_14 = F_19 ( 1 , V_35 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
F_22 ( V_2 , V_14 , V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_52 , struct V_53 * V_54 ,
int V_30 , int type )
{
#ifdef F_26
int V_14 , V_13 ;
struct V_34 * V_35 ;
struct V_1 * V_2 = V_54 -> V_55 -> V_56 ;
if ( type == V_59 )
return - V_58 ;
F_27 ( ! F_28 ( & V_54 -> V_60 . V_61 ) ) ;
V_35 = F_29 ( V_54 -> V_60 . V_61 . V_62 , struct V_34 , V_63 ) ;
V_14 = F_19 ( V_30 , V_35 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
F_22 ( V_2 , V_14 , V_13 ) ;
return 0 ;
#else
return - V_58 ;
#endif
}
static void F_30 ( struct V_51 * V_52 , unsigned int V_14 )
{
struct V_64 * V_50 = F_31 ( V_14 ) ;
struct V_34 * V_65 = F_32 ( V_50 ) ;
struct V_1 * V_2 = (struct V_1 * ) F_20 ( V_65 ) ;
F_14 ( V_2 , V_14 , 1 , V_50 -> V_66 ) ;
}
static int F_33 ( struct V_20 * V_67 , unsigned int V_14 ,
T_4 V_66 )
{
F_34 ( V_14 , & V_68 , V_69 ) ;
F_35 ( V_14 , V_67 -> V_70 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_71 * V_60 = V_7 -> V_60 ;
struct V_72 * V_73 = V_60 -> V_74 ;
struct V_75 * V_54 = F_37 ( V_60 ) ;
struct V_76 * V_55 , * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_12 , V_15 ;
struct V_82 * V_83 , * V_84 ;
V_81 = F_38 ( V_54 , V_85 , L_1 ) ;
if ( V_81 ) {
V_2 -> V_86 = F_39 ( V_81 ) / 2 ;
V_2 -> V_87 = F_39 ( V_81 ) / 2 ;
V_2 -> V_88 = V_81 -> V_89 ;
V_2 -> V_90 = V_81 -> V_89 + V_2 -> V_86 ;
} else if ( ! V_2 -> V_91 ) {
F_40 ( V_60 , L_2 ) ;
}
V_79 = F_41 ( 0 ) ;
if ( ! V_79 )
return - V_92 ;
V_15 = F_42 ( V_73 , 0 , 0xff ,
& V_79 -> V_93 , & V_2 -> V_94 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_43 ( V_60 , & V_79 -> V_93 ) ;
if ( V_15 )
goto error;
F_44 (win, tmp, &bridge->windows) {
switch ( F_45 ( V_83 -> V_26 ) ) {
case V_95 :
V_15 = F_46 ( V_83 -> V_26 , V_2 -> V_94 ) ;
if ( V_15 ) {
F_47 ( V_60 , L_3 ,
V_15 , V_83 -> V_26 ) ;
F_48 ( V_83 ) ;
} else {
V_2 -> V_96 = V_83 -> V_26 ;
V_2 -> V_96 -> V_97 = L_4 ;
V_2 -> V_98 = F_39 ( V_2 -> V_96 ) ;
V_2 -> V_99 = V_2 -> V_96 -> V_89 - V_83 -> V_100 ;
}
break;
case V_85 :
V_2 -> V_101 = V_83 -> V_26 ;
V_2 -> V_101 -> V_97 = L_5 ;
V_2 -> V_102 = F_39 ( V_2 -> V_101 ) ;
V_2 -> V_103 = V_2 -> V_101 -> V_89 - V_83 -> V_100 ;
break;
case 0 :
V_2 -> V_104 = V_83 -> V_26 ;
V_2 -> V_86 = F_39 ( V_2 -> V_104 ) / 2 ;
V_2 -> V_87 = F_39 ( V_2 -> V_104 ) / 2 ;
V_2 -> V_88 = V_2 -> V_104 -> V_89 ;
V_2 -> V_90 = V_2 -> V_104 -> V_89 + V_2 -> V_86 ;
break;
case V_105 :
V_2 -> V_106 = V_83 -> V_26 ;
break;
}
}
if ( ! V_7 -> V_10 ) {
V_7 -> V_10 = F_49 ( V_60 ,
V_2 -> V_104 -> V_89 ,
F_39 ( V_2 -> V_104 ) ) ;
if ( ! V_7 -> V_10 ) {
F_40 ( V_60 , L_6 ) ;
V_15 = - V_92 ;
goto error;
}
}
V_2 -> V_107 = V_2 -> V_101 -> V_89 ;
if ( ! V_2 -> V_91 ) {
V_2 -> V_91 = F_49 ( V_60 ,
V_2 -> V_88 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_91 ) {
F_40 ( V_60 , L_7 ) ;
V_15 = - V_92 ;
goto error;
}
}
if ( ! V_2 -> V_108 ) {
V_2 -> V_108 = F_49 ( V_60 ,
V_2 -> V_90 ,
V_2 -> V_87 ) ;
if ( ! V_2 -> V_108 ) {
F_40 ( V_60 , L_6 ) ;
V_15 = - V_92 ;
goto error;
}
}
V_15 = F_50 ( V_73 , L_8 , & V_7 -> V_109 ) ;
if ( V_15 )
V_7 -> V_109 = 2 ;
if ( F_51 ( F_26 ) ) {
if ( ! V_2 -> V_8 -> V_110 ) {
V_2 -> V_20 = F_52 ( V_60 -> V_74 ,
V_37 , & V_111 ,
& V_112 ) ;
if ( ! V_2 -> V_20 ) {
F_40 ( V_60 , L_9 ) ;
V_15 = - V_113 ;
goto error;
}
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ )
F_53 ( V_2 -> V_20 , V_12 ) ;
} else {
V_15 = V_2 -> V_8 -> V_110 ( V_2 , & V_112 ) ;
if ( V_15 < 0 )
goto error;
}
}
if ( V_2 -> V_8 -> V_114 ) {
V_15 = V_2 -> V_8 -> V_114 ( V_2 ) ;
if ( V_15 )
goto error;
}
V_2 -> V_115 = V_2 -> V_106 -> V_89 ;
V_79 -> V_60 . V_116 = V_60 ;
V_79 -> V_56 = V_2 ;
V_79 -> V_117 = V_2 -> V_115 ;
V_79 -> V_8 = & V_118 ;
V_79 -> V_119 = V_120 ;
V_79 -> V_121 = V_122 ;
if ( F_51 ( F_26 ) ) {
V_79 -> V_65 = & V_112 ;
V_112 . V_60 = V_60 ;
}
V_15 = F_54 ( V_79 ) ;
if ( V_15 )
goto error;
V_55 = V_79 -> V_55 ;
if ( V_2 -> V_8 -> V_123 )
V_2 -> V_8 -> V_123 ( V_2 ) ;
F_55 ( V_55 ) ;
F_56 ( V_55 ) ;
F_57 (child, &bus->children, node)
F_58 ( V_77 ) ;
F_59 ( V_55 ) ;
return 0 ;
error:
F_60 ( V_79 ) ;
return V_15 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_76 * V_55 ,
T_1 V_124 , int V_3 , int V_4 , T_1 * V_5 )
{
int V_15 , type ;
T_1 V_125 , V_126 ;
T_3 V_127 ;
void T_5 * V_128 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_8 -> V_129 )
return V_2 -> V_8 -> V_129 ( V_2 , V_55 , V_124 , V_3 , V_4 , V_5 ) ;
V_125 = F_62 ( V_55 -> V_130 ) | F_63 ( F_64 ( V_124 ) ) |
F_65 ( F_66 ( V_124 ) ) ;
if ( V_55 -> V_116 -> V_130 == V_2 -> V_115 ) {
type = V_131 ;
V_127 = V_2 -> V_88 ;
V_126 = V_2 -> V_86 ;
V_128 = V_2 -> V_91 ;
} else {
type = V_132 ;
V_127 = V_2 -> V_90 ;
V_126 = V_2 -> V_87 ;
V_128 = V_2 -> V_108 ;
}
F_67 ( V_7 , V_133 ,
type , V_127 ,
V_125 , V_126 ) ;
V_15 = F_3 ( V_128 + V_3 , V_4 , V_5 ) ;
if ( V_7 -> V_109 <= 2 )
F_67 ( V_7 , V_133 ,
V_134 , V_2 -> V_94 ,
V_2 -> V_99 , V_2 -> V_98 ) ;
return V_15 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_76 * V_55 ,
T_1 V_124 , int V_3 , int V_4 , T_1 V_5 )
{
int V_15 , type ;
T_1 V_125 , V_126 ;
T_3 V_127 ;
void T_5 * V_128 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_8 -> V_135 )
return V_2 -> V_8 -> V_135 ( V_2 , V_55 , V_124 , V_3 , V_4 , V_5 ) ;
V_125 = F_62 ( V_55 -> V_130 ) | F_63 ( F_64 ( V_124 ) ) |
F_65 ( F_66 ( V_124 ) ) ;
if ( V_55 -> V_116 -> V_130 == V_2 -> V_115 ) {
type = V_131 ;
V_127 = V_2 -> V_88 ;
V_126 = V_2 -> V_86 ;
V_128 = V_2 -> V_91 ;
} else {
type = V_132 ;
V_127 = V_2 -> V_90 ;
V_126 = V_2 -> V_87 ;
V_128 = V_2 -> V_108 ;
}
F_67 ( V_7 , V_133 ,
type , V_127 ,
V_125 , V_126 ) ;
V_15 = F_5 ( V_128 + V_3 , V_4 , V_5 ) ;
if ( V_7 -> V_109 <= 2 )
F_67 ( V_7 , V_133 ,
V_134 , V_2 -> V_94 ,
V_2 -> V_99 , V_2 -> V_98 ) ;
return V_15 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_76 * V_55 ,
int V_60 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_55 -> V_130 != V_2 -> V_115 ) {
if ( ! F_70 ( V_7 ) )
return 0 ;
}
if ( V_55 -> V_130 == V_2 -> V_115 && V_60 > 0 )
return 0 ;
return 1 ;
}
static int F_71 ( struct V_76 * V_55 , T_1 V_124 , int V_3 ,
int V_4 , T_1 * V_5 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
if ( ! F_69 ( V_2 , V_55 , F_64 ( V_124 ) ) ) {
* V_5 = 0xffffffff ;
return V_136 ;
}
if ( V_55 -> V_130 == V_2 -> V_115 )
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
return F_61 ( V_2 , V_55 , V_124 , V_3 , V_4 , V_5 ) ;
}
static int F_72 ( struct V_76 * V_55 , T_1 V_124 ,
int V_3 , int V_4 , T_1 V_5 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
if ( ! F_69 ( V_2 , V_55 , F_64 ( V_124 ) ) )
return V_136 ;
if ( V_55 -> V_130 == V_2 -> V_115 )
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
return F_68 ( V_2 , V_55 , V_124 , V_3 , V_4 , V_5 ) ;
}
static T_6 F_73 ( struct V_6 * V_7 )
{
T_1 V_5 ;
V_5 = F_74 ( V_7 , V_137 ) ;
if ( V_5 == 0xffffffff )
return 1 ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_76 ( V_7 ) ;
F_77 ( V_7 , V_138 , 0x00000004 ) ;
F_77 ( V_7 , V_139 , 0x00000000 ) ;
F_78 ( V_7 ) ;
V_5 = F_74 ( V_7 , V_140 ) ;
V_5 &= 0xffff00ff ;
V_5 |= 0x00000100 ;
F_77 ( V_7 , V_140 , V_5 ) ;
F_79 ( V_7 ) ;
V_5 = F_74 ( V_7 , V_141 ) ;
V_5 &= 0xff000000 ;
V_5 |= 0x00010100 ;
F_77 ( V_7 , V_141 , V_5 ) ;
V_5 = F_74 ( V_7 , V_142 ) ;
V_5 &= 0xffff0000 ;
V_5 |= V_143 | V_144 |
V_145 | V_146 ;
F_77 ( V_7 , V_142 , V_5 ) ;
if ( ! V_2 -> V_8 -> V_129 ) {
V_7 -> V_147 = F_73 ( V_7 ) ;
F_80 ( V_7 -> V_60 , L_10 ,
V_7 -> V_147 ? L_11 : L_12 ) ;
F_67 ( V_7 , V_148 ,
V_149 , V_2 -> V_107 ,
V_2 -> V_103 , V_2 -> V_102 ) ;
if ( V_7 -> V_109 > 2 )
F_67 ( V_7 , V_150 ,
V_134 , V_2 -> V_94 ,
V_2 -> V_99 , V_2 -> V_98 ) ;
}
F_4 ( V_2 , V_138 , 4 , 0 ) ;
F_78 ( V_7 ) ;
F_4 ( V_2 , V_151 , 2 , V_152 ) ;
F_79 ( V_7 ) ;
F_1 ( V_2 , V_153 , 4 , & V_5 ) ;
V_5 |= V_154 ;
F_4 ( V_2 , V_153 , 4 , V_5 ) ;
}
