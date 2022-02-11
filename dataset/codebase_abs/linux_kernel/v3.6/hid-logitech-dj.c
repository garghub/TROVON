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
int V_64 ;
if ( ! V_10 -> V_30 ) {
F_6 ( & V_10 -> V_11 , L_26
L_27 , V_12 ) ;
return - V_65 ;
}
V_64 = V_10 -> V_30 ( V_10 , ( T_1 * ) V_3 ,
sizeof( struct V_3 ) ,
V_66 ) ;
return ( V_64 < 0 ) ? V_64 : 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_52 ;
if ( V_2 -> V_25 )
return 0 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_67 ;
V_3 -> V_68 = V_69 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_54 = V_70 ;
V_52 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_52 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned V_71 )
{
struct V_3 * V_3 ;
int V_52 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_67 ;
V_3 -> V_68 = V_69 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_54 = V_72 ;
V_3 -> V_22 [ V_73 ] = 0x3F ;
V_3 -> V_22 [ V_74 ] = ( T_1 ) V_71 ;
V_52 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_52 ;
}
static int F_33 ( struct V_13 * V_75 )
{
F_10 ( L_28 , V_12 , V_75 -> V_42 ) ;
return 0 ;
}
static void F_34 ( struct V_13 * V_75 )
{
F_10 ( L_28 , V_12 , V_75 -> V_42 ) ;
}
static int V_31 ( struct V_13 * V_75 , T_1 * V_76 ,
T_2 V_51 ,
unsigned char V_54 )
{
F_10 ( L_10 , V_12 ) ;
return 0 ;
}
static void F_35 ( char * * V_77 , unsigned int * V_78 , const char * V_79 , unsigned int V_80 )
{
memcpy ( * V_77 + * V_78 , V_79 , V_80 ) ;
* V_78 += V_80 ;
}
static int F_36 ( struct V_13 * V_75 )
{
struct V_4 * V_60 = V_75 -> V_47 ;
unsigned int V_78 = 0 ;
char * V_77 ;
int V_52 ;
F_10 ( L_10 , V_12 ) ;
V_60 -> V_10 -> V_81 = 0x0111 ;
V_60 -> V_10 -> V_82 = 0x00 ;
V_77 = F_37 ( V_83 , V_43 ) ;
if ( ! V_77 )
return - V_67 ;
if ( V_60 -> V_45 & V_84 ) {
F_10 ( L_29 ,
V_12 , V_60 -> V_45 ) ;
F_35 ( & V_77 , & V_78 , V_85 , sizeof( V_85 ) ) ;
}
if ( V_60 -> V_45 & V_86 ) {
F_10 ( L_30
L_31 , V_12 , V_60 -> V_45 ) ;
F_35 ( & V_77 , & V_78 , V_87 , sizeof( V_87 ) ) ;
}
if ( V_60 -> V_45 & V_88 ) {
F_10 ( L_32 ,
V_12 , V_60 -> V_45 ) ;
F_35 ( & V_77 , & V_78 , V_89 , sizeof( V_89 ) ) ;
}
if ( V_60 -> V_45 & V_90 ) {
F_10 ( L_33 ,
V_12 , V_60 -> V_45 ) ;
F_35 ( & V_77 , & V_78 , V_91 , sizeof( V_91 ) ) ;
}
if ( V_60 -> V_45 & V_92 ) {
F_10 ( L_34 ,
V_12 , V_60 -> V_45 ) ;
F_35 ( & V_77 , & V_78 , V_93 , sizeof( V_93 ) ) ;
}
if ( V_60 -> V_45 & V_94 ) {
F_10 ( L_35 ,
V_12 , V_60 -> V_45 ) ;
}
V_52 = F_38 ( V_75 , V_77 , V_78 ) ;
F_5 ( V_77 ) ;
return V_52 ;
}
static int F_39 ( struct V_95 * V_11 , unsigned int type ,
unsigned int V_96 , int V_97 )
{
struct V_13 * V_20 = F_40 ( V_11 ) ;
struct V_4 * V_5 = V_20 -> V_47 ;
struct V_1 * V_2 =
F_41 ( V_20 -> V_11 . V_17 ) ;
struct V_13 * V_98 = V_2 -> V_10 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned char V_79 [ 8 ] ;
int V_105 ;
F_10 ( L_36 ,
V_12 , V_11 -> V_42 , type , V_96 , V_97 ) ;
if ( type != V_106 )
return - 1 ;
V_105 = F_42 ( V_20 , type , V_96 , & V_102 ) ;
if ( V_105 == - 1 ) {
F_43 ( & V_11 -> V_11 , L_37 ) ;
return - 1 ;
}
F_44 ( V_102 , V_105 , V_97 ) ;
F_45 ( V_102 -> V_104 , & V_79 [ 0 ] ) ;
V_100 = & V_98 -> V_107 [ V_66 ] ;
V_104 = V_100 -> V_108 [ V_69 ] ;
F_44 ( V_104 -> V_102 [ 0 ] , 0 , V_5 -> V_9 ) ;
F_44 ( V_104 -> V_102 [ 0 ] , 1 , V_109 ) ;
F_44 ( V_104 -> V_102 [ 0 ] , 2 , V_79 [ 1 ] ) ;
F_46 ( V_98 , V_104 , V_110 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_75 )
{
F_10 ( L_10 , V_12 ) ;
return 0 ;
}
static void F_48 ( struct V_13 * V_75 )
{
F_10 ( L_10 , V_12 ) ;
}
static int F_49 ( struct V_13 * V_10 ,
struct V_103 * V_104 , T_1 * V_79 ,
int V_80 )
{
struct V_1 * V_2 = F_50 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_79 ;
unsigned long V_6 ;
bool V_111 = false ;
F_10 ( L_38 , V_12 , V_80 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_3 -> V_68 == V_69 ) {
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
return - V_65 ;
F_10 ( L_39 , V_12 ,
V_16 -> V_117 -> V_118 . V_119 ) ;
if ( V_16 -> V_117 -> V_118 . V_119 !=
V_120 ) {
F_10 ( L_40 , V_12 ,
V_16 -> V_117 -> V_118 . V_119 ) ;
return - V_65 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
return - V_67 ;
}
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_50 , F_19 ) ;
F_54 ( & V_2 -> V_7 ) ;
if ( F_55 ( & V_2 -> V_53 ,
V_121 * sizeof( struct V_3 ) ,
V_43 ) ) {
F_6 ( & V_10 -> V_11 ,
L_42 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_67 ;
}
F_56 ( V_10 , V_2 ) ;
V_52 = F_57 ( V_10 ) ;
if ( V_52 ) {
F_6 ( & V_10 -> V_11 ,
L_43 , V_12 ) ;
goto V_122;
}
V_52 = F_58 ( V_10 , V_123 ) ;
if ( V_52 ) {
F_6 ( & V_10 -> V_11 ,
L_44 , V_12 ) ;
goto V_124;
}
V_52 = F_32 ( V_2 , 0 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_45 ,
V_12 , V_52 ) ;
goto V_125;
}
V_52 = V_10 -> V_28 -> V_126 ( V_10 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 , L_46
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
V_52 = F_32 ( V_2 , 0 ) ;
if ( V_52 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_45 ,
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
return - V_65 ;
V_131 = F_57 ( V_10 ) ;
if ( ! V_131 )
V_131 = F_58 ( V_10 , V_123 ) ;
return V_131 ;
}
static int T_3 F_65 ( void )
{
int V_52 ;
F_10 ( L_47 , V_12 ) ;
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
F_10 ( L_47 , V_12 ) ;
F_67 ( & V_133 ) ;
F_67 ( & V_132 ) ;
}
