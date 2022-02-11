void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 , V_7 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( struct V_5 ) ) ;
F_2 ( V_4 , V_2 -> V_8 , & V_6 ) ;
if ( V_2 -> V_4 -> V_9 == V_10 ||
V_2 -> V_4 -> V_9 == V_11 ) {
V_6 . V_12 = 1 ;
V_6 . V_13 = 0 ;
V_6 . V_14 = 0 ;
} else if ( V_2 -> V_4 -> V_9 == V_15 ) {
int V_16 = V_2 -> V_17 [ V_18 ] ;
F_2 ( V_4 , V_16 , & V_7 ) ;
V_6 . V_12 = V_7 . V_12 ;
if ( V_4 -> V_19 == V_20 )
V_6 . V_13 = 2 * V_7 . V_13 ;
else
V_6 . V_13 = 4 * V_7 . V_13 ;
V_6 . V_14 = V_7 . V_14 ;
}
if ( ! F_3 ( V_4 , V_2 -> V_8 , & V_6 ) ) {
F_4 ( F_5 ( V_4 ) ,
L_1 , V_2 -> V_8 ) ;
} else {
F_6 ( V_4 , V_2 -> V_8 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_25 V_26 ;
enum V_27 V_28 = 0 ;
int V_29 , V_30 , V_31 ;
int V_32 , V_33 , V_34 ;
T_1 V_35 = 0 , V_36 , V_37 ;
T_2 V_38 = 0 ;
T_3 V_39 ;
int V_40 , V_41 , V_42 , V_43 ;
int T_4 V_44 ( ( V_45 ) ) ;
T_5 V_46 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_36 = V_22 -> V_47 ;
V_34 = ( V_48 * V_22 -> V_47 ) ;
V_29 = V_22 -> V_49 ;
if ( V_29 <= 0 )
V_29 = 1 ;
V_30 = 1 ;
if ( V_30 >= V_29 )
V_30 = 0 ;
V_32 = 1 ;
V_33 = 0 ;
V_31 = V_36 ;
if ( V_31 <= 0 )
V_31 = V_36 ;
V_39 = F_8 ( V_2 -> V_4 ) ;
V_37 = F_9 ( V_39 >> 32 , V_39 ) + V_50 ;
V_40 = V_37 / V_36 + 1 ;
V_41 = V_37 % V_36 ;
V_35 = V_37 - V_41 ;
if ( V_41 )
V_35 += V_36 ;
V_42 = V_40 % V_29 ;
V_43 = ( V_40 / V_29 ) % V_32 ;
if ( V_42 )
V_43 ++ ;
V_30 -= V_42 ;
if ( V_30 < 0 )
V_30 += V_29 ;
V_33 -= V_43 ;
if ( V_33 < 0 )
V_33 += V_32 ;
V_26 . V_51 = V_36 ;
V_26 . V_52 = V_35 ;
V_26 . V_53 = V_29 * V_36 ;
V_26 . V_54 = V_26 . V_52 + V_30 * V_36 ;
V_26 . V_55 = V_32 * V_26 . V_53 ;
V_26 . V_56 = V_26 . V_54 + V_33 * V_26 . V_53 ;
V_26 . V_57 = 0 ;
if ( V_31 > V_36 ) {
V_26 . V_58 = V_48 / 2 ;
} else {
V_26 . V_58 = F_10 ( V_34 , V_36 ) ;
if ( V_26 . V_58 > 15 )
V_26 . V_58 = 15 ;
else if ( V_26 . V_58 <= 0 )
V_26 . V_58 = 1 ;
}
V_26 . V_59 = F_11 ( F_12 ( 100 ) , V_31 ) ;
if ( V_26 . V_59 > V_26 . V_53 )
V_26 . V_59 = V_26 . V_53 ;
V_26 . V_60 = V_61 ;
F_13 ( V_24 , V_62 , L_2 ,
V_36 , V_39 , V_37 ) ;
F_13 ( V_24 , V_62 ,
L_3 ,
V_26 . V_58 , V_26 . V_59 ,
V_26 . V_55 , V_26 . V_57 , V_26 . V_56 ) ;
F_14 ( V_63 ) ;
F_15 ( V_2 -> V_4 , & V_26 ) ;
V_28 |= V_64 ;
V_38 = F_16 ( V_28 ) ;
F_17 ( V_65 , & V_38 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
enum V_27 V_28 = 0 ;
T_1 V_35 , V_36 , V_37 ;
T_2 V_38 = 0 ;
int T_4 V_44 ( ( V_45 ) ) ;
T_5 V_46 ;
T_3 V_39 ;
V_36 = V_22 -> V_47 ;
V_36 /= V_66 ;
V_35 = V_36 ;
if ( V_36 > V_67 )
V_2 -> V_4 -> V_68 . V_69 = V_67 ;
else
V_2 -> V_4 -> V_68 . V_69 = V_70 ;
if ( F_19 ( V_71 , & V_2 -> V_72 ) ) {
F_20 ( V_2 -> V_4 ) ;
F_21 ( V_71 , & V_2 -> V_72 ) ;
} else {
V_39 = F_8 ( V_2 -> V_4 ) ;
V_37 = F_9 ( V_39 >> 32 , V_39 ) + V_50 ;
do {
V_35 += V_36 ;
} while ( V_35 < V_37 );
}
if ( F_19 ( V_73 , & V_2 -> V_72 ) )
V_28 |= V_74 ;
F_13 ( V_24 , V_62 ,
L_4 ,
V_22 -> V_47 , V_35 ,
V_2 -> V_4 -> V_68 . V_69 , V_28 ) ;
F_1 ( V_2 ) ;
F_14 ( V_63 ) ;
F_22 ( V_2 -> V_4 , F_23 ( V_35 ) , F_23 ( V_36 ) ) ;
V_2 -> V_75 . V_76 = 0 ;
V_38 = F_16 ( V_28 ) ;
F_17 ( V_65 , & V_38 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
enum V_27 V_28 = 0 ;
T_1 V_35 , V_36 , V_37 ;
T_2 V_38 = 0 ;
int T_4 V_44 ( ( V_45 ) ) ;
T_5 V_46 ;
T_3 V_39 ;
V_36 = V_22 -> V_47 ;
V_35 = V_36 ;
V_39 = F_8 ( V_2 -> V_4 ) ;
V_37 = F_9 ( V_39 >> 32 , V_39 ) + V_50 ;
do {
V_35 += V_36 ;
} while ( V_35 < V_37 );
if ( V_36 > V_67 )
V_2 -> V_4 -> V_68 . V_69 = V_67 ;
else
V_2 -> V_4 -> V_68 . V_69 = V_70 ;
if ( F_19 ( V_73 , & V_2 -> V_72 ) )
V_28 |= V_74 ;
F_13 ( V_24 , V_62 ,
L_5 ,
V_22 -> V_47 , V_35 ,
V_2 -> V_4 -> V_68 . V_69 , V_28 ) ;
F_14 ( V_63 ) ;
F_22 ( V_2 -> V_4 , F_23 ( V_35 ) , F_23 ( V_36 ) ) ;
V_2 -> V_75 . V_76 = 0 ;
V_38 = F_16 ( V_28 ) ;
F_17 ( V_65 , & V_38 ) ;
}
void F_25 ( void * V_77 , struct V_78 * V_79 ,
enum V_80 V_81 , bool V_82 )
{
F_26 ( V_79 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
int V_83 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_84 * V_85 ;
struct V_78 * V_79 ;
struct V_86 * V_87 ;
int V_88 , V_89 , T_4 , V_90 ;
F_28 ( & V_2 -> V_91 ) ;
V_85 = V_2 -> V_75 . V_92 [ V_83 ] ;
V_79 = F_29 ( V_2 -> V_93 , V_85 ) ;
while( V_79 ) {
V_87 = (struct V_86 * ) V_79 -> V_94 ;
V_88 = F_30 ( V_87 -> V_95 ) ;
V_89 = V_88 & 3 ;
if ( V_89 && V_79 -> V_96 > V_88 ) {
if ( F_31 ( V_79 ) < V_89 ) {
F_26 ( V_79 ) ;
goto V_97;
}
F_32 ( V_79 , V_89 ) ;
memmove ( V_79 -> V_94 , V_79 -> V_94 + V_89 , V_88 ) ;
}
V_90 = F_33 ( V_2 ) ;
if ( V_90 < 0 ) {
F_13 ( V_24 , V_98 , L_6 ) ;
F_26 ( V_79 ) ;
goto V_97;
}
T_4 = F_34 ( V_2 , NULL , V_79 , V_90 , true ) ;
if ( T_4 != 0 ) {
F_35 ( V_2 , V_90 ) ;
F_26 ( V_79 ) ;
F_13 ( V_24 , V_98 , L_7 ) ;
} else {
F_28 ( & V_2 -> V_99 . V_100 ) ;
V_2 -> V_99 . V_101 ++ ;
F_36 ( & V_2 -> V_99 . V_100 ) ;
}
V_97:
V_79 = F_29 ( V_2 -> V_93 , V_85 ) ;
}
F_36 ( & V_2 -> V_91 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
int V_83 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
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
F_28 ( & V_2 -> V_91 ) ;
V_85 = V_2 -> V_75 . V_92 [ V_83 ] ;
V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( F_38 ( F_19 ( V_114 , & V_2 -> V_72 ) ) ) {
F_36 ( & V_2 -> V_91 ) ;
return;
}
V_112 = F_39 ( V_2 -> V_93 , V_85 ) ;
if ( ! V_112 ) {
F_36 ( & V_2 -> V_91 ) ;
return;
}
V_111 = (struct V_110 * ) V_112 -> V_94 ;
V_111 -> V_115 . V_112 . V_116 = V_103 -> V_117 ;
V_109 = F_40 ( V_112 ) ;
if ( V_109 -> V_118 & V_119 ) {
struct V_86 * V_87 =
(struct V_86 * ) V_112 -> V_94 ;
V_103 -> V_120 += 0x10 ;
V_87 -> V_121 &= F_41 ( V_122 ) ;
V_87 -> V_121 |= F_41 ( V_103 -> V_120 ) ;
}
V_107 = F_42 ( V_112 ) ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> type = V_123 ;
V_107 -> V_124 = V_2 -> V_125 ;
V_105 . V_126 = V_103 -> V_127 ;
V_113 = F_32 ( V_112 , sizeof( V_105 ) ) ;
memcpy ( V_113 , ( T_5 * ) & V_105 , sizeof( V_105 ) ) ;
T_4 = F_43 ( V_2 -> V_128 , V_112 ) ;
if ( T_4 != 0 ) {
if ( T_4 == - V_129 ) {
F_13 ( V_24 , V_130 ,
L_8 ) ;
}
F_26 ( V_112 ) ;
}
F_36 ( & V_2 -> V_91 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
T_3 V_39 ;
T_1 V_37 ;
T_6 V_36 ;
int V_83 ;
V_36 = V_2 -> V_75 . V_47 ;
V_39 = F_45 ( V_132 -> V_39 ) ;
V_37 = F_9 ( V_39 >> 32 , V_39 ) ;
V_83 = ( ( V_37 % V_36 ) * V_66 ) / V_36 ;
V_83 = V_66 - V_83 - 1 ;
F_13 ( V_24 , V_133 ,
L_9 ,
V_83 , V_39 , V_37 , V_36 ) ;
return V_83 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
int V_83 ;
if ( V_132 -> V_134 != 0 ) {
V_2 -> V_75 . V_76 ++ ;
if ( V_2 -> V_75 . V_76 > V_135 ) {
F_13 ( V_24 , V_130 , L_10 ) ;
F_47 ( V_2 -> V_93 ,
& V_2 -> V_136 ) ;
}
return;
}
if ( V_2 -> V_75 . V_76 ) {
F_13 ( V_24 , V_130 ,
L_11 ,
V_2 -> V_75 . V_76 ) ;
V_2 -> V_75 . V_76 = 0 ;
}
V_83 = F_44 ( V_2 , V_132 ) ;
F_28 ( & V_2 -> V_91 ) ;
if ( V_2 -> V_75 . V_92 [ V_83 ] == NULL ) {
F_36 ( & V_2 -> V_91 ) ;
return;
}
F_36 ( & V_2 -> V_91 ) ;
F_27 ( V_2 , V_83 ) ;
F_37 ( V_2 , V_83 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
int V_137 = 0 ;
F_28 ( & V_2 -> V_91 ) ;
for ( V_137 = 0 ; V_137 < V_66 ; V_137 ++ ) {
if ( V_2 -> V_75 . V_92 [ V_137 ] == NULL ) {
V_103 -> V_92 = V_137 ;
break;
}
}
V_2 -> V_75 . V_92 [ V_103 -> V_92 ] = V_85 ;
F_36 ( & V_2 -> V_91 ) ;
F_13 ( V_24 , V_62 , L_12 ,
V_103 -> V_92 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
F_28 ( & V_2 -> V_91 ) ;
V_2 -> V_75 . V_92 [ V_103 -> V_92 ] = NULL ;
F_36 ( & V_2 -> V_91 ) ;
F_13 ( V_24 , V_62 , L_13 ,
V_103 -> V_92 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
struct V_21 * V_138 = & V_2 -> V_75 ;
T_3 V_117 ;
if ( V_103 -> V_92 == 0 )
return;
V_117 = V_138 -> V_47 * V_103 -> V_92 / V_66 ;
V_103 -> V_117 = F_51 ( F_23 ( V_117 ) ) ;
F_13 ( V_24 , V_62 , L_14 ,
( unsigned long long ) V_117 , V_103 -> V_92 ) ;
}
static void F_52 ( void * V_94 , T_5 * V_139 , struct V_84 * V_85 )
{
bool * V_140 = ( bool * ) V_94 ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( V_85 -> type == V_141 &&
V_103 -> V_140 )
* V_140 = true ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_138 = & V_2 -> V_75 ;
struct V_142 * V_22 = & V_85 -> V_22 ;
bool V_140 ;
if ( ( V_2 -> V_4 -> V_9 == V_10 ) &&
( V_2 -> V_143 > 1 ) &&
( V_85 -> type == V_10 ) &&
( V_138 -> V_47 != V_22 -> V_144 ) ) {
F_13 ( V_24 , V_62 ,
L_15 ) ;
return false ;
}
if ( V_2 -> V_143 &&
( V_85 -> type != V_10 ) ) {
F_13 ( V_24 , V_62 ,
L_16 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_9 == V_141 ) &&
( V_2 -> V_145 > 1 ) &&
( V_85 -> type == V_141 ) ) {
V_140 = false ;
F_54 (
V_2 -> V_93 , V_146 ,
F_52 , & V_140 ) ;
if ( V_140 ) {
F_13 ( V_24 , V_62 ,
L_17 ) ;
return false ;
}
}
return true ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_138 = & V_2 -> V_75 ;
struct V_142 * V_22 = & V_85 -> V_22 ;
struct V_102 * V_103 = (struct V_102 * ) V_85 -> V_77 ;
if ( ! F_53 ( V_2 , V_85 ) )
return;
V_138 -> V_47 = V_22 -> V_144 ;
if ( V_138 -> V_47 == 0 )
V_138 -> V_47 = 100 ;
V_138 -> V_49 = V_22 -> V_49 ;
V_138 -> V_34 =
V_48 * V_138 -> V_47 ;
switch ( V_85 -> type ) {
case V_141 :
F_7 ( V_2 , V_138 ) ;
V_103 -> V_140 = true ;
break;
case V_15 :
F_24 ( V_2 , V_138 ) ;
break;
case V_11 :
case V_10 :
F_18 ( V_2 , V_138 ) ;
break;
default:
F_13 ( V_24 , V_62 , L_18 ) ;
return;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_138 = & V_2 -> V_75 ;
switch ( V_2 -> V_4 -> V_9 ) {
case V_141 :
F_7 ( V_2 , V_138 ) ;
break;
case V_15 :
F_24 ( V_2 , V_138 ) ;
break;
case V_11 :
case V_10 :
F_18 ( V_2 , V_138 ) ;
break;
default:
F_13 ( V_24 , V_62 , L_18 ) ;
return;
}
}
