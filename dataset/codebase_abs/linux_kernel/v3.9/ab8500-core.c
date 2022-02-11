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
if ( V_32 >= V_35 && V_32 <= V_36 )
V_1 -> V_6 [ V_34 + 2 ] |= V_6 ;
if ( V_32 >= V_37 && V_32 <= V_38 )
V_1 -> V_6 [ V_34 + 1 ] |= V_6 ;
if ( V_32 == V_39 || V_32 == V_40 )
V_1 -> V_6 [ V_34 ] |= ( V_6 << 1 ) ;
}
static void F_26 ( struct V_22 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
unsigned int type = F_27 ( V_3 ) ;
int V_32 = V_3 -> V_33 ;
int V_34 = V_32 / 8 ;
int V_6 = 1 << ( V_32 % 8 ) ;
if ( type & V_41 )
V_1 -> V_6 [ V_34 ] &= ~ V_6 ;
if ( type & V_42 ) {
if ( V_32 >= V_35 && V_32 <= V_36 )
V_1 -> V_6 [ V_34 + 2 ] &= ~ V_6 ;
else if ( V_32 >= V_37 && V_32 <= V_38 )
V_1 -> V_6 [ V_34 + 1 ] &= ~ V_6 ;
else if ( V_32 == V_39 || V_32 == V_40 )
V_1 -> V_6 [ V_34 ] &= ~ ( V_6 << 1 ) ;
else
V_1 -> V_6 [ V_34 ] &= ~ V_6 ;
} else {
V_1 -> V_6 [ V_34 ] &= ~ V_6 ;
}
}
static int F_28 ( struct V_22 * V_3 , unsigned int type )
{
return 0 ;
}
static int F_29 ( struct V_1 * V_1 ,
int V_43 , T_2 V_44 )
{
int V_45 = F_30 ( V_44 ) ;
int line , V_24 ;
do {
V_45 = F_30 ( V_44 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
if ( V_1 -> V_29 [ V_24 ] == V_43 )
break;
if ( V_24 >= V_1 -> V_25 ) {
F_3 ( V_1 -> V_5 , L_8 ,
V_43 ) ;
return - V_46 ;
}
line = ( V_24 << 3 ) + V_45 ;
V_44 &= ~ ( 1 << V_45 ) ;
if ( line >= V_47 && line <= V_48 )
line -= 16 ;
if ( line >= V_49 && line <= V_50 )
line -= 8 ;
if ( line == V_51 || line == V_52 )
line += 1 ;
F_31 ( V_1 -> V_53 + line ) ;
} while ( V_44 );
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
int V_54 , T_2 V_55 )
{
int V_56 , V_57 ;
T_2 V_43 , V_44 ;
do {
V_56 = F_30 ( V_55 ) ;
V_43 = ( V_54 << 3 ) + V_56 ;
if ( F_33 ( V_43 == 17 ) )
V_43 = 24 ;
V_57 = F_17 ( V_1 ,
V_31 ,
V_58 + V_43 ,
& V_44 ) ;
if ( V_57 < 0 || V_44 == 0 )
goto V_59;
V_57 = F_29 ( V_1 ,
V_43 , V_44 ) ;
if ( V_57 < 0 )
return V_57 ;
V_59:
V_55 &= ~ ( 1 << V_56 ) ;
} while ( V_55 );
return 0 ;
}
static T_3 F_34 ( int V_60 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
T_2 V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
for ( V_24 = 0 ; V_24 < V_61 ; V_24 ++ ) {
int V_57 ;
T_2 V_55 ;
V_57 = F_17 ( V_1 , V_31 ,
V_62 + V_24 , & V_55 ) ;
if ( V_57 < 0 || V_55 == 0 )
continue;
V_57 = F_32 ( V_1 , V_24 , V_55 ) ;
if ( V_57 < 0 )
break;
}
return V_63 ;
}
static int F_35 ( struct V_1 * V_1 , int V_60 )
{
if ( ! V_1 )
return - V_8 ;
return F_36 ( V_1 -> V_64 , V_60 ) ;
}
static T_3 F_37 ( int V_60 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
int V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
F_15 ( & V_1 -> V_16 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
int V_65 = V_1 -> V_29 [ V_24 ] ;
int V_57 ;
T_2 V_15 ;
if ( V_65 == 11 && F_24 ( V_1 ) )
continue;
V_57 = F_17 ( V_1 , V_31 ,
V_58 + V_65 , & V_15 ) ;
if ( V_57 < 0 || V_15 == 0 )
continue;
do {
int V_66 = F_30 ( V_15 ) ;
int line = V_24 * 8 + V_66 ;
int V_67 = F_35 ( V_1 , line ) ;
F_31 ( V_67 ) ;
F_38 ( line ) ;
V_15 &= ~ ( 1 << V_66 ) ;
} while ( V_15 );
}
F_16 ( & V_1 -> V_16 ) ;
return V_63 ;
}
static int F_39 ( struct V_68 * V_69 , unsigned int V_67 ,
T_4 V_33 )
{
struct V_1 * V_1 = V_69 -> V_70 ;
if ( ! V_1 )
return - V_8 ;
F_40 ( V_67 , V_1 ) ;
F_41 ( V_67 , & V_71 ,
V_72 ) ;
F_42 ( V_67 , 1 ) ;
#ifdef F_43
F_44 ( V_67 , V_73 ) ;
#else
F_45 ( V_67 ) ;
#endif
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
int V_76 ;
if ( F_47 ( V_1 ) )
V_76 = V_77 ;
else if ( F_48 ( V_1 ) )
V_76 = V_78 ;
else
V_76 = V_79 ;
V_1 -> V_64 = F_49 ( NULL ,
V_76 , V_1 -> V_53 ,
& V_80 , V_1 ) ;
if ( ! V_1 -> V_64 ) {
F_3 ( V_1 -> V_5 , L_10 ) ;
return - V_81 ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_1 )
{
if ( F_51 ( & V_1 -> V_16 ) )
return - V_8 ;
else
return 0 ;
}
static T_5 F_52 ( struct V_7 * V_5 ,
struct V_82 * V_83 , char * V_84 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
return sprintf ( V_84 , L_11 , V_1 ? V_1 -> V_10 : - V_8 ) ;
}
static T_5 F_53 ( struct V_7 * V_5 ,
struct V_82 * V_83 , char * V_84 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_85 ,
V_86 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_84 , L_11 , V_15 ) ;
}
static T_5 F_54 ( struct V_7 * V_5 ,
struct V_82 * V_83 , char * V_84 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_87 ,
V_88 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_84 , L_11 , V_15 ) ;
}
static T_5 F_55 ( struct V_7 * V_5 ,
struct V_82 * V_83 , char * V_84 )
{
struct V_1 * V_1 ;
int V_4 ;
T_2 V_15 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_89 ,
V_90 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_84 , L_12 ,
( V_15 & V_91 ) ? 1 : 0 ) ;
}
static T_5 F_56 ( struct V_7 * V_5 ,
struct V_82 * V_83 , const char * V_84 , T_6 V_92 )
{
struct V_1 * V_1 ;
int V_4 = V_92 ;
int V_93 ;
T_2 V_19 ;
V_1 = F_9 ( V_5 ) ;
if ( V_92 > 0 ) {
switch ( V_84 [ 0 ] ) {
case '0' :
V_19 = 0 ;
break;
case '1' :
V_19 = V_91 ;
break;
default:
goto exit;
}
V_93 = F_19 ( V_1 ,
V_89 , V_90 ,
V_91 , V_19 ) ;
if ( V_93 )
F_57 ( V_1 -> V_5 ,
L_13 ,
V_84 [ 0 ] , V_93 ) ;
}
exit:
return V_4 ;
}
static int F_58 ( struct V_94 * V_95 )
{
static char * V_96 [] = {
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 } ;
struct V_97 * V_98 = F_59 ( & V_95 -> V_5 ) ;
const struct V_99 * V_100 = F_60 ( V_95 ) ;
enum V_101 V_102 = V_103 ;
struct V_74 * V_75 = V_95 -> V_5 . V_104 ;
struct V_1 * V_1 ;
struct V_105 * V_105 ;
int V_4 ;
int V_24 ;
T_2 V_15 ;
V_1 = F_61 ( & V_95 -> V_5 , sizeof *V_1 , V_106 ) ;
if ( ! V_1 )
return - V_107 ;
if ( V_98 )
V_1 -> V_53 = V_98 -> V_53 ;
V_1 -> V_5 = & V_95 -> V_5 ;
V_105 = F_62 ( V_95 , V_108 , 0 ) ;
if ( ! V_105 )
return - V_109 ;
V_1 -> V_60 = V_105 -> V_110 ;
V_1 -> V_17 = F_6 ;
V_1 -> V_14 = F_1 ;
V_1 -> V_20 = F_4 ;
F_63 ( & V_1 -> V_13 ) ;
F_63 ( & V_1 -> V_23 ) ;
F_64 ( & V_1 -> V_16 , 0 ) ;
F_65 ( V_95 , V_1 ) ;
if ( V_100 )
V_102 = V_100 -> V_111 ;
if ( V_102 != V_103 )
V_1 -> V_102 = V_102 ;
else {
V_4 = F_17 ( V_1 , V_112 ,
V_113 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_102 = V_15 ;
}
V_4 = F_17 ( V_1 , V_112 ,
V_114 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_10 = V_15 ;
F_57 ( V_1 -> V_5 , L_22 ,
V_115 [ V_1 -> V_102 ] ,
V_1 -> V_10 >> 4 ,
V_1 -> V_10 & 0x0F ) ;
if ( F_47 ( V_1 ) || F_48 ( V_1 ) ) {
V_1 -> V_25 = V_116 ;
V_1 -> V_29 = V_117 ;
} else {
V_1 -> V_25 = V_118 ;
V_1 -> V_29 = V_119 ;
}
V_1 -> V_6 = F_61 ( & V_95 -> V_5 , V_1 -> V_25 , V_106 ) ;
if ( ! V_1 -> V_6 )
return - V_107 ;
V_1 -> V_27 = F_61 ( & V_95 -> V_5 , V_1 -> V_25 , V_106 ) ;
if ( ! V_1 -> V_27 )
return - V_107 ;
V_4 = F_17 ( V_1 , V_85 ,
V_86 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_57 ( V_1 -> V_5 , L_23 , V_15 ) ;
if ( V_15 ) {
for ( V_24 = 0 ; V_24 < F_66 ( V_96 ) ; V_24 ++ ) {
if ( V_15 & 1 )
F_67 ( V_120 L_24 ,
V_96 [ V_24 ] ) ;
V_15 = V_15 >> 1 ;
}
F_67 ( V_120 L_25 ) ;
} else {
F_67 ( V_120 L_26 ) ;
}
if ( V_98 && V_98 -> V_121 )
V_98 -> V_121 ( V_1 ) ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
F_17 ( V_1 , V_31 ,
V_58 + V_1 -> V_29 [ V_24 ] ,
& V_15 ) ;
F_10 ( V_1 , V_31 ,
V_30 + V_1 -> V_29 [ V_24 ] , 0xff ) ;
}
V_4 = F_68 ( V_1 -> V_5 , & V_122 ) ;
if ( V_4 )
return V_4 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
V_1 -> V_6 [ V_24 ] = V_1 -> V_27 [ V_24 ] = 0xff ;
V_4 = F_46 ( V_1 , V_75 ) ;
if ( V_4 )
return V_4 ;
if ( F_47 ( V_1 ) ) {
V_4 = F_69 ( & V_95 -> V_5 , V_1 -> V_60 , NULL ,
F_34 ,
V_123 | V_124 ,
L_27 , V_1 ) ;
}
else {
V_4 = F_69 ( & V_95 -> V_5 , V_1 -> V_60 , NULL ,
F_37 ,
V_123 | V_124 ,
L_27 , V_1 ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_70 ( V_1 -> V_5 , 0 , V_125 ,
F_66 ( V_125 ) , NULL ,
V_1 -> V_53 , V_1 -> V_64 ) ;
if ( V_4 )
return V_4 ;
if ( F_47 ( V_1 ) )
V_4 = F_70 ( V_1 -> V_5 , 0 , V_126 ,
F_66 ( V_126 ) , NULL ,
V_1 -> V_53 , V_1 -> V_64 ) ;
else
V_4 = F_70 ( V_1 -> V_5 , 0 , V_127 ,
F_66 ( V_127 ) , NULL ,
V_1 -> V_53 , V_1 -> V_64 ) ;
if ( V_4 )
return V_4 ;
if ( F_47 ( V_1 ) || F_48 ( V_1 ) )
V_4 = F_70 ( V_1 -> V_5 , 0 , V_128 ,
F_66 ( V_128 ) , NULL ,
V_1 -> V_53 , V_1 -> V_64 ) ;
if ( V_4 )
return V_4 ;
if ( ! V_129 ) {
V_4 = F_70 ( V_1 -> V_5 , 0 , V_130 ,
F_66 ( V_130 ) , NULL ,
V_1 -> V_53 , V_1 -> V_64 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_28 ) ;
}
if ( F_47 ( V_1 ) )
V_4 = F_71 ( & V_1 -> V_5 -> V_131 ,
& V_132 ) ;
else
V_4 = F_71 ( & V_1 -> V_5 -> V_131 ,
& V_133 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_29 ) ;
return V_4 ;
}
static int F_72 ( struct V_94 * V_95 )
{
struct V_1 * V_1 = F_73 ( V_95 ) ;
if ( F_47 ( V_1 ) )
F_74 ( & V_1 -> V_5 -> V_131 , & V_132 ) ;
else
F_74 ( & V_1 -> V_5 -> V_131 , & V_133 ) ;
F_75 ( V_1 -> V_5 ) ;
return 0 ;
}
static int T_7 F_76 ( void )
{
return F_77 ( & V_134 ) ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_134 ) ;
}
