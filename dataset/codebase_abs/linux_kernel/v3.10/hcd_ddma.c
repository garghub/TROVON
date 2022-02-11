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
if ( F_25 ( V_10 ) )
V_16 -> V_45 -- ;
else
F_21 ( V_16 , V_10 , 0 ) ;
if ( V_38 -> V_10 ) {
if ( ! F_26 ( & V_38 -> V_46 ) )
F_27 ( & V_38 -> V_46 ) ;
F_28 ( V_16 , V_38 ) ;
F_29 ( & V_38 -> V_46 , & V_16 -> V_47 ) ;
V_38 -> V_10 = NULL ;
}
V_10 -> V_41 = NULL ;
V_10 -> V_48 = 0 ;
if ( V_10 -> V_18 )
memset ( V_10 -> V_18 , 0 , sizeof( struct V_20 ) *
F_4 ( V_10 ) ) ;
}
int F_30 ( struct V_15 * V_16 , struct V_9 * V_10 ,
T_3 V_25 )
{
int V_49 ;
if ( V_10 -> V_50 ) {
F_23 ( V_16 -> V_19 ,
L_6 ) ;
V_49 = - V_51 ;
goto V_52;
}
V_49 = F_6 ( V_16 , V_10 , V_25 ) ;
if ( V_49 )
goto V_52;
if ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_53 ) {
if ( ! V_16 -> V_26 ) {
V_49 = F_12 ( V_16 , V_25 ) ;
if ( V_49 )
goto V_54;
F_16 ( V_16 , V_55 ) ;
}
}
V_10 -> V_48 = 0 ;
return 0 ;
V_54:
F_10 ( V_16 , V_10 ) ;
V_52:
return V_49 ;
}
void F_31 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
F_10 ( V_16 , V_10 ) ;
if ( V_10 -> V_41 )
F_24 ( V_16 , V_10 ) ;
if ( ( V_10 -> V_11 == V_12 ||
V_10 -> V_11 == V_53 ) &&
! V_16 -> V_56 && V_16 -> V_26 ) {
F_20 ( V_16 ) ;
F_13 ( V_16 ) ;
}
}
static T_2 F_32 ( struct V_9 * V_10 , T_1 V_57 )
{
if ( V_10 -> V_13 == V_6 )
return ( V_57 & ( ( V_7 / 8 ) - 1 ) ) * 8 ;
else
return V_57 & ( V_8 - 1 ) ;
}
static T_1 F_33 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 * V_58 )
{
T_1 V_1 ;
V_16 -> V_59 = F_34 ( V_16 ) ;
if ( V_10 -> V_13 == V_6 ) {
if ( F_35 ( V_16 -> V_59 ) >= 5 ) {
* V_58 = 2 * 8 ;
V_1 = F_36 ( V_16 -> V_59 ,
* V_58 ) ;
} else {
* V_58 = 1 * 8 ;
V_1 = F_36 ( V_16 -> V_59 ,
* V_58 ) ;
}
V_1 = F_37 ( V_1 ) ;
} else {
* V_58 = 1 ;
V_1 = F_36 ( V_16 -> V_59 , 2 ) ;
}
return V_1 ;
}
static T_1 F_38 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
T_1 V_1 , V_60 , V_61 , V_58 ;
if ( V_10 -> V_41 ) {
V_1 = F_33 ( V_16 , V_10 , & V_58 ) ;
V_61 = F_1 ( V_1 ) ;
V_60 = ( V_2 +
F_1 ( V_10 -> V_42 ) - V_61 )
% F_5 ( V_10 ) ;
V_60 = ( V_60 + V_61 ) % V_2 ;
} else {
V_10 -> V_42 = F_33 ( V_16 , V_10 ,
& V_58 ) ;
V_60 = F_1 ( V_10 -> V_42 ) ;
}
V_10 -> V_62 = V_10 -> V_63 = F_32 ( V_10 , V_60 ) ;
return V_58 ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_64 * V_65 ,
struct V_9 * V_10 , V_24 V_66 ,
T_1 V_3 )
{
struct V_20 * V_67 = & V_10 -> V_18 [ V_3 ] ;
struct V_68 * V_69 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_69 = & V_65 -> V_70 -> V_71 [ V_65 -> V_72 ] ;
if ( V_69 -> V_73 > V_66 )
V_10 -> V_23 [ V_3 ] = V_66 ;
else
V_10 -> V_23 [ V_3 ] = V_69 -> V_73 ;
V_67 -> V_74 = ( V_24 ) ( V_65 -> V_70 -> V_75 + V_69 -> V_76 ) ;
V_67 -> V_77 = V_10 -> V_23 [ V_3 ] << V_78 &
V_79 ;
#ifdef F_40
if ( V_65 -> V_72 == V_65 -> V_70 -> V_80 )
V_67 -> V_77 |= V_81 ;
#endif
V_10 -> V_48 ++ ;
V_65 -> V_72 ++ ;
}
static void F_41 ( struct V_15 * V_16 ,
struct V_9 * V_10 , T_1 V_58 )
{
struct V_64 * V_65 ;
V_24 V_66 ;
T_1 V_3 , V_4 , V_82 , V_83 = 0 ;
V_3 = V_10 -> V_63 ;
V_4 = V_10 -> V_14 ;
V_82 = 0 ;
if ( V_10 -> V_14 ) {
V_83 = ( F_4 ( V_10 ) + V_10 -> V_14 - 1 ) /
V_10 -> V_14 ;
if ( V_58 && ! V_10 -> V_41 )
V_83 -= V_58 / V_10 -> V_14 ;
}
V_66 = V_10 -> V_13 == V_6 ?
V_84 : V_85 ;
F_42 (qtd, &qh->qtd_list, qtd_list_entry) {
while ( V_10 -> V_48 < V_83 && V_65 -> V_72 <
V_65 -> V_70 -> V_80 ) {
if ( V_82 > 1 )
V_10 -> V_18 [ V_82 - 1 ] . V_77 |= V_86 ;
F_39 ( V_16 , V_65 , V_10 ,
V_66 , V_3 ) ;
V_3 = F_2 ( V_3 , V_4 , V_10 -> V_13 ) ;
V_82 ++ ;
}
V_65 -> V_87 = 1 ;
}
V_10 -> V_63 = V_3 ;
#ifdef F_40
if ( V_10 -> V_48 == V_83 ) {
V_3 = F_3 ( V_10 -> V_63 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_18 [ V_3 ] . V_77 |= V_81 ;
}
#else
if ( V_82 > V_88 )
V_3 = F_3 ( V_3 , V_4 * ( ( V_10 -> V_48 + 1 ) / 2 ) ,
V_10 -> V_13 ) ;
else
V_3 = F_3 ( V_10 -> V_63 , V_4 , V_10 -> V_13 ) ;
V_10 -> V_18 [ V_3 ] . V_77 |= V_81 ;
#endif
if ( V_82 ) {
V_10 -> V_18 [ V_82 - 1 ] . V_77 |= V_86 ;
if ( V_82 > 1 )
V_10 -> V_18 [ 0 ] . V_77 |= V_86 ;
}
}
static void F_43 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_64 * V_65 , struct V_9 * V_10 ,
int V_82 )
{
struct V_20 * V_67 = & V_10 -> V_18 [ V_82 ] ;
int V_89 = V_38 -> V_90 ;
if ( V_89 > V_91 )
V_89 = V_91 - V_38 -> V_92 + 1 ;
if ( V_38 -> V_93 ) {
int V_94 ;
if ( V_89 > 0 && V_38 -> V_92 )
V_94 = ( V_89 + V_38 -> V_92 - 1 )
/ V_38 -> V_92 ;
else
V_94 = 1 ;
V_89 = V_94 * V_38 -> V_92 ;
}
V_67 -> V_77 = V_89 << V_95 & V_96 ;
V_10 -> V_23 [ V_82 ] = V_89 ;
if ( V_10 -> V_11 == V_97 &&
V_65 -> V_98 == V_99 )
V_67 -> V_77 |= V_100 ;
V_67 -> V_74 = ( V_24 ) V_38 -> V_101 ;
if ( V_89 > V_38 -> V_90 ) {
V_38 -> V_90 = 0 ;
} else {
V_38 -> V_101 += V_89 ;
V_38 -> V_90 -= V_89 ;
}
}
static void F_44 ( struct V_15 * V_16 ,
struct V_9 * V_10 )
{
struct V_64 * V_65 ;
struct V_37 * V_38 = V_10 -> V_41 ;
int V_82 = 0 ;
F_19 ( V_16 -> V_19 , L_7 , V_102 , V_10 ,
( unsigned long ) V_38 -> V_101 , V_38 -> V_90 ) ;
F_42 (qtd, &qh->qtd_list, qtd_list_entry) {
F_19 ( V_16 -> V_19 , L_8 , V_65 ) ;
if ( V_82 ) {
V_38 -> V_101 = V_65 -> V_70 -> V_75 +
V_65 -> V_70 -> V_103 ;
V_38 -> V_90 = V_65 -> V_70 -> V_73 -
V_65 -> V_70 -> V_103 ;
F_19 ( V_16 -> V_19 , L_9 ,
( unsigned long ) V_38 -> V_101 , V_38 -> V_90 ) ;
}
V_65 -> V_82 = 0 ;
do {
if ( V_82 > 1 ) {
V_10 -> V_18 [ V_82 - 1 ] . V_77 |= V_86 ;
F_19 ( V_16 -> V_19 ,
L_10 ,
V_82 - 1 ,
& V_10 -> V_18 [ V_82 - 1 ] ) ;
}
F_43 ( V_16 , V_38 , V_65 , V_10 , V_82 ) ;
F_19 ( V_16 -> V_19 ,
L_11 ,
V_82 , & V_10 -> V_18 [ V_82 ] ,
V_10 -> V_18 [ V_82 ] . V_74 ,
V_10 -> V_18 [ V_82 ] . V_77 ) ;
V_65 -> V_82 ++ ;
V_82 ++ ;
} while ( V_38 -> V_90 > 0 &&
V_82 != V_8 );
F_19 ( V_16 -> V_19 , L_12 , V_82 ) ;
V_65 -> V_87 = 1 ;
if ( V_10 -> V_11 == V_97 )
break;
if ( V_82 == V_8 )
break;
}
if ( V_82 ) {
V_10 -> V_18 [ V_82 - 1 ] . V_77 |=
V_81 | V_104 | V_86 ;
F_19 ( V_16 -> V_19 , L_13 ,
V_82 - 1 , & V_10 -> V_18 [ V_82 - 1 ] ) ;
if ( V_82 > 1 ) {
V_10 -> V_18 [ 0 ] . V_77 |= V_86 ;
F_19 ( V_16 -> V_19 , L_14 ,
& V_10 -> V_18 [ 0 ] ) ;
}
V_38 -> V_48 = V_82 ;
}
}
void F_45 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_41 ;
T_1 V_58 = 0 ;
switch ( V_38 -> V_11 ) {
case V_97 :
case V_105 :
F_44 ( V_16 , V_10 ) ;
F_46 ( V_16 , V_38 ) ;
break;
case V_53 :
F_44 ( V_16 , V_10 ) ;
F_21 ( V_16 , V_10 , 1 ) ;
F_46 ( V_16 , V_38 ) ;
break;
case V_12 :
if ( ! V_10 -> V_48 )
V_58 = F_38 ( V_16 , V_10 ) ;
F_41 ( V_16 , V_10 , V_58 ) ;
if ( ! V_38 -> V_106 ) {
F_21 ( V_16 , V_10 , 1 ) ;
V_38 -> V_48 = F_4 ( V_10 ) ;
F_46 ( V_16 , V_38 ) ;
}
break;
default:
break;
}
}
static int F_47 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_64 * V_65 ,
struct V_9 * V_10 , T_1 V_3 )
{
struct V_20 * V_67 = & V_10 -> V_18 [ V_3 ] ;
struct V_68 * V_69 ;
T_1 V_107 = 0 ;
int V_108 = 0 ;
V_69 = & V_65 -> V_70 -> V_71 [ V_65 -> V_72 ] ;
V_67 -> V_74 = ( V_24 ) ( V_65 -> V_70 -> V_75 + V_69 -> V_76 ) ;
if ( V_38 -> V_93 )
V_107 = V_67 -> V_77 >> V_78 &
V_79 >> V_78 ;
if ( ( V_67 -> V_77 & V_109 ) == V_110 ) {
V_65 -> V_70 -> V_111 ++ ;
V_69 -> V_103 = V_10 -> V_23 [ V_3 ] - V_107 ;
V_69 -> V_77 = - V_112 ;
} else {
V_69 -> V_103 = V_10 -> V_23 [ V_3 ] - V_107 ;
V_69 -> V_77 = 0 ;
}
if ( ++ V_65 -> V_113 == V_65 -> V_70 -> V_80 ) {
F_48 ( V_16 , V_65 -> V_70 -> V_114 , V_65 -> V_70 , 0 ) ;
F_49 ( V_16 , V_65 , V_10 ) ;
if ( V_38 -> V_115 == V_116 )
return - 1 ;
V_108 = V_117 ;
}
V_10 -> V_48 -- ;
if ( V_67 -> V_77 & V_81 )
V_108 = V_118 ;
return V_108 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
enum V_119 V_115 )
{
struct V_68 * V_69 ;
struct V_64 * V_65 , * V_120 ;
struct V_9 * V_10 ;
T_1 V_3 ;
int V_108 ;
V_10 = V_38 -> V_10 ;
V_3 = V_10 -> V_62 ;
if ( V_38 -> V_115 == V_116 ) {
F_42 (qtd, &qh->qtd_list, qtd_list_entry)
V_65 -> V_87 = 0 ;
return;
}
if ( V_115 == V_121 ||
V_115 == V_122 ) {
int V_123 = V_115 == V_121 ?
- V_124 : - V_125 ;
F_51 (qtd, qtd_tmp, &qh->qtd_list,
qtd_list_entry) {
for ( V_3 = 0 ; V_3 < V_65 -> V_70 -> V_80 ; V_3 ++ ) {
V_69 = & V_65 -> V_70 -> V_71 [ V_3 ] ;
V_69 -> V_77 = V_123 ;
}
F_48 ( V_16 , V_65 -> V_70 -> V_114 , V_65 -> V_70 ,
V_123 ) ;
F_49 ( V_16 , V_65 , V_10 ) ;
}
return;
}
F_51 (qtd, qtd_tmp, &qh->qtd_list, qtd_list_entry) {
if ( ! V_65 -> V_87 )
break;
do {
V_108 = F_47 ( V_16 , V_38 , V_65 , V_10 ,
V_3 ) ;
if ( V_108 < 0 )
return;
V_3 = F_2 ( V_3 , V_10 -> V_14 ,
V_38 -> V_5 ) ;
if ( V_108 == V_118 )
goto V_126;
if ( V_108 == V_117 )
break;
} while ( V_3 != V_10 -> V_62 );
}
V_126:
V_10 -> V_62 = V_3 ;
}
static int F_52 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
struct V_64 * V_65 ,
struct V_20 * V_67 ,
enum V_119 V_115 ,
V_24 V_23 , int * V_127 )
{
struct V_128 * V_70 = V_65 -> V_70 ;
T_1 V_107 = 0 ;
if ( V_38 -> V_93 )
V_107 = V_67 -> V_77 >> V_95 &
V_96 >> V_95 ;
F_19 ( V_16 -> V_19 , L_15 , V_107 , V_70 ) ;
if ( V_115 == V_121 ) {
F_23 ( V_16 -> V_19 , L_16 ) ;
V_70 -> V_77 = - V_124 ;
return 1 ;
}
if ( ( V_67 -> V_77 & V_109 ) == V_110 ) {
switch ( V_115 ) {
case V_129 :
F_19 ( V_16 -> V_19 , L_17 ) ;
V_70 -> V_77 = - V_130 ;
break;
case V_122 :
F_23 ( V_16 -> V_19 , L_18 ) ;
V_70 -> V_77 = - V_125 ;
break;
case V_131 :
F_23 ( V_16 -> V_19 , L_19 ) ;
V_70 -> V_77 = - V_112 ;
break;
default:
F_23 ( V_16 -> V_19 ,
L_20 ,
V_102 , V_115 ) ;
break;
}
return 1 ;
}
if ( V_67 -> V_77 & V_86 ) {
F_19 ( V_16 -> V_19 ,
L_21 ,
V_38 -> V_43 ) ;
return 0 ;
}
if ( V_38 -> V_11 == V_97 ) {
if ( V_65 -> V_98 == V_132 ) {
V_70 -> V_103 += V_23 - V_107 ;
if ( V_107 || V_70 -> V_103 >= V_70 -> V_73 ) {
* V_127 = 1 ;
}
} else if ( V_65 -> V_98 == V_133 ) {
V_70 -> V_77 = 0 ;
* V_127 = 1 ;
}
} else {
V_70 -> V_103 += V_23 - V_107 ;
F_19 ( V_16 -> V_19 , L_22 , V_70 -> V_73 ,
V_70 -> V_103 ) ;
if ( V_107 || V_70 -> V_103 >= V_70 -> V_73 ) {
V_70 -> V_77 = 0 ;
* V_127 = 1 ;
}
}
return 0 ;
}
static int F_53 ( struct V_15 * V_16 ,
struct V_37 * V_38 ,
int V_134 , struct V_64 * V_65 ,
int V_135 ,
enum V_119 V_115 ,
int * V_127 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_128 * V_70 = V_65 -> V_70 ;
struct V_20 * V_67 ;
V_24 V_23 ;
int V_136 ;
F_19 ( V_16 -> V_19 , L_23 , V_102 ) ;
V_67 = & V_10 -> V_18 [ V_135 ] ;
V_23 = V_10 -> V_23 [ V_135 ] ;
F_19 ( V_16 -> V_19 ,
L_24 ,
V_65 , V_70 , V_135 , V_67 , V_23 ) ;
V_136 = F_52 ( V_16 , V_38 , V_65 , V_67 ,
V_115 , V_23 ,
V_127 ) ;
if ( V_136 || ( * V_127 && V_70 -> V_77 != - V_137 ) ) {
F_48 ( V_16 , V_70 -> V_114 , V_70 , V_70 -> V_77 ) ;
F_49 ( V_16 , V_65 , V_10 ) ;
F_19 ( V_16 -> V_19 , L_25 ,
V_136 , * V_127 , V_70 -> V_77 ) ;
return V_136 ;
}
if ( V_10 -> V_11 == V_97 ) {
switch ( V_65 -> V_98 ) {
case V_99 :
if ( V_70 -> V_73 > 0 )
V_65 -> V_98 = V_132 ;
else
V_65 -> V_98 = V_133 ;
F_19 ( V_16 -> V_19 ,
L_26 ) ;
break;
case V_132 :
if ( * V_127 ) {
V_65 -> V_98 = V_133 ;
F_19 ( V_16 -> V_19 ,
L_27 ) ;
} else if ( V_135 + 1 == V_65 -> V_82 ) {
F_54 ( V_16 , V_38 , V_134 ,
V_65 ) ;
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
int V_134 ,
enum V_119 V_115 )
{
struct V_138 * V_139 , * V_120 ;
struct V_9 * V_10 = V_38 -> V_10 ;
struct V_64 * V_65 = NULL ;
int V_127 ;
int V_135 = 0 ;
if ( V_38 -> V_115 == V_116 ) {
F_42 (qtd, &qh->qtd_list, qtd_list_entry)
V_65 -> V_87 = 0 ;
return;
}
F_56 (qtd_item, qtd_tmp, &qh->qtd_list) {
int V_39 ;
V_65 = F_57 ( V_139 , struct V_64 , V_140 ) ;
V_127 = 0 ;
for ( V_39 = 0 ; V_39 < V_65 -> V_82 ; V_39 ++ ) {
if ( F_53 ( V_16 , V_38 , V_134 , V_65 ,
V_135 , V_115 ,
& V_127 ) )
break;
V_135 ++ ;
}
}
if ( V_10 -> V_11 != V_97 ) {
if ( V_115 == V_129 )
V_10 -> V_141 = V_142 ;
else if ( V_65 )
F_54 ( V_16 , V_38 , V_134 , V_65 ) ;
}
if ( V_115 == V_143 ) {
if ( V_38 -> V_144 & V_145 ) {
V_10 -> V_146 = 1 ;
}
}
}
void F_58 ( struct V_15 * V_16 ,
struct V_37 * V_38 , int V_134 ,
enum V_119 V_115 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
int V_147 = 0 ;
enum V_148 V_149 ;
if ( V_38 -> V_11 == V_12 ) {
F_50 ( V_16 , V_38 , V_115 ) ;
if ( V_115 != V_143 ||
F_26 ( & V_10 -> V_150 ) ) {
if ( V_115 == V_143 )
F_59 ( V_16 , V_38 , V_115 ) ;
F_24 ( V_16 , V_10 ) ;
F_60 ( V_16 , V_10 ) ;
} else {
F_61 ( & V_10 -> V_151 ,
& V_16 -> V_152 ) ;
V_147 = 1 ;
}
} else {
F_55 ( V_16 , V_38 , V_134 ,
V_115 ) ;
F_24 ( V_16 , V_10 ) ;
F_60 ( V_16 , V_10 ) ;
if ( ! F_26 ( & V_10 -> V_150 ) ) {
F_62 ( V_16 , V_10 ) ;
}
}
V_149 = F_63 ( V_16 ) ;
if ( V_149 != V_153 || V_147 ) {
if ( V_147 ) {
if ( V_149 == V_153 )
V_149 = V_154 ;
else if ( V_149 == V_155 )
V_149 = V_156 ;
}
F_64 ( V_16 , V_149 ) ;
}
}
