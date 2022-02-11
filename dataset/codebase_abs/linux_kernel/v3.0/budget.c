static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , ( V_2 ? V_5 : V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_7 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , V_5 ) ;
F_5 ( V_7 ? 500 : 1000 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_5 ( V_7 ? 1000 : 500 ) ;
}
static void F_6 ( struct V_1 * V_1 , int V_7 )
{
int V_8 , V_9 = 1 , V_10 ;
F_2 ( 2 , L_1 , V_1 ) ;
for ( V_8 = 7 ; V_8 >= 0 ; V_8 -- ) {
V_10 = ( V_7 >> V_8 ) & 1 ;
V_9 ^= V_10 ;
F_4 ( V_1 , V_10 ) ;
}
F_4 ( V_1 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_11 , T_1 * V_12 , unsigned long V_13 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_8 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_8 ( 16 ) ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
F_6 ( V_1 , V_12 [ V_8 ] ) ;
F_8 ( 16 ) ;
if ( V_13 != - 1 ) {
if ( V_13 )
F_6 ( V_1 , 0xff ) ;
else {
F_3 ( V_4 , 3 , V_5 ) ;
F_8 ( 12 ) ;
F_5 ( 500 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
}
F_9 ( 20 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
switch ( V_14 ) {
case V_15 :
F_3 ( V_4 , 1 , V_5 ) ;
F_3 ( V_4 , 2 , V_6 ) ;
break;
case V_16 :
F_3 ( V_4 , 1 , V_5 ) ;
F_3 ( V_4 , 2 , V_5 ) ;
break;
case V_17 :
F_3 ( V_4 , 1 , V_6 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_19 * V_20 , T_2 V_14 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
return F_10 ( V_1 , V_14 ) ;
}
static int F_12 ( struct V_19 * V_20 , T_3 V_23 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
switch ( V_23 ) {
case V_24 :
F_1 ( V_1 , 1 ) ;
break;
case V_25 :
F_1 ( V_1 , 0 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
F_7 ( V_1 , V_27 -> V_28 , V_27 -> V_12 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , T_4 V_29 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
F_7 ( V_1 , 0 , NULL , V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
T_1 V_32 = 0 ;
T_1 V_33 [ 4 ] ;
struct V_34 V_12 = { . V_35 = 0x61 , . V_36 = 0 , . V_33 = V_33 , . V_11 = sizeof( V_33 ) } ;
T_5 div = ( V_31 -> V_37 + 479500 ) / 125 ;
if ( V_31 -> V_37 > 2000000 ) V_32 = 3 ;
else if ( V_31 -> V_37 > 1800000 ) V_32 = 2 ;
else if ( V_31 -> V_37 > 1600000 ) V_32 = 1 ;
else if ( V_31 -> V_37 > 1200000 ) V_32 = 0 ;
else if ( V_31 -> V_37 >= 1100000 ) V_32 = 1 ;
else V_32 = 2 ;
V_33 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_33 [ 1 ] = div & 0xff ;
V_33 [ 2 ] = ( ( div & 0x18000 ) >> 10 ) | 0x95 ;
V_33 [ 3 ] = ( V_32 << 6 ) | 0x30 ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
if ( F_16 ( & V_1 -> V_40 , & V_12 , 1 ) != 1 ) return - V_41 ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
T_5 div ;
T_1 V_7 [ 4 ] ;
struct V_34 V_12 = { . V_35 = 0x62 , . V_36 = 0 , . V_33 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = ( V_31 -> V_37 + 35937500 + 31250 ) / 62500 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x85 | ( ( div >> 10 ) & 0x60 ) ;
V_7 [ 3 ] = ( V_31 -> V_37 < 174000000 ? 0x88 : V_31 -> V_37 < 470000000 ? 0x84 : 0x81 ) ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
if ( F_16 ( & V_1 -> V_40 , & V_12 , 1 ) != 1 ) return - V_41 ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
struct V_1 * V_1 = V_20 -> V_21 -> V_22 ;
T_1 * V_42 = V_20 -> V_43 ;
T_5 div ;
T_1 V_44 , V_45 , V_46 ;
T_1 V_7 [ 4 ] ;
struct V_34 V_12 = { . V_36 = 0 , . V_33 = V_7 , . V_11 = sizeof( V_7 ) } ;
if ( V_42 )
V_12 . V_35 = * V_42 ;
else
V_12 . V_35 = 0x61 ;
div = ( 36125000 + V_31 -> V_37 ) / 166666 ;
V_44 = 0x88 ;
if ( V_31 -> V_37 < 175000000 ) V_45 = 2 ;
else if ( V_31 -> V_37 < 390000000 ) V_45 = 1 ;
else if ( V_31 -> V_37 < 470000000 ) V_45 = 2 ;
else if ( V_31 -> V_37 < 750000000 ) V_45 = 1 ;
else V_45 = 3 ;
if ( V_31 -> V_37 < 175000000 ) V_46 = 0x0e ;
else if ( V_31 -> V_37 < 470000000 ) V_46 = 0x05 ;
else V_46 = 0x03 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = ( ( div >> 10 ) & 0x60 ) | V_44 ;
V_7 [ 3 ] = ( V_45 << 6 ) | V_46 ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
if ( F_16 ( & V_1 -> V_40 , & V_12 , 1 ) != 1 ) return - V_41 ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
T_5 div ;
T_1 V_7 [ 4 ] ;
struct V_34 V_12 = { . V_35 = 0x61 , . V_36 = 0 , . V_33 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_31 -> V_37 / 125 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x8e ;
V_7 [ 3 ] = 0x00 ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
if ( F_16 ( & V_1 -> V_40 , & V_12 , 1 ) != 1 ) return - V_41 ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , struct V_30 * V_31 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
T_5 div ;
T_1 V_7 [ 4 ] ;
struct V_34 V_12 = { . V_35 = 0x61 , . V_36 = 0 , . V_33 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_31 -> V_37 / 1000 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0xc2 ;
if ( div < 1450 )
V_7 [ 3 ] = 0x00 ;
else if ( div < 1850 )
V_7 [ 3 ] = 0x40 ;
else if ( div < 2000 )
V_7 [ 3 ] = 0x80 ;
else
V_7 [ 3 ] = 0xc0 ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
if ( F_16 ( & V_1 -> V_40 , & V_12 , 1 ) != 1 ) return - V_41 ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , const struct V_47 * * V_48 , char * V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_21 -> V_22 ;
return F_22 ( V_48 , V_49 , & V_1 -> V_4 -> V_50 -> V_4 ) ;
}
static int F_23 ( struct V_51 * V_52 , T_1 V_53 , T_1 V_54 )
{
T_1 V_55 ;
struct V_34 V_12 [] = {
{ . V_35 = V_53 , . V_36 = 0 , . V_33 = & V_54 , . V_11 = 1 } ,
{ . V_35 = V_53 , . V_36 = V_56 , . V_33 = & V_55 , . V_11 = 1 }
} ;
return ( F_16 ( V_52 , V_12 , 2 ) != 2 ) ? - V_41 : V_55 ;
}
static T_1 F_24 ( struct V_1 * V_1 )
{
T_1 V_57 = 0xff ;
T_1 V_58 ;
struct V_34 V_12 [] = { { . V_35 = 0x50 , . V_36 = 0 , . V_33 = & V_57 , . V_11 = 1 } ,
{ . V_35 = 0x50 , . V_36 = V_56 , . V_33 = & V_58 , . V_11 = 1 } } ;
if ( ( F_16 ( & V_1 -> V_40 , V_12 , 2 ) != 2 ) || ( V_58 == 0xff ) )
V_58 = 0x48 ;
return V_58 ;
}
static void F_25 ( struct V_1 * V_1 )
{
( void ) V_59 ;
switch( V_1 -> V_4 -> V_50 -> V_60 ) {
case 0x1003 :
case 0x1013 :
V_1 -> V_19 = F_26 ( V_61 , & V_62 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_15 ;
V_1 -> V_19 -> V_38 . V_65 = F_13 ;
V_1 -> V_19 -> V_38 . V_66 = F_14 ;
V_1 -> V_19 -> V_38 . V_67 = F_12 ;
break;
}
V_1 -> V_19 = F_26 ( V_68 , & V_69 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = V_70 ;
V_1 -> V_19 -> V_43 = & V_1 -> V_40 ;
if ( V_1 -> V_4 -> V_50 -> V_60 == 0x1003 && V_71 == 0 ) {
V_1 -> V_19 -> V_38 . V_65 = F_13 ;
V_1 -> V_19 -> V_38 . V_66 = F_14 ;
V_1 -> V_19 -> V_38 . V_67 = F_12 ;
}
break;
}
break;
case 0x1004 :
V_1 -> V_19 = F_26 ( V_72 , & V_73 , & V_1 -> V_40 , F_24 ( V_1 ) ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_17 ;
break;
}
break;
case 0x1005 :
V_1 -> V_19 = F_26 ( V_74 , & V_75 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_18 ;
V_1 -> V_19 -> V_43 = NULL ;
break;
}
break;
case 0x4f60 :
{
int V_76 = F_23 ( & V_1 -> V_40 , 0x50 , 0x67 ) ;
if ( V_76 < 0 )
break;
if ( V_76 < 0x36 ) {
V_1 -> V_19 = F_26 ( V_68 , & V_77 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
F_27 ( V_78 L_2 ) ;
V_1 -> V_19 -> V_38 . V_63 . V_64 = V_70 ;
V_1 -> V_19 -> V_43 = & V_1 -> V_40 ;
V_1 -> V_19 -> V_38 . V_79 = F_11 ;
V_1 -> V_19 -> V_38 . V_80 = NULL ;
break;
}
} else {
F_3 ( V_1 -> V_4 , 3 , V_6 ) ;
F_9 ( 50 ) ;
F_3 ( V_1 -> V_4 , 3 , V_5 ) ;
F_9 ( 250 ) ;
V_1 -> V_19 = F_26 ( V_68 , & V_81 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
F_27 ( V_78 L_3 ) ;
V_1 -> V_19 -> V_38 . V_63 . V_64 = V_82 ;
V_1 -> V_19 -> V_43 = & V_1 -> V_40 ;
V_1 -> V_19 -> V_38 . V_79 = F_11 ;
V_1 -> V_19 -> V_38 . V_80 = NULL ;
break;
}
}
break;
}
case 0x4f61 :
V_1 -> V_19 = F_26 ( V_83 , & V_84 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_19 ;
V_1 -> V_19 -> V_38 . V_79 = F_11 ;
V_1 -> V_19 -> V_38 . V_80 = NULL ;
}
break;
case 0x5f60 :
V_1 -> V_19 = F_26 ( V_85 , & V_86 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = V_87 ;
V_1 -> V_19 -> V_43 = & V_1 -> V_40 ;
}
break;
case 0x5f61 :
V_1 -> V_19 = F_26 ( V_74 , & V_88 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_43 = & V_89 ;
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_18 ;
}
break;
case 0x1016 :
V_1 -> V_19 = F_26 ( V_90 , & V_91 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 -> V_38 . V_63 . V_64 = F_20 ;
if ( F_26 ( V_92 , V_1 -> V_19 , & V_1 -> V_40 , 0 , 0 ) == NULL ) {
F_27 ( L_4 , V_93 ) ;
goto V_94;
}
break;
}
case 0x1018 :
F_3 ( V_1 -> V_4 , 2 , V_6 ) ;
F_9 ( 1 ) ;
F_3 ( V_1 -> V_4 , 2 , V_5 ) ;
F_9 ( 1 ) ;
V_1 -> V_19 = F_26 ( V_95 , & V_96 , & V_1 -> V_40 ) ;
if ( V_1 -> V_19 ) {
if ( F_26 ( V_97 , V_1 -> V_19 , 0x60 , & V_1 -> V_40 , 0 ) == NULL )
F_27 ( L_5 , V_93 ) ;
if ( F_26 ( V_92 , V_1 -> V_19 , & V_1 -> V_40 , 0 , 0 ) == NULL ) {
F_27 ( L_4 , V_93 ) ;
goto V_94;
}
break;
}
case 0x101c : {
struct V_98 * V_99 ;
F_3 ( V_1 -> V_4 , 2 , V_6 ) ;
F_9 ( 50 ) ;
F_3 ( V_1 -> V_4 , 2 , V_5 ) ;
F_9 ( 250 ) ;
V_1 -> V_19 = F_26 ( V_100 ,
& V_101 ,
& V_1 -> V_40 ,
V_102 ) ;
if ( V_1 -> V_19 ) {
V_99 = F_26 ( V_103 ,
V_1 -> V_19 ,
& V_104 ,
& V_1 -> V_40 ) ;
if ( V_99 ) {
V_101 . V_105 = V_99 -> V_105 ;
V_101 . V_106 = V_99 -> V_106 ;
V_101 . V_107 = V_99 -> V_107 ;
V_101 . V_108 = V_99 -> V_108 ;
V_101 . V_109 = V_99 -> V_109 ;
V_101 . V_110 = V_99 -> V_110 ;
V_101 . V_111 = V_99 -> V_111 ;
V_101 . V_112 = V_99 -> V_112 ;
V_101 . V_113 = V_99 -> V_113 ;
V_101 . V_114 = V_99 -> V_114 ;
V_101 . V_115 = V_99 -> V_115 ;
if ( V_1 -> V_19 -> V_38 . V_116 )
V_1 -> V_19 -> V_38 . V_116 ( V_1 -> V_19 ) ;
if ( F_26 ( V_117 ,
V_1 -> V_19 ,
& V_1 -> V_40 ,
& V_118 ) == NULL ) {
F_27 ( V_119 L_6 , V_93 ) ;
goto V_94;
}
} else {
F_27 ( V_119 L_7 , V_93 ) ;
goto V_94;
}
}
}
break;
}
if ( V_1 -> V_19 == NULL ) {
F_27 ( L_8 ,
V_1 -> V_4 -> V_50 -> V_120 ,
V_1 -> V_4 -> V_50 -> V_121 ,
V_1 -> V_4 -> V_50 -> V_122 ,
V_1 -> V_4 -> V_50 -> V_60 ) ;
} else {
if ( F_28 ( & V_1 -> V_123 , V_1 -> V_19 ) )
goto V_94;
}
return;
V_94:
F_27 ( L_9 ) ;
F_29 ( V_1 -> V_19 ) ;
V_1 -> V_19 = NULL ;
return;
}
static int F_30 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
struct V_1 * V_1 = NULL ;
int V_126 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_127 ) ;
if( NULL == V_1 ) {
return - V_128 ;
}
F_2 ( 2 , L_10 , V_4 , V_125 , V_1 ) ;
V_4 -> V_129 = V_1 ;
V_126 = F_32 ( V_1 , V_4 , V_125 , V_130 , V_131 ) ;
if ( V_126 ) {
F_27 ( L_11 ) ;
F_33 ( V_1 ) ;
return V_126 ;
}
V_1 -> V_123 . V_22 = V_1 ;
F_25 ( V_1 ) ;
F_34 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 -> V_129 ;
int V_126 ;
if ( V_1 -> V_19 ) {
F_36 ( V_1 -> V_19 ) ;
F_29 ( V_1 -> V_19 ) ;
}
V_126 = F_37 ( V_1 ) ;
F_33 ( V_1 ) ;
V_4 -> V_129 = NULL ;
return V_126 ;
}
static int T_6 F_38 ( void )
{
return F_39 ( & V_132 ) ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_132 ) ;
}
