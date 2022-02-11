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
return;
}
if ( ( V_3 -> V_9 < V_25 ) ||
( V_3 -> V_9 > V_26 ) ) {
F_6 ( & V_14 -> V_11 , L_3 ,
V_12 , V_3 -> V_9 ) ;
return;
}
V_20 = F_11 () ;
if ( F_12 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_4 ,
V_12 ) ;
return;
}
V_20 -> V_27 = & V_28 ;
V_20 -> V_29 = V_30 ;
V_20 -> V_11 . V_17 = & V_14 -> V_11 ;
V_20 -> V_31 = V_32 ;
V_20 -> V_33 = F_13 ( V_19 -> V_34 . V_35 ) ;
V_20 -> V_36 = F_13 ( V_19 -> V_34 . V_37 ) ;
snprintf ( V_20 -> V_38 , sizeof( V_20 -> V_38 ) ,
L_5 ,
V_3 -> V_22 [ V_39 ] ,
V_3 -> V_22 [ V_40 ] ) ;
F_14 ( V_19 , V_20 -> V_41 , sizeof( V_20 -> V_41 ) ) ;
snprintf ( V_21 , sizeof( V_21 ) , L_6 , V_3 -> V_9 ) ;
F_15 ( V_20 -> V_41 , V_21 , sizeof( V_20 -> V_41 ) ) ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_42 ) ;
if ( ! V_5 ) {
F_6 ( & V_14 -> V_11 , L_7 ,
V_12 ) ;
goto V_43;
}
V_5 -> V_44 = F_17 (
V_3 -> V_22 + V_45 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_9 = V_3 -> V_9 ;
V_20 -> V_46 = V_5 ;
V_2 -> V_8 [ V_3 -> V_9 ] = V_5 ;
if ( F_18 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_8 ,
V_12 ) ;
goto V_47;
}
return;
V_47:
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_5 ( V_5 ) ;
V_43:
F_4 ( V_20 ) ;
}
static void F_19 ( struct V_48 * V_49 )
{
struct V_1 * V_2 =
F_20 ( V_49 , struct V_1 , V_49 ) ;
struct V_3 V_3 ;
unsigned long V_6 ;
int V_50 ;
F_10 ( L_9 , V_12 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_50 = F_21 ( & V_2 -> V_51 , & V_3 ,
sizeof( struct V_3 ) ) ;
if ( V_50 != sizeof( struct V_3 ) ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_10
L_11 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
return;
}
if ( ! F_22 ( & V_2 -> V_51 ) ) {
if ( F_23 ( & V_2 -> V_49 ) == 0 ) {
F_10 ( L_12
L_13 , V_12 ) ;
}
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
switch ( V_3 . V_52 ) {
case V_53 :
F_7 ( V_2 , & V_3 ) ;
break;
case V_54 :
F_1 ( V_2 , & V_3 ) ;
break;
default:
F_10 ( L_14 , V_12 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_25 ( & V_2 -> V_51 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_49 ) == 0 ) {
F_10 ( L_15
L_16 , V_12 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_55 ;
T_1 V_56 [ V_57 ] ;
struct V_4 * V_58 ;
V_58 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( ! V_58 ) {
F_10 ( L_17
L_18 , V_3 -> V_9 ) ;
return;
}
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
for ( V_55 = 0 ; V_55 < V_59 ; V_55 ++ ) {
if ( V_58 -> V_44 & ( 1 << V_55 ) ) {
V_56 [ 0 ] = V_55 ;
if ( F_27 ( V_58 -> V_10 ,
V_60 ,
V_56 ,
V_61 [ V_55 ] , 1 ) ) {
F_10 ( L_19
L_20 ) ;
}
}
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_4 ;
V_4 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( V_4 == NULL ) {
F_10 ( L_17
L_18 , V_3 -> V_9 ) ;
return;
}
if ( ( V_3 -> V_52 > F_29 ( V_61 ) - 1 ) ||
( V_61 [ V_3 -> V_52 ] == 0 ) ) {
F_10 ( L_21 , V_3 -> V_52 ) ;
return;
}
if ( F_27 ( V_4 -> V_10 ,
V_60 , & V_3 -> V_52 ,
V_61 [ V_3 -> V_52 ] , 1 ) ) {
F_10 ( L_22 ) ;
}
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_1 * V_66 = ( T_1 * ) ( & V_3 -> V_9 ) ;
int V_55 ;
V_65 = & V_10 -> V_67 [ V_68 ] ;
V_63 = V_65 -> V_69 [ V_70 ] ;
if ( ! V_63 ) {
F_6 ( & V_10 -> V_11 , L_23 , V_12 ) ;
return - V_71 ;
}
for ( V_55 = 0 ; V_55 < V_63 -> V_72 [ 0 ] -> V_73 ; V_55 ++ )
V_63 -> V_72 [ 0 ] -> V_74 [ V_55 ] = V_66 [ V_55 ] ;
F_31 ( V_10 , V_63 , V_75 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_76 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_77 ;
V_3 -> V_78 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_79 ;
V_76 = F_30 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_76 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_80 )
{
struct V_3 * V_3 ;
int V_76 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_77 ;
V_3 -> V_78 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_81 ;
V_3 -> V_22 [ V_82 ] = 0x3F ;
V_3 -> V_22 [ V_83 ] = ( T_1 ) V_80 ;
V_76 = F_30 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_76 ;
}
static int F_34 ( struct V_13 * V_84 )
{
F_10 ( L_24 , V_12 , V_84 -> V_41 ) ;
return 0 ;
}
static void F_35 ( struct V_13 * V_84 )
{
F_10 ( L_24 , V_12 , V_84 -> V_41 ) ;
}
static int V_30 ( struct V_13 * V_84 , T_1 * V_85 ,
T_2 V_50 ,
unsigned char V_52 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_36 ( char * * V_86 , unsigned int * V_87 , const char * V_66 , unsigned int V_88 )
{
memcpy ( * V_86 + * V_87 , V_66 , V_88 ) ;
* V_87 += V_88 ;
}
static int F_37 ( struct V_13 * V_84 )
{
struct V_4 * V_58 = V_84 -> V_46 ;
unsigned int V_87 = 0 ;
char * V_86 ;
int V_76 ;
F_10 ( L_9 , V_12 ) ;
V_58 -> V_10 -> V_89 = 0x0111 ;
V_58 -> V_10 -> V_90 = 0x00 ;
V_86 = F_38 ( V_91 , V_42 ) ;
if ( ! V_86 )
return - V_77 ;
if ( V_58 -> V_44 & V_92 ) {
F_10 ( L_25 ,
V_12 , V_58 -> V_44 ) ;
F_36 ( & V_86 , & V_87 , V_93 , sizeof( V_93 ) ) ;
}
if ( V_58 -> V_44 & V_94 ) {
F_10 ( L_26
L_27 , V_12 , V_58 -> V_44 ) ;
F_36 ( & V_86 , & V_87 , V_95 , sizeof( V_95 ) ) ;
}
if ( V_58 -> V_44 & V_96 ) {
F_10 ( L_28 ,
V_12 , V_58 -> V_44 ) ;
F_36 ( & V_86 , & V_87 , V_97 , sizeof( V_97 ) ) ;
}
if ( V_58 -> V_44 & V_98 ) {
F_10 ( L_29 ,
V_12 , V_58 -> V_44 ) ;
F_36 ( & V_86 , & V_87 , V_99 , sizeof( V_99 ) ) ;
}
if ( V_58 -> V_44 & V_100 ) {
F_10 ( L_30 ,
V_12 , V_58 -> V_44 ) ;
F_36 ( & V_86 , & V_87 , V_101 , sizeof( V_101 ) ) ;
}
if ( V_58 -> V_44 & V_102 ) {
F_10 ( L_31 ,
V_12 , V_58 -> V_44 ) ;
}
V_76 = F_39 ( V_84 , V_86 , V_87 ) ;
F_5 ( V_86 ) ;
return V_76 ;
}
static int F_40 ( struct V_103 * V_11 , unsigned int type ,
unsigned int V_104 , int V_74 )
{
struct V_13 * V_20 = F_41 ( V_11 ) ;
struct V_4 * V_5 = V_20 -> V_46 ;
struct V_1 * V_2 =
F_42 ( V_20 -> V_11 . V_17 ) ;
struct V_13 * V_105 = V_2 -> V_10 ;
struct V_64 * V_65 ;
struct V_106 * V_72 ;
struct V_62 * V_63 ;
unsigned char V_66 [ 8 ] ;
int V_107 ;
F_10 ( L_32 ,
V_12 , V_11 -> V_41 , type , V_104 , V_74 ) ;
if ( type != V_108 )
return - 1 ;
V_107 = F_43 ( V_20 , type , V_104 , & V_72 ) ;
if ( V_107 == - 1 ) {
F_44 ( & V_11 -> V_11 , L_33 ) ;
return - 1 ;
}
F_45 ( V_72 , V_107 , V_74 ) ;
F_46 ( V_72 -> V_63 , & V_66 [ 0 ] ) ;
V_65 = & V_105 -> V_67 [ V_68 ] ;
V_63 = V_65 -> V_69 [ V_70 ] ;
F_45 ( V_63 -> V_72 [ 0 ] , 0 , V_5 -> V_9 ) ;
F_45 ( V_63 -> V_72 [ 0 ] , 1 , V_109 ) ;
F_45 ( V_63 -> V_72 [ 0 ] , 2 , V_66 [ 1 ] ) ;
F_31 ( V_105 , V_63 , V_75 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_84 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_48 ( struct V_13 * V_84 )
{
F_10 ( L_9 , V_12 ) ;
}
static int F_49 ( struct V_13 * V_10 ,
struct V_62 * V_63 , T_1 * V_66 ,
int V_88 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_66 ;
unsigned long V_6 ;
bool V_110 = false ;
F_10 ( L_34 , V_12 , V_88 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_3 -> V_78 == V_70 ) {
switch ( V_3 -> V_52 ) {
case V_53 :
case V_54 :
F_24 ( V_2 , V_3 ) ;
break;
case V_111 :
if ( V_3 -> V_22 [ V_112 ] ==
V_113 ) {
F_26 ( V_2 , V_3 ) ;
}
break;
default:
F_28 ( V_2 , V_3 ) ;
}
V_110 = true ;
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
return V_110 ;
}
static int F_51 ( struct V_13 * V_10 ,
const struct V_114 * V_115 )
{
struct V_15 * V_16 = F_8 ( V_10 -> V_11 . V_17 ) ;
struct V_1 * V_2 ;
int V_76 ;
if ( F_52 ( (struct V_4 * ) V_10 -> V_46 ) )
return - V_71 ;
F_10 ( L_35 , V_12 ,
V_16 -> V_116 -> V_117 . V_118 ) ;
if ( V_16 -> V_116 -> V_117 . V_118 !=
V_119 ) {
F_10 ( L_36 , V_12 ,
V_16 -> V_116 -> V_117 . V_118 ) ;
return - V_71 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_37 , V_12 ) ;
return - V_77 ;
}
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_49 , F_19 ) ;
F_54 ( & V_2 -> V_7 ) ;
if ( F_55 ( & V_2 -> V_51 ,
V_120 * sizeof( struct V_3 ) ,
V_42 ) ) {
F_6 ( & V_10 -> V_11 ,
L_38 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_77 ;
}
F_56 ( V_10 , V_2 ) ;
V_76 = F_57 ( V_10 ) ;
if ( V_76 ) {
F_6 ( & V_10 -> V_11 ,
L_39 , V_12 ) ;
goto V_121;
}
V_76 = F_58 ( V_10 , V_122 ) ;
if ( V_76 ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
goto V_123;
}
V_76 = F_33 ( V_2 , 0 ) ;
if ( V_76 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_41 ,
V_12 , V_76 ) ;
goto V_124;
}
V_76 = V_10 -> V_27 -> V_125 ( V_10 ) ;
if ( V_76 < 0 ) {
F_6 ( & V_10 -> V_11 , L_42
L_43 , V_12 , V_76 ) ;
goto V_126;
}
F_59 ( V_10 ) ;
V_76 = F_32 ( V_2 ) ;
if ( V_76 < 0 ) {
F_6 ( & V_10 -> V_11 , L_44
L_43 , V_12 , V_76 ) ;
goto V_127;
}
return V_76 ;
V_127:
V_10 -> V_27 -> V_128 ( V_10 ) ;
V_126:
V_124:
F_60 ( V_10 ) ;
V_123:
V_121:
F_61 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
return V_76 ;
}
static int F_62 ( struct V_13 * V_10 )
{
int V_76 ;
struct V_1 * V_2 = F_50 ( V_10 ) ;
V_76 = F_33 ( V_2 , 0 ) ;
if ( V_76 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_41 ,
V_12 , V_76 ) ;
}
return 0 ;
}
static void F_63 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_4 * V_5 ;
int V_55 ;
F_10 ( L_9 , V_12 ) ;
F_64 ( & V_2 -> V_49 ) ;
V_10 -> V_27 -> V_128 ( V_10 ) ;
F_60 ( V_10 ) ;
for ( V_55 = 0 ; V_55 < ( V_129 + V_25 ) ; V_55 ++ ) {
V_5 = V_2 -> V_8 [ V_55 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_55 ] = NULL ;
}
}
F_61 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
}
static int F_65 ( struct V_13 * V_10 ,
const struct V_114 * V_115 )
{
int V_130 ;
struct V_4 * V_5 = V_10 -> V_46 ;
if ( ! F_52 ( V_5 ) )
return - V_71 ;
V_130 = F_57 ( V_10 ) ;
if ( ! V_130 )
V_130 = F_58 ( V_10 , V_122 ) ;
return V_130 ;
}
static int T_3 F_66 ( void )
{
int V_76 ;
F_10 ( L_45 , V_12 ) ;
V_76 = F_67 ( & V_131 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_67 ( & V_132 ) ;
if ( V_76 )
F_68 ( & V_131 ) ;
return V_76 ;
}
static void T_4 F_69 ( void )
{
F_10 ( L_45 , V_12 ) ;
F_68 ( & V_132 ) ;
F_68 ( & V_131 ) ;
}
