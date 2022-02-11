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
if ( F_50 ( V_2 -> V_47 -> V_104 ) && ! V_103 )
return;
F_51 ( V_2 -> V_47 -> V_104 , V_102 ) ;
F_51 ( V_2 -> V_105 , V_102 ) ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_106 * V_107 , T_2 * V_108 )
{
bool V_109 = false ;
int V_34 ;
if ( F_26 ( V_2 ) <= 1 ) {
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
* V_108 = 0 ;
return;
}
for ( V_34 = 0 ; V_34 < V_110 ; V_34 ++ ) {
if ( V_2 -> V_111 [ V_34 ] >= F_26 ( V_2 ) ) {
V_109 = true ;
break;
}
}
if ( ! ( V_2 -> V_112 & V_113 ) || V_109 ) {
for ( V_34 = 0 ; V_34 < V_110 ; V_34 ++ ) {
T_1 V_114 , V_115 ;
V_115 = F_26 ( V_2 ) ;
V_114 = F_53 ( V_34 , V_115 ) ;
V_2 -> V_111 [ V_34 ] = V_114 ;
}
V_2 -> V_112 |= V_113 ;
}
for ( V_34 = 0 ; V_34 < V_110 ; V_34 ++ ) {
T_1 V_116 = F_54 ( V_2 , V_2 -> V_111 [ V_34 ] ) ;
V_107 -> V_111 [ V_34 ] = V_2 -> V_117 [ V_116 ] . V_118 -> V_119 ;
}
if ( ! ( V_2 -> V_112 & V_120 ) ) {
F_55 ( V_2 -> V_121 , sizeof( V_2 -> V_121 ) ) ;
V_2 -> V_112 |= V_120 ;
}
memcpy ( V_107 -> V_121 , V_2 -> V_121 , sizeof( V_107 -> V_121 ) ) ;
if ( ! ( V_2 -> V_112 & V_122 ) ) {
V_2 -> V_123 = V_124 | V_125 |
V_126 | V_127 ;
V_2 -> V_112 |= V_122 ;
}
V_107 -> V_123 = V_2 -> V_123 ;
* V_108 = 1 ;
}
static int F_56 ( struct V_1 * V_2 ,
enum V_128 V_129 ,
unsigned char V_102 [ V_130 ] )
{
struct V_131 V_132 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . type = V_133 ;
V_132 . V_27 . V_134 . type = V_129 ;
V_132 . V_27 . V_134 . V_135 = 1 ;
F_51 ( V_132 . V_27 . V_134 . V_102 , V_102 ) ;
return V_2 -> V_9 -> V_136 ( V_2 -> V_19 , & V_132 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
enum V_128 V_129 ,
T_1 V_137 )
{
struct V_131 V_132 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . type = V_133 ;
V_132 . V_27 . V_134 . type = V_129 ;
V_132 . V_27 . V_134 . V_138 = 1 ;
V_132 . V_27 . V_134 . V_139 = V_137 ;
return V_2 -> V_9 -> V_136 ( V_2 -> V_19 , & V_132 ) ;
}
static int F_58 ( struct V_1 * V_2 , bool V_140 )
{
struct V_141 * V_142 ;
int V_81 ;
if ( V_2 -> V_143 == V_140 )
return 0 ;
V_142 = F_22 ( sizeof( * V_142 ) ) ;
if ( ! V_142 )
return - V_56 ;
V_142 -> V_144 = 0 ;
V_142 -> V_143 = V_140 ;
V_142 -> V_145 = 1 ;
V_81 = V_2 -> V_9 -> V_146 ( V_2 -> V_19 , V_142 ) ;
if ( V_81 ) {
F_59 ( V_2 , L_7 ,
V_140 ? L_8 : L_9 ) ;
} else {
F_60 ( V_2 , L_10 ,
V_140 ? L_11 : L_12 ) ;
V_2 -> V_143 = V_140 ;
}
F_27 ( V_142 ) ;
return 0 ;
}
int F_61 ( struct V_79 * V_26 , T_3 V_147 , T_1 V_137 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_148 * V_139 , * V_149 ;
int V_81 = 0 ;
F_2 ( V_2 , V_150 , L_13 , V_137 ) ;
V_139 = F_39 ( sizeof( * V_139 ) , V_151 ) ;
if ( ! V_139 ) {
F_60 ( V_2 , L_14 ) ;
return - V_56 ;
}
F_62 ( & V_139 -> V_152 ) ;
V_139 -> V_137 = V_137 ;
V_139 -> V_153 = false ;
F_63 (tmp, &edev->vlan_list, list) {
if ( V_149 -> V_137 == V_139 -> V_137 ) {
F_2 ( V_2 , ( V_150 | V_154 ) ,
L_15 ) ;
F_5 ( V_139 ) ;
return - V_155 ;
}
}
F_64 ( V_2 ) ;
if ( V_2 -> V_31 != V_42 ) {
F_2 ( V_2 , V_154 ,
L_16 ,
V_137 ) ;
if ( V_137 != 0 )
V_2 -> V_156 ++ ;
F_65 ( & V_139 -> V_152 , & V_2 -> V_157 ) ;
goto V_158;
}
if ( ( V_2 -> V_159 < V_2 -> V_160 . V_161 ) ||
( V_139 -> V_137 == 0 ) ) {
V_81 = F_57 ( V_2 ,
V_162 ,
V_139 -> V_137 ) ;
if ( V_81 ) {
F_59 ( V_2 , L_17 ,
V_139 -> V_137 ) ;
F_5 ( V_139 ) ;
goto V_158;
}
V_139 -> V_153 = true ;
if ( V_139 -> V_137 != 0 )
V_2 -> V_159 ++ ;
} else {
if ( ! V_2 -> V_156 ) {
V_81 = F_58 ( V_2 , true ) ;
if ( V_81 ) {
F_5 ( V_139 ) ;
goto V_158;
}
}
V_2 -> V_156 ++ ;
}
F_65 ( & V_139 -> V_152 , & V_2 -> V_157 ) ;
V_158:
F_66 ( V_2 ) ;
return V_81 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_148 * V_139 )
{
if ( V_139 -> V_137 != 0 ) {
if ( V_139 -> V_153 )
V_2 -> V_159 -- ;
else
V_2 -> V_156 -- ;
}
F_68 ( & V_139 -> V_152 ) ;
F_5 ( V_139 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_81 = 0 , V_163 = 0 , V_143 = 0 ;
struct V_164 * V_160 ;
struct V_148 * V_139 = NULL ;
if ( F_70 ( & V_2 -> V_157 ) )
return 0 ;
V_160 = & V_2 -> V_160 ;
F_63 (vlan, &edev->vlan_list, list) {
if ( V_139 -> V_153 )
continue;
if ( ( V_139 -> V_137 != 0 ) &&
( V_2 -> V_159 == V_160 -> V_161 ) ) {
V_143 = 1 ;
continue;
}
F_2 ( V_2 , V_150 , L_18 , V_139 -> V_137 ) ;
V_81 = F_57 ( V_2 , V_162 ,
V_139 -> V_137 ) ;
if ( V_81 ) {
F_59 ( V_2 , L_19 ,
V_139 -> V_137 ) ;
V_163 = V_81 ;
continue;
}
V_139 -> V_153 = true ;
if ( V_139 -> V_137 != 0 ) {
V_2 -> V_156 -- ;
V_2 -> V_159 ++ ;
}
}
if ( V_143 )
V_81 = F_58 ( V_2 , true ) ;
else if ( ! V_2 -> V_156 )
V_81 = F_58 ( V_2 , false ) ;
if ( V_81 && ! V_163 )
V_163 = V_81 ;
return V_163 ;
}
int F_71 ( struct V_79 * V_26 , T_3 V_147 , T_1 V_137 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_148 * V_139 = NULL ;
int V_81 = 0 ;
F_2 ( V_2 , V_154 , L_20 , V_137 ) ;
F_64 ( V_2 ) ;
F_63 (vlan, &edev->vlan_list, list)
if ( V_139 -> V_137 == V_137 )
break;
if ( ! V_139 || ( V_139 -> V_137 != V_137 ) ) {
F_2 ( V_2 , ( V_150 | V_154 ) ,
L_21 ) ;
goto V_158;
}
if ( V_2 -> V_31 != V_42 ) {
F_2 ( V_2 , V_154 ,
L_22 ) ;
F_67 ( V_2 , V_139 ) ;
goto V_158;
}
if ( V_139 -> V_153 ) {
V_81 = F_57 ( V_2 , V_165 ,
V_137 ) ;
if ( V_81 ) {
F_59 ( V_2 , L_23 , V_137 ) ;
goto V_158;
}
}
F_67 ( V_2 , V_139 ) ;
V_81 = F_69 ( V_2 ) ;
V_158:
F_66 ( V_2 ) ;
return V_81 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_148 * V_139 = NULL ;
if ( F_70 ( & V_2 -> V_157 ) )
return;
F_63 (vlan, &edev->vlan_list, list) {
if ( ! V_139 -> V_153 )
continue;
V_139 -> V_153 = false ;
if ( V_139 -> V_137 != 0 ) {
V_2 -> V_156 ++ ;
V_2 -> V_159 -- ;
}
F_2 ( V_2 , V_154 ,
L_24 , V_139 -> V_137 ) ;
}
V_2 -> V_143 = false ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_166 * args )
{
V_2 -> V_47 -> V_167 = args -> V_168 . V_167 ;
}
int F_74 ( struct V_79 * V_26 , T_5 V_167 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
T_5 V_169 = V_167 ^ V_26 -> V_167 ;
bool V_170 = false ;
if ( V_169 & V_171 ) {
if ( V_26 -> V_167 & V_171 )
V_170 = ! V_2 -> V_172 ;
else
V_170 = V_2 -> V_172 ;
}
if ( V_170 ) {
struct V_166 args ;
args . V_168 . V_167 = V_167 ;
args . V_173 = & F_73 ;
F_64 ( V_2 ) ;
if ( V_2 -> V_174 )
args . V_173 ( V_2 , & args ) ;
else
F_75 ( V_2 , & args , true ) ;
F_66 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_76 ( struct V_79 * V_26 , struct V_175 * V_176 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_177 V_178 ;
T_1 V_179 = F_3 ( V_176 -> V_180 ) ;
int V_81 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
switch ( V_176 -> type ) {
case V_181 :
if ( ! V_2 -> V_160 . V_182 . V_183 )
return;
if ( V_2 -> V_100 )
return;
V_178 . V_184 = 1 ;
V_178 . V_98 = V_179 ;
F_64 ( V_2 ) ;
V_81 = V_2 -> V_9 -> V_185 ( V_2 -> V_19 , & V_178 ) ;
F_66 ( V_2 ) ;
if ( ! V_81 ) {
V_2 -> V_100 = V_179 ;
F_2 ( V_2 , V_186 , L_25 ,
V_179 ) ;
} else {
F_8 ( V_2 , L_26 ,
V_179 ) ;
}
break;
case V_187 :
if ( ! V_2 -> V_160 . V_182 . V_188 )
return;
if ( V_2 -> V_101 )
return;
V_178 . V_189 = 1 ;
V_178 . V_99 = V_179 ;
F_64 ( V_2 ) ;
V_81 = V_2 -> V_9 -> V_185 ( V_2 -> V_19 , & V_178 ) ;
F_66 ( V_2 ) ;
if ( ! V_81 ) {
V_2 -> V_101 = V_179 ;
F_2 ( V_2 , V_186 ,
L_27 , V_179 ) ;
} else {
F_8 ( V_2 , L_28 ,
V_179 ) ;
}
break;
default:
return;
}
}
void F_77 ( struct V_79 * V_26 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
struct V_177 V_178 ;
T_1 V_179 = F_3 ( V_176 -> V_180 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
switch ( V_176 -> type ) {
case V_181 :
if ( V_179 != V_2 -> V_100 )
return;
V_178 . V_184 = 1 ;
V_178 . V_98 = 0 ;
F_64 ( V_2 ) ;
V_2 -> V_9 -> V_185 ( V_2 -> V_19 , & V_178 ) ;
F_66 ( V_2 ) ;
V_2 -> V_100 = 0 ;
F_2 ( V_2 , V_186 , L_29 ,
V_179 ) ;
break;
case V_187 :
if ( V_179 != V_2 -> V_101 )
return;
V_178 . V_189 = 1 ;
V_178 . V_99 = 0 ;
F_64 ( V_2 ) ;
V_2 -> V_9 -> V_185 ( V_2 -> V_19 , & V_178 ) ;
F_66 ( V_2 ) ;
V_2 -> V_101 = 0 ;
F_2 ( V_2 , V_186 , L_30 ,
V_179 ) ;
break;
default:
return;
}
}
static void F_78 ( struct V_1 * V_2 ,
struct V_166 * args )
{
struct V_190 * V_191 ;
V_191 = F_79 ( & V_2 -> V_174 , args -> V_168 . V_192 ) ;
if ( V_191 )
F_80 ( V_191 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_190 * V_193 )
{
struct V_166 args ;
args . V_173 = & F_78 ;
args . V_168 . V_192 = V_193 ;
F_75 ( V_2 , & args , false ) ;
return 0 ;
}
int F_82 ( struct V_79 * V_26 , struct V_194 * V_195 )
{
struct V_1 * V_2 = F_41 ( V_26 ) ;
switch ( V_195 -> V_196 ) {
case V_197 :
return F_81 ( V_2 , V_195 -> V_193 ) ;
case V_198 :
V_195 -> V_199 = ! ! V_2 -> V_174 ;
return 0 ;
default:
return - V_200 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
enum V_128 V_129 ,
unsigned char * V_102 , int V_201 )
{
struct V_131 V_132 ;
int V_34 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . type = V_202 ;
V_132 . V_27 . V_203 . type = V_129 ;
V_132 . V_27 . V_203 . V_204 = V_201 ;
for ( V_34 = 0 ; V_34 < V_201 ; V_34 ++ , V_102 += V_130 )
F_51 ( V_132 . V_27 . V_203 . V_102 [ V_34 ] , V_102 ) ;
return V_2 -> V_9 -> V_136 ( V_2 -> V_19 , & V_132 ) ;
}
int F_84 ( struct V_79 * V_47 , void * V_205 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
struct V_206 * V_207 = V_205 ;
int V_81 ;
F_85 () ;
F_60 ( V_2 , L_31 ) ;
if ( ! F_50 ( V_207 -> V_208 ) ) {
F_8 ( V_2 , L_32 ) ;
return - V_209 ;
}
if ( ! V_2 -> V_9 -> V_210 ( V_2 -> V_19 , V_207 -> V_208 ) ) {
F_8 ( V_2 , L_33 ) ;
return - V_200 ;
}
F_51 ( V_47 -> V_104 , V_207 -> V_208 ) ;
if ( ! F_86 ( V_47 ) ) {
F_8 ( V_2 , L_34 ) ;
return 0 ;
}
V_81 = F_56 ( V_2 , V_165 ,
V_2 -> V_105 ) ;
if ( V_81 )
return V_81 ;
V_2 -> V_9 -> V_182 -> V_211 ( V_2 -> V_19 , V_207 -> V_208 ) ;
F_51 ( V_2 -> V_105 , V_47 -> V_104 ) ;
return F_56 ( V_2 , V_162 ,
V_2 -> V_105 ) ;
}
static int
F_87 ( struct V_79 * V_47 ,
enum V_212 * V_213 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
unsigned char * V_214 , * V_37 ;
struct V_215 * V_216 ;
int V_81 = 0 , V_217 ;
T_6 V_71 ;
V_71 = 64 * V_130 ;
V_214 = F_39 ( V_71 , V_151 ) ;
if ( ! V_214 ) {
F_8 ( V_2 ,
L_35 ) ;
V_81 = - V_56 ;
goto exit;
}
V_37 = V_214 ;
V_81 = F_83 ( V_2 , V_165 ,
V_214 , 1 ) ;
if ( V_81 )
goto exit;
F_88 ( V_47 ) ;
V_217 = F_89 ( V_47 ) ;
if ( V_217 < 64 ) {
F_90 (ha, ndev) {
F_51 ( V_37 , V_216 -> V_207 ) ;
V_37 += V_130 ;
}
}
F_91 ( V_47 ) ;
if ( ( V_47 -> V_218 & V_219 ) || ( V_217 > 64 ) ) {
if ( * V_213 == V_220 )
* V_213 = V_221 ;
} else {
V_81 = F_83 ( V_2 , V_162 ,
V_214 , V_217 ) ;
}
exit:
F_5 ( V_214 ) ;
return V_81 ;
}
void F_92 ( struct V_79 * V_47 )
{
struct V_1 * V_2 = F_41 ( V_47 ) ;
F_11 ( V_222 , & V_2 -> V_51 ) ;
F_18 ( & V_2 -> V_52 , 0 ) ;
}
void F_93 ( struct V_79 * V_47 )
{
enum V_212 V_213 ;
struct V_1 * V_2 = F_41 ( V_47 ) ;
struct V_131 V_223 ;
unsigned char * V_224 , * V_37 ;
struct V_215 * V_216 ;
int V_81 , V_225 ;
T_6 V_71 ;
F_88 ( V_47 ) ;
V_225 = F_94 ( V_47 ) ;
V_71 = V_225 * V_130 ;
V_224 = F_39 ( V_71 , V_78 ) ;
if ( ! V_224 ) {
F_8 ( V_2 , L_36 ) ;
F_91 ( V_47 ) ;
return;
}
V_37 = V_224 ;
F_95 (ha, ndev) {
F_51 ( V_37 , V_216 -> V_207 ) ;
V_37 += V_130 ;
}
F_91 ( V_47 ) ;
memset ( & V_223 , 0 , sizeof( struct V_131 ) ) ;
V_223 . type = V_226 ;
V_81 = F_56 ( V_2 , V_227 ,
V_2 -> V_105 ) ;
if ( V_81 )
goto V_158;
if ( V_47 -> V_218 & V_228 )
V_213 = V_229 ;
else
V_213 = V_220 ;
if ( V_225 < V_2 -> V_160 . V_230 ) {
int V_34 ;
V_37 = V_224 ;
for ( V_34 = 0 ; V_34 < V_225 ; V_34 ++ ) {
V_81 = F_56 ( V_2 ,
V_162 ,
V_37 ) ;
if ( V_81 )
goto V_158;
V_37 += V_130 ;
}
} else {
V_213 = V_229 ;
}
V_81 = F_87 ( V_47 , & V_213 ) ;
if ( V_81 )
goto V_158;
if ( V_47 -> V_218 & V_228 ) {
F_58 ( V_2 , true ) ;
} else if ( ! V_2 -> V_156 ) {
F_58 ( V_2 , false ) ;
}
V_223 . V_27 . V_213 = V_213 ;
V_2 -> V_9 -> V_136 ( V_2 -> V_19 , & V_223 ) ;
V_158:
F_5 ( V_224 ) ;
}
