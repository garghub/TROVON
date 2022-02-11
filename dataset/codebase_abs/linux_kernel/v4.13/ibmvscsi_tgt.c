static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
T_1 V_4 = V_1 -> V_4 ;
if ( ! V_4 )
return;
if ( V_1 -> V_5 & V_6 ) {
if ( V_1 -> V_7 == V_8 ) {
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = F_2 ( V_4 ) ;
} else if ( V_1 -> V_7 == V_12 ) {
V_3 -> V_9 = V_13 ;
V_3 -> V_14 = F_2 ( V_4 ) ;
}
} else if ( V_1 -> V_5 & V_15 ) {
if ( V_1 -> V_7 == V_8 ) {
V_3 -> V_9 = V_16 ;
V_3 -> V_11 = F_2 ( V_4 ) ;
} else if ( V_1 -> V_7 == V_12 ) {
V_3 -> V_9 = V_17 ;
V_3 -> V_14 = F_2 ( V_4 ) ;
}
}
}
static bool F_3 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_23 ;
bool V_24 = false ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_28 ;
V_21 -> V_29 = V_30 ;
V_23 = F_4 ( V_19 -> V_31 . V_32 ,
F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
F_6 ( L_1 , V_23 ) ;
if ( V_23 == V_35 )
V_24 = true ;
return V_24 ;
}
static long F_7 ( struct V_18 * V_19 )
{
long V_36 ;
long V_24 = V_37 ;
int V_38 = 0 ;
do {
V_36 = F_8 ( V_19 -> V_31 . V_32 ) ;
switch ( V_36 ) {
case V_39 :
F_9 ( & V_19 -> V_40 ) ;
V_19 -> V_9 &= ~ V_41 ;
F_10 ( & V_19 -> V_40 ) ;
break;
case V_42 :
case V_43 :
F_11 ( & V_19 -> V_44 , L_2 ,
V_36 ) ;
V_24 = ERROR ;
break;
case V_45 :
case V_46 :
F_12 ( 1000 , 2000 ) ;
V_38 += 1 ;
break;
case V_47 :
F_12 ( 10000 , 20000 ) ;
V_38 += 10 ;
break;
case V_48 :
F_13 ( 100 ) ;
V_38 += 100 ;
break;
case V_49 :
F_14 ( 1 ) ;
V_38 += 1000 ;
break;
case V_50 :
F_14 ( 10 ) ;
V_38 += 10000 ;
break;
case V_51 :
F_14 ( 100 ) ;
V_38 += 100000 ;
break;
default:
F_11 ( & V_19 -> V_44 , L_3 ,
V_36 ) ;
V_24 = ERROR ;
break;
}
if ( V_38 > 300000 && V_36 != V_39 ) {
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_4 ) ;
}
} while ( V_36 != V_39 && V_24 == V_37 );
F_6 ( L_5 , V_36 , V_24 ) ;
return V_24 ;
}
static void F_15 ( struct V_18 * V_19 ,
bool V_52 )
{
V_19 -> V_53 = 0 ;
if ( V_52 )
V_19 -> V_54 . V_55 = 0 ;
}
static long F_16 ( struct V_18 * V_19 )
{
int V_56 ;
T_1 V_57 ;
T_3 V_58 ;
long V_24 = V_37 ;
if ( ! ( V_19 -> V_9 & V_59 ) ) {
F_17 ( V_19 -> V_60 ) ;
V_58 = V_19 -> V_61 ;
V_57 = V_19 -> V_9 ;
V_19 -> V_62 = 0 ;
V_19 -> V_63 = 0 ;
F_10 ( & V_19 -> V_40 ) ;
V_24 = F_7 ( V_19 ) ;
F_9 ( & V_19 -> V_40 ) ;
if ( V_58 != V_19 -> V_61 )
V_19 -> V_62 = V_19 -> V_61 ;
V_19 -> V_63 = ( ( ~ V_57 ) & V_19 -> V_9 ) ;
if ( V_24 == V_37 ) {
V_56 = V_19 -> V_64 . V_65 * V_66 ;
memset ( V_19 -> V_64 . V_67 , 0 , V_56 ) ;
V_19 -> V_64 . V_68 = 0 ;
V_19 -> V_9 |= V_59 ;
F_15 ( V_19 , false ) ;
}
F_6 ( L_6 ,
V_19 -> V_9 , V_19 -> V_69 , V_19 -> V_63 ,
V_19 -> V_62 ) ;
}
return V_24 ;
}
static struct V_20 * F_18 ( T_4 V_70 ,
T_4 * V_71 ,
struct V_20 * V_67 )
{
struct V_20 * V_72 ;
V_72 = V_67 + * V_71 ;
if ( V_72 -> V_25 ) {
* V_71 = ( * V_71 + 1 ) & V_70 ;
F_19 () ;
} else {
V_72 = NULL ;
}
return V_72 ;
}
static long F_20 ( struct V_18 * V_19 , T_5 V_27 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_24 ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_73 ;
V_21 -> V_27 = V_27 ;
V_24 = F_4 ( V_19 -> V_31 . V_32 , F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
return V_24 ;
}
static long F_21 ( struct V_18 * V_19 , T_4 * V_27 )
{
struct V_20 * V_21 ;
long V_24 = V_37 ;
V_21 = F_18 ( V_19 -> V_64 . V_70 , & V_19 -> V_64 . V_68 ,
V_19 -> V_64 . V_67 ) ;
if ( ! V_21 ) {
* V_27 = ( T_4 ) V_74 ;
} else if ( V_21 -> V_25 == V_73 && V_21 -> V_27 == V_75 ) {
* V_27 = ( T_4 ) V_75 ;
V_21 -> V_25 = V_76 ;
F_19 () ;
V_21 = F_18 ( V_19 -> V_64 . V_70 ,
& V_19 -> V_64 . V_68 ,
V_19 -> V_64 . V_67 ) ;
if ( V_21 ) {
* V_27 = ( T_4 ) ( V_21 -> V_27 ) ;
V_24 = ERROR ;
V_21 -> V_25 = V_76 ;
F_19 () ;
}
} else {
* V_27 = ( T_4 ) ( V_21 -> V_27 ) ;
V_24 = ERROR ;
V_21 -> V_25 = V_76 ;
F_19 () ;
}
return V_24 ;
}
static void F_22 ( struct V_77 * V_78 )
{
struct V_18 * V_19 = F_23 ( V_78 , struct V_18 ,
V_79 ) ;
T_3 V_61 ;
bool V_80 = false ;
F_9 ( & V_19 -> V_40 ) ;
V_61 = V_19 -> V_61 ;
V_19 -> V_61 = 0 ;
V_19 -> V_9 |= V_81 ;
V_19 -> V_9 &= ~ V_82 ;
F_6 ( L_7 , V_19 -> V_9 ,
V_19 -> V_69 ) ;
switch ( V_19 -> V_69 ) {
case V_83 :
case V_84 :
break;
case V_85 :
if ( V_61 == V_84 )
V_19 -> V_69 = V_61 ;
break;
case V_86 :
switch ( V_61 ) {
case V_84 :
case V_85 :
V_19 -> V_69 = V_61 ;
break;
case V_87 :
break;
default:
break;
}
break;
case V_88 :
if ( V_61 == V_84 )
V_19 -> V_69 = V_61 ;
break;
case V_89 :
switch ( V_61 ) {
case V_84 :
V_19 -> V_69 = V_61 ;
V_19 -> V_9 |= V_90 ;
V_19 -> V_9 &= ~ ( V_82 |
V_81 ) ;
F_19 () ;
if ( V_19 -> V_9 & V_91 ) {
V_19 -> V_9 &= ~ V_91 ;
F_24 ( & V_19 -> V_92 ) ;
}
break;
case V_85 :
case V_86 :
case V_87 :
F_11 ( & V_19 -> V_44 , L_8 ,
V_19 -> V_69 ) ;
break;
}
break;
case V_87 :
switch ( V_61 ) {
case V_84 :
V_19 -> V_9 |= V_90 ;
V_19 -> V_69 = V_61 ;
V_19 -> V_9 &= ~ ( V_82 |
V_81 ) ;
F_16 ( V_19 ) ;
break;
case V_85 :
case V_86 :
V_19 -> V_69 = V_61 ;
break;
}
break;
case V_93 :
case V_94 :
case V_95 :
V_80 = true ;
V_19 -> V_69 = V_61 ;
break;
case V_96 :
if ( V_61 == V_84 )
V_19 -> V_69 = V_61 ;
break;
default:
break;
}
if ( V_80 ) {
F_6 ( L_9 ,
( int ) F_25 ( & V_19 -> V_97 ) ,
( int ) F_25 ( & V_19 -> V_98 ) ) ;
if ( ! F_25 ( & V_19 -> V_97 ) ||
! F_25 ( & V_19 -> V_98 ) ) {
V_19 -> V_9 |= V_99 ;
F_6 ( L_10 , V_19 -> V_9 ) ;
F_10 ( & V_19 -> V_40 ) ;
F_26 ( & V_19 -> V_80 ) ;
F_9 ( & V_19 -> V_40 ) ;
}
F_6 ( L_11 ) ;
F_27 ( V_19 ) ;
}
F_10 ( & V_19 -> V_40 ) ;
}
static void F_28 ( struct V_18 * V_19 , T_4 V_61 ,
T_4 V_100 )
{
T_4 V_69 ;
switch ( V_61 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
break;
default:
F_11 ( & V_19 -> V_44 , L_12 ,
V_61 ) ;
return;
}
V_19 -> V_9 |= V_100 ;
F_6 ( L_13 ,
V_61 , V_100 , V_19 -> V_9 , V_19 -> V_69 ) ;
if ( ! ( V_19 -> V_9 & ( V_81 | V_82 ) ) ) {
V_19 -> V_9 |= V_82 ;
V_19 -> V_61 = V_61 ;
F_29 ( & V_19 -> V_79 , F_22 ) ;
( void ) F_30 ( V_19 -> V_101 , & V_19 -> V_79 ) ;
} else {
if ( V_19 -> V_61 )
V_69 = V_19 -> V_61 ;
else
V_69 = V_19 -> V_69 ;
switch ( V_69 ) {
case V_83 :
case V_84 :
break;
case V_88 :
case V_85 :
case V_96 :
if ( V_61 == V_84 )
V_19 -> V_61 = V_61 ;
break;
case V_86 :
switch ( V_61 ) {
case V_84 :
case V_85 :
V_19 -> V_61 = V_61 ;
break;
default:
break;
}
break;
case V_89 :
case V_87 :
case V_93 :
case V_94 :
case V_95 :
V_19 -> V_61 = V_61 ;
break;
default:
break;
}
}
F_6 ( L_14 ,
V_19 -> V_9 , V_19 -> V_61 ) ;
}
static long F_31 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_69 ) {
case V_83 :
case V_85 :
case V_86 :
case V_88 :
case V_84 :
case V_96 :
V_24 = ERROR ;
break;
case V_93 :
V_19 -> V_69 = V_94 ;
break;
case V_87 :
case V_95 :
case V_94 :
case V_89 :
default:
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_15 ,
V_19 -> V_69 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
return V_24 ;
}
static long F_32 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_69 ) {
case V_93 :
V_24 = F_20 ( V_19 , V_102 ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_69 = V_94 ;
break;
case V_43 :
F_11 ( & V_19 -> V_44 , L_16 ,
V_24 ) ;
F_28 ( V_19 , V_85 , 0 ) ;
break;
case V_103 :
F_11 ( & V_19 -> V_44 , L_16 ,
V_24 ) ;
V_24 = ERROR ;
F_28 ( V_19 ,
V_86 , 0 ) ;
break;
case V_35 :
F_33 ( L_16 , V_24 ) ;
V_24 = 0 ;
break;
}
break;
case V_96 :
V_24 = ERROR ;
break;
case V_84 :
break;
case V_89 :
case V_94 :
case V_95 :
case V_87 :
case V_83 :
case V_85 :
case V_86 :
case V_88 :
default:
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_17 ,
V_19 -> V_69 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
return V_24 ;
}
static long F_34 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_18 , V_19 -> V_69 ) ;
V_24 = F_35 ( V_19 -> V_31 . V_32 , V_104 ,
( T_2 ) V_19 -> V_105 | ( ( T_2 ) V_66 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_54 . V_106 =
F_36 ( * ( T_2 * ) V_19 -> V_107 ) ;
F_6 ( L_19 ,
V_19 -> V_54 . V_106 ) ;
} else {
F_6 ( L_20 , V_24 ) ;
V_24 = V_37 ;
}
if ( V_21 -> V_27 == V_75 ) {
V_24 = F_32 ( V_19 ) ;
} else if ( V_21 -> V_27 == V_102 ) {
V_24 = F_31 ( V_19 ) ;
} else {
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_21 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
}
return V_24 ;
}
static long F_37 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
T_4 V_27 ;
V_24 = F_35 ( V_19 -> V_31 . V_32 , V_108 , 30000 ,
0 , 0 , 0 , 0 ) ;
if ( V_24 == V_39 )
V_19 -> V_9 |= V_109 ;
else if ( V_24 != V_110 )
F_38 ( L_22 , V_24 ) ;
V_19 -> V_9 &= V_111 ;
V_19 -> V_112 . V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_115 = 0 ;
V_24 = F_39 ( V_19 -> V_60 ) ;
if ( V_24 ) {
F_33 ( L_23 ,
V_24 ) ;
return V_24 ;
}
V_24 = F_21 ( V_19 , & V_27 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_24 ,
V_24 ) ;
return V_24 ;
}
if ( V_27 == V_74 ) {
V_24 = F_20 ( V_19 , V_75 ) ;
switch ( V_24 ) {
case V_39 :
case V_103 :
case V_35 :
V_24 = V_37 ;
break;
case V_43 :
case V_42 :
break;
default:
V_19 -> V_69 = V_96 ;
V_24 = V_42 ;
break;
}
} else if ( V_27 == V_75 ) {
V_24 = F_32 ( V_19 ) ;
}
return V_24 ;
}
static void F_40 ( struct V_18 * V_19 )
{
int V_56 ;
long V_24 = V_37 ;
F_6 ( L_25 , V_19 -> V_9 ) ;
if ( V_19 -> V_9 & ( V_116 | V_117 ) ) {
V_19 -> V_9 &= V_111 ;
V_19 -> V_112 . V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_115 = 0 ;
V_19 -> V_69 = V_93 ;
F_39 ( V_19 -> V_60 ) ;
} else {
V_24 = F_16 ( V_19 ) ;
if ( V_24 == V_37 ) {
V_19 -> V_69 = V_93 ;
V_56 = V_19 -> V_64 . V_65 * V_66 ;
V_24 = F_41 ( V_19 -> V_31 . V_32 ,
V_19 -> V_64 . V_118 , V_56 ) ;
if ( V_24 == V_35 || V_24 == V_39 ) {
V_24 = F_37 ( V_19 ) ;
}
if ( V_24 != V_37 ) {
F_6 ( L_26 , V_24 ) ;
V_19 -> V_69 = V_88 ;
V_19 -> V_9 |= V_90 ;
F_16 ( V_19 ) ;
}
} else {
V_19 -> V_69 = V_88 ;
V_19 -> V_9 |= V_90 ;
}
}
}
static void F_42 ( struct V_18 * V_19 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
switch ( V_120 -> type ) {
case V_123 :
case V_124 :
if ( V_19 -> V_114 )
V_19 -> V_114 -= 1 ;
break;
case V_125 :
V_19 -> V_9 &= ~ V_126 ;
break;
case V_127 :
break;
default:
F_11 ( & V_19 -> V_44 , L_27 ,
V_120 -> type ) ;
break;
}
V_120 -> V_122 = NULL ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_129 ) ;
F_44 ( V_122 ) ;
if ( F_25 ( & V_19 -> V_97 ) && F_25 ( & V_19 -> V_98 ) &&
F_25 ( & V_19 -> V_130 ) && ( V_19 -> V_9 & V_99 ) ) {
V_19 -> V_9 &= ~ V_99 ;
F_24 ( & V_19 -> V_80 ) ;
}
}
static long F_45 ( struct V_18 * V_19 , bool V_131 )
{
long V_24 = 0 ;
struct V_20 * V_21 ;
V_21 = V_19 -> V_64 . V_67 + V_19 -> V_64 . V_68 ;
F_6 ( L_28 ,
V_19 -> V_9 , V_19 -> V_69 , ( int ) V_21 -> V_25 ) ;
if ( ! ( V_19 -> V_9 & V_132 ) && ! ( V_21 -> V_25 ) ) {
V_24 = F_35 ( V_19 -> V_31 . V_32 , V_133 , 0 , 0 , 0 ,
0 , 0 ) ;
if ( V_24 ) {
F_38 ( L_29 , V_24 ) ;
V_24 = 0 ;
}
} else if ( ( ( V_19 -> V_9 & V_134 ) &&
( V_19 -> V_9 & V_132 ) ) ||
( ( V_21 -> V_25 ) && ( ( V_21 -> V_25 != V_135 ) ||
( V_21 -> V_27 != V_136 ) ) ) ) {
if ( V_131 ) {
V_19 -> V_69 = V_86 ;
F_40 ( V_19 ) ;
V_24 = - 1 ;
} else if ( V_19 -> V_69 == V_94 ) {
F_28 ( V_19 ,
V_86 , 0 ) ;
}
V_19 -> V_9 &= ~ V_134 ;
if ( ( V_21 -> V_25 ) && ( ( V_21 -> V_25 != V_135 ) ||
( V_21 -> V_27 != V_136 ) ) )
F_38 ( L_30 ) ;
}
V_19 -> V_9 &= ~ ( V_137 | V_132 ) ;
return V_24 ;
}
static long F_46 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_31 ,
( int ) V_21 -> V_27 , V_19 -> V_9 , V_19 -> V_69 ) ;
switch ( V_21 -> V_27 ) {
case V_138 :
case V_139 :
case V_140 :
F_15 ( V_19 , true ) ;
if ( V_21 -> V_27 == V_138 )
V_19 -> V_9 &= ~ V_134 ;
switch ( V_19 -> V_69 ) {
case V_83 :
case V_88 :
case V_96 :
break;
case V_84 :
V_19 -> V_9 |= ( V_90 | V_117 ) ;
break;
case V_89 :
break;
case V_93 :
break;
case V_94 :
F_28 ( V_19 , V_87 ,
( V_90 |
V_117 ) ) ;
break;
case V_95 :
if ( ( V_19 -> V_114 > 0 ) ||
! F_25 ( & V_19 -> V_98 ) ||
! F_25 ( & V_19 -> V_130 ) ||
! F_25 ( & V_19 -> V_97 ) ) {
F_6 ( L_32 ,
V_19 -> V_114 ,
( int ) F_25 ( & V_19 -> V_98 ) ,
( int ) F_25 ( & V_19 -> V_130 ) ,
( int ) F_25 ( & V_19 -> V_97 ) ) ;
F_33 ( L_33 ) ;
} else {
F_6 ( L_34 ) ;
}
F_28 ( V_19 , V_87 ,
( V_90 |
V_117 ) ) ;
break;
case V_85 :
case V_86 :
case V_87 :
V_19 -> V_9 |= ( V_90 | V_117 ) ;
break;
}
break;
case V_141 :
F_6 ( L_35 ,
( int ) V_21 -> V_29 ) ;
switch ( V_19 -> V_69 ) {
case V_88 :
case V_93 :
case V_94 :
F_45 ( V_19 , false ) ;
break;
case V_95 :
V_19 -> V_142 = V_19 -> V_69 ;
V_19 -> V_9 |= V_137 ;
if ( V_21 -> V_29 == V_143 )
V_19 -> V_9 |= V_134 ;
F_28 ( V_19 , V_87 , 0 ) ;
break;
case V_83 :
case V_96 :
case V_84 :
case V_89 :
case V_85 :
case V_86 :
case V_87 :
F_38 ( L_36 ,
V_19 -> V_69 ) ;
break;
}
break;
case V_136 :
F_6 ( L_37 ,
( int ) V_21 -> V_29 ) ;
if ( V_19 -> V_9 & V_137 ) {
V_19 -> V_9 |= V_132 ;
} else {
if ( ( V_21 -> V_29 == V_143 ) ||
( V_19 -> V_9 & V_134 ) ) {
F_28 ( V_19 ,
V_86 ,
0 ) ;
V_19 -> V_9 &= ~ V_134 ;
}
}
break;
default:
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_38 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 , V_85 ,
V_90 ) ;
break;
}
V_24 = V_19 -> V_9 & V_82 ;
F_6 ( L_39 ,
V_19 -> V_9 , V_19 -> V_69 , V_24 ) ;
return V_24 ;
}
static void F_47 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
long V_24 ;
bool V_144 = true ;
volatile T_5 V_25 ;
F_6 ( L_40 ,
V_19 -> V_9 , V_19 -> V_69 , V_19 -> V_64 . V_68 ) ;
V_24 = V_19 -> V_9 & V_82 ;
V_21 = V_19 -> V_64 . V_67 + V_19 -> V_64 . V_68 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_145:
V_19 -> V_64 . V_68 =
( V_19 -> V_64 . V_68 + 1 ) & V_19 -> V_64 . V_70 ;
if ( ! V_24 ) {
V_24 = F_48 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_135 ) {
V_24 = F_46 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_117 ) {
F_6 ( L_41 ) ;
if ( V_19 -> V_64 . V_68 )
V_19 -> V_64 . V_68 -= 1 ;
else
V_19 -> V_64 . V_68 = V_19 -> V_64 . V_70 ;
break;
}
}
V_21 -> V_25 = V_76 ;
V_21 = V_19 -> V_64 . V_67 + V_19 -> V_64 . V_68 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
}
if ( ! V_24 ) {
if ( V_144 ) {
F_39 ( V_19 -> V_60 ) ;
V_144 = false ;
F_6 ( L_42 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_145;
}
F_6 ( L_43 , V_24 ) ;
}
static void F_49 ( struct V_18 * V_19 )
{
struct V_119 * V_120 , * V_146 ;
F_6 ( L_44 ,
( int ) F_25 ( & V_19 -> V_130 ) ,
V_19 -> V_112 . V_147 ) ;
F_50 (cmd, nxt, &vscsi->waiting_rsp, list) {
F_51 ( & V_120 -> V_128 ) ;
F_42 ( V_19 , V_120 ) ;
}
}
static struct V_119 * F_52 ( struct V_18 * V_19 )
{
struct V_119 * V_120 = NULL ;
struct V_121 * V_122 ;
V_122 = F_53 ( & V_19 -> V_148 ) ;
if ( V_122 ) {
V_120 = F_54 ( & V_19 -> V_129 ,
struct V_119 , V_128 ) ;
if ( V_120 ) {
if ( V_120 -> V_149 )
V_120 -> V_149 = NULL ;
V_120 -> V_9 &= ~ ( V_150 ) ;
F_51 ( & V_120 -> V_128 ) ;
V_120 -> V_122 = V_122 ;
V_120 -> type = V_127 ;
memset ( & V_120 -> V_1 , 0 , sizeof( V_120 -> V_1 ) ) ;
} else {
F_44 ( V_122 ) ;
}
}
return V_120 ;
}
static void F_27 ( struct V_18 * V_19 )
{
int V_151 = false ;
long V_24 = 0 ;
F_6 ( L_45 , V_19 -> V_9 ,
V_19 -> V_69 ) ;
if ( V_19 -> V_69 != V_93 || V_19 -> V_9 & V_117 )
V_151 = true ;
switch ( V_19 -> V_69 ) {
case V_84 :
F_16 ( V_19 ) ;
F_19 () ;
F_55 () ;
if ( V_19 -> V_9 & V_91 ) {
V_19 -> V_9 &= ~ V_91 ;
F_24 ( & V_19 -> V_92 ) ;
}
break;
case V_86 :
F_40 ( V_19 ) ;
F_6 ( L_46 , V_19 -> V_9 ) ;
break;
case V_85 :
F_16 ( V_19 ) ;
V_19 -> V_9 &= ~ ( V_82 | V_81 ) ;
V_19 -> V_9 |= V_90 ;
if ( V_19 -> V_152 . V_153 )
V_19 -> V_69 = V_88 ;
else
V_19 -> V_69 = V_89 ;
F_6 ( L_47 ,
V_19 -> V_9 , V_19 -> V_69 ) ;
break;
case V_87 :
V_19 -> V_112 . V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_115 = 0 ;
if ( V_19 -> V_9 & V_137 ) {
V_19 -> V_69 = V_19 -> V_142 ;
V_19 -> V_142 = 0 ;
V_24 = F_45 ( V_19 , true ) ;
V_19 -> V_9 &= ~ V_81 ;
if ( V_24 )
break;
} else if ( V_19 -> V_9 & V_117 ) {
V_19 -> V_69 = V_93 ;
V_19 -> V_9 &= V_111 ;
} else {
V_19 -> V_69 = V_94 ;
V_19 -> V_9 &= ~ V_81 ;
}
F_6 ( L_48 ,
V_19 -> V_9 , V_19 -> V_69 ) ;
F_47 ( V_19 ) ;
break;
case V_88 :
V_19 -> V_9 &= ~ V_81 ;
F_6 ( L_49 ,
V_19 -> V_9 , V_19 -> V_69 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_50 ,
V_19 -> V_69 ) ;
break;
}
if ( V_151 )
F_49 ( V_19 ) ;
if ( V_19 -> V_62 != 0 ) {
V_19 -> V_9 |= V_19 -> V_63 ;
F_28 ( V_19 , V_19 -> V_62 , 0 ) ;
V_19 -> V_62 = 0 ;
V_19 -> V_63 = 0 ;
F_6 ( L_51 ,
V_19 -> V_9 , V_19 -> V_69 , V_19 -> V_63 ,
V_19 -> V_62 ) ;
}
F_6 ( L_52 ,
V_19 -> V_9 , V_19 -> V_69 , V_19 -> V_61 ) ;
}
static long F_56 ( struct V_18 * V_19 ,
struct V_119 * V_120 ,
struct V_20 * V_21 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
long V_24 = 0 ;
T_3 V_154 ;
V_154 = F_57 ( V_21 -> V_155 ) ;
if ( ( V_154 > V_156 ) || ( V_154 == 0 ) ) {
F_11 ( & V_19 -> V_44 , L_53 , V_154 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
return V_157 ;
}
V_24 = F_58 ( V_154 , V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_21 -> V_161 ) ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_122 -> V_163 -> V_164 ) ;
switch ( V_24 ) {
case V_39 :
V_120 -> V_165 = F_59 () ;
V_122 -> V_166 = V_21 -> V_161 ;
V_122 -> V_167 = V_154 ;
F_6 ( L_54 ,
F_36 ( V_21 -> V_161 ) , V_120 -> V_165 ) ;
break;
case V_168 :
if ( F_3 ( V_19 ) )
F_28 ( V_19 ,
V_86 ,
( V_90 |
V_116 ) ) ;
else
F_28 ( V_19 ,
V_86 , 0 ) ;
F_11 ( & V_19 -> V_44 , L_55 ,
V_24 ) ;
break;
case V_169 :
case V_170 :
default:
F_11 ( & V_19 -> V_44 , L_55 ,
V_24 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
return V_24 ;
}
static long F_60 ( struct V_18 * V_19 ,
struct V_121 * V_122 )
{
struct V_171 * V_172 = & F_61 ( V_122 ) -> V_172 . V_173 ;
struct V_174 * V_175 ;
T_4 V_100 = 0 ;
T_6 V_176 ;
long V_24 ;
V_172 -> V_177 . V_29 = F_62 ( V_178 ) ;
if ( F_57 ( V_172 -> V_177 . V_179 ) > sizeof( * V_175 ) ) {
V_172 -> V_177 . V_29 = F_62 ( V_180 ) ;
return 0 ;
}
V_175 = F_63 ( & V_19 -> V_60 -> V_44 , sizeof( * V_175 ) , & V_176 ,
V_181 ) ;
if ( ! V_175 ) {
F_11 ( & V_19 -> V_44 , L_56 ,
V_122 -> V_148 ) ;
V_172 -> V_177 . V_29 = F_62 ( V_180 ) ;
return 0 ;
}
V_24 = F_58 ( F_57 ( V_172 -> V_177 . V_179 ) ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_172 -> V_22 ) ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_176 ) ;
if ( V_24 != V_39 ) {
if ( V_24 == V_168 ) {
if ( F_3 ( V_19 ) )
V_100 = ( V_90 | V_116 ) ;
}
F_33 ( L_57 ,
V_24 ) ;
F_6 ( L_58 ,
F_36 ( V_172 -> V_22 ) , V_19 -> V_9 , V_100 ) ;
F_28 ( V_19 , V_86 ,
V_100 ) ;
goto V_182;
}
if ( V_19 -> V_54 . V_106 == 0 )
V_19 -> V_54 . V_106 =
F_64 ( V_175 -> V_106 ) ;
strncpy ( V_19 -> V_54 . V_183 , V_175 -> V_183 ,
sizeof( V_19 -> V_54 . V_183 ) ) ;
strncpy ( V_19 -> V_54 . V_184 , V_175 -> V_184 ,
sizeof( V_19 -> V_54 . V_184 ) ) ;
V_19 -> V_54 . V_185 = F_64 ( V_175 -> V_185 ) ;
V_19 -> V_54 . V_55 = F_64 ( V_175 -> V_55 ) ;
strncpy ( V_175 -> V_183 , V_186 ,
sizeof( V_175 -> V_183 ) ) ;
strncpy ( V_175 -> V_184 , V_19 -> V_31 . V_184 ,
sizeof( V_175 -> V_184 ) ) ;
V_175 -> V_106 = F_2 ( V_19 -> V_31 . V_187 ) ;
V_175 -> V_185 = F_2 ( V_188 ) ;
V_175 -> V_55 = F_2 ( V_189 ) ;
memset ( & V_175 -> V_190 [ 0 ] , 0 , sizeof( V_175 -> V_190 ) ) ;
V_175 -> V_190 [ 0 ] = F_2 ( V_191 ) ;
F_65 () ;
V_24 = F_58 ( sizeof( * V_175 ) , V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_176 , V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_172 -> V_22 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_170 :
case V_169 :
case V_168 :
if ( F_3 ( V_19 ) )
V_100 = ( V_90 | V_116 ) ;
default:
F_11 ( & V_19 -> V_44 , L_59 ,
V_24 ) ;
F_28 ( V_19 ,
V_86 ,
V_100 ) ;
break;
}
V_182:
F_66 ( & V_19 -> V_60 -> V_44 , sizeof( * V_175 ) , V_175 , V_176 ) ;
F_6 ( L_60 , V_24 ) ;
return V_24 ;
}
static int F_67 ( struct V_18 * V_19 , struct V_121 * V_122 )
{
struct V_192 * V_172 = & F_61 ( V_122 ) -> V_172 . V_193 ;
struct V_193 * V_194 ;
struct V_195 * V_177 ;
T_6 V_176 ;
T_3 V_196 , V_154 , V_29 , V_197 , V_198 ;
T_1 V_199 ;
T_4 V_100 = 0 ;
long V_24 = 0 ;
V_196 = F_57 ( V_172 -> V_177 . V_179 ) ;
V_197 = F_68 ( struct V_193 , V_200 ) ;
if ( ( V_196 < V_197 ) || ( V_196 > V_66 ) ) {
F_33 ( L_61 , V_196 ) ;
V_172 -> V_177 . V_29 = F_62 ( V_180 ) ;
return 0 ;
}
V_194 = F_63 ( & V_19 -> V_60 -> V_44 , V_196 , & V_176 ,
V_181 ) ;
if ( ! V_194 ) {
F_11 ( & V_19 -> V_44 , L_56 ,
V_122 -> V_148 ) ;
V_172 -> V_177 . V_29 = F_62 ( V_180 ) ;
return 0 ;
}
V_24 = F_58 ( V_196 , V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_172 -> V_22 ) ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_176 ) ;
if ( V_24 == V_39 ) {
strncpy ( V_194 -> V_201 , F_69 ( & V_19 -> V_60 -> V_44 ) ,
V_202 ) ;
V_154 = V_196 - V_197 ;
V_29 = V_178 ;
V_177 = (struct V_195 * ) & V_194 -> V_200 ;
while ( ( V_154 > 0 ) && ( V_29 == V_178 ) && ! V_24 ) {
F_6 ( L_62 ,
V_154 , F_64 ( V_177 -> V_203 ) ,
F_57 ( V_177 -> V_179 ) ) ;
V_198 = F_57 ( V_177 -> V_179 ) ;
if ( V_198 > V_154 ) {
F_11 ( & V_19 -> V_44 , L_63 ) ;
V_29 = V_180 ;
break;
}
if ( V_198 == 0 ) {
F_11 ( & V_19 -> V_44 , L_64 ) ;
V_29 = V_180 ;
break;
}
switch ( V_177 -> V_203 ) {
default:
F_6 ( L_65 ) ;
V_177 -> V_204 = 0 ;
V_199 = F_2 ( ( T_1 ) V_205 ) ;
V_194 -> V_9 &= ~ V_199 ;
break;
}
V_154 = V_154 - V_198 ;
V_177 = (struct V_195 * )
( ( char * ) V_177 + V_198 ) ;
}
V_172 -> V_177 . V_29 = F_62 ( V_29 ) ;
F_65 () ;
V_24 = F_58 ( V_196 , V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_176 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_172 -> V_22 ) ) ;
if ( V_24 != V_39 ) {
F_6 ( L_66 ,
V_24 ) ;
if ( V_24 == V_168 ) {
if ( F_3 ( V_19 ) )
V_100 = ( V_90 |
V_116 ) ;
}
F_33 ( L_67 ,
V_24 ) ;
F_28 ( V_19 ,
V_86 ,
V_100 ) ;
}
}
F_66 ( & V_19 -> V_60 -> V_44 , V_196 , V_194 , V_176 ) ;
F_6 ( L_68 ,
V_24 , V_19 -> V_53 ) ;
return V_24 ;
}
static long F_70 ( struct V_18 * V_19 , struct V_121 * V_122 )
{
struct V_206 * V_172 = (struct V_206 * ) & F_61 ( V_122 ) -> V_172 ;
struct V_207 * V_208 ;
long V_24 = V_37 ;
switch ( F_64 ( V_172 -> type ) ) {
case V_209 :
V_208 = & F_61 ( V_122 ) -> V_172 . V_210 ;
V_19 -> V_211 = F_36 ( V_208 -> V_22 ) ;
V_19 -> V_212 = F_36 ( V_208 -> V_177 . V_213 ) ;
V_172 -> V_29 = F_62 ( V_178 ) ;
break;
case V_214 :
V_24 = F_60 ( V_19 , V_122 ) ;
break;
case V_215 :
V_24 = F_67 ( V_19 , V_122 ) ;
break;
case V_216 :
if ( V_19 -> V_69 == V_94 ) {
V_19 -> V_217 = true ;
V_172 -> V_29 = F_62 ( V_178 ) ;
} else {
F_33 ( L_69 ) ;
V_172 -> V_29 = F_62 ( V_180 ) ;
}
break;
default:
V_172 -> V_29 = F_62 ( V_218 ) ;
break;
}
return V_24 ;
}
static void F_71 ( struct V_18 * V_19 , long V_24 )
{
T_7 V_219 ;
if ( V_24 != V_103 ) {
F_49 ( V_19 ) ;
if ( V_24 == V_35 )
V_19 -> V_9 |= V_116 ;
if ( ! ( V_19 -> V_9 & V_90 ) ) {
V_19 -> V_9 |= V_90 ;
if ( ! ( V_19 -> V_69 & ( V_85 |
V_86 |
V_88 | V_96 ) ) ) {
F_11 ( & V_19 -> V_44 , L_70 ,
V_19 -> V_69 , V_19 -> V_9 , V_24 ) ;
}
F_28 ( V_19 ,
V_86 , 0 ) ;
}
return;
}
if ( ( V_19 -> V_112 . V_113 < V_220 ) ||
( V_19 -> V_69 == V_95 ) ) {
F_6 ( L_71 ,
V_19 -> V_9 , ( int ) V_19 -> V_112 . V_147 ,
V_19 -> V_112 . V_113 ) ;
if ( ! V_19 -> V_112 . V_147 ) {
if ( V_19 -> V_112 . V_113 <
V_220 ) {
V_219 = V_221 ;
} else {
V_219 = F_72 ( V_222 , 0 ) ;
}
V_19 -> V_112 . V_147 = true ;
F_73 ( & V_19 -> V_112 . V_223 , V_219 ,
V_224 ) ;
}
} else {
V_19 -> V_9 |= V_90 ;
F_49 ( V_19 ) ;
if ( ! ( V_19 -> V_69 & ( V_85 |
V_86 |
V_88 | V_96 ) ) ) {
F_11 ( & V_19 -> V_44 , L_72 ) ;
F_28 ( V_19 ,
V_86 ,
0 ) ;
}
}
}
static void F_74 ( struct V_18 * V_19 )
{
T_2 V_225 = 0 ;
struct V_20 * V_21 = (struct V_20 * ) & V_225 ;
struct V_119 * V_120 , * V_146 ;
struct V_121 * V_122 ;
long V_24 = V_37 ;
bool V_226 = false ;
if ( ! ( V_19 -> V_9 & V_90 ) ) {
do {
V_226 = false ;
F_50 (cmd, nxt, &vscsi->waiting_rsp,
list) {
if ( V_120 -> V_9 & V_150 )
continue;
if ( V_120 -> V_149 ) {
V_226 = true ;
V_120 -> V_149 -> V_9 &= ~ ( V_150 ) ;
V_120 -> V_149 = NULL ;
}
if ( V_120 -> V_1 . V_227 & V_228 &&
! ( V_120 -> V_1 . V_227 & V_229 ) ) {
F_51 ( & V_120 -> V_128 ) ;
F_42 ( V_19 ,
V_120 ) ;
V_19 -> V_115 += 1 ;
} else {
V_122 = V_120 -> V_122 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_120 -> V_3 . V_27 ;
if ( V_120 -> V_9 & V_230 )
V_21 -> V_29 = V_231 ;
V_21 -> V_155 = F_62 ( V_120 -> V_3 . V_154 ) ;
V_24 = F_4 ( V_19 -> V_60 -> V_232 ,
F_36 ( V_225 ) ,
F_36 ( V_120 -> V_3 . V_213 ) ) ;
F_6 ( L_73 ,
V_120 , F_36 ( V_120 -> V_3 . V_213 ) , V_24 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_112 . V_113 = 0 ;
F_51 ( & V_120 -> V_128 ) ;
F_42 ( V_19 ,
V_120 ) ;
} else {
F_71 ( V_19 , V_24 ) ;
break;
}
}
}
} while ( V_226 );
if ( ! V_24 ) {
V_19 -> V_112 . V_113 = 0 ;
}
} else {
F_49 ( V_19 ) ;
}
}
static void F_75 ( struct V_18 * V_19 ,
struct V_119 * V_120 ,
struct V_20 * V_21 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_206 * V_172 = (struct V_206 * ) & F_61 ( V_122 ) -> V_172 ;
T_4 V_100 = 0 ;
long V_24 ;
F_65 () ;
V_24 = F_58 ( sizeof( struct V_206 ) ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_122 -> V_163 -> V_164 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_21 -> V_161 ) ) ;
if ( ! V_24 ) {
V_120 -> V_3 . V_27 = V_233 ;
V_120 -> V_3 . V_154 = sizeof( struct V_206 ) ;
V_120 -> V_3 . V_213 = V_172 -> V_213 ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_130 ) ;
F_74 ( V_19 ) ;
} else {
F_6 ( L_74 , V_24 ) ;
if ( V_24 == V_168 ) {
if ( F_3 ( V_19 ) )
V_100 = ( V_90 | V_116 ) ;
}
F_11 ( & V_19 -> V_44 , L_75 ,
V_24 ) ;
F_42 ( V_19 , V_120 ) ;
F_28 ( V_19 , V_86 ,
V_100 ) ;
}
}
static long F_76 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_121 * V_122 ;
struct V_119 * V_120 ;
struct V_206 * V_172 ;
long V_24 = V_37 ;
switch ( V_19 -> V_69 ) {
case V_93 :
F_6 ( L_76 ,
V_19 -> V_9 ) ;
return V_37 ;
case V_95 :
case V_94 :
break;
case V_84 :
case V_87 :
case V_85 :
case V_86 :
default:
F_11 ( & V_19 -> V_44 , L_77 ,
V_19 -> V_69 ) ;
return V_37 ;
}
V_120 = F_52 ( V_19 ) ;
if ( ! V_120 ) {
F_11 ( & V_19 -> V_44 , L_78 ,
V_19 -> V_114 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
return ERROR ;
}
V_122 = V_120 -> V_122 ;
V_120 -> type = V_125 ;
V_24 = F_56 ( V_19 , V_120 , V_21 ) ;
if ( ! V_24 ) {
V_172 = (struct V_206 * ) & F_61 ( V_122 ) -> V_172 ;
F_6 ( L_79 , F_64 ( V_172 -> type ) ) ;
V_24 = F_70 ( V_19 , V_122 ) ;
F_6 ( L_80 , F_57 ( V_172 -> V_29 ) ,
V_24 ) ;
if ( ! V_24 )
F_75 ( V_19 , V_120 , V_21 ) ;
} else {
F_42 ( V_19 , V_120 ) ;
}
F_6 ( L_81 , V_24 ) ;
return V_24 ;
}
static long F_77 ( struct V_18 * V_19 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_234 * V_3 = & F_61 ( V_122 ) -> V_235 . V_236 ;
struct V_237 * V_238 ;
T_4 V_100 = 0 ;
long V_24 = V_37 ;
memset ( V_3 , 0 , sizeof( struct V_234 ) ) ;
V_3 -> V_239 = V_240 ;
V_3 -> V_241 = F_2 ( V_19 -> V_242 ) ;
V_3 -> V_213 = V_120 -> V_3 . V_213 ;
V_3 -> V_243 = F_2 ( V_156 ) ;
V_3 -> V_244 = F_2 ( V_156 ) ;
V_238 = (struct V_237 * ) & V_3 -> V_245 ;
V_238 -> V_246 = V_247 ;
V_19 -> V_115 = 0 ;
V_120 -> V_3 . V_154 = sizeof( struct V_234 ) ;
F_65 () ;
V_24 = F_58 ( V_120 -> V_3 . V_154 , V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_122 -> V_163 -> V_164 , V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_122 -> V_166 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_168 :
if ( F_3 ( V_19 ) )
V_100 = V_90 | V_116 ;
F_11 ( & V_19 -> V_44 , L_82 ,
V_24 ) ;
F_28 ( V_19 , V_86 ,
V_100 ) ;
break;
case V_170 :
case V_169 :
default:
F_11 ( & V_19 -> V_44 , L_82 ,
V_24 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
return V_24 ;
}
static long F_78 ( struct V_18 * V_19 ,
struct V_119 * V_120 , T_1 V_248 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_249 * V_250 = & F_61 ( V_122 ) -> V_235 . V_251 ;
struct V_237 * V_238 ;
T_4 V_100 = 0 ;
long V_24 = V_37 ;
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
V_250 -> V_239 = V_252 ;
V_250 -> V_248 = F_2 ( V_248 ) ;
V_250 -> V_213 = V_120 -> V_3 . V_213 ;
V_238 = (struct V_237 * ) & V_250 -> V_245 ;
V_238 -> V_246 = V_247 ;
V_120 -> V_3 . V_154 = sizeof( * V_250 ) ;
F_65 () ;
V_24 = F_58 ( V_120 -> V_3 . V_154 , V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_122 -> V_163 -> V_164 , V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_122 -> V_166 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_168 :
if ( F_3 ( V_19 ) )
V_100 = V_90 | V_116 ;
F_11 ( & V_19 -> V_44 , L_83 ,
V_24 ) ;
F_28 ( V_19 , V_86 ,
V_100 ) ;
break;
case V_170 :
case V_169 :
default:
F_11 ( & V_19 -> V_44 , L_83 ,
V_24 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
return V_24 ;
}
static int F_79 ( struct V_253 * V_152 )
{
char * V_201 = V_152 -> V_254 ;
struct V_255 * V_256 ;
int V_24 ;
if ( V_152 -> V_257 ) {
F_6 ( L_84 ) ;
return 0 ;
}
V_256 = F_80 ( sizeof( * V_256 ) , V_258 ) ;
if ( ! V_256 ) {
F_38 ( L_85 ) ;
return - V_259 ;
}
V_256 -> V_260 = F_81 ( & V_152 -> V_261 , 0 , 0 ,
V_262 , V_201 , V_256 ,
NULL ) ;
if ( F_82 ( V_256 -> V_260 ) ) {
V_24 = F_83 ( V_256 -> V_260 ) ;
goto V_263;
}
V_152 -> V_257 = V_256 ;
return 0 ;
V_263:
F_84 ( V_256 ) ;
return V_24 ;
}
static int F_85 ( struct V_253 * V_152 )
{
struct V_264 * V_260 ;
struct V_255 * V_256 ;
V_256 = V_152 -> V_257 ;
if ( ! V_256 )
return - V_265 ;
V_260 = V_256 -> V_260 ;
if ( ! V_260 )
return - V_265 ;
F_86 ( V_260 ) ;
F_87 ( V_260 ) ;
F_88 ( V_260 ) ;
V_152 -> V_257 = NULL ;
F_84 ( V_256 ) ;
return 0 ;
}
static long F_89 ( struct V_18 * V_19 ,
struct V_119 * V_120 ,
struct V_20 * V_21 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_266 * V_267 = & F_61 ( V_122 ) -> V_235 . V_268 ;
struct V_269 {
T_8 V_270 ;
T_8 V_271 ;
} * V_272 , * V_152 ;
struct V_237 * V_238 ;
T_1 V_248 = 0x0 ;
long V_24 = V_37 ;
V_272 = (struct V_269 * ) V_267 -> V_273 ;
V_152 = (struct V_269 * ) V_267 -> V_274 ;
V_238 = (struct V_237 * ) & V_267 -> V_275 ;
if ( F_64 ( V_267 -> V_276 ) > V_156 )
V_248 = V_277 ;
else if ( F_64 ( V_267 -> V_276 ) < 64 )
V_248 = V_278 ;
else if ( ( F_36 ( V_272 -> V_270 ) > ( V_279 - 1 ) ) ||
( F_36 ( V_152 -> V_270 ) > ( V_279 - 1 ) ) )
V_248 = V_280 ;
else if ( V_267 -> V_281 & V_282 )
V_248 = V_283 ;
else if ( V_238 -> V_246 & ( ~ V_247 ) )
V_248 = V_284 ;
else if ( ( V_238 -> V_246 & V_247 ) == 0 )
V_248 = V_284 ;
if ( V_19 -> V_69 == V_95 )
V_248 = V_285 ;
V_24 = F_79 ( & V_19 -> V_152 ) ;
if ( V_24 )
V_248 = V_278 ;
V_120 -> V_3 . V_27 = V_286 ;
V_120 -> V_3 . V_213 = V_267 -> V_213 ;
F_6 ( L_86 , V_248 ) ;
if ( V_248 )
V_24 = F_78 ( V_19 , V_120 , V_248 ) ;
else
V_24 = F_77 ( V_19 , V_120 ) ;
if ( ! V_24 ) {
if ( ! V_248 )
V_19 -> V_69 = V_95 ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_130 ) ;
F_74 ( V_19 ) ;
} else {
F_42 ( V_19 , V_120 ) ;
}
F_6 ( L_87 , V_24 ) ;
return V_24 ;
}
static long F_90 ( struct V_18 * V_19 ,
struct V_119 * V_120 ,
struct V_20 * V_21 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_287 * V_288 = & F_61 ( V_122 ) -> V_235 . V_289 ;
long V_24 = V_37 ;
if ( ( V_19 -> V_114 > 0 ) || ! F_25 ( & V_19 -> V_98 ) ||
! F_25 ( & V_19 -> V_130 ) ) {
F_11 ( & V_19 -> V_44 , L_88 ) ;
F_28 ( V_19 , V_85 , 0 ) ;
} else {
V_120 -> V_3 . V_27 = V_290 ;
V_120 -> V_3 . V_213 = V_288 -> V_213 ;
V_120 -> V_3 . V_154 = sizeof( struct V_206 ) ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_130 ) ;
F_74 ( V_19 ) ;
F_28 ( V_19 , V_87 , 0 ) ;
}
return V_24 ;
}
static void F_91 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_291 * V_235 ;
struct V_292 * V_293 ;
long V_24 ;
if ( V_19 -> V_242 - V_19 -> V_114 <= 0 ) {
F_11 ( & V_19 -> V_44 , L_89 ,
V_19 -> V_242 , V_19 -> V_114 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
return;
}
V_120 = F_52 ( V_19 ) ;
if ( ! V_120 ) {
F_11 ( & V_19 -> V_44 , L_90 ,
V_19 -> V_114 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
return;
}
V_122 = V_120 -> V_122 ;
V_235 = & F_61 ( V_122 ) -> V_235 . V_120 ;
V_24 = F_56 ( V_19 , V_120 , V_21 ) ;
if ( V_24 ) {
F_42 ( V_19 , V_120 ) ;
return;
}
if ( V_19 -> V_69 == V_95 ) {
switch ( V_235 -> V_239 ) {
case V_294 :
V_24 = F_89 ( V_19 , V_120 , V_21 ) ;
break;
case V_295 :
V_293 = & F_61 ( V_122 ) -> V_235 . V_296 ;
F_6 ( L_91 , V_293 -> V_213 ,
V_293 -> V_213 ) ;
V_120 -> V_3 . V_213 = V_293 -> V_213 ;
V_19 -> V_114 += 1 ;
V_120 -> type = V_123 ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_98 ) ;
F_30 ( V_19 -> V_101 , & V_120 -> V_78 ) ;
break;
case V_297 :
F_6 ( L_92 , V_235 -> V_213 ,
V_235 -> V_213 ) ;
V_120 -> V_3 . V_213 = V_235 -> V_213 ;
V_19 -> V_114 += 1 ;
V_120 -> type = V_124 ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_98 ) ;
F_30 ( V_19 -> V_101 , & V_120 -> V_78 ) ;
break;
case V_298 :
V_24 = F_90 ( V_19 , V_120 , V_21 ) ;
break;
case V_299 :
case V_300 :
default:
F_42 ( V_19 , V_120 ) ;
F_11 ( & V_19 -> V_44 , L_93 ,
( T_4 ) V_235 -> V_239 ) ;
F_28 ( V_19 ,
V_86 , 0 ) ;
break;
}
} else if ( V_235 -> V_239 == V_294 && V_19 -> V_69 == V_94 ) {
V_24 = F_89 ( V_19 , V_120 , V_21 ) ;
} else {
F_42 ( V_19 , V_120 ) ;
F_11 ( & V_19 -> V_44 , L_94 ,
V_19 -> V_69 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
}
}
static long F_92 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_24 ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = ( T_5 ) V_28 ;
V_21 -> V_29 = V_301 ;
V_24 = F_4 ( V_19 -> V_31 . V_32 , F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_35 :
V_19 -> V_9 |= V_116 ;
case V_103 :
V_19 -> V_9 |= V_90 ;
case V_302 :
F_11 ( & V_19 -> V_44 , L_95 ,
V_24 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_96 ,
V_24 ) ;
F_28 ( V_19 , V_85 , 0 ) ;
break;
}
return V_24 ;
}
static long F_48 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
switch ( V_21 -> V_25 ) {
case V_26 :
switch ( V_21 -> V_27 ) {
case V_303 :
case V_304 :
case V_305 :
case V_306 :
if ( V_19 -> V_9 & V_126 ) {
V_24 = ERROR ;
F_11 ( & V_19 -> V_44 , L_97 ) ;
F_28 ( V_19 ,
V_86 ,
0 ) ;
} else {
V_19 -> V_9 |= V_126 ;
V_24 = F_76 ( V_19 , V_21 ) ;
}
break;
case V_290 :
F_91 ( V_19 , V_21 ) ;
break;
case V_28 :
if ( V_21 -> V_29 == V_30 )
F_92 ( V_19 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_98 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 ,
V_86 , 0 ) ;
break;
}
break;
case V_135 :
V_24 = F_46 ( V_19 , V_21 ) ;
break;
case V_73 :
V_24 = F_34 ( V_19 , V_21 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_99 ,
( T_4 ) V_21 -> V_25 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
break;
}
V_24 = V_19 -> V_9 & V_82 ;
return V_24 ;
}
static int F_93 ( struct V_18 * V_19 )
{
struct V_307 * V_308 = V_19 -> V_60 ;
const T_9 * V_309 ;
const T_9 * V_310 ;
V_309 = ( const T_9 * ) F_94 ( V_308 ,
L_100 ,
NULL ) ;
if ( ! V_309 ) {
F_38 ( L_101 ) ;
return - 1 ;
}
V_19 -> V_31 . V_158 [ V_162 ] . V_160 = F_64 ( * V_309 ) ;
V_309 ++ ;
V_310 = ( const T_9 * ) F_94 ( V_308 , L_102 ,
NULL ) ;
if ( ! V_310 ) {
F_33 ( L_103 ) ;
V_309 ++ ;
} else {
V_309 += F_64 ( * V_310 ) ;
}
V_310 = ( const T_9 * ) F_94 ( V_308 , L_104 ,
NULL ) ;
if ( ! V_310 ) {
F_33 ( L_105 ) ;
V_309 ++ ;
} else {
V_309 += F_64 ( * V_310 ) ;
}
V_19 -> V_31 . V_158 [ V_159 ] . V_160 = F_64 ( * V_309 ) ;
return 0 ;
}
static struct V_253 * F_95 ( const char * V_201 )
{
struct V_253 * V_152 = NULL ;
struct V_307 * V_308 ;
struct V_18 * V_19 ;
F_9 ( & V_311 ) ;
F_96 (vscsi, &ibmvscsis_dev_list, list) {
V_308 = V_19 -> V_60 ;
if ( ! strcmp ( F_69 ( & V_308 -> V_44 ) , V_201 ) ) {
V_152 = & V_19 -> V_152 ;
break;
}
}
F_10 ( & V_311 ) ;
return V_152 ;
}
static void F_97 ( struct V_18 * V_19 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_291 * V_235 = (struct V_291 * ) V_122 -> V_163 -> V_312 ;
struct V_255 * V_256 ;
T_2 V_313 = 0 ;
enum V_314 V_315 ;
int V_316 = 0 ;
int V_24 = 0 ;
V_256 = V_19 -> V_152 . V_257 ;
if ( V_235 -> V_317 & 0x03 ) {
F_11 ( & V_19 -> V_44 , L_106 ) ;
F_9 ( & V_19 -> V_40 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
F_42 ( V_19 , V_120 ) ;
F_10 ( & V_19 -> V_40 ) ;
return;
}
if ( F_98 ( V_235 , & V_315 , & V_313 ) ) {
F_11 ( & V_19 -> V_44 , L_107 ,
V_235 -> V_213 ) ;
goto V_318;
}
V_120 -> V_3 . V_319 = V_235 -> V_319 ;
switch ( V_235 -> V_320 ) {
case V_321 :
V_316 = V_322 ;
break;
case V_323 :
V_316 = V_324 ;
break;
case V_325 :
V_316 = V_326 ;
break;
case V_327 :
V_316 = V_328 ;
break;
default:
F_11 ( & V_19 -> V_44 , L_108 ,
V_235 -> V_320 ) ;
goto V_318;
}
V_120 -> V_1 . V_213 = F_36 ( V_235 -> V_213 ) ;
F_9 ( & V_19 -> V_40 ) ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_97 ) ;
F_10 ( & V_19 -> V_40 ) ;
V_235 -> V_329 . V_330 [ 0 ] &= 0x3f ;
V_24 = F_99 ( & V_120 -> V_1 , V_256 -> V_260 , V_235 -> V_331 ,
V_120 -> V_332 , F_100 ( & V_235 -> V_329 ) ,
V_313 , V_316 , V_315 , 0 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_109 , V_24 ) ;
F_9 ( & V_19 -> V_40 ) ;
F_51 ( & V_120 -> V_128 ) ;
F_42 ( V_19 , V_120 ) ;
F_10 ( & V_19 -> V_40 ) ;
goto V_318;
}
return;
V_318:
F_9 ( & V_19 -> V_40 ) ;
F_28 ( V_19 , V_86 , 0 ) ;
F_10 ( & V_19 -> V_40 ) ;
}
static void F_101 ( struct V_18 * V_19 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_292 * V_333 = & F_61 ( V_122 ) -> V_235 . V_296 ;
int V_334 ;
T_2 V_335 = 0 ;
int V_24 = 0 ;
struct V_255 * V_256 ;
V_256 = V_19 -> V_152 . V_257 ;
V_120 -> V_3 . V_319 = V_333 -> V_319 ;
switch ( V_333 -> V_336 ) {
case V_337 :
V_334 = V_338 ;
V_335 = F_36 ( V_333 -> V_339 ) ;
break;
case V_340 :
V_334 = V_341 ;
break;
case V_342 :
V_334 = V_343 ;
break;
case V_344 :
V_334 = V_345 ;
break;
case V_346 :
V_334 = V_347 ;
break;
default:
F_11 ( & V_19 -> V_44 , L_110 ,
V_333 -> V_336 ) ;
V_120 -> V_1 . V_348 -> V_349 =
V_350 ;
V_24 = - 1 ;
break;
}
if ( ! V_24 ) {
V_120 -> V_1 . V_213 = F_36 ( V_333 -> V_213 ) ;
F_9 ( & V_19 -> V_40 ) ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_97 ) ;
F_10 ( & V_19 -> V_40 ) ;
V_333 -> V_329 . V_330 [ 0 ] &= 0x3f ;
F_6 ( L_111 ,
V_333 -> V_336 ) ;
V_24 = F_102 ( & V_120 -> V_1 , V_256 -> V_260 , NULL ,
F_100 ( & V_333 -> V_329 ) , V_333 ,
V_334 , V_258 , V_335 , 0 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_112 ,
V_24 ) ;
F_9 ( & V_19 -> V_40 ) ;
F_51 ( & V_120 -> V_128 ) ;
F_10 ( & V_19 -> V_40 ) ;
V_120 -> V_1 . V_348 -> V_349 =
V_351 ;
}
}
if ( V_24 )
F_103 ( & V_120 -> V_1 , 0 , 0 ) ;
}
static void F_104 ( struct V_77 * V_78 )
{
struct V_119 * V_120 = F_23 ( V_78 , struct V_119 ,
V_78 ) ;
struct V_18 * V_19 = V_120 -> V_352 ;
F_9 ( & V_19 -> V_40 ) ;
F_51 ( & V_120 -> V_128 ) ;
if ( V_19 -> V_9 & ( V_82 | V_81 ) ) {
F_42 ( V_19 , V_120 ) ;
if ( F_25 ( & V_19 -> V_97 ) &&
F_25 ( & V_19 -> V_98 ) &&
( V_19 -> V_9 & V_99 ) ) {
V_19 -> V_9 &= ~ V_99 ;
F_24 ( & V_19 -> V_80 ) ;
}
F_10 ( & V_19 -> V_40 ) ;
return;
}
F_10 ( & V_19 -> V_40 ) ;
switch ( V_120 -> type ) {
case V_124 :
F_97 ( V_19 , V_120 ) ;
break;
case V_123 :
F_101 ( V_19 , V_120 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_113 ,
V_120 -> type ) ;
F_9 ( & V_19 -> V_40 ) ;
F_42 ( V_19 , V_120 ) ;
F_10 ( & V_19 -> V_40 ) ;
break;
}
}
static int F_105 ( struct V_18 * V_19 , int V_353 )
{
struct V_119 * V_120 ;
int V_354 ;
F_106 ( & V_19 -> V_129 ) ;
V_19 -> V_355 = F_107 ( V_353 , sizeof( struct V_119 ) ,
V_258 ) ;
if ( ! V_19 -> V_355 )
return - V_259 ;
for ( V_354 = 0 , V_120 = (struct V_119 * ) V_19 -> V_355 ; V_354 < V_353 ;
V_354 ++ , V_120 ++ ) {
V_120 -> V_149 = NULL ;
V_120 -> V_352 = V_19 ;
F_29 ( & V_120 -> V_78 , F_104 ) ;
F_43 ( & V_120 -> V_128 , & V_19 -> V_129 ) ;
}
return 0 ;
}
static void F_108 ( struct V_18 * V_19 )
{
F_84 ( V_19 -> V_355 ) ;
V_19 -> V_355 = NULL ;
F_106 ( & V_19 -> V_129 ) ;
}
static enum V_356 F_109 ( struct V_357 * V_223 )
{
struct V_358 * V_359 = F_23 ( V_223 , struct V_358 , V_223 ) ;
struct V_18 * V_19 = F_23 ( V_359 , struct V_18 ,
V_112 ) ;
F_9 ( & V_19 -> V_40 ) ;
V_359 -> V_113 += 1 ;
V_359 -> V_147 = false ;
F_74 ( V_19 ) ;
F_10 ( & V_19 -> V_40 ) ;
return V_360 ;
}
static long F_110 ( struct V_18 * V_19 )
{
struct V_358 * V_359 ;
V_359 = & V_19 -> V_112 ;
F_111 ( & V_359 -> V_223 , V_361 , V_224 ) ;
V_359 -> V_223 . V_362 = F_109 ;
V_359 -> V_147 = false ;
V_359 -> V_113 = 0 ;
return V_37 ;
}
static void F_112 ( struct V_18 * V_19 )
{
struct V_358 * V_359 ;
V_359 = & V_19 -> V_112 ;
( void ) F_113 ( & V_359 -> V_223 ) ;
V_359 -> V_147 = false ;
V_359 -> V_113 = 0 ;
}
static T_10 F_114 ( int V_363 , void * V_364 )
{
struct V_18 * V_19 = V_364 ;
F_17 ( V_19 -> V_60 ) ;
F_115 ( & V_19 -> V_365 ) ;
return V_366 ;
}
static long F_116 ( struct V_18 * V_19 )
{
int V_56 ;
long V_24 = V_37 ;
V_56 = V_19 -> V_64 . V_65 * V_66 ;
V_24 = F_41 ( V_19 -> V_31 . V_32 , V_19 -> V_64 . V_118 , V_56 ) ;
if ( V_24 == V_35 || V_24 == V_39 ) {
V_19 -> V_69 = V_93 ;
V_24 = F_37 ( V_19 ) ;
}
if ( V_24 != V_37 ) {
V_19 -> V_69 = V_88 ;
V_19 -> V_9 |= V_90 ;
}
return V_24 ;
}
static long F_117 ( struct V_18 * V_19 , int V_367 )
{
int V_368 ;
struct V_307 * V_308 = V_19 -> V_60 ;
V_368 = 1 ;
V_19 -> V_64 . V_65 = V_368 ;
V_19 -> V_64 . V_67 =
(struct V_20 * ) F_118 ( V_258 ) ;
if ( ! V_19 -> V_64 . V_67 )
return - V_259 ;
V_19 -> V_64 . V_70 = ( ( T_4 ) V_368 * V_369 ) - 1 ;
V_19 -> V_64 . V_118 = F_119 ( & V_308 -> V_44 ,
V_19 -> V_64 . V_67 ,
V_66 , V_370 ) ;
if ( F_120 ( & V_308 -> V_44 , V_19 -> V_64 . V_118 ) ) {
F_121 ( ( unsigned long ) V_19 -> V_64 . V_67 ) ;
return - V_259 ;
}
return 0 ;
}
static void F_122 ( struct V_18 * V_19 )
{
F_123 ( & V_19 -> V_60 -> V_44 , V_19 -> V_64 . V_118 ,
V_66 , V_370 ) ;
F_121 ( ( unsigned long ) V_19 -> V_64 . V_67 ) ;
V_19 -> V_64 . V_67 = NULL ;
V_19 -> V_69 = V_83 ;
}
static T_5 F_124 ( struct V_18 * V_19 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_1 * V_1 = & V_120 -> V_1 ;
struct V_291 * V_235 = (struct V_291 * ) V_122 -> V_163 -> V_312 ;
struct V_371 V_372 ;
T_5 V_24 = V_1 -> V_373 ;
if ( V_19 -> V_217 && ( F_125 ( V_235 -> V_331 ) || F_126 ( V_235 -> V_331 ) ) )
if ( F_127 ( V_1 -> V_374 ,
V_1 -> V_375 , & V_372 ) )
if ( V_372 . V_376 == V_377 &&
( V_1 -> V_4 == 0 ||
V_1 -> V_4 == V_1 -> V_378 ) ) {
V_24 = V_379 ;
V_120 -> V_9 |= V_230 ;
}
return V_24 ;
}
static long F_128 ( struct V_18 * V_19 ,
struct V_119 * V_120 , T_4 * V_380 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_1 * V_1 = & V_120 -> V_1 ;
struct V_2 * V_3 ;
T_4 V_154 ;
T_1 V_381 ;
char * V_364 ;
T_1 * V_382 ;
long V_24 = V_37 ;
F_9 ( & V_19 -> V_40 ) ;
V_3 = & F_61 ( V_122 ) -> V_235 . V_3 ;
V_154 = sizeof( * V_3 ) ;
memset ( V_3 , 0 , V_154 ) ;
V_364 = V_3 -> V_364 ;
V_3 -> V_239 = V_383 ;
V_3 -> V_241 = F_2 ( 1 + V_19 -> V_115 ) ;
V_3 -> V_213 = V_120 -> V_3 . V_213 ;
V_3 -> V_9 = 0 ;
if ( V_120 -> type == V_124 ) {
V_3 -> V_29 = F_124 ( V_19 , V_120 ) ;
if ( V_3 -> V_29 ) {
F_6 ( L_114 , V_120 ,
( int ) V_3 -> V_29 ) ;
F_1 ( V_1 , V_3 ) ;
if ( V_1 -> V_375 && V_1 -> V_374 ) {
V_3 -> V_384 =
F_2 ( V_1 -> V_375 ) ;
V_3 -> V_9 |= V_385 ;
V_154 += V_1 -> V_375 ;
memcpy ( V_364 , V_1 -> V_374 ,
V_1 -> V_375 ) ;
}
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_386 ) >>
V_387 ;
} else if ( V_120 -> V_9 & V_230 ) {
F_6 ( L_115 , V_120 ) ;
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_386 ) >>
V_387 ;
} else {
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_388 ) >>
V_389 ;
}
} else {
V_3 -> V_29 = 0 ;
V_3 -> V_390 = F_2 ( 4 ) ;
V_3 -> V_9 |= V_391 ;
switch ( V_1 -> V_348 -> V_349 ) {
case V_392 :
case V_393 :
V_381 = V_394 ;
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_388 ) >>
V_389 ;
break;
case V_350 :
case V_395 :
V_381 = V_396 ;
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_386 ) >>
V_387 ;
break;
case V_397 :
case V_351 :
default:
V_381 = V_398 ;
V_3 -> V_319 = ( V_120 -> V_3 . V_319 & V_386 ) >>
V_387 ;
break;
}
V_382 = ( T_1 * ) V_364 ;
* V_382 = F_2 ( V_381 ) ;
V_364 = ( char * ) ( V_382 + 1 ) ;
V_154 += 4 ;
}
F_65 () ;
V_24 = F_58 ( V_154 , V_19 -> V_31 . V_158 [ V_162 ] . V_160 , V_122 -> V_163 -> V_164 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
F_36 ( V_122 -> V_166 ) ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_115 = 0 ;
* V_380 = V_154 ;
break;
case V_168 :
if ( F_3 ( V_19 ) )
V_19 -> V_9 |= V_90 | V_116 ;
F_11 ( & V_19 -> V_44 , L_116 ,
V_24 , V_19 -> V_9 , V_19 -> V_69 ) ;
break;
case V_170 :
case V_169 :
default:
F_11 ( & V_19 -> V_44 , L_117 ,
V_24 ) ;
break;
}
F_10 ( & V_19 -> V_40 ) ;
return V_24 ;
}
static int F_129 ( struct V_119 * V_120 , struct V_399 * V_400 ,
int V_401 , struct V_402 * V_403 , int V_404 ,
enum V_314 V_315 , unsigned int V_56 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_405 * V_148 = V_122 -> V_148 ;
struct V_18 * V_19 = V_148 -> V_406 ;
struct V_399 * V_407 ;
T_6 V_408 , V_409 ;
T_11 V_410 ;
T_11 V_411 , V_412 ;
int V_413 ;
long V_414 ;
long V_24 = 0 ;
if ( V_56 == 0 )
return 0 ;
V_407 = V_400 ;
V_411 = 0 ;
V_412 = 0 ;
V_413 = 0 ;
V_414 = V_56 ;
do {
if ( V_411 == 0 ) {
if ( V_413 >= V_404 ) {
F_11 ( & V_19 -> V_44 , L_118 ) ;
V_24 = - V_415 ;
break;
}
V_408 = F_36 ( V_403 [ V_413 ] . V_416 ) ;
V_411 = F_64 ( V_403 [ V_413 ] . V_154 ) ;
}
if ( V_412 == 0 ) {
if ( ! V_407 ) {
F_11 ( & V_19 -> V_44 , L_119 ) ;
V_24 = - V_415 ;
break;
}
V_409 = F_130 ( V_407 ) ;
V_412 = F_131 ( V_407 ) ;
}
V_410 = V_414 ;
if ( V_410 > V_411 )
V_410 = V_411 ;
if ( V_410 > V_412 )
V_410 = V_412 ;
if ( V_410 > V_417 )
V_410 = V_417 ;
if ( V_315 == V_8 ) {
V_24 = F_58 ( V_410 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
V_408 ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_409 ) ;
} else {
F_55 () ;
F_65 () ;
V_24 = F_58 ( V_410 ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_409 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ,
V_408 ) ;
}
switch ( V_24 ) {
case V_39 :
break;
case V_168 :
case V_170 :
case V_169 :
if ( F_3 ( V_19 ) ) {
F_9 ( & V_19 -> V_40 ) ;
V_19 -> V_9 |=
( V_90 | V_116 ) ;
F_10 ( & V_19 -> V_40 ) ;
}
F_11 ( & V_19 -> V_44 , L_120 ,
V_24 ) ;
break;
default:
F_11 ( & V_19 -> V_44 , L_121 ,
V_24 ) ;
break;
}
if ( ! V_24 ) {
V_414 -= V_410 ;
if ( V_414 ) {
V_411 -= V_410 ;
if ( V_411 == 0 )
V_413 ++ ;
else
V_408 += V_410 ;
V_412 -= V_410 ;
if ( V_412 == 0 )
V_407 = F_132 ( V_407 ) ;
else
V_409 += V_410 ;
} else {
break;
}
}
} while ( ! V_24 );
return V_24 ;
}
static void F_133 ( unsigned long V_364 )
{
struct V_18 * V_19 = (struct V_18 * ) V_364 ;
struct V_20 * V_21 ;
long V_24 ;
bool V_144 = true ;
volatile T_5 V_25 ;
F_9 ( & V_19 -> V_40 ) ;
F_6 ( L_122 ) ;
if ( F_134 ( V_19 ) ) {
F_39 ( V_19 -> V_60 ) ;
F_6 ( L_123 ,
V_19 -> V_9 , V_19 -> V_69 ) ;
F_10 ( & V_19 -> V_40 ) ;
return;
}
V_24 = V_19 -> V_9 & V_82 ;
V_21 = V_19 -> V_64 . V_67 + V_19 -> V_64 . V_68 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_418:
V_19 -> V_64 . V_68 =
( V_19 -> V_64 . V_68 + 1 ) & V_19 -> V_64 . V_70 ;
if ( ! V_24 ) {
V_24 = F_48 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_135 ) {
V_24 = F_46 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_117 ) {
if ( V_19 -> V_64 . V_68 )
V_19 -> V_64 . V_68 -= 1 ;
else
V_19 -> V_64 . V_68 = V_19 -> V_64 . V_70 ;
break;
}
}
V_21 -> V_25 = V_76 ;
V_21 = V_19 -> V_64 . V_67 + V_19 -> V_64 . V_68 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
}
if ( ! V_24 ) {
if ( V_144 ) {
F_39 ( V_19 -> V_60 ) ;
V_144 = false ;
F_6 ( L_124 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_418;
} else {
F_6 ( L_125 ,
V_19 -> V_9 , V_19 -> V_69 , V_19 -> V_64 . V_68 ) ;
}
F_6 ( L_126 ,
( int ) F_25 ( & V_19 -> V_98 ) , V_19 -> V_9 ,
V_19 -> V_69 ) ;
F_10 ( & V_19 -> V_40 ) ;
}
static int F_135 ( struct V_307 * V_308 ,
const struct V_419 * V_420 )
{
struct V_18 * V_19 ;
int V_24 = 0 ;
long V_421 = 0 ;
char V_422 [ 24 ] ;
V_19 = F_80 ( sizeof( * V_19 ) , V_258 ) ;
if ( ! V_19 ) {
V_24 = - V_259 ;
F_38 ( L_127 ) ;
return V_24 ;
}
V_19 -> V_60 = V_308 ;
V_19 -> V_44 = V_308 -> V_44 ;
F_106 ( & V_19 -> V_98 ) ;
F_106 ( & V_19 -> V_130 ) ;
F_106 ( & V_19 -> V_97 ) ;
snprintf ( V_19 -> V_152 . V_254 , V_423 , L_128 ,
F_69 ( & V_308 -> V_44 ) ) ;
F_6 ( L_129 , V_19 -> V_152 . V_254 ) ;
V_24 = F_93 ( V_19 ) ;
if ( V_24 )
goto V_424;
F_6 ( L_130 ,
V_19 -> V_31 . V_158 [ V_162 ] . V_160 ,
V_19 -> V_31 . V_158 [ V_159 ] . V_160 ) ;
strcpy ( V_19 -> V_425 , L_131 ) ;
strncat ( V_19 -> V_425 , V_308 -> V_201 , V_426 ) ;
V_19 -> V_31 . V_32 = V_308 -> V_232 ;
strncpy ( V_19 -> V_31 . V_184 , V_184 ,
sizeof( V_19 -> V_31 . V_184 ) ) ;
V_19 -> V_31 . V_187 = V_106 ;
F_9 ( & V_311 ) ;
F_43 ( & V_19 -> V_128 , & V_427 ) ;
F_10 ( & V_311 ) ;
V_19 -> V_242 = V_428 ;
V_24 = F_136 ( & V_19 -> V_148 , & V_308 -> V_44 , V_19 -> V_242 ,
V_156 ) ;
if ( V_24 )
goto V_429;
V_19 -> V_148 . V_406 = V_19 ;
V_24 = F_105 ( V_19 , V_19 -> V_242 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_132 ,
V_24 , V_19 -> V_242 ) ;
goto V_430;
}
F_137 ( & V_19 -> V_40 ) ;
V_24 = F_110 ( V_19 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_133 , V_24 ) ;
goto V_431;
}
V_24 = F_117 ( V_19 , 256 ) ;
if ( V_24 ) {
F_11 ( & V_19 -> V_44 , L_134 ,
V_24 ) ;
goto V_432;
}
V_19 -> V_107 = F_80 ( V_66 , V_258 ) ;
if ( ! V_19 -> V_107 ) {
V_24 = - V_259 ;
F_11 ( & V_19 -> V_44 , L_135 ) ;
goto V_433;
}
V_19 -> V_105 = F_119 ( & V_308 -> V_44 , V_19 -> V_107 , V_66 ,
V_370 ) ;
if ( F_120 ( & V_308 -> V_44 , V_19 -> V_105 ) ) {
V_24 = - V_259 ;
F_11 ( & V_19 -> V_44 , L_136 ) ;
goto V_434;
}
V_421 = F_35 ( V_19 -> V_31 . V_32 , V_104 ,
( T_2 ) V_19 -> V_105 | ( ( T_2 ) V_66 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_421 == V_39 )
V_19 -> V_54 . V_106 =
F_36 ( * ( T_2 * ) V_19 -> V_107 ) ;
F_6 ( L_137 ,
V_421 , V_19 -> V_54 . V_106 ) ;
F_138 ( & V_19 -> V_365 , F_133 ,
( unsigned long ) V_19 ) ;
F_139 ( & V_19 -> V_80 ) ;
F_139 ( & V_19 -> V_92 ) ;
snprintf ( V_422 , 24 , L_138 , F_69 ( & V_308 -> V_44 ) ) ;
V_19 -> V_101 = F_140 ( V_422 ) ;
if ( ! V_19 -> V_101 ) {
V_24 = - V_259 ;
F_11 ( & V_19 -> V_44 , L_139 ) ;
goto V_435;
}
V_24 = F_141 ( V_308 -> V_436 , F_114 , 0 , L_140 , V_19 ) ;
if ( V_24 ) {
V_24 = - V_437 ;
F_11 ( & V_19 -> V_44 , L_141 , V_24 ) ;
goto V_438;
}
V_19 -> V_69 = V_89 ;
F_142 ( & V_308 -> V_44 , V_19 ) ;
return 0 ;
V_438:
F_143 ( V_19 -> V_101 ) ;
V_435:
F_123 ( & V_308 -> V_44 , V_19 -> V_105 , V_66 ,
V_370 ) ;
V_434:
F_84 ( V_19 -> V_107 ) ;
V_433:
F_144 ( & V_19 -> V_365 ) ;
F_7 ( V_19 ) ;
F_122 ( V_19 ) ;
V_432:
F_112 ( V_19 ) ;
V_431:
F_108 ( V_19 ) ;
V_430:
F_145 ( & V_19 -> V_148 ) ;
V_429:
F_9 ( & V_311 ) ;
F_51 ( & V_19 -> V_128 ) ;
F_10 ( & V_311 ) ;
V_424:
F_84 ( V_19 ) ;
return V_24 ;
}
static int F_146 ( struct V_307 * V_308 )
{
struct V_18 * V_19 = F_147 ( & V_308 -> V_44 ) ;
F_6 ( L_142 , F_69 ( & V_19 -> V_60 -> V_44 ) ) ;
F_9 ( & V_19 -> V_40 ) ;
F_28 ( V_19 , V_84 , 0 ) ;
V_19 -> V_9 |= V_91 ;
F_10 ( & V_19 -> V_40 ) ;
F_26 ( & V_19 -> V_92 ) ;
F_17 ( V_308 ) ;
F_148 ( V_308 -> V_436 , V_19 ) ;
F_143 ( V_19 -> V_101 ) ;
F_123 ( & V_308 -> V_44 , V_19 -> V_105 , V_66 ,
V_370 ) ;
F_84 ( V_19 -> V_107 ) ;
F_144 ( & V_19 -> V_365 ) ;
F_122 ( V_19 ) ;
F_112 ( V_19 ) ;
F_108 ( V_19 ) ;
F_145 ( & V_19 -> V_148 ) ;
F_9 ( & V_311 ) ;
F_51 ( & V_19 -> V_128 ) ;
F_10 ( & V_311 ) ;
F_84 ( V_19 ) ;
return 0 ;
}
static T_12 F_149 ( struct V_439 * V_44 ,
struct V_440 * V_316 , char * V_312 )
{
return snprintf ( V_312 , V_66 , L_143 , V_441 ) ;
}
static T_12 F_150 ( struct V_439 * V_44 ,
struct V_440 * V_316 , char * V_312 )
{
return snprintf ( V_312 , V_66 , L_144 , V_106 ) ;
}
static T_12 F_151 ( struct V_439 * V_44 ,
struct V_440 * V_316 , char * V_312 )
{
struct V_18 * V_19 = F_23 ( V_44 , struct V_18 , V_44 ) ;
return snprintf ( V_312 , V_66 , L_144 , V_19 -> V_60 -> V_232 ) ;
}
static int F_152 ( void )
{
struct V_442 * V_443 , * V_444 ;
const char * V_420 , * V_445 , * V_201 ;
const T_4 * V_353 ;
V_443 = F_153 ( L_145 ) ;
if ( ! V_443 )
return - V_446 ;
V_445 = F_154 ( V_443 , L_146 , NULL ) ;
V_420 = F_154 ( V_443 , L_147 , NULL ) ;
if ( V_445 && V_420 )
snprintf ( V_441 , sizeof( V_441 ) , L_148 , V_445 , V_420 ) ;
V_201 = F_154 ( V_443 , L_149 , NULL ) ;
if ( V_201 )
strncpy ( V_184 , V_201 , sizeof( V_184 ) ) ;
V_353 = F_154 ( V_443 , L_150 , NULL ) ;
if ( V_353 )
V_106 = F_155 ( V_353 , 1 ) ;
F_156 ( V_443 ) ;
V_444 = F_153 ( L_151 ) ;
if ( V_444 ) {
const T_4 * V_447 ;
V_447 = F_154 ( V_444 , L_152 ,
NULL ) ;
if ( V_447 )
V_417 = * V_447 ;
F_156 ( V_444 ) ;
}
return 0 ;
}
static char * F_157 ( void )
{
return L_140 ;
}
static char * F_158 ( struct V_448 * V_261 )
{
struct V_253 * V_152 =
F_23 ( V_261 , struct V_253 , V_261 ) ;
return V_152 -> V_254 ;
}
static T_3 F_159 ( struct V_448 * V_261 )
{
struct V_253 * V_152 =
F_23 ( V_261 , struct V_253 , V_261 ) ;
return V_152 -> V_449 ;
}
static T_1 F_160 ( struct V_448 * V_261 )
{
return 1 ;
}
static int F_161 ( struct V_448 * V_261 )
{
return 1 ;
}
static int F_162 ( struct V_448 * V_261 )
{
return 0 ;
}
static T_1 F_163 ( struct V_448 * V_261 )
{
return 1 ;
}
static int F_164 ( struct V_1 * V_1 )
{
return F_165 ( V_1 ) ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_119 * V_120 = F_23 ( V_1 , struct V_119 ,
V_1 ) ;
struct V_18 * V_19 = V_120 -> V_352 ;
F_9 ( & V_19 -> V_40 ) ;
F_167 ( & V_120 -> V_128 , & V_19 -> V_130 ) ;
F_74 ( V_19 ) ;
F_10 ( & V_19 -> V_40 ) ;
}
static T_1 F_168 ( struct V_264 * V_260 )
{
return 0 ;
}
static int F_169 ( struct V_1 * V_1 )
{
struct V_119 * V_120 = F_23 ( V_1 , struct V_119 ,
V_1 ) ;
struct V_18 * V_19 = V_120 -> V_352 ;
struct V_121 * V_122 = V_120 -> V_122 ;
int V_24 ;
if ( ( V_19 -> V_9 & ( V_116 | V_90 ) ) ) {
F_38 ( L_153 , V_19 -> V_9 ) ;
return 0 ;
}
V_24 = F_170 ( V_120 , & F_61 ( V_122 ) -> V_235 . V_120 , F_129 ,
1 , 1 ) ;
if ( V_24 ) {
F_38 ( L_154 , V_24 ) ;
return - V_415 ;
}
F_171 ( V_1 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_173 ( struct V_450 * V_451 )
{
}
static int F_174 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_175 ( struct V_1 * V_1 )
{
struct V_119 * V_120 = F_23 ( V_1 , struct V_119 ,
V_1 ) ;
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_18 * V_19 = V_120 -> V_352 ;
char * V_452 ;
T_4 V_154 = 0 ;
int V_24 ;
V_24 = F_170 ( V_120 , & F_61 ( V_122 ) -> V_235 . V_120 , F_129 , 1 ,
1 ) ;
if ( V_24 ) {
F_38 ( L_155 , V_24 ) ;
V_452 = V_1 -> V_374 ;
V_1 -> V_375 = 18 ;
memset ( V_1 -> V_374 , 0 , V_1 -> V_375 ) ;
F_176 ( 0 , V_1 -> V_374 , V_453 ,
0x08 , 0x01 ) ;
}
F_128 ( V_19 , V_120 , & V_154 ) ;
V_120 -> V_3 . V_27 = V_290 ;
V_120 -> V_3 . V_154 = V_154 ;
return 0 ;
}
static int F_177 ( struct V_1 * V_1 )
{
struct V_119 * V_120 = F_23 ( V_1 , struct V_119 ,
V_1 ) ;
struct V_18 * V_19 = V_120 -> V_352 ;
T_4 V_154 ;
F_6 ( L_156 , V_1 ) ;
F_128 ( V_19 , V_120 , & V_154 ) ;
V_120 -> V_3 . V_27 = V_290 ;
V_120 -> V_3 . V_154 = V_154 ;
return 0 ;
}
static void F_178 ( struct V_1 * V_1 )
{
struct V_119 * V_120 = F_23 ( V_1 , struct V_119 ,
V_1 ) ;
struct V_18 * V_19 = V_120 -> V_352 ;
struct V_119 * V_454 ;
struct V_121 * V_122 = V_122 = V_120 -> V_122 ;
struct V_292 * V_333 = & F_61 ( V_122 ) -> V_235 . V_296 ;
T_2 V_335 = F_36 ( V_333 -> V_339 ) ;
T_4 V_154 ;
F_6 ( L_157 ,
V_1 , ( int ) V_1 -> V_348 -> V_349 ) ;
if ( V_333 -> V_336 == V_337 &&
V_120 -> V_1 . V_348 -> V_349 == V_393 ) {
F_9 ( & V_19 -> V_40 ) ;
F_96 (cmd_itr, &vscsi->active_q, list) {
if ( V_335 == V_454 -> V_1 . V_213 ) {
V_454 -> V_149 = V_120 ;
V_120 -> V_9 |= V_150 ;
break;
}
}
F_10 ( & V_19 -> V_40 ) ;
}
F_128 ( V_19 , V_120 , & V_154 ) ;
V_120 -> V_3 . V_27 = V_290 ;
V_120 -> V_3 . V_154 = V_154 ;
}
static void F_179 ( struct V_1 * V_1 )
{
F_6 ( L_158 ,
V_1 , V_1 -> V_213 ) ;
}
static struct V_455 * F_180 ( struct V_456 * V_457 ,
struct V_458 * V_459 ,
const char * V_201 )
{
struct V_253 * V_152 ;
V_152 = F_95 ( V_201 ) ;
if ( V_152 ) {
V_152 -> V_460 = V_461 ;
F_6 ( L_159 ,
V_201 , V_152 , V_152 -> V_460 ) ;
return & V_152 -> V_462 ;
}
return F_181 ( - V_463 ) ;
}
static void F_182 ( struct V_455 * V_464 )
{
struct V_253 * V_152 = F_23 ( V_464 ,
struct V_253 ,
V_462 ) ;
F_6 ( L_160 ,
F_183 ( & V_152 -> V_462 . V_465 . V_466 ) ) ;
}
static struct V_448 * F_184 ( struct V_455 * V_464 ,
struct V_458 * V_459 ,
const char * V_201 )
{
struct V_253 * V_152 =
F_23 ( V_464 , struct V_253 , V_462 ) ;
T_3 V_467 ;
int V_24 ;
if ( strstr ( V_201 , L_161 ) != V_201 )
return F_181 ( - V_463 ) ;
V_24 = F_185 ( V_201 + 5 , 0 , & V_467 ) ;
if ( V_24 )
return F_181 ( V_24 ) ;
V_152 -> V_449 = V_467 ;
V_152 -> V_468 = false ;
V_24 = F_186 ( & V_152 -> V_462 , & V_152 -> V_261 ,
V_152 -> V_460 ) ;
if ( V_24 )
return F_181 ( V_24 ) ;
return & V_152 -> V_261 ;
}
static void F_187 ( struct V_448 * V_261 )
{
struct V_253 * V_152 = F_23 ( V_261 ,
struct V_253 ,
V_261 ) ;
V_152 -> V_468 = true ;
V_152 -> V_153 = false ;
F_85 ( V_152 ) ;
F_188 ( V_261 ) ;
}
static T_12 F_189 ( struct V_469 * V_470 ,
char * V_471 )
{
return F_190 ( V_471 , V_66 , L_143 , V_472 ) ;
}
static T_12 F_191 ( struct V_469 * V_470 ,
char * V_471 )
{
struct V_448 * V_261 = F_192 ( V_470 ) ;
struct V_253 * V_152 = F_23 ( V_261 ,
struct V_253 ,
V_261 ) ;
return snprintf ( V_471 , V_66 , L_162 , ( V_152 -> V_153 ) ? 1 : 0 ) ;
}
static T_12 F_193 ( struct V_469 * V_470 ,
const char * V_471 , T_13 V_473 )
{
struct V_448 * V_261 = F_192 ( V_470 ) ;
struct V_253 * V_152 = F_23 ( V_261 ,
struct V_253 ,
V_261 ) ;
struct V_18 * V_19 = F_23 ( V_152 , struct V_18 , V_152 ) ;
unsigned long V_474 ;
int V_24 ;
long V_475 ;
V_24 = F_194 ( V_471 , 0 , & V_474 ) ;
if ( V_24 < 0 ) {
F_38 ( L_163 ) ;
return - V_463 ;
}
if ( ( V_474 != 0 ) && ( V_474 != 1 ) ) {
F_38 ( L_164 ) ;
return - V_463 ;
}
if ( V_474 ) {
F_9 ( & V_19 -> V_40 ) ;
V_152 -> V_153 = true ;
V_475 = F_116 ( V_19 ) ;
if ( V_475 )
F_38 ( L_165 ,
V_475 , V_19 -> V_69 ) ;
F_10 ( & V_19 -> V_40 ) ;
} else {
F_9 ( & V_19 -> V_40 ) ;
V_152 -> V_153 = false ;
F_28 ( V_19 , V_85 , 0 ) ;
F_10 ( & V_19 -> V_40 ) ;
}
F_6 ( L_166 , V_474 , V_19 -> V_69 ) ;
return V_473 ;
}
static void F_195 ( struct V_439 * V_44 ) {}
static int T_14 F_196 ( void )
{
int V_24 = 0 ;
V_24 = F_152 () ;
if ( V_24 ) {
F_38 ( L_167 , V_24 ) ;
goto V_476;
}
V_24 = F_197 ( & V_477 ) ;
if ( V_24 ) {
F_38 ( L_168 ) ;
goto V_476;
}
V_24 = F_198 ( & V_478 ) ;
if ( V_24 ) {
F_38 ( L_169 , V_24 ) ;
goto V_479;
}
V_24 = F_199 ( & V_480 ) ;
if ( V_24 ) {
F_38 ( L_170 , V_24 ) ;
goto V_481;
}
return 0 ;
V_481:
F_200 ( & V_478 ) ;
V_479:
F_201 ( & V_477 ) ;
V_476:
return V_24 ;
}
static void T_15 F_202 ( void )
{
F_203 ( L_171 ) ;
F_204 ( & V_480 ) ;
F_200 ( & V_478 ) ;
F_201 ( & V_477 ) ;
}
