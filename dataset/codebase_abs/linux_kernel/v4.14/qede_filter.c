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
static int
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_22 ,
T_1 V_26 )
{
V_22 -> V_20 = F_8 ( & V_2 -> V_27 -> V_28 , V_22 -> V_23 ,
V_22 -> V_21 , V_29 ) ;
if ( F_9 ( & V_2 -> V_27 -> V_28 , V_22 -> V_20 ) ) {
F_10 ( V_2 , L_4 ) ;
F_4 ( V_2 , V_22 ) ;
return - V_30 ;
}
F_11 ( & V_22 -> V_31 ) ;
F_12 ( & V_22 -> V_31 ,
F_13 ( V_2 , V_26 ) ) ;
V_2 -> V_24 -> V_32 ++ ;
if ( V_2 -> V_24 -> V_32 == 1 && ! V_2 -> V_24 -> V_33 ) {
V_2 -> V_9 -> V_34 ( V_2 -> V_19 , true ) ;
V_2 -> V_24 -> V_33 = true ;
}
return 0 ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_3 * V_22 )
{
F_15 ( & V_22 -> V_31 ) ;
F_16 ( & V_2 -> V_27 -> V_28 , V_22 -> V_20 ,
V_22 -> V_21 , V_29 ) ;
F_4 ( V_2 , V_22 ) ;
V_2 -> V_24 -> V_32 -- ;
if ( ! V_2 -> V_24 -> V_32 && V_2 -> V_24 -> V_33 ) {
V_2 -> V_24 -> V_33 = false ;
V_2 -> V_9 -> V_34 ( V_2 -> V_19 , false ) ;
}
}
void F_17 ( void * V_28 , void * V_35 , T_2 V_36 )
{
struct V_3 * V_22 = V_35 ;
struct V_1 * V_2 = V_28 ;
V_22 -> V_36 = V_36 ;
if ( V_36 ) {
F_10 ( V_2 ,
L_5 ,
V_36 , V_22 -> V_12 , V_22 -> V_13 ,
F_3 ( V_22 -> V_14 . V_15 ) ,
F_3 ( V_22 -> V_14 . V_16 ) , V_22 -> V_5 ) ;
F_18 ( & V_2 -> V_24 -> V_37 ) ;
V_22 -> V_10 = false ;
F_6 ( V_38 , & V_22 -> V_39 ) ;
F_19 ( & V_2 -> V_24 -> V_37 ) ;
return;
}
F_18 ( & V_2 -> V_24 -> V_37 ) ;
V_22 -> V_10 = false ;
if ( V_22 -> V_17 ) {
F_20 ( V_38 , & V_22 -> V_39 ) ;
if ( V_22 -> V_5 != V_22 -> V_40 )
F_1 ( V_2 , V_22 , V_22 -> V_5 ,
false ) ;
} else {
F_6 ( V_38 , & V_22 -> V_39 ) ;
if ( V_22 -> V_5 != V_22 -> V_40 ) {
V_22 -> V_5 = V_22 -> V_40 ;
F_1 ( V_2 , V_22 ,
V_22 -> V_5 , true ) ;
}
}
F_19 ( & V_2 -> V_24 -> V_37 ) ;
}
void F_21 ( struct V_1 * V_2 , bool V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 <= V_43 ; V_42 ++ ) {
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_3 * V_22 ;
V_47 = & V_2 -> V_24 -> V_48 [ V_42 ] ;
F_22 (fltr, temp, head, node) {
bool V_49 = false ;
if ( V_2 -> V_39 != V_50 )
V_49 = true ;
F_18 ( & V_2 -> V_24 -> V_37 ) ;
if ( ( ! F_23 ( V_38 , & V_22 -> V_39 ) &&
! V_22 -> V_10 ) || V_41 ) {
F_14 ( V_2 ,
V_22 ) ;
} else {
bool V_51 = false ;
#ifdef F_24
V_51 = F_25 ( V_2 -> V_52 ,
V_22 -> V_5 ,
V_22 -> V_12 ,
V_22 -> V_13 ) ;
#endif
if ( ( V_51 || V_49 ) && ! V_41 )
F_1 ( V_2 , V_22 ,
V_22 -> V_5 ,
false ) ;
}
F_19 ( & V_2 -> V_24 -> V_37 ) ;
}
}
F_18 ( & V_2 -> V_24 -> V_37 ) ;
if ( ! V_2 -> V_24 -> V_32 ) {
if ( V_2 -> V_24 -> V_33 ) {
V_2 -> V_24 -> V_33 = false ;
V_2 -> V_9 -> V_34 ( V_2 -> V_19 , false ) ;
}
#ifdef F_24
} else {
F_20 ( V_53 , & V_2 -> V_54 ) ;
F_26 ( & V_2 -> V_55 ,
V_56 ) ;
#endif
}
F_19 ( & V_2 -> V_24 -> V_37 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
int V_57 = V_58 ;
while ( V_57 ) {
F_21 ( V_2 , false ) ;
if ( ! V_2 -> V_24 -> V_32 )
break;
F_28 ( 100 ) ;
V_57 -- ;
}
if ( ! V_57 ) {
F_10 ( V_2 , L_6 ) ;
F_21 ( V_2 , true ) ;
}
}
int F_29 ( struct V_1 * V_2 )
{
int V_42 ;
V_2 -> V_24 = F_30 ( sizeof( * V_2 -> V_24 ) ) ;
if ( ! V_2 -> V_24 )
return - V_30 ;
F_31 ( & V_2 -> V_24 -> V_37 ) ;
for ( V_42 = 0 ; V_42 <= V_43 ; V_42 ++ )
F_32 ( F_13 ( V_2 , V_42 ) ) ;
V_2 -> V_24 -> V_25 = F_30 ( F_33 ( V_59 ) *
sizeof( long ) ) ;
if ( ! V_2 -> V_24 -> V_25 ) {
F_34 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
return - V_30 ;
}
#ifdef F_24
V_2 -> V_52 -> V_60 = F_35 ( F_36 ( V_2 ) ) ;
if ( ! V_2 -> V_52 -> V_60 ) {
F_34 ( V_2 -> V_24 -> V_25 ) ;
V_2 -> V_24 -> V_25 = NULL ;
F_34 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
return - V_30 ;
}
#endif
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
#ifdef F_24
if ( V_2 -> V_52 -> V_60 )
F_38 ( V_2 -> V_52 -> V_60 ) ;
V_2 -> V_52 -> V_60 = NULL ;
#endif
F_34 ( V_2 -> V_24 -> V_25 ) ;
V_2 -> V_24 -> V_25 = NULL ;
F_34 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
static bool F_39 ( struct V_3 * V_61 ,
const struct V_62 * V_63 )
{
if ( V_63 -> V_64 == F_40 ( V_65 ) ) {
if ( V_61 -> V_14 . V_66 == F_41 ( V_63 ) -> V_67 &&
V_61 -> V_14 . V_68 == F_41 ( V_63 ) -> V_69 )
return true ;
else
return false ;
} else {
struct V_70 * V_71 = & V_61 -> V_14 . V_72 ;
T_2 V_73 = sizeof( struct V_70 ) ;
if ( ! memcmp ( V_71 , & F_42 ( V_63 ) -> V_67 , V_73 ) &&
! memcmp ( & V_61 -> V_14 . V_74 , & F_42 ( V_63 ) -> V_69 , V_73 ) )
return true ;
else
return false ;
}
}
static struct V_3 *
F_43 ( struct V_46 * V_75 , const struct V_62 * V_63 ,
T_3 V_15 , T_3 V_16 , T_2 V_76 )
{
struct V_3 * V_61 ;
F_44 (tpos, h, node)
if ( V_61 -> V_14 . V_76 == V_76 &&
V_61 -> V_14 . V_77 == V_63 -> V_64 &&
F_39 ( V_61 , V_63 ) &&
V_61 -> V_14 . V_15 == V_15 &&
V_61 -> V_14 . V_16 == V_16 )
return V_61 ;
return NULL ;
}
static struct V_3 *
F_45 ( struct V_1 * V_2 , int V_78 )
{
struct V_3 * V_4 ;
int V_79 ;
V_79 = F_46 ( V_2 -> V_24 -> V_25 ,
V_59 ) ;
if ( V_79 >= V_59 )
return NULL ;
V_4 = F_47 ( sizeof( * V_4 ) , V_80 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_23 = F_47 ( V_78 , V_80 ) ;
if ( ! V_4 -> V_23 ) {
F_5 ( V_4 ) ;
return NULL ;
}
V_4 -> V_13 = ( T_1 ) V_79 ;
F_20 ( V_79 , V_2 -> V_24 -> V_25 ) ;
return V_4 ;
}
int F_48 ( struct V_81 * V_28 , const struct V_62 * V_63 ,
T_1 V_82 , T_4 V_12 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
struct V_3 * V_4 ;
int V_78 , V_83 , V_84 ;
struct V_85 * V_86 ;
T_3 * V_87 ;
T_1 V_88 ;
T_2 V_76 ;
if ( V_63 -> V_89 )
return - V_90 ;
if ( V_63 -> V_64 != F_40 ( V_65 ) &&
V_63 -> V_64 != F_40 ( V_91 ) )
return - V_90 ;
if ( V_63 -> V_64 == F_40 ( V_65 ) ) {
V_76 = F_41 ( V_63 ) -> V_64 ;
V_84 = sizeof( struct V_92 ) ;
} else {
V_76 = F_42 ( V_63 ) -> V_93 ;
V_84 = sizeof( struct V_94 ) ;
}
if ( V_76 != V_95 && V_76 != V_96 )
return - V_90 ;
V_87 = ( T_3 * ) ( V_63 -> V_23 + V_84 ) ;
V_88 = F_50 ( V_63 ) & V_43 ;
F_18 ( & V_2 -> V_24 -> V_37 ) ;
V_4 = F_43 ( F_13 ( V_2 , V_88 ) ,
V_63 , V_87 [ 0 ] , V_87 [ 1 ] , V_76 ) ;
if ( V_4 ) {
V_4 -> V_40 = V_82 ;
if ( F_23 ( V_38 , & V_4 -> V_39 ) ) {
if ( V_4 -> V_5 != V_82 )
F_1 ( V_2 , V_4 , V_4 -> V_5 ,
false ) ;
} else {
if ( ! V_4 -> V_10 ) {
V_4 -> V_5 = V_82 ;
F_1 ( V_2 , V_4 , V_4 -> V_5 ,
true ) ;
}
}
V_83 = V_4 -> V_13 ;
goto V_97;
}
V_78 = V_98 + F_51 ( V_63 ) ;
V_4 = F_45 ( V_2 , V_78 ) ;
if ( ! V_4 ) {
V_83 = - V_30 ;
goto V_97;
}
V_4 -> V_21 = V_78 ;
V_4 -> V_5 = V_82 ;
V_4 -> V_40 = V_82 ;
V_4 -> V_14 . V_15 = V_87 [ 0 ] ;
V_4 -> V_14 . V_16 = V_87 [ 1 ] ;
V_4 -> V_12 = V_12 ;
if ( V_63 -> V_64 == F_40 ( V_65 ) ) {
V_4 -> V_14 . V_66 = F_41 ( V_63 ) -> V_67 ;
V_4 -> V_14 . V_68 = F_41 ( V_63 ) -> V_69 ;
} else {
memcpy ( & V_4 -> V_14 . V_72 , & F_42 ( V_63 ) -> V_67 ,
sizeof( struct V_70 ) ) ;
memcpy ( & V_4 -> V_14 . V_74 , & F_42 ( V_63 ) -> V_69 ,
sizeof( struct V_70 ) ) ;
}
V_86 = (struct V_85 * ) V_4 -> V_23 ;
V_86 -> V_99 = V_63 -> V_64 ;
V_4 -> V_14 . V_77 = V_63 -> V_64 ;
V_4 -> V_14 . V_76 = V_76 ;
memcpy ( V_4 -> V_23 + V_98 , V_63 -> V_23 , F_51 ( V_63 ) ) ;
V_83 = F_7 ( V_2 , V_4 , V_88 ) ;
if ( V_83 )
goto V_97;
F_1 ( V_2 , V_4 , V_4 -> V_5 , true ) ;
F_19 ( & V_2 -> V_24 -> V_37 ) ;
F_20 ( V_53 , & V_2 -> V_54 ) ;
F_26 ( & V_2 -> V_55 , 0 ) ;
return V_4 -> V_13 ;
V_97:
F_19 ( & V_2 -> V_24 -> V_37 ) ;
return V_83 ;
}
void F_52 ( void * V_28 , T_1 V_100 , T_1 V_101 )
{
struct V_1 * V_2 = V_28 ;
if ( V_2 -> V_102 != V_100 )
V_2 -> V_102 = 0 ;
if ( V_2 -> V_103 != V_101 )
V_2 -> V_103 = 0 ;
}
void F_53 ( void * V_28 , T_2 * V_104 , bool V_105 )
{
struct V_1 * V_2 = V_28 ;
F_54 ( V_2 ) ;
if ( F_55 ( V_2 -> V_52 -> V_106 ) && ! V_105 ) {
F_56 ( V_2 ) ;
return;
}
F_57 ( V_2 -> V_52 -> V_106 , V_104 ) ;
F_56 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_107 * V_108 , T_2 * V_109 )
{
bool V_110 = false ;
int V_42 ;
if ( F_36 ( V_2 ) <= 1 ) {
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
* V_109 = 0 ;
return;
}
for ( V_42 = 0 ; V_42 < V_111 ; V_42 ++ ) {
if ( V_2 -> V_112 [ V_42 ] >= F_36 ( V_2 ) ) {
V_110 = true ;
break;
}
}
if ( ! ( V_2 -> V_113 & V_114 ) || V_110 ) {
for ( V_42 = 0 ; V_42 < V_111 ; V_42 ++ ) {
T_1 V_115 , V_116 ;
V_116 = F_36 ( V_2 ) ;
V_115 = F_59 ( V_42 , V_116 ) ;
V_2 -> V_112 [ V_42 ] = V_115 ;
}
V_2 -> V_113 |= V_114 ;
}
for ( V_42 = 0 ; V_42 < V_111 ; V_42 ++ ) {
T_1 V_117 = F_60 ( V_2 , V_2 -> V_112 [ V_42 ] ) ;
V_108 -> V_112 [ V_42 ] = V_2 -> V_118 [ V_117 ] . V_119 -> V_120 ;
}
if ( ! ( V_2 -> V_113 & V_121 ) ) {
F_61 ( V_2 -> V_122 , sizeof( V_2 -> V_122 ) ) ;
V_2 -> V_113 |= V_121 ;
}
memcpy ( V_108 -> V_122 , V_2 -> V_122 , sizeof( V_108 -> V_122 ) ) ;
if ( ! ( V_2 -> V_113 & V_123 ) ) {
V_2 -> V_124 = V_125 | V_126 |
V_127 | V_128 ;
V_2 -> V_113 |= V_123 ;
}
V_108 -> V_124 = V_2 -> V_124 ;
* V_109 = 1 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_129 V_130 ,
unsigned char V_104 [ V_131 ] )
{
struct V_132 V_133 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_134 ;
V_133 . V_35 . V_135 . type = V_130 ;
V_133 . V_35 . V_135 . V_136 = 1 ;
F_57 ( V_133 . V_35 . V_135 . V_104 , V_104 ) ;
return V_2 -> V_9 -> V_137 ( V_2 -> V_19 , & V_133 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
enum V_129 V_130 ,
T_1 V_138 )
{
struct V_132 V_133 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_134 ;
V_133 . V_35 . V_135 . type = V_130 ;
V_133 . V_35 . V_135 . V_139 = 1 ;
V_133 . V_35 . V_135 . V_140 = V_138 ;
return V_2 -> V_9 -> V_137 ( V_2 -> V_19 , & V_133 ) ;
}
static int F_64 ( struct V_1 * V_2 , bool V_141 )
{
struct V_142 * V_143 ;
int V_83 ;
if ( V_2 -> V_144 == V_141 )
return 0 ;
V_143 = F_30 ( sizeof( * V_143 ) ) ;
if ( ! V_143 )
return - V_30 ;
V_143 -> V_145 = 0 ;
V_143 -> V_144 = V_141 ;
V_143 -> V_146 = 1 ;
V_83 = V_2 -> V_9 -> V_147 ( V_2 -> V_19 , V_143 ) ;
if ( V_83 ) {
F_65 ( V_2 , L_7 ,
V_141 ? L_8 : L_9 ) ;
} else {
F_66 ( V_2 , L_10 ,
V_141 ? L_11 : L_12 ) ;
V_2 -> V_144 = V_141 ;
}
F_34 ( V_143 ) ;
return 0 ;
}
int F_67 ( struct V_81 * V_28 , T_3 V_148 , T_1 V_138 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
struct V_149 * V_140 , * V_150 ;
int V_83 = 0 ;
F_2 ( V_2 , V_151 , L_13 , V_138 ) ;
V_140 = F_47 ( sizeof( * V_140 ) , V_152 ) ;
if ( ! V_140 ) {
F_66 ( V_2 , L_14 ) ;
return - V_30 ;
}
F_68 ( & V_140 -> V_153 ) ;
V_140 -> V_138 = V_138 ;
V_140 -> V_154 = false ;
F_69 (tmp, &edev->vlan_list, list) {
if ( V_150 -> V_138 == V_140 -> V_138 ) {
F_2 ( V_2 , ( V_151 | V_155 ) ,
L_15 ) ;
F_5 ( V_140 ) ;
return - V_156 ;
}
}
F_54 ( V_2 ) ;
if ( V_2 -> V_39 != V_50 ) {
F_2 ( V_2 , V_155 ,
L_16 ,
V_138 ) ;
if ( V_138 != 0 )
V_2 -> V_157 ++ ;
F_70 ( & V_140 -> V_153 , & V_2 -> V_158 ) ;
goto V_159;
}
if ( ( V_2 -> V_160 < V_2 -> V_161 . V_162 ) ||
( V_140 -> V_138 == 0 ) ) {
V_83 = F_63 ( V_2 ,
V_163 ,
V_140 -> V_138 ) ;
if ( V_83 ) {
F_65 ( V_2 , L_17 ,
V_140 -> V_138 ) ;
F_5 ( V_140 ) ;
goto V_159;
}
V_140 -> V_154 = true ;
if ( V_140 -> V_138 != 0 )
V_2 -> V_160 ++ ;
} else {
if ( ! V_2 -> V_157 ) {
V_83 = F_64 ( V_2 , true ) ;
if ( V_83 ) {
F_5 ( V_140 ) ;
goto V_159;
}
}
V_2 -> V_157 ++ ;
}
F_70 ( & V_140 -> V_153 , & V_2 -> V_158 ) ;
V_159:
F_56 ( V_2 ) ;
return V_83 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_149 * V_140 )
{
if ( V_140 -> V_138 != 0 ) {
if ( V_140 -> V_154 )
V_2 -> V_160 -- ;
else
V_2 -> V_157 -- ;
}
F_72 ( & V_140 -> V_153 ) ;
F_5 ( V_140 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_83 = 0 , V_164 = 0 , V_144 = 0 ;
struct V_165 * V_161 ;
struct V_149 * V_140 = NULL ;
if ( F_74 ( & V_2 -> V_158 ) )
return 0 ;
V_161 = & V_2 -> V_161 ;
F_69 (vlan, &edev->vlan_list, list) {
if ( V_140 -> V_154 )
continue;
if ( ( V_140 -> V_138 != 0 ) &&
( V_2 -> V_160 == V_161 -> V_162 ) ) {
V_144 = 1 ;
continue;
}
F_2 ( V_2 , V_151 , L_18 , V_140 -> V_138 ) ;
V_83 = F_63 ( V_2 , V_163 ,
V_140 -> V_138 ) ;
if ( V_83 ) {
F_65 ( V_2 , L_19 ,
V_140 -> V_138 ) ;
V_164 = V_83 ;
continue;
}
V_140 -> V_154 = true ;
if ( V_140 -> V_138 != 0 ) {
V_2 -> V_157 -- ;
V_2 -> V_160 ++ ;
}
}
if ( V_144 )
V_83 = F_64 ( V_2 , true ) ;
else if ( ! V_2 -> V_157 )
V_83 = F_64 ( V_2 , false ) ;
if ( V_83 && ! V_164 )
V_164 = V_83 ;
return V_164 ;
}
int F_75 ( struct V_81 * V_28 , T_3 V_148 , T_1 V_138 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
struct V_149 * V_140 = NULL ;
int V_83 = 0 ;
F_2 ( V_2 , V_155 , L_20 , V_138 ) ;
F_54 ( V_2 ) ;
F_69 (vlan, &edev->vlan_list, list)
if ( V_140 -> V_138 == V_138 )
break;
if ( ! V_140 || ( V_140 -> V_138 != V_138 ) ) {
F_2 ( V_2 , ( V_151 | V_155 ) ,
L_21 ) ;
goto V_159;
}
if ( V_2 -> V_39 != V_50 ) {
F_2 ( V_2 , V_155 ,
L_22 ) ;
F_71 ( V_2 , V_140 ) ;
goto V_159;
}
if ( V_140 -> V_154 ) {
V_83 = F_63 ( V_2 , V_166 ,
V_138 ) ;
if ( V_83 ) {
F_65 ( V_2 , L_23 , V_138 ) ;
goto V_159;
}
}
F_71 ( V_2 , V_140 ) ;
V_83 = F_73 ( V_2 ) ;
V_159:
F_56 ( V_2 ) ;
return V_83 ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_149 * V_140 = NULL ;
if ( F_74 ( & V_2 -> V_158 ) )
return;
F_69 (vlan, &edev->vlan_list, list) {
if ( ! V_140 -> V_154 )
continue;
V_140 -> V_154 = false ;
if ( V_140 -> V_138 != 0 ) {
V_2 -> V_157 ++ ;
V_2 -> V_160 -- ;
}
F_2 ( V_2 , V_155 ,
L_24 , V_140 -> V_138 ) ;
}
V_2 -> V_144 = false ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_167 * args )
{
V_2 -> V_52 -> V_168 = args -> V_169 . V_168 ;
}
int F_78 ( struct V_81 * V_28 , T_5 V_168 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
T_5 V_170 = V_168 ^ V_28 -> V_168 ;
bool V_171 = false ;
if ( V_170 & V_172 ) {
if ( V_28 -> V_168 & V_172 )
V_171 = ! V_2 -> V_173 ;
else
V_171 = V_2 -> V_173 ;
}
if ( V_171 ) {
struct V_167 args ;
args . V_169 . V_168 = V_168 ;
args . V_174 = & F_77 ;
F_54 ( V_2 ) ;
if ( V_2 -> V_175 )
args . V_174 ( V_2 , & args ) ;
else
F_79 ( V_2 , & args , true ) ;
F_56 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_80 ( struct V_81 * V_28 , struct V_176 * V_177 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
struct V_178 V_179 ;
T_1 V_180 = F_3 ( V_177 -> V_181 ) ;
int V_83 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
switch ( V_177 -> type ) {
case V_182 :
if ( ! V_2 -> V_161 . V_183 . V_184 )
return;
if ( V_2 -> V_102 )
return;
V_179 . V_185 = 1 ;
V_179 . V_100 = V_180 ;
F_54 ( V_2 ) ;
V_83 = V_2 -> V_9 -> V_186 ( V_2 -> V_19 , & V_179 ) ;
F_56 ( V_2 ) ;
if ( ! V_83 ) {
V_2 -> V_102 = V_180 ;
F_2 ( V_2 , V_187 , L_25 ,
V_180 ) ;
} else {
F_10 ( V_2 , L_26 ,
V_180 ) ;
}
break;
case V_188 :
if ( ! V_2 -> V_161 . V_183 . V_189 )
return;
if ( V_2 -> V_103 )
return;
V_179 . V_190 = 1 ;
V_179 . V_101 = V_180 ;
F_54 ( V_2 ) ;
V_83 = V_2 -> V_9 -> V_186 ( V_2 -> V_19 , & V_179 ) ;
F_56 ( V_2 ) ;
if ( ! V_83 ) {
V_2 -> V_103 = V_180 ;
F_2 ( V_2 , V_187 ,
L_27 , V_180 ) ;
} else {
F_10 ( V_2 , L_28 ,
V_180 ) ;
}
break;
default:
return;
}
}
void F_81 ( struct V_81 * V_28 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
struct V_178 V_179 ;
T_1 V_180 = F_3 ( V_177 -> V_181 ) ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
switch ( V_177 -> type ) {
case V_182 :
if ( V_180 != V_2 -> V_102 )
return;
V_179 . V_185 = 1 ;
V_179 . V_100 = 0 ;
F_54 ( V_2 ) ;
V_2 -> V_9 -> V_186 ( V_2 -> V_19 , & V_179 ) ;
F_56 ( V_2 ) ;
V_2 -> V_102 = 0 ;
F_2 ( V_2 , V_187 , L_29 ,
V_180 ) ;
break;
case V_188 :
if ( V_180 != V_2 -> V_103 )
return;
V_179 . V_190 = 1 ;
V_179 . V_101 = 0 ;
F_54 ( V_2 ) ;
V_2 -> V_9 -> V_186 ( V_2 -> V_19 , & V_179 ) ;
F_56 ( V_2 ) ;
V_2 -> V_103 = 0 ;
F_2 ( V_2 , V_187 , L_30 ,
V_180 ) ;
break;
default:
return;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_167 * args )
{
struct V_191 * V_192 ;
V_192 = F_83 ( & V_2 -> V_175 , args -> V_169 . V_193 ) ;
if ( V_192 )
F_84 ( V_192 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_191 * V_194 )
{
struct V_167 args ;
args . V_174 = & F_82 ;
args . V_169 . V_193 = V_194 ;
F_79 ( V_2 , & args , false ) ;
return 0 ;
}
int F_86 ( struct V_81 * V_28 , struct V_195 * V_196 )
{
struct V_1 * V_2 = F_49 ( V_28 ) ;
switch ( V_196 -> V_197 ) {
case V_198 :
return F_85 ( V_2 , V_196 -> V_194 ) ;
case V_199 :
V_196 -> V_200 = ! ! V_2 -> V_175 ;
V_196 -> V_201 = V_2 -> V_175 ? V_2 -> V_175 -> V_202 -> V_203 : 0 ;
return 0 ;
default:
return - V_204 ;
}
}
static int F_87 ( struct V_1 * V_2 ,
enum V_129 V_130 ,
unsigned char * V_104 , int V_205 )
{
struct V_132 V_133 ;
int V_42 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_206 ;
V_133 . V_35 . V_207 . type = V_130 ;
V_133 . V_35 . V_207 . V_208 = V_205 ;
for ( V_42 = 0 ; V_42 < V_205 ; V_42 ++ , V_104 += V_131 )
F_57 ( V_133 . V_35 . V_207 . V_104 [ V_42 ] , V_104 ) ;
return V_2 -> V_9 -> V_137 ( V_2 -> V_19 , & V_133 ) ;
}
int F_88 ( struct V_81 * V_52 , void * V_209 )
{
struct V_1 * V_2 = F_49 ( V_52 ) ;
struct V_210 * V_211 = V_209 ;
int V_83 = 0 ;
F_54 ( V_2 ) ;
if ( ! F_55 ( V_211 -> V_212 ) ) {
F_10 ( V_2 , L_31 ) ;
V_83 = - V_213 ;
goto V_159;
}
if ( ! V_2 -> V_9 -> V_214 ( V_2 -> V_19 , V_211 -> V_212 ) ) {
F_10 ( V_2 , L_32 ,
V_211 -> V_212 ) ;
V_83 = - V_204 ;
goto V_159;
}
if ( V_2 -> V_39 == V_50 ) {
V_83 = F_62 ( V_2 , V_166 ,
V_52 -> V_106 ) ;
if ( V_83 )
goto V_159;
}
F_57 ( V_52 -> V_106 , V_211 -> V_212 ) ;
F_66 ( V_2 , L_33 , V_211 -> V_212 ) ;
if ( V_2 -> V_39 != V_50 ) {
F_2 ( V_2 , V_155 ,
L_34 ) ;
goto V_159;
}
V_2 -> V_9 -> V_183 -> V_215 ( V_2 -> V_19 , V_52 -> V_106 ) ;
V_83 = F_62 ( V_2 , V_163 ,
V_52 -> V_106 ) ;
V_159:
F_56 ( V_2 ) ;
return V_83 ;
}
static int
F_89 ( struct V_81 * V_52 ,
enum V_216 * V_217 )
{
struct V_1 * V_2 = F_49 ( V_52 ) ;
unsigned char * V_218 , * V_45 ;
struct V_219 * V_220 ;
int V_83 = 0 , V_221 ;
T_6 V_73 ;
V_73 = 64 * V_131 ;
V_218 = F_47 ( V_73 , V_152 ) ;
if ( ! V_218 ) {
F_10 ( V_2 ,
L_35 ) ;
V_83 = - V_30 ;
goto exit;
}
V_45 = V_218 ;
V_83 = F_87 ( V_2 , V_166 ,
V_218 , 1 ) ;
if ( V_83 )
goto exit;
F_90 ( V_52 ) ;
V_221 = F_91 ( V_52 ) ;
if ( V_221 < 64 ) {
F_92 (ha, ndev) {
F_57 ( V_45 , V_220 -> V_211 ) ;
V_45 += V_131 ;
}
}
F_93 ( V_52 ) ;
if ( ( V_52 -> V_222 & V_223 ) || ( V_221 > 64 ) ) {
if ( * V_217 == V_224 )
* V_217 = V_225 ;
} else {
V_83 = F_87 ( V_2 , V_163 ,
V_218 , V_221 ) ;
}
exit:
F_5 ( V_218 ) ;
return V_83 ;
}
void F_94 ( struct V_81 * V_52 )
{
struct V_1 * V_2 = F_49 ( V_52 ) ;
F_20 ( V_226 , & V_2 -> V_54 ) ;
F_26 ( & V_2 -> V_55 , 0 ) ;
}
void F_95 ( struct V_81 * V_52 )
{
enum V_216 V_217 ;
struct V_1 * V_2 = F_49 ( V_52 ) ;
struct V_132 V_227 ;
unsigned char * V_228 , * V_45 ;
struct V_219 * V_220 ;
int V_83 , V_229 ;
T_6 V_73 ;
F_90 ( V_52 ) ;
V_229 = F_96 ( V_52 ) ;
V_73 = V_229 * V_131 ;
V_228 = F_47 ( V_73 , V_80 ) ;
if ( ! V_228 ) {
F_10 ( V_2 , L_36 ) ;
F_93 ( V_52 ) ;
return;
}
V_45 = V_228 ;
F_97 (ha, ndev) {
F_57 ( V_45 , V_220 -> V_211 ) ;
V_45 += V_131 ;
}
F_93 ( V_52 ) ;
memset ( & V_227 , 0 , sizeof( struct V_132 ) ) ;
V_227 . type = V_230 ;
V_83 = F_62 ( V_2 , V_231 ,
V_2 -> V_52 -> V_106 ) ;
if ( V_83 )
goto V_159;
if ( V_52 -> V_222 & V_232 )
V_217 = V_233 ;
else
V_217 = V_224 ;
if ( V_229 < V_2 -> V_161 . V_234 ) {
int V_42 ;
V_45 = V_228 ;
for ( V_42 = 0 ; V_42 < V_229 ; V_42 ++ ) {
V_83 = F_62 ( V_2 ,
V_163 ,
V_45 ) ;
if ( V_83 )
goto V_159;
V_45 += V_131 ;
}
} else {
V_217 = V_233 ;
}
V_83 = F_89 ( V_52 , & V_217 ) ;
if ( V_83 )
goto V_159;
if ( V_52 -> V_222 & V_232 ) {
F_64 ( V_2 , true ) ;
} else if ( ! V_2 -> V_157 ) {
F_64 ( V_2 , false ) ;
}
V_227 . V_35 . V_217 = V_217 ;
V_2 -> V_9 -> V_137 ( V_2 -> V_19 , & V_227 ) ;
V_159:
F_5 ( V_228 ) ;
}
static struct V_3 *
F_98 ( struct V_46 * V_47 , T_4 V_235 )
{
struct V_3 * V_22 ;
F_44 (fltr, head, node)
if ( V_235 == V_22 -> V_13 )
return V_22 ;
return NULL ;
}
static bool
F_99 ( struct V_3 * V_61 ,
struct V_236 * V_237 ,
T_3 V_148 )
{
if ( V_148 == F_40 ( V_65 ) ) {
struct V_238 * V_239 ;
V_239 = & V_237 -> V_240 . V_241 ;
if ( V_61 -> V_14 . V_66 == V_239 -> V_242 &&
V_61 -> V_14 . V_68 == V_239 -> V_243 )
return true ;
else
return false ;
} else {
struct V_244 * V_245 ;
struct V_70 * V_71 ;
V_245 = & V_237 -> V_240 . V_246 ;
V_71 = & V_61 -> V_14 . V_72 ;
if ( ! memcmp ( V_71 , & V_245 -> V_247 , sizeof( struct V_70 ) ) &&
! memcmp ( & V_61 -> V_14 . V_74 , & V_245 -> V_248 ,
sizeof( struct V_70 ) ) )
return true ;
else
return false ;
}
return false ;
}
int F_100 ( struct V_1 * V_2 , struct V_249 * V_250 ,
T_4 * V_251 )
{
struct V_3 * V_22 ;
struct V_46 * V_47 ;
int V_252 = 0 , V_83 = 0 ;
V_250 -> V_23 = V_59 ;
F_54 ( V_2 ) ;
if ( ! V_2 -> V_24 ) {
V_83 = - V_253 ;
goto V_254;
}
V_47 = F_13 ( V_2 , 0 ) ;
F_44 (fltr, head, node) {
if ( V_252 == V_250 -> V_255 ) {
V_83 = - V_256 ;
goto V_254;
}
V_251 [ V_252 ] = V_22 -> V_13 ;
V_252 ++ ;
}
V_250 -> V_255 = V_252 ;
V_254:
F_56 ( V_2 ) ;
return V_83 ;
}
int F_101 ( struct V_1 * V_2 , struct V_249 * V_257 )
{
struct V_236 * V_237 = & V_257 -> V_258 ;
struct V_3 * V_22 = NULL ;
int V_83 = 0 ;
V_257 -> V_23 = V_59 ;
F_54 ( V_2 ) ;
if ( ! V_2 -> V_24 ) {
V_83 = - V_253 ;
goto V_254;
}
V_22 = F_98 ( F_13 ( V_2 , 0 ) ,
V_237 -> V_235 ) ;
if ( ! V_22 ) {
F_10 ( V_2 , L_37 ,
V_237 -> V_235 ) ;
V_83 = - V_204 ;
goto V_254;
}
if ( V_22 -> V_14 . V_77 == F_40 ( V_65 ) ) {
if ( V_22 -> V_14 . V_76 == V_95 )
V_237 -> V_259 = V_260 ;
else
V_237 -> V_259 = V_261 ;
V_237 -> V_240 . V_241 . V_262 = V_22 -> V_14 . V_15 ;
V_237 -> V_240 . V_241 . V_263 = V_22 -> V_14 . V_16 ;
V_237 -> V_240 . V_241 . V_242 = V_22 -> V_14 . V_66 ;
V_237 -> V_240 . V_241 . V_243 = V_22 -> V_14 . V_68 ;
} else {
if ( V_22 -> V_14 . V_76 == V_95 )
V_237 -> V_259 = V_264 ;
else
V_237 -> V_259 = V_265 ;
V_237 -> V_240 . V_246 . V_262 = V_22 -> V_14 . V_15 ;
V_237 -> V_240 . V_246 . V_263 = V_22 -> V_14 . V_16 ;
memcpy ( & V_237 -> V_240 . V_246 . V_247 ,
& V_22 -> V_14 . V_72 , sizeof( struct V_70 ) ) ;
memcpy ( & V_237 -> V_240 . V_246 . V_248 ,
& V_22 -> V_14 . V_74 , sizeof( struct V_70 ) ) ;
}
V_237 -> V_266 = V_22 -> V_5 ;
V_254:
F_56 ( V_2 ) ;
return V_83 ;
}
static int
F_102 ( struct V_1 * V_2 ,
struct V_236 * V_237 ,
int * V_78 )
{
T_3 V_15 = 0x0 , V_16 = 0x0 ;
struct V_3 * V_22 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_3 V_77 ;
T_2 V_76 ;
if ( V_237 -> V_235 >= V_59 ||
V_237 -> V_266 >= F_36 ( V_2 ) )
return - V_204 ;
if ( V_237 -> V_259 == V_260 ) {
* V_78 += sizeof( struct V_92 ) +
sizeof( struct V_267 ) ;
V_77 = F_40 ( V_65 ) ;
V_76 = V_95 ;
} else if ( V_237 -> V_259 == V_261 ) {
* V_78 += sizeof( struct V_92 ) +
sizeof( struct V_268 ) ;
V_77 = F_40 ( V_65 ) ;
V_76 = V_96 ;
} else if ( V_237 -> V_259 == V_264 ) {
* V_78 += sizeof( struct V_94 ) +
sizeof( struct V_267 ) ;
V_77 = F_40 ( V_91 ) ;
V_76 = V_95 ;
} else if ( V_237 -> V_259 == V_265 ) {
* V_78 += sizeof( struct V_94 ) +
sizeof( struct V_268 ) ;
V_77 = F_40 ( V_91 ) ;
V_76 = V_96 ;
} else {
F_10 ( V_2 , L_38 ,
V_237 -> V_259 ) ;
return - V_90 ;
}
if ( V_77 == F_40 ( V_65 ) ) {
V_15 = V_237 -> V_240 . V_241 . V_262 ;
V_16 = V_237 -> V_240 . V_241 . V_263 ;
} else {
V_15 = V_237 -> V_240 . V_246 . V_262 ;
V_16 = V_237 -> V_240 . V_246 . V_263 ;
}
V_47 = F_13 ( V_2 , 0 ) ;
F_22 (fltr, temp, head, node) {
if ( ( V_22 -> V_14 . V_76 == V_76 &&
V_22 -> V_14 . V_77 == V_77 &&
F_99 ( V_22 , V_237 , V_77 ) &&
V_22 -> V_14 . V_15 == V_15 &&
V_22 -> V_14 . V_16 == V_16 ) ||
V_22 -> V_13 == V_237 -> V_235 )
return - V_156 ;
}
return 0 ;
}
static int
F_103 ( struct V_1 * V_2 ,
struct V_3 * V_22 )
{
int V_57 = V_58 ;
while ( V_22 -> V_10 && V_57 ) {
F_28 ( 20 ) ;
V_57 -- ;
}
if ( V_57 == 0 || V_22 -> V_36 ) {
F_14 ( V_2 , V_22 ) ;
return - V_269 ;
}
return V_22 -> V_36 ;
}
int F_104 ( struct V_1 * V_2 , struct V_249 * V_250 )
{
struct V_236 * V_237 = & V_250 -> V_258 ;
struct V_3 * V_4 ;
int V_78 = V_98 , V_83 ;
struct V_85 * V_86 ;
struct V_92 * V_239 ;
T_3 * V_87 ;
F_54 ( V_2 ) ;
if ( ! V_2 -> V_24 ) {
V_83 = - V_253 ;
goto V_254;
}
V_83 = F_102 ( V_2 , V_237 , & V_78 ) ;
if ( V_83 )
goto V_254;
V_4 = F_47 ( sizeof( * V_4 ) , V_152 ) ;
if ( ! V_4 ) {
V_83 = - V_30 ;
goto V_254;
}
V_4 -> V_23 = F_47 ( V_78 , V_152 ) ;
if ( ! V_4 -> V_23 ) {
F_5 ( V_4 ) ;
V_83 = - V_30 ;
goto V_254;
}
V_4 -> V_13 = V_237 -> V_235 ;
F_20 ( V_4 -> V_13 , V_2 -> V_24 -> V_25 ) ;
V_4 -> V_21 = V_78 ;
V_4 -> V_5 = V_237 -> V_266 ;
V_4 -> V_40 = V_4 -> V_5 ;
V_86 = (struct V_85 * ) V_4 -> V_23 ;
if ( V_250 -> V_258 . V_259 == V_260 ||
V_250 -> V_258 . V_259 == V_261 ) {
V_87 = ( T_3 * ) ( V_4 -> V_23 + V_98 +
sizeof( struct V_92 ) ) ;
V_86 -> V_99 = F_40 ( V_65 ) ;
V_4 -> V_14 . V_77 = F_40 ( V_65 ) ;
V_4 -> V_14 . V_66 = V_250 -> V_258 . V_240 . V_241 . V_242 ;
V_4 -> V_14 . V_68 = V_250 -> V_258 . V_240 . V_241 . V_243 ;
V_4 -> V_14 . V_15 = V_250 -> V_258 . V_240 . V_241 . V_262 ;
V_4 -> V_14 . V_16 = V_250 -> V_258 . V_240 . V_241 . V_263 ;
V_87 [ 0 ] = V_4 -> V_14 . V_15 ;
V_87 [ 1 ] = V_4 -> V_14 . V_16 ;
V_239 = (struct V_92 * ) ( V_4 -> V_23 + V_98 ) ;
V_239 -> V_67 = V_250 -> V_258 . V_240 . V_241 . V_242 ;
V_239 -> V_69 = V_250 -> V_258 . V_240 . V_241 . V_243 ;
V_239 -> V_270 = 0x4 ;
V_239 -> V_271 = 0x5 ;
if ( V_250 -> V_258 . V_259 == V_260 ) {
V_4 -> V_14 . V_76 = V_95 ;
V_239 -> V_64 = V_95 ;
} else {
V_4 -> V_14 . V_76 = V_96 ;
V_239 -> V_64 = V_96 ;
}
V_239 -> V_272 = F_105 ( V_78 - V_98 ) ;
} else {
struct V_94 * V_245 ;
V_245 = (struct V_94 * ) ( V_4 -> V_23 + V_98 ) ;
V_87 = ( T_3 * ) ( V_4 -> V_23 + V_98 +
sizeof( struct V_94 ) ) ;
V_86 -> V_99 = F_40 ( V_91 ) ;
V_4 -> V_14 . V_77 = F_40 ( V_91 ) ;
memcpy ( & V_4 -> V_14 . V_72 , & V_250 -> V_258 . V_240 . V_246 . V_247 ,
sizeof( struct V_70 ) ) ;
memcpy ( & V_4 -> V_14 . V_74 , & V_250 -> V_258 . V_240 . V_246 . V_248 ,
sizeof( struct V_70 ) ) ;
V_4 -> V_14 . V_15 = V_250 -> V_258 . V_240 . V_246 . V_262 ;
V_4 -> V_14 . V_16 = V_250 -> V_258 . V_240 . V_246 . V_263 ;
V_87 [ 0 ] = V_4 -> V_14 . V_15 ;
V_87 [ 1 ] = V_4 -> V_14 . V_16 ;
memcpy ( & V_245 -> V_67 , & V_4 -> V_14 . V_72 ,
sizeof( struct V_70 ) ) ;
memcpy ( & V_245 -> V_69 , & V_4 -> V_14 . V_74 ,
sizeof( struct V_70 ) ) ;
V_245 -> V_270 = 0x6 ;
if ( V_250 -> V_258 . V_259 == V_264 ) {
V_4 -> V_14 . V_76 = V_95 ;
V_245 -> V_93 = V_273 ;
V_245 -> V_274 = F_105 ( sizeof( struct V_267 ) ) ;
} else {
V_4 -> V_14 . V_76 = V_96 ;
V_245 -> V_93 = V_275 ;
V_245 -> V_274 = F_105 ( sizeof( struct V_268 ) ) ;
}
}
V_83 = F_7 ( V_2 , V_4 , 0 ) ;
if ( V_83 )
goto V_254;
F_1 ( V_2 , V_4 , V_4 -> V_5 , true ) ;
V_83 = F_103 ( V_2 , V_4 ) ;
V_254:
F_56 ( V_2 ) ;
return V_83 ;
}
int F_106 ( struct V_1 * V_2 , struct V_249 * V_250 )
{
struct V_236 * V_237 = & V_250 -> V_258 ;
struct V_3 * V_22 = NULL ;
int V_83 = - V_253 ;
F_54 ( V_2 ) ;
if ( ! V_2 -> V_24 )
goto V_254;
V_22 = F_98 ( F_13 ( V_2 , 0 ) ,
V_237 -> V_235 ) ;
if ( ! V_22 )
goto V_254;
F_1 ( V_2 , V_22 , V_22 -> V_5 , false ) ;
V_83 = F_103 ( V_2 , V_22 ) ;
if ( V_83 == 0 )
F_14 ( V_2 , V_22 ) ;
V_254:
F_56 ( V_2 ) ;
return V_83 ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
F_54 ( V_2 ) ;
if ( ! V_2 -> V_24 )
goto V_254;
V_57 = V_2 -> V_24 -> V_32 ;
V_254:
F_56 ( V_2 ) ;
return V_57 ;
}
