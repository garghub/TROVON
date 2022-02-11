static int F_1 ( struct V_1 * V_2 , int V_3 , ... )
{
int V_4 , V_5 ;
T_1 V_6 ;
T_2 V_7 [ V_8 ] ;
va_start ( V_6 , V_3 ) ;
if ( F_2 ( V_3 > V_8 ) ) {
F_3 ( & V_2 -> V_9 -> V_10 , L_1 , V_3 ) ;
va_end ( V_6 ) ;
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_7 [ V_5 ] = va_arg ( V_6 , int ) ;
va_end ( V_6 ) ;
V_4 = F_4 ( V_2 -> V_9 , V_7 , V_3 ) ;
if ( F_2 ( V_4 == - V_11 ) )
V_4 = F_4 ( V_2 -> V_9 , V_7 , V_3 ) ;
if ( F_2 ( V_4 != V_3 ) )
F_3 ( & V_2 -> V_9 -> V_10 , L_2 ,
V_3 , V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_12 , T_2 * V_13 , int V_3 )
{
int V_4 ;
V_4 = F_4 ( V_2 -> V_9 , & V_12 , 1 ) ;
if ( F_2 ( V_4 == - V_11 ) )
V_4 = F_4 ( V_2 -> V_9 , & V_12 , 1 ) ;
if ( F_2 ( V_4 != 1 ) ) {
F_3 ( & V_2 -> V_9 -> V_10 , L_3 ,
V_12 ) ;
return 0 ;
}
V_4 = F_6 ( V_2 -> V_9 , V_13 , V_3 ) ;
if ( F_2 ( V_4 != V_3 ) )
F_3 ( & V_2 -> V_9 -> V_10 , L_4 ,
V_3 , V_4 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 , int time )
{
F_1 ( V_2 , 2 , V_14 , time >> 2 ) ;
}
static inline T_2 F_8 ( T_2 V_15 )
{
return V_15 & 0x7f ;
}
static inline int F_9 ( T_2 V_15 )
{
return ( V_15 & 0x80 ) ? 1 : 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_2 V_16 [ V_17 + 1 ] ;
int V_18 = V_2 -> V_19 ;
int V_4 ;
int V_5 = 0 ;
V_4 = F_5 ( V_2 , V_20 , V_16 , V_17 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_9 -> V_10 , L_5 ) ;
return;
}
V_16 [ V_4 ] = 0 ;
while ( ( V_15 = V_16 [ V_5 ++ ] ) ) {
T_2 V_21 = F_8 ( V_15 ) ;
int V_22 = F_9 ( V_15 ) ;
unsigned short V_23 = V_2 -> V_24 [ V_21 ] ;
F_11 ( & V_2 -> V_9 -> V_10 , L_6 ,
V_21 , V_22 ? L_7 : L_8 ) ;
if ( V_2 -> V_25 ) {
F_12 ( V_2 -> V_26 , V_27 , V_28 , V_21 ) ;
F_13 ( V_2 -> V_26 , V_23 , V_22 ) ;
F_14 ( V_2 -> V_26 ) ;
}
if ( V_22 )
V_2 -> V_19 ++ ;
else
V_2 -> V_19 -- ;
}
if ( ! V_18 && V_2 -> V_19 )
F_7 ( V_2 , 0 ) ;
if ( V_18 && ! V_2 -> V_19 )
F_7 ( V_2 , V_2 -> V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 error ;
if ( F_5 ( V_2 , V_30 , & error , 1 ) == 1 ) {
if ( error & V_31 )
F_11 ( & V_2 -> V_9 -> V_10 , L_9 ) ;
if ( error & V_32 )
F_11 ( & V_2 -> V_9 -> V_10 ,
L_10 ) ;
if ( error & V_33 )
F_11 ( & V_2 -> V_9 -> V_10 ,
L_11 ) ;
if ( error & V_34 )
F_11 ( & V_2 -> V_9 -> V_10 , L_12 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 2 , V_35 , 0xAA ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_36 = ( V_2 -> V_37 << 4 ) | V_2 -> V_38 ;
int clock = ( V_39 | V_40 ) ;
int V_41 = V_2 -> V_42 >> 2 ;
int V_43 = V_2 -> V_29 >> 2 ;
if ( V_41 >= V_43 )
V_43 = V_41 + 3 ;
F_1 ( V_2 , 2 , V_44 , 0 ) ;
F_1 ( V_2 , 2 , V_45 , clock ) ;
F_1 ( V_2 , 2 , V_46 , V_36 ) ;
F_7 ( V_2 , V_2 -> V_29 ) ;
F_1 ( V_2 , 2 , V_47 , V_41 ) ;
F_1 ( V_2 , 3 , V_48 , 0xff , 0xff ) ;
F_1 ( V_2 , 3 , V_49 , 0 , 0 ) ;
return 0 ;
}
static void F_18 ( struct V_50 * V_51 )
{
F_19 ( & V_51 -> V_52 ) ;
V_51 -> V_53 = false ;
if ( V_51 -> V_54 != V_51 -> V_55 )
F_20 ( & V_51 -> V_56 ) ;
F_21 ( & V_51 -> V_52 ) ;
}
static T_3 F_22 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_2 V_59 ;
int V_5 ;
F_19 ( & V_2 -> V_52 ) ;
while ( ( F_5 ( V_2 , V_60 , & V_59 , 1 ) == 1 ) && V_59 ) {
if ( F_23 ( V_59 & V_61 ) )
F_10 ( V_2 ) ;
if ( V_59 & V_62 ) {
F_11 ( & V_2 -> V_9 -> V_10 , L_13 ) ;
}
if ( V_59 & V_63 ) {
F_11 ( & V_2 -> V_9 -> V_10 , L_14 ) ;
F_15 ( V_2 ) ;
}
if ( V_59 & V_64 ) {
F_3 ( & V_2 -> V_9 -> V_10 , L_15
L_16 ) ;
F_17 ( V_2 ) ;
}
for ( V_5 = 0 ; V_5 < V_65 ; V_5 ++ ) {
if ( V_59 & ( 1 << ( V_66 + V_5 ) ) ) {
F_11 ( & V_2 -> V_9 -> V_10 ,
L_17 , V_5 ) ;
F_18 ( & V_2 -> V_51 [ V_5 ] ) ;
}
}
}
F_21 ( & V_2 -> V_52 ) ;
return V_67 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 * V_13 )
{
int V_68 ;
V_68 = F_5 ( V_2 , V_69 , V_13 , 2 ) ;
if ( F_2 ( V_68 != 2 ) )
return - V_70 ;
return 0 ;
}
static void F_25 ( struct V_50 * V_51 , int V_71 , T_4 V_12 )
{
F_1 ( V_51 -> V_72 , 4 , V_73 , ( V_71 << 2 ) | V_51 -> V_74 ,
( V_12 & 0xff00 ) >> 8 , V_12 & 0x00ff ) ;
}
static void F_26 ( struct V_50 * V_51 , int V_75 ,
int V_3 , const T_4 * V_76 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
F_25 ( V_51 , V_5 , V_76 [ V_5 ] ) ;
F_25 ( V_51 , V_5 ++ , F_27 ( V_75 ) ) ;
F_1 ( V_51 -> V_72 , 2 , V_77 , V_51 -> V_74 ) ;
V_51 -> V_53 = true ;
}
static void F_28 ( struct V_78 * V_56 )
{
struct V_50 * V_51 = F_29 ( V_56 ) ;
int V_79 , V_80 , V_81 , V_82 , V_83 , V_75 ;
T_4 V_84 [ 3 ] ;
int V_85 = 0 ;
F_19 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_53 || V_51 -> V_54 == V_51 -> V_55 )
goto V_86;
V_75 = ( V_51 -> V_54 == 0 ) ;
V_83 = ( V_51 -> V_54 > V_51 -> V_55 ) ;
V_81 = abs ( V_51 -> V_54 - V_51 -> V_55 ) ;
if ( ( V_51 -> V_87 / V_81 ) > ( 32768 / 512 ) ) {
V_79 = 1 ;
V_82 = 32768 / 512 ;
} else {
V_79 = 0 ;
V_82 = 32768 / 16 ;
}
V_80 = ( V_82 * V_51 -> V_87 ) / ( V_81 * 1000 ) ;
if ( V_80 == 0 )
V_80 = 1 ;
else if ( V_80 > 63 )
V_80 = 63 ;
while ( V_81 ) {
int V_88 ;
V_88 = F_30 ( 126 , V_81 ) ;
V_84 [ V_85 ++ ] = F_31 ( V_79 , V_80 , V_88 , V_83 ) ;
V_81 -= V_88 ;
}
F_26 ( V_51 , V_75 , V_85 , V_84 ) ;
V_51 -> V_55 = V_51 -> V_54 ;
V_86:
F_21 ( & V_51 -> V_52 ) ;
}
static void F_32 ( struct V_89 * V_90 ,
enum V_91 V_55 )
{
struct V_50 * V_51 = F_33 ( V_90 ) ;
struct V_1 * V_2 = V_51 -> V_72 ;
F_19 ( & V_51 -> V_52 ) ;
V_51 -> V_54 = V_55 ;
F_21 ( & V_51 -> V_52 ) ;
if ( F_34 () ) {
F_20 ( & V_51 -> V_56 ) ;
} else {
F_19 ( & V_2 -> V_52 ) ;
if ( F_23 ( ! V_2 -> V_92 ) )
F_20 ( & V_51 -> V_56 ) ;
else
F_28 ( & V_51 -> V_56 ) ;
F_21 ( & V_2 -> V_52 ) ;
}
}
static T_5 F_35 ( struct V_93 * V_10 ,
struct V_94 * V_95 , char * V_13 )
{
struct V_89 * V_90 = F_36 ( V_10 ) ;
struct V_50 * V_51 = F_33 ( V_90 ) ;
return sprintf ( V_13 , L_18 , V_51 -> V_87 ) ;
}
static T_5 F_37 ( struct V_93 * V_10 ,
struct V_94 * V_95 , const char * V_13 , T_6 V_3 )
{
struct V_89 * V_90 = F_36 ( V_10 ) ;
struct V_50 * V_51 = F_33 ( V_90 ) ;
int V_4 , time ;
V_4 = F_38 ( V_13 , 10 , & time ) ;
if ( V_4 )
return V_4 ;
V_51 -> V_87 = time ;
return strlen ( V_13 ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_74 , struct V_93 * V_10 ,
const char * V_96 )
{
struct V_50 * V_51 ;
F_40 ( V_74 > 3 ) ;
V_51 = & V_2 -> V_51 [ V_74 - 1 ] ;
V_51 -> V_74 = V_74 ;
V_51 -> V_87 = 0 ;
V_51 -> V_55 = 0 ;
V_51 -> V_54 = 0 ;
V_51 -> V_53 = false ;
V_51 -> V_97 = false ;
F_41 ( & V_51 -> V_56 , F_28 ) ;
F_42 ( & V_51 -> V_52 ) ;
V_51 -> V_72 = V_2 ;
if ( V_96 ) {
V_51 -> V_98 . V_96 = V_96 ;
V_51 -> V_98 . V_99 = F_32 ;
if ( F_43 ( V_10 , & V_51 -> V_98 ) < 0 ) {
F_3 ( V_10 , L_19 , V_74 ) ;
return - 1 ;
}
if ( F_44 ( V_51 -> V_98 . V_10 ,
& V_100 ) < 0 ) {
F_3 ( V_10 , L_20 ) ;
F_45 ( & V_51 -> V_98 ) ;
return - 1 ;
}
V_51 -> V_97 = true ;
}
return 0 ;
}
static T_5 F_46 ( struct V_93 * V_10 ,
struct V_94 * V_95 , char * V_13 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
return sprintf ( V_13 , L_21 , ! V_2 -> V_25 ) ;
}
static T_5 F_47 ( struct V_93 * V_10 ,
struct V_94 * V_95 ,
const char * V_13 , T_6 V_101 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
int V_4 ;
unsigned int V_5 ;
V_4 = F_48 ( V_13 , 10 , & V_5 ) ;
F_19 ( & V_2 -> V_52 ) ;
V_2 -> V_25 = ! V_5 ;
F_21 ( & V_2 -> V_52 ) ;
return V_101 ;
}
static int T_7 F_49 ( struct V_102 * V_9 ,
const struct V_103 * V_74 )
{
struct V_104 * V_105 = V_9 -> V_10 . V_106 ;
struct V_107 * V_26 ;
struct V_1 * V_2 ;
int V_51 ;
int V_5 , V_108 ;
unsigned long V_109 ;
T_2 V_7 [ 2 ] ;
if ( ! V_105 || ! V_105 -> V_37 || ! V_105 -> V_38 ) {
F_3 ( & V_9 -> V_10 , L_22 ) ;
return - V_110 ;
}
if ( V_105 -> V_37 > 8 ) {
F_3 ( & V_9 -> V_10 , L_23 ,
V_105 -> V_37 ) ;
return - V_110 ;
}
if ( V_105 -> V_38 > 12 ) {
F_3 ( & V_9 -> V_10 , L_24 ,
V_105 -> V_38 ) ;
return - V_110 ;
}
V_2 = F_50 ( sizeof *V_2 , V_111 ) ;
V_26 = F_51 () ;
if ( ! V_2 || ! V_26 ) {
V_108 = - V_112 ;
goto V_113;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_26 = V_26 ;
F_42 ( & V_2 -> V_52 ) ;
V_2 -> V_37 = V_105 -> V_37 ;
V_2 -> V_38 = V_105 -> V_38 ;
F_11 ( & V_9 -> V_10 , L_25 ,
V_2 -> V_37 , V_2 -> V_38 ) ;
V_2 -> V_42 = V_105 -> V_42 ;
V_2 -> V_29 = V_105 -> V_29 ;
F_16 ( V_2 ) ;
V_109 = V_114 + F_52 ( 100 ) ;
while ( F_5 ( V_2 , V_60 , V_7 , 1 ) == 1 ) {
if ( V_7 [ 0 ] & V_64 )
break;
if ( F_53 ( V_114 , V_109 ) ) {
F_3 ( & V_9 -> V_10 ,
L_26 ) ;
break;
}
F_54 ( 1 ) ;
}
F_17 ( V_2 ) ;
if ( F_24 ( V_2 , V_7 ) != 0 ) {
F_3 ( & V_9 -> V_10 , L_27 ) ;
V_108 = - V_115 ;
goto V_113;
}
for ( V_51 = 0 ; V_51 < V_65 ; V_51 ++ ) {
V_108 = F_39 ( V_2 , V_51 + 1 , & V_9 -> V_10 ,
V_105 -> V_116 [ V_51 ] ) ;
if ( V_108 < 0 )
goto V_117;
}
V_2 -> V_25 = true ;
V_108 = F_44 ( & V_9 -> V_10 , & V_118 ) ;
if ( V_108 < 0 )
goto V_117;
V_26 -> V_96 = V_105 -> V_96 ? : L_28 ;
snprintf ( V_2 -> V_119 , sizeof( V_2 -> V_119 ) ,
L_29 , F_55 ( & V_9 -> V_10 ) ) ;
V_26 -> V_119 = V_2 -> V_119 ;
V_26 -> V_120 [ 0 ] = F_56 ( V_121 ) | F_56 ( V_27 ) ;
F_57 ( V_28 , V_26 -> V_122 ) ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
F_57 ( V_105 -> V_24 [ V_5 ] , V_26 -> V_124 ) ;
V_2 -> V_24 [ V_5 ] = V_105 -> V_24 [ V_5 ] ;
}
F_58 ( V_125 , V_26 -> V_124 ) ;
if ( V_105 -> V_126 )
F_57 ( V_127 , V_26 -> V_120 ) ;
V_108 = F_59 ( V_26 ) ;
if ( V_108 ) {
F_60 ( & V_9 -> V_10 , L_30 ) ;
goto V_128;
}
V_108 = F_61 ( V_9 -> V_57 , NULL , F_22 ,
V_129 | V_130 , L_31 , V_2 ) ;
if ( V_108 ) {
F_3 ( & V_9 -> V_10 , L_32 , V_9 -> V_57 ) ;
goto V_131;
}
F_62 ( V_9 , V_2 ) ;
F_63 ( & V_9 -> V_10 , 1 ) ;
F_64 ( V_9 -> V_57 ) ;
return 0 ;
V_131:
F_65 ( V_26 ) ;
V_26 = NULL ;
V_128:
F_66 ( & V_9 -> V_10 , & V_118 ) ;
V_117:
while ( -- V_51 >= 0 )
if ( V_2 -> V_51 [ V_51 ] . V_97 ) {
F_66 ( V_2 -> V_51 [ V_51 ] . V_98 . V_10 ,
& V_100 ) ;
F_45 ( & V_2 -> V_51 [ V_51 ] . V_98 ) ;
}
V_113:
F_67 ( V_26 ) ;
F_68 ( V_2 ) ;
return V_108 ;
}
static int T_8 F_69 ( struct V_102 * V_9 )
{
struct V_1 * V_2 = F_70 ( V_9 ) ;
int V_5 ;
F_71 ( V_9 -> V_57 ) ;
F_72 ( V_9 -> V_57 , V_2 ) ;
F_65 ( V_2 -> V_26 ) ;
F_66 ( & V_2 -> V_9 -> V_10 , & V_118 ) ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ )
if ( V_2 -> V_51 [ V_5 ] . V_97 ) {
F_66 ( V_2 -> V_51 [ V_5 ] . V_98 . V_10 , & V_100 ) ;
F_45 ( & V_2 -> V_51 [ V_5 ] . V_98 ) ;
}
F_68 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_93 * V_10 )
{
struct V_102 * V_9 = F_74 ( V_10 ) ;
struct V_1 * V_2 = F_70 ( V_9 ) ;
int V_5 ;
F_75 ( V_9 -> V_57 , 0 ) ;
F_76 ( V_9 -> V_57 ) ;
F_19 ( & V_2 -> V_52 ) ;
V_2 -> V_92 = true ;
F_21 ( & V_2 -> V_52 ) ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ )
if ( V_2 -> V_51 [ V_5 ] . V_97 )
F_77 ( & V_2 -> V_51 [ V_5 ] . V_98 ) ;
return 0 ;
}
static int F_78 ( struct V_93 * V_10 )
{
struct V_102 * V_9 = F_74 ( V_10 ) ;
struct V_1 * V_2 = F_70 ( V_9 ) ;
int V_5 ;
F_19 ( & V_2 -> V_52 ) ;
V_2 -> V_92 = false ;
F_21 ( & V_2 -> V_52 ) ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ )
if ( V_2 -> V_51 [ V_5 ] . V_97 )
F_79 ( & V_2 -> V_51 [ V_5 ] . V_98 ) ;
F_80 ( V_9 -> V_57 ) ;
F_75 ( V_9 -> V_57 , 1 ) ;
return 0 ;
}
