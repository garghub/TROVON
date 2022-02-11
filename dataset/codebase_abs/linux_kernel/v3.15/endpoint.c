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
int V_11 ;
if ( F_15 ( V_8 -> V_73 == - V_13 ||
V_8 -> V_73 == - V_12 ||
V_8 -> V_73 == - V_74 ||
V_8 -> V_73 == - V_16 ||
V_5 -> V_6 -> V_75 ) )
goto V_76;
if ( F_8 ( V_5 -> V_25 ) ) {
F_13 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_76;
if ( F_7 ( V_5 ) ) {
unsigned long V_26 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
goto V_76;
}
F_17 ( V_5 , V_39 ) ;
} else {
F_14 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_76;
F_19 ( V_5 , V_39 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 == 0 )
return;
F_26 ( V_5 -> V_6 , L_10 , V_11 ) ;
V_76:
F_30 ( V_39 -> V_70 , & V_5 -> V_71 ) ;
}
struct V_22 * F_31 ( struct V_77 * V_6 ,
struct V_78 * V_79 ,
int V_80 , int V_81 , int type )
{
struct V_22 * V_5 ;
int V_82 = V_81 == V_83 ;
if ( F_32 ( ! V_79 ) )
return NULL ;
F_33 ( & V_6 -> V_84 ) ;
F_34 (ep, &chip->ep_list, list) {
if ( V_5 -> V_80 == V_80 &&
V_5 -> V_85 == V_79 -> V_86 . V_87 &&
V_5 -> V_88 == V_79 -> V_86 . V_89 ) {
F_35 ( V_5 -> V_6 ,
L_11 ,
V_80 , V_5 -> V_85 , V_5 -> V_88 , V_5 ) ;
goto V_90;
}
}
F_35 ( V_6 , L_12 ,
V_82 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_80 ) ;
V_5 = F_36 ( sizeof( * V_5 ) , V_91 ) ;
if ( ! V_5 )
goto V_90;
V_5 -> V_6 = V_6 ;
F_37 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_80 = V_80 ;
V_5 -> V_85 = V_79 -> V_86 . V_87 ;
V_5 -> V_88 = V_79 -> V_86 . V_89 ;
F_38 ( & V_5 -> V_67 ) ;
V_80 &= V_92 ;
if ( V_82 )
V_5 -> V_25 = F_39 ( V_6 -> V_7 , V_80 ) ;
else
V_5 -> V_25 = F_40 ( V_6 -> V_7 , V_80 ) ;
if ( type == V_54 ) {
if ( F_41 ( V_79 , 1 ) -> V_93 >= V_94 &&
F_41 ( V_79 , 1 ) -> V_95 >= 1 &&
F_41 ( V_79 , 1 ) -> V_95 <= 9 )
V_5 -> V_96 = F_41 ( V_79 , 1 ) -> V_95 ;
else if ( F_18 ( V_6 -> V_7 ) == V_97 )
V_5 -> V_96 = 1 ;
else if ( F_41 ( V_79 , 1 ) -> V_98 >= 1 &&
F_41 ( V_79 , 1 ) -> V_98 <= 16 )
V_5 -> V_96 = F_41 ( V_79 , 1 ) -> V_98 - 1 ;
else
V_5 -> V_96 = 3 ;
V_5 -> V_58 = F_42 ( F_41 ( V_79 , 1 ) -> V_99 ) ;
if ( V_6 -> V_100 == F_43 ( 0x0644 , 0x8038 ) &&
V_5 -> V_58 == 4 )
V_5 -> V_101 = 1 ;
}
F_29 ( & V_5 -> V_102 , & V_6 -> V_103 ) ;
V_90:
F_44 ( & V_6 -> V_84 ) ;
return V_5 ;
}
static int F_45 ( struct V_22 * V_5 )
{
unsigned long V_104 = V_105 + F_46 ( 1000 ) ;
int V_106 ;
do {
V_106 = F_47 ( & V_5 -> V_71 , V_5 -> V_107 ) ;
if ( ! V_106 )
break;
F_48 ( 1 ) ;
} while ( F_49 ( V_105 , V_104 ) );
if ( V_106 )
F_26 ( V_5 -> V_6 ,
L_17 ,
V_106 , V_5 -> V_80 ) ;
F_30 ( V_108 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_50 ( struct V_22 * V_5 )
{
if ( V_5 && F_21 ( V_108 , & V_5 -> V_26 ) )
F_45 ( V_5 ) ;
}
static int F_51 ( struct V_22 * V_5 , bool V_109 )
{
unsigned int V_40 ;
if ( ! V_109 && V_5 -> V_6 -> V_75 )
return - V_110 ;
F_30 ( V_59 , & V_5 -> V_26 ) ;
F_38 ( & V_5 -> V_67 ) ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
if ( F_21 ( V_40 , & V_5 -> V_71 ) ) {
if ( ! F_52 ( V_40 , & V_5 -> V_111 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_40 ] . V_8 ;
F_53 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_54 ( struct V_22 * V_5 , int V_109 )
{
int V_40 ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_51 ( V_5 , V_109 ) ;
F_45 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ )
F_3 ( & V_5 -> V_8 [ V_40 ] ) ;
if ( V_5 -> V_112 )
F_4 ( V_5 -> V_6 -> V_7 , V_113 * 4 ,
V_5 -> V_112 , V_5 -> V_114 ) ;
V_5 -> V_112 = NULL ;
V_5 -> V_107 = 0 ;
}
static int F_55 ( struct V_22 * V_5 ,
T_1 V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
unsigned int V_123 , V_124 , V_125 , V_126 ;
unsigned int V_127 , V_128 , V_129 ;
unsigned int V_130 , V_40 ;
int V_131 = F_56 ( V_115 ) * V_116 ;
if ( V_115 == V_132 && V_121 -> V_133 ) {
V_131 += V_116 << 3 ;
}
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_49 = V_131 >> 3 ;
V_5 -> V_53 = V_115 == V_134 ? 0x80 : 0 ;
V_5 -> V_135 = V_5 -> V_56 + ( V_5 -> V_56 >> 2 ) ;
V_123 = ( ( V_5 -> V_135 + 0xffff ) * ( V_131 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
if ( V_5 -> V_136 && V_5 -> V_136 < V_123 ) {
V_123 = V_5 -> V_136 ;
V_5 -> V_135 = ( V_123 / ( V_131 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_57 = V_5 -> V_136 ;
else
V_5 -> V_57 = V_123 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_97 ) {
V_125 = 8 >> V_5 -> V_33 ;
V_126 = V_137 ;
} else {
V_125 = 1 ;
V_126 = V_138 ;
}
if ( V_122 && ! F_7 ( V_5 ) )
V_126 = F_11 ( V_126 ,
1U << V_122 -> V_96 ) ;
V_126 = F_57 ( 1u , V_126 >> V_5 -> V_33 ) ;
if ( F_58 ( V_5 -> V_25 ) ||
F_7 ( V_5 ) ) {
V_129 = V_125 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_139 ) {
int V_140 = V_5 -> V_33 ;
while ( V_140 < 5 ) {
V_129 <<= 1 ;
++ V_140 ;
}
}
V_129 = F_11 ( V_126 , V_129 ) ;
while ( V_129 > 1 && V_129 * V_123 >= V_117 )
V_129 >>= 1 ;
V_5 -> V_107 = V_66 ;
} else {
V_124 = ( V_5 -> V_56 >> ( 16 - V_5 -> V_33 ) ) *
( V_131 >> 3 ) ;
if ( V_122 )
V_124 -= V_124 >> 3 ;
V_124 = F_57 ( V_124 , 1u ) ;
V_127 = F_59 ( V_117 , V_124 ) ;
V_128 = F_59 ( V_127 ,
V_126 ) ;
V_129 = F_59 ( V_127 , V_128 ) ;
V_5 -> V_141 = F_59 ( V_118 ,
V_128 ) ;
V_130 = F_11 ( ( unsigned ) V_66 ,
V_142 * V_125 / V_129 ) ;
V_5 -> V_107 = F_11 ( V_130 , V_128 * V_119 ) ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_70 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = V_129 ;
V_3 -> V_4 = V_123 * V_3 -> V_44 ;
if ( V_121 -> V_143 == V_144 )
V_3 -> V_44 ++ ;
V_3 -> V_8 = F_60 ( V_3 -> V_44 , V_91 ) ;
if ( ! V_3 -> V_8 )
goto V_145;
V_3 -> V_8 -> V_9 =
F_61 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_91 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_145;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_146 = V_147 ;
V_3 -> V_8 -> V_140 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_148 = F_28 ;
F_38 ( & V_3 -> V_68 ) ;
}
return 0 ;
V_145:
F_54 ( V_5 , 0 ) ;
return - V_149 ;
}
static int F_62 ( struct V_22 * V_5 )
{
int V_40 ;
V_5 -> V_112 = F_61 ( V_5 -> V_6 -> V_7 , V_113 * 4 ,
V_91 , & V_5 -> V_114 ) ;
if ( ! V_5 -> V_112 )
return - V_149 ;
for ( V_40 = 0 ; V_40 < V_113 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_70 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = 1 ;
V_3 -> V_8 = F_60 ( 1 , V_91 ) ;
if ( ! V_3 -> V_8 )
goto V_145;
V_3 -> V_8 -> V_9 = V_5 -> V_112 + V_40 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_114 + V_40 * 4 ;
V_3 -> V_8 -> V_52 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_146 = V_147 ;
V_3 -> V_8 -> V_51 = 1 ;
V_3 -> V_8 -> V_140 = 1 << V_5 -> V_96 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_148 = F_28 ;
}
V_5 -> V_107 = V_113 ;
return 0 ;
V_145:
F_54 ( V_5 , 0 ) ;
return - V_149 ;
}
int F_63 ( struct V_22 * V_5 ,
T_1 V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_150 ,
unsigned int V_151 ,
unsigned int V_1 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
int V_11 ;
if ( V_5 -> V_152 != 0 ) {
F_64 ( V_5 -> V_6 ,
L_18 ,
V_5 -> V_80 ) ;
return - V_153 ;
}
F_54 ( V_5 , 0 ) ;
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_136 = V_121 -> V_136 ;
V_5 -> V_28 = ! ! ( V_121 -> V_154 & V_155 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_97 )
V_5 -> V_56 = F_1 ( V_1 ) ;
else
V_5 -> V_56 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_56 ;
V_5 -> V_156 = V_157 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_55 ( V_5 , V_115 , V_116 ,
V_117 , V_150 ,
V_151 , V_121 , V_122 ) ;
break;
case V_54 :
V_11 = F_62 ( V_5 ) ;
break;
default:
V_11 = - V_18 ;
}
F_35 ( V_5 -> V_6 ,
L_19 ,
V_5 -> V_80 , V_5 -> type , V_5 -> V_107 , V_11 ) ;
return V_11 ;
}
int F_65 ( struct V_22 * V_5 , bool V_158 )
{
int V_11 ;
unsigned int V_40 ;
if ( V_5 -> V_6 -> V_75 )
return - V_110 ;
if ( ++ V_5 -> V_152 != 1 )
return 0 ;
F_51 ( V_5 , false ) ;
if ( V_158 )
F_45 ( V_5 ) ;
V_5 -> V_71 = 0 ;
V_5 -> V_111 = 0 ;
V_5 -> V_31 = 0 ;
F_66 ( V_5 ) ;
F_27 ( V_59 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
struct V_2 * V_39 = V_5 -> V_8 + V_40 ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
}
return 0 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_40 ] . V_8 ;
if ( F_67 ( ! V_8 ) )
goto V_159;
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
goto V_159;
}
F_27 ( V_40 , & V_5 -> V_71 ) ;
}
return 0 ;
V_159:
F_30 ( V_59 , & V_5 -> V_26 ) ;
V_5 -> V_152 -- ;
F_51 ( V_5 , false ) ;
return - V_14 ;
}
void F_68 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_67 ( V_5 -> V_152 == 0 ) )
return;
if ( -- V_5 -> V_152 == 0 ) {
F_51 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_27 ( V_108 , & V_5 -> V_26 ) ;
}
}
void F_69 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( V_5 -> V_152 != 0 )
return;
F_51 ( V_5 , true ) ;
F_45 ( V_5 ) ;
}
void F_70 ( struct V_160 * V_161 )
{
struct V_22 * V_5 ;
V_5 = F_71 ( V_161 , struct V_22 , V_102 ) ;
F_54 ( V_5 , 1 ) ;
F_72 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_162 ,
const struct V_8 * V_8 )
{
int V_163 ;
unsigned int V_164 ;
unsigned long V_26 ;
F_67 ( V_5 == V_162 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_152 != 0 ) {
int V_40 , V_165 = 0 ;
struct V_2 * V_166 ;
struct V_60 * V_167 ;
V_166 = V_8 -> V_72 ;
for ( V_40 = 0 ; V_40 < V_166 -> V_44 ; V_40 ++ )
if ( V_8 -> V_47 [ V_40 ] . V_73 == 0 )
V_165 += V_8 -> V_47 [ V_40 ] . V_168 ;
if ( V_165 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_167 = V_5 -> V_65 + V_5 -> V_64 ;
V_167 -> V_44 = V_166 -> V_44 ;
for ( V_40 = 0 ; V_40 < V_166 -> V_44 ; V_40 ++ ) {
if ( V_8 -> V_47 [ V_40 ] . V_73 == 0 )
V_167 -> V_46 [ V_40 ] =
V_8 -> V_47 [ V_40 ] . V_168 / V_162 -> V_49 ;
else
V_167 -> V_46 [ V_40 ] = 0 ;
}
V_5 -> V_64 ++ ;
V_5 -> V_64 %= V_66 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
return;
}
if ( V_8 -> V_47 [ 0 ] . V_73 != 0 ||
V_8 -> V_47 [ 0 ] . V_168 < 3 )
return;
V_164 = F_73 ( V_8 -> V_9 ) ;
if ( V_8 -> V_47 [ 0 ] . V_168 == 3 )
V_164 &= 0x00ffffff ;
else
V_164 &= 0x0fffffff ;
if ( V_164 == 0 )
return;
if ( F_15 ( V_162 -> V_101 ) ) {
if ( V_164 < V_5 -> V_56 - 0x8000 )
V_164 += 0x10000 ;
else if ( V_164 > V_5 -> V_56 + 0x8000 )
V_164 -= 0x10000 ;
} else if ( F_15 ( V_5 -> V_156 == V_157 ) ) {
V_163 = 0 ;
while ( V_164 < V_5 -> V_56 - V_5 -> V_56 / 4 ) {
V_164 <<= 1 ;
V_163 ++ ;
}
while ( V_164 > V_5 -> V_56 + V_5 -> V_56 / 2 ) {
V_164 >>= 1 ;
V_163 -- ;
}
V_5 -> V_156 = V_163 ;
} else if ( V_5 -> V_156 >= 0 )
V_164 <<= V_5 -> V_156 ;
else
V_164 >>= - V_5 -> V_156 ;
if ( F_74 ( V_164 >= V_5 -> V_56 - V_5 -> V_56 / 8 && V_164 <= V_5 -> V_135 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_164 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_156 = V_157 ;
}
}
