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
return V_3 -> V_12 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
unsigned long V_13 ;
int V_14 = - 1 ;
if ( ! V_3 -> V_15 )
return V_3 -> V_16 ;
F_8 ( & V_3 -> V_17 , V_13 ) ;
F_9 ( V_3 -> V_4 ) ;
V_14 = F_10 ( V_3 -> V_4 + V_18 ) ;
V_14 &= V_19 ;
F_11 ( V_3 -> V_4 ) ;
F_12 ( & V_3 -> V_17 , V_13 ) ;
return V_14 ;
}
static void F_13 ( void * V_1 )
{
int V_20 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
F_1 ( V_3 ) ;
F_2 ( 0 , V_3 -> V_4 + V_21 ) ;
if ( F_14 ( V_3 -> V_4 , V_22 , V_23 , 1 ) )
F_15 ( V_3 -> V_10 ,
L_1 ,
V_22 ) ;
F_2 ( V_3 -> V_24 , V_3 -> V_4 + V_25 ) ;
F_2 ( V_3 -> V_26 , V_3 -> V_4 + V_27 ) ;
F_2 ( 0x0 , V_3 -> V_4 + V_28 ) ;
F_2 ( V_3 -> V_29 , V_3 -> V_4 + V_30 ) ;
F_2 ( V_3 -> V_31 , V_3 -> V_4 + V_32 ) ;
F_2 ( V_3 -> V_33 , V_3 -> V_4 + V_34 ) ;
F_2 ( V_3 -> V_35 , V_3 -> V_4 + V_36 ) ;
F_2 ( V_3 -> V_37 , V_3 -> V_4 + V_38 ) ;
F_2 ( V_3 -> V_39 , V_3 -> V_4 + V_40 ) ;
F_2 ( V_3 -> V_41 , V_3 -> V_4 + V_42 ) ;
F_2 ( V_3 -> V_16 , V_3 -> V_4 + V_18 ) ;
F_2 ( V_3 -> V_43 , V_3 -> V_4 + V_44 ) ;
F_2 ( V_3 -> V_45 , V_3 -> V_4 + V_46 ) ;
F_2 ( V_3 -> V_47 ,
V_3 -> V_4 + V_48 ) ;
F_2 ( V_3 -> V_49 ,
V_3 -> V_4 + V_50 ) ;
for ( V_20 = 0 ; V_20 < V_3 -> V_51 - 1 ; V_20 ++ )
F_2 ( V_3 -> V_52 [ V_20 ] ,
V_3 -> V_4 + F_16 ( V_20 ) ) ;
F_2 ( V_3 -> V_53 , V_3 -> V_4 + V_54 ) ;
F_2 ( V_3 -> V_55 , V_3 -> V_4 + V_56 ) ;
F_2 ( V_3 -> V_57 , V_3 -> V_4 + V_58 ) ;
for ( V_20 = 0 ; V_20 < V_3 -> V_59 ; V_20 ++ ) {
F_2 ( V_3 -> V_60 [ V_20 ] ,
V_3 -> V_4 + F_17 ( V_20 ) ) ;
F_2 ( V_3 -> V_61 [ V_20 ] ,
V_3 -> V_4 + F_18 ( V_20 ) ) ;
F_2 ( V_3 -> V_62 [ V_20 ] ,
V_3 -> V_4 + F_19 ( V_20 ) ) ;
}
for ( V_20 = 2 ; V_20 < V_3 -> V_63 * 2 ; V_20 ++ )
F_2 ( V_3 -> V_64 [ V_20 ] ,
V_3 -> V_4 + F_20 ( V_20 ) ) ;
for ( V_20 = 0 ; V_20 < V_3 -> V_65 ; V_20 ++ ) {
F_2 ( V_3 -> V_66 [ V_20 ] ,
V_3 -> V_4 + F_21 ( V_20 ) ) ;
F_2 ( V_3 -> V_67 [ V_20 ] ,
V_3 -> V_4 + F_22 ( V_20 ) ) ;
F_2 ( V_3 -> V_68 [ V_20 ] ,
V_3 -> V_4 + F_23 ( V_20 ) ) ;
}
for ( V_20 = 0 ; V_20 < V_3 -> V_69 ; V_20 ++ ) {
F_24 ( V_3 -> V_70 [ V_20 ] ,
V_3 -> V_4 + F_25 ( V_20 ) ) ;
F_24 ( V_3 -> V_71 [ V_20 ] ,
V_3 -> V_4 + F_26 ( V_20 ) ) ;
}
for ( V_20 = 0 ; V_20 < V_3 -> V_72 ; V_20 ++ )
F_24 ( V_3 -> V_73 [ V_20 ] ,
V_3 -> V_4 + F_27 ( V_20 ) ) ;
F_2 ( V_3 -> V_74 , V_3 -> V_4 + V_75 ) ;
F_2 ( V_3 -> V_76 , V_3 -> V_4 + V_77 ) ;
for ( V_20 = 0 ; V_20 < V_3 -> V_78 ; V_20 ++ )
F_24 ( V_3 -> V_79 [ V_20 ] ,
V_3 -> V_4 + F_28 ( V_20 ) ) ;
F_2 ( V_3 -> V_80 , V_3 -> V_4 + V_81 ) ;
F_2 ( V_3 -> V_82 , V_3 -> V_4 + V_83 ) ;
F_2 ( 1 , V_3 -> V_4 + V_21 ) ;
if ( F_14 ( V_3 -> V_4 , V_22 , V_23 , 0 ) )
F_15 ( V_3 -> V_10 ,
L_1 ,
V_22 ) ;
F_11 ( V_3 -> V_4 ) ;
F_29 ( V_3 -> V_10 , L_2 , V_3 -> V_12 ) ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_84 * V_85 , T_2 V_86 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
int V_87 ;
F_31 ( & V_3 -> V_17 ) ;
V_87 = F_32 ( V_3 -> V_12 ,
F_13 , V_3 , 1 ) ;
if ( V_87 )
goto V_88;
V_3 -> V_15 = true ;
V_3 -> V_89 = true ;
F_33 ( & V_3 -> V_17 ) ;
F_34 ( V_3 -> V_10 , L_3 ) ;
return 0 ;
V_88:
F_33 ( & V_3 -> V_17 ) ;
return V_87 ;
}
static void F_35 ( void * V_1 )
{
T_2 V_90 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
V_90 = F_10 ( V_3 -> V_4 + V_21 ) ;
V_90 &= ~ 0x1 ;
F_36 () ;
F_3 () ;
F_2 ( V_90 , V_3 -> V_4 + V_21 ) ;
F_11 ( V_3 -> V_4 ) ;
F_29 ( V_3 -> V_10 , L_4 , V_3 -> V_12 ) ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_6 ( V_9 -> V_10 . V_11 ) ;
F_38 () ;
F_31 ( & V_3 -> V_17 ) ;
F_32 ( V_3 -> V_12 , F_35 , V_3 , 1 ) ;
V_3 -> V_15 = false ;
F_33 ( & V_3 -> V_17 ) ;
F_39 () ;
F_34 ( V_3 -> V_10 , L_5 ) ;
}
static int F_40 ( struct V_2 * V_3 , bool V_91 )
{
T_1 V_92 = V_3 -> V_93 ;
if ( F_41 ( V_3 -> V_71 [ V_92 ] , 0 , 1 ) == V_94 ) {
if ( V_92 % 2 != 0 )
return - V_95 ;
if ( V_3 -> V_96 [ V_92 ] != V_97 ||
V_3 -> V_96 [ V_92 + 1 ] != V_97 )
return - V_95 ;
if ( V_91 == true ) {
V_3 -> V_45 |= F_42 ( V_92 / 2 + 16 ) ;
V_3 -> V_45 &= ~ F_42 ( V_92 / 2 ) ;
} else {
V_3 -> V_45 |= F_42 ( V_92 / 2 ) ;
V_3 -> V_45 &= ~ F_42 ( V_92 / 2 + 16 ) ;
}
}
return 0 ;
}
static T_3 F_43 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_102 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_45 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_69 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_46 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_59 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_47 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_104 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_48 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_72 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_49 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_78 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_50 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_51 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_51 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_63 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_52 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_65 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_53 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
int V_20 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
if ( V_101 )
V_3 -> V_86 = 0x0 ;
V_3 -> V_86 &= ~ ( V_106 | V_107 ) ;
V_3 -> V_26 &= ~ ( F_42 ( 1 ) | F_42 ( 2 ) ) ;
V_3 -> V_86 &= ~ ( V_108 |
V_109 ) ;
V_3 -> V_26 &= ~ ( F_42 ( 16 ) | F_42 ( 17 ) ) ;
V_3 -> V_29 = 0x0 ;
V_3 -> V_31 = 0x0 ;
V_3 -> V_35 = 0x0 ;
V_3 -> V_33 = 0x0 ;
if ( V_3 -> V_110 == false )
V_3 -> V_37 = 0x8 ;
V_3 -> V_43 |= F_42 ( 0 ) ;
if ( V_3 -> V_69 == true ) {
V_3 -> V_86 |= V_111 ;
V_3 -> V_43 |= F_42 ( 9 ) ;
}
V_3 -> V_45 = 0x0 ;
V_3 -> V_47 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_51 - 1 ; V_20 ++ )
V_3 -> V_52 [ V_20 ] = 0x0 ;
V_3 -> V_53 = 0x0 ;
V_3 -> V_55 = 0x0 ;
V_3 -> V_57 = 0x0 ;
V_3 -> V_112 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_59 ; V_20 ++ ) {
V_3 -> V_60 [ V_20 ] = 0x0 ;
V_3 -> V_61 [ V_20 ] = 0x0 ;
V_3 -> V_62 [ V_20 ] = 0x0 ;
}
V_3 -> V_113 = 0x2 ;
for ( V_20 = 2 ; V_20 < V_3 -> V_63 * 2 ; V_20 ++ )
V_3 -> V_64 [ V_20 ] = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_65 ; V_20 ++ ) {
V_3 -> V_66 [ V_20 ] = 0x0 ;
V_3 -> V_68 [ V_20 ] = 0x0 ;
}
V_3 -> V_93 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_69 * 2 ; V_20 ++ ) {
V_3 -> V_70 [ V_20 ] = 0x0 ;
V_3 -> V_71 [ V_20 ] = 0x0 ;
V_3 -> V_96 [ V_20 ] = V_114 ;
}
V_3 -> V_115 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_72 ; V_20 ++ ) {
V_3 -> V_73 [ V_20 ] = 0x0 ;
V_3 -> V_116 [ V_20 ] = 0x0 ;
}
V_3 -> V_74 = 0x0 ;
V_3 -> V_76 = 0x0 ;
V_3 -> V_117 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_78 ; V_20 ++ )
V_3 -> V_79 [ V_20 ] = 0x0 ;
V_3 -> V_80 = 0x0 ;
V_3 -> V_82 = 0x0 ;
V_3 -> V_16 = V_3 -> V_12 + 1 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_55 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_86 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_56 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 , V_86 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_86 = V_101 & V_118 ;
if ( V_3 -> V_86 & V_119 )
F_40 ( V_3 , true ) ;
else
F_40 ( V_3 , false ) ;
if ( V_3 -> V_120 == true ) {
V_3 -> V_26 &= ~ ( F_42 ( 1 ) | F_42 ( 2 ) ) ;
if ( V_3 -> V_86 & V_106 )
V_3 -> V_26 |= F_42 ( 1 ) ;
if ( V_3 -> V_86 & V_107 )
V_3 -> V_26 |= F_42 ( 2 ) ;
if ( V_3 -> V_86 & V_121 )
V_3 -> V_26 |= F_42 ( 1 ) | F_42 ( 2 ) ;
}
if ( ( V_3 -> V_86 & V_122 ) && ( V_3 -> V_123 == true ) )
V_3 -> V_26 |= F_42 ( 3 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 3 ) ;
if ( ( V_3 -> V_86 & V_124 ) &&
( V_3 -> V_125 == true ) )
V_3 -> V_26 |= F_42 ( 4 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 4 ) ;
if ( ( V_3 -> V_86 & V_126 ) && ( V_3 -> V_127 ) )
V_3 -> V_26 |= F_42 ( 6 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 6 ) ;
if ( ( V_3 -> V_86 & V_128 ) && ( V_3 -> V_129 ) )
V_3 -> V_26 |= F_42 ( 7 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 7 ) ;
V_86 = F_57 ( V_3 -> V_86 ) ;
if ( V_3 -> V_130 == true ) {
V_3 -> V_26 &= ~ ( F_42 ( 8 ) | F_42 ( 9 ) | F_42 ( 10 ) ) ;
V_3 -> V_26 |= V_86 << 8 ;
}
if ( ( V_3 -> V_86 & V_131 ) && ( V_3 -> V_132 ) )
V_3 -> V_26 |= F_42 ( 11 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 11 ) ;
if ( ( V_3 -> V_86 & V_133 ) &&
( V_3 -> V_134 == true ) )
V_3 -> V_26 |= F_42 ( 12 ) ;
else
V_3 -> V_26 &= ~ F_42 ( 12 ) ;
V_86 = F_58 ( V_3 -> V_86 ) ;
V_3 -> V_26 &= ~ ( F_42 ( 13 ) | F_42 ( 14 ) ) ;
if ( ( V_86 & F_42 ( 0 ) ) && ( V_3 -> V_135 & F_42 ( 0 ) ) )
V_3 -> V_26 |= F_42 ( 13 ) ;
if ( ( V_86 & F_42 ( 1 ) ) && ( V_3 -> V_135 & F_42 ( 1 ) ) )
V_3 -> V_26 |= F_42 ( 14 ) ;
if ( ( V_3 -> V_86 & V_136 ) &&
( V_3 -> V_137 == true ) )
V_3 -> V_31 |= F_42 ( 11 ) ;
else
V_3 -> V_31 &= ~ F_42 ( 11 ) ;
if ( ( V_3 -> V_86 & V_138 ) &&
( V_3 -> V_139 == true ) )
V_3 -> V_31 |= F_42 ( 12 ) ;
else
V_3 -> V_31 &= ~ F_42 ( 12 ) ;
if ( V_3 -> V_86 & V_140 )
V_3 -> V_33 |= F_42 ( 8 ) ;
else
V_3 -> V_33 &= ~ F_42 ( 8 ) ;
if ( V_3 -> V_86 & V_141 )
V_3 -> V_33 |= F_42 ( 10 ) ;
else
V_3 -> V_33 &= ~ F_42 ( 10 ) ;
if ( ( V_3 -> V_86 & V_142 ) &&
( V_3 -> V_143 == true ) )
V_3 -> V_33 |= F_42 ( 13 ) ;
else
V_3 -> V_33 &= ~ F_42 ( 13 ) ;
if ( V_3 -> V_86 & V_111 )
V_3 -> V_43 |= F_42 ( 9 ) ;
else
V_3 -> V_43 &= ~ F_42 ( 9 ) ;
if ( V_3 -> V_86 & V_144 )
V_3 -> V_43 |= F_42 ( 10 ) ;
else
V_3 -> V_43 &= ~ F_42 ( 10 ) ;
if ( ( V_3 -> V_86 & V_145 ) &&
( V_3 -> V_146 == true ) )
V_3 -> V_43 |= F_42 ( 11 ) ;
else
V_3 -> V_43 &= ~ F_42 ( 11 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_59 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_24 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_60 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
if ( V_101 > V_3 -> V_147 ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_95 ;
}
V_3 -> V_24 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_61 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_29 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_62 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
switch ( V_3 -> V_148 ) {
case 0x0 :
V_3 -> V_29 = V_101 & 0xFF ;
break;
case 0x1 :
V_3 -> V_29 = V_101 & 0xFFFF ;
break;
case 0x2 :
V_3 -> V_29 = V_101 & 0xFFFFFF ;
break;
case 0x3 :
V_3 -> V_29 = V_101 ;
break;
default:
break;
}
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_63 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = F_41 ( V_3 -> V_31 , 0 , 3 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_64 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_31 &= ~ ( F_42 ( 0 ) | F_42 ( 1 ) | F_42 ( 2 ) | F_42 ( 3 ) ) ;
switch ( V_3 -> V_148 ) {
case 0x0 :
V_3 -> V_31 |= V_101 & F_42 ( 1 ) ;
break;
case 0x1 :
V_3 -> V_31 |= V_101 & ( F_42 ( 0 ) | F_42 ( 1 ) ) ;
break;
case 0x2 :
V_3 -> V_31 |= V_101 & ( F_42 ( 0 ) | F_42 ( 1 ) | F_42 ( 2 ) ) ;
break;
case 0x3 :
V_3 -> V_31 |= V_101 & 0xF ;
break;
default:
break;
}
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_65 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_35 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_66 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( ! V_3 -> V_132 )
return - V_95 ;
V_3 -> V_35 = V_101 & V_149 ;
return V_105 ;
}
static T_3 F_67 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_37 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_68 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_3 -> V_110 == true )
return - V_95 ;
V_3 -> V_37 = V_101 & V_150 ;
return V_105 ;
}
static T_3 F_69 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_39 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_70 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 < V_3 -> V_151 )
return - V_95 ;
V_3 -> V_39 = V_101 & V_152 ;
return V_105 ;
}
static T_3 F_71 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_41 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_72 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_3 -> V_123 == false )
return - V_95 ;
if ( ! V_3 -> V_69 )
return - V_95 ;
if ( F_41 ( V_101 , 0 , 7 ) > V_3 -> V_69 )
return - V_95 ;
V_3 -> V_41 = V_101 ;
return V_105 ;
}
static T_3 F_73 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_43 & V_149 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_74 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_101 &= V_149 ;
V_3 -> V_43 &= ~ V_149 ;
V_3 -> V_43 |= V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_75 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = F_41 ( V_3 -> V_43 , 16 , 19 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_76 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_43 &= ~ ( F_42 ( 16 ) | F_42 ( 17 ) | F_42 ( 19 ) ) ;
V_101 &= V_3 -> V_153 ;
V_3 -> V_43 |= ( V_101 << 16 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_77 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = F_41 ( V_3 -> V_43 , 20 , 23 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_78 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_43 &= ~ ( F_42 ( 20 ) | F_42 ( 21 ) | F_42 ( 22 ) ) ;
V_101 &= V_3 -> V_154 ;
V_3 -> V_43 |= ( V_101 << 20 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_79 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_93 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_80 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_69 * 2 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_93 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_81 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_3 V_155 ;
T_1 V_101 , V_92 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
V_101 = F_41 ( V_3 -> V_71 [ V_92 ] , 0 , 1 ) ;
V_155 = F_44 ( V_100 , V_103 , L_7 ,
V_101 == V_94 ? L_8 :
( V_101 == V_156 ? L_9 :
( V_101 == V_157 ? L_10 :
L_11 ) ) ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_155 ;
}
static T_3 F_82 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
char V_158 [ 20 ] = L_12 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( strlen ( V_100 ) >= 20 )
return - V_95 ;
if ( sscanf ( V_100 , L_13 , V_158 ) != 1 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! strcmp ( V_158 , L_8 ) )
V_3 -> V_71 [ V_92 ] &= ~ ( F_42 ( 0 ) | F_42 ( 1 ) ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_83 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_92 = V_3 -> V_93 ;
F_31 ( & V_3 -> V_17 ) ;
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_159 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_101 = ( unsigned long ) V_3 -> V_70 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_84 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_159 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_3 -> V_70 [ V_92 ] = ( V_161 ) V_101 ;
V_3 -> V_96 [ V_92 ] = V_159 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_85 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_162 , V_163 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( V_92 % 2 != 0 ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
if ( ! ( ( V_3 -> V_96 [ V_92 ] == V_114 &&
V_3 -> V_96 [ V_92 + 1 ] == V_114 ) ||
( V_3 -> V_96 [ V_92 ] == V_97 &&
V_3 -> V_96 [ V_92 + 1 ] == V_97 ) ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_162 = ( unsigned long ) V_3 -> V_70 [ V_92 ] ;
V_163 = ( unsigned long ) V_3 -> V_70 [ V_92 + 1 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_14 , V_162 , V_163 ) ;
}
static T_3 F_86 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_162 , V_163 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( sscanf ( V_100 , L_15 , & V_162 , & V_163 ) != 2 )
return - V_95 ;
if ( V_162 > V_163 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( V_92 % 2 != 0 ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
if ( ! ( ( V_3 -> V_96 [ V_92 ] == V_114 &&
V_3 -> V_96 [ V_92 + 1 ] == V_114 ) ||
( V_3 -> V_96 [ V_92 ] == V_97 &&
V_3 -> V_96 [ V_92 + 1 ] == V_97 ) ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_3 -> V_70 [ V_92 ] = ( V_161 ) V_162 ;
V_3 -> V_96 [ V_92 ] = V_97 ;
V_3 -> V_70 [ V_92 + 1 ] = ( V_161 ) V_163 ;
V_3 -> V_96 [ V_92 + 1 ] = V_97 ;
if ( V_3 -> V_86 & V_119 )
F_40 ( V_3 , true ) ;
else
F_40 ( V_3 , false ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_87 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_164 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_101 = ( unsigned long ) V_3 -> V_70 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_88 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! V_3 -> V_69 ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_95 ;
}
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_164 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_3 -> V_70 [ V_92 ] = ( V_161 ) V_101 ;
V_3 -> V_96 [ V_92 ] = V_164 ;
V_3 -> V_47 |= F_42 ( V_92 ) ;
V_3 -> V_43 |= F_42 ( 9 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_89 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_165 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_101 = ( unsigned long ) V_3 -> V_70 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_90 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! V_3 -> V_69 ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_95 ;
}
if ( ! ( V_3 -> V_96 [ V_92 ] == V_114 ||
V_3 -> V_96 [ V_92 ] == V_165 ) ) {
F_33 ( & V_3 -> V_17 ) ;
return - V_160 ;
}
V_3 -> V_70 [ V_92 ] = ( V_161 ) V_101 ;
V_3 -> V_96 [ V_92 ] = V_165 ;
V_3 -> V_47 |= F_42 ( V_92 + 16 ) ;
V_3 -> V_43 |= F_42 ( 9 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_91 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_3 V_155 ;
T_1 V_92 , V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
V_101 = F_41 ( V_3 -> V_71 [ V_92 ] , 2 , 3 ) ;
V_155 = F_44 ( V_100 , V_103 , L_7 , V_101 == V_166 ? L_16 :
( V_101 == V_167 ? L_17 :
( V_101 == V_168 ? L_18 : L_19 ) ) ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_155 ;
}
static T_3 F_92 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
char V_158 [ 10 ] = L_12 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( strlen ( V_100 ) >= 10 )
return - V_95 ;
if ( sscanf ( V_100 , L_13 , V_158 ) != 1 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
if ( ! strcmp ( V_158 , L_16 ) )
V_3 -> V_71 [ V_92 ] &= ~ ( F_42 ( 2 ) | F_42 ( 3 ) ) ;
else if ( ! strcmp ( V_158 , L_17 ) ) {
if ( V_3 -> V_72 ) {
V_3 -> V_71 [ V_92 ] |= F_42 ( 2 ) ;
V_3 -> V_71 [ V_92 ] &= ~ F_42 ( 3 ) ;
}
} else if ( ! strcmp ( V_158 , L_18 ) ) {
if ( V_3 -> V_78 ) {
V_3 -> V_71 [ V_92 ] &= ~ F_42 ( 2 ) ;
V_3 -> V_71 [ V_92 ] |= F_42 ( 3 ) ;
}
} else if ( ! strcmp ( V_158 , L_19 ) ) {
if ( V_3 -> V_72 )
V_3 -> V_71 [ V_92 ] |= F_42 ( 2 ) ;
if ( V_3 -> V_78 )
V_3 -> V_71 [ V_92 ] |= F_42 ( 3 ) ;
}
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_93 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
V_101 = F_41 ( V_3 -> V_71 [ V_92 ] , 4 , 6 ) ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_94 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( ( V_3 -> V_72 <= 1 ) && ( V_3 -> V_78 <= 1 ) )
return - V_95 ;
if ( V_101 >= ( V_3 -> V_72 >= V_3 -> V_78 ?
V_3 -> V_72 : V_3 -> V_78 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_93 ;
V_3 -> V_71 [ V_92 ] &= ~ ( F_42 ( 4 ) | F_42 ( 5 ) | F_42 ( 6 ) ) ;
V_3 -> V_71 [ V_92 ] |= ( V_101 << 4 ) ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_95 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_169 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_96 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_51 - 1 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_169 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_97 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_55 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_98 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_51 )
return - V_95 ;
V_3 -> V_55 = V_101 ;
return V_105 ;
}
static T_3 F_99 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_169 ;
V_101 = V_3 -> V_52 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_100 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_169 ;
V_3 -> V_52 [ V_92 ] = V_101 & 0xFF ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_101 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_53 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_102 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( ! ( V_3 -> V_51 ) )
return - V_95 ;
V_3 -> V_53 = V_101 & V_149 ;
return V_105 ;
}
static T_3 F_103 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_112 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_104 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_59 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_112 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_105 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_101 = V_3 -> V_60 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_106 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 > V_170 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_3 -> V_60 [ V_92 ] = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_107 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_101 = V_3 -> V_62 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_108 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 > V_170 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_3 -> V_62 [ V_92 ] = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_109 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_101 = V_3 -> V_61 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_110 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_112 ;
V_3 -> V_61 [ V_92 ] = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_111 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_113 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_112 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 < 2 || V_101 >= V_3 -> V_63 * 2 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_113 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_113 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_113 ;
V_101 = V_3 -> V_64 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_114 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_113 ;
if ( V_92 % 2 != 0 )
V_101 &= ~ F_42 ( 21 ) ;
V_3 -> V_64 [ V_92 ] = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_115 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_115 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_116 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_72 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_115 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_117 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
T_1 V_92 ;
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_115 ;
V_101 = ( unsigned long ) V_3 -> V_116 [ V_92 ] ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_118 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_92 ;
unsigned long V_171 , V_172 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_127 || ! V_3 -> V_72 )
return - V_95 ;
if ( F_54 ( V_100 , 16 , & V_171 ) )
return - V_95 ;
V_172 = F_119 ( V_171 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_92 = V_3 -> V_115 ;
V_3 -> V_73 [ V_92 ] = ( V_161 ) V_172 ;
V_3 -> V_116 [ V_92 ] = ( V_161 ) V_171 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_120 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_162 , V_163 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_162 = V_3 -> V_74 ;
V_163 = V_3 -> V_76 ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_14 , V_162 , V_163 ) ;
}
static T_3 F_121 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_20 , V_173 , V_174 ;
unsigned long V_162 , V_163 , V_175 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_127 || ! V_3 -> V_72 )
return - V_95 ;
if ( sscanf ( V_100 , L_15 , & V_162 , & V_163 ) != 2 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
switch ( V_3 -> V_72 ) {
case 0x1 :
V_3 -> V_74 = V_162 & 0xFF ;
break;
case 0x2 :
V_3 -> V_74 = V_162 & 0xFFFF ;
break;
case 0x3 :
V_3 -> V_74 = V_162 & 0xFFFFFF ;
break;
case 0x4 :
V_3 -> V_74 = V_162 ;
break;
case 0x5 :
V_3 -> V_74 = V_162 ;
V_3 -> V_76 = V_163 & 0xFF ;
break;
case 0x6 :
V_3 -> V_74 = V_162 ;
V_3 -> V_76 = V_163 & 0xFFFF ;
break;
case 0x7 :
V_3 -> V_74 = V_162 ;
V_3 -> V_76 = V_163 & 0xFFFFFF ;
break;
case 0x8 :
V_3 -> V_74 = V_162 ;
V_3 -> V_76 = V_163 ;
break;
default:
break;
}
V_175 = V_3 -> V_74 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_72 ; V_20 ++ ) {
V_174 = V_175 & V_149 ;
for ( V_173 = 0 ; V_173 < 8 ; V_173 ++ ) {
if ( V_174 & 1 )
V_3 -> V_73 [ V_20 ] &= ~ ( 0xFF << ( V_173 * 8 ) ) ;
V_174 >>= 1 ;
}
if ( V_20 == 3 )
V_175 = V_3 -> V_76 ;
else
V_175 >>= 0x8 ;
}
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_122 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_117 ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_123 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
if ( V_101 >= V_3 -> V_78 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_117 = V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_124 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
char * V_100 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = ( unsigned long ) V_3 -> V_79 [ V_3 -> V_117 ] ;
return F_44 ( V_100 , V_103 , L_6 , V_101 ) ;
}
static T_3 F_125 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
unsigned long V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_129 || ! V_3 -> V_78 )
return - V_95 ;
if ( F_54 ( V_100 , 16 , & V_101 ) )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
V_3 -> V_79 [ V_3 -> V_117 ] = ( V_161 ) V_101 ;
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_126 ( struct V_98 * V_10 ,
struct V_99 * V_85 , char * V_100 )
{
unsigned long V_162 , V_163 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
F_31 ( & V_3 -> V_17 ) ;
V_162 = V_3 -> V_80 ;
V_163 = V_3 -> V_82 ;
F_33 ( & V_3 -> V_17 ) ;
return F_44 ( V_100 , V_103 , L_14 , V_162 , V_163 ) ;
}
static T_3 F_127 ( struct V_98 * V_10 ,
struct V_99 * V_85 ,
const char * V_100 , T_4 V_105 )
{
T_1 V_20 , V_173 , V_174 ;
unsigned long V_162 , V_163 , V_175 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
if ( ! V_3 -> V_129 || ! V_3 -> V_78 )
return - V_95 ;
if ( sscanf ( V_100 , L_15 , & V_162 , & V_163 ) != 2 )
return - V_95 ;
F_31 ( & V_3 -> V_17 ) ;
switch ( V_3 -> V_78 ) {
case 0x1 :
V_3 -> V_80 = V_162 & 0xFF ;
break;
case 0x2 :
V_3 -> V_80 = V_162 & 0xFFFF ;
break;
case 0x3 :
V_3 -> V_80 = V_162 & 0xFFFFFF ;
break;
case 0x4 :
V_3 -> V_80 = V_162 ;
break;
case 0x5 :
V_3 -> V_80 = V_162 ;
V_3 -> V_82 = V_163 & 0xFF ;
break;
case 0x6 :
V_3 -> V_80 = V_162 ;
V_3 -> V_82 = V_163 & 0xFFFF ;
break;
case 0x7 :
V_3 -> V_80 = V_162 ;
V_3 -> V_82 = V_163 & 0xFFFFFF ;
break;
case 0x8 :
V_3 -> V_80 = V_162 ;
V_3 -> V_82 = V_163 ;
break;
default:
break;
}
V_175 = V_3 -> V_80 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_78 ; V_20 ++ ) {
V_174 = V_175 & V_149 ;
for ( V_173 = 0 ; V_173 < 8 ; V_173 ++ ) {
if ( V_174 & 1 )
V_3 -> V_79 [ V_20 ] &= ~ ( 0xFF << ( V_173 * 8 ) ) ;
V_174 >>= 1 ;
}
if ( V_20 == 3 )
V_175 = V_3 -> V_82 ;
else
V_175 >>= 0x8 ;
}
F_33 ( & V_3 -> V_17 ) ;
return V_105 ;
}
static T_3 F_128 ( struct V_98 * V_10 ,
struct V_99 * V_85 , char * V_100 )
{
int V_101 ;
struct V_2 * V_3 = F_6 ( V_10 -> V_11 ) ;
V_101 = V_3 -> V_12 ;
return F_44 ( V_100 , V_103 , L_20 , V_101 ) ;
}
static void F_129 ( void * V_1 )
{
T_2 V_176 ;
T_2 V_177 ;
T_2 V_178 ;
T_2 V_179 ;
T_2 V_180 ;
T_2 V_181 ;
struct V_2 * V_3 = V_1 ;
F_9 ( V_3 -> V_4 ) ;
V_176 = F_10 ( V_3 -> V_4 + V_182 ) ;
if ( F_41 ( V_176 , 1 , 1 ) && F_41 ( V_176 , 2 , 2 ) )
V_3 -> V_120 = true ;
else
V_3 -> V_120 = false ;
if ( F_41 ( V_176 , 5 , 5 ) )
V_3 -> V_123 = true ;
else
V_3 -> V_123 = false ;
if ( F_41 ( V_176 , 6 , 6 ) )
V_3 -> V_130 = true ;
else
V_3 -> V_130 = false ;
if ( F_41 ( V_176 , 7 , 7 ) )
V_3 -> V_125 = true ;
else
V_3 -> V_125 = false ;
if ( F_41 ( V_176 , 9 , 9 ) )
V_3 -> V_134 = true ;
else
V_3 -> V_134 = false ;
V_3 -> V_148 = F_41 ( V_176 , 10 , 11 ) ;
V_3 -> V_135 = F_41 ( V_176 , 15 , 16 ) ;
V_3 -> V_132 = F_41 ( V_176 , 24 , 28 ) ;
V_177 = F_10 ( V_3 -> V_4 + V_183 ) ;
V_3 -> V_6 = F_41 ( V_177 , 4 , 11 ) ;
V_178 = F_10 ( V_3 -> V_4 + V_184 ) ;
V_3 -> V_127 = F_41 ( V_178 , 5 , 9 ) ;
V_3 -> V_129 = F_41 ( V_178 , 10 , 14 ) ;
V_3 -> V_185 = F_41 ( V_178 , 25 , 28 ) ;
V_179 = F_10 ( V_3 -> V_4 + V_186 ) ;
V_3 -> V_151 = F_41 ( V_179 , 0 , 11 ) ;
V_3 -> V_153 = F_41 ( V_179 , 16 , 19 ) ;
V_3 -> V_154 = F_41 ( V_179 , 20 , 23 ) ;
if ( F_41 ( V_179 , 24 , 24 ) )
V_3 -> V_146 = true ;
else
V_3 -> V_146 = false ;
if ( F_41 ( V_179 , 25 , 25 ) )
V_3 -> V_110 = true ;
else
V_3 -> V_110 = false ;
if ( F_41 ( V_179 , 26 , 26 ) )
V_3 -> V_187 = true ;
else
V_3 -> V_187 = false ;
if ( F_41 ( V_179 , 27 , 27 ) )
V_3 -> V_188 = true ;
else
V_3 -> V_188 = false ;
V_3 -> V_147 = F_41 ( V_179 , 28 , 30 ) ;
if ( F_41 ( V_179 , 31 , 31 ) )
V_3 -> V_143 = true ;
else
V_3 -> V_143 = false ;
V_180 = F_10 ( V_3 -> V_4 + V_189 ) ;
V_3 -> V_69 = F_41 ( V_180 , 0 , 3 ) ;
V_3 -> V_102 = F_41 ( V_180 , 12 , 15 ) ;
V_3 -> V_63 = F_41 ( V_180 , 16 , 19 ) + 1 ;
V_3 -> V_65 = F_41 ( V_180 , 20 , 23 ) ;
V_3 -> V_72 = F_41 ( V_180 , 24 , 27 ) ;
V_3 -> V_78 = F_41 ( V_180 , 28 , 31 ) ;
V_181 = F_10 ( V_3 -> V_4 + V_190 ) ;
V_3 -> V_104 = F_41 ( V_181 , 0 , 8 ) ;
V_3 -> V_191 = F_41 ( V_181 , 16 , 21 ) ;
if ( F_41 ( V_181 , 22 , 22 ) )
V_3 -> V_137 = true ;
else
V_3 -> V_137 = false ;
if ( F_41 ( V_181 , 23 , 23 ) )
V_3 -> V_139 = true ;
else
V_3 -> V_139 = false ;
V_3 -> V_51 = F_41 ( V_181 , 25 , 27 ) ;
V_3 -> V_59 = F_41 ( V_181 , 28 , 30 ) ;
F_11 ( V_3 -> V_4 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
int V_20 ;
V_3 -> V_24 = 0x0 ;
V_3 -> V_26 = ( V_126 | V_128 |
V_131 | V_133 ) ;
V_3 -> V_29 = 0x0 ;
V_3 -> V_31 = 0x0 ;
V_3 -> V_33 = 0x0 ;
V_3 -> V_35 = 0x0 ;
if ( V_3 -> V_110 == false )
V_3 -> V_37 = 0xC ;
V_3 -> V_43 |= F_42 ( 0 ) ;
if ( V_3 -> V_69 )
V_3 -> V_43 |= F_42 ( 9 ) ;
V_3 -> V_45 = 0x0 ;
V_3 -> V_47 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_51 - 1 ; V_20 ++ )
V_3 -> V_52 [ V_20 ] = 0x0 ;
V_3 -> V_53 = 0x0 ;
V_3 -> V_55 = 0x0 ;
V_3 -> V_57 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_59 ; V_20 ++ ) {
V_3 -> V_60 [ V_20 ] = 0x0 ;
V_3 -> V_61 [ V_20 ] = 0x0 ;
V_3 -> V_62 [ V_20 ] = 0x0 ;
}
V_3 -> V_113 = 0x2 ;
for ( V_20 = 2 ; V_20 < V_3 -> V_63 * 2 ; V_20 ++ )
V_3 -> V_64 [ V_20 ] = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_65 ; V_20 ++ ) {
V_3 -> V_66 [ V_20 ] = 0x0 ;
V_3 -> V_68 [ V_20 ] = 0x0 ;
}
if ( V_3 -> V_69 >= 1 ) {
V_3 -> V_70 [ 0 ] = ( unsigned long ) V_192 ;
V_3 -> V_70 [ 1 ] = ( unsigned long ) V_193 ;
V_3 -> V_96 [ 0 ] = V_97 ;
V_3 -> V_96 [ 1 ] = V_97 ;
}
for ( V_20 = 0 ; V_20 < V_3 -> V_72 ; V_20 ++ ) {
V_3 -> V_73 [ V_20 ] = 0x0 ;
V_3 -> V_116 [ V_20 ] = 0x0 ;
}
V_3 -> V_74 = 0x0 ;
V_3 -> V_76 = 0x0 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_78 ; V_20 ++ )
V_3 -> V_79 [ V_20 ] = 0x0 ;
V_3 -> V_80 = 0x0 ;
V_3 -> V_82 = 0x0 ;
V_3 -> V_16 = 0x20 + V_3 -> V_12 ;
}
static int F_131 ( struct V_194 * V_195 , unsigned long V_196 ,
void * V_197 )
{
unsigned int V_12 = ( unsigned long ) V_197 ;
if ( ! V_198 [ V_12 ] )
goto V_199;
switch ( V_196 & ( ~ V_200 ) ) {
case V_201 :
F_31 ( & V_198 [ V_12 ] -> V_17 ) ;
if ( ! V_198 [ V_12 ] -> V_202 ) {
F_1 ( V_198 [ V_12 ] ) ;
V_198 [ V_12 ] -> V_202 = true ;
}
if ( V_198 [ V_12 ] -> V_15 )
F_13 ( V_198 [ V_12 ] ) ;
F_33 ( & V_198 [ V_12 ] -> V_17 ) ;
break;
case V_203 :
if ( V_198 [ V_12 ] -> V_204 &&
! V_198 [ V_12 ] -> V_89 )
F_132 ( V_198 [ V_12 ] -> V_9 ) ;
break;
case V_205 :
F_31 ( & V_198 [ V_12 ] -> V_17 ) ;
if ( V_198 [ V_12 ] -> V_15 )
F_35 ( V_198 [ V_12 ] ) ;
F_33 ( & V_198 [ V_12 ] -> V_17 ) ;
break;
}
V_199:
return V_206 ;
}
static int F_133 ( struct V_207 * V_208 , const struct V_209 * V_210 )
{
int V_87 ;
void T_5 * V_4 ;
struct V_98 * V_10 = & V_208 -> V_10 ;
struct V_211 * V_212 = NULL ;
struct V_2 * V_3 ;
struct V_213 * V_214 = & V_208 -> V_214 ;
struct V_215 * V_216 ;
struct V_217 * V_218 = V_208 -> V_10 . V_219 ;
V_216 = F_134 ( V_10 , sizeof( * V_216 ) , V_220 ) ;
if ( ! V_216 )
return - V_221 ;
V_3 = F_134 ( V_10 , sizeof( * V_3 ) , V_220 ) ;
if ( ! V_3 )
return - V_221 ;
if ( V_218 ) {
V_212 = F_135 ( V_10 , V_218 ) ;
if ( F_136 ( V_212 ) )
return F_137 ( V_212 ) ;
V_208 -> V_10 . V_222 = V_212 ;
}
V_3 -> V_10 = & V_208 -> V_10 ;
F_138 ( V_10 , V_3 ) ;
V_4 = F_139 ( V_10 , V_214 ) ;
if ( F_136 ( V_4 ) )
return F_137 ( V_4 ) ;
V_3 -> V_4 = V_4 ;
F_140 ( & V_3 -> V_17 ) ;
V_3 -> V_12 = V_212 ? V_212 -> V_12 : 0 ;
F_38 () ;
V_198 [ V_3 -> V_12 ] = V_3 ;
if ( ! F_32 ( V_3 -> V_12 , F_1 , V_3 , 1 ) )
V_3 -> V_202 = true ;
if ( F_32 ( V_3 -> V_12 ,
F_129 , V_3 , 1 ) )
F_15 ( V_10 , L_21 ) ;
if ( ! V_223 ++ )
F_141 ( & V_224 ) ;
F_39 () ;
if ( F_4 ( V_3 -> V_6 ) == false ) {
V_87 = - V_95 ;
goto V_225;
}
F_130 ( V_3 ) ;
F_142 ( & V_208 -> V_10 ) ;
V_216 -> type = V_226 ;
V_216 -> V_227 . V_228 = V_229 ;
V_216 -> V_230 = & V_231 ;
V_216 -> V_212 = V_212 ;
V_216 -> V_10 = V_10 ;
V_216 -> V_232 = V_233 ;
V_3 -> V_9 = F_143 ( V_216 ) ;
if ( F_136 ( V_3 -> V_9 ) ) {
V_87 = F_137 ( V_3 -> V_9 ) ;
goto V_234;
}
F_34 ( V_10 , L_22 , ( char * ) V_210 -> V_235 ) ;
if ( V_204 ) {
F_132 ( V_3 -> V_9 ) ;
V_3 -> V_204 = true ;
}
return 0 ;
V_225:
F_142 ( & V_208 -> V_10 ) ;
V_234:
if ( -- V_223 == 0 )
F_144 ( & V_224 ) ;
return V_87 ;
}
