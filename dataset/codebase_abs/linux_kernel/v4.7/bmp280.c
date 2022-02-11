static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
} ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static T_1 F_3 ( struct V_14 * V_15 ,
T_1 V_16 )
{
int V_17 ;
T_1 V_18 , V_19 ;
T_2 V_20 [ V_21 / 2 ] ;
V_17 = F_4 ( V_15 -> V_22 , V_23 ,
V_20 , V_21 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_1 ) ;
return V_17 ;
}
V_18 = ( ( ( V_16 >> 3 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) << 1 ) ) *
( ( T_1 ) ( V_26 ) F_6 ( V_20 [ V_27 ] ) ) ) >> 11 ;
V_19 = ( ( ( ( ( V_16 >> 4 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) ) ) *
( ( V_16 >> 4 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) ) ) ) >> 12 ) *
( ( T_1 ) ( V_26 ) F_6 ( V_20 [ V_28 ] ) ) ) >> 14 ;
V_15 -> V_29 = V_18 + V_19 ;
return ( V_15 -> V_29 * 5 + 128 ) >> 8 ;
}
static T_3 F_7 ( struct V_14 * V_15 ,
T_1 V_30 )
{
int V_17 ;
T_4 V_18 , V_19 , V_31 ;
T_2 V_20 [ V_32 / 2 ] ;
V_17 = F_4 ( V_15 -> V_22 , V_33 ,
V_20 , V_32 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_2 ) ;
return V_17 ;
}
V_18 = ( ( T_4 ) V_15 -> V_29 ) - 128000 ;
V_19 = V_18 * V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_34 ] ) ;
V_19 += ( V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_35 ] ) ) << 17 ;
V_19 += ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_36 ] ) ) << 35 ;
V_18 = ( ( V_18 * V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_37 ] ) ) >> 8 ) +
( ( V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_38 ] ) ) << 12 ) ;
V_18 = ( ( ( ( T_4 ) 1 ) << 47 ) + V_18 ) * ( ( T_4 ) F_6 ( V_20 [ V_39 ] ) ) >> 33 ;
if ( V_18 == 0 )
return 0 ;
V_31 = ( ( ( ( T_4 ) 1048576 - V_30 ) << 31 ) - V_19 ) * 3125 ;
V_31 = F_8 ( V_31 , V_18 ) ;
V_18 = ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_40 ] ) ) * ( V_31 >> 13 ) * ( V_31 >> 13 ) ) >> 25 ;
V_19 = ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_41 ] ) ) * V_31 ) >> 19 ;
V_31 = ( ( V_31 + V_18 + V_19 ) >> 8 ) + ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_42 ] ) ) << 4 ) ;
return ( T_3 ) V_31 ;
}
static int F_9 ( struct V_14 * V_15 ,
int * V_43 )
{
int V_17 ;
T_5 V_44 = 0 ;
T_1 V_16 , V_45 ;
V_17 = F_4 ( V_15 -> V_22 , V_9 ,
( V_46 * ) & V_44 , 3 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 , L_3 ) ;
return V_17 ;
}
V_16 = F_10 ( V_44 ) >> 12 ;
V_45 = F_3 ( V_15 , V_16 ) ;
if ( V_43 ) {
* V_43 = V_45 * 10 ;
return V_47 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
int * V_43 , int * V_48 )
{
int V_17 ;
T_5 V_44 = 0 ;
T_1 V_30 ;
T_3 V_49 ;
V_17 = F_9 ( V_15 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_15 -> V_22 , V_12 ,
( V_46 * ) & V_44 , 3 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 , L_4 ) ;
return V_17 ;
}
V_30 = F_10 ( V_44 ) >> 12 ;
V_49 = F_7 ( V_15 , V_30 ) ;
* V_43 = V_49 ;
* V_48 = 256000 ;
return V_50 ;
}
static int F_12 ( struct V_51 * V_52 ,
struct V_53 const * V_54 ,
int * V_43 , int * V_48 , long V_55 )
{
int V_17 ;
struct V_14 * V_15 = F_13 ( V_52 ) ;
F_14 ( & V_15 -> V_56 ) ;
switch ( V_55 ) {
case V_57 :
switch ( V_54 -> type ) {
case V_58 :
V_17 = V_15 -> V_59 -> V_60 ( V_15 , V_43 , V_48 ) ;
break;
case V_61 :
V_17 = V_15 -> V_59 -> V_62 ( V_15 , V_43 ) ;
break;
default:
V_17 = - V_63 ;
break;
}
break;
case V_64 :
switch ( V_54 -> type ) {
case V_58 :
* V_43 = 1 << V_15 -> V_65 ;
V_17 = V_47 ;
break;
case V_61 :
* V_43 = 1 << V_15 -> V_66 ;
V_17 = V_47 ;
break;
default:
V_17 = - V_63 ;
break;
}
break;
default:
V_17 = - V_63 ;
break;
}
F_15 ( & V_15 -> V_56 ) ;
return V_17 ;
}
static int F_16 ( struct V_14 * V_15 ,
int V_43 )
{
int V_67 ;
const int * V_68 = V_15 -> V_59 -> V_69 ;
const int V_70 = V_15 -> V_59 -> V_71 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
if ( V_68 [ V_67 ] == V_43 ) {
V_15 -> V_66 = F_17 ( V_43 ) ;
return V_15 -> V_59 -> V_72 ( V_15 ) ;
}
}
return - V_63 ;
}
static int F_18 ( struct V_14 * V_15 ,
int V_43 )
{
int V_67 ;
const int * V_68 = V_15 -> V_59 -> V_73 ;
const int V_70 = V_15 -> V_59 -> V_74 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
if ( V_68 [ V_67 ] == V_43 ) {
V_15 -> V_65 = F_17 ( V_43 ) ;
return V_15 -> V_59 -> V_72 ( V_15 ) ;
}
}
return - V_63 ;
}
static int F_19 ( struct V_51 * V_52 ,
struct V_53 const * V_54 ,
int V_43 , int V_48 , long V_55 )
{
int V_17 = 0 ;
struct V_14 * V_15 = F_13 ( V_52 ) ;
switch ( V_55 ) {
case V_64 :
F_14 ( & V_15 -> V_56 ) ;
switch ( V_54 -> type ) {
case V_58 :
V_17 = F_18 ( V_15 , V_43 ) ;
break;
case V_61 :
V_17 = F_16 ( V_15 , V_43 ) ;
break;
default:
V_17 = - V_63 ;
break;
}
F_15 ( & V_15 -> V_56 ) ;
break;
default:
return - V_63 ;
}
return V_17 ;
}
static T_6 F_20 ( char * V_20 , const int * V_75 , const int V_70 )
{
T_7 V_76 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ )
V_76 += F_21 ( V_20 + V_76 , V_77 - V_76 , L_5 , V_75 [ V_67 ] ) ;
V_20 [ V_76 - 1 ] = '\n' ;
return V_76 ;
}
static T_6 F_22 ( struct V_1 * V_2 ,
struct V_78 * V_79 , char * V_20 )
{
struct V_14 * V_15 = F_13 ( F_23 ( V_2 ) ) ;
return F_20 ( V_20 , V_15 -> V_59 -> V_69 ,
V_15 -> V_59 -> V_71 ) ;
}
static T_6 F_24 ( struct V_1 * V_2 ,
struct V_78 * V_79 , char * V_20 )
{
struct V_14 * V_15 = F_13 ( F_23 ( V_2 ) ) ;
return F_20 ( V_20 , V_15 -> V_59 -> V_73 ,
V_15 -> V_59 -> V_74 ) ;
}
static int F_25 ( struct V_14 * V_15 )
{
int V_17 ;
V_46 V_80 = F_26 ( V_15 -> V_66 + 1 ) |
F_27 ( V_15 -> V_65 + 1 ) ;
V_17 = F_28 ( V_15 -> V_22 , V_5 ,
V_81 |
V_82 |
V_83 ,
V_80 | V_84 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_6 ) ;
return V_17 ;
}
V_17 = F_28 ( V_15 -> V_22 , V_4 ,
V_85 ,
V_86 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_7 ) ;
return V_17 ;
}
return V_17 ;
}
static bool F_29 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
return true ;
default:
return false ;
} ;
}
static bool F_30 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_87 :
case V_88 :
case V_89 :
case V_5 :
return true ;
default:
return false ;
}
}
static int F_31 ( struct V_14 * V_15 , V_46 V_90 )
{
int V_17 ;
const int V_91 [] = { 4500 , 7500 , 13500 , 25500 } ;
unsigned int V_92 ;
unsigned int V_93 ;
V_17 = F_32 ( V_15 -> V_22 , V_5 , V_90 ) ;
if ( V_17 )
return V_17 ;
if ( V_90 == V_94 )
V_92 = 4500 ;
else
V_92 = V_91 [ V_15 -> V_65 ] ;
F_33 ( V_92 , V_92 + 1000 ) ;
V_17 = F_34 ( V_15 -> V_22 , V_5 , & V_93 ) ;
if ( V_17 )
return V_17 ;
if ( V_93 & V_95 )
return - V_96 ;
return 0 ;
}
static int F_35 ( struct V_14 * V_15 , int * V_43 )
{
int V_17 ;
T_8 V_44 = 0 ;
V_17 = F_31 ( V_15 , V_94 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_4 ( V_15 -> V_22 , V_89 , ( V_46 * ) & V_44 , 2 ) ;
if ( V_17 )
return V_17 ;
* V_43 = F_36 ( V_44 ) ;
return 0 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_97 * V_98 )
{
int V_17 ;
int V_67 ;
T_8 V_20 [ V_99 / 2 ] ;
V_17 = F_4 ( V_15 -> V_22 , V_100 , V_20 ,
sizeof( V_20 ) ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_67 = 0 ; V_67 < F_38 ( V_20 ) ; V_67 ++ ) {
if ( V_20 [ V_67 ] == F_39 ( 0 ) || V_20 [ V_67 ] == F_39 ( 0xffff ) )
return - V_96 ;
}
V_98 -> V_101 = F_36 ( V_20 [ V_101 ] ) ;
V_98 -> V_102 = F_36 ( V_20 [ V_102 ] ) ;
V_98 -> V_103 = F_36 ( V_20 [ V_103 ] ) ;
V_98 -> V_104 = F_36 ( V_20 [ V_104 ] ) ;
V_98 -> V_105 = F_36 ( V_20 [ V_105 ] ) ;
V_98 -> V_106 = F_36 ( V_20 [ V_106 ] ) ;
V_98 -> V_107 = F_36 ( V_20 [ V_107 ] ) ;
V_98 -> V_108 = F_36 ( V_20 [ V_108 ] ) ;
V_98 -> V_109 = F_36 ( V_20 [ V_109 ] ) ;
V_98 -> V_110 = F_36 ( V_20 [ V_110 ] ) ;
V_98 -> V_111 = F_36 ( V_20 [ V_111 ] ) ;
return 0 ;
}
static T_1 F_40 ( struct V_14 * V_15 , T_1 V_16 )
{
int V_17 ;
T_1 V_112 , V_113 ;
struct V_97 V_98 ;
V_17 = F_37 ( V_15 , & V_98 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_8 ) ;
return V_17 ;
}
V_112 = ( ( V_16 - V_98 . V_106 ) * V_98 . V_105 ) >> 15 ;
V_113 = ( V_98 . V_110 << 11 ) / ( V_112 + V_98 . V_111 ) ;
V_15 -> V_29 = V_112 + V_113 ;
return ( V_15 -> V_29 + 8 ) >> 4 ;
}
static int F_41 ( struct V_14 * V_15 , int * V_43 )
{
int V_17 ;
T_1 V_16 , V_45 ;
V_17 = F_35 ( V_15 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_45 = F_40 ( V_15 , V_16 ) ;
if ( V_43 ) {
* V_43 = V_45 * 100 ;
return V_47 ;
}
return 0 ;
}
static int F_42 ( struct V_14 * V_15 , int * V_43 )
{
int V_17 ;
T_5 V_44 = 0 ;
V_46 V_114 = V_15 -> V_65 ;
V_17 = F_31 ( V_15 , F_43 ( V_114 ) ) ;
if ( V_17 )
return V_17 ;
V_17 = F_4 ( V_15 -> V_22 , V_89 , ( V_46 * ) & V_44 , 3 ) ;
if ( V_17 )
return V_17 ;
* V_43 = ( F_10 ( V_44 ) >> 8 ) >> ( 8 - V_114 ) ;
return 0 ;
}
static T_3 F_44 ( struct V_14 * V_15 , T_1 V_30 )
{
int V_17 ;
T_1 V_112 , V_113 , V_115 , V_31 ;
T_1 V_116 , V_117 ;
T_3 V_118 , V_119 ;
T_1 V_114 = V_15 -> V_65 ;
struct V_97 V_98 ;
V_17 = F_37 ( V_15 , & V_98 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_8 ) ;
return V_17 ;
}
V_117 = V_15 -> V_29 - 4000 ;
V_112 = ( V_98 . V_108 * ( V_117 * V_117 >> 12 ) ) >> 11 ;
V_113 = V_98 . V_102 * V_117 >> 11 ;
V_115 = V_112 + V_113 ;
V_116 = ( ( ( ( T_1 ) V_98 . V_101 * 4 + V_115 ) << V_114 ) + 2 ) / 4 ;
V_112 = V_98 . V_103 * V_117 >> 13 ;
V_113 = ( V_98 . V_107 * ( ( V_117 * V_117 ) >> 12 ) ) >> 16 ;
V_115 = ( V_112 + V_113 + 2 ) >> 2 ;
V_118 = V_98 . V_104 * ( T_3 ) ( V_115 + 32768 ) >> 15 ;
V_119 = ( ( T_3 ) V_30 - V_116 ) * ( 50000 >> V_114 ) ;
if ( V_119 < 0x80000000 )
V_31 = ( V_119 * 2 ) / V_118 ;
else
V_31 = ( V_119 / V_118 ) * 2 ;
V_112 = ( V_31 >> 8 ) * ( V_31 >> 8 ) ;
V_112 = ( V_112 * 3038 ) >> 16 ;
V_113 = ( - 7357 * V_31 ) >> 16 ;
return V_31 + ( ( V_112 + V_113 + 3791 ) >> 4 ) ;
}
static int F_45 ( struct V_14 * V_15 ,
int * V_43 , int * V_48 )
{
int V_17 ;
T_1 V_30 ;
T_3 V_49 ;
V_17 = F_41 ( V_15 , NULL ) ;
if ( V_17 )
return V_17 ;
V_17 = F_42 ( V_15 , & V_30 ) ;
if ( V_17 )
return V_17 ;
V_49 = F_44 ( V_15 , V_30 ) ;
* V_43 = V_49 ;
* V_48 = 1000 ;
return V_50 ;
}
static int F_46 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_47 ( struct V_120 * V_24 ,
const struct V_121 * V_122 )
{
int V_17 ;
struct V_51 * V_52 ;
struct V_14 * V_15 ;
unsigned int V_123 ;
V_52 = F_48 ( & V_24 -> V_2 , sizeof( * V_15 ) ) ;
if ( ! V_52 )
return - V_124 ;
V_15 = F_13 ( V_52 ) ;
F_49 ( & V_15 -> V_56 ) ;
V_15 -> V_24 = V_24 ;
V_52 -> V_2 . V_125 = & V_24 -> V_2 ;
V_52 -> V_126 = V_122 -> V_126 ;
V_52 -> V_127 = V_128 ;
V_52 -> V_129 = F_38 ( V_128 ) ;
V_52 -> V_130 = & V_131 ;
V_52 -> V_132 = V_133 ;
switch ( V_122 -> V_134 ) {
case V_135 :
V_15 -> V_59 = & V_136 ;
V_15 -> V_65 = F_17 ( 8 ) ;
V_15 -> V_66 = F_17 ( 1 ) ;
break;
case V_137 :
V_15 -> V_59 = & V_138 ;
V_15 -> V_65 = F_17 ( 16 ) ;
V_15 -> V_66 = F_17 ( 2 ) ;
break;
default:
return - V_63 ;
}
V_15 -> V_22 = F_50 ( V_24 ,
V_15 -> V_59 -> V_139 ) ;
if ( F_51 ( V_15 -> V_22 ) ) {
F_5 ( & V_24 -> V_2 , L_9 ) ;
return F_52 ( V_15 -> V_22 ) ;
}
V_17 = F_34 ( V_15 -> V_22 , V_140 , & V_123 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_123 != V_122 -> V_134 ) {
F_5 ( & V_24 -> V_2 , L_10 ,
V_122 -> V_134 , V_123 ) ;
return - V_63 ;
}
V_17 = V_15 -> V_59 -> V_72 ( V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_53 ( & V_24 -> V_2 , V_52 ) ;
}
