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
F_25 ( & V_12 -> V_63 ) ;
V_12 -> V_57 =
( V_12 -> V_62 . V_64 != V_65 ) ? 1 : 0 ;
}
V_8 -> V_9 = 0 ;
V_30 = F_8 ( V_8 , V_27 ) ;
}
static int F_26 ( struct V_42 * V_43 )
{
struct V_11 * V_12 = F_17 ( V_43 ) ;
int V_15 = - V_19 ;
char V_66 [ 16 ] ;
V_12 -> V_57 = 0 ;
V_12 -> V_62 . V_67 = FALSE ;
V_12 -> V_62 . V_64 = V_65 ;
V_12 -> V_62 . V_68 = V_69 ;
V_12 -> V_62 . V_50 = F_27 ( V_69 ) ;
if ( ! V_12 -> V_62 . V_50 )
goto V_70;
F_28 ( V_12 -> V_62 . V_50 , 1 ) ;
V_12 -> V_62 . V_71 = V_12 -> V_62 . V_50 -> V_72 ;
F_25 ( & V_12 -> V_63 ) ;
V_12 -> V_73 = F_29 ( 0 , V_74 ) ;
if ( ! V_12 -> V_73 )
goto V_70;
V_12 -> V_38 = F_29 ( 0 , V_74 ) ;
if ( ! V_12 -> V_38 )
goto V_70;
V_12 -> V_18 = F_29 ( 0 , V_74 ) ;
if ( ! V_12 -> V_18 )
goto V_70;
V_12 -> V_48 = 9600 ;
V_15 = F_4 ( V_12 , 9600 ) ;
if ( V_15 < 0 )
goto V_70;
sprintf ( V_66 , L_8 , V_12 -> V_26 -> V_75 ) ;
V_12 -> V_76 = F_30 ( V_43 , & V_12 -> V_77 , V_66 ) ;
if ( ! V_12 -> V_76 ) {
F_3 ( & V_12 -> V_26 -> V_10 , L_9 ) ;
goto V_70;
}
F_6 ( V_12 -> V_73 , V_12 -> V_26 ,
F_31 ( V_12 -> V_26 , 0 ) ,
( unsigned char * ) V_12 -> V_78 ,
V_12 -> V_79 , V_80 ,
F_23 , V_12 ) ;
V_12 -> V_73 -> V_9 = 0 ;
V_15 = F_8 ( V_12 -> V_73 , V_74 ) ;
if ( V_15 ) {
F_3 ( & V_12 -> V_26 -> V_10 ,
L_10 , V_15 ) ;
goto V_81;
}
F_12 ( V_43 ) ;
return 0 ;
V_81:
F_32 ( V_12 -> V_76 ) ;
V_70:
F_33 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
F_33 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
F_33 ( V_12 -> V_73 ) ;
V_12 -> V_73 = NULL ;
if ( V_12 -> V_62 . V_50 ) {
F_34 ( V_12 -> V_62 . V_50 ) ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_62 . V_71 = NULL ;
}
return V_15 ;
}
static int F_35 ( struct V_42 * V_43 )
{
struct V_11 * V_12 = F_17 ( V_43 ) ;
F_15 ( V_43 ) ;
F_36 ( V_12 -> V_38 ) ;
F_33 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
F_36 ( V_12 -> V_18 ) ;
F_33 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
F_36 ( V_12 -> V_73 ) ;
F_33 ( V_12 -> V_73 ) ;
V_12 -> V_73 = NULL ;
F_34 ( V_12 -> V_62 . V_50 ) ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_62 . V_71 = NULL ;
V_12 -> V_62 . V_67 = FALSE ;
V_12 -> V_62 . V_64 = V_65 ;
V_12 -> V_57 = 0 ;
if ( V_12 -> V_76 )
F_32 ( V_12 -> V_76 ) ;
V_12 -> V_76 = NULL ;
return 0 ;
}
static int F_37 ( struct V_42 * V_43 , struct V_82 * V_83 , int V_84 )
{
struct V_85 * V_86 = (struct V_85 * ) V_83 ;
struct V_11 * V_12 = F_17 ( V_43 ) ;
int V_30 = 0 ;
switch ( V_84 ) {
case V_87 :
if ( ! F_38 ( V_88 ) )
return - V_89 ;
if ( F_39 ( V_12 -> V_43 ) )
return F_4 ( V_12 , V_86 -> V_90 ) ;
break;
case V_91 :
if ( ! F_38 ( V_88 ) )
return - V_89 ;
if ( F_11 ( V_12 -> V_43 ) )
F_40 ( V_12 -> V_43 , TRUE ) ;
break;
case V_92 :
V_86 -> V_93 = V_12 -> V_57 ;
break;
default:
V_30 = - V_20 ;
}
return V_30 ;
}
static int F_41 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_98 * V_10 = F_42 ( V_95 ) ;
struct V_11 * V_12 = NULL ;
struct V_42 * V_99 = NULL ;
int V_30 = - V_19 ;
V_99 = F_43 ( sizeof( * V_12 ) ) ;
if ( ! V_99 )
goto V_100;
F_44 ( V_99 , & V_95 -> V_10 ) ;
V_12 = F_17 ( V_99 ) ;
V_12 -> V_43 = V_99 ;
V_12 -> V_26 = V_10 ;
V_12 -> V_76 = NULL ;
V_12 -> V_35 = NULL ;
V_12 -> V_38 = NULL ;
V_12 -> V_33 = NULL ;
V_12 -> V_34 = NULL ;
V_12 -> V_32 = 0 ;
V_12 -> V_40 = 0 ;
V_12 -> V_78 = NULL ;
V_12 -> V_73 = NULL ;
V_12 -> V_79 = NULL ;
V_12 -> V_61 = 0 ;
V_12 -> V_62 . V_67 = FALSE ;
V_12 -> V_62 . V_64 = V_65 ;
V_12 -> V_62 . V_50 = NULL ;
V_12 -> V_57 = 0 ;
F_45 ( & V_12 -> V_51 ) ;
V_12 -> V_17 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_21 . V_23 = 0 ;
V_12 -> V_79 = F_46 ( V_80 , V_74 ) ;
if ( ! V_12 -> V_79 )
goto V_70;
V_12 -> V_78 =
F_46 ( sizeof( struct V_101 ) , V_74 ) ;
if ( ! V_12 -> V_78 )
goto V_70;
V_12 -> V_78 -> V_102 =
V_103 | V_104 | V_105 ;
V_12 -> V_78 -> V_106 = V_107 ;
V_12 -> V_78 -> V_36 = F_10 ( 0x0200 ) ;
V_12 -> V_78 -> V_108 = 0 ;
V_12 -> V_78 -> V_37 = F_10 ( V_80 ) ;
V_12 -> V_33 = F_46 ( V_52 , V_74 ) ;
if ( ! V_12 -> V_33 )
goto V_70;
V_12 -> V_34 = F_46 ( V_31 , V_74 ) ;
if ( ! V_12 -> V_34 )
goto V_70;
V_12 -> V_35 =
F_46 ( sizeof( struct V_101 ) , V_74 ) ;
if ( ! V_12 -> V_35 )
goto V_70;
V_12 -> V_35 -> V_102 =
V_109 | V_104 | V_105 ;
V_12 -> V_35 -> V_106 = V_110 ;
V_12 -> V_35 -> V_36 = 0 ;
V_12 -> V_35 -> V_108 = 0 ;
V_12 -> V_35 -> V_37 = 0 ;
V_12 -> V_17 =
F_46 ( sizeof( struct V_101 ) , V_74 ) ;
if ( ! V_12 -> V_17 )
goto V_70;
V_12 -> V_17 -> V_102 =
V_109 | V_104 | V_105 ;
V_12 -> V_17 -> V_106 = V_110 ;
V_12 -> V_17 -> V_36 = F_10 ( 0x0200 ) ;
V_12 -> V_17 -> V_108 = F_10 ( 0x0001 ) ;
V_12 -> V_17 -> V_37 =
F_10 ( sizeof( struct V_22 ) ) ;
F_47 ( V_111 L_11
L_12 ,
V_10 -> V_75 , F_48 ( V_10 -> V_112 . V_113 ) ,
F_48 ( V_10 -> V_112 . V_114 ) ) ;
F_49 ( & V_12 -> V_77 ) ;
V_12 -> V_77 . V_115 . V_116 =
V_117 | V_118 | V_119 | V_120 | V_121 ;
V_12 -> V_77 . V_122 . V_116 &= V_123 ;
F_50 ( & V_12 -> V_77 ) ;
V_99 -> V_124 = & V_125 ;
V_30 = F_51 ( V_99 ) ;
if ( V_30 != 0 )
goto V_70;
F_52 ( & V_99 -> V_10 , L_13 ,
V_99 -> V_126 ) ;
F_53 ( V_95 , V_12 ) ;
return 0 ;
V_70:
F_54 ( V_12 -> V_17 ) ;
F_54 ( V_12 -> V_35 ) ;
F_54 ( V_12 -> V_34 ) ;
F_54 ( V_12 -> V_33 ) ;
F_54 ( V_12 -> V_78 ) ;
F_54 ( V_12 -> V_79 ) ;
F_55 ( V_99 ) ;
V_100:
return V_30 ;
}
static void F_56 ( struct V_94 * V_95 )
{
struct V_11 * V_12 = F_57 ( V_95 ) ;
if ( ! V_12 )
return;
F_58 ( V_12 -> V_43 ) ;
if ( V_12 -> V_18 != NULL ) {
F_36 ( V_12 -> V_18 ) ;
F_33 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
}
if ( V_12 -> V_38 != NULL ) {
F_36 ( V_12 -> V_38 ) ;
F_33 ( V_12 -> V_38 ) ;
V_12 -> V_38 = NULL ;
}
if ( V_12 -> V_73 != NULL ) {
F_36 ( V_12 -> V_73 ) ;
F_33 ( V_12 -> V_73 ) ;
V_12 -> V_73 = NULL ;
}
F_54 ( V_12 -> V_17 ) ;
F_54 ( V_12 -> V_35 ) ;
F_54 ( V_12 -> V_34 ) ;
F_54 ( V_12 -> V_33 ) ;
F_54 ( V_12 -> V_78 ) ;
F_54 ( V_12 -> V_79 ) ;
F_55 ( V_12 -> V_43 ) ;
F_53 ( V_95 , NULL ) ;
}
static int F_59 ( struct V_94 * V_95 , T_3 V_127 )
{
struct V_11 * V_12 = F_57 ( V_95 ) ;
F_60 ( V_12 -> V_43 ) ;
if ( V_12 -> V_18 != NULL )
F_36 ( V_12 -> V_18 ) ;
if ( V_12 -> V_38 != NULL )
F_36 ( V_12 -> V_38 ) ;
if ( V_12 -> V_73 != NULL )
F_36 ( V_12 -> V_73 ) ;
return 0 ;
}
static int F_61 ( struct V_94 * V_95 )
{
struct V_11 * V_12 = F_57 ( V_95 ) ;
if ( V_12 -> V_73 != NULL ) {
F_8 ( V_12 -> V_73 , V_74 ) ;
}
F_62 ( V_12 -> V_43 ) ;
return 0 ;
}
