static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , bool V_6 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_4 -> V_10 )
return;
F_2 ( V_2 , V_11 ,
L_1 ,
V_6 ? L_2 : L_3 ,
V_4 -> V_12 , V_4 -> V_13 , F_3 ( V_4 -> V_14 . V_15 ) ,
F_3 ( V_4 -> V_14 . V_16 ) , V_5 ) ;
V_4 -> V_10 = true ;
V_4 -> V_17 = V_6 ;
V_8 -> V_18 ( V_2 -> V_19 , V_4 , V_4 -> V_20 , V_4 -> V_21 , 0 ,
V_5 , V_6 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_3 * V_22 )
{
F_5 ( V_22 -> V_23 ) ;
F_6 ( V_22 -> V_13 , V_2 -> V_24 -> V_25 ) ;
F_5 ( V_22 ) ;
}
void F_7 ( void * V_26 , void * V_27 , T_2 V_28 )
{
struct V_3 * V_22 = V_27 ;
struct V_1 * V_2 = V_26 ;
if ( V_28 ) {
F_8 ( V_2 ,
L_4 ,
V_28 , V_22 -> V_12 , V_22 -> V_13 ,
F_3 ( V_22 -> V_14 . V_15 ) ,
F_3 ( V_22 -> V_14 . V_16 ) , V_22 -> V_5 ) ;
F_9 ( & V_2 -> V_24 -> V_29 ) ;
V_22 -> V_10 = false ;
F_6 ( V_30 , & V_22 -> V_31 ) ;
F_10 ( & V_2 -> V_24 -> V_29 ) ;
return;
}
F_9 ( & V_2 -> V_24 -> V_29 ) ;
V_22 -> V_10 = false ;
if ( V_22 -> V_17 ) {
F_11 ( V_30 , & V_22 -> V_31 ) ;
if ( V_22 -> V_5 != V_22 -> V_32 )
F_1 ( V_2 , V_22 , V_22 -> V_5 ,
false ) ;
} else {
F_6 ( V_30 , & V_22 -> V_31 ) ;
if ( V_22 -> V_5 != V_22 -> V_32 ) {
V_22 -> V_5 = V_22 -> V_32 ;
F_1 ( V_2 , V_22 ,
V_22 -> V_5 , true ) ;
}
}
F_10 ( & V_2 -> V_24 -> V_29 ) ;
}
void F_12 ( struct V_1 * V_2 , bool V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 <= V_35 ; V_34 ++ ) {
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_3 * V_22 ;
V_39 = & V_2 -> V_24 -> V_40 [ V_34 ] ;
F_13 (fltr, temp, head, node) {
bool V_41 = false ;
if ( V_2 -> V_31 != V_42 )
V_41 = true ;
F_9 ( & V_2 -> V_24 -> V_29 ) ;
if ( ( ! F_14 ( V_30 , & V_22 -> V_31 ) &&
! V_22 -> V_10 ) || V_33 ) {
F_15 ( & V_22 -> V_43 ) ;
F_16 ( & V_2 -> V_44 -> V_26 ,
V_22 -> V_20 ,
V_22 -> V_21 , V_45 ) ;
F_4 ( V_2 , V_22 ) ;
V_2 -> V_24 -> V_46 -- ;
} else {
if ( ( F_17 ( V_2 -> V_47 ,
V_22 -> V_5 ,
V_22 -> V_12 ,
V_22 -> V_13 ) || V_41 ) &&
! V_33 )
F_1 ( V_2 , V_22 ,
V_22 -> V_5 ,
false ) ;
}
F_10 ( & V_2 -> V_24 -> V_29 ) ;
}
}
F_9 ( & V_2 -> V_24 -> V_29 ) ;
if ( ! V_2 -> V_24 -> V_46 ) {
if ( V_2 -> V_24 -> V_48 ) {
V_2 -> V_24 -> V_48 = false ;
V_2 -> V_9 -> V_49 ( V_2 -> V_19 , false ) ;
}
} else {
F_11 ( V_50 , & V_2 -> V_51 ) ;
F_18 ( & V_2 -> V_52 ,
V_53 ) ;
}
F_10 ( & V_2 -> V_24 -> V_29 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
int V_54 = V_55 ;
while ( V_54 ) {
F_12 ( V_2 , false ) ;
if ( ! V_2 -> V_24 -> V_46 )
break;
F_20 ( 100 ) ;
V_54 -- ;
}
if ( ! V_54 ) {
F_8 ( V_2 , L_5 ) ;
F_12 ( V_2 , true ) ;
}
}
int F_21 ( struct V_1 * V_2 )
{
int V_34 ;
V_2 -> V_24 = F_22 ( sizeof( * V_2 -> V_24 ) ) ;
if ( ! V_2 -> V_24 )
return - V_56 ;
F_23 ( & V_2 -> V_24 -> V_29 ) ;
for ( V_34 = 0 ; V_34 <= V_35 ; V_34 ++ )
F_24 ( & V_2 -> V_24 -> V_40 [ V_34 ] ) ;
V_2 -> V_47 -> V_57 = F_25 ( F_26 ( V_2 ) ) ;
if ( ! V_2 -> V_47 -> V_57 ) {
F_27 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
return - V_56 ;
}
V_2 -> V_24 -> V_25 = F_22 ( F_28 ( V_58 ) *
sizeof( long ) ) ;
if ( ! V_2 -> V_24 -> V_25 ) {
F_29 ( V_2 -> V_47 -> V_57 ) ;
V_2 -> V_47 -> V_57 = NULL ;
F_27 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
return - V_56 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
if ( V_2 -> V_47 -> V_57 )
F_29 ( V_2 -> V_47 -> V_57 ) ;
V_2 -> V_47 -> V_57 = NULL ;
F_27 ( V_2 -> V_24 -> V_25 ) ;
V_2 -> V_24 -> V_25 = NULL ;
F_27 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
static bool F_31 ( struct V_3 * V_59 ,
const struct V_60 * V_61 )
{
if ( V_61 -> V_62 == F_32 ( V_63 ) ) {
if ( V_59 -> V_14 . V_64 == F_33 ( V_61 ) -> V_65 &&
V_59 -> V_14 . V_66 == F_33 ( V_61 ) -> V_67 )
return true ;
else
return false ;
} else {
struct V_68 * V_69 = & V_59 -> V_14 . V_70 ;
T_2 V_71 = sizeof( struct V_68 ) ;
if ( ! memcmp ( V_69 , & F_34 ( V_61 ) -> V_65 , V_71 ) &&
! memcmp ( & V_59 -> V_14 . V_72 , & F_34 ( V_61 ) -> V_67 , V_71 ) )
return true ;
else
return false ;
}
}
static struct V_3 *
F_35 ( struct V_38 * V_73 , const struct V_60 * V_61 ,
T_3 V_15 , T_3 V_16 , T_2 V_74 )
{
struct V_3 * V_59 ;
F_36 (tpos, h, node)
if ( V_59 -> V_14 . V_74 == V_74 &&
V_59 -> V_14 . V_75 == V_61 -> V_62 &&
F_31 ( V_59 , V_61 ) &&
V_59 -> V_14 . V_15 == V_15 &&
V_59 -> V_14 . V_16 == V_16 )
return V_59 ;
return NULL ;
}
static struct V_3 *
F_37 ( struct V_1 * V_2 , int V_76 )
{
struct V_3 * V_4 ;
int V_77 ;
V_77 = F_38 ( V_2 -> V_24 -> V_25 ,
V_58 ) ;
if ( V_77 >= V_58 )
return NULL ;
V_4 = F_39 ( sizeof( * V_4 ) , V_78 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_23 = F_39 ( V_76 , V_78 ) ;
if ( ! V_4 -> V_23 ) {
F_5 ( V_4 ) ;
return NULL ;
}
V_4 -> V_13 = ( T_1 ) V_77 ;
F_11 ( V_77 , V_2 -> V_24 -> V_25 ) ;
return V_4 ;
}
int F_40 ( struct V_79 * V_26 , const struct V_60 * V_61 ,
T_1 V_80 , T_4 V_12 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_3 * V_4 ;
int V_76 , V_81 , V_82 ;
struct V_83 * V_84 ;
T_3 * V_85 ;
T_1 V_86 ;
T_2 V_74 ;
if ( V_61 -> V_87 )
return - V_88 ;
if ( V_61 -> V_62 != F_32 ( V_63 ) &&
V_61 -> V_62 != F_32 ( V_89 ) )
return - V_88 ;
if ( V_61 -> V_62 == F_32 ( V_63 ) ) {
V_74 = F_33 ( V_61 ) -> V_62 ;
V_82 = sizeof( struct V_90 ) ;
} else {
V_74 = F_34 ( V_61 ) -> V_91 ;
V_82 = sizeof( struct V_92 ) ;
}
if ( V_74 != V_93 && V_74 != V_94 )
return - V_88 ;
V_85 = ( T_3 * ) ( V_61 -> V_23 + V_82 ) ;
V_86 = F_42 ( V_61 ) & V_35 ;
F_9 ( & V_2 -> V_24 -> V_29 ) ;
V_4 = F_35 ( & V_2 -> V_24 -> V_40 [ V_86 ] ,
V_61 , V_85 [ 0 ] , V_85 [ 1 ] , V_74 ) ;
if ( V_4 ) {
V_4 -> V_32 = V_80 ;
if ( F_14 ( V_30 , & V_4 -> V_31 ) ) {
if ( V_4 -> V_5 != V_80 )
F_1 ( V_2 , V_4 , V_4 -> V_5 ,
false ) ;
} else {
if ( ! V_4 -> V_10 ) {
V_4 -> V_5 = V_80 ;
F_1 ( V_2 , V_4 , V_4 -> V_5 ,
true ) ;
}
}
V_81 = V_4 -> V_13 ;
goto V_95;
}
V_76 = V_96 + F_43 ( V_61 ) ;
V_4 = F_37 ( V_2 , V_76 ) ;
if ( ! V_4 ) {
V_81 = - V_56 ;
goto V_95;
}
V_4 -> V_21 = V_76 ;
V_4 -> V_5 = V_80 ;
V_4 -> V_32 = V_80 ;
V_4 -> V_14 . V_15 = V_85 [ 0 ] ;
V_4 -> V_14 . V_16 = V_85 [ 1 ] ;
V_4 -> V_12 = V_12 ;
if ( V_61 -> V_62 == F_32 ( V_63 ) ) {
V_4 -> V_14 . V_64 = F_33 ( V_61 ) -> V_65 ;
V_4 -> V_14 . V_66 = F_33 ( V_61 ) -> V_67 ;
} else {
memcpy ( & V_4 -> V_14 . V_70 , & F_34 ( V_61 ) -> V_65 ,
sizeof( struct V_68 ) ) ;
memcpy ( & V_4 -> V_14 . V_72 , & F_34 ( V_61 ) -> V_67 ,
sizeof( struct V_68 ) ) ;
}
V_84 = (struct V_83 * ) V_4 -> V_23 ;
V_84 -> V_97 = V_61 -> V_62 ;
V_4 -> V_14 . V_75 = V_61 -> V_62 ;
V_4 -> V_14 . V_74 = V_74 ;
memcpy ( V_4 -> V_23 + V_96 , V_61 -> V_23 , F_43 ( V_61 ) ) ;
V_4 -> V_20 = F_44 ( & V_2 -> V_44 -> V_26 , V_4 -> V_23 ,
V_4 -> V_21 , V_45 ) ;
if ( F_45 ( & V_2 -> V_44 -> V_26 , V_4 -> V_20 ) ) {
F_8 ( V_2 , L_6 ) ;
F_4 ( V_2 , V_4 ) ;
V_81 = - V_56 ;
goto V_95;
}
F_46 ( & V_4 -> V_43 ) ;
F_47 ( & V_4 -> V_43 , & V_2 -> V_24 -> V_40 [ V_86 ] ) ;
V_2 -> V_24 -> V_46 ++ ;
if ( V_2 -> V_24 -> V_46 == 1 && ! V_2 -> V_24 -> V_48 ) {
V_2 -> V_9 -> V_49 ( V_2 -> V_19 , true ) ;
V_2 -> V_24 -> V_48 = true ;
}
F_1 ( V_2 , V_4 , V_4 -> V_5 , true ) ;
F_10 ( & V_2 -> V_24 -> V_29 ) ;
F_11 ( V_50 , & V_2 -> V_51 ) ;
F_18 ( & V_2 -> V_52 , 0 ) ;
return V_4 -> V_13 ;
V_95:
F_10 ( & V_2 -> V_24 -> V_29 ) ;
return V_81 ;
}
void F_48 ( void * V_26 , T_1 V_98 , T_1 V_99 )
{
struct V_1 * V_2 = V_26 ;
if ( V_2 -> V_100 != V_98 )
V_2 -> V_100 = 0 ;
if ( V_2 -> V_101 != V_99 )
V_2 -> V_101 = 0 ;
}
void F_49 ( void * V_26 , T_2 * V_102 , bool V_103 )
{
struct V_1 * V_2 = V_26 ;
F_50 ( V_2 ) ;
if ( F_51 ( V_2 -> V_47 -> V_104 ) && ! V_103 ) {
F_52 ( V_2 ) ;
return;
}
F_53 ( V_2 -> V_47 -> V_104 , V_102 ) ;
F_52 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 ,
struct V_105 * V_106 , T_2 * V_107 )
{
bool V_108 = false ;
int V_34 ;
if ( F_26 ( V_2 ) <= 1 ) {
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
* V_107 = 0 ;
return;
}
for ( V_34 = 0 ; V_34 < V_109 ; V_34 ++ ) {
if ( V_2 -> V_110 [ V_34 ] >= F_26 ( V_2 ) ) {
V_108 = true ;
break;
}
}
if ( ! ( V_2 -> V_111 & V_112 ) || V_108 ) {
for ( V_34 = 0 ; V_34 < V_109 ; V_34 ++ ) {
T_1 V_113 , V_114 ;
V_114 = F_26 ( V_2 ) ;
V_113 = F_55 ( V_34 , V_114 ) ;
V_2 -> V_110 [ V_34 ] = V_113 ;
}
V_2 -> V_111 |= V_112 ;
}
for ( V_34 = 0 ; V_34 < V_109 ; V_34 ++ ) {
T_1 V_115 = F_56 ( V_2 , V_2 -> V_110 [ V_34 ] ) ;
V_106 -> V_110 [ V_34 ] = V_2 -> V_116 [ V_115 ] . V_117 -> V_118 ;
}
if ( ! ( V_2 -> V_111 & V_119 ) ) {
F_57 ( V_2 -> V_120 , sizeof( V_2 -> V_120 ) ) ;
V_2 -> V_111 |= V_119 ;
}
memcpy ( V_106 -> V_120 , V_2 -> V_120 , sizeof( V_106 -> V_120 ) ) ;
if ( ! ( V_2 -> V_111 & V_121 ) ) {
V_2 -> V_122 = V_123 | V_124 |
V_125 | V_126 ;
V_2 -> V_111 |= V_121 ;
}
V_106 -> V_122 = V_2 -> V_122 ;
* V_107 = 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
enum V_127 V_128 ,
unsigned char V_102 [ V_129 ] )
{
struct V_130 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . type = V_132 ;
V_131 . V_27 . V_133 . type = V_128 ;
V_131 . V_27 . V_133 . V_134 = 1 ;
F_53 ( V_131 . V_27 . V_133 . V_102 , V_102 ) ;
return V_2 -> V_9 -> V_135 ( V_2 -> V_19 , & V_131 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
enum V_127 V_128 ,
T_1 V_136 )
{
struct V_130 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . type = V_132 ;
V_131 . V_27 . V_133 . type = V_128 ;
V_131 . V_27 . V_133 . V_137 = 1 ;
V_131 . V_27 . V_133 . V_138 = V_136 ;
return V_2 -> V_9 -> V_135 ( V_2 -> V_19 , & V_131 ) ;
}
static int F_60 ( struct V_1 * V_2 , bool V_139 )
{
struct V_140 * V_141 ;
int V_81 ;
if ( V_2 -> V_142 == V_139 )
return 0 ;
V_141 = F_22 ( sizeof( * V_141 ) ) ;
if ( ! V_141 )
return - V_56 ;
V_141 -> V_143 = 0 ;
V_141 -> V_142 = V_139 ;
V_141 -> V_144 = 1 ;
V_81 = V_2 -> V_9 -> V_145 ( V_2 -> V_19 , V_141 ) ;
if ( V_81 ) {
F_61 ( V_2 , L_7 ,
V_139 ? L_8 : L_9 ) ;
} else {
F_62 ( V_2 , L_10 ,
V_139 ? L_11 : L_12 ) ;
V_2 -> V_142 = V_139 ;
}
F_27 ( V_141 ) ;
return 0 ;
}
int F_63 ( struct V_79 * V_26 , T_3 V_146 , T_1 V_136 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_147 * V_138 , * V_148 ;
int V_81 = 0 ;
F_2 ( V_2 , V_149 , L_13 , V_136 ) ;
V_138 = F_39 ( sizeof( * V_138 ) , V_150 ) ;
if ( ! V_138 ) {
F_62 ( V_2 , L_14 ) ;
return - V_56 ;
}
F_64 ( & V_138 -> V_151 ) ;
V_138 -> V_136 = V_136 ;
V_138 -> V_152 = false ;
F_65 (tmp, &edev->vlan_list, list) {
if ( V_148 -> V_136 == V_138 -> V_136 ) {
F_2 ( V_2 , ( V_149 | V_153 ) ,
L_15 ) ;
F_5 ( V_138 ) ;
return - V_154 ;
}
}
F_50 ( V_2 ) ;
if ( V_2 -> V_31 != V_42 ) {
F_2 ( V_2 , V_153 ,
L_16 ,
V_136 ) ;
if ( V_136 != 0 )
V_2 -> V_155 ++ ;
F_66 ( & V_138 -> V_151 , & V_2 -> V_156 ) ;
goto V_157;
}
if ( ( V_2 -> V_158 < V_2 -> V_159 . V_160 ) ||
( V_138 -> V_136 == 0 ) ) {
V_81 = F_59 ( V_2 ,
V_161 ,
V_138 -> V_136 ) ;
if ( V_81 ) {
F_61 ( V_2 , L_17 ,
V_138 -> V_136 ) ;
F_5 ( V_138 ) ;
goto V_157;
}
V_138 -> V_152 = true ;
if ( V_138 -> V_136 != 0 )
V_2 -> V_158 ++ ;
} else {
if ( ! V_2 -> V_155 ) {
V_81 = F_60 ( V_2 , true ) ;
if ( V_81 ) {
F_5 ( V_138 ) ;
goto V_157;
}
}
V_2 -> V_155 ++ ;
}
F_66 ( & V_138 -> V_151 , & V_2 -> V_156 ) ;
V_157:
F_52 ( V_2 ) ;
return V_81 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_147 * V_138 )
{
if ( V_138 -> V_136 != 0 ) {
if ( V_138 -> V_152 )
V_2 -> V_158 -- ;
else
V_2 -> V_155 -- ;
}
F_68 ( & V_138 -> V_151 ) ;
F_5 ( V_138 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_81 = 0 , V_162 = 0 , V_142 = 0 ;
struct V_163 * V_159 ;
struct V_147 * V_138 = NULL ;
if ( F_70 ( & V_2 -> V_156 ) )
return 0 ;
V_159 = & V_2 -> V_159 ;
F_65 (vlan, &edev->vlan_list, list) {
if ( V_138 -> V_152 )
continue;
if ( ( V_138 -> V_136 != 0 ) &&
( V_2 -> V_158 == V_159 -> V_160 ) ) {
V_142 = 1 ;
continue;
}
F_2 ( V_2 , V_149 , L_18 , V_138 -> V_136 ) ;
V_81 = F_59 ( V_2 , V_161 ,
V_138 -> V_136 ) ;
if ( V_81 ) {
F_61 ( V_2 , L_19 ,
V_138 -> V_136 ) ;
V_162 = V_81 ;
continue;
}
V_138 -> V_152 = true ;
if ( V_138 -> V_136 != 0 ) {
V_2 -> V_155 -- ;
V_2 -> V_158 ++ ;
}
}
if ( V_142 )
V_81 = F_60 ( V_2 , true ) ;
else if ( ! V_2 -> V_155 )
V_81 = F_60 ( V_2 , false ) ;
if ( V_81 && ! V_162 )
V_162 = V_81 ;
return V_162 ;
}
int F_71 ( struct V_79 * V_26 , T_3 V_146 , T_1 V_136 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_147 * V_138 = NULL ;
int V_81 = 0 ;
F_2 ( V_2 , V_153 , L_20 , V_136 ) ;
F_50 ( V_2 ) ;
F_65 (vlan, &edev->vlan_list, list)
if ( V_138 -> V_136 == V_136 )
break;
if ( ! V_138 || ( V_138 -> V_136 != V_136 ) ) {
F_2 ( V_2 , ( V_149 | V_153 ) ,
L_21 ) ;
goto V_157;
}
if ( V_2 -> V_31 != V_42 ) {
F_2 ( V_2 , V_153 ,
L_22 ) ;
F_67 ( V_2 , V_138 ) ;
goto V_157;
}
if ( V_138 -> V_152 ) {
V_81 = F_59 ( V_2 , V_164 ,
V_136 ) ;
if ( V_81 ) {
F_61 ( V_2 , L_23 , V_136 ) ;
goto V_157;
}
}
F_67 ( V_2 , V_138 ) ;
V_81 = F_69 ( V_2 ) ;
V_157:
F_52 ( V_2 ) ;
return V_81 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_147 * V_138 = NULL ;
if ( F_70 ( & V_2 -> V_156 ) )
return;
F_65 (vlan, &edev->vlan_list, list) {
if ( ! V_138 -> V_152 )
continue;
V_138 -> V_152 = false ;
if ( V_138 -> V_136 != 0 ) {
V_2 -> V_155 ++ ;
V_2 -> V_158 -- ;
}
F_2 ( V_2 , V_153 ,
L_24 , V_138 -> V_136 ) ;
}
V_2 -> V_142 = false ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_165 * args )
{
V_2 -> V_47 -> V_166 = args -> V_167 . V_166 ;
}
int F_74 ( struct V_79 * V_26 , T_5 V_166 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
T_5 V_168 = V_166 ^ V_26 -> V_166 ;
bool V_169 = false ;
if ( V_168 & V_170 ) {
if ( V_26 -> V_166 & V_170 )
V_169 = ! V_2 -> V_171 ;
else
V_169 = V_2 -> V_171 ;
}
if ( V_169 ) {
struct V_165 args ;
args . V_167 . V_166 = V_166 ;
args . V_172 = & F_73 ;
F_50 ( V_2 ) ;
if ( V_2 -> V_173 )
args . V_172 ( V_2 , & args ) ;
else
F_75 ( V_2 , & args , true ) ;
F_52 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_76 ( struct V_79 * V_26 , struct V_174 * V_175 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_176 V_177 ;
T_1 V_178 = F_3 ( V_175 -> V_179 ) ;
int V_81 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
switch ( V_175 -> type ) {
case V_180 :
if ( ! V_2 -> V_159 . V_181 . V_182 )
return;
if ( V_2 -> V_100 )
return;
V_177 . V_183 = 1 ;
V_177 . V_98 = V_178 ;
F_50 ( V_2 ) ;
V_81 = V_2 -> V_9 -> V_184 ( V_2 -> V_19 , & V_177 ) ;
F_52 ( V_2 ) ;
if ( ! V_81 ) {
V_2 -> V_100 = V_178 ;
F_2 ( V_2 , V_185 , L_25 ,
V_178 ) ;
} else {
F_8 ( V_2 , L_26 ,
V_178 ) ;
}
break;
case V_186 :
if ( ! V_2 -> V_159 . V_181 . V_187 )
return;
if ( V_2 -> V_101 )
return;
V_177 . V_188 = 1 ;
V_177 . V_99 = V_178 ;
F_50 ( V_2 ) ;
V_81 = V_2 -> V_9 -> V_184 ( V_2 -> V_19 , & V_177 ) ;
F_52 ( V_2 ) ;
if ( ! V_81 ) {
V_2 -> V_101 = V_178 ;
F_2 ( V_2 , V_185 ,
L_27 , V_178 ) ;
} else {
F_8 ( V_2 , L_28 ,
V_178 ) ;
}
break;
default:
return;
}
}
void F_77 ( struct V_79 * V_26 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_176 V_177 ;
T_1 V_178 = F_3 ( V_175 -> V_179 ) ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
switch ( V_175 -> type ) {
case V_180 :
if ( V_178 != V_2 -> V_100 )
return;
V_177 . V_183 = 1 ;
V_177 . V_98 = 0 ;
F_50 ( V_2 ) ;
V_2 -> V_9 -> V_184 ( V_2 -> V_19 , & V_177 ) ;
F_52 ( V_2 ) ;
V_2 -> V_100 = 0 ;
F_2 ( V_2 , V_185 , L_29 ,
V_178 ) ;
break;
case V_186 :
if ( V_178 != V_2 -> V_101 )
return;
V_177 . V_188 = 1 ;
V_177 . V_99 = 0 ;
F_50 ( V_2 ) ;
V_2 -> V_9 -> V_184 ( V_2 -> V_19 , & V_177 ) ;
F_52 ( V_2 ) ;
V_2 -> V_101 = 0 ;
F_2 ( V_2 , V_185 , L_30 ,
V_178 ) ;
break;
default:
return;
}
}
static void F_78 ( struct V_1 * V_2 ,
struct V_165 * args )
{
struct V_189 * V_190 ;
V_190 = F_79 ( & V_2 -> V_173 , args -> V_167 . V_191 ) ;
if ( V_190 )
F_80 ( V_190 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_189 * V_192 )
{
struct V_165 args ;
args . V_172 = & F_78 ;
args . V_167 . V_191 = V_192 ;
F_75 ( V_2 , & args , false ) ;
return 0 ;
}
int F_82 ( struct V_79 * V_26 , struct V_193 * V_194 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
switch ( V_194 -> V_195 ) {
case V_196 :
return F_81 ( V_2 , V_194 -> V_192 ) ;
case V_197 :
V_194 -> V_198 = ! ! V_2 -> V_173 ;
V_194 -> V_199 = V_2 -> V_173 ? V_2 -> V_173 -> V_200 -> V_201 : 0 ;
return 0 ;
default:
return - V_202 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
enum V_127 V_128 ,
unsigned char * V_102 , int V_203 )
{
struct V_130 V_131 ;
int V_34 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . type = V_204 ;
V_131 . V_27 . V_205 . type = V_128 ;
V_131 . V_27 . V_205 . V_206 = V_203 ;
for ( V_34 = 0 ; V_34 < V_203 ; V_34 ++ , V_102 += V_129 )
F_53 ( V_131 . V_27 . V_205 . V_102 [ V_34 ] , V_102 ) ;
return V_2 -> V_9 -> V_135 ( V_2 -> V_19 , & V_131 ) ;
}
int F_84 ( struct V_79 * V_47 , void * V_207 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
struct V_208 * V_209 = V_207 ;
int V_81 = 0 ;
F_50 ( V_2 ) ;
if ( ! F_51 ( V_209 -> V_210 ) ) {
F_8 ( V_2 , L_31 ) ;
V_81 = - V_211 ;
goto V_157;
}
if ( ! V_2 -> V_9 -> V_212 ( V_2 -> V_19 , V_209 -> V_210 ) ) {
F_8 ( V_2 , L_32 ,
V_209 -> V_210 ) ;
V_81 = - V_202 ;
goto V_157;
}
if ( V_2 -> V_31 == V_42 ) {
V_81 = F_58 ( V_2 , V_164 ,
V_47 -> V_104 ) ;
if ( V_81 )
goto V_157;
}
F_53 ( V_47 -> V_104 , V_209 -> V_210 ) ;
F_62 ( V_2 , L_33 , V_209 -> V_210 ) ;
if ( V_2 -> V_31 != V_42 ) {
F_2 ( V_2 , V_153 ,
L_34 ) ;
goto V_157;
}
V_2 -> V_9 -> V_181 -> V_213 ( V_2 -> V_19 , V_47 -> V_104 ) ;
V_81 = F_58 ( V_2 , V_161 ,
V_47 -> V_104 ) ;
V_157:
F_52 ( V_2 ) ;
return V_81 ;
}
static int
F_85 ( struct V_79 * V_47 ,
enum V_214 * V_215 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
unsigned char * V_216 , * V_37 ;
struct V_217 * V_218 ;
int V_81 = 0 , V_219 ;
T_6 V_71 ;
V_71 = 64 * V_129 ;
V_216 = F_39 ( V_71 , V_150 ) ;
if ( ! V_216 ) {
F_8 ( V_2 ,
L_35 ) ;
V_81 = - V_56 ;
goto exit;
}
V_37 = V_216 ;
V_81 = F_83 ( V_2 , V_164 ,
V_216 , 1 ) ;
if ( V_81 )
goto exit;
F_86 ( V_47 ) ;
V_219 = F_87 ( V_47 ) ;
if ( V_219 < 64 ) {
F_88 (ha, ndev) {
F_53 ( V_37 , V_218 -> V_209 ) ;
V_37 += V_129 ;
}
}
F_89 ( V_47 ) ;
if ( ( V_47 -> V_220 & V_221 ) || ( V_219 > 64 ) ) {
if ( * V_215 == V_222 )
* V_215 = V_223 ;
} else {
V_81 = F_83 ( V_2 , V_161 ,
V_216 , V_219 ) ;
}
exit:
F_5 ( V_216 ) ;
return V_81 ;
}
void F_90 ( struct V_79 * V_47 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
F_11 ( V_224 , & V_2 -> V_51 ) ;
F_18 ( & V_2 -> V_52 , 0 ) ;
}
void F_91 ( struct V_79 * V_47 )
{
enum V_214 V_215 ;
struct V_1 * V_2 = F_41 ( V_47 ) ;
struct V_130 V_225 ;
unsigned char * V_226 , * V_37 ;
struct V_217 * V_218 ;
int V_81 , V_227 ;
T_6 V_71 ;
F_86 ( V_47 ) ;
V_227 = F_92 ( V_47 ) ;
V_71 = V_227 * V_129 ;
V_226 = F_39 ( V_71 , V_78 ) ;
if ( ! V_226 ) {
F_8 ( V_2 , L_36 ) ;
F_89 ( V_47 ) ;
return;
}
V_37 = V_226 ;
F_93 (ha, ndev) {
F_53 ( V_37 , V_218 -> V_209 ) ;
V_37 += V_129 ;
}
F_89 ( V_47 ) ;
memset ( & V_225 , 0 , sizeof( struct V_130 ) ) ;
V_225 . type = V_228 ;
V_81 = F_58 ( V_2 , V_229 ,
V_2 -> V_47 -> V_104 ) ;
if ( V_81 )
goto V_157;
if ( V_47 -> V_220 & V_230 )
V_215 = V_231 ;
else
V_215 = V_222 ;
if ( V_227 < V_2 -> V_159 . V_232 ) {
int V_34 ;
V_37 = V_226 ;
for ( V_34 = 0 ; V_34 < V_227 ; V_34 ++ ) {
V_81 = F_58 ( V_2 ,
V_161 ,
V_37 ) ;
if ( V_81 )
goto V_157;
V_37 += V_129 ;
}
} else {
V_215 = V_231 ;
}
V_81 = F_85 ( V_47 , & V_215 ) ;
if ( V_81 )
goto V_157;
if ( V_47 -> V_220 & V_230 ) {
F_60 ( V_2 , true ) ;
} else if ( ! V_2 -> V_155 ) {
F_60 ( V_2 , false ) ;
}
V_225 . V_27 . V_215 = V_215 ;
V_2 -> V_9 -> V_135 ( V_2 -> V_19 , & V_225 ) ;
V_157:
F_5 ( V_226 ) ;
}
