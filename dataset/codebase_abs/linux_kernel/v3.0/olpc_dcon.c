static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_5 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_6 )
{
struct V_7 * V_5 = V_2 -> V_5 ;
T_4 V_8 ;
int V_9 = 0 ;
V_8 = F_4 ( V_5 , V_10 ) ;
if ( ( V_8 >> 8 ) != 0xDC ) {
F_6 ( V_11 L_1
L_2 , V_8 ) ;
V_9 = - V_12 ;
goto V_13;
}
if ( V_6 ) {
F_6 ( V_14 L_3 ,
V_8 & 0xFF ) ;
V_9 = V_15 -> V_16 ( V_2 ) ;
if ( V_9 != 0 ) {
F_6 ( V_11 L_4 ) ;
goto V_13;
}
}
if ( V_8 < 0xdc02 && ! V_17 ) {
F_2 ( V_5 , 0x4b , 0x00cc ) ;
F_2 ( V_5 , 0x4b , 0x00cc ) ;
F_2 ( V_5 , 0x4b , 0x00cc ) ;
F_2 ( V_5 , 0x0b , 0x007a ) ;
F_2 ( V_5 , 0x36 , 0x025c ) ;
F_2 ( V_5 , 0x37 , 0x025e ) ;
F_2 ( V_5 , 0x3b , 0x002b ) ;
F_2 ( V_5 , 0x41 , 0x0101 ) ;
F_2 ( V_5 , 0x42 , 0x0101 ) ;
} else if ( ! V_17 ) {
F_2 ( V_5 , 0x3a , 0xc040 ) ;
F_2 ( V_5 , 0x41 , 0x0000 ) ;
F_2 ( V_5 , 0x41 , 0x0101 ) ;
F_2 ( V_5 , 0x42 , 0x0101 ) ;
}
if ( V_6 ) {
V_2 -> V_18 = V_19 | V_20 |
V_21 ;
if ( V_22 )
V_2 -> V_18 |= V_23 ;
}
F_2 ( V_5 , V_24 , V_2 -> V_18 ) ;
F_2 ( V_5 , V_25 , V_26 ) ;
V_13:
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_27 )
{
unsigned long V_28 ;
int V_29 ;
V_30:
if ( V_27 ) {
V_29 = 1 ;
V_29 = F_8 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
if ( V_29 ) {
F_6 ( V_31 L_5
L_6 , V_29 ) ;
return V_29 ;
}
F_9 ( 10 ) ;
}
V_15 -> V_32 () ;
for ( V_29 = - 1 , V_28 = 50 ; V_28 && V_29 < 0 ; V_28 -- ) {
F_9 ( 1 ) ;
V_29 = F_3 ( V_2 , V_10 ) ;
}
if ( V_29 < 0 ) {
F_6 ( V_11 L_7
L_8 ) ;
F_10 ( F_11 ( F_12 ( 0xc2 ) ) ) ;
V_29 = 0 ;
F_8 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
F_9 ( 100 ) ;
V_27 = 1 ;
goto V_30;
}
if ( V_27 )
return F_5 ( V_2 , 0 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_34 = V_33 ;
F_1 ( V_2 , V_35 , V_2 -> V_34 ) ;
if ( V_2 -> V_34 == 0 ) {
V_2 -> V_18 &= ~ V_20 ;
F_1 ( V_2 , V_24 , V_2 -> V_18 ) ;
} else if ( ! ( V_2 -> V_18 & V_20 ) ) {
V_2 -> V_18 |= V_20 ;
F_1 ( V_2 , V_24 , V_2 -> V_18 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , bool V_36 )
{
if ( V_2 -> V_37 == V_36 )
return 0 ;
V_2 -> V_37 = V_36 ;
if ( V_36 ) {
V_2 -> V_18 &= ~ ( V_21 | V_23 ) ;
V_2 -> V_18 |= V_38 ;
} else {
V_2 -> V_18 &= ~ ( V_38 ) ;
V_2 -> V_18 |= V_21 ;
if ( V_22 )
V_2 -> V_18 |= V_23 ;
}
F_1 ( V_2 , V_24 , V_2 -> V_18 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_39 )
{
int V_29 ;
if ( V_2 -> V_40 == V_39 )
return;
if ( ! F_11 ( F_12 ( 0xc2 ) ) )
return;
if ( V_39 ) {
V_29 = 0 ;
V_29 = F_8 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
if ( V_29 )
F_6 ( V_31 L_5
L_9 , V_29 ) ;
else
V_2 -> V_40 = V_39 ;
} else {
if ( V_2 -> V_34 != 0 )
V_2 -> V_18 |= V_20 ;
V_29 = F_7 ( V_2 , 1 ) ;
if ( V_29 )
F_6 ( V_31 L_10
L_11 , V_29 ) ;
else
V_2 -> V_40 = V_39 ;
F_13 ( V_2 , V_2 -> V_34 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_41 V_42 , V_43 ;
while ( 1 ) {
F_17 ( & V_43 ) ;
V_42 = F_18 ( V_43 , V_2 -> V_44 ) ;
if ( V_42 . V_45 != 0 ||
V_42 . V_46 > V_47 * 20 ) {
break;
}
F_19 ( 4 ) ;
}
}
static bool F_20 ( struct V_1 * V_2 , bool V_48 )
{
int V_13 ;
if ( ! F_21 ( V_2 -> V_49 ) ) {
F_22 ( & V_2 -> V_5 -> V_50 , L_12 ) ;
return false ;
}
F_23 () ;
V_2 -> V_51 = true ;
V_13 = F_24 ( V_2 -> V_49 ,
V_48 ? V_52 : V_53 ) ;
V_2 -> V_51 = false ;
F_25 () ;
F_26 ( V_2 -> V_49 ) ;
if ( V_13 ) {
F_22 ( & V_2 -> V_5 -> V_50 , L_13 ,
V_48 ? L_14 : L_15 ) ;
return false ;
}
return true ;
}
static void F_27 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_28 ( V_55 , struct V_1 ,
V_56 ) ;
F_29 ( V_57 , V_58 ) ;
int V_59 = V_2 -> V_60 ;
if ( V_2 -> V_61 == V_59 )
return;
F_16 ( V_2 ) ;
V_2 -> V_62 = false ;
switch ( V_59 ) {
case V_63 :
F_6 ( L_16 ) ;
if ( F_1 ( V_2 , V_24 ,
V_2 -> V_18 | V_64 ) )
F_6 ( V_11
L_17 ) ;
else {
F_30 ( V_65 ,
V_2 -> V_62 == true , V_66 ) ;
}
if ( ! V_2 -> V_62 )
F_6 ( V_11 L_18 ) ;
if ( F_1 ( V_2 , V_24 , V_2 -> V_18 ) )
F_6 ( V_11 L_19 ) ;
if ( ! F_20 ( V_2 , false ) ) {
F_6 ( V_11 L_20 ) ;
V_2 -> V_60 = V_67 ;
return;
}
V_15 -> V_68 ( 1 ) ;
F_17 ( & V_2 -> V_44 ) ;
F_6 ( V_14 L_21 ) ;
break;
case V_67 :
{
int V_69 ;
struct V_41 V_42 ;
F_6 ( V_14 L_22 ) ;
F_31 ( & V_65 , & V_57 ) ;
F_32 ( V_70 ) ;
V_15 -> V_68 ( 0 ) ;
F_17 ( & V_2 -> V_44 ) ;
V_69 = F_33 ( V_66 / 2 ) ;
F_34 ( & V_65 , & V_57 ) ;
F_32 ( V_71 ) ;
if ( ! V_2 -> V_62 ) {
F_6 ( V_11 L_23 ) ;
} else {
V_42 = F_18 ( V_2 -> V_72 , V_2 -> V_44 ) ;
if ( V_2 -> V_62 && V_42 . V_45 == 0 &&
V_42 . V_46 < V_47 * 20 ) {
F_6 ( V_11 L_24 ) ;
V_15 -> V_68 ( 1 ) ;
F_19 ( 41 ) ;
V_15 -> V_68 ( 0 ) ;
F_17 ( & V_2 -> V_44 ) ;
F_19 ( 41 ) ;
}
}
F_20 ( V_2 , true ) ;
F_6 ( V_14 L_25 ) ;
break;
}
default:
F_35 () ;
}
V_2 -> V_61 = V_59 ;
}
static void F_36 ( struct V_1 * V_2 , int V_73 )
{
if ( V_2 -> V_60 == V_73 )
return;
V_2 -> V_60 = V_73 ;
if ( ( V_2 -> V_61 != V_73 ) && ! F_37 ( & V_2 -> V_56 ) )
F_38 ( & V_2 -> V_56 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_73 )
{
F_36 ( V_2 , V_73 ) ;
F_40 () ;
}
static T_5 F_41 ( struct V_74 * V_50 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
return sprintf ( V_77 , L_26 , V_2 -> V_18 ) ;
}
static T_5 F_43 ( struct V_74 * V_50 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
return sprintf ( V_77 , L_27 , V_2 -> V_40 ) ;
}
static T_5 F_44 ( struct V_74 * V_50 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
return sprintf ( V_77 , L_27 , V_2 -> V_61 == V_67 ? 1 : 0 ) ;
}
static T_5 F_45 ( struct V_74 * V_50 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
return sprintf ( V_77 , L_27 , V_2 -> V_37 ) ;
}
static T_5 F_46 ( struct V_74 * V_50 ,
struct V_75 * V_76 , char * V_77 )
{
return sprintf ( V_77 , L_27 , V_26 ) ;
}
static T_5 F_47 ( struct V_74 * V_50 ,
struct V_75 * V_76 , const char * V_77 , T_6 V_78 )
{
unsigned long V_36 ;
int V_9 ;
V_9 = F_48 ( V_77 , 10 , & V_36 ) ;
if ( V_9 )
return V_9 ;
F_14 ( F_42 ( V_50 ) , V_36 ? true : false ) ;
return V_78 ;
}
static T_5 F_49 ( struct V_74 * V_50 ,
struct V_75 * V_76 , const char * V_77 , T_6 V_78 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
unsigned long V_79 ;
int V_80 ;
V_80 = F_48 ( V_77 , 10 , & V_79 ) ;
if ( V_80 )
return V_80 ;
F_6 ( V_14 L_28 , V_79 ) ;
switch ( V_79 ) {
case 0 :
F_36 ( V_2 , V_63 ) ;
break;
case 1 :
F_39 ( V_2 , V_67 ) ;
break;
case 2 :
F_36 ( V_2 , V_67 ) ;
break;
default:
return - V_81 ;
}
return V_78 ;
}
static T_5 F_50 ( struct V_74 * V_50 ,
struct V_75 * V_76 , const char * V_77 , T_6 V_78 )
{
unsigned long V_82 ;
int V_9 ;
V_9 = F_48 ( V_77 , 10 , & V_82 ) ;
if ( V_9 )
return V_9 ;
V_26 = V_82 ;
F_1 ( F_42 ( V_50 ) , V_25 , V_26 ) ;
return V_78 ;
}
static T_5 F_51 ( struct V_74 * V_50 ,
struct V_75 * V_76 , const char * V_77 , T_6 V_78 )
{
unsigned long V_79 ;
int V_80 ;
V_80 = F_48 ( V_77 , 10 , & V_79 ) ;
if ( V_80 )
return V_80 ;
F_15 ( F_42 ( V_50 ) , V_79 ? true : false ) ;
return V_78 ;
}
static int F_52 ( struct V_83 * V_50 )
{
struct V_1 * V_2 = F_53 ( V_50 ) ;
T_2 V_33 = V_50 -> V_84 . V_85 & 0x0F ;
if ( V_50 -> V_84 . V_86 != V_53 )
V_33 = 0 ;
if ( V_33 != V_2 -> V_34 )
F_13 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_54 ( struct V_83 * V_50 )
{
struct V_1 * V_2 = F_53 ( V_50 ) ;
return V_2 -> V_34 ;
}
static int F_55 ( struct V_87 * V_88 ,
unsigned long V_89 , void * V_90 )
{
struct V_1 * V_2 = F_28 ( V_88 , struct V_1 , V_91 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return 0 ;
F_1 ( V_2 , V_24 , 0x39 ) ;
F_1 ( V_2 , V_24 , 0x32 ) ;
return 0 ;
}
static int F_56 ( struct V_87 * V_88 ,
unsigned long V_92 , void * V_93 )
{
V_15 -> V_68 ( 1 ) ;
return V_94 ;
}
static int F_57 ( struct V_87 * V_95 ,
unsigned long V_96 , void * V_97 )
{
struct V_98 * V_99 = V_97 ;
struct V_1 * V_2 = F_28 ( V_95 , struct V_1 ,
V_100 ) ;
int * V_48 = ( int * ) V_99 -> V_97 ;
if ( ( ( V_96 != V_101 ) && ( V_96 != V_102 ) ) ||
V_2 -> V_51 )
return 0 ;
F_15 ( V_2 , * V_48 ? true : false ) ;
return 0 ;
}
static int F_58 ( struct V_7 * V_5 , struct V_103 * V_104 )
{
F_59 ( V_104 -> type , L_29 , V_105 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_5 , const struct V_106 * V_107 )
{
struct V_1 * V_2 ;
int V_9 , V_108 , V_109 ;
if ( ! V_15 )
return - V_12 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_5 = V_5 ;
F_62 ( & V_2 -> V_56 , F_27 ) ;
V_2 -> V_91 . V_112 = F_55 ;
V_2 -> V_91 . V_113 = - 1 ;
V_2 -> V_100 . V_112 = F_57 ;
F_63 ( V_5 , V_2 ) ;
if ( V_114 < 1 ) {
F_22 ( & V_5 -> V_50 , L_30 ) ;
V_9 = - V_115 ;
goto V_116;
}
V_2 -> V_49 = V_117 [ 0 ] ;
V_9 = F_5 ( V_2 , 1 ) ;
if ( V_9 )
goto V_116;
V_118 = F_64 ( L_31 , - 1 ) ;
if ( V_118 == NULL ) {
F_6 ( V_11 L_32 ) ;
V_9 = - V_111 ;
goto V_119;
}
V_9 = F_65 ( V_118 ) ;
F_66 ( V_118 , V_2 ) ;
if ( V_9 ) {
F_6 ( V_11 L_33 ) ;
goto V_120;
}
for ( V_108 = 0 ; V_108 < F_67 ( V_121 ) ; V_108 ++ ) {
V_9 = F_68 ( & V_118 -> V_50 ,
& V_121 [ V_108 ] ) ;
if ( V_9 ) {
F_22 ( & V_118 -> V_50 , L_34 ) ;
goto V_122;
}
}
V_2 -> V_34 = F_3 ( V_2 , V_35 ) & 0x0F ;
V_123 . V_85 = V_2 -> V_34 ;
V_2 -> V_124 = F_69 ( L_35 , & V_118 -> V_50 ,
V_2 , & V_125 , & V_123 ) ;
if ( F_70 ( V_2 -> V_124 ) ) {
F_22 ( & V_5 -> V_50 , L_36 ,
F_71 ( V_2 -> V_124 ) ) ;
V_2 -> V_124 = NULL ;
}
F_72 ( & V_2 -> V_91 ) ;
F_73 ( & V_126 , & V_127 ) ;
F_74 ( & V_2 -> V_100 ) ;
return 0 ;
V_122:
for ( V_109 = 0 ; V_109 < V_108 ; V_109 ++ )
F_75 ( & V_118 -> V_50 , & V_121 [ V_109 ] ) ;
V_120:
F_76 ( V_118 ) ;
V_118 = NULL ;
V_119:
F_77 ( V_128 , V_2 ) ;
V_116:
F_63 ( V_5 , NULL ) ;
F_78 ( V_2 ) ;
return V_9 ;
}
static int F_79 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_80 ( V_5 ) ;
F_63 ( V_5 , NULL ) ;
F_81 ( & V_2 -> V_100 ) ;
F_82 ( & V_2 -> V_91 ) ;
F_83 ( & V_126 , & V_127 ) ;
F_77 ( V_128 , V_2 ) ;
if ( V_2 -> V_124 )
F_84 ( V_2 -> V_124 ) ;
if ( V_118 != NULL )
F_76 ( V_118 ) ;
F_85 ( & V_2 -> V_56 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_7 * V_5 , T_7 V_129 )
{
struct V_1 * V_2 = F_80 ( V_5 ) ;
if ( ! V_2 -> V_40 ) {
F_39 ( V_2 , V_67 ) ;
}
return 0 ;
}
static int F_87 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_80 ( V_5 ) ;
if ( ! V_2 -> V_40 ) {
F_7 ( V_2 , 0 ) ;
F_36 ( V_2 , V_63 ) ;
}
return 0 ;
}
T_8 F_88 ( int V_130 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
int V_131 = V_15 -> V_132 () ;
if ( V_131 == - 1 )
return V_133 ;
switch ( V_131 & 3 ) {
case 3 :
F_6 ( V_134 L_37 ) ;
break;
case 2 :
case 1 :
V_2 -> V_62 = true ;
F_17 ( & V_2 -> V_72 ) ;
F_89 ( & V_65 ) ;
break;
case 0 :
if ( V_2 -> V_61 != V_2 -> V_60 && ! V_2 -> V_62 ) {
V_2 -> V_62 = true ;
F_17 ( & V_2 -> V_72 ) ;
F_89 ( & V_65 ) ;
F_6 ( V_134 L_38 ) ;
} else {
F_6 ( V_134 L_39 ) ;
}
}
return V_135 ;
}
static int T_9 F_90 ( void )
{
#ifdef F_91
if ( F_11 ( F_12 ( 0xd0 ) ) )
V_15 = & V_136 ;
#endif
#ifdef F_92
if ( ! V_15 )
V_15 = & V_137 ;
#endif
return F_93 ( & V_138 ) ;
}
static void T_10 F_94 ( void )
{
F_95 ( & V_138 ) ;
}
