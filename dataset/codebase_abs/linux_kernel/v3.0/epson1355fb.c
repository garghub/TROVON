static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_6 = F_1 ( V_2 , V_3 ) ;
T_1 V_7 = F_1 ( V_2 , V_3 + 1 ) ;
return ( V_7 << 8 ) | V_6 ;
}
static inline void F_6 ( struct V_1 * V_2 , T_2 V_5 , int V_3 )
{
T_1 V_6 = V_5 & 0xff ;
T_1 V_7 = ( V_5 >> 8 ) & 0xff ;
F_3 ( V_2 , V_6 , V_3 ) ;
F_3 ( V_2 , V_7 , V_3 + 1 ) ;
}
static inline T_3 F_7 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_8 = F_1 ( V_2 , V_3 ) ;
T_1 V_9 = F_1 ( V_2 , V_3 + 1 ) ;
T_1 V_10 = F_1 ( V_2 , V_3 + 2 ) ;
return ( V_10 & 0x0f ) << 16 | ( V_9 << 8 ) | V_8 ;
}
static inline void F_8 ( struct V_1 * V_2 , T_3 V_5 , int V_3 )
{
T_1 V_8 = V_5 & 0xff ;
T_1 V_9 = ( V_5 >> 8 ) & 0xff ;
T_1 V_10 = ( V_5 >> 16 ) & 0x0f ;
F_3 ( V_2 , V_8 , V_3 ) ;
F_3 ( V_2 , V_9 , V_3 + 1 ) ;
F_3 ( V_2 , V_10 , V_3 + 2 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 , T_1 V_12 , T_1 V_13 )
{
F_3 ( V_2 , V_3 , V_14 ) ;
F_3 ( V_2 , V_11 , V_15 ) ;
F_3 ( V_2 , V_12 , V_15 ) ;
F_3 ( V_2 , V_13 , V_15 ) ;
}
static int F_10 ( unsigned V_16 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 , unsigned V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_19 -> V_20 . V_21 )
V_11 = V_12 = V_13 = ( 19595 * V_11 + 38470 * V_12 + 7471 * V_13 ) >> 16 ;
switch ( V_19 -> V_22 . V_23 ) {
case V_24 :
if ( V_16 >= 16 )
return - V_25 ;
( ( T_3 * ) V_19 -> V_26 ) [ V_16 ] =
( V_11 & 0xf800 ) | ( V_12 & 0xfc00 ) >> 5 | ( V_13 & 0xf800 ) >> 11 ;
break;
case V_27 :
if ( V_16 >= 256 )
return - V_25 ;
F_9 ( V_2 , V_16 , V_11 >> 8 , V_12 >> 8 , V_13 >> 8 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_11 ( struct V_29 * V_20 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_3 V_30 ;
if ( V_20 -> V_31 != 0 )
return - V_25 ;
if ( V_20 -> V_32 + V_19 -> V_20 . V_33 > V_19 -> V_20 . V_34 )
return - V_25 ;
V_30 = ( V_19 -> V_22 . V_35 >> 1 ) * V_20 -> V_32 ;
F_8 ( V_2 , V_30 , V_36 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_37 )
{
T_1 V_38 = F_1 ( V_2 , V_39 ) ;
if ( V_37 )
V_38 |= 1 ;
else
V_38 &= ~ 1 ;
F_3 ( V_2 , V_38 , V_39 ) ;
}
static void F_13 ( int V_37 )
{
T_1 V_40 = F_14 ( V_41 ) ;
if ( V_37 )
V_40 |= ( 1 << 5 ) ;
else
V_40 &= ~ ( 1 << 5 ) ;
F_15 ( V_40 , V_41 ) ;
}
static void F_13 ( int V_37 )
{
}
static int F_16 ( int V_42 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
switch ( V_42 ) {
case V_43 :
case V_44 :
F_12 ( V_2 , 1 ) ;
F_13 ( 1 ) ;
break;
case V_45 :
case V_46 :
F_13 ( 0 ) ;
break;
case V_47 :
F_13 ( 0 ) ;
F_12 ( V_2 , 0 ) ;
break;
default:
return - V_25 ;
}
return ( V_42 == V_44 ) ? 1 : 0 ;
}
static inline void F_17 ( unsigned long V_48 , unsigned long * V_49 )
{
T_2 * V_50 = ( T_2 * ) V_49 ;
T_2 V_51 = V_48 & 0xffff ;
T_2 V_52 = V_48 >> 16 ;
F_18 ( V_51 , V_50 ) ;
F_18 ( V_52 , V_50 + 1 ) ;
}
static inline unsigned long F_19 ( const unsigned long * V_49 )
{
const T_2 * V_50 = ( T_2 * ) V_49 ;
T_2 V_51 = F_20 ( V_50 ) ;
T_2 V_52 = F_20 ( V_50 + 1 ) ;
return ( V_52 << 16 ) | V_51 ;
}
static inline unsigned long F_21 ( void * V_53 , const void * V_54 ,
unsigned long V_55 )
{
T_2 * V_56 = ( T_2 * ) V_53 ;
T_2 * V_57 = ( T_2 * ) V_54 ;
if ( ! F_22 ( V_58 , V_54 , V_55 ) )
return V_55 ;
while ( V_55 > 1 ) {
T_2 V_48 ;
if ( F_23 ( V_48 , V_57 ) )
return V_55 ;
F_18 ( V_48 , V_56 ) ;
V_57 ++ , V_56 ++ ;
V_55 -= 2 ;
}
if ( V_55 ) {
T_1 V_48 ;
if ( F_23 ( V_48 , ( ( T_1 * ) V_57 ) ) )
return V_55 ;
F_24 ( V_48 , V_56 ) ;
}
return 0 ;
}
static inline unsigned long F_25 ( void * V_53 , const void * V_54 ,
unsigned long V_55 )
{
T_2 * V_56 = ( T_2 * ) V_53 ;
T_2 * V_57 = ( T_2 * ) V_54 ;
if ( ! F_22 ( V_59 , V_53 , V_55 ) )
return V_55 ;
while ( V_55 > 1 ) {
T_2 V_48 = F_20 ( V_57 ) ;
if ( F_26 ( V_48 , V_56 ) )
return V_55 ;
V_57 ++ , V_56 ++ ;
V_55 -= 2 ;
}
if ( V_55 ) {
T_1 V_48 = F_27 ( V_57 ) ;
if ( F_26 ( V_48 , ( ( T_1 * ) V_56 ) ) )
return V_55 ;
}
return 0 ;
}
static T_4
F_28 ( struct V_18 * V_19 , char * V_60 , T_5 V_61 , T_6 * V_62 )
{
unsigned long V_50 = * V_62 ;
if ( V_50 >= V_19 -> V_22 . V_63 )
return 0 ;
if ( V_61 >= V_19 -> V_22 . V_63 )
V_61 = V_19 -> V_22 . V_63 ;
if ( V_61 + V_50 > V_19 -> V_22 . V_63 )
V_61 = V_19 -> V_22 . V_63 - V_50 ;
if ( V_61 ) {
char * V_64 ;
V_64 = V_19 -> V_65 ;
V_61 -= F_25 ( V_60 , V_64 + V_50 , V_61 ) ;
if ( ! V_61 )
return - V_66 ;
* V_62 += V_61 ;
}
return V_61 ;
}
static T_4
F_29 ( struct V_18 * V_19 , const char * V_60 ,
T_5 V_61 , T_6 * V_62 )
{
unsigned long V_50 = * V_62 ;
int V_67 ;
if ( V_50 > V_19 -> V_22 . V_63 )
return - V_68 ;
if ( V_61 >= V_19 -> V_22 . V_63 )
V_61 = V_19 -> V_22 . V_63 ;
V_67 = 0 ;
if ( V_61 + V_50 > V_19 -> V_22 . V_63 ) {
V_61 = V_19 -> V_22 . V_63 - V_50 ;
V_67 = - V_68 ;
}
if ( V_61 ) {
char * V_64 ;
V_64 = V_19 -> V_65 ;
V_61 -= F_21 ( V_64 + V_50 , V_60 , V_61 ) ;
* V_62 += V_61 ;
V_67 = - V_66 ;
}
if ( V_61 )
return V_61 ;
return V_67 ;
}
static T_7 unsigned int F_30 ( struct V_18 * V_19 )
{
unsigned int V_69 = 2 * 1024 * 1024 ;
char * V_50 = V_19 -> V_65 ;
F_24 ( 1 , V_50 ) ;
F_24 ( 0 , V_50 + 0x80000 ) ;
if ( ! F_27 ( V_50 ) )
V_69 = 512 * 1024 ;
F_24 ( 0 , V_50 ) ;
return V_69 ;
}
static void T_7 F_31 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_29 * V_20 = & V_19 -> V_20 ;
struct V_70 * V_22 = & V_19 -> V_22 ;
T_1 V_71 , V_72 ;
T_2 V_73 ;
T_3 V_74 , V_33 ;
T_3 V_75 , V_34 ;
int V_76 , V_77 ;
int V_78 , V_79 , V_80 ;
int V_81 , V_82 ;
V_22 -> type = V_83 ;
V_72 = F_1 ( V_2 , V_39 ) ;
V_76 = V_84 [ ( V_72 >> 2 ) & 7 ] ;
switch ( V_76 ) {
case 8 :
V_22 -> V_23 = V_27 ;
V_20 -> V_85 = 8 ;
V_20 -> V_86 . V_73 = V_20 -> V_87 . V_73 = V_20 -> V_88 . V_73 = 0 ;
V_20 -> V_86 . V_89 = V_20 -> V_87 . V_89 = V_20 -> V_88 . V_89 = 8 ;
break;
case 16 :
V_22 -> V_23 = V_24 ;
V_20 -> V_85 = 16 ;
V_20 -> V_86 . V_73 = 11 ;
V_20 -> V_86 . V_89 = 5 ;
V_20 -> V_87 . V_73 = 5 ;
V_20 -> V_87 . V_89 = 6 ;
V_20 -> V_88 . V_73 = 0 ;
V_20 -> V_88 . V_89 = 5 ;
break;
default:
F_32 () ;
}
F_33 ( & ( V_19 -> V_90 ) , 256 , 0 ) ;
V_71 = F_1 ( V_2 , V_91 ) ;
V_78 = ( V_71 & 0x04 ) != 0 ;
V_79 = ( V_71 & 0x02 ) != 0 ;
V_80 = ( V_71 & 0x01 ) != 0 ;
V_82 = ( V_72 & 0x02 ) != 0 ;
V_81 = ( V_72 & 0x01 ) != 0 ;
V_77 = V_92 [ V_80 ] [ ( V_71 >> 4 ) & 3 ] ;
V_74 = ( F_1 ( V_2 , V_93 ) + 1 ) * 8 ;
V_33 = ( F_5 ( V_2 , V_94 ) + 1 ) *
( ( V_79 && ! V_82 ) ? 2 : 1 ) ;
V_73 = F_5 ( V_2 , V_95 ) & 0x7ff ;
V_75 = V_73 * 16 / V_76 ;
V_34 = V_22 -> V_63 / ( V_73 * 2 ) ;
V_20 -> V_74 = V_74 ;
V_20 -> V_33 = V_33 ;
V_20 -> V_75 = V_75 ;
V_20 -> V_34 = V_34 ;
V_20 -> V_31 = V_20 -> V_32 = 0 ;
V_22 -> V_35 = V_73 * 2 ;
V_22 -> V_96 = 0 ;
V_22 -> V_97 = 1 ;
V_22 -> V_98 = 0 ;
V_22 -> V_99 = V_100 ;
V_20 -> V_21 = ! V_78 ;
#ifdef F_34
F_35 ( V_101
L_1
L_2 ,
V_74 , V_33 , V_78 , V_79 , V_80 ) ;
F_35 ( V_101
L_3
L_4 ,
V_76 , V_77 , V_82 , V_81 ) ;
#endif
}
static void F_36 ( struct V_18 * V_19 )
{
T_2 * V_56 = ( T_2 * ) V_19 -> V_65 ;
unsigned long V_55 = V_19 -> V_22 . V_63 ;
while ( V_55 > 1 ) {
F_18 ( 0 , V_56 ) ;
V_56 ++ , V_55 -= 2 ;
}
if ( V_55 )
F_24 ( 0 , V_56 ) ;
}
static int F_37 ( struct V_102 * V_103 )
{
struct V_18 * V_19 = F_38 ( V_103 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_13 ( 0 ) ;
if ( V_2 ) {
F_12 ( V_2 , 0 ) ;
if ( V_2 && V_2 -> V_4 )
F_39 ( ( void * ) V_2 -> V_4 ) ;
}
if ( V_19 ) {
F_40 ( & V_19 -> V_90 ) ;
if ( V_19 -> V_65 )
F_39 ( V_19 -> V_65 ) ;
F_41 ( V_19 ) ;
}
F_42 ( V_104 , V_105 ) ;
F_42 ( V_106 , V_107 ) ;
return 0 ;
}
int T_8 F_43 ( struct V_102 * V_103 )
{
struct V_1 * V_108 ;
struct V_18 * V_19 ;
T_1 V_109 ;
int V_110 = 0 ;
if ( ! F_44 ( V_106 , V_107 , L_5 ) ) {
F_35 ( V_111 L_6
L_7 , V_106 ) ;
V_110 = - V_112 ;
goto V_113;
}
if ( ! F_44 ( V_104 , V_105 ,
L_8 ) ) {
F_35 ( V_111 L_6
L_9 , V_104 ) ;
V_110 = - V_112 ;
goto V_113;
}
V_19 = F_45 ( sizeof( struct V_1 ) , & V_103 -> V_103 ) ;
if ( ! V_19 ) {
V_110 = - V_114 ;
goto V_113;
}
V_108 = V_19 -> V_2 ;
V_108 -> V_4 = ( unsigned long ) F_46 ( V_106 , V_107 ) ;
if ( ! V_108 -> V_4 ) {
F_35 ( V_111 L_10 ) ;
V_110 = - V_114 ;
goto V_113;
}
V_19 -> V_26 = V_108 -> V_26 ;
V_19 -> V_65 = F_46 ( V_104 , V_105 ) ;
if ( ! V_19 -> V_65 ) {
F_35 ( V_111 L_11 ) ;
V_110 = - V_114 ;
goto V_113;
}
V_109 = F_1 ( V_108 , V_115 ) ;
if ( ( V_109 >> 2 ) != 3 ) {
F_35 ( V_101 L_12 ) ;
V_110 = - V_116 ;
goto V_113;
}
V_19 -> V_22 . V_117 = V_106 ;
V_19 -> V_22 . V_118 = V_107 ;
V_19 -> V_22 . V_119 = V_104 ;
V_19 -> V_22 . V_63 = F_30 ( V_19 ) ;
F_35 ( V_101 L_13 ,
V_108 -> V_4 , V_19 -> V_22 . V_63 / 1024 , V_19 -> V_65 ) ;
strcpy ( V_19 -> V_22 . V_120 , L_14 ) ;
V_19 -> V_2 = V_108 ;
V_19 -> V_121 = & V_122 ;
V_19 -> V_123 = V_124 | V_125 ;
F_31 ( V_19 , V_108 ) ;
F_36 ( V_19 ) ;
F_13 ( 1 ) ;
F_12 ( V_108 , 1 ) ;
if ( F_47 ( V_19 ) < 0 ) {
V_110 = - V_25 ;
goto V_113;
}
F_48 ( V_103 , V_19 ) ;
F_35 ( V_101 L_15 ,
V_19 -> V_126 , V_19 -> V_22 . V_120 ) ;
return 0 ;
V_113:
F_37 ( V_103 ) ;
return V_110 ;
}
int T_7 F_49 ( void )
{
int V_127 = 0 ;
if ( F_50 ( L_16 , NULL ) )
return - V_116 ;
V_127 = F_51 ( & V_128 ) ;
if ( ! V_127 ) {
V_129 = F_52 ( L_16 , 0 ) ;
if ( V_129 )
V_127 = F_53 ( V_129 ) ;
else
V_127 = - V_114 ;
if ( V_127 ) {
F_54 ( V_129 ) ;
F_55 ( & V_128 ) ;
}
}
return V_127 ;
}
static void T_9 F_56 ( void )
{
F_57 ( V_129 ) ;
F_55 ( & V_128 ) ;
}
