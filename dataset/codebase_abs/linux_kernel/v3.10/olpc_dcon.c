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
V_19 | V_20 ;
}
F_1 ( V_2 , V_21 , V_2 -> V_16 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
V_11:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_24 )
{
unsigned long V_25 ;
int V_26 ;
V_27:
if ( V_24 ) {
V_26 = 1 ;
V_26 = F_10 ( 0x26 , ( unsigned char * ) & V_26 , 1 , NULL , 0 ) ;
if ( V_26 ) {
F_11 ( L_5 , V_26 ) ;
return V_26 ;
}
F_12 ( 10 ) ;
}
V_12 -> V_28 () ;
for ( V_26 = - 1 , V_25 = 50 ; V_25 && V_26 < 0 ; V_25 -- ) {
F_12 ( 1 ) ;
V_26 = F_3 ( V_2 , V_9 ) ;
}
if ( V_26 < 0 ) {
F_6 ( L_6 ) ;
F_13 ( F_14 ( F_15 ( 0xc2 ) ) ) ;
V_26 = 0 ;
F_10 ( 0x26 , ( unsigned char * ) & V_26 , 1 , NULL , 0 ) ;
F_12 ( 100 ) ;
V_24 = 1 ;
goto V_27;
}
if ( V_24 )
return F_5 ( V_2 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_29 )
{
V_2 -> V_30 = V_29 ;
F_1 ( V_2 , V_31 , V_2 -> V_30 ) ;
if ( V_2 -> V_30 == 0 ) {
V_2 -> V_16 &= ~ V_18 ;
F_1 ( V_2 , V_21 , V_2 -> V_16 ) ;
} else if ( ! ( V_2 -> V_16 & V_18 ) ) {
V_2 -> V_16 |= V_18 ;
F_1 ( V_2 , V_21 , V_2 -> V_16 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , bool V_32 )
{
if ( V_2 -> V_33 == V_32 )
return 0 ;
V_2 -> V_33 = V_32 ;
if ( V_32 ) {
V_2 -> V_16 &= ~ ( V_19 | V_20 ) ;
V_2 -> V_16 |= V_34 ;
} else {
V_2 -> V_16 &= ~ ( V_34 ) ;
V_2 -> V_16 |= V_19 | V_20 ;
}
F_1 ( V_2 , V_21 , V_2 -> V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , bool V_35 )
{
int V_26 ;
if ( V_2 -> V_36 == V_35 )
return;
if ( ! F_14 ( F_15 ( 0xc2 ) ) )
return;
if ( V_35 ) {
V_26 = 0 ;
V_26 = F_10 ( 0x26 , ( unsigned char * ) & V_26 , 1 , NULL , 0 ) ;
if ( V_26 )
F_11 ( L_7 , V_26 ) ;
else
V_2 -> V_36 = V_35 ;
} else {
if ( V_2 -> V_30 != 0 )
V_2 -> V_16 |= V_18 ;
V_26 = F_9 ( V_2 , 1 ) ;
if ( V_26 )
F_11 ( L_8 , V_26 ) ;
else
V_2 -> V_36 = V_35 ;
F_16 ( V_2 , V_2 -> V_30 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_37 V_38 , V_39 ;
while ( 1 ) {
F_20 ( & V_39 ) ;
V_38 = F_21 ( V_39 , V_2 -> V_40 ) ;
if ( V_38 . V_41 != 0 ||
V_38 . V_42 > V_43 * 20 ) {
break;
}
F_22 ( 4 ) ;
}
}
static bool F_23 ( struct V_1 * V_2 , bool V_44 )
{
int V_11 ;
if ( ! F_24 ( V_2 -> V_45 ) ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_9 ) ;
return false ;
}
F_25 () ;
V_2 -> V_46 = true ;
V_11 = F_26 ( V_2 -> V_45 ,
V_44 ? V_47 : V_48 ) ;
V_2 -> V_46 = false ;
F_27 () ;
F_28 ( V_2 -> V_45 ) ;
if ( V_11 ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_10 ,
V_44 ? L_11 : L_12 ) ;
return false ;
}
return true ;
}
static void F_29 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 , struct V_1 ,
V_51 ) ;
int V_52 = V_2 -> V_53 ;
if ( V_2 -> V_54 == V_52 )
return;
F_19 ( V_2 ) ;
V_2 -> V_55 = false ;
switch ( V_52 ) {
case V_56 :
F_7 ( L_13 ) ;
if ( F_1 ( V_2 , V_21 ,
V_2 -> V_16 | V_57 ) )
F_6 ( L_14 ) ;
else
F_31 ( V_2 -> V_58 , V_2 -> V_55 , V_59 ) ;
if ( ! V_2 -> V_55 )
F_6 ( L_15 ) ;
if ( F_1 ( V_2 , V_21 , V_2 -> V_16 ) )
F_6 ( L_16 ) ;
if ( ! F_23 ( V_2 , false ) ) {
F_6 ( L_17 ) ;
V_2 -> V_53 = V_60 ;
return;
}
V_12 -> V_61 ( 1 ) ;
F_20 ( & V_2 -> V_40 ) ;
F_7 ( L_18 ) ;
break;
case V_60 :
{
struct V_37 V_38 ;
F_7 ( L_19 ) ;
V_12 -> V_61 ( 0 ) ;
F_20 ( & V_2 -> V_40 ) ;
F_31 ( V_2 -> V_58 , V_2 -> V_55 , V_59 / 2 ) ;
if ( ! V_2 -> V_55 ) {
F_6 ( L_20 ) ;
} else {
V_38 = F_21 ( V_2 -> V_62 , V_2 -> V_40 ) ;
if ( V_2 -> V_55 && V_38 . V_41 == 0 &&
V_38 . V_42 < V_43 * 20 ) {
F_6 ( L_21 ) ;
V_12 -> V_61 ( 1 ) ;
F_22 ( 41 ) ;
V_12 -> V_61 ( 0 ) ;
F_20 ( & V_2 -> V_40 ) ;
F_22 ( 41 ) ;
}
}
F_23 ( V_2 , true ) ;
F_7 ( L_22 ) ;
break;
}
default:
F_32 () ;
}
V_2 -> V_54 = V_52 ;
}
static void F_33 ( struct V_1 * V_2 , int V_63 )
{
if ( V_2 -> V_53 == V_63 )
return;
V_2 -> V_53 = V_63 ;
if ( ( V_2 -> V_54 != V_63 ) && ! F_34 ( & V_2 -> V_51 ) )
F_35 ( & V_2 -> V_51 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_63 )
{
F_33 ( V_2 , V_63 ) ;
F_37 () ;
}
static T_5 F_38 ( struct V_64 * V_14 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_67 , L_23 , V_2 -> V_16 ) ;
}
static T_5 F_40 ( struct V_64 * V_14 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_67 , L_24 , V_2 -> V_36 ) ;
}
static T_5 F_41 ( struct V_64 * V_14 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_67 , L_24 , V_2 -> V_54 == V_60 ? 1 : 0 ) ;
}
static T_5 F_42 ( struct V_64 * V_14 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_67 , L_24 , V_2 -> V_33 ) ;
}
static T_5 F_43 ( struct V_64 * V_14 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_24 , V_23 ) ;
}
static T_5 F_44 ( struct V_64 * V_14 ,
struct V_65 * V_66 , const char * V_67 , T_6 V_68 )
{
unsigned long V_32 ;
int V_8 ;
V_8 = F_45 ( V_67 , 10 , & V_32 ) ;
if ( V_8 )
return V_8 ;
F_17 ( F_39 ( V_14 ) , V_32 ? true : false ) ;
return V_68 ;
}
static T_5 F_46 ( struct V_64 * V_14 ,
struct V_65 * V_66 , const char * V_67 , T_6 V_68 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
unsigned long V_69 ;
int V_70 ;
V_70 = F_45 ( V_67 , 10 , & V_69 ) ;
if ( V_70 )
return V_70 ;
F_7 ( L_25 , V_69 ) ;
switch ( V_69 ) {
case 0 :
F_33 ( V_2 , V_56 ) ;
break;
case 1 :
F_36 ( V_2 , V_60 ) ;
break;
case 2 :
F_33 ( V_2 , V_60 ) ;
break;
default:
return - V_71 ;
}
return V_68 ;
}
static T_5 F_47 ( struct V_64 * V_14 ,
struct V_65 * V_66 , const char * V_67 , T_6 V_68 )
{
unsigned short V_72 ;
int V_8 ;
V_8 = F_48 ( V_67 , 10 , & V_72 ) ;
if ( V_8 )
return V_8 ;
V_23 = V_72 ;
F_1 ( F_39 ( V_14 ) , V_22 , V_23 ) ;
return V_68 ;
}
static T_5 F_49 ( struct V_64 * V_14 ,
struct V_65 * V_66 , const char * V_67 , T_6 V_68 )
{
unsigned long V_69 ;
int V_70 ;
V_70 = F_45 ( V_67 , 10 , & V_69 ) ;
if ( V_70 )
return V_70 ;
F_18 ( F_39 ( V_14 ) , V_69 ? true : false ) ;
return V_68 ;
}
static int F_50 ( struct V_73 * V_14 )
{
struct V_1 * V_2 = F_51 ( V_14 ) ;
T_2 V_29 = V_14 -> V_74 . V_75 & 0x0F ;
if ( V_14 -> V_74 . V_76 != V_48 )
V_29 = 0 ;
if ( V_29 != V_2 -> V_30 )
F_16 ( V_2 , V_29 ) ;
if ( ! V_2 -> V_46 )
F_18 ( V_2 , ! ! ( V_14 -> V_74 . V_77 & V_78 ) ) ;
return 0 ;
}
static int F_52 ( struct V_73 * V_14 )
{
struct V_1 * V_2 = F_51 ( V_14 ) ;
return V_2 -> V_30 ;
}
static int F_53 ( struct V_79 * V_80 ,
unsigned long V_81 , void * V_82 )
{
struct V_1 * V_2 = F_30 ( V_80 , struct V_1 , V_83 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return V_84 ;
F_1 ( V_2 , V_21 , 0x39 ) ;
F_1 ( V_2 , V_21 , 0x32 ) ;
return V_84 ;
}
static int F_54 ( struct V_79 * V_80 ,
unsigned long V_85 , void * V_86 )
{
V_12 -> V_61 ( 1 ) ;
return V_84 ;
}
static int F_55 ( struct V_87 * V_5 , struct V_88 * V_89 )
{
F_56 ( V_89 -> type , L_26 , V_90 ) ;
return 0 ;
}
static int F_57 ( struct V_87 * V_5 , const struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_8 , V_93 , V_94 ;
if ( ! V_12 )
return - V_10 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_5 = V_5 ;
F_59 ( & V_2 -> V_58 ) ;
F_60 ( & V_2 -> V_51 , F_29 ) ;
V_2 -> V_83 . V_97 = F_53 ;
V_2 -> V_83 . V_98 = - 1 ;
F_61 ( V_5 , V_2 ) ;
if ( V_99 < 1 ) {
F_8 ( & V_5 -> V_14 , L_27 ) ;
V_8 = - V_100 ;
goto V_101;
}
V_2 -> V_45 = V_102 [ 0 ] ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( V_8 )
goto V_101;
V_103 = F_62 ( L_28 , - 1 ) ;
if ( V_103 == NULL ) {
F_6 ( L_29 ) ;
V_8 = - V_96 ;
goto V_104;
}
V_8 = F_63 ( V_103 ) ;
F_64 ( V_103 , V_2 ) ;
if ( V_8 ) {
F_6 ( L_30 ) ;
goto V_105;
}
for ( V_93 = 0 ; V_93 < F_65 ( V_106 ) ; V_93 ++ ) {
V_8 = F_66 ( & V_103 -> V_14 ,
& V_106 [ V_93 ] ) ;
if ( V_8 ) {
F_8 ( & V_103 -> V_14 , L_31 ) ;
goto V_107;
}
}
V_2 -> V_30 = F_3 ( V_2 , V_31 ) & 0x0F ;
V_108 . V_75 = V_2 -> V_30 ;
V_2 -> V_109 = F_67 ( L_32 , & V_103 -> V_14 ,
V_2 , & V_110 , & V_108 ) ;
if ( F_68 ( V_2 -> V_109 ) ) {
F_8 ( & V_5 -> V_14 , L_33 ,
F_69 ( V_2 -> V_109 ) ) ;
V_2 -> V_109 = NULL ;
}
F_70 ( & V_2 -> V_83 ) ;
F_71 ( & V_111 , & V_112 ) ;
return 0 ;
V_107:
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ )
F_72 ( & V_103 -> V_14 , & V_106 [ V_94 ] ) ;
V_105:
F_73 ( V_103 ) ;
V_103 = NULL ;
V_104:
F_74 ( V_113 , V_2 ) ;
V_101:
F_75 ( V_2 ) ;
return V_8 ;
}
static int F_76 ( struct V_87 * V_5 )
{
struct V_1 * V_2 = F_77 ( V_5 ) ;
F_78 ( & V_2 -> V_83 ) ;
F_79 ( & V_111 , & V_112 ) ;
F_74 ( V_113 , V_2 ) ;
if ( V_2 -> V_109 )
F_80 ( V_2 -> V_109 ) ;
if ( V_103 != NULL )
F_73 ( V_103 ) ;
F_81 ( & V_2 -> V_51 ) ;
F_75 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_64 * V_14 )
{
struct V_87 * V_5 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_77 ( V_5 ) ;
if ( ! V_2 -> V_36 ) {
F_36 ( V_2 , V_60 ) ;
}
return 0 ;
}
static int F_84 ( struct V_64 * V_14 )
{
struct V_87 * V_5 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_77 ( V_5 ) ;
if ( ! V_2 -> V_36 ) {
F_9 ( V_2 , 0 ) ;
F_33 ( V_2 , V_56 ) ;
}
return 0 ;
}
T_7 F_85 ( int V_114 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
T_2 V_115 ;
if ( V_12 -> V_116 ( & V_115 ) )
return V_117 ;
switch ( V_115 & 3 ) {
case 3 :
F_86 ( L_34 ) ;
break;
case 2 :
case 1 :
V_2 -> V_55 = true ;
F_20 ( & V_2 -> V_62 ) ;
F_87 ( & V_2 -> V_58 ) ;
break;
case 0 :
if ( V_2 -> V_54 != V_2 -> V_53 && ! V_2 -> V_55 ) {
V_2 -> V_55 = true ;
F_20 ( & V_2 -> V_62 ) ;
F_87 ( & V_2 -> V_58 ) ;
F_86 ( L_35 ) ;
} else {
F_86 ( L_36 ) ;
}
}
return V_118 ;
}
static int T_8 F_88 ( void )
{
#ifdef F_89
if ( F_14 ( F_15 ( 0xd0 ) ) )
V_12 = & V_119 ;
#endif
#ifdef F_90
if ( ! V_12 )
V_12 = & V_120 ;
#endif
return F_91 ( & V_121 ) ;
}
static void T_9 F_92 ( void )
{
F_93 ( & V_121 ) ;
}
