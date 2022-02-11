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
int V_62 ;
if ( ! V_10 -> V_29 ) {
F_6 ( & V_10 -> V_11 , L_23
L_24 , V_12 ) ;
return - V_63 ;
}
V_62 = V_10 -> V_29 ( V_10 , ( T_1 * ) V_3 ,
sizeof( struct V_3 ) ,
V_64 ) ;
return ( V_62 < 0 ) ? V_62 : 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_65 ;
V_3 = F_16 ( sizeof( V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_67 = V_68 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_69 ;
V_65 = F_30 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_65 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned V_70 )
{
struct V_3 * V_3 ;
int V_65 ;
V_3 = F_16 ( sizeof( V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_67 = V_68 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_71 ;
V_3 -> V_22 [ V_72 ] = 0x3F ;
V_3 -> V_22 [ V_73 ] = ( T_1 ) V_70 ;
V_65 = F_30 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_65 ;
}
static int F_33 ( struct V_13 * V_74 )
{
F_10 ( L_25 , V_12 , V_74 -> V_41 ) ;
return 0 ;
}
static void F_34 ( struct V_13 * V_74 )
{
F_10 ( L_25 , V_12 , V_74 -> V_41 ) ;
}
static int V_30 ( struct V_13 * V_74 , T_1 * V_75 ,
T_2 V_50 ,
unsigned char V_52 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_35 ( char * * V_76 , unsigned int * V_77 , const char * V_78 , unsigned int V_79 )
{
memcpy ( * V_76 + * V_77 , V_78 , V_79 ) ;
* V_77 += V_79 ;
}
static int F_36 ( struct V_13 * V_74 )
{
struct V_4 * V_58 = V_74 -> V_46 ;
unsigned int V_77 = 0 ;
char * V_76 ;
int V_65 ;
F_10 ( L_9 , V_12 ) ;
V_58 -> V_10 -> V_80 = 0x0111 ;
V_58 -> V_10 -> V_81 = 0x00 ;
V_76 = F_37 ( V_82 , V_42 ) ;
if ( ! V_76 )
return - V_66 ;
if ( V_58 -> V_44 & V_83 ) {
F_10 ( L_26 ,
V_12 , V_58 -> V_44 ) ;
F_35 ( & V_76 , & V_77 , V_84 , sizeof( V_84 ) ) ;
}
if ( V_58 -> V_44 & V_85 ) {
F_10 ( L_27
L_28 , V_12 , V_58 -> V_44 ) ;
F_35 ( & V_76 , & V_77 , V_86 , sizeof( V_86 ) ) ;
}
if ( V_58 -> V_44 & V_87 ) {
F_10 ( L_29 ,
V_12 , V_58 -> V_44 ) ;
F_35 ( & V_76 , & V_77 , V_88 , sizeof( V_88 ) ) ;
}
if ( V_58 -> V_44 & V_89 ) {
F_10 ( L_30 ,
V_12 , V_58 -> V_44 ) ;
F_35 ( & V_76 , & V_77 , V_90 , sizeof( V_90 ) ) ;
}
if ( V_58 -> V_44 & V_91 ) {
F_10 ( L_31 ,
V_12 , V_58 -> V_44 ) ;
F_35 ( & V_76 , & V_77 , V_92 , sizeof( V_92 ) ) ;
}
if ( V_58 -> V_44 & V_93 ) {
F_10 ( L_32 ,
V_12 , V_58 -> V_44 ) ;
}
V_65 = F_38 ( V_74 , V_76 , V_77 ) ;
F_5 ( V_76 ) ;
return V_65 ;
}
static int F_39 ( struct V_94 * V_11 , unsigned int type ,
unsigned int V_95 , int V_96 )
{
struct V_13 * V_20 = F_40 ( V_11 ) ;
struct V_4 * V_5 = V_20 -> V_46 ;
struct V_1 * V_2 =
F_41 ( V_20 -> V_11 . V_17 ) ;
struct V_13 * V_97 = V_2 -> V_10 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
unsigned char V_78 [ 8 ] ;
int V_104 ;
F_10 ( L_33 ,
V_12 , V_11 -> V_41 , type , V_95 , V_96 ) ;
if ( type != V_105 )
return - 1 ;
V_104 = F_42 ( V_20 , type , V_95 , & V_101 ) ;
if ( V_104 == - 1 ) {
F_43 ( & V_11 -> V_11 , L_34 ) ;
return - 1 ;
}
F_44 ( V_101 , V_104 , V_96 ) ;
F_45 ( V_101 -> V_103 , & V_78 [ 0 ] ) ;
V_99 = & V_97 -> V_106 [ V_64 ] ;
V_103 = V_99 -> V_107 [ V_68 ] ;
F_44 ( V_103 -> V_101 [ 0 ] , 0 , V_5 -> V_9 ) ;
F_44 ( V_103 -> V_101 [ 0 ] , 1 , V_108 ) ;
F_44 ( V_103 -> V_101 [ 0 ] , 2 , V_78 [ 1 ] ) ;
F_46 ( V_97 , V_103 , V_109 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_74 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_48 ( struct V_13 * V_74 )
{
F_10 ( L_9 , V_12 ) ;
}
static int F_49 ( struct V_13 * V_10 ,
struct V_102 * V_103 , T_1 * V_78 ,
int V_79 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_78 ;
unsigned long V_6 ;
bool V_110 = false ;
F_10 ( L_35 , V_12 , V_79 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_3 -> V_67 == V_68 ) {
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
int V_65 ;
if ( F_52 ( (struct V_4 * ) V_10 -> V_46 ) )
return - V_63 ;
F_10 ( L_36 , V_12 ,
V_16 -> V_116 -> V_117 . V_118 ) ;
if ( V_16 -> V_116 -> V_117 . V_118 !=
V_119 ) {
F_10 ( L_37 , V_12 ,
V_16 -> V_116 -> V_117 . V_118 ) ;
return - V_63 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_38 , V_12 ) ;
return - V_66 ;
}
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_49 , F_19 ) ;
F_54 ( & V_2 -> V_7 ) ;
if ( F_55 ( & V_2 -> V_51 ,
V_120 * sizeof( struct V_3 ) ,
V_42 ) ) {
F_6 ( & V_10 -> V_11 ,
L_39 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_66 ;
}
F_56 ( V_10 , V_2 ) ;
V_65 = F_57 ( V_10 ) ;
if ( V_65 ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
goto V_121;
}
V_65 = F_58 ( V_10 , V_122 ) ;
if ( V_65 ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
goto V_123;
}
V_65 = F_32 ( V_2 , 0 ) ;
if ( V_65 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_65 ) ;
goto V_124;
}
V_65 = V_10 -> V_27 -> V_125 ( V_10 ) ;
if ( V_65 < 0 ) {
F_6 ( & V_10 -> V_11 , L_43
L_44 , V_12 , V_65 ) ;
goto V_126;
}
V_65 = F_31 ( V_2 ) ;
if ( V_65 < 0 ) {
F_6 ( & V_10 -> V_11 , L_45
L_44 , V_12 , V_65 ) ;
goto V_127;
}
return V_65 ;
V_127:
V_10 -> V_27 -> V_128 ( V_10 ) ;
V_126:
V_124:
F_59 ( V_10 ) ;
V_123:
V_121:
F_60 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
return V_65 ;
}
static int F_61 ( struct V_13 * V_10 )
{
int V_65 ;
struct V_1 * V_2 = F_50 ( V_10 ) ;
V_65 = F_32 ( V_2 , 0 ) ;
if ( V_65 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_65 ) ;
}
return 0 ;
}
static void F_62 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_4 * V_5 ;
int V_55 ;
F_10 ( L_9 , V_12 ) ;
F_63 ( & V_2 -> V_49 ) ;
V_10 -> V_27 -> V_128 ( V_10 ) ;
F_59 ( V_10 ) ;
for ( V_55 = 0 ; V_55 < ( V_129 + V_25 ) ; V_55 ++ ) {
V_5 = V_2 -> V_8 [ V_55 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_55 ] = NULL ;
}
}
F_60 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
}
static int F_64 ( struct V_13 * V_10 ,
const struct V_114 * V_115 )
{
int V_130 ;
struct V_4 * V_5 = V_10 -> V_46 ;
if ( ! F_52 ( V_5 ) )
return - V_63 ;
V_130 = F_57 ( V_10 ) ;
if ( ! V_130 )
V_130 = F_58 ( V_10 , V_122 ) ;
return V_130 ;
}
static int T_3 F_65 ( void )
{
int V_65 ;
F_10 ( L_46 , V_12 ) ;
V_65 = F_66 ( & V_131 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_66 ( & V_132 ) ;
if ( V_65 )
F_67 ( & V_131 ) ;
return V_65 ;
}
static void T_4 F_68 ( void )
{
F_10 ( L_46 , V_12 ) ;
F_67 ( & V_132 ) ;
F_67 ( & V_131 ) ;
}
