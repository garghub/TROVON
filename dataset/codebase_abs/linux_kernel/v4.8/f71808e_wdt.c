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
F_17 ( & V_14 . V_15 ) ;
if ( V_18 <= 1 ) {
V_14 . V_20 = 0 ;
} else if ( V_18 <= 25 ) {
V_14 . V_20 = 1 ;
} else if ( V_18 <= 125 ) {
V_14 . V_20 = 2 ;
} else if ( V_18 <= 5000 ) {
V_14 . V_20 = 3 ;
} else {
F_12 ( L_3 ) ;
V_19 = - V_13 ;
goto V_21;
}
V_14 . V_22 = V_18 ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_21 ( void )
{
int V_19 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_14 . V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
if ( V_14 . V_17 )
F_6 ( V_14 . V_23 , V_25 ,
V_26 ) ;
else
F_8 ( V_14 . V_23 , V_25 ,
V_26 ) ;
F_5 ( V_14 . V_23 , V_27 ,
V_14 . V_16 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_22 ( unsigned short V_28 )
{
if ( V_29 == 63 ) {
if ( V_28 ) {
F_8 ( V_28 , V_30 , 6 ) ;
F_6 ( V_28 , V_31 , 4 ) ;
}
} else if ( V_29 == 56 ) {
if ( V_28 )
F_6 ( V_28 , V_32 , 1 ) ;
} else {
F_12 ( L_4 , V_29 ) ;
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
V_19 = F_10 ( V_14 . V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
switch ( V_14 . type ) {
case V_33 :
F_8 ( V_14 . V_23 , V_34 , 3 ) ;
F_8 ( V_14 . V_23 , V_31 , 3 ) ;
break;
case V_35 :
V_19 = F_22 ( V_14 . V_23 ) ;
if ( V_19 )
goto V_36;
break;
case V_37 :
F_8 ( V_14 . V_23 , V_32 , 4 ) ;
break;
case V_38 :
F_6 ( V_14 . V_23 , V_32 , 1 ) ;
break;
case V_39 :
F_5 ( V_14 . V_23 , V_31 ,
F_1 ( V_14 . V_23 , V_31 ) & 0xcf ) ;
break;
case V_40 :
F_8 ( V_14 . V_23 , V_31 , 5 ) ;
break;
case V_41 :
F_8 ( V_14 . V_23 , V_42 ,
F_24 ( 3 ) | F_24 ( 0 ) ) ;
F_6 ( V_14 . V_23 , V_42 ,
F_24 ( 2 ) ) ;
F_8 ( V_14 . V_23 , V_43 ,
F_24 ( 5 ) ) ;
break;
default:
V_19 = - V_44 ;
goto V_36;
}
F_13 ( V_14 . V_23 , V_24 ) ;
F_6 ( V_14 . V_23 , V_45 , 0 ) ;
if ( V_14 . type == V_40 || V_14 . type == V_41 )
F_6 ( V_14 . V_23 , V_46 ,
V_47 ) ;
else
F_6 ( V_14 . V_23 , V_48 ,
V_49 ) ;
F_6 ( V_14 . V_23 , V_25 ,
V_50 ) ;
if ( V_14 . V_22 ) {
T_1 V_51 = F_1 ( V_14 . V_23 ,
V_25 ) ;
V_51 = ( V_51 & 0xfc ) | ( V_14 . V_20 & 0x03 ) ;
V_51 |= F_24 ( V_52 ) ;
F_5 ( V_14 . V_23 , V_25 ,
V_51 ) ;
} else {
F_8 ( V_14 . V_23 , V_25 ,
V_52 ) ;
}
V_36:
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_25 ( void )
{
int V_19 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_14 . V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
F_8 ( V_14 . V_23 , V_25 ,
V_50 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_26 ( void )
{
int V_53 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_53 = ( V_14 . V_54 ) ? V_55 : 0 ;
F_19 ( & V_14 . V_15 ) ;
return V_53 ;
}
static bool F_27 ( void )
{
bool V_56 = true ;
F_17 ( & V_14 . V_15 ) ;
if ( F_10 ( V_14 . V_23 ) )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
V_56 = ( F_1 ( V_14 . V_23 , V_45 ) & F_24 ( 0 ) )
&& ( F_1 ( V_14 . V_23 , V_25 )
& V_50 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_56 ;
}
static int F_28 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
int V_19 ;
if ( F_29 ( 0 , & V_14 . V_59 ) )
return - V_6 ;
V_19 = F_23 () ;
if ( V_19 ) {
F_30 ( 0 , & V_14 . V_59 ) ;
return V_19 ;
}
if ( V_60 )
F_31 ( V_61 ) ;
V_14 . V_62 = 0 ;
return F_32 ( V_57 , V_58 ) ;
}
static int F_33 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
F_30 ( 0 , & V_14 . V_59 ) ;
if ( ! V_14 . V_62 ) {
F_21 () ;
F_34 ( L_5 ) ;
} else if ( ! V_60 ) {
F_25 () ;
}
return 0 ;
}
static T_2 F_35 ( struct V_58 * V_58 , const char T_3 * V_63 ,
T_4 V_64 , T_5 * V_65 )
{
if ( V_64 ) {
if ( ! V_60 ) {
T_4 V_66 ;
bool V_62 = false ;
for ( V_66 = 0 ; V_66 != V_64 ; V_66 ++ ) {
char V_67 ;
if ( F_36 ( V_67 , V_63 + V_66 ) )
return - V_68 ;
V_62 = ( V_67 == 'V' ) ;
}
F_17 ( & V_14 . V_15 ) ;
V_14 . V_62 = V_62 ;
F_19 ( & V_14 . V_15 ) ;
}
F_21 () ;
}
return V_64 ;
}
static long F_37 ( struct V_58 * V_58 , unsigned int V_69 ,
unsigned long V_70 )
{
int V_53 ;
int V_71 ;
int V_72 ;
union {
struct V_73 T_3 * V_74 ;
int T_3 * V_66 ;
} V_75 ;
V_75 . V_66 = ( int T_3 * ) V_70 ;
switch ( V_69 ) {
case V_76 :
return F_38 ( V_75 . V_74 , & V_14 . V_74 ,
sizeof( V_14 . V_74 ) ) ? - V_68 : 0 ;
case V_77 :
V_53 = F_26 () ;
if ( V_53 < 0 )
return V_53 ;
return F_39 ( V_53 , V_75 . V_66 ) ;
case V_78 :
return F_39 ( 0 , V_75 . V_66 ) ;
case V_79 :
if ( F_36 ( V_71 , V_75 . V_66 ) )
return - V_68 ;
if ( V_71 & V_80 )
F_25 () ;
if ( V_71 & V_81 )
return F_23 () ;
case V_82 :
F_21 () ;
return 0 ;
case V_83 :
if ( F_36 ( V_72 , V_75 . V_66 ) )
return - V_68 ;
if ( F_16 ( V_72 ) )
return - V_13 ;
F_21 () ;
case V_84 :
return F_39 ( V_14 . V_11 , V_75 . V_66 ) ;
default:
return - V_85 ;
}
}
static int F_40 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
if ( V_88 == V_90 || V_88 == V_91 )
F_25 () ;
return V_92 ;
}
static int T_6 F_41 ( int V_23 )
{
int V_51 , V_19 = 0 ;
V_14 . V_23 = V_23 ;
V_14 . V_74 . V_93 = V_83
| V_94
| V_95 ;
snprintf ( V_14 . V_74 . V_96 ,
sizeof( V_14 . V_74 . V_96 ) , L_6 ,
V_97 [ V_14 . type ] ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
F_13 ( V_14 . V_23 , V_24 ) ;
V_51 = F_1 ( V_23 , V_25 ) ;
V_14 . V_54 = V_51 & F_24 ( V_98 ) ;
F_14 ( V_23 ) ;
V_19 = F_16 ( V_11 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_20 ( V_99 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_42 ( & V_100 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_43 ( & V_101 ) ;
if ( V_19 ) {
F_12 ( L_7 ,
V_101 . V_102 ) ;
goto V_103;
}
if ( V_104 ) {
if ( V_104 <= 0
|| V_104 > V_12 ) {
F_12 ( L_8 ) ;
V_19 = - V_13 ;
goto V_105;
}
V_19 = F_23 () ;
if ( V_19 ) {
F_12 ( L_9 ) ;
goto V_105;
}
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
if ( V_104 > 0xff ) {
F_6 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
F_18 ( V_104 , 60 ) ) ;
} else {
F_8 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
V_104 ) ;
}
F_14 ( V_23 ) ;
F_19 ( & V_14 . V_15 ) ;
if ( V_60 )
F_31 ( V_61 ) ;
F_44 ( L_10 ,
V_104 ) ;
}
return 0 ;
V_21:
F_19 ( & V_14 . V_15 ) ;
V_105:
F_45 ( & V_101 ) ;
V_103:
F_46 ( & V_100 ) ;
return V_19 ;
}
static int T_6 F_47 ( int V_23 )
{
T_7 V_106 ;
int V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
V_106 = F_4 ( V_23 , V_107 ) ;
if ( V_106 != V_108 ) {
F_48 ( L_11 ) ;
V_19 = - V_44 ;
goto exit;
}
V_106 = V_109 ? V_109 : F_4 ( V_23 , V_110 ) ;
switch ( V_106 ) {
case V_111 :
V_14 . type = V_33 ;
break;
case V_112 :
V_14 . type = V_35 ;
V_19 = F_22 ( 0 ) ;
break;
case V_113 :
case V_114 :
V_14 . type = V_37 ;
break;
case V_115 :
V_14 . type = V_38 ;
break;
case V_116 :
V_14 . type = V_39 ;
break;
case V_117 :
V_19 = - V_44 ;
goto exit;
case V_118 :
V_14 . type = V_40 ;
break;
case V_119 :
V_14 . type = V_41 ;
break;
default:
F_44 ( L_12 ,
( unsigned int ) V_106 ) ;
V_19 = - V_44 ;
goto exit;
}
F_44 ( L_13 ,
V_97 [ V_14 . type ] ,
( int ) F_1 ( V_23 , V_120 ) ) ;
exit:
F_14 ( V_23 ) ;
return V_19 ;
}
static int T_6 F_49 ( void )
{
static const unsigned short V_121 [] = { 0x2e , 0x4e } ;
int V_19 = - V_44 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_50 ( V_121 ) ; V_66 ++ ) {
V_19 = F_47 ( V_121 [ V_66 ] ) ;
if ( V_19 == 0 )
break;
}
if ( V_66 == F_50 ( V_121 ) )
return V_19 ;
return F_41 ( V_121 [ V_66 ] ) ;
}
static void T_8 F_51 ( void )
{
if ( F_27 () ) {
F_52 ( L_14 ) ;
F_25 () ;
}
F_45 ( & V_101 ) ;
F_46 ( & V_100 ) ;
}
