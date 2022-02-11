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
V_20 -> V_11 . V_17 = & V_14 -> V_11 ;
V_20 -> V_30 = V_31 ;
V_20 -> V_32 = F_13 ( V_19 -> V_33 . V_34 ) ;
V_20 -> V_35 = F_13 ( V_19 -> V_33 . V_36 ) ;
snprintf ( V_20 -> V_37 , sizeof( V_20 -> V_37 ) ,
L_6 ,
V_3 -> V_22 [ V_38 ] ,
V_3 -> V_22 [ V_39 ] ) ;
F_14 ( V_19 , V_20 -> V_40 , sizeof( V_20 -> V_40 ) ) ;
snprintf ( V_21 , sizeof( V_21 ) , L_7 , V_3 -> V_9 ) ;
F_15 ( V_20 -> V_40 , V_21 , sizeof( V_20 -> V_40 ) ) ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_41 ) ;
if ( ! V_5 ) {
F_6 ( & V_14 -> V_11 , L_8 ,
V_12 ) ;
goto V_42;
}
V_5 -> V_43 = F_17 (
V_3 -> V_22 + V_44 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_9 = V_3 -> V_9 ;
V_20 -> V_45 = V_5 ;
V_2 -> V_8 [ V_3 -> V_9 ] = V_5 ;
if ( F_18 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_9 ,
V_12 ) ;
goto V_46;
}
return;
V_46:
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_5 ( V_5 ) ;
V_42:
F_4 ( V_20 ) ;
}
static void F_19 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
F_20 ( V_48 , struct V_1 , V_48 ) ;
struct V_3 V_3 ;
unsigned long V_6 ;
int V_49 ;
int V_50 ;
F_10 ( L_10 , V_12 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_49 = F_21 ( & V_2 -> V_51 , & V_3 ,
sizeof( struct V_3 ) ) ;
if ( V_49 != sizeof( struct V_3 ) ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_11
L_12 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
return;
}
if ( ! F_22 ( & V_2 -> V_51 ) ) {
if ( F_23 ( & V_2 -> V_48 ) == 0 ) {
F_10 ( L_13
L_14 , V_12 ) ;
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
if ( ! V_2 -> V_8 [ V_3 . V_9 ] ) {
V_50 = F_24 ( V_2 ) ;
if ( ! V_50 ) {
break;
}
F_6 ( & V_2 -> V_10 -> V_11 ,
L_15
L_16 , V_12 , V_50 ) ;
}
F_10 ( L_17 , V_12 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_26 ( & V_2 -> V_51 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_48 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_55 ;
T_1 V_56 [ V_57 ] ;
struct V_4 * V_58 ;
V_58 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( ! V_58 ) {
F_10 ( L_20
L_21 , V_3 -> V_9 ) ;
F_26 ( & V_2 -> V_51 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_48 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
return;
}
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
for ( V_55 = 0 ; V_55 < V_59 ; V_55 ++ ) {
if ( V_58 -> V_43 & ( 1 << V_55 ) ) {
V_56 [ 0 ] = V_55 ;
if ( F_28 ( V_58 -> V_10 ,
V_60 ,
V_56 ,
V_61 [ V_55 ] , 1 ) ) {
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
F_26 ( & V_2 -> V_51 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_48 ) == 0 ) {
F_10 ( L_18
L_19 , V_12 ) ;
}
return;
}
if ( ( V_3 -> V_52 > F_30 ( V_61 ) - 1 ) ||
( V_61 [ V_3 -> V_52 ] == 0 ) ) {
F_10 ( L_24 , V_3 -> V_52 ) ;
return;
}
if ( F_28 ( V_4 -> V_10 ,
V_60 , & V_3 -> V_52 ,
V_61 [ V_3 -> V_52 ] , 1 ) ) {
F_10 ( L_25 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_1 * V_66 = ( T_1 * ) ( & V_3 -> V_9 ) ;
unsigned int V_55 ;
V_65 = & V_10 -> V_67 [ V_68 ] ;
V_63 = V_65 -> V_69 [ V_70 ] ;
if ( ! V_63 ) {
F_6 ( & V_10 -> V_11 , L_26 , V_12 ) ;
return - V_71 ;
}
for ( V_55 = 0 ; V_55 < V_72 - 1 ; V_55 ++ )
V_63 -> V_73 [ 0 ] -> V_74 [ V_55 ] = V_66 [ V_55 ] ;
F_32 ( V_10 , V_63 , V_75 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_50 ;
if ( V_2 -> V_25 )
return 0 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_76 ;
V_3 -> V_77 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_78 ;
V_50 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_50 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_79 )
{
struct V_3 * V_3 ;
int V_50 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_41 ) ;
if ( ! V_3 )
return - V_76 ;
V_3 -> V_77 = V_70 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_52 = V_80 ;
V_3 -> V_22 [ V_81 ] = 0x3F ;
V_3 -> V_22 [ V_82 ] = ( T_1 ) V_79 ;
V_50 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
F_34 ( 50 ) ;
return V_50 ;
}
static int F_35 ( struct V_13 * V_83 )
{
F_10 ( L_27 , V_12 , V_83 -> V_40 ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_83 )
{
F_10 ( L_27 , V_12 , V_83 -> V_40 ) ;
}
static int F_37 ( struct V_13 * V_83 ,
unsigned char V_84 , T_2 * V_85 ,
T_3 V_49 , unsigned char V_52 ,
int V_86 )
{
struct V_4 * V_58 = V_83 -> V_45 ;
struct V_1 * V_2 = V_58 -> V_1 ;
T_1 * V_87 ;
int V_88 ;
if ( V_85 [ 0 ] != V_89 )
return - V_90 ;
V_87 = F_16 ( V_72 , V_91 ) ;
if ( ! V_87 )
return - V_76 ;
if ( V_49 < V_72 - 2 )
V_49 = V_72 - 2 ;
V_87 [ 0 ] = V_70 ;
V_87 [ 1 ] = V_58 -> V_9 ;
memcpy ( V_87 + 2 , V_85 , V_49 ) ;
V_88 = F_38 ( V_2 -> V_10 , V_87 [ 0 ] , V_87 ,
V_72 , V_52 , V_86 ) ;
F_5 ( V_87 ) ;
return V_88 ;
}
static void F_39 ( char * V_92 , unsigned int * V_93 , const char * V_66 , unsigned int V_94 )
{
memcpy ( V_92 + * V_93 , V_66 , V_94 ) ;
* V_93 += V_94 ;
}
static int F_40 ( struct V_13 * V_83 )
{
struct V_4 * V_58 = V_83 -> V_45 ;
unsigned int V_93 = 0 ;
char * V_92 ;
int V_50 ;
F_10 ( L_10 , V_12 ) ;
V_58 -> V_10 -> V_95 = 0x0111 ;
V_58 -> V_10 -> V_96 = 0x00 ;
V_92 = F_41 ( V_97 , V_41 ) ;
if ( ! V_92 )
return - V_76 ;
if ( V_58 -> V_43 & V_98 ) {
F_10 ( L_28 ,
V_12 , V_58 -> V_43 ) ;
F_39 ( V_92 , & V_93 , V_99 , sizeof( V_99 ) ) ;
}
if ( V_58 -> V_43 & V_100 ) {
F_10 ( L_29
L_30 , V_12 , V_58 -> V_43 ) ;
F_39 ( V_92 , & V_93 , V_101 , sizeof( V_101 ) ) ;
}
if ( V_58 -> V_43 & V_102 ) {
F_10 ( L_31 ,
V_12 , V_58 -> V_43 ) ;
F_39 ( V_92 , & V_93 , V_103 , sizeof( V_103 ) ) ;
}
if ( V_58 -> V_43 & V_104 ) {
F_10 ( L_32 ,
V_12 , V_58 -> V_43 ) ;
F_39 ( V_92 , & V_93 , V_105 , sizeof( V_105 ) ) ;
}
if ( V_58 -> V_43 & V_106 ) {
F_10 ( L_33 ,
V_12 , V_58 -> V_43 ) ;
F_39 ( V_92 , & V_93 , V_107 , sizeof( V_107 ) ) ;
}
if ( V_58 -> V_43 & V_108 ) {
F_10 ( L_34 ,
V_12 , V_58 -> V_43 ) ;
}
V_50 = F_42 ( V_83 , V_92 , V_93 ) ;
F_5 ( V_92 ) ;
return V_50 ;
}
static int F_43 ( struct V_13 * V_83 )
{
F_10 ( L_10 , V_12 ) ;
return 0 ;
}
static void F_44 ( struct V_13 * V_83 )
{
F_10 ( L_10 , V_12 ) ;
}
static int F_45 ( struct V_13 * V_10 ,
struct V_62 * V_63 , T_1 * V_66 ,
int V_94 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_66 ;
unsigned long V_6 ;
bool V_109 = false ;
F_10 ( L_35 , V_12 , V_94 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_3 -> V_77 == V_70 ) {
switch ( V_3 -> V_52 ) {
case V_53 :
case V_54 :
F_25 ( V_2 , V_3 ) ;
break;
case V_110 :
if ( V_3 -> V_22 [ V_111 ] ==
V_112 ) {
F_27 ( V_2 , V_3 ) ;
}
break;
default:
F_29 ( V_2 , V_3 ) ;
}
V_109 = true ;
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
return V_109 ;
}
static int F_47 ( struct V_13 * V_10 ,
const struct V_113 * V_114 )
{
struct V_15 * V_16 = F_8 ( V_10 -> V_11 . V_17 ) ;
struct V_1 * V_2 ;
int V_50 ;
if ( F_48 ( (struct V_4 * ) V_10 -> V_45 ) )
return - V_71 ;
F_10 ( L_36 , V_12 ,
V_16 -> V_115 -> V_116 . V_117 ) ;
if ( V_16 -> V_115 -> V_116 . V_117 !=
V_118 ) {
F_10 ( L_37 , V_12 ,
V_16 -> V_115 -> V_116 . V_117 ) ;
return - V_71 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_38 , V_12 ) ;
return - V_76 ;
}
V_2 -> V_10 = V_10 ;
F_49 ( & V_2 -> V_48 , F_19 ) ;
F_50 ( & V_2 -> V_7 ) ;
if ( F_51 ( & V_2 -> V_51 ,
V_119 * sizeof( struct V_3 ) ,
V_41 ) ) {
F_6 ( & V_10 -> V_11 ,
L_39 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_76 ;
}
F_52 ( V_10 , V_2 ) ;
V_50 = F_53 ( V_10 ) ;
if ( V_50 ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
goto V_120;
}
if ( ! F_54 ( V_10 , V_68 , V_70 ,
0 , V_72 - 1 ) ) {
V_50 = - V_71 ;
goto V_120;
}
V_50 = F_55 ( V_10 , V_121 ) ;
if ( V_50 ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
goto V_122;
}
V_50 = F_33 ( V_2 , 0 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_50 ) ;
goto V_123;
}
V_50 = F_56 ( V_10 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_10 -> V_11 , L_43 ,
V_12 , V_50 ) ;
goto V_124;
}
F_57 ( V_10 ) ;
V_50 = F_24 ( V_2 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_10 -> V_11 , L_15
L_16 , V_12 , V_50 ) ;
goto V_125;
}
return V_50 ;
V_125:
F_58 ( V_10 ) ;
V_124:
V_123:
F_59 ( V_10 ) ;
V_122:
V_120:
F_60 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_52 ( V_10 , NULL ) ;
return V_50 ;
}
static int F_61 ( struct V_13 * V_10 )
{
int V_50 ;
struct V_1 * V_2 = F_46 ( V_10 ) ;
V_50 = F_33 ( V_2 , 0 ) ;
if ( V_50 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_50 ) ;
}
return 0 ;
}
static void F_62 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
struct V_4 * V_5 ;
int V_55 ;
F_10 ( L_10 , V_12 ) ;
F_63 ( & V_2 -> V_48 ) ;
F_58 ( V_10 ) ;
F_59 ( V_10 ) ;
for ( V_55 = 0 ; V_55 < ( V_126 + V_26 ) ; V_55 ++ ) {
V_5 = V_2 -> V_8 [ V_55 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_55 ] = NULL ;
}
}
F_60 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
F_52 ( V_10 , NULL ) ;
}
static int F_64 ( struct V_13 * V_10 ,
const struct V_113 * V_114 )
{
int V_88 ;
struct V_4 * V_5 = V_10 -> V_45 ;
if ( ! F_48 ( V_5 ) )
return - V_71 ;
V_88 = F_53 ( V_10 ) ;
if ( ! V_88 )
V_88 = F_55 ( V_10 , V_121 ) ;
return V_88 ;
}
static int T_4 F_65 ( void )
{
int V_50 ;
F_10 ( L_44 , V_12 ) ;
V_50 = F_66 ( & V_127 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_66 ( & V_128 ) ;
if ( V_50 )
F_67 ( & V_127 ) ;
return V_50 ;
}
static void T_5 F_68 ( void )
{
F_10 ( L_44 , V_12 ) ;
F_67 ( & V_128 ) ;
F_67 ( & V_127 ) ;
}
