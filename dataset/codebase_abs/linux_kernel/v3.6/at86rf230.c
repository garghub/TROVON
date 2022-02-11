static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 = {
. V_11 = 2 ,
. V_12 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 & V_13 ) | V_14 | V_15 ;
V_5 [ 1 ] = V_4 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_10 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 * V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 & V_13 ) | V_14 ;
V_5 [ 1 ] = 0xff ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_10 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
if ( V_6 == 0 )
* V_4 = V_5 [ 1 ] ;
return V_6 ;
}
static int
F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 * V_4 )
{
int V_6 ;
F_8 ( & V_2 -> V_21 ) ;
V_6 = F_6 ( V_2 , V_3 , V_18 , V_19 , V_4 ) ;
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 V_4 )
{
int V_6 ;
T_1 V_22 ;
F_8 ( & V_2 -> V_21 ) ;
V_6 = F_6 ( V_2 , V_3 , 0xff , 0 , & V_22 ) ;
if ( V_6 )
goto V_23;
V_22 &= ~ V_18 ;
V_22 |= ( V_4 << V_19 ) & V_18 ;
V_6 = F_1 ( V_2 , V_3 , V_22 ) ;
V_23:
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_11 ( struct V_1 * V_2 , T_1 * V_4 , T_1 V_11 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_24 = {
. V_11 = 2 ,
. V_12 = V_5 ,
} ;
struct V_9 V_25 = {
. V_11 = V_11 ,
. V_12 = V_4 ,
} ;
F_8 ( & V_2 -> V_21 ) ;
V_5 [ 0 ] = V_15 | V_26 ;
V_5 [ 1 ] = V_11 + 2 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_24 , & V_8 ) ;
F_4 ( & V_25 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 * V_4 , T_1 * V_11 , T_1 * V_27 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_24 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
struct V_9 V_28 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
struct V_9 V_25 = {
. V_11 = 0 ,
. V_20 = V_4 ,
} ;
F_8 ( & V_2 -> V_21 ) ;
V_5 [ 0 ] = V_26 ;
V_5 [ 1 ] = 0x00 ;
F_3 ( & V_8 ) ;
F_4 ( & V_24 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
V_25 . V_11 = * ( V_5 + 1 ) + 1 ;
* V_11 = V_5 [ 1 ] ;
V_5 [ 0 ] = V_26 ;
V_5 [ 1 ] = 0x00 ;
F_3 ( & V_8 ) ;
F_4 ( & V_28 , & V_8 ) ;
F_4 ( & V_25 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
if ( V_6 ) {
if ( V_27 && ( * V_11 > V_2 -> V_5 [ 1 ] ) )
* V_27 = V_4 [ V_2 -> V_5 [ 1 ] ] ;
}
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_13 ( struct V_29 * V_17 , T_1 * V_30 )
{
F_14 () ;
F_15 ( ! V_30 ) ;
* V_30 = 0xbe ;
return 0 ;
}
static int
F_16 ( struct V_29 * V_17 , int V_31 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
T_1 V_22 ;
T_1 V_34 ;
F_14 () ;
if ( V_31 == V_35 )
V_34 = V_36 ;
else if ( V_31 == V_37 )
V_34 = V_38 ;
else
V_34 = V_31 ;
do {
V_33 = F_7 ( V_2 , V_39 , & V_22 ) ;
if ( V_33 )
goto V_40;
} while ( V_22 == V_41 );
if ( V_22 == V_34 )
return 0 ;
V_33 = F_10 ( V_2 , V_42 , V_31 ) ;
if ( V_33 )
goto V_40;
do {
V_33 = F_7 ( V_2 , V_39 , & V_22 ) ;
if ( V_33 )
goto V_40;
} while ( V_22 == V_41 );
if ( V_22 == V_34 )
return 0 ;
F_17 ( L_4 , V_22 , V_31 ) ;
return - V_43 ;
V_40:
F_17 ( L_5 , V_33 ) ;
return V_33 ;
}
static int
F_18 ( struct V_29 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
T_1 V_33 ;
V_33 = F_10 ( V_2 , V_44 , 1 ) ;
if ( V_33 )
return V_33 ;
return F_16 ( V_17 , V_45 ) ;
}
static void
F_19 ( struct V_29 * V_17 )
{
F_16 ( V_17 , V_37 ) ;
}
static int
F_20 ( struct V_29 * V_17 , int V_46 , int V_47 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
F_14 () ;
if ( V_46 != 0 || V_47 < 11 || V_47 > 26 ) {
F_21 ( 1 ) ;
return - V_48 ;
}
V_33 = F_10 ( V_2 , V_49 , V_47 ) ;
F_22 ( 1 ) ;
V_17 -> V_50 -> V_51 = V_47 ;
return 0 ;
}
static int
F_23 ( struct V_29 * V_17 , struct V_52 * V_53 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
unsigned long V_54 ;
F_24 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_56 ) {
F_25 ( & V_2 -> V_55 ) ;
return - V_43 ;
}
F_25 ( & V_2 -> V_55 ) ;
F_14 () ;
V_33 = F_16 ( V_17 , V_35 ) ;
if ( V_33 )
goto V_40;
F_26 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_57 = 1 ;
F_27 ( V_2 -> V_58 ) ;
F_28 ( & V_2 -> V_55 , V_54 ) ;
V_33 = F_11 ( V_2 , V_53 -> V_4 , V_53 -> V_11 ) ;
if ( V_33 )
goto V_59;
V_33 = F_10 ( V_2 , V_42 , V_60 ) ;
if ( V_33 )
goto V_59;
V_33 = F_29 ( & V_2 -> V_58 ) ;
if ( V_33 < 0 )
goto V_59;
V_33 = F_18 ( V_17 ) ;
return V_33 ;
V_59:
F_18 ( V_17 ) ;
V_40:
F_17 ( L_5 , V_33 ) ;
F_26 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_57 = 0 ;
F_28 ( & V_2 -> V_55 , V_54 ) ;
return V_33 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_11 = 128 , V_27 = 0 ;
struct V_52 * V_53 ;
V_53 = F_31 ( V_11 , V_61 ) ;
if ( ! V_53 )
return - V_62 ;
if ( F_12 ( V_2 , F_32 ( V_53 , V_11 ) , & V_11 , & V_27 ) )
goto V_40;
if ( V_11 < 2 )
goto V_40;
F_33 ( V_53 , V_11 - 2 ) ;
F_34 ( V_2 -> V_17 , V_53 , V_27 ) ;
F_35 ( & V_2 -> V_16 -> V_17 , L_6 , V_11 , V_27 ) ;
return 0 ;
V_40:
F_36 ( L_7 ) ;
F_37 ( V_53 ) ;
return - V_48 ;
}
static void F_38 ( struct V_63 * V_64 )
{
struct V_1 * V_2 =
F_39 ( V_64 , struct V_1 , V_65 ) ;
T_1 V_6 = 0 , V_22 ;
int V_33 ;
unsigned long V_54 ;
V_33 = F_7 ( V_2 , V_66 , 0xff , 0 , & V_22 ) ;
V_6 |= V_22 ;
V_6 &= ~ V_67 ;
V_6 &= ~ V_68 ;
V_6 &= ~ V_69 ;
V_6 &= ~ V_70 ;
if ( V_6 & V_71 ) {
F_26 ( & V_2 -> V_55 , V_54 ) ;
V_6 &= ~ V_71 ;
if ( V_2 -> V_57 ) {
V_2 -> V_57 = 0 ;
F_28 ( & V_2 -> V_55 , V_54 ) ;
F_40 ( & V_2 -> V_58 ) ;
} else {
F_28 ( & V_2 -> V_55 , V_54 ) ;
F_30 ( V_2 ) ;
}
}
F_26 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_56 = 0 ;
F_28 ( & V_2 -> V_55 , V_54 ) ;
F_41 ( V_2 -> V_16 -> V_72 ) ;
}
static T_2 F_42 ( int V_72 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_43 ( V_72 ) ;
F_24 ( & V_2 -> V_55 ) ;
V_2 -> V_56 = 1 ;
F_25 ( & V_2 -> V_55 ) ;
F_44 ( & V_2 -> V_65 ) ;
return V_73 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_33 ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_46 ( & V_2 -> V_16 -> V_17 , L_8 , V_6 ) ;
if ( V_6 == V_74 ) {
V_33 = F_10 ( V_2 , V_42 , V_38 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_46 ( & V_2 -> V_16 -> V_17 , L_8 , V_6 ) ;
}
V_33 = F_10 ( V_2 , V_75 , 0xff ) ;
if ( V_33 )
return V_33 ;
V_33 = F_10 ( V_2 , V_76 , 0x00 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_10 ( V_2 , V_77 , 0x00 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 100 ) ;
V_33 = F_10 ( V_2 , V_42 , V_36 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_46 ( & V_2 -> V_16 -> V_17 , L_8 , V_6 ) ;
V_33 = F_7 ( V_2 , V_78 , & V_6 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_6 ) {
F_47 ( & V_2 -> V_16 -> V_17 , L_9 ) ;
return - V_48 ;
}
V_33 = F_7 ( V_2 , V_79 , & V_6 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_6 ) {
F_47 ( & V_2 -> V_16 -> V_17 , L_10 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_48 ( struct V_80 * V_16 , T_3 V_81 )
{
return 0 ;
}
static int F_49 ( struct V_80 * V_16 )
{
return 0 ;
}
static int F_50 ( struct V_80 * V_16 )
{
struct V_1 * V_2 = F_51 ( V_16 ) ;
struct V_82 * V_83 = V_16 -> V_17 . V_84 ;
if ( ! V_83 ) {
F_47 ( & V_16 -> V_17 , L_11 ) ;
return - V_48 ;
}
V_2 -> V_85 = V_83 -> V_85 ;
V_2 -> V_86 = V_83 -> V_86 ;
V_2 -> V_87 = V_83 -> V_87 ;
return 0 ;
}
static int T_4 F_52 ( struct V_80 * V_16 )
{
struct V_29 * V_17 ;
struct V_1 * V_2 ;
T_1 V_88 , V_89 ;
int V_33 ;
const char * V_90 ;
int V_91 = 0 ;
if ( ! V_16 -> V_72 ) {
F_47 ( & V_16 -> V_17 , L_12 ) ;
return - V_48 ;
}
V_17 = F_53 ( sizeof( * V_2 ) , & V_92 ) ;
if ( ! V_17 )
return - V_62 ;
V_2 = V_17 -> V_32 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_16 = V_16 ;
V_17 -> V_32 = V_2 ;
V_17 -> V_93 = & V_16 -> V_17 ;
V_17 -> V_94 = 0 ;
V_17 -> V_50 -> V_95 [ 0 ] = 0x7FFF800 ;
V_17 -> V_54 = V_96 ;
F_54 ( & V_2 -> V_21 ) ;
F_55 ( & V_2 -> V_65 , F_38 ) ;
F_56 ( & V_2 -> V_55 ) ;
F_57 ( & V_2 -> V_58 ) ;
F_58 ( V_16 , V_2 ) ;
V_33 = F_50 ( V_16 ) ;
if ( V_33 )
goto V_97;
V_33 = F_59 ( V_2 -> V_85 , L_13 ) ;
if ( V_33 )
goto V_98;
if ( F_60 ( V_2 -> V_86 ) ) {
V_33 = F_59 ( V_2 -> V_86 , L_14 ) ;
if ( V_33 )
goto V_99;
}
V_33 = F_61 ( V_2 -> V_85 , 1 ) ;
if ( V_33 )
goto V_100;
if ( F_60 ( V_2 -> V_86 ) ) {
V_33 = F_61 ( V_2 -> V_86 , 0 ) ;
if ( V_33 )
goto V_100;
}
F_22 ( 1 ) ;
F_62 ( V_2 -> V_85 , 0 ) ;
F_22 ( 1 ) ;
F_62 ( V_2 -> V_85 , 1 ) ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_101 , & V_88 ) ;
if ( V_33 )
goto V_100;
V_33 = F_7 ( V_2 , V_102 , & V_89 ) ;
if ( V_33 )
goto V_100;
if ( V_89 != 0x00 || V_88 != 0x1f ) {
F_47 ( & V_16 -> V_17 , L_15 ,
V_89 , V_88 ) ;
V_33 = - V_48 ;
goto V_100;
}
V_33 = F_7 ( V_2 , V_103 , & V_2 -> V_104 ) ;
if ( V_33 )
goto V_100;
V_33 = F_7 ( V_2 , V_105 , & V_2 -> V_106 ) ;
if ( V_33 )
goto V_100;
switch ( V_2 -> V_104 ) {
case 2 :
V_90 = L_16 ;
break;
case 3 :
V_90 = L_17 ;
V_91 = 1 ;
break;
default:
V_90 = L_18 ;
break;
}
F_46 ( & V_16 -> V_17 , L_19 , V_90 , V_2 -> V_106 ) ;
if ( ! V_91 ) {
V_33 = - V_107 ;
goto V_100;
}
V_33 = F_45 ( V_2 ) ;
if ( V_33 )
goto V_100;
V_33 = F_63 ( V_16 -> V_72 , F_42 , V_108 ,
F_64 ( & V_16 -> V_17 ) , V_2 ) ;
if ( V_33 )
goto V_100;
V_33 = F_65 ( V_2 -> V_17 ) ;
if ( V_33 )
goto V_109;
return V_33 ;
F_66 ( V_2 -> V_17 ) ;
V_109:
F_67 ( V_16 -> V_72 , V_2 ) ;
F_68 ( & V_2 -> V_65 ) ;
V_100:
if ( F_60 ( V_2 -> V_86 ) )
F_69 ( V_2 -> V_86 ) ;
V_99:
F_69 ( V_2 -> V_85 ) ;
V_98:
V_97:
F_58 ( V_16 , NULL ) ;
F_70 ( & V_2 -> V_21 ) ;
F_71 ( V_2 -> V_17 ) ;
return V_33 ;
}
static int T_5 F_72 ( struct V_80 * V_16 )
{
struct V_1 * V_2 = F_51 ( V_16 ) ;
F_66 ( V_2 -> V_17 ) ;
F_67 ( V_16 -> V_72 , V_2 ) ;
F_68 ( & V_2 -> V_65 ) ;
if ( F_60 ( V_2 -> V_86 ) )
F_69 ( V_2 -> V_86 ) ;
F_69 ( V_2 -> V_85 ) ;
F_58 ( V_16 , NULL ) ;
F_70 ( & V_2 -> V_21 ) ;
F_71 ( V_2 -> V_17 ) ;
F_35 ( & V_16 -> V_17 , L_20 ) ;
return 0 ;
}
static int T_6 F_73 ( void )
{
return F_74 ( & V_110 ) ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_110 ) ;
}
