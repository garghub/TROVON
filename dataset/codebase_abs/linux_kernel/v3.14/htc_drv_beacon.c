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
int V_32 ;
T_1 V_33 = 0 , V_34 , V_35 ;
T_2 V_36 = 0 ;
T_3 V_37 ;
int V_38 , V_39 , V_40 ;
int T_4 V_41 ( ( V_42 ) ) ;
T_5 V_43 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_34 = V_22 -> V_44 ;
V_32 = ( V_45 * V_22 -> V_44 ) ;
V_29 = V_22 -> V_46 ;
if ( V_29 <= 0 )
V_29 = 1 ;
V_30 = 1 ;
if ( V_30 >= V_29 )
V_30 = 0 ;
V_31 = V_34 ;
if ( V_31 <= 0 )
V_31 = V_34 ;
V_37 = F_8 ( V_2 -> V_4 ) ;
V_35 = F_9 ( V_37 >> 32 , V_37 ) + V_47 ;
V_38 = V_35 / V_34 + 1 ;
V_39 = V_35 % V_34 ;
V_33 = V_35 - V_39 ;
if ( V_39 )
V_33 += V_34 ;
V_40 = V_38 % V_29 ;
V_30 -= V_40 ;
if ( V_30 < 0 )
V_30 += V_29 ;
V_26 . V_48 = F_10 ( V_34 ) ;
V_26 . V_49 = F_10 ( V_33 ) ;
V_26 . V_50 = V_29 * V_26 . V_48 ;
V_26 . V_51 = V_26 . V_49 + V_30 * V_26 . V_48 ;
if ( V_31 > V_34 ) {
V_26 . V_52 = V_45 / 2 ;
} else {
V_26 . V_52 = F_11 ( V_32 , V_34 ) ;
if ( V_26 . V_52 > 15 )
V_26 . V_52 = 15 ;
else if ( V_26 . V_52 <= 0 )
V_26 . V_52 = 1 ;
}
V_26 . V_53 = F_10 ( F_12 ( F_13 ( 100 ) ,
V_31 ) ) ;
if ( V_26 . V_53 > V_26 . V_50 )
V_26 . V_53 = V_26 . V_50 ;
V_26 . V_54 = V_55 ;
F_14 ( V_24 , V_56 , L_2 ,
V_34 , V_37 , V_35 ) ;
F_14 ( V_24 , V_56 , L_3 ,
V_26 . V_52 , V_26 . V_53 ) ;
F_15 ( V_57 ) ;
F_16 ( V_2 -> V_4 , & V_26 ) ;
V_28 |= V_58 ;
V_36 = F_17 ( V_28 ) ;
F_18 ( V_59 , & V_36 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
enum V_27 V_28 = 0 ;
T_1 V_33 , V_34 , V_35 ;
T_2 V_36 = 0 ;
int T_4 V_41 ( ( V_42 ) ) ;
T_5 V_43 ;
T_3 V_37 ;
V_34 = V_22 -> V_44 ;
V_34 /= V_60 ;
V_33 = V_34 ;
if ( V_34 > V_61 )
V_2 -> V_4 -> V_62 . V_63 = V_61 ;
else
V_2 -> V_4 -> V_62 . V_63 = V_64 ;
if ( F_20 ( V_65 , & V_2 -> V_66 ) ) {
F_21 ( V_2 -> V_4 ) ;
F_22 ( V_65 , & V_2 -> V_66 ) ;
} else {
V_37 = F_8 ( V_2 -> V_4 ) ;
V_35 = F_9 ( V_37 >> 32 , V_37 ) + V_47 ;
do {
V_33 += V_34 ;
} while ( V_33 < V_35 );
}
if ( F_20 ( V_67 , & V_2 -> V_66 ) )
V_28 |= V_68 ;
F_14 ( V_24 , V_56 ,
L_4 ,
V_22 -> V_44 , V_33 ,
V_2 -> V_4 -> V_62 . V_63 , V_28 ) ;
F_1 ( V_2 ) ;
F_15 ( V_57 ) ;
F_23 ( V_2 -> V_4 , F_10 ( V_33 ) , F_10 ( V_34 ) ) ;
V_2 -> V_69 . V_70 = 0 ;
V_36 = F_17 ( V_28 ) ;
F_18 ( V_59 , & V_36 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
enum V_27 V_28 = 0 ;
T_1 V_33 , V_34 , V_35 ;
T_2 V_36 = 0 ;
int T_4 V_41 ( ( V_42 ) ) ;
T_5 V_43 ;
T_3 V_37 ;
V_34 = V_22 -> V_44 ;
V_33 = V_34 ;
V_37 = F_8 ( V_2 -> V_4 ) ;
V_35 = F_9 ( V_37 >> 32 , V_37 ) + V_47 ;
do {
V_33 += V_34 ;
} while ( V_33 < V_35 );
if ( V_34 > V_61 )
V_2 -> V_4 -> V_62 . V_63 = V_61 ;
else
V_2 -> V_4 -> V_62 . V_63 = V_64 ;
if ( F_20 ( V_67 , & V_2 -> V_66 ) )
V_28 |= V_68 ;
F_14 ( V_24 , V_56 ,
L_5 ,
V_22 -> V_44 , V_33 ,
V_2 -> V_4 -> V_62 . V_63 , V_28 ) ;
F_15 ( V_57 ) ;
F_23 ( V_2 -> V_4 , F_10 ( V_33 ) , F_10 ( V_34 ) ) ;
V_2 -> V_69 . V_70 = 0 ;
V_36 = F_17 ( V_28 ) ;
F_18 ( V_59 , & V_36 ) ;
}
void F_25 ( void * V_71 , struct V_72 * V_73 ,
enum V_74 V_75 , bool V_76 )
{
F_26 ( V_73 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
int V_77 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_78 * V_79 ;
struct V_72 * V_73 ;
struct V_80 * V_81 ;
int V_82 , V_83 , T_4 , V_84 ;
F_28 ( & V_2 -> V_85 ) ;
V_79 = V_2 -> V_69 . V_86 [ V_77 ] ;
V_73 = F_29 ( V_2 -> V_87 , V_79 ) ;
while( V_73 ) {
V_81 = (struct V_80 * ) V_73 -> V_88 ;
V_82 = F_30 ( V_81 -> V_89 ) ;
V_83 = V_82 & 3 ;
if ( V_83 && V_73 -> V_90 > V_82 ) {
if ( F_31 ( V_73 ) < V_83 ) {
F_26 ( V_73 ) ;
goto V_91;
}
F_32 ( V_73 , V_83 ) ;
memmove ( V_73 -> V_88 , V_73 -> V_88 + V_83 , V_82 ) ;
}
V_84 = F_33 ( V_2 ) ;
if ( V_84 < 0 ) {
F_14 ( V_24 , V_92 , L_6 ) ;
F_26 ( V_73 ) ;
goto V_91;
}
T_4 = F_34 ( V_2 , NULL , V_73 , V_84 , true ) ;
if ( T_4 != 0 ) {
F_35 ( V_2 , V_84 ) ;
F_26 ( V_73 ) ;
F_14 ( V_24 , V_92 , L_7 ) ;
} else {
F_28 ( & V_2 -> V_93 . V_94 ) ;
V_2 -> V_93 . V_95 ++ ;
F_36 ( & V_2 -> V_93 . V_94 ) ;
}
V_91:
V_73 = F_29 ( V_2 -> V_87 , V_79 ) ;
}
F_36 ( & V_2 -> V_85 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
int V_77 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_78 * V_79 ;
struct V_96 * V_97 ;
struct V_98 V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_72 * V_106 ;
T_5 * V_107 ;
int T_4 ;
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
F_28 ( & V_2 -> V_85 ) ;
V_79 = V_2 -> V_69 . V_86 [ V_77 ] ;
V_97 = (struct V_96 * ) V_79 -> V_71 ;
if ( F_38 ( F_20 ( V_108 , & V_2 -> V_66 ) ) ) {
F_36 ( & V_2 -> V_85 ) ;
return;
}
V_106 = F_39 ( V_2 -> V_87 , V_79 ) ;
if ( ! V_106 ) {
F_36 ( & V_2 -> V_85 ) ;
return;
}
V_105 = (struct V_104 * ) V_106 -> V_88 ;
V_105 -> V_109 . V_106 . V_110 = V_97 -> V_111 ;
V_103 = F_40 ( V_106 ) ;
if ( V_103 -> V_112 & V_113 ) {
struct V_80 * V_81 =
(struct V_80 * ) V_106 -> V_88 ;
V_97 -> V_114 += 0x10 ;
V_81 -> V_115 &= F_41 ( V_116 ) ;
V_81 -> V_115 |= F_41 ( V_97 -> V_114 ) ;
}
V_101 = F_42 ( V_106 ) ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> type = V_117 ;
V_101 -> V_118 = V_2 -> V_119 ;
V_99 . V_120 = V_97 -> V_121 ;
V_107 = F_32 ( V_106 , sizeof( V_99 ) ) ;
memcpy ( V_107 , ( T_5 * ) & V_99 , sizeof( V_99 ) ) ;
T_4 = F_43 ( V_2 -> V_122 , V_106 ) ;
if ( T_4 != 0 ) {
if ( T_4 == - V_123 ) {
F_14 ( V_24 , V_124 ,
L_8 ) ;
}
F_26 ( V_106 ) ;
}
F_36 ( & V_2 -> V_85 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
T_3 V_37 ;
T_1 V_35 ;
T_6 V_34 ;
int V_77 ;
V_34 = V_2 -> V_69 . V_44 ;
V_37 = F_45 ( V_126 -> V_37 ) ;
V_35 = F_9 ( V_37 >> 32 , V_37 ) ;
V_77 = ( ( V_35 % V_34 ) * V_60 ) / V_34 ;
V_77 = V_60 - V_77 - 1 ;
F_14 ( V_24 , V_127 ,
L_9 ,
V_77 , V_37 , V_35 , V_34 ) ;
return V_77 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
int V_77 ;
if ( V_126 -> V_128 != 0 ) {
V_2 -> V_69 . V_70 ++ ;
if ( V_2 -> V_69 . V_70 > V_129 ) {
F_14 ( V_24 , V_124 , L_10 ) ;
F_47 ( V_2 -> V_87 ,
& V_2 -> V_130 ) ;
}
return;
}
if ( V_2 -> V_69 . V_70 ) {
F_14 ( V_24 , V_124 ,
L_11 ,
V_2 -> V_69 . V_70 ) ;
V_2 -> V_69 . V_70 = 0 ;
}
V_77 = F_44 ( V_2 , V_126 ) ;
F_28 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_69 . V_86 [ V_77 ] == NULL ) {
F_36 ( & V_2 -> V_85 ) ;
return;
}
F_36 ( & V_2 -> V_85 ) ;
F_27 ( V_2 , V_77 ) ;
F_37 ( V_2 , V_77 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_96 * V_97 = (struct V_96 * ) V_79 -> V_71 ;
int V_131 = 0 ;
F_28 ( & V_2 -> V_85 ) ;
for ( V_131 = 0 ; V_131 < V_60 ; V_131 ++ ) {
if ( V_2 -> V_69 . V_86 [ V_131 ] == NULL ) {
V_97 -> V_86 = V_131 ;
break;
}
}
V_2 -> V_69 . V_86 [ V_97 -> V_86 ] = V_79 ;
F_36 ( & V_2 -> V_85 ) ;
F_14 ( V_24 , V_56 , L_12 ,
V_97 -> V_86 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_96 * V_97 = (struct V_96 * ) V_79 -> V_71 ;
F_28 ( & V_2 -> V_85 ) ;
V_2 -> V_69 . V_86 [ V_97 -> V_86 ] = NULL ;
F_36 ( & V_2 -> V_85 ) ;
F_14 ( V_24 , V_56 , L_13 ,
V_97 -> V_86 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_96 * V_97 = (struct V_96 * ) V_79 -> V_71 ;
struct V_21 * V_132 = & V_2 -> V_69 ;
T_3 V_111 ;
if ( V_97 -> V_86 == 0 )
return;
V_111 = V_132 -> V_44 * V_97 -> V_86 / V_60 ;
V_97 -> V_111 = F_51 ( F_10 ( V_111 ) ) ;
F_14 ( V_24 , V_56 , L_14 ,
( unsigned long long ) V_111 , V_97 -> V_86 ) ;
}
static void F_52 ( void * V_88 , T_5 * V_133 , struct V_78 * V_79 )
{
bool * V_134 = ( bool * ) V_88 ;
struct V_96 * V_97 = (struct V_96 * ) V_79 -> V_71 ;
if ( V_79 -> type == V_135 &&
V_97 -> V_134 )
* V_134 = true ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_132 = & V_2 -> V_69 ;
struct V_136 * V_22 = & V_79 -> V_22 ;
bool V_134 ;
if ( ( V_2 -> V_4 -> V_9 == V_10 ) &&
( V_2 -> V_137 > 1 ) &&
( V_79 -> type == V_10 ) &&
( V_132 -> V_44 != V_22 -> V_138 ) ) {
F_14 ( V_24 , V_56 ,
L_15 ) ;
return false ;
}
if ( V_2 -> V_137 &&
( V_79 -> type != V_10 ) ) {
F_14 ( V_24 , V_56 ,
L_16 ) ;
return false ;
}
if ( ( V_2 -> V_4 -> V_9 == V_135 ) &&
( V_2 -> V_139 > 1 ) &&
( V_79 -> type == V_135 ) ) {
V_134 = false ;
F_54 (
V_2 -> V_87 , V_140 ,
F_52 , & V_134 ) ;
if ( V_134 ) {
F_14 ( V_24 , V_56 ,
L_17 ) ;
return false ;
}
}
return true ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_132 = & V_2 -> V_69 ;
struct V_136 * V_22 = & V_79 -> V_22 ;
struct V_96 * V_97 = (struct V_96 * ) V_79 -> V_71 ;
if ( ! F_53 ( V_2 , V_79 ) )
return;
V_132 -> V_44 = V_22 -> V_138 ;
if ( V_132 -> V_44 == 0 )
V_132 -> V_44 = 100 ;
V_132 -> V_46 = V_22 -> V_46 ;
V_132 -> V_32 =
V_45 * V_132 -> V_44 ;
switch ( V_79 -> type ) {
case V_135 :
F_7 ( V_2 , V_132 ) ;
V_97 -> V_134 = true ;
break;
case V_15 :
F_24 ( V_2 , V_132 ) ;
break;
case V_11 :
case V_10 :
F_19 ( V_2 , V_132 ) ;
break;
default:
F_14 ( V_24 , V_56 , L_18 ) ;
return;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_5 ( V_2 -> V_4 ) ;
struct V_21 * V_132 = & V_2 -> V_69 ;
switch ( V_2 -> V_4 -> V_9 ) {
case V_135 :
F_7 ( V_2 , V_132 ) ;
break;
case V_15 :
F_24 ( V_2 , V_132 ) ;
break;
case V_11 :
case V_10 :
F_19 ( V_2 , V_132 ) ;
break;
default:
F_14 ( V_24 , V_56 , L_18 ) ;
return;
}
}
