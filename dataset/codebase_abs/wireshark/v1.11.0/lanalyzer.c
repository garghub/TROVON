int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
char V_6 [ 2 ] ;
char * V_7 ;
char V_8 [ 210 ] ;
T_4 V_9 , V_10 ;
T_4 V_11 , V_12 ;
T_5 V_13 , V_14 ;
T_4 V_15 ;
struct V_16 V_16 ;
T_6 * V_17 ;
V_18 = V_19 ;
V_4 = F_2 ( & V_5 , V_20 , V_1 -> V_21 ) ;
if ( V_4 != V_20 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_22 )
return - 1 ;
return 0 ;
}
V_11 = F_4 ( V_5 . V_11 ) ;
V_12 = F_4 ( V_5 . V_12 ) ;
if ( V_11 != V_23 && V_11 != V_24 ) {
return 0 ;
}
if ( V_12 < 2 ) {
return 0 ;
}
V_4 = F_2 ( & V_6 , sizeof V_6 , V_1 -> V_21 ) ;
if ( V_4 != sizeof V_6 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_22 )
return - 1 ;
return 0 ;
}
V_12 -= sizeof V_6 ;
if ( V_12 != 0 ) {
V_7 = ( char * ) F_5 ( V_12 + 1 ) ;
V_4 = F_2 ( V_7 , V_12 , V_1 -> V_21 ) ;
if ( V_4 != V_12 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_22 )
return - 1 ;
return 0 ;
}
V_7 [ V_12 ] = '\0' ;
V_1 -> V_25 . V_26 = V_7 ;
}
V_1 -> V_27 = V_28 ;
V_17 = ( T_6 * ) F_5 ( sizeof( T_6 ) ) ;
V_1 -> V_29 = ( void * ) V_17 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = 0 ;
V_1 -> V_35 = V_36 ;
while ( 1 ) {
V_18 = V_19 ;
V_4 = F_2 ( & V_5 , V_20 , V_1 -> V_21 ) ;
if ( V_4 != V_20 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return - 1 ;
}
V_11 = F_4 ( V_5 . V_11 ) ;
V_12 = F_4 ( V_5 . V_12 ) ;
switch ( V_11 ) {
case V_37 :
V_18 = V_19 ;
V_4 = F_2 ( V_8 , sizeof V_8 ,
V_1 -> V_21 ) ;
if ( V_4 != sizeof V_8 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return - 1 ;
}
V_13 = V_8 [ 0 ] ;
V_14 = V_8 [ 1 ] ;
V_15 = F_4 ( & V_8 [ 2 ] ) ;
V_16 . V_38 = V_15 - 1900 ;
V_16 . V_39 = V_14 - 1 ;
V_16 . V_40 = V_13 ;
V_16 . V_41 = 0 ;
V_16 . V_42 = 0 ;
V_16 . V_43 = 0 ;
V_16 . V_44 = - 1 ;
V_17 -> V_45 = mktime ( & V_16 ) ;
V_10 = F_4 ( & V_8 [ 30 ] ) ;
V_1 -> V_34 = V_10 ;
V_9 = F_4 ( & V_8 [ 188 ] ) ;
switch ( V_9 ) {
case V_46 :
V_1 -> V_47 = V_48 ;
break;
case V_49 :
V_1 -> V_47 = V_50 ;
break;
default:
* V_2 = V_51 ;
* V_3 = F_6 ( L_1 ,
V_9 ) ;
return - 1 ;
}
break;
case V_52 :
if ( F_7 ( V_1 -> V_21 , - V_20 , V_53 , V_2 ) == - 1 ) {
return - 1 ;
}
return 1 ;
default:
if ( F_7 ( V_1 -> V_21 , V_12 , V_53 , V_2 ) == - 1 ) {
return - 1 ;
}
break;
}
}
}
static T_7 F_8 ( T_1 * V_1 , T_8 V_21 ,
struct V_54 * V_55 , T_9 * V_56 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_57 [ 2 ] ;
char V_58 [ 2 ] ;
T_4 V_11 , V_12 ;
int V_59 ;
int V_60 ;
T_2 V_61 [ V_62 ] ;
T_6 * V_17 ;
T_4 V_63 , V_64 , V_65 , V_66 ;
T_10 V_67 ;
T_11 V_68 ;
V_18 = V_19 ;
V_4 = F_2 ( V_57 , 2 , V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_21 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_22 ;
}
return FALSE ;
}
V_4 = F_2 ( V_58 , 2 , V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
V_11 = F_4 ( V_57 ) ;
V_12 = F_4 ( V_58 ) ;
if ( V_11 != V_52 ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_2 ,
V_11 ) ;
return FALSE ;
}
if ( V_12 < V_62 ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_3 ,
V_12 ) ;
return FALSE ;
}
V_59 = V_12 - V_62 ;
V_18 = V_19 ;
V_4 = F_2 ( V_61 , V_62 , V_21 ) ;
if ( V_4 != V_62 ) {
* V_2 = F_3 ( V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
V_66 = F_4 ( & V_61 [ 4 ] ) ;
V_60 = F_4 ( & V_61 [ 6 ] ) ;
if ( V_60 > V_59 ) {
* V_2 = V_69 ;
* V_3 = F_9 ( L_4 ) ;
return FALSE ;
}
V_55 -> V_70 = V_71 | V_72 ;
V_63 = F_4 ( & V_61 [ 8 ] ) ;
V_64 = F_4 ( & V_61 [ 10 ] ) ;
V_65 = F_4 ( & V_61 [ 12 ] ) ;
V_67 = ( ( ( T_10 ) V_63 ) << 0 ) + ( ( ( T_10 ) V_64 ) << 16 ) +
( ( ( T_10 ) V_65 ) << 32 ) ;
V_68 = ( T_11 ) ( V_67 / 2000000 ) ;
V_17 = ( T_6 * ) V_1 -> V_29 ;
V_55 -> V_73 . V_74 = V_68 + V_17 -> V_45 ;
V_55 -> V_73 . V_75 = ( ( V_76 ) ( V_67 - V_68 * 2000000 ) ) * 500 ;
if ( V_66 - 4 >= V_60 ) {
V_66 -= 4 ;
}
V_55 -> V_77 = V_66 ;
V_55 -> V_78 = V_60 ;
switch ( V_1 -> V_47 ) {
case V_48 :
V_55 -> V_79 . V_80 . V_81 = 0 ;
break;
}
return F_10 ( V_21 , V_56 , V_60 , V_2 , V_3 ) ;
}
static T_7 V_31 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_12 * V_82 )
{
* V_82 = F_11 ( V_1 -> V_21 ) ;
return F_8 ( V_1 , V_1 -> V_21 , & V_1 -> V_55 ,
V_1 -> V_83 , V_2 , V_3 ) ;
}
static T_7 V_33 ( T_1 * V_1 , T_12 V_84 ,
struct V_54 * V_55 , T_9 * V_56 , int T_13 V_85 , int * V_2 ,
T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_86 , V_84 , V_87 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_86 , V_55 , V_56 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
return TRUE ;
}
static T_7 F_12 ( T_14 * V_88 , T_15 V_89 , int * V_2 )
{
T_15 V_90 ;
while ( V_89 ) {
V_90 = V_89 > 64 ? 64 : V_89 ;
if ( ! F_13 ( V_88 , V_91 , V_90 , V_2 ) )
return FALSE ;
V_89 -= V_90 ;
}
return TRUE ;
}
static T_7 F_14 ( T_14 * V_88 , const T_5 V_92 , int * V_2 )
{
return F_13 ( V_88 , & V_92 , 1 , V_2 ) ;
}
static T_7 F_15 ( T_14 * V_88 , const T_4 V_93 , int * V_2 )
{
return F_13 ( V_88 , & V_93 , 2 , V_2 ) ;
}
static T_7 F_16 ( T_14 * V_88 , const V_76 V_94 , int * V_2 )
{
return F_13 ( V_88 , & V_94 , 4 , V_2 ) ;
}
static void F_17 ( const struct V_95 * V_96 ,
const struct V_95 * V_97 ,
struct V_95 * V_98 )
{
T_16 V_99 = ( T_16 ) V_96 -> V_100 ;
V_98 -> V_101 = V_96 -> V_101 - V_97 -> V_101 ;
if ( V_97 -> V_100 > V_99 ) {
V_98 -> V_101 -- ;
V_99 += 1000000 ;
}
V_98 -> V_100 = V_99 - V_97 -> V_100 ;
}
static T_7 F_18 ( T_14 * V_88 ,
const struct V_54 * V_55 ,
const T_5 * V_102 , int * V_2 )
{
double V_103 ;
int V_104 ;
int V_77 ;
struct V_95 V_105 ;
T_17 * V_106 = ( T_17 * ) ( V_88 -> V_29 ) ;
struct V_95 V_107 ;
int V_108 = V_55 -> V_78 + V_109 + V_20 ;
if ( V_88 -> V_110 + V_108 > V_111 ) {
* V_2 = V_112 ;
return FALSE ;
}
V_77 = V_55 -> V_78 + ( V_55 -> V_78 ? V_109 : 0 ) ;
if ( ! F_15 ( V_88 , F_19 ( 0x1005 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_77 ) , V_2 ) )
return FALSE ;
V_105 . V_101 = ( long int ) V_55 -> V_73 . V_74 ;
V_105 . V_100 = V_55 -> V_73 . V_75 / 1000 ;
if ( ! V_106 -> V_113 ) {
V_106 -> V_45 = V_105 ;
V_106 -> V_114 = 0 ;
V_106 -> V_113 = TRUE ;
V_106 -> V_115 = V_88 -> V_115 ;
V_106 -> V_116 = 0 ;
}
F_17 ( & ( V_105 ) , & ( V_106 -> V_45 ) , & V_107 ) ;
V_103 = ( double ) V_107 . V_100 ;
V_103 += ( double ) V_107 . V_101 * 1000000 ;
V_103 *= 2 ;
if ( ! F_15 ( V_88 , F_19 ( 0x0001 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 0x0008 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_55 -> V_77 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_55 -> V_78 ) , V_2 ) )
return FALSE ;
for ( V_104 = 0 ; V_104 < 3 ; V_104 ++ ) {
if ( ! F_15 ( V_88 , F_19 ( ( T_4 ) V_103 ) , V_2 ) )
return FALSE ;
V_103 /= 0xffff ;
}
if ( ! F_16 ( V_88 , F_20 ( ++ V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_106 -> V_116 ) , V_2 ) )
return FALSE ;
V_106 -> V_116 = V_77 ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , V_102 , V_55 -> V_78 , V_2 ) )
return FALSE ;
V_88 -> V_110 += V_108 ;
return TRUE ;
}
int F_21 ( int V_115 )
{
if ( V_115 == V_117 )
return V_118 ;
if ( V_115 != V_48
&& V_115 != V_50 )
return V_51 ;
return 0 ;
}
T_7 F_22 ( T_14 * V_88 , int * V_2 )
{
int V_119 ;
void * V_120 ;
V_120 = F_5 ( sizeof( T_17 ) ) ;
if ( ! V_120 ) {
* V_2 = V_18 ;
return FALSE ;
}
( ( T_17 * ) V_120 ) -> V_113 = FALSE ;
V_88 -> V_29 = V_120 ;
V_88 -> V_121 = F_18 ;
V_88 -> V_122 = V_123 ;
V_119 = sizeof ( V_124 )
+ sizeof ( V_125 )
+ sizeof ( V_126 )
+ sizeof ( V_127 )
+ sizeof ( V_128 )
+ sizeof ( V_129 )
+ V_130
+ V_131
+ sizeof ( V_132 )
+ V_133 ;
if ( F_23 ( V_88 , V_119 , V_87 , V_2 ) == - 1 )
return FALSE ;
V_88 -> V_110 = V_119 ;
return TRUE ;
}
static T_7 F_24 ( T_14 * V_88 , int * V_2 )
{
T_17 * V_106 = ( T_17 * ) ( V_88 -> V_29 ) ;
T_4 V_9 = V_106 -> V_115 == V_50
? V_49
: V_46 ;
T_11 V_74 ;
struct V_16 * V_134 ;
V_74 = V_106 -> V_45 . V_101 ;
V_134 = localtime ( & V_74 ) ;
if ( V_134 == NULL )
return FALSE ;
if ( F_23 ( V_88 , 0 , V_87 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_88 , & V_124 ,
sizeof V_124 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_125 ,
sizeof V_125 , V_2 ) )
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
if ( ! F_15 ( V_88 , F_19 ( V_37 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_135 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_134 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_134 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_134 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_134 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 2 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_134 -> V_40 , V_2 ) )
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
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_9 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 20 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_136 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_131 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_132 ,
sizeof V_132 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_137 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_133 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_138 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , V_133 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_7 V_123 ( T_14 * V_88 , int * V_2 )
{
F_24 ( V_88 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
