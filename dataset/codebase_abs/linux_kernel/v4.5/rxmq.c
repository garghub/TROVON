void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 ++ ;
#ifdef F_2
if ( V_2 -> V_6 . V_7 & F_3 ( V_8 ) ) {
F_4 ( & V_2 -> V_9 ) ;
V_2 -> V_10 . V_11 ++ ;
F_5 ( & V_2 -> V_9 ) ;
}
#endif
}
static inline int F_6 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 = (struct V_19 * ) V_13 -> V_21 ;
struct V_22 * V_23 = F_7 ( V_13 ) ;
struct V_24 * V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 [ V_29 ] ;
T_1 * V_30 ;
if ( ! F_8 ( V_20 -> V_31 ) ||
F_9 ( V_20 -> V_32 ) )
return 0 ;
if ( ! ( V_23 -> V_33 & V_34 ) )
return 0 ;
if ( V_14 == 0 )
return 0 ;
if ( F_10 ( V_16 ) ) {
F_11 ( V_2 ,
L_1 ) ;
return - 1 ;
}
V_18 = F_12 ( V_16 ) ;
V_30 = ( T_1 * ) V_20 + F_13 ( V_20 -> V_31 ) ;
V_27 = V_30 [ 3 ] >> 6 ;
V_25 = F_14 ( V_18 -> V_25 [ V_27 ] ) ;
if ( ! V_25 )
return - 1 ;
if ( F_15 ( V_20 -> V_31 ) )
V_26 = * F_16 ( V_20 ) & V_35 ;
else
V_26 = 0 ;
if ( V_26 >= V_36 )
return - 1 ;
V_28 [ 0 ] = V_30 [ 7 ] ;
V_28 [ 1 ] = V_30 [ 6 ] ;
V_28 [ 2 ] = V_30 [ 5 ] ;
V_28 [ 3 ] = V_30 [ 4 ] ;
V_28 [ 4 ] = V_30 [ 1 ] ;
V_28 [ 5 ] = V_30 [ 0 ] ;
if ( memcmp ( V_28 , V_25 -> V_37 [ V_14 ] . V_28 [ V_26 ] ,
V_29 ) <= 0 )
return - 1 ;
memcpy ( V_25 -> V_37 [ V_14 ] . V_28 [ V_26 ] , V_28 , V_29 ) ;
V_23 -> V_33 |= V_38 ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 , struct V_19 * V_20 ,
T_2 V_39 , T_1 V_40 ,
struct V_3 * V_4 )
{
unsigned int V_41 , V_42 ;
V_41 = ( V_39 <= F_18 ( V_13 ) ) ? V_39 :
sizeof( * V_20 ) + V_40 + 8 ;
memcpy ( F_19 ( V_13 , V_41 ) , V_20 , V_41 ) ;
V_42 = V_39 - V_41 ;
if ( V_42 ) {
int V_43 = ( void * ) V_20 + V_41 -
F_20 ( V_4 ) + F_21 ( V_4 ) ;
F_22 ( V_13 , 0 , F_23 ( V_4 ) , V_43 ,
V_42 , V_4 -> V_44 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_12 * V_13 , int V_14 ,
struct V_15 * V_16 )
{
if ( F_6 ( V_2 , V_13 , V_14 , V_16 ) )
F_25 ( V_13 ) ;
else
F_26 ( V_2 -> V_47 , V_13 , V_46 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_22 * V_50 )
{
int V_51 , V_52 , V_53 , V_54 ;
V_51 = V_49 -> V_51 ;
V_51 = V_51 ? - V_51 : V_55 ;
V_52 = V_49 -> V_52 ;
V_52 = V_52 ? - V_52 : V_55 ;
V_53 = V_49 -> V_53 ;
V_53 = V_53 ? - V_53 : V_55 ;
V_54 = F_28 ( V_51 , V_52 ) ;
V_54 = F_28 ( V_54 , V_53 ) ;
F_29 ( V_2 , L_2 ,
V_51 , V_52 , V_53 , V_54 ) ;
V_50 -> signal = V_54 ;
V_50 -> V_56 = 0 ;
V_50 -> V_57 [ 0 ] = V_51 ;
V_50 -> V_57 [ 1 ] = V_52 ;
V_50 -> V_57 [ 2 ] = V_53 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_22 * V_23 ,
struct V_48 * V_49 , int V_14 ,
T_1 * V_40 )
{
T_2 V_58 = F_31 ( V_49 -> V_58 ) ;
if ( ! F_32 ( V_20 -> V_31 ) ||
( V_58 & V_59 ) ==
V_60 )
return 0 ;
switch ( V_58 & V_59 ) {
case V_61 :
case V_62 :
F_33 ( V_29 != V_63 ) ;
if ( ! ( V_58 & V_64 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
* V_40 = V_65 ;
return 0 ;
case V_66 :
if ( ! ( V_58 & V_67 ) )
return 0 ;
* V_40 = V_68 ;
case V_69 :
if ( ! ( V_58 & V_70 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
if ( ( V_58 & V_59 ) ==
V_69 )
* V_40 = V_71 ;
return 0 ;
case V_72 :
if ( ! ( V_58 & V_64 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
return 0 ;
default:
F_11 ( V_2 , L_3 , V_58 ) ;
}
return 0 ;
}
static void F_34 ( struct V_15 * V_16 ,
struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_73 * V_74 = F_35 ( V_18 -> V_75 ) ;
if ( V_74 -> V_76 & V_77 &&
V_49 -> V_78 & F_3 ( V_79 ) &&
V_49 -> V_78 & F_3 ( V_80 ) )
V_13 -> V_81 = V_82 ;
}
void F_36 ( struct V_1 * V_2 , struct V_45 * V_46 ,
struct V_3 * V_4 , int V_14 )
{
struct V_22 * V_50 ;
struct V_83 * V_84 = F_20 ( V_4 ) ;
struct V_48 * V_49 = ( void * ) V_84 -> V_21 ;
struct V_19 * V_20 = ( void * ) ( V_49 + 1 ) ;
T_3 V_39 = F_31 ( V_49 -> V_85 ) ;
T_3 V_86 = F_37 ( V_49 -> V_86 ) ;
struct V_15 * V_16 = NULL ;
struct V_12 * V_13 ;
T_1 V_40 = 0 ;
V_13 = F_38 ( 128 , V_87 ) ;
if ( ! V_13 ) {
F_11 ( V_2 , L_4 ) ;
return;
}
V_50 = F_7 ( V_13 ) ;
if ( F_30 ( V_2 , V_20 , V_50 , V_49 , V_14 , & V_40 ) ) {
F_25 ( V_13 ) ;
return;
}
if ( ! ( V_49 -> V_58 & F_3 ( V_88 ) ) ||
! ( V_49 -> V_58 & F_3 ( V_89 ) ) ) {
F_39 ( V_2 , L_5 ,
F_31 ( V_49 -> V_58 ) ) ;
V_50 -> V_33 |= V_90 ;
}
V_50 -> V_91 = F_40 ( V_49 -> V_92 ) ;
V_50 -> V_93 = F_37 ( V_49 -> V_94 ) ;
V_50 -> V_95 = V_49 -> V_96 > 14 ? V_97 :
V_98 ;
V_50 -> V_99 = F_41 ( V_49 -> V_96 ,
V_50 -> V_95 ) ;
F_27 ( V_2 , V_49 , V_50 ) ;
F_42 () ;
if ( F_31 ( V_49 -> V_58 ) & V_100 ) {
T_1 V_101 = V_49 -> V_102 & V_103 ;
if ( ! F_43 ( V_101 >= V_104 ) ) {
V_16 = F_14 ( V_2 -> V_105 [ V_101 ] ) ;
if ( F_44 ( V_16 ) )
V_16 = NULL ;
}
} else if ( ! F_9 ( V_20 -> V_106 ) ) {
V_16 = F_45 ( V_2 -> V_47 , V_20 -> V_106 , NULL ) ;
}
if ( V_16 ) {
struct V_17 * V_18 = F_12 ( V_16 ) ;
if ( F_46 ( V_2 -> V_107 ) )
F_47 ( V_2 , V_16 , false ) ;
F_48 ( V_2 , & V_18 -> V_108 , V_50 ) ;
if ( F_49 ( V_2 -> V_109 , V_110 ) &&
F_50 ( V_20 -> V_31 ) ) {
struct V_111 * V_112 ;
struct V_113 * V_114 ;
bool V_115 ;
T_4 V_116 ;
V_112 = F_51 ( V_2 -> V_109 ,
V_110 ) ;
V_114 = ( void * ) V_112 -> V_21 ;
V_116 = F_37 ( V_114 -> V_116 ) ;
V_115 =
F_52 ( V_2 , V_18 -> V_75 ,
V_112 ) ;
if ( V_115 && V_50 -> signal < V_116 )
F_53 ( V_2 , V_112 , NULL ) ;
}
if ( F_8 ( V_20 -> V_31 ) )
F_34 ( V_16 , V_13 , V_49 ) ;
}
switch ( V_86 & V_117 ) {
case V_118 :
break;
case V_119 :
V_50 -> V_33 |= V_120 ;
break;
case V_121 :
V_50 -> V_122 |= V_123 ;
break;
case V_124 :
V_50 -> V_122 |= V_125 ;
break;
}
if ( V_86 & V_126 )
V_50 -> V_33 |= V_127 ;
if ( V_86 & V_128 )
V_50 -> V_33 |= V_129 ;
if ( V_86 & V_130 )
V_50 -> V_33 |= V_131 ;
if ( V_86 & V_132 ) {
T_1 V_133 = ( V_86 & V_134 ) >>
V_135 ;
V_50 -> V_33 |= V_136 ;
V_50 -> V_137 = V_86 & V_138 ;
V_50 -> V_33 |= V_133 << V_139 ;
} else if ( V_86 & V_140 ) {
T_1 V_133 = ( V_86 & V_141 ) >>
V_135 ;
V_50 -> V_142 =
( ( V_86 & V_143 ) >>
V_144 ) + 1 ;
V_50 -> V_137 = V_86 & V_145 ;
V_50 -> V_33 |= V_146 ;
V_50 -> V_33 |= V_133 << V_139 ;
if ( V_86 & V_147 )
V_50 -> V_122 |= V_148 ;
} else {
V_50 -> V_137 =
F_54 ( V_86 ,
V_50 -> V_95 ) ;
}
F_17 ( V_13 , V_20 , V_39 , V_40 , V_4 ) ;
F_24 ( V_2 , V_46 , V_13 , V_14 , V_16 ) ;
F_55 () ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_14 )
{
}
