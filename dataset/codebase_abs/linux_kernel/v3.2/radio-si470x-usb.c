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
int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 )
return - V_34 ;
else
return 0 ;
}
static void F_16 ( struct V_35 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
int V_6 ;
unsigned char V_17 ;
unsigned char V_37 ;
unsigned short V_38 ;
unsigned short V_39 ;
unsigned char V_40 [ 3 ] ;
if ( V_35 -> V_41 ) {
if ( V_35 -> V_41 == - V_42 ||
V_35 -> V_41 == - V_43 ||
V_35 -> V_41 == - V_44 ) {
return;
} else {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_5 , V_35 -> V_41 ) ;
goto V_45;
}
}
if ( V_2 -> V_33 )
return;
if ( ( V_2 -> V_19 [ V_46 ] & V_47 ) == 0 )
goto V_45;
if ( V_35 -> V_48 > 0 ) {
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_2 -> V_19 [ V_50 + V_17 ] =
F_9 ( & V_2 -> V_51 [
V_17 * V_24 + 1 ] ) ;
if ( ( V_2 -> V_19 [ V_50 ] & V_52 ) == 0 ) {
goto V_45;
}
if ( ( V_2 -> V_19 [ V_50 ] & V_53 ) == 0 ) {
goto V_45;
}
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
switch ( V_37 ) {
default:
V_38 = ( V_2 -> V_19 [ V_50 ] &
V_54 ) >> 9 ;
V_39 = V_2 -> V_19 [ V_55 ] ;
break;
case 1 :
V_38 = ( V_2 -> V_19 [ V_56 ] &
V_57 ) >> 14 ;
V_39 = V_2 -> V_19 [ V_58 ] ;
break;
case 2 :
V_38 = ( V_2 -> V_19 [ V_56 ] &
V_59 ) >> 12 ;
V_39 = V_2 -> V_19 [ V_60 ] ;
break;
case 3 :
V_38 = ( V_2 -> V_19 [ V_56 ] &
V_61 ) >> 10 ;
V_39 = V_2 -> V_19 [ V_62 ] ;
break;
} ;
F_17 ( V_39 , & V_40 ) ;
V_40 [ 2 ] = V_37 ;
V_40 [ 2 ] |= V_37 << 3 ;
if ( V_38 > V_63 )
V_40 [ 2 ] |= 0x80 ;
else if ( V_38 > 0 )
V_40 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_64 [ V_2 -> V_65 ] , & V_40 , 3 ) ;
V_2 -> V_65 += 3 ;
if ( V_2 -> V_65 >= V_2 -> V_66 )
V_2 -> V_65 = 0 ;
if ( V_2 -> V_65 == V_2 -> V_67 ) {
V_2 -> V_67 += 3 ;
if ( V_2 -> V_67 >= V_2 -> V_66 )
V_2 -> V_67 = 0 ;
}
}
if ( V_2 -> V_65 != V_2 -> V_67 )
F_18 ( & V_2 -> V_68 ) ;
}
V_45:
if ( V_2 -> V_69 && V_2 -> V_7 ) {
V_6 = F_19 ( V_2 -> V_70 , V_71 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_6 , V_6 ) ;
V_2 -> V_69 = 0 ;
}
}
}
int F_20 ( struct V_72 * V_72 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
int V_6 ;
F_22 ( & V_2 -> V_73 ) ;
V_2 -> V_74 ++ ;
V_6 = F_23 ( V_2 -> V_13 ) ;
if ( V_6 < 0 ) {
V_2 -> V_74 -- ;
V_6 = - V_34 ;
goto V_75;
}
if ( V_2 -> V_74 == 1 ) {
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 ) {
F_25 ( V_2 -> V_13 ) ;
goto V_75;
}
F_26 ( V_2 -> V_70 , V_2 -> V_7 ,
F_27 ( V_2 -> V_7 ,
V_2 -> V_76 -> V_77 ) ,
V_2 -> V_51 ,
F_28 ( V_2 -> V_76 -> V_78 ) ,
F_16 ,
V_2 ,
V_2 -> V_76 -> V_79 ) ;
V_2 -> V_69 = 1 ;
F_29 () ;
V_6 = F_19 ( V_2 -> V_70 , V_80 ) ;
if ( V_6 ) {
F_30 ( & V_2 -> V_13 -> V_14 ,
L_7 , V_6 ) ;
V_2 -> V_69 = 0 ;
F_25 ( V_2 -> V_13 ) ;
}
}
V_75:
F_31 ( & V_2 -> V_73 ) ;
return V_6 ;
}
int F_32 ( struct V_72 * V_72 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
int V_6 = 0 ;
if ( ! V_2 ) {
V_6 = - V_81 ;
goto V_75;
}
F_22 ( & V_2 -> V_73 ) ;
V_2 -> V_74 -- ;
if ( V_2 -> V_74 == 0 ) {
if ( V_2 -> V_69 ) {
V_2 -> V_69 = 0 ;
if ( V_2 -> V_70 )
F_33 ( V_2 -> V_70 ) ;
}
if ( V_2 -> V_33 ) {
F_34 ( V_2 -> V_82 ) ;
F_35 ( V_2 -> V_51 ) ;
F_35 ( V_2 -> V_64 ) ;
F_31 ( & V_2 -> V_73 ) ;
F_35 ( V_2 ) ;
goto V_75;
}
F_18 ( & V_2 -> V_68 ) ;
V_6 = F_36 ( V_2 ) ;
F_25 ( V_2 -> V_13 ) ;
}
F_31 ( & V_2 -> V_73 ) ;
V_75:
return V_6 ;
}
int F_37 ( struct V_72 * V_72 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = F_21 ( V_72 ) ;
F_38 ( V_85 -> V_86 , V_87 , sizeof( V_85 -> V_86 ) ) ;
F_38 ( V_85 -> V_88 , V_89 , sizeof( V_85 -> V_88 ) ) ;
F_39 ( V_2 -> V_7 , V_85 -> V_90 ,
sizeof( V_85 -> V_90 ) ) ;
V_85 -> V_91 = V_92 |
V_93 | V_94 | V_95 ;
return 0 ;
}
static int F_40 ( struct V_96 * V_13 ,
const struct V_97 * V_98 )
{
struct V_1 * V_2 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
int V_103 , V_104 , V_6 = 0 ;
unsigned char V_105 = 0 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_2 ) {
V_6 = - V_106 ;
goto V_107;
}
V_2 -> V_74 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_7 = F_42 ( V_13 ) ;
V_2 -> V_13 = V_13 ;
F_43 ( & V_2 -> V_73 ) ;
V_100 = V_13 -> V_108 ;
for ( V_103 = 0 ; V_103 < V_100 -> V_109 . V_110 ; ++ V_103 ) {
V_102 = & V_100 -> V_102 [ V_103 ] . V_109 ;
if ( ( ( V_102 -> V_77 & V_111 ) ==
V_11 ) && ( ( V_102 -> V_112 &
V_113 ) == V_114 ) )
V_2 -> V_76 = V_102 ;
}
if ( ! V_2 -> V_76 ) {
F_30 ( & V_13 -> V_14 , L_8 ) ;
V_6 = - V_34 ;
goto V_115;
}
V_104 = F_28 ( V_2 -> V_76 -> V_78 ) ;
V_2 -> V_51 = F_44 ( V_104 , V_80 ) ;
if ( ! V_2 -> V_51 ) {
F_30 ( & V_13 -> V_14 , L_9 ) ;
V_6 = - V_106 ;
goto V_115;
}
V_2 -> V_70 = F_45 ( 0 , V_80 ) ;
if ( ! V_2 -> V_70 ) {
F_30 ( & V_13 -> V_14 , L_10 ) ;
V_6 = - V_106 ;
goto V_116;
}
V_2 -> V_82 = F_46 () ;
if ( ! V_2 -> V_82 ) {
V_6 = - V_106 ;
goto V_117;
}
memcpy ( V_2 -> V_82 , & V_118 ,
sizeof( V_118 ) ) ;
F_47 ( V_2 -> V_82 , V_2 ) ;
if ( F_12 ( V_2 ) < 0 ) {
V_6 = - V_34 ;
goto V_119;
}
F_30 ( & V_13 -> V_14 , L_11 ,
V_2 -> V_19 [ V_120 ] , V_2 -> V_19 [ V_121 ] ) ;
if ( ( V_2 -> V_19 [ V_121 ] & V_122 ) < V_123 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_13 , V_123 ) ;
F_4 ( & V_13 -> V_14 ,
L_14 ,
V_2 -> V_19 [ V_121 ] & V_122 ) ;
V_105 = 1 ;
}
if ( F_14 ( V_2 ) < 0 ) {
V_6 = - V_34 ;
goto V_119;
}
F_30 ( & V_13 -> V_14 , L_15 ,
V_2 -> V_31 , V_2 -> V_32 ) ;
if ( V_2 -> V_31 < V_124 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_16 , V_124 ) ;
F_4 ( & V_13 -> V_14 ,
L_17 ,
V_2 -> V_31 ) ;
V_105 = 1 ;
}
if ( V_2 -> V_32 < V_125 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_18 , V_125 ) ;
F_4 ( & V_13 -> V_14 ,
L_19 ,
V_2 -> V_32 ) ;
V_105 = 1 ;
}
if ( V_105 == 1 ) {
F_4 ( & V_13 -> V_14 ,
L_20 ) ;
F_4 ( & V_13 -> V_14 ,
L_21
L_22 ) ;
}
F_48 ( V_2 , 87.5 * V_126 ) ;
F_13 ( V_2 , V_127 ) ;
V_2 -> V_66 = V_128 * 3 ;
V_2 -> V_64 = F_44 ( V_2 -> V_66 , V_80 ) ;
if ( ! V_2 -> V_64 ) {
V_6 = - V_34 ;
goto V_119;
}
V_2 -> V_65 = 0 ;
V_2 -> V_67 = 0 ;
F_49 ( & V_2 -> V_68 ) ;
V_6 = F_50 ( V_2 -> V_82 , V_129 ,
V_130 ) ;
if ( V_6 ) {
F_4 ( & V_13 -> V_14 , L_23 ) ;
goto V_131;
}
F_51 ( V_13 , V_2 ) ;
return 0 ;
V_131:
F_35 ( V_2 -> V_64 ) ;
V_119:
F_52 ( V_2 -> V_82 ) ;
V_117:
F_53 ( V_2 -> V_70 ) ;
V_116:
F_35 ( V_2 -> V_51 ) ;
V_115:
F_35 ( V_2 ) ;
V_107:
return V_6 ;
}
static int F_54 ( struct V_96 * V_13 ,
T_1 V_132 )
{
F_30 ( & V_13 -> V_14 , L_24 ) ;
return 0 ;
}
static int F_55 ( struct V_96 * V_13 )
{
F_30 ( & V_13 -> V_14 , L_25 ) ;
return 0 ;
}
static void F_56 ( struct V_96 * V_13 )
{
struct V_1 * V_2 = F_57 ( V_13 ) ;
F_22 ( & V_2 -> V_73 ) ;
V_2 -> V_33 = 1 ;
F_51 ( V_13 , NULL ) ;
if ( V_2 -> V_74 == 0 ) {
F_13 ( V_2 , V_133 ) ;
F_53 ( V_2 -> V_70 ) ;
F_35 ( V_2 -> V_51 ) ;
F_34 ( V_2 -> V_82 ) ;
F_35 ( V_2 -> V_64 ) ;
F_31 ( & V_2 -> V_73 ) ;
F_35 ( V_2 ) ;
} else {
F_31 ( & V_2 -> V_73 ) ;
}
}
static int T_2 F_58 ( void )
{
F_59 (KERN_INFO DRIVER_DESC L_26 DRIVER_VERSION L_27 ) ;
return F_60 ( & V_134 ) ;
}
static void T_3 F_61 ( void )
{
F_62 ( & V_134 ) ;
}
