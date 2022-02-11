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
V_20 -> V_33 = F_13 ( V_19 -> V_31 . V_34 ) ;
snprintf ( V_20 -> V_35 , sizeof( V_20 -> V_35 ) ,
L_5 ,
V_3 -> V_22 [ V_36 ] ,
V_3 -> V_22 [ V_37 ] ) ;
F_14 ( V_19 , V_20 -> V_38 , sizeof( V_20 -> V_38 ) ) ;
snprintf ( V_21 , sizeof( V_21 ) , L_6 , V_3 -> V_9 ) ;
F_15 ( V_20 -> V_38 , V_21 , sizeof( V_20 -> V_38 ) ) ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_39 ) ;
if ( ! V_5 ) {
F_6 ( & V_14 -> V_11 , L_7 ,
V_12 ) ;
goto V_40;
}
V_5 -> V_41 = F_17 (
V_3 -> V_22 + V_42 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_9 = V_3 -> V_9 ;
V_20 -> V_43 = V_5 ;
V_2 -> V_8 [ V_3 -> V_9 ] = V_5 ;
if ( F_18 ( V_20 ) ) {
F_6 ( & V_14 -> V_11 , L_8 ,
V_12 ) ;
goto V_44;
}
return;
V_44:
V_2 -> V_8 [ V_3 -> V_9 ] = NULL ;
F_5 ( V_5 ) ;
V_40:
F_4 ( V_20 ) ;
}
static void F_19 ( struct V_45 * V_46 )
{
struct V_1 * V_2 =
F_20 ( V_46 , struct V_1 , V_46 ) ;
struct V_3 V_3 ;
unsigned long V_6 ;
int V_47 ;
int V_48 ;
F_10 ( L_9 , V_12 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_47 = F_21 ( & V_2 -> V_49 , & V_3 ,
sizeof( struct V_3 ) ) ;
if ( V_47 != sizeof( struct V_3 ) ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_10
L_11 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_6 ) ;
return;
}
if ( ! F_22 ( & V_2 -> V_49 ) ) {
if ( F_23 ( & V_2 -> V_46 ) == 0 ) {
F_10 ( L_12
L_13 , V_12 ) ;
}
}
F_3 ( & V_2 -> V_7 , V_6 ) ;
switch ( V_3 . V_50 ) {
case V_51 :
F_7 ( V_2 , & V_3 ) ;
break;
case V_52 :
F_1 ( V_2 , & V_3 ) ;
break;
default:
if ( ! V_2 -> V_8 [ V_3 . V_9 ] ) {
V_48 = F_24 ( V_2 ) ;
if ( ! V_48 ) {
break;
}
F_6 ( & V_2 -> V_10 -> V_11 ,
L_14
L_15 , V_12 , V_48 ) ;
}
F_10 ( L_16 , V_12 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_26 ( & V_2 -> V_49 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_46 ) == 0 ) {
F_10 ( L_17
L_18 , V_12 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
unsigned int V_53 ;
T_1 V_54 [ V_55 ] ;
struct V_4 * V_56 ;
V_56 = V_2 -> V_8 [ V_3 -> V_9 ] ;
if ( ! V_56 ) {
F_10 ( L_19
L_20 , V_3 -> V_9 ) ;
F_26 ( & V_2 -> V_49 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_46 ) == 0 ) {
F_10 ( L_17
L_18 , V_12 ) ;
}
return;
}
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
for ( V_53 = 0 ; V_53 < V_57 ; V_53 ++ ) {
if ( V_56 -> V_41 & ( 1 << V_53 ) ) {
V_54 [ 0 ] = V_53 ;
if ( F_28 ( V_56 -> V_10 ,
V_58 ,
V_54 ,
V_59 [ V_53 ] , 1 ) ) {
F_10 ( L_21
L_22 ) ;
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
F_10 ( L_19
L_20 , V_3 -> V_9 ) ;
F_26 ( & V_2 -> V_49 , V_3 , sizeof( struct V_3 ) ) ;
if ( F_23 ( & V_2 -> V_46 ) == 0 ) {
F_10 ( L_17
L_18 , V_12 ) ;
}
return;
}
if ( ( V_3 -> V_50 > F_30 ( V_59 ) - 1 ) ||
( V_59 [ V_3 -> V_50 ] == 0 ) ) {
F_10 ( L_23 , V_3 -> V_50 ) ;
return;
}
if ( F_28 ( V_4 -> V_10 ,
V_58 , & V_3 -> V_50 ,
V_59 [ V_3 -> V_50 ] , 1 ) ) {
F_10 ( L_24 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_13 * V_10 = V_2 -> V_10 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
T_1 * V_64 = ( T_1 * ) ( & V_3 -> V_9 ) ;
unsigned int V_53 ;
V_63 = & V_10 -> V_65 [ V_66 ] ;
V_61 = V_63 -> V_67 [ V_68 ] ;
if ( ! V_61 ) {
F_6 ( & V_10 -> V_11 , L_25 , V_12 ) ;
return - V_69 ;
}
for ( V_53 = 0 ; V_53 < V_70 - 1 ; V_53 ++ )
V_61 -> V_71 [ 0 ] -> V_72 [ V_53 ] = V_64 [ V_53 ] ;
F_32 ( V_10 , V_61 , V_73 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_48 ;
if ( V_2 -> V_25 )
return 0 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_3 )
return - V_74 ;
V_3 -> V_75 = V_68 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_50 = V_76 ;
V_48 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
return V_48 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned V_77 )
{
struct V_3 * V_3 ;
int V_48 ;
V_3 = F_16 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_3 )
return - V_74 ;
V_3 -> V_75 = V_68 ;
V_3 -> V_9 = 0xFF ;
V_3 -> V_50 = V_78 ;
V_3 -> V_22 [ V_79 ] = 0x3F ;
V_3 -> V_22 [ V_80 ] = ( T_1 ) V_77 ;
V_48 = F_31 ( V_2 , V_3 ) ;
F_5 ( V_3 ) ;
F_34 ( 50 ) ;
return V_48 ;
}
static int F_35 ( struct V_13 * V_81 )
{
F_10 ( L_26 , V_12 , V_81 -> V_38 ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_81 )
{
F_10 ( L_26 , V_12 , V_81 -> V_38 ) ;
}
static int F_37 ( struct V_13 * V_81 ,
unsigned char V_82 , T_2 * V_83 ,
T_3 V_47 , unsigned char V_50 ,
int V_84 )
{
struct V_4 * V_56 = V_81 -> V_43 ;
struct V_1 * V_2 = V_56 -> V_1 ;
T_1 * V_85 ;
int V_86 ;
if ( V_83 [ 0 ] != V_87 )
return - V_88 ;
V_85 = F_16 ( V_70 , V_89 ) ;
if ( ! V_85 )
return - V_74 ;
if ( V_47 > V_70 - 2 )
V_47 = V_70 - 2 ;
V_85 [ 0 ] = V_68 ;
V_85 [ 1 ] = V_56 -> V_9 ;
memcpy ( V_85 + 2 , V_83 , V_47 ) ;
V_86 = F_38 ( V_2 -> V_10 , V_85 [ 0 ] , V_85 ,
V_70 , V_50 , V_84 ) ;
F_5 ( V_85 ) ;
return V_86 ;
}
static void F_39 ( char * V_90 , unsigned int * V_91 , const char * V_64 , unsigned int V_92 )
{
memcpy ( V_90 + * V_91 , V_64 , V_92 ) ;
* V_91 += V_92 ;
}
static int F_40 ( struct V_13 * V_81 )
{
struct V_4 * V_56 = V_81 -> V_43 ;
unsigned int V_91 = 0 ;
char * V_90 ;
int V_48 ;
F_10 ( L_9 , V_12 ) ;
V_56 -> V_10 -> V_93 = 0x0111 ;
V_56 -> V_10 -> V_94 = 0x00 ;
V_90 = F_41 ( V_95 , V_39 ) ;
if ( ! V_90 )
return - V_74 ;
if ( V_56 -> V_41 & V_96 ) {
F_10 ( L_27 ,
V_12 , V_56 -> V_41 ) ;
F_39 ( V_90 , & V_91 , V_97 , sizeof( V_97 ) ) ;
}
if ( V_56 -> V_41 & V_98 ) {
F_10 ( L_28
L_29 , V_12 , V_56 -> V_41 ) ;
F_39 ( V_90 , & V_91 , V_99 , sizeof( V_99 ) ) ;
}
if ( V_56 -> V_41 & V_100 ) {
F_10 ( L_30 ,
V_12 , V_56 -> V_41 ) ;
F_39 ( V_90 , & V_91 , V_101 , sizeof( V_101 ) ) ;
}
if ( V_56 -> V_41 & V_102 ) {
F_10 ( L_31 ,
V_12 , V_56 -> V_41 ) ;
F_39 ( V_90 , & V_91 , V_103 , sizeof( V_103 ) ) ;
}
if ( V_56 -> V_41 & V_104 ) {
F_10 ( L_32 ,
V_12 , V_56 -> V_41 ) ;
F_39 ( V_90 , & V_91 , V_105 , sizeof( V_105 ) ) ;
}
if ( V_56 -> V_41 & V_106 ) {
F_10 ( L_33 ,
V_12 , V_56 -> V_41 ) ;
}
V_48 = F_42 ( V_81 , V_90 , V_91 ) ;
F_5 ( V_90 ) ;
return V_48 ;
}
static int F_43 ( struct V_13 * V_81 )
{
F_10 ( L_9 , V_12 ) ;
return 0 ;
}
static void F_44 ( struct V_13 * V_81 )
{
F_10 ( L_9 , V_12 ) ;
}
static int F_45 ( struct V_13 * V_10 ,
struct V_60 * V_61 , T_1 * V_64 ,
int V_92 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
struct V_3 * V_3 = (struct V_3 * ) V_64 ;
unsigned long V_6 ;
F_10 ( L_34 , V_12 , V_92 ) ;
if ( V_64 [ 0 ] != V_68 )
return false ;
if ( ( V_3 -> V_9 < V_107 ) ||
( V_3 -> V_9 > V_108 ) ) {
if ( V_3 -> V_9 != V_109 )
F_6 ( & V_10 -> V_11 , L_35 ,
V_12 , V_3 -> V_9 ) ;
return false ;
}
F_2 ( & V_2 -> V_7 , V_6 ) ;
switch ( V_3 -> V_50 ) {
case V_51 :
case V_52 :
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
F_3 ( & V_2 -> V_7 , V_6 ) ;
return true ;
}
static int F_47 ( struct V_13 * V_10 ,
const struct V_113 * V_114 )
{
struct V_15 * V_16 = F_8 ( V_10 -> V_11 . V_17 ) ;
struct V_1 * V_2 ;
int V_48 ;
if ( F_48 ( (struct V_4 * ) V_10 -> V_43 ) )
return - V_69 ;
F_10 ( L_36 , V_12 ,
V_16 -> V_115 -> V_116 . V_117 ) ;
if ( V_16 -> V_115 -> V_116 . V_117 !=
V_118 ) {
F_10 ( L_37 , V_12 ,
V_16 -> V_115 -> V_116 . V_117 ) ;
return - V_69 ;
}
V_2 = F_16 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_2 ) {
F_6 ( & V_10 -> V_11 ,
L_38 , V_12 ) ;
return - V_74 ;
}
V_2 -> V_10 = V_10 ;
F_49 ( & V_2 -> V_46 , F_19 ) ;
F_50 ( & V_2 -> V_7 ) ;
if ( F_51 ( & V_2 -> V_49 ,
V_119 * sizeof( struct V_3 ) ,
V_39 ) ) {
F_6 ( & V_10 -> V_11 ,
L_39 , V_12 ) ;
F_5 ( V_2 ) ;
return - V_74 ;
}
F_52 ( V_10 , V_2 ) ;
V_48 = F_53 ( V_10 ) ;
if ( V_48 ) {
F_6 ( & V_10 -> V_11 ,
L_40 , V_12 ) ;
goto V_120;
}
if ( ! F_54 ( V_10 , V_66 , V_68 ,
0 , V_70 - 1 ) ) {
V_48 = - V_69 ;
goto V_120;
}
V_48 = F_55 ( V_10 , V_121 ) ;
if ( V_48 ) {
F_6 ( & V_10 -> V_11 ,
L_41 , V_12 ) ;
goto V_122;
}
V_48 = F_33 ( V_2 , 0 ) ;
if ( V_48 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_48 ) ;
goto V_123;
}
V_48 = F_56 ( V_10 ) ;
if ( V_48 < 0 ) {
F_6 ( & V_10 -> V_11 , L_43 ,
V_12 , V_48 ) ;
goto V_124;
}
F_57 ( V_10 ) ;
V_48 = F_24 ( V_2 ) ;
if ( V_48 < 0 ) {
F_6 ( & V_10 -> V_11 , L_14
L_15 , V_12 , V_48 ) ;
goto V_125;
}
return V_48 ;
V_125:
F_58 ( V_10 ) ;
V_124:
V_123:
F_59 ( V_10 ) ;
V_122:
V_120:
F_60 ( & V_2 -> V_49 ) ;
F_5 ( V_2 ) ;
F_52 ( V_10 , NULL ) ;
return V_48 ;
}
static int F_61 ( struct V_13 * V_10 )
{
int V_48 ;
struct V_1 * V_2 = F_46 ( V_10 ) ;
V_48 = F_33 ( V_2 , 0 ) ;
if ( V_48 < 0 ) {
F_6 ( & V_10 -> V_11 ,
L_42 ,
V_12 , V_48 ) ;
}
return 0 ;
}
static void F_62 ( struct V_13 * V_10 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
struct V_4 * V_5 ;
int V_53 ;
F_10 ( L_9 , V_12 ) ;
F_63 ( & V_2 -> V_46 ) ;
F_58 ( V_10 ) ;
F_59 ( V_10 ) ;
for ( V_53 = 0 ; V_53 < ( V_126 + V_107 ) ; V_53 ++ ) {
V_5 = V_2 -> V_8 [ V_53 ] ;
if ( V_5 != NULL ) {
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_5 ) ;
V_2 -> V_8 [ V_53 ] = NULL ;
}
}
F_60 ( & V_2 -> V_49 ) ;
F_5 ( V_2 ) ;
F_52 ( V_10 , NULL ) ;
}
static int F_64 ( struct V_13 * V_10 ,
const struct V_113 * V_114 )
{
int V_86 ;
struct V_4 * V_5 = V_10 -> V_43 ;
if ( ! F_48 ( V_5 ) )
return - V_69 ;
V_86 = F_53 ( V_10 ) ;
if ( ! V_86 )
V_86 = F_55 ( V_10 , V_121 ) ;
return V_86 ;
}
static int T_4 F_65 ( void )
{
int V_48 ;
F_10 ( L_44 , V_12 ) ;
V_48 = F_66 ( & V_127 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_66 ( & V_128 ) ;
if ( V_48 )
F_67 ( & V_127 ) ;
return V_48 ;
}
static void T_5 F_68 ( void )
{
F_10 ( L_44 , V_12 ) ;
F_67 ( & V_128 ) ;
F_67 ( & V_127 ) ;
}
