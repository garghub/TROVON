static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 ;
T_1 V_6 = 10 ;
T_1 V_7 = 0 ;
do {
V_5 = F_2 ( V_4 , V_8 ) ;
V_5 = ( V_5 >> V_9 ) & 0x1 ;
V_7 ++ ;
if ( V_5 == V_2 )
return 0 ;
F_3 ( 1 ) ;
} while ( V_7 < V_6 );
return - V_10 ;
}
static int F_4 ( struct V_1 * V_1 , int V_11 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 ;
int V_12 ;
V_5 = V_11 << V_13 ;
F_5 ( V_4 , V_14 , V_5 ) ;
V_5 |= ( 0x1 << V_15 ) ;
F_5 ( V_4 , V_14 , V_5 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_5 = V_11 << V_13 ;
F_5 ( V_4 , V_14 , V_5 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_6 ( struct V_1 * V_1 , int V_11 , int * V_16 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 , V_17 ;
int V_12 ;
V_12 = F_4 ( V_1 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_17 = 0x1 << V_18 ;
F_5 ( V_4 , V_14 , V_17 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_5 = F_2 ( V_4 , V_8 ) ;
* V_16 = V_5 & 0xffff ;
F_5 ( V_4 , V_14 , 0x00 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_11 , int V_16 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_19 ;
int V_12 ;
V_12 = F_4 ( V_1 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_19 |= ( 0x1 << V_20 ) ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 0 ) ;
if ( V_12 )
return V_12 ;
V_19 = 0x1 << V_21 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 0 ) ;
if ( V_12 )
return V_12 ;
F_5 ( V_4 , V_14 , 0x0 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_1 )
{
T_1 V_22 ;
F_6 ( V_1 , V_23 , & V_22 ) ;
V_22 |= ( V_24 |
V_25 ) ;
F_7 ( V_1 , V_23 , V_22 ) ;
F_9 ( 2000 , 3000 ) ;
F_6 ( V_1 , V_23 , & V_22 ) ;
V_22 &= ~ ( V_24 |
V_25 ) ;
F_7 ( V_1 , V_23 , V_22 ) ;
}
static int F_10 ( unsigned long V_11 ,
unsigned int V_26 , struct V_27 * V_28 )
{
unsigned long V_29 = F_11 ( V_28 ) ;
unsigned long V_30 = * ( unsigned long * ) V_29 ;
int V_31 = ( V_30 >> 12 ) & 15 ;
if ( ( V_30 & 0x0c100000 ) == 0x04100000 ) {
unsigned long V_5 ;
if ( V_30 & 0x00400000 )
V_5 = 255 ;
else
V_5 = - 1 ;
V_28 -> V_32 [ V_31 ] = V_5 ;
V_28 -> V_33 += 4 ;
return 0 ;
}
if ( ( V_30 & 0x0e100090 ) == 0x00100090 ) {
V_28 -> V_32 [ V_31 ] = - 1 ;
V_28 -> V_33 += 4 ;
return 0 ;
}
return 1 ;
}
static void F_12 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_34 ) {
case V_35 :
F_13 ( V_1 -> V_36 ) ;
F_13 ( V_1 -> V_37 ) ;
break;
case V_38 :
F_14 ( V_1 -> V_39 , V_40 ,
V_41 ,
V_41 ) ;
F_14 ( V_1 -> V_39 , V_42 ,
V_43 ,
V_43 ) ;
break;
case V_44 :
F_14 ( V_1 -> V_39 , V_45 ,
V_46 ,
V_46 ) ;
break;
case V_47 :
F_14 ( V_1 -> V_39 , V_45 ,
V_48 , 1 << 18 ) ;
F_14 ( V_1 -> V_39 , V_45 ,
V_49 , 0 << 16 ) ;
break;
}
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_50 * V_51 = V_4 -> V_51 ;
int V_12 = 0 ;
switch ( V_1 -> V_34 ) {
case V_38 :
V_12 = F_16 ( V_1 -> V_52 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_1 ) ;
break;
}
F_14 ( V_1 -> V_39 , V_40 ,
V_41 , 0 ) ;
break;
case V_44 :
case V_47 :
F_14 ( V_1 -> V_39 , V_45 ,
V_48 , 0 << 18 ) ;
F_3 ( 10 ) ;
F_14 ( V_1 -> V_39 , V_45 ,
V_49 , 1 << 16 ) ;
break;
case V_35 :
break;
}
return V_12 ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_5 ;
unsigned int V_53 ;
struct V_50 * V_51 = V_1 -> V_4 -> V_51 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
F_19 ( V_1 -> V_39 , V_55 , & V_5 ) ;
if ( V_5 & V_56 )
return;
F_9 ( V_57 ,
V_58 ) ;
}
F_17 ( V_51 , L_2 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_50 * V_51 = V_4 -> V_51 ;
int V_12 ;
V_12 = F_16 ( V_1 -> V_59 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_3 ) ;
return;
}
V_12 = F_16 ( V_1 -> V_60 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_4 ) ;
goto V_61;
}
V_12 = F_16 ( V_1 -> V_62 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_5 ) ;
goto V_63;
}
V_12 = F_15 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_6 ) ;
goto V_64;
}
F_9 ( 200 , 500 ) ;
if ( F_21 ( V_1 -> V_65 ) ) {
F_22 ( V_1 -> V_65 ,
V_1 -> V_66 ) ;
F_23 ( 100 ) ;
F_22 ( V_1 -> V_65 ,
! V_1 -> V_66 ) ;
}
switch ( V_1 -> V_34 ) {
case V_35 :
F_24 ( V_1 -> V_36 ) ;
F_18 ( V_1 ) ;
break;
case V_38 :
F_14 ( V_1 -> V_39 , V_42 ,
V_43 , 0 ) ;
break;
case V_44 :
F_14 ( V_1 -> V_39 , V_45 ,
V_46 , 0 ) ;
F_9 ( 200 , 500 ) ;
break;
case V_47 :
break;
}
return;
V_64:
F_25 ( V_1 -> V_62 ) ;
V_63:
F_25 ( V_1 -> V_60 ) ;
V_61:
F_25 ( V_1 -> V_59 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_34 ) {
case V_35 :
F_14 ( V_1 -> V_39 , V_40 ,
V_67 , 0 ) ;
break;
case V_38 :
F_14 ( V_1 -> V_39 , V_40 ,
V_68 ,
V_69 ) ;
default:
F_14 ( V_1 -> V_39 , V_40 ,
V_70 , 0 << 10 ) ;
F_14 ( V_1 -> V_39 , V_40 ,
V_71 , 9 << 4 ) ;
F_14 ( V_1 -> V_39 , V_72 ,
V_73 ,
V_1 -> V_74 << 0 ) ;
F_14 ( V_1 -> V_39 , V_72 ,
V_75 ,
V_1 -> V_76 << 6 ) ;
F_14 ( V_1 -> V_39 , V_72 ,
V_77 ,
V_1 -> V_78 << 12 ) ;
F_14 ( V_1 -> V_39 , V_72 ,
V_79 ,
V_1 -> V_80 << 18 ) ;
F_14 ( V_1 -> V_39 , V_72 ,
V_81 ,
V_1 -> V_82 << 25 ) ;
break;
}
F_14 ( V_1 -> V_39 , V_40 ,
V_83 , V_84 << 12 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_50 * V_51 = V_4 -> V_51 ;
if ( ! F_28 ( V_4 ) )
return 0 ;
F_29 ( V_51 , L_7 ,
F_2 ( V_4 , V_85 ) ,
F_2 ( V_4 , V_86 ) ) ;
return - V_10 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_50 * V_51 = V_4 -> V_51 ;
T_1 V_22 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < 200 ; V_53 ++ ) {
V_22 = F_2 ( V_4 , V_87 ) ;
if ( ! ( V_22 & V_88 ) )
return 0 ;
F_9 ( 100 , 1000 ) ;
}
F_17 ( V_51 , L_8 ) ;
return - V_89 ;
}
static T_2 F_31 ( int V_90 , void * V_91 )
{
struct V_1 * V_1 = V_91 ;
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_92 * V_93 = & V_4 -> V_93 ;
return F_32 ( V_93 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_50 * V_51 = V_4 -> V_51 ;
T_1 V_22 ;
int V_12 ;
V_22 = F_2 ( V_4 , V_94 ) ;
V_22 &= ~ V_95 ;
V_22 |= V_96 ;
F_5 ( V_4 , V_94 , V_22 ) ;
if ( V_1 -> V_34 == V_35 )
F_24 ( V_1 -> V_37 ) ;
else
F_14 ( V_1 -> V_39 , V_40 ,
V_70 , 1 << 10 ) ;
V_12 = F_27 ( V_1 ) ;
if ( V_12 )
goto V_97;
if ( V_1 -> V_98 == 2 ) {
V_22 = F_2 ( V_4 , V_94 ) ;
V_22 &= ~ V_95 ;
V_22 |= V_99 ;
F_5 ( V_4 , V_94 , V_22 ) ;
V_22 = F_2 ( V_4 , V_87 ) ;
V_22 |= V_88 ;
F_5 ( V_4 , V_87 , V_22 ) ;
if ( V_1 -> V_34 != V_35 ) {
V_12 = F_30 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_9 ) ;
goto V_97;
}
}
V_12 = F_27 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_9 ) ;
goto V_97;
}
} else {
F_34 ( V_51 , L_10 ) ;
}
V_22 = F_2 ( V_4 , V_100 ) ;
F_34 ( V_51 , L_11 , ( V_22 >> 16 ) & 0xf ) ;
return 0 ;
V_97:
F_29 ( V_51 , L_12 ,
F_2 ( V_4 , V_85 ) ,
F_2 ( V_4 , V_86 ) ) ;
F_8 ( V_1 ) ;
return V_12 ;
}
static void F_35 ( struct V_92 * V_93 )
{
struct V_3 * V_4 = F_36 ( V_93 ) ;
struct V_1 * V_1 = F_37 ( V_4 ) ;
F_12 ( V_1 ) ;
F_26 ( V_1 ) ;
F_20 ( V_1 ) ;
F_38 ( V_93 ) ;
F_33 ( V_1 ) ;
if ( F_39 ( V_101 ) )
F_40 ( V_93 ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , V_86 ) &
V_102 ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_103 * V_104 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_92 * V_93 = & V_4 -> V_93 ;
struct V_50 * V_51 = & V_104 -> V_51 ;
int V_12 ;
if ( F_39 ( V_101 ) ) {
V_93 -> V_105 = F_43 ( V_104 , L_13 ) ;
if ( V_93 -> V_105 <= 0 ) {
F_17 ( V_51 , L_14 ) ;
return - V_106 ;
}
V_12 = F_44 ( V_51 , V_93 -> V_105 ,
F_31 ,
V_107 | V_108 ,
L_15 , V_1 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_16 ) ;
return V_12 ;
}
}
V_93 -> V_109 = - 1 ;
V_93 -> V_110 = & V_111 ;
V_12 = F_45 ( V_93 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_17 ) ;
return V_12 ;
}
return 0 ;
}
static int F_46 ( struct V_103 * V_104 )
{
struct V_50 * V_51 = & V_104 -> V_51 ;
struct V_3 * V_4 ;
struct V_1 * V_1 ;
struct V_112 * V_113 ;
struct V_114 * V_115 = V_51 -> V_116 ;
int V_12 ;
V_1 = F_47 ( V_51 , sizeof( * V_1 ) , V_117 ) ;
if ( ! V_1 )
return - V_118 ;
V_4 = F_47 ( V_51 , sizeof( * V_4 ) , V_117 ) ;
if ( ! V_4 )
return - V_118 ;
V_4 -> V_51 = V_51 ;
V_4 -> V_110 = & V_119 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_34 =
(enum V_120 ) F_48 ( V_51 ) ;
V_113 = F_49 ( V_104 , V_121 , 0 ) ;
V_4 -> V_113 = F_50 ( V_51 , V_113 ) ;
if ( F_51 ( V_4 -> V_113 ) )
return F_52 ( V_4 -> V_113 ) ;
V_1 -> V_65 = F_53 ( V_115 , L_18 , 0 ) ;
V_1 -> V_66 = F_54 ( V_115 ,
L_19 ) ;
if ( F_21 ( V_1 -> V_65 ) ) {
V_12 = F_55 ( V_51 , V_1 -> V_65 ,
V_1 -> V_66 ?
V_122 :
V_123 ,
L_20 ) ;
if ( V_12 ) {
F_17 ( V_51 , L_21 ) ;
return V_12 ;
}
} else if ( V_1 -> V_65 == - V_124 ) {
return V_1 -> V_65 ;
}
V_1 -> V_59 = F_56 ( V_51 , L_22 ) ;
if ( F_51 ( V_1 -> V_59 ) ) {
F_17 ( V_51 , L_23 ) ;
return F_52 ( V_1 -> V_59 ) ;
}
V_1 -> V_60 = F_56 ( V_51 , L_24 ) ;
if ( F_51 ( V_1 -> V_60 ) ) {
F_17 ( V_51 , L_25 ) ;
return F_52 ( V_1 -> V_60 ) ;
}
V_1 -> V_62 = F_56 ( V_51 , L_26 ) ;
if ( F_51 ( V_1 -> V_62 ) ) {
F_17 ( V_51 , L_27 ) ;
return F_52 ( V_1 -> V_62 ) ;
}
switch ( V_1 -> V_34 ) {
case V_38 :
V_1 -> V_52 = F_56 ( V_51 ,
L_28 ) ;
if ( F_51 ( V_1 -> V_52 ) ) {
F_17 ( V_51 , L_29 ) ;
return F_52 ( V_1 -> V_52 ) ;
}
break;
case V_35 :
V_1 -> V_36 = F_57 ( V_51 ,
L_30 ) ;
if ( F_51 ( V_1 -> V_36 ) ) {
F_17 ( V_51 , L_31 ) ;
return F_52 ( V_1 -> V_36 ) ;
}
V_1 -> V_37 = F_57 ( V_51 , L_32 ) ;
if ( F_51 ( V_1 -> V_37 ) ) {
F_17 ( V_51 , L_33 ) ;
return F_52 ( V_1 -> V_37 ) ;
}
break;
default:
break;
}
V_1 -> V_39 =
F_58 ( L_34 ) ;
if ( F_51 ( V_1 -> V_39 ) ) {
F_17 ( V_51 , L_35 ) ;
return F_52 ( V_1 -> V_39 ) ;
}
if ( F_59 ( V_115 , L_36 ,
& V_1 -> V_74 ) )
V_1 -> V_74 = 0 ;
if ( F_59 ( V_115 , L_37 ,
& V_1 -> V_76 ) )
V_1 -> V_76 = 0 ;
if ( F_59 ( V_115 , L_38 ,
& V_1 -> V_78 ) )
V_1 -> V_78 = 20 ;
if ( F_59 ( V_115 , L_39 ,
& V_1 -> V_80 ) )
V_1 -> V_80 = 127 ;
if ( F_59 ( V_115 , L_40 ,
& V_1 -> V_82 ) )
V_1 -> V_82 = 127 ;
V_12 = F_59 ( V_115 , L_41 ,
& V_1 -> V_98 ) ;
if ( V_12 )
V_1 -> V_98 = 1 ;
F_60 ( V_104 , V_1 ) ;
V_12 = F_42 ( V_1 , V_104 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_61 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_62 ( V_104 ) ;
F_12 ( V_1 ) ;
}
static int T_3 F_63 ( void )
{
F_64 ( 8 , F_10 , V_125 , 0 ,
L_42 ) ;
return F_65 ( & V_126 ) ;
}
