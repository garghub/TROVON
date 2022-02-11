static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_4 -> V_7 ) ;
int V_8 ;
if ( F_2 ( V_6 -> V_9 ) == V_10 ) {
struct V_11 V_12 ;
struct V_3 * V_13 ;
F_3 ( & V_12 ) ;
F_4 ( V_4 , F_2 ( V_6 -> V_14 ) ) ;
F_5 ( V_4 , F_2 ( V_6 -> V_15 ) ) ;
F_6 ( V_4 , & V_12 , V_2 -> V_16 ,
V_2 -> V_17 . V_18 , 0 , false ) ;
while ( ! F_7 ( & V_12 ) ) {
struct V_19 * V_20 ;
V_13 = F_8 ( & V_12 ) ;
V_20 = (struct V_19 * ) V_13 -> V_7 ;
if ( F_9 ( V_2 -> V_21 -> V_22 ) &&
F_10 ( V_20 -> V_23 . V_24 ) == V_25 ) {
F_11 ( V_2 ,
( V_26 * ) V_20 ,
V_4 -> V_27 ) ;
}
if ( V_2 -> V_28 == V_29 )
V_8 = F_12 ( V_2 , V_13 ) ;
else
V_8 = F_13 ( V_2 , V_13 ) ;
if ( V_8 == - 1 )
F_14 ( V_2 -> V_21 , ERROR ,
L_1 ) ;
}
return 0 ;
}
return - 1 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_30 )
{
int V_8 = F_1 ( V_2 , V_30 ) ;
if ( ! V_8 )
return 0 ;
if ( V_2 -> V_28 == V_29 )
return F_16 ( V_2 , V_30 ) ;
return F_17 ( V_2 , V_30 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
int V_33 )
{
int V_34 , V_35 ;
void * V_36 ;
unsigned long V_37 ;
V_34 = ( V_33 > V_32 -> V_33 ) ?
F_19 ( ( V_33 - V_32 -> V_33 ) , V_32 -> V_38 ) :
V_32 -> V_38 ;
for ( V_35 = 0 ; V_35 < V_34 ; ++ V_35 ) {
F_20 ( & V_2 -> V_39 , V_37 ) ;
V_36 = NULL ;
if ( V_32 -> V_40 [ V_35 ] ) {
V_36 = V_32 -> V_40 [ V_35 ] ;
V_32 -> V_40 [ V_35 ] = NULL ;
}
F_21 ( & V_2 -> V_39 , V_37 ) ;
if ( V_36 )
F_15 ( V_2 , V_36 ) ;
}
F_20 ( & V_2 -> V_39 , V_37 ) ;
for ( V_35 = 0 ; V_35 < V_32 -> V_38 - V_34 ; ++ V_35 ) {
V_32 -> V_40 [ V_35 ] = V_32 -> V_40 [ V_34 + V_35 ] ;
V_32 -> V_40 [ V_34 + V_35 ] = NULL ;
}
V_32 -> V_33 = V_33 ;
F_21 ( & V_2 -> V_39 , V_37 ) ;
}
static void
F_22 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_35 , V_41 , V_42 ;
void * V_36 ;
unsigned long V_37 ;
for ( V_35 = 0 ; V_35 < V_32 -> V_38 ; ++ V_35 ) {
F_20 ( & V_2 -> V_39 , V_37 ) ;
if ( ! V_32 -> V_40 [ V_35 ] ) {
F_21 ( & V_2 -> V_39 , V_37 ) ;
break;
}
V_36 = V_32 -> V_40 [ V_35 ] ;
V_32 -> V_40 [ V_35 ] = NULL ;
F_21 ( & V_2 -> V_39 , V_37 ) ;
F_15 ( V_2 , V_36 ) ;
}
F_20 ( & V_2 -> V_39 , V_37 ) ;
if ( V_35 > 0 ) {
V_42 = V_32 -> V_38 - V_35 ;
for ( V_41 = 0 ; V_41 < V_42 ; ++ V_41 ) {
V_32 -> V_40 [ V_41 ] = V_32 -> V_40 [ V_35 + V_41 ] ;
V_32 -> V_40 [ V_35 + V_41 ] = NULL ;
}
}
V_32 -> V_33 = ( V_32 -> V_33 + V_35 ) & ( V_43 - 1 ) ;
F_21 ( & V_2 -> V_39 , V_37 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
unsigned long V_37 ;
int V_33 ;
if ( ! V_32 )
return;
F_20 ( & V_2 -> V_21 -> V_44 , V_37 ) ;
V_2 -> V_21 -> V_45 = true ;
if ( V_2 -> V_21 -> V_46 ) {
F_21 ( & V_2 -> V_21 -> V_44 , V_37 ) ;
F_24 ( V_2 -> V_21 -> V_47 ) ;
} else {
F_21 ( & V_2 -> V_21 -> V_44 , V_37 ) ;
}
V_33 = ( V_32 -> V_33 + V_32 -> V_38 ) & ( V_43 - 1 ) ;
F_18 ( V_2 , V_32 , V_33 ) ;
F_25 ( & V_32 -> V_48 . V_49 ) ;
V_32 -> V_48 . V_50 = false ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
F_26 ( & V_32 -> V_12 ) ;
F_21 ( & V_2 -> V_51 , V_37 ) ;
F_27 ( V_32 -> V_40 ) ;
F_27 ( V_32 ) ;
F_20 ( & V_2 -> V_21 -> V_44 , V_37 ) ;
V_2 -> V_21 -> V_45 = false ;
F_21 ( & V_2 -> V_21 -> V_44 , V_37 ) ;
}
struct V_31 *
F_28 ( struct V_1 * V_2 , int V_52 , V_26 * V_53 )
{
struct V_31 * V_32 ;
unsigned long V_37 ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
F_29 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_32 -> V_53 , V_53 , V_54 ) && V_32 -> V_52 == V_52 ) {
F_21 ( & V_2 -> V_51 ,
V_37 ) ;
return V_32 ;
}
}
F_21 ( & V_2 -> V_51 , V_37 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 , V_26 * V_53 )
{
struct V_31 * V_32 , * V_55 ;
unsigned long V_37 ;
if ( ! V_53 )
return;
F_20 ( & V_2 -> V_51 , V_37 ) ;
F_31 (tbl, tmp, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_32 -> V_53 , V_53 , V_54 ) ) {
F_21 ( & V_2 -> V_51 ,
V_37 ) ;
F_23 ( V_2 , V_32 ) ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
}
}
F_21 ( & V_2 -> V_51 , V_37 ) ;
return;
}
static int
F_32 ( struct V_56 * V_57 )
{
struct V_31 * V_58 = V_57 -> V_59 ;
struct V_1 * V_2 = V_57 -> V_2 ;
unsigned long V_37 ;
int V_35 ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
for ( V_35 = V_58 -> V_38 - 1 ; V_35 >= 0 ; -- V_35 ) {
if ( V_58 -> V_40 [ V_35 ] ) {
F_21 ( & V_2 -> V_51 ,
V_37 ) ;
return V_35 ;
}
}
F_21 ( & V_2 -> V_51 , V_37 ) ;
return - 1 ;
}
static void
F_33 ( unsigned long V_60 )
{
struct V_56 * V_57 =
(struct V_56 * ) V_60 ;
int V_33 , V_61 ;
V_57 -> V_50 = false ;
V_61 = F_32 ( V_57 ) ;
if ( V_61 < 0 )
return;
F_14 ( V_57 -> V_2 -> V_21 , V_62 , L_2 , V_61 ) ;
V_33 = ( V_57 -> V_59 -> V_33 + V_61 + 1 ) & ( V_43 - 1 ) ;
F_18 ( V_57 -> V_2 , V_57 -> V_59 ,
V_33 ) ;
}
static void
F_34 ( struct V_1 * V_2 , V_26 * V_53 ,
int V_52 , int V_38 , int V_61 )
{
int V_35 ;
struct V_31 * V_32 , * V_63 ;
T_1 V_64 = 0 ;
unsigned long V_37 ;
struct V_65 * V_66 ;
V_32 = F_28 ( V_2 , V_52 , V_53 ) ;
if ( V_32 ) {
F_18 ( V_2 , V_32 , V_61 ) ;
return;
}
V_63 = F_35 ( sizeof( struct V_31 ) , V_67 ) ;
if ( ! V_63 )
return;
F_36 ( & V_63 -> V_12 ) ;
V_63 -> V_52 = V_52 ;
memcpy ( V_63 -> V_53 , V_53 , V_54 ) ;
V_63 -> V_33 = V_61 ;
V_63 -> V_68 = V_61 ;
V_63 -> V_37 = 0 ;
F_20 ( & V_2 -> V_69 , V_37 ) ;
if ( F_37 ( V_2 ) ) {
if ( V_2 -> V_28 == V_29 ) {
V_66 = F_38 ( V_2 , V_53 ) ;
if ( V_66 )
V_64 = V_66 -> V_70 [ V_52 ] ;
}
} else {
V_66 = F_38 ( V_2 , V_53 ) ;
if ( V_66 )
V_64 = V_66 -> V_70 [ V_52 ] ;
else
V_64 = V_2 -> V_70 [ V_52 ] ;
}
F_21 ( & V_2 -> V_69 , V_37 ) ;
F_14 ( V_2 -> V_21 , V_62 ,
L_3 ,
V_64 , V_63 -> V_33 ) ;
if ( V_64 != V_71 &&
V_64 >= V_63 -> V_33 ) {
V_63 -> V_33 = V_64 + 1 ;
V_63 -> V_37 |= V_72 ;
}
V_63 -> V_38 = V_38 ;
V_63 -> V_40 = F_35 ( sizeof( void * ) * V_38 ,
V_67 ) ;
if ( ! V_63 -> V_40 ) {
F_27 ( ( V_26 * ) V_63 ) ;
F_14 ( V_2 -> V_21 , ERROR ,
L_4 , V_73 ) ;
return;
}
V_63 -> V_48 . V_59 = V_63 ;
V_63 -> V_48 . V_2 = V_2 ;
V_63 -> V_48 . V_50 = false ;
F_39 ( & V_63 -> V_48 . V_49 , F_33 ,
( unsigned long ) & V_63 -> V_48 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; ++ V_35 )
V_63 -> V_40 [ V_35 ] = NULL ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
F_40 ( & V_63 -> V_12 , & V_2 -> V_58 ) ;
F_21 ( & V_2 -> V_51 , V_37 ) ;
}
static void
F_41 ( struct V_31 * V_32 )
{
T_2 V_74 ;
if ( V_32 -> V_38 >= V_75 )
V_74 = V_76 ;
else
V_74 = V_77 ;
F_42 ( & V_32 -> V_48 . V_49 ,
V_78 + F_43 ( V_74 * V_32 -> V_38 ) ) ;
V_32 -> V_48 . V_50 = true ;
}
int F_44 ( struct V_79 * V_80 , void * V_81 )
{
struct V_82 * V_83 = & V_80 -> V_84 . V_83 ;
V_80 -> V_85 = F_45 ( V_86 ) ;
V_80 -> V_87 = F_45 ( sizeof( * V_83 ) + V_88 ) ;
memcpy ( V_83 , V_81 , sizeof( * V_83 ) ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
struct V_82
* V_89 )
{
struct V_90 * V_91 = & V_80 -> V_84 . V_91 ;
struct V_65 * V_92 ;
T_2 V_93 = V_2 -> V_94 . V_93 ;
V_26 V_52 ;
int V_38 ;
unsigned long V_37 ;
T_3 V_95 ;
if ( ( F_47 ( V_2 ) == V_96 ) &&
F_9 ( V_2 -> V_21 -> V_22 ) &&
V_2 -> V_21 -> V_97 &&
memcmp ( V_2 -> V_98 , V_89 -> V_99 , V_54 ) ) {
F_20 ( & V_2 -> V_69 , V_37 ) ;
V_92 = F_38 ( V_2 ,
V_89 -> V_99 ) ;
if ( ! V_92 ) {
F_21 ( & V_2 -> V_69 , V_37 ) ;
F_14 ( V_2 -> V_21 , ERROR ,
L_5 ,
V_89 -> V_99 ) ;
return - 1 ;
}
if ( V_92 -> V_100 )
V_93 = V_101 ;
F_21 ( & V_2 -> V_69 , V_37 ) ;
}
V_80 -> V_85 = F_45 ( V_102 ) ;
V_80 -> V_87 = F_45 ( sizeof( * V_91 ) + V_88 ) ;
memcpy ( V_91 -> V_99 , V_89 -> V_99 ,
V_54 ) ;
V_91 -> V_103 = V_89 -> V_103 ;
V_91 -> V_104 = V_89 -> V_104 ;
V_91 -> V_105 = V_89 -> V_105 ;
V_95 = F_2 ( V_89 -> V_95 ) ;
V_52 = ( V_95 & V_106 )
>> V_107 ;
V_91 -> V_108 = F_45 ( V_109 ) ;
V_95 &= ~ V_110 ;
if ( ! V_2 -> V_94 . V_111 ||
( V_2 -> V_112 [ V_52 ] . V_113 == V_114 ) )
V_95 &= ~ V_115 ;
V_95 |= V_93 << V_116 ;
V_91 -> V_95 = F_45 ( V_95 ) ;
V_38 = ( F_2 ( V_91 -> V_95 )
& V_110 )
>> V_116 ;
V_89 -> V_95 = F_45 ( V_95 ) ;
F_34 ( V_2 , V_89 -> V_99 ,
V_52 , V_38 ,
F_2 ( V_89 -> V_105 ) ) ;
return 0 ;
}
int F_48 ( struct V_79 * V_80 , void * V_81 )
{
struct V_117 * V_118 = & V_80 -> V_84 . V_118 ;
V_80 -> V_85 = F_45 ( V_119 ) ;
V_80 -> V_87 = F_45 ( sizeof( * V_118 ) + V_88 ) ;
memcpy ( V_118 , V_81 , sizeof( * V_118 ) ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 ,
T_1 V_61 , T_1 V_52 ,
V_26 * V_53 , V_26 V_120 , void * V_30 )
{
struct V_31 * V_32 ;
int V_121 , V_33 , V_122 , V_38 ;
T_1 V_123 ;
bool V_124 = false ;
int V_8 = 0 ;
V_32 = F_28 ( V_2 , V_52 , V_53 ) ;
if ( ! V_32 ) {
if ( V_120 != V_125 )
F_15 ( V_2 , V_30 ) ;
return V_8 ;
}
if ( ( V_120 == V_10 ) && ! V_32 -> V_113 ) {
F_15 ( V_2 , V_30 ) ;
return V_8 ;
}
V_33 = V_32 -> V_33 ;
V_121 = V_33 ;
V_38 = V_32 -> V_38 ;
V_122 = ( ( V_33 + V_38 ) - 1 ) & ( V_43 - 1 ) ;
if ( V_32 -> V_37 & V_72 ) {
V_124 = true ;
V_32 -> V_37 &= ~ V_72 ;
}
if ( V_32 -> V_37 & V_126 ) {
F_14 ( V_2 -> V_21 , V_62 ,
L_6 ) ;
V_32 -> V_37 &= ~ V_126 ;
} else if ( V_124 && V_61 < V_33 &&
V_61 >= V_32 -> V_68 ) {
F_14 ( V_2 -> V_21 , V_62 ,
L_7 ,
V_33 , V_61 , V_32 -> V_68 ) ;
V_32 -> V_33 = V_33 = V_61 ;
V_122 = ( ( V_33 + V_38 ) - 1 ) & ( V_43 - 1 ) ;
} else {
if ( ( V_33 + V_127 ) > ( V_43 - 1 ) ) {
if ( V_61 >= ( ( V_33 + V_127 ) &
( V_43 - 1 ) ) &&
V_61 < V_33 ) {
V_8 = - 1 ;
goto V_128;
}
} else if ( ( V_61 < V_33 ) ||
( V_61 >= ( V_33 + V_127 ) ) ) {
V_8 = - 1 ;
goto V_128;
}
}
if ( V_120 == V_125 )
V_61 = ( ( V_61 + V_38 ) - 1 ) & ( V_43 - 1 ) ;
if ( ( ( V_122 < V_33 ) &&
( V_61 < V_33 ) && ( V_61 > V_122 ) ) ||
( ( V_122 > V_33 ) && ( ( V_61 > V_122 ) ||
( V_61 < V_33 ) ) ) ) {
V_122 = V_61 ;
if ( ( ( V_122 - V_38 ) + 1 ) >= 0 )
V_33 = ( V_122 - V_38 ) + 1 ;
else
V_33 = ( V_43 - ( V_38 - V_122 ) ) + 1 ;
F_18 ( V_2 , V_32 , V_33 ) ;
}
if ( V_120 != V_125 ) {
if ( V_61 >= V_33 )
V_123 = V_61 - V_33 ;
else
V_123 = ( V_61 + V_43 ) - V_33 ;
if ( V_32 -> V_40 [ V_123 ] ) {
V_8 = - 1 ;
goto V_128;
}
V_32 -> V_40 [ V_123 ] = V_30 ;
}
F_22 ( V_2 , V_32 ) ;
V_128:
if ( ! V_32 -> V_48 . V_50 ||
V_121 != V_32 -> V_33 )
F_41 ( V_32 ) ;
return V_8 ;
}
void
F_50 ( struct V_1 * V_2 , int V_52 , V_26 * V_129 ,
V_26 type , int V_130 )
{
struct V_31 * V_32 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_26 V_135 ;
unsigned long V_37 ;
int V_136 ;
if ( type == V_137 )
V_135 = ( V_130 ) ? true : false ;
else
V_135 = ( V_130 ) ? false : true ;
F_14 ( V_2 -> V_21 , V_138 , L_8 ,
V_129 , V_52 , V_130 ) ;
if ( V_135 ) {
V_32 = F_28 ( V_2 , V_52 ,
V_129 ) ;
if ( ! V_32 ) {
F_14 ( V_2 -> V_21 , V_138 ,
L_9 ) ;
return;
}
F_23 ( V_2 , V_32 ) ;
} else {
V_132 = F_51 ( V_2 , V_52 , V_129 ) ;
if ( ! V_132 ) {
F_14 ( V_2 -> V_21 , V_138 ,
L_10 ) ;
return;
}
V_136 = F_52 ( V_2 , V_52 ) ;
V_134 = F_53 ( V_2 , V_136 , V_129 ) ;
if ( V_134 ) {
V_134 -> V_139 = false ;
V_134 -> V_140 = V_141 ;
}
F_20 ( & V_2 -> V_142 , V_37 ) ;
F_54 ( V_2 , V_132 ) ;
F_21 ( & V_2 -> V_142 , V_37 ) ;
}
}
int F_55 ( struct V_1 * V_2 ,
struct V_79 * V_143 )
{
struct V_90 * V_91 = & V_143 -> V_84 . V_91 ;
int V_52 , V_38 ;
struct V_31 * V_32 ;
T_3 V_95 ;
V_95 = F_2 ( V_91 -> V_95 ) ;
V_52 = ( V_95 & V_106 )
>> V_107 ;
if ( F_2 ( V_91 -> V_108 ) != V_144 ) {
F_14 ( V_2 -> V_21 , ERROR , L_11 ,
V_91 -> V_99 , V_52 ) ;
V_32 = F_28 ( V_2 , V_52 ,
V_91 -> V_99 ) ;
if ( V_32 )
F_23 ( V_2 , V_32 ) ;
return 0 ;
}
V_38 = ( V_95 & V_110 )
>> V_116 ;
V_32 = F_28 ( V_2 , V_52 ,
V_91 -> V_99 ) ;
if ( V_32 ) {
if ( ( V_95 & V_115 ) &&
V_2 -> V_94 . V_111 &&
( V_2 -> V_112 [ V_52 ] . V_113 != V_114 ) )
V_32 -> V_113 = true ;
else
V_32 -> V_113 = false ;
}
F_14 ( V_2 -> V_21 , V_145 ,
L_12 ,
V_91 -> V_99 , V_52 , V_91 -> V_105 , V_38 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_117 V_148 ;
memset ( & V_148 , 0 , sizeof( struct V_117 ) ) ;
memcpy ( V_148 . V_99 , V_147 -> V_99 , V_54 ) ;
V_148 . V_149 |=
F_45 ( ( T_1 ) V_147 -> V_52 << V_150 ) ;
V_148 . V_149 |= F_45 (
( T_1 ) V_147 -> V_151 << V_152 ) ;
V_148 . V_153 = F_45 ( V_154 ) ;
F_57 ( V_2 , V_119 , 0 , 0 , & V_148 , false ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_31 * V_155 , * V_156 ;
unsigned long V_37 ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
F_31 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_21 ( & V_2 -> V_51 , V_37 ) ;
F_23 ( V_2 , V_155 ) ;
F_20 ( & V_2 -> V_51 , V_37 ) ;
}
F_36 ( & V_2 -> V_58 ) ;
F_21 ( & V_2 -> V_51 , V_37 ) ;
F_59 ( V_2 ) ;
}
void F_60 ( struct V_157 * V_21 , V_26 V_37 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
unsigned long V_158 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_21 -> V_159 ; V_35 ++ ) {
V_2 = V_21 -> V_2 [ V_35 ] ;
if ( ! V_2 )
continue;
F_20 ( & V_2 -> V_51 , V_158 ) ;
if ( F_61 ( & V_2 -> V_58 ) ) {
F_21 ( & V_2 -> V_51 ,
V_158 ) ;
continue;
}
F_29 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_32 -> V_37 = V_37 ;
F_21 ( & V_2 -> V_51 , V_158 ) ;
}
return;
}
static void F_62 ( struct V_157 * V_21 ,
bool V_160 )
{
V_26 V_35 ;
T_2 V_93 ;
struct V_1 * V_2 ;
F_63 ( V_21 -> V_161 , L_13 , V_160 ) ;
for ( V_35 = 0 ; V_35 < V_21 -> V_159 ; V_35 ++ ) {
if ( ! V_21 -> V_2 [ V_35 ] )
continue;
V_2 = V_21 -> V_2 [ V_35 ] ;
V_93 = V_2 -> V_94 . V_93 ;
if ( V_160 ) {
if ( V_2 -> V_162 == V_163 )
V_2 -> V_94 . V_93 =
V_164 ;
if ( V_2 -> V_162 == V_165 )
V_2 -> V_94 . V_93 =
V_164 ;
if ( V_2 -> V_162 == V_166 )
V_2 -> V_94 . V_93 =
V_167 ;
} else {
if ( V_2 -> V_162 == V_163 )
V_2 -> V_94 . V_93 =
V_168 ;
if ( V_2 -> V_162 == V_165 )
V_2 -> V_94 . V_93 =
V_168 ;
if ( V_2 -> V_162 == V_166 )
V_2 -> V_94 . V_93 =
V_169 ;
}
if ( V_21 -> V_170 && V_21 -> V_171 )
V_2 -> V_94 . V_93 =
V_21 -> V_171 ;
if ( V_93 != V_2 -> V_94 . V_93 ) {
if ( ! V_2 -> V_172 )
continue;
for ( V_35 = 0 ; V_35 < V_173 ; V_35 ++ )
F_64 ( V_2 , V_35 ) ;
}
}
}
void F_65 ( struct V_157 * V_21 )
{
V_26 V_35 ;
struct V_1 * V_2 ;
V_26 V_174 = 0 ;
for ( V_35 = 0 ; V_35 < V_21 -> V_159 ; V_35 ++ ) {
if ( V_21 -> V_2 [ V_35 ] ) {
V_2 = V_21 -> V_2 [ V_35 ] ;
if ( F_47 ( V_2 ) == V_96 ) {
if ( V_2 -> V_172 )
V_174 ++ ;
}
if ( F_47 ( V_2 ) == V_29 ) {
if ( V_2 -> V_175 )
V_174 ++ ;
}
}
if ( V_174 >= V_176 )
break;
}
if ( V_174 >= V_176 )
F_62 ( V_21 , true ) ;
else
F_62 ( V_21 , false ) ;
}
