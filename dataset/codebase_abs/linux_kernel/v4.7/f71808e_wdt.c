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
default:
V_19 = - V_41 ;
goto V_36;
}
F_13 ( V_14 . V_23 , V_24 ) ;
F_6 ( V_14 . V_23 , V_42 , 0 ) ;
if ( V_14 . type == V_40 )
F_6 ( V_14 . V_23 , V_43 ,
V_44 ) ;
else
F_6 ( V_14 . V_23 , V_45 ,
V_46 ) ;
F_6 ( V_14 . V_23 , V_25 ,
V_47 ) ;
if ( V_14 . V_22 ) {
T_1 V_48 = F_1 ( V_14 . V_23 ,
V_25 ) ;
V_48 = ( V_48 & 0xfc ) | ( V_14 . V_20 & 0x03 ) ;
V_48 |= F_24 ( V_49 ) ;
F_5 ( V_14 . V_23 , V_25 ,
V_48 ) ;
} else {
F_8 ( V_14 . V_23 , V_25 ,
V_49 ) ;
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
V_47 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_26 ( void )
{
int V_50 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_50 = ( V_14 . V_51 ) ? V_52 : 0 ;
F_19 ( & V_14 . V_15 ) ;
return V_50 ;
}
static bool F_27 ( void )
{
bool V_53 = true ;
F_17 ( & V_14 . V_15 ) ;
if ( F_10 ( V_14 . V_23 ) )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
V_53 = ( F_1 ( V_14 . V_23 , V_42 ) & F_24 ( 0 ) )
&& ( F_1 ( V_14 . V_23 , V_25 )
& V_47 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_53 ;
}
static int F_28 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
int V_19 ;
if ( F_29 ( 0 , & V_14 . V_56 ) )
return - V_6 ;
V_19 = F_23 () ;
if ( V_19 ) {
F_30 ( 0 , & V_14 . V_56 ) ;
return V_19 ;
}
if ( V_57 )
F_31 ( V_58 ) ;
V_14 . V_59 = 0 ;
return F_32 ( V_54 , V_55 ) ;
}
static int F_33 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
F_30 ( 0 , & V_14 . V_56 ) ;
if ( ! V_14 . V_59 ) {
F_21 () ;
F_34 ( L_5 ) ;
} else if ( ! V_57 ) {
F_25 () ;
}
return 0 ;
}
static T_2 F_35 ( struct V_55 * V_55 , const char T_3 * V_60 ,
T_4 V_61 , T_5 * V_62 )
{
if ( V_61 ) {
if ( ! V_57 ) {
T_4 V_63 ;
bool V_59 = false ;
for ( V_63 = 0 ; V_63 != V_61 ; V_63 ++ ) {
char V_64 ;
if ( F_36 ( V_64 , V_60 + V_63 ) )
return - V_65 ;
V_59 = ( V_64 == 'V' ) ;
}
F_17 ( & V_14 . V_15 ) ;
V_14 . V_59 = V_59 ;
F_19 ( & V_14 . V_15 ) ;
}
F_21 () ;
}
return V_61 ;
}
static long F_37 ( struct V_55 * V_55 , unsigned int V_66 ,
unsigned long V_67 )
{
int V_50 ;
int V_68 ;
int V_69 ;
union {
struct V_70 T_3 * V_71 ;
int T_3 * V_63 ;
} V_72 ;
V_72 . V_63 = ( int T_3 * ) V_67 ;
switch ( V_66 ) {
case V_73 :
return F_38 ( V_72 . V_71 , & V_14 . V_71 ,
sizeof( V_14 . V_71 ) ) ? - V_65 : 0 ;
case V_74 :
V_50 = F_26 () ;
if ( V_50 < 0 )
return V_50 ;
return F_39 ( V_50 , V_72 . V_63 ) ;
case V_75 :
return F_39 ( 0 , V_72 . V_63 ) ;
case V_76 :
if ( F_36 ( V_68 , V_72 . V_63 ) )
return - V_65 ;
if ( V_68 & V_77 )
F_25 () ;
if ( V_68 & V_78 )
return F_23 () ;
case V_79 :
F_21 () ;
return 0 ;
case V_80 :
if ( F_36 ( V_69 , V_72 . V_63 ) )
return - V_65 ;
if ( F_16 ( V_69 ) )
return - V_13 ;
F_21 () ;
case V_81 :
return F_39 ( V_14 . V_11 , V_72 . V_63 ) ;
default:
return - V_82 ;
}
}
static int F_40 ( struct V_83 * V_84 , unsigned long V_85 ,
void * V_86 )
{
if ( V_85 == V_87 || V_85 == V_88 )
F_25 () ;
return V_89 ;
}
static int T_6 F_41 ( int V_23 )
{
int V_48 , V_19 = 0 ;
V_14 . V_23 = V_23 ;
V_14 . V_71 . V_90 = V_80
| V_91
| V_92 ;
snprintf ( V_14 . V_71 . V_93 ,
sizeof( V_14 . V_71 . V_93 ) , L_6 ,
V_94 [ V_14 . type ] ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
F_13 ( V_14 . V_23 , V_24 ) ;
V_48 = F_1 ( V_23 , V_25 ) ;
V_14 . V_51 = V_48 & F_24 ( V_95 ) ;
F_14 ( V_23 ) ;
V_19 = F_16 ( V_11 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_20 ( V_96 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_42 ( & V_97 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_43 ( & V_98 ) ;
if ( V_19 ) {
F_12 ( L_7 ,
V_98 . V_99 ) ;
goto V_100;
}
if ( V_101 ) {
if ( V_101 <= 0
|| V_101 > V_12 ) {
F_12 ( L_8 ) ;
V_19 = - V_13 ;
goto V_102;
}
V_19 = F_23 () ;
if ( V_19 ) {
F_12 ( L_9 ) ;
goto V_102;
}
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
if ( V_101 > 0xff ) {
F_6 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
F_18 ( V_101 , 60 ) ) ;
} else {
F_8 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
V_101 ) ;
}
F_14 ( V_23 ) ;
F_19 ( & V_14 . V_15 ) ;
if ( V_57 )
F_31 ( V_58 ) ;
F_44 ( L_10 ,
V_101 ) ;
}
return 0 ;
V_21:
F_19 ( & V_14 . V_15 ) ;
V_102:
F_45 ( & V_98 ) ;
V_100:
F_46 ( & V_97 ) ;
return V_19 ;
}
static int T_6 F_47 ( int V_23 )
{
T_7 V_103 ;
int V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
V_103 = F_4 ( V_23 , V_104 ) ;
if ( V_103 != V_105 ) {
F_48 ( L_11 ) ;
V_19 = - V_41 ;
goto exit;
}
V_103 = V_106 ? V_106 : F_4 ( V_23 , V_107 ) ;
switch ( V_103 ) {
case V_108 :
V_14 . type = V_33 ;
break;
case V_109 :
V_14 . type = V_35 ;
V_19 = F_22 ( 0 ) ;
break;
case V_110 :
case V_111 :
V_14 . type = V_37 ;
break;
case V_112 :
V_14 . type = V_38 ;
break;
case V_113 :
V_14 . type = V_39 ;
break;
case V_114 :
V_19 = - V_41 ;
goto exit;
case V_115 :
V_14 . type = V_40 ;
break;
default:
F_44 ( L_12 ,
( unsigned int ) V_103 ) ;
V_19 = - V_41 ;
goto exit;
}
F_44 ( L_13 ,
V_94 [ V_14 . type ] ,
( int ) F_1 ( V_23 , V_116 ) ) ;
exit:
F_14 ( V_23 ) ;
return V_19 ;
}
static int T_6 F_49 ( void )
{
static const unsigned short V_117 [] = { 0x2e , 0x4e } ;
int V_19 = - V_41 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < F_50 ( V_117 ) ; V_63 ++ ) {
V_19 = F_47 ( V_117 [ V_63 ] ) ;
if ( V_19 == 0 )
break;
}
if ( V_63 == F_50 ( V_117 ) )
return V_19 ;
return F_41 ( V_117 [ V_63 ] ) ;
}
static void T_8 F_51 ( void )
{
if ( F_27 () ) {
F_52 ( L_14 ) ;
F_25 () ;
}
F_45 ( & V_98 ) ;
F_46 ( & V_97 ) ;
}
