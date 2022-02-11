static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
(struct V_2 * ) V_1 -> V_4 ;
unsigned char * V_5 = V_3 -> V_6 ;
int V_7 ;
switch ( V_1 -> V_8 ) {
case 0 :
break;
case - V_9 :
case - V_10 :
case - V_11 :
F_2 ( L_1 , V_12 ,
V_1 -> V_8 ) ;
return;
default:
F_2 ( L_2 , V_12 ,
V_1 -> V_8 ) ;
goto V_13;
}
F_2 ( L_3 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
V_3 -> V_14 = V_5 [ 0 ] ;
V_3 -> V_15 = V_5 [ 1 ] ;
V_3 -> V_16 = V_5 [ 2 ] ;
F_3 ( & V_3 -> V_17 , 1 ) ;
V_13:
V_7 = F_4 ( V_1 , V_18 ) ;
if ( V_7 )
F_5 ( L_4 ,
V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned char V_19 , unsigned char * V_20 , unsigned char * V_21 )
{
int V_22 , V_23 ;
unsigned char * V_24 ;
if ( ( ! V_3 ) || ( ! V_3 -> V_25 ) )
return - 1 ;
V_24 = F_7 ( 6 , V_26 ) ;
if ( V_24 == NULL )
return 0 ;
V_24 [ 0 ] = V_19 ;
V_24 [ 1 ] = * V_20 ;
V_24 [ 2 ] = * V_21 ;
V_24 [ 3 ] = V_24 [ 4 ] = V_24 [ 5 ] = 0 ;
F_2 ( L_5 ,
V_24 [ 0 ] , V_24 [ 1 ] , V_24 [ 2 ] ) ;
F_3 ( & V_3 -> V_17 , 0 ) ;
if ( F_8 ( V_3 -> V_27 , F_9 ( V_3 -> V_27 , 0 ) ,
V_28 , V_29 ,
0x0200 , V_3 -> V_30 , V_24 , 6 ,
V_31 ) != 6 ) {
F_2 ( L_6
L_7 , V_19 , * V_20 , * V_21 ) ;
}
V_22 = 0 ;
for ( V_23 = 0 ; ( V_23 < V_31 ) && ( ! V_22 ) ;
V_23 ++ ) {
F_10 ( 1 ) ;
if ( F_11 ( & V_3 -> V_17 ) )
V_22 = 1 ;
}
if ( ( V_22 ) && ( V_19 == V_3 -> V_14 ) ) {
* V_20 = V_3 -> V_15 ;
* V_21 = V_3 -> V_16 ;
}
F_12 ( V_24 ) ;
return V_22 ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned char V_20 = 0x00 ;
unsigned char V_21 = 0x00 ;
int V_7 ;
V_7 = F_6 ( V_3 , V_32 ,
& V_20 , & V_21 ) ;
if ( ( V_7 == 0 ) || ( V_21 == 0 ) ) {
F_5 ( L_8 ) ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned char V_20 = 0xA5 ;
unsigned char V_21 = 0xC3 ;
int V_7 ;
V_7 = F_6 ( V_3 , V_33 ,
& V_20 , & V_21 ) ;
if ( ( V_7 == 0 ) || ( V_21 != 0 ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
unsigned char V_34 ;
F_6 ( V_3 , V_35 , & V_34 , & V_34 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , int V_36 )
{
unsigned char V_20 = V_36 / 256 ;
unsigned char V_21 = V_36 % 256 ;
if ( ( V_36 < 0x0001 ) || ( V_36 > 0xFFFF ) )
return - V_37 ;
F_6 ( V_3 , V_38 , & V_20 , & V_21 ) ;
V_39 = V_36 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
int * V_40 )
{
unsigned char V_20 , V_21 ;
F_6 ( V_3 , V_41 , & V_20 , & V_21 ) ;
* V_40 = ( V_21 * 9 / 5 ) + 32 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
int * V_42 )
{
unsigned char V_20 , V_21 ;
F_6 ( V_3 , V_43 , & V_20 , & V_21 ) ;
* V_42 = ( V_20 << 8 ) + V_21 ;
return 0 ;
}
static T_1 F_19 ( struct V_44 * V_44 , const char T_2 * V_5 ,
T_3 V_45 , T_4 * V_46 )
{
if ( V_45 ) {
if ( ! V_47 ) {
T_3 V_48 ;
V_49 = 0 ;
for ( V_48 = 0 ; V_48 != V_45 ; V_48 ++ ) {
char V_50 ;
if ( F_20 ( V_50 , V_5 + V_48 ) )
return - V_51 ;
if ( V_50 == 'V' )
V_49 = 42 ;
}
}
F_15 ( V_52 ) ;
}
return V_45 ;
}
static long F_21 ( struct V_44 * V_44 , unsigned int V_19 ,
unsigned long V_53 )
{
void T_2 * V_54 = ( void T_2 * ) V_53 ;
int T_2 * V_55 = V_54 ;
static const struct V_56 V_57 = {
. V_58 = V_59 |
V_60 |
V_61 ,
. V_62 = 1 ,
. V_63 = V_64 ,
} ;
switch ( V_19 ) {
case V_65 :
return F_22 ( V_54 , & V_57 , sizeof( V_57 ) ) ? - V_51 : 0 ;
case V_66 :
case V_67 :
return F_23 ( 0 , V_55 ) ;
case V_68 :
{
int V_40 ;
if ( F_17 ( V_52 , & V_40 ) )
return - V_51 ;
return F_23 ( V_40 , V_55 ) ;
}
case V_69 :
{
int V_70 , V_7 = - V_37 ;
if ( F_20 ( V_70 , V_55 ) )
return - V_51 ;
if ( V_70 & V_71 ) {
F_14 ( V_52 ) ;
V_7 = 0 ;
}
if ( V_70 & V_72 ) {
F_13 ( V_52 ) ;
V_7 = 0 ;
}
return V_7 ;
}
case V_73 :
F_15 ( V_52 ) ;
return 0 ;
case V_74 :
{
int V_75 ;
if ( F_20 ( V_75 , V_55 ) )
return - V_51 ;
if ( F_16 ( V_52 , V_75 ) )
return - V_37 ;
F_15 ( V_52 ) ;
}
case V_76 :
return F_23 ( V_39 , V_55 ) ;
case V_77 :
{
int V_42 ;
if ( F_18 ( V_52 , & V_42 ) )
return - V_51 ;
return F_23 ( V_42 , V_55 ) ;
}
default:
return - V_78 ;
}
}
static int F_24 ( struct V_79 * V_79 , struct V_44 * V_44 )
{
if ( F_25 ( 0 , & V_80 ) )
return - V_81 ;
F_13 ( V_52 ) ;
F_15 ( V_52 ) ;
return F_26 ( V_79 , V_44 ) ;
}
static int F_27 ( struct V_79 * V_79 , struct V_44 * V_44 )
{
if ( V_49 == 42 ) {
F_14 ( V_52 ) ;
} else {
F_28 ( L_10 ) ;
F_15 ( V_52 ) ;
}
V_49 = 0 ;
F_29 ( 0 , & V_80 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_44 * V_44 , char T_2 * V_5 ,
T_3 V_45 , T_4 * V_46 )
{
int V_40 ;
if ( F_17 ( V_52 , & V_40 ) )
return - V_51 ;
if ( F_22 ( V_5 , & V_40 , 1 ) )
return - V_51 ;
return 1 ;
}
static int F_31 ( struct V_79 * V_79 , struct V_44 * V_44 )
{
return F_26 ( V_79 , V_44 ) ;
}
static int F_32 ( struct V_79 * V_79 , struct V_44 * V_44 )
{
return 0 ;
}
static int F_33 ( struct V_82 * V_83 , unsigned long V_84 ,
void * V_85 )
{
if ( V_84 == V_86 || V_84 == V_87 )
F_14 ( V_52 ) ;
return V_88 ;
}
static inline void F_34 ( struct V_2 * V_3 )
{
F_35 ( V_3 -> V_89 ) ;
if ( V_3 -> V_6 != NULL )
F_36 ( V_3 -> V_27 , V_3 -> V_90 ,
V_3 -> V_6 , V_3 -> V_91 ) ;
F_12 ( V_3 ) ;
}
static int F_37 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
struct V_96 * V_27 = F_38 ( V_93 ) ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_2 * V_3 = NULL ;
int V_101 , V_102 ;
int V_7 = - V_103 ;
int V_104 ;
unsigned char V_105 , V_106 ;
char V_107 [ 20 ] ;
unsigned char V_108 , V_34 ;
V_109 ++ ;
if ( V_109 > 1 ) {
F_5 ( L_11 ) ;
return - V_110 ;
}
V_98 = V_93 -> V_111 ;
if ( ! ( V_98 -> V_112 . V_113 == V_114 ) ) {
F_5 ( L_12 ) ;
return - V_110 ;
}
V_100 = & V_98 -> V_100 [ 0 ] . V_112 ;
if ( ! F_39 ( V_100 ) ) {
F_5 ( L_13 ) ;
return - V_110 ;
}
V_101 = F_40 ( V_27 , V_100 -> V_115 ) ;
V_102 = F_41 ( V_27 , V_101 , F_42 ( V_101 ) ) ;
V_3 = F_43 ( sizeof( struct V_2 ) , V_26 ) ;
if ( V_3 == NULL ) {
F_5 ( L_14 ) ;
goto error;
}
V_52 = V_3 ;
F_44 ( & V_3 -> V_116 ) ;
V_3 -> V_27 = V_27 ;
V_3 -> V_93 = V_93 ;
V_3 -> V_30 = V_98 -> V_112 . V_117 ;
V_3 -> V_90 = ( F_45 ( V_100 -> V_118 ) > 8 ?
F_45 ( V_100 -> V_118 ) : 8 ) ;
V_3 -> V_6 = F_46 ( V_27 , V_3 -> V_90 ,
V_18 , & V_3 -> V_91 ) ;
if ( ! V_3 -> V_6 ) {
F_5 ( L_14 ) ;
goto error;
}
V_3 -> V_89 = F_47 ( 0 , V_26 ) ;
if ( ! V_3 -> V_89 ) {
F_5 ( L_14 ) ;
goto error;
}
F_48 ( V_3 -> V_89 , V_27 , V_101 ,
V_3 -> V_6 , V_3 -> V_90 ,
F_1 , V_3 , V_100 -> V_119 ) ;
V_3 -> V_89 -> V_120 = V_3 -> V_91 ;
V_3 -> V_89 -> V_121 |= V_122 ;
if ( F_4 ( V_3 -> V_89 , V_26 ) ) {
F_5 ( L_15 ) ;
V_7 = - V_123 ;
goto error;
}
V_3 -> V_25 = 1 ;
F_14 ( V_3 ) ;
V_104 = F_6 ( V_3 , V_124 ,
& V_105 , & V_106 ) ;
if ( V_104 )
sprintf ( V_107 , L_16 , V_105 , V_106 ) ;
else
sprintf ( V_107 , L_17 ) ;
F_49 ( L_18 , V_107 ) ;
F_6 ( V_3 , V_125 , & V_34 ,
& V_108 ) ;
F_49 ( L_19 ,
V_108 ,
( ( V_108 & 0x10 ) ? L_20 : L_21 ) ,
( ( V_108 & 0x08 ) ? L_20 : L_21 ) ) ;
if ( V_39 == 0 )
V_39 = V_126 [ ( V_108 & 0x07 ) ] ;
if ( F_16 ( V_3 , V_39 ) ) {
F_16 ( V_3 , V_127 ) ;
F_49 ( L_22 ,
V_127 ) ;
}
V_7 = F_50 ( & V_128 ) ;
if ( V_7 != 0 ) {
F_5 ( L_23 , V_7 ) ;
goto error;
}
V_7 = F_51 ( & V_129 ) ;
if ( V_7 != 0 ) {
F_5 ( L_24 ,
V_130 , V_7 ) ;
goto V_131;
}
V_7 = F_51 ( & V_132 ) ;
if ( V_7 != 0 ) {
F_5 ( L_24 ,
V_133 , V_7 ) ;
goto V_134;
}
F_52 ( V_93 , V_3 ) ;
F_49 ( L_25 ,
V_39 , V_47 ) ;
return 0 ;
V_134:
F_53 ( & V_129 ) ;
V_131:
F_54 ( & V_128 ) ;
error:
if ( V_3 )
F_34 ( V_3 ) ;
V_52 = NULL ;
return V_7 ;
}
static void F_55 ( struct V_92 * V_93 )
{
struct V_2 * V_3 ;
F_56 ( & V_135 ) ;
V_3 = F_57 ( V_93 ) ;
F_52 ( V_93 , NULL ) ;
F_56 ( & V_3 -> V_116 ) ;
if ( ! V_47 )
F_14 ( V_3 ) ;
V_3 -> V_25 = 0 ;
F_53 ( & V_132 ) ;
F_53 ( & V_129 ) ;
F_54 ( & V_128 ) ;
F_58 ( & V_3 -> V_116 ) ;
F_34 ( V_3 ) ;
V_109 -- ;
F_58 ( & V_135 ) ;
F_49 ( L_26 ) ;
}
