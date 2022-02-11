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
int F_2 ( T_1 * V_8 , int * V_9 , T_2 * * V_10 )
{
int V_11 ;
T_3 V_12 ;
T_4 V_13 ;
T_5 V_14 ;
int V_15 ;
int V_16 ;
T_6 V_17 ;
T_7 * V_18 = NULL ;
V_19 = V_20 ;
V_11 = 0 ;
if ( ! F_3 ( V_8 -> V_21 , & V_12 , sizeof V_12 ,
V_9 , V_10 ) ) {
if ( * V_9 != V_22 )
return - 1 ;
return 0 ;
}
V_11 += ( int ) sizeof V_12 ;
F_4 ( V_12 ) ;
if ( memcmp ( V_12 . V_23 , V_24 , V_25 ) != 0 ) {
return 0 ;
}
V_18 = ( T_7 * ) F_5 ( sizeof( T_7 ) ) ;
V_18 -> V_26 = V_27 ;
V_8 -> V_28 = ( void * ) V_18 ;
V_16 = V_12 . V_29 + ( ( int ) ( V_12 . V_30 ) << 16 ) ;
for ( V_13 = 0 ; V_13 < V_12 . V_31 ; V_13 ++ ) {
if ( V_11 >= V_16 )
break;
if ( ! F_3 ( V_8 -> V_21 , & V_14 , sizeof V_14 , V_9 , V_10 ) )
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
case V_34 :
if ( ! F_3 ( V_8 -> V_21 , & V_18 -> V_26 ,
sizeof V_18 -> V_26 ,
V_9 , V_10 ) )
return - 1 ;
V_18 -> V_26 = F_8 ( V_18 -> V_26 ) ;
V_11 += ( int ) sizeof V_18 -> V_26 ;
break;
default:
V_15 = V_14 . V_32 - ( int ) sizeof V_14 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_21 , V_15 , V_35 , V_9 ) == - 1 )
return - 1 ;
}
V_11 += V_15 ;
}
}
if ( V_16 < V_11 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_2 ,
V_16 , V_11 ) ;
return - 1 ;
}
V_15 = V_16 - V_11 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_21 , V_15 , V_35 , V_9 ) == - 1 )
return - 1 ;
}
if ( ! F_3 ( V_8 -> V_21 , & V_17 , sizeof V_17 ,
V_9 , V_10 ) )
return - 1 ;
F_10 ( V_17 ) ;
if ( V_17 . V_36 != V_37 ) {
* V_9 = V_38 ;
* V_10 = F_7 ( L_3 , V_17 . V_36 ) ;
return - 1 ;
}
if ( F_11 ( V_17 . V_39 ) == V_40 ) {
* V_9 = V_38 ;
* V_10 = F_7 ( L_4 , V_17 . V_39 ) ;
return - 1 ;
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
if ( F_9 ( V_8 -> V_21 , V_16 , V_54 , V_9 ) == - 1 )
return - 1 ;
F_1 () ;
return 1 ;
}
static T_8 V_44 ( T_1 * V_8 , int * V_9 , T_2 * * V_10 ,
T_9 * V_55 )
{
int V_56 ;
int V_57 ;
T_6 V_17 ;
for (; ; ) {
* V_55 = F_13 ( V_8 -> V_21 ) ;
V_56 = F_14 ( V_8 -> V_21 , & V_8 -> V_58 . V_59 , & V_17 , V_9 ,
V_10 ) ;
if ( V_56 <= 0 )
return FALSE ;
if ( V_17 . V_60 == V_61 )
break;
if ( ! F_15 ( V_8 , V_17 . V_62 ,
V_56 , V_9 , V_10 ) ) {
return FALSE ;
}
}
if ( ! F_16 ( V_8 , & V_17 , & V_8 -> V_58 , V_9 , V_10 ) )
return FALSE ;
V_57 = F_17 ( V_8 -> V_21 , V_17 . V_63 ,
V_56 , V_8 -> V_64 ,
V_8 -> V_58 . V_65 , V_9 , V_10 ) ;
if ( V_57 < 0 ) {
return FALSE ;
}
if ( ! F_15 ( V_8 , V_17 . V_62 ,
V_56 + V_57 , V_9 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
static T_8 V_46 ( T_1 * V_8 , T_9 V_66 ,
struct V_67 * V_58 , T_10 * V_68 , int * V_9 , T_2 * * V_10 )
{
union V_69 * V_59 = & V_58 -> V_59 ;
T_6 V_17 ;
int V_11 ;
int V_57 ;
if ( F_9 ( V_8 -> V_70 , V_66 , V_54 , V_9 ) == - 1 )
return FALSE ;
V_11 = F_14 ( V_8 -> V_70 , V_59 , & V_17 , V_9 ,
V_10 ) ;
if ( V_11 <= 0 )
return FALSE ;
if ( ! F_16 ( V_8 , & V_17 , V_58 , V_9 , V_10 ) )
return FALSE ;
V_57 = F_17 ( V_8 -> V_70 , V_17 . V_63 ,
V_11 , V_68 , V_58 -> V_65 , V_9 , V_10 ) ;
if ( V_57 < 0 ) {
return FALSE ;
}
return TRUE ;
}
static int
F_14 ( T_11 V_21 , union V_69 * V_59 ,
T_6 * V_17 , int * V_9 , T_2 * * V_10 )
{
int V_11 ;
T_4 V_13 ;
T_5 V_14 ;
int V_15 ;
T_12 V_71 ;
V_11 = 0 ;
if ( ! F_18 ( V_21 , V_17 , sizeof *V_17 ,
V_9 , V_10 ) ) {
if ( * V_9 == 0 )
return 0 ;
return - 1 ;
}
V_11 += ( int ) sizeof *V_17 ;
F_10 ( * V_17 ) ;
if ( V_17 -> V_36 != V_37 ) {
for ( V_13 = 0 ; V_13 < sizeof *V_17 ; V_13 ++ ) {
if ( ( ( V_72 * ) V_17 ) [ V_13 ] != 0 )
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
for ( V_13 = 0 ; V_13 < V_17 -> V_31 ; V_13 ++ ) {
if ( ! F_3 ( V_21 , & V_14 , sizeof V_14 , V_9 , V_10 ) )
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
case V_73 :
if ( ! F_3 ( V_21 , & V_71 , sizeof V_71 ,
V_9 , V_10 ) )
return - 1 ;
V_59 -> V_74 . V_75 = 0 ;
V_59 -> V_74 . V_76 = ( V_71 . V_77 & V_78 ) != 0 ;
V_59 -> V_74 . V_79 = V_71 . V_80 ;
V_59 -> V_74 . V_81 = V_71 . V_82 ;
V_59 -> V_74 . V_83 = V_71 . V_84 ;
V_11 += ( int ) sizeof V_71 ;
break;
default:
V_15 = V_14 . V_32 - ( int ) sizeof V_14 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_21 , V_15 , V_35 , V_9 ) == - 1 )
return - 1 ;
}
V_11 += V_15 ;
}
}
return V_11 ;
}
static T_8
F_16 ( T_1 * V_8 , T_6 * V_17 ,
struct V_67 * V_58 , int * V_9 , T_2 * * V_10 )
{
V_58 -> V_85 = V_86 ;
V_58 -> V_87 = V_88 | V_89 ;
V_58 -> V_90 = F_11 ( V_17 -> V_39 ) ;
if( V_8 -> V_41 == V_91 ) {
V_58 -> V_92 = V_17 -> V_93 ;
V_58 -> V_65 = V_17 -> V_94 ;
} else {
if ( V_17 -> V_93 < 4 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_6 ,
V_17 -> V_93 ) ;
return FALSE ;
}
V_58 -> V_92 = V_17 -> V_93 - 4 ;
V_58 -> V_65 = F_19 ( V_17 -> V_94 , V_58 -> V_92 ) ;
}
V_58 -> V_95 . V_96 = ( V_2 ) ( ( V_17 -> V_97 / 1000000000 ) + V_98 ) ;
V_58 -> V_95 . V_99 = ( int ) ( V_17 -> V_97 % 1000000000 ) ;
if ( ( ( T_7 * ) V_8 -> V_28 ) -> V_26 == V_27 )
{
struct V_4 V_100 ;
struct V_4 V_101 ;
V_2 V_102 ;
V_58 -> V_95 . V_96 += V_1 ;
V_101 = * localtime ( & V_58 -> V_95 . V_96 ) ;
if ( V_101 . V_7 > 0 ) {
V_100 = V_101 ;
V_101 . V_7 = 0 ;
V_102 = mktime ( & V_101 ) - mktime ( & V_100 ) ;
V_58 -> V_95 . V_96 -= V_102 ;
}
}
switch ( V_8 -> V_41 ) {
case V_103 :
V_58 -> V_59 . V_104 . V_75 = 0 ;
break;
case V_105 :
break;
}
return TRUE ;
}
static int
F_17 ( T_11 V_21 , int V_63 ,
int V_106 , T_10 * V_68 , int V_32 ,
int * V_9 , char * * V_10 )
{
int V_15 ;
int V_107 = 0 ;
if ( V_63 < V_106 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_7 ,
V_63 , V_106 ) ;
return - 1 ;
}
V_15 = V_63 - V_106 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_21 , V_15 , V_35 , V_9 ) == - 1 ) {
return - 1 ;
}
V_107 += V_15 ;
}
F_20 ( V_68 , V_32 ) ;
if ( ! F_21 ( V_21 , V_68 , V_32 , V_9 , V_10 ) )
return FALSE ;
V_107 += V_32 ;
return V_107 ;
}
static T_8
F_15 ( T_1 * V_8 , int V_62 ,
int V_106 , int * V_9 , char * * V_10 )
{
int V_15 ;
if ( V_62 < V_106 ) {
* V_9 = V_33 ;
* V_10 = F_7 ( L_8 ,
V_62 , V_106 ) ;
return FALSE ;
}
V_15 = V_62 - V_106 ;
if ( V_15 > 0 ) {
if ( F_9 ( V_8 -> V_21 , V_15 , V_35 , V_9 ) == - 1 )
return FALSE ;
}
return TRUE ;
}
int F_22 ( int V_108 )
{
if ( V_108 == V_109 )
return V_110 ;
if ( V_108 < 0 || ( F_12 ( V_108 ) == V_111 ) )
return V_38 ;
return 0 ;
}
T_8 F_23 ( T_13 * V_112 , int * V_9 )
{
T_7 * V_18 = NULL ;
T_3 V_12 ;
T_5 V_113 ;
T_14 V_114 ;
char V_115 [ 64 ] ;
T_15 V_116 ;
struct V_4 * V_117 ;
V_2 V_118 ;
V_18 = ( T_7 * ) F_5 ( sizeof( T_7 ) ) ;
V_18 -> V_42 = 0 ;
V_18 -> V_39 = F_12 ( V_112 -> V_108 ) ;
V_18 -> V_26 = V_119 ;
V_112 -> V_28 = ( void * ) V_18 ;
V_112 -> V_120 = V_121 ;
memset ( & V_12 , 0x00 , sizeof( V_12 ) ) ;
F_24 ( V_12 . V_23 , V_24 , 31 ) ;
V_12 . V_29 = ( V_122 ) sizeof( V_12 ) ;
V_12 . V_30 = 0 ;
{
time ( & V_118 ) ;
V_117 = localtime ( & V_118 ) ;
memset ( & V_115 , 0x00 , sizeof( V_115 ) ) ;
F_25 ( V_115 , 64 , L_9 , asctime ( V_117 ) ) ;
V_116 = strlen ( V_115 ) ;
V_113 . type = V_123 ;
V_113 . V_32 = ( V_122 ) ( sizeof( V_113 ) + V_116 ) ;
V_12 . V_31 ++ ;
V_12 . V_29 += V_113 . V_32 ;
}
{
V_114 . type = V_34 ;
V_114 . V_32 = ( V_122 ) ( sizeof( V_114 ) ) ;
V_114 . V_26 = V_119 ;
V_12 . V_31 ++ ;
V_12 . V_29 += V_114 . V_32 ;
}
F_26 ( V_12 ) ;
if ( ! F_27 ( V_112 , & V_12 , sizeof( V_12 ) , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += sizeof( V_12 ) ;
{
F_28 ( V_113 ) ;
if ( ! F_27 ( V_112 , & V_113 , sizeof( V_113 ) , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += sizeof( V_113 ) ;
if ( ! F_27 ( V_112 , & V_115 , V_116 , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += V_116 ;
}
{
F_29 ( V_114 ) ;
if ( ! F_27 ( V_112 , & V_114 , sizeof( V_114 ) , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += sizeof( V_114 ) ;
}
F_1 () ;
return TRUE ;
}
static T_8 V_121 ( T_13 * V_112 , const struct V_67 * V_58 ,
const V_72 * V_125 ,
int * V_9 )
{
T_7 * V_18 = NULL ;
T_6 V_17 ;
T_16 V_126 ;
if ( V_58 -> V_85 != V_86 ) {
* V_9 = V_127 ;
return FALSE ;
}
if ( V_58 -> V_65 > 65535 ) {
* V_9 = V_128 ;
return FALSE ;
}
if ( V_58 -> V_95 . V_96 < V_98 ) {
if( V_58 -> V_95 . V_96 > ( V_2 ) 0 ) {
V_126 = V_58 -> V_95 . V_96 ;
} else {
V_126 = ( V_2 ) 0 ;
}
} else {
V_126 = V_58 -> V_95 . V_96 - V_98 ;
}
V_18 = ( T_7 * ) V_112 -> V_28 ;
memset ( & V_17 , 0x00 , sizeof( V_17 ) ) ;
V_17 . V_36 = V_37 ;
V_17 . V_129 = 1000000 ;
V_17 . V_94 = ( V_122 ) V_58 -> V_65 ;
V_17 . V_93 = ( V_122 ) ( V_58 -> V_92 + 4 ) ;
V_17 . V_63 = sizeof( V_17 ) ;
V_17 . V_62 = ( V_122 ) sizeof( V_17 ) + V_58 -> V_65 ;
V_17 . V_39 = V_18 -> V_39 ;
V_17 . V_130 = 0x00 ;
V_17 . V_31 = 0 ;
V_17 . V_60 = V_61 ;
V_17 . V_131 = V_18 -> V_42 ;
V_17 . V_132 = V_17 . V_131 ;
V_17 . V_97 = V_126 * 1000000000 + V_58 -> V_95 . V_99 ;
V_18 -> V_42 ++ ;
F_30 ( V_17 ) ;
if ( ! F_27 ( V_112 , & V_17 , sizeof( V_17 ) , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += sizeof( V_17 ) ;
if ( ! F_27 ( V_112 , V_125 , V_58 -> V_65 , V_9 ) ) {
return FALSE ;
}
V_112 -> V_124 += V_58 -> V_65 ;
return TRUE ;
}
static T_17 F_11 ( int V_133 )
{
switch( V_133 ) {
case V_134 :
return V_103 ;
case V_135 :
return V_136 ;
case V_137 :
return V_91 ;
case V_138 :
return V_105 ;
case V_111 :
return V_40 ;
}
return V_40 ;
}
static T_17 F_12 ( int V_139 )
{
switch( V_139 ) {
case V_103 :
return V_134 ;
case V_136 :
return V_135 ;
case V_91 :
return V_137 ;
case V_40 :
return V_111 ;
}
return V_111 ;
}
