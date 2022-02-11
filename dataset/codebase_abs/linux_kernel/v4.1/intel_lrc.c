int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 . V_5 == - 1 ) ;
if ( F_3 ( V_2 ) -> V_6 >= 9 )
return 1 ;
if ( V_3 == 0 )
return 0 ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) &&
V_4 . V_7 >= 0 )
return 1 ;
return 0 ;
}
T_1 F_6 ( struct V_8 * V_9 )
{
T_1 V_10 = F_7 ( V_9 ) ;
return V_10 >> 12 ;
}
static T_2 F_8 ( struct V_11 * V_12 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_13 ;
T_2 V_10 = F_7 ( V_9 ) ;
F_2 ( V_10 & 0xFFFFFFFF00000FFFULL ) ;
V_13 = V_14 ;
V_13 |= V_15 << V_16 ;
V_13 |= V_17 ;
V_13 |= V_18 ;
V_13 |= V_10 ;
V_13 |= ( V_19 ) F_6 ( V_9 ) << V_20 ;
if ( F_9 ( V_2 ) &&
F_10 ( V_2 ) <= V_21 &&
( V_12 -> V_22 == V_23 || V_12 -> V_22 == V_24 ||
V_12 -> V_22 == V_25 || V_12 -> V_22 == V_26 ) )
V_13 |= V_27 ;
return V_13 ;
}
static void F_11 ( struct V_11 * V_12 ,
struct V_8 * V_28 ,
struct V_8 * V_29 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
T_2 V_33 = 0 ;
T_3 V_13 [ 4 ] ;
if ( V_29 )
V_33 = F_8 ( V_12 , V_29 ) ;
else
V_33 = 0 ;
V_13 [ 1 ] = ( T_1 ) ( V_33 >> 32 ) ;
V_13 [ 0 ] = ( T_1 ) V_33 ;
V_33 = F_8 ( V_12 , V_28 ) ;
V_13 [ 3 ] = ( T_1 ) ( V_33 >> 32 ) ;
V_13 [ 2 ] = ( T_1 ) V_33 ;
F_12 ( V_31 , V_34 ) ;
F_13 ( F_14 ( V_12 ) , V_13 [ 1 ] ) ;
F_13 ( F_14 ( V_12 ) , V_13 [ 0 ] ) ;
F_13 ( F_14 ( V_12 ) , V_13 [ 3 ] ) ;
F_13 ( F_14 ( V_12 ) , V_13 [ 2 ] ) ;
F_15 ( F_16 ( V_12 ) ) ;
F_17 ( V_31 , V_34 ) ;
}
static int F_18 ( struct V_8 * V_9 ,
struct V_8 * V_35 ,
T_1 V_36 )
{
struct V_37 * V_37 ;
T_3 * V_38 ;
V_37 = F_19 ( V_9 , 1 ) ;
V_38 = F_20 ( V_37 ) ;
V_38 [ V_39 + 1 ] = V_36 ;
V_38 [ V_40 + 1 ] = F_7 ( V_35 ) ;
F_21 ( V_38 ) ;
return 0 ;
}
static void F_22 ( struct V_11 * V_12 ,
struct V_41 * V_42 , T_1 V_43 ,
struct V_41 * V_44 , T_1 V_45 )
{
struct V_8 * V_28 = V_42 -> V_46 [ V_12 -> V_22 ] . V_47 ;
struct V_48 * V_49 = V_42 -> V_46 [ V_12 -> V_22 ] . V_50 ;
struct V_8 * V_29 = NULL ;
struct V_48 * V_51 = NULL ;
F_23 ( ! V_28 ) ;
F_2 ( ! F_24 ( V_28 ) ) ;
F_2 ( ! F_24 ( V_49 -> V_52 ) ) ;
F_18 ( V_28 , V_49 -> V_52 , V_43 ) ;
if ( V_44 ) {
V_51 = V_44 -> V_46 [ V_12 -> V_22 ] . V_50 ;
V_29 = V_44 -> V_46 [ V_12 -> V_22 ] . V_47 ;
F_23 ( ! V_29 ) ;
F_2 ( ! F_24 ( V_29 ) ) ;
F_2 ( ! F_24 ( V_51 -> V_52 ) ) ;
F_18 ( V_29 , V_51 -> V_52 , V_45 ) ;
}
F_11 ( V_12 , V_28 , V_29 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
struct V_53 * V_54 = NULL , * V_55 = NULL ;
struct V_53 * V_56 = NULL , * V_57 = NULL ;
F_26 ( & V_12 -> V_58 ) ;
if ( F_27 ( & V_12 -> V_59 ) )
return;
F_28 (cursor, tmp, &ring->execlist_queue,
execlist_link) {
if ( ! V_54 ) {
V_54 = V_56 ;
} else if ( V_54 -> V_60 == V_56 -> V_60 ) {
V_56 -> V_61 = V_54 -> V_61 ;
F_29 ( & V_54 -> V_62 ) ;
F_30 ( & V_54 -> V_62 ,
& V_12 -> V_63 ) ;
V_54 = V_56 ;
} else {
V_55 = V_56 ;
break;
}
}
if ( F_31 ( V_12 -> V_2 ) || F_9 ( V_12 -> V_2 ) ) {
if ( V_54 && V_54 -> V_61 ) {
struct V_48 * V_50 ;
V_50 = V_54 -> V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
V_54 -> V_36 += 8 ;
V_54 -> V_36 &= V_50 -> V_64 - 1 ;
}
}
F_2 ( V_55 && V_55 -> V_61 ) ;
F_22 ( V_12 , V_54 -> V_60 , V_54 -> V_36 ,
V_55 ? V_55 -> V_60 : NULL ,
V_55 ? V_55 -> V_36 : 0 ) ;
V_54 -> V_61 ++ ;
if ( V_55 )
V_55 -> V_61 ++ ;
}
static bool F_32 ( struct V_11 * V_12 ,
T_1 V_65 )
{
struct V_53 * V_66 ;
F_26 ( & V_12 -> V_58 ) ;
V_66 = F_33 ( & V_12 -> V_59 ,
struct V_53 ,
V_62 ) ;
if ( V_66 != NULL ) {
struct V_8 * V_9 =
V_66 -> V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ;
if ( F_6 ( V_9 ) == V_65 ) {
F_34 ( V_66 -> V_61 == 0 ,
L_1 ) ;
if ( -- V_66 -> V_61 <= 0 ) {
F_29 ( & V_66 -> V_62 ) ;
F_30 ( & V_66 -> V_62 ,
& V_12 -> V_63 ) ;
return true ;
}
}
}
return false ;
}
void F_35 ( struct V_11 * V_12 )
{
struct V_30 * V_31 = V_12 -> V_2 -> V_32 ;
T_1 V_67 ;
T_4 V_68 ;
T_4 V_69 ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_72 = 0 ;
V_67 = F_36 ( F_37 ( V_12 ) ) ;
V_68 = V_12 -> V_73 ;
V_69 = V_67 & 0x07 ;
if ( V_68 > V_69 )
V_69 += 6 ;
F_38 ( & V_12 -> V_58 ) ;
while ( V_68 < V_69 ) {
V_68 ++ ;
V_70 = F_36 ( F_39 ( V_12 ) +
( V_68 % 6 ) * 8 ) ;
V_71 = F_36 ( F_39 ( V_12 ) +
( V_68 % 6 ) * 8 + 4 ) ;
if ( V_70 & V_74 ) {
if ( V_70 & V_75 ) {
if ( F_32 ( V_12 , V_71 ) )
F_34 ( 1 , L_2 ) ;
} else
F_34 ( 1 , L_3 ) ;
}
if ( ( V_70 & V_76 ) ||
( V_70 & V_77 ) ) {
if ( F_32 ( V_12 , V_71 ) )
V_72 ++ ;
}
}
if ( V_72 != 0 )
F_25 ( V_12 ) ;
F_40 ( & V_12 -> V_58 ) ;
F_34 ( V_72 > 2 , L_4 ) ;
V_12 -> V_73 = V_69 % 6 ;
F_13 ( F_37 ( V_12 ) ,
( ( T_1 ) V_12 -> V_73 & 0x07 ) << 8 ) ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_41 * V_78 ,
T_1 V_36 ,
struct V_53 * V_79 )
{
struct V_53 * V_56 ;
struct V_30 * V_31 = V_12 -> V_2 -> V_32 ;
unsigned long V_80 ;
int V_81 = 0 ;
if ( V_78 != V_12 -> V_82 )
F_42 ( V_12 , V_78 ) ;
if ( ! V_79 ) {
V_79 = F_43 ( sizeof( * V_79 ) , V_83 ) ;
if ( V_79 == NULL )
return - V_84 ;
V_79 -> V_12 = V_12 ;
V_79 -> V_60 = V_78 ;
F_44 ( & V_79 -> V_85 ) ;
V_79 -> V_86 = V_31 -> V_87 ++ ;
F_45 ( V_79 -> V_60 ) ;
} else {
F_46 ( V_79 ) ;
F_2 ( V_78 != V_79 -> V_60 ) ;
}
V_79 -> V_36 = V_36 ;
F_47 ( V_31 ) ;
F_48 ( & V_12 -> V_58 , V_80 ) ;
F_49 (cursor, &ring->execlist_queue, execlist_link)
if ( ++ V_81 > 2 )
break;
if ( V_81 > 2 ) {
struct V_53 * V_88 ;
V_88 = F_50 ( & V_12 -> V_59 ,
struct V_53 ,
V_62 ) ;
if ( V_78 == V_88 -> V_60 ) {
F_34 ( V_88 -> V_61 != 0 ,
L_5 ) ;
F_29 ( & V_88 -> V_62 ) ;
F_30 ( & V_88 -> V_62 ,
& V_12 -> V_63 ) ;
}
}
F_30 ( & V_79 -> V_62 , & V_12 -> V_59 ) ;
if ( V_81 == 0 )
F_25 ( V_12 ) ;
F_51 ( & V_12 -> V_58 , V_80 ) ;
return 0 ;
}
static int F_52 ( struct V_48 * V_50 ,
struct V_41 * V_60 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
T_3 V_89 ;
int V_90 ;
V_89 = 0 ;
if ( V_12 -> V_91 )
V_89 = V_92 ;
V_90 = V_12 -> V_93 ( V_50 , V_60 ,
V_92 , V_89 ) ;
if ( V_90 )
return V_90 ;
V_12 -> V_91 = false ;
return 0 ;
}
static int F_53 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
struct V_94 * V_95 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_96 * V_97 ;
T_3 V_89 = 0 ;
bool V_98 = false ;
int V_90 ;
F_49 (vma, vmas, exec_list) {
struct V_8 * V_52 = V_97 -> V_52 ;
V_90 = F_54 ( V_52 , V_12 ) ;
if ( V_90 )
return V_90 ;
if ( V_52 -> V_99 . V_100 & V_101 )
V_98 |= F_55 ( V_52 , false ) ;
V_89 |= V_52 -> V_99 . V_100 ;
}
if ( V_89 & V_102 )
F_56 () ;
return F_52 ( V_50 , V_60 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_11 * V_12 ,
struct V_41 * V_60 ,
struct V_105 * args ,
struct V_94 * V_95 ,
struct V_8 * V_106 ,
V_19 V_107 , T_1 V_108 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_48 * V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
int V_109 ;
T_1 V_110 ;
int V_90 ;
V_109 = args -> V_80 & V_111 ;
V_110 = V_111 ;
switch ( V_109 ) {
case V_112 :
case V_113 :
case V_114 :
if ( V_109 != 0 && V_12 != & V_31 -> V_12 [ V_115 ] ) {
F_58 ( L_6 ) ;
return - V_116 ;
}
if ( V_109 != V_31 -> V_117 ) {
if ( V_109 == V_114 ) {
F_58 ( L_7 ) ;
return - V_116 ;
}
V_110 &= ~ V_114 ;
}
break;
default:
F_58 ( L_8 , V_109 ) ;
return - V_116 ;
}
if ( args -> V_118 != 0 ) {
F_58 ( L_9 ) ;
return - V_116 ;
} else {
if ( args -> V_119 == 0xffffffff ) {
F_58 ( L_10 ) ;
args -> V_119 = 0 ;
}
if ( args -> V_120 || args -> V_119 || args -> V_121 ) {
F_58 ( L_11 ) ;
return - V_116 ;
}
}
if ( args -> V_80 & V_122 ) {
F_58 ( L_12 ) ;
return - V_116 ;
}
V_90 = F_53 ( V_50 , V_60 , V_95 ) ;
if ( V_90 )
return V_90 ;
if ( V_12 == & V_31 -> V_12 [ V_115 ] &&
V_109 != V_31 -> V_117 ) {
V_90 = F_59 ( V_50 , V_60 , 4 ) ;
if ( V_90 )
return V_90 ;
F_60 ( V_50 , V_123 ) ;
F_60 ( V_50 , F_61 ( 1 ) ) ;
F_60 ( V_50 , V_124 ) ;
F_60 ( V_50 , V_110 << 16 | V_109 ) ;
F_62 ( V_50 ) ;
V_31 -> V_117 = V_109 ;
}
V_90 = V_12 -> V_125 ( V_50 , V_60 , V_107 , V_108 ) ;
if ( V_90 )
return V_90 ;
F_63 ( F_64 ( V_12 ) , V_108 ) ;
F_65 ( V_95 , V_12 ) ;
F_66 ( V_2 , V_104 , V_12 , V_106 ) ;
return 0 ;
}
void F_67 ( struct V_11 * V_12 )
{
struct V_53 * V_126 , * V_57 ;
struct V_30 * V_31 = V_12 -> V_2 -> V_32 ;
unsigned long V_80 ;
struct V_94 V_127 ;
F_2 ( ! F_68 ( & V_12 -> V_2 -> V_128 ) ) ;
if ( F_27 ( & V_12 -> V_63 ) )
return;
F_69 ( & V_127 ) ;
F_48 ( & V_12 -> V_58 , V_80 ) ;
F_70 ( & V_12 -> V_63 , & V_127 ) ;
F_51 ( & V_12 -> V_58 , V_80 ) ;
F_28 (req, tmp, &retired_list, execlist_link) {
struct V_41 * V_60 = V_126 -> V_60 ;
struct V_8 * V_9 =
V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ;
if ( V_9 && ( V_60 != V_12 -> V_82 ) )
F_71 ( V_12 , V_60 ) ;
F_72 ( V_31 ) ;
F_29 ( & V_126 -> V_62 ) ;
F_73 ( V_126 ) ;
}
}
void F_74 ( struct V_11 * V_12 )
{
struct V_30 * V_31 = V_12 -> V_2 -> V_32 ;
int V_90 ;
if ( ! F_75 ( V_12 ) )
return;
V_90 = F_76 ( V_12 ) ;
if ( V_90 && ! F_77 ( & F_78 ( V_12 -> V_2 ) -> V_129 ) )
F_79 ( L_13 ,
V_12 -> V_130 , V_90 ) ;
F_80 ( V_12 , F_81 ( V_131 ) ) ;
if ( F_82 ( ( F_83 ( V_12 ) & V_132 ) != 0 , 1000 ) ) {
F_79 ( L_14 , V_12 -> V_130 ) ;
return;
}
F_80 ( V_12 , F_84 ( V_131 ) ) ;
}
int F_85 ( struct V_48 * V_50 ,
struct V_41 * V_60 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
int V_90 ;
if ( ! V_12 -> V_91 )
return 0 ;
V_90 = V_12 -> V_93 ( V_50 , V_60 , 0 , V_92 ) ;
if ( V_90 )
return V_90 ;
V_12 -> V_91 = false ;
return 0 ;
}
static void
F_86 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
struct V_53 * V_79 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
F_62 ( V_50 ) ;
if ( F_87 ( V_12 ) )
return;
F_41 ( V_12 , V_60 , V_50 -> V_36 , V_79 ) ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
struct V_8 * V_9 = V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ;
struct V_48 * V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
int V_90 = 0 ;
F_2 ( ! F_68 ( & V_12 -> V_2 -> V_128 ) ) ;
if ( V_60 -> V_46 [ V_12 -> V_22 ] . V_133 ++ == 0 ) {
V_90 = F_88 ( V_9 ,
V_134 , 0 ) ;
if ( V_90 )
goto V_135;
V_90 = F_89 ( V_12 -> V_2 , V_50 ) ;
if ( V_90 )
goto V_136;
}
return V_90 ;
V_136:
F_90 ( V_9 ) ;
V_135:
V_60 -> V_46 [ V_12 -> V_22 ] . V_133 = 0 ;
return V_90 ;
}
void F_71 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
struct V_8 * V_9 = V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ;
struct V_48 * V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
if ( V_9 ) {
F_2 ( ! F_68 ( & V_12 -> V_2 -> V_128 ) ) ;
if ( -- V_60 -> V_46 [ V_12 -> V_22 ] . V_133 == 0 ) {
F_91 ( V_50 ) ;
F_90 ( V_9 ) ;
}
}
}
static int F_92 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
struct V_53 * V_79 ;
struct V_30 * V_32 = V_12 -> V_2 -> V_32 ;
int V_90 ;
if ( V_12 -> V_137 )
return 0 ;
V_79 = F_43 ( sizeof( * V_79 ) , V_83 ) ;
if ( V_79 == NULL )
return - V_84 ;
if ( V_60 != V_12 -> V_82 ) {
V_90 = F_42 ( V_12 , V_60 ) ;
if ( V_90 ) {
F_93 ( V_79 ) ;
return V_90 ;
}
}
F_44 ( & V_79 -> V_85 ) ;
V_79 -> V_12 = V_12 ;
V_79 -> V_86 = V_32 -> V_87 ++ ;
V_90 = F_94 ( V_12 -> V_2 , & V_79 -> V_138 ) ;
if ( V_90 ) {
F_71 ( V_12 , V_60 ) ;
F_93 ( V_79 ) ;
return V_90 ;
}
V_79 -> V_60 = V_60 ;
F_45 ( V_79 -> V_60 ) ;
V_79 -> V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
V_12 -> V_137 = V_79 ;
return 0 ;
}
static int F_95 ( struct V_48 * V_50 ,
int V_139 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_53 * V_79 ;
int V_90 ;
if ( F_96 ( V_50 ) >= V_139 )
return 0 ;
F_49 (request, &ring->request_list, list) {
struct V_41 * V_60 = V_79 -> V_60 ;
if ( V_60 -> V_46 [ V_12 -> V_22 ] . V_50 != V_50 )
continue;
if ( F_97 ( V_79 -> V_36 , V_50 -> V_36 ,
V_50 -> V_64 ) >= V_139 ) {
break;
}
}
if ( & V_79 -> V_140 == & V_12 -> V_141 )
return - V_142 ;
V_90 = F_98 ( V_79 ) ;
if ( V_90 )
return V_90 ;
F_99 ( V_12 ) ;
return F_96 ( V_50 ) >= V_139 ? 0 : - V_142 ;
}
static int F_100 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
int V_139 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
unsigned long V_143 ;
int V_90 ;
V_90 = F_95 ( V_50 , V_139 ) ;
if ( V_90 != - V_142 )
return V_90 ;
F_86 ( V_50 , V_60 , NULL ) ;
V_143 = V_144 + 60 * V_145 ;
V_90 = 0 ;
do {
if ( F_96 ( V_50 ) >= V_139 )
break;
F_101 ( 1 ) ;
if ( V_31 -> V_146 . V_147 && F_102 ( V_148 ) ) {
V_90 = - V_149 ;
break;
}
V_90 = F_103 ( & V_31 -> V_129 ,
V_31 -> V_146 . V_147 ) ;
if ( V_90 )
break;
if ( F_104 ( V_144 , V_143 ) ) {
V_90 = - V_150 ;
break;
}
} while ( 1 );
return V_90 ;
}
static int F_105 ( struct V_48 * V_50 ,
struct V_41 * V_60 )
{
T_3 T_5 * V_151 ;
int V_152 = V_50 -> V_64 - V_50 -> V_36 ;
if ( V_50 -> V_153 < V_152 ) {
int V_90 = F_100 ( V_50 , V_60 , V_152 ) ;
if ( V_90 )
return V_90 ;
}
V_151 = V_50 -> V_154 + V_50 -> V_36 ;
V_152 /= 4 ;
while ( V_152 -- )
F_106 ( V_123 , V_151 ++ ) ;
V_50 -> V_36 = 0 ;
F_107 ( V_50 ) ;
return 0 ;
}
static int F_108 ( struct V_48 * V_50 ,
struct V_41 * V_60 , int V_139 )
{
int V_90 ;
if ( F_109 ( V_50 -> V_36 + V_139 > V_50 -> V_155 ) ) {
V_90 = F_105 ( V_50 , V_60 ) ;
if ( F_109 ( V_90 ) )
return V_90 ;
}
if ( F_109 ( V_50 -> V_153 < V_139 ) ) {
V_90 = F_100 ( V_50 , V_60 , V_139 ) ;
if ( F_109 ( V_90 ) )
return V_90 ;
}
return 0 ;
}
int F_59 ( struct V_48 * V_50 ,
struct V_41 * V_60 , int V_156 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
int V_90 ;
V_90 = F_103 ( & V_31 -> V_129 ,
V_31 -> V_146 . V_147 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_108 ( V_50 , V_60 , V_156 * sizeof( T_3 ) ) ;
if ( V_90 )
return V_90 ;
V_90 = F_92 ( V_12 , V_60 ) ;
if ( V_90 )
return V_90 ;
V_50 -> V_153 -= V_156 * sizeof( T_3 ) ;
return 0 ;
}
static int F_110 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
int V_90 , V_157 ;
struct V_48 * V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_158 * V_159 = & V_31 -> V_160 ;
if ( F_111 ( V_159 -> V_161 == 0 ) )
return 0 ;
V_12 -> V_91 = true ;
V_90 = F_85 ( V_50 , V_60 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_59 ( V_50 , V_60 , V_159 -> V_161 * 2 + 2 ) ;
if ( V_90 )
return V_90 ;
F_60 ( V_50 , F_61 ( V_159 -> V_161 ) ) ;
for ( V_157 = 0 ; V_157 < V_159 -> V_161 ; V_157 ++ ) {
F_60 ( V_50 , V_159 -> V_162 [ V_157 ] . V_163 ) ;
F_60 ( V_50 , V_159 -> V_162 [ V_157 ] . V_164 ) ;
}
F_60 ( V_50 , V_123 ) ;
F_62 ( V_50 ) ;
V_12 -> V_91 = true ;
V_90 = F_85 ( V_50 , V_60 ) ;
if ( V_90 )
return V_90 ;
return 0 ;
}
static int F_112 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
F_113 ( V_12 , ~ ( V_12 -> V_165 | V_12 -> V_166 ) ) ;
F_13 ( F_114 ( V_12 -> V_167 ) , 0xffffffff ) ;
if ( V_12 -> V_168 . V_52 ) {
F_13 ( F_115 ( V_12 -> V_167 ) ,
( T_1 ) V_12 -> V_168 . V_169 ) ;
F_15 ( F_115 ( V_12 -> V_167 ) ) ;
}
F_13 ( F_116 ( V_12 ) ,
F_84 ( V_170 ) |
F_81 ( V_171 ) ) ;
F_15 ( F_116 ( V_12 ) ) ;
V_12 -> V_73 = 0 ;
F_117 ( L_15 , V_12 -> V_130 ) ;
memset ( & V_12 -> V_172 , 0 , sizeof( V_12 -> V_172 ) ) ;
return 0 ;
}
static int F_118 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
int V_90 ;
V_90 = F_112 ( V_12 ) ;
if ( V_90 )
return V_90 ;
F_13 ( V_173 , F_81 ( V_174 ) ) ;
F_13 ( V_124 , F_81 ( V_175 ) ) ;
return F_119 ( V_12 ) ;
}
static int F_120 ( struct V_11 * V_12 )
{
int V_90 ;
V_90 = F_112 ( V_12 ) ;
if ( V_90 )
return V_90 ;
return F_119 ( V_12 ) ;
}
static int F_121 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
V_19 V_176 , unsigned V_108 )
{
bool V_177 = ! ( V_108 & V_178 ) ;
int V_90 ;
V_90 = F_59 ( V_50 , V_60 , 4 ) ;
if ( V_90 )
return V_90 ;
F_60 ( V_50 , V_179 | ( V_177 << 8 ) ) ;
F_60 ( V_50 , F_122 ( V_176 ) ) ;
F_60 ( V_50 , F_123 ( V_176 ) ) ;
F_60 ( V_50 , V_123 ) ;
F_62 ( V_50 ) ;
return 0 ;
}
static bool F_124 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
unsigned long V_80 ;
if ( F_2 ( ! F_125 ( V_31 ) ) )
return false ;
F_48 ( & V_31 -> V_180 , V_80 ) ;
if ( V_12 -> V_181 ++ == 0 ) {
F_113 ( V_12 , ~ ( V_12 -> V_165 | V_12 -> V_166 ) ) ;
F_15 ( F_126 ( V_12 -> V_167 ) ) ;
}
F_51 ( & V_31 -> V_180 , V_80 ) ;
return true ;
}
static void F_127 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
unsigned long V_80 ;
F_48 ( & V_31 -> V_180 , V_80 ) ;
if ( -- V_12 -> V_181 == 0 ) {
F_113 ( V_12 , ~ V_12 -> V_166 ) ;
F_15 ( F_126 ( V_12 -> V_167 ) ) ;
}
F_51 ( & V_31 -> V_180 , V_80 ) ;
}
static int F_128 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
T_1 V_182 ,
T_1 V_183 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
T_3 V_184 ;
int V_90 ;
V_90 = F_59 ( V_50 , V_60 , 4 ) ;
if ( V_90 )
return V_90 ;
V_184 = V_185 + 1 ;
V_184 |= V_186 | V_187 ;
if ( V_182 & V_92 ) {
V_184 |= V_188 ;
if ( V_12 == & V_31 -> V_12 [ V_24 ] )
V_184 |= V_189 ;
}
F_60 ( V_50 , V_184 ) ;
F_60 ( V_50 ,
V_190 |
V_191 ) ;
F_60 ( V_50 , 0 ) ;
F_60 ( V_50 , 0 ) ;
F_62 ( V_50 ) ;
return 0 ;
}
static int F_129 ( struct V_48 * V_50 ,
struct V_41 * V_60 ,
T_1 V_182 ,
T_1 V_89 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
T_1 V_192 = V_12 -> V_193 . V_194 + 2 * V_195 ;
T_1 V_80 = 0 ;
int V_90 ;
V_80 |= V_196 ;
if ( V_89 ) {
V_80 |= V_197 ;
V_80 |= V_198 ;
}
if ( V_182 ) {
V_80 |= V_199 ;
V_80 |= V_200 ;
V_80 |= V_201 ;
V_80 |= V_202 ;
V_80 |= V_203 ;
V_80 |= V_204 ;
V_80 |= V_205 ;
V_80 |= V_206 ;
}
V_90 = F_59 ( V_50 , V_60 , 6 ) ;
if ( V_90 )
return V_90 ;
F_60 ( V_50 , F_130 ( 6 ) ) ;
F_60 ( V_50 , V_80 ) ;
F_60 ( V_50 , V_192 ) ;
F_60 ( V_50 , 0 ) ;
F_60 ( V_50 , 0 ) ;
F_60 ( V_50 , 0 ) ;
F_62 ( V_50 ) ;
return 0 ;
}
static T_1 F_131 ( struct V_11 * V_12 , bool V_207 )
{
return F_132 ( V_12 , V_208 ) ;
}
static void F_133 ( struct V_11 * V_12 , T_1 V_138 )
{
F_134 ( V_12 , V_208 , V_138 ) ;
}
static int F_135 ( struct V_48 * V_50 ,
struct V_53 * V_79 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
T_1 V_184 ;
int V_90 ;
V_90 = F_59 ( V_50 , V_79 -> V_60 , 8 ) ;
if ( V_90 )
return V_90 ;
V_184 = V_209 ;
V_184 |= V_210 ;
F_60 ( V_50 , V_184 ) ;
F_60 ( V_50 ,
( V_12 -> V_168 . V_169 +
( V_208 << V_211 ) ) ) ;
F_60 ( V_50 , 0 ) ;
F_60 ( V_50 ,
F_136 ( V_12 -> V_137 ) ) ;
F_60 ( V_50 , V_212 ) ;
F_60 ( V_50 , V_123 ) ;
F_86 ( V_50 , V_79 -> V_60 , V_79 ) ;
F_60 ( V_50 , V_123 ) ;
F_60 ( V_50 , V_123 ) ;
F_62 ( V_50 ) ;
return 0 ;
}
static int F_137 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
struct V_48 * V_50 = V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
struct V_213 V_214 ;
struct V_215 * V_216 = V_60 -> V_216 ;
struct V_103 * V_104 = V_216 ? V_216 -> V_104 : NULL ;
int V_90 ;
V_90 = F_138 ( V_12 , & V_214 ) ;
if ( V_90 )
return V_90 ;
if ( V_214 . V_217 == NULL )
return 0 ;
V_90 = V_12 -> V_125 ( V_50 ,
V_60 ,
V_214 . V_218 ,
V_178 ) ;
if ( V_90 )
goto V_219;
F_139 ( F_140 ( V_214 . V_52 ) , V_12 ) ;
V_90 = F_141 ( V_12 , V_104 , V_214 . V_52 ) ;
V_219:
F_142 ( & V_214 ) ;
return V_90 ;
}
static int F_143 ( struct V_11 * V_12 ,
struct V_41 * V_60 )
{
int V_90 ;
V_90 = F_110 ( V_12 , V_60 ) ;
if ( V_90 )
return V_90 ;
return F_137 ( V_12 , V_60 ) ;
}
void F_144 ( struct V_11 * V_12 )
{
struct V_30 * V_31 ;
if ( ! F_75 ( V_12 ) )
return;
V_31 = V_12 -> V_2 -> V_32 ;
F_74 ( V_12 ) ;
F_2 ( ( F_83 ( V_12 ) & V_132 ) == 0 ) ;
F_145 ( & V_12 -> V_137 , NULL ) ;
if ( V_12 -> V_220 )
V_12 -> V_220 ( V_12 ) ;
F_146 ( V_12 ) ;
if ( V_12 -> V_168 . V_52 ) {
F_147 ( F_148 ( V_12 -> V_168 . V_52 -> V_221 -> V_222 ) ) ;
V_12 -> V_168 . V_52 = NULL ;
}
}
static int F_149 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_90 ;
V_12 -> V_223 = NULL ;
V_12 -> V_2 = V_2 ;
F_69 ( & V_12 -> V_224 ) ;
F_69 ( & V_12 -> V_141 ) ;
F_150 ( & V_12 -> V_225 ) ;
F_69 ( & V_12 -> V_59 ) ;
F_69 ( & V_12 -> V_63 ) ;
F_151 ( & V_12 -> V_58 ) ;
V_90 = F_152 ( V_12 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_153 ( V_12 -> V_82 , V_12 ) ;
return V_90 ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 = & V_31 -> V_12 [ V_115 ] ;
int V_90 ;
V_12 -> V_130 = L_16 ;
V_12 -> V_22 = V_115 ;
V_12 -> V_167 = V_226 ;
V_12 -> V_165 =
V_227 << V_228 ;
V_12 -> V_166 =
V_229 << V_228 ;
if ( F_155 ( V_2 ) )
V_12 -> V_166 |= V_230 ;
if ( F_3 ( V_2 ) -> V_6 >= 9 )
V_12 -> V_231 = F_120 ;
else
V_12 -> V_231 = F_118 ;
V_12 -> V_232 = F_143 ;
V_12 -> V_220 = V_233 ;
V_12 -> V_234 = F_131 ;
V_12 -> V_235 = F_133 ;
V_12 -> V_236 = F_135 ;
V_12 -> V_93 = F_129 ;
V_12 -> V_237 = F_124 ;
V_12 -> V_238 = F_127 ;
V_12 -> V_125 = F_121 ;
V_12 -> V_2 = V_2 ;
V_90 = F_149 ( V_2 , V_12 ) ;
if ( V_90 )
return V_90 ;
return F_156 ( V_12 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 = & V_31 -> V_12 [ V_24 ] ;
V_12 -> V_130 = L_17 ;
V_12 -> V_22 = V_24 ;
V_12 -> V_167 = V_239 ;
V_12 -> V_165 =
V_227 << V_240 ;
V_12 -> V_166 =
V_229 << V_240 ;
V_12 -> V_231 = F_112 ;
V_12 -> V_234 = F_131 ;
V_12 -> V_235 = F_133 ;
V_12 -> V_236 = F_135 ;
V_12 -> V_93 = F_128 ;
V_12 -> V_237 = F_124 ;
V_12 -> V_238 = F_127 ;
V_12 -> V_125 = F_121 ;
return F_149 ( V_2 , V_12 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 = & V_31 -> V_12 [ V_26 ] ;
V_12 -> V_130 = L_18 ;
V_12 -> V_22 = V_26 ;
V_12 -> V_167 = V_241 ;
V_12 -> V_165 =
V_227 << V_242 ;
V_12 -> V_166 =
V_229 << V_242 ;
V_12 -> V_231 = F_112 ;
V_12 -> V_234 = F_131 ;
V_12 -> V_235 = F_133 ;
V_12 -> V_236 = F_135 ;
V_12 -> V_93 = F_128 ;
V_12 -> V_237 = F_124 ;
V_12 -> V_238 = F_127 ;
V_12 -> V_125 = F_121 ;
return F_149 ( V_2 , V_12 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 = & V_31 -> V_12 [ V_23 ] ;
V_12 -> V_130 = L_19 ;
V_12 -> V_22 = V_23 ;
V_12 -> V_167 = V_243 ;
V_12 -> V_165 =
V_227 << V_244 ;
V_12 -> V_166 =
V_229 << V_244 ;
V_12 -> V_231 = F_112 ;
V_12 -> V_234 = F_131 ;
V_12 -> V_235 = F_133 ;
V_12 -> V_236 = F_135 ;
V_12 -> V_93 = F_128 ;
V_12 -> V_237 = F_124 ;
V_12 -> V_238 = F_127 ;
V_12 -> V_125 = F_121 ;
return F_149 ( V_2 , V_12 ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 = & V_31 -> V_12 [ V_25 ] ;
V_12 -> V_130 = L_20 ;
V_12 -> V_22 = V_25 ;
V_12 -> V_167 = V_245 ;
V_12 -> V_165 =
V_227 << V_246 ;
V_12 -> V_166 =
V_229 << V_246 ;
V_12 -> V_231 = F_112 ;
V_12 -> V_234 = F_131 ;
V_12 -> V_235 = F_133 ;
V_12 -> V_236 = F_135 ;
V_12 -> V_93 = F_128 ;
V_12 -> V_237 = F_124 ;
V_12 -> V_238 = F_127 ;
V_12 -> V_125 = F_121 ;
return F_149 ( V_2 , V_12 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
int V_90 ;
V_90 = F_154 ( V_2 ) ;
if ( V_90 )
return V_90 ;
if ( F_162 ( V_2 ) ) {
V_90 = F_157 ( V_2 ) ;
if ( V_90 )
goto V_247;
}
if ( F_163 ( V_2 ) ) {
V_90 = F_159 ( V_2 ) ;
if ( V_90 )
goto V_248;
}
if ( F_164 ( V_2 ) ) {
V_90 = F_160 ( V_2 ) ;
if ( V_90 )
goto V_249;
}
if ( F_165 ( V_2 ) ) {
V_90 = F_158 ( V_2 ) ;
if ( V_90 )
goto V_250;
}
V_90 = F_166 ( V_2 , ( ( T_1 ) ~ 0 - 0x1000 ) ) ;
if ( V_90 )
goto V_251;
return 0 ;
V_251:
F_144 ( & V_31 -> V_12 [ V_26 ] ) ;
V_250:
F_144 ( & V_31 -> V_12 [ V_25 ] ) ;
V_249:
F_144 ( & V_31 -> V_12 [ V_23 ] ) ;
V_248:
F_144 ( & V_31 -> V_12 [ V_24 ] ) ;
V_247:
F_144 ( & V_31 -> V_12 [ V_115 ] ) ;
return V_90 ;
}
static T_1
F_167 ( struct V_1 * V_2 )
{
T_1 V_252 = 0 ;
if ( F_3 ( V_2 ) -> V_6 < 9 )
return 0 ;
if ( F_3 ( V_2 ) -> V_253 ) {
V_252 |= V_254 ;
V_252 |= F_3 ( V_2 ) -> V_255 <<
V_256 ;
V_252 |= V_257 ;
}
if ( F_3 ( V_2 ) -> V_258 ) {
V_252 |= V_259 ;
V_252 |= F_3 ( V_2 ) -> V_260 <<
V_261 ;
V_252 |= V_257 ;
}
if ( F_3 ( V_2 ) -> V_262 ) {
V_252 |= F_3 ( V_2 ) -> V_263 <<
V_264 ;
V_252 |= F_3 ( V_2 ) -> V_263 <<
V_265 ;
V_252 |= V_257 ;
}
return V_252 ;
}
static int
F_168 ( struct V_41 * V_60 , struct V_8 * V_9 ,
struct V_11 * V_12 , struct V_48 * V_50 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_266 * V_177 = V_60 -> V_177 ;
struct V_37 * V_37 ;
T_3 * V_38 ;
int V_90 ;
if ( ! V_177 )
V_177 = V_31 -> V_146 . V_267 ;
V_90 = F_169 ( V_9 , true ) ;
if ( V_90 ) {
F_117 ( L_21 ) ;
return V_90 ;
}
V_90 = F_170 ( V_9 ) ;
if ( V_90 ) {
F_117 ( L_22 ) ;
return V_90 ;
}
F_171 ( V_9 ) ;
V_37 = F_19 ( V_9 , 1 ) ;
V_38 = F_20 ( V_37 ) ;
if ( V_12 -> V_22 == V_115 )
V_38 [ V_268 ] = F_61 ( 14 ) ;
else
V_38 [ V_268 ] = F_61 ( 11 ) ;
V_38 [ V_268 ] |= V_269 ;
V_38 [ V_270 ] = F_172 ( V_12 ) ;
V_38 [ V_270 + 1 ] =
F_81 ( V_271 |
V_272 ) ;
V_38 [ V_273 ] = F_173 ( V_12 -> V_167 ) ;
V_38 [ V_273 + 1 ] = 0 ;
V_38 [ V_39 ] = F_174 ( V_12 -> V_167 ) ;
V_38 [ V_39 + 1 ] = 0 ;
V_38 [ V_40 ] = F_175 ( V_12 -> V_167 ) ;
V_38 [ V_274 ] = F_176 ( V_12 -> V_167 ) ;
V_38 [ V_274 + 1 ] =
( ( V_50 -> V_64 - V_275 ) & V_276 ) | V_277 ;
V_38 [ V_278 ] = V_12 -> V_167 + 0x168 ;
V_38 [ V_278 + 1 ] = 0 ;
V_38 [ V_279 ] = V_12 -> V_167 + 0x140 ;
V_38 [ V_279 + 1 ] = 0 ;
V_38 [ V_280 ] = V_12 -> V_167 + 0x110 ;
V_38 [ V_280 + 1 ] = ( 1 << 5 ) ;
V_38 [ V_281 ] = V_12 -> V_167 + 0x11c ;
V_38 [ V_281 + 1 ] = 0 ;
V_38 [ V_282 ] = V_12 -> V_167 + 0x114 ;
V_38 [ V_282 + 1 ] = 0 ;
V_38 [ V_283 ] = V_12 -> V_167 + 0x118 ;
V_38 [ V_283 + 1 ] = 0 ;
if ( V_12 -> V_22 == V_115 ) {
V_38 [ V_284 ] = V_12 -> V_167 + 0x1c0 ;
V_38 [ V_284 + 1 ] = 0 ;
V_38 [ V_285 ] = V_12 -> V_167 + 0x1c4 ;
V_38 [ V_285 + 1 ] = 0 ;
V_38 [ V_286 ] = V_12 -> V_167 + 0x1c8 ;
V_38 [ V_286 + 1 ] = 0 ;
}
V_38 [ V_287 ] = F_61 ( 9 ) ;
V_38 [ V_287 ] |= V_269 ;
V_38 [ V_288 ] = V_12 -> V_167 + 0x3a8 ;
V_38 [ V_288 + 1 ] = 0 ;
V_38 [ V_289 ] = F_177 ( V_12 , 3 ) ;
V_38 [ V_290 ] = F_178 ( V_12 , 3 ) ;
V_38 [ V_291 ] = F_177 ( V_12 , 2 ) ;
V_38 [ V_292 ] = F_178 ( V_12 , 2 ) ;
V_38 [ V_293 ] = F_177 ( V_12 , 1 ) ;
V_38 [ V_294 ] = F_178 ( V_12 , 1 ) ;
V_38 [ V_295 ] = F_177 ( V_12 , 0 ) ;
V_38 [ V_296 ] = F_178 ( V_12 , 0 ) ;
V_38 [ V_289 + 1 ] = F_123 ( V_177 -> V_297 . V_298 [ 3 ] -> V_299 ) ;
V_38 [ V_290 + 1 ] = F_122 ( V_177 -> V_297 . V_298 [ 3 ] -> V_299 ) ;
V_38 [ V_291 + 1 ] = F_123 ( V_177 -> V_297 . V_298 [ 2 ] -> V_299 ) ;
V_38 [ V_292 + 1 ] = F_122 ( V_177 -> V_297 . V_298 [ 2 ] -> V_299 ) ;
V_38 [ V_293 + 1 ] = F_123 ( V_177 -> V_297 . V_298 [ 1 ] -> V_299 ) ;
V_38 [ V_294 + 1 ] = F_122 ( V_177 -> V_297 . V_298 [ 1 ] -> V_299 ) ;
V_38 [ V_295 + 1 ] = F_123 ( V_177 -> V_297 . V_298 [ 0 ] -> V_299 ) ;
V_38 [ V_296 + 1 ] = F_122 ( V_177 -> V_297 . V_298 [ 0 ] -> V_299 ) ;
if ( V_12 -> V_22 == V_115 ) {
V_38 [ V_300 ] = F_61 ( 1 ) ;
V_38 [ V_301 ] = V_302 ;
V_38 [ V_301 + 1 ] = F_167 ( V_2 ) ;
}
F_21 ( V_38 ) ;
V_9 -> V_303 = 1 ;
F_179 ( V_37 ) ;
F_180 ( V_9 ) ;
return 0 ;
}
void F_181 ( struct V_41 * V_60 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_304 ; V_157 ++ ) {
struct V_8 * V_9 = V_60 -> V_46 [ V_157 ] . V_47 ;
if ( V_9 ) {
struct V_48 * V_50 =
V_60 -> V_46 [ V_157 ] . V_50 ;
struct V_11 * V_12 = V_50 -> V_12 ;
if ( V_60 == V_12 -> V_82 ) {
F_91 ( V_50 ) ;
F_90 ( V_9 ) ;
}
F_2 ( V_60 -> V_46 [ V_12 -> V_22 ] . V_133 ) ;
F_182 ( V_50 ) ;
F_93 ( V_50 ) ;
F_183 ( & V_9 -> V_99 ) ;
}
}
}
static T_3 F_184 ( struct V_11 * V_12 )
{
int V_90 = 0 ;
F_2 ( F_3 ( V_12 -> V_2 ) -> V_6 < 8 ) ;
switch ( V_12 -> V_22 ) {
case V_115 :
if ( F_3 ( V_12 -> V_2 ) -> V_6 >= 9 )
V_90 = V_305 ;
else
V_90 = V_306 ;
break;
case V_24 :
case V_23 :
case V_25 :
case V_26 :
V_90 = V_307 ;
break;
}
return V_90 ;
}
static void F_185 ( struct V_11 * V_12 ,
struct V_8 * V_308 )
{
struct V_30 * V_31 = V_12 -> V_2 -> V_32 ;
V_12 -> V_168 . V_169 = F_7 ( V_308 ) ;
V_12 -> V_168 . V_309 =
F_186 ( F_148 ( V_308 -> V_221 -> V_222 ) ) ;
V_12 -> V_168 . V_52 = V_308 ;
F_13 ( F_115 ( V_12 -> V_167 ) ,
( T_1 ) V_12 -> V_168 . V_169 ) ;
F_15 ( F_115 ( V_12 -> V_167 ) ) ;
}
int F_153 ( struct V_41 * V_60 ,
struct V_11 * V_12 )
{
const bool V_310 = ( V_60 == V_12 -> V_82 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_8 * V_9 ;
T_3 V_311 ;
struct V_48 * V_50 ;
int V_90 ;
F_2 ( V_60 -> V_312 . V_313 != NULL ) ;
F_2 ( V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ) ;
V_311 = F_187 ( F_184 ( V_12 ) , 4096 ) ;
V_9 = F_188 ( V_2 , V_311 ) ;
if ( F_189 ( V_9 ) ) {
V_90 = F_190 ( V_9 ) ;
F_117 ( L_23 , V_90 ) ;
return V_90 ;
}
if ( V_310 ) {
V_90 = F_88 ( V_9 , V_134 , 0 ) ;
if ( V_90 ) {
F_117 ( L_24 ,
V_90 ) ;
F_183 ( & V_9 -> V_99 ) ;
return V_90 ;
}
}
V_50 = F_43 ( sizeof( * V_50 ) , V_83 ) ;
if ( ! V_50 ) {
F_117 ( L_25 ,
V_12 -> V_130 ) ;
V_90 = - V_84 ;
goto V_314;
}
V_50 -> V_12 = V_12 ;
V_50 -> V_64 = 32 * V_275 ;
V_50 -> V_155 = V_50 -> V_64 ;
V_50 -> V_315 = 0 ;
V_50 -> V_36 = 0 ;
V_50 -> V_316 = - 1 ;
F_107 ( V_50 ) ;
if ( V_50 -> V_52 == NULL ) {
V_90 = F_191 ( V_2 , V_50 ) ;
if ( V_90 ) {
F_117 (
L_26 ,
V_12 -> V_130 , V_90 ) ;
goto V_317;
}
if ( V_310 ) {
V_90 = F_89 ( V_2 , V_50 ) ;
if ( V_90 ) {
F_79 (
L_27 ,
V_12 -> V_130 , V_90 ) ;
goto V_318;
}
}
}
V_90 = F_168 ( V_60 , V_9 , V_12 , V_50 ) ;
if ( V_90 ) {
F_117 ( L_28 , V_90 ) ;
goto error;
}
V_60 -> V_46 [ V_12 -> V_22 ] . V_50 = V_50 ;
V_60 -> V_46 [ V_12 -> V_22 ] . V_47 = V_9 ;
if ( V_60 == V_12 -> V_82 )
F_185 ( V_12 , V_9 ) ;
else if ( V_12 -> V_22 == V_115 && ! V_60 -> V_319 ) {
if ( V_12 -> V_232 ) {
V_90 = V_12 -> V_232 ( V_12 , V_60 ) ;
if ( V_90 ) {
F_79 ( L_29 , V_90 ) ;
V_60 -> V_46 [ V_12 -> V_22 ] . V_50 = NULL ;
V_60 -> V_46 [ V_12 -> V_22 ] . V_47 = NULL ;
goto error;
}
}
V_60 -> V_319 = true ;
}
return 0 ;
error:
if ( V_310 )
F_91 ( V_50 ) ;
V_318:
F_182 ( V_50 ) ;
V_317:
F_93 ( V_50 ) ;
V_314:
if ( V_310 )
F_90 ( V_9 ) ;
F_183 ( & V_9 -> V_99 ) ;
return V_90 ;
}
void F_192 ( struct V_1 * V_2 ,
struct V_41 * V_60 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_11 * V_12 ;
int V_157 ;
F_193 (ring, dev_priv, i) {
struct V_8 * V_9 =
V_60 -> V_46 [ V_12 -> V_22 ] . V_47 ;
struct V_48 * V_50 =
V_60 -> V_46 [ V_12 -> V_22 ] . V_50 ;
T_3 * V_38 ;
struct V_37 * V_37 ;
if ( ! V_9 )
continue;
if ( F_170 ( V_9 ) ) {
F_34 ( 1 , L_30 ) ;
continue;
}
V_37 = F_19 ( V_9 , 1 ) ;
V_38 = F_20 ( V_37 ) ;
V_38 [ V_273 + 1 ] = 0 ;
V_38 [ V_39 + 1 ] = 0 ;
F_21 ( V_38 ) ;
V_50 -> V_315 = 0 ;
V_50 -> V_36 = 0 ;
}
}
