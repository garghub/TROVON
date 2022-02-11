static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_12 * V_13 ;
unsigned V_14 ;
struct V_15 * V_16 ;
T_1 * V_17 ;
if ( V_10 -> V_2 -> V_18 ) {
struct V_19 * V_20 ;
V_14 = sizeof( struct V_19 ) ;
V_20 = & V_10 -> V_2 -> V_21 . V_22 ;
memset ( V_20 , 0 , V_14 ) ;
V_13 = & V_20 -> V_13 ;
V_20 -> V_23 = V_24 + 0x40 ;
V_20 -> V_25 = 0x1 ;
V_20 -> V_26 [ 0 ] = 0x01 ;
V_20 -> V_26 [ 1 ] = 0x28 ;
V_17 = V_20 -> V_17 ;
} else {
struct V_27 * V_20 ;
V_14 = sizeof( struct V_27 ) ;
V_20 = & V_10 -> V_2 -> V_21 . V_28 ;
memset ( V_20 , 0 , V_14 ) ;
V_13 = & V_20 -> V_13 ;
V_20 -> V_23 = V_24 ;
V_20 -> V_26 = 0x68 ;
V_17 = V_20 -> V_17 ;
}
V_13 -> V_29 [ 1 ] = V_30 ;
V_13 -> V_31 = V_32 ;
V_13 -> V_33 = V_34 ;
F_2 (qdata, list, entry) {
V_17 [ V_16 -> V_10 -> V_35 ] = 0x81 ;
}
if ( V_10 -> V_2 -> V_18 ) {
V_5 [ 0 ] = V_36 ;
V_5 [ 7 ] = V_14 >> 8 ;
V_5 [ 8 ] = V_14 & 0xff ;
} else {
V_5 [ 0 ] = V_37 ;
V_5 [ 4 ] = V_14 ;
}
return V_14 ;
}
static void F_3 ( struct V_38 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_38 , struct V_1 , V_38 ) ;
F_5 ( & V_2 -> V_39 ) ;
F_6 ( V_2 ) ;
}
static struct V_1 * F_7 ( int V_40 , char * V_41 ,
T_1 * V_42 , struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_43 ;
F_2 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_43 -> V_42 , V_42 , V_44 ) == 0 ) &&
( V_43 -> V_40 == V_40 ) &&
( V_43 -> V_45 == V_7 -> V_45 ) ) {
F_8 ( & V_43 -> V_38 ) ;
return V_43 ;
}
}
V_2 = F_9 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 -> V_42 , V_42 , V_44 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_45 = V_7 -> V_45 ;
memcpy ( V_2 -> V_41 , V_41 , V_47 ) ;
F_10 ( & V_2 -> V_38 ) ;
V_2 -> V_18 = - 1 ;
V_2 -> V_48 = 0 ;
V_2 -> V_8 = NULL ;
F_11 ( & V_2 -> V_49 ) ;
F_12 ( & V_2 -> V_50 , V_51 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_14 ( & V_2 -> V_39 , & V_53 ) ;
F_13 ( & V_2 -> V_54 ) ;
return V_2 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_9 * V_10 ,
char * V_41 , T_1 * V_42 )
{
int V_55 = V_56 , V_57 ;
struct V_58 * V_59 = & V_10 -> V_60 . V_61 ;
if ( ! F_16 ( V_7 , 0xC8 , ( unsigned char * ) V_59 ,
sizeof( struct V_58 ) ) ) {
if ( V_59 -> V_23 != 0xc8 )
return V_62 ;
if ( V_59 -> V_63 [ 0 ] != 'e' || V_59 -> V_63 [ 1 ] != 'd' ||
V_59 -> V_63 [ 2 ] != 'i' || V_59 -> V_63 [ 3 ] != 'd' )
return V_62 ;
V_10 -> V_35 = V_59 -> V_35 [ 7 ] ;
for( V_57 = 0 ; V_57 < V_47 - 1 ; ++ V_57 )
* ( V_41 + V_57 ) = V_59 -> V_64 [ ( 2 * V_57 ) + 1 ] ;
* ( V_41 + V_47 - 1 ) = '\0' ;
memset ( V_42 , 0 , V_44 ) ;
memcpy ( V_42 , V_59 -> V_65 , V_59 -> V_66 ) ;
V_55 = V_67 ;
}
return V_55 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
int V_55 = V_56 , V_68 ;
struct V_9 * V_43 ;
struct V_69 * V_59 = & V_10 -> V_60 . V_70 ;
V_10 -> V_71 = V_72 ;
if ( ! F_16 ( V_7 , 0xC9 , ( unsigned char * ) V_59 ,
sizeof( struct V_69 ) ) ) {
if ( ( V_59 -> V_73 >> 5 ) & 0x1 )
V_10 -> V_74 = V_75 ;
else if ( V_59 -> V_73 >> 7 )
V_10 -> V_74 = V_76 ;
else
V_10 -> V_74 = V_77 ;
if ( V_59 -> V_73 & 0x1 ) {
V_10 -> V_78 = V_79 ;
V_68 = V_80 ;
} else {
V_10 -> V_78 = V_81 ;
if ( V_10 -> V_74 == V_77 ) {
V_10 -> V_71 = V_82 ;
V_68 = V_83 ;
} else
V_68 = V_84 ;
}
if ( V_59 -> V_85 & 0x1 ) {
V_10 -> V_86 = V_87 ;
V_68 |= V_88 ;
} else
V_10 -> V_86 = V_89 ;
F_18 () ;
F_19 (tmp, &h->ctlr->dh_list, node) {
F_20 ( ! V_43 -> V_7 ) ;
V_43 -> V_7 -> V_68 = V_68 ;
}
F_21 () ;
V_55 = V_67 ;
}
return V_55 ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_41 , T_1 * V_42 )
{
int V_55 = V_56 , V_40 ;
struct V_90 * V_59 = & V_10 -> V_60 . V_91 ;
if ( ! F_16 ( V_7 , 0xC4 , ( unsigned char * ) V_59 ,
sizeof( struct V_90 ) ) ) {
if ( V_59 -> V_92 [ 1 ] == 0x31 )
V_40 = 0 ;
else
V_40 = 1 ;
F_23 ( & V_93 ) ;
V_10 -> V_2 = F_7 ( V_40 , V_41 , V_42 , V_7 ) ;
if ( ! V_10 -> V_2 )
V_55 = V_94 ;
else {
F_24 ( & V_10 -> V_39 , & V_10 -> V_2 -> V_54 ) ;
V_10 -> V_7 = V_7 ;
}
F_25 ( & V_93 ) ;
V_55 = V_67 ;
}
return V_55 ;
}
static int F_26 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
int V_55 = V_56 ;
struct V_95 * V_59 = & V_10 -> V_60 . V_96 ;
if ( ! F_16 ( V_7 , 0xC2 , ( unsigned char * ) V_59 ,
sizeof( struct V_95 ) ) ) {
if ( V_59 -> V_97 >= V_98 )
V_10 -> V_2 -> V_18 = 1 ;
else
V_10 -> V_2 -> V_18 = 0 ;
V_55 = V_67 ;
}
return V_55 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_99 * V_100 )
{
int V_55 = V_56 ;
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! F_28 ( V_100 ) )
goto V_101;
switch ( V_100 -> V_102 ) {
case V_103 :
case V_104 :
case V_105 :
V_55 = V_106 ;
break;
case V_107 :
if ( V_100 -> V_108 == 0x04 && V_100 -> V_109 == 0x01 )
V_55 = V_106 ;
break;
case V_110 :
if ( V_100 -> V_108 == 0x91 && V_100 -> V_109 == 0x36 )
V_55 = V_111 ;
break;
default:
break;
}
F_29 ( V_112 , V_7 , L_1
L_2 ,
( char * ) V_10 -> V_2 -> V_41 , V_10 -> V_2 -> V_40 ,
V_100 -> V_102 , V_100 -> V_108 , V_100 -> V_109 ) ;
V_101:
return V_55 ;
}
static void V_51 ( struct V_113 * V_114 )
{
struct V_1 * V_2 =
F_4 ( V_114 , struct V_1 , V_50 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
int V_55 = V_67 , V_115 = V_116 ;
struct V_15 * V_43 , * V_16 ;
F_30 ( V_4 ) ;
unsigned char V_5 [ F_31 ( V_36 ) ] ;
struct V_99 V_117 ;
unsigned int V_14 ;
T_2 V_118 = V_119 | V_120 |
V_121 ;
F_23 ( & V_2 -> V_49 ) ;
F_32 ( & V_2 -> V_52 , & V_4 ) ;
V_2 -> V_48 = 0 ;
V_2 -> V_8 = NULL ;
F_25 ( & V_2 -> V_49 ) ;
V_122:
V_14 = F_1 ( V_2 , & V_4 , V_5 ) ;
F_29 ( V_112 , V_7 , L_1
L_3 ,
( char * ) V_10 -> V_2 -> V_41 , V_10 -> V_2 -> V_40 ,
( V_115 == V_116 ) ? L_4 : L_5 ) ;
if ( F_33 ( V_7 , V_5 , V_123 , & V_10 -> V_2 -> V_21 ,
V_14 , NULL , & V_117 , V_124 * V_125 ,
V_126 , V_118 , 0 , NULL ) ) {
V_55 = F_27 ( V_7 , & V_117 ) ;
if ( V_55 == V_106 && V_115 -- )
goto V_122;
if ( V_55 == V_111 )
goto V_122;
}
if ( V_55 == V_67 ) {
V_10 -> V_71 = V_72 ;
F_29 ( V_112 , V_7 , L_1
L_6 ,
( char * ) V_10 -> V_2 -> V_41 , V_10 -> V_2 -> V_40 ) ;
}
F_34 (qdata, tmp, &list, entry) {
F_5 ( & V_16 -> V_127 ) ;
if ( V_55 == V_67 )
V_16 -> V_10 -> V_71 = V_72 ;
if ( V_16 -> V_128 )
V_16 -> V_128 ( V_16 -> V_129 , V_55 ) ;
F_6 ( V_16 ) ;
}
return;
}
static int F_35 ( struct V_6 * V_7 ,
T_3 V_130 , void * V_131 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_36 ( sizeof( * V_16 ) , V_132 ) ;
if ( ! V_16 )
return V_106 ;
V_16 -> V_10 = V_7 -> V_11 ;
V_16 -> V_128 = V_130 ;
V_16 -> V_129 = V_131 ;
V_2 = V_16 -> V_10 -> V_2 ;
F_23 ( & V_2 -> V_49 ) ;
F_37 ( & V_16 -> V_127 , & V_2 -> V_52 ) ;
if ( ! V_2 -> V_48 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_8 = V_7 ;
F_38 ( V_133 , & V_2 -> V_50 ) ;
}
F_25 ( & V_2 -> V_49 ) ;
return V_67 ;
}
static int F_39 ( struct V_6 * V_7 ,
T_3 V_130 , void * V_131 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_55 = V_67 ;
int V_134 = 0 ;
V_55 = F_17 ( V_7 , V_10 ) ;
if ( V_55 != V_67 )
goto V_101;
switch ( V_10 -> V_74 ) {
case V_77 :
if ( V_10 -> V_78 == V_81 )
V_134 = 1 ;
break;
case V_75 :
if ( ( V_10 -> V_78 == V_81 ) &&
( V_10 -> V_86 == V_87 ) )
V_134 = 1 ;
break;
default:
break;
}
if ( V_134 ) {
V_55 = F_35 ( V_7 , V_130 , V_131 ) ;
if ( V_55 == V_67 )
return 0 ;
}
V_101:
if ( V_130 )
V_130 ( V_131 , V_55 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 , struct V_135 * V_136 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_137 = V_138 ;
if ( V_10 -> V_71 != V_72 ) {
V_137 = V_139 ;
V_136 -> V_140 |= V_141 ;
}
return V_137 ;
}
static int F_41 ( struct V_6 * V_7 ,
struct V_99 * V_100 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_29 ( V_142 , V_7 , L_1
L_7 ,
( char * ) V_10 -> V_2 -> V_41 , V_10 -> V_2 -> V_40 ,
V_100 -> V_102 , V_100 -> V_108 , V_100 -> V_109 ) ;
switch ( V_100 -> V_102 ) {
case V_107 :
if ( V_100 -> V_108 == 0x04 && V_100 -> V_109 == 0x01 )
return V_143 ;
if ( V_100 -> V_108 == 0x04 && V_100 -> V_109 == 0x81 )
return V_144 ;
if ( V_100 -> V_108 == 0x04 && V_100 -> V_109 == 0xA1 )
return V_143 ;
if ( V_100 -> V_108 == 0xA1 && V_100 -> V_109 == 0x02 )
return V_143 ;
break;
case V_110 :
if ( V_100 -> V_108 == 0x94 && V_100 -> V_109 == 0x01 ) {
V_10 -> V_71 = V_82 ;
return V_144 ;
}
break;
case V_105 :
if ( V_100 -> V_108 == 0x29 && V_100 -> V_109 == 0x00 )
return V_143 ;
if ( V_100 -> V_108 == 0x8b && V_100 -> V_109 == 0x02 )
return V_143 ;
break;
}
return V_145 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_9 * V_10 ;
int V_55 ;
char V_41 [ V_47 ] ;
char V_42 [ V_44 ] ;
V_10 = F_36 ( sizeof( * V_10 ) , V_132 ) ;
if ( ! V_10 )
return - V_146 ;
V_10 -> V_35 = V_147 ;
V_10 -> V_71 = V_72 ;
V_55 = F_15 ( V_7 , V_10 , V_41 , V_42 ) ;
if ( V_55 != V_67 )
goto V_148;
V_55 = F_22 ( V_7 , V_10 , V_41 , V_42 ) ;
if ( V_55 != V_67 )
goto V_148;
V_55 = F_17 ( V_7 , V_10 ) ;
if ( V_55 != V_67 )
goto V_149;
V_55 = F_26 ( V_7 , V_10 ) ;
if ( V_55 != V_67 )
goto V_149;
F_43 ( V_150 , V_7 ,
L_8 ,
V_151 , V_10 -> V_35 , V_74 [ ( int ) V_10 -> V_74 ] ,
V_78 [ ( int ) V_10 -> V_78 ] ) ;
V_7 -> V_11 = V_10 ;
return 0 ;
V_149:
F_23 ( & V_93 ) ;
F_44 ( & V_10 -> V_2 -> V_38 , F_3 ) ;
F_25 ( & V_93 ) ;
V_148:
F_6 ( V_10 ) ;
return - V_152 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( V_10 -> V_2 && V_10 -> V_2 -> V_48 )
F_46 ( V_133 ) ;
F_23 ( & V_93 ) ;
if ( V_10 -> V_2 ) {
F_47 ( & V_10 -> V_39 ) ;
V_10 -> V_7 = NULL ;
F_44 ( & V_10 -> V_2 -> V_38 , F_3 ) ;
}
F_25 ( & V_93 ) ;
V_7 -> V_11 = NULL ;
F_6 ( V_10 ) ;
}
static int T_4 F_48 ( void )
{
int V_153 ;
V_153 = F_49 ( & V_154 ) ;
if ( V_153 != 0 ) {
F_50 ( V_155 L_9 ) ;
goto V_101;
}
V_133 = F_51 ( L_10 ) ;
if ( ! V_133 ) {
F_52 ( & V_154 ) ;
F_50 ( V_155 L_11 ) ;
V_153 = - V_152 ;
}
V_101:
return V_153 ;
}
static void T_5 F_53 ( void )
{
F_54 ( V_133 ) ;
F_52 ( & V_154 ) ;
}
