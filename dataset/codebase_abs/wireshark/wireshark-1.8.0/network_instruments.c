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
if ( * V_9 != 0 )
return - 1 ;
return 0 ;
}
V_12 += V_11 ;
F_5 ( V_13 ) ;
if ( memcmp ( V_13 . V_23 , V_24 , V_25 ) != 0 ) {
return 0 ;
}
V_19 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
V_19 -> V_26 = V_27 ;
V_8 -> V_28 = ( void * ) V_19 ;
V_17 = V_13 . V_29 + ( ( int ) ( V_13 . V_30 ) << 16 ) ;
for ( V_14 = 0 ; V_14 < V_13 . V_31 ; V_14 ++ ) {
if ( V_12 >= V_17 )
break;
V_11 = F_3 ( & V_15 , sizeof V_15 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_15 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_32 ;
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
V_11 = F_3 ( & V_19 -> V_26 , sizeof V_19 -> V_26 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_19 -> V_26 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if( * V_9 == 0 )
* V_9 = V_32 ;
return - 1 ;
}
V_19 -> V_26 = F_9 ( V_19 -> V_26 ) ;
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
return FALSE ;
}
V_16 = V_17 - V_12 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_8 -> V_22 , V_16 , V_36 , V_9 ) == - 1 )
return - 1 ;
}
V_11 = F_3 ( & V_18 , sizeof V_18 , V_8 -> V_22 ) ;
if ( V_11 != sizeof V_18 ) {
* V_9 = F_4 ( V_8 -> V_22 , V_10 ) ;
if ( * V_9 != 0 )
return - 1 ;
return 0 ;
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
V_57 = F_15 ( V_8 -> V_22 , & V_8 -> V_59 , & V_18 , V_9 ,
V_10 ) ;
if ( V_57 <= 0 )
return FALSE ;
if ( V_18 . V_60 == V_61 )
break;
if ( ! F_16 ( V_8 , V_18 . V_62 ,
V_57 , V_9 , V_10 ) ) {
return FALSE ;
}
}
if ( V_18 . V_63 < 4 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_5 ,
V_18 . V_63 ) ;
return FALSE ;
}
V_8 -> V_64 . V_65 = V_66 | V_67 ;
V_8 -> V_64 . V_68 = F_12 ( V_18 . V_40 ) ;
if( V_8 -> V_42 == V_69 ) {
V_8 -> V_64 . V_70 = V_18 . V_63 ;
V_8 -> V_64 . V_71 = V_18 . V_72 ;
} else {
V_8 -> V_64 . V_70 = V_18 . V_63 - 4 ;
V_8 -> V_64 . V_71 = F_17 ( V_18 . V_72 , V_8 -> V_64 . V_70 ) ;
}
V_8 -> V_64 . V_73 . V_74 = ( V_2 ) ( ( V_18 . V_75 / 1000000000 ) + V_76 ) ;
V_8 -> V_64 . V_73 . V_77 = ( int ) ( V_18 . V_75 % 1000000000 ) ;
if ( ( ( T_7 * ) V_8 -> V_28 ) -> V_26 == V_27 )
{
struct V_4 V_78 ;
struct V_4 V_79 ;
V_2 V_80 ;
V_8 -> V_64 . V_73 . V_74 += V_1 ;
V_79 = * localtime ( & V_8 -> V_64 . V_73 . V_74 ) ;
if ( V_79 . V_7 > 0 ) {
V_78 = V_79 ;
V_79 . V_7 = 0 ;
V_80 = mktime ( & V_79 ) - mktime ( & V_78 ) ;
V_8 -> V_64 . V_73 . V_74 -= V_80 ;
}
}
switch ( V_8 -> V_42 ) {
case V_81 :
V_8 -> V_59 . V_82 . V_83 = 0 ;
break;
case V_84 :
break;
}
F_18 ( V_8 -> V_85 , V_18 . V_72 ) ;
V_58 = F_19 ( V_8 -> V_22 , V_18 . V_86 ,
V_57 , F_20 ( V_8 -> V_85 ) ,
V_18 . V_72 , V_9 , V_10 ) ;
if ( V_58 < 0 ) {
return FALSE ;
}
if ( ! F_16 ( V_8 , V_18 . V_62 ,
V_57 + V_58 , V_9 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
static T_8 V_47 ( T_1 * V_8 , T_9 V_87 ,
union V_88 * V_59 , T_10 * V_89 , int V_33 ,
int * V_9 , T_2 * * V_10 )
{
T_6 V_18 ;
int V_12 ;
if ( F_10 ( V_8 -> V_90 , V_87 , V_55 , V_9 ) == - 1 )
return FALSE ;
V_12 = F_15 ( V_8 -> V_90 , V_59 , & V_18 , V_9 ,
V_10 ) ;
if ( V_12 <= 0 )
return FALSE ;
switch ( V_8 -> V_42 ) {
case V_81 :
V_59 -> V_82 . V_83 = 0 ;
break;
case V_84 :
break;
}
if ( ! F_19 ( V_8 -> V_90 , V_18 . V_86 ,
V_12 , V_89 , V_33 , V_9 , V_10 ) )
return FALSE ;
return TRUE ;
}
static int
F_15 ( T_11 V_22 , union V_88 * V_59 ,
T_6 * V_18 , int * V_9 , T_2 * * V_10 )
{
int V_12 ;
int V_11 ;
T_4 V_14 ;
T_5 V_15 ;
int V_16 ;
T_12 V_91 ;
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
if ( ( ( T_10 * ) V_18 ) [ V_14 ] != 0 )
break;
}
if ( V_14 == sizeof *V_18 ) {
* V_9 = 0 ;
return 0 ;
}
* V_9 = V_34 ;
* V_10 = F_8 ( L_6 ,
V_18 -> V_37 ) ;
return - 1 ;
}
for ( V_14 = 0 ; V_14 < V_18 -> V_31 ; V_14 ++ ) {
V_11 = F_3 ( & V_15 , sizeof V_15 , V_22 ) ;
if ( V_11 != sizeof V_15 ) {
* V_9 = F_4 ( V_22 , V_10 ) ;
if ( * V_9 == 0 )
* V_9 = V_32 ;
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
case V_92 :
V_11 = F_3 ( & V_91 , sizeof V_91 , V_22 ) ;
if ( V_11 != sizeof V_91 ) {
* V_9 = F_4 ( V_22 , V_10 ) ;
if( * V_9 == 0 )
* V_9 = V_32 ;
return - 1 ;
}
V_59 -> V_93 . V_83 = 0 ;
V_59 -> V_93 . V_94 = V_91 . V_95 ;
V_59 -> V_93 . V_96 = V_91 . V_97 ;
V_59 -> V_93 . V_98 = V_91 . V_99 ;
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
static int
F_19 ( T_11 V_22 , int V_86 , int V_100 , T_10 * V_89 ,
int V_33 , int * V_9 , char * * V_10 )
{
int V_16 ;
int V_101 = 0 ;
if ( V_86 < V_100 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_7 ,
V_86 , V_100 ) ;
return - 1 ;
}
V_16 = V_86 - V_100 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_22 , V_16 , V_36 , V_9 ) == - 1 ) {
return - 1 ;
}
V_101 += V_16 ;
}
F_21 ( V_89 , V_33 , V_22 , V_9 , V_10 ) ;
V_101 += V_33 ;
return V_101 ;
}
static T_8
F_16 ( T_1 * V_8 , int V_62 , int V_100 , int * V_9 ,
char * * V_10 )
{
int V_16 ;
if ( V_62 < V_100 ) {
* V_9 = V_34 ;
* V_10 = F_8 ( L_8 ,
V_62 , V_100 ) ;
return FALSE ;
}
V_16 = V_62 - V_100 ;
if ( V_16 > 0 ) {
if ( F_10 ( V_8 -> V_22 , V_16 , V_36 , V_9 ) == - 1 )
return FALSE ;
}
return TRUE ;
}
int F_22 ( int V_102 )
{
if ( V_102 == V_103 )
return V_104 ;
if ( V_102 < 0 || ( F_13 ( V_102 ) == V_105 ) )
return V_39 ;
return 0 ;
}
T_8 F_23 ( T_13 * V_106 , int * V_9 )
{
T_7 * V_19 = NULL ;
T_3 V_13 ;
T_5 V_107 ;
T_14 V_108 ;
char V_109 [ 64 ] ;
T_15 V_110 ;
struct V_4 * V_111 ;
V_2 V_112 ;
V_19 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
V_19 -> V_43 = 0 ;
V_19 -> V_40 = F_13 ( V_106 -> V_102 ) ;
V_19 -> V_26 = V_113 ;
V_106 -> V_28 = ( void * ) V_19 ;
V_106 -> V_114 = V_115 ;
memset ( & V_13 , 0x00 , sizeof( V_13 ) ) ;
F_24 ( V_13 . V_23 , V_24 , 31 ) ;
V_13 . V_29 = ( V_116 ) sizeof( V_13 ) ;
V_13 . V_30 = 0 ;
{
time ( & V_112 ) ;
V_111 = localtime ( & V_112 ) ;
memset ( & V_109 , 0x00 , sizeof( V_109 ) ) ;
F_25 ( V_109 , 64 , L_9 , asctime ( V_111 ) ) ;
V_110 = strlen ( V_109 ) ;
V_107 . type = V_117 ;
V_107 . V_33 = ( V_116 ) ( sizeof( V_107 ) + V_110 ) ;
V_13 . V_31 ++ ;
V_13 . V_29 += V_107 . V_33 ;
}
{
V_108 . type = V_35 ;
V_108 . V_33 = ( V_116 ) ( sizeof( V_108 ) ) ;
V_108 . V_26 = V_113 ;
V_13 . V_31 ++ ;
V_13 . V_29 += V_108 . V_33 ;
}
F_26 ( V_13 ) ;
if ( ! F_27 ( V_106 , & V_13 , sizeof( V_13 ) , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += sizeof( V_13 ) ;
{
F_28 ( V_107 ) ;
if ( ! F_27 ( V_106 , & V_107 , sizeof( V_107 ) , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += sizeof( V_107 ) ;
if ( ! F_27 ( V_106 , & V_109 , V_110 , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += V_110 ;
}
{
F_29 ( V_108 ) ;
if ( ! F_27 ( V_106 , & V_108 , sizeof( V_108 ) , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += sizeof( V_108 ) ;
}
F_1 () ;
return TRUE ;
}
static T_8 V_115 ( T_13 * V_106 , const struct V_119 * V_64 ,
const union V_88 * V_59 V_120 , const T_10 * V_89 ,
int * V_9 )
{
T_7 * V_19 = NULL ;
T_6 V_18 ;
T_16 V_121 ;
if ( V_64 -> V_73 . V_74 < V_76 ) {
if( V_64 -> V_73 . V_74 > ( V_2 ) 0 ) {
V_121 = V_64 -> V_73 . V_74 ;
} else {
V_121 = ( V_2 ) 0 ;
}
} else {
V_121 = V_64 -> V_73 . V_74 - V_76 ;
}
V_19 = ( T_7 * ) V_106 -> V_28 ;
memset ( & V_18 , 0x00 , sizeof( V_18 ) ) ;
V_18 . V_37 = V_38 ;
V_18 . V_122 = 1000000 ;
V_18 . V_72 = ( V_116 ) V_64 -> V_71 ;
V_18 . V_63 = ( V_116 ) ( V_64 -> V_70 + 4 ) ;
V_18 . V_86 = sizeof( V_18 ) ;
V_18 . V_62 = ( V_116 ) sizeof( V_18 ) + V_64 -> V_71 ;
V_18 . V_40 = V_19 -> V_40 ;
V_18 . V_123 = 0x00 ;
V_18 . V_31 = 0 ;
V_18 . V_60 = V_61 ;
V_18 . V_124 = V_19 -> V_43 ;
V_18 . V_125 = V_18 . V_124 ;
V_18 . V_75 = V_121 * 1000000000 + V_64 -> V_73 . V_77 ;
V_19 -> V_43 ++ ;
F_30 ( V_18 ) ;
if ( ! F_27 ( V_106 , & V_18 , sizeof( V_18 ) , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += sizeof( V_18 ) ;
if ( ! F_27 ( V_106 , V_89 , V_64 -> V_71 , V_9 ) ) {
return FALSE ;
}
V_106 -> V_118 += V_64 -> V_71 ;
return TRUE ;
}
static T_17 F_12 ( int V_126 )
{
switch( V_126 ) {
case V_127 :
return V_81 ;
case V_128 :
return V_129 ;
case V_130 :
return V_69 ;
case V_131 :
return V_84 ;
case V_105 :
return V_41 ;
}
return V_41 ;
}
static T_17 F_13 ( int V_132 )
{
switch( V_132 ) {
case V_81 :
return V_127 ;
case V_129 :
return V_128 ;
case V_69 :
return V_130 ;
case V_41 :
return V_105 ;
}
return V_105 ;
}
