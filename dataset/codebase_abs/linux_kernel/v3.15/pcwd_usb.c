static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
(struct V_2 * ) V_1 -> V_4 ;
unsigned char * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = & V_3 -> V_9 -> V_8 ;
int V_10 ;
switch ( V_1 -> V_11 ) {
case 0 :
break;
case - V_12 :
case - V_13 :
case - V_14 :
F_2 ( V_8 , L_1 ,
V_15 , V_1 -> V_11 ) ;
return;
default:
F_2 ( V_8 , L_2 ,
V_15 , V_1 -> V_11 ) ;
goto V_16;
}
F_2 ( V_8 , L_3 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
V_3 -> V_17 = V_5 [ 0 ] ;
V_3 -> V_18 = V_5 [ 1 ] ;
V_3 -> V_19 = V_5 [ 2 ] ;
F_3 ( & V_3 -> V_20 , 1 ) ;
V_16:
V_10 = F_4 ( V_1 , V_21 ) ;
if ( V_10 )
F_5 ( L_4 ,
V_10 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned char V_22 , unsigned char * V_23 , unsigned char * V_24 )
{
int V_25 , V_26 ;
unsigned char * V_27 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_28 ) )
return - 1 ;
V_27 = F_7 ( 6 , V_29 ) ;
if ( V_27 == NULL )
return 0 ;
V_27 [ 0 ] = V_22 ;
V_27 [ 1 ] = * V_23 ;
V_27 [ 2 ] = * V_24 ;
V_27 [ 3 ] = V_27 [ 4 ] = V_27 [ 5 ] = 0 ;
F_2 ( & V_3 -> V_9 -> V_8 ,
L_5 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ) ;
F_3 ( & V_3 -> V_20 , 0 ) ;
if ( F_8 ( V_3 -> V_30 , F_9 ( V_3 -> V_30 , 0 ) ,
V_31 , V_32 ,
0x0200 , V_3 -> V_33 , V_27 , 6 ,
V_34 ) != 6 ) {
F_2 ( & V_3 -> V_9 -> V_8 ,
L_6 ,
V_22 , * V_23 , * V_24 ) ;
}
V_25 = 0 ;
for ( V_26 = 0 ; ( V_26 < V_34 ) && ( ! V_25 ) ;
V_26 ++ ) {
F_10 ( 1 ) ;
if ( F_11 ( & V_3 -> V_20 ) )
V_25 = 1 ;
}
if ( ( V_25 ) && ( V_22 == V_3 -> V_17 ) ) {
* V_23 = V_3 -> V_18 ;
* V_24 = V_3 -> V_19 ;
}
F_12 ( V_27 ) ;
return V_25 ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned char V_23 = 0x00 ;
unsigned char V_24 = 0x00 ;
int V_10 ;
V_10 = F_6 ( V_3 , V_35 ,
& V_23 , & V_24 ) ;
if ( ( V_10 == 0 ) || ( V_24 == 0 ) ) {
F_5 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned char V_23 = 0xA5 ;
unsigned char V_24 = 0xC3 ;
int V_10 ;
V_10 = F_6 ( V_3 , V_36 ,
& V_23 , & V_24 ) ;
if ( ( V_10 == 0 ) || ( V_24 != 0 ) ) {
F_5 ( L_8 ) ;
return - 1 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
unsigned char V_37 ;
F_6 ( V_3 , V_38 , & V_37 , & V_37 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , int V_39 )
{
unsigned char V_23 = V_39 / 256 ;
unsigned char V_24 = V_39 % 256 ;
if ( ( V_39 < 0x0001 ) || ( V_39 > 0xFFFF ) )
return - V_40 ;
F_6 ( V_3 , V_41 , & V_23 , & V_24 ) ;
V_42 = V_39 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
int * V_43 )
{
unsigned char V_23 , V_24 ;
F_6 ( V_3 , V_44 , & V_23 , & V_24 ) ;
* V_43 = ( V_24 * 9 / 5 ) + 32 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
int * V_45 )
{
unsigned char V_23 , V_24 ;
F_6 ( V_3 , V_46 , & V_23 , & V_24 ) ;
* V_45 = ( V_23 << 8 ) + V_24 ;
return 0 ;
}
static T_1 F_19 ( struct V_47 * V_47 , const char T_2 * V_5 ,
T_3 V_48 , T_4 * V_49 )
{
if ( V_48 ) {
if ( ! V_50 ) {
T_3 V_51 ;
V_52 = 0 ;
for ( V_51 = 0 ; V_51 != V_48 ; V_51 ++ ) {
char V_53 ;
if ( F_20 ( V_53 , V_5 + V_51 ) )
return - V_54 ;
if ( V_53 == 'V' )
V_52 = 42 ;
}
}
F_15 ( V_55 ) ;
}
return V_48 ;
}
static long F_21 ( struct V_47 * V_47 , unsigned int V_22 ,
unsigned long V_56 )
{
void T_2 * V_57 = ( void T_2 * ) V_56 ;
int T_2 * V_58 = V_57 ;
static const struct V_59 V_60 = {
. V_61 = V_62 |
V_63 |
V_64 ,
. V_65 = 1 ,
. V_66 = V_67 ,
} ;
switch ( V_22 ) {
case V_68 :
return F_22 ( V_57 , & V_60 , sizeof( V_60 ) ) ? - V_54 : 0 ;
case V_69 :
case V_70 :
return F_23 ( 0 , V_58 ) ;
case V_71 :
{
int V_43 ;
if ( F_17 ( V_55 , & V_43 ) )
return - V_54 ;
return F_23 ( V_43 , V_58 ) ;
}
case V_72 :
{
int V_73 , V_10 = - V_40 ;
if ( F_20 ( V_73 , V_58 ) )
return - V_54 ;
if ( V_73 & V_74 ) {
F_14 ( V_55 ) ;
V_10 = 0 ;
}
if ( V_73 & V_75 ) {
F_13 ( V_55 ) ;
V_10 = 0 ;
}
return V_10 ;
}
case V_76 :
F_15 ( V_55 ) ;
return 0 ;
case V_77 :
{
int V_78 ;
if ( F_20 ( V_78 , V_58 ) )
return - V_54 ;
if ( F_16 ( V_55 , V_78 ) )
return - V_40 ;
F_15 ( V_55 ) ;
}
case V_79 :
return F_23 ( V_42 , V_58 ) ;
case V_80 :
{
int V_45 ;
if ( F_18 ( V_55 , & V_45 ) )
return - V_54 ;
return F_23 ( V_45 , V_58 ) ;
}
default:
return - V_81 ;
}
}
static int F_24 ( struct V_82 * V_82 , struct V_47 * V_47 )
{
if ( F_25 ( 0 , & V_83 ) )
return - V_84 ;
F_13 ( V_55 ) ;
F_15 ( V_55 ) ;
return F_26 ( V_82 , V_47 ) ;
}
static int F_27 ( struct V_82 * V_82 , struct V_47 * V_47 )
{
if ( V_52 == 42 ) {
F_14 ( V_55 ) ;
} else {
F_28 ( L_9 ) ;
F_15 ( V_55 ) ;
}
V_52 = 0 ;
F_29 ( 0 , & V_83 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_47 * V_47 , char T_2 * V_5 ,
T_3 V_48 , T_4 * V_49 )
{
int V_43 ;
if ( F_17 ( V_55 , & V_43 ) )
return - V_54 ;
if ( F_22 ( V_5 , & V_43 , 1 ) )
return - V_54 ;
return 1 ;
}
static int F_31 ( struct V_82 * V_82 , struct V_47 * V_47 )
{
return F_26 ( V_82 , V_47 ) ;
}
static int F_32 ( struct V_82 * V_82 , struct V_47 * V_47 )
{
return 0 ;
}
static int F_33 ( struct V_85 * V_86 , unsigned long V_87 ,
void * V_88 )
{
if ( V_87 == V_89 || V_87 == V_90 )
F_14 ( V_55 ) ;
return V_91 ;
}
static inline void F_34 ( struct V_2 * V_3 )
{
F_35 ( V_3 -> V_92 ) ;
if ( V_3 -> V_6 != NULL )
F_36 ( V_3 -> V_30 , V_3 -> V_93 ,
V_3 -> V_6 , V_3 -> V_94 ) ;
F_12 ( V_3 ) ;
}
static int F_37 ( struct V_95 * V_9 ,
const struct V_96 * V_97 )
{
struct V_98 * V_30 = F_38 ( V_9 ) ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_2 * V_3 = NULL ;
int V_103 , V_104 ;
int V_10 = - V_105 ;
int V_106 ;
unsigned char V_107 , V_108 ;
char V_109 [ 20 ] ;
unsigned char V_110 , V_37 ;
V_111 ++ ;
if ( V_111 > 1 ) {
F_5 ( L_10 ) ;
return - V_112 ;
}
V_100 = V_9 -> V_113 ;
if ( ! ( V_100 -> V_114 . V_115 == V_116 ) ) {
F_5 ( L_11 ) ;
return - V_112 ;
}
V_102 = & V_100 -> V_102 [ 0 ] . V_114 ;
if ( ! F_39 ( V_102 ) ) {
F_5 ( L_12 ) ;
return - V_112 ;
}
V_103 = F_40 ( V_30 , V_102 -> V_117 ) ;
V_104 = F_41 ( V_30 , V_103 , F_42 ( V_103 ) ) ;
V_3 = F_43 ( sizeof( struct V_2 ) , V_29 ) ;
if ( V_3 == NULL )
goto error;
V_55 = V_3 ;
F_44 ( & V_3 -> V_118 ) ;
V_3 -> V_30 = V_30 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_33 = V_100 -> V_114 . V_119 ;
V_3 -> V_93 = ( F_45 ( V_102 -> V_120 ) > 8 ?
F_45 ( V_102 -> V_120 ) : 8 ) ;
V_3 -> V_6 = F_46 ( V_30 , V_3 -> V_93 ,
V_21 , & V_3 -> V_94 ) ;
if ( ! V_3 -> V_6 ) {
F_5 ( L_13 ) ;
goto error;
}
V_3 -> V_92 = F_47 ( 0 , V_29 ) ;
if ( ! V_3 -> V_92 ) {
F_5 ( L_13 ) ;
goto error;
}
F_48 ( V_3 -> V_92 , V_30 , V_103 ,
V_3 -> V_6 , V_3 -> V_93 ,
F_1 , V_3 , V_102 -> V_121 ) ;
V_3 -> V_92 -> V_122 = V_3 -> V_94 ;
V_3 -> V_92 -> V_123 |= V_124 ;
if ( F_4 ( V_3 -> V_92 , V_29 ) ) {
F_5 ( L_14 ) ;
V_10 = - V_125 ;
goto error;
}
V_3 -> V_28 = 1 ;
F_14 ( V_3 ) ;
V_106 = F_6 ( V_3 , V_126 ,
& V_107 , & V_108 ) ;
if ( V_106 )
sprintf ( V_109 , L_15 , V_107 , V_108 ) ;
else
sprintf ( V_109 , L_16 ) ;
F_49 ( L_17 , V_109 ) ;
F_6 ( V_3 , V_127 , & V_37 ,
& V_110 ) ;
F_49 ( L_18 ,
V_110 ,
( ( V_110 & 0x10 ) ? L_19 : L_20 ) ,
( ( V_110 & 0x08 ) ? L_19 : L_20 ) ) ;
if ( V_42 == 0 )
V_42 = V_128 [ ( V_110 & 0x07 ) ] ;
if ( F_16 ( V_3 , V_42 ) ) {
F_16 ( V_3 , V_129 ) ;
F_49 ( L_21 ,
V_129 ) ;
}
V_10 = F_50 ( & V_130 ) ;
if ( V_10 != 0 ) {
F_5 ( L_22 , V_10 ) ;
goto error;
}
V_10 = F_51 ( & V_131 ) ;
if ( V_10 != 0 ) {
F_5 ( L_23 ,
V_132 , V_10 ) ;
goto V_133;
}
V_10 = F_51 ( & V_134 ) ;
if ( V_10 != 0 ) {
F_5 ( L_23 ,
V_135 , V_10 ) ;
goto V_136;
}
F_52 ( V_9 , V_3 ) ;
F_49 ( L_24 ,
V_42 , V_50 ) ;
return 0 ;
V_136:
F_53 ( & V_131 ) ;
V_133:
F_54 ( & V_130 ) ;
error:
if ( V_3 )
F_34 ( V_3 ) ;
V_55 = NULL ;
return V_10 ;
}
static void F_55 ( struct V_95 * V_9 )
{
struct V_2 * V_3 ;
F_56 ( & V_137 ) ;
V_3 = F_57 ( V_9 ) ;
F_52 ( V_9 , NULL ) ;
F_56 ( & V_3 -> V_118 ) ;
if ( ! V_50 )
F_14 ( V_3 ) ;
V_3 -> V_28 = 0 ;
F_53 ( & V_134 ) ;
F_53 ( & V_131 ) ;
F_54 ( & V_130 ) ;
F_58 ( & V_3 -> V_118 ) ;
F_34 ( V_3 ) ;
V_111 -- ;
F_58 ( & V_137 ) ;
F_49 ( L_25 ) ;
}
