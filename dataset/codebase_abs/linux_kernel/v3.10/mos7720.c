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
F_3 ( V_24 -> V_8 , V_28 , V_29 , V_24 -> V_27 ) ;
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
F_10 ( V_33 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
}
static void F_17 ( unsigned long V_35 )
{
int V_36 ;
unsigned long V_37 ;
struct V_23 * V_24 = ( void * ) V_35 ;
struct V_32 * V_33 , * V_38 ;
struct V_39 * V_40 , * V_41 ;
struct V_42 * V_12 ;
if ( F_18 ( V_24 -> V_8 == NULL ) )
return;
V_12 = & V_24 -> V_8 -> V_12 -> V_12 ;
if ( ! F_19 ( & V_24 -> V_8 -> V_43 ) ) {
F_20 ( V_12 , L_2 , V_44 ) ;
F_21 ( & V_24 -> V_45 ) ;
return;
}
if ( F_18 ( V_24 -> V_8 -> V_46 ) ) {
F_22 ( & V_24 -> V_8 -> V_43 ) ;
return;
}
F_23 ( & V_24 -> V_47 , V_37 ) ;
if ( F_24 ( & V_24 -> V_48 ) ) {
F_25 ( & V_24 -> V_47 , V_37 ) ;
F_22 ( & V_24 -> V_8 -> V_43 ) ;
F_20 ( V_12 , L_3 , V_44 ) ;
return;
}
F_26 (cursor, next, &mos_parport->deferred_urbs)
F_27 ( V_40 , & V_24 -> V_49 ) ;
F_28 (urbtrack, tmp, &mos_parport->active_urbs,
urblist_entry) {
V_36 = F_29 ( V_33 -> V_34 , V_50 ) ;
F_20 ( V_12 , L_4 , V_44 ) ;
if ( V_36 ) {
F_6 ( V_12 , L_5 , V_36 ) ;
F_30 ( & V_33 -> V_51 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
}
}
F_25 ( & V_24 -> V_47 , V_37 ) ;
F_22 ( & V_24 -> V_8 -> V_43 ) ;
}
static void F_31 ( struct V_34 * V_34 )
{
struct V_32 * V_33 = V_34 -> V_52 ;
int V_18 = V_34 -> V_18 ;
if ( F_18 ( V_18 ) )
F_20 ( & V_34 -> V_12 -> V_12 , L_6 , V_44 , V_18 ) ;
F_32 ( & V_33 -> V_24 -> V_47 ) ;
F_30 ( & V_33 -> V_51 ) ;
F_33 ( & V_33 -> V_24 -> V_47 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
}
static int F_34 ( struct V_23 * V_24 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_32 * V_33 ;
int V_36 ;
unsigned long V_37 ;
struct V_53 V_54 ;
struct V_7 * V_8 = V_24 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
V_33 = F_9 ( sizeof( struct V_32 ) , V_50 ) ;
if ( V_33 == NULL ) {
F_6 ( & V_11 -> V_12 , L_7 ) ;
return - V_22 ;
}
F_35 ( & V_24 -> V_31 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_34 = F_36 ( 0 , V_50 ) ;
if ( V_33 -> V_34 == NULL ) {
F_6 ( & V_11 -> V_12 , L_8 ) ;
F_10 ( V_33 ) ;
return - V_22 ;
}
V_54 . V_55 = ( T_2 ) 0x40 ;
V_54 . V_56 = ( T_2 ) 0x0e ;
V_54 . V_57 = F_2 ( V_2 , V_28 ) ;
V_54 . V_58 = F_1 ( V_2 ) ;
V_54 . V_59 = 0 ;
F_37 ( V_33 -> V_34 , V_11 ,
F_4 ( V_11 , 0 ) ,
( unsigned char * ) & V_54 ,
NULL , 0 , F_31 , V_33 ) ;
F_38 ( & V_33 -> V_31 ) ;
F_39 ( & V_33 -> V_51 ) ;
if ( ! F_19 ( & V_8 -> V_43 ) ) {
F_23 ( & V_24 -> V_47 , V_37 ) ;
F_40 ( & V_33 -> V_51 ,
& V_24 -> V_48 ) ;
F_25 ( & V_24 -> V_47 , V_37 ) ;
F_21 ( & V_24 -> V_45 ) ;
F_20 ( & V_11 -> V_12 , L_9 ) ;
return 0 ;
}
if ( V_8 -> V_46 ) {
F_16 ( & V_33 -> V_31 , F_14 ) ;
F_22 ( & V_8 -> V_43 ) ;
return - V_60 ;
}
F_23 ( & V_24 -> V_47 , V_37 ) ;
F_40 ( & V_33 -> V_51 , & V_24 -> V_49 ) ;
F_25 ( & V_24 -> V_47 , V_37 ) ;
V_36 = F_29 ( V_33 -> V_34 , V_50 ) ;
F_22 ( & V_8 -> V_43 ) ;
if ( V_36 ) {
F_6 ( & V_11 -> V_12 ,
L_10 , V_44 , V_36 ) ;
F_23 ( & V_24 -> V_47 , V_37 ) ;
F_30 ( & V_33 -> V_51 ) ;
F_25 ( & V_24 -> V_47 , V_37 ) ;
F_16 ( & V_33 -> V_31 , F_14 ) ;
return V_36 ;
}
return 0 ;
}
static int F_41 ( struct V_61 * V_62 )
{
struct V_23 * V_24 ;
F_32 ( & V_63 ) ;
V_24 = V_62 -> V_64 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_63 ) ;
return - 1 ;
}
V_24 -> V_65 = true ;
F_42 ( V_24 -> V_66 ) ;
F_33 ( & V_63 ) ;
F_43 ( & V_24 -> V_8 -> V_43 ) ;
if ( V_24 -> V_8 -> V_46 ) {
F_22 ( & V_24 -> V_8 -> V_43 ) ;
V_24 -> V_65 = false ;
F_44 ( & V_24 -> V_66 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_45 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
F_22 ( & V_24 -> V_8 -> V_43 ) ;
V_24 -> V_65 = false ;
F_44 ( & V_24 -> V_66 ) ;
}
static void F_46 ( struct V_61 * V_62 , unsigned char V_67 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
if ( F_41 ( V_62 ) < 0 )
return;
F_11 ( V_24 , V_68 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_6 , ( T_2 ) V_67 ) ;
F_45 ( V_62 ) ;
}
static unsigned char F_47 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
unsigned char V_67 ;
if ( F_41 ( V_62 ) < 0 )
return 0 ;
F_7 ( V_24 -> V_8 , V_28 , V_6 , & V_67 ) ;
F_45 ( V_62 ) ;
return V_67 ;
}
static void F_48 ( struct V_61 * V_62 , unsigned char V_67 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
T_2 V_9 ;
if ( F_41 ( V_62 ) < 0 )
return;
V_9 = ( ( T_2 ) V_67 & 0x0f ) | ( V_24 -> V_69 & 0xf0 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_70 , V_9 ) ;
V_24 -> V_69 = V_9 ;
F_45 ( V_62 ) ;
}
static unsigned char F_49 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
T_2 V_71 ;
F_32 ( & V_63 ) ;
V_24 = V_62 -> V_64 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_63 ) ;
return 0 ;
}
V_71 = V_24 -> V_69 & 0x0f ;
F_33 ( & V_63 ) ;
return V_71 ;
}
static unsigned char F_50 ( struct V_61 * V_62 ,
unsigned char V_72 ,
unsigned char V_73 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
T_2 V_71 ;
V_72 &= 0x0f ;
V_73 &= 0x0f ;
if ( F_41 ( V_62 ) < 0 )
return 0 ;
V_24 -> V_69 = ( V_24 -> V_69 & ( ~ V_72 ) ) ^ V_73 ;
F_3 ( V_24 -> V_8 , V_28 , V_70 , V_24 -> V_69 ) ;
V_71 = V_24 -> V_69 & 0x0f ;
F_45 ( V_62 ) ;
return V_71 ;
}
static unsigned char F_51 ( struct V_61 * V_62 )
{
unsigned char V_18 ;
struct V_23 * V_24 = V_62 -> V_64 ;
F_32 ( & V_63 ) ;
V_24 = V_62 -> V_64 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_63 ) ;
return 0 ;
}
V_18 = F_52 ( & V_24 -> V_74 ) & 0xf8 ;
F_33 ( & V_63 ) ;
return V_18 ;
}
static void F_53 ( struct V_61 * V_62 )
{
}
static void F_54 ( struct V_61 * V_62 )
{
}
static void F_55 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
if ( F_41 ( V_62 ) < 0 )
return;
F_11 ( V_24 , V_75 ) ;
V_24 -> V_69 &= ~ 0x20 ;
F_3 ( V_24 -> V_8 , V_28 , V_70 , V_24 -> V_69 ) ;
F_45 ( V_62 ) ;
}
static void F_56 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = V_62 -> V_64 ;
if ( F_41 ( V_62 ) < 0 )
return;
F_11 ( V_24 , V_75 ) ;
V_24 -> V_69 |= 0x20 ;
F_3 ( V_24 -> V_8 , V_28 , V_70 , V_24 -> V_69 ) ;
F_45 ( V_62 ) ;
}
static void F_57 ( struct V_76 * V_12 ,
struct V_77 * V_78 )
{
V_78 -> V_79 . V_80 . V_81 = V_82 ;
V_78 -> V_79 . V_80 . V_83 = V_84 ;
}
static void F_58 ( struct V_61 * V_62 ,
struct V_77 * V_78 )
{
struct V_23 * V_24 ;
F_32 ( & V_63 ) ;
V_24 = V_62 -> V_64 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_63 ) ;
return;
}
V_78 -> V_79 . V_80 . V_81 = V_24 -> V_69 ;
V_78 -> V_79 . V_80 . V_83 = V_24 -> V_27 ;
F_33 ( & V_63 ) ;
}
static void F_59 ( struct V_61 * V_62 ,
struct V_77 * V_78 )
{
struct V_23 * V_24 ;
F_32 ( & V_63 ) ;
V_24 = V_62 -> V_64 ;
if ( F_18 ( V_24 == NULL ) ) {
F_33 ( & V_63 ) ;
return;
}
F_34 ( V_24 , V_70 , V_24 -> V_69 ) ;
F_34 ( V_24 , V_29 , V_24 -> V_27 ) ;
F_33 ( & V_63 ) ;
}
static T_4 F_60 ( struct V_61 * V_62 ,
const void * V_85 ,
T_4 V_86 , int V_37 )
{
int V_87 ;
struct V_23 * V_24 = V_62 -> V_64 ;
int V_88 ;
if ( F_41 ( V_62 ) < 0 )
return 0 ;
F_11 ( V_24 , V_89 ) ;
V_87 = F_61 ( V_24 -> V_8 -> V_12 ,
F_62 ( V_24 -> V_8 -> V_12 , 2 ) ,
( void * ) V_85 , V_86 , & V_88 ,
V_19 ) ;
F_45 ( V_62 ) ;
if ( V_87 ) {
F_6 ( & V_24 -> V_8 -> V_12 -> V_12 ,
L_11 , V_87 ) ;
return 0 ;
}
return V_88 ;
}
static int F_63 ( struct V_7 * V_8 )
{
struct V_23 * V_24 ;
V_24 = F_64 ( sizeof( struct V_23 ) , V_21 ) ;
if ( V_24 == NULL ) {
F_20 ( & V_8 -> V_12 -> V_12 , L_12 , V_44 ) ;
return - V_22 ;
}
V_24 -> V_65 = false ;
F_38 ( & V_24 -> V_31 ) ;
F_65 ( & V_24 -> V_47 ) ;
F_39 ( & V_24 -> V_49 ) ;
F_39 ( & V_24 -> V_48 ) ;
F_66 ( V_8 , V_24 ) ;
V_24 -> V_8 = V_8 ;
F_67 ( & V_24 -> V_45 , F_17 ,
( unsigned long ) V_24 ) ;
F_68 ( & V_24 -> V_66 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_90 , ( T_2 ) 0x80 ) ;
F_3 ( V_24 -> V_8 , V_28 , V_90 , ( T_2 ) 0x00 ) ;
V_24 -> V_69 = V_82 ;
F_3 ( V_24 -> V_8 , V_28 , V_70 , V_24 -> V_69 ) ;
V_24 -> V_27 = V_84 ;
F_3 ( V_24 -> V_8 , V_28 , V_29 , V_24 -> V_27 ) ;
V_24 -> V_62 = F_69 ( 0 , V_91 ,
V_92 ,
& V_93 ) ;
if ( V_24 -> V_62 == NULL ) {
F_6 ( & V_8 -> V_94 -> V_12 ,
L_13 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
return - V_95 ;
}
V_24 -> V_62 -> V_64 = V_24 ;
V_24 -> V_62 -> V_96 = V_97 | V_98 ;
V_24 -> V_62 -> V_12 = & V_8 -> V_94 -> V_12 ;
F_70 ( V_24 -> V_62 ) ;
return 0 ;
}
static void F_71 ( struct V_34 * V_34 )
{
int V_99 ;
int V_100 ;
int V_18 = V_34 -> V_18 ;
struct V_42 * V_12 = & V_34 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_101 ;
T_2 V_102 ;
switch ( V_18 ) {
case 0 :
break;
case - V_103 :
case - V_104 :
case - V_105 :
F_20 ( V_12 , L_14 , V_44 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_44 , V_18 ) ;
goto exit;
}
V_100 = V_34 -> V_106 ;
V_9 = V_34 -> V_107 ;
if ( F_18 ( V_100 != 4 ) ) {
F_20 ( V_12 , L_15 ) ;
return;
}
V_101 = V_9 [ 3 ] ;
V_102 = V_9 [ 2 ] ;
if ( ( V_101 | V_102 ) & 0x01 ) {
F_20 ( V_12 , L_16 ) ;
} else {
switch ( V_101 & 0x0f ) {
case V_108 :
F_20 ( V_12 , L_17 ) ;
break;
case V_109 :
F_20 ( V_12 , L_18 ) ;
break;
case V_110 :
break;
}
switch ( V_102 & 0x0f ) {
case V_108 :
F_20 ( V_12 , L_19 ) ;
break;
case V_109 :
F_20 ( V_12 , L_20 ) ;
break;
case V_110 :
break;
}
}
exit:
V_99 = F_29 ( V_34 , V_50 ) ;
if ( V_99 )
F_6 ( V_12 , L_21 , V_44 , V_99 ) ;
}
static void F_72 ( struct V_34 * V_34 )
{
int V_99 ;
int V_100 ;
int V_18 = V_34 -> V_18 ;
struct V_42 * V_12 = & V_34 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_111 ;
switch ( V_18 ) {
case 0 :
break;
case - V_103 :
case - V_104 :
case - V_105 :
case - V_60 :
F_20 ( V_12 , L_14 , V_44 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_44 , V_18 ) ;
goto exit;
}
V_100 = V_34 -> V_106 ;
V_9 = V_34 -> V_107 ;
if ( F_18 ( V_100 != 4 ) ) {
F_20 ( V_12 , L_15 ) ;
return;
}
V_111 = V_9 [ 0 ] ;
if ( ! ( V_111 & 0x01 ) ) {
switch ( V_111 & 0x0f ) {
case V_108 :
F_20 ( V_12 , L_22 ) ;
break;
case V_109 :
F_20 ( V_12 , L_23 ) ;
break;
case V_110 :
break;
}
}
#ifdef F_73
{
struct V_112 * V_113 = V_34 -> V_52 ;
struct V_23 * V_24 = V_113 -> V_8 -> V_114 ;
if ( F_18 ( V_24 == NULL ) )
return;
F_74 ( & V_24 -> V_74 , V_9 [ 2 ] ) ;
}
#endif
exit:
V_99 = F_29 ( V_34 , V_50 ) ;
if ( V_99 )
F_6 ( V_12 , L_21 , V_44 , V_99 ) ;
}
static void F_75 ( struct V_34 * V_34 )
{
int V_87 ;
unsigned char * V_9 ;
struct V_112 * V_113 ;
int V_18 = V_34 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_24 , V_18 ) ;
return;
}
V_113 = V_34 -> V_52 ;
F_20 ( & V_113 -> V_12 , L_25 , V_44 ) ;
V_9 = V_34 -> V_107 ;
if ( V_34 -> V_106 ) {
F_76 ( & V_113 -> V_113 , V_9 , V_34 -> V_106 ) ;
F_77 ( & V_113 -> V_113 ) ;
}
if ( V_113 -> V_115 -> V_18 != - V_116 ) {
V_87 = F_29 ( V_113 -> V_115 , V_50 ) ;
if ( V_87 )
F_20 ( & V_113 -> V_12 , L_26 , V_87 ) ;
}
}
static void F_78 ( struct V_34 * V_34 )
{
struct V_117 * V_118 ;
int V_18 = V_34 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_27 , V_18 ) ;
return;
}
V_118 = V_34 -> V_52 ;
if ( ! V_118 ) {
F_20 ( & V_34 -> V_12 -> V_12 , L_28 ) ;
return ;
}
if ( V_118 -> V_119 )
F_79 ( & V_118 -> V_113 -> V_113 ) ;
}
static int F_80 ( struct V_7 * V_8 ,
const struct V_120 * V_121 )
{
if ( V_121 -> V_122 == V_123 )
V_124 . V_125 =
F_72 ;
else
V_124 . V_125 =
F_71 ;
return 0 ;
}
static int F_81 ( struct V_7 * V_8 )
{
T_5 V_126 = F_82 ( V_8 -> V_12 -> V_127 . V_122 ) ;
if ( V_126 == V_123 )
return 1 ;
return 2 ;
}
static int F_83 ( struct V_128 * V_129 , struct V_112 * V_113 )
{
struct V_7 * V_8 ;
struct V_34 * V_34 ;
struct V_117 * V_118 ;
int V_130 ;
int V_131 ;
T_2 V_9 ;
int V_132 = 0 ;
int V_133 ;
V_8 = V_113 -> V_8 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return - V_60 ;
F_85 ( V_8 -> V_12 , V_113 -> V_134 -> V_13 ) ;
F_85 ( V_8 -> V_12 , V_113 -> V_115 -> V_13 ) ;
for ( V_133 = 0 ; V_133 < V_135 ; ++ V_133 ) {
V_34 = F_36 ( 0 , V_21 ) ;
V_118 -> V_136 [ V_133 ] = V_34 ;
if ( V_34 == NULL ) {
F_6 ( & V_113 -> V_12 , L_29 ) ;
continue;
}
V_34 -> V_107 = F_9 ( V_137 ,
V_21 ) ;
if ( ! V_34 -> V_107 ) {
F_6 ( & V_113 -> V_12 ,
L_30 ,
V_44 ) ;
F_15 ( V_118 -> V_136 [ V_133 ] ) ;
V_118 -> V_136 [ V_133 ] = NULL ;
continue;
}
V_132 ++ ;
}
if ( ! V_132 )
return - V_22 ;
V_131 = V_113 -> V_138 - V_113 -> V_8 -> V_139 ;
F_7 ( V_8 , V_131 , V_140 , & V_9 ) ;
F_20 ( & V_113 -> V_12 , L_31 , V_118 , V_9 ) ;
F_3 ( V_8 , V_28 , V_5 , 0x02 ) ;
F_3 ( V_8 , V_28 , V_141 , 0x02 ) ;
F_3 ( V_8 , V_131 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0xcf ) ;
V_118 -> V_144 = 0x03 ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
V_118 -> V_146 = 0x0b ;
F_3 ( V_8 , V_131 , V_147 , V_118 -> V_146 ) ;
F_3 ( V_8 , V_131 , V_148 , 0x00 ) ;
F_7 ( V_8 , V_28 , V_148 , & V_9 ) ;
V_9 = V_9 | ( V_113 -> V_138 - V_113 -> V_8 -> V_139 + 1 ) ;
F_3 ( V_8 , V_28 , V_148 , V_9 ) ;
V_118 -> V_144 = 0x83 ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
F_3 ( V_8 , V_131 , V_149 , 0x0c ) ;
F_3 ( V_8 , V_131 , V_142 , 0x00 ) ;
V_118 -> V_144 = 0x03 ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
F_3 ( V_8 , V_131 , V_142 , 0x0c ) ;
V_130 = F_29 ( V_113 -> V_115 , V_21 ) ;
if ( V_130 )
F_6 ( & V_113 -> V_12 , L_32 ,
V_44 , V_130 ) ;
V_118 -> V_146 = V_150 ;
V_118 -> V_119 = 1 ;
return 0 ;
}
static int F_86 ( struct V_128 * V_129 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
int V_152 ;
int V_153 = 0 ;
struct V_117 * V_118 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return 0 ;
for ( V_152 = 0 ; V_152 < V_135 ; ++ V_152 ) {
if ( V_118 -> V_136 [ V_152 ] &&
V_118 -> V_136 [ V_152 ] -> V_18 == - V_116 )
V_153 += V_137 ;
}
F_20 ( & V_113 -> V_12 , L_33 , V_44 , V_153 ) ;
return V_153 ;
}
static void F_87 ( struct V_112 * V_113 )
{
struct V_7 * V_8 ;
struct V_117 * V_118 ;
int V_133 ;
V_8 = V_113 -> V_8 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return;
for ( V_133 = 0 ; V_133 < V_135 ; ++ V_133 )
F_88 ( V_118 -> V_136 [ V_133 ] ) ;
for ( V_133 = 0 ; V_133 < V_135 ; ++ V_133 ) {
if ( V_118 -> V_136 [ V_133 ] ) {
F_10 ( V_118 -> V_136 [ V_133 ] -> V_107 ) ;
F_15 ( V_118 -> V_136 [ V_133 ] ) ;
}
}
F_88 ( V_113 -> V_134 ) ;
F_88 ( V_113 -> V_115 ) ;
F_3 ( V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 , V_147 , 0x00 ) ;
F_3 ( V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 , V_142 , 0x00 ) ;
V_118 -> V_119 = 0 ;
}
static void F_89 ( struct V_128 * V_129 , int V_154 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
unsigned char V_9 ;
struct V_7 * V_8 ;
struct V_117 * V_118 ;
V_8 = V_113 -> V_8 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return;
if ( V_154 == - 1 )
V_9 = V_118 -> V_144 | V_155 ;
else
V_9 = V_118 -> V_144 & ~ V_155 ;
V_118 -> V_144 = V_9 ;
F_3 ( V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 ,
V_145 , V_118 -> V_144 ) ;
}
static int F_90 ( struct V_128 * V_129 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 ;
int V_156 = 0 ;
int V_152 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return - V_60 ;
for ( V_152 = 0 ; V_152 < V_135 ; ++ V_152 ) {
if ( V_118 -> V_136 [ V_152 ] &&
V_118 -> V_136 [ V_152 ] -> V_18 != - V_116 )
V_156 += V_137 ;
}
F_20 ( & V_113 -> V_12 , L_33 , V_44 , V_156 ) ;
return V_156 ;
}
static int F_91 ( struct V_128 * V_129 , struct V_112 * V_113 ,
const unsigned char * V_9 , int V_157 )
{
int V_18 ;
int V_152 ;
int V_158 = 0 ;
int V_159 ;
struct V_117 * V_118 ;
struct V_7 * V_8 ;
struct V_34 * V_34 ;
const unsigned char * V_160 = V_9 ;
V_8 = V_113 -> V_8 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return - V_60 ;
V_34 = NULL ;
for ( V_152 = 0 ; V_152 < V_135 ; ++ V_152 ) {
if ( V_118 -> V_136 [ V_152 ] &&
V_118 -> V_136 [ V_152 ] -> V_18 != - V_116 ) {
V_34 = V_118 -> V_136 [ V_152 ] ;
F_20 ( & V_113 -> V_12 , L_34 , V_152 ) ;
break;
}
}
if ( V_34 == NULL ) {
F_20 ( & V_113 -> V_12 , L_35 , V_44 ) ;
goto exit;
}
if ( V_34 -> V_107 == NULL ) {
V_34 -> V_107 = F_9 ( V_137 ,
V_21 ) ;
if ( V_34 -> V_107 == NULL ) {
F_92 ( V_113 , L_36 ,
V_44 ) ;
goto exit;
}
}
V_159 = F_93 ( V_157 , V_137 ) ;
memcpy ( V_34 -> V_107 , V_160 , V_159 ) ;
F_94 ( & V_113 -> V_12 , V_44 , V_159 ,
V_34 -> V_107 ) ;
F_95 ( V_34 , V_8 -> V_12 ,
F_62 ( V_8 -> V_12 ,
V_113 -> V_161 ) ,
V_34 -> V_107 , V_159 ,
F_78 , V_118 ) ;
V_18 = F_29 ( V_34 , V_50 ) ;
if ( V_18 ) {
F_92 ( V_113 , L_37
L_38 , V_44 , V_18 ) ;
V_158 = V_18 ;
goto exit;
}
V_158 = V_159 ;
exit:
return V_158 ;
}
static void F_96 ( struct V_128 * V_129 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 ;
int V_18 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return;
if ( ! V_118 -> V_119 ) {
F_20 ( & V_113 -> V_12 , L_39 , V_44 ) ;
return;
}
if ( F_97 ( V_129 ) ) {
unsigned char V_162 = F_98 ( V_129 ) ;
V_18 = F_91 ( V_129 , V_113 , & V_162 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_129 -> V_163 . V_164 & V_165 ) {
V_118 -> V_146 &= ~ V_166 ;
F_3 ( V_113 -> V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 ,
V_147 , V_118 -> V_146 ) ;
if ( V_18 != 0 )
return;
}
}
static void F_99 ( struct V_128 * V_129 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 = F_84 ( V_113 ) ;
int V_18 ;
if ( V_118 == NULL )
return;
if ( ! V_118 -> V_119 ) {
F_20 ( & V_113 -> V_12 , L_39 , V_44 ) ;
return;
}
if ( F_97 ( V_129 ) ) {
unsigned char V_167 = F_100 ( V_129 ) ;
V_18 = F_91 ( V_129 , V_113 , & V_167 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_129 -> V_163 . V_164 & V_165 ) {
V_118 -> V_146 |= V_166 ;
F_3 ( V_113 -> V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 ,
V_147 , V_118 -> V_146 ) ;
if ( V_18 != 0 )
return;
}
}
static int F_101 ( struct V_117 * V_118 ,
unsigned int V_168 )
{
struct V_112 * V_113 ;
struct V_7 * V_8 ;
int V_131 ;
enum V_1 V_169 ;
if ( V_118 == NULL )
return - V_170 ;
V_113 = V_118 -> V_113 ;
V_8 = V_113 -> V_8 ;
F_20 ( & V_113 -> V_12 , L_40 ) ;
V_131 = V_113 -> V_138 - V_113 -> V_8 -> V_139 ;
F_3 ( V_8 , V_131 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0xcf ) ;
V_118 -> V_146 = 0x0b ;
F_3 ( V_8 , V_131 , V_147 , V_118 -> V_146 ) ;
F_3 ( V_8 , V_28 , V_148 , 0x00 ) ;
if ( V_131 == 0 )
V_169 = V_5 ;
else
V_169 = V_141 ;
F_3 ( V_8 , V_28 , V_169 , V_168 * 0x10 ) ;
F_3 ( V_8 , V_28 , V_148 , 0x03 ) ;
V_118 -> V_146 = 0x2b ;
F_3 ( V_8 , V_131 , V_147 , V_118 -> V_146 ) ;
V_118 -> V_144 = V_118 -> V_144 | V_171 ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
F_3 ( V_8 , V_131 , V_172 , 0x01 ) ;
F_3 ( V_8 , V_131 , V_173 , 0x00 ) ;
V_118 -> V_144 = V_118 -> V_144 & ~ V_171 ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
return 0 ;
}
static int F_102 ( struct V_112 * V_113 , int V_174 , int * V_175 )
{
int V_152 ;
T_1 V_176 ;
T_1 V_177 ;
T_1 V_178 ;
F_20 ( & V_113 -> V_12 , L_41 , V_44 , V_174 ) ;
for ( V_152 = 0 ; V_152 < F_103 ( V_179 ) ; V_152 ++ ) {
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
F_20 ( & V_113 -> V_12 , L_42 , V_174 , V_176 ) ;
return 0 ;
}
F_20 ( & V_113 -> V_12 , L_43 ) ;
return - V_170 ;
}
static int F_104 ( struct V_117 * V_118 ,
int V_174 )
{
struct V_112 * V_113 ;
struct V_7 * V_8 ;
int V_175 ;
int V_18 ;
unsigned char V_138 ;
if ( V_118 == NULL )
return - 1 ;
V_113 = V_118 -> V_113 ;
V_8 = V_113 -> V_8 ;
V_138 = V_113 -> V_138 - V_113 -> V_8 -> V_139 ;
F_20 ( & V_113 -> V_12 , L_44 , V_44 , V_174 ) ;
V_18 = F_102 ( V_113 , V_174 , & V_175 ) ;
if ( V_18 ) {
F_6 ( & V_113 -> V_12 , L_45 , V_44 ) ;
return V_18 ;
}
V_118 -> V_144 = V_118 -> V_144 | V_171 ;
F_3 ( V_8 , V_138 , V_145 , V_118 -> V_144 ) ;
F_3 ( V_8 , V_138 , V_172 , ( T_2 ) ( V_175 & 0xff ) ) ;
F_3 ( V_8 , V_138 , V_173 , ( T_2 ) ( ( V_175 & 0xff00 ) >> 8 ) ) ;
V_118 -> V_144 = V_118 -> V_144 & ~ V_171 ;
F_3 ( V_8 , V_138 , V_145 , V_118 -> V_144 ) ;
return V_18 ;
}
static void F_105 ( struct V_128 * V_129 ,
struct V_117 * V_118 ,
struct V_180 * V_181 )
{
struct V_112 * V_113 ;
struct V_7 * V_8 ;
int V_168 ;
unsigned V_182 ;
unsigned V_183 ;
T_2 V_72 = 0xff ;
T_2 V_184 ;
T_2 V_185 ;
T_2 V_186 ;
int V_18 ;
int V_131 ;
if ( V_118 == NULL )
return ;
V_113 = V_118 -> V_113 ;
V_8 = V_113 -> V_8 ;
V_131 = V_113 -> V_138 - V_113 -> V_8 -> V_139 ;
if ( ! V_118 -> V_119 ) {
F_20 ( & V_113 -> V_12 , L_39 , V_44 ) ;
return;
}
V_184 = V_187 ;
V_186 = 0x00 ;
V_185 = 0x00 ;
V_182 = V_129 -> V_163 . V_164 ;
V_183 = V_129 -> V_163 . V_188 ;
switch ( V_182 & V_189 ) {
case V_190 :
V_184 = V_191 ;
V_72 = 0x1f ;
break;
case V_192 :
V_184 = V_193 ;
V_72 = 0x3f ;
break;
case V_194 :
V_184 = V_195 ;
V_72 = 0x7f ;
break;
default:
case V_196 :
V_184 = V_187 ;
break;
}
if ( V_182 & V_197 ) {
if ( V_182 & V_198 ) {
V_185 = V_199 ;
F_20 ( & V_113 -> V_12 , L_46 , V_44 ) ;
} else {
V_185 = ( V_200 | V_199 ) ;
F_20 ( & V_113 -> V_12 , L_47 , V_44 ) ;
}
} else {
F_20 ( & V_113 -> V_12 , L_48 , V_44 ) ;
}
if ( V_182 & V_201 )
V_185 = V_185 | 0x20 ;
if ( V_182 & V_202 ) {
V_186 = V_203 ;
F_20 ( & V_113 -> V_12 , L_49 , V_44 ) ;
} else {
V_186 = 0x00 ;
F_20 ( & V_113 -> V_12 , L_50 , V_44 ) ;
}
#define F_106 0x03
#define F_107 0x04
#define F_108 0x38
V_118 -> V_144 &=
~ ( F_106 | F_107 | F_108 ) ;
V_118 -> V_144 |= ( V_184 | V_185 | V_186 ) ;
F_3 ( V_8 , V_131 , V_142 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0x00 ) ;
F_3 ( V_8 , V_131 , V_143 , 0xcf ) ;
F_3 ( V_8 , V_131 , V_145 , V_118 -> V_144 ) ;
V_118 -> V_146 = 0x0b ;
F_3 ( V_8 , V_131 , V_147 , V_118 -> V_146 ) ;
V_118 -> V_146 = V_150 ;
if ( V_182 & V_204 )
V_118 -> V_146 |= ( V_205 | V_166 ) ;
if ( V_182 & V_165 ) {
V_118 -> V_146 |= ( V_206 ) ;
if ( V_131 )
F_3 ( V_8 , V_28 , V_148 , 0x01 ) ;
else
F_3 ( V_8 , V_28 , V_148 , 0x02 ) ;
} else
V_118 -> V_146 &= ~ ( V_206 ) ;
F_3 ( V_8 , V_131 , V_147 , V_118 -> V_146 ) ;
V_168 = F_109 ( V_129 ) ;
if ( ! V_168 ) {
F_20 ( & V_113 -> V_12 , L_51 ) ;
V_168 = 9600 ;
}
if ( V_168 >= 230400 ) {
F_101 ( V_118 , V_168 ) ;
F_3 ( V_8 , V_131 , V_142 , 0x0c ) ;
return;
}
F_20 ( & V_113 -> V_12 , L_52 , V_44 , V_168 ) ;
V_18 = F_104 ( V_118 , V_168 ) ;
if ( V_182 & V_204 )
F_110 ( V_129 , V_168 , V_168 ) ;
F_3 ( V_8 , V_131 , V_142 , 0x0c ) ;
if ( V_113 -> V_115 -> V_18 != - V_116 ) {
V_18 = F_29 ( V_113 -> V_115 , V_50 ) ;
if ( V_18 )
F_20 ( & V_113 -> V_12 , L_53 , V_18 ) ;
}
}
static void F_111 ( struct V_128 * V_129 ,
struct V_112 * V_113 , struct V_180 * V_181 )
{
int V_18 ;
unsigned int V_182 ;
struct V_7 * V_8 ;
struct V_117 * V_118 ;
V_8 = V_113 -> V_8 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return;
if ( ! V_118 -> V_119 ) {
F_20 ( & V_113 -> V_12 , L_39 , V_44 ) ;
return;
}
F_20 ( & V_113 -> V_12 , L_54 ) ;
V_182 = V_129 -> V_163 . V_164 ;
F_20 ( & V_113 -> V_12 , L_55 , V_44 ,
V_129 -> V_163 . V_164 , F_112 ( V_129 -> V_163 . V_188 ) ) ;
F_20 ( & V_113 -> V_12 , L_56 , V_44 ,
V_181 -> V_164 , F_112 ( V_181 -> V_188 ) ) ;
F_105 ( V_129 , V_118 , V_181 ) ;
if ( V_113 -> V_115 -> V_18 != - V_116 ) {
V_18 = F_29 ( V_113 -> V_115 , V_50 ) ;
if ( V_18 )
F_20 ( & V_113 -> V_12 , L_53 , V_18 ) ;
}
}
static int F_113 ( struct V_128 * V_129 ,
struct V_117 * V_118 , unsigned int T_6 * V_17 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
unsigned int V_99 = 0 ;
unsigned char V_9 = 0 ;
int V_131 = V_113 -> V_138 - V_113 -> V_8 -> V_139 ;
int V_157 ;
V_157 = F_86 ( V_129 ) ;
if ( V_157 == 0 ) {
F_7 ( V_113 -> V_8 , V_131 , V_140 , & V_9 ) ;
if ( ( V_9 & ( V_207 | V_208 ) )
== ( V_207 | V_208 ) ) {
F_20 ( & V_113 -> V_12 , L_57 , V_44 ) ;
V_99 = V_209 ;
}
}
if ( F_114 ( V_17 , & V_99 , sizeof( int ) ) )
return - V_210 ;
return 0 ;
}
static int F_115 ( struct V_128 * V_129 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 = F_84 ( V_113 ) ;
unsigned int V_99 = 0 ;
unsigned int V_211 ;
unsigned int V_212 ;
V_211 = V_118 -> V_146 ;
V_212 = V_118 -> V_213 ;
V_99 = ( ( V_211 & V_205 ) ? V_214 : 0 )
| ( ( V_211 & V_166 ) ? V_215 : 0 )
| ( ( V_212 & V_216 ) ? V_217 : 0 )
| ( ( V_212 & V_218 ) ? V_219 : 0 )
| ( ( V_212 & V_220 ) ? V_221 : 0 )
| ( ( V_212 & V_222 ) ? V_223 : 0 ) ;
return V_99 ;
}
static int F_116 ( struct V_128 * V_129 ,
unsigned int V_224 , unsigned int V_225 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 = F_84 ( V_113 ) ;
unsigned int V_211 ;
V_211 = V_118 -> V_146 ;
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
V_118 -> V_146 = V_211 ;
F_3 ( V_113 -> V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 ,
V_147 , V_118 -> V_146 ) ;
return 0 ;
}
static int F_117 ( struct V_117 * V_118 , unsigned int V_228 ,
unsigned int T_6 * V_17 )
{
unsigned int V_211 ;
unsigned int V_229 ;
struct V_112 * V_113 ;
if ( V_118 == NULL )
return - 1 ;
V_113 = (struct V_112 * ) V_118 -> V_113 ;
V_211 = V_118 -> V_146 ;
if ( F_118 ( & V_229 , V_17 , sizeof( int ) ) )
return - V_210 ;
switch ( V_228 ) {
case V_230 :
if ( V_229 & V_215 )
V_211 |= V_166 ;
if ( V_229 & V_214 )
V_211 |= V_166 ;
if ( V_229 & V_226 )
V_211 |= V_227 ;
break;
case V_231 :
if ( V_229 & V_215 )
V_211 &= ~ V_166 ;
if ( V_229 & V_214 )
V_211 &= ~ V_166 ;
if ( V_229 & V_226 )
V_211 &= ~ V_227 ;
break;
}
V_118 -> V_146 = V_211 ;
F_3 ( V_113 -> V_8 , V_113 -> V_138 - V_113 -> V_8 -> V_139 ,
V_147 , V_118 -> V_146 ) ;
return 0 ;
}
static int F_119 ( struct V_117 * V_118 ,
struct V_232 T_6 * V_233 )
{
struct V_232 V_38 ;
if ( ! V_233 )
return - V_210 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . type = V_234 ;
V_38 . line = V_118 -> V_113 -> V_8 -> V_139 ;
V_38 . V_113 = V_118 -> V_113 -> V_138 ;
V_38 . V_235 = 0 ;
V_38 . V_37 = V_236 | V_237 ;
V_38 . V_238 = V_135 * V_137 ;
V_38 . V_239 = 9600 ;
V_38 . V_240 = 5 * V_241 ;
V_38 . V_242 = 30 * V_241 ;
if ( F_114 ( V_233 , & V_38 , sizeof( * V_233 ) ) )
return - V_210 ;
return 0 ;
}
static int F_120 ( struct V_128 * V_129 ,
unsigned int V_228 , unsigned long V_229 )
{
struct V_112 * V_113 = V_129 -> V_151 ;
struct V_117 * V_118 ;
V_118 = F_84 ( V_113 ) ;
if ( V_118 == NULL )
return - V_60 ;
F_20 ( & V_113 -> V_12 , L_58 , V_44 , V_228 ) ;
switch ( V_228 ) {
case V_243 :
F_20 ( & V_113 -> V_12 , L_59 , V_44 ) ;
return F_113 ( V_129 , V_118 ,
( unsigned int T_6 * ) V_229 ) ;
case V_230 :
case V_231 :
F_20 ( & V_113 -> V_12 , L_60 , V_44 ) ;
return F_117 ( V_118 , V_228 ,
( unsigned int T_6 * ) V_229 ) ;
case V_244 :
F_20 ( & V_113 -> V_12 , L_61 , V_44 ) ;
return F_119 ( V_118 ,
(struct V_232 T_6 * ) V_229 ) ;
}
return - V_245 ;
}
static int F_121 ( struct V_7 * V_8 )
{
struct V_10 * V_12 ;
char V_9 ;
T_5 V_126 ;
int V_36 ;
V_126 = F_82 ( V_8 -> V_12 -> V_127 . V_122 ) ;
V_12 = V_8 -> V_12 ;
if ( V_126 == V_123 ) {
struct V_112 * V_38 = V_8 -> V_113 [ 0 ] ;
V_8 -> V_113 [ 0 ] = V_8 -> V_113 [ 1 ] ;
V_8 -> V_113 [ 1 ] = V_38 ;
V_8 -> V_113 [ 0 ] -> V_246 = V_38 -> V_246 ;
V_8 -> V_113 [ 0 ] -> V_247 = V_38 -> V_247 ;
V_8 -> V_113 [ 0 ] -> V_248 =
V_38 -> V_248 ;
V_8 -> V_113 [ 1 ] -> V_246 = NULL ;
V_8 -> V_113 [ 1 ] -> V_247 = NULL ;
}
F_5 ( V_8 -> V_12 , F_4 ( V_8 -> V_12 , 0 ) ,
( T_2 ) 0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 , 5000 ) ;
V_36 = F_29 ( V_8 -> V_113 [ 0 ] -> V_246 , V_21 ) ;
if ( V_36 )
F_6 ( & V_12 -> V_12 ,
L_21 ,
V_44 , V_36 ) ;
#ifdef F_73
if ( V_126 == V_123 ) {
V_36 = F_63 ( V_8 ) ;
if ( V_36 < 0 )
return V_36 ;
}
#endif
F_7 ( V_8 , 0 , V_140 , & V_9 ) ;
F_20 ( & V_12 -> V_12 , L_62 , V_9 ) ;
return 0 ;
}
static void F_122 ( struct V_7 * V_8 )
{
#ifdef F_73
if ( F_82 ( V_8 -> V_12 -> V_127 . V_122 )
== V_123 ) {
struct V_32 * V_33 ;
unsigned long V_37 ;
struct V_23 * V_24 =
F_123 ( V_8 ) ;
F_32 ( & V_63 ) ;
V_24 -> V_62 -> V_64 = NULL ;
F_33 ( & V_63 ) ;
if ( V_24 -> V_65 )
F_124 ( & V_24 -> V_66 ,
F_125 ( V_19 ) ) ;
F_126 ( V_24 -> V_62 ) ;
F_66 ( V_8 , NULL ) ;
V_24 -> V_8 = NULL ;
F_127 ( & V_24 -> V_45 ) ;
F_23 ( & V_24 -> V_47 , V_37 ) ;
F_128 (urbtrack,
&mos_parport->active_urbs,
urblist_entry)
F_129 ( V_33 -> V_34 ) ;
F_25 ( & V_24 -> V_47 , V_37 ) ;
F_16 ( & V_24 -> V_31 , F_12 ) ;
}
#endif
}
static int F_130 ( struct V_112 * V_113 )
{
struct V_117 * V_118 ;
V_118 = F_64 ( sizeof( * V_118 ) , V_21 ) ;
if ( ! V_118 )
return - V_22 ;
V_113 -> V_248 =
V_113 -> V_8 -> V_113 [ 0 ] -> V_248 ;
V_118 -> V_113 = V_113 ;
F_131 ( V_113 , V_118 ) ;
return 0 ;
}
static int F_132 ( struct V_112 * V_113 )
{
struct V_117 * V_118 ;
V_118 = F_84 ( V_113 ) ;
F_10 ( V_118 ) ;
return 0 ;
}
