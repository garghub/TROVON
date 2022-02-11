static inline unsigned F_1 ( unsigned int V_1 )
{
return ( ( V_1 << 13 ) + 62 ) / 125 ;
}
static inline unsigned F_2 ( unsigned int V_1 )
{
return ( ( V_1 << 10 ) + 62 ) / 125 ;
}
static void F_3 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 )
F_4 ( V_3 -> V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_3 -> V_8 -> V_9 ,
V_3 -> V_8 -> V_10 ) ;
F_5 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
static const char * F_6 ( int V_11 )
{
switch ( V_11 ) {
case - V_12 :
return L_1 ;
case - V_13 :
return L_2 ;
case - V_14 :
return L_3 ;
case - V_15 :
return L_4 ;
case - V_16 :
return L_5 ;
case - V_17 :
return L_6 ;
case - V_18 :
case - V_19 :
case - V_20 :
case - V_21 :
return L_7 ;
default:
return L_8 ;
}
}
int F_7 ( struct V_22 * V_5 )
{
return V_5 -> V_23 &&
V_5 -> V_23 -> type == V_24 &&
V_5 -> type == V_24 &&
F_8 ( V_5 -> V_25 ) ;
}
int F_9 ( struct V_22 * V_5 )
{
unsigned long V_26 ;
int V_27 ;
if ( V_5 -> V_28 )
return V_5 -> V_29 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_31 = ( V_5 -> V_31 & 0xffff )
+ ( V_5 -> V_32 << V_5 -> V_33 ) ;
V_27 = F_11 ( V_5 -> V_31 >> 16 , V_5 -> V_29 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
return V_27 ;
}
static void F_13 ( struct V_22 * V_5 ,
struct V_2 * V_34 )
{
if ( V_5 -> V_35 )
V_5 -> V_35 ( V_5 -> V_36 , V_34 -> V_8 ) ;
}
static void F_14 ( struct V_22 * V_5 ,
struct V_2 * V_34 )
{
struct V_8 * V_8 = V_34 -> V_8 ;
if ( F_15 ( V_5 -> V_37 > 0 ) ) {
V_5 -> V_37 -- ;
return;
}
if ( V_5 -> V_38 )
F_16 ( V_5 -> V_38 , V_5 , V_8 ) ;
if ( V_5 -> V_35 )
V_5 -> V_35 ( V_5 -> V_36 , V_8 ) ;
}
static void F_17 ( struct V_22 * V_5 ,
struct V_2 * V_39 )
{
struct V_8 * V_8 = V_39 -> V_8 ;
unsigned int V_40 = 0 ;
unsigned int V_41 = 0 ;
T_1 V_42 ;
int V_43 ;
if ( V_5 -> V_6 -> V_44 )
V_41 = sizeof( V_42 ) ;
for ( V_43 = 0 ; V_43 < V_39 -> V_45 ; ++ V_43 ) {
unsigned int V_46 ;
unsigned int V_47 ;
int V_48 ;
if ( V_39 -> V_49 [ V_43 ] )
V_48 = V_39 -> V_49 [ V_43 ] ;
else
V_48 = F_9 ( V_5 ) ;
V_47 = V_48 * V_5 -> V_50 ;
V_46 = V_40 * V_5 -> V_50 + V_41 * V_43 ;
V_8 -> V_51 [ V_43 ] . V_46 = V_46 ;
V_8 -> V_51 [ V_43 ] . V_47 = V_47 + V_41 ;
if ( V_41 ) {
V_42 = F_18 ( V_47 ) ;
memcpy ( V_8 -> V_9 + V_46 ,
& V_42 , sizeof( V_42 ) ) ;
}
memset ( V_8 -> V_9 + V_46 + V_41 ,
V_5 -> V_52 , V_47 ) ;
V_40 += V_48 ;
}
V_8 -> V_53 = V_39 -> V_45 ;
V_8 -> V_54 = V_40 * V_5 -> V_50 + V_39 -> V_45 * V_41 ;
}
static void F_19 ( struct V_22 * V_5 ,
struct V_2 * V_39 )
{
struct V_8 * V_8 = V_39 -> V_8 ;
unsigned char * V_55 = V_8 -> V_9 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
if ( V_5 -> V_56 ) {
V_5 -> V_56 ( V_5 -> V_36 , V_8 ) ;
} else {
F_17 ( V_5 , V_39 ) ;
}
break;
case V_57 :
if ( F_20 ( V_5 -> V_6 -> V_7 ) >= V_58 ) {
V_8 -> V_51 [ 0 ] . V_47 = 4 ;
V_8 -> V_51 [ 0 ] . V_46 = 0 ;
V_55 [ 0 ] = V_5 -> V_59 ;
V_55 [ 1 ] = V_5 -> V_59 >> 8 ;
V_55 [ 2 ] = V_5 -> V_59 >> 16 ;
V_55 [ 3 ] = V_5 -> V_59 >> 24 ;
} else {
V_8 -> V_51 [ 0 ] . V_47 = 3 ;
V_8 -> V_51 [ 0 ] . V_46 = 0 ;
V_55 [ 0 ] = V_5 -> V_59 >> 2 ;
V_55 [ 1 ] = V_5 -> V_59 >> 10 ;
V_55 [ 2 ] = V_5 -> V_59 >> 18 ;
}
break;
}
}
static inline void F_21 ( struct V_22 * V_5 ,
struct V_2 * V_34 )
{
int V_43 , V_40 ;
struct V_8 * V_8 = V_34 -> V_8 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
V_40 = 0 ;
for ( V_43 = 0 ; V_43 < V_34 -> V_45 ; V_43 ++ ) {
V_8 -> V_51 [ V_43 ] . V_46 = V_40 ;
V_8 -> V_51 [ V_43 ] . V_47 = V_5 -> V_60 ;
V_40 += V_5 -> V_60 ;
}
V_8 -> V_54 = V_40 ;
V_8 -> V_53 = V_34 -> V_45 ;
break;
case V_57 :
V_8 -> V_51 [ 0 ] . V_47 = F_11 ( 4u , V_5 -> V_61 ) ;
V_8 -> V_51 [ 0 ] . V_46 = 0 ;
break;
}
}
static void F_22 ( struct V_22 * V_5 )
{
while ( F_23 ( V_62 , & V_5 -> V_26 ) ) {
unsigned long V_26 ;
struct V_63 * V_64 ( V_65 ) ;
struct V_2 * V_39 = NULL ;
struct V_8 * V_8 ;
int V_11 , V_43 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
if ( V_5 -> V_66 != V_5 -> V_67 ) {
V_65 = V_5 -> V_68 + V_5 -> V_66 ;
V_5 -> V_66 ++ ;
V_5 -> V_66 %= V_69 ;
if ( ! F_24 ( & V_5 -> V_70 ) )
V_39 = F_25 ( & V_5 -> V_70 ,
struct V_2 , V_71 ) ;
}
F_12 ( & V_5 -> V_30 , V_26 ) ;
if ( V_39 == NULL )
return;
F_26 ( & V_39 -> V_71 ) ;
V_8 = V_39 -> V_8 ;
for ( V_43 = 0 ; V_43 < V_65 -> V_45 ; V_43 ++ )
V_39 -> V_49 [ V_43 ] = V_65 -> V_49 [ V_43 ] ;
F_19 ( V_5 , V_39 ) ;
V_11 = F_27 ( V_39 -> V_8 , V_72 ) ;
if ( V_11 < 0 )
F_28 ( V_5 -> V_6 ,
L_9 ,
V_39 -> V_73 , V_11 , V_39 -> V_8 ) ;
else
F_29 ( V_39 -> V_73 , & V_5 -> V_74 ) ;
}
}
static void F_30 ( struct V_8 * V_8 )
{
struct V_2 * V_39 = V_8 -> V_75 ;
struct V_22 * V_5 = V_39 -> V_5 ;
struct V_76 * V_77 ;
unsigned long V_26 ;
int V_11 ;
if ( F_15 ( V_8 -> V_78 == - V_13 ||
V_8 -> V_78 == - V_12 ||
V_8 -> V_78 == - V_79 ||
V_8 -> V_78 == - V_16 ) )
goto V_80;
if ( F_15 ( F_31 ( & V_5 -> V_6 -> V_81 ) ) )
goto V_80;
if ( F_8 ( V_5 -> V_25 ) ) {
F_13 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_23 ( V_62 , & V_5 -> V_26 ) ) )
goto V_80;
if ( F_7 ( V_5 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
F_32 ( & V_39 -> V_71 , & V_5 -> V_70 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_22 ( V_5 ) ;
goto V_80;
}
F_19 ( V_5 , V_39 ) ;
} else {
F_14 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_23 ( V_62 , & V_5 -> V_26 ) ) )
goto V_80;
F_21 ( V_5 , V_39 ) ;
}
V_11 = F_27 ( V_8 , V_72 ) ;
if ( V_11 == 0 )
return;
F_28 ( V_5 -> V_6 , L_10 , V_11 ) ;
if ( V_5 -> V_36 && V_5 -> V_36 -> V_82 ) {
V_77 = V_5 -> V_36 -> V_82 ;
F_33 ( V_77 ) ;
}
V_80:
F_34 ( V_39 -> V_73 , & V_5 -> V_74 ) ;
}
struct V_22 * F_35 ( struct V_83 * V_6 ,
struct V_84 * V_85 ,
int V_86 , int V_87 , int type )
{
struct V_22 * V_5 ;
int V_88 = V_87 == V_89 ;
if ( F_36 ( ! V_85 ) )
return NULL ;
F_37 ( & V_6 -> V_90 ) ;
F_38 (ep, &chip->ep_list, list) {
if ( V_5 -> V_86 == V_86 &&
V_5 -> V_91 == V_85 -> V_92 . V_93 &&
V_5 -> V_94 == V_85 -> V_92 . V_95 ) {
F_39 ( V_5 -> V_6 ,
L_11 ,
V_86 , V_5 -> V_91 , V_5 -> V_94 , V_5 ) ;
goto V_96;
}
}
F_39 ( V_6 , L_12 ,
V_88 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_86 ) ;
V_5 = F_40 ( sizeof( * V_5 ) , V_97 ) ;
if ( ! V_5 )
goto V_96;
V_5 -> V_6 = V_6 ;
F_41 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_86 = V_86 ;
V_5 -> V_91 = V_85 -> V_92 . V_93 ;
V_5 -> V_94 = V_85 -> V_92 . V_95 ;
F_42 ( & V_5 -> V_70 ) ;
V_86 &= V_98 ;
if ( V_88 )
V_5 -> V_25 = F_43 ( V_6 -> V_7 , V_86 ) ;
else
V_5 -> V_25 = F_44 ( V_6 -> V_7 , V_86 ) ;
if ( type == V_57 ) {
if ( F_45 ( V_85 , 1 ) -> V_99 >= V_100 &&
F_45 ( V_85 , 1 ) -> V_101 >= 1 &&
F_45 ( V_85 , 1 ) -> V_101 <= 9 )
V_5 -> V_102 = F_45 ( V_85 , 1 ) -> V_101 ;
else if ( F_20 ( V_6 -> V_7 ) == V_103 )
V_5 -> V_102 = 1 ;
else if ( F_45 ( V_85 , 1 ) -> V_104 >= 1 &&
F_45 ( V_85 , 1 ) -> V_104 <= 16 )
V_5 -> V_102 = F_45 ( V_85 , 1 ) -> V_104 - 1 ;
else
V_5 -> V_102 = 3 ;
V_5 -> V_61 = F_46 ( F_45 ( V_85 , 1 ) -> V_105 ) ;
}
F_32 ( & V_5 -> V_106 , & V_6 -> V_107 ) ;
V_96:
F_47 ( & V_6 -> V_90 ) ;
return V_5 ;
}
static int F_48 ( struct V_22 * V_5 )
{
unsigned long V_108 = V_109 + F_49 ( 1000 ) ;
int V_110 ;
do {
V_110 = F_50 ( & V_5 -> V_74 , V_5 -> V_111 ) ;
if ( ! V_110 )
break;
F_51 ( 1 ) ;
} while ( F_52 ( V_109 , V_108 ) );
if ( V_110 )
F_28 ( V_5 -> V_6 ,
L_17 ,
V_110 , V_5 -> V_86 ) ;
F_34 ( V_112 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_53 ( struct V_22 * V_5 )
{
if ( V_5 && F_23 ( V_112 , & V_5 -> V_26 ) )
F_48 ( V_5 ) ;
}
static int F_54 ( struct V_22 * V_5 , bool V_113 )
{
unsigned int V_43 ;
if ( ! V_113 && F_31 ( & V_5 -> V_6 -> V_81 ) )
return - V_114 ;
F_34 ( V_62 , & V_5 -> V_26 ) ;
F_42 ( & V_5 -> V_70 ) ;
V_5 -> V_66 = 0 ;
V_5 -> V_67 = 0 ;
for ( V_43 = 0 ; V_43 < V_5 -> V_111 ; V_43 ++ ) {
if ( F_23 ( V_43 , & V_5 -> V_74 ) ) {
if ( ! F_55 ( V_43 , & V_5 -> V_115 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_43 ] . V_8 ;
F_56 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_57 ( struct V_22 * V_5 , int V_113 )
{
int V_43 ;
V_5 -> V_35 = NULL ;
V_5 -> V_56 = NULL ;
F_54 ( V_5 , V_113 ) ;
F_48 ( V_5 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_111 ; V_43 ++ )
F_3 ( & V_5 -> V_8 [ V_43 ] ) ;
if ( V_5 -> V_116 )
F_4 ( V_5 -> V_6 -> V_7 , V_117 * 4 ,
V_5 -> V_116 , V_5 -> V_118 ) ;
V_5 -> V_116 = NULL ;
V_5 -> V_111 = 0 ;
}
static int F_58 ( struct V_22 * V_5 ,
T_2 V_119 ,
unsigned int V_120 ,
unsigned int V_121 ,
unsigned int V_122 ,
unsigned int V_123 ,
struct V_124 * V_125 ,
struct V_22 * V_126 )
{
unsigned int V_127 , V_128 , V_129 , V_130 ;
unsigned int V_131 , V_132 , V_133 ;
unsigned int V_134 , V_43 ;
int V_135 = F_59 ( V_119 ) * V_120 ;
int V_44 = ( V_5 -> V_6 -> V_44 &&
F_8 ( V_5 -> V_25 ) ) ;
if ( V_119 == V_136 && V_125 -> V_137 ) {
V_135 += V_120 << 3 ;
}
V_5 -> V_33 = V_125 -> V_33 ;
V_5 -> V_50 = V_135 >> 3 ;
V_5 -> V_52 = V_119 == V_138 ? 0x80 : 0 ;
V_5 -> V_139 = V_5 -> V_59 + ( V_5 -> V_59 >> 2 ) ;
V_127 = ( ( ( V_5 -> V_139 << V_5 -> V_33 ) + 0xffff ) >> 16 ) *
( V_135 >> 3 ) ;
if ( V_44 )
V_127 += sizeof( T_1 ) ;
if ( V_5 -> V_140 && V_5 -> V_140 < V_127 ) {
unsigned int V_141 = V_127 = V_5 -> V_140 ;
if ( V_44 )
V_141 -= sizeof( T_1 ) ;
V_5 -> V_139 = ( V_141 / ( V_135 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_60 = V_5 -> V_140 ;
else
V_5 -> V_60 = V_127 ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) != V_103 ) {
V_129 = 8 >> V_5 -> V_33 ;
V_130 = V_142 ;
} else {
V_129 = 1 ;
V_130 = V_143 ;
}
if ( V_126 && ! F_7 ( V_5 ) )
V_130 = F_11 ( V_130 ,
1U << V_126 -> V_102 ) ;
V_130 = F_60 ( 1u , V_130 >> V_5 -> V_33 ) ;
if ( F_61 ( V_5 -> V_25 ) ||
F_7 ( V_5 ) ) {
V_133 = V_129 ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) == V_144 ) {
int V_145 = V_5 -> V_33 ;
while ( V_145 < 5 ) {
V_133 <<= 1 ;
++ V_145 ;
}
}
V_133 = F_11 ( V_130 , V_133 ) ;
while ( V_133 > 1 && V_133 * V_127 >= V_121 )
V_133 >>= 1 ;
V_5 -> V_111 = V_69 ;
} else {
V_128 = ( V_5 -> V_59 >> ( 16 - V_5 -> V_33 ) ) *
( V_135 >> 3 ) ;
if ( V_126 )
V_128 -= V_128 >> 3 ;
V_128 = F_60 ( V_128 , 1u ) ;
V_131 = F_62 ( V_121 , V_128 ) ;
V_132 = F_62 ( V_131 ,
V_130 ) ;
V_133 = F_62 ( V_131 , V_132 ) ;
V_5 -> V_146 = F_62 ( V_122 ,
V_132 ) ;
V_134 = F_11 ( ( unsigned ) V_69 ,
V_147 * V_129 / V_133 ) ;
V_5 -> V_111 = F_11 ( V_134 , V_132 * V_123 ) ;
}
for ( V_43 = 0 ; V_43 < V_5 -> V_111 ; V_43 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_43 ] ;
V_3 -> V_73 = V_43 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_45 = V_133 ;
V_3 -> V_4 = V_127 * V_3 -> V_45 ;
if ( V_125 -> V_148 == V_149 )
V_3 -> V_45 ++ ;
V_3 -> V_8 = F_63 ( V_3 -> V_45 , V_97 ) ;
if ( ! V_3 -> V_8 )
goto V_150;
V_3 -> V_8 -> V_9 =
F_64 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_97 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_150;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_151 = V_152 ;
V_3 -> V_8 -> V_145 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_75 = V_3 ;
V_3 -> V_8 -> V_153 = F_30 ;
F_42 ( & V_3 -> V_71 ) ;
}
return 0 ;
V_150:
F_57 ( V_5 , 0 ) ;
return - V_154 ;
}
static int F_65 ( struct V_22 * V_5 )
{
int V_43 ;
V_5 -> V_116 = F_64 ( V_5 -> V_6 -> V_7 , V_117 * 4 ,
V_97 , & V_5 -> V_118 ) ;
if ( ! V_5 -> V_116 )
return - V_154 ;
for ( V_43 = 0 ; V_43 < V_117 ; V_43 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_43 ] ;
V_3 -> V_73 = V_43 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_45 = 1 ;
V_3 -> V_8 = F_63 ( 1 , V_97 ) ;
if ( ! V_3 -> V_8 )
goto V_150;
V_3 -> V_8 -> V_9 = V_5 -> V_116 + V_43 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_118 + V_43 * 4 ;
V_3 -> V_8 -> V_54 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_151 = V_152 ;
V_3 -> V_8 -> V_53 = 1 ;
V_3 -> V_8 -> V_145 = 1 << V_5 -> V_102 ;
V_3 -> V_8 -> V_75 = V_3 ;
V_3 -> V_8 -> V_153 = F_30 ;
}
V_5 -> V_111 = V_117 ;
return 0 ;
V_150:
F_57 ( V_5 , 0 ) ;
return - V_154 ;
}
int F_66 ( struct V_22 * V_5 ,
T_2 V_119 ,
unsigned int V_120 ,
unsigned int V_121 ,
unsigned int V_155 ,
unsigned int V_156 ,
unsigned int V_1 ,
struct V_124 * V_125 ,
struct V_22 * V_126 )
{
int V_11 ;
if ( V_5 -> V_157 != 0 ) {
F_67 ( V_5 -> V_6 ,
L_18 ,
V_5 -> V_86 ) ;
return - V_158 ;
}
F_57 ( V_5 , 0 ) ;
V_5 -> V_33 = V_125 -> V_33 ;
V_5 -> V_140 = V_125 -> V_140 ;
V_5 -> V_28 = ! ! ( V_125 -> V_159 & V_160 ) ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) == V_103 )
V_5 -> V_59 = F_1 ( V_1 ) ;
else
V_5 -> V_59 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_59 ;
V_5 -> V_161 = V_162 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_58 ( V_5 , V_119 , V_120 ,
V_121 , V_155 ,
V_156 , V_125 , V_126 ) ;
break;
case V_57 :
V_11 = F_65 ( V_5 ) ;
break;
default:
V_11 = - V_18 ;
}
F_39 ( V_5 -> V_6 ,
L_19 ,
V_5 -> V_86 , V_5 -> type , V_5 -> V_111 , V_11 ) ;
return V_11 ;
}
int F_68 ( struct V_22 * V_5 , bool V_163 )
{
int V_11 ;
unsigned int V_43 ;
if ( F_31 ( & V_5 -> V_6 -> V_81 ) )
return - V_114 ;
if ( ++ V_5 -> V_157 != 1 )
return 0 ;
F_54 ( V_5 , false ) ;
if ( V_163 )
F_48 ( V_5 ) ;
V_5 -> V_74 = 0 ;
V_5 -> V_115 = 0 ;
V_5 -> V_31 = 0 ;
F_69 ( V_5 ) ;
F_29 ( V_62 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_43 = 0 ; V_43 < V_5 -> V_111 ; V_43 ++ ) {
struct V_2 * V_39 = V_5 -> V_8 + V_43 ;
F_32 ( & V_39 -> V_71 , & V_5 -> V_70 ) ;
}
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_5 -> V_111 ; V_43 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_43 ] . V_8 ;
if ( F_70 ( ! V_8 ) )
goto V_164;
if ( F_8 ( V_5 -> V_25 ) ) {
F_19 ( V_5 , V_8 -> V_75 ) ;
} else {
F_21 ( V_5 , V_8 -> V_75 ) ;
}
V_11 = F_27 ( V_8 , V_72 ) ;
if ( V_11 < 0 ) {
F_28 ( V_5 -> V_6 ,
L_20 ,
V_43 , V_11 , F_6 ( V_11 ) ) ;
goto V_164;
}
F_29 ( V_43 , & V_5 -> V_74 ) ;
}
return 0 ;
V_164:
F_34 ( V_62 , & V_5 -> V_26 ) ;
V_5 -> V_157 -- ;
F_54 ( V_5 , false ) ;
return - V_14 ;
}
void F_71 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_70 ( V_5 -> V_157 == 0 ) )
return;
if ( -- V_5 -> V_157 == 0 ) {
F_54 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_56 = NULL ;
F_29 ( V_112 , & V_5 -> V_26 ) ;
}
}
void F_72 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( V_5 -> V_157 != 0 )
return;
F_54 ( V_5 , true ) ;
F_48 ( V_5 ) ;
}
void F_73 ( struct V_22 * V_5 )
{
F_57 ( V_5 , 1 ) ;
}
void F_74 ( struct V_22 * V_5 )
{
F_75 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_165 ,
const struct V_8 * V_8 )
{
int V_166 ;
unsigned int V_167 ;
unsigned long V_26 ;
F_70 ( V_5 == V_165 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_157 != 0 ) {
int V_43 , V_168 = 0 ;
struct V_2 * V_169 ;
struct V_63 * V_170 ;
V_169 = V_8 -> V_75 ;
for ( V_43 = 0 ; V_43 < V_169 -> V_45 ; V_43 ++ )
if ( V_8 -> V_51 [ V_43 ] . V_78 == 0 )
V_168 += V_8 -> V_51 [ V_43 ] . V_171 ;
if ( V_168 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_170 = V_5 -> V_68 + V_5 -> V_67 ;
V_170 -> V_45 = V_169 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_169 -> V_45 ; V_43 ++ ) {
if ( V_8 -> V_51 [ V_43 ] . V_78 == 0 )
V_170 -> V_49 [ V_43 ] =
V_8 -> V_51 [ V_43 ] . V_171 / V_165 -> V_50 ;
else
V_170 -> V_49 [ V_43 ] = 0 ;
}
V_5 -> V_67 ++ ;
V_5 -> V_67 %= V_69 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_22 ( V_5 ) ;
return;
}
if ( V_8 -> V_51 [ 0 ] . V_78 != 0 ||
V_8 -> V_51 [ 0 ] . V_171 < 3 )
return;
V_167 = F_76 ( V_8 -> V_9 ) ;
if ( V_8 -> V_51 [ 0 ] . V_171 == 3 )
V_167 &= 0x00ffffff ;
else
V_167 &= 0x0fffffff ;
if ( V_167 == 0 )
return;
if ( F_15 ( V_165 -> V_172 ) ) {
if ( V_167 < V_5 -> V_59 - 0x8000 )
V_167 += 0xf000 ;
else if ( V_167 > V_5 -> V_59 + 0x8000 )
V_167 -= 0xf000 ;
} else if ( F_15 ( V_5 -> V_161 == V_162 ) ) {
V_166 = 0 ;
while ( V_167 < V_5 -> V_59 - V_5 -> V_59 / 4 ) {
V_167 <<= 1 ;
V_166 ++ ;
}
while ( V_167 > V_5 -> V_59 + V_5 -> V_59 / 2 ) {
V_167 >>= 1 ;
V_166 -- ;
}
V_5 -> V_161 = V_166 ;
} else if ( V_5 -> V_161 >= 0 )
V_167 <<= V_5 -> V_161 ;
else
V_167 >>= - V_5 -> V_161 ;
if ( F_77 ( V_167 >= V_5 -> V_59 - V_5 -> V_59 / 8 && V_167 <= V_5 -> V_139 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_167 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_161 = V_162 ;
}
}
