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
F_1 ( V_2 , V_16 , 0x0000 ) ;
F_1 ( V_2 , V_16 ,
V_17 | V_18 ) ;
F_1 ( V_2 , V_19 , V_20 ) ;
if ( V_6 ) {
V_2 -> V_21 = V_22 | V_23 |
V_24 | V_25 ;
}
F_1 ( V_2 , V_26 , V_2 -> V_21 ) ;
F_1 ( V_2 , V_27 , V_28 ) ;
V_11:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_29 )
{
unsigned long V_30 ;
T_2 V_31 ;
int V_32 ;
V_33:
if ( V_29 ) {
V_31 = 1 ;
V_32 = F_10 ( V_34 , & V_31 , 1 , NULL , 0 ) ;
if ( V_32 ) {
F_11 ( L_5 , V_32 ) ;
return V_32 ;
}
F_12 ( 10000 , 11000 ) ;
}
V_12 -> V_35 () ;
for ( V_32 = - 1 , V_30 = 50 ; V_30 && V_32 < 0 ; V_30 -- ) {
F_12 ( 1000 , 1100 ) ;
V_32 = F_3 ( V_2 , V_9 ) ;
}
if ( V_32 < 0 ) {
F_6 ( L_6 ) ;
F_13 ( F_14 ( F_15 ( 0xc2 ) ) ) ;
V_31 = 0 ;
F_10 ( V_34 , & V_31 , 1 , NULL , 0 ) ;
F_16 ( 100 ) ;
V_29 = 1 ;
goto V_33;
}
if ( V_29 )
return F_5 ( V_2 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_36 )
{
V_2 -> V_37 = V_36 ;
F_1 ( V_2 , V_38 , V_2 -> V_37 ) ;
if ( V_2 -> V_37 == 0 ) {
V_2 -> V_21 &= ~ V_23 ;
F_1 ( V_2 , V_26 , V_2 -> V_21 ) ;
} else if ( ! ( V_2 -> V_21 & V_23 ) ) {
V_2 -> V_21 |= V_23 ;
F_1 ( V_2 , V_26 , V_2 -> V_21 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , bool V_39 )
{
if ( V_2 -> V_40 == V_39 )
return 0 ;
V_2 -> V_40 = V_39 ;
if ( V_39 ) {
V_2 -> V_21 &= ~ ( V_24 | V_25 ) ;
V_2 -> V_21 |= V_41 ;
} else {
V_2 -> V_21 &= ~ ( V_41 ) ;
V_2 -> V_21 |= V_24 | V_25 ;
}
F_1 ( V_2 , V_26 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , bool V_42 )
{
int V_32 ;
if ( V_2 -> V_43 == V_42 )
return;
if ( ! F_14 ( F_15 ( 0xc2 ) ) )
return;
if ( V_42 ) {
T_2 V_31 = 0 ;
V_32 = F_10 ( V_34 , & V_31 , 1 , NULL , 0 ) ;
if ( V_32 )
F_11 ( L_7 , V_32 ) ;
else
V_2 -> V_43 = V_42 ;
} else {
if ( V_2 -> V_37 != 0 )
V_2 -> V_21 |= V_23 ;
V_32 = F_9 ( V_2 , 1 ) ;
if ( V_32 )
F_11 ( L_8 , V_32 ) ;
else
V_2 -> V_43 = V_42 ;
F_17 ( V_2 , V_2 -> V_37 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_44 V_45 , V_46 ;
while ( 1 ) {
F_21 ( & V_46 ) ;
V_45 = F_22 ( V_46 , V_2 -> V_47 ) ;
if ( V_45 . V_48 != 0 ||
V_45 . V_49 > V_50 * 20 ) {
break;
}
F_23 ( 4 ) ;
}
}
static bool F_24 ( struct V_1 * V_2 , bool V_51 )
{
int V_11 ;
F_25 () ;
if ( ! F_26 ( V_2 -> V_52 ) ) {
F_27 () ;
F_8 ( & V_2 -> V_5 -> V_14 , L_9 ) ;
return false ;
}
V_2 -> V_53 = true ;
V_11 = F_28 ( V_2 -> V_52 ,
V_51 ? V_54 : V_55 ) ;
V_2 -> V_53 = false ;
F_29 ( V_2 -> V_52 ) ;
F_27 () ;
if ( V_11 ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_10 ,
V_51 ? L_11 : L_12 ) ;
return false ;
}
return true ;
}
static void F_30 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_31 ( V_57 , struct V_1 ,
V_58 ) ;
int V_59 = V_2 -> V_60 ;
if ( V_2 -> V_61 == V_59 )
return;
F_20 ( V_2 ) ;
V_2 -> V_62 = false ;
switch ( V_59 ) {
case V_63 :
F_7 ( L_13 ) ;
if ( F_1 ( V_2 , V_26 ,
V_2 -> V_21 | V_64 ) )
F_6 ( L_14 ) ;
else
F_32 ( V_2 -> V_65 , V_2 -> V_62 , V_66 ) ;
if ( ! V_2 -> V_62 )
F_6 ( L_15 ) ;
if ( F_1 ( V_2 , V_26 , V_2 -> V_21 ) )
F_6 ( L_16 ) ;
if ( ! F_24 ( V_2 , false ) ) {
F_6 ( L_17 ) ;
V_2 -> V_60 = V_67 ;
return;
}
V_12 -> V_68 ( 1 ) ;
F_21 ( & V_2 -> V_47 ) ;
F_7 ( L_18 ) ;
break;
case V_67 :
{
struct V_44 V_45 ;
F_7 ( L_19 ) ;
V_12 -> V_68 ( 0 ) ;
F_21 ( & V_2 -> V_47 ) ;
F_32 ( V_2 -> V_65 , V_2 -> V_62 , V_66 / 2 ) ;
if ( ! V_2 -> V_62 ) {
F_6 ( L_20 ) ;
} else {
V_45 = F_22 ( V_2 -> V_69 , V_2 -> V_47 ) ;
if ( V_2 -> V_62 && V_45 . V_48 == 0 &&
V_45 . V_49 < V_50 * 20 ) {
F_6 ( L_21 ) ;
V_12 -> V_68 ( 1 ) ;
F_23 ( 41 ) ;
V_12 -> V_68 ( 0 ) ;
F_21 ( & V_2 -> V_47 ) ;
F_23 ( 41 ) ;
}
}
F_24 ( V_2 , true ) ;
F_7 ( L_22 ) ;
break;
}
default:
F_33 () ;
}
V_2 -> V_61 = V_59 ;
}
static void F_34 ( struct V_1 * V_2 , int V_70 )
{
if ( V_2 -> V_60 == V_70 )
return;
V_2 -> V_60 = V_70 ;
if ( V_2 -> V_61 != V_70 )
F_35 ( & V_2 -> V_58 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_70 )
{
F_34 ( V_2 , V_70 ) ;
F_37 () ;
}
static T_5 F_38 ( struct V_71 * V_14 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_74 , L_23 , V_2 -> V_21 ) ;
}
static T_5 F_40 ( struct V_71 * V_14 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_74 , L_24 , V_2 -> V_43 ) ;
}
static T_5 F_41 ( struct V_71 * V_14 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_74 , L_24 , V_2 -> V_61 == V_67 ? 1 : 0 ) ;
}
static T_5 F_42 ( struct V_71 * V_14 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
return sprintf ( V_74 , L_24 , V_2 -> V_40 ) ;
}
static T_5 F_43 ( struct V_71 * V_14 ,
struct V_72 * V_73 , char * V_74 )
{
return sprintf ( V_74 , L_24 , V_28 ) ;
}
static T_5 F_44 ( struct V_71 * V_14 ,
struct V_72 * V_73 , const char * V_74 , T_6 V_75 )
{
unsigned long V_39 ;
int V_8 ;
V_8 = F_45 ( V_74 , 10 , & V_39 ) ;
if ( V_8 )
return V_8 ;
F_18 ( F_39 ( V_14 ) , V_39 ? true : false ) ;
return V_75 ;
}
static T_5 F_46 ( struct V_71 * V_14 ,
struct V_72 * V_73 , const char * V_74 , T_6 V_75 )
{
struct V_1 * V_2 = F_39 ( V_14 ) ;
unsigned long V_76 ;
int V_77 ;
V_77 = F_45 ( V_74 , 10 , & V_76 ) ;
if ( V_77 )
return V_77 ;
F_7 ( L_25 , V_76 ) ;
switch ( V_76 ) {
case 0 :
F_34 ( V_2 , V_63 ) ;
break;
case 1 :
F_36 ( V_2 , V_67 ) ;
break;
case 2 :
F_34 ( V_2 , V_67 ) ;
break;
default:
return - V_78 ;
}
return V_75 ;
}
static T_5 F_47 ( struct V_71 * V_14 ,
struct V_72 * V_73 , const char * V_74 , T_6 V_75 )
{
unsigned short V_79 ;
int V_8 ;
V_8 = F_48 ( V_74 , 10 , & V_79 ) ;
if ( V_8 )
return V_8 ;
V_28 = V_79 ;
F_1 ( F_39 ( V_14 ) , V_27 , V_28 ) ;
return V_75 ;
}
static T_5 F_49 ( struct V_71 * V_14 ,
struct V_72 * V_73 , const char * V_74 , T_6 V_75 )
{
unsigned long V_76 ;
int V_77 ;
V_77 = F_45 ( V_74 , 10 , & V_76 ) ;
if ( V_77 )
return V_77 ;
F_19 ( F_39 ( V_14 ) , V_76 ? true : false ) ;
return V_75 ;
}
static int F_50 ( struct V_80 * V_14 )
{
struct V_1 * V_2 = F_51 ( V_14 ) ;
T_2 V_36 = V_14 -> V_81 . V_82 & 0x0F ;
if ( V_14 -> V_81 . V_83 != V_55 )
V_36 = 0 ;
if ( V_36 != V_2 -> V_37 )
F_17 ( V_2 , V_36 ) ;
if ( ! V_2 -> V_53 )
F_19 ( V_2 , ! ! ( V_14 -> V_81 . V_84 & V_85 ) ) ;
return 0 ;
}
static int F_52 ( struct V_80 * V_14 )
{
struct V_1 * V_2 = F_51 ( V_14 ) ;
return V_2 -> V_37 ;
}
static int F_53 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_1 * V_2 = F_31 ( V_87 , struct V_1 , V_90 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return V_91 ;
F_1 ( V_2 , V_26 , 0x39 ) ;
F_1 ( V_2 , V_26 , 0x32 ) ;
return V_91 ;
}
static int F_54 ( struct V_86 * V_87 ,
unsigned long V_92 , void * V_93 )
{
V_12 -> V_68 ( 1 ) ;
return V_91 ;
}
static int F_55 ( struct V_94 * V_5 , struct V_95 * V_96 )
{
F_56 ( V_96 -> type , L_26 , V_97 ) ;
return 0 ;
}
static int F_57 ( struct V_94 * V_5 , const struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_8 , V_100 , V_101 ;
if ( ! V_12 )
return - V_10 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_5 = V_5 ;
F_59 ( & V_2 -> V_65 ) ;
F_60 ( & V_2 -> V_58 , F_30 ) ;
V_2 -> V_90 . V_104 = F_53 ;
V_2 -> V_90 . V_105 = - 1 ;
F_61 ( V_5 , V_2 ) ;
if ( V_106 < 1 ) {
F_8 ( & V_5 -> V_14 , L_27 ) ;
V_8 = - V_107 ;
goto V_108;
}
V_2 -> V_52 = V_109 [ 0 ] ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( V_8 )
goto V_108;
V_110 = F_62 ( L_28 , - 1 ) ;
if ( V_110 == NULL ) {
F_6 ( L_29 ) ;
V_8 = - V_103 ;
goto V_111;
}
V_8 = F_63 ( V_110 ) ;
F_64 ( V_110 , V_2 ) ;
if ( V_8 ) {
F_6 ( L_30 ) ;
goto V_112;
}
for ( V_100 = 0 ; V_100 < F_65 ( V_113 ) ; V_100 ++ ) {
V_8 = F_66 ( & V_110 -> V_14 ,
& V_113 [ V_100 ] ) ;
if ( V_8 ) {
F_8 ( & V_110 -> V_14 , L_31 ) ;
goto V_114;
}
}
V_2 -> V_37 = F_3 ( V_2 , V_38 ) & 0x0F ;
V_115 . V_82 = V_2 -> V_37 ;
V_2 -> V_116 = F_67 ( L_32 , & V_110 -> V_14 ,
V_2 , & V_117 , & V_115 ) ;
if ( F_68 ( V_2 -> V_116 ) ) {
F_8 ( & V_5 -> V_14 , L_33 ,
F_69 ( V_2 -> V_116 ) ) ;
V_2 -> V_116 = NULL ;
}
F_70 ( & V_2 -> V_90 ) ;
F_71 ( & V_118 , & V_119 ) ;
return 0 ;
V_114:
for ( V_101 = 0 ; V_101 < V_100 ; V_101 ++ )
F_72 ( & V_110 -> V_14 , & V_113 [ V_101 ] ) ;
V_112:
F_73 ( V_110 ) ;
V_110 = NULL ;
V_111:
F_74 ( V_120 , V_2 ) ;
V_108:
F_75 ( V_2 ) ;
return V_8 ;
}
static int F_76 ( struct V_94 * V_5 )
{
struct V_1 * V_2 = F_77 ( V_5 ) ;
F_78 ( & V_2 -> V_90 ) ;
F_79 ( & V_118 , & V_119 ) ;
F_74 ( V_120 , V_2 ) ;
F_80 ( V_2 -> V_116 ) ;
if ( V_110 != NULL )
F_73 ( V_110 ) ;
F_81 ( & V_2 -> V_58 ) ;
F_75 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_71 * V_14 )
{
struct V_94 * V_5 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_77 ( V_5 ) ;
if ( ! V_2 -> V_43 ) {
F_36 ( V_2 , V_67 ) ;
}
return 0 ;
}
static int F_84 ( struct V_71 * V_14 )
{
struct V_94 * V_5 = F_83 ( V_14 ) ;
struct V_1 * V_2 = F_77 ( V_5 ) ;
if ( ! V_2 -> V_43 ) {
F_9 ( V_2 , 0 ) ;
F_34 ( V_2 , V_63 ) ;
}
return 0 ;
}
T_7 F_85 ( int V_121 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
T_2 V_122 ;
if ( V_12 -> V_123 ( & V_122 ) )
return V_124 ;
switch ( V_122 & 3 ) {
case 3 :
F_86 ( L_34 ) ;
break;
case 2 :
case 1 :
V_2 -> V_62 = true ;
F_21 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_65 ) ;
break;
case 0 :
if ( V_2 -> V_61 != V_2 -> V_60 && ! V_2 -> V_62 ) {
V_2 -> V_62 = true ;
F_21 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_65 ) ;
F_86 ( L_35 ) ;
} else {
F_86 ( L_36 ) ;
}
}
return V_125 ;
}
static int T_8 F_88 ( void )
{
#ifdef F_89
if ( F_14 ( F_15 ( 0xd0 ) ) )
V_12 = & V_126 ;
#endif
#ifdef F_90
if ( ! V_12 )
V_12 = & V_127 ;
#endif
return F_91 ( & V_128 ) ;
}
static void T_9 F_92 ( void )
{
F_93 ( & V_128 ) ;
}
