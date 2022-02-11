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
int V_108 ;
do {
V_108 = F_46 ( & V_5 -> V_72 , V_5 -> V_109 ) ;
if ( ! V_108 )
break;
F_47 ( 1 ) ;
} while ( F_48 ( V_107 , V_106 ) );
if ( V_108 )
F_26 ( V_70 L_17 ,
V_108 , V_5 -> V_81 ) ;
F_30 ( V_110 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_49 ( struct V_22 * V_5 )
{
if ( V_5 && F_21 ( V_110 , & V_5 -> V_26 ) )
F_44 ( V_5 ) ;
}
static int F_50 ( struct V_22 * V_5 , bool V_111 )
{
unsigned int V_40 ;
if ( ! V_111 && V_5 -> V_6 -> V_76 )
return - V_112 ;
F_30 ( V_59 , & V_5 -> V_26 ) ;
F_38 ( & V_5 -> V_67 ) ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
if ( F_21 ( V_40 , & V_5 -> V_72 ) ) {
if ( ! F_51 ( V_40 , & V_5 -> V_113 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_40 ] . V_8 ;
F_52 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_53 ( struct V_22 * V_5 , int V_111 )
{
int V_40 ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_50 ( V_5 , V_111 ) ;
F_44 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ )
F_3 ( & V_5 -> V_8 [ V_40 ] ) ;
if ( V_5 -> V_114 )
F_4 ( V_5 -> V_6 -> V_7 , V_115 * 4 ,
V_5 -> V_114 , V_5 -> V_116 ) ;
V_5 -> V_114 = NULL ;
V_5 -> V_109 = 0 ;
}
static int F_54 ( struct V_22 * V_5 ,
T_1 V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
unsigned int V_123 , V_40 , V_124 , V_125 , V_126 ;
int V_85 = F_8 ( V_5 -> V_25 ) ;
int V_127 = F_55 ( V_117 ) * V_118 ;
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_49 = V_127 >> 3 ;
V_5 -> V_53 = V_117 == V_128 ? 0x80 : 0 ;
if ( V_5 -> V_129 ) {
V_123 = V_5 -> V_129 ;
V_5 -> V_130 = ( V_123 / ( V_127 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
} else {
V_5 -> V_130 = V_5 -> V_56 + ( V_5 -> V_56 >> 2 ) ;
V_123 = ( ( V_5 -> V_130 + 0xffff ) * ( V_127 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_57 = V_5 -> V_129 ;
else
V_5 -> V_57 = V_123 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_102 )
V_126 = 8 >> V_5 -> V_33 ;
else
V_126 = 1 ;
if ( V_85 && ! F_7 ( V_5 ) ) {
V_124 = F_56 ( V_5 -> V_6 -> V_131 , 1 ) ;
V_124 = F_11 ( V_124 , ( unsigned int ) V_132 ) ;
} else {
V_124 = 1 ;
}
V_124 *= V_126 ;
if ( V_122 && ! F_7 ( V_5 ) )
V_124 = F_11 ( V_124 , 1U << V_122 -> V_101 ) ;
if ( V_85 && ! F_7 ( V_5 ) ) {
unsigned int V_133 , V_134 ;
V_133 = ( V_5 -> V_56 >> ( 16 - V_5 -> V_33 ) )
* ( V_127 >> 3 ) ;
if ( V_122 )
V_133 -= V_133 >> 3 ;
V_133 = F_56 ( V_133 , 1u ) ;
V_125 = ( V_119 + V_133 - 1 ) / V_133 ;
if ( V_125 < 2 ) {
V_125 = 2 ;
} else {
V_134 = F_56 ( V_135 * V_126 , V_124 * 2 ) ;
V_125 = F_11 ( V_125 , V_134 ) ;
}
} else {
while ( V_124 > 1 && V_124 * V_123 >= V_119 )
V_124 >>= 1 ;
V_125 = V_66 * V_124 ;
}
V_5 -> V_109 = ( V_125 + V_124 - 1 ) / V_124 ;
if ( V_5 -> V_109 > V_66 ) {
V_5 -> V_109 = V_66 ;
V_125 = V_66 * V_124 ;
} else if ( V_5 -> V_109 < 2 ) {
V_5 -> V_109 = 2 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_109 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = ( V_40 + 1 ) * V_125 / V_5 -> V_109
- V_40 * V_125 / V_5 -> V_109 ;
V_3 -> V_4 = V_123 * V_3 -> V_44 ;
if ( V_121 -> V_136 == V_137 )
V_3 -> V_44 ++ ;
V_3 -> V_8 = F_57 ( V_3 -> V_44 , V_96 ) ;
if ( ! V_3 -> V_8 )
goto V_138;
V_3 -> V_8 -> V_9 =
F_58 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_96 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_138;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_139 = V_140 | V_141 ;
V_3 -> V_8 -> V_142 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_143 = F_28 ;
F_38 ( & V_3 -> V_68 ) ;
}
return 0 ;
V_138:
F_53 ( V_5 , 0 ) ;
return - V_144 ;
}
static int F_59 ( struct V_22 * V_5 ,
struct V_120 * V_121 )
{
int V_40 ;
V_5 -> V_114 = F_58 ( V_5 -> V_6 -> V_7 , V_115 * 4 ,
V_96 , & V_5 -> V_116 ) ;
if ( ! V_5 -> V_114 )
return - V_144 ;
for ( V_40 = 0 ; V_40 < V_115 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = 1 ;
V_3 -> V_8 = F_57 ( 1 , V_96 ) ;
if ( ! V_3 -> V_8 )
goto V_138;
V_3 -> V_8 -> V_9 = V_5 -> V_114 + V_40 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_116 + V_40 * 4 ;
V_3 -> V_8 -> V_52 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_139 = V_140 |
V_141 ;
V_3 -> V_8 -> V_51 = 1 ;
V_3 -> V_8 -> V_142 = 1 << V_5 -> V_101 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_143 = F_28 ;
}
V_5 -> V_109 = V_115 ;
return 0 ;
V_138:
F_53 ( V_5 , 0 ) ;
return - V_144 ;
}
int F_60 ( struct V_22 * V_5 ,
T_1 V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
unsigned int V_1 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
int V_11 ;
if ( V_5 -> V_145 != 0 ) {
F_26 ( V_146 L_18 ,
V_5 -> V_81 ) ;
return - V_147 ;
}
F_53 ( V_5 , 0 ) ;
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_129 = V_121 -> V_129 ;
V_5 -> V_28 = ! ! ( V_121 -> V_148 & V_149 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_102 )
V_5 -> V_56 = F_1 ( V_1 ) ;
else
V_5 -> V_56 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_56 ;
V_5 -> V_150 = V_151 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_54 ( V_5 , V_117 , V_118 ,
V_119 , V_121 , V_122 ) ;
break;
case V_54 :
V_11 = F_59 ( V_5 , V_121 ) ;
break;
default:
V_11 = - V_18 ;
}
F_35 ( V_94 L_19 ,
V_5 -> V_81 , V_5 -> type , V_5 -> V_109 , V_11 ) ;
return V_11 ;
}
int F_61 ( struct V_22 * V_5 , bool V_152 )
{
int V_11 ;
unsigned int V_40 ;
if ( V_5 -> V_6 -> V_76 )
return - V_112 ;
if ( ++ V_5 -> V_145 != 1 )
return 0 ;
F_50 ( V_5 , false ) ;
if ( V_152 )
F_44 ( V_5 ) ;
V_5 -> V_72 = 0 ;
V_5 -> V_113 = 0 ;
V_5 -> V_31 = 0 ;
F_62 ( V_5 ) ;
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
if ( F_63 ( ! V_8 ) )
goto V_153;
if ( F_8 ( V_5 -> V_25 ) ) {
F_17 ( V_5 , V_8 -> V_73 ) ;
} else {
F_19 ( V_5 , V_8 -> V_73 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 < 0 ) {
F_26 ( V_70 L_20 ,
V_40 , V_11 , F_6 ( V_11 ) ) ;
goto V_153;
}
F_27 ( V_40 , & V_5 -> V_72 ) ;
}
return 0 ;
V_153:
F_30 ( V_59 , & V_5 -> V_26 ) ;
V_5 -> V_145 -- ;
F_50 ( V_5 , false ) ;
return - V_14 ;
}
void F_64 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_63 ( V_5 -> V_145 == 0 ) )
return;
if ( -- V_5 -> V_145 == 0 ) {
F_50 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_27 ( V_110 , & V_5 -> V_26 ) ;
}
}
int F_65 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return - V_18 ;
F_50 ( V_5 , true ) ;
F_44 ( V_5 ) ;
if ( V_5 -> V_145 != 0 )
return 0 ;
F_30 ( V_154 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_66 ( struct V_83 * V_155 )
{
struct V_22 * V_5 ;
V_5 = F_34 ( V_155 , struct V_22 , V_88 ) ;
F_53 ( V_5 , 1 ) ;
F_67 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_156 ,
const struct V_8 * V_8 )
{
int V_157 ;
unsigned int V_158 ;
unsigned long V_26 ;
F_63 ( V_5 == V_156 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_145 != 0 ) {
int V_40 , V_159 = 0 ;
struct V_2 * V_160 ;
struct V_60 * V_161 ;
V_160 = V_8 -> V_73 ;
for ( V_40 = 0 ; V_40 < V_160 -> V_44 ; V_40 ++ )
if ( V_8 -> V_47 [ V_40 ] . V_74 == 0 )
V_159 += V_8 -> V_47 [ V_40 ] . V_162 ;
if ( V_159 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_161 = V_5 -> V_65 + V_5 -> V_64 ;
V_161 -> V_44 = V_160 -> V_44 ;
for ( V_40 = 0 ; V_40 < V_160 -> V_44 ; V_40 ++ ) {
if ( V_8 -> V_47 [ V_40 ] . V_74 == 0 )
V_161 -> V_46 [ V_40 ] =
V_8 -> V_47 [ V_40 ] . V_162 / V_156 -> V_49 ;
else
V_161 -> V_46 [ V_40 ] = 0 ;
}
V_5 -> V_64 ++ ;
V_5 -> V_64 %= V_66 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
return;
}
if ( V_8 -> V_47 [ 0 ] . V_74 != 0 ||
V_8 -> V_47 [ 0 ] . V_162 < 3 )
return;
V_158 = F_68 ( V_8 -> V_9 ) ;
if ( V_8 -> V_47 [ 0 ] . V_162 == 3 )
V_158 &= 0x00ffffff ;
else
V_158 &= 0x0fffffff ;
if ( V_158 == 0 )
return;
if ( F_15 ( V_5 -> V_150 == V_151 ) ) {
V_157 = 0 ;
while ( V_158 < V_5 -> V_56 - V_5 -> V_56 / 4 ) {
V_158 <<= 1 ;
V_157 ++ ;
}
while ( V_158 > V_5 -> V_56 + V_5 -> V_56 / 2 ) {
V_158 >>= 1 ;
V_157 -- ;
}
V_5 -> V_150 = V_157 ;
} else if ( V_5 -> V_150 >= 0 )
V_158 <<= V_5 -> V_150 ;
else
V_158 >>= - V_5 -> V_150 ;
if ( F_69 ( V_158 >= V_5 -> V_56 - V_5 -> V_56 / 8 && V_158 <= V_5 -> V_130 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_158 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_150 = V_151 ;
}
}
