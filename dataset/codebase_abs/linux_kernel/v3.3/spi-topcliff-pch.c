static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , ( V_6 -> V_7 + V_3 ) ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 -> V_7 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_10 = F_4 ( V_2 , V_3 ) ;
V_10 = ( V_10 & ~ V_9 ) | V_8 ;
F_1 ( V_2 , V_3 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_11 , V_12 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_11 , V_13 , 0 ) ;
F_6 ( V_2 , V_11 , 0 , V_13 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_14 ,
void T_2 * V_7 )
{
T_1 V_15 , V_16 , V_17 , V_18 ;
T_3 * V_19 , * V_20 ;
int V_21 ;
T_1 V_22 ;
void T_2 * V_23 ;
void T_2 * V_24 ;
void T_2 * V_25 ;
V_23 = V_7 + V_26 ;
F_3 ( V_14 , V_23 ) ;
if ( V_6 -> V_27 ) {
V_17 = V_6 -> V_17 ;
V_16 = V_6 -> V_16 ;
V_18 = V_6 -> V_18 ;
V_19 = V_6 -> V_28 ;
V_20 = V_6 -> V_20 ;
V_24 = V_7 + V_29 ;
V_25 = V_7 + V_30 ;
V_15 = F_10 ( V_14 ) ;
for ( V_21 = 0 ; ( V_21 < V_15 ) ; V_21 ++ ) {
V_19 [ V_17 ++ ] = F_5 ( V_24 ) ;
if ( V_16 < V_18 )
F_3 ( V_20 [ V_16 ++ ] , V_25 ) ;
}
if ( ( V_18 - V_17 ) <= V_31 ) {
V_22 = F_5 ( V_7 + V_11 ) ;
V_22 &= ~ V_32 ;
V_22 &= ~ V_33 ;
V_22 |= ( V_34 << V_35 ) ;
F_3 ( V_22 , ( V_7 + V_11 ) ) ;
}
V_6 -> V_16 = V_16 ;
V_6 -> V_17 = V_17 ;
}
if ( V_14 & V_36 ) {
if ( ( V_16 == V_18 ) && ( V_17 == V_16 ) ) {
F_6 ( V_6 -> V_2 , V_11 , 0 , V_37 ) ;
V_6 -> V_38 = true ;
V_6 -> V_27 = false ;
F_11 ( & V_6 -> V_39 ) ;
} else {
F_12 ( & V_6 -> V_2 -> V_40 ,
L_1 , V_41 ) ;
}
}
}
static T_4 F_13 ( int V_42 , void * V_43 )
{
T_1 V_14 ;
void T_2 * V_23 ;
void T_2 * V_7 ;
T_4 V_44 = V_45 ;
struct V_5 * V_6 = V_43 ;
struct V_46 * V_47 = V_6 -> V_47 ;
if ( V_47 -> V_48 ) {
F_14 ( & V_47 -> V_49 -> V_40 ,
L_2 , V_41 ) ;
return V_45 ;
}
V_7 = V_6 -> V_7 ;
V_23 = V_7 + V_26 ;
V_14 = F_5 ( V_23 ) ;
if ( V_14 & V_50 ) {
F_12 ( & V_47 -> V_49 -> V_40 , L_3 , V_41 ) ;
if ( V_6 -> V_51 -> V_52 != 0 ) {
V_6 -> V_38 = true ;
V_6 -> V_51 -> V_53 = - V_54 ;
V_6 -> V_51 -> V_52 ( V_6 -> V_51 -> V_55 ) ;
V_6 -> V_56 = false ;
V_6 -> V_51 = NULL ;
V_6 -> V_57 = NULL ;
}
}
if ( V_6 -> V_58 )
return V_45 ;
if ( V_14 & ( V_36 | V_59 ) ) {
F_9 ( V_6 , V_14 , V_7 ) ;
V_44 = V_60 ;
}
F_14 ( & V_47 -> V_49 -> V_40 , L_4 ,
V_41 , V_44 ) ;
return V_44 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_61 )
{
T_1 V_62 = V_63 / ( V_61 * 2 ) ;
if ( V_62 > V_64 )
V_62 = V_64 ;
F_6 ( V_2 , V_65 , V_62 , V_66 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_5 V_67 )
{
if ( V_67 == 8 )
F_6 ( V_2 , V_65 , 0 , V_68 ) ;
else
F_6 ( V_2 , V_65 , V_68 , 0 ) ;
}
static void F_17 ( struct V_69 * V_70 )
{
T_1 V_71 = 0 ;
F_14 ( & V_70 -> V_40 , L_5 ,
V_41 , F_4 ( V_70 -> V_2 , V_65 ) ,
V_70 -> V_72 ) ;
F_15 ( V_70 -> V_2 , V_70 -> V_72 ) ;
F_16 ( V_70 -> V_2 , V_70 -> V_67 ) ;
if ( ! ( V_70 -> V_73 & V_74 ) )
V_71 |= V_75 ;
if ( V_70 -> V_73 & V_76 )
V_71 |= V_77 ;
if ( V_70 -> V_73 & V_78 )
V_71 |= V_79 ;
F_6 ( V_70 -> V_2 , V_11 , V_71 ,
( V_75 | V_77 | V_79 ) ) ;
F_8 ( V_70 -> V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_80 , 0x1 ) ;
F_1 ( V_2 , V_80 , 0x0 ) ;
}
static int F_19 ( struct V_69 * V_81 )
{
if ( V_81 -> V_67 == 0 ) {
V_81 -> V_67 = 8 ;
F_14 ( & V_81 -> V_40 , L_6 , V_41 ) ;
}
if ( ( V_81 -> V_67 != 8 ) && ( V_81 -> V_67 != 16 ) ) {
F_12 ( & V_81 -> V_40 , L_7 , V_41 ) ;
return - V_82 ;
}
if ( ( V_81 -> V_72 ) > V_83 )
V_81 -> V_72 = V_83 ;
F_14 ( & V_81 -> V_40 , L_8 , V_41 ,
( V_81 -> V_73 ) & ( V_76 | V_78 ) ) ;
return 0 ;
}
static int F_20 ( struct V_69 * V_81 , struct V_84 * V_85 )
{
struct V_86 * V_87 ;
struct V_5 * V_6 = F_2 ( V_81 -> V_2 ) ;
int V_88 ;
unsigned long V_71 ;
if ( F_21 ( F_22 ( & V_85 -> V_89 ) == 1 ) ) {
F_12 ( & V_81 -> V_40 , L_9 , V_41 ) ;
V_88 = - V_82 ;
goto V_90;
}
if ( F_21 ( V_81 -> V_72 == 0 ) ) {
F_12 ( & V_81 -> V_40 , L_10 ,
V_41 , V_81 -> V_72 ) ;
V_88 = - V_82 ;
goto V_90;
}
F_14 ( & V_81 -> V_40 , L_11
L_12 , V_41 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_24 (transfer, &pmsg->transfers, transfer_list) {
if ( ! V_87 -> V_92 && ! V_87 -> V_93 ) {
F_12 ( & V_81 -> V_40 ,
L_13 , V_41 ) ;
V_88 = - V_82 ;
goto V_94;
}
if ( ! V_87 -> V_95 ) {
F_12 ( & V_81 -> V_40 , L_14 ,
V_41 ) ;
V_88 = - V_82 ;
goto V_94;
}
F_14 ( & V_81 -> V_40 , L_15
L_16 , V_41 ) ;
if ( V_87 -> V_61 > V_83 )
V_87 -> V_61 = V_83 ;
if ( V_87 -> V_67 ) {
if ( ( V_87 -> V_67 != 8 )
&& ( V_87 -> V_67 != 16 ) ) {
V_88 = - V_82 ;
F_12 ( & V_81 -> V_40 ,
L_7 , V_41 ) ;
goto V_94;
}
}
}
F_25 ( & V_6 -> V_91 , V_71 ) ;
if ( V_6 -> V_53 == V_96 ) {
F_12 ( & V_81 -> V_40 , L_17 , V_41 ) ;
V_88 = - V_97 ;
goto V_90;
}
if ( V_6 -> V_47 -> V_48 ) {
F_12 ( & V_81 -> V_40 , L_18 , V_41 ) ;
V_88 = - V_82 ;
goto V_90;
}
V_85 -> V_98 = 0 ;
F_14 ( & V_81 -> V_40 , L_19 , V_41 , V_85 -> V_53 ) ;
V_85 -> V_53 = - V_99 ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_26 ( & V_85 -> V_100 , & V_6 -> V_100 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
F_14 ( & V_81 -> V_40 , L_20 , V_41 ) ;
F_27 ( V_6 -> V_101 , & V_6 -> V_102 ) ;
F_14 ( & V_81 -> V_40 , L_21 , V_41 ) ;
V_88 = 0 ;
V_90:
F_14 ( & V_81 -> V_40 , L_22 , V_41 , V_88 ) ;
return V_88 ;
V_94:
F_14 ( & V_81 -> V_40 , L_22 , V_41 , V_88 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
return V_88 ;
}
static inline void F_28 ( struct V_5 * V_6 ,
struct V_69 * V_81 )
{
if ( V_6 -> V_103 != NULL ) {
if ( V_81 -> V_104 != V_6 -> V_105 ) {
F_14 ( & V_81 -> V_40 , L_23 , V_41 ) ;
V_6 -> V_103 = NULL ;
}
}
V_6 -> V_103 = V_81 ;
V_6 -> V_105 = V_6 -> V_103 -> V_104 ;
F_14 ( & V_81 -> V_40 , L_24 , V_41 ) ;
F_17 ( V_81 ) ;
}
static void F_29 ( struct V_5 * V_6 , int * V_106 )
{
int V_107 ;
T_1 V_108 ;
int V_109 ;
struct V_84 * V_85 ;
const T_5 * V_92 ;
const T_3 * V_110 ;
if ( V_6 -> V_57 -> V_61 ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_25 , V_41 ) ;
F_15 ( V_6 -> V_2 , V_6 -> V_57 -> V_61 ) ;
}
if ( V_6 -> V_57 -> V_67 &&
( V_6 -> V_51 -> V_70 -> V_67 != V_6 -> V_57 -> V_67 ) ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_26 , V_41 ) ;
F_16 ( V_6 -> V_2 ,
V_6 -> V_57 -> V_67 ) ;
* V_106 = V_6 -> V_57 -> V_67 ;
} else {
* V_106 = V_6 -> V_51 -> V_70 -> V_67 ;
}
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = V_6 -> V_57 -> V_95 / ( * V_106 / 8 ) ;
V_107 = V_6 -> V_57 -> V_95 * sizeof( * V_6 -> V_20 ) ;
V_6 -> V_20 = F_30 ( V_107 , V_111 ) ;
if ( V_6 -> V_20 != NULL ) {
V_6 -> V_28 = F_30 ( V_107 , V_111 ) ;
if ( ! V_6 -> V_28 )
F_31 ( V_6 -> V_20 ) ;
}
if ( ! V_6 -> V_28 ) {
F_12 ( & V_6 -> V_2 -> V_40 , L_27 , V_41 ) ;
F_24 (pmsg, data->queue.next, queue) {
V_85 -> V_53 = - V_112 ;
if ( V_85 -> V_52 != 0 )
V_85 -> V_52 ( V_85 -> V_55 ) ;
F_32 ( & V_85 -> V_100 ) ;
}
return;
}
if ( V_6 -> V_57 -> V_92 != NULL ) {
if ( * V_106 == 8 ) {
V_92 = V_6 -> V_57 -> V_92 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
V_6 -> V_20 [ V_109 ] = * V_92 ++ ;
} else {
V_110 = V_6 -> V_57 -> V_92 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
V_6 -> V_20 [ V_109 ] = * V_110 ++ ;
}
}
V_108 = V_6 -> V_18 ;
if ( V_108 > V_31 )
V_108 = V_31 ;
F_14 ( & V_6 -> V_2 -> V_40 , L_28
L_29 , V_41 ) ;
F_1 ( V_6 -> V_2 , V_113 , V_114 ) ;
for ( V_109 = 0 ; V_109 < V_108 ; V_109 ++ )
F_1 ( V_6 -> V_2 , V_30 , V_6 -> V_20 [ V_109 ] ) ;
V_6 -> V_16 = V_109 ;
V_6 -> V_38 = false ;
V_6 -> V_27 = true ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_84 * V_85 ;
F_14 ( & V_6 -> V_2 -> V_40 , L_30 , V_41 ) ;
V_6 -> V_51 -> V_53 = 0 ;
if ( V_6 -> V_51 -> V_52 != 0 ) {
F_14 ( & V_6 -> V_2 -> V_40 ,
L_31 , V_41 ) ;
V_6 -> V_51 -> V_52 ( V_6 -> V_51 -> V_55 ) ;
}
V_6 -> V_56 = false ;
F_14 ( & V_6 -> V_2 -> V_40 ,
L_32 , V_41 ) ;
V_6 -> V_51 = NULL ;
V_6 -> V_57 = NULL ;
if ( ( F_22 ( & V_6 -> V_100 ) == 0 ) &&
( ! V_6 -> V_47 -> V_48 ) &&
( V_6 -> V_53 != V_96 ) ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_33 , V_41 ) ;
F_27 ( V_6 -> V_101 , & V_6 -> V_102 ) ;
} else if ( V_6 -> V_47 -> V_48 ||
V_6 -> V_53 == V_96 ) {
F_14 ( & V_6 -> V_2 -> V_40 ,
L_34 ,
V_41 ) ;
F_24 (pmsg, data->queue.next, queue) {
V_85 -> V_53 = - V_54 ;
if ( V_85 -> V_52 )
V_85 -> V_52 ( V_85 -> V_55 ) ;
F_32 ( & V_85 -> V_100 ) ;
}
}
}
static void F_34 ( struct V_5 * V_6 )
{
if ( ( V_6 -> V_18 ) > V_31 )
F_6 ( V_6 -> V_2 , V_11 ,
V_115 << V_35 |
V_116 | V_32 |
V_117 | V_118 ,
V_33 | V_37 ) ;
else
F_6 ( V_6 -> V_2 , V_11 ,
V_34 << V_35 |
V_116 | V_117 |
V_118 ,
V_33 | V_37 ) ;
F_14 ( & V_6 -> V_2 -> V_40 ,
L_35 , V_41 ) ;
F_35 ( V_6 -> V_39 , V_6 -> V_38 ) ;
F_1 ( V_6 -> V_2 , V_26 ,
F_4 ( V_6 -> V_2 , V_26 ) ) ;
F_6 ( V_6 -> V_2 , V_11 , 0 , V_37 | V_118 ) ;
F_8 ( V_6 -> V_2 ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_106 )
{
int V_109 ;
T_5 * V_93 ;
T_3 * V_119 ;
if ( ! V_6 -> V_57 -> V_93 )
return;
if ( V_106 == 8 ) {
V_93 = V_6 -> V_57 -> V_93 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
* V_93 ++ = V_6 -> V_28 [ V_109 ] & 0xFF ;
} else {
V_119 = V_6 -> V_57 -> V_93 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
* V_119 ++ = V_6 -> V_28 [ V_109 ] ;
}
}
static void F_37 ( struct V_5 * V_6 , int V_106 )
{
int V_109 ;
T_5 * V_93 ;
T_3 * V_119 ;
const T_5 * V_120 ;
const T_3 * V_121 ;
if ( ! V_6 -> V_57 -> V_93 )
return;
if ( V_106 == 8 ) {
V_93 = V_6 -> V_57 -> V_93 ;
V_120 = V_6 -> V_122 . V_123 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
* V_93 ++ = * V_120 ++ & 0xFF ;
} else {
V_119 = V_6 -> V_57 -> V_93 ;
V_121 = V_6 -> V_122 . V_123 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_18 ; V_109 ++ )
* V_119 ++ = * V_121 ++ ;
}
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_124 * V_122 ;
unsigned long V_71 ;
int V_125 ;
V_122 = & V_6 -> V_122 ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_6 ( V_6 -> V_2 , V_11 , V_118 , V_37 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
F_14 ( & V_6 -> V_2 -> V_40 ,
L_35 , V_41 ) ;
V_125 = F_39 ( V_6 -> V_39 ,
V_6 -> V_38 ,
F_40 ( 2 * V_126 ) ) ;
F_41 ( & V_6 -> V_2 -> V_40 , V_122 -> V_127 , V_122 -> V_128 ,
V_129 ) ;
F_41 ( & V_6 -> V_2 -> V_40 , V_122 -> V_130 , V_122 -> V_128 ,
V_129 ) ;
memset ( V_6 -> V_122 . V_131 , 0 , V_132 ) ;
F_42 ( V_122 -> V_133 ) ;
F_42 ( V_122 -> V_134 ) ;
F_31 ( V_122 -> V_130 ) ;
F_31 ( V_122 -> V_127 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_6 ( V_6 -> V_2 , V_11 , 0 ,
V_33 | V_135 | V_37 |
V_118 ) ;
F_1 ( V_6 -> V_2 , V_26 ,
F_4 ( V_6 -> V_2 , V_26 ) ) ;
F_8 ( V_6 -> V_2 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
return V_125 ;
}
static void F_43 ( void * V_136 )
{
struct V_5 * V_6 = V_136 ;
V_6 -> V_38 = true ;
F_44 ( & V_6 -> V_39 ) ;
}
static bool F_45 ( struct V_137 * V_138 , void * V_139 )
{
struct V_140 * V_141 = V_139 ;
if ( ( V_138 -> V_142 == V_141 -> V_142 ) &&
( V_141 -> V_143 == V_138 -> V_144 -> V_40 ) ) {
V_138 -> V_145 = V_141 ;
return true ;
} else {
return false ;
}
}
static void F_46 ( struct V_5 * V_6 , int V_106 )
{
T_6 V_146 ;
struct V_137 * V_138 ;
struct V_147 * V_143 ;
struct V_140 * V_141 ;
struct V_124 * V_122 ;
unsigned int V_148 ;
if ( V_106 == 8 )
V_148 = V_149 ;
else
V_148 = V_150 ;
V_122 = & V_6 -> V_122 ;
F_47 ( V_146 ) ;
F_48 ( V_151 , V_146 ) ;
V_143 = F_49 ( 2 , F_50 ( 12 , 0 ) ) ;
V_141 = & V_122 -> V_152 ;
V_141 -> V_143 = & V_143 -> V_40 ;
V_141 -> V_142 = V_6 -> V_2 -> V_153 * 2 ;
V_141 -> V_154 = V_6 -> V_155 + V_30 ;
V_141 -> V_148 = V_148 ;
V_138 = F_51 ( V_146 , F_45 , V_141 ) ;
if ( ! V_138 ) {
F_12 ( & V_6 -> V_2 -> V_40 ,
L_36 ) ;
V_6 -> V_58 = 0 ;
return;
}
V_122 -> V_156 = V_138 ;
V_141 = & V_122 -> V_157 ;
V_141 -> V_143 = & V_143 -> V_40 ;
V_141 -> V_142 = V_6 -> V_2 -> V_153 * 2 + 1 ;
V_141 -> V_158 = V_6 -> V_155 + V_29 ;
V_141 -> V_148 = V_148 ;
V_138 = F_51 ( V_146 , F_45 , V_141 ) ;
if ( ! V_138 ) {
F_12 ( & V_6 -> V_2 -> V_40 ,
L_37 ) ;
F_52 ( V_122 -> V_156 ) ;
V_122 -> V_156 = NULL ;
V_6 -> V_58 = 0 ;
return;
}
V_122 -> V_159 = V_138 ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_124 * V_122 ;
V_122 = & V_6 -> V_122 ;
if ( V_122 -> V_156 ) {
F_52 ( V_122 -> V_156 ) ;
V_122 -> V_156 = NULL ;
}
if ( V_122 -> V_159 ) {
F_52 ( V_122 -> V_159 ) ;
V_122 -> V_159 = NULL ;
}
return;
}
static void F_54 ( struct V_5 * V_6 , int * V_106 )
{
const T_5 * V_92 ;
const T_3 * V_110 ;
T_5 * V_160 ;
T_3 * V_161 ;
struct V_162 * V_163 ;
struct V_164 * V_134 ;
struct V_164 * V_133 ;
int V_165 ;
int V_166 ;
int V_107 ;
int V_167 ;
unsigned long V_71 ;
struct V_124 * V_122 ;
V_122 = & V_6 -> V_122 ;
if ( V_6 -> V_57 -> V_61 ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_25 , V_41 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_15 ( V_6 -> V_2 , V_6 -> V_57 -> V_61 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
}
if ( V_6 -> V_57 -> V_67 &&
( V_6 -> V_51 -> V_70 -> V_67 !=
V_6 -> V_57 -> V_67 ) ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_26 , V_41 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_16 ( V_6 -> V_2 ,
V_6 -> V_57 -> V_67 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
* V_106 = V_6 -> V_57 -> V_67 ;
} else {
* V_106 = V_6 -> V_51 -> V_70 -> V_67 ;
}
V_6 -> V_18 = V_6 -> V_57 -> V_95 / ( * V_106 / 8 ) ;
if ( V_6 -> V_57 -> V_92 != NULL ) {
if ( * V_106 == 8 ) {
V_92 = V_6 -> V_57 -> V_92 ;
V_160 = V_122 -> V_131 ;
for ( V_166 = 0 ; V_166 < V_6 -> V_18 ; V_166 ++ )
* V_160 ++ = * V_92 ++ ;
} else {
V_110 = V_6 -> V_57 -> V_92 ;
V_161 = V_122 -> V_131 ;
for ( V_166 = 0 ; V_166 < V_6 -> V_18 ; V_166 ++ )
* V_161 ++ = * V_110 ++ ;
}
}
if ( V_6 -> V_18 > V_168 ) {
V_165 = V_6 -> V_18 / V_168 + 1 ;
V_107 = V_168 ;
V_167 = V_6 -> V_18 % V_168 ;
} else {
V_165 = 1 ;
V_107 = V_6 -> V_18 ;
V_167 = V_6 -> V_18 ;
}
F_14 ( & V_6 -> V_2 -> V_40 , L_38 ,
V_41 , V_165 , V_107 , V_167 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_6 ( V_6 -> V_2 , V_11 ,
( ( V_107 - 1 ) << V_35 ) |
( V_169 << V_170 ) ,
V_33 | V_135 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
V_122 -> V_127 = F_30 ( sizeof( struct V_162 ) * V_165 , V_171 ) ;
F_55 ( V_122 -> V_127 , V_165 ) ;
V_163 = V_122 -> V_127 ;
for ( V_166 = 0 ; V_166 < V_165 ; V_166 ++ , V_163 ++ ) {
if ( V_166 == ( V_165 - 2 ) ) {
V_163 -> V_172 = V_107 * V_166 ;
V_163 -> V_172 = V_163 -> V_172 * ( * V_106 / 8 ) ;
F_56 ( V_163 , F_57 ( V_122 -> V_123 ) , V_167 ,
V_163 -> V_172 ) ;
F_58 ( V_163 ) = V_167 ;
} else if ( V_166 == ( V_165 - 1 ) ) {
V_163 -> V_172 = V_107 * ( V_166 - 1 ) + V_167 ;
V_163 -> V_172 = V_163 -> V_172 * ( * V_106 / 8 ) ;
F_56 ( V_163 , F_57 ( V_122 -> V_123 ) , V_107 ,
V_163 -> V_172 ) ;
F_58 ( V_163 ) = V_107 ;
} else {
V_163 -> V_172 = V_107 * V_166 ;
V_163 -> V_172 = V_163 -> V_172 * ( * V_106 / 8 ) ;
F_56 ( V_163 , F_57 ( V_122 -> V_123 ) , V_107 ,
V_163 -> V_172 ) ;
F_58 ( V_163 ) = V_107 ;
}
F_59 ( V_163 ) = V_122 -> V_173 + V_163 -> V_172 ;
}
V_163 = V_122 -> V_127 ;
V_133 = V_122 -> V_159 -> V_144 -> V_174 ( V_122 -> V_159 , V_163 ,
V_165 , V_175 ,
V_176 | V_177 ) ;
if ( ! V_133 ) {
F_12 ( & V_6 -> V_2 -> V_40 , L_39 ,
V_41 ) ;
return;
}
F_60 ( & V_6 -> V_2 -> V_40 , V_163 , V_165 , V_129 ) ;
V_133 -> V_178 = F_43 ;
V_133 -> V_179 = V_6 ;
V_122 -> V_128 = V_165 ;
V_122 -> V_133 = V_133 ;
if ( V_6 -> V_18 > V_168 ) {
V_165 = V_6 -> V_18 / V_168 ;
V_107 = V_168 ;
V_167 = 16 ;
} else {
V_165 = 1 ;
V_107 = V_6 -> V_18 ;
V_167 = V_6 -> V_18 ;
}
V_122 -> V_130 = F_30 ( sizeof( struct V_162 ) * V_165 , V_171 ) ;
F_55 ( V_122 -> V_130 , V_165 ) ;
V_163 = V_122 -> V_130 ;
for ( V_166 = 0 ; V_166 < V_165 ; V_166 ++ , V_163 ++ ) {
if ( V_166 == 0 ) {
V_163 -> V_172 = 0 ;
F_56 ( V_163 , F_57 ( V_122 -> V_131 ) , V_167 ,
V_163 -> V_172 ) ;
F_58 ( V_163 ) = V_167 ;
} else {
V_163 -> V_172 = V_167 + V_107 * ( V_166 - 1 ) ;
V_163 -> V_172 = V_163 -> V_172 * ( * V_106 / 8 ) ;
F_56 ( V_163 , F_57 ( V_122 -> V_131 ) , V_107 ,
V_163 -> V_172 ) ;
F_58 ( V_163 ) = V_107 ;
}
F_59 ( V_163 ) = V_122 -> V_180 + V_163 -> V_172 ;
}
V_163 = V_122 -> V_130 ;
V_134 = V_122 -> V_156 -> V_144 -> V_174 ( V_122 -> V_156 ,
V_163 , V_165 , V_181 ,
V_176 | V_177 ) ;
if ( ! V_134 ) {
F_12 ( & V_6 -> V_2 -> V_40 , L_39 ,
V_41 ) ;
return;
}
F_60 ( & V_6 -> V_2 -> V_40 , V_163 , V_165 , V_182 ) ;
V_134 -> V_178 = NULL ;
V_134 -> V_179 = V_6 ;
V_122 -> V_128 = V_165 ;
V_122 -> V_134 = V_134 ;
F_14 ( & V_6 -> V_2 -> V_40 , L_28
L_29 , V_41 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
F_1 ( V_6 -> V_2 , V_113 , V_114 ) ;
V_133 -> V_183 ( V_133 ) ;
V_134 -> V_183 ( V_134 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
V_6 -> V_38 = false ;
}
static void F_61 ( struct V_184 * V_185 )
{
struct V_84 * V_85 ;
struct V_5 * V_6 ;
int V_106 ;
V_6 = F_62 ( V_185 , struct V_5 , V_102 ) ;
F_14 ( & V_6 -> V_2 -> V_40 , L_40 , V_41 ) ;
F_63 ( & V_6 -> V_91 ) ;
if ( V_6 -> V_47 -> V_48 || ( V_6 -> V_53 == V_96 ) ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_41
L_42 , V_41 ) ;
F_24 (pmsg, data->queue.next, queue) {
V_85 -> V_53 = - V_54 ;
if ( V_85 -> V_52 != 0 ) {
F_64 ( & V_6 -> V_91 ) ;
V_85 -> V_52 ( V_85 -> V_55 ) ;
F_63 ( & V_6 -> V_91 ) ;
}
F_32 ( & V_85 -> V_100 ) ;
}
F_64 ( & V_6 -> V_91 ) ;
return;
}
V_6 -> V_56 = true ;
F_14 ( & V_6 -> V_2 -> V_40 ,
L_43 , V_41 ) ;
V_6 -> V_51 = F_65 ( V_6 -> V_100 . V_186 , struct V_84 ,
V_100 ) ;
F_32 ( & V_6 -> V_51 -> V_100 ) ;
V_6 -> V_51 -> V_53 = 0 ;
F_28 ( V_6 , V_6 -> V_51 -> V_70 ) ;
F_64 ( & V_6 -> V_91 ) ;
if ( V_6 -> V_58 )
F_46 ( V_6 ,
V_6 -> V_51 -> V_70 -> V_67 ) ;
F_1 ( V_6 -> V_2 , V_113 , V_187 ) ;
do {
F_63 ( & V_6 -> V_91 ) ;
if ( V_6 -> V_57 == NULL ) {
V_6 -> V_57 =
F_65 ( V_6 -> V_51 -> V_89 . V_186 ,
struct V_86 , V_188 ) ;
F_14 ( & V_6 -> V_2 -> V_40 , L_44
L_45 , V_41 ) ;
} else {
V_6 -> V_57 =
F_65 ( V_6 -> V_57 -> V_188 . V_186 ,
struct V_86 , V_188 ) ;
F_14 ( & V_6 -> V_2 -> V_40 , L_44
L_46 , V_41 ) ;
}
F_64 ( & V_6 -> V_91 ) ;
if ( V_6 -> V_58 ) {
F_54 ( V_6 , & V_106 ) ;
if ( ! F_38 ( V_6 ) )
goto V_189;
F_37 ( V_6 , V_106 ) ;
} else {
F_29 ( V_6 , & V_106 ) ;
F_34 ( V_6 ) ;
F_36 ( V_6 , V_106 ) ;
F_31 ( V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
F_31 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
V_6 -> V_51 -> V_98 += V_6 -> V_57 -> V_95 ;
F_14 ( & V_6 -> V_2 -> V_40 ,
L_47 ,
V_41 , V_6 -> V_51 -> V_98 ) ;
if ( V_6 -> V_57 -> V_190 ) {
F_14 ( & V_6 -> V_2 -> V_40 , L_48
L_49 , V_41 ,
V_6 -> V_57 -> V_190 ) ;
F_66 ( V_6 -> V_57 -> V_190 ) ;
}
F_63 ( & V_6 -> V_91 ) ;
if ( ( V_6 -> V_57 -> V_188 . V_186 ) ==
& ( V_6 -> V_51 -> V_89 ) ) {
F_33 ( V_6 ) ;
}
F_64 ( & V_6 -> V_91 ) ;
} while ( V_6 -> V_57 != NULL );
V_189:
F_1 ( V_6 -> V_2 , V_113 , V_191 ) ;
if ( V_6 -> V_58 )
F_53 ( V_6 ) ;
}
static void F_67 ( struct V_46 * V_47 ,
struct V_5 * V_6 )
{
F_14 ( & V_47 -> V_49 -> V_40 , L_50 , V_41 ) ;
if ( V_6 -> V_101 != NULL ) {
F_68 ( V_6 -> V_101 ) ;
V_6 -> V_101 = NULL ;
F_14 ( & V_47 -> V_49 -> V_40 ,
L_51 ,
V_41 ) ;
}
}
static int F_69 ( struct V_46 * V_47 ,
struct V_5 * V_6 )
{
int V_88 = 0 ;
F_14 ( & V_47 -> V_49 -> V_40 , L_50 , V_41 ) ;
V_6 -> V_101 = F_70 ( V_192 ) ;
if ( ! V_6 -> V_101 ) {
F_12 ( & V_47 -> V_49 -> V_40 ,
L_52 , V_41 ) ;
V_88 = - V_193 ;
goto V_194;
}
F_18 ( V_6 -> V_2 ) ;
F_14 ( & V_47 -> V_49 -> V_40 ,
L_53 , V_41 ) ;
F_14 ( & V_47 -> V_49 -> V_40 , L_54 , V_41 ) ;
V_194:
if ( V_88 != 0 ) {
F_12 ( & V_47 -> V_49 -> V_40 ,
L_55 , V_41 ) ;
F_67 ( V_47 , V_6 ) ;
}
F_14 ( & V_47 -> V_49 -> V_40 , L_56 , V_41 , V_88 ) ;
return V_88 ;
}
static void F_71 ( struct V_46 * V_47 ,
struct V_5 * V_6 )
{
struct V_124 * V_122 ;
V_122 = & V_6 -> V_122 ;
if ( V_122 -> V_180 )
F_72 ( & V_47 -> V_49 -> V_40 , V_195 ,
V_122 -> V_131 , V_122 -> V_180 ) ;
if ( V_122 -> V_173 )
F_72 ( & V_47 -> V_49 -> V_40 , V_195 ,
V_122 -> V_123 , V_122 -> V_173 ) ;
return;
}
static void F_73 ( struct V_46 * V_47 ,
struct V_5 * V_6 )
{
struct V_124 * V_122 ;
V_122 = & V_6 -> V_122 ;
V_122 -> V_131 = F_74 ( & V_47 -> V_49 -> V_40 ,
V_195 , & V_122 -> V_180 , V_111 ) ;
V_122 -> V_123 = F_74 ( & V_47 -> V_49 -> V_40 ,
V_195 , & V_122 -> V_173 , V_111 ) ;
}
static int T_7 F_75 ( struct V_196 * V_197 )
{
int V_44 ;
struct V_1 * V_2 ;
struct V_46 * V_47 = F_76 ( & V_197 -> V_40 ) ;
struct V_5 * V_6 ;
F_14 ( & V_197 -> V_40 , L_57 , V_41 ) ;
V_2 = F_77 ( & V_47 -> V_49 -> V_40 ,
sizeof( struct V_5 ) ) ;
if ( ! V_2 ) {
F_12 ( & V_197 -> V_40 , L_58 ,
V_197 -> V_198 ) ;
return - V_112 ;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
F_78 ( V_197 , V_6 ) ;
V_6 -> V_155 = F_79 ( V_47 -> V_49 , 1 ) +
V_199 * V_197 -> V_198 ;
V_6 -> V_7 = F_80 ( V_47 -> V_49 , 1 , 0 ) +
V_199 * V_197 -> V_198 ;
if ( ! V_6 -> V_7 ) {
F_12 ( & V_197 -> V_40 , L_59 , V_41 ) ;
V_44 = - V_112 ;
goto V_200;
}
F_14 ( & V_197 -> V_40 , L_60 ,
V_197 -> V_198 , V_6 -> V_7 ) ;
V_2 -> V_153 = - 1 ;
V_2 -> V_201 = V_202 ;
V_2 -> V_203 = F_19 ;
V_2 -> V_87 = F_20 ;
V_6 -> V_47 = V_47 ;
V_6 -> V_197 = V_197 ;
V_6 -> V_105 = 255 ;
V_6 -> V_53 = V_204 ;
V_6 -> V_205 = V_197 -> V_198 ;
V_6 -> V_58 = V_58 ;
F_81 ( & V_6 -> V_100 ) ;
F_82 ( & V_6 -> V_91 ) ;
F_83 ( & V_6 -> V_102 , F_61 ) ;
F_84 ( & V_6 -> V_39 ) ;
V_44 = F_69 ( V_47 , V_6 ) ;
if ( V_44 ) {
F_12 ( & V_197 -> V_40 , L_61 , V_41 , V_44 ) ;
goto V_206;
}
V_44 = F_85 ( V_47 -> V_49 -> V_42 , F_13 ,
V_207 , V_192 , V_6 ) ;
if ( V_44 ) {
F_12 ( & V_197 -> V_40 ,
L_62 , V_41 ) ;
goto V_208;
}
V_6 -> V_209 = true ;
F_7 ( V_2 ) ;
V_44 = F_86 ( V_2 ) ;
if ( V_44 != 0 ) {
F_12 ( & V_197 -> V_40 ,
L_63 , V_41 ) ;
goto V_210;
}
if ( V_58 ) {
F_87 ( & V_197 -> V_40 , L_64 ) ;
F_73 ( V_47 , V_6 ) ;
}
return 0 ;
V_210:
F_88 ( V_47 -> V_49 -> V_42 , V_47 ) ;
V_208:
F_67 ( V_47 , V_6 ) ;
V_206:
F_89 ( V_47 -> V_49 , V_6 -> V_7 ) ;
V_200:
F_90 ( V_2 ) ;
return V_44 ;
}
static int T_8 F_91 ( struct V_196 * V_197 )
{
struct V_46 * V_47 = F_76 ( & V_197 -> V_40 ) ;
struct V_5 * V_6 = F_92 ( V_197 ) ;
int V_211 ;
unsigned long V_71 ;
F_14 ( & V_197 -> V_40 , L_65 ,
V_41 , V_197 -> V_198 , V_47 -> V_49 -> V_42 ) ;
if ( V_58 )
F_71 ( V_47 , V_6 ) ;
V_211 = 500 ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
V_6 -> V_53 = V_96 ;
while ( ( F_22 ( & V_6 -> V_100 ) == 0 ) && -- V_211 ) {
F_14 ( & V_47 -> V_49 -> V_40 , L_66 ,
V_41 ) ;
F_25 ( & V_6 -> V_91 , V_71 ) ;
F_93 ( V_212 ) ;
F_23 ( & V_6 -> V_91 , V_71 ) ;
}
F_25 ( & V_6 -> V_91 , V_71 ) ;
F_67 ( V_47 , V_6 ) ;
if ( V_6 -> V_209 ) {
F_6 ( V_6 -> V_2 , V_11 , 0 , V_37 ) ;
V_6 -> V_209 = false ;
F_88 ( V_47 -> V_49 -> V_42 , V_6 ) ;
}
F_89 ( V_47 -> V_49 , V_6 -> V_7 ) ;
F_94 ( V_6 -> V_2 ) ;
F_90 ( V_6 -> V_2 ) ;
F_78 ( V_197 , NULL ) ;
return 0 ;
}
static int F_95 ( struct V_196 * V_213 ,
T_9 V_214 )
{
T_5 V_211 ;
struct V_46 * V_47 = F_76 ( & V_213 -> V_40 ) ;
struct V_5 * V_6 = F_92 ( V_213 ) ;
F_14 ( & V_213 -> V_40 , L_50 , V_41 ) ;
if ( ! V_47 ) {
F_12 ( & V_213 -> V_40 ,
L_67 , V_41 ) ;
return - V_215 ;
}
V_211 = 255 ;
while ( ( -- V_211 ) > 0 ) {
if ( ! ( V_6 -> V_56 ) )
break;
F_93 ( V_212 ) ;
}
if ( V_6 -> V_209 ) {
F_6 ( V_6 -> V_2 , V_11 , 0 , V_37 ) ;
F_18 ( V_6 -> V_2 ) ;
F_88 ( V_47 -> V_49 -> V_42 , V_6 ) ;
V_6 -> V_209 = false ;
F_14 ( & V_213 -> V_40 ,
L_68 , V_41 ) ;
}
return 0 ;
}
static int F_96 ( struct V_196 * V_213 )
{
struct V_46 * V_47 = F_76 ( & V_213 -> V_40 ) ;
struct V_5 * V_6 = F_92 ( V_213 ) ;
int V_88 ;
if ( ! V_47 ) {
F_12 ( & V_213 -> V_40 ,
L_67 , V_41 ) ;
return - V_215 ;
}
if ( ! V_6 -> V_209 ) {
V_88 = F_85 ( V_47 -> V_49 -> V_42 , F_13 ,
V_207 , V_192 , V_6 ) ;
if ( V_88 < 0 ) {
F_12 ( & V_213 -> V_40 ,
L_62 , V_41 ) ;
return V_88 ;
}
F_18 ( V_6 -> V_2 ) ;
F_7 ( V_6 -> V_2 ) ;
V_6 -> V_209 = true ;
}
return 0 ;
}
static int T_7 F_97 ( struct V_147 * V_49 ,
const struct V_216 * V_198 )
{
struct V_46 * V_47 ;
struct V_196 * V_213 = NULL ;
int V_88 ;
int V_166 ;
struct V_217 * V_218 ;
V_218 = F_30 ( sizeof( struct V_217 ) , V_111 ) ;
if ( ! V_218 ) {
F_12 ( & V_49 -> V_40 , L_69 , V_41 ) ;
return - V_112 ;
}
V_47 = F_30 ( sizeof( struct V_46 ) , V_111 ) ;
if ( ! V_47 ) {
F_12 ( & V_49 -> V_40 , L_70 , V_41 ) ;
V_88 = - V_112 ;
goto V_219;
}
V_88 = F_98 ( V_49 , V_192 ) ;
if ( V_88 ) {
F_12 ( & V_49 -> V_40 , L_71 , V_41 ) ;
goto F_98;
}
V_47 -> V_49 = V_49 ;
V_47 -> V_165 = V_198 -> V_220 ;
V_218 -> V_165 = V_198 -> V_220 ;
V_218 -> V_47 = V_47 ;
V_88 = F_99 ( V_49 ) ;
if ( V_88 ) {
F_12 ( & V_49 -> V_40 , L_72 , V_41 ) ;
goto F_99;
}
for ( V_166 = 0 ; V_166 < V_47 -> V_165 ; V_166 ++ ) {
V_213 = F_100 ( L_73 , V_166 ) ;
if ( ! V_213 ) {
F_12 ( & V_49 -> V_40 , L_74 ) ;
goto V_221;
}
V_218 -> V_222 [ V_166 ] = V_213 ;
V_213 -> V_40 . V_223 = & V_49 -> V_40 ;
V_88 = F_101 ( V_213 , V_47 ,
sizeof( * V_47 ) ) ;
if ( V_88 ) {
F_12 ( & V_49 -> V_40 ,
L_75 ) ;
F_102 ( V_213 ) ;
goto V_221;
}
V_88 = F_103 ( V_213 ) ;
if ( V_88 ) {
F_12 ( & V_49 -> V_40 , L_76 ) ;
F_102 ( V_213 ) ;
goto V_221;
}
}
F_104 ( V_49 , V_218 ) ;
return 0 ;
V_221:
F_105 ( V_49 ) ;
F_99:
F_106 ( V_49 ) ;
F_98:
F_31 ( V_47 ) ;
V_219:
F_31 ( V_218 ) ;
return V_88 ;
}
static void T_8 F_107 ( struct V_147 * V_49 )
{
int V_166 ;
struct V_217 * V_218 = F_108 ( V_49 ) ;
F_14 ( & V_49 -> V_40 , L_77 , V_41 , V_49 ) ;
for ( V_166 = 0 ; V_166 < V_218 -> V_165 ; V_166 ++ )
F_109 ( V_218 -> V_222 [ V_166 ] ) ;
F_105 ( V_49 ) ;
F_106 ( V_49 ) ;
F_31 ( V_218 -> V_47 ) ;
F_31 ( V_218 ) ;
}
static int F_110 ( struct V_147 * V_49 , T_9 V_214 )
{
int V_88 ;
struct V_217 * V_218 = F_108 ( V_49 ) ;
F_14 ( & V_49 -> V_40 , L_50 , V_41 ) ;
V_218 -> V_47 -> V_48 = true ;
V_88 = F_111 ( V_49 ) ;
if ( V_88 == 0 ) {
F_112 ( V_49 , V_224 , 0 ) ;
F_105 ( V_49 ) ;
F_113 ( V_49 , V_224 ) ;
} else {
F_12 ( & V_49 -> V_40 , L_78 , V_41 ) ;
}
return V_88 ;
}
static int F_114 ( struct V_147 * V_49 )
{
int V_88 ;
struct V_217 * V_218 = F_108 ( V_49 ) ;
F_14 ( & V_49 -> V_40 , L_50 , V_41 ) ;
F_113 ( V_49 , V_225 ) ;
F_115 ( V_49 ) ;
V_88 = F_99 ( V_49 ) ;
if ( V_88 < 0 ) {
F_12 ( & V_49 -> V_40 ,
L_72 , V_41 ) ;
} else {
F_112 ( V_49 , V_224 , 0 ) ;
V_218 -> V_47 -> V_48 = false ;
}
return V_88 ;
}
static int T_10 F_116 ( void )
{
int V_44 ;
V_44 = F_117 ( & V_226 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_118 ( & V_227 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
static void T_11 F_119 ( void )
{
F_120 ( & V_227 ) ;
F_121 ( & V_226 ) ;
}
