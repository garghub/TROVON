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
V_10 -> V_18 = F_7 ( V_16 -> V_19 ,
sizeof( struct V_20 ) *
F_4 ( V_10 ) , & V_10 -> V_21 ,
V_17 ) ;
if ( ! V_10 -> V_18 )
return - V_22 ;
memset ( V_10 -> V_18 , 0 ,
sizeof( struct V_20 ) * F_4 ( V_10 ) ) ;
V_10 -> V_23 = F_8 ( sizeof( V_24 ) * F_4 ( V_10 ) , V_17 ) ;
if ( ! V_10 -> V_23 ) {
F_9 ( V_16 -> V_19 , sizeof( struct V_20 )
* F_4 ( V_10 ) , V_10 -> V_18 ,
V_10 -> V_21 ) ;
V_10 -> V_18 = NULL ;
return - V_22 ;
}
return 0 ;
}
static void F_10 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
if ( V_10 -> V_18 ) {
F_9 ( V_16 -> V_19 , sizeof( struct V_20 )
* F_4 ( V_10 ) , V_10 -> V_18 ,
V_10 -> V_21 ) ;
V_10 -> V_18 = NULL ;
}
F_11 ( V_10 -> V_23 ) ;
V_10 -> V_23 = NULL ;
}
static int F_12 ( struct V_15 * V_16 , T_3 V_25 )
{
if ( V_16 -> V_26 )
return 0 ;
V_16 -> V_26 = F_7 ( V_16 -> V_19 ,
4 * V_2 ,
& V_16 -> V_27 ,
V_25 ) ;
if ( ! V_16 -> V_26 )
return - V_22 ;
memset ( V_16 -> V_26 , 0 , 4 * V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_15 * V_16 )
{
V_24 * V_26 ;
T_4 V_27 ;
unsigned long V_17 ;
F_14 ( & V_16 -> V_28 , V_17 ) ;
if ( ! V_16 -> V_26 ) {
F_15 ( & V_16 -> V_28 , V_17 ) ;
return;
}
V_26 = V_16 -> V_26 ;
V_27 = V_16 -> V_27 ;
V_16 -> V_26 = NULL ;
F_15 ( & V_16 -> V_28 , V_17 ) ;
F_9 ( V_16 -> V_19 , 4 * V_2 , V_26 ,
V_27 ) ;
}
static void F_16 ( struct V_15 * V_16 , V_24 V_29 )
{
V_24 V_30 ;
unsigned long V_17 ;
F_14 ( & V_16 -> V_28 , V_17 ) ;
V_30 = F_17 ( V_16 -> V_31 + V_32 ) ;
if ( V_30 & V_33 ) {
F_15 ( & V_16 -> V_28 , V_17 ) ;
return;
}
F_18 ( V_16 -> V_27 , V_16 -> V_31 + V_34 ) ;
V_30 &= ~ V_35 ;
V_30 |= V_29 | V_33 ;
F_19 ( V_16 -> V_19 , L_1 ) ;
F_18 ( V_30 , V_16 -> V_31 + V_32 ) ;
F_15 ( & V_16 -> V_28 , V_17 ) ;
}
static void F_20 ( struct V_15 * V_16 )
{
V_24 V_30 ;
unsigned long V_17 ;
F_14 ( & V_16 -> V_28 , V_17 ) ;
V_30 = F_17 ( V_16 -> V_31 + V_32 ) ;
if ( ! ( V_30 & V_33 ) ) {
F_15 ( & V_16 -> V_28 , V_17 ) ;
return;
}
V_30 &= ~ V_33 ;
F_19 ( V_16 -> V_19 , L_2 ) ;
F_18 ( V_30 , V_16 -> V_31 + V_32 ) ;
F_15 ( & V_16 -> V_28 , V_17 ) ;
}
static void F_21 ( struct V_15 * V_16 , struct V_9 * V_10 ,
int V_36 )
{
struct V_37 * V_38 ;
T_1 V_39 , V_40 , V_4 ;
if ( ! V_16 ) {
F_22 ( L_3 , V_16 ) ;
return;
}
if ( ! V_10 -> V_41 ) {
F_23 ( V_16 -> V_19 , L_4 , V_10 -> V_41 ) ;
return;
}
if ( ! V_16 -> V_26 ) {
F_23 ( V_16 -> V_19 , L_5 ,
V_16 -> V_26 ) ;
return;
}
V_38 = V_10 -> V_41 ;
V_4 = F_5 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
V_39 = F_1 ( V_10 -> V_42 ) ;
else
V_39 = 0 ;
V_40 = V_39 ;
do {
if ( V_36 )
V_16 -> V_26 [ V_40 ] |= 1 << V_38 -> V_43 ;
else
V_16 -> V_26 [ V_40 ] &= ~ ( 1 << V_38 -> V_43 ) ;
V_40 = ( V_40 + V_4 ) & ( V_2 - 1 ) ;
} while ( V_40 != V_39 );
if ( ! V_36 )
return;
V_38 -> V_44 = 0 ;
if ( V_38 -> V_5 == V_6 && V_10 -> V_14 ) {
V_40 = 1 ;
V_4 = ( 8 + V_10 -> V_14 - 1 ) / V_10 -> V_14 ;
for ( V_39 = 0 ; V_39 < V_4 ; V_39 ++ ) {
V_38 -> V_44 |= V_40 ;
V_40 = V_40 << V_10 -> V_14 ;
}
} else {
V_38 -> V_44 = 0xff ;
}
}
static void F_24 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_41 ;
if ( F_25 ( V_10 ) ) {
if ( V_16 -> V_45 -> V_46 > 0 )
V_16 -> V_47 ++ ;
else
V_16 -> V_48 -- ;
} else {
F_21 ( V_16 , V_10 , 0 ) ;
}
if ( V_38 -> V_10 ) {
if ( ! F_26 ( & V_38 -> V_49 ) )
F_27 ( & V_38 -> V_49 ) ;
F_28 ( V_16 , V_38 ) ;
F_29 ( & V_38 -> V_49 , & V_16 -> V_50 ) ;
V_38 -> V_10 = NULL ;
}
V_10 -> V_41 = NULL ;
V_10 -> V_51 = 0 ;
if ( V_10 -> V_18 )
memset ( V_10 -> V_18 , 0 , sizeof( struct V_20 ) *
F_4 ( V_10 ) ) ;
}
int F_30 ( struct V_15 * V_16 , struct V_9 * V_10 ,
T_3 V_25 )
{
int V_52 ;
if ( V_10 -> V_53 ) {
F_23 ( V_16 -> V_19 ,
L_6 ) ;
V_52 = - V_54 ;
goto V_55;
}
V_52 = F_6 ( V_16 , V_10 , V_25 ) ;
if ( V_52 )
goto V_55;
if ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_56 ) {
if ( ! V_16 -> V_26 ) {
V_52 = F_12 ( V_16 , V_25 ) ;
if ( V_52 )
goto V_57;
F_16 ( V_16 , V_58 ) ;
}
}
V_10 -> V_51 = 0 ;
return 0 ;
V_57:
F_10 ( V_16 , V_10 ) ;
V_55:
return V_52 ;
}
void F_31 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
F_10 ( V_16 , V_10 ) ;
if ( V_10 -> V_41 )
F_24 ( V_16 , V_10 ) ;
if ( ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_56 ) &&
( V_16 -> V_45 -> V_46 > 0 ||
! V_16 -> V_59 ) && V_16 -> V_26 ) {
F_20 ( V_16 ) ;
F_13 ( V_16 ) ;
}
}
static T_2 F_32 ( struct V_9 * V_10 , T_1 V_60 )
{
if ( V_10 -> V_13 == V_6 )
return ( V_60 & ( ( V_7 / 8 ) - 1 ) ) * 8 ;
else
return V_60 & ( V_8 - 1 ) ;
}
static T_1 F_33 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 * V_61 )
{
T_1 V_1 ;
V_16 -> V_62 = F_34 ( V_16 ) ;
if ( V_10 -> V_13 == V_6 ) {
if ( F_35 ( V_16 -> V_62 ) >= 5 ) {
* V_61 = 2 * 8 ;
V_1 = F_36 ( V_16 -> V_62 ,
* V_61 ) ;
} else {
* V_61 = 1 * 8 ;
V_1 = F_36 ( V_16 -> V_62 ,
* V_61 ) ;
}
V_1 = F_37 ( V_1 ) ;
} else {
* V_61 = 1 ;
V_1 = F_36 ( V_16 -> V_62 , 2 ) ;
}
return V_1 ;
}
static T_1 F_38 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
T_1 V_1 , V_63 , V_64 , V_61 ;
if ( V_10 -> V_41 ) {
V_1 = F_33 ( V_16 , V_10 , & V_61 ) ;
V_64 = F_1 ( V_1 ) ;
V_63 = ( V_2 +
F_1 ( V_10 -> V_42 ) - V_64 )
% F_5 ( V_10 ) ;
V_63 = ( V_63 + V_64 ) % V_2 ;
} else {
V_10 -> V_42 = F_33 ( V_16 , V_10 ,
& V_61 ) ;
V_63 = F_1 ( V_10 -> V_42 ) ;
}
V_10 -> V_65 = V_10 -> V_66 = F_32 ( V_10 , V_63 ) ;
return V_61 ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_67 * V_68 ,
struct V_9 * V_10 , V_24 V_69 ,
T_1 V_3 )
{
struct V_20 * V_70 = & V_10 -> V_18 [ V_3 ] ;
struct V_71 * V_72 ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_72 = & V_68 -> V_73 -> V_74 [ V_68 -> V_75 ] ;
if ( V_72 -> V_76 > V_69 )
V_10 -> V_23 [ V_3 ] = V_69 ;
else
V_10 -> V_23 [ V_3 ] = V_72 -> V_76 ;
V_70 -> V_77 = ( V_24 ) ( V_68 -> V_73 -> V_78 + V_72 -> V_79 ) ;
V_70 -> V_80 = V_10 -> V_23 [ V_3 ] << V_81 &
V_82 ;
#ifdef F_40
if ( V_68 -> V_75 == V_68 -> V_73 -> V_83 )
V_70 -> V_80 |= V_84 ;
#endif
V_10 -> V_51 ++ ;
V_68 -> V_75 ++ ;
}
static void F_41 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 V_61 )
{
struct V_67 * V_68 ;
V_24 V_69 ;
T_1 V_3 , V_4 , V_85 , V_86 = 0 ;
V_3 = V_10 -> V_66 ;
V_4 = V_10 -> V_14 ;
V_85 = 0 ;
if ( V_10 -> V_14 ) {
V_86 = ( F_4 ( V_10 ) + V_10 -> V_14 - 1 ) /
V_10 -> V_14 ;
if ( V_61 && ! V_10 -> V_41 )
V_86 -= V_61 / V_10 -> V_14 ;
}
V_69 = V_10 -> V_13 == V_6 ?
V_87 : V_88 ;
F_42 (qtd, &qh->qtd_list, qtd_list_entry) {
while ( V_10 -> V_51 < V_86 && V_68 -> V_75 <
V_68 -> V_73 -> V_83 ) {
if ( V_85 > 1 )
V_10 -> V_18 [ V_85 - 1 ] . V_80 |= V_89 ;
F_39 ( V_16 , V_68 , V_10 ,
V_69 , V_3 ) ;
V_3 = F_2 ( V_3 , V_4 , V_10 -> V_13 ) ;
V_85 ++ ;
}
V_68 -> V_90 = 1 ;
}
V_10 -> V_66 = V_3 ;
#ifdef F_40
if ( V_10 -> V_51 == V_86 ) {
V_3 = F_3 ( V_10 -> V_66 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_18 [ V_3 ] . V_80 |= V_84 ;
}
#else
if ( V_85 > V_91 )
V_3 = F_3 ( V_3 , V_4 * ( ( V_10 -> V_51 + 1 ) / 2 ) ,
V_10 -> V_13 ) ;
else
V_3 = F_3 ( V_10 -> V_66 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_18 [ V_3 ] . V_80 |= V_84 ;
#endif
if ( V_85 ) {
V_10 -> V_18 [ V_85 - 1 ] . V_80 |= V_89 ;
if ( V_85 > 1 )
V_10 -> V_18 [ 0 ] . V_80 |= V_89 ;
}
}
static void F_43 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_67 * V_68 , struct V_9 * V_10 ,
int V_85 )
{
struct V_20 * V_70 = & V_10 -> V_18 [ V_85 ] ;
int V_92 = V_38 -> V_93 ;
if ( V_92 > V_94 - ( V_38 -> V_95 - 1 ) )
V_92 = V_94 - ( V_38 -> V_95 - 1 ) ;
if ( V_38 -> V_96 ) {
int V_97 ;
if ( V_92 > 0 && V_38 -> V_95 )
V_97 = ( V_92 + V_38 -> V_95 - 1 )
/ V_38 -> V_95 ;
else
V_97 = 1 ;
V_92 = V_97 * V_38 -> V_95 ;
}
V_70 -> V_80 = V_92 << V_98 & V_99 ;
V_10 -> V_23 [ V_85 ] = V_92 ;
if ( V_10 -> V_11 == V_100 &&
V_68 -> V_101 == V_102 )
V_70 -> V_80 |= V_103 ;
V_70 -> V_77 = ( V_24 ) V_38 -> V_104 ;
if ( V_92 > V_38 -> V_93 ) {
V_38 -> V_93 = 0 ;
} else {
V_38 -> V_104 += V_92 ;
V_38 -> V_93 -= V_92 ;
}
}
static void F_44 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_67 * V_68 ;
struct V_37 * V_38 = V_10 -> V_41 ;
int V_85 = 0 ;
F_19 ( V_16 -> V_19 , L_7 , V_105 , V_10 ,
( unsigned long ) V_38 -> V_104 , V_38 -> V_93 ) ;
F_42 (qtd, &qh->qtd_list, qtd_list_entry) {
F_19 ( V_16 -> V_19 , L_8 , V_68 ) ;
if ( V_85 ) {
V_38 -> V_104 = V_68 -> V_73 -> V_78 +
V_68 -> V_73 -> V_106 ;
V_38 -> V_93 = V_68 -> V_73 -> V_76 -
V_68 -> V_73 -> V_106 ;
F_19 ( V_16 -> V_19 , L_9 ,
( unsigned long ) V_38 -> V_104 , V_38 -> V_93 ) ;
}
V_68 -> V_85 = 0 ;
do {
if ( V_85 > 1 ) {
V_10 -> V_18 [ V_85 - 1 ] . V_80 |= V_89 ;
F_19 ( V_16 -> V_19 ,
L_10 ,
V_85 - 1 ,
& V_10 -> V_18 [ V_85 - 1 ] ) ;
}
F_43 ( V_16 , V_38 , V_68 , V_10 , V_85 ) ;
F_19 ( V_16 -> V_19 ,
L_11 ,
V_85 , & V_10 -> V_18 [ V_85 ] ,
V_10 -> V_18 [ V_85 ] . V_77 ,
V_10 -> V_18 [ V_85 ] . V_80 ) ;
V_68 -> V_85 ++ ;
V_85 ++ ;
} while ( V_38 -> V_93 > 0 &&
V_85 != V_8 );
F_19 ( V_16 -> V_19 , L_12 , V_85 ) ;
V_68 -> V_90 = 1 ;
if ( V_10 -> V_11 == V_100 )
break;
if ( V_85 == V_8 )
break;
}
if ( V_85 ) {
V_10 -> V_18 [ V_85 - 1 ] . V_80 |=
V_84 | V_107 | V_89 ;
F_19 ( V_16 -> V_19 , L_13 ,
V_85 - 1 , & V_10 -> V_18 [ V_85 - 1 ] ) ;
if ( V_85 > 1 ) {
V_10 -> V_18 [ 0 ] . V_80 |= V_89 ;
F_19 ( V_16 -> V_19 , L_14 ,
& V_10 -> V_18 [ 0 ] ) ;
}
V_38 -> V_51 = V_85 ;
}
}
void F_45 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_41 ;
T_1 V_61 = 0 ;
switch ( V_38 -> V_11 ) {
case V_100 :
case V_108 :
F_44 ( V_16 , V_10 ) ;
F_46 ( V_16 , V_38 ) ;
break;
case V_56 :
F_44 ( V_16 , V_10 ) ;
F_21 ( V_16 , V_10 , 1 ) ;
F_46 ( V_16 , V_38 ) ;
break;
case V_12 :
if ( ! V_10 -> V_51 )
V_61 = F_38 ( V_16 , V_10 ) ;
F_41 ( V_16 , V_10 , V_61 ) ;
if ( ! V_38 -> V_109 ) {
F_21 ( V_16 , V_10 , 1 ) ;
V_38 -> V_51 = F_4 ( V_10 ) ;
F_46 ( V_16 , V_38 ) ;
}
break;
default:
break;
}
}
static int F_47 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_67 * V_68 ,
struct V_9 * V_10 , T_1 V_3 )
{
struct V_20 * V_70 = & V_10 -> V_18 [ V_3 ] ;
struct V_71 * V_72 ;
T_1 V_110 = 0 ;
int V_111 = 0 ;
if ( ! V_68 -> V_73 )
return - V_54 ;
V_72 = & V_68 -> V_73 -> V_74 [ V_68 -> V_75 ] ;
V_70 -> V_77 = ( V_24 ) ( V_68 -> V_73 -> V_78 + V_72 -> V_79 ) ;
if ( V_38 -> V_96 )
V_110 = ( V_70 -> V_80 & V_82 ) >>
V_81 ;
if ( ( V_70 -> V_80 & V_112 ) == V_113 ) {
V_68 -> V_73 -> V_114 ++ ;
V_72 -> V_106 = V_10 -> V_23 [ V_3 ] - V_110 ;
V_72 -> V_80 = - V_115 ;
} else {
V_72 -> V_106 = V_10 -> V_23 [ V_3 ] - V_110 ;
V_72 -> V_80 = 0 ;
}
if ( ++ V_68 -> V_116 == V_68 -> V_73 -> V_83 ) {
F_48 ( V_16 , V_68 , 0 ) ;
F_49 ( V_16 , V_68 , V_10 ) ;
if ( V_38 -> V_117 == V_118 )
return - 1 ;
V_111 = V_119 ;
}
V_10 -> V_51 -- ;
if ( V_70 -> V_80 & V_84 )
V_111 = V_120 ;
return V_111 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
enum V_121 V_117 )
{
struct V_71 * V_72 ;
struct V_67 * V_68 , * V_122 ;
struct V_9 * V_10 ;
T_1 V_3 ;
int V_111 ;
V_10 = V_38 -> V_10 ;
V_3 = V_10 -> V_65 ;
if ( V_38 -> V_117 == V_118 ) {
F_42 (qtd, &qh->qtd_list, qtd_list_entry)
V_68 -> V_90 = 0 ;
return;
}
if ( V_117 == V_123 ||
V_117 == V_124 ) {
int V_125 = V_117 == V_123 ?
- V_126 : - V_127 ;
F_51 (qtd, qtd_tmp, &qh->qtd_list,
qtd_list_entry) {
if ( V_68 -> V_73 ) {
for ( V_3 = 0 ; V_3 < V_68 -> V_73 -> V_83 ;
V_3 ++ ) {
V_72 = & V_68 -> V_73 -> V_74 [ V_3 ] ;
V_72 -> V_80 = V_125 ;
}
F_48 ( V_16 , V_68 , V_125 ) ;
}
F_49 ( V_16 , V_68 , V_10 ) ;
}
return;
}
F_51 (qtd, qtd_tmp, &qh->qtd_list, qtd_list_entry) {
if ( ! V_68 -> V_90 )
break;
do {
V_111 = F_47 ( V_16 , V_38 , V_68 , V_10 ,
V_3 ) ;
if ( V_111 < 0 )
return;
V_3 = F_2 ( V_3 , V_10 -> V_14 ,
V_38 -> V_5 ) ;
if ( V_111 == V_120 )
goto V_128;
if ( V_111 == V_119 )
break;
} while ( V_3 != V_10 -> V_65 );
}
V_128:
V_10 -> V_65 = V_3 ;
}
static int F_52 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_67 * V_68 ,
struct V_20 * V_70 ,
enum V_121 V_117 ,
V_24 V_23 , int * V_129 )
{
struct V_130 * V_73 = V_68 -> V_73 ;
T_1 V_110 = 0 ;
if ( V_38 -> V_96 )
V_110 = ( V_70 -> V_80 & V_99 ) >>
V_98 ;
F_19 ( V_16 -> V_19 , L_15 , V_110 , V_73 ) ;
if ( V_117 == V_123 ) {
F_23 ( V_16 -> V_19 , L_16 ) ;
V_73 -> V_80 = - V_126 ;
return 1 ;
}
if ( ( V_70 -> V_80 & V_112 ) == V_113 ) {
switch ( V_117 ) {
case V_131 :
F_19 ( V_16 -> V_19 , L_17 ) ;
V_73 -> V_80 = - V_132 ;
break;
case V_124 :
F_23 ( V_16 -> V_19 , L_18 ) ;
V_73 -> V_80 = - V_127 ;
break;
case V_133 :
F_23 ( V_16 -> V_19 , L_19 ) ;
V_73 -> V_80 = - V_115 ;
break;
default:
F_23 ( V_16 -> V_19 ,
L_20 ,
V_105 , V_117 ) ;
break;
}
return 1 ;
}
if ( V_70 -> V_80 & V_89 ) {
F_19 ( V_16 -> V_19 ,
L_21 ,
V_38 -> V_43 ) ;
return 0 ;
}
if ( V_38 -> V_11 == V_100 ) {
if ( V_68 -> V_101 == V_134 ) {
V_73 -> V_106 += V_23 - V_110 ;
if ( V_110 || V_73 -> V_106 >= V_73 -> V_76 ) {
* V_129 = 1 ;
}
} else if ( V_68 -> V_101 == V_135 ) {
V_73 -> V_80 = 0 ;
* V_129 = 1 ;
}
} else {
V_73 -> V_106 += V_23 - V_110 ;
F_19 ( V_16 -> V_19 , L_22 , V_73 -> V_76 ,
V_73 -> V_106 ) ;
if ( V_110 || V_73 -> V_106 >= V_73 -> V_76 ) {
V_73 -> V_80 = 0 ;
* V_129 = 1 ;
}
}
return 0 ;
}
static int F_53 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
int V_136 , struct V_67 * V_68 ,
int V_137 ,
enum V_121 V_117 ,
int * V_129 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_130 * V_73 = V_68 -> V_73 ;
struct V_20 * V_70 ;
V_24 V_23 ;
int V_138 ;
F_19 ( V_16 -> V_19 , L_23 , V_105 ) ;
if ( ! V_73 )
return - V_54 ;
V_70 = & V_10 -> V_18 [ V_137 ] ;
V_23 = V_10 -> V_23 [ V_137 ] ;
F_19 ( V_16 -> V_19 ,
L_24 ,
V_68 , V_73 , V_137 , V_70 , V_23 ) ;
V_138 = F_52 ( V_16 , V_38 , V_68 , V_70 ,
V_117 , V_23 ,
V_129 ) ;
if ( V_138 || ( * V_129 && V_73 -> V_80 != - V_139 ) ) {
F_48 ( V_16 , V_68 , V_73 -> V_80 ) ;
F_49 ( V_16 , V_68 , V_10 ) ;
F_19 ( V_16 -> V_19 , L_25 ,
V_138 , * V_129 , V_73 -> V_80 ) ;
return V_138 ;
}
if ( V_10 -> V_11 == V_100 ) {
switch ( V_68 -> V_101 ) {
case V_102 :
if ( V_73 -> V_76 > 0 )
V_68 -> V_101 = V_134 ;
else
V_68 -> V_101 = V_135 ;
F_19 ( V_16 -> V_19 ,
L_26 ) ;
break;
case V_134 :
if ( * V_129 ) {
V_68 -> V_101 = V_135 ;
F_19 ( V_16 -> V_19 ,
L_27 ) ;
} else if ( V_137 + 1 == V_68 -> V_85 ) {
F_54 ( V_16 , V_38 , V_136 ,
V_68 ) ;
}
break;
default:
break;
}
}
return 0 ;
}
static void F_55 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
int V_136 ,
enum V_121 V_117 )
{
struct V_140 * V_141 , * V_122 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_67 * V_68 = NULL ;
int V_129 ;
int V_137 = 0 ;
if ( V_38 -> V_117 == V_118 ) {
F_42 (qtd, &qh->qtd_list, qtd_list_entry)
V_68 -> V_90 = 0 ;
return;
}
F_56 (qtd_item, qtd_tmp, &qh->qtd_list) {
int V_39 ;
V_68 = F_57 ( V_141 , struct V_67 , V_142 ) ;
V_129 = 0 ;
for ( V_39 = 0 ; V_39 < V_68 -> V_85 ; V_39 ++ ) {
if ( F_53 ( V_16 , V_38 , V_136 , V_68 ,
V_137 , V_117 ,
& V_129 ) ) {
V_68 = NULL ;
break;
}
V_137 ++ ;
}
}
if ( V_10 -> V_11 != V_100 ) {
if ( V_117 == V_131 )
V_10 -> V_143 = V_144 ;
else if ( V_68 )
F_54 ( V_16 , V_38 , V_136 , V_68 ) ;
}
if ( V_117 == V_145 ) {
if ( V_38 -> V_146 & V_147 ) {
V_10 -> V_148 = 1 ;
}
}
}
void F_58 ( struct V_15 * V_16 ,
struct V_37 * V_38 , int V_136 ,
enum V_121 V_117 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
int V_149 = 0 ;
enum V_150 V_151 ;
if ( V_38 -> V_11 == V_12 ) {
F_50 ( V_16 , V_38 , V_117 ) ;
if ( V_117 != V_145 ||
F_26 ( & V_10 -> V_152 ) ) {
if ( V_117 == V_145 )
F_59 ( V_16 , V_38 , V_117 ) ;
F_24 ( V_16 , V_10 ) ;
F_60 ( V_16 , V_10 ) ;
} else {
F_61 ( & V_10 -> V_153 ,
& V_16 -> V_154 ) ;
V_149 = 1 ;
}
} else {
F_55 ( V_16 , V_38 , V_136 ,
V_117 ) ;
F_24 ( V_16 , V_10 ) ;
F_60 ( V_16 , V_10 ) ;
if ( ! F_26 ( & V_10 -> V_152 ) ) {
F_62 ( V_16 , V_10 ) ;
}
}
V_151 = F_63 ( V_16 ) ;
if ( V_151 != V_155 || V_149 ) {
if ( V_149 ) {
if ( V_151 == V_155 )
V_151 = V_156 ;
else if ( V_151 == V_157 )
V_151 = V_158 ;
}
F_64 ( V_16 , V_151 ) ;
}
}
