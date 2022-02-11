static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 != 0 )
F_2 ( & V_1 -> V_3 -> V_3 ,
L_1 ,
V_1 -> V_2 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned V_6 )
{
static unsigned int V_7 [] = { 2400 , 9600 , 19200 , 38400 ,
57600 , 115200 , 576000 , 1152000 , 4000000 , 0
} ;
int V_8 ;
unsigned int V_9 ;
if ( V_5 -> V_10 == NULL || V_5 -> V_11 == NULL )
return - V_12 ;
for ( V_9 = 0 ; V_7 [ V_9 ] && V_7 [ V_9 ] != V_6 ; V_9 ++ ) ;
if ( V_7 [ V_9 ] == 0 )
return - V_13 ;
memset ( & ( V_5 -> V_14 ) , 0 , sizeof( struct V_15 ) ) ;
V_5 -> V_14 . V_16 = F_4 ( V_6 ) ;
V_5 -> V_14 . V_17 = V_18 ;
F_5 ( V_5 -> V_11 , V_5 -> V_19 ,
F_6 ( V_5 -> V_19 , 0 ) ,
( unsigned char * ) V_5 -> V_10 ,
& ( V_5 -> V_14 ) ,
sizeof( struct V_15 ) ,
F_1 , V_5 ) ;
V_5 -> V_11 -> V_2 = 0 ;
V_8 = F_7 ( V_5 -> V_11 , V_20 ) ;
return V_8 ;
}
static int F_8 ( struct V_4 * V_5 )
{
unsigned int V_21 ;
int V_22 ;
V_21 = 7 ;
if ( V_21 > V_5 -> V_23 )
V_21 = V_5 -> V_23 ;
memset ( V_5 -> V_24 , 0 , 8 ) ;
V_5 -> V_24 [ 0 ] = ( unsigned char ) 0xf8 + V_21 ;
memcpy ( V_5 -> V_24 + 1 , V_5 -> V_25 , V_21 ) ;
F_9 ( V_5 -> V_26 , V_5 -> V_19 ,
F_10 ( V_5 -> V_19 , V_5 -> V_27 ) ,
V_5 -> V_24 , 8 , V_28 , V_5 , 1 ) ;
V_5 -> V_26 -> V_2 = 0 ;
V_22 = F_7 ( V_5 -> V_26 , V_20 ) ;
V_5 -> V_29 = ( V_22 == 0 ) ? V_21 : 0 ;
return V_22 ;
}
static void V_28 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_30 ;
struct V_31 * V_32 = V_5 -> V_32 ;
int V_22 = 0 ;
if ( ! F_11 ( V_5 -> V_32 ) ) {
F_2 ( & V_5 -> V_19 -> V_3 ,
L_2 ) ;
return;
}
if ( V_1 -> V_2 != 0 ) {
F_2 ( & V_5 -> V_19 -> V_3 ,
L_3 ,
V_1 -> V_2 ) ;
return;
}
if ( V_5 -> V_23 > 0 ) {
if ( V_5 -> V_29 < V_5 -> V_23 ) {
memmove ( V_5 -> V_25 ,
V_5 -> V_25 +
V_5 -> V_29 ,
V_5 -> V_23 -
V_5 -> V_29 ) ;
}
V_5 -> V_23 -= V_5 -> V_29 ;
V_5 -> V_29 = 0 ;
if ( V_5 -> V_23 > 0 ) {
if ( ( V_22 = F_8 ( V_5 ) ) != 0 ) {
F_2 ( & V_5 -> V_19 -> V_3 ,
L_4 ,
V_22 ) ;
switch ( V_22 ) {
case - V_33 :
case - V_34 :
break;
default:
V_32 -> V_35 . V_36 ++ ;
F_12 ( V_32 ) ;
}
}
} else {
if ( V_5 -> V_37 != - 1 &&
F_4 ( V_5 -> V_37 ) !=
V_5 -> V_14 . V_16 )
F_3 ( V_5 ,
V_5 -> V_37 ) ;
F_13 ( V_32 ) ;
}
}
}
static T_1 F_14 ( struct V_38 * V_39 ,
struct V_31 * V_32 )
{
struct V_4 * V_5 ;
unsigned int V_21 ;
int V_22 = 0 ;
F_15 ( V_32 ) ;
F_16 ( V_39 ) ;
V_5 = F_17 ( V_32 ) ;
F_18 ( & V_5 -> V_40 ) ;
V_5 -> V_37 = F_19 ( V_39 ) ;
V_21 =
F_20 ( V_39 , V_5 -> V_25 , V_41 ) ;
V_5 -> V_23 = V_21 ;
if ( ( V_22 = F_8 ( V_5 ) ) != 0 ) {
F_2 ( & V_5 -> V_19 -> V_3 ,
L_5 , V_22 ) ;
switch ( V_22 ) {
case - V_33 :
case - V_34 :
break;
default:
V_32 -> V_35 . V_36 ++ ;
F_12 ( V_32 ) ;
}
} else {
V_32 -> V_35 . V_42 ++ ;
V_32 -> V_35 . V_43 += V_39 -> V_44 ;
}
F_21 ( V_39 ) ;
F_22 ( & V_5 -> V_40 ) ;
return V_45 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_30 ;
struct V_31 * V_32 = V_5 -> V_32 ;
if ( ! F_11 ( V_32 ) ) {
V_5 -> V_46 = 0 ;
return;
}
if ( V_1 -> V_2 != 0 ) {
F_2 ( & V_5 -> V_19 -> V_3 ,
L_6 ,
V_1 -> V_2 ) ;
V_5 -> V_46 = 0 ;
return;
}
if ( V_1 -> V_47 > 0 ) {
T_2 * V_48 = V_1 -> V_49 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_47 ; V_9 ++ ) {
F_24 ( V_32 , & V_32 -> V_35 ,
& V_5 -> V_50 , V_48 [ V_9 ] ) ;
}
V_5 -> V_46 =
( V_5 -> V_50 . V_51 != V_52 ) ? 1 : 0 ;
}
V_1 -> V_2 = 0 ;
F_7 ( V_1 , V_20 ) ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_17 ( V_32 ) ;
int V_8 = - V_12 ;
char V_53 [ 16 ] ;
V_5 -> V_46 = 0 ;
V_5 -> V_50 . V_54 = FALSE ;
V_5 -> V_50 . V_51 = V_52 ;
V_5 -> V_50 . V_55 = V_56 ;
V_5 -> V_50 . V_39 = F_26 ( V_56 ) ;
if ( ! V_5 -> V_50 . V_39 )
goto V_57;
F_27 ( V_5 -> V_50 . V_39 , 1 ) ;
V_5 -> V_50 . V_58 = V_5 -> V_50 . V_39 -> V_59 ;
V_5 -> V_60 = F_28 ( 0 , V_61 ) ;
if ( ! V_5 -> V_60 )
goto V_57;
V_5 -> V_26 = F_28 ( 0 , V_61 ) ;
if ( ! V_5 -> V_26 )
goto V_57;
V_5 -> V_11 = F_28 ( 0 , V_61 ) ;
if ( ! V_5 -> V_11 )
goto V_57;
V_5 -> V_37 = 9600 ;
V_8 = F_3 ( V_5 , 9600 ) ;
if ( V_8 < 0 )
goto V_57;
sprintf ( V_53 , L_7 , V_5 -> V_19 -> V_62 ) ;
V_5 -> V_63 = F_29 ( V_32 , & V_5 -> V_64 , V_53 ) ;
if ( ! V_5 -> V_63 ) {
F_2 ( & V_5 -> V_19 -> V_3 , L_8 ) ;
goto V_57;
}
F_9 ( V_5 -> V_60 , V_5 -> V_19 ,
F_30 ( V_5 -> V_19 , V_5 -> V_65 ) ,
V_5 -> V_66 , V_67 , F_23 ,
V_5 , 1 ) ;
V_5 -> V_60 -> V_2 = 0 ;
V_8 = F_7 ( V_5 -> V_60 , V_61 ) ;
if ( V_8 ) {
F_2 ( & V_5 -> V_19 -> V_3 , L_9 , V_8 ) ;
goto V_68;
}
F_12 ( V_32 ) ;
return 0 ;
V_68:
F_31 ( V_5 -> V_63 ) ;
V_57:
F_32 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
F_32 ( V_5 -> V_26 ) ;
V_5 -> V_26 = NULL ;
F_32 ( V_5 -> V_60 ) ;
V_5 -> V_60 = NULL ;
if ( V_5 -> V_50 . V_39 ) {
F_33 ( V_5 -> V_50 . V_39 ) ;
V_5 -> V_50 . V_39 = NULL ;
V_5 -> V_50 . V_58 = NULL ;
}
return V_8 ;
}
static int F_34 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_17 ( V_32 ) ;
F_15 ( V_32 ) ;
F_35 ( V_5 -> V_26 ) ;
F_32 ( V_5 -> V_26 ) ;
V_5 -> V_26 = NULL ;
F_35 ( V_5 -> V_11 ) ;
F_32 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
F_35 ( V_5 -> V_60 ) ;
F_32 ( V_5 -> V_60 ) ;
V_5 -> V_60 = NULL ;
F_33 ( V_5 -> V_50 . V_39 ) ;
V_5 -> V_50 . V_39 = NULL ;
V_5 -> V_50 . V_58 = NULL ;
V_5 -> V_50 . V_54 = FALSE ;
V_5 -> V_50 . V_51 = V_52 ;
V_5 -> V_46 = 0 ;
F_31 ( V_5 -> V_63 ) ;
V_5 -> V_63 = NULL ;
return 0 ;
}
static int F_36 ( struct V_31 * V_32 , struct V_69 * V_70 ,
int V_71 )
{
struct V_72 * V_73 = (struct V_72 * ) V_70 ;
struct V_4 * V_5 = F_17 ( V_32 ) ;
int V_22 = 0 ;
switch ( V_71 ) {
case V_74 :
if ( ! F_37 ( V_75 ) )
return - V_76 ;
if ( F_38 ( V_5 -> V_32 ) )
return F_3 ( V_5 ,
V_73 -> V_77 ) ;
break;
case V_78 :
if ( ! F_37 ( V_75 ) )
return - V_76 ;
if ( F_11 ( V_5 -> V_32 ) )
F_39 ( V_5 -> V_32 , TRUE ) ;
break;
case V_79 :
V_73 -> V_80 = V_5 -> V_46 ;
break;
default:
V_22 = - V_13 ;
}
return V_22 ;
}
static int F_40 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_3 = F_41 ( V_82 ) ;
struct V_4 * V_5 = NULL ;
struct V_31 * V_90 = NULL ;
int V_22 = - V_12 ;
int V_91 , V_92 , V_93 ;
T_2 V_65 ;
T_2 V_27 ;
V_86 = V_82 -> V_94 ;
if ( V_86 -> V_95 . V_96 != 2 ) {
F_2 ( & V_82 -> V_3 , L_10 ,
V_86 -> V_95 . V_96 ) ;
return - V_33 ;
}
V_88 = & V_86 -> V_88 [ V_97 ] . V_95 ;
if ( ! F_42 ( V_88 ) ) {
F_2 ( & V_82 -> V_3 ,
L_11 ) ;
return - V_33 ;
}
V_65 = V_88 -> V_98 ;
V_91 = F_30 ( V_3 , V_65 ) ;
V_92 = F_43 ( V_3 , V_91 , F_44 ( V_91 ) ) ;
if ( V_92 > 255 || V_92 <= 1 ) {
F_2 ( & V_82 -> V_3 ,
L_12 ,
V_92 ) ;
return - V_33 ;
}
V_88 = & V_86 -> V_88 [ V_99 ] . V_95 ;
if ( ! F_45 ( V_88 ) ) {
F_2 ( & V_82 -> V_3 ,
L_13 ) ;
return - V_33 ;
}
V_27 = V_88 -> V_98 ;
V_91 = F_10 ( V_3 , V_27 ) ;
V_93 = F_43 ( V_3 , V_91 , F_44 ( V_91 ) ) ;
V_90 = F_46 ( sizeof( * V_5 ) ) ;
if ( ! V_90 )
goto V_100;
F_47 ( V_90 , & V_82 -> V_3 ) ;
V_5 = F_17 ( V_90 ) ;
V_5 -> V_32 = V_90 ;
V_5 -> V_19 = V_3 ;
V_5 -> V_65 = V_65 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_63 = NULL ;
V_5 -> V_26 = NULL ;
V_5 -> V_25 = NULL ;
V_5 -> V_23 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_60 = NULL ;
V_5 -> V_66 = NULL ;
V_5 -> V_50 . V_54 = FALSE ;
V_5 -> V_50 . V_51 = V_52 ;
V_5 -> V_50 . V_39 = NULL ;
V_5 -> V_46 = 0 ;
F_48 ( & V_5 -> V_40 ) ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = NULL ;
V_5 -> V_14 . V_16 = 0 ;
V_5 -> V_66 = F_49 ( V_67 , V_61 ) ;
if ( ! V_5 -> V_66 )
goto V_57;
V_5 -> V_25 = F_49 ( V_41 , V_61 ) ;
if ( ! V_5 -> V_25 )
goto V_57;
V_5 -> V_10 =
F_49 ( sizeof( struct V_101 ) , V_61 ) ;
if ( ! V_5 -> V_10 )
goto V_57;
V_5 -> V_10 -> V_102 =
V_103 | V_104 | V_105 ;
V_5 -> V_10 -> V_106 = V_107 ;
V_5 -> V_10 -> V_108 = F_50 ( 0x0200 ) ;
V_5 -> V_10 -> V_109 = F_50 ( 0x0001 ) ;
V_5 -> V_10 -> V_110 =
F_50 ( sizeof( struct V_15 ) ) ;
F_51 ( V_111 L_14
L_15 ,
V_3 -> V_62 , F_52 ( V_3 -> V_112 . V_113 ) ,
F_52 ( V_3 -> V_112 . V_114 ) ) ;
F_53 ( & V_5 -> V_64 ) ;
V_5 -> V_64 . V_115 . V_116 =
V_117 | V_118 | V_119 | V_120 | V_121 | V_122 ;
V_5 -> V_64 . V_123 . V_116 &= V_124 ;
F_54 ( & V_5 -> V_64 ) ;
V_90 -> V_125 = & V_126 ;
V_22 = F_55 ( V_90 ) ;
if ( V_22 != 0 )
goto V_57;
F_56 ( & V_90 -> V_3 , L_16 ,
V_90 -> V_127 ) ;
F_57 ( V_82 , V_5 ) ;
return 0 ;
V_57:
F_58 ( V_5 -> V_10 ) ;
F_58 ( V_5 -> V_25 ) ;
F_58 ( V_5 -> V_66 ) ;
F_59 ( V_90 ) ;
V_100:
return V_22 ;
}
static void F_60 ( struct V_81 * V_82 )
{
struct V_4 * V_5 = F_61 ( V_82 ) ;
if ( ! V_5 )
return;
F_62 ( V_5 -> V_32 ) ;
F_35 ( V_5 -> V_11 ) ;
F_32 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
F_35 ( V_5 -> V_26 ) ;
F_32 ( V_5 -> V_26 ) ;
V_5 -> V_26 = NULL ;
F_35 ( V_5 -> V_60 ) ;
F_32 ( V_5 -> V_60 ) ;
V_5 -> V_60 = NULL ;
F_58 ( V_5 -> V_10 ) ;
F_58 ( V_5 -> V_25 ) ;
F_58 ( V_5 -> V_66 ) ;
F_59 ( V_5 -> V_32 ) ;
F_57 ( V_82 , NULL ) ;
}
static int F_63 ( struct V_81 * V_82 , T_3 V_128 )
{
struct V_4 * V_5 = F_61 ( V_82 ) ;
F_64 ( V_5 -> V_32 ) ;
if ( V_5 -> V_11 != NULL )
F_35 ( V_5 -> V_11 ) ;
if ( V_5 -> V_26 != NULL )
F_35 ( V_5 -> V_26 ) ;
if ( V_5 -> V_60 != NULL )
F_35 ( V_5 -> V_60 ) ;
return 0 ;
}
static int F_65 ( struct V_81 * V_82 )
{
struct V_4 * V_5 = F_61 ( V_82 ) ;
if ( V_5 -> V_60 != NULL ) {
F_7 ( V_5 -> V_60 , V_61 ) ;
}
F_66 ( V_5 -> V_32 ) ;
return 0 ;
}
