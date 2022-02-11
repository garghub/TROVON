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
V_20 |= V_15 -> V_30 [ V_18 ] . V_23 . V_31 ;
if ( V_20 & V_32 ) {
for ( V_18 = 0 ; V_18 < V_15 -> V_23 . V_29 ; V_18 ++ ) {
V_19 = V_15 -> V_30 [ V_18 ] . V_23 . V_33 . V_34 - 0x81 ;
if ( V_19 < 0 || V_19 >= V_22 ) {
F_4 ( V_11 L_6 ) ;
return - V_35 ;
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
static int F_10 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
struct V_38 * V_39 ;
if ( ( V_39 = F_12 ( V_37 , 1 ) ) == NULL ) {
F_5 ( L_7 ) ;
return - V_40 ;
}
return F_13 ( V_2 , V_39 -> V_41 . V_42 ,
V_39 -> V_41 . V_43 ) ;
}
static int F_14 ( struct V_14 * V_15 , T_3 * V_44 , int * V_45 )
{
struct V_46 * V_47 = V_15 -> V_48 ;
int V_18 , V_8 = 0 ;
T_1 * V_49 ;
V_49 = F_15 ( 2 , V_50 ) ;
if ( ! V_49 )
return - V_51 ;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_28 , 0x0 , V_52 , V_49 , 1 ) ) != 0 )
goto V_53;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_28 , 0x0 , V_54 , V_49 + 1 , 1 ) ) != 0 )
goto V_53;
for ( V_18 = 0 ; V_18 < V_15 -> V_23 . V_24 . V_25 . V_55 ; V_18 ++ )
if ( F_16 ( & V_15 -> V_23 . V_24 . V_25 . V_56 [ V_18 ] ) == V_49 [ 1 ] ) {
* V_44 = V_15 -> V_23 . V_24 . V_25 . V_56 [ V_18 ] . V_57 ;
switch( V_49 [ 0 ] ) {
case 0x80 :
* V_45 = V_58 ;
goto V_53;
case 0x88 :
case 0x99 :
case 0xc0 :
case 0xd8 :
* V_45 = V_58 ;
V_47 -> V_59 = 0 ;
goto V_53;
case 0x93 :
case 0x92 :
case 0x83 :
case 0x82 :
V_47 -> V_59 = 0 ;
* V_45 = V_60 ;
goto V_53;
case 0x91 :
case 0x81 :
if ( ++ V_47 -> V_59 > 2 )
* V_45 = V_61 ;
else
* V_45 = V_58 ;
goto V_53;
default:
F_5 ( L_8 , V_49 [ 0 ] ) ;
* V_45 = V_58 ;
goto V_53;
}
}
if ( V_49 [ 1 ] != 0 )
F_5 ( L_9 , V_49 [ 1 ] ) ;
* V_45 = V_58 ;
V_53:
F_17 ( V_49 ) ;
return V_8 ;
}
static int F_18 ( struct V_62 * V_63 , struct V_64 V_65 [] , int V_66 )
{
struct V_14 * V_15 = F_19 ( V_63 ) ;
int V_18 , V_67 ;
int V_8 = 0 ;
if ( ! V_66 )
return - V_35 ;
if ( F_20 ( & V_15 -> V_68 ) < 0 )
return - V_69 ;
for ( V_18 = 0 ; V_18 < V_66 ; V_18 ++ ) {
if ( V_65 [ V_18 ] . V_20 & ( V_70 | V_71 | V_72 ) || V_65 [ V_18 ] . V_73 == 0 ) {
V_8 = - V_74 ;
goto V_75;
}
if ( ! ( V_65 [ V_18 ] . V_20 & V_76 ) ) {
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_77 ,
( V_65 [ V_18 ] . V_78 << 1 ) |
( V_65 [ V_18 ] . V_20 & V_79 ? 0x01 : 0 ) , 0x80 ) ) != 0 )
goto V_75;
}
if ( V_65 [ V_18 ] . V_20 & V_79 ) {
for ( V_67 = 0 ; V_67 < V_65 [ V_18 ] . V_73 ; V_67 ++ ) {
int V_80 = ( V_18 + 1 == V_66 && V_67 + 1 == V_65 [ V_18 ] . V_73 ) ? 0x40 : 0x01 ;
if ( ( V_8 = F_1 ( V_15 -> V_2 , V_77 , 0x0 ,
0x20 | V_80 ,
& V_65 [ V_18 ] . V_81 [ V_67 ] , 1 ) ) != 0 )
goto V_75;
}
} else {
for ( V_67 = 0 ; V_67 < V_65 [ V_18 ] . V_73 ; V_67 ++ ) {
int V_80 = ( V_18 + 1 == V_66 && V_67 + 1 == V_65 [ V_18 ] . V_73 ) ? 0x40 : 0x00 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_77 , V_65 [ V_18 ] . V_81 [ V_67 ] , V_80 ) ) != 0 )
goto V_75;
}
}
}
V_8 = V_66 ;
V_75:
F_21 ( & V_15 -> V_68 ) ;
return V_8 ;
}
static T_3 F_22 ( struct V_62 * V_30 )
{
return V_82 ;
}
static int F_9 ( struct V_14 * V_15 , int type , int V_83 , int V_84 )
{
int V_8 = 0 ;
if ( V_84 >= 0x8000 )
return - V_35 ;
V_84 |= 0x8000 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_85 , V_84 , ( type << 8 ) | ( V_83 * 4 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_6 ( V_15 -> V_2 , V_85 , 0 , ( type << 8 ) | ( V_83 * 4 ) ) ) != 0 )
return V_8 ;
return V_8 ;
}
static int F_23 ( struct V_86 * V_63 )
{
struct V_46 * V_47 = V_63 -> V_87 -> V_48 ;
int V_88 = V_47 -> V_89 [ V_63 -> V_90 ] ;
int V_18 , V_8 = 0 , V_91 = 0 ;
int V_92 = V_63 -> V_23 . V_33 . V_34 ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
if ( V_47 -> V_94 [ V_63 -> V_90 ] [ V_18 ] == 8192 )
V_88 = 0 ;
if ( ( V_8 = F_9 ( V_63 -> V_87 , V_92 , 1 , V_88 ) ) != 0 )
return V_8 ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
if ( ( V_8 = F_9 ( V_63 -> V_87 , V_92 , V_18 + 2 , 0 ) ) != 0 )
return V_8 ;
if ( V_88 ) {
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ ) {
if ( V_47 -> V_94 [ V_63 -> V_90 ] [ V_18 ] == 0 )
continue;
if ( ( V_8 = F_9 ( V_63 -> V_87 , V_92 , V_91 + 2 , V_47 -> V_94 [ V_63 -> V_90 ] [ V_18 ] ) ) != 0 )
return V_8 ;
V_91 ++ ;
}
}
return V_8 ;
}
static int F_24 ( struct V_86 * V_63 , int V_95 )
{
struct V_46 * V_47 = V_63 -> V_87 -> V_48 ;
V_47 -> V_89 [ V_63 -> V_90 ] = V_95 ? 1 : 0 ;
return F_23 ( V_63 ) ;
}
static int F_25 ( struct V_86 * V_63 , int V_5 , T_2 V_84 , int V_95 )
{
struct V_46 * V_47 = V_63 -> V_87 -> V_48 ;
V_47 -> V_94 [ V_63 -> V_90 ] [ V_5 ] = V_95 ? V_84 : 0 ;
return F_23 ( V_63 ) ;
}
static int F_26 ( struct V_1 * V_2 , const struct V_96 * V_97 )
{
T_2 V_4 , V_5 , V_7 ;
T_1 * V_98 , * V_99 ;
int V_18 , V_100 , V_8 = 0 ;
V_99 = F_15 ( 65536 , V_50 ) ;
if ( V_99 == NULL )
return - V_51 ;
V_98 = F_15 ( 4 , V_50 ) ;
if ( ! V_98 ) {
F_17 ( V_99 ) ;
return - V_51 ;
}
if ( ( V_8 = F_1 ( V_2 , V_85 , 0x0 , 0x8000 , V_98 , 4 ) ) != 0 )
goto V_101;
F_5 ( L_10 , V_98 [ 0 ] , V_98 [ 1 ] , V_98 [ 2 ] , V_98 [ 3 ] ) ;
if ( ( V_8 = F_1 ( V_2 , V_102 , 0x0 , 0x0 , V_98 , 1 ) ) != 0 )
goto V_101;
F_5 ( L_11 , V_98 [ 0 ] ) ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ ) {
for ( V_18 = 0 ; V_18 + ( sizeof( T_2 ) * 3 ) < V_97 -> V_7 ; ) {
V_4 = F_27 ( V_97 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
V_5 = F_27 ( V_97 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
V_7 = F_27 ( V_97 -> V_6 + V_18 ) ;
V_18 += sizeof( T_2 ) ;
if ( V_100 == 1 ) {
memcpy ( V_99 , V_97 -> V_6 + V_18 , V_7 ) ;
V_8 = F_2 ( V_2 , F_7 ( V_2 , 0 ) ,
V_102 ,
V_9 | V_13 ,
V_4 , V_5 , V_99 , V_7 , 20 ) ;
if ( V_8 != V_7 ) {
F_5 ( L_12 ) ;
V_8 = - V_12 ;
goto V_101;
}
F_28 ( 3 ) ;
}
V_18 += V_7 ;
}
if ( V_18 != V_97 -> V_7 ) {
F_5 ( L_13 ) ;
V_8 = - V_35 ;
goto V_101;
}
}
F_28 ( 36 ) ;
( void ) F_6 ( V_2 , V_28 , 0x01 , V_103 ) ;
F_5 ( L_14 ) ;
V_101:
F_17 ( V_98 ) ;
F_17 ( V_99 ) ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_104 * V_23 ,
struct V_105 * * V_41 ,
int * V_106 )
{
struct V_38 * V_39 ;
V_39 = F_12 ( F_30 ( V_2 , 0 ) , 1 ) ;
* V_106 = ( V_39 == NULL ) ? 1 : 0 ;
return 0 ;
}
static int F_31 ( struct V_107 * V_108 )
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
if ( ( V_8 = F_32 ( V_108 , V_109 , F_33 ( V_109 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , clock , F_33 ( clock ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_112 , F_33 ( V_112 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_114 , F_33 ( V_114 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_116 , F_33 ( V_116 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_118 , F_33 ( V_118 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_119 , F_33 ( V_119 ) ) ) != 0 )
return V_8 ;
if ( ( V_8 = F_32 ( V_108 , V_120 , F_33 ( V_120 ) ) ) != 0 )
return V_8 ;
return 0 ;
}
static int F_34 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( ( V_63 -> V_108 = F_35 ( V_122 ,
& V_123 ,
& V_63 -> V_87 -> V_124 ) ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_36 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( ( V_63 -> V_108 = F_35 ( V_125 ,
& V_126 ,
& V_63 -> V_87 -> V_124 ) ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_37 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( ( V_63 -> V_108 = F_35 ( V_125 ,
& V_127 ,
& V_63 -> V_87 -> V_124 ) ) == NULL )
return - V_12 ;
return 0 ;
}
static int F_38 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_128 , V_63 -> V_108 , & V_63 -> V_87 -> V_124 , & V_129 ) == NULL )
return - V_40 ;
return 0 ;
}
static int F_39 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_130 , V_63 -> V_108 , 0x60 , & V_63 -> V_87 -> V_124 , NULL ) == NULL )
return - V_40 ;
return 0 ;
}
static int F_40 ( struct V_86 * V_63 )
{
F_5 ( L_16 , V_121 ) ;
if ( F_35 ( V_130 , V_63 -> V_108 , 0x61 , & V_63 -> V_87 -> V_124 , NULL ) == NULL )
return - V_40 ;
return 0 ;
}
static int F_41 ( struct V_86 * V_63 )
{
F_35 ( V_131 , V_63 -> V_108 ,
& V_63 -> V_87 -> V_124 , 0x61 ,
V_132 ) ;
return 0 ;
}
static int F_42 ( struct V_36 * V_37 ,
const struct V_133 * V_90 )
{
struct V_14 * V_15 = NULL ;
int V_8 ;
struct V_16 * V_134 = NULL ;
int V_42 = V_37 -> V_135 -> V_41 . V_42 ;
F_5 ( L_17 , V_42 ) ;
if ( V_42 == 0 ) {
V_8 = F_43 ( V_37 , & V_136 ,
V_137 , & V_15 , V_138 ) ;
if ( V_8 == 0 ) {
V_134 = V_139 ;
goto V_140;
}
V_8 = F_43 ( V_37 , & V_141 ,
V_137 , & V_15 , V_138 ) ;
if ( V_8 == 0 ) {
goto V_140;
}
V_8 = F_43 ( V_37 , & V_142 ,
V_137 , & V_15 , V_138 ) ;
if ( V_8 == 0 ) {
V_134 = V_143 ;
goto V_140;
}
V_8 = F_43 ( V_37 , & V_144 ,
V_137 , & V_15 , V_138 ) ;
if ( V_8 == 0 ) {
goto V_140;
}
V_8 = F_43 ( V_37 , & V_145 ,
V_137 , & V_15 , V_138 ) ;
if ( V_8 == 0 ) {
V_134 = V_146 ;
goto V_140;
}
return V_8 ;
} else {
}
V_140:
if ( ( V_8 = F_10 ( V_37 ) ) < 0 )
return V_8 ;
if ( V_15 && ( V_8 = F_8 ( V_15 , V_134 ) ) != 0 )
return V_8 ;
return V_8 ;
}
static int T_4 F_44 ( void )
{
int V_8 ;
if ( ( V_8 = F_45 ( & V_147 ) ) ) {
F_46 ( L_18 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_147 ) ;
}
