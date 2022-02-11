static int F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
int V_5 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_7 , V_6 ) ;
F_3 ( ( V_2 << V_8 ) |
V_9 , & V_10 -> V_11 . V_12 . V_13 ) ;
F_4 () ;
V_5 = F_5 ( & V_10 -> V_11 . V_12 . V_13 ) ;
F_6 ( 200 ) ;
V_5 = F_5 ( & V_10 -> V_11 . V_12 . V_14 ) ;
F_7 ( & V_4 -> V_7 , V_6 ) ;
return V_5 ;
}
static int F_8 ( void * V_1 , int V_2 , int V_15 )
{
struct V_3 * V_4 = V_1 ;
int V_5 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_7 , V_6 ) ;
F_3 ( ( V_2 << V_8 ) |
( V_15 << V_16 ) ,
& V_10 -> V_11 . V_12 . V_13 ) ;
F_4 () ;
V_5 = F_5 ( & V_10 -> V_11 . V_12 . V_13 ) ;
F_6 ( 200 ) ;
F_7 ( & V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
V_20 -> type = V_21 ;
V_20 -> V_22 = 2 ;
V_20 -> V_23 . integer . V_24 = 0 ;
V_20 -> V_23 . integer . V_25 = F_11 ( & V_4 -> V_26 ,
( int ) V_18 -> V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_30 ;
V_30 = F_13 ( & V_4 -> V_26 , ( int ) V_18 -> V_27 ) ;
V_29 -> V_23 . integer . V_23 [ 0 ] = ( V_30 >> 8 ) & 0xFF ;
V_29 -> V_23 . integer . V_23 [ 1 ] = V_30 & 0xFF ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_31 , V_32 ;
V_32 = F_13 ( & V_4 -> V_26 , V_18 -> V_27 ) ;
V_31 = ( V_29 -> V_23 . integer . V_23 [ 0 ] << 8 ) |
V_29 -> V_23 . integer . V_23 [ 1 ] ;
V_31 = F_15 ( & V_4 -> V_26 , V_18 -> V_27 ,
V_31 ) ;
return V_31 != V_32 ;
}
static int F_16 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
static const char * const V_33 [ 3 ] = {
L_1 , L_2 , L_3
} ;
return F_17 ( V_20 , 1 , 3 , V_33 ) ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
V_29 -> V_23 . V_34 . V_35 [ 0 ] = F_19 ( & V_4 -> V_26 ) ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_36 , V_37 ;
V_37 = F_19 ( & V_4 -> V_26 ) ;
V_36 = F_21 ( & V_4 -> V_26 ,
V_29 -> V_23 . V_34 . V_35 [ 0 ] ) ;
return V_36 != V_37 ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_40 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_41 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_42 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_43 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_44 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_45 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_23 ( V_4 -> V_39 ,
F_24 ( & V_46 , V_4 ) ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned int V_47 , unsigned int V_22 )
{
int V_48 ;
unsigned long V_49 , V_50 , V_51 ;
unsigned char * V_52 ;
int V_53 ;
T_1 * V_54 ;
T_2 * V_55 ;
T_1 V_56 ;
unsigned long V_6 ;
struct V_57 * V_58 = V_4 -> V_59 [ V_47 ] . V_60 -> V_58 ;
F_2 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
V_49 = ( unsigned long ) V_4 -> V_62 | ( V_47 << V_63 ) ;
V_50 = F_5 ( & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_65 ) ;
V_52 = V_58 -> V_66 ;
V_53 = V_4 -> V_59 [ V_47 ] . V_67 ;
V_51 = F_26 ( V_58 , V_58 -> V_68 ) - 1 ;
V_4 -> V_59 [ V_47 ] . V_69 += ( V_22 >> 3 ) ;
V_48 = V_4 -> V_59 [ V_47 ] . V_69 >= V_58 -> V_70 ;
V_4 -> V_59 [ V_47 ] . V_69 %= V_58 -> V_70 ;
while ( V_22 ) {
V_54 = ( T_1 * ) ( V_49 + V_50 ) ;
V_55 = ( T_2 * ) ( V_52 + V_53 ) ;
V_56 = * V_54 ;
V_55 [ 0 ] = ( V_56 >> V_71 ) & 0xffff ;
V_55 [ 1 ] = ( V_56 >> V_72 ) & 0xffff ;
V_50 = ( V_50 + sizeof( T_1 ) ) & V_73 ;
V_53 = ( V_53 + 2 * sizeof( T_2 ) ) & V_51 ;
V_22 -= sizeof( T_1 ) ;
}
F_3 ( V_50 , & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_65 ) ;
V_4 -> V_59 [ V_47 ] . V_67 = V_53 ;
F_7 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
return V_48 ;
}
static int F_27 ( struct V_3 * V_4 ,
unsigned int V_47 , unsigned int V_22 )
{
int V_48 ;
T_3 V_74 , V_75 ;
unsigned long V_52 , V_53 , V_76 ;
unsigned char * V_49 ;
int V_50 ;
T_1 * V_55 ;
T_2 * V_54 ;
unsigned long V_6 ;
struct V_57 * V_58 = V_4 -> V_59 [ V_47 ] . V_60 -> V_58 ;
F_2 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
V_52 = ( unsigned long ) V_4 -> V_62 | ( V_47 << V_63 ) ;
V_53 = F_5 ( & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_77 ) ;
V_49 = V_58 -> V_66 ;
V_50 = V_4 -> V_59 [ V_47 ] . V_67 ;
V_76 = F_26 ( V_58 , V_58 -> V_68 ) - 1 ;
V_4 -> V_59 [ V_47 ] . V_69 += ( V_22 >> 3 ) ;
V_48 = V_4 -> V_59 [ V_47 ] . V_69 >= V_58 -> V_70 ;
V_4 -> V_59 [ V_47 ] . V_69 %= V_58 -> V_70 ;
while ( V_22 ) {
V_54 = ( T_2 * ) ( V_49 + V_50 ) ;
V_55 = ( T_1 * ) ( V_52 + V_53 ) ;
V_74 = V_54 [ 0 ] ;
V_75 = V_54 [ 1 ] ;
* V_55 = ( ( V_74 & 0x00ffffff ) << V_71 ) |
( ( V_75 & 0x00ffffff ) << V_72 ) ;
V_53 = ( V_53 + sizeof( T_1 ) ) & V_73 ;
V_50 = ( V_50 + 2 * sizeof( T_2 ) ) & V_76 ;
V_22 -= sizeof( T_1 ) ;
}
F_3 ( V_53 , & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_77 ) ;
V_4 -> V_59 [ V_47 ] . V_67 = V_50 ;
F_7 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
return V_48 ;
}
static int F_28 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_79 * V_64 = V_60 -> V_58 -> V_80 ;
int V_47 = V_64 -> V_81 ;
F_3 ( V_82 , & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_83 ) ;
F_6 ( 10 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_83 ) ;
if ( V_60 -> V_84 == V_85 ) {
F_27 ( V_4 , V_47 , V_86 - 32 ) ;
}
F_3 ( V_87 | V_88 ,
& V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_83 ) ;
return 0 ;
}
static int F_30 ( struct V_78 * V_60 )
{
struct V_79 * V_64 = V_60 -> V_58 -> V_80 ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_64 [ V_64 -> V_81 ] . V_83 ) ;
return 0 ;
}
static T_4 F_31 ( int V_89 , void * V_90 )
{
struct V_79 * V_64 = V_90 ;
struct V_78 * V_60 ;
struct V_3 * V_4 ;
int V_22 , V_47 ;
V_60 = V_64 -> V_60 ;
V_4 = F_29 ( V_60 ) ;
V_47 = V_64 -> V_81 ;
V_22 = V_86 -
F_5 ( & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_91 ) - 32 ;
if ( F_25 ( V_4 , V_47 , V_22 ) )
F_32 ( V_60 ) ;
return V_92 ;
}
static T_4 F_33 ( int V_89 , void * V_90 )
{
struct V_79 * V_64 = V_90 ;
struct V_78 * V_60 ;
struct V_3 * V_4 ;
int V_22 , V_47 ;
V_60 = V_64 -> V_60 ;
V_4 = F_29 ( V_60 ) ;
V_47 = V_64 -> V_81 ;
V_22 = V_86 -
F_5 ( & V_10 -> V_11 . V_12 . V_64 [ V_47 ] . V_91 ) - 32 ;
if ( F_27 ( V_4 , V_47 , V_22 ) )
F_32 ( V_60 ) ;
return V_92 ;
}
static T_4 F_34 ( int V_89 , void * V_90 )
{
struct V_79 * V_64 = V_90 ;
struct V_78 * V_60 ;
V_60 = V_64 -> V_60 ;
F_30 ( V_60 ) ;
F_28 ( V_60 ) ;
return V_92 ;
}
static int F_35 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_57 * V_58 = V_60 -> V_58 ;
V_58 -> V_93 = V_94 ;
V_58 -> V_80 = & V_4 -> V_59 [ 1 ] ;
return 0 ;
}
static int F_36 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_57 * V_58 = V_60 -> V_58 ;
V_58 -> V_93 = V_94 ;
V_58 -> V_80 = & V_4 -> V_59 [ 2 ] ;
return 0 ;
}
static int F_37 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_57 * V_58 = V_60 -> V_58 ;
V_58 -> V_93 = V_94 ;
V_58 -> V_80 = & V_4 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_38 ( struct V_78 * V_60 )
{
struct V_57 * V_58 = V_60 -> V_58 ;
V_58 -> V_80 = NULL ;
return 0 ;
}
static int F_39 ( struct V_78 * V_60 ,
struct V_95 * V_96 )
{
return F_40 ( V_60 ,
F_41 ( V_96 ) ) ;
}
static int F_42 ( struct V_78 * V_60 )
{
return F_43 ( V_60 ) ;
}
static int F_44 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_57 * V_58 = V_60 -> V_58 ;
struct V_79 * V_64 = V_60 -> V_58 -> V_80 ;
int V_47 = V_64 -> V_81 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
V_4 -> V_59 [ V_47 ] . V_67 = 0 ;
V_4 -> V_59 [ V_47 ] . V_69 = 0 ;
V_4 -> V_59 [ V_47 ] . V_60 = V_60 ;
switch ( V_60 -> V_84 ) {
case V_85 :
F_45 ( & V_4 -> V_26 ,
V_47 - 1 ,
V_58 -> V_97 ,
V_98 ,
V_58 -> V_99 ) ;
break;
case V_100 :
F_46 ( & V_4 -> V_26 ,
V_58 -> V_97 ,
V_98 ,
V_58 -> V_99 ) ;
break;
}
F_7 ( & V_4 -> V_59 [ V_47 ] . V_61 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_78 * V_60 ,
int V_101 )
{
switch ( V_101 ) {
case V_102 :
F_28 ( V_60 ) ;
break;
case V_103 :
F_30 ( V_60 ) ;
break;
default:
return - V_104 ;
}
return 0 ;
}
static T_5
F_48 ( struct V_78 * V_60 )
{
struct V_3 * V_4 = F_29 ( V_60 ) ;
struct V_79 * V_64 = V_60 -> V_58 -> V_80 ;
return F_49 ( V_60 -> V_58 ,
V_4 -> V_59 [ V_64 -> V_81 ] . V_67 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_105 * V_106 ;
int V_38 ;
V_38 = F_51 ( V_4 -> V_39 , L_4 , 0 , 1 , 1 , & V_106 ) ;
if ( V_38 < 0 )
return V_38 ;
V_106 -> V_80 = V_4 ;
strcpy ( V_106 -> V_107 , L_5 ) ;
F_52 ( V_106 , V_85 ,
& V_108 ) ;
F_52 ( V_106 , V_100 ,
& V_109 ) ;
V_38 = F_51 ( V_4 -> V_39 , L_4 , 1 , 1 , 0 , & V_106 ) ;
if ( V_38 < 0 )
return V_38 ;
V_106 -> V_80 = V_4 ;
strcpy ( V_106 -> V_107 , L_6 ) ;
F_52 ( V_106 , V_85 ,
& V_110 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
int V_111 ;
F_3 ( V_112 , & V_10 -> V_11 . V_12 . V_83 ) ;
F_6 ( 1 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_83 ) ;
for ( V_111 = 0 ; V_111 < F_54 ( V_113 ) ; V_111 ++ )
F_55 ( V_113 [ V_111 ] . V_89 ,
& V_4 -> V_59 [ V_113 [ V_111 ] . V_81 ] ) ;
F_56 ( NULL , V_114 ,
V_4 -> V_62 , V_4 -> V_115 ) ;
F_57 ( V_4 ) ;
return 0 ;
}
static int F_58 ( struct V_116 * V_117 )
{
struct V_3 * V_4 = V_117 -> V_118 ;
return F_53 ( V_4 ) ;
}
static int F_59 ( struct V_119 * V_39 ,
struct V_3 * * V_120 )
{
struct V_3 * V_4 ;
int V_111 , V_38 ;
* V_120 = NULL ;
if ( ! ( F_5 ( & V_10 -> V_11 . V_12 . V_83 ) & V_121 ) )
return - V_122 ;
V_4 = F_60 ( sizeof( struct V_3 ) , V_123 ) ;
if ( V_4 == NULL )
return - V_124 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_62 = F_61 ( NULL , V_114 ,
& V_4 -> V_115 , V_125 ) ;
if ( V_4 -> V_62 == NULL ) {
F_62 ( V_126
L_7 ) ;
F_57 ( V_4 ) ;
return - V_124 ;
}
F_63 ( & V_4 -> V_7 ) ;
for ( V_111 = 0 ; V_111 < 3 ; V_111 ++ ) {
F_63 ( & V_4 -> V_59 [ V_111 ] . V_61 ) ;
V_4 -> V_59 [ V_111 ] . V_81 = V_111 ;
}
for ( V_111 = 0 ; V_111 < F_54 ( V_113 ) ; V_111 ++ ) {
if ( F_64 ( V_113 [ V_111 ] . V_89 ,
V_113 [ V_111 ] . V_127 ,
0 ,
V_113 [ V_111 ] . V_128 ,
& V_4 -> V_59 [ V_113 [ V_111 ] . V_81 ] ) ) {
F_53 ( V_4 ) ;
F_62 ( V_126 L_8 ,
V_113 [ V_111 ] . V_89 ) ;
return - V_129 ;
}
}
F_3 ( V_112 , & V_10 -> V_11 . V_12 . V_83 ) ;
F_6 ( 1 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_83 ) ;
F_65 ( 1 ) ;
F_3 ( V_4 -> V_115 , & V_10 -> V_11 . V_130 . V_131 ) ;
V_4 -> V_26 . V_132 = F_1 ;
V_4 -> V_26 . V_133 = F_8 ;
V_4 -> V_26 . V_4 = V_4 ;
V_38 = F_66 ( & V_4 -> V_26 ) ;
if ( V_38 < 0 ) {
F_53 ( V_4 ) ;
return V_38 ;
}
V_38 = F_67 ( V_39 , V_134 , V_4 , & V_135 ) ;
if ( V_38 < 0 ) {
F_53 ( V_4 ) ;
return V_38 ;
}
* V_120 = V_4 ;
return 0 ;
}
static int F_68 ( struct V_136 * V_137 )
{
struct V_119 * V_39 ;
struct V_3 * V_4 ;
int V_38 ;
V_38 = F_69 ( & V_137 -> V_138 , V_139 , V_140 , V_141 , 0 , & V_39 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_59 ( V_39 , & V_4 ) ;
if ( V_38 < 0 ) {
F_70 ( V_39 ) ;
return V_38 ;
}
V_38 = F_50 ( V_4 ) ;
if ( V_38 < 0 ) {
F_70 ( V_39 ) ;
return V_38 ;
}
V_38 = F_22 ( V_4 ) ;
if ( V_38 < 0 ) {
F_70 ( V_39 ) ;
return V_38 ;
}
strcpy ( V_39 -> V_142 , L_4 ) ;
strcpy ( V_39 -> V_143 , L_4 ) ;
sprintf ( V_39 -> V_144 , L_9 ,
V_39 -> V_143 ,
V_145 ,
V_146 ) ;
V_38 = F_71 ( V_39 ) ;
if ( V_38 < 0 ) {
F_70 ( V_39 ) ;
return V_38 ;
}
F_72 ( V_137 , V_39 ) ;
return 0 ;
}
static int F_73 ( struct V_136 * V_137 )
{
struct V_119 * V_39 = F_74 ( V_137 ) ;
F_70 ( V_39 ) ;
return 0 ;
}
