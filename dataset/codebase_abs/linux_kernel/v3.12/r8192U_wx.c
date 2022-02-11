static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_3 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_5 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_7 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_10 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_13 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_15 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_17 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_19 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_15 ;
T_2 V_16 ;
F_9 ( & V_9 -> V_14 ) ;
F_21 ( V_15 , ( T_1 * ) V_6 -> V_17 . V_18 ) ;
V_16 = F_22 ( V_2 , V_15 ) ;
V_6 -> V_17 . V_19 = V_16 ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_15 ;
F_9 ( & V_9 -> V_14 ) ;
F_21 ( V_15 , ( T_1 * ) V_6 -> V_17 . V_18 ) ;
F_24 ( V_2 , V_15 , V_6 -> V_17 . V_19 ) ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
F_9 ( & V_9 -> V_14 ) ;
V_20 = F_26 ( V_2 , ( T_1 ) V_6 -> V_17 . V_19 , 0x00000000 ) ;
V_6 -> V_17 . V_19 = V_20 ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_20 ;
F_9 ( & V_9 -> V_14 ) ;
F_21 ( V_20 , ( T_1 * ) V_6 -> V_17 . V_18 ) ;
F_28 ( V_2 , V_6 -> V_17 . V_19 , V_20 ) ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_3 V_15 ;
F_9 ( & V_9 -> V_14 ) ;
F_21 ( V_15 , ( T_3 * ) V_6 -> V_17 . V_18 ) ;
F_30 ( V_2 , V_15 , V_6 -> V_17 . V_19 ) ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_3 V_15 ;
T_2 V_16 ;
F_9 ( & V_9 -> V_14 ) ;
F_21 ( V_15 , ( T_3 * ) V_6 -> V_17 . V_18 ) ;
F_32 ( V_2 , V_15 , & V_16 ) ;
V_6 -> V_17 . V_19 = V_16 ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_21 * V_22 = V_9 -> V_10 ;
struct V_23 * V_24 ;
int V_25 ;
F_9 ( & V_9 -> V_14 ) ;
for( V_25 = 0 ; ( ( char * ) V_6 -> V_17 . V_18 ) [ V_25 ] != '\0' ; V_25 ++ ) ;
F_34 (target, &ieee->network_list, list) {
if ( ( V_24 -> V_26 == V_25 ) &&
( strncmp ( V_24 -> V_27 , ( char * ) V_6 -> V_17 . V_18 , V_25 ) == 0 ) ) {
if( V_24 -> V_28 > 0 || V_24 -> V_29 > 0 )
V_6 -> V_17 . V_30 = 1 ;
else V_6 -> V_17 . V_30 = 0 ;
break;
}
}
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
F_36 ( L_1 , V_31 , * V_12 ) ;
V_9 -> V_32 = * V_12 ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_38 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_33 = ( int * ) V_12 ;
int V_34 = ( V_33 [ 0 ] > 0 ) ;
short V_35 = V_9 -> V_36 ;
F_9 ( & V_9 -> V_14 ) ;
if( V_34 )
V_9 -> V_36 = 1 ;
else
V_9 -> V_36 = 0 ;
F_40 ( L_2 ,
V_9 -> V_36 ? L_3 : L_4 ) ;
if( V_35 != V_9 -> V_36 && V_9 -> F_11 ) {
}
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_42 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_43 ( V_2 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_37 * V_38 = (struct V_37 * ) V_12 ;
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 V_41 ;
int V_42 ;
V_6 -> V_17 . V_19 = sizeof( * V_38 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_43 = 5 * 1000 * 1000 ;
if( V_9 -> V_44 != NULL )
V_38 -> V_45 = V_9 -> V_46 ;
V_38 -> V_47 . V_48 = 100 ;
V_38 -> V_47 . V_49 = 0 ;
V_38 -> V_47 . V_50 = - 98 ;
V_38 -> V_47 . V_51 = 7 ;
V_38 -> V_52 . V_48 = 92 ;
V_38 -> V_52 . V_49 = 20 + - 98 ;
V_38 -> V_52 . V_50 = 0 ;
V_38 -> V_52 . V_51 = 7 ;
V_38 -> V_53 = V_54 ;
for ( V_42 = 0 ; V_42 < V_54 && V_42 < V_55 ; V_42 ++ ) {
V_38 -> V_56 [ V_42 ] = V_57 [ V_42 ] ;
}
V_38 -> V_58 = V_59 ;
V_38 -> V_60 = V_61 ;
V_38 -> V_62 = 0 ;
V_38 -> V_63 = 5000000 ;
V_38 -> V_64 = 0 ;
V_38 -> V_65 = 65535 * 1000 ;
V_38 -> V_66 = V_67 ;
V_38 -> V_68 = V_69 ;
V_38 -> V_70 = V_67 | V_69 | V_71 ;
V_38 -> V_72 = V_73 ;
V_38 -> V_74 = 16 ;
for ( V_42 = 0 , V_41 = 0 ; V_42 < 14 ; V_42 ++ ) {
if ( ( F_45 ( V_9 -> V_10 ) -> V_75 ) [ V_42 + 1 ] ) {
V_38 -> V_76 [ V_41 ] . V_42 = V_42 + 1 ;
V_38 -> V_76 [ V_41 ] . V_77 = V_78 [ V_42 ] * 100000 ;
V_38 -> V_76 [ V_41 ] . V_79 = 1 ;
V_41 ++ ;
} else {
}
if ( V_41 == V_80 )
break;
}
V_38 -> V_81 = V_41 ;
V_38 -> V_82 = V_41 ;
#if V_73 > 17
V_38 -> V_83 = V_84 | V_85 |
V_86 | V_87 ;
#endif
V_40 -> V_88 = 0x01 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_21 * V_22 = V_9 -> V_10 ;
int V_13 = 0 ;
if( ! V_9 -> F_11 ) return - V_89 ;
if ( V_9 -> V_10 -> V_90 . V_91 == true )
return - V_92 ;
if ( V_6 -> V_17 . V_30 & V_93 )
{
struct V_94 * V_95 = (struct V_94 * ) V_7 ;
if ( V_95 -> V_96 )
{
V_22 -> V_97 . V_26 = V_95 -> V_96 ;
memcpy ( V_22 -> V_97 . V_27 , V_95 -> V_98 , V_95 -> V_96 ) ;
}
}
F_9 ( & V_9 -> V_14 ) ;
if( V_9 -> V_10 -> V_99 != V_100 ) {
V_9 -> V_10 -> V_101 = 0 ;
F_47 ( V_9 -> V_10 ) ;
V_13 = 0 ;
}
else
V_13 = F_48 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if( ! V_9 -> F_11 ) return - V_89 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_50 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_52 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_54 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_56 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_58 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_6 -> V_102 . V_103 )
V_9 -> V_10 -> V_104 = V_105 ;
else {
if ( V_6 -> V_102 . V_106 < V_59 ||
V_6 -> V_102 . V_106 > V_61 )
return - V_107 ;
V_9 -> V_10 -> V_104 = V_6 -> V_102 . V_106 & ~ 0x1 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_102 . V_106 = V_9 -> V_10 -> V_104 ;
V_6 -> V_102 . V_108 = 0 ;
V_6 -> V_102 . V_103 = ( V_6 -> V_102 . V_106 == V_105 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_109 ,
char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_62 ( V_9 -> V_10 , V_11 , V_109 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_64 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_110 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_66 ( V_9 -> V_10 , V_11 , V_6 , V_110 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_110 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_21 * V_22 = V_9 -> V_10 ;
int V_13 ;
T_3 V_111 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_112 = 0xff ;
T_3 V_113 = 0 ;
T_1 V_114 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_42 ;
if( ! V_9 -> F_11 ) return - V_89 ;
F_9 ( & V_9 -> V_14 ) ;
F_68 ( V_115 , L_5 ) ;
V_13 = F_69 ( V_9 -> V_10 , V_11 , V_6 , V_110 ) ;
F_11 ( & V_9 -> V_14 ) ;
if( V_6 -> V_116 . V_19 != 0 ) {
for( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
V_111 [ V_42 ] |= V_110 [ 4 * V_42 + 0 ] & V_112 ;
if( V_42 == 1 && ( 4 * V_42 + 1 ) == V_6 -> V_116 . V_19 ) V_112 = 0x00 ;
if( V_42 == 3 && ( 4 * V_42 + 1 ) == V_6 -> V_116 . V_19 ) V_112 = 0x00 ;
V_111 [ V_42 ] |= ( V_110 [ 4 * V_42 + 1 ] & V_112 ) << 8 ;
V_111 [ V_42 ] |= ( V_110 [ 4 * V_42 + 2 ] & V_112 ) << 16 ;
V_111 [ V_42 ] |= ( V_110 [ 4 * V_42 + 3 ] & V_112 ) << 24 ;
}
#define F_70 0x4
#define F_71 0x14
switch ( V_6 -> V_116 . V_30 & V_117 ) {
case 0 : V_113 = V_22 -> V_118 ; break;
case 1 : V_113 = 0 ; break;
case 2 : V_113 = 1 ; break;
case 3 : V_113 = 2 ; break;
case 4 : V_113 = 3 ; break;
default: break;
}
if( V_6 -> V_116 . V_19 == 0x5 ) {
V_22 -> V_119 = V_120 ;
F_72 ( V_2 ) ;
F_73 ( V_2 ,
V_113 ,
V_113 ,
V_120 ,
V_114 [ V_113 ] ,
0 ,
V_111 ) ;
}
else if( V_6 -> V_116 . V_19 == 0xd ) {
V_22 -> V_119 = V_121 ;
F_72 ( V_2 ) ;
F_73 ( V_2 ,
V_113 ,
V_113 ,
V_121 ,
V_114 [ V_113 ] ,
0 ,
V_111 ) ;
}
else F_36 ( L_6 ) ;
}
return V_13 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_3 * V_122 , union
V_5 * V_6 , char * V_123 ) {
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_33 = ( int * ) V_123 ;
int V_124 = V_33 [ 0 ] ;
V_9 -> V_10 -> V_125 = V_124 ;
return 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_126 = 0 ;
F_9 ( & V_9 -> V_14 ) ;
if ( V_6 -> V_127 . V_30 & V_128 ||
V_6 -> V_127 . V_103 ) {
V_126 = - V_107 ;
goto exit;
}
if ( ! ( V_6 -> V_127 . V_30 & V_129 ) ) {
V_126 = - V_107 ;
goto exit;
}
if( V_6 -> V_127 . V_106 > V_130 ) {
V_126 = - V_107 ;
goto exit;
}
if ( V_6 -> V_127 . V_30 & V_131 ) {
V_9 -> V_132 = V_6 -> V_127 . V_106 ;
F_40 ( L_7 , V_6 -> V_127 . V_106 ) ;
} else {
V_9 -> V_133 = V_6 -> V_127 . V_106 ;
F_40 ( L_8 , V_6 -> V_127 . V_106 ) ;
}
F_76 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_14 ) ;
return V_126 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_127 . V_103 = 0 ;
if ( ( V_6 -> V_127 . V_30 & V_134 ) ==
V_128 )
return - V_107 ;
if ( V_6 -> V_127 . V_30 & V_131 ) {
V_6 -> V_127 . V_30 = V_129 | V_131 ;
V_6 -> V_127 . V_106 = V_9 -> V_132 ;
} else {
V_6 -> V_127 . V_30 = V_129 | V_135 ;
V_6 -> V_127 . V_106 = V_9 -> V_133 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if( V_9 -> V_44 == NULL )
return - 1 ;
V_6 -> V_136 . V_106 = V_9 -> V_136 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_126 = 0 ;
F_9 ( & V_9 -> V_14 ) ;
if( V_9 -> V_44 == NULL ) {
V_126 = - 1 ;
goto exit;
}
if( V_9 -> V_44 ( V_2 , V_6 -> V_136 . V_106 ) == 0 )
V_9 -> V_136 = V_6 -> V_136 . V_106 ;
else
V_126 = - V_107 ;
exit:
F_11 ( & V_9 -> V_14 ) ;
return V_126 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_21 * V_22 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_81 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
{
T_1 V_137 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_138 [ 6 ] = { 0 } ;
T_3 V_110 [ 4 ] = { 0 } ;
struct V_139 * V_140 = (struct V_139 * ) V_12 ;
struct V_141 * V_116 = & V_6 -> V_116 ;
T_1 V_142 = 0 , V_143 = 0 , V_144 = 0 ;
if ( ( V_116 -> V_30 & V_145 ) ||
V_140 -> V_143 == V_146 )
goto V_147;
V_143 = ( V_140 -> V_143 == V_148 ) ? V_149 : V_140 -> V_143 ;
V_142 = V_116 -> V_30 & V_117 ;
if ( V_142 )
V_142 -- ;
V_144 = V_140 -> V_150 & V_151 ;
if ( ( ! V_144 ) || ( V_152 == V_22 -> V_153 ) || ( V_143 == V_120 ) )
{
if ( ( V_140 -> V_154 == 13 ) && ( V_143 == V_120 ) )
V_143 = V_121 ;
V_22 -> V_119 = V_143 ;
F_72 ( V_2 ) ;
}
memcpy ( ( T_1 * ) V_110 , V_140 -> V_110 , 16 ) ;
if ( ( V_143 & V_120 ) && ( V_22 -> V_155 != 2 ) )
{
F_73 ( V_2 ,
V_142 ,
V_142 ,
V_143 ,
V_138 ,
0 ,
V_110 ) ;
}
else if ( V_144 )
{
V_22 -> V_156 = V_143 ;
F_73 ( V_2 ,
V_142 ,
V_142 ,
V_143 ,
V_137 ,
0 ,
V_110 ) ;
}
else
{
F_73 ( V_2 ,
4 ,
V_142 ,
V_143 ,
( T_1 * ) V_22 -> V_157 ,
0 ,
V_110 ) ;
}
}
V_147:
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_17 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_83 ( V_9 -> V_10 , V_11 , & ( V_17 -> V_158 ) , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_85 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_17 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_87 ( V_9 -> V_10 , V_12 , V_17 -> V_17 . V_19 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
return - 1 ;
}
struct V_159 * F_89 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_21 * V_22 = V_9 -> V_10 ;
struct V_159 * V_160 = & V_9 -> V_160 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_163 = 0 ;
if( V_22 -> V_99 < V_100 )
{
V_160 -> V_48 . V_48 = 0 ;
V_160 -> V_48 . V_49 = 0 ;
V_160 -> V_48 . V_50 = 0 ;
V_160 -> V_48 . V_51 = V_164 | V_165 ;
return V_160 ;
}
V_161 = ( & V_22 -> V_97 ) -> V_166 . V_167 ;
V_162 = ( & V_22 -> V_97 ) -> V_166 . signal ;
V_163 = ( & V_22 -> V_97 ) -> V_166 . V_50 ;
V_160 -> V_48 . V_49 = V_161 ;
V_160 -> V_48 . V_48 = V_162 ;
V_160 -> V_48 . V_50 = V_163 ;
V_160 -> V_48 . V_51 = V_164 | V_165 ;
return V_160 ;
}
