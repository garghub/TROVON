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
if ( V_6 -> V_106 == F_47 ( 0x0644 , 0x8038 ) &&
V_5 -> V_61 == 4 )
V_5 -> V_107 = 1 ;
}
F_32 ( & V_5 -> V_108 , & V_6 -> V_109 ) ;
V_96:
F_48 ( & V_6 -> V_90 ) ;
return V_5 ;
}
static int F_49 ( struct V_22 * V_5 )
{
unsigned long V_110 = V_111 + F_50 ( 1000 ) ;
int V_112 ;
do {
V_112 = F_51 ( & V_5 -> V_74 , V_5 -> V_113 ) ;
if ( ! V_112 )
break;
F_52 ( 1 ) ;
} while ( F_53 ( V_111 , V_110 ) );
if ( V_112 )
F_28 ( V_5 -> V_6 ,
L_17 ,
V_112 , V_5 -> V_86 ) ;
F_34 ( V_114 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_54 ( struct V_22 * V_5 )
{
if ( V_5 && F_23 ( V_114 , & V_5 -> V_26 ) )
F_49 ( V_5 ) ;
}
static int F_55 ( struct V_22 * V_5 , bool V_115 )
{
unsigned int V_43 ;
if ( ! V_115 && F_31 ( & V_5 -> V_6 -> V_81 ) )
return - V_116 ;
F_34 ( V_62 , & V_5 -> V_26 ) ;
F_42 ( & V_5 -> V_70 ) ;
V_5 -> V_66 = 0 ;
V_5 -> V_67 = 0 ;
for ( V_43 = 0 ; V_43 < V_5 -> V_113 ; V_43 ++ ) {
if ( F_23 ( V_43 , & V_5 -> V_74 ) ) {
if ( ! F_56 ( V_43 , & V_5 -> V_117 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_43 ] . V_8 ;
F_57 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_58 ( struct V_22 * V_5 , int V_115 )
{
int V_43 ;
V_5 -> V_35 = NULL ;
V_5 -> V_56 = NULL ;
F_55 ( V_5 , V_115 ) ;
F_49 ( V_5 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_113 ; V_43 ++ )
F_3 ( & V_5 -> V_8 [ V_43 ] ) ;
if ( V_5 -> V_118 )
F_4 ( V_5 -> V_6 -> V_7 , V_119 * 4 ,
V_5 -> V_118 , V_5 -> V_120 ) ;
V_5 -> V_118 = NULL ;
V_5 -> V_113 = 0 ;
}
static int F_59 ( struct V_22 * V_5 ,
T_2 V_121 ,
unsigned int V_122 ,
unsigned int V_123 ,
unsigned int V_124 ,
unsigned int V_125 ,
struct V_126 * V_127 ,
struct V_22 * V_128 )
{
unsigned int V_129 , V_130 , V_131 , V_132 ;
unsigned int V_133 , V_134 , V_135 ;
unsigned int V_136 , V_43 ;
int V_137 = F_60 ( V_121 ) * V_122 ;
int V_44 = ( V_5 -> V_6 -> V_44 &&
F_8 ( V_5 -> V_25 ) ) ;
if ( V_121 == V_138 && V_127 -> V_139 ) {
V_137 += V_122 << 3 ;
}
V_5 -> V_33 = V_127 -> V_33 ;
V_5 -> V_50 = V_137 >> 3 ;
V_5 -> V_52 = V_121 == V_140 ? 0x80 : 0 ;
V_5 -> V_141 = V_5 -> V_59 + ( V_5 -> V_59 >> 2 ) ;
V_129 = ( ( ( V_5 -> V_141 << V_5 -> V_33 ) + 0xffff ) >> 16 ) *
( V_137 >> 3 ) ;
if ( V_44 )
V_129 += sizeof( T_1 ) ;
if ( V_5 -> V_142 && V_5 -> V_142 < V_129 ) {
unsigned int V_143 = V_129 = V_5 -> V_142 ;
if ( V_44 )
V_143 -= sizeof( T_1 ) ;
V_5 -> V_141 = ( V_143 / ( V_137 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_60 = V_5 -> V_142 ;
else
V_5 -> V_60 = V_129 ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) != V_103 ) {
V_131 = 8 >> V_5 -> V_33 ;
V_132 = V_144 ;
} else {
V_131 = 1 ;
V_132 = V_145 ;
}
if ( V_128 && ! F_7 ( V_5 ) )
V_132 = F_11 ( V_132 ,
1U << V_128 -> V_102 ) ;
V_132 = F_61 ( 1u , V_132 >> V_5 -> V_33 ) ;
if ( F_62 ( V_5 -> V_25 ) ||
F_7 ( V_5 ) ) {
V_135 = V_131 ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) == V_146 ) {
int V_147 = V_5 -> V_33 ;
while ( V_147 < 5 ) {
V_135 <<= 1 ;
++ V_147 ;
}
}
V_135 = F_11 ( V_132 , V_135 ) ;
while ( V_135 > 1 && V_135 * V_129 >= V_123 )
V_135 >>= 1 ;
V_5 -> V_113 = V_69 ;
} else {
V_130 = ( V_5 -> V_59 >> ( 16 - V_5 -> V_33 ) ) *
( V_137 >> 3 ) ;
if ( V_128 )
V_130 -= V_130 >> 3 ;
V_130 = F_61 ( V_130 , 1u ) ;
V_133 = F_63 ( V_123 , V_130 ) ;
V_134 = F_63 ( V_133 ,
V_132 ) ;
V_135 = F_63 ( V_133 , V_134 ) ;
V_5 -> V_148 = F_63 ( V_124 ,
V_134 ) ;
V_136 = F_11 ( ( unsigned ) V_69 ,
V_149 * V_131 / V_135 ) ;
V_5 -> V_113 = F_11 ( V_136 , V_134 * V_125 ) ;
}
for ( V_43 = 0 ; V_43 < V_5 -> V_113 ; V_43 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_43 ] ;
V_3 -> V_73 = V_43 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_45 = V_135 ;
V_3 -> V_4 = V_129 * V_3 -> V_45 ;
if ( V_127 -> V_150 == V_151 )
V_3 -> V_45 ++ ;
V_3 -> V_8 = F_64 ( V_3 -> V_45 , V_97 ) ;
if ( ! V_3 -> V_8 )
goto V_152;
V_3 -> V_8 -> V_9 =
F_65 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_97 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_152;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_153 = V_154 ;
V_3 -> V_8 -> V_147 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_75 = V_3 ;
V_3 -> V_8 -> V_155 = F_30 ;
F_42 ( & V_3 -> V_71 ) ;
}
return 0 ;
V_152:
F_58 ( V_5 , 0 ) ;
return - V_156 ;
}
static int F_66 ( struct V_22 * V_5 )
{
int V_43 ;
V_5 -> V_118 = F_65 ( V_5 -> V_6 -> V_7 , V_119 * 4 ,
V_97 , & V_5 -> V_120 ) ;
if ( ! V_5 -> V_118 )
return - V_156 ;
for ( V_43 = 0 ; V_43 < V_119 ; V_43 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_43 ] ;
V_3 -> V_73 = V_43 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_45 = 1 ;
V_3 -> V_8 = F_64 ( 1 , V_97 ) ;
if ( ! V_3 -> V_8 )
goto V_152;
V_3 -> V_8 -> V_9 = V_5 -> V_118 + V_43 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_120 + V_43 * 4 ;
V_3 -> V_8 -> V_54 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_153 = V_154 ;
V_3 -> V_8 -> V_53 = 1 ;
V_3 -> V_8 -> V_147 = 1 << V_5 -> V_102 ;
V_3 -> V_8 -> V_75 = V_3 ;
V_3 -> V_8 -> V_155 = F_30 ;
}
V_5 -> V_113 = V_119 ;
return 0 ;
V_152:
F_58 ( V_5 , 0 ) ;
return - V_156 ;
}
int F_67 ( struct V_22 * V_5 ,
T_2 V_121 ,
unsigned int V_122 ,
unsigned int V_123 ,
unsigned int V_157 ,
unsigned int V_158 ,
unsigned int V_1 ,
struct V_126 * V_127 ,
struct V_22 * V_128 )
{
int V_11 ;
if ( V_5 -> V_159 != 0 ) {
F_68 ( V_5 -> V_6 ,
L_18 ,
V_5 -> V_86 ) ;
return - V_160 ;
}
F_58 ( V_5 , 0 ) ;
V_5 -> V_33 = V_127 -> V_33 ;
V_5 -> V_142 = V_127 -> V_142 ;
V_5 -> V_28 = ! ! ( V_127 -> V_161 & V_162 ) ;
if ( F_20 ( V_5 -> V_6 -> V_7 ) == V_103 )
V_5 -> V_59 = F_1 ( V_1 ) ;
else
V_5 -> V_59 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_59 ;
V_5 -> V_163 = V_164 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_59 ( V_5 , V_121 , V_122 ,
V_123 , V_157 ,
V_158 , V_127 , V_128 ) ;
break;
case V_57 :
V_11 = F_66 ( V_5 ) ;
break;
default:
V_11 = - V_18 ;
}
F_39 ( V_5 -> V_6 ,
L_19 ,
V_5 -> V_86 , V_5 -> type , V_5 -> V_113 , V_11 ) ;
return V_11 ;
}
int F_69 ( struct V_22 * V_5 , bool V_165 )
{
int V_11 ;
unsigned int V_43 ;
if ( F_31 ( & V_5 -> V_6 -> V_81 ) )
return - V_116 ;
if ( ++ V_5 -> V_159 != 1 )
return 0 ;
F_55 ( V_5 , false ) ;
if ( V_165 )
F_49 ( V_5 ) ;
V_5 -> V_74 = 0 ;
V_5 -> V_117 = 0 ;
V_5 -> V_31 = 0 ;
F_70 ( V_5 ) ;
F_29 ( V_62 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_43 = 0 ; V_43 < V_5 -> V_113 ; V_43 ++ ) {
struct V_2 * V_39 = V_5 -> V_8 + V_43 ;
F_32 ( & V_39 -> V_71 , & V_5 -> V_70 ) ;
}
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_5 -> V_113 ; V_43 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_43 ] . V_8 ;
if ( F_71 ( ! V_8 ) )
goto V_166;
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
goto V_166;
}
F_29 ( V_43 , & V_5 -> V_74 ) ;
}
return 0 ;
V_166:
F_34 ( V_62 , & V_5 -> V_26 ) ;
V_5 -> V_159 -- ;
F_55 ( V_5 , false ) ;
return - V_14 ;
}
void F_72 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_71 ( V_5 -> V_159 == 0 ) )
return;
if ( -- V_5 -> V_159 == 0 ) {
F_55 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_56 = NULL ;
F_29 ( V_114 , & V_5 -> V_26 ) ;
}
}
void F_73 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( V_5 -> V_159 != 0 )
return;
F_55 ( V_5 , true ) ;
F_49 ( V_5 ) ;
}
void F_74 ( struct V_22 * V_5 )
{
F_58 ( V_5 , 1 ) ;
}
void F_75 ( struct V_22 * V_5 )
{
F_76 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_167 ,
const struct V_8 * V_8 )
{
int V_168 ;
unsigned int V_169 ;
unsigned long V_26 ;
F_71 ( V_5 == V_167 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_159 != 0 ) {
int V_43 , V_170 = 0 ;
struct V_2 * V_171 ;
struct V_63 * V_172 ;
V_171 = V_8 -> V_75 ;
for ( V_43 = 0 ; V_43 < V_171 -> V_45 ; V_43 ++ )
if ( V_8 -> V_51 [ V_43 ] . V_78 == 0 )
V_170 += V_8 -> V_51 [ V_43 ] . V_173 ;
if ( V_170 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_172 = V_5 -> V_68 + V_5 -> V_67 ;
V_172 -> V_45 = V_171 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_171 -> V_45 ; V_43 ++ ) {
if ( V_8 -> V_51 [ V_43 ] . V_78 == 0 )
V_172 -> V_49 [ V_43 ] =
V_8 -> V_51 [ V_43 ] . V_173 / V_167 -> V_50 ;
else
V_172 -> V_49 [ V_43 ] = 0 ;
}
V_5 -> V_67 ++ ;
V_5 -> V_67 %= V_69 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_22 ( V_5 ) ;
return;
}
if ( V_8 -> V_51 [ 0 ] . V_78 != 0 ||
V_8 -> V_51 [ 0 ] . V_173 < 3 )
return;
V_169 = F_77 ( V_8 -> V_9 ) ;
if ( V_8 -> V_51 [ 0 ] . V_173 == 3 )
V_169 &= 0x00ffffff ;
else
V_169 &= 0x0fffffff ;
if ( V_169 == 0 )
return;
if ( F_15 ( V_167 -> V_107 ) ) {
if ( V_169 < V_5 -> V_59 - 0x8000 )
V_169 += 0x10000 ;
else if ( V_169 > V_5 -> V_59 + 0x8000 )
V_169 -= 0x10000 ;
} else if ( F_15 ( V_5 -> V_163 == V_164 ) ) {
V_168 = 0 ;
while ( V_169 < V_5 -> V_59 - V_5 -> V_59 / 4 ) {
V_169 <<= 1 ;
V_168 ++ ;
}
while ( V_169 > V_5 -> V_59 + V_5 -> V_59 / 2 ) {
V_169 >>= 1 ;
V_168 -- ;
}
V_5 -> V_163 = V_168 ;
} else if ( V_5 -> V_163 >= 0 )
V_169 <<= V_5 -> V_163 ;
else
V_169 >>= - V_5 -> V_163 ;
if ( F_78 ( V_169 >= V_5 -> V_59 - V_5 -> V_59 / 8 && V_169 <= V_5 -> V_141 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_169 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_163 = V_164 ;
}
}
