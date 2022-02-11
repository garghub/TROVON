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
if ( V_1 -> V_29 [ V_24 ] < 0 )
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
static void F_29 ( T_2 * V_32 , int V_24 )
{
if ( F_30 ( * V_32 == 17 ) )
* V_32 = 24 ;
if ( F_30 ( * V_32 == 16 ) )
* V_32 = 25 ;
if ( ( V_24 == 3 ) && ( * V_32 >= 24 ) )
* V_32 += 2 ;
}
static int F_31 ( struct V_1 * V_1 ,
int V_43 , T_2 V_44 )
{
int V_45 , line , V_24 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
if ( V_1 -> V_29 [ V_24 ] == V_43 )
break;
if ( V_24 >= V_1 -> V_25 ) {
F_3 ( V_1 -> V_5 , L_8 ,
V_43 ) ;
return - V_46 ;
}
V_44 &= ~ V_1 -> V_6 [ V_24 ] ;
while ( V_44 ) {
V_45 = F_32 ( V_44 ) ;
line = ( V_24 << 3 ) + V_45 ;
V_44 &= ~ ( 1 << V_45 ) ;
if ( line >= V_47 && line <= V_48 )
line -= 16 ;
if ( line >= V_49 && line <= V_50 )
line -= 8 ;
if ( line == V_51 || line == V_52 )
line += 1 ;
F_33 ( V_1 -> V_53 + line ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 ,
int V_54 , T_2 V_55 )
{
int V_56 , V_57 ;
T_2 V_43 , V_44 ;
do {
V_56 = F_32 ( V_55 ) ;
V_43 = ( V_54 << 3 ) + V_56 ;
F_29 ( & V_43 , V_54 ) ;
V_57 = F_17 ( V_1 ,
V_31 ,
V_58 + V_43 ,
& V_44 ) ;
if ( V_57 < 0 || V_44 == 0 )
goto V_59;
V_57 = F_31 ( V_1 ,
V_43 , V_44 ) ;
if ( V_57 < 0 )
return V_57 ;
V_59:
V_55 &= ~ ( 1 << V_56 ) ;
} while ( V_55 );
return 0 ;
}
static T_3 F_35 ( int V_60 , void * V_5 )
{
struct V_1 * V_1 = V_5 ;
T_2 V_24 ;
F_11 ( V_1 -> V_5 , L_9 ) ;
for ( V_24 = 0 ; V_24 < ( V_1 -> V_61 ) ; V_24 ++ ) {
int V_57 ;
T_2 V_55 ;
V_57 = F_17 ( V_1 , V_31 ,
V_62 + V_24 , & V_55 ) ;
if ( V_57 < 0 || V_55 == 0 )
continue;
V_57 = F_34 ( V_1 , V_24 , V_55 ) ;
if ( V_57 < 0 )
break;
}
return V_63 ;
}
static int F_36 ( struct V_64 * V_65 , unsigned int V_66 ,
T_4 V_33 )
{
struct V_1 * V_1 = V_65 -> V_67 ;
if ( ! V_1 )
return - V_8 ;
F_37 ( V_66 , V_1 ) ;
F_38 ( V_66 , & V_68 ,
V_69 ) ;
F_39 ( V_66 , 1 ) ;
#ifdef F_40
F_41 ( V_66 , V_70 ) ;
#else
F_42 ( V_66 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_71 * V_72 )
{
int V_73 ;
if ( F_44 ( V_1 ) )
V_73 = V_74 ;
else if ( F_45 ( V_1 ) )
V_73 = V_75 ;
else if ( F_46 ( V_1 ) )
V_73 = V_76 ;
else
V_73 = V_77 ;
V_1 -> V_78 = F_47 ( NULL ,
V_73 , V_1 -> V_53 ,
& V_79 , V_1 ) ;
if ( ! V_1 -> V_78 ) {
F_3 ( V_1 -> V_5 , L_10 ) ;
return - V_80 ;
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
struct V_81 * V_82 , char * V_83 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
return sprintf ( V_83 , L_11 , V_1 ? V_1 -> V_10 : - V_8 ) ;
}
static T_5 F_51 ( struct V_7 * V_5 ,
struct V_81 * V_82 , char * V_83 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_84 ,
V_85 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_83 , L_11 , V_15 ) ;
}
void F_52 ( T_2 V_6 , T_2 V_86 )
{
F_53 ( & V_87 ) ;
V_88 = V_6 ;
V_89 = V_86 ;
F_54 ( & V_87 ) ;
}
static T_5 F_55 ( struct V_7 * V_5 ,
struct V_81 * V_82 , char * V_83 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_90 ,
V_91 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_45 ( V_1 ) ) {
F_53 ( & V_87 ) ;
V_15 = ( V_15 & V_88 ) | V_89 ;
F_54 ( & V_87 ) ;
}
return sprintf ( V_83 , L_11 , V_15 ) ;
}
static T_5 F_56 ( struct V_7 * V_5 ,
struct V_81 * V_82 , char * V_83 )
{
int V_4 ;
T_2 V_15 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_90 ,
V_92 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_83 , L_11 , ( V_15 & 0x1 ) ) ;
}
static T_5 F_57 ( struct V_7 * V_5 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_1 * V_1 ;
int V_4 ;
T_2 V_15 ;
V_1 = F_9 ( V_5 ) ;
V_4 = F_17 ( V_1 , V_93 ,
V_94 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_83 , L_12 ,
( V_15 & V_95 ) ? 1 : 0 ) ;
}
static T_5 F_58 ( struct V_7 * V_5 ,
struct V_81 * V_82 , const char * V_83 , T_6 V_96 )
{
struct V_1 * V_1 ;
int V_4 = V_96 ;
int V_97 ;
T_2 V_19 ;
V_1 = F_9 ( V_5 ) ;
if ( V_96 > 0 ) {
switch ( V_83 [ 0 ] ) {
case '0' :
V_19 = 0 ;
break;
case '1' :
V_19 = V_95 ;
break;
default:
goto exit;
}
V_97 = F_19 ( V_1 ,
V_93 , V_94 ,
V_95 , V_19 ) ;
if ( V_97 )
F_59 ( V_1 -> V_5 ,
L_13 ,
V_83 [ 0 ] , V_97 ) ;
}
exit:
return V_4 ;
}
static int F_60 ( struct V_98 * V_99 )
{
static char * V_100 [] = {
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 } ;
static char * V_101 [] = {
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 } ;
struct V_102 * V_103 = F_61 ( & V_99 -> V_5 ) ;
const struct V_104 * V_105 = F_62 ( V_99 ) ;
enum V_106 V_107 = V_108 ;
struct V_71 * V_72 = V_99 -> V_5 . V_109 ;
struct V_1 * V_1 ;
struct V_110 * V_110 ;
int V_4 ;
int V_24 ;
T_2 V_15 ;
V_1 = F_63 ( & V_99 -> V_5 , sizeof *V_1 , V_111 ) ;
if ( ! V_1 )
return - V_112 ;
if ( V_103 )
V_1 -> V_53 = V_103 -> V_53 ;
V_1 -> V_5 = & V_99 -> V_5 ;
V_110 = F_64 ( V_99 , V_113 , 0 ) ;
if ( ! V_110 )
return - V_114 ;
V_1 -> V_60 = V_110 -> V_115 ;
V_1 -> V_17 = F_6 ;
V_1 -> V_14 = F_1 ;
V_1 -> V_20 = F_4 ;
F_65 ( & V_1 -> V_13 ) ;
F_65 ( & V_1 -> V_23 ) ;
F_66 ( & V_1 -> V_16 , 0 ) ;
F_67 ( V_99 , V_1 ) ;
if ( V_105 )
V_107 = V_105 -> V_116 ;
if ( V_107 != V_108 )
V_1 -> V_107 = V_107 ;
else {
V_4 = F_17 ( V_1 , V_117 ,
V_118 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_107 = V_15 ;
}
V_4 = F_17 ( V_1 , V_117 ,
V_119 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
V_1 -> V_10 = V_15 ;
F_59 ( V_1 -> V_5 , L_30 ,
V_120 [ V_1 -> V_107 ] ,
V_1 -> V_10 >> 4 ,
V_1 -> V_10 & 0x0F ) ;
if ( F_44 ( V_1 ) ) {
V_1 -> V_25 = V_121 ;
V_1 -> V_29 = V_122 ;
V_1 -> V_61 = V_123 ;
}
else if ( F_45 ( V_1 ) || F_46 ( V_1 ) ) {
V_1 -> V_25 = V_124 ;
V_1 -> V_29 = V_125 ;
V_1 -> V_61 = V_126 ;
} else {
V_1 -> V_25 = V_127 ;
V_1 -> V_29 = V_128 ;
V_1 -> V_61 = V_126 ;
}
V_1 -> V_6 = F_63 ( & V_99 -> V_5 , V_1 -> V_25 , V_111 ) ;
if ( ! V_1 -> V_6 )
return - V_112 ;
V_1 -> V_27 = F_63 ( & V_99 -> V_5 , V_1 -> V_25 , V_111 ) ;
if ( ! V_1 -> V_27 )
return - V_112 ;
V_4 = F_17 ( V_1 , V_84 ,
V_85 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_59 ( V_1 -> V_5 , L_31 , V_15 ) ;
if ( V_15 ) {
for ( V_24 = 0 ; V_24 < F_68 ( V_100 ) ; V_24 ++ ) {
if ( V_15 & 1 )
F_69 ( V_129 L_32 ,
V_100 [ V_24 ] ) ;
V_15 = V_15 >> 1 ;
}
F_69 ( V_129 L_33 ) ;
} else {
F_69 ( V_129 L_34 ) ;
}
V_4 = F_17 ( V_1 , V_90 ,
V_91 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
F_59 ( V_1 -> V_5 , L_35 , V_15 ) ;
if ( V_15 ) {
for ( V_24 = 0 ; V_24 < F_68 ( V_101 ) ; V_24 ++ ) {
if ( V_15 & 1 )
F_69 ( L_36 , V_101 [ V_24 ] ) ;
V_15 = V_15 >> 1 ;
}
F_69 ( L_33 ) ;
} else {
F_69 ( L_37 ) ;
}
if ( V_103 && V_103 -> V_130 )
V_103 -> V_130 ( V_1 ) ;
if ( F_45 ( V_1 ) ) {
V_4 = F_17 ( V_1 , V_131 ,
V_132 , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_15 & V_133 ) && ( V_15 & V_134 ) )
F_52 ( ~ V_135 ,
V_136 ) ;
}
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ ) {
if ( V_1 -> V_29 [ V_24 ] == 11 &&
F_24 ( V_1 ) )
continue;
if ( V_1 -> V_29 [ V_24 ] < 0 )
continue;
F_17 ( V_1 , V_31 ,
V_58 + V_1 -> V_29 [ V_24 ] ,
& V_15 ) ;
F_10 ( V_1 , V_31 ,
V_30 + V_1 -> V_29 [ V_24 ] , 0xff ) ;
}
V_4 = F_70 ( V_1 -> V_5 , & V_137 ) ;
if ( V_4 )
return V_4 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_25 ; V_24 ++ )
V_1 -> V_6 [ V_24 ] = V_1 -> V_27 [ V_24 ] = 0xff ;
V_4 = F_43 ( V_1 , V_72 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_71 ( & V_99 -> V_5 , V_1 -> V_60 , NULL ,
F_35 ,
V_138 | V_139 ,
L_38 , V_1 ) ;
if ( V_4 )
return V_4 ;
#if V_140
V_141 [ 0 ] . V_115 = V_1 -> V_60 ;
V_141 [ 0 ] . V_142 = V_1 -> V_60 ;
#endif
if ( F_45 ( V_1 ) )
V_4 = F_72 ( V_1 -> V_5 , 0 , V_143 ,
F_68 ( V_143 ) , NULL ,
V_1 -> V_53 , V_1 -> V_78 ) ;
else if ( F_44 ( V_1 ) ) {
V_4 = F_72 ( V_1 -> V_5 , 0 , V_144 ,
F_68 ( V_144 ) , NULL ,
V_1 -> V_53 , NULL ) ;
if ( V_4 )
return V_4 ;
if ( F_73 ( V_1 ) )
V_4 = F_72 ( V_1 -> V_5 , 0 , V_145 ,
F_68 ( V_145 ) , NULL ,
V_1 -> V_53 , NULL ) ;
else
V_4 = F_72 ( V_1 -> V_5 , 0 , V_146 ,
F_68 ( V_146 ) , NULL ,
V_1 -> V_53 , NULL ) ;
} else if ( F_46 ( V_1 ) )
V_4 = F_72 ( V_1 -> V_5 , 0 , V_147 ,
F_68 ( V_147 ) , NULL ,
V_1 -> V_53 , V_1 -> V_78 ) ;
else
V_4 = F_72 ( V_1 -> V_5 , 0 , V_148 ,
F_68 ( V_148 ) , NULL ,
V_1 -> V_53 , V_1 -> V_78 ) ;
if ( V_4 )
return V_4 ;
if ( ! V_149 ) {
V_4 = F_72 ( V_1 -> V_5 , 0 , V_150 ,
F_68 ( V_150 ) , NULL ,
V_1 -> V_53 , V_1 -> V_78 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_39 ) ;
}
if ( ( ( F_46 ( V_1 ) || F_45 ( V_1 ) ) &&
V_1 -> V_10 >= V_151 ) || F_44 ( V_1 ) )
V_4 = F_74 ( & V_1 -> V_5 -> V_152 ,
& V_153 ) ;
else
V_4 = F_74 ( & V_1 -> V_5 -> V_152 ,
& V_154 ) ;
if ( ( F_46 ( V_1 ) || F_45 ( V_1 ) ) &&
V_1 -> V_10 >= V_151 )
V_4 = F_74 ( & V_1 -> V_5 -> V_152 ,
& V_155 ) ;
if ( V_4 )
F_3 ( V_1 -> V_5 , L_40 ) ;
return V_4 ;
}
static int F_75 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_76 ( V_99 ) ;
if ( ( ( F_46 ( V_1 ) || F_45 ( V_1 ) ) &&
V_1 -> V_10 >= V_151 ) || F_44 ( V_1 ) )
F_77 ( & V_1 -> V_5 -> V_152 , & V_153 ) ;
else
F_77 ( & V_1 -> V_5 -> V_152 , & V_154 ) ;
if ( ( F_46 ( V_1 ) || F_45 ( V_1 ) ) &&
V_1 -> V_10 >= V_151 )
F_77 ( & V_1 -> V_5 -> V_152 , & V_155 ) ;
F_78 ( V_1 -> V_5 ) ;
return 0 ;
}
static int T_7 F_79 ( void )
{
return F_80 ( & V_156 ) ;
}
static void T_8 F_81 ( void )
{
F_82 ( & V_156 ) ;
}
