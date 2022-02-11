static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_5 )
{
struct V_6 * V_7 ;
unsigned V_8 ;
struct V_9 * V_10 ;
T_1 * V_11 ;
if ( V_2 -> V_12 ) {
struct V_13 * V_14 ;
V_8 = sizeof( struct V_13 ) ;
V_14 = & V_2 -> V_15 . V_16 ;
memset ( V_14 , 0 , V_8 ) ;
V_7 = & V_14 -> V_7 ;
V_14 -> V_17 = V_18 + 0x40 ;
V_14 -> V_19 = 0x1 ;
V_14 -> V_20 [ 0 ] = 0x01 ;
V_14 -> V_20 [ 1 ] = 0x28 ;
V_11 = V_14 -> V_11 ;
} else {
struct V_21 * V_14 ;
V_8 = sizeof( struct V_21 ) ;
V_14 = & V_2 -> V_15 . V_22 ;
memset ( V_14 , 0 , V_8 ) ;
V_7 = & V_14 -> V_7 ;
V_14 -> V_17 = V_18 ;
V_14 -> V_20 = 0x68 ;
V_11 = V_14 -> V_11 ;
}
V_7 -> V_23 [ 1 ] = V_24 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = V_28 ;
F_2 (qdata, list, entry) {
V_11 [ V_10 -> V_29 -> V_30 ] = 0x81 ;
}
if ( V_2 -> V_12 ) {
V_5 [ 0 ] = V_31 ;
V_5 [ 7 ] = V_8 >> 8 ;
V_5 [ 8 ] = V_8 & 0xff ;
} else {
V_5 [ 0 ] = V_32 ;
V_5 [ 4 ] = V_8 ;
}
return V_8 ;
}
static void F_3 ( struct V_33 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_33 , struct V_1 , V_33 ) ;
F_5 ( & V_2 -> V_34 ) ;
F_6 ( V_2 ) ;
}
static struct V_1 * F_7 ( int V_35 , char * V_36 ,
T_1 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 , * V_40 ;
F_2 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_40 -> V_37 , V_37 , V_41 ) == 0 ) &&
( V_40 -> V_35 == V_35 ) &&
( V_40 -> V_42 == V_39 -> V_42 ) ) {
F_8 ( & V_40 -> V_33 ) ;
return V_40 ;
}
}
V_2 = F_9 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 -> V_37 , V_37 , V_41 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_42 = V_39 -> V_42 ;
memcpy ( V_2 -> V_36 , V_36 , V_44 ) ;
F_10 ( & V_2 -> V_33 ) ;
V_2 -> V_12 = - 1 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = NULL ;
F_11 ( & V_2 -> V_47 ) ;
F_12 ( & V_2 -> V_48 , V_49 ) ;
F_13 ( & V_2 -> V_50 ) ;
F_14 ( & V_2 -> V_34 , & V_51 ) ;
F_13 ( & V_2 -> V_52 ) ;
return V_2 ;
}
static int F_15 ( struct V_38 * V_39 , struct V_53 * V_29 ,
char * V_36 , T_1 * V_37 )
{
int V_54 = V_55 , V_56 ;
struct V_57 * V_58 = & V_29 -> V_59 . V_60 ;
if ( ! F_16 ( V_39 , 0xC8 , ( unsigned char * ) V_58 ,
sizeof( struct V_57 ) ) ) {
if ( V_58 -> V_17 != 0xc8 )
return V_61 ;
if ( V_58 -> V_62 [ 0 ] != 'e' || V_58 -> V_62 [ 1 ] != 'd' ||
V_58 -> V_62 [ 2 ] != 'i' || V_58 -> V_62 [ 3 ] != 'd' )
return V_61 ;
V_29 -> V_30 = V_58 -> V_30 [ 7 ] ;
for( V_56 = 0 ; V_56 < V_44 - 1 ; ++ V_56 )
* ( V_36 + V_56 ) = V_58 -> V_63 [ ( 2 * V_56 ) + 1 ] ;
* ( V_36 + V_44 - 1 ) = '\0' ;
memset ( V_37 , 0 , V_41 ) ;
memcpy ( V_37 , V_58 -> V_64 , V_58 -> V_65 ) ;
V_54 = V_66 ;
}
return V_54 ;
}
static int F_17 ( struct V_38 * V_39 , struct V_53 * V_29 )
{
int V_54 = V_55 , V_67 ;
struct V_53 * V_40 ;
struct V_68 * V_58 = & V_29 -> V_59 . V_69 ;
V_29 -> V_70 = V_71 ;
if ( ! F_16 ( V_39 , 0xC9 , ( unsigned char * ) V_58 ,
sizeof( struct V_68 ) ) ) {
if ( ( V_58 -> V_72 >> 5 ) & 0x1 )
V_29 -> V_73 = V_74 ;
else if ( V_58 -> V_72 >> 7 )
V_29 -> V_73 = V_75 ;
else
V_29 -> V_73 = V_76 ;
if ( V_58 -> V_72 & 0x1 ) {
V_29 -> V_77 = V_78 ;
V_67 = V_79 ;
} else {
V_29 -> V_77 = V_80 ;
if ( V_29 -> V_73 == V_76 ) {
V_29 -> V_70 = V_81 ;
V_67 = V_82 ;
} else
V_67 = V_83 ;
}
if ( V_58 -> V_84 & 0x1 ) {
V_29 -> V_85 = V_86 ;
V_67 |= V_87 ;
} else
V_29 -> V_85 = V_88 ;
F_18 () ;
F_19 (tmp, &h->ctlr->dh_list, node) {
F_20 ( ! V_40 -> V_39 ) ;
V_40 -> V_39 -> V_67 = V_67 ;
}
F_21 () ;
V_54 = V_66 ;
}
return V_54 ;
}
static int F_22 ( struct V_38 * V_39 ,
struct V_53 * V_29 , char * V_36 , T_1 * V_37 )
{
int V_54 = V_55 , V_35 ;
struct V_89 * V_58 = & V_29 -> V_59 . V_90 ;
if ( ! F_16 ( V_39 , 0xC4 , ( unsigned char * ) V_58 ,
sizeof( struct V_89 ) ) ) {
if ( V_58 -> V_91 [ 1 ] == 0x31 )
V_35 = 0 ;
else
V_35 = 1 ;
F_23 ( & V_92 ) ;
V_29 -> V_2 = F_7 ( V_35 , V_36 , V_37 , V_39 ) ;
if ( ! V_29 -> V_2 )
V_54 = V_93 ;
else {
F_24 ( & V_29 -> V_34 , & V_29 -> V_2 -> V_52 ) ;
V_29 -> V_39 = V_39 ;
}
F_25 ( & V_92 ) ;
V_54 = V_66 ;
}
return V_54 ;
}
static int F_26 ( struct V_38 * V_39 , struct V_53 * V_29 )
{
int V_54 = V_55 ;
struct V_94 * V_58 = & V_29 -> V_59 . V_95 ;
if ( ! F_16 ( V_39 , 0xC2 , ( unsigned char * ) V_58 ,
sizeof( struct V_94 ) ) ) {
if ( V_58 -> V_96 >= V_97 )
V_29 -> V_2 -> V_12 = 1 ;
else
V_29 -> V_2 -> V_12 = 0 ;
V_54 = V_66 ;
}
return V_54 ;
}
static int F_27 ( struct V_38 * V_39 ,
struct V_98 * V_99 )
{
int V_54 = V_55 ;
struct V_53 * V_29 = V_39 -> V_100 ;
if ( ! F_28 ( V_99 ) )
goto V_101;
switch ( V_99 -> V_102 ) {
case V_103 :
case V_104 :
case V_105 :
V_54 = V_106 ;
break;
case V_107 :
if ( V_99 -> V_108 == 0x04 && V_99 -> V_109 == 0x01 )
V_54 = V_106 ;
break;
case V_110 :
if ( V_99 -> V_108 == 0x91 && V_99 -> V_109 == 0x36 )
V_54 = V_111 ;
break;
default:
break;
}
F_29 ( V_112 , V_39 , L_1
L_2 ,
( char * ) V_29 -> V_2 -> V_36 , V_29 -> V_2 -> V_35 ,
V_99 -> V_102 , V_99 -> V_108 , V_99 -> V_109 ) ;
V_101:
return V_54 ;
}
static void V_49 ( struct V_113 * V_114 )
{
struct V_1 * V_2 =
F_4 ( V_114 , struct V_1 , V_48 ) ;
struct V_38 * V_39 = V_2 -> V_46 ;
struct V_53 * V_29 = V_39 -> V_100 ;
int V_54 = V_66 , V_115 = V_116 ;
struct V_9 * V_40 , * V_10 ;
F_30 ( V_4 ) ;
unsigned char V_5 [ F_31 ( V_31 ) ] ;
struct V_98 V_117 ;
unsigned int V_8 ;
T_2 V_118 = V_119 | V_120 |
V_121 ;
F_23 ( & V_2 -> V_47 ) ;
F_32 ( & V_2 -> V_50 , & V_4 ) ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = NULL ;
F_25 ( & V_2 -> V_47 ) ;
V_122:
V_8 = F_1 ( V_2 , & V_4 , V_5 ) ;
F_29 ( V_112 , V_39 , L_1
L_3 ,
( char * ) V_29 -> V_2 -> V_36 , V_29 -> V_2 -> V_35 ,
( V_115 == V_116 ) ? L_4 : L_5 ) ;
if ( F_33 ( V_39 , V_5 , V_123 , & V_29 -> V_2 -> V_15 ,
V_8 , NULL , & V_117 , V_124 * V_125 ,
V_126 , V_118 , 0 , NULL ) ) {
V_54 = F_27 ( V_39 , & V_117 ) ;
if ( V_54 == V_106 && V_115 -- )
goto V_122;
if ( V_54 == V_111 )
goto V_122;
}
if ( V_54 == V_66 ) {
V_29 -> V_70 = V_71 ;
F_29 ( V_112 , V_39 , L_1
L_6 ,
( char * ) V_29 -> V_2 -> V_36 , V_29 -> V_2 -> V_35 ) ;
}
F_34 (qdata, tmp, &list, entry) {
F_5 ( & V_10 -> V_127 ) ;
if ( V_54 == V_66 )
V_10 -> V_29 -> V_70 = V_71 ;
if ( V_10 -> V_128 )
V_10 -> V_128 ( V_10 -> V_129 , V_54 ) ;
F_6 ( V_10 ) ;
}
return;
}
static int F_35 ( struct V_38 * V_39 ,
T_3 V_130 , void * V_131 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_36 ( sizeof( * V_10 ) , V_132 ) ;
if ( ! V_10 )
return V_106 ;
V_10 -> V_29 = V_39 -> V_100 ;
V_10 -> V_128 = V_130 ;
V_10 -> V_129 = V_131 ;
V_2 = V_10 -> V_29 -> V_2 ;
F_23 ( & V_2 -> V_47 ) ;
F_37 ( & V_10 -> V_127 , & V_2 -> V_50 ) ;
if ( ! V_2 -> V_45 ) {
V_2 -> V_45 = 1 ;
V_2 -> V_46 = V_39 ;
F_38 ( V_133 , & V_2 -> V_48 ) ;
}
F_25 ( & V_2 -> V_47 ) ;
return V_66 ;
}
static int F_39 ( struct V_38 * V_39 ,
T_3 V_130 , void * V_131 )
{
struct V_53 * V_29 = V_39 -> V_100 ;
int V_54 = V_66 ;
int V_134 = 0 ;
V_54 = F_17 ( V_39 , V_29 ) ;
if ( V_54 != V_66 )
goto V_101;
switch ( V_29 -> V_73 ) {
case V_76 :
if ( V_29 -> V_77 == V_80 )
V_134 = 1 ;
break;
case V_74 :
if ( ( V_29 -> V_77 == V_80 ) &&
( V_29 -> V_85 == V_86 ) )
V_134 = 1 ;
break;
default:
break;
}
if ( V_134 ) {
V_54 = F_35 ( V_39 , V_130 , V_131 ) ;
if ( V_54 == V_66 )
return 0 ;
}
V_101:
if ( V_130 )
V_130 ( V_131 , V_54 ) ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 , struct V_135 * V_136 )
{
struct V_53 * V_29 = V_39 -> V_100 ;
int V_137 = V_138 ;
if ( V_29 -> V_70 != V_71 ) {
V_137 = V_139 ;
V_136 -> V_140 |= V_141 ;
}
return V_137 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_98 * V_99 )
{
struct V_53 * V_29 = V_39 -> V_100 ;
F_29 ( V_142 , V_39 , L_1
L_7 ,
( char * ) V_29 -> V_2 -> V_36 , V_29 -> V_2 -> V_35 ,
V_99 -> V_102 , V_99 -> V_108 , V_99 -> V_109 ) ;
switch ( V_99 -> V_102 ) {
case V_107 :
if ( V_99 -> V_108 == 0x04 && V_99 -> V_109 == 0x01 )
return V_143 ;
if ( V_99 -> V_108 == 0x04 && V_99 -> V_109 == 0x81 )
return V_144 ;
if ( V_99 -> V_108 == 0x04 && V_99 -> V_109 == 0xA1 )
return V_143 ;
if ( V_99 -> V_108 == 0xA1 && V_99 -> V_109 == 0x02 )
return V_143 ;
break;
case V_110 :
if ( V_99 -> V_108 == 0x94 && V_99 -> V_109 == 0x01 ) {
V_29 -> V_70 = V_81 ;
return V_144 ;
}
break;
case V_105 :
if ( V_99 -> V_108 == 0x29 && V_99 -> V_109 == 0x00 )
return V_143 ;
if ( V_99 -> V_108 == 0x8b && V_99 -> V_109 == 0x02 )
return V_143 ;
break;
}
return V_145 ;
}
static int F_42 ( struct V_38 * V_39 )
{
struct V_53 * V_29 ;
int V_54 ;
char V_36 [ V_44 ] ;
char V_37 [ V_41 ] ;
V_29 = F_36 ( sizeof( * V_29 ) , V_132 ) ;
if ( ! V_29 )
return - V_146 ;
V_29 -> V_30 = V_147 ;
V_29 -> V_70 = V_71 ;
V_54 = F_15 ( V_39 , V_29 , V_36 , V_37 ) ;
if ( V_54 != V_66 )
goto V_148;
V_54 = F_22 ( V_39 , V_29 , V_36 , V_37 ) ;
if ( V_54 != V_66 )
goto V_148;
V_54 = F_17 ( V_39 , V_29 ) ;
if ( V_54 != V_66 )
goto V_149;
V_54 = F_26 ( V_39 , V_29 ) ;
if ( V_54 != V_66 )
goto V_149;
F_43 ( V_150 , V_39 ,
L_8 ,
V_151 , V_29 -> V_30 , V_73 [ ( int ) V_29 -> V_73 ] ,
V_77 [ ( int ) V_29 -> V_77 ] ) ;
V_39 -> V_100 = V_29 ;
return 0 ;
V_149:
F_23 ( & V_92 ) ;
F_44 ( & V_29 -> V_2 -> V_33 , F_3 ) ;
F_25 ( & V_92 ) ;
V_148:
F_6 ( V_29 ) ;
return - V_152 ;
}
static void F_45 ( struct V_38 * V_39 )
{
struct V_53 * V_29 = V_39 -> V_100 ;
if ( V_29 -> V_2 && V_29 -> V_2 -> V_45 )
F_46 ( V_133 ) ;
F_23 ( & V_92 ) ;
if ( V_29 -> V_2 ) {
F_47 ( & V_29 -> V_34 ) ;
V_29 -> V_39 = NULL ;
F_44 ( & V_29 -> V_2 -> V_33 , F_3 ) ;
}
F_25 ( & V_92 ) ;
V_39 -> V_100 = NULL ;
F_6 ( V_29 ) ;
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
