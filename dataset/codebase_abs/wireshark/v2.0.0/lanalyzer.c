T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
char V_5 [ 2 ] ;
char * V_6 ;
char V_7 [ 210 ] ;
T_5 V_8 , V_9 ;
T_5 V_10 , V_11 ;
T_6 V_12 , V_13 ;
T_5 V_14 ;
struct V_15 V_15 ;
T_7 * V_16 ;
if ( ! F_2 ( V_1 -> V_17 , & V_4 , V_18 ,
V_2 , V_3 ) ) {
if ( * V_2 != V_19 )
return V_20 ;
return V_21 ;
}
V_10 = F_3 ( V_4 . V_10 ) ;
V_11 = F_3 ( V_4 . V_11 ) ;
if ( V_10 != V_22 && V_10 != V_23 ) {
return V_21 ;
}
if ( V_11 < 2 ) {
return V_21 ;
}
if ( ! F_2 ( V_1 -> V_17 , & V_5 , sizeof V_5 ,
V_2 , V_3 ) ) {
if ( * V_2 != V_19 )
return V_20 ;
return V_21 ;
}
V_11 -= sizeof V_5 ;
if ( V_11 != 0 ) {
V_6 = ( char * ) F_4 ( V_11 + 1 ) ;
if ( ! F_2 ( V_1 -> V_17 , V_6 , V_11 ,
V_2 , V_3 ) ) {
if ( * V_2 != V_19 )
return V_20 ;
return V_21 ;
}
V_6 [ V_11 ] = '\0' ;
V_1 -> V_24 . V_25 = V_6 ;
}
V_1 -> V_26 = V_27 ;
V_16 = ( T_7 * ) F_4 ( sizeof( T_7 ) ) ;
V_1 -> V_28 = ( void * ) V_16 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = V_35 ;
while ( 1 ) {
if ( ! F_5 ( V_1 -> V_17 , & V_4 ,
V_18 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
return V_36 ;
}
return V_20 ;
}
V_10 = F_3 ( V_4 . V_10 ) ;
V_11 = F_3 ( V_4 . V_11 ) ;
switch ( V_10 ) {
case V_37 :
if ( ! F_2 ( V_1 -> V_17 , V_7 ,
sizeof V_7 , V_2 , V_3 ) )
return V_20 ;
V_12 = V_7 [ 0 ] ;
V_13 = V_7 [ 1 ] ;
V_14 = F_3 ( & V_7 [ 2 ] ) ;
V_15 . V_38 = V_14 - 1900 ;
V_15 . V_39 = V_13 - 1 ;
V_15 . V_40 = V_12 ;
V_15 . V_41 = 0 ;
V_15 . V_42 = 0 ;
V_15 . V_43 = 0 ;
V_15 . V_44 = - 1 ;
V_16 -> V_45 = mktime ( & V_15 ) ;
V_9 = F_3 ( & V_7 [ 30 ] ) ;
V_1 -> V_33 = V_9 ;
V_8 = F_3 ( & V_7 [ 188 ] ) ;
switch ( V_8 ) {
case V_46 :
V_1 -> V_47 = V_48 ;
break;
case V_49 :
V_1 -> V_47 = V_50 ;
break;
default:
* V_2 = V_51 ;
* V_3 = F_6 ( L_1 ,
V_8 ) ;
return V_20 ;
}
break;
case V_52 :
if ( F_7 ( V_1 -> V_17 , - V_18 , V_53 , V_2 ) == - 1 ) {
return V_20 ;
}
return V_36 ;
default:
if ( F_7 ( V_1 -> V_17 , V_11 , V_53 , V_2 ) == - 1 ) {
return V_20 ;
}
break;
}
}
}
static T_8 F_8 ( T_2 * V_1 , T_9 V_17 ,
struct V_54 * V_55 , T_10 * V_56 , int * V_2 , T_3 * * V_3 )
{
char V_57 [ 2 ] ;
char V_58 [ 2 ] ;
T_5 V_10 , V_11 ;
int V_59 ;
int V_60 ;
T_3 V_61 [ V_62 ] ;
T_7 * V_16 ;
T_5 V_63 , V_64 , V_65 , V_66 ;
T_11 V_67 ;
T_12 V_68 ;
if ( ! F_5 ( V_17 , V_57 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_2 ( V_17 , V_58 , 2 , V_2 , V_3 ) )
return FALSE ;
V_10 = F_3 ( V_57 ) ;
V_11 = F_3 ( V_58 ) ;
if ( V_10 != V_52 ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_2 ,
V_10 ) ;
return FALSE ;
}
if ( V_11 < V_62 ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_3 ,
V_11 ) ;
return FALSE ;
}
V_59 = V_11 - V_62 ;
if ( ! F_2 ( V_17 , V_61 , V_62 , V_2 , V_3 ) )
return FALSE ;
V_66 = F_3 ( & V_61 [ 4 ] ) ;
V_60 = F_3 ( & V_61 [ 6 ] ) ;
if ( V_60 > V_59 ) {
* V_2 = V_69 ;
* V_3 = F_9 ( L_4 ) ;
return FALSE ;
}
V_55 -> V_70 = V_71 ;
V_55 -> V_72 = V_73 | V_74 ;
V_63 = F_3 ( & V_61 [ 8 ] ) ;
V_64 = F_3 ( & V_61 [ 10 ] ) ;
V_65 = F_3 ( & V_61 [ 12 ] ) ;
V_67 = ( ( ( T_11 ) V_63 ) << 0 ) + ( ( ( T_11 ) V_64 ) << 16 ) +
( ( ( T_11 ) V_65 ) << 32 ) ;
V_68 = ( T_12 ) ( V_67 / 2000000 ) ;
V_16 = ( T_7 * ) V_1 -> V_28 ;
V_55 -> V_75 . V_76 = V_68 + V_16 -> V_45 ;
V_55 -> V_75 . V_77 = ( ( V_78 ) ( V_67 - V_68 * 2000000 ) ) * 500 ;
if ( V_66 - 4 >= V_60 ) {
V_66 -= 4 ;
}
V_55 -> V_79 = V_66 ;
V_55 -> V_80 = V_60 ;
switch ( V_1 -> V_47 ) {
case V_48 :
V_55 -> V_81 . V_82 . V_83 = 0 ;
break;
}
return F_10 ( V_17 , V_56 , V_60 , V_2 , V_3 ) ;
}
static T_8 V_30 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_13 * V_84 )
{
* V_84 = F_11 ( V_1 -> V_17 ) ;
return F_8 ( V_1 , V_1 -> V_17 , & V_1 -> V_55 ,
V_1 -> V_85 , V_2 , V_3 ) ;
}
static T_8 V_32 ( T_2 * V_1 , T_13 V_86 ,
struct V_54 * V_55 , T_10 * V_56 , int * V_2 , T_3 * * V_3 )
{
if ( F_7 ( V_1 -> V_87 , V_86 , V_88 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_87 , V_55 , V_56 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_19 ;
return FALSE ;
}
return TRUE ;
}
static T_8 F_12 ( T_14 * V_89 , T_15 V_90 , int * V_2 )
{
T_15 V_91 ;
while ( V_90 ) {
V_91 = V_90 > 64 ? 64 : V_90 ;
if ( ! F_13 ( V_89 , V_92 , V_91 , V_2 ) )
return FALSE ;
V_90 -= V_91 ;
}
return TRUE ;
}
static T_8 F_14 ( T_14 * V_89 , const T_6 V_93 , int * V_2 )
{
return F_13 ( V_89 , & V_93 , 1 , V_2 ) ;
}
static T_8 F_15 ( T_14 * V_89 , const T_5 V_94 , int * V_2 )
{
T_5 V_95 = F_16 ( V_94 ) ;
return F_13 ( V_89 , & V_95 , 2 , V_2 ) ;
}
static T_8 F_17 ( T_14 * V_89 , const V_78 V_96 , int * V_2 )
{
V_78 V_97 = F_18 ( V_96 ) ;
return F_13 ( V_89 , & V_97 , 4 , V_2 ) ;
}
static T_8 F_19 ( T_14 * V_89 , const T_11 V_98 , int * V_2 )
{
#ifdef F_20
T_5 V_99 = F_21 ( ( T_5 ) ( V_98 >> 32 ) ) ;
V_78 V_100 = F_22 ( ( V_78 ) ( V_98 & 0xFFFFFFFF ) ) ;
#else
T_5 V_99 = ( T_5 ) ( V_98 >> 32 ) ;
V_78 V_100 = ( V_78 ) ( V_98 & 0xFFFFFFFF ) ;
#endif
return F_13 ( V_89 , & V_100 , 4 , V_2 ) &&
F_13 ( V_89 , & V_99 , 2 , V_2 ) ;
}
static T_8 F_23 ( T_14 * V_89 ,
const struct V_54 * V_55 ,
const T_6 * V_101 , int * V_2 , T_3 * * V_3 V_102 )
{
T_11 V_103 ;
int V_79 ;
T_16 * V_104 = ( T_16 * ) ( V_89 -> V_28 ) ;
T_17 V_105 ;
int V_106 = V_55 -> V_80 + V_107 + V_18 ;
if ( V_55 -> V_70 != V_71 ) {
* V_2 = V_108 ;
return FALSE ;
}
if ( V_89 -> V_109 + V_106 > V_110 ) {
* V_2 = V_111 ;
return FALSE ;
}
V_79 = V_55 -> V_80 + ( V_55 -> V_80 ? V_107 : 0 ) ;
if ( V_79 > 65535 ) {
* V_2 = V_112 ;
return FALSE ;
}
if ( ! F_15 ( V_89 , 0x1005 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) V_79 , V_2 ) )
return FALSE ;
if ( ! V_104 -> V_113 ) {
V_104 -> V_45 = V_55 -> V_75 ;
V_104 -> V_114 = 0 ;
V_104 -> V_113 = TRUE ;
V_104 -> V_115 = V_89 -> V_115 ;
V_104 -> V_116 = 0 ;
}
if ( ! F_15 ( V_89 , 0x0001 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , 0x0008 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) ( V_55 -> V_79 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) V_55 -> V_80 , V_2 ) )
return FALSE ;
F_24 ( & V_105 , & V_55 -> V_75 , & V_104 -> V_45 ) ;
V_103 = ( V_105 . V_77 + 250 ) / 500 ;
V_103 += V_105 . V_76 * 2000000 ;
if ( ! F_19 ( V_89 , V_103 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_89 , ++ V_104 -> V_114 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) V_104 -> V_116 , V_2 ) )
return FALSE ;
V_104 -> V_116 = V_79 ;
if ( ! F_12 ( V_89 , 12 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , V_101 , V_55 -> V_80 , V_2 ) )
return FALSE ;
V_89 -> V_109 += V_106 ;
return TRUE ;
}
int F_25 ( int V_115 )
{
if ( V_115 == V_117 )
return V_118 ;
if ( V_115 != V_48
&& V_115 != V_50 )
return V_119 ;
return 0 ;
}
T_8 F_26 ( T_14 * V_89 , int * V_2 )
{
int V_120 ;
void * V_121 ;
V_121 = F_4 ( sizeof( T_16 ) ) ;
if ( ! V_121 ) {
* V_2 = V_122 ;
return FALSE ;
}
( ( T_16 * ) V_121 ) -> V_113 = FALSE ;
V_89 -> V_28 = V_121 ;
V_89 -> V_123 = F_23 ;
V_89 -> V_124 = V_125 ;
V_120 = sizeof ( V_126 )
+ sizeof ( V_127 )
+ sizeof ( V_128 )
+ sizeof ( V_129 )
+ sizeof ( V_130 )
+ sizeof ( V_131 )
+ V_132
+ V_133
+ sizeof ( V_134 )
+ V_135 ;
if ( F_27 ( V_89 , V_120 , V_88 , V_2 ) == - 1 )
return FALSE ;
V_89 -> V_109 = V_120 ;
return TRUE ;
}
static T_8 F_28 ( T_14 * V_89 , int * V_2 )
{
T_16 * V_104 = ( T_16 * ) ( V_89 -> V_28 ) ;
T_5 V_8 = V_104 -> V_115 == V_50
? V_49
: V_46 ;
struct V_15 * V_136 ;
V_136 = localtime ( & V_104 -> V_45 . V_76 ) ;
if ( V_136 == NULL )
return FALSE ;
if ( F_27 ( V_89 , 0 , V_88 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_89 , & V_126 ,
sizeof V_126 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_127 ,
sizeof V_127 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_128 ,
sizeof V_128 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_129 ,
sizeof V_129 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_130 ,
sizeof V_130 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_131 ,
sizeof V_131 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_37 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_137 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) ( V_136 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) ( V_136 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) ( V_136 -> V_39 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , ( T_5 ) ( V_136 -> V_38 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 2 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_14 ( V_89 , ( T_6 ) V_136 -> V_40 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 2 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 6 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , 0 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , 1514 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_89 , V_104 -> V_114 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 12 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_89 , V_104 -> V_114 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_8 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , 20 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_138 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_133 - 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , 1 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_89 , V_104 -> V_114 , V_2 ) )
return FALSE ;
if ( ! F_13 ( V_89 , & V_134 ,
sizeof V_134 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_139 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_135 - 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_89 , V_140 , V_2 ) )
return FALSE ;
if ( ! F_12 ( V_89 , V_135 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8 V_125 ( T_14 * V_89 , int * V_2 )
{
F_28 ( V_89 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
