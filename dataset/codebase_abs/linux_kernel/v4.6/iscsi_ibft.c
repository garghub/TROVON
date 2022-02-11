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
static int T_4 F_10 ( void )
{
int V_6 ;
T_1 * V_92 ;
T_1 V_93 = 0 ;
V_6 = V_94 -> V_20 . V_11 ;
if ( V_94 -> V_20 . V_95 != 1 ) {
F_5 ( V_12 L_12 \
L_13 ,
V_94 -> V_20 . V_95 ) ;
return - V_96 ;
}
for ( V_92 = ( T_1 * ) V_94 ; V_92 < ( T_1 * ) V_94 + V_6 ; V_92 ++ )
V_93 += * V_92 ;
if ( V_93 ) {
F_5 ( V_12 L_14 , V_93 ) ;
return - V_96 ;
}
return 0 ;
}
static T_5 F_11 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_36 * V_37 = V_16 -> V_37 ;
T_5 V_97 = 0 ;
switch ( type ) {
case V_39 :
case V_40 :
V_97 = V_98 ;
break;
case V_41 :
if ( F_1 ( V_37 -> V_42 ) )
V_97 = V_98 ;
break;
case V_45 :
case V_43 :
if ( V_37 -> V_44 )
V_97 = V_98 ;
break;
case V_46 :
V_97 = V_98 ;
break;
case V_48 :
if ( F_1 ( V_37 -> V_49 ) )
V_97 = V_98 ;
break;
case V_50 :
if ( F_1 ( V_37 -> V_51 ) )
V_97 = V_98 ;
break;
case V_52 :
if ( F_1 ( V_37 -> V_53 ) )
V_97 = V_98 ;
break;
case V_54 :
if ( F_1 ( V_37 -> V_55 ) )
V_97 = V_98 ;
break;
case V_56 :
case V_58 :
V_97 = V_98 ;
break;
case V_60 :
if ( V_37 -> V_62 )
V_97 = V_98 ;
break;
default:
break;
}
return V_97 ;
}
static T_5 T_4 F_12 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_63 * V_64 = V_16 -> V_64 ;
T_5 V_97 = 0 ;
switch ( type ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_71 :
case V_73 :
case V_75 :
V_97 = V_98 ;
case V_77 :
if ( V_64 -> V_78 )
V_97 = V_98 ;
break;
case V_80 :
case V_83 :
if ( V_64 -> V_81 )
V_97 = V_98 ;
break;
case V_86 :
case V_89 :
if ( V_64 -> V_87 )
V_97 = V_98 ;
break;
default:
break;
}
return V_97 ;
}
static T_5 T_4 F_13 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_17 * V_99 = V_16 -> V_18 ;
T_5 V_97 = 0 ;
switch ( type ) {
case V_21 :
case V_23 :
V_97 = V_98 ;
break;
case V_25 :
if ( F_1 ( V_99 -> V_26 ) )
V_97 = V_98 ;
break;
case V_27 :
if ( F_1 ( V_99 -> V_28 ) )
V_97 = V_98 ;
break;
case V_29 :
if ( F_1 ( V_99 -> V_30 ) )
V_97 = V_98 ;
break;
case V_31 :
if ( F_1 ( V_99 -> V_32 ) )
V_97 = V_98 ;
break;
case V_33 :
if ( V_99 -> V_34 )
V_97 = V_98 ;
break;
default:
break;
}
return V_97 ;
}
static void F_14 ( void * V_14 )
{
F_15 ( V_14 ) ;
}
static int T_4 F_16 ( struct V_100 * V_20 ,
struct V_8 * V_9 )
{
struct V_101 * V_102 = NULL ;
struct V_15 * V_103 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_9 ;
struct V_104 * V_104 ;
int V_97 = 0 ;
V_103 = F_17 ( sizeof( * V_103 ) , V_105 ) ;
if ( ! V_103 )
return - V_106 ;
V_103 -> V_20 = V_20 ;
V_103 -> V_9 = V_9 ;
switch ( V_9 -> V_10 ) {
case V_107 :
V_97 = F_4 ( L_15 , V_9 , V_107 ,
sizeof( * V_103 -> V_18 ) ) ;
if ( V_97 )
break;
V_102 = F_18 ( V_108 , V_9 -> V_22 ,
V_103 ,
F_6 ,
F_13 ,
F_14 ) ;
if ( ! V_102 ) {
V_97 = - V_106 ;
goto V_109;
}
break;
case V_110 :
V_97 = F_4 ( L_16 , V_9 , V_110 ,
sizeof( * V_103 -> V_37 ) ) ;
if ( V_97 )
break;
V_102 = F_19 ( V_108 , V_9 -> V_22 ,
V_103 ,
F_7 ,
F_11 ,
F_14 ) ;
if ( ! V_102 ) {
V_97 = - V_106 ;
goto V_109;
}
break;
case V_111 :
V_97 = F_4 ( L_17 , V_9 , V_111 ,
sizeof( * V_103 -> V_64 ) ) ;
if ( V_97 )
break;
V_102 = F_20 ( V_108 , V_9 -> V_22 ,
V_103 ,
F_9 ,
F_12 ,
F_14 ) ;
if ( ! V_102 ) {
V_97 = - V_106 ;
goto V_109;
}
break;
case V_112 :
case V_113 :
case V_114 :
V_97 = 1 ;
break;
default:
F_5 ( V_12 L_18 \
L_19 , V_9 -> V_10 ,
V_20 -> V_20 . V_115 ) ;
V_97 = 1 ;
break;
}
if ( V_97 ) {
V_97 = 0 ;
goto V_109;
}
if ( V_9 -> V_10 == V_110 ) {
V_104 = F_21 ( ( V_37 -> V_116 & 0xff00 ) >> 8 ,
( V_37 -> V_116 & 0xff ) ) ;
if ( V_104 ) {
V_97 = F_22 ( & V_102 -> V_117 ,
& V_104 -> V_118 . V_117 , L_20 ) ;
F_23 ( V_104 ) ;
}
}
return 0 ;
V_109:
F_15 ( V_103 ) ;
return V_97 ;
}
static int T_4 F_24 ( struct V_100 * V_20 )
{
struct V_119 * V_120 = NULL ;
void * V_121 , * V_122 ;
int V_97 = 0 ;
T_6 V_123 ;
T_6 V_124 ;
V_120 = ( void * ) V_20 + sizeof( * V_20 ) ;
V_122 = ( void * ) V_120 + V_120 -> V_9 . V_11 ;
V_124 = ( void * ) V_20 + V_20 -> V_20 . V_11 - ( void * ) V_120 ;
V_97 = F_4 ( L_21 , (struct V_8 * ) V_120 , V_113 ,
sizeof( * V_120 ) ) ;
V_97 |= ( ( V_120 -> V_9 . V_22 ) ? - V_13 : 0 ) ;
if ( V_97 ) {
F_5 ( V_12 L_22 ) ;
return V_97 ;
}
for ( V_121 = & V_120 -> V_125 ; V_121 < V_122 ; V_121 += sizeof( T_6 ) ) {
V_123 = * ( T_6 * ) V_121 ;
if ( V_123 && V_123 < V_20 -> V_20 . V_11 &&
V_123 < V_124 ) {
V_97 = F_16 ( V_20 ,
( void * ) V_20 + V_123 ) ;
if ( V_97 )
break;
}
}
return V_97 ;
}
static void F_25 ( void )
{
struct V_101 * V_102 , * V_126 ;
struct V_15 * V_103 ;
F_26 (boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list) {
V_103 = V_102 -> V_14 ;
if ( V_103 -> V_9 -> V_10 == V_110 )
F_27 ( & V_102 -> V_117 , L_20 ) ;
} ;
}
static void F_28 ( void )
{
if ( V_108 ) {
F_25 () ;
F_29 ( V_108 ) ;
}
}
static void T_7 F_30 ( void )
{
F_28 () ;
}
static void T_4 F_31 ( void )
{
int V_65 ;
struct V_127 * V_128 = NULL ;
if ( V_129 )
return;
for ( V_65 = 0 ; V_65 < F_32 ( V_130 ) && ! V_94 ; V_65 ++ ) {
F_33 ( V_130 [ V_65 ] . V_131 , 0 , & V_128 ) ;
V_94 = (struct V_100 * ) V_128 ;
}
}
static void T_4 F_31 ( void )
{
}
static int T_4 F_34 ( void )
{
int V_97 = 0 ;
if ( ! V_94 )
F_31 () ;
if ( V_94 ) {
F_35 ( L_23 ) ;
V_97 = F_10 () ;
if ( V_97 )
return V_97 ;
V_108 = F_36 ( L_24 ) ;
if ( ! V_108 )
return - V_106 ;
V_97 = F_24 ( V_94 ) ;
if ( V_97 )
goto V_132;
} else
F_5 ( V_133 L_25 ) ;
return 0 ;
V_132:
F_28 () ;
return V_97 ;
}
