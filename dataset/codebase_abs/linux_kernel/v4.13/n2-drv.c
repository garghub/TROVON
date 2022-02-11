static int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
case V_7 :
return - V_8 ;
case V_9 :
return - V_10 ;
case V_11 :
case V_12 :
return - V_13 ;
default:
return - V_14 ;
}
}
static unsigned long F_2 ( unsigned long V_15 ,
unsigned long V_16 )
{
unsigned long V_1 , V_17 , V_18 , V_19 , V_20 ;
int V_21 = 0 , V_22 = 0 ;
while ( 1 ) {
V_1 = F_3 ( V_15 , V_16 , & V_17 ,
& V_18 ,
& V_19 ,
& V_20 ) ;
if ( V_1 == V_2 )
break;
if ( V_1 == V_9 ) {
if ( ++ V_22 >= V_23 )
break;
F_4 ( 1 ) ;
} else if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
break;
F_5 ( V_18 ) ;
} else
break;
}
return V_1 ;
}
static unsigned long F_6 ( struct V_25 * V_26 , int V_16 )
{
unsigned long V_15 = F_7 ( & V_26 -> V_27 [ 0 ] ) ;
return F_2 ( V_15 , V_16 ) ;
}
static unsigned long F_8 ( struct V_25 * V_26 , int V_16 ,
unsigned long V_17 ,
unsigned long V_28 ,
unsigned long V_29 ,
unsigned long * V_18 )
{
unsigned long V_1 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_9 ( V_28 , V_17 ,
V_29 , V_18 ) ;
} else {
V_1 = F_10 ( V_28 , V_17 ,
V_29 , V_16 ) ;
if ( V_1 == V_2 )
V_1 = F_6 ( V_26 , V_16 ) ;
* V_18 = V_31 ;
}
return V_1 ;
}
static int F_11 ( unsigned long V_32 )
{
unsigned long V_18 , V_1 ;
int V_21 = 0 , V_33 = 0 ;
while ( 1 ) {
V_1 = F_12 ( V_32 , & V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_5 ) {
return - V_6 ;
} else if ( V_1 == V_7 ) {
if ( ++ V_33 >= V_35 )
return - V_8 ;
F_4 ( 10000 ) ;
} else
return - V_36 ;
}
}
static unsigned long F_13 ( struct V_25 * V_26 ,
unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_37 ,
unsigned long * V_18 )
{
unsigned long V_1 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_14 ( V_32 , V_37 , V_18 ) ;
} else {
V_1 = F_15 ( V_32 , V_37 ,
V_16 , V_18 ) ;
if ( ! * V_18 )
* V_18 = V_31 ;
}
return V_1 ;
}
static int F_16 ( struct V_25 * V_26 ,
unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_37 )
{
unsigned long V_18 , V_1 ;
int V_21 = 0 ;
while ( 1 ) {
V_1 = F_13 ( V_26 , V_16 ,
V_32 , V_37 ,
& V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_5 ) {
return - V_6 ;
} else if ( V_1 == V_7 ) {
return - V_8 ;
} else
return - V_36 ;
}
}
static int F_17 ( struct V_25 * V_26 ,
unsigned long V_28 ,
unsigned long V_16 ,
unsigned long V_17 )
{
unsigned long V_1 , V_18 ;
int V_21 = 0 , V_22 = 0 ;
while ( 1 ) {
V_1 = F_8 ( V_26 , V_16 , V_17 , V_28 ,
V_26 -> V_38 , & V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_9 ) {
if ( ++ V_22 >= V_23 )
return - V_10 ;
F_4 ( 1 ) ;
} else
return - V_36 ;
}
}
static int F_18 ( struct V_25 * V_26 )
{
unsigned long V_1 ;
unsigned long V_39 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_19 () ;
} else {
V_1 = F_3 ( 0UL , ~ 0UL , & V_39 , & V_39 , & V_39 , & V_39 ) ;
switch ( V_1 ) {
case V_3 :
case V_5 :
break;
default:
V_1 = V_2 ;
break;
}
}
return F_1 ( V_1 ) ;
}
static T_1 F_20 ( struct V_25 * V_26 , int V_40 )
{
T_1 V_41 = 0 ;
if ( V_26 -> V_42 -> V_43 == 1 ) {
V_41 = ( ( 2 << V_44 ) |
( V_31 << V_45 ) |
V_46 ) ;
switch ( V_40 ) {
case 0 :
V_41 |= ( 1 << V_47 ) | V_48 ;
break;
case 1 :
V_41 |= ( 2 << V_47 ) | V_49 ;
break;
case 2 :
V_41 |= ( 3 << V_47 ) | V_50 ;
break;
case 3 :
V_41 |= V_48 | V_49 | V_50 ;
break;
default:
break;
}
} else {
V_41 = ( ( 2 << V_51 ) |
( V_31 << V_52 ) |
V_46 ) ;
switch ( V_40 ) {
case 0 :
V_41 |= ( 1 << V_53 ) | V_48 ;
break;
case 1 :
V_41 |= ( 2 << V_53 ) | V_49 ;
break;
case 2 :
V_41 |= ( 3 << V_53 ) | V_50 ;
break;
case 3 :
V_41 |= V_48 | V_49 | V_50 ;
break;
default:
break;
}
}
return V_41 ;
}
static void F_21 ( struct V_25 * V_26 )
{
int V_54 ;
V_26 -> V_55 |= V_56 ;
V_26 -> V_57 = V_58 ;
V_26 -> V_59 = V_31 ;
V_26 -> V_38 = V_60 ;
for ( V_54 = 0 ; V_54 < V_26 -> V_61 ; V_54 ++ ) {
struct V_62 * V_63 = & V_26 -> V_64 [ V_54 ] ;
V_63 -> V_65 [ 0 ] = F_20 ( V_26 , 0 ) ;
V_63 -> V_65 [ 1 ] = F_20 ( V_26 , 1 ) ;
V_63 -> V_65 [ 2 ] = F_20 ( V_26 , 2 ) ;
V_63 -> V_65 [ 3 ] = F_20 ( V_26 , 3 ) ;
}
V_26 -> V_66 = V_67 ;
}
static int F_22 ( struct V_25 * V_26 )
{
int V_54 , V_68 , V_69 = - V_36 ;
V_68 = 0 ;
for ( V_54 = 0 ; V_54 < 100 ; V_54 ++ ) {
V_69 = F_18 ( V_26 ) ;
if ( V_69 != - V_4 )
break;
if ( ++ V_68 > 100 ) {
F_23 ( & V_26 -> V_70 -> V_71 ,
L_1 ) ;
return - V_36 ;
}
F_4 ( 1 ) ;
}
return V_69 ;
}
static int F_24 ( struct V_25 * V_26 )
{
int V_69 = F_22 ( V_26 ) ;
if ( V_69 == - V_6 )
return 0 ;
if ( V_69 )
return V_69 ;
F_21 ( V_26 ) ;
return 0 ;
}
static int F_25 ( struct V_72 * V_73 , T_2 * V_42 )
{
struct V_25 * V_26 = (struct V_25 * ) V_73 -> V_74 ;
unsigned long V_15 = F_7 ( & V_26 -> V_75 ) ;
int V_76 ;
if ( ! ( V_26 -> V_55 & V_77 ) ) {
V_76 = 0 ;
} else if ( V_26 -> V_55 & V_78 ) {
V_26 -> V_55 &= ~ V_78 ;
* V_42 = V_26 -> V_79 ;
V_76 = 4 ;
} else {
int V_69 = F_11 ( V_15 ) ;
if ( ! V_69 ) {
V_26 -> V_55 |= V_78 ;
V_26 -> V_79 = V_26 -> V_75 >> 32 ;
* V_42 = V_26 -> V_75 & 0xffffffff ;
V_76 = 4 ;
} else {
F_23 ( & V_26 -> V_70 -> V_71 , L_2 ) ;
V_26 -> V_55 &= ~ V_77 ;
if ( ! ( V_26 -> V_55 & V_80 ) )
F_26 ( & V_26 -> V_81 , 0 ) ;
V_76 = 0 ;
}
}
return V_76 ;
}
static int F_27 ( struct V_25 * V_26 )
{
unsigned long V_15 = F_7 ( & V_26 -> V_75 ) ;
return F_11 ( V_15 ) ;
}
static int F_28 ( struct V_25 * V_26 , unsigned long V_16 ,
T_1 * V_82 , T_1 V_83 ,
T_1 * V_79 , unsigned long V_84 ,
T_1 * V_85 , T_1 V_86 )
{
unsigned long V_87 = F_7 ( V_85 ) ;
unsigned long V_88 = F_7 ( V_82 ) ;
unsigned long V_89 = F_7 ( V_79 ) ;
int V_69 ;
V_69 = F_17 ( V_26 , V_88 , V_16 , V_83 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_16 ( V_26 , V_16 ,
V_89 , V_84 ) ;
( void ) F_17 ( V_26 , V_87 , V_16 ,
V_86 ) ;
return V_69 ;
}
static T_1 F_29 ( T_1 V_90 , T_1 V_41 , int V_91 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
int V_92 = ( ( V_93 ) V_41 < 0 ) ;
V_41 <<= 1 ;
if ( V_92 )
V_41 ^= V_90 ;
}
return V_41 ;
}
static int F_30 ( struct V_25 * V_26 , T_1 V_41 )
{
int V_54 , V_91 = 0 ;
for ( V_54 = 1 ; V_54 < V_94 ; V_54 ++ ) {
if ( V_26 -> V_95 [ V_54 ] == V_41 )
V_91 ++ ;
}
return V_91 ;
}
static void F_31 ( struct V_25 * V_26 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_94 ; V_54 ++ )
F_23 ( & V_26 -> V_70 -> V_71 , L_3 ,
V_54 , V_26 -> V_95 [ V_54 ] ) ;
}
static int F_32 ( struct V_25 * V_26 , unsigned long V_16 )
{
T_1 V_41 ;
int V_69 , V_96 , V_97 ;
switch ( V_26 -> V_42 -> V_98 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_41 = V_103 ;
break;
default:
V_41 = V_104 ;
break;
}
V_96 = 0 ;
for ( V_97 = 0 ; V_97 < V_105 ; V_97 ++ ) {
V_96 += F_30 ( V_26 , V_41 ) ;
if ( V_96 >= V_106 )
break;
V_41 = F_29 ( V_107 , V_41 , 1 ) ;
}
V_69 = 0 ;
if ( V_97 >= V_105 ) {
V_69 = - V_36 ;
F_23 ( & V_26 -> V_70 -> V_71 , L_4 , V_16 ) ;
F_31 ( V_26 ) ;
} else
F_33 ( & V_26 -> V_70 -> V_71 , L_5 , V_16 ) ;
return V_69 ;
}
static int F_34 ( struct V_25 * V_26 , unsigned long V_16 )
{
int V_69 ;
T_1 V_108 , V_109 ;
switch ( V_26 -> V_42 -> V_98 ) {
case V_99 :
case V_100 :
case V_101 :
V_108 = V_110 << V_44 ;
V_109 = V_108 | V_46 |
( ( V_111 - 2 ) << V_45 ) ;
break;
case V_102 :
V_108 = V_112 << V_51 ;
V_109 = V_108 | V_46 |
( ( V_111 - 2 ) << V_52 ) ;
break;
default:
V_108 = V_112 << V_51 ;
V_109 = V_108 | V_46 |
( V_113 << V_52 ) ;
break;
}
V_26 -> V_114 [ 0 ] = V_108 ;
V_26 -> V_114 [ 1 ] = V_108 ;
V_26 -> V_114 [ 2 ] = V_108 ;
V_26 -> V_114 [ 3 ] = V_109 ;
V_69 = F_28 ( V_26 , V_16 , V_26 -> V_114 ,
V_115 ,
V_26 -> V_95 ,
sizeof( V_26 -> V_95 ) ,
& V_26 -> V_64 [ V_16 ] . V_65 [ 0 ] ,
V_26 -> V_66 ) ;
if ( V_69 )
return V_69 ;
return F_32 ( V_26 , V_16 ) ;
}
static int F_35 ( struct V_25 * V_26 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_26 -> V_61 ; V_54 ++ ) {
int V_69 = F_34 ( V_26 , V_54 ) ;
if ( V_69 )
return V_69 ;
}
return 0 ;
}
static int F_36 ( struct V_25 * V_26 )
{
int V_16 , V_69 ;
V_69 = 0 ;
for ( V_16 = 0 ; V_16 < V_26 -> V_61 ; V_16 ++ ) {
struct V_62 * V_63 = & V_26 -> V_64 [ V_16 ] ;
unsigned long V_116 = F_7 ( & V_63 -> V_65 [ 0 ] ) ;
int V_117 ;
T_1 V_108 , V_118 ;
if ( V_26 -> V_42 -> V_43 == 1 ) {
V_108 = ( ( V_26 -> V_59 << V_45 ) |
( V_110 << V_44 ) |
V_46 ) ;
V_118 = V_47 ;
} else {
V_108 = ( ( V_26 -> V_59 << V_52 ) |
( V_112 << V_51 ) |
V_46 ) ;
V_118 = V_53 ;
}
for ( V_117 = 0 ; V_117 < 3 ; V_117 ++ )
V_63 -> V_65 [ V_117 ] = V_108 |
( V_117 << V_118 ) |
( V_48 << V_117 ) ;
V_63 -> V_65 [ 3 ] = V_108 |
( V_48 | V_49 | V_50 ) ;
V_69 = F_17 ( V_26 , V_116 , V_16 ,
V_119 ) ;
if ( V_69 )
break;
}
return V_69 ;
}
static void F_37 ( struct V_120 * V_81 )
{
struct V_25 * V_26 = F_38 ( V_81 , struct V_25 , V_81 . V_81 ) ;
int V_69 = 0 ;
static int V_121 = 4 ;
if ( ! ( V_26 -> V_55 & V_56 ) ) {
V_69 = F_27 ( V_26 ) ;
} else {
F_39 () ;
V_69 = F_35 ( V_26 ) ;
F_40 () ;
if ( ! V_69 )
V_69 = F_36 ( V_26 ) ;
}
if ( ! V_69 ) {
V_26 -> V_55 |= V_77 ;
F_33 ( & V_26 -> V_70 -> V_71 , L_6 ) ;
}
if ( -- V_121 == 0 )
F_23 ( & V_26 -> V_70 -> V_71 , L_7 ) ;
else if ( V_69 && ! ( V_26 -> V_55 & V_80 ) )
F_26 ( & V_26 -> V_81 , V_122 * 2 ) ;
}
static void F_41 ( void )
{
static int V_123 ;
if ( V_123 ++ == 0 )
F_42 ( L_8 , V_124 ) ;
}
static int F_43 ( struct V_125 * V_70 )
{
const struct V_126 * V_127 ;
int V_69 = - V_128 ;
struct V_25 * V_26 ;
V_127 = F_44 ( V_129 , & V_70 -> V_71 ) ;
if ( ! V_127 )
return - V_14 ;
F_41 () ;
V_26 = F_45 ( & V_70 -> V_71 , sizeof( * V_26 ) , V_130 ) ;
if ( ! V_26 )
goto V_131;
V_26 -> V_70 = V_70 ;
V_26 -> V_42 = (struct V_132 * ) V_127 -> V_42 ;
F_46 ( & V_26 -> V_81 , F_37 ) ;
if ( V_26 -> V_42 -> V_133 )
V_26 -> V_55 |= V_134 ;
V_69 = - V_36 ;
V_26 -> V_30 = 2 ;
if ( F_47 ( V_135 ,
V_26 -> V_30 ,
& V_26 -> V_136 ) ) {
V_26 -> V_30 = 1 ;
if ( F_47 ( V_135 ,
V_26 -> V_30 ,
& V_26 -> V_136 ) ) {
F_23 ( & V_70 -> V_71 , L_9
L_10 ) ;
goto V_131;
}
}
if ( V_26 -> V_55 & V_134 ) {
if ( V_26 -> V_30 < 2 ) {
F_23 ( & V_70 -> V_71 , L_11
L_12 ,
V_26 -> V_30 ) ;
goto V_137;
}
V_26 -> V_61 = F_48 ( V_70 -> V_71 . V_138 ,
L_13 , 0 ) ;
if ( ! V_26 -> V_61 ) {
F_23 ( & V_70 -> V_71 , L_14 ) ;
goto V_137;
}
} else {
V_26 -> V_61 = 1 ;
}
F_33 ( & V_70 -> V_71 , L_15 ,
V_26 -> V_30 , V_26 -> V_136 ) ;
V_26 -> V_64 = F_49 ( & V_70 -> V_71 , V_26 -> V_61 , sizeof( * V_26 -> V_64 ) ,
V_130 ) ;
V_69 = - V_128 ;
if ( ! V_26 -> V_64 )
goto V_137;
V_69 = F_24 ( V_26 ) ;
if ( V_69 )
goto V_137;
F_33 ( & V_70 -> V_71 , L_16 ,
( ( V_26 -> V_55 & V_134 ) ?
L_17 : L_18 ) ,
V_26 -> V_61 ) ;
V_26 -> V_72 . V_139 = V_140 ;
V_26 -> V_72 . V_141 = F_25 ;
V_26 -> V_72 . V_74 = ( unsigned long ) V_26 ;
V_69 = F_50 ( & V_26 -> V_72 ) ;
if ( V_69 )
goto V_137;
F_51 ( V_70 , V_26 ) ;
F_26 ( & V_26 -> V_81 , 0 ) ;
return 0 ;
V_137:
F_52 ( V_135 ) ;
V_131:
return V_69 ;
}
static int F_53 ( struct V_125 * V_70 )
{
struct V_25 * V_26 = F_54 ( V_70 ) ;
V_26 -> V_55 |= V_80 ;
F_55 ( & V_26 -> V_81 ) ;
F_56 ( & V_26 -> V_72 ) ;
F_52 ( V_135 ) ;
return 0 ;
}
