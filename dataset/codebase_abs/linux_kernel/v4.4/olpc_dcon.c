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
T_3 V_7 ;
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
T_4 V_44 , V_45 ;
while ( 1 ) {
V_45 = F_21 () ;
V_44 = F_22 ( V_45 , V_2 -> V_46 ) ;
if ( F_23 ( V_44 ) > V_47 * 20 )
break;
F_24 ( 4 ) ;
}
}
static bool F_25 ( struct V_1 * V_2 , bool V_48 )
{
int V_11 ;
F_26 () ;
if ( ! F_27 ( V_2 -> V_49 ) ) {
F_28 () ;
F_8 ( & V_2 -> V_5 -> V_14 , L_9 ) ;
return false ;
}
V_2 -> V_50 = true ;
V_11 = F_29 ( V_2 -> V_49 ,
V_48 ? V_51 : V_52 ) ;
V_2 -> V_50 = false ;
F_30 ( V_2 -> V_49 ) ;
F_28 () ;
if ( V_11 ) {
F_8 ( & V_2 -> V_5 -> V_14 , L_10 ,
V_48 ? L_11 : L_12 ) ;
return false ;
}
return true ;
}
static void F_31 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_32 ( V_54 , struct V_1 ,
V_55 ) ;
int V_56 = V_2 -> V_57 ;
if ( V_2 -> V_58 == V_56 )
return;
F_20 ( V_2 ) ;
V_2 -> V_59 = false ;
switch ( V_56 ) {
case V_60 :
F_7 ( L_13 ) ;
if ( F_1 ( V_2 , V_26 ,
V_2 -> V_21 | V_61 ) )
F_6 ( L_14 ) ;
else
F_33 ( V_2 -> V_62 , V_2 -> V_59 , V_63 ) ;
if ( ! V_2 -> V_59 )
F_6 ( L_15 ) ;
if ( F_1 ( V_2 , V_26 , V_2 -> V_21 ) )
F_6 ( L_16 ) ;
if ( ! F_25 ( V_2 , false ) ) {
F_6 ( L_17 ) ;
V_2 -> V_57 = V_64 ;
return;
}
V_12 -> V_65 ( 1 ) ;
V_2 -> V_46 = F_21 () ;
F_7 ( L_18 ) ;
break;
case V_64 :
{
T_4 V_44 ;
F_7 ( L_19 ) ;
V_12 -> V_65 ( 0 ) ;
V_2 -> V_46 = F_21 () ;
F_33 ( V_2 -> V_62 , V_2 -> V_59 , V_63 / 2 ) ;
if ( ! V_2 -> V_59 ) {
F_6 ( L_20 ) ;
} else {
V_44 = F_22 ( V_2 -> V_66 , V_2 -> V_46 ) ;
if ( V_2 -> V_59 && F_23 ( V_44 )
< V_47 * 20 ) {
F_6 ( L_21 ) ;
V_12 -> V_65 ( 1 ) ;
F_24 ( 41 ) ;
V_12 -> V_65 ( 0 ) ;
V_2 -> V_46 = F_21 () ;
F_24 ( 41 ) ;
}
}
F_25 ( V_2 , true ) ;
F_7 ( L_22 ) ;
break;
}
default:
F_34 () ;
}
V_2 -> V_58 = V_56 ;
}
static void F_35 ( struct V_1 * V_2 , int V_67 )
{
if ( V_2 -> V_57 == V_67 )
return;
V_2 -> V_57 = V_67 ;
if ( V_2 -> V_58 != V_67 )
F_36 ( & V_2 -> V_55 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_67 )
{
F_35 ( V_2 , V_67 ) ;
F_38 () ;
}
static T_5 F_39 ( struct V_68 * V_14 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_1 * V_2 = F_40 ( V_14 ) ;
return sprintf ( V_71 , L_23 , V_2 -> V_21 ) ;
}
static T_5 F_41 ( struct V_68 * V_14 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_1 * V_2 = F_40 ( V_14 ) ;
return sprintf ( V_71 , L_24 , V_2 -> V_43 ) ;
}
static T_5 F_42 ( struct V_68 * V_14 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_1 * V_2 = F_40 ( V_14 ) ;
return sprintf ( V_71 , L_24 , V_2 -> V_58 == V_64 ? 1 : 0 ) ;
}
static T_5 F_43 ( struct V_68 * V_14 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_1 * V_2 = F_40 ( V_14 ) ;
return sprintf ( V_71 , L_24 , V_2 -> V_40 ) ;
}
static T_5 F_44 ( struct V_68 * V_14 ,
struct V_69 * V_70 , char * V_71 )
{
return sprintf ( V_71 , L_24 , V_28 ) ;
}
static T_5 F_45 ( struct V_68 * V_14 ,
struct V_69 * V_70 , const char * V_71 , T_6 V_72 )
{
unsigned long V_39 ;
int V_8 ;
V_8 = F_46 ( V_71 , 10 , & V_39 ) ;
if ( V_8 )
return V_8 ;
F_18 ( F_40 ( V_14 ) , V_39 ? true : false ) ;
return V_72 ;
}
static T_5 F_47 ( struct V_68 * V_14 ,
struct V_69 * V_70 , const char * V_71 , T_6 V_72 )
{
struct V_1 * V_2 = F_40 ( V_14 ) ;
unsigned long V_73 ;
int V_74 ;
V_74 = F_46 ( V_71 , 10 , & V_73 ) ;
if ( V_74 )
return V_74 ;
F_7 ( L_25 , V_73 ) ;
switch ( V_73 ) {
case 0 :
F_35 ( V_2 , V_60 ) ;
break;
case 1 :
F_37 ( V_2 , V_64 ) ;
break;
case 2 :
F_35 ( V_2 , V_64 ) ;
break;
default:
return - V_75 ;
}
return V_72 ;
}
static T_5 F_48 ( struct V_68 * V_14 ,
struct V_69 * V_70 , const char * V_71 , T_6 V_72 )
{
unsigned short V_76 ;
int V_8 ;
V_8 = F_49 ( V_71 , 10 , & V_76 ) ;
if ( V_8 )
return V_8 ;
V_28 = V_76 ;
F_1 ( F_40 ( V_14 ) , V_27 , V_28 ) ;
return V_72 ;
}
static T_5 F_50 ( struct V_68 * V_14 ,
struct V_69 * V_70 , const char * V_71 , T_6 V_72 )
{
unsigned long V_73 ;
int V_74 ;
V_74 = F_46 ( V_71 , 10 , & V_73 ) ;
if ( V_74 )
return V_74 ;
F_19 ( F_40 ( V_14 ) , V_73 ? true : false ) ;
return V_72 ;
}
static int F_51 ( struct V_77 * V_14 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
T_2 V_36 = V_14 -> V_78 . V_79 & 0x0F ;
if ( V_14 -> V_78 . V_80 != V_52 )
V_36 = 0 ;
if ( V_36 != V_2 -> V_37 )
F_17 ( V_2 , V_36 ) ;
if ( ! V_2 -> V_50 )
F_19 ( V_2 , ! ! ( V_14 -> V_78 . V_81 & V_82 ) ) ;
return 0 ;
}
static int F_53 ( struct V_77 * V_14 )
{
struct V_1 * V_2 = F_52 ( V_14 ) ;
return V_2 -> V_37 ;
}
static int F_54 ( struct V_83 * V_84 ,
unsigned long V_85 , void * V_86 )
{
struct V_1 * V_2 = F_32 ( V_84 , struct V_1 , V_87 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
return V_88 ;
F_1 ( V_2 , V_26 , 0x39 ) ;
F_1 ( V_2 , V_26 , 0x32 ) ;
return V_88 ;
}
static int F_55 ( struct V_83 * V_84 ,
unsigned long V_89 , void * V_90 )
{
V_12 -> V_65 ( 1 ) ;
return V_88 ;
}
static int F_56 ( struct V_91 * V_5 , struct V_92 * V_93 )
{
F_57 ( V_93 -> type , L_26 , V_94 ) ;
return 0 ;
}
static int F_58 ( struct V_91 * V_5 , const struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_8 , V_97 , V_98 ;
if ( ! V_12 )
return - V_10 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_5 = V_5 ;
F_60 ( & V_2 -> V_62 ) ;
F_61 ( & V_2 -> V_55 , F_31 ) ;
V_2 -> V_87 . V_101 = F_54 ;
V_2 -> V_87 . V_102 = - 1 ;
F_62 ( V_5 , V_2 ) ;
if ( V_103 < 1 ) {
F_8 ( & V_5 -> V_14 , L_27 ) ;
V_8 = - V_104 ;
goto V_105;
}
V_2 -> V_49 = V_106 [ 0 ] ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( V_8 )
goto V_105;
V_107 = F_63 ( L_28 , - 1 ) ;
if ( ! V_107 ) {
F_6 ( L_29 ) ;
V_8 = - V_100 ;
goto V_108;
}
V_8 = F_64 ( V_107 ) ;
F_65 ( V_107 , V_2 ) ;
if ( V_8 ) {
F_6 ( L_30 ) ;
goto V_109;
}
for ( V_97 = 0 ; V_97 < F_66 ( V_110 ) ; V_97 ++ ) {
V_8 = F_67 ( & V_107 -> V_14 ,
& V_110 [ V_97 ] ) ;
if ( V_8 ) {
F_8 ( & V_107 -> V_14 , L_31 ) ;
goto V_111;
}
}
V_2 -> V_37 = F_3 ( V_2 , V_38 ) & 0x0F ;
V_112 . V_79 = V_2 -> V_37 ;
V_2 -> V_113 = F_68 ( L_32 , & V_107 -> V_14 ,
V_2 , & V_114 , & V_112 ) ;
if ( F_69 ( V_2 -> V_113 ) ) {
F_8 ( & V_5 -> V_14 , L_33 ,
F_70 ( V_2 -> V_113 ) ) ;
V_2 -> V_113 = NULL ;
}
F_71 ( & V_2 -> V_87 ) ;
F_72 ( & V_115 , & V_116 ) ;
return 0 ;
V_111:
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ )
F_73 ( & V_107 -> V_14 , & V_110 [ V_98 ] ) ;
V_109:
F_74 ( V_107 ) ;
V_107 = NULL ;
V_108:
F_75 ( V_117 , V_2 ) ;
V_105:
F_76 ( V_2 ) ;
return V_8 ;
}
static int F_77 ( struct V_91 * V_5 )
{
struct V_1 * V_2 = F_78 ( V_5 ) ;
F_79 ( & V_2 -> V_87 ) ;
F_80 ( & V_115 , & V_116 ) ;
F_75 ( V_117 , V_2 ) ;
F_81 ( V_2 -> V_113 ) ;
if ( V_107 )
F_74 ( V_107 ) ;
F_82 ( & V_2 -> V_55 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_68 * V_14 )
{
struct V_91 * V_5 = F_84 ( V_14 ) ;
struct V_1 * V_2 = F_78 ( V_5 ) ;
if ( ! V_2 -> V_43 ) {
F_37 ( V_2 , V_64 ) ;
}
return 0 ;
}
static int F_85 ( struct V_68 * V_14 )
{
struct V_91 * V_5 = F_84 ( V_14 ) ;
struct V_1 * V_2 = F_78 ( V_5 ) ;
if ( ! V_2 -> V_43 ) {
F_9 ( V_2 , 0 ) ;
F_35 ( V_2 , V_60 ) ;
}
return 0 ;
}
T_7 F_86 ( int V_118 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
T_2 V_119 ;
if ( V_12 -> V_120 ( & V_119 ) )
return V_121 ;
switch ( V_119 & 3 ) {
case 3 :
F_87 ( L_34 ) ;
break;
case 2 :
case 1 :
V_2 -> V_59 = true ;
V_2 -> V_66 = F_21 () ;
F_88 ( & V_2 -> V_62 ) ;
break;
case 0 :
if ( V_2 -> V_58 != V_2 -> V_57 && ! V_2 -> V_59 ) {
V_2 -> V_59 = true ;
V_2 -> V_66 = F_21 () ;
F_88 ( & V_2 -> V_62 ) ;
F_87 ( L_35 ) ;
} else {
F_87 ( L_36 ) ;
}
}
return V_122 ;
}
static int T_8 F_89 ( void )
{
#ifdef F_90
if ( F_14 ( F_15 ( 0xd0 ) ) )
V_12 = & V_123 ;
#endif
#ifdef F_91
if ( ! V_12 )
V_12 = & V_124 ;
#endif
return F_92 ( & V_125 ) ;
}
static void T_9 F_93 ( void )
{
F_94 ( & V_125 ) ;
}
