static void F_1 ( unsigned int V_1 )
{
V_2 |= V_1 ;
V_3 = V_2 ;
}
static void F_2 ( unsigned int V_1 )
{
V_2 &= ~ V_1 ;
V_3 = V_2 ;
}
static void F_3 ( int V_4 )
{
if ( V_4 )
F_1 ( V_5 ) ;
else
F_2 ( V_5 ) ;
}
static T_1 F_4 ( void )
{
T_1 V_6 , V_7 ;
unsigned long V_8 ;
F_5 ( V_8 ) ;
V_9 = 0 ;
V_6 = V_9 ;
V_9 = 0xff ;
V_7 = V_9 ;
V_6 = ( V_6 != V_7 || V_6 == 0xff ) ? 0 : V_6 ;
F_6 ( V_8 ) ;
return V_6 ;
}
static int F_7 ( void )
{
F_1 ( V_10 ) ;
return 0 ;
}
static void F_8 ( void )
{
F_2 ( V_10 ) ;
}
static void F_9 ( unsigned long V_11 , int V_12 )
{
int V_13 = 0 ;
unsigned int V_14 = 0 ;
const char * V_15 ;
if ( V_11 < 200000 ) {
V_15 = L_1 ; V_14 = 0xfff ;
} else if ( V_11 < 300000 ) {
V_15 = L_2 ; V_14 = 0xde5 ;
} else {
V_15 = L_3 ; V_14 = 0x325 ;
}
F_10 ( L_4 ,
V_15 , ( int ) V_11 / 1000 , ( int ) V_11 % 1000 ) ;
#define F_11 0x100
do {
int V_16 ;
if ( V_12 )
V_16 = V_14 ;
else if ( V_17 < V_14 - F_11 )
V_16 = V_17 + F_11 ;
else if ( V_17 > V_14 + F_11 )
V_16 = V_17 - F_11 ;
else
V_16 = V_14 ;
V_12 = 0 ;
F_12 ( V_18 , 0 ) ;
F_12 ( V_19 , 0 ) ;
for ( V_13 = 1 << 11 ; V_13 > 0 ; V_13 >>= 1 ) {
F_13 ( 1 ) ;
F_12 ( V_20 , V_16 & V_13 ) ;
F_13 ( 1 ) ;
F_12 ( V_18 , 1 ) ;
F_13 ( 1 ) ;
F_12 ( V_18 , 0 ) ;
}
F_13 ( 1 ) ;
F_12 ( V_19 , 1 ) ;
F_13 ( 1 ) ;
F_12 ( V_19 , 0 ) ;
V_17 = V_16 ;
} while ( V_17 != V_14 );
}
static inline int F_14 ( unsigned int V_21 )
{
return V_22 [ V_21 - F_15 ( 0 ) ] ;
}
static inline int F_16 ( int V_1 )
{
return V_23 [ V_1 ] + F_15 ( 0 ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
int V_26 = F_14 ( V_25 -> V_21 ) ;
if ( V_26 & 0xff )
V_27 = V_26 ;
else
V_28 = ( V_26 >> 8 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
V_29 &= ~ ( F_14 ( V_25 -> V_21 ) ) ;
}
static void F_19 ( struct V_24 * V_25 )
{
V_29 |= F_14 ( V_25 -> V_21 ) ;
}
static inline unsigned long F_20 ( void )
{
return ( V_28 << 8 | V_27 ) &
V_29 ;
}
static void F_21 ( struct V_30 * V_31 )
{
unsigned int V_21 ;
unsigned long V_32 ;
V_32 = F_20 () ;
do {
V_31 -> V_24 . V_33 -> V_34 ( & V_31 -> V_24 ) ;
if ( F_22 ( V_32 ) ) {
V_21 = F_16 ( F_23 ( V_32 ) ) ;
F_24 ( V_21 ) ;
}
V_32 = F_20 () ;
} while ( V_32 );
}
static void T_2 F_25 ( void )
{
int V_35 ;
int V_36 ;
F_26 () ;
for ( V_35 = 0 ; V_35 < F_27 ( V_23 ) ; V_35 ++ ) {
V_36 = F_16 ( V_35 ) ;
F_28 ( V_36 , & V_37 ,
V_38 ) ;
F_29 ( V_36 , V_39 | V_40 ) ;
}
F_30 ( F_31 ( V_41 ) ,
F_21 ) ;
F_32 ( F_31 ( V_41 ) , V_42 ) ;
}
static int F_33 ( struct V_43 * V_44 )
{
int V_45 ;
V_45 = F_34 ( V_46 , L_5 ) ;
if ( V_45 )
goto V_47;
V_45 = F_34 ( V_48 , L_6 ) ;
if ( V_45 )
goto V_49;
V_45 = F_35 ( V_46 , 0 ) ;
if ( V_45 )
goto V_50;
V_45 = F_35 ( V_48 , 0 ) ;
if ( V_45 )
goto V_50;
return 0 ;
V_50:
F_36 ( V_48 ) ;
V_49:
F_36 ( V_46 ) ;
V_47:
F_37 ( V_44 , L_7 ) ;
return V_45 ;
}
static int F_38 ( struct V_43 * V_44 , int V_51 )
{
F_12 ( V_48 , ! ! V_51 ) ;
F_12 ( V_46 , ! ! V_51 ) ;
return V_51 ;
}
static void F_39 ( struct V_43 * V_44 )
{
F_36 ( V_48 ) ;
F_36 ( V_46 ) ;
}
static void F_40 ( struct V_43 * V_44 , int V_52 )
{
F_41 ( V_52 ) ;
}
static int T_2 F_42 ( char * V_53 )
{
return F_43 ( V_53 , 10 , & V_54 ) >= 0 ;
}
static void T_2 F_44 ( void )
{
struct V_55 * V_56 ;
struct V_57 V_58 = {
. V_59 = V_60 ,
. V_61 = V_62 ,
. F_13 = 10 ,
. V_63 = V_64 ,
} ;
char * V_65 ;
if ( ! V_54 )
return;
V_56 = F_45 ( L_8 , 2 ) ;
if ( V_56 ) {
if ( ! F_46 ( V_56 ,
& V_58 ,
sizeof( V_58 ) ) ) {
if ( F_47 ( V_56 ) ) {
V_65 = L_9 ;
goto V_66;
}
} else {
V_65 = L_10 ;
goto V_66;
}
} else {
V_65 = L_11 ;
goto V_67;
}
return;
V_66:
F_48 ( V_56 ) ;
V_67:
F_49 ( L_12 , V_65 ) ;
}
static void T_2 F_50 ( void )
{
if ( F_34 ( V_20 , L_13 ) )
goto V_68;
if ( F_34 ( V_18 , L_14 ) )
goto V_69;
if ( F_34 ( V_19 , L_15 ) )
goto V_70;
if ( F_35 ( V_20 , 0 ) ||
F_35 ( V_18 , 0 ) ||
F_35 ( V_19 , 0 ) )
goto V_50;
F_9 ( F_51 ( 0 ) , 1 ) ;
return;
V_50:
F_36 ( V_19 ) ;
V_70:
F_36 ( V_18 ) ;
V_69:
F_36 ( V_20 ) ;
V_68:
F_49 ( L_16 ) ;
}
static void T_2 F_52 ( void )
{
if ( F_34 ( V_71 , L_17 ) )
goto V_72;
if ( F_35 ( V_71 , 0 ) )
goto V_50;
return;
V_50:
F_36 ( V_71 ) ;
V_72:
F_49 ( L_18 ) ;
}
static int F_53 ( struct V_73 * V_74 ,
unsigned long V_75 , void * V_76 )
{
struct V_77 * V_78 = V_76 ;
switch ( V_75 ) {
case V_79 :
if ( V_78 -> V_80 < V_78 -> V_81 ) {
F_9 ( V_78 -> V_81 , 0 ) ;
}
break;
case V_82 :
if ( V_78 -> V_80 > V_78 -> V_81 ) {
F_9 ( V_78 -> V_81 , 0 ) ;
}
break;
default:
break;
}
return 0 ;
}
static void T_2 F_54 ( void )
{
if ( F_55 ( & V_83 ,
V_84 ) )
F_49 ( L_19 ) ;
}
static inline void F_54 ( void ) {}
static void F_56 ( void )
{
F_57 ( L_20 ) ;
F_12 ( V_85 , 1 ) ;
while ( 1 ) ;
}
static void T_2 F_58 ( void )
{
T_1 V_86 ;
V_87 = F_56 ;
F_59 ( F_60 ( V_88 ) ) ;
F_61 ( NULL ) ;
F_62 ( NULL ) ;
F_63 ( NULL ) ;
F_52 () ;
F_64 ( NULL , & V_89 ) ;
V_86 = F_4 () ;
if ( V_86 == 0 )
V_90 . V_91 -- ;
F_65 ( NULL ) ;
F_66 ( V_92 , F_27 ( V_92 ) ) ;
F_50 () ;
F_54 () ;
F_67 ( & V_93 ) ;
if ( V_86 ) {
F_68 ( L_21
L_22 ,
F_69 ( V_86 ) ,
F_70 ( V_86 ) ,
F_71 ( V_86 ) ) ;
V_94 = ( F_69 ( V_86 ) << 8 ) |
( F_70 ( V_86 ) << 4 ) |
F_71 ( V_86 ) ;
} else {
F_68 ( L_23 ) ;
}
F_72 ( 1 , F_60 ( V_95 ) ) ;
F_44 () ;
F_73 ( NULL ) ;
}
static void T_2 F_74 ( void )
{
F_75 () ;
F_76 ( V_96 , F_27 ( V_96 ) ) ;
V_97 |= V_98 ;
}
