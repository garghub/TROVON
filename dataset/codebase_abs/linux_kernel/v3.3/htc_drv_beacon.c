void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 , V_7 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( struct V_5 ) ) ;
F_2 ( V_4 , V_2 -> V_8 , & V_6 ) ;
if ( V_2 -> V_4 -> V_9 == V_10 ) {
V_6 . V_11 = 1 ;
V_6 . V_12 = 0 ;
V_6 . V_13 = 0 ;
} else if ( V_2 -> V_4 -> V_9 == V_14 ) {
int V_15 = V_2 -> V_16 [ V_17 ] ;
F_2 ( V_4 , V_15 , & V_7 ) ;
V_6 . V_11 = V_7 . V_11 ;
if ( V_4 -> V_18 == V_19 )
V_6 . V_12 = 2 * V_7 . V_12 ;
else
V_6 . V_12 = 4 * V_7 . V_12 ;
V_6 . V_13 = V_7 . V_13 ;
}
if ( ! F_3 ( V_4 , V_2 -> V_8 , & V_6 ) ) {
F_4 ( F_5 ( V_4 ) ,
L_1 , V_2 -> V_8 ) ;
} else {
F_6 ( V_4 , V_2 -> V_8 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_24 V_25 ;
enum V_26 V_27 = 0 ;
int V_28 , V_29 , V_30 ;
int V_31 , V_32 , V_33 ;
T_1 V_34 = 0 , V_35 , V_36 ;
T_2 V_37 = 0 ;
T_3 V_38 ;
int V_39 , V_40 , V_41 , V_42 ;
int T_4 V_43 ( ( V_44 ) ) ;
T_5 V_45 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_35 = V_21 -> V_46 ;
V_33 = ( V_47 * V_21 -> V_46 ) ;
V_28 = V_21 -> V_48 ;
if ( V_28 <= 0 )
V_28 = 1 ;
V_29 = 1 ;
if ( V_29 >= V_28 )
V_29 = 0 ;
V_31 = 1 ;
V_32 = 0 ;
V_30 = V_35 ;
if ( V_30 <= 0 )
V_30 = V_35 ;
V_38 = F_8 ( V_2 -> V_4 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_49 ;
V_39 = V_36 / V_35 + 1 ;
V_40 = V_36 % V_35 ;
V_34 = V_36 - V_40 ;
if ( V_40 )
V_34 += V_35 ;
V_41 = V_39 % V_28 ;
V_42 = ( V_39 / V_28 ) % V_31 ;
if ( V_41 )
V_42 ++ ;
V_29 -= V_41 ;
if ( V_29 < 0 )
V_29 += V_28 ;
V_32 -= V_42 ;
if ( V_32 < 0 )
V_32 += V_31 ;
V_25 . V_50 = V_35 ;
V_25 . V_51 = V_34 ;
V_25 . V_52 = V_28 * V_35 ;
V_25 . V_53 = V_25 . V_51 + V_29 * V_35 ;
V_25 . V_54 = V_31 * V_25 . V_52 ;
V_25 . V_55 = V_25 . V_53 + V_32 * V_25 . V_52 ;
V_25 . V_56 = 0 ;
if ( V_30 > V_35 ) {
V_25 . V_57 = V_47 / 2 ;
} else {
V_25 . V_57 = F_10 ( V_33 , V_35 ) ;
if ( V_25 . V_57 > 15 )
V_25 . V_57 = 15 ;
else if ( V_25 . V_57 <= 0 )
V_25 . V_57 = 1 ;
}
V_25 . V_58 = F_11 ( F_12 ( 100 ) , V_30 ) ;
if ( V_25 . V_58 > V_25 . V_52 )
V_25 . V_58 = V_25 . V_52 ;
V_25 . V_59 = V_60 ;
F_13 ( V_23 , V_61 , L_2 ,
V_35 , V_38 , V_36 ) ;
F_13 ( V_23 , V_61 ,
L_3 ,
V_25 . V_57 , V_25 . V_58 ,
V_25 . V_54 , V_25 . V_56 , V_25 . V_55 ) ;
F_14 ( V_62 ) ;
F_15 ( V_2 -> V_4 , & V_25 ) ;
V_27 |= V_63 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_64 , & V_37 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
enum V_26 V_27 = 0 ;
T_1 V_34 , V_35 , V_36 ;
T_2 V_37 = 0 ;
int T_4 V_43 ( ( V_44 ) ) ;
T_5 V_45 ;
T_3 V_38 ;
V_35 = V_21 -> V_46 ;
V_35 /= V_65 ;
V_34 = V_35 ;
if ( V_35 > V_66 )
V_2 -> V_4 -> V_67 . V_68 = V_66 ;
else
V_2 -> V_4 -> V_67 . V_68 = V_69 ;
if ( V_2 -> V_70 & V_71 ) {
F_19 ( V_2 -> V_4 ) ;
V_2 -> V_70 &= ~ V_71 ;
} else {
V_38 = F_8 ( V_2 -> V_4 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_49 ;
do {
V_34 += V_35 ;
} while ( V_34 < V_36 );
}
if ( V_2 -> V_70 & V_72 )
V_27 |= V_73 ;
F_13 ( V_23 , V_61 ,
L_4 ,
V_21 -> V_46 , V_34 ,
V_2 -> V_4 -> V_67 . V_68 , V_27 ) ;
F_1 ( V_2 ) ;
F_14 ( V_62 ) ;
F_20 ( V_2 -> V_4 , F_21 ( V_34 ) , F_21 ( V_35 ) ) ;
V_2 -> V_74 . V_75 = 0 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_64 , & V_37 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
enum V_26 V_27 = 0 ;
T_1 V_34 , V_35 , V_36 ;
T_2 V_37 = 0 ;
int T_4 V_43 ( ( V_44 ) ) ;
T_5 V_45 ;
T_3 V_38 ;
V_35 = V_21 -> V_46 ;
V_34 = V_35 ;
V_38 = F_8 ( V_2 -> V_4 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_49 ;
do {
V_34 += V_35 ;
} while ( V_34 < V_36 );
if ( V_35 > V_66 )
V_2 -> V_4 -> V_67 . V_68 = V_66 ;
else
V_2 -> V_4 -> V_67 . V_68 = V_69 ;
if ( V_2 -> V_70 & V_72 )
V_27 |= V_73 ;
F_13 ( V_23 , V_61 ,
L_5 ,
V_21 -> V_46 , V_34 ,
V_2 -> V_4 -> V_67 . V_68 , V_27 ) ;
F_14 ( V_62 ) ;
F_20 ( V_2 -> V_4 , F_21 ( V_34 ) , F_21 ( V_35 ) ) ;
V_2 -> V_74 . V_75 = 0 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_64 , & V_37 ) ;
}
void F_23 ( void * V_76 , struct V_77 * V_78 ,
enum V_79 V_80 , bool V_81 )
{
F_24 ( V_78 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
int V_82 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_83 * V_84 ;
struct V_77 * V_78 ;
struct V_85 * V_86 ;
int V_87 , V_88 , T_4 , V_89 ;
F_26 ( & V_2 -> V_90 ) ;
V_84 = V_2 -> V_74 . V_91 [ V_82 ] ;
V_78 = F_27 ( V_2 -> V_92 , V_84 ) ;
while( V_78 ) {
V_86 = (struct V_85 * ) V_78 -> V_93 ;
V_87 = F_28 ( V_86 -> V_94 ) ;
V_88 = V_87 & 3 ;
if ( V_88 && V_78 -> V_95 > V_87 ) {
if ( F_29 ( V_78 ) < V_88 ) {
F_24 ( V_78 ) ;
goto V_96;
}
F_30 ( V_78 , V_88 ) ;
memmove ( V_78 -> V_93 , V_78 -> V_93 + V_88 , V_87 ) ;
}
V_89 = F_31 ( V_2 ) ;
if ( V_89 < 0 ) {
F_13 ( V_23 , V_97 , L_6 ) ;
F_24 ( V_78 ) ;
goto V_96;
}
T_4 = F_32 ( V_2 , V_78 , V_89 , true ) ;
if ( T_4 != 0 ) {
F_33 ( V_2 , V_89 ) ;
F_24 ( V_78 ) ;
F_13 ( V_23 , V_97 , L_7 ) ;
} else {
F_26 ( & V_2 -> V_98 . V_99 ) ;
V_2 -> V_98 . V_100 ++ ;
F_34 ( & V_2 -> V_98 . V_99 ) ;
}
V_96:
V_78 = F_27 ( V_2 -> V_92 , V_84 ) ;
}
F_34 ( & V_2 -> V_90 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
int V_82 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_83 * V_84 ;
struct V_101 * V_102 ;
struct V_103 V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_77 * V_111 ;
T_5 * V_112 ;
int T_4 ;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
F_26 ( & V_2 -> V_90 ) ;
V_84 = V_2 -> V_74 . V_91 [ V_82 ] ;
V_102 = (struct V_101 * ) V_84 -> V_76 ;
if ( F_36 ( V_2 -> V_70 & V_113 ) ) {
F_34 ( & V_2 -> V_90 ) ;
return;
}
V_111 = F_37 ( V_2 -> V_92 , V_84 ) ;
if ( ! V_111 ) {
F_34 ( & V_2 -> V_90 ) ;
return;
}
V_110 = (struct V_109 * ) V_111 -> V_93 ;
V_110 -> V_114 . V_111 . V_115 = V_102 -> V_116 ;
V_108 = F_38 ( V_111 ) ;
if ( V_108 -> V_117 & V_118 ) {
struct V_85 * V_86 =
(struct V_85 * ) V_111 -> V_93 ;
V_102 -> V_119 += 0x10 ;
V_86 -> V_120 &= F_39 ( V_121 ) ;
V_86 -> V_120 |= F_39 ( V_102 -> V_119 ) ;
}
V_106 = F_40 ( V_111 ) ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> type = V_122 ;
V_106 -> V_123 = V_2 -> V_124 ;
V_104 . V_125 = V_102 -> V_126 ;
V_112 = F_30 ( V_111 , sizeof( V_104 ) ) ;
memcpy ( V_112 , ( T_5 * ) & V_104 , sizeof( V_104 ) ) ;
T_4 = F_41 ( V_2 -> V_127 , V_111 ) ;
if ( T_4 != 0 ) {
if ( T_4 == - V_128 ) {
F_13 ( V_23 , V_129 ,
L_8 ) ;
}
F_24 ( V_111 ) ;
}
F_34 ( & V_2 -> V_90 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
T_3 V_38 ;
T_1 V_36 ;
T_6 V_35 ;
int V_82 ;
V_35 = V_2 -> V_74 . V_46 ;
V_38 = F_43 ( V_131 -> V_38 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) ;
V_82 = ( ( V_36 % V_35 ) * V_65 ) / V_35 ;
V_82 = V_65 - V_82 - 1 ;
F_13 ( V_23 , V_132 ,
L_9 ,
V_82 , V_38 , V_36 , V_35 ) ;
return V_82 ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
int V_82 ;
if ( V_131 -> V_133 != 0 ) {
V_2 -> V_74 . V_75 ++ ;
if ( V_2 -> V_74 . V_75 > V_134 ) {
F_13 ( V_23 , V_129 , L_10 ) ;
F_45 ( V_2 -> V_92 ,
& V_2 -> V_135 ) ;
}
return;
}
if ( V_2 -> V_74 . V_75 ) {
F_13 ( V_23 , V_129 ,
L_11 ,
V_2 -> V_74 . V_75 ) ;
V_2 -> V_74 . V_75 = 0 ;
}
V_82 = F_42 ( V_2 , V_131 ) ;
F_26 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_74 . V_91 [ V_82 ] == NULL ) {
F_34 ( & V_2 -> V_90 ) ;
return;
}
F_34 ( & V_2 -> V_90 ) ;
F_25 ( V_2 , V_82 ) ;
F_35 ( V_2 , V_82 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_101 * V_102 = (struct V_101 * ) V_84 -> V_76 ;
int V_136 = 0 ;
F_26 ( & V_2 -> V_90 ) ;
for ( V_136 = 0 ; V_136 < V_65 ; V_136 ++ ) {
if ( V_2 -> V_74 . V_91 [ V_136 ] == NULL ) {
V_102 -> V_91 = V_136 ;
break;
}
}
V_2 -> V_74 . V_91 [ V_102 -> V_91 ] = V_84 ;
F_34 ( & V_2 -> V_90 ) ;
F_13 ( V_23 , V_61 , L_12 ,
V_102 -> V_91 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_101 * V_102 = (struct V_101 * ) V_84 -> V_76 ;
F_26 ( & V_2 -> V_90 ) ;
V_2 -> V_74 . V_91 [ V_102 -> V_91 ] = NULL ;
F_34 ( & V_2 -> V_90 ) ;
F_13 ( V_23 , V_61 , L_13 ,
V_102 -> V_91 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_101 * V_102 = (struct V_101 * ) V_84 -> V_76 ;
struct V_20 * V_137 = & V_2 -> V_74 ;
T_3 V_116 ;
if ( V_102 -> V_91 == 0 )
return;
V_116 = V_137 -> V_46 * V_102 -> V_91 / V_65 ;
V_102 -> V_116 = F_49 ( F_21 ( V_116 ) ) ;
F_13 ( V_23 , V_61 , L_14 ,
( unsigned long long ) V_116 , V_102 -> V_91 ) ;
}
static void F_50 ( void * V_93 , T_5 * V_138 , struct V_83 * V_84 )
{
bool * V_139 = ( bool * ) V_93 ;
struct V_101 * V_102 = (struct V_101 * ) V_84 -> V_76 ;
if ( V_84 -> type == V_140 &&
V_102 -> V_139 )
* V_139 = true ;
}
static bool F_51 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_137 = & V_2 -> V_74 ;
struct V_141 * V_21 = & V_84 -> V_21 ;
bool V_139 ;
if ( ( V_2 -> V_4 -> V_9 == V_10 ) &&
( V_2 -> V_142 > 1 ) &&
( V_84 -> type == V_10 ) &&
( V_137 -> V_46 != V_21 -> V_143 ) ) {
F_13 ( V_23 , V_61 ,
L_15 ) ;
return false ;
}
if ( V_2 -> V_142 &&
( V_84 -> type != V_10 ) ) {
F_13 ( V_23 , V_61 ,
L_16 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_9 == V_140 ) &&
( V_2 -> V_144 > 1 ) &&
( V_84 -> type == V_140 ) ) {
V_139 = false ;
F_52 ( V_2 -> V_92 ,
F_50 ,
& V_139 ) ;
if ( V_139 ) {
F_13 ( V_23 , V_61 ,
L_17 ) ;
return false ;
}
}
return true ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_137 = & V_2 -> V_74 ;
struct V_141 * V_21 = & V_84 -> V_21 ;
struct V_101 * V_102 = (struct V_101 * ) V_84 -> V_76 ;
if ( ! F_51 ( V_2 , V_84 ) )
return;
V_137 -> V_46 = V_21 -> V_143 ;
if ( V_137 -> V_46 == 0 )
V_137 -> V_46 = 100 ;
V_137 -> V_48 = V_21 -> V_48 ;
V_137 -> V_33 =
V_47 * V_137 -> V_46 ;
switch ( V_84 -> type ) {
case V_140 :
F_7 ( V_2 , V_137 ) ;
V_102 -> V_139 = true ;
break;
case V_14 :
F_22 ( V_2 , V_137 ) ;
break;
case V_10 :
F_18 ( V_2 , V_137 ) ;
break;
default:
F_13 ( V_23 , V_61 , L_18 ) ;
return;
}
}
void F_54 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_137 = & V_2 -> V_74 ;
switch ( V_2 -> V_4 -> V_9 ) {
case V_140 :
F_7 ( V_2 , V_137 ) ;
break;
case V_14 :
F_22 ( V_2 , V_137 ) ;
break;
case V_10 :
F_18 ( V_2 , V_137 ) ;
break;
default:
F_13 ( V_23 , V_61 , L_18 ) ;
return;
}
}
