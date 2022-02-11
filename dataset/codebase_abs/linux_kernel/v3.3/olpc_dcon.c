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
T_4 V_7 ;
int V_8 = 0 ;
V_7 = F_3 ( V_2 , V_9 ) ;
if ( ( V_7 >> 8 ) != 0xDC ) {
F_6 ( V_10 L_1
L_2 , V_7 ) ;
V_8 = - V_11 ;
goto V_12;
}
if ( V_6 ) {
F_6 ( V_13 L_3 ,
V_7 & 0xFF ) ;
V_8 = V_14 -> V_15 ( V_2 ) ;
if ( V_8 != 0 ) {
F_6 ( V_10 L_4 ) ;
goto V_12;
}
}
if ( V_7 < 0xdc02 ) {
F_7 ( & V_2 -> V_5 -> V_16 ,
L_5 ) ;
V_8 = - V_17 ;
goto V_12;
}
F_1 ( V_2 , 0x3a , 0xc040 ) ;
F_1 ( V_2 , 0x41 , 0x0000 ) ;
F_1 ( V_2 , 0x41 , 0x0101 ) ;
F_1 ( V_2 , 0x42 , 0x0101 ) ;
if ( V_6 ) {
V_2 -> V_18 = V_19 | V_20 |
V_21 ;
if ( V_22 )
V_2 -> V_18 |= V_23 ;
}
F_1 ( V_2 , V_24 , V_2 -> V_18 ) ;
F_1 ( V_2 , V_25 , V_26 ) ;
V_12:
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , int V_27 )
{
unsigned long V_28 ;
int V_29 ;
V_30:
if ( V_27 ) {
V_29 = 1 ;
V_29 = F_9 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
if ( V_29 ) {
F_6 ( V_31 L_6
L_7 , V_29 ) ;
return V_29 ;
}
F_10 ( 10 ) ;
}
V_14 -> V_32 () ;
for ( V_29 = - 1 , V_28 = 50 ; V_28 && V_29 < 0 ; V_28 -- ) {
F_10 ( 1 ) ;
V_29 = F_3 ( V_2 , V_9 ) ;
}
if ( V_29 < 0 ) {
F_6 ( V_10 L_8
L_9 ) ;
F_11 ( F_12 ( F_13 ( 0xc2 ) ) ) ;
V_29 = 0 ;
F_9 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
F_10 ( 100 ) ;
V_27 = 1 ;
goto V_30;
}
if ( V_27 )
return F_5 ( V_2 , 0 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_33 )
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
static int F_15 ( struct V_1 * V_2 , bool V_36 )
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
static void F_16 ( struct V_1 * V_2 , bool V_39 )
{
int V_29 ;
if ( V_2 -> V_40 == V_39 )
return;
if ( ! F_12 ( F_13 ( 0xc2 ) ) )
return;
if ( V_39 ) {
V_29 = 0 ;
V_29 = F_9 ( 0x26 , ( unsigned char * ) & V_29 , 1 , NULL , 0 ) ;
if ( V_29 )
F_6 ( V_31 L_6
L_10 , V_29 ) ;
else
V_2 -> V_40 = V_39 ;
} else {
if ( V_2 -> V_34 != 0 )
V_2 -> V_18 |= V_20 ;
V_29 = F_8 ( V_2 , 1 ) ;
if ( V_29 )
F_6 ( V_31 L_11
L_12 , V_29 ) ;
else
V_2 -> V_40 = V_39 ;
F_14 ( V_2 , V_2 -> V_34 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_41 V_42 , V_43 ;
while ( 1 ) {
F_18 ( & V_43 ) ;
V_42 = F_19 ( V_43 , V_2 -> V_44 ) ;
if ( V_42 . V_45 != 0 ||
V_42 . V_46 > V_47 * 20 ) {
break;
}
F_20 ( 4 ) ;
}
}
static bool F_21 ( struct V_1 * V_2 , bool V_48 )
{
int V_12 ;
if ( ! F_22 ( V_2 -> V_49 ) ) {
F_7 ( & V_2 -> V_5 -> V_16 , L_13 ) ;
return false ;
}
F_23 () ;
V_2 -> V_50 = true ;
V_12 = F_24 ( V_2 -> V_49 ,
V_48 ? V_51 : V_52 ) ;
V_2 -> V_50 = false ;
F_25 () ;
F_26 ( V_2 -> V_49 ) ;
if ( V_12 ) {
F_7 ( & V_2 -> V_5 -> V_16 , L_14 ,
V_48 ? L_15 : L_16 ) ;
return false ;
}
return true ;
}
static void F_27 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_28 ( V_54 , struct V_1 ,
V_55 ) ;
F_29 ( V_56 , V_57 ) ;
int V_58 = V_2 -> V_59 ;
if ( V_2 -> V_60 == V_58 )
return;
F_17 ( V_2 ) ;
V_2 -> V_61 = false ;
switch ( V_58 ) {
case V_62 :
F_6 ( L_17 ) ;
if ( F_1 ( V_2 , V_24 ,
V_2 -> V_18 | V_63 ) )
F_6 ( V_10
L_18 ) ;
else {
F_30 ( V_64 ,
V_2 -> V_61 == true , V_65 ) ;
}
if ( ! V_2 -> V_61 )
F_6 ( V_10 L_19 ) ;
if ( F_1 ( V_2 , V_24 , V_2 -> V_18 ) )
F_6 ( V_10 L_20 ) ;
if ( ! F_21 ( V_2 , false ) ) {
F_6 ( V_10 L_21 ) ;
V_2 -> V_59 = V_66 ;
return;
}
V_14 -> V_67 ( 1 ) ;
F_18 ( & V_2 -> V_44 ) ;
F_6 ( V_13 L_22 ) ;
break;
case V_66 :
{
int V_68 ;
struct V_41 V_42 ;
F_6 ( V_13 L_23 ) ;
F_31 ( & V_64 , & V_56 ) ;
F_32 ( V_69 ) ;
V_14 -> V_67 ( 0 ) ;
F_18 ( & V_2 -> V_44 ) ;
V_68 = F_33 ( V_65 / 2 ) ;
F_34 ( & V_64 , & V_56 ) ;
F_32 ( V_70 ) ;
if ( ! V_2 -> V_61 ) {
F_6 ( V_10 L_24 ) ;
} else {
V_42 = F_19 ( V_2 -> V_71 , V_2 -> V_44 ) ;
if ( V_2 -> V_61 && V_42 . V_45 == 0 &&
V_42 . V_46 < V_47 * 20 ) {
F_6 ( V_10 L_25 ) ;
V_14 -> V_67 ( 1 ) ;
F_20 ( 41 ) ;
V_14 -> V_67 ( 0 ) ;
F_18 ( & V_2 -> V_44 ) ;
F_20 ( 41 ) ;
}
}
F_21 ( V_2 , true ) ;
F_6 ( V_13 L_26 ) ;
break;
}
default:
F_35 () ;
}
V_2 -> V_60 = V_58 ;
}
static void F_36 ( struct V_1 * V_2 , int V_72 )
{
if ( V_2 -> V_59 == V_72 )
return;
V_2 -> V_59 = V_72 ;
if ( ( V_2 -> V_60 != V_72 ) && ! F_37 ( & V_2 -> V_55 ) )
F_38 ( & V_2 -> V_55 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_72 )
{
F_36 ( V_2 , V_72 ) ;
F_40 () ;
}
static T_5 F_41 ( struct V_73 * V_16 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_1 * V_2 = F_42 ( V_16 ) ;
return sprintf ( V_76 , L_27 , V_2 -> V_18 ) ;
}
static T_5 F_43 ( struct V_73 * V_16 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_1 * V_2 = F_42 ( V_16 ) ;
return sprintf ( V_76 , L_28 , V_2 -> V_40 ) ;
}
static T_5 F_44 ( struct V_73 * V_16 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_1 * V_2 = F_42 ( V_16 ) ;
return sprintf ( V_76 , L_28 , V_2 -> V_60 == V_66 ? 1 : 0 ) ;
}
static T_5 F_45 ( struct V_73 * V_16 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_1 * V_2 = F_42 ( V_16 ) ;
return sprintf ( V_76 , L_28 , V_2 -> V_37 ) ;
}
static T_5 F_46 ( struct V_73 * V_16 ,
struct V_74 * V_75 , char * V_76 )
{
return sprintf ( V_76 , L_28 , V_26 ) ;
}
static T_5 F_47 ( struct V_73 * V_16 ,
struct V_74 * V_75 , const char * V_76 , T_6 V_77 )
{
unsigned long V_36 ;
int V_8 ;
V_8 = F_48 ( V_76 , 10 , & V_36 ) ;
if ( V_8 )
return V_8 ;
F_15 ( F_42 ( V_16 ) , V_36 ? true : false ) ;
return V_77 ;
}
static T_5 F_49 ( struct V_73 * V_16 ,
struct V_74 * V_75 , const char * V_76 , T_6 V_77 )
{
struct V_1 * V_2 = F_42 ( V_16 ) ;
unsigned long V_78 ;
int V_79 ;
V_79 = F_48 ( V_76 , 10 , & V_78 ) ;
if ( V_79 )
return V_79 ;
F_6 ( V_13 L_29 , V_78 ) ;
switch ( V_78 ) {
case 0 :
F_36 ( V_2 , V_62 ) ;
break;
case 1 :
F_39 ( V_2 , V_66 ) ;
break;
case 2 :
F_36 ( V_2 , V_66 ) ;
break;
default:
return - V_80 ;
}
return V_77 ;
}
static T_5 F_50 ( struct V_73 * V_16 ,
struct V_74 * V_75 , const char * V_76 , T_6 V_77 )
{
unsigned short V_81 ;
int V_8 ;
V_8 = F_51 ( V_76 , 10 , & V_81 ) ;
if ( V_8 )
return V_8 ;
V_26 = V_81 ;
F_1 ( F_42 ( V_16 ) , V_25 , V_26 ) ;
return V_77 ;
}
static T_5 F_52 ( struct V_73 * V_16 ,
struct V_74 * V_75 , const char * V_76 , T_6 V_77 )
{
unsigned long V_78 ;
int V_79 ;
V_79 = F_48 ( V_76 , 10 , & V_78 ) ;
if ( V_79 )
return V_79 ;
F_16 ( F_42 ( V_16 ) , V_78 ? true : false ) ;
return V_77 ;
}
static int F_53 ( struct V_82 * V_16 )
{
struct V_1 * V_2 = F_54 ( V_16 ) ;
T_2 V_33 = V_16 -> V_83 . V_84 & 0x0F ;
if ( V_16 -> V_83 . V_85 != V_52 )
V_33 = 0 ;
if ( V_33 != V_2 -> V_34 )
F_14 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_55 ( struct V_82 * V_16 )
{
struct V_1 * V_2 = F_54 ( V_16 ) ;
return V_2 -> V_34 ;
}
static int F_56 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_1 * V_2 = F_28 ( V_87 , struct V_1 , V_90 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return 0 ;
F_1 ( V_2 , V_24 , 0x39 ) ;
F_1 ( V_2 , V_24 , 0x32 ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_87 ,
unsigned long V_91 , void * V_92 )
{
V_14 -> V_67 ( 1 ) ;
return V_93 ;
}
static int F_58 ( struct V_86 * V_94 ,
unsigned long V_95 , void * V_96 )
{
struct V_97 * V_98 = V_96 ;
struct V_1 * V_2 = F_28 ( V_94 , struct V_1 ,
V_99 ) ;
int * V_48 = ( int * ) V_98 -> V_96 ;
if ( ( ( V_95 != V_100 ) && ( V_95 != V_101 ) ) ||
V_2 -> V_50 )
return 0 ;
F_16 ( V_2 , * V_48 ? true : false ) ;
return 0 ;
}
static int F_59 ( struct V_102 * V_5 , struct V_103 * V_104 )
{
F_60 ( V_104 -> type , L_30 , V_105 ) ;
return 0 ;
}
static int F_61 ( struct V_102 * V_5 , const struct V_106 * V_107 )
{
struct V_1 * V_2 ;
int V_8 , V_108 , V_109 ;
if ( ! V_14 )
return - V_11 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_5 = V_5 ;
F_63 ( & V_2 -> V_55 , F_27 ) ;
V_2 -> V_90 . V_112 = F_56 ;
V_2 -> V_90 . V_113 = - 1 ;
V_2 -> V_99 . V_112 = F_58 ;
F_64 ( V_5 , V_2 ) ;
if ( V_114 < 1 ) {
F_7 ( & V_5 -> V_16 , L_31 ) ;
V_8 = - V_115 ;
goto V_116;
}
V_2 -> V_49 = V_117 [ 0 ] ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( V_8 )
goto V_116;
V_118 = F_65 ( L_32 , - 1 ) ;
if ( V_118 == NULL ) {
F_6 ( V_10 L_33 ) ;
V_8 = - V_111 ;
goto V_119;
}
V_8 = F_66 ( V_118 ) ;
F_67 ( V_118 , V_2 ) ;
if ( V_8 ) {
F_6 ( V_10 L_34 ) ;
goto V_120;
}
for ( V_108 = 0 ; V_108 < F_68 ( V_121 ) ; V_108 ++ ) {
V_8 = F_69 ( & V_118 -> V_16 ,
& V_121 [ V_108 ] ) ;
if ( V_8 ) {
F_7 ( & V_118 -> V_16 , L_35 ) ;
goto V_122;
}
}
V_2 -> V_34 = F_3 ( V_2 , V_35 ) & 0x0F ;
V_123 . V_84 = V_2 -> V_34 ;
V_2 -> V_124 = F_70 ( L_36 , & V_118 -> V_16 ,
V_2 , & V_125 , & V_123 ) ;
if ( F_71 ( V_2 -> V_124 ) ) {
F_7 ( & V_5 -> V_16 , L_37 ,
F_72 ( V_2 -> V_124 ) ) ;
V_2 -> V_124 = NULL ;
}
F_73 ( & V_2 -> V_90 ) ;
F_74 ( & V_126 , & V_127 ) ;
F_75 ( & V_2 -> V_99 ) ;
return 0 ;
V_122:
for ( V_109 = 0 ; V_109 < V_108 ; V_109 ++ )
F_76 ( & V_118 -> V_16 , & V_121 [ V_109 ] ) ;
V_120:
F_77 ( V_118 ) ;
V_118 = NULL ;
V_119:
F_78 ( V_128 , V_2 ) ;
V_116:
F_79 ( V_2 ) ;
return V_8 ;
}
static int F_80 ( struct V_102 * V_5 )
{
struct V_1 * V_2 = F_81 ( V_5 ) ;
F_82 ( & V_2 -> V_99 ) ;
F_83 ( & V_2 -> V_90 ) ;
F_84 ( & V_126 , & V_127 ) ;
F_78 ( V_128 , V_2 ) ;
if ( V_2 -> V_124 )
F_85 ( V_2 -> V_124 ) ;
if ( V_118 != NULL )
F_77 ( V_118 ) ;
F_86 ( & V_2 -> V_55 ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_102 * V_5 , T_7 V_129 )
{
struct V_1 * V_2 = F_81 ( V_5 ) ;
if ( ! V_2 -> V_40 ) {
F_39 ( V_2 , V_66 ) ;
}
return 0 ;
}
static int F_88 ( struct V_102 * V_5 )
{
struct V_1 * V_2 = F_81 ( V_5 ) ;
if ( ! V_2 -> V_40 ) {
F_8 ( V_2 , 0 ) ;
F_36 ( V_2 , V_62 ) ;
}
return 0 ;
}
T_8 F_89 ( int V_130 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
T_2 V_131 ;
if ( V_14 -> V_132 ( & V_131 ) )
return V_133 ;
switch ( V_131 & 3 ) {
case 3 :
F_6 ( V_134 L_38 ) ;
break;
case 2 :
case 1 :
V_2 -> V_61 = true ;
F_18 ( & V_2 -> V_71 ) ;
F_90 ( & V_64 ) ;
break;
case 0 :
if ( V_2 -> V_60 != V_2 -> V_59 && ! V_2 -> V_61 ) {
V_2 -> V_61 = true ;
F_18 ( & V_2 -> V_71 ) ;
F_90 ( & V_64 ) ;
F_6 ( V_134 L_39 ) ;
} else {
F_6 ( V_134 L_40 ) ;
}
}
return V_135 ;
}
static int T_9 F_91 ( void )
{
#ifdef F_92
if ( F_12 ( F_13 ( 0xd0 ) ) )
V_14 = & V_136 ;
#endif
#ifdef F_93
if ( ! V_14 )
V_14 = & V_137 ;
#endif
return F_94 ( & V_138 ) ;
}
static void T_10 F_95 ( void )
{
F_96 ( & V_138 ) ;
}
