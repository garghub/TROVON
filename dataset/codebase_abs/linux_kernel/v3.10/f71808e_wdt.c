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
default:
V_19 = - V_40 ;
goto V_36;
}
F_13 ( V_14 . V_23 , V_24 ) ;
F_6 ( V_14 . V_23 , V_41 , 0 ) ;
F_6 ( V_14 . V_23 , V_42 ,
V_43 ) ;
F_6 ( V_14 . V_23 , V_25 ,
V_44 ) ;
if ( V_14 . V_22 ) {
T_1 V_45 = F_1 ( V_14 . V_23 ,
V_25 ) ;
V_45 = ( V_45 & 0xfc ) | ( V_14 . V_20 & 0x03 ) ;
V_45 |= F_24 ( V_46 ) ;
F_5 ( V_14 . V_23 , V_25 ,
V_45 ) ;
} else {
F_8 ( V_14 . V_23 , V_25 ,
V_46 ) ;
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
V_44 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_19 ;
}
static int F_26 ( void )
{
int V_47 = 0 ;
F_17 ( & V_14 . V_15 ) ;
V_47 = ( V_14 . V_48 ) ? V_49 : 0 ;
F_19 ( & V_14 . V_15 ) ;
return V_47 ;
}
static bool F_27 ( void )
{
bool V_50 = true ;
F_17 ( & V_14 . V_15 ) ;
if ( F_10 ( V_14 . V_23 ) )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
V_50 = ( F_1 ( V_14 . V_23 , V_41 ) & F_24 ( 0 ) )
&& ( F_1 ( V_14 . V_23 , V_25 )
& V_44 ) ;
F_14 ( V_14 . V_23 ) ;
V_21:
F_19 ( & V_14 . V_15 ) ;
return V_50 ;
}
static int F_28 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
int V_19 ;
if ( F_29 ( 0 , & V_14 . V_53 ) )
return - V_6 ;
V_19 = F_23 () ;
if ( V_19 ) {
F_30 ( 0 , & V_14 . V_53 ) ;
return V_19 ;
}
if ( V_54 )
F_31 ( V_55 ) ;
V_14 . V_56 = 0 ;
return F_32 ( V_51 , V_52 ) ;
}
static int F_33 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
F_30 ( 0 , & V_14 . V_53 ) ;
if ( ! V_14 . V_56 ) {
F_21 () ;
F_34 ( L_5 ) ;
} else if ( ! V_54 ) {
F_25 () ;
}
return 0 ;
}
static T_2 F_35 ( struct V_52 * V_52 , const char T_3 * V_57 ,
T_4 V_58 , T_5 * V_59 )
{
if ( V_58 ) {
if ( ! V_54 ) {
T_4 V_60 ;
bool V_56 = false ;
for ( V_60 = 0 ; V_60 != V_58 ; V_60 ++ ) {
char V_61 ;
if ( F_36 ( V_61 , V_57 + V_60 ) )
return - V_62 ;
V_56 = ( V_61 == 'V' ) ;
}
F_17 ( & V_14 . V_15 ) ;
V_14 . V_56 = V_56 ;
F_19 ( & V_14 . V_15 ) ;
}
F_21 () ;
}
return V_58 ;
}
static long F_37 ( struct V_52 * V_52 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_47 ;
int V_65 ;
int V_66 ;
union {
struct V_67 T_3 * V_68 ;
int T_3 * V_60 ;
} V_69 ;
V_69 . V_60 = ( int T_3 * ) V_64 ;
switch ( V_63 ) {
case V_70 :
return F_38 ( V_69 . V_68 , & V_14 . V_68 ,
sizeof( V_14 . V_68 ) ) ? - V_62 : 0 ;
case V_71 :
V_47 = F_26 () ;
if ( V_47 < 0 )
return V_47 ;
return F_39 ( V_47 , V_69 . V_60 ) ;
case V_72 :
return F_39 ( 0 , V_69 . V_60 ) ;
case V_73 :
if ( F_36 ( V_65 , V_69 . V_60 ) )
return - V_62 ;
if ( V_65 & V_74 )
F_25 () ;
if ( V_65 & V_75 )
return F_23 () ;
case V_76 :
F_21 () ;
return 0 ;
case V_77 :
if ( F_36 ( V_66 , V_69 . V_60 ) )
return - V_62 ;
if ( F_16 ( V_66 ) )
return - V_13 ;
F_21 () ;
case V_78 :
return F_39 ( V_14 . V_11 , V_69 . V_60 ) ;
default:
return - V_79 ;
}
}
static int F_40 ( struct V_80 * V_81 , unsigned long V_82 ,
void * V_83 )
{
if ( V_82 == V_84 || V_82 == V_85 )
F_25 () ;
return V_86 ;
}
static int T_6 F_41 ( int V_23 )
{
int V_45 , V_19 = 0 ;
V_14 . V_23 = V_23 ;
V_14 . V_68 . V_87 = V_77
| V_88
| V_89 ;
snprintf ( V_14 . V_68 . V_90 ,
sizeof( V_14 . V_68 . V_90 ) , L_6 ,
V_91 [ V_14 . type ] ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
F_13 ( V_14 . V_23 , V_24 ) ;
V_45 = F_1 ( V_23 , V_25 ) ;
V_14 . V_48 = V_45 & V_92 ;
F_14 ( V_23 ) ;
V_19 = F_16 ( V_11 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_20 ( V_93 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_42 ( & V_94 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_43 ( & V_95 ) ;
if ( V_19 ) {
F_12 ( L_7 ,
V_95 . V_96 ) ;
goto V_97;
}
if ( V_98 ) {
if ( V_98 <= 0
|| V_98 > V_12 ) {
F_12 ( L_8 ) ;
V_19 = - V_13 ;
goto V_99;
}
V_19 = F_23 () ;
if ( V_19 ) {
F_12 ( L_9 ) ;
goto V_99;
}
F_17 ( & V_14 . V_15 ) ;
V_19 = F_10 ( V_23 ) ;
if ( V_19 )
goto V_21;
F_13 ( V_14 . V_23 , V_24 ) ;
if ( V_98 > 0xff ) {
F_6 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
F_18 ( V_98 , 60 ) ) ;
} else {
F_8 ( V_23 , V_25 ,
V_26 ) ;
F_5 ( V_23 , V_27 ,
V_98 ) ;
}
F_14 ( V_23 ) ;
F_19 ( & V_14 . V_15 ) ;
if ( V_54 )
F_31 ( V_55 ) ;
F_44 ( L_10 ,
V_98 ) ;
}
return 0 ;
V_21:
F_19 ( & V_14 . V_15 ) ;
V_99:
F_45 ( & V_95 ) ;
V_97:
F_46 ( & V_94 ) ;
return V_19 ;
}
static int T_6 F_47 ( int V_23 )
{
T_7 V_100 ;
int V_19 = F_10 ( V_23 ) ;
if ( V_19 )
return V_19 ;
V_100 = F_4 ( V_23 , V_101 ) ;
if ( V_100 != V_102 ) {
F_48 ( L_11 ) ;
V_19 = - V_40 ;
goto exit;
}
V_100 = V_103 ? V_103 : F_4 ( V_23 , V_104 ) ;
switch ( V_100 ) {
case V_105 :
V_14 . type = V_33 ;
break;
case V_106 :
V_14 . type = V_35 ;
V_19 = F_22 ( 0 ) ;
break;
case V_107 :
case V_108 :
V_14 . type = V_37 ;
break;
case V_109 :
V_14 . type = V_38 ;
break;
case V_110 :
V_14 . type = V_39 ;
break;
case V_111 :
V_19 = - V_40 ;
goto exit;
default:
F_44 ( L_12 ,
( unsigned int ) V_100 ) ;
V_19 = - V_40 ;
goto exit;
}
F_44 ( L_13 ,
V_91 [ V_14 . type ] ,
( int ) F_1 ( V_23 , V_112 ) ) ;
exit:
F_14 ( V_23 ) ;
return V_19 ;
}
static int T_6 F_49 ( void )
{
static const unsigned short V_113 [] = { 0x2e , 0x4e } ;
int V_19 = - V_40 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_50 ( V_113 ) ; V_60 ++ ) {
V_19 = F_47 ( V_113 [ V_60 ] ) ;
if ( V_19 == 0 )
break;
}
if ( V_60 == F_50 ( V_113 ) )
return V_19 ;
return F_41 ( V_113 [ V_60 ] ) ;
}
static void T_8 F_51 ( void )
{
if ( F_27 () ) {
F_52 ( L_14 ) ;
F_25 () ;
}
F_45 ( & V_95 ) ;
F_46 ( & V_94 ) ;
}
