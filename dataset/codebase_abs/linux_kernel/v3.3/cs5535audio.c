static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned int V_4 ;
do {
V_4 = F_2 ( V_2 , V_5 ) ;
if ( ! ( V_4 & V_6 ) )
break;
F_3 ( 1 ) ;
} while ( -- V_3 );
if ( ! V_3 )
F_4 ( V_7 L_1 ) ;
}
static unsigned short F_5 ( struct V_1 * V_2 ,
unsigned short V_8 )
{
unsigned int V_9 ;
unsigned int V_3 ;
unsigned int V_10 ;
V_9 = ( ( unsigned int ) V_8 ) << 24 ;
V_9 |= V_11 ;
V_9 |= V_6 ;
F_6 ( V_2 , V_5 , V_9 ) ;
F_1 ( V_2 , 50 ) ;
V_3 = 50 ;
do {
V_10 = F_2 ( V_2 , V_12 ) ;
if ( ( V_10 & V_13 ) && V_8 == ( V_10 >> 24 ) )
break;
F_3 ( 1 ) ;
} while ( -- V_3 );
if ( ! V_3 )
F_4 ( V_7 L_2
L_3 , V_8 , V_10 ) ;
return ( unsigned short ) V_10 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned short V_8 , unsigned short V_10 )
{
unsigned int V_9 ;
V_9 = ( ( unsigned int ) V_8 ) << 24 ;
V_9 |= V_10 ;
V_9 &= V_14 ;
V_9 |= V_6 ;
V_9 &= V_15 ;
F_6 ( V_2 , V_5 , V_9 ) ;
F_1 ( V_2 , 50 ) ;
}
static void F_8 ( struct V_16 * V_17 ,
unsigned short V_8 , unsigned short V_10 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
F_7 ( V_2 , V_8 , V_10 ) ;
}
static unsigned short F_9 ( struct V_16 * V_17 ,
unsigned short V_8 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
return F_5 ( V_2 , V_8 ) ;
}
static int T_1 F_10 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 ;
struct V_23 V_17 ;
int V_24 ;
static struct V_25 V_26 = {
. V_27 = F_8 ,
. V_28 = F_9 ,
} ;
if ( ( V_24 = V_21 ( V_20 , 0 , & V_26 , NULL , & V_22 ) ) < 0 )
return V_24 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_29 = V_30 | V_31
| V_32 ;
V_17 . V_18 = V_2 ;
V_17 . V_33 = V_2 -> V_33 ;
F_11 ( V_20 , & V_17 ) ;
if ( ( V_24 = F_12 ( V_22 , & V_17 , & V_2 -> V_17 ) ) < 0 ) {
F_4 ( V_7 L_4 ) ;
return V_24 ;
}
F_13 ( V_2 -> V_17 , V_34 , V_35 ) ;
V_24 = F_14 ( V_20 , V_2 -> V_17 ) ;
if ( V_24 < 0 ) {
F_4 ( V_7 L_5 ) ;
return V_24 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_36 ;
F_16 ( & V_2 -> V_37 ) ;
V_36 = F_17 ( V_2 , V_38 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( V_36 & V_39 ) {
struct V_40 * V_41 ;
V_41 = V_2 -> V_42 -> V_43 -> V_18 ;
F_19 ( V_2 -> V_42 ) ;
} else {
F_4 ( V_7 L_6 ,
V_36 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_36 ;
F_16 ( & V_2 -> V_37 ) ;
V_36 = F_17 ( V_2 , V_44 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( V_36 & V_39 ) {
struct V_40 * V_41 ;
V_41 = V_2 -> V_45 -> V_43 -> V_18 ;
F_19 ( V_2 -> V_45 ) ;
}
}
static T_3 F_21 ( int V_46 , void * V_47 )
{
T_4 V_48 ;
unsigned char V_49 ;
struct V_1 * V_2 = V_47 ;
if ( V_2 == NULL )
return V_50 ;
V_48 = F_22 ( V_2 , V_51 ) ;
if ( ! V_48 )
return V_50 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_48 & ( 1 << V_49 ) ) {
switch ( V_49 ) {
case V_52 :
F_2 ( V_2 , V_53 ) ;
break;
case V_54 :
F_2 ( V_2 , V_53 ) ;
break;
case V_55 :
F_15 ( V_2 ) ;
break;
case V_56 :
F_20 ( V_2 ) ;
break;
default:
F_4 ( V_7 L_7
L_8 , V_48 ) ;
break;
}
}
}
return V_57 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_46 ) ;
F_25 ( V_2 -> V_33 , 3 ) ;
if ( V_2 -> V_46 >= 0 )
F_26 ( V_2 -> V_46 , V_2 ) ;
F_27 ( V_2 -> V_33 ) ;
F_28 ( V_2 -> V_33 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
return F_23 ( V_2 ) ;
}
static int T_1 F_31 ( struct V_19 * V_20 ,
struct V_61 * V_33 ,
struct V_1 * * V_62 )
{
struct V_1 * V_2 ;
int V_24 ;
static struct V_63 V_26 = {
. V_64 = F_30 ,
} ;
* V_62 = NULL ;
if ( ( V_24 = F_32 ( V_33 ) ) < 0 )
return V_24 ;
if ( F_33 ( V_33 , F_34 ( 32 ) ) < 0 ||
F_35 ( V_33 , F_34 ( 32 ) ) < 0 ) {
F_36 ( V_65 L_9 ) ;
V_24 = - V_66 ;
goto V_67;
}
V_2 = F_37 ( sizeof( * V_2 ) , V_68 ) ;
if ( V_2 == NULL ) {
V_24 = - V_69 ;
goto V_67;
}
F_38 ( & V_2 -> V_37 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_46 = - 1 ;
if ( ( V_24 = F_39 ( V_33 , L_10 ) ) < 0 ) {
F_29 ( V_2 ) ;
goto V_67;
}
V_2 -> V_70 = F_40 ( V_33 , 0 ) ;
if ( F_41 ( V_33 -> V_46 , F_21 ,
V_71 , V_72 , V_2 ) ) {
F_4 ( V_7 L_11 , V_33 -> V_46 ) ;
V_24 = - V_73 ;
goto V_74;
}
V_2 -> V_46 = V_33 -> V_46 ;
F_42 ( V_33 ) ;
if ( ( V_24 = F_43 ( V_20 , V_75 ,
V_2 , & V_26 ) ) < 0 )
goto V_74;
F_44 ( V_20 , & V_33 -> V_76 ) ;
* V_62 = V_2 ;
return 0 ;
V_74:
F_23 ( V_2 ) ;
return V_24 ;
V_67:
F_28 ( V_33 ) ;
return V_24 ;
}
static int T_1 F_45 ( struct V_61 * V_33 ,
const struct V_77 * V_78 )
{
static int V_76 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
int V_24 ;
if ( V_76 >= V_79 )
return - V_80 ;
if ( ! V_81 [ V_76 ] ) {
V_76 ++ ;
return - V_82 ;
}
V_24 = F_46 ( V_83 [ V_76 ] , V_84 [ V_76 ] , V_85 , 0 , & V_20 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ( V_24 = F_31 ( V_20 , V_33 , & V_2 ) ) < 0 )
goto V_86;
V_20 -> V_18 = V_2 ;
if ( ( V_24 = F_10 ( V_2 ) ) < 0 )
goto V_86;
if ( ( V_24 = F_47 ( V_2 ) ) < 0 )
goto V_86;
strcpy ( V_20 -> V_87 , V_88 ) ;
strcpy ( V_20 -> V_89 , L_10 ) ;
sprintf ( V_20 -> V_90 , L_12 ,
V_20 -> V_89 , V_20 -> V_87 ,
V_2 -> V_70 , V_2 -> V_46 ) ;
if ( ( V_24 = F_48 ( V_20 ) ) < 0 )
goto V_86;
F_49 ( V_33 , V_20 ) ;
V_76 ++ ;
return 0 ;
V_86:
F_50 ( V_20 ) ;
return V_24 ;
}
static void T_5 F_51 ( struct V_61 * V_33 )
{
F_52 () ;
F_50 ( F_53 ( V_33 ) ) ;
F_49 ( V_33 , NULL ) ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_87 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_87 ) ;
}
