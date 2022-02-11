static T_1 F_1 ( T_1 V_1 )
{
return V_1 & ( V_2 - 1 ) ;
}
static T_1 F_2 ( T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
return ( V_3 + V_4 ) &
( ( V_5 == V_6 ? V_7 :
V_8 ) - 1 ) ;
}
static T_1 F_3 ( T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
return ( V_3 - V_4 ) &
( ( V_5 == V_6 ? V_7 :
V_8 ) - 1 ) ;
}
static T_1 F_4 ( struct V_9 * V_10 )
{
return ( V_10 -> V_11 == V_12 &&
V_10 -> V_13 == V_6 ) ?
V_7 : V_8 ;
}
static T_1 F_5 ( struct V_9 * V_10 )
{
return V_10 -> V_13 == V_6 ?
( V_10 -> V_14 + 8 - 1 ) / 8 : V_10 -> V_14 ;
}
static int F_6 ( struct V_15 * V_16 , struct V_9 * V_10 ,
T_3 V_17 )
{
struct V_18 * V_19 ;
if ( V_10 -> V_11 == V_12
&& V_10 -> V_13 == V_6 )
V_19 = V_16 -> V_20 ;
else
V_19 = V_16 -> V_21 ;
V_10 -> V_22 = sizeof( struct V_23 ) *
F_4 ( V_10 ) ;
V_10 -> V_24 = F_7 ( V_19 , V_17 | V_25 ) ;
if ( ! V_10 -> V_24 )
return - V_26 ;
V_10 -> V_27 = F_8 ( V_16 -> V_28 , V_10 -> V_24 ,
V_10 -> V_22 ,
V_29 ) ;
V_10 -> V_30 = F_9 ( sizeof( V_31 ) * F_4 ( V_10 ) , V_17 ) ;
if ( ! V_10 -> V_30 ) {
F_10 ( V_16 -> V_28 , V_10 -> V_27 ,
V_10 -> V_22 ,
V_32 ) ;
F_11 ( V_19 , V_10 -> V_24 ) ;
V_10 -> V_24 = NULL ;
return - V_26 ;
}
return 0 ;
}
static void F_12 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
struct V_18 * V_19 ;
if ( V_10 -> V_11 == V_12
&& V_10 -> V_13 == V_6 )
V_19 = V_16 -> V_20 ;
else
V_19 = V_16 -> V_21 ;
if ( V_10 -> V_24 ) {
F_10 ( V_16 -> V_28 , V_10 -> V_27 ,
V_10 -> V_22 , V_32 ) ;
F_11 ( V_19 , V_10 -> V_24 ) ;
V_10 -> V_24 = NULL ;
}
F_13 ( V_10 -> V_30 ) ;
V_10 -> V_30 = NULL ;
}
static int F_14 ( struct V_15 * V_16 , T_3 V_33 )
{
if ( V_16 -> V_34 )
return 0 ;
V_16 -> V_35 = 4 * V_2 ;
V_16 -> V_34 = F_9 ( V_16 -> V_35 , V_36 | V_25 ) ;
if ( ! V_16 -> V_34 )
return - V_26 ;
V_16 -> V_37 = F_8 ( V_16 -> V_28 , V_16 -> V_34 ,
V_16 -> V_35 ,
V_29 ) ;
return 0 ;
}
static void F_15 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
F_16 ( & V_16 -> V_38 , V_17 ) ;
if ( ! V_16 -> V_34 ) {
F_17 ( & V_16 -> V_38 , V_17 ) ;
return;
}
F_10 ( V_16 -> V_28 , V_16 -> V_37 ,
V_16 -> V_35 , V_32 ) ;
F_13 ( V_16 -> V_34 ) ;
V_16 -> V_34 = NULL ;
F_17 ( & V_16 -> V_38 , V_17 ) ;
}
static void F_18 ( struct V_15 * V_16 , V_31 V_39 )
{
V_31 V_40 ;
unsigned long V_17 ;
F_16 ( & V_16 -> V_38 , V_17 ) ;
V_40 = F_19 ( V_16 -> V_41 + V_42 ) ;
if ( V_40 & V_43 ) {
F_17 ( & V_16 -> V_38 , V_17 ) ;
return;
}
F_20 ( V_16 -> V_37 , V_16 -> V_41 + V_44 ) ;
V_40 &= ~ V_45 ;
V_40 |= V_39 | V_43 ;
F_21 ( V_16 -> V_28 , L_1 ) ;
F_20 ( V_40 , V_16 -> V_41 + V_42 ) ;
F_17 ( & V_16 -> V_38 , V_17 ) ;
}
static void F_22 ( struct V_15 * V_16 )
{
V_31 V_40 ;
unsigned long V_17 ;
F_16 ( & V_16 -> V_38 , V_17 ) ;
V_40 = F_19 ( V_16 -> V_41 + V_42 ) ;
if ( ! ( V_40 & V_43 ) ) {
F_17 ( & V_16 -> V_38 , V_17 ) ;
return;
}
V_40 &= ~ V_43 ;
F_21 ( V_16 -> V_28 , L_2 ) ;
F_20 ( V_40 , V_16 -> V_41 + V_42 ) ;
F_17 ( & V_16 -> V_38 , V_17 ) ;
}
static void F_23 ( struct V_15 * V_16 , struct V_9 * V_10 ,
int V_46 )
{
struct V_47 * V_48 ;
T_1 V_49 , V_50 , V_4 ;
if ( ! V_16 ) {
F_24 ( L_3 , V_16 ) ;
return;
}
if ( ! V_10 -> V_51 ) {
F_25 ( V_16 -> V_28 , L_4 , V_10 -> V_51 ) ;
return;
}
if ( ! V_16 -> V_34 ) {
F_25 ( V_16 -> V_28 , L_5 ,
V_16 -> V_34 ) ;
return;
}
V_48 = V_10 -> V_51 ;
V_4 = F_5 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
V_49 = F_1 ( V_10 -> V_52 ) ;
else
V_49 = 0 ;
V_50 = V_49 ;
do {
if ( V_46 )
V_16 -> V_34 [ V_50 ] |= 1 << V_48 -> V_53 ;
else
V_16 -> V_34 [ V_50 ] &= ~ ( 1 << V_48 -> V_53 ) ;
V_50 = ( V_50 + V_4 ) & ( V_2 - 1 ) ;
} while ( V_50 != V_49 );
F_26 ( V_16 -> V_28 ,
V_16 -> V_37 ,
V_16 -> V_35 ,
V_29 ) ;
if ( ! V_46 )
return;
V_48 -> V_54 = 0 ;
if ( V_48 -> V_5 == V_6 && V_10 -> V_14 ) {
V_50 = 1 ;
V_4 = ( 8 + V_10 -> V_14 - 1 ) / V_10 -> V_14 ;
for ( V_49 = 0 ; V_49 < V_4 ; V_49 ++ ) {
V_48 -> V_54 |= V_50 ;
V_50 = V_50 << V_10 -> V_14 ;
}
} else {
V_48 -> V_54 = 0xff ;
}
}
static void F_27 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_47 * V_48 = V_10 -> V_51 ;
if ( F_28 ( V_10 ) ) {
if ( V_16 -> V_55 -> V_56 > 0 )
V_16 -> V_57 ++ ;
else
V_16 -> V_58 -- ;
} else {
F_23 ( V_16 , V_10 , 0 ) ;
V_16 -> V_57 ++ ;
}
if ( V_48 -> V_10 ) {
if ( ! F_29 ( & V_48 -> V_59 ) )
F_30 ( & V_48 -> V_59 ) ;
F_31 ( V_16 , V_48 ) ;
F_32 ( & V_48 -> V_59 , & V_16 -> V_60 ) ;
V_48 -> V_10 = NULL ;
}
V_10 -> V_51 = NULL ;
V_10 -> V_61 = 0 ;
if ( V_10 -> V_24 )
memset ( V_10 -> V_24 , 0 , sizeof( struct V_23 ) *
F_4 ( V_10 ) ) ;
}
int F_33 ( struct V_15 * V_16 , struct V_9 * V_10 ,
T_3 V_33 )
{
int V_62 ;
if ( V_10 -> V_63 ) {
F_25 ( V_16 -> V_28 ,
L_6 ) ;
V_62 = - V_64 ;
goto V_65;
}
V_62 = F_6 ( V_16 , V_10 , V_33 ) ;
if ( V_62 )
goto V_65;
if ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_66 ) {
if ( ! V_16 -> V_34 ) {
V_62 = F_14 ( V_16 , V_33 ) ;
if ( V_62 )
goto V_67;
F_18 ( V_16 , V_68 ) ;
}
}
V_10 -> V_61 = 0 ;
return 0 ;
V_67:
F_12 ( V_16 , V_10 ) ;
V_65:
return V_62 ;
}
void F_34 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
unsigned long V_17 ;
F_12 ( V_16 , V_10 ) ;
F_16 ( & V_16 -> V_38 , V_17 ) ;
if ( V_10 -> V_51 )
F_27 ( V_16 , V_10 ) ;
F_17 ( & V_16 -> V_38 , V_17 ) ;
if ( ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_66 ) &&
( V_16 -> V_55 -> V_56 > 0 ||
! V_16 -> V_69 ) && V_16 -> V_34 ) {
F_22 ( V_16 ) ;
F_15 ( V_16 ) ;
}
}
static T_2 F_35 ( struct V_9 * V_10 , T_1 V_70 )
{
if ( V_10 -> V_13 == V_6 )
return ( V_70 & ( ( V_7 / 8 ) - 1 ) ) * 8 ;
else
return V_70 & ( V_8 - 1 ) ;
}
static T_1 F_36 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 * V_71 )
{
T_1 V_1 ;
V_16 -> V_72 = F_37 ( V_16 ) ;
if ( V_10 -> V_13 == V_6 ) {
if ( F_38 ( V_16 -> V_72 ) >= 5 ) {
* V_71 = 2 * 8 ;
V_1 = F_39 ( V_16 -> V_72 ,
* V_71 ) ;
} else {
* V_71 = 1 * 8 ;
V_1 = F_39 ( V_16 -> V_72 ,
* V_71 ) ;
}
V_1 = F_40 ( V_1 ) ;
} else {
* V_71 = 1 ;
V_1 = F_39 ( V_16 -> V_72 , 2 ) ;
}
return V_1 ;
}
static T_1 F_41 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
T_1 V_1 , V_73 , V_74 , V_71 ;
if ( V_10 -> V_51 ) {
V_1 = F_36 ( V_16 , V_10 , & V_71 ) ;
V_74 = F_1 ( V_1 ) ;
V_73 = ( V_2 +
F_1 ( V_10 -> V_52 ) -
V_74 ) % F_5 ( V_10 ) ;
V_73 = ( V_73 + V_74 ) % V_2 ;
} else {
V_10 -> V_52 = F_36 ( V_16 , V_10 ,
& V_71 ) ;
V_73 = F_1 ( V_10 -> V_52 ) ;
}
V_10 -> V_75 = V_10 -> V_76 = F_35 ( V_10 , V_73 ) ;
return V_71 ;
}
static void F_42 ( struct V_15 * V_16 ,
struct V_77 * V_78 ,
struct V_9 * V_10 , V_31 V_79 ,
T_1 V_3 )
{
struct V_23 * V_80 = & V_10 -> V_24 [ V_3 ] ;
struct V_81 * V_82 ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
V_82 = & V_78 -> V_83 -> V_84 [ V_78 -> V_85 ] ;
if ( V_82 -> V_86 > V_79 )
V_10 -> V_30 [ V_3 ] = V_79 ;
else
V_10 -> V_30 [ V_3 ] = V_82 -> V_86 ;
V_80 -> V_87 = ( V_31 ) ( V_78 -> V_83 -> V_88 + V_82 -> V_89 ) ;
V_80 -> V_90 = V_10 -> V_30 [ V_3 ] << V_91 &
V_92 ;
V_80 -> V_90 |= V_93 ;
V_10 -> V_61 ++ ;
V_78 -> V_85 ++ ;
#ifdef F_43
if ( V_78 -> V_85 == V_78 -> V_83 -> V_94 )
V_80 -> V_90 |= V_95 ;
#endif
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 +
( V_3 * sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 V_71 )
{
struct V_77 * V_78 ;
V_31 V_79 ;
T_1 V_3 , V_4 , V_96 = 0 , V_97 = 0 ;
T_1 V_98 ;
T_1 V_99 ;
V_3 = V_10 -> V_76 ;
V_4 = V_10 -> V_14 ;
V_16 -> V_72 = F_37 ( V_16 ) ;
V_98 = F_1 ( V_16 -> V_72 ) ;
V_99 = F_2 ( V_10 -> V_76 , V_4 , V_10 -> V_13 ) ;
if ( F_45 ( V_98 , V_99 ) || ( V_98 == V_99 ) ) {
if ( V_4 < 32 ) {
F_21 ( V_16 -> V_28 ,
L_7 ) ;
V_10 -> V_76 = F_2 ( V_98 , V_4 ,
V_10 -> V_13 ) ;
V_3 = V_10 -> V_76 ;
}
}
if ( V_10 -> V_14 ) {
V_97 = ( F_4 ( V_10 ) + V_10 -> V_14 - 1 ) /
V_10 -> V_14 ;
if ( V_71 && ! V_10 -> V_51 )
V_97 -= V_71 / V_10 -> V_14 ;
}
V_79 = V_10 -> V_13 == V_6 ?
V_100 : V_101 ;
F_46 (qtd, &qh->qtd_list, qtd_list_entry) {
if ( V_78 -> V_102 &&
V_78 -> V_85 ==
V_78 -> V_83 -> V_94 )
continue;
V_78 -> V_103 = V_3 ;
while ( V_10 -> V_61 < V_97 && V_78 -> V_85 <
V_78 -> V_83 -> V_94 ) {
F_42 ( V_16 , V_78 , V_10 ,
V_79 , V_3 ) ;
V_3 = F_2 ( V_3 , V_4 , V_10 -> V_13 ) ;
V_96 ++ ;
}
V_78 -> V_104 = V_3 ;
V_78 -> V_102 = 1 ;
}
V_10 -> V_76 = V_3 ;
#ifdef F_43
if ( V_10 -> V_61 == V_97 ) {
V_3 = F_3 ( V_10 -> V_76 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_24 [ V_3 ] . V_90 |= V_95 ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 + ( V_3 *
sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
}
#else
if ( V_96 > V_105 )
V_3 = F_3 ( V_3 , V_4 * ( ( V_10 -> V_61 + 1 ) / 2 ) ,
V_10 -> V_13 ) ;
else
V_3 = F_3 ( V_10 -> V_76 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_24 [ V_3 ] . V_90 |= V_95 ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 +
( V_3 * sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
#endif
}
static void F_47 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
struct V_77 * V_78 , struct V_9 * V_10 ,
int V_96 )
{
struct V_23 * V_80 = & V_10 -> V_24 [ V_96 ] ;
int V_106 = V_48 -> V_107 ;
if ( V_106 > V_108 - ( V_48 -> V_109 - 1 ) )
V_106 = V_108 - ( V_48 -> V_109 - 1 ) ;
if ( V_48 -> V_110 ) {
int V_111 ;
if ( V_106 > 0 && V_48 -> V_109 )
V_111 = ( V_106 + V_48 -> V_109 - 1 )
/ V_48 -> V_109 ;
else
V_111 = 1 ;
V_106 = V_111 * V_48 -> V_109 ;
}
V_80 -> V_90 = V_106 << V_112 & V_113 ;
V_10 -> V_30 [ V_96 ] = V_106 ;
if ( V_10 -> V_11 == V_114 &&
V_78 -> V_115 == V_116 )
V_80 -> V_90 |= V_117 ;
V_80 -> V_87 = ( V_31 ) V_48 -> V_118 ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 +
( V_96 * sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
if ( V_106 > V_48 -> V_107 ) {
V_48 -> V_107 = 0 ;
} else {
V_48 -> V_118 += V_106 ;
V_48 -> V_107 -= V_106 ;
}
}
static void F_48 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_77 * V_78 ;
struct V_47 * V_48 = V_10 -> V_51 ;
int V_96 = 0 ;
F_21 ( V_16 -> V_28 , L_8 , V_119 , V_10 ,
( unsigned long ) V_48 -> V_118 , V_48 -> V_107 ) ;
F_46 (qtd, &qh->qtd_list, qtd_list_entry) {
F_21 ( V_16 -> V_28 , L_9 , V_78 ) ;
if ( V_96 ) {
V_48 -> V_118 = V_78 -> V_83 -> V_88 +
V_78 -> V_83 -> V_120 ;
V_48 -> V_107 = V_78 -> V_83 -> V_86 -
V_78 -> V_83 -> V_120 ;
F_21 ( V_16 -> V_28 , L_10 ,
( unsigned long ) V_48 -> V_118 , V_48 -> V_107 ) ;
}
V_78 -> V_96 = 0 ;
do {
if ( V_96 > 1 ) {
V_10 -> V_24 [ V_96 - 1 ] . V_90 |= V_93 ;
F_21 ( V_16 -> V_28 ,
L_11 ,
V_96 - 1 ,
& V_10 -> V_24 [ V_96 - 1 ] ) ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 +
( ( V_96 - 1 ) *
sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
}
F_47 ( V_16 , V_48 , V_78 , V_10 , V_96 ) ;
F_21 ( V_16 -> V_28 ,
L_12 ,
V_96 , & V_10 -> V_24 [ V_96 ] ,
V_10 -> V_24 [ V_96 ] . V_87 ,
V_10 -> V_24 [ V_96 ] . V_90 ) ;
V_78 -> V_96 ++ ;
V_96 ++ ;
} while ( V_48 -> V_107 > 0 &&
V_96 != V_8 );
F_21 ( V_16 -> V_28 , L_13 , V_96 ) ;
V_78 -> V_102 = 1 ;
if ( V_10 -> V_11 == V_114 )
break;
if ( V_96 == V_8 )
break;
}
if ( V_96 ) {
V_10 -> V_24 [ V_96 - 1 ] . V_90 |=
V_95 | V_121 | V_93 ;
F_21 ( V_16 -> V_28 , L_14 ,
V_96 - 1 , & V_10 -> V_24 [ V_96 - 1 ] ) ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 + ( V_96 - 1 ) *
sizeof( struct V_23 ) ,
sizeof( struct V_23 ) ,
V_29 ) ;
if ( V_96 > 1 ) {
V_10 -> V_24 [ 0 ] . V_90 |= V_93 ;
F_21 ( V_16 -> V_28 , L_15 ,
& V_10 -> V_24 [ 0 ] ) ;
F_26 ( V_16 -> V_28 ,
V_10 -> V_27 ,
sizeof( struct V_23 ) ,
V_29 ) ;
}
V_48 -> V_61 = V_96 ;
}
}
void F_49 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
struct V_47 * V_48 = V_10 -> V_51 ;
T_1 V_71 = 0 ;
switch ( V_48 -> V_11 ) {
case V_114 :
case V_122 :
F_48 ( V_16 , V_10 ) ;
F_50 ( V_16 , V_48 ) ;
break;
case V_66 :
F_48 ( V_16 , V_10 ) ;
F_23 ( V_16 , V_10 , 1 ) ;
F_50 ( V_16 , V_48 ) ;
break;
case V_12 :
if ( ! V_10 -> V_61 )
V_71 = F_41 ( V_16 , V_10 ) ;
F_44 ( V_16 , V_10 , V_71 ) ;
if ( ! V_48 -> V_123 ) {
F_23 ( V_16 , V_10 , 1 ) ;
V_48 -> V_61 = F_4 ( V_10 ) ;
F_50 ( V_16 , V_48 ) ;
}
break;
default:
break;
}
}
static int F_51 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
struct V_77 * V_78 ,
struct V_9 * V_10 , T_1 V_3 )
{
struct V_23 * V_80 ;
struct V_81 * V_82 ;
T_1 V_124 = 0 ;
int V_125 = 0 ;
if ( ! V_78 -> V_83 )
return - V_64 ;
F_52 ( V_16 -> V_28 , V_10 -> V_27 + ( V_3 *
sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_32 ) ;
V_80 = & V_10 -> V_24 [ V_3 ] ;
V_82 = & V_78 -> V_83 -> V_84 [ V_78 -> V_85 ] ;
V_80 -> V_87 = ( V_31 ) ( V_78 -> V_83 -> V_88 + V_82 -> V_89 ) ;
if ( V_48 -> V_110 )
V_124 = ( V_80 -> V_90 & V_92 ) >>
V_91 ;
if ( ( V_80 -> V_90 & V_126 ) == V_127 ) {
V_78 -> V_83 -> V_128 ++ ;
V_82 -> V_120 = V_10 -> V_30 [ V_3 ] - V_124 ;
V_82 -> V_90 = - V_129 ;
} else {
V_82 -> V_120 = V_10 -> V_30 [ V_3 ] - V_124 ;
V_82 -> V_90 = 0 ;
}
if ( ++ V_78 -> V_130 == V_78 -> V_83 -> V_94 ) {
F_53 ( V_16 , V_78 , 0 ) ;
F_54 ( V_16 , V_78 , V_10 ) ;
if ( V_48 -> V_131 == V_132 )
return - 1 ;
V_125 = V_133 ;
}
V_10 -> V_61 -- ;
if ( V_80 -> V_90 & V_95 )
V_125 = V_134 ;
return V_125 ;
}
static void F_55 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
enum V_135 V_131 )
{
struct V_81 * V_82 ;
struct V_77 * V_78 , * V_136 ;
struct V_9 * V_10 ;
T_1 V_3 ;
int V_125 ;
V_10 = V_48 -> V_10 ;
V_3 = V_10 -> V_75 ;
if ( V_48 -> V_131 == V_132 ) {
F_46 (qtd, &qh->qtd_list, qtd_list_entry)
V_78 -> V_102 = 0 ;
return;
}
if ( V_131 == V_137 ||
V_131 == V_138 ) {
int V_139 = V_131 == V_137 ?
- V_140 : - V_141 ;
F_56 (qtd, qtd_tmp, &qh->qtd_list,
qtd_list_entry) {
if ( V_78 -> V_83 ) {
for ( V_3 = 0 ; V_3 < V_78 -> V_83 -> V_94 ;
V_3 ++ ) {
V_82 = & V_78 -> V_83 -> V_84 [ V_3 ] ;
V_82 -> V_90 = V_139 ;
}
F_53 ( V_16 , V_78 , V_139 ) ;
}
F_54 ( V_16 , V_78 , V_10 ) ;
}
return;
}
F_56 (qtd, qtd_tmp, &qh->qtd_list, qtd_list_entry) {
if ( ! V_78 -> V_102 )
break;
if ( V_3 != V_78 -> V_103 ) {
F_21 ( V_16 -> V_28 ,
L_16 ,
V_3 , V_78 -> V_103 ) ;
V_3 = V_78 -> V_103 ;
}
do {
struct V_77 * V_142 ;
T_1 V_98 ;
V_125 = F_51 ( V_16 , V_48 , V_78 , V_10 ,
V_3 ) ;
if ( V_125 < 0 )
return;
V_3 = F_2 ( V_3 , V_10 -> V_14 ,
V_48 -> V_5 ) ;
if ( ! V_125 )
continue;
if ( V_125 == V_133 )
break;
if ( V_10 -> V_14 >= 32 )
goto V_143;
V_10 -> V_75 = V_3 ;
V_98 = F_1 ( V_16 -> V_72 ) ;
V_142 = F_57 ( & V_10 -> V_144 ,
struct V_77 ,
V_145 ) ;
if ( F_45 ( V_98 ,
V_142 -> V_104 ) )
break;
goto V_143;
} while ( V_3 != V_10 -> V_75 );
}
V_143:
V_10 -> V_75 = V_3 ;
}
static int F_58 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
struct V_77 * V_78 ,
struct V_23 * V_80 ,
enum V_135 V_131 ,
V_31 V_30 , int * V_146 )
{
struct V_147 * V_83 = V_78 -> V_83 ;
T_1 V_124 = 0 ;
if ( V_48 -> V_110 )
V_124 = ( V_80 -> V_90 & V_113 ) >>
V_112 ;
F_21 ( V_16 -> V_28 , L_17 , V_124 , V_83 ) ;
if ( V_131 == V_137 ) {
F_25 ( V_16 -> V_28 , L_18 ) ;
V_83 -> V_90 = - V_140 ;
return 1 ;
}
if ( ( V_80 -> V_90 & V_126 ) == V_127 ) {
switch ( V_131 ) {
case V_148 :
F_21 ( V_16 -> V_28 , L_19 ) ;
V_83 -> V_90 = - V_149 ;
break;
case V_138 :
F_25 ( V_16 -> V_28 , L_20 ) ;
V_83 -> V_90 = - V_141 ;
break;
case V_150 :
F_25 ( V_16 -> V_28 , L_21 ) ;
V_83 -> V_90 = - V_129 ;
break;
default:
F_25 ( V_16 -> V_28 ,
L_22 ,
V_119 , V_131 ) ;
break;
}
return 1 ;
}
if ( V_80 -> V_90 & V_93 ) {
F_21 ( V_16 -> V_28 ,
L_23 ,
V_48 -> V_53 ) ;
return 0 ;
}
if ( V_48 -> V_11 == V_114 ) {
if ( V_78 -> V_115 == V_151 ) {
V_83 -> V_120 += V_30 - V_124 ;
if ( V_124 || V_83 -> V_120 >= V_83 -> V_86 ) {
* V_146 = 1 ;
}
} else if ( V_78 -> V_115 == V_152 ) {
V_83 -> V_90 = 0 ;
* V_146 = 1 ;
}
} else {
V_83 -> V_120 += V_30 - V_124 ;
F_21 ( V_16 -> V_28 , L_24 , V_83 -> V_86 ,
V_83 -> V_120 ) ;
if ( V_124 || V_83 -> V_120 >= V_83 -> V_86 ) {
V_83 -> V_90 = 0 ;
* V_146 = 1 ;
}
}
return 0 ;
}
static int F_59 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
int V_153 , struct V_77 * V_78 ,
int V_154 ,
enum V_135 V_131 ,
int * V_146 )
{
struct V_9 * V_10 = V_48 -> V_10 ;
struct V_147 * V_83 = V_78 -> V_83 ;
struct V_23 * V_80 ;
V_31 V_30 ;
int V_155 ;
F_21 ( V_16 -> V_28 , L_25 , V_119 ) ;
if ( ! V_83 )
return - V_64 ;
F_52 ( V_16 -> V_28 ,
V_10 -> V_27 + ( V_154 *
sizeof( struct V_23 ) ) ,
sizeof( struct V_23 ) ,
V_32 ) ;
V_80 = & V_10 -> V_24 [ V_154 ] ;
V_30 = V_10 -> V_30 [ V_154 ] ;
F_21 ( V_16 -> V_28 ,
L_26 ,
V_78 , V_83 , V_154 , V_80 , V_30 ) ;
V_155 = F_58 ( V_16 , V_48 , V_78 , V_80 ,
V_131 , V_30 ,
V_146 ) ;
if ( V_155 || ( * V_146 && V_83 -> V_90 != - V_156 ) ) {
F_53 ( V_16 , V_78 , V_83 -> V_90 ) ;
F_54 ( V_16 , V_78 , V_10 ) ;
F_21 ( V_16 -> V_28 , L_27 ,
V_155 , * V_146 ) ;
return V_155 ;
}
if ( V_10 -> V_11 == V_114 ) {
switch ( V_78 -> V_115 ) {
case V_116 :
if ( V_83 -> V_86 > 0 )
V_78 -> V_115 = V_151 ;
else
V_78 -> V_115 = V_152 ;
F_21 ( V_16 -> V_28 ,
L_28 ) ;
break;
case V_151 :
if ( * V_146 ) {
V_78 -> V_115 = V_152 ;
F_21 ( V_16 -> V_28 ,
L_29 ) ;
} else if ( V_154 + 1 == V_78 -> V_96 ) {
F_60 ( V_16 , V_48 , V_153 ,
V_78 ) ;
}
break;
default:
break;
}
}
return 0 ;
}
static void F_61 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
int V_153 ,
enum V_135 V_131 )
{
struct V_157 * V_158 , * V_136 ;
struct V_9 * V_10 = V_48 -> V_10 ;
struct V_77 * V_78 = NULL ;
int V_146 ;
int V_154 = 0 ;
if ( V_48 -> V_131 == V_132 ) {
F_46 (qtd, &qh->qtd_list, qtd_list_entry)
V_78 -> V_102 = 0 ;
return;
}
F_62 (qtd_item, qtd_tmp, &qh->qtd_list) {
int V_49 ;
int V_159 ;
V_78 = F_63 ( V_158 , struct V_77 , V_145 ) ;
V_146 = 0 ;
V_159 = V_78 -> V_96 ;
for ( V_49 = 0 ; V_49 < V_159 ; V_49 ++ ) {
if ( F_59 ( V_16 , V_48 , V_153 , V_78 ,
V_154 , V_131 ,
& V_146 ) ) {
V_78 = NULL ;
goto V_143;
}
V_154 ++ ;
}
}
V_143:
if ( V_10 -> V_11 != V_114 ) {
if ( V_131 == V_148 )
V_10 -> V_160 = V_161 ;
else
F_60 ( V_16 , V_48 , V_153 , NULL ) ;
}
if ( V_131 == V_162 ) {
if ( V_48 -> V_163 & V_164 ) {
V_10 -> V_165 = 1 ;
}
}
}
void F_64 ( struct V_15 * V_16 ,
struct V_47 * V_48 , int V_153 ,
enum V_135 V_131 )
{
struct V_9 * V_10 = V_48 -> V_10 ;
int V_166 = 0 ;
enum V_167 V_168 ;
if ( V_48 -> V_11 == V_12 ) {
F_55 ( V_16 , V_48 , V_131 ) ;
if ( V_131 != V_162 ||
F_29 ( & V_10 -> V_144 ) ) {
struct V_77 * V_78 , * V_136 ;
F_56 (qtd, qtd_tmp,
&qh->qtd_list,
qtd_list_entry) {
F_53 ( V_16 , V_78 ,
- V_169 ) ;
F_54 ( V_16 ,
V_78 , V_10 ) ;
}
if ( V_131 == V_162 )
F_65 ( V_16 , V_48 , V_131 ) ;
F_27 ( V_16 , V_10 ) ;
F_66 ( V_16 , V_10 ) ;
} else {
F_67 ( & V_10 -> V_170 ,
& V_16 -> V_171 ) ;
if ( ! V_48 -> V_131 )
V_166 = 1 ;
}
} else {
F_61 ( V_16 , V_48 , V_153 ,
V_131 ) ;
F_27 ( V_16 , V_10 ) ;
F_66 ( V_16 , V_10 ) ;
if ( ! F_29 ( & V_10 -> V_144 ) ) {
F_68 ( V_16 , V_10 ) ;
}
}
V_168 = F_69 ( V_16 ) ;
if ( V_168 != V_172 || V_166 ) {
if ( V_166 ) {
if ( V_168 == V_172 )
V_168 = V_173 ;
else if ( V_168 == V_174 )
V_168 = V_175 ;
}
F_70 ( V_16 , V_168 ) ;
}
}
