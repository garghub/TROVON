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
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_11 = F_4 ( V_5 . V_11 ) ;
V_12 = F_4 ( V_5 . V_12 ) ;
if ( V_11 != V_22 && V_11 != V_23 ) {
return 0 ;
}
if ( V_12 < 2 ) {
* V_2 = V_24 ;
* V_3 = F_5 ( L_1 ,
V_12 ) ;
return - 1 ;
}
V_4 = F_2 ( & V_6 , sizeof V_6 , V_1 -> V_21 ) ;
if ( V_4 != sizeof V_6 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_12 -= sizeof V_6 ;
if ( V_12 != 0 ) {
V_7 = ( char * ) F_6 ( V_12 + 1 ) ;
V_4 = F_2 ( V_7 , V_12 , V_1 -> V_21 ) ;
if ( V_4 != V_12 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return - 1 ;
}
V_7 [ V_12 ] = '\0' ;
V_1 -> V_26 . V_27 = V_7 ;
}
V_1 -> V_28 = V_29 ;
V_17 = ( T_6 * ) F_6 ( sizeof( T_6 ) ) ;
V_1 -> V_30 = ( void * ) V_17 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = V_34 ;
V_1 -> V_35 = 0 ;
V_1 -> V_36 = V_37 ;
while ( 1 ) {
V_18 = V_19 ;
V_4 = F_2 ( & V_5 , V_20 , V_1 -> V_21 ) ;
if ( V_4 != V_20 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 != 0 ) {
F_7 ( V_1 -> V_30 ) ;
return - 1 ;
}
F_7 ( V_1 -> V_30 ) ;
return 0 ;
}
V_11 = F_4 ( V_5 . V_11 ) ;
V_12 = F_4 ( V_5 . V_12 ) ;
switch ( V_11 ) {
case V_38 :
V_18 = V_19 ;
V_4 = F_2 ( V_8 , sizeof V_8 ,
V_1 -> V_21 ) ;
if ( V_4 != sizeof V_8 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 != 0 ) {
F_7 ( V_1 -> V_30 ) ;
return - 1 ;
}
F_7 ( V_1 -> V_30 ) ;
return 0 ;
}
V_13 = V_8 [ 0 ] ;
V_14 = V_8 [ 1 ] ;
V_15 = F_4 ( & V_8 [ 2 ] ) ;
V_16 . V_39 = V_15 - 1900 ;
V_16 . V_40 = V_14 - 1 ;
V_16 . V_41 = V_13 ;
V_16 . V_42 = 0 ;
V_16 . V_43 = 0 ;
V_16 . V_44 = 0 ;
V_16 . V_45 = - 1 ;
V_17 -> V_46 = mktime ( & V_16 ) ;
V_10 = F_4 ( & V_8 [ 30 ] ) ;
V_1 -> V_35 = V_10 ;
V_9 = F_4 ( & V_8 [ 188 ] ) ;
switch ( V_9 ) {
case V_47 :
V_1 -> V_48 = V_49 ;
break;
case V_50 :
V_1 -> V_48 = V_51 ;
break;
default:
F_7 ( V_1 -> V_30 ) ;
* V_2 = V_52 ;
* V_3 = F_5 ( L_2 ,
V_9 ) ;
return - 1 ;
}
break;
case V_53 :
if ( F_8 ( V_1 -> V_21 , - V_20 , V_54 , V_2 ) == - 1 ) {
F_7 ( V_1 -> V_30 ) ;
return - 1 ;
}
return 1 ;
default:
if ( F_8 ( V_1 -> V_21 , V_12 , V_54 , V_2 ) == - 1 ) {
F_7 ( V_1 -> V_30 ) ;
return - 1 ;
}
break;
}
}
}
static T_7 V_32 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_55 )
{
int V_56 = 0 ;
int V_4 ;
char V_57 [ 2 ] ;
char V_58 [ 2 ] ;
T_4 V_11 , V_12 ;
T_2 V_59 [ V_60 ] ;
T_4 V_61 , V_62 , V_63 , V_64 ;
T_9 V_65 ;
T_10 V_66 ;
T_6 * V_17 ;
V_18 = V_19 ;
V_4 = F_2 ( V_57 , 2 , V_1 -> V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_25 ;
}
return FALSE ;
}
V_4 = F_2 ( V_58 , 2 , V_1 -> V_21 ) ;
if ( V_4 != 2 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return FALSE ;
}
V_11 = F_4 ( V_57 ) ;
V_12 = F_4 ( V_58 ) ;
if ( V_11 != V_53 ) {
* V_2 = V_24 ;
* V_3 = F_5 ( L_3 ,
V_11 ) ;
return FALSE ;
}
else {
if ( V_12 < V_60 ) {
* V_2 = V_24 ;
* V_3 = F_5 ( L_4 ,
V_12 ) ;
return FALSE ;
}
V_56 = V_12 - V_60 ;
}
V_18 = V_19 ;
V_4 = F_2 ( V_59 , V_60 , V_1 -> V_21 ) ;
if ( V_4 != V_60 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return FALSE ;
}
F_9 ( V_1 -> V_67 , V_56 ) ;
* V_55 = F_10 ( V_1 -> V_21 ) ;
V_18 = V_19 ;
V_4 = F_2 ( F_11 ( V_1 -> V_67 ) ,
V_56 , V_1 -> V_21 ) ;
if ( V_4 != V_56 ) {
* V_2 = F_3 ( V_1 -> V_21 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return FALSE ;
}
V_64 = F_4 ( & V_59 [ 4 ] ) ;
V_56 = F_4 ( & V_59 [ 6 ] ) ;
if ( V_56 > V_12 - V_60 ) {
* V_2 = V_24 ;
* V_3 = F_12 ( L_5 ) ;
return FALSE ;
}
V_1 -> V_68 . V_69 = V_70 | V_71 ;
V_61 = F_4 ( & V_59 [ 8 ] ) ;
V_62 = F_4 ( & V_59 [ 10 ] ) ;
V_63 = F_4 ( & V_59 [ 12 ] ) ;
V_65 = ( ( ( T_9 ) V_61 ) << 0 ) + ( ( ( T_9 ) V_62 ) << 16 ) +
( ( ( T_9 ) V_63 ) << 32 ) ;
V_66 = ( T_10 ) ( V_65 / 2000000 ) ;
V_17 = ( T_6 * ) V_1 -> V_30 ;
V_1 -> V_68 . V_72 . V_73 = V_66 + V_17 -> V_46 ;
V_1 -> V_68 . V_72 . V_74 = ( ( V_75 ) ( V_65 - V_66 * 2000000 ) ) * 500 ;
if ( V_64 - 4 >= V_56 ) {
V_64 -= 4 ;
}
V_1 -> V_68 . V_76 = V_64 ;
V_1 -> V_68 . V_77 = V_56 ;
switch ( V_1 -> V_48 ) {
case V_49 :
V_1 -> V_78 . V_79 . V_80 = 0 ;
break;
}
return TRUE ;
}
static T_7 V_34 ( T_1 * V_1 , T_8 V_81 ,
union V_82 * V_78 , T_5 * V_83 , int V_84 ,
int * V_2 , T_2 * * V_3 )
{
int V_4 ;
if ( F_8 ( V_1 -> V_85 , V_81 , V_86 , V_2 ) == - 1 )
return FALSE ;
V_4 = F_2 ( V_83 , V_84 , V_1 -> V_85 ) ;
if ( V_4 != V_84 ) {
* V_2 = F_3 ( V_1 -> V_85 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_25 ;
return FALSE ;
}
switch ( V_1 -> V_48 ) {
case V_49 :
V_78 -> V_79 . V_80 = 0 ;
break;
}
return TRUE ;
}
static T_7 F_13 ( T_11 * V_87 , T_12 V_88 , int * V_2 )
{
static const T_5 V_89 [ 64 ] ;
T_12 V_90 ;
while ( V_88 ) {
V_90 = V_88 > 64 ? 64 : V_88 ;
if ( ! F_14 ( V_87 , V_89 , V_90 , V_2 ) )
return FALSE ;
V_88 -= V_90 ;
}
return TRUE ;
}
static T_7 F_15 ( T_11 * V_87 , const T_5 V_91 , int * V_2 )
{
return F_14 ( V_87 , & V_91 , 1 , V_2 ) ;
}
static T_7 F_16 ( T_11 * V_87 , const T_4 V_92 , int * V_2 )
{
return F_14 ( V_87 , & V_92 , 2 , V_2 ) ;
}
static T_7 F_17 ( T_11 * V_87 , const V_75 V_93 , int * V_2 )
{
return F_14 ( V_87 , & V_93 , 4 , V_2 ) ;
}
static void F_18 ( const struct V_94 * V_95 ,
const struct V_94 * V_96 ,
struct V_94 * V_97 )
{
T_13 V_98 = V_95 -> V_99 ;
V_97 -> V_100 = V_95 -> V_100 - V_96 -> V_100 ;
if ( V_96 -> V_99 > V_98 ) {
V_97 -> V_100 -- ;
V_98 += 1000000 ;
}
V_97 -> V_99 = V_98 - V_96 -> V_99 ;
}
static T_7 F_19 ( T_11 * V_87 ,
const struct V_101 * V_68 ,
const union V_82 * V_78 V_102 ,
const T_5 * V_83 , int * V_2 )
{
double V_103 ;
int V_104 ;
int V_76 ;
struct V_94 V_105 ;
T_14 * V_106 = ( T_14 * ) ( V_87 -> V_30 ) ;
struct V_94 V_107 ;
int V_108 = V_68 -> V_77 + V_109 + V_20 ;
if ( V_87 -> V_110 + V_108 > V_111 ) {
* V_2 = V_112 ;
return FALSE ;
}
V_76 = V_68 -> V_77 + ( V_68 -> V_77 ? V_109 : 0 ) ;
if ( ! F_16 ( V_87 , F_20 ( 0x1005 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_76 ) , V_2 ) )
return FALSE ;
V_105 . V_100 = ( long int ) V_68 -> V_72 . V_73 ;
V_105 . V_99 = V_68 -> V_72 . V_74 / 1000 ;
if ( ! V_106 -> V_113 ) {
V_106 -> V_46 = V_105 ;
V_106 -> V_114 = 0 ;
V_106 -> V_113 = TRUE ;
V_106 -> V_115 = V_87 -> V_115 ;
V_106 -> V_116 = 0 ;
}
F_18 ( & ( V_105 ) , & ( V_106 -> V_46 ) , & V_107 ) ;
V_103 = ( double ) V_107 . V_99 ;
V_103 += ( double ) V_107 . V_100 * 1000000 ;
V_103 *= 2 ;
if ( ! F_16 ( V_87 , F_20 ( 0x0001 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( 0x0008 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_68 -> V_76 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_68 -> V_77 ) , V_2 ) )
return FALSE ;
for ( V_104 = 0 ; V_104 < 3 ; V_104 ++ ) {
if ( ! F_16 ( V_87 , F_20 ( ( T_4 ) V_103 ) , V_2 ) )
return FALSE ;
V_103 /= 0xffff ;
}
if ( ! F_17 ( V_87 , F_21 ( ++ V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_106 -> V_116 ) , V_2 ) )
return FALSE ;
V_106 -> V_116 = V_76 ;
if ( ! F_13 ( V_87 , 12 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , V_83 , V_68 -> V_77 , V_2 ) )
return FALSE ;
V_87 -> V_110 += V_108 ;
return TRUE ;
}
int F_22 ( int V_115 )
{
if ( V_115 == V_117 )
return V_118 ;
if ( V_115 != V_49
&& V_115 != V_51 )
return V_52 ;
return 0 ;
}
T_7 F_23 ( T_11 * V_87 , int * V_2 )
{
int V_119 ;
void * V_120 ;
V_120 = F_6 ( sizeof( T_14 ) ) ;
if ( ! V_120 ) {
* V_2 = V_18 ;
return FALSE ;
}
( ( T_14 * ) V_120 ) -> V_113 = FALSE ;
V_87 -> V_30 = V_120 ;
V_87 -> V_121 = F_19 ;
V_87 -> V_122 = V_123 ;
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
if ( fseek ( V_87 -> V_21 , V_119 , V_86 ) == - 1 ) {
* V_2 = V_18 ;
return FALSE ;
}
V_87 -> V_110 = V_119 ;
return TRUE ;
}
static T_7 F_24 ( T_11 * V_87 , int * V_2 )
{
T_14 * V_106 = ( T_14 * ) ( V_87 -> V_30 ) ;
T_4 V_9 = V_106 -> V_115 == V_51
? V_50
: V_47 ;
T_10 V_73 ;
struct V_16 * V_134 ;
V_73 = V_106 -> V_46 . V_100 ;
V_134 = localtime ( & V_73 ) ;
if ( V_134 == NULL )
return FALSE ;
fseek ( V_87 -> V_21 , 0 , V_86 ) ;
if ( ! F_14 ( V_87 , & V_124 ,
sizeof V_124 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_125 ,
sizeof V_125 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_126 ,
sizeof V_126 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_127 ,
sizeof V_127 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_128 ,
sizeof V_128 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_129 ,
sizeof V_129 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_38 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_135 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) ( V_134 -> V_40 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_134 -> V_39 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) ( V_134 -> V_40 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_134 -> V_39 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_44 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_44 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_87 , ( T_5 ) V_134 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 2 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 6 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( 0 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( 1514 ) , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_87 , F_21 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 12 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_87 , F_21 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_9 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , 20 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_136 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_131 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( 1 ) , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_87 , F_21 ( V_106 -> V_114 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_87 , & V_132 ,
sizeof V_132 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_137 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_133 - 4 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_87 , F_20 ( V_138 ) , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_87 , V_133 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_7 V_123 ( T_11 * V_87 , int * V_2 )
{
F_24 ( V_87 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
