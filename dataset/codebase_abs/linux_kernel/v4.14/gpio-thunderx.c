static unsigned int F_1 ( unsigned int line )
{
return 8 * line + V_1 ;
}
static unsigned int F_2 ( unsigned int line )
{
return 8 * line + V_2 ;
}
static bool F_3 ( struct V_3 * V_4 ,
unsigned int line )
{
T_1 V_5 = F_4 ( V_4 -> V_6 + F_1 ( line ) ) ;
return ( V_5 & V_7 ) == 0 ;
}
static bool F_5 ( struct V_3 * V_4 ,
unsigned int line )
{
bool V_8 = F_3 ( V_4 , line ) ;
F_6 ( ! V_8 , L_1 , line ) ;
return V_8 ;
}
static int F_7 ( struct V_9 * V_10 , unsigned int line )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
return F_5 ( V_4 , line ) ? 0 : - V_11 ;
}
static int F_9 ( struct V_9 * V_10 , unsigned int line )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
if ( ! F_5 ( V_4 , line ) )
return - V_11 ;
F_10 ( & V_4 -> V_12 ) ;
F_11 ( line , V_4 -> V_13 ) ;
F_11 ( line , V_4 -> V_14 ) ;
F_12 ( V_4 -> V_15 [ line ] . V_16 ,
V_4 -> V_6 + F_1 ( line ) ) ;
F_13 ( & V_4 -> V_12 ) ;
return 0 ;
}
static void F_14 ( struct V_9 * V_10 , unsigned int line ,
int V_17 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
int V_18 = line / 64 ;
int V_19 = line % 64 ;
void T_2 * V_20 = V_4 -> V_6 +
( V_18 * V_21 ) + ( V_17 ? V_22 : V_23 ) ;
F_12 ( F_15 ( V_19 ) , V_20 ) ;
}
static int F_16 ( struct V_9 * V_10 , unsigned int line ,
int V_17 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
T_1 V_5 = V_4 -> V_15 [ line ] . V_16 | V_24 ;
if ( ! F_5 ( V_4 , line ) )
return - V_11 ;
F_10 ( & V_4 -> V_12 ) ;
F_14 ( V_10 , line , V_17 ) ;
if ( F_17 ( line , V_4 -> V_13 ) )
V_5 |= V_25 ;
if ( F_17 ( line , V_4 -> V_14 ) )
V_5 |= V_26 ;
F_12 ( V_5 , V_4 -> V_6 + F_1 ( line ) ) ;
F_13 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , unsigned int line )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
T_1 V_5 ;
if ( ! F_3 ( V_4 , line ) )
return 1 ;
V_5 = F_4 ( V_4 -> V_6 + F_1 ( line ) ) ;
return ! ( V_5 & V_24 ) ;
}
static int F_19 ( struct V_9 * V_10 ,
unsigned int line ,
unsigned long V_27 )
{
bool V_28 , V_29 , V_30 , V_31 , V_32 ;
T_3 V_33 , V_34 ;
T_1 V_5 ;
int V_18 = line / 64 ;
int V_19 = line % 64 ;
int V_35 = - V_36 ;
struct V_3 * V_4 = F_8 ( V_10 ) ;
void T_2 * V_20 = V_4 -> V_6 + ( V_18 * V_21 ) + V_22 ;
if ( ! F_5 ( V_4 , line ) )
return - V_11 ;
F_10 ( & V_4 -> V_12 ) ;
V_28 = F_17 ( line , V_4 -> V_13 ) ;
V_31 = V_28 ;
V_29 = F_17 ( line , V_4 -> V_14 ) ;
V_32 = V_29 ;
V_30 = ( ( F_4 ( V_20 ) >> V_19 ) & 1 ) ^ V_28 ;
V_5 = F_4 ( V_4 -> V_6 + F_1 ( line ) ) ;
switch ( F_20 ( V_27 ) ) {
case V_37 :
F_21 ( line , V_4 -> V_13 ) ;
V_31 = true ;
F_21 ( line , V_4 -> V_14 ) ;
V_32 = true ;
V_35 = 0 ;
break;
case V_38 :
F_11 ( line , V_4 -> V_13 ) ;
V_31 = false ;
F_11 ( line , V_4 -> V_14 ) ;
V_32 = false ;
V_35 = 0 ;
break;
case V_39 :
V_33 = F_22 ( V_27 ) ;
if ( V_33 > 1228 ) {
V_35 = - V_40 ;
break;
}
V_33 *= 400 ;
V_34 = 0 ;
while ( V_33 > 15 ) {
V_34 ++ ;
V_33 ++ ;
V_33 >>= 1 ;
}
V_4 -> V_15 [ line ] . V_16 =
( V_34 << V_41 ) |
( V_33 << V_42 ) ;
V_5 &= ~ V_43 ;
V_5 |= V_4 -> V_15 [ line ] . V_16 ;
F_12 ( V_5 , V_4 -> V_6 + F_1 ( line ) ) ;
V_35 = 0 ;
break;
default:
break;
}
F_13 ( & V_4 -> V_12 ) ;
if ( ( V_31 != V_28 || V_32 != V_29 ) &&
( V_5 & V_24 ) )
V_35 = F_16 ( V_10 , line , V_30 ^ V_31 ) ;
return V_35 ;
}
static int F_23 ( struct V_9 * V_10 , unsigned int line )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
int V_18 = line / 64 ;
int V_19 = line % 64 ;
T_1 V_44 = F_4 ( V_4 -> V_6 + ( V_18 * V_21 ) + V_45 ) ;
T_1 V_46 = V_44 & F_15 ( V_19 ) ;
if ( F_17 ( line , V_4 -> V_13 ) )
return V_46 == 0 ;
else
return V_46 != 0 ;
}
static void F_24 ( struct V_9 * V_10 ,
unsigned long * V_47 ,
unsigned long * V_48 )
{
int V_18 ;
T_1 V_49 , V_50 ;
struct V_3 * V_4 = F_8 ( V_10 ) ;
for ( V_18 = 0 ; V_18 <= V_10 -> V_51 / 64 ; V_18 ++ ) {
V_49 = V_48 [ V_18 ] & V_47 [ V_18 ] ;
V_50 = ~ V_48 [ V_18 ] & V_47 [ V_18 ] ;
F_12 ( V_49 , V_4 -> V_6 + ( V_18 * V_21 ) + V_22 ) ;
F_12 ( V_50 , V_4 -> V_6 + ( V_18 * V_21 ) + V_23 ) ;
}
}
static void F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
F_12 ( V_56 ,
V_55 -> V_4 -> V_6 + F_2 ( V_55 -> line ) ) ;
}
static void F_27 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
F_12 ( V_57 ,
V_55 -> V_4 -> V_6 + F_2 ( V_55 -> line ) ) ;
}
static void F_28 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
F_12 ( V_57 | V_56 ,
V_55 -> V_4 -> V_6 + F_2 ( V_55 -> line ) ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
F_12 ( V_58 ,
V_55 -> V_4 -> V_6 + F_2 ( V_55 -> line ) ) ;
}
static int F_30 ( struct V_52 * V_53 ,
unsigned int V_59 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
T_1 V_5 ;
F_31 ( V_53 , V_59 ) ;
V_5 = V_55 -> V_16 | V_60 ;
if ( V_59 & V_61 ) {
F_32 ( V_53 , V_62 ) ;
V_5 |= V_63 ;
} else {
F_32 ( V_53 , V_64 ) ;
}
F_10 ( & V_4 -> V_12 ) ;
if ( V_59 & ( V_65 | V_66 ) ) {
V_5 |= V_25 ;
F_21 ( V_55 -> line , V_4 -> V_13 ) ;
} else {
F_11 ( V_55 -> line , V_4 -> V_13 ) ;
}
F_11 ( V_55 -> line , V_4 -> V_14 ) ;
F_12 ( V_5 , V_4 -> V_6 + F_1 ( V_55 -> line ) ) ;
F_13 ( & V_4 -> V_12 ) ;
return V_67 ;
}
static void F_33 ( struct V_52 * V_53 )
{
F_34 ( V_53 ) ;
F_29 ( V_53 ) ;
}
static void F_35 ( struct V_52 * V_53 )
{
F_27 ( V_53 ) ;
F_36 ( V_53 ) ;
}
static int F_37 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_52 * V_68 = V_53 -> V_68 ;
int V_69 ;
V_69 = F_38 ( & V_4 -> V_10 , V_55 -> line ) ;
if ( V_69 )
return V_69 ;
if ( V_68 && V_68 -> V_10 -> V_70 ) {
V_69 = V_68 -> V_10 -> V_70 ( V_68 ) ;
if ( V_69 )
goto error;
}
return 0 ;
error:
F_39 ( & V_4 -> V_10 , V_55 -> line ) ;
return V_69 ;
}
static void F_40 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_52 * V_68 = V_53 -> V_68 ;
if ( V_68 && V_68 -> V_10 -> V_71 )
V_68 -> V_10 -> V_71 ( V_68 ) ;
F_39 ( & V_4 -> V_10 , V_55 -> line ) ;
}
static int F_41 ( struct V_72 * V_73 , unsigned int V_74 ,
T_4 V_75 )
{
struct V_3 * V_4 = V_73 -> V_76 ;
if ( V_75 >= V_4 -> V_10 . V_51 )
return - V_40 ;
if ( ! F_3 ( V_4 , V_75 ) )
return - V_77 ;
return 0 ;
}
static int F_42 ( struct V_72 * V_73 ,
struct V_78 * V_79 ,
T_4 * V_75 ,
unsigned int * type )
{
struct V_3 * V_4 = V_73 -> V_76 ;
if ( F_43 ( V_79 -> V_80 < 2 ) )
return - V_40 ;
if ( V_79 -> V_81 [ 0 ] >= V_4 -> V_10 . V_51 )
return - V_40 ;
* V_75 = V_79 -> V_81 [ 0 ] ;
* type = V_79 -> V_81 [ 1 ] & V_82 ;
return 0 ;
}
static int F_44 ( struct V_72 * V_73 , unsigned int V_83 ,
unsigned int V_84 , void * V_33 )
{
struct V_54 * V_55 = V_33 ;
return F_45 ( V_73 , V_83 , V_55 -> line ,
& V_85 , V_55 ) ;
}
static int F_46 ( struct V_9 * V_10 , unsigned int V_86 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
return F_47 ( V_4 -> V_87 , V_86 ) ;
}
static int F_48 ( struct V_88 * V_89 ,
const struct V_90 * V_91 )
{
void T_2 * const * V_92 ;
struct V_93 * V_94 = & V_89 -> V_94 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
int V_51 , V_95 ;
int V_96 = 0 ;
V_4 = F_49 ( V_94 , sizeof( * V_4 ) , V_97 ) ;
if ( ! V_4 )
return - V_98 ;
F_50 ( & V_4 -> V_12 ) ;
V_10 = & V_4 -> V_10 ;
F_51 ( V_89 , V_4 ) ;
V_96 = F_52 ( V_89 ) ;
if ( V_96 ) {
F_53 ( V_94 , L_2 , V_96 ) ;
goto V_99;
}
V_96 = F_54 ( V_89 , 1 << 0 , V_100 ) ;
if ( V_96 ) {
F_53 ( V_94 , L_3 , V_96 ) ;
goto V_99;
}
V_92 = F_55 ( V_89 ) ;
V_4 -> V_6 = V_92 [ 0 ] ;
if ( ! V_4 -> V_6 ) {
F_53 ( V_94 , L_4 ) ;
V_96 = - V_98 ;
goto V_99;
}
if ( V_89 -> V_101 == 0xa10a ) {
V_51 = 50 ;
V_4 -> V_102 = 48 ;
} else {
T_1 V_103 = F_4 ( V_4 -> V_6 + V_104 ) ;
V_51 = V_103 & V_105 ;
V_4 -> V_102 = ( V_103 >> 8 ) & 0xff ;
}
V_4 -> V_106 = F_49 ( V_94 ,
sizeof( struct V_107 ) * V_51 ,
V_97 ) ;
if ( ! V_4 -> V_106 ) {
V_96 = - V_98 ;
goto V_99;
}
V_4 -> V_15 = F_49 ( V_94 ,
sizeof( struct V_54 ) * V_51 ,
V_97 ) ;
if ( ! V_4 -> V_15 ) {
V_96 = - V_98 ;
goto V_99;
}
for ( V_95 = 0 ; V_95 < V_51 ; V_95 ++ ) {
T_1 V_5 = F_4 ( V_4 -> V_6 + F_1 ( V_95 ) ) ;
V_4 -> V_106 [ V_95 ] . V_108 = V_4 -> V_102 + ( 2 * V_95 ) ;
V_4 -> V_15 [ V_95 ] . line = V_95 ;
V_4 -> V_15 [ V_95 ] . V_4 = V_4 ;
V_4 -> V_15 [ V_95 ] . V_16 = V_5 ?
( V_5 & V_43 ) : V_109 ;
if ( ( V_5 & V_24 ) && ( V_5 & V_26 ) )
F_21 ( V_95 , V_4 -> V_14 ) ;
if ( V_5 & V_25 )
F_21 ( V_95 , V_4 -> V_13 ) ;
}
V_96 = F_56 ( V_89 , V_4 -> V_106 , V_51 , V_51 ) ;
if ( V_96 < 0 )
goto V_99;
V_4 -> V_87 = F_57 ( F_58 ( V_4 -> V_106 [ 0 ] . V_110 ) -> V_111 ,
0 , 0 , F_59 ( V_94 -> V_112 ) ,
& V_113 , V_4 ) ;
if ( ! V_4 -> V_87 )
goto V_99;
for ( V_95 = 0 ; V_95 < V_51 ; V_95 ++ ) {
V_96 = F_60 ( V_4 -> V_87 ,
V_4 -> V_106 [ V_95 ] . V_110 ,
& V_4 -> V_15 [ V_95 ] ) ;
if ( V_96 < 0 )
F_53 ( V_94 , L_5 , V_96 ) ;
}
V_10 -> V_114 = V_100 ;
V_10 -> V_115 = V_94 ;
V_10 -> V_116 = V_117 ;
V_10 -> V_118 = F_7 ;
V_10 -> V_119 = - 1 ;
V_10 -> V_120 = false ;
V_10 -> V_51 = V_51 ;
V_10 -> V_121 = F_18 ;
V_10 -> V_122 = F_9 ;
V_10 -> V_123 = F_23 ;
V_10 -> V_124 = F_16 ;
V_10 -> V_125 = F_14 ;
V_10 -> V_126 = F_24 ;
V_10 -> V_127 = F_19 ;
V_10 -> V_128 = F_46 ;
V_96 = F_61 ( V_94 , V_10 , V_4 ) ;
if ( V_96 )
goto V_99;
F_62 ( V_94 , L_6 ,
V_51 , V_10 -> V_119 ) ;
return 0 ;
V_99:
F_51 ( V_89 , NULL ) ;
return V_96 ;
}
static void F_63 ( struct V_88 * V_89 )
{
int V_95 ;
struct V_3 * V_4 = F_64 ( V_89 ) ;
for ( V_95 = 0 ; V_95 < V_4 -> V_10 . V_51 ; V_95 ++ )
F_65 ( V_4 -> V_87 ,
V_4 -> V_106 [ V_95 ] . V_110 ) ;
F_66 ( V_4 -> V_87 ) ;
F_51 ( V_89 , NULL ) ;
}
