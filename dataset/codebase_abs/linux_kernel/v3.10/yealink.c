static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
if ( V_3 >= F_2 ( V_9 ) )
return - V_10 ;
if ( V_4 == '\t' || V_4 == '\n' )
return 0 ;
V_2 -> V_9 [ V_3 ] = V_4 ;
if ( V_9 [ V_3 ] . type == '.' ) {
V_6 = V_9 [ V_3 ] . V_11 . V_12 . V_6 ;
V_7 = V_9 [ V_3 ] . V_11 . V_12 . V_7 ;
if ( V_4 != ' ' )
V_2 -> V_13 . V_14 [ V_6 ] |= V_7 ;
else
V_2 -> V_13 . V_14 [ V_6 ] &= ~ V_7 ;
return 0 ;
}
V_8 = F_3 ( & V_15 , V_4 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_9 [ 0 ] . V_11 . V_16 ) ; V_5 ++ ) {
V_7 = V_9 [ V_3 ] . V_11 . V_16 [ V_5 ] . V_7 ;
if ( V_7 == 0 )
continue;
V_6 = V_9 [ V_3 ] . V_11 . V_16 [ V_5 ] . V_6 ;
if ( V_8 & 1 )
V_2 -> V_13 . V_14 [ V_6 ] |= V_7 ;
else
V_2 -> V_13 . V_14 [ V_6 ] &= ~ V_7 ;
V_8 = V_8 >> 1 ;
}
return 0 ;
}
static int F_4 ( int V_17 )
{
switch( V_17 ) {
case 0x23 : return V_18 ;
case 0x33 : return V_19 ;
case 0x04 : return V_20 ;
case 0x24 : return V_21 ;
case 0x03 : return V_22 ;
case 0x14 : return V_23 ;
case 0x13 : return V_24 ;
case 0x00 : return V_25 ;
case 0x01 : return V_26 ;
case 0x02 : return V_27 ;
case 0x10 : return V_28 ;
case 0x11 : return V_29 ;
case 0x12 : return V_30 ;
case 0x20 : return V_31 ;
case 0x21 : return V_32 ;
case 0x22 : return V_33 ;
case 0x30 : return V_34 ;
case 0x31 : return V_35 ;
case 0x32 : return V_36 |
V_27 << 8 ;
}
return - V_10 ;
}
static void F_5 ( struct V_1 * V_2 , int V_37 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
if ( V_2 -> V_40 >= 0 ) {
F_6 ( V_39 , V_2 -> V_40 & 0xff , 0 ) ;
if ( V_2 -> V_40 >> 8 )
F_6 ( V_39 , V_2 -> V_40 >> 8 , 0 ) ;
}
V_2 -> V_40 = V_37 ;
if ( V_37 >= 0 ) {
F_6 ( V_39 , V_37 & 0xff , 1 ) ;
if ( V_37 >> 8 )
F_6 ( V_39 , V_37 >> 8 , 1 ) ;
}
F_7 ( V_39 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_41 * V_12 )
{
T_1 * V_42 = ( T_1 * ) V_12 ;
int V_5 ;
T_1 V_43 = 0 ;
for( V_5 = 0 ; V_5 < V_44 - 1 ; V_5 ++ )
V_43 -= V_42 [ V_5 ] ;
V_12 -> V_43 = V_43 ;
return F_9 ( V_2 -> V_45 ,
F_10 ( V_2 -> V_45 , 0 ) ,
V_46 ,
V_47 | V_48 | V_49 ,
0x200 , 3 ,
V_12 , sizeof( * V_12 ) ,
V_50 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_42 , T_2 V_51 )
{
struct V_41 * V_12 = V_2 -> V_52 ;
int V_53 , V_54 ;
if ( V_51 <= 0 )
return - V_10 ;
memset ( V_2 -> V_52 , 0 , sizeof( * ( V_2 -> V_52 ) ) ) ;
V_2 -> V_52 -> V_55 = V_56 ;
V_2 -> V_52 -> V_51 = 1 ;
V_2 -> V_52 -> V_57 [ 0 ] = V_42 [ 0 ] ;
F_8 ( V_2 , V_12 ) ;
V_42 ++ ;
V_51 -- ;
V_12 -> V_55 = V_58 ;
V_53 = 0 ;
while ( V_51 != V_53 ) {
V_54 = V_51 - V_53 ;
if ( V_54 > sizeof( V_12 -> V_57 ) )
V_54 = sizeof( V_12 -> V_57 ) ;
V_12 -> V_51 = V_54 ;
V_12 -> V_59 = F_12 ( V_53 ) ;
memcpy ( V_12 -> V_57 , & V_42 [ V_53 ] , V_54 ) ;
F_8 ( V_2 , V_12 ) ;
V_53 += V_54 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_8 ;
int V_5 , V_53 , V_54 ;
V_53 = V_2 -> V_60 ;
memset ( V_2 -> V_52 , 0 , sizeof( * ( V_2 -> V_52 ) ) ) ;
V_2 -> V_52 -> V_55 = V_61 ;
V_2 -> V_52 -> V_51 = 1 ;
V_2 -> V_52 -> V_43 = 0xff - V_61 ;
if ( V_53 >= sizeof( V_2 -> V_13 ) ) {
V_2 -> V_60 = 0 ;
return 0 ;
}
do {
V_8 = V_2 -> V_13 . V_14 [ V_53 ] ;
if ( V_8 != V_2 -> V_62 . V_14 [ V_53 ] )
goto V_63;
} while ( ++ V_53 < sizeof( V_2 -> V_13 ) );
V_2 -> V_60 = 0 ;
return 0 ;
V_63:
V_2 -> V_62 . V_14 [ V_53 ] = V_8 ;
V_2 -> V_52 -> V_57 [ 0 ] = V_8 ;
switch( V_53 ) {
case F_14 ( struct V_64 , V_65 ) :
V_2 -> V_52 -> V_55 = V_66 ;
V_2 -> V_52 -> V_43 = - 1 - V_66 - V_8 ;
break;
case F_14 ( struct V_64 , V_67 ) :
V_2 -> V_52 -> V_55 = V_68 ;
V_2 -> V_52 -> V_43 = - 1 - V_68 - V_8 ;
break;
case F_14 ( struct V_64 , V_69 ) :
V_2 -> V_52 -> V_55 = V_70 ;
V_2 -> V_52 -> V_43 = - 1 - V_70 - V_8 ;
break;
case F_14 ( struct V_64 , V_71 ) :
V_8 -- ;
V_8 &= 0x1f ;
V_2 -> V_52 -> V_55 = V_72 ;
V_2 -> V_52 -> V_59 = F_12 ( V_8 ) ;
V_2 -> V_52 -> V_57 [ 0 ] = 0 ;
V_2 -> V_52 -> V_43 = - 1 - V_72 - V_8 ;
break;
default:
V_54 = sizeof( V_2 -> V_13 . V_16 . V_73 ) - V_53 ;
if ( V_54 > sizeof( V_2 -> V_52 -> V_57 ) )
V_54 = sizeof( V_2 -> V_52 -> V_57 ) ;
V_2 -> V_52 -> V_55 = V_74 ;
V_2 -> V_52 -> V_59 = F_12 ( V_53 ) ;
V_2 -> V_52 -> V_51 = V_54 ;
V_2 -> V_52 -> V_43 = - V_74 - V_53 - V_8 - V_54 ;
for( V_5 = 1 ; V_5 < V_54 ; V_5 ++ ) {
V_53 ++ ;
V_8 = V_2 -> V_13 . V_14 [ V_53 ] ;
V_2 -> V_62 . V_14 [ V_53 ] = V_8 ;
V_2 -> V_52 -> V_57 [ V_5 ] = V_8 ;
V_2 -> V_52 -> V_43 -= V_8 ;
}
}
V_2 -> V_60 = V_53 + 1 ;
return 1 ;
}
static void F_15 ( struct V_75 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
int V_77 , V_78 = V_75 -> V_78 ;
if ( V_78 )
F_16 ( & V_2 -> V_79 -> V_80 , L_1 ,
V_81 , V_78 ) ;
switch ( V_2 -> V_82 -> V_55 ) {
case V_61 :
V_2 -> V_13 . V_16 . V_71 = V_2 -> V_82 -> V_57 [ 0 ] ;
break;
case V_72 :
F_17 ( & V_2 -> V_79 -> V_80 , L_2 ,
V_2 -> V_82 -> V_57 [ 0 ] ) ;
F_5 ( V_2 , F_4 ( V_2 -> V_82 -> V_57 [ 0 ] ) ) ;
break;
default:
F_16 ( & V_2 -> V_79 -> V_80 , L_3 ,
V_2 -> V_82 -> V_55 ) ;
}
F_13 ( V_2 ) ;
if ( ! V_2 -> V_83 ) {
V_77 = F_18 ( V_2 -> V_84 , V_85 ) ;
if ( V_77 && V_77 != - V_86 )
F_16 ( & V_2 -> V_79 -> V_80 ,
L_4 ,
V_81 , V_77 ) ;
}
}
static void F_19 ( struct V_75 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
int V_77 = 0 , V_78 = V_75 -> V_78 ;
if ( V_78 )
F_16 ( & V_2 -> V_79 -> V_80 , L_1 ,
V_81 , V_78 ) ;
switch ( V_2 -> V_52 -> V_55 ) {
case V_61 :
case V_72 :
if ( ! V_2 -> V_83 )
V_77 = F_18 ( V_2 -> V_87 , V_85 ) ;
break;
default:
F_13 ( V_2 ) ;
if ( ! V_2 -> V_83 )
V_77 = F_18 ( V_2 -> V_84 , V_85 ) ;
break;
}
if ( V_77 && V_77 != - V_86 )
F_16 ( & V_2 -> V_79 -> V_80 , L_4 ,
V_81 , V_77 ) ;
}
static int F_20 ( struct V_38 * V_80 )
{
struct V_1 * V_2 = F_21 ( V_80 ) ;
int V_5 , V_77 ;
F_17 ( & V_2 -> V_79 -> V_80 , L_5 , V_81 ) ;
for ( V_5 = 0 ; V_5 < sizeof( V_2 -> V_13 ) ; V_5 ++ )
V_2 -> V_62 . V_14 [ V_5 ] = ~ V_2 -> V_13 . V_14 [ V_5 ] ;
V_2 -> V_40 = - 1 ;
F_11 ( V_2 , V_88 , sizeof( V_88 ) ) ;
memset ( V_2 -> V_52 , 0 , sizeof( * ( V_2 -> V_52 ) ) ) ;
V_2 -> V_52 -> V_55 = V_89 ;
V_2 -> V_52 -> V_51 = 10 ;
V_2 -> V_52 -> V_43 = 0x100 - V_89 - 10 ;
if ( ( V_77 = F_18 ( V_2 -> V_84 , V_90 ) ) != 0 ) {
F_17 ( & V_2 -> V_79 -> V_80 ,
L_6 ,
V_81 , V_77 ) ;
return V_77 ;
}
return 0 ;
}
static void F_22 ( struct V_38 * V_80 )
{
struct V_1 * V_2 = F_21 ( V_80 ) ;
V_2 -> V_83 = 1 ;
F_23 () ;
F_24 ( V_2 -> V_84 ) ;
F_24 ( V_2 -> V_87 ) ;
V_2 -> V_83 = 0 ;
F_23 () ;
}
static T_3 F_25 ( struct V_91 * V_80 , struct V_92 * V_93 ,
char * V_42 )
{
memcpy ( V_42 , & V_15 , sizeof( V_15 ) ) ;
return sizeof( V_15 ) ;
}
static T_3 F_26 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_94 )
{
if ( V_94 != sizeof( V_15 ) )
return - V_10 ;
memcpy ( & V_15 , V_42 , sizeof( V_15 ) ) ;
return sizeof( V_15 ) ;
}
static T_3 F_27 ( struct V_91 * V_80 , char * V_42 , int V_6 , int V_14 )
{
struct V_1 * V_2 ;
int V_5 ;
F_28 ( & V_95 ) ;
V_2 = F_29 ( V_80 ) ;
if ( V_2 == NULL ) {
F_30 ( & V_95 ) ;
return - V_96 ;
}
for ( V_5 = V_6 ; V_5 < V_14 ; V_5 ++ )
* V_42 ++ = V_9 [ V_5 ] . type ;
* V_42 ++ = '\n' ;
for ( V_5 = V_6 ; V_5 < V_14 ; V_5 ++ )
* V_42 ++ = V_2 -> V_9 [ V_5 ] ;
* V_42 ++ = '\n' ;
* V_42 = 0 ;
F_30 ( & V_95 ) ;
return 3 + ( ( V_14 - V_6 ) << 1 ) ;
}
static T_3 F_31 ( struct V_91 * V_80 , struct V_92 * V_93 ,
char * V_42 )
{
return F_27 ( V_80 , V_42 , V_97 , V_98 ) ;
}
static T_3 F_32 ( struct V_91 * V_80 , struct V_92 * V_93 ,
char * V_42 )
{
return F_27 ( V_80 , V_42 , V_98 , V_99 ) ;
}
static T_3 F_33 ( struct V_91 * V_80 , struct V_92 * V_93 ,
char * V_42 )
{
return F_27 ( V_80 , V_42 , V_99 , V_100 ) ;
}
static T_3 F_34 ( struct V_91 * V_80 , const char * V_42 , T_2 V_101 ,
int V_3 , T_2 V_54 )
{
struct V_1 * V_2 ;
int V_5 ;
F_35 ( & V_95 ) ;
V_2 = F_29 ( V_80 ) ;
if ( V_2 == NULL ) {
F_36 ( & V_95 ) ;
return - V_96 ;
}
if ( V_54 > V_101 )
V_54 = V_101 ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ )
F_1 ( V_2 , V_3 ++ , V_42 [ V_5 ] ) ;
F_36 ( & V_95 ) ;
return V_101 ;
}
static T_3 F_37 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
return F_34 ( V_80 , V_42 , V_101 , V_97 , V_102 ) ;
}
static T_3 F_38 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
return F_34 ( V_80 , V_42 , V_101 , V_98 , V_103 ) ;
}
static T_3 F_39 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
return F_34 ( V_80 , V_42 , V_101 , V_99 , V_104 ) ;
}
static T_3 F_40 ( struct V_91 * V_80 , struct V_92 * V_93 ,
char * V_42 )
{
struct V_1 * V_2 ;
int V_5 , V_77 = 1 ;
F_28 ( & V_95 ) ;
V_2 = F_29 ( V_80 ) ;
if ( V_2 == NULL ) {
F_30 ( & V_95 ) ;
return - V_96 ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_9 ) ; V_5 ++ ) {
if ( V_9 [ V_5 ] . type != '.' )
continue;
V_77 += sprintf ( & V_42 [ V_77 ] , L_7 ,
V_2 -> V_9 [ V_5 ] == ' ' ? L_8 : L_9 ,
V_9 [ V_5 ] . V_11 . V_12 . V_105 ) ;
}
F_30 ( & V_95 ) ;
return V_77 ;
}
static T_3 F_41 ( struct V_91 * V_80 , const char * V_42 , T_2 V_101 ,
int V_4 )
{
struct V_1 * V_2 ;
int V_5 ;
F_35 ( & V_95 ) ;
V_2 = F_29 ( V_80 ) ;
if ( V_2 == NULL ) {
F_36 ( & V_95 ) ;
return - V_96 ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_9 ) ; V_5 ++ ) {
if ( V_9 [ V_5 ] . type != '.' )
continue;
if ( strncmp ( V_42 , V_9 [ V_5 ] . V_11 . V_12 . V_105 , V_101 ) == 0 ) {
F_1 ( V_2 , V_5 , V_4 ) ;
break;
}
}
F_36 ( & V_95 ) ;
return V_101 ;
}
static T_3 F_42 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
return F_41 ( V_80 , V_42 , V_101 , V_42 [ 0 ] ) ;
}
static T_3 F_43 ( struct V_91 * V_80 , struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
return F_41 ( V_80 , V_42 , V_101 , ' ' ) ;
}
static T_3 F_44 ( struct V_91 * V_80 ,
struct V_92 * V_93 ,
const char * V_42 , T_2 V_101 )
{
struct V_1 * V_2 ;
F_35 ( & V_95 ) ;
V_2 = F_29 ( V_80 ) ;
if ( V_2 == NULL ) {
F_36 ( & V_95 ) ;
return - V_96 ;
}
F_11 ( V_2 , ( char * ) V_42 , V_101 ) ;
F_36 ( & V_95 ) ;
return V_101 ;
}
static int F_45 ( struct V_1 * V_2 , int V_106 )
{
if ( V_2 == NULL )
return V_106 ;
if ( V_2 -> V_39 ) {
if ( V_106 )
F_46 ( V_2 -> V_39 ) ;
else
F_47 ( V_2 -> V_39 ) ;
}
F_48 ( V_2 -> V_87 ) ;
F_48 ( V_2 -> V_84 ) ;
F_49 ( V_2 -> V_107 ) ;
F_50 ( V_2 -> V_45 , V_44 , V_2 -> V_52 , V_2 -> V_108 ) ;
F_50 ( V_2 -> V_45 , V_44 , V_2 -> V_82 , V_2 -> V_109 ) ;
F_49 ( V_2 ) ;
return V_106 ;
}
static void F_51 ( struct V_110 * V_79 )
{
struct V_1 * V_2 ;
F_35 ( & V_95 ) ;
V_2 = F_52 ( V_79 ) ;
F_53 ( & V_79 -> V_80 . V_111 , & V_112 ) ;
F_54 ( V_79 , NULL ) ;
F_36 ( & V_95 ) ;
F_45 ( V_2 , 0 ) ;
}
static int F_55 ( struct V_110 * V_79 , const struct V_113 * V_114 )
{
struct V_115 * V_45 = F_56 ( V_79 ) ;
struct V_116 * V_117 = (struct V_116 * ) V_114 -> V_116 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_1 * V_2 ;
struct V_38 * V_38 ;
int V_77 , V_122 , V_5 ;
V_119 = V_79 -> V_123 ;
V_121 = & V_119 -> V_121 [ 0 ] . V_124 ;
if ( ! F_57 ( V_121 ) )
return - V_96 ;
V_2 = F_58 ( sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_2 )
return - V_125 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_39 = V_38 = F_59 () ;
if ( ! V_38 )
return F_45 ( V_2 , - V_125 ) ;
V_2 -> V_82 = F_60 ( V_45 , V_44 ,
V_85 , & V_2 -> V_109 ) ;
if ( V_2 -> V_82 == NULL )
return F_45 ( V_2 , - V_125 ) ;
V_2 -> V_52 = F_60 ( V_45 , V_44 ,
V_85 , & V_2 -> V_108 ) ;
if ( ! V_2 -> V_52 )
return F_45 ( V_2 , - V_125 ) ;
V_2 -> V_107 = F_61 ( sizeof( * ( V_2 -> V_107 ) ) , V_90 ) ;
if ( V_2 -> V_107 == NULL )
return F_45 ( V_2 , - V_125 ) ;
V_2 -> V_87 = F_62 ( 0 , V_90 ) ;
if ( V_2 -> V_87 == NULL )
return F_45 ( V_2 , - V_125 ) ;
V_2 -> V_84 = F_62 ( 0 , V_90 ) ;
if ( V_2 -> V_84 == NULL )
return F_45 ( V_2 , - V_125 ) ;
V_122 = F_63 ( V_45 , V_121 -> V_126 ) ;
V_77 = F_64 ( V_45 , V_122 , F_65 ( V_122 ) ) ;
if ( V_77 != V_44 )
F_16 ( & V_79 -> V_80 , L_10 ,
V_77 , V_44 ) ;
F_66 ( V_2 -> V_87 , V_45 , V_122 , V_2 -> V_82 ,
V_44 ,
F_15 ,
V_2 , V_121 -> V_127 ) ;
V_2 -> V_87 -> V_128 = V_2 -> V_109 ;
V_2 -> V_87 -> V_129 |= V_130 ;
V_2 -> V_87 -> V_80 = V_45 ;
V_2 -> V_107 -> V_131 = V_47 | V_48 |
V_49 ;
V_2 -> V_107 -> V_132 = V_46 ;
V_2 -> V_107 -> V_133 = F_67 ( 0x200 ) ;
V_2 -> V_107 -> V_134 = F_67 ( V_119 -> V_124 . V_135 ) ;
V_2 -> V_107 -> V_136 = F_67 ( V_44 ) ;
F_68 ( V_2 -> V_84 , V_45 , F_10 ( V_45 , 0 ) ,
( void * ) V_2 -> V_107 , V_2 -> V_52 , V_44 ,
F_19 , V_2 ) ;
V_2 -> V_84 -> V_128 = V_2 -> V_108 ;
V_2 -> V_84 -> V_129 |= V_130 ;
V_2 -> V_84 -> V_80 = V_45 ;
F_69 ( V_45 , V_2 -> V_137 , sizeof( V_2 -> V_137 ) ) ;
F_70 ( V_2 -> V_137 , L_11 , sizeof( V_2 -> V_137 ) ) ;
V_38 -> V_105 = V_117 -> V_105 ;
V_38 -> V_137 = V_2 -> V_137 ;
F_71 ( V_45 , & V_38 -> V_114 ) ;
V_38 -> V_80 . V_138 = & V_79 -> V_80 ;
F_72 ( V_38 , V_2 ) ;
V_38 -> V_139 = F_20 ;
V_38 -> V_140 = F_22 ;
V_38 -> V_141 [ 0 ] = F_73 ( V_142 ) ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ ) {
int V_143 = F_4 ( V_5 ) ;
if ( V_143 >= 0 ) {
F_74 ( V_143 & 0xff , V_38 -> V_144 ) ;
if ( V_143 >> 8 )
F_74 ( V_143 >> 8 , V_38 -> V_144 ) ;
}
}
V_77 = F_75 ( V_2 -> V_39 ) ;
if ( V_77 )
return F_45 ( V_2 , V_77 ) ;
F_54 ( V_79 , V_2 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_9 ) ; V_5 ++ )
F_1 ( V_2 , V_5 , ' ' ) ;
F_39 ( & V_79 -> V_80 , NULL ,
V_145 , sizeof( V_145 ) ) ;
V_77 = F_76 ( & V_79 -> V_80 . V_111 , & V_112 ) ;
return 0 ;
}
