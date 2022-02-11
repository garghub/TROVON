int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
char V_5 [ 2 ] ;
char * V_6 ;
char V_7 [ 210 ] ;
T_4 V_8 , V_9 ;
T_4 V_10 , V_11 ;
T_5 V_12 , V_13 ;
T_4 V_14 ;
struct V_15 V_15 ;
T_6 * V_16 ;
V_17 = V_18 ;
if ( ! F_2 ( V_1 -> V_19 , & V_4 , V_20 ,
V_2 , V_3 ) ) {
if ( * V_2 != V_21 )
return - 1 ;
return 0 ;
}
V_10 = F_3 ( V_4 . V_10 ) ;
V_11 = F_3 ( V_4 . V_11 ) ;
if ( V_10 != V_22 && V_10 != V_23 ) {
return 0 ;
}
if ( V_11 < 2 ) {
return 0 ;
}
if ( ! F_2 ( V_1 -> V_19 , & V_5 , sizeof V_5 ,
V_2 , V_3 ) ) {
if ( * V_2 == V_21 ) {
return 0 ;
}
return - 1 ;
}
V_11 -= sizeof V_5 ;
if ( V_11 != 0 ) {
V_6 = ( char * ) F_4 ( V_11 + 1 ) ;
if ( ! F_2 ( V_1 -> V_19 , V_6 , V_11 ,
V_2 , V_3 ) ) {
if ( * V_2 == V_21 ) {
return 0 ;
}
return - 1 ;
}
V_6 [ V_11 ] = '\0' ;
V_1 -> V_24 . V_25 = V_6 ;
}
V_1 -> V_26 = V_27 ;
V_16 = ( T_6 * ) F_4 ( sizeof( T_6 ) ) ;
V_1 -> V_28 = ( void * ) V_16 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = V_35 ;
while ( 1 ) {
V_17 = V_18 ;
if ( ! F_5 ( V_1 -> V_19 , & V_4 ,
V_20 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
return 1 ;
}
return - 1 ;
}
V_10 = F_3 ( V_4 . V_10 ) ;
V_11 = F_3 ( V_4 . V_11 ) ;
switch ( V_10 ) {
case V_36 :
V_17 = V_18 ;
if ( ! F_2 ( V_1 -> V_19 , V_7 ,
sizeof V_7 , V_2 , V_3 ) )
return - 1 ;
V_12 = V_7 [ 0 ] ;
V_13 = V_7 [ 1 ] ;
V_14 = F_3 ( & V_7 [ 2 ] ) ;
V_15 . V_37 = V_14 - 1900 ;
V_15 . V_38 = V_13 - 1 ;
V_15 . V_39 = V_12 ;
V_15 . V_40 = 0 ;
V_15 . V_41 = 0 ;
V_15 . V_42 = 0 ;
V_15 . V_43 = - 1 ;
V_16 -> V_44 = mktime ( & V_15 ) ;
V_9 = F_3 ( & V_7 [ 30 ] ) ;
V_1 -> V_33 = V_9 ;
V_8 = F_3 ( & V_7 [ 188 ] ) ;
switch ( V_8 ) {
case V_45 :
V_1 -> V_46 = V_47 ;
break;
case V_48 :
V_1 -> V_46 = V_49 ;
break;
default:
* V_2 = V_50 ;
* V_3 = F_6 ( L_1 ,
V_8 ) ;
return - 1 ;
}
break;
case V_51 :
if ( F_7 ( V_1 -> V_19 , - V_20 , V_52 , V_2 ) == - 1 ) {
return - 1 ;
}
return 1 ;
default:
if ( F_7 ( V_1 -> V_19 , V_11 , V_52 , V_2 ) == - 1 ) {
return - 1 ;
}
break;
}
}
}
static T_7 F_8 ( T_1 * V_1 , T_8 V_19 ,
struct V_53 * V_54 , T_9 * V_55 , int * V_2 , T_2 * * V_3 )
{
char V_56 [ 2 ] ;
char V_57 [ 2 ] ;
T_4 V_10 , V_11 ;
int V_58 ;
int V_59 ;
T_2 V_60 [ V_61 ] ;
T_6 * V_16 ;
T_4 V_62 , V_63 , V_64 , V_65 ;
T_10 V_66 ;
T_11 V_67 ;
V_17 = V_18 ;
if ( ! F_5 ( V_19 , V_56 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_2 ( V_19 , V_57 , 2 , V_2 , V_3 ) )
return FALSE ;
V_10 = F_3 ( V_56 ) ;
V_11 = F_3 ( V_57 ) ;
if ( V_10 != V_51 ) {
* V_2 = V_68 ;
* V_3 = F_6 ( L_2 ,
V_10 ) ;
return FALSE ;
}
if ( V_11 < V_61 ) {
* V_2 = V_68 ;
* V_3 = F_6 ( L_3 ,
V_11 ) ;
return FALSE ;
}
V_58 = V_11 - V_61 ;
V_17 = V_18 ;
if ( ! F_2 ( V_19 , V_60 , V_61 , V_2 , V_3 ) )
return FALSE ;
V_65 = F_3 ( & V_60 [ 4 ] ) ;
V_59 = F_3 ( & V_60 [ 6 ] ) ;
if ( V_59 > V_58 ) {
* V_2 = V_68 ;
* V_3 = F_9 ( L_4 ) ;
return FALSE ;
}
V_54 -> V_69 = V_70 ;
V_54 -> V_71 = V_72 | V_73 ;
V_62 = F_3 ( & V_60 [ 8 ] ) ;
V_63 = F_3 ( & V_60 [ 10 ] ) ;
V_64 = F_3 ( & V_60 [ 12 ] ) ;
V_66 = ( ( ( T_10 ) V_62 ) << 0 ) + ( ( ( T_10 ) V_63 ) << 16 ) +
( ( ( T_10 ) V_64 ) << 32 ) ;
V_67 = ( T_11 ) ( V_66 / 2000000 ) ;
V_16 = ( T_6 * ) V_1 -> V_28 ;
V_54 -> V_74 . V_75 = V_67 + V_16 -> V_44 ;
V_54 -> V_74 . V_76 = ( ( V_77 ) ( V_66 - V_67 * 2000000 ) ) * 500 ;
if ( V_65 - 4 >= V_59 ) {
V_65 -= 4 ;
}
V_54 -> V_78 = V_65 ;
V_54 -> V_79 = V_59 ;
switch ( V_1 -> V_46 ) {
case V_47 :
V_54 -> V_80 . V_81 . V_82 = 0 ;
break;
}
return F_10 ( V_19 , V_55 , V_59 , V_2 , V_3 ) ;
}
static T_7 V_30 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_12 * V_83 )
{
* V_83 = F_11 ( V_1 -> V_19 ) ;
return F_8 ( V_1 , V_1 -> V_19 , & V_1 -> V_54 ,
V_1 -> V_84 , V_2 , V_3 ) ;
}
static T_7 V_32 ( T_1 * V_1 , T_12 V_85 ,
struct V_53 * V_54 , T_9 * V_55 , int * V_2 , T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_86 , V_85 , V_87 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_86 , V_54 , V_55 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_21 ;
return FALSE ;
}
return TRUE ;
}
static T_7 F_12 ( T_13 * V_88 , T_14 V_89 , int * V_2 )
{
T_14 V_90 ;
while ( V_89 ) {
V_90 = V_89 > 64 ? 64 : V_89 ;
if ( ! F_13 ( V_88 , V_91 , V_90 , V_2 ) )
return FALSE ;
V_89 -= V_90 ;
}
return TRUE ;
}
static T_7 F_14 ( T_13 * V_88 , const T_5 V_92 , int * V_2 )
{
return F_13 ( V_88 , & V_92 , 1 , V_2 ) ;
}
static T_7 F_15 ( T_13 * V_88 , const T_4 V_93 , int * V_2 )
{
return F_13 ( V_88 , & V_93 , 2 , V_2 ) ;
}
static T_7 F_16 ( T_13 * V_88 , const V_77 V_94 , int * V_2 )
{
return F_13 ( V_88 , & V_94 , 4 , V_2 ) ;
}
static void F_17 ( const struct V_95 * V_96 ,
const struct V_95 * V_97 ,
struct V_95 * V_98 )
{
T_15 V_99 = ( T_15 ) V_96 -> V_100 ;
V_98 -> V_101 = V_96 -> V_101 - V_97 -> V_101 ;
if ( V_97 -> V_100 > V_99 ) {
V_98 -> V_101 -- ;
V_99 += 1000000 ;
}
V_98 -> V_100 = V_99 - V_97 -> V_100 ;
}
static T_7 F_18 ( T_13 * V_88 ,
const struct V_53 * V_54 ,
const T_5 * V_102 , int * V_2 )
{
double V_103 ;
int V_104 ;
int V_78 ;
struct V_95 V_105 ;
T_16 * V_106 = ( T_16 * ) ( V_88 -> V_28 ) ;
struct V_95 V_107 ;
int V_108 = V_54 -> V_79 + V_109 + V_20 ;
if ( V_54 -> V_69 != V_70 ) {
* V_2 = V_110 ;
return FALSE ;
}
if ( V_88 -> V_111 + V_108 > V_112 ) {
* V_2 = V_113 ;
return FALSE ;
}
V_78 = V_54 -> V_79 + ( V_54 -> V_79 ? V_109 : 0 ) ;
if ( V_78 > 65535 ) {
* V_2 = V_114 ;
return FALSE ;
}
if ( ! F_15 ( V_88 , F_19 ( 0x1005 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_78 ) , V_2 ) )
return FALSE ;
V_105 . V_101 = ( long int ) V_54 -> V_74 . V_75 ;
V_105 . V_100 = V_54 -> V_74 . V_76 / 1000 ;
if ( ! V_106 -> V_115 ) {
V_106 -> V_44 = V_105 ;
V_106 -> V_116 = 0 ;
V_106 -> V_115 = TRUE ;
V_106 -> V_117 = V_88 -> V_117 ;
V_106 -> V_118 = 0 ;
}
F_17 ( & ( V_105 ) , & ( V_106 -> V_44 ) , & V_107 ) ;
V_103 = ( double ) V_107 . V_100 ;
V_103 += ( double ) V_107 . V_101 * 1000000 ;
V_103 *= 2 ;
if ( ! F_15 ( V_88 , F_19 ( 0x0001 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 0x0008 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_54 -> V_78 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_54 -> V_79 ) , V_2 ) )
return FALSE ;
for ( V_104 = 0 ; V_104 < 3 ; V_104 ++ ) {
if ( ! F_15 ( V_88 , F_19 ( ( T_4 ) V_103 ) , V_2 ) )
return FALSE ;
V_103 /= 0xffff ;
}
if ( ! F_16 ( V_88 , F_20 ( ++ V_106 -> V_116 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_106 -> V_118 ) , V_2 ) )
return FALSE ;
V_106 -> V_118 = V_78 ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , V_102 , V_54 -> V_79 , V_2 ) )
return FALSE ;
V_88 -> V_111 += V_108 ;
return TRUE ;
}
int F_21 ( int V_117 )
{
if ( V_117 == V_119 )
return V_120 ;
if ( V_117 != V_47
&& V_117 != V_49 )
return V_50 ;
return 0 ;
}
T_7 F_22 ( T_13 * V_88 , int * V_2 )
{
int V_121 ;
void * V_122 ;
V_122 = F_4 ( sizeof( T_16 ) ) ;
if ( ! V_122 ) {
* V_2 = V_17 ;
return FALSE ;
}
( ( T_16 * ) V_122 ) -> V_115 = FALSE ;
V_88 -> V_28 = V_122 ;
V_88 -> V_123 = F_18 ;
V_88 -> V_124 = V_125 ;
V_121 = sizeof ( V_126 )
+ sizeof ( V_127 )
+ sizeof ( V_128 )
+ sizeof ( V_129 )
+ sizeof ( V_130 )
+ sizeof ( V_131 )
+ V_132
+ V_133
+ sizeof ( V_134 )
+ V_135 ;
if ( F_23 ( V_88 , V_121 , V_87 , V_2 ) == - 1 )
return FALSE ;
V_88 -> V_111 = V_121 ;
return TRUE ;
}
static T_7 F_24 ( T_13 * V_88 , int * V_2 )
{
T_16 * V_106 = ( T_16 * ) ( V_88 -> V_28 ) ;
T_4 V_8 = V_106 -> V_117 == V_49
? V_48
: V_45 ;
T_11 V_75 ;
struct V_15 * V_136 ;
V_75 = V_106 -> V_44 . V_101 ;
V_136 = localtime ( & V_75 ) ;
if ( V_136 == NULL )
return FALSE ;
if ( F_23 ( V_88 , 0 , V_87 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_88 , & V_126 ,
sizeof V_126 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_127 ,
sizeof V_127 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_128 ,
sizeof V_128 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_129 ,
sizeof V_129 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_130 ,
sizeof V_130 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_131 ,
sizeof V_131 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_36 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_137 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_39 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_136 -> V_38 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_136 -> V_37 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_39 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_136 -> V_38 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_136 -> V_37 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_39 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 2 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_136 -> V_39 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 2 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 6 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 0 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 1514 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_116 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_116 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_8 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 20 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_138 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_133 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_116 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_134 ,
sizeof V_134 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_139 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_135 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_140 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , V_135 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_7 V_125 ( T_13 * V_88 , int * V_2 )
{
F_24 ( V_88 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
