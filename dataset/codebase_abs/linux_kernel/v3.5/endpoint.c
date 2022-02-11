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
static int F_9 ( struct V_22 * V_5 )
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
if ( V_5 -> V_37 )
F_15 ( V_5 -> V_37 , V_5 , V_8 ) ;
if ( V_5 -> V_35 )
V_5 -> V_35 ( V_5 -> V_36 , V_8 ) ;
}
static void F_16 ( struct V_22 * V_5 ,
struct V_2 * V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_40 ; ++ V_39 )
V_38 -> V_41 [ V_39 ] = F_9 ( V_5 ) ;
}
static void F_17 ( struct V_22 * V_5 ,
struct V_2 * V_38 )
{
int V_39 ;
struct V_8 * V_8 = V_38 -> V_8 ;
unsigned char * V_42 = V_8 -> V_9 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
if ( V_5 -> V_43 ) {
V_5 -> V_43 ( V_5 -> V_36 , V_8 ) ;
} else {
unsigned int V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_40 ; ++ V_39 ) {
int V_45 = V_38 -> V_41 [ V_39 ] ;
V_8 -> V_46 [ V_39 ] . V_47 = V_44 * V_5 -> V_48 ;
V_8 -> V_46 [ V_39 ] . V_49 = V_45 * V_5 -> V_48 ;
V_44 += V_45 ;
}
V_8 -> V_50 = V_38 -> V_40 ;
V_8 -> V_51 = V_44 * V_5 -> V_48 ;
memset ( V_8 -> V_9 , V_5 -> V_52 ,
V_44 * V_5 -> V_48 ) ;
}
break;
case V_53 :
if ( F_18 ( V_5 -> V_6 -> V_7 ) >= V_54 ) {
V_8 -> V_46 [ 0 ] . V_49 = 4 ;
V_8 -> V_46 [ 0 ] . V_47 = 0 ;
V_42 [ 0 ] = V_5 -> V_55 ;
V_42 [ 1 ] = V_5 -> V_55 >> 8 ;
V_42 [ 2 ] = V_5 -> V_55 >> 16 ;
V_42 [ 3 ] = V_5 -> V_55 >> 24 ;
} else {
V_8 -> V_46 [ 0 ] . V_49 = 3 ;
V_8 -> V_46 [ 0 ] . V_47 = 0 ;
V_42 [ 0 ] = V_5 -> V_55 >> 2 ;
V_42 [ 1 ] = V_5 -> V_55 >> 10 ;
V_42 [ 2 ] = V_5 -> V_55 >> 18 ;
}
break;
}
}
static inline void F_19 ( struct V_22 * V_5 ,
struct V_2 * V_34 )
{
int V_39 , V_44 ;
struct V_8 * V_8 = V_34 -> V_8 ;
V_8 -> V_7 = V_5 -> V_6 -> V_7 ;
switch ( V_5 -> type ) {
case V_24 :
V_44 = 0 ;
for ( V_39 = 0 ; V_39 < V_34 -> V_40 ; V_39 ++ ) {
V_8 -> V_46 [ V_39 ] . V_47 = V_44 ;
V_8 -> V_46 [ V_39 ] . V_49 = V_5 -> V_56 ;
V_44 += V_5 -> V_56 ;
}
V_8 -> V_51 = V_44 ;
V_8 -> V_50 = V_34 -> V_40 ;
break;
case V_53 :
V_8 -> V_46 [ 0 ] . V_49 = F_11 ( 4u , V_5 -> V_57 ) ;
V_8 -> V_46 [ 0 ] . V_47 = 0 ;
break;
}
}
static void F_20 ( struct V_22 * V_5 )
{
while ( F_21 ( V_58 , & V_5 -> V_26 ) ) {
unsigned long V_26 ;
struct V_59 * V_60 ( V_61 ) ;
struct V_2 * V_38 = NULL ;
struct V_8 * V_8 ;
int V_11 , V_39 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
if ( V_5 -> V_62 != V_5 -> V_63 ) {
V_61 = V_5 -> V_64 + V_5 -> V_62 ;
V_5 -> V_62 ++ ;
V_5 -> V_62 %= V_65 ;
if ( ! F_22 ( & V_5 -> V_66 ) )
V_38 = F_23 ( & V_5 -> V_66 ,
struct V_2 , V_67 ) ;
}
F_12 ( & V_5 -> V_30 , V_26 ) ;
if ( V_38 == NULL )
return;
F_24 ( & V_38 -> V_67 ) ;
V_8 = V_38 -> V_8 ;
for ( V_39 = 0 ; V_39 < V_61 -> V_40 ; V_39 ++ )
V_38 -> V_41 [ V_39 ] = V_61 -> V_41 [ V_39 ] ;
F_17 ( V_5 , V_38 ) ;
V_11 = F_25 ( V_38 -> V_8 , V_68 ) ;
if ( V_11 < 0 )
F_26 ( V_69 L_9 ,
V_38 -> V_70 , V_11 , V_38 -> V_8 ) ;
else
F_27 ( V_38 -> V_70 , & V_5 -> V_71 ) ;
}
}
static void F_28 ( struct V_8 * V_8 )
{
struct V_2 * V_38 = V_8 -> V_72 ;
struct V_22 * V_5 = V_38 -> V_5 ;
int V_11 ;
if ( F_29 ( V_8 -> V_73 == - V_13 ||
V_8 -> V_73 == - V_12 ||
V_8 -> V_73 == - V_74 ||
V_8 -> V_73 == - V_16 ||
V_5 -> V_6 -> V_75 ) )
goto V_76;
if ( F_8 ( V_5 -> V_25 ) ) {
F_13 ( V_5 , V_38 ) ;
if ( F_29 ( ! F_21 ( V_58 , & V_5 -> V_26 ) ) )
goto V_76;
if ( F_7 ( V_5 ) ) {
unsigned long V_26 ;
F_10 ( & V_5 -> V_30 , V_26 ) ;
F_30 ( & V_38 -> V_67 , & V_5 -> V_66 ) ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
goto V_76;
}
F_16 ( V_5 , V_38 ) ;
F_17 ( V_5 , V_38 ) ;
} else {
F_14 ( V_5 , V_38 ) ;
if ( F_29 ( ! F_21 ( V_58 , & V_5 -> V_26 ) ) )
goto V_76;
F_19 ( V_5 , V_38 ) ;
}
V_11 = F_25 ( V_8 , V_68 ) ;
if ( V_11 == 0 )
return;
F_26 ( V_69 L_10 , V_11 ) ;
V_76:
F_31 ( V_38 -> V_70 , & V_5 -> V_71 ) ;
}
struct V_22 * F_32 ( struct V_77 * V_6 ,
struct V_78 * V_79 ,
int V_80 , int V_81 , int type )
{
struct V_82 * V_83 ;
struct V_22 * V_5 ;
int V_84 = V_81 == V_85 ;
F_33 ( & V_6 -> V_86 ) ;
F_34 (p, &chip->ep_list) {
V_5 = F_35 ( V_83 , struct V_22 , V_87 ) ;
if ( V_5 -> V_80 == V_80 &&
V_5 -> V_88 == V_79 -> V_89 . V_90 &&
V_5 -> V_91 == V_79 -> V_89 . V_92 ) {
F_36 ( V_93 L_11 ,
V_80 , V_5 -> V_88 , V_5 -> V_91 , V_5 ) ;
goto V_94;
}
}
F_36 ( V_93 L_12 ,
V_84 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_80 ) ;
V_5 = F_37 ( sizeof( * V_5 ) , V_95 ) ;
if ( ! V_5 )
goto V_94;
V_5 -> V_6 = V_6 ;
F_38 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_80 = V_80 ;
V_5 -> V_88 = V_79 -> V_89 . V_90 ;
V_5 -> V_91 = V_79 -> V_89 . V_92 ;
F_39 ( & V_5 -> V_66 ) ;
V_80 &= V_96 ;
if ( V_84 )
V_5 -> V_25 = F_40 ( V_6 -> V_7 , V_80 ) ;
else
V_5 -> V_25 = F_41 ( V_6 -> V_7 , V_80 ) ;
if ( type == V_53 ) {
if ( F_42 ( V_79 , 1 ) -> V_97 >= V_98 &&
F_42 ( V_79 , 1 ) -> V_99 >= 1 &&
F_42 ( V_79 , 1 ) -> V_99 <= 9 )
V_5 -> V_100 = F_42 ( V_79 , 1 ) -> V_99 ;
else if ( F_18 ( V_6 -> V_7 ) == V_101 )
V_5 -> V_100 = 1 ;
else if ( F_42 ( V_79 , 1 ) -> V_102 >= 1 &&
F_42 ( V_79 , 1 ) -> V_102 <= 16 )
V_5 -> V_100 = F_42 ( V_79 , 1 ) -> V_102 - 1 ;
else
V_5 -> V_100 = 3 ;
V_5 -> V_57 = F_43 ( F_42 ( V_79 , 1 ) -> V_103 ) ;
}
F_30 ( & V_5 -> V_87 , & V_6 -> V_104 ) ;
V_94:
F_44 ( & V_6 -> V_86 ) ;
return V_5 ;
}
static int F_45 ( struct V_22 * V_5 )
{
unsigned long V_105 = V_106 + F_46 ( 1000 ) ;
unsigned int V_39 ;
int V_107 ;
do {
V_107 = 0 ;
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ )
if ( F_21 ( V_39 , & V_5 -> V_71 ) )
V_107 ++ ;
if ( ! V_107 )
break;
F_47 ( 1 ) ;
} while ( F_48 ( V_106 , V_105 ) );
if ( V_107 )
F_26 ( V_69 L_17 ,
V_107 , V_5 -> V_80 ) ;
return 0 ;
}
static int F_49 ( struct V_22 * V_5 , int V_109 , int V_110 )
{
unsigned int V_39 ;
int V_111 ;
if ( ! V_109 && V_5 -> V_6 -> V_75 )
return - V_112 ;
V_111 = ! V_110 && V_5 -> V_6 -> V_113 ;
F_31 ( V_58 , & V_5 -> V_26 ) ;
F_39 ( & V_5 -> V_66 ) ;
V_5 -> V_62 = 0 ;
V_5 -> V_63 = 0 ;
if ( ! V_111 && F_50 () )
return 0 ;
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ ) {
if ( F_21 ( V_39 , & V_5 -> V_71 ) ) {
if ( ! F_51 ( V_39 , & V_5 -> V_114 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_39 ] . V_8 ;
if ( V_111 )
F_52 ( V_3 ) ;
else
F_53 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_54 ( struct V_22 * V_5 , int V_109 )
{
int V_39 ;
V_5 -> V_35 = NULL ;
V_5 -> V_43 = NULL ;
F_49 ( V_5 , V_109 , 1 ) ;
F_45 ( V_5 ) ;
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ )
F_3 ( & V_5 -> V_8 [ V_39 ] ) ;
if ( V_5 -> V_115 )
F_4 ( V_5 -> V_6 -> V_7 , V_116 * 4 ,
V_5 -> V_115 , V_5 -> V_117 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_108 = 0 ;
}
static int F_55 ( struct V_22 * V_5 ,
struct V_118 * V_119 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
unsigned int V_123 , V_39 , V_124 , V_125 , V_126 ;
int V_127 = F_56 ( V_119 ) ;
int V_128 = F_57 ( V_119 ) ;
int V_84 = F_8 ( V_5 -> V_25 ) ;
int V_129 = F_58 ( F_57 ( V_119 ) ) *
F_59 ( V_119 ) ;
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_48 = V_129 >> 3 ;
V_5 -> V_52 = V_128 == V_130 ? 0x80 : 0 ;
if ( V_5 -> V_131 ) {
V_123 = V_5 -> V_131 ;
V_5 -> V_132 = ( V_123 / ( V_129 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
} else {
V_5 -> V_132 = V_5 -> V_55 + ( V_5 -> V_55 >> 2 ) ;
V_123 = ( ( V_5 -> V_132 + 0xffff ) * ( V_129 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_56 = V_5 -> V_131 ;
else
V_5 -> V_56 = V_123 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_101 )
V_126 = 8 >> V_5 -> V_33 ;
else
V_126 = 1 ;
if ( V_84 && ! F_7 ( V_5 ) ) {
V_124 = F_60 ( V_5 -> V_6 -> V_133 , 1 ) ;
V_124 = F_11 ( V_124 , ( unsigned int ) V_134 ) ;
} else {
V_124 = 1 ;
}
V_124 *= V_126 ;
if ( V_122 && ! F_7 ( V_5 ) )
V_124 = F_11 ( V_124 , 1U << V_122 -> V_100 ) ;
if ( V_84 && ! F_7 ( V_5 ) ) {
unsigned int V_135 , V_136 ;
V_135 = ( V_5 -> V_55 >> ( 16 - V_5 -> V_33 ) )
* ( V_129 >> 3 ) ;
if ( V_122 )
V_135 -= V_135 >> 3 ;
V_135 = F_60 ( V_135 , 1u ) ;
V_125 = ( V_127 + V_135 - 1 ) / V_135 ;
if ( V_125 < 2 ) {
V_125 = 2 ;
} else {
V_136 = F_60 ( V_137 * V_126 , V_124 * 2 ) ;
V_125 = F_11 ( V_125 , V_136 ) ;
}
} else {
while ( V_124 > 1 && V_124 * V_123 >= V_127 )
V_124 >>= 1 ;
V_125 = V_65 * V_124 ;
}
V_5 -> V_108 = ( V_125 + V_124 - 1 ) / V_124 ;
if ( V_5 -> V_108 > V_65 ) {
V_5 -> V_108 = V_65 ;
V_125 = V_65 * V_124 ;
} else if ( V_5 -> V_108 < 2 ) {
V_5 -> V_108 = 2 ;
}
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_39 ] ;
V_3 -> V_70 = V_39 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_40 = ( V_39 + 1 ) * V_125 / V_5 -> V_108
- V_39 * V_125 / V_5 -> V_108 ;
V_3 -> V_4 = V_123 * V_3 -> V_40 ;
if ( V_121 -> V_138 == V_139 )
V_3 -> V_40 ++ ;
V_3 -> V_8 = F_61 ( V_3 -> V_40 , V_95 ) ;
if ( ! V_3 -> V_8 )
goto V_140;
V_3 -> V_8 -> V_9 =
F_62 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_95 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_140;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_141 = V_142 | V_143 ;
V_3 -> V_8 -> V_144 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_145 = F_28 ;
F_39 ( & V_3 -> V_67 ) ;
}
return 0 ;
V_140:
F_54 ( V_5 , 0 ) ;
return - V_146 ;
}
static int F_63 ( struct V_22 * V_5 ,
struct V_118 * V_119 ,
struct V_120 * V_121 )
{
int V_39 ;
V_5 -> V_115 = F_62 ( V_5 -> V_6 -> V_7 , V_116 * 4 ,
V_95 , & V_5 -> V_117 ) ;
if ( ! V_5 -> V_115 )
return - V_146 ;
for ( V_39 = 0 ; V_39 < V_116 ; V_39 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_39 ] ;
V_3 -> V_70 = V_39 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_40 = 1 ;
V_3 -> V_8 = F_61 ( 1 , V_95 ) ;
if ( ! V_3 -> V_8 )
goto V_140;
V_3 -> V_8 -> V_9 = V_5 -> V_115 + V_39 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_117 + V_39 * 4 ;
V_3 -> V_8 -> V_51 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_141 = V_142 |
V_143 ;
V_3 -> V_8 -> V_50 = 1 ;
V_3 -> V_8 -> V_144 = 1 << V_5 -> V_100 ;
V_3 -> V_8 -> V_72 = V_3 ;
V_3 -> V_8 -> V_145 = F_28 ;
}
V_5 -> V_108 = V_116 ;
return 0 ;
V_140:
F_54 ( V_5 , 0 ) ;
return - V_146 ;
}
int F_64 ( struct V_22 * V_5 ,
struct V_118 * V_119 ,
struct V_120 * V_121 ,
struct V_22 * V_122 )
{
int V_11 ;
if ( V_5 -> V_147 != 0 ) {
F_26 ( V_148 L_18 ,
V_5 -> V_80 ) ;
return - V_149 ;
}
F_54 ( V_5 , 0 ) ;
V_5 -> V_33 = V_121 -> V_33 ;
V_5 -> V_131 = V_121 -> V_131 ;
V_5 -> V_28 = ! ! ( V_121 -> V_150 & V_151 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_101 )
V_5 -> V_55 = F_1 ( F_65 ( V_119 ) ) ;
else
V_5 -> V_55 = F_2 ( F_65 ( V_119 ) ) ;
V_5 -> V_32 = V_5 -> V_55 ;
V_5 -> V_152 = V_153 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_55 ( V_5 , V_119 , V_121 , V_122 ) ;
break;
case V_53 :
V_11 = F_63 ( V_5 , V_119 , V_121 ) ;
break;
default:
V_11 = - V_18 ;
}
F_36 ( V_93 L_19 ,
V_5 -> V_80 , V_5 -> type , V_5 -> V_108 , V_11 ) ;
return V_11 ;
}
int F_66 ( struct V_22 * V_5 )
{
int V_11 ;
unsigned int V_39 ;
if ( V_5 -> V_6 -> V_75 )
return - V_112 ;
if ( ++ V_5 -> V_147 != 1 )
return 0 ;
F_49 ( V_5 , 0 , 1 ) ;
F_45 ( V_5 ) ;
V_5 -> V_71 = 0 ;
V_5 -> V_114 = 0 ;
V_5 -> V_31 = 0 ;
F_27 ( V_58 , & V_5 -> V_26 ) ;
if ( F_7 ( V_5 ) ) {
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ ) {
struct V_2 * V_38 = V_5 -> V_8 + V_39 ;
F_30 ( & V_38 -> V_67 , & V_5 -> V_66 ) ;
}
return 0 ;
}
for ( V_39 = 0 ; V_39 < V_5 -> V_108 ; V_39 ++ ) {
struct V_8 * V_8 = V_5 -> V_8 [ V_39 ] . V_8 ;
if ( F_67 ( ! V_8 ) )
goto V_154;
if ( F_8 ( V_5 -> V_25 ) ) {
F_16 ( V_5 , V_8 -> V_72 ) ;
F_17 ( V_5 , V_8 -> V_72 ) ;
} else {
F_19 ( V_5 , V_8 -> V_72 ) ;
}
V_11 = F_25 ( V_8 , V_68 ) ;
if ( V_11 < 0 ) {
F_26 ( V_69 L_20 ,
V_39 , V_11 , F_6 ( V_11 ) ) ;
goto V_154;
}
F_27 ( V_39 , & V_5 -> V_71 ) ;
}
return 0 ;
V_154:
F_31 ( V_58 , & V_5 -> V_26 ) ;
V_5 -> V_147 -- ;
F_49 ( V_5 , 0 , 0 ) ;
return - V_14 ;
}
void F_68 ( struct V_22 * V_5 ,
int V_109 , int V_110 , int V_155 )
{
if ( ! V_5 )
return;
if ( F_67 ( V_5 -> V_147 == 0 ) )
return;
if ( -- V_5 -> V_147 == 0 ) {
F_49 ( V_5 , V_109 , V_110 ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_37 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_43 = NULL ;
if ( V_155 )
F_45 ( V_5 ) ;
}
}
int F_69 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return - V_18 ;
F_49 ( V_5 , 1 , 1 ) ;
F_45 ( V_5 ) ;
if ( V_5 -> V_147 != 0 )
return 0 ;
F_31 ( V_156 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_70 ( struct V_82 * V_157 )
{
struct V_22 * V_5 ;
V_5 = F_35 ( V_157 , struct V_22 , V_87 ) ;
F_54 ( V_5 , 1 ) ;
F_71 ( V_5 ) ;
}
void F_15 ( struct V_22 * V_5 ,
struct V_22 * V_158 ,
const struct V_8 * V_8 )
{
int V_159 ;
unsigned int V_160 ;
unsigned long V_26 ;
F_67 ( V_5 == V_158 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_147 != 0 ) {
int V_39 , V_161 = 0 ;
struct V_2 * V_162 ;
struct V_59 * V_163 ;
V_162 = V_8 -> V_72 ;
for ( V_39 = 0 ; V_39 < V_162 -> V_40 ; V_39 ++ )
if ( V_8 -> V_46 [ V_39 ] . V_73 == 0 )
V_161 += V_8 -> V_46 [ V_39 ] . V_164 ;
if ( V_161 == 0 )
return;
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_163 = V_5 -> V_64 + V_5 -> V_63 ;
V_163 -> V_40 = V_162 -> V_40 ;
for ( V_39 = 0 ; V_39 < V_162 -> V_40 ; V_39 ++ ) {
if ( V_8 -> V_46 [ V_39 ] . V_73 == 0 )
V_163 -> V_41 [ V_39 ] =
V_8 -> V_46 [ V_39 ] . V_164 / V_5 -> V_48 ;
else
V_163 -> V_41 [ V_39 ] = 0 ;
}
V_5 -> V_63 ++ ;
V_5 -> V_63 %= V_65 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
F_20 ( V_5 ) ;
return;
}
if ( V_8 -> V_46 [ 0 ] . V_73 != 0 ||
V_8 -> V_46 [ 0 ] . V_164 < 3 )
return;
V_160 = F_72 ( V_8 -> V_9 ) ;
if ( V_8 -> V_46 [ 0 ] . V_164 == 3 )
V_160 &= 0x00ffffff ;
else
V_160 &= 0x0fffffff ;
if ( V_160 == 0 )
return;
if ( F_29 ( V_5 -> V_152 == V_153 ) ) {
V_159 = 0 ;
while ( V_160 < V_5 -> V_55 - V_5 -> V_55 / 4 ) {
V_160 <<= 1 ;
V_159 ++ ;
}
while ( V_160 > V_5 -> V_55 + V_5 -> V_55 / 2 ) {
V_160 >>= 1 ;
V_159 -- ;
}
V_5 -> V_152 = V_159 ;
} else if ( V_5 -> V_152 >= 0 )
V_160 <<= V_5 -> V_152 ;
else
V_160 >>= - V_5 -> V_152 ;
if ( F_73 ( V_160 >= V_5 -> V_55 - V_5 -> V_55 / 8 && V_160 <= V_5 -> V_132 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_160 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_152 = V_153 ;
}
}
