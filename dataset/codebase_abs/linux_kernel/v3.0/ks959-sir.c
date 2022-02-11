static unsigned int F_1 ( const T_1 * V_1 ,
unsigned int V_2 ,
T_1 * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = ( ( V_2 + 7 ) & ~ 0x7 ) + 0x10 ;
if ( V_5 <= V_4 ) {
static const T_1 V_6 [] = L_1 ;
T_1 V_7 ;
memset ( V_3 , 0 , V_5 ) ;
V_7 = V_6 [ ( V_2 & 0x0f ) ^ 0x06 ] ^ 0x55 ;
while ( V_2 -- > 0 ) {
* V_3 ++ = * V_1 ++ ^ V_7 ;
}
} else {
V_5 = 0 ;
}
return V_5 ;
}
static void F_2 ( struct V_8 * V_8 )
{
if ( V_8 -> V_9 != 0 ) {
F_3 ( L_2 ,
V_8 -> V_9 ) ;
}
}
static int F_4 ( struct V_10 * V_11 , unsigned V_12 )
{
static unsigned int V_13 [] = { 2400 , 9600 , 19200 , 38400 ,
57600 , 115200 , 576000 , 1152000 , 4000000 , 0
} ;
int F_3 ;
unsigned int V_14 ;
if ( V_11 -> V_15 == NULL || V_11 -> V_16 == NULL )
return - V_17 ;
for ( V_14 = 0 ; V_13 [ V_14 ] && V_13 [ V_14 ] != V_12 ; V_14 ++ ) ;
if ( V_13 [ V_14 ] == 0 )
return - V_18 ;
memset ( & ( V_11 -> V_19 ) , 0 , sizeof( struct V_20 ) ) ;
V_11 -> V_19 . V_21 = F_5 ( V_12 ) ;
V_11 -> V_19 . V_22 = V_23 ;
F_6 ( V_11 -> V_16 , V_11 -> V_24 ,
F_7 ( V_11 -> V_24 , 0 ) ,
( unsigned char * ) V_11 -> V_15 ,
& ( V_11 -> V_19 ) ,
sizeof( struct V_20 ) , F_2 ,
V_11 ) ;
V_11 -> V_16 -> V_9 = 0 ;
F_3 = F_8 ( V_11 -> V_16 , V_25 ) ;
return F_3 ;
}
static int F_9 ( struct V_10 * V_11 )
{
unsigned int V_26 ;
unsigned int V_27 ;
int V_28 ;
V_27 = ( V_29 & ~ 0x7 ) - 0x10 ;
if ( V_27 > V_11 -> V_30 )
V_27 = V_11 -> V_30 ;
V_26 = F_1 ( V_11 -> V_31 , V_27 ,
V_11 -> V_32 ,
V_29 ) ;
V_11 -> V_33 -> V_34 = F_10 ( V_27 ) ;
V_11 -> V_33 -> V_35 = F_10 ( V_26 ) ;
F_6 ( V_11 -> V_36 , V_11 -> V_24 ,
F_7 ( V_11 -> V_24 , 0 ) ,
( unsigned char * ) V_11 -> V_33 ,
V_11 -> V_32 , V_26 ,
V_37 , V_11 ) ;
V_11 -> V_36 -> V_9 = 0 ;
V_28 = F_8 ( V_11 -> V_36 , V_25 ) ;
V_11 -> V_38 = ( V_28 == 0 ) ? V_27 : 0 ;
return V_28 ;
}
static void V_37 ( struct V_8 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_39 ;
struct V_40 * V_41 = V_11 -> V_41 ;
int V_28 = 0 ;
if ( ! F_11 ( V_11 -> V_41 ) ) {
F_3 ( L_3 ) ;
return;
}
if ( V_8 -> V_9 != 0 ) {
F_3 ( L_4 ,
V_8 -> V_9 ) ;
return;
}
if ( V_11 -> V_30 > 0 ) {
if ( V_11 -> V_38 < V_11 -> V_30 ) {
memmove ( V_11 -> V_31 ,
V_11 -> V_31 +
V_11 -> V_38 ,
V_11 -> V_30 -
V_11 -> V_38 ) ;
}
V_11 -> V_30 -= V_11 -> V_38 ;
V_11 -> V_38 = 0 ;
if ( V_11 -> V_30 > 0 ) {
if ( ( V_28 = F_9 ( V_11 ) ) != 0 ) {
F_3 ( L_5 ,
V_28 ) ;
switch ( V_28 ) {
case - V_42 :
case - V_43 :
break;
default:
V_41 -> V_44 . V_45 ++ ;
F_12 ( V_41 ) ;
}
}
} else {
if ( V_11 -> V_46 != - 1 &&
F_5 ( V_11 -> V_46 ) !=
V_11 -> V_19 . V_21 )
F_4 ( V_11 , V_11 -> V_46 ) ;
F_13 ( V_41 ) ;
}
}
}
static T_2 F_14 ( struct V_47 * V_48 ,
struct V_40 * V_41 )
{
struct V_10 * V_11 ;
unsigned int V_27 ;
int V_28 = 0 ;
F_15 ( V_41 ) ;
F_16 ( V_48 ) ;
V_11 = F_17 ( V_41 ) ;
F_18 ( & V_11 -> V_49 ) ;
V_11 -> V_46 = F_19 ( V_48 ) ;
V_27 =
F_20 ( V_48 , V_11 -> V_31 , V_50 ) ;
V_11 -> V_30 = V_27 ;
if ( ( V_28 = F_9 ( V_11 ) ) != 0 ) {
F_3 ( L_6 , V_28 ) ;
switch ( V_28 ) {
case - V_42 :
case - V_43 :
break;
default:
V_41 -> V_44 . V_45 ++ ;
F_12 ( V_41 ) ;
}
} else {
V_41 -> V_44 . V_51 ++ ;
V_41 -> V_44 . V_52 += V_48 -> V_53 ;
}
F_21 ( V_48 ) ;
F_22 ( & V_11 -> V_49 ) ;
return V_54 ;
}
static void F_23 ( struct V_8 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_39 ;
int V_28 ;
if ( ! F_11 ( V_11 -> V_41 ) ) {
V_11 -> V_55 = 0 ;
return;
}
if ( V_8 -> V_9 != 0 ) {
F_3 ( L_7 ,
V_8 -> V_9 ) ;
V_11 -> V_55 = 0 ;
return;
}
if ( V_8 -> V_56 > 0 ) {
T_1 * V_57 = V_8 -> V_58 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_8 -> V_56 ; V_14 ++ ) {
V_11 -> V_59 ++ ;
V_57 [ V_14 ] =
V_57 [ V_14 ] ^ V_11 -> V_59 ^ 0x55u ;
if ( V_11 -> V_59 != 0 ) {
F_24 ( V_11 -> V_41 ,
& V_11 -> V_41 -> V_44 ,
& V_11 -> V_60 ,
V_57 [ V_14 ] ) ;
}
}
F_25 ( & V_11 -> V_61 ) ;
V_11 -> V_55 =
( V_11 -> V_60 . V_62 != V_63 ) ? 1 : 0 ;
}
V_8 -> V_9 = 0 ;
V_28 = F_8 ( V_8 , V_25 ) ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_10 * V_11 = F_17 ( V_41 ) ;
int F_3 = - V_17 ;
char V_64 [ 16 ] ;
V_11 -> V_55 = 0 ;
V_11 -> V_60 . V_65 = FALSE ;
V_11 -> V_60 . V_62 = V_63 ;
V_11 -> V_60 . V_66 = V_67 ;
V_11 -> V_60 . V_48 = F_27 ( V_67 ) ;
if ( ! V_11 -> V_60 . V_48 )
goto V_68;
F_28 ( V_11 -> V_60 . V_48 , 1 ) ;
V_11 -> V_60 . V_69 = V_11 -> V_60 . V_48 -> V_70 ;
F_25 ( & V_11 -> V_61 ) ;
V_11 -> V_71 = F_29 ( 0 , V_72 ) ;
if ( ! V_11 -> V_71 )
goto V_68;
V_11 -> V_36 = F_29 ( 0 , V_72 ) ;
if ( ! V_11 -> V_36 )
goto V_68;
V_11 -> V_16 = F_29 ( 0 , V_72 ) ;
if ( ! V_11 -> V_16 )
goto V_68;
V_11 -> V_46 = 9600 ;
F_3 = F_4 ( V_11 , 9600 ) ;
if ( F_3 < 0 )
goto V_68;
sprintf ( V_64 , L_8 , V_11 -> V_24 -> V_73 ) ;
V_11 -> V_74 = F_30 ( V_41 , & V_11 -> V_75 , V_64 ) ;
if ( ! V_11 -> V_74 ) {
F_3 ( L_9 ) ;
goto V_68;
}
F_6 ( V_11 -> V_71 , V_11 -> V_24 ,
F_31 ( V_11 -> V_24 , 0 ) ,
( unsigned char * ) V_11 -> V_76 ,
V_11 -> V_77 , V_78 ,
F_23 , V_11 ) ;
V_11 -> V_71 -> V_9 = 0 ;
F_3 = F_8 ( V_11 -> V_71 , V_72 ) ;
if ( F_3 ) {
F_3 ( L_10 , F_3 ) ;
goto V_79;
}
F_12 ( V_41 ) ;
return 0 ;
V_79:
F_32 ( V_11 -> V_74 ) ;
V_68:
F_33 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_33 ( V_11 -> V_36 ) ;
V_11 -> V_36 = NULL ;
F_33 ( V_11 -> V_71 ) ;
V_11 -> V_71 = NULL ;
if ( V_11 -> V_60 . V_48 ) {
F_34 ( V_11 -> V_60 . V_48 ) ;
V_11 -> V_60 . V_48 = NULL ;
V_11 -> V_60 . V_69 = NULL ;
}
return F_3 ;
}
static int F_35 ( struct V_40 * V_41 )
{
struct V_10 * V_11 = F_17 ( V_41 ) ;
F_15 ( V_41 ) ;
F_36 ( V_11 -> V_36 ) ;
F_33 ( V_11 -> V_36 ) ;
V_11 -> V_36 = NULL ;
F_36 ( V_11 -> V_16 ) ;
F_33 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_36 ( V_11 -> V_71 ) ;
F_33 ( V_11 -> V_71 ) ;
V_11 -> V_71 = NULL ;
F_34 ( V_11 -> V_60 . V_48 ) ;
V_11 -> V_60 . V_48 = NULL ;
V_11 -> V_60 . V_69 = NULL ;
V_11 -> V_60 . V_65 = FALSE ;
V_11 -> V_60 . V_62 = V_63 ;
V_11 -> V_55 = 0 ;
if ( V_11 -> V_74 )
F_32 ( V_11 -> V_74 ) ;
V_11 -> V_74 = NULL ;
return 0 ;
}
static int F_37 ( struct V_40 * V_41 , struct V_80 * V_81 , int V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 ;
struct V_10 * V_11 = F_17 ( V_41 ) ;
int V_28 = 0 ;
switch ( V_82 ) {
case V_85 :
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( F_39 ( V_11 -> V_41 ) )
return F_4 ( V_11 , V_84 -> V_88 ) ;
break;
case V_89 :
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( F_11 ( V_11 -> V_41 ) )
F_40 ( V_11 -> V_41 , TRUE ) ;
break;
case V_90 :
V_84 -> V_91 = V_11 -> V_55 ;
break;
default:
V_28 = - V_18 ;
}
return V_28 ;
}
static int F_41 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
struct V_96 * V_97 = F_42 ( V_93 ) ;
struct V_10 * V_11 = NULL ;
struct V_40 * V_98 = NULL ;
int V_28 = - V_17 ;
V_98 = F_43 ( sizeof( * V_11 ) ) ;
if ( ! V_98 )
goto V_99;
F_44 ( V_98 , & V_93 -> V_97 ) ;
V_11 = F_17 ( V_98 ) ;
V_11 -> V_41 = V_98 ;
V_11 -> V_24 = V_97 ;
V_11 -> V_74 = NULL ;
V_11 -> V_33 = NULL ;
V_11 -> V_36 = NULL ;
V_11 -> V_31 = NULL ;
V_11 -> V_32 = NULL ;
V_11 -> V_30 = 0 ;
V_11 -> V_38 = 0 ;
V_11 -> V_76 = NULL ;
V_11 -> V_71 = NULL ;
V_11 -> V_77 = NULL ;
V_11 -> V_59 = 0 ;
V_11 -> V_60 . V_65 = FALSE ;
V_11 -> V_60 . V_62 = V_63 ;
V_11 -> V_60 . V_48 = NULL ;
V_11 -> V_55 = 0 ;
F_45 ( & V_11 -> V_49 ) ;
V_11 -> V_15 = NULL ;
V_11 -> V_16 = NULL ;
V_11 -> V_19 . V_21 = 0 ;
V_11 -> V_77 = F_46 ( V_78 , V_72 ) ;
if ( ! V_11 -> V_77 )
goto V_68;
V_11 -> V_76 =
F_46 ( sizeof( struct V_100 ) , V_72 ) ;
if ( ! V_11 -> V_76 )
goto V_68;
V_11 -> V_76 -> V_101 =
V_102 | V_103 | V_104 ;
V_11 -> V_76 -> V_105 = V_106 ;
V_11 -> V_76 -> V_34 = F_10 ( 0x0200 ) ;
V_11 -> V_76 -> V_107 = 0 ;
V_11 -> V_76 -> V_35 = F_10 ( V_78 ) ;
V_11 -> V_31 = F_46 ( V_50 , V_72 ) ;
if ( ! V_11 -> V_31 )
goto V_68;
V_11 -> V_32 = F_46 ( V_29 , V_72 ) ;
if ( ! V_11 -> V_32 )
goto V_68;
V_11 -> V_33 =
F_46 ( sizeof( struct V_100 ) , V_72 ) ;
if ( ! V_11 -> V_33 )
goto V_68;
V_11 -> V_33 -> V_101 =
V_108 | V_103 | V_104 ;
V_11 -> V_33 -> V_105 = V_109 ;
V_11 -> V_33 -> V_34 = 0 ;
V_11 -> V_33 -> V_107 = 0 ;
V_11 -> V_33 -> V_35 = 0 ;
V_11 -> V_15 =
F_46 ( sizeof( struct V_100 ) , V_72 ) ;
if ( ! V_11 -> V_15 )
goto V_68;
V_11 -> V_15 -> V_101 =
V_108 | V_103 | V_104 ;
V_11 -> V_15 -> V_105 = V_109 ;
V_11 -> V_15 -> V_34 = F_10 ( 0x0200 ) ;
V_11 -> V_15 -> V_107 = F_10 ( 0x0001 ) ;
V_11 -> V_15 -> V_35 =
F_10 ( sizeof( struct V_20 ) ) ;
F_47 ( V_110 L_11
L_12 ,
V_97 -> V_73 , F_48 ( V_97 -> V_111 . V_112 ) ,
F_48 ( V_97 -> V_111 . V_113 ) ) ;
F_49 ( & V_11 -> V_75 ) ;
V_11 -> V_75 . V_114 . V_115 =
V_116 | V_117 | V_118 | V_119 | V_120 ;
V_11 -> V_75 . V_121 . V_115 &= V_122 ;
F_50 ( & V_11 -> V_75 ) ;
V_98 -> V_123 = & V_124 ;
V_28 = F_51 ( V_98 ) ;
if ( V_28 != 0 )
goto V_68;
F_52 ( & V_98 -> V_97 , L_13 ,
V_98 -> V_125 ) ;
F_53 ( V_93 , V_11 ) ;
return 0 ;
V_68:
F_54 ( V_11 -> V_15 ) ;
F_54 ( V_11 -> V_33 ) ;
F_54 ( V_11 -> V_32 ) ;
F_54 ( V_11 -> V_31 ) ;
F_54 ( V_11 -> V_76 ) ;
F_54 ( V_11 -> V_77 ) ;
F_55 ( V_98 ) ;
V_99:
return V_28 ;
}
static void F_56 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_57 ( V_93 ) ;
if ( ! V_11 )
return;
F_58 ( V_11 -> V_41 ) ;
if ( V_11 -> V_16 != NULL ) {
F_36 ( V_11 -> V_16 ) ;
F_33 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
}
if ( V_11 -> V_36 != NULL ) {
F_36 ( V_11 -> V_36 ) ;
F_33 ( V_11 -> V_36 ) ;
V_11 -> V_36 = NULL ;
}
if ( V_11 -> V_71 != NULL ) {
F_36 ( V_11 -> V_71 ) ;
F_33 ( V_11 -> V_71 ) ;
V_11 -> V_71 = NULL ;
}
F_54 ( V_11 -> V_15 ) ;
F_54 ( V_11 -> V_33 ) ;
F_54 ( V_11 -> V_32 ) ;
F_54 ( V_11 -> V_31 ) ;
F_54 ( V_11 -> V_76 ) ;
F_54 ( V_11 -> V_77 ) ;
F_55 ( V_11 -> V_41 ) ;
F_53 ( V_93 , NULL ) ;
}
static int F_59 ( struct V_92 * V_93 , T_3 V_126 )
{
struct V_10 * V_11 = F_57 ( V_93 ) ;
F_60 ( V_11 -> V_41 ) ;
if ( V_11 -> V_16 != NULL )
F_36 ( V_11 -> V_16 ) ;
if ( V_11 -> V_36 != NULL )
F_36 ( V_11 -> V_36 ) ;
if ( V_11 -> V_71 != NULL )
F_36 ( V_11 -> V_71 ) ;
return 0 ;
}
static int F_61 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = F_57 ( V_93 ) ;
if ( V_11 -> V_71 != NULL ) {
F_8 ( V_11 -> V_71 , V_72 ) ;
}
F_62 ( V_11 -> V_41 ) ;
return 0 ;
}
static int T_4 F_63 ( void )
{
return F_64 ( & V_127 ) ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_127 ) ;
}
