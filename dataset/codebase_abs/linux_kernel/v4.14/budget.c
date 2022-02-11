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
static int F_10 ( struct V_1 * V_1 ,
enum V_14 V_15 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
switch ( V_15 ) {
case V_16 :
F_3 ( V_4 , 1 , V_5 ) ;
F_3 ( V_4 , 2 , V_6 ) ;
break;
case V_17 :
F_3 ( V_4 , 1 , V_5 ) ;
F_3 ( V_4 , 2 , V_5 ) ;
break;
case V_18 :
F_3 ( V_4 , 1 , V_6 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
enum V_14 V_15 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
return F_10 ( V_1 , V_15 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
enum V_24 V_25 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
switch ( V_25 ) {
case V_26 :
F_1 ( V_1 , 1 ) ;
break;
case V_27 :
F_1 ( V_1 , 0 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
F_7 ( V_1 , V_29 -> V_30 , V_29 -> V_12 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
enum V_31 V_32 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
F_7 ( V_1 , 0 , NULL , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = & V_21 -> V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
T_1 V_36 = 0 ;
T_1 V_37 [ 4 ] ;
struct V_38 V_12 = { . V_39 = 0x61 , . V_40 = 0 , . V_37 = V_37 , . V_11 = sizeof( V_37 ) } ;
T_2 div = ( V_34 -> V_41 + 479500 ) / 125 ;
if ( V_34 -> V_41 > 2000000 )
V_36 = 3 ;
else if ( V_34 -> V_41 > 1800000 )
V_36 = 2 ;
else if ( V_34 -> V_41 > 1600000 )
V_36 = 1 ;
else if ( V_34 -> V_41 > 1200000 )
V_36 = 0 ;
else if ( V_34 -> V_41 >= 1100000 )
V_36 = 1 ;
else V_36 = 2 ;
V_37 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_37 [ 1 ] = div & 0xff ;
V_37 [ 2 ] = ( ( div & 0x18000 ) >> 10 ) | 0x95 ;
V_37 [ 3 ] = ( V_36 << 6 ) | 0x30 ;
if ( V_21 -> V_42 . V_43 )
V_21 -> V_42 . V_43 ( V_21 , 1 ) ;
if ( F_16 ( & V_1 -> V_44 , & V_12 , 1 ) != 1 ) return - V_45 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = & V_21 -> V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
T_2 div ;
T_1 V_7 [ 4 ] ;
struct V_38 V_12 = { . V_39 = 0x62 , . V_40 = 0 , . V_37 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = ( V_34 -> V_41 + 35937500 + 31250 ) / 62500 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x85 | ( ( div >> 10 ) & 0x60 ) ;
V_7 [ 3 ] = ( V_34 -> V_41 < 174000000 ? 0x88 : V_34 -> V_41 < 470000000 ? 0x84 : 0x81 ) ;
if ( V_21 -> V_42 . V_43 )
V_21 -> V_42 . V_43 ( V_21 , 1 ) ;
if ( F_16 ( & V_1 -> V_44 , & V_12 , 1 ) != 1 ) return - V_45 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = & V_21 -> V_35 ;
struct V_1 * V_1 = V_21 -> V_22 -> V_23 ;
T_1 * V_46 = V_21 -> V_47 ;
T_2 div ;
T_1 V_48 , V_49 , V_50 ;
T_1 V_7 [ 4 ] ;
struct V_38 V_12 = { . V_40 = 0 , . V_37 = V_7 , . V_11 = sizeof( V_7 ) } ;
if ( V_46 )
V_12 . V_39 = * V_46 ;
else
V_12 . V_39 = 0x61 ;
div = ( 36125000 + V_34 -> V_41 ) / 166666 ;
V_48 = 0x88 ;
if ( V_34 -> V_41 < 175000000 )
V_49 = 2 ;
else if ( V_34 -> V_41 < 390000000 )
V_49 = 1 ;
else if ( V_34 -> V_41 < 470000000 )
V_49 = 2 ;
else if ( V_34 -> V_41 < 750000000 )
V_49 = 1 ;
else
V_49 = 3 ;
if ( V_34 -> V_41 < 175000000 )
V_50 = 0x0e ;
else if ( V_34 -> V_41 < 470000000 )
V_50 = 0x05 ;
else
V_50 = 0x03 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = ( ( div >> 10 ) & 0x60 ) | V_48 ;
V_7 [ 3 ] = ( V_49 << 6 ) | V_50 ;
if ( V_21 -> V_42 . V_43 )
V_21 -> V_42 . V_43 ( V_21 , 1 ) ;
if ( F_16 ( & V_1 -> V_44 , & V_12 , 1 ) != 1 ) return - V_45 ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = & V_21 -> V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
T_2 div ;
T_1 V_7 [ 4 ] ;
struct V_38 V_12 = { . V_39 = 0x61 , . V_40 = 0 , . V_37 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_34 -> V_41 / 125 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x8e ;
V_7 [ 3 ] = 0x00 ;
if ( V_21 -> V_42 . V_43 )
V_21 -> V_42 . V_43 ( V_21 , 1 ) ;
if ( F_16 ( & V_1 -> V_44 , & V_12 , 1 ) != 1 ) return - V_45 ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = & V_21 -> V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
T_2 div ;
T_1 V_7 [ 4 ] ;
struct V_38 V_12 = { . V_39 = 0x61 , . V_40 = 0 , . V_37 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_34 -> V_41 / 1000 ;
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
if ( V_21 -> V_42 . V_43 )
V_21 -> V_42 . V_43 ( V_21 , 1 ) ;
if ( F_16 ( & V_1 -> V_44 , & V_12 , 1 ) != 1 ) return - V_45 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , const struct V_51 * * V_52 , char * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 -> V_22 -> V_23 ;
return F_22 ( V_52 , V_53 , & V_1 -> V_4 -> V_54 -> V_4 ) ;
}
static int F_23 ( struct V_55 * V_56 , T_1 V_57 , T_1 V_58 )
{
T_1 V_59 ;
struct V_38 V_12 [] = {
{ . V_39 = V_57 , . V_40 = 0 , . V_37 = & V_58 , . V_11 = 1 } ,
{ . V_39 = V_57 , . V_40 = V_60 , . V_37 = & V_59 , . V_11 = 1 }
} ;
return ( F_16 ( V_56 , V_12 , 2 ) != 2 ) ? - V_45 : V_59 ;
}
static T_1 F_24 ( struct V_1 * V_1 )
{
T_1 V_61 = 0xff ;
T_1 V_62 ;
struct V_38 V_12 [] = { { . V_39 = 0x50 , . V_40 = 0 , . V_37 = & V_61 , . V_11 = 1 } ,
{ . V_39 = 0x50 , . V_40 = V_60 , . V_37 = & V_62 , . V_11 = 1 } } ;
if ( ( F_16 ( & V_1 -> V_44 , V_12 , 2 ) != 2 ) || ( V_62 == 0xff ) )
V_62 = 0x48 ;
return V_62 ;
}
static void F_25 ( struct V_1 * V_1 )
{
( void ) V_63 ;
switch( V_1 -> V_4 -> V_54 -> V_64 ) {
case 0x1003 :
case 0x1013 :
V_1 -> V_20 = F_26 ( V_65 , & V_66 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = F_15 ;
V_1 -> V_20 -> V_42 . V_69 = F_13 ;
V_1 -> V_20 -> V_42 . V_70 = F_14 ;
V_1 -> V_20 -> V_42 . V_71 = F_12 ;
break;
}
V_1 -> V_20 = F_26 ( V_72 , & V_73 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = V_74 ;
V_1 -> V_20 -> V_47 = & V_1 -> V_44 ;
if ( V_1 -> V_4 -> V_54 -> V_64 == 0x1003 && V_75 == 0 ) {
V_1 -> V_20 -> V_42 . V_69 = F_13 ;
V_1 -> V_20 -> V_42 . V_70 = F_14 ;
V_1 -> V_20 -> V_42 . V_71 = F_12 ;
}
break;
}
break;
case 0x1004 :
V_1 -> V_20 = F_26 ( V_76 , & V_77 , & V_1 -> V_44 , F_24 ( V_1 ) ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = F_17 ;
break;
}
break;
case 0x1005 :
V_1 -> V_20 = F_26 ( V_78 , & V_79 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = F_18 ;
V_1 -> V_20 -> V_47 = NULL ;
break;
}
break;
case 0x4f52 :
V_1 -> V_20 = F_26 ( V_72 , & V_73 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
F_27 ( V_80 L_2 ) ;
V_1 -> V_20 -> V_42 . V_67 . V_68 = V_74 ;
V_1 -> V_20 -> V_47 = & V_1 -> V_44 ;
break;
}
break;
case 0x4f60 :
{
int V_81 = F_23 ( & V_1 -> V_44 , 0x50 , 0x67 ) ;
if ( V_81 < 0 )
break;
if ( V_81 < 0x36 ) {
V_1 -> V_20 = F_26 ( V_72 , & V_82 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
F_27 ( V_80 L_3 ) ;
V_1 -> V_20 -> V_42 . V_67 . V_68 = V_74 ;
V_1 -> V_20 -> V_47 = & V_1 -> V_44 ;
V_1 -> V_20 -> V_42 . V_83 = F_11 ;
V_1 -> V_20 -> V_42 . V_84 = NULL ;
break;
}
} else {
F_3 ( V_1 -> V_4 , 3 , V_6 ) ;
F_9 ( 50 ) ;
F_3 ( V_1 -> V_4 , 3 , V_5 ) ;
F_9 ( 250 ) ;
V_1 -> V_20 = F_26 ( V_72 , & V_85 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
F_27 ( V_80 L_4 ) ;
V_1 -> V_20 -> V_42 . V_67 . V_68 = V_86 ;
V_1 -> V_20 -> V_47 = & V_1 -> V_44 ;
V_1 -> V_20 -> V_42 . V_83 = F_11 ;
V_1 -> V_20 -> V_42 . V_84 = NULL ;
break;
}
}
break;
}
case 0x4f61 :
V_1 -> V_20 = F_26 ( V_87 , & V_88 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = F_19 ;
V_1 -> V_20 -> V_42 . V_83 = F_11 ;
V_1 -> V_20 -> V_42 . V_84 = NULL ;
}
break;
case 0x5f60 :
V_1 -> V_20 = F_26 ( V_89 , & V_90 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_42 . V_67 . V_68 = V_91 ;
V_1 -> V_20 -> V_47 = & V_1 -> V_44 ;
}
break;
case 0x5f61 :
V_1 -> V_20 = F_26 ( V_78 , & V_92 , & V_1 -> V_44 ) ;
if ( V_1 -> V_20 ) {
V_1 -> V_20 -> V_47 = & V_93 ;
V_1 -> V_20 -> V_42 . V_67 . V_68 = F_18 ;
}
break;
case 0x1016 :
{
struct V_20 * V_21 ;
V_21 = F_26 ( V_94 , & V_95 , & V_1 -> V_44 ) ;
if ( V_21 ) {
V_21 -> V_42 . V_67 . V_68 = F_20 ;
V_1 -> V_20 = V_21 ;
if ( F_26 ( V_96 , V_21 , & V_1 -> V_44 ,
0 , 0 ) == NULL ) {
F_27 ( L_5 , V_97 ) ;
goto V_98;
}
break;
}
}
case 0x1018 :
{
struct V_20 * V_21 ;
F_3 ( V_1 -> V_4 , 2 , V_6 ) ;
F_9 ( 1 ) ;
F_3 ( V_1 -> V_4 , 2 , V_5 ) ;
F_9 ( 1 ) ;
V_21 = F_26 ( V_99 , & V_100 , & V_1 -> V_44 ) ;
if ( V_21 ) {
V_1 -> V_20 = V_21 ;
if ( F_26 ( V_101 , V_21 , 0x60 ,
& V_1 -> V_44 , 0 ) == NULL )
F_27 ( L_6 , V_97 ) ;
if ( F_26 ( V_96 , V_21 ,
& V_1 -> V_44 , 0 , 0 ) == NULL ) {
F_27 ( L_5 , V_97 ) ;
goto V_98;
}
break;
}
}
case 0x101c : {
const struct V_102 * V_103 ;
F_3 ( V_1 -> V_4 , 2 , V_6 ) ;
F_9 ( 50 ) ;
F_3 ( V_1 -> V_4 , 2 , V_5 ) ;
F_9 ( 250 ) ;
V_1 -> V_20 = F_26 ( V_104 ,
& V_105 ,
& V_1 -> V_44 ,
V_106 ) ;
if ( V_1 -> V_20 ) {
V_103 = F_26 ( V_107 ,
V_1 -> V_20 ,
& V_108 ,
& V_1 -> V_44 ) ;
if ( V_103 ) {
V_105 . V_109 = V_103 -> V_109 ;
V_105 . V_110 = V_103 -> V_110 ;
V_105 . V_111 = V_103 -> V_111 ;
V_105 . V_112 = V_103 -> V_112 ;
V_105 . V_113 = V_103 -> V_113 ;
V_105 . V_114 = V_103 -> V_114 ;
V_105 . V_115 = V_103 -> V_115 ;
V_105 . V_116 = V_103 -> V_116 ;
V_105 . V_117 = V_103 -> V_117 ;
V_105 . V_118 = V_103 -> V_118 ;
V_105 . V_119 = V_103 -> V_119 ;
if ( V_1 -> V_20 -> V_42 . V_120 )
V_1 -> V_20 -> V_42 . V_120 ( V_1 -> V_20 ) ;
if ( F_26 ( V_121 ,
V_1 -> V_20 ,
& V_1 -> V_44 ,
& V_122 ) == NULL ) {
F_27 ( V_123 L_7 , V_97 ) ;
goto V_98;
}
} else {
F_27 ( V_123 L_8 , V_97 ) ;
goto V_98;
}
}
}
break;
case 0x1020 : {
const struct V_102 * V_103 ;
F_3 ( V_1 -> V_4 , 2 , V_6 ) ;
F_9 ( 50 ) ;
F_3 ( V_1 -> V_4 , 2 , V_5 ) ;
F_9 ( 250 ) ;
V_1 -> V_20 = F_26 ( V_104 ,
& V_105 ,
& V_1 -> V_44 ,
V_106 ) ;
if ( V_1 -> V_20 ) {
F_27 ( V_80 L_9 ) ;
V_103 = F_26 ( V_107 ,
V_1 -> V_20 ,
& V_108 ,
& V_1 -> V_44 ) ;
if ( V_103 ) {
V_105 . V_109 = V_103 -> V_109 ;
V_105 . V_110 = V_103 -> V_110 ;
V_105 . V_111 = V_103 -> V_111 ;
V_105 . V_112 = V_103 -> V_112 ;
V_105 . V_113 = V_103 -> V_113 ;
V_105 . V_114 = V_103 -> V_114 ;
V_105 . V_115 = V_103 -> V_115 ;
V_105 . V_116 = V_103 -> V_116 ;
V_105 . V_117 = V_103 -> V_117 ;
V_105 . V_118 = V_103 -> V_118 ;
V_105 . V_119 = V_103 -> V_119 ;
if ( V_1 -> V_20 -> V_42 . V_120 )
V_1 -> V_20 -> V_42 . V_120 ( V_1 -> V_20 ) ;
if ( F_26 ( V_124 ,
V_1 -> V_20 ,
& V_1 -> V_44 ,
V_125 | V_126 ,
V_127 , 0x14 >> 1 ) == NULL ) {
F_27 ( V_123
L_10 ) ;
goto V_98;
}
} else {
F_27 ( V_123 L_8 , V_97 ) ;
goto V_98;
}
}
}
break;
}
if ( V_1 -> V_20 == NULL ) {
F_27 ( L_11 ,
V_1 -> V_4 -> V_54 -> V_128 ,
V_1 -> V_4 -> V_54 -> V_129 ,
V_1 -> V_4 -> V_54 -> V_130 ,
V_1 -> V_4 -> V_54 -> V_64 ) ;
} else {
if ( F_28 ( & V_1 -> V_131 , V_1 -> V_20 ) )
goto V_98;
}
return;
V_98:
F_27 ( L_12 ) ;
F_29 ( V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
return;
}
static int F_30 ( struct V_3 * V_4 , struct V_132 * V_133 )
{
struct V_1 * V_1 = NULL ;
int V_134 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_135 ) ;
if( NULL == V_1 ) {
return - V_136 ;
}
F_2 ( 2 , L_13 , V_4 , V_133 , V_1 ) ;
V_4 -> V_137 = V_1 ;
V_134 = F_32 ( V_1 , V_4 , V_133 , V_138 , V_139 ) ;
if ( V_134 ) {
F_27 ( L_14 ) ;
F_33 ( V_1 ) ;
return V_134 ;
}
V_1 -> V_131 . V_23 = V_1 ;
F_25 ( V_1 ) ;
F_34 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 -> V_137 ;
int V_134 ;
if ( V_1 -> V_20 ) {
F_36 ( V_1 -> V_20 ) ;
F_29 ( V_1 -> V_20 ) ;
}
V_134 = F_37 ( V_1 ) ;
F_33 ( V_1 ) ;
V_4 -> V_137 = NULL ;
return V_134 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_140 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_140 ) ;
}
