static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_8 + ( V_3 / 8 ) ] ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
int V_10 ;
V_10 = F_4 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_10 & V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_12 = V_11 ? V_13 : V_14 ;
T_1 V_6 = V_5 -> V_7 [ V_12 + ( V_3 / 8 ) ] ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
if ( V_5 -> V_7 [ V_13 ] == V_5 -> V_7 [ V_14 ] )
F_6 ( V_5 , V_6 , V_9 , V_11 ? V_9 : 0 ) ;
else
F_7 ( V_5 , V_6 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_3 / 8 ) ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
int V_10 ;
V_10 = F_4 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ( V_10 & V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 + ( V_3 / 8 ) ] ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
F_5 ( V_2 , V_3 , V_11 ) ;
return F_6 ( V_5 , V_6 , V_9 , V_9 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 + ( V_3 / 8 ) ] ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
return F_6 ( V_5 , V_6 , V_9 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_16 & F_3 ( V_3 ) )
return - V_17 ;
return F_12 ( V_5 , F_3 ( V_3 ) , V_18 ) ;
}
static int F_13 ( struct V_19 * V_20 , unsigned int type )
{
struct V_1 * V_21 = F_14 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = F_3 ( V_3 % 8 ) ;
if ( type & V_24 || type & V_25 )
return - V_17 ;
if ( V_4 -> V_5 -> V_26 == V_27 ||
V_4 -> V_5 -> V_26 == V_28 )
return 0 ;
if ( type & V_29 )
V_4 -> V_7 [ V_30 ] [ V_23 ] |= V_9 ;
else
V_4 -> V_7 [ V_30 ] [ V_23 ] &= ~ V_9 ;
if ( type & V_31 )
V_4 -> V_7 [ V_32 ] [ V_23 ] |= V_9 ;
else
V_4 -> V_7 [ V_32 ] [ V_23 ] &= ~ V_9 ;
return 0 ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_14 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
F_16 ( & V_4 -> V_33 ) ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_14 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_34 = F_18 ( V_5 -> V_35 , 8 ) ;
static const T_1 V_36 [ V_37 ] [ V_38 ] = {
[ V_30 ] [ V_39 ] = V_40 ,
[ V_30 ] [ V_41 ] = V_42 ,
[ V_30 ] [ V_43 ] = V_44 ,
[ V_32 ] [ V_39 ] = V_45 ,
[ V_32 ] [ V_41 ] = V_46 ,
[ V_32 ] [ V_43 ] = V_47 ,
[ V_48 ] [ V_39 ] = V_49 ,
[ V_48 ] [ V_41 ] = V_50 ,
[ V_48 ] [ V_43 ] = V_51 ,
} ;
int V_52 , V_53 ;
for ( V_52 = 0 ; V_52 < V_37 ; V_52 ++ ) {
if ( ( V_5 -> V_26 == V_27 ||
V_5 -> V_26 == V_28 ) &&
( V_52 != V_48 ) )
continue;
for ( V_53 = 0 ; V_53 < V_34 ; V_53 ++ ) {
T_1 V_54 = V_4 -> V_55 [ V_52 ] [ V_53 ] ;
T_1 V_56 = V_4 -> V_7 [ V_52 ] [ V_53 ] ;
if ( V_56 == V_54 )
continue;
V_4 -> V_55 [ V_52 ] [ V_53 ] = V_56 ;
F_7 ( V_5 , V_5 -> V_7 [ V_36 [ V_52 ] [ V_53 ] ] , V_56 ) ;
}
}
F_19 ( & V_4 -> V_33 ) ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_14 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = F_3 ( V_3 % 8 ) ;
V_4 -> V_7 [ V_48 ] [ V_23 ] &= ~ V_9 ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_14 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = F_3 ( V_3 % 8 ) ;
V_4 -> V_7 [ V_48 ] [ V_23 ] |= V_9 ;
if ( V_5 -> V_26 == V_28 )
F_4 ( V_5 ,
V_5 -> V_7 [ V_8 + V_23 ] ) ;
}
static void F_22 ( struct V_57 * V_58 ,
struct V_1 * V_21 ,
unsigned V_3 , unsigned V_59 )
{
struct V_4 * V_4 = F_2 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
const char * V_60 = F_23 ( V_21 , V_3 ) ;
bool V_11 = ! ! F_1 ( V_21 , V_3 ) ;
T_1 V_61 = V_3 / 8 ;
T_1 V_62 = V_5 -> V_7 [ V_15 + V_61 ] ;
T_1 V_9 = F_3 ( V_3 % 8 ) ;
int V_10 ;
T_1 V_63 ;
V_10 = F_4 ( V_5 , V_62 ) ;
if ( V_10 < 0 )
return;
V_63 = ! ! ( V_10 & V_9 ) ;
if ( V_63 ) {
F_24 ( V_58 , L_1 ,
V_59 , V_60 ? : L_2 ,
V_11 ? L_3 : L_4 ) ;
} else {
T_1 V_64 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
char * V_68 [] = { L_5 ,
L_6 ,
L_7 } ;
char * V_69 [] = { L_8 ,
L_9 ,
L_7 } ;
char * V_70 [] = { L_10 ,
L_11 ,
L_7 } ;
#define F_25 2
T_1 V_71 = F_25 ;
T_1 V_72 = F_25 ;
T_1 V_73 = F_25 ;
bool V_74 ;
switch ( V_5 -> V_26 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_64 = V_5 -> V_7 [ V_80 + V_61 ] ;
V_10 = F_4 ( V_5 , V_64 ) ;
if ( V_10 < 0 )
return;
V_71 = ! ! ( V_10 & V_9 ) ;
case V_81 :
V_65 = V_5 -> V_7 [ V_40 + V_61 ] ;
V_66 = V_5 -> V_7 [ V_45 + V_61 ] ;
V_10 = F_4 ( V_5 , V_65 ) ;
if ( V_10 < 0 )
return;
V_72 = ! ! ( V_10 & V_9 ) ;
V_10 = F_4 ( V_5 , V_66 ) ;
if ( V_10 < 0 )
return;
V_73 = ! ! ( V_10 & V_9 ) ;
case V_27 :
case V_28 :
V_67 = V_5 -> V_7 [ V_49 + V_61 ] ;
break;
default:
return;
}
V_10 = F_4 ( V_5 , V_67 ) ;
if ( V_10 < 0 )
return;
V_74 = ! ! ( V_10 & V_9 ) ;
F_24 ( V_58 , L_12 ,
V_59 , V_60 ? : L_2 ,
V_11 ? L_3 : L_4 ,
V_68 [ V_71 ] ,
V_74 ? L_13 : L_14 ,
V_69 [ V_72 ] ,
V_70 [ V_73 ] ) ;
}
}
static void F_26 ( struct V_57 * V_58 , struct V_1 * V_21 )
{
unsigned V_52 ;
unsigned V_59 = V_21 -> V_82 ;
for ( V_52 = 0 ; V_52 < V_21 -> V_83 ; V_52 ++ , V_59 ++ ) {
F_22 ( V_58 , V_21 , V_52 , V_59 ) ;
F_24 ( V_58 , L_15 ) ;
}
}
static T_2 F_27 ( int V_84 , void * V_85 )
{
struct V_4 * V_4 = V_85 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_86 ;
int V_34 = F_18 ( V_5 -> V_35 , 8 ) ;
T_1 V_87 [ V_34 ] ;
int V_10 ;
int V_52 ;
if ( V_5 -> V_26 == V_28 )
V_86 = V_5 -> V_7 [ V_88 ] ;
else
V_86 = V_5 -> V_7 [ V_89 ] ;
V_10 = F_28 ( V_5 , V_86 , V_34 , V_87 ) ;
if ( V_10 < 0 )
return V_90 ;
for ( V_52 = 0 ; V_52 < V_34 ; V_52 ++ ) {
int V_61 = ( V_4 -> V_5 -> V_26 == V_28 ) ? V_52 :
V_34 - V_52 - 1 ;
unsigned int V_91 = V_4 -> V_7 [ V_48 ] [ V_61 ] ;
unsigned int V_92 = V_87 [ V_52 ] ;
V_92 &= V_91 ;
if ( ! V_92 )
continue;
while ( V_92 ) {
int V_93 = F_29 ( V_92 ) ;
int line = V_61 * 8 + V_93 ;
int V_94 = F_30 ( V_4 -> V_2 . V_95 ,
line ) ;
F_31 ( V_94 ) ;
V_92 &= ~ F_3 ( V_93 ) ;
}
if ( V_5 -> V_26 != V_27 && V_5 -> V_26 != V_28 &&
V_5 -> V_26 != V_81 ) {
F_7 ( V_5 , V_86 + V_52 , V_87 [ V_52 ] ) ;
F_7 ( V_5 ,
V_5 -> V_7 [ V_96 ] + V_52 ,
V_87 [ V_52 ] ) ;
}
}
return V_97 ;
}
static int F_32 ( struct V_98 * V_99 )
{
struct V_5 * V_5 = F_33 ( V_99 -> V_85 . V_100 ) ;
struct V_101 * V_102 = V_99 -> V_85 . V_103 ;
struct V_4 * V_4 ;
int V_10 ;
int V_84 = 0 ;
V_84 = F_34 ( V_99 , 0 ) ;
V_4 = F_35 ( sizeof( struct V_4 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
F_36 ( & V_4 -> V_33 ) ;
V_4 -> V_85 = & V_99 -> V_85 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_106 ;
V_4 -> V_2 . V_83 = V_5 -> V_35 ;
V_4 -> V_2 . V_100 = & V_99 -> V_85 ;
V_4 -> V_2 . V_103 = V_102 ;
V_4 -> V_2 . V_82 = - 1 ;
if ( F_37 ( V_107 ) )
V_4 -> V_2 . V_108 = F_26 ;
F_38 ( V_102 , L_16 ,
& V_4 -> V_16 ) ;
if ( V_4 -> V_16 )
V_4 -> V_2 . V_109 = true ;
if ( V_84 < 0 )
F_39 ( & V_99 -> V_85 ,
L_17
L_18 ) ;
V_10 = F_40 ( V_5 , V_18 ) ;
if ( V_10 )
goto V_110;
V_10 = F_41 ( & V_4 -> V_2 , V_4 ) ;
if ( V_10 ) {
F_42 ( & V_99 -> V_85 , L_19 , V_10 ) ;
goto V_111;
}
if ( V_84 > 0 ) {
V_10 = F_43 ( & V_99 -> V_85 , V_84 , NULL ,
F_27 , V_112 ,
L_20 , V_4 ) ;
if ( V_10 ) {
F_42 ( & V_99 -> V_85 , L_21 , V_10 ) ;
goto V_111;
}
if ( V_4 -> V_16 ) {
int V_52 ;
for ( V_52 = 0 ; V_52 < sizeof( V_113 ) ; V_52 ++ )
if ( V_4 -> V_16 & F_3 ( V_52 ) )
F_44 ( V_52 , V_4 -> V_2 . V_114 ) ;
}
V_10 = F_45 ( & V_4 -> V_2 ,
& V_115 ,
0 ,
V_116 ,
V_117 ) ;
if ( V_10 ) {
F_42 ( & V_99 -> V_85 ,
L_22 ) ;
goto V_111;
}
F_46 ( & V_4 -> V_2 ,
& V_115 ,
V_84 ) ;
}
F_47 ( V_99 , V_4 ) ;
return 0 ;
V_111:
F_48 ( V_5 , V_18 ) ;
F_49 ( & V_4 -> V_2 ) ;
V_110:
F_50 ( V_4 ) ;
return V_10 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_118 ) ;
}
