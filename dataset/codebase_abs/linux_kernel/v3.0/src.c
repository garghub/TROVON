static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 , V_6 ;
int V_7 = 0 ;
int V_8 ;
T_2 V_9 , V_10 ;
V_5 = F_2 ( V_4 , V_11 . V_12 ) ;
if ( V_5 & V_13 ) {
V_5 = V_13 ;
V_7 = 1 ;
V_9 = V_4 -> V_14 ;
if ( V_4 -> V_15 [ V_9 ] == 0 ) {
T_2 V_16 = V_9 ;
do {
V_9 ++ ;
if ( V_9 == V_4 -> V_17 -> V_18 +
V_19 )
V_9 = 0 ;
if ( V_4 -> V_15 [ V_9 ] != 0 )
break;
} while ( V_9 != V_16 );
V_4 -> V_14 = V_9 ;
}
for (; ; ) {
V_8 = 0 ;
V_10 = ( V_4 -> V_15 [ V_9 ] & 0x7fffffff ) ;
if ( V_10 & 0x40000000 )
V_8 = 1 ;
V_10 &= 0x0000ffff ;
if ( V_10 == 0 )
break;
F_3 ( V_4 , V_10 - 1 , 0 , V_8 , NULL ) ;
V_4 -> V_15 [ V_9 ++ ] = 0 ;
if ( V_9 == V_4 -> V_17 -> V_18 +
V_19 )
V_9 = 0 ;
V_4 -> V_14 = V_9 ;
}
} else {
V_6 = ( V_5 >> V_20 ) ;
if ( V_6 & V_21 ) {
V_7 = 1 ;
F_3 ( V_4 , 0 , 2 , 0 , NULL ) ;
}
}
if ( V_7 ) {
F_4 ( V_4 , V_11 . V_22 , V_5 ) ;
return V_23 ;
}
return V_24 ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_11 . V_25 , V_4 -> V_25 = 0xffffffff ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_11 . V_25 , V_4 -> V_25 = 0xfffffff8 ) ;
}
static int F_7 ( struct V_3 * V_4 , T_2 V_26 ,
T_2 V_27 , T_2 V_28 , T_2 V_29 , T_2 V_30 , T_2 V_31 , T_2 V_32 ,
T_2 * V_33 , T_2 * V_34 , T_2 * V_35 , T_2 * V_36 , T_2 * V_37 )
{
unsigned long V_38 ;
int V_39 ;
F_8 ( V_26 , & V_4 -> V_40 -> V_41 [ 0 ] ) ;
F_8 ( V_27 , & V_4 -> V_40 -> V_41 [ 1 ] ) ;
F_8 ( V_28 , & V_4 -> V_40 -> V_41 [ 2 ] ) ;
F_8 ( V_29 , & V_4 -> V_40 -> V_41 [ 3 ] ) ;
F_8 ( V_30 , & V_4 -> V_40 -> V_41 [ 4 ] ) ;
F_4 ( V_4 , V_11 . V_22 , V_42 << V_20 ) ;
F_4 ( V_4 , V_11 . V_25 , V_4 -> V_25 = 0xffffffff ) ;
F_2 ( V_4 , V_11 . V_25 ) ;
F_4 ( V_4 , V_11 . V_43 , V_44 << V_45 ) ;
V_39 = 0 ;
V_38 = V_46 ;
while ( F_9 ( V_46 , V_38 + 30 * V_47 ) ) {
F_10 ( 5 ) ;
if ( ( F_2 ( V_4 , V_11 . V_12 ) >> V_20 ) & V_42 ) {
F_4 ( V_4 ,
V_11 . V_22 ,
V_42 << V_20 ) ;
V_39 = 1 ;
break;
}
F_11 ( 1 ) ;
}
if ( F_12 ( V_39 != 1 ) ) {
F_13 ( V_4 ) ;
return - V_48 ;
}
if ( V_33 )
* V_33 = F_14 ( & V_4 -> V_40 -> V_41 [ 0 ] ) ;
if ( V_34 )
* V_34 = F_14 ( & V_4 -> V_40 -> V_41 [ 1 ] ) ;
if ( V_35 )
* V_35 = F_14 ( & V_4 -> V_40 -> V_41 [ 2 ] ) ;
if ( V_36 )
* V_36 = F_14 ( & V_4 -> V_40 -> V_41 [ 3 ] ) ;
if ( V_37 )
* V_37 = F_14 ( & V_4 -> V_40 -> V_41 [ 4 ] ) ;
F_4 ( V_4 , V_11 . V_22 , V_42 << V_20 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_7 ( V_4 , V_49 ,
0 , 0 , 0 , 0 , 0 , 0 ,
NULL , NULL , NULL , NULL , NULL ) ;
}
static void F_16 ( struct V_3 * V_4 , T_2 V_50 )
{
switch ( V_50 ) {
case V_51 :
F_4 ( V_4 , V_11 . V_22 ,
V_52 << V_20 ) ;
break;
case V_53 :
F_4 ( V_4 , V_11 . V_22 ,
V_54 << V_20 ) ;
break;
case V_55 :
F_4 ( V_4 , V_11 . V_22 ,
V_56 << V_20 ) ;
break;
case V_57 :
F_4 ( V_4 , V_11 . V_22 ,
V_58 << V_20 ) ;
break;
case V_59 :
F_4 ( V_4 , V_11 . V_22 ,
V_60 << V_20 ) ;
break;
case V_61 :
F_4 ( V_4 , V_11 . V_22 ,
V_62 << V_20 ) ;
break;
default:
F_17 () ;
break;
}
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_63 * V_64 ;
V_64 = V_4 -> V_64 ;
V_64 -> V_65 = F_19 ( F_20 () ) ;
F_7 ( V_4 , V_66 , ( T_2 ) ( V_67 ) V_4 -> V_68 ,
0 , 0 , 0 , 0 , 0 , NULL , NULL , NULL , NULL , NULL ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
T_2 V_33 = F_2 ( V_4 , V_11 . V_69 ) ;
if ( F_12 ( V_33 & V_70 ) )
return - 1 ;
if ( F_12 ( V_33 & V_71 ) )
return ( V_33 >> 16 ) & 0xFF ;
if ( F_12 ( ! ( V_33 & V_72 ) ) )
return - 3 ;
return 0 ;
}
static int F_22 ( struct V_73 * V_73 )
{
struct V_3 * V_4 = V_73 -> V_4 ;
struct V_74 * V_75 = & V_4 -> V_76 -> V_77 [ V_78 ] ;
unsigned long V_79 ;
T_2 V_80 ;
T_3 V_81 ;
struct V_82 * V_83 ;
F_23 ( V_75 -> V_84 , V_79 ) ;
V_75 -> V_85 ++ ;
F_24 ( V_75 -> V_84 , V_79 ) ;
V_80 = ( sizeof( struct V_82 ) +
V_73 -> V_86 -> V_87 . V_88 + 127 ) / 128 - 1 ;
if ( V_80 > ( V_89 - 1 ) )
V_80 = V_89 - 1 ;
V_83 = (struct V_82 * )
( ( unsigned char * ) V_73 -> V_86 -
sizeof( struct V_82 ) ) ;
V_83 -> V_90 = V_73 -> V_86 -> V_87 . V_91 + 1 ;
V_83 -> V_92 = V_73 -> V_93 ;
V_83 -> V_88 = V_73 -> V_86 -> V_87 . V_88 ;
V_81 = V_73 -> V_93 - ( T_3 ) sizeof( struct V_82 ) ;
F_4 ( V_4 , V_11 . V_94 , ( T_2 ) ( V_81 >> 32 ) ) ;
F_4 ( V_4 , V_11 . V_95 , ( T_2 ) ( V_81 & 0xffffffff ) + V_80 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 , T_2 V_96 )
{
if ( ! V_96 ) {
F_26 ( V_4 -> V_97 . V_98 . V_99 ) ;
V_4 -> V_97 . V_98 . V_99 = NULL ;
F_26 ( V_4 -> V_100 ) ;
V_4 -> V_100 = NULL ;
return 0 ;
}
V_4 -> V_97 . V_98 . V_101 = F_27 ( F_28 ( V_4 -> V_102 , 2 ) ,
V_103 ) ;
V_4 -> V_100 = NULL ;
if ( V_4 -> V_97 . V_98 . V_101 == NULL )
return - 1 ;
V_4 -> V_100 = V_4 -> V_97 . V_98 . V_99 = F_27 ( V_4 -> V_17 -> V_100 ,
V_96 ) ;
if ( V_4 -> V_100 == NULL ) {
F_26 ( V_4 -> V_97 . V_98 . V_101 ) ;
V_4 -> V_97 . V_98 . V_101 = NULL ;
return - 1 ;
}
V_4 -> V_40 = & ( (struct V_104 V_105 * )
V_4 -> V_100 ) -> V_40 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 , int V_106 )
{
T_2 V_107 , V_108 ;
if ( V_106 >= 0 ) {
if ( V_106 )
F_30 ( V_109 L_1 ,
V_4 -> V_110 , V_4 -> V_111 , V_106 ) ;
V_106 = F_31 ( V_4 , V_112 ,
0 , 0 , 0 , 0 , 0 , 0 , & V_107 , & V_108 , NULL , NULL , NULL ) ;
if ( V_106 || ( V_107 != 0x00000001 ) )
V_106 = - V_113 ;
if ( V_4 -> V_114 . V_115 &
V_116 ) {
F_4 ( V_4 , V_11 . V_43 , V_108 ) ;
F_11 ( 5000 ) ;
}
}
if ( F_2 ( V_4 , V_11 . V_69 ) & V_71 )
return - V_117 ;
if ( V_118 < 300 )
V_118 = 300 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 , int V_119 )
{
switch ( V_119 ) {
case V_120 :
V_4 -> V_121 . V_122 = F_6 ;
V_4 -> V_121 . V_123 = F_1 ;
V_4 -> V_121 . V_124 = F_22 ;
break;
default:
return 1 ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 )
{
unsigned long V_38 ;
unsigned long V_33 ;
int V_125 = 0 ;
int V_126 = V_4 -> V_111 ;
const char * V_110 = V_4 -> V_110 ;
V_4 -> V_121 . V_127 = F_25 ;
V_4 -> V_121 . V_128 = F_32 ;
V_4 -> V_129 = V_130 ;
if ( F_34 ( V_4 , V_4 -> V_129 ) ) {
F_30 ( V_131 L_2 , V_110 ) ;
goto V_132;
}
V_4 -> V_121 . V_133 = F_7 ;
V_4 -> V_121 . V_122 = F_5 ;
if ( ( V_134 || V_135 ) &&
! F_29 ( V_4 , 0 ) )
++ V_125 ;
V_33 = F_2 ( V_4 , V_11 . V_69 ) ;
if ( V_33 & V_71 ) {
if ( F_29 ( V_4 , F_21 ( V_4 ) ) )
goto V_132;
++ V_125 ;
}
V_33 = F_2 ( V_4 , V_11 . V_69 ) ;
if ( V_33 & V_70 ) {
F_30 ( V_109 L_3 ,
V_4 -> V_110 , V_126 ) ;
goto V_132;
}
if ( V_33 & V_136 ) {
F_30 ( V_109 L_4 ,
V_4 -> V_110 , V_126 ) ;
goto V_132;
}
V_38 = V_46 ;
while ( ! ( ( V_33 = F_2 ( V_4 , V_11 . V_69 ) ) &
V_72 ) ) {
if ( ( V_125 &&
( V_33 & ( V_71 | V_70 | V_136 ) ) ) ||
F_35 ( V_46 , V_38 + V_47 * V_118 ) ) {
F_30 ( V_109 L_5 ,
V_4 -> V_110 , V_126 , V_33 ) ;
goto V_132;
}
if ( ! V_125 &&
( ( V_33 & ( V_71 | V_70 | V_136 ) ) ||
F_35 ( V_46 , V_38 + V_47 *
( ( V_118 > 60 )
? ( V_118 - 60 )
: ( V_118 / 2 ) ) ) ) ) {
if ( F_36 ( ! F_29 ( V_4 ,
F_21 ( V_4 ) ) ) )
V_38 = V_46 ;
++ V_125 ;
}
F_11 ( 1 ) ;
}
if ( V_125 && V_137 )
V_137 = 1 ;
V_4 -> V_121 . V_138 = F_15 ;
V_4 -> V_121 . V_139 = F_5 ;
V_4 -> V_121 . V_140 = F_16 ;
V_4 -> V_121 . V_133 = F_7 ;
V_4 -> V_121 . V_141 = F_21 ;
V_4 -> V_121 . V_142 = F_29 ;
F_37 ( V_4 , V_120 ) ;
F_38 ( V_4 ) ;
F_4 ( V_4 , V_11 . V_22 , 0xffffffff ) ;
F_13 ( V_4 ) ;
if ( F_39 ( V_4 ) == NULL )
goto V_132;
if ( V_4 -> V_143 != V_144 )
goto V_132;
V_4 -> V_145 = V_146 && ! F_40 ( V_4 -> V_102 ) ;
if ( F_41 ( V_4 -> V_102 -> V_1 , V_4 -> V_121 . V_123 ,
V_147 | V_148 , L_6 , V_4 ) < 0 ) {
if ( V_4 -> V_145 )
F_42 ( V_4 -> V_102 ) ;
F_30 ( V_109 L_7 ,
V_110 , V_126 ) ;
goto V_132;
}
V_4 -> V_149 = F_28 ( V_4 -> V_102 , 2 ) ;
V_4 -> V_150 = V_4 -> V_97 . V_98 . V_101 ;
V_4 -> V_151 = V_103 ;
F_13 ( V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
V_132:
return - 1 ;
}
