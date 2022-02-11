static inline unsigned int F_1 ( int V_1 )
{
return ( V_1 * 10 ) / 6 ;
}
static void F_2 ( void )
{
T_1 V_2 ;
if ( V_3 . V_4 == 2 ) {
V_2 = F_3 ( V_3 . V_5 ) ;
V_2 |= 0x00000020 ;
F_4 ( V_2 , V_3 . V_5 ) ;
} else if ( V_3 . V_4 == 1 ) {
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
V_2 |= 0x00000002 ;
F_6 ( V_3 . V_6 , 0xd4 , V_2 ) ;
}
}
static int F_7 ( void )
{
int V_7 = 0 ;
T_1 V_2 ;
if ( V_3 . V_4 == 2 ) {
V_2 = F_3 ( V_3 . V_5 ) ;
V_2 &= 0xffffffdf ;
F_4 ( V_2 , V_3 . V_5 ) ;
V_2 = F_3 ( V_3 . V_5 ) ;
if ( V_2 & 0x00000020 )
V_7 = - V_8 ;
} else if ( V_3 . V_4 == 1 ) {
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
V_2 &= 0xfffffffd ;
F_6 ( V_3 . V_6 , 0xd4 , V_2 ) ;
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
if ( V_2 & 0x00000002 )
V_7 = - V_8 ;
}
return V_7 ;
}
static int F_8 ( void )
{
unsigned int V_9 ;
F_9 ( & V_3 . V_10 ) ;
F_10 ( V_3 . V_11 , V_12 ) ;
if ( F_7 () ) {
F_11 ( & V_3 . V_10 ) ;
F_12 ( L_1 ) ;
return - V_8 ;
}
if ( V_3 . V_4 == 2 )
F_13 ( 0x01 , V_13 ) ;
else if ( V_3 . V_4 == 1 )
F_14 ( 0x01 , V_13 ) ;
V_9 = F_15 ( V_14 ) ;
V_9 &= 0xf7ff ;
F_13 ( V_9 , V_14 ) ;
V_9 = F_15 ( V_14 ) ;
F_11 ( & V_3 . V_10 ) ;
if ( V_9 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_16 ( void )
{
unsigned int V_9 ;
F_9 ( & V_3 . V_10 ) ;
F_17 ( V_3 . V_11 ) ;
V_9 = F_15 ( V_14 ) ;
V_9 |= 0x0800 ;
F_13 ( V_9 , V_14 ) ;
V_9 = F_15 ( V_14 ) ;
F_2 () ;
F_11 ( & V_3 . V_10 ) ;
if ( ( V_9 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_18 ( void )
{
F_9 ( & V_3 . V_10 ) ;
F_19 ( V_3 . V_11 , V_12 ) ;
if ( V_3 . V_4 == 2 )
F_13 ( 0x01 , V_13 ) ;
else if ( V_3 . V_4 == 1 ) {
F_13 ( 0x0008 , V_15 ) ;
F_14 ( 0x01 , V_13 ) ;
}
F_11 ( & V_3 . V_10 ) ;
return 0 ;
}
static int F_20 ( int V_16 )
{
unsigned int V_17 ;
unsigned char V_18 ;
unsigned int V_19 ;
V_19 = F_1 ( V_16 ) ;
if ( V_3 . V_4 == 1 )
V_19 /= 2 ;
if ( V_19 < 0x04 )
return - V_20 ;
if ( ( ( V_3 . V_4 == 2 ) && ( V_19 > 0x3ff ) ) ||
( ( V_3 . V_4 == 1 ) && ( V_19 > 0x03f ) ) )
return - V_20 ;
F_21 ( V_19 ) ;
if ( V_3 . V_4 == 2 ) {
F_9 ( & V_3 . V_10 ) ;
V_17 = F_15 ( V_21 ) ;
V_17 &= 0xfc00 ;
V_17 |= V_19 ;
F_13 ( V_17 , V_21 ) ;
V_17 = F_15 ( V_21 ) ;
F_11 ( & V_3 . V_10 ) ;
if ( ( V_17 & 0x3ff ) != V_19 )
return - V_20 ;
} else if ( V_3 . V_4 == 1 ) {
F_9 ( & V_3 . V_10 ) ;
V_18 = F_22 ( V_22 ) ;
V_18 &= 0xc0 ;
V_18 |= ( V_19 & 0xff ) ;
F_14 ( V_18 , V_22 ) ;
V_18 = F_22 ( V_22 ) ;
F_11 ( & V_3 . V_10 ) ;
if ( ( V_18 & 0x3f ) != V_19 )
return - V_20 ;
}
V_12 = V_16 ;
return 0 ;
}
static int F_23 ( int * V_23 )
{
unsigned int V_17 ;
unsigned char V_18 ;
if ( V_3 . V_4 == 2 ) {
F_9 ( & V_3 . V_10 ) ;
V_17 = F_15 ( V_13 ) ;
V_17 &= 0x3ff ;
F_11 ( & V_3 . V_10 ) ;
* V_23 = ( V_17 * 6 ) / 10 ;
} else if ( V_3 . V_4 == 1 ) {
F_9 ( & V_3 . V_10 ) ;
V_18 = F_22 ( V_13 ) ;
V_18 &= 0x3f ;
if ( ! ( F_15 ( V_15 ) & 0x0008 ) )
V_18 += ( F_22 ( V_22 ) & 0x3f ) ;
F_11 ( & V_3 . V_10 ) ;
* V_23 = ( V_18 * 6 ) / 10 ;
} else
return - V_20 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
if ( F_25 ( 0 , & V_26 ) )
return - V_27 ;
F_8 () ;
return F_26 ( V_24 , V_25 ) ;
}
static int F_27 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
if ( V_28 == 42 ) {
F_16 () ;
} else {
F_28 ( L_2 ) ;
F_18 () ;
}
F_29 ( 0 , & V_26 ) ;
V_28 = 0 ;
return 0 ;
}
static T_2 F_30 ( struct V_25 * V_25 , const char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
if ( V_30 ) {
if ( ! V_32 ) {
T_4 V_33 ;
V_28 = 0 ;
for ( V_33 = 0 ; V_33 != V_30 ; V_33 ++ ) {
char V_34 ;
if ( F_31 ( V_34 , V_29 + V_33 ) )
return - V_35 ;
if ( V_34 == 'V' )
V_28 = 42 ;
}
}
F_18 () ;
}
return V_30 ;
}
static long F_32 ( struct V_25 * V_25 , unsigned int V_36 ,
unsigned long V_37 )
{
int V_38 , V_39 = - V_20 ;
int V_40 ;
void T_3 * V_41 = ( void T_3 * ) V_37 ;
int T_3 * V_42 = V_41 ;
static const struct V_43 V_44 = {
. V_45 = V_46 |
V_47 |
V_48 ,
. V_49 = 0 ,
. V_50 = V_51 ,
} ;
switch ( V_36 ) {
case V_52 :
return F_33 ( V_41 , & V_44 , sizeof( V_44 ) ) ? - V_35 : 0 ;
case V_53 :
case V_54 :
return F_34 ( 0 , V_42 ) ;
case V_55 :
{
if ( F_31 ( V_38 , V_42 ) )
return - V_35 ;
if ( V_38 & V_56 ) {
F_16 () ;
V_39 = 0 ;
}
if ( V_38 & V_57 ) {
F_18 () ;
F_8 () ;
V_39 = 0 ;
}
return V_39 ;
}
case V_58 :
F_18 () ;
return 0 ;
case V_59 :
{
if ( F_31 ( V_40 , V_42 ) )
return - V_35 ;
if ( F_20 ( V_40 ) )
return - V_20 ;
F_18 () ;
}
case V_60 :
return F_34 ( V_12 , V_42 ) ;
case V_61 :
{
int V_23 ;
if ( F_23 ( & V_23 ) )
return - V_20 ;
return F_34 ( V_23 , V_42 ) ;
}
default:
return - V_62 ;
}
}
static void T_6 F_35 ( void )
{
if ( ! V_32 )
F_16 () ;
F_36 ( & V_63 ) ;
F_37 ( V_3 . V_64 -> V_65 ,
F_38 ( V_3 . V_64 ) ) ;
F_37 ( V_3 . V_11 -> V_65 ,
F_38 ( V_3 . V_11 ) ) ;
if ( V_3 . V_4 == 2 ) {
F_39 ( V_3 . V_5 ) ;
F_40 ( V_3 . V_66 -> V_65 ,
F_38 ( V_3 . V_66 ) ) ;
}
V_3 . V_64 = NULL ;
V_3 . V_11 = NULL ;
V_3 . V_66 = NULL ;
V_3 . V_5 = NULL ;
}
static int T_7 F_41 ( struct V_67 * V_68 )
{
int V_7 = - V_69 ;
unsigned long V_2 ;
struct V_70 * V_71 = V_68 -> V_68 . V_72 ;
if ( ! V_71 )
goto V_73;
F_42 ( & V_3 . V_10 ) ;
V_3 . V_64 =
F_43 ( V_68 , V_74 , V_75 ) ;
if ( ! V_3 . V_64 )
goto V_73;
V_3 . V_11 =
F_43 ( V_68 , V_74 , V_76 ) ;
if ( ! V_3 . V_11 )
goto V_73;
V_3 . V_4 = V_71 -> V_4 ;
V_3 . V_68 = V_68 ;
V_3 . V_6 = F_44 ( V_68 -> V_68 . V_77 ) ;
if ( V_3 . V_4 == 2 ) {
V_3 . V_66 = F_43 ( V_68 ,
V_78 ,
V_79 ) ;
if ( ! V_3 . V_66 )
goto V_73;
if ( ! F_45 ( V_3 . V_66 -> V_65 ,
F_38 ( V_3 . V_66 ) , V_68 -> V_80 ) ) {
V_7 = - V_27 ;
goto V_73;
}
V_3 . V_5 = F_46 ( V_3 . V_66 -> V_65 ,
F_38 ( V_3 . V_66 ) ) ;
if ( ! V_3 . V_5 ) {
V_7 = - V_8 ;
goto V_81;
}
}
if ( F_7 () && F_47 () ) {
F_48 ( L_3 ) ;
V_7 = - V_69 ;
goto V_82;
}
F_2 () ;
if ( ! F_49 ( V_3 . V_11 -> V_65 ,
F_38 ( V_3 . V_11 ) , V_68 -> V_80 ) ) {
F_12 ( L_4 ,
( V_83 ) V_84 ) ;
V_7 = - V_27 ;
goto V_82;
}
if ( V_85 >= V_3 . V_4 ) {
V_2 = F_50 ( V_84 ) ;
V_2 &= 0xffffdfff ;
F_51 ( V_2 , V_84 ) ;
}
if ( ! F_49 ( V_3 . V_64 -> V_65 ,
F_38 ( V_3 . V_64 ) , V_68 -> V_80 ) ) {
F_12 ( L_4 ,
( V_83 ) V_86 ) ;
V_7 = - V_27 ;
goto V_87;
}
F_48 ( L_5 ,
V_71 -> V_80 , V_71 -> V_4 , ( V_83 ) V_86 ) ;
F_13 ( 0x0008 , V_15 ) ;
F_13 ( 0x0002 , V_88 ) ;
F_13 ( 0x0004 , V_88 ) ;
F_16 () ;
if ( F_20 ( V_12 ) ) {
F_20 ( V_89 ) ;
F_48 ( L_6 , V_12 ) ;
}
V_7 = F_52 ( & V_63 ) ;
if ( V_7 != 0 ) {
F_12 ( L_7 ,
V_90 , V_7 ) ;
goto V_91;
}
F_48 ( L_8 ,
V_12 , V_32 ) ;
return 0 ;
V_91:
F_37 ( V_3 . V_64 -> V_65 ,
F_38 ( V_3 . V_64 ) ) ;
V_87:
F_37 ( V_3 . V_11 -> V_65 ,
F_38 ( V_3 . V_11 ) ) ;
V_82:
if ( V_3 . V_4 == 2 )
F_39 ( V_3 . V_5 ) ;
V_81:
if ( V_3 . V_4 == 2 )
F_40 ( V_3 . V_66 -> V_65 ,
F_38 ( V_3 . V_66 ) ) ;
V_73:
V_3 . V_64 = NULL ;
V_3 . V_11 = NULL ;
V_3 . V_66 = NULL ;
V_3 . V_5 = NULL ;
return V_7 ;
}
static int T_6 F_53 ( struct V_67 * V_68 )
{
if ( V_3 . V_64 || V_3 . V_11 )
F_35 () ;
return 0 ;
}
static void F_54 ( struct V_67 * V_68 )
{
F_16 () ;
}
static int T_8 F_55 ( void )
{
int V_92 ;
F_48 ( L_9 , V_93 ) ;
V_92 = F_56 ( & V_94 ) ;
if ( V_92 )
return V_92 ;
return 0 ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_94 ) ;
F_48 ( L_10 ) ;
}
