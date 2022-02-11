static int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
unsigned char * V_5 = ( unsigned char * ) V_3 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_8 ,
V_9 | V_10 | V_11 ,
V_5 [ 0 ] , 2 ,
V_3 , V_4 , V_12 ) ;
if ( V_6 < 0 )
F_4 ( & V_2 -> V_13 -> V_14 ,
L_1 ,
V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
unsigned char * V_5 = ( unsigned char * ) V_3 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 ,
F_6 ( V_2 -> V_7 , 0 ) ,
V_15 ,
V_9 | V_10 | V_16 ,
V_5 [ 0 ] , 2 ,
V_3 , V_4 , V_12 ) ;
if ( V_6 < 0 )
F_4 ( & V_2 -> V_13 -> V_14 ,
L_2 ,
V_6 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , int V_17 )
{
unsigned char V_3 [ V_18 ] ;
int V_6 ;
V_3 [ 0 ] = F_8 ( V_17 ) ;
V_6 = F_1 ( V_2 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_6 >= 0 )
V_2 -> V_19 [ V_17 ] = F_9 ( & V_3 [ 1 ] ) ;
return ( V_6 < 0 ) ? - V_20 : 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_17 )
{
unsigned char V_3 [ V_18 ] ;
int V_6 ;
V_3 [ 0 ] = F_8 ( V_17 ) ;
F_11 ( V_2 -> V_19 [ V_17 ] , & V_3 [ 1 ] ) ;
V_6 = F_5 ( V_2 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
return ( V_6 < 0 ) ? - V_20 : 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned char V_3 [ V_21 ] ;
int V_6 ;
unsigned char V_17 ;
V_3 [ 0 ] = V_22 ;
V_6 = F_1 ( V_2 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_6 >= 0 )
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
V_2 -> V_19 [ V_17 ] = F_9 (
& V_3 [ V_17 * V_24 + 1 ] ) ;
return ( V_6 < 0 ) ? - V_20 : 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned char V_25 )
{
unsigned char V_3 [ V_26 ] ;
int V_6 ;
V_3 [ 0 ] = V_27 ;
V_3 [ 1 ] = V_28 ;
V_3 [ 2 ] = V_25 ;
V_6 = F_5 ( V_2 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
return ( V_6 < 0 ) ? - V_20 : 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned char V_3 [ V_29 ] ;
int V_6 ;
V_3 [ 0 ] = V_30 ;
V_6 = F_1 ( V_2 , ( void * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
F_4 ( & V_2 -> V_13 -> V_14 , L_3
L_4 , V_6 ) ;
else {
V_2 -> V_31 = V_3 [ 1 ] ;
V_2 -> V_32 = V_3 [ 2 ] ;
}
return ( V_6 < 0 ) ? - V_20 : 0 ;
}
static void F_15 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
int V_6 ;
unsigned char V_17 ;
unsigned char V_35 ;
unsigned short V_36 ;
unsigned short V_37 ;
unsigned char V_38 [ 3 ] ;
if ( V_33 -> V_39 ) {
if ( V_33 -> V_39 == - V_40 ||
V_33 -> V_39 == - V_41 ||
V_33 -> V_39 == - V_42 ) {
return;
} else {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_5 , V_33 -> V_39 ) ;
goto V_43;
}
}
if ( ( V_2 -> V_19 [ V_44 ] & V_45 ) == 0 )
goto V_43;
if ( V_33 -> V_46 > 0 ) {
for ( V_17 = 0 ; V_17 < V_47 ; V_17 ++ )
V_2 -> V_19 [ V_48 + V_17 ] =
F_9 ( & V_2 -> V_49 [
V_17 * V_24 + 1 ] ) ;
if ( ( V_2 -> V_19 [ V_48 ] & V_50 ) == 0 ) {
goto V_43;
}
if ( ( V_2 -> V_19 [ V_48 ] & V_51 ) == 0 ) {
goto V_43;
}
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
switch ( V_35 ) {
default:
V_36 = ( V_2 -> V_19 [ V_48 ] &
V_52 ) >> 9 ;
V_37 = V_2 -> V_19 [ V_53 ] ;
break;
case 1 :
V_36 = ( V_2 -> V_19 [ V_54 ] &
V_55 ) >> 14 ;
V_37 = V_2 -> V_19 [ V_56 ] ;
break;
case 2 :
V_36 = ( V_2 -> V_19 [ V_54 ] &
V_57 ) >> 12 ;
V_37 = V_2 -> V_19 [ V_58 ] ;
break;
case 3 :
V_36 = ( V_2 -> V_19 [ V_54 ] &
V_59 ) >> 10 ;
V_37 = V_2 -> V_19 [ V_60 ] ;
break;
} ;
F_16 ( V_37 , & V_38 ) ;
V_38 [ 2 ] = V_35 ;
V_38 [ 2 ] |= V_35 << 3 ;
if ( V_36 > V_61 )
V_38 [ 2 ] |= 0x80 ;
else if ( V_36 > 0 )
V_38 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_62 [ V_2 -> V_63 ] , & V_38 , 3 ) ;
V_2 -> V_63 += 3 ;
if ( V_2 -> V_63 >= V_2 -> V_64 )
V_2 -> V_63 = 0 ;
if ( V_2 -> V_63 == V_2 -> V_65 ) {
V_2 -> V_65 += 3 ;
if ( V_2 -> V_65 >= V_2 -> V_64 )
V_2 -> V_65 = 0 ;
}
}
if ( V_2 -> V_63 != V_2 -> V_65 )
F_17 ( & V_2 -> V_66 ) ;
}
V_43:
if ( V_2 -> V_67 && V_2 -> V_7 ) {
V_6 = F_18 ( V_2 -> V_68 , V_69 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_6 , V_6 ) ;
V_2 -> V_67 = 0 ;
}
}
}
int F_19 ( struct V_70 * V_70 )
{
return F_20 ( V_70 ) ;
}
int F_21 ( struct V_70 * V_70 )
{
return F_22 ( V_70 ) ;
}
static void F_23 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_24 ( V_72 , struct V_1 , V_72 ) ;
F_25 ( V_2 -> V_68 ) ;
F_26 ( & V_2 -> V_73 ) ;
F_27 ( & V_2 -> V_72 ) ;
F_28 ( V_2 -> V_49 ) ;
F_28 ( V_2 -> V_62 ) ;
F_28 ( V_2 ) ;
}
int F_29 ( struct V_70 * V_70 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_30 ( V_70 ) ;
F_31 ( V_76 -> V_77 , V_78 , sizeof( V_76 -> V_77 ) ) ;
F_31 ( V_76 -> V_79 , V_80 , sizeof( V_76 -> V_79 ) ) ;
F_32 ( V_2 -> V_7 , V_76 -> V_81 ,
sizeof( V_76 -> V_81 ) ) ;
V_76 -> V_82 = V_83 |
V_84 | V_85 | V_86 ;
V_76 -> V_87 = V_76 -> V_82 | V_88 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_34 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
F_35 ( & V_2 -> V_73 ) ;
F_36 ( V_2 -> V_68 , V_2 -> V_7 ,
F_37 ( V_2 -> V_7 ,
V_2 -> V_89 -> V_90 ) ,
V_2 -> V_49 ,
F_38 ( V_2 -> V_89 -> V_91 ) ,
F_15 ,
V_2 ,
V_2 -> V_89 -> V_92 ) ;
V_2 -> V_67 = 1 ;
F_39 () ;
V_6 = F_18 ( V_2 -> V_68 , V_93 ) ;
if ( V_6 ) {
F_40 ( & V_2 -> V_13 -> V_14 ,
L_7 , V_6 ) ;
V_2 -> V_67 = 0 ;
}
return V_6 ;
}
static int F_41 ( struct V_94 * V_13 ,
const struct V_95 * V_96 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_101 , V_102 , V_6 = 0 ;
unsigned char V_103 = 0 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_93 ) ;
if ( ! V_2 ) {
V_6 = - V_104 ;
goto V_105;
}
V_2 -> V_7 = F_43 ( V_13 ) ;
V_2 -> V_13 = V_13 ;
F_44 ( & V_2 -> V_106 ) ;
V_98 = V_13 -> V_107 ;
for ( V_101 = 0 ; V_101 < V_98 -> V_108 . V_109 ; ++ V_101 ) {
V_100 = & V_98 -> V_100 [ V_101 ] . V_108 ;
if ( ( ( V_100 -> V_90 & V_110 ) ==
V_11 ) && ( ( V_100 -> V_111 &
V_112 ) == V_113 ) )
V_2 -> V_89 = V_100 ;
}
if ( ! V_2 -> V_89 ) {
F_40 ( & V_13 -> V_14 , L_8 ) ;
V_6 = - V_114 ;
goto V_115;
}
V_102 = F_38 ( V_2 -> V_89 -> V_91 ) ;
V_2 -> V_49 = F_45 ( V_102 , V_93 ) ;
if ( ! V_2 -> V_49 ) {
F_40 ( & V_13 -> V_14 , L_9 ) ;
V_6 = - V_104 ;
goto V_115;
}
V_2 -> V_68 = F_46 ( 0 , V_93 ) ;
if ( ! V_2 -> V_68 ) {
F_40 ( & V_13 -> V_14 , L_10 ) ;
V_6 = - V_104 ;
goto V_116;
}
V_2 -> V_72 . V_117 = F_23 ;
V_6 = F_47 ( & V_13 -> V_14 , & V_2 -> V_72 ) ;
if ( V_6 < 0 ) {
F_48 ( & V_13 -> V_14 , L_11 ) ;
goto V_118;
}
F_49 ( & V_2 -> V_73 , 2 ) ;
F_50 ( & V_2 -> V_73 , & V_119 ,
V_120 , 0 , 1 , 1 , 1 ) ;
F_50 ( & V_2 -> V_73 , & V_119 ,
V_121 , 0 , 15 , 1 , 15 ) ;
if ( V_2 -> V_73 . error ) {
V_6 = V_2 -> V_73 . error ;
F_48 ( & V_13 -> V_14 , L_12 ) ;
goto V_122;
}
V_2 -> V_123 = V_124 ;
V_2 -> V_123 . V_125 = & V_2 -> V_73 ;
V_2 -> V_123 . V_106 = & V_2 -> V_106 ;
V_2 -> V_123 . V_72 = & V_2 -> V_72 ;
V_2 -> V_123 . V_117 = V_126 ;
F_51 ( V_127 , & V_2 -> V_123 . V_128 ) ;
F_52 ( & V_2 -> V_123 , V_2 ) ;
if ( F_12 ( V_2 ) < 0 ) {
V_6 = - V_114 ;
goto V_129;
}
F_40 ( & V_13 -> V_14 , L_13 ,
V_2 -> V_19 [ V_130 ] , V_2 -> V_19 [ V_131 ] ) ;
if ( ( V_2 -> V_19 [ V_131 ] & V_132 ) < V_133 ) {
F_4 ( & V_13 -> V_14 ,
L_14
L_15 , V_133 ) ;
F_4 ( & V_13 -> V_14 ,
L_16 ,
V_2 -> V_19 [ V_131 ] & V_132 ) ;
V_103 = 1 ;
}
if ( F_14 ( V_2 ) < 0 ) {
V_6 = - V_114 ;
goto V_129;
}
F_40 ( & V_13 -> V_14 , L_17 ,
V_2 -> V_31 , V_2 -> V_32 ) ;
if ( V_2 -> V_31 < V_134 ) {
F_4 ( & V_13 -> V_14 ,
L_14
L_18 , V_134 ) ;
F_4 ( & V_13 -> V_14 ,
L_19 ,
V_2 -> V_31 ) ;
V_103 = 1 ;
}
if ( V_2 -> V_32 < V_135 ) {
F_4 ( & V_13 -> V_14 ,
L_14
L_20 , V_135 ) ;
F_4 ( & V_13 -> V_14 ,
L_21 ,
V_2 -> V_32 ) ;
V_103 = 1 ;
}
if ( V_103 == 1 ) {
F_4 ( & V_13 -> V_14 ,
L_22 ) ;
F_4 ( & V_13 -> V_14 ,
L_23
L_24 ) ;
}
F_53 ( V_2 , 87.5 * V_136 ) ;
F_13 ( V_2 , V_137 ) ;
V_2 -> V_64 = V_138 * 3 ;
V_2 -> V_62 = F_45 ( V_2 -> V_64 , V_93 ) ;
if ( ! V_2 -> V_62 ) {
V_6 = - V_114 ;
goto V_129;
}
V_2 -> V_63 = 0 ;
V_2 -> V_65 = 0 ;
F_54 ( & V_2 -> V_66 ) ;
F_55 ( V_13 , V_2 ) ;
V_6 = F_33 ( V_2 ) ;
if ( V_6 < 0 )
goto V_139;
V_6 = F_56 ( & V_2 -> V_123 , V_140 ,
V_141 ) ;
if ( V_6 ) {
F_48 ( & V_13 -> V_14 , L_25 ) ;
goto V_139;
}
return 0 ;
V_139:
F_28 ( V_2 -> V_62 ) ;
V_129:
F_26 ( & V_2 -> V_73 ) ;
V_122:
F_27 ( & V_2 -> V_72 ) ;
V_118:
F_25 ( V_2 -> V_68 ) ;
V_116:
F_28 ( V_2 -> V_49 ) ;
V_115:
F_28 ( V_2 ) ;
V_105:
return V_6 ;
}
static int F_57 ( struct V_94 * V_13 ,
T_1 V_142 )
{
struct V_1 * V_2 = F_58 ( V_13 ) ;
F_40 ( & V_13 -> V_14 , L_26 ) ;
if ( V_2 -> V_67 ) {
V_2 -> V_67 = 0 ;
if ( V_2 -> V_68 )
F_59 ( V_2 -> V_68 ) ;
}
F_17 ( & V_2 -> V_66 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_94 * V_13 )
{
struct V_1 * V_2 = F_58 ( V_13 ) ;
F_40 ( & V_13 -> V_14 , L_27 ) ;
return F_33 ( V_2 ) ;
}
static void F_62 ( struct V_94 * V_13 )
{
struct V_1 * V_2 = F_58 ( V_13 ) ;
F_63 ( & V_2 -> V_106 ) ;
F_64 ( & V_2 -> V_72 ) ;
F_65 ( & V_2 -> V_123 ) ;
F_55 ( V_13 , NULL ) ;
F_66 ( & V_2 -> V_106 ) ;
F_67 ( & V_2 -> V_72 ) ;
}
