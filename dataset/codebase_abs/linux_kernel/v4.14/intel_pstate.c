static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline int F_4 ( T_1 V_1 )
{
int V_5 , V_6 ;
V_6 = F_5 ( V_1 ) ;
V_5 = ( 1 << V_4 ) - 1 ;
if ( V_1 & V_5 )
V_6 += 1 ;
return V_6 ;
}
static inline T_1 F_6 ( int V_7 )
{
return F_2 ( V_7 , 100 ) ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_8 ;
}
static inline T_3 F_8 ( T_3 V_1 , T_3 V_2 )
{
return F_9 ( V_1 << V_8 , V_2 ) ;
}
static inline T_1 F_10 ( int V_7 )
{
return F_8 ( V_7 , 100 ) ;
}
static bool F_11 ( void )
{
if ( V_9 . V_10 == V_11 ||
V_9 . V_10 == V_12 )
return true ;
return V_13 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 () ;
}
static void F_14 ( int V_16 )
{
struct V_17 V_18 ;
static T_4 V_19 = 0 , V_20 = V_21 ;
int V_6 ;
V_6 = F_15 ( V_16 , & V_18 ) ;
if ( V_6 )
return;
F_16 ( V_18 . V_22 , V_16 ) ;
if ( V_19 <= V_20 ) {
if ( V_18 . V_22 > V_19 )
V_19 = V_18 . V_22 ;
if ( V_18 . V_22 < V_20 )
V_20 = V_18 . V_22 ;
if ( V_19 > V_20 ) {
F_17 ( & V_23 ) ;
}
}
}
static void F_14 ( int V_16 )
{
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_6 ;
int V_27 ;
if ( V_28 ) {
F_14 ( V_25 -> V_16 ) ;
return;
}
if ( ! F_11 () )
return;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_6 = F_19 ( & V_16 -> V_30 ,
V_25 -> V_16 ) ;
if ( V_6 )
return;
if ( V_16 -> V_30 . V_31 . V_32 !=
V_33 )
goto V_34;
if ( V_16 -> V_30 . V_35 < 2 )
goto V_34;
F_20 ( L_1 , V_25 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_16 -> V_30 . V_35 ; V_27 ++ ) {
F_20 ( L_2 ,
( V_27 == V_16 -> V_30 . V_36 ? '*' : ' ' ) , V_27 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_38 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_39 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_40 ) ;
}
if ( ! V_41 . V_42 )
V_16 -> V_30 . V_37 [ 0 ] . V_38 =
V_25 -> V_43 . V_44 / 1000 ;
V_16 -> V_45 = true ;
F_20 ( L_3 ) ;
return;
V_34:
V_16 -> V_45 = false ;
F_21 ( V_25 -> V_16 ) ;
}
static void F_22 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_16 -> V_45 )
return;
F_21 ( V_25 -> V_16 ) ;
}
static inline void F_18 ( struct V_24 * V_25 )
{
}
static inline void F_22 ( struct V_24 * V_25 )
{
}
static inline void F_23 ( void )
{
T_3 V_46 ;
struct V_26 * V_16 ;
V_16 = V_29 [ 0 ] ;
F_24 ( V_47 , V_46 ) ;
V_41 . V_42 =
( V_46 & V_48 ||
V_16 -> V_49 . V_50 == V_16 -> V_49 . V_51 ) ;
}
static int F_25 ( void )
{
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_51 = V_16 -> V_49 . V_51 ;
return V_51 ?
( V_16 -> V_49 . V_52 * 100 / V_51 ) : 0 ;
}
static T_5 F_26 ( struct V_26 * V_53 )
{
T_3 V_54 ;
int V_6 ;
if ( ! F_27 ( V_55 ) )
return - V_56 ;
V_6 = F_28 ( V_53 -> V_16 , V_57 , & V_54 ) ;
if ( V_6 )
return ( T_5 ) V_6 ;
return ( T_5 ) ( V_54 & 0x0f ) ;
}
static T_5 F_29 ( struct V_26 * V_53 , T_3 V_58 )
{
T_5 V_59 ;
if ( F_27 ( V_60 ) ) {
if ( ! V_58 ) {
V_59 = F_28 ( V_53 -> V_16 , V_61 ,
& V_58 ) ;
if ( V_59 )
return V_59 ;
}
V_59 = ( V_58 >> 24 ) & 0xff ;
} else {
V_59 = F_26 ( V_53 ) ;
}
return V_59 ;
}
static int F_30 ( int V_16 , T_5 V_62 )
{
T_3 V_54 ;
int V_6 ;
if ( ! F_27 ( V_55 ) )
return - V_56 ;
V_6 = F_28 ( V_16 , V_57 , & V_54 ) ;
if ( V_6 )
return V_6 ;
V_54 = ( V_54 & ~ 0x0f ) | V_62 ;
F_31 ( V_16 , V_57 , V_54 ) ;
return 0 ;
}
static int F_32 ( struct V_26 * V_53 )
{
T_5 V_59 ;
int V_63 = - V_64 ;
V_59 = F_29 ( V_53 , 0 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( F_27 ( V_60 ) ) {
if ( V_59 == V_65 )
return 1 ;
if ( V_59 <= V_66 )
return 2 ;
if ( V_59 <= V_67 )
return 3 ;
else
return 4 ;
} else if ( F_27 ( V_55 ) ) {
V_63 = ( V_59 >> 2 ) + 1 ;
}
return V_63 ;
}
static int F_33 ( struct V_26 * V_53 ,
int V_68 )
{
int V_59 = - V_64 ;
int V_6 ;
if ( ! V_68 )
V_59 = V_53 -> V_69 ;
F_34 ( & V_70 ) ;
if ( F_27 ( V_60 ) ) {
T_3 V_71 ;
V_6 = F_28 ( V_53 -> V_16 , V_61 , & V_71 ) ;
if ( V_6 )
goto V_72;
V_71 &= ~ F_35 ( 31 , 24 ) ;
if ( V_59 == - V_64 )
V_59 = V_73 [ V_68 - 1 ] ;
V_71 |= ( T_3 ) V_59 << 24 ;
V_6 = F_31 ( V_53 -> V_16 , V_61 , V_71 ) ;
} else {
if ( V_59 == - V_64 )
V_59 = ( V_68 - 1 ) << 2 ;
V_6 = F_30 ( V_53 -> V_16 , V_59 ) ;
}
V_72:
F_36 ( & V_70 ) ;
return V_6 ;
}
static T_6 F_37 (
struct V_24 * V_25 , char * V_74 )
{
int V_27 = 0 ;
int V_6 = 0 ;
while ( V_75 [ V_27 ] != NULL )
V_6 += sprintf ( & V_74 [ V_6 ] , L_4 , V_75 [ V_27 ++ ] ) ;
V_6 += sprintf ( & V_74 [ V_6 ] , L_5 ) ;
return V_6 ;
}
static T_6 F_38 (
struct V_24 * V_25 , const char * V_74 , T_7 V_76 )
{
struct V_26 * V_53 = V_29 [ V_25 -> V_16 ] ;
char V_77 [ 21 ] ;
int V_6 , V_27 = 0 ;
V_6 = sscanf ( V_74 , L_6 , V_77 ) ;
if ( V_6 != 1 )
return - V_64 ;
while ( V_75 [ V_27 ] != NULL ) {
if ( ! strcmp ( V_77 , V_75 [ V_27 ] ) ) {
F_33 ( V_53 , V_27 ) ;
return V_76 ;
}
++ V_27 ;
}
return - V_64 ;
}
static T_6 F_39 (
struct V_24 * V_25 , char * V_74 )
{
struct V_26 * V_53 = V_29 [ V_25 -> V_16 ] ;
int V_78 ;
V_78 = F_32 ( V_53 ) ;
if ( V_78 < 0 )
return V_78 ;
return sprintf ( V_74 , L_7 , V_75 [ V_78 ] ) ;
}
static void F_40 ( unsigned int V_16 , int * V_79 ,
int * V_80 )
{
T_3 V_81 ;
F_28 ( V_16 , V_82 , & V_81 ) ;
if ( V_41 . V_83 )
* V_80 = F_41 ( V_81 ) ;
else
* V_80 = F_42 ( V_81 ) ;
* V_79 = F_42 ( V_81 ) ;
}
static void F_43 ( unsigned int V_16 )
{
struct V_26 * V_53 = V_29 [ V_16 ] ;
int V_84 , V_85 ;
T_3 V_71 ;
T_5 V_59 ;
V_84 = V_53 -> V_86 ;
V_85 = V_53 -> V_87 ;
if ( V_53 -> V_25 == V_88 )
V_85 = V_84 ;
F_28 ( V_16 , V_61 , & V_71 ) ;
V_71 &= ~ F_44 ( ~ 0L ) ;
V_71 |= F_44 ( V_85 ) ;
V_71 &= ~ F_45 ( ~ 0L ) ;
V_71 |= F_45 ( V_84 ) ;
if ( V_53 -> V_89 == V_53 -> V_25 )
goto V_90;
V_53 -> V_89 = V_53 -> V_25 ;
if ( V_53 -> V_91 >= 0 ) {
V_59 = V_53 -> V_91 ;
V_53 -> V_91 = - V_64 ;
goto V_92;
}
if ( V_53 -> V_25 == V_88 ) {
V_59 = F_29 ( V_53 , V_71 ) ;
V_53 -> V_93 = V_59 ;
if ( V_59 < 0 )
goto V_90;
V_59 = 0 ;
} else {
if ( V_53 -> V_93 < 0 )
goto V_90;
V_59 = F_29 ( V_53 , V_71 ) ;
if ( V_59 )
goto V_90;
V_59 = V_53 -> V_93 ;
}
V_92:
if ( F_27 ( V_60 ) ) {
V_71 &= ~ F_35 ( 31 , 24 ) ;
V_71 |= ( T_3 ) V_59 << 24 ;
} else {
F_30 ( V_16 , V_59 ) ;
}
V_90:
F_31 ( V_16 , V_61 , V_71 ) ;
}
static int F_46 ( struct V_24 * V_25 )
{
struct V_26 * V_53 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_28 )
return 0 ;
V_53 -> V_91 = F_29 ( V_53 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_24 * V_25 )
{
if ( ! V_28 )
return 0 ;
F_34 ( & V_70 ) ;
V_29 [ V_25 -> V_16 ] -> V_89 = 0 ;
F_43 ( V_25 -> V_16 ) ;
F_36 ( & V_70 ) ;
return 0 ;
}
static void F_48 ( void )
{
int V_16 ;
F_49 (cpu)
F_50 ( V_16 ) ;
}
static T_6 F_51 ( struct V_94 * V_95 ,
struct V_96 * V_97 , char * V_74 )
{
T_6 V_6 ;
F_34 ( & V_98 ) ;
V_6 = F_52 ( V_74 ) ;
F_36 ( & V_98 ) ;
return V_6 ;
}
static T_6 F_53 ( struct V_94 * V_99 , struct V_96 * V_100 ,
const char * V_74 , T_7 V_76 )
{
char * V_101 = memchr ( V_74 , '\n' , V_76 ) ;
int V_6 ;
F_34 ( & V_98 ) ;
V_6 = F_54 ( V_74 , V_101 ? V_101 - V_74 : V_76 ) ;
F_36 ( & V_98 ) ;
return V_6 < 0 ? V_6 : V_76 ;
}
static T_6 F_55 ( struct V_94 * V_95 ,
struct V_96 * V_97 , char * V_74 )
{
struct V_26 * V_16 ;
int V_102 , V_83 , V_103 ;
T_8 V_104 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
V_16 = V_29 [ 0 ] ;
V_102 = V_16 -> V_49 . V_51 - V_16 -> V_49 . V_52 + 1 ;
V_83 = V_16 -> V_49 . V_50 - V_16 -> V_49 . V_52 + 1 ;
V_104 = F_2 ( V_83 , V_102 ) ;
V_103 = 100 - F_5 ( F_1 ( V_104 , F_56 ( 100 ) ) ) ;
F_36 ( & V_98 ) ;
return sprintf ( V_74 , L_8 , V_103 ) ;
}
static T_6 F_57 ( struct V_94 * V_95 ,
struct V_96 * V_97 , char * V_74 )
{
struct V_26 * V_16 ;
int V_102 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
V_16 = V_29 [ 0 ] ;
V_102 = V_16 -> V_49 . V_51 - V_16 -> V_49 . V_52 + 1 ;
F_36 ( & V_98 ) ;
return sprintf ( V_74 , L_8 , V_102 ) ;
}
static T_6 F_58 ( struct V_94 * V_95 ,
struct V_96 * V_97 , char * V_74 )
{
T_6 V_6 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
F_23 () ;
if ( V_41 . V_42 )
V_6 = sprintf ( V_74 , L_8 , V_41 . V_42 ) ;
else
V_6 = sprintf ( V_74 , L_8 , V_41 . V_83 ) ;
F_36 ( & V_98 ) ;
return V_6 ;
}
static T_6 F_59 ( struct V_94 * V_99 , struct V_96 * V_100 ,
const char * V_74 , T_7 V_76 )
{
unsigned int V_107 ;
int V_6 ;
V_6 = sscanf ( V_74 , L_9 , & V_107 ) ;
if ( V_6 != 1 )
return - V_64 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
F_34 ( & V_70 ) ;
F_23 () ;
if ( V_41 . V_42 ) {
F_60 ( L_10 ) ;
F_36 ( & V_70 ) ;
F_36 ( & V_98 ) ;
return - V_108 ;
}
V_41 . V_83 = F_61 ( int , V_107 , 0 , 1 ) ;
if ( V_41 . V_83 ) {
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_109 = V_16 -> V_49 . V_50 * 100 / V_16 -> V_49 . V_51 ;
if ( V_41 . V_110 > V_109 )
V_41 . V_110 = V_109 ;
}
F_36 ( & V_70 ) ;
F_48 () ;
F_36 ( & V_98 ) ;
return V_76 ;
}
static T_6 F_62 ( struct V_94 * V_99 , struct V_96 * V_100 ,
const char * V_74 , T_7 V_76 )
{
unsigned int V_107 ;
int V_6 ;
V_6 = sscanf ( V_74 , L_9 , & V_107 ) ;
if ( V_6 != 1 )
return - V_64 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
F_34 ( & V_70 ) ;
V_41 . V_111 = F_61 ( int , V_107 , V_41 . V_110 , 100 ) ;
F_36 ( & V_70 ) ;
F_48 () ;
F_36 ( & V_98 ) ;
return V_76 ;
}
static T_6 F_63 ( struct V_94 * V_99 , struct V_96 * V_100 ,
const char * V_74 , T_7 V_76 )
{
unsigned int V_107 ;
int V_6 ;
V_6 = sscanf ( V_74 , L_9 , & V_107 ) ;
if ( V_6 != 1 )
return - V_64 ;
F_34 ( & V_98 ) ;
if ( ! V_105 ) {
F_36 ( & V_98 ) ;
return - V_106 ;
}
F_34 ( & V_70 ) ;
V_41 . V_110 = F_61 ( int , V_107 ,
F_25 () , V_41 . V_111 ) ;
F_36 ( & V_70 ) ;
F_48 () ;
F_36 ( & V_98 ) ;
return V_76 ;
}
static void T_9 F_64 ( void )
{
struct V_94 * V_112 ;
int V_113 ;
V_112 = F_65 ( L_11 ,
& V_114 . V_115 -> V_95 ) ;
if ( F_66 ( ! V_112 ) )
return;
V_113 = F_67 ( V_112 , & V_116 ) ;
if ( F_66 ( V_113 ) )
return;
if ( V_117 )
return;
V_113 = F_68 ( V_112 , & V_111 . V_97 ) ;
F_66 ( V_113 ) ;
V_113 = F_68 ( V_112 , & V_110 . V_97 ) ;
F_66 ( V_113 ) ;
}
static void F_69 ( struct V_26 * V_26 )
{
if ( F_27 ( V_118 ) )
F_31 ( V_26 -> V_16 , V_119 , 0x00 ) ;
F_31 ( V_26 -> V_16 , V_120 , 0x1 ) ;
V_26 -> V_89 = 0 ;
if ( V_26 -> V_69 == - V_64 )
V_26 -> V_69 = F_29 ( V_26 , 0 ) ;
}
static void F_70 ( int V_16 )
{
T_3 V_121 ;
int V_6 ;
V_6 = F_28 ( V_16 , V_122 , & V_121 ) ;
if ( V_6 )
return;
if ( ! ( V_121 & F_71 ( V_123 ) ) ) {
F_72 ( L_12 ) ;
V_121 |= F_71 ( V_123 ) ;
F_31 ( V_16 , V_122 , V_121 ) ;
}
}
static int F_73 ( void )
{
T_3 V_71 ;
F_24 ( V_124 , V_71 ) ;
return ( V_71 >> 8 ) & 0x7F ;
}
static int F_74 ( void )
{
T_3 V_71 ;
F_24 ( V_124 , V_71 ) ;
return ( V_71 >> 16 ) & 0x7F ;
}
static int F_75 ( void )
{
T_3 V_71 ;
F_24 ( V_125 , V_71 ) ;
return V_71 & 0x7F ;
}
static T_3 F_76 ( struct V_26 * V_26 , int V_49 )
{
T_3 V_126 ;
T_1 V_127 ;
T_4 V_128 ;
V_126 = ( T_3 ) V_49 << 8 ;
if ( V_41 . V_83 && ! V_41 . V_42 )
V_126 |= ( T_3 ) 1 << 32 ;
V_127 = V_26 -> V_128 . V_85 + F_1 (
F_56 ( V_49 - V_26 -> V_49 . V_52 ) ,
V_26 -> V_128 . V_129 ) ;
V_127 = F_61 ( T_1 , V_127 , V_26 -> V_128 . V_85 , V_26 -> V_128 . V_84 ) ;
V_128 = F_4 ( V_127 ) ;
if ( V_49 > V_26 -> V_49 . V_50 )
V_128 = V_26 -> V_128 . V_130 ;
return V_126 | V_128 ;
}
static int F_77 ( void )
{
T_3 V_71 ;
int V_27 ;
static int V_131 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_24 ( V_132 , V_71 ) ;
V_27 = V_71 & 0x7 ;
F_66 ( V_27 > 4 ) ;
return V_131 [ V_27 ] ;
}
static int F_78 ( void )
{
T_3 V_71 ;
int V_27 ;
static int V_133 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_24 ( V_132 , V_71 ) ;
V_27 = V_71 & 0xF ;
F_66 ( V_27 > 8 ) ;
return V_133 [ V_27 ] ;
}
static void F_79 ( struct V_26 * V_26 )
{
T_3 V_71 ;
F_24 ( V_134 , V_71 ) ;
V_26 -> V_128 . V_85 = F_56 ( ( V_71 >> 8 ) & 0x7f ) ;
V_26 -> V_128 . V_84 = F_56 ( ( V_71 >> 16 ) & 0x7f ) ;
V_26 -> V_128 . V_129 = F_2 (
V_26 -> V_128 . V_84 - V_26 -> V_128 . V_85 ,
F_56 ( V_26 -> V_49 . V_50 -
V_26 -> V_49 . V_52 ) ) ;
F_24 ( V_135 , V_71 ) ;
V_26 -> V_128 . V_130 = V_71 & 0x7f ;
}
static int F_80 ( void )
{
T_3 V_71 ;
F_24 ( V_136 , V_71 ) ;
return ( V_71 >> 40 ) & 0xFF ;
}
static int F_81 ( void )
{
T_3 V_71 ;
F_24 ( V_136 , V_71 ) ;
return ( V_71 >> 8 ) & 0xFF ;
}
static int F_82 ( T_3 V_137 )
{
if ( V_137 & 0x600000000 ) {
T_3 V_138 ;
T_3 V_139 ;
int V_140 ;
int V_34 ;
V_34 = F_83 ( V_141 , & V_138 ) ;
if ( V_34 )
return V_34 ;
V_140 = V_142 + ( V_138 & 0x03 ) ;
V_34 = F_83 ( V_140 , & V_139 ) ;
if ( V_34 )
return V_34 ;
if ( V_138 & 0x03 )
V_139 >>= 16 ;
V_139 &= 0xff ;
F_20 ( L_13 , ( int ) V_139 ) ;
return ( int ) V_139 ;
}
return - V_56 ;
}
static int F_84 ( void )
{
T_3 V_143 ;
T_3 V_137 ;
int V_50 ;
int V_139 ;
int V_34 ;
F_24 ( V_136 , V_137 ) ;
V_50 = ( V_137 >> 8 ) & 0xFF ;
V_139 = F_82 ( V_137 ) ;
if ( V_139 <= 0 )
return V_50 ;
if ( V_28 ) {
return V_139 ;
}
V_34 = F_83 ( V_144 , & V_143 ) ;
if ( ! V_34 ) {
int V_145 ;
V_145 = V_143 & 0xff ;
if ( V_139 - 1 == V_145 ) {
V_50 = V_145 ;
F_20 ( L_14 , V_50 ) ;
}
}
return V_50 ;
}
static int F_85 ( void )
{
T_3 V_71 ;
int V_146 , V_6 ;
F_24 ( V_147 , V_71 ) ;
V_146 = F_84 () ;
V_6 = ( V_71 ) & 255 ;
if ( V_6 <= V_146 )
V_6 = V_146 ;
return V_6 ;
}
static inline int F_86 ( void )
{
return 100000 ;
}
static T_3 F_87 ( struct V_26 * V_26 , int V_49 )
{
T_3 V_126 ;
V_126 = ( T_3 ) V_49 << 8 ;
if ( V_41 . V_83 && ! V_41 . V_42 )
V_126 |= ( T_3 ) 1 << 32 ;
return V_126 ;
}
static int F_88 ( void )
{
return 10 ;
}
static int F_89 ( void )
{
T_3 V_71 ;
int V_146 , V_6 ;
F_24 ( V_147 , V_71 ) ;
V_146 = F_84 () ;
V_6 = ( ( ( V_71 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_146 )
V_6 = V_146 ;
return V_6 ;
}
static int F_90 ( struct V_26 * V_16 )
{
return V_41 . V_83 || V_41 . V_42 ?
V_16 -> V_49 . V_50 : V_16 -> V_49 . V_51 ;
}
static void F_91 ( struct V_26 * V_16 , int V_49 )
{
F_92 ( V_49 * V_16 -> V_49 . V_148 , V_16 -> V_16 ) ;
V_16 -> V_49 . V_149 = V_49 ;
F_31 ( V_16 -> V_16 , V_150 ,
V_151 . V_152 ( V_16 , V_49 ) ) ;
}
static void F_93 ( struct V_26 * V_16 )
{
F_91 ( V_16 , V_16 -> V_49 . V_52 ) ;
}
static void F_94 ( struct V_26 * V_16 )
{
int V_49 ;
F_23 () ;
V_49 = F_90 ( V_16 ) ;
V_49 = V_84 ( V_16 -> V_49 . V_52 , V_16 -> V_86 ) ;
F_91 ( V_16 , V_49 ) ;
}
static void F_95 ( struct V_26 * V_16 )
{
V_16 -> V_49 . V_52 = V_151 . V_153 () ;
V_16 -> V_49 . V_50 = V_151 . V_154 () ;
V_16 -> V_49 . V_155 = V_151 . V_156 () ;
V_16 -> V_49 . V_51 = V_151 . V_157 () ;
V_16 -> V_49 . V_148 = V_151 . V_158 () ;
V_16 -> V_49 . V_44 = V_16 -> V_49 . V_50 * V_16 -> V_49 . V_148 ;
V_16 -> V_49 . V_159 = V_16 -> V_49 . V_51 * V_16 -> V_49 . V_148 ;
if ( V_151 . V_160 )
V_16 -> V_161 = V_151 . V_160 () ;
if ( V_151 . V_162 )
V_151 . V_162 ( V_16 ) ;
F_93 ( V_16 ) ;
}
static inline void F_96 ( struct V_26 * V_16 )
{
struct V_163 * V_163 = & V_16 -> V_163 ;
V_163 -> V_164 = F_8 ( V_163 -> V_165 , V_163 -> V_166 ) ;
}
static inline bool F_97 ( struct V_26 * V_16 , T_3 time )
{
T_3 V_165 , V_166 ;
unsigned long V_167 ;
T_3 V_168 ;
F_98 ( V_167 ) ;
F_24 ( V_169 , V_165 ) ;
F_24 ( V_170 , V_166 ) ;
V_168 = F_99 () ;
if ( V_16 -> V_171 == V_166 || V_16 -> V_172 == V_168 ) {
F_100 ( V_167 ) ;
return false ;
}
F_100 ( V_167 ) ;
V_16 -> V_173 = V_16 -> V_163 . time ;
V_16 -> V_163 . time = time ;
V_16 -> V_163 . V_165 = V_165 ;
V_16 -> V_163 . V_166 = V_166 ;
V_16 -> V_163 . V_168 = V_168 ;
V_16 -> V_163 . V_165 -= V_16 -> V_174 ;
V_16 -> V_163 . V_166 -= V_16 -> V_171 ;
V_16 -> V_163 . V_168 -= V_16 -> V_172 ;
V_16 -> V_174 = V_165 ;
V_16 -> V_171 = V_166 ;
V_16 -> V_172 = V_168 ;
if ( V_16 -> V_173 ) {
F_96 ( V_16 ) ;
return true ;
}
return false ;
}
static inline T_1 F_101 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_163 . V_164 , V_175 ) ;
}
static inline T_1 F_102 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_49 . V_155 ,
V_16 -> V_163 . V_164 ) ;
}
static inline T_1 F_103 ( struct V_26 * V_16 )
{
struct V_163 * V_163 = & V_16 -> V_163 ;
T_1 V_176 , V_177 ;
int V_178 , V_179 ;
V_176 = F_2 ( V_163 -> V_166 << V_16 -> V_161 ,
V_163 -> V_168 ) ;
V_177 = V_16 -> V_180 ;
V_16 -> V_180 >>= 1 ;
if ( V_176 < V_177 )
V_176 = V_177 ;
V_163 -> V_181 = V_176 * 100 ;
V_178 = V_41 . V_83 || V_41 . V_42 ?
V_16 -> V_49 . V_50 : V_16 -> V_49 . V_51 ;
V_178 += V_178 >> 2 ;
V_178 = F_1 ( V_178 , V_176 ) ;
if ( V_178 < V_16 -> V_49 . V_52 )
V_178 = V_16 -> V_49 . V_52 ;
V_179 = F_102 ( V_16 ) ;
if ( V_179 > V_178 )
V_178 += ( V_179 - V_178 ) >> 1 ;
return V_178 ;
}
static int F_104 ( struct V_26 * V_16 , int V_49 )
{
int V_50 = F_90 ( V_16 ) ;
int V_52 ;
V_52 = V_84 ( V_16 -> V_49 . V_52 , V_16 -> V_87 ) ;
V_50 = V_84 ( V_52 , V_16 -> V_86 ) ;
return F_61 ( int , V_49 , V_52 , V_50 ) ;
}
static void F_105 ( struct V_26 * V_16 , int V_49 )
{
if ( V_49 == V_16 -> V_49 . V_149 )
return;
V_16 -> V_49 . V_149 = V_49 ;
F_106 ( V_150 , V_151 . V_152 ( V_16 , V_49 ) ) ;
}
static void F_107 ( struct V_26 * V_16 )
{
int V_182 = V_16 -> V_49 . V_149 ;
struct V_163 * V_163 ;
int V_183 ;
F_23 () ;
V_183 = F_103 ( V_16 ) ;
V_183 = F_104 ( V_16 , V_183 ) ;
F_92 ( V_183 * V_16 -> V_49 . V_148 , V_16 -> V_16 ) ;
F_105 ( V_16 , V_183 ) ;
V_163 = & V_16 -> V_163 ;
F_108 ( F_7 ( 100 , V_163 -> V_164 ) ,
F_5 ( V_163 -> V_181 ) ,
V_182 ,
V_16 -> V_49 . V_149 ,
V_163 -> V_166 ,
V_163 -> V_165 ,
V_163 -> V_168 ,
F_101 ( V_16 ) ,
F_5 ( V_16 -> V_180 * 100 ) ) ;
}
static void F_109 ( struct V_184 * V_185 , T_3 time ,
unsigned int V_167 )
{
struct V_26 * V_16 = F_110 ( V_185 , struct V_26 , V_186 ) ;
T_3 V_187 ;
if ( F_111 () != V_16 -> V_16 )
return;
if ( V_167 & V_188 ) {
V_16 -> V_180 = F_56 ( 1 ) ;
V_16 -> V_189 = time ;
if ( F_5 ( V_16 -> V_163 . V_181 ) == 100 )
return;
goto V_190;
} else if ( V_16 -> V_180 ) {
V_187 = time - V_16 -> V_189 ;
if ( V_187 > V_191 )
V_16 -> V_180 = 0 ;
}
V_16 -> V_189 = time ;
V_187 = time - V_16 -> V_163 . time ;
if ( ( T_2 ) V_187 < V_192 )
return;
V_190:
if ( F_97 ( V_16 , time ) )
F_107 ( V_16 ) ;
}
static int F_112 ( unsigned int V_193 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_193 ] ;
if ( ! V_16 ) {
V_16 = F_113 ( sizeof( * V_16 ) , V_194 ) ;
if ( ! V_16 )
return - V_195 ;
V_29 [ V_193 ] = V_16 ;
V_16 -> V_69 = - V_64 ;
V_16 -> V_93 = - V_64 ;
V_16 -> V_91 = - V_64 ;
}
V_16 = V_29 [ V_193 ] ;
V_16 -> V_16 = V_193 ;
if ( V_28 ) {
const struct V_196 * V_197 ;
V_197 = F_114 ( V_198 ) ;
if ( V_197 )
F_70 ( V_193 ) ;
F_69 ( V_16 ) ;
}
F_95 ( V_16 ) ;
F_20 ( L_15 , V_193 ) ;
return 0 ;
}
static void F_115 ( unsigned int V_199 )
{
struct V_26 * V_16 = V_29 [ V_199 ] ;
if ( V_28 )
return;
if ( V_16 -> V_200 )
return;
V_16 -> V_163 . time = 0 ;
F_116 ( V_199 , & V_16 -> V_186 ,
F_109 ) ;
V_16 -> V_200 = true ;
}
static void F_117 ( unsigned int V_16 )
{
struct V_26 * V_53 = V_29 [ V_16 ] ;
if ( ! V_53 -> V_200 )
return;
F_118 ( V_16 ) ;
V_53 -> V_200 = false ;
F_119 () ;
}
static int F_120 ( struct V_26 * V_16 )
{
return V_41 . V_42 || V_41 . V_83 ?
V_16 -> V_49 . V_44 : V_16 -> V_49 . V_159 ;
}
static void F_121 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
int V_44 = F_120 ( V_16 ) ;
T_1 V_201 , V_202 ;
int V_203 , V_204 ;
if ( V_28 ) {
F_40 ( V_16 -> V_16 , & V_204 , & V_203 ) ;
} else {
V_203 = F_90 ( V_16 ) ;
V_204 = V_16 -> V_49 . V_51 ;
}
V_201 = V_203 * V_25 -> V_84 / V_44 ;
if ( V_25 -> V_84 == V_25 -> V_85 ) {
V_202 = V_201 ;
} else {
V_202 = V_203 * V_25 -> V_85 / V_44 ;
V_202 = F_61 ( T_1 , V_202 ,
0 , V_201 ) ;
}
F_20 ( L_16 ,
V_25 -> V_16 , V_203 ,
V_202 , V_201 ) ;
if ( V_117 ) {
V_16 -> V_87 = V_202 ;
V_16 -> V_86 = V_201 ;
} else {
T_1 V_205 , V_206 ;
V_206 = F_122 ( V_204 * V_41 . V_111 , 100 ) ;
V_205 = F_122 ( V_204 * V_41 . V_110 , 100 ) ;
V_205 = F_61 ( T_1 , V_205 , 0 , V_206 ) ;
F_20 ( L_17 , V_25 -> V_16 ,
V_205 , V_206 ) ;
V_16 -> V_87 = V_84 ( V_202 , V_205 ) ;
V_16 -> V_87 = V_85 ( V_16 -> V_87 , V_201 ) ;
V_16 -> V_86 = V_85 ( V_201 , V_206 ) ;
V_16 -> V_86 = V_84 ( V_202 , V_16 -> V_86 ) ;
V_16 -> V_87 = V_85 ( V_16 -> V_87 ,
V_16 -> V_86 ) ;
}
F_20 ( L_18 , V_25 -> V_16 ,
V_16 -> V_86 ,
V_16 -> V_87 ) ;
}
static int F_123 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
if ( ! V_25 -> V_43 . V_44 )
return - V_207 ;
F_20 ( L_19 ,
V_25 -> V_43 . V_44 , V_25 -> V_84 ) ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_25 = V_25 -> V_25 ;
F_34 ( & V_70 ) ;
F_121 ( V_25 , V_16 ) ;
if ( V_16 -> V_25 == V_88 ) {
F_117 ( V_25 -> V_16 ) ;
F_94 ( V_16 ) ;
} else {
F_115 ( V_25 -> V_16 ) ;
}
if ( V_28 )
F_43 ( V_25 -> V_16 ) ;
F_36 ( & V_70 ) ;
return 0 ;
}
static void F_124 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
if ( V_16 -> V_49 . V_155 > V_16 -> V_49 . V_50 &&
V_25 -> V_84 < V_25 -> V_43 . V_44 &&
V_25 -> V_84 > V_16 -> V_49 . V_44 ) {
F_20 ( L_20 ) ;
V_25 -> V_84 = V_25 -> V_43 . V_44 ;
}
}
static int F_125 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_23 () ;
F_126 ( V_25 , V_25 -> V_43 . V_208 ,
F_120 ( V_16 ) ) ;
if ( V_25 -> V_25 != V_209 &&
V_25 -> V_25 != V_88 )
return - V_64 ;
F_124 ( V_25 , V_16 ) ;
return 0 ;
}
static void F_127 ( struct V_24 * V_25 )
{
F_93 ( V_29 [ V_25 -> V_16 ] ) ;
}
static void F_128 ( struct V_24 * V_25 )
{
F_20 ( L_21 , V_25 -> V_16 ) ;
F_117 ( V_25 -> V_16 ) ;
if ( V_28 )
F_46 ( V_25 ) ;
else
F_127 ( V_25 ) ;
}
static int F_129 ( struct V_24 * V_25 )
{
F_22 ( V_25 ) ;
V_25 -> V_210 = false ;
return 0 ;
}
static int F_130 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_113 ;
V_113 = F_112 ( V_25 -> V_16 ) ;
if ( V_113 )
return V_113 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_86 = 0xFF ;
V_16 -> V_87 = 0 ;
V_25 -> V_85 = V_16 -> V_49 . V_52 * V_16 -> V_49 . V_148 ;
V_25 -> V_84 = V_16 -> V_49 . V_51 * V_16 -> V_49 . V_148 ;
V_25 -> V_43 . V_208 = V_16 -> V_49 . V_52 * V_16 -> V_49 . V_148 ;
F_23 () ;
V_25 -> V_43 . V_44 = V_41 . V_42 ?
V_16 -> V_49 . V_50 : V_16 -> V_49 . V_51 ;
V_25 -> V_43 . V_44 *= V_16 -> V_49 . V_148 ;
F_18 ( V_25 ) ;
V_25 -> V_210 = true ;
return 0 ;
}
static int F_131 ( struct V_24 * V_25 )
{
int V_6 = F_130 ( V_25 ) ;
if ( V_6 )
return V_6 ;
if ( F_132 ( V_211 ) )
V_25 -> V_25 = V_88 ;
else
V_25 -> V_25 = V_209 ;
return 0 ;
}
static int F_133 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_23 () ;
F_126 ( V_25 , V_25 -> V_43 . V_208 ,
F_120 ( V_16 ) ) ;
F_124 ( V_25 , V_16 ) ;
F_121 ( V_25 , V_16 ) ;
return 0 ;
}
static int F_134 ( struct V_24 * V_25 ,
unsigned int V_212 ,
unsigned int V_213 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
struct V_214 V_215 ;
int V_183 ;
F_23 () ;
V_215 . V_216 = V_25 -> V_217 ;
V_215 . V_218 = V_212 ;
F_135 ( V_25 , & V_215 ) ;
switch ( V_213 ) {
case V_219 :
V_183 = F_122 ( V_215 . V_218 , V_16 -> V_49 . V_148 ) ;
break;
case V_220 :
V_183 = V_215 . V_218 / V_16 -> V_49 . V_148 ;
break;
default:
V_183 = F_136 ( V_215 . V_218 , V_16 -> V_49 . V_148 ) ;
break;
}
V_183 = F_104 ( V_16 , V_183 ) ;
if ( V_183 != V_16 -> V_49 . V_149 ) {
V_16 -> V_49 . V_149 = V_183 ;
F_31 ( V_25 -> V_16 , V_150 ,
V_151 . V_152 ( V_16 , V_183 ) ) ;
}
V_215 . V_218 = V_183 * V_16 -> V_49 . V_148 ;
F_137 ( V_25 , & V_215 , false ) ;
return 0 ;
}
static unsigned int F_138 ( struct V_24 * V_25 ,
unsigned int V_212 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
int V_183 ;
F_23 () ;
V_183 = F_122 ( V_212 , V_16 -> V_49 . V_148 ) ;
V_183 = F_104 ( V_16 , V_183 ) ;
F_105 ( V_16 , V_183 ) ;
return V_183 * V_16 -> V_49 . V_148 ;
}
static int F_139 ( struct V_24 * V_25 )
{
int V_6 = F_130 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_43 . V_221 = V_222 ;
V_25 -> V_223 = V_224 ;
V_25 -> V_217 = V_25 -> V_43 . V_208 ;
return 0 ;
}
static void F_140 ( void )
{
unsigned int V_16 ;
F_141 () ;
F_142 (cpu) {
if ( V_29 [ V_16 ] ) {
if ( V_105 == & V_225 )
F_117 ( V_16 ) ;
F_143 ( V_29 [ V_16 ] ) ;
V_29 [ V_16 ] = NULL ;
}
}
F_144 () ;
V_105 = NULL ;
}
static int F_145 ( struct V_226 * V_227 )
{
int V_6 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_111 = 100 ;
V_105 = V_227 ;
V_6 = F_146 ( V_105 ) ;
if ( V_6 ) {
F_140 () ;
return V_6 ;
}
V_41 . V_110 = F_25 () ;
return 0 ;
}
static int F_147 ( void )
{
if ( V_28 )
return - V_228 ;
F_148 ( V_105 ) ;
F_140 () ;
return 0 ;
}
static T_6 F_52 ( char * V_74 )
{
if ( ! V_105 )
return sprintf ( V_74 , L_22 ) ;
return sprintf ( V_74 , L_7 , V_105 == & V_225 ?
L_23 : L_24 ) ;
}
static int F_54 ( const char * V_74 , T_7 V_229 )
{
int V_6 ;
if ( V_229 == 3 && ! strncmp ( V_74 , L_25 , V_229 ) )
return V_105 ?
F_147 () : - V_64 ;
if ( V_229 == 6 && ! strncmp ( V_74 , L_23 , V_229 ) ) {
if ( V_105 ) {
if ( V_105 == & V_225 )
return 0 ;
V_6 = F_147 () ;
if ( V_6 )
return V_6 ;
}
return F_145 ( & V_225 ) ;
}
if ( V_229 == 7 && ! strncmp ( V_74 , L_24 , V_229 ) ) {
if ( V_105 ) {
if ( V_105 == & V_230 )
return 0 ;
V_6 = F_147 () ;
if ( V_6 )
return V_6 ;
}
return F_145 ( & V_230 ) ;
}
return - V_64 ;
}
static int T_9 F_149 ( void )
{
if ( ! V_151 . V_154 () ||
! V_151 . V_153 () ||
! V_151 . V_157 () )
return - V_207 ;
return 0 ;
}
static void T_9 F_150 ( struct V_151 * V_231 )
{
V_151 . V_154 = V_231 -> V_154 ;
V_151 . V_156 = V_231 -> V_156 ;
V_151 . V_153 = V_231 -> V_153 ;
V_151 . V_157 = V_231 -> V_157 ;
V_151 . V_158 = V_231 -> V_158 ;
V_151 . V_152 = V_231 -> V_152 ;
V_151 . V_162 = V_231 -> V_162 ;
V_151 . V_160 = V_231 -> V_160 ;
}
static bool T_9 F_151 ( void )
{
int V_27 ;
F_49 (i) {
T_10 V_232 ;
union V_233 * V_234 ;
struct V_235 V_236 = { V_237 , NULL } ;
struct V_238 * V_239 = F_152 ( V_240 , V_27 ) ;
if ( ! V_239 )
continue;
V_232 = F_153 ( V_239 -> V_241 , L_26 , NULL , & V_236 ) ;
if ( F_154 ( V_232 ) )
continue;
V_234 = V_236 . V_242 ;
if ( V_234 && V_234 -> type == V_243 ) {
F_143 ( V_234 ) ;
return false ;
}
F_143 ( V_234 ) ;
}
return true ;
}
static bool T_9 F_155 ( void )
{
int V_27 ;
F_49 (i) {
struct V_238 * V_239 = F_152 ( V_240 , V_27 ) ;
if ( ! V_239 )
continue;
if ( F_156 ( V_239 -> V_241 , L_27 ) )
return true ;
}
return false ;
}
static bool T_9 F_157 ( void )
{
const struct V_196 * V_197 ;
T_3 V_244 ;
int V_245 ;
V_197 = F_114 ( V_246 ) ;
if ( V_197 ) {
F_24 ( V_247 , V_244 ) ;
if ( V_244 & ( 1 << 8 ) )
return true ;
}
V_245 = F_158 ( V_137 ) ;
if ( V_245 < 0 )
return false ;
switch ( V_137 [ V_245 ] . V_185 ) {
case V_248 :
return F_151 () ;
case V_249 :
return F_155 () && ! V_250 ;
}
return false ;
}
static void F_159 ( void )
{
if ( V_13 )
F_160 () ;
}
static inline bool F_157 ( void ) { return false ; }
static inline bool F_155 ( void ) { return false ; }
static inline void F_159 ( void ) {}
static int T_9 F_161 ( void )
{
int V_113 ;
if ( V_251 )
return - V_207 ;
if ( F_114 ( V_252 ) ) {
F_150 ( & V_253 ) ;
if ( ! V_254 ) {
V_28 ++ ;
V_225 . V_97 = V_255 ;
goto V_256;
}
} else {
const struct V_196 * V_197 ;
V_197 = F_114 ( V_257 ) ;
if ( ! V_197 )
return - V_207 ;
F_150 ( (struct V_151 * ) V_197 -> V_258 ) ;
}
if ( F_149 () )
return - V_207 ;
V_256:
if ( F_157 () )
return - V_207 ;
if ( ! V_28 && V_259 )
return - V_260 ;
F_72 ( L_28 ) ;
V_29 = F_162 ( sizeof( void * ) * F_163 () ) ;
if ( ! V_29 )
return - V_195 ;
F_159 () ;
F_64 () ;
F_34 ( & V_98 ) ;
V_113 = F_145 ( V_261 ) ;
F_36 ( & V_98 ) ;
if ( V_113 )
return V_113 ;
if ( V_28 )
F_72 ( L_29 ) ;
return 0 ;
}
static int T_9 F_164 ( char * V_262 )
{
if ( ! V_262 )
return - V_64 ;
if ( ! strcmp ( V_262 , L_30 ) ) {
V_251 = 1 ;
} else if ( ! strcmp ( V_262 , L_24 ) ) {
F_72 ( L_31 ) ;
V_261 = & V_230 ;
V_254 = 1 ;
}
if ( ! strcmp ( V_262 , L_32 ) ) {
F_72 ( L_33 ) ;
V_254 = 1 ;
}
if ( ! strcmp ( V_262 , L_34 ) )
V_250 = 1 ;
if ( ! strcmp ( V_262 , L_35 ) )
V_259 = 1 ;
if ( ! strcmp ( V_262 , L_36 ) )
V_117 = true ;
#ifdef F_165
if ( ! strcmp ( V_262 , L_37 ) )
V_13 = true ;
#endif
return 0 ;
}
