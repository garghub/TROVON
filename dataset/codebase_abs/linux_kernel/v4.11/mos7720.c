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
if ( V_18 == 1 ) {
* V_9 = * V_20 ;
} else {
F_6 ( & V_11 -> V_12 ,
L_1 , V_18 ) ;
if ( V_18 >= 0 )
V_18 = - V_23 ;
* V_9 = 0 ;
}
F_10 ( V_20 ) ;
return V_18 ;
}
static inline int F_11 ( struct V_24 * V_25 ,
enum V_26 V_27 )
{
V_25 -> V_28 = V_27 ;
F_3 ( V_25 -> V_8 , V_29 , V_30 ,
V_25 -> V_28 ) ;
return 0 ;
}
static void F_12 ( struct V_31 * V_31 )
{
struct V_24 * V_25 =
F_13 ( V_31 , struct V_24 , V_32 ) ;
F_10 ( V_25 ) ;
}
static void F_14 ( struct V_31 * V_31 )
{
struct V_33 * V_34 =
F_13 ( V_31 , struct V_33 , V_32 ) ;
struct V_24 * V_25 = V_34 -> V_25 ;
F_15 ( V_34 -> V_35 ) ;
F_10 ( V_34 -> V_36 ) ;
F_10 ( V_34 ) ;
F_16 ( & V_25 -> V_32 , F_12 ) ;
}
static void F_17 ( unsigned long V_37 )
{
int V_38 ;
unsigned long V_39 ;
struct V_24 * V_25 = ( void * ) V_37 ;
struct V_33 * V_34 , * V_40 ;
struct V_41 * V_42 , * V_43 ;
struct V_44 * V_12 ;
if ( F_18 ( V_25 -> V_8 == NULL ) )
return;
V_12 = & V_25 -> V_8 -> V_12 -> V_12 ;
if ( ! F_19 ( & V_25 -> V_8 -> V_45 ) ) {
F_20 ( V_12 , L_2 , V_46 ) ;
F_21 ( & V_25 -> V_47 ) ;
return;
}
if ( F_18 ( V_25 -> V_8 -> V_48 ) ) {
F_22 ( & V_25 -> V_8 -> V_45 ) ;
return;
}
F_23 ( & V_25 -> V_49 , V_39 ) ;
if ( F_24 ( & V_25 -> V_50 ) ) {
F_25 ( & V_25 -> V_49 , V_39 ) ;
F_22 ( & V_25 -> V_8 -> V_45 ) ;
F_20 ( V_12 , L_3 , V_46 ) ;
return;
}
F_26 (cursor, next, &mos_parport->deferred_urbs)
F_27 ( V_42 , & V_25 -> V_51 ) ;
F_28 (urbtrack, tmp, &mos_parport->active_urbs,
urblist_entry) {
V_38 = F_29 ( V_34 -> V_35 , V_52 ) ;
F_20 ( V_12 , L_4 , V_46 ) ;
if ( V_38 ) {
F_6 ( V_12 , L_5 , V_38 ) ;
F_30 ( & V_34 -> V_53 ) ;
F_16 ( & V_34 -> V_32 , F_14 ) ;
}
}
F_25 ( & V_25 -> V_49 , V_39 ) ;
F_22 ( & V_25 -> V_8 -> V_45 ) ;
}
static void F_31 ( struct V_35 * V_35 )
{
struct V_33 * V_34 = V_35 -> V_54 ;
int V_18 = V_35 -> V_18 ;
if ( F_18 ( V_18 ) )
F_20 ( & V_35 -> V_12 -> V_12 , L_6 , V_46 , V_18 ) ;
F_32 ( & V_34 -> V_25 -> V_49 ) ;
F_30 ( & V_34 -> V_53 ) ;
F_33 ( & V_34 -> V_25 -> V_49 ) ;
F_16 ( & V_34 -> V_32 , F_14 ) ;
}
static int F_34 ( struct V_24 * V_25 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_33 * V_34 ;
int V_38 ;
unsigned long V_39 ;
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
V_34 = F_9 ( sizeof( struct V_33 ) , V_52 ) ;
if ( ! V_34 )
return - V_22 ;
F_35 ( & V_25 -> V_32 ) ;
V_34 -> V_25 = V_25 ;
V_34 -> V_35 = F_36 ( 0 , V_52 ) ;
if ( ! V_34 -> V_35 ) {
F_10 ( V_34 ) ;
return - V_22 ;
}
V_34 -> V_36 = F_9 ( sizeof( * V_34 -> V_36 ) , V_52 ) ;
if ( ! V_34 -> V_36 ) {
F_15 ( V_34 -> V_35 ) ;
F_10 ( V_34 ) ;
return - V_22 ;
}
V_34 -> V_36 -> V_55 = ( T_2 ) 0x40 ;
V_34 -> V_36 -> V_56 = ( T_2 ) 0x0e ;
V_34 -> V_36 -> V_57 = F_37 ( F_2 ( V_2 , V_29 ) ) ;
V_34 -> V_36 -> V_58 = F_37 ( F_1 ( V_2 ) ) ;
V_34 -> V_36 -> V_59 = 0 ;
F_38 ( V_34 -> V_35 , V_11 ,
F_4 ( V_11 , 0 ) ,
( unsigned char * ) V_34 -> V_36 ,
NULL , 0 , F_31 , V_34 ) ;
F_39 ( & V_34 -> V_32 ) ;
F_40 ( & V_34 -> V_53 ) ;
if ( ! F_19 ( & V_8 -> V_45 ) ) {
F_23 ( & V_25 -> V_49 , V_39 ) ;
F_41 ( & V_34 -> V_53 ,
& V_25 -> V_50 ) ;
F_25 ( & V_25 -> V_49 , V_39 ) ;
F_21 ( & V_25 -> V_47 ) ;
F_20 ( & V_11 -> V_12 , L_7 ) ;
return 0 ;
}
if ( V_8 -> V_48 ) {
F_16 ( & V_34 -> V_32 , F_14 ) ;
F_22 ( & V_8 -> V_45 ) ;
return - V_60 ;
}
F_23 ( & V_25 -> V_49 , V_39 ) ;
F_41 ( & V_34 -> V_53 , & V_25 -> V_51 ) ;
F_25 ( & V_25 -> V_49 , V_39 ) ;
V_38 = F_29 ( V_34 -> V_35 , V_52 ) ;
F_22 ( & V_8 -> V_45 ) ;
if ( V_38 ) {
F_6 ( & V_11 -> V_12 ,
L_8 , V_46 , V_38 ) ;
F_23 ( & V_25 -> V_49 , V_39 ) ;
F_30 ( & V_34 -> V_53 ) ;
F_25 ( & V_25 -> V_49 , V_39 ) ;
F_16 ( & V_34 -> V_32 , F_14 ) ;
return V_38 ;
}
return 0 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_24 * V_25 ;
F_32 ( & V_63 ) ;
V_25 = V_62 -> V_64 ;
if ( F_18 ( V_25 == NULL ) ) {
F_33 ( & V_63 ) ;
return - 1 ;
}
V_25 -> V_65 = true ;
F_43 ( & V_25 -> V_66 ) ;
F_33 ( & V_63 ) ;
F_44 ( & V_25 -> V_8 -> V_45 ) ;
if ( V_25 -> V_8 -> V_48 ) {
F_22 ( & V_25 -> V_8 -> V_45 ) ;
V_25 -> V_65 = false ;
F_45 ( & V_25 -> V_66 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_46 ( struct V_61 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
F_22 ( & V_25 -> V_8 -> V_45 ) ;
V_25 -> V_65 = false ;
F_45 ( & V_25 -> V_66 ) ;
}
static void F_47 ( struct V_61 * V_62 , unsigned char V_67 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
if ( F_42 ( V_62 ) < 0 )
return;
F_11 ( V_25 , V_68 ) ;
F_3 ( V_25 -> V_8 , V_29 , V_6 , ( T_2 ) V_67 ) ;
F_46 ( V_62 ) ;
}
static unsigned char F_48 ( struct V_61 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
unsigned char V_67 ;
if ( F_42 ( V_62 ) < 0 )
return 0 ;
F_7 ( V_25 -> V_8 , V_29 , V_6 , & V_67 ) ;
F_46 ( V_62 ) ;
return V_67 ;
}
static void F_49 ( struct V_61 * V_62 , unsigned char V_67 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
T_2 V_9 ;
if ( F_42 ( V_62 ) < 0 )
return;
V_9 = ( ( T_2 ) V_67 & 0x0f ) | ( V_25 -> V_69 & 0xf0 ) ;
F_3 ( V_25 -> V_8 , V_29 , V_70 , V_9 ) ;
V_25 -> V_69 = V_9 ;
F_46 ( V_62 ) ;
}
static unsigned char F_50 ( struct V_61 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
T_2 V_71 ;
F_32 ( & V_63 ) ;
V_25 = V_62 -> V_64 ;
if ( F_18 ( V_25 == NULL ) ) {
F_33 ( & V_63 ) ;
return 0 ;
}
V_71 = V_25 -> V_69 & 0x0f ;
F_33 ( & V_63 ) ;
return V_71 ;
}
static unsigned char F_51 ( struct V_61 * V_62 ,
unsigned char V_72 ,
unsigned char V_73 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
T_2 V_71 ;
V_72 &= 0x0f ;
V_73 &= 0x0f ;
if ( F_42 ( V_62 ) < 0 )
return 0 ;
V_25 -> V_69 = ( V_25 -> V_69 & ( ~ V_72 ) ) ^ V_73 ;
F_3 ( V_25 -> V_8 , V_29 , V_70 ,
V_25 -> V_69 ) ;
V_71 = V_25 -> V_69 & 0x0f ;
F_46 ( V_62 ) ;
return V_71 ;
}
static unsigned char F_52 ( struct V_61 * V_62 )
{
unsigned char V_18 ;
struct V_24 * V_25 = V_62 -> V_64 ;
F_32 ( & V_63 ) ;
V_25 = V_62 -> V_64 ;
if ( F_18 ( V_25 == NULL ) ) {
F_33 ( & V_63 ) ;
return 0 ;
}
V_18 = F_53 ( & V_25 -> V_74 ) & 0xf8 ;
F_33 ( & V_63 ) ;
return V_18 ;
}
static void F_54 ( struct V_61 * V_62 )
{
}
static void F_55 ( struct V_61 * V_62 )
{
}
static void F_56 ( struct V_61 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
if ( F_42 ( V_62 ) < 0 )
return;
F_11 ( V_25 , V_75 ) ;
V_25 -> V_69 &= ~ 0x20 ;
F_3 ( V_25 -> V_8 , V_29 , V_70 ,
V_25 -> V_69 ) ;
F_46 ( V_62 ) ;
}
static void F_57 ( struct V_61 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_64 ;
if ( F_42 ( V_62 ) < 0 )
return;
F_11 ( V_25 , V_75 ) ;
V_25 -> V_69 |= 0x20 ;
F_3 ( V_25 -> V_8 , V_29 , V_70 ,
V_25 -> V_69 ) ;
F_46 ( V_62 ) ;
}
static void F_58 ( struct V_76 * V_12 ,
struct V_77 * V_78 )
{
V_78 -> V_79 . V_80 . V_81 = V_82 ;
V_78 -> V_79 . V_80 . V_83 = V_84 ;
}
static void F_59 ( struct V_61 * V_62 ,
struct V_77 * V_78 )
{
struct V_24 * V_25 ;
F_32 ( & V_63 ) ;
V_25 = V_62 -> V_64 ;
if ( F_18 ( V_25 == NULL ) ) {
F_33 ( & V_63 ) ;
return;
}
V_78 -> V_79 . V_80 . V_81 = V_25 -> V_69 ;
V_78 -> V_79 . V_80 . V_83 = V_25 -> V_28 ;
F_33 ( & V_63 ) ;
}
static void F_60 ( struct V_61 * V_62 ,
struct V_77 * V_78 )
{
struct V_24 * V_25 ;
F_32 ( & V_63 ) ;
V_25 = V_62 -> V_64 ;
if ( F_18 ( V_25 == NULL ) ) {
F_33 ( & V_63 ) ;
return;
}
F_34 ( V_25 , V_70 ,
V_25 -> V_69 ) ;
F_34 ( V_25 , V_30 ,
V_25 -> V_28 ) ;
F_33 ( & V_63 ) ;
}
static T_4 F_61 ( struct V_61 * V_62 ,
const void * V_85 ,
T_4 V_86 , int V_39 )
{
int V_87 ;
struct V_24 * V_25 = V_62 -> V_64 ;
int V_88 ;
if ( F_42 ( V_62 ) < 0 )
return 0 ;
F_11 ( V_25 , V_89 ) ;
V_87 = F_62 ( V_25 -> V_8 -> V_12 ,
F_63 ( V_25 -> V_8 -> V_12 , 2 ) ,
( void * ) V_85 , V_86 , & V_88 ,
V_19 ) ;
F_46 ( V_62 ) ;
if ( V_87 ) {
F_6 ( & V_25 -> V_8 -> V_12 -> V_12 ,
L_9 , V_87 ) ;
return 0 ;
}
return V_88 ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_24 * V_25 ;
V_25 = F_65 ( sizeof( struct V_24 ) , V_21 ) ;
if ( ! V_25 )
return - V_22 ;
V_25 -> V_65 = false ;
F_39 ( & V_25 -> V_32 ) ;
F_66 ( & V_25 -> V_49 ) ;
F_40 ( & V_25 -> V_51 ) ;
F_40 ( & V_25 -> V_50 ) ;
F_67 ( V_8 , V_25 ) ;
V_25 -> V_8 = V_8 ;
F_68 ( & V_25 -> V_47 , F_17 ,
( unsigned long ) V_25 ) ;
F_69 ( & V_25 -> V_66 ) ;
F_3 ( V_25 -> V_8 , V_29 , V_90 , ( T_2 ) 0x80 ) ;
F_3 ( V_25 -> V_8 , V_29 , V_90 , ( T_2 ) 0x00 ) ;
V_25 -> V_69 = V_82 ;
F_3 ( V_25 -> V_8 , V_29 , V_70 ,
V_25 -> V_69 ) ;
V_25 -> V_28 = V_84 ;
F_3 ( V_25 -> V_8 , V_29 , V_30 ,
V_25 -> V_28 ) ;
V_25 -> V_62 = F_70 ( 0 , V_91 ,
V_92 ,
& V_93 ) ;
if ( V_25 -> V_62 == NULL ) {
F_6 ( & V_8 -> V_94 -> V_12 ,
L_10 ) ;
F_16 ( & V_25 -> V_32 , F_12 ) ;
return - V_23 ;
}
V_25 -> V_62 -> V_64 = V_25 ;
V_25 -> V_62 -> V_95 = V_96 | V_97 ;
V_25 -> V_62 -> V_12 = & V_8 -> V_94 -> V_12 ;
F_71 ( V_25 -> V_62 ) ;
return 0 ;
}
static void F_72 ( struct V_35 * V_35 )
{
int V_98 ;
int V_99 ;
int V_18 = V_35 -> V_18 ;
struct V_44 * V_12 = & V_35 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_100 ;
T_2 V_101 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
F_20 ( V_12 , L_11 , V_46 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_46 , V_18 ) ;
goto exit;
}
V_99 = V_35 -> V_105 ;
V_9 = V_35 -> V_106 ;
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
V_98 = F_29 ( V_35 , V_52 ) ;
if ( V_98 )
F_6 ( V_12 , L_18 , V_46 , V_98 ) ;
}
static void F_73 ( struct V_35 * V_35 )
{
int V_98 ;
int V_99 ;
int V_18 = V_35 -> V_18 ;
struct V_44 * V_12 = & V_35 -> V_12 -> V_12 ;
T_2 * V_9 ;
T_2 V_110 ;
switch ( V_18 ) {
case 0 :
break;
case - V_102 :
case - V_103 :
case - V_104 :
case - V_60 :
F_20 ( V_12 , L_11 , V_46 , V_18 ) ;
return;
default:
F_20 ( V_12 , L_6 , V_46 , V_18 ) ;
goto exit;
}
V_99 = V_35 -> V_105 ;
V_9 = V_35 -> V_106 ;
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
struct V_111 * V_112 = V_35 -> V_54 ;
struct V_24 * V_25 = V_112 -> V_8 -> V_113 ;
if ( F_18 ( V_25 == NULL ) )
return;
F_75 ( & V_25 -> V_74 , V_9 [ 2 ] ) ;
}
#endif
exit:
V_98 = F_29 ( V_35 , V_52 ) ;
if ( V_98 )
F_6 ( V_12 , L_18 , V_46 , V_98 ) ;
}
static void F_76 ( struct V_35 * V_35 )
{
int V_87 ;
unsigned char * V_9 ;
struct V_111 * V_112 ;
int V_18 = V_35 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_35 -> V_12 -> V_12 , L_21 , V_18 ) ;
return;
}
V_112 = V_35 -> V_54 ;
F_20 ( & V_112 -> V_12 , L_22 , V_46 ) ;
V_9 = V_35 -> V_106 ;
if ( V_35 -> V_105 ) {
F_77 ( & V_112 -> V_112 , V_9 , V_35 -> V_105 ) ;
F_78 ( & V_112 -> V_112 ) ;
}
if ( V_112 -> V_114 -> V_18 != - V_115 ) {
V_87 = F_29 ( V_112 -> V_114 , V_52 ) ;
if ( V_87 )
F_20 ( & V_112 -> V_12 , L_23 , V_87 ) ;
}
}
static void F_79 ( struct V_35 * V_35 )
{
struct V_116 * V_117 ;
int V_18 = V_35 -> V_18 ;
if ( V_18 ) {
F_20 ( & V_35 -> V_12 -> V_12 , L_24 , V_18 ) ;
return;
}
V_117 = V_35 -> V_54 ;
if ( ! V_117 ) {
F_20 ( & V_35 -> V_12 -> V_12 , L_25 ) ;
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
struct V_35 * V_35 ;
struct V_116 * V_117 ;
int V_125 ;
int V_126 ;
T_2 V_9 ;
int V_127 = 0 ;
int V_128 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_60 ;
F_85 ( V_8 -> V_12 , V_112 -> V_129 -> V_13 ) ;
F_85 ( V_8 -> V_12 , V_112 -> V_114 -> V_13 ) ;
for ( V_128 = 0 ; V_128 < V_130 ; ++ V_128 ) {
V_35 = F_36 ( 0 , V_21 ) ;
V_117 -> V_131 [ V_128 ] = V_35 ;
if ( ! V_35 )
continue;
V_35 -> V_106 = F_9 ( V_132 ,
V_21 ) ;
if ( ! V_35 -> V_106 ) {
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
F_3 ( V_8 , V_29 , V_5 , 0x02 ) ;
F_3 ( V_8 , V_29 , V_134 , 0x02 ) ;
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
F_7 ( V_8 , V_29 , V_141 , & V_9 ) ;
V_9 = V_9 | ( V_112 -> V_126 + 1 ) ;
F_3 ( V_8 , V_29 , V_141 , V_9 ) ;
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
V_46 , V_125 ) ;
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
F_20 ( & V_112 -> V_12 , L_28 , V_46 , V_146 ) ;
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
return - V_60 ;
for ( V_145 = 0 ; V_145 < V_130 ; ++ V_145 ) {
if ( V_117 -> V_131 [ V_145 ] &&
V_117 -> V_131 [ V_145 ] -> V_18 != - V_115 )
V_149 += V_132 ;
}
F_20 ( & V_112 -> V_12 , L_28 , V_46 , V_149 ) ;
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
struct V_35 * V_35 ;
const unsigned char * V_153 = V_9 ;
V_8 = V_112 -> V_8 ;
V_117 = F_84 ( V_112 ) ;
if ( V_117 == NULL )
return - V_60 ;
V_35 = NULL ;
for ( V_145 = 0 ; V_145 < V_130 ; ++ V_145 ) {
if ( V_117 -> V_131 [ V_145 ] &&
V_117 -> V_131 [ V_145 ] -> V_18 != - V_115 ) {
V_35 = V_117 -> V_131 [ V_145 ] ;
F_20 ( & V_112 -> V_12 , L_29 , V_145 ) ;
break;
}
}
if ( V_35 == NULL ) {
F_20 ( & V_112 -> V_12 , L_30 , V_46 ) ;
goto exit;
}
if ( V_35 -> V_106 == NULL ) {
V_35 -> V_106 = F_9 ( V_132 ,
V_52 ) ;
if ( ! V_35 -> V_106 )
goto exit;
}
V_152 = F_92 ( V_150 , V_132 ) ;
memcpy ( V_35 -> V_106 , V_153 , V_152 ) ;
F_93 ( & V_112 -> V_12 , V_46 , V_152 ,
V_35 -> V_106 ) ;
F_94 ( V_35 , V_8 -> V_12 ,
F_63 ( V_8 -> V_12 ,
V_112 -> V_154 ) ,
V_35 -> V_106 , V_152 ,
F_79 , V_117 ) ;
V_18 = F_29 ( V_35 , V_52 ) ;
if ( V_18 ) {
F_95 ( V_112 , L_31
L_32 , V_46 , V_18 ) ;
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
F_20 ( & V_112 -> V_12 , L_33 , V_46 ) ;
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
F_20 ( & V_112 -> V_12 , L_33 , V_46 ) ;
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
F_3 ( V_8 , V_29 , V_141 , 0x00 ) ;
if ( V_126 == 0 )
V_159 = V_5 ;
else
V_159 = V_134 ;
F_3 ( V_8 , V_29 , V_159 , V_158 * 0x10 ) ;
F_3 ( V_8 , V_29 , V_141 , 0x03 ) ;
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
F_20 ( & V_112 -> V_12 , L_35 , V_46 , V_164 ) ;
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
F_20 ( & V_112 -> V_12 , L_38 , V_46 , V_164 ) ;
V_18 = F_103 ( V_112 , V_164 , & V_165 ) ;
if ( V_18 ) {
F_6 ( & V_112 -> V_12 , L_39 , V_46 ) ;
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
T_2 V_72 = 0xff ;
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
F_20 ( & V_112 -> V_12 , L_33 , V_46 ) ;
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
V_72 = 0x1f ;
break;
case V_185 :
V_175 = V_186 ;
V_72 = 0x3f ;
break;
case V_187 :
V_175 = V_188 ;
V_72 = 0x7f ;
break;
default:
case V_189 :
V_175 = V_178 ;
break;
}
if ( V_173 & V_190 ) {
if ( V_173 & V_191 ) {
V_176 = V_192 ;
F_20 ( & V_112 -> V_12 , L_40 , V_46 ) ;
} else {
V_176 = ( V_193 | V_192 ) ;
F_20 ( & V_112 -> V_12 , L_41 , V_46 ) ;
}
} else {
F_20 ( & V_112 -> V_12 , L_42 , V_46 ) ;
}
if ( V_173 & V_194 )
V_176 = V_176 | 0x20 ;
if ( V_173 & V_195 ) {
V_177 = V_196 ;
F_20 ( & V_112 -> V_12 , L_43 , V_46 ) ;
} else {
V_177 = 0x00 ;
F_20 ( & V_112 -> V_12 , L_44 , V_46 ) ;
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
F_3 ( V_8 , V_29 , V_141 ,
0x01 ) ;
else
F_3 ( V_8 , V_29 , V_141 ,
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
F_20 ( & V_112 -> V_12 , L_46 , V_46 , V_158 ) ;
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
F_20 ( & V_112 -> V_12 , L_33 , V_46 ) ;
return;
}
F_20 ( & V_112 -> V_12 , L_48 ) ;
V_173 = V_124 -> V_179 . V_180 ;
F_20 ( & V_112 -> V_12 , L_49 , V_46 ,
V_124 -> V_179 . V_180 , F_113 ( V_124 -> V_179 . V_181 ) ) ;
F_20 ( & V_112 -> V_12 , L_50 , V_46 ,
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
F_20 ( & V_112 -> V_12 , L_51 , V_46 ) ;
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
struct V_226 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . type = V_228 ;
V_40 . line = V_117 -> V_112 -> V_229 ;
V_40 . V_112 = V_117 -> V_112 -> V_126 ;
V_40 . V_230 = 0 ;
V_40 . V_231 = V_130 * V_132 ;
V_40 . V_232 = 9600 ;
V_40 . V_233 = 5 * V_234 ;
V_40 . V_235 = 30 * V_234 ;
if ( F_115 ( V_227 , & V_40 , sizeof( * V_227 ) ) )
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
return - V_60 ;
switch ( V_222 ) {
case V_236 :
F_20 ( & V_112 -> V_12 , L_52 , V_46 ) ;
return F_114 ( V_124 , V_117 ,
( unsigned int T_6 * ) V_223 ) ;
case V_224 :
case V_225 :
F_20 ( & V_112 -> V_12 , L_53 , V_46 ) ;
return F_118 ( V_117 , V_222 ,
( unsigned int T_6 * ) V_223 ) ;
case V_237 :
F_20 ( & V_112 -> V_12 , L_54 , V_46 ) ;
return F_120 ( V_117 ,
(struct V_226 T_6 * ) V_223 ) ;
}
return - V_238 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_10 * V_12 ;
char V_9 ;
T_5 V_119 ;
int V_38 ;
if ( V_8 -> V_239 < 2 || V_8 -> V_240 < 2 ) {
F_6 ( & V_8 -> V_94 -> V_12 , L_55 ) ;
return - V_60 ;
}
V_119 = F_82 ( V_8 -> V_12 -> V_120 . V_121 ) ;
V_12 = V_8 -> V_12 ;
if ( V_119 == V_122 ) {
struct V_111 * V_40 = V_8 -> V_112 [ 0 ] ;
V_8 -> V_112 [ 0 ] = V_8 -> V_112 [ 1 ] ;
V_8 -> V_112 [ 1 ] = V_40 ;
V_8 -> V_112 [ 0 ] -> V_241 = V_40 -> V_241 ;
V_8 -> V_112 [ 0 ] -> V_242 = V_40 -> V_242 ;
V_8 -> V_112 [ 0 ] -> V_243 =
V_40 -> V_243 ;
V_8 -> V_112 [ 1 ] -> V_241 = NULL ;
V_8 -> V_112 [ 1 ] -> V_242 = NULL ;
if ( V_8 -> V_112 [ 0 ] -> V_241 ) {
struct V_35 * V_35 = V_8 -> V_112 [ 0 ] -> V_241 ;
V_35 -> F_45 = F_73 ;
}
}
F_5 ( V_8 -> V_12 , F_4 ( V_8 -> V_12 , 0 ) ,
( T_2 ) 0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 , 5000 ) ;
#ifdef F_74
if ( V_119 == V_122 ) {
V_38 = F_64 ( V_8 ) ;
if ( V_38 < 0 )
return V_38 ;
}
#endif
V_38 = F_29 ( V_8 -> V_112 [ 0 ] -> V_241 , V_21 ) ;
if ( V_38 ) {
F_6 ( & V_12 -> V_12 , L_56 ,
V_38 ) ;
}
F_7 ( V_8 , 0 , V_133 , & V_9 ) ;
F_20 ( & V_12 -> V_12 , L_57 , V_9 ) ;
return 0 ;
}
static void F_123 ( struct V_7 * V_8 )
{
F_88 ( V_8 -> V_112 [ 0 ] -> V_241 ) ;
#ifdef F_74
if ( F_82 ( V_8 -> V_12 -> V_120 . V_121 )
== V_122 ) {
struct V_33 * V_34 ;
unsigned long V_39 ;
struct V_24 * V_25 =
F_124 ( V_8 ) ;
F_32 ( & V_63 ) ;
V_25 -> V_62 -> V_64 = NULL ;
F_33 ( & V_63 ) ;
if ( V_25 -> V_65 )
F_125 ( & V_25 -> V_66 ,
F_126 ( V_19 ) ) ;
F_127 ( V_25 -> V_62 ) ;
F_67 ( V_8 , NULL ) ;
V_25 -> V_8 = NULL ;
F_128 ( & V_25 -> V_47 ) ;
F_23 ( & V_25 -> V_49 , V_39 ) ;
F_129 (urbtrack,
&mos_parport->active_urbs,
urblist_entry)
F_130 ( V_34 -> V_35 ) ;
F_25 ( & V_25 -> V_49 , V_39 ) ;
F_131 ( V_25 -> V_62 ) ;
F_16 ( & V_25 -> V_32 , F_12 ) ;
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
