static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_12 ; V_10 ++ ) {
if ( ! F_3 ( V_10 , V_6 -> V_13 ) )
continue;
V_9 -> V_14 [ V_11 ] = F_4 ( V_9 , F_5 ( V_9 , V_10 ) ) ;
V_11 ++ ;
}
F_6 ( V_6 , V_9 -> V_14 , V_4 -> V_15 ) ;
F_7 ( V_6 -> V_16 ) ;
F_4 ( V_9 , V_17 ) ;
F_8 ( V_9 -> V_1 ) ;
return V_18 ;
}
static void F_9 ( int V_1 , struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
if ( F_10 ( V_6 ) ) {
F_11 ( V_1 ) ;
F_12 ( V_6 -> V_16 ) ;
} else {
V_9 -> V_19 = F_4 ( V_9 , F_5 ( V_9 , V_9 -> V_20 ) ) ;
V_9 -> V_21 = true ;
F_13 ( & V_9 -> V_22 ) ;
}
}
static int F_14 ( struct V_8 * V_9 )
{
unsigned int V_23 , V_24 , V_25 , V_26 , V_27 ;
unsigned int V_28 , V_29 , V_30 , V_31 , V_32 ;
unsigned int V_33 = 1 ;
unsigned int V_34 = 1000 ;
struct V_5 * V_6 = F_15 ( V_9 ) ;
unsigned int V_35 = V_9 -> V_36 ;
unsigned int V_37 = ( 1 << V_35 ) - 1 ;
V_25 = F_4 ( V_9 , V_38 ) ;
V_31 = V_25 & V_37 ;
V_28 = ( V_31 << V_39 ) - V_31 ;
V_23 = ( V_25 >> 16 ) & V_37 ;
if ( V_23 == 0 ) {
F_16 ( & V_6 -> V_40 , L_1 ) ;
return - 1 ;
}
V_28 /= V_23 ;
V_25 = F_4 ( V_9 , V_41 ) ;
V_32 = V_25 & V_37 ;
V_29 = ( V_32 << V_39 ) - V_32 ;
V_24 = ( V_25 >> 16 ) & V_37 ;
if ( V_24 == 0 ) {
F_16 ( & V_6 -> V_40 , L_2 ) ;
return - 1 ;
}
V_29 /= V_24 ;
V_25 = F_4 ( V_9 , V_42 ) ;
V_26 = V_25 & V_37 ;
V_27 = ( V_25 >> 16 ) & V_37 ;
if ( V_26 != 0 )
V_30 = V_33 * ( V_28 * V_34 / 1024 ) * ( V_27 * V_34 / V_26 - V_34 )
/ V_34 ;
else
V_30 = V_9 -> V_43 ;
F_17 ( & V_6 -> V_40 , L_3 ,
V_31 , V_23 , V_32 , V_24 , V_26 , V_27 , V_30 ) ;
if ( V_30 < V_9 -> V_43 ) {
F_17 ( & V_6 -> V_40 , L_4 ,
V_28 , V_29 , V_30 / V_34 ) ;
F_18 ( V_9 -> V_44 , V_45 , V_28 ) ;
F_18 ( V_9 -> V_44 , V_46 , V_29 ) ;
F_18 ( V_9 -> V_44 , V_47 , V_30 ) ;
F_19 ( V_9 -> V_44 , V_48 , 1 ) ;
F_20 ( V_9 -> V_44 ) ;
} else {
F_17 ( & V_6 -> V_40 , L_5 ) ;
}
return 0 ;
}
static T_1 F_21 ( int V_1 , void * V_49 )
{
struct V_5 * V_6 = V_49 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_2 V_50 = F_4 ( V_9 , V_9 -> V_51 -> V_52 ) ;
unsigned int V_25 ;
V_50 &= F_4 ( V_9 , V_53 ) ;
if ( V_50 & F_22 ( V_9 -> V_54 - 1 , 0 ) )
F_9 ( V_1 , V_6 ) ;
if ( V_50 & V_55 ) {
V_25 = F_4 ( V_9 , V_56 ) ;
V_25 &= ~ V_57 ;
F_23 ( V_9 , V_56 , V_25 ) ;
F_23 ( V_9 , V_58 , V_55 ) ;
F_23 ( V_9 , V_59 , V_60
| F_24 ( 3 ) ) ;
F_23 ( V_9 , V_9 -> V_51 -> V_61 ,
V_62 |
F_25 ( V_9 -> V_63 ) ) ;
} else if ( V_50 & V_60 ) {
V_25 = F_4 ( V_9 , V_56 ) ;
V_25 |= F_26 ( V_9 -> V_64 ) & V_57 ;
F_23 ( V_9 , V_56 , V_25 ) ;
F_23 ( V_9 , V_9 -> V_51 -> V_61 ,
V_65 ) ;
F_23 ( V_9 , V_58 , V_60
| F_24 ( 3 ) ) ;
F_23 ( V_9 , V_59 , V_55 ) ;
V_9 -> V_66 = false ;
F_19 ( V_9 -> V_44 , V_48 , 0 ) ;
F_20 ( V_9 -> V_44 ) ;
} else if ( V_50 & F_24 ( 3 ) && V_9 -> V_44 ) {
if ( V_9 -> V_66 ) {
F_18 ( V_9 -> V_44 , V_45 , V_9 -> V_67 ) ;
F_18 ( V_9 -> V_44 , V_46 , V_9 -> V_68 ) ;
F_19 ( V_9 -> V_44 , V_48 , 1 ) ;
F_20 ( V_9 -> V_44 ) ;
} else
V_9 -> V_66 = true ;
V_9 -> V_67 = F_4 ( V_9 , F_5 ( V_9 , 3 ) )
<< V_69 ;
V_9 -> V_67 /= F_4 ( V_9 , F_5 ( V_9 , 2 ) ) ;
V_9 -> V_68 = F_4 ( V_9 , F_5 ( V_9 , 1 ) )
<< V_69 ;
V_9 -> V_68 /= F_4 ( V_9 , F_5 ( V_9 , 0 ) ) ;
}
return V_18 ;
}
static T_1 F_27 ( int V_1 , void * V_49 )
{
struct V_5 * V_6 = V_49 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_2 V_50 = F_4 ( V_9 , V_9 -> V_51 -> V_52 ) ;
const T_3 V_70 =
V_71 |
V_72 |
V_73 ;
if ( V_50 & F_22 ( V_9 -> V_54 - 1 , 0 ) )
F_9 ( V_1 , V_6 ) ;
if ( V_50 & V_74 ) {
F_23 ( V_9 , V_58 , V_74 ) ;
F_23 ( V_9 , V_59 , V_75 |
V_70 ) ;
F_23 ( V_9 , V_9 -> V_51 -> V_61 ,
V_62 |
F_25 ( V_9 -> V_63 ) ) ;
} else if ( V_50 & V_75 ) {
F_23 ( V_9 , V_9 -> V_51 -> V_61 , 0 ) ;
F_23 ( V_9 , V_58 , V_75 |
V_70 ) ;
F_23 ( V_9 , V_59 , V_74 ) ;
F_19 ( V_9 -> V_44 , V_48 , 0 ) ;
F_20 ( V_9 -> V_44 ) ;
} else if ( ( V_50 & V_70 ) == V_70 ) {
if ( V_50 & V_76 ) {
F_14 ( V_9 ) ;
} else {
F_4 ( V_9 , V_38 ) ;
F_4 ( V_9 , V_41 ) ;
F_4 ( V_9 , V_42 ) ;
}
}
return V_18 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_77 * V_78 , * V_15 ;
int V_79 , V_80 = 0 ;
unsigned long V_81 = 0 ;
if ( V_9 -> V_82 == V_83 )
V_81 = V_84 ;
else if ( V_9 -> V_82 == V_85 )
V_81 = V_86 ;
V_9 -> V_87 &= ~ V_81 ;
V_6 -> V_54 = F_29 ( & V_9 -> V_87 ,
V_9 -> V_54 ) + 1 ;
V_78 = F_30 ( & V_6 -> V_40 ,
( ( V_6 -> V_54 + 1 ) *
sizeof( struct V_77 ) ) ,
V_88 ) ;
if ( ! V_78 )
return - V_89 ;
F_31 (bit, &st->channels_mask, st->num_channels) {
struct V_77 * V_90 = V_78 + V_80 ;
V_90 -> type = V_91 ;
V_90 -> V_92 = 1 ;
V_90 -> V_93 = V_79 ;
V_90 -> V_94 = V_80 ;
V_90 -> V_95 . V_96 = 'u' ;
V_90 -> V_95 . V_97 = V_9 -> V_36 ;
V_90 -> V_95 . V_98 = 16 ;
V_90 -> V_99 = F_32 ( V_100 ) ;
V_90 -> V_101 = F_32 ( V_102 ) ;
V_80 ++ ;
}
V_15 = V_78 + V_80 ;
V_15 -> type = V_103 ;
V_15 -> V_93 = - 1 ;
V_15 -> V_94 = V_80 ;
V_15 -> V_95 . V_96 = 's' ;
V_15 -> V_95 . V_97 = 64 ;
V_15 -> V_95 . V_98 = 64 ;
V_6 -> V_104 = V_78 ;
return V_6 -> V_54 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_105 * V_106 ,
const char * V_107 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_108 ; V_10 ++ ) {
char * V_109 = F_34 ( V_88 ,
L_6 ,
V_6 -> V_109 ,
V_6 -> V_110 ,
V_106 [ V_10 ] . V_109 ) ;
if ( ! V_109 )
return - V_89 ;
if ( strcmp ( V_107 , V_109 ) == 0 ) {
F_35 ( V_109 ) ;
if ( V_106 [ V_10 ] . V_111 == 0 )
return - V_112 ;
return V_106 [ V_10 ] . V_111 ;
}
F_35 ( V_109 ) ;
}
return - V_112 ;
}
static int F_36 ( struct V_113 * V_16 , bool V_114 )
{
struct V_5 * V_6 = F_37 ( V_16 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_115 * V_25 = V_9 -> V_51 ;
T_2 V_50 = F_4 ( V_9 , V_25 -> V_61 ) ;
int V_111 ;
T_4 V_79 ;
V_111 = F_33 ( V_6 ,
V_9 -> V_116 ,
V_6 -> V_16 -> V_109 ) ;
if ( V_111 < 0 )
return V_111 ;
if ( V_114 ) {
V_9 -> V_14 = F_38 ( V_6 -> V_117 , V_88 ) ;
if ( V_9 -> V_14 == NULL )
return - V_89 ;
F_23 ( V_9 , V_25 -> V_61 ,
V_50 | V_111 ) ;
F_31 (bit, idev->active_scan_mask,
st->num_channels) {
struct V_77 const * V_90 = V_6 -> V_104 + V_79 ;
F_23 ( V_9 , V_118 ,
F_39 ( V_90 -> V_93 ) ) ;
}
F_23 ( V_9 , V_59 , V_25 -> V_119 ) ;
} else {
F_23 ( V_9 , V_58 , V_25 -> V_119 ) ;
F_23 ( V_9 , V_25 -> V_61 ,
V_50 & ~ V_111 ) ;
F_31 (bit, idev->active_scan_mask,
st->num_channels) {
struct V_77 const * V_90 = V_6 -> V_104 + V_79 ;
F_23 ( V_9 , V_120 ,
F_39 ( V_90 -> V_93 ) ) ;
}
F_35 ( V_9 -> V_14 ) ;
}
return 0 ;
}
static struct V_113 * F_40 ( struct V_5 * V_6 ,
struct V_105 * V_121 )
{
struct V_113 * V_16 ;
int V_122 ;
V_16 = F_41 ( L_6 , V_6 -> V_109 ,
V_6 -> V_110 , V_121 -> V_109 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_40 . V_123 = V_6 -> V_40 . V_123 ;
F_42 ( V_16 , V_6 ) ;
V_16 -> V_124 = & V_125 ;
V_122 = F_43 ( V_16 ) ;
if ( V_122 )
return NULL ;
return V_16 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_122 ;
V_9 -> V_16 = F_30 ( & V_6 -> V_40 ,
V_9 -> V_108 * sizeof( * V_9 -> V_16 ) ,
V_88 ) ;
if ( V_9 -> V_16 == NULL ) {
V_122 = - V_89 ;
goto V_126;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_108 ; V_10 ++ ) {
if ( V_9 -> V_116 [ V_10 ] . V_127 && ! ( V_9 -> V_128 ) )
continue;
V_9 -> V_16 [ V_10 ] = F_40 ( V_6 ,
V_9 -> V_116 + V_10 ) ;
if ( V_9 -> V_16 [ V_10 ] == NULL ) {
F_16 ( & V_6 -> V_40 ,
L_7 , V_10 ) ;
V_122 = - V_89 ;
goto V_129;
}
}
return 0 ;
V_129:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- ) {
F_45 ( V_9 -> V_16 [ V_10 ] ) ;
F_46 ( V_9 -> V_16 [ V_10 ] ) ;
}
V_126:
return V_122 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_108 ; V_10 ++ ) {
F_45 ( V_9 -> V_16 [ V_10 ] ) ;
F_46 ( V_9 -> V_16 [ V_10 ] ) ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
return F_49 ( V_6 , & V_130 ,
& F_1 , NULL ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_77 const * V_90 ,
int * V_131 , int * V_132 , long V_133 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_122 ;
switch ( V_133 ) {
case V_102 :
F_53 ( & V_9 -> V_134 ) ;
V_9 -> V_20 = V_90 -> V_93 ;
F_23 ( V_9 , V_118 ,
F_39 ( V_90 -> V_93 ) ) ;
F_23 ( V_9 , V_59 , F_32 ( V_90 -> V_93 ) ) ;
F_23 ( V_9 , V_135 , V_136 ) ;
V_122 = F_54 ( V_9 -> V_22 ,
V_9 -> V_21 ,
F_55 ( 1000 ) ) ;
if ( V_122 == 0 )
V_122 = - V_137 ;
if ( V_122 < 0 ) {
F_56 ( & V_9 -> V_134 ) ;
return V_122 ;
}
* V_131 = V_9 -> V_19 ;
F_23 ( V_9 , V_120 ,
F_39 ( V_90 -> V_93 ) ) ;
F_23 ( V_9 , V_58 , F_32 ( V_90 -> V_93 ) ) ;
V_9 -> V_19 = 0 ;
V_9 -> V_21 = false ;
F_56 ( & V_9 -> V_134 ) ;
return V_138 ;
case V_100 :
* V_131 = V_9 -> V_139 ;
* V_132 = V_90 -> V_95 . V_97 ;
return V_140 ;
default:
break;
}
return - V_112 ;
}
static int F_57 ( struct V_8 * V_9 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_15 ( V_9 ) ;
struct V_143 * V_144 = V_142 -> V_40 . V_145 ;
int V_146 , V_10 , V_122 = 0 ;
char * V_147 , * V_148 ;
T_2 * V_149 ;
V_146 = F_58 ( V_144 , L_8 ) ;
if ( V_146 < 2 ) {
F_16 ( & V_6 -> V_40 , L_9
L_10 ) ;
return V_146 ;
}
V_149 = F_59 ( V_146 , sizeof( * V_149 ) , V_88 ) ;
if ( ! V_149 )
return - V_89 ;
if ( F_60 ( V_144 , L_11 , V_149 , V_146 ) ) {
F_16 ( & V_6 -> V_40 , L_12 ) ;
V_122 = - V_150 ;
goto V_122;
}
if ( F_61 ( V_144 , L_13 , ( const char * * ) & V_147 ) )
V_147 = L_14 ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
if ( F_62 ( V_144 , L_8 , V_10 , ( const char * * ) & V_148 ) )
continue;
if ( strcmp ( V_147 , V_148 ) )
continue;
V_9 -> V_36 = V_149 [ V_10 ] ;
if ( ! strcmp ( V_147 , L_15 ) )
V_9 -> V_151 = true ;
else
V_9 -> V_151 = false ;
F_63 ( & V_6 -> V_40 , L_16 , V_9 -> V_36 ) ;
goto V_122;
}
F_16 ( & V_6 -> V_40 , L_17 , V_147 ) ;
V_122:
F_35 ( V_149 ) ;
return V_122 ;
}
static T_2 F_64 ( T_2 V_152 , T_2 V_153 )
{
return F_65 ( ( V_152 * V_153 / 1000 ) - 1 , 8 ) / 8 ;
}
static T_2 F_66 ( T_2 V_152 , T_2 V_153 )
{
static const int V_154 [] = {
0 , 8 , 16 , 24 ,
64 , 80 , 96 , 112 ,
512 , 576 , 640 , 704 ,
768 , 832 , 896 , 960
} ;
int V_10 , V_155 = F_67 ( V_154 ) ;
unsigned int V_156 ;
V_156 = V_152 * V_153 / 1000 ;
for ( V_10 = 0 ; V_10 < V_155 ; V_10 ++ )
if ( V_156 < V_154 [ V_10 ] )
break;
V_156 = V_10 ;
if ( V_156 == V_155 )
V_156 = V_155 - 1 ;
return V_156 ;
}
static int F_68 ( struct V_143 * V_157 ,
struct V_8 * V_9 , struct V_158 * V_40 )
{
int V_122 ;
T_2 V_159 ;
V_122 = F_69 ( V_157 , L_18 , & V_159 ) ;
if ( V_122 ) {
F_63 ( V_40 , L_19 ) ;
return 0 ;
}
switch ( V_159 ) {
case 4 :
case 5 :
V_9 -> V_82 = V_159 ;
break;
default:
F_16 ( V_40 , L_20 , V_159 ) ;
return - V_112 ;
}
if ( ! V_9 -> V_160 -> V_161 )
return 0 ;
V_159 = 0 ;
F_69 ( V_157 , L_21 , & V_159 ) ;
V_9 -> V_43 = V_159 ;
if ( V_9 -> V_43 ) {
return 0 ;
} else {
F_16 ( V_40 , L_22 ) ;
return - V_112 ;
}
}
static int F_70 ( struct V_8 * V_9 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_15 ( V_9 ) ;
struct V_143 * V_157 = V_142 -> V_40 . V_145 ;
struct V_143 * V_162 ;
int V_10 = 0 , V_122 ;
T_2 V_159 ;
if ( ! V_157 )
return - V_112 ;
V_9 -> V_160 = (struct V_163 * )
F_71 ( V_164 , & V_142 -> V_40 ) -> V_165 ;
V_9 -> V_128 = F_72 ( V_157 , L_23 ) ;
if ( F_69 ( V_157 , L_24 , & V_159 ) ) {
F_16 ( & V_6 -> V_40 , L_25 ) ;
V_122 = - V_112 ;
goto V_126;
}
V_9 -> V_87 = V_159 ;
V_9 -> V_166 = F_72 ( V_157 , L_26 ) ;
if ( F_69 ( V_157 , L_27 , & V_159 ) ) {
F_16 ( & V_6 -> V_40 , L_28 ) ;
V_122 = - V_112 ;
goto V_126;
}
V_9 -> V_152 = V_159 ;
V_159 = 0 ;
F_69 ( V_157 , L_29 , & V_159 ) ;
V_9 -> V_167 = V_159 ;
if ( F_69 ( V_157 , L_30 , & V_159 ) ) {
F_16 ( & V_6 -> V_40 , L_31 ) ;
V_122 = - V_112 ;
goto V_126;
}
V_9 -> V_139 = V_159 ;
V_122 = F_57 ( V_9 , V_142 ) ;
if ( V_122 )
goto V_126;
V_9 -> V_51 = & V_9 -> V_160 -> V_51 ;
V_9 -> V_54 = V_9 -> V_160 -> V_54 ;
V_9 -> V_108 = F_73 ( V_157 ) ;
V_9 -> V_116 = F_30 ( & V_6 -> V_40 , V_9 -> V_108 *
sizeof( struct V_105 ) ,
V_88 ) ;
if ( ! V_9 -> V_116 ) {
F_16 ( & V_6 -> V_40 , L_32 ) ;
V_122 = - V_89 ;
goto V_126;
}
F_74 (node, trig_node) {
struct V_105 * V_16 = V_9 -> V_116 + V_10 ;
const char * V_109 ;
if ( F_61 ( V_162 , L_33 , & V_109 ) ) {
F_16 ( & V_6 -> V_40 , L_34 ) ;
V_122 = - V_112 ;
goto V_126;
}
V_16 -> V_109 = V_109 ;
if ( F_69 ( V_162 , L_35 , & V_159 ) ) {
F_16 ( & V_6 -> V_40 , L_36 ) ;
V_122 = - V_112 ;
goto V_126;
}
V_16 -> V_111 = V_159 ;
V_16 -> V_127 = F_72 ( V_162 , L_37 ) ;
V_10 ++ ;
}
if ( V_9 -> V_160 -> V_168 )
return F_68 ( V_157 , V_9 , & V_6 -> V_40 ) ;
else
F_63 ( & V_6 -> V_40 , L_38 ) ;
return 0 ;
V_126:
return V_122 ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_141 * V_142 )
{
struct V_169 * V_170 = V_142 -> V_40 . V_171 ;
if ( ! V_170 )
return - V_112 ;
V_9 -> V_160 = (struct V_163 * )
F_76 ( V_142 ) -> V_172 ;
V_9 -> V_128 = V_170 -> V_173 ;
V_9 -> V_139 = V_170 -> V_174 ;
V_9 -> V_87 = V_170 -> V_175 ;
V_9 -> V_54 = V_9 -> V_160 -> V_54 ;
V_9 -> V_152 = V_170 -> V_152 ;
V_9 -> V_108 = V_170 -> V_108 ;
V_9 -> V_116 = V_170 -> V_116 ;
V_9 -> V_51 = & V_9 -> V_160 -> V_51 ;
V_9 -> V_82 = V_170 -> V_82 ;
return 0 ;
}
static int F_77 ( struct V_176 * V_40 )
{
struct V_8 * V_9 = F_78 ( V_40 ) ;
if ( V_9 -> V_160 -> V_161 )
F_23 ( V_9 , V_59 , V_74 ) ;
else
F_23 ( V_9 , V_59 , V_55 ) ;
return 0 ;
}
static void F_79 ( struct V_176 * V_40 )
{
struct V_8 * V_9 = F_78 ( V_40 ) ;
if ( V_9 -> V_160 -> V_161 )
F_23 ( V_9 , V_58 , V_74 ) ;
else
F_23 ( V_9 , V_58 , V_55 ) ;
}
static int F_80 ( struct V_8 * V_9 , T_2 V_153 )
{
struct V_5 * V_6 = F_15 ( V_9 ) ;
T_2 V_25 = 0 ;
T_2 V_177 = 0 ;
int V_10 = 0 ;
V_9 -> V_64 = F_65 ( V_178 * V_153 /
1000 , 1 ) ;
while ( V_9 -> V_64 >> ++ V_10 )
;
if ( abs ( V_9 -> V_64 - ( 1 << V_10 ) ) < abs ( V_9 -> V_64 - ( 1 << ( V_10 - 1 ) ) ) )
V_9 -> V_64 = V_10 ;
else
V_9 -> V_64 = V_10 - 1 ;
if ( ! V_9 -> V_160 -> V_161 ) {
V_25 = F_4 ( V_9 , V_56 ) ;
V_25 |= V_179 | V_180 ;
V_25 |= F_26 ( V_9 -> V_64 ) & V_57 ;
F_23 ( V_9 , V_56 , V_25 ) ;
V_25 = F_81 ( V_181 ) & V_182 ;
F_23 ( V_9 , V_183 , V_25 ) ;
V_9 -> V_63 = F_65 ( ( V_184 *
V_153 / 1000 ) - 1 , 1 ) ;
return 0 ;
}
V_177 = F_82 ( V_185 * V_153 / 1000 , 4 ) ;
F_17 ( & V_6 -> V_40 , L_39 ,
V_153 , V_177 ) ;
if ( V_9 -> V_82 == V_83 )
V_25 = V_186 ;
else
V_25 = V_187 ;
V_25 |= F_83 ( V_177 ) & V_188 ;
V_25 |= F_84 ( V_9 -> V_160 -> V_189 )
& V_190 ;
V_25 |= F_85 ( V_9 -> V_64 ) & V_191 ;
V_25 |= V_192 ;
V_25 |= V_193 ;
V_25 |= 0x03 << 8 ;
F_23 ( V_9 , V_194 , V_25 ) ;
F_23 ( V_9 , V_195 , V_9 -> V_160 -> V_196
& V_197 ) ;
V_9 -> V_63 = F_65 ( ( V_198 *
V_153 / 1000 ) - 1 , 1 ) ;
return 0 ;
}
static int F_86 ( struct V_8 * V_9 ,
struct V_141 * V_142 )
{
struct V_176 * V_199 ;
struct V_5 * V_6 = F_15 ( V_9 ) ;
int V_122 ;
V_199 = F_87 () ;
if ( ! V_199 ) {
F_16 ( & V_6 -> V_40 , L_40 ) ;
return - V_89 ;
}
V_199 -> V_109 = V_200 ;
V_199 -> V_110 . V_201 = V_202 ;
V_199 -> V_40 . V_123 = & V_142 -> V_40 ;
V_199 -> V_203 = F_77 ;
V_199 -> V_204 = F_79 ;
F_88 ( V_205 , V_199 -> V_206 ) ;
F_88 ( V_207 , V_199 -> V_206 ) ;
F_88 ( V_48 , V_199 -> V_208 ) ;
if ( V_9 -> V_160 -> V_161 ) {
F_89 ( V_199 , V_45 , 0 , ( 1 << V_39 ) - 1 ,
0 , 0 ) ;
F_89 ( V_199 , V_46 , 0 , ( 1 << V_39 ) - 1 ,
0 , 0 ) ;
F_89 ( V_199 , V_47 , 0 , 0xffffff , 0 , 0 ) ;
} else {
if ( V_9 -> V_82 != V_83 ) {
F_16 ( & V_142 -> V_40 ,
L_41 ) ;
V_122 = - V_112 ;
goto V_209;
}
F_89 ( V_199 , V_45 , 0 , ( 1 << V_69 ) - 1 ,
0 , 0 ) ;
F_89 ( V_199 , V_46 , 0 , ( 1 << V_69 ) - 1 ,
0 , 0 ) ;
}
V_9 -> V_44 = V_199 ;
F_90 ( V_199 , V_9 ) ;
V_122 = F_91 ( V_199 ) ;
if ( V_122 )
goto V_209;
return V_122 ;
V_209:
F_92 ( V_9 -> V_44 ) ;
return V_122 ;
}
static void F_93 ( struct V_8 * V_9 )
{
F_94 ( V_9 -> V_44 ) ;
}
static int F_95 ( struct V_141 * V_142 )
{
unsigned int V_210 , V_211 , V_156 , V_212 , V_153 , V_213 ;
int V_122 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_214 * V_36 ;
T_2 V_25 ;
V_6 = F_96 ( & V_142 -> V_40 , sizeof( struct V_8 ) ) ;
if ( ! V_6 )
return - V_89 ;
V_9 = F_2 ( V_6 ) ;
if ( V_142 -> V_40 . V_145 )
V_122 = F_70 ( V_9 , V_142 ) ;
else
V_122 = F_75 ( V_9 , V_142 ) ;
if ( V_122 ) {
F_16 ( & V_142 -> V_40 , L_42 ) ;
return - V_112 ;
}
F_97 ( V_142 , V_6 ) ;
V_6 -> V_40 . V_123 = & V_142 -> V_40 ;
V_6 -> V_109 = F_98 ( & V_142 -> V_40 ) ;
V_6 -> V_215 = V_216 ;
V_6 -> V_217 = & V_218 ;
V_9 -> V_1 = F_99 ( V_142 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_16 ( & V_142 -> V_40 , L_43 ) ;
return - V_150 ;
}
V_36 = F_100 ( V_142 , V_219 , 0 ) ;
V_9 -> V_220 = F_101 ( & V_142 -> V_40 , V_36 ) ;
if ( F_102 ( V_9 -> V_220 ) ) {
return F_103 ( V_9 -> V_220 ) ;
}
F_23 ( V_9 , V_135 , V_221 ) ;
F_23 ( V_9 , V_58 , 0xFFFFFFFF ) ;
if ( V_9 -> V_160 -> V_161 )
V_122 = F_104 ( V_9 -> V_1 , F_27 , 0 ,
V_142 -> V_40 . V_222 -> V_109 , V_6 ) ;
else
V_122 = F_104 ( V_9 -> V_1 , F_21 , 0 ,
V_142 -> V_40 . V_222 -> V_109 , V_6 ) ;
if ( V_122 ) {
F_16 ( & V_142 -> V_40 , L_44 ) ;
return V_122 ;
}
V_9 -> V_223 = F_105 ( & V_142 -> V_40 , L_45 ) ;
if ( F_102 ( V_9 -> V_223 ) ) {
F_16 ( & V_142 -> V_40 , L_46 ) ;
V_122 = F_103 ( V_9 -> V_223 ) ;
goto V_224;
}
V_122 = F_106 ( V_9 -> V_223 ) ;
if ( V_122 ) {
F_16 ( & V_142 -> V_40 ,
L_47 ) ;
goto V_224;
}
V_9 -> V_212 = F_105 ( & V_142 -> V_40 , L_48 ) ;
if ( F_102 ( V_9 -> V_212 ) ) {
F_16 ( & V_142 -> V_40 , L_49 ) ;
V_122 = F_103 ( V_9 -> V_212 ) ;
goto V_225;
}
V_122 = F_106 ( V_9 -> V_212 ) ;
if ( V_122 ) {
F_16 ( & V_142 -> V_40 ,
L_50 ) ;
goto V_225;
}
V_211 = F_107 ( V_9 -> V_223 ) ;
V_212 = F_107 ( V_9 -> V_212 ) ;
V_153 = V_212 / 1000 ;
F_17 ( & V_142 -> V_40 , L_51 ,
V_211 , V_212 ) ;
V_210 = ( V_211 / ( 2 * V_212 ) ) - 1 ;
if ( ! V_9 -> V_152 ) {
F_16 ( & V_142 -> V_40 , L_52 ) ;
V_122 = - V_112 ;
goto V_226;
}
V_156 = (* V_9 -> V_160 -> V_227 )( V_9 -> V_152 , V_153 ) ;
if ( V_9 -> V_167 > 0 )
V_213 = F_65 ( ( V_9 -> V_167 * V_153 / 1000 )
- 1 , 1 ) ;
else
V_213 = 0 ;
V_25 = F_108 ( V_210 ) & V_9 -> V_51 -> V_228 ;
V_25 |= F_109 ( V_156 ) & V_9 -> V_51 -> V_229 ;
if ( V_9 -> V_151 )
V_25 |= V_230 ;
if ( V_9 -> V_166 )
V_25 |= V_231 ;
V_25 |= F_110 ( V_213 ) & V_232 ;
F_23 ( V_9 , V_56 , V_25 ) ;
V_122 = F_28 ( V_6 ) ;
if ( V_122 < 0 ) {
F_16 ( & V_142 -> V_40 , L_53 ) ;
goto V_226;
}
F_111 ( & V_9 -> V_22 ) ;
F_112 ( & V_9 -> V_134 ) ;
if ( ! V_9 -> V_82 ) {
V_122 = F_48 ( V_6 ) ;
if ( V_122 < 0 ) {
F_16 ( & V_142 -> V_40 , L_54 ) ;
goto V_226;
}
V_122 = F_44 ( V_6 ) ;
if ( V_122 < 0 ) {
F_16 ( & V_142 -> V_40 , L_55 ) ;
F_50 ( V_6 ) ;
goto V_226;
}
} else {
V_122 = F_86 ( V_9 , V_142 ) ;
if ( V_122 )
goto V_226;
F_80 ( V_9 , V_153 ) ;
}
V_122 = F_113 ( V_6 ) ;
if ( V_122 < 0 ) {
F_16 ( & V_142 -> V_40 , L_56 ) ;
goto V_233;
}
return 0 ;
V_233:
if ( ! V_9 -> V_82 ) {
F_47 ( V_6 ) ;
F_50 ( V_6 ) ;
} else {
F_93 ( V_9 ) ;
}
V_226:
F_114 ( V_9 -> V_212 ) ;
V_225:
F_114 ( V_9 -> V_223 ) ;
V_224:
F_115 ( V_9 -> V_1 , V_6 ) ;
return V_122 ;
}
static int F_116 ( struct V_141 * V_142 )
{
struct V_5 * V_6 = F_117 ( V_142 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_118 ( V_6 ) ;
if ( ! V_9 -> V_82 ) {
F_47 ( V_6 ) ;
F_50 ( V_6 ) ;
} else {
F_93 ( V_9 ) ;
}
F_114 ( V_9 -> V_212 ) ;
F_114 ( V_9 -> V_223 ) ;
F_115 ( V_9 -> V_1 , V_6 ) ;
return 0 ;
}
static int F_119 ( struct V_158 * V_40 )
{
struct V_5 * V_6 = F_117 ( F_120 ( V_40 ) ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_121 ( V_40 ) ;
F_114 ( V_9 -> V_223 ) ;
return 0 ;
}
static int F_122 ( struct V_158 * V_40 )
{
struct V_5 * V_6 = F_117 ( F_120 ( V_40 ) ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_106 ( V_9 -> V_223 ) ;
F_123 ( V_40 ) ;
return 0 ;
}
