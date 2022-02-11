static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 = V_2 -> V_8 [ V_3 -> V_9 ] ;
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_1 ,
V_12 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
struct V_15 * V_16 = F_8 ( V_14 -> V_11 . V_17 ) ;
struct V_18 * V_19 = F_9 ( V_16 ) ;
struct V_13 * V_20 ;
struct V_4 * V_5 ;
unsigned char V_21 [ 3 ] ;
if ( V_3 -> V_22 [ V_23 ] &
V_24 ) {
F_10 ( L_2 , V_12 ) ;
V_2 -> V_25 = false ;
return;
}
if ( V_2 -> V_8 [ V_3 -> V_9 ] ) {
F_10 ( L_3 , V_12 ) ;
return;
}
V_20 = F_11 () ;
if ( F_12 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_4 ,
V_12 ) ;
return;
}
V_20 -> V_26 = & V_27 ;
V_20 -> V_11 . V_17 = & V_14 -> V_11 ;
V_20 -> V_28 = V_29 ;
V_20 -> V_30 = F_13 ( V_19 -> V_31 . V_32 ) ;
V_20 -> V_33 =
( V_3 -> V_22 [ V_34 ]
<< 8 ) |
V_3 -> V_22 [ V_35 ] ;
snprintf ( V_20 -> V_36 , sizeof( V_20 -> V_36 ) ,
L_5 ,
V_20 -> V_33 ) ;
V_20 -> V_37 = V_38 ;
F_14 ( V_19 , V_20 -> V_39 , sizeof( V_20 -> V_39 ) ) ;
snprintf ( V_21 , sizeof( V_21 ) , L_6 , V_3 -> V_9 ) ;
F_15 ( V_20 -> V_39 , V_21 , sizeof( V_20 -> V_39 ) ) ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_40 ) ;
if ( ! V_5 ) {
F_6 ( & V_14 -> V_11 , L_7 ,
V_12 ) ;
goto V_41;
}
V_5 -> V_42 = F_17 (
V_3 -> V_22 + V_43 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_9 = V_3 -> V_9 ;
V_20 -> V_44 = V_5 ;
V_2 -> V_8 [ V_3 -> V_9 ] = V_5 ;
if ( F_18 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_8 ,
V_12 ) ;
goto V_45;
}
return;
V_45:
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_5 ( V_5 ) ;
V_41:
F_4 ( V_20 ) ;
}
static void F_19 ( struct V_46 * V_47 )
{
struct V_1 * V_2 =
F_20 ( V_47 , struct V_1 , V_47 ) ;
struct V_3 V_3 ;
unsigned long V_6 ;
int V_48 ;
int V_49 ;
F_10 ( L_9 , V_12 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_48 = F_21 ( & V_2 -> V_50 , & V_3 ,
sizeof( struct V_3 ) ) ;
if ( V_48 != sizeof( struct V_3 ) ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_10
L_11 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
return;
}
if ( ! F_22 ( & V_2 -> V_50 ) ) {
if ( F_23 ( & V_2 -> V_47 ) == 0 ) {
F_10 ( L_12
L_13 , V_12 ) ;
}
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
switch ( V_3 . V_51 ) {
case V_52 :
F_7 ( V_2 , & V_3 ) ;
break;
case V_53 :
F_1 ( V_2 , & V_3 ) ;
break;
default:
if ( ! V_2 -> V_8 [ V_3 . V_9 ] ) {
V_49 = F_24 ( V_2 ) ;
if ( ! V_49 ) {
break;
}
F_6 ( & V_2 -> V_10 -> V_11 ,
L_14
L_15 , V_12 , V_49 ) ;
}
F_10 ( L_16 , V_12 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_26 ( & V_2 -> V_50 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_47 ) == 0 ) {
F_10 ( L_17
L_18 , V_12 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_54 ;
T_1 V_55 [ V_56 ] ;
struct V_4 * V_57 ;
V_57 = V_2 -> V_8 [ V_3 -> V_9 ] ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
for ( V_54 = 0 ; V_54 < V_58 ; V_54 ++ ) {
if ( V_57 -> V_42 & ( 1 << V_54 ) ) {
V_55 [ 0 ] = V_54 ;
if ( F_28 ( V_57 -> V_10 ,
V_59 ,
V_55 ,
V_60 [ V_54 ] , 1 ) ) {
F_10 ( L_19
L_20 ) ;
}
}
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_4 ;
V_4 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( ( V_3 -> V_51 > F_30 ( V_60 ) - 1 ) ||
( V_60 [ V_3 -> V_51 ] == 0 ) ) {
F_10 ( L_21 , V_3 -> V_51 ) ;
return;
}
if ( F_28 ( V_4 -> V_10 ,
V_59 , & V_3 -> V_51 ,
V_60 [ V_3 -> V_51 ] , 1 ) ) {
F_10 ( L_22 ) ;
}
}
static void F_31 ( struct V_4 * V_5 , T_1 * V_61 ,
int V_62 )
{
if ( F_28 ( V_5 -> V_10 , V_59 , V_61 , V_62 , 1 ) )
F_10 ( L_22 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_1 * V_61 = ( T_1 * ) ( & V_3 -> V_9 ) ;
unsigned int V_54 ;
V_66 = & V_10 -> V_67 [ V_68 ] ;
V_64 = V_66 -> V_69 [ V_70 ] ;
if ( ! V_64 ) {
F_6 ( & V_10 -> V_11 , L_23 , V_12 ) ;
return - V_71 ;
}
for ( V_54 = 0 ; V_54 < V_72 - 1 ; V_54 ++ )
V_64 -> V_73 [ 0 ] -> V_74 [ V_54 ] = V_61 [ V_54 ] ;
F_33 ( V_10 , V_64 , V_75 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_49 ;
if ( V_2 -> V_25 )
return 0 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_40 ) ;
if ( ! V_3 )
return - V_76 ;
V_3 -> V_77 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_51 = V_78 ;
V_49 = F_32 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_49 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned V_79 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_3 * V_3 ;
T_1 * V_80 ;
int V_49 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_40 ) ;
if ( ! V_3 )
return - V_76 ;
V_3 -> V_77 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_51 = V_81 ;
V_3 -> V_22 [ V_82 ] = 0x3F ;
V_3 -> V_22 [ V_83 ] = ( T_1 ) V_79 ;
V_49 = F_32 ( V_2 , V_3 ) ;
F_35 ( 50 ) ;
V_80 = ( T_1 * ) V_3 ;
memset ( V_80 , 0 , V_84 ) ;
V_80 [ 0 ] = V_85 ;
V_80 [ 1 ] = 0xFF ;
V_80 [ 2 ] = 0x80 ;
V_80 [ 3 ] = 0x00 ;
V_80 [ 4 ] = 0x00 ;
V_80 [ 5 ] = 0x09 ;
V_80 [ 6 ] = 0x00 ;
F_36 ( V_10 , V_85 , V_80 ,
V_84 , V_68 ,
V_75 ) ;
F_5 ( V_3 ) ;
return V_49 ;
}
static int F_37 ( struct V_13 * V_86 )
{
F_10 ( L_24 , V_12 , V_86 -> V_39 ) ;
return 0 ;
}
static void F_38 ( struct V_13 * V_86 )
{
F_10 ( L_24 , V_12 , V_86 -> V_39 ) ;
}
static int F_39 ( struct V_13 * V_86 ,
unsigned char V_87 , T_2 * V_80 ,
T_3 V_48 , unsigned char V_51 ,
int V_88 )
{
struct V_4 * V_57 = V_86 -> V_44 ;
struct V_1 * V_2 = V_57 -> V_1 ;
T_1 * V_89 ;
int V_90 ;
if ( ( V_80 [ 0 ] == V_85 ) ||
( V_80 [ 0 ] == V_91 ) ) {
if ( V_48 < 2 )
return - V_92 ;
if ( V_48 == 7 && ! memcmp ( V_80 , V_93 ,
sizeof( V_93 ) ) )
V_80 [ 4 ] = ( V_80 [ 4 ] & 0xf0 ) | ( V_57 -> V_9 - 1 ) ;
else
V_80 [ 1 ] = V_57 -> V_9 ;
return F_36 ( V_2 -> V_10 , V_87 , V_80 ,
V_48 , V_51 , V_88 ) ;
}
if ( V_80 [ 0 ] != V_94 )
return - V_92 ;
V_89 = F_16 ( V_72 , V_95 ) ;
if ( ! V_89 )
return - V_76 ;
if ( V_48 > V_72 - 2 )
V_48 = V_72 - 2 ;
V_89 [ 0 ] = V_70 ;
V_89 [ 1 ] = V_57 -> V_9 ;
memcpy ( V_89 + 2 , V_80 , V_48 ) ;
V_90 = F_36 ( V_2 -> V_10 , V_89 [ 0 ] , V_89 ,
V_72 , V_51 , V_88 ) ;
F_5 ( V_89 ) ;
return V_90 ;
}
static void F_40 ( char * V_96 , unsigned int * V_97 , const char * V_61 , unsigned int V_62 )
{
memcpy ( V_96 + * V_97 , V_61 , V_62 ) ;
* V_97 += V_62 ;
}
static int F_41 ( struct V_13 * V_86 )
{
struct V_4 * V_57 = V_86 -> V_44 ;
unsigned int V_97 = 0 ;
char * V_96 ;
int V_49 ;
F_10 ( L_9 , V_12 ) ;
V_57 -> V_10 -> V_98 = 0x0111 ;
V_57 -> V_10 -> V_99 = 0x00 ;
V_96 = F_42 ( V_100 , V_40 ) ;
if ( ! V_96 )
return - V_76 ;
if ( V_57 -> V_42 & V_101 ) {
F_10 ( L_25 ,
V_12 , V_57 -> V_42 ) ;
F_40 ( V_96 , & V_97 , V_102 , sizeof( V_102 ) ) ;
}
if ( V_57 -> V_42 & V_103 ) {
F_10 ( L_26
L_27 , V_12 , V_57 -> V_42 ) ;
F_40 ( V_96 , & V_97 , V_104 , sizeof( V_104 ) ) ;
}
if ( V_57 -> V_42 & V_105 ) {
F_10 ( L_28 ,
V_12 , V_57 -> V_42 ) ;
F_40 ( V_96 , & V_97 , V_106 , sizeof( V_106 ) ) ;
}
if ( V_57 -> V_42 & V_107 ) {
F_10 ( L_29 ,
V_12 , V_57 -> V_42 ) ;
F_40 ( V_96 , & V_97 , V_108 , sizeof( V_108 ) ) ;
}
if ( V_57 -> V_42 & V_109 ) {
F_10 ( L_30 ,
V_12 , V_57 -> V_42 ) ;
F_40 ( V_96 , & V_97 , V_110 , sizeof( V_110 ) ) ;
}
if ( V_57 -> V_42 & V_111 ) {
F_10 ( L_31 ,
V_12 , V_57 -> V_42 ) ;
}
F_40 ( V_96 , & V_97 , V_112 , sizeof( V_112 ) ) ;
V_49 = F_43 ( V_86 , V_96 , V_97 ) ;
F_5 ( V_96 ) ;
return V_49 ;
}
static int F_44 ( struct V_13 * V_86 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_45 ( struct V_13 * V_86 )
{
F_10 ( L_9 , V_12 ) ;
}
static int F_46 ( struct V_13 * V_10 ,
struct V_63 * V_64 , T_1 * V_61 ,
int V_62 )
{
struct V_1 * V_2 = F_47 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_61 ;
unsigned long V_6 ;
if ( ( V_3 -> V_9 < V_113 ) ||
( V_3 -> V_9 > V_114 ) ) {
if ( V_3 -> V_9 != V_115 )
F_6 ( & V_10 -> V_11 , L_32 ,
V_12 , V_3 -> V_9 ) ;
return false ;
}
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( ! V_2 -> V_8 [ V_3 -> V_9 ] ) {
F_25 ( V_2 , V_3 ) ;
goto V_116;
}
switch ( V_3 -> V_51 ) {
case V_52 :
break;
case V_53 :
F_25 ( V_2 , V_3 ) ;
break;
case V_117 :
if ( V_3 -> V_22 [ V_118 ] ==
V_119 ) {
F_27 ( V_2 , V_3 ) ;
}
break;
default:
F_29 ( V_2 , V_3 ) ;
}
V_116:
F_3 ( & V_2 -> V_7 , V_6 ) ;
return true ;
}
static int F_48 ( struct V_13 * V_10 ,
struct V_63 * V_64 , T_1 * V_61 ,
int V_62 )
{
struct V_1 * V_2 = F_47 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_61 ;
unsigned long V_6 ;
T_1 V_9 = V_3 -> V_9 ;
if ( V_9 == V_120 ) {
if ( V_62 == V_121 &&
! memcmp ( V_61 , V_122 ,
sizeof( V_122 ) ) )
V_9 = ( V_61 [ 4 ] & 0x0F ) + 1 ;
else
return false ;
}
if ( ( V_9 < V_113 ) ||
( V_9 > V_114 ) ) {
F_6 ( & V_10 -> V_11 , L_32 ,
V_12 , V_3 -> V_9 ) ;
return false ;
}
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( ! V_2 -> V_8 [ V_9 ] )
goto V_116;
F_31 ( V_2 -> V_8 [ V_9 ] ,
V_61 , V_62 ) ;
V_116:
F_3 ( & V_2 -> V_7 , V_6 ) ;
return false ;
}
static int F_49 ( struct V_13 * V_10 ,
struct V_63 * V_64 , T_1 * V_61 ,
int V_62 )
{
F_10 ( L_33 , V_12 , V_62 ) ;
switch ( V_61 [ 0 ] ) {
case V_70 :
if ( V_62 != V_72 ) {
F_6 ( & V_10 -> V_11 , L_34 , V_62 ) ;
return false ;
}
return F_46 ( V_10 , V_64 , V_61 , V_62 ) ;
case V_85 :
if ( V_62 != V_84 ) {
F_6 ( & V_10 -> V_11 ,
L_35 , V_62 ) ;
return false ;
}
return F_48 ( V_10 , V_64 , V_61 , V_62 ) ;
case V_91 :
if ( V_62 != V_121 ) {
F_6 ( & V_10 -> V_11 ,
L_36 , V_62 ) ;
return false ;
}
return F_48 ( V_10 , V_64 , V_61 , V_62 ) ;
}
return false ;
}
static int F_50 ( struct V_13 * V_10 ,
const struct V_123 * V_124 )
{
struct V_15 * V_16 = F_8 ( V_10 -> V_11 . V_17 ) ;
struct V_1 * V_2 ;
int V_49 ;
F_10 ( L_37 , V_12 ,
V_16 -> V_125 -> V_126 . V_127 ) ;
if ( V_16 -> V_125 -> V_126 . V_127 !=
V_128 ) {
F_10 ( L_38 , V_12 ,
V_16 -> V_125 -> V_126 . V_127 ) ;
return - V_71 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_39 , V_12 ) ;
return - V_76 ;
}
V_2 -> V_10 = V_10 ;
F_51 ( & V_2 -> V_47 , F_19 ) ;
F_52 ( & V_2 -> V_7 ) ;
if ( F_53 ( & V_2 -> V_50 ,
V_129 * sizeof( struct V_3 ) ,
V_40 ) ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_76 ;
}
F_54 ( V_10 , V_2 ) ;
V_49 = F_55 ( V_10 ) ;
if ( V_49 ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
goto V_130;
}
if ( ! F_56 ( V_10 , V_68 , V_70 ,
0 , V_72 - 1 ) ) {
V_49 = - V_71 ;
goto V_130;
}
V_49 = F_57 ( V_10 , V_131 ) ;
if ( V_49 ) {
F_6 ( & V_10 -> V_11 ,
L_42 , V_12 ) ;
goto V_132;
}
V_49 = F_34 ( V_2 , 0 ) ;
if ( V_49 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_43 ,
V_12 , V_49 ) ;
goto V_133;
}
V_49 = F_58 ( V_10 ) ;
if ( V_49 < 0 ) {
F_6 ( & V_10 -> V_11 , L_44 ,
V_12 , V_49 ) ;
goto V_134;
}
F_59 ( V_10 ) ;
V_49 = F_24 ( V_2 ) ;
if ( V_49 < 0 ) {
F_6 ( & V_10 -> V_11 , L_14
L_15 , V_12 , V_49 ) ;
goto V_135;
}
return V_49 ;
V_135:
F_60 ( V_10 ) ;
V_134:
V_133:
F_61 ( V_10 ) ;
V_132:
V_130:
F_62 ( & V_2 -> V_50 ) ;
F_5 ( V_2 ) ;
F_54 ( V_10 , NULL ) ;
return V_49 ;
}
static int F_63 ( struct V_13 * V_10 )
{
int V_49 ;
struct V_1 * V_2 = F_47 ( V_10 ) ;
V_49 = F_34 ( V_2 , 0 ) ;
if ( V_49 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_43 ,
V_12 , V_49 ) ;
}
return 0 ;
}
static void F_64 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_47 ( V_10 ) ;
struct V_4 * V_5 ;
int V_54 ;
F_10 ( L_9 , V_12 ) ;
F_65 ( & V_2 -> V_47 ) ;
F_60 ( V_10 ) ;
F_61 ( V_10 ) ;
for ( V_54 = 0 ; V_54 < ( V_136 + V_113 ) ; V_54 ++ ) {
V_5 = V_2 -> V_8 [ V_54 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_54 ] = NULL ;
}
}
F_62 ( & V_2 -> V_50 ) ;
F_5 ( V_2 ) ;
F_54 ( V_10 , NULL ) ;
}
