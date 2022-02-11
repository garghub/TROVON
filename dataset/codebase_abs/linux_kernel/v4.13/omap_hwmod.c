static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( 1 , L_1 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_7 = F_3 ( V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
if ( ! ( V_2 -> V_3 -> V_4 -> V_9 & V_10 ) )
V_2 -> V_11 |= V_12 ;
return 0 ;
}
static void F_4 ( T_1 V_13 , struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( 1 , L_2 , V_2 -> V_5 ) ;
return;
}
V_2 -> V_7 = V_13 ;
if ( V_2 -> V_3 -> V_14 )
V_2 -> V_3 -> V_14 ( V_2 ) ;
F_5 ( V_13 , V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
if ( V_2 -> V_3 -> V_15 )
V_2 -> V_3 -> V_15 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_16 ,
T_1 * V_13 )
{
T_1 V_17 ;
T_2 V_18 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_19 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_18 = V_2 -> V_3 -> V_4 -> V_20 -> V_21 ;
V_17 = ( 0x3 << V_18 ) ;
* V_13 &= ~ V_17 ;
* V_13 |= F_7 ( V_16 ) << V_18 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_22 , T_1 * V_13 )
{
T_1 V_23 ;
T_2 V_24 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_25 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_24 = V_2 -> V_3 -> V_4 -> V_20 -> V_24 ;
V_23 = ( 0x3 << V_24 ) ;
* V_13 &= ~ V_23 ;
* V_13 |= F_7 ( V_22 ) << V_24 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_26 , T_1 * V_13 )
{
T_1 V_27 ;
T_2 V_28 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_29 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_28 = V_2 -> V_3 -> V_4 -> V_20 -> V_28 ;
V_27 = ( 0x3 << V_28 ) ;
* V_13 &= ~ V_27 ;
* V_13 |= V_26 << V_28 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_30 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_31 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_30 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_20 -> V_32 ) ;
* V_13 |= V_30 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_30 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_31 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 ,
L_4 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
V_30 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_20 -> V_32 ) ;
* V_13 &= ~ V_30 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_33 * V_4 ;
T_1 V_30 ;
int V_34 = 0 ;
V_4 = V_2 -> V_3 -> V_4 ;
if ( V_4 -> V_9 & V_35 )
F_13 ( ( F_3 ( V_2 , V_4 -> V_36 )
& V_37 ) ,
V_38 , V_34 ) ;
else if ( V_4 -> V_9 & V_39 ) {
V_30 = ( 0x1 << V_4 -> V_20 -> V_32 ) ;
F_13 ( ! ( F_3 ( V_2 , V_4 -> V_8 )
& V_30 ) ,
V_38 , V_34 ) ;
}
return V_34 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_1 V_40 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_41 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_42 != V_43 ) {
F_15 ( L_5 , V_2 -> V_5 ) ;
return - V_6 ;
}
F_16 ( L_6 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_40 =
( 0x1 << V_2 -> V_3 -> V_4 -> V_20 -> V_44 ) ;
V_13 |= V_40 ;
F_4 ( V_13 , V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_45 ,
T_1 * V_13 )
{
T_1 V_46 ;
T_2 V_47 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_48 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_47 = V_2 -> V_3 -> V_4 -> V_20 -> V_47 ;
V_46 = ( 0x1 << V_47 ) ;
* V_13 &= ~ V_46 ;
* V_13 |= V_45 << V_47 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ||
( V_2 -> V_3 -> V_4 -> V_50 & V_51 ) ||
( V_2 -> V_3 -> V_4 -> V_50 & V_52 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_49 )
* V_13 |= 0x1 << V_2 -> V_3 -> V_4 -> V_20 -> V_53 ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
F_8 ( V_2 , V_54 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_52 )
F_6 ( V_2 , V_54 , V_13 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ||
( V_2 -> V_3 -> V_4 -> V_50 & V_51 ) ||
( V_2 -> V_3 -> V_4 -> V_50 & V_52 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_20 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_49 )
* V_13 &= ~ ( 0x1 << V_2 -> V_3 -> V_4 -> V_20 -> V_53 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
F_8 ( V_2 , V_55 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_52 )
F_6 ( V_2 , V_55 , V_13 ) ;
return 0 ;
}
static struct V_56 * F_20 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
if ( V_2 -> V_59 ) {
return V_2 -> V_59 ;
} else if ( V_2 -> V_60 ) {
if ( F_21 ( V_2 -> V_60 ) & V_61 )
return NULL ;
V_58 = F_22 ( F_23 ( V_2 -> V_60 ) ) ;
return V_58 -> V_59 ;
}
return NULL ;
}
static int F_24 ( struct V_1 * V_2 , struct V_1 * V_62 )
{
struct V_56 * V_59 , * V_63 ;
V_59 = F_20 ( V_2 ) ;
V_63 = F_20 ( V_62 ) ;
if ( ! V_59 || ! V_63 )
return - V_6 ;
if ( V_59 && V_59 -> V_64 & V_65 )
return 0 ;
return F_25 ( V_59 , V_63 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_1 * V_62 )
{
struct V_56 * V_59 , * V_63 ;
V_59 = F_20 ( V_2 ) ;
V_63 = F_20 ( V_62 ) ;
if ( ! V_59 || ! V_63 )
return - V_6 ;
if ( V_59 && V_59 -> V_64 & V_65 )
return 0 ;
return F_27 ( V_59 , V_63 ) ;
}
static int F_28 ( struct V_56 * V_59 , void * V_66 )
{
struct V_67 * V_68 = V_66 ;
if ( F_29 ( V_59 ) == V_68 -> V_69 ) {
F_16 ( L_7 , V_70 ,
V_59 -> V_5 , V_68 -> V_69 ,
V_68 -> V_71 -> V_72 -> V_5 ) ;
V_68 -> V_59 = V_59 ;
return - 1 ;
}
return 0 ;
}
static int F_30 ( struct V_73 * V_74 )
{
const T_3 * V_75 ;
struct V_67 * V_68 ;
V_68 = F_31 ( sizeof( * V_68 ) , 0 ) ;
if ( ! V_68 )
return - V_76 ;
V_75 = F_32 ( V_74 , 0 , NULL , NULL ) ;
V_68 -> V_69 = ( T_1 ) F_33 ( V_74 , V_75 ) ;
V_68 -> V_77 = V_68 -> V_69 & 0xff ;
V_68 -> V_69 &= ~ 0xff ;
V_68 -> V_71 = V_74 ;
F_34 ( F_28 , V_68 ) ;
if ( ! V_68 -> V_59 ) {
F_35 ( L_8 ,
V_70 , V_74 -> V_72 -> V_5 , V_68 -> V_69 ) ;
F_36 ( F_37 ( V_68 ) , sizeof( * V_68 ) ) ;
return - V_6 ;
}
F_38 ( & V_68 -> V_78 , & V_79 ) ;
return 0 ;
}
static int F_39 ( void )
{
struct V_73 * V_74 ;
int V_80 = 0 ;
F_40 (np, ti_clkctrl_match_table) {
V_80 = F_30 ( V_74 ) ;
if ( V_80 )
break;
}
return V_80 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
return V_2 -> V_81 . V_82 . V_83 -
V_68 -> V_77 - V_68 -> V_59 -> V_84 ;
}
static struct V_58 * F_42 ( struct V_1 * V_2 )
{
struct V_67 * V_68 ;
struct V_58 * V_58 ;
if ( ! V_85 . V_86 )
return NULL ;
F_43 (provider, &clkctrl_providers, link) {
if ( V_68 -> V_59 == V_2 -> V_59 ) {
struct V_87 V_88 ;
V_88 . V_74 = V_68 -> V_71 ;
V_88 . V_89 = 2 ;
V_88 . args [ 0 ] = V_85 . V_86 ( V_2 , V_68 ) ;
V_88 . args [ 1 ] = 0 ;
V_58 = F_44 ( & V_88 ) ;
return V_58 ;
}
}
return NULL ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_80 = 0 ;
struct V_58 * V_58 = NULL ;
V_58 = F_42 ( V_2 ) ;
if ( ! F_46 ( V_58 ) ) {
F_16 ( L_9 , V_70 ,
F_47 ( V_58 ) , V_2 -> V_5 ) ;
V_2 -> V_90 = F_47 ( V_58 ) ;
V_2 -> V_60 = V_58 ;
V_85 . V_91 ( V_2 ) ;
} else {
if ( ! V_2 -> V_90 )
return 0 ;
V_2 -> V_60 = F_48 ( NULL , V_2 -> V_90 ) ;
}
if ( F_49 ( V_2 -> V_60 ) ) {
F_15 ( L_10 ,
V_2 -> V_5 , V_2 -> V_90 ) ;
return - V_6 ;
}
F_50 ( V_2 -> V_60 ) ;
if ( ! F_20 ( V_2 ) )
F_16 ( L_11 ,
V_2 -> V_5 , V_2 -> V_90 ) ;
return V_80 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
struct V_58 * V_34 ;
int V_80 = 0 ;
F_43 (os, &oh->slave_ports, node) {
if ( ! V_93 -> V_58 )
continue;
V_34 = F_48 ( NULL , V_93 -> V_58 ) ;
if ( F_49 ( V_34 ) ) {
F_15 ( L_12 ,
V_2 -> V_5 , V_93 -> V_58 ) ;
V_80 = - V_6 ;
continue;
}
V_93 -> V_60 = V_34 ;
F_50 ( V_93 -> V_60 ) ;
}
return V_80 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_94 * V_95 ;
struct V_58 * V_34 ;
int V_96 ;
int V_80 = 0 ;
for ( V_96 = V_2 -> V_97 , V_95 = V_2 -> V_98 ; V_96 > 0 ; V_96 -- , V_95 ++ ) {
V_34 = F_48 ( NULL , V_95 -> V_58 ) ;
if ( F_49 ( V_34 ) ) {
F_15 ( L_13 ,
V_2 -> V_5 , V_95 -> V_58 ) ;
V_80 = - V_6 ;
continue;
}
V_95 -> V_60 = V_34 ;
F_50 ( V_95 -> V_60 ) ;
}
return V_80 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_94 * V_95 ;
int V_96 ;
F_16 ( L_14 , V_2 -> V_5 ) ;
for ( V_96 = V_2 -> V_97 , V_95 = V_2 -> V_98 ; V_96 > 0 ; V_96 -- , V_95 ++ )
if ( V_95 -> V_60 ) {
F_16 ( L_15 , V_95 -> V_99 ,
F_47 ( V_95 -> V_60 ) ) ;
F_54 ( V_95 -> V_60 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_94 * V_95 ;
int V_96 ;
F_16 ( L_16 , V_2 -> V_5 ) ;
for ( V_96 = V_2 -> V_97 , V_95 = V_2 -> V_98 ; V_96 > 0 ; V_96 -- , V_95 ++ )
if ( V_95 -> V_60 ) {
F_16 ( L_17 , V_95 -> V_99 ,
F_47 ( V_95 -> V_60 ) ) ;
F_56 ( V_95 -> V_60 ) ;
}
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
F_16 ( L_18 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_54 ( V_2 -> V_60 ) ;
F_43 (os, &oh->slave_ports, node) {
if ( V_93 -> V_60 && ( V_93 -> V_64 & V_100 ) )
F_54 ( V_93 -> V_60 ) ;
}
if ( V_2 -> V_64 & V_101 )
F_53 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
F_16 ( L_19 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_56 ( V_2 -> V_60 ) ;
F_43 (os, &oh->slave_ports, node) {
if ( V_93 -> V_60 && ( V_93 -> V_64 & V_100 ) )
F_56 ( V_93 -> V_60 ) ;
}
if ( V_2 -> V_64 & V_101 )
F_55 ( V_2 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 || ! V_2 -> V_81 . V_82 . V_102 )
return;
F_16 ( L_20 ,
V_2 -> V_5 , V_70 , V_2 -> V_81 . V_82 . V_102 ) ;
F_60 ( V_2 -> V_81 . V_82 . V_102 ,
V_2 -> V_59 -> V_103 ,
V_2 -> V_59 -> V_104 , V_2 -> V_81 . V_82 . V_83 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_105 || ! V_2 -> V_59 )
return 0 ;
if ( V_2 -> V_64 & V_106 )
return 0 ;
if ( ! V_2 -> V_81 . V_82 . V_83 &&
! ( V_2 -> V_81 . V_82 . V_64 & V_107 ) )
return 0 ;
return F_62 ( V_2 -> V_59 -> V_103 ,
V_2 -> V_59 -> V_104 ,
V_2 -> V_81 . V_82 . V_83 , 0 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
int V_96 = 0 ;
if ( ! V_2 || ! V_2 -> V_110 )
return 0 ;
do {
V_109 = & V_2 -> V_110 [ V_96 ++ ] ;
} while ( V_109 -> V_111 != - 1 );
return V_96 - 1 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
int V_96 = 0 ;
if ( ! V_2 || ! V_2 -> V_114 )
return 0 ;
do {
V_113 = & V_2 -> V_114 [ V_96 ++ ] ;
} while ( V_113 -> V_115 != - 1 );
return V_96 - 1 ;
}
static int F_65 ( struct V_92 * V_93 )
{
struct V_116 * V_117 ;
int V_96 = 0 ;
if ( ! V_93 || ! V_93 -> V_69 )
return 0 ;
do {
V_117 = & V_93 -> V_69 [ V_96 ++ ] ;
} while ( V_117 -> V_118 != V_117 -> V_119 );
return V_96 - 1 ;
}
static int F_66 ( struct V_1 * V_2 , const char * V_5 ,
unsigned int * V_111 )
{
int V_96 ;
bool V_120 = false ;
if ( ! V_2 -> V_110 )
return - V_121 ;
V_96 = 0 ;
while ( V_2 -> V_110 [ V_96 ] . V_111 != - 1 ) {
if ( V_5 == V_2 -> V_110 [ V_96 ] . V_5 ||
! strcmp ( V_5 , V_2 -> V_110 [ V_96 ] . V_5 ) ) {
V_120 = true ;
break;
}
V_96 ++ ;
}
if ( ! V_120 )
return - V_121 ;
* V_111 = V_2 -> V_110 [ V_96 ] . V_111 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , const char * V_5 ,
unsigned int * V_122 )
{
int V_96 ;
bool V_120 = false ;
if ( ! V_2 -> V_114 )
return - V_121 ;
V_96 = 0 ;
while ( V_2 -> V_114 [ V_96 ] . V_115 != - 1 ) {
if ( V_5 == V_2 -> V_114 [ V_96 ] . V_5 ||
! strcmp ( V_5 , V_2 -> V_114 [ V_96 ] . V_5 ) ) {
V_120 = true ;
break;
}
V_96 ++ ;
}
if ( ! V_120 )
return - V_121 ;
* V_122 = V_2 -> V_114 [ V_96 ] . V_115 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , const char * V_5 ,
T_1 * V_118 , T_1 * V_119 )
{
int V_123 ;
struct V_92 * V_93 ;
bool V_120 = false ;
F_43 (os, &oh->slave_ports, node) {
if ( ! V_93 -> V_69 )
return - V_121 ;
V_123 = 0 ;
while ( V_93 -> V_69 [ V_123 ] . V_118 != V_93 -> V_69 [ V_123 ] . V_119 ) {
if ( V_5 == V_93 -> V_69 [ V_123 ] . V_5 ||
! strcmp ( V_5 , V_93 -> V_69 [ V_123 ] . V_5 ) ) {
V_120 = true ;
break;
}
V_123 ++ ;
}
if ( V_120 )
break;
}
if ( ! V_120 )
return - V_121 ;
* V_118 = V_93 -> V_69 [ V_123 ] . V_118 ;
* V_119 = V_93 -> V_69 [ V_123 ] . V_119 ;
return 0 ;
}
static void T_4 F_69 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = NULL ;
if ( ! V_2 )
return;
V_2 -> V_11 |= V_105 ;
F_43 (os, &oh->slave_ports, node) {
if ( V_93 -> V_66 & V_124 ) {
V_2 -> V_125 = V_93 ;
V_2 -> V_11 &= ~ V_105 ;
break;
}
}
return;
}
static struct V_92 * F_70 ( struct V_1 * V_2 )
{
if ( ! V_2 || V_2 -> V_11 & V_105 || V_2 -> V_126 == 0 )
return NULL ;
return V_2 -> V_125 ;
}
static struct V_116 * T_4 F_71 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
struct V_116 * V_117 ;
int V_120 = 0 , V_96 = 0 ;
V_93 = F_70 ( V_2 ) ;
if ( ! V_93 || ! V_93 -> V_69 )
return NULL ;
do {
V_117 = & V_93 -> V_69 [ V_96 ++ ] ;
if ( V_117 -> V_64 & V_127 )
V_120 = 1 ;
} while ( ! V_120 && V_117 -> V_118 != V_117 -> V_119 );
return ( V_120 ) ? V_117 : NULL ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_2 V_22 , V_128 ;
T_1 V_13 ;
bool V_129 ;
struct V_56 * V_59 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
if ( V_2 -> V_64 & V_130 )
F_53 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_64 & V_130 )
F_55 ( V_2 ) ;
V_13 = V_2 -> V_7 ;
V_128 = V_2 -> V_3 -> V_4 -> V_9 ;
V_59 = F_20 ( V_2 ) ;
if ( V_128 & V_25 ) {
if ( V_2 -> V_64 & V_131 ||
V_2 -> V_64 & V_132 ) {
V_22 = V_133 ;
} else {
if ( V_128 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
V_129 = ( V_59 && V_59 -> V_64 & V_134 ) ;
if ( V_129 && ! ( V_2 -> V_3 -> V_4 -> V_50 &
( V_135 | V_51 ) ) )
V_22 = V_136 ;
F_8 ( V_2 , V_22 , & V_13 ) ;
}
if ( V_128 & V_19 ) {
if ( V_2 -> V_64 & V_137 ) {
V_22 = V_136 ;
} else if ( V_2 -> V_64 & V_138 ) {
V_22 = V_133 ;
} else {
if ( V_128 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_52 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
F_6 ( V_2 , V_22 , & V_13 ) ;
}
if ( ( V_2 -> V_64 & V_139 ) &&
( V_128 & V_29 ) )
F_9 ( V_2 , V_140 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
if ( V_128 & V_48 ) {
V_22 = ( V_2 -> V_64 & V_141 ) ?
0 : 1 ;
F_17 ( V_2 , V_22 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
T_2 V_22 , V_128 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_128 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_128 & V_25 ) {
if ( V_2 -> V_64 & V_131 ) {
V_22 = V_136 ;
} else {
if ( V_128 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
F_8 ( V_2 , V_22 , & V_13 ) ;
}
if ( V_128 & V_19 ) {
if ( ( V_2 -> V_64 & V_138 ) ||
( V_2 -> V_64 & V_137 ) ) {
V_22 = V_136 ;
} else {
if ( V_128 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_52 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
F_6 ( V_2 , V_22 , & V_13 ) ;
}
if ( V_2 -> V_7 != V_13 )
F_4 ( V_13 , V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_128 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_128 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_128 & V_25 )
F_8 ( V_2 , V_136 , & V_13 ) ;
if ( V_128 & V_19 )
F_6 ( V_2 , V_136 , & V_13 ) ;
if ( V_128 & V_48 )
F_17 ( V_2 , 1 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static struct V_1 * F_75 ( const char * V_5 )
{
struct V_1 * V_2 , * V_142 ;
V_2 = NULL ;
F_43 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_5 , V_142 -> V_5 ) ) {
V_2 = V_142 ;
break;
}
}
return V_2 ;
}
static int F_76 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_143 ) {
F_16 ( L_21 , V_2 -> V_5 ) ;
return 0 ;
}
V_2 -> V_59 = F_77 ( V_2 -> V_143 ) ;
if ( ! V_2 -> V_59 ) {
F_15 ( L_22 ,
V_2 -> V_5 , V_2 -> V_143 ) ;
return 0 ;
}
F_16 ( L_23 ,
V_2 -> V_5 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
int V_80 = 0 ;
if ( V_2 -> V_42 != V_144 )
return 0 ;
F_16 ( L_24 , V_2 -> V_5 ) ;
if ( V_85 . V_63 )
V_80 |= V_85 . V_63 ( V_2 ) ;
V_80 |= F_45 ( V_2 ) ;
V_80 |= F_51 ( V_2 ) ;
V_80 |= F_52 ( V_2 ) ;
if ( ! V_80 )
V_2 -> V_42 = V_145 ;
else
F_15 ( L_25 , V_2 -> V_5 ) ;
return V_80 ;
}
static int F_79 ( struct V_1 * V_2 , const char * V_5 ,
struct V_146 * V_147 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_2 -> V_148 ; V_96 ++ ) {
const char * V_149 = V_2 -> V_150 [ V_96 ] . V_5 ;
if ( ! strcmp ( V_149 , V_5 ) ) {
V_147 -> V_151 = V_2 -> V_150 [ V_96 ] . V_151 ;
V_147 -> V_152 = V_2 -> V_150 [ V_96 ] . V_152 ;
F_16 ( L_26 ,
V_2 -> V_5 , V_70 , V_149 , V_147 -> V_151 ,
V_147 -> V_152 ) ;
return 0 ;
}
}
return - V_121 ;
}
static int F_80 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_146 V_147 ;
int V_80 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_85 . V_153 )
return - V_154 ;
V_80 = F_79 ( V_2 , V_5 , & V_147 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = V_85 . V_153 ( V_2 , & V_147 ) ;
return V_80 ;
}
static int F_81 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_146 V_147 ;
int V_80 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_85 . V_155 )
return - V_154 ;
V_80 = F_79 ( V_2 , V_5 , & V_147 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_2 -> V_59 ) {
F_82 ( V_2 -> V_59 ) ;
V_80 = F_83 ( V_2 -> V_59 , V_2 ) ;
if ( V_80 ) {
F_2 ( 1 , L_27 ,
V_2 -> V_5 , V_2 -> V_59 -> V_5 , V_80 ) ;
return V_80 ;
}
}
F_57 ( V_2 ) ;
if ( V_85 . V_156 )
V_85 . V_156 ( V_2 ) ;
V_80 = V_85 . V_155 ( V_2 , & V_147 ) ;
if ( V_85 . V_157 )
V_85 . V_157 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_80 == - V_158 )
F_15 ( L_28 , V_2 -> V_5 ) ;
if ( V_2 -> V_59 ) {
F_84 ( V_2 -> V_59 ) ;
F_85 ( V_2 -> V_59 , V_2 ) ;
}
return V_80 ;
}
static int F_86 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_146 V_147 ;
int V_80 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_85 . V_159 )
return - V_154 ;
V_80 = F_79 ( V_2 , V_5 , & V_147 ) ;
if ( V_80 < 0 )
return V_80 ;
return V_85 . V_159 ( V_2 , & V_147 ) ;
}
static bool F_87 ( struct V_1 * V_2 )
{
int V_96 , V_160 = 0 ;
if ( V_2 -> V_148 == 0 )
return false ;
for ( V_96 = 0 ; V_96 < V_2 -> V_148 ; V_96 ++ )
if ( F_86 ( V_2 , V_2 -> V_150 [ V_96 ] . V_5 ) > 0 )
V_160 ++ ;
if ( V_2 -> V_148 == V_160 )
return true ;
return false ;
}
static bool F_88 ( struct V_1 * V_2 )
{
int V_160 = 0 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_2 -> V_148 && V_160 == 0 ; V_96 ++ )
if ( F_86 ( V_2 , V_2 -> V_150 [ V_96 ] . V_5 ) > 0 )
V_160 ++ ;
return ( V_160 ) ? true : false ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! V_2 -> V_59 || ! V_2 -> V_81 . V_82 . V_102 )
return - V_6 ;
if ( F_88 ( V_2 ) )
return 0 ;
F_16 ( L_29 , V_2 -> V_5 , V_70 ) ;
F_90 ( V_2 -> V_59 -> V_103 , V_2 -> V_59 -> V_104 ,
V_2 -> V_81 . V_82 . V_83 ) ;
V_13 = F_61 ( V_2 ) ;
if ( V_13 )
F_15 ( L_30 ,
V_2 -> V_5 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_34 = 0 ;
int V_80 = 0 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_31 ) )
return - V_121 ;
if ( V_2 -> V_42 != V_43 ) {
F_15 ( L_31 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_64 & V_130 )
F_53 ( V_2 ) ;
F_16 ( L_32 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_80 = F_10 ( V_2 , & V_13 ) ;
if ( V_80 )
goto V_161;
F_4 ( V_13 , V_2 ) ;
if ( V_2 -> V_3 -> V_4 -> V_162 )
F_92 ( V_2 -> V_3 -> V_4 -> V_162 ) ;
V_34 = F_12 ( V_2 ) ;
if ( V_34 == V_38 ) {
F_15 ( L_33 ,
V_2 -> V_5 , V_38 ) ;
V_80 = - V_163 ;
goto V_161;
} else {
F_16 ( L_34 , V_2 -> V_5 , V_34 ) ;
}
V_80 = F_11 ( V_2 , & V_13 ) ;
if ( V_80 )
goto V_161;
F_4 ( V_13 , V_2 ) ;
V_161:
if ( V_2 -> V_64 & V_130 )
F_55 ( V_2 ) ;
return V_80 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_96 , V_164 ;
F_16 ( L_35 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_165 ) {
V_164 = V_2 -> V_3 -> V_165 ( V_2 ) ;
} else {
if ( V_2 -> V_148 > 0 ) {
for ( V_96 = 0 ; V_96 < V_2 -> V_148 ; V_96 ++ )
F_80 ( V_2 , V_2 -> V_150 [ V_96 ] . V_5 ) ;
return 0 ;
} else {
V_164 = F_91 ( V_2 ) ;
if ( V_164 == - V_121 )
V_164 = 0 ;
}
}
F_14 ( V_2 ) ;
if ( V_2 -> V_3 -> V_4 ) {
F_1 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_164 ;
}
static void F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 . V_82 . V_64 & V_166 )
return;
if ( ! F_95 ( V_2 -> V_59 -> V_167 . V_168 -> V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_170 ) )
return;
V_2 -> V_81 . V_82 . V_171 ++ ;
F_96 ( V_2 -> V_59 -> V_167 . V_168 -> V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_170 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
return V_2 -> V_81 . V_82 . V_171 ;
}
static int F_98 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_172 )
return 0 ;
return V_2 -> V_3 -> V_172 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_164 ;
F_16 ( L_36 , V_2 -> V_5 ) ;
if ( V_2 -> V_11 & V_173 ) {
V_2 -> V_11 &= ~ V_173 ;
return 0 ;
}
if ( V_2 -> V_42 != V_174 &&
V_2 -> V_42 != V_175 &&
V_2 -> V_42 != V_176 ) {
F_2 ( 1 , L_37 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( F_87 ( V_2 ) )
return 0 ;
F_24 ( V_2 , V_177 ) ;
if ( V_2 -> V_59 ) {
F_82 ( V_2 -> V_59 ) ;
V_164 = F_83 ( V_2 -> V_59 , V_2 ) ;
if ( V_164 ) {
F_2 ( 1 , L_27 ,
V_2 -> V_5 , V_2 -> V_59 -> V_5 , V_164 ) ;
return V_164 ;
}
}
F_57 ( V_2 ) ;
if ( V_85 . V_156 )
V_85 . V_156 ( V_2 ) ;
if ( V_2 -> V_64 & V_178 )
F_100 ( true ) ;
if ( V_85 . V_179 )
V_85 . V_179 ( V_2 ) ;
V_164 = ( V_85 . V_180 ) ? V_85 . V_180 ( V_2 ) :
- V_6 ;
if ( V_2 -> V_59 && ! ( V_2 -> V_64 & V_181 ) )
F_84 ( V_2 -> V_59 ) ;
if ( ! V_164 ) {
V_2 -> V_42 = V_43 ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_1 ( V_2 ) ;
F_72 ( V_2 ) ;
}
V_164 = F_98 ( V_2 ) ;
} else {
if ( V_85 . V_157 )
V_85 . V_157 ( V_2 ) ;
F_58 ( V_2 ) ;
F_35 ( L_38 ,
V_2 -> V_5 , V_164 ) ;
if ( V_2 -> V_59 )
F_85 ( V_2 -> V_59 , V_2 ) ;
}
return V_164 ;
}
static int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 & V_182 ) {
V_2 -> V_11 |= V_173 ;
return 0 ;
}
F_16 ( L_39 , V_2 -> V_5 ) ;
if ( F_87 ( V_2 ) )
return 0 ;
if ( V_2 -> V_42 != V_43 ) {
F_2 ( 1 , L_40 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 )
F_73 ( V_2 ) ;
F_26 ( V_2 , V_177 ) ;
if ( V_2 -> V_59 && ! ( V_2 -> V_64 & V_181 ) )
F_82 ( V_2 -> V_59 ) ;
if ( V_2 -> V_64 & V_178 )
F_100 ( false ) ;
if ( V_85 . V_157 )
V_85 . V_157 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_59 ) {
F_84 ( V_2 -> V_59 ) ;
F_85 ( V_2 -> V_59 , V_2 ) ;
}
V_2 -> V_42 = V_175 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_80 , V_96 ;
T_2 V_183 ;
if ( F_87 ( V_2 ) )
return 0 ;
if ( V_2 -> V_42 != V_175 &&
V_2 -> V_42 != V_43 ) {
F_2 ( 1 , L_41 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
F_16 ( L_42 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_184 ) {
V_183 = V_2 -> V_42 ;
if ( V_2 -> V_42 == V_175 )
F_99 ( V_2 ) ;
V_80 = V_2 -> V_3 -> V_184 ( V_2 ) ;
if ( V_80 ) {
if ( V_183 == V_175 )
F_101 ( V_2 ) ;
return V_80 ;
}
}
if ( V_2 -> V_3 -> V_4 ) {
if ( V_2 -> V_42 == V_175 )
F_99 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_2 -> V_42 == V_43 ) {
F_26 ( V_2 , V_177 ) ;
if ( V_2 -> V_64 & V_178 )
F_100 ( false ) ;
if ( V_85 . V_157 )
V_85 . V_157 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_59 )
F_85 ( V_2 -> V_59 , V_2 ) ;
}
for ( V_96 = 0 ; V_96 < V_2 -> V_148 ; V_96 ++ )
F_80 ( V_2 , V_2 -> V_150 [ V_96 ] . V_5 ) ;
V_2 -> V_42 = V_176 ;
return 0 ;
}
static int F_103 ( struct V_73 * V_74 ,
struct V_1 * V_2 )
{
int V_185 , V_96 , V_186 ;
const char * V_187 ;
V_185 = F_104 ( V_74 , L_43 ) ;
if ( V_185 < 1 )
return - V_188 ;
for ( V_96 = 0 ; V_96 < V_185 ; V_96 ++ ) {
V_186 = F_105 ( V_74 , L_43 ,
V_96 , & V_187 ) ;
if ( V_186 )
continue;
if ( ! strcmp ( V_187 , V_2 -> V_5 ) ) {
F_16 ( L_44 ,
V_74 -> V_5 , V_96 , V_2 -> V_5 ) ;
return V_96 ;
}
}
return - V_188 ;
}
static int F_106 ( struct V_73 * V_74 ,
struct V_1 * V_2 ,
int * V_189 ,
struct V_73 * * V_120 )
{
struct V_73 * V_190 = NULL ;
int V_186 ;
V_186 = F_103 ( V_74 , V_2 ) ;
if ( V_186 >= 0 ) {
* V_120 = V_74 ;
* V_189 = V_186 ;
return 0 ;
}
F_107 (np, np0) {
struct V_73 * V_191 ;
int V_96 ;
V_186 = F_106 ( V_190 , V_2 , & V_96 , & V_191 ) ;
if ( V_186 == 0 ) {
* V_120 = V_191 ;
* V_189 = V_96 ;
return 0 ;
}
}
* V_120 = NULL ;
* V_189 = 0 ;
return - V_188 ;
}
static int T_4 F_108 ( struct V_1 * V_2 , void * V_192 ,
int V_189 , struct V_73 * V_74 )
{
struct V_116 * V_117 ;
void T_5 * va_start = NULL ;
if ( ! V_2 )
return - V_6 ;
F_69 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
return 0 ;
if ( V_2 -> V_11 & V_105 )
return - V_193 ;
V_117 = F_71 ( V_2 ) ;
if ( ! V_117 ) {
F_16 ( L_45 ,
V_2 -> V_5 ) ;
if ( ! V_74 ) {
F_35 ( L_46 , V_2 -> V_5 ) ;
return - V_193 ;
}
va_start = F_109 ( V_74 , V_189 + V_2 -> V_194 ) ;
} else {
va_start = F_110 ( V_117 -> V_118 , V_117 -> V_119 - V_117 -> V_118 ) ;
}
if ( ! va_start ) {
if ( V_117 )
F_35 ( L_47 , V_2 -> V_5 ) ;
else
F_35 ( L_48 ,
V_2 -> V_5 , V_189 , V_74 -> V_195 ) ;
return - V_193 ;
}
F_16 ( L_49 ,
V_2 -> V_5 , va_start ) ;
V_2 -> V_196 = va_start ;
return 0 ;
}
static int T_4 F_111 ( struct V_1 * V_2 , void * V_192 )
{
int V_164 , V_189 ;
struct V_73 * V_74 = NULL ;
struct V_73 * V_197 ;
if ( V_2 -> V_42 != V_144 )
return 0 ;
V_197 = F_112 ( NULL , L_50 ) ;
if ( ! V_197 )
return - V_188 ;
V_164 = F_106 ( V_197 , V_2 , & V_189 , & V_74 ) ;
if ( V_164 )
F_16 ( L_51 , V_2 -> V_5 ) ;
else if ( V_74 && V_189 )
F_15 ( L_52 ,
V_2 -> V_5 , V_74 -> V_5 ) ;
V_164 = F_108 ( V_2 , NULL , V_189 , V_74 ) ;
if ( V_164 < 0 ) {
F_2 ( 1 , L_53 ,
V_2 -> V_5 ) ;
return 0 ;
}
V_164 = F_78 ( V_2 , V_74 ) ;
if ( V_164 < 0 ) {
F_2 ( 1 , L_54 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_74 ) {
if ( F_113 ( V_74 , L_55 , NULL ) )
V_2 -> V_64 |= V_198 ;
if ( F_113 ( V_74 , L_56 , NULL ) )
V_2 -> V_64 |= V_199 ;
if ( F_113 ( V_74 , L_57 , NULL ) )
V_2 -> V_64 |= V_182 ;
}
V_2 -> V_42 = V_174 ;
return 0 ;
}
static void T_4 F_114 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
if ( V_2 -> V_42 != V_174 )
return;
F_43 (os, &oh->slave_ports, node) {
if ( ! V_93 -> V_60 )
continue;
if ( V_93 -> V_64 & V_100 ) {
} else {
F_54 ( V_93 -> V_60 ) ;
}
}
return;
}
static int T_4 F_115 ( struct V_1 * V_2 )
{
int V_164 ;
if ( V_2 -> V_42 != V_174 )
return - V_6 ;
if ( V_2 -> V_64 & V_200 )
return - V_201 ;
if ( V_2 -> V_148 == 0 ) {
V_164 = F_99 ( V_2 ) ;
if ( V_164 ) {
F_15 ( L_58 ,
V_2 -> V_5 , V_2 -> V_42 ) ;
return - V_6 ;
}
}
if ( ! ( V_2 -> V_64 & V_198 ) )
V_164 = F_93 ( V_2 ) ;
return V_164 ;
}
static void T_4 F_116 ( struct V_1 * V_2 )
{
T_2 V_202 ;
if ( V_2 -> V_148 > 0 )
return;
V_202 = V_2 -> V_203 ;
if ( V_202 == V_204 )
V_202 = V_43 ;
if ( ( V_2 -> V_64 & ( V_199 | V_182 ) ) &&
( V_202 == V_175 ) ) {
V_2 -> V_11 |= V_173 ;
V_202 = V_43 ;
}
if ( V_202 == V_175 )
F_101 ( V_2 ) ;
else if ( V_202 == V_176 )
F_102 ( V_2 ) ;
else if ( V_202 != V_43 )
F_2 ( 1 , L_59 ,
V_2 -> V_5 , V_202 ) ;
return;
}
static int T_4 F_117 ( struct V_1 * V_2 , void * V_192 )
{
if ( V_2 -> V_42 != V_174 )
return 0 ;
if ( V_2 -> V_205 ) {
int V_164 ;
V_164 = F_99 ( V_2 -> V_205 ) ;
F_2 ( V_164 , L_60 ,
V_2 -> V_5 , V_2 -> V_205 -> V_5 ) ;
}
F_114 ( V_2 ) ;
if ( ! F_115 ( V_2 ) )
F_116 ( V_2 ) ;
if ( V_2 -> V_205 ) {
T_2 V_202 ;
V_202 = V_2 -> V_205 -> V_203 ;
if ( V_202 == V_175 )
F_101 ( V_2 -> V_205 ) ;
else if ( V_202 == V_176 )
F_102 ( V_2 -> V_205 ) ;
else if ( V_202 != V_43 )
F_2 ( 1 , L_59 ,
V_2 -> V_205 -> V_5 , V_202 ) ;
}
return 0 ;
}
static int T_4 F_118 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_5 || ! V_2 -> V_3 || ! V_2 -> V_3 -> V_5 ||
( V_2 -> V_42 != V_204 ) )
return - V_6 ;
F_16 ( L_61 , V_2 -> V_5 ) ;
if ( F_75 ( V_2 -> V_5 ) )
return - V_206 ;
F_119 ( & V_2 -> V_71 , & V_207 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_121 ( & V_2 -> V_209 ) ;
F_122 ( & V_2 -> V_209 , & V_2 -> V_210 ) ;
V_2 -> V_42 = V_144 ;
if ( ! strcmp ( V_2 -> V_5 , V_211 ) )
V_177 = V_2 ;
return 0 ;
}
static int T_4 F_123 ( struct V_92 * V_212 )
{
F_16 ( L_62 , V_212 -> V_213 -> V_5 ,
V_212 -> V_214 -> V_5 ) ;
F_38 ( & V_212 -> V_71 , & V_212 -> V_214 -> V_208 ) ;
V_212 -> V_214 -> V_126 ++ ;
return 0 ;
}
static int T_4 F_124 ( struct V_92 * V_212 )
{
if ( ! V_212 || ! V_212 -> V_213 || ! V_212 -> V_214 || ! V_212 -> V_66 )
return - V_6 ;
if ( V_212 -> V_11 & V_215 )
return - V_206 ;
F_16 ( L_63 ,
V_212 -> V_213 -> V_5 , V_212 -> V_214 -> V_5 ) ;
if ( V_212 -> V_213 -> V_42 != V_144 )
F_118 ( V_212 -> V_213 ) ;
if ( V_212 -> V_214 -> V_42 != V_144 )
F_118 ( V_212 -> V_214 ) ;
F_123 ( V_212 ) ;
V_212 -> V_11 |= V_215 ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_64 & V_106 )
return 0 ;
if ( ! F_70 ( V_2 ) )
return 0 ;
return F_126 ( 0 , V_2 -> V_81 . V_216 . V_217 ,
V_2 -> V_81 . V_216 . V_218 ,
V_2 -> V_81 . V_216 . V_219 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_64 & V_106 || ! V_2 -> V_59 )
return 0 ;
if ( ! F_70 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_81 . V_82 . V_83 &&
! ( V_2 -> V_81 . V_82 . V_64 & V_107 ) )
return 0 ;
return F_126 ( V_2 -> V_59 -> V_103 ,
V_2 -> V_59 -> V_104 ,
V_2 -> V_81 . V_82 . V_83 , 0 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
return F_129 ( V_147 -> V_151 , 0 ,
V_2 -> V_81 . V_216 . V_217 , 0 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
return F_131 ( V_147 -> V_151 , V_147 -> V_152 , 0 ,
V_2 -> V_81 . V_216 . V_217 , 0 , 0 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
return F_133 ( V_147 -> V_152 , 0 ,
V_2 -> V_81 . V_216 . V_217 , 0 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
return F_129 ( V_147 -> V_151 ,
V_2 -> V_59 -> V_167 . V_168 -> V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_220 ) ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
if ( V_147 -> V_152 )
F_35 ( L_64 ,
V_2 -> V_5 , V_147 -> V_5 ) ;
return F_131 ( V_147 -> V_151 , V_147 -> V_151 ,
V_2 -> V_59 -> V_167 . V_168 -> V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_220 ,
V_2 -> V_81 . V_82 . V_220 +
V_221 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
return F_133 ( V_147 -> V_151 ,
V_2 -> V_59 -> V_167 . V_168 ->
V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_220 ) ;
}
static int F_137 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
V_2 -> V_81 . V_82 . V_83 = 0 ;
V_2 -> V_81 . V_82 . V_102 = 0 ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
return F_131 ( V_147 -> V_151 , V_147 -> V_152 ,
V_2 -> V_59 -> V_167 . V_168 -> V_103 ,
V_2 -> V_59 -> V_167 . V_168 -> V_169 ,
V_2 -> V_81 . V_82 . V_220 ,
V_2 -> V_81 . V_82 . V_222 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , T_6 V_223 )
{
if ( V_2 -> V_64 & V_224 )
return F_139 ( V_2 -> V_196 + V_223 ) ;
else
return F_140 ( V_2 -> V_196 + V_223 ) ;
}
void F_5 ( T_1 V_13 , struct V_1 * V_2 , T_6 V_223 )
{
if ( V_2 -> V_64 & V_224 )
F_141 ( V_13 , V_2 -> V_196 + V_223 ) ;
else
F_142 ( V_13 , V_2 -> V_196 + V_223 ) ;
}
int F_143 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_80 ;
if ( ! V_2 || ! ( V_2 -> V_7 ) )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_80 = F_10 ( V_2 , & V_13 ) ;
if ( V_80 )
goto error;
F_4 ( V_13 , V_2 ) ;
V_80 = F_11 ( V_2 , & V_13 ) ;
if ( V_80 )
goto error;
F_4 ( V_13 , V_2 ) ;
error:
return V_80 ;
}
struct V_1 * F_144 ( const char * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return NULL ;
V_2 = F_75 ( V_5 ) ;
return V_2 ;
}
int F_145 ( int (* F_146)( struct V_1 * V_2 , void * V_192 ) ,
void * V_192 )
{
struct V_1 * V_142 ;
int V_80 = 0 ;
if ( ! F_146 )
return - V_6 ;
F_43 (temp_oh, &omap_hwmod_list, node) {
V_80 = (* F_146)( V_142 , V_192 ) ;
if ( V_80 )
break;
}
return V_80 ;
}
int T_4 F_147 ( struct V_92 * * V_225 )
{
int V_164 , V_96 ;
if ( ! V_226 )
return - V_6 ;
if ( ! V_225 )
return 0 ;
if ( V_225 [ 0 ] == NULL )
return 0 ;
V_96 = 0 ;
do {
V_164 = F_124 ( V_225 [ V_96 ] ) ;
F_2 ( V_164 && V_164 != - V_206 ,
L_65 ,
V_225 [ V_96 ] -> V_213 -> V_5 , V_225 [ V_96 ] -> V_214 -> V_5 , V_164 ) ;
} while ( V_225 [ ++ V_96 ] );
return 0 ;
}
static void T_4 F_148 ( struct V_1 * V_2 )
{
if ( ! V_177 || V_177 -> V_42 == V_204 )
F_35 ( L_66 ,
V_70 , V_211 ) ;
else if ( V_177 -> V_42 == V_144 && V_2 != V_177 )
F_149 ( V_211 ) ;
}
int T_4 F_149 ( const char * V_227 )
{
struct V_1 * V_2 ;
F_16 ( L_29 , V_227 , V_70 ) ;
V_2 = F_75 ( V_227 ) ;
if ( ! V_2 ) {
F_2 ( 1 , L_67 , V_227 ) ;
return - V_6 ;
}
F_148 ( V_2 ) ;
F_111 ( V_2 , NULL ) ;
F_117 ( V_2 , NULL ) ;
return 0 ;
}
static void T_4 F_150 ( void )
{
struct V_73 * V_74 ;
struct V_1 * V_2 ;
const char * V_228 ;
V_74 = F_151 ( L_68 ) ;
if ( V_74 ) {
V_228 = F_152 ( V_74 , L_69 , NULL ) ;
if ( V_228 ) {
V_74 = F_151 ( V_228 ) ;
if ( V_74 ) {
V_228 = F_152 ( V_74 , L_43 , NULL ) ;
V_2 = F_144 ( V_228 ) ;
if ( V_2 )
V_2 -> V_64 |= V_229 ;
}
}
}
}
static int T_4 F_153 ( void )
{
F_148 ( NULL ) ;
F_145 ( F_111 , NULL ) ;
#ifdef F_154
F_150 () ;
#endif
F_145 ( F_117 , NULL ) ;
return 0 ;
}
int F_155 ( struct V_1 * V_2 )
{
int V_164 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
V_164 = F_99 ( V_2 ) ;
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_164 ;
}
int F_158 ( struct V_1 * V_2 )
{
int V_164 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
V_164 = F_101 ( V_2 ) ;
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_164 ;
}
int F_159 ( struct V_1 * V_2 )
{
int V_164 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
V_164 = F_102 ( V_2 ) ;
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_164 ;
}
int F_160 ( struct V_1 * V_2 , unsigned long V_64 )
{
int V_80 = 0 ;
if ( V_64 & V_230 )
V_80 += F_63 ( V_2 ) ;
if ( V_64 & V_231 )
V_80 += F_64 ( V_2 ) ;
if ( V_64 & V_232 ) {
struct V_92 * V_93 ;
F_43 (os, &oh->slave_ports, node)
V_80 += F_65 ( V_93 ) ;
}
return V_80 ;
}
int F_161 ( struct V_1 * V_2 , struct V_233 * V_186 )
{
struct V_92 * V_93 ;
int V_96 , V_123 , V_234 , V_235 , V_236 ;
int V_164 = 0 ;
V_234 = F_63 ( V_2 ) ;
for ( V_96 = 0 ; V_96 < V_234 ; V_96 ++ ) {
unsigned int V_111 ;
if ( V_2 -> V_237 )
V_111 = V_2 -> V_237 ( ( V_2 -> V_110 + V_96 ) -> V_111 ) ;
else
V_111 = ( V_2 -> V_110 + V_96 ) -> V_111 ;
( V_186 + V_164 ) -> V_5 = ( V_2 -> V_110 + V_96 ) -> V_5 ;
( V_186 + V_164 ) -> V_238 = V_111 ;
( V_186 + V_164 ) -> V_239 = V_111 ;
( V_186 + V_164 ) -> V_64 = V_230 ;
V_164 ++ ;
}
V_235 = F_64 ( V_2 ) ;
for ( V_96 = 0 ; V_96 < V_235 ; V_96 ++ ) {
( V_186 + V_164 ) -> V_5 = ( V_2 -> V_114 + V_96 ) -> V_5 ;
( V_186 + V_164 ) -> V_238 = ( V_2 -> V_114 + V_96 ) -> V_115 ;
( V_186 + V_164 ) -> V_239 = ( V_2 -> V_114 + V_96 ) -> V_115 ;
( V_186 + V_164 ) -> V_64 = V_231 ;
V_164 ++ ;
}
F_43 (os, &oh->slave_ports, node) {
V_236 = F_65 ( V_93 ) ;
for ( V_123 = 0 ; V_123 < V_236 ; V_123 ++ ) {
( V_186 + V_164 ) -> V_5 = ( V_93 -> V_69 + V_123 ) -> V_5 ;
( V_186 + V_164 ) -> V_238 = ( V_93 -> V_69 + V_123 ) -> V_118 ;
( V_186 + V_164 ) -> V_239 = ( V_93 -> V_69 + V_123 ) -> V_119 ;
( V_186 + V_164 ) -> V_64 = V_232 ;
V_164 ++ ;
}
}
return V_164 ;
}
int F_162 ( struct V_1 * V_2 , struct V_233 * V_186 )
{
int V_96 , V_235 ;
int V_164 = 0 ;
V_235 = F_64 ( V_2 ) ;
for ( V_96 = 0 ; V_96 < V_235 ; V_96 ++ ) {
( V_186 + V_164 ) -> V_5 = ( V_2 -> V_114 + V_96 ) -> V_5 ;
( V_186 + V_164 ) -> V_238 = ( V_2 -> V_114 + V_96 ) -> V_115 ;
( V_186 + V_164 ) -> V_239 = ( V_2 -> V_114 + V_96 ) -> V_115 ;
( V_186 + V_164 ) -> V_64 = V_231 ;
V_164 ++ ;
}
return V_164 ;
}
int F_163 ( struct V_1 * V_2 , unsigned int type ,
const char * V_5 , struct V_233 * V_240 )
{
int V_164 ;
unsigned int V_111 , V_122 ;
T_1 V_118 , V_119 ;
if ( ! V_2 || ! V_240 )
return - V_6 ;
if ( type == V_230 ) {
V_164 = F_66 ( V_2 , V_5 , & V_111 ) ;
if ( V_164 )
return V_164 ;
V_240 -> V_238 = V_111 ;
V_240 -> V_239 = V_111 ;
} else if ( type == V_231 ) {
V_164 = F_67 ( V_2 , V_5 , & V_122 ) ;
if ( V_164 )
return V_164 ;
V_240 -> V_238 = V_122 ;
V_240 -> V_239 = V_122 ;
} else if ( type == V_232 ) {
V_164 = F_68 ( V_2 , V_5 , & V_118 , & V_119 ) ;
if ( V_164 )
return V_164 ;
V_240 -> V_238 = V_118 ;
V_240 -> V_239 = V_119 ;
} else {
return - V_6 ;
}
V_240 -> V_64 = type ;
V_240 -> V_5 = V_5 ;
return 0 ;
}
struct V_241 * F_164 ( struct V_1 * V_2 )
{
struct V_58 * V_34 ;
struct V_92 * V_212 ;
struct V_56 * V_59 ;
struct V_57 * V_58 ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_59 )
return V_2 -> V_59 -> V_167 . V_168 ;
if ( V_2 -> V_60 ) {
V_34 = V_2 -> V_60 ;
} else {
V_212 = F_70 ( V_2 ) ;
if ( ! V_212 )
return NULL ;
V_34 = V_212 -> V_60 ;
}
V_58 = F_22 ( F_23 ( V_34 ) ) ;
V_59 = V_58 -> V_59 ;
if ( ! V_59 )
return NULL ;
return V_59 -> V_167 . V_168 ;
}
void T_5 * F_165 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_11 & V_105 )
return NULL ;
if ( V_2 -> V_42 == V_204 )
return NULL ;
return V_2 -> V_196 ;
}
int F_166 ( struct V_1 * V_2 )
{
unsigned long V_64 ;
T_1 V_13 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ) {
V_13 = V_2 -> V_7 ;
F_18 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_157 ( & V_2 -> V_209 , V_64 ) ;
return 0 ;
}
int F_167 ( struct V_1 * V_2 )
{
unsigned long V_64 ;
T_1 V_13 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ) {
V_13 = V_2 -> V_7 ;
F_19 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_157 ( & V_2 -> V_209 , V_64 ) ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 , const char * V_5 )
{
int V_80 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
V_80 = F_80 ( V_2 , V_5 ) ;
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_80 ;
}
int F_169 ( struct V_1 * V_2 , const char * V_5 )
{
int V_80 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
V_80 = F_81 ( V_2 , V_5 ) ;
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_80 ;
}
int F_170 ( const char * V_242 ,
int (* F_146)( struct V_1 * V_2 ,
void * V_66 ) ,
void * V_66 )
{
struct V_1 * V_142 ;
int V_80 = 0 ;
if ( ! V_242 || ! F_146 )
return - V_6 ;
F_16 ( L_70 ,
V_70 , V_242 ) ;
F_43 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_142 -> V_3 -> V_5 , V_242 ) ) {
F_16 ( L_71 ,
V_70 , V_142 -> V_5 ) ;
V_80 = (* F_146)( V_142 , V_66 ) ;
if ( V_80 )
break;
}
}
if ( V_80 )
F_16 ( L_72 ,
V_70 , V_80 ) ;
return V_80 ;
}
int F_171 ( struct V_1 * V_2 , T_2 V_243 )
{
int V_80 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
if ( V_243 != V_176 &&
V_243 != V_43 &&
V_243 != V_175 )
return - V_6 ;
F_156 ( & V_2 -> V_209 , V_64 ) ;
if ( V_2 -> V_42 != V_144 ) {
V_80 = - V_6 ;
goto V_244;
}
V_2 -> V_203 = V_243 ;
V_80 = 0 ;
V_244:
F_157 ( & V_2 -> V_209 , V_64 ) ;
return V_80 ;
}
int F_172 ( struct V_1 * V_2 )
{
struct V_241 * V_167 ;
int V_80 = 0 ;
if ( V_85 . V_245 )
return V_85 . V_245 ( V_2 ) ;
V_167 = F_164 ( V_2 ) ;
if ( V_167 )
V_80 = F_173 ( V_167 ) ;
return V_80 ;
}
void T_4 F_174 ( void )
{
if ( F_175 () ) {
V_85 . V_180 = F_125 ;
V_85 . V_153 = F_128 ;
V_85 . V_155 = F_130 ;
V_85 . V_159 = F_132 ;
} else if ( F_176 () ) {
V_85 . V_180 = F_125 ;
V_85 . V_153 = F_128 ;
V_85 . V_155 = F_130 ;
V_85 . V_159 = F_132 ;
V_85 . V_63 = F_76 ;
} else if ( F_177 () || F_178 () || F_179 () ) {
V_85 . V_156 = F_59 ;
V_85 . V_157 = F_89 ;
V_85 . V_180 = F_127 ;
V_85 . V_153 = F_134 ;
V_85 . V_155 = F_135 ;
V_85 . V_159 = F_136 ;
V_85 . V_63 = F_76 ;
V_85 . V_179 = F_94 ;
V_85 . V_245 = F_97 ;
V_85 . V_91 = F_137 ;
V_85 . V_86 = F_41 ;
} else if ( F_180 () || F_181 () || F_182 () ||
F_183 () ) {
V_85 . V_156 = F_59 ;
V_85 . V_157 = F_89 ;
V_85 . V_180 = F_127 ;
V_85 . V_153 = F_134 ;
V_85 . V_155 = F_138 ;
V_85 . V_159 = F_136 ;
V_85 . V_63 = F_76 ;
V_85 . V_91 = F_137 ;
} else {
F_2 ( 1 , L_73 ) ;
}
F_39 () ;
V_226 = true ;
}
const char * F_184 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
return V_2 -> V_90 ;
}
