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
break;
case V_40 :
case V_41 :
F_9 ( & V_19 -> V_42 , L_2 ,
V_36 ) ;
V_24 = ERROR ;
break;
case V_43 :
case V_44 :
F_10 ( 1000 , 2000 ) ;
V_38 += 1 ;
break;
case V_45 :
F_10 ( 10000 , 20000 ) ;
V_38 += 10 ;
break;
case V_46 :
F_11 ( 100 ) ;
V_38 += 100 ;
break;
case V_47 :
F_12 ( 1 ) ;
V_38 += 1000 ;
break;
case V_48 :
F_12 ( 10 ) ;
V_38 += 10000 ;
break;
case V_49 :
F_12 ( 100 ) ;
V_38 += 100000 ;
break;
default:
F_9 ( & V_19 -> V_42 , L_3 ,
V_36 ) ;
V_24 = ERROR ;
break;
}
if ( V_38 > 300000 && V_36 != V_39 ) {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_4 ) ;
}
} while ( V_36 != V_39 && V_24 == V_37 );
F_6 ( L_5 , V_36 , V_24 ) ;
return V_24 ;
}
static void F_13 ( struct V_18 * V_19 ,
bool V_50 )
{
V_19 -> V_51 = 0 ;
if ( V_50 )
V_19 -> V_52 . V_53 = 0 ;
}
static long F_14 ( struct V_18 * V_19 )
{
int V_54 ;
T_1 V_55 ;
T_3 V_56 ;
long V_24 = V_37 ;
if ( ! ( V_19 -> V_9 & V_57 ) ) {
F_15 ( V_19 -> V_58 ) ;
V_56 = V_19 -> V_59 ;
V_55 = V_19 -> V_9 ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = 0 ;
F_16 ( & V_19 -> V_62 ) ;
V_24 = F_7 ( V_19 ) ;
F_17 ( & V_19 -> V_62 ) ;
if ( V_56 != V_19 -> V_59 )
V_19 -> V_60 = V_19 -> V_59 ;
V_19 -> V_61 = ( ( ~ V_55 ) & V_19 -> V_9 ) ;
if ( V_24 == V_37 ) {
V_54 = V_19 -> V_63 . V_64 * V_65 ;
memset ( V_19 -> V_63 . V_66 , 0 , V_54 ) ;
V_19 -> V_63 . V_67 = 0 ;
V_19 -> V_9 |= V_57 ;
F_13 ( V_19 , false ) ;
}
F_6 ( L_6 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_61 ,
V_19 -> V_60 ) ;
}
return V_24 ;
}
static struct V_20 * F_18 ( T_4 V_69 ,
T_4 * V_70 ,
struct V_20 * V_66 )
{
struct V_20 * V_71 ;
V_71 = V_66 + * V_70 ;
if ( V_71 -> V_25 ) {
* V_70 = ( * V_70 + 1 ) & V_69 ;
F_19 () ;
} else {
V_71 = NULL ;
}
return V_71 ;
}
static long F_20 ( struct V_18 * V_19 , T_5 V_27 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_24 ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_72 ;
V_21 -> V_27 = V_27 ;
V_24 = F_4 ( V_19 -> V_31 . V_32 , F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
return V_24 ;
}
static long F_21 ( struct V_18 * V_19 , T_4 * V_27 )
{
struct V_20 * V_21 ;
long V_24 = V_37 ;
V_21 = F_18 ( V_19 -> V_63 . V_69 , & V_19 -> V_63 . V_67 ,
V_19 -> V_63 . V_66 ) ;
if ( ! V_21 ) {
* V_27 = ( T_4 ) V_73 ;
} else if ( V_21 -> V_25 == V_72 && V_21 -> V_27 == V_74 ) {
* V_27 = ( T_4 ) V_74 ;
V_21 -> V_25 = V_75 ;
F_19 () ;
V_21 = F_18 ( V_19 -> V_63 . V_69 ,
& V_19 -> V_63 . V_67 ,
V_19 -> V_63 . V_66 ) ;
if ( V_21 ) {
* V_27 = ( T_4 ) ( V_21 -> V_27 ) ;
V_24 = ERROR ;
V_21 -> V_25 = V_75 ;
F_19 () ;
}
} else {
* V_27 = ( T_4 ) ( V_21 -> V_27 ) ;
V_24 = ERROR ;
V_21 -> V_25 = V_75 ;
F_19 () ;
}
return V_24 ;
}
static long F_22 ( struct V_18 * V_19 , T_4 V_59 )
{
long V_24 = V_37 ;
T_4 V_27 ;
V_19 -> V_9 &= V_76 ;
V_19 -> V_77 . V_78 = 0 ;
V_19 -> V_79 = 0 ;
V_19 -> V_80 = 0 ;
V_24 = F_23 ( V_19 -> V_58 ) ;
if ( V_24 ) {
F_24 ( L_7 ,
V_24 ) ;
return V_24 ;
}
V_24 = F_21 ( V_19 , & V_27 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_8 ,
V_24 ) ;
return V_24 ;
}
if ( V_27 == V_73 && V_59 == V_81 ) {
V_24 = F_20 ( V_19 , V_74 ) ;
switch ( V_24 ) {
case V_39 :
case V_82 :
case V_35 :
V_24 = V_37 ;
break;
case V_41 :
case V_40 :
break;
default:
V_19 -> V_68 = V_83 ;
V_24 = V_40 ;
break;
}
}
return V_24 ;
}
static void F_25 ( struct V_18 * V_19 , T_4 V_59 )
{
int V_54 ;
long V_24 = V_37 ;
F_6 ( L_9 , V_19 -> V_9 ) ;
if ( V_19 -> V_9 & ( V_84 | V_85 ) ) {
V_19 -> V_9 &= V_76 ;
V_19 -> V_77 . V_78 = 0 ;
V_19 -> V_79 = 0 ;
V_19 -> V_80 = 0 ;
V_19 -> V_68 = V_59 ;
F_23 ( V_19 -> V_58 ) ;
} else {
V_24 = F_14 ( V_19 ) ;
if ( V_24 == V_37 ) {
V_19 -> V_68 = V_59 ;
V_54 = V_19 -> V_63 . V_64 * V_65 ;
V_24 = F_26 ( V_19 -> V_31 . V_32 ,
V_19 -> V_63 . V_86 , V_54 ) ;
if ( V_24 == V_35 || V_24 == V_39 ) {
V_24 = F_22 ( V_19 ,
V_59 ) ;
}
if ( V_24 != V_37 ) {
F_6 ( L_10 , V_24 ) ;
V_19 -> V_68 = V_87 ;
V_19 -> V_9 |= V_88 ;
F_14 ( V_19 ) ;
}
} else {
V_19 -> V_68 = V_87 ;
V_19 -> V_9 |= V_88 ;
}
}
}
static void F_27 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
switch ( V_90 -> type ) {
case V_93 :
case V_94 :
if ( V_19 -> V_79 )
V_19 -> V_79 -= 1 ;
break;
case V_95 :
V_19 -> V_9 &= ~ V_96 ;
break;
case V_97 :
break;
default:
F_9 ( & V_19 -> V_42 , L_11 ,
V_90 -> type ) ;
break;
}
V_90 -> V_92 = NULL ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_99 ) ;
F_29 ( V_92 ) ;
if ( F_30 ( & V_19 -> V_100 ) && F_30 ( & V_19 -> V_101 ) &&
F_30 ( & V_19 -> V_102 ) && ( V_19 -> V_9 & V_103 ) ) {
V_19 -> V_9 &= ~ V_103 ;
F_31 ( & V_19 -> V_104 ) ;
}
}
static void F_32 ( struct V_105 * V_106 )
{
struct V_18 * V_19 = F_33 ( V_106 , struct V_18 ,
V_107 ) ;
T_3 V_59 ;
bool V_104 = false ;
long V_24 = V_37 ;
F_17 ( & V_19 -> V_62 ) ;
V_59 = V_19 -> V_59 ;
V_19 -> V_59 = 0 ;
F_6 ( L_12 , V_19 -> V_9 ,
V_19 -> V_68 ) ;
switch ( V_19 -> V_68 ) {
case V_108 :
case V_109 :
break;
case V_110 :
if ( V_59 == V_109 )
V_19 -> V_68 = V_59 ;
break;
case V_111 :
switch ( V_59 ) {
case V_109 :
case V_110 :
V_19 -> V_68 = V_59 ;
break;
case V_112 :
break;
default:
break;
}
break;
case V_87 :
if ( V_59 == V_109 )
V_19 -> V_68 = V_59 ;
break;
case V_113 :
case V_114 :
switch ( V_59 ) {
case V_110 :
V_19 -> V_9 |= V_88 ;
V_19 -> V_68 = V_59 ;
V_19 -> V_9 &= ~ ( V_115 |
V_116 ) ;
F_14 ( V_19 ) ;
break;
case V_111 :
F_25 ( V_19 , V_113 ) ;
break;
case V_112 :
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_13 ,
V_19 -> V_68 ) ;
break;
}
break;
case V_112 :
switch ( V_59 ) {
case V_110 :
case V_111 :
V_19 -> V_68 = V_59 ;
break;
}
break;
case V_81 :
case V_117 :
case V_118 :
V_104 = true ;
V_19 -> V_68 = V_59 ;
break;
case V_83 :
if ( V_59 == V_109 )
V_19 -> V_68 = V_59 ;
break;
default:
break;
}
if ( V_104 ) {
F_6 ( L_14 ,
( int ) F_30 ( & V_19 -> V_100 ) ,
( int ) F_30 ( & V_19 -> V_101 ) ) ;
if ( ! F_30 ( & V_19 -> V_100 ) ||
! F_30 ( & V_19 -> V_101 ) ) {
V_19 -> V_9 |= V_103 ;
F_6 ( L_15 , V_19 -> V_9 ) ;
F_16 ( & V_19 -> V_62 ) ;
F_34 ( & V_19 -> V_104 ) ;
F_17 ( & V_19 -> V_62 ) ;
}
F_6 ( L_16 ) ;
F_35 ( V_19 ) ;
}
F_16 ( & V_19 -> V_62 ) ;
}
static void F_36 ( struct V_18 * V_19 , T_4 V_59 ,
T_4 V_119 )
{
T_4 V_68 ;
switch ( V_59 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
break;
default:
F_9 ( & V_19 -> V_42 , L_17 ,
V_59 ) ;
return;
}
V_19 -> V_9 |= V_119 ;
F_6 ( L_18 ,
V_59 , V_119 , V_19 -> V_9 , V_19 -> V_68 ) ;
if ( ! ( V_19 -> V_9 & ( V_116 | V_115 ) ) ) {
V_19 -> V_9 |= V_115 ;
V_19 -> V_59 = V_59 ;
F_37 ( & V_19 -> V_107 , F_32 ) ;
( void ) F_38 ( V_19 -> V_120 , & V_19 -> V_107 ) ;
} else {
if ( V_19 -> V_59 )
V_68 = V_19 -> V_59 ;
else
V_68 = V_19 -> V_68 ;
switch ( V_68 ) {
case V_108 :
case V_109 :
break;
case V_87 :
case V_110 :
case V_83 :
if ( V_59 == V_109 )
V_19 -> V_59 = V_59 ;
break;
case V_111 :
switch ( V_59 ) {
case V_109 :
case V_110 :
V_19 -> V_59 = V_59 ;
break;
default:
break;
}
break;
case V_113 :
case V_114 :
case V_112 :
case V_81 :
case V_117 :
case V_118 :
V_19 -> V_59 = V_59 ;
break;
default:
break;
}
}
F_6 ( L_19 ,
V_19 -> V_9 , V_19 -> V_59 ) ;
}
static long F_39 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_20 ,
( int ) V_21 -> V_27 , V_19 -> V_9 , V_19 -> V_68 ) ;
switch ( V_21 -> V_27 ) {
case V_121 :
case V_122 :
case V_123 :
F_13 ( V_19 , true ) ;
break;
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_21 ,
( T_4 ) V_21 -> V_27 ) ;
F_36 ( V_19 , V_110 ,
V_88 ) ;
break;
}
if ( V_24 == V_37 ) {
switch ( V_19 -> V_68 ) {
case V_108 :
case V_87 :
case V_83 :
break;
case V_109 :
V_19 -> V_9 |= ( V_88 | V_85 ) ;
break;
case V_113 :
break;
case V_81 :
break;
case V_117 :
F_36 ( V_19 , V_112 ,
( V_88 |
V_85 ) ) ;
break;
case V_114 :
V_19 -> V_68 = V_113 ;
break;
case V_118 :
if ( ( V_19 -> V_79 > 0 ) ||
! F_30 ( & V_19 -> V_101 ) ||
! F_30 ( & V_19 -> V_102 ) ||
! F_30 ( & V_19 -> V_100 ) ) {
F_6 ( L_22 ,
V_19 -> V_79 ,
( int ) F_30 ( & V_19 -> V_101 ) ,
( int ) F_30 ( & V_19 -> V_102 ) ,
( int ) F_30 ( & V_19 -> V_100 ) ) ;
F_24 ( L_23 ) ;
} else {
F_6 ( L_24 ) ;
}
F_36 ( V_19 , V_112 ,
( V_88 |
V_85 ) ) ;
break;
case V_110 :
case V_111 :
case V_112 :
V_19 -> V_9 |= ( V_88 | V_85 ) ;
break;
}
}
V_24 = V_19 -> V_9 & V_115 ;
F_6 ( L_25 ,
V_19 -> V_9 , V_19 -> V_68 , V_24 ) ;
return V_24 ;
}
static void F_40 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
long V_24 ;
bool V_124 = true ;
volatile T_5 V_25 ;
F_6 ( L_26 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_63 . V_67 ) ;
V_24 = V_19 -> V_9 & V_115 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_125:
V_19 -> V_63 . V_67 =
( V_19 -> V_63 . V_67 + 1 ) & V_19 -> V_63 . V_69 ;
if ( ! V_24 ) {
V_24 = F_41 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_126 ) {
V_24 = F_39 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_85 ) {
F_6 ( L_27 ) ;
if ( V_19 -> V_63 . V_67 )
V_19 -> V_63 . V_67 -= 1 ;
else
V_19 -> V_63 . V_67 = V_19 -> V_63 . V_69 ;
break;
}
}
V_21 -> V_25 = V_75 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
}
if ( ! V_24 ) {
if ( V_124 ) {
F_23 ( V_19 -> V_58 ) ;
V_124 = false ;
F_6 ( L_28 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_125;
}
F_6 ( L_29 , V_24 ) ;
}
static void F_42 ( struct V_18 * V_19 )
{
struct V_89 * V_90 , * V_127 ;
F_6 ( L_30 ,
( int ) F_30 ( & V_19 -> V_102 ) ,
V_19 -> V_77 . V_128 ) ;
F_43 (cmd, nxt, &vscsi->waiting_rsp, list) {
F_44 ( & V_90 -> V_98 ) ;
F_27 ( V_19 , V_90 ) ;
}
}
static struct V_89 * F_45 ( struct V_18 * V_19 )
{
struct V_89 * V_90 = NULL ;
struct V_91 * V_92 ;
V_92 = F_46 ( & V_19 -> V_129 ) ;
if ( V_92 ) {
V_90 = F_47 ( & V_19 -> V_99 ,
struct V_89 , V_98 ) ;
if ( V_90 ) {
F_44 ( & V_90 -> V_98 ) ;
V_90 -> V_92 = V_92 ;
V_90 -> type = V_97 ;
memset ( & V_90 -> V_1 , 0 , sizeof( V_90 -> V_1 ) ) ;
} else {
F_29 ( V_92 ) ;
}
}
return V_90 ;
}
static void F_35 ( struct V_18 * V_19 )
{
int V_130 = false ;
F_6 ( L_31 , V_19 -> V_9 ,
V_19 -> V_68 ) ;
if ( V_19 -> V_68 != V_81 || V_19 -> V_9 & V_85 )
V_130 = true ;
switch ( V_19 -> V_68 ) {
case V_111 :
F_25 ( V_19 , V_81 ) ;
F_6 ( L_32 , V_19 -> V_9 ) ;
break;
case V_110 :
F_14 ( V_19 ) ;
V_19 -> V_9 &= ~ V_116 ;
V_19 -> V_9 |= V_88 ;
V_19 -> V_68 = V_87 ;
F_6 ( L_33 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
break;
case V_112 :
V_19 -> V_77 . V_78 = 0 ;
V_19 -> V_79 = 0 ;
V_19 -> V_80 = 0 ;
if ( V_19 -> V_9 & V_85 ) {
V_19 -> V_68 = V_81 ;
V_19 -> V_9 &= V_76 ;
} else {
V_19 -> V_68 = V_117 ;
V_19 -> V_9 &= ~ V_116 ;
}
F_6 ( L_34 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
F_40 ( V_19 ) ;
break;
case V_87 :
V_19 -> V_9 &= ~ V_116 ;
F_6 ( L_35 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_36 ,
V_19 -> V_68 ) ;
break;
}
if ( V_130 )
F_42 ( V_19 ) ;
if ( V_19 -> V_60 != 0 ) {
V_19 -> V_9 |= V_19 -> V_61 ;
F_36 ( V_19 , V_19 -> V_60 , 0 ) ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = 0 ;
F_6 ( L_37 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_61 ,
V_19 -> V_60 ) ;
}
F_6 ( L_38 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_59 ) ;
}
static long F_48 ( struct V_18 * V_19 ,
struct V_89 * V_90 ,
struct V_20 * V_21 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
long V_24 = 0 ;
T_3 V_131 ;
V_131 = F_49 ( V_21 -> V_132 ) ;
if ( ( V_131 > V_133 ) || ( V_131 == 0 ) ) {
F_9 ( & V_19 -> V_42 , L_39 , V_131 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
return V_134 ;
}
V_24 = F_50 ( V_131 , V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_21 -> V_138 ) ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_92 -> V_140 -> V_141 ) ;
switch ( V_24 ) {
case V_39 :
V_90 -> V_142 = F_52 () ;
V_92 -> V_143 = V_21 -> V_138 ;
V_92 -> V_144 = V_131 ;
F_6 ( L_40 ,
F_51 ( V_21 -> V_138 ) , V_90 -> V_142 ) ;
break;
case V_145 :
if ( F_3 ( V_19 ) )
F_36 ( V_19 ,
V_111 ,
( V_88 |
V_84 ) ) ;
else
F_36 ( V_19 ,
V_111 , 0 ) ;
F_9 ( & V_19 -> V_42 , L_41 ,
V_24 ) ;
break;
case V_146 :
case V_147 :
default:
F_9 ( & V_19 -> V_42 , L_41 ,
V_24 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
return V_24 ;
}
static long F_53 ( struct V_18 * V_19 ,
struct V_91 * V_92 )
{
struct V_148 * V_149 = & F_54 ( V_92 ) -> V_149 . V_150 ;
struct V_151 * V_152 ;
T_4 V_119 = 0 ;
T_6 V_153 ;
long V_24 ;
V_149 -> V_154 . V_29 = F_55 ( V_155 ) ;
if ( F_49 ( V_149 -> V_154 . V_156 ) > sizeof( * V_152 ) ) {
V_149 -> V_154 . V_29 = F_55 ( V_157 ) ;
return 0 ;
}
V_152 = F_56 ( & V_19 -> V_58 -> V_42 , sizeof( * V_152 ) , & V_153 ,
V_158 ) ;
if ( ! V_152 ) {
F_9 ( & V_19 -> V_42 , L_42 ,
V_92 -> V_129 ) ;
V_149 -> V_154 . V_29 = F_55 ( V_157 ) ;
return 0 ;
}
V_24 = F_50 ( F_49 ( V_149 -> V_154 . V_156 ) ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_149 -> V_22 ) ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_153 ) ;
if ( V_24 != V_39 ) {
if ( V_24 == V_145 ) {
if ( F_3 ( V_19 ) )
V_119 = ( V_88 | V_84 ) ;
}
F_24 ( L_43 ,
V_24 ) ;
F_6 ( L_44 ,
F_51 ( V_149 -> V_22 ) , V_19 -> V_9 , V_119 ) ;
F_36 ( V_19 , V_111 ,
V_119 ) ;
goto V_159;
}
if ( V_19 -> V_52 . V_160 == 0 )
V_19 -> V_52 . V_160 =
F_57 ( V_152 -> V_160 ) ;
strncpy ( V_19 -> V_52 . V_161 , V_152 -> V_161 ,
sizeof( V_19 -> V_52 . V_161 ) ) ;
strncpy ( V_19 -> V_52 . V_162 , V_152 -> V_162 ,
sizeof( V_19 -> V_52 . V_162 ) ) ;
V_19 -> V_52 . V_163 = F_57 ( V_152 -> V_163 ) ;
V_19 -> V_52 . V_53 = F_57 ( V_152 -> V_53 ) ;
strncpy ( V_152 -> V_161 , V_164 ,
sizeof( V_152 -> V_161 ) ) ;
strncpy ( V_152 -> V_162 , V_19 -> V_31 . V_162 ,
sizeof( V_152 -> V_162 ) ) ;
V_152 -> V_160 = F_2 ( V_19 -> V_31 . V_165 ) ;
V_152 -> V_163 = F_2 ( V_166 ) ;
V_152 -> V_53 = F_2 ( V_167 ) ;
memset ( & V_152 -> V_168 [ 0 ] , 0 , sizeof( V_152 -> V_168 ) ) ;
V_152 -> V_168 [ 0 ] = F_2 ( 128 * V_65 ) ;
F_58 () ;
V_24 = F_50 ( sizeof( * V_152 ) , V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_153 , V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_149 -> V_22 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_147 :
case V_146 :
case V_145 :
if ( F_3 ( V_19 ) )
V_119 = ( V_88 | V_84 ) ;
default:
F_9 ( & V_19 -> V_42 , L_45 ,
V_24 ) ;
F_36 ( V_19 ,
V_111 ,
V_119 ) ;
break;
}
V_159:
F_59 ( & V_19 -> V_58 -> V_42 , sizeof( * V_152 ) , V_152 , V_153 ) ;
F_6 ( L_46 , V_24 ) ;
return V_24 ;
}
static int F_60 ( struct V_18 * V_19 , struct V_91 * V_92 )
{
struct V_169 * V_149 = & F_54 ( V_92 ) -> V_149 . V_170 ;
struct V_170 * V_171 ;
struct V_172 * V_154 ;
T_6 V_153 ;
T_3 V_173 , V_131 , V_29 , V_174 , V_175 ;
T_1 V_176 ;
T_4 V_119 = 0 ;
long V_24 = 0 ;
V_173 = F_49 ( V_149 -> V_154 . V_156 ) ;
V_174 = F_61 ( struct V_170 , V_177 ) ;
if ( ( V_173 < V_174 ) || ( V_173 > V_65 ) ) {
F_24 ( L_47 , V_173 ) ;
V_149 -> V_154 . V_29 = F_55 ( V_157 ) ;
return 0 ;
}
V_171 = F_56 ( & V_19 -> V_58 -> V_42 , V_173 , & V_153 ,
V_158 ) ;
if ( ! V_171 ) {
F_9 ( & V_19 -> V_42 , L_42 ,
V_92 -> V_129 ) ;
V_149 -> V_154 . V_29 = F_55 ( V_157 ) ;
return 0 ;
}
V_24 = F_50 ( V_173 , V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_149 -> V_22 ) ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_153 ) ;
if ( V_24 == V_39 ) {
strncpy ( V_171 -> V_178 , F_62 ( & V_19 -> V_58 -> V_42 ) ,
V_179 ) ;
V_131 = V_173 - V_174 ;
V_29 = V_155 ;
V_154 = (struct V_172 * ) & V_171 -> V_177 ;
while ( ( V_131 > 0 ) && ( V_29 == V_155 ) && ! V_24 ) {
F_6 ( L_48 ,
V_131 , F_57 ( V_154 -> V_180 ) ,
F_49 ( V_154 -> V_156 ) ) ;
V_175 = F_49 ( V_154 -> V_156 ) ;
if ( V_175 > V_131 ) {
F_9 ( & V_19 -> V_42 , L_49 ) ;
V_29 = V_157 ;
break;
}
if ( V_175 == 0 ) {
F_9 ( & V_19 -> V_42 , L_50 ) ;
V_29 = V_157 ;
break;
}
switch ( V_154 -> V_180 ) {
default:
F_6 ( L_51 ) ;
V_154 -> V_181 = 0 ;
V_176 = F_2 ( ( T_1 ) V_182 ) ;
V_171 -> V_9 &= ~ V_176 ;
break;
}
V_131 = V_131 - V_175 ;
V_154 = (struct V_172 * )
( ( char * ) V_154 + V_175 ) ;
}
V_149 -> V_154 . V_29 = F_55 ( V_29 ) ;
F_58 () ;
V_24 = F_50 ( V_173 , V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_153 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_149 -> V_22 ) ) ;
if ( V_24 != V_39 ) {
F_6 ( L_52 ,
V_24 ) ;
if ( V_24 == V_145 ) {
if ( F_3 ( V_19 ) )
V_119 = ( V_88 |
V_84 ) ;
}
F_24 ( L_53 ,
V_24 ) ;
F_36 ( V_19 ,
V_111 ,
V_119 ) ;
}
}
F_59 ( & V_19 -> V_58 -> V_42 , V_173 , V_171 , V_153 ) ;
F_6 ( L_54 ,
V_24 , V_19 -> V_51 ) ;
return V_24 ;
}
static long F_63 ( struct V_18 * V_19 , struct V_91 * V_92 )
{
struct V_183 * V_149 = (struct V_183 * ) & F_54 ( V_92 ) -> V_149 ;
struct V_184 * V_185 ;
long V_24 = V_37 ;
switch ( F_57 ( V_149 -> type ) ) {
case V_186 :
V_185 = & F_54 ( V_92 ) -> V_149 . V_187 ;
V_19 -> V_188 = F_51 ( V_185 -> V_22 ) ;
V_19 -> V_189 = F_51 ( V_185 -> V_154 . V_190 ) ;
V_149 -> V_29 = F_55 ( V_155 ) ;
break;
case V_191 :
V_24 = F_53 ( V_19 , V_92 ) ;
break;
case V_192 :
V_24 = F_60 ( V_19 , V_92 ) ;
break;
case V_193 :
if ( V_19 -> V_68 == V_117 ) {
V_19 -> V_194 = true ;
V_149 -> V_29 = F_55 ( V_155 ) ;
} else {
F_24 ( L_55 ) ;
V_149 -> V_29 = F_55 ( V_157 ) ;
}
break;
default:
V_149 -> V_29 = F_55 ( V_195 ) ;
break;
}
return V_24 ;
}
static void F_64 ( struct V_18 * V_19 , long V_24 )
{
T_7 V_196 ;
if ( V_24 != V_82 ) {
F_42 ( V_19 ) ;
if ( V_24 == V_35 )
V_19 -> V_9 |= V_84 ;
if ( ! ( V_19 -> V_9 & V_88 ) ) {
V_19 -> V_9 |= V_88 ;
if ( ! ( V_19 -> V_68 & ( V_110 |
V_111 |
V_87 | V_83 ) ) ) {
F_9 ( & V_19 -> V_42 , L_56 ,
V_19 -> V_68 , V_19 -> V_9 , V_24 ) ;
}
F_36 ( V_19 ,
V_111 , 0 ) ;
}
return;
}
if ( ( V_19 -> V_77 . V_78 < V_197 ) ||
( V_19 -> V_68 == V_118 ) ) {
F_6 ( L_57 ,
V_19 -> V_9 , ( int ) V_19 -> V_77 . V_128 ,
V_19 -> V_77 . V_78 ) ;
if ( ! V_19 -> V_77 . V_128 ) {
if ( V_19 -> V_77 . V_78 <
V_197 ) {
V_196 = F_65 ( 0 , V_198 ) ;
} else {
V_196 = F_65 ( V_199 , 0 ) ;
}
V_19 -> V_77 . V_128 = true ;
F_66 ( & V_19 -> V_77 . V_200 , V_196 ,
V_201 ) ;
}
} else {
V_19 -> V_9 |= V_88 ;
F_42 ( V_19 ) ;
if ( ! ( V_19 -> V_68 & ( V_110 |
V_111 |
V_87 | V_83 ) ) ) {
F_9 ( & V_19 -> V_42 , L_58 ) ;
F_36 ( V_19 ,
V_111 ,
0 ) ;
}
}
}
static void F_67 ( struct V_18 * V_19 )
{
T_2 V_202 = 0 ;
struct V_20 * V_21 = (struct V_20 * ) & V_202 ;
struct V_89 * V_90 , * V_127 ;
struct V_91 * V_92 ;
long V_24 = V_37 ;
if ( ! ( V_19 -> V_9 & V_88 ) ) {
F_43 (cmd, nxt, &vscsi->waiting_rsp, list) {
F_6 ( L_59 , V_90 ) ;
V_92 = V_90 -> V_92 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_90 -> V_3 . V_27 ;
if ( V_90 -> V_9 & V_203 )
V_21 -> V_29 = V_204 ;
V_21 -> V_132 = F_55 ( V_90 -> V_3 . V_131 ) ;
V_24 = F_4 ( V_19 -> V_58 -> V_205 ,
F_51 ( V_202 ) ,
F_51 ( V_90 -> V_3 . V_190 ) ) ;
F_6 ( L_60 ,
F_51 ( V_90 -> V_3 . V_190 ) , V_24 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_77 . V_78 = 0 ;
F_44 ( & V_90 -> V_98 ) ;
F_27 ( V_19 , V_90 ) ;
} else {
F_64 ( V_19 , V_24 ) ;
break;
}
}
if ( ! V_24 ) {
V_19 -> V_77 . V_78 = 0 ;
}
} else {
F_42 ( V_19 ) ;
}
}
static void F_68 ( struct V_18 * V_19 ,
struct V_89 * V_90 ,
struct V_20 * V_21 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_183 * V_149 = (struct V_183 * ) & F_54 ( V_92 ) -> V_149 ;
T_4 V_119 = 0 ;
long V_24 ;
F_58 () ;
V_24 = F_50 ( sizeof( struct V_183 ) ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_92 -> V_140 -> V_141 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_21 -> V_138 ) ) ;
if ( ! V_24 ) {
V_90 -> V_3 . V_27 = V_206 ;
V_90 -> V_3 . V_131 = sizeof( struct V_183 ) ;
V_90 -> V_3 . V_190 = V_149 -> V_190 ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_102 ) ;
F_67 ( V_19 ) ;
} else {
F_6 ( L_61 , V_24 ) ;
if ( V_24 == V_145 ) {
if ( F_3 ( V_19 ) )
V_119 = ( V_88 | V_84 ) ;
}
F_9 ( & V_19 -> V_42 , L_62 ,
V_24 ) ;
F_27 ( V_19 , V_90 ) ;
F_36 ( V_19 , V_111 ,
V_119 ) ;
}
}
static long F_69 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_91 * V_92 ;
struct V_89 * V_90 ;
struct V_183 * V_149 ;
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_81 :
F_6 ( L_63 ,
V_19 -> V_9 ) ;
return V_37 ;
case V_118 :
case V_117 :
break;
case V_109 :
case V_112 :
case V_110 :
case V_111 :
default:
F_9 ( & V_19 -> V_42 , L_64 ,
V_19 -> V_68 ) ;
return V_37 ;
}
V_90 = F_45 ( V_19 ) ;
if ( ! V_90 ) {
F_9 ( & V_19 -> V_42 , L_65 ,
V_19 -> V_79 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
return ERROR ;
}
V_92 = V_90 -> V_92 ;
V_90 -> type = V_95 ;
V_24 = F_48 ( V_19 , V_90 , V_21 ) ;
if ( ! V_24 ) {
V_149 = (struct V_183 * ) & F_54 ( V_92 ) -> V_149 ;
F_6 ( L_66 , F_57 ( V_149 -> type ) ) ;
if ( F_49 ( V_149 -> V_156 ) < 0 ) {
F_9 ( & V_19 -> V_42 , L_67 ) ;
F_36 ( V_19 ,
V_111 , 0 ) ;
V_24 = V_134 ;
} else {
V_24 = F_63 ( V_19 , V_92 ) ;
}
F_6 ( L_68 , F_49 ( V_149 -> V_29 ) ,
V_24 ) ;
if ( ! V_24 )
F_68 ( V_19 , V_90 , V_21 ) ;
} else {
F_27 ( V_19 , V_90 ) ;
}
F_6 ( L_69 , V_24 ) ;
return V_24 ;
}
static long F_70 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_207 * V_3 = & F_54 ( V_92 ) -> V_208 . V_209 ;
struct V_210 * V_211 ;
T_4 V_119 = 0 ;
long V_24 = V_37 ;
memset ( V_3 , 0 , sizeof( struct V_207 ) ) ;
V_3 -> V_212 = V_213 ;
V_3 -> V_214 = F_2 ( V_19 -> V_215 ) ;
V_3 -> V_190 = V_90 -> V_3 . V_190 ;
V_3 -> V_216 = F_2 ( V_133 ) ;
V_3 -> V_217 = F_2 ( V_133 ) ;
V_211 = (struct V_210 * ) & V_3 -> V_218 ;
V_211 -> V_219 = V_220 ;
V_19 -> V_80 = 0 ;
V_90 -> V_3 . V_131 = sizeof( struct V_207 ) ;
F_58 () ;
V_24 = F_50 ( V_90 -> V_3 . V_131 , V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_92 -> V_140 -> V_141 , V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_92 -> V_143 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_145 :
if ( F_3 ( V_19 ) )
V_119 = V_88 | V_84 ;
F_9 ( & V_19 -> V_42 , L_70 ,
V_24 ) ;
F_36 ( V_19 , V_111 ,
V_119 ) ;
break;
case V_147 :
case V_146 :
default:
F_9 ( & V_19 -> V_42 , L_70 ,
V_24 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
return V_24 ;
}
static long F_71 ( struct V_18 * V_19 ,
struct V_89 * V_90 , T_1 V_221 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_222 * V_223 = & F_54 ( V_92 ) -> V_208 . V_224 ;
struct V_210 * V_211 ;
T_4 V_119 = 0 ;
long V_24 = V_37 ;
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
V_223 -> V_212 = V_225 ;
V_223 -> V_221 = F_2 ( V_221 ) ;
V_223 -> V_190 = V_90 -> V_3 . V_190 ;
V_211 = (struct V_210 * ) & V_223 -> V_218 ;
V_211 -> V_219 = V_220 ;
V_90 -> V_3 . V_131 = sizeof( * V_223 ) ;
F_58 () ;
V_24 = F_50 ( V_90 -> V_3 . V_131 , V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_92 -> V_140 -> V_141 , V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_92 -> V_143 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_145 :
if ( F_3 ( V_19 ) )
V_119 = V_88 | V_84 ;
F_9 ( & V_19 -> V_42 , L_71 ,
V_24 ) ;
F_36 ( V_19 , V_111 ,
V_119 ) ;
break;
case V_147 :
case V_146 :
default:
F_9 ( & V_19 -> V_42 , L_71 ,
V_24 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
return V_24 ;
}
static int F_72 ( struct V_226 * V_227 )
{
char * V_178 = V_227 -> V_228 ;
struct V_229 * V_230 ;
int V_24 ;
if ( V_227 -> V_231 ) {
F_6 ( L_72 ) ;
return 0 ;
}
V_230 = F_73 ( sizeof( * V_230 ) , V_158 ) ;
if ( ! V_230 ) {
F_74 ( L_73 ) ;
return - V_232 ;
}
V_230 -> V_233 = F_75 ( & V_227 -> V_234 , 0 , 0 ,
V_235 , V_178 , V_230 ,
NULL ) ;
if ( F_76 ( V_230 -> V_233 ) ) {
V_24 = F_77 ( V_230 -> V_233 ) ;
goto V_236;
}
V_227 -> V_231 = V_230 ;
return 0 ;
V_236:
F_78 ( V_230 ) ;
return V_24 ;
}
static int F_79 ( struct V_226 * V_227 )
{
struct V_237 * V_233 ;
struct V_229 * V_230 ;
V_230 = V_227 -> V_231 ;
if ( ! V_230 )
return - V_238 ;
V_233 = V_230 -> V_233 ;
if ( ! V_233 )
return - V_238 ;
F_80 ( V_233 ) ;
V_227 -> V_231 = NULL ;
F_78 ( V_230 ) ;
return 0 ;
}
static long F_81 ( struct V_18 * V_19 ,
struct V_89 * V_90 ,
struct V_20 * V_21 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_239 * V_240 = & F_54 ( V_92 ) -> V_208 . V_241 ;
struct V_242 {
T_8 V_243 ;
T_8 V_244 ;
} * V_245 , * V_227 ;
struct V_210 * V_211 ;
T_1 V_221 = 0x0 ;
long V_24 = V_37 ;
V_245 = (struct V_242 * ) V_240 -> V_246 ;
V_227 = (struct V_242 * ) V_240 -> V_247 ;
V_211 = (struct V_210 * ) & V_240 -> V_248 ;
if ( F_57 ( V_240 -> V_249 ) > V_133 )
V_221 = V_250 ;
else if ( F_57 ( V_240 -> V_249 ) < 64 )
V_221 = V_251 ;
else if ( ( F_51 ( V_245 -> V_243 ) > ( V_252 - 1 ) ) ||
( F_51 ( V_227 -> V_243 ) > ( V_252 - 1 ) ) )
V_221 = V_253 ;
else if ( V_240 -> V_254 & V_255 )
V_221 = V_256 ;
else if ( V_211 -> V_219 & ( ~ V_220 ) )
V_221 = V_257 ;
else if ( ( V_211 -> V_219 | V_220 ) == 0 )
V_221 = V_257 ;
if ( V_19 -> V_68 == V_118 )
V_221 = V_258 ;
V_24 = F_72 ( & V_19 -> V_227 ) ;
if ( V_24 )
V_221 = V_251 ;
V_90 -> V_3 . V_27 = V_259 ;
V_90 -> V_3 . V_190 = V_240 -> V_190 ;
F_6 ( L_74 , V_221 ) ;
if ( V_221 )
V_24 = F_71 ( V_19 , V_90 , V_221 ) ;
else
V_24 = F_70 ( V_19 , V_90 ) ;
if ( ! V_24 ) {
if ( ! V_221 )
V_19 -> V_68 = V_118 ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_102 ) ;
F_67 ( V_19 ) ;
} else {
F_27 ( V_19 , V_90 ) ;
}
F_6 ( L_75 , V_24 ) ;
return V_24 ;
}
static long F_82 ( struct V_18 * V_19 ,
struct V_89 * V_90 ,
struct V_20 * V_21 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_260 * V_261 = & F_54 ( V_92 ) -> V_208 . V_262 ;
long V_24 = V_37 ;
if ( ( V_19 -> V_79 > 0 ) || ! F_30 ( & V_19 -> V_101 ) ||
! F_30 ( & V_19 -> V_102 ) ) {
F_9 ( & V_19 -> V_42 , L_76 ) ;
F_36 ( V_19 , V_110 , 0 ) ;
} else {
V_90 -> V_3 . V_27 = V_263 ;
V_90 -> V_3 . V_190 = V_261 -> V_190 ;
V_90 -> V_3 . V_131 = sizeof( struct V_183 ) ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_102 ) ;
F_67 ( V_19 ) ;
F_36 ( V_19 , V_112 , 0 ) ;
}
return V_24 ;
}
static void F_83 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_264 * V_208 ;
struct V_265 * V_266 ;
long V_24 ;
if ( V_19 -> V_215 - V_19 -> V_79 <= 0 ) {
F_9 ( & V_19 -> V_42 , L_77 ,
V_19 -> V_215 , V_19 -> V_79 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
return;
}
V_90 = F_45 ( V_19 ) ;
if ( ! V_90 ) {
F_9 ( & V_19 -> V_42 , L_78 ,
V_19 -> V_79 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
return;
}
V_92 = V_90 -> V_92 ;
V_208 = & F_54 ( V_92 ) -> V_208 . V_90 ;
V_24 = F_48 ( V_19 , V_90 , V_21 ) ;
if ( V_24 ) {
F_27 ( V_19 , V_90 ) ;
return;
}
if ( V_19 -> V_68 == V_118 ) {
switch ( V_208 -> V_212 ) {
case V_267 :
V_24 = F_81 ( V_19 , V_90 , V_21 ) ;
break;
case V_268 :
V_266 = & F_54 ( V_92 ) -> V_208 . V_269 ;
F_6 ( L_79 , V_266 -> V_190 ,
V_266 -> V_190 ) ;
V_90 -> V_3 . V_190 = V_266 -> V_190 ;
V_19 -> V_79 += 1 ;
V_90 -> type = V_93 ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_101 ) ;
F_38 ( V_19 -> V_120 , & V_90 -> V_106 ) ;
break;
case V_270 :
F_6 ( L_80 , V_208 -> V_190 ,
V_208 -> V_190 ) ;
V_90 -> V_3 . V_190 = V_208 -> V_190 ;
V_19 -> V_79 += 1 ;
V_90 -> type = V_94 ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_101 ) ;
F_38 ( V_19 -> V_120 , & V_90 -> V_106 ) ;
break;
case V_271 :
V_24 = F_82 ( V_19 , V_90 , V_21 ) ;
break;
case V_272 :
case V_273 :
default:
F_27 ( V_19 , V_90 ) ;
F_9 ( & V_19 -> V_42 , L_81 ,
( T_4 ) V_208 -> V_212 ) ;
F_36 ( V_19 ,
V_111 , 0 ) ;
break;
}
} else if ( V_208 -> V_212 == V_267 && V_19 -> V_68 == V_117 ) {
V_24 = F_81 ( V_19 , V_90 , V_21 ) ;
} else {
F_27 ( V_19 , V_90 ) ;
F_9 ( & V_19 -> V_42 , L_82 ,
V_19 -> V_68 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
}
}
static long F_84 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_24 ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = ( T_5 ) V_28 ;
V_21 -> V_29 = V_274 ;
V_24 = F_4 ( V_19 -> V_31 . V_32 , F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_35 :
V_19 -> V_9 |= V_84 ;
case V_82 :
V_19 -> V_9 |= V_88 ;
case V_275 :
F_9 ( & V_19 -> V_42 , L_83 ,
V_24 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_84 ,
V_24 ) ;
F_36 ( V_19 , V_110 , 0 ) ;
break;
}
return V_24 ;
}
static long F_85 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_108 :
case V_110 :
case V_111 :
case V_87 :
case V_109 :
case V_83 :
V_24 = ERROR ;
break;
case V_81 :
V_19 -> V_68 = V_117 ;
break;
case V_112 :
case V_118 :
case V_117 :
case V_113 :
case V_114 :
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_85 ,
V_19 -> V_68 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
return V_24 ;
}
static long F_86 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_113 :
V_19 -> V_68 = V_114 ;
break;
case V_81 :
V_24 = F_20 ( V_19 , V_276 ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_68 = V_117 ;
break;
case V_41 :
F_9 ( & V_19 -> V_42 , L_86 ,
V_24 ) ;
F_36 ( V_19 , V_110 , 0 ) ;
break;
case V_82 :
F_9 ( & V_19 -> V_42 , L_86 ,
V_24 ) ;
V_24 = ERROR ;
F_36 ( V_19 ,
V_111 , 0 ) ;
break;
case V_35 :
F_24 ( L_86 , V_24 ) ;
V_24 = 0 ;
break;
}
break;
case V_83 :
V_24 = ERROR ;
break;
case V_109 :
break;
case V_114 :
case V_117 :
case V_118 :
case V_112 :
case V_108 :
case V_110 :
case V_111 :
case V_87 :
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_87 ,
V_19 -> V_68 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
return V_24 ;
}
static long F_87 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_88 , V_19 -> V_68 ) ;
V_24 = F_88 ( V_19 -> V_31 . V_32 , V_277 ,
( T_2 ) V_19 -> V_278 | ( ( T_2 ) V_65 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_52 . V_160 =
F_51 ( * ( T_2 * ) V_19 -> V_279 ) ;
F_6 ( L_89 ,
V_19 -> V_52 . V_160 ) ;
} else {
F_6 ( L_90 , V_24 ) ;
V_24 = V_37 ;
}
if ( V_21 -> V_27 == V_74 ) {
V_24 = F_86 ( V_19 ) ;
} else if ( V_21 -> V_27 == V_276 ) {
V_24 = F_85 ( V_19 ) ;
} else {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_91 ,
( T_4 ) V_21 -> V_27 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
}
return V_24 ;
}
static long F_41 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
switch ( V_21 -> V_25 ) {
case V_26 :
switch ( V_21 -> V_27 ) {
case V_280 :
case V_281 :
case V_282 :
case V_283 :
if ( V_19 -> V_9 & V_96 ) {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_92 ) ;
F_36 ( V_19 ,
V_111 ,
0 ) ;
} else {
V_19 -> V_9 |= V_96 ;
V_24 = F_69 ( V_19 , V_21 ) ;
}
break;
case V_263 :
F_83 ( V_19 , V_21 ) ;
break;
case V_28 :
if ( V_21 -> V_29 == V_30 )
F_84 ( V_19 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_93 ,
( T_4 ) V_21 -> V_27 ) ;
F_36 ( V_19 ,
V_111 , 0 ) ;
break;
}
break;
case V_126 :
V_24 = F_39 ( V_19 , V_21 ) ;
break;
case V_72 :
V_24 = F_87 ( V_19 , V_21 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_94 ,
( T_4 ) V_21 -> V_25 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
break;
}
V_24 = V_19 -> V_9 & V_115 ;
return V_24 ;
}
static int F_89 ( struct V_18 * V_19 )
{
struct V_284 * V_285 = V_19 -> V_58 ;
const T_9 * V_286 ;
const T_9 * V_287 ;
V_286 = ( const T_9 * ) F_90 ( V_285 ,
L_95 ,
NULL ) ;
if ( ! V_286 ) {
F_74 ( L_96 ) ;
return - 1 ;
}
V_19 -> V_31 . V_135 [ V_139 ] . V_137 = F_57 ( * V_286 ) ;
V_286 ++ ;
V_287 = ( const T_9 * ) F_90 ( V_285 , L_97 ,
NULL ) ;
if ( ! V_287 ) {
F_24 ( L_98 ) ;
V_286 ++ ;
} else {
V_286 += F_57 ( * V_287 ) ;
}
V_287 = ( const T_9 * ) F_90 ( V_285 , L_99 ,
NULL ) ;
if ( ! V_287 ) {
F_24 ( L_100 ) ;
V_286 ++ ;
} else {
V_286 += F_57 ( * V_287 ) ;
}
V_19 -> V_31 . V_135 [ V_136 ] . V_137 = F_57 ( * V_286 ) ;
return 0 ;
}
static struct V_226 * F_91 ( const char * V_178 )
{
struct V_226 * V_227 = NULL ;
struct V_284 * V_285 ;
struct V_18 * V_19 ;
F_17 ( & V_288 ) ;
F_92 (vscsi, &ibmvscsis_dev_list, list) {
V_285 = V_19 -> V_58 ;
if ( ! strcmp ( F_62 ( & V_285 -> V_42 ) , V_178 ) ) {
V_227 = & V_19 -> V_227 ;
break;
}
}
F_16 ( & V_288 ) ;
return V_227 ;
}
static void F_93 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_264 * V_208 = (struct V_264 * ) V_92 -> V_140 -> V_289 ;
struct V_229 * V_230 ;
T_2 V_290 = 0 ;
enum V_291 V_292 ;
int V_293 = 0 ;
int V_24 = 0 ;
V_230 = V_19 -> V_227 . V_231 ;
if ( V_208 -> V_294 & 0x03 ) {
F_9 ( & V_19 -> V_42 , L_101 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
F_27 ( V_19 , V_90 ) ;
F_16 ( & V_19 -> V_62 ) ;
return;
}
if ( F_94 ( V_208 , & V_292 , & V_290 ) ) {
F_9 ( & V_19 -> V_42 , L_102 ,
V_208 -> V_190 ) ;
goto V_295;
return;
}
V_90 -> V_3 . V_296 = V_208 -> V_296 ;
switch ( V_208 -> V_297 ) {
case V_298 :
V_293 = V_299 ;
break;
case V_300 :
V_293 = V_301 ;
break;
case V_302 :
V_293 = V_303 ;
break;
case V_304 :
V_293 = V_305 ;
break;
default:
F_9 ( & V_19 -> V_42 , L_103 ,
V_208 -> V_297 ) ;
goto V_295;
}
V_90 -> V_1 . V_190 = F_51 ( V_208 -> V_190 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_100 ) ;
F_16 ( & V_19 -> V_62 ) ;
V_208 -> V_306 . V_307 [ 0 ] &= 0x3f ;
F_6 ( L_104 ,
& V_90 -> V_1 , F_95 ( & V_208 -> V_306 ) , ( int ) V_208 -> V_308 [ 0 ] ,
V_293 ) ;
V_24 = F_96 ( & V_90 -> V_1 , V_230 -> V_233 , V_208 -> V_308 ,
V_90 -> V_309 , F_95 ( & V_208 -> V_306 ) ,
V_290 , V_293 , V_292 , 0 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_105 , V_24 ) ;
goto V_295;
}
return;
V_295:
F_17 ( & V_19 -> V_62 ) ;
F_36 ( V_19 , V_111 , 0 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static void F_97 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_265 * V_310 = & F_54 ( V_92 ) -> V_208 . V_269 ;
int V_311 ;
T_2 V_312 = 0 ;
int V_24 = 0 ;
struct V_229 * V_230 ;
V_230 = V_19 -> V_227 . V_231 ;
V_90 -> V_3 . V_296 = V_310 -> V_296 ;
switch ( V_310 -> V_313 ) {
case V_314 :
V_311 = V_315 ;
V_312 = F_51 ( V_310 -> V_316 ) ;
break;
case V_317 :
V_311 = V_318 ;
break;
case V_319 :
V_311 = V_320 ;
break;
case V_321 :
V_311 = V_322 ;
break;
case V_323 :
V_311 = V_324 ;
break;
default:
F_9 ( & V_19 -> V_42 , L_106 ,
V_310 -> V_313 ) ;
V_90 -> V_1 . V_325 -> V_326 =
V_327 ;
V_24 = - 1 ;
break;
}
if ( ! V_24 ) {
V_90 -> V_1 . V_190 = F_51 ( V_310 -> V_190 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_100 ) ;
F_16 ( & V_19 -> V_62 ) ;
V_310 -> V_306 . V_307 [ 0 ] &= 0x3f ;
F_6 ( L_107 ,
V_310 -> V_313 ) ;
V_24 = F_98 ( & V_90 -> V_1 , V_230 -> V_233 , NULL ,
F_95 ( & V_310 -> V_306 ) , V_310 ,
V_311 , V_158 , V_312 , 0 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_108 ,
V_24 ) ;
V_90 -> V_1 . V_325 -> V_326 =
V_328 ;
}
}
if ( V_24 )
F_99 ( & V_90 -> V_1 , 0 , 0 ) ;
}
static void F_100 ( struct V_105 * V_106 )
{
struct V_89 * V_90 = F_33 ( V_106 , struct V_89 ,
V_106 ) ;
struct V_18 * V_19 = V_90 -> V_329 ;
F_17 ( & V_19 -> V_62 ) ;
F_44 ( & V_90 -> V_98 ) ;
if ( V_19 -> V_9 & ( V_115 | V_116 ) ) {
F_27 ( V_19 , V_90 ) ;
if ( F_30 ( & V_19 -> V_100 ) &&
F_30 ( & V_19 -> V_101 ) &&
( V_19 -> V_9 & V_103 ) ) {
V_19 -> V_9 &= ~ V_103 ;
F_31 ( & V_19 -> V_104 ) ;
}
F_16 ( & V_19 -> V_62 ) ;
return;
}
F_16 ( & V_19 -> V_62 ) ;
switch ( V_90 -> type ) {
case V_94 :
F_93 ( V_19 , V_90 ) ;
break;
case V_93 :
F_97 ( V_19 , V_90 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_109 ,
V_90 -> type ) ;
F_17 ( & V_19 -> V_62 ) ;
F_27 ( V_19 , V_90 ) ;
F_16 ( & V_19 -> V_62 ) ;
break;
}
}
static int F_101 ( struct V_18 * V_19 , int V_330 )
{
struct V_89 * V_90 ;
int V_331 ;
F_102 ( & V_19 -> V_99 ) ;
V_19 -> V_332 = F_103 ( V_330 , sizeof( struct V_89 ) ,
V_158 ) ;
if ( ! V_19 -> V_332 )
return - V_232 ;
for ( V_331 = 0 , V_90 = (struct V_89 * ) V_19 -> V_332 ; V_331 < V_330 ;
V_331 ++ , V_90 ++ ) {
V_90 -> V_329 = V_19 ;
F_37 ( & V_90 -> V_106 , F_100 ) ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_99 ) ;
}
return 0 ;
}
static void F_104 ( struct V_18 * V_19 )
{
F_78 ( V_19 -> V_332 ) ;
V_19 -> V_332 = NULL ;
F_102 ( & V_19 -> V_99 ) ;
}
static enum V_333 F_105 ( struct V_334 * V_200 )
{
struct V_335 * V_336 = F_33 ( V_200 , struct V_335 , V_200 ) ;
struct V_18 * V_19 = F_33 ( V_336 , struct V_18 ,
V_77 ) ;
F_17 ( & V_19 -> V_62 ) ;
V_336 -> V_78 += 1 ;
V_336 -> V_128 = false ;
F_67 ( V_19 ) ;
F_16 ( & V_19 -> V_62 ) ;
return V_337 ;
}
static long F_106 ( struct V_18 * V_19 )
{
struct V_335 * V_336 ;
V_336 = & V_19 -> V_77 ;
F_107 ( & V_336 -> V_200 , V_338 , V_201 ) ;
V_336 -> V_200 . V_339 = F_105 ;
V_336 -> V_128 = false ;
V_336 -> V_78 = 0 ;
return V_37 ;
}
static void F_108 ( struct V_18 * V_19 )
{
struct V_335 * V_336 ;
V_336 = & V_19 -> V_77 ;
( void ) F_109 ( & V_336 -> V_200 ) ;
V_336 -> V_128 = false ;
V_336 -> V_78 = 0 ;
}
static T_10 F_110 ( int V_340 , void * V_341 )
{
struct V_18 * V_19 = V_341 ;
F_15 ( V_19 -> V_58 ) ;
F_111 ( & V_19 -> V_342 ) ;
return V_343 ;
}
static long F_112 ( struct V_18 * V_19 )
{
T_4 V_27 ;
long V_24 ;
V_24 = F_21 ( V_19 , & V_27 ) ;
if ( V_24 )
F_36 ( V_19 , V_111 , 0 ) ;
else if ( V_27 == V_73 )
V_19 -> V_68 = V_113 ;
else
V_19 -> V_68 = V_114 ;
return V_24 ;
}
static long F_113 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
V_344:
switch ( V_19 -> V_68 ) {
case V_113 :
V_24 = F_20 ( V_19 , V_74 ) ;
switch ( V_24 ) {
case V_39 :
case V_82 :
case V_35 :
V_19 -> V_68 = V_81 ;
V_24 = V_37 ;
break;
case V_41 :
break;
case V_40 :
break;
default:
V_19 -> V_68 = V_83 ;
V_24 = V_40 ;
break;
}
break;
case V_114 :
V_24 = F_20 ( V_19 , V_276 ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_68 = V_117 ;
V_24 = V_37 ;
break;
case V_82 :
case V_35 :
V_19 -> V_68 = V_113 ;
goto V_344;
case V_41 :
break;
case V_40 :
break;
default:
V_24 = V_40 ;
break;
}
break;
case V_81 :
case V_112 :
case V_118 :
case V_117 :
V_24 = V_37 ;
break;
case V_109 :
V_24 = ERROR ;
V_19 -> V_68 = V_83 ;
break;
case V_110 :
case V_111 :
default:
F_9 ( & V_19 -> V_42 , L_110 ,
V_19 -> V_68 ) ;
V_24 = V_37 ;
break;
}
return V_24 ;
}
static long F_114 ( struct V_18 * V_19 , int V_345 )
{
long V_24 = 0 ;
int V_346 ;
struct V_284 * V_285 = V_19 -> V_58 ;
V_346 = 1 ;
V_19 -> V_63 . V_64 = V_346 ;
V_19 -> V_63 . V_66 =
(struct V_20 * ) F_115 ( V_158 ) ;
if ( ! V_19 -> V_63 . V_66 )
return - V_232 ;
V_19 -> V_63 . V_69 = ( ( T_4 ) V_346 * V_347 ) - 1 ;
V_19 -> V_63 . V_86 = F_116 ( & V_285 -> V_42 ,
V_19 -> V_63 . V_66 ,
V_65 , V_348 ) ;
if ( F_117 ( & V_285 -> V_42 , V_19 -> V_63 . V_86 ) ) {
F_118 ( ( unsigned long ) V_19 -> V_63 . V_66 ) ;
return - V_232 ;
}
V_24 = F_26 ( V_19 -> V_31 . V_32 , V_19 -> V_63 . V_86 , V_65 ) ;
if ( V_24 ) {
if ( V_24 == V_35 ) {
V_19 -> V_68 = V_113 ;
V_24 = 0 ;
} else {
F_119 ( & V_285 -> V_42 , V_19 -> V_63 . V_86 ,
V_65 , V_348 ) ;
F_118 ( ( unsigned long ) V_19 -> V_63 . V_66 ) ;
V_24 = - V_238 ;
}
} else {
V_19 -> V_68 = V_113 ;
}
return V_24 ;
}
static void F_120 ( struct V_18 * V_19 )
{
F_119 ( & V_19 -> V_58 -> V_42 , V_19 -> V_63 . V_86 ,
V_65 , V_348 ) ;
F_118 ( ( unsigned long ) V_19 -> V_63 . V_66 ) ;
V_19 -> V_63 . V_66 = NULL ;
V_19 -> V_68 = V_108 ;
}
static T_5 F_121 ( struct V_18 * V_19 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_1 * V_1 = & V_90 -> V_1 ;
struct V_264 * V_208 = (struct V_264 * ) V_92 -> V_140 -> V_289 ;
struct V_349 V_350 ;
T_5 V_24 = V_1 -> V_351 ;
if ( V_19 -> V_194 && ( F_122 ( V_208 -> V_308 ) || F_123 ( V_208 -> V_308 ) ) )
if ( F_124 ( V_1 -> V_352 ,
V_1 -> V_353 , & V_350 ) )
if ( V_350 . V_354 == V_355 &&
( V_1 -> V_4 == 0 ||
V_1 -> V_4 == V_1 -> V_356 ) ) {
V_24 = V_357 ;
V_90 -> V_9 |= V_203 ;
}
return V_24 ;
}
static long F_125 ( struct V_18 * V_19 ,
struct V_89 * V_90 , T_4 * V_358 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_1 * V_1 = & V_90 -> V_1 ;
struct V_2 * V_3 ;
T_4 V_131 ;
T_1 V_359 ;
char * V_341 ;
T_1 * V_360 ;
long V_24 = V_37 ;
F_17 ( & V_19 -> V_62 ) ;
V_3 = & F_54 ( V_92 ) -> V_208 . V_3 ;
V_131 = sizeof( * V_3 ) ;
memset ( V_3 , 0 , V_131 ) ;
V_341 = V_3 -> V_341 ;
V_3 -> V_212 = V_361 ;
if ( V_19 -> V_80 > 0 && V_19 -> V_68 == V_118 )
V_3 -> V_214 = F_2 ( V_19 -> V_80 ) ;
else
V_3 -> V_214 = F_2 ( 1 + V_19 -> V_80 ) ;
V_3 -> V_190 = V_90 -> V_3 . V_190 ;
V_3 -> V_9 = 0 ;
if ( V_90 -> type == V_94 ) {
V_3 -> V_29 = F_121 ( V_19 , V_90 ) ;
if ( V_3 -> V_29 ) {
F_6 ( L_111 , V_90 ,
( int ) V_3 -> V_29 ) ;
F_1 ( V_1 , V_3 ) ;
if ( V_1 -> V_353 && V_1 -> V_352 ) {
V_3 -> V_362 =
F_2 ( V_1 -> V_353 ) ;
V_3 -> V_9 |= V_363 ;
V_131 += V_1 -> V_353 ;
memcpy ( V_341 , V_1 -> V_352 ,
V_1 -> V_353 ) ;
}
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_364 ) >>
V_365 ;
} else if ( V_90 -> V_9 & V_203 ) {
F_6 ( L_112 , V_90 ) ;
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_364 ) >>
V_365 ;
} else {
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_366 ) >>
V_367 ;
}
} else {
V_3 -> V_29 = 0 ;
V_3 -> V_368 = F_2 ( 4 ) ;
V_3 -> V_9 |= V_369 ;
switch ( V_1 -> V_325 -> V_326 ) {
case V_370 :
case V_371 :
V_359 = V_372 ;
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_366 ) >>
V_367 ;
break;
case V_327 :
case V_373 :
V_359 = V_374 ;
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_364 ) >>
V_365 ;
break;
case V_375 :
case V_328 :
default:
V_359 = V_376 ;
V_3 -> V_296 = ( V_90 -> V_3 . V_296 & V_364 ) >>
V_365 ;
break;
}
V_360 = ( T_1 * ) V_341 ;
* V_360 = F_2 ( V_359 ) ;
V_341 = ( char * ) ( V_360 + 1 ) ;
V_131 += 4 ;
}
F_58 () ;
V_24 = F_50 ( V_131 , V_19 -> V_31 . V_135 [ V_139 ] . V_137 , V_92 -> V_140 -> V_141 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
F_51 ( V_92 -> V_143 ) ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_80 = 0 ;
* V_358 = V_131 ;
break;
case V_145 :
if ( F_3 ( V_19 ) )
V_19 -> V_9 |= V_88 | V_84 ;
F_9 ( & V_19 -> V_42 , L_113 ,
V_24 , V_19 -> V_9 , V_19 -> V_68 ) ;
break;
case V_147 :
case V_146 :
default:
F_9 ( & V_19 -> V_42 , L_114 ,
V_24 ) ;
break;
}
F_16 ( & V_19 -> V_62 ) ;
return V_24 ;
}
static int F_126 ( struct V_89 * V_90 , struct V_377 * V_378 ,
int V_379 , struct V_380 * V_381 , int V_382 ,
enum V_291 V_292 , unsigned int V_54 )
{
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_383 * V_129 = V_92 -> V_129 ;
struct V_18 * V_19 = V_129 -> V_384 ;
struct V_377 * V_385 ;
T_6 V_386 , V_387 ;
T_11 V_388 ;
T_11 V_389 , V_390 ;
int V_391 ;
long V_392 ;
long V_24 = 0 ;
F_6 ( L_115 , V_292 , V_54 ) ;
if ( V_54 == 0 )
return 0 ;
V_385 = V_378 ;
V_389 = 0 ;
V_390 = 0 ;
V_391 = 0 ;
V_392 = V_54 ;
do {
if ( V_389 == 0 ) {
if ( V_391 >= V_382 ) {
F_9 ( & V_19 -> V_42 , L_116 ) ;
V_24 = - V_393 ;
break;
}
V_386 = F_51 ( V_381 [ V_391 ] . V_394 ) ;
V_389 = F_57 ( V_381 [ V_391 ] . V_131 ) ;
}
if ( V_390 == 0 ) {
if ( ! V_385 ) {
F_9 ( & V_19 -> V_42 , L_117 ) ;
V_24 = - V_393 ;
break;
}
V_387 = F_127 ( V_385 ) ;
V_390 = F_128 ( V_385 ) ;
}
V_388 = V_392 ;
if ( V_388 > V_389 )
V_388 = V_389 ;
if ( V_388 > V_390 )
V_388 = V_390 ;
if ( V_388 > V_395 )
V_388 = V_395 ;
if ( V_292 == V_8 ) {
V_24 = F_50 ( V_388 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
V_386 ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_387 ) ;
} else {
struct V_264 * V_208 = (struct V_264 * ) V_92 -> V_140 -> V_289 ;
if ( ! F_122 ( V_208 -> V_308 ) )
F_129 ( L_118 , V_396 ,
F_130 ( V_385 ) , V_388 ) ;
F_131 () ;
F_58 () ;
V_24 = F_50 ( V_388 ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_387 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ,
V_386 ) ;
}
switch ( V_24 ) {
case V_39 :
break;
case V_145 :
case V_147 :
case V_146 :
if ( F_3 ( V_19 ) ) {
F_17 ( & V_19 -> V_62 ) ;
V_19 -> V_9 |=
( V_88 | V_84 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
F_9 ( & V_19 -> V_42 , L_119 ,
V_24 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_120 ,
V_24 ) ;
break;
}
if ( ! V_24 ) {
V_392 -= V_388 ;
if ( V_392 ) {
V_389 -= V_388 ;
if ( V_389 == 0 )
V_391 ++ ;
else
V_386 += V_388 ;
V_390 -= V_388 ;
if ( V_390 == 0 )
V_385 = F_132 ( V_385 ) ;
else
V_387 += V_388 ;
} else {
break;
}
}
} while ( ! V_24 );
return V_24 ;
}
static void F_133 ( unsigned long V_341 )
{
struct V_18 * V_19 = (struct V_18 * ) V_341 ;
struct V_20 * V_21 ;
long V_24 ;
bool V_124 = true ;
volatile T_5 V_25 ;
F_17 ( & V_19 -> V_62 ) ;
F_6 ( L_121 ) ;
if ( F_134 ( V_19 ) ) {
F_23 ( V_19 -> V_58 ) ;
F_6 ( L_122 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
return;
}
V_24 = V_19 -> V_9 & V_115 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_397:
V_19 -> V_63 . V_67 =
( V_19 -> V_63 . V_67 + 1 ) & V_19 -> V_63 . V_69 ;
if ( ! V_24 ) {
V_24 = F_41 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_126 ) {
V_24 = F_39 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_85 ) {
F_6 ( L_123 ) ;
if ( V_19 -> V_63 . V_67 )
V_19 -> V_63 . V_67 -= 1 ;
else
V_19 -> V_63 . V_67 = V_19 -> V_63 . V_69 ;
break;
}
}
V_21 -> V_25 = V_75 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
}
if ( ! V_24 ) {
if ( V_124 ) {
F_23 ( V_19 -> V_58 ) ;
V_124 = false ;
F_6 ( L_124 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_397;
} else {
F_6 ( L_125 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_63 . V_67 ) ;
}
F_6 ( L_126 ,
( int ) F_30 ( & V_19 -> V_101 ) , V_19 -> V_9 ,
V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static int F_135 ( struct V_284 * V_285 ,
const struct V_398 * V_399 )
{
struct V_18 * V_19 ;
int V_24 = 0 ;
long V_400 = 0 ;
char V_401 [ 24 ] ;
V_19 = F_73 ( sizeof( * V_19 ) , V_158 ) ;
if ( ! V_19 ) {
V_24 = - V_232 ;
F_74 ( L_127 ) ;
return V_24 ;
}
V_19 -> V_58 = V_285 ;
V_19 -> V_42 = V_285 -> V_42 ;
F_102 ( & V_19 -> V_101 ) ;
F_102 ( & V_19 -> V_102 ) ;
F_102 ( & V_19 -> V_100 ) ;
snprintf ( V_19 -> V_227 . V_228 , 256 , L_128 , F_62 ( & V_285 -> V_42 ) ) ;
F_6 ( L_129 , V_19 -> V_227 . V_228 ) ;
V_24 = F_89 ( V_19 ) ;
if ( V_24 )
goto V_402;
F_6 ( L_130 ,
V_19 -> V_31 . V_135 [ V_139 ] . V_137 ,
V_19 -> V_31 . V_135 [ V_136 ] . V_137 ) ;
strcpy ( V_19 -> V_403 , L_131 ) ;
strncat ( V_19 -> V_403 , V_285 -> V_178 , V_404 ) ;
V_19 -> V_31 . V_32 = V_285 -> V_205 ;
F_17 ( & V_288 ) ;
F_28 ( & V_19 -> V_98 , & V_405 ) ;
F_16 ( & V_288 ) ;
V_19 -> V_215 = V_406 ;
V_24 = F_136 ( & V_19 -> V_129 , & V_285 -> V_42 , V_19 -> V_215 ,
V_133 ) ;
if ( V_24 )
goto V_407;
V_19 -> V_129 . V_384 = V_19 ;
V_24 = F_101 ( V_19 , V_19 -> V_215 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_132 ,
V_24 , V_19 -> V_215 ) ;
goto V_408;
}
F_137 ( & V_19 -> V_62 ) ;
V_24 = F_106 ( V_19 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_133 , V_24 ) ;
goto V_409;
}
V_24 = F_114 ( V_19 , 256 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_134 ,
V_24 ) ;
goto V_410;
}
V_19 -> V_279 = F_73 ( V_65 , V_158 ) ;
if ( ! V_19 -> V_279 ) {
V_24 = - V_232 ;
F_9 ( & V_19 -> V_42 , L_135 ) ;
goto V_411;
}
V_19 -> V_278 = F_116 ( & V_285 -> V_42 , V_19 -> V_279 , V_65 ,
V_348 ) ;
if ( F_117 ( & V_285 -> V_42 , V_19 -> V_278 ) ) {
F_9 ( & V_19 -> V_42 , L_136 ) ;
goto V_412;
}
V_400 = F_88 ( V_19 -> V_31 . V_32 , V_277 ,
( T_2 ) V_19 -> V_278 | ( ( T_2 ) V_65 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_400 == V_39 )
V_19 -> V_52 . V_160 =
F_51 ( * ( T_2 * ) V_19 -> V_279 ) ;
F_6 ( L_137 ,
V_400 , V_19 -> V_52 . V_160 ) ;
F_138 ( & V_19 -> V_342 , F_133 ,
( unsigned long ) V_19 ) ;
F_139 ( & V_19 -> V_104 ) ;
snprintf ( V_401 , 24 , L_138 , F_62 ( & V_285 -> V_42 ) ) ;
V_19 -> V_120 = F_140 ( V_401 ) ;
if ( ! V_19 -> V_120 ) {
V_24 = - V_232 ;
F_9 ( & V_19 -> V_42 , L_139 ) ;
goto V_413;
}
V_24 = F_141 ( V_285 -> V_414 , F_110 , 0 , L_140 , V_19 ) ;
if ( V_24 ) {
V_24 = - V_415 ;
F_9 ( & V_19 -> V_42 , L_141 , V_24 ) ;
goto V_416;
}
F_17 ( & V_19 -> V_62 ) ;
F_23 ( V_285 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_142 , V_24 ) ;
V_24 = - V_238 ;
F_16 ( & V_19 -> V_62 ) ;
goto V_417;
}
if ( F_112 ( V_19 ) ) {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_143 , V_24 ) ;
F_16 ( & V_19 -> V_62 ) ;
goto V_418;
}
F_16 ( & V_19 -> V_62 ) ;
F_142 ( & V_285 -> V_42 , V_19 ) ;
return 0 ;
V_418:
F_15 ( V_285 ) ;
V_417:
V_417 ( V_285 -> V_414 , V_19 ) ;
V_416:
F_143 ( V_19 -> V_120 ) ;
V_413:
F_119 ( & V_285 -> V_42 , V_19 -> V_278 , V_65 ,
V_348 ) ;
V_412:
F_78 ( V_19 -> V_279 ) ;
V_411:
F_144 ( & V_19 -> V_342 ) ;
F_7 ( V_19 ) ;
F_120 ( V_19 ) ;
V_410:
F_108 ( V_19 ) ;
V_409:
F_104 ( V_19 ) ;
V_408:
F_145 ( & V_19 -> V_129 ) ;
V_407:
F_17 ( & V_288 ) ;
F_44 ( & V_19 -> V_98 ) ;
F_16 ( & V_288 ) ;
V_402:
F_78 ( V_19 ) ;
return V_24 ;
}
static int F_146 ( struct V_284 * V_285 )
{
struct V_18 * V_19 = F_147 ( & V_285 -> V_42 ) ;
F_6 ( L_144 , F_62 ( & V_19 -> V_58 -> V_42 ) ) ;
F_15 ( V_285 ) ;
V_417 ( V_285 -> V_414 , V_19 ) ;
F_143 ( V_19 -> V_120 ) ;
F_119 ( & V_285 -> V_42 , V_19 -> V_278 , V_65 ,
V_348 ) ;
F_78 ( V_19 -> V_279 ) ;
F_144 ( & V_19 -> V_342 ) ;
F_7 ( V_19 ) ;
F_120 ( V_19 ) ;
F_108 ( V_19 ) ;
F_104 ( V_19 ) ;
F_145 ( & V_19 -> V_129 ) ;
F_17 ( & V_288 ) ;
F_44 ( & V_19 -> V_98 ) ;
F_16 ( & V_288 ) ;
F_78 ( V_19 ) ;
return 0 ;
}
static T_12 F_148 ( struct V_419 * V_42 ,
struct V_420 * V_293 , char * V_289 )
{
return snprintf ( V_289 , V_65 , L_145 , V_421 ) ;
}
static T_12 F_149 ( struct V_419 * V_42 ,
struct V_420 * V_293 , char * V_289 )
{
return snprintf ( V_289 , V_65 , L_146 , V_160 ) ;
}
static T_12 F_150 ( struct V_419 * V_42 ,
struct V_420 * V_293 , char * V_289 )
{
struct V_18 * V_19 = F_33 ( V_42 , struct V_18 , V_42 ) ;
return snprintf ( V_289 , V_65 , L_146 , V_19 -> V_58 -> V_205 ) ;
}
static int F_151 ( void )
{
struct V_422 * V_423 , * V_424 ;
const char * V_399 , * V_425 , * V_178 ;
const T_4 * V_330 ;
V_423 = F_152 ( L_147 ) ;
if ( ! V_423 )
return - V_426 ;
V_425 = F_153 ( V_423 , L_148 , NULL ) ;
V_399 = F_153 ( V_423 , L_149 , NULL ) ;
if ( V_425 && V_399 )
snprintf ( V_421 , sizeof( V_421 ) , L_150 , V_425 , V_399 ) ;
V_178 = F_153 ( V_423 , L_151 , NULL ) ;
if ( V_178 )
strncpy ( V_162 , V_178 , sizeof( V_162 ) ) ;
V_330 = F_153 ( V_423 , L_152 , NULL ) ;
if ( V_330 )
V_160 = * V_330 ;
F_154 ( V_423 ) ;
V_424 = F_152 ( L_153 ) ;
if ( V_424 ) {
const T_4 * V_427 ;
V_427 = F_153 ( V_424 , L_154 ,
NULL ) ;
if ( V_427 )
V_395 = * V_427 ;
F_154 ( V_424 ) ;
}
return 0 ;
}
static char * F_155 ( void )
{
return L_140 ;
}
static char * F_156 ( struct V_428 * V_234 )
{
struct V_226 * V_227 =
F_33 ( V_234 , struct V_226 , V_234 ) ;
return V_227 -> V_228 ;
}
static T_3 F_157 ( struct V_428 * V_234 )
{
struct V_226 * V_227 =
F_33 ( V_234 , struct V_226 , V_234 ) ;
return V_227 -> V_429 ;
}
static T_1 F_158 ( struct V_428 * V_234 )
{
return 1 ;
}
static int F_159 ( struct V_428 * V_234 )
{
return 1 ;
}
static int F_160 ( struct V_428 * V_234 )
{
return 0 ;
}
static T_1 F_161 ( struct V_428 * V_234 )
{
return 1 ;
}
static int F_162 ( struct V_1 * V_1 )
{
return F_163 ( V_1 ) ;
}
static void F_164 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = F_33 ( V_1 , struct V_89 ,
V_1 ) ;
struct V_18 * V_19 = V_90 -> V_329 ;
F_6 ( L_155 , V_1 , V_90 -> V_9 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_44 ( & V_90 -> V_98 ) ;
F_28 ( & V_90 -> V_98 , & V_19 -> V_102 ) ;
F_67 ( V_19 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static T_1 F_165 ( struct V_237 * V_233 )
{
return 0 ;
}
static int F_166 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = F_33 ( V_1 , struct V_89 ,
V_1 ) ;
struct V_91 * V_92 = V_90 -> V_92 ;
int V_24 ;
F_6 ( L_156 ,
V_1 , V_1 -> V_356 ) ;
V_24 = F_167 ( V_90 , & F_54 ( V_92 ) -> V_208 . V_90 , F_126 ,
1 , 1 ) ;
if ( V_24 ) {
F_74 ( L_157 , V_24 ) ;
return - V_430 ;
}
F_168 ( V_1 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_170 ( struct V_431 * V_432 )
{
}
static int F_171 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_172 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = F_33 ( V_1 , struct V_89 ,
V_1 ) ;
struct V_91 * V_92 = V_90 -> V_92 ;
struct V_18 * V_19 = V_90 -> V_329 ;
char * V_433 ;
T_4 V_131 = 0 ;
int V_24 ;
F_6 ( L_158 ,
V_1 , V_1 -> V_356 ) ;
V_24 = F_167 ( V_90 , & F_54 ( V_92 ) -> V_208 . V_90 , F_126 , 1 ,
1 ) ;
if ( V_24 ) {
F_74 ( L_159 , V_24 ) ;
V_433 = V_1 -> V_352 ;
V_1 -> V_353 = 18 ;
memset ( V_1 -> V_352 , 0 , V_1 -> V_353 ) ;
F_173 ( 0 , V_1 -> V_352 , V_434 ,
0x08 , 0x01 ) ;
}
F_125 ( V_19 , V_90 , & V_131 ) ;
V_90 -> V_3 . V_27 = V_263 ;
V_90 -> V_3 . V_131 = V_131 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = F_33 ( V_1 , struct V_89 ,
V_1 ) ;
struct V_18 * V_19 = V_90 -> V_329 ;
T_4 V_131 ;
F_6 ( L_160 , V_1 ) ;
F_125 ( V_19 , V_90 , & V_131 ) ;
V_90 -> V_3 . V_27 = V_263 ;
V_90 -> V_3 . V_131 = V_131 ;
return 0 ;
}
static void F_175 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = F_33 ( V_1 , struct V_89 ,
V_1 ) ;
struct V_18 * V_19 = V_90 -> V_329 ;
T_4 V_131 ;
F_6 ( L_161 ,
V_1 , ( int ) V_1 -> V_325 -> V_326 ) ;
F_125 ( V_19 , V_90 , & V_131 ) ;
V_90 -> V_3 . V_27 = V_263 ;
V_90 -> V_3 . V_131 = V_131 ;
}
static void F_176 ( struct V_1 * V_1 )
{
F_6 ( L_162 , V_1 ) ;
}
static struct V_435 * F_177 ( struct V_436 * V_437 ,
struct V_438 * V_439 ,
const char * V_178 )
{
struct V_226 * V_227 ;
V_227 = F_91 ( V_178 ) ;
if ( V_227 ) {
V_227 -> V_440 = V_441 ;
F_6 ( L_163 ,
V_178 , V_227 , V_227 -> V_440 ) ;
return & V_227 -> V_442 ;
}
return F_178 ( - V_443 ) ;
}
static void F_179 ( struct V_435 * V_444 )
{
struct V_226 * V_227 = F_33 ( V_444 ,
struct V_226 ,
V_442 ) ;
F_6 ( L_164 ,
F_180 ( & V_227 -> V_442 . V_445 . V_446 ) ) ;
}
static struct V_428 * F_181 ( struct V_435 * V_444 ,
struct V_438 * V_439 ,
const char * V_178 )
{
struct V_226 * V_227 =
F_33 ( V_444 , struct V_226 , V_442 ) ;
int V_24 ;
V_227 -> V_447 = false ;
V_24 = F_182 ( & V_227 -> V_442 , & V_227 -> V_234 ,
V_227 -> V_440 ) ;
if ( V_24 )
return F_178 ( V_24 ) ;
return & V_227 -> V_234 ;
}
static void F_183 ( struct V_428 * V_234 )
{
struct V_226 * V_227 = F_33 ( V_234 ,
struct V_226 ,
V_234 ) ;
V_227 -> V_447 = true ;
V_227 -> V_448 = false ;
F_79 ( V_227 ) ;
F_184 ( V_234 ) ;
}
static T_12 F_185 ( struct V_449 * V_450 ,
char * V_451 )
{
return F_186 ( V_451 , V_65 , L_145 , V_452 ) ;
}
static T_12 F_187 ( struct V_449 * V_450 ,
char * V_451 )
{
struct V_428 * V_234 = F_188 ( V_450 ) ;
struct V_226 * V_227 = F_33 ( V_234 ,
struct V_226 ,
V_234 ) ;
return snprintf ( V_451 , V_65 , L_165 , ( V_227 -> V_448 ) ? 1 : 0 ) ;
}
static T_12 F_189 ( struct V_449 * V_450 ,
const char * V_451 , T_13 V_453 )
{
struct V_428 * V_234 = F_188 ( V_450 ) ;
struct V_226 * V_227 = F_33 ( V_234 ,
struct V_226 ,
V_234 ) ;
struct V_18 * V_19 = F_33 ( V_227 , struct V_18 , V_227 ) ;
unsigned long V_454 ;
int V_24 ;
long V_455 ;
V_24 = F_190 ( V_451 , 0 , & V_454 ) ;
if ( V_24 < 0 ) {
F_74 ( L_166 ) ;
return - V_443 ;
}
if ( ( V_454 != 0 ) && ( V_454 != 1 ) ) {
F_74 ( L_167 ) ;
return - V_443 ;
}
if ( V_454 ) {
V_227 -> V_448 = true ;
F_17 ( & V_19 -> V_62 ) ;
V_455 = F_113 ( V_19 ) ;
if ( V_455 )
F_74 ( L_168 ,
V_455 , V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
} else {
V_227 -> V_448 = false ;
}
F_6 ( L_169 , V_19 -> V_68 ) ;
return V_453 ;
}
static void F_191 ( struct V_419 * V_42 ) {}
static int T_14 F_192 ( void )
{
int V_24 = 0 ;
V_24 = F_151 () ;
if ( V_24 ) {
F_74 ( L_170 , V_24 ) ;
goto V_456;
}
V_24 = F_193 ( & V_457 ) ;
if ( V_24 ) {
F_74 ( L_171 ) ;
goto V_456;
}
V_24 = F_194 ( & V_458 ) ;
if ( V_24 ) {
F_74 ( L_172 , V_24 ) ;
goto V_459;
}
V_24 = F_195 ( & V_460 ) ;
if ( V_24 ) {
F_74 ( L_173 , V_24 ) ;
goto V_461;
}
return 0 ;
V_461:
F_196 ( & V_458 ) ;
V_459:
F_197 ( & V_457 ) ;
V_456:
return V_24 ;
}
static void T_15 F_198 ( void )
{
F_199 ( L_174 ) ;
F_200 ( & V_460 ) ;
F_196 ( & V_458 ) ;
F_197 ( & V_457 ) ;
}
