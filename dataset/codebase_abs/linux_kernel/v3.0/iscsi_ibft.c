static T_1 F_1 ( char * V_1 , T_2 * V_2 )
{
char * V_3 = V_1 ;
if ( V_2 [ 0 ] == 0 && V_2 [ 1 ] == 0 && V_2 [ 2 ] == 0 && V_2 [ 3 ] == 0 &&
V_2 [ 4 ] == 0 && V_2 [ 5 ] == 0 && V_2 [ 6 ] == 0 && V_2 [ 7 ] == 0 &&
V_2 [ 8 ] == 0 && V_2 [ 9 ] == 0 && V_2 [ 10 ] == 0xff && V_2 [ 11 ] == 0xff ) {
V_3 += sprintf ( V_1 , L_1 , V_2 + 12 ) ;
} else {
V_3 += sprintf ( V_3 , L_2 , V_2 ) ;
}
V_3 += sprintf ( V_3 , L_3 ) ;
return V_3 - V_1 ;
}
static T_1 F_2 ( char * V_3 , int V_4 , char * V_1 )
{
return sprintf ( V_3 , L_4 , V_4 , V_1 ) ;
}
static int F_3 ( char * V_5 , struct V_6 * V_7 , int V_8 , int V_9 )
{
if ( V_7 -> V_8 != V_8 ) {
F_4 ( V_10 L_5 \
L_6 \
L_7 , V_5 , V_8 , V_7 -> V_8 ) ;
return - V_11 ;
}
if ( V_7 -> V_9 != V_9 ) {
F_4 ( V_10 L_5 \
L_8 \
L_7 , V_5 , V_9 , V_7 -> V_9 ) ;
return - V_11 ;
}
return 0 ;
}
static T_1 F_5 ( void * V_12 , int type , char * V_1 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 = V_14 -> V_16 ;
void * V_17 = V_14 -> V_18 ;
char * V_3 = V_1 ;
if ( ! V_16 )
return 0 ;
switch ( type ) {
case V_19 :
V_3 += sprintf ( V_3 , L_9 , V_16 -> V_7 . V_20 ) ;
break;
case V_21 :
V_3 += sprintf ( V_3 , L_9 , V_16 -> V_7 . V_22 ) ;
break;
case V_23 :
V_3 += F_1 ( V_3 , V_16 -> V_24 ) ;
break;
case V_25 :
V_3 += F_1 ( V_3 , V_16 -> V_26 ) ;
break;
case V_27 :
V_3 += F_1 ( V_3 , V_16 -> V_28 ) ;
break;
case V_29 :
V_3 += F_1 ( V_3 , V_16 -> V_30 ) ;
break;
case V_31 :
V_3 += F_2 ( V_3 , V_16 -> V_32 ,
( char * ) V_17 +
V_16 -> V_33 ) ;
break;
default:
break;
}
return V_3 - V_1 ;
}
static T_1 F_6 ( void * V_12 , int type , char * V_1 )
{
struct V_13 * V_14 = V_12 ;
struct V_34 * V_35 = V_14 -> V_35 ;
void * V_17 = V_14 -> V_18 ;
char * V_3 = V_1 ;
T_3 V_36 ;
if ( ! V_35 )
return 0 ;
switch ( type ) {
case V_37 :
V_3 += sprintf ( V_3 , L_9 , V_35 -> V_7 . V_20 ) ;
break;
case V_38 :
V_3 += sprintf ( V_3 , L_9 , V_35 -> V_7 . V_22 ) ;
break;
case V_39 :
V_3 += F_1 ( V_3 , V_35 -> V_40 ) ;
break;
case V_41 :
V_36 = F_7 ( ~ ( ( 1 << ( 32 - V_35 -> V_42 ) ) - 1 ) ) ;
V_3 += sprintf ( V_3 , L_1 , & V_36 ) ;
break;
case V_43 :
V_3 += sprintf ( V_3 , L_9 , V_35 -> V_44 ) ;
break;
case V_45 :
V_3 += F_1 ( V_3 , V_35 -> V_46 ) ;
break;
case V_47 :
V_3 += F_1 ( V_3 , V_35 -> V_48 ) ;
break;
case V_49 :
V_3 += F_1 ( V_3 , V_35 -> V_50 ) ;
break;
case V_51 :
V_3 += F_1 ( V_3 , V_35 -> V_52 ) ;
break;
case V_53 :
V_3 += sprintf ( V_3 , L_9 , V_35 -> V_54 ) ;
break;
case V_55 :
V_3 += sprintf ( V_3 , L_10 , V_35 -> V_56 ) ;
break;
case V_57 :
V_3 += F_2 ( V_3 , V_35 -> V_58 ,
( char * ) V_17 + V_35 -> V_59 ) ;
break;
default:
break;
}
return V_3 - V_1 ;
}
static T_1 F_8 ( void * V_12 , int type , char * V_1 )
{
struct V_13 * V_14 = V_12 ;
struct V_60 * V_61 = V_14 -> V_61 ;
void * V_17 = V_14 -> V_18 ;
char * V_3 = V_1 ;
int V_62 ;
if ( ! V_61 )
return 0 ;
switch ( type ) {
case V_63 :
V_3 += sprintf ( V_3 , L_9 , V_61 -> V_7 . V_20 ) ;
break;
case V_64 :
V_3 += sprintf ( V_3 , L_9 , V_61 -> V_7 . V_22 ) ;
break;
case V_65 :
V_3 += F_1 ( V_3 , V_61 -> V_40 ) ;
break;
case V_66 :
V_3 += sprintf ( V_3 , L_9 , V_61 -> V_67 ) ;
break;
case V_68 :
for ( V_62 = 0 ; V_62 < 8 ; V_62 ++ )
V_3 += sprintf ( V_3 , L_11 , ( T_2 ) V_61 -> V_69 [ V_62 ] ) ;
V_3 += sprintf ( V_3 , L_3 ) ;
break;
case V_70 :
V_3 += sprintf ( V_3 , L_9 , V_61 -> V_71 ) ;
break;
case V_72 :
V_3 += sprintf ( V_3 , L_9 , V_61 -> V_73 ) ;
break;
case V_74 :
V_3 += F_2 ( V_3 , V_61 -> V_75 ,
( char * ) V_17 + V_61 -> V_76 ) ;
break;
case V_77 :
V_3 += F_2 ( V_3 , V_61 -> V_78 ,
( char * ) V_17 + V_61 -> V_79 ) ;
break;
case V_80 :
V_3 += F_2 ( V_3 , V_61 -> V_81 ,
( char * ) V_17 + V_61 -> V_82 ) ;
break;
case V_83 :
V_3 += F_2 ( V_3 , V_61 -> V_84 ,
( char * ) V_17 +
V_61 -> V_85 ) ;
break;
case V_86 :
V_3 += F_2 ( V_3 , V_61 -> V_87 ,
( char * ) V_17 +
V_61 -> V_88 ) ;
break;
default:
break;
}
return V_3 - V_1 ;
}
static int T_4 F_9 ( void )
{
int V_4 ;
T_2 * V_89 ;
T_2 V_90 = 0 ;
V_4 = V_91 -> V_18 . V_9 ;
if ( V_91 -> V_18 . V_92 != 1 ) {
F_4 ( V_10 L_12 \
L_13 ,
V_91 -> V_18 . V_92 ) ;
return - V_93 ;
}
for ( V_89 = ( T_2 * ) V_91 ; V_89 < ( T_2 * ) V_91 + V_4 ; V_89 ++ )
V_90 += * V_89 ;
if ( V_90 ) {
F_4 ( V_10 L_14 , V_90 ) ;
return - V_93 ;
}
return 0 ;
}
static T_5 F_10 ( void * V_12 , int type )
{
struct V_13 * V_14 = V_12 ;
struct V_34 * V_35 = V_14 -> V_35 ;
T_5 V_94 = 0 ;
switch ( type ) {
case V_37 :
case V_38 :
V_94 = V_95 ;
break;
case V_39 :
if ( memcmp ( V_35 -> V_40 , V_96 , sizeof( V_35 -> V_40 ) ) )
V_94 = V_95 ;
break;
case V_41 :
if ( V_35 -> V_42 )
V_94 = V_95 ;
break;
case V_43 :
V_94 = V_95 ;
break;
case V_45 :
if ( memcmp ( V_35 -> V_46 , V_96 , sizeof( V_35 -> V_46 ) ) )
V_94 = V_95 ;
break;
case V_47 :
if ( memcmp ( V_35 -> V_48 , V_96 ,
sizeof( V_35 -> V_48 ) ) )
V_94 = V_95 ;
break;
case V_49 :
if ( memcmp ( V_35 -> V_50 , V_96 ,
sizeof( V_35 -> V_50 ) ) )
V_94 = V_95 ;
break;
case V_51 :
if ( memcmp ( V_35 -> V_52 , V_96 , sizeof( V_35 -> V_52 ) ) )
V_94 = V_95 ;
break;
case V_53 :
case V_55 :
V_94 = V_95 ;
break;
case V_57 :
if ( V_35 -> V_59 )
V_94 = V_95 ;
break;
default:
break;
}
return V_94 ;
}
static T_5 T_4 F_11 ( void * V_12 , int type )
{
struct V_13 * V_14 = V_12 ;
struct V_60 * V_61 = V_14 -> V_61 ;
T_5 V_94 = 0 ;
switch ( type ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_68 :
case V_70 :
case V_72 :
V_94 = V_95 ;
case V_74 :
if ( V_61 -> V_75 )
V_94 = V_95 ;
break;
case V_77 :
case V_80 :
if ( V_61 -> V_78 )
V_94 = V_95 ;
break;
case V_83 :
case V_86 :
if ( V_61 -> V_84 )
V_94 = V_95 ;
break;
default:
break;
}
return V_94 ;
}
static T_5 T_4 F_12 ( void * V_12 , int type )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_97 = V_14 -> V_16 ;
T_5 V_94 = 0 ;
switch ( type ) {
case V_19 :
case V_21 :
V_94 = V_95 ;
break;
case V_23 :
if ( memcmp ( V_97 -> V_24 , V_96 ,
sizeof( V_97 -> V_24 ) ) )
V_94 = V_95 ;
break;
case V_25 :
if ( memcmp ( V_97 -> V_26 , V_96 ,
sizeof( V_97 -> V_26 ) ) )
V_94 = V_95 ;
break;
case V_27 :
if ( memcmp ( V_97 -> V_28 , V_96 ,
sizeof( V_97 -> V_28 ) ) )
V_94 = V_95 ;
break;
case V_29 :
if ( memcmp ( V_97 -> V_30 , V_96 ,
sizeof( V_97 -> V_30 ) ) )
V_94 = V_95 ;
break;
case V_31 :
if ( V_97 -> V_32 )
V_94 = V_95 ;
break;
default:
break;
}
return V_94 ;
}
static int T_4 F_13 ( struct V_98 * V_18 ,
struct V_6 * V_7 )
{
struct V_99 * V_100 = NULL ;
struct V_13 * V_101 = NULL ;
struct V_34 * V_35 = (struct V_34 * ) V_7 ;
struct V_102 * V_102 ;
int V_94 = 0 ;
V_101 = F_14 ( sizeof( * V_101 ) , V_103 ) ;
if ( ! V_101 )
return - V_104 ;
V_101 -> V_18 = V_18 ;
V_101 -> V_7 = V_7 ;
switch ( V_7 -> V_8 ) {
case V_105 :
V_94 = F_3 ( L_15 , V_7 , V_105 ,
sizeof( * V_101 -> V_16 ) ) ;
if ( V_94 )
break;
V_100 = F_15 ( V_106 , V_7 -> V_20 ,
V_101 ,
F_5 ,
F_12 ) ;
if ( ! V_100 ) {
V_94 = - V_104 ;
goto V_107;
}
break;
case V_108 :
V_94 = F_3 ( L_16 , V_7 , V_108 ,
sizeof( * V_101 -> V_35 ) ) ;
if ( V_94 )
break;
V_100 = F_16 ( V_106 , V_7 -> V_20 ,
V_101 ,
F_6 ,
F_10 ) ;
if ( ! V_100 ) {
V_94 = - V_104 ;
goto V_107;
}
break;
case V_109 :
V_94 = F_3 ( L_17 , V_7 , V_109 ,
sizeof( * V_101 -> V_61 ) ) ;
if ( V_94 )
break;
V_100 = F_17 ( V_106 , V_7 -> V_20 ,
V_101 ,
F_8 ,
F_11 ) ;
if ( ! V_100 ) {
V_94 = - V_104 ;
goto V_107;
}
break;
case V_110 :
case V_111 :
case V_112 :
V_94 = 1 ;
break;
default:
F_4 ( V_10 L_18 \
L_19 , V_7 -> V_8 ,
V_18 -> V_18 . V_113 ) ;
V_94 = 1 ;
break;
}
if ( V_94 ) {
V_94 = 0 ;
goto V_107;
}
if ( V_7 -> V_8 == V_108 ) {
V_102 = F_18 ( ( V_35 -> V_114 & 0xff00 ) >> 8 ,
( V_35 -> V_114 & 0xff ) ) ;
if ( V_102 ) {
V_94 = F_19 ( & V_100 -> V_115 ,
& V_102 -> V_116 . V_115 , L_20 ) ;
F_20 ( V_102 ) ;
}
}
return 0 ;
V_107:
F_21 ( V_101 ) ;
return V_94 ;
}
static int T_4 F_22 ( struct V_98 * V_18 )
{
struct V_117 * V_118 = NULL ;
void * V_119 , * V_120 ;
int V_94 = 0 ;
T_6 V_121 ;
T_6 V_122 ;
V_118 = ( void * ) V_18 + sizeof( * V_18 ) ;
V_120 = ( void * ) V_118 + V_118 -> V_7 . V_9 ;
V_122 = ( void * ) V_18 + V_18 -> V_18 . V_9 - ( void * ) V_118 ;
V_94 = F_3 ( L_21 , (struct V_6 * ) V_118 , V_111 ,
sizeof( * V_118 ) ) ;
V_94 |= ( ( V_118 -> V_7 . V_20 ) ? - V_11 : 0 ) ;
if ( V_94 ) {
F_4 ( V_10 L_22 ) ;
return V_94 ;
}
for ( V_119 = & V_118 -> V_123 ; V_119 < V_120 ; V_119 += sizeof( T_6 ) ) {
V_121 = * ( T_6 * ) V_119 ;
if ( V_121 && V_121 < V_18 -> V_18 . V_9 &&
V_121 < V_122 ) {
V_94 = F_13 ( V_18 ,
( void * ) V_18 + V_121 ) ;
if ( V_94 )
break;
}
}
return V_94 ;
}
static void F_23 ( void )
{
struct V_99 * V_100 , * V_124 ;
struct V_13 * V_101 ;
F_24 (boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list) {
V_101 = V_100 -> V_12 ;
if ( V_101 -> V_7 -> V_8 == V_108 )
F_25 ( & V_100 -> V_115 , L_20 ) ;
} ;
}
static void F_26 ( void )
{
if ( V_106 ) {
F_23 () ;
F_27 ( V_106 ) ;
}
}
static void T_7 F_28 ( void )
{
F_26 () ;
}
static int T_4 F_29 ( void )
{
int V_94 = 0 ;
if ( V_91 ) {
F_4 ( V_125 L_23 ,
( V_126 ) F_30 ( V_91 ) ) ;
V_94 = F_9 () ;
if ( V_94 )
return V_94 ;
V_106 = F_31 ( L_24 ) ;
if ( ! V_106 )
return - V_104 ;
V_94 = F_22 ( V_91 ) ;
if ( V_94 )
goto V_127;
} else
F_4 ( V_125 L_25 ) ;
return 0 ;
V_127:
F_26 () ;
return V_94 ;
}
