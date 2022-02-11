static inline T_1 F_1 ( enum V_1 V_2 )
{
static const T_1 V_3 [] = {
0x00 ,
0x00 ,
0x01 ,
0x02 ,
0x02 ,
0x03 ,
0x04 ,
0x05 ,
0x06 ,
0x07 ,
0x00 ,
0x01 ,
0x00 ,
0x01 ,
0x02 ,
0x0a ,
0x01 ,
0x02 ,
0x04 ,
0x08 ,
} ;
return V_3 [ V_2 ] ;
}
static inline T_1 F_2 ( enum V_1 V_2 ,
unsigned int V_4 )
{
if ( V_2 >= V_5 )
return 0x0000 ;
else if ( V_2 >= V_6 )
return 0x0100 ;
else
return ( V_4 + 2 ) << 8 ;
}
static int F_3 ( struct V_7 * V_8 , unsigned int V_4 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_13 = F_4 ( V_11 , 0 ) ;
T_2 V_14 = ( T_2 ) 0x0e ;
T_2 V_15 = ( T_2 ) 0x40 ;
T_1 V_16 = F_1 ( V_2 ) ;
T_1 V_17 = F_2 ( V_2 , V_4 ) + V_9 ;
int V_18 = F_5 ( V_11 , V_13 , V_14 , V_15 , V_17 ,
V_16 , NULL , 0 , V_19 ) ;
if ( V_18 < 0 )
F_6 ( & V_11 -> V_12 ,
L_1 , V_18 ) ;
return V_18 ;
}
static int F_7 ( struct V_7 * V_8 , unsigned int V_4 ,
enum V_1 V_2 , T_2 * V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_13 = F_8 ( V_11 , 0 ) ;
T_2 V_14 = ( T_2 ) 0x0d ;
T_2 V_15 = ( T_2 ) 0xc0 ;
T_1 V_16 = F_1 ( V_2 ) ;
T_1 V_17 = F_2 ( V_2 , V_4 ) ;
int V_18 = F_5 ( V_11 , V_13 , V_14 , V_15 , V_17 ,
V_16 , V_9 , 1 , V_19 ) ;
if ( V_18 < 0 )
F_6 ( & V_11 -> V_12 ,
L_1 , V_18 ) ;
return V_18 ;
}
static inline int F_9 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
V_21 -> V_24 = V_23 ;
F_3 ( V_21 -> V_8 , V_25 , V_26 , V_21 -> V_24 ) ;
return 0 ;
}
static void F_10 ( struct V_27 * V_27 )
{
struct V_20 * V_21 =
F_11 ( V_27 , struct V_20 , V_28 ) ;
F_12 ( V_21 ) ;
}
static void F_13 ( struct V_27 * V_27 )
{
struct V_29 * V_30 =
F_11 ( V_27 , struct V_29 , V_28 ) ;
struct V_20 * V_21 = V_30 -> V_21 ;
F_14 ( V_30 -> V_31 ) ;
F_12 ( V_30 ) ;
F_15 ( & V_21 -> V_28 , F_10 ) ;
}
static void F_16 ( unsigned long V_32 )
{
int V_33 ;
unsigned long V_34 ;
struct V_20 * V_21 = ( void * ) V_32 ;
struct V_29 * V_30 , * V_35 ;
struct V_36 * V_37 , * V_38 ;
struct V_39 * V_12 ;
if ( F_17 ( V_21 -> V_8 == NULL ) )
return;
V_12 = & V_21 -> V_8 -> V_12 -> V_12 ;
if ( ! F_18 ( & V_21 -> V_8 -> V_40 ) ) {
F_19 ( V_12 , L_2 , V_41 ) ;
F_20 ( & V_21 -> V_42 ) ;
return;
}
if ( F_17 ( V_21 -> V_8 -> V_43 ) ) {
F_21 ( & V_21 -> V_8 -> V_40 ) ;
return;
}
F_22 ( & V_21 -> V_44 , V_34 ) ;
if ( F_23 ( & V_21 -> V_45 ) ) {
F_24 ( & V_21 -> V_44 , V_34 ) ;
F_21 ( & V_21 -> V_8 -> V_40 ) ;
F_19 ( V_12 , L_3 , V_41 ) ;
return;
}
F_25 (cursor, next, &mos_parport->deferred_urbs)
F_26 ( V_37 , & V_21 -> V_46 ) ;
F_27 (urbtrack, tmp, &mos_parport->active_urbs,
urblist_entry) {
V_33 = F_28 ( V_30 -> V_31 , V_47 ) ;
F_19 ( V_12 , L_4 , V_41 ) ;
if ( V_33 ) {
F_6 ( V_12 , L_5 , V_33 ) ;
F_29 ( & V_30 -> V_48 ) ;
F_15 ( & V_30 -> V_28 , F_13 ) ;
}
}
F_24 ( & V_21 -> V_44 , V_34 ) ;
F_21 ( & V_21 -> V_8 -> V_40 ) ;
}
static void F_30 ( struct V_31 * V_31 )
{
struct V_29 * V_30 = V_31 -> V_49 ;
int V_18 = V_31 -> V_18 ;
if ( F_17 ( V_18 ) )
F_19 ( & V_31 -> V_12 -> V_12 , L_6 , V_41 , V_18 ) ;
F_31 ( & V_30 -> V_21 -> V_44 ) ;
F_29 ( & V_30 -> V_48 ) ;
F_32 ( & V_30 -> V_21 -> V_44 ) ;
F_15 ( & V_30 -> V_28 , F_13 ) ;
}
static int F_33 ( struct V_20 * V_21 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_29 * V_30 ;
int V_33 ;
unsigned long V_34 ;
struct V_50 V_51 ;
struct V_7 * V_8 = V_21 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
V_30 = F_34 ( sizeof( struct V_29 ) , V_47 ) ;
if ( V_30 == NULL ) {
F_6 ( & V_11 -> V_12 , L_7 ) ;
return - V_52 ;
}
F_35 ( & V_21 -> V_28 ) ;
V_30 -> V_21 = V_21 ;
V_30 -> V_31 = F_36 ( 0 , V_47 ) ;
if ( V_30 -> V_31 == NULL ) {
F_6 ( & V_11 -> V_12 , L_8 ) ;
F_12 ( V_30 ) ;
return - V_52 ;
}
V_51 . V_53 = ( T_2 ) 0x40 ;
V_51 . V_54 = ( T_2 ) 0x0e ;
V_51 . V_55 = F_2 ( V_2 , V_25 ) ;
V_51 . V_56 = F_1 ( V_2 ) ;
V_51 . V_57 = 0 ;
F_37 ( V_30 -> V_31 , V_11 ,
F_4 ( V_11 , 0 ) ,
( unsigned char * ) & V_51 ,
NULL , 0 , F_30 , V_30 ) ;
F_38 ( & V_30 -> V_28 ) ;
F_39 ( & V_30 -> V_48 ) ;
if ( ! F_18 ( & V_8 -> V_40 ) ) {
F_22 ( & V_21 -> V_44 , V_34 ) ;
F_40 ( & V_30 -> V_48 ,
& V_21 -> V_45 ) ;
F_24 ( & V_21 -> V_44 , V_34 ) ;
F_20 ( & V_21 -> V_42 ) ;
F_19 ( & V_11 -> V_12 , L_9 ) ;
return 0 ;
}
if ( V_8 -> V_43 ) {
F_15 ( & V_30 -> V_28 , F_13 ) ;
F_21 ( & V_8 -> V_40 ) ;
return - V_58 ;
}
F_22 ( & V_21 -> V_44 , V_34 ) ;
F_40 ( & V_30 -> V_48 , & V_21 -> V_46 ) ;
F_24 ( & V_21 -> V_44 , V_34 ) ;
V_33 = F_28 ( V_30 -> V_31 , V_47 ) ;
F_21 ( & V_8 -> V_40 ) ;
if ( V_33 ) {
F_6 ( & V_11 -> V_12 ,
L_10 , V_41 , V_33 ) ;
F_22 ( & V_21 -> V_44 , V_34 ) ;
F_29 ( & V_30 -> V_48 ) ;
F_24 ( & V_21 -> V_44 , V_34 ) ;
F_15 ( & V_30 -> V_28 , F_13 ) ;
return V_33 ;
}
return 0 ;
}
static int F_41 ( struct V_59 * V_60 )
{
struct V_20 * V_21 ;
F_31 ( & V_61 ) ;
V_21 = V_60 -> V_62 ;
if ( F_17 ( V_21 == NULL ) ) {
F_32 ( & V_61 ) ;
return - 1 ;
}
V_21 -> V_63 = true ;
F_42 ( V_21 -> V_64 ) ;
F_32 ( & V_61 ) ;
F_43 ( & V_21 -> V_8 -> V_40 ) ;
if ( V_21 -> V_8 -> V_43 ) {
F_21 ( & V_21 -> V_8 -> V_40 ) ;
V_21 -> V_63 = false ;
F_44 ( & V_21 -> V_64 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_45 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
F_21 ( & V_21 -> V_8 -> V_40 ) ;
V_21 -> V_63 = false ;
F_44 ( & V_21 -> V_64 ) ;
}
static void F_46 ( struct V_59 * V_60 , unsigned char V_65 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
if ( F_41 ( V_60 ) < 0 )
return;
F_9 ( V_21 , V_66 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_6 , ( T_2 ) V_65 ) ;
F_45 ( V_60 ) ;
}
static unsigned char F_47 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
unsigned char V_65 ;
if ( F_41 ( V_60 ) < 0 )
return 0 ;
F_7 ( V_21 -> V_8 , V_25 , V_6 , & V_65 ) ;
F_45 ( V_60 ) ;
return V_65 ;
}
static void F_48 ( struct V_59 * V_60 , unsigned char V_65 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
T_2 V_9 ;
if ( F_41 ( V_60 ) < 0 )
return;
V_9 = ( ( T_2 ) V_65 & 0x0f ) | ( V_21 -> V_67 & 0xf0 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_68 , V_9 ) ;
V_21 -> V_67 = V_9 ;
F_45 ( V_60 ) ;
}
static unsigned char F_49 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
T_2 V_69 ;
F_31 ( & V_61 ) ;
V_21 = V_60 -> V_62 ;
if ( F_17 ( V_21 == NULL ) ) {
F_32 ( & V_61 ) ;
return 0 ;
}
V_69 = V_21 -> V_67 & 0x0f ;
F_32 ( & V_61 ) ;
return V_69 ;
}
static unsigned char F_50 ( struct V_59 * V_60 ,
unsigned char V_70 ,
unsigned char V_71 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
T_2 V_69 ;
V_70 &= 0x0f ;
V_71 &= 0x0f ;
if ( F_41 ( V_60 ) < 0 )
return 0 ;
V_21 -> V_67 = ( V_21 -> V_67 & ( ~ V_70 ) ) ^ V_71 ;
F_3 ( V_21 -> V_8 , V_25 , V_68 , V_21 -> V_67 ) ;
V_69 = V_21 -> V_67 & 0x0f ;
F_45 ( V_60 ) ;
return V_69 ;
}
static unsigned char F_51 ( struct V_59 * V_60 )
{
unsigned char V_18 ;
struct V_20 * V_21 = V_60 -> V_62 ;
F_31 ( & V_61 ) ;
V_21 = V_60 -> V_62 ;
if ( F_17 ( V_21 == NULL ) ) {
F_32 ( & V_61 ) ;
return 0 ;
}
V_18 = F_52 ( & V_21 -> V_72 ) & 0xf8 ;
F_32 ( & V_61 ) ;
return V_18 ;
}
static void F_53 ( struct V_59 * V_60 )
{
}
static void F_54 ( struct V_59 * V_60 )
{
}
static void F_55 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
if ( F_41 ( V_60 ) < 0 )
return;
F_9 ( V_21 , V_73 ) ;
V_21 -> V_67 &= ~ 0x20 ;
F_3 ( V_21 -> V_8 , V_25 , V_68 , V_21 -> V_67 ) ;
F_45 ( V_60 ) ;
}
static void F_56 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_62 ;
if ( F_41 ( V_60 ) < 0 )
return;
F_9 ( V_21 , V_73 ) ;
V_21 -> V_67 |= 0x20 ;
F_3 ( V_21 -> V_8 , V_25 , V_68 , V_21 -> V_67 ) ;
F_45 ( V_60 ) ;
}
static void F_57 ( struct V_74 * V_12 ,
struct V_75 * V_76 )
{
V_76 -> V_77 . V_78 . V_79 = V_80 ;
V_76 -> V_77 . V_78 . V_81 = V_82 ;
}
static void F_58 ( struct V_59 * V_60 ,
struct V_75 * V_76 )
{
struct V_20 * V_21 ;
F_31 ( & V_61 ) ;
V_21 = V_60 -> V_62 ;
if ( F_17 ( V_21 == NULL ) ) {
F_32 ( & V_61 ) ;
return;
}
V_76 -> V_77 . V_78 . V_79 = V_21 -> V_67 ;
V_76 -> V_77 . V_78 . V_81 = V_21 -> V_24 ;
F_32 ( & V_61 ) ;
}
static void F_59 ( struct V_59 * V_60 ,
struct V_75 * V_76 )
{
struct V_20 * V_21 ;
F_31 ( & V_61 ) ;
V_21 = V_60 -> V_62 ;
if ( F_17 ( V_21 == NULL ) ) {
F_32 ( & V_61 ) ;
return;
}
F_33 ( V_21 , V_68 , V_21 -> V_67 ) ;
F_33 ( V_21 , V_26 , V_21 -> V_24 ) ;
F_32 ( & V_61 ) ;
}
static T_3 F_60 ( struct V_59 * V_60 ,
const void * V_83 ,
T_3 V_84 , int V_34 )
{
int V_85 ;
struct V_20 * V_21 = V_60 -> V_62 ;
int V_86 ;
if ( F_41 ( V_60 ) < 0 )
return 0 ;
F_9 ( V_21 , V_87 ) ;
V_85 = F_61 ( V_21 -> V_8 -> V_12 ,
F_62 ( V_21 -> V_8 -> V_12 , 2 ) ,
( void * ) V_83 , V_84 , & V_86 ,
V_19 ) ;
F_45 ( V_60 ) ;
if ( V_85 ) {
F_6 ( & V_21 -> V_8 -> V_12 -> V_12 ,
L_11 , V_85 ) ;
return 0 ;
}
return V_86 ;
}
static int F_63 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
V_21 = F_64 ( sizeof( struct V_20 ) , V_88 ) ;
if ( V_21 == NULL ) {
F_19 ( & V_8 -> V_12 -> V_12 , L_12 , V_41 ) ;
return - V_52 ;
}
V_21 -> V_63 = false ;
F_38 ( & V_21 -> V_28 ) ;
F_65 ( & V_21 -> V_44 ) ;
F_39 ( & V_21 -> V_46 ) ;
F_39 ( & V_21 -> V_45 ) ;
F_66 ( V_8 , V_21 ) ;
V_21 -> V_8 = V_8 ;
F_67 ( & V_21 -> V_42 , F_16 ,
( unsigned long ) V_21 ) ;
F_68 ( & V_21 -> V_64 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_89 , ( T_2 ) 0x80 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_89 , ( T_2 ) 0x00 ) ;
V_21 -> V_67 = V_80 ;
F_3 ( V_21 -> V_8 , V_25 , V_68 , V_21 -> V_67 ) ;
V_21 -> V_24 = V_82 ;
F_3 ( V_21 -> V_8 , V_25 , V_26 , V_21 -> V_24 ) ;
V_21 -> V_60 = F_69 ( 0 , V_90 ,
V_91 ,
& V_92 ) ;
if ( V_21 -> V_60 == NULL ) {
F_6 ( & V_8 -> V_93 -> V_12 ,
L_13 ) ;
F_15 ( & V_21 -> V_28 , F_10 ) ;
return - V_94 ;
}
V_21 -> V_60 -> V_62 = V_21 ;
V_21 -> V_60 -> V_95 = V_96 | V_97 ;
V_21 -> V_60 -> V_12 = & V_8 -> V_93 -> V_12 ;
F_70 ( V_21 -> V_60 ) ;
return 0 ;
}
static void F_71 ( struct V_31 * V_31 )
{
int V_98 ;
int V_99 ;
int V_18 = V_31 -> V_18 ;
struct V_39 * V_12 = & V_31 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_100 ;
T_2 V_101 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
F_19 ( V_12 , L_14 , V_41 , V_18 ) ;
return;
default:
F_19 ( V_12 , L_6 , V_41 , V_18 ) ;
goto exit;
}
V_99 = V_31 -> V_105 ;
V_9 = V_31 -> V_106 ;
if ( F_17 ( V_99 != 4 ) ) {
F_19 ( V_12 , L_15 ) ;
return;
}
V_100 = V_9 [ 3 ] ;
V_101 = V_9 [ 2 ] ;
if ( ( V_100 | V_101 ) & 0x01 ) {
F_19 ( V_12 , L_16 ) ;
} else {
switch ( V_100 & 0x0f ) {
case V_107 :
F_19 ( V_12 , L_17 ) ;
break;
case V_108 :
F_19 ( V_12 , L_18 ) ;
break;
case V_109 :
break;
}
switch ( V_101 & 0x0f ) {
case V_107 :
F_19 ( V_12 , L_19 ) ;
break;
case V_108 :
F_19 ( V_12 , L_20 ) ;
break;
case V_109 :
break;
}
}
exit:
V_98 = F_28 ( V_31 , V_47 ) ;
if ( V_98 )
F_6 ( V_12 , L_21 , V_41 , V_98 ) ;
}
static void F_72 ( struct V_31 * V_31 )
{
int V_98 ;
int V_99 ;
int V_18 = V_31 -> V_18 ;
struct V_39 * V_12 = & V_31 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_110 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
case - V_58 :
F_19 ( V_12 , L_14 , V_41 , V_18 ) ;
return;
default:
F_19 ( V_12 , L_6 , V_41 , V_18 ) ;
goto exit;
}
V_99 = V_31 -> V_105 ;
V_9 = V_31 -> V_106 ;
if ( F_17 ( V_99 != 4 ) ) {
F_19 ( V_12 , L_15 ) ;
return;
}
V_110 = V_9 [ 0 ] ;
if ( ! ( V_110 & 0x01 ) ) {
switch ( V_110 & 0x0f ) {
case V_107 :
F_19 ( V_12 , L_22 ) ;
break;
case V_108 :
F_19 ( V_12 , L_23 ) ;
break;
case V_109 :
break;
}
}
#ifdef F_73
{
struct V_111 * V_112 = V_31 -> V_49 ;
struct V_20 * V_21 = V_112 -> V_8 -> V_113 ;
if ( F_17 ( V_21 == NULL ) )
return;
F_74 ( & V_21 -> V_72 , V_9 [ 2 ] ) ;
}
#endif
exit:
V_98 = F_28 ( V_31 , V_47 ) ;
if ( V_98 )
F_6 ( V_12 , L_21 , V_41 , V_98 ) ;
}
static void F_75 ( struct V_31 * V_31 )
{
int V_85 ;
unsigned char * V_9 ;
struct V_111 * V_112 ;
int V_18 = V_31 -> V_18 ;
if ( V_18 ) {
F_19 ( & V_31 -> V_12 -> V_12 , L_24 , V_18 ) ;
return;
}
V_112 = V_31 -> V_49 ;
F_19 ( & V_112 -> V_12 , L_25 , V_41 ) ;
V_9 = V_31 -> V_106 ;
if ( V_31 -> V_105 ) {
F_76 ( & V_112 -> V_112 , V_9 , V_31 -> V_105 ) ;
F_77 ( & V_112 -> V_112 ) ;
}
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_85 = F_28 ( V_112 -> V_114 , V_47 ) ;
if ( V_85 )
F_19 ( & V_112 -> V_12 , L_26 , V_85 ) ;
}
}
static void F_78 ( struct V_31 * V_31 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
int V_18 = V_31 -> V_18 ;
if ( V_18 ) {
F_19 ( & V_31 -> V_12 -> V_12 , L_27 , V_18 ) ;
return;
}
V_117 = V_31 -> V_49 ;
if ( ! V_117 ) {
F_19 ( & V_31 -> V_12 -> V_12 , L_28 ) ;
return ;
}
V_119 = F_79 ( & V_117 -> V_112 -> V_112 ) ;
if ( V_119 && V_117 -> V_120 )
F_80 ( V_119 ) ;
F_81 ( V_119 ) ;
}
static int F_82 ( struct V_7 * V_8 ,
const struct V_121 * V_122 )
{
if ( V_122 -> V_123 == V_124 )
V_125 . V_126 =
F_72 ;
else
V_125 . V_126 =
F_71 ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 )
{
T_4 V_127 = F_84 ( V_8 -> V_12 -> V_128 . V_123 ) ;
if ( V_127 == V_124 )
return 1 ;
return 2 ;
}
static int F_85 ( struct V_118 * V_119 , struct V_111 * V_112 )
{
struct V_7 * V_8 ;
struct V_31 * V_31 ;
struct V_116 * V_117 ;
int V_129 ;
int V_130 ;
T_2 V_9 ;
int V_131 = 0 ;
int V_132 ;
V_8 = V_112 -> V_8 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return - V_58 ;
F_87 ( V_8 -> V_12 , V_112 -> V_133 -> V_13 ) ;
F_87 ( V_8 -> V_12 , V_112 -> V_114 -> V_13 ) ;
for ( V_132 = 0 ; V_132 < V_134 ; ++ V_132 ) {
V_31 = F_36 ( 0 , V_88 ) ;
V_117 -> V_135 [ V_132 ] = V_31 ;
if ( V_31 == NULL ) {
F_6 ( & V_112 -> V_12 , L_29 ) ;
continue;
}
V_31 -> V_106 = F_34 ( V_136 ,
V_88 ) ;
if ( ! V_31 -> V_106 ) {
F_6 ( & V_112 -> V_12 ,
L_30 ,
V_41 ) ;
F_14 ( V_117 -> V_135 [ V_132 ] ) ;
V_117 -> V_135 [ V_132 ] = NULL ;
continue;
}
V_131 ++ ;
}
if ( ! V_131 )
return - V_52 ;
V_130 = V_112 -> V_137 - V_112 -> V_8 -> V_138 ;
F_7 ( V_8 , V_130 , V_139 , & V_9 ) ;
F_19 ( & V_112 -> V_12 , L_31 , V_117 , V_9 ) ;
F_3 ( V_8 , V_25 , V_5 , 0x02 ) ;
F_3 ( V_8 , V_25 , V_140 , 0x02 ) ;
F_3 ( V_8 , V_130 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0xcf ) ;
V_117 -> V_143 = 0x03 ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
V_117 -> V_145 = 0x0b ;
F_3 ( V_8 , V_130 , V_146 , V_117 -> V_145 ) ;
F_3 ( V_8 , V_130 , V_147 , 0x00 ) ;
F_7 ( V_8 , V_25 , V_147 , & V_9 ) ;
V_9 = V_9 | ( V_112 -> V_137 - V_112 -> V_8 -> V_138 + 1 ) ;
F_3 ( V_8 , V_25 , V_147 , V_9 ) ;
V_117 -> V_143 = 0x83 ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
F_3 ( V_8 , V_130 , V_148 , 0x0c ) ;
F_3 ( V_8 , V_130 , V_141 , 0x00 ) ;
V_117 -> V_143 = 0x03 ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
F_3 ( V_8 , V_130 , V_141 , 0x0c ) ;
V_129 = F_28 ( V_112 -> V_114 , V_88 ) ;
if ( V_129 )
F_6 ( & V_112 -> V_12 , L_32 ,
V_41 , V_129 ) ;
memset ( & ( V_117 -> V_149 ) , 0x00 , sizeof( V_117 -> V_149 ) ) ;
V_117 -> V_145 = V_150 ;
V_117 -> V_120 = 1 ;
return 0 ;
}
static int F_88 ( struct V_118 * V_119 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
int V_152 ;
int V_153 = 0 ;
struct V_116 * V_117 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return 0 ;
for ( V_152 = 0 ; V_152 < V_134 ; ++ V_152 ) {
if ( V_117 -> V_135 [ V_152 ] &&
V_117 -> V_135 [ V_152 ] -> V_18 == - V_115 )
V_153 += V_136 ;
}
F_19 ( & V_112 -> V_12 , L_33 , V_41 , V_153 ) ;
return V_153 ;
}
static void F_89 ( struct V_111 * V_112 )
{
struct V_7 * V_8 ;
struct V_116 * V_117 ;
int V_132 ;
V_8 = V_112 -> V_8 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return;
for ( V_132 = 0 ; V_132 < V_134 ; ++ V_132 )
F_90 ( V_117 -> V_135 [ V_132 ] ) ;
for ( V_132 = 0 ; V_132 < V_134 ; ++ V_132 ) {
if ( V_117 -> V_135 [ V_132 ] ) {
F_12 ( V_117 -> V_135 [ V_132 ] -> V_106 ) ;
F_14 ( V_117 -> V_135 [ V_132 ] ) ;
}
}
F_90 ( V_112 -> V_133 ) ;
F_90 ( V_112 -> V_114 ) ;
F_43 ( & V_8 -> V_40 ) ;
if ( ! V_8 -> V_43 ) {
F_3 ( V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_146 , 0x00 ) ;
F_3 ( V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_141 , 0x00 ) ;
}
F_21 ( & V_8 -> V_40 ) ;
V_117 -> V_120 = 0 ;
}
static void F_91 ( struct V_118 * V_119 , int V_154 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
unsigned char V_9 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
V_8 = V_112 -> V_8 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( V_154 == - 1 )
V_9 = V_117 -> V_143 | V_155 ;
else
V_9 = V_117 -> V_143 & ~ V_155 ;
V_117 -> V_143 = V_9 ;
F_3 ( V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_144 , V_117 -> V_143 ) ;
}
static int F_92 ( struct V_118 * V_119 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 ;
int V_156 = 0 ;
int V_152 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return - V_58 ;
for ( V_152 = 0 ; V_152 < V_134 ; ++ V_152 ) {
if ( V_117 -> V_135 [ V_152 ] &&
V_117 -> V_135 [ V_152 ] -> V_18 != - V_115 )
V_156 += V_136 ;
}
F_19 ( & V_112 -> V_12 , L_33 , V_41 , V_156 ) ;
return V_156 ;
}
static int F_93 ( struct V_118 * V_119 , struct V_111 * V_112 ,
const unsigned char * V_9 , int V_157 )
{
int V_18 ;
int V_152 ;
int V_158 = 0 ;
int V_159 ;
struct V_116 * V_117 ;
struct V_7 * V_8 ;
struct V_31 * V_31 ;
const unsigned char * V_160 = V_9 ;
V_8 = V_112 -> V_8 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return - V_58 ;
V_31 = NULL ;
for ( V_152 = 0 ; V_152 < V_134 ; ++ V_152 ) {
if ( V_117 -> V_135 [ V_152 ] &&
V_117 -> V_135 [ V_152 ] -> V_18 != - V_115 ) {
V_31 = V_117 -> V_135 [ V_152 ] ;
F_19 ( & V_112 -> V_12 , L_34 , V_152 ) ;
break;
}
}
if ( V_31 == NULL ) {
F_19 ( & V_112 -> V_12 , L_35 , V_41 ) ;
goto exit;
}
if ( V_31 -> V_106 == NULL ) {
V_31 -> V_106 = F_34 ( V_136 ,
V_88 ) ;
if ( V_31 -> V_106 == NULL ) {
F_94 ( V_112 , L_36 ,
V_41 ) ;
goto exit;
}
}
V_159 = F_95 ( V_157 , V_136 ) ;
memcpy ( V_31 -> V_106 , V_160 , V_159 ) ;
F_96 ( & V_112 -> V_12 , V_41 , V_159 ,
V_31 -> V_106 ) ;
F_97 ( V_31 , V_8 -> V_12 ,
F_62 ( V_8 -> V_12 ,
V_112 -> V_161 ) ,
V_31 -> V_106 , V_159 ,
F_78 , V_117 ) ;
V_18 = F_28 ( V_31 , V_47 ) ;
if ( V_18 ) {
F_94 ( V_112 , L_37
L_38 , V_41 , V_18 ) ;
V_158 = V_18 ;
goto exit;
}
V_158 = V_159 ;
exit:
return V_158 ;
}
static void F_98 ( struct V_118 * V_119 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 ;
int V_18 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_120 ) {
F_19 ( & V_112 -> V_12 , L_39 , V_41 ) ;
return;
}
if ( F_99 ( V_119 ) ) {
unsigned char V_162 = F_100 ( V_119 ) ;
V_18 = F_93 ( V_119 , V_112 , & V_162 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_119 -> V_163 . V_164 & V_165 ) {
V_117 -> V_145 &= ~ V_166 ;
F_3 ( V_112 -> V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_146 , V_117 -> V_145 ) ;
if ( V_18 != 0 )
return;
}
}
static void F_101 ( struct V_118 * V_119 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 = F_86 ( V_112 ) ;
int V_18 ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_120 ) {
F_19 ( & V_112 -> V_12 , L_39 , V_41 ) ;
return;
}
if ( F_99 ( V_119 ) ) {
unsigned char V_167 = F_102 ( V_119 ) ;
V_18 = F_93 ( V_119 , V_112 , & V_167 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_119 -> V_163 . V_164 & V_165 ) {
V_117 -> V_145 |= V_166 ;
F_3 ( V_112 -> V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_146 , V_117 -> V_145 ) ;
if ( V_18 != 0 )
return;
}
}
static int F_103 ( struct V_116 * V_117 ,
unsigned int V_168 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_130 ;
enum V_1 V_169 ;
if ( V_117 == NULL )
return - V_170 ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
F_19 ( & V_112 -> V_12 , L_40 ) ;
V_130 = V_112 -> V_137 - V_112 -> V_8 -> V_138 ;
F_3 ( V_8 , V_130 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0xcf ) ;
V_117 -> V_145 = 0x0b ;
F_3 ( V_8 , V_130 , V_146 , V_117 -> V_145 ) ;
F_3 ( V_8 , V_25 , V_147 , 0x00 ) ;
if ( V_130 == 0 )
V_169 = V_5 ;
else
V_169 = V_140 ;
F_3 ( V_8 , V_25 , V_169 , V_168 * 0x10 ) ;
F_3 ( V_8 , V_25 , V_147 , 0x03 ) ;
V_117 -> V_145 = 0x2b ;
F_3 ( V_8 , V_130 , V_146 , V_117 -> V_145 ) ;
V_117 -> V_143 = V_117 -> V_143 | V_171 ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
F_3 ( V_8 , V_130 , V_172 , 0x01 ) ;
F_3 ( V_8 , V_130 , V_173 , 0x00 ) ;
V_117 -> V_143 = V_117 -> V_143 & ~ V_171 ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
return 0 ;
}
static int F_104 ( struct V_111 * V_112 , int V_174 , int * V_175 )
{
int V_152 ;
T_1 V_176 ;
T_1 V_177 ;
T_1 V_178 ;
F_19 ( & V_112 -> V_12 , L_41 , V_41 , V_174 ) ;
for ( V_152 = 0 ; V_152 < F_105 ( V_179 ) ; V_152 ++ ) {
if ( V_179 [ V_152 ] . V_174 == V_174 ) {
* V_175 = V_179 [ V_152 ] . V_175 ;
return 0 ;
}
}
if ( V_174 > 75 && V_174 < 230400 ) {
V_176 = ( T_1 ) ( 230400L / V_174 ) ;
V_177 = ( T_1 ) ( 2304000L / V_174 ) ;
V_178 = ( T_1 ) ( V_177 - ( V_176 * 10 ) ) ;
if ( V_178 > 4 )
V_176 ++ ;
* V_175 = V_176 ;
F_19 ( & V_112 -> V_12 , L_42 , V_174 , V_176 ) ;
return 0 ;
}
F_19 ( & V_112 -> V_12 , L_43 ) ;
return - V_170 ;
}
static int F_106 ( struct V_116 * V_117 ,
int V_174 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_175 ;
int V_18 ;
unsigned char V_137 ;
if ( V_117 == NULL )
return - 1 ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
V_137 = V_112 -> V_137 - V_112 -> V_8 -> V_138 ;
F_19 ( & V_112 -> V_12 , L_44 , V_41 , V_174 ) ;
V_18 = F_104 ( V_112 , V_174 , & V_175 ) ;
if ( V_18 ) {
F_6 ( & V_112 -> V_12 , L_45 , V_41 ) ;
return V_18 ;
}
V_117 -> V_143 = V_117 -> V_143 | V_171 ;
F_3 ( V_8 , V_137 , V_144 , V_117 -> V_143 ) ;
F_3 ( V_8 , V_137 , V_172 , ( T_2 ) ( V_175 & 0xff ) ) ;
F_3 ( V_8 , V_137 , V_173 , ( T_2 ) ( ( V_175 & 0xff00 ) >> 8 ) ) ;
V_117 -> V_143 = V_117 -> V_143 & ~ V_171 ;
F_3 ( V_8 , V_137 , V_144 , V_117 -> V_143 ) ;
return V_18 ;
}
static void F_107 ( struct V_118 * V_119 ,
struct V_116 * V_117 ,
struct V_180 * V_181 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_168 ;
unsigned V_182 ;
unsigned V_183 ;
T_2 V_70 = 0xff ;
T_2 V_184 ;
T_2 V_185 ;
T_2 V_186 ;
int V_18 ;
int V_130 ;
if ( V_117 == NULL )
return ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
V_130 = V_112 -> V_137 - V_112 -> V_8 -> V_138 ;
if ( ! V_117 -> V_120 ) {
F_19 ( & V_112 -> V_12 , L_39 , V_41 ) ;
return;
}
V_184 = V_187 ;
V_186 = 0x00 ;
V_185 = 0x00 ;
V_182 = V_119 -> V_163 . V_164 ;
V_183 = V_119 -> V_163 . V_188 ;
switch ( V_182 & V_189 ) {
case V_190 :
V_184 = V_191 ;
V_70 = 0x1f ;
break;
case V_192 :
V_184 = V_193 ;
V_70 = 0x3f ;
break;
case V_194 :
V_184 = V_195 ;
V_70 = 0x7f ;
break;
default:
case V_196 :
V_184 = V_187 ;
break;
}
if ( V_182 & V_197 ) {
if ( V_182 & V_198 ) {
V_185 = V_199 ;
F_19 ( & V_112 -> V_12 , L_46 , V_41 ) ;
} else {
V_185 = ( V_200 | V_199 ) ;
F_19 ( & V_112 -> V_12 , L_47 , V_41 ) ;
}
} else {
F_19 ( & V_112 -> V_12 , L_48 , V_41 ) ;
}
if ( V_182 & V_201 )
V_185 = V_185 | 0x20 ;
if ( V_182 & V_202 ) {
V_186 = V_203 ;
F_19 ( & V_112 -> V_12 , L_49 , V_41 ) ;
} else {
V_186 = 0x00 ;
F_19 ( & V_112 -> V_12 , L_50 , V_41 ) ;
}
#define F_108 0x03
#define F_109 0x04
#define F_110 0x38
V_117 -> V_143 &=
~ ( F_108 | F_109 | F_110 ) ;
V_117 -> V_143 |= ( V_184 | V_185 | V_186 ) ;
F_3 ( V_8 , V_130 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_130 , V_142 , 0xcf ) ;
F_3 ( V_8 , V_130 , V_144 , V_117 -> V_143 ) ;
V_117 -> V_145 = 0x0b ;
F_3 ( V_8 , V_130 , V_146 , V_117 -> V_145 ) ;
V_117 -> V_145 = V_150 ;
if ( V_182 & V_204 )
V_117 -> V_145 |= ( V_205 | V_166 ) ;
if ( V_182 & V_165 ) {
V_117 -> V_145 |= ( V_206 ) ;
if ( V_112 -> V_137 )
F_3 ( V_8 , V_25 , V_147 , 0x01 ) ;
else
F_3 ( V_8 , V_25 , V_147 , 0x02 ) ;
} else
V_117 -> V_145 &= ~ ( V_206 ) ;
F_3 ( V_8 , V_130 , V_146 , V_117 -> V_145 ) ;
V_168 = F_111 ( V_119 ) ;
if ( ! V_168 ) {
F_19 ( & V_112 -> V_12 , L_51 ) ;
V_168 = 9600 ;
}
if ( V_168 >= 230400 ) {
F_103 ( V_117 , V_168 ) ;
F_3 ( V_8 , V_130 , V_141 , 0x0c ) ;
return;
}
F_19 ( & V_112 -> V_12 , L_52 , V_41 , V_168 ) ;
V_18 = F_106 ( V_117 , V_168 ) ;
if ( V_182 & V_204 )
F_112 ( V_119 , V_168 , V_168 ) ;
F_3 ( V_8 , V_130 , V_141 , 0x0c ) ;
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_18 = F_28 ( V_112 -> V_114 , V_47 ) ;
if ( V_18 )
F_19 ( & V_112 -> V_12 , L_53 , V_18 ) ;
}
}
static void F_113 ( struct V_118 * V_119 ,
struct V_111 * V_112 , struct V_180 * V_181 )
{
int V_18 ;
unsigned int V_182 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
V_8 = V_112 -> V_8 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_120 ) {
F_19 ( & V_112 -> V_12 , L_39 , V_41 ) ;
return;
}
F_19 ( & V_112 -> V_12 , L_54 ) ;
V_182 = V_119 -> V_163 . V_164 ;
F_19 ( & V_112 -> V_12 , L_55 , V_41 ,
V_119 -> V_163 . V_164 , F_114 ( V_119 -> V_163 . V_188 ) ) ;
F_19 ( & V_112 -> V_12 , L_56 , V_41 ,
V_181 -> V_164 , F_114 ( V_181 -> V_188 ) ) ;
F_107 ( V_119 , V_117 , V_181 ) ;
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_18 = F_28 ( V_112 -> V_114 , V_47 ) ;
if ( V_18 )
F_19 ( & V_112 -> V_12 , L_53 , V_18 ) ;
}
}
static int F_115 ( struct V_118 * V_119 ,
struct V_116 * V_117 , unsigned int T_5 * V_17 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
unsigned int V_98 = 0 ;
unsigned char V_9 = 0 ;
int V_130 = V_112 -> V_137 - V_112 -> V_8 -> V_138 ;
int V_157 ;
V_157 = F_88 ( V_119 ) ;
if ( V_157 == 0 ) {
F_7 ( V_112 -> V_8 , V_130 , V_139 , & V_9 ) ;
if ( ( V_9 & ( V_207 | V_208 ) )
== ( V_207 | V_208 ) ) {
F_19 ( & V_112 -> V_12 , L_57 , V_41 ) ;
V_98 = V_209 ;
}
}
if ( F_116 ( V_17 , & V_98 , sizeof( int ) ) )
return - V_210 ;
return 0 ;
}
static int F_117 ( struct V_118 * V_119 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 = F_86 ( V_112 ) ;
unsigned int V_98 = 0 ;
unsigned int V_211 ;
unsigned int V_212 ;
V_211 = V_117 -> V_145 ;
V_212 = V_117 -> V_213 ;
V_98 = ( ( V_211 & V_205 ) ? V_214 : 0 )
| ( ( V_211 & V_166 ) ? V_215 : 0 )
| ( ( V_212 & V_216 ) ? V_217 : 0 )
| ( ( V_212 & V_218 ) ? V_219 : 0 )
| ( ( V_212 & V_220 ) ? V_221 : 0 )
| ( ( V_212 & V_222 ) ? V_223 : 0 ) ;
return V_98 ;
}
static int F_118 ( struct V_118 * V_119 ,
unsigned int V_224 , unsigned int V_225 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 = F_86 ( V_112 ) ;
unsigned int V_211 ;
V_211 = V_117 -> V_145 ;
if ( V_224 & V_215 )
V_211 |= V_166 ;
if ( V_224 & V_214 )
V_211 |= V_205 ;
if ( V_224 & V_226 )
V_211 |= V_227 ;
if ( V_225 & V_215 )
V_211 &= ~ V_166 ;
if ( V_225 & V_214 )
V_211 &= ~ V_205 ;
if ( V_225 & V_226 )
V_211 &= ~ V_227 ;
V_117 -> V_145 = V_211 ;
F_3 ( V_112 -> V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_146 , V_117 -> V_145 ) ;
return 0 ;
}
static int F_119 ( struct V_118 * V_119 ,
struct V_228 * V_149 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 ;
struct V_229 V_230 ;
V_117 = F_86 ( V_112 ) ;
V_230 = V_117 -> V_149 ;
V_149 -> V_231 = V_230 . V_231 ;
V_149 -> V_232 = V_230 . V_232 ;
V_149 -> V_233 = V_230 . V_233 ;
V_149 -> V_234 = V_230 . V_234 ;
V_149 -> V_235 = V_230 . V_235 ;
V_149 -> V_236 = V_230 . V_236 ;
V_149 -> V_237 = V_230 . V_237 ;
V_149 -> V_238 = V_230 . V_238 ;
V_149 -> V_239 = V_230 . V_239 ;
V_149 -> V_240 = V_230 . V_240 ;
V_149 -> V_241 = V_230 . V_241 ;
F_19 ( & V_112 -> V_12 , L_58 , V_41 ,
V_149 -> V_235 , V_149 -> V_236 ) ;
return 0 ;
}
static int F_120 ( struct V_116 * V_117 , unsigned int V_242 ,
unsigned int T_5 * V_17 )
{
unsigned int V_211 ;
unsigned int V_243 ;
struct V_111 * V_112 ;
if ( V_117 == NULL )
return - 1 ;
V_112 = (struct V_111 * ) V_117 -> V_112 ;
V_211 = V_117 -> V_145 ;
if ( F_121 ( & V_243 , V_17 , sizeof( int ) ) )
return - V_210 ;
switch ( V_242 ) {
case V_244 :
if ( V_243 & V_215 )
V_211 |= V_166 ;
if ( V_243 & V_214 )
V_211 |= V_166 ;
if ( V_243 & V_226 )
V_211 |= V_227 ;
break;
case V_245 :
if ( V_243 & V_215 )
V_211 &= ~ V_166 ;
if ( V_243 & V_214 )
V_211 &= ~ V_166 ;
if ( V_243 & V_226 )
V_211 &= ~ V_227 ;
break;
}
V_117 -> V_145 = V_211 ;
F_3 ( V_112 -> V_8 , V_112 -> V_137 - V_112 -> V_8 -> V_138 ,
V_146 , V_117 -> V_145 ) ;
return 0 ;
}
static int F_122 ( struct V_116 * V_117 ,
struct V_246 T_5 * V_247 )
{
struct V_246 V_35 ;
if ( ! V_247 )
return - V_210 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . type = V_248 ;
V_35 . line = V_117 -> V_112 -> V_8 -> V_138 ;
V_35 . V_112 = V_117 -> V_112 -> V_137 ;
V_35 . V_249 = 0 ;
V_35 . V_34 = V_250 | V_251 ;
V_35 . V_252 = V_134 * V_136 ;
V_35 . V_253 = 9600 ;
V_35 . V_254 = 5 * V_255 ;
V_35 . V_256 = 30 * V_255 ;
if ( F_116 ( V_247 , & V_35 , sizeof( * V_247 ) ) )
return - V_210 ;
return 0 ;
}
static int F_123 ( struct V_118 * V_119 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_111 * V_112 = V_119 -> V_151 ;
struct V_116 * V_117 ;
struct V_229 V_230 ;
struct V_229 V_257 ;
V_117 = F_86 ( V_112 ) ;
if ( V_117 == NULL )
return - V_58 ;
F_19 ( & V_112 -> V_12 , L_59 , V_41 , V_242 ) ;
switch ( V_242 ) {
case V_258 :
F_19 ( & V_112 -> V_12 , L_60 , V_41 ) ;
return F_115 ( V_119 , V_117 ,
( unsigned int T_5 * ) V_243 ) ;
case V_244 :
case V_245 :
F_19 ( & V_112 -> V_12 , L_61 , V_41 ) ;
return F_120 ( V_117 , V_242 ,
( unsigned int T_5 * ) V_243 ) ;
case V_259 :
F_19 ( & V_112 -> V_12 , L_62 , V_41 ) ;
return F_122 ( V_117 ,
(struct V_246 T_5 * ) V_243 ) ;
case V_260 :
F_19 ( & V_112 -> V_12 , L_63 , V_41 ) ;
V_257 = V_117 -> V_149 ;
while ( 1 ) {
if ( F_124 ( V_261 ) )
return - V_262 ;
V_230 = V_117 -> V_149 ;
if ( V_230 . V_233 == V_257 . V_233 && V_230 . V_232 == V_257 . V_232 &&
V_230 . V_234 == V_257 . V_234 && V_230 . V_231 == V_257 . V_231 )
return - V_94 ;
if ( ( ( V_243 & V_263 ) && ( V_230 . V_233 != V_257 . V_233 ) ) ||
( ( V_243 & V_223 ) && ( V_230 . V_232 != V_257 . V_232 ) ) ||
( ( V_243 & V_264 ) && ( V_230 . V_234 != V_257 . V_234 ) ) ||
( ( V_243 & V_217 ) && ( V_230 . V_231 != V_257 . V_231 ) ) ) {
return 0 ;
}
V_257 = V_230 ;
}
break;
}
return - V_265 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_10 * V_12 ;
char V_9 ;
T_4 V_127 ;
int V_33 ;
V_127 = F_84 ( V_8 -> V_12 -> V_128 . V_123 ) ;
V_12 = V_8 -> V_12 ;
if ( V_127 == V_124 ) {
struct V_111 * V_35 = V_8 -> V_112 [ 0 ] ;
V_8 -> V_112 [ 0 ] = V_8 -> V_112 [ 1 ] ;
V_8 -> V_112 [ 1 ] = V_35 ;
V_8 -> V_112 [ 0 ] -> V_266 = V_35 -> V_266 ;
V_8 -> V_112 [ 0 ] -> V_267 = V_35 -> V_267 ;
V_8 -> V_112 [ 0 ] -> V_268 =
V_35 -> V_268 ;
V_8 -> V_112 [ 1 ] -> V_266 = NULL ;
V_8 -> V_112 [ 1 ] -> V_267 = NULL ;
}
F_5 ( V_8 -> V_12 , F_4 ( V_8 -> V_12 , 0 ) ,
( T_2 ) 0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 , 5 * V_255 ) ;
V_33 = F_28 ( V_8 -> V_112 [ 0 ] -> V_266 , V_88 ) ;
if ( V_33 )
F_6 ( & V_12 -> V_12 ,
L_21 ,
V_41 , V_33 ) ;
#ifdef F_73
if ( V_127 == V_124 ) {
V_33 = F_63 ( V_8 ) ;
if ( V_33 < 0 )
return V_33 ;
}
#endif
F_7 ( V_8 , 0 , V_139 , & V_9 ) ;
F_19 ( & V_12 -> V_12 , L_64 , V_9 ) ;
return 0 ;
}
static void F_126 ( struct V_7 * V_8 )
{
#ifdef F_73
if ( F_84 ( V_8 -> V_12 -> V_128 . V_123 )
== V_124 ) {
struct V_29 * V_30 ;
unsigned long V_34 ;
struct V_20 * V_21 =
F_127 ( V_8 ) ;
F_31 ( & V_61 ) ;
V_21 -> V_60 -> V_62 = NULL ;
F_32 ( & V_61 ) ;
if ( V_21 -> V_63 )
F_128 ( & V_21 -> V_64 ,
V_19 ) ;
F_129 ( V_21 -> V_60 ) ;
F_66 ( V_8 , NULL ) ;
V_21 -> V_8 = NULL ;
F_130 ( & V_21 -> V_42 ) ;
F_22 ( & V_21 -> V_44 , V_34 ) ;
F_131 (urbtrack,
&mos_parport->active_urbs,
urblist_entry)
F_132 ( V_30 -> V_31 ) ;
F_24 ( & V_21 -> V_44 , V_34 ) ;
F_15 ( & V_21 -> V_28 , F_10 ) ;
}
#endif
}
static int F_133 ( struct V_111 * V_112 )
{
struct V_116 * V_117 ;
V_117 = F_64 ( sizeof( * V_117 ) , V_88 ) ;
if ( ! V_117 )
return - V_52 ;
V_112 -> V_268 =
V_112 -> V_8 -> V_112 [ 0 ] -> V_268 ;
V_117 -> V_112 = V_112 ;
F_134 ( V_112 , V_117 ) ;
return 0 ;
}
static int F_135 ( struct V_111 * V_112 )
{
struct V_116 * V_117 ;
V_117 = F_86 ( V_112 ) ;
F_12 ( V_117 ) ;
return 0 ;
}
