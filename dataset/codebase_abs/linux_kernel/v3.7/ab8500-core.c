static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = F_2 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_6 ,
T_2 V_3 )
{
int V_4 ;
V_4 = F_5 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 ,
& V_6 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
T_2 V_3 ;
V_4 = F_7 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
return ( int ) V_3 ;
}
static int F_8 ( struct V_7 * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_5 )
return - V_8 ;
V_1 = F_9 ( V_5 -> V_9 ) ;
return V_1 ? ( int ) V_1 -> V_10 : - V_8 ;
}
static int F_10 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 V_3 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_11 ( V_1 -> V_5 , L_2 , V_2 , V_3 ) ;
F_12 ( & V_1 -> V_13 ) ;
V_4 = V_1 -> V_14 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_4 ) ;
F_13 ( & V_1 -> V_13 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_5 , T_2 V_11 ,
T_2 V_12 , T_2 V_15 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_10 ( V_1 , V_11 , V_12 , V_15 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 * V_15 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_12 ( & V_1 -> V_13 ) ;
V_4 = V_1 -> V_17 ( V_1 , V_2 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_4 ) ;
else
* V_15 = V_4 ;
F_13 ( & V_1 -> V_13 ) ;
F_11 ( V_1 -> V_5 , L_5 , V_2 , V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_7 * V_5 , T_2 V_11 ,
T_2 V_12 , T_2 * V_15 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_17 ( V_1 , V_11 , V_12 , V_15 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_11 ,
T_2 V_12 , T_2 V_18 , T_2 V_19 )
{
int V_4 ;
T_1 V_2 = ( ( T_1 ) V_11 ) << 8 | V_12 ;
F_12 ( & V_1 -> V_13 ) ;
if ( V_1 -> V_20 == NULL ) {
T_2 V_3 ;
V_4 = V_1 -> V_17 ( V_1 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_4 ) ;
goto V_21;
}
V_3 = ( T_2 ) V_4 ;
V_3 = ( ~ V_18 & V_3 ) | ( V_18 & V_19 ) ;
V_4 = V_1 -> V_14 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_4 ) ;
F_11 ( V_1 -> V_5 , L_6 , V_2 ,
V_3 ) ;
goto V_21;
}
V_4 = V_1 -> V_20 ( V_1 , V_2 , V_18 , V_19 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_7 , V_2 ,
V_4 ) ;
V_21:
F_13 ( & V_1 -> V_13 ) ;
return V_4 ;
}
static int F_20 ( struct V_7 * V_5 ,
T_2 V_11 , T_2 V_12 , T_2 V_18 , T_2 V_19 )
{
int V_4 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
V_4 = F_19 ( V_1 , V_11 , V_12 ,
V_18 , V_19 ) ;
F_16 ( & V_1 -> V_16 ) ;
return V_4 ;
}
static void F_21 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
F_12 ( & V_1 -> V_23 ) ;
F_15 ( & V_1 -> V_16 ) ;
}
static void F_23 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
T_2 V_26 = V_1 -> V_27 [ V_24 ] ;
T_2 V_28 = V_1 -> V_6 [ V_24 ] ;
int V_12 ;
if ( V_28 == V_26 )
continue;
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
V_1 -> V_27 [ V_24 ] = V_28 ;
V_12 = V_30 + V_1 -> V_29 [ V_24 ] ;
F_10 ( V_1 , V_31 , V_12 , V_28 ) ;
}
F_16 ( & V_1 -> V_16 ) ;
F_13 ( & V_1 -> V_23 ) ;
}
static void F_25 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_32 = V_3 -> V_33 ;
int V_34 = V_32 / 8 ;
int V_6 = 1 << ( V_32 % 8 ) ;
V_1 -> V_6 [ V_34 ] |= V_6 ;
}
static void F_26 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
int V_32 = V_3 -> V_33 ;
int V_34 = V_32 / 8 ;
int V_6 = 1 << ( V_32 % 8 ) ;
V_1 -> V_6 [ V_34 ] &= ~ V_6 ;
}
static int F_27 ( struct V_1 * V_1 ,
int V_35 , T_2 V_36 )
{
int V_37 = F_28 ( V_36 ) ;
int line , V_24 ;
do {
V_37 = F_28 ( V_36 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
if ( V_1 -> V_29 [ V_24 ] == V_35 )
break;
if ( V_24 >= V_1 -> V_25 ) {
F_3 ( V_1 -> V_5 , L_8 ,
V_35 ) ;
return - V_38 ;
}
line = ( V_24 << 3 ) + V_37 ;
V_36 &= ~ ( 1 << V_37 ) ;
F_29 ( V_1 -> V_39 + line ) ;
} while ( V_36 );
return 0 ;
}
static int F_30 ( struct V_1 * V_1 ,
int V_40 , T_2 V_41 )
{
int V_42 , V_43 ;
T_2 V_35 , V_36 ;
do {
V_42 = F_28 ( V_41 ) ;
V_35 = ( V_40 << 3 ) + V_42 ;
if ( F_31 ( V_35 == 17 ) )
V_35 = 24 ;
V_43 = F_17 ( V_1 ,
V_31 ,
V_44 + V_35 ,
& V_36 ) ;
if ( V_43 < 0 || V_36 == 0 )
goto V_45;
V_43 = F_27 ( V_1 ,
V_35 , V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45:
V_41 &= ~ ( 1 << V_42 ) ;
} while ( V_41 );
return 0 ;
}
static T_3 F_32 ( int V_46 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
T_2 V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ ) {
int V_43 ;
T_2 V_41 ;
V_43 = F_17 ( V_1 , V_31 ,
V_48 + V_24 , & V_41 ) ;
if ( V_43 < 0 || V_41 == 0 )
continue;
V_43 = F_30 ( V_1 , V_24 , V_41 ) ;
if ( V_43 < 0 )
break;
}
return V_49 ;
}
static int F_33 ( struct V_1 * V_1 , int V_46 )
{
if ( ! V_1 )
return - V_8 ;
return F_34 ( V_1 -> V_50 , V_46 ) ;
}
static T_3 F_35 ( int V_46 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
int V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
int V_51 = V_1 -> V_29 [ V_24 ] ;
int V_43 ;
T_2 V_15 ;
if ( V_51 == 11 && F_24 ( V_1 ) )
continue;
V_43 = F_17 ( V_1 , V_31 ,
V_44 + V_51 , & V_15 ) ;
if ( V_43 < 0 || V_15 == 0 )
continue;
do {
int V_52 = F_28 ( V_15 ) ;
int line = V_24 * 8 + V_52 ;
int V_53 = F_33 ( V_1 , line ) ;
F_29 ( V_53 ) ;
V_15 &= ~ ( 1 << V_52 ) ;
} while ( V_15 );
}
F_16 ( & V_1 -> V_16 ) ;
return V_49 ;
}
static int F_36 ( struct V_54 * V_55 , unsigned int V_53 ,
T_4 V_33 )
{
struct V_1 * V_1 = V_55 -> V_56 ;
if ( ! V_1 )
return - V_8 ;
F_37 ( V_53 , V_1 ) ;
F_38 ( V_53 , & V_57 ,
V_58 ) ;
F_39 ( V_53 , 1 ) ;
#ifdef F_40
F_41 ( V_53 , V_59 ) ;
#else
F_42 ( V_53 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_60 * V_61 )
{
int V_62 ;
if ( F_44 ( V_1 ) )
V_62 = V_63 ;
else if ( F_45 ( V_1 ) )
V_62 = V_64 ;
else
V_62 = V_65 ;
if ( V_1 -> V_39 ) {
V_1 -> V_50 = F_46 (
NULL , V_62 , V_1 -> V_39 ,
0 , & V_66 , V_1 ) ;
}
else {
V_1 -> V_50 = F_47 (
V_61 , V_62 , & V_66 , V_1 ) ;
}
if ( ! V_1 -> V_50 ) {
F_3 ( V_1 -> V_5 , L_10 ) ;
return - V_67 ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_1 )
{
if ( F_49 ( & V_1 -> V_16 ) )
return - V_8 ;
else
return 0 ;
}
static T_5 F_50 ( struct V_7 * V_5 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
return sprintf ( V_70 , L_11 , V_1 ? V_1 -> V_10 : - V_8 ) ;
}
static T_5 F_51 ( struct V_7 * V_5 ,
struct V_68 * V_69 , char * V_70 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_71 ,
V_72 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_70 , L_11 , V_15 ) ;
}
static T_5 F_52 ( struct V_7 * V_5 ,
struct V_68 * V_69 , char * V_70 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_73 ,
V_74 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_70 , L_11 , V_15 ) ;
}
static T_5 F_53 ( struct V_7 * V_5 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_1 * V_1 ;
int V_4 ;
T_2 V_15 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_75 ,
V_76 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_70 , L_12 ,
( V_15 & V_77 ) ? 1 : 0 ) ;
}
static T_5 F_54 ( struct V_7 * V_5 ,
struct V_68 * V_69 , const char * V_70 , T_6 V_78 )
{
struct V_1 * V_1 ;
int V_4 = V_78 ;
int V_79 ;
T_2 V_19 ;
V_1 = F_9 ( V_5 ) ;
if ( V_78 > 0 ) {
switch ( V_70 [ 0 ] ) {
case '0' :
V_19 = 0 ;
break;
case '1' :
V_19 = V_77 ;
break;
default:
goto exit;
}
V_79 = F_19 ( V_1 ,
V_75 , V_76 ,
V_77 , V_19 ) ;
if ( V_79 )
F_55 ( V_1 -> V_5 ,
L_13 ,
V_70 [ 0 ] , V_79 ) ;
}
exit:
return V_4 ;
}
static int T_7 F_56 ( struct V_80 * V_81 )
{
static char * V_82 [] = {
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 } ;
struct V_83 * V_84 = F_57 ( & V_81 -> V_5 ) ;
const struct V_85 * V_86 = F_58 ( V_81 ) ;
enum V_87 V_88 = V_89 ;
struct V_60 * V_61 = V_81 -> V_5 . V_90 ;
struct V_1 * V_1 ;
struct V_91 * V_91 ;
int V_4 ;
int V_24 ;
T_2 V_15 ;
V_1 = F_59 ( sizeof *V_1 , V_92 ) ;
if ( ! V_1 )
return - V_93 ;
if ( V_84 )
V_1 -> V_39 = V_84 -> V_39 ;
V_1 -> V_5 = & V_81 -> V_5 ;
V_91 = F_60 ( V_81 , V_94 , 0 ) ;
if ( ! V_91 ) {
V_4 = - V_95 ;
goto V_96;
}
V_1 -> V_46 = V_91 -> V_97 ;
V_1 -> V_17 = F_6 ;
V_1 -> V_14 = F_1 ;
V_1 -> V_20 = F_4 ;
F_61 ( & V_1 -> V_13 ) ;
F_61 ( & V_1 -> V_23 ) ;
F_62 ( & V_1 -> V_16 , 0 ) ;
F_63 ( V_81 , V_1 ) ;
if ( V_86 )
V_88 = V_86 -> V_98 ;
if ( V_88 != V_89 )
V_1 -> V_88 = V_88 ;
else {
V_4 = F_17 ( V_1 , V_99 ,
V_100 , & V_15 ) ;
if ( V_4 < 0 )
goto V_96;
V_1 -> V_88 = V_15 ;
}
V_4 = F_17 ( V_1 , V_99 ,
V_101 , & V_15 ) ;
if ( V_4 < 0 )
goto V_96;
V_1 -> V_10 = V_15 ;
F_55 ( V_1 -> V_5 , L_22 ,
V_102 [ V_1 -> V_88 ] ,
V_1 -> V_10 >> 4 ,
V_1 -> V_10 & 0x0F ) ;
if ( F_44 ( V_1 ) || F_45 ( V_1 ) ) {
V_1 -> V_25 = V_103 ;
V_1 -> V_29 = V_104 ;
} else {
V_1 -> V_25 = V_105 ;
V_1 -> V_29 = V_106 ;
}
V_1 -> V_6 = F_59 ( V_1 -> V_25 , V_92 ) ;
if ( ! V_1 -> V_6 )
return - V_93 ;
V_1 -> V_27 = F_59 ( V_1 -> V_25 , V_92 ) ;
if ( ! V_1 -> V_27 ) {
V_4 = - V_93 ;
goto V_107;
}
V_4 = F_17 ( V_1 , V_71 ,
V_72 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_55 ( V_1 -> V_5 , L_23 , V_15 ) ;
if ( V_15 ) {
for ( V_24 = 0 ; V_24 < F_64 ( V_82 ) ; V_24 ++ ) {
if ( V_15 & 1 )
F_65 ( V_108 L_24 ,
V_82 [ V_24 ] ) ;
V_15 = V_15 >> 1 ;
}
F_65 ( V_108 L_25 ) ;
} else {
F_65 ( V_108 L_26 ) ;
}
if ( V_84 && V_84 -> V_109 )
V_84 -> V_109 ( V_1 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
F_17 ( V_1 , V_31 ,
V_44 + V_1 -> V_29 [ V_24 ] ,
& V_15 ) ;
F_10 ( V_1 , V_31 ,
V_30 + V_1 -> V_29 [ V_24 ] , 0xff ) ;
}
V_4 = F_66 ( V_1 -> V_5 , & V_110 ) ;
if ( V_4 )
goto V_111;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
V_1 -> V_6 [ V_24 ] = V_1 -> V_27 [ V_24 ] = 0xff ;
V_4 = F_43 ( V_1 , V_61 ) ;
if ( V_4 )
goto V_111;
if ( F_44 ( V_1 ) ) {
V_4 = F_67 ( V_1 -> V_46 , NULL ,
F_32 ,
V_112 | V_113 ,
L_27 , V_1 ) ;
}
else {
V_4 = F_67 ( V_1 -> V_46 , NULL ,
F_35 ,
V_112 | V_113 ,
L_27 , V_1 ) ;
if ( V_4 )
goto V_111;
}
V_4 = F_68 ( V_1 -> V_5 , 0 , V_114 ,
F_64 ( V_114 ) , NULL ,
V_1 -> V_39 , V_1 -> V_50 ) ;
if ( V_4 )
goto V_115;
if ( F_44 ( V_1 ) )
V_4 = F_68 ( V_1 -> V_5 , 0 , V_116 ,
F_64 ( V_116 ) , NULL ,
V_1 -> V_39 , V_1 -> V_50 ) ;
else
V_4 = F_68 ( V_1 -> V_5 , 0 , V_117 ,
F_64 ( V_117 ) , NULL ,
V_1 -> V_39 , V_1 -> V_50 ) ;
if ( V_4 )
goto V_115;
if ( F_44 ( V_1 ) || F_45 ( V_1 ) )
V_4 = F_68 ( V_1 -> V_5 , 0 , V_118 ,
F_64 ( V_118 ) , NULL ,
V_1 -> V_39 , V_1 -> V_50 ) ;
if ( V_4 )
goto V_115;
if ( ! V_119 ) {
V_4 = F_68 ( V_1 -> V_5 , 0 , V_120 ,
F_64 ( V_120 ) , NULL ,
V_1 -> V_39 , V_1 -> V_50 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_28 ) ;
}
if ( F_44 ( V_1 ) )
V_4 = F_69 ( & V_1 -> V_5 -> V_121 ,
& V_122 ) ;
else
V_4 = F_69 ( & V_1 -> V_5 -> V_121 ,
& V_123 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_29 ) ;
return V_4 ;
V_115:
F_70 ( V_1 -> V_46 , V_1 ) ;
V_111:
F_71 ( V_1 -> V_27 ) ;
V_107:
F_71 ( V_1 -> V_6 ) ;
V_96:
F_71 ( V_1 ) ;
return V_4 ;
}
static int T_8 F_72 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_73 ( V_81 ) ;
if ( F_44 ( V_1 ) )
F_74 ( & V_1 -> V_5 -> V_121 , & V_122 ) ;
else
F_74 ( & V_1 -> V_5 -> V_121 , & V_123 ) ;
F_75 ( V_1 -> V_5 ) ;
F_70 ( V_1 -> V_46 , V_1 ) ;
F_71 ( V_1 -> V_27 ) ;
F_71 ( V_1 -> V_6 ) ;
F_71 ( V_1 ) ;
return 0 ;
}
static int T_9 F_76 ( void )
{
return F_77 ( & V_124 ) ;
}
static void T_10 F_78 ( void )
{
F_79 ( & V_124 ) ;
}
