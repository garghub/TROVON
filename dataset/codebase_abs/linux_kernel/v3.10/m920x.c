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
int V_8 ;
V_8 = F_2 ( V_2 , F_7 ( V_2 , 0 ) ,
V_3 , V_9 | V_13 ,
V_4 , V_5 , NULL , 0 , 2000 ) ;
return V_8 ;
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
F_23 ( V_18 -> V_65 , V_47 [ 1 ] , 0 ) ;
V_60:
F_19 ( V_47 ) ;
return V_8 ;
}
static int F_24 ( struct V_66 * V_67 , struct V_68 V_69 [] , int V_70 )
{
struct V_17 * V_18 = F_25 ( V_67 ) ;
int V_20 , V_71 ;
int V_8 = 0 ;
if ( ! V_70 )
return - V_38 ;
if ( F_26 ( & V_18 -> V_72 ) < 0 )
return - V_73 ;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ ) {
if ( V_69 [ V_20 ] . V_22 & ( V_74 | V_75 | V_76 ) || V_69 [ V_20 ] . V_77 == 0 ) {
V_8 = - V_78 ;
goto V_79;
}
if ( ! ( V_69 [ V_20 ] . V_22 & V_80 ) ) {
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_81 ,
( V_69 [ V_20 ] . V_82 << 1 ) |
( V_69 [ V_20 ] . V_22 & V_83 ? 0x01 : 0 ) , 0x80 ) ) != 0 )
goto V_79;
}
if ( V_69 [ V_20 ] . V_22 & V_83 ) {
for ( V_71 = 0 ; V_71 < V_69 [ V_20 ] . V_77 ; V_71 ++ ) {
int V_84 = ( V_20 + 1 == V_70 && V_71 + 1 == V_69 [ V_20 ] . V_77 ) ? 0x40 : 0x01 ;
if ( ( V_8 = F_1 ( V_18 -> V_2 , V_81 , 0x0 ,
0x20 | V_84 ,
& V_69 [ V_20 ] . V_85 [ V_71 ] , 1 ) ) != 0 )
goto V_79;
}
} else {
for ( V_71 = 0 ; V_71 < V_69 [ V_20 ] . V_77 ; V_71 ++ ) {
int V_84 = ( V_20 + 1 == V_70 && V_71 + 1 == V_69 [ V_20 ] . V_77 ) ? 0x40 : 0x00 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_81 , V_69 [ V_20 ] . V_85 [ V_71 ] , V_84 ) ) != 0 )
goto V_79;
}
}
}
V_8 = V_70 ;
V_79:
F_27 ( & V_18 -> V_72 ) ;
return V_8 ;
}
static T_3 F_28 ( struct V_66 * V_32 )
{
return V_86 ;
}
static int F_10 ( struct V_17 * V_18 , int type , int V_87 , int V_88 )
{
int V_8 = 0 ;
if ( V_88 >= 0x8000 )
return - V_38 ;
V_88 |= 0x8000 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_89 , V_88 , ( type << 8 ) | ( V_87 * 4 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_6 ( V_18 -> V_2 , V_89 , 0 , ( type << 8 ) | ( V_87 * 4 ) ) ) != 0 )
return V_8 ;
return V_8 ;
}
static int F_29 ( struct V_90 * V_67 )
{
struct V_49 * V_50 = V_67 -> V_91 -> V_51 ;
int V_92 = V_50 -> V_93 [ V_67 -> V_94 ] ;
int V_20 , V_8 = 0 , V_95 = 0 ;
int V_96 = V_67 -> V_25 . V_33 [ 0 ] . V_36 . V_37 ;
for ( V_20 = 0 ; V_20 < V_97 ; V_20 ++ )
if ( V_50 -> V_98 [ V_67 -> V_94 ] [ V_20 ] == 8192 )
V_92 = 0 ;
if ( ( V_8 = F_10 ( V_67 -> V_91 , V_96 , 1 , V_92 ) ) != 0 )
return V_8 ;
for ( V_20 = 0 ; V_20 < V_97 ; V_20 ++ )
if ( ( V_8 = F_10 ( V_67 -> V_91 , V_96 , V_20 + 2 , 0 ) ) != 0 )
return V_8 ;
if ( V_92 ) {
for ( V_20 = 0 ; V_20 < V_97 ; V_20 ++ ) {
if ( V_50 -> V_98 [ V_67 -> V_94 ] [ V_20 ] == 0 )
continue;
if ( ( V_8 = F_10 ( V_67 -> V_91 , V_96 , V_95 + 2 , V_50 -> V_98 [ V_67 -> V_94 ] [ V_20 ] ) ) != 0 )
return V_8 ;
V_95 ++ ;
}
}
return V_8 ;
}
static int F_30 ( struct V_90 * V_67 , int V_99 )
{
struct V_49 * V_50 = V_67 -> V_91 -> V_51 ;
V_50 -> V_93 [ V_67 -> V_94 ] = V_99 ? 1 : 0 ;
return F_29 ( V_67 ) ;
}
static int F_31 ( struct V_90 * V_67 , int V_5 , T_2 V_88 , int V_99 )
{
struct V_49 * V_50 = V_67 -> V_91 -> V_51 ;
V_50 -> V_98 [ V_67 -> V_94 ] [ V_5 ] = V_99 ? V_88 : 0 ;
return F_29 ( V_67 ) ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_100 * V_101 )
{
T_2 V_4 , V_5 , V_7 ;
T_1 * V_102 , * V_103 ;
int V_20 , V_104 , V_8 = 0 ;
V_103 = F_17 ( 65536 , V_57 ) ;
if ( V_103 == NULL )
return - V_58 ;
V_102 = F_17 ( 4 , V_57 ) ;
if ( ! V_102 ) {
F_19 ( V_103 ) ;
return - V_58 ;
}
if ( ( V_8 = F_1 ( V_2 , V_89 , 0x0 , 0x8000 , V_102 , 4 ) ) != 0 )
goto V_105;
F_5 ( L_11 , 4 , V_102 ) ;
if ( ( V_8 = F_1 ( V_2 , V_106 , 0x0 , 0x0 , V_102 , 1 ) ) != 0 )
goto V_105;
F_5 ( L_12 , V_102 [ 0 ] ) ;
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
for ( V_20 = 0 ; V_20 + ( sizeof( T_2 ) * 3 ) < V_101 -> V_7 ; ) {
V_4 = F_33 ( V_101 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
V_5 = F_33 ( V_101 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
V_7 = F_33 ( V_101 -> V_6 + V_20 ) ;
V_20 += sizeof( T_2 ) ;
if ( V_104 == 1 ) {
memcpy ( V_103 , V_101 -> V_6 + V_20 , V_7 ) ;
V_8 = F_2 ( V_2 , F_7 ( V_2 , 0 ) ,
V_106 ,
V_9 | V_13 ,
V_4 , V_5 , V_103 , V_7 , 20 ) ;
if ( V_8 != V_7 ) {
F_5 ( L_13 ) ;
V_8 = - V_12 ;
goto V_105;
}
F_34 ( 3 ) ;
}
V_20 += V_7 ;
}
if ( V_20 != V_101 -> V_7 ) {
F_5 ( L_14 ) ;
V_8 = - V_38 ;
goto V_105;
}
}
F_34 ( 36 ) ;
( void ) F_6 ( V_2 , V_30 , 0x01 , V_107 ) ;
F_5 ( L_15 ) ;
V_105:
F_19 ( V_102 ) ;
F_19 ( V_103 ) ;
return V_8 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_108 * V_25 ,
struct V_109 * * V_44 ,
int * V_110 )
{
struct V_41 * V_42 ;
V_42 = F_13 ( F_36 ( V_2 , 0 ) , 1 ) ;
* V_110 = ( V_42 == NULL ) ? 1 : 0 ;
return 0 ;
}
static int F_37 ( struct V_111 * V_33 )
{
int V_8 ;
T_1 V_112 [] = { V_113 , 0x3d } ;
T_1 clock [] = { V_114 , 0x30 } ;
T_1 V_115 [] = { V_116 , 0x80 } ;
T_1 V_117 [] = { V_118 , 0x40 } ;
T_1 V_119 [] = { V_120 , 0x1c , 0x20 } ;
T_1 V_121 [] = { 0x69 , 0x00 , 0xff , 0xff , 0x40 , 0xff , 0x00 , 0x40 , 0x40 } ;
T_1 V_122 [] = { 0x93 , 0x1a } ;
T_1 V_123 [] = { 0xb5 , 0x7a } ;
F_5 ( L_16 ) ;
if ( ( V_8 = F_38 ( V_33 , V_112 , F_39 ( V_112 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , clock , F_39 ( clock ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_115 , F_39 ( V_115 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_117 , F_39 ( V_117 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_119 , F_39 ( V_119 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_121 , F_39 ( V_121 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_122 , F_39 ( V_122 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_38 ( V_33 , V_123 , F_39 ( V_123 ) ) ) != 0 )
return V_8 ;
return 0 ;
}
static int F_40 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
V_67 -> V_125 [ 0 ] . V_33 = F_41 ( V_126 ,
& V_127 ,
& V_67 -> V_91 -> V_128 ) ;
if ( ( V_67 -> V_125 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_42 ( struct V_90 * V_67 )
{
struct V_14 V_129 [] = {
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
F_5 ( L_17 , V_124 ) ;
V_8 = F_8 ( V_67 -> V_91 -> V_2 , V_30 , V_129 ) ;
if ( V_8 != 0 ) {
F_5 ( L_18 ) ;
return V_8 ;
}
return F_40 ( V_67 ) ;
}
static int F_43 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
V_67 -> V_125 [ 0 ] . V_33 = F_41 ( V_130 ,
& V_131 ,
& V_67 -> V_91 -> V_128 ) ;
if ( ( V_67 -> V_125 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_44 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
V_67 -> V_125 [ 0 ] . V_33 = F_41 ( V_130 ,
& V_132 ,
& V_67 -> V_91 -> V_128 ) ;
if ( ( V_67 -> V_125 [ 0 ] . V_33 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_45 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
if ( F_41 ( V_133 , V_67 -> V_125 [ 0 ] . V_33 , & V_67 -> V_91 -> V_128 , & V_134 ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_46 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
if ( F_41 ( V_135 , V_67 -> V_125 [ 0 ] . V_33 , 0x60 , & V_67 -> V_91 -> V_128 , NULL ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_47 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
if ( F_41 ( V_135 , V_67 -> V_125 [ 0 ] . V_33 , 0x61 , & V_67 -> V_91 -> V_128 , NULL ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_48 ( struct V_90 * V_67 )
{
F_41 ( V_136 , V_67 -> V_125 [ 0 ] . V_33 ,
& V_67 -> V_91 -> V_128 , 0x61 ,
V_137 ) ;
return 0 ;
}
static int F_49 ( struct V_90 * V_67 )
{
F_5 ( L_17 , V_124 ) ;
if ( F_41 ( V_138 , V_67 -> V_125 [ 0 ] . V_33 , & V_67 -> V_91 -> V_128 ,
& V_139 , 1220 ) == NULL )
return - V_43 ;
return 0 ;
}
static int F_50 ( struct V_39 * V_40 ,
const struct V_140 * V_94 )
{
struct V_17 * V_18 = NULL ;
int V_8 ;
struct V_14 * V_141 = NULL ;
int V_45 = V_40 -> V_142 -> V_44 . V_45 ;
F_5 ( L_19 , V_45 ) ;
if ( V_45 == 0 ) {
V_8 = F_51 ( V_40 , & V_143 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
V_141 = V_146 ;
goto V_147;
}
V_8 = F_51 ( V_40 , & V_148 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
goto V_147;
}
V_8 = F_51 ( V_40 , & V_149 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
V_141 = V_150 ;
goto V_147;
}
V_8 = F_51 ( V_40 , & V_151 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
goto V_147;
}
V_8 = F_51 ( V_40 , & V_152 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
V_141 = V_153 ;
goto V_147;
}
V_8 = F_51 ( V_40 , & V_154 ,
V_144 , & V_18 , V_145 ) ;
if ( V_8 == 0 ) {
V_141 = V_155 ;
goto V_147;
}
return V_8 ;
} else {
}
V_147:
if ( ( V_8 = F_11 ( V_40 ) ) < 0 )
return V_8 ;
if ( V_18 && ( V_8 = F_9 ( V_18 , V_141 ) ) != 0 )
return V_8 ;
return V_8 ;
}
