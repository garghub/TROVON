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
if ( ( V_3 -> V_9 < V_26 ) ||
( V_3 -> V_9 > V_27 ) ) {
F_6 ( & V_14 -> V_11 , L_3 ,
V_12 , V_3 -> V_9 ) ;
return;
}
if ( V_2 -> V_8 [ V_3 -> V_9 ] ) {
F_10 ( L_4 , V_12 ) ;
return;
}
V_20 = F_11 () ;
if ( F_12 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_5 ,
V_12 ) ;
return;
}
V_20 -> V_28 = & V_29 ;
V_20 -> V_30 = V_31 ;
V_20 -> V_11 . V_17 = & V_14 -> V_11 ;
V_20 -> V_32 = V_33 ;
V_20 -> V_34 = F_13 ( V_19 -> V_35 . V_36 ) ;
V_20 -> V_37 = F_13 ( V_19 -> V_35 . V_38 ) ;
snprintf ( V_20 -> V_39 , sizeof( V_20 -> V_39 ) ,
L_6 ,
V_3 -> V_22 [ V_40 ] ,
V_3 -> V_22 [ V_41 ] ) ;
F_14 ( V_19 , V_20 -> V_42 , sizeof( V_20 -> V_42 ) ) ;
snprintf ( V_21 , sizeof( V_21 ) , L_7 , V_3 -> V_9 ) ;
F_15 ( V_20 -> V_42 , V_21 , sizeof( V_20 -> V_42 ) ) ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_43 ) ;
if ( ! V_5 ) {
F_6 ( & V_14 -> V_11 , L_8 ,
V_12 ) ;
goto V_44;
}
V_5 -> V_45 = F_17 (
V_3 -> V_22 + V_46 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_9 = V_3 -> V_9 ;
V_20 -> V_47 = V_5 ;
V_2 -> V_8 [ V_3 -> V_9 ] = V_5 ;
if ( F_18 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_9 ,
V_12 ) ;
goto V_48;
}
return;
V_48:
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_5 ( V_5 ) ;
V_44:
F_4 ( V_20 ) ;
}
static void F_19 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_20 ( V_50 , struct V_1 , V_50 ) ;
struct V_3 V_3 ;
unsigned long V_6 ;
int V_51 ;
int V_52 ;
F_10 ( L_10 , V_12 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_51 = F_21 ( & V_2 -> V_53 , & V_3 ,
sizeof( struct V_3 ) ) ;
if ( V_51 != sizeof( struct V_3 ) ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_11
L_12 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
return;
}
if ( ! F_22 ( & V_2 -> V_53 ) ) {
if ( F_23 ( & V_2 -> V_50 ) == 0 ) {
F_10 ( L_13
L_14 , V_12 ) ;
}
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
switch ( V_3 . V_54 ) {
case V_55 :
F_7 ( V_2 , & V_3 ) ;
break;
case V_56 :
F_1 ( V_2 , & V_3 ) ;
break;
default:
if ( ! V_2 -> V_8 [ V_3 . V_9 ] ) {
V_52 = F_24 ( V_2 ) ;
if ( ! V_52 ) {
break;
}
F_6 ( & V_2 -> V_10 -> V_11 ,
L_15
L_16 , V_12 , V_52 ) ;
}
F_10 ( L_17 , V_12 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_26 ( & V_2 -> V_53 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_50 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_57 ;
T_1 V_58 [ V_59 ] ;
struct V_4 * V_60 ;
V_60 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( ! V_60 ) {
F_10 ( L_20
L_21 , V_3 -> V_9 ) ;
F_26 ( & V_2 -> V_53 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_50 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
return;
}
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ ) {
if ( V_60 -> V_45 & ( 1 << V_57 ) ) {
V_58 [ 0 ] = V_57 ;
if ( F_28 ( V_60 -> V_10 ,
V_62 ,
V_58 ,
V_63 [ V_57 ] , 1 ) ) {
F_10 ( L_22
L_23 ) ;
}
}
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_4 ;
V_4 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( V_4 == NULL ) {
F_10 ( L_20
L_21 , V_3 -> V_9 ) ;
F_26 ( & V_2 -> V_53 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_50 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
return;
}
if ( ( V_3 -> V_54 > F_30 ( V_63 ) - 1 ) ||
( V_63 [ V_3 -> V_54 ] == 0 ) ) {
F_10 ( L_24 , V_3 -> V_54 ) ;
return;
}
if ( F_28 ( V_4 -> V_10 ,
V_62 , & V_3 -> V_54 ,
V_63 [ V_3 -> V_54 ] , 1 ) ) {
F_10 ( L_25 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_1 * V_68 = ( T_1 * ) ( & V_3 -> V_9 ) ;
int V_57 ;
V_67 = & V_10 -> V_69 [ V_70 ] ;
V_65 = V_67 -> V_71 [ V_72 ] ;
if ( ! V_65 ) {
F_6 ( & V_10 -> V_11 , L_26 , V_12 ) ;
return - V_73 ;
}
for ( V_57 = 0 ; V_57 < V_65 -> V_74 [ 0 ] -> V_75 ; V_57 ++ )
V_65 -> V_74 [ 0 ] -> V_76 [ V_57 ] = V_68 [ V_57 ] ;
F_32 ( V_10 , V_65 , V_77 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_52 ;
if ( V_2 -> V_25 )
return 0 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_78 ;
V_3 -> V_79 = V_72 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_54 = V_80 ;
V_52 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_52 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_81 )
{
struct V_3 * V_3 ;
int V_52 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_78 ;
V_3 -> V_79 = V_72 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_54 = V_82 ;
V_3 -> V_22 [ V_83 ] = 0x3F ;
V_3 -> V_22 [ V_84 ] = ( T_1 ) V_81 ;
V_52 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_52 ;
}
static int F_34 ( struct V_13 * V_85 )
{
F_10 ( L_27 , V_12 , V_85 -> V_42 ) ;
return 0 ;
}
static void F_35 ( struct V_13 * V_85 )
{
F_10 ( L_27 , V_12 , V_85 -> V_42 ) ;
}
static int V_31 ( struct V_13 * V_85 , T_1 * V_86 ,
T_2 V_51 ,
unsigned char V_54 )
{
F_10 ( L_10 , V_12 ) ;
return 0 ;
}
static void F_36 ( char * * V_87 , unsigned int * V_88 , const char * V_68 , unsigned int V_89 )
{
memcpy ( * V_87 + * V_88 , V_68 , V_89 ) ;
* V_88 += V_89 ;
}
static int F_37 ( struct V_13 * V_85 )
{
struct V_4 * V_60 = V_85 -> V_47 ;
unsigned int V_88 = 0 ;
char * V_87 ;
int V_52 ;
F_10 ( L_10 , V_12 ) ;
V_60 -> V_10 -> V_90 = 0x0111 ;
V_60 -> V_10 -> V_91 = 0x00 ;
V_87 = F_38 ( V_92 , V_43 ) ;
if ( ! V_87 )
return - V_78 ;
if ( V_60 -> V_45 & V_93 ) {
F_10 ( L_28 ,
V_12 , V_60 -> V_45 ) ;
F_36 ( & V_87 , & V_88 , V_94 , sizeof( V_94 ) ) ;
}
if ( V_60 -> V_45 & V_95 ) {
F_10 ( L_29
L_30 , V_12 , V_60 -> V_45 ) ;
F_36 ( & V_87 , & V_88 , V_96 , sizeof( V_96 ) ) ;
}
if ( V_60 -> V_45 & V_97 ) {
F_10 ( L_31 ,
V_12 , V_60 -> V_45 ) ;
F_36 ( & V_87 , & V_88 , V_98 , sizeof( V_98 ) ) ;
}
if ( V_60 -> V_45 & V_99 ) {
F_10 ( L_32 ,
V_12 , V_60 -> V_45 ) ;
F_36 ( & V_87 , & V_88 , V_100 , sizeof( V_100 ) ) ;
}
if ( V_60 -> V_45 & V_101 ) {
F_10 ( L_33 ,
V_12 , V_60 -> V_45 ) ;
F_36 ( & V_87 , & V_88 , V_102 , sizeof( V_102 ) ) ;
}
if ( V_60 -> V_45 & V_103 ) {
F_10 ( L_34 ,
V_12 , V_60 -> V_45 ) ;
}
V_52 = F_39 ( V_85 , V_87 , V_88 ) ;
F_5 ( V_87 ) ;
return V_52 ;
}
static int F_40 ( struct V_104 * V_11 , unsigned int type ,
unsigned int V_105 , int V_76 )
{
struct V_13 * V_20 = F_41 ( V_11 ) ;
struct V_4 * V_5 = V_20 -> V_47 ;
struct V_1 * V_2 =
F_42 ( V_20 -> V_11 . V_17 ) ;
struct V_13 * V_106 = V_2 -> V_10 ;
struct V_66 * V_67 ;
struct V_107 * V_74 ;
struct V_64 * V_65 ;
unsigned char V_68 [ 8 ] ;
int V_108 ;
F_10 ( L_35 ,
V_12 , V_11 -> V_42 , type , V_105 , V_76 ) ;
if ( type != V_109 )
return - 1 ;
V_108 = F_43 ( V_20 , type , V_105 , & V_74 ) ;
if ( V_108 == - 1 ) {
F_44 ( & V_11 -> V_11 , L_36 ) ;
return - 1 ;
}
F_45 ( V_74 , V_108 , V_76 ) ;
F_46 ( V_74 -> V_65 , & V_68 [ 0 ] ) ;
V_67 = & V_106 -> V_69 [ V_70 ] ;
V_65 = V_67 -> V_71 [ V_72 ] ;
F_45 ( V_65 -> V_74 [ 0 ] , 0 , V_5 -> V_9 ) ;
F_45 ( V_65 -> V_74 [ 0 ] , 1 , V_110 ) ;
F_45 ( V_65 -> V_74 [ 0 ] , 2 , V_68 [ 1 ] ) ;
F_32 ( V_106 , V_65 , V_77 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_85 )
{
F_10 ( L_10 , V_12 ) ;
return 0 ;
}
static void F_48 ( struct V_13 * V_85 )
{
F_10 ( L_10 , V_12 ) ;
}
static int F_49 ( struct V_13 * V_10 ,
struct V_64 * V_65 , T_1 * V_68 ,
int V_89 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_68 ;
unsigned long V_6 ;
bool V_111 = false ;
F_10 ( L_37 , V_12 , V_89 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_3 -> V_79 == V_72 ) {
switch ( V_3 -> V_54 ) {
case V_55 :
case V_56 :
F_25 ( V_2 , V_3 ) ;
break;
case V_112 :
if ( V_3 -> V_22 [ V_113 ] ==
V_114 ) {
F_27 ( V_2 , V_3 ) ;
}
break;
default:
F_29 ( V_2 , V_3 ) ;
}
V_111 = true ;
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
return V_111 ;
}
static int F_51 ( struct V_13 * V_10 ,
const struct V_115 * V_116 )
{
struct V_15 * V_16 = F_8 ( V_10 -> V_11 . V_17 ) ;
struct V_1 * V_2 ;
int V_52 ;
if ( F_52 ( (struct V_4 * ) V_10 -> V_47 ) )
return - V_73 ;
F_10 ( L_38 , V_12 ,
V_16 -> V_117 -> V_118 . V_119 ) ;
if ( V_16 -> V_117 -> V_118 . V_119 !=
V_120 ) {
F_10 ( L_39 , V_12 ,
V_16 -> V_117 -> V_118 . V_119 ) ;
return - V_73 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
return - V_78 ;
}
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_50 , F_19 ) ;
F_54 ( & V_2 -> V_7 ) ;
if ( F_55 ( & V_2 -> V_53 ,
V_121 * sizeof( struct V_3 ) ,
V_43 ) ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_78 ;
}
F_56 ( V_10 , V_2 ) ;
V_52 = F_57 ( V_10 ) ;
if ( V_52 ) {
F_6 ( & V_10 -> V_11 ,
L_42 , V_12 ) ;
goto V_122;
}
V_52 = F_58 ( V_10 , V_123 ) ;
if ( V_52 ) {
F_6 ( & V_10 -> V_11 ,
L_43 , V_12 ) ;
goto V_124;
}
V_52 = F_33 ( V_2 , 0 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_44 ,
V_12 , V_52 ) ;
goto V_125;
}
V_52 = V_10 -> V_28 -> V_126 ( V_10 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 , L_45
L_16 , V_12 , V_52 ) ;
goto V_127;
}
V_52 = F_24 ( V_2 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 , L_15
L_16 , V_12 , V_52 ) ;
goto V_128;
}
return V_52 ;
V_128:
V_10 -> V_28 -> V_129 ( V_10 ) ;
V_127:
V_125:
F_59 ( V_10 ) ;
V_124:
V_122:
F_60 ( & V_2 -> V_53 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
return V_52 ;
}
static int F_61 ( struct V_13 * V_10 )
{
int V_52 ;
struct V_1 * V_2 = F_50 ( V_10 ) ;
V_52 = F_33 ( V_2 , 0 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_44 ,
V_12 , V_52 ) ;
}
return 0 ;
}
static void F_62 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_4 * V_5 ;
int V_57 ;
F_10 ( L_10 , V_12 ) ;
F_63 ( & V_2 -> V_50 ) ;
V_10 -> V_28 -> V_129 ( V_10 ) ;
F_59 ( V_10 ) ;
for ( V_57 = 0 ; V_57 < ( V_130 + V_26 ) ; V_57 ++ ) {
V_5 = V_2 -> V_8 [ V_57 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_57 ] = NULL ;
}
}
F_60 ( & V_2 -> V_53 ) ;
F_5 ( V_2 ) ;
F_56 ( V_10 , NULL ) ;
}
static int F_64 ( struct V_13 * V_10 ,
const struct V_115 * V_116 )
{
int V_131 ;
struct V_4 * V_5 = V_10 -> V_47 ;
if ( ! F_52 ( V_5 ) )
return - V_73 ;
V_131 = F_57 ( V_10 ) ;
if ( ! V_131 )
V_131 = F_58 ( V_10 , V_123 ) ;
return V_131 ;
}
static int T_3 F_65 ( void )
{
int V_52 ;
F_10 ( L_46 , V_12 ) ;
V_52 = F_66 ( & V_132 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_66 ( & V_133 ) ;
if ( V_52 )
F_67 ( & V_132 ) ;
return V_52 ;
}
static void T_4 F_68 ( void )
{
F_10 ( L_46 , V_12 ) ;
F_67 ( & V_133 ) ;
F_67 ( & V_132 ) ;
}
