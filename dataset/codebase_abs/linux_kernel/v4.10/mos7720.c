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
T_3 * V_20 ;
int V_18 ;
V_20 = F_9 ( 1 , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_18 = F_5 ( V_11 , V_13 , V_14 , V_15 , V_17 ,
V_16 , V_20 , 1 , V_19 ) ;
if ( V_18 == 1 )
* V_9 = * V_20 ;
else if ( V_18 < 0 )
F_6 ( & V_11 -> V_12 ,
L_1 , V_18 ) ;
F_10 ( V_20 ) ;
return V_18 ;
}
static inline int F_11 ( struct V_23 * V_24 ,
enum V_25 V_26 )
{
V_24 -> V_27 = V_26 ;
F_3 ( V_24 -> V_8 , V_28 , V_29 ,
V_24 -> V_27 ) ;
return 0 ;
}
static void F_12 ( struct V_30 * V_30 )
{
struct V_23 * V_24 =
F_13 ( V_30 , struct V_23 , V_31 ) ;
F_10 ( V_24 ) ;
}
static void F_14 ( struct V_30 * V_30 )
{
struct V_32 * V_33 =
F_13 ( V_30 , struct V_32 , V_31 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_15 ( V_33 -> V_34 ) ;
F_10 ( V_33 -> V_35 ) ;
F_10 ( V_33 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
}
static void F_17 ( unsigned long V_36 )
{
int V_37 ;
unsigned long V_38 ;
struct V_23 * V_24 = ( void * ) V_36 ;
struct V_32 * V_33 , * V_39 ;
struct V_40 * V_41 , * V_42 ;
struct V_43 * V_12 ;
if ( F_18 ( V_24 -> V_8 == NULL ) )
return;
V_12 = & V_24 -> V_8 -> V_12 -> V_12 ;
if ( ! F_19 ( & V_24 -> V_8 -> V_44 ) ) {
F_20 ( V_12 , L_2 , V_45 ) ;
F_21 ( & V_24 -> V_46 ) ;
return;
}
if ( F_18 ( V_24 -> V_8 -> V_47 ) ) {
F_22 ( & V_24 -> V_8 -> V_44 ) ;
return;
}
F_23 ( & V_24 -> V_48 , V_38 ) ;
if ( F_24 ( & V_24 -> V_49 ) ) {
F_25 ( & V_24 -> V_48 , V_38 ) ;
F_22 ( & V_24 -> V_8 -> V_44 ) ;
F_20 ( V_12 , L_3 , V_45 ) ;
return;
}
F_26 (cursor, next, &mos_parport->deferred_urbs)
F_27 ( V_41 , & V_24 -> V_50 ) ;
F_28 (urbtrack, tmp, &mos_parport->active_urbs,
urblist_entry) {
V_37 = F_29 ( V_33 -> V_34 , V_51 ) ;
F_20 ( V_12 , L_4 , V_45 ) ;
if ( V_37 ) {
F_6 ( V_12 , L_5 , V_37 ) ;
F_30 ( & V_33 -> V_52 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
}
}
F_25 ( & V_24 -> V_48 , V_38 ) ;
F_22 ( & V_24 -> V_8 -> V_44 ) ;
}
static void F_31 ( struct V_34 * V_34 )
{
struct V_32 * V_33 = V_34 -> V_53 ;
int V_18 = V_34 -> V_18 ;
if ( F_18 ( V_18 ) )
F_20 ( & V_34 -> V_12 -> V_12 , L_6 , V_45 , V_18 ) ;
F_32 ( & V_33 -> V_24 -> V_48 ) ;
F_30 ( & V_33 -> V_52 ) ;
F_33 ( & V_33 -> V_24 -> V_48 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
}
static int F_34 ( struct V_23 * V_24 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_32 * V_33 ;
int V_37 ;
unsigned long V_38 ;
struct V_7 * V_8 = V_24 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
V_33 = F_9 ( sizeof( struct V_32 ) , V_51 ) ;
if ( ! V_33 )
return - V_22 ;
F_35 ( & V_24 -> V_31 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_34 = F_36 ( 0 , V_51 ) ;
if ( ! V_33 -> V_34 ) {
F_10 ( V_33 ) ;
return - V_22 ;
}
V_33 -> V_35 = F_9 ( sizeof( * V_33 -> V_35 ) , V_51 ) ;
if ( ! V_33 -> V_35 ) {
F_15 ( V_33 -> V_34 ) ;
F_10 ( V_33 ) ;
return - V_22 ;
}
V_33 -> V_35 -> V_54 = ( T_2 ) 0x40 ;
V_33 -> V_35 -> V_55 = ( T_2 ) 0x0e ;
V_33 -> V_35 -> V_56 = F_37 ( F_2 ( V_2 , V_28 ) ) ;
V_33 -> V_35 -> V_57 = F_37 ( F_1 ( V_2 ) ) ;
V_33 -> V_35 -> V_58 = 0 ;
F_38 ( V_33 -> V_34 , V_11 ,
F_4 ( V_11 , 0 ) ,
( unsigned char * ) V_33 -> V_35 ,
NULL , 0 , F_31 , V_33 ) ;
F_39 ( & V_33 -> V_31 ) ;
F_40 ( & V_33 -> V_52 ) ;
if ( ! F_19 ( & V_8 -> V_44 ) ) {
F_23 ( & V_24 -> V_48 , V_38 ) ;
F_41 ( & V_33 -> V_52 ,
& V_24 -> V_49 ) ;
F_25 ( & V_24 -> V_48 , V_38 ) ;
F_21 ( & V_24 -> V_46 ) ;
F_20 ( & V_11 -> V_12 , L_7 ) ;
return 0 ;
}
if ( V_8 -> V_47 ) {
F_16 ( & V_33 -> V_31 , F_14 ) ;
F_22 ( & V_8 -> V_44 ) ;
return - V_59 ;
}
F_23 ( & V_24 -> V_48 , V_38 ) ;
F_41 ( & V_33 -> V_52 , & V_24 -> V_50 ) ;
F_25 ( & V_24 -> V_48 , V_38 ) ;
V_37 = F_29 ( V_33 -> V_34 , V_51 ) ;
F_22 ( & V_8 -> V_44 ) ;
if ( V_37 ) {
F_6 ( & V_11 -> V_12 ,
L_8 , V_45 , V_37 ) ;
F_23 ( & V_24 -> V_48 , V_38 ) ;
F_30 ( & V_33 -> V_52 ) ;
F_25 ( & V_24 -> V_48 , V_38 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
return V_37 ;
}
return 0 ;
}
static int F_42 ( struct V_60 * V_61 )
{
struct V_23 * V_24 ;
F_32 ( & V_62 ) ;
V_24 = V_61 -> V_63 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_62 ) ;
return - 1 ;
}
V_24 -> V_64 = true ;
F_43 ( & V_24 -> V_65 ) ;
F_33 ( & V_62 ) ;
F_44 ( & V_24 -> V_8 -> V_44 ) ;
if ( V_24 -> V_8 -> V_47 ) {
F_22 ( & V_24 -> V_8 -> V_44 ) ;
V_24 -> V_64 = false ;
F_45 ( & V_24 -> V_65 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_46 ( struct V_60 * V_61 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
F_22 ( & V_24 -> V_8 -> V_44 ) ;
V_24 -> V_64 = false ;
F_45 ( & V_24 -> V_65 ) ;
}
static void F_47 ( struct V_60 * V_61 , unsigned char V_66 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
if ( F_42 ( V_61 ) < 0 )
return;
F_11 ( V_24 , V_67 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_6 , ( T_2 ) V_66 ) ;
F_46 ( V_61 ) ;
}
static unsigned char F_48 ( struct V_60 * V_61 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
unsigned char V_66 ;
if ( F_42 ( V_61 ) < 0 )
return 0 ;
F_7 ( V_24 -> V_8 , V_28 , V_6 , & V_66 ) ;
F_46 ( V_61 ) ;
return V_66 ;
}
static void F_49 ( struct V_60 * V_61 , unsigned char V_66 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
T_2 V_9 ;
if ( F_42 ( V_61 ) < 0 )
return;
V_9 = ( ( T_2 ) V_66 & 0x0f ) | ( V_24 -> V_68 & 0xf0 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_69 , V_9 ) ;
V_24 -> V_68 = V_9 ;
F_46 ( V_61 ) ;
}
static unsigned char F_50 ( struct V_60 * V_61 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
T_2 V_70 ;
F_32 ( & V_62 ) ;
V_24 = V_61 -> V_63 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_62 ) ;
return 0 ;
}
V_70 = V_24 -> V_68 & 0x0f ;
F_33 ( & V_62 ) ;
return V_70 ;
}
static unsigned char F_51 ( struct V_60 * V_61 ,
unsigned char V_71 ,
unsigned char V_72 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
T_2 V_70 ;
V_71 &= 0x0f ;
V_72 &= 0x0f ;
if ( F_42 ( V_61 ) < 0 )
return 0 ;
V_24 -> V_68 = ( V_24 -> V_68 & ( ~ V_71 ) ) ^ V_72 ;
F_3 ( V_24 -> V_8 , V_28 , V_69 ,
V_24 -> V_68 ) ;
V_70 = V_24 -> V_68 & 0x0f ;
F_46 ( V_61 ) ;
return V_70 ;
}
static unsigned char F_52 ( struct V_60 * V_61 )
{
unsigned char V_18 ;
struct V_23 * V_24 = V_61 -> V_63 ;
F_32 ( & V_62 ) ;
V_24 = V_61 -> V_63 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_62 ) ;
return 0 ;
}
V_18 = F_53 ( & V_24 -> V_73 ) & 0xf8 ;
F_33 ( & V_62 ) ;
return V_18 ;
}
static void F_54 ( struct V_60 * V_61 )
{
}
static void F_55 ( struct V_60 * V_61 )
{
}
static void F_56 ( struct V_60 * V_61 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
if ( F_42 ( V_61 ) < 0 )
return;
F_11 ( V_24 , V_74 ) ;
V_24 -> V_68 &= ~ 0x20 ;
F_3 ( V_24 -> V_8 , V_28 , V_69 ,
V_24 -> V_68 ) ;
F_46 ( V_61 ) ;
}
static void F_57 ( struct V_60 * V_61 )
{
struct V_23 * V_24 = V_61 -> V_63 ;
if ( F_42 ( V_61 ) < 0 )
return;
F_11 ( V_24 , V_74 ) ;
V_24 -> V_68 |= 0x20 ;
F_3 ( V_24 -> V_8 , V_28 , V_69 ,
V_24 -> V_68 ) ;
F_46 ( V_61 ) ;
}
static void F_58 ( struct V_75 * V_12 ,
struct V_76 * V_77 )
{
V_77 -> V_78 . V_79 . V_80 = V_81 ;
V_77 -> V_78 . V_79 . V_82 = V_83 ;
}
static void F_59 ( struct V_60 * V_61 ,
struct V_76 * V_77 )
{
struct V_23 * V_24 ;
F_32 ( & V_62 ) ;
V_24 = V_61 -> V_63 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_62 ) ;
return;
}
V_77 -> V_78 . V_79 . V_80 = V_24 -> V_68 ;
V_77 -> V_78 . V_79 . V_82 = V_24 -> V_27 ;
F_33 ( & V_62 ) ;
}
static void F_60 ( struct V_60 * V_61 ,
struct V_76 * V_77 )
{
struct V_23 * V_24 ;
F_32 ( & V_62 ) ;
V_24 = V_61 -> V_63 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_62 ) ;
return;
}
F_34 ( V_24 , V_69 ,
V_24 -> V_68 ) ;
F_34 ( V_24 , V_29 ,
V_24 -> V_27 ) ;
F_33 ( & V_62 ) ;
}
static T_4 F_61 ( struct V_60 * V_61 ,
const void * V_84 ,
T_4 V_85 , int V_38 )
{
int V_86 ;
struct V_23 * V_24 = V_61 -> V_63 ;
int V_87 ;
if ( F_42 ( V_61 ) < 0 )
return 0 ;
F_11 ( V_24 , V_88 ) ;
V_86 = F_62 ( V_24 -> V_8 -> V_12 ,
F_63 ( V_24 -> V_8 -> V_12 , 2 ) ,
( void * ) V_84 , V_85 , & V_87 ,
V_19 ) ;
F_46 ( V_61 ) ;
if ( V_86 ) {
F_6 ( & V_24 -> V_8 -> V_12 -> V_12 ,
L_9 , V_86 ) ;
return 0 ;
}
return V_87 ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_23 * V_24 ;
V_24 = F_65 ( sizeof( struct V_23 ) , V_21 ) ;
if ( ! V_24 )
return - V_22 ;
V_24 -> V_64 = false ;
F_39 ( & V_24 -> V_31 ) ;
F_66 ( & V_24 -> V_48 ) ;
F_40 ( & V_24 -> V_50 ) ;
F_40 ( & V_24 -> V_49 ) ;
F_67 ( V_8 , V_24 ) ;
V_24 -> V_8 = V_8 ;
F_68 ( & V_24 -> V_46 , F_17 ,
( unsigned long ) V_24 ) ;
F_69 ( & V_24 -> V_65 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_89 , ( T_2 ) 0x80 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_89 , ( T_2 ) 0x00 ) ;
V_24 -> V_68 = V_81 ;
F_3 ( V_24 -> V_8 , V_28 , V_69 ,
V_24 -> V_68 ) ;
V_24 -> V_27 = V_83 ;
F_3 ( V_24 -> V_8 , V_28 , V_29 ,
V_24 -> V_27 ) ;
V_24 -> V_61 = F_70 ( 0 , V_90 ,
V_91 ,
& V_92 ) ;
if ( V_24 -> V_61 == NULL ) {
F_6 ( & V_8 -> V_93 -> V_12 ,
L_10 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
return - V_94 ;
}
V_24 -> V_61 -> V_63 = V_24 ;
V_24 -> V_61 -> V_95 = V_96 | V_97 ;
V_24 -> V_61 -> V_12 = & V_8 -> V_93 -> V_12 ;
F_71 ( V_24 -> V_61 ) ;
return 0 ;
}
static void F_72 ( struct V_34 * V_34 )
{
int V_98 ;
int V_99 ;
int V_18 = V_34 -> V_18 ;
struct V_43 * V_12 = & V_34 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_100 ;
T_2 V_101 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
F_20 ( V_12 , L_11 , V_45 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_45 , V_18 ) ;
goto exit;
}
V_99 = V_34 -> V_105 ;
V_9 = V_34 -> V_106 ;
if ( F_18 ( V_99 != 4 ) ) {
F_20 ( V_12 , L_12 ) ;
return;
}
V_100 = V_9 [ 3 ] ;
V_101 = V_9 [ 2 ] ;
if ( ( V_100 | V_101 ) & 0x01 ) {
F_20 ( V_12 , L_13 ) ;
} else {
switch ( V_100 & 0x0f ) {
case V_107 :
F_20 ( V_12 , L_14 ) ;
break;
case V_108 :
F_20 ( V_12 , L_15 ) ;
break;
case V_109 :
break;
}
switch ( V_101 & 0x0f ) {
case V_107 :
F_20 ( V_12 , L_16 ) ;
break;
case V_108 :
F_20 ( V_12 , L_17 ) ;
break;
case V_109 :
break;
}
}
exit:
V_98 = F_29 ( V_34 , V_51 ) ;
if ( V_98 )
F_6 ( V_12 , L_18 , V_45 , V_98 ) ;
}
static void F_73 ( struct V_34 * V_34 )
{
int V_98 ;
int V_99 ;
int V_18 = V_34 -> V_18 ;
struct V_43 * V_12 = & V_34 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_110 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
case - V_59 :
F_20 ( V_12 , L_11 , V_45 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_45 , V_18 ) ;
goto exit;
}
V_99 = V_34 -> V_105 ;
V_9 = V_34 -> V_106 ;
if ( F_18 ( V_99 != 4 ) ) {
F_20 ( V_12 , L_12 ) ;
return;
}
V_110 = V_9 [ 0 ] ;
if ( ! ( V_110 & 0x01 ) ) {
switch ( V_110 & 0x0f ) {
case V_107 :
F_20 ( V_12 , L_19 ) ;
break;
case V_108 :
F_20 ( V_12 , L_20 ) ;
break;
case V_109 :
break;
}
}
#ifdef F_74
{
struct V_111 * V_112 = V_34 -> V_53 ;
struct V_23 * V_24 = V_112 -> V_8 -> V_113 ;
if ( F_18 ( V_24 == NULL ) )
return;
F_75 ( & V_24 -> V_73 , V_9 [ 2 ] ) ;
}
#endif
exit:
V_98 = F_29 ( V_34 , V_51 ) ;
if ( V_98 )
F_6 ( V_12 , L_18 , V_45 , V_98 ) ;
}
static void F_76 ( struct V_34 * V_34 )
{
int V_86 ;
unsigned char * V_9 ;
struct V_111 * V_112 ;
int V_18 = V_34 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_21 , V_18 ) ;
return;
}
V_112 = V_34 -> V_53 ;
F_20 ( & V_112 -> V_12 , L_22 , V_45 ) ;
V_9 = V_34 -> V_106 ;
if ( V_34 -> V_105 ) {
F_77 ( & V_112 -> V_112 , V_9 , V_34 -> V_105 ) ;
F_78 ( & V_112 -> V_112 ) ;
}
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_86 = F_29 ( V_112 -> V_114 , V_51 ) ;
if ( V_86 )
F_20 ( & V_112 -> V_12 , L_23 , V_86 ) ;
}
}
static void F_79 ( struct V_34 * V_34 )
{
struct V_116 * V_117 ;
int V_18 = V_34 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_24 , V_18 ) ;
return;
}
V_117 = V_34 -> V_53 ;
if ( ! V_117 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_25 ) ;
return ;
}
if ( V_117 -> V_118 )
F_80 ( & V_117 -> V_112 -> V_112 ) ;
}
static int F_81 ( struct V_7 * V_8 )
{
T_5 V_119 = F_82 ( V_8 -> V_12 -> V_120 . V_121 ) ;
if ( V_119 == V_122 )
return 1 ;
return 2 ;
}
static int F_83 ( struct V_123 * V_124 , struct V_111 * V_112 )
{
struct V_7 * V_8 ;
struct V_34 * V_34 ;
struct V_116 * V_117 ;
int V_125 ;
int V_126 ;
T_2 V_9 ;
int V_127 = 0 ;
int V_128 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_59 ;
F_85 ( V_8 -> V_12 , V_112 -> V_129 -> V_13 ) ;
F_85 ( V_8 -> V_12 , V_112 -> V_114 -> V_13 ) ;
for ( V_128 = 0 ; V_128 < V_130 ; ++ V_128 ) {
V_34 = F_36 ( 0 , V_21 ) ;
V_117 -> V_131 [ V_128 ] = V_34 ;
if ( ! V_34 )
continue;
V_34 -> V_106 = F_9 ( V_132 ,
V_21 ) ;
if ( ! V_34 -> V_106 ) {
F_15 ( V_117 -> V_131 [ V_128 ] ) ;
V_117 -> V_131 [ V_128 ] = NULL ;
continue;
}
V_127 ++ ;
}
if ( ! V_127 )
return - V_22 ;
V_126 = V_112 -> V_126 ;
F_7 ( V_8 , V_126 , V_133 , & V_9 ) ;
F_20 ( & V_112 -> V_12 , L_26 , V_117 , V_9 ) ;
F_3 ( V_8 , V_28 , V_5 , 0x02 ) ;
F_3 ( V_8 , V_28 , V_134 , 0x02 ) ;
F_3 ( V_8 , V_126 , V_135 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0xcf ) ;
V_117 -> V_137 = 0x03 ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
V_117 -> V_139 = 0x0b ;
F_3 ( V_8 , V_126 , V_140 ,
V_117 -> V_139 ) ;
F_3 ( V_8 , V_126 , V_141 , 0x00 ) ;
F_7 ( V_8 , V_28 , V_141 , & V_9 ) ;
V_9 = V_9 | ( V_112 -> V_126 + 1 ) ;
F_3 ( V_8 , V_28 , V_141 , V_9 ) ;
V_117 -> V_137 = 0x83 ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
F_3 ( V_8 , V_126 , V_142 , 0x0c ) ;
F_3 ( V_8 , V_126 , V_135 , 0x00 ) ;
V_117 -> V_137 = 0x03 ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
F_3 ( V_8 , V_126 , V_135 , 0x0c ) ;
V_125 = F_29 ( V_112 -> V_114 , V_21 ) ;
if ( V_125 )
F_6 ( & V_112 -> V_12 , L_27 ,
V_45 , V_125 ) ;
V_117 -> V_139 = V_143 ;
V_117 -> V_118 = 1 ;
return 0 ;
}
static int F_86 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
int V_145 ;
int V_146 = 0 ;
struct V_116 * V_117 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return 0 ;
for ( V_145 = 0 ; V_145 < V_130 ; ++ V_145 ) {
if ( V_117 -> V_131 [ V_145 ] &&
V_117 -> V_131 [ V_145 ] -> V_18 == - V_115 )
V_146 += V_132 ;
}
F_20 ( & V_112 -> V_12 , L_28 , V_45 , V_146 ) ;
return V_146 ;
}
static void F_87 ( struct V_111 * V_112 )
{
struct V_7 * V_8 ;
struct V_116 * V_117 ;
int V_128 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return;
for ( V_128 = 0 ; V_128 < V_130 ; ++ V_128 )
F_88 ( V_117 -> V_131 [ V_128 ] ) ;
for ( V_128 = 0 ; V_128 < V_130 ; ++ V_128 ) {
if ( V_117 -> V_131 [ V_128 ] ) {
F_10 ( V_117 -> V_131 [ V_128 ] -> V_106 ) ;
F_15 ( V_117 -> V_131 [ V_128 ] ) ;
}
}
F_88 ( V_112 -> V_129 ) ;
F_88 ( V_112 -> V_114 ) ;
F_3 ( V_8 , V_112 -> V_126 , V_140 , 0x00 ) ;
F_3 ( V_8 , V_112 -> V_126 , V_135 , 0x00 ) ;
V_117 -> V_118 = 0 ;
}
static void F_89 ( struct V_123 * V_124 , int V_147 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
unsigned char V_9 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( V_147 == - 1 )
V_9 = V_117 -> V_137 | V_148 ;
else
V_9 = V_117 -> V_137 & ~ V_148 ;
V_117 -> V_137 = V_9 ;
F_3 ( V_8 , V_112 -> V_126 , V_138 ,
V_117 -> V_137 ) ;
}
static int F_90 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 ;
int V_149 = 0 ;
int V_145 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_59 ;
for ( V_145 = 0 ; V_145 < V_130 ; ++ V_145 ) {
if ( V_117 -> V_131 [ V_145 ] &&
V_117 -> V_131 [ V_145 ] -> V_18 != - V_115 )
V_149 += V_132 ;
}
F_20 ( & V_112 -> V_12 , L_28 , V_45 , V_149 ) ;
return V_149 ;
}
static int F_91 ( struct V_123 * V_124 , struct V_111 * V_112 ,
const unsigned char * V_9 , int V_150 )
{
int V_18 ;
int V_145 ;
int V_151 = 0 ;
int V_152 ;
struct V_116 * V_117 ;
struct V_7 * V_8 ;
struct V_34 * V_34 ;
const unsigned char * V_153 = V_9 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_59 ;
V_34 = NULL ;
for ( V_145 = 0 ; V_145 < V_130 ; ++ V_145 ) {
if ( V_117 -> V_131 [ V_145 ] &&
V_117 -> V_131 [ V_145 ] -> V_18 != - V_115 ) {
V_34 = V_117 -> V_131 [ V_145 ] ;
F_20 ( & V_112 -> V_12 , L_29 , V_145 ) ;
break;
}
}
if ( V_34 == NULL ) {
F_20 ( & V_112 -> V_12 , L_30 , V_45 ) ;
goto exit;
}
if ( V_34 -> V_106 == NULL ) {
V_34 -> V_106 = F_9 ( V_132 ,
V_51 ) ;
if ( ! V_34 -> V_106 )
goto exit;
}
V_152 = F_92 ( V_150 , V_132 ) ;
memcpy ( V_34 -> V_106 , V_153 , V_152 ) ;
F_93 ( & V_112 -> V_12 , V_45 , V_152 ,
V_34 -> V_106 ) ;
F_94 ( V_34 , V_8 -> V_12 ,
F_63 ( V_8 -> V_12 ,
V_112 -> V_154 ) ,
V_34 -> V_106 , V_152 ,
F_79 , V_117 ) ;
V_18 = F_29 ( V_34 , V_51 ) ;
if ( V_18 ) {
F_95 ( V_112 , L_31
L_32 , V_45 , V_18 ) ;
V_151 = V_18 ;
goto exit;
}
V_151 = V_152 ;
exit:
return V_151 ;
}
static void F_96 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 ;
int V_18 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_20 ( & V_112 -> V_12 , L_33 , V_45 ) ;
return;
}
if ( F_97 ( V_124 ) ) {
unsigned char V_155 = F_98 ( V_124 ) ;
V_18 = F_91 ( V_124 , V_112 , & V_155 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( F_99 ( V_124 ) ) {
V_117 -> V_139 &= ~ V_156 ;
F_3 ( V_112 -> V_8 , V_112 -> V_126 , V_140 ,
V_117 -> V_139 ) ;
}
}
static void F_100 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 = F_84 ( V_112 ) ;
int V_18 ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_20 ( & V_112 -> V_12 , L_33 , V_45 ) ;
return;
}
if ( F_97 ( V_124 ) ) {
unsigned char V_157 = F_101 ( V_124 ) ;
V_18 = F_91 ( V_124 , V_112 , & V_157 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( F_99 ( V_124 ) ) {
V_117 -> V_139 |= V_156 ;
F_3 ( V_112 -> V_8 , V_112 -> V_126 , V_140 ,
V_117 -> V_139 ) ;
}
}
static int F_102 ( struct V_116 * V_117 ,
unsigned int V_158 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_126 ;
enum V_1 V_159 ;
if ( V_117 == NULL )
return - V_160 ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
F_20 ( & V_112 -> V_12 , L_34 ) ;
V_126 = V_112 -> V_126 ;
F_3 ( V_8 , V_126 , V_135 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0xcf ) ;
V_117 -> V_139 = 0x0b ;
F_3 ( V_8 , V_126 , V_140 ,
V_117 -> V_139 ) ;
F_3 ( V_8 , V_28 , V_141 , 0x00 ) ;
if ( V_126 == 0 )
V_159 = V_5 ;
else
V_159 = V_134 ;
F_3 ( V_8 , V_28 , V_159 , V_158 * 0x10 ) ;
F_3 ( V_8 , V_28 , V_141 , 0x03 ) ;
V_117 -> V_139 = 0x2b ;
F_3 ( V_8 , V_126 , V_140 ,
V_117 -> V_139 ) ;
V_117 -> V_137 = V_117 -> V_137 | V_161 ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
F_3 ( V_8 , V_126 , V_162 , 0x01 ) ;
F_3 ( V_8 , V_126 , V_163 , 0x00 ) ;
V_117 -> V_137 = V_117 -> V_137 & ~ V_161 ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
return 0 ;
}
static int F_103 ( struct V_111 * V_112 , int V_164 , int * V_165 )
{
int V_145 ;
T_1 V_166 ;
T_1 V_167 ;
T_1 V_168 ;
F_20 ( & V_112 -> V_12 , L_35 , V_45 , V_164 ) ;
for ( V_145 = 0 ; V_145 < F_104 ( V_169 ) ; V_145 ++ ) {
if ( V_169 [ V_145 ] . V_164 == V_164 ) {
* V_165 = V_169 [ V_145 ] . V_165 ;
return 0 ;
}
}
if ( V_164 > 75 && V_164 < 230400 ) {
V_166 = ( T_1 ) ( 230400L / V_164 ) ;
V_167 = ( T_1 ) ( 2304000L / V_164 ) ;
V_168 = ( T_1 ) ( V_167 - ( V_166 * 10 ) ) ;
if ( V_168 > 4 )
V_166 ++ ;
* V_165 = V_166 ;
F_20 ( & V_112 -> V_12 , L_36 , V_164 , V_166 ) ;
return 0 ;
}
F_20 ( & V_112 -> V_12 , L_37 ) ;
return - V_160 ;
}
static int F_105 ( struct V_116 * V_117 ,
int V_164 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_165 ;
int V_18 ;
unsigned char V_170 ;
if ( V_117 == NULL )
return - 1 ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
V_170 = V_112 -> V_126 ;
F_20 ( & V_112 -> V_12 , L_38 , V_45 , V_164 ) ;
V_18 = F_103 ( V_112 , V_164 , & V_165 ) ;
if ( V_18 ) {
F_6 ( & V_112 -> V_12 , L_39 , V_45 ) ;
return V_18 ;
}
V_117 -> V_137 = V_117 -> V_137 | V_161 ;
F_3 ( V_8 , V_170 , V_138 , V_117 -> V_137 ) ;
F_3 ( V_8 , V_170 , V_162 , ( T_2 ) ( V_165 & 0xff ) ) ;
F_3 ( V_8 , V_170 , V_163 ,
( T_2 ) ( ( V_165 & 0xff00 ) >> 8 ) ) ;
V_117 -> V_137 = V_117 -> V_137 & ~ V_161 ;
F_3 ( V_8 , V_170 , V_138 , V_117 -> V_137 ) ;
return V_18 ;
}
static void F_106 ( struct V_123 * V_124 ,
struct V_116 * V_117 ,
struct V_171 * V_172 )
{
struct V_111 * V_112 ;
struct V_7 * V_8 ;
int V_158 ;
unsigned V_173 ;
unsigned V_174 ;
T_2 V_71 = 0xff ;
T_2 V_175 ;
T_2 V_176 ;
T_2 V_177 ;
int V_18 ;
int V_126 ;
if ( V_117 == NULL )
return ;
V_112 = V_117 -> V_112 ;
V_8 = V_112 -> V_8 ;
V_126 = V_112 -> V_126 ;
if ( ! V_117 -> V_118 ) {
F_20 ( & V_112 -> V_12 , L_33 , V_45 ) ;
return;
}
V_175 = V_178 ;
V_177 = 0x00 ;
V_176 = 0x00 ;
V_173 = V_124 -> V_179 . V_180 ;
V_174 = V_124 -> V_179 . V_181 ;
switch ( V_173 & V_182 ) {
case V_183 :
V_175 = V_184 ;
V_71 = 0x1f ;
break;
case V_185 :
V_175 = V_186 ;
V_71 = 0x3f ;
break;
case V_187 :
V_175 = V_188 ;
V_71 = 0x7f ;
break;
default:
case V_189 :
V_175 = V_178 ;
break;
}
if ( V_173 & V_190 ) {
if ( V_173 & V_191 ) {
V_176 = V_192 ;
F_20 ( & V_112 -> V_12 , L_40 , V_45 ) ;
} else {
V_176 = ( V_193 | V_192 ) ;
F_20 ( & V_112 -> V_12 , L_41 , V_45 ) ;
}
} else {
F_20 ( & V_112 -> V_12 , L_42 , V_45 ) ;
}
if ( V_173 & V_194 )
V_176 = V_176 | 0x20 ;
if ( V_173 & V_195 ) {
V_177 = V_196 ;
F_20 ( & V_112 -> V_12 , L_43 , V_45 ) ;
} else {
V_177 = 0x00 ;
F_20 ( & V_112 -> V_12 , L_44 , V_45 ) ;
}
#define F_107 0x03
#define F_108 0x04
#define F_109 0x38
V_117 -> V_137 &=
~ ( F_107 | F_108 | F_109 ) ;
V_117 -> V_137 |= ( V_175 | V_176 | V_177 ) ;
F_3 ( V_8 , V_126 , V_135 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0x00 ) ;
F_3 ( V_8 , V_126 , V_136 , 0xcf ) ;
F_3 ( V_8 , V_126 , V_138 ,
V_117 -> V_137 ) ;
V_117 -> V_139 = 0x0b ;
F_3 ( V_8 , V_126 , V_140 ,
V_117 -> V_139 ) ;
V_117 -> V_139 = V_143 ;
if ( V_173 & V_197 )
V_117 -> V_139 |= ( V_198 | V_156 ) ;
if ( V_173 & V_199 ) {
V_117 -> V_139 |= ( V_200 ) ;
if ( V_126 )
F_3 ( V_8 , V_28 , V_141 ,
0x01 ) ;
else
F_3 ( V_8 , V_28 , V_141 ,
0x02 ) ;
} else
V_117 -> V_139 &= ~ ( V_200 ) ;
F_3 ( V_8 , V_126 , V_140 ,
V_117 -> V_139 ) ;
V_158 = F_110 ( V_124 ) ;
if ( ! V_158 ) {
F_20 ( & V_112 -> V_12 , L_45 ) ;
V_158 = 9600 ;
}
if ( V_158 >= 230400 ) {
F_102 ( V_117 , V_158 ) ;
F_3 ( V_8 , V_126 , V_135 , 0x0c ) ;
return;
}
F_20 ( & V_112 -> V_12 , L_46 , V_45 , V_158 ) ;
V_18 = F_105 ( V_117 , V_158 ) ;
if ( V_173 & V_197 )
F_111 ( V_124 , V_158 , V_158 ) ;
F_3 ( V_8 , V_126 , V_135 , 0x0c ) ;
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_18 = F_29 ( V_112 -> V_114 , V_21 ) ;
if ( V_18 )
F_20 ( & V_112 -> V_12 , L_47 , V_18 ) ;
}
}
static void F_112 ( struct V_123 * V_124 ,
struct V_111 * V_112 , struct V_171 * V_172 )
{
int V_18 ;
unsigned int V_173 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_20 ( & V_112 -> V_12 , L_33 , V_45 ) ;
return;
}
F_20 ( & V_112 -> V_12 , L_48 ) ;
V_173 = V_124 -> V_179 . V_180 ;
F_20 ( & V_112 -> V_12 , L_49 , V_45 ,
V_124 -> V_179 . V_180 , F_113 ( V_124 -> V_179 . V_181 ) ) ;
F_20 ( & V_112 -> V_12 , L_50 , V_45 ,
V_172 -> V_180 , F_113 ( V_172 -> V_181 ) ) ;
F_106 ( V_124 , V_117 , V_172 ) ;
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_18 = F_29 ( V_112 -> V_114 , V_21 ) ;
if ( V_18 )
F_20 ( & V_112 -> V_12 , L_47 , V_18 ) ;
}
}
static int F_114 ( struct V_123 * V_124 ,
struct V_116 * V_117 , unsigned int T_6 * V_17 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
unsigned int V_98 = 0 ;
unsigned char V_9 = 0 ;
int V_126 = V_112 -> V_126 ;
int V_150 ;
V_150 = F_86 ( V_124 ) ;
if ( V_150 == 0 ) {
F_7 ( V_112 -> V_8 , V_126 , V_133 , & V_9 ) ;
if ( ( V_9 & ( V_201 | V_202 ) )
== ( V_201 | V_202 ) ) {
F_20 ( & V_112 -> V_12 , L_51 , V_45 ) ;
V_98 = V_203 ;
}
}
if ( F_115 ( V_17 , & V_98 , sizeof( int ) ) )
return - V_204 ;
return 0 ;
}
static int F_116 ( struct V_123 * V_124 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 = F_84 ( V_112 ) ;
unsigned int V_98 = 0 ;
unsigned int V_205 ;
unsigned int V_206 ;
V_205 = V_117 -> V_139 ;
V_206 = V_117 -> V_207 ;
V_98 = ( ( V_205 & V_198 ) ? V_208 : 0 )
| ( ( V_205 & V_156 ) ? V_209 : 0 )
| ( ( V_206 & V_210 ) ? V_211 : 0 )
| ( ( V_206 & V_212 ) ? V_213 : 0 )
| ( ( V_206 & V_214 ) ? V_215 : 0 )
| ( ( V_206 & V_216 ) ? V_217 : 0 ) ;
return V_98 ;
}
static int F_117 ( struct V_123 * V_124 ,
unsigned int V_218 , unsigned int V_219 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 = F_84 ( V_112 ) ;
unsigned int V_205 ;
V_205 = V_117 -> V_139 ;
if ( V_218 & V_209 )
V_205 |= V_156 ;
if ( V_218 & V_208 )
V_205 |= V_198 ;
if ( V_218 & V_220 )
V_205 |= V_221 ;
if ( V_219 & V_209 )
V_205 &= ~ V_156 ;
if ( V_219 & V_208 )
V_205 &= ~ V_198 ;
if ( V_219 & V_220 )
V_205 &= ~ V_221 ;
V_117 -> V_139 = V_205 ;
F_3 ( V_112 -> V_8 , V_112 -> V_126 , V_140 ,
V_117 -> V_139 ) ;
return 0 ;
}
static int F_118 ( struct V_116 * V_117 , unsigned int V_222 ,
unsigned int T_6 * V_17 )
{
unsigned int V_205 ;
unsigned int V_223 ;
struct V_111 * V_112 ;
if ( V_117 == NULL )
return - 1 ;
V_112 = (struct V_111 * ) V_117 -> V_112 ;
V_205 = V_117 -> V_139 ;
if ( F_119 ( & V_223 , V_17 , sizeof( int ) ) )
return - V_204 ;
switch ( V_222 ) {
case V_224 :
if ( V_223 & V_209 )
V_205 |= V_156 ;
if ( V_223 & V_208 )
V_205 |= V_156 ;
if ( V_223 & V_220 )
V_205 |= V_221 ;
break;
case V_225 :
if ( V_223 & V_209 )
V_205 &= ~ V_156 ;
if ( V_223 & V_208 )
V_205 &= ~ V_156 ;
if ( V_223 & V_220 )
V_205 &= ~ V_221 ;
break;
}
V_117 -> V_139 = V_205 ;
F_3 ( V_112 -> V_8 , V_112 -> V_126 , V_140 ,
V_117 -> V_139 ) ;
return 0 ;
}
static int F_120 ( struct V_116 * V_117 ,
struct V_226 T_6 * V_227 )
{
struct V_226 V_39 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . type = V_228 ;
V_39 . line = V_117 -> V_112 -> V_229 ;
V_39 . V_112 = V_117 -> V_112 -> V_126 ;
V_39 . V_230 = 0 ;
V_39 . V_38 = V_231 | V_232 ;
V_39 . V_233 = V_130 * V_132 ;
V_39 . V_234 = 9600 ;
V_39 . V_235 = 5 * V_236 ;
V_39 . V_237 = 30 * V_236 ;
if ( F_115 ( V_227 , & V_39 , sizeof( * V_227 ) ) )
return - V_204 ;
return 0 ;
}
static int F_121 ( struct V_123 * V_124 ,
unsigned int V_222 , unsigned long V_223 )
{
struct V_111 * V_112 = V_124 -> V_144 ;
struct V_116 * V_117 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_59 ;
switch ( V_222 ) {
case V_238 :
F_20 ( & V_112 -> V_12 , L_52 , V_45 ) ;
return F_114 ( V_124 , V_117 ,
( unsigned int T_6 * ) V_223 ) ;
case V_224 :
case V_225 :
F_20 ( & V_112 -> V_12 , L_53 , V_45 ) ;
return F_118 ( V_117 , V_222 ,
( unsigned int T_6 * ) V_223 ) ;
case V_239 :
F_20 ( & V_112 -> V_12 , L_54 , V_45 ) ;
return F_120 ( V_117 ,
(struct V_226 T_6 * ) V_223 ) ;
}
return - V_240 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_10 * V_12 ;
char V_9 ;
T_5 V_119 ;
int V_37 ;
if ( V_8 -> V_241 < 2 || V_8 -> V_242 < 2 ) {
F_6 ( & V_8 -> V_93 -> V_12 , L_55 ) ;
return - V_59 ;
}
V_119 = F_82 ( V_8 -> V_12 -> V_120 . V_121 ) ;
V_12 = V_8 -> V_12 ;
if ( V_119 == V_122 ) {
struct V_111 * V_39 = V_8 -> V_112 [ 0 ] ;
V_8 -> V_112 [ 0 ] = V_8 -> V_112 [ 1 ] ;
V_8 -> V_112 [ 1 ] = V_39 ;
V_8 -> V_112 [ 0 ] -> V_243 = V_39 -> V_243 ;
V_8 -> V_112 [ 0 ] -> V_244 = V_39 -> V_244 ;
V_8 -> V_112 [ 0 ] -> V_245 =
V_39 -> V_245 ;
V_8 -> V_112 [ 1 ] -> V_243 = NULL ;
V_8 -> V_112 [ 1 ] -> V_244 = NULL ;
if ( V_8 -> V_112 [ 0 ] -> V_243 ) {
struct V_34 * V_34 = V_8 -> V_112 [ 0 ] -> V_243 ;
V_34 -> F_45 = F_73 ;
}
}
F_5 ( V_8 -> V_12 , F_4 ( V_8 -> V_12 , 0 ) ,
( T_2 ) 0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 , 5000 ) ;
#ifdef F_74
if ( V_119 == V_122 ) {
V_37 = F_64 ( V_8 ) ;
if ( V_37 < 0 )
return V_37 ;
}
#endif
V_37 = F_29 ( V_8 -> V_112 [ 0 ] -> V_243 , V_21 ) ;
if ( V_37 ) {
F_6 ( & V_12 -> V_12 , L_56 ,
V_37 ) ;
}
F_7 ( V_8 , 0 , V_133 , & V_9 ) ;
F_20 ( & V_12 -> V_12 , L_57 , V_9 ) ;
return 0 ;
}
static void F_123 ( struct V_7 * V_8 )
{
F_88 ( V_8 -> V_112 [ 0 ] -> V_243 ) ;
#ifdef F_74
if ( F_82 ( V_8 -> V_12 -> V_120 . V_121 )
== V_122 ) {
struct V_32 * V_33 ;
unsigned long V_38 ;
struct V_23 * V_24 =
F_124 ( V_8 ) ;
F_32 ( & V_62 ) ;
V_24 -> V_61 -> V_63 = NULL ;
F_33 ( & V_62 ) ;
if ( V_24 -> V_64 )
F_125 ( & V_24 -> V_65 ,
F_126 ( V_19 ) ) ;
F_127 ( V_24 -> V_61 ) ;
F_67 ( V_8 , NULL ) ;
V_24 -> V_8 = NULL ;
F_128 ( & V_24 -> V_46 ) ;
F_23 ( & V_24 -> V_48 , V_38 ) ;
F_129 (urbtrack,
&mos_parport->active_urbs,
urblist_entry)
F_130 ( V_33 -> V_34 ) ;
F_25 ( & V_24 -> V_48 , V_38 ) ;
F_131 ( V_24 -> V_61 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
}
#endif
}
static int F_132 ( struct V_111 * V_112 )
{
struct V_116 * V_117 ;
V_117 = F_65 ( sizeof( * V_117 ) , V_21 ) ;
if ( ! V_117 )
return - V_22 ;
V_117 -> V_112 = V_112 ;
F_133 ( V_112 , V_117 ) ;
return 0 ;
}
static int F_134 ( struct V_111 * V_112 )
{
struct V_116 * V_117 ;
V_117 = F_84 ( V_112 ) ;
F_10 ( V_117 ) ;
return 0 ;
}
