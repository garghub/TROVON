static int F_1 ( int V_1 )
{
T_1 V_2 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_3 )
return - V_4 ;
V_2 [ 0 ] = 0x80 ;
V_2 [ 1 ] = ( T_1 ) ( V_1 * 31 ) ;
return F_2 ( V_5 , V_2 , sizeof( V_2 ) ,
NULL , 0 ) ;
}
static int F_3 ( void )
{
T_1 V_6 = 0 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return ( int ) V_7 / 31 ;
}
static int F_4 ( void )
{
T_1 V_6 = 4 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return ! ! ( V_7 & 8 ) ;
}
static int F_5 ( int V_9 )
{
T_1 V_6 [ 2 ] , V_7 ;
int V_8 ;
V_6 [ 0 ] = 4 ;
V_8 = F_2 ( V_5 , V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 [ 0 ] = 0x84 ;
V_6 [ 1 ] = ( V_7 & 0xF7 ) | ( V_9 ? 8 : 0 ) ;
return F_2 ( V_5 , V_6 , 2 ,
NULL , 0 ) ;
}
static T_2 F_6 ( const char * V_2 , T_3 V_10 , T_1 V_11 )
{
int V_12 ;
T_1 V_6 = 0 , V_7 ;
int V_8 ;
if ( sscanf ( V_2 , L_1 , & V_12 ) != 1 || ( V_12 < 0 || V_12 > 1 ) )
return - V_4 ;
V_8 = F_7 ( V_13 , & V_7 ) ;
if ( V_8 < 0 )
return - V_4 ;
if ( ! ! ( V_7 & V_11 ) != V_12 ) {
if ( V_7 & V_11 )
V_6 = V_7 & ~ V_11 ;
else
V_6 = V_7 | V_11 ;
V_8 = F_8 ( V_13 , V_6 ) ;
if ( V_8 < 0 )
return - V_4 ;
}
return V_10 ;
}
static int F_9 ( int * V_14 , int * V_15 )
{
T_1 V_6 = 0 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_16 , & V_6 , 1 , & V_7 , 1 ) ;
if ( V_8 < 0 )
return - 1 ;
if ( V_14 )
* V_14 = ! ! ( V_7 & 8 ) ;
if ( V_15 )
* V_15 = ! ! ( V_7 & 128 ) ;
return 0 ;
}
static int F_10 ( void )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_13 , & V_7 ) ;
if ( V_8 < 0 )
return - 1 ;
V_17 = ! ! ( V_7 & V_18 ) ;
V_19 = ! ! ( V_7 & V_20 ) ;
V_21 = ! ! ( V_7 & V_22 ) ;
return 0 ;
}
static int F_11 ( void )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_23 , & V_7 ) ;
if ( V_8 < 0 )
return - 1 ;
V_24 = ! ! ( V_7 & V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 )
{
return F_3 () ;
}
static int F_13 ( struct V_25 * V_26 )
{
return F_1 ( V_26 -> V_27 . V_28 ) ;
}
static T_2 F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_2 )
{
int V_33 , V_34 ;
if ( V_35 ) {
V_33 = F_9 ( & V_34 , NULL ) ;
} else {
V_33 = F_10 () ;
V_34 = V_17 ;
}
if ( V_33 < 0 )
return V_33 ;
return sprintf ( V_2 , L_2 , V_34 ) ;
}
static T_2 F_15 ( struct V_29 * V_30 ,
struct V_31 * V_32 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_18 ) ;
}
static T_2 F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_2 )
{
int V_33 , V_34 ;
if ( V_35 ) {
V_33 = F_9 ( NULL , & V_34 ) ;
} else {
V_33 = F_10 () ;
V_34 = V_19 ;
}
if ( V_33 < 0 )
return V_33 ;
return sprintf ( V_2 , L_2 , V_34 ) ;
}
static T_2 F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_20 ) ;
}
static T_2 F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_2 )
{
int V_33 ;
if ( V_35 )
return - 1 ;
V_33 = F_10 () ;
if ( V_33 < 0 )
return V_33 ;
return sprintf ( V_2 , L_2 , V_21 ) ;
}
static T_2 F_19 ( struct V_29 * V_30 ,
struct V_31 * V_32 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_22 ) ;
}
static T_2 F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_2 )
{
int V_33 ;
V_33 = F_3 () ;
if ( V_33 < 0 )
return V_33 ;
return sprintf ( V_2 , L_2 , V_33 ) ;
}
static T_2 F_21 ( struct V_29 * V_30 ,
struct V_31 * V_32 , const char * V_2 , T_3 V_10 )
{
int V_1 , V_33 ;
if ( sscanf ( V_2 , L_1 , & V_1 ) != 1 ||
( V_1 < 0 || V_1 >= V_3 ) )
return - V_4 ;
V_33 = F_1 ( V_1 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_10 ;
}
static T_2 F_22 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_2 )
{
int V_33 ;
V_33 = F_4 () ;
if ( V_33 < 0 )
return V_33 ;
return sprintf ( V_2 , L_2 , V_33 ) ;
}
static T_2 F_23 ( struct V_29 * V_30 ,
struct V_31 * V_32 , const char * V_2 , T_3 V_10 )
{
int V_9 , V_33 ;
if ( sscanf ( V_2 , L_1 , & V_9 ) != 1 || ( V_9 != ( V_9 & 1 ) ) )
return - V_4 ;
V_33 = F_5 ( V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_10 ;
}
static int F_24 ( const struct V_36 * V_37 )
{
F_25 ( L_3 , V_37 -> V_38 ) ;
return 1 ;
}
static int F_26 ( void * V_39 , bool V_40 )
{
if ( V_40 )
F_6 ( L_4 , 0 , V_20 ) ;
else
F_6 ( L_5 , 0 , V_20 ) ;
return 0 ;
}
static int F_27 ( void * V_39 , bool V_40 )
{
if ( V_40 )
F_6 ( L_4 , 0 , V_18 ) ;
else
F_6 ( L_5 , 0 , V_18 ) ;
return 0 ;
}
static int F_28 ( void * V_39 , bool V_40 )
{
if ( V_40 )
F_6 ( L_4 , 0 , V_22 ) ;
else
F_6 ( L_5 , 0 , V_22 ) ;
return 0 ;
}
static void F_29 ( void )
{
if ( V_41 ) {
F_30 ( V_41 ) ;
F_31 ( V_41 ) ;
}
if ( V_42 ) {
F_30 ( V_42 ) ;
F_31 ( V_42 ) ;
}
if ( V_43 ) {
F_30 ( V_43 ) ;
F_31 ( V_43 ) ;
}
}
static void F_32 ( struct V_44 * V_45 )
{
F_10 () ;
if ( V_43 )
F_33 ( V_43 , ! V_17 ) ;
if ( V_41 )
F_33 ( V_41 , ! V_19 ) ;
if ( V_42 )
F_33 ( V_42 , ! V_21 ) ;
}
static void F_34 ( struct V_44 * V_45 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_46 , & V_7 ) ;
if ( V_8 < 0 )
return;
F_35 ( V_47 ,
( V_7 & V_48 ) ?
V_49 : V_50 , 1 , true ) ;
}
static bool F_36 ( unsigned char V_39 , unsigned char V_51 ,
struct V_52 * V_53 )
{
static bool V_54 ;
if ( V_51 & 0x20 )
return false ;
if ( F_37 ( V_39 == 0xe0 ) ) {
V_54 = true ;
return false ;
} else if ( F_37 ( V_54 ) ) {
V_54 = false ;
switch ( V_39 ) {
case 0xE4 :
F_38 ( & V_55 ,
F_39 ( 0.5 * V_56 ) ) ;
break;
case 0x54 :
case 0x62 :
case 0x76 :
F_38 ( & V_57 ,
F_39 ( 0.5 * V_56 ) ) ;
break;
}
}
return false ;
}
static void F_40 ( struct V_44 * V_45 )
{
if ( V_43 ) {
F_33 ( V_43 , ! V_17 ) ;
F_27 ( NULL , ! V_17 ) ;
}
if ( V_41 ) {
F_33 ( V_41 , ! V_19 ) ;
F_26 ( NULL , ! V_19 ) ;
}
if ( V_42 ) {
F_33 ( V_42 , ! V_21 ) ;
F_28 ( NULL , ! V_21 ) ;
}
}
static int F_41 ( struct V_58 * V_59 )
{
int V_60 ;
F_10 () ;
V_41 = F_42 ( L_6 , & V_59 -> V_30 ,
V_61 ,
& V_62 , NULL ) ;
if ( ! V_41 ) {
V_60 = - V_63 ;
goto V_64;
}
V_60 = F_43 ( V_41 ) ;
if ( V_60 )
goto V_64;
V_43 = F_42 ( L_7 , & V_59 -> V_30 , V_65 ,
& V_66 , NULL ) ;
if ( ! V_43 ) {
V_60 = - V_63 ;
goto V_67;
}
V_60 = F_43 ( V_43 ) ;
if ( V_60 )
goto V_67;
if ( V_24 ) {
V_42 = F_42 ( L_8 , & V_59 -> V_30 ,
V_68 , & V_69 , NULL ) ;
if ( ! V_42 ) {
V_60 = - V_63 ;
goto V_70;
}
V_60 = F_43 ( V_42 ) ;
if ( V_60 )
goto V_70;
}
F_38 ( & V_71 ,
F_39 ( 1 * V_56 ) ) ;
return 0 ;
V_70:
F_31 ( V_42 ) ;
if ( V_43 )
F_30 ( V_43 ) ;
V_67:
F_31 ( V_43 ) ;
if ( V_41 )
F_30 ( V_41 ) ;
V_64:
F_31 ( V_41 ) ;
return V_60 ;
}
static int F_44 ( struct V_58 * V_29 )
{
T_1 V_39 ;
int V_8 ;
if ( ! V_72 )
return 0 ;
V_8 = F_7 ( V_73 , & V_39 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_73 ,
V_39 | V_74 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int T_4 F_45 ( void )
{
int V_75 ;
V_47 = F_46 () ;
if ( ! V_47 )
return - V_63 ;
V_47 -> V_76 = L_9 ;
V_47 -> V_77 = L_10 ;
V_47 -> V_37 . V_78 = V_79 ;
V_75 = F_47 ( V_47 ,
V_80 , NULL ) ;
if ( V_75 )
goto V_81;
V_75 = F_48 ( V_47 ) ;
if ( V_75 )
goto V_82;
return 0 ;
V_82:
F_49 ( V_47 ) ;
V_81:
F_50 ( V_47 ) ;
return V_75 ;
}
static void F_51 ( void )
{
F_49 ( V_47 ) ;
F_52 ( V_47 ) ;
}
static int T_4 F_53 ( struct V_58 * V_59 )
{
T_1 V_39 ;
int V_8 ;
V_83 . V_84 = F_17 ;
V_85 . V_84 = F_15 ;
V_86 . V_84 = F_19 ;
V_83 . V_32 . V_87 |= V_88 ;
V_85 . V_32 . V_87 |= V_88 ;
V_86 . V_32 . V_87 |= V_88 ;
V_8 = F_7 ( V_73 , & V_39 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_73 ,
V_39 | V_74 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_41 ( V_59 ) ;
if ( V_8 < 0 )
goto V_89;
V_8 = F_45 () ;
if ( V_8 )
goto V_90;
V_8 = F_54 ( F_36 ) ;
if ( V_8 ) {
F_55 ( L_11 ) ;
goto V_91;
}
return 0 ;
V_91:
F_51 () ;
V_90:
F_29 () ;
V_89:
return V_8 ;
}
static int T_4 F_56 ( void )
{
int V_33 ;
if ( V_92 )
return - V_93 ;
if ( V_94 || F_57 ( V_95 ) )
V_35 = 1 ;
if ( ! V_35 )
F_11 () ;
if ( ! V_35 && F_57 ( V_96 ) )
V_72 = 1 ;
if ( V_97 < 0 || V_97 > 2 )
return - V_4 ;
if ( F_58 () ) {
F_25 ( L_12 ) ;
} else {
struct V_98 V_27 ;
memset ( & V_27 , 0 , sizeof( struct V_98 ) ) ;
V_27 . type = V_99 ;
V_27 . V_100 = V_3 - 1 ;
V_101 = F_59 ( L_13 , NULL ,
NULL , & V_102 ,
& V_27 ) ;
if ( F_60 ( V_101 ) )
return F_61 ( V_101 ) ;
}
V_33 = F_62 ( & V_103 ) ;
if ( V_33 )
goto V_104;
V_105 = F_63 ( L_14 , - 1 ) ;
if ( ! V_105 ) {
V_33 = - V_63 ;
goto V_106;
}
V_33 = F_64 ( V_105 ) ;
if ( V_33 )
goto V_107;
if ( V_72 && ( F_53 ( V_105 ) < 0 ) ) {
V_33 = - V_4 ;
goto V_107;
}
V_33 = F_65 ( & V_105 -> V_30 . V_108 ,
& V_109 ) ;
if ( V_33 )
goto V_110;
if ( ! V_35 ) {
if ( V_24 )
V_33 = F_66 ( & V_105 -> V_30 ,
& V_86 ) ;
if ( V_33 )
goto V_110;
}
if ( V_97 != 2 )
F_5 ( V_97 ) ;
F_25 ( L_15 V_111 L_16 ) ;
return 0 ;
V_110:
if ( V_72 ) {
F_67 ( F_36 ) ;
F_68 ( & V_57 ) ;
F_29 () ;
}
F_69 ( V_105 ) ;
V_107:
F_70 ( V_105 ) ;
V_106:
F_71 ( & V_103 ) ;
V_104:
F_72 ( V_101 ) ;
return V_33 ;
}
static void T_5 F_73 ( void )
{
if ( V_72 ) {
F_67 ( F_36 ) ;
F_51 () ;
F_68 ( & V_57 ) ;
F_29 () ;
}
F_74 ( & V_105 -> V_30 . V_108 , & V_109 ) ;
if ( ! V_35 && V_24 )
F_75 ( & V_105 -> V_30 , & V_86 ) ;
F_76 ( V_105 ) ;
F_71 ( & V_103 ) ;
F_72 ( V_101 ) ;
if ( V_97 != 2 )
F_5 ( 1 ) ;
F_25 ( L_17 ) ;
}
