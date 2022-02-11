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
static T_7 V_31 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_54 )
{
int V_55 = 0 ;
int V_4 ;
char V_56 [ 2 ] ;
char V_57 [ 2 ] ;
T_4 V_11 , V_12 ;
T_2 V_58 [ V_59 ] ;
T_4 V_60 , V_61 , V_62 , V_63 ;
T_9 V_64 ;
T_10 V_65 ;
T_6 * V_17 ;
V_18 = V_19 ;
V_4 = F_2 ( V_56 , 2 , V_1 -> V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_22 ;
}
return FALSE ;
}
V_4 = F_2 ( V_57 , 2 , V_1 -> V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
V_11 = F_4 ( V_56 ) ;
V_12 = F_4 ( V_57 ) ;
if ( V_11 != V_52 ) {
* V_2 = V_66 ;
* V_3 = F_6 ( L_2 ,
V_11 ) ;
return FALSE ;
}
else {
if ( V_12 < V_59 ) {
* V_2 = V_66 ;
* V_3 = F_6 ( L_3 ,
V_12 ) ;
return FALSE ;
}
V_55 = V_12 - V_59 ;
}
V_18 = V_19 ;
V_4 = F_2 ( V_58 , V_59 , V_1 -> V_21 ) ;
if ( V_4 != V_59 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
F_8 ( V_1 -> V_67 , V_55 ) ;
* V_54 = F_9 ( V_1 -> V_21 ) ;
V_18 = V_19 ;
V_4 = F_2 ( F_10 ( V_1 -> V_67 ) ,
V_55 , V_1 -> V_21 ) ;
if ( V_4 != V_55 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
V_63 = F_4 ( & V_58 [ 4 ] ) ;
V_55 = F_4 ( & V_58 [ 6 ] ) ;
if ( V_55 > V_12 - V_59 ) {
* V_2 = V_66 ;
* V_3 = F_11 ( L_4 ) ;
return FALSE ;
}
V_1 -> V_68 . V_69 = V_70 | V_71 ;
V_60 = F_4 ( & V_58 [ 8 ] ) ;
V_61 = F_4 ( & V_58 [ 10 ] ) ;
V_62 = F_4 ( & V_58 [ 12 ] ) ;
V_64 = ( ( ( T_9 ) V_60 ) << 0 ) + ( ( ( T_9 ) V_61 ) << 16 ) +
( ( ( T_9 ) V_62 ) << 32 ) ;
V_65 = ( T_10 ) ( V_64 / 2000000 ) ;
V_17 = ( T_6 * ) V_1 -> V_29 ;
V_1 -> V_68 . V_72 . V_73 = V_65 + V_17 -> V_45 ;
V_1 -> V_68 . V_72 . V_74 = ( ( V_75 ) ( V_64 - V_65 * 2000000 ) ) * 500 ;
if ( V_63 - 4 >= V_55 ) {
V_63 -= 4 ;
}
V_1 -> V_68 . V_76 = V_63 ;
V_1 -> V_68 . V_77 = V_55 ;
switch ( V_1 -> V_47 ) {
case V_48 :
V_1 -> V_68 . V_78 . V_79 . V_80 = 0 ;
break;
}
return TRUE ;
}
static T_7 V_33 ( T_1 * V_1 , T_8 V_81 ,
struct V_82 * V_68 , T_5 * V_83 , int V_84 ,
int * V_2 , T_2 * * V_3 )
{
union V_85 * V_78 = & V_68 -> V_78 ;
int V_4 ;
if ( F_7 ( V_1 -> V_86 , V_81 , V_87 , V_2 ) == - 1 )
return FALSE ;
V_4 = F_2 ( V_83 , V_84 , V_1 -> V_86 ) ;
if ( V_4 != V_84 ) {
* V_2 = F_3 ( V_1 -> V_86 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_22 ;
return FALSE ;
}
switch ( V_1 -> V_47 ) {
case V_48 :
V_78 -> V_79 . V_80 = 0 ;
break;
}
return TRUE ;
}
static T_7 F_12 ( T_11 * V_88 , T_12 V_89 , int * V_2 )
{
T_12 V_90 ;
while ( V_89 ) {
V_90 = V_89 > 64 ? 64 : V_89 ;
if ( ! F_13 ( V_88 , V_91 , V_90 , V_2 ) )
return FALSE ;
V_89 -= V_90 ;
}
return TRUE ;
}
static T_7 F_14 ( T_11 * V_88 , const T_5 V_92 , int * V_2 )
{
return F_13 ( V_88 , & V_92 , 1 , V_2 ) ;
}
static T_7 F_15 ( T_11 * V_88 , const T_4 V_93 , int * V_2 )
{
return F_13 ( V_88 , & V_93 , 2 , V_2 ) ;
}
static T_7 F_16 ( T_11 * V_88 , const V_75 V_94 , int * V_2 )
{
return F_13 ( V_88 , & V_94 , 4 , V_2 ) ;
}
static void F_17 ( const struct V_95 * V_96 ,
const struct V_95 * V_97 ,
struct V_95 * V_98 )
{
T_13 V_99 = V_96 -> V_100 ;
V_98 -> V_101 = V_96 -> V_101 - V_97 -> V_101 ;
if ( V_97 -> V_100 > V_99 ) {
V_98 -> V_101 -- ;
V_99 += 1000000 ;
}
V_98 -> V_100 = V_99 - V_97 -> V_100 ;
}
static T_7 F_18 ( T_11 * V_88 ,
const struct V_82 * V_68 ,
const T_5 * V_83 , int * V_2 )
{
double V_102 ;
int V_103 ;
int V_76 ;
struct V_95 V_104 ;
T_14 * V_105 = ( T_14 * ) ( V_88 -> V_29 ) ;
struct V_95 V_106 ;
int V_107 = V_68 -> V_77 + V_108 + V_20 ;
if ( V_88 -> V_109 + V_107 > V_110 ) {
* V_2 = V_111 ;
return FALSE ;
}
V_76 = V_68 -> V_77 + ( V_68 -> V_77 ? V_108 : 0 ) ;
if ( ! F_15 ( V_88 , F_19 ( 0x1005 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_76 ) , V_2 ) )
return FALSE ;
V_104 . V_101 = ( long int ) V_68 -> V_72 . V_73 ;
V_104 . V_100 = V_68 -> V_72 . V_74 / 1000 ;
if ( ! V_105 -> V_112 ) {
V_105 -> V_45 = V_104 ;
V_105 -> V_113 = 0 ;
V_105 -> V_112 = TRUE ;
V_105 -> V_114 = V_88 -> V_114 ;
V_105 -> V_115 = 0 ;
}
F_17 ( & ( V_104 ) , & ( V_105 -> V_45 ) , & V_106 ) ;
V_102 = ( double ) V_106 . V_100 ;
V_102 += ( double ) V_106 . V_101 * 1000000 ;
V_102 *= 2 ;
if ( ! F_15 ( V_88 , F_19 ( 0x0001 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 0x0008 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_68 -> V_76 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_68 -> V_77 ) , V_2 ) )
return FALSE ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
if ( ! F_15 ( V_88 , F_19 ( ( T_4 ) V_102 ) , V_2 ) )
return FALSE ;
V_102 /= 0xffff ;
}
if ( ! F_16 ( V_88 , F_20 ( ++ V_105 -> V_113 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_105 -> V_115 ) , V_2 ) )
return FALSE ;
V_105 -> V_115 = V_76 ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , V_83 , V_68 -> V_77 , V_2 ) )
return FALSE ;
V_88 -> V_109 += V_107 ;
return TRUE ;
}
int F_21 ( int V_114 )
{
if ( V_114 == V_116 )
return V_117 ;
if ( V_114 != V_48
&& V_114 != V_50 )
return V_51 ;
return 0 ;
}
T_7 F_22 ( T_11 * V_88 , int * V_2 )
{
int V_118 ;
void * V_119 ;
V_119 = F_5 ( sizeof( T_14 ) ) ;
if ( ! V_119 ) {
* V_2 = V_18 ;
return FALSE ;
}
( ( T_14 * ) V_119 ) -> V_112 = FALSE ;
V_88 -> V_29 = V_119 ;
V_88 -> V_120 = F_18 ;
V_88 -> V_121 = V_122 ;
V_118 = sizeof ( V_123 )
+ sizeof ( V_124 )
+ sizeof ( V_125 )
+ sizeof ( V_126 )
+ sizeof ( V_127 )
+ sizeof ( V_128 )
+ V_129
+ V_130
+ sizeof ( V_131 )
+ V_132 ;
if ( F_23 ( V_88 , V_118 , V_87 , V_2 ) == - 1 )
return FALSE ;
V_88 -> V_109 = V_118 ;
return TRUE ;
}
static T_7 F_24 ( T_11 * V_88 , int * V_2 )
{
T_14 * V_105 = ( T_14 * ) ( V_88 -> V_29 ) ;
T_4 V_9 = V_105 -> V_114 == V_50
? V_49
: V_46 ;
T_10 V_73 ;
struct V_16 * V_133 ;
V_73 = V_105 -> V_45 . V_101 ;
V_133 = localtime ( & V_73 ) ;
if ( V_133 == NULL )
return FALSE ;
if ( F_23 ( V_88 , 0 , V_87 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_88 , & V_123 ,
sizeof V_123 , V_2 ) )
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
if ( ! F_15 ( V_88 , F_19 ( V_37 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_134 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_133 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_133 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) ( V_133 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_133 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 2 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_88 , ( T_5 ) V_133 -> V_40 , V_2 ) )
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
if ( ! F_16 ( V_88 , F_20 ( V_105 -> V_113 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 12 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_105 -> V_113 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_9 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , 20 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_135 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_130 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_88 , F_20 ( V_105 -> V_113 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_88 , & V_131 ,
sizeof V_131 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_136 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_132 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_88 , F_19 ( V_137 ) , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_88 , V_132 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_7 V_122 ( T_11 * V_88 , int * V_2 )
{
F_24 ( V_88 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
