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
static int F_8 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
int V_8 = 0 , V_18 , V_19 , V_20 = 0 ;
int V_21 [ V_22 ] = { 0 } ;
if ( V_15 -> V_23 . V_24 . V_25 . V_26 ) {
F_5 ( L_3 ) ;
while ( V_17 -> V_27 ) {
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_28 ,
V_17 -> V_6 ,
V_17 -> V_27 ) ) != 0 ) {
F_5 ( L_4 ) ;
return V_8 ;
}
V_17 ++ ;
}
F_5 ( L_5 ) ;
}
for ( V_18 = 0 ; V_18 < V_15 -> V_23 . V_29 ; V_18 ++ )
V_20 |= V_15 -> V_30 [ V_18 ] . V_23 . V_31 [ 0 ] . V_32 ;
if ( V_20 & V_33 ) {
for ( V_18 = 0 ; V_18 < V_15 -> V_23 . V_29 ; V_18 ++ ) {
V_19 = V_15 -> V_30 [ V_18 ] . V_23 . V_31 [ 0 ] . V_34 . V_35 - 0x81 ;
if ( V_19 < 0 || V_19 >= V_22 ) {
F_4 ( V_11 L_6 ) ;
return - V_36 ;
}
V_21 [ V_19 ] = 1 ;
}
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
if ( V_21 [ V_18 ] )
continue;
if ( ( V_8 = F_9 ( V_15 , 0x81 + V_18 , 0 , 0x0 ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_9 ( V_15 , 0x81 + V_18 , 0 , 0x02f5 ) ) != 0 )
return V_8 ;
}
}
return V_8 ;
}
static int F_10 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_11 ( V_38 ) ;
struct V_39 * V_40 ;
if ( ( V_40 = F_12 ( V_38 , 1 ) ) == NULL ) {
F_5 ( L_7 ) ;
return - V_41 ;
}
return F_13 ( V_2 , V_40 -> V_42 . V_43 ,
V_40 -> V_42 . V_44 ) ;
}
static int F_14 ( struct V_14 * V_15 , T_3 * V_45 , int * V_46 )
{
struct V_47 * V_48 = V_15 -> V_49 ;
int V_18 , V_8 = 0 ;
T_1 * V_50 ;
V_50 = F_15 ( 2 , V_51 ) ;
if ( ! V_50 )
return - V_52 ;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_28 , 0x0 , V_53 , V_50 , 1 ) ) != 0 )
goto V_54;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_28 , 0x0 , V_55 , V_50 + 1 , 1 ) ) != 0 )
goto V_54;
for ( V_18 = 0 ; V_18 < V_15 -> V_23 . V_24 . V_25 . V_56 ; V_18 ++ )
if ( F_16 ( & V_15 -> V_23 . V_24 . V_25 . V_57 [ V_18 ] ) == V_50 [ 1 ] ) {
* V_45 = V_15 -> V_23 . V_24 . V_25 . V_57 [ V_18 ] . V_58 ;
switch( V_50 [ 0 ] ) {
case 0x80 :
* V_46 = V_59 ;
goto V_54;
case 0x88 :
case 0x99 :
case 0xc0 :
case 0xd8 :
* V_46 = V_59 ;
V_48 -> V_60 = 0 ;
goto V_54;
case 0x93 :
case 0x92 :
case 0x83 :
case 0x82 :
V_48 -> V_60 = 0 ;
* V_46 = V_61 ;
goto V_54;
case 0x91 :
case 0x81 :
if ( ++ V_48 -> V_60 > 2 )
* V_46 = V_62 ;
else
* V_46 = V_59 ;
goto V_54;
default:
F_5 ( L_8 , V_50 [ 0 ] ) ;
* V_46 = V_59 ;
goto V_54;
}
}
if ( V_50 [ 1 ] != 0 )
F_5 ( L_9 , V_50 [ 1 ] ) ;
* V_46 = V_59 ;
V_54:
F_17 ( V_50 ) ;
return V_8 ;
}
static int F_18 ( struct V_63 * V_64 , struct V_65 V_66 [] , int V_67 )
{
struct V_14 * V_15 = F_19 ( V_64 ) ;
int V_18 , V_68 ;
int V_8 = 0 ;
if ( ! V_67 )
return - V_36 ;
if ( F_20 ( & V_15 -> V_69 ) < 0 )
return - V_70 ;
for ( V_18 = 0 ; V_18 < V_67 ; V_18 ++ ) {
if ( V_66 [ V_18 ] . V_20 & ( V_71 | V_72 | V_73 ) || V_66 [ V_18 ] . V_74 == 0 ) {
V_8 = - V_75 ;
goto V_76;
}
if ( ! ( V_66 [ V_18 ] . V_20 & V_77 ) ) {
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_78 ,
( V_66 [ V_18 ] . V_79 << 1 ) |
( V_66 [ V_18 ] . V_20 & V_80 ? 0x01 : 0 ) , 0x80 ) ) != 0 )
goto V_76;
}
if ( V_66 [ V_18 ] . V_20 & V_80 ) {
for ( V_68 = 0 ; V_68 < V_66 [ V_18 ] . V_74 ; V_68 ++ ) {
int V_81 = ( V_18 + 1 == V_67 && V_68 + 1 == V_66 [ V_18 ] . V_74 ) ? 0x40 : 0x01 ;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_78 , 0x0 ,
0x20 | V_81 ,
& V_66 [ V_18 ] . V_82 [ V_68 ] , 1 ) ) != 0 )
goto V_76;
}
} else {
for ( V_68 = 0 ; V_68 < V_66 [ V_18 ] . V_74 ; V_68 ++ ) {
int V_81 = ( V_18 + 1 == V_67 && V_68 + 1 == V_66 [ V_18 ] . V_74 ) ? 0x40 : 0x00 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_78 , V_66 [ V_18 ] . V_82 [ V_68 ] , V_81 ) ) != 0 )
goto V_76;
}
}
}
V_8 = V_67 ;
V_76:
F_21 ( & V_15 -> V_69 ) ;
return V_8 ;
}
static T_3 F_22 ( struct V_63 * V_30 )
{
return V_83 ;
}
static int F_9 ( struct V_14 * V_15 , int type , int V_84 , int V_85 )
{
int V_8 = 0 ;
if ( V_85 >= 0x8000 )
return - V_36 ;
V_85 |= 0x8000 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_86 , V_85 , ( type << 8 ) | ( V_84 * 4 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_86 , 0 , ( type << 8 ) | ( V_84 * 4 ) ) ) != 0 )
return V_8 ;
return V_8 ;
}
static int F_23 ( struct V_87 * V_64 )
{
struct V_47 * V_48 = V_64 -> V_88 -> V_49 ;
int V_89 = V_48 -> V_90 [ V_64 -> V_91 ] ;
int V_18 , V_8 = 0 , V_92 = 0 ;
int V_93 = V_64 -> V_23 . V_31 [ 0 ] . V_34 . V_35 ;
for ( V_18 = 0 ; V_18 < V_94 ; V_18 ++ )
if ( V_48 -> V_95 [ V_64 -> V_91 ] [ V_18 ] == 8192 )
V_89 = 0 ;
if ( ( V_8 = F_9 ( V_64 -> V_88 , V_93 , 1 , V_89 ) ) != 0 )
return V_8 ;
for ( V_18 = 0 ; V_18 < V_94 ; V_18 ++ )
if ( ( V_8 = F_9 ( V_64 -> V_88 , V_93 , V_18 + 2 , 0 ) ) != 0 )
return V_8 ;
if ( V_89 ) {
for ( V_18 = 0 ; V_18 < V_94 ; V_18 ++ ) {
if ( V_48 -> V_95 [ V_64 -> V_91 ] [ V_18 ] == 0 )
continue;
if ( ( V_8 = F_9 ( V_64 -> V_88 , V_93 , V_92 + 2 , V_48 -> V_95 [ V_64 -> V_91 ] [ V_18 ] ) ) != 0 )
return V_8 ;
V_92 ++ ;
}
}
return V_8 ;
}
static int F_24 ( struct V_87 * V_64 , int V_96 )
{
struct V_47 * V_48 = V_64 -> V_88 -> V_49 ;
V_48 -> V_90 [ V_64 -> V_91 ] = V_96 ? 1 : 0 ;
return F_23 ( V_64 ) ;
}
static int F_25 ( struct V_87 * V_64 , int V_5 , T_2 V_85 , int V_96 )
{
struct V_47 * V_48 = V_64 -> V_88 -> V_49 ;
V_48 -> V_95 [ V_64 -> V_91 ] [ V_5 ] = V_96 ? V_85 : 0 ;
return F_23 ( V_64 ) ;
}
static int F_26 ( struct V_1 * V_2 , const struct V_97 * V_98 )
{
T_2 V_4 , V_5 , V_7 ;
T_1 * V_99 , * V_100 ;
int V_18 , V_101 , V_8 = 0 ;
V_100 = F_15 ( 65536 , V_51 ) ;
if ( V_100 == NULL )
return - V_52 ;
V_99 = F_15 ( 4 , V_51 ) ;
if ( ! V_99 ) {
F_17 ( V_100 ) ;
return - V_52 ;
}
if ( ( V_8 = F_1 ( V_2 , V_86 , 0x0 , 0x8000 , V_99 , 4 ) ) != 0 )
goto V_102;
F_5 ( L_10 , 4 , V_99 ) ;
if ( ( V_8 = F_1 ( V_2 , V_103 , 0x0 , 0x0 , V_99 , 1 ) ) != 0 )
goto V_102;
F_5 ( L_11 , V_99 [ 0 ] ) ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
for ( V_18 = 0 ; V_18 + ( sizeof( T_2 ) * 3 ) < V_98 -> V_7 ; ) {
V_4 = F_27 ( V_98 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
V_5 = F_27 ( V_98 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
V_7 = F_27 ( V_98 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
if ( V_101 == 1 ) {
memcpy ( V_100 , V_98 -> V_6 + V_18 , V_7 ) ;
V_8 = F_2 ( V_2 , F_7 ( V_2 , 0 ) ,
V_103 ,
V_9 | V_13 ,
V_4 , V_5 , V_100 , V_7 , 20 ) ;
if ( V_8 != V_7 ) {
F_5 ( L_12 ) ;
V_8 = - V_12 ;
goto V_102;
}
F_28 ( 3 ) ;
}
V_18 += V_7 ;
}
if ( V_18 != V_98 -> V_7 ) {
F_5 ( L_13 ) ;
V_8 = - V_36 ;
goto V_102;
}
}
F_28 ( 36 ) ;
( void ) F_6 ( V_2 , V_28 , 0x01 , V_104 ) ;
F_5 ( L_14 ) ;
V_102:
F_17 ( V_99 ) ;
F_17 ( V_100 ) ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_105 * V_23 ,
struct V_106 * * V_42 ,
int * V_107 )
{
struct V_39 * V_40 ;
V_40 = F_12 ( F_30 ( V_2 , 0 ) , 1 ) ;
* V_107 = ( V_40 == NULL ) ? 1 : 0 ;
return 0 ;
}
static int F_31 ( struct V_108 * V_31 )
{
int V_8 ;
T_1 V_109 [] = { V_110 , 0x3d } ;
T_1 clock [] = { V_111 , 0x30 } ;
T_1 V_112 [] = { V_113 , 0x80 } ;
T_1 V_114 [] = { V_115 , 0x40 } ;
T_1 V_116 [] = { V_117 , 0x1c , 0x20 } ;
T_1 V_118 [] = { 0x69 , 0x00 , 0xff , 0xff , 0x40 , 0xff , 0x00 , 0x40 , 0x40 } ;
T_1 V_119 [] = { 0x93 , 0x1a } ;
T_1 V_120 [] = { 0xb5 , 0x7a } ;
F_5 ( L_15 ) ;
if ( ( V_8 = F_32 ( V_31 , V_109 , F_33 ( V_109 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , clock , F_33 ( clock ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_112 , F_33 ( V_112 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_114 , F_33 ( V_114 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_116 , F_33 ( V_116 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_118 , F_33 ( V_118 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_119 , F_33 ( V_119 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_31 , V_120 , F_33 ( V_120 ) ) ) != 0 )
return V_8 ;
return 0 ;
}
static int F_34 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
V_64 -> V_122 [ 0 ] . V_31 = F_35 ( V_123 ,
& V_124 ,
& V_64 -> V_88 -> V_125 ) ;
if ( ( V_64 -> V_122 [ 0 ] . V_31 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_36 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
V_64 -> V_122 [ 0 ] . V_31 = F_35 ( V_126 ,
& V_127 ,
& V_64 -> V_88 -> V_125 ) ;
if ( ( V_64 -> V_122 [ 0 ] . V_31 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_37 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
V_64 -> V_122 [ 0 ] . V_31 = F_35 ( V_126 ,
& V_128 ,
& V_64 -> V_88 -> V_125 ) ;
if ( ( V_64 -> V_122 [ 0 ] . V_31 ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_38 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_129 , V_64 -> V_122 [ 0 ] . V_31 , & V_64 -> V_88 -> V_125 , & V_130 ) == NULL )
return - V_41 ;
return 0 ;
}
static int F_39 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_131 , V_64 -> V_122 [ 0 ] . V_31 , 0x60 , & V_64 -> V_88 -> V_125 , NULL ) == NULL )
return - V_41 ;
return 0 ;
}
static int F_40 ( struct V_87 * V_64 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_131 , V_64 -> V_122 [ 0 ] . V_31 , 0x61 , & V_64 -> V_88 -> V_125 , NULL ) == NULL )
return - V_41 ;
return 0 ;
}
static int F_41 ( struct V_87 * V_64 )
{
F_35 ( V_132 , V_64 -> V_122 [ 0 ] . V_31 ,
& V_64 -> V_88 -> V_125 , 0x61 ,
V_133 ) ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
const struct V_134 * V_91 )
{
struct V_14 * V_15 = NULL ;
int V_8 ;
struct V_16 * V_135 = NULL ;
int V_43 = V_38 -> V_136 -> V_42 . V_43 ;
F_5 ( L_17 , V_43 ) ;
if ( V_43 == 0 ) {
V_8 = F_43 ( V_38 , & V_137 ,
V_138 , & V_15 , V_139 ) ;
if ( V_8 == 0 ) {
V_135 = V_140 ;
goto V_141;
}
V_8 = F_43 ( V_38 , & V_142 ,
V_138 , & V_15 , V_139 ) ;
if ( V_8 == 0 ) {
goto V_141;
}
V_8 = F_43 ( V_38 , & V_143 ,
V_138 , & V_15 , V_139 ) ;
if ( V_8 == 0 ) {
V_135 = V_144 ;
goto V_141;
}
V_8 = F_43 ( V_38 , & V_145 ,
V_138 , & V_15 , V_139 ) ;
if ( V_8 == 0 ) {
goto V_141;
}
V_8 = F_43 ( V_38 , & V_146 ,
V_138 , & V_15 , V_139 ) ;
if ( V_8 == 0 ) {
V_135 = V_147 ;
goto V_141;
}
return V_8 ;
} else {
}
V_141:
if ( ( V_8 = F_10 ( V_38 ) ) < 0 )
return V_8 ;
if ( V_15 && ( V_8 = F_8 ( V_15 , V_135 ) ) != 0 )
return V_8 ;
return V_8 ;
}
