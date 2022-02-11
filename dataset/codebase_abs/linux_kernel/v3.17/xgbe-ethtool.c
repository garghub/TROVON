static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
memcpy ( V_4 , V_9 [ V_5 ] . V_10 ,
V_11 ) ;
V_4 += V_11 ;
}
break;
}
F_2 ( L_2 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 * V_4 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
T_2 * V_16 ;
int V_5 ;
F_2 ( L_1 , V_6 ) ;
V_15 -> V_17 . V_18 ( V_15 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_16 = ( T_2 * ) V_15 + V_9 [ V_5 ] . V_19 ;
* V_4 ++ = * ( T_3 * ) V_16 ;
}
F_2 ( L_2 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_20 ;
F_2 ( L_1 , V_6 ) ;
switch ( V_3 ) {
case V_7 :
V_20 = V_8 ;
break;
default:
V_20 = - V_21 ;
}
F_2 ( L_2 , V_6 ) ;
return V_20 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_2 ( L_3 ) ;
V_23 -> V_24 = V_15 -> V_25 ;
V_23 -> V_26 = V_15 -> V_26 ;
V_23 -> V_27 = V_15 -> V_27 ;
F_2 ( L_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
int V_20 = 0 ;
F_2 ( L_5 ) ;
F_2 ( L_6 ,
V_23 -> V_24 , V_23 -> V_26 , V_23 -> V_27 ) ;
V_15 -> V_25 = V_23 -> V_24 ;
if ( V_23 -> V_24 ) {
V_29 -> V_30 |= V_31 ;
V_29 -> V_30 |= V_32 ;
} else {
V_29 -> V_30 &= ~ V_31 ;
V_29 -> V_30 &= ~ V_32 ;
V_15 -> V_26 = V_23 -> V_26 ;
V_15 -> V_27 = V_23 -> V_27 ;
}
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
F_2 ( L_7 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
int V_20 ;
F_2 ( L_8 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
V_20 = F_11 ( V_15 -> V_29 , V_34 ) ;
V_34 -> V_36 = V_37 ;
F_2 ( L_9 ) ;
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
T_1 V_38 ;
int V_20 ;
F_2 ( L_10 ) ;
if ( ! V_15 -> V_29 )
return - V_35 ;
V_38 = F_13 ( V_34 ) ;
if ( V_34 -> V_39 != V_29 -> V_40 )
return - V_41 ;
if ( ( V_34 -> V_24 != V_42 ) &&
( V_34 -> V_24 != V_43 ) )
return - V_41 ;
if ( V_34 -> V_24 == V_43 ) {
switch ( V_38 ) {
case V_44 :
case V_45 :
case V_46 :
break;
default:
return - V_41 ;
}
if ( V_34 -> V_47 != V_48 )
return - V_41 ;
}
V_34 -> V_30 &= V_29 -> V_49 ;
if ( ( V_34 -> V_24 == V_42 ) && ! V_34 -> V_30 )
return - V_41 ;
V_20 = 0 ;
V_29 -> V_24 = V_34 -> V_24 ;
V_29 -> V_38 = V_38 ;
V_29 -> V_47 = V_34 -> V_47 ;
V_29 -> V_30 = V_34 -> V_30 ;
if ( V_34 -> V_24 == V_42 )
V_29 -> V_30 |= V_50 ;
else
V_29 -> V_30 &= ~ V_50 ;
if ( F_8 ( V_2 ) )
V_20 = F_9 ( V_29 ) ;
F_2 ( L_11 ) ;
return V_20 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_53 * V_54 = & V_15 -> V_54 ;
F_15 ( V_52 -> V_55 , V_56 , sizeof( V_52 -> V_55 ) ) ;
F_15 ( V_52 -> V_57 , V_58 , sizeof( V_52 -> V_57 ) ) ;
F_15 ( V_52 -> V_59 , F_16 ( V_15 -> V_60 ) ,
sizeof( V_52 -> V_59 ) ) ;
snprintf ( V_52 -> V_61 , sizeof( V_52 -> V_61 ) , L_12 ,
F_17 ( V_54 -> V_57 , V_62 , V_63 ) ,
F_17 ( V_54 -> V_57 , V_62 , V_64 ) ,
F_17 ( V_54 -> V_57 , V_62 , V_65 ) ) ;
V_52 -> V_66 = V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_69 * V_17 = & V_15 -> V_17 ;
unsigned int V_70 ;
F_2 ( L_13 ) ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
V_70 = V_15 -> V_71 ;
V_68 -> V_72 = V_17 -> V_73 ( V_15 , V_70 ) ;
V_68 -> V_74 = V_15 -> V_75 ;
V_68 -> V_76 = V_15 -> V_77 ;
V_68 -> V_78 = V_15 -> V_79 ;
F_2 ( L_14 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_69 * V_17 = & V_15 -> V_17 ;
unsigned int V_75 , V_71 , V_80 ;
unsigned int V_79 , V_77 ;
F_2 ( L_15 ) ;
if ( ( V_68 -> V_81 ) ||
( V_68 -> V_82 ) ||
( V_68 -> V_83 ) ||
( V_68 -> V_84 ) ||
( V_68 -> V_85 ) ||
( V_68 -> V_86 ) ||
( V_68 -> V_87 ) ||
( V_68 -> V_88 ) ||
( V_68 -> V_89 ) ||
( V_68 -> V_90 ) ||
( V_68 -> V_91 ) ||
( V_68 -> V_92 ) ||
( V_68 -> V_93 ) ||
( V_68 -> V_94 ) ||
( V_68 -> V_95 ) ||
( V_68 -> V_96 ) ||
( V_68 -> V_97 ) ||
( V_68 -> V_98 ) )
return - V_21 ;
V_75 = V_15 -> V_75 ;
if ( V_75 != V_68 -> V_74 && F_8 ( V_2 ) ) {
F_20 ( V_2 ,
L_16 ) ;
return - V_41 ;
}
V_71 = V_17 -> V_99 ( V_15 , V_68 -> V_72 ) ;
V_75 = V_68 -> V_74 ;
if ( V_68 -> V_72 && ! V_71 )
V_71 = 1 ;
if ( V_71 > V_100 ) {
V_80 = V_17 -> V_73 ( V_15 , V_100 ) ;
F_20 ( V_2 , L_17 ,
V_80 ) ;
return - V_41 ;
}
if ( V_75 > V_15 -> V_101 -> V_102 -> V_103 ) {
F_20 ( V_2 , L_18 ,
V_15 -> V_101 -> V_102 -> V_103 ) ;
return - V_41 ;
}
V_77 = V_68 -> V_76 ;
V_79 = V_68 -> V_78 ;
if ( V_79 > V_15 -> V_101 -> V_104 -> V_103 ) {
F_20 ( V_2 , L_19 ,
V_15 -> V_101 -> V_104 -> V_103 ) ;
return - V_41 ;
}
V_15 -> V_71 = V_71 ;
V_15 -> V_75 = V_75 ;
V_17 -> V_105 ( V_15 ) ;
V_15 -> V_77 = V_77 ;
V_15 -> V_79 = V_79 ;
V_17 -> V_106 ( V_15 ) ;
F_2 ( L_20 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
V_108 -> V_109 = V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
if ( V_15 -> V_116 )
V_108 -> V_117 = F_22 ( V_15 -> V_116 ) ;
else
V_108 -> V_117 = - 1 ;
V_108 -> V_118 = ( 1 << V_119 ) | ( 1 << V_120 ) ;
V_108 -> V_121 = ( 1 << V_122 ) |
( 1 << V_123 ) |
( 1 << V_124 ) |
( 1 << V_125 ) |
( 1 << V_126 ) |
( 1 << V_127 ) |
( 1 << V_128 ) |
( 1 << V_129 ) |
( 1 << V_130 ) |
( 1 << V_131 ) |
( 1 << V_132 ) ;
return 0 ;
}
struct V_133 * F_23 ( void )
{
return (struct V_133 * ) & V_134 ;
}
