static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( 0x0 , V_3 -> V_4 + V_5 ) ;
F_3 () ;
}
static bool F_4 ( T_1 V_6 )
{
switch ( V_6 ) {
case V_7 :
break;
default:
return false ;
}
return true ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
unsigned long V_12 ;
int V_13 = - 1 ;
if ( ! V_3 -> V_14 )
return V_3 -> V_15 ;
F_7 ( V_3 -> V_10 ) ;
F_8 ( & V_3 -> V_16 , V_12 ) ;
F_9 ( V_3 -> V_4 ) ;
V_13 = F_10 ( V_3 -> V_4 + V_17 ) ;
V_13 &= V_18 ;
F_11 ( V_3 -> V_4 ) ;
F_12 ( & V_3 -> V_16 , V_12 ) ;
F_13 ( V_3 -> V_10 ) ;
return V_13 ;
}
static void F_14 ( void * V_1 )
{
int V_19 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
F_1 ( V_3 ) ;
F_2 ( 0 , V_3 -> V_4 + V_20 ) ;
if ( F_15 ( V_3 -> V_4 , V_21 , V_22 , 1 ) )
F_16 ( V_3 -> V_10 ,
L_1 ,
V_21 ) ;
F_2 ( V_3 -> V_23 , V_3 -> V_4 + V_24 ) ;
F_2 ( V_3 -> V_25 , V_3 -> V_4 + V_26 ) ;
F_2 ( 0x0 , V_3 -> V_4 + V_27 ) ;
F_2 ( V_3 -> V_28 , V_3 -> V_4 + V_29 ) ;
F_2 ( V_3 -> V_30 , V_3 -> V_4 + V_31 ) ;
F_2 ( V_3 -> V_32 , V_3 -> V_4 + V_33 ) ;
F_2 ( V_3 -> V_34 , V_3 -> V_4 + V_35 ) ;
F_2 ( V_3 -> V_36 , V_3 -> V_4 + V_37 ) ;
F_2 ( V_3 -> V_38 , V_3 -> V_4 + V_39 ) ;
F_2 ( V_3 -> V_40 , V_3 -> V_4 + V_41 ) ;
F_2 ( V_3 -> V_15 , V_3 -> V_4 + V_17 ) ;
F_2 ( V_3 -> V_42 , V_3 -> V_4 + V_43 ) ;
F_2 ( V_3 -> V_44 , V_3 -> V_4 + V_45 ) ;
F_2 ( V_3 -> V_46 ,
V_3 -> V_4 + V_47 ) ;
F_2 ( V_3 -> V_48 ,
V_3 -> V_4 + V_49 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_50 - 1 ; V_19 ++ )
F_2 ( V_3 -> V_51 [ V_19 ] ,
V_3 -> V_4 + F_17 ( V_19 ) ) ;
F_2 ( V_3 -> V_52 , V_3 -> V_4 + V_53 ) ;
F_2 ( V_3 -> V_54 , V_3 -> V_4 + V_55 ) ;
F_2 ( V_3 -> V_56 , V_3 -> V_4 + V_57 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_58 ; V_19 ++ ) {
F_2 ( V_3 -> V_59 [ V_19 ] ,
V_3 -> V_4 + F_18 ( V_19 ) ) ;
F_2 ( V_3 -> V_60 [ V_19 ] ,
V_3 -> V_4 + F_19 ( V_19 ) ) ;
F_2 ( V_3 -> V_61 [ V_19 ] ,
V_3 -> V_4 + F_20 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_3 -> V_62 ; V_19 ++ )
F_2 ( V_3 -> V_63 [ V_19 ] ,
V_3 -> V_4 + F_21 ( V_19 ) ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_64 ; V_19 ++ ) {
F_2 ( V_3 -> V_65 [ V_19 ] ,
V_3 -> V_4 + F_22 ( V_19 ) ) ;
F_2 ( V_3 -> V_66 [ V_19 ] ,
V_3 -> V_4 + F_23 ( V_19 ) ) ;
F_2 ( V_3 -> V_67 [ V_19 ] ,
V_3 -> V_4 + F_24 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_3 -> V_68 ; V_19 ++ ) {
F_25 ( V_3 -> V_69 [ V_19 ] ,
V_3 -> V_4 + F_26 ( V_19 ) ) ;
F_25 ( V_3 -> V_70 [ V_19 ] ,
V_3 -> V_4 + F_27 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_3 -> V_71 ; V_19 ++ )
F_25 ( V_3 -> V_72 [ V_19 ] ,
V_3 -> V_4 + F_28 ( V_19 ) ) ;
F_2 ( V_3 -> V_73 , V_3 -> V_4 + V_74 ) ;
F_2 ( V_3 -> V_75 , V_3 -> V_4 + V_76 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_77 ; V_19 ++ )
F_25 ( V_3 -> V_78 [ V_19 ] ,
V_3 -> V_4 + F_29 ( V_19 ) ) ;
F_2 ( V_3 -> V_79 , V_3 -> V_4 + V_80 ) ;
F_2 ( V_3 -> V_81 , V_3 -> V_4 + V_82 ) ;
F_2 ( 1 , V_3 -> V_4 + V_20 ) ;
if ( F_15 ( V_3 -> V_4 , V_21 , V_22 , 0 ) )
F_16 ( V_3 -> V_10 ,
L_1 ,
V_21 ) ;
F_11 ( V_3 -> V_4 ) ;
F_30 ( V_3 -> V_10 , L_2 , V_3 -> V_83 ) ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
int V_84 ;
F_7 ( V_3 -> V_10 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_84 = F_33 ( V_3 -> V_83 ,
F_14 , V_3 , 1 ) ;
if ( V_84 )
goto V_85;
V_3 -> V_14 = true ;
V_3 -> V_86 = true ;
F_34 ( & V_3 -> V_16 ) ;
F_35 ( V_3 -> V_10 , L_3 ) ;
return 0 ;
V_85:
F_34 ( & V_3 -> V_16 ) ;
F_13 ( V_3 -> V_10 ) ;
return V_84 ;
}
static void F_36 ( void * V_1 )
{
T_2 V_87 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
V_87 = F_10 ( V_3 -> V_4 + V_20 ) ;
V_87 &= ~ 0x1 ;
F_37 () ;
F_3 () ;
F_2 ( V_87 , V_3 -> V_4 + V_20 ) ;
F_11 ( V_3 -> V_4 ) ;
F_30 ( V_3 -> V_10 , L_4 , V_3 -> V_83 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
F_39 () ;
F_32 ( & V_3 -> V_16 ) ;
F_33 ( V_3 -> V_83 , F_36 , V_3 , 1 ) ;
V_3 -> V_14 = false ;
F_34 ( & V_3 -> V_16 ) ;
F_40 () ;
F_13 ( V_3 -> V_10 ) ;
F_35 ( V_3 -> V_10 , L_5 ) ;
}
static int F_41 ( struct V_2 * V_3 , bool V_88 )
{
T_1 V_89 = V_3 -> V_90 ;
if ( F_42 ( V_3 -> V_70 [ V_89 ] , 0 , 1 ) == V_91 ) {
if ( V_89 % 2 != 0 )
return - V_92 ;
if ( V_3 -> V_93 [ V_89 ] != V_94 ||
V_3 -> V_93 [ V_89 + 1 ] != V_94 )
return - V_92 ;
if ( V_88 == true ) {
V_3 -> V_44 |= F_43 ( V_89 / 2 + 16 ) ;
V_3 -> V_44 &= ~ F_43 ( V_89 / 2 ) ;
} else {
V_3 -> V_44 |= F_43 ( V_89 / 2 ) ;
V_3 -> V_44 &= ~ F_43 ( V_89 / 2 + 16 ) ;
}
}
return 0 ;
}
static T_3 F_44 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_100 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_46 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_68 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_47 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_58 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_48 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_102 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_49 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_71 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_50 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_77 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_51 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_50 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_52 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_62 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_53 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_64 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_54 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
int V_19 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
if ( V_99 )
V_3 -> V_104 = 0x0 ;
V_3 -> V_104 &= ~ ( V_105 | V_106 ) ;
V_3 -> V_25 &= ~ ( F_43 ( 1 ) | F_43 ( 2 ) ) ;
V_3 -> V_104 &= ~ ( V_107 |
V_108 ) ;
V_3 -> V_25 &= ~ ( F_43 ( 16 ) | F_43 ( 17 ) ) ;
V_3 -> V_28 = 0x0 ;
V_3 -> V_30 = 0x0 ;
V_3 -> V_34 = 0x0 ;
V_3 -> V_32 = 0x0 ;
if ( V_3 -> V_109 == false )
V_3 -> V_36 = 0x8 ;
V_3 -> V_42 |= F_43 ( 0 ) ;
if ( V_3 -> V_68 == true ) {
V_3 -> V_104 |= V_110 ;
V_3 -> V_42 |= F_43 ( 9 ) ;
}
V_3 -> V_44 = 0x0 ;
V_3 -> V_46 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_50 - 1 ; V_19 ++ )
V_3 -> V_51 [ V_19 ] = 0x0 ;
V_3 -> V_52 = 0x0 ;
V_3 -> V_54 = 0x0 ;
V_3 -> V_56 = 0x0 ;
V_3 -> V_111 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_58 ; V_19 ++ ) {
V_3 -> V_59 [ V_19 ] = 0x0 ;
V_3 -> V_60 [ V_19 ] = 0x0 ;
V_3 -> V_61 [ V_19 ] = 0x0 ;
}
V_3 -> V_112 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_62 ; V_19 ++ )
V_3 -> V_63 [ V_19 ] = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_64 ; V_19 ++ ) {
V_3 -> V_65 [ V_19 ] = 0x0 ;
V_3 -> V_67 [ V_19 ] = 0x0 ;
}
V_3 -> V_90 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_68 * 2 ; V_19 ++ ) {
V_3 -> V_69 [ V_19 ] = 0x0 ;
V_3 -> V_70 [ V_19 ] = 0x0 ;
V_3 -> V_93 [ V_19 ] = V_113 ;
}
V_3 -> V_114 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_71 ; V_19 ++ )
V_3 -> V_72 [ V_19 ] = 0x0 ;
V_3 -> V_73 = 0x0 ;
V_3 -> V_75 = 0x0 ;
V_3 -> V_115 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_77 ; V_19 ++ )
V_3 -> V_78 [ V_19 ] = 0x0 ;
V_3 -> V_79 = 0x0 ;
V_3 -> V_81 = 0x0 ;
V_3 -> V_15 = V_3 -> V_83 + 1 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_56 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_104 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_57 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 , V_104 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_104 = V_99 & V_116 ;
if ( V_3 -> V_104 & V_117 )
F_41 ( V_3 , true ) ;
else
F_41 ( V_3 , false ) ;
if ( V_3 -> V_118 == true ) {
V_3 -> V_25 &= ~ ( F_43 ( 1 ) | F_43 ( 2 ) ) ;
if ( V_3 -> V_104 & V_105 )
V_3 -> V_25 |= F_43 ( 1 ) ;
if ( V_3 -> V_104 & V_106 )
V_3 -> V_25 |= F_43 ( 2 ) ;
if ( V_3 -> V_104 & V_119 )
V_3 -> V_25 |= F_43 ( 1 ) | F_43 ( 2 ) ;
}
if ( ( V_3 -> V_104 & V_120 ) && ( V_3 -> V_121 == true ) )
V_3 -> V_25 |= F_43 ( 3 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 3 ) ;
if ( ( V_3 -> V_104 & V_122 ) &&
( V_3 -> V_123 == true ) )
V_3 -> V_25 |= F_43 ( 4 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 4 ) ;
if ( ( V_3 -> V_104 & V_124 ) && ( V_3 -> V_125 ) )
V_3 -> V_25 |= F_43 ( 6 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 6 ) ;
if ( ( V_3 -> V_104 & V_126 ) && ( V_3 -> V_127 ) )
V_3 -> V_25 |= F_43 ( 7 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 7 ) ;
V_104 = F_58 ( V_3 -> V_104 ) ;
if ( V_3 -> V_128 == true ) {
V_3 -> V_25 &= ~ ( F_43 ( 8 ) | F_43 ( 9 ) | F_43 ( 10 ) ) ;
V_3 -> V_25 |= V_104 << 8 ;
}
if ( ( V_3 -> V_104 & V_129 ) && ( V_3 -> V_130 ) )
V_3 -> V_25 |= F_43 ( 11 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 11 ) ;
if ( ( V_3 -> V_104 & V_131 ) &&
( V_3 -> V_132 == true ) )
V_3 -> V_25 |= F_43 ( 12 ) ;
else
V_3 -> V_25 &= ~ F_43 ( 12 ) ;
V_104 = F_59 ( V_3 -> V_104 ) ;
V_3 -> V_25 &= ~ ( F_43 ( 13 ) | F_43 ( 14 ) ) ;
if ( ( V_104 & F_43 ( 0 ) ) && ( V_3 -> V_133 & F_43 ( 0 ) ) )
V_3 -> V_25 |= F_43 ( 13 ) ;
if ( ( V_104 & F_43 ( 1 ) ) && ( V_3 -> V_133 & F_43 ( 1 ) ) )
V_3 -> V_25 |= F_43 ( 14 ) ;
if ( ( V_3 -> V_104 & V_134 ) &&
( V_3 -> V_135 == true ) )
V_3 -> V_30 |= F_43 ( 11 ) ;
else
V_3 -> V_30 &= ~ F_43 ( 11 ) ;
if ( ( V_3 -> V_104 & V_136 ) &&
( V_3 -> V_137 == true ) )
V_3 -> V_30 |= F_43 ( 12 ) ;
else
V_3 -> V_30 &= ~ F_43 ( 12 ) ;
if ( V_3 -> V_104 & V_138 )
V_3 -> V_32 |= F_43 ( 8 ) ;
else
V_3 -> V_32 &= ~ F_43 ( 8 ) ;
if ( V_3 -> V_104 & V_139 )
V_3 -> V_32 |= F_43 ( 10 ) ;
else
V_3 -> V_32 &= ~ F_43 ( 10 ) ;
if ( ( V_3 -> V_104 & V_140 ) &&
( V_3 -> V_141 == true ) )
V_3 -> V_32 |= F_43 ( 13 ) ;
else
V_3 -> V_32 &= ~ F_43 ( 13 ) ;
if ( V_3 -> V_104 & V_110 )
V_3 -> V_42 |= F_43 ( 9 ) ;
else
V_3 -> V_42 &= ~ F_43 ( 9 ) ;
if ( V_3 -> V_104 & V_142 )
V_3 -> V_42 |= F_43 ( 10 ) ;
else
V_3 -> V_42 &= ~ F_43 ( 10 ) ;
if ( ( V_3 -> V_104 & V_143 ) &&
( V_3 -> V_144 == true ) )
V_3 -> V_42 |= F_43 ( 11 ) ;
else
V_3 -> V_42 &= ~ F_43 ( 11 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_60 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_23 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_61 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
if ( V_99 > V_3 -> V_145 ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_92 ;
}
V_3 -> V_23 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_62 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_28 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_63 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
switch ( V_3 -> V_146 ) {
case 0x0 :
V_3 -> V_28 = V_99 & 0xFF ;
break;
case 0x1 :
V_3 -> V_28 = V_99 & 0xFFFF ;
break;
case 0x2 :
V_3 -> V_28 = V_99 & 0xFFFFFF ;
break;
case 0x3 :
V_3 -> V_28 = V_99 ;
break;
default:
break;
}
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_64 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = F_42 ( V_3 -> V_30 , 0 , 3 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_65 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_30 &= ~ ( F_43 ( 0 ) | F_43 ( 1 ) | F_43 ( 2 ) | F_43 ( 3 ) ) ;
switch ( V_3 -> V_146 ) {
case 0x0 :
V_3 -> V_30 |= V_99 & F_43 ( 1 ) ;
break;
case 0x1 :
V_3 -> V_30 |= V_99 & ( F_43 ( 0 ) | F_43 ( 1 ) ) ;
break;
case 0x2 :
V_3 -> V_30 |= V_99 & ( F_43 ( 0 ) | F_43 ( 1 ) | F_43 ( 2 ) ) ;
break;
case 0x3 :
V_3 -> V_30 |= V_99 & 0xF ;
break;
default:
break;
}
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_66 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_34 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_67 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( ! V_3 -> V_130 )
return - V_92 ;
V_3 -> V_34 = V_99 & V_147 ;
return V_103 ;
}
static T_3 F_68 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_36 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_69 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_3 -> V_109 == true )
return - V_92 ;
V_3 -> V_36 = V_99 & V_148 ;
return V_103 ;
}
static T_3 F_70 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_38 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_71 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 < V_3 -> V_149 )
return - V_92 ;
V_3 -> V_38 = V_99 & V_150 ;
return V_103 ;
}
static T_3 F_72 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_40 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_73 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_3 -> V_121 == false )
return - V_92 ;
if ( ! V_3 -> V_68 )
return - V_92 ;
if ( F_42 ( V_99 , 0 , 7 ) > V_3 -> V_68 )
return - V_92 ;
V_3 -> V_40 = V_99 ;
return V_103 ;
}
static T_3 F_74 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_42 & V_147 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_75 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_99 &= V_147 ;
V_3 -> V_42 &= ~ V_147 ;
V_3 -> V_42 |= V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_76 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = F_42 ( V_3 -> V_42 , 16 , 19 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_77 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_42 &= ~ ( F_43 ( 16 ) | F_43 ( 17 ) | F_43 ( 19 ) ) ;
V_99 &= V_3 -> V_151 ;
V_3 -> V_42 |= ( V_99 << 16 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_78 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = F_42 ( V_3 -> V_42 , 20 , 23 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_79 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_42 &= ~ ( F_43 ( 20 ) | F_43 ( 21 ) | F_43 ( 22 ) ) ;
V_99 &= V_3 -> V_152 ;
V_3 -> V_42 |= ( V_99 << 20 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_80 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_90 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_81 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_68 * 2 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_90 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_82 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_3 V_153 ;
T_1 V_99 , V_89 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
V_99 = F_42 ( V_3 -> V_70 [ V_89 ] , 0 , 1 ) ;
V_153 = F_45 ( V_98 , V_101 , L_7 ,
V_99 == V_91 ? L_8 :
( V_99 == V_154 ? L_9 :
( V_99 == V_155 ? L_10 :
L_11 ) ) ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_153 ;
}
static T_3 F_83 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
char V_156 [ 20 ] = L_12 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( strlen ( V_98 ) >= 20 )
return - V_92 ;
if ( sscanf ( V_98 , L_13 , V_156 ) != 1 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! strcmp ( V_156 , L_8 ) )
V_3 -> V_70 [ V_89 ] &= ~ ( F_43 ( 0 ) | F_43 ( 1 ) ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_84 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_89 = V_3 -> V_90 ;
F_32 ( & V_3 -> V_16 ) ;
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_157 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_99 = ( unsigned long ) V_3 -> V_69 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_85 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_157 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_3 -> V_69 [ V_89 ] = ( V_159 ) V_99 ;
V_3 -> V_93 [ V_89 ] = V_157 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_86 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_160 , V_161 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( V_89 % 2 != 0 ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
if ( ! ( ( V_3 -> V_93 [ V_89 ] == V_113 &&
V_3 -> V_93 [ V_89 + 1 ] == V_113 ) ||
( V_3 -> V_93 [ V_89 ] == V_94 &&
V_3 -> V_93 [ V_89 + 1 ] == V_94 ) ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_160 = ( unsigned long ) V_3 -> V_69 [ V_89 ] ;
V_161 = ( unsigned long ) V_3 -> V_69 [ V_89 + 1 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_14 , V_160 , V_161 ) ;
}
static T_3 F_87 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_160 , V_161 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( sscanf ( V_98 , L_15 , & V_160 , & V_161 ) != 2 )
return - V_92 ;
if ( V_160 > V_161 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( V_89 % 2 != 0 ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
if ( ! ( ( V_3 -> V_93 [ V_89 ] == V_113 &&
V_3 -> V_93 [ V_89 + 1 ] == V_113 ) ||
( V_3 -> V_93 [ V_89 ] == V_94 &&
V_3 -> V_93 [ V_89 + 1 ] == V_94 ) ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_3 -> V_69 [ V_89 ] = ( V_159 ) V_160 ;
V_3 -> V_93 [ V_89 ] = V_94 ;
V_3 -> V_69 [ V_89 + 1 ] = ( V_159 ) V_161 ;
V_3 -> V_93 [ V_89 + 1 ] = V_94 ;
if ( V_3 -> V_104 & V_117 )
F_41 ( V_3 , true ) ;
else
F_41 ( V_3 , false ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_88 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_162 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_99 = ( unsigned long ) V_3 -> V_69 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_89 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! V_3 -> V_68 ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_92 ;
}
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_162 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_3 -> V_69 [ V_89 ] = ( V_159 ) V_99 ;
V_3 -> V_93 [ V_89 ] = V_162 ;
V_3 -> V_46 |= F_43 ( V_89 ) ;
V_3 -> V_42 |= F_43 ( 9 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_90 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_163 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_99 = ( unsigned long ) V_3 -> V_69 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_91 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! V_3 -> V_68 ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_92 ;
}
if ( ! ( V_3 -> V_93 [ V_89 ] == V_113 ||
V_3 -> V_93 [ V_89 ] == V_163 ) ) {
F_34 ( & V_3 -> V_16 ) ;
return - V_158 ;
}
V_3 -> V_69 [ V_89 ] = ( V_159 ) V_99 ;
V_3 -> V_93 [ V_89 ] = V_163 ;
V_3 -> V_46 |= F_43 ( V_89 + 16 ) ;
V_3 -> V_42 |= F_43 ( 9 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_92 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_3 V_153 ;
T_1 V_89 , V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
V_99 = F_42 ( V_3 -> V_70 [ V_89 ] , 2 , 3 ) ;
V_153 = F_45 ( V_98 , V_101 , L_7 , V_99 == V_164 ? L_16 :
( V_99 == V_165 ? L_17 :
( V_99 == V_166 ? L_18 : L_19 ) ) ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_153 ;
}
static T_3 F_93 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
char V_156 [ 10 ] = L_12 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( strlen ( V_98 ) >= 10 )
return - V_92 ;
if ( sscanf ( V_98 , L_13 , V_156 ) != 1 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
if ( ! strcmp ( V_156 , L_16 ) )
V_3 -> V_70 [ V_89 ] &= ~ ( F_43 ( 2 ) | F_43 ( 3 ) ) ;
else if ( ! strcmp ( V_156 , L_17 ) ) {
if ( V_3 -> V_71 ) {
V_3 -> V_70 [ V_89 ] |= F_43 ( 2 ) ;
V_3 -> V_70 [ V_89 ] &= ~ F_43 ( 3 ) ;
}
} else if ( ! strcmp ( V_156 , L_18 ) ) {
if ( V_3 -> V_77 ) {
V_3 -> V_70 [ V_89 ] &= ~ F_43 ( 2 ) ;
V_3 -> V_70 [ V_89 ] |= F_43 ( 3 ) ;
}
} else if ( ! strcmp ( V_156 , L_19 ) ) {
if ( V_3 -> V_71 )
V_3 -> V_70 [ V_89 ] |= F_43 ( 2 ) ;
if ( V_3 -> V_77 )
V_3 -> V_70 [ V_89 ] |= F_43 ( 3 ) ;
}
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_94 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
V_99 = F_42 ( V_3 -> V_70 [ V_89 ] , 4 , 6 ) ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_95 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( ( V_3 -> V_71 <= 1 ) && ( V_3 -> V_77 <= 1 ) )
return - V_92 ;
if ( V_99 >= ( V_3 -> V_71 >= V_3 -> V_77 ?
V_3 -> V_71 : V_3 -> V_77 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_90 ;
V_3 -> V_70 [ V_89 ] &= ~ ( F_43 ( 4 ) | F_43 ( 5 ) | F_43 ( 6 ) ) ;
V_3 -> V_70 [ V_89 ] |= ( V_99 << 4 ) ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_96 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_167 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_97 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_50 - 1 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_167 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_98 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_54 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_99 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_50 )
return - V_92 ;
V_3 -> V_54 = V_99 ;
return V_103 ;
}
static T_3 F_100 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_167 ;
V_99 = V_3 -> V_51 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_101 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_167 ;
V_3 -> V_51 [ V_89 ] = V_99 & 0xFF ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_102 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_52 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_103 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( ! ( V_3 -> V_50 ) )
return - V_92 ;
V_3 -> V_52 = V_99 & V_147 ;
return V_103 ;
}
static T_3 F_104 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_111 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_105 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_58 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_111 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_106 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_99 = V_3 -> V_59 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_107 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 > V_168 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_3 -> V_59 [ V_89 ] = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_108 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_99 = V_3 -> V_61 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_109 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 > V_168 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_3 -> V_61 [ V_89 ] = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_110 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_99 = V_3 -> V_60 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_111 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_111 ;
V_3 -> V_60 [ V_89 ] = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_112 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_112 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_113 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( ( V_99 == 0 ) || ( V_99 >= V_3 -> V_62 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_112 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_114 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_112 ;
V_99 = V_3 -> V_63 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_115 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_112 ;
if ( V_89 % 2 != 0 )
V_99 &= ~ F_43 ( 21 ) ;
V_3 -> V_63 [ V_89 ] = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_116 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_114 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_117 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_71 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_114 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_118 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_114 ;
V_99 = ( unsigned long ) V_3 -> V_72 [ V_89 ] ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_119 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_89 ;
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_125 || ! V_3 -> V_71 )
return - V_92 ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_89 = V_3 -> V_114 ;
V_3 -> V_72 [ V_89 ] = ( V_159 ) V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_120 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_160 , V_161 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_160 = V_3 -> V_73 ;
V_161 = V_3 -> V_75 ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_14 , V_160 , V_161 ) ;
}
static T_3 F_121 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_19 , V_169 , V_170 ;
unsigned long V_160 , V_161 , V_171 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_125 || ! V_3 -> V_71 )
return - V_92 ;
if ( sscanf ( V_98 , L_15 , & V_160 , & V_161 ) != 2 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
switch ( V_3 -> V_71 ) {
case 0x1 :
V_3 -> V_73 = V_160 & 0xFF ;
break;
case 0x2 :
V_3 -> V_73 = V_160 & 0xFFFF ;
break;
case 0x3 :
V_3 -> V_73 = V_160 & 0xFFFFFF ;
break;
case 0x4 :
V_3 -> V_73 = V_160 ;
break;
case 0x5 :
V_3 -> V_73 = V_160 ;
V_3 -> V_75 = V_161 & 0xFF ;
break;
case 0x6 :
V_3 -> V_73 = V_160 ;
V_3 -> V_75 = V_161 & 0xFFFF ;
break;
case 0x7 :
V_3 -> V_73 = V_160 ;
V_3 -> V_75 = V_161 & 0xFFFFFF ;
break;
case 0x8 :
V_3 -> V_73 = V_160 ;
V_3 -> V_75 = V_161 ;
break;
default:
break;
}
V_171 = V_3 -> V_73 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_71 ; V_19 ++ ) {
V_170 = V_171 & V_147 ;
for ( V_169 = 0 ; V_169 < 8 ; V_169 ++ ) {
if ( V_170 & 1 )
V_3 -> V_72 [ V_19 ] &= ~ ( 0xFF << ( V_169 * 8 ) ) ;
V_170 >>= 1 ;
}
if ( V_19 == 3 )
V_171 = V_3 -> V_75 ;
else
V_171 >>= 0x8 ;
}
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_122 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_115 ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_123 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
if ( V_99 >= V_3 -> V_77 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_115 = V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_124 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
char * V_98 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = ( unsigned long ) V_3 -> V_78 [ V_3 -> V_115 ] ;
return F_45 ( V_98 , V_101 , L_6 , V_99 ) ;
}
static T_3 F_125 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
unsigned long V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_127 || ! V_3 -> V_77 )
return - V_92 ;
if ( F_55 ( V_98 , 16 , & V_99 ) )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
V_3 -> V_78 [ V_3 -> V_115 ] = ( V_159 ) V_99 ;
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_126 ( struct V_95 * V_10 ,
struct V_96 * V_97 , char * V_98 )
{
unsigned long V_160 , V_161 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_32 ( & V_3 -> V_16 ) ;
V_160 = V_3 -> V_79 ;
V_161 = V_3 -> V_81 ;
F_34 ( & V_3 -> V_16 ) ;
return F_45 ( V_98 , V_101 , L_14 , V_160 , V_161 ) ;
}
static T_3 F_127 ( struct V_95 * V_10 ,
struct V_96 * V_97 ,
const char * V_98 , T_4 V_103 )
{
T_1 V_19 , V_169 , V_170 ;
unsigned long V_160 , V_161 , V_171 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_127 || ! V_3 -> V_77 )
return - V_92 ;
if ( sscanf ( V_98 , L_15 , & V_160 , & V_161 ) != 2 )
return - V_92 ;
F_32 ( & V_3 -> V_16 ) ;
switch ( V_3 -> V_77 ) {
case 0x1 :
V_3 -> V_79 = V_160 & 0xFF ;
break;
case 0x2 :
V_3 -> V_79 = V_160 & 0xFFFF ;
break;
case 0x3 :
V_3 -> V_79 = V_160 & 0xFFFFFF ;
break;
case 0x4 :
V_3 -> V_79 = V_160 ;
break;
case 0x5 :
V_3 -> V_79 = V_160 ;
V_3 -> V_81 = V_161 & 0xFF ;
break;
case 0x6 :
V_3 -> V_79 = V_160 ;
V_3 -> V_81 = V_161 & 0xFFFF ;
break;
case 0x7 :
V_3 -> V_79 = V_160 ;
V_3 -> V_81 = V_161 & 0xFFFFFF ;
break;
case 0x8 :
V_3 -> V_79 = V_160 ;
V_3 -> V_81 = V_161 ;
break;
default:
break;
}
V_171 = V_3 -> V_79 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_77 ; V_19 ++ ) {
V_170 = V_171 & V_147 ;
for ( V_169 = 0 ; V_169 < 8 ; V_169 ++ ) {
if ( V_170 & 1 )
V_3 -> V_78 [ V_19 ] &= ~ ( 0xFF << ( V_169 * 8 ) ) ;
V_170 >>= 1 ;
}
if ( V_19 == 3 )
V_171 = V_3 -> V_81 ;
else
V_171 >>= 0x8 ;
}
F_34 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static T_3 F_128 ( struct V_95 * V_10 ,
struct V_96 * V_97 , char * V_98 )
{
int V_99 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_99 = V_3 -> V_83 ;
return F_45 ( V_98 , V_101 , L_20 , V_99 ) ;
}
static void F_129 ( void * V_1 )
{
T_2 V_172 ;
T_2 V_173 ;
T_2 V_174 ;
T_2 V_175 ;
T_2 V_176 ;
T_2 V_177 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
V_172 = F_10 ( V_3 -> V_4 + V_178 ) ;
if ( F_42 ( V_172 , 1 , 1 ) && F_42 ( V_172 , 2 , 2 ) )
V_3 -> V_118 = true ;
else
V_3 -> V_118 = false ;
if ( F_42 ( V_172 , 5 , 5 ) )
V_3 -> V_121 = true ;
else
V_3 -> V_121 = false ;
if ( F_42 ( V_172 , 6 , 6 ) )
V_3 -> V_128 = true ;
else
V_3 -> V_128 = false ;
if ( F_42 ( V_172 , 7 , 7 ) )
V_3 -> V_123 = true ;
else
V_3 -> V_123 = false ;
if ( F_42 ( V_172 , 9 , 9 ) )
V_3 -> V_132 = true ;
else
V_3 -> V_132 = false ;
V_3 -> V_146 = F_42 ( V_172 , 10 , 11 ) ;
V_3 -> V_133 = F_42 ( V_172 , 15 , 16 ) ;
V_3 -> V_130 = F_42 ( V_172 , 24 , 28 ) ;
V_173 = F_10 ( V_3 -> V_4 + V_179 ) ;
V_3 -> V_6 = F_42 ( V_173 , 4 , 11 ) ;
V_174 = F_10 ( V_3 -> V_4 + V_180 ) ;
V_3 -> V_125 = F_42 ( V_174 , 5 , 9 ) ;
V_3 -> V_127 = F_42 ( V_174 , 10 , 14 ) ;
V_3 -> V_181 = F_42 ( V_174 , 25 , 28 ) ;
V_175 = F_10 ( V_3 -> V_4 + V_182 ) ;
V_3 -> V_149 = F_42 ( V_175 , 0 , 11 ) ;
V_3 -> V_151 = F_42 ( V_175 , 16 , 19 ) ;
V_3 -> V_152 = F_42 ( V_175 , 20 , 23 ) ;
if ( F_42 ( V_175 , 24 , 24 ) )
V_3 -> V_144 = true ;
else
V_3 -> V_144 = false ;
if ( F_42 ( V_175 , 25 , 25 ) )
V_3 -> V_109 = true ;
else
V_3 -> V_109 = false ;
if ( F_42 ( V_175 , 26 , 26 ) )
V_3 -> V_183 = true ;
else
V_3 -> V_183 = false ;
if ( F_42 ( V_175 , 27 , 27 ) )
V_3 -> V_184 = true ;
else
V_3 -> V_184 = false ;
V_3 -> V_145 = F_42 ( V_175 , 28 , 30 ) ;
if ( F_42 ( V_175 , 31 , 31 ) )
V_3 -> V_141 = true ;
else
V_3 -> V_141 = false ;
V_176 = F_10 ( V_3 -> V_4 + V_185 ) ;
V_3 -> V_68 = F_42 ( V_176 , 0 , 3 ) ;
V_3 -> V_100 = F_42 ( V_176 , 12 , 15 ) ;
V_3 -> V_62 = F_42 ( V_176 , 16 , 19 ) ;
V_3 -> V_64 = F_42 ( V_176 , 20 , 23 ) ;
V_3 -> V_71 = F_42 ( V_176 , 24 , 27 ) ;
V_3 -> V_77 = F_42 ( V_176 , 28 , 31 ) ;
V_177 = F_10 ( V_3 -> V_4 + V_186 ) ;
V_3 -> V_102 = F_42 ( V_177 , 0 , 8 ) ;
V_3 -> V_187 = F_42 ( V_177 , 16 , 21 ) ;
if ( F_42 ( V_177 , 22 , 22 ) )
V_3 -> V_135 = true ;
else
V_3 -> V_135 = false ;
if ( F_42 ( V_177 , 23 , 23 ) )
V_3 -> V_137 = true ;
else
V_3 -> V_137 = false ;
V_3 -> V_50 = F_42 ( V_177 , 25 , 27 ) ;
V_3 -> V_58 = F_42 ( V_177 , 28 , 30 ) ;
F_11 ( V_3 -> V_4 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
int V_19 ;
V_3 -> V_23 = 0x0 ;
V_3 -> V_25 = ( V_124 | V_126 |
V_129 | V_131 ) ;
V_3 -> V_28 = 0x0 ;
V_3 -> V_30 = 0x0 ;
V_3 -> V_32 = 0x0 ;
V_3 -> V_34 = 0x0 ;
if ( V_3 -> V_109 == false )
V_3 -> V_36 = 0xC ;
V_3 -> V_42 |= F_43 ( 0 ) ;
if ( V_3 -> V_68 )
V_3 -> V_42 |= F_43 ( 9 ) ;
V_3 -> V_44 = 0x0 ;
V_3 -> V_46 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_50 - 1 ; V_19 ++ )
V_3 -> V_51 [ V_19 ] = 0x0 ;
V_3 -> V_52 = 0x0 ;
V_3 -> V_54 = 0x0 ;
V_3 -> V_56 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_58 ; V_19 ++ ) {
V_3 -> V_59 [ V_19 ] = 0x0 ;
V_3 -> V_60 [ V_19 ] = 0x0 ;
V_3 -> V_61 [ V_19 ] = 0x0 ;
}
for ( V_19 = 2 ; V_19 < V_3 -> V_62 * 2 ; V_19 ++ )
V_3 -> V_63 [ V_19 ] = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_64 ; V_19 ++ ) {
V_3 -> V_65 [ V_19 ] = 0x0 ;
V_3 -> V_67 [ V_19 ] = 0x0 ;
}
if ( V_3 -> V_68 >= 1 ) {
V_3 -> V_69 [ 0 ] = ( unsigned long ) V_188 ;
V_3 -> V_69 [ 1 ] = ( unsigned long ) V_189 ;
V_3 -> V_93 [ 0 ] = V_94 ;
V_3 -> V_93 [ 1 ] = V_94 ;
}
for ( V_19 = 0 ; V_19 < V_3 -> V_71 ; V_19 ++ )
V_3 -> V_72 [ V_19 ] = 0x0 ;
V_3 -> V_73 = 0x0 ;
V_3 -> V_75 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_77 ; V_19 ++ )
V_3 -> V_78 [ V_19 ] = 0x0 ;
V_3 -> V_79 = 0x0 ;
V_3 -> V_81 = 0x0 ;
V_3 -> V_15 = 0x20 + V_3 -> V_83 ;
}
static int F_131 ( struct V_190 * V_191 , unsigned long V_192 ,
void * V_193 )
{
unsigned int V_83 = ( unsigned long ) V_193 ;
if ( ! V_194 [ V_83 ] )
goto V_195;
switch ( V_192 & ( ~ V_196 ) ) {
case V_197 :
F_32 ( & V_194 [ V_83 ] -> V_16 ) ;
if ( ! V_194 [ V_83 ] -> V_198 ) {
F_1 ( V_194 [ V_83 ] ) ;
V_194 [ V_83 ] -> V_198 = true ;
}
if ( V_194 [ V_83 ] -> V_14 )
F_14 ( V_194 [ V_83 ] ) ;
F_34 ( & V_194 [ V_83 ] -> V_16 ) ;
break;
case V_199 :
if ( V_194 [ V_83 ] -> V_200 &&
! V_194 [ V_83 ] -> V_86 )
F_132 ( V_194 [ V_83 ] -> V_9 ) ;
break;
case V_201 :
F_32 ( & V_194 [ V_83 ] -> V_16 ) ;
if ( V_194 [ V_83 ] -> V_14 )
F_36 ( V_194 [ V_83 ] ) ;
F_34 ( & V_194 [ V_83 ] -> V_16 ) ;
break;
}
V_195:
return V_202 ;
}
static int F_133 ( struct V_203 * V_204 , const struct V_205 * V_206 )
{
int V_84 ;
void T_5 * V_4 ;
struct V_95 * V_10 = & V_204 -> V_10 ;
struct V_207 * V_208 = NULL ;
struct V_2 * V_3 ;
struct V_209 * V_210 = & V_204 -> V_210 ;
struct V_211 * V_212 ;
struct V_213 * V_214 = V_204 -> V_10 . V_215 ;
V_212 = F_134 ( V_10 , sizeof( * V_212 ) , V_216 ) ;
if ( ! V_212 )
return - V_217 ;
V_3 = F_134 ( V_10 , sizeof( * V_3 ) , V_216 ) ;
if ( ! V_3 )
return - V_217 ;
if ( V_214 ) {
V_208 = F_135 ( V_10 , V_214 ) ;
if ( F_136 ( V_208 ) )
return F_137 ( V_208 ) ;
V_204 -> V_10 . V_218 = V_208 ;
}
V_3 -> V_10 = & V_204 -> V_10 ;
F_138 ( V_10 , V_3 ) ;
V_4 = F_139 ( V_10 , V_210 ) ;
if ( F_136 ( V_4 ) )
return F_137 ( V_4 ) ;
V_3 -> V_4 = V_4 ;
F_140 ( & V_3 -> V_16 ) ;
V_3 -> V_83 = V_208 ? V_208 -> V_83 : 0 ;
F_39 () ;
V_194 [ V_3 -> V_83 ] = V_3 ;
if ( ! F_33 ( V_3 -> V_83 , F_1 , V_3 , 1 ) )
V_3 -> V_198 = true ;
if ( F_33 ( V_3 -> V_83 ,
F_129 , V_3 , 1 ) )
F_16 ( V_10 , L_21 ) ;
if ( ! V_219 ++ )
F_141 ( & V_220 ) ;
F_40 () ;
if ( F_4 ( V_3 -> V_6 ) == false ) {
V_84 = - V_92 ;
goto V_221;
}
F_130 ( V_3 ) ;
F_13 ( & V_204 -> V_10 ) ;
V_212 -> type = V_222 ;
V_212 -> V_223 . V_224 = V_225 ;
V_212 -> V_226 = & V_227 ;
V_212 -> V_208 = V_208 ;
V_212 -> V_10 = V_10 ;
V_212 -> V_228 = V_229 ;
V_3 -> V_9 = F_142 ( V_212 ) ;
if ( F_136 ( V_3 -> V_9 ) ) {
V_84 = F_137 ( V_3 -> V_9 ) ;
goto V_230;
}
F_35 ( V_10 , L_22 , ( char * ) V_206 -> V_231 ) ;
if ( V_200 ) {
F_132 ( V_3 -> V_9 ) ;
V_3 -> V_200 = true ;
}
return 0 ;
V_221:
F_13 ( & V_204 -> V_10 ) ;
V_230:
if ( -- V_219 == 0 )
F_143 ( & V_220 ) ;
return V_84 ;
}
static int F_144 ( struct V_203 * V_204 )
{
struct V_2 * V_3 = F_145 ( V_204 ) ;
F_146 ( V_3 -> V_9 ) ;
if ( -- V_219 == 0 )
F_143 ( & V_220 ) ;
return 0 ;
}
