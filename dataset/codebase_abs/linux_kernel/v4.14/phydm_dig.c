static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
switch ( * V_2 -> V_4 ) {
case V_5 :
F_2 ( V_2 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ,
V_3 ) ;
if ( V_2 -> V_8 > V_9 )
F_2 ( V_2 , F_3 ( V_10 , V_2 ) , F_4 ( V_7 , V_2 ) ,
V_3 ) ;
break;
case V_11 :
F_2 ( V_2 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ,
V_3 ) ;
if ( V_2 -> V_8 != V_9 )
F_2 ( V_2 , F_3 ( V_10 , V_2 ) , F_4 ( V_7 , V_2 ) ,
F_5 ( V_3 ) ) ;
break;
case V_12 :
F_2 ( V_2 , F_3 ( V_10 , V_2 ) , F_4 ( V_7 , V_2 ) ,
F_5 ( V_3 ) ) ;
if ( V_2 -> V_8 != V_9 )
F_2 ( V_2 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ,
V_3 ) ;
break;
}
}
static inline T_1 F_6 ( T_1 V_13 , T_1 V_14 ,
T_1 V_3 )
{
if ( V_14 < V_13 ) {
if ( V_3 < V_14 )
return V_14 ;
} else {
if ( V_3 < V_13 )
return V_13 ;
}
return V_3 ;
}
void F_7 ( void * V_15 , T_2 V_16 ,
T_2 V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
if ( V_16 == V_21 ) {
V_19 -> V_22 = V_17 ;
} else if ( V_16 == V_23 ) {
V_19 -> V_24 = V_17 ;
} else if ( V_16 == V_25 ) {
V_19 -> V_26 = true ;
} else if ( V_16 == V_27 ) {
V_19 -> V_26 = false ;
} else if ( V_16 == V_28 ) {
if ( V_17 > 30 )
V_17 = 30 ;
V_19 -> V_29 = ( T_1 ) V_17 ;
} else if ( V_16 == V_30 ) {
if ( V_17 == 0 )
V_17 = 0x1 ;
V_19 -> V_31 = ( T_1 ) V_17 ;
} else if ( V_16 == V_32 ) {
if ( V_17 > 0x50 )
V_17 = 0x50 ;
V_19 -> V_33 = ( T_1 ) V_17 ;
}
}
static int F_5 ( int V_34 )
{
#define F_8 0x30
#define F_9 8
if ( V_34 < F_8 ) {
if ( ( F_8 - V_34 ) < F_9 )
return F_8 ;
else
return V_34 + F_9 ;
}
return V_34 ;
}
static void F_10 ( void * V_15 , bool V_35 ,
bool V_36 , T_2 V_37 , T_2 V_38 ,
T_2 * V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
if ( V_2 -> V_40 && ( V_36 || V_35 ) ) {
V_39 [ 0 ] = V_41 ;
V_39 [ 1 ] = V_42 ;
V_39 [ 2 ] = V_43 ;
} else {
if ( V_35 ) {
V_39 [ 0 ] = 250 ;
V_39 [ 1 ] = 1000 ;
V_39 [ 2 ] = 2000 ;
} else {
V_39 [ 0 ] = 2000 ;
V_39 [ 1 ] = 4000 ;
V_39 [ 2 ] = 5000 ;
}
}
}
static T_1 F_11 ( void * V_15 , T_1 V_44 ,
T_1 V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_45 * V_46 =
(struct V_45 * ) F_12 (
V_2 , V_47 ) ;
T_1 V_31 = V_19 -> V_31 ;
if ( V_19 -> V_48 ) {
if ( -- V_19 -> V_48 == 0 )
V_19 -> V_49 = 0 ;
}
if ( V_46 -> V_50 > 10000 ) {
F_13 ( V_2 , V_51 ,
L_1 , V_52 ) ;
if ( V_19 -> V_49 != 3 )
V_19 -> V_49 ++ ;
if ( V_19 -> V_53 < V_3 ) {
V_19 -> V_53 = V_3 ;
V_19 -> V_49 = 1 ;
V_19 -> V_48 = V_54 ;
}
if ( V_19 -> V_49 >= 3 ) {
if ( ( V_19 -> V_53 + 2 ) >
V_19 -> V_33 )
V_31 = V_19 -> V_33 ;
else
V_31 =
( V_19 -> V_53 + 2 ) ;
V_19 -> V_55 = 1800 ;
F_13 (
V_2 , V_51 ,
L_2 ,
V_52 , V_19 -> V_55 ) ;
}
}
else if ( V_46 -> V_50 > 2000 ) {
F_13 ( V_2 , V_51 ,
L_3 ) ;
F_13 (
V_2 , V_51 ,
L_4 ,
V_46 -> V_50 , V_46 -> V_56 , V_3 ,
V_19 -> V_57 ) ;
if ( ( V_46 -> V_50 >
( V_46 -> V_56 + ( V_46 -> V_56 >> 3 ) +
( V_46 -> V_56 >> 4 ) ) ) &&
( V_3 < V_19 -> V_57 ) ) {
if ( V_19 -> V_49 != 3 )
V_19 -> V_49 ++ ;
if ( V_19 -> V_53 < V_3 ) {
F_13 (
V_2 , V_51 ,
L_5 ,
V_19 -> V_53 , V_3 ) ;
V_19 -> V_53 = V_3 ;
V_19 -> V_49 = 1 ;
V_19 -> V_48 = V_54 ;
}
}
if ( V_19 -> V_49 >= 3 ) {
F_13 (
V_2 , V_51 ,
L_6 ,
V_19 -> V_33 , V_31 ,
V_19 -> V_53 ) ;
if ( ( V_19 -> V_53 + 1 ) >
V_19 -> V_33 )
V_31 = V_19 -> V_33 ;
else
V_31 =
( V_19 -> V_53 + 1 ) ;
V_19 -> V_55 = 1200 ;
F_13 (
V_2 , V_51 ,
L_7 ,
V_19 -> V_55 , V_31 ) ;
}
} else {
if ( V_19 -> V_55 != 0 ) {
V_19 -> V_55 -- ;
F_13 ( V_2 , V_51 ,
L_8 ,
V_52 , V_19 -> V_55 ) ;
return V_31 ;
}
if ( V_19 -> V_49 >= 3 ) {
V_19 -> V_49 = 0 ;
return V_31 ;
}
if ( ( V_19 -> V_53 - 2 ) <
V_44 ) {
V_19 -> V_53 =
V_44 ;
V_31 = V_44 ;
F_13 ( V_2 , V_51 ,
L_9 ,
V_52 ) ;
} else {
if ( V_19 -> V_49 == 0 ) {
V_19 -> V_53 -= 2 ;
V_31 =
( V_19 -> V_53 + 2 ) ;
F_13 (
V_2 , V_51 ,
L_10 ,
V_52 ) ;
}
}
}
return V_31 ;
}
static void F_14 ( void * V_15 , T_1 V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
T_1 V_58 [ 8 ] = { 24 , 30 , 40 , 50 , 60 , 70 , 80 , 90 } ;
T_1 V_59 ;
if ( V_19 -> V_60 == 0 )
return;
for ( V_59 = 0 ; V_59 <= V_19 -> V_61 ; V_59 ++ ) {
if ( ( V_3 + V_58 [ V_59 ] ) >
V_19 -> V_62 [ V_19 -> V_63 ] ) {
if ( V_59 != 0 )
V_59 = V_59 - 1 ;
break;
} else if ( V_59 == V_19 -> V_61 ) {
break;
}
}
if ( V_2 -> V_64 & V_65 )
F_2 ( V_2 , 0x8c8 , 0xe , V_59 ) ;
else if ( V_2 -> V_64 & V_66 )
F_2 ( V_2 , V_67 , 0xe , V_59 ) ;
F_13 ( V_2 , V_51 ,
L_11 , V_52 , V_59 ,
V_19 -> V_61 ,
V_19 -> V_62 [ V_19 -> V_63 ] ) ;
}
void F_15 ( void * V_15 , T_1 V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
if ( V_19 -> V_68 ) {
F_13 ( V_2 , V_51 , L_12 ,
V_52 ) ;
return;
}
F_13 ( V_2 , V_51 ,
L_13 ,
V_52 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ) ;
if ( ( ! V_19 -> V_69 ) && V_2 -> V_40 ) {
if ( V_3 > V_19 -> V_33 ) {
F_13 (
V_2 , V_51 ,
L_14 ,
V_52 , V_3 ) ;
V_3 = V_19 -> V_33 ;
}
if ( V_2 -> V_70 & V_71 &&
V_2 -> V_72 ) {
if ( V_3 > V_2 -> V_73 )
V_3 = V_2 -> V_73 ;
F_13 (
V_2 , V_51 ,
L_15 ,
V_52 , V_3 ) ;
}
}
if ( V_19 -> V_74 != V_3 ) {
if ( V_2 -> V_64 & ( V_65 | V_66 ) )
F_14 ( V_2 , V_3 ) ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_64 & V_76 )
F_2 ( V_2 , 0xa0c , 0x00003f00 ,
( V_3 >> 1 ) ) ;
}
if ( ( V_2 -> V_70 & V_71 ) &&
( V_3 > V_19 -> V_74 ) ) {
V_19 -> V_74 = V_3 ;
F_16 ( V_2 ) ;
}
if ( V_2 -> V_77 & ( V_78 | V_79 ) ) {
F_2 ( V_2 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ,
V_3 ) ;
if ( V_2 -> V_8 > V_9 )
F_2 ( V_2 , F_3 ( V_10 , V_2 ) ,
F_4 ( V_7 , V_2 ) , V_3 ) ;
} else if ( V_2 -> V_77 & ( V_80 ) ) {
F_1 ( V_2 , V_3 ) ;
}
V_19 -> V_74 = V_3 ;
}
F_13 ( V_2 , V_51 , L_16 , V_52 ,
V_3 ) ;
}
void F_17 ( void * V_15 , enum V_81 V_82 ,
enum V_83 V_84 , T_1 V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
T_3 V_86 ;
F_13 ( V_2 , V_51 , L_17 , V_52 ,
V_84 ) ;
if ( ( V_19 -> V_87 == 0 ) &&
( ! ( V_2 -> V_70 & V_88 ) ||
! ( V_2 -> V_70 & V_89 ) ) ) {
F_13 (
V_2 , V_51 ,
L_18 ,
V_52 ) ;
return;
}
if ( V_84 > V_90 ) {
F_13 ( V_2 , V_51 ,
L_19 , V_52 ) ;
return;
}
F_13 ( V_2 , V_51 ,
L_20 ,
V_52 , V_19 -> V_87 , V_85 ) ;
F_13 (
V_2 , V_51 ,
L_21 ,
V_52 , V_19 -> V_91 [ 7 ] ,
V_19 -> V_91 [ 6 ] , V_19 -> V_91 [ 5 ] ,
V_19 -> V_91 [ 4 ] , V_19 -> V_91 [ 3 ] ,
V_19 -> V_91 [ 2 ] , V_19 -> V_91 [ 1 ] ,
V_19 -> V_91 [ 0 ] ) ;
switch ( V_82 ) {
case V_92 : {
F_18 ( V_2 , V_93 ,
V_2 -> V_70 & ( ~ V_88 ) ) ;
F_13 ( V_2 , V_51 , L_22 ,
V_52 ) ;
if ( V_19 -> V_87 == 0 ) {
V_19 -> V_94 = V_19 -> V_74 ;
F_13 (
V_2 , V_51 ,
L_23 ,
V_52 , V_19 -> V_94 , V_85 ) ;
}
V_19 -> V_91 [ V_84 ] = V_85 ;
V_19 -> V_87 =
( V_19 -> V_87 | F_19 ( V_84 ) ) ;
if ( F_19 ( V_84 + 1 ) > V_19 -> V_87 ) {
F_15 ( V_2 , V_85 ) ;
F_13 ( V_2 , V_51 ,
L_24 ,
V_52 , V_85 ) ;
}
break;
}
case V_95 : {
if ( ( V_19 -> V_87 & ( F_19 ( V_84 ) ) ) != 0 ) {
V_19 -> V_87 = V_19 -> V_87 &
( ~ ( F_19 ( V_84 ) ) ) ;
V_19 -> V_91 [ V_84 ] = 0 ;
F_13 ( V_2 , V_51 , L_25 ,
V_52 ) ;
} else {
F_13 ( V_2 , V_51 ,
L_26 , V_52 ) ;
break;
}
if ( V_19 -> V_87 == 0 ) {
F_15 ( V_2 , V_19 -> V_94 ) ;
V_19 -> V_96 = true ;
F_13 ( V_2 , V_51 ,
L_27 ,
V_52 , V_19 -> V_94 ) ;
F_18 ( V_2 , V_93 ,
V_2 -> V_70 | V_88 ) ;
break;
}
if ( F_19 ( V_84 ) <= V_19 -> V_87 )
break;
for ( V_86 = ( V_84 - 1 ) ; V_86 >= 0 ;
V_86 -- ) {
if ( ( V_19 -> V_87 & F_19 ( V_86 ) ) > 0 )
break;
}
F_15 ( V_2 , V_19 -> V_91 [ V_86 ] ) ;
F_13 ( V_2 , V_51 ,
L_28 , V_52 ,
V_19 -> V_91 [ V_86 ] , V_86 ) ;
break;
}
default:
F_13 ( V_2 , V_51 , L_29 ,
V_52 ) ;
break;
}
F_13 ( V_2 , V_51 ,
L_20 ,
V_52 , V_19 -> V_87 , V_85 ) ;
F_13 (
V_2 , V_51 ,
L_21 ,
V_52 , V_19 -> V_91 [ 7 ] ,
V_19 -> V_91 [ 6 ] , V_19 -> V_91 [ 5 ] ,
V_19 -> V_91 [ 4 ] , V_19 -> V_91 [ 3 ] ,
V_19 -> V_91 [ 2 ] , V_19 -> V_91 [ 1 ] ,
V_19 -> V_91 [ 0 ] ) ;
}
static bool F_20 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
if ( ! ( V_2 -> V_70 & V_89 ) ) {
F_13 (
V_2 , V_51 ,
L_30 ,
V_52 ) ;
return true ;
}
if ( ! ( V_2 -> V_70 & V_88 ) ) {
F_13 (
V_2 , V_51 ,
L_31 ,
V_52 ) ;
return true ;
}
if ( * V_2 -> V_97 ) {
F_13 ( V_2 , V_51 ,
L_32 , V_52 ) ;
return true ;
}
if ( V_19 -> V_96 ) {
V_19 -> V_96 = false ;
F_13 ( V_2 , V_51 , L_33 ,
V_52 ) ;
return true ;
}
if ( ! V_2 -> V_98 ) {
F_13 ( V_2 , V_51 ,
L_34 , V_52 ) ;
return true ;
}
return false ;
}
void F_21 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
T_2 V_99 ;
T_1 V_59 ;
V_19 -> V_68 = false ;
V_19 -> V_96 = false ;
V_19 -> V_69 = false ;
V_19 -> V_74 =
( T_1 ) F_22 ( V_2 , F_3 ( V_6 , V_2 ) , F_4 ( V_7 , V_2 ) ) ;
V_19 -> V_57 = 0 ;
V_19 -> V_24 = V_100 ;
V_19 -> V_22 = V_101 ;
V_19 -> V_102 = V_103 ;
V_19 -> V_104 = V_105 ;
V_19 -> V_29 = V_106 ;
V_19 -> V_107 = V_108 ;
V_19 -> V_109 = V_110 ;
V_19 -> V_111 = 0xFF ;
V_19 -> V_112 = 0x83 ;
V_19 -> V_53 = V_113 ;
V_19 -> V_49 = 0 ;
V_19 -> V_48 = 0 ;
V_19 -> V_55 = 0 ;
V_19 -> V_114 = false ;
V_19 -> V_115 = false ;
V_2 -> V_98 = true ;
V_19 -> V_116 = V_113 ;
V_19 -> V_117 = V_113 ;
V_19 -> V_118 = 0x32 ;
F_23 ( V_2 , V_19 -> V_91 , 0 ,
( V_90 + 1 ) ) ;
V_19 -> V_87 = 0 ;
F_23 ( V_2 , V_19 -> V_119 , 0 ,
( V_90 + 1 ) ) ;
V_19 -> V_120 = 0 ;
if ( V_2 -> V_121 & ( V_122 | V_123 ) ) {
V_19 -> V_33 = V_124 ;
V_19 -> V_31 = V_113 ;
} else {
V_19 -> V_33 = V_124 ;
V_19 -> V_31 = V_113 ;
}
V_19 -> V_60 = 1 ;
if ( V_2 -> V_64 & V_65 ) {
V_99 = F_22 ( V_2 , 0x8c8 , V_125 ) ;
V_19 -> V_61 = ( T_1 ) ( V_99 & 0xe ) >> 1 ;
V_19 -> V_126 = ( T_1 ) ( V_99 & 0x30 ) >> 4 ;
V_19 -> V_127 = ( T_1 ) ( V_99 & 0xc0 ) >> 6 ;
} else if ( V_2 -> V_64 & V_66 ) {
V_99 =
F_22 ( V_2 , V_67 , V_125 ) ;
V_19 -> V_61 = ( T_1 ) ( V_99 & 0xe ) >> 1 ;
V_19 -> V_126 = ( T_1 ) ( V_99 & 0x30 ) >> 4 ;
V_19 -> V_127 = ( T_1 ) ( V_99 & 0xc0 ) >> 6 ;
}
if ( V_2 -> V_64 & ( V_65 | V_66 ) ) {
for ( V_59 = 0 ; V_59 < sizeof( V_19 -> V_62 ) ; V_59 ++ ) {
if ( V_19 -> V_62 [ V_59 ] == 0 )
V_19 -> V_62 [ V_59 ] =
0x64 ;
}
}
}
void F_24 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_45 * V_46 =
(struct V_45 * ) F_12 (
V_2 , V_47 ) ;
bool V_128 , V_129 ;
T_1 V_13 , V_44 ;
T_1 V_130 , V_131 ;
T_1 V_3 = V_19 -> V_74 ;
T_1 V_132 ;
T_2 V_39 [ 3 ] ;
T_2 V_38 = 0 , V_37 = 0 ;
bool V_35 = false ;
bool V_36 = true , V_133 = false ,
V_134 = false ;
if ( F_20 ( V_2 ) )
return;
F_13 ( V_2 , V_51 , L_35 ) ;
{
V_44 = V_19 -> V_116 ;
V_128 = ( V_2 -> V_40 ) && ! V_19 -> V_114 ;
V_129 =
( ! V_2 -> V_40 ) && V_19 -> V_114 ;
}
{
if ( V_2 -> V_64 >= V_135 )
V_130 = 0x5A ;
else
V_130 = V_124 ;
if ( V_2 -> V_64 != V_136 )
V_131 = V_113 ;
else
V_131 = 0x1C ;
V_13 = V_137 ;
if ( ( ( ( * V_2 -> V_138 >= 52 ) && ( * V_2 -> V_138 <= 64 ) ) ||
( ( * V_2 -> V_138 >= 100 ) && ( * V_2 -> V_138 <= 140 ) ) ) &&
F_25 ( V_2 ) ) {
V_35 = true ;
if ( * V_2 -> V_139 == V_140 )
V_131 = V_141 + 2 ;
else
V_131 = V_141 ;
F_13 ( V_2 , V_51 ,
L_36 ) ;
}
}
F_13 ( V_2 , V_51 ,
L_37 ,
V_130 , V_131 ) ;
if ( V_2 -> V_142 && ( * V_2 -> V_142 > 0 ) ) {
F_13 ( V_2 , V_51 , L_38 ,
* V_2 -> V_142 ) ;
V_131 = * V_2 -> V_142 ;
V_130 = ( V_131 <= V_130 ) ? ( V_130 ) :
( V_131 + 1 ) ;
}
if ( V_2 -> V_40 && V_36 ) {
if ( ( V_2 -> V_64 & ( V_143 | V_144 |
V_145 | V_136 ) ) &&
( V_2 -> V_146 == 1 ) ) {
V_132 = 10 ;
F_13 (
V_2 , V_51 ,
L_39 ,
V_132 ) ;
} else {
V_132 = 15 ;
}
if ( ( V_2 -> V_14 + V_132 ) > V_130 )
V_19 -> V_33 = V_130 ;
else if ( ( V_2 -> V_14 + V_132 ) < V_131 )
V_19 -> V_33 = V_131 ;
else
V_19 -> V_33 = V_2 -> V_14 + V_132 ;
{
if ( V_2 -> V_14 < V_131 )
V_44 = V_131 ;
else if ( V_2 -> V_14 > V_13 )
V_44 = V_13 ;
else
V_44 = V_2 -> V_14 ;
if ( V_35 ) {
V_44 = V_131 ;
F_13 (
V_2 , V_51 ,
L_40 ,
V_131 ) ;
}
}
} else {
if ( V_36 && V_35 ) {
V_19 -> V_33 = 0x28 ;
F_13 (
V_2 , V_51 ,
L_41 ,
V_19 -> V_33 ) ;
} else {
if ( V_36 )
V_19 -> V_33 = V_147 ;
else
V_19 -> V_33 = V_130 ;
}
V_44 = V_131 ;
}
if ( V_2 -> V_40 && ! V_2 -> V_148 &&
( V_2 -> V_64 & V_149 ) &&
( V_2 -> V_70 & V_150 ) ) {
if ( V_2 -> V_151 == V_152 ||
V_2 -> V_151 == V_153 ) {
if ( V_19 -> V_154 > V_13 )
V_44 = V_13 ;
else
V_44 = ( T_1 ) V_19 -> V_154 ;
F_13 (
V_2 , V_51 ,
L_42 ,
V_44 ) ;
F_13 ( V_2 , V_51 ,
L_43 ,
V_19 -> V_154 ) ;
}
}
F_13 (
V_2 , V_51 ,
L_44 ,
V_19 -> V_33 , V_44 ) ;
F_13 (
V_2 , V_51 ,
L_45 ,
V_2 -> V_40 , V_2 -> V_14 , V_128 , V_129 ) ;
if ( V_35 ) {
V_19 -> V_31 = V_44 ;
} else {
if ( ! V_2 -> V_40 ) {
V_19 -> V_31 = V_44 ;
if ( V_129 )
V_19 -> V_53 = V_44 ;
} else {
V_19 -> V_31 = F_11 (
V_2 , V_44 , V_3 ) ;
}
}
if ( V_2 -> V_40 && ! V_128 ) {
F_13 ( V_2 , V_51 , L_46 ,
V_2 -> V_155 . V_156 ) ;
if ( ( V_2 -> V_155 . V_156 < 5 ) &&
( V_2 -> V_157 ) ) {
V_19 -> V_31 = 0x1c ;
F_13 (
V_2 , V_51 ,
L_47 ,
V_2 -> V_155 . V_156 ,
V_19 -> V_31 ) ;
}
}
if ( V_19 -> V_31 > V_19 -> V_33 ) {
V_19 -> V_31 = V_19 -> V_33 ;
F_13 (
V_2 , V_51 ,
L_48 ,
V_19 -> V_31 ) ;
}
F_10 ( V_2 , V_35 , V_36 , V_37 , V_38 ,
V_39 ) ;
F_13 ( V_2 , V_51 ,
L_49 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ) ;
if ( V_2 -> V_40 && V_36 ) {
F_13 ( V_2 , V_51 , L_50 ) ;
if ( V_133 || ( V_128 && V_36 ) ) {
V_19 -> V_49 = 0 ;
if ( V_35 ) {
T_1 V_158 = V_2 -> V_14 ;
V_3 =
( V_2 -> V_14 > 0x28 ) ? 0x28 : V_158 ;
F_13 (
V_2 , V_51 ,
L_51 ) ;
} else {
V_3 = F_6 (
V_13 , V_2 -> V_14 ,
V_3 ) ;
}
F_13 (
V_2 , V_51 ,
L_52 ,
V_3 ) ;
} else {
if ( V_46 -> V_50 > V_39 [ 2 ] )
V_3 = V_3 + 4 ;
else if ( V_46 -> V_50 > V_39 [ 1 ] )
V_3 = V_3 + 2 ;
else if ( V_46 -> V_50 < V_39 [ 0 ] )
V_3 = V_3 - 2 ;
if ( ( V_2 -> V_155 . V_156 < 5 ) &&
( V_46 -> V_50 < V_42 ) &&
( V_2 -> V_157 ) ) {
V_3 = V_19 -> V_31 ;
F_13 (
V_2 , V_51 ,
L_53 ,
V_2 -> V_155 . V_156 ,
V_3 ) ;
}
}
} else {
F_13 ( V_2 , V_51 , L_54 ) ;
if ( V_129 || V_134 ) {
V_3 = V_131 ;
F_13 (
V_2 , V_51 ,
L_55 ) ;
} else {
if ( V_46 -> V_50 > V_39 [ 2 ] )
V_3 = V_3 + 4 ;
else if ( V_46 -> V_50 > V_39 [ 1 ] )
V_3 = V_3 + 2 ;
else if ( V_46 -> V_50 < V_39 [ 0 ] )
V_3 = V_3 - 2 ;
}
}
if ( V_3 < V_19 -> V_31 )
V_3 = V_19 -> V_31 ;
if ( V_3 > V_19 -> V_33 )
V_3 = V_19 -> V_33 ;
F_13 ( V_2 , V_51 , L_56 ,
V_3 , V_46 -> V_50 ) ;
if ( V_2 -> V_159 ) {
if ( V_2 -> V_40 ) {
if ( V_19 -> V_118 > ( V_3 ) )
F_15 ( V_2 , V_3 ) ;
else
F_15 ( V_2 , V_19 -> V_118 ) ;
V_19 -> V_114 = V_2 -> V_40 ;
V_19 -> V_116 = V_44 ;
} else {
if ( V_2 -> V_160 )
F_15 ( V_2 , 0x1c ) ;
else if ( V_2 -> V_161 )
F_15 ( V_2 , 0x28 ) ;
else
F_15 ( V_2 , V_19 -> V_118 ) ;
}
} else {
F_15 ( V_2 , V_3 ) ;
V_19 -> V_114 = V_2 -> V_40 ;
V_19 -> V_116 = V_44 ;
}
F_13 ( V_2 , V_51 , L_57 ) ;
}
void F_26 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_45 * V_46 =
(struct V_45 * ) F_12 (
V_2 , V_47 ) ;
T_1 V_162 = V_113 ;
T_1 V_3 = V_2 -> V_14 ;
if ( F_20 ( V_2 ) )
return;
V_3 = V_3 + V_163 ;
F_13 ( V_2 , V_51 , L_58 , V_52 ) ;
if ( V_46 -> V_50 > V_164 )
V_3 = V_3 + 4 ;
else if ( V_46 -> V_50 > V_165 )
V_3 = V_3 + 2 ;
else if ( V_46 -> V_50 < V_166 )
V_3 = V_3 - 2 ;
if ( ( V_2 -> V_14 - 10 ) > V_113 )
V_162 = ( V_2 -> V_14 - 10 ) ;
else
V_162 = V_113 ;
if ( V_3 > V_124 )
V_3 = V_124 ;
else if ( V_3 < V_162 )
V_3 = V_162 ;
F_13 ( V_2 , V_51 , L_59 , V_52 ,
V_46 -> V_50 ) ;
F_13 ( V_2 , V_51 , L_60 , V_52 ,
V_2 -> V_14 ) ;
F_13 ( V_2 , V_51 , L_61 , V_52 ,
V_3 ) ;
F_15 (
V_2 ,
V_3 ) ;
}
void F_27 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_45 * V_167 =
(struct V_45 * ) F_12 (
V_2 , V_47 ) ;
struct V_168 * V_169 = & V_2 -> V_170 ;
T_2 V_99 ;
if ( ! ( V_2 -> V_70 & V_89 ) )
return;
F_13 ( V_2 , V_171 , L_62 , V_52 ) ;
if ( V_2 -> V_64 & V_172 ) {
F_2 ( V_2 , V_173 , F_19 ( 31 ) ,
1 ) ;
F_2 ( V_2 , V_174 , F_19 ( 31 ) ,
1 ) ;
V_99 = F_22 ( V_2 , V_175 ,
V_176 ) ;
V_167 -> V_177 = ( V_99 & 0xffff ) ;
V_167 -> V_178 =
( ( V_99 & 0xffff0000 ) >> 16 ) ;
V_99 = F_22 ( V_2 , V_179 ,
V_176 ) ;
V_167 -> V_180 = ( V_99 & 0xffff ) ;
V_167 -> V_181 =
( ( V_99 & 0xffff0000 ) >> 16 ) ;
V_99 = F_22 ( V_2 , V_182 ,
V_176 ) ;
V_167 -> V_183 = ( V_99 & 0xffff ) ;
V_167 -> V_184 = ( ( V_99 & 0xffff0000 ) >> 16 ) ;
V_99 = F_22 ( V_2 , V_185 ,
V_176 ) ;
V_167 -> V_186 = ( V_99 & 0xffff ) ;
V_167 -> V_187 =
V_167 -> V_181 +
V_167 -> V_183 +
V_167 -> V_184 +
V_167 -> V_186 +
V_167 -> V_177 +
V_167 -> V_178 ;
V_167 -> V_188 = F_22 (
V_2 , V_189 , V_176 ) ;
V_167 -> V_190 = F_22 (
V_2 , V_191 , V_176 ) ;
V_99 = F_22 ( V_2 , V_192 ,
V_176 ) ;
V_167 -> V_193 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_194 = V_99 & 0xffff ;
V_99 =
F_22 ( V_2 , V_195 , V_176 ) ;
V_167 -> V_196 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_197 = V_99 & 0xffff ;
V_167 -> V_198 = 0 ;
V_167 -> V_199 = 0 ;
{
F_2 ( V_2 , V_200 , F_19 ( 12 ) , 1 ) ;
F_2 ( V_2 , V_200 , F_19 ( 14 ) , 1 ) ;
V_99 = F_22 ( V_2 , V_201 ,
V_202 ) ;
V_167 -> V_203 = V_99 ;
V_99 = F_22 ( V_2 , V_204 ,
V_205 ) ;
V_167 -> V_203 += ( V_99 & 0xff ) << 8 ;
V_99 = F_22 ( V_2 , V_206 ,
V_176 ) ;
V_167 -> V_207 =
( ( V_99 & 0xFF ) << 8 ) |
( ( V_99 & 0xFF00 ) >> 8 ) ;
}
V_167 -> V_56 = V_167 -> V_50 ;
V_167 -> V_50 = ( V_167 -> V_177 +
V_167 -> V_178 +
V_167 -> V_181 +
V_167 -> V_183 +
V_167 -> V_184 +
V_167 -> V_186 +
V_167 -> V_203 ) ;
V_167 -> V_208 = V_167 -> V_180 +
V_167 -> V_207 ;
if ( V_2 -> V_64 >= V_135 ) {
F_2 ( V_2 , V_209 , F_19 ( 31 ) ,
1 ) ;
F_2 ( V_2 , V_209 , F_19 ( 31 ) ,
0 ) ;
F_2 ( V_2 , V_174 , F_19 ( 27 ) ,
1 ) ;
F_2 ( V_2 , V_174 , F_19 ( 27 ) ,
0 ) ;
F_2 ( V_2 , V_173 , F_19 ( 31 ) ,
0 ) ;
F_2 ( V_2 , V_174 , F_19 ( 31 ) ,
0 ) ;
F_2 ( V_2 , V_200 ,
F_19 ( 13 ) | F_19 ( 12 ) , 0 ) ;
F_2 ( V_2 , V_200 ,
F_19 ( 13 ) | F_19 ( 12 ) , 2 ) ;
F_2 ( V_2 , V_200 ,
F_19 ( 15 ) | F_19 ( 14 ) , 0 ) ;
F_2 ( V_2 , V_200 ,
F_19 ( 15 ) | F_19 ( 14 ) , 2 ) ;
F_2 ( V_2 , V_210 , F_19 ( 16 ) , 1 ) ;
F_2 ( V_2 , V_210 , F_19 ( 16 ) , 0 ) ;
}
F_2 ( V_2 , V_211 , V_176 , 0x0 ) ;
V_167 -> V_212 =
F_22 ( V_2 , V_213 , V_176 ) ;
F_2 ( V_2 , V_211 , V_176 , 0x208 ) ;
V_167 -> V_214 =
( bool ) F_22 ( V_2 , V_213 , F_19 ( 30 ) ) ;
F_13 (
V_2 , V_171 ,
L_63 ,
V_167 -> V_181 ,
V_167 -> V_183 ,
V_167 -> V_184 ,
V_167 -> V_186 ,
V_167 -> V_177 ,
V_167 -> V_178 ) ;
}
if ( V_2 -> V_64 & V_215 ) {
T_2 V_216 ;
V_167 -> V_187 =
F_22 ( V_2 , V_217 , V_125 ) ;
V_167 -> V_203 =
F_22 ( V_2 , V_218 , V_125 ) ;
V_99 =
F_22 ( V_2 , V_219 , V_176 ) ;
V_167 -> V_180 = ( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_207 = V_99 & 0xffff ;
V_99 = F_22 ( V_2 , V_220 ,
V_176 ) ;
V_167 -> V_188 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_190 = V_99 & 0xffff ;
V_99 = F_22 ( V_2 , V_221 ,
V_176 ) ;
V_167 -> V_193 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_194 = V_99 & 0xffff ;
V_99 = F_22 ( V_2 , V_222 ,
V_176 ) ;
V_167 -> V_196 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_197 = V_99 & 0xffff ;
V_99 = F_22 ( V_2 , V_223 ,
V_176 ) ;
V_167 -> V_198 =
( V_99 & 0xffff0000 ) >> 16 ;
V_167 -> V_199 = V_99 & 0xffff ;
F_2 ( V_2 , V_224 , F_19 ( 17 ) , 1 ) ;
F_2 ( V_2 , V_224 , F_19 ( 17 ) , 0 ) ;
F_2 ( V_2 , V_225 , F_19 ( 15 ) , 0 ) ;
F_2 ( V_2 , V_225 , F_19 ( 15 ) , 1 ) ;
F_2 ( V_2 , V_226 , F_19 ( 0 ) , 1 ) ;
F_2 ( V_2 , V_226 , F_19 ( 0 ) , 0 ) ;
V_216 =
F_22 ( V_2 , V_227 , F_19 ( 28 ) ) ;
if ( V_216 ) {
V_167 -> V_50 = V_167 -> V_187 +
V_167 -> V_203 ;
V_167 -> V_208 =
V_167 -> V_207 +
V_167 -> V_180 ;
} else {
V_167 -> V_50 = V_167 -> V_187 ;
V_167 -> V_208 =
V_167 -> V_180 ;
}
if ( V_169 -> V_228 == V_229 ) {
if ( F_28 (
V_2 , V_230 ,
0x0 ) ) {
V_167 -> V_212 =
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
}
if ( F_28 (
V_2 , V_230 ,
0x209 ) ) {
V_167 -> V_214 =
( bool ) ( ( F_29 (
V_2 ) &
F_19 ( 30 ) ) >>
30 ) ;
F_30 ( V_2 ) ;
}
}
}
V_167 -> V_231 =
V_167 -> V_198 +
V_167 -> V_196 +
V_167 -> V_193 +
V_167 -> V_188 ;
V_167 -> V_232 = V_167 -> V_199 +
V_167 -> V_197 +
V_167 -> V_194 +
V_167 -> V_190 ;
F_13 ( V_2 , V_171 ,
L_64 ,
V_167 -> V_207 , V_167 -> V_180 ,
V_167 -> V_208 ) ;
F_13 ( V_2 , V_171 ,
L_65 ,
V_167 -> V_203 , V_167 -> V_187 ,
V_167 -> V_50 ) ;
F_13 ( V_2 , V_171 ,
L_66 ,
V_167 -> V_188 ,
V_167 -> V_190 ) ;
F_13 ( V_2 , V_171 , L_67 ,
V_167 -> V_193 ,
V_167 -> V_194 ) ;
F_13 ( V_2 , V_171 ,
L_68 ,
V_167 -> V_196 ,
V_167 -> V_197 ) ;
F_13 ( V_2 , V_171 ,
L_69 ,
V_167 -> V_198 ,
V_167 -> V_199 ) ;
F_13 ( V_2 , V_171 ,
L_69 ,
V_167 -> V_231 ,
V_167 -> V_232 ) ;
F_13 ( V_2 , V_171 ,
L_70 ,
V_167 -> V_212 , V_167 -> V_214 ) ;
}
void F_31 ( void * V_15 ,
enum V_81 V_82 ,
enum V_83 V_84 ,
T_1 V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
T_3 V_86 ;
F_13 ( V_2 , V_51 , L_17 , V_52 ,
V_84 ) ;
if ( ( V_19 -> V_120 == 0 ) &&
( ! ( V_2 -> V_70 & V_234 ) ||
! ( V_2 -> V_70 & V_89 ) ) ) {
F_13 (
V_2 , V_51 ,
L_71 ) ;
return;
}
if ( V_84 > V_90 ) {
F_13 ( V_2 , V_51 ,
L_19 , V_52 ) ;
return;
}
F_13 ( V_2 , V_51 ,
L_20 ,
V_52 , V_19 -> V_120 , V_233 ) ;
F_13 (
V_2 , V_51 ,
L_21 ,
V_52 , V_19 -> V_119 [ 7 ] ,
V_19 -> V_119 [ 6 ] , V_19 -> V_119 [ 5 ] ,
V_19 -> V_119 [ 4 ] , V_19 -> V_119 [ 3 ] ,
V_19 -> V_119 [ 2 ] , V_19 -> V_119 [ 1 ] ,
V_19 -> V_119 [ 0 ] ) ;
switch ( V_82 ) {
case V_92 : {
F_18 ( V_2 , V_93 ,
V_2 -> V_70 & ( ~ V_234 ) ) ;
F_13 ( V_2 , V_51 ,
L_72 ,
V_52 ) ;
if ( V_19 -> V_120 == 0 ) {
V_19 -> V_235 = V_19 -> V_112 ;
F_13 (
V_2 , V_51 ,
L_73 ,
V_52 , V_19 -> V_235 ,
V_233 ) ;
}
V_19 -> V_120 =
( V_19 -> V_120 | F_19 ( V_84 ) ) ;
V_19 -> V_119 [ V_84 ] = V_233 ;
if ( F_19 ( V_84 + 1 ) > V_19 -> V_120 ) {
F_32 ( V_2 , V_233 ) ;
F_13 ( V_2 , V_51 ,
L_74 ,
V_52 , V_233 ) ;
}
break;
}
case V_95 : {
if ( ( V_19 -> V_120 & ( F_19 ( V_84 ) ) ) != 0 ) {
V_19 -> V_120 =
V_19 -> V_120 &
( ~ ( F_19 ( V_84 ) ) ) ;
V_19 -> V_119 [ V_84 ] = 0 ;
F_13 ( V_2 , V_51 ,
L_75 , V_52 ) ;
} else {
F_13 ( V_2 , V_51 ,
L_26 , V_52 ) ;
break;
}
if ( V_19 -> V_120 == 0 ) {
F_32 ( V_2 , V_19 -> V_235 ) ;
F_13 ( V_2 , V_51 ,
L_76 ,
V_52 , V_19 -> V_235 ) ;
F_18 ( V_2 , V_93 ,
V_2 -> V_70 |
V_234 ) ;
break;
}
if ( F_19 ( V_84 ) <= V_19 -> V_120 )
break;
for ( V_86 = ( V_84 - 1 ) ; V_86 >= 0 ;
V_86 -- ) {
if ( ( V_19 -> V_120 & F_19 ( V_86 ) ) > 0 )
break;
}
F_32 ( V_2 ,
V_19 -> V_119 [ V_86 ] ) ;
F_13 ( V_2 , V_51 ,
L_77 ,
V_52 , V_19 -> V_119 [ V_86 ] ,
V_86 ) ;
break;
}
default:
F_13 ( V_2 , V_51 , L_29 ,
V_52 ) ;
break;
}
F_13 ( V_2 , V_51 ,
L_20 ,
V_52 , V_19 -> V_120 , V_233 ) ;
F_13 (
V_2 , V_51 ,
L_21 ,
V_52 , V_19 -> V_119 [ 7 ] ,
V_19 -> V_119 [ 6 ] , V_19 -> V_119 [ 5 ] ,
V_19 -> V_119 [ 4 ] , V_19 -> V_119 [ 3 ] ,
V_19 -> V_119 [ 2 ] , V_19 -> V_119 [ 1 ] ,
V_19 -> V_119 [ 0 ] ) ;
}
void F_33 ( void * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_45 * V_167 =
(struct V_45 * ) F_12 (
V_2 , V_47 ) ;
T_1 V_112 = V_19 -> V_112 , V_236 = 35 ;
if ( ( ! ( V_2 -> V_70 & V_234 ) ) ||
( ! ( V_2 -> V_70 & V_89 ) ) ) {
F_13 ( V_2 , V_51 , L_78 ) ;
return;
}
if ( V_2 -> V_237 )
return;
F_13 ( V_2 , V_51 , L_79 ) ;
if ( V_19 -> V_238 == 0xffffffff )
V_19 -> V_238 = V_167 -> V_203 ;
else
V_19 -> V_238 =
( ( V_19 -> V_238 << 1 ) + V_19 -> V_238 +
V_167 -> V_203 ) >>
2 ;
F_13 ( V_2 , V_51 , L_80 ,
V_19 -> V_238 ) ;
if ( V_2 -> V_40 ) {
if ( V_2 -> V_14 > V_236 ) {
V_112 = 0xcd ;
} else if ( V_2 -> V_14 > 20 ) {
if ( V_19 -> V_238 >
( ( V_42 >> 1 ) + ( V_42 >> 3 ) ) )
V_112 = 0xcd ;
else if ( V_19 -> V_238 < ( V_41 >> 1 ) )
V_112 = 0x83 ;
} else if ( V_2 -> V_14 > 7 ) {
V_112 = 0x83 ;
} else {
V_112 = 0x40 ;
}
} else {
if ( V_19 -> V_238 > 0x400 )
V_112 = 0x83 ;
else if ( V_19 -> V_238 < 0x200 )
V_112 = 0x40 ;
}
{
F_32 ( V_2 , V_112 ) ;
}
F_13 ( V_2 , V_51 , L_81 ,
V_112 ) ;
}
void F_32 ( void * V_15 , T_1 V_112 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
if ( V_19 -> V_112 !=
V_112 ) {
F_34 ( V_2 , F_3 ( V_239 , V_2 ) , V_112 ) ;
V_19 -> V_238 = 0xffffffff ;
}
V_19 -> V_111 = V_19 -> V_112 ;
V_19 -> V_112 = V_112 ;
}
bool F_35 ( void * V_15 )
{
bool V_240 = true ;
return V_240 ;
}
