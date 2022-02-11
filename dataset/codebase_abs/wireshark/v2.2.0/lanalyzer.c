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
if ( * V_2 != V_19 ) {
F_5 ( V_6 ) ;
return V_20 ;
}
F_5 ( V_6 ) ;
return V_21 ;
}
F_6 ( F_7 ( V_1 -> V_24 , V_25 , 0 ) , V_26 , V_6 , V_11 ) ;
F_5 ( V_6 ) ;
}
V_1 -> V_27 = V_28 ;
V_16 = ( T_7 * ) F_4 ( sizeof( T_7 ) ) ;
V_1 -> V_29 = ( void * ) V_16 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = 0 ;
V_1 -> V_35 = V_36 ;
while ( 1 ) {
if ( ! F_8 ( V_1 -> V_17 , & V_4 ,
V_18 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
return V_37 ;
}
return V_20 ;
}
V_10 = F_3 ( V_4 . V_10 ) ;
V_11 = F_3 ( V_4 . V_11 ) ;
switch ( V_10 ) {
case V_38 :
if ( ! F_2 ( V_1 -> V_17 , V_7 ,
sizeof V_7 , V_2 , V_3 ) )
return V_20 ;
V_12 = V_7 [ 0 ] ;
V_13 = V_7 [ 1 ] ;
V_14 = F_3 ( & V_7 [ 2 ] ) ;
V_15 . V_39 = V_14 - 1900 ;
V_15 . V_40 = V_13 - 1 ;
V_15 . V_41 = V_12 ;
V_15 . V_42 = 0 ;
V_15 . V_43 = 0 ;
V_15 . V_44 = 0 ;
V_15 . V_45 = - 1 ;
V_16 -> V_46 = mktime ( & V_15 ) ;
V_9 = F_3 ( & V_7 [ 30 ] ) ;
V_1 -> V_34 = V_9 ;
V_8 = F_3 ( & V_7 [ 188 ] ) ;
switch ( V_8 ) {
case V_47 :
V_1 -> V_48 = V_49 ;
break;
case V_50 :
V_1 -> V_48 = V_51 ;
break;
default:
* V_2 = V_52 ;
* V_3 = F_9 ( L_1 ,
V_8 ) ;
return V_20 ;
}
break;
case V_53 :
if ( F_10 ( V_1 -> V_17 , - V_18 , V_54 , V_2 ) == - 1 ) {
return V_20 ;
}
return V_37 ;
default:
if ( F_10 ( V_1 -> V_17 , V_11 , V_54 , V_2 ) == - 1 ) {
return V_20 ;
}
break;
}
}
}
static T_8 F_11 ( T_2 * V_1 , T_9 V_17 ,
struct V_55 * V_56 , T_10 * V_57 , int * V_2 , T_3 * * V_3 )
{
char V_58 [ 2 ] ;
char V_59 [ 2 ] ;
T_5 V_10 , V_11 ;
int V_60 ;
int V_61 ;
T_3 V_62 [ V_63 ] ;
T_7 * V_16 ;
T_5 V_64 , V_65 , V_66 , V_67 ;
T_11 V_68 ;
T_12 V_69 ;
if ( ! F_8 ( V_17 , V_58 , 2 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_2 ( V_17 , V_59 , 2 , V_2 , V_3 ) )
return FALSE ;
V_10 = F_3 ( V_58 ) ;
V_11 = F_3 ( V_59 ) ;
if ( V_10 != V_53 ) {
* V_2 = V_70 ;
* V_3 = F_9 ( L_2 ,
V_10 ) ;
return FALSE ;
}
if ( V_11 < V_63 ) {
* V_2 = V_70 ;
* V_3 = F_9 ( L_3 ,
V_11 ) ;
return FALSE ;
}
V_60 = V_11 - V_63 ;
if ( ! F_2 ( V_17 , V_62 , V_63 , V_2 , V_3 ) )
return FALSE ;
V_67 = F_3 ( & V_62 [ 4 ] ) ;
V_61 = F_3 ( & V_62 [ 6 ] ) ;
if ( V_61 > V_60 ) {
* V_2 = V_70 ;
* V_3 = F_12 ( L_4 ) ;
return FALSE ;
}
V_56 -> V_71 = V_72 ;
V_56 -> V_73 = V_74 | V_75 ;
V_64 = F_3 ( & V_62 [ 8 ] ) ;
V_65 = F_3 ( & V_62 [ 10 ] ) ;
V_66 = F_3 ( & V_62 [ 12 ] ) ;
V_68 = ( ( ( T_11 ) V_64 ) << 0 ) + ( ( ( T_11 ) V_65 ) << 16 ) +
( ( ( T_11 ) V_66 ) << 32 ) ;
V_69 = ( T_12 ) ( V_68 / 2000000 ) ;
V_16 = ( T_7 * ) V_1 -> V_29 ;
V_56 -> V_76 . V_77 = V_69 + V_16 -> V_46 ;
V_56 -> V_76 . V_78 = ( ( V_79 ) ( V_68 - V_69 * 2000000 ) ) * 500 ;
if ( V_67 - 4 >= V_61 ) {
V_67 -= 4 ;
}
V_56 -> V_80 = V_67 ;
V_56 -> V_81 = V_61 ;
switch ( V_1 -> V_48 ) {
case V_49 :
V_56 -> V_82 . V_83 . V_84 = 0 ;
break;
}
return F_13 ( V_17 , V_57 , V_61 , V_2 , V_3 ) ;
}
static T_8 V_31 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_13 * V_85 )
{
* V_85 = F_14 ( V_1 -> V_17 ) ;
return F_11 ( V_1 , V_1 -> V_17 , & V_1 -> V_56 ,
V_1 -> V_86 , V_2 , V_3 ) ;
}
static T_8 V_33 ( T_2 * V_1 , T_13 V_87 ,
struct V_55 * V_56 , T_10 * V_57 , int * V_2 , T_3 * * V_3 )
{
if ( F_10 ( V_1 -> V_88 , V_87 , V_89 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_11 ( V_1 , V_1 -> V_88 , V_56 , V_57 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_19 ;
return FALSE ;
}
return TRUE ;
}
static T_8 F_15 ( T_14 * V_90 , T_15 V_91 , int * V_2 )
{
T_15 V_92 ;
while ( V_91 ) {
V_92 = V_91 > 64 ? 64 : V_91 ;
if ( ! F_16 ( V_90 , V_93 , V_92 , V_2 ) )
return FALSE ;
V_91 -= V_92 ;
}
return TRUE ;
}
static T_8 F_17 ( T_14 * V_90 , const T_6 V_94 , int * V_2 )
{
return F_16 ( V_90 , & V_94 , 1 , V_2 ) ;
}
static T_8 F_18 ( T_14 * V_90 , const T_5 V_95 , int * V_2 )
{
T_5 V_96 = F_19 ( V_95 ) ;
return F_16 ( V_90 , & V_96 , 2 , V_2 ) ;
}
static T_8 F_20 ( T_14 * V_90 , const V_79 V_97 , int * V_2 )
{
V_79 V_98 = F_21 ( V_97 ) ;
return F_16 ( V_90 , & V_98 , 4 , V_2 ) ;
}
static T_8 F_22 ( T_14 * V_90 , const T_11 V_99 , int * V_2 )
{
#ifdef F_23
T_5 V_100 = F_24 ( ( T_5 ) ( V_99 >> 32 ) ) ;
V_79 V_101 = F_25 ( ( V_79 ) ( V_99 & 0xFFFFFFFF ) ) ;
#else
T_5 V_100 = ( T_5 ) ( V_99 >> 32 ) ;
V_79 V_101 = ( V_79 ) ( V_99 & 0xFFFFFFFF ) ;
#endif
return F_16 ( V_90 , & V_101 , 4 , V_2 ) &&
F_16 ( V_90 , & V_100 , 2 , V_2 ) ;
}
static T_8 F_26 ( T_14 * V_90 ,
const struct V_55 * V_56 ,
const T_6 * V_102 , int * V_2 , T_3 * * V_3 V_103 )
{
T_11 V_104 ;
int V_80 ;
T_16 * V_105 = ( T_16 * ) ( V_90 -> V_29 ) ;
T_17 V_106 ;
int V_107 = V_56 -> V_81 + V_108 + V_18 ;
if ( V_56 -> V_71 != V_72 ) {
* V_2 = V_109 ;
return FALSE ;
}
if ( V_90 -> V_110 + V_107 > V_111 ) {
* V_2 = V_112 ;
return FALSE ;
}
V_80 = V_56 -> V_81 + ( V_56 -> V_81 ? V_108 : 0 ) ;
if ( V_80 > 65535 ) {
* V_2 = V_113 ;
return FALSE ;
}
if ( ! F_18 ( V_90 , 0x1005 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) V_80 , V_2 ) )
return FALSE ;
if ( ! V_105 -> V_114 ) {
V_105 -> V_46 = V_56 -> V_76 ;
V_105 -> V_115 = 0 ;
V_105 -> V_114 = TRUE ;
V_105 -> V_116 = V_90 -> V_116 ;
V_105 -> V_117 = 0 ;
}
if ( ! F_18 ( V_90 , 0x0001 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , 0x0008 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) ( V_56 -> V_80 + 4 ) , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) V_56 -> V_81 , V_2 ) )
return FALSE ;
F_27 ( & V_106 , & V_56 -> V_76 , & V_105 -> V_46 ) ;
V_104 = ( V_106 . V_78 + 250 ) / 500 ;
V_104 += V_106 . V_77 * 2000000 ;
if ( ! F_22 ( V_90 , V_104 , V_2 ) )
return FALSE ;
if ( ! F_20 ( V_90 , ++ V_105 -> V_115 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) V_105 -> V_117 , V_2 ) )
return FALSE ;
V_105 -> V_117 = V_80 ;
if ( ! F_15 ( V_90 , 12 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , V_102 , V_56 -> V_81 , V_2 ) )
return FALSE ;
V_90 -> V_110 += V_107 ;
return TRUE ;
}
int F_28 ( int V_116 )
{
if ( V_116 == V_118 )
return V_119 ;
if ( V_116 != V_49
&& V_116 != V_51 )
return V_120 ;
return 0 ;
}
T_8 F_29 ( T_14 * V_90 , int * V_2 )
{
int V_121 ;
void * V_122 ;
V_122 = F_4 ( sizeof( T_16 ) ) ;
if ( ! V_122 ) {
* V_2 = V_123 ;
return FALSE ;
}
( ( T_16 * ) V_122 ) -> V_114 = FALSE ;
V_90 -> V_29 = V_122 ;
V_90 -> V_124 = F_26 ;
V_90 -> V_125 = V_126 ;
V_121 = sizeof ( V_127 )
+ sizeof ( V_128 )
+ sizeof ( V_129 )
+ sizeof ( V_130 )
+ sizeof ( V_131 )
+ sizeof ( V_132 )
+ V_133
+ V_134
+ sizeof ( V_135 )
+ V_136 ;
if ( F_30 ( V_90 , V_121 , V_89 , V_2 ) == - 1 )
return FALSE ;
V_90 -> V_110 = V_121 ;
return TRUE ;
}
static T_8 F_31 ( T_14 * V_90 , int * V_2 )
{
T_16 * V_105 = ( T_16 * ) ( V_90 -> V_29 ) ;
T_5 V_8 = V_105 -> V_116 == V_51
? V_50
: V_47 ;
struct V_15 * V_137 ;
V_137 = localtime ( & V_105 -> V_46 . V_77 ) ;
if ( V_137 == NULL )
return FALSE ;
if ( F_30 ( V_90 , 0 , V_89 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_16 ( V_90 , & V_127 ,
sizeof V_127 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_128 ,
sizeof V_128 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_129 ,
sizeof V_129 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_130 ,
sizeof V_130 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_131 ,
sizeof V_131 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_132 ,
sizeof V_132 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_38 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_138 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) ( V_137 -> V_40 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) ( V_137 -> V_39 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) ( V_137 -> V_40 + 1 ) , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , ( T_5 ) ( V_137 -> V_39 + 1900 ) , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_44 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 2 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_44 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_43 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_42 , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_90 , ( T_6 ) V_137 -> V_41 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 6 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , 0 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , 1514 , V_2 ) )
return FALSE ;
if ( ! F_20 ( V_90 , V_105 -> V_115 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 12 , V_2 ) )
return FALSE ;
if ( ! F_20 ( V_90 , V_105 -> V_115 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 34 * 4 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_8 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , 20 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_139 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_134 - 4 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , 1 , V_2 ) )
return FALSE ;
if ( ! F_20 ( V_90 , V_105 -> V_115 , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_90 , & V_135 ,
sizeof V_135 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_140 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_136 - 4 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_90 , V_141 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_90 , V_136 - 6 , V_2 ) )
return FALSE ;
return TRUE ;
}
static T_8 V_126 ( T_14 * V_90 , int * V_2 )
{
F_31 ( V_90 , V_2 ) ;
return * V_2 ? FALSE : TRUE ;
}
