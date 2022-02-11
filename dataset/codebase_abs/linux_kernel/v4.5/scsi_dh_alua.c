static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_2 -> V_4 && V_2 -> V_4 != V_2 -> V_5 )
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = F_3 ( V_3 , V_6 ) ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = V_2 -> V_5 ;
V_2 -> V_7 = V_8 ;
return 1 ;
}
V_2 -> V_7 = V_3 ;
return 0 ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 ,
void * V_12 , unsigned V_13 , int V_14 )
{
struct V_9 * V_15 ;
struct V_16 * V_17 = V_11 -> V_16 ;
V_15 = F_5 ( V_17 , V_14 , V_6 ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( V_18 , V_11 ,
L_1 , V_19 ) ;
return NULL ;
}
F_8 ( V_15 ) ;
if ( V_13 && F_9 ( V_17 , V_15 , V_12 , V_13 , V_6 ) ) {
F_10 ( V_15 ) ;
F_7 ( V_18 , V_11 ,
L_2 , V_19 ) ;
return NULL ;
}
V_15 -> V_20 |= V_21 | V_22 |
V_23 ;
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_27 * V_28 ;
return V_15 ;
}
static unsigned F_11 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_9 * V_15 ;
int V_29 = 0 ;
V_15 = F_4 ( V_11 , V_2 -> V_4 , V_2 -> V_7 , V_30 ) ;
if ( ! V_15 ) {
V_29 = V_31 << 24 ;
goto V_32;
}
V_15 -> V_33 [ 0 ] = V_34 ;
if ( ! ( V_2 -> V_35 & V_36 ) )
V_15 -> V_33 [ 1 ] = V_37 | V_38 ;
else
V_15 -> V_33 [ 1 ] = V_37 ;
F_12 ( V_2 -> V_7 , & V_15 -> V_33 [ 6 ] ) ;
V_15 -> V_39 = F_13 ( V_34 ) ;
V_15 -> V_40 = V_2 -> V_40 ;
memset ( V_15 -> V_40 , 0 , V_41 ) ;
V_15 -> V_42 = 0 ;
F_14 ( V_15 -> V_17 , NULL , V_15 , 1 ) ;
if ( V_15 -> V_43 )
V_29 = V_15 -> V_43 ;
F_10 ( V_15 ) ;
V_32:
return V_29 ;
}
static void F_15 ( struct V_9 * V_44 , int error )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 V_47 ;
unsigned V_29 = V_48 ;
if ( F_16 ( V_44 -> V_43 ) != V_49 ||
F_17 ( V_44 -> V_43 ) != V_50 ) {
V_29 = V_51 ;
goto V_32;
}
if ( F_18 ( V_2 -> V_40 , V_41 ,
& V_47 ) ) {
if ( V_47 . V_52 == V_53 &&
V_47 . V_54 == 0x04 && V_47 . V_55 == 0x0a ) {
V_29 = V_48 ;
goto V_32;
}
if ( V_47 . V_52 == V_56 ) {
V_29 = V_57 ;
goto V_32;
}
F_7 ( V_18 , V_2 -> V_11 , L_3 ,
V_58 ) ;
F_19 ( V_2 -> V_11 , V_58 , & V_47 ) ;
V_29 = V_51 ;
} else if ( error )
V_29 = V_51 ;
if ( V_29 == V_48 ) {
V_2 -> V_59 = V_60 ;
F_7 ( V_18 , V_2 -> V_11 ,
L_4 ,
V_58 , V_2 -> V_61 ,
F_20 ( V_2 -> V_59 ) ) ;
}
V_32:
V_44 -> V_45 = NULL ;
F_21 ( V_44 -> V_17 , V_44 ) ;
if ( V_2 -> V_62 ) {
V_2 -> V_62 ( V_2 -> V_63 , V_29 ) ;
V_2 -> V_62 = V_2 -> V_63 = NULL ;
}
return;
}
static unsigned F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_15 ;
int V_64 = 8 ;
struct V_10 * V_11 = V_2 -> V_11 ;
memset ( V_2 -> V_4 , 0 , V_64 ) ;
V_2 -> V_4 [ 4 ] = V_60 & 0x0f ;
F_23 ( V_2 -> V_61 , & V_2 -> V_4 [ 6 ] ) ;
V_15 = F_4 ( V_11 , V_2 -> V_4 , V_64 , V_65 ) ;
if ( ! V_15 )
return V_66 ;
V_15 -> V_33 [ 0 ] = V_67 ;
V_15 -> V_33 [ 1 ] = V_68 ;
F_12 ( V_64 , & V_15 -> V_33 [ 6 ] ) ;
V_15 -> V_39 = F_13 ( V_67 ) ;
V_15 -> V_40 = V_2 -> V_40 ;
memset ( V_15 -> V_40 , 0 , V_41 ) ;
V_15 -> V_42 = 0 ;
V_15 -> V_45 = V_2 ;
F_24 ( V_15 -> V_17 , NULL , V_15 , 1 , F_15 ) ;
return V_48 ;
}
static int F_25 ( struct V_10 * V_11 )
{
int V_69 = V_70 ;
if ( V_11 -> type != V_71 ) {
F_7 ( V_18 , V_11 ,
L_5 ,
V_58 ) ;
return V_69 ;
}
V_69 = F_26 ( V_11 ) ;
switch ( V_69 ) {
case V_72 | V_73 :
F_7 ( V_18 , V_11 ,
L_6 ,
V_58 ) ;
break;
case V_72 :
F_7 ( V_18 , V_11 , L_7 ,
V_58 ) ;
break;
case V_73 :
F_7 ( V_18 , V_11 , L_8 ,
V_58 ) ;
break;
case V_70 :
F_7 ( V_18 , V_11 , L_9 ,
V_58 ) ;
break;
default:
F_7 ( V_18 , V_11 ,
L_10 ,
V_58 , V_69 ) ;
V_69 = V_70 ;
break;
}
return V_69 ;
}
static int F_27 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_74 = - 1 , V_61 ;
V_61 = F_28 ( V_11 , & V_74 ) ;
if ( V_61 < 0 ) {
F_7 ( V_18 , V_11 ,
L_11 ,
V_58 ) ;
return V_75 ;
}
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = V_61 ;
F_7 ( V_18 , V_11 ,
L_12 ,
V_58 , V_2 -> V_61 , V_2 -> V_74 ) ;
return 0 ;
}
static char F_20 ( int V_59 )
{
switch ( V_59 ) {
case V_60 :
return 'A' ;
case V_76 :
return 'N' ;
case V_77 :
return 'S' ;
case V_78 :
return 'U' ;
case V_79 :
return 'L' ;
case V_80 :
return 'O' ;
case V_81 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_29 ( struct V_10 * V_11 ,
struct V_46 * V_47 )
{
switch ( V_47 -> V_52 ) {
case V_53 :
if ( V_47 -> V_54 == 0x04 && V_47 -> V_55 == 0x0a )
return V_82 ;
break;
case V_56 :
if ( V_47 -> V_54 == 0x29 && V_47 -> V_55 == 0x00 )
return V_82 ;
if ( V_47 -> V_54 == 0x29 && V_47 -> V_55 == 0x04 )
return V_82 ;
if ( V_47 -> V_54 == 0x2a && V_47 -> V_55 == 0x01 )
return V_82 ;
if ( V_47 -> V_54 == 0x2a && V_47 -> V_55 == 0x06 )
return V_82 ;
if ( V_47 -> V_54 == 0x2a && V_47 -> V_55 == 0x07 )
return V_82 ;
if ( V_47 -> V_54 == 0x3f && V_47 -> V_55 == 0x03 )
return V_82 ;
if ( V_47 -> V_54 == 0x3f && V_47 -> V_55 == 0x0e )
return V_82 ;
break;
}
return V_83 ;
}
static int F_30 ( struct V_10 * V_11 , struct V_1 * V_2 , int V_84 )
{
struct V_46 V_47 ;
int V_3 , V_85 , V_86 , V_87 = 0 ;
unsigned char * V_88 ;
unsigned V_29 , V_89 ;
unsigned long V_90 , V_91 = 0 ;
unsigned int V_92 ;
unsigned char V_93 ;
if ( ! V_2 -> V_94 )
V_90 = F_31 ( V_95 + V_27 * V_28 ) ;
else
V_90 = F_31 ( V_95 + V_2 -> V_94 * V_28 ) ;
V_96:
V_89 = F_11 ( V_11 , V_2 ) ;
if ( V_89 ) {
if ( ! F_18 ( V_2 -> V_40 , V_41 ,
& V_47 ) ) {
F_7 ( V_18 , V_11 ,
L_13 ,
V_58 , V_89 ) ;
if ( F_32 ( V_89 ) == V_31 )
return V_97 ;
return V_51 ;
}
if ( ! ( V_2 -> V_35 & V_36 ) &&
V_47 . V_52 == V_98 &&
V_47 . V_54 == 0x24 && V_47 . V_55 == 0 ) {
V_2 -> V_35 |= V_36 ;
goto V_96;
}
if ( V_47 . V_52 == V_53 &&
V_47 . V_54 == 0x04 && V_47 . V_55 == 0x0a )
V_29 = V_57 ;
else if ( V_47 . V_52 == V_56 )
V_29 = V_57 ;
if ( V_29 == V_57 && F_33 ( V_95 , V_90 ) ) {
F_7 ( V_99 , V_11 , L_14 ,
V_58 ) ;
F_19 ( V_11 , V_58 , & V_47 ) ;
goto V_96;
}
F_7 ( V_99 , V_11 , L_15 ,
V_58 ) ;
F_19 ( V_11 , V_58 , & V_47 ) ;
return V_51 ;
}
V_3 = F_34 ( & V_2 -> V_4 [ 0 ] ) + 4 ;
if ( V_3 > V_2 -> V_7 ) {
if ( F_1 ( V_2 , V_3 ) ) {
F_7 ( V_100 , V_11 ,
L_16 , V_19 ) ;
return V_97 ;
}
goto V_96;
}
V_93 = V_2 -> V_94 ;
if ( ( V_2 -> V_4 [ 4 ] & V_101 ) == V_102 && V_2 -> V_4 [ 5 ] != 0 )
V_2 -> V_94 = V_2 -> V_4 [ 5 ] ;
else
V_2 -> V_94 = V_27 ;
if ( V_84 && ( V_93 != V_2 -> V_94 ) ) {
F_7 ( V_18 , V_11 ,
L_17 ,
V_58 , V_2 -> V_94 ) ;
V_90 = V_95 + V_2 -> V_94 * V_28 ;
}
if ( ( V_2 -> V_4 [ 4 ] & V_101 ) == V_102 )
V_92 = 8 ;
else
V_92 = 4 ;
for ( V_85 = V_92 , V_88 = V_2 -> V_4 + V_92 ;
V_85 < V_3 ;
V_85 += V_86 , V_88 += V_86 ) {
if ( V_2 -> V_61 == F_35 ( & V_88 [ 2 ] ) ) {
V_2 -> V_59 = V_88 [ 0 ] & 0x0f ;
V_2 -> V_103 = V_88 [ 0 ] >> 7 ;
V_87 = V_88 [ 1 ] ;
}
V_86 = 8 + ( V_88 [ 7 ] * 4 ) ;
}
F_7 ( V_18 , V_11 ,
L_18 ,
V_58 , V_2 -> V_61 , F_20 ( V_2 -> V_59 ) ,
V_2 -> V_103 ? L_19 : L_20 ,
V_87 & V_104 ? 'T' : 't' ,
V_87 & V_105 ? 'O' : 'o' ,
V_87 & V_106 ? 'L' : 'l' ,
V_87 & V_107 ? 'U' : 'u' ,
V_87 & V_108 ? 'S' : 's' ,
V_87 & V_109 ? 'N' : 'n' ,
V_87 & V_110 ? 'A' : 'a' ) ;
switch ( V_2 -> V_59 ) {
case V_81 :
if ( V_84 ) {
if ( F_33 ( V_95 , V_90 ) ) {
V_91 += 2000 ;
F_36 ( V_91 ) ;
goto V_96;
}
V_29 = V_57 ;
} else {
V_29 = V_48 ;
}
V_2 -> V_59 = V_77 ;
break;
case V_80 :
V_29 = V_111 ;
break;
default:
V_29 = V_48 ;
break;
}
return V_29 ;
}
static int F_37 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_29 = V_75 ;
V_2 -> V_69 = F_25 ( V_11 ) ;
if ( V_2 -> V_69 == V_70 )
goto V_112;
V_29 = F_27 ( V_11 , V_2 ) ;
if ( V_29 != V_48 )
goto V_112;
V_29 = F_30 ( V_11 , V_2 , 0 ) ;
if ( V_29 != V_48 )
goto V_112;
V_112:
return V_29 ;
}
static int F_38 ( struct V_10 * V_11 , const char * V_113 )
{
struct V_1 * V_2 = V_11 -> V_114 ;
unsigned int V_115 = 0 , V_116 ;
const char * V_117 = V_113 ;
int V_118 = V_48 ;
if ( ( sscanf ( V_113 , L_21 , & V_116 ) != 1 ) || ( V_116 != 1 ) )
return - V_119 ;
while ( * V_117 ++ )
;
if ( ( sscanf ( V_117 , L_21 , & V_115 ) != 1 ) || ( V_115 > 1 ) )
return - V_119 ;
if ( V_115 )
V_2 -> V_35 |= V_120 ;
else
V_2 -> V_35 &= ~ V_120 ;
return V_118 ;
}
static int F_39 ( struct V_10 * V_11 ,
T_1 V_121 , void * V_122 )
{
struct V_1 * V_2 = V_11 -> V_114 ;
int V_29 = V_48 ;
int V_123 = 0 ;
V_29 = F_30 ( V_11 , V_2 , 1 ) ;
if ( V_29 != V_48 )
goto V_112;
if ( V_124 )
V_2 -> V_35 |= V_120 ;
if ( V_2 -> V_69 & V_72 ) {
switch ( V_2 -> V_59 ) {
case V_76 :
V_123 = 1 ;
if ( ( V_2 -> V_35 & V_120 ) &&
( ! V_2 -> V_103 ) &&
( V_2 -> V_69 & V_73 ) )
V_123 = 0 ;
break;
case V_77 :
case V_78 :
V_123 = 1 ;
break;
case V_80 :
V_29 = V_51 ;
break;
case V_81 :
V_29 = V_57 ;
break;
default:
break;
}
}
if ( V_123 ) {
V_2 -> V_62 = V_121 ;
V_2 -> V_63 = V_122 ;
V_29 = F_22 ( V_2 ) ;
if ( V_29 == V_48 )
return 0 ;
V_2 -> V_62 = V_2 -> V_63 = NULL ;
}
V_112:
if ( V_121 )
V_121 ( V_122 , V_29 ) ;
return 0 ;
}
static int F_40 ( struct V_10 * V_11 , struct V_9 * V_44 )
{
struct V_1 * V_2 = V_11 -> V_114 ;
int V_125 = V_126 ;
if ( V_2 -> V_59 == V_81 )
V_125 = V_127 ;
else if ( V_2 -> V_59 != V_60 &&
V_2 -> V_59 != V_76 &&
V_2 -> V_59 != V_79 ) {
V_125 = V_128 ;
V_44 -> V_20 |= V_129 ;
}
return V_125 ;
}
static int F_41 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_130 ) ;
if ( ! V_2 )
return - V_131 ;
V_2 -> V_69 = V_132 ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = - 1 ;
V_2 -> V_74 = - 1 ;
V_2 -> V_4 = V_2 -> V_5 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_11 = V_11 ;
V_29 = F_37 ( V_11 , V_2 ) ;
if ( V_29 != V_48 && V_29 != V_111 )
goto V_133;
V_11 -> V_114 = V_2 ;
return 0 ;
V_133:
F_2 ( V_2 ) ;
return - V_119 ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 ;
if ( V_2 -> V_4 && V_2 -> V_5 != V_2 -> V_4 )
F_2 ( V_2 -> V_4 ) ;
V_11 -> V_114 = NULL ;
F_2 ( V_2 ) ;
}
static int T_2 F_44 ( void )
{
int V_134 ;
V_134 = F_45 ( & V_135 ) ;
if ( V_134 != 0 )
F_46 ( V_99 L_22 ,
V_58 ) ;
return V_134 ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_135 ) ;
}
