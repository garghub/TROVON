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
F_26 ( V_70 L_9 ,
V_39 -> V_71 , V_11 , V_39 -> V_8 ) ;
else
F_27 ( V_39 -> V_71 , & V_5 -> V_72 ) ;
}
}
static void F_28 ( struct V_8 * V_8 )
{
struct V_2 * V_39 = V_8 -> V_73 ;
struct V_22 * V_5 = V_39 -> V_5 ;
int V_11 ;
if ( F_15 ( V_8 -> V_74 == - V_13 ||
V_8 -> V_74 == - V_12 ||
V_8 -> V_74 == - V_75 ||
V_8 -> V_74 == - V_16 ||
V_5 -> V_6 -> V_76 ) )
goto V_77;
if ( F_8 ( V_5 -> V_25 ) ) {
F_13 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_77;
if ( F_7 ( V_5 ) ) {
unsigned long V_26 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
goto V_77;
}
F_17 ( V_5 , V_39 ) ;
} else {
F_14 ( V_5 , V_39 ) ;
if ( F_15 ( ! F_21 ( V_59 , & V_5 -> V_26 ) ) )
goto V_77;
F_19 ( V_5 , V_39 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 == 0 )
return;
F_26 ( V_70 L_10 , V_11 ) ;
V_77:
F_30 ( V_39 -> V_71 , & V_5 -> V_72 ) ;
}
struct V_22 * F_31 ( struct V_78 * V_6 ,
struct V_79 * V_80 ,
int V_81 , int V_82 , int type )
{
struct V_83 * V_84 ;
struct V_22 * V_5 ;
int V_85 = V_82 == V_86 ;
F_32 ( & V_6 -> V_87 ) ;
F_33 (p, &chip->ep_list) {
V_5 = F_34 ( V_84 , struct V_22 , V_88 ) ;
if ( V_5 -> V_81 == V_81 &&
V_5 -> V_89 == V_80 -> V_90 . V_91 &&
V_5 -> V_92 == V_80 -> V_90 . V_93 ) {
F_35 ( V_94 L_11 ,
V_81 , V_5 -> V_89 , V_5 -> V_92 , V_5 ) ;
goto V_95;
}
}
F_35 ( V_94 L_12 ,
V_85 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_81 ) ;
V_5 = F_36 ( sizeof( * V_5 ) , V_96 ) ;
if ( ! V_5 )
goto V_95;
V_5 -> V_6 = V_6 ;
F_37 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_81 = V_81 ;
V_5 -> V_89 = V_80 -> V_90 . V_91 ;
V_5 -> V_92 = V_80 -> V_90 . V_93 ;
F_38 ( & V_5 -> V_67 ) ;
V_81 &= V_97 ;
if ( V_85 )
V_5 -> V_25 = F_39 ( V_6 -> V_7 , V_81 ) ;
else
V_5 -> V_25 = F_40 ( V_6 -> V_7 , V_81 ) ;
if ( type == V_54 ) {
if ( F_41 ( V_80 , 1 ) -> V_98 >= V_99 &&
F_41 ( V_80 , 1 ) -> V_100 >= 1 &&
F_41 ( V_80 , 1 ) -> V_100 <= 9 )
V_5 -> V_101 = F_41 ( V_80 , 1 ) -> V_100 ;
else if ( F_18 ( V_6 -> V_7 ) == V_102 )
V_5 -> V_101 = 1 ;
else if ( F_41 ( V_80 , 1 ) -> V_103 >= 1 &&
F_41 ( V_80 , 1 ) -> V_103 <= 16 )
V_5 -> V_101 = F_41 ( V_80 , 1 ) -> V_103 - 1 ;
else
V_5 -> V_101 = 3 ;
V_5 -> V_58 = F_42 ( F_41 ( V_80 , 1 ) -> V_104 ) ;
}
F_29 ( & V_5 -> V_88 , & V_6 -> V_105 ) ;
V_95:
F_43 ( & V_6 -> V_87 ) ;
return V_5 ;
}
static int F_44 ( struct V_22 * V_5 )
{
unsigned long V_106 = V_107 + F_45 ( 1000 ) ;
unsigned int V_40 ;
int V_108 ;
do {
V_108 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ )
if ( F_21 ( V_40 , & V_5 -> V_72 ) )
V_108 ++ ;
if ( ! V_108 )
break;
F_46 ( 1 ) ;
} while ( F_47 ( V_107 , V_106 ) );
if ( V_108 )
F_26 ( V_70 L_17 ,
V_108 , V_5 -> V_81 ) ;
F_30 ( V_110 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_48 ( struct V_22 * V_5 )
{
if ( V_5 && F_21 ( V_110 , & V_5 -> V_26 ) )
F_44 ( V_5 ) ;
}
static int F_49 ( struct V_22 * V_5 , int V_111 , int V_112 )
{
unsigned int V_40 ;
int V_113 ;
if ( ! V_111 && V_5 -> V_6 -> V_76 )
return - V_114 ;
V_113 = ! V_112 && V_5 -> V_6 -> V_115 ;
F_30 ( V_59 , & V_5 -> V_26 ) ;
F_38 ( & V_5 -> V_67 ) ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
if ( ! V_113 && F_50 () )
return 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
if ( F_21 ( V_40 , & V_5 -> V_72 ) ) {
if ( ! F_51 ( V_40 , & V_5 -> V_116 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_40 ] . V_8 ;
if ( V_113 )
F_52 ( V_3 ) ;
else
F_53 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_54 ( struct V_22 * V_5 , int V_111 )
{
int V_40 ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_49 ( V_5 , V_111 , 1 ) ;
F_44 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ )
F_3 ( & V_5 -> V_8 [ V_40 ] ) ;
if ( V_5 -> V_117 )
F_4 ( V_5 -> V_6 -> V_7 , V_118 * 4 ,
V_5 -> V_117 , V_5 -> V_119 ) ;
V_5 -> V_117 = NULL ;
V_5 -> V_109 = 0 ;
}
static int F_55 ( struct V_22 * V_5 ,
T_1 V_120 ,
unsigned int V_121 ,
unsigned int V_122 ,
struct V_123 * V_124 ,
struct V_22 * V_125 )
{
unsigned int V_126 , V_40 , V_127 , V_128 , V_129 ;
int V_85 = F_8 ( V_5 -> V_25 ) ;
int V_130 = F_56 ( V_120 ) * V_121 ;
V_5 -> V_33 = V_124 -> V_33 ;
V_5 -> V_49 = V_130 >> 3 ;
V_5 -> V_53 = V_120 == V_131 ? 0x80 : 0 ;
if ( V_5 -> V_132 ) {
V_126 = V_5 -> V_132 ;
V_5 -> V_133 = ( V_126 / ( V_130 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
} else {
V_5 -> V_133 = V_5 -> V_56 + ( V_5 -> V_56 >> 2 ) ;
V_126 = ( ( V_5 -> V_133 + 0xffff ) * ( V_130 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_57 = V_5 -> V_132 ;
else
V_5 -> V_57 = V_126 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_102 )
V_129 = 8 >> V_5 -> V_33 ;
else
V_129 = 1 ;
if ( V_85 && ! F_7 ( V_5 ) ) {
V_127 = F_57 ( V_5 -> V_6 -> V_134 , 1 ) ;
V_127 = F_11 ( V_127 , ( unsigned int ) V_135 ) ;
} else {
V_127 = 1 ;
}
V_127 *= V_129 ;
if ( V_125 && ! F_7 ( V_5 ) )
V_127 = F_11 ( V_127 , 1U << V_125 -> V_101 ) ;
if ( V_85 && ! F_7 ( V_5 ) ) {
unsigned int V_136 , V_137 ;
V_136 = ( V_5 -> V_56 >> ( 16 - V_5 -> V_33 ) )
* ( V_130 >> 3 ) ;
if ( V_125 )
V_136 -= V_136 >> 3 ;
V_136 = F_57 ( V_136 , 1u ) ;
V_128 = ( V_122 + V_136 - 1 ) / V_136 ;
if ( V_128 < 2 ) {
V_128 = 2 ;
} else {
V_137 = F_57 ( V_138 * V_129 , V_127 * 2 ) ;
V_128 = F_11 ( V_128 , V_137 ) ;
}
} else {
while ( V_127 > 1 && V_127 * V_126 >= V_122 )
V_127 >>= 1 ;
V_128 = V_66 * V_127 ;
}
V_5 -> V_109 = ( V_128 + V_127 - 1 ) / V_127 ;
if ( V_5 -> V_109 > V_66 ) {
V_5 -> V_109 = V_66 ;
V_128 = V_66 * V_127 ;
} else if ( V_5 -> V_109 < 2 ) {
V_5 -> V_109 = 2 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = ( V_40 + 1 ) * V_128 / V_5 -> V_109
- V_40 * V_128 / V_5 -> V_109 ;
V_3 -> V_4 = V_126 * V_3 -> V_44 ;
if ( V_124 -> V_139 == V_140 )
V_3 -> V_44 ++ ;
V_3 -> V_8 = F_58 ( V_3 -> V_44 , V_96 ) ;
if ( ! V_3 -> V_8 )
goto V_141;
V_3 -> V_8 -> V_9 =
F_59 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_96 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_141;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_142 = V_143 | V_144 ;
V_3 -> V_8 -> V_145 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_146 = F_28 ;
F_38 ( & V_3 -> V_68 ) ;
}
return 0 ;
V_141:
F_54 ( V_5 , 0 ) ;
return - V_147 ;
}
static int F_60 ( struct V_22 * V_5 ,
struct V_123 * V_124 )
{
int V_40 ;
V_5 -> V_117 = F_59 ( V_5 -> V_6 -> V_7 , V_118 * 4 ,
V_96 , & V_5 -> V_119 ) ;
if ( ! V_5 -> V_117 )
return - V_147 ;
for ( V_40 = 0 ; V_40 < V_118 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = 1 ;
V_3 -> V_8 = F_58 ( 1 , V_96 ) ;
if ( ! V_3 -> V_8 )
goto V_141;
V_3 -> V_8 -> V_9 = V_5 -> V_117 + V_40 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_119 + V_40 * 4 ;
V_3 -> V_8 -> V_52 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_142 = V_143 |
V_144 ;
V_3 -> V_8 -> V_51 = 1 ;
V_3 -> V_8 -> V_145 = 1 << V_5 -> V_101 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_146 = F_28 ;
}
V_5 -> V_109 = V_118 ;
return 0 ;
V_141:
F_54 ( V_5 , 0 ) ;
return - V_147 ;
}
int F_61 ( struct V_22 * V_5 ,
T_1 V_120 ,
unsigned int V_121 ,
unsigned int V_122 ,
unsigned int V_1 ,
struct V_123 * V_124 ,
struct V_22 * V_125 )
{
int V_11 ;
if ( V_5 -> V_148 != 0 ) {
F_26 ( V_149 L_18 ,
V_5 -> V_81 ) ;
return - V_150 ;
}
F_54 ( V_5 , 0 ) ;
V_5 -> V_33 = V_124 -> V_33 ;
V_5 -> V_132 = V_124 -> V_132 ;
V_5 -> V_28 = ! ! ( V_124 -> V_151 & V_152 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_102 )
V_5 -> V_56 = F_1 ( V_1 ) ;
else
V_5 -> V_56 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_56 ;
V_5 -> V_153 = V_154 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_55 ( V_5 , V_120 , V_121 ,
V_122 , V_124 , V_125 ) ;
break;
case V_54 :
V_11 = F_60 ( V_5 , V_124 ) ;
break;
default:
V_11 = - V_18 ;
}
F_35 ( V_94 L_19 ,
V_5 -> V_81 , V_5 -> type , V_5 -> V_109 , V_11 ) ;
return V_11 ;
}
int F_62 ( struct V_22 * V_5 , int V_112 )
{
int V_11 ;
unsigned int V_40 ;
if ( V_5 -> V_6 -> V_76 )
return - V_114 ;
if ( ++ V_5 -> V_148 != 1 )
return 0 ;
F_49 ( V_5 , 0 , V_112 ) ;
if ( V_112 )
F_44 ( V_5 ) ;
V_5 -> V_72 = 0 ;
V_5 -> V_116 = 0 ;
V_5 -> V_31 = 0 ;
F_63 ( V_5 ) ;
F_27 ( V_59 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
struct V_2 * V_39 = V_5 -> V_8 + V_40 ;
F_29 ( & V_39 -> V_68 , & V_5 -> V_67 ) ;
}
return 0 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_40 ] . V_8 ;
if ( F_64 ( ! V_8 ) )
goto V_155;
if ( F_8 ( V_5 -> V_25 ) ) {
F_17 ( V_5 , V_8 -> V_73 ) ;
} else {
F_19 ( V_5 , V_8 -> V_73 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 < 0 ) {
F_26 ( V_70 L_20 ,
V_40 , V_11 , F_6 ( V_11 ) ) ;
goto V_155;
}
F_27 ( V_40 , & V_5 -> V_72 ) ;
}
return 0 ;
V_155:
F_30 ( V_59 , & V_5 -> V_26 ) ;
V_5 -> V_148 -- ;
F_49 ( V_5 , 0 , 0 ) ;
return - V_14 ;
}
void F_65 ( struct V_22 * V_5 ,
int V_111 , int V_112 , int V_156 )
{
if ( ! V_5 )
return;
if ( F_64 ( V_5 -> V_148 == 0 ) )
return;
if ( -- V_5 -> V_148 == 0 ) {
F_49 ( V_5 , V_111 , V_112 ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
if ( V_156 )
F_44 ( V_5 ) ;
else
F_27 ( V_110 , & V_5 -> V_26 ) ;
}
}
int F_66 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return - V_18 ;
F_49 ( V_5 , 1 , 1 ) ;
F_44 ( V_5 ) ;
if ( V_5 -> V_148 != 0 )
return 0 ;
F_30 ( V_157 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_67 ( struct V_83 * V_158 )
{
struct V_22 * V_5 ;
V_5 = F_34 ( V_158 , struct V_22 , V_88 ) ;
F_54 ( V_5 , 1 ) ;
F_68 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_159 ,
const struct V_8 * V_8 )
{
int V_160 ;
unsigned int V_161 ;
unsigned long V_26 ;
F_64 ( V_5 == V_159 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_148 != 0 ) {
int V_40 , V_162 = 0 ;
struct V_2 * V_163 ;
struct V_60 * V_164 ;
V_163 = V_8 -> V_73 ;
for ( V_40 = 0 ; V_40 < V_163 -> V_44 ; V_40 ++ )
if ( V_8 -> V_47 [ V_40 ] . V_74 == 0 )
V_162 += V_8 -> V_47 [ V_40 ] . V_165 ;
if ( V_162 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_164 = V_5 -> V_65 + V_5 -> V_64 ;
V_164 -> V_44 = V_163 -> V_44 ;
for ( V_40 = 0 ; V_40 < V_163 -> V_44 ; V_40 ++ ) {
if ( V_8 -> V_47 [ V_40 ] . V_74 == 0 )
V_164 -> V_46 [ V_40 ] =
V_8 -> V_47 [ V_40 ] . V_165 / V_5 -> V_49 ;
else
V_164 -> V_46 [ V_40 ] = 0 ;
}
V_5 -> V_64 ++ ;
V_5 -> V_64 %= V_66 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
return;
}
if ( V_8 -> V_47 [ 0 ] . V_74 != 0 ||
V_8 -> V_47 [ 0 ] . V_165 < 3 )
return;
V_161 = F_69 ( V_8 -> V_9 ) ;
if ( V_8 -> V_47 [ 0 ] . V_165 == 3 )
V_161 &= 0x00ffffff ;
else
V_161 &= 0x0fffffff ;
if ( V_161 == 0 )
return;
if ( F_15 ( V_5 -> V_153 == V_154 ) ) {
V_160 = 0 ;
while ( V_161 < V_5 -> V_56 - V_5 -> V_56 / 4 ) {
V_161 <<= 1 ;
V_160 ++ ;
}
while ( V_161 > V_5 -> V_56 + V_5 -> V_56 / 2 ) {
V_161 >>= 1 ;
V_160 -- ;
}
V_5 -> V_153 = V_160 ;
} else if ( V_5 -> V_153 >= 0 )
V_161 <<= V_5 -> V_153 ;
else
V_161 >>= - V_5 -> V_153 ;
if ( F_70 ( V_161 >= V_5 -> V_56 - V_5 -> V_56 / 8 && V_161 <= V_5 -> V_133 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_161 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_153 = V_154 ;
}
}
