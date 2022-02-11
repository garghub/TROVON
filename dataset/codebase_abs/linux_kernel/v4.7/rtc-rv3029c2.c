static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_3 > V_8 + 7 ) ||
( V_3 + V_5 > V_8 + 8 ) )
return - V_9 ;
return F_3 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 const V_4 [] ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_3 > V_8 + 7 ) ||
( V_3 + V_5 > V_8 + 8 ) )
return - V_9 ;
return F_5 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 , T_1 V_12 )
{
T_1 V_4 ;
int V_13 ;
V_13 = F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 &= ~ V_11 ;
V_4 |= V_12 & V_11 ;
V_13 = F_4 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_13 = F_1 ( V_2 , V_14 , V_4 , 1 ) ;
if ( V_13 < 0 )
return - V_15 ;
F_8 ( V_2 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_4 [ 1 ] ;
int V_17 ;
V_4 [ 0 ] = V_16 ;
V_17 = F_4 ( V_2 , V_14 , V_4 , 1 ) ;
F_8 ( V_2 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
if ( V_17 < 0 )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_18 , V_13 ;
T_1 V_17 ;
for ( V_18 = 100 ; V_18 > 0 ; V_18 -- ) {
V_13 = F_7 ( V_2 , & V_17 ) ;
if ( V_13 < 0 )
break;
if ( ! ( V_17 & V_19 ) )
break;
F_11 ( 1000 , 10000 ) ;
}
if ( V_18 <= 0 ) {
F_12 ( V_2 , L_2 ) ;
return - V_20 ;
}
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_21 ,
V_22 ,
V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_17 ;
V_13 = F_7 ( V_2 , & V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_17 & ( V_23 | V_24 ) ) {
V_17 &= ~ V_23 ;
V_17 &= ~ V_24 ;
V_13 = F_9 ( V_2 , V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
F_11 ( 1000 , 10000 ) ;
V_13 = F_7 ( V_2 , & V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_17 & ( V_23 | V_24 ) ) {
F_12 ( V_2 ,
L_3 ) ;
return - V_25 ;
}
}
V_13 = F_6 ( V_2 , V_21 , V_22 ,
0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 < 0 )
F_13 ( V_2 ) ;
return V_13 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 [] , T_2 V_5 )
{
int V_13 , V_26 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
V_13 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_26 = F_13 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 const V_4 [] , T_2 V_5 )
{
int V_13 , V_26 ;
T_2 V_18 ;
T_1 V_27 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_18 = 0 ; V_18 < V_5 ; V_18 ++ , V_3 ++ ) {
V_13 = F_1 ( V_2 , V_3 , & V_27 , 1 ) ;
if ( V_13 < 0 )
break;
if ( V_27 != V_4 [ V_18 ] ) {
V_13 = F_4 ( V_2 , V_3 , & V_4 [ V_18 ] , 1 ) ;
if ( V_13 < 0 )
break;
}
V_13 = F_10 ( V_2 ) ;
if ( V_13 < 0 )
break;
}
V_26 = F_13 ( V_2 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_11 , T_1 V_12 )
{
T_1 V_4 ;
int V_13 ;
V_13 = F_15 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 &= ~ V_11 ;
V_4 |= V_12 & V_11 ;
V_13 = F_16 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static T_3 F_18 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 * V_31 = & V_7 -> V_32 -> V_33 ;
unsigned long V_34 = 0 ;
T_1 V_35 , V_36 ;
int V_13 ;
F_19 ( V_31 ) ;
V_13 = F_1 ( V_2 , V_37 , & V_36 , 1 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_4 , V_13 ) ;
F_21 ( V_31 ) ;
return V_38 ;
}
V_13 = F_1 ( V_2 , V_39 , & V_35 , 1 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_5 , V_13 ) ;
F_21 ( V_31 ) ;
return V_38 ;
}
if ( V_35 & V_40 ) {
V_35 &= ~ V_40 ;
V_36 &= ~ V_41 ;
V_34 |= V_42 ;
}
if ( V_34 ) {
F_22 ( V_7 -> V_32 , 1 , V_34 ) ;
F_4 ( V_2 , V_39 , & V_35 , 1 ) ;
F_4 ( V_2 , V_37 , & V_36 , 1 ) ;
}
F_21 ( V_31 ) ;
return V_43 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
T_1 V_4 [ 1 ] ;
int V_13 ;
T_1 V_46 [ V_47 ] = { 0 , } ;
V_13 = F_7 ( V_2 , V_4 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_6 , V_48 ) ;
return - V_15 ;
}
V_13 = F_1 ( V_2 , V_49 , V_46 ,
V_47 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_7 , V_48 ) ;
return V_13 ;
}
V_45 -> V_50 = F_24 ( V_46 [ V_49 - V_49 ] ) ;
V_45 -> V_51 = F_24 ( V_46 [ V_52 - V_49 ] ) ;
{
const T_1 V_53 = V_46 [ V_54 - V_49 ] ;
if ( V_53 & V_55 ) {
V_45 -> V_56 = F_24 ( V_53 & 0x1f ) ;
if ( V_53 & V_57 )
V_45 -> V_56 += 12 ;
} else
V_45 -> V_56 = F_24 ( V_53 & 0x3f ) ;
}
V_45 -> V_58 = F_24 ( V_46 [ V_59 - V_49 ] ) ;
V_45 -> V_60 = F_24 ( V_46 [ V_61 - V_49 ] ) - 1 ;
V_45 -> V_62 = F_24 ( V_46 [ V_63 - V_49 ] ) + 100 ;
V_45 -> V_64 = F_24 ( V_46 [ V_65 - V_49 ] ) - 1 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_44 * const V_45 = & V_67 -> time ;
int V_13 ;
T_1 V_46 [ 8 ] , V_36 , V_35 ;
V_13 = F_7 ( V_2 , V_46 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_6 , V_48 ) ;
return - V_15 ;
}
V_13 = F_1 ( V_2 , V_68 , V_46 ,
V_69 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_8 , V_48 ) ;
return V_13 ;
}
V_13 = F_1 ( V_2 , V_37 , & V_36 , 1 ) ;
if ( V_13 ) {
F_12 ( V_2 , L_4 , V_13 ) ;
return V_13 ;
}
V_13 = F_1 ( V_2 , V_39 , & V_35 , 1 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_5 , V_13 ) ;
return V_13 ;
}
V_45 -> V_50 = F_24 ( V_46 [ V_68 - V_68 ] & 0x7f ) ;
V_45 -> V_51 = F_24 ( V_46 [ V_70 - V_68 ] & 0x7f ) ;
V_45 -> V_56 = F_24 ( V_46 [ V_71 - V_68 ] & 0x3f ) ;
V_45 -> V_58 = F_24 ( V_46 [ V_72 - V_68 ] & 0x3f ) ;
V_45 -> V_60 = F_24 ( V_46 [ V_73 - V_68 ] & 0x1f ) - 1 ;
V_45 -> V_62 = F_24 ( V_46 [ V_74 - V_68 ] & 0x7f ) + 100 ;
V_45 -> V_64 = F_24 ( V_46 [ V_75 - V_68 ] & 0x07 ) - 1 ;
V_67 -> V_76 = ! ! ( V_36 & V_41 ) ;
V_67 -> V_77 = ( V_35 & V_40 ) && V_67 -> V_76 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_78 )
{
int V_13 ;
T_1 V_36 ;
V_13 = F_1 ( V_2 , V_37 , & V_36 , 1 ) ;
if ( V_13 < 0 ) {
F_20 ( V_2 , L_4 , V_13 ) ;
return V_13 ;
}
if ( V_78 )
V_36 |= V_41 ;
else
V_36 &= ~ V_41 ;
V_13 = F_4 ( V_2 , V_37 , & V_36 , 1 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_9 ) ;
return V_13 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_44 * const V_45 = & V_67 -> time ;
int V_13 ;
T_1 V_46 [ 8 ] ;
if ( V_45 -> V_62 < 100 )
return - V_9 ;
V_13 = F_7 ( V_2 , V_46 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_6 , V_48 ) ;
return - V_15 ;
}
V_46 [ V_68 - V_68 ] = F_28 ( V_45 -> V_50 ) | V_79 ;
V_46 [ V_70 - V_68 ] = F_28 ( V_45 -> V_51 ) | V_79 ;
V_46 [ V_71 - V_68 ] = ( F_28 ( V_45 -> V_56 ) & 0x3f )
| V_79 ;
V_46 [ V_72 - V_68 ] = ( F_28 ( V_45 -> V_58 ) & 0x3f )
| V_79 ;
V_46 [ V_73 - V_68 ] = ( F_28 ( V_45 -> V_60 + 1 ) & 0x1f )
| V_79 ;
V_46 [ V_75 - V_68 ] = ( F_28 ( V_45 -> V_64 + 1 ) & 0x7 )
| V_79 ;
V_46 [ V_74 - V_68 ] = ( F_28 ( V_45 -> V_62 - 100 ) )
| V_79 ;
V_13 = F_4 ( V_2 , V_68 , V_46 ,
V_69 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_67 -> V_76 ) {
V_13 = F_26 ( V_2 , 1 ) ;
if ( V_13 )
return V_13 ;
} else {
V_13 = F_26 ( V_2 , 0 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
T_1 V_46 [ 8 ] ;
int V_13 ;
if ( V_45 -> V_62 < 100 )
return - V_9 ;
V_46 [ V_49 - V_49 ] = F_28 ( V_45 -> V_50 ) ;
V_46 [ V_52 - V_49 ] = F_28 ( V_45 -> V_51 ) ;
V_46 [ V_54 - V_49 ] = F_28 ( V_45 -> V_56 ) ;
V_46 [ V_59 - V_49 ] = F_28 ( V_45 -> V_58 ) ;
V_46 [ V_61 - V_49 ] = F_28 ( V_45 -> V_60 + 1 ) ;
V_46 [ V_65 - V_49 ] = F_28 ( V_45 -> V_64 + 1 ) & 0x7 ;
V_46 [ V_63 - V_49 ] = F_28 ( V_45 -> V_62 - 100 ) ;
V_13 = F_4 ( V_2 , V_49 , V_46 ,
V_47 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_2 , V_46 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_6 , V_48 ) ;
return V_13 ;
}
V_13 = F_9 ( V_2 , ( V_46 [ 0 ] & ~ V_80 ) ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 , L_6 , V_48 ) ;
return V_13 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
const struct V_83 * V_84 ;
int V_18 , V_26 ;
T_4 V_85 ;
T_1 V_86 ;
if ( ! V_82 )
return;
V_26 = F_31 ( V_82 , L_10 , & V_85 ) ;
if ( V_26 ) {
V_86 = 0 ;
} else {
for ( V_18 = 0 ; V_18 < F_32 ( V_87 ) ; V_18 ++ ) {
V_84 = & V_87 [ V_18 ] ;
if ( V_84 -> V_88 >= V_85 )
break;
}
V_86 = V_84 -> V_89 ;
F_33 ( V_2 ,
L_11 ,
V_84 -> V_88 ) ;
}
V_26 = F_17 ( V_2 , V_90 ,
V_91 ,
V_86 ) ;
if ( V_26 < 0 )
F_12 ( V_2 , L_12 ) ;
}
static int F_34 ( struct V_1 * V_2 , int * V_92 )
{
int V_13 ;
T_1 V_93 ;
V_13 = F_1 ( V_2 , V_94 , & V_93 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_92 = ( ( int ) V_93 - 60 ) * 1000 ;
return 0 ;
}
static T_5 F_35 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
char * V_4 )
{
int V_13 , V_92 ;
V_13 = F_34 ( V_2 , & V_92 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_4 , L_13 , V_92 ) ;
}
static T_5 F_36 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
const char * V_4 ,
T_2 V_97 )
{
unsigned long V_98 ;
int V_13 ;
T_1 V_99 = 0 ;
V_13 = F_37 ( V_4 , 10 , & V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_98 != 0 ) {
V_99 |= V_100 ;
if ( V_98 >= 16000 )
V_99 |= V_101 ;
}
V_13 = F_17 ( V_2 , V_90 ,
V_100 | V_101 ,
V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_97 ;
}
static T_5 F_38 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
char * V_4 )
{
int V_13 , V_98 ;
T_1 V_102 ;
V_13 = F_15 ( V_2 , V_90 ,
& V_102 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_102 & V_100 ) {
if ( V_102 & V_101 )
V_98 = 16000 ;
else
V_98 = 1000 ;
} else {
V_98 = 0 ;
}
return sprintf ( V_4 , L_13 , V_98 ) ;
}
static void F_39 ( struct V_1 * V_2 , const char * V_103 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_1 * V_104 ;
V_104 = F_40 ( V_2 , V_103 , V_7 ,
V_105 ) ;
if ( F_41 ( V_104 ) ) {
F_20 ( V_2 , L_14 ,
F_42 ( V_104 ) ) ;
}
}
static void F_39 ( struct V_1 * V_2 , const char * V_103 )
{
}
static int F_43 ( struct V_1 * V_2 , struct V_10 * V_10 , int V_28 ,
const char * V_103 )
{
struct V_6 * V_7 ;
int V_106 = 0 ;
T_1 V_4 [ 1 ] ;
V_7 = F_44 ( V_2 , sizeof( * V_7 ) , V_107 ) ;
if ( ! V_7 )
return - V_108 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_2 = V_2 ;
F_45 ( V_2 , V_7 ) ;
V_106 = F_7 ( V_2 , V_4 ) ;
if ( V_106 < 0 ) {
F_12 ( V_2 , L_15 ) ;
return V_106 ;
}
F_30 ( V_2 ) ;
F_39 ( V_2 , V_103 ) ;
V_7 -> V_32 = F_46 ( V_2 , V_103 , & V_109 ,
V_110 ) ;
if ( F_41 ( V_7 -> V_32 ) ) {
F_12 ( V_2 , L_16 ) ;
return F_42 ( V_7 -> V_32 ) ;
}
if ( V_7 -> V_28 > 0 ) {
V_106 = F_47 ( V_2 , V_7 -> V_28 ,
NULL , F_18 ,
V_111 | V_112 ,
L_17 , V_2 ) ;
if ( V_106 ) {
F_20 ( V_2 , L_18 ) ;
V_7 -> V_28 = 0 ;
} else {
V_109 . V_113 = F_25 ;
V_109 . V_114 = F_27 ;
V_109 . V_115 = F_26 ;
}
}
return 0 ;
}
static int F_48 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
struct V_10 * V_10 ;
static const struct V_120 V_121 = {
. V_122 = 8 ,
. V_123 = 8 ,
} ;
if ( ! F_49 ( V_117 -> V_124 , V_125 |
V_126 ) ) {
F_12 ( & V_117 -> V_2 , L_19 ) ;
return - V_25 ;
}
V_10 = F_50 ( V_117 , & V_121 ) ;
if ( F_41 ( V_10 ) ) {
F_12 ( & V_117 -> V_2 , L_20 ,
V_48 , F_42 ( V_10 ) ) ;
return F_42 ( V_10 ) ;
}
return F_43 ( & V_117 -> V_2 , V_10 , V_117 -> V_28 , V_117 -> V_103 ) ;
}
static int F_51 ( void )
{
return F_52 ( & V_127 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_127 ) ;
}
static int F_51 ( void )
{
return 0 ;
}
static void F_53 ( void )
{
}
static int F_55 ( struct V_128 * V_129 )
{
static const struct V_120 V_121 = {
. V_122 = 8 ,
. V_123 = 8 ,
} ;
struct V_10 * V_10 ;
V_10 = F_56 ( V_129 , & V_121 ) ;
if ( F_41 ( V_10 ) ) {
F_12 ( & V_129 -> V_2 , L_20 ,
V_48 , F_42 ( V_10 ) ) ;
return F_42 ( V_10 ) ;
}
return F_43 ( & V_129 -> V_2 , V_10 , V_129 -> V_28 , L_21 ) ;
}
static int F_57 ( void )
{
return F_58 ( & V_130 ) ;
}
static void F_59 ( void )
{
F_60 ( & V_130 ) ;
}
static int F_57 ( void )
{
return 0 ;
}
static void F_59 ( void )
{
}
static int T_6 F_61 ( void )
{
int V_13 ;
V_13 = F_51 () ;
if ( V_13 ) {
F_62 ( L_22 , V_13 ) ;
return V_13 ;
}
V_13 = F_57 () ;
if ( V_13 ) {
F_62 ( L_23 , V_13 ) ;
F_53 () ;
}
return V_13 ;
}
static void T_7 F_63 ( void )
{
F_59 () ;
F_53 () ;
}
