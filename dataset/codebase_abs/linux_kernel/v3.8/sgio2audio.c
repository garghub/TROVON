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
static const char * V_33 [ 3 ] = {
L_1 , L_2 , L_3
} ;
V_20 -> type = V_34 ;
V_20 -> V_22 = 1 ;
V_20 -> V_23 . V_35 . V_36 = 3 ;
if ( V_20 -> V_23 . V_35 . V_37 >= 3 )
V_20 -> V_23 . V_35 . V_37 = 1 ;
strcpy ( V_20 -> V_23 . V_35 . V_38 ,
V_33 [ V_20 -> V_23 . V_35 . V_37 ] ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
V_29 -> V_23 . V_35 . V_37 [ 0 ] = F_18 ( & V_4 -> V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_39 , V_40 ;
V_40 = F_18 ( & V_4 -> V_26 ) ;
V_39 = F_20 ( & V_4 -> V_26 ,
V_29 -> V_23 . V_35 . V_37 [ 0 ] ) ;
return V_39 != V_40 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_43 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_44 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_45 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_46 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_47 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_48 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_22 ( V_4 -> V_42 ,
F_23 ( & V_49 , V_4 ) ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
unsigned int V_50 , unsigned int V_22 )
{
int V_51 ;
unsigned long V_52 , V_53 , V_54 ;
unsigned char * V_55 ;
int V_56 ;
T_1 * V_57 ;
T_2 * V_58 ;
T_1 V_59 ;
unsigned long V_6 ;
struct V_60 * V_61 = V_4 -> V_62 [ V_50 ] . V_63 -> V_61 ;
F_2 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
V_52 = ( unsigned long ) V_4 -> V_65 | ( V_50 << V_66 ) ;
V_53 = F_5 ( & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_68 ) ;
V_55 = V_61 -> V_69 ;
V_56 = V_4 -> V_62 [ V_50 ] . V_70 ;
V_54 = F_25 ( V_61 , V_61 -> V_71 ) - 1 ;
V_4 -> V_62 [ V_50 ] . V_72 += ( V_22 >> 3 ) ;
V_51 = V_4 -> V_62 [ V_50 ] . V_72 >= V_61 -> V_73 ;
V_4 -> V_62 [ V_50 ] . V_72 %= V_61 -> V_73 ;
while ( V_22 ) {
V_57 = ( T_1 * ) ( V_52 + V_53 ) ;
V_58 = ( T_2 * ) ( V_55 + V_56 ) ;
V_59 = * V_57 ;
V_58 [ 0 ] = ( V_59 >> V_74 ) & 0xffff ;
V_58 [ 1 ] = ( V_59 >> V_75 ) & 0xffff ;
V_53 = ( V_53 + sizeof( T_1 ) ) & V_76 ;
V_56 = ( V_56 + 2 * sizeof( T_2 ) ) & V_54 ;
V_22 -= sizeof( T_1 ) ;
}
F_3 ( V_53 , & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_68 ) ;
V_4 -> V_62 [ V_50 ] . V_70 = V_56 ;
F_7 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
return V_51 ;
}
static int F_26 ( struct V_3 * V_4 ,
unsigned int V_50 , unsigned int V_22 )
{
int V_51 ;
T_3 V_77 , V_78 ;
unsigned long V_55 , V_56 , V_79 ;
unsigned char * V_52 ;
int V_53 ;
T_1 * V_58 ;
T_2 * V_57 ;
unsigned long V_6 ;
struct V_60 * V_61 = V_4 -> V_62 [ V_50 ] . V_63 -> V_61 ;
F_2 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
V_55 = ( unsigned long ) V_4 -> V_65 | ( V_50 << V_66 ) ;
V_56 = F_5 ( & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_80 ) ;
V_52 = V_61 -> V_69 ;
V_53 = V_4 -> V_62 [ V_50 ] . V_70 ;
V_79 = F_25 ( V_61 , V_61 -> V_71 ) - 1 ;
V_4 -> V_62 [ V_50 ] . V_72 += ( V_22 >> 3 ) ;
V_51 = V_4 -> V_62 [ V_50 ] . V_72 >= V_61 -> V_73 ;
V_4 -> V_62 [ V_50 ] . V_72 %= V_61 -> V_73 ;
while ( V_22 ) {
V_57 = ( T_2 * ) ( V_52 + V_53 ) ;
V_58 = ( T_1 * ) ( V_55 + V_56 ) ;
V_77 = V_57 [ 0 ] ;
V_78 = V_57 [ 1 ] ;
* V_58 = ( ( V_77 & 0x00ffffff ) << V_74 ) |
( ( V_78 & 0x00ffffff ) << V_75 ) ;
V_56 = ( V_56 + sizeof( T_1 ) ) & V_76 ;
V_53 = ( V_53 + 2 * sizeof( T_2 ) ) & V_79 ;
V_22 -= sizeof( T_1 ) ;
}
F_3 ( V_56 , & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_80 ) ;
V_4 -> V_62 [ V_50 ] . V_70 = V_53 ;
F_7 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
return V_51 ;
}
static int F_27 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_82 * V_67 = V_63 -> V_61 -> V_83 ;
int V_50 = V_67 -> V_84 ;
F_3 ( V_85 , & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_86 ) ;
F_6 ( 10 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_86 ) ;
if ( V_63 -> V_87 == V_88 ) {
F_26 ( V_4 , V_50 , V_89 - 32 ) ;
}
F_3 ( V_90 | V_91 ,
& V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_86 ) ;
return 0 ;
}
static int F_29 ( struct V_81 * V_63 )
{
struct V_82 * V_67 = V_63 -> V_61 -> V_83 ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_67 [ V_67 -> V_84 ] . V_86 ) ;
return 0 ;
}
static T_4 F_30 ( int V_92 , void * V_93 )
{
struct V_82 * V_67 = V_93 ;
struct V_81 * V_63 ;
struct V_3 * V_4 ;
int V_22 , V_50 ;
V_63 = V_67 -> V_63 ;
V_4 = F_28 ( V_63 ) ;
V_50 = V_67 -> V_84 ;
V_22 = V_89 -
F_5 ( & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_94 ) - 32 ;
if ( F_24 ( V_4 , V_50 , V_22 ) )
F_31 ( V_63 ) ;
return V_95 ;
}
static T_4 F_32 ( int V_92 , void * V_93 )
{
struct V_82 * V_67 = V_93 ;
struct V_81 * V_63 ;
struct V_3 * V_4 ;
int V_22 , V_50 ;
V_63 = V_67 -> V_63 ;
V_4 = F_28 ( V_63 ) ;
V_50 = V_67 -> V_84 ;
V_22 = V_89 -
F_5 ( & V_10 -> V_11 . V_12 . V_67 [ V_50 ] . V_94 ) - 32 ;
if ( F_26 ( V_4 , V_50 , V_22 ) )
F_31 ( V_63 ) ;
return V_95 ;
}
static T_4 F_33 ( int V_92 , void * V_93 )
{
struct V_82 * V_67 = V_93 ;
struct V_81 * V_63 ;
V_63 = V_67 -> V_63 ;
F_29 ( V_63 ) ;
F_27 ( V_63 ) ;
return V_95 ;
}
static int F_34 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_60 * V_61 = V_63 -> V_61 ;
V_61 -> V_96 = V_97 ;
V_61 -> V_83 = & V_4 -> V_62 [ 1 ] ;
return 0 ;
}
static int F_35 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_60 * V_61 = V_63 -> V_61 ;
V_61 -> V_96 = V_97 ;
V_61 -> V_83 = & V_4 -> V_62 [ 2 ] ;
return 0 ;
}
static int F_36 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_60 * V_61 = V_63 -> V_61 ;
V_61 -> V_96 = V_97 ;
V_61 -> V_83 = & V_4 -> V_62 [ 0 ] ;
return 0 ;
}
static int F_37 ( struct V_81 * V_63 )
{
struct V_60 * V_61 = V_63 -> V_61 ;
V_61 -> V_83 = NULL ;
return 0 ;
}
static int F_38 ( struct V_81 * V_63 ,
struct V_98 * V_99 )
{
return F_39 ( V_63 ,
F_40 ( V_99 ) ) ;
}
static int F_41 ( struct V_81 * V_63 )
{
return F_42 ( V_63 ) ;
}
static int F_43 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_60 * V_61 = V_63 -> V_61 ;
struct V_82 * V_67 = V_63 -> V_61 -> V_83 ;
int V_50 = V_67 -> V_84 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
V_4 -> V_62 [ V_50 ] . V_70 = 0 ;
V_4 -> V_62 [ V_50 ] . V_72 = 0 ;
V_4 -> V_62 [ V_50 ] . V_63 = V_63 ;
switch ( V_63 -> V_87 ) {
case V_88 :
F_44 ( & V_4 -> V_26 ,
V_50 - 1 ,
V_61 -> V_100 ,
V_101 ,
V_61 -> V_102 ) ;
break;
case V_103 :
F_45 ( & V_4 -> V_26 ,
V_61 -> V_100 ,
V_101 ,
V_61 -> V_102 ) ;
break;
}
F_7 ( & V_4 -> V_62 [ V_50 ] . V_64 , V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_81 * V_63 ,
int V_104 )
{
switch ( V_104 ) {
case V_105 :
F_27 ( V_63 ) ;
break;
case V_106 :
F_29 ( V_63 ) ;
break;
default:
return - V_107 ;
}
return 0 ;
}
static T_5
F_47 ( struct V_81 * V_63 )
{
struct V_3 * V_4 = F_28 ( V_63 ) ;
struct V_82 * V_67 = V_63 -> V_61 -> V_83 ;
return F_48 ( V_63 -> V_61 ,
V_4 -> V_62 [ V_67 -> V_84 ] . V_70 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_108 * V_109 ;
int V_41 ;
V_41 = F_50 ( V_4 -> V_42 , L_4 , 0 , 1 , 1 , & V_109 ) ;
if ( V_41 < 0 )
return V_41 ;
V_109 -> V_83 = V_4 ;
strcpy ( V_109 -> V_38 , L_5 ) ;
F_51 ( V_109 , V_88 ,
& V_110 ) ;
F_51 ( V_109 , V_103 ,
& V_111 ) ;
V_41 = F_50 ( V_4 -> V_42 , L_4 , 1 , 1 , 0 , & V_109 ) ;
if ( V_41 < 0 )
return V_41 ;
V_109 -> V_83 = V_4 ;
strcpy ( V_109 -> V_38 , L_6 ) ;
F_51 ( V_109 , V_88 ,
& V_112 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 )
{
int V_113 ;
F_3 ( V_114 , & V_10 -> V_11 . V_12 . V_86 ) ;
F_6 ( 1 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_86 ) ;
for ( V_113 = 0 ; V_113 < F_53 ( V_115 ) ; V_113 ++ )
F_54 ( V_115 [ V_113 ] . V_92 ,
& V_4 -> V_62 [ V_115 [ V_113 ] . V_84 ] ) ;
F_55 ( NULL , V_116 ,
V_4 -> V_65 , V_4 -> V_117 ) ;
F_56 ( V_4 ) ;
return 0 ;
}
static int F_57 ( struct V_118 * V_119 )
{
struct V_3 * V_4 = V_119 -> V_120 ;
return F_52 ( V_4 ) ;
}
static int F_58 ( struct V_121 * V_42 ,
struct V_3 * * V_122 )
{
struct V_3 * V_4 ;
int V_113 , V_41 ;
* V_122 = NULL ;
if ( ! ( F_5 ( & V_10 -> V_11 . V_12 . V_86 ) & V_123 ) )
return - V_124 ;
V_4 = F_59 ( sizeof( struct V_3 ) , V_125 ) ;
if ( V_4 == NULL )
return - V_126 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_65 = F_60 ( NULL , V_116 ,
& V_4 -> V_117 , V_127 ) ;
if ( V_4 -> V_65 == NULL ) {
F_61 ( V_128
L_7 ) ;
F_56 ( V_4 ) ;
return - V_126 ;
}
F_62 ( & V_4 -> V_7 ) ;
for ( V_113 = 0 ; V_113 < 3 ; V_113 ++ ) {
F_62 ( & V_4 -> V_62 [ V_113 ] . V_64 ) ;
V_4 -> V_62 [ V_113 ] . V_84 = V_113 ;
}
for ( V_113 = 0 ; V_113 < F_53 ( V_115 ) ; V_113 ++ ) {
if ( F_63 ( V_115 [ V_113 ] . V_92 ,
V_115 [ V_113 ] . V_129 ,
0 ,
V_115 [ V_113 ] . V_130 ,
& V_4 -> V_62 [ V_115 [ V_113 ] . V_84 ] ) ) {
F_52 ( V_4 ) ;
F_61 ( V_128 L_8 ,
V_115 [ V_113 ] . V_92 ) ;
return - V_131 ;
}
}
F_3 ( V_114 , & V_10 -> V_11 . V_12 . V_86 ) ;
F_6 ( 1 ) ;
F_3 ( 0 , & V_10 -> V_11 . V_12 . V_86 ) ;
F_64 ( 1 ) ;
F_3 ( V_4 -> V_117 , & V_10 -> V_11 . V_132 . V_133 ) ;
V_4 -> V_26 . V_134 = F_1 ;
V_4 -> V_26 . V_135 = F_8 ;
V_4 -> V_26 . V_4 = V_4 ;
V_41 = F_65 ( & V_4 -> V_26 ) ;
if ( V_41 < 0 ) {
F_52 ( V_4 ) ;
return V_41 ;
}
V_41 = F_66 ( V_42 , V_136 , V_4 , & V_137 ) ;
if ( V_41 < 0 ) {
F_52 ( V_4 ) ;
return V_41 ;
}
* V_122 = V_4 ;
return 0 ;
}
static int F_67 ( struct V_138 * V_139 )
{
struct V_121 * V_42 ;
struct V_3 * V_4 ;
int V_41 ;
V_41 = F_68 ( V_140 , V_141 , V_142 , 0 , & V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_58 ( V_42 , & V_4 ) ;
if ( V_41 < 0 ) {
F_69 ( V_42 ) ;
return V_41 ;
}
F_70 ( V_42 , & V_139 -> V_143 ) ;
V_41 = F_49 ( V_4 ) ;
if ( V_41 < 0 ) {
F_69 ( V_42 ) ;
return V_41 ;
}
V_41 = F_21 ( V_4 ) ;
if ( V_41 < 0 ) {
F_69 ( V_42 ) ;
return V_41 ;
}
strcpy ( V_42 -> V_144 , L_4 ) ;
strcpy ( V_42 -> V_145 , L_4 ) ;
sprintf ( V_42 -> V_146 , L_9 ,
V_42 -> V_145 ,
V_147 ,
V_148 ) ;
V_41 = F_71 ( V_42 ) ;
if ( V_41 < 0 ) {
F_69 ( V_42 ) ;
return V_41 ;
}
F_72 ( V_139 , V_42 ) ;
return 0 ;
}
static int F_73 ( struct V_138 * V_139 )
{
struct V_121 * V_42 = F_74 ( V_139 ) ;
F_69 ( V_42 ) ;
F_72 ( V_139 , NULL ) ;
return 0 ;
}
