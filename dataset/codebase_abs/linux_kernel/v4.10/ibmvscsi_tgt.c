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
static void F_22 ( struct V_76 * V_77 )
{
struct V_18 * V_19 = F_23 ( V_77 , struct V_18 ,
V_78 ) ;
T_3 V_59 ;
bool V_79 = false ;
F_17 ( & V_19 -> V_62 ) ;
V_59 = V_19 -> V_59 ;
V_19 -> V_59 = 0 ;
F_6 ( L_7 , V_19 -> V_9 ,
V_19 -> V_68 ) ;
switch ( V_19 -> V_68 ) {
case V_80 :
case V_81 :
break;
case V_82 :
if ( V_59 == V_81 )
V_19 -> V_68 = V_59 ;
break;
case V_83 :
switch ( V_59 ) {
case V_81 :
case V_82 :
V_19 -> V_68 = V_59 ;
break;
case V_84 :
break;
default:
break;
}
break;
case V_85 :
if ( V_59 == V_81 )
V_19 -> V_68 = V_59 ;
break;
case V_86 :
switch ( V_59 ) {
case V_81 :
V_19 -> V_68 = V_59 ;
V_19 -> V_9 |= V_87 ;
V_19 -> V_9 &= ~ ( V_88 |
V_89 ) ;
F_19 () ;
if ( V_19 -> V_9 & V_90 ) {
V_19 -> V_9 &= ~ V_90 ;
F_24 ( & V_19 -> V_91 ) ;
}
break;
case V_82 :
case V_83 :
case V_84 :
F_9 ( & V_19 -> V_42 , L_8 ,
V_19 -> V_68 ) ;
break;
}
break;
case V_84 :
switch ( V_59 ) {
case V_81 :
V_19 -> V_9 |= V_87 ;
V_19 -> V_68 = V_59 ;
V_19 -> V_9 &= ~ ( V_88 |
V_89 ) ;
F_14 ( V_19 ) ;
break;
case V_82 :
case V_83 :
V_19 -> V_68 = V_59 ;
break;
}
break;
case V_92 :
case V_93 :
case V_94 :
V_79 = true ;
V_19 -> V_68 = V_59 ;
break;
case V_95 :
if ( V_59 == V_81 )
V_19 -> V_68 = V_59 ;
break;
default:
break;
}
if ( V_79 ) {
F_6 ( L_9 ,
( int ) F_25 ( & V_19 -> V_96 ) ,
( int ) F_25 ( & V_19 -> V_97 ) ) ;
if ( ! F_25 ( & V_19 -> V_96 ) ||
! F_25 ( & V_19 -> V_97 ) ) {
V_19 -> V_9 |= V_98 ;
F_6 ( L_10 , V_19 -> V_9 ) ;
F_16 ( & V_19 -> V_62 ) ;
F_26 ( & V_19 -> V_79 ) ;
F_17 ( & V_19 -> V_62 ) ;
}
F_6 ( L_11 ) ;
F_27 ( V_19 ) ;
}
F_16 ( & V_19 -> V_62 ) ;
}
static void F_28 ( struct V_18 * V_19 , T_4 V_59 ,
T_4 V_99 )
{
T_4 V_68 ;
switch ( V_59 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
break;
default:
F_9 ( & V_19 -> V_42 , L_12 ,
V_59 ) ;
return;
}
V_19 -> V_9 |= V_99 ;
F_6 ( L_13 ,
V_59 , V_99 , V_19 -> V_9 , V_19 -> V_68 ) ;
if ( ! ( V_19 -> V_9 & ( V_89 | V_88 ) ) ) {
V_19 -> V_9 |= V_88 ;
V_19 -> V_59 = V_59 ;
F_29 ( & V_19 -> V_78 , F_22 ) ;
( void ) F_30 ( V_19 -> V_100 , & V_19 -> V_78 ) ;
} else {
if ( V_19 -> V_59 )
V_68 = V_19 -> V_59 ;
else
V_68 = V_19 -> V_68 ;
switch ( V_68 ) {
case V_80 :
case V_81 :
break;
case V_85 :
case V_82 :
case V_95 :
if ( V_59 == V_81 )
V_19 -> V_59 = V_59 ;
break;
case V_83 :
switch ( V_59 ) {
case V_81 :
case V_82 :
V_19 -> V_59 = V_59 ;
break;
default:
break;
}
break;
case V_86 :
case V_84 :
case V_92 :
case V_93 :
case V_94 :
V_19 -> V_59 = V_59 ;
break;
default:
break;
}
}
F_6 ( L_14 ,
V_19 -> V_9 , V_19 -> V_59 ) ;
}
static long F_31 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_80 :
case V_82 :
case V_83 :
case V_85 :
case V_81 :
case V_95 :
V_24 = ERROR ;
break;
case V_92 :
V_19 -> V_68 = V_93 ;
break;
case V_84 :
case V_94 :
case V_93 :
case V_86 :
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_15 ,
V_19 -> V_68 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
return V_24 ;
}
static long F_32 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_92 :
V_24 = F_20 ( V_19 , V_101 ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_68 = V_93 ;
break;
case V_41 :
F_9 ( & V_19 -> V_42 , L_16 ,
V_24 ) ;
F_28 ( V_19 , V_82 , 0 ) ;
break;
case V_102 :
F_9 ( & V_19 -> V_42 , L_16 ,
V_24 ) ;
V_24 = ERROR ;
F_28 ( V_19 ,
V_83 , 0 ) ;
break;
case V_35 :
F_33 ( L_16 , V_24 ) ;
V_24 = 0 ;
break;
}
break;
case V_95 :
V_24 = ERROR ;
break;
case V_81 :
break;
case V_86 :
case V_93 :
case V_94 :
case V_84 :
case V_80 :
case V_82 :
case V_83 :
case V_85 :
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_17 ,
V_19 -> V_68 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
return V_24 ;
}
static long F_34 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_18 , V_19 -> V_68 ) ;
V_24 = F_35 ( V_19 -> V_31 . V_32 , V_103 ,
( T_2 ) V_19 -> V_104 | ( ( T_2 ) V_65 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_52 . V_105 =
F_36 ( * ( T_2 * ) V_19 -> V_106 ) ;
F_6 ( L_19 ,
V_19 -> V_52 . V_105 ) ;
} else {
F_6 ( L_20 , V_24 ) ;
V_24 = V_37 ;
}
if ( V_21 -> V_27 == V_74 ) {
V_24 = F_32 ( V_19 ) ;
} else if ( V_21 -> V_27 == V_101 ) {
V_24 = F_31 ( V_19 ) ;
} else {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_21 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
}
return V_24 ;
}
static long F_37 ( struct V_18 * V_19 )
{
long V_24 = V_37 ;
T_4 V_27 ;
V_19 -> V_9 &= V_107 ;
V_19 -> V_108 . V_109 = 0 ;
V_19 -> V_110 = 0 ;
V_19 -> V_111 = 0 ;
V_24 = F_38 ( V_19 -> V_58 ) ;
if ( V_24 ) {
F_33 ( L_22 ,
V_24 ) ;
return V_24 ;
}
V_24 = F_21 ( V_19 , & V_27 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_23 ,
V_24 ) ;
return V_24 ;
}
if ( V_27 == V_73 ) {
V_24 = F_20 ( V_19 , V_74 ) ;
switch ( V_24 ) {
case V_39 :
case V_102 :
case V_35 :
V_24 = V_37 ;
break;
case V_41 :
case V_40 :
break;
default:
V_19 -> V_68 = V_95 ;
V_24 = V_40 ;
break;
}
} else if ( V_27 == V_74 ) {
V_24 = F_32 ( V_19 ) ;
}
return V_24 ;
}
static void F_39 ( struct V_18 * V_19 )
{
int V_54 ;
long V_24 = V_37 ;
F_6 ( L_24 , V_19 -> V_9 ) ;
if ( V_19 -> V_9 & ( V_112 | V_113 ) ) {
V_19 -> V_9 &= V_107 ;
V_19 -> V_108 . V_109 = 0 ;
V_19 -> V_110 = 0 ;
V_19 -> V_111 = 0 ;
V_19 -> V_68 = V_92 ;
F_38 ( V_19 -> V_58 ) ;
} else {
V_24 = F_14 ( V_19 ) ;
if ( V_24 == V_37 ) {
V_19 -> V_68 = V_92 ;
V_54 = V_19 -> V_63 . V_64 * V_65 ;
V_24 = F_40 ( V_19 -> V_31 . V_32 ,
V_19 -> V_63 . V_114 , V_54 ) ;
if ( V_24 == V_35 || V_24 == V_39 ) {
V_24 = F_37 ( V_19 ) ;
}
if ( V_24 != V_37 ) {
F_6 ( L_25 , V_24 ) ;
V_19 -> V_68 = V_85 ;
V_19 -> V_9 |= V_87 ;
F_14 ( V_19 ) ;
}
} else {
V_19 -> V_68 = V_85 ;
V_19 -> V_9 |= V_87 ;
}
}
}
static void F_41 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
switch ( V_116 -> type ) {
case V_119 :
case V_120 :
if ( V_19 -> V_110 )
V_19 -> V_110 -= 1 ;
break;
case V_121 :
V_19 -> V_9 &= ~ V_122 ;
break;
case V_123 :
break;
default:
F_9 ( & V_19 -> V_42 , L_26 ,
V_116 -> type ) ;
break;
}
V_116 -> V_118 = NULL ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_125 ) ;
F_43 ( V_118 ) ;
if ( F_25 ( & V_19 -> V_96 ) && F_25 ( & V_19 -> V_97 ) &&
F_25 ( & V_19 -> V_126 ) && ( V_19 -> V_9 & V_98 ) ) {
V_19 -> V_9 &= ~ V_98 ;
F_24 ( & V_19 -> V_79 ) ;
}
}
static long F_44 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
F_6 ( L_27 ,
( int ) V_21 -> V_27 , V_19 -> V_9 , V_19 -> V_68 ) ;
switch ( V_21 -> V_27 ) {
case V_127 :
case V_128 :
case V_129 :
F_13 ( V_19 , true ) ;
break;
default:
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_28 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 , V_82 ,
V_87 ) ;
break;
}
if ( V_24 == V_37 ) {
switch ( V_19 -> V_68 ) {
case V_80 :
case V_85 :
case V_95 :
break;
case V_81 :
V_19 -> V_9 |= ( V_87 | V_113 ) ;
break;
case V_86 :
break;
case V_92 :
break;
case V_93 :
F_28 ( V_19 , V_84 ,
( V_87 |
V_113 ) ) ;
break;
case V_94 :
if ( ( V_19 -> V_110 > 0 ) ||
! F_25 ( & V_19 -> V_97 ) ||
! F_25 ( & V_19 -> V_126 ) ||
! F_25 ( & V_19 -> V_96 ) ) {
F_6 ( L_29 ,
V_19 -> V_110 ,
( int ) F_25 ( & V_19 -> V_97 ) ,
( int ) F_25 ( & V_19 -> V_126 ) ,
( int ) F_25 ( & V_19 -> V_96 ) ) ;
F_33 ( L_30 ) ;
} else {
F_6 ( L_31 ) ;
}
F_28 ( V_19 , V_84 ,
( V_87 |
V_113 ) ) ;
break;
case V_82 :
case V_83 :
case V_84 :
V_19 -> V_9 |= ( V_87 | V_113 ) ;
break;
}
}
V_24 = V_19 -> V_9 & V_88 ;
F_6 ( L_32 ,
V_19 -> V_9 , V_19 -> V_68 , V_24 ) ;
return V_24 ;
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
long V_24 ;
bool V_130 = true ;
volatile T_5 V_25 ;
F_6 ( L_33 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_63 . V_67 ) ;
V_24 = V_19 -> V_9 & V_88 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_131:
V_19 -> V_63 . V_67 =
( V_19 -> V_63 . V_67 + 1 ) & V_19 -> V_63 . V_69 ;
if ( ! V_24 ) {
V_24 = F_46 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_132 ) {
V_24 = F_44 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_113 ) {
F_6 ( L_34 ) ;
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
if ( V_130 ) {
F_38 ( V_19 -> V_58 ) ;
V_130 = false ;
F_6 ( L_35 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_131;
}
F_6 ( L_36 , V_24 ) ;
}
static void F_47 ( struct V_18 * V_19 )
{
struct V_115 * V_116 , * V_133 ;
F_6 ( L_37 ,
( int ) F_25 ( & V_19 -> V_126 ) ,
V_19 -> V_108 . V_134 ) ;
F_48 (cmd, nxt, &vscsi->waiting_rsp, list) {
F_49 ( & V_116 -> V_124 ) ;
F_41 ( V_19 , V_116 ) ;
}
}
static struct V_115 * F_50 ( struct V_18 * V_19 )
{
struct V_115 * V_116 = NULL ;
struct V_117 * V_118 ;
V_118 = F_51 ( & V_19 -> V_135 ) ;
if ( V_118 ) {
V_116 = F_52 ( & V_19 -> V_125 ,
struct V_115 , V_124 ) ;
if ( V_116 ) {
F_49 ( & V_116 -> V_124 ) ;
V_116 -> V_118 = V_118 ;
V_116 -> type = V_123 ;
memset ( & V_116 -> V_1 , 0 , sizeof( V_116 -> V_1 ) ) ;
} else {
F_43 ( V_118 ) ;
}
}
return V_116 ;
}
static void F_27 ( struct V_18 * V_19 )
{
int V_136 = false ;
F_6 ( L_38 , V_19 -> V_9 ,
V_19 -> V_68 ) ;
if ( V_19 -> V_68 != V_92 || V_19 -> V_9 & V_113 )
V_136 = true ;
switch ( V_19 -> V_68 ) {
case V_81 :
F_14 ( V_19 ) ;
F_19 () ;
F_53 () ;
if ( V_19 -> V_9 & V_90 ) {
V_19 -> V_9 &= ~ V_90 ;
F_24 ( & V_19 -> V_91 ) ;
}
break;
case V_83 :
F_39 ( V_19 ) ;
F_6 ( L_39 , V_19 -> V_9 ) ;
break;
case V_82 :
F_14 ( V_19 ) ;
V_19 -> V_9 &= ~ ( V_88 | V_89 ) ;
V_19 -> V_9 |= V_87 ;
if ( V_19 -> V_137 . V_138 )
V_19 -> V_68 = V_85 ;
else
V_19 -> V_68 = V_86 ;
F_6 ( L_40 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
break;
case V_84 :
V_19 -> V_108 . V_109 = 0 ;
V_19 -> V_110 = 0 ;
V_19 -> V_111 = 0 ;
if ( V_19 -> V_9 & V_113 ) {
V_19 -> V_68 = V_92 ;
V_19 -> V_9 &= V_107 ;
} else {
V_19 -> V_68 = V_93 ;
V_19 -> V_9 &= ~ V_89 ;
}
F_6 ( L_41 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
F_45 ( V_19 ) ;
break;
case V_85 :
V_19 -> V_9 &= ~ V_89 ;
F_6 ( L_42 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_43 ,
V_19 -> V_68 ) ;
break;
}
if ( V_136 )
F_47 ( V_19 ) ;
if ( V_19 -> V_60 != 0 ) {
V_19 -> V_9 |= V_19 -> V_61 ;
F_28 ( V_19 , V_19 -> V_60 , 0 ) ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = 0 ;
F_6 ( L_44 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_61 ,
V_19 -> V_60 ) ;
}
F_6 ( L_45 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_59 ) ;
}
static long F_54 ( struct V_18 * V_19 ,
struct V_115 * V_116 ,
struct V_20 * V_21 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
long V_24 = 0 ;
T_3 V_139 ;
V_139 = F_55 ( V_21 -> V_140 ) ;
if ( ( V_139 > V_141 ) || ( V_139 == 0 ) ) {
F_9 ( & V_19 -> V_42 , L_46 , V_139 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
return V_142 ;
}
V_24 = F_56 ( V_139 , V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_21 -> V_146 ) ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_118 -> V_148 -> V_149 ) ;
switch ( V_24 ) {
case V_39 :
V_116 -> V_150 = F_57 () ;
V_118 -> V_151 = V_21 -> V_146 ;
V_118 -> V_152 = V_139 ;
F_6 ( L_47 ,
F_36 ( V_21 -> V_146 ) , V_116 -> V_150 ) ;
break;
case V_153 :
if ( F_3 ( V_19 ) )
F_28 ( V_19 ,
V_83 ,
( V_87 |
V_112 ) ) ;
else
F_28 ( V_19 ,
V_83 , 0 ) ;
F_9 ( & V_19 -> V_42 , L_48 ,
V_24 ) ;
break;
case V_154 :
case V_155 :
default:
F_9 ( & V_19 -> V_42 , L_48 ,
V_24 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
return V_24 ;
}
static long F_58 ( struct V_18 * V_19 ,
struct V_117 * V_118 )
{
struct V_156 * V_157 = & F_59 ( V_118 ) -> V_157 . V_158 ;
struct V_159 * V_160 ;
T_4 V_99 = 0 ;
T_6 V_161 ;
long V_24 ;
V_157 -> V_162 . V_29 = F_60 ( V_163 ) ;
if ( F_55 ( V_157 -> V_162 . V_164 ) > sizeof( * V_160 ) ) {
V_157 -> V_162 . V_29 = F_60 ( V_165 ) ;
return 0 ;
}
V_160 = F_61 ( & V_19 -> V_58 -> V_42 , sizeof( * V_160 ) , & V_161 ,
V_166 ) ;
if ( ! V_160 ) {
F_9 ( & V_19 -> V_42 , L_49 ,
V_118 -> V_135 ) ;
V_157 -> V_162 . V_29 = F_60 ( V_165 ) ;
return 0 ;
}
V_24 = F_56 ( F_55 ( V_157 -> V_162 . V_164 ) ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_157 -> V_22 ) ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_161 ) ;
if ( V_24 != V_39 ) {
if ( V_24 == V_153 ) {
if ( F_3 ( V_19 ) )
V_99 = ( V_87 | V_112 ) ;
}
F_33 ( L_50 ,
V_24 ) ;
F_6 ( L_51 ,
F_36 ( V_157 -> V_22 ) , V_19 -> V_9 , V_99 ) ;
F_28 ( V_19 , V_83 ,
V_99 ) ;
goto V_167;
}
if ( V_19 -> V_52 . V_105 == 0 )
V_19 -> V_52 . V_105 =
F_62 ( V_160 -> V_105 ) ;
strncpy ( V_19 -> V_52 . V_168 , V_160 -> V_168 ,
sizeof( V_19 -> V_52 . V_168 ) ) ;
strncpy ( V_19 -> V_52 . V_169 , V_160 -> V_169 ,
sizeof( V_19 -> V_52 . V_169 ) ) ;
V_19 -> V_52 . V_170 = F_62 ( V_160 -> V_170 ) ;
V_19 -> V_52 . V_53 = F_62 ( V_160 -> V_53 ) ;
strncpy ( V_160 -> V_168 , V_171 ,
sizeof( V_160 -> V_168 ) ) ;
strncpy ( V_160 -> V_169 , V_19 -> V_31 . V_169 ,
sizeof( V_160 -> V_169 ) ) ;
V_160 -> V_105 = F_2 ( V_19 -> V_31 . V_172 ) ;
V_160 -> V_170 = F_2 ( V_173 ) ;
V_160 -> V_53 = F_2 ( V_174 ) ;
memset ( & V_160 -> V_175 [ 0 ] , 0 , sizeof( V_160 -> V_175 ) ) ;
V_160 -> V_175 [ 0 ] = F_2 ( V_176 ) ;
F_63 () ;
V_24 = F_56 ( sizeof( * V_160 ) , V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_161 , V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_157 -> V_22 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_155 :
case V_154 :
case V_153 :
if ( F_3 ( V_19 ) )
V_99 = ( V_87 | V_112 ) ;
default:
F_9 ( & V_19 -> V_42 , L_52 ,
V_24 ) ;
F_28 ( V_19 ,
V_83 ,
V_99 ) ;
break;
}
V_167:
F_64 ( & V_19 -> V_58 -> V_42 , sizeof( * V_160 ) , V_160 , V_161 ) ;
F_6 ( L_53 , V_24 ) ;
return V_24 ;
}
static int F_65 ( struct V_18 * V_19 , struct V_117 * V_118 )
{
struct V_177 * V_157 = & F_59 ( V_118 ) -> V_157 . V_178 ;
struct V_178 * V_179 ;
struct V_180 * V_162 ;
T_6 V_161 ;
T_3 V_181 , V_139 , V_29 , V_182 , V_183 ;
T_1 V_184 ;
T_4 V_99 = 0 ;
long V_24 = 0 ;
V_181 = F_55 ( V_157 -> V_162 . V_164 ) ;
V_182 = F_66 ( struct V_178 , V_185 ) ;
if ( ( V_181 < V_182 ) || ( V_181 > V_65 ) ) {
F_33 ( L_54 , V_181 ) ;
V_157 -> V_162 . V_29 = F_60 ( V_165 ) ;
return 0 ;
}
V_179 = F_61 ( & V_19 -> V_58 -> V_42 , V_181 , & V_161 ,
V_166 ) ;
if ( ! V_179 ) {
F_9 ( & V_19 -> V_42 , L_49 ,
V_118 -> V_135 ) ;
V_157 -> V_162 . V_29 = F_60 ( V_165 ) ;
return 0 ;
}
V_24 = F_56 ( V_181 , V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_157 -> V_22 ) ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_161 ) ;
if ( V_24 == V_39 ) {
strncpy ( V_179 -> V_186 , F_67 ( & V_19 -> V_58 -> V_42 ) ,
V_187 ) ;
V_139 = V_181 - V_182 ;
V_29 = V_163 ;
V_162 = (struct V_180 * ) & V_179 -> V_185 ;
while ( ( V_139 > 0 ) && ( V_29 == V_163 ) && ! V_24 ) {
F_6 ( L_55 ,
V_139 , F_62 ( V_162 -> V_188 ) ,
F_55 ( V_162 -> V_164 ) ) ;
V_183 = F_55 ( V_162 -> V_164 ) ;
if ( V_183 > V_139 ) {
F_9 ( & V_19 -> V_42 , L_56 ) ;
V_29 = V_165 ;
break;
}
if ( V_183 == 0 ) {
F_9 ( & V_19 -> V_42 , L_57 ) ;
V_29 = V_165 ;
break;
}
switch ( V_162 -> V_188 ) {
default:
F_6 ( L_58 ) ;
V_162 -> V_189 = 0 ;
V_184 = F_2 ( ( T_1 ) V_190 ) ;
V_179 -> V_9 &= ~ V_184 ;
break;
}
V_139 = V_139 - V_183 ;
V_162 = (struct V_180 * )
( ( char * ) V_162 + V_183 ) ;
}
V_157 -> V_162 . V_29 = F_60 ( V_29 ) ;
F_63 () ;
V_24 = F_56 ( V_181 , V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_161 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_157 -> V_22 ) ) ;
if ( V_24 != V_39 ) {
F_6 ( L_59 ,
V_24 ) ;
if ( V_24 == V_153 ) {
if ( F_3 ( V_19 ) )
V_99 = ( V_87 |
V_112 ) ;
}
F_33 ( L_60 ,
V_24 ) ;
F_28 ( V_19 ,
V_83 ,
V_99 ) ;
}
}
F_64 ( & V_19 -> V_58 -> V_42 , V_181 , V_179 , V_161 ) ;
F_6 ( L_61 ,
V_24 , V_19 -> V_51 ) ;
return V_24 ;
}
static long F_68 ( struct V_18 * V_19 , struct V_117 * V_118 )
{
struct V_191 * V_157 = (struct V_191 * ) & F_59 ( V_118 ) -> V_157 ;
struct V_192 * V_193 ;
long V_24 = V_37 ;
switch ( F_62 ( V_157 -> type ) ) {
case V_194 :
V_193 = & F_59 ( V_118 ) -> V_157 . V_195 ;
V_19 -> V_196 = F_36 ( V_193 -> V_22 ) ;
V_19 -> V_197 = F_36 ( V_193 -> V_162 . V_198 ) ;
V_157 -> V_29 = F_60 ( V_163 ) ;
break;
case V_199 :
V_24 = F_58 ( V_19 , V_118 ) ;
break;
case V_200 :
V_24 = F_65 ( V_19 , V_118 ) ;
break;
case V_201 :
if ( V_19 -> V_68 == V_93 ) {
V_19 -> V_202 = true ;
V_157 -> V_29 = F_60 ( V_163 ) ;
} else {
F_33 ( L_62 ) ;
V_157 -> V_29 = F_60 ( V_165 ) ;
}
break;
default:
V_157 -> V_29 = F_60 ( V_203 ) ;
break;
}
return V_24 ;
}
static void F_69 ( struct V_18 * V_19 , long V_24 )
{
T_7 V_204 ;
if ( V_24 != V_102 ) {
F_47 ( V_19 ) ;
if ( V_24 == V_35 )
V_19 -> V_9 |= V_112 ;
if ( ! ( V_19 -> V_9 & V_87 ) ) {
V_19 -> V_9 |= V_87 ;
if ( ! ( V_19 -> V_68 & ( V_82 |
V_83 |
V_85 | V_95 ) ) ) {
F_9 ( & V_19 -> V_42 , L_63 ,
V_19 -> V_68 , V_19 -> V_9 , V_24 ) ;
}
F_28 ( V_19 ,
V_83 , 0 ) ;
}
return;
}
if ( ( V_19 -> V_108 . V_109 < V_205 ) ||
( V_19 -> V_68 == V_94 ) ) {
F_6 ( L_64 ,
V_19 -> V_9 , ( int ) V_19 -> V_108 . V_134 ,
V_19 -> V_108 . V_109 ) ;
if ( ! V_19 -> V_108 . V_134 ) {
if ( V_19 -> V_108 . V_109 <
V_205 ) {
V_204 = V_206 ;
} else {
V_204 = F_70 ( V_207 , 0 ) ;
}
V_19 -> V_108 . V_134 = true ;
F_71 ( & V_19 -> V_108 . V_208 , V_204 ,
V_209 ) ;
}
} else {
V_19 -> V_9 |= V_87 ;
F_47 ( V_19 ) ;
if ( ! ( V_19 -> V_68 & ( V_82 |
V_83 |
V_85 | V_95 ) ) ) {
F_9 ( & V_19 -> V_42 , L_65 ) ;
F_28 ( V_19 ,
V_83 ,
0 ) ;
}
}
}
static void F_72 ( struct V_18 * V_19 )
{
T_2 V_210 = 0 ;
struct V_20 * V_21 = (struct V_20 * ) & V_210 ;
struct V_115 * V_116 , * V_133 ;
struct V_117 * V_118 ;
long V_24 = V_37 ;
if ( ! ( V_19 -> V_9 & V_87 ) ) {
F_48 (cmd, nxt, &vscsi->waiting_rsp, list) {
V_118 = V_116 -> V_118 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = V_116 -> V_3 . V_27 ;
if ( V_116 -> V_9 & V_211 )
V_21 -> V_29 = V_212 ;
V_21 -> V_140 = F_60 ( V_116 -> V_3 . V_139 ) ;
V_24 = F_4 ( V_19 -> V_58 -> V_213 ,
F_36 ( V_210 ) ,
F_36 ( V_116 -> V_3 . V_198 ) ) ;
F_6 ( L_66 ,
V_116 , F_36 ( V_116 -> V_3 . V_198 ) , V_24 ) ;
if ( V_24 == V_39 ) {
V_19 -> V_108 . V_109 = 0 ;
F_49 ( & V_116 -> V_124 ) ;
F_41 ( V_19 , V_116 ) ;
} else {
F_69 ( V_19 , V_24 ) ;
break;
}
}
if ( ! V_24 ) {
V_19 -> V_108 . V_109 = 0 ;
}
} else {
F_47 ( V_19 ) ;
}
}
static void F_73 ( struct V_18 * V_19 ,
struct V_115 * V_116 ,
struct V_20 * V_21 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_191 * V_157 = (struct V_191 * ) & F_59 ( V_118 ) -> V_157 ;
T_4 V_99 = 0 ;
long V_24 ;
F_63 () ;
V_24 = F_56 ( sizeof( struct V_191 ) ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_118 -> V_148 -> V_149 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_21 -> V_146 ) ) ;
if ( ! V_24 ) {
V_116 -> V_3 . V_27 = V_214 ;
V_116 -> V_3 . V_139 = sizeof( struct V_191 ) ;
V_116 -> V_3 . V_198 = V_157 -> V_198 ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_126 ) ;
F_72 ( V_19 ) ;
} else {
F_6 ( L_67 , V_24 ) ;
if ( V_24 == V_153 ) {
if ( F_3 ( V_19 ) )
V_99 = ( V_87 | V_112 ) ;
}
F_9 ( & V_19 -> V_42 , L_68 ,
V_24 ) ;
F_41 ( V_19 , V_116 ) ;
F_28 ( V_19 , V_83 ,
V_99 ) ;
}
}
static long F_74 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_117 * V_118 ;
struct V_115 * V_116 ;
struct V_191 * V_157 ;
long V_24 = V_37 ;
switch ( V_19 -> V_68 ) {
case V_92 :
F_6 ( L_69 ,
V_19 -> V_9 ) ;
return V_37 ;
case V_94 :
case V_93 :
break;
case V_81 :
case V_84 :
case V_82 :
case V_83 :
default:
F_9 ( & V_19 -> V_42 , L_70 ,
V_19 -> V_68 ) ;
return V_37 ;
}
V_116 = F_50 ( V_19 ) ;
if ( ! V_116 ) {
F_9 ( & V_19 -> V_42 , L_71 ,
V_19 -> V_110 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
return ERROR ;
}
V_118 = V_116 -> V_118 ;
V_116 -> type = V_121 ;
V_24 = F_54 ( V_19 , V_116 , V_21 ) ;
if ( ! V_24 ) {
V_157 = (struct V_191 * ) & F_59 ( V_118 ) -> V_157 ;
F_6 ( L_72 , F_62 ( V_157 -> type ) ) ;
V_24 = F_68 ( V_19 , V_118 ) ;
F_6 ( L_73 , F_55 ( V_157 -> V_29 ) ,
V_24 ) ;
if ( ! V_24 )
F_73 ( V_19 , V_116 , V_21 ) ;
} else {
F_41 ( V_19 , V_116 ) ;
}
F_6 ( L_74 , V_24 ) ;
return V_24 ;
}
static long F_75 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_215 * V_3 = & F_59 ( V_118 ) -> V_216 . V_217 ;
struct V_218 * V_219 ;
T_4 V_99 = 0 ;
long V_24 = V_37 ;
memset ( V_3 , 0 , sizeof( struct V_215 ) ) ;
V_3 -> V_220 = V_221 ;
V_3 -> V_222 = F_2 ( V_19 -> V_223 ) ;
V_3 -> V_198 = V_116 -> V_3 . V_198 ;
V_3 -> V_224 = F_2 ( V_141 ) ;
V_3 -> V_225 = F_2 ( V_141 ) ;
V_219 = (struct V_218 * ) & V_3 -> V_226 ;
V_219 -> V_227 = V_228 ;
V_19 -> V_111 = 0 ;
V_116 -> V_3 . V_139 = sizeof( struct V_215 ) ;
F_63 () ;
V_24 = F_56 ( V_116 -> V_3 . V_139 , V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_118 -> V_148 -> V_149 , V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_118 -> V_151 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_153 :
if ( F_3 ( V_19 ) )
V_99 = V_87 | V_112 ;
F_9 ( & V_19 -> V_42 , L_75 ,
V_24 ) ;
F_28 ( V_19 , V_83 ,
V_99 ) ;
break;
case V_155 :
case V_154 :
default:
F_9 ( & V_19 -> V_42 , L_75 ,
V_24 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
return V_24 ;
}
static long F_76 ( struct V_18 * V_19 ,
struct V_115 * V_116 , T_1 V_229 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_230 * V_231 = & F_59 ( V_118 ) -> V_216 . V_232 ;
struct V_218 * V_219 ;
T_4 V_99 = 0 ;
long V_24 = V_37 ;
memset ( V_231 , 0 , sizeof( * V_231 ) ) ;
V_231 -> V_220 = V_233 ;
V_231 -> V_229 = F_2 ( V_229 ) ;
V_231 -> V_198 = V_116 -> V_3 . V_198 ;
V_219 = (struct V_218 * ) & V_231 -> V_226 ;
V_219 -> V_227 = V_228 ;
V_116 -> V_3 . V_139 = sizeof( * V_231 ) ;
F_63 () ;
V_24 = F_56 ( V_116 -> V_3 . V_139 , V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_118 -> V_148 -> V_149 , V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_118 -> V_151 ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_153 :
if ( F_3 ( V_19 ) )
V_99 = V_87 | V_112 ;
F_9 ( & V_19 -> V_42 , L_76 ,
V_24 ) ;
F_28 ( V_19 , V_83 ,
V_99 ) ;
break;
case V_155 :
case V_154 :
default:
F_9 ( & V_19 -> V_42 , L_76 ,
V_24 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
return V_24 ;
}
static int F_77 ( struct V_234 * V_137 )
{
char * V_186 = V_137 -> V_235 ;
struct V_236 * V_237 ;
int V_24 ;
if ( V_137 -> V_238 ) {
F_6 ( L_77 ) ;
return 0 ;
}
V_237 = F_78 ( sizeof( * V_237 ) , V_239 ) ;
if ( ! V_237 ) {
F_79 ( L_78 ) ;
return - V_240 ;
}
V_237 -> V_241 = F_80 ( & V_137 -> V_242 , 0 , 0 ,
V_243 , V_186 , V_237 ,
NULL ) ;
if ( F_81 ( V_237 -> V_241 ) ) {
V_24 = F_82 ( V_237 -> V_241 ) ;
goto V_244;
}
V_137 -> V_238 = V_237 ;
return 0 ;
V_244:
F_83 ( V_237 ) ;
return V_24 ;
}
static int F_84 ( struct V_234 * V_137 )
{
struct V_245 * V_241 ;
struct V_236 * V_237 ;
V_237 = V_137 -> V_238 ;
if ( ! V_237 )
return - V_246 ;
V_241 = V_237 -> V_241 ;
if ( ! V_241 )
return - V_246 ;
F_85 ( V_241 ) ;
F_86 ( V_241 ) ;
F_87 ( V_241 ) ;
V_137 -> V_238 = NULL ;
F_83 ( V_237 ) ;
return 0 ;
}
static long F_88 ( struct V_18 * V_19 ,
struct V_115 * V_116 ,
struct V_20 * V_21 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_247 * V_248 = & F_59 ( V_118 ) -> V_216 . V_249 ;
struct V_250 {
T_8 V_251 ;
T_8 V_252 ;
} * V_253 , * V_137 ;
struct V_218 * V_219 ;
T_1 V_229 = 0x0 ;
long V_24 = V_37 ;
V_253 = (struct V_250 * ) V_248 -> V_254 ;
V_137 = (struct V_250 * ) V_248 -> V_255 ;
V_219 = (struct V_218 * ) & V_248 -> V_256 ;
if ( F_62 ( V_248 -> V_257 ) > V_141 )
V_229 = V_258 ;
else if ( F_62 ( V_248 -> V_257 ) < 64 )
V_229 = V_259 ;
else if ( ( F_36 ( V_253 -> V_251 ) > ( V_260 - 1 ) ) ||
( F_36 ( V_137 -> V_251 ) > ( V_260 - 1 ) ) )
V_229 = V_261 ;
else if ( V_248 -> V_262 & V_263 )
V_229 = V_264 ;
else if ( V_219 -> V_227 & ( ~ V_228 ) )
V_229 = V_265 ;
else if ( ( V_219 -> V_227 & V_228 ) == 0 )
V_229 = V_265 ;
if ( V_19 -> V_68 == V_94 )
V_229 = V_266 ;
V_24 = F_77 ( & V_19 -> V_137 ) ;
if ( V_24 )
V_229 = V_259 ;
V_116 -> V_3 . V_27 = V_267 ;
V_116 -> V_3 . V_198 = V_248 -> V_198 ;
F_6 ( L_79 , V_229 ) ;
if ( V_229 )
V_24 = F_76 ( V_19 , V_116 , V_229 ) ;
else
V_24 = F_75 ( V_19 , V_116 ) ;
if ( ! V_24 ) {
if ( ! V_229 )
V_19 -> V_68 = V_94 ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_126 ) ;
F_72 ( V_19 ) ;
} else {
F_41 ( V_19 , V_116 ) ;
}
F_6 ( L_80 , V_24 ) ;
return V_24 ;
}
static long F_89 ( struct V_18 * V_19 ,
struct V_115 * V_116 ,
struct V_20 * V_21 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_268 * V_269 = & F_59 ( V_118 ) -> V_216 . V_270 ;
long V_24 = V_37 ;
if ( ( V_19 -> V_110 > 0 ) || ! F_25 ( & V_19 -> V_97 ) ||
! F_25 ( & V_19 -> V_126 ) ) {
F_9 ( & V_19 -> V_42 , L_81 ) ;
F_28 ( V_19 , V_82 , 0 ) ;
} else {
V_116 -> V_3 . V_27 = V_271 ;
V_116 -> V_3 . V_198 = V_269 -> V_198 ;
V_116 -> V_3 . V_139 = sizeof( struct V_191 ) ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_126 ) ;
F_72 ( V_19 ) ;
F_28 ( V_19 , V_84 , 0 ) ;
}
return V_24 ;
}
static void F_90 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_272 * V_216 ;
struct V_273 * V_274 ;
long V_24 ;
if ( V_19 -> V_223 - V_19 -> V_110 <= 0 ) {
F_9 ( & V_19 -> V_42 , L_82 ,
V_19 -> V_223 , V_19 -> V_110 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
return;
}
V_116 = F_50 ( V_19 ) ;
if ( ! V_116 ) {
F_9 ( & V_19 -> V_42 , L_83 ,
V_19 -> V_110 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
return;
}
V_118 = V_116 -> V_118 ;
V_216 = & F_59 ( V_118 ) -> V_216 . V_116 ;
V_24 = F_54 ( V_19 , V_116 , V_21 ) ;
if ( V_24 ) {
F_41 ( V_19 , V_116 ) ;
return;
}
if ( V_19 -> V_68 == V_94 ) {
switch ( V_216 -> V_220 ) {
case V_275 :
V_24 = F_88 ( V_19 , V_116 , V_21 ) ;
break;
case V_276 :
V_274 = & F_59 ( V_118 ) -> V_216 . V_277 ;
F_6 ( L_84 , V_274 -> V_198 ,
V_274 -> V_198 ) ;
V_116 -> V_3 . V_198 = V_274 -> V_198 ;
V_19 -> V_110 += 1 ;
V_116 -> type = V_119 ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_97 ) ;
F_30 ( V_19 -> V_100 , & V_116 -> V_77 ) ;
break;
case V_278 :
F_6 ( L_85 , V_216 -> V_198 ,
V_216 -> V_198 ) ;
V_116 -> V_3 . V_198 = V_216 -> V_198 ;
V_19 -> V_110 += 1 ;
V_116 -> type = V_120 ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_97 ) ;
F_30 ( V_19 -> V_100 , & V_116 -> V_77 ) ;
break;
case V_279 :
V_24 = F_89 ( V_19 , V_116 , V_21 ) ;
break;
case V_280 :
case V_281 :
default:
F_41 ( V_19 , V_116 ) ;
F_9 ( & V_19 -> V_42 , L_86 ,
( T_4 ) V_216 -> V_220 ) ;
F_28 ( V_19 ,
V_83 , 0 ) ;
break;
}
} else if ( V_216 -> V_220 == V_275 && V_19 -> V_68 == V_93 ) {
V_24 = F_88 ( V_19 , V_116 , V_21 ) ;
} else {
F_41 ( V_19 , V_116 ) ;
F_9 ( & V_19 -> V_42 , L_87 ,
V_19 -> V_68 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
}
}
static long F_91 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_22 [ 2 ] = { 0 , 0 } ;
long V_24 ;
V_21 = (struct V_20 * ) & V_22 ;
V_21 -> V_25 = V_26 ;
V_21 -> V_27 = ( T_5 ) V_28 ;
V_21 -> V_29 = V_282 ;
V_24 = F_4 ( V_19 -> V_31 . V_32 , F_5 ( V_22 [ V_33 ] ) ,
F_5 ( V_22 [ V_34 ] ) ) ;
switch ( V_24 ) {
case V_39 :
break;
case V_35 :
V_19 -> V_9 |= V_112 ;
case V_102 :
V_19 -> V_9 |= V_87 ;
case V_283 :
F_9 ( & V_19 -> V_42 , L_88 ,
V_24 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_89 ,
V_24 ) ;
F_28 ( V_19 , V_82 , 0 ) ;
break;
}
return V_24 ;
}
static long F_46 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
long V_24 = V_37 ;
switch ( V_21 -> V_25 ) {
case V_26 :
switch ( V_21 -> V_27 ) {
case V_284 :
case V_285 :
case V_286 :
case V_287 :
if ( V_19 -> V_9 & V_122 ) {
V_24 = ERROR ;
F_9 ( & V_19 -> V_42 , L_90 ) ;
F_28 ( V_19 ,
V_83 ,
0 ) ;
} else {
V_19 -> V_9 |= V_122 ;
V_24 = F_74 ( V_19 , V_21 ) ;
}
break;
case V_271 :
F_90 ( V_19 , V_21 ) ;
break;
case V_28 :
if ( V_21 -> V_29 == V_30 )
F_91 ( V_19 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_91 ,
( T_4 ) V_21 -> V_27 ) ;
F_28 ( V_19 ,
V_83 , 0 ) ;
break;
}
break;
case V_132 :
V_24 = F_44 ( V_19 , V_21 ) ;
break;
case V_72 :
V_24 = F_34 ( V_19 , V_21 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_92 ,
( T_4 ) V_21 -> V_25 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
break;
}
V_24 = V_19 -> V_9 & V_88 ;
return V_24 ;
}
static int F_92 ( struct V_18 * V_19 )
{
struct V_288 * V_289 = V_19 -> V_58 ;
const T_9 * V_290 ;
const T_9 * V_291 ;
V_290 = ( const T_9 * ) F_93 ( V_289 ,
L_93 ,
NULL ) ;
if ( ! V_290 ) {
F_79 ( L_94 ) ;
return - 1 ;
}
V_19 -> V_31 . V_143 [ V_147 ] . V_145 = F_62 ( * V_290 ) ;
V_290 ++ ;
V_291 = ( const T_9 * ) F_93 ( V_289 , L_95 ,
NULL ) ;
if ( ! V_291 ) {
F_33 ( L_96 ) ;
V_290 ++ ;
} else {
V_290 += F_62 ( * V_291 ) ;
}
V_291 = ( const T_9 * ) F_93 ( V_289 , L_97 ,
NULL ) ;
if ( ! V_291 ) {
F_33 ( L_98 ) ;
V_290 ++ ;
} else {
V_290 += F_62 ( * V_291 ) ;
}
V_19 -> V_31 . V_143 [ V_144 ] . V_145 = F_62 ( * V_290 ) ;
return 0 ;
}
static struct V_234 * F_94 ( const char * V_186 )
{
struct V_234 * V_137 = NULL ;
struct V_288 * V_289 ;
struct V_18 * V_19 ;
F_17 ( & V_292 ) ;
F_95 (vscsi, &ibmvscsis_dev_list, list) {
V_289 = V_19 -> V_58 ;
if ( ! strcmp ( F_67 ( & V_289 -> V_42 ) , V_186 ) ) {
V_137 = & V_19 -> V_137 ;
break;
}
}
F_16 ( & V_292 ) ;
return V_137 ;
}
static void F_96 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_272 * V_216 = (struct V_272 * ) V_118 -> V_148 -> V_293 ;
struct V_236 * V_237 ;
T_2 V_294 = 0 ;
enum V_295 V_296 ;
int V_297 = 0 ;
int V_24 = 0 ;
V_237 = V_19 -> V_137 . V_238 ;
if ( V_216 -> V_298 & 0x03 ) {
F_9 ( & V_19 -> V_42 , L_99 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
F_41 ( V_19 , V_116 ) ;
F_16 ( & V_19 -> V_62 ) ;
return;
}
if ( F_97 ( V_216 , & V_296 , & V_294 ) ) {
F_9 ( & V_19 -> V_42 , L_100 ,
V_216 -> V_198 ) ;
goto V_299;
}
V_116 -> V_3 . V_300 = V_216 -> V_300 ;
switch ( V_216 -> V_301 ) {
case V_302 :
V_297 = V_303 ;
break;
case V_304 :
V_297 = V_305 ;
break;
case V_306 :
V_297 = V_307 ;
break;
case V_308 :
V_297 = V_309 ;
break;
default:
F_9 ( & V_19 -> V_42 , L_101 ,
V_216 -> V_301 ) ;
goto V_299;
}
V_116 -> V_1 . V_198 = F_36 ( V_216 -> V_198 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_96 ) ;
F_16 ( & V_19 -> V_62 ) ;
V_216 -> V_310 . V_311 [ 0 ] &= 0x3f ;
V_24 = F_98 ( & V_116 -> V_1 , V_237 -> V_241 , V_216 -> V_312 ,
V_116 -> V_313 , F_99 ( & V_216 -> V_310 ) ,
V_294 , V_297 , V_296 , 0 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_102 , V_24 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_49 ( & V_116 -> V_124 ) ;
F_41 ( V_19 , V_116 ) ;
F_16 ( & V_19 -> V_62 ) ;
goto V_299;
}
return;
V_299:
F_17 ( & V_19 -> V_62 ) ;
F_28 ( V_19 , V_83 , 0 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static void F_100 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_273 * V_314 = & F_59 ( V_118 ) -> V_216 . V_277 ;
int V_315 ;
T_2 V_316 = 0 ;
int V_24 = 0 ;
struct V_236 * V_237 ;
V_237 = V_19 -> V_137 . V_238 ;
V_116 -> V_3 . V_300 = V_314 -> V_300 ;
switch ( V_314 -> V_317 ) {
case V_318 :
V_315 = V_319 ;
V_316 = F_36 ( V_314 -> V_320 ) ;
break;
case V_321 :
V_315 = V_322 ;
break;
case V_323 :
V_315 = V_324 ;
break;
case V_325 :
V_315 = V_326 ;
break;
case V_327 :
V_315 = V_328 ;
break;
default:
F_9 ( & V_19 -> V_42 , L_103 ,
V_314 -> V_317 ) ;
V_116 -> V_1 . V_329 -> V_330 =
V_331 ;
V_24 = - 1 ;
break;
}
if ( ! V_24 ) {
V_116 -> V_1 . V_198 = F_36 ( V_314 -> V_198 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_96 ) ;
F_16 ( & V_19 -> V_62 ) ;
V_314 -> V_310 . V_311 [ 0 ] &= 0x3f ;
F_6 ( L_104 ,
V_314 -> V_317 ) ;
V_24 = F_101 ( & V_116 -> V_1 , V_237 -> V_241 , NULL ,
F_99 ( & V_314 -> V_310 ) , V_314 ,
V_315 , V_239 , V_316 , 0 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_105 ,
V_24 ) ;
F_17 ( & V_19 -> V_62 ) ;
F_49 ( & V_116 -> V_124 ) ;
F_16 ( & V_19 -> V_62 ) ;
V_116 -> V_1 . V_329 -> V_330 =
V_332 ;
}
}
if ( V_24 )
F_102 ( & V_116 -> V_1 , 0 , 0 ) ;
}
static void F_103 ( struct V_76 * V_77 )
{
struct V_115 * V_116 = F_23 ( V_77 , struct V_115 ,
V_77 ) ;
struct V_18 * V_19 = V_116 -> V_333 ;
F_17 ( & V_19 -> V_62 ) ;
F_49 ( & V_116 -> V_124 ) ;
if ( V_19 -> V_9 & ( V_88 | V_89 ) ) {
F_41 ( V_19 , V_116 ) ;
if ( F_25 ( & V_19 -> V_96 ) &&
F_25 ( & V_19 -> V_97 ) &&
( V_19 -> V_9 & V_98 ) ) {
V_19 -> V_9 &= ~ V_98 ;
F_24 ( & V_19 -> V_79 ) ;
}
F_16 ( & V_19 -> V_62 ) ;
return;
}
F_16 ( & V_19 -> V_62 ) ;
switch ( V_116 -> type ) {
case V_120 :
F_96 ( V_19 , V_116 ) ;
break;
case V_119 :
F_100 ( V_19 , V_116 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_106 ,
V_116 -> type ) ;
F_17 ( & V_19 -> V_62 ) ;
F_41 ( V_19 , V_116 ) ;
F_16 ( & V_19 -> V_62 ) ;
break;
}
}
static int F_104 ( struct V_18 * V_19 , int V_334 )
{
struct V_115 * V_116 ;
int V_335 ;
F_105 ( & V_19 -> V_125 ) ;
V_19 -> V_336 = F_106 ( V_334 , sizeof( struct V_115 ) ,
V_239 ) ;
if ( ! V_19 -> V_336 )
return - V_240 ;
for ( V_335 = 0 , V_116 = (struct V_115 * ) V_19 -> V_336 ; V_335 < V_334 ;
V_335 ++ , V_116 ++ ) {
V_116 -> V_333 = V_19 ;
F_29 ( & V_116 -> V_77 , F_103 ) ;
F_42 ( & V_116 -> V_124 , & V_19 -> V_125 ) ;
}
return 0 ;
}
static void F_107 ( struct V_18 * V_19 )
{
F_83 ( V_19 -> V_336 ) ;
V_19 -> V_336 = NULL ;
F_105 ( & V_19 -> V_125 ) ;
}
static enum V_337 F_108 ( struct V_338 * V_208 )
{
struct V_339 * V_340 = F_23 ( V_208 , struct V_339 , V_208 ) ;
struct V_18 * V_19 = F_23 ( V_340 , struct V_18 ,
V_108 ) ;
F_17 ( & V_19 -> V_62 ) ;
V_340 -> V_109 += 1 ;
V_340 -> V_134 = false ;
F_72 ( V_19 ) ;
F_16 ( & V_19 -> V_62 ) ;
return V_341 ;
}
static long F_109 ( struct V_18 * V_19 )
{
struct V_339 * V_340 ;
V_340 = & V_19 -> V_108 ;
F_110 ( & V_340 -> V_208 , V_342 , V_209 ) ;
V_340 -> V_208 . V_343 = F_108 ;
V_340 -> V_134 = false ;
V_340 -> V_109 = 0 ;
return V_37 ;
}
static void F_111 ( struct V_18 * V_19 )
{
struct V_339 * V_340 ;
V_340 = & V_19 -> V_108 ;
( void ) F_112 ( & V_340 -> V_208 ) ;
V_340 -> V_134 = false ;
V_340 -> V_109 = 0 ;
}
static T_10 F_113 ( int V_344 , void * V_345 )
{
struct V_18 * V_19 = V_345 ;
F_15 ( V_19 -> V_58 ) ;
F_114 ( & V_19 -> V_346 ) ;
return V_347 ;
}
static long F_115 ( struct V_18 * V_19 )
{
int V_54 ;
long V_24 = V_37 ;
V_54 = V_19 -> V_63 . V_64 * V_65 ;
V_24 = F_40 ( V_19 -> V_31 . V_32 , V_19 -> V_63 . V_114 , V_54 ) ;
if ( V_24 == V_35 || V_24 == V_39 ) {
V_19 -> V_68 = V_92 ;
V_24 = F_37 ( V_19 ) ;
}
if ( V_24 != V_37 ) {
V_19 -> V_68 = V_85 ;
V_19 -> V_9 |= V_87 ;
}
return V_24 ;
}
static long F_116 ( struct V_18 * V_19 , int V_348 )
{
int V_349 ;
struct V_288 * V_289 = V_19 -> V_58 ;
V_349 = 1 ;
V_19 -> V_63 . V_64 = V_349 ;
V_19 -> V_63 . V_66 =
(struct V_20 * ) F_117 ( V_239 ) ;
if ( ! V_19 -> V_63 . V_66 )
return - V_240 ;
V_19 -> V_63 . V_69 = ( ( T_4 ) V_349 * V_350 ) - 1 ;
V_19 -> V_63 . V_114 = F_118 ( & V_289 -> V_42 ,
V_19 -> V_63 . V_66 ,
V_65 , V_351 ) ;
if ( F_119 ( & V_289 -> V_42 , V_19 -> V_63 . V_114 ) ) {
F_120 ( ( unsigned long ) V_19 -> V_63 . V_66 ) ;
return - V_240 ;
}
return 0 ;
}
static void F_121 ( struct V_18 * V_19 )
{
F_122 ( & V_19 -> V_58 -> V_42 , V_19 -> V_63 . V_114 ,
V_65 , V_351 ) ;
F_120 ( ( unsigned long ) V_19 -> V_63 . V_66 ) ;
V_19 -> V_63 . V_66 = NULL ;
V_19 -> V_68 = V_80 ;
}
static T_5 F_123 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_1 * V_1 = & V_116 -> V_1 ;
struct V_272 * V_216 = (struct V_272 * ) V_118 -> V_148 -> V_293 ;
struct V_352 V_353 ;
T_5 V_24 = V_1 -> V_354 ;
if ( V_19 -> V_202 && ( F_124 ( V_216 -> V_312 ) || F_125 ( V_216 -> V_312 ) ) )
if ( F_126 ( V_1 -> V_355 ,
V_1 -> V_356 , & V_353 ) )
if ( V_353 . V_357 == V_358 &&
( V_1 -> V_4 == 0 ||
V_1 -> V_4 == V_1 -> V_359 ) ) {
V_24 = V_360 ;
V_116 -> V_9 |= V_211 ;
}
return V_24 ;
}
static long F_127 ( struct V_18 * V_19 ,
struct V_115 * V_116 , T_4 * V_361 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_1 * V_1 = & V_116 -> V_1 ;
struct V_2 * V_3 ;
T_4 V_139 ;
T_1 V_362 ;
char * V_345 ;
T_1 * V_363 ;
long V_24 = V_37 ;
F_17 ( & V_19 -> V_62 ) ;
V_3 = & F_59 ( V_118 ) -> V_216 . V_3 ;
V_139 = sizeof( * V_3 ) ;
memset ( V_3 , 0 , V_139 ) ;
V_345 = V_3 -> V_345 ;
V_3 -> V_220 = V_364 ;
if ( V_19 -> V_111 > 0 && V_19 -> V_68 == V_94 )
V_3 -> V_222 = F_2 ( V_19 -> V_111 ) ;
else
V_3 -> V_222 = F_2 ( 1 + V_19 -> V_111 ) ;
V_3 -> V_198 = V_116 -> V_3 . V_198 ;
V_3 -> V_9 = 0 ;
if ( V_116 -> type == V_120 ) {
V_3 -> V_29 = F_123 ( V_19 , V_116 ) ;
if ( V_3 -> V_29 ) {
F_6 ( L_107 , V_116 ,
( int ) V_3 -> V_29 ) ;
F_1 ( V_1 , V_3 ) ;
if ( V_1 -> V_356 && V_1 -> V_355 ) {
V_3 -> V_365 =
F_2 ( V_1 -> V_356 ) ;
V_3 -> V_9 |= V_366 ;
V_139 += V_1 -> V_356 ;
memcpy ( V_345 , V_1 -> V_355 ,
V_1 -> V_356 ) ;
}
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_367 ) >>
V_368 ;
} else if ( V_116 -> V_9 & V_211 ) {
F_6 ( L_108 , V_116 ) ;
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_367 ) >>
V_368 ;
} else {
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_369 ) >>
V_370 ;
}
} else {
V_3 -> V_29 = 0 ;
V_3 -> V_371 = F_2 ( 4 ) ;
V_3 -> V_9 |= V_372 ;
switch ( V_1 -> V_329 -> V_330 ) {
case V_373 :
case V_374 :
V_362 = V_375 ;
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_369 ) >>
V_370 ;
break;
case V_331 :
case V_376 :
V_362 = V_377 ;
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_367 ) >>
V_368 ;
break;
case V_378 :
case V_332 :
default:
V_362 = V_379 ;
V_3 -> V_300 = ( V_116 -> V_3 . V_300 & V_367 ) >>
V_368 ;
break;
}
V_363 = ( T_1 * ) V_345 ;
* V_363 = F_2 ( V_362 ) ;
V_345 = ( char * ) ( V_363 + 1 ) ;
V_139 += 4 ;
}
F_63 () ;
V_24 = F_56 ( V_139 , V_19 -> V_31 . V_143 [ V_147 ] . V_145 , V_118 -> V_148 -> V_149 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
F_36 ( V_118 -> V_151 ) ) ;
switch ( V_24 ) {
case V_39 :
V_19 -> V_111 = 0 ;
* V_361 = V_139 ;
break;
case V_153 :
if ( F_3 ( V_19 ) )
V_19 -> V_9 |= V_87 | V_112 ;
F_9 ( & V_19 -> V_42 , L_109 ,
V_24 , V_19 -> V_9 , V_19 -> V_68 ) ;
break;
case V_155 :
case V_154 :
default:
F_9 ( & V_19 -> V_42 , L_110 ,
V_24 ) ;
break;
}
F_16 ( & V_19 -> V_62 ) ;
return V_24 ;
}
static int F_128 ( struct V_115 * V_116 , struct V_380 * V_381 ,
int V_382 , struct V_383 * V_384 , int V_385 ,
enum V_295 V_296 , unsigned int V_54 )
{
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_386 * V_135 = V_118 -> V_135 ;
struct V_18 * V_19 = V_135 -> V_387 ;
struct V_380 * V_388 ;
T_6 V_389 , V_390 ;
T_11 V_391 ;
T_11 V_392 , V_393 ;
int V_394 ;
long V_395 ;
long V_24 = 0 ;
if ( V_54 == 0 )
return 0 ;
V_388 = V_381 ;
V_392 = 0 ;
V_393 = 0 ;
V_394 = 0 ;
V_395 = V_54 ;
do {
if ( V_392 == 0 ) {
if ( V_394 >= V_385 ) {
F_9 ( & V_19 -> V_42 , L_111 ) ;
V_24 = - V_396 ;
break;
}
V_389 = F_36 ( V_384 [ V_394 ] . V_397 ) ;
V_392 = F_62 ( V_384 [ V_394 ] . V_139 ) ;
}
if ( V_393 == 0 ) {
if ( ! V_388 ) {
F_9 ( & V_19 -> V_42 , L_112 ) ;
V_24 = - V_396 ;
break;
}
V_390 = F_129 ( V_388 ) ;
V_393 = F_130 ( V_388 ) ;
}
V_391 = V_395 ;
if ( V_391 > V_392 )
V_391 = V_392 ;
if ( V_391 > V_393 )
V_391 = V_393 ;
if ( V_391 > V_398 )
V_391 = V_398 ;
if ( V_296 == V_8 ) {
V_24 = F_56 ( V_391 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
V_389 ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_390 ) ;
} else {
F_53 () ;
F_63 () ;
V_24 = F_56 ( V_391 ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_390 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ,
V_389 ) ;
}
switch ( V_24 ) {
case V_39 :
break;
case V_153 :
case V_155 :
case V_154 :
if ( F_3 ( V_19 ) ) {
F_17 ( & V_19 -> V_62 ) ;
V_19 -> V_9 |=
( V_87 | V_112 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
F_9 ( & V_19 -> V_42 , L_113 ,
V_24 ) ;
break;
default:
F_9 ( & V_19 -> V_42 , L_114 ,
V_24 ) ;
break;
}
if ( ! V_24 ) {
V_395 -= V_391 ;
if ( V_395 ) {
V_392 -= V_391 ;
if ( V_392 == 0 )
V_394 ++ ;
else
V_389 += V_391 ;
V_393 -= V_391 ;
if ( V_393 == 0 )
V_388 = F_131 ( V_388 ) ;
else
V_390 += V_391 ;
} else {
break;
}
}
} while ( ! V_24 );
return V_24 ;
}
static void F_132 ( unsigned long V_345 )
{
struct V_18 * V_19 = (struct V_18 * ) V_345 ;
struct V_20 * V_21 ;
long V_24 ;
bool V_130 = true ;
volatile T_5 V_25 ;
F_17 ( & V_19 -> V_62 ) ;
F_6 ( L_115 ) ;
if ( F_133 ( V_19 ) ) {
F_38 ( V_19 -> V_58 ) ;
F_6 ( L_116 ,
V_19 -> V_9 , V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
return;
}
V_24 = V_19 -> V_9 & V_88 ;
V_21 = V_19 -> V_63 . V_66 + V_19 -> V_63 . V_67 ;
V_25 = V_21 -> V_25 ;
F_19 () ;
while ( V_25 ) {
V_399:
V_19 -> V_63 . V_67 =
( V_19 -> V_63 . V_67 + 1 ) & V_19 -> V_63 . V_69 ;
if ( ! V_24 ) {
V_24 = F_46 ( V_19 , V_21 ) ;
} else {
if ( ( T_4 ) V_21 -> V_25 == V_132 ) {
V_24 = F_44 ( V_19 , V_21 ) ;
} else if ( V_19 -> V_9 & V_113 ) {
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
if ( V_130 ) {
F_38 ( V_19 -> V_58 ) ;
V_130 = false ;
F_6 ( L_117 ) ;
}
V_25 = V_21 -> V_25 ;
F_19 () ;
if ( V_25 )
goto V_399;
} else {
F_6 ( L_118 ,
V_19 -> V_9 , V_19 -> V_68 , V_19 -> V_63 . V_67 ) ;
}
F_6 ( L_119 ,
( int ) F_25 ( & V_19 -> V_97 ) , V_19 -> V_9 ,
V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static int F_134 ( struct V_288 * V_289 ,
const struct V_400 * V_401 )
{
struct V_18 * V_19 ;
int V_24 = 0 ;
long V_402 = 0 ;
char V_403 [ 24 ] ;
V_19 = F_78 ( sizeof( * V_19 ) , V_239 ) ;
if ( ! V_19 ) {
V_24 = - V_240 ;
F_79 ( L_120 ) ;
return V_24 ;
}
V_19 -> V_58 = V_289 ;
V_19 -> V_42 = V_289 -> V_42 ;
F_105 ( & V_19 -> V_97 ) ;
F_105 ( & V_19 -> V_126 ) ;
F_105 ( & V_19 -> V_96 ) ;
snprintf ( V_19 -> V_137 . V_235 , V_404 , L_121 ,
F_67 ( & V_289 -> V_42 ) ) ;
F_6 ( L_122 , V_19 -> V_137 . V_235 ) ;
V_24 = F_92 ( V_19 ) ;
if ( V_24 )
goto V_405;
F_6 ( L_123 ,
V_19 -> V_31 . V_143 [ V_147 ] . V_145 ,
V_19 -> V_31 . V_143 [ V_144 ] . V_145 ) ;
strcpy ( V_19 -> V_406 , L_124 ) ;
strncat ( V_19 -> V_406 , V_289 -> V_186 , V_407 ) ;
V_19 -> V_31 . V_32 = V_289 -> V_213 ;
strncpy ( V_19 -> V_31 . V_169 , V_169 ,
sizeof( V_19 -> V_31 . V_169 ) ) ;
V_19 -> V_31 . V_172 = V_105 ;
F_17 ( & V_292 ) ;
F_42 ( & V_19 -> V_124 , & V_408 ) ;
F_16 ( & V_292 ) ;
V_19 -> V_223 = V_409 ;
V_24 = F_135 ( & V_19 -> V_135 , & V_289 -> V_42 , V_19 -> V_223 ,
V_141 ) ;
if ( V_24 )
goto V_410;
V_19 -> V_135 . V_387 = V_19 ;
V_24 = F_104 ( V_19 , V_19 -> V_223 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_125 ,
V_24 , V_19 -> V_223 ) ;
goto V_411;
}
F_136 ( & V_19 -> V_62 ) ;
V_24 = F_109 ( V_19 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_126 , V_24 ) ;
goto V_412;
}
V_24 = F_116 ( V_19 , 256 ) ;
if ( V_24 ) {
F_9 ( & V_19 -> V_42 , L_127 ,
V_24 ) ;
goto V_413;
}
V_19 -> V_106 = F_78 ( V_65 , V_239 ) ;
if ( ! V_19 -> V_106 ) {
V_24 = - V_240 ;
F_9 ( & V_19 -> V_42 , L_128 ) ;
goto V_414;
}
V_19 -> V_104 = F_118 ( & V_289 -> V_42 , V_19 -> V_106 , V_65 ,
V_351 ) ;
if ( F_119 ( & V_289 -> V_42 , V_19 -> V_104 ) ) {
V_24 = - V_240 ;
F_9 ( & V_19 -> V_42 , L_129 ) ;
goto V_415;
}
V_402 = F_35 ( V_19 -> V_31 . V_32 , V_103 ,
( T_2 ) V_19 -> V_104 | ( ( T_2 ) V_65 << 32 ) , 0 , 0 , 0 ,
0 ) ;
if ( V_402 == V_39 )
V_19 -> V_52 . V_105 =
F_36 ( * ( T_2 * ) V_19 -> V_106 ) ;
F_6 ( L_130 ,
V_402 , V_19 -> V_52 . V_105 ) ;
F_137 ( & V_19 -> V_346 , F_132 ,
( unsigned long ) V_19 ) ;
F_138 ( & V_19 -> V_79 ) ;
F_138 ( & V_19 -> V_91 ) ;
snprintf ( V_403 , 24 , L_131 , F_67 ( & V_289 -> V_42 ) ) ;
V_19 -> V_100 = F_139 ( V_403 ) ;
if ( ! V_19 -> V_100 ) {
V_24 = - V_240 ;
F_9 ( & V_19 -> V_42 , L_132 ) ;
goto V_416;
}
V_24 = F_140 ( V_289 -> V_417 , F_113 , 0 , L_133 , V_19 ) ;
if ( V_24 ) {
V_24 = - V_418 ;
F_9 ( & V_19 -> V_42 , L_134 , V_24 ) ;
goto V_419;
}
V_19 -> V_68 = V_86 ;
F_141 ( & V_289 -> V_42 , V_19 ) ;
return 0 ;
V_419:
F_142 ( V_19 -> V_100 ) ;
V_416:
F_122 ( & V_289 -> V_42 , V_19 -> V_104 , V_65 ,
V_351 ) ;
V_415:
F_83 ( V_19 -> V_106 ) ;
V_414:
F_143 ( & V_19 -> V_346 ) ;
F_7 ( V_19 ) ;
F_121 ( V_19 ) ;
V_413:
F_111 ( V_19 ) ;
V_412:
F_107 ( V_19 ) ;
V_411:
F_144 ( & V_19 -> V_135 ) ;
V_410:
F_17 ( & V_292 ) ;
F_49 ( & V_19 -> V_124 ) ;
F_16 ( & V_292 ) ;
V_405:
F_83 ( V_19 ) ;
return V_24 ;
}
static int F_145 ( struct V_288 * V_289 )
{
struct V_18 * V_19 = F_146 ( & V_289 -> V_42 ) ;
F_6 ( L_135 , F_67 ( & V_19 -> V_58 -> V_42 ) ) ;
F_17 ( & V_19 -> V_62 ) ;
F_28 ( V_19 , V_81 , 0 ) ;
V_19 -> V_9 |= V_90 ;
F_16 ( & V_19 -> V_62 ) ;
F_26 ( & V_19 -> V_91 ) ;
F_15 ( V_289 ) ;
F_147 ( V_289 -> V_417 , V_19 ) ;
F_142 ( V_19 -> V_100 ) ;
F_122 ( & V_289 -> V_42 , V_19 -> V_104 , V_65 ,
V_351 ) ;
F_83 ( V_19 -> V_106 ) ;
F_143 ( & V_19 -> V_346 ) ;
F_121 ( V_19 ) ;
F_111 ( V_19 ) ;
F_107 ( V_19 ) ;
F_144 ( & V_19 -> V_135 ) ;
F_17 ( & V_292 ) ;
F_49 ( & V_19 -> V_124 ) ;
F_16 ( & V_292 ) ;
F_83 ( V_19 ) ;
return 0 ;
}
static T_12 F_148 ( struct V_420 * V_42 ,
struct V_421 * V_297 , char * V_293 )
{
return snprintf ( V_293 , V_65 , L_136 , V_422 ) ;
}
static T_12 F_149 ( struct V_420 * V_42 ,
struct V_421 * V_297 , char * V_293 )
{
return snprintf ( V_293 , V_65 , L_137 , V_105 ) ;
}
static T_12 F_150 ( struct V_420 * V_42 ,
struct V_421 * V_297 , char * V_293 )
{
struct V_18 * V_19 = F_23 ( V_42 , struct V_18 , V_42 ) ;
return snprintf ( V_293 , V_65 , L_137 , V_19 -> V_58 -> V_213 ) ;
}
static int F_151 ( void )
{
struct V_423 * V_424 , * V_425 ;
const char * V_401 , * V_426 , * V_186 ;
const T_4 * V_334 ;
V_424 = F_152 ( L_138 ) ;
if ( ! V_424 )
return - V_427 ;
V_426 = F_153 ( V_424 , L_139 , NULL ) ;
V_401 = F_153 ( V_424 , L_140 , NULL ) ;
if ( V_426 && V_401 )
snprintf ( V_422 , sizeof( V_422 ) , L_141 , V_426 , V_401 ) ;
V_186 = F_153 ( V_424 , L_142 , NULL ) ;
if ( V_186 )
strncpy ( V_169 , V_186 , sizeof( V_169 ) ) ;
V_334 = F_153 ( V_424 , L_143 , NULL ) ;
if ( V_334 )
V_105 = F_154 ( V_334 , 1 ) ;
F_155 ( V_424 ) ;
V_425 = F_152 ( L_144 ) ;
if ( V_425 ) {
const T_4 * V_428 ;
V_428 = F_153 ( V_425 , L_145 ,
NULL ) ;
if ( V_428 )
V_398 = * V_428 ;
F_155 ( V_425 ) ;
}
return 0 ;
}
static char * F_156 ( void )
{
return L_133 ;
}
static char * F_157 ( struct V_429 * V_242 )
{
struct V_234 * V_137 =
F_23 ( V_242 , struct V_234 , V_242 ) ;
return V_137 -> V_235 ;
}
static T_3 F_158 ( struct V_429 * V_242 )
{
struct V_234 * V_137 =
F_23 ( V_242 , struct V_234 , V_242 ) ;
return V_137 -> V_430 ;
}
static T_1 F_159 ( struct V_429 * V_242 )
{
return 1 ;
}
static int F_160 ( struct V_429 * V_242 )
{
return 1 ;
}
static int F_161 ( struct V_429 * V_242 )
{
return 0 ;
}
static T_1 F_162 ( struct V_429 * V_242 )
{
return 1 ;
}
static int F_163 ( struct V_1 * V_1 )
{
return F_164 ( V_1 ) ;
}
static void F_165 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = F_23 ( V_1 , struct V_115 ,
V_1 ) ;
struct V_18 * V_19 = V_116 -> V_333 ;
F_17 ( & V_19 -> V_62 ) ;
F_166 ( & V_116 -> V_124 , & V_19 -> V_126 ) ;
F_72 ( V_19 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
static T_1 F_167 ( struct V_245 * V_241 )
{
return 0 ;
}
static int F_168 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = F_23 ( V_1 , struct V_115 ,
V_1 ) ;
struct V_117 * V_118 = V_116 -> V_118 ;
int V_24 ;
V_24 = F_169 ( V_116 , & F_59 ( V_118 ) -> V_216 . V_116 , F_128 ,
1 , 1 ) ;
if ( V_24 ) {
F_79 ( L_146 , V_24 ) ;
return - V_396 ;
}
F_170 ( V_1 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_172 ( struct V_431 * V_432 )
{
}
static int F_173 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_174 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = F_23 ( V_1 , struct V_115 ,
V_1 ) ;
struct V_117 * V_118 = V_116 -> V_118 ;
struct V_18 * V_19 = V_116 -> V_333 ;
char * V_433 ;
T_4 V_139 = 0 ;
int V_24 ;
V_24 = F_169 ( V_116 , & F_59 ( V_118 ) -> V_216 . V_116 , F_128 , 1 ,
1 ) ;
if ( V_24 ) {
F_79 ( L_147 , V_24 ) ;
V_433 = V_1 -> V_355 ;
V_1 -> V_356 = 18 ;
memset ( V_1 -> V_355 , 0 , V_1 -> V_356 ) ;
F_175 ( 0 , V_1 -> V_355 , V_434 ,
0x08 , 0x01 ) ;
}
F_127 ( V_19 , V_116 , & V_139 ) ;
V_116 -> V_3 . V_27 = V_271 ;
V_116 -> V_3 . V_139 = V_139 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = F_23 ( V_1 , struct V_115 ,
V_1 ) ;
struct V_18 * V_19 = V_116 -> V_333 ;
T_4 V_139 ;
F_6 ( L_148 , V_1 ) ;
F_127 ( V_19 , V_116 , & V_139 ) ;
V_116 -> V_3 . V_27 = V_271 ;
V_116 -> V_3 . V_139 = V_139 ;
return 0 ;
}
static void F_177 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = F_23 ( V_1 , struct V_115 ,
V_1 ) ;
struct V_18 * V_19 = V_116 -> V_333 ;
T_4 V_139 ;
F_6 ( L_149 ,
V_1 , ( int ) V_1 -> V_329 -> V_330 ) ;
F_127 ( V_19 , V_116 , & V_139 ) ;
V_116 -> V_3 . V_27 = V_271 ;
V_116 -> V_3 . V_139 = V_139 ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_6 ( L_150 , V_1 ) ;
}
static struct V_435 * F_179 ( struct V_436 * V_437 ,
struct V_438 * V_439 ,
const char * V_186 )
{
struct V_234 * V_137 ;
V_137 = F_94 ( V_186 ) ;
if ( V_137 ) {
V_137 -> V_440 = V_441 ;
F_6 ( L_151 ,
V_186 , V_137 , V_137 -> V_440 ) ;
return & V_137 -> V_442 ;
}
return F_180 ( - V_443 ) ;
}
static void F_181 ( struct V_435 * V_444 )
{
struct V_234 * V_137 = F_23 ( V_444 ,
struct V_234 ,
V_442 ) ;
F_6 ( L_152 ,
F_182 ( & V_137 -> V_442 . V_445 . V_446 ) ) ;
}
static struct V_429 * F_183 ( struct V_435 * V_444 ,
struct V_438 * V_439 ,
const char * V_186 )
{
struct V_234 * V_137 =
F_23 ( V_444 , struct V_234 , V_442 ) ;
int V_24 ;
V_137 -> V_447 = false ;
V_24 = F_184 ( & V_137 -> V_442 , & V_137 -> V_242 ,
V_137 -> V_440 ) ;
if ( V_24 )
return F_180 ( V_24 ) ;
return & V_137 -> V_242 ;
}
static void F_185 ( struct V_429 * V_242 )
{
struct V_234 * V_137 = F_23 ( V_242 ,
struct V_234 ,
V_242 ) ;
V_137 -> V_447 = true ;
V_137 -> V_138 = false ;
F_84 ( V_137 ) ;
F_186 ( V_242 ) ;
}
static T_12 F_187 ( struct V_448 * V_449 ,
char * V_450 )
{
return F_188 ( V_450 , V_65 , L_136 , V_451 ) ;
}
static T_12 F_189 ( struct V_448 * V_449 ,
char * V_450 )
{
struct V_429 * V_242 = F_190 ( V_449 ) ;
struct V_234 * V_137 = F_23 ( V_242 ,
struct V_234 ,
V_242 ) ;
return snprintf ( V_450 , V_65 , L_153 , ( V_137 -> V_138 ) ? 1 : 0 ) ;
}
static T_12 F_191 ( struct V_448 * V_449 ,
const char * V_450 , T_13 V_452 )
{
struct V_429 * V_242 = F_190 ( V_449 ) ;
struct V_234 * V_137 = F_23 ( V_242 ,
struct V_234 ,
V_242 ) ;
struct V_18 * V_19 = F_23 ( V_137 , struct V_18 , V_137 ) ;
unsigned long V_453 ;
int V_24 ;
long V_454 ;
V_24 = F_192 ( V_450 , 0 , & V_453 ) ;
if ( V_24 < 0 ) {
F_79 ( L_154 ) ;
return - V_443 ;
}
if ( ( V_453 != 0 ) && ( V_453 != 1 ) ) {
F_79 ( L_155 ) ;
return - V_443 ;
}
if ( V_453 ) {
F_17 ( & V_19 -> V_62 ) ;
V_137 -> V_138 = true ;
V_454 = F_115 ( V_19 ) ;
if ( V_454 )
F_79 ( L_156 ,
V_454 , V_19 -> V_68 ) ;
F_16 ( & V_19 -> V_62 ) ;
} else {
F_17 ( & V_19 -> V_62 ) ;
V_137 -> V_138 = false ;
F_28 ( V_19 , V_82 , 0 ) ;
F_16 ( & V_19 -> V_62 ) ;
}
F_6 ( L_157 , V_453 , V_19 -> V_68 ) ;
return V_452 ;
}
static void F_193 ( struct V_420 * V_42 ) {}
static int T_14 F_194 ( void )
{
int V_24 = 0 ;
V_24 = F_151 () ;
if ( V_24 ) {
F_79 ( L_158 , V_24 ) ;
goto V_455;
}
V_24 = F_195 ( & V_456 ) ;
if ( V_24 ) {
F_79 ( L_159 ) ;
goto V_455;
}
V_24 = F_196 ( & V_457 ) ;
if ( V_24 ) {
F_79 ( L_160 , V_24 ) ;
goto V_458;
}
V_24 = F_197 ( & V_459 ) ;
if ( V_24 ) {
F_79 ( L_161 , V_24 ) ;
goto V_460;
}
return 0 ;
V_460:
F_198 ( & V_457 ) ;
V_458:
F_199 ( & V_456 ) ;
V_455:
return V_24 ;
}
static void T_15 F_200 ( void )
{
F_201 ( L_162 ) ;
F_202 ( & V_459 ) ;
F_198 ( & V_457 ) ;
F_199 ( & V_456 ) ;
}
