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
F_12 ( L_2 , V_29 ) ;
F_13 ( V_21 ) ;
}
static void F_14 ( struct V_27 * V_27 )
{
struct V_30 * V_31 =
F_11 ( V_27 , struct V_30 , V_28 ) ;
struct V_20 * V_21 = V_31 -> V_21 ;
F_12 ( L_2 , V_29 ) ;
F_15 ( V_31 -> V_32 ) ;
F_13 ( V_31 ) ;
F_16 ( & V_21 -> V_28 , F_10 ) ;
}
static void F_17 ( unsigned long V_33 )
{
int V_34 ;
unsigned long V_35 ;
struct V_20 * V_21 = ( void * ) V_33 ;
struct V_30 * V_31 ;
struct V_36 * V_37 , * V_38 ;
F_12 ( L_2 , V_29 ) ;
if ( F_18 ( V_21 -> V_8 == NULL ) )
return;
if ( ! F_19 ( & V_21 -> V_8 -> V_39 ) ) {
F_12 ( L_3 , V_29 ) ;
F_20 ( & V_21 -> V_40 ) ;
return;
}
if ( F_18 ( V_21 -> V_8 -> V_41 ) ) {
F_21 ( & V_21 -> V_8 -> V_39 ) ;
return;
}
F_22 ( & V_21 -> V_42 , V_35 ) ;
if ( F_23 ( & V_21 -> V_43 ) ) {
F_24 ( & V_21 -> V_42 , V_35 ) ;
F_21 ( & V_21 -> V_8 -> V_39 ) ;
F_12 ( L_4 , V_29 ) ;
return;
}
F_25 (cursor, next, &mos_parport->deferred_urbs)
F_26 ( V_37 , & V_21 -> V_44 ) ;
F_27 (urbtrack, &mos_parport->active_urbs,
urblist_entry) {
V_34 = F_28 ( V_31 -> V_32 , V_45 ) ;
F_12 ( L_5 , V_29 ) ;
if ( V_34 ) {
F_6 ( & V_21 -> V_8 -> V_12 -> V_12 ,
L_6 , V_34 ) ;
F_29 ( & V_31 -> V_46 ) ;
F_16 ( & V_31 -> V_28 , F_14 ) ;
}
}
F_24 ( & V_21 -> V_42 , V_35 ) ;
F_21 ( & V_21 -> V_8 -> V_39 ) ;
}
static void F_30 ( struct V_32 * V_32 )
{
struct V_30 * V_31 = V_32 -> V_47 ;
int V_18 = V_32 -> V_18 ;
F_12 ( L_2 , V_29 ) ;
if ( F_18 ( V_18 ) )
F_12 ( L_7 , V_29 , V_18 ) ;
F_31 ( & V_31 -> V_21 -> V_42 ) ;
F_29 ( & V_31 -> V_46 ) ;
F_32 ( & V_31 -> V_21 -> V_42 ) ;
F_16 ( & V_31 -> V_28 , F_14 ) ;
}
static int F_33 ( struct V_20 * V_21 ,
enum V_1 V_2 , T_2 V_9 )
{
struct V_30 * V_31 ;
int V_34 ;
unsigned long V_35 ;
struct V_48 V_49 ;
struct V_7 * V_8 = V_21 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
F_12 ( L_2 , V_29 ) ;
V_31 = F_34 ( sizeof( struct V_30 ) , V_45 ) ;
if ( V_31 == NULL ) {
F_6 ( & V_11 -> V_12 , L_8 ) ;
return - V_50 ;
}
F_35 ( & V_21 -> V_28 ) ;
V_31 -> V_21 = V_21 ;
V_31 -> V_32 = F_36 ( 0 , V_45 ) ;
if ( V_31 -> V_32 == NULL ) {
F_6 ( & V_11 -> V_12 , L_9 ) ;
F_13 ( V_31 ) ;
return - V_50 ;
}
V_49 . V_51 = ( T_2 ) 0x40 ;
V_49 . V_52 = ( T_2 ) 0x0e ;
V_49 . V_53 = F_2 ( V_2 , V_25 ) ;
V_49 . V_54 = F_1 ( V_2 ) ;
V_49 . V_55 = 0 ;
F_37 ( V_31 -> V_32 , V_11 ,
F_4 ( V_11 , 0 ) ,
( unsigned char * ) & V_49 ,
NULL , 0 , F_30 , V_31 ) ;
F_38 ( & V_31 -> V_28 ) ;
F_39 ( & V_31 -> V_46 ) ;
if ( ! F_19 ( & V_8 -> V_39 ) ) {
F_22 ( & V_21 -> V_42 , V_35 ) ;
F_40 ( & V_31 -> V_46 ,
& V_21 -> V_43 ) ;
F_24 ( & V_21 -> V_42 , V_35 ) ;
F_20 ( & V_21 -> V_40 ) ;
F_12 ( L_10 ) ;
return 0 ;
}
if ( V_8 -> V_41 ) {
F_16 ( & V_31 -> V_28 , F_14 ) ;
F_21 ( & V_8 -> V_39 ) ;
return - V_56 ;
}
F_22 ( & V_21 -> V_42 , V_35 ) ;
F_40 ( & V_31 -> V_46 , & V_21 -> V_44 ) ;
F_24 ( & V_21 -> V_42 , V_35 ) ;
V_34 = F_28 ( V_31 -> V_32 , V_45 ) ;
F_21 ( & V_8 -> V_39 ) ;
if ( V_34 ) {
F_6 ( & V_11 -> V_12 ,
L_11 , V_29 , V_34 ) ;
F_22 ( & V_21 -> V_42 , V_35 ) ;
F_29 ( & V_31 -> V_46 ) ;
F_24 ( & V_21 -> V_42 , V_35 ) ;
F_16 ( & V_31 -> V_28 , F_14 ) ;
return V_34 ;
}
return 0 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_20 * V_21 ;
F_31 ( & V_59 ) ;
V_21 = V_58 -> V_60 ;
if ( F_18 ( V_21 == NULL ) ) {
F_32 ( & V_59 ) ;
return - 1 ;
}
V_21 -> V_61 = true ;
F_42 ( V_21 -> V_62 ) ;
F_32 ( & V_59 ) ;
F_43 ( & V_21 -> V_8 -> V_39 ) ;
if ( V_21 -> V_8 -> V_41 ) {
F_21 ( & V_21 -> V_8 -> V_39 ) ;
V_21 -> V_61 = false ;
F_44 ( & V_21 -> V_62 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_45 ( struct V_57 * V_58 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
F_21 ( & V_21 -> V_8 -> V_39 ) ;
V_21 -> V_61 = false ;
F_44 ( & V_21 -> V_62 ) ;
}
static void F_46 ( struct V_57 * V_58 , unsigned char V_63 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
F_12 ( L_12 , V_29 , V_63 ) ;
if ( F_41 ( V_58 ) < 0 )
return;
F_9 ( V_21 , V_64 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_6 , ( T_2 ) V_63 ) ;
F_45 ( V_58 ) ;
}
static unsigned char F_47 ( struct V_57 * V_58 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
unsigned char V_63 ;
F_12 ( L_2 , V_29 ) ;
if ( F_41 ( V_58 ) < 0 )
return 0 ;
F_7 ( V_21 -> V_8 , V_25 , V_6 , & V_63 ) ;
F_45 ( V_58 ) ;
return V_63 ;
}
static void F_48 ( struct V_57 * V_58 , unsigned char V_63 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
T_2 V_9 ;
F_12 ( L_12 , V_29 , V_63 ) ;
if ( F_41 ( V_58 ) < 0 )
return;
V_9 = ( ( T_2 ) V_63 & 0x0f ) | ( V_21 -> V_65 & 0xf0 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_66 , V_9 ) ;
V_21 -> V_65 = V_9 ;
F_45 ( V_58 ) ;
}
static unsigned char F_49 ( struct V_57 * V_58 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
T_2 V_67 ;
F_12 ( L_2 , V_29 ) ;
F_31 ( & V_59 ) ;
V_21 = V_58 -> V_60 ;
if ( F_18 ( V_21 == NULL ) ) {
F_32 ( & V_59 ) ;
return 0 ;
}
V_67 = V_21 -> V_65 & 0x0f ;
F_32 ( & V_59 ) ;
return V_67 ;
}
static unsigned char F_50 ( struct V_57 * V_58 ,
unsigned char V_68 ,
unsigned char V_69 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
T_2 V_67 ;
F_12 ( L_2 , V_29 ) ;
V_68 &= 0x0f ;
V_69 &= 0x0f ;
if ( F_41 ( V_58 ) < 0 )
return 0 ;
V_21 -> V_65 = ( V_21 -> V_65 & ( ~ V_68 ) ) ^ V_69 ;
F_3 ( V_21 -> V_8 , V_25 , V_66 , V_21 -> V_65 ) ;
V_67 = V_21 -> V_65 & 0x0f ;
F_45 ( V_58 ) ;
return V_67 ;
}
static unsigned char F_51 ( struct V_57 * V_58 )
{
unsigned char V_18 ;
struct V_20 * V_21 = V_58 -> V_60 ;
F_12 ( L_2 , V_29 ) ;
F_31 ( & V_59 ) ;
V_21 = V_58 -> V_60 ;
if ( F_18 ( V_21 == NULL ) ) {
F_32 ( & V_59 ) ;
return 0 ;
}
V_18 = F_52 ( & V_21 -> V_70 ) & 0xf8 ;
F_32 ( & V_59 ) ;
return V_18 ;
}
static void F_53 ( struct V_57 * V_58 )
{
F_12 ( L_2 , V_29 ) ;
}
static void F_54 ( struct V_57 * V_58 )
{
F_12 ( L_2 , V_29 ) ;
}
static void F_55 ( struct V_57 * V_58 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
F_12 ( L_2 , V_29 ) ;
if ( F_41 ( V_58 ) < 0 )
return;
F_9 ( V_21 , V_71 ) ;
V_21 -> V_65 &= ~ 0x20 ;
F_3 ( V_21 -> V_8 , V_25 , V_66 , V_21 -> V_65 ) ;
F_45 ( V_58 ) ;
}
static void F_56 ( struct V_57 * V_58 )
{
struct V_20 * V_21 = V_58 -> V_60 ;
F_12 ( L_2 , V_29 ) ;
if ( F_41 ( V_58 ) < 0 )
return;
F_9 ( V_21 , V_71 ) ;
V_21 -> V_65 |= 0x20 ;
F_3 ( V_21 -> V_8 , V_25 , V_66 , V_21 -> V_65 ) ;
F_45 ( V_58 ) ;
}
static void F_57 ( struct V_72 * V_12 ,
struct V_73 * V_74 )
{
F_12 ( L_2 , V_29 ) ;
V_74 -> V_75 . V_76 . V_77 = V_78 ;
V_74 -> V_75 . V_76 . V_79 = V_80 ;
}
static void F_58 ( struct V_57 * V_58 ,
struct V_73 * V_74 )
{
struct V_20 * V_21 ;
F_12 ( L_2 , V_29 ) ;
F_31 ( & V_59 ) ;
V_21 = V_58 -> V_60 ;
if ( F_18 ( V_21 == NULL ) ) {
F_32 ( & V_59 ) ;
return;
}
V_74 -> V_75 . V_76 . V_77 = V_21 -> V_65 ;
V_74 -> V_75 . V_76 . V_79 = V_21 -> V_24 ;
F_32 ( & V_59 ) ;
}
static void F_59 ( struct V_57 * V_58 ,
struct V_73 * V_74 )
{
struct V_20 * V_21 ;
F_12 ( L_2 , V_29 ) ;
F_31 ( & V_59 ) ;
V_21 = V_58 -> V_60 ;
if ( F_18 ( V_21 == NULL ) ) {
F_32 ( & V_59 ) ;
return;
}
F_33 ( V_21 , V_66 , V_21 -> V_65 ) ;
F_33 ( V_21 , V_26 , V_21 -> V_24 ) ;
F_32 ( & V_59 ) ;
}
static T_3 F_60 ( struct V_57 * V_58 ,
const void * V_81 ,
T_3 V_82 , int V_35 )
{
int V_83 ;
struct V_20 * V_21 = V_58 -> V_60 ;
int V_84 ;
F_12 ( L_13 , V_29 , ( unsigned int ) V_82 ) ;
if ( F_41 ( V_58 ) < 0 )
return 0 ;
F_9 ( V_21 , V_85 ) ;
V_83 = F_61 ( V_21 -> V_8 -> V_12 ,
F_62 ( V_21 -> V_8 -> V_12 , 2 ) ,
( void * ) V_81 , V_82 , & V_84 ,
V_19 ) ;
F_45 ( V_58 ) ;
if ( V_83 ) {
F_6 ( & V_21 -> V_8 -> V_12 -> V_12 ,
L_14 , V_83 ) ;
return 0 ;
}
return V_84 ;
}
static int F_63 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
V_21 = F_64 ( sizeof( struct V_20 ) , V_86 ) ;
if ( V_21 == NULL ) {
F_12 ( L_15 ) ;
return - V_50 ;
}
V_21 -> V_61 = false ;
F_38 ( & V_21 -> V_28 ) ;
F_65 ( & V_21 -> V_42 ) ;
F_39 ( & V_21 -> V_44 ) ;
F_39 ( & V_21 -> V_43 ) ;
F_66 ( V_8 , V_21 ) ;
V_21 -> V_8 = V_8 ;
F_67 ( & V_21 -> V_40 , F_17 ,
( unsigned long ) V_21 ) ;
F_68 ( & V_21 -> V_62 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_87 , ( T_2 ) 0x80 ) ;
F_3 ( V_21 -> V_8 , V_25 , V_87 , ( T_2 ) 0x00 ) ;
V_21 -> V_65 = V_78 ;
F_3 ( V_21 -> V_8 , V_25 , V_66 , V_21 -> V_65 ) ;
V_21 -> V_24 = V_80 ;
F_3 ( V_21 -> V_8 , V_25 , V_26 , V_21 -> V_24 ) ;
V_21 -> V_58 = F_69 ( 0 , V_88 ,
V_89 ,
& V_90 ) ;
if ( V_21 -> V_58 == NULL ) {
F_6 ( & V_8 -> V_91 -> V_12 ,
L_16 ) ;
F_16 ( & V_21 -> V_28 , F_10 ) ;
return - V_92 ;
}
V_21 -> V_58 -> V_60 = V_21 ;
V_21 -> V_58 -> V_93 = V_94 | V_95 ;
V_21 -> V_58 -> V_12 = & V_8 -> V_91 -> V_12 ;
F_70 ( V_21 -> V_58 ) ;
return 0 ;
}
static void F_71 ( struct V_32 * V_32 )
{
int V_96 ;
int V_97 ;
int V_18 = V_32 -> V_18 ;
T_2 * V_9 ;
T_2 V_98 ;
T_2 V_99 ;
switch ( V_18 ) {
case 0 :
break;
case - V_100 :
case - V_101 :
case - V_102 :
F_12 ( L_17 , V_29 ,
V_18 ) ;
return;
default:
F_12 ( L_7 , V_29 ,
V_18 ) ;
goto exit;
}
V_97 = V_32 -> V_103 ;
V_9 = V_32 -> V_104 ;
if ( F_18 ( V_97 != 4 ) ) {
F_12 ( L_18 ) ;
return;
}
V_98 = V_9 [ 3 ] ;
V_99 = V_9 [ 2 ] ;
if ( ( V_98 | V_99 ) & 0x01 ) {
F_12 ( L_19 ) ;
} else {
switch ( V_98 & 0x0f ) {
case V_105 :
F_12 ( L_20
L_21 ) ;
break;
case V_106 :
F_12 ( L_22 ) ;
break;
case V_107 :
break;
}
switch ( V_99 & 0x0f ) {
case V_105 :
F_12 ( L_23
L_24 ) ;
break;
case V_106 :
F_12 ( L_25 ) ;
break;
case V_107 :
break;
}
}
exit:
V_96 = F_28 ( V_32 , V_45 ) ;
if ( V_96 )
F_6 ( & V_32 -> V_12 -> V_12 ,
L_26 ,
V_29 , V_96 ) ;
}
static void F_72 ( struct V_32 * V_32 )
{
int V_96 ;
int V_97 ;
int V_18 = V_32 -> V_18 ;
T_2 * V_9 ;
T_2 V_108 ;
switch ( V_18 ) {
case 0 :
break;
case - V_100 :
case - V_101 :
case - V_102 :
case - V_56 :
F_12 ( L_17 , V_29 ,
V_18 ) ;
return;
default:
F_12 ( L_7 , V_29 ,
V_18 ) ;
goto exit;
}
V_97 = V_32 -> V_103 ;
V_9 = V_32 -> V_104 ;
if ( F_18 ( V_97 != 4 ) ) {
F_12 ( L_18 ) ;
return;
}
V_108 = V_9 [ 0 ] ;
if ( ! ( V_108 & 0x01 ) ) {
switch ( V_108 & 0x0f ) {
case V_105 :
F_12 ( L_27
L_21 ) ;
break;
case V_106 :
F_12 ( L_28 ) ;
break;
case V_107 :
break;
}
}
#ifdef F_73
{
struct V_109 * V_110 = V_32 -> V_47 ;
struct V_20 * V_21 = V_110 -> V_8 -> V_111 ;
if ( F_18 ( V_21 == NULL ) )
return;
F_74 ( & V_21 -> V_70 , V_9 [ 2 ] ) ;
}
#endif
exit:
V_96 = F_28 ( V_32 , V_45 ) ;
if ( V_96 )
F_6 ( & V_32 -> V_12 -> V_12 ,
L_26 ,
V_29 , V_96 ) ;
}
static void F_75 ( struct V_32 * V_32 )
{
int V_83 ;
unsigned char * V_9 ;
struct V_109 * V_110 ;
struct V_112 * V_113 ;
int V_18 = V_32 -> V_18 ;
if ( V_18 ) {
F_12 ( L_29 , V_18 ) ;
return;
}
V_110 = V_32 -> V_47 ;
F_12 ( L_30 , V_29 ) ;
V_9 = V_32 -> V_104 ;
V_113 = F_76 ( & V_110 -> V_110 ) ;
if ( V_113 && V_32 -> V_103 ) {
F_77 ( V_113 , V_9 , V_32 -> V_103 ) ;
F_78 ( V_113 ) ;
}
F_79 ( V_113 ) ;
if ( ! V_110 -> V_114 ) {
F_12 ( L_31 ) ;
return;
}
if ( V_110 -> V_114 -> V_18 != - V_115 ) {
V_110 -> V_114 -> V_12 = V_110 -> V_8 -> V_12 ;
V_83 = F_28 ( V_110 -> V_114 , V_45 ) ;
if ( V_83 )
F_12 ( L_32 ,
V_83 ) ;
}
}
static void F_80 ( struct V_32 * V_32 )
{
struct V_116 * V_117 ;
struct V_112 * V_113 ;
int V_18 = V_32 -> V_18 ;
if ( V_18 ) {
F_12 ( L_33 , V_18 ) ;
return;
}
V_117 = V_32 -> V_47 ;
if ( ! V_117 ) {
F_12 ( L_34 ) ;
return ;
}
V_113 = F_76 ( & V_117 -> V_110 -> V_110 ) ;
if ( V_113 && V_117 -> V_118 )
F_81 ( V_113 ) ;
F_79 ( V_113 ) ;
}
static int F_82 ( struct V_7 * V_8 ,
const struct V_119 * V_120 )
{
if ( V_120 -> V_121 == V_122 )
V_123 . V_124 =
F_72 ;
else
V_123 . V_124 =
F_71 ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 )
{
T_4 V_125 = F_84 ( V_8 -> V_12 -> V_126 . V_121 ) ;
if ( V_125 == V_122 )
return 1 ;
return 2 ;
}
static int F_85 ( struct V_112 * V_113 , struct V_109 * V_110 )
{
struct V_7 * V_8 ;
struct V_109 * V_127 ;
struct V_32 * V_32 ;
struct V_116 * V_117 ;
int V_128 ;
int V_129 ;
T_2 V_9 ;
int V_130 = 0 ;
int V_131 ;
V_8 = V_110 -> V_8 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return - V_56 ;
V_127 = V_8 -> V_110 [ 0 ] ;
F_87 ( V_8 -> V_12 , V_110 -> V_132 -> V_13 ) ;
F_87 ( V_8 -> V_12 , V_110 -> V_114 -> V_13 ) ;
for ( V_131 = 0 ; V_131 < V_133 ; ++ V_131 ) {
V_32 = F_36 ( 0 , V_86 ) ;
V_117 -> V_134 [ V_131 ] = V_32 ;
if ( V_32 == NULL ) {
F_6 ( & V_110 -> V_12 , L_35 ) ;
continue;
}
V_32 -> V_104 = F_34 ( V_135 ,
V_86 ) ;
if ( ! V_32 -> V_104 ) {
F_6 ( & V_110 -> V_12 ,
L_36 ,
V_29 ) ;
F_15 ( V_117 -> V_134 [ V_131 ] ) ;
V_117 -> V_134 [ V_131 ] = NULL ;
continue;
}
V_130 ++ ;
}
if ( ! V_130 )
return - V_50 ;
V_129 = V_110 -> V_136 - V_110 -> V_8 -> V_137 ;
F_7 ( V_8 , V_129 , V_138 , & V_9 ) ;
F_12 ( L_37 , V_117 , V_9 ) ;
F_12 ( L_38 ) ;
F_3 ( V_8 , V_25 , V_5 , 0x02 ) ;
F_3 ( V_8 , V_25 , V_139 , 0x02 ) ;
F_3 ( V_8 , V_129 , V_140 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0xcf ) ;
V_117 -> V_142 = 0x03 ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
V_117 -> V_144 = 0x0b ;
F_3 ( V_8 , V_129 , V_145 , V_117 -> V_144 ) ;
F_3 ( V_8 , V_129 , V_146 , 0x00 ) ;
F_7 ( V_8 , V_25 , V_146 , & V_9 ) ;
V_9 = V_9 | ( V_110 -> V_136 - V_110 -> V_8 -> V_137 + 1 ) ;
F_3 ( V_8 , V_25 , V_146 , V_9 ) ;
V_117 -> V_142 = 0x83 ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
F_3 ( V_8 , V_129 , V_147 , 0x0c ) ;
F_3 ( V_8 , V_129 , V_140 , 0x00 ) ;
V_117 -> V_142 = 0x03 ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
F_3 ( V_8 , V_129 , V_140 , 0x0c ) ;
V_128 = F_28 ( V_110 -> V_114 , V_86 ) ;
if ( V_128 )
F_6 ( & V_110 -> V_12 , L_39 ,
V_29 , V_128 ) ;
memset ( & ( V_117 -> V_148 ) , 0x00 , sizeof( V_117 -> V_148 ) ) ;
V_117 -> V_144 = V_149 ;
V_117 -> V_118 = 1 ;
return 0 ;
}
static int F_88 ( struct V_112 * V_113 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
int V_151 ;
int V_152 = 0 ;
struct V_116 * V_117 ;
F_12 ( L_40 , V_29 ) ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL ) {
F_12 ( L_41 , V_29 ) ;
return 0 ;
}
for ( V_151 = 0 ; V_151 < V_133 ; ++ V_151 ) {
if ( V_117 -> V_134 [ V_151 ] &&
V_117 -> V_134 [ V_151 ] -> V_18 == - V_115 )
V_152 += V_135 ;
}
F_12 ( L_42 , V_29 , V_152 ) ;
return V_152 ;
}
static void F_89 ( struct V_109 * V_110 )
{
struct V_7 * V_8 ;
struct V_116 * V_117 ;
int V_131 ;
F_12 ( L_43 ) ;
V_8 = V_110 -> V_8 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return;
for ( V_131 = 0 ; V_131 < V_133 ; ++ V_131 )
F_90 ( V_117 -> V_134 [ V_131 ] ) ;
for ( V_131 = 0 ; V_131 < V_133 ; ++ V_131 ) {
if ( V_117 -> V_134 [ V_131 ] ) {
F_13 ( V_117 -> V_134 [ V_131 ] -> V_104 ) ;
F_15 ( V_117 -> V_134 [ V_131 ] ) ;
}
}
F_12 ( L_44 ) ;
F_90 ( V_110 -> V_132 ) ;
F_12 ( L_45 ) ;
F_90 ( V_110 -> V_114 ) ;
F_43 ( & V_8 -> V_39 ) ;
if ( ! V_8 -> V_41 ) {
F_3 ( V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_145 , 0x00 ) ;
F_3 ( V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_140 , 0x00 ) ;
}
F_21 ( & V_8 -> V_39 ) ;
V_117 -> V_118 = 0 ;
F_12 ( L_46 , V_29 ) ;
}
static void F_91 ( struct V_112 * V_113 , int V_153 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
unsigned char V_9 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
F_12 ( L_47 , V_29 ) ;
V_8 = V_110 -> V_8 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return;
if ( V_153 == - 1 )
V_9 = V_117 -> V_142 | V_154 ;
else
V_9 = V_117 -> V_142 & ~ V_154 ;
V_117 -> V_142 = V_9 ;
F_3 ( V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_143 , V_117 -> V_142 ) ;
}
static int F_92 ( struct V_112 * V_113 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 ;
int V_155 = 0 ;
int V_151 ;
F_12 ( L_40 , V_29 ) ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL ) {
F_12 ( L_41 , V_29 ) ;
return - V_56 ;
}
for ( V_151 = 0 ; V_151 < V_133 ; ++ V_151 ) {
if ( V_117 -> V_134 [ V_151 ] &&
V_117 -> V_134 [ V_151 ] -> V_18 != - V_115 )
V_155 += V_135 ;
}
F_12 ( L_42 , V_29 , V_155 ) ;
return V_155 ;
}
static int F_93 ( struct V_112 * V_113 , struct V_109 * V_110 ,
const unsigned char * V_9 , int V_156 )
{
int V_18 ;
int V_151 ;
int V_157 = 0 ;
int V_158 ;
struct V_116 * V_117 ;
struct V_7 * V_8 ;
struct V_32 * V_32 ;
const unsigned char * V_159 = V_9 ;
F_12 ( L_40 , V_29 ) ;
V_8 = V_110 -> V_8 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL ) {
F_12 ( L_48 ) ;
return - V_56 ;
}
V_32 = NULL ;
for ( V_151 = 0 ; V_151 < V_133 ; ++ V_151 ) {
if ( V_117 -> V_134 [ V_151 ] &&
V_117 -> V_134 [ V_151 ] -> V_18 != - V_115 ) {
V_32 = V_117 -> V_134 [ V_151 ] ;
F_12 ( L_49 , V_151 ) ;
break;
}
}
if ( V_32 == NULL ) {
F_12 ( L_50 , V_29 ) ;
goto exit;
}
if ( V_32 -> V_104 == NULL ) {
V_32 -> V_104 = F_34 ( V_135 ,
V_86 ) ;
if ( V_32 -> V_104 == NULL ) {
F_6 ( & V_110 -> V_12 , L_51 ,
V_29 ) ;
goto exit;
}
}
V_158 = F_94 ( V_156 , V_135 ) ;
memcpy ( V_32 -> V_104 , V_159 , V_158 ) ;
F_95 ( V_160 , & V_110 -> V_12 , V_29 , V_158 ,
V_32 -> V_104 ) ;
F_96 ( V_32 , V_8 -> V_12 ,
F_62 ( V_8 -> V_12 ,
V_110 -> V_161 ) ,
V_32 -> V_104 , V_158 ,
F_80 , V_117 ) ;
V_18 = F_28 ( V_32 , V_45 ) ;
if ( V_18 ) {
F_6 ( & V_110 -> V_12 , L_52
L_53 , V_29 , V_18 ) ;
V_157 = V_18 ;
goto exit;
}
V_157 = V_158 ;
exit:
return V_157 ;
}
static void F_97 ( struct V_112 * V_113 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 ;
int V_18 ;
F_12 ( L_54 , V_29 , V_110 -> V_136 ) ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_12 ( L_55 ) ;
return;
}
F_12 ( L_56 , V_29 ) ;
if ( F_98 ( V_113 ) ) {
unsigned char V_162 = F_99 ( V_113 ) ;
V_18 = F_93 ( V_113 , V_110 , & V_162 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_113 -> V_163 -> V_164 & V_165 ) {
V_117 -> V_144 &= ~ V_166 ;
F_3 ( V_110 -> V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_145 , V_117 -> V_144 ) ;
if ( V_18 != 0 )
return;
}
}
static void F_100 ( struct V_112 * V_113 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 = F_86 ( V_110 ) ;
int V_18 ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_12 ( L_57 , V_29 ) ;
return;
}
F_12 ( L_56 , V_29 ) ;
if ( F_98 ( V_113 ) ) {
unsigned char V_167 = F_101 ( V_113 ) ;
V_18 = F_93 ( V_113 , V_110 , & V_167 , 1 ) ;
if ( V_18 <= 0 )
return;
}
if ( V_113 -> V_163 -> V_164 & V_165 ) {
V_117 -> V_144 |= V_166 ;
F_3 ( V_110 -> V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_145 , V_117 -> V_144 ) ;
if ( V_18 != 0 )
return;
}
}
static int F_102 ( struct V_116 * V_117 ,
unsigned int V_168 )
{
struct V_109 * V_110 ;
struct V_7 * V_8 ;
int V_129 ;
enum V_1 V_169 ;
if ( V_117 == NULL )
return - V_170 ;
V_110 = V_117 -> V_110 ;
V_8 = V_110 -> V_8 ;
F_12 ( L_58 ) ;
V_129 = V_110 -> V_136 - V_110 -> V_8 -> V_137 ;
F_3 ( V_8 , V_129 , V_140 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0xcf ) ;
V_117 -> V_144 = 0x0b ;
F_3 ( V_8 , V_129 , V_145 , V_117 -> V_144 ) ;
F_3 ( V_8 , V_25 , V_146 , 0x00 ) ;
if ( V_129 == 0 )
V_169 = V_5 ;
else
V_169 = V_139 ;
F_3 ( V_8 , V_25 , V_169 , V_168 * 0x10 ) ;
F_3 ( V_8 , V_25 , V_146 , 0x03 ) ;
V_117 -> V_144 = 0x2b ;
F_3 ( V_8 , V_129 , V_145 , V_117 -> V_144 ) ;
V_117 -> V_142 = V_117 -> V_142 | V_171 ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
F_3 ( V_8 , V_129 , V_172 , 0x01 ) ;
F_3 ( V_8 , V_129 , V_173 , 0x00 ) ;
V_117 -> V_142 = V_117 -> V_142 & ~ V_171 ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
return 0 ;
}
static int F_103 ( int V_174 , int * V_175 )
{
int V_151 ;
T_1 V_176 ;
T_1 V_177 ;
T_1 V_178 ;
F_12 ( L_59 , V_29 , V_174 ) ;
for ( V_151 = 0 ; V_151 < F_104 ( V_179 ) ; V_151 ++ ) {
if ( V_179 [ V_151 ] . V_174 == V_174 ) {
* V_175 = V_179 [ V_151 ] . V_175 ;
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
F_12 ( L_60 , V_174 , V_176 ) ;
return 0 ;
}
F_12 ( L_61 ) ;
return - V_170 ;
}
static int F_105 ( struct V_116 * V_117 ,
int V_174 )
{
struct V_109 * V_110 ;
struct V_7 * V_8 ;
int V_175 ;
int V_18 ;
unsigned char V_136 ;
if ( V_117 == NULL )
return - 1 ;
V_110 = V_117 -> V_110 ;
V_8 = V_110 -> V_8 ;
F_12 ( L_56 , V_29 ) ;
V_136 = V_110 -> V_136 - V_110 -> V_8 -> V_137 ;
F_12 ( L_62 , V_29 , V_110 -> V_136 , V_174 ) ;
V_18 = F_103 ( V_174 , & V_175 ) ;
if ( V_18 ) {
F_6 ( & V_110 -> V_12 , L_63 , V_29 ) ;
return V_18 ;
}
V_117 -> V_142 = V_117 -> V_142 | V_171 ;
F_3 ( V_8 , V_136 , V_143 , V_117 -> V_142 ) ;
F_3 ( V_8 , V_136 , V_172 , ( T_2 ) ( V_175 & 0xff ) ) ;
F_3 ( V_8 , V_136 , V_173 , ( T_2 ) ( ( V_175 & 0xff00 ) >> 8 ) ) ;
V_117 -> V_142 = V_117 -> V_142 & ~ V_171 ;
F_3 ( V_8 , V_136 , V_143 , V_117 -> V_142 ) ;
return V_18 ;
}
static void F_106 ( struct V_112 * V_113 ,
struct V_116 * V_117 ,
struct V_180 * V_181 )
{
struct V_109 * V_110 ;
struct V_7 * V_8 ;
int V_168 ;
unsigned V_182 ;
unsigned V_183 ;
T_2 V_68 = 0xff ;
T_2 V_184 ;
T_2 V_185 ;
T_2 V_186 ;
int V_18 ;
int V_129 ;
if ( V_117 == NULL )
return ;
V_110 = V_117 -> V_110 ;
V_8 = V_110 -> V_8 ;
V_129 = V_110 -> V_136 - V_110 -> V_8 -> V_137 ;
F_12 ( L_64 , V_29 , V_110 -> V_136 ) ;
if ( ! V_117 -> V_118 ) {
F_12 ( L_57 , V_29 ) ;
return;
}
F_12 ( L_56 , V_29 ) ;
V_184 = V_187 ;
V_186 = 0x00 ;
V_185 = 0x00 ;
V_182 = V_113 -> V_163 -> V_164 ;
V_183 = V_113 -> V_163 -> V_188 ;
switch ( V_182 & V_189 ) {
case V_190 :
V_184 = V_191 ;
V_68 = 0x1f ;
break;
case V_192 :
V_184 = V_193 ;
V_68 = 0x3f ;
break;
case V_194 :
V_184 = V_195 ;
V_68 = 0x7f ;
break;
default:
case V_196 :
V_184 = V_187 ;
break;
}
if ( V_182 & V_197 ) {
if ( V_182 & V_198 ) {
V_185 = V_199 ;
F_12 ( L_65 , V_29 ) ;
} else {
V_185 = ( V_200 | V_199 ) ;
F_12 ( L_66 , V_29 ) ;
}
} else {
F_12 ( L_67 , V_29 ) ;
}
if ( V_182 & V_201 )
V_185 = V_185 | 0x20 ;
if ( V_182 & V_202 ) {
V_186 = V_203 ;
F_12 ( L_68 , V_29 ) ;
} else {
V_186 = 0x00 ;
F_12 ( L_69 , V_29 ) ;
}
#define F_107 0x03
#define F_108 0x04
#define F_109 0x38
V_117 -> V_142 &=
~ ( F_107 | F_108 | F_109 ) ;
V_117 -> V_142 |= ( V_184 | V_185 | V_186 ) ;
F_3 ( V_8 , V_129 , V_140 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0x00 ) ;
F_3 ( V_8 , V_129 , V_141 , 0xcf ) ;
F_3 ( V_8 , V_129 , V_143 , V_117 -> V_142 ) ;
V_117 -> V_144 = 0x0b ;
F_3 ( V_8 , V_129 , V_145 , V_117 -> V_144 ) ;
V_117 -> V_144 = V_149 ;
if ( V_182 & V_204 )
V_117 -> V_144 |= ( V_205 | V_166 ) ;
if ( V_182 & V_165 ) {
V_117 -> V_144 |= ( V_206 ) ;
if ( V_110 -> V_136 )
F_3 ( V_8 , V_25 , V_146 , 0x01 ) ;
else
F_3 ( V_8 , V_25 , V_146 , 0x02 ) ;
} else
V_117 -> V_144 &= ~ ( V_206 ) ;
F_3 ( V_8 , V_129 , V_145 , V_117 -> V_144 ) ;
V_168 = F_110 ( V_113 ) ;
if ( ! V_168 ) {
F_12 ( L_70 ) ;
V_168 = 9600 ;
}
if ( V_168 >= 230400 ) {
F_102 ( V_117 , V_168 ) ;
F_3 ( V_8 , V_129 , V_140 , 0x0c ) ;
return;
}
F_12 ( L_71 , V_29 , V_168 ) ;
V_18 = F_105 ( V_117 , V_168 ) ;
if ( V_182 & V_204 )
F_111 ( V_113 , V_168 , V_168 ) ;
F_3 ( V_8 , V_129 , V_140 , 0x0c ) ;
if ( V_110 -> V_114 -> V_18 != - V_115 ) {
V_110 -> V_114 -> V_12 = V_8 -> V_12 ;
V_18 = F_28 ( V_110 -> V_114 , V_45 ) ;
if ( V_18 )
F_12 ( L_72 ,
V_18 ) ;
}
}
static void F_112 ( struct V_112 * V_113 ,
struct V_109 * V_110 , struct V_180 * V_181 )
{
int V_18 ;
unsigned int V_182 ;
struct V_7 * V_8 ;
struct V_116 * V_117 ;
V_8 = V_110 -> V_8 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return;
if ( ! V_117 -> V_118 ) {
F_12 ( L_57 , V_29 ) ;
return;
}
F_12 ( L_73 , L_74 ) ;
V_182 = V_113 -> V_163 -> V_164 ;
F_12 ( L_75 , V_29 ,
V_113 -> V_163 -> V_164 ,
F_113 ( V_113 -> V_163 -> V_188 ) ) ;
F_12 ( L_76 , V_29 ,
V_181 -> V_164 ,
F_113 ( V_181 -> V_188 ) ) ;
F_12 ( L_64 , V_29 , V_110 -> V_136 ) ;
F_106 ( V_113 , V_117 , V_181 ) ;
if ( ! V_110 -> V_114 ) {
F_12 ( L_77 , L_78 ) ;
return;
}
if ( V_110 -> V_114 -> V_18 != - V_115 ) {
V_110 -> V_114 -> V_12 = V_8 -> V_12 ;
V_18 = F_28 ( V_110 -> V_114 , V_45 ) ;
if ( V_18 )
F_12 ( L_72 ,
V_18 ) ;
}
}
static int F_114 ( struct V_112 * V_113 ,
struct V_116 * V_117 , unsigned int T_5 * V_17 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
unsigned int V_96 = 0 ;
unsigned char V_9 = 0 ;
int V_129 = V_110 -> V_136 - V_110 -> V_8 -> V_137 ;
int V_156 ;
V_156 = F_88 ( V_113 ) ;
if ( V_156 == 0 ) {
F_7 ( V_110 -> V_8 , V_129 , V_138 , & V_9 ) ;
if ( ( V_9 & ( V_207 | V_208 ) )
== ( V_207 | V_208 ) ) {
F_12 ( L_79 , V_29 ) ;
V_96 = V_209 ;
}
}
if ( F_115 ( V_17 , & V_96 , sizeof( int ) ) )
return - V_210 ;
return 0 ;
}
static int F_116 ( struct V_112 * V_113 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 = F_86 ( V_110 ) ;
unsigned int V_96 = 0 ;
unsigned int V_211 ;
unsigned int V_212 ;
F_12 ( L_64 , V_29 , V_110 -> V_136 ) ;
V_211 = V_117 -> V_144 ;
V_212 = V_117 -> V_213 ;
V_96 = ( ( V_211 & V_205 ) ? V_214 : 0 )
| ( ( V_211 & V_166 ) ? V_215 : 0 )
| ( ( V_212 & V_216 ) ? V_217 : 0 )
| ( ( V_212 & V_218 ) ? V_219 : 0 )
| ( ( V_212 & V_220 ) ? V_221 : 0 )
| ( ( V_212 & V_222 ) ? V_223 : 0 ) ;
F_12 ( L_80 , V_29 , V_96 ) ;
return V_96 ;
}
static int F_117 ( struct V_112 * V_113 ,
unsigned int V_224 , unsigned int V_225 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 = F_86 ( V_110 ) ;
unsigned int V_211 ;
F_12 ( L_64 , V_29 , V_110 -> V_136 ) ;
F_12 ( L_81 ) ;
V_211 = V_117 -> V_144 ;
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
V_117 -> V_144 = V_211 ;
F_3 ( V_110 -> V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_145 , V_117 -> V_144 ) ;
return 0 ;
}
static int F_118 ( struct V_112 * V_113 ,
struct V_228 * V_148 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 ;
struct V_229 V_230 ;
V_117 = F_86 ( V_110 ) ;
V_230 = V_117 -> V_148 ;
V_148 -> V_231 = V_230 . V_231 ;
V_148 -> V_232 = V_230 . V_232 ;
V_148 -> V_233 = V_230 . V_233 ;
V_148 -> V_234 = V_230 . V_234 ;
V_148 -> V_235 = V_230 . V_235 ;
V_148 -> V_236 = V_230 . V_236 ;
V_148 -> V_237 = V_230 . V_237 ;
V_148 -> V_238 = V_230 . V_238 ;
V_148 -> V_239 = V_230 . V_239 ;
V_148 -> V_240 = V_230 . V_240 ;
V_148 -> V_241 = V_230 . V_241 ;
F_12 ( L_82 , V_29 ,
V_110 -> V_136 , V_148 -> V_235 , V_148 -> V_236 ) ;
return 0 ;
}
static int F_119 ( struct V_116 * V_117 , unsigned int V_242 ,
unsigned int T_5 * V_17 )
{
unsigned int V_211 ;
unsigned int V_243 ;
struct V_109 * V_110 ;
if ( V_117 == NULL )
return - 1 ;
V_110 = (struct V_109 * ) V_117 -> V_110 ;
V_211 = V_117 -> V_144 ;
if ( F_120 ( & V_243 , V_17 , sizeof( int ) ) )
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
V_117 -> V_144 = V_211 ;
F_3 ( V_110 -> V_8 , V_110 -> V_136 - V_110 -> V_8 -> V_137 ,
V_145 , V_117 -> V_144 ) ;
return 0 ;
}
static int F_121 ( struct V_116 * V_117 ,
struct V_246 T_5 * V_247 )
{
struct V_246 V_248 ;
if ( ! V_247 )
return - V_210 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_248 . type = V_249 ;
V_248 . line = V_117 -> V_110 -> V_8 -> V_137 ;
V_248 . V_110 = V_117 -> V_110 -> V_136 ;
V_248 . V_250 = 0 ;
V_248 . V_35 = V_251 | V_252 ;
V_248 . V_253 = V_133 * V_135 ;
V_248 . V_254 = 9600 ;
V_248 . V_255 = 5 * V_256 ;
V_248 . V_257 = 30 * V_256 ;
if ( F_115 ( V_247 , & V_248 , sizeof( * V_247 ) ) )
return - V_210 ;
return 0 ;
}
static int F_122 ( struct V_112 * V_113 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_109 * V_110 = V_113 -> V_150 ;
struct V_116 * V_117 ;
struct V_229 V_230 ;
struct V_229 V_258 ;
V_117 = F_86 ( V_110 ) ;
if ( V_117 == NULL )
return - V_56 ;
F_12 ( L_83 , V_29 , V_110 -> V_136 , V_242 ) ;
switch ( V_242 ) {
case V_259 :
F_12 ( L_84 , V_29 , V_110 -> V_136 ) ;
return F_114 ( V_113 , V_117 ,
( unsigned int T_5 * ) V_243 ) ;
case V_244 :
case V_245 :
F_12 ( L_85 ,
V_29 , V_110 -> V_136 ) ;
return F_119 ( V_117 , V_242 ,
( unsigned int T_5 * ) V_243 ) ;
case V_260 :
F_12 ( L_86 , V_29 , V_110 -> V_136 ) ;
return F_121 ( V_117 ,
(struct V_246 T_5 * ) V_243 ) ;
case V_261 :
F_12 ( L_87 , V_29 , V_110 -> V_136 ) ;
V_258 = V_117 -> V_148 ;
while ( 1 ) {
if ( F_123 ( V_262 ) )
return - V_263 ;
V_230 = V_117 -> V_148 ;
if ( V_230 . V_233 == V_258 . V_233 && V_230 . V_232 == V_258 . V_232 &&
V_230 . V_234 == V_258 . V_234 && V_230 . V_231 == V_258 . V_231 )
return - V_92 ;
if ( ( ( V_243 & V_264 ) && ( V_230 . V_233 != V_258 . V_233 ) ) ||
( ( V_243 & V_223 ) && ( V_230 . V_232 != V_258 . V_232 ) ) ||
( ( V_243 & V_265 ) && ( V_230 . V_234 != V_258 . V_234 ) ) ||
( ( V_243 & V_217 ) && ( V_230 . V_231 != V_258 . V_231 ) ) ) {
return 0 ;
}
V_258 = V_230 ;
}
break;
}
return - V_266 ;
}
static int F_124 ( struct V_7 * V_8 )
{
struct V_116 * V_117 ;
struct V_10 * V_12 ;
int V_151 ;
char V_9 ;
T_4 V_125 ;
int V_34 ;
F_12 ( L_56 , V_29 ) ;
if ( ! V_8 ) {
F_12 ( L_88 ) ;
return - V_56 ;
}
V_125 = F_84 ( V_8 -> V_12 -> V_126 . V_121 ) ;
V_12 = V_8 -> V_12 ;
if ( V_125 == V_122 ) {
struct V_109 * V_248 = V_8 -> V_110 [ 0 ] ;
V_8 -> V_110 [ 0 ] = V_8 -> V_110 [ 1 ] ;
V_8 -> V_110 [ 1 ] = V_248 ;
V_8 -> V_110 [ 0 ] -> V_267 = V_248 -> V_267 ;
V_8 -> V_110 [ 0 ] -> V_268 = V_248 -> V_268 ;
V_8 -> V_110 [ 0 ] -> V_269 =
V_248 -> V_269 ;
V_8 -> V_110 [ 1 ] -> V_267 = NULL ;
V_8 -> V_110 [ 1 ] -> V_268 = NULL ;
}
for ( V_151 = 0 ; V_151 < V_8 -> V_270 ; ++ V_151 ) {
V_117 = F_64 ( sizeof( struct V_116 ) , V_86 ) ;
if ( V_117 == NULL ) {
F_6 ( & V_12 -> V_12 , L_89 , V_29 ) ;
return - V_50 ;
}
V_8 -> V_110 [ V_151 ] -> V_269 =
V_8 -> V_110 [ 0 ] -> V_269 ;
V_117 -> V_110 = V_8 -> V_110 [ V_151 ] ;
F_125 ( V_8 -> V_110 [ V_151 ] , V_117 ) ;
F_12 ( L_90 , V_8 -> V_110 [ V_151 ] -> V_136 ) ;
F_12 ( L_91 , V_8 -> V_137 ) ;
}
F_5 ( V_8 -> V_12 , F_4 ( V_8 -> V_12 , 0 ) ,
( T_2 ) 0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 , 5 * V_256 ) ;
V_34 = F_28 ( V_8 -> V_110 [ 0 ] -> V_267 , V_86 ) ;
if ( V_34 )
F_6 ( & V_12 -> V_12 ,
L_26 ,
V_29 , V_34 ) ;
#ifdef F_73
if ( V_125 == V_122 ) {
V_34 = F_63 ( V_8 ) ;
if ( V_34 < 0 )
return V_34 ;
}
#endif
F_7 ( V_8 , 0 , V_138 , & V_9 ) ;
F_12 ( L_92 , V_9 ) ;
return 0 ;
}
static void F_126 ( struct V_7 * V_8 )
{
int V_151 ;
#ifdef F_73
if ( F_84 ( V_8 -> V_12 -> V_126 . V_121 )
== V_122 ) {
struct V_30 * V_31 ;
unsigned long V_35 ;
struct V_20 * V_21 =
F_127 ( V_8 ) ;
F_31 ( & V_59 ) ;
V_21 -> V_58 -> V_60 = NULL ;
F_32 ( & V_59 ) ;
if ( V_21 -> V_61 )
F_128 ( & V_21 -> V_62 ,
V_19 ) ;
F_129 ( V_21 -> V_58 ) ;
F_66 ( V_8 , NULL ) ;
V_21 -> V_8 = NULL ;
F_130 ( & V_21 -> V_40 ) ;
F_22 ( & V_21 -> V_42 , V_35 ) ;
F_27 (urbtrack,
&mos_parport->active_urbs,
urblist_entry)
F_131 ( V_31 -> V_32 ) ;
F_24 ( & V_21 -> V_42 , V_35 ) ;
F_16 ( & V_21 -> V_28 , F_10 ) ;
}
#endif
for ( V_151 = 0 ; V_151 < V_8 -> V_270 ; ++ V_151 )
F_13 ( F_86 ( V_8 -> V_110 [ V_151 ] ) ) ;
}
static int T_6 F_132 ( void )
{
int V_83 ;
F_12 ( L_56 , V_29 ) ;
V_83 = F_133 ( & V_123 ) ;
if ( V_83 )
goto V_271;
F_134 (KERN_INFO KBUILD_MODNAME L_93 DRIVER_VERSION L_94
DRIVER_DESC L_95 ) ;
V_83 = F_135 ( & V_272 ) ;
if ( V_83 )
goto V_273;
return 0 ;
V_273:
F_136 ( & V_123 ) ;
V_271:
return V_83 ;
}
static void T_7 F_137 ( void )
{
F_138 ( & V_272 ) ;
F_136 ( & V_123 ) ;
}
