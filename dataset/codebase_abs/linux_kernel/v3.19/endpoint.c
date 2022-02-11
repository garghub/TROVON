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
int V_40 ;
struct V_8 * V_8 = V_39 -> V_8 ;
unsigned char * V_41 = V_8 -> V_9 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
if ( V_5 -> V_42 ) {
V_5 -> V_42 ( V_5 -> V_36 , V_8 ) ;
} else {
unsigned int V_43 = 0 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_44 ; ++ V_40 ) {
int V_45 ;
if ( V_39 -> V_46 [ V_40 ] )
V_45 = V_39 -> V_46 [ V_40 ] ;
else
V_45 = F_9 ( V_5 ) ;
V_8 -> V_47 [ V_40 ] . V_48 = V_43 * V_5 -> V_49 ;
V_8 -> V_47 [ V_40 ] . V_50 = V_45 * V_5 -> V_49 ;
V_43 += V_45 ;
}
V_8 -> V_51 = V_39 -> V_44 ;
V_8 -> V_52 = V_43 * V_5 -> V_49 ;
memset ( V_8 -> V_9 , V_5 -> V_53 ,
V_43 * V_5 -> V_49 ) ;
}
break;
case V_54 :
if ( F_18 ( V_5 -> V_6 -> V_7 ) >= V_55 ) {
V_8 -> V_47 [ 0 ] . V_50 = 4 ;
V_8 -> V_47 [ 0 ] . V_48 = 0 ;
V_41 [ 0 ] = V_5 -> V_56 ;
V_41 [ 1 ] = V_5 -> V_56 >> 8 ;
V_41 [ 2 ] = V_5 -> V_56 >> 16 ;
V_41 [ 3 ] = V_5 -> V_56 >> 24 ;
} else {
V_8 -> V_47 [ 0 ] . V_50 = 3 ;
V_8 -> V_47 [ 0 ] . V_48 = 0 ;
V_41 [ 0 ] = V_5 -> V_56 >> 2 ;
V_41 [ 1 ] = V_5 -> V_56 >> 10 ;
V_41 [ 2 ] = V_5 -> V_56 >> 18 ;
}
break;
}
}
static inline void F_19 ( struct V_22 * V_5 ,
struct V_2 * V_34 )
{
int V_40 , V_43 ;
struct V_8 * V_8 = V_34 -> V_8 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
V_43 = 0 ;
for ( V_40 = 0 ; V_40 < V_34 -> V_44 ; V_40 ++ ) {
V_8 -> V_47 [ V_40 ] . V_48 = V_43 ;
V_8 -> V_47 [ V_40 ] . V_50 = V_5 -> V_57 ;
V_43 += V_5 -> V_57 ;
}
V_8 -> V_52 = V_43 ;
V_8 -> V_51 = V_34 -> V_44 ;
break;
case V_54 :
V_8 -> V_47 [ 0 ] . V_50 = F_11 ( 4u , V_5 -> V_58 ) ;
V_8 -> V_47 [ 0 ] . V_48 = 0 ;
break;
}
}
static void F_20 ( struct V_22 * V_5 )
{
while ( F_21 ( V_59 , & V_5 -> V_26 ) ) {
unsigned long V_26 ;
struct V_60 * V_61 ( V_62 ) ;
struct V_2 * V_39 = NULL ;
struct V_8 * V_8 ;
int V_11 , V_40 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
if ( V_5 -> V_63 != V_5 -> V_64 ) {
V_62 = V_5 -> V_65 + V_5 -> V_63 ;
V_5 -> V_63 ++ ;
V_5 -> V_63 %= V_66 ;
if ( ! F_22 ( & V_5 -> V_67 ) )
V_39 = F_23 ( & V_5 -> V_67 ,
struct V_2 , V_68 ) ;
}
F_12 ( & V_5 -> V_30 , V_26 ) ;
if ( V_39 == NULL )
return;
F_24 ( & V_39 -> V_68 ) ;
V_8 = V_39 -> V_8 ;
for ( V_40 = 0 ; V_40 < V_62 -> V_44 ; V_40 ++ )
V_39 -> V_46 [ V_40 ] = V_62 -> V_46 [ V_40 ] ;
F_17 ( V_5 , V_39 ) ;
V_11 = F_25 ( V_39 -> V_8 , V_69 ) ;
if ( V_11 < 0 )
F_26 ( V_5 -> V_6 ,
L_9 ,
V_39 -> V_70 , V_11 , V_39 -> V_8 ) ;
else
F_27 ( V_39 -> V_70 , & V_5 -> V_71 ) ;
}
}
static void F_28 ( struct V_8 * V_8 )
{
struct V_2 * V_39 = V_8 -> V_72 ;
struct V_22 * V_5 = V_39 -> V_5 ;
struct V_73 * V_74 ;
unsigned long V_26 ;
int V_11 ;
if ( F_15 ( V_8 -> V_75 == - V_13 ||
V_8 -> V_75 == - V_12 ||
V_8 -> V_75 == - V_76 ||
V_8 -> V_75 == - V_16 ||
V_5 -> V_6 -> V_77 ) )
goto V_78;
if ( F_8 ( V_5 -> V_25 ) ) {
F_13 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_78;
if ( F_7 ( V_5 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
goto V_78;
}
F_17 ( V_5 , V_39 ) ;
} else {
F_14 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_78;
F_19 ( V_5 , V_39 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 == 0 )
return;
F_26 ( V_5 -> V_6 , L_10 , V_11 ) ;
if ( V_5 -> V_36 && V_5 -> V_36 -> V_79 ) {
V_74 = V_5 -> V_36 -> V_79 ;
F_30 ( V_74 ) ;
}
V_78:
F_31 ( V_39 -> V_70 , & V_5 -> V_71 ) ;
}
struct V_22 * F_32 ( struct V_80 * V_6 ,
struct V_81 * V_82 ,
int V_83 , int V_84 , int type )
{
struct V_22 * V_5 ;
int V_85 = V_84 == V_86 ;
if ( F_33 ( ! V_82 ) )
return NULL ;
F_34 ( & V_6 -> V_87 ) ;
F_35 (ep, &chip->ep_list, list) {
if ( V_5 -> V_83 == V_83 &&
V_5 -> V_88 == V_82 -> V_89 . V_90 &&
V_5 -> V_91 == V_82 -> V_89 . V_92 ) {
F_36 ( V_5 -> V_6 ,
L_11 ,
V_83 , V_5 -> V_88 , V_5 -> V_91 , V_5 ) ;
goto V_93;
}
}
F_36 ( V_6 , L_12 ,
V_85 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_83 ) ;
V_5 = F_37 ( sizeof( * V_5 ) , V_94 ) ;
if ( ! V_5 )
goto V_93;
V_5 -> V_6 = V_6 ;
F_38 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_83 = V_83 ;
V_5 -> V_88 = V_82 -> V_89 . V_90 ;
V_5 -> V_91 = V_82 -> V_89 . V_92 ;
F_39 ( & V_5 -> V_67 ) ;
V_83 &= V_95 ;
if ( V_85 )
V_5 -> V_25 = F_40 ( V_6 -> V_7 , V_83 ) ;
else
V_5 -> V_25 = F_41 ( V_6 -> V_7 , V_83 ) ;
if ( type == V_54 ) {
if ( F_42 ( V_82 , 1 ) -> V_96 >= V_97 &&
F_42 ( V_82 , 1 ) -> V_98 >= 1 &&
F_42 ( V_82 , 1 ) -> V_98 <= 9 )
V_5 -> V_99 = F_42 ( V_82 , 1 ) -> V_98 ;
else if ( F_18 ( V_6 -> V_7 ) == V_100 )
V_5 -> V_99 = 1 ;
else if ( F_42 ( V_82 , 1 ) -> V_101 >= 1 &&
F_42 ( V_82 , 1 ) -> V_101 <= 16 )
V_5 -> V_99 = F_42 ( V_82 , 1 ) -> V_101 - 1 ;
else
V_5 -> V_99 = 3 ;
V_5 -> V_58 = F_43 ( F_42 ( V_82 , 1 ) -> V_102 ) ;
if ( V_6 -> V_103 == F_44 ( 0x0644 , 0x8038 ) &&
V_5 -> V_58 == 4 )
V_5 -> V_104 = 1 ;
}
F_29 ( & V_5 -> V_105 , & V_6 -> V_106 ) ;
V_93:
F_45 ( & V_6 -> V_87 ) ;
return V_5 ;
}
static int F_46 ( struct V_22 * V_5 )
{
unsigned long V_107 = V_108 + F_47 ( 1000 ) ;
int V_109 ;
do {
V_109 = F_48 ( & V_5 -> V_71 , V_5 -> V_110 ) ;
if ( ! V_109 )
break;
F_49 ( 1 ) ;
} while ( F_50 ( V_108 , V_107 ) );
if ( V_109 )
F_26 ( V_5 -> V_6 ,
L_17 ,
V_109 , V_5 -> V_83 ) ;
F_31 ( V_111 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_51 ( struct V_22 * V_5 )
{
if ( V_5 && F_21 ( V_111 , & V_5 -> V_26 ) )
F_46 ( V_5 ) ;
}
static int F_52 ( struct V_22 * V_5 , bool V_112 )
{
unsigned int V_40 ;
if ( ! V_112 && V_5 -> V_6 -> V_77 )
return - V_113 ;
F_31 ( V_59 , & V_5 -> V_26 ) ;
F_39 ( & V_5 -> V_67 ) ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_110 ; V_40 ++ ) {
if ( F_21 ( V_40 , & V_5 -> V_71 ) ) {
if ( ! F_53 ( V_40 , & V_5 -> V_114 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_40 ] . V_8 ;
F_54 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_55 ( struct V_22 * V_5 , int V_112 )
{
int V_40 ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_52 ( V_5 , V_112 ) ;
F_46 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_110 ; V_40 ++ )
F_3 ( & V_5 -> V_8 [ V_40 ] ) ;
if ( V_5 -> V_115 )
F_4 ( V_5 -> V_6 -> V_7 , V_116 * 4 ,
V_5 -> V_115 , V_5 -> V_117 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_110 = 0 ;
}
static int F_56 ( struct V_22 * V_5 ,
T_1 V_118 ,
unsigned int V_119 ,
unsigned int V_120 ,
unsigned int V_121 ,
unsigned int V_122 ,
struct V_123 * V_124 ,
struct V_22 * V_125 )
{
unsigned int V_126 , V_127 , V_128 , V_129 ;
unsigned int V_130 , V_131 , V_132 ;
unsigned int V_133 , V_40 ;
int V_134 = F_57 ( V_118 ) * V_119 ;
if ( V_118 == V_135 && V_124 -> V_136 ) {
V_134 += V_119 << 3 ;
}
V_5 -> V_33 = V_124 -> V_33 ;
V_5 -> V_49 = V_134 >> 3 ;
V_5 -> V_53 = V_118 == V_137 ? 0x80 : 0 ;
V_5 -> V_138 = V_5 -> V_56 + ( V_5 -> V_56 >> 2 ) ;
V_126 = ( ( V_5 -> V_138 + 0xffff ) * ( V_134 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
if ( V_5 -> V_139 && V_5 -> V_139 < V_126 ) {
V_126 = V_5 -> V_139 ;
V_5 -> V_138 = ( V_126 / ( V_134 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_57 = V_5 -> V_139 ;
else
V_5 -> V_57 = V_126 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_100 ) {
V_128 = 8 >> V_5 -> V_33 ;
V_129 = V_140 ;
} else {
V_128 = 1 ;
V_129 = V_141 ;
}
if ( V_125 && ! F_7 ( V_5 ) )
V_129 = F_11 ( V_129 ,
1U << V_125 -> V_99 ) ;
V_129 = F_58 ( 1u , V_129 >> V_5 -> V_33 ) ;
if ( F_59 ( V_5 -> V_25 ) ||
F_7 ( V_5 ) ) {
V_132 = V_128 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_142 ) {
int V_143 = V_5 -> V_33 ;
while ( V_143 < 5 ) {
V_132 <<= 1 ;
++ V_143 ;
}
}
V_132 = F_11 ( V_129 , V_132 ) ;
while ( V_132 > 1 && V_132 * V_126 >= V_120 )
V_132 >>= 1 ;
V_5 -> V_110 = V_66 ;
} else {
V_127 = ( V_5 -> V_56 >> ( 16 - V_5 -> V_33 ) ) *
( V_134 >> 3 ) ;
if ( V_125 )
V_127 -= V_127 >> 3 ;
V_127 = F_58 ( V_127 , 1u ) ;
V_130 = F_60 ( V_120 , V_127 ) ;
V_131 = F_60 ( V_130 ,
V_129 ) ;
V_132 = F_60 ( V_130 , V_131 ) ;
V_5 -> V_144 = F_60 ( V_121 ,
V_131 ) ;
V_133 = F_11 ( ( unsigned ) V_66 ,
V_145 * V_128 / V_132 ) ;
V_5 -> V_110 = F_11 ( V_133 , V_131 * V_122 ) ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_110 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_70 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = V_132 ;
V_3 -> V_4 = V_126 * V_3 -> V_44 ;
if ( V_124 -> V_146 == V_147 )
V_3 -> V_44 ++ ;
V_3 -> V_8 = F_61 ( V_3 -> V_44 , V_94 ) ;
if ( ! V_3 -> V_8 )
goto V_148;
V_3 -> V_8 -> V_9 =
F_62 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_94 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_148;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_149 = V_150 ;
V_3 -> V_8 -> V_143 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_151 = F_28 ;
F_39 ( & V_3 -> V_68 ) ;
}
return 0 ;
V_148:
F_55 ( V_5 , 0 ) ;
return - V_152 ;
}
static int F_63 ( struct V_22 * V_5 )
{
int V_40 ;
V_5 -> V_115 = F_62 ( V_5 -> V_6 -> V_7 , V_116 * 4 ,
V_94 , & V_5 -> V_117 ) ;
if ( ! V_5 -> V_115 )
return - V_152 ;
for ( V_40 = 0 ; V_40 < V_116 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_70 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = 1 ;
V_3 -> V_8 = F_61 ( 1 , V_94 ) ;
if ( ! V_3 -> V_8 )
goto V_148;
V_3 -> V_8 -> V_9 = V_5 -> V_115 + V_40 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_117 + V_40 * 4 ;
V_3 -> V_8 -> V_52 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_149 = V_150 ;
V_3 -> V_8 -> V_51 = 1 ;
V_3 -> V_8 -> V_143 = 1 << V_5 -> V_99 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_151 = F_28 ;
}
V_5 -> V_110 = V_116 ;
return 0 ;
V_148:
F_55 ( V_5 , 0 ) ;
return - V_152 ;
}
int F_64 ( struct V_22 * V_5 ,
T_1 V_118 ,
unsigned int V_119 ,
unsigned int V_120 ,
unsigned int V_153 ,
unsigned int V_154 ,
unsigned int V_1 ,
struct V_123 * V_124 ,
struct V_22 * V_125 )
{
int V_11 ;
if ( V_5 -> V_155 != 0 ) {
F_65 ( V_5 -> V_6 ,
L_18 ,
V_5 -> V_83 ) ;
return - V_156 ;
}
F_55 ( V_5 , 0 ) ;
V_5 -> V_33 = V_124 -> V_33 ;
V_5 -> V_139 = V_124 -> V_139 ;
V_5 -> V_28 = ! ! ( V_124 -> V_157 & V_158 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_100 )
V_5 -> V_56 = F_1 ( V_1 ) ;
else
V_5 -> V_56 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_56 ;
V_5 -> V_159 = V_160 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_56 ( V_5 , V_118 , V_119 ,
V_120 , V_153 ,
V_154 , V_124 , V_125 ) ;
break;
case V_54 :
V_11 = F_63 ( V_5 ) ;
break;
default:
V_11 = - V_18 ;
}
F_36 ( V_5 -> V_6 ,
L_19 ,
V_5 -> V_83 , V_5 -> type , V_5 -> V_110 , V_11 ) ;
return V_11 ;
}
int F_66 ( struct V_22 * V_5 , bool V_161 )
{
int V_11 ;
unsigned int V_40 ;
if ( V_5 -> V_6 -> V_77 )
return - V_113 ;
if ( ++ V_5 -> V_155 != 1 )
return 0 ;
F_52 ( V_5 , false ) ;
if ( V_161 )
F_46 ( V_5 ) ;
V_5 -> V_71 = 0 ;
V_5 -> V_114 = 0 ;
V_5 -> V_31 = 0 ;
F_67 ( V_5 ) ;
F_27 ( V_59 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_40 = 0 ; V_40 < V_5 -> V_110 ; V_40 ++ ) {
struct V_2 * V_39 = V_5 -> V_8 + V_40 ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
}
return 0 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_110 ; V_40 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_40 ] . V_8 ;
if ( F_68 ( ! V_8 ) )
goto V_162;
if ( F_8 ( V_5 -> V_25 ) ) {
F_17 ( V_5 , V_8 -> V_72 ) ;
} else {
F_19 ( V_5 , V_8 -> V_72 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 < 0 ) {
F_26 ( V_5 -> V_6 ,
L_20 ,
V_40 , V_11 , F_6 ( V_11 ) ) ;
goto V_162;
}
F_27 ( V_40 , & V_5 -> V_71 ) ;
}
return 0 ;
V_162:
F_31 ( V_59 , & V_5 -> V_26 ) ;
V_5 -> V_155 -- ;
F_52 ( V_5 , false ) ;
return - V_14 ;
}
void F_69 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_68 ( V_5 -> V_155 == 0 ) )
return;
if ( -- V_5 -> V_155 == 0 ) {
F_52 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_27 ( V_111 , & V_5 -> V_26 ) ;
}
}
void F_70 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( V_5 -> V_155 != 0 )
return;
F_52 ( V_5 , true ) ;
F_46 ( V_5 ) ;
}
void F_71 ( struct V_22 * V_5 )
{
F_55 ( V_5 , 1 ) ;
}
void F_72 ( struct V_22 * V_5 )
{
F_73 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_163 ,
const struct V_8 * V_8 )
{
int V_164 ;
unsigned int V_165 ;
unsigned long V_26 ;
F_68 ( V_5 == V_163 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_155 != 0 ) {
int V_40 , V_166 = 0 ;
struct V_2 * V_167 ;
struct V_60 * V_168 ;
V_167 = V_8 -> V_72 ;
for ( V_40 = 0 ; V_40 < V_167 -> V_44 ; V_40 ++ )
if ( V_8 -> V_47 [ V_40 ] . V_75 == 0 )
V_166 += V_8 -> V_47 [ V_40 ] . V_169 ;
if ( V_166 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_168 = V_5 -> V_65 + V_5 -> V_64 ;
V_168 -> V_44 = V_167 -> V_44 ;
for ( V_40 = 0 ; V_40 < V_167 -> V_44 ; V_40 ++ ) {
if ( V_8 -> V_47 [ V_40 ] . V_75 == 0 )
V_168 -> V_46 [ V_40 ] =
V_8 -> V_47 [ V_40 ] . V_169 / V_163 -> V_49 ;
else
V_168 -> V_46 [ V_40 ] = 0 ;
}
V_5 -> V_64 ++ ;
V_5 -> V_64 %= V_66 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
return;
}
if ( V_8 -> V_47 [ 0 ] . V_75 != 0 ||
V_8 -> V_47 [ 0 ] . V_169 < 3 )
return;
V_165 = F_74 ( V_8 -> V_9 ) ;
if ( V_8 -> V_47 [ 0 ] . V_169 == 3 )
V_165 &= 0x00ffffff ;
else
V_165 &= 0x0fffffff ;
if ( V_165 == 0 )
return;
if ( F_15 ( V_163 -> V_104 ) ) {
if ( V_165 < V_5 -> V_56 - 0x8000 )
V_165 += 0x10000 ;
else if ( V_165 > V_5 -> V_56 + 0x8000 )
V_165 -= 0x10000 ;
} else if ( F_15 ( V_5 -> V_159 == V_160 ) ) {
V_164 = 0 ;
while ( V_165 < V_5 -> V_56 - V_5 -> V_56 / 4 ) {
V_165 <<= 1 ;
V_164 ++ ;
}
while ( V_165 > V_5 -> V_56 + V_5 -> V_56 / 2 ) {
V_165 >>= 1 ;
V_164 -- ;
}
V_5 -> V_159 = V_164 ;
} else if ( V_5 -> V_159 >= 0 )
V_165 <<= V_5 -> V_159 ;
else
V_165 >>= - V_5 -> V_159 ;
if ( F_75 ( V_165 >= V_5 -> V_56 - V_5 -> V_56 / 8 && V_165 <= V_5 -> V_138 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_165 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_159 = V_160 ;
}
}
