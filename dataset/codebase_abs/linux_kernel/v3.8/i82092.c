static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned char V_5 ;
int V_6 , V_7 ;
F_2 ( L_1 ) ;
if ( ( V_7 = F_3 ( V_2 ) ) )
return V_7 ;
F_4 ( V_2 , 0x40 , & V_5 ) ;
switch( V_5 & 6 ) {
case 0 :
V_8 = 2 ;
break;
case 2 :
V_8 = 1 ;
break;
case 4 :
case 6 :
V_8 = 4 ;
break;
default:
F_5 ( V_9 L_2 ) ;
V_7 = - V_10 ;
goto V_11;
}
F_5 ( V_12 L_3 , V_8 ) ;
if ( ! F_6 ( F_7 ( V_2 , 0 ) , 2 , L_4 ) ) {
V_7 = - V_13 ;
goto V_11;
}
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_14 [ V_6 ] . V_15 = 1 ;
V_14 [ V_6 ] . V_16 = F_7 ( V_2 , 0 ) ;
V_14 [ V_6 ] . V_17 . V_18 |= V_19 ;
V_14 [ V_6 ] . V_17 . V_20 = 0x1000 ;
V_14 [ V_6 ] . V_17 . V_21 = 0 ;
V_14 [ V_6 ] . V_17 . V_22 = V_2 -> V_23 ;
V_14 [ V_6 ] . V_17 . V_24 = V_2 ;
V_14 [ V_6 ] . V_17 . V_25 = V_26 ;
V_14 [ V_6 ] . V_27 = V_6 ;
if ( F_8 ( V_6 ) ) {
V_14 [ V_6 ] . V_15 = 3 ;
F_9 ( V_28 L_5 , V_6 ) ;
} else {
F_9 ( V_28 L_6 , V_6 ) ;
}
}
V_5 = 0xFF ;
F_10 ( V_2 , 0x50 , V_5 ) ;
F_9 ( V_28 L_7 , V_2 -> V_23 ) ;
if ( ( V_7 = F_11 ( V_2 -> V_23 , V_29 , V_30 , L_4 , V_29 ) ) ) {
F_5 ( V_9 L_8 , V_2 -> V_23 ) ;
goto V_31;
}
F_12 ( V_2 , & V_14 [ V_6 ] . V_17 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_14 [ V_6 ] . V_17 . V_2 . V_32 = & V_2 -> V_2 ;
V_14 [ V_6 ] . V_17 . V_33 = & V_34 ;
V_14 [ V_6 ] . V_17 . V_35 = & V_36 ;
V_7 = F_13 ( & V_14 [ V_6 ] . V_17 ) ;
if ( V_7 ) {
goto V_37;
}
}
F_14 ( L_1 ) ;
return 0 ;
V_37:
if ( V_6 ) {
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
F_15 ( & V_14 [ V_6 ] . V_17 ) ;
}
}
F_16 ( V_2 -> V_23 , V_29 ) ;
V_31:
F_17 ( F_7 ( V_2 , 0 ) , 2 ) ;
V_11:
F_18 ( V_2 ) ;
return V_7 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_38 * V_17 = F_20 ( V_2 ) ;
F_2 ( L_9 ) ;
F_16 ( V_2 -> V_23 , V_29 ) ;
if ( V_17 )
F_15 ( V_17 ) ;
F_14 ( L_9 ) ;
}
static unsigned char F_21 ( int V_17 , unsigned short V_39 )
{
unsigned short int V_40 ;
unsigned char V_41 ;
unsigned long V_42 ;
F_22 ( & V_43 , V_42 ) ;
V_39 += V_17 * 0x40 ;
V_40 = V_14 [ V_17 ] . V_16 ;
F_23 ( V_39 , V_40 ) ;
V_41 = F_24 ( V_40 + 1 ) ;
F_25 ( & V_43 , V_42 ) ;
return V_41 ;
}
static void F_26 ( int V_17 , unsigned short V_39 , unsigned char V_44 )
{
unsigned short int V_40 ;
unsigned long V_42 ;
F_22 ( & V_43 , V_42 ) ;
V_39 = V_39 + V_17 * 0x40 ;
V_40 = V_14 [ V_17 ] . V_16 ;
F_23 ( V_39 , V_40 ) ;
F_23 ( V_44 , V_40 + 1 ) ;
F_25 ( & V_43 , V_42 ) ;
}
static void F_27 ( int V_17 , unsigned short V_39 , unsigned char V_45 )
{
unsigned short int V_40 ;
unsigned char V_41 ;
unsigned long V_42 ;
F_22 ( & V_43 , V_42 ) ;
V_39 = V_39 + V_17 * 0x40 ;
V_40 = V_14 [ V_17 ] . V_16 ;
F_23 ( V_39 , V_40 ) ;
V_41 = F_24 ( V_40 + 1 ) ;
V_41 |= V_45 ;
F_23 ( V_39 , V_40 ) ;
F_23 ( V_41 , V_40 + 1 ) ;
F_25 ( & V_43 , V_42 ) ;
}
static void F_28 ( int V_17 , unsigned short V_39 , unsigned char V_45 )
{
unsigned short int V_40 ;
unsigned char V_41 ;
unsigned long V_42 ;
F_22 ( & V_43 , V_42 ) ;
V_39 = V_39 + V_17 * 0x40 ;
V_40 = V_14 [ V_17 ] . V_16 ;
F_23 ( V_39 , V_40 ) ;
V_41 = F_24 ( V_40 + 1 ) ;
V_41 &= ~ V_45 ;
F_23 ( V_39 , V_40 ) ;
F_23 ( V_41 , V_40 + 1 ) ;
F_25 ( & V_43 , V_42 ) ;
}
static void F_29 ( int V_17 , unsigned short V_39 , unsigned short V_44 )
{
unsigned short int V_40 ;
unsigned char V_41 ;
unsigned long V_42 ;
F_22 ( & V_43 , V_42 ) ;
V_39 = V_39 + V_17 * 0x40 ;
V_40 = V_14 [ V_17 ] . V_16 ;
F_23 ( V_39 , V_40 ) ;
V_41 = V_44 & 255 ;
F_23 ( V_41 , V_40 + 1 ) ;
V_39 ++ ;
F_23 ( V_39 , V_40 ) ;
V_41 = V_44 >> 8 ;
F_23 ( V_41 , V_40 + 1 ) ;
F_25 ( & V_43 , V_42 ) ;
}
static int F_30 ( int V_46 )
{
if ( V_47 != 0 )
return V_46 / V_47 ;
else
return 0 ;
}
static T_1 V_29 ( int V_23 , void * V_2 )
{
int V_6 ;
int V_48 = 0 ;
int V_49 = 0 ;
unsigned int V_50 , V_51 = 0 ;
while ( 1 ) {
V_48 ++ ;
if ( V_48 > 20 ) {
F_5 ( V_9 L_10 ) ;
break;
}
V_51 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
int V_52 ;
if ( V_14 [ V_6 ] . V_15 == 0 )
continue;
V_52 = F_21 ( V_6 , V_53 ) ;
if ( V_52 == 0 )
continue;
V_49 = 1 ;
V_50 = 0 ;
if ( V_52 & V_54 ) {
V_50 |= V_55 ;
F_5 ( L_11 , V_6 ) ;
}
if ( F_21 ( V_6 , V_56 ) & V_57 ) {
V_50 |= ( V_52 & V_58 ) ? V_59 : 0 ;
} else {
V_50 |= ( V_52 & V_60 ) ? V_61 : 0 ;
V_50 |= ( V_52 & V_62 ) ? V_63 : 0 ;
V_50 |= ( V_52 & V_64 ) ? V_65 : 0 ;
}
if ( V_50 ) {
F_31 ( & V_14 [ V_6 ] . V_17 , V_50 ) ;
}
V_51 |= V_50 ;
}
if ( V_51 == 0 )
break;
}
return F_32 ( V_49 ) ;
}
static int F_8 ( int V_66 )
{
unsigned int V_41 ;
F_2 ( L_12 ) ;
if ( ( V_66 < 0 ) || ( V_66 >= V_67 ) )
return 0 ;
if ( V_14 [ V_66 ] . V_16 == 0 )
return 0 ;
V_41 = F_21 ( V_66 , 1 ) ;
if ( ( V_41 & 12 ) == 12 ) {
F_14 ( L_13 ) ;
return 1 ;
}
F_14 ( L_14 ) ;
return 0 ;
}
static void F_33 ( int V_68 )
{
F_2 ( L_15 ) ;
F_26 ( V_68 , V_69 , 0x00 ) ;
F_26 ( V_68 , V_70 , 0x00 ) ;
F_27 ( V_68 , V_56 , 0x08 ) ;
F_14 ( L_15 ) ;
}
static int F_34 ( struct V_38 * V_68 )
{
int V_6 ;
struct V_71 V_72 = { . V_73 = 0 , . V_74 = 0x0fff } ;
T_2 V_75 = { 0 , 0 , 0 , 0 , 1 } ;
T_3 V_76 = { . V_72 = & V_72 , } ;
F_2 ( L_16 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_75 . V_77 = V_6 ;
F_35 ( V_68 , & V_75 ) ;
}
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ ) {
V_76 . V_77 = V_6 ;
F_36 ( V_68 , & V_76 ) ;
}
F_14 ( L_16 ) ;
return 0 ;
}
static int F_37 ( struct V_38 * V_17 , T_4 * V_44 )
{
unsigned int V_68 = F_38 ( V_17 , struct V_78 , V_17 ) -> V_27 ;
unsigned int V_79 ;
F_2 ( L_17 ) ;
V_79 = F_21 ( V_68 , V_80 ) ;
* V_44 = 0 ;
if ( ( V_79 & V_81 ) == V_81 ) {
* V_44 |= V_55 ;
}
if ( F_21 ( V_68 , V_56 ) & V_57 ) {
if ( ! ( V_79 & V_82 ) )
* V_44 |= V_59 ;
} else {
if ( ! ( V_79 & V_83 ) )
* V_44 |= V_61 ;
if ( ! ( V_79 & V_84 ) )
* V_44 |= V_63 ;
}
if ( V_79 & V_85 )
( * V_44 ) |= V_86 ;
if ( V_79 & V_87 )
( * V_44 ) |= V_65 ;
if ( V_79 & V_88 )
( * V_44 ) |= V_89 ;
F_14 ( L_17 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_17 , T_5 * V_90 )
{
unsigned int V_68 = F_38 ( V_17 , struct V_78 , V_17 ) -> V_27 ;
unsigned char V_39 ;
F_2 ( L_18 ) ;
F_33 ( V_68 ) ;
V_39 = 0 ;
if ( ! ( V_90 -> V_42 & V_91 ) )
V_39 = V_39 | V_92 ;
if ( V_90 -> V_42 & V_93 )
V_39 = V_39 | V_57 ;
F_26 ( V_68 , V_56 , V_39 ) ;
V_39 = V_94 ;
if ( V_90 -> V_42 & V_95 ) {
F_5 ( L_19 ) ;
V_39 |= V_96 ;
}
if ( V_90 -> V_42 & V_97 ) {
F_5 ( L_20 ) ;
V_39 |= V_98 ;
}
switch ( V_90 -> V_99 ) {
case 0 :
break;
case 50 :
F_5 ( L_21 , V_68 ) ;
V_39 |= V_100 ;
break;
default:
F_5 ( L_22 , V_90 -> V_99 ) ;
F_14 ( L_18 ) ;
return - V_101 ;
}
switch ( V_90 -> V_102 ) {
case 0 :
F_5 ( L_23 , V_68 ) ;
break;
case 50 :
F_5 ( L_24 , V_68 ) ;
V_39 |= V_103 | V_104 ;
break;
case 120 :
F_5 ( L_25 ) ;
V_39 |= V_105 | V_106 ;
break;
default:
F_5 ( L_26 , V_90 -> V_99 ) ;
F_14 ( L_18 ) ;
return - V_101 ;
}
if ( V_39 != F_21 ( V_68 , V_107 ) )
F_26 ( V_68 , V_107 , V_39 ) ;
V_39 = 0x00 ;
if ( V_90 -> V_108 & V_55 ) {
V_39 |= V_54 ;
}
if ( V_90 -> V_42 & V_93 ) {
if ( V_90 -> V_108 & V_59 )
V_39 |= V_58 ;
} else {
if ( V_90 -> V_108 & V_61 )
V_39 |= V_60 ;
if ( V_90 -> V_108 & V_63 )
V_39 |= V_62 ;
if ( V_90 -> V_108 & V_65 )
V_39 |= V_64 ;
}
F_26 ( V_68 , V_109 , V_39 ) ;
( void ) F_21 ( V_68 , V_53 ) ;
F_14 ( L_18 ) ;
return 0 ;
}
static int F_35 ( struct V_38 * V_17 , struct T_2 * V_75 )
{
unsigned int V_68 = F_38 ( V_17 , struct V_78 , V_17 ) -> V_27 ;
unsigned char V_77 , V_110 ;
F_2 ( L_27 ) ;
V_77 = V_75 -> V_77 ;
if ( V_77 > 1 ) {
F_14 ( L_28 ) ;
return - V_101 ;
}
if ( ( V_75 -> V_73 > 0xffff ) || ( V_75 -> V_111 > 0xffff ) || ( V_75 -> V_111 < V_75 -> V_73 ) ) {
F_14 ( L_29 ) ;
return - V_101 ;
}
if ( F_21 ( V_68 , V_112 ) & F_40 ( V_77 ) )
F_28 ( V_68 , V_112 , F_40 ( V_77 ) ) ;
F_29 ( V_68 , F_41 ( V_77 ) + V_113 , V_75 -> V_73 ) ;
F_29 ( V_68 , F_41 ( V_77 ) + V_114 , V_75 -> V_111 ) ;
V_110 = F_21 ( V_68 , V_115 ) & ~ F_42 ( V_77 ) ;
if ( V_75 -> V_42 & ( V_116 | V_117 ) )
V_110 |= F_43 ( V_77 ) ;
F_26 ( V_68 , V_115 , V_110 ) ;
if ( V_75 -> V_42 & V_118 )
F_27 ( V_68 , V_112 , F_40 ( V_77 ) ) ;
F_14 ( L_27 ) ;
return 0 ;
}
static int F_36 ( struct V_38 * V_17 , struct T_3 * V_76 )
{
struct V_78 * V_119 = F_38 ( V_17 , struct V_78 , V_17 ) ;
unsigned int V_68 = V_119 -> V_27 ;
struct V_120 V_121 ;
unsigned short V_122 , V_6 ;
unsigned char V_77 ;
F_2 ( L_30 ) ;
F_44 ( V_119 -> V_2 , & V_121 , V_76 -> V_72 ) ;
V_77 = V_76 -> V_77 ;
if ( V_77 > 4 ) {
F_14 ( L_31 ) ;
return - V_101 ;
}
if ( ( V_76 -> V_123 > 0x3ffffff ) || ( V_121 . V_73 > V_121 . V_74 ) ||
( V_76 -> V_124 > 1000 ) ) {
F_14 ( L_32 ) ;
F_5 ( L_33
L_34 ,
V_68 ,
( unsigned long long ) V_121 . V_73 ,
( unsigned long long ) V_121 . V_74 ,
V_76 -> V_123 ) ;
return - V_101 ;
}
if ( F_21 ( V_68 , V_112 ) & F_45 ( V_77 ) )
F_28 ( V_68 , V_112 , F_45 ( V_77 ) ) ;
V_122 = F_46 ( V_77 ) ;
V_6 = ( V_121 . V_73 >> 12 ) & 0x0fff ;
if ( V_76 -> V_42 & V_116 )
V_6 |= V_125 ;
if ( V_76 -> V_42 & V_126 )
V_6 |= V_127 ;
F_29 ( V_68 , V_122 + V_113 , V_6 ) ;
V_6 = ( V_121 . V_74 >> 12 ) & 0x0fff ;
switch ( F_30 ( V_76 -> V_124 ) ) {
case 0 :
break;
case 1 :
V_6 |= V_128 ;
break;
case 2 :
V_6 |= V_129 ;
break;
default:
V_6 |= V_129 | V_128 ;
break;
}
F_29 ( V_68 , V_122 + V_114 , V_6 ) ;
V_6 = ( ( V_76 -> V_123 - V_121 . V_73 ) >> 12 ) & 0x3fff ;
if ( V_76 -> V_42 & V_130 )
V_6 |= V_131 ;
if ( V_76 -> V_42 & V_132 ) {
V_6 |= V_133 ;
} else {
}
F_29 ( V_68 , V_122 + V_134 , V_6 ) ;
if ( V_76 -> V_42 & V_118 )
F_27 ( V_68 , V_112 , F_45 ( V_77 ) ) ;
F_14 ( L_30 ) ;
return 0 ;
}
static int F_47 ( void )
{
return F_48 ( & V_135 ) ;
}
static void F_49 ( void )
{
F_2 ( L_35 ) ;
F_50 ( & V_135 ) ;
if ( V_14 [ 0 ] . V_16 > 0 )
F_17 ( V_14 [ 0 ] . V_16 , 2 ) ;
F_14 ( L_35 ) ;
}
