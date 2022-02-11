static void F_1 ( void )
{
if ( V_1 == ( V_2 ) - 1 ) {
V_2 V_3 = 86400 ;
struct V_4 V_5 ;
struct V_4 V_6 ;
V_5 = * gmtime ( & V_3 ) ;
V_6 = * localtime ( & V_3 ) ;
V_6 . V_7 = 0 ;
V_1 = mktime ( & V_5 ) - mktime ( & V_6 ) ;
}
}
T_1 F_2 ( T_2 * V_8 , int * V_9 , T_3 * * V_10 )
{
int V_11 ;
T_4 V_12 ;
T_5 V_13 ;
T_6 V_14 ;
int V_15 ;
int V_16 ;
T_7 V_17 ;
T_8 * V_18 = NULL ;
V_11 = 0 ;
if ( ! F_3 ( V_8 -> V_19 , & V_12 , sizeof V_12 ,
V_9 , V_10 ) ) {
if ( * V_9 != V_20 )
return V_21 ;
return V_22 ;
}
V_11 += ( int ) sizeof V_12 ;
F_4 ( V_12 ) ;
if ( memcmp ( V_12 . V_23 , V_24 , V_25 ) != 0 ) {
return V_22 ;
}
V_18 = ( T_8 * ) F_5 ( sizeof( T_8 ) ) ;
V_18 -> V_26 = V_27 ;
V_8 -> V_28 = ( void * ) V_18 ;
V_16 = V_12 . V_29 + ( ( int ) ( V_12 . V_30 ) << 16 ) ;
for ( V_13 = 0 ; V_13 < V_12 . V_31 ; V_13 ++ ) {
if ( V_11 >= V_16 )
break;
if ( ! F_3 ( V_8 -> V_19 , & V_14 , sizeof V_14 , V_9 , V_10 ) )
return V_21 ;
V_11 += ( int ) sizeof V_14 ;
F_6 ( V_14 ) ;
if ( V_14 . V_32 < sizeof V_14 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_1 ,
V_14 . V_32 , ( unsigned long ) sizeof V_14 ) ;
return V_21 ;
}
switch ( V_14 . type ) {
case V_34 :
if ( ! F_3 ( V_8 -> V_19 , & V_18 -> V_26 ,
sizeof V_18 -> V_26 ,
V_9 , V_10 ) )
return V_21 ;
V_18 -> V_26 = F_8 ( V_18 -> V_26 ) ;
V_11 += ( int ) sizeof V_18 -> V_26 ;
break;
default:
V_15 = V_14 . V_32 - ( int ) sizeof V_14 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_19 , V_15 , V_35 , V_9 ) == - 1 )
return V_21 ;
}
V_11 += V_15 ;
}
}
if ( V_16 < V_11 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_2 ,
V_16 , V_11 ) ;
return V_21 ;
}
V_15 = V_16 - V_11 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_19 , V_15 , V_35 , V_9 ) == - 1 )
return V_21 ;
}
if ( ! F_3 ( V_8 -> V_19 , & V_17 , sizeof V_17 ,
V_9 , V_10 ) )
return V_21 ;
F_10 ( V_17 ) ;
if ( V_17 . V_36 != V_37 ) {
* V_9 = V_38 ;
* V_10 = F_7 ( L_3 , V_17 . V_36 ) ;
return V_21 ;
}
if ( F_11 ( V_17 . V_39 ) == V_40 ) {
* V_9 = V_38 ;
* V_10 = F_7 ( L_4 , V_17 . V_39 ) ;
return V_21 ;
}
V_8 -> V_41 = F_11 ( V_17 . V_39 ) ;
V_18 -> V_42 = 0 ;
V_18 -> V_39 = F_12 ( V_8 -> V_41 ) ;
V_8 -> V_43 = V_44 ;
V_8 -> V_45 = V_46 ;
V_8 -> V_47 = NULL ;
V_8 -> V_48 = NULL ;
V_8 -> V_49 = 0 ;
V_8 -> V_50 = V_51 ;
V_8 -> V_52 = V_53 ;
if ( F_9 ( V_8 -> V_19 , V_16 , V_54 , V_9 ) == - 1 )
return V_21 ;
F_1 () ;
return V_55 ;
}
static T_9 V_44 ( T_2 * V_8 , int * V_9 , T_3 * * V_10 ,
T_10 * V_56 )
{
int V_57 ;
int V_58 ;
T_7 V_17 ;
for (; ; ) {
* V_56 = F_13 ( V_8 -> V_19 ) ;
V_57 = F_14 ( V_8 , V_8 -> V_19 , & V_8 -> V_59 . V_60 , & V_17 , V_9 ,
V_10 ) ;
if ( V_57 <= 0 )
return FALSE ;
if ( V_17 . V_61 == V_62 )
break;
if ( ! F_15 ( V_8 , V_17 . V_63 ,
V_57 , V_9 , V_10 ) ) {
return FALSE ;
}
}
if ( ! F_16 ( V_8 , & V_17 , & V_8 -> V_59 , V_9 , V_10 ) )
return FALSE ;
V_58 = F_17 ( V_8 -> V_19 , V_17 . V_64 ,
V_57 , V_8 -> V_65 ,
V_8 -> V_59 . V_66 , V_9 , V_10 ) ;
if ( V_58 < 0 ) {
return FALSE ;
}
if ( ! F_15 ( V_8 , V_17 . V_63 ,
V_57 + V_58 , V_9 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
static T_9 V_46 ( T_2 * V_8 , T_10 V_67 ,
struct V_68 * V_59 , T_11 * V_69 , int * V_9 , T_3 * * V_10 )
{
union V_70 * V_60 = & V_59 -> V_60 ;
T_7 V_17 ;
int V_11 ;
int V_58 ;
if ( F_9 ( V_8 -> V_71 , V_67 , V_54 , V_9 ) == - 1 )
return FALSE ;
V_11 = F_14 ( V_8 , V_8 -> V_71 , V_60 , & V_17 , V_9 ,
V_10 ) ;
if ( V_11 <= 0 )
return FALSE ;
if ( ! F_16 ( V_8 , & V_17 , V_59 , V_9 , V_10 ) )
return FALSE ;
V_58 = F_17 ( V_8 -> V_71 , V_17 . V_64 ,
V_11 , V_69 , V_59 -> V_66 , V_9 , V_10 ) ;
if ( V_58 < 0 ) {
return FALSE ;
}
return TRUE ;
}
static int
F_14 ( T_2 * V_8 , T_12 V_19 , union V_70 * V_60 ,
T_7 * V_17 , int * V_9 , T_3 * * V_10 )
{
int V_11 ;
T_5 V_13 ;
T_6 V_14 ;
int V_15 ;
T_13 V_72 ;
V_11 = 0 ;
if ( ! F_18 ( V_19 , V_17 , sizeof *V_17 ,
V_9 , V_10 ) ) {
if ( * V_9 != 0 )
return - 1 ;
return 0 ;
}
V_11 += ( int ) sizeof *V_17 ;
F_10 ( * V_17 ) ;
if ( V_17 -> V_36 != V_37 ) {
for ( V_13 = 0 ; V_13 < sizeof *V_17 ; V_13 ++ ) {
if ( ( ( V_73 * ) V_17 ) [ V_13 ] != 0 )
break;
}
if ( V_13 == sizeof *V_17 ) {
* V_9 = 0 ;
return 0 ;
}
* V_9 = V_33 ;
* V_10 = F_7 ( L_5 ,
V_17 -> V_36 ) ;
return - 1 ;
}
switch ( V_8 -> V_41 ) {
case V_74 :
V_60 -> V_75 . V_76 = 0 ;
break;
case V_77 :
V_60 -> V_78 . V_76 = 0 ;
V_60 -> V_78 . V_79 = FALSE ;
V_60 -> V_78 . V_80 = FALSE ;
V_60 -> V_78 . V_81 = V_82 ;
V_60 -> V_78 . V_83 = 0 ;
break;
}
for ( V_13 = 0 ; V_13 < V_17 -> V_31 ; V_13 ++ ) {
if ( ! F_3 ( V_19 , & V_14 , sizeof V_14 , V_9 , V_10 ) )
return - 1 ;
V_11 += ( int ) sizeof V_14 ;
F_6 ( V_14 ) ;
if ( V_14 . V_32 < sizeof V_14 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_1 ,
V_14 . V_32 , ( unsigned long ) sizeof V_14 ) ;
return - 1 ;
}
switch ( V_14 . type ) {
case V_84 :
if ( ! F_3 ( V_19 , & V_72 , sizeof V_72 ,
V_9 , V_10 ) )
return - 1 ;
V_60 -> V_78 . V_83 |=
V_85 |
V_86 |
V_87 ;
V_60 -> V_78 . V_79 = ( V_72 . V_88 & V_89 ) != 0 ;
V_60 -> V_78 . V_90 = V_72 . V_91 ;
V_60 -> V_78 . V_92 = V_72 . V_93 ;
V_60 -> V_78 . V_94 = V_72 . V_95 ;
V_11 += ( int ) sizeof V_72 ;
break;
default:
V_15 = V_14 . V_32 - ( int ) sizeof V_14 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_19 , V_15 , V_35 , V_9 ) == - 1 )
return - 1 ;
}
V_11 += V_15 ;
}
}
return V_11 ;
}
static T_9
F_16 ( T_2 * V_8 , T_7 * V_17 ,
struct V_68 * V_59 , int * V_9 , T_3 * * V_10 )
{
V_59 -> V_96 = V_97 ;
V_59 -> V_83 = V_98 | V_99 ;
V_59 -> V_100 = F_11 ( V_17 -> V_39 ) ;
if( V_8 -> V_41 == V_101 ) {
V_59 -> V_102 = V_17 -> V_103 ;
V_59 -> V_66 = V_17 -> V_104 ;
} else {
if ( V_17 -> V_103 < 4 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_6 ,
V_17 -> V_103 ) ;
return FALSE ;
}
V_59 -> V_102 = V_17 -> V_103 - 4 ;
V_59 -> V_66 = F_19 ( V_17 -> V_104 , V_59 -> V_102 ) ;
}
V_59 -> V_105 . V_106 = ( V_2 ) ( ( V_17 -> V_107 / 1000000000 ) + V_108 ) ;
V_59 -> V_105 . V_109 = ( int ) ( V_17 -> V_107 % 1000000000 ) ;
if ( ( ( T_8 * ) V_8 -> V_28 ) -> V_26 == V_27 )
{
struct V_4 V_110 ;
struct V_4 V_111 ;
V_2 V_112 ;
V_59 -> V_105 . V_106 += V_1 ;
V_111 = * localtime ( & V_59 -> V_105 . V_106 ) ;
if ( V_111 . V_7 > 0 ) {
V_110 = V_111 ;
V_111 . V_7 = 0 ;
V_112 = mktime ( & V_111 ) - mktime ( & V_110 ) ;
V_59 -> V_105 . V_106 -= V_112 ;
}
}
return TRUE ;
}
static int
F_17 ( T_12 V_19 , int V_64 , int V_113 , T_11 * V_69 ,
int V_32 , int * V_9 , char * * V_10 )
{
int V_15 ;
int V_114 = 0 ;
if ( V_64 < V_113 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_7 ,
V_64 , V_113 ) ;
return - 1 ;
}
V_15 = V_64 - V_113 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_19 , V_15 , V_35 , V_9 ) == - 1 ) {
return - 1 ;
}
V_114 += V_15 ;
}
F_20 ( V_69 , V_32 ) ;
if ( ! F_21 ( V_19 , V_69 , V_32 , V_9 , V_10 ) )
return FALSE ;
V_114 += V_32 ;
return V_114 ;
}
static T_9
F_15 ( T_2 * V_8 , int V_63 , int V_113 , int * V_9 ,
char * * V_10 )
{
int V_15 ;
if ( V_63 < V_113 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_8 ,
V_63 , V_113 ) ;
return FALSE ;
}
V_15 = V_63 - V_113 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_19 , V_15 , V_35 , V_9 ) == - 1 )
return FALSE ;
}
return TRUE ;
}
int F_22 ( int V_115 )
{
if ( V_115 == V_116 )
return V_117 ;
if ( V_115 < 0 || ( F_12 ( V_115 ) == V_118 ) )
return V_119 ;
return 0 ;
}
T_9 F_23 ( T_14 * V_120 , int * V_9 )
{
T_8 * V_18 = NULL ;
T_4 V_12 ;
T_6 V_121 ;
T_15 V_122 ;
char V_123 [ 64 ] ;
T_16 V_124 ;
struct V_4 * V_125 ;
V_2 V_126 ;
V_18 = ( T_8 * ) F_5 ( sizeof( T_8 ) ) ;
V_18 -> V_42 = 0 ;
V_18 -> V_39 = F_12 ( V_120 -> V_115 ) ;
V_18 -> V_26 = V_127 ;
V_120 -> V_28 = ( void * ) V_18 ;
V_120 -> V_128 = V_129 ;
memset ( & V_12 , 0x00 , sizeof( V_12 ) ) ;
F_24 ( V_12 . V_23 , V_24 , 31 ) ;
V_12 . V_29 = ( V_130 ) sizeof( V_12 ) ;
V_12 . V_30 = 0 ;
{
time ( & V_126 ) ;
V_125 = localtime ( & V_126 ) ;
memset ( & V_123 , 0x00 , sizeof( V_123 ) ) ;
F_25 ( V_123 , 64 , L_9 , asctime ( V_125 ) ) ;
V_124 = strlen ( V_123 ) ;
V_121 . type = V_131 ;
V_121 . V_32 = ( V_130 ) ( sizeof( V_121 ) + V_124 ) ;
V_12 . V_31 ++ ;
V_12 . V_29 += V_121 . V_32 ;
}
{
V_122 . type = V_34 ;
V_122 . V_32 = ( V_130 ) ( sizeof( V_122 ) ) ;
V_122 . V_26 = V_127 ;
V_12 . V_31 ++ ;
V_12 . V_29 += V_122 . V_32 ;
}
F_26 ( V_12 ) ;
if ( ! F_27 ( V_120 , & V_12 , sizeof( V_12 ) , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += sizeof( V_12 ) ;
{
F_28 ( V_121 ) ;
if ( ! F_27 ( V_120 , & V_121 , sizeof( V_121 ) , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += sizeof( V_121 ) ;
if ( ! F_27 ( V_120 , & V_123 , V_124 , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += V_124 ;
}
{
F_29 ( V_122 ) ;
if ( ! F_27 ( V_120 , & V_122 , sizeof( V_122 ) , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += sizeof( V_122 ) ;
}
F_1 () ;
return TRUE ;
}
static T_9 V_129 ( T_14 * V_120 , const struct V_68 * V_59 ,
const V_73 * V_133 ,
int * V_9 , T_3 * * V_10 V_134 )
{
T_8 * V_18 = NULL ;
T_7 V_17 ;
T_17 V_135 ;
if ( V_59 -> V_96 != V_97 ) {
* V_9 = V_136 ;
return FALSE ;
}
if ( V_59 -> V_66 > 65535 ) {
* V_9 = V_137 ;
return FALSE ;
}
if ( V_59 -> V_105 . V_106 < V_108 ) {
if( V_59 -> V_105 . V_106 > ( V_2 ) 0 ) {
V_135 = V_59 -> V_105 . V_106 ;
} else {
V_135 = ( V_2 ) 0 ;
}
} else {
V_135 = V_59 -> V_105 . V_106 - V_108 ;
}
V_18 = ( T_8 * ) V_120 -> V_28 ;
memset ( & V_17 , 0x00 , sizeof( V_17 ) ) ;
V_17 . V_36 = V_37 ;
V_17 . V_138 = 1000000 ;
V_17 . V_104 = ( V_130 ) V_59 -> V_66 ;
V_17 . V_103 = ( V_130 ) ( V_59 -> V_102 + 4 ) ;
V_17 . V_64 = sizeof( V_17 ) ;
V_17 . V_63 = ( V_130 ) sizeof( V_17 ) + V_59 -> V_66 ;
V_17 . V_39 = V_18 -> V_39 ;
V_17 . V_139 = 0x00 ;
V_17 . V_31 = 0 ;
V_17 . V_61 = V_62 ;
V_17 . V_140 = V_18 -> V_42 ;
V_17 . V_141 = V_17 . V_140 ;
V_17 . V_107 = V_135 * 1000000000 + V_59 -> V_105 . V_109 ;
V_18 -> V_42 ++ ;
F_30 ( V_17 ) ;
if ( ! F_27 ( V_120 , & V_17 , sizeof( V_17 ) , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += sizeof( V_17 ) ;
if ( ! F_27 ( V_120 , V_133 , V_59 -> V_66 , V_9 ) ) {
return FALSE ;
}
V_120 -> V_132 += V_59 -> V_66 ;
return TRUE ;
}
static T_18 F_11 ( int V_142 )
{
switch( V_142 ) {
case V_143 :
return V_74 ;
case V_144 :
return V_145 ;
case V_146 :
return V_101 ;
case V_147 :
return V_77 ;
case V_118 :
return V_40 ;
}
return V_40 ;
}
static T_18 F_12 ( int V_148 )
{
switch( V_148 ) {
case V_74 :
return V_143 ;
case V_145 :
return V_144 ;
case V_101 :
return V_146 ;
case V_40 :
return V_118 ;
}
return V_118 ;
}
