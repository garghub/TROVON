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
V_35 = V_21 -> V_46 & V_47 ;
V_33 = ( V_48 * V_21 -> V_46 ) ;
V_28 = V_21 -> V_49 ;
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
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_50 ;
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
V_25 . V_51 = V_35 ;
V_25 . V_52 = V_34 ;
V_25 . V_53 = V_28 * V_35 ;
V_25 . V_54 = V_25 . V_52 + V_29 * V_35 ;
V_25 . V_55 = V_31 * V_25 . V_53 ;
V_25 . V_56 = V_25 . V_54 + V_32 * V_25 . V_53 ;
V_25 . V_57 = 0 ;
if ( V_30 > V_35 ) {
V_25 . V_58 = V_48 / 2 ;
} else {
V_25 . V_58 = F_10 ( V_33 , V_35 ) ;
if ( V_25 . V_58 > 15 )
V_25 . V_58 = 15 ;
else if ( V_25 . V_58 <= 0 )
V_25 . V_58 = 1 ;
}
V_25 . V_59 = F_11 ( F_12 ( 100 ) , V_30 ) ;
if ( V_25 . V_59 > V_25 . V_53 )
V_25 . V_59 = V_25 . V_53 ;
V_25 . V_60 = V_61 ;
F_13 ( V_23 , V_62 , L_2 ,
V_35 , V_38 , V_36 ) ;
F_13 ( V_23 , V_62 ,
L_3 ,
V_25 . V_58 , V_25 . V_59 ,
V_25 . V_55 , V_25 . V_57 , V_25 . V_56 ) ;
F_14 ( V_63 ) ;
F_15 ( V_2 -> V_4 , & V_25 ) ;
V_27 |= V_64 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_65 , & V_37 ) ;
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
V_35 = V_21 -> V_46 & V_47 ;
V_35 /= V_66 ;
V_34 = V_35 ;
if ( V_35 > V_67 )
V_2 -> V_4 -> V_68 . V_69 = V_67 ;
else
V_2 -> V_4 -> V_68 . V_69 = V_70 ;
if ( V_2 -> V_71 & V_72 ) {
F_19 ( V_2 -> V_4 ) ;
V_2 -> V_71 &= ~ V_72 ;
} else {
V_38 = F_8 ( V_2 -> V_4 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_50 ;
do {
V_34 += V_35 ;
} while ( V_34 < V_36 );
}
if ( V_2 -> V_71 & V_73 )
V_27 |= V_74 ;
F_13 ( V_23 , V_62 ,
L_4
L_5 ,
V_21 -> V_46 , V_34 ,
V_2 -> V_4 -> V_68 . V_69 , V_27 ) ;
F_1 ( V_2 ) ;
F_14 ( V_63 ) ;
F_20 ( V_2 -> V_4 , F_21 ( V_34 ) , F_21 ( V_35 ) ) ;
V_2 -> V_75 . V_76 = 0 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_65 , & V_37 ) ;
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
V_35 = V_21 -> V_46 & V_47 ;
V_34 = V_35 ;
V_38 = F_8 ( V_2 -> V_4 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) + V_50 ;
do {
V_34 += V_35 ;
} while ( V_34 < V_36 );
if ( V_35 > V_67 )
V_2 -> V_4 -> V_68 . V_69 = V_67 ;
else
V_2 -> V_4 -> V_68 . V_69 = V_70 ;
if ( V_2 -> V_71 & V_73 )
V_27 |= V_74 ;
F_13 ( V_23 , V_62 ,
L_6
L_7 ,
V_21 -> V_46 , V_34 ,
V_2 -> V_4 -> V_68 . V_69 , V_27 ) ;
F_14 ( V_63 ) ;
F_20 ( V_2 -> V_4 , F_21 ( V_34 ) , F_21 ( V_35 ) ) ;
V_2 -> V_75 . V_76 = 0 ;
V_37 = F_16 ( V_27 ) ;
F_17 ( V_65 , & V_37 ) ;
}
void F_23 ( void * V_77 , struct V_78 * V_79 ,
enum V_80 V_81 , bool V_82 )
{
F_24 ( V_79 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
int V_83 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_84 * V_85 ;
struct V_78 * V_79 ;
struct V_86 * V_87 ;
int V_88 , V_89 , T_4 , V_90 ;
F_26 ( & V_2 -> V_91 ) ;
V_85 = V_2 -> V_75 . V_92 [ V_83 ] ;
V_79 = F_27 ( V_2 -> V_93 , V_85 ) ;
while( V_79 ) {
V_87 = (struct V_86 * ) V_79 -> V_94 ;
V_88 = F_28 ( V_87 -> V_95 ) ;
V_89 = V_88 & 3 ;
if ( V_89 && V_79 -> V_96 > V_88 ) {
if ( F_29 ( V_79 ) < V_89 ) {
F_24 ( V_79 ) ;
goto V_97;
}
F_30 ( V_79 , V_89 ) ;
memmove ( V_79 -> V_94 , V_79 -> V_94 + V_89 , V_88 ) ;
}
V_90 = F_31 ( V_2 ) ;
if ( V_90 < 0 ) {
F_13 ( V_23 , V_98 , L_8 ) ;
F_24 ( V_79 ) ;
goto V_97;
}
T_4 = F_32 ( V_2 , V_79 , V_90 , true ) ;
if ( T_4 != 0 ) {
F_33 ( V_2 , V_90 ) ;
F_24 ( V_79 ) ;
F_13 ( V_23 , V_98 ,
L_9 ) ;
} else {
F_26 ( & V_2 -> V_99 . V_100 ) ;
V_2 -> V_99 . V_101 ++ ;
F_34 ( & V_2 -> V_99 . V_100 ) ;
}
V_97:
V_79 = F_27 ( V_2 -> V_93 , V_85 ) ;
}
F_34 ( & V_2 -> V_91 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
int V_83 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_84 * V_85 ;
struct V_102 * V_103 ;
struct V_104 V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_78 * V_112 ;
T_5 * V_113 ;
int T_4 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
F_26 ( & V_2 -> V_91 ) ;
V_85 = V_2 -> V_75 . V_92 [ V_83 ] ;
V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( F_36 ( V_2 -> V_71 & V_114 ) ) {
F_34 ( & V_2 -> V_91 ) ;
return;
}
V_112 = F_37 ( V_2 -> V_93 , V_85 ) ;
if ( ! V_112 ) {
F_34 ( & V_2 -> V_91 ) ;
return;
}
V_111 = (struct V_110 * ) V_112 -> V_94 ;
V_111 -> V_115 . V_112 . V_116 = V_103 -> V_117 ;
V_109 = F_38 ( V_112 ) ;
if ( V_109 -> V_118 & V_119 ) {
struct V_86 * V_87 =
(struct V_86 * ) V_112 -> V_94 ;
V_103 -> V_120 += 0x10 ;
V_87 -> V_121 &= F_39 ( V_122 ) ;
V_87 -> V_121 |= F_39 ( V_103 -> V_120 ) ;
}
V_107 = F_40 ( V_112 ) ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> type = V_123 ;
V_107 -> V_124 = V_2 -> V_125 ;
V_105 . V_126 = V_103 -> V_127 ;
V_113 = F_30 ( V_112 , sizeof( V_105 ) ) ;
memcpy ( V_113 , ( T_5 * ) & V_105 , sizeof( V_105 ) ) ;
T_4 = F_41 ( V_2 -> V_128 , V_112 ) ;
if ( T_4 != 0 ) {
if ( T_4 == - V_129 ) {
F_13 ( V_23 , V_130 ,
L_10 ) ;
}
F_24 ( V_112 ) ;
}
F_34 ( & V_2 -> V_91 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
T_3 V_38 ;
T_1 V_36 ;
T_6 V_35 ;
int V_83 ;
V_35 = V_2 -> V_75 . V_46 & V_47 ;
V_38 = F_43 ( V_132 -> V_38 ) ;
V_36 = F_9 ( V_38 >> 32 , V_38 ) ;
V_83 = ( ( V_36 % V_35 ) * V_66 ) / V_35 ;
V_83 = V_66 - V_83 - 1 ;
F_13 ( V_23 , V_133 ,
L_11 ,
V_83 , V_38 , V_36 , V_35 ) ;
return V_83 ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
int V_83 ;
if ( V_132 -> V_134 != 0 ) {
V_2 -> V_75 . V_76 ++ ;
if ( V_2 -> V_75 . V_76 > V_135 ) {
F_13 ( V_23 , V_130 ,
L_12 ) ;
F_45 ( V_2 -> V_93 ,
& V_2 -> V_136 ) ;
}
return;
}
if ( V_2 -> V_75 . V_76 ) {
F_13 ( V_23 , V_130 ,
L_13 ,
V_2 -> V_75 . V_76 ) ;
V_2 -> V_75 . V_76 = 0 ;
}
V_83 = F_42 ( V_2 , V_132 ) ;
F_26 ( & V_2 -> V_91 ) ;
if ( V_2 -> V_75 . V_92 [ V_83 ] == NULL ) {
F_34 ( & V_2 -> V_91 ) ;
return;
}
F_34 ( & V_2 -> V_91 ) ;
F_25 ( V_2 , V_83 ) ;
F_35 ( V_2 , V_83 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
int V_137 = 0 ;
F_26 ( & V_2 -> V_91 ) ;
for ( V_137 = 0 ; V_137 < V_66 ; V_137 ++ ) {
if ( V_2 -> V_75 . V_92 [ V_137 ] == NULL ) {
V_103 -> V_92 = V_137 ;
break;
}
}
V_2 -> V_75 . V_92 [ V_103 -> V_92 ] = V_85 ;
F_34 ( & V_2 -> V_91 ) ;
F_13 ( V_23 , V_62 ,
L_14 , V_103 -> V_92 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
F_26 ( & V_2 -> V_91 ) ;
V_2 -> V_75 . V_92 [ V_103 -> V_92 ] = NULL ;
F_34 ( & V_2 -> V_91 ) ;
F_13 ( V_23 , V_62 ,
L_15 , V_103 -> V_92 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
struct V_20 * V_138 = & V_2 -> V_75 ;
T_3 V_117 ;
if ( V_103 -> V_92 == 0 )
return;
V_117 = V_138 -> V_46 * V_103 -> V_92 / V_66 ;
V_103 -> V_117 = F_49 ( F_21 ( V_117 ) ) ;
F_13 ( V_23 , V_62 ,
L_16 ,
( unsigned long long ) V_117 , V_103 -> V_92 ) ;
}
static void F_50 ( void * V_94 , T_5 * V_139 , struct V_84 * V_85 )
{
bool * V_140 = ( bool * ) V_94 ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( V_85 -> type == V_141 &&
V_103 -> V_140 )
* V_140 = true ;
}
static bool F_51 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_138 = & V_2 -> V_75 ;
struct V_142 * V_21 = & V_85 -> V_21 ;
bool V_140 ;
if ( ( V_2 -> V_4 -> V_9 == V_10 ) &&
( V_2 -> V_143 > 1 ) &&
( V_85 -> type == V_10 ) &&
( V_138 -> V_46 != V_21 -> V_144 ) ) {
F_13 ( V_23 , V_62 ,
L_17 ) ;
return false ;
}
if ( V_2 -> V_143 &&
( V_85 -> type != V_10 ) ) {
F_13 ( V_23 , V_62 ,
L_18 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_9 == V_141 ) &&
( V_2 -> V_145 > 1 ) &&
( V_85 -> type == V_141 ) ) {
V_140 = false ;
F_52 ( V_2 -> V_93 ,
F_50 ,
& V_140 ) ;
if ( V_140 ) {
F_13 ( V_23 , V_62 ,
L_19 ) ;
return false ;
}
}
return true ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_138 = & V_2 -> V_75 ;
struct V_142 * V_21 = & V_85 -> V_21 ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( ! F_51 ( V_2 , V_85 ) )
return;
V_138 -> V_46 = V_21 -> V_144 ;
if ( V_138 -> V_46 == 0 )
V_138 -> V_46 = 100 ;
V_138 -> V_49 = V_21 -> V_49 ;
V_138 -> V_33 =
V_48 * V_138 -> V_46 ;
switch ( V_85 -> type ) {
case V_141 :
F_7 ( V_2 , V_138 ) ;
V_103 -> V_140 = true ;
break;
case V_14 :
F_22 ( V_2 , V_138 ) ;
break;
case V_10 :
F_18 ( V_2 , V_138 ) ;
break;
default:
F_13 ( V_23 , V_62 ,
L_20 ) ;
return;
}
}
void F_54 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_5 ( V_2 -> V_4 ) ;
struct V_20 * V_138 = & V_2 -> V_75 ;
switch ( V_2 -> V_4 -> V_9 ) {
case V_141 :
F_7 ( V_2 , V_138 ) ;
break;
case V_14 :
F_22 ( V_2 , V_138 ) ;
break;
case V_10 :
F_18 ( V_2 , V_138 ) ;
break;
default:
F_13 ( V_23 , V_62 ,
L_20 ) ;
return;
}
}
