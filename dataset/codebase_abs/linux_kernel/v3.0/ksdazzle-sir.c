static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 != 0 ) {
F_2 ( L_1 ,
V_1 -> V_2 ) ;
}
}
static int F_3 ( struct V_3 * V_4 , unsigned V_5 )
{
static unsigned int V_6 [] = { 2400 , 9600 , 19200 , 38400 ,
57600 , 115200 , 576000 , 1152000 , 4000000 , 0
} ;
int F_2 ;
unsigned int V_7 ;
if ( V_4 -> V_8 == NULL || V_4 -> V_9 == NULL )
return - V_10 ;
for ( V_7 = 0 ; V_6 [ V_7 ] && V_6 [ V_7 ] != V_5 ; V_7 ++ ) ;
if ( V_6 [ V_7 ] == 0 )
return - V_11 ;
memset ( & ( V_4 -> V_12 ) , 0 , sizeof( struct V_13 ) ) ;
V_4 -> V_12 . V_14 = F_4 ( V_5 ) ;
V_4 -> V_12 . V_15 = V_16 ;
F_5 ( V_4 -> V_9 , V_4 -> V_17 ,
F_6 ( V_4 -> V_17 , 0 ) ,
( unsigned char * ) V_4 -> V_8 ,
& ( V_4 -> V_12 ) ,
sizeof( struct V_13 ) ,
F_1 , V_4 ) ;
V_4 -> V_9 -> V_2 = 0 ;
F_2 = F_7 ( V_4 -> V_9 , V_18 ) ;
return F_2 ;
}
static int F_8 ( struct V_3 * V_4 )
{
unsigned int V_19 ;
int V_20 ;
V_19 = 7 ;
if ( V_19 > V_4 -> V_21 )
V_19 = V_4 -> V_21 ;
memset ( V_4 -> V_22 , 0 , 8 ) ;
V_4 -> V_22 [ 0 ] = ( unsigned char ) 0xf8 + V_19 ;
memcpy ( V_4 -> V_22 + 1 , V_4 -> V_23 , V_19 ) ;
F_9 ( V_4 -> V_24 , V_4 -> V_17 ,
F_10 ( V_4 -> V_17 , V_4 -> V_25 ) ,
V_4 -> V_22 , 8 , V_26 , V_4 , 1 ) ;
V_4 -> V_24 -> V_2 = 0 ;
V_20 = F_7 ( V_4 -> V_24 , V_18 ) ;
V_4 -> V_27 = ( V_20 == 0 ) ? V_19 : 0 ;
return V_20 ;
}
static void V_26 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_28 ;
struct V_29 * V_30 = V_4 -> V_30 ;
int V_20 = 0 ;
if ( ! F_11 ( V_4 -> V_30 ) ) {
F_2 ( L_2 ) ;
return;
}
if ( V_1 -> V_2 != 0 ) {
F_2 ( L_3 ,
V_1 -> V_2 ) ;
return;
}
if ( V_4 -> V_21 > 0 ) {
if ( V_4 -> V_27 < V_4 -> V_21 ) {
memmove ( V_4 -> V_23 ,
V_4 -> V_23 +
V_4 -> V_27 ,
V_4 -> V_21 -
V_4 -> V_27 ) ;
}
V_4 -> V_21 -= V_4 -> V_27 ;
V_4 -> V_27 = 0 ;
if ( V_4 -> V_21 > 0 ) {
if ( ( V_20 = F_8 ( V_4 ) ) != 0 ) {
F_2 ( L_4 , V_20 ) ;
switch ( V_20 ) {
case - V_31 :
case - V_32 :
break;
default:
V_30 -> V_33 . V_34 ++ ;
F_12 ( V_30 ) ;
}
}
} else {
if ( V_4 -> V_35 != - 1 &&
F_4 ( V_4 -> V_35 ) !=
V_4 -> V_12 . V_14 )
F_3 ( V_4 ,
V_4 -> V_35 ) ;
F_13 ( V_30 ) ;
}
}
}
static T_1 F_14 ( struct V_36 * V_37 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 ;
unsigned int V_19 ;
int V_20 = 0 ;
F_15 ( V_30 ) ;
F_16 ( V_37 ) ;
V_4 = F_17 ( V_30 ) ;
F_18 ( & V_4 -> V_38 ) ;
V_4 -> V_35 = F_19 ( V_37 ) ;
V_19 =
F_20 ( V_37 , V_4 -> V_23 , V_39 ) ;
V_4 -> V_21 = V_19 ;
if ( ( V_20 = F_8 ( V_4 ) ) != 0 ) {
F_2 ( L_5 , V_20 ) ;
switch ( V_20 ) {
case - V_31 :
case - V_32 :
break;
default:
V_30 -> V_33 . V_34 ++ ;
F_12 ( V_30 ) ;
}
} else {
V_30 -> V_33 . V_40 ++ ;
V_30 -> V_33 . V_41 += V_37 -> V_42 ;
}
F_21 ( V_37 ) ;
F_22 ( & V_4 -> V_38 ) ;
return V_43 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_28 ;
struct V_29 * V_30 = V_4 -> V_30 ;
if ( ! F_11 ( V_30 ) ) {
V_4 -> V_44 = 0 ;
return;
}
if ( V_1 -> V_2 != 0 ) {
F_2 ( L_6 ,
V_1 -> V_2 ) ;
V_4 -> V_44 = 0 ;
return;
}
if ( V_1 -> V_45 > 0 ) {
T_2 * V_46 = V_1 -> V_47 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_1 -> V_45 ; V_7 ++ ) {
F_24 ( V_30 , & V_30 -> V_33 ,
& V_4 -> V_48 , V_46 [ V_7 ] ) ;
}
V_4 -> V_44 =
( V_4 -> V_48 . V_49 != V_50 ) ? 1 : 0 ;
}
V_1 -> V_2 = 0 ;
F_7 ( V_1 , V_18 ) ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_17 ( V_30 ) ;
int F_2 = - V_10 ;
char V_51 [ 16 ] ;
V_4 -> V_44 = 0 ;
V_4 -> V_48 . V_52 = FALSE ;
V_4 -> V_48 . V_49 = V_50 ;
V_4 -> V_48 . V_53 = V_54 ;
V_4 -> V_48 . V_37 = F_26 ( V_54 ) ;
if ( ! V_4 -> V_48 . V_37 )
goto V_55;
F_27 ( V_4 -> V_48 . V_37 , 1 ) ;
V_4 -> V_48 . V_56 = V_4 -> V_48 . V_37 -> V_57 ;
V_4 -> V_58 = F_28 ( 0 , V_59 ) ;
if ( ! V_4 -> V_58 )
goto V_55;
V_4 -> V_24 = F_28 ( 0 , V_59 ) ;
if ( ! V_4 -> V_24 )
goto V_55;
V_4 -> V_9 = F_28 ( 0 , V_59 ) ;
if ( ! V_4 -> V_9 )
goto V_55;
V_4 -> V_35 = 9600 ;
F_2 = F_3 ( V_4 , 9600 ) ;
if ( F_2 < 0 )
goto V_55;
sprintf ( V_51 , L_7 , V_4 -> V_17 -> V_60 ) ;
V_4 -> V_61 = F_29 ( V_30 , & V_4 -> V_62 , V_51 ) ;
if ( ! V_4 -> V_61 ) {
F_2 ( L_8 ) ;
goto V_55;
}
F_9 ( V_4 -> V_58 , V_4 -> V_17 ,
F_30 ( V_4 -> V_17 , V_4 -> V_63 ) ,
V_4 -> V_64 , V_65 , F_23 ,
V_4 , 1 ) ;
V_4 -> V_58 -> V_2 = 0 ;
F_2 = F_7 ( V_4 -> V_58 , V_59 ) ;
if ( F_2 ) {
F_2 ( L_9 , F_2 ) ;
goto V_66;
}
F_12 ( V_30 ) ;
return 0 ;
V_66:
F_31 ( V_4 -> V_61 ) ;
V_55:
F_32 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
F_32 ( V_4 -> V_24 ) ;
V_4 -> V_24 = NULL ;
F_32 ( V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
if ( V_4 -> V_48 . V_37 ) {
F_33 ( V_4 -> V_48 . V_37 ) ;
V_4 -> V_48 . V_37 = NULL ;
V_4 -> V_48 . V_56 = NULL ;
}
return F_2 ;
}
static int F_34 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_17 ( V_30 ) ;
F_15 ( V_30 ) ;
F_35 ( V_4 -> V_24 ) ;
F_32 ( V_4 -> V_24 ) ;
V_4 -> V_24 = NULL ;
F_35 ( V_4 -> V_9 ) ;
F_32 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
F_35 ( V_4 -> V_58 ) ;
F_32 ( V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
F_33 ( V_4 -> V_48 . V_37 ) ;
V_4 -> V_48 . V_37 = NULL ;
V_4 -> V_48 . V_56 = NULL ;
V_4 -> V_48 . V_52 = FALSE ;
V_4 -> V_48 . V_49 = V_50 ;
V_4 -> V_44 = 0 ;
F_31 ( V_4 -> V_61 ) ;
V_4 -> V_61 = NULL ;
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_67 * V_68 ,
int V_69 )
{
struct V_70 * V_71 = (struct V_70 * ) V_68 ;
struct V_3 * V_4 = F_17 ( V_30 ) ;
int V_20 = 0 ;
switch ( V_69 ) {
case V_72 :
if ( ! F_37 ( V_73 ) )
return - V_74 ;
if ( F_38 ( V_4 -> V_30 ) )
return F_3 ( V_4 ,
V_71 -> V_75 ) ;
break;
case V_76 :
if ( ! F_37 ( V_73 ) )
return - V_74 ;
if ( F_11 ( V_4 -> V_30 ) )
F_39 ( V_4 -> V_30 , TRUE ) ;
break;
case V_77 :
V_71 -> V_78 = V_4 -> V_44 ;
break;
default:
V_20 = - V_11 ;
}
return V_20 ;
}
static int F_40 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 = F_41 ( V_80 ) ;
struct V_3 * V_4 = NULL ;
struct V_29 * V_89 = NULL ;
int V_20 = - V_10 ;
int V_90 , V_91 , V_92 ;
T_2 V_63 ;
T_2 V_25 ;
V_84 = V_80 -> V_93 ;
if ( V_84 -> V_94 . V_95 != 2 ) {
F_2 ( L_10 ,
V_84 -> V_94 . V_95 ) ;
return - V_31 ;
}
V_86 = & V_84 -> V_86 [ V_96 ] . V_94 ;
if ( ! F_42 ( V_86 ) ) {
F_2 ( L_11 ) ;
return - V_31 ;
}
V_63 = V_86 -> V_97 ;
V_90 = F_30 ( V_88 , V_63 ) ;
V_91 = F_43 ( V_88 , V_90 , F_44 ( V_90 ) ) ;
if ( V_91 > 255 || V_91 <= 1 ) {
F_2 ( L_12 , V_91 ) ;
return - V_31 ;
}
V_86 = & V_84 -> V_86 [ V_98 ] . V_94 ;
if ( ! F_45 ( V_86 ) ) {
F_2 ( L_13 ) ;
return - V_31 ;
}
V_25 = V_86 -> V_97 ;
V_90 = F_10 ( V_88 , V_25 ) ;
V_92 = F_43 ( V_88 , V_90 , F_44 ( V_90 ) ) ;
V_89 = F_46 ( sizeof( * V_4 ) ) ;
if ( ! V_89 )
goto V_99;
F_47 ( V_89 , & V_80 -> V_88 ) ;
V_4 = F_17 ( V_89 ) ;
V_4 -> V_30 = V_89 ;
V_4 -> V_17 = V_88 ;
V_4 -> V_63 = V_63 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_61 = NULL ;
V_4 -> V_24 = NULL ;
V_4 -> V_23 = NULL ;
V_4 -> V_21 = 0 ;
V_4 -> V_27 = 0 ;
V_4 -> V_58 = NULL ;
V_4 -> V_64 = NULL ;
V_4 -> V_48 . V_52 = FALSE ;
V_4 -> V_48 . V_49 = V_50 ;
V_4 -> V_48 . V_37 = NULL ;
V_4 -> V_44 = 0 ;
F_48 ( & V_4 -> V_38 ) ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> V_12 . V_14 = 0 ;
V_4 -> V_64 = F_49 ( V_65 , V_59 ) ;
if ( ! V_4 -> V_64 )
goto V_55;
V_4 -> V_23 = F_49 ( V_39 , V_59 ) ;
if ( ! V_4 -> V_23 )
goto V_55;
V_4 -> V_8 =
F_49 ( sizeof( struct V_100 ) , V_59 ) ;
if ( ! V_4 -> V_8 )
goto V_55;
V_4 -> V_8 -> V_101 =
V_102 | V_103 | V_104 ;
V_4 -> V_8 -> V_105 = V_106 ;
V_4 -> V_8 -> V_107 = F_50 ( 0x0200 ) ;
V_4 -> V_8 -> V_108 = F_50 ( 0x0001 ) ;
V_4 -> V_8 -> V_109 =
F_50 ( sizeof( struct V_13 ) ) ;
F_51 ( V_110 L_14
L_15 ,
V_88 -> V_60 , F_52 ( V_88 -> V_111 . V_112 ) ,
F_52 ( V_88 -> V_111 . V_113 ) ) ;
F_53 ( & V_4 -> V_62 ) ;
V_4 -> V_62 . V_114 . V_115 =
V_116 | V_117 | V_118 | V_119 | V_120 | V_121 ;
V_4 -> V_62 . V_122 . V_115 &= V_123 ;
F_54 ( & V_4 -> V_62 ) ;
V_89 -> V_124 = & V_125 ;
V_20 = F_55 ( V_89 ) ;
if ( V_20 != 0 )
goto V_55;
F_56 ( & V_89 -> V_88 , L_16 ,
V_89 -> V_126 ) ;
F_57 ( V_80 , V_4 ) ;
return 0 ;
V_55:
F_58 ( V_4 -> V_8 ) ;
F_58 ( V_4 -> V_23 ) ;
F_58 ( V_4 -> V_64 ) ;
F_59 ( V_89 ) ;
V_99:
return V_20 ;
}
static void F_60 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_61 ( V_80 ) ;
if ( ! V_4 )
return;
F_62 ( V_4 -> V_30 ) ;
F_35 ( V_4 -> V_9 ) ;
F_32 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
F_35 ( V_4 -> V_24 ) ;
F_32 ( V_4 -> V_24 ) ;
V_4 -> V_24 = NULL ;
F_35 ( V_4 -> V_58 ) ;
F_32 ( V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
F_58 ( V_4 -> V_8 ) ;
F_58 ( V_4 -> V_23 ) ;
F_58 ( V_4 -> V_64 ) ;
F_59 ( V_4 -> V_30 ) ;
F_57 ( V_80 , NULL ) ;
}
static int F_63 ( struct V_79 * V_80 , T_3 V_127 )
{
struct V_3 * V_4 = F_61 ( V_80 ) ;
F_64 ( V_4 -> V_30 ) ;
if ( V_4 -> V_9 != NULL )
F_35 ( V_4 -> V_9 ) ;
if ( V_4 -> V_24 != NULL )
F_35 ( V_4 -> V_24 ) ;
if ( V_4 -> V_58 != NULL )
F_35 ( V_4 -> V_58 ) ;
return 0 ;
}
static int F_65 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_61 ( V_80 ) ;
if ( V_4 -> V_58 != NULL ) {
F_7 ( V_4 -> V_58 , V_59 ) ;
}
F_66 ( V_4 -> V_30 ) ;
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_128 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_128 ) ;
}
