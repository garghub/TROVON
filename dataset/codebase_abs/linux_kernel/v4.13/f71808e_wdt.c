static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static int F_4 ( int V_1 , int V_2 )
{
int V_3 ;
V_3 = F_1 ( V_1 , V_2 ) << 8 ;
V_3 |= F_1 ( V_1 , V_2 + 1 ) ;
return V_3 ;
}
static inline void F_5 ( int V_1 , int V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline void F_6 ( int V_1 , int V_2 , int V_4 )
{
unsigned long V_3 = F_1 ( V_1 , V_2 ) ;
F_7 ( V_4 , & V_3 ) ;
F_5 ( V_1 , V_2 , V_3 ) ;
}
static inline void F_8 ( int V_1 , int V_2 , int V_4 )
{
unsigned long V_3 = F_1 ( V_1 , V_2 ) ;
F_9 ( V_4 , & V_3 ) ;
F_5 ( V_1 , V_2 , V_3 ) ;
}
static inline int F_10 ( int V_1 )
{
if ( ! F_11 ( V_1 , 2 , V_5 ) ) {
F_12 ( L_1 , ( int ) V_1 ) ;
return - V_6 ;
}
F_2 ( V_7 , V_1 ) ;
F_2 ( V_7 , V_1 ) ;
return 0 ;
}
static inline void F_13 ( int V_1 , int V_8 )
{
F_2 ( V_9 , V_1 ) ;
F_2 ( V_8 , V_1 + 1 ) ;
}
static inline void F_14 ( int V_1 )
{
F_2 ( V_10 , V_1 ) ;
F_15 ( V_1 , 2 ) ;
}
static int F_16 ( int V_11 )
{
if ( V_11 <= 0
|| V_11 > V_12 ) {
F_12 ( L_2 ) ;
return - V_13 ;
}
F_17 ( & V_14 . V_15 ) ;
V_14 . V_11 = V_11 ;
if ( V_11 > 0xff ) {
V_14 . V_16 = F_18 ( V_11 , 60 ) ;
V_14 . V_17 = true ;
} else {
V_14 . V_16 = V_11 ;
V_14 . V_17 = false ;
}
F_19 ( & V_14 . V_15 ) ;
return 0 ;
}
static int F_20 ( unsigned int V_18 )
{
int V_19 = 0 ;
unsigned int V_20 = 25 , V_21 = 125 , V_22 = 5000 ;
if ( V_14 . type == V_23 ) {
V_20 = 30 ;
V_21 = 150 ;
V_22 = 6000 ;
}
F_17 ( & V_14 . V_15 ) ;
if ( V_18 <= 1 ) {
V_14 . V_24 = 0 ;
} else if ( V_18 <= V_20 ) {
V_14 . V_24 = 1 ;
} else if ( V_18 <= V_21 ) {
V_14 . V_24 = 2 ;
} else if ( V_18 <= V_22 ) {
V_14 . V_24 = 3 ;
} else {
F_12 ( L_3 ) ;
V_19 = - V_13 ;
goto V_25;
}
V_14 . V_26 = V_18 ;
V_25:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_21 ( void )
{
int V_19 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_14 . V_27 ) ;
if ( V_19 )
goto V_25;
F_13 ( V_14 . V_27 , V_28 ) ;
if ( V_14 . V_17 )
F_6 ( V_14 . V_27 , V_29 ,
V_30 ) ;
else
F_8 ( V_14 . V_27 , V_29 ,
V_30 ) ;
F_5 ( V_14 . V_27 , V_31 ,
V_14 . V_16 ) ;
F_14 ( V_14 . V_27 ) ;
V_25:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_22 ( unsigned short V_32 )
{
if ( V_33 == 63 ) {
if ( V_32 ) {
F_8 ( V_32 , V_34 , 6 ) ;
F_6 ( V_32 , V_35 , 4 ) ;
}
} else if ( V_33 == 56 ) {
if ( V_32 )
F_6 ( V_32 , V_36 , 1 ) ;
} else {
F_12 ( L_4 , V_33 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_23 ( void )
{
int V_19 = F_21 () ;
if ( V_19 )
return V_19 ;
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_14 . V_27 ) ;
if ( V_19 )
goto V_25;
F_13 ( V_14 . V_27 , V_28 ) ;
switch ( V_14 . type ) {
case V_37 :
F_8 ( V_14 . V_27 , V_38 , 3 ) ;
F_8 ( V_14 . V_27 , V_35 , 3 ) ;
break;
case V_39 :
V_19 = F_22 ( V_14 . V_27 ) ;
if ( V_19 )
goto V_40;
break;
case V_23 :
case V_41 :
F_8 ( V_14 . V_27 , V_36 , 4 ) ;
break;
case V_42 :
F_6 ( V_14 . V_27 , V_36 , 1 ) ;
break;
case V_43 :
F_5 ( V_14 . V_27 , V_35 ,
F_1 ( V_14 . V_27 , V_35 ) & 0xcf ) ;
break;
case V_44 :
F_8 ( V_14 . V_27 , V_35 , 5 ) ;
break;
case V_45 :
F_8 ( V_14 . V_27 , V_46 ,
F_24 ( 3 ) | F_24 ( 0 ) ) ;
F_6 ( V_14 . V_27 , V_46 ,
F_24 ( 2 ) ) ;
F_8 ( V_14 . V_27 , V_47 ,
F_24 ( 5 ) ) ;
break;
default:
V_19 = - V_48 ;
goto V_40;
}
F_13 ( V_14 . V_27 , V_28 ) ;
F_6 ( V_14 . V_27 , V_49 , 0 ) ;
if ( V_14 . type == V_44 || V_14 . type == V_45 )
F_6 ( V_14 . V_27 , V_50 ,
V_51 ) ;
else
F_6 ( V_14 . V_27 , V_52 ,
V_53 ) ;
F_6 ( V_14 . V_27 , V_29 ,
V_54 ) ;
if ( V_14 . V_26 ) {
T_1 V_55 = F_1 ( V_14 . V_27 ,
V_29 ) ;
V_55 = ( V_55 & 0xfc ) | ( V_14 . V_24 & 0x03 ) ;
V_55 |= F_24 ( V_56 ) ;
F_5 ( V_14 . V_27 , V_29 ,
V_55 ) ;
} else {
F_8 ( V_14 . V_27 , V_29 ,
V_56 ) ;
}
V_40:
F_14 ( V_14 . V_27 ) ;
V_25:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_25 ( void )
{
int V_19 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_14 . V_27 ) ;
if ( V_19 )
goto V_25;
F_13 ( V_14 . V_27 , V_28 ) ;
F_8 ( V_14 . V_27 , V_29 ,
V_54 ) ;
F_14 ( V_14 . V_27 ) ;
V_25:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_26 ( void )
{
int V_57 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_57 = ( V_14 . V_58 ) ? V_59 : 0 ;
F_19 ( & V_14 . V_15 ) ;
return V_57 ;
}
static bool F_27 ( void )
{
bool V_60 = true ;
F_17 ( & V_14 . V_15 ) ;
if ( F_10 ( V_14 . V_27 ) )
goto V_25;
F_13 ( V_14 . V_27 , V_28 ) ;
V_60 = ( F_1 ( V_14 . V_27 , V_49 ) & F_24 ( 0 ) )
&& ( F_1 ( V_14 . V_27 , V_29 )
& V_54 ) ;
F_14 ( V_14 . V_27 ) ;
V_25:
F_19 ( & V_14 . V_15 ) ;
return V_60 ;
}
static int F_28 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
int V_19 ;
if ( F_29 ( 0 , & V_14 . V_63 ) )
return - V_6 ;
V_19 = F_23 () ;
if ( V_19 ) {
F_30 ( 0 , & V_14 . V_63 ) ;
return V_19 ;
}
if ( V_64 )
F_31 ( V_65 ) ;
V_14 . V_66 = 0 ;
return F_32 ( V_61 , V_62 ) ;
}
static int F_33 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
F_30 ( 0 , & V_14 . V_63 ) ;
if ( ! V_14 . V_66 ) {
F_21 () ;
F_34 ( L_5 ) ;
} else if ( ! V_64 ) {
F_25 () ;
}
return 0 ;
}
static T_2 F_35 ( struct V_62 * V_62 , const char T_3 * V_67 ,
T_4 V_68 , T_5 * V_69 )
{
if ( V_68 ) {
if ( ! V_64 ) {
T_4 V_70 ;
bool V_66 = false ;
for ( V_70 = 0 ; V_70 != V_68 ; V_70 ++ ) {
char V_71 ;
if ( F_36 ( V_71 , V_67 + V_70 ) )
return - V_72 ;
V_66 = ( V_71 == 'V' ) ;
}
F_17 ( & V_14 . V_15 ) ;
V_14 . V_66 = V_66 ;
F_19 ( & V_14 . V_15 ) ;
}
F_21 () ;
}
return V_68 ;
}
static long F_37 ( struct V_62 * V_62 , unsigned int V_73 ,
unsigned long V_74 )
{
int V_57 ;
int V_75 ;
int V_76 ;
union {
struct V_77 T_3 * V_78 ;
int T_3 * V_70 ;
} V_79 ;
V_79 . V_70 = ( int T_3 * ) V_74 ;
switch ( V_73 ) {
case V_80 :
return F_38 ( V_79 . V_78 , & V_14 . V_78 ,
sizeof( V_14 . V_78 ) ) ? - V_72 : 0 ;
case V_81 :
V_57 = F_26 () ;
if ( V_57 < 0 )
return V_57 ;
return F_39 ( V_57 , V_79 . V_70 ) ;
case V_82 :
return F_39 ( 0 , V_79 . V_70 ) ;
case V_83 :
if ( F_36 ( V_75 , V_79 . V_70 ) )
return - V_72 ;
if ( V_75 & V_84 )
F_25 () ;
if ( V_75 & V_85 )
return F_23 () ;
case V_86 :
F_21 () ;
return 0 ;
case V_87 :
if ( F_36 ( V_76 , V_79 . V_70 ) )
return - V_72 ;
if ( F_16 ( V_76 ) )
return - V_13 ;
F_21 () ;
case V_88 :
return F_39 ( V_14 . V_11 , V_79 . V_70 ) ;
default:
return - V_89 ;
}
}
static int F_40 ( struct V_90 * V_91 , unsigned long V_92 ,
void * V_93 )
{
if ( V_92 == V_94 || V_92 == V_95 )
F_25 () ;
return V_96 ;
}
static int T_6 F_41 ( int V_27 )
{
int V_55 , V_19 = 0 ;
V_14 . V_27 = V_27 ;
V_14 . V_78 . V_97 = V_87
| V_98
| V_99 ;
snprintf ( V_14 . V_78 . V_100 ,
sizeof( V_14 . V_78 . V_100 ) , L_6 ,
V_101 [ V_14 . type ] ) ;
V_19 = F_10 ( V_27 ) ;
if ( V_19 )
return V_19 ;
F_13 ( V_14 . V_27 , V_28 ) ;
V_55 = F_1 ( V_27 , V_29 ) ;
V_14 . V_58 = V_55 & F_24 ( V_102 ) ;
F_14 ( V_27 ) ;
V_19 = F_16 ( V_11 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_20 ( V_103 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_42 ( & V_104 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_43 ( & V_105 ) ;
if ( V_19 ) {
F_12 ( L_7 ,
V_105 . V_106 ) ;
goto V_107;
}
if ( V_108 ) {
if ( V_108 <= 0
|| V_108 > V_12 ) {
F_12 ( L_8 ) ;
V_19 = - V_13 ;
goto V_109;
}
V_19 = F_23 () ;
if ( V_19 ) {
F_12 ( L_9 ) ;
goto V_109;
}
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_27 ) ;
if ( V_19 )
goto V_25;
F_13 ( V_14 . V_27 , V_28 ) ;
if ( V_108 > 0xff ) {
F_6 ( V_27 , V_29 ,
V_30 ) ;
F_5 ( V_27 , V_31 ,
F_18 ( V_108 , 60 ) ) ;
} else {
F_8 ( V_27 , V_29 ,
V_30 ) ;
F_5 ( V_27 , V_31 ,
V_108 ) ;
}
F_14 ( V_27 ) ;
F_19 ( & V_14 . V_15 ) ;
if ( V_64 )
F_31 ( V_65 ) ;
F_44 ( L_10 ,
V_108 ) ;
}
return 0 ;
V_25:
F_19 ( & V_14 . V_15 ) ;
V_109:
F_45 ( & V_105 ) ;
V_107:
F_46 ( & V_104 ) ;
return V_19 ;
}
static int T_6 F_47 ( int V_27 )
{
T_7 V_110 ;
int V_19 = F_10 ( V_27 ) ;
if ( V_19 )
return V_19 ;
V_110 = F_4 ( V_27 , V_111 ) ;
if ( V_110 != V_112 ) {
F_48 ( L_11 ) ;
V_19 = - V_48 ;
goto exit;
}
V_110 = V_113 ? V_113 : F_4 ( V_27 , V_114 ) ;
switch ( V_110 ) {
case V_115 :
V_14 . type = V_37 ;
break;
case V_116 :
V_14 . type = V_39 ;
V_19 = F_22 ( 0 ) ;
break;
case V_117 :
V_14 . type = V_23 ;
break;
case V_118 :
case V_119 :
V_14 . type = V_41 ;
break;
case V_120 :
V_14 . type = V_42 ;
break;
case V_121 :
V_14 . type = V_43 ;
break;
case V_122 :
V_19 = - V_48 ;
goto exit;
case V_123 :
V_14 . type = V_44 ;
break;
case V_124 :
V_14 . type = V_45 ;
break;
default:
F_44 ( L_12 ,
( unsigned int ) V_110 ) ;
V_19 = - V_48 ;
goto exit;
}
F_44 ( L_13 ,
V_101 [ V_14 . type ] ,
( int ) F_1 ( V_27 , V_125 ) ) ;
exit:
F_14 ( V_27 ) ;
return V_19 ;
}
static int T_6 F_49 ( void )
{
static const unsigned short V_126 [] = { 0x2e , 0x4e } ;
int V_19 = - V_48 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_50 ( V_126 ) ; V_70 ++ ) {
V_19 = F_47 ( V_126 [ V_70 ] ) ;
if ( V_19 == 0 )
break;
}
if ( V_70 == F_50 ( V_126 ) )
return V_19 ;
return F_41 ( V_126 [ V_70 ] ) ;
}
static void T_8 F_51 ( void )
{
if ( F_27 () ) {
F_52 ( L_14 ) ;
F_25 () ;
}
F_45 ( & V_105 ) ;
F_46 ( & V_104 ) ;
}
