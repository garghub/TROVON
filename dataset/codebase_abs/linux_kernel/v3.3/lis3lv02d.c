static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
if ( ! V_4 ) {
int V_1 = * ( int * ) V_3 -> V_5 ;
if ( V_1 < 0 )
V_1 = - V_1 ;
if ( ! V_1 || V_1 > 3 )
return - V_6 ;
}
return V_4 ;
}
static T_1 F_3 ( struct V_7 * V_8 , int V_9 )
{
T_2 V_10 ;
if ( V_8 -> V_11 ( V_8 , V_9 , & V_10 ) < 0 )
return 0 ;
return V_10 ;
}
static T_1 F_4 ( struct V_7 * V_8 , int V_9 )
{
T_3 V_10 , V_12 ;
V_8 -> V_11 ( V_8 , V_9 - 1 , & V_10 ) ;
V_8 -> V_11 ( V_8 , V_9 , & V_12 ) ;
return ( T_1 ) ( ( V_12 << 8 ) | V_10 ) ;
}
static inline int F_5 ( T_2 V_13 , int V_14 [ 3 ] )
{
if ( V_13 > 0 )
return V_14 [ V_13 - 1 ] ;
else
return - V_14 [ - V_13 - 1 ] ;
}
static void F_6 ( struct V_7 * V_8 , int * V_15 , int * V_16 , int * V_17 )
{
int V_18 [ 3 ] ;
int V_19 ;
if ( V_8 -> V_20 ) {
if ( V_8 -> V_21 == V_22 ) {
T_4 V_23 [ 3 ] ;
V_8 -> V_20 ( V_8 , V_24 , 6 , ( T_3 * ) V_23 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_18 [ V_19 ] = ( T_1 ) F_7 ( V_23 [ V_19 ] ) ;
} else {
T_3 V_23 [ 5 ] ;
V_8 -> V_20 ( V_8 , V_25 , 5 , V_23 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_18 [ V_19 ] = ( T_2 ) V_23 [ V_19 * 2 ] ;
}
} else {
V_18 [ 0 ] = V_8 -> V_26 ( V_8 , V_25 ) ;
V_18 [ 1 ] = V_8 -> V_26 ( V_8 , V_27 ) ;
V_18 [ 2 ] = V_8 -> V_26 ( V_8 , V_28 ) ;
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_18 [ V_19 ] = ( V_18 [ V_19 ] * V_8 -> V_29 ) / V_30 ;
* V_15 = F_5 ( V_8 -> V_31 . V_15 , V_18 ) ;
* V_16 = F_5 ( V_8 -> V_31 . V_16 , V_18 ) ;
* V_17 = F_5 ( V_8 -> V_31 . V_17 , V_18 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
T_3 V_32 ;
int V_33 ;
V_8 -> V_11 ( V_8 , V_34 , & V_32 ) ;
V_32 &= V_8 -> V_35 ;
V_33 = F_9 ( V_8 -> V_35 ) - 1 ;
return V_8 -> V_36 [ ( V_32 >> V_33 ) ] ;
}
static int F_10 ( struct V_7 * V_8 )
{
int div = F_8 ( V_8 ) ;
if ( F_11 ( div == 0 , L_1 ) )
return - V_37 ;
F_12 ( V_8 -> V_38 / div ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , int V_39 )
{
T_3 V_32 ;
int V_19 , V_40 , V_33 ;
if ( ! V_39 )
return - V_6 ;
V_8 -> V_11 ( V_8 , V_34 , & V_32 ) ;
V_32 &= ~ V_8 -> V_35 ;
V_40 = 1 << F_14 ( V_8 -> V_35 ) ;
V_33 = F_9 ( V_8 -> V_35 ) - 1 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ )
if ( V_8 -> V_36 [ V_19 ] == V_39 ) {
V_8 -> V_41 ( V_8 , V_34 ,
V_32 | ( V_19 << V_33 ) ) ;
return 0 ;
}
return - V_6 ;
}
static int F_15 ( struct V_7 * V_8 , T_1 V_42 [ 3 ] )
{
T_3 V_43 , V_9 ;
T_1 V_15 , V_16 , V_17 ;
T_3 V_44 ;
int V_4 ;
T_3 V_45 ;
unsigned char V_46 ;
F_16 ( & V_8 -> V_47 ) ;
V_46 = V_8 -> V_46 ;
if ( V_8 -> V_21 == V_48 ) {
V_8 -> V_49 [ V_50 ] = 0 ;
V_8 -> V_49 [ V_51 ] = 0 ;
F_17 ( & V_8 -> V_52 ) ;
V_8 -> V_46 = V_53 | V_54 ;
V_8 -> V_11 ( V_8 , V_55 , & V_45 ) ;
V_8 -> V_41 ( V_8 , V_55 , ( V_45 &
~ ( V_56 | V_57 ) ) |
( V_53 | V_54 ) ) ;
}
if ( V_8 -> V_21 == V_58 ) {
V_43 = V_59 ;
V_44 = V_60 ;
} else {
V_43 = V_34 ;
if ( V_8 -> V_21 == V_22 )
V_44 = V_61 ;
else
V_44 = V_62 ;
}
V_8 -> V_11 ( V_8 , V_43 , & V_9 ) ;
V_8 -> V_41 ( V_8 , V_43 , ( V_9 | V_44 ) ) ;
V_4 = F_10 ( V_8 ) ;
if ( V_4 )
goto V_63;
V_15 = V_8 -> V_26 ( V_8 , V_25 ) ;
V_16 = V_8 -> V_26 ( V_8 , V_27 ) ;
V_17 = V_8 -> V_26 ( V_8 , V_28 ) ;
V_8 -> V_41 ( V_8 , V_43 , V_9 ) ;
V_4 = F_10 ( V_8 ) ;
if ( V_4 )
goto V_63;
V_42 [ 0 ] = V_15 - V_8 -> V_26 ( V_8 , V_25 ) ;
V_42 [ 1 ] = V_16 - V_8 -> V_26 ( V_8 , V_27 ) ;
V_42 [ 2 ] = V_17 - V_8 -> V_26 ( V_8 , V_28 ) ;
V_4 = 0 ;
if ( V_8 -> V_21 == V_48 ) {
F_18 ( & V_8 -> V_52 ) ;
V_8 -> V_41 ( V_8 , V_55 , V_45 ) ;
V_8 -> V_46 = V_46 ;
if ( ( V_46 & V_56 ) &&
V_8 -> V_49 [ V_50 ] < 2 ) {
V_4 = V_64 ;
goto V_63;
}
if ( ( V_46 & V_57 ) &&
V_8 -> V_49 [ V_51 ] < 2 ) {
V_4 = V_64 ;
goto V_63;
}
}
if ( V_8 -> V_65 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( ( V_42 [ V_19 ] < V_8 -> V_65 -> V_66 [ V_19 ] ) ||
( V_42 [ V_19 ] > V_8 -> V_65 -> V_67 [ V_19 ] ) ) {
V_4 = V_68 ;
goto V_63;
}
}
}
V_63:
F_19 ( & V_8 -> V_47 ) ;
return V_4 ;
}
static inline void F_20 ( struct V_7 * V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_69 ; V_19 ++ )
V_8 -> V_11 ( V_8 , V_8 -> V_70 [ V_19 ] , & V_8 -> V_71 [ V_19 ] ) ;
V_8 -> V_72 = true ;
}
static inline void F_21 ( struct V_7 * V_8 )
{
int V_19 ;
if ( V_8 -> V_72 )
for ( V_19 = 0 ; V_19 < V_8 -> V_69 ; V_19 ++ )
V_8 -> V_41 ( V_8 , V_8 -> V_70 [ V_19 ] , V_8 -> V_71 [ V_19 ] ) ;
}
void F_22 ( struct V_7 * V_8 )
{
if ( V_8 -> V_73 )
F_20 ( V_8 ) ;
V_8 -> V_41 ( V_8 , V_34 , 0x00 ) ;
if ( V_8 -> V_73 )
V_8 -> V_73 ( V_8 , V_74 ) ;
}
int F_23 ( struct V_7 * V_8 )
{
int V_75 ;
T_3 V_9 ;
V_8 -> V_76 ( V_8 ) ;
if ( V_8 -> V_65 ) {
V_8 -> V_11 ( V_8 , V_77 , & V_9 ) ;
if ( V_8 -> V_21 == V_22 )
V_9 |= V_78 | V_79 ;
else
V_9 |= V_80 ;
V_8 -> V_41 ( V_8 , V_77 , V_9 ) ;
}
V_75 = F_10 ( V_8 ) ;
if ( V_75 )
return V_75 ;
if ( V_8 -> V_73 )
F_21 ( V_8 ) ;
return 0 ;
}
static void F_24 ( struct V_81 * V_82 )
{
struct V_7 * V_8 = V_82 -> V_83 ;
int V_15 , V_16 , V_17 ;
F_16 ( & V_8 -> V_47 ) ;
F_6 ( V_8 , & V_15 , & V_16 , & V_17 ) ;
F_25 ( V_82 -> V_84 , V_85 , V_15 ) ;
F_25 ( V_82 -> V_84 , V_86 , V_16 ) ;
F_25 ( V_82 -> V_84 , V_87 , V_17 ) ;
F_26 ( V_82 -> V_84 ) ;
F_19 ( & V_8 -> V_47 ) ;
}
static void F_27 ( struct V_81 * V_82 )
{
struct V_7 * V_8 = V_82 -> V_83 ;
if ( V_8 -> V_88 )
F_28 ( V_8 -> V_88 ) ;
if ( V_8 -> V_65 && V_8 -> V_21 == V_48 && V_8 -> V_89 )
F_29 ( & V_8 -> V_52 , 1 ) ;
F_24 ( V_82 ) ;
}
static void F_30 ( struct V_81 * V_82 )
{
struct V_7 * V_8 = V_82 -> V_83 ;
F_29 ( & V_8 -> V_52 , 0 ) ;
if ( V_8 -> V_88 )
F_31 ( V_8 -> V_88 ) ;
}
static T_5 F_32 ( int V_90 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
if ( ! F_33 ( 0 , & V_8 -> V_91 ) )
goto V_92;
F_17 ( & V_8 -> V_93 ) ;
F_34 ( & V_8 -> V_94 ) ;
F_35 ( & V_8 -> V_95 , V_96 , V_97 ) ;
V_92:
if ( F_36 ( & V_8 -> V_52 ) )
return V_98 ;
return V_99 ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = V_8 -> V_89 -> V_84 ;
T_3 V_102 ;
F_16 ( & V_8 -> V_47 ) ;
V_8 -> V_11 ( V_8 , V_103 , & V_102 ) ;
if ( V_102 & V_104 ) {
F_38 ( V_101 , V_8 -> V_105 [ 0 ] , 1 ) ;
F_38 ( V_101 , V_8 -> V_105 [ 0 ] , 0 ) ;
}
if ( V_102 & V_106 ) {
F_38 ( V_101 , V_8 -> V_105 [ 1 ] , 1 ) ;
F_38 ( V_101 , V_8 -> V_105 [ 1 ] , 0 ) ;
}
if ( V_102 & V_107 ) {
F_38 ( V_101 , V_8 -> V_105 [ 2 ] , 1 ) ;
F_38 ( V_101 , V_8 -> V_105 [ 2 ] , 0 ) ;
}
F_26 ( V_101 ) ;
F_19 ( & V_8 -> V_47 ) ;
}
static inline void F_39 ( struct V_7 * V_8 , int V_108 )
{
int V_109 ;
F_6 ( V_8 , & V_109 , & V_109 , & V_109 ) ;
V_8 -> V_49 [ V_108 ] ++ ;
}
static T_5 F_40 ( int V_90 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
T_3 V_46 = V_8 -> V_46 & V_56 ;
if ( V_46 == V_110 )
F_37 ( V_8 ) ;
else if ( F_41 ( V_46 == V_53 ) )
F_39 ( V_8 , V_50 ) ;
else
F_24 ( V_8 -> V_89 ) ;
return V_99 ;
}
static T_5 F_42 ( int V_90 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
T_3 V_46 = V_8 -> V_46 & V_57 ;
if ( V_46 == V_111 )
F_37 ( V_8 ) ;
else if ( F_41 ( V_46 == V_54 ) )
F_39 ( V_8 , V_51 ) ;
else
F_24 ( V_8 -> V_89 ) ;
return V_99 ;
}
static int F_43 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
struct V_7 * V_8 = F_44 ( V_113 -> V_114 ,
struct V_7 , V_115 ) ;
if ( F_45 ( 0 , & V_8 -> V_91 ) )
return - V_116 ;
if ( V_8 -> V_88 )
F_28 ( V_8 -> V_88 ) ;
F_29 ( & V_8 -> V_93 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
struct V_7 * V_8 = F_44 ( V_113 -> V_114 ,
struct V_7 , V_115 ) ;
F_47 ( - 1 , V_113 , 0 , & V_8 -> V_95 ) ;
F_48 ( 0 , & V_8 -> V_91 ) ;
if ( V_8 -> V_88 )
F_31 ( V_8 -> V_88 ) ;
return 0 ;
}
static T_6 F_49 ( struct V_113 * V_113 , char T_7 * V_117 ,
T_8 V_93 , T_9 * V_118 )
{
struct V_7 * V_8 = F_44 ( V_113 -> V_114 ,
struct V_7 , V_115 ) ;
F_50 ( V_119 , V_120 ) ;
T_10 V_23 ;
unsigned char V_121 ;
T_6 V_122 = 1 ;
if ( V_93 < 1 )
return - V_6 ;
F_51 ( & V_8 -> V_94 , & V_119 ) ;
while ( true ) {
F_52 ( V_123 ) ;
V_23 = F_53 ( & V_8 -> V_93 , 0 ) ;
if ( V_23 )
break;
if ( V_113 -> V_124 & V_125 ) {
V_122 = - V_126 ;
goto V_92;
}
if ( F_54 ( V_120 ) ) {
V_122 = - V_127 ;
goto V_92;
}
F_55 () ;
}
if ( V_23 < 255 )
V_121 = V_23 ;
else
V_121 = 255 ;
F_52 ( V_128 ) ;
if ( F_56 ( V_117 , & V_121 , sizeof( V_121 ) ) )
V_122 = - V_129 ;
V_92:
F_57 ( V_128 ) ;
F_58 ( & V_8 -> V_94 , & V_119 ) ;
return V_122 ;
}
static unsigned int F_59 ( struct V_113 * V_113 , T_11 * V_119 )
{
struct V_7 * V_8 = F_44 ( V_113 -> V_114 ,
struct V_7 , V_115 ) ;
F_60 ( V_113 , & V_8 -> V_94 , V_119 ) ;
if ( F_36 ( & V_8 -> V_93 ) )
return V_130 | V_131 ;
return 0 ;
}
static int F_61 ( int V_132 , struct V_113 * V_113 , int V_133 )
{
struct V_7 * V_8 = F_44 ( V_113 -> V_114 ,
struct V_7 , V_115 ) ;
return F_47 ( V_132 , V_113 , V_133 , & V_8 -> V_95 ) ;
}
int F_62 ( struct V_7 * V_8 )
{
struct V_100 * V_100 ;
int V_75 ;
int V_134 , V_135 , V_136 ;
int V_137 [] = { V_138 , V_139 , V_140 } ;
if ( V_8 -> V_89 )
return - V_6 ;
V_8 -> V_89 = F_63 () ;
if ( ! V_8 -> V_89 )
return - V_141 ;
V_8 -> V_89 -> V_142 = F_24 ;
V_8 -> V_89 -> V_143 = F_27 ;
V_8 -> V_89 -> V_144 = F_30 ;
V_8 -> V_89 -> V_145 = V_146 ;
V_8 -> V_89 -> V_147 = V_148 ;
V_8 -> V_89 -> V_149 = V_150 ;
V_8 -> V_89 -> V_83 = V_8 ;
V_100 = V_8 -> V_89 -> V_84 ;
V_100 -> V_151 = L_2 ;
V_100 -> V_152 = V_153 L_3 ;
V_100 -> V_154 . V_155 = V_156 ;
V_100 -> V_154 . V_157 = 0 ;
V_100 -> V_101 . V_158 = & V_8 -> V_159 -> V_101 ;
F_64 ( V_160 , V_100 -> V_161 ) ;
V_134 = ( V_8 -> V_162 * V_8 -> V_29 ) / V_30 ;
if ( V_8 -> V_21 == V_22 ) {
V_135 = V_163 ;
V_136 = V_164 ;
} else {
V_135 = V_165 ;
V_136 = V_166 ;
}
V_135 = ( V_135 * V_8 -> V_29 ) / V_30 ;
V_136 = ( V_136 * V_8 -> V_29 ) / V_30 ;
F_65 ( V_100 , V_85 , - V_134 , V_134 , V_135 , V_136 ) ;
F_65 ( V_100 , V_86 , - V_134 , V_134 , V_135 , V_136 ) ;
F_65 ( V_100 , V_87 , - V_134 , V_134 , V_135 , V_136 ) ;
V_8 -> V_105 [ 0 ] = F_5 ( abs ( V_8 -> V_31 . V_15 ) , V_137 ) ;
V_8 -> V_105 [ 1 ] = F_5 ( abs ( V_8 -> V_31 . V_16 ) , V_137 ) ;
V_8 -> V_105 [ 2 ] = F_5 ( abs ( V_8 -> V_31 . V_17 ) , V_137 ) ;
V_75 = F_66 ( V_8 -> V_89 ) ;
if ( V_75 ) {
F_67 ( V_8 -> V_89 ) ;
V_8 -> V_89 = NULL ;
}
return V_75 ;
}
void F_68 ( struct V_7 * V_8 )
{
if ( V_8 -> V_90 )
F_69 ( V_8 -> V_90 , V_8 ) ;
if ( V_8 -> V_65 && V_8 -> V_65 -> V_167 )
F_69 ( V_8 -> V_65 -> V_167 , V_8 ) ;
if ( ! V_8 -> V_89 )
return;
if ( V_8 -> V_90 )
F_70 ( & V_8 -> V_115 ) ;
F_71 ( V_8 -> V_89 ) ;
F_67 ( V_8 -> V_89 ) ;
V_8 -> V_89 = NULL ;
}
static void F_72 ( struct V_7 * V_8 )
{
if ( V_8 -> V_88 ) {
F_28 ( V_8 -> V_88 ) ;
F_73 ( V_8 -> V_88 ) ;
F_74 ( V_8 -> V_88 , V_168 ) ;
}
}
static T_6 F_75 ( struct V_169 * V_101 ,
struct V_170 * V_171 , char * V_117 )
{
struct V_7 * V_8 = F_76 ( V_101 ) ;
T_1 V_172 [ 3 ] ;
static const char V_173 [] = L_4 ;
static const char V_63 [] = L_5 ;
static const char V_90 [] = L_6 ;
const char * V_174 ;
F_72 ( V_8 ) ;
switch ( F_15 ( V_8 , V_172 ) ) {
case V_68 :
V_174 = V_63 ;
break;
case V_64 :
V_174 = V_90 ;
break;
case V_175 :
default:
V_174 = V_173 ;
break;
}
return sprintf ( V_117 , L_7 , V_174 ,
V_172 [ 0 ] , V_172 [ 1 ] , V_172 [ 2 ] ) ;
}
static T_6 F_77 ( struct V_169 * V_101 ,
struct V_170 * V_171 , char * V_117 )
{
struct V_7 * V_8 = F_76 ( V_101 ) ;
int V_15 , V_16 , V_17 ;
F_72 ( V_8 ) ;
F_16 ( & V_8 -> V_47 ) ;
F_6 ( V_8 , & V_15 , & V_16 , & V_17 ) ;
F_19 ( & V_8 -> V_47 ) ;
return sprintf ( V_117 , L_8 , V_15 , V_16 , V_17 ) ;
}
static T_6 F_78 ( struct V_169 * V_101 ,
struct V_170 * V_171 , char * V_117 )
{
struct V_7 * V_8 = F_76 ( V_101 ) ;
F_72 ( V_8 ) ;
return sprintf ( V_117 , L_9 , F_8 ( V_8 ) ) ;
}
static T_6 F_79 ( struct V_169 * V_101 ,
struct V_170 * V_171 , const char * V_117 ,
T_8 V_93 )
{
struct V_7 * V_8 = F_76 ( V_101 ) ;
unsigned long V_39 ;
if ( F_80 ( V_117 , 0 , & V_39 ) )
return - V_6 ;
F_72 ( V_8 ) ;
if ( F_13 ( V_8 , V_39 ) )
return - V_6 ;
return V_93 ;
}
static int F_81 ( struct V_7 * V_8 )
{
V_8 -> V_159 = F_82 ( V_153 , - 1 , NULL , 0 ) ;
if ( F_83 ( V_8 -> V_159 ) )
return F_84 ( V_8 -> V_159 ) ;
F_85 ( V_8 -> V_159 , V_8 ) ;
return F_86 ( & V_8 -> V_159 -> V_101 . V_176 , & V_177 ) ;
}
int F_87 ( struct V_7 * V_8 )
{
F_88 ( & V_8 -> V_159 -> V_101 . V_176 , & V_177 ) ;
F_89 ( V_8 -> V_159 ) ;
if ( V_8 -> V_88 ) {
F_90 ( V_8 -> V_88 ) ;
if ( ! F_91 ( V_8 -> V_88 ) )
F_22 ( V_8 ) ;
F_92 ( V_8 -> V_88 ) ;
F_93 ( V_8 -> V_88 ) ;
}
F_94 ( V_8 -> V_71 ) ;
return 0 ;
}
static void F_95 ( struct V_7 * V_8 ,
struct V_178 * V_179 )
{
int V_75 ;
int V_180 = V_179 -> V_181 ;
if ( V_179 -> V_182 ) {
V_8 -> V_41 ( V_8 , V_183 , V_179 -> V_182 ) ;
V_8 -> V_41 ( V_8 , V_184 , V_179 -> V_185 ) ;
V_8 -> V_41 ( V_8 , V_186 , V_179 -> V_187 ) ;
V_8 -> V_41 ( V_8 , V_188 , V_179 -> V_189 ) ;
V_8 -> V_41 ( V_8 , V_190 , V_179 -> V_191 & 0xf ) ;
V_8 -> V_41 ( V_8 , V_192 ,
( V_179 -> V_193 & 0xf ) |
( V_179 -> V_194 << 4 ) ) ;
if ( V_8 -> V_89 ) {
struct V_100 * V_100 = V_8 -> V_89 -> V_84 ;
F_96 ( V_100 , V_195 , V_138 ) ;
F_96 ( V_100 , V_195 , V_139 ) ;
F_96 ( V_100 , V_195 , V_140 ) ;
}
}
if ( V_179 -> V_196 ) {
V_8 -> V_41 ( V_8 , V_197 , V_179 -> V_196 ) ;
V_8 -> V_41 ( V_8 , V_198 , V_179 -> V_199 & 0x7f ) ;
V_8 -> V_41 ( V_8 , V_200 , V_179 -> V_201 + 1 ) ;
V_180 ^= V_202 ;
}
if ( V_179 -> V_203 ) {
V_8 -> V_41 ( V_8 , V_204 , V_179 -> V_203 ) ;
V_8 -> V_41 ( V_8 , V_205 , V_179 -> V_206 & 0x7f ) ;
V_8 -> V_41 ( V_8 , V_207 , V_179 -> V_208 + 1 ) ;
V_180 ^= V_209 ;
}
V_8 -> V_41 ( V_8 , V_77 , V_180 ) ;
if ( V_179 -> V_167 ) {
V_75 = F_97 ( V_179 -> V_167 ,
NULL ,
F_42 ,
V_210 | V_211 |
( V_179 -> V_212 & V_213 ) ,
V_153 , V_8 ) ;
if ( V_75 < 0 )
F_98 ( L_10 ) ;
}
}
int F_99 ( struct V_7 * V_8 )
{
int V_75 ;
T_12 V_214 ;
int V_215 = 0 ;
V_8 -> V_21 = F_3 ( V_8 , V_216 ) ;
switch ( V_8 -> V_21 ) {
case V_22 :
F_100 ( L_11 ) ;
V_8 -> V_26 = F_4 ;
V_8 -> V_162 = 2048 ;
V_8 -> V_38 = V_217 ;
V_8 -> V_36 = V_218 ;
V_8 -> V_35 = V_219 | V_220 ;
V_8 -> V_29 = V_221 ;
V_8 -> V_70 = V_222 ;
V_8 -> V_69 = F_101 ( V_222 ) ;
break;
case V_48 :
F_100 ( L_12 ) ;
V_8 -> V_26 = F_3 ;
V_8 -> V_162 = 128 ;
V_8 -> V_38 = V_223 ;
V_8 -> V_36 = V_224 ;
V_8 -> V_35 = V_225 ;
V_8 -> V_29 = V_226 ;
V_8 -> V_70 = V_227 ;
V_8 -> V_69 = F_101 ( V_227 ) ;
break;
case V_58 :
F_100 ( L_13 ) ;
V_8 -> V_26 = F_3 ;
V_8 -> V_162 = 128 ;
V_8 -> V_38 = V_223 ;
V_8 -> V_36 = V_228 ;
V_8 -> V_35 = V_229 | V_230 | V_231 | V_232 ;
V_8 -> V_29 = V_226 ;
break;
default:
F_98 ( L_14 , V_8 -> V_21 ) ;
return - V_6 ;
}
V_8 -> V_71 = F_102 ( F_103 ( sizeof( V_227 ) ,
sizeof( V_222 ) ) , V_233 ) ;
if ( V_8 -> V_71 == NULL ) {
F_104 (KERN_ERR DRIVER_NAME L_15 ) ;
return - V_141 ;
}
F_105 ( & V_8 -> V_47 ) ;
F_29 ( & V_8 -> V_52 , 0 ) ;
F_81 ( V_8 ) ;
V_75 = F_23 ( V_8 ) ;
if ( V_75 ) {
F_87 ( V_8 ) ;
return V_75 ;
}
if ( V_8 -> V_88 ) {
F_106 ( V_8 -> V_88 ) ;
F_107 ( V_8 -> V_88 ) ;
}
if ( F_62 ( V_8 ) )
F_98 ( L_16 ) ;
if ( V_8 -> V_65 ) {
struct V_178 * V_179 = V_8 -> V_65 ;
if ( V_8 -> V_21 == V_48 )
F_95 ( V_8 , V_179 ) ;
V_215 = V_179 -> V_234 & V_213 ;
V_8 -> V_46 = V_179 -> V_46 ;
if ( V_179 -> V_46 )
V_8 -> V_41 ( V_8 , V_55 , V_179 -> V_46 ) ;
if ( V_179 -> V_235 )
F_13 ( V_8 , V_179 -> V_235 ) ;
}
if ( ! V_8 -> V_90 ) {
F_108 ( L_17 ) ;
goto V_92;
}
if ( V_8 -> V_65 && V_8 -> V_21 == V_48 )
V_214 = F_40 ;
else
V_214 = NULL ;
V_75 = F_97 ( V_8 -> V_90 , F_32 ,
V_214 ,
V_210 | V_211 |
V_215 ,
V_153 , V_8 ) ;
if ( V_75 < 0 ) {
F_98 ( L_18 ) ;
goto V_92;
}
V_8 -> V_115 . V_236 = V_237 ;
V_8 -> V_115 . V_151 = L_19 ;
V_8 -> V_115 . V_238 = & V_239 ;
if ( F_109 ( & V_8 -> V_115 ) )
F_98 ( L_20 ) ;
V_92:
return 0 ;
}
