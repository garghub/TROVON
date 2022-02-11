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
static int F_28 ( struct V_1 * V_2 )
{
int V_66 = 0 ;
char V_5 [ V_67 ] ;
struct V_58 * V_58 ;
static const char V_68 [] = L_7 ;
if ( strlen ( V_2 -> V_5 ) >= V_67 - strlen ( V_68 ) )
F_15 ( L_8 , V_69 ,
V_2 -> V_5 ) ;
F_29 ( V_5 , V_2 -> V_5 , V_67 - strlen ( V_68 ) ) ;
F_30 ( V_5 , V_68 , V_67 ) ;
V_58 = F_31 ( NULL , V_5 ) ;
if ( ! F_32 ( V_58 ) ) {
V_2 -> V_60 = V_58 ;
V_70 . V_71 ( V_2 ) ;
V_2 -> V_72 = F_33 ( V_5 , V_73 ) ;
} else {
if ( ! V_2 -> V_72 )
return 0 ;
V_2 -> V_60 = F_31 ( NULL , V_2 -> V_72 ) ;
}
if ( F_32 ( V_2 -> V_60 ) ) {
F_15 ( L_9 ,
V_2 -> V_5 , V_2 -> V_72 ) ;
return - V_6 ;
}
F_34 ( V_2 -> V_60 ) ;
if ( ! F_20 ( V_2 ) )
F_16 ( L_10 ,
V_2 -> V_5 , V_2 -> V_72 ) ;
return V_66 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
struct V_58 * V_34 ;
int V_66 = 0 ;
F_36 (os, &oh->slave_ports, node) {
if ( ! V_75 -> V_58 )
continue;
V_34 = F_31 ( NULL , V_75 -> V_58 ) ;
if ( F_32 ( V_34 ) ) {
F_15 ( L_11 ,
V_2 -> V_5 , V_75 -> V_58 ) ;
V_66 = - V_6 ;
continue;
}
V_75 -> V_60 = V_34 ;
F_34 ( V_75 -> V_60 ) ;
}
return V_66 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_58 * V_34 ;
int V_78 ;
int V_66 = 0 ;
for ( V_78 = V_2 -> V_79 , V_77 = V_2 -> V_80 ; V_78 > 0 ; V_78 -- , V_77 ++ ) {
V_34 = F_31 ( NULL , V_77 -> V_58 ) ;
if ( F_32 ( V_34 ) ) {
F_15 ( L_12 ,
V_2 -> V_5 , V_77 -> V_58 ) ;
V_66 = - V_6 ;
continue;
}
V_77 -> V_60 = V_34 ;
F_34 ( V_77 -> V_60 ) ;
}
return V_66 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
int V_78 ;
F_16 ( L_13 , V_2 -> V_5 ) ;
for ( V_78 = V_2 -> V_79 , V_77 = V_2 -> V_80 ; V_78 > 0 ; V_78 -- , V_77 ++ )
if ( V_77 -> V_60 ) {
F_16 ( L_14 , V_77 -> V_81 ,
F_39 ( V_77 -> V_60 ) ) ;
F_40 ( V_77 -> V_60 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
int V_78 ;
F_16 ( L_15 , V_2 -> V_5 ) ;
for ( V_78 = V_2 -> V_79 , V_77 = V_2 -> V_80 ; V_78 > 0 ; V_78 -- , V_77 ++ )
if ( V_77 -> V_60 ) {
F_16 ( L_16 , V_77 -> V_81 ,
F_39 ( V_77 -> V_60 ) ) ;
F_42 ( V_77 -> V_60 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
F_16 ( L_17 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_40 ( V_2 -> V_60 ) ;
F_36 (os, &oh->slave_ports, node) {
if ( V_75 -> V_60 && ( V_75 -> V_64 & V_82 ) )
F_40 ( V_75 -> V_60 ) ;
}
if ( V_2 -> V_64 & V_83 )
F_38 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
F_16 ( L_18 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_42 ( V_2 -> V_60 ) ;
F_36 (os, &oh->slave_ports, node) {
if ( V_75 -> V_60 && ( V_75 -> V_64 & V_82 ) )
F_42 ( V_75 -> V_60 ) ;
}
if ( V_2 -> V_64 & V_83 )
F_41 ( V_2 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 || ! V_2 -> V_84 . V_85 . V_86 )
return;
F_16 ( L_19 ,
V_2 -> V_5 , V_69 , V_2 -> V_84 . V_85 . V_86 ) ;
F_46 ( V_2 -> V_84 . V_85 . V_86 ,
V_2 -> V_59 -> V_87 ,
V_2 -> V_59 -> V_88 , V_2 -> V_84 . V_85 . V_89 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_90 || ! V_2 -> V_59 )
return 0 ;
if ( V_2 -> V_64 & V_91 )
return 0 ;
if ( ! V_2 -> V_84 . V_85 . V_89 &&
! ( V_2 -> V_84 . V_85 . V_64 & V_92 ) )
return 0 ;
return F_48 ( V_2 -> V_59 -> V_87 ,
V_2 -> V_59 -> V_88 ,
V_2 -> V_84 . V_85 . V_89 , 0 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
int V_78 = 0 ;
if ( ! V_2 || ! V_2 -> V_95 )
return 0 ;
do {
V_94 = & V_2 -> V_95 [ V_78 ++ ] ;
} while ( V_94 -> V_96 != - 1 );
return V_78 - 1 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_78 = 0 ;
if ( ! V_2 || ! V_2 -> V_99 )
return 0 ;
do {
V_98 = & V_2 -> V_99 [ V_78 ++ ] ;
} while ( V_98 -> V_100 != - 1 );
return V_78 - 1 ;
}
static int F_51 ( struct V_74 * V_75 )
{
struct V_101 * V_102 ;
int V_78 = 0 ;
if ( ! V_75 || ! V_75 -> V_103 )
return 0 ;
do {
V_102 = & V_75 -> V_103 [ V_78 ++ ] ;
} while ( V_102 -> V_104 != V_102 -> V_105 );
return V_78 - 1 ;
}
static int F_52 ( struct V_1 * V_2 , const char * V_5 ,
unsigned int * V_96 )
{
int V_78 ;
bool V_106 = false ;
if ( ! V_2 -> V_95 )
return - V_107 ;
V_78 = 0 ;
while ( V_2 -> V_95 [ V_78 ] . V_96 != - 1 ) {
if ( V_5 == V_2 -> V_95 [ V_78 ] . V_5 ||
! strcmp ( V_5 , V_2 -> V_95 [ V_78 ] . V_5 ) ) {
V_106 = true ;
break;
}
V_78 ++ ;
}
if ( ! V_106 )
return - V_107 ;
* V_96 = V_2 -> V_95 [ V_78 ] . V_96 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , const char * V_5 ,
unsigned int * V_108 )
{
int V_78 ;
bool V_106 = false ;
if ( ! V_2 -> V_99 )
return - V_107 ;
V_78 = 0 ;
while ( V_2 -> V_99 [ V_78 ] . V_100 != - 1 ) {
if ( V_5 == V_2 -> V_99 [ V_78 ] . V_5 ||
! strcmp ( V_5 , V_2 -> V_99 [ V_78 ] . V_5 ) ) {
V_106 = true ;
break;
}
V_78 ++ ;
}
if ( ! V_106 )
return - V_107 ;
* V_108 = V_2 -> V_99 [ V_78 ] . V_100 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , const char * V_5 ,
T_1 * V_104 , T_1 * V_105 )
{
int V_109 ;
struct V_74 * V_75 ;
bool V_106 = false ;
F_36 (os, &oh->slave_ports, node) {
if ( ! V_75 -> V_103 )
return - V_107 ;
V_109 = 0 ;
while ( V_75 -> V_103 [ V_109 ] . V_104 != V_75 -> V_103 [ V_109 ] . V_105 ) {
if ( V_5 == V_75 -> V_103 [ V_109 ] . V_5 ||
! strcmp ( V_5 , V_75 -> V_103 [ V_109 ] . V_5 ) ) {
V_106 = true ;
break;
}
V_109 ++ ;
}
if ( V_106 )
break;
}
if ( ! V_106 )
return - V_107 ;
* V_104 = V_75 -> V_103 [ V_109 ] . V_104 ;
* V_105 = V_75 -> V_103 [ V_109 ] . V_105 ;
return 0 ;
}
static void T_3 F_55 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = NULL ;
if ( ! V_2 )
return;
V_2 -> V_11 |= V_90 ;
F_36 (os, &oh->slave_ports, node) {
if ( V_75 -> V_110 & V_111 ) {
V_2 -> V_112 = V_75 ;
V_2 -> V_11 &= ~ V_90 ;
break;
}
}
return;
}
static struct V_74 * F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 || V_2 -> V_11 & V_90 || V_2 -> V_113 == 0 )
return NULL ;
return V_2 -> V_112 ;
}
static struct V_101 * T_3 F_57 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
struct V_101 * V_102 ;
int V_106 = 0 , V_78 = 0 ;
V_75 = F_56 ( V_2 ) ;
if ( ! V_75 || ! V_75 -> V_103 )
return NULL ;
do {
V_102 = & V_75 -> V_103 [ V_78 ++ ] ;
if ( V_102 -> V_64 & V_114 )
V_106 = 1 ;
} while ( ! V_106 && V_102 -> V_104 != V_102 -> V_105 );
return ( V_106 ) ? V_102 : NULL ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_22 , V_115 ;
T_1 V_13 ;
bool V_116 ;
struct V_56 * V_59 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
if ( V_2 -> V_64 & V_117 )
F_38 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_64 & V_117 )
F_41 ( V_2 ) ;
V_13 = V_2 -> V_7 ;
V_115 = V_2 -> V_3 -> V_4 -> V_9 ;
V_59 = F_20 ( V_2 ) ;
if ( V_115 & V_25 ) {
if ( V_2 -> V_64 & V_118 ||
V_2 -> V_64 & V_119 ) {
V_22 = V_120 ;
} else {
if ( V_115 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
V_116 = ( V_59 && V_59 -> V_64 & V_121 ) ;
if ( V_116 && ! ( V_2 -> V_3 -> V_4 -> V_50 &
( V_122 | V_51 ) ) )
V_22 = V_123 ;
F_8 ( V_2 , V_22 , & V_13 ) ;
}
if ( V_115 & V_19 ) {
if ( V_2 -> V_64 & V_124 ) {
V_22 = V_123 ;
} else if ( V_2 -> V_64 & V_125 ) {
V_22 = V_120 ;
} else {
if ( V_115 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_52 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
F_6 ( V_2 , V_22 , & V_13 ) ;
}
if ( ( V_2 -> V_64 & V_126 ) &&
( V_115 & V_29 ) )
F_9 ( V_2 , V_127 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
if ( V_115 & V_48 ) {
V_22 = ( V_2 -> V_64 & V_128 ) ?
0 : 1 ;
F_17 ( V_2 , V_22 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
T_2 V_22 , V_115 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_115 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_115 & V_25 ) {
if ( V_2 -> V_64 & V_118 ) {
V_22 = V_123 ;
} else {
if ( V_115 & V_49 )
F_18 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_50 & V_51 )
V_22 = V_54 ;
else
V_22 = V_55 ;
}
F_8 ( V_2 , V_22 , & V_13 ) ;
}
if ( V_115 & V_19 ) {
if ( ( V_2 -> V_64 & V_125 ) ||
( V_2 -> V_64 & V_124 ) ) {
V_22 = V_123 ;
} else {
if ( V_115 & V_49 )
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
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_115 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_115 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_115 & V_25 )
F_8 ( V_2 , V_123 , & V_13 ) ;
if ( V_115 & V_19 )
F_6 ( V_2 , V_123 , & V_13 ) ;
if ( V_115 & V_48 )
F_17 ( V_2 , 1 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static struct V_1 * F_61 ( const char * V_5 )
{
struct V_1 * V_2 , * V_129 ;
V_2 = NULL ;
F_36 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_5 , V_129 -> V_5 ) ) {
V_2 = V_129 ;
break;
}
}
return V_2 ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_130 ) {
F_16 ( L_20 , V_2 -> V_5 ) ;
return 0 ;
}
V_2 -> V_59 = F_63 ( V_2 -> V_130 ) ;
if ( ! V_2 -> V_59 ) {
F_15 ( L_21 ,
V_2 -> V_5 , V_2 -> V_130 ) ;
return 0 ;
}
F_16 ( L_22 ,
V_2 -> V_5 , V_2 -> V_130 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , void * V_131 )
{
int V_66 = 0 ;
if ( V_2 -> V_42 != V_132 )
return 0 ;
F_16 ( L_23 , V_2 -> V_5 ) ;
if ( V_70 . V_63 )
V_66 |= V_70 . V_63 ( V_2 ) ;
V_66 |= F_28 ( V_2 ) ;
V_66 |= F_35 ( V_2 ) ;
V_66 |= F_37 ( V_2 ) ;
if ( ! V_66 )
V_2 -> V_42 = V_133 ;
else
F_15 ( L_24 , V_2 -> V_5 ) ;
return V_66 ;
}
static int F_65 ( struct V_1 * V_2 , const char * V_5 ,
struct V_134 * V_135 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_136 ; V_78 ++ ) {
const char * V_137 = V_2 -> V_138 [ V_78 ] . V_5 ;
if ( ! strcmp ( V_137 , V_5 ) ) {
V_135 -> V_139 = V_2 -> V_138 [ V_78 ] . V_139 ;
V_135 -> V_140 = V_2 -> V_138 [ V_78 ] . V_140 ;
F_16 ( L_25 ,
V_2 -> V_5 , V_69 , V_137 , V_135 -> V_139 ,
V_135 -> V_140 ) ;
return 0 ;
}
}
return - V_107 ;
}
static int F_66 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_134 V_135 ;
int V_66 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_70 . V_141 )
return - V_142 ;
V_66 = F_65 ( V_2 , V_5 , & V_135 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = V_70 . V_141 ( V_2 , & V_135 ) ;
return V_66 ;
}
static int F_67 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_134 V_135 ;
int V_66 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_70 . V_143 )
return - V_142 ;
V_66 = F_65 ( V_2 , V_5 , & V_135 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( V_2 -> V_59 ) {
F_68 ( V_2 -> V_59 ) ;
V_66 = F_69 ( V_2 -> V_59 , V_2 ) ;
if ( V_66 ) {
F_2 ( 1 , L_26 ,
V_2 -> V_5 , V_2 -> V_59 -> V_5 , V_66 ) ;
return V_66 ;
}
}
F_43 ( V_2 ) ;
if ( V_70 . V_144 )
V_70 . V_144 ( V_2 ) ;
V_66 = V_70 . V_143 ( V_2 , & V_135 ) ;
if ( V_70 . V_145 )
V_70 . V_145 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_66 == - V_146 )
F_15 ( L_27 , V_2 -> V_5 ) ;
if ( V_2 -> V_59 ) {
F_70 ( V_2 -> V_59 ) ;
F_71 ( V_2 -> V_59 , V_2 ) ;
}
return V_66 ;
}
static int F_72 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_134 V_135 ;
int V_66 = - V_6 ;
if ( ! V_2 )
return - V_6 ;
if ( ! V_70 . V_147 )
return - V_142 ;
V_66 = F_65 ( V_2 , V_5 , & V_135 ) ;
if ( V_66 < 0 )
return V_66 ;
return V_70 . V_147 ( V_2 , & V_135 ) ;
}
static bool F_73 ( struct V_1 * V_2 )
{
int V_78 , V_148 = 0 ;
if ( V_2 -> V_136 == 0 )
return false ;
for ( V_78 = 0 ; V_78 < V_2 -> V_136 ; V_78 ++ )
if ( F_72 ( V_2 , V_2 -> V_138 [ V_78 ] . V_5 ) > 0 )
V_148 ++ ;
if ( V_2 -> V_136 == V_148 )
return true ;
return false ;
}
static bool F_74 ( struct V_1 * V_2 )
{
int V_148 = 0 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_136 && V_148 == 0 ; V_78 ++ )
if ( F_72 ( V_2 , V_2 -> V_138 [ V_78 ] . V_5 ) > 0 )
V_148 ++ ;
return ( V_148 ) ? true : false ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! V_2 -> V_59 || ! V_2 -> V_84 . V_85 . V_86 )
return - V_6 ;
if ( F_74 ( V_2 ) )
return 0 ;
F_16 ( L_28 , V_2 -> V_5 , V_69 ) ;
F_76 ( V_2 -> V_59 -> V_87 , V_2 -> V_59 -> V_88 ,
V_2 -> V_84 . V_85 . V_89 ) ;
V_13 = F_47 ( V_2 ) ;
if ( V_13 )
F_15 ( L_29 ,
V_2 -> V_5 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_34 = 0 ;
int V_66 = 0 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_31 ) )
return - V_107 ;
if ( V_2 -> V_42 != V_43 ) {
F_15 ( L_30 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_64 & V_117 )
F_38 ( V_2 ) ;
F_16 ( L_31 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_66 = F_10 ( V_2 , & V_13 ) ;
if ( V_66 )
goto V_149;
F_4 ( V_13 , V_2 ) ;
if ( V_2 -> V_3 -> V_4 -> V_150 )
F_78 ( V_2 -> V_3 -> V_4 -> V_150 ) ;
V_34 = F_12 ( V_2 ) ;
if ( V_34 == V_38 ) {
F_15 ( L_32 ,
V_2 -> V_5 , V_38 ) ;
V_66 = - V_151 ;
goto V_149;
} else {
F_16 ( L_33 , V_2 -> V_5 , V_34 ) ;
}
V_66 = F_11 ( V_2 , & V_13 ) ;
if ( V_66 )
goto V_149;
F_4 ( V_13 , V_2 ) ;
V_149:
if ( V_2 -> V_64 & V_117 )
F_41 ( V_2 ) ;
return V_66 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_78 , V_152 ;
F_16 ( L_34 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_153 ) {
V_152 = V_2 -> V_3 -> V_153 ( V_2 ) ;
} else {
if ( V_2 -> V_136 > 0 ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_136 ; V_78 ++ )
F_66 ( V_2 , V_2 -> V_138 [ V_78 ] . V_5 ) ;
return 0 ;
} else {
V_152 = F_77 ( V_2 ) ;
if ( V_152 == - V_107 )
V_152 = 0 ;
}
}
F_14 ( V_2 ) ;
if ( V_2 -> V_3 -> V_4 ) {
F_1 ( V_2 ) ;
F_58 ( V_2 ) ;
}
return V_152 ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 . V_85 . V_64 & V_154 )
return;
if ( ! F_81 ( V_2 -> V_59 -> V_155 . V_156 -> V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_158 ) )
return;
V_2 -> V_84 . V_85 . V_159 ++ ;
F_82 ( V_2 -> V_59 -> V_155 . V_156 -> V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_158 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
return V_2 -> V_84 . V_85 . V_159 ;
}
static int F_84 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_160 )
return 0 ;
return V_2 -> V_3 -> V_160 ( V_2 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_152 ;
F_16 ( L_35 , V_2 -> V_5 ) ;
if ( V_2 -> V_11 & V_161 ) {
V_2 -> V_11 &= ~ V_161 ;
return 0 ;
}
if ( V_2 -> V_42 != V_162 &&
V_2 -> V_42 != V_163 &&
V_2 -> V_42 != V_164 ) {
F_2 ( 1 , L_36 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( F_73 ( V_2 ) )
return 0 ;
F_24 ( V_2 , V_165 ) ;
if ( V_2 -> V_59 ) {
F_68 ( V_2 -> V_59 ) ;
V_152 = F_69 ( V_2 -> V_59 , V_2 ) ;
if ( V_152 ) {
F_2 ( 1 , L_26 ,
V_2 -> V_5 , V_2 -> V_59 -> V_5 , V_152 ) ;
return V_152 ;
}
}
F_43 ( V_2 ) ;
if ( V_70 . V_144 )
V_70 . V_144 ( V_2 ) ;
if ( V_2 -> V_64 & V_166 )
F_86 ( true ) ;
if ( V_70 . V_167 )
V_70 . V_167 ( V_2 ) ;
V_152 = ( V_70 . V_168 ) ? V_70 . V_168 ( V_2 ) :
- V_6 ;
if ( V_2 -> V_59 && ! ( V_2 -> V_64 & V_169 ) )
F_70 ( V_2 -> V_59 ) ;
if ( ! V_152 ) {
V_2 -> V_42 = V_43 ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_1 ( V_2 ) ;
F_58 ( V_2 ) ;
}
V_152 = F_84 ( V_2 ) ;
} else {
if ( V_70 . V_145 )
V_70 . V_145 ( V_2 ) ;
F_44 ( V_2 ) ;
F_87 ( L_37 ,
V_2 -> V_5 , V_152 ) ;
if ( V_2 -> V_59 )
F_71 ( V_2 -> V_59 , V_2 ) ;
}
return V_152 ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 & V_170 ) {
V_2 -> V_11 |= V_161 ;
return 0 ;
}
F_16 ( L_38 , V_2 -> V_5 ) ;
if ( F_73 ( V_2 ) )
return 0 ;
if ( V_2 -> V_42 != V_43 ) {
F_2 ( 1 , L_39 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 )
F_59 ( V_2 ) ;
F_26 ( V_2 , V_165 ) ;
if ( V_2 -> V_59 && ! ( V_2 -> V_64 & V_169 ) )
F_68 ( V_2 -> V_59 ) ;
if ( V_2 -> V_64 & V_166 )
F_86 ( false ) ;
if ( V_70 . V_145 )
V_70 . V_145 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_2 -> V_59 ) {
F_70 ( V_2 -> V_59 ) ;
F_71 ( V_2 -> V_59 , V_2 ) ;
}
V_2 -> V_42 = V_163 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_66 , V_78 ;
T_2 V_171 ;
if ( F_73 ( V_2 ) )
return 0 ;
if ( V_2 -> V_42 != V_163 &&
V_2 -> V_42 != V_43 ) {
F_2 ( 1 , L_40 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
F_16 ( L_41 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_172 ) {
V_171 = V_2 -> V_42 ;
if ( V_2 -> V_42 == V_163 )
F_85 ( V_2 ) ;
V_66 = V_2 -> V_3 -> V_172 ( V_2 ) ;
if ( V_66 ) {
if ( V_171 == V_163 )
F_88 ( V_2 ) ;
return V_66 ;
}
}
if ( V_2 -> V_3 -> V_4 ) {
if ( V_2 -> V_42 == V_163 )
F_85 ( V_2 ) ;
F_60 ( V_2 ) ;
}
if ( V_2 -> V_42 == V_43 ) {
F_26 ( V_2 , V_165 ) ;
if ( V_2 -> V_64 & V_166 )
F_86 ( false ) ;
if ( V_70 . V_145 )
V_70 . V_145 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_2 -> V_59 )
F_71 ( V_2 -> V_59 , V_2 ) ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_136 ; V_78 ++ )
F_66 ( V_2 , V_2 -> V_138 [ V_78 ] . V_5 ) ;
V_2 -> V_42 = V_164 ;
return 0 ;
}
static int F_90 ( struct V_173 * V_174 ,
struct V_1 * V_2 )
{
int V_175 , V_78 , V_176 ;
const char * V_177 ;
V_175 = F_91 ( V_174 , L_42 ) ;
if ( V_175 < 1 )
return - V_178 ;
for ( V_78 = 0 ; V_78 < V_175 ; V_78 ++ ) {
V_176 = F_92 ( V_174 , L_42 ,
V_78 , & V_177 ) ;
if ( V_176 )
continue;
if ( ! strcmp ( V_177 , V_2 -> V_5 ) ) {
F_16 ( L_43 ,
V_174 -> V_5 , V_78 , V_2 -> V_5 ) ;
return V_78 ;
}
}
return - V_178 ;
}
static int F_93 ( struct V_173 * V_174 ,
struct V_1 * V_2 ,
int * V_179 ,
struct V_173 * * V_106 )
{
struct V_173 * V_180 = NULL ;
int V_176 ;
V_176 = F_90 ( V_174 , V_2 ) ;
if ( V_176 >= 0 ) {
* V_106 = V_174 ;
* V_179 = V_176 ;
return 0 ;
}
F_94 (np, np0) {
struct V_173 * V_181 ;
int V_78 ;
V_176 = F_93 ( V_180 , V_2 , & V_78 , & V_181 ) ;
if ( V_176 == 0 ) {
* V_106 = V_181 ;
* V_179 = V_78 ;
return 0 ;
}
}
* V_106 = NULL ;
* V_179 = 0 ;
return - V_178 ;
}
static int T_3 F_95 ( struct V_1 * V_2 , void * V_131 ,
int V_179 , struct V_173 * V_174 )
{
struct V_101 * V_102 ;
void T_4 * va_start = NULL ;
if ( ! V_2 )
return - V_6 ;
F_55 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
return 0 ;
if ( V_2 -> V_11 & V_90 )
return - V_182 ;
V_102 = F_57 ( V_2 ) ;
if ( ! V_102 ) {
F_16 ( L_44 ,
V_2 -> V_5 ) ;
if ( ! V_174 ) {
F_87 ( L_45 , V_2 -> V_5 ) ;
return - V_182 ;
}
va_start = F_96 ( V_174 , V_179 + V_2 -> V_183 ) ;
} else {
va_start = F_97 ( V_102 -> V_104 , V_102 -> V_105 - V_102 -> V_104 ) ;
}
if ( ! va_start ) {
if ( V_102 )
F_87 ( L_46 , V_2 -> V_5 ) ;
else
F_87 ( L_47 ,
V_2 -> V_5 , V_179 , V_174 -> V_184 ) ;
return - V_182 ;
}
F_16 ( L_48 ,
V_2 -> V_5 , va_start ) ;
V_2 -> V_185 = va_start ;
return 0 ;
}
static int T_3 F_98 ( struct V_1 * V_2 , void * V_131 )
{
int V_152 , V_179 ;
struct V_173 * V_174 = NULL ;
if ( V_2 -> V_42 != V_132 )
return 0 ;
if ( F_99 () ) {
struct V_173 * V_186 ;
V_186 = F_100 ( NULL , L_49 ) ;
if ( ! V_186 )
return - V_178 ;
V_152 = F_93 ( V_186 , V_2 , & V_179 , & V_174 ) ;
if ( V_152 )
F_16 ( L_50 , V_2 -> V_5 ) ;
else if ( V_174 && V_179 )
F_15 ( L_51 ,
V_2 -> V_5 , V_174 -> V_5 ) ;
}
V_152 = F_95 ( V_2 , NULL , V_179 , V_174 ) ;
if ( V_152 < 0 ) {
F_2 ( 1 , L_52 ,
V_2 -> V_5 ) ;
return 0 ;
}
V_152 = F_64 ( V_2 , NULL ) ;
if ( V_152 < 0 ) {
F_2 ( 1 , L_53 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_174 ) {
if ( F_101 ( V_174 , L_54 , NULL ) )
V_2 -> V_64 |= V_187 ;
if ( F_101 ( V_174 , L_55 , NULL ) )
V_2 -> V_64 |= V_188 ;
if ( F_101 ( V_174 , L_56 , NULL ) )
V_2 -> V_64 |= V_170 ;
}
V_2 -> V_42 = V_162 ;
return 0 ;
}
static void T_3 F_102 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
if ( V_2 -> V_42 != V_162 )
return;
F_36 (os, &oh->slave_ports, node) {
if ( ! V_75 -> V_60 )
continue;
if ( V_75 -> V_64 & V_82 ) {
} else {
F_40 ( V_75 -> V_60 ) ;
}
}
return;
}
static int T_3 F_103 ( struct V_1 * V_2 )
{
int V_152 ;
if ( V_2 -> V_42 != V_162 )
return - V_6 ;
if ( V_2 -> V_64 & V_189 )
return - V_190 ;
if ( V_2 -> V_136 == 0 ) {
V_152 = F_85 ( V_2 ) ;
if ( V_152 ) {
F_15 ( L_57 ,
V_2 -> V_5 , V_2 -> V_42 ) ;
return - V_6 ;
}
}
if ( ! ( V_2 -> V_64 & V_187 ) )
V_152 = F_79 ( V_2 ) ;
return V_152 ;
}
static void T_3 F_104 ( struct V_1 * V_2 )
{
T_2 V_191 ;
if ( V_2 -> V_136 > 0 )
return;
V_191 = V_2 -> V_192 ;
if ( V_191 == V_193 )
V_191 = V_43 ;
if ( ( V_2 -> V_64 & ( V_188 | V_170 ) ) &&
( V_191 == V_163 ) ) {
V_2 -> V_11 |= V_161 ;
V_191 = V_43 ;
}
if ( V_191 == V_163 )
F_88 ( V_2 ) ;
else if ( V_191 == V_164 )
F_89 ( V_2 ) ;
else if ( V_191 != V_43 )
F_2 ( 1 , L_58 ,
V_2 -> V_5 , V_191 ) ;
return;
}
static int T_3 F_105 ( struct V_1 * V_2 , void * V_131 )
{
if ( V_2 -> V_42 != V_162 )
return 0 ;
if ( V_2 -> V_194 ) {
int V_152 ;
V_152 = F_85 ( V_2 -> V_194 ) ;
F_2 ( V_152 , L_59 ,
V_2 -> V_5 , V_2 -> V_194 -> V_5 ) ;
}
F_102 ( V_2 ) ;
if ( ! F_103 ( V_2 ) )
F_104 ( V_2 ) ;
if ( V_2 -> V_194 ) {
T_2 V_191 ;
V_191 = V_2 -> V_194 -> V_192 ;
if ( V_191 == V_163 )
F_88 ( V_2 -> V_194 ) ;
else if ( V_191 == V_164 )
F_89 ( V_2 -> V_194 ) ;
else if ( V_191 != V_43 )
F_2 ( 1 , L_58 ,
V_2 -> V_194 -> V_5 , V_191 ) ;
}
return 0 ;
}
static int T_3 F_106 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_5 || ! V_2 -> V_3 || ! V_2 -> V_3 -> V_5 ||
( V_2 -> V_42 != V_193 ) )
return - V_6 ;
F_16 ( L_60 , V_2 -> V_5 ) ;
if ( F_61 ( V_2 -> V_5 ) )
return - V_195 ;
F_107 ( & V_2 -> V_196 , & V_197 ) ;
F_108 ( & V_2 -> V_198 ) ;
F_109 ( & V_2 -> V_199 ) ;
F_110 ( & V_2 -> V_199 , & V_2 -> V_200 ) ;
V_2 -> V_42 = V_132 ;
if ( ! strcmp ( V_2 -> V_5 , V_201 ) )
V_165 = V_2 ;
return 0 ;
}
static int T_3 F_111 ( struct V_74 * V_202 )
{
F_16 ( L_61 , V_202 -> V_203 -> V_5 ,
V_202 -> V_204 -> V_5 ) ;
F_112 ( & V_202 -> V_196 , & V_202 -> V_204 -> V_198 ) ;
V_202 -> V_204 -> V_113 ++ ;
return 0 ;
}
static int T_3 F_113 ( struct V_74 * V_202 )
{
if ( ! V_202 || ! V_202 -> V_203 || ! V_202 -> V_204 || ! V_202 -> V_110 )
return - V_6 ;
if ( V_202 -> V_11 & V_205 )
return - V_195 ;
F_16 ( L_62 ,
V_202 -> V_203 -> V_5 , V_202 -> V_204 -> V_5 ) ;
if ( V_202 -> V_203 -> V_42 != V_132 )
F_106 ( V_202 -> V_203 ) ;
if ( V_202 -> V_204 -> V_42 != V_132 )
F_106 ( V_202 -> V_204 ) ;
F_111 ( V_202 ) ;
V_202 -> V_11 |= V_205 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_64 & V_91 )
return 0 ;
if ( ! F_56 ( V_2 ) )
return 0 ;
return F_115 ( 0 , V_2 -> V_84 . V_206 . V_207 ,
V_2 -> V_84 . V_206 . V_208 ,
V_2 -> V_84 . V_206 . V_209 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_64 & V_91 || ! V_2 -> V_59 )
return 0 ;
if ( ! F_56 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_84 . V_85 . V_89 &&
! ( V_2 -> V_84 . V_85 . V_64 & V_92 ) )
return 0 ;
return F_115 ( V_2 -> V_59 -> V_87 ,
V_2 -> V_59 -> V_88 ,
V_2 -> V_84 . V_85 . V_89 , 0 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
return F_118 ( V_135 -> V_139 , 0 ,
V_2 -> V_84 . V_206 . V_207 , 0 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
return F_120 ( V_135 -> V_139 , V_135 -> V_140 , 0 ,
V_2 -> V_84 . V_206 . V_207 , 0 , 0 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
return F_122 ( V_135 -> V_140 , 0 ,
V_2 -> V_84 . V_206 . V_207 , 0 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
return F_118 ( V_135 -> V_139 ,
V_2 -> V_59 -> V_155 . V_156 -> V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_210 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
if ( V_135 -> V_140 )
F_87 ( L_63 ,
V_2 -> V_5 , V_135 -> V_5 ) ;
return F_120 ( V_135 -> V_139 , V_135 -> V_139 ,
V_2 -> V_59 -> V_155 . V_156 -> V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_210 ,
V_2 -> V_84 . V_85 . V_210 +
V_211 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
if ( ! V_2 -> V_59 )
return - V_6 ;
return F_122 ( V_135 -> V_139 ,
V_2 -> V_59 -> V_155 . V_156 ->
V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_210 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
V_2 -> V_84 . V_85 . V_89 = 0 ;
V_2 -> V_84 . V_85 . V_86 = 0 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
return F_120 ( V_135 -> V_139 , V_135 -> V_140 ,
V_2 -> V_59 -> V_155 . V_156 -> V_87 ,
V_2 -> V_59 -> V_155 . V_156 -> V_157 ,
V_2 -> V_84 . V_85 . V_210 ,
V_2 -> V_84 . V_85 . V_212 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , T_5 V_213 )
{
if ( V_2 -> V_64 & V_214 )
return F_128 ( V_2 -> V_185 + V_213 ) ;
else
return F_129 ( V_2 -> V_185 + V_213 ) ;
}
void F_5 ( T_1 V_13 , struct V_1 * V_2 , T_5 V_213 )
{
if ( V_2 -> V_64 & V_214 )
F_130 ( V_13 , V_2 -> V_185 + V_213 ) ;
else
F_131 ( V_13 , V_2 -> V_185 + V_213 ) ;
}
int F_132 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_66 ;
if ( ! V_2 || ! ( V_2 -> V_7 ) )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_66 = F_10 ( V_2 , & V_13 ) ;
if ( V_66 )
goto error;
F_4 ( V_13 , V_2 ) ;
V_66 = F_11 ( V_2 , & V_13 ) ;
if ( V_66 )
goto error;
F_4 ( V_13 , V_2 ) ;
error:
return V_66 ;
}
struct V_1 * F_133 ( const char * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return NULL ;
V_2 = F_61 ( V_5 ) ;
return V_2 ;
}
int F_134 ( int (* F_135)( struct V_1 * V_2 , void * V_131 ) ,
void * V_131 )
{
struct V_1 * V_129 ;
int V_66 = 0 ;
if ( ! F_135 )
return - V_6 ;
F_36 (temp_oh, &omap_hwmod_list, node) {
V_66 = (* F_135)( V_129 , V_131 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
int T_3 F_136 ( struct V_74 * * V_215 )
{
int V_152 , V_78 ;
if ( ! V_216 )
return - V_6 ;
if ( ! V_215 )
return 0 ;
if ( V_215 [ 0 ] == NULL )
return 0 ;
V_78 = 0 ;
do {
V_152 = F_113 ( V_215 [ V_78 ] ) ;
F_2 ( V_152 && V_152 != - V_195 ,
L_64 ,
V_215 [ V_78 ] -> V_203 -> V_5 , V_215 [ V_78 ] -> V_204 -> V_5 , V_152 ) ;
} while ( V_215 [ ++ V_78 ] );
return 0 ;
}
static void T_3 F_137 ( struct V_1 * V_2 )
{
if ( ! V_165 || V_165 -> V_42 == V_193 )
F_87 ( L_65 ,
V_69 , V_201 ) ;
else if ( V_165 -> V_42 == V_132 && V_2 != V_165 )
F_138 ( V_201 ) ;
}
int T_3 F_138 ( const char * V_217 )
{
struct V_1 * V_2 ;
F_16 ( L_28 , V_217 , V_69 ) ;
V_2 = F_61 ( V_217 ) ;
if ( ! V_2 ) {
F_2 ( 1 , L_66 , V_217 ) ;
return - V_6 ;
}
F_137 ( V_2 ) ;
F_98 ( V_2 , NULL ) ;
F_105 ( V_2 , NULL ) ;
return 0 ;
}
static void T_3 F_139 ( void )
{
struct V_173 * V_174 ;
struct V_1 * V_2 ;
const char * V_218 ;
V_174 = F_140 ( L_67 ) ;
if ( V_174 ) {
V_218 = F_141 ( V_174 , L_68 , NULL ) ;
if ( V_218 ) {
V_174 = F_140 ( V_218 ) ;
if ( V_174 ) {
V_218 = F_141 ( V_174 , L_42 , NULL ) ;
V_2 = F_133 ( V_218 ) ;
if ( V_2 )
V_2 -> V_64 |= V_219 ;
}
}
}
}
static int T_3 F_142 ( void )
{
F_137 ( NULL ) ;
F_134 ( F_98 , NULL ) ;
#ifdef F_143
F_139 () ;
#endif
F_134 ( F_105 , NULL ) ;
return 0 ;
}
int F_144 ( struct V_1 * V_2 )
{
int V_152 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
V_152 = F_85 ( V_2 ) ;
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_152 ;
}
int F_147 ( struct V_1 * V_2 )
{
int V_152 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
V_152 = F_88 ( V_2 ) ;
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_152 ;
}
int F_148 ( struct V_1 * V_2 )
{
int V_152 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
V_152 = F_89 ( V_2 ) ;
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_152 ;
}
int F_149 ( struct V_1 * V_2 , unsigned long V_64 )
{
int V_66 = 0 ;
if ( V_64 & V_220 )
V_66 += F_49 ( V_2 ) ;
if ( V_64 & V_221 )
V_66 += F_50 ( V_2 ) ;
if ( V_64 & V_222 ) {
struct V_74 * V_75 ;
F_36 (os, &oh->slave_ports, node)
V_66 += F_51 ( V_75 ) ;
}
return V_66 ;
}
int F_150 ( struct V_1 * V_2 , struct V_223 * V_176 )
{
struct V_74 * V_75 ;
int V_78 , V_109 , V_224 , V_225 , V_226 ;
int V_152 = 0 ;
V_224 = F_49 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_224 ; V_78 ++ ) {
unsigned int V_96 ;
if ( V_2 -> V_227 )
V_96 = V_2 -> V_227 ( ( V_2 -> V_95 + V_78 ) -> V_96 ) ;
else
V_96 = ( V_2 -> V_95 + V_78 ) -> V_96 ;
( V_176 + V_152 ) -> V_5 = ( V_2 -> V_95 + V_78 ) -> V_5 ;
( V_176 + V_152 ) -> V_228 = V_96 ;
( V_176 + V_152 ) -> V_229 = V_96 ;
( V_176 + V_152 ) -> V_64 = V_220 ;
V_152 ++ ;
}
V_225 = F_50 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_225 ; V_78 ++ ) {
( V_176 + V_152 ) -> V_5 = ( V_2 -> V_99 + V_78 ) -> V_5 ;
( V_176 + V_152 ) -> V_228 = ( V_2 -> V_99 + V_78 ) -> V_100 ;
( V_176 + V_152 ) -> V_229 = ( V_2 -> V_99 + V_78 ) -> V_100 ;
( V_176 + V_152 ) -> V_64 = V_221 ;
V_152 ++ ;
}
F_36 (os, &oh->slave_ports, node) {
V_226 = F_51 ( V_75 ) ;
for ( V_109 = 0 ; V_109 < V_226 ; V_109 ++ ) {
( V_176 + V_152 ) -> V_5 = ( V_75 -> V_103 + V_109 ) -> V_5 ;
( V_176 + V_152 ) -> V_228 = ( V_75 -> V_103 + V_109 ) -> V_104 ;
( V_176 + V_152 ) -> V_229 = ( V_75 -> V_103 + V_109 ) -> V_105 ;
( V_176 + V_152 ) -> V_64 = V_222 ;
V_152 ++ ;
}
}
return V_152 ;
}
int F_151 ( struct V_1 * V_2 , struct V_223 * V_176 )
{
int V_78 , V_225 ;
int V_152 = 0 ;
V_225 = F_50 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_225 ; V_78 ++ ) {
( V_176 + V_152 ) -> V_5 = ( V_2 -> V_99 + V_78 ) -> V_5 ;
( V_176 + V_152 ) -> V_228 = ( V_2 -> V_99 + V_78 ) -> V_100 ;
( V_176 + V_152 ) -> V_229 = ( V_2 -> V_99 + V_78 ) -> V_100 ;
( V_176 + V_152 ) -> V_64 = V_221 ;
V_152 ++ ;
}
return V_152 ;
}
int F_152 ( struct V_1 * V_2 , unsigned int type ,
const char * V_5 , struct V_223 * V_230 )
{
int V_152 ;
unsigned int V_96 , V_108 ;
T_1 V_104 , V_105 ;
if ( ! V_2 || ! V_230 )
return - V_6 ;
if ( type == V_220 ) {
V_152 = F_52 ( V_2 , V_5 , & V_96 ) ;
if ( V_152 )
return V_152 ;
V_230 -> V_228 = V_96 ;
V_230 -> V_229 = V_96 ;
} else if ( type == V_221 ) {
V_152 = F_53 ( V_2 , V_5 , & V_108 ) ;
if ( V_152 )
return V_152 ;
V_230 -> V_228 = V_108 ;
V_230 -> V_229 = V_108 ;
} else if ( type == V_222 ) {
V_152 = F_54 ( V_2 , V_5 , & V_104 , & V_105 ) ;
if ( V_152 )
return V_152 ;
V_230 -> V_228 = V_104 ;
V_230 -> V_229 = V_105 ;
} else {
return - V_6 ;
}
V_230 -> V_64 = type ;
V_230 -> V_5 = V_5 ;
return 0 ;
}
struct V_231 * F_153 ( struct V_1 * V_2 )
{
struct V_58 * V_34 ;
struct V_74 * V_202 ;
struct V_56 * V_59 ;
struct V_57 * V_58 ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_59 )
return V_2 -> V_59 -> V_155 . V_156 ;
if ( V_2 -> V_60 ) {
V_34 = V_2 -> V_60 ;
} else {
V_202 = F_56 ( V_2 ) ;
if ( ! V_202 )
return NULL ;
V_34 = V_202 -> V_60 ;
}
V_58 = F_22 ( F_23 ( V_34 ) ) ;
V_59 = V_58 -> V_59 ;
if ( ! V_59 )
return NULL ;
return V_59 -> V_155 . V_156 ;
}
void T_4 * F_154 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_11 & V_90 )
return NULL ;
if ( V_2 -> V_42 == V_193 )
return NULL ;
return V_2 -> V_185 ;
}
int F_155 ( struct V_1 * V_2 )
{
unsigned long V_64 ;
T_1 V_13 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ) {
V_13 = V_2 -> V_7 ;
F_18 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_146 ( & V_2 -> V_199 , V_64 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 )
{
unsigned long V_64 ;
T_1 V_13 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_49 ) ) {
V_13 = V_2 -> V_7 ;
F_19 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_146 ( & V_2 -> V_199 , V_64 ) ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 , const char * V_5 )
{
int V_66 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
V_66 = F_66 ( V_2 , V_5 ) ;
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_66 ;
}
int F_158 ( struct V_1 * V_2 , const char * V_5 )
{
int V_66 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
V_66 = F_67 ( V_2 , V_5 ) ;
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_66 ;
}
int F_159 ( const char * V_232 ,
int (* F_135)( struct V_1 * V_2 ,
void * V_110 ) ,
void * V_110 )
{
struct V_1 * V_129 ;
int V_66 = 0 ;
if ( ! V_232 || ! F_135 )
return - V_6 ;
F_16 ( L_69 ,
V_69 , V_232 ) ;
F_36 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_129 -> V_3 -> V_5 , V_232 ) ) {
F_16 ( L_70 ,
V_69 , V_129 -> V_5 ) ;
V_66 = (* F_135)( V_129 , V_110 ) ;
if ( V_66 )
break;
}
}
if ( V_66 )
F_16 ( L_71 ,
V_69 , V_66 ) ;
return V_66 ;
}
int F_160 ( struct V_1 * V_2 , T_2 V_233 )
{
int V_66 ;
unsigned long V_64 ;
if ( ! V_2 )
return - V_6 ;
if ( V_233 != V_164 &&
V_233 != V_43 &&
V_233 != V_163 )
return - V_6 ;
F_145 ( & V_2 -> V_199 , V_64 ) ;
if ( V_2 -> V_42 != V_132 ) {
V_66 = - V_6 ;
goto V_234;
}
V_2 -> V_192 = V_233 ;
V_66 = 0 ;
V_234:
F_146 ( & V_2 -> V_199 , V_64 ) ;
return V_66 ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_231 * V_155 ;
int V_66 = 0 ;
if ( V_70 . V_235 )
return V_70 . V_235 ( V_2 ) ;
V_155 = F_153 ( V_2 ) ;
if ( V_155 )
V_66 = F_162 ( V_155 ) ;
return V_66 ;
}
void T_3 F_163 ( void )
{
if ( F_164 () ) {
V_70 . V_168 = F_114 ;
V_70 . V_141 = F_117 ;
V_70 . V_143 = F_119 ;
V_70 . V_147 = F_121 ;
} else if ( F_165 () ) {
V_70 . V_168 = F_114 ;
V_70 . V_141 = F_117 ;
V_70 . V_143 = F_119 ;
V_70 . V_147 = F_121 ;
V_70 . V_63 = F_62 ;
} else if ( F_166 () || F_167 () || F_168 () ) {
V_70 . V_144 = F_45 ;
V_70 . V_145 = F_75 ;
V_70 . V_168 = F_116 ;
V_70 . V_141 = F_123 ;
V_70 . V_143 = F_124 ;
V_70 . V_147 = F_125 ;
V_70 . V_63 = F_62 ;
V_70 . V_167 = F_80 ;
V_70 . V_235 = F_83 ;
V_70 . V_71 = F_126 ;
} else if ( F_169 () || F_170 () || F_171 () ||
F_172 () ) {
V_70 . V_144 = F_45 ;
V_70 . V_145 = F_75 ;
V_70 . V_168 = F_116 ;
V_70 . V_141 = F_123 ;
V_70 . V_143 = F_127 ;
V_70 . V_147 = F_125 ;
V_70 . V_63 = F_62 ;
V_70 . V_71 = F_126 ;
} else {
F_2 ( 1 , L_72 ) ;
}
V_216 = true ;
}
const char * F_173 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
return V_2 -> V_72 ;
}
