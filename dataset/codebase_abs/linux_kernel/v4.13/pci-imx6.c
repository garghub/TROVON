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
struct V_34 * V_35 = V_1 -> V_4 -> V_35 ;
switch ( V_1 -> V_36 ) {
case V_37 :
F_13 ( V_1 -> V_38 ) ;
F_13 ( V_1 -> V_39 ) ;
break;
case V_40 :
F_14 ( V_1 -> V_41 , V_42 ,
V_43 ,
V_43 ) ;
F_14 ( V_1 -> V_41 , V_44 ,
V_45 ,
V_45 ) ;
break;
case V_46 :
F_14 ( V_1 -> V_41 , V_47 ,
V_48 ,
V_48 ) ;
break;
case V_49 :
F_14 ( V_1 -> V_41 , V_47 ,
V_50 , 1 << 18 ) ;
F_14 ( V_1 -> V_41 , V_47 ,
V_51 , 0 << 16 ) ;
break;
}
if ( V_1 -> V_52 && F_15 ( V_1 -> V_52 ) > 0 ) {
int V_12 = F_16 ( V_1 -> V_52 ) ;
if ( V_12 )
F_17 ( V_35 , L_1 ,
V_12 ) ;
}
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_34 * V_35 = V_4 -> V_35 ;
int V_12 = 0 ;
switch ( V_1 -> V_36 ) {
case V_40 :
V_12 = F_19 ( V_1 -> V_53 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_2 ) ;
break;
}
F_14 ( V_1 -> V_41 , V_42 ,
V_43 , 0 ) ;
break;
case V_46 :
case V_49 :
F_14 ( V_1 -> V_41 , V_47 ,
V_50 , 0 << 18 ) ;
F_3 ( 10 ) ;
F_14 ( V_1 -> V_41 , V_47 ,
V_51 , 1 << 16 ) ;
break;
case V_37 :
break;
}
return V_12 ;
}
static void F_20 ( struct V_1 * V_1 )
{
T_1 V_5 ;
unsigned int V_54 ;
struct V_34 * V_35 = V_1 -> V_4 -> V_35 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
F_21 ( V_1 -> V_41 , V_56 , & V_5 ) ;
if ( V_5 & V_57 )
return;
F_9 ( V_58 ,
V_59 ) ;
}
F_17 ( V_35 , L_3 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_34 * V_35 = V_4 -> V_35 ;
int V_12 ;
if ( V_1 -> V_52 && ! F_15 ( V_1 -> V_52 ) ) {
V_12 = F_23 ( V_1 -> V_52 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_4 ,
V_12 ) ;
return;
}
}
V_12 = F_19 ( V_1 -> V_60 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_5 ) ;
goto V_61;
}
V_12 = F_19 ( V_1 -> V_62 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_6 ) ;
goto V_63;
}
V_12 = F_19 ( V_1 -> V_64 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_7 ) ;
goto V_65;
}
V_12 = F_18 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_8 ) ;
goto V_66;
}
F_9 ( 200 , 500 ) ;
if ( F_24 ( V_1 -> V_67 ) ) {
F_25 ( V_1 -> V_67 ,
V_1 -> V_68 ) ;
F_26 ( 100 ) ;
F_25 ( V_1 -> V_67 ,
! V_1 -> V_68 ) ;
}
switch ( V_1 -> V_36 ) {
case V_37 :
F_27 ( V_1 -> V_38 ) ;
F_20 ( V_1 ) ;
break;
case V_40 :
F_14 ( V_1 -> V_41 , V_44 ,
V_45 , 0 ) ;
break;
case V_46 :
F_14 ( V_1 -> V_41 , V_47 ,
V_48 , 0 ) ;
F_9 ( 200 , 500 ) ;
break;
case V_49 :
break;
}
return;
V_66:
F_28 ( V_1 -> V_64 ) ;
V_65:
F_28 ( V_1 -> V_62 ) ;
V_63:
F_28 ( V_1 -> V_60 ) ;
V_61:
if ( V_1 -> V_52 && F_15 ( V_1 -> V_52 ) > 0 ) {
V_12 = F_16 ( V_1 -> V_52 ) ;
if ( V_12 )
F_17 ( V_35 , L_1 ,
V_12 ) ;
}
}
static void F_29 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_36 ) {
case V_37 :
F_14 ( V_1 -> V_41 , V_42 ,
V_69 , 0 ) ;
break;
case V_40 :
F_14 ( V_1 -> V_41 , V_42 ,
V_70 ,
V_71 ) ;
default:
F_14 ( V_1 -> V_41 , V_42 ,
V_72 , 0 << 10 ) ;
F_14 ( V_1 -> V_41 , V_42 ,
V_73 , 9 << 4 ) ;
F_14 ( V_1 -> V_41 , V_74 ,
V_75 ,
V_1 -> V_76 << 0 ) ;
F_14 ( V_1 -> V_41 , V_74 ,
V_77 ,
V_1 -> V_78 << 6 ) ;
F_14 ( V_1 -> V_41 , V_74 ,
V_79 ,
V_1 -> V_80 << 12 ) ;
F_14 ( V_1 -> V_41 , V_74 ,
V_81 ,
V_1 -> V_82 << 18 ) ;
F_14 ( V_1 -> V_41 , V_74 ,
V_83 ,
V_1 -> V_84 << 25 ) ;
break;
}
F_14 ( V_1 -> V_41 , V_42 ,
V_85 , V_86 << 12 ) ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_34 * V_35 = V_4 -> V_35 ;
if ( ! F_31 ( V_4 ) )
return 0 ;
F_32 ( V_35 , L_9 ,
F_2 ( V_4 , V_87 ) ,
F_2 ( V_4 , V_88 ) ) ;
return - V_10 ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_34 * V_35 = V_4 -> V_35 ;
T_1 V_22 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < 200 ; V_54 ++ ) {
V_22 = F_2 ( V_4 , V_89 ) ;
if ( ! ( V_22 & V_90 ) )
return 0 ;
F_9 ( 100 , 1000 ) ;
}
F_17 ( V_35 , L_10 ) ;
return - V_91 ;
}
static T_2 F_34 ( int V_92 , void * V_93 )
{
struct V_1 * V_1 = V_93 ;
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_94 * V_95 = & V_4 -> V_95 ;
return F_35 ( V_95 ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_34 * V_35 = V_4 -> V_35 ;
T_1 V_22 ;
int V_12 ;
V_22 = F_2 ( V_4 , V_96 ) ;
V_22 &= ~ V_97 ;
V_22 |= V_98 ;
F_5 ( V_4 , V_96 , V_22 ) ;
if ( V_1 -> V_36 == V_37 )
F_27 ( V_1 -> V_39 ) ;
else
F_14 ( V_1 -> V_41 , V_42 ,
V_72 , 1 << 10 ) ;
V_12 = F_30 ( V_1 ) ;
if ( V_12 )
goto V_99;
if ( V_1 -> V_100 == 2 ) {
V_22 = F_2 ( V_4 , V_96 ) ;
V_22 &= ~ V_97 ;
V_22 |= V_101 ;
F_5 ( V_4 , V_96 , V_22 ) ;
V_22 = F_2 ( V_4 , V_89 ) ;
V_22 |= V_90 ;
F_5 ( V_4 , V_89 , V_22 ) ;
if ( V_1 -> V_36 != V_37 ) {
V_12 = F_33 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_11 ) ;
goto V_99;
}
}
V_12 = F_30 ( V_1 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_11 ) ;
goto V_99;
}
} else {
F_37 ( V_35 , L_12 ) ;
}
V_22 = F_2 ( V_4 , V_102 ) ;
F_37 ( V_35 , L_13 , ( V_22 >> 16 ) & 0xf ) ;
return 0 ;
V_99:
F_32 ( V_35 , L_14 ,
F_2 ( V_4 , V_87 ) ,
F_2 ( V_4 , V_88 ) ) ;
F_8 ( V_1 ) ;
return V_12 ;
}
static void F_38 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_39 ( V_95 ) ;
struct V_1 * V_1 = F_40 ( V_4 ) ;
F_12 ( V_1 ) ;
F_29 ( V_1 ) ;
F_22 ( V_1 ) ;
F_41 ( V_95 ) ;
F_36 ( V_1 ) ;
if ( F_42 ( V_103 ) )
F_43 ( V_95 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , V_88 ) &
V_104 ;
}
static int F_45 ( struct V_1 * V_1 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_94 * V_95 = & V_4 -> V_95 ;
struct V_34 * V_35 = & V_106 -> V_35 ;
int V_12 ;
if ( F_42 ( V_103 ) ) {
V_95 -> V_107 = F_46 ( V_106 , L_15 ) ;
if ( V_95 -> V_107 <= 0 ) {
F_17 ( V_35 , L_16 ) ;
return - V_108 ;
}
V_12 = F_47 ( V_35 , V_95 -> V_107 ,
F_34 ,
V_109 | V_110 ,
L_17 , V_1 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_18 ) ;
return V_12 ;
}
}
V_95 -> V_111 = - 1 ;
V_95 -> V_112 = & V_113 ;
V_12 = F_48 ( V_95 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_19 ) ;
return V_12 ;
}
return 0 ;
}
static int F_49 ( struct V_105 * V_106 )
{
struct V_34 * V_35 = & V_106 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_1 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = V_35 -> V_118 ;
int V_12 ;
V_1 = F_50 ( V_35 , sizeof( * V_1 ) , V_119 ) ;
if ( ! V_1 )
return - V_120 ;
V_4 = F_50 ( V_35 , sizeof( * V_4 ) , V_119 ) ;
if ( ! V_4 )
return - V_120 ;
V_4 -> V_35 = V_35 ;
V_4 -> V_112 = & V_121 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_36 =
(enum V_122 ) F_51 ( V_35 ) ;
V_115 = F_52 ( V_106 , V_123 , 0 ) ;
V_4 -> V_115 = F_53 ( V_35 , V_115 ) ;
if ( F_54 ( V_4 -> V_115 ) )
return F_55 ( V_4 -> V_115 ) ;
V_1 -> V_67 = F_56 ( V_117 , L_20 , 0 ) ;
V_1 -> V_68 = F_57 ( V_117 ,
L_21 ) ;
if ( F_24 ( V_1 -> V_67 ) ) {
V_12 = F_58 ( V_35 , V_1 -> V_67 ,
V_1 -> V_68 ?
V_124 :
V_125 ,
L_22 ) ;
if ( V_12 ) {
F_17 ( V_35 , L_23 ) ;
return V_12 ;
}
} else if ( V_1 -> V_67 == - V_126 ) {
return V_1 -> V_67 ;
}
V_1 -> V_60 = F_59 ( V_35 , L_24 ) ;
if ( F_54 ( V_1 -> V_60 ) ) {
F_17 ( V_35 , L_25 ) ;
return F_55 ( V_1 -> V_60 ) ;
}
V_1 -> V_62 = F_59 ( V_35 , L_26 ) ;
if ( F_54 ( V_1 -> V_62 ) ) {
F_17 ( V_35 , L_27 ) ;
return F_55 ( V_1 -> V_62 ) ;
}
V_1 -> V_64 = F_59 ( V_35 , L_28 ) ;
if ( F_54 ( V_1 -> V_64 ) ) {
F_17 ( V_35 , L_29 ) ;
return F_55 ( V_1 -> V_64 ) ;
}
switch ( V_1 -> V_36 ) {
case V_40 :
V_1 -> V_53 = F_59 ( V_35 ,
L_30 ) ;
if ( F_54 ( V_1 -> V_53 ) ) {
F_17 ( V_35 , L_31 ) ;
return F_55 ( V_1 -> V_53 ) ;
}
break;
case V_37 :
V_1 -> V_38 = F_60 ( V_35 ,
L_32 ) ;
if ( F_54 ( V_1 -> V_38 ) ) {
F_17 ( V_35 , L_33 ) ;
return F_55 ( V_1 -> V_38 ) ;
}
V_1 -> V_39 = F_60 ( V_35 , L_34 ) ;
if ( F_54 ( V_1 -> V_39 ) ) {
F_17 ( V_35 , L_35 ) ;
return F_55 ( V_1 -> V_39 ) ;
}
break;
default:
break;
}
V_1 -> V_41 =
F_61 ( L_36 ) ;
if ( F_54 ( V_1 -> V_41 ) ) {
F_17 ( V_35 , L_37 ) ;
return F_55 ( V_1 -> V_41 ) ;
}
if ( F_62 ( V_117 , L_38 ,
& V_1 -> V_76 ) )
V_1 -> V_76 = 0 ;
if ( F_62 ( V_117 , L_39 ,
& V_1 -> V_78 ) )
V_1 -> V_78 = 0 ;
if ( F_62 ( V_117 , L_40 ,
& V_1 -> V_80 ) )
V_1 -> V_80 = 20 ;
if ( F_62 ( V_117 , L_41 ,
& V_1 -> V_82 ) )
V_1 -> V_82 = 127 ;
if ( F_62 ( V_117 , L_42 ,
& V_1 -> V_84 ) )
V_1 -> V_84 = 127 ;
V_12 = F_62 ( V_117 , L_43 ,
& V_1 -> V_100 ) ;
if ( V_12 )
V_1 -> V_100 = 1 ;
V_1 -> V_52 = F_63 ( & V_106 -> V_35 , L_44 ) ;
if ( F_54 ( V_1 -> V_52 ) ) {
if ( F_55 ( V_1 -> V_52 ) == - V_126 )
return - V_126 ;
V_1 -> V_52 = NULL ;
}
F_64 ( V_106 , V_1 ) ;
V_12 = F_45 ( V_1 , V_106 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_65 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = F_66 ( V_106 ) ;
F_12 ( V_1 ) ;
}
static int T_3 F_67 ( void )
{
F_68 ( 8 , F_10 , V_127 , 0 ,
L_45 ) ;
return F_69 ( & V_128 ) ;
}
