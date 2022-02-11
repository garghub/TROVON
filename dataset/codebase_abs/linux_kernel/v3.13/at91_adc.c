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
void F_9 ( int V_1 , struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
if ( F_10 ( V_6 ) ) {
F_11 ( V_1 ) ;
F_12 ( V_6 -> V_16 , F_13 () ) ;
} else {
V_9 -> V_19 = F_4 ( V_9 , V_17 ) ;
V_9 -> V_20 = true ;
F_14 ( & V_9 -> V_21 ) ;
}
}
static int F_15 ( struct V_8 * V_9 )
{
unsigned int V_22 , V_23 , V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 , V_30 , V_31 ;
unsigned int V_32 = 1 ;
unsigned int V_33 = 1000 ;
struct V_5 * V_6 = F_16 ( V_9 ) ;
unsigned int V_34 = V_9 -> V_35 ;
unsigned int V_36 = ( 1 << V_34 ) - 1 ;
V_24 = F_4 ( V_9 , V_37 ) ;
V_30 = V_24 & V_36 ;
V_27 = ( V_30 << V_38 ) - V_30 ;
V_22 = ( V_24 >> 16 ) & V_36 ;
if ( V_22 == 0 ) {
F_17 ( & V_6 -> V_39 , L_1 ) ;
return - 1 ;
}
V_27 /= V_22 ;
V_24 = F_4 ( V_9 , V_40 ) ;
V_31 = V_24 & V_36 ;
V_28 = ( V_31 << V_38 ) - V_31 ;
V_23 = ( V_24 >> 16 ) & V_36 ;
if ( V_23 == 0 ) {
F_17 ( & V_6 -> V_39 , L_2 ) ;
return - 1 ;
}
V_28 /= V_23 ;
V_24 = F_4 ( V_9 , V_41 ) ;
V_25 = V_24 & V_36 ;
V_26 = ( V_24 >> 16 ) & V_36 ;
if ( V_25 != 0 )
V_29 = V_32 * ( V_27 * V_33 / 1024 ) * ( V_26 * V_33 / V_25 - V_33 )
/ V_33 ;
else
V_29 = V_9 -> V_42 ;
F_18 ( & V_6 -> V_39 , L_3 ,
V_30 , V_22 , V_31 , V_23 , V_25 , V_26 , V_29 ) ;
if ( V_29 < V_9 -> V_42 ) {
F_18 ( & V_6 -> V_39 , L_4 ,
V_27 , V_28 , V_29 / V_33 ) ;
F_19 ( V_9 -> V_43 , V_44 , V_27 ) ;
F_19 ( V_9 -> V_43 , V_45 , V_28 ) ;
F_19 ( V_9 -> V_43 , V_46 , V_29 ) ;
F_20 ( V_9 -> V_43 , V_47 , 1 ) ;
F_21 ( V_9 -> V_43 ) ;
} else {
F_18 ( & V_6 -> V_39 , L_5 ) ;
}
return 0 ;
}
static T_1 F_22 ( int V_1 , void * V_48 )
{
struct V_5 * V_6 = V_48 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_2 V_49 = F_4 ( V_9 , V_9 -> V_50 -> V_51 ) ;
const T_3 V_52 =
V_53 |
V_54 |
V_55 ;
if ( V_49 & V_9 -> V_50 -> V_56 )
F_9 ( V_1 , V_6 ) ;
if ( V_49 & V_57 ) {
F_23 ( V_9 , V_58 , V_57 ) ;
F_23 ( V_9 , V_59 , V_60 |
V_52 ) ;
F_23 ( V_9 , V_9 -> V_50 -> V_61 ,
V_62 |
F_24 ( V_9 -> V_63 ) ) ;
} else if ( V_49 & V_60 ) {
F_23 ( V_9 , V_9 -> V_50 -> V_61 , 0 ) ;
F_23 ( V_9 , V_58 , V_60 |
V_52 ) ;
F_23 ( V_9 , V_59 , V_57 ) ;
F_20 ( V_9 -> V_43 , V_47 , 0 ) ;
F_21 ( V_9 -> V_43 ) ;
} else if ( ( V_49 & V_52 ) == V_52 ) {
if ( V_49 & V_64 ) {
F_15 ( V_9 ) ;
} else {
F_4 ( V_9 , V_37 ) ;
F_4 ( V_9 , V_40 ) ;
F_4 ( V_9 , V_41 ) ;
}
}
return V_18 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_65 * V_66 , * V_15 ;
int V_67 , V_68 = 0 ;
unsigned long V_69 = 0 ;
if ( V_9 -> V_70 == V_71 )
V_69 = V_72 ;
else if ( V_9 -> V_70 == V_73 )
V_69 = V_74 ;
V_9 -> V_75 &= ~ V_69 ;
V_6 -> V_76 = F_26 ( & V_9 -> V_75 ,
V_9 -> V_76 ) + 1 ;
V_66 = F_27 ( & V_6 -> V_39 ,
( ( V_6 -> V_76 + 1 ) *
sizeof( struct V_65 ) ) ,
V_77 ) ;
if ( ! V_66 )
return - V_78 ;
F_28 (bit, &st->channels_mask, st->num_channels) {
struct V_65 * V_79 = V_66 + V_68 ;
V_79 -> type = V_80 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 = V_67 ;
V_79 -> V_83 = V_68 ;
V_79 -> V_84 . V_85 = 'u' ;
V_79 -> V_84 . V_86 = V_9 -> V_35 ;
V_79 -> V_84 . V_87 = 16 ;
V_79 -> V_88 = F_29 ( V_89 ) ;
V_79 -> V_90 = F_29 ( V_91 ) ;
V_68 ++ ;
}
V_15 = V_66 + V_68 ;
V_15 -> type = V_92 ;
V_15 -> V_82 = - 1 ;
V_15 -> V_83 = V_68 ;
V_15 -> V_84 . V_85 = 's' ;
V_15 -> V_84 . V_86 = 64 ;
V_15 -> V_84 . V_87 = 64 ;
V_6 -> V_93 = V_66 ;
return V_6 -> V_76 ;
}
static T_4 F_30 ( struct V_5 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
T_4 V_97 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_98 ; V_10 ++ ) {
char * V_99 = F_31 ( V_77 ,
L_6 ,
V_6 -> V_99 ,
V_6 -> V_100 ,
V_95 [ V_10 ] . V_99 ) ;
if ( ! V_99 )
return - V_78 ;
if ( strcmp ( V_96 , V_99 ) == 0 ) {
V_97 = V_95 [ V_10 ] . V_97 ;
F_32 ( V_99 ) ;
break;
}
F_32 ( V_99 ) ;
}
return V_97 ;
}
static int F_33 ( struct V_101 * V_16 , bool V_102 )
{
struct V_5 * V_6 = F_34 ( V_16 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_103 * V_14 = V_6 -> V_14 ;
struct V_104 * V_24 = V_9 -> V_50 ;
T_2 V_49 = F_4 ( V_9 , V_24 -> V_61 ) ;
T_4 V_97 ;
T_4 V_67 ;
V_97 = F_30 ( V_6 ,
V_9 -> V_105 ,
V_6 -> V_16 -> V_99 ) ;
if ( V_97 == 0 )
return - V_106 ;
if ( V_102 ) {
V_9 -> V_14 = F_35 ( V_6 -> V_107 , V_77 ) ;
if ( V_9 -> V_14 == NULL )
return - V_78 ;
F_23 ( V_9 , V_24 -> V_61 ,
V_49 | V_97 ) ;
F_28 (bit, buffer->scan_mask,
st->num_channels) {
struct V_65 const * V_79 = V_6 -> V_93 + V_67 ;
F_23 ( V_9 , V_108 ,
F_36 ( V_79 -> V_82 ) ) ;
}
F_23 ( V_9 , V_59 , V_24 -> V_56 ) ;
} else {
F_23 ( V_9 , V_58 , V_24 -> V_56 ) ;
F_23 ( V_9 , V_24 -> V_61 ,
V_49 & ~ V_97 ) ;
F_28 (bit, buffer->scan_mask,
st->num_channels) {
struct V_65 const * V_79 = V_6 -> V_93 + V_67 ;
F_23 ( V_9 , V_109 ,
F_36 ( V_79 -> V_82 ) ) ;
}
F_32 ( V_9 -> V_14 ) ;
}
return 0 ;
}
static struct V_101 * F_37 ( struct V_5 * V_6 ,
struct V_94 * V_110 )
{
struct V_101 * V_16 ;
int V_111 ;
V_16 = F_38 ( L_6 , V_6 -> V_99 ,
V_6 -> V_100 , V_110 -> V_99 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_39 . V_112 = V_6 -> V_39 . V_112 ;
F_39 ( V_16 , V_6 ) ;
V_16 -> V_113 = & V_114 ;
V_111 = F_40 ( V_16 ) ;
if ( V_111 )
return NULL ;
return V_16 ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 , V_111 ;
V_9 -> V_16 = F_27 ( & V_6 -> V_39 ,
V_9 -> V_98 * sizeof( * V_9 -> V_16 ) ,
V_77 ) ;
if ( V_9 -> V_16 == NULL ) {
V_111 = - V_78 ;
goto V_115;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_98 ; V_10 ++ ) {
if ( V_9 -> V_105 [ V_10 ] . V_116 && ! ( V_9 -> V_117 ) )
continue;
V_9 -> V_16 [ V_10 ] = F_37 ( V_6 ,
V_9 -> V_105 + V_10 ) ;
if ( V_9 -> V_16 [ V_10 ] == NULL ) {
F_17 ( & V_6 -> V_39 ,
L_7 , V_10 ) ;
V_111 = - V_78 ;
goto V_118;
}
}
return 0 ;
V_118:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- ) {
F_42 ( V_9 -> V_16 [ V_10 ] ) ;
F_43 ( V_9 -> V_16 [ V_10 ] ) ;
}
V_115:
return V_111 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_98 ; V_10 ++ ) {
F_42 ( V_9 -> V_16 [ V_10 ] ) ;
F_43 ( V_9 -> V_16 [ V_10 ] ) ;
}
}
static int F_45 ( struct V_5 * V_6 )
{
return F_46 ( V_6 , & V_119 ,
& F_1 , NULL ) ;
}
static void F_47 ( struct V_5 * V_6 )
{
F_48 ( V_6 ) ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_65 const * V_79 ,
int * V_120 , int * V_121 , long V_122 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
int V_111 ;
switch ( V_122 ) {
case V_91 :
F_50 ( & V_9 -> V_123 ) ;
F_23 ( V_9 , V_108 ,
F_36 ( V_79 -> V_82 ) ) ;
F_23 ( V_9 , V_59 , V_9 -> V_50 -> V_56 ) ;
F_23 ( V_9 , V_124 , V_125 ) ;
V_111 = F_51 ( V_9 -> V_21 ,
V_9 -> V_20 ,
F_52 ( 1000 ) ) ;
if ( V_111 == 0 )
V_111 = - V_126 ;
if ( V_111 < 0 ) {
F_53 ( & V_9 -> V_123 ) ;
return V_111 ;
}
* V_120 = V_9 -> V_19 ;
F_23 ( V_9 , V_109 ,
F_36 ( V_79 -> V_82 ) ) ;
F_23 ( V_9 , V_58 , V_9 -> V_50 -> V_56 ) ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = false ;
F_53 ( & V_9 -> V_123 ) ;
return V_127 ;
case V_89 :
* V_120 = V_9 -> V_128 ;
* V_121 = V_79 -> V_84 . V_86 ;
return V_129 ;
default:
break;
}
return - V_106 ;
}
static int F_54 ( struct V_8 * V_9 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_16 ( V_9 ) ;
struct V_132 * V_133 = V_131 -> V_39 . V_134 ;
int V_135 , V_10 , V_111 = 0 ;
char * V_136 , * V_137 ;
T_2 * V_138 ;
V_135 = F_55 ( V_133 , L_8 ) ;
if ( V_135 < 2 ) {
F_17 ( & V_6 -> V_39 , L_9
L_10 ) ;
return V_135 ;
}
V_138 = F_35 ( V_135 * sizeof( * V_138 ) , V_77 ) ;
if ( ! V_138 )
return - V_78 ;
if ( F_56 ( V_133 , L_11 , V_138 , V_135 ) ) {
F_17 ( & V_6 -> V_39 , L_12 ) ;
V_111 = - V_139 ;
goto V_111;
}
if ( F_57 ( V_133 , L_13 , ( const char * * ) & V_136 ) )
V_136 = L_14 ;
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ ) {
if ( F_58 ( V_133 , L_8 , V_10 , ( const char * * ) & V_137 ) )
continue;
if ( strcmp ( V_136 , V_137 ) )
continue;
V_9 -> V_35 = V_138 [ V_10 ] ;
if ( ! strcmp ( V_136 , L_15 ) )
V_9 -> V_140 = true ;
else
V_9 -> V_140 = false ;
F_59 ( & V_6 -> V_39 , L_16 , V_9 -> V_35 ) ;
goto V_111;
}
F_17 ( & V_6 -> V_39 , L_17 , V_136 ) ;
V_111:
F_32 ( V_138 ) ;
return V_111 ;
}
static T_2 F_60 ( T_4 V_141 , T_2 V_142 )
{
return F_61 ( ( V_141 * V_142 / 1000 ) - 1 , 8 ) / 8 ;
}
static T_2 F_62 ( T_4 V_141 , T_2 V_142 )
{
const int V_143 [] = {
0 , 8 , 16 , 24 ,
64 , 80 , 96 , 112 ,
512 , 576 , 640 , 704 ,
768 , 832 , 896 , 960
} ;
int V_10 , V_144 = F_63 ( V_143 ) ;
unsigned int V_145 ;
V_145 = V_141 * V_142 / 1000 ;
for ( V_10 = 0 ; V_10 < V_144 ; V_10 ++ )
if ( V_145 < V_143 [ V_10 ] )
break;
V_145 = V_10 ;
if ( V_145 == V_144 )
V_145 = V_144 - 1 ;
return V_145 ;
}
static int F_64 ( struct V_132 * V_146 ,
struct V_8 * V_9 , struct V_147 * V_39 )
{
int V_111 ;
T_2 V_148 ;
V_111 = F_65 ( V_146 , L_18 , & V_148 ) ;
if ( V_111 ) {
F_59 ( V_39 , L_19 ) ;
return 0 ;
}
switch ( V_148 ) {
case 4 :
case 5 :
V_9 -> V_70 = V_148 ;
break;
default:
F_17 ( V_39 , L_20 , V_148 ) ;
return - V_106 ;
}
V_148 = 0 ;
F_65 ( V_146 , L_21 , & V_148 ) ;
V_9 -> V_42 = V_148 ;
if ( V_9 -> V_42 ) {
return 0 ;
} else {
F_17 ( V_39 , L_22 ) ;
return - V_106 ;
}
}
static int F_66 ( struct V_8 * V_9 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_16 ( V_9 ) ;
struct V_132 * V_146 = V_131 -> V_39 . V_134 ;
struct V_132 * V_149 ;
int V_10 = 0 , V_111 ;
T_2 V_148 ;
if ( ! V_146 )
return - V_106 ;
V_9 -> V_150 = (struct V_151 * )
F_67 ( V_152 , & V_131 -> V_39 ) -> V_153 ;
V_9 -> V_117 = F_68 ( V_146 , L_23 ) ;
if ( F_65 ( V_146 , L_24 , & V_148 ) ) {
F_17 ( & V_6 -> V_39 , L_25 ) ;
V_111 = - V_106 ;
goto V_115;
}
V_9 -> V_75 = V_148 ;
V_9 -> V_154 = F_68 ( V_146 , L_26 ) ;
if ( F_65 ( V_146 , L_27 , & V_148 ) ) {
F_17 ( & V_6 -> V_39 , L_28 ) ;
V_111 = - V_106 ;
goto V_115;
}
V_9 -> V_141 = V_148 ;
V_148 = 0 ;
F_65 ( V_146 , L_29 , & V_148 ) ;
V_9 -> V_155 = V_148 ;
if ( F_65 ( V_146 , L_30 , & V_148 ) ) {
F_17 ( & V_6 -> V_39 , L_31 ) ;
V_111 = - V_106 ;
goto V_115;
}
V_9 -> V_128 = V_148 ;
V_111 = F_54 ( V_9 , V_131 ) ;
if ( V_111 )
goto V_115;
V_9 -> V_50 = & V_9 -> V_150 -> V_50 ;
V_9 -> V_76 = V_9 -> V_150 -> V_76 ;
V_9 -> V_98 = F_69 ( V_146 ) ;
V_9 -> V_105 = F_27 ( & V_6 -> V_39 , V_9 -> V_98 *
sizeof( struct V_94 ) ,
V_77 ) ;
if ( ! V_9 -> V_105 ) {
F_17 ( & V_6 -> V_39 , L_32 ) ;
V_111 = - V_78 ;
goto V_115;
}
F_70 (node, trig_node) {
struct V_94 * V_16 = V_9 -> V_105 + V_10 ;
const char * V_99 ;
if ( F_57 ( V_149 , L_33 , & V_99 ) ) {
F_17 ( & V_6 -> V_39 , L_34 ) ;
V_111 = - V_106 ;
goto V_115;
}
V_16 -> V_99 = V_99 ;
if ( F_65 ( V_149 , L_35 , & V_148 ) ) {
F_17 ( & V_6 -> V_39 , L_36 ) ;
V_111 = - V_106 ;
goto V_115;
}
V_16 -> V_97 = V_148 ;
V_16 -> V_116 = F_68 ( V_149 , L_37 ) ;
V_10 ++ ;
}
if ( V_9 -> V_150 -> V_156 )
return F_64 ( V_146 , V_9 , & V_6 -> V_39 ) ;
else
F_59 ( & V_6 -> V_39 , L_38 ) ;
return 0 ;
V_115:
return V_111 ;
}
static int F_71 ( struct V_8 * V_9 ,
struct V_130 * V_131 )
{
struct V_157 * V_158 = V_131 -> V_39 . V_159 ;
if ( ! V_158 )
return - V_106 ;
V_9 -> V_117 = V_158 -> V_160 ;
V_9 -> V_128 = V_158 -> V_161 ;
V_9 -> V_75 = V_158 -> V_162 ;
V_9 -> V_76 = V_158 -> V_76 ;
V_9 -> V_141 = V_158 -> V_141 ;
V_9 -> V_98 = V_158 -> V_98 ;
V_9 -> V_105 = V_158 -> V_105 ;
V_9 -> V_50 = V_158 -> V_50 ;
return 0 ;
}
static int F_72 ( struct V_163 * V_39 )
{
struct V_8 * V_9 = F_73 ( V_39 ) ;
F_23 ( V_9 , V_59 , V_57 ) ;
return 0 ;
}
static void F_74 ( struct V_163 * V_39 )
{
struct V_8 * V_9 = F_73 ( V_39 ) ;
F_23 ( V_9 , V_58 , V_57 ) ;
}
static int F_75 ( struct V_8 * V_9 , T_2 V_142 )
{
T_2 V_24 = 0 , V_164 ;
int V_10 = 0 ;
if ( V_9 -> V_70 == V_71 )
V_24 = V_165 ;
else
V_24 = V_166 ;
V_164 = F_61 ( V_167 * V_142 / 1000 , 1 ) ;
while ( V_164 >> ++ V_10 )
;
if ( abs ( V_164 - ( 1 << V_10 ) ) < abs ( V_164 - ( 1 << ( V_10 - 1 ) ) ) )
V_164 = V_10 ;
else
V_164 = V_10 - 1 ;
if ( V_9 -> V_150 -> V_168 ) {
V_24 |= F_76 ( V_9 -> V_150 -> V_169 )
& V_170 ;
V_24 |= F_77 ( V_164 ) & V_171 ;
V_24 |= V_172 ;
V_24 |= V_173 ;
V_24 |= 0x03 << 8 ;
F_23 ( V_9 , V_174 , V_24 ) ;
} else {
}
F_23 ( V_9 , V_175 , V_9 -> V_150 -> V_176
& V_177 ) ;
V_9 -> V_63 = F_61 ( ( V_178 *
V_142 / 1000 ) - 1 , 1 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_9 ,
struct V_130 * V_131 )
{
struct V_163 * V_179 ;
struct V_5 * V_6 = F_16 ( V_9 ) ;
int V_111 ;
V_179 = F_79 () ;
if ( ! V_179 ) {
F_17 ( & V_6 -> V_39 , L_39 ) ;
return - V_78 ;
}
V_179 -> V_99 = V_180 ;
V_179 -> V_100 . V_181 = V_182 ;
V_179 -> V_39 . V_112 = & V_131 -> V_39 ;
V_179 -> V_183 = F_72 ;
V_179 -> V_184 = F_74 ;
F_80 ( V_185 , V_179 -> V_186 ) ;
F_80 ( V_187 , V_179 -> V_186 ) ;
F_80 ( V_47 , V_179 -> V_188 ) ;
F_81 ( V_179 , V_44 , 0 , ( 1 << V_38 ) - 1 , 0 , 0 ) ;
F_81 ( V_179 , V_45 , 0 , ( 1 << V_38 ) - 1 , 0 , 0 ) ;
F_81 ( V_179 , V_46 , 0 , 0xffffff , 0 , 0 ) ;
V_9 -> V_43 = V_179 ;
F_82 ( V_179 , V_9 ) ;
V_111 = F_83 ( V_179 ) ;
if ( V_111 )
F_84 ( V_9 -> V_43 ) ;
return V_111 ;
}
static void F_85 ( struct V_8 * V_9 )
{
F_86 ( V_9 -> V_43 ) ;
}
static int F_87 ( struct V_130 * V_131 )
{
unsigned int V_189 , V_190 , V_145 , V_191 , V_142 , V_192 ;
int V_111 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_193 * V_35 ;
T_2 V_24 ;
V_6 = F_88 ( & V_131 -> V_39 , sizeof( struct V_8 ) ) ;
if ( ! V_6 )
return - V_78 ;
V_9 = F_2 ( V_6 ) ;
if ( V_131 -> V_39 . V_134 )
V_111 = F_66 ( V_9 , V_131 ) ;
else
V_111 = F_71 ( V_9 , V_131 ) ;
if ( V_111 ) {
F_17 ( & V_131 -> V_39 , L_40 ) ;
return - V_106 ;
}
F_89 ( V_131 , V_6 ) ;
V_6 -> V_39 . V_112 = & V_131 -> V_39 ;
V_6 -> V_99 = F_90 ( & V_131 -> V_39 ) ;
V_6 -> V_194 = V_195 ;
V_6 -> V_196 = & V_197 ;
V_9 -> V_1 = F_91 ( V_131 , 0 ) ;
if ( V_9 -> V_1 < 0 ) {
F_17 ( & V_131 -> V_39 , L_41 ) ;
return - V_139 ;
}
V_35 = F_92 ( V_131 , V_198 , 0 ) ;
V_9 -> V_199 = F_93 ( & V_131 -> V_39 , V_35 ) ;
if ( F_94 ( V_9 -> V_199 ) ) {
return F_95 ( V_9 -> V_199 ) ;
}
F_23 ( V_9 , V_124 , V_200 ) ;
F_23 ( V_9 , V_58 , 0xFFFFFFFF ) ;
V_111 = F_96 ( V_9 -> V_1 ,
F_22 ,
0 ,
V_131 -> V_39 . V_201 -> V_99 ,
V_6 ) ;
if ( V_111 ) {
F_17 ( & V_131 -> V_39 , L_42 ) ;
return V_111 ;
}
V_9 -> V_202 = F_97 ( & V_131 -> V_39 , L_43 ) ;
if ( F_94 ( V_9 -> V_202 ) ) {
F_17 ( & V_131 -> V_39 , L_44 ) ;
V_111 = F_95 ( V_9 -> V_202 ) ;
goto V_203;
}
V_111 = F_98 ( V_9 -> V_202 ) ;
if ( V_111 ) {
F_17 ( & V_131 -> V_39 ,
L_45 ) ;
goto V_203;
}
V_9 -> V_191 = F_97 ( & V_131 -> V_39 , L_46 ) ;
if ( F_94 ( V_9 -> V_191 ) ) {
F_17 ( & V_131 -> V_39 , L_47 ) ;
V_111 = F_95 ( V_9 -> V_191 ) ;
goto V_204;
}
V_111 = F_98 ( V_9 -> V_191 ) ;
if ( V_111 ) {
F_17 ( & V_131 -> V_39 ,
L_48 ) ;
goto V_204;
}
V_190 = F_99 ( V_9 -> V_202 ) ;
V_191 = F_99 ( V_9 -> V_191 ) ;
V_142 = V_191 / 1000 ;
F_18 ( & V_131 -> V_39 , L_49 ,
V_190 , V_191 ) ;
V_189 = ( V_190 / ( 2 * V_191 ) ) - 1 ;
if ( ! V_9 -> V_141 ) {
F_17 ( & V_131 -> V_39 , L_50 ) ;
V_111 = - V_106 ;
goto V_205;
}
V_145 = (* V_9 -> V_150 -> V_206 )( V_9 -> V_141 , V_142 ) ;
V_192 = F_61 ( ( V_9 -> V_155 * V_142 /
1000 ) - 1 , 1 ) ;
V_24 = F_100 ( V_189 ) & V_9 -> V_50 -> V_207 ;
V_24 |= F_101 ( V_145 ) & V_9 -> V_50 -> V_208 ;
if ( V_9 -> V_140 )
V_24 |= V_209 ;
if ( V_9 -> V_154 )
V_24 |= V_210 ;
V_24 |= F_102 ( V_192 ) & V_211 ;
F_23 ( V_9 , V_212 , V_24 ) ;
V_111 = F_25 ( V_6 ) ;
if ( V_111 < 0 ) {
F_17 ( & V_131 -> V_39 , L_51 ) ;
goto V_205;
}
F_103 ( & V_9 -> V_21 ) ;
F_104 ( & V_9 -> V_123 ) ;
if ( ! V_9 -> V_70 ) {
V_111 = F_45 ( V_6 ) ;
if ( V_111 < 0 ) {
F_17 ( & V_131 -> V_39 , L_52 ) ;
goto V_205;
}
V_111 = F_41 ( V_6 ) ;
if ( V_111 < 0 ) {
F_17 ( & V_131 -> V_39 , L_53 ) ;
F_47 ( V_6 ) ;
goto V_205;
}
} else {
if ( ! V_9 -> V_150 -> V_168 ) {
F_17 ( & V_131 -> V_39 , L_54 ) ;
V_111 = - V_139 ;
goto V_205;
}
V_111 = F_78 ( V_9 , V_131 ) ;
if ( V_111 )
goto V_205;
F_75 ( V_9 , V_142 ) ;
}
V_111 = F_105 ( V_6 ) ;
if ( V_111 < 0 ) {
F_17 ( & V_131 -> V_39 , L_55 ) ;
goto V_213;
}
return 0 ;
V_213:
if ( ! V_9 -> V_70 ) {
F_44 ( V_6 ) ;
F_47 ( V_6 ) ;
} else {
F_85 ( V_9 ) ;
}
V_205:
F_106 ( V_9 -> V_191 ) ;
V_204:
F_106 ( V_9 -> V_202 ) ;
V_203:
F_107 ( V_9 -> V_1 , V_6 ) ;
return V_111 ;
}
static int F_108 ( struct V_130 * V_131 )
{
struct V_5 * V_6 = F_109 ( V_131 ) ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_110 ( V_6 ) ;
if ( ! V_9 -> V_70 ) {
F_44 ( V_6 ) ;
F_47 ( V_6 ) ;
} else {
F_85 ( V_9 ) ;
}
F_106 ( V_9 -> V_191 ) ;
F_106 ( V_9 -> V_202 ) ;
F_107 ( V_9 -> V_1 , V_6 ) ;
return 0 ;
}
