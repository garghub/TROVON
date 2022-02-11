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
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_46 ) ;
break;
case V_47 :
V_5 += F_2 ( V_5 , V_37 -> V_48 ) ;
break;
case V_49 :
V_5 += F_2 ( V_5 , V_37 -> V_50 ) ;
break;
case V_51 :
V_5 += F_2 ( V_5 , V_37 -> V_52 ) ;
break;
case V_53 :
V_5 += F_2 ( V_5 , V_37 -> V_54 ) ;
break;
case V_55 :
V_5 += sprintf ( V_5 , L_9 , V_37 -> V_56 ) ;
break;
case V_57 :
V_5 += sprintf ( V_5 , L_10 , V_37 -> V_58 ) ;
break;
case V_59 :
V_5 += F_3 ( V_5 , V_37 -> V_60 ,
( char * ) V_19 + V_37 -> V_61 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static T_2 F_9 ( void * V_14 , int type , char * V_4 )
{
struct V_15 * V_16 = V_14 ;
struct V_62 * V_63 = V_16 -> V_63 ;
void * V_19 = V_16 -> V_20 ;
char * V_5 = V_4 ;
int V_64 ;
if ( ! V_63 )
return 0 ;
switch ( type ) {
case V_65 :
V_5 += sprintf ( V_5 , L_9 , V_63 -> V_9 . V_22 ) ;
break;
case V_66 :
V_5 += sprintf ( V_5 , L_9 , V_63 -> V_9 . V_24 ) ;
break;
case V_67 :
V_5 += F_2 ( V_5 , V_63 -> V_42 ) ;
break;
case V_68 :
V_5 += sprintf ( V_5 , L_9 , V_63 -> V_69 ) ;
break;
case V_70 :
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ )
V_5 += sprintf ( V_5 , L_11 , ( T_1 ) V_63 -> V_71 [ V_64 ] ) ;
V_5 += sprintf ( V_5 , L_3 ) ;
break;
case V_72 :
V_5 += sprintf ( V_5 , L_9 , V_63 -> V_73 ) ;
break;
case V_74 :
V_5 += sprintf ( V_5 , L_9 , V_63 -> V_75 ) ;
break;
case V_76 :
V_5 += F_3 ( V_5 , V_63 -> V_77 ,
( char * ) V_19 + V_63 -> V_78 ) ;
break;
case V_79 :
V_5 += F_3 ( V_5 , V_63 -> V_80 ,
( char * ) V_19 + V_63 -> V_81 ) ;
break;
case V_82 :
V_5 += F_3 ( V_5 , V_63 -> V_83 ,
( char * ) V_19 + V_63 -> V_84 ) ;
break;
case V_85 :
V_5 += F_3 ( V_5 , V_63 -> V_86 ,
( char * ) V_19 +
V_63 -> V_87 ) ;
break;
case V_88 :
V_5 += F_3 ( V_5 , V_63 -> V_89 ,
( char * ) V_19 +
V_63 -> V_90 ) ;
break;
default:
break;
}
return V_5 - V_4 ;
}
static int T_4 F_10 ( void )
{
int V_6 ;
T_1 * V_91 ;
T_1 V_92 = 0 ;
V_6 = V_93 -> V_20 . V_11 ;
if ( V_93 -> V_20 . V_94 != 1 ) {
F_5 ( V_12 L_12 \
L_13 ,
V_93 -> V_20 . V_94 ) ;
return - V_95 ;
}
for ( V_91 = ( T_1 * ) V_93 ; V_91 < ( T_1 * ) V_93 + V_6 ; V_91 ++ )
V_92 += * V_91 ;
if ( V_92 ) {
F_5 ( V_12 L_14 , V_92 ) ;
return - V_95 ;
}
return 0 ;
}
static T_5 F_11 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_36 * V_37 = V_16 -> V_37 ;
T_5 V_96 = 0 ;
switch ( type ) {
case V_39 :
case V_40 :
V_96 = V_97 ;
break;
case V_41 :
if ( F_1 ( V_37 -> V_42 ) )
V_96 = V_97 ;
break;
case V_43 :
if ( V_37 -> V_44 )
V_96 = V_97 ;
break;
case V_45 :
V_96 = V_97 ;
break;
case V_47 :
if ( F_1 ( V_37 -> V_48 ) )
V_96 = V_97 ;
break;
case V_49 :
if ( F_1 ( V_37 -> V_50 ) )
V_96 = V_97 ;
break;
case V_51 :
if ( F_1 ( V_37 -> V_52 ) )
V_96 = V_97 ;
break;
case V_53 :
if ( F_1 ( V_37 -> V_54 ) )
V_96 = V_97 ;
break;
case V_55 :
case V_57 :
V_96 = V_97 ;
break;
case V_59 :
if ( V_37 -> V_61 )
V_96 = V_97 ;
break;
default:
break;
}
return V_96 ;
}
static T_5 T_4 F_12 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_62 * V_63 = V_16 -> V_63 ;
T_5 V_96 = 0 ;
switch ( type ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_70 :
case V_72 :
case V_74 :
V_96 = V_97 ;
case V_76 :
if ( V_63 -> V_77 )
V_96 = V_97 ;
break;
case V_79 :
case V_82 :
if ( V_63 -> V_80 )
V_96 = V_97 ;
break;
case V_85 :
case V_88 :
if ( V_63 -> V_86 )
V_96 = V_97 ;
break;
default:
break;
}
return V_96 ;
}
static T_5 T_4 F_13 ( void * V_14 , int type )
{
struct V_15 * V_16 = V_14 ;
struct V_17 * V_98 = V_16 -> V_18 ;
T_5 V_96 = 0 ;
switch ( type ) {
case V_21 :
case V_23 :
V_96 = V_97 ;
break;
case V_25 :
if ( F_1 ( V_98 -> V_26 ) )
V_96 = V_97 ;
break;
case V_27 :
if ( F_1 ( V_98 -> V_28 ) )
V_96 = V_97 ;
break;
case V_29 :
if ( F_1 ( V_98 -> V_30 ) )
V_96 = V_97 ;
break;
case V_31 :
if ( F_1 ( V_98 -> V_32 ) )
V_96 = V_97 ;
break;
case V_33 :
if ( V_98 -> V_34 )
V_96 = V_97 ;
break;
default:
break;
}
return V_96 ;
}
static void F_14 ( void * V_14 )
{
F_15 ( V_14 ) ;
}
static int T_4 F_16 ( struct V_99 * V_20 ,
struct V_8 * V_9 )
{
struct V_100 * V_101 = NULL ;
struct V_15 * V_102 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_9 ;
struct V_103 * V_103 ;
int V_96 = 0 ;
V_102 = F_17 ( sizeof( * V_102 ) , V_104 ) ;
if ( ! V_102 )
return - V_105 ;
V_102 -> V_20 = V_20 ;
V_102 -> V_9 = V_9 ;
switch ( V_9 -> V_10 ) {
case V_106 :
V_96 = F_4 ( L_15 , V_9 , V_106 ,
sizeof( * V_102 -> V_18 ) ) ;
if ( V_96 )
break;
V_101 = F_18 ( V_107 , V_9 -> V_22 ,
V_102 ,
F_6 ,
F_13 ,
F_14 ) ;
if ( ! V_101 ) {
V_96 = - V_105 ;
goto V_108;
}
break;
case V_109 :
V_96 = F_4 ( L_16 , V_9 , V_109 ,
sizeof( * V_102 -> V_37 ) ) ;
if ( V_96 )
break;
V_101 = F_19 ( V_107 , V_9 -> V_22 ,
V_102 ,
F_7 ,
F_11 ,
F_14 ) ;
if ( ! V_101 ) {
V_96 = - V_105 ;
goto V_108;
}
break;
case V_110 :
V_96 = F_4 ( L_17 , V_9 , V_110 ,
sizeof( * V_102 -> V_63 ) ) ;
if ( V_96 )
break;
V_101 = F_20 ( V_107 , V_9 -> V_22 ,
V_102 ,
F_9 ,
F_12 ,
F_14 ) ;
if ( ! V_101 ) {
V_96 = - V_105 ;
goto V_108;
}
break;
case V_111 :
case V_112 :
case V_113 :
V_96 = 1 ;
break;
default:
F_5 ( V_12 L_18 \
L_19 , V_9 -> V_10 ,
V_20 -> V_20 . V_114 ) ;
V_96 = 1 ;
break;
}
if ( V_96 ) {
V_96 = 0 ;
goto V_108;
}
if ( V_9 -> V_10 == V_109 ) {
V_103 = F_21 ( ( V_37 -> V_115 & 0xff00 ) >> 8 ,
( V_37 -> V_115 & 0xff ) ) ;
if ( V_103 ) {
V_96 = F_22 ( & V_101 -> V_116 ,
& V_103 -> V_117 . V_116 , L_20 ) ;
F_23 ( V_103 ) ;
}
}
return 0 ;
V_108:
F_15 ( V_102 ) ;
return V_96 ;
}
static int T_4 F_24 ( struct V_99 * V_20 )
{
struct V_118 * V_119 = NULL ;
void * V_120 , * V_121 ;
int V_96 = 0 ;
T_6 V_122 ;
T_6 V_123 ;
V_119 = ( void * ) V_20 + sizeof( * V_20 ) ;
V_121 = ( void * ) V_119 + V_119 -> V_9 . V_11 ;
V_123 = ( void * ) V_20 + V_20 -> V_20 . V_11 - ( void * ) V_119 ;
V_96 = F_4 ( L_21 , (struct V_8 * ) V_119 , V_112 ,
sizeof( * V_119 ) ) ;
V_96 |= ( ( V_119 -> V_9 . V_22 ) ? - V_13 : 0 ) ;
if ( V_96 ) {
F_5 ( V_12 L_22 ) ;
return V_96 ;
}
for ( V_120 = & V_119 -> V_124 ; V_120 < V_121 ; V_120 += sizeof( T_6 ) ) {
V_122 = * ( T_6 * ) V_120 ;
if ( V_122 && V_122 < V_20 -> V_20 . V_11 &&
V_122 < V_123 ) {
V_96 = F_16 ( V_20 ,
( void * ) V_20 + V_122 ) ;
if ( V_96 )
break;
}
}
return V_96 ;
}
static void F_25 ( void )
{
struct V_100 * V_101 , * V_125 ;
struct V_15 * V_102 ;
F_26 (boot_kobj, tmp_kobj,
&boot_kset->kobj_list, list) {
V_102 = V_101 -> V_14 ;
if ( V_102 -> V_9 -> V_10 == V_109 )
F_27 ( & V_101 -> V_116 , L_20 ) ;
} ;
}
static void F_28 ( void )
{
if ( V_107 ) {
F_25 () ;
F_29 ( V_107 ) ;
}
}
static void T_7 F_30 ( void )
{
F_28 () ;
}
static void T_4 F_31 ( void )
{
int V_64 ;
struct V_126 * V_127 = NULL ;
if ( V_128 )
return;
for ( V_64 = 0 ; V_64 < F_32 ( V_129 ) && ! V_93 ; V_64 ++ ) {
F_33 ( V_129 [ V_64 ] . V_130 , 0 , & V_127 ) ;
V_93 = (struct V_99 * ) V_127 ;
}
}
static void T_4 F_31 ( void )
{
}
static int T_4 F_34 ( void )
{
int V_96 = 0 ;
if ( ! V_93 )
F_31 () ;
if ( V_93 ) {
F_35 ( L_23 ) ;
V_96 = F_10 () ;
if ( V_96 )
return V_96 ;
V_107 = F_36 ( L_24 ) ;
if ( ! V_107 )
return - V_105 ;
V_96 = F_24 ( V_93 ) ;
if ( V_96 )
goto V_131;
} else
F_5 ( V_132 L_25 ) ;
return 0 ;
V_131:
F_28 () ;
return V_96 ;
}
