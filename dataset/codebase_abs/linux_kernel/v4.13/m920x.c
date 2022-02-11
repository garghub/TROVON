static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , void * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_3 , V_9 | V_10 ,
V_4 , V_5 , V_6 , V_7 , 2000 ) ;
if ( V_8 < 0 ) {
F_4 ( V_11 L_1 , V_8 ) ;
return V_8 ;
}
if ( V_8 != V_7 ) {
F_5 ( L_2 ) ;
return - V_12 ;
}
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
return F_2 ( V_2 , F_7 ( V_2 , 0 ) , V_3 ,
V_9 | V_13 , V_4 , V_5 ,
NULL , 0 , 2000 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_14 * V_15 )
{
int V_8 ;
do {
V_8 = F_6 ( V_2 , V_3 , V_15 -> V_6 , V_15 -> V_16 ) ;
if ( V_8 != 0 )
return V_8 ;
V_15 ++ ;
} while ( V_15 -> V_16 );
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , struct V_14 * V_19 )
{
int V_8 , V_20 , V_21 , V_22 = 0 ;
int V_23 [ V_24 ] = { 0 } ;
if ( V_18 -> V_25 . V_26 . V_27 . V_28 || V_18 -> V_25 . V_26 . V_29 . V_28 ) {
F_5 ( L_3 ) ;
V_8 = F_8 ( V_18 -> V_2 , V_30 , V_19 ) ;
if ( V_8 != 0 ) {
F_5 ( L_4 ) ;
return V_8 ;
}
F_5 ( L_5 ) ;
}
for ( V_20 = 0 ; V_20 < V_18 -> V_25 . V_31 ; V_20 ++ )
V_22 |= V_18 -> V_32 [ V_20 ] . V_25 . V_33 [ 0 ] . V_34 ;
if ( V_22 & V_35 ) {
for ( V_20 = 0 ; V_20 < V_18 -> V_25 . V_31 ; V_20 ++ ) {
V_21 = V_18 -> V_32 [ V_20 ] . V_25 . V_33 [ 0 ] . V_36 . V_37 - 0x81 ;
if ( V_21 < 0 || V_21 >= V_24 ) {
F_4 ( V_11 L_6 ) ;
return - V_38 ;
}
V_23 [ V_21 ] = 1 ;
}
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_23 [ V_20 ] )
continue;
if ( ( V_8 = F_10 ( V_18 , 0x81 + V_20 , 0 , 0x0 ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_10 ( V_18 , 0x81 + V_20 , 0 , 0x02f5 ) ) != 0 )
return V_8 ;
}
}
return 0 ;
}
static int F_11 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_41 * V_42 ;
if ( ( V_42 = F_13 ( V_40 , 1 ) ) == NULL ) {
F_5 ( L_7 ) ;
return - V_43 ;
}
return F_14 ( V_2 , V_42 -> V_44 . V_45 ,
V_42 -> V_44 . V_46 ) ;
}
static inline void F_15 ( struct V_17 * V_18 , T_1 V_47 ,
int * V_48 )
{
struct V_49 * V_50 = V_18 -> V_51 ;
switch ( V_47 ) {
case 0x80 :
* V_48 = V_52 ;
break;
case 0x88 :
case 0x99 :
case 0xc0 :
case 0xd8 :
* V_48 = V_52 ;
V_50 -> V_53 = 0 ;
break;
case 0x93 :
case 0x92 :
case 0x83 :
case 0x82 :
V_50 -> V_53 = 0 ;
* V_48 = V_54 ;
break;
case 0x91 :
case 0x81 :
if ( ++ V_50 -> V_53 > 2 )
* V_48 = V_55 ;
else
* V_48 = V_52 ;
break;
default:
F_5 ( L_8 , V_47 ) ;
* V_48 = V_52 ;
break;
}
}
static int F_16 ( struct V_17 * V_18 , T_3 * V_56 , int * V_48 )
{
int V_20 , V_8 = 0 ;
T_1 * V_47 ;
V_47 = F_17 ( 2 , V_57 ) ;
if ( ! V_47 )
return - V_58 ;
V_8 = F_1 ( V_18 -> V_2 , V_30 , 0x0 , V_59 ,
V_47 , 1 ) ;
if ( V_8 != 0 )
goto V_60;
V_8 = F_1 ( V_18 -> V_2 , V_30 , 0x0 , V_61 ,
V_47 + 1 , 1 ) ;
if ( V_8 != 0 )
goto V_60;
F_15 ( V_18 , V_47 [ 0 ] , V_48 ) ;
for ( V_20 = 0 ; V_20 < V_18 -> V_25 . V_26 . V_27 . V_62 ; V_20 ++ )
if ( F_18 ( & V_18 -> V_25 . V_26 . V_27 . V_63 [ V_20 ] ) == V_47 [ 1 ] ) {
* V_56 = V_18 -> V_25 . V_26 . V_27 . V_63 [ V_20 ] . V_64 ;
goto V_60;
}
if ( V_47 [ 1 ] != 0 )
F_5 ( L_9 , V_47 [ 1 ] ) ;
* V_48 = V_52 ;
V_60:
F_19 ( V_47 ) ;
return V_8 ;
}
static int F_20 ( struct V_17 * V_18 )
{
int V_8 = 0 ;
T_1 * V_47 ;
int V_48 ;
V_47 = F_17 ( 2 , V_57 ) ;
if ( ! V_47 )
return - V_58 ;
if ( ( V_8 = F_1 ( V_18 -> V_2 , V_30 , 0x0 , V_59 , & V_47 [ 0 ] , 1 ) ) != 0 )
goto V_60;
if ( ( V_8 = F_1 ( V_18 -> V_2 , V_30 , 0x0 , V_61 , & V_47 [ 1 ] , 1 ) ) != 0 )
goto V_60;
F_5 ( L_10 , V_47 [ 0 ] , V_47 [ 1 ] ) ;
F_15 ( V_18 , V_47 [ 0 ] , & V_48 ) ;
if ( V_48 == V_52 )
F_21 ( V_18 -> V_65 ) ;
else if ( V_48 == V_55 )
F_22 ( V_18 -> V_65 ) ;
else
F_23 ( V_18 -> V_65 , V_66 , V_47 [ 1 ] , 0 ) ;
V_60:
F_19 ( V_47 ) ;
return V_8 ;
}
static int F_24 ( struct V_67 * V_68 , struct V_69 V_70 [] , int V_71 )
{
struct V_17 * V_18 = F_25 ( V_68 ) ;
int V_20 , V_72 ;
int V_8 = 0 ;
if ( ! V_71 )
return - V_38 ;
if ( F_26 ( & V_18 -> V_73 ) < 0 )
return - V_74 ;
for ( V_20 = 0 ; V_20 < V_71 ; V_20 ++ ) {
if ( V_70 [ V_20 ] . V_22 & ( V_75 | V_76 | V_77 ) || V_70 [ V_20 ] . V_78 == 0 ) {
V_8 = - V_79 ;
goto V_80;
}
if ( ! ( V_70 [ V_20 ] . V_22 & V_81 ) ) {
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_82 ,
( V_70 [ V_20 ] . V_83 << 1 ) |
( V_70 [ V_20 ] . V_22 & V_84 ? 0x01 : 0 ) , 0x80 ) ) != 0 )
goto V_80;
}
if ( V_70 [ V_20 ] . V_22 & V_84 ) {
for ( V_72 = 0 ; V_72 < V_70 [ V_20 ] . V_78 ; V_72 ++ ) {
int V_85 = ( V_20 + 1 == V_71 && V_72 + 1 == V_70 [ V_20 ] . V_78 ) ? 0x40 : 0x01 ;
if ( ( V_8 = F_1 ( V_18 -> V_2 , V_82 , 0x0 ,
0x20 | V_85 ,
& V_70 [ V_20 ] . V_86 [ V_72 ] , 1 ) ) != 0 )
goto V_80;
}
} else {
for ( V_72 = 0 ; V_72 < V_70 [ V_20 ] . V_78 ; V_72 ++ ) {
int V_85 = ( V_20 + 1 == V_71 && V_72 + 1 == V_70 [ V_20 ] . V_78 ) ? 0x40 : 0x00 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_82 , V_70 [ V_20 ] . V_86 [ V_72 ] , V_85 ) ) != 0 )
goto V_80;
}
}
}
V_8 = V_71 ;
V_80:
F_27 ( & V_18 -> V_73 ) ;
return V_8 ;
}
static T_3 F_28 ( struct V_67 * V_32 )
{
return V_87 ;
}
static int F_10 ( struct V_17 * V_18 , int type , int V_88 , int V_89 )
{
int V_8 = 0 ;
if ( V_89 >= 0x8000 )
return - V_38 ;
V_89 |= 0x8000 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_90 , V_89 , ( type << 8 ) | ( V_88 * 4 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_90 , 0 , ( type << 8 ) | ( V_88 * 4 ) ) ) != 0 )
return V_8 ;
return V_8 ;
}
static int F_29 ( struct V_91 * V_68 )
{
struct V_49 * V_50 = V_68 -> V_92 -> V_51 ;
int V_93 = V_50 -> V_94 [ V_68 -> V_95 ] ;
int V_20 , V_8 = 0 , V_96 = 0 ;
int V_97 = V_68 -> V_25 . V_33 [ 0 ] . V_36 . V_37 ;
for ( V_20 = 0 ; V_20 < V_98 ; V_20 ++ )
if ( V_50 -> V_99 [ V_68 -> V_95 ] [ V_20 ] == 8192 )
V_93 = 0 ;
if ( ( V_8 = F_10 ( V_68 -> V_92 , V_97 , 1 , V_93 ) ) != 0 )
return V_8 ;
for ( V_20 = 0 ; V_20 < V_98 ; V_20 ++ )
if ( ( V_8 = F_10 ( V_68 -> V_92 , V_97 , V_20 + 2 , 0 ) ) != 0 )
return V_8 ;
if ( V_93 ) {
for ( V_20 = 0 ; V_20 < V_98 ; V_20 ++ ) {
if ( V_50 -> V_99 [ V_68 -> V_95 ] [ V_20 ] == 0 )
continue;
if ( ( V_8 = F_10 ( V_68 -> V_92 , V_97 , V_96 + 2 , V_50 -> V_99 [ V_68 -> V_95 ] [ V_20 ] ) ) != 0 )
return V_8 ;
V_96 ++ ;
}
}
return V_8 ;
}
static int F_30 ( struct V_91 * V_68 , int V_100 )
{
struct V_49 * V_50 = V_68 -> V_92 -> V_51 ;
V_50 -> V_94 [ V_68 -> V_95 ] = V_100 ? 1 : 0 ;
return F_29 ( V_68 ) ;
}
static int F_31 ( struct V_91 * V_68 , int V_5 , T_2 V_89 , int V_100 )
{
struct V_49 * V_50 = V_68 -> V_92 -> V_51 ;
V_50 -> V_99 [ V_68 -> V_95 ] [ V_5 ] = V_100 ? V_89 : 0 ;
return F_29 ( V_68 ) ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_101 * V_102 )
{
T_2 V_4 , V_5 , V_7 ;
T_1 * V_103 , * V_104 ;
int V_20 , V_105 , V_8 = 0 ;
V_104 = F_17 ( 65536 , V_57 ) ;
if ( V_104 == NULL )
return - V_58 ;
V_103 = F_17 ( 4 , V_57 ) ;
if ( ! V_103 ) {
F_19 ( V_104 ) ;
return - V_58 ;
}
if ( ( V_8 = F_1 ( V_2 , V_90 , 0x0 , 0x8000 , V_103 , 4 ) ) != 0 )
goto V_106;
F_5 ( L_11 , 4 , V_103 ) ;
if ( ( V_8 = F_1 ( V_2 , V_107 , 0x0 , 0x0 , V_103 , 1 ) ) != 0 )
goto V_106;
F_5 ( L_12 , V_103 [ 0 ] ) ;
for ( V_105 = 0 ; V_105 < 2 ; V_105 ++ ) {
for ( V_20 = 0 ; V_20 + ( sizeof( T_2 ) * 3 ) < V_102 -> V_7 ; ) {
V_4 = F_33 ( V_102 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
V_5 = F_33 ( V_102 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
V_7 = F_33 ( V_102 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
if ( V_105 == 1 ) {
memcpy ( V_104 , V_102 -> V_6 + V_20 , V_7 ) ;
V_8 = F_2 ( V_2 , F_7 ( V_2 , 0 ) ,
V_107 ,
V_9 | V_13 ,
V_4 , V_5 , V_104 , V_7 , 20 ) ;
if ( V_8 != V_7 ) {
F_5 ( L_13 ) ;
V_8 = - V_12 ;
goto V_106;
}
F_34 ( 3 ) ;
}
V_20 += V_7 ;
}
if ( V_20 != V_102 -> V_7 ) {
F_5 ( L_14 ) ;
V_8 = - V_38 ;
goto V_106;
}
}
F_34 ( 36 ) ;
( void ) F_6 ( V_2 , V_30 , 0x01 , V_108 ) ;
F_5 ( L_15 ) ;
V_106:
F_19 ( V_103 ) ;
F_19 ( V_104 ) ;
return V_8 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_109 * V_25 ,
struct V_110 * * V_44 ,
int * V_111 )
{
struct V_41 * V_42 ;
V_42 = F_13 ( F_36 ( V_2 , 0 ) , 1 ) ;
* V_111 = ( V_42 == NULL ) ? 1 : 0 ;
return 0 ;
}
static int F_37 ( struct V_112 * V_33 )
{
int V_8 ;
T_1 V_113 [] = { V_114 , 0x3d } ;
T_1 clock [] = { V_115 , 0x30 } ;
T_1 V_116 [] = { V_117 , 0x80 } ;
T_1 V_118 [] = { V_119 , 0x40 } ;
T_1 V_120 [] = { V_121 , 0x1c , 0x20 } ;
T_1 V_122 [] = { 0x69 , 0x00 , 0xff , 0xff , 0x40 , 0xff , 0x00 , 0x40 , 0x40 } ;
T_1 V_123 [] = { 0x93 , 0x1a } ;
T_1 V_124 [] = { 0xb5 , 0x7a } ;
F_5 ( L_16 ) ;
if ( ( V_8 = F_38 ( V_33 , V_113 , F_39 ( V_113 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , clock , F_39 ( clock ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_116 , F_39 ( V_116 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_118 , F_39 ( V_118 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_120 , F_39 ( V_120 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_122 , F_39 ( V_122 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_123 , F_39 ( V_123 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_124 , F_39 ( V_124 ) ) ) != 0 )
return V_8 ;
return 0 ;
}
static int F_40 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
V_68 -> V_126 [ 0 ] . V_33 = F_41 ( V_127 ,
& V_128 ,
& V_68 -> V_92 -> V_129 ) ;
if ( ( V_68 -> V_126 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_42 ( struct V_91 * V_68 )
{
struct V_14 V_130 [] = {
{ 0xff28 , 0x00 } ,
{ 0xff23 , 0x00 } ,
{ 0xff28 , 0x00 } ,
{ 0xff23 , 0x00 } ,
{ 0xff21 , 0x20 } ,
{ 0xff21 , 0x60 } ,
{ 0xff28 , 0x00 } ,
{ 0xff22 , 0x00 } ,
{ 0xff20 , 0x30 } ,
{ 0xff20 , 0x20 } ,
{ 0xff20 , 0x30 } ,
{ }
} ;
int V_8 ;
F_5 ( L_17 , V_125 ) ;
V_8 = F_8 ( V_68 -> V_92 -> V_2 , V_30 , V_130 ) ;
if ( V_8 != 0 ) {
F_5 ( L_18 ) ;
return V_8 ;
}
return F_40 ( V_68 ) ;
}
static int F_43 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
V_68 -> V_126 [ 0 ] . V_33 = F_41 ( V_131 ,
& V_132 ,
& V_68 -> V_92 -> V_129 ) ;
if ( ( V_68 -> V_126 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_44 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
V_68 -> V_126 [ 0 ] . V_33 = F_41 ( V_131 ,
& V_133 ,
& V_68 -> V_92 -> V_129 ) ;
if ( ( V_68 -> V_126 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_45 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
if ( F_41 ( V_134 , V_68 -> V_126 [ 0 ] . V_33 , & V_68 -> V_92 -> V_129 , & V_135 ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_46 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
if ( F_41 ( V_136 , V_68 -> V_126 [ 0 ] . V_33 , 0x60 , & V_68 -> V_92 -> V_129 , NULL ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_47 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
if ( F_41 ( V_136 , V_68 -> V_126 [ 0 ] . V_33 , 0x61 , & V_68 -> V_92 -> V_129 , NULL ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_48 ( struct V_91 * V_68 )
{
F_41 ( V_137 , V_68 -> V_126 [ 0 ] . V_33 ,
& V_68 -> V_92 -> V_129 , 0x61 ,
V_138 ) ;
return 0 ;
}
static int F_49 ( struct V_91 * V_68 )
{
F_5 ( L_17 , V_125 ) ;
if ( F_41 ( V_139 , V_68 -> V_126 [ 0 ] . V_33 , & V_68 -> V_92 -> V_129 ,
& V_140 , 1220 ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_50 ( struct V_39 * V_40 ,
const struct V_141 * V_95 )
{
struct V_17 * V_18 = NULL ;
int V_8 ;
struct V_14 * V_142 = NULL ;
int V_45 = V_40 -> V_143 -> V_44 . V_45 ;
F_5 ( L_19 , V_45 ) ;
if ( V_45 == 0 ) {
V_8 = F_51 ( V_40 , & V_144 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
V_142 = V_147 ;
goto V_148;
}
V_8 = F_51 ( V_40 , & V_149 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
goto V_148;
}
V_8 = F_51 ( V_40 , & V_150 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
V_142 = V_151 ;
goto V_148;
}
V_8 = F_51 ( V_40 , & V_152 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
goto V_148;
}
V_8 = F_51 ( V_40 , & V_153 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
V_142 = V_154 ;
goto V_148;
}
V_8 = F_51 ( V_40 , & V_155 ,
V_145 , & V_18 , V_146 ) ;
if ( V_8 == 0 ) {
V_142 = V_156 ;
goto V_148;
}
return V_8 ;
} else {
}
V_148:
if ( ( V_8 = F_11 ( V_40 ) ) < 0 )
return V_8 ;
if ( V_18 && ( V_8 = F_9 ( V_18 , V_142 ) ) != 0 )
return V_8 ;
return V_8 ;
}
