static inline T_1 * F_1 ( struct V_1 * V_2 )
{
char * V_3 = F_2 ( V_2 ) ;
return ( T_1 * ) ( V_3 + sizeof( struct V_4 ) ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
T_1 * V_7 ;
struct V_1 * V_2 ;
F_4 ( & V_6 -> V_2 , L_1 ) ;
V_2 = F_5 ( sizeof( T_1 ) ) ;
if ( ! V_2 ) return - V_8 ;
V_7 = F_1 ( V_2 ) ;
V_7 -> V_9 = V_6 ;
V_6 -> V_10 = V_2 ;
V_6 -> V_11 |= V_12 | V_13 ;
V_2 -> V_14 = & V_15 ;
return F_6 ( V_6 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
F_4 ( & V_6 -> V_2 , L_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_6 ) ;
F_10 ( V_2 ) ;
}
static T_2 * F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_3 T_4 * V_16 , * V_17 ;
int V_18 , V_19 ;
V_6 -> V_20 [ 2 ] -> V_21 |= V_22 | V_23 | V_24 ;
V_6 -> V_20 [ 2 ] -> V_25 = 0 ; V_6 -> V_20 [ 2 ] -> V_26 = 0 ;
V_18 = F_12 ( V_6 , V_6 -> V_20 [ 2 ] , 0 ) ;
if ( V_18 != 0 )
return NULL ;
V_17 = F_13 ( V_6 -> V_20 [ 2 ] -> V_25 ,
F_14 ( V_6 -> V_20 [ 2 ] ) ) ;
for ( V_18 = 0 ; V_18 < V_27 ; V_18 ++ ) {
F_15 ( V_6 , V_6 -> V_20 [ 2 ] ,
V_28 [ V_18 ] . V_29 & ~ ( F_14 ( V_6 -> V_20 [ 2 ] ) - 1 ) ) ;
V_16 = & V_17 [ V_28 [ V_18 ] . V_29 & ( F_14 ( V_6 -> V_20 [ 2 ] ) - 1 ) ] ;
if ( ( F_16 ( V_16 + 0 ) == V_28 [ V_18 ] . V_30 ) &&
( F_16 ( V_16 + 2 ) == V_28 [ V_18 ] . V_31 ) &&
( F_16 ( V_16 + 4 ) == V_28 [ V_18 ] . V_32 ) ) {
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_2 -> V_33 [ V_19 ] = F_16 ( V_16 + ( V_19 << 1 ) ) ;
break;
}
}
F_17 ( V_17 ) ;
V_19 = F_18 ( V_6 , V_6 -> V_20 [ 2 ] ) ;
return ( V_18 < V_27 ) ? V_28 + V_18 : NULL ;
}
static T_2 * F_19 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
unsigned int V_34 = V_2 -> V_35 ;
T_3 V_36 [ 32 ] ;
int V_18 , V_19 ;
struct {
T_3 V_37 , V_29 ;
} V_38 [] = {
{ V_39 + V_40 + V_41 , V_42 } ,
{ 0x48 , V_43 } ,
{ 0x00 , V_44 } ,
{ 0x00 , V_45 } ,
{ 0x00 , V_46 } ,
{ 0xFF , V_47 } ,
{ V_48 , V_49 } ,
{ V_50 , V_51 } ,
{ 32 , V_44 } ,
{ 0x00 , V_45 } ,
{ 0x00 , V_52 } ,
{ 0x00 , V_53 } ,
{ V_54 + V_55 , V_42 } ,
} ;
F_20 ( V_2 ) ;
F_21 ( 10 ) ;
for ( V_18 = 0 ; V_18 < F_22 ( V_38 ) ; V_18 ++ )
F_23 ( V_38 [ V_18 ] . V_37 , V_34 + V_38 [ V_18 ] . V_29 ) ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
V_36 [ V_18 ] = F_24 ( V_34 + V_56 ) ;
for ( V_18 = 0 ; V_18 < V_27 ; V_18 ++ ) {
if ( ( V_36 [ 0 ] == V_28 [ V_18 ] . V_30 ) &&
( V_36 [ 2 ] == V_28 [ V_18 ] . V_31 ) &&
( V_36 [ 4 ] == V_28 [ V_18 ] . V_32 ) )
break;
}
if ( ( V_18 < V_27 ) || ( ( V_36 [ 28 ] == 0x57 ) && ( V_36 [ 30 ] == 0x57 ) ) ) {
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_2 -> V_33 [ V_19 ] = V_36 [ V_19 << 1 ] ;
return ( V_18 < V_27 ) ? V_28 + V_18 : & V_57 ;
}
return NULL ;
}
static T_2 * F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
int V_18 ;
T_3 V_58 ;
for ( V_58 = 0 , V_18 = 0x14 ; V_18 < 0x1c ; V_18 ++ )
V_58 += F_26 ( V_2 -> V_35 + V_18 ) ;
if ( V_58 != 0xff )
return NULL ;
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ )
V_2 -> V_33 [ V_18 ] = F_26 ( V_2 -> V_35 + 0x14 + V_18 ) ;
V_18 = F_24 ( V_2 -> V_35 + 0x1f ) ;
return ( ( V_18 == 0x91 ) || ( V_18 == 0x99 ) ) ? & V_59 : & V_60 ;
}
static T_2 * F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
unsigned int V_34 = V_2 -> V_35 ;
int V_18 , V_19 ;
if ( V_6 -> V_61 != 0x03c0 )
return NULL ;
F_23 ( 0x01 , V_34 + V_43 ) ;
F_23 ( 0x00 , V_34 + V_52 ) ;
F_23 ( 0x04 , V_34 + V_53 ) ;
F_23 ( V_54 + V_55 , V_34 + V_42 ) ;
for ( V_18 = 0 ; V_18 < 6 ; V_18 += 2 ) {
V_19 = F_28 ( V_34 + V_56 ) ;
V_2 -> V_33 [ V_18 ] = V_19 & 0xff ;
V_2 -> V_33 [ V_18 + 1 ] = V_19 >> 8 ;
}
return NULL ;
}
static T_2 * F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ )
if ( V_62 [ V_18 ] != 0 ) break;
if ( V_18 == 6 )
return NULL ;
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ )
V_2 -> V_33 [ V_18 ] = V_62 [ V_18 ] ;
return & V_57 ;
}
static int F_30 ( struct V_5 * V_6 )
{
int V_19 , V_63 ;
V_6 -> V_20 [ 0 ] -> V_21 &= ~ V_64 ;
V_6 -> V_20 [ 1 ] -> V_21 &= ~ V_64 ;
if ( V_6 -> V_20 [ 0 ] -> V_26 == 32 ) {
V_6 -> V_20 [ 0 ] -> V_21 |= V_65 ;
if ( V_6 -> V_20 [ 1 ] -> V_26 > 0 ) {
V_6 -> V_20 [ 1 ] -> V_21 |= V_66 ;
}
} else {
V_6 -> V_20 [ 0 ] -> V_21 |= V_66 ;
V_6 -> V_20 [ 1 ] -> V_21 |= V_67 ;
}
if ( V_6 -> V_20 [ 0 ] -> V_25 == 0 ) {
for ( V_19 = 0 ; V_19 < 0x400 ; V_19 += 0x20 ) {
V_6 -> V_20 [ 0 ] -> V_25 = V_19 ^ 0x300 ;
V_6 -> V_20 [ 1 ] -> V_25 = ( V_19 ^ 0x300 ) + 0x10 ;
V_6 -> V_68 = 16 ;
V_63 = F_31 ( V_6 ) ;
if ( V_63 == 0 )
return V_63 ;
}
return V_63 ;
} else {
return F_31 ( V_6 ) ;
}
}
static int F_32 ( struct V_5 * V_9 , void * V_69 )
{
int * V_10 = V_69 ;
int V_70 = ( * V_10 & 0x1 ) ;
* V_10 &= ( V_9 -> V_20 [ 2 ] -> V_26 >= 0x4000 ) ? 0x10 : ~ 0x10 ;
if ( V_9 -> V_71 == 0 )
return - V_72 ;
if ( V_9 -> V_20 [ 0 ] -> V_26 + V_9 -> V_20 [ 1 ] -> V_26 < 32 )
return - V_72 ;
if ( V_70 )
V_9 -> V_68 = 16 ;
return F_30 ( V_9 ) ;
}
static T_2 * F_33 ( struct V_5 * V_6 ,
int * V_73 , int V_70 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_2 * V_74 ;
T_1 * V_7 = F_1 ( V_2 ) ;
int V_10 = V_70 ;
int V_63 ;
V_63 = F_34 ( V_6 , F_32 , & V_10 ) ;
if ( V_63 ) {
F_35 ( & V_6 -> V_2 , L_3 ) ;
return NULL ;
}
* V_73 = ( V_10 & 0x10 ) ;
if ( ! V_6 -> V_75 )
return NULL ;
if ( F_14 ( V_6 -> V_20 [ 1 ] ) == 8 )
V_6 -> V_11 |= V_76 ;
if ( ( V_6 -> V_77 == V_78 ) &&
( V_6 -> V_79 == V_80 ) )
V_6 -> V_71 |= 0x10 ;
V_63 = F_36 ( V_6 ) ;
if ( V_63 )
return NULL ;
V_2 -> V_75 = V_6 -> V_75 ;
V_2 -> V_35 = V_6 -> V_20 [ 0 ] -> V_25 ;
if ( V_7 -> V_21 & V_81 ) {
if ( ( V_82 == 1 ) || ( V_82 == 2 ) )
V_2 -> V_82 = V_82 ;
else
F_37 ( & V_6 -> V_2 , L_4 ) ;
} else
V_2 -> V_82 = 0 ;
if ( ( V_6 -> V_61 == 0x03c0 ) &&
( V_6 -> V_77 == 0x149 ) && ( V_6 -> V_79 == 0xc1ab ) ) {
F_38 ( & V_6 -> V_2 ,
L_5 ) ;
return NULL ;
}
V_74 = F_11 ( V_6 ) ;
if ( ! V_74 )
V_74 = F_19 ( V_6 ) ;
if ( ! V_74 )
V_74 = F_25 ( V_6 ) ;
if ( ! V_74 )
V_74 = F_27 ( V_6 ) ;
if ( ! V_74 )
V_74 = F_29 ( V_6 ) ;
return V_74 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_1 * V_7 = F_1 ( V_2 ) ;
int V_83 , V_84 , V_85 ;
int V_73 = 0 ;
T_2 * V_74 ;
F_4 ( & V_6 -> V_2 , L_6 ) ;
V_74 = F_33 ( V_6 , & V_73 , 0 ) ;
if ( ! V_74 ) {
F_39 ( V_6 ) ;
V_74 = F_33 ( V_6 , & V_73 , 1 ) ;
if ( V_74 == NULL ) {
F_37 ( & V_6 -> V_2 , L_7
L_8 , V_2 -> V_35 ) ;
goto V_86;
}
}
V_7 -> V_21 = V_74 -> V_21 ;
V_7 -> V_21 |= ( V_87 ) ? V_88 : 0 ;
if ( ( V_6 -> V_77 == V_89 ) &&
( ( V_6 -> V_79 == V_90 ) ||
( V_6 -> V_79 == V_91 ) ||
( V_6 -> V_79 == V_92 ) ) )
V_7 -> V_21 &= ~ V_93 ;
if ( ! V_94 )
V_7 -> V_21 &= ~ V_93 ;
if ( V_7 -> V_21 & V_93 ) {
V_83 = V_95 ;
V_84 = V_96 ;
V_85 = 0x10000 ;
} else {
V_83 = V_97 ;
V_84 = V_98 ;
V_85 = 0 ;
}
if ( ( V_99 == 0 ) || ( ! V_73 && ( V_99 == - 1 ) ) ||
( F_40 ( V_6 , V_83 , V_84 , V_85 ) != 0 ) )
F_41 ( V_6 , V_83 , V_84 ) ;
V_100 . V_101 = L_9 ;
V_100 . V_102 = 1 ;
V_100 . V_103 = F_20 ;
if ( V_7 -> V_21 & ( V_104 | V_105 ) )
F_42 ( V_2 ) ;
F_43 ( V_2 , & V_6 -> V_2 ) ;
if ( F_44 ( V_2 ) != 0 ) {
F_45 ( L_10 ) ;
goto V_86;
}
if ( V_7 -> V_21 & ( V_104 | V_105 ) ) {
T_3 V_106 = F_24 ( V_2 -> V_35 + 0x1a ) ;
F_46 ( V_2 , L_11 ,
( V_7 -> V_21 & V_105 ) ? 22 : 19 , V_106 ) ;
if ( V_7 -> V_107 )
F_47 ( L_12 ) ;
} else {
F_46 ( V_2 , L_13 ) ;
}
F_47 ( L_14 , V_2 -> V_35 , V_2 -> V_75 ) ;
if ( V_7 -> V_21 & V_108 )
F_47 ( L_15 , V_2 -> V_109 ) ;
if ( V_7 -> V_21 & V_81 )
F_47 ( L_16 , V_110 [ V_2 -> V_82 ] ) ;
F_47 ( L_17 , V_2 -> V_33 ) ;
return 0 ;
V_86:
F_9 ( V_6 ) ;
return - V_111 ;
}
static void F_9 ( struct V_5 * V_6 )
{
T_1 * V_7 = F_1 ( V_6 -> V_10 ) ;
F_4 ( & V_6 -> V_2 , L_18 ) ;
if ( V_7 -> V_21 & V_108 )
F_17 ( V_7 -> V_16 ) ;
F_39 ( V_6 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
if ( V_6 -> V_112 )
F_49 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
if ( V_6 -> V_112 ) {
F_20 ( V_2 ) ;
F_51 ( V_2 , 1 ) ;
F_52 ( V_2 ) ;
}
return 0 ;
}
static void F_53 ( unsigned int V_113 )
{
int V_114 , V_115 = F_24 ( V_113 ) & V_116 ;
for ( V_114 = 0 ; V_114 < 32 ; V_114 ++ ) {
F_54 ( V_115 | V_117 , V_113 ) ;
F_54 ( V_115 | V_117 | V_118 , V_113 ) ;
}
}
static int F_55 ( unsigned int V_113 , int V_119 , int V_120 )
{
T_5 V_121 = ( 0x06 << 10 ) | ( V_119 << 5 ) | V_120 ;
int V_18 , V_122 = 0 , V_115 = F_24 ( V_113 ) & V_116 ;
F_53 ( V_113 ) ;
for ( V_18 = 13 ; V_18 >= 0 ; V_18 -- ) {
int V_123 = ( V_121 & ( 1 << V_18 ) ) ? V_117 : V_124 ;
F_54 ( V_115 | V_123 , V_113 ) ;
F_54 ( V_115 | V_123 | V_118 , V_113 ) ;
}
for ( V_18 = 19 ; V_18 > 0 ; V_18 -- ) {
F_54 ( V_115 , V_113 ) ;
V_122 = ( V_122 << 1 ) | ( ( F_24 ( V_113 ) & V_125 ) != 0 ) ;
F_54 ( V_115 | V_118 , V_113 ) ;
}
return ( V_122 >> 1 ) & 0xffff ;
}
static void F_56 ( unsigned int V_113 , int V_119 , int V_120 , int V_37 )
{
T_5 V_121 = ( 0x05 << 28 ) | ( V_119 << 23 ) | ( V_120 << 18 ) | ( 1 << 17 ) | V_37 ;
int V_18 , V_115 = F_24 ( V_113 ) & V_116 ;
F_53 ( V_113 ) ;
for ( V_18 = 31 ; V_18 >= 0 ; V_18 -- ) {
int V_123 = ( V_121 & ( 1 << V_18 ) ) ? V_117 : V_124 ;
F_54 ( V_115 | V_123 , V_113 ) ;
F_54 ( V_115 | V_123 | V_118 , V_113 ) ;
}
for ( V_18 = 1 ; V_18 >= 0 ; V_18 -- ) {
F_54 ( V_115 , V_113 ) ;
F_54 ( V_115 | V_118 , V_113 ) ;
}
}
static int F_57 ( unsigned int V_34 , int V_126 )
{
int V_18 , V_122 = 0 ;
unsigned int V_127 = V_34 + V_128 ;
int V_129 = V_126 | ( V_130 << 8 ) ;
F_54 ( 0 , V_127 ) ;
F_54 ( V_131 | V_132 , V_127 ) ;
for ( V_18 = 10 ; V_18 >= 0 ; V_18 -- ) {
short V_133 = ( V_129 & ( 1 << V_18 ) ) ? V_134 : 0 ;
F_23 ( V_131 | V_132 | V_133 , V_127 ) ;
F_23 ( V_131 | V_132 | V_133 | V_135 , V_127 ) ;
}
F_54 ( V_131 | V_132 , V_127 ) ;
for ( V_18 = 16 ; V_18 > 0 ; V_18 -- ) {
F_23 ( V_131 | V_132 | V_135 , V_127 ) ;
V_122 = ( V_122 << 1 ) | ( ( F_24 ( V_127 ) & V_136 ) ? 1 : 0 ) ;
F_23 ( V_131 | V_132 , V_127 ) ;
}
F_54 ( 0 , V_127 ) ;
return V_122 ;
}
static void F_58 ( unsigned int V_34 , int V_126 , short V_137 )
{
int V_18 ;
unsigned int V_127 = V_34 + V_128 ;
short V_133 ;
int V_129 = V_126 | ( V_130 << 8 ) ;
V_137 |= F_57 ( V_34 , V_126 ) ;
F_54 ( 0 , V_127 ) ;
F_54 ( V_138 | V_132 | V_136 , V_127 ) ;
V_129 = V_129 >> 1 ;
for ( V_18 = 9 ; V_18 >= 0 ; V_18 -- ) {
V_133 = ( V_129 & ( 1 << V_18 ) ) ? V_134 : 0 ;
F_23 ( V_138 | V_132 | V_136 | V_133 , V_127 ) ;
F_23 ( V_138 | V_132 | V_136 | V_133 | V_135 , V_127 ) ;
F_23 ( V_138 | V_132 | V_136 | V_133 , V_127 ) ;
}
F_54 ( V_138 | V_132 , V_127 ) ;
F_54 ( V_138 | V_132 | V_135 , V_127 ) ;
F_54 ( V_138 | V_132 , V_127 ) ;
for ( V_18 = 15 ; V_18 >= 0 ; V_18 -- ) {
V_133 = ( V_137 & ( 1 << V_18 ) ) ? V_139 : 0 ;
F_23 ( V_138 | V_132 | V_133 , V_127 ) ;
F_23 ( V_138 | V_132 | V_133 | V_135 , V_127 ) ;
F_23 ( V_138 | V_132 | V_133 , V_127 ) ;
}
F_54 ( V_138 | V_136 , V_127 ) ;
F_54 ( V_138 | V_136 | V_135 , V_127 ) ;
F_54 ( V_138 | V_136 , V_127 ) ;
F_54 ( 0 , V_127 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned int V_140 = V_2 -> V_35 ;
T_1 * V_7 = F_1 ( V_2 ) ;
T_3 V_141 ;
if ( V_7 -> V_21 & V_81 ) {
V_141 = F_26 ( V_140 + V_142 ) & ~ 3 ;
if ( V_2 -> V_82 == 2 )
V_141 |= 1 ;
if ( V_7 -> V_21 & V_93 )
V_141 |= 2 ;
if ( V_7 -> V_21 & V_143 )
V_141 |= 8 ;
F_23 ( V_141 , V_140 + V_142 ) ;
}
if ( V_7 -> V_21 & V_105 ) {
if ( V_7 -> V_21 & V_144 ) {
F_56 ( V_140 + V_145 , V_7 -> V_146 , 4 , 0x01e1 ) ;
F_56 ( V_140 + V_145 , V_7 -> V_146 , 0 , 0x0000 ) ;
F_56 ( V_140 + V_145 , V_7 -> V_146 , 0 , 0x1200 ) ;
V_7 -> V_147 = V_148 ;
} else {
F_54 ( V_149 ? 4 : 0 , V_140 + V_150 ) ;
}
} else if ( V_7 -> V_21 & V_104 ) {
F_56 ( V_140 + V_145 , V_7 -> V_146 , 4 , 0x01e1 ) ;
F_56 ( V_140 + V_145 , V_7 -> V_146 , 0 , 0x0000 ) ;
F_56 ( V_140 + V_145 , V_7 -> V_146 , 0 , 0x1200 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
T_1 * V_7 = F_1 ( V_2 ) ;
unsigned int V_151 = V_2 -> V_35 + V_145 ;
int V_18 ;
T_5 V_141 , V_152 ;
for ( V_18 = 31 ; V_18 >= 0 ; V_18 -- ) {
V_141 = F_55 ( V_151 , V_18 , 1 ) ;
if ( ( V_141 == 0 ) || ( V_141 == 0xffff ) )
continue;
V_141 = F_55 ( V_151 , V_18 , V_153 ) ;
V_152 = V_141 << 16 ;
V_152 |= F_55 ( V_151 , V_18 , V_154 ) ;
V_152 &= V_155 ;
F_60 ( V_2 , L_19 , V_18 , V_152 ) ;
if ( V_152 == V_156 ) {
V_7 -> V_107 = V_18 ;
} else if ( V_152 != V_157 ) {
V_7 -> V_146 = V_18 ;
}
}
}
static int F_61 ( struct V_1 * V_2 )
{
int V_63 ;
T_1 * V_7 = F_1 ( V_2 ) ;
struct V_5 * V_6 = V_7 -> V_9 ;
unsigned int V_140 = V_2 -> V_35 ;
F_4 ( & V_6 -> V_2 , L_20 , V_2 -> V_101 ) ;
if ( ! F_62 ( V_6 ) )
return - V_111 ;
F_59 ( V_2 ) ;
F_23 ( 0xFF , V_140 + V_47 ) ;
V_63 = F_63 ( V_2 -> V_75 , V_158 , V_159 , V_2 -> V_101 , V_2 ) ;
if ( V_63 )
return V_63 ;
V_6 -> V_112 ++ ;
V_7 -> V_119 = V_7 -> V_146 ;
V_7 -> V_160 = 0x00 ;
F_64 ( & V_7 -> V_161 ) ;
V_7 -> V_161 . V_162 = V_163 ;
V_7 -> V_161 . V_164 = ( V_165 ) V_2 ;
V_7 -> V_161 . V_166 = V_148 + V_167 ;
F_65 ( & V_7 -> V_161 ) ;
return F_66 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 * V_7 = F_1 ( V_2 ) ;
struct V_5 * V_6 = V_7 -> V_9 ;
F_4 ( & V_6 -> V_2 , L_21 , V_2 -> V_101 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 -> V_75 , V_2 ) ;
V_6 -> V_112 -- ;
F_70 ( V_2 ) ;
F_71 ( & V_7 -> V_161 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned int V_140 = V_2 -> V_35 ;
int V_18 ;
V_100 . V_168 = V_100 . V_169 = 0 ;
F_23 ( V_39 + V_40 + V_41 , V_140 + V_42 ) ;
F_54 ( F_24 ( V_140 + V_170 ) , V_140 + V_170 ) ;
for ( V_18 = 0 ; V_18 < 100 ; V_18 ++ ) {
if ( ( F_26 ( V_140 + V_47 ) & V_171 ) != 0 )
break;
F_72 ( 100 ) ;
}
F_23 ( V_171 , V_140 + V_47 ) ;
if ( V_18 == 100 )
F_73 ( V_2 , L_22 ) ;
F_59 ( V_2 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
T_1 * V_7 = F_1 ( V_2 ) ;
if ( ( V_173 -> V_174 != ( T_3 ) ( - 1 ) ) && ( V_173 -> V_174 != V_2 -> V_82 ) ) {
if ( ! ( V_7 -> V_21 & V_81 ) )
return - V_175 ;
else if ( ( V_173 -> V_174 < 1 ) || ( V_173 -> V_174 > 2 ) )
return - V_72 ;
V_2 -> V_82 = V_173 -> V_174 ;
F_46 ( V_2 , L_23 , V_110 [ V_2 -> V_82 ] ) ;
F_51 ( V_2 , 1 ) ;
}
return 0 ;
}
static T_6 V_158 ( int V_75 , void * V_176 )
{
struct V_1 * V_2 = V_176 ;
T_1 * V_7 ;
T_6 V_63 = F_75 ( V_75 , V_176 ) ;
if ( V_63 == V_177 ) {
V_7 = F_1 ( V_2 ) ;
V_7 -> V_178 = 0 ;
}
return V_63 ;
}
static void V_163 ( V_165 V_179 )
{
struct V_1 * V_2 = (struct V_1 * ) V_179 ;
T_1 * V_7 = F_1 ( V_2 ) ;
unsigned int V_140 = V_2 -> V_35 ;
unsigned int V_151 = V_140 + V_145 ;
T_7 V_6 ;
if ( ! F_76 ( V_2 ) ) goto V_180;
if ( V_7 -> V_178 ++ && ( F_26 ( V_140 + V_47 ) & V_181 ) ) {
if ( ! V_7 -> V_182 )
F_46 ( V_2 , L_24 ) ;
V_158 ( V_2 -> V_75 , V_2 ) ;
V_7 -> V_182 = V_167 ;
}
if ( V_7 -> V_182 ) {
V_7 -> V_182 -- ;
V_7 -> V_161 . V_166 = V_148 + 1 ;
F_65 ( & V_7 -> V_161 ) ;
return;
}
if ( ! ( V_7 -> V_21 & V_144 ) )
goto V_180;
F_55 ( V_151 , V_7 -> V_119 , 1 ) ;
V_6 = F_55 ( V_151 , V_7 -> V_119 , 1 ) ;
if ( ! V_6 || ( V_6 == 0xffff ) ) {
if ( V_7 -> V_146 ) {
V_7 -> V_119 = V_7 -> V_146 = 0 ;
} else {
F_46 ( V_2 , L_25 ) ;
V_7 -> V_21 &= ~ V_144 ;
}
goto V_180;
}
V_6 &= 0x0004 ;
if ( V_6 != V_7 -> V_160 ) {
T_7 V_3 = F_55 ( V_151 , V_7 -> V_119 , 5 ) ;
F_46 ( V_2 , L_26 , V_6 ? L_27 : L_28 ) ;
if ( V_6 && ( V_7 -> V_21 & V_105 ) ) {
F_54 ( ( V_3 & 0x0140 ) ? 4 : 0 , V_140 + V_150 ) ;
} else if ( V_6 && ( V_7 -> V_21 & V_104 ) ) {
F_58 ( V_2 -> V_35 , 4 , ( V_3 & 0x140 ) ? V_183 : 0 ) ;
}
if ( V_6 ) {
if ( V_7 -> V_119 == V_7 -> V_146 ) {
if ( V_3 )
F_46 ( V_2 , L_29
L_30 ,
( ( V_3 & 0x0180 ) ? L_31 : L_32 ) ,
( ( V_3 & 0x0140 ) ? 'F' : 'H' ) ) ;
else
F_46 ( V_2 , L_33 ) ;
}
F_51 ( V_2 , 1 ) ;
}
V_7 -> V_160 = V_6 ;
}
if ( V_7 -> V_107 && F_77 ( V_148 , V_7 -> V_147 + 6 * V_167 ) ) {
V_6 = F_55 ( V_151 , V_7 -> V_146 , 1 ) & 0x0004 ;
if ( ( ( V_7 -> V_119 == V_7 -> V_107 ) && V_6 ) ||
( ( V_7 -> V_119 != V_7 -> V_107 ) && ! V_6 ) ) {
F_56 ( V_151 , V_7 -> V_119 , 0 , 0x0400 ) ;
V_7 -> V_119 ^= V_7 -> V_107 ^ V_7 -> V_146 ;
F_46 ( V_2 , L_34 ,
( V_7 -> V_119 == V_7 -> V_146 ) ? L_35 : L_36 ) ;
F_56 ( V_151 , V_7 -> V_119 , 0 ,
( V_7 -> V_119 == V_7 -> V_146 ) ? 0x1000 : 0 ) ;
V_7 -> V_160 = 0 ;
V_7 -> V_147 = V_148 ;
}
}
V_180:
V_7 -> V_161 . V_166 = V_148 + V_167 ;
F_65 ( & V_7 -> V_161 ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_184 * V_185 , int V_121 )
{
T_1 * V_7 = F_1 ( V_2 ) ;
struct V_186 * V_164 = F_79 ( V_185 ) ;
unsigned int V_151 = V_2 -> V_35 + V_145 ;
if ( ! ( V_7 -> V_21 & ( V_104 | V_105 ) ) )
return - V_72 ;
switch ( V_121 ) {
case V_187 :
V_164 -> V_119 = V_7 -> V_119 ;
case V_188 :
V_164 -> V_189 = F_55 ( V_151 , V_164 -> V_119 , V_164 -> V_190 & 0x1f ) ;
return 0 ;
case V_191 :
F_56 ( V_151 , V_164 -> V_119 , V_164 -> V_190 & 0x1f , V_164 -> V_192 ) ;
return 0 ;
}
return - V_175 ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_193 * V_194 ,
int V_195 )
{
unsigned int V_140 = V_2 -> V_35 ;
if ( V_100 . V_169 ) {
F_81 ( V_2 , L_37
L_38 ,
V_100 . V_169 , V_100 . V_196 ) ;
return;
}
V_100 . V_169 |= 0x01 ;
F_23 ( V_39 + V_40 + V_55 , V_140 + V_197 ) ;
F_23 ( sizeof( struct V_193 ) , V_140 + V_44 ) ;
F_23 ( 0 , V_140 + V_45 ) ;
F_23 ( 0 , V_140 + V_52 ) ;
F_23 ( V_195 , V_140 + V_53 ) ;
F_23 ( V_54 + V_55 , V_140 + V_197 ) ;
F_82 ( V_140 + V_56 , V_194 ,
sizeof( struct V_193 ) >> 1 ) ;
V_194 -> V_198 = F_83 ( V_194 -> V_198 ) ;
F_23 ( V_199 , V_140 + V_47 ) ;
V_100 . V_169 &= ~ 0x01 ;
}
static void F_84 ( struct V_1 * V_2 , int V_198 ,
struct V_200 * V_201 , int V_202 )
{
unsigned int V_140 = V_2 -> V_35 ;
int V_203 = V_198 ;
char * V_204 = V_201 -> V_164 ;
if ( ( V_205 > 4 ) && ( V_198 != 4 ) )
F_60 ( V_2 , L_39 , V_198 + 4 ) ;
if ( V_100 . V_169 ) {
F_81 ( V_2 , L_37
L_38 ,
V_100 . V_169 , V_100 . V_196 ) ;
return;
}
V_100 . V_169 |= 0x01 ;
F_23 ( V_39 + V_40 + V_55 , V_140 + V_197 ) ;
F_23 ( V_198 & 0xff , V_140 + V_44 ) ;
F_23 ( V_198 >> 8 , V_140 + V_45 ) ;
F_23 ( V_202 & 0xff , V_140 + V_52 ) ;
F_23 ( V_202 >> 8 , V_140 + V_53 ) ;
F_23 ( V_54 + V_55 , V_140 + V_197 ) ;
F_82 ( V_140 + V_56 , V_204 , V_198 >> 1 ) ;
if ( V_198 & 0x01 )
V_204 [ V_198 - 1 ] = F_24 ( V_140 + V_56 ) , V_203 ++ ;
#ifdef F_85
if ( V_205 > 4 ) {
int V_113 , V_206 = 20 ;
do {
int V_207 = F_26 ( V_140 + V_53 ) ;
int V_208 = F_26 ( V_140 + V_52 ) ;
V_113 = ( V_207 << 8 ) + V_208 ;
if ( ( ( V_202 + V_203 ) & 0xff ) == ( V_113 & 0xff ) )
break;
} while ( -- V_206 > 0 );
if ( V_206 <= 0 )
F_81 ( V_2 , L_40
L_41 ,
V_202 + V_203 , V_113 ) ;
}
#endif
F_23 ( V_199 , V_140 + V_47 ) ;
V_100 . V_169 &= ~ 0x01 ;
}
static void F_86 ( struct V_1 * V_2 , int V_198 ,
const T_3 * V_204 , const int V_209 )
{
unsigned int V_140 = V_2 -> V_35 ;
T_1 * V_7 = F_1 ( V_2 ) ;
#ifdef F_85
int V_210 = 0 ;
#endif
V_165 V_211 ;
#ifdef F_85
if ( V_205 > 4 )
F_60 ( V_2 , L_42 , V_198 ) ;
#endif
if ( V_198 & 0x01 )
V_198 ++ ;
if ( V_100 . V_169 ) {
F_81 ( V_2 , L_43
L_38 ,
V_100 . V_169 , V_100 . V_196 ) ;
return;
}
V_100 . V_169 |= 0x01 ;
F_23 ( V_40 + V_55 + V_39 , V_140 + V_197 ) ;
#ifdef F_85
V_212:
#endif
F_23 ( V_199 , V_140 + V_47 ) ;
F_23 ( V_198 & 0xff , V_140 + V_44 ) ;
F_23 ( V_198 >> 8 , V_140 + V_45 ) ;
F_23 ( 0x00 , V_140 + V_52 ) ;
F_23 ( V_209 , V_140 + V_53 ) ;
F_23 ( V_213 + V_55 , V_140 + V_197 ) ;
F_87 ( V_140 + V_56 , V_204 , V_198 >> 1 ) ;
V_211 = V_148 ;
#ifdef F_85
if ( V_205 > 4 ) {
int V_113 , V_206 = 20 ;
do {
int V_207 = F_26 ( V_140 + V_53 ) ;
int V_208 = F_26 ( V_140 + V_52 ) ;
V_113 = ( V_207 << 8 ) + V_208 ;
if ( ( V_209 << 8 ) + V_198 == V_113 )
break;
} while ( -- V_206 > 0 );
if ( V_206 <= 0 ) {
F_81 ( V_2 , L_44
L_41 ,
( V_209 << 8 ) + V_198 , V_113 ) ;
if ( V_210 ++ == 0 )
goto V_212;
}
}
#endif
while ( ( F_26 ( V_140 + V_47 ) & V_199 ) == 0 )
if ( F_77 ( V_148 , V_211 + V_214 ) ) {
F_81 ( V_2 , L_45 ) ;
F_20 ( V_2 ) ;
F_51 ( V_2 , 1 ) ;
break;
}
F_23 ( V_199 , V_140 + V_47 ) ;
if ( V_7 -> V_21 & V_88 )
F_72 ( ( long ) V_215 ) ;
V_100 . V_169 &= ~ 0x01 ;
}
static int F_41 ( struct V_5 * V_6 , int V_83 ,
int V_84 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
V_100 . V_216 = V_83 ;
V_100 . V_217 = V_83 + V_218 ;
V_100 . V_219 = V_84 ;
V_100 . V_220 = F_80 ;
V_100 . V_221 = F_84 ;
V_100 . V_222 = F_86 ;
return 0 ;
}
static void F_88 ( void * V_223 , void T_4 * V_224 , int V_225 )
{
T_7 * V_226 = V_223 ;
T_7 T_4 * V_227 = V_224 ;
int V_228 ;
if ( V_225 <= 0 )
return;
V_228 = ( V_225 & 1 ) ; V_225 >>= 1 ;
if ( V_225 ) {
do { * V_226 ++ = F_89 ( V_227 ++ ) ; } while ( -- V_225 );
}
if ( V_228 )
* ( ( T_3 * ) V_226 ) = F_90 ( V_227 ) & 0xff ;
}
static void F_91 ( void T_4 * V_223 , const void * V_224 , int V_225 )
{
T_7 T_4 * V_226 = V_223 ;
const T_7 * V_227 = V_224 ;
int V_228 ;
if ( V_225 <= 0 )
return;
V_228 = ( V_225 & 1 ) ; V_225 >>= 1 ;
if ( V_225 ) {
do { F_92 ( * V_227 ++ , V_226 ++ ) ; } while ( -- V_225 );
}
if ( V_228 )
F_93 ( ( F_90 ( V_226 ) & 0xff00 ) | * ( T_3 * ) V_227 , V_226 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_193 * V_194 ,
int V_195 )
{
void T_4 * V_229 = V_100 . V_230 + ( V_218 << 8 )
+ ( V_195 << 8 )
- ( V_100 . V_217 << 8 ) ;
F_88 ( V_194 , V_229 , sizeof( struct V_193 ) ) ;
V_194 -> V_198 = F_83 ( V_194 -> V_198 ) ;
}
static void F_95 ( struct V_1 * V_2 , int V_198 ,
struct V_200 * V_201 , int V_202 )
{
void T_4 * V_16 = V_100 . V_230 ;
unsigned long V_29 = ( V_218 << 8 ) + V_202
- ( V_100 . V_217 << 8 ) ;
char * V_204 = V_201 -> V_164 ;
if ( V_29 + V_198 > V_100 . V_10 ) {
int V_231 = V_100 . V_10 - V_29 ;
F_88 ( V_204 , V_16 + V_29 , V_231 ) ;
V_204 += V_231 ;
V_29 = V_218 << 8 ;
V_198 -= V_231 ;
}
F_88 ( V_204 , V_16 + V_29 , V_198 ) ;
}
static void F_96 ( struct V_1 * V_2 , int V_198 ,
const T_3 * V_204 , const int V_209 )
{
void T_4 * V_232 = V_100 . V_230 + ( V_209 << 8 ) ;
V_232 -= V_100 . V_216 << 8 ;
F_91 ( V_232 , V_204 , V_198 ) ;
}
static int F_40 ( struct V_5 * V_6 , int V_83 ,
int V_84 , int V_85 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_1 * V_7 = F_1 ( V_2 ) ;
int V_18 , V_233 , V_29 , V_63 ;
V_233 = ( V_84 - V_83 ) << 8 ;
if ( V_233 > 32 * 1024 )
V_233 = 32 * 1024 ;
V_233 = F_97 ( V_233 ) ;
V_6 -> V_20 [ 3 ] -> V_21 |= V_234 | V_235 | V_24 ;
V_6 -> V_20 [ 3 ] -> V_21 |= V_236 ;
V_6 -> V_20 [ 3 ] -> V_25 = 0 ; V_6 -> V_20 [ 3 ] -> V_26 = V_233 ;
V_63 = F_12 ( V_6 , V_6 -> V_20 [ 3 ] , V_237 ) ;
if ( V_63 )
goto V_86;
V_29 = ( V_83 << 8 ) + V_85 ;
V_29 -= V_29 % V_233 ;
V_63 = F_15 ( V_6 , V_6 -> V_20 [ 3 ] , V_29 ) ;
if ( V_63 )
goto V_86;
V_7 -> V_16 = F_13 ( V_6 -> V_20 [ 3 ] -> V_25 ,
F_14 ( V_6 -> V_20 [ 3 ] ) ) ;
for ( V_18 = 0 ; V_18 < ( V_218 << 8 ) ; V_18 += 2 )
F_92 ( ( V_18 >> 1 ) , V_7 -> V_16 + V_29 + V_18 ) ;
F_72 ( 100 ) ;
for ( V_18 = 0 ; V_18 < ( V_218 << 8 ) ; V_18 += 2 )
if ( F_89 ( V_7 -> V_16 + V_29 + V_18 ) != ( V_18 >> 1 ) ) break;
F_20 ( V_2 ) ;
if ( V_18 != ( V_218 << 8 ) ) {
F_17 ( V_7 -> V_16 ) ;
F_18 ( V_6 , V_6 -> V_20 [ 3 ] ) ;
V_7 -> V_16 = NULL ;
goto V_86;
}
V_100 . V_230 = V_7 -> V_16 + V_29 ;
V_100 . V_10 = F_14 ( V_6 -> V_20 [ 3 ] ) ;
V_2 -> V_109 = ( V_165 ) V_100 . V_230 ;
V_2 -> V_238 = V_2 -> V_109 + F_14 ( V_6 -> V_20 [ 3 ] ) ;
V_100 . V_216 = V_83 ;
V_100 . V_217 = V_83 + V_218 ;
V_100 . V_219 = V_83 + (
( F_14 ( V_6 -> V_20 [ 3 ] ) - V_29 ) >> 8 ) ;
V_100 . V_220 = F_94 ;
V_100 . V_221 = F_95 ;
V_100 . V_222 = F_96 ;
V_7 -> V_21 |= V_108 ;
return 0 ;
V_86:
return 1 ;
}
static int T_8 F_98 ( void )
{
return F_99 ( & V_239 ) ;
}
static void T_9 F_100 ( void )
{
F_101 ( & V_239 ) ;
}
