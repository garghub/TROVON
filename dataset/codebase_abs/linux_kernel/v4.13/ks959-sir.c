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
F_3 ( & V_8 -> V_10 -> V_10 ,
L_2 ,
V_8 -> V_9 ) ;
}
}
static int F_4 ( struct V_11 * V_12 , unsigned V_13 )
{
static unsigned int V_14 [] = { 2400 , 9600 , 19200 , 38400 ,
57600 , 115200 , 576000 , 1152000 , 4000000 , 0
} ;
int V_15 ;
unsigned int V_16 ;
if ( V_12 -> V_17 == NULL || V_12 -> V_18 == NULL )
return - V_19 ;
for ( V_16 = 0 ; V_14 [ V_16 ] && V_14 [ V_16 ] != V_13 ; V_16 ++ ) ;
if ( V_14 [ V_16 ] == 0 )
return - V_20 ;
memset ( & ( V_12 -> V_21 ) , 0 , sizeof( struct V_22 ) ) ;
V_12 -> V_21 . V_23 = F_5 ( V_13 ) ;
V_12 -> V_21 . V_24 = V_25 ;
F_6 ( V_12 -> V_18 , V_12 -> V_26 ,
F_7 ( V_12 -> V_26 , 0 ) ,
( unsigned char * ) V_12 -> V_17 ,
& ( V_12 -> V_21 ) ,
sizeof( struct V_22 ) , F_2 ,
V_12 ) ;
V_12 -> V_18 -> V_9 = 0 ;
V_15 = F_8 ( V_12 -> V_18 , V_27 ) ;
return V_15 ;
}
static int F_9 ( struct V_11 * V_12 )
{
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
V_29 = ( V_31 & ~ 0x7 ) - 0x10 ;
if ( V_29 > V_12 -> V_32 )
V_29 = V_12 -> V_32 ;
V_28 = F_1 ( V_12 -> V_33 , V_29 ,
V_12 -> V_34 ,
V_31 ) ;
V_12 -> V_35 -> V_36 = F_10 ( V_29 ) ;
V_12 -> V_35 -> V_37 = F_10 ( V_28 ) ;
F_6 ( V_12 -> V_38 , V_12 -> V_26 ,
F_7 ( V_12 -> V_26 , 0 ) ,
( unsigned char * ) V_12 -> V_35 ,
V_12 -> V_34 , V_28 ,
V_39 , V_12 ) ;
V_12 -> V_38 -> V_9 = 0 ;
V_30 = F_8 ( V_12 -> V_38 , V_27 ) ;
V_12 -> V_40 = ( V_30 == 0 ) ? V_29 : 0 ;
return V_30 ;
}
static void V_39 ( struct V_8 * V_8 )
{
struct V_11 * V_12 = V_8 -> V_41 ;
struct V_42 * V_43 = V_12 -> V_43 ;
int V_30 = 0 ;
if ( ! F_11 ( V_12 -> V_43 ) ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_3 ) ;
return;
}
if ( V_8 -> V_9 != 0 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_4 ,
V_8 -> V_9 ) ;
return;
}
if ( V_12 -> V_32 > 0 ) {
if ( V_12 -> V_40 < V_12 -> V_32 ) {
memmove ( V_12 -> V_33 ,
V_12 -> V_33 +
V_12 -> V_40 ,
V_12 -> V_32 -
V_12 -> V_40 ) ;
}
V_12 -> V_32 -= V_12 -> V_40 ;
V_12 -> V_40 = 0 ;
if ( V_12 -> V_32 > 0 ) {
if ( ( V_30 = F_9 ( V_12 ) ) != 0 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_5 ,
V_30 ) ;
switch ( V_30 ) {
case - V_44 :
case - V_45 :
break;
default:
V_43 -> V_46 . V_47 ++ ;
F_12 ( V_43 ) ;
}
}
} else {
if ( V_12 -> V_48 != - 1 &&
F_5 ( V_12 -> V_48 ) !=
V_12 -> V_21 . V_23 )
F_4 ( V_12 , V_12 -> V_48 ) ;
F_13 ( V_43 ) ;
}
}
}
static T_2 F_14 ( struct V_49 * V_50 ,
struct V_42 * V_43 )
{
struct V_11 * V_12 ;
unsigned int V_29 ;
int V_30 = 0 ;
F_15 ( V_43 ) ;
F_16 ( V_50 ) ;
V_12 = F_17 ( V_43 ) ;
F_18 ( & V_12 -> V_51 ) ;
V_12 -> V_48 = F_19 ( V_50 ) ;
V_29 =
F_20 ( V_50 , V_12 -> V_33 , V_52 ) ;
V_12 -> V_32 = V_29 ;
if ( ( V_30 = F_9 ( V_12 ) ) != 0 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_6 , V_30 ) ;
switch ( V_30 ) {
case - V_44 :
case - V_45 :
break;
default:
V_43 -> V_46 . V_47 ++ ;
F_12 ( V_43 ) ;
}
} else {
V_43 -> V_46 . V_53 ++ ;
V_43 -> V_46 . V_54 += V_50 -> V_55 ;
}
F_21 ( V_50 ) ;
F_22 ( & V_12 -> V_51 ) ;
return V_56 ;
}
static void F_23 ( struct V_8 * V_8 )
{
struct V_11 * V_12 = V_8 -> V_41 ;
int V_30 ;
if ( ! F_11 ( V_12 -> V_43 ) ) {
V_12 -> V_57 = 0 ;
return;
}
if ( V_8 -> V_9 != 0 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_7 ,
V_8 -> V_9 ) ;
V_12 -> V_57 = 0 ;
return;
}
if ( V_8 -> V_58 > 0 ) {
T_1 * V_59 = V_8 -> V_60 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_8 -> V_58 ; V_16 ++ ) {
V_12 -> V_61 ++ ;
V_59 [ V_16 ] =
V_59 [ V_16 ] ^ V_12 -> V_61 ^ 0x55u ;
if ( V_12 -> V_61 != 0 ) {
F_24 ( V_12 -> V_43 ,
& V_12 -> V_43 -> V_46 ,
& V_12 -> V_62 ,
V_59 [ V_16 ] ) ;
}
}
V_12 -> V_57 =
( V_12 -> V_62 . V_63 != V_64 ) ? 1 : 0 ;
}
V_8 -> V_9 = 0 ;
V_30 = F_8 ( V_8 , V_27 ) ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_11 * V_12 = F_17 ( V_43 ) ;
int V_15 = - V_19 ;
char V_65 [ 16 ] ;
V_12 -> V_57 = 0 ;
V_12 -> V_62 . V_66 = FALSE ;
V_12 -> V_62 . V_63 = V_64 ;
V_12 -> V_62 . V_67 = V_68 ;
V_12 -> V_62 . V_50 = F_26 ( V_68 ) ;
if ( ! V_12 -> V_62 . V_50 )
goto V_69;
F_27 ( V_12 -> V_62 . V_50 , 1 ) ;
V_12 -> V_62 . V_70 = V_12 -> V_62 . V_50 -> V_71 ;
V_12 -> V_72 = F_28 ( 0 , V_73 ) ;
if ( ! V_12 -> V_72 )
goto V_69;
V_12 -> V_38 = F_28 ( 0 , V_73 ) ;
if ( ! V_12 -> V_38 )
goto V_69;
V_12 -> V_18 = F_28 ( 0 , V_73 ) ;
if ( ! V_12 -> V_18 )
goto V_69;
V_12 -> V_48 = 9600 ;
V_15 = F_4 ( V_12 , 9600 ) ;
if ( V_15 < 0 )
goto V_69;
sprintf ( V_65 , L_8 , V_12 -> V_26 -> V_74 ) ;
V_12 -> V_75 = F_29 ( V_43 , & V_12 -> V_76 , V_65 ) ;
if ( ! V_12 -> V_75 ) {
V_15 = - V_19 ;
F_3 ( & V_12 -> V_26 -> V_10 , L_9 ) ;
goto V_69;
}
F_6 ( V_12 -> V_72 , V_12 -> V_26 ,
F_30 ( V_12 -> V_26 , 0 ) ,
( unsigned char * ) V_12 -> V_77 ,
V_12 -> V_78 , V_79 ,
F_23 , V_12 ) ;
V_12 -> V_72 -> V_9 = 0 ;
V_15 = F_8 ( V_12 -> V_72 , V_73 ) ;
if ( V_15 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_10 , V_15 ) ;
goto V_80;
}
F_12 ( V_43 ) ;
return 0 ;
V_80:
F_31 ( V_12 -> V_75 ) ;
V_69:
F_32 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
F_32 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
F_32 ( V_12 -> V_72 ) ;
V_12 -> V_72 = NULL ;
if ( V_12 -> V_62 . V_50 ) {
F_33 ( V_12 -> V_62 . V_50 ) ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_62 . V_70 = NULL ;
}
return V_15 ;
}
static int F_34 ( struct V_42 * V_43 )
{
struct V_11 * V_12 = F_17 ( V_43 ) ;
F_15 ( V_43 ) ;
F_35 ( V_12 -> V_38 ) ;
F_32 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
F_35 ( V_12 -> V_18 ) ;
F_32 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
F_35 ( V_12 -> V_72 ) ;
F_32 ( V_12 -> V_72 ) ;
V_12 -> V_72 = NULL ;
F_33 ( V_12 -> V_62 . V_50 ) ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_62 . V_70 = NULL ;
V_12 -> V_62 . V_66 = FALSE ;
V_12 -> V_62 . V_63 = V_64 ;
V_12 -> V_57 = 0 ;
if ( V_12 -> V_75 )
F_31 ( V_12 -> V_75 ) ;
V_12 -> V_75 = NULL ;
return 0 ;
}
static int F_36 ( struct V_42 * V_43 , struct V_81 * V_82 , int V_83 )
{
struct V_84 * V_85 = (struct V_84 * ) V_82 ;
struct V_11 * V_12 = F_17 ( V_43 ) ;
int V_30 = 0 ;
switch ( V_83 ) {
case V_86 :
if ( ! F_37 ( V_87 ) )
return - V_88 ;
if ( F_38 ( V_12 -> V_43 ) )
return F_4 ( V_12 , V_85 -> V_89 ) ;
break;
case V_90 :
if ( ! F_37 ( V_87 ) )
return - V_88 ;
if ( F_11 ( V_12 -> V_43 ) )
F_39 ( V_12 -> V_43 , TRUE ) ;
break;
case V_91 :
V_85 -> V_92 = V_12 -> V_57 ;
break;
default:
V_30 = - V_20 ;
}
return V_30 ;
}
static int F_40 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
struct V_97 * V_10 = F_41 ( V_94 ) ;
struct V_11 * V_12 = NULL ;
struct V_42 * V_98 = NULL ;
int V_30 = - V_19 ;
V_98 = F_42 ( sizeof( * V_12 ) ) ;
if ( ! V_98 )
goto V_99;
F_43 ( V_98 , & V_94 -> V_10 ) ;
V_12 = F_17 ( V_98 ) ;
V_12 -> V_43 = V_98 ;
V_12 -> V_26 = V_10 ;
V_12 -> V_75 = NULL ;
V_12 -> V_35 = NULL ;
V_12 -> V_38 = NULL ;
V_12 -> V_33 = NULL ;
V_12 -> V_34 = NULL ;
V_12 -> V_32 = 0 ;
V_12 -> V_40 = 0 ;
V_12 -> V_77 = NULL ;
V_12 -> V_72 = NULL ;
V_12 -> V_78 = NULL ;
V_12 -> V_61 = 0 ;
V_12 -> V_62 . V_66 = FALSE ;
V_12 -> V_62 . V_63 = V_64 ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_57 = 0 ;
F_44 ( & V_12 -> V_51 ) ;
V_12 -> V_17 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_21 . V_23 = 0 ;
V_12 -> V_78 = F_45 ( V_79 , V_73 ) ;
if ( ! V_12 -> V_78 )
goto V_69;
V_12 -> V_77 =
F_45 ( sizeof( struct V_100 ) , V_73 ) ;
if ( ! V_12 -> V_77 )
goto V_69;
V_12 -> V_77 -> V_101 =
V_102 | V_103 | V_104 ;
V_12 -> V_77 -> V_105 = V_106 ;
V_12 -> V_77 -> V_36 = F_10 ( 0x0200 ) ;
V_12 -> V_77 -> V_107 = 0 ;
V_12 -> V_77 -> V_37 = F_10 ( V_79 ) ;
V_12 -> V_33 = F_45 ( V_52 , V_73 ) ;
if ( ! V_12 -> V_33 )
goto V_69;
V_12 -> V_34 = F_45 ( V_31 , V_73 ) ;
if ( ! V_12 -> V_34 )
goto V_69;
V_12 -> V_35 =
F_45 ( sizeof( struct V_100 ) , V_73 ) ;
if ( ! V_12 -> V_35 )
goto V_69;
V_12 -> V_35 -> V_101 =
V_108 | V_103 | V_104 ;
V_12 -> V_35 -> V_105 = V_109 ;
V_12 -> V_35 -> V_36 = 0 ;
V_12 -> V_35 -> V_107 = 0 ;
V_12 -> V_35 -> V_37 = 0 ;
V_12 -> V_17 =
F_45 ( sizeof( struct V_100 ) , V_73 ) ;
if ( ! V_12 -> V_17 )
goto V_69;
V_12 -> V_17 -> V_101 =
V_108 | V_103 | V_104 ;
V_12 -> V_17 -> V_105 = V_109 ;
V_12 -> V_17 -> V_36 = F_10 ( 0x0200 ) ;
V_12 -> V_17 -> V_107 = F_10 ( 0x0001 ) ;
V_12 -> V_17 -> V_37 =
F_10 ( sizeof( struct V_22 ) ) ;
F_46 ( V_110 L_11
L_12 ,
V_10 -> V_74 , F_47 ( V_10 -> V_111 . V_112 ) ,
F_47 ( V_10 -> V_111 . V_113 ) ) ;
F_48 ( & V_12 -> V_76 ) ;
V_12 -> V_76 . V_114 . V_115 =
V_116 | V_117 | V_118 | V_119 | V_120 ;
V_12 -> V_76 . V_121 . V_115 &= V_122 ;
F_49 ( & V_12 -> V_76 ) ;
V_98 -> V_123 = & V_124 ;
V_30 = F_50 ( V_98 ) ;
if ( V_30 != 0 )
goto V_69;
F_51 ( & V_98 -> V_10 , L_13 ,
V_98 -> V_125 ) ;
F_52 ( V_94 , V_12 ) ;
return 0 ;
V_69:
F_53 ( V_12 -> V_17 ) ;
F_53 ( V_12 -> V_35 ) ;
F_53 ( V_12 -> V_34 ) ;
F_53 ( V_12 -> V_33 ) ;
F_53 ( V_12 -> V_77 ) ;
F_53 ( V_12 -> V_78 ) ;
F_54 ( V_98 ) ;
V_99:
return V_30 ;
}
static void F_55 ( struct V_93 * V_94 )
{
struct V_11 * V_12 = F_56 ( V_94 ) ;
if ( ! V_12 )
return;
F_57 ( V_12 -> V_43 ) ;
if ( V_12 -> V_18 != NULL ) {
F_35 ( V_12 -> V_18 ) ;
F_32 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
}
if ( V_12 -> V_38 != NULL ) {
F_35 ( V_12 -> V_38 ) ;
F_32 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
}
if ( V_12 -> V_72 != NULL ) {
F_35 ( V_12 -> V_72 ) ;
F_32 ( V_12 -> V_72 ) ;
V_12 -> V_72 = NULL ;
}
F_53 ( V_12 -> V_17 ) ;
F_53 ( V_12 -> V_35 ) ;
F_53 ( V_12 -> V_34 ) ;
F_53 ( V_12 -> V_33 ) ;
F_53 ( V_12 -> V_77 ) ;
F_53 ( V_12 -> V_78 ) ;
F_54 ( V_12 -> V_43 ) ;
F_52 ( V_94 , NULL ) ;
}
static int F_58 ( struct V_93 * V_94 , T_3 V_126 )
{
struct V_11 * V_12 = F_56 ( V_94 ) ;
F_59 ( V_12 -> V_43 ) ;
if ( V_12 -> V_18 != NULL )
F_35 ( V_12 -> V_18 ) ;
if ( V_12 -> V_38 != NULL )
F_35 ( V_12 -> V_38 ) ;
if ( V_12 -> V_72 != NULL )
F_35 ( V_12 -> V_72 ) ;
return 0 ;
}
static int F_60 ( struct V_93 * V_94 )
{
struct V_11 * V_12 = F_56 ( V_94 ) ;
if ( V_12 -> V_72 != NULL ) {
F_8 ( V_12 -> V_72 , V_73 ) ;
}
F_61 ( V_12 -> V_43 ) ;
return 0 ;
}
