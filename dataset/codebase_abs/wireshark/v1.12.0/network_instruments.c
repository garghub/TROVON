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
int V_12 ;
T_3 V_13 ;
T_4 V_14 ;
T_5 V_15 ;
int V_16 ;
int V_17 ;
T_6 V_18 ;
T_7 * V_19 = NULL ;
V_20 = V_21 ;
V_12 = 0 ;
V_11 = F_3 ( & V_13 , sizeof V_13 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_13 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 != 0 && * V_9 != V_23 )
return - 1 ;
return 0 ;
}
V_12 += V_11 ;
F_5 ( V_13 ) ;
if ( memcmp ( V_13 . V_24 , V_25 , V_26 ) != 0 ) {
return 0 ;
}
V_19 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
V_19 -> V_27 = V_28 ;
V_8 -> V_29 = ( void * ) V_19 ;
V_17 = V_13 . V_30 + ( ( int ) ( V_13 . V_31 ) << 16 ) ;
for ( V_14 = 0 ; V_14 < V_13 . V_32 ; V_14 ++ ) {
if ( V_12 >= V_17 )
break;
V_11 = F_3 ( & V_15 , sizeof V_15 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_15 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_23 ;
return - 1 ;
}
V_12 += V_11 ;
F_7 ( V_15 ) ;
if ( V_15 . V_33 < sizeof V_15 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_1 ,
V_15 . V_33 , ( unsigned long ) sizeof V_15 ) ;
return - 1 ;
}
switch ( V_15 . type ) {
case V_35 :
V_11 = F_3 ( & V_19 -> V_27 , sizeof V_19 -> V_27 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_19 -> V_27 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_23 ;
return - 1 ;
}
V_19 -> V_27 = F_9 ( V_19 -> V_27 ) ;
V_12 += V_11 ;
break;
default:
V_16 = V_15 . V_33 - ( int ) sizeof V_15 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_8 -> V_22 , V_16 , V_36 , V_9 ) == - 1 )
return - 1 ;
}
V_12 += V_16 ;
}
}
if ( V_17 < V_12 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_2 ,
V_17 , V_12 ) ;
return - 1 ;
}
V_16 = V_17 - V_12 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_8 -> V_22 , V_16 , V_36 , V_9 ) == - 1 )
return - 1 ;
}
V_11 = F_3 ( & V_18 , sizeof V_18 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_18 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_23 ;
return - 1 ;
}
F_11 ( V_18 ) ;
if ( V_18 . V_37 != V_38 ) {
* V_9 = V_39 ;
* V_10 = F_8 ( L_3 , V_18 . V_37 ) ;
return - 1 ;
}
if ( F_12 ( V_18 . V_40 ) == V_41 ) {
* V_9 = V_39 ;
* V_10 = F_8 ( L_4 , V_18 . V_40 ) ;
return - 1 ;
}
V_8 -> V_42 = F_12 ( V_18 . V_40 ) ;
V_19 -> V_43 = 0 ;
V_19 -> V_40 = F_13 ( V_8 -> V_42 ) ;
V_8 -> V_44 = V_45 ;
V_8 -> V_46 = V_47 ;
V_8 -> V_48 = NULL ;
V_8 -> V_49 = NULL ;
V_8 -> V_50 = 0 ;
V_8 -> V_51 = V_52 ;
V_8 -> V_53 = V_54 ;
if ( F_10 ( V_8 -> V_22 , V_17 , V_55 , V_9 ) == - 1 )
return - 1 ;
F_1 () ;
return 1 ;
}
static T_8 V_45 ( T_1 * V_8 , int * V_9 , T_2 * * V_10 ,
T_9 * V_56 )
{
int V_57 ;
int V_58 ;
T_6 V_18 ;
for (; ; ) {
* V_56 = F_14 ( V_8 -> V_22 ) ;
V_57 = F_15 ( V_8 -> V_22 , & V_8 -> V_59 . V_60 , & V_18 , V_9 ,
V_10 ) ;
if ( V_57 <= 0 )
return FALSE ;
if ( V_18 . V_61 == V_62 )
break;
if ( ! F_16 ( V_8 , V_18 . V_63 ,
V_57 , V_9 , V_10 ) ) {
return FALSE ;
}
}
if ( ! F_17 ( V_8 , & V_18 , & V_8 -> V_59 , V_9 , V_10 ) )
return FALSE ;
V_58 = F_18 ( V_8 -> V_22 , V_18 . V_64 ,
V_57 , V_8 -> V_65 ,
V_8 -> V_59 . V_66 , V_9 , V_10 ) ;
if ( V_58 < 0 ) {
return FALSE ;
}
if ( ! F_16 ( V_8 , V_18 . V_63 ,
V_57 + V_58 , V_9 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
static T_8 V_47 ( T_1 * V_8 , T_9 V_67 ,
struct V_68 * V_59 , T_10 * V_69 , int * V_9 , T_2 * * V_10 )
{
union V_70 * V_60 = & V_59 -> V_60 ;
T_6 V_18 ;
int V_12 ;
int V_58 ;
if ( F_10 ( V_8 -> V_71 , V_67 , V_55 , V_9 ) == - 1 )
return FALSE ;
V_12 = F_15 ( V_8 -> V_71 , V_60 , & V_18 , V_9 ,
V_10 ) ;
if ( V_12 <= 0 )
return FALSE ;
if ( ! F_17 ( V_8 , & V_18 , V_59 , V_9 , V_10 ) )
return FALSE ;
V_58 = F_18 ( V_8 -> V_71 , V_18 . V_64 ,
V_12 , V_69 , V_59 -> V_66 , V_9 , V_10 ) ;
if ( V_58 < 0 ) {
return FALSE ;
}
return TRUE ;
}
static int
F_15 ( T_11 V_22 , union V_70 * V_60 ,
T_6 * V_18 , int * V_9 , T_2 * * V_10 )
{
int V_12 ;
int V_11 ;
T_4 V_14 ;
T_5 V_15 ;
int V_16 ;
T_12 V_72 ;
V_12 = 0 ;
V_11 = F_3 ( V_18 , sizeof *V_18 , V_22 ) ;
if ( V_11 != sizeof *V_18 ) {
* V_9 = F_4 ( V_22 , V_10 ) ;
if ( * V_9 != 0 )
return - 1 ;
return 0 ;
}
V_12 += V_11 ;
F_11 ( * V_18 ) ;
if ( V_18 -> V_37 != V_38 ) {
for ( V_14 = 0 ; V_14 < sizeof *V_18 ; V_14 ++ ) {
if ( ( ( V_73 * ) V_18 ) [ V_14 ] != 0 )
break;
}
if ( V_14 == sizeof *V_18 ) {
* V_9 = 0 ;
return 0 ;
}
* V_9 = V_34 ;
* V_10 = F_8 ( L_5 ,
V_18 -> V_37 ) ;
return - 1 ;
}
for ( V_14 = 0 ; V_14 < V_18 -> V_32 ; V_14 ++ ) {
V_11 = F_3 ( & V_15 , sizeof V_15 , V_22 ) ;
if ( V_11 != sizeof V_15 ) {
* V_9 = F_4 ( V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_23 ;
return - 1 ;
}
V_12 += V_11 ;
F_7 ( V_15 ) ;
if ( V_15 . V_33 < sizeof V_15 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_1 ,
V_15 . V_33 , ( unsigned long ) sizeof V_15 ) ;
return - 1 ;
}
switch ( V_15 . type ) {
case V_74 :
V_11 = F_3 ( & V_72 , sizeof V_72 , V_22 ) ;
if ( V_11 != sizeof V_72 ) {
* V_9 = F_4 ( V_22 , V_10 ) ;
if( * V_9 == 0 )
* V_9 = V_23 ;
return - 1 ;
}
V_60 -> V_75 . V_76 = 0 ;
V_60 -> V_75 . V_77 = ( V_72 . V_78 & V_79 ) != 0 ;
V_60 -> V_75 . V_80 = V_72 . V_81 ;
V_60 -> V_75 . V_82 = V_72 . V_83 ;
V_60 -> V_75 . V_84 = V_72 . V_85 ;
V_12 += V_11 ;
break;
default:
V_16 = V_15 . V_33 - ( int ) sizeof V_15 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_22 , V_16 , V_36 , V_9 ) == - 1 )
return - 1 ;
}
V_12 += V_16 ;
}
}
return V_12 ;
}
static T_8
F_17 ( T_1 * V_8 , T_6 * V_18 ,
struct V_68 * V_59 , int * V_9 , T_2 * * V_10 )
{
V_59 -> V_86 = V_87 ;
V_59 -> V_88 = V_89 | V_90 ;
V_59 -> V_91 = F_12 ( V_18 -> V_40 ) ;
if( V_8 -> V_42 == V_92 ) {
V_59 -> V_93 = V_18 -> V_94 ;
V_59 -> V_66 = V_18 -> V_95 ;
} else {
if ( V_18 -> V_94 < 4 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_6 ,
V_18 -> V_94 ) ;
return FALSE ;
}
V_59 -> V_93 = V_18 -> V_94 - 4 ;
V_59 -> V_66 = F_19 ( V_18 -> V_95 , V_59 -> V_93 ) ;
}
V_59 -> V_96 . V_97 = ( V_2 ) ( ( V_18 -> V_98 / 1000000000 ) + V_99 ) ;
V_59 -> V_96 . V_100 = ( int ) ( V_18 -> V_98 % 1000000000 ) ;
if ( ( ( T_7 * ) V_8 -> V_29 ) -> V_27 == V_28 )
{
struct V_4 V_101 ;
struct V_4 V_102 ;
V_2 V_103 ;
V_59 -> V_96 . V_97 += V_1 ;
V_102 = * localtime ( & V_59 -> V_96 . V_97 ) ;
if ( V_102 . V_7 > 0 ) {
V_101 = V_102 ;
V_102 . V_7 = 0 ;
V_103 = mktime ( & V_102 ) - mktime ( & V_101 ) ;
V_59 -> V_96 . V_97 -= V_103 ;
}
}
switch ( V_8 -> V_42 ) {
case V_104 :
V_59 -> V_60 . V_105 . V_76 = 0 ;
break;
case V_106 :
break;
}
return TRUE ;
}
static int
F_18 ( T_11 V_22 , int V_64 , int V_107 , T_10 * V_69 ,
int V_33 , int * V_9 , char * * V_10 )
{
int V_16 ;
int V_108 = 0 ;
if ( V_64 < V_107 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_7 ,
V_64 , V_107 ) ;
return - 1 ;
}
V_16 = V_64 - V_107 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_22 , V_16 , V_36 , V_9 ) == - 1 ) {
return - 1 ;
}
V_108 += V_16 ;
}
F_20 ( V_69 , V_33 ) ;
if ( ! F_21 ( V_22 , V_69 , V_33 , V_9 , V_10 ) )
return FALSE ;
V_108 += V_33 ;
return V_108 ;
}
static T_8
F_16 ( T_1 * V_8 , int V_63 , int V_107 , int * V_9 ,
char * * V_10 )
{
int V_16 ;
if ( V_63 < V_107 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_8 ,
V_63 , V_107 ) ;
return FALSE ;
}
V_16 = V_63 - V_107 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_8 -> V_22 , V_16 , V_36 , V_9 ) == - 1 )
return FALSE ;
}
return TRUE ;
}
int F_22 ( int V_109 )
{
if ( V_109 == V_110 )
return V_111 ;
if ( V_109 < 0 || ( F_13 ( V_109 ) == V_112 ) )
return V_39 ;
return 0 ;
}
T_8 F_23 ( T_13 * V_113 , int * V_9 )
{
T_7 * V_19 = NULL ;
T_3 V_13 ;
T_5 V_114 ;
T_14 V_115 ;
char V_116 [ 64 ] ;
T_15 V_117 ;
struct V_4 * V_118 ;
V_2 V_119 ;
V_19 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
V_19 -> V_43 = 0 ;
V_19 -> V_40 = F_13 ( V_113 -> V_109 ) ;
V_19 -> V_27 = V_120 ;
V_113 -> V_29 = ( void * ) V_19 ;
V_113 -> V_121 = V_122 ;
memset ( & V_13 , 0x00 , sizeof( V_13 ) ) ;
F_24 ( V_13 . V_24 , V_25 , 31 ) ;
V_13 . V_30 = ( V_123 ) sizeof( V_13 ) ;
V_13 . V_31 = 0 ;
{
time ( & V_119 ) ;
V_118 = localtime ( & V_119 ) ;
memset ( & V_116 , 0x00 , sizeof( V_116 ) ) ;
F_25 ( V_116 , 64 , L_9 , asctime ( V_118 ) ) ;
V_117 = strlen ( V_116 ) ;
V_114 . type = V_124 ;
V_114 . V_33 = ( V_123 ) ( sizeof( V_114 ) + V_117 ) ;
V_13 . V_32 ++ ;
V_13 . V_30 += V_114 . V_33 ;
}
{
V_115 . type = V_35 ;
V_115 . V_33 = ( V_123 ) ( sizeof( V_115 ) ) ;
V_115 . V_27 = V_120 ;
V_13 . V_32 ++ ;
V_13 . V_30 += V_115 . V_33 ;
}
F_26 ( V_13 ) ;
if ( ! F_27 ( V_113 , & V_13 , sizeof( V_13 ) , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += sizeof( V_13 ) ;
{
F_28 ( V_114 ) ;
if ( ! F_27 ( V_113 , & V_114 , sizeof( V_114 ) , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += sizeof( V_114 ) ;
if ( ! F_27 ( V_113 , & V_116 , V_117 , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += V_117 ;
}
{
F_29 ( V_115 ) ;
if ( ! F_27 ( V_113 , & V_115 , sizeof( V_115 ) , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += sizeof( V_115 ) ;
}
F_1 () ;
return TRUE ;
}
static T_8 V_122 ( T_13 * V_113 , const struct V_68 * V_59 ,
const V_73 * V_126 ,
int * V_9 )
{
T_7 * V_19 = NULL ;
T_6 V_18 ;
T_16 V_127 ;
if ( V_59 -> V_86 != V_87 ) {
* V_9 = V_128 ;
return FALSE ;
}
if ( V_59 -> V_66 > 65535 ) {
* V_9 = V_129 ;
return FALSE ;
}
if ( V_59 -> V_96 . V_97 < V_99 ) {
if( V_59 -> V_96 . V_97 > ( V_2 ) 0 ) {
V_127 = V_59 -> V_96 . V_97 ;
} else {
V_127 = ( V_2 ) 0 ;
}
} else {
V_127 = V_59 -> V_96 . V_97 - V_99 ;
}
V_19 = ( T_7 * ) V_113 -> V_29 ;
memset ( & V_18 , 0x00 , sizeof( V_18 ) ) ;
V_18 . V_37 = V_38 ;
V_18 . V_130 = 1000000 ;
V_18 . V_95 = ( V_123 ) V_59 -> V_66 ;
V_18 . V_94 = ( V_123 ) ( V_59 -> V_93 + 4 ) ;
V_18 . V_64 = sizeof( V_18 ) ;
V_18 . V_63 = ( V_123 ) sizeof( V_18 ) + V_59 -> V_66 ;
V_18 . V_40 = V_19 -> V_40 ;
V_18 . V_131 = 0x00 ;
V_18 . V_32 = 0 ;
V_18 . V_61 = V_62 ;
V_18 . V_132 = V_19 -> V_43 ;
V_18 . V_133 = V_18 . V_132 ;
V_18 . V_98 = V_127 * 1000000000 + V_59 -> V_96 . V_100 ;
V_19 -> V_43 ++ ;
F_30 ( V_18 ) ;
if ( ! F_27 ( V_113 , & V_18 , sizeof( V_18 ) , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += sizeof( V_18 ) ;
if ( ! F_27 ( V_113 , V_126 , V_59 -> V_66 , V_9 ) ) {
return FALSE ;
}
V_113 -> V_125 += V_59 -> V_66 ;
return TRUE ;
}
static T_17 F_12 ( int V_134 )
{
switch( V_134 ) {
case V_135 :
return V_104 ;
case V_136 :
return V_137 ;
case V_138 :
return V_92 ;
case V_139 :
return V_106 ;
case V_112 :
return V_41 ;
}
return V_41 ;
}
static T_17 F_13 ( int V_140 )
{
switch( V_140 ) {
case V_104 :
return V_135 ;
case V_137 :
return V_136 ;
case V_92 :
return V_138 ;
case V_41 :
return V_112 ;
}
return V_112 ;
}
