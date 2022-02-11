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
unsigned char V_3 [ V_37 ] ;
int V_6 ;
unsigned char V_17 ;
unsigned char V_38 ;
unsigned short V_39 ;
unsigned short V_40 ;
unsigned char V_41 [ 3 ] ;
if ( V_35 -> V_42 ) {
if ( V_35 -> V_42 == - V_43 ||
V_35 -> V_42 == - V_44 ||
V_35 -> V_42 == - V_45 ) {
return;
} else {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_5 , V_35 -> V_42 ) ;
goto V_46;
}
}
if ( V_2 -> V_33 )
return;
if ( ( V_2 -> V_19 [ V_47 ] & V_48 ) == 0 )
goto V_46;
if ( V_35 -> V_49 > 0 ) {
V_3 [ 0 ] = V_50 ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ )
V_2 -> V_19 [ V_52 + V_17 ] =
F_9 ( & V_2 -> V_53 [
V_17 * V_24 + 1 ] ) ;
if ( ( V_2 -> V_19 [ V_52 ] & V_54 ) == 0 ) {
goto V_46;
}
if ( ( V_2 -> V_19 [ V_52 ] & V_55 ) == 0 ) {
goto V_46;
}
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
switch ( V_38 ) {
default:
V_39 = ( V_2 -> V_19 [ V_52 ] &
V_56 ) >> 9 ;
V_40 = V_2 -> V_19 [ V_57 ] ;
break;
case 1 :
V_39 = ( V_2 -> V_19 [ V_58 ] &
V_59 ) >> 14 ;
V_40 = V_2 -> V_19 [ V_60 ] ;
break;
case 2 :
V_39 = ( V_2 -> V_19 [ V_58 ] &
V_61 ) >> 12 ;
V_40 = V_2 -> V_19 [ V_62 ] ;
break;
case 3 :
V_39 = ( V_2 -> V_19 [ V_58 ] &
V_63 ) >> 10 ;
V_40 = V_2 -> V_19 [ V_64 ] ;
break;
} ;
F_17 ( V_40 , & V_41 ) ;
V_41 [ 2 ] = V_38 ;
V_41 [ 2 ] |= V_38 << 3 ;
if ( V_39 > V_65 )
V_41 [ 2 ] |= 0x80 ;
else if ( V_39 > 0 )
V_41 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_66 [ V_2 -> V_67 ] , & V_41 , 3 ) ;
V_2 -> V_67 += 3 ;
if ( V_2 -> V_67 >= V_2 -> V_68 )
V_2 -> V_67 = 0 ;
if ( V_2 -> V_67 == V_2 -> V_69 ) {
V_2 -> V_69 += 3 ;
if ( V_2 -> V_69 >= V_2 -> V_68 )
V_2 -> V_69 = 0 ;
}
}
if ( V_2 -> V_67 != V_2 -> V_69 )
F_18 ( & V_2 -> V_70 ) ;
}
V_46:
if ( V_2 -> V_71 && V_2 -> V_7 ) {
V_6 = F_19 ( V_2 -> V_72 , V_73 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_13 -> V_14 ,
L_6 , V_6 ) ;
V_2 -> V_71 = 0 ;
}
}
}
int F_20 ( struct V_74 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_74 ) ;
int V_6 ;
F_22 ( & V_2 -> V_75 ) ;
V_2 -> V_76 ++ ;
V_6 = F_23 ( V_2 -> V_13 ) ;
if ( V_6 < 0 ) {
V_2 -> V_76 -- ;
V_6 = - V_34 ;
goto V_77;
}
if ( V_2 -> V_76 == 1 ) {
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 ) {
F_25 ( V_2 -> V_13 ) ;
goto V_77;
}
F_26 ( V_2 -> V_72 , V_2 -> V_7 ,
F_27 ( V_2 -> V_7 ,
V_2 -> V_78 -> V_79 ) ,
V_2 -> V_53 ,
F_28 ( V_2 -> V_78 -> V_80 ) ,
F_16 ,
V_2 ,
V_2 -> V_78 -> V_81 ) ;
V_2 -> V_71 = 1 ;
F_29 () ;
V_6 = F_19 ( V_2 -> V_72 , V_82 ) ;
if ( V_6 ) {
F_30 ( & V_2 -> V_13 -> V_14 ,
L_7 , V_6 ) ;
V_2 -> V_71 = 0 ;
F_25 ( V_2 -> V_13 ) ;
}
}
V_77:
F_31 ( & V_2 -> V_75 ) ;
return V_6 ;
}
int F_32 ( struct V_74 * V_74 )
{
struct V_1 * V_2 = F_21 ( V_74 ) ;
int V_6 = 0 ;
if ( ! V_2 ) {
V_6 = - V_83 ;
goto V_77;
}
F_22 ( & V_2 -> V_75 ) ;
V_2 -> V_76 -- ;
if ( V_2 -> V_76 == 0 ) {
if ( V_2 -> V_71 ) {
V_2 -> V_71 = 0 ;
if ( V_2 -> V_72 )
F_33 ( V_2 -> V_72 ) ;
}
if ( V_2 -> V_33 ) {
F_34 ( V_2 -> V_84 ) ;
F_35 ( V_2 -> V_53 ) ;
F_35 ( V_2 -> V_66 ) ;
F_31 ( & V_2 -> V_75 ) ;
F_35 ( V_2 ) ;
goto V_77;
}
F_18 ( & V_2 -> V_70 ) ;
V_6 = F_36 ( V_2 ) ;
F_25 ( V_2 -> V_13 ) ;
}
F_31 ( & V_2 -> V_75 ) ;
V_77:
return V_6 ;
}
int F_37 ( struct V_74 * V_74 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = F_21 ( V_74 ) ;
F_38 ( V_87 -> V_88 , V_89 , sizeof( V_87 -> V_88 ) ) ;
F_38 ( V_87 -> V_90 , V_91 , sizeof( V_87 -> V_90 ) ) ;
F_39 ( V_2 -> V_7 , V_87 -> V_92 ,
sizeof( V_87 -> V_92 ) ) ;
V_87 -> V_93 = V_94 ;
V_87 -> V_95 = V_96 |
V_97 | V_98 | V_99 ;
return 0 ;
}
static int F_40 ( struct V_100 * V_13 ,
const struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_107 , V_108 , V_6 = 0 ;
unsigned char V_109 = 0 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_2 ) {
V_6 = - V_110 ;
goto V_111;
}
V_2 -> V_76 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_7 = F_42 ( V_13 ) ;
V_2 -> V_13 = V_13 ;
F_43 ( & V_2 -> V_75 ) ;
V_104 = V_13 -> V_112 ;
for ( V_107 = 0 ; V_107 < V_104 -> V_113 . V_114 ; ++ V_107 ) {
V_106 = & V_104 -> V_106 [ V_107 ] . V_113 ;
if ( ( ( V_106 -> V_79 & V_115 ) ==
V_11 ) && ( ( V_106 -> V_116 &
V_117 ) == V_118 ) )
V_2 -> V_78 = V_106 ;
}
if ( ! V_2 -> V_78 ) {
F_30 ( & V_13 -> V_14 , L_8 ) ;
V_6 = - V_34 ;
goto V_119;
}
V_108 = F_28 ( V_2 -> V_78 -> V_80 ) ;
V_2 -> V_53 = F_44 ( V_108 , V_82 ) ;
if ( ! V_2 -> V_53 ) {
F_30 ( & V_13 -> V_14 , L_9 ) ;
V_6 = - V_110 ;
goto V_119;
}
V_2 -> V_72 = F_45 ( 0 , V_82 ) ;
if ( ! V_2 -> V_72 ) {
F_30 ( & V_13 -> V_14 , L_10 ) ;
V_6 = - V_110 ;
goto V_120;
}
V_2 -> V_84 = F_46 () ;
if ( ! V_2 -> V_84 ) {
V_6 = - V_110 ;
goto V_120;
}
memcpy ( V_2 -> V_84 , & V_121 ,
sizeof( V_121 ) ) ;
F_47 ( V_2 -> V_84 , V_2 ) ;
if ( F_12 ( V_2 ) < 0 ) {
V_6 = - V_34 ;
goto V_122;
}
F_30 ( & V_13 -> V_14 , L_11 ,
V_2 -> V_19 [ V_123 ] , V_2 -> V_19 [ V_124 ] ) ;
if ( ( V_2 -> V_19 [ V_124 ] & V_125 ) < V_126 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_13 , V_126 ) ;
F_4 ( & V_13 -> V_14 ,
L_14 ,
V_2 -> V_19 [ V_124 ] & V_125 ) ;
V_109 = 1 ;
}
if ( F_14 ( V_2 ) < 0 ) {
V_6 = - V_34 ;
goto V_122;
}
F_30 ( & V_13 -> V_14 , L_15 ,
V_2 -> V_31 , V_2 -> V_32 ) ;
if ( V_2 -> V_31 < V_127 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_16 , V_127 ) ;
F_4 ( & V_13 -> V_14 ,
L_17 ,
V_2 -> V_31 ) ;
V_109 = 1 ;
}
if ( V_2 -> V_32 < V_128 ) {
F_4 ( & V_13 -> V_14 ,
L_12
L_18 , V_128 ) ;
F_4 ( & V_13 -> V_14 ,
L_19 ,
V_2 -> V_32 ) ;
V_109 = 1 ;
}
if ( V_109 == 1 ) {
F_4 ( & V_13 -> V_14 ,
L_20 ) ;
F_4 ( & V_13 -> V_14 ,
L_21
L_22 ) ;
}
F_48 ( V_2 , 87.5 * V_129 ) ;
F_13 ( V_2 , V_130 ) ;
V_2 -> V_68 = V_131 * 3 ;
V_2 -> V_66 = F_44 ( V_2 -> V_68 , V_82 ) ;
if ( ! V_2 -> V_66 ) {
V_6 = - V_34 ;
goto V_122;
}
V_2 -> V_67 = 0 ;
V_2 -> V_69 = 0 ;
F_49 ( & V_2 -> V_70 ) ;
V_6 = F_50 ( V_2 -> V_84 , V_132 ,
V_133 ) ;
if ( V_6 ) {
F_4 ( & V_13 -> V_14 , L_23 ) ;
goto V_134;
}
F_51 ( V_13 , V_2 ) ;
return 0 ;
V_134:
F_35 ( V_2 -> V_66 ) ;
V_122:
F_52 ( V_2 -> V_84 ) ;
V_120:
F_35 ( V_2 -> V_53 ) ;
V_119:
F_35 ( V_2 ) ;
V_111:
return V_6 ;
}
static int F_53 ( struct V_100 * V_13 ,
T_1 V_135 )
{
F_30 ( & V_13 -> V_14 , L_24 ) ;
return 0 ;
}
static int F_54 ( struct V_100 * V_13 )
{
F_30 ( & V_13 -> V_14 , L_25 ) ;
return 0 ;
}
static void F_55 ( struct V_100 * V_13 )
{
struct V_1 * V_2 = F_56 ( V_13 ) ;
F_22 ( & V_2 -> V_75 ) ;
V_2 -> V_33 = 1 ;
F_51 ( V_13 , NULL ) ;
if ( V_2 -> V_76 == 0 ) {
F_13 ( V_2 , V_136 ) ;
F_57 ( V_2 -> V_72 ) ;
F_35 ( V_2 -> V_53 ) ;
F_34 ( V_2 -> V_84 ) ;
F_35 ( V_2 -> V_66 ) ;
F_31 ( & V_2 -> V_75 ) ;
F_35 ( V_2 ) ;
} else {
F_31 ( & V_2 -> V_75 ) ;
}
}
static int T_2 F_58 ( void )
{
F_59 (KERN_INFO DRIVER_DESC L_26 DRIVER_VERSION L_27 ) ;
return F_60 ( & V_137 ) ;
}
static void T_3 F_61 ( void )
{
F_62 ( & V_137 ) ;
}
