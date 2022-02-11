static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ,
V_2 -> V_7 , V_8 ,
V_9 , V_2 , V_2 -> V_10 ) ;
V_2 -> V_4 -> V_11 = 0 ;
V_3 = F_4 ( V_2 -> V_4 , V_12 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_4 ) ;
}
int F_7 ( struct V_1 * V_2 , const char * V_13 ,
int V_14 )
{
int V_15 , V_16 = 0 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 += V_2 -> V_17 ) {
int V_18 ;
const char * V_19 = V_13 + V_15 ;
int V_20 = F_8 ( V_2 -> V_17 , V_14 - V_15 ) ;
int V_21 ;
V_21 = F_9 ( V_2 -> V_5 ,
F_10 ( V_2 -> V_5 ,
V_2 -> V_22 ) ,
( char * ) V_19 , V_20 ,
& V_18 , V_23 * V_24 ) ;
if ( V_21 ) {
F_11 ( V_2 -> V_25 ,
L_1 , V_21 ) ;
break;
}
V_16 += V_20 ;
}
return V_16 ;
}
static void F_12 ( struct V_26 * V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_26 -> V_29 ;
if ( V_28 -> V_16 >= V_28 -> V_14 ) {
F_13 ( V_26 ) ;
F_14 ( V_28 ) ;
} else
F_15 ( V_28 , V_26 ) ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_26 * V_26 )
{
int V_21 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_16 = V_28 -> V_16 ;
int V_30 = F_8 ( V_28 -> V_14 - V_16 , V_2 -> V_17 ) ;
F_2 ( V_26 , V_2 -> V_5 ,
F_10 ( V_2 -> V_5 , V_2 -> V_22 ) ,
( char * ) V_28 -> V_13 + V_16 , V_30 ,
F_12 , V_28 , V_2 -> V_10 ) ;
V_28 -> V_16 += V_30 ;
V_21 = F_4 ( V_26 , V_12 ) ;
if ( V_21 < 0 ) {
F_11 ( V_2 -> V_25 , L_2 ,
V_31 , V_21 ) ;
F_13 ( V_26 ) ;
F_14 ( V_28 ) ;
return - V_32 ;
}
return 0 ;
}
void F_16 ( struct V_33 * V_34 , unsigned int V_35 ,
void (* F_17) ( unsigned long ) , unsigned long V_36 )
{
F_18 ( V_34 , F_17 , V_36 ) ;
V_34 -> V_37 = V_38 + V_35 * V_24 / 1000 ;
F_19 ( V_34 ) ;
}
int F_20 ( struct V_1 * V_2 , const char * V_13 ,
int V_14 )
{
struct V_27 * V_28 ;
struct V_26 * V_26 ;
V_28 = F_21 ( sizeof( struct V_27 ) , V_12 ) ;
if ( V_28 == NULL )
return - V_39 ;
V_26 = F_22 ( 0 , V_12 ) ;
if ( V_26 == NULL ) {
F_14 ( V_28 ) ;
F_11 ( V_2 -> V_25 , L_3 ) ;
return - V_39 ;
}
V_28 -> V_2 = V_2 ;
V_28 -> V_13 = V_13 ;
V_28 -> V_14 = V_14 ;
V_28 -> V_16 = 0 ;
return F_15 ( V_28 , V_26 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
char * V_13 ;
int V_21 ;
V_13 = F_24 ( V_40 ,
sizeof( V_40 ) , V_12 ) ;
if ( V_13 == NULL ) {
F_11 ( V_2 -> V_25 , L_4 ) ;
return - V_39 ;
}
V_21 = F_20 ( V_2 , V_13 ,
sizeof( V_40 ) ) ;
F_14 ( V_13 ) ;
return V_21 ;
}
int F_25 ( struct V_1 * V_2 , const char * V_13 ,
int V_14 )
{
return F_7 ( V_2 , V_13 ,
V_14 + V_41 ) -
V_41 ;
}
char * F_26 ( struct V_1 * V_2 , int V_42 , int V_43 ,
int V_14 )
{
char * V_13 = F_21 ( V_14 + V_41 , V_12 ) ;
if ( ! V_13 )
return NULL ;
V_13 [ 0 ] = V_44 ;
memcpy ( V_13 + 1 , V_45 , sizeof( V_45 ) ) ;
V_13 [ sizeof( V_45 ) + 1 ] = V_42 ;
V_13 [ sizeof( V_45 ) + 2 ] = V_43 ;
V_13 [ sizeof( V_45 ) + 3 + V_14 ] = V_46 ;
return V_13 ;
}
static void V_9 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 -> V_29 ;
struct V_47 * V_48 = & V_2 -> V_49 -> V_50 ;
int V_16 ;
if ( V_26 -> V_51 == - V_52 )
return;
V_16 =
F_27 ( V_48 , V_26 -> V_53 , V_26 -> V_11 ) ;
if ( V_16 < V_26 -> V_11 ) {
F_28 ( V_48 , V_16 ) ;
F_29 ( V_2 -> V_25 , L_5 ,
V_16 , V_26 -> V_11 ) ;
}
for (; ; ) {
V_16 =
F_30 ( V_48 , V_2 -> V_54 ,
V_55 ) ;
if ( V_16 == 0 )
break;
V_2 -> V_56 = V_16 ;
F_31 ( V_2 , V_2 -> V_54 , V_16 ) ;
switch ( V_2 -> V_5 -> V_57 . V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_32 ( (struct V_65 * )
V_2 ) ;
break;
case V_66 :
case V_67 :
break;
case V_68 :
switch ( V_2 -> V_69 ) {
case V_70 :
F_32 ( (struct V_65
* ) V_2 ) ;
break;
case V_71 :
F_33 ( (struct
V_72
* ) V_2 ) ;
break;
default:
F_11 ( V_2 -> V_25 ,
L_6 ,
V_2 -> V_69 ) ;
}
break;
case V_73 :
F_33 ( (struct V_72 * )
V_2 ) ;
break;
default:
V_74 ;
}
}
F_1 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_75 )
{
int V_21 ;
unsigned char * V_13 ;
int V_18 ;
V_13 = F_21 ( 2 , V_76 ) ;
if ( ! V_13 )
return - V_39 ;
V_13 [ 0 ] = V_77 | V_78 ;
V_13 [ 1 ] = V_75 ;
V_21 = F_9 ( V_2 -> V_5 ,
F_10 ( V_2 -> V_5 ,
V_2 -> V_22 ) ,
V_13 , 2 , & V_18 , V_23 * V_24 ) ;
if ( V_21 )
F_11 ( V_2 -> V_25 , L_1 ,
V_21 ) ;
F_14 ( V_13 ) ;
return V_21 ;
}
int F_35 ( struct V_1 * V_2 , int V_79 , T_1 V_75 )
{
int V_21 ;
unsigned char * V_13 ;
int V_18 ;
V_13 = F_21 ( 3 , V_76 ) ;
if ( ! V_13 )
return - V_39 ;
V_13 [ 0 ] = V_80 | V_78 ;
V_13 [ 1 ] = V_79 ;
V_13 [ 2 ] = V_75 ;
V_21 = F_9 ( V_2 -> V_5 ,
F_10 ( V_2 -> V_5 ,
V_2 -> V_22 ) ,
V_13 , 3 , & V_18 , V_23 * V_24 ) ;
if ( V_21 )
F_11 ( V_2 -> V_25 , L_1 ,
V_21 ) ;
F_14 ( V_13 ) ;
return V_21 ;
}
int F_36 ( struct V_1 * V_2 , int V_81 , void * V_36 ,
T_2 V_82 )
{
struct V_83 * V_5 = V_2 -> V_5 ;
int V_84 ;
unsigned char V_85 ;
V_84 = F_37 ( V_5 , F_38 ( V_5 , 0 ) , 0x67 ,
V_86 | V_87 | V_88 ,
( V_82 << 8 ) | 0x21 , V_81 ,
NULL , 0 , V_23 * V_24 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_25 , L_7 , V_84 ) ;
return V_84 ;
}
do {
V_84 = F_37 ( V_5 , F_39 ( V_5 , 0 ) , 0x67 ,
V_86 | V_87 |
V_89 ,
0x0012 , 0x0000 , & V_85 , 1 ,
V_23 * V_24 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_25 ,
L_8 , V_84 ) ;
return V_84 ;
}
} while ( V_85 == 0xff );
if ( V_85 != V_82 ) {
F_11 ( V_2 -> V_25 ,
L_9 ,
( int ) V_82 , ( int ) V_85 ) ;
return - V_32 ;
}
V_84 = F_37 ( V_5 , F_39 ( V_5 , 0 ) , 0x67 ,
V_86 | V_87 | V_89 ,
0x0013 , 0x0000 , V_36 , V_82 ,
V_23 * V_24 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_25 , L_10 , V_84 ) ;
return V_84 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_81 , void * V_36 ,
T_2 V_82 )
{
struct V_83 * V_5 = V_2 -> V_5 ;
int V_84 ;
unsigned char V_51 ;
V_84 = F_37 ( V_5 , F_38 ( V_5 , 0 ) , 0x67 ,
V_86 | V_87 | V_88 ,
0x0022 , V_81 , V_36 , V_82 ,
V_23 * V_24 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_25 ,
L_11 , V_84 ) ;
return V_84 ;
}
do {
V_84 = F_37 ( V_5 , F_39 ( V_5 , 0 ) ,
0x67 ,
V_86 | V_87 |
V_89 ,
0x0012 , 0x0000 ,
& V_51 , 1 , V_23 * V_24 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_25 ,
L_12 , V_84 ) ;
return V_84 ;
}
} while ( V_51 == 0xff );
if ( V_51 != 0 ) {
F_11 ( V_2 -> V_25 , L_13 , V_84 ) ;
return - V_32 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 , int * V_90 )
{
return F_36 ( V_2 , 0x80d0 , V_90 ,
sizeof( * V_90 ) ) ;
}
T_3 F_42 ( struct V_91 * V_92 , struct V_93 * V_94 ,
char * V_95 )
{
return 0 ;
}
static void F_43 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
if ( V_97 == NULL )
return;
V_2 = F_44 ( V_97 ) ;
if ( V_2 == NULL )
return;
F_14 ( V_2 -> V_54 ) ;
F_14 ( V_2 -> V_7 ) ;
F_13 ( V_2 -> V_4 ) ;
F_45 ( V_97 , NULL ) ;
F_14 ( V_2 ) ;
}
static int F_46 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
int V_100 ;
struct V_83 * V_5 ;
struct V_1 * V_2 ;
const struct V_101 * V_102 ;
int V_69 , V_103 = 0 ;
int V_104 ;
int V_14 = 0 ;
int V_105 = 0 , V_106 = 0 ;
int V_84 ;
if ( V_97 == NULL )
return - V_107 ;
V_5 = F_47 ( V_97 ) ;
if ( V_5 == NULL )
return - V_107 ;
if ( V_5 -> V_57 . V_108 != 1 ) {
V_84 = - V_107 ;
goto V_109;
}
for ( V_100 = F_48 ( V_110 ) - 1 ; V_100 -- ; ) {
T_4 V_111 = F_49 ( V_5 -> V_57 . V_111 ) ;
T_4 V_58 = F_49 ( V_5 -> V_57 . V_58 ) ;
if ( V_111 == V_110 [ V_100 ] . V_111 &&
V_58 == V_110 [ V_100 ] . V_58 )
break;
}
if ( V_100 < 0 ) {
V_84 = - V_107 ;
goto V_109;
}
V_102 = & V_112 [ V_100 ] ;
F_50 ( & V_97 -> V_92 , L_14 , V_102 -> V_113 ) ;
V_104 = F_49 ( V_5 -> V_57 . V_58 ) ;
V_69 = V_97 -> V_114 -> V_115 . V_116 ;
switch ( V_104 ) {
case V_60 :
case V_68 :
case V_73 :
V_103 = 1 ;
break;
case V_64 :
switch ( V_69 ) {
case 0 :
return 0 ;
case 1 :
V_103 = 0 ;
break;
default:
V_74 ;
}
break;
case V_67 :
case V_117 :
case V_118 :
switch ( V_69 ) {
case 0 :
V_103 = 1 ;
break;
case 1 :
V_103 = 0 ;
break;
default:
V_74 ;
}
break;
case V_59 :
case V_61 :
case V_62 :
case V_63 :
case V_66 :
V_103 = 5 ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_103 = 2 ;
break;
case V_124 :
case V_125 :
switch ( V_69 ) {
case 0 :
V_103 = 2 ;
break;
case 1 :
return - V_107 ;
default:
V_74 ;
}
break;
default:
V_74 ;
V_84 = - V_107 ;
goto V_109;
}
V_84 = F_51 ( V_5 , V_69 , V_103 ) ;
if ( V_84 < 0 ) {
F_11 ( & V_97 -> V_92 , L_15 ) ;
goto V_109;
}
switch ( V_104 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_14 = sizeof( struct V_65 ) ;
V_105 = 0x84 ;
V_106 = 0x03 ;
break;
case V_66 :
V_14 = sizeof( struct V_126 ) ;
V_105 = 0x84 ;
V_106 = 0x03 ;
break;
case V_67 :
V_14 = sizeof( struct V_126 ) ;
V_105 = 0x81 ;
V_106 = 0x01 ;
break;
case V_64 :
V_14 = sizeof( struct V_65 ) ;
V_105 = 0x82 ;
V_106 = 0x02 ;
break;
case V_117 :
case V_118 :
V_14 = sizeof( struct V_65 ) ;
V_105 = 0x81 ;
V_106 = 0x01 ;
break;
case V_120 :
case V_121 :
case V_125 :
case V_122 :
case V_123 :
case V_124 :
case V_119 :
V_14 = sizeof( struct V_127 ) ;
break;
case V_68 :
switch ( V_69 ) {
case V_70 :
V_14 = sizeof( struct V_65 ) ;
V_105 = 0x84 ;
V_106 = 0x03 ;
break;
case V_71 :
V_14 = sizeof( struct V_72 ) ;
V_105 = 0x86 ;
V_106 = 0x05 ;
break;
default:
V_84 = - V_107 ;
goto V_109;
}
break;
case V_73 :
V_14 = sizeof( struct V_72 ) ;
V_105 = 0x82 ;
V_106 = 0x01 ;
break;
default:
V_74 ;
V_84 = - V_107 ;
goto V_109;
}
if ( V_14 == 0 ) {
F_11 ( & V_97 -> V_92 ,
L_16 ) ;
V_84 = - V_107 ;
goto V_109;
}
V_2 = F_52 ( V_14 , V_76 ) ;
if ( V_2 == NULL ) {
V_84 = - V_107 ;
goto V_109;
}
V_2 -> V_69 = V_69 ;
V_2 -> V_102 = V_102 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_25 = & V_97 -> V_92 ;
V_2 -> V_6 = V_105 ;
V_2 -> V_22 = V_106 ;
V_2 -> V_104 = V_104 ;
{
struct V_128 * V_129 ;
unsigned V_130 =
F_53 ( F_3 ( V_5 , V_105 ) ) ;
V_129 = V_5 -> V_131 [ V_130 ] ;
if ( V_129 != NULL ) {
V_2 -> V_10 = V_129 -> V_115 . V_132 ;
V_2 -> V_17 =
F_49 ( V_129 -> V_115 . V_133 ) ;
} else {
V_2 -> V_10 = V_134 ;
V_2 -> V_17 = V_135 ;
F_11 ( V_2 -> V_25 ,
L_17 ) ;
}
}
F_45 ( V_97 , V_2 ) ;
if ( V_102 -> V_136 & V_137 ) {
V_2 -> V_7 =
F_21 ( V_8 , V_76 ) ;
if ( V_2 -> V_7 == NULL ) {
V_84 = - V_39 ;
goto V_138;
}
V_2 -> V_54 =
F_21 ( V_55 , V_76 ) ;
if ( V_2 -> V_54 == NULL ) {
V_84 = - V_39 ;
goto V_138;
}
V_2 -> V_4 = F_22 ( 0 , V_76 ) ;
if ( V_2 -> V_4 == NULL ) {
F_11 ( & V_97 -> V_92 , L_3 ) ;
F_43 ( V_97 ) ;
V_84 = - V_39 ;
goto V_138;
}
V_84 = F_1 ( V_2 ) ;
if ( V_84 < 0 ) {
F_11 ( & V_97 -> V_92 , L_18 ,
V_31 ) ;
goto V_138;
}
}
switch ( V_104 ) {
case V_59 :
case V_60 :
case V_61 :
case V_64 :
case V_117 :
case V_118 :
case V_62 :
case V_63 :
V_84 = F_54 ( V_97 , (struct V_65 * ) V_2 ) ;
break;
case V_66 :
case V_67 :
V_84 = F_55 ( V_97 ,
(struct V_126 * ) V_2 ) ;
break;
case V_68 :
switch ( V_69 ) {
case V_70 :
V_84 =
F_54 ( V_97 ,
(struct V_65 * ) V_2 ) ;
break;
case V_71 :
V_84 =
F_56 ( V_97 ,
(struct V_72 * ) V_2 ) ;
break;
default:
F_11 ( & V_97 -> V_92 ,
L_6 ,
V_69 ) ;
V_84 = - V_107 ;
}
break;
case V_73 :
V_84 =
F_56 ( V_97 ,
(struct V_72 * ) V_2 ) ;
break;
case V_120 :
case V_121 :
case V_125 :
case V_122 :
case V_123 :
case V_124 :
case V_119 :
V_84 =
F_57 ( V_97 ,
(struct V_127 * ) V_2 ) ;
break;
default:
V_74 ;
V_84 = - V_107 ;
}
if ( V_84 < 0 )
goto V_138;
V_84 = F_58 ( & V_97 -> V_92 . V_139 , & V_5 -> V_92 . V_139 ,
L_19 ) ;
if ( V_84 < 0 )
goto V_138;
F_50 ( & V_97 -> V_92 , L_20 ,
V_2 -> V_102 -> V_113 ) ;
switch ( V_104 ) {
case V_117 :
case V_118 :
F_50 ( & V_97 -> V_92 ,
L_21 ,
V_2 -> V_102 -> V_113 ) ;
}
F_59 ( V_97 ) ;
F_60 ( V_5 ) ;
return 0 ;
V_138:
F_43 ( V_97 ) ;
V_109:
return V_84 ;
}
static void F_61 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
struct V_83 * V_5 ;
int V_69 ;
if ( V_97 == NULL )
return;
V_5 = F_47 ( V_97 ) ;
if ( V_5 == NULL )
return;
F_62 ( & V_97 -> V_92 . V_139 , L_19 ) ;
V_69 = V_97 -> V_114 -> V_115 . V_116 ;
V_2 = F_44 ( V_97 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_4 != NULL )
F_5 ( V_2 ) ;
if ( V_5 != V_2 -> V_5 )
F_11 ( V_2 -> V_25 ,
L_22 ) ;
switch ( V_2 -> V_5 -> V_57 . V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_64 :
case V_117 :
case V_118 :
case V_62 :
case V_63 :
F_63 ( V_97 ) ;
break;
case V_66 :
case V_67 :
F_64 ( V_97 ) ;
break;
case V_68 :
switch ( V_69 ) {
case V_70 :
F_63 ( V_97 ) ;
break;
case V_71 :
F_65 ( V_97 ) ;
break;
}
break;
case V_73 :
F_65 ( V_97 ) ;
break;
case V_120 :
case V_121 :
case V_125 :
case V_122 :
case V_123 :
case V_124 :
case V_119 :
F_66 ( V_97 ) ;
break;
default:
V_74 ;
}
F_50 ( & V_97 -> V_92 , L_23 ,
V_2 -> V_102 -> V_113 ) ;
}
F_43 ( V_97 ) ;
F_67 ( V_97 ) ;
F_68 ( V_5 ) ;
}
static int F_69 ( struct V_96 * V_97 , T_5 V_27 )
{
struct V_1 * V_2 = F_44 ( V_97 ) ;
struct V_140 * V_141 = V_2 -> V_141 ;
F_70 ( V_2 -> V_142 , V_143 ) ;
if ( V_2 -> V_102 -> V_136 & V_137 )
F_5 ( V_2 ) ;
if ( V_141 != NULL ) {
F_71 ( V_141 -> V_144 ) ;
F_72 ( V_141 ) ;
V_141 -> V_145 = 0 ;
}
return 0 ;
}
static int F_73 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_44 ( V_97 ) ;
if ( V_2 -> V_102 -> V_136 & V_137 )
F_1 ( V_2 ) ;
F_70 ( V_2 -> V_142 , V_146 ) ;
return 0 ;
}
static int F_74 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_44 ( V_97 ) ;
switch ( V_2 -> V_5 -> V_57 . V_58 ) {
case V_120 :
case V_121 :
case V_125 :
case V_122 :
case V_123 :
case V_124 :
case V_119 :
F_75 ( (struct V_127 * ) V_2 ) ;
}
return F_73 ( V_97 ) ;
}
