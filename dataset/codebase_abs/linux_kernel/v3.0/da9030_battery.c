static inline int F_1 ( int V_1 )
{
return ( ( V_1 * 2650 ) >> 8 ) + 2650 ;
}
static inline int F_2 ( int V_2 )
{
return ( ( V_2 - 2650 ) << 8 ) / 2650 ;
}
static inline int F_3 ( int V_1 )
{
return ( ( V_1 * 24000 ) >> 8 ) / 15 ;
}
static int F_4 ( struct V_3 * V_4 , void * V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
F_5 ( V_4 , L_1 , V_7 -> V_9 ? L_2 : L_3 ) ;
if ( V_7 -> V_10 ) {
F_5 ( V_4 , L_4 ,
V_7 -> V_11 , V_7 -> V_2 ) ;
}
F_5 ( V_4 , L_5 ,
V_7 -> V_12 . V_13 ,
F_1 ( V_7 -> V_12 . V_13 ) ) ;
F_5 ( V_4 , L_6 ,
V_7 -> V_12 . V_14 ,
F_1 ( V_7 -> V_12 . V_14 ) ) ;
F_5 ( V_4 , L_7 ,
V_7 -> V_12 . V_15 ,
F_1 ( V_7 -> V_12 . V_15 ) ) ;
F_5 ( V_4 , L_8 ,
V_7 -> V_12 . V_16 ,
F_1 ( V_7 -> V_12 . V_16 ) ) ;
F_5 ( V_4 , L_9 ,
V_7 -> V_12 . V_17 ,
F_3 ( V_7 -> V_12 . V_17 ) ) ;
F_5 ( V_4 , L_10 ,
V_7 -> V_12 . V_18 ,
F_3 ( V_7 -> V_12 . V_18 ) ) ;
F_5 ( V_4 , L_11 ,
V_7 -> V_12 . V_19 ,
F_3 ( V_7 -> V_12 . V_19 ) ) ;
F_5 ( V_4 , L_12 ,
V_7 -> V_12 . V_20 ,
F_1 ( V_7 -> V_12 . V_20 ) ) ;
return 0 ;
}
static int F_6 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_7 ( V_22 , F_4 , V_21 -> V_23 ) ;
}
static struct V_24 * F_8 ( struct V_6 * V_7 )
{
V_7 -> V_25 = F_9 ( L_13 , 0666 , 0 , V_7 ,
& V_26 ) ;
return V_7 -> V_25 ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_7 -> V_25 ) ;
}
static inline struct V_24 * F_8 ( struct V_6 * V_7 )
{
return NULL ;
}
static inline void F_10 ( struct V_6 * V_7 )
{
}
static inline void F_12 ( struct V_6 * V_7 ,
struct V_27 * V_12 )
{
F_13 ( V_7 -> V_28 , V_29 ,
sizeof( * V_12 ) , ( V_30 * ) V_12 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
V_30 V_31 ;
F_15 ( V_7 -> V_28 , V_32 , & V_31 ) ;
V_7 -> V_9 = ( V_31 & V_33 ) ? 1 : 0 ;
V_7 -> V_11 = ( ( V_31 >> 3 ) & 0xf ) * 100 ;
V_7 -> V_2 = ( V_31 & 0x7 ) * 50 + 4000 ;
F_12 ( V_7 , & V_7 -> V_12 ) ;
F_15 ( V_7 -> V_28 , V_34 , & V_7 -> V_35 ) ;
V_7 -> V_10 = F_16 ( V_7 -> V_28 ,
V_36 ) ;
}
static void F_17 ( struct V_6 * V_7 , int V_37 )
{
V_30 V_31 ;
if ( V_37 ) {
V_31 = V_33 ;
V_31 |= ( V_7 -> V_38 / 100 ) << 3 ;
V_31 |= ( V_7 -> V_39 - 4000 ) / 50 ;
V_7 -> V_9 = 1 ;
} else {
V_31 = 0 ;
V_7 -> V_9 = 0 ;
}
F_18 ( V_7 -> V_28 , V_32 , V_31 ) ;
F_19 ( & V_7 -> V_40 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
if ( ! V_7 -> V_9 ) {
if ( ( V_7 -> V_10 ) &&
( V_7 -> V_12 . V_13 <
V_7 -> V_41 . V_42 ) ) {
F_17 ( V_7 , 1 ) ;
}
} else {
if ( ! V_7 -> V_10 ) {
F_17 ( V_7 , 0 ) ;
return;
}
if ( V_7 -> V_12 . V_13 >=
V_7 -> V_41 . V_43 ) {
F_17 ( V_7 , 0 ) ;
F_18 ( V_7 -> V_28 , V_44 ,
V_7 -> V_41 . V_45 ) ;
} else if ( V_7 -> V_12 . V_13 >
V_7 -> V_41 . V_46 ) {
F_18 ( V_7 -> V_28 , V_44 ,
V_7 -> V_41 . V_46 ) ;
}
if ( V_7 -> V_12 . V_19 > V_7 -> V_41 . V_47 ||
V_7 -> V_12 . V_20 < V_7 -> V_41 . V_48 ||
V_7 -> V_12 . V_49 < V_7 -> V_41 . V_50 ||
V_7 -> V_12 . V_49 > V_7 -> V_41 . V_51 ) {
F_17 ( V_7 , 0 ) ;
}
}
}
static void F_21 ( struct V_52 * V_53 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_53 , struct V_6 , V_53 . V_53 ) ;
F_20 ( V_7 ) ;
F_23 ( & V_7 -> V_53 , V_7 -> V_54 ) ;
}
static void F_24 ( struct V_6 * V_7 ,
union V_55 * V_31 )
{
if ( V_7 -> V_10 ) {
if ( V_7 -> V_9 )
V_31 -> V_56 = V_57 ;
else
V_31 -> V_56 = V_58 ;
} else {
V_31 -> V_56 = V_59 ;
}
}
static void F_25 ( struct V_6 * V_7 ,
union V_55 * V_31 )
{
if ( V_7 -> V_35 & V_60 )
V_31 -> V_56 = V_61 ;
else if ( V_7 -> V_35 & V_62 )
V_31 -> V_56 = V_63 ;
else
V_31 -> V_56 = V_64 ;
}
static int F_26 ( struct V_65 * V_40 ,
enum V_66 V_67 ,
union V_55 * V_31 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( V_40 , struct V_6 , V_40 ) ;
switch ( V_67 ) {
case V_68 :
F_24 ( V_7 , V_31 ) ;
break;
case V_69 :
F_25 ( V_7 , V_31 ) ;
break;
case V_70 :
V_31 -> V_56 = V_7 -> V_71 -> V_72 ;
break;
case V_73 :
V_31 -> V_56 = V_7 -> V_71 -> V_74 ;
break;
case V_75 :
V_31 -> V_56 = V_7 -> V_71 -> V_76 ;
break;
case V_77 :
V_31 -> V_56 = F_1 ( V_7 -> V_12 . V_13 ) * 1000 ;
break;
case V_78 :
V_31 -> V_56 =
F_3 ( V_7 -> V_12 . V_18 ) * 1000 ;
break;
case V_79 :
V_31 -> V_80 = V_7 -> V_71 -> V_81 ;
break;
default:
break;
}
return 0 ;
}
static void F_27 ( struct V_6 * V_7 )
{
F_12 ( V_7 , & V_7 -> V_12 ) ;
if ( V_7 -> V_9 )
return;
if ( V_7 -> V_12 . V_13 < V_7 -> V_41 . V_46 ) {
F_18 ( V_7 -> V_28 , V_44 ,
V_7 -> V_41 . V_82 ) ;
if ( V_7 -> V_83 )
V_7 -> V_83 () ;
} else if ( V_7 -> V_12 . V_13 <
V_7 -> V_41 . V_82 ) {
if ( V_7 -> V_84 )
V_7 -> V_84 () ;
}
}
static int F_28 ( struct V_85 * V_86 , unsigned long V_87 ,
void * V_5 )
{
struct V_6 * V_7 =
F_22 ( V_86 , struct V_6 , V_86 ) ;
switch ( V_87 ) {
case V_88 :
F_29 ( & V_7 -> V_53 ) ;
F_30 ( & V_7 -> V_53 . V_53 ) ;
break;
case V_89 :
F_27 ( V_7 ) ;
break;
case V_90 :
case V_91 :
F_17 ( V_7 , 0 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_6 * V_7 ,
struct V_92 * V_93 )
{
V_7 -> V_41 . V_51 = V_93 -> V_51 ;
V_7 -> V_41 . V_50 = V_93 -> V_50 ;
V_7 -> V_41 . V_94 = V_93 -> V_94 ;
V_7 -> V_41 . V_46 =
F_2 ( V_93 -> V_46 ) ;
V_7 -> V_41 . V_82 =
F_2 ( V_93 -> V_82 ) ;
V_7 -> V_41 . V_42 =
F_2 ( V_93 -> V_42 ) ;
V_7 -> V_41 . V_43 =
F_2 ( V_93 -> V_43 ) ;
V_7 -> V_41 . V_45 =
F_2 ( V_93 -> V_45 ) ;
V_7 -> V_41 . V_48 =
F_2 ( V_93 -> V_48 ) ;
V_7 -> V_41 . V_47 =
F_2 ( V_93 -> V_47 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_65 * V_40 = & V_7 -> V_40 ;
struct V_95 * V_96 = V_7 -> V_71 ;
V_40 -> V_81 = V_96 -> V_81 ;
V_40 -> V_97 = V_96 -> V_97 ;
V_40 -> type = V_98 ;
V_40 -> V_99 = F_26 ;
V_40 -> V_100 = V_101 ;
V_40 -> V_102 = F_33 ( V_101 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
char V_103 [ 5 ] ;
int V_104 ;
V_103 [ 0 ] = V_103 [ 1 ] = V_7 -> V_41 . V_46 ;
V_103 [ 2 ] = V_7 -> V_41 . V_50 ;
V_103 [ 3 ] = V_7 -> V_41 . V_94 ;
V_103 [ 4 ] = V_7 -> V_41 . V_51 ;
V_104 = F_35 ( V_7 -> V_28 , V_44 , 5 , V_103 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_18 ( V_7 -> V_28 , V_105 ,
V_106 |
V_107 ) ;
if ( V_104 )
return V_104 ;
return F_18 ( V_7 -> V_28 , V_108 ,
V_109 | V_110 |
V_111 | V_112 |
V_113 |
V_114 ) ;
}
static int F_36 ( struct V_115 * V_116 )
{
struct V_6 * V_7 ;
struct V_92 * V_93 = V_116 -> V_117 . V_118 ;
int V_104 ;
if ( V_93 == NULL )
return - V_119 ;
if ( V_93 -> V_38 >= 1500 ||
V_93 -> V_39 < 4000 ||
V_93 -> V_39 > 4350 )
return - V_119 ;
V_7 = F_37 ( sizeof( * V_7 ) , V_120 ) ;
if ( V_7 == NULL )
return - V_121 ;
V_7 -> V_28 = V_116 -> V_117 . V_122 ;
V_7 -> V_54 = F_38 (
( V_93 -> V_123 ? : 10 ) * 1000 ) ;
V_7 -> V_38 = V_93 -> V_38 ;
V_7 -> V_39 = V_93 -> V_39 ;
V_7 -> V_71 = V_93 -> V_71 ;
V_7 -> V_83 = V_93 -> V_83 ;
V_7 -> V_84 = V_93 -> V_84 ;
F_31 ( V_7 , V_93 ) ;
V_104 = F_34 ( V_7 ) ;
if ( V_104 )
goto V_124;
F_39 ( & V_7 -> V_53 , F_21 ) ;
F_23 ( & V_7 -> V_53 , V_7 -> V_54 ) ;
V_7 -> V_86 . V_125 = F_28 ;
V_104 = F_40 ( V_7 -> V_28 , & V_7 -> V_86 ,
V_88 |
V_89 |
V_90 |
V_91 ) ;
if ( V_104 )
goto V_126;
F_32 ( V_7 ) ;
V_104 = F_41 ( & V_116 -> V_117 , & V_7 -> V_40 ) ;
if ( V_104 )
goto V_127;
V_7 -> V_25 = F_8 ( V_7 ) ;
F_42 ( V_116 , V_7 ) ;
return 0 ;
V_127:
F_43 ( V_7 -> V_28 , & V_7 -> V_86 ,
V_88 | V_89 |
V_90 | V_91 ) ;
V_126:
F_44 ( & V_7 -> V_53 ) ;
V_124:
F_45 ( V_7 ) ;
return V_104 ;
}
static int F_46 ( struct V_115 * V_117 )
{
struct V_6 * V_7 = F_47 ( V_117 ) ;
F_10 ( V_7 ) ;
F_43 ( V_7 -> V_28 , & V_7 -> V_86 ,
V_88 | V_89 |
V_90 | V_91 ) ;
F_29 ( & V_7 -> V_53 ) ;
F_17 ( V_7 , 0 ) ;
F_48 ( & V_7 -> V_40 ) ;
F_45 ( V_7 ) ;
return 0 ;
}
static int F_49 ( void )
{
return F_50 ( & V_128 ) ;
}
static void F_51 ( void )
{
F_52 ( & V_128 ) ;
}
