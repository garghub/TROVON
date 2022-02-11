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
F_9 ( & V_9 -> V_14 ) ;
F_21 ( L_1 , V_15 , * V_12 ) ;
V_9 -> V_16 = * V_12 ;
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_23 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_17 = ( int * ) V_12 ;
int V_18 = ( V_17 [ 0 ] > 0 ) ;
short V_19 = V_9 -> V_20 ;
F_9 ( & V_9 -> V_14 ) ;
if ( V_18 )
V_9 -> V_20 = 1 ;
else
V_9 -> V_20 = 0 ;
F_25 ( L_2 ,
V_9 -> V_20 ? L_3 : L_4 ) ;
if ( V_19 != V_9 -> V_20 && V_9 -> F_11 ) {
}
F_11 ( & V_9 -> V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_27 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_28 ( V_2 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_21 * V_22 = (struct V_21 * ) V_12 ;
struct V_23 * V_24 = (struct V_23 * ) V_22 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_25 ;
int V_26 ;
V_6 -> V_27 . V_28 = sizeof( * V_22 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_29 = 5 * 1000 * 1000 ;
if ( V_9 -> V_30 != NULL )
V_22 -> V_31 = V_9 -> V_32 ;
V_22 -> V_33 . V_34 = 100 ;
V_22 -> V_33 . V_35 = 0 ;
V_22 -> V_33 . V_36 = - 98 ;
V_22 -> V_33 . V_37 = 7 ;
V_22 -> V_38 . V_34 = 92 ;
V_22 -> V_38 . V_35 = 20 + - 98 ;
V_22 -> V_38 . V_36 = 0 ;
V_22 -> V_38 . V_37 = 7 ;
V_22 -> V_39 = V_40 ;
for ( V_26 = 0 ; V_26 < V_40 && V_26 < V_41 ; V_26 ++ )
V_22 -> V_42 [ V_26 ] = V_43 [ V_26 ] ;
V_22 -> V_44 = V_45 ;
V_22 -> V_46 = V_47 ;
V_22 -> V_48 = 0 ;
V_22 -> V_49 = 5000000 ;
V_22 -> V_50 = 0 ;
V_22 -> V_51 = 65535 * 1000 ;
V_22 -> V_52 = V_53 ;
V_22 -> V_54 = V_55 ;
V_22 -> V_56 = V_53 | V_55 | V_57 ;
V_22 -> V_58 = V_59 ;
V_22 -> V_60 = 16 ;
for ( V_26 = 0 , V_25 = 0 ; V_26 < 14 ; V_26 ++ ) {
if ( ( F_30 ( V_9 -> V_10 ) -> V_61 ) [ V_26 + 1 ] ) {
V_22 -> V_62 [ V_25 ] . V_26 = V_26 + 1 ;
V_22 -> V_62 [ V_25 ] . V_63 = V_64 [ V_26 ] * 100000 ;
V_22 -> V_62 [ V_25 ] . V_65 = 1 ;
V_25 ++ ;
} else {
}
if ( V_25 == V_66 )
break;
}
V_22 -> V_67 = V_25 ;
V_22 -> V_68 = V_25 ;
V_22 -> V_69 = V_70 | V_71 |
V_72 | V_73 ;
V_24 -> V_74 = 0x01 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 = V_9 -> V_10 ;
int V_13 = 0 ;
if ( ! V_9 -> F_11 )
return - V_77 ;
if ( V_9 -> V_10 -> V_78 . V_79 == true )
return - V_80 ;
if ( V_6 -> V_27 . V_81 & V_82 ) {
struct V_83 * V_84 = (struct V_83 * ) V_7 ;
if ( V_84 -> V_85 ) {
V_76 -> V_86 . V_87 = V_84 -> V_85 ;
memcpy ( V_76 -> V_86 . V_88 , V_84 -> V_89 , V_84 -> V_85 ) ;
}
}
F_9 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_10 -> V_90 != V_91 ) {
V_9 -> V_10 -> V_92 = 0 ;
F_32 ( V_9 -> V_10 ) ;
V_13 = 0 ;
} else {
V_13 = F_33 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> F_11 )
return - V_77 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_35 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_37 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_39 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_41 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_43 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_6 -> V_93 . V_94 )
V_9 -> V_10 -> V_95 = V_96 ;
else {
if ( V_6 -> V_93 . V_97 < V_45 ||
V_6 -> V_93 . V_97 > V_47 )
return - V_98 ;
V_9 -> V_10 -> V_95 = V_6 -> V_93 . V_97 & ~ 0x1 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_93 . V_97 = V_9 -> V_10 -> V_95 ;
V_6 -> V_93 . V_99 = 0 ;
V_6 -> V_93 . V_94 = ( V_6 -> V_93 . V_97 == V_96 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_100 ,
char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_47 ( V_9 -> V_10 , V_11 , V_100 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_49 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_101 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_51 ( V_9 -> V_10 , V_11 , V_6 , V_101 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_101 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 = V_9 -> V_10 ;
int V_13 ;
T_2 V_102 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 V_103 = 0xff ;
T_2 V_104 = 0 ;
T_3 V_105 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_26 ;
if ( ! V_9 -> F_11 )
return - V_77 ;
F_9 ( & V_9 -> V_14 ) ;
F_53 ( V_106 , L_5 ) ;
V_13 = F_54 ( V_9 -> V_10 , V_11 , V_6 , V_101 ) ;
F_11 ( & V_9 -> V_14 ) ;
if ( V_6 -> V_107 . V_28 != 0 ) {
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_102 [ V_26 ] |= V_101 [ 4 * V_26 + 0 ] & V_103 ;
if ( V_26 == 1 && ( 4 * V_26 + 1 ) == V_6 -> V_107 . V_28 )
V_103 = 0x00 ;
if ( V_26 == 3 && ( 4 * V_26 + 1 ) == V_6 -> V_107 . V_28 )
V_103 = 0x00 ;
V_102 [ V_26 ] |= ( V_101 [ 4 * V_26 + 1 ] & V_103 ) << 8 ;
V_102 [ V_26 ] |= ( V_101 [ 4 * V_26 + 2 ] & V_103 ) << 16 ;
V_102 [ V_26 ] |= ( V_101 [ 4 * V_26 + 3 ] & V_103 ) << 24 ;
}
#define F_55 0x4
#define F_56 0x14
switch ( V_6 -> V_107 . V_81 & V_108 ) {
case 0 :
V_104 = V_76 -> V_109 ;
break;
case 1 :
V_104 = 0 ;
break;
case 2 :
V_104 = 1 ;
break;
case 3 :
V_104 = 2 ;
break;
case 4 :
V_104 = 3 ;
break;
default:
break;
}
if ( V_6 -> V_107 . V_28 == 0x5 ) {
V_76 -> V_110 = V_111 ;
F_57 ( V_2 ) ;
F_58 ( V_2 ,
V_104 ,
V_104 ,
V_111 ,
V_105 [ V_104 ] ,
0 ,
V_102 ) ;
}
else if ( V_6 -> V_107 . V_28 == 0xd ) {
V_76 -> V_110 = V_112 ;
F_57 ( V_2 ) ;
F_58 ( V_2 ,
V_104 ,
V_104 ,
V_112 ,
V_105 [ V_104 ] ,
0 ,
V_102 ) ;
} else {
F_21 ( L_6 ) ;
}
}
return V_13 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_3 * V_113 ,
union V_5 * V_6 , char * V_114 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_17 = ( int * ) V_114 ;
int V_115 = V_17 [ 0 ] ;
V_9 -> V_10 -> V_116 = V_115 ;
return 1 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_117 = 0 ;
F_9 ( & V_9 -> V_14 ) ;
if ( V_6 -> V_118 . V_81 & V_119 ||
V_6 -> V_118 . V_94 ) {
V_117 = - V_98 ;
goto exit;
}
if ( ! ( V_6 -> V_118 . V_81 & V_120 ) ) {
V_117 = - V_98 ;
goto exit;
}
if ( V_6 -> V_118 . V_97 > V_121 ) {
V_117 = - V_98 ;
goto exit;
}
if ( V_6 -> V_118 . V_81 & V_122 ) {
V_9 -> V_123 = V_6 -> V_118 . V_97 ;
F_25 ( L_7 , V_6 -> V_118 . V_97 ) ;
} else {
V_9 -> V_124 = V_6 -> V_118 . V_97 ;
F_25 ( L_8 , V_6 -> V_118 . V_97 ) ;
}
F_61 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_14 ) ;
return V_117 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_118 . V_94 = 0 ;
if ( ( V_6 -> V_118 . V_81 & V_125 ) ==
V_119 )
return - V_98 ;
if ( V_6 -> V_118 . V_81 & V_122 ) {
V_6 -> V_118 . V_81 = V_120 | V_122 ;
V_6 -> V_118 . V_97 = V_9 -> V_123 ;
} else {
V_6 -> V_118 . V_81 = V_120 | V_126 ;
V_6 -> V_118 . V_97 = V_9 -> V_124 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_30 == NULL )
return - 1 ;
V_6 -> V_127 . V_97 = V_9 -> V_127 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_117 = 0 ;
F_9 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_30 == NULL ) {
V_117 = - 1 ;
goto exit;
}
if ( V_9 -> V_30 ( V_2 , V_6 -> V_127 . V_97 ) == 0 )
V_9 -> V_127 = V_6 -> V_127 . V_97 ;
else
V_117 = - V_98 ;
exit:
F_11 ( & V_9 -> V_14 ) ;
return V_117 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_66 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
{
T_3 V_128 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_3 V_129 [ 6 ] = { 0 } ;
T_2 V_101 [ 4 ] = { 0 } ;
struct V_130 * V_131 = (struct V_130 * ) V_12 ;
struct V_132 * V_107 = & V_6 -> V_107 ;
T_3 V_133 = 0 , V_134 = 0 , V_135 = 0 ;
if ( ( V_107 -> V_81 & V_136 ) || V_131 -> V_134 == V_137 )
goto V_138;
V_134 = ( V_131 -> V_134 == V_139 ) ? V_140 : V_131 -> V_134 ;
V_133 = V_107 -> V_81 & V_108 ;
if ( V_133 )
V_133 -- ;
V_135 = V_131 -> V_141 & V_142 ;
if ( ( ! V_135 ) || ( V_143 == V_76 -> V_144 ) || ( V_134 == V_111 ) ) {
if ( ( V_131 -> V_145 == 13 ) && ( V_134 == V_111 ) )
V_134 = V_112 ;
V_76 -> V_110 = V_134 ;
F_57 ( V_2 ) ;
}
memcpy ( ( T_3 * ) V_101 , V_131 -> V_101 , 16 ) ;
if ( ( V_134 & V_111 ) && ( V_76 -> V_146 != 2 ) ) {
F_58 ( V_2 ,
V_133 ,
V_133 ,
V_134 ,
V_129 ,
0 ,
V_101 ) ;
} else if ( V_135 ) {
V_76 -> V_147 = V_134 ;
F_58 ( V_2 ,
V_133 ,
V_133 ,
V_134 ,
V_128 ,
0 ,
V_101 ) ;
} else {
F_58 ( V_2 ,
4 ,
V_133 ,
V_134 ,
( T_3 * ) V_76 -> V_148 ,
0 ,
V_101 ) ;
}
}
V_138:
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_27 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_68 ( V_9 -> V_10 , V_11 , & ( V_27 -> V_149 ) , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_70 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_27 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_14 ) ;
V_13 = F_72 ( V_9 -> V_10 , V_12 , V_27 -> V_27 . V_28 ) ;
F_11 ( & V_9 -> V_14 ) ;
return V_13 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
return - 1 ;
}
struct V_150 * F_74 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 = V_9 -> V_10 ;
struct V_150 * V_151 = & V_9 -> V_151 ;
int V_152 = 0 ;
int V_153 = 0 ;
int V_154 = 0 ;
if ( V_76 -> V_90 < V_91 ) {
V_151 -> V_34 . V_34 = 0 ;
V_151 -> V_34 . V_35 = 0 ;
V_151 -> V_34 . V_36 = 0 ;
V_151 -> V_34 . V_37 = V_155 | V_156 ;
return V_151 ;
}
V_152 = ( & V_76 -> V_86 ) -> V_157 . V_158 ;
V_153 = ( & V_76 -> V_86 ) -> V_157 . signal ;
V_154 = ( & V_76 -> V_86 ) -> V_157 . V_36 ;
V_151 -> V_34 . V_35 = V_152 ;
V_151 -> V_34 . V_34 = V_153 ;
V_151 -> V_34 . V_36 = V_154 ;
V_151 -> V_34 . V_37 = V_155 | V_156 ;
return V_151 ;
}
