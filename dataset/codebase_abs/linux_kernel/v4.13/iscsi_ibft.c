static int F_1 ( T_1 * V_1 )
{
return ( memcmp ( V_1 , V_2 , 16 ) && memcmp ( V_1 , V_3 , 16 ) ) ;
}
static T_2 F_2 ( char * V_4 , T_1 * V_1 )
{
char * V_5 = V_4 ;
if ( V_1 [ 0 ] == 0 && V_1 [ 1 ] == 0 && V_1 [ 2 ] == 0 && V_1 [ 3 ] == 0 &&
V_1 [ 4 ] == 0 && V_1 [ 5 ] == 0 && V_1 [ 6 ] == 0 && V_1 [ 7 ] == 0 &&
V_1 [ 8 ] == 0 && V_1 [ 9 ] == 0 && V_1 [ 10 ] == 0xff && V_1 [ 11 ] == 0xff ) {
V_5 += sprintf ( V_4 , L_1 , V_1 + 12 ) ;
} else {
V_5 += sprintf ( V_5 , L_2 , V_1 ) ;
}
V_5 += sprintf ( V_5 , L_3 ) ;
return V_5 - V_4 ;
}
static T_2 F_3 ( char * V_5 , int V_6 , char * V_4 )
{
return sprintf ( V_5 , L_4 , V_6 , V_4 ) ;
}
static int F_4 ( char * V_7 , struct V_8 * V_9 , int V_10 , int V_11 )
{
if ( V_9 -> V_10 != V_10 ) {
F_5 ( V_12 L_5 \
L_6 \
L_7 , V_7 , V_10 , V_9 -> V_10 ) ;
return - V_13 ;
}
if ( V_9 -> V_11 != V_11 ) {
F_5 ( V_12 L_5 \
L_8 \
L_7 , V_7 , V_11 , V_9 -> V_11 ) ;
return - V_13 ;
}
return 0 ;
}
static T_2 F_6 ( void * V_14 , int type , char * V_4 )
{
struct V_15 * V_16 = V_14 ;
struct V_17 * V_18 = V_16 -> V_18 ;
void * V_19 = V_16 -> V_20 ;
char * V_5 = V_4 ;
if ( ! V_18 )
return 0 ;
switch ( type ) {
case V_21 :
V_5 += sprintf ( V_5 , L_9 , V_18 -> V_9 . V_22 ) ;
break;
case V_23 :
V_5 += sprintf ( V_5 , L_9 , V_18 -> V_9 . V_24 ) ;
break;
case V_25 :
V_5 += F_2 ( V_5 , V_18 -> V_26 ) ;
break;
case V_27 :
V_5 += F_2 ( V_5 , V_18 -> V_28 ) ;
break;
case V_29 :
V_5 += F_2 ( V_5 , V_18 -> V_30 ) ;
break;
case V_31 :
V_5 += F_2 ( V_5 , V_18 -> V_32 ) ;
break;
case V_33 :
V_5 += F_3 ( V_5 , V_18 -> V_34 ,
( char * ) V_19 +
V_18 -> V_35 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static T_2 F_7 ( void * V_14 , int type , char * V_4 )
{
struct V_15 * V_16 = V_14 ;
struct V_36 * V_37 = V_16 -> V_37 ;
void * V_19 = V_16 -> V_20 ;
char * V_5 = V_4 ;
T_3 V_38 ;
if ( ! V_37 )
return 0 ;
switch ( type ) {
case V_39 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_9 . V_22 ) ;
break;
case V_40 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_9 . V_24 ) ;
break;
case V_41 :
V_5 += F_2 ( V_5 , V_37 -> V_42 ) ;
break;
case V_43 :
V_38 = F_8 ( ~ ( ( 1 << ( 32 - V_37 -> V_44 ) ) - 1 ) ) ;
V_5 += sprintf ( V_5 , L_1 , & V_38 ) ;
break;
case V_45 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_44 ) ;
break;
case V_46 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_47 ) ;
break;
case V_48 :
V_5 += F_2 ( V_5 , V_37 -> V_49 ) ;
break;
case V_50 :
V_5 += F_2 ( V_5 , V_37 -> V_51 ) ;
break;
case V_52 :
V_5 += F_2 ( V_5 , V_37 -> V_53 ) ;
break;
case V_54 :
V_5 += F_2 ( V_5 , V_37 -> V_55 ) ;
break;
case V_56 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_57 ) ;
break;
case V_58 :
V_5 += sprintf ( V_5 , L_10 , V_37 -> V_59 ) ;
break;
case V_60 :
V_5 += F_3 ( V_5 , V_37 -> V_61 ,
( char * ) V_19 + V_37 -> V_62 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static T_2 F_9 ( void * V_14 , int type , char * V_4 )
{
struct V_15 * V_16 = V_14 ;
struct V_63 * V_64 = V_16 -> V_64 ;
void * V_19 = V_16 -> V_20 ;
char * V_5 = V_4 ;
int V_65 ;
if ( ! V_64 )
return 0 ;
switch ( type ) {
case V_66 :
V_5 += sprintf ( V_5 , L_9 , V_64 -> V_9 . V_22 ) ;
break;
case V_67 :
V_5 += sprintf ( V_5 , L_9 , V_64 -> V_9 . V_24 ) ;
break;
case V_68 :
V_5 += F_2 ( V_5 , V_64 -> V_42 ) ;
break;
case V_69 :
V_5 += sprintf ( V_5 , L_9 , V_64 -> V_70 ) ;
break;
case V_71 :
for ( V_65 = 0 ; V_65 < 8 ; V_65 ++ )
V_5 += sprintf ( V_5 , L_11 , ( T_1 ) V_64 -> V_72 [ V_65 ] ) ;
V_5 += sprintf ( V_5 , L_3 ) ;
break;
case V_73 :
V_5 += sprintf ( V_5 , L_9 , V_64 -> V_74 ) ;
break;
case V_75 :
V_5 += sprintf ( V_5 , L_9 , V_64 -> V_76 ) ;
break;
case V_77 :
V_5 += F_3 ( V_5 , V_64 -> V_78 ,
( char * ) V_19 + V_64 -> V_79 ) ;
break;
case V_80 :
V_5 += F_3 ( V_5 , V_64 -> V_81 ,
( char * ) V_19 + V_64 -> V_82 ) ;
break;
case V_83 :
V_5 += F_3 ( V_5 , V_64 -> V_84 ,
( char * ) V_19 + V_64 -> V_85 ) ;
break;
case V_86 :
V_5 += F_3 ( V_5 , V_64 -> V_87 ,
( char * ) V_19 +
V_64 -> V_88 ) ;
break;
case V_89 :
V_5 += F_3 ( V_5 , V_64 -> V_90 ,
( char * ) V_19 +
V_64 -> V_91 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static T_2 F_10 ( void * V_14 , int type , char * V_4 )
{
struct V_15 * V_16 = V_14 ;
char * V_5 = V_4 ;
switch ( type ) {
case V_92 :
V_5 += F_3 ( V_5 , V_93 ,
V_16 -> V_20 -> V_20 . V_94 ) ;
break;
case V_95 :
V_5 += F_3 ( V_5 , V_96 ,
V_16 -> V_20 -> V_20 . V_97 ) ;
break;
case V_98 :
V_5 += F_3 ( V_5 , V_99 ,
V_16 -> V_20 -> V_20 . V_100 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static int T_4 F_11 ( void )
{
int V_6 ;
T_1 * V_101 ;
T_1 V_102 = 0 ;
V_6 = V_103 -> V_20 . V_11 ;
if ( V_103 -> V_20 . V_104 != 1 ) {
F_5 ( V_12 L_12 \
L_13 ,
V_103 -> V_20 . V_104 ) ;
return - V_105 ;
}
for ( V_101 = ( T_1 * ) V_103 ; V_101 < ( T_1 * ) V_103 + V_6 ; V_101 ++ )
V_102 += * V_101 ;
if ( V_102 ) {
F_5 ( V_12 L_14 , V_102 ) ;
return - V_105 ;
}
return 0 ;
}
static T_5 F_12 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_36 * V_37 = V_16 -> V_37 ;
T_5 V_106 = 0 ;
switch ( type ) {
case V_39 :
case V_40 :
V_106 = V_107 ;
break;
case V_41 :
if ( F_1 ( V_37 -> V_42 ) )
V_106 = V_107 ;
break;
case V_45 :
case V_43 :
if ( V_37 -> V_44 )
V_106 = V_107 ;
break;
case V_46 :
V_106 = V_107 ;
break;
case V_48 :
if ( F_1 ( V_37 -> V_49 ) )
V_106 = V_107 ;
break;
case V_50 :
if ( F_1 ( V_37 -> V_51 ) )
V_106 = V_107 ;
break;
case V_52 :
if ( F_1 ( V_37 -> V_53 ) )
V_106 = V_107 ;
break;
case V_54 :
if ( F_1 ( V_37 -> V_55 ) )
V_106 = V_107 ;
break;
case V_56 :
case V_58 :
V_106 = V_107 ;
break;
case V_60 :
if ( V_37 -> V_62 )
V_106 = V_107 ;
break;
default:
break;
}
return V_106 ;
}
static T_5 T_4 F_13 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_63 * V_64 = V_16 -> V_64 ;
T_5 V_106 = 0 ;
switch ( type ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_71 :
case V_73 :
case V_75 :
V_106 = V_107 ;
case V_77 :
if ( V_64 -> V_78 )
V_106 = V_107 ;
break;
case V_80 :
case V_83 :
if ( V_64 -> V_81 )
V_106 = V_107 ;
break;
case V_86 :
case V_89 :
if ( V_64 -> V_87 )
V_106 = V_107 ;
break;
default:
break;
}
return V_106 ;
}
static T_5 T_4 F_14 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_17 * V_108 = V_16 -> V_18 ;
T_5 V_106 = 0 ;
switch ( type ) {
case V_21 :
case V_23 :
V_106 = V_107 ;
break;
case V_25 :
if ( F_1 ( V_108 -> V_26 ) )
V_106 = V_107 ;
break;
case V_27 :
if ( F_1 ( V_108 -> V_28 ) )
V_106 = V_107 ;
break;
case V_29 :
if ( F_1 ( V_108 -> V_30 ) )
V_106 = V_107 ;
break;
case V_31 :
if ( F_1 ( V_108 -> V_32 ) )
V_106 = V_107 ;
break;
case V_33 :
if ( V_108 -> V_34 )
V_106 = V_107 ;
break;
default:
break;
}
return V_106 ;
}
static T_5 T_4 F_15 ( void * V_14 , int type )
{
T_5 V_106 = 0 ;
switch ( type ) {
case V_92 :
case V_95 :
case V_98 :
V_106 = V_107 ;
break;
default:
break;
}
return V_106 ;
}
static void F_16 ( void * V_14 )
{
F_17 ( V_14 ) ;
}
static int T_4 F_18 ( struct V_109 * V_20 ,
struct V_8 * V_9 )
{
struct V_110 * V_111 = NULL ;
struct V_15 * V_112 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_9 ;
struct V_113 * V_113 ;
int V_106 = 0 ;
V_112 = F_19 ( sizeof( * V_112 ) , V_114 ) ;
if ( ! V_112 )
return - V_115 ;
V_112 -> V_20 = V_20 ;
V_112 -> V_9 = V_9 ;
switch ( V_9 -> V_10 ) {
case V_116 :
V_106 = F_4 ( L_15 , V_9 , V_116 ,
sizeof( * V_112 -> V_18 ) ) ;
if ( V_106 )
break;
V_111 = F_20 ( V_117 , V_9 -> V_22 ,
V_112 ,
F_6 ,
F_14 ,
F_16 ) ;
if ( ! V_111 ) {
V_106 = - V_115 ;
goto V_118;
}
break;
case V_119 :
V_106 = F_4 ( L_16 , V_9 , V_119 ,
sizeof( * V_112 -> V_37 ) ) ;
if ( V_106 )
break;
V_111 = F_21 ( V_117 , V_9 -> V_22 ,
V_112 ,
F_7 ,
F_12 ,
F_16 ) ;
if ( ! V_111 ) {
V_106 = - V_115 ;
goto V_118;
}
break;
case V_120 :
V_106 = F_4 ( L_17 , V_9 , V_120 ,
sizeof( * V_112 -> V_64 ) ) ;
if ( V_106 )
break;
V_111 = F_22 ( V_117 , V_9 -> V_22 ,
V_112 ,
F_9 ,
F_13 ,
F_16 ) ;
if ( ! V_111 ) {
V_106 = - V_115 ;
goto V_118;
}
break;
case V_121 :
case V_122 :
case V_123 :
V_106 = 1 ;
break;
default:
F_5 ( V_12 L_18 \
L_19 , V_9 -> V_10 ,
V_20 -> V_20 . V_97 ) ;
V_106 = 1 ;
break;
}
if ( V_106 ) {
V_106 = 0 ;
goto V_118;
}
if ( V_9 -> V_10 == V_119 ) {
V_113 = F_23 ( ( V_37 -> V_124 & 0xff00 ) >> 8 ,
( V_37 -> V_124 & 0xff ) ) ;
if ( V_113 ) {
V_106 = F_24 ( & V_111 -> V_125 ,
& V_113 -> V_126 . V_125 , L_20 ) ;
F_25 ( V_113 ) ;
}
}
return 0 ;
V_118:
F_17 ( V_112 ) ;
return V_106 ;
}
static int T_4 F_26 ( struct V_109 * V_20 )
{
struct V_127 * V_128 = NULL ;
struct V_110 * V_111 ;
struct V_15 * V_112 ;
void * V_129 , * V_130 ;
int V_106 = 0 ;
T_6 V_131 ;
T_6 V_132 ;
V_128 = ( void * ) V_20 + sizeof( * V_20 ) ;
V_130 = ( void * ) V_128 + V_128 -> V_9 . V_11 ;
V_132 = ( void * ) V_20 + V_20 -> V_20 . V_11 - ( void * ) V_128 ;
V_106 = F_4 ( L_21 , (struct V_8 * ) V_128 , V_122 ,
sizeof( * V_128 ) ) ;
V_106 |= ( ( V_128 -> V_9 . V_22 ) ? - V_13 : 0 ) ;
if ( V_106 ) {
F_5 ( V_12 L_22 ) ;
return V_106 ;
}
for ( V_129 = & V_128 -> V_133 ; V_129 < V_130 ; V_129 += sizeof( T_6 ) ) {
V_131 = * ( T_6 * ) V_129 ;
if ( V_131 && V_131 < V_20 -> V_20 . V_11 &&
V_131 < V_132 ) {
V_106 = F_18 ( V_20 ,
( void * ) V_20 + V_131 ) ;
if ( V_106 )
break;
}
}
if ( V_106 )
return V_106 ;
V_112 = F_19 ( sizeof( * V_112 ) , V_114 ) ;
if ( ! V_112 )
return - V_115 ;
V_112 -> V_20 = V_20 ;
V_112 -> V_9 = NULL ;
V_111 = F_27 ( V_117 , 0 ,
V_112 ,
F_10 ,
F_15 ,
F_16 ) ;
if ( ! V_111 ) {
F_17 ( V_112 ) ;
V_106 = - V_115 ;
}
return V_106 ;
}
static void F_28 ( void )
{
struct V_110 * V_111 , * V_134 ;
struct V_15 * V_112 ;
F_29 (boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list) {
V_112 = V_111 -> V_14 ;
if ( V_112 -> V_9 && V_112 -> V_9 -> V_10 == V_119 )
F_30 ( & V_111 -> V_125 , L_20 ) ;
} ;
}
static void F_31 ( void )
{
if ( V_117 ) {
F_28 () ;
F_32 ( V_117 ) ;
}
}
static void T_7 F_33 ( void )
{
F_31 () ;
}
static void T_4 F_34 ( void )
{
int V_65 ;
struct V_135 * V_136 = NULL ;
if ( V_137 )
return;
for ( V_65 = 0 ; V_65 < F_35 ( V_138 ) && ! V_103 ; V_65 ++ ) {
F_36 ( V_138 [ V_65 ] . V_139 , 0 , & V_136 ) ;
V_103 = (struct V_109 * ) V_136 ;
}
}
static void T_4 F_34 ( void )
{
}
static int T_4 F_37 ( void )
{
int V_106 = 0 ;
if ( ! V_103 )
F_34 () ;
if ( V_103 ) {
F_38 ( L_23 ) ;
V_106 = F_11 () ;
if ( V_106 )
return V_106 ;
V_117 = F_39 ( L_24 ) ;
if ( ! V_117 )
return - V_115 ;
V_106 = F_26 ( V_103 ) ;
if ( V_106 )
goto V_140;
} else
F_5 ( V_141 L_25 ) ;
return 0 ;
V_140:
F_31 () ;
return V_106 ;
}
