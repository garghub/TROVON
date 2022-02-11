static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
F_2 ( V_4 == NULL ) ;
return ( (struct V_1 * ) V_4 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_6 , unsigned V_7 )
{
if ( V_6 -> V_8 && V_6 -> V_8 != V_6 -> V_9 )
F_4 ( V_6 -> V_8 ) ;
V_6 -> V_8 = F_5 ( V_7 , V_10 ) ;
if ( ! V_6 -> V_8 ) {
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
return 1 ;
}
V_6 -> V_11 = V_7 ;
return 0 ;
}
static struct V_13 * F_6 ( struct V_2 * V_3 ,
void * V_14 , unsigned V_15 , int V_16 )
{
struct V_13 * V_17 ;
struct V_18 * V_19 = V_3 -> V_18 ;
V_17 = F_7 ( V_19 , V_16 , V_10 ) ;
if ( ! V_17 ) {
F_8 ( V_20 , V_3 ,
L_1 , V_21 ) ;
return NULL ;
}
if ( V_15 && F_9 ( V_19 , V_17 , V_14 , V_15 , V_10 ) ) {
F_10 ( V_17 ) ;
F_8 ( V_20 , V_3 ,
L_2 , V_21 ) ;
return NULL ;
}
V_17 -> V_22 = V_23 ;
V_17 -> V_24 |= V_25 | V_26 |
V_27 ;
V_17 -> V_28 = V_29 ;
V_17 -> V_30 = V_31 ;
return V_17 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_32 = V_33 ;
V_17 = F_6 ( V_3 , V_6 -> V_9 , V_12 , V_34 ) ;
if ( ! V_17 )
goto V_35;
V_17 -> V_36 [ 0 ] = V_37 ;
V_17 -> V_36 [ 1 ] = 0 ;
V_17 -> V_36 [ 2 ] = 0 ;
V_17 -> V_36 [ 4 ] = V_12 ;
V_17 -> V_38 = F_12 ( V_37 ) ;
V_17 -> V_39 = V_6 -> V_39 ;
memset ( V_17 -> V_39 , 0 , V_40 ) ;
V_17 -> V_41 = V_6 -> V_42 = 0 ;
V_32 = F_13 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_32 == - V_43 ) {
F_8 ( V_20 , V_3 ,
L_3 ,
V_44 , V_17 -> V_45 ) ;
V_6 -> V_42 = V_17 -> V_41 ;
V_32 = V_46 ;
}
F_10 ( V_17 ) ;
V_35:
return V_32 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_32 = V_33 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_34 ) ;
if ( ! V_17 )
goto V_35;
V_17 -> V_36 [ 0 ] = V_37 ;
V_17 -> V_36 [ 1 ] = 1 ;
V_17 -> V_36 [ 2 ] = 0x83 ;
V_17 -> V_36 [ 4 ] = V_6 -> V_11 ;
V_17 -> V_38 = F_12 ( V_37 ) ;
V_17 -> V_39 = V_6 -> V_39 ;
memset ( V_17 -> V_39 , 0 , V_40 ) ;
V_17 -> V_41 = V_6 -> V_42 = 0 ;
V_32 = F_13 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_32 == - V_43 ) {
F_8 ( V_20 , V_3 ,
L_4 ,
V_44 , V_17 -> V_45 ) ;
V_6 -> V_42 = V_17 -> V_41 ;
V_32 = V_46 ;
}
F_10 ( V_17 ) ;
V_35:
return V_32 ;
}
static unsigned F_15 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_32 = V_33 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_34 ) ;
if ( ! V_17 )
goto V_35;
V_17 -> V_36 [ 0 ] = V_47 ;
V_17 -> V_36 [ 1 ] = V_48 ;
V_17 -> V_36 [ 6 ] = ( V_6 -> V_11 >> 24 ) & 0xff ;
V_17 -> V_36 [ 7 ] = ( V_6 -> V_11 >> 16 ) & 0xff ;
V_17 -> V_36 [ 8 ] = ( V_6 -> V_11 >> 8 ) & 0xff ;
V_17 -> V_36 [ 9 ] = V_6 -> V_11 & 0xff ;
V_17 -> V_38 = F_12 ( V_47 ) ;
V_17 -> V_39 = V_6 -> V_39 ;
memset ( V_17 -> V_39 , 0 , V_40 ) ;
V_17 -> V_41 = V_6 -> V_42 = 0 ;
V_32 = F_13 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_32 == - V_43 ) {
F_8 ( V_20 , V_3 ,
L_5 ,
V_44 , V_17 -> V_45 ) ;
V_6 -> V_42 = V_17 -> V_41 ;
V_32 = V_46 ;
}
F_10 ( V_17 ) ;
V_35:
return V_32 ;
}
static void F_16 ( struct V_13 * V_49 , int error )
{
struct V_1 * V_6 = V_49 -> V_50 ;
struct V_51 V_52 ;
unsigned V_32 = V_53 ;
if ( error || F_17 ( V_49 -> V_45 ) != V_54 ||
F_18 ( V_49 -> V_45 ) != V_55 ) {
V_32 = V_46 ;
goto V_35;
}
if ( V_6 -> V_42 > 0 ) {
V_32 = F_19 ( V_6 -> V_39 , V_40 ,
& V_52 ) ;
if ( ! V_32 ) {
V_32 = V_46 ;
goto V_35;
}
V_32 = F_20 ( V_6 -> V_3 , & V_52 ) ;
if ( V_32 == V_56 ) {
V_32 = V_57 ;
goto V_35;
}
F_8 ( V_20 , V_6 -> V_3 ,
L_6 ,
V_44 , V_52 . V_58 ,
V_52 . V_59 , V_52 . V_60 ) ;
V_32 = V_46 ;
}
if ( V_32 == V_53 ) {
V_6 -> V_61 = V_62 ;
F_8 ( V_20 , V_6 -> V_3 ,
L_7 ,
V_44 , V_6 -> V_63 ,
F_21 ( V_6 -> V_61 ) ) ;
}
V_35:
V_49 -> V_50 = NULL ;
F_22 ( V_49 -> V_19 , V_49 ) ;
if ( V_6 -> V_64 ) {
V_6 -> V_64 ( V_6 -> V_65 , V_32 ) ;
V_6 -> V_64 = V_6 -> V_65 = NULL ;
}
return;
}
static unsigned F_23 ( struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_66 = 8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
memset ( V_6 -> V_8 , 0 , V_66 ) ;
V_6 -> V_8 [ 4 ] = V_62 & 0x0f ;
V_6 -> V_8 [ 6 ] = ( V_6 -> V_63 >> 8 ) & 0xff ;
V_6 -> V_8 [ 7 ] = V_6 -> V_63 & 0xff ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_66 , V_67 ) ;
if ( ! V_17 )
return V_33 ;
V_17 -> V_36 [ 0 ] = V_68 ;
V_17 -> V_36 [ 1 ] = V_69 ;
V_17 -> V_36 [ 6 ] = ( V_66 >> 24 ) & 0xff ;
V_17 -> V_36 [ 7 ] = ( V_66 >> 16 ) & 0xff ;
V_17 -> V_36 [ 8 ] = ( V_66 >> 8 ) & 0xff ;
V_17 -> V_36 [ 9 ] = V_66 & 0xff ;
V_17 -> V_38 = F_12 ( V_68 ) ;
V_17 -> V_39 = V_6 -> V_39 ;
memset ( V_17 -> V_39 , 0 , V_40 ) ;
V_17 -> V_41 = V_6 -> V_42 = 0 ;
V_17 -> V_50 = V_6 ;
F_24 ( V_17 -> V_19 , NULL , V_17 , 1 , F_16 ) ;
return V_53 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_32 ;
V_32 = F_11 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
return V_32 ;
V_6 -> V_70 = ( V_6 -> V_9 [ 5 ] >> 4 ) & 0x3 ;
switch ( V_6 -> V_70 ) {
case V_71 | V_72 :
F_8 ( V_20 , V_3 ,
L_8 ,
V_44 ) ;
break;
case V_71 :
F_8 ( V_20 , V_3 , L_9 ,
V_44 ) ;
break;
case V_72 :
F_8 ( V_20 , V_3 , L_10 ,
V_44 ) ;
break;
default:
V_6 -> V_70 = V_73 ;
F_8 ( V_20 , V_3 , L_11 ,
V_44 ) ;
V_32 = V_74 ;
break;
}
return V_32 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_7 ;
unsigned V_32 ;
unsigned char * V_75 ;
V_76:
V_32 = F_14 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
return V_32 ;
V_7 = ( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_8 ( V_77 , V_3 ,
L_12 ,
V_44 ) ;
return V_78 ;
}
goto V_76;
}
V_75 = V_6 -> V_8 + 4 ;
while ( V_75 < V_6 -> V_8 + V_7 ) {
switch ( V_75 [ 1 ] & 0xf ) {
case 0x4 :
V_6 -> V_79 = ( V_75 [ 6 ] << 8 ) + V_75 [ 7 ] ;
break;
case 0x5 :
V_6 -> V_63 = ( V_75 [ 6 ] << 8 ) + V_75 [ 7 ] ;
break;
default:
break;
}
V_75 += V_75 [ 3 ] + 4 ;
}
if ( V_6 -> V_63 == - 1 ) {
F_8 ( V_20 , V_3 ,
L_13 ,
V_44 ) ;
V_6 -> V_61 = V_62 ;
V_6 -> V_70 = V_73 ;
V_32 = V_74 ;
} else {
F_8 ( V_20 , V_3 ,
L_14 ,
V_44 , V_6 -> V_63 , V_6 -> V_79 ) ;
}
return V_32 ;
}
static char F_21 ( int V_61 )
{
switch ( V_61 ) {
case V_62 :
return 'A' ;
case V_80 :
return 'N' ;
case V_81 :
return 'S' ;
case V_82 :
return 'U' ;
case V_83 :
return 'L' ;
case V_84 :
return 'O' ;
case V_85 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_20 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
switch ( V_52 -> V_58 ) {
case V_86 :
if ( V_52 -> V_59 == 0x04 && V_52 -> V_60 == 0x0a )
return V_56 ;
if ( V_52 -> V_59 == 0x04 && V_52 -> V_60 == 0x0b )
return V_87 ;
if ( V_52 -> V_59 == 0x04 && V_52 -> V_60 == 0x0c )
return V_87 ;
if ( V_52 -> V_59 == 0x04 && V_52 -> V_60 == 0x12 )
return V_87 ;
break;
case V_88 :
if ( V_52 -> V_59 == 0x29 && V_52 -> V_60 == 0x00 )
return V_56 ;
if ( V_52 -> V_59 == 0x2a && V_52 -> V_60 == 0x06 ) {
return V_56 ;
}
if ( V_52 -> V_59 == 0x2a && V_52 -> V_60 == 0x07 ) {
return V_56 ;
}
if ( V_52 -> V_59 == 0x3f && V_52 -> V_60 == 0x0e ) {
return V_56 ;
}
break;
}
return V_89 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_51 V_52 ;
int V_7 , V_90 , V_91 , V_92 = 0 ;
char * V_93 ;
unsigned V_32 ;
unsigned long V_94 , V_95 = 10 ;
V_94 = F_28 ( V_96 + V_31 ) ;
V_76:
V_32 = F_15 ( V_3 , V_6 ) ;
if ( V_32 == V_46 && V_6 -> V_42 > 0 ) {
V_32 = F_19 ( V_6 -> V_39 , V_40 ,
& V_52 ) ;
if ( ! V_32 )
return V_46 ;
V_32 = F_20 ( V_3 , & V_52 ) ;
if ( V_32 == V_56 && F_29 ( V_96 , V_94 ) )
goto V_76;
F_8 ( V_20 , V_3 ,
L_15 ,
V_44 , V_52 . V_58 ,
V_52 . V_59 , V_52 . V_60 ) ;
V_32 = V_46 ;
}
if ( V_32 != V_53 )
return V_32 ;
V_7 = ( V_6 -> V_8 [ 0 ] << 24 ) + ( V_6 -> V_8 [ 1 ] << 16 ) +
( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_8 ( V_77 , V_3 ,
L_12 , V_21 ) ;
return V_78 ;
}
goto V_76;
}
for ( V_90 = 4 , V_93 = V_6 -> V_8 + 4 ; V_90 < V_7 ; V_90 += V_91 , V_93 += V_91 ) {
if ( V_6 -> V_63 == ( V_93 [ 2 ] << 8 ) + V_93 [ 3 ] ) {
V_6 -> V_61 = V_93 [ 0 ] & 0x0f ;
V_92 = V_93 [ 1 ] ;
}
V_91 = 8 + ( V_93 [ 7 ] * 4 ) ;
}
F_8 ( V_20 , V_3 ,
L_16 ,
V_44 , V_6 -> V_63 , F_21 ( V_6 -> V_61 ) ,
V_92 & V_97 ? 'T' : 't' ,
V_92 & V_98 ? 'O' : 'o' ,
V_92 & V_99 ? 'L' : 'l' ,
V_92 & V_100 ? 'U' : 'u' ,
V_92 & V_101 ? 'S' : 's' ,
V_92 & V_102 ? 'N' : 'n' ,
V_92 & V_103 ? 'A' : 'a' ) ;
switch ( V_6 -> V_61 ) {
case V_85 :
if ( F_29 ( V_96 , V_94 ) ) {
V_95 *= 10 ;
F_30 ( V_95 ) ;
goto V_76;
}
V_32 = V_57 ;
V_6 -> V_61 = V_81 ;
break;
case V_84 :
case V_82 :
V_32 = V_104 ;
break;
default:
V_32 = V_53 ;
break;
}
return V_32 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_32 ;
V_32 = F_25 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
goto V_105;
V_32 = F_26 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
goto V_105;
V_32 = F_27 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
goto V_105;
V_105:
return V_32 ;
}
static int F_32 ( struct V_2 * V_3 ,
T_1 V_106 , void * V_107 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_32 = V_53 ;
if ( V_6 -> V_63 != - 1 ) {
V_32 = F_27 ( V_3 , V_6 ) ;
if ( V_32 != V_53 )
goto V_105;
}
if ( V_6 -> V_70 & V_71 &&
V_6 -> V_61 != V_62 &&
V_6 -> V_61 != V_83 ) {
V_6 -> V_64 = V_106 ;
V_6 -> V_65 = V_107 ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 == V_53 )
return 0 ;
V_6 -> V_64 = V_6 -> V_65 = NULL ;
}
V_105:
if ( V_106 )
V_106 ( V_107 , V_32 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_13 * V_49 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_108 = V_109 ;
if ( V_6 -> V_61 == V_85 )
V_108 = V_110 ;
else if ( V_6 -> V_61 != V_62 &&
V_6 -> V_61 != V_80 &&
V_6 -> V_61 != V_83 ) {
V_108 = V_111 ;
V_49 -> V_24 |= V_112 ;
}
return V_108 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_113 ;
int V_32 = V_53 ;
V_4 = F_35 ( sizeof( * V_4 )
+ sizeof( * V_6 ) , V_114 ) ;
if ( ! V_4 ) {
F_8 ( V_115 , V_3 , L_17 ,
V_44 ) ;
return - V_116 ;
}
V_4 -> V_117 = & V_118 ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
V_6 -> V_70 = V_119 ;
V_6 -> V_61 = V_62 ;
V_6 -> V_63 = - 1 ;
V_6 -> V_79 = - 1 ;
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_3 = V_3 ;
V_32 = F_31 ( V_3 , V_6 ) ;
if ( ( V_32 != V_53 ) && ( V_32 != V_104 ) )
goto V_120;
if ( ! F_36 ( V_121 ) )
goto V_120;
F_37 ( V_3 -> V_18 -> V_122 , V_113 ) ;
V_3 -> V_4 = V_4 ;
F_38 ( V_3 -> V_18 -> V_122 , V_113 ) ;
return 0 ;
V_120:
F_4 ( V_4 ) ;
F_8 ( V_115 , V_3 , L_18 , V_44 ) ;
return - V_123 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_113 ;
F_37 ( V_3 -> V_18 -> V_122 , V_113 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_38 ( V_3 -> V_18 -> V_122 , V_113 ) ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_6 -> V_8 && V_6 -> V_9 != V_6 -> V_8 )
F_4 ( V_6 -> V_8 ) ;
F_4 ( V_4 ) ;
F_40 ( V_121 ) ;
F_8 ( V_124 , V_3 , L_19 , V_44 ) ;
}
static int T_2 F_41 ( void )
{
int V_125 ;
V_125 = F_42 ( & V_118 ) ;
if ( V_125 != 0 )
F_43 ( V_115 L_20 ,
V_44 ) ;
return V_125 ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_118 ) ;
}
