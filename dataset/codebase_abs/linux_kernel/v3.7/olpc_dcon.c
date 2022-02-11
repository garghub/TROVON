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
F_6 ( L_1 , V_7 ) ;
V_8 = - V_10 ;
goto V_11;
}
if ( V_6 ) {
F_7 ( L_2 , V_7 & 0xFF ) ;
V_8 = V_12 -> V_13 ( V_2 ) ;
if ( V_8 != 0 ) {
F_6 ( L_3 ) ;
goto V_11;
}
}
if ( V_7 < 0xdc02 ) {
F_8 ( & V_2 -> V_5 -> V_14 ,
L_4 ) ;
V_8 = - V_15 ;
goto V_11;
}
F_1 ( V_2 , 0x3a , 0xc040 ) ;
F_1 ( V_2 , 0x41 , 0x0000 ) ;
F_1 ( V_2 , 0x41 , 0x0101 ) ;
F_1 ( V_2 , 0x42 , 0x0101 ) ;
if ( V_6 ) {
V_2 -> V_16 = V_17 | V_18 |
V_19 ;
if ( V_20 )
V_2 -> V_16 |= V_21 ;
}
F_1 ( V_2 , V_22 , V_2 -> V_16 ) ;
F_1 ( V_2 , V_23 , V_24 ) ;
V_11:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_25 )
{
unsigned long V_26 ;
int V_27 ;
V_28:
if ( V_25 ) {
V_27 = 1 ;
V_27 = F_10 ( 0x26 , ( unsigned char * ) & V_27 , 1 , NULL , 0 ) ;
if ( V_27 ) {
F_11 ( L_5 , V_27 ) ;
return V_27 ;
}
F_12 ( 10 ) ;
}
V_12 -> V_29 () ;
for ( V_27 = - 1 , V_26 = 50 ; V_26 && V_27 < 0 ; V_26 -- ) {
F_12 ( 1 ) ;
V_27 = F_3 ( V_2 , V_9 ) ;
}
if ( V_27 < 0 ) {
F_6 ( L_6 ) ;
F_13 ( F_14 ( F_15 ( 0xc2 ) ) ) ;
V_27 = 0 ;
F_10 ( 0x26 , ( unsigned char * ) & V_27 , 1 , NULL , 0 ) ;
F_12 ( 100 ) ;
V_25 = 1 ;
goto V_28;
}
if ( V_25 )
return F_5 ( V_2 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_30 )
{
V_2 -> V_31 = V_30 ;
F_1 ( V_2 , V_32 , V_2 -> V_31 ) ;
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_16 &= ~ V_18 ;
F_1 ( V_2 , V_22 , V_2 -> V_16 ) ;
} else if ( ! ( V_2 -> V_16 & V_18 ) ) {
V_2 -> V_16 |= V_18 ;
F_1 ( V_2 , V_22 , V_2 -> V_16 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , bool V_33 )
{
if ( V_2 -> V_34 == V_33 )
return 0 ;
V_2 -> V_34 = V_33 ;
if ( V_33 ) {
V_2 -> V_16 &= ~ ( V_19 | V_21 ) ;
V_2 -> V_16 |= V_35 ;
} else {
V_2 -> V_16 &= ~ ( V_35 ) ;
V_2 -> V_16 |= V_19 ;
if ( V_20 )
V_2 -> V_16 |= V_21 ;
}
F_1 ( V_2 , V_22 , V_2 -> V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , bool V_36 )
{
int V_27 ;
if ( V_2 -> V_37 == V_36 )
return;
if ( ! F_14 ( F_15 ( 0xc2 ) ) )
return;
if ( V_36 ) {
V_27 = 0 ;
V_27 = F_10 ( 0x26 , ( unsigned char * ) & V_27 , 1 , NULL , 0 ) ;
if ( V_27 )
F_11 ( L_7 , V_27 ) ;
else
V_2 -> V_37 = V_36 ;
} else {
if ( V_2 -> V_31 != 0 )
V_2 -> V_16 |= V_18 ;
V_27 = F_9 ( V_2 , 1 ) ;
if ( V_27 )
F_11 ( L_8 , V_27 ) ;
else
V_2 -> V_37 = V_36 ;
F_16 ( V_2 , V_2 -> V_31 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_38 V_39 , V_40 ;
while ( 1 ) {
F_20 ( & V_40 ) ;
V_39 = F_21 ( V_40 , V_2 -> V_41 ) ;
if ( V_39 . V_42 != 0 ||
V_39 . V_43 > V_44 * 20 ) {
break;
}
F_22 ( 4 ) ;
}
}
static bool F_23 ( struct V_1 * V_2 , bool V_45 )
{
int V_11 ;
if ( ! F_24 ( V_2 -> V_46 ) ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_9 ) ;
return false ;
}
F_25 () ;
V_2 -> V_47 = true ;
V_11 = F_26 ( V_2 -> V_46 ,
V_45 ? V_48 : V_49 ) ;
V_2 -> V_47 = false ;
F_27 () ;
F_28 ( V_2 -> V_46 ) ;
if ( V_11 ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_10 ,
V_45 ? L_11 : L_12 ) ;
return false ;
}
return true ;
}
static void F_29 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_30 ( V_51 , struct V_1 ,
V_52 ) ;
F_31 ( V_53 , V_54 ) ;
int V_55 = V_2 -> V_56 ;
if ( V_2 -> V_57 == V_55 )
return;
F_19 ( V_2 ) ;
V_2 -> V_58 = false ;
switch ( V_55 ) {
case V_59 :
F_7 ( L_13 ) ;
if ( F_1 ( V_2 , V_22 ,
V_2 -> V_16 | V_60 ) )
F_6 ( L_14 ) ;
else {
F_32 ( V_61 ,
V_2 -> V_58 == true , V_62 ) ;
}
if ( ! V_2 -> V_58 )
F_6 ( L_15 ) ;
if ( F_1 ( V_2 , V_22 , V_2 -> V_16 ) )
F_6 ( L_16 ) ;
if ( ! F_23 ( V_2 , false ) ) {
F_6 ( L_17 ) ;
V_2 -> V_56 = V_63 ;
return;
}
V_12 -> V_64 ( 1 ) ;
F_20 ( & V_2 -> V_41 ) ;
F_7 ( L_18 ) ;
break;
case V_63 :
{
int V_65 ;
struct V_38 V_39 ;
F_7 ( L_19 ) ;
F_33 ( & V_61 , & V_53 ) ;
F_34 ( V_66 ) ;
V_12 -> V_64 ( 0 ) ;
F_20 ( & V_2 -> V_41 ) ;
V_65 = F_35 ( V_62 / 2 ) ;
F_36 ( & V_61 , & V_53 ) ;
F_34 ( V_67 ) ;
if ( ! V_2 -> V_58 ) {
F_6 ( L_20 ) ;
} else {
V_39 = F_21 ( V_2 -> V_68 , V_2 -> V_41 ) ;
if ( V_2 -> V_58 && V_39 . V_42 == 0 &&
V_39 . V_43 < V_44 * 20 ) {
F_6 ( L_21 ) ;
V_12 -> V_64 ( 1 ) ;
F_22 ( 41 ) ;
V_12 -> V_64 ( 0 ) ;
F_20 ( & V_2 -> V_41 ) ;
F_22 ( 41 ) ;
}
}
F_23 ( V_2 , true ) ;
F_7 ( L_22 ) ;
break;
}
default:
F_37 () ;
}
V_2 -> V_57 = V_55 ;
}
static void F_38 ( struct V_1 * V_2 , int V_69 )
{
if ( V_2 -> V_56 == V_69 )
return;
V_2 -> V_56 = V_69 ;
if ( ( V_2 -> V_57 != V_69 ) && ! F_39 ( & V_2 -> V_52 ) )
F_40 ( & V_2 -> V_52 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_69 )
{
F_38 ( V_2 , V_69 ) ;
F_42 () ;
}
static T_5 F_43 ( struct V_70 * V_14 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
return sprintf ( V_73 , L_23 , V_2 -> V_16 ) ;
}
static T_5 F_45 ( struct V_70 * V_14 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
return sprintf ( V_73 , L_24 , V_2 -> V_37 ) ;
}
static T_5 F_46 ( struct V_70 * V_14 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
return sprintf ( V_73 , L_24 , V_2 -> V_57 == V_63 ? 1 : 0 ) ;
}
static T_5 F_47 ( struct V_70 * V_14 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
return sprintf ( V_73 , L_24 , V_2 -> V_34 ) ;
}
static T_5 F_48 ( struct V_70 * V_14 ,
struct V_71 * V_72 , char * V_73 )
{
return sprintf ( V_73 , L_24 , V_24 ) ;
}
static T_5 F_49 ( struct V_70 * V_14 ,
struct V_71 * V_72 , const char * V_73 , T_6 V_74 )
{
unsigned long V_33 ;
int V_8 ;
V_8 = F_50 ( V_73 , 10 , & V_33 ) ;
if ( V_8 )
return V_8 ;
F_17 ( F_44 ( V_14 ) , V_33 ? true : false ) ;
return V_74 ;
}
static T_5 F_51 ( struct V_70 * V_14 ,
struct V_71 * V_72 , const char * V_73 , T_6 V_74 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
unsigned long V_75 ;
int V_76 ;
V_76 = F_50 ( V_73 , 10 , & V_75 ) ;
if ( V_76 )
return V_76 ;
F_7 ( L_25 , V_75 ) ;
switch ( V_75 ) {
case 0 :
F_38 ( V_2 , V_59 ) ;
break;
case 1 :
F_41 ( V_2 , V_63 ) ;
break;
case 2 :
F_38 ( V_2 , V_63 ) ;
break;
default:
return - V_77 ;
}
return V_74 ;
}
static T_5 F_52 ( struct V_70 * V_14 ,
struct V_71 * V_72 , const char * V_73 , T_6 V_74 )
{
unsigned short V_78 ;
int V_8 ;
V_8 = F_53 ( V_73 , 10 , & V_78 ) ;
if ( V_8 )
return V_8 ;
V_24 = V_78 ;
F_1 ( F_44 ( V_14 ) , V_23 , V_24 ) ;
return V_74 ;
}
static T_5 F_54 ( struct V_70 * V_14 ,
struct V_71 * V_72 , const char * V_73 , T_6 V_74 )
{
unsigned long V_75 ;
int V_76 ;
V_76 = F_50 ( V_73 , 10 , & V_75 ) ;
if ( V_76 )
return V_76 ;
F_18 ( F_44 ( V_14 ) , V_75 ? true : false ) ;
return V_74 ;
}
static int F_55 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_56 ( V_14 ) ;
T_2 V_30 = V_14 -> V_80 . V_81 & 0x0F ;
if ( V_14 -> V_80 . V_82 != V_49 )
V_30 = 0 ;
if ( V_30 != V_2 -> V_31 )
F_16 ( V_2 , V_30 ) ;
return 0 ;
}
static int F_57 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_56 ( V_14 ) ;
return V_2 -> V_31 ;
}
static int F_58 ( struct V_83 * V_84 ,
unsigned long V_85 , void * V_86 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 , V_87 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return 0 ;
F_1 ( V_2 , V_22 , 0x39 ) ;
F_1 ( V_2 , V_22 , 0x32 ) ;
return 0 ;
}
static int F_59 ( struct V_83 * V_84 ,
unsigned long V_88 , void * V_89 )
{
V_12 -> V_64 ( 1 ) ;
return V_90 ;
}
static int F_60 ( struct V_83 * V_91 ,
unsigned long V_92 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_1 * V_2 = F_30 ( V_91 , struct V_1 ,
V_96 ) ;
int * V_45 = ( int * ) V_95 -> V_93 ;
if ( ( ( V_92 != V_97 ) && ( V_92 != V_98 ) ) ||
V_2 -> V_47 )
return 0 ;
F_18 ( V_2 , * V_45 ? true : false ) ;
return 0 ;
}
static int F_61 ( struct V_99 * V_5 , struct V_100 * V_101 )
{
F_62 ( V_101 -> type , L_26 , V_102 ) ;
return 0 ;
}
static int F_63 ( struct V_99 * V_5 , const struct V_103 * V_104 )
{
struct V_1 * V_2 ;
int V_8 , V_105 , V_106 ;
if ( ! V_12 )
return - V_10 ;
V_2 = F_64 ( sizeof( * V_2 ) , V_107 ) ;
if ( ! V_2 )
return - V_108 ;
V_2 -> V_5 = V_5 ;
F_65 ( & V_2 -> V_52 , F_29 ) ;
V_2 -> V_87 . V_109 = F_58 ;
V_2 -> V_87 . V_110 = - 1 ;
V_2 -> V_96 . V_109 = F_60 ;
F_66 ( V_5 , V_2 ) ;
if ( V_111 < 1 ) {
F_8 ( & V_5 -> V_14 , L_27 ) ;
V_8 = - V_112 ;
goto V_113;
}
V_2 -> V_46 = V_114 [ 0 ] ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( V_8 )
goto V_113;
V_115 = F_67 ( L_28 , - 1 ) ;
if ( V_115 == NULL ) {
F_6 ( L_29 ) ;
V_8 = - V_108 ;
goto V_116;
}
V_8 = F_68 ( V_115 ) ;
F_69 ( V_115 , V_2 ) ;
if ( V_8 ) {
F_6 ( L_30 ) ;
goto V_117;
}
for ( V_105 = 0 ; V_105 < F_70 ( V_118 ) ; V_105 ++ ) {
V_8 = F_71 ( & V_115 -> V_14 ,
& V_118 [ V_105 ] ) ;
if ( V_8 ) {
F_8 ( & V_115 -> V_14 , L_31 ) ;
goto V_119;
}
}
V_2 -> V_31 = F_3 ( V_2 , V_32 ) & 0x0F ;
V_120 . V_81 = V_2 -> V_31 ;
V_2 -> V_121 = F_72 ( L_32 , & V_115 -> V_14 ,
V_2 , & V_122 , & V_120 ) ;
if ( F_73 ( V_2 -> V_121 ) ) {
F_8 ( & V_5 -> V_14 , L_33 ,
F_74 ( V_2 -> V_121 ) ) ;
V_2 -> V_121 = NULL ;
}
F_75 ( & V_2 -> V_87 ) ;
F_76 ( & V_123 , & V_124 ) ;
F_77 ( & V_2 -> V_96 ) ;
return 0 ;
V_119:
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ )
F_78 ( & V_115 -> V_14 , & V_118 [ V_106 ] ) ;
V_117:
F_79 ( V_115 ) ;
V_115 = NULL ;
V_116:
F_80 ( V_125 , V_2 ) ;
V_113:
F_81 ( V_2 ) ;
return V_8 ;
}
static int F_82 ( struct V_99 * V_5 )
{
struct V_1 * V_2 = F_83 ( V_5 ) ;
F_84 ( & V_2 -> V_96 ) ;
F_85 ( & V_2 -> V_87 ) ;
F_86 ( & V_123 , & V_124 ) ;
F_80 ( V_125 , V_2 ) ;
if ( V_2 -> V_121 )
F_87 ( V_2 -> V_121 ) ;
if ( V_115 != NULL )
F_79 ( V_115 ) ;
F_88 ( & V_2 -> V_52 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_99 * V_5 , T_7 V_126 )
{
struct V_1 * V_2 = F_83 ( V_5 ) ;
if ( ! V_2 -> V_37 ) {
F_41 ( V_2 , V_63 ) ;
}
return 0 ;
}
static int F_90 ( struct V_99 * V_5 )
{
struct V_1 * V_2 = F_83 ( V_5 ) ;
if ( ! V_2 -> V_37 ) {
F_9 ( V_2 , 0 ) ;
F_38 ( V_2 , V_59 ) ;
}
return 0 ;
}
T_8 F_91 ( int V_127 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
T_2 V_128 ;
if ( V_12 -> V_129 ( & V_128 ) )
return V_130 ;
switch ( V_128 & 3 ) {
case 3 :
F_92 ( L_34 ) ;
break;
case 2 :
case 1 :
V_2 -> V_58 = true ;
F_20 ( & V_2 -> V_68 ) ;
F_93 ( & V_61 ) ;
break;
case 0 :
if ( V_2 -> V_57 != V_2 -> V_56 && ! V_2 -> V_58 ) {
V_2 -> V_58 = true ;
F_20 ( & V_2 -> V_68 ) ;
F_93 ( & V_61 ) ;
F_92 ( L_35 ) ;
} else {
F_92 ( L_36 ) ;
}
}
return V_131 ;
}
static int T_9 F_94 ( void )
{
#ifdef F_95
if ( F_14 ( F_15 ( 0xd0 ) ) )
V_12 = & V_132 ;
#endif
#ifdef F_96
if ( ! V_12 )
V_12 = & V_133 ;
#endif
return F_97 ( & V_134 ) ;
}
static void T_10 F_98 ( void )
{
F_99 ( & V_134 ) ;
}
