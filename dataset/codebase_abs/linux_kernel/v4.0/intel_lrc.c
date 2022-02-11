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
static T_2 F_8 ( struct V_8 * V_9 )
{
T_2 V_11 ;
T_2 V_10 = F_7 ( V_9 ) ;
F_2 ( V_10 & 0xFFFFFFFF00000FFFULL ) ;
V_11 = V_12 ;
V_11 |= V_13 << V_14 ;
V_11 |= V_15 ;
V_11 |= V_16 ;
V_11 |= V_10 ;
V_11 |= ( V_17 ) F_6 ( V_9 ) << V_18 ;
return V_11 ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_8 * V_21 ,
struct V_8 * V_22 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_2 V_26 = 0 ;
T_3 V_11 [ 4 ] ;
if ( V_22 )
V_26 = F_8 ( V_22 ) ;
else
V_26 = 0 ;
V_11 [ 1 ] = ( T_1 ) ( V_26 >> 32 ) ;
V_11 [ 0 ] = ( T_1 ) V_26 ;
V_26 = F_8 ( V_21 ) ;
V_11 [ 3 ] = ( T_1 ) ( V_26 >> 32 ) ;
V_11 [ 2 ] = ( T_1 ) V_26 ;
F_10 ( V_24 , V_27 ) ;
F_11 ( F_12 ( V_20 ) , V_11 [ 1 ] ) ;
F_11 ( F_12 ( V_20 ) , V_11 [ 0 ] ) ;
F_11 ( F_12 ( V_20 ) , V_11 [ 3 ] ) ;
F_11 ( F_12 ( V_20 ) , V_11 [ 2 ] ) ;
F_13 ( F_14 ( V_20 ) ) ;
F_15 ( V_24 , V_27 ) ;
}
static int F_16 ( struct V_8 * V_9 ,
struct V_8 * V_28 ,
T_1 V_29 )
{
struct V_30 * V_30 ;
T_3 * V_31 ;
V_30 = F_17 ( V_9 , 1 ) ;
V_31 = F_18 ( V_30 ) ;
V_31 [ V_32 + 1 ] = V_29 ;
V_31 [ V_33 + 1 ] = F_7 ( V_28 ) ;
F_19 ( V_31 ) ;
return 0 ;
}
static void F_20 ( struct V_19 * V_20 ,
struct V_34 * V_35 , T_1 V_36 ,
struct V_34 * V_37 , T_1 V_38 )
{
struct V_8 * V_21 = V_35 -> V_39 [ V_20 -> V_40 ] . V_41 ;
struct V_42 * V_43 = V_35 -> V_39 [ V_20 -> V_40 ] . V_44 ;
struct V_8 * V_22 = NULL ;
struct V_42 * V_45 = NULL ;
F_21 ( ! V_21 ) ;
F_2 ( ! F_22 ( V_21 ) ) ;
F_2 ( ! F_22 ( V_43 -> V_46 ) ) ;
F_16 ( V_21 , V_43 -> V_46 , V_36 ) ;
if ( V_37 ) {
V_45 = V_37 -> V_39 [ V_20 -> V_40 ] . V_44 ;
V_22 = V_37 -> V_39 [ V_20 -> V_40 ] . V_41 ;
F_21 ( ! V_22 ) ;
F_2 ( ! F_22 ( V_22 ) ) ;
F_2 ( ! F_22 ( V_45 -> V_46 ) ) ;
F_16 ( V_22 , V_45 -> V_46 , V_38 ) ;
}
F_9 ( V_20 , V_21 , V_22 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_47 * V_48 = NULL , * V_49 = NULL ;
struct V_47 * V_50 = NULL , * V_51 = NULL ;
F_24 ( & V_20 -> V_52 ) ;
if ( F_25 ( & V_20 -> V_53 ) )
return;
F_26 (cursor, tmp, &ring->execlist_queue,
execlist_link) {
if ( ! V_48 ) {
V_48 = V_50 ;
} else if ( V_48 -> V_54 == V_50 -> V_54 ) {
V_50 -> V_55 = V_48 -> V_55 ;
F_27 ( & V_48 -> V_56 ) ;
F_28 ( & V_48 -> V_56 ,
& V_20 -> V_57 ) ;
V_48 = V_50 ;
} else {
V_49 = V_50 ;
break;
}
}
F_2 ( V_49 && V_49 -> V_55 ) ;
F_20 ( V_20 , V_48 -> V_54 , V_48 -> V_29 ,
V_49 ? V_49 -> V_54 : NULL ,
V_49 ? V_49 -> V_29 : 0 ) ;
V_48 -> V_55 ++ ;
if ( V_49 )
V_49 -> V_55 ++ ;
}
static bool F_29 ( struct V_19 * V_20 ,
T_1 V_58 )
{
struct V_47 * V_59 ;
F_24 ( & V_20 -> V_52 ) ;
V_59 = F_30 ( & V_20 -> V_53 ,
struct V_47 ,
V_56 ) ;
if ( V_59 != NULL ) {
struct V_8 * V_9 =
V_59 -> V_54 -> V_39 [ V_20 -> V_40 ] . V_41 ;
if ( F_6 ( V_9 ) == V_58 ) {
F_31 ( V_59 -> V_55 == 0 ,
L_1 ) ;
if ( -- V_59 -> V_55 <= 0 ) {
F_27 ( & V_59 -> V_56 ) ;
F_28 ( & V_59 -> V_56 ,
& V_20 -> V_57 ) ;
return true ;
}
}
}
return false ;
}
void F_32 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_2 -> V_25 ;
T_1 V_60 ;
T_4 V_61 ;
T_4 V_62 ;
T_1 V_63 ;
T_1 V_64 ;
T_1 V_65 = 0 ;
V_60 = F_33 ( F_34 ( V_20 ) ) ;
V_61 = V_20 -> V_66 ;
V_62 = V_60 & 0x07 ;
if ( V_61 > V_62 )
V_62 += 6 ;
F_35 ( & V_20 -> V_52 ) ;
while ( V_61 < V_62 ) {
V_61 ++ ;
V_63 = F_33 ( F_36 ( V_20 ) +
( V_61 % 6 ) * 8 ) ;
V_64 = F_33 ( F_36 ( V_20 ) +
( V_61 % 6 ) * 8 + 4 ) ;
if ( V_63 & V_67 ) {
if ( V_63 & V_68 ) {
if ( F_29 ( V_20 , V_64 ) )
F_31 ( 1 , L_2 ) ;
} else
F_31 ( 1 , L_3 ) ;
}
if ( ( V_63 & V_69 ) ||
( V_63 & V_70 ) ) {
if ( F_29 ( V_20 , V_64 ) )
V_65 ++ ;
}
}
if ( V_65 != 0 )
F_23 ( V_20 ) ;
F_37 ( & V_20 -> V_52 ) ;
F_31 ( V_65 > 2 , L_4 ) ;
V_20 -> V_66 = V_62 % 6 ;
F_11 ( F_34 ( V_20 ) ,
( ( T_1 ) V_20 -> V_66 & 0x07 ) << 8 ) ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_34 * V_71 ,
T_1 V_29 ,
struct V_47 * V_72 )
{
struct V_47 * V_50 ;
struct V_23 * V_24 = V_20 -> V_2 -> V_25 ;
unsigned long V_73 ;
int V_74 = 0 ;
if ( V_71 != V_20 -> V_75 )
F_39 ( V_20 , V_71 ) ;
if ( ! V_72 ) {
V_72 = F_40 ( sizeof( * V_72 ) , V_76 ) ;
if ( V_72 == NULL )
return - V_77 ;
V_72 -> V_20 = V_20 ;
V_72 -> V_54 = V_71 ;
F_41 ( & V_72 -> V_78 ) ;
V_72 -> V_79 = V_24 -> V_80 ++ ;
F_42 ( V_72 -> V_54 ) ;
} else {
F_43 ( V_72 ) ;
F_2 ( V_71 != V_72 -> V_54 ) ;
}
V_72 -> V_29 = V_29 ;
F_44 ( V_24 ) ;
F_45 ( & V_20 -> V_52 , V_73 ) ;
F_46 (cursor, &ring->execlist_queue, execlist_link)
if ( ++ V_74 > 2 )
break;
if ( V_74 > 2 ) {
struct V_47 * V_81 ;
V_81 = F_47 ( & V_20 -> V_53 ,
struct V_47 ,
V_56 ) ;
if ( V_71 == V_81 -> V_54 ) {
F_31 ( V_81 -> V_55 != 0 ,
L_5 ) ;
F_27 ( & V_81 -> V_56 ) ;
F_28 ( & V_81 -> V_56 ,
& V_20 -> V_57 ) ;
}
}
F_28 ( & V_72 -> V_56 , & V_20 -> V_53 ) ;
if ( V_74 == 0 )
F_23 ( V_20 ) ;
F_48 ( & V_20 -> V_52 , V_73 ) ;
return 0 ;
}
static int F_49 ( struct V_42 * V_44 ,
struct V_34 * V_54 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
T_3 V_82 ;
int V_83 ;
V_82 = 0 ;
if ( V_20 -> V_84 )
V_82 = V_85 ;
V_83 = V_20 -> V_86 ( V_44 , V_54 ,
V_85 , V_82 ) ;
if ( V_83 )
return V_83 ;
V_20 -> V_84 = false ;
return 0 ;
}
static int F_50 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
struct V_87 * V_88 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
struct V_89 * V_90 ;
T_3 V_82 = 0 ;
bool V_91 = false ;
int V_83 ;
F_46 (vma, vmas, exec_list) {
struct V_8 * V_46 = V_90 -> V_46 ;
V_83 = F_51 ( V_46 , V_20 ) ;
if ( V_83 )
return V_83 ;
if ( V_46 -> V_92 . V_93 & V_94 )
V_91 |= F_52 ( V_46 , false ) ;
V_82 |= V_46 -> V_92 . V_93 ;
}
if ( V_82 & V_95 )
F_53 () ;
return F_49 ( V_44 , V_54 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_96 * V_97 ,
struct V_19 * V_20 ,
struct V_34 * V_54 ,
struct V_98 * args ,
struct V_87 * V_88 ,
struct V_8 * V_99 ,
V_17 V_100 , T_1 V_73 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_42 * V_44 = V_54 -> V_39 [ V_20 -> V_40 ] . V_44 ;
int V_101 ;
T_1 V_102 ;
int V_83 ;
V_101 = args -> V_73 & V_103 ;
V_102 = V_103 ;
switch ( V_101 ) {
case V_104 :
case V_105 :
case V_106 :
if ( V_101 != 0 && V_20 != & V_24 -> V_20 [ V_107 ] ) {
F_55 ( L_6 ) ;
return - V_108 ;
}
if ( V_101 != V_24 -> V_109 ) {
if ( V_101 == V_106 ) {
F_55 ( L_7 ) ;
return - V_108 ;
}
V_102 &= ~ V_106 ;
}
break;
default:
F_55 ( L_8 , V_101 ) ;
return - V_108 ;
}
if ( args -> V_110 != 0 ) {
F_55 ( L_9 ) ;
return - V_108 ;
} else {
if ( args -> V_111 == 0xffffffff ) {
F_55 ( L_10 ) ;
args -> V_111 = 0 ;
}
if ( args -> V_112 || args -> V_111 || args -> V_113 ) {
F_55 ( L_11 ) ;
return - V_108 ;
}
}
if ( args -> V_73 & V_114 ) {
F_55 ( L_12 ) ;
return - V_108 ;
}
V_83 = F_50 ( V_44 , V_54 , V_88 ) ;
if ( V_83 )
return V_83 ;
if ( V_20 == & V_24 -> V_20 [ V_107 ] &&
V_101 != V_24 -> V_109 ) {
V_83 = F_56 ( V_44 , V_54 , 4 ) ;
if ( V_83 )
return V_83 ;
F_57 ( V_44 , V_115 ) ;
F_57 ( V_44 , F_58 ( 1 ) ) ;
F_57 ( V_44 , V_116 ) ;
F_57 ( V_44 , V_102 << 16 | V_101 ) ;
F_59 ( V_44 ) ;
V_24 -> V_109 = V_101 ;
}
V_83 = V_20 -> V_117 ( V_44 , V_54 , V_100 , V_73 ) ;
if ( V_83 )
return V_83 ;
F_60 ( V_88 , V_20 ) ;
F_61 ( V_2 , V_97 , V_20 , V_99 ) ;
return 0 ;
}
void F_62 ( struct V_19 * V_20 )
{
struct V_47 * V_118 , * V_51 ;
struct V_23 * V_24 = V_20 -> V_2 -> V_25 ;
unsigned long V_73 ;
struct V_87 V_119 ;
F_2 ( ! F_63 ( & V_20 -> V_2 -> V_120 ) ) ;
if ( F_25 ( & V_20 -> V_57 ) )
return;
F_64 ( & V_119 ) ;
F_45 ( & V_20 -> V_52 , V_73 ) ;
F_65 ( & V_20 -> V_57 , & V_119 ) ;
F_48 ( & V_20 -> V_52 , V_73 ) ;
F_26 (req, tmp, &retired_list, execlist_link) {
struct V_34 * V_54 = V_118 -> V_54 ;
struct V_8 * V_9 =
V_54 -> V_39 [ V_20 -> V_40 ] . V_41 ;
if ( V_9 && ( V_54 != V_20 -> V_75 ) )
F_66 ( V_20 , V_54 ) ;
F_67 ( V_24 ) ;
F_27 ( & V_118 -> V_56 ) ;
F_68 ( V_118 ) ;
}
}
void F_69 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_2 -> V_25 ;
int V_83 ;
if ( ! F_70 ( V_20 ) )
return;
V_83 = F_71 ( V_20 ) ;
if ( V_83 && ! F_72 ( & F_73 ( V_20 -> V_2 ) -> V_121 ) )
F_74 ( L_13 ,
V_20 -> V_122 , V_83 ) ;
F_75 ( V_20 , F_76 ( V_123 ) ) ;
if ( F_77 ( ( F_78 ( V_20 ) & V_124 ) != 0 , 1000 ) ) {
F_74 ( L_14 , V_20 -> V_122 ) ;
return;
}
F_75 ( V_20 , F_79 ( V_123 ) ) ;
}
int F_80 ( struct V_42 * V_44 ,
struct V_34 * V_54 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
int V_83 ;
if ( ! V_20 -> V_84 )
return 0 ;
V_83 = V_20 -> V_86 ( V_44 , V_54 , 0 , V_85 ) ;
if ( V_83 )
return V_83 ;
V_20 -> V_84 = false ;
return 0 ;
}
void F_81 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
struct V_47 * V_72 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
F_59 ( V_44 ) ;
if ( F_82 ( V_20 ) )
return;
F_38 ( V_20 , V_54 , V_44 -> V_29 , V_72 ) ;
}
static int F_39 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_39 [ V_20 -> V_40 ] . V_41 ;
struct V_42 * V_44 = V_54 -> V_39 [ V_20 -> V_40 ] . V_44 ;
int V_83 = 0 ;
F_2 ( ! F_63 ( & V_20 -> V_2 -> V_120 ) ) ;
if ( V_54 -> V_39 [ V_20 -> V_40 ] . V_125 ++ == 0 ) {
V_83 = F_83 ( V_9 ,
V_126 , 0 ) ;
if ( V_83 )
goto V_127;
V_83 = F_84 ( V_20 -> V_2 , V_44 ) ;
if ( V_83 )
goto V_128;
}
return V_83 ;
V_128:
F_85 ( V_9 ) ;
V_127:
V_54 -> V_39 [ V_20 -> V_40 ] . V_125 = 0 ;
return V_83 ;
}
void F_66 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_39 [ V_20 -> V_40 ] . V_41 ;
struct V_42 * V_44 = V_54 -> V_39 [ V_20 -> V_40 ] . V_44 ;
if ( V_9 ) {
F_2 ( ! F_63 ( & V_20 -> V_2 -> V_120 ) ) ;
if ( -- V_54 -> V_39 [ V_20 -> V_40 ] . V_125 == 0 ) {
F_86 ( V_44 ) ;
F_85 ( V_9 ) ;
}
}
}
static int F_87 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
struct V_47 * V_72 ;
struct V_23 * V_25 = V_20 -> V_2 -> V_25 ;
int V_83 ;
if ( V_20 -> V_129 )
return 0 ;
V_72 = F_40 ( sizeof( * V_72 ) , V_76 ) ;
if ( V_72 == NULL )
return - V_77 ;
if ( V_54 != V_20 -> V_75 ) {
V_83 = F_39 ( V_20 , V_54 ) ;
if ( V_83 ) {
F_88 ( V_72 ) ;
return V_83 ;
}
}
F_41 ( & V_72 -> V_78 ) ;
V_72 -> V_20 = V_20 ;
V_72 -> V_79 = V_25 -> V_80 ++ ;
V_83 = F_89 ( V_20 -> V_2 , & V_72 -> V_130 ) ;
if ( V_83 ) {
F_66 ( V_20 , V_54 ) ;
F_88 ( V_72 ) ;
return V_83 ;
}
V_72 -> V_54 = V_54 ;
F_42 ( V_72 -> V_54 ) ;
V_20 -> V_129 = V_72 ;
return 0 ;
}
static int F_90 ( struct V_42 * V_44 ,
int V_131 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
struct V_47 * V_72 ;
int V_83 ;
if ( F_91 ( V_44 ) >= V_131 )
return 0 ;
F_46 (request, &ring->request_list, list) {
struct V_34 * V_54 = V_72 -> V_54 ;
if ( V_54 -> V_39 [ V_20 -> V_40 ] . V_44 != V_44 )
continue;
if ( F_92 ( V_72 -> V_29 , V_44 -> V_29 ,
V_44 -> V_132 ) >= V_131 ) {
break;
}
}
if ( & V_72 -> V_133 == & V_20 -> V_134 )
return - V_135 ;
V_83 = F_93 ( V_72 ) ;
if ( V_83 )
return V_83 ;
F_94 ( V_20 ) ;
return F_91 ( V_44 ) >= V_131 ? 0 : - V_135 ;
}
static int F_95 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
int V_131 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned long V_136 ;
int V_83 ;
V_83 = F_90 ( V_44 , V_131 ) ;
if ( V_83 != - V_135 )
return V_83 ;
F_81 ( V_44 , V_54 , NULL ) ;
V_136 = V_137 + 60 * V_138 ;
V_83 = 0 ;
do {
if ( F_91 ( V_44 ) >= V_131 )
break;
F_96 ( 1 ) ;
if ( V_24 -> V_139 . V_140 && F_97 ( V_141 ) ) {
V_83 = - V_142 ;
break;
}
V_83 = F_98 ( & V_24 -> V_121 ,
V_24 -> V_139 . V_140 ) ;
if ( V_83 )
break;
if ( F_99 ( V_137 , V_136 ) ) {
V_83 = - V_143 ;
break;
}
} while ( 1 );
return V_83 ;
}
static int F_100 ( struct V_42 * V_44 ,
struct V_34 * V_54 )
{
T_3 T_5 * V_144 ;
int V_145 = V_44 -> V_132 - V_44 -> V_29 ;
if ( V_44 -> V_146 < V_145 ) {
int V_83 = F_95 ( V_44 , V_54 , V_145 ) ;
if ( V_83 )
return V_83 ;
}
V_144 = V_44 -> V_147 + V_44 -> V_29 ;
V_145 /= 4 ;
while ( V_145 -- )
F_101 ( V_115 , V_144 ++ ) ;
V_44 -> V_29 = 0 ;
F_102 ( V_44 ) ;
return 0 ;
}
static int F_103 ( struct V_42 * V_44 ,
struct V_34 * V_54 , int V_131 )
{
int V_83 ;
if ( F_104 ( V_44 -> V_29 + V_131 > V_44 -> V_148 ) ) {
V_83 = F_100 ( V_44 , V_54 ) ;
if ( F_104 ( V_83 ) )
return V_83 ;
}
if ( F_104 ( V_44 -> V_146 < V_131 ) ) {
V_83 = F_95 ( V_44 , V_54 , V_131 ) ;
if ( F_104 ( V_83 ) )
return V_83 ;
}
return 0 ;
}
int F_56 ( struct V_42 * V_44 ,
struct V_34 * V_54 , int V_149 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_83 ;
V_83 = F_98 ( & V_24 -> V_121 ,
V_24 -> V_139 . V_140 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_103 ( V_44 , V_54 , V_149 * sizeof( T_3 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_87 ( V_20 , V_54 ) ;
if ( V_83 )
return V_83 ;
V_44 -> V_146 -= V_149 * sizeof( T_3 ) ;
return 0 ;
}
static int F_105 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
int V_83 , V_150 ;
struct V_42 * V_44 = V_54 -> V_39 [ V_20 -> V_40 ] . V_44 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_151 * V_152 = & V_24 -> V_153 ;
if ( F_106 ( V_152 -> V_154 == 0 ) )
return 0 ;
V_20 -> V_84 = true ;
V_83 = F_80 ( V_44 , V_54 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_56 ( V_44 , V_54 , V_152 -> V_154 * 2 + 2 ) ;
if ( V_83 )
return V_83 ;
F_57 ( V_44 , F_58 ( V_152 -> V_154 ) ) ;
for ( V_150 = 0 ; V_150 < V_152 -> V_154 ; V_150 ++ ) {
F_57 ( V_44 , V_152 -> V_155 [ V_150 ] . V_156 ) ;
F_57 ( V_44 , V_152 -> V_155 [ V_150 ] . V_157 ) ;
}
F_57 ( V_44 , V_115 ) ;
F_59 ( V_44 ) ;
V_20 -> V_84 = true ;
V_83 = F_80 ( V_44 , V_54 ) ;
if ( V_83 )
return V_83 ;
return 0 ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
F_108 ( V_20 , ~ ( V_20 -> V_158 | V_20 -> V_159 ) ) ;
F_11 ( F_109 ( V_20 -> V_160 ) , 0xffffffff ) ;
F_11 ( F_110 ( V_20 ) ,
F_79 ( V_161 ) |
F_76 ( V_162 ) ) ;
F_13 ( F_110 ( V_20 ) ) ;
V_20 -> V_66 = 0 ;
F_111 ( L_15 , V_20 -> V_122 ) ;
memset ( & V_20 -> V_163 , 0 , sizeof( V_20 -> V_163 ) ) ;
return 0 ;
}
static int F_112 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_83 ;
V_83 = F_107 ( V_20 ) ;
if ( V_83 )
return V_83 ;
F_11 ( V_164 , F_76 ( V_165 ) ) ;
F_11 ( V_116 , F_76 ( V_166 ) ) ;
return F_113 ( V_20 ) ;
}
static int F_114 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
V_17 V_167 , unsigned V_73 )
{
bool V_168 = ! ( V_73 & V_169 ) ;
int V_83 ;
V_83 = F_56 ( V_44 , V_54 , 4 ) ;
if ( V_83 )
return V_83 ;
F_57 ( V_44 , V_170 | ( V_168 << 8 ) ) ;
F_57 ( V_44 , F_115 ( V_167 ) ) ;
F_57 ( V_44 , F_116 ( V_167 ) ) ;
F_57 ( V_44 , V_115 ) ;
F_59 ( V_44 ) ;
return 0 ;
}
static bool F_117 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned long V_73 ;
if ( F_2 ( ! F_118 ( V_24 ) ) )
return false ;
F_45 ( & V_24 -> V_171 , V_73 ) ;
if ( V_20 -> V_172 ++ == 0 ) {
F_108 ( V_20 , ~ ( V_20 -> V_158 | V_20 -> V_159 ) ) ;
F_13 ( F_119 ( V_20 -> V_160 ) ) ;
}
F_48 ( & V_24 -> V_171 , V_73 ) ;
return true ;
}
static void F_120 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned long V_73 ;
F_45 ( & V_24 -> V_171 , V_73 ) ;
if ( -- V_20 -> V_172 == 0 ) {
F_108 ( V_20 , ~ V_20 -> V_159 ) ;
F_13 ( F_119 ( V_20 -> V_160 ) ) ;
}
F_48 ( & V_24 -> V_171 , V_73 ) ;
}
static int F_121 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
T_1 V_173 ,
T_1 V_174 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
T_3 V_175 ;
int V_83 ;
V_83 = F_56 ( V_44 , V_54 , 4 ) ;
if ( V_83 )
return V_83 ;
V_175 = V_176 + 1 ;
V_175 |= V_177 | V_178 ;
if ( V_173 & V_85 ) {
V_175 |= V_179 ;
if ( V_20 == & V_24 -> V_20 [ V_180 ] )
V_175 |= V_181 ;
}
F_57 ( V_44 , V_175 ) ;
F_57 ( V_44 ,
V_182 |
V_183 ) ;
F_57 ( V_44 , 0 ) ;
F_57 ( V_44 , 0 ) ;
F_59 ( V_44 ) ;
return 0 ;
}
static int F_122 ( struct V_42 * V_44 ,
struct V_34 * V_54 ,
T_1 V_173 ,
T_1 V_82 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
T_1 V_184 = V_20 -> V_185 . V_186 + 2 * V_187 ;
T_1 V_73 = 0 ;
int V_83 ;
V_73 |= V_188 ;
if ( V_82 ) {
V_73 |= V_189 ;
V_73 |= V_190 ;
}
if ( V_173 ) {
V_73 |= V_191 ;
V_73 |= V_192 ;
V_73 |= V_193 ;
V_73 |= V_194 ;
V_73 |= V_195 ;
V_73 |= V_196 ;
V_73 |= V_197 ;
V_73 |= V_198 ;
}
V_83 = F_56 ( V_44 , V_54 , 6 ) ;
if ( V_83 )
return V_83 ;
F_57 ( V_44 , F_123 ( 6 ) ) ;
F_57 ( V_44 , V_73 ) ;
F_57 ( V_44 , V_184 ) ;
F_57 ( V_44 , 0 ) ;
F_57 ( V_44 , 0 ) ;
F_57 ( V_44 , 0 ) ;
F_59 ( V_44 ) ;
return 0 ;
}
static T_1 F_124 ( struct V_19 * V_20 , bool V_199 )
{
return F_125 ( V_20 , V_200 ) ;
}
static void F_126 ( struct V_19 * V_20 , T_1 V_130 )
{
F_127 ( V_20 , V_200 , V_130 ) ;
}
static int F_128 ( struct V_42 * V_44 ,
struct V_47 * V_72 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
T_1 V_175 ;
int V_83 ;
V_83 = F_56 ( V_44 , V_72 -> V_54 , 6 ) ;
if ( V_83 )
return V_83 ;
V_175 = V_201 ;
V_175 |= V_202 ;
F_57 ( V_44 , V_175 ) ;
F_57 ( V_44 ,
( V_20 -> V_203 . V_204 +
( V_200 << V_205 ) ) ) ;
F_57 ( V_44 , 0 ) ;
F_57 ( V_44 ,
F_129 ( V_20 -> V_129 ) ) ;
F_57 ( V_44 , V_206 ) ;
F_57 ( V_44 , V_115 ) ;
F_81 ( V_44 , V_72 -> V_54 , V_72 ) ;
return 0 ;
}
static int F_130 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
int V_83 ;
V_83 = F_105 ( V_20 , V_54 ) ;
if ( V_83 )
return V_83 ;
return F_131 ( V_20 , V_54 ) ;
}
void F_132 ( struct V_19 * V_20 )
{
struct V_23 * V_24 ;
if ( ! F_70 ( V_20 ) )
return;
V_24 = V_20 -> V_2 -> V_25 ;
F_69 ( V_20 ) ;
F_2 ( ( F_78 ( V_20 ) & V_124 ) == 0 ) ;
F_133 ( & V_20 -> V_129 , NULL ) ;
if ( V_20 -> V_207 )
V_20 -> V_207 ( V_20 ) ;
F_134 ( V_20 ) ;
if ( V_20 -> V_203 . V_46 ) {
F_135 ( F_136 ( V_20 -> V_203 . V_46 -> V_208 -> V_209 ) ) ;
V_20 -> V_203 . V_46 = NULL ;
}
}
static int F_137 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_83 ;
V_20 -> V_210 = NULL ;
V_20 -> V_2 = V_2 ;
F_64 ( & V_20 -> V_211 ) ;
F_64 ( & V_20 -> V_134 ) ;
F_138 ( & V_20 -> V_212 ) ;
F_64 ( & V_20 -> V_53 ) ;
F_64 ( & V_20 -> V_57 ) ;
F_139 ( & V_20 -> V_52 ) ;
V_83 = F_140 ( V_20 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_141 ( V_20 -> V_75 , V_20 ) ;
return V_83 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_19 * V_20 = & V_24 -> V_20 [ V_107 ] ;
int V_83 ;
V_20 -> V_122 = L_16 ;
V_20 -> V_40 = V_107 ;
V_20 -> V_160 = V_213 ;
V_20 -> V_158 =
V_214 << V_215 ;
V_20 -> V_159 =
V_216 << V_215 ;
if ( F_143 ( V_2 ) )
V_20 -> V_159 |= V_217 ;
V_20 -> V_218 = F_112 ;
V_20 -> V_219 = F_130 ;
V_20 -> V_207 = V_220 ;
V_20 -> V_221 = F_124 ;
V_20 -> V_222 = F_126 ;
V_20 -> V_223 = F_128 ;
V_20 -> V_86 = F_122 ;
V_20 -> V_224 = F_117 ;
V_20 -> V_225 = F_120 ;
V_20 -> V_117 = F_114 ;
V_20 -> V_2 = V_2 ;
V_83 = F_137 ( V_2 , V_20 ) ;
if ( V_83 )
return V_83 ;
return F_144 ( V_20 ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_19 * V_20 = & V_24 -> V_20 [ V_180 ] ;
V_20 -> V_122 = L_17 ;
V_20 -> V_40 = V_180 ;
V_20 -> V_160 = V_226 ;
V_20 -> V_158 =
V_214 << V_227 ;
V_20 -> V_159 =
V_216 << V_227 ;
V_20 -> V_218 = F_107 ;
V_20 -> V_221 = F_124 ;
V_20 -> V_222 = F_126 ;
V_20 -> V_223 = F_128 ;
V_20 -> V_86 = F_121 ;
V_20 -> V_224 = F_117 ;
V_20 -> V_225 = F_120 ;
V_20 -> V_117 = F_114 ;
return F_137 ( V_2 , V_20 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_19 * V_20 = & V_24 -> V_20 [ V_228 ] ;
V_20 -> V_122 = L_18 ;
V_20 -> V_40 = V_228 ;
V_20 -> V_160 = V_229 ;
V_20 -> V_158 =
V_214 << V_230 ;
V_20 -> V_159 =
V_216 << V_230 ;
V_20 -> V_218 = F_107 ;
V_20 -> V_221 = F_124 ;
V_20 -> V_222 = F_126 ;
V_20 -> V_223 = F_128 ;
V_20 -> V_86 = F_121 ;
V_20 -> V_224 = F_117 ;
V_20 -> V_225 = F_120 ;
V_20 -> V_117 = F_114 ;
return F_137 ( V_2 , V_20 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_19 * V_20 = & V_24 -> V_20 [ V_231 ] ;
V_20 -> V_122 = L_19 ;
V_20 -> V_40 = V_231 ;
V_20 -> V_160 = V_232 ;
V_20 -> V_158 =
V_214 << V_233 ;
V_20 -> V_159 =
V_216 << V_233 ;
V_20 -> V_218 = F_107 ;
V_20 -> V_221 = F_124 ;
V_20 -> V_222 = F_126 ;
V_20 -> V_223 = F_128 ;
V_20 -> V_86 = F_121 ;
V_20 -> V_224 = F_117 ;
V_20 -> V_225 = F_120 ;
V_20 -> V_117 = F_114 ;
return F_137 ( V_2 , V_20 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_19 * V_20 = & V_24 -> V_20 [ V_234 ] ;
V_20 -> V_122 = L_20 ;
V_20 -> V_40 = V_234 ;
V_20 -> V_160 = V_235 ;
V_20 -> V_158 =
V_214 << V_236 ;
V_20 -> V_159 =
V_216 << V_236 ;
V_20 -> V_218 = F_107 ;
V_20 -> V_221 = F_124 ;
V_20 -> V_222 = F_126 ;
V_20 -> V_223 = F_128 ;
V_20 -> V_86 = F_121 ;
V_20 -> V_224 = F_117 ;
V_20 -> V_225 = F_120 ;
V_20 -> V_117 = F_114 ;
return F_137 ( V_2 , V_20 ) ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_83 ;
V_83 = F_142 ( V_2 ) ;
if ( V_83 )
return V_83 ;
if ( F_150 ( V_2 ) ) {
V_83 = F_145 ( V_2 ) ;
if ( V_83 )
goto V_237;
}
if ( F_151 ( V_2 ) ) {
V_83 = F_147 ( V_2 ) ;
if ( V_83 )
goto V_238;
}
if ( F_152 ( V_2 ) ) {
V_83 = F_148 ( V_2 ) ;
if ( V_83 )
goto V_239;
}
if ( F_153 ( V_2 ) ) {
V_83 = F_146 ( V_2 ) ;
if ( V_83 )
goto V_240;
}
V_83 = F_154 ( V_2 , ( ( T_1 ) ~ 0 - 0x1000 ) ) ;
if ( V_83 )
goto V_241;
return 0 ;
V_241:
F_132 ( & V_24 -> V_20 [ V_228 ] ) ;
V_240:
F_132 ( & V_24 -> V_20 [ V_234 ] ) ;
V_239:
F_132 ( & V_24 -> V_20 [ V_231 ] ) ;
V_238:
F_132 ( & V_24 -> V_20 [ V_180 ] ) ;
V_237:
F_132 ( & V_24 -> V_20 [ V_107 ] ) ;
return V_83 ;
}
int F_131 ( struct V_19 * V_20 ,
struct V_34 * V_54 )
{
struct V_42 * V_44 = V_54 -> V_39 [ V_20 -> V_40 ] . V_44 ;
struct V_242 V_243 ;
struct V_244 * V_245 = V_54 -> V_245 ;
struct V_96 * V_97 = V_245 ? V_245 -> V_97 : NULL ;
int V_83 ;
V_83 = F_155 ( V_20 , & V_243 ) ;
if ( V_83 )
return V_83 ;
if ( V_243 . V_246 == NULL )
return 0 ;
V_83 = V_20 -> V_117 ( V_44 ,
V_54 ,
V_243 . V_247 ,
V_169 ) ;
if ( V_83 )
goto V_248;
F_156 ( F_157 ( V_243 . V_46 ) , V_20 ) ;
V_83 = F_158 ( V_20 , V_97 , V_243 . V_46 ) ;
V_248:
F_159 ( & V_243 ) ;
return V_83 ;
}
static int
F_160 ( struct V_34 * V_54 , struct V_8 * V_9 ,
struct V_19 * V_20 , struct V_42 * V_44 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_249 * V_168 = V_54 -> V_168 ;
struct V_30 * V_30 ;
T_3 * V_31 ;
int V_83 ;
if ( ! V_168 )
V_168 = V_24 -> V_139 . V_250 ;
V_83 = F_161 ( V_9 , true ) ;
if ( V_83 ) {
F_111 ( L_21 ) ;
return V_83 ;
}
V_83 = F_162 ( V_9 ) ;
if ( V_83 ) {
F_111 ( L_22 ) ;
return V_83 ;
}
F_163 ( V_9 ) ;
V_30 = F_17 ( V_9 , 1 ) ;
V_31 = F_18 ( V_30 ) ;
if ( V_20 -> V_40 == V_107 )
V_31 [ V_251 ] = F_58 ( 14 ) ;
else
V_31 [ V_251 ] = F_58 ( 11 ) ;
V_31 [ V_251 ] |= V_252 ;
V_31 [ V_253 ] = F_164 ( V_20 ) ;
V_31 [ V_253 + 1 ] =
F_76 ( ( 1 << 3 ) | V_254 ) ;
V_31 [ V_255 ] = F_165 ( V_20 -> V_160 ) ;
V_31 [ V_255 + 1 ] = 0 ;
V_31 [ V_32 ] = F_166 ( V_20 -> V_160 ) ;
V_31 [ V_32 + 1 ] = 0 ;
V_31 [ V_33 ] = F_167 ( V_20 -> V_160 ) ;
V_31 [ V_256 ] = F_168 ( V_20 -> V_160 ) ;
V_31 [ V_256 + 1 ] =
( ( V_44 -> V_132 - V_257 ) & V_258 ) | V_259 ;
V_31 [ V_260 ] = V_20 -> V_160 + 0x168 ;
V_31 [ V_260 + 1 ] = 0 ;
V_31 [ V_261 ] = V_20 -> V_160 + 0x140 ;
V_31 [ V_261 + 1 ] = 0 ;
V_31 [ V_262 ] = V_20 -> V_160 + 0x110 ;
V_31 [ V_262 + 1 ] = ( 1 << 5 ) ;
V_31 [ V_263 ] = V_20 -> V_160 + 0x11c ;
V_31 [ V_263 + 1 ] = 0 ;
V_31 [ V_264 ] = V_20 -> V_160 + 0x114 ;
V_31 [ V_264 + 1 ] = 0 ;
V_31 [ V_265 ] = V_20 -> V_160 + 0x118 ;
V_31 [ V_265 + 1 ] = 0 ;
if ( V_20 -> V_40 == V_107 ) {
V_31 [ V_266 ] = V_20 -> V_160 + 0x1c0 ;
V_31 [ V_266 + 1 ] = 0 ;
V_31 [ V_267 ] = V_20 -> V_160 + 0x1c4 ;
V_31 [ V_267 + 1 ] = 0 ;
V_31 [ V_268 ] = V_20 -> V_160 + 0x1c8 ;
V_31 [ V_268 + 1 ] = 0 ;
}
V_31 [ V_269 ] = F_58 ( 9 ) ;
V_31 [ V_269 ] |= V_252 ;
V_31 [ V_270 ] = V_20 -> V_160 + 0x3a8 ;
V_31 [ V_270 + 1 ] = 0 ;
V_31 [ V_271 ] = F_169 ( V_20 , 3 ) ;
V_31 [ V_272 ] = F_170 ( V_20 , 3 ) ;
V_31 [ V_273 ] = F_169 ( V_20 , 2 ) ;
V_31 [ V_274 ] = F_170 ( V_20 , 2 ) ;
V_31 [ V_275 ] = F_169 ( V_20 , 1 ) ;
V_31 [ V_276 ] = F_170 ( V_20 , 1 ) ;
V_31 [ V_277 ] = F_169 ( V_20 , 0 ) ;
V_31 [ V_278 ] = F_170 ( V_20 , 0 ) ;
V_31 [ V_271 + 1 ] = F_116 ( V_168 -> V_279 [ 3 ] ) ;
V_31 [ V_272 + 1 ] = F_115 ( V_168 -> V_279 [ 3 ] ) ;
V_31 [ V_273 + 1 ] = F_116 ( V_168 -> V_279 [ 2 ] ) ;
V_31 [ V_274 + 1 ] = F_115 ( V_168 -> V_279 [ 2 ] ) ;
V_31 [ V_275 + 1 ] = F_116 ( V_168 -> V_279 [ 1 ] ) ;
V_31 [ V_276 + 1 ] = F_115 ( V_168 -> V_279 [ 1 ] ) ;
V_31 [ V_277 + 1 ] = F_116 ( V_168 -> V_279 [ 0 ] ) ;
V_31 [ V_278 + 1 ] = F_115 ( V_168 -> V_279 [ 0 ] ) ;
if ( V_20 -> V_40 == V_107 ) {
V_31 [ V_280 ] = F_58 ( 1 ) ;
V_31 [ V_281 ] = 0x20c8 ;
V_31 [ V_281 + 1 ] = 0 ;
}
F_19 ( V_31 ) ;
V_9 -> V_282 = 1 ;
F_171 ( V_30 ) ;
F_172 ( V_9 ) ;
return 0 ;
}
void F_173 ( struct V_34 * V_54 )
{
int V_150 ;
for ( V_150 = 0 ; V_150 < V_283 ; V_150 ++ ) {
struct V_8 * V_9 = V_54 -> V_39 [ V_150 ] . V_41 ;
if ( V_9 ) {
struct V_42 * V_44 =
V_54 -> V_39 [ V_150 ] . V_44 ;
struct V_19 * V_20 = V_44 -> V_20 ;
if ( V_54 == V_20 -> V_75 ) {
F_86 ( V_44 ) ;
F_85 ( V_9 ) ;
}
F_2 ( V_54 -> V_39 [ V_20 -> V_40 ] . V_125 ) ;
F_174 ( V_44 ) ;
F_88 ( V_44 ) ;
F_175 ( & V_9 -> V_92 ) ;
}
}
}
static T_3 F_176 ( struct V_19 * V_20 )
{
int V_83 = 0 ;
F_2 ( F_3 ( V_20 -> V_2 ) -> V_6 < 8 ) ;
switch ( V_20 -> V_40 ) {
case V_107 :
if ( F_3 ( V_20 -> V_2 ) -> V_6 >= 9 )
V_83 = V_284 ;
else
V_83 = V_285 ;
break;
case V_180 :
case V_231 :
case V_234 :
case V_228 :
V_83 = V_286 ;
break;
}
return V_83 ;
}
static void F_177 ( struct V_19 * V_20 ,
struct V_8 * V_287 )
{
struct V_23 * V_24 = V_20 -> V_2 -> V_25 ;
V_20 -> V_203 . V_204 = F_7 ( V_287 ) ;
V_20 -> V_203 . V_288 =
F_178 ( F_136 ( V_287 -> V_208 -> V_209 ) ) ;
V_20 -> V_203 . V_46 = V_287 ;
F_11 ( F_179 ( V_20 -> V_160 ) ,
( T_1 ) V_20 -> V_203 . V_204 ) ;
F_13 ( F_179 ( V_20 -> V_160 ) ) ;
}
int F_141 ( struct V_34 * V_54 ,
struct V_19 * V_20 )
{
const bool V_289 = ( V_54 == V_20 -> V_75 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_8 * V_9 ;
T_3 V_290 ;
struct V_42 * V_44 ;
int V_83 ;
F_2 ( V_54 -> V_291 . V_292 != NULL ) ;
F_2 ( V_54 -> V_39 [ V_20 -> V_40 ] . V_41 ) ;
V_290 = F_180 ( F_176 ( V_20 ) , 4096 ) ;
V_9 = F_181 ( V_2 , V_290 ) ;
if ( F_182 ( V_9 ) ) {
V_83 = F_183 ( V_9 ) ;
F_111 ( L_23 , V_83 ) ;
return V_83 ;
}
if ( V_289 ) {
V_83 = F_83 ( V_9 , V_126 , 0 ) ;
if ( V_83 ) {
F_111 ( L_24 ,
V_83 ) ;
F_175 ( & V_9 -> V_92 ) ;
return V_83 ;
}
}
V_44 = F_40 ( sizeof( * V_44 ) , V_76 ) ;
if ( ! V_44 ) {
F_111 ( L_25 ,
V_20 -> V_122 ) ;
V_83 = - V_77 ;
goto V_293;
}
V_44 -> V_20 = V_20 ;
V_44 -> V_132 = 32 * V_257 ;
V_44 -> V_148 = V_44 -> V_132 ;
V_44 -> V_294 = 0 ;
V_44 -> V_29 = 0 ;
V_44 -> V_295 = - 1 ;
F_102 ( V_44 ) ;
if ( V_44 -> V_46 == NULL ) {
V_83 = F_184 ( V_2 , V_44 ) ;
if ( V_83 ) {
F_111 (
L_26 ,
V_20 -> V_122 , V_83 ) ;
goto V_296;
}
if ( V_289 ) {
V_83 = F_84 ( V_2 , V_44 ) ;
if ( V_83 ) {
F_74 (
L_27 ,
V_20 -> V_122 , V_83 ) ;
goto V_297;
}
}
}
V_83 = F_160 ( V_54 , V_9 , V_20 , V_44 ) ;
if ( V_83 ) {
F_111 ( L_28 , V_83 ) ;
goto error;
}
V_54 -> V_39 [ V_20 -> V_40 ] . V_44 = V_44 ;
V_54 -> V_39 [ V_20 -> V_40 ] . V_41 = V_9 ;
if ( V_54 == V_20 -> V_75 )
F_177 ( V_20 , V_9 ) ;
else if ( V_20 -> V_40 == V_107 && ! V_54 -> V_298 ) {
if ( V_20 -> V_219 ) {
V_83 = V_20 -> V_219 ( V_20 , V_54 ) ;
if ( V_83 ) {
F_74 ( L_29 , V_83 ) ;
V_54 -> V_39 [ V_20 -> V_40 ] . V_44 = NULL ;
V_54 -> V_39 [ V_20 -> V_40 ] . V_41 = NULL ;
goto error;
}
}
V_54 -> V_298 = true ;
}
return 0 ;
error:
if ( V_289 )
F_86 ( V_44 ) ;
V_297:
F_174 ( V_44 ) ;
V_296:
F_88 ( V_44 ) ;
V_293:
if ( V_289 )
F_85 ( V_9 ) ;
F_175 ( & V_9 -> V_92 ) ;
return V_83 ;
}
