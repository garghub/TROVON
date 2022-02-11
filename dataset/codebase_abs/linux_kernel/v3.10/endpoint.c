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
struct V_22 * V_5 ;
int V_83 = V_82 == V_84 ;
F_32 ( & V_6 -> V_85 ) ;
F_33 (ep, &chip->ep_list, list) {
if ( V_5 -> V_81 == V_81 &&
V_5 -> V_86 == V_80 -> V_87 . V_88 &&
V_5 -> V_89 == V_80 -> V_87 . V_90 ) {
F_34 ( V_91 L_11 ,
V_81 , V_5 -> V_86 , V_5 -> V_89 , V_5 ) ;
goto V_92;
}
}
F_34 ( V_91 L_12 ,
V_83 ? L_13 : L_14 ,
type == V_24 ? L_15 : L_16 ,
V_81 ) ;
V_5 = F_35 ( sizeof( * V_5 ) , V_93 ) ;
if ( ! V_5 )
goto V_92;
V_5 -> V_6 = V_6 ;
F_36 ( & V_5 -> V_30 ) ;
V_5 -> type = type ;
V_5 -> V_81 = V_81 ;
V_5 -> V_86 = V_80 -> V_87 . V_88 ;
V_5 -> V_89 = V_80 -> V_87 . V_90 ;
F_37 ( & V_5 -> V_67 ) ;
V_81 &= V_94 ;
if ( V_83 )
V_5 -> V_25 = F_38 ( V_6 -> V_7 , V_81 ) ;
else
V_5 -> V_25 = F_39 ( V_6 -> V_7 , V_81 ) ;
if ( type == V_54 ) {
if ( F_40 ( V_80 , 1 ) -> V_95 >= V_96 &&
F_40 ( V_80 , 1 ) -> V_97 >= 1 &&
F_40 ( V_80 , 1 ) -> V_97 <= 9 )
V_5 -> V_98 = F_40 ( V_80 , 1 ) -> V_97 ;
else if ( F_18 ( V_6 -> V_7 ) == V_99 )
V_5 -> V_98 = 1 ;
else if ( F_40 ( V_80 , 1 ) -> V_100 >= 1 &&
F_40 ( V_80 , 1 ) -> V_100 <= 16 )
V_5 -> V_98 = F_40 ( V_80 , 1 ) -> V_100 - 1 ;
else
V_5 -> V_98 = 3 ;
V_5 -> V_58 = F_41 ( F_40 ( V_80 , 1 ) -> V_101 ) ;
}
F_29 ( & V_5 -> V_102 , & V_6 -> V_103 ) ;
V_92:
F_42 ( & V_6 -> V_85 ) ;
return V_5 ;
}
static int F_43 ( struct V_22 * V_5 )
{
unsigned long V_104 = V_105 + F_44 ( 1000 ) ;
int V_106 ;
do {
V_106 = F_45 ( & V_5 -> V_72 , V_5 -> V_107 ) ;
if ( ! V_106 )
break;
F_46 ( 1 ) ;
} while ( F_47 ( V_105 , V_104 ) );
if ( V_106 )
F_26 ( V_70 L_17 ,
V_106 , V_5 -> V_81 ) ;
F_30 ( V_108 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_48 ( struct V_22 * V_5 )
{
if ( V_5 && F_21 ( V_108 , & V_5 -> V_26 ) )
F_43 ( V_5 ) ;
}
static int F_49 ( struct V_22 * V_5 , bool V_109 )
{
unsigned int V_40 ;
if ( ! V_109 && V_5 -> V_6 -> V_76 )
return - V_110 ;
F_30 ( V_59 , & V_5 -> V_26 ) ;
F_37 ( & V_5 -> V_67 ) ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
if ( F_21 ( V_40 , & V_5 -> V_72 ) ) {
if ( ! F_50 ( V_40 , & V_5 -> V_111 ) ) {
struct V_8 * V_3 = V_5 -> V_8 [ V_40 ] . V_8 ;
F_51 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_52 ( struct V_22 * V_5 , int V_109 )
{
int V_40 ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_49 ( V_5 , V_109 ) ;
F_43 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ )
F_3 ( & V_5 -> V_8 [ V_40 ] ) ;
if ( V_5 -> V_112 )
F_4 ( V_5 -> V_6 -> V_7 , V_113 * 4 ,
V_5 -> V_112 , V_5 -> V_114 ) ;
V_5 -> V_112 = NULL ;
V_5 -> V_107 = 0 ;
}
static int F_53 ( struct V_22 * V_5 ,
T_1 V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
struct V_118 * V_119 ,
struct V_22 * V_120 )
{
unsigned int V_121 , V_40 , V_122 , V_123 , V_124 ;
int V_83 = F_8 ( V_5 -> V_25 ) ;
int V_125 = F_54 ( V_115 ) * V_116 ;
if ( V_115 == V_126 && V_119 -> V_127 ) {
V_125 += V_116 << 3 ;
}
V_5 -> V_33 = V_119 -> V_33 ;
V_5 -> V_49 = V_125 >> 3 ;
V_5 -> V_53 = V_115 == V_128 ? 0x80 : 0 ;
if ( V_5 -> V_129 ) {
V_121 = V_5 -> V_129 ;
V_5 -> V_130 = ( V_121 / ( V_125 >> 3 ) )
<< ( 16 - V_5 -> V_33 ) ;
} else {
V_5 -> V_130 = V_5 -> V_56 + ( V_5 -> V_56 >> 2 ) ;
V_121 = ( ( V_5 -> V_130 + 0xffff ) * ( V_125 >> 3 ) )
>> ( 16 - V_5 -> V_33 ) ;
}
if ( V_5 -> V_28 )
V_5 -> V_57 = V_5 -> V_129 ;
else
V_5 -> V_57 = V_121 ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) != V_99 )
V_124 = 8 >> V_5 -> V_33 ;
else
V_124 = 1 ;
if ( V_83 && ! F_7 ( V_5 ) ) {
V_122 = F_55 ( V_5 -> V_6 -> V_131 , 1 ) ;
V_122 = F_11 ( V_122 , ( unsigned int ) V_132 ) ;
} else {
V_122 = 1 ;
}
V_122 *= V_124 ;
if ( V_120 && ! F_7 ( V_5 ) )
V_122 = F_11 ( V_122 , 1U << V_120 -> V_98 ) ;
if ( V_83 && ! F_7 ( V_5 ) ) {
unsigned int V_133 , V_134 ;
V_133 = ( V_5 -> V_56 >> ( 16 - V_5 -> V_33 ) )
* ( V_125 >> 3 ) ;
if ( V_120 )
V_133 -= V_133 >> 3 ;
V_133 = F_55 ( V_133 , 1u ) ;
V_123 = ( V_117 + V_133 - 1 ) / V_133 ;
if ( V_123 < 2 ) {
V_123 = 2 ;
} else {
V_134 = F_55 ( V_135 * V_124 , V_122 * 2 ) ;
V_123 = F_11 ( V_123 , V_134 ) ;
}
} else {
while ( V_122 > 1 && V_122 * V_121 >= V_117 )
V_122 >>= 1 ;
V_123 = V_66 * V_122 ;
}
V_5 -> V_107 = ( V_123 + V_122 - 1 ) / V_122 ;
if ( V_5 -> V_107 > V_66 ) {
V_5 -> V_107 = V_66 ;
V_123 = V_66 * V_122 ;
} else if ( V_5 -> V_107 < 2 ) {
V_5 -> V_107 = 2 ;
}
for ( V_40 = 0 ; V_40 < V_5 -> V_107 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = ( V_40 + 1 ) * V_123 / V_5 -> V_107
- V_40 * V_123 / V_5 -> V_107 ;
V_3 -> V_4 = V_121 * V_3 -> V_44 ;
if ( V_119 -> V_136 == V_137 )
V_3 -> V_44 ++ ;
V_3 -> V_8 = F_56 ( V_3 -> V_44 , V_93 ) ;
if ( ! V_3 -> V_8 )
goto V_138;
V_3 -> V_8 -> V_9 =
F_57 ( V_5 -> V_6 -> V_7 , V_3 -> V_4 ,
V_93 , & V_3 -> V_8 -> V_10 ) ;
if ( ! V_3 -> V_8 -> V_9 )
goto V_138;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_139 = V_140 ;
V_3 -> V_8 -> V_141 = 1 << V_5 -> V_33 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_142 = F_28 ;
F_37 ( & V_3 -> V_68 ) ;
}
return 0 ;
V_138:
F_52 ( V_5 , 0 ) ;
return - V_143 ;
}
static int F_58 ( struct V_22 * V_5 ,
struct V_118 * V_119 )
{
int V_40 ;
V_5 -> V_112 = F_57 ( V_5 -> V_6 -> V_7 , V_113 * 4 ,
V_93 , & V_5 -> V_114 ) ;
if ( ! V_5 -> V_112 )
return - V_143 ;
for ( V_40 = 0 ; V_40 < V_113 ; V_40 ++ ) {
struct V_2 * V_3 = & V_5 -> V_8 [ V_40 ] ;
V_3 -> V_71 = V_40 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_44 = 1 ;
V_3 -> V_8 = F_56 ( 1 , V_93 ) ;
if ( ! V_3 -> V_8 )
goto V_138;
V_3 -> V_8 -> V_9 = V_5 -> V_112 + V_40 * 4 ;
V_3 -> V_8 -> V_10 = V_5 -> V_114 + V_40 * 4 ;
V_3 -> V_8 -> V_52 = 4 ;
V_3 -> V_8 -> V_25 = V_5 -> V_25 ;
V_3 -> V_8 -> V_139 = V_140 ;
V_3 -> V_8 -> V_51 = 1 ;
V_3 -> V_8 -> V_141 = 1 << V_5 -> V_98 ;
V_3 -> V_8 -> V_73 = V_3 ;
V_3 -> V_8 -> V_142 = F_28 ;
}
V_5 -> V_107 = V_113 ;
return 0 ;
V_138:
F_52 ( V_5 , 0 ) ;
return - V_143 ;
}
int F_59 ( struct V_22 * V_5 ,
T_1 V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_1 ,
struct V_118 * V_119 ,
struct V_22 * V_120 )
{
int V_11 ;
if ( V_5 -> V_144 != 0 ) {
F_26 ( V_145 L_18 ,
V_5 -> V_81 ) ;
return - V_146 ;
}
F_52 ( V_5 , 0 ) ;
V_5 -> V_33 = V_119 -> V_33 ;
V_5 -> V_129 = V_119 -> V_129 ;
V_5 -> V_28 = ! ! ( V_119 -> V_147 & V_148 ) ;
if ( F_18 ( V_5 -> V_6 -> V_7 ) == V_99 )
V_5 -> V_56 = F_1 ( V_1 ) ;
else
V_5 -> V_56 = F_2 ( V_1 ) ;
V_5 -> V_32 = V_5 -> V_56 ;
V_5 -> V_149 = V_150 ;
V_5 -> V_31 = 0 ;
switch ( V_5 -> type ) {
case V_24 :
V_11 = F_53 ( V_5 , V_115 , V_116 ,
V_117 , V_119 , V_120 ) ;
break;
case V_54 :
V_11 = F_58 ( V_5 , V_119 ) ;
break;
default:
V_11 = - V_18 ;
}
F_34 ( V_91 L_19 ,
V_5 -> V_81 , V_5 -> type , V_5 -> V_107 , V_11 ) ;
return V_11 ;
}
int F_60 ( struct V_22 * V_5 , bool V_151 )
{
int V_11 ;
unsigned int V_40 ;
if ( V_5 -> V_6 -> V_76 )
return - V_110 ;
if ( ++ V_5 -> V_144 != 1 )
return 0 ;
F_49 ( V_5 , false ) ;
if ( V_151 )
F_43 ( V_5 ) ;
V_5 -> V_72 = 0 ;
V_5 -> V_111 = 0 ;
V_5 -> V_31 = 0 ;
F_61 ( V_5 ) ;
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
if ( F_62 ( ! V_8 ) )
goto V_152;
if ( F_8 ( V_5 -> V_25 ) ) {
F_17 ( V_5 , V_8 -> V_73 ) ;
} else {
F_19 ( V_5 , V_8 -> V_73 ) ;
}
V_11 = F_25 ( V_8 , V_69 ) ;
if ( V_11 < 0 ) {
F_26 ( V_70 L_20 ,
V_40 , V_11 , F_6 ( V_11 ) ) ;
goto V_152;
}
F_27 ( V_40 , & V_5 -> V_72 ) ;
}
return 0 ;
V_152:
F_30 ( V_59 , & V_5 -> V_26 ) ;
V_5 -> V_144 -- ;
F_49 ( V_5 , false ) ;
return - V_14 ;
}
void F_63 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return;
if ( F_62 ( V_5 -> V_144 == 0 ) )
return;
if ( -- V_5 -> V_144 == 0 ) {
F_49 ( V_5 , false ) ;
V_5 -> V_36 = NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_35 = NULL ;
V_5 -> V_42 = NULL ;
F_27 ( V_108 , & V_5 -> V_26 ) ;
}
}
int F_64 ( struct V_22 * V_5 )
{
if ( ! V_5 )
return - V_18 ;
F_49 ( V_5 , true ) ;
F_43 ( V_5 ) ;
if ( V_5 -> V_144 != 0 )
return 0 ;
F_30 ( V_153 , & V_5 -> V_26 ) ;
return 0 ;
}
void F_65 ( struct V_154 * V_155 )
{
struct V_22 * V_5 ;
V_5 = F_66 ( V_155 , struct V_22 , V_102 ) ;
F_52 ( V_5 , 1 ) ;
F_67 ( V_5 ) ;
}
void F_16 ( struct V_22 * V_5 ,
struct V_22 * V_156 ,
const struct V_8 * V_8 )
{
int V_157 ;
unsigned int V_158 ;
unsigned long V_26 ;
F_62 ( V_5 == V_156 ) ;
if ( F_7 ( V_5 ) &&
V_5 -> V_144 != 0 ) {
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
if ( F_15 ( V_5 -> V_149 == V_150 ) ) {
V_157 = 0 ;
while ( V_158 < V_5 -> V_56 - V_5 -> V_56 / 4 ) {
V_158 <<= 1 ;
V_157 ++ ;
}
while ( V_158 > V_5 -> V_56 + V_5 -> V_56 / 2 ) {
V_158 >>= 1 ;
V_157 -- ;
}
V_5 -> V_149 = V_157 ;
} else if ( V_5 -> V_149 >= 0 )
V_158 <<= V_5 -> V_149 ;
else
V_158 >>= - V_5 -> V_149 ;
if ( F_69 ( V_158 >= V_5 -> V_56 - V_5 -> V_56 / 8 && V_158 <= V_5 -> V_130 ) ) {
F_10 ( & V_5 -> V_30 , V_26 ) ;
V_5 -> V_32 = V_158 ;
F_12 ( & V_5 -> V_30 , V_26 ) ;
} else {
V_5 -> V_149 = V_150 ;
}
}
