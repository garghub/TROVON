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
V_2 -> V_17 . V_18 , 0 , NULL , NULL ) ;
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
int V_8 ;
if ( ! V_30 ) {
F_14 ( V_2 -> V_21 , V_31 , L_2 ) ;
return 0 ;
}
V_8 = F_1 ( V_2 , V_30 ) ;
if ( ! V_8 )
return 0 ;
if ( V_2 -> V_28 == V_29 )
return F_16 ( V_2 , V_30 ) ;
return F_17 ( V_2 , V_30 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
int V_34 )
{
int V_35 , V_36 ;
void * V_37 ;
unsigned long V_38 ;
V_35 = ( V_34 > V_33 -> V_34 ) ?
F_19 ( ( V_34 - V_33 -> V_34 ) , V_33 -> V_39 ) :
V_33 -> V_39 ;
for ( V_36 = 0 ; V_36 < V_35 ; ++ V_36 ) {
F_20 ( & V_2 -> V_40 , V_38 ) ;
V_37 = NULL ;
if ( V_33 -> V_41 [ V_36 ] ) {
V_37 = V_33 -> V_41 [ V_36 ] ;
V_33 -> V_41 [ V_36 ] = NULL ;
}
F_21 ( & V_2 -> V_40 , V_38 ) ;
if ( V_37 )
F_15 ( V_2 , V_37 ) ;
}
F_20 ( & V_2 -> V_40 , V_38 ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_39 - V_35 ; ++ V_36 ) {
V_33 -> V_41 [ V_36 ] = V_33 -> V_41 [ V_35 + V_36 ] ;
V_33 -> V_41 [ V_35 + V_36 ] = NULL ;
}
V_33 -> V_34 = V_34 ;
F_21 ( & V_2 -> V_40 , V_38 ) ;
}
static void
F_22 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_36 , V_42 , V_43 ;
void * V_37 ;
unsigned long V_38 ;
for ( V_36 = 0 ; V_36 < V_33 -> V_39 ; ++ V_36 ) {
F_20 ( & V_2 -> V_40 , V_38 ) ;
if ( ! V_33 -> V_41 [ V_36 ] ) {
F_21 ( & V_2 -> V_40 , V_38 ) ;
break;
}
V_37 = V_33 -> V_41 [ V_36 ] ;
V_33 -> V_41 [ V_36 ] = NULL ;
F_21 ( & V_2 -> V_40 , V_38 ) ;
F_15 ( V_2 , V_37 ) ;
}
F_20 ( & V_2 -> V_40 , V_38 ) ;
if ( V_36 > 0 ) {
V_43 = V_33 -> V_39 - V_36 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
V_33 -> V_41 [ V_42 ] = V_33 -> V_41 [ V_36 + V_42 ] ;
V_33 -> V_41 [ V_36 + V_42 ] = NULL ;
}
}
V_33 -> V_34 = ( V_33 -> V_34 + V_36 ) & ( V_44 - 1 ) ;
F_21 ( & V_2 -> V_40 , V_38 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
unsigned long V_38 ;
int V_34 ;
if ( ! V_33 )
return;
F_20 ( & V_2 -> V_21 -> V_45 , V_38 ) ;
V_2 -> V_21 -> V_46 = true ;
if ( V_2 -> V_21 -> V_47 ) {
F_21 ( & V_2 -> V_21 -> V_45 , V_38 ) ;
F_24 ( V_2 -> V_21 -> V_48 ) ;
} else {
F_21 ( & V_2 -> V_21 -> V_45 , V_38 ) ;
}
V_34 = ( V_33 -> V_34 + V_33 -> V_39 ) & ( V_44 - 1 ) ;
F_18 ( V_2 , V_33 , V_34 ) ;
F_25 ( & V_33 -> V_49 . V_50 ) ;
V_33 -> V_49 . V_51 = false ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
F_26 ( & V_33 -> V_12 ) ;
F_21 ( & V_2 -> V_52 , V_38 ) ;
F_27 ( V_33 -> V_41 ) ;
F_27 ( V_33 ) ;
F_20 ( & V_2 -> V_21 -> V_45 , V_38 ) ;
V_2 -> V_21 -> V_46 = false ;
F_21 ( & V_2 -> V_21 -> V_45 , V_38 ) ;
}
struct V_32 *
F_28 ( struct V_1 * V_2 , int V_53 , V_26 * V_54 )
{
struct V_32 * V_33 ;
unsigned long V_38 ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
F_29 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_33 -> V_54 , V_54 , V_55 ) && V_33 -> V_53 == V_53 ) {
F_21 ( & V_2 -> V_52 ,
V_38 ) ;
return V_33 ;
}
}
F_21 ( & V_2 -> V_52 , V_38 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 , V_26 * V_54 )
{
struct V_32 * V_33 , * V_56 ;
unsigned long V_38 ;
if ( ! V_54 )
return;
F_20 ( & V_2 -> V_52 , V_38 ) ;
F_31 (tbl, tmp, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_33 -> V_54 , V_54 , V_55 ) ) {
F_21 ( & V_2 -> V_52 ,
V_38 ) ;
F_23 ( V_2 , V_33 ) ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
}
}
F_21 ( & V_2 -> V_52 , V_38 ) ;
return;
}
static int
F_32 ( struct V_57 * V_58 )
{
struct V_32 * V_59 = V_58 -> V_60 ;
struct V_1 * V_2 = V_58 -> V_2 ;
unsigned long V_38 ;
int V_36 ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
for ( V_36 = V_59 -> V_39 - 1 ; V_36 >= 0 ; -- V_36 ) {
if ( V_59 -> V_41 [ V_36 ] ) {
F_21 ( & V_2 -> V_52 ,
V_38 ) ;
return V_36 ;
}
}
F_21 ( & V_2 -> V_52 , V_38 ) ;
return - 1 ;
}
static void
F_33 ( unsigned long V_61 )
{
struct V_57 * V_58 =
(struct V_57 * ) V_61 ;
int V_34 , V_62 ;
V_58 -> V_51 = false ;
V_62 = F_32 ( V_58 ) ;
if ( V_62 < 0 )
return;
F_14 ( V_58 -> V_2 -> V_21 , V_31 , L_3 , V_62 ) ;
V_34 = ( V_58 -> V_60 -> V_34 + V_62 + 1 ) & ( V_44 - 1 ) ;
F_18 ( V_58 -> V_2 , V_58 -> V_60 ,
V_34 ) ;
}
static void
F_34 ( struct V_1 * V_2 , V_26 * V_54 ,
int V_53 , int V_39 , int V_62 )
{
int V_36 ;
struct V_32 * V_33 , * V_63 ;
T_1 V_64 = 0 ;
unsigned long V_38 ;
struct V_65 * V_66 ;
V_33 = F_28 ( V_2 , V_53 , V_54 ) ;
if ( V_33 ) {
F_18 ( V_2 , V_33 , V_62 ) ;
return;
}
V_63 = F_35 ( sizeof( struct V_32 ) , V_67 ) ;
if ( ! V_63 )
return;
F_36 ( & V_63 -> V_12 ) ;
V_63 -> V_53 = V_53 ;
memcpy ( V_63 -> V_54 , V_54 , V_55 ) ;
V_63 -> V_34 = V_62 ;
V_63 -> V_68 = V_62 ;
V_63 -> V_38 = 0 ;
F_20 ( & V_2 -> V_69 , V_38 ) ;
if ( F_37 ( V_2 ) ) {
if ( V_2 -> V_28 == V_29 ) {
V_66 = F_38 ( V_2 , V_54 ) ;
if ( V_66 )
V_64 = V_66 -> V_70 [ V_53 ] ;
}
} else {
V_66 = F_38 ( V_2 , V_54 ) ;
if ( V_66 )
V_64 = V_66 -> V_70 [ V_53 ] ;
else
V_64 = V_2 -> V_70 [ V_53 ] ;
}
F_21 ( & V_2 -> V_69 , V_38 ) ;
F_14 ( V_2 -> V_21 , V_31 ,
L_4 ,
V_64 , V_63 -> V_34 ) ;
if ( V_64 != V_71 &&
V_64 >= V_63 -> V_34 ) {
V_63 -> V_34 = V_64 + 1 ;
V_63 -> V_38 |= V_72 ;
}
V_63 -> V_39 = V_39 ;
V_63 -> V_41 = F_35 ( sizeof( void * ) * V_39 ,
V_67 ) ;
if ( ! V_63 -> V_41 ) {
F_27 ( ( V_26 * ) V_63 ) ;
F_14 ( V_2 -> V_21 , ERROR ,
L_5 , V_73 ) ;
return;
}
V_63 -> V_49 . V_60 = V_63 ;
V_63 -> V_49 . V_2 = V_2 ;
V_63 -> V_49 . V_51 = false ;
F_39 ( & V_63 -> V_49 . V_50 , F_33 ,
( unsigned long ) & V_63 -> V_49 ) ;
for ( V_36 = 0 ; V_36 < V_39 ; ++ V_36 )
V_63 -> V_41 [ V_36 ] = NULL ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
F_40 ( & V_63 -> V_12 , & V_2 -> V_59 ) ;
F_21 ( & V_2 -> V_52 , V_38 ) ;
}
static void
F_41 ( struct V_32 * V_33 )
{
T_2 V_74 ;
if ( V_33 -> V_39 >= V_75 )
V_74 = V_76 ;
else
V_74 = V_77 ;
F_42 ( & V_33 -> V_49 . V_50 ,
V_78 + F_43 ( V_74 * V_33 -> V_39 ) ) ;
V_33 -> V_49 . V_51 = true ;
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
V_26 V_53 ;
int V_39 ;
unsigned long V_38 ;
T_3 V_95 ;
if ( ( F_47 ( V_2 ) == V_96 ) &&
F_9 ( V_2 -> V_21 -> V_22 ) &&
V_2 -> V_21 -> V_97 &&
memcmp ( V_2 -> V_98 , V_89 -> V_99 , V_55 ) ) {
F_20 ( & V_2 -> V_69 , V_38 ) ;
V_92 = F_38 ( V_2 ,
V_89 -> V_99 ) ;
if ( ! V_92 ) {
F_21 ( & V_2 -> V_69 , V_38 ) ;
F_14 ( V_2 -> V_21 , ERROR ,
L_6 ,
V_89 -> V_99 ) ;
return - 1 ;
}
if ( V_92 -> V_100 )
V_93 = V_101 ;
F_21 ( & V_2 -> V_69 , V_38 ) ;
}
V_80 -> V_85 = F_45 ( V_102 ) ;
V_80 -> V_87 = F_45 ( sizeof( * V_91 ) + V_88 ) ;
memcpy ( V_91 -> V_99 , V_89 -> V_99 ,
V_55 ) ;
V_91 -> V_103 = V_89 -> V_103 ;
V_91 -> V_104 = V_89 -> V_104 ;
V_91 -> V_105 = V_89 -> V_105 ;
V_95 = F_2 ( V_89 -> V_95 ) ;
V_53 = ( V_95 & V_106 )
>> V_107 ;
V_91 -> V_108 = F_45 ( V_109 ) ;
V_95 &= ~ V_110 ;
if ( ! V_2 -> V_94 . V_111 ||
( V_2 -> V_112 [ V_53 ] . V_113 == V_114 ) )
V_95 &= ~ V_115 ;
V_95 |= V_93 << V_116 ;
V_91 -> V_95 = F_45 ( V_95 ) ;
V_39 = ( F_2 ( V_91 -> V_95 )
& V_110 )
>> V_116 ;
V_89 -> V_95 = F_45 ( V_95 ) ;
F_34 ( V_2 , V_89 -> V_99 ,
V_53 , V_39 ,
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
T_1 V_62 , T_1 V_53 ,
V_26 * V_54 , V_26 V_120 , void * V_30 )
{
struct V_32 * V_33 ;
int V_121 , V_34 , V_122 , V_39 ;
T_1 V_123 ;
bool V_124 = false ;
int V_8 = 0 ;
V_33 = F_28 ( V_2 , V_53 , V_54 ) ;
if ( ! V_33 ) {
if ( V_120 != V_125 )
F_15 ( V_2 , V_30 ) ;
return V_8 ;
}
if ( ( V_120 == V_10 ) && ! V_33 -> V_113 ) {
F_15 ( V_2 , V_30 ) ;
return V_8 ;
}
V_34 = V_33 -> V_34 ;
V_121 = V_34 ;
V_39 = V_33 -> V_39 ;
V_122 = ( ( V_34 + V_39 ) - 1 ) & ( V_44 - 1 ) ;
if ( V_33 -> V_38 & V_72 ) {
V_124 = true ;
V_33 -> V_38 &= ~ V_72 ;
}
if ( V_33 -> V_38 & V_126 ) {
F_14 ( V_2 -> V_21 , V_31 ,
L_7 ) ;
V_33 -> V_38 &= ~ V_126 ;
} else if ( V_124 && V_62 < V_34 &&
V_62 >= V_33 -> V_68 ) {
F_14 ( V_2 -> V_21 , V_31 ,
L_8 ,
V_34 , V_62 , V_33 -> V_68 ) ;
V_33 -> V_34 = V_34 = V_62 ;
V_122 = ( ( V_34 + V_39 ) - 1 ) & ( V_44 - 1 ) ;
} else {
if ( ( V_34 + V_127 ) > ( V_44 - 1 ) ) {
if ( V_62 >= ( ( V_34 + V_127 ) &
( V_44 - 1 ) ) &&
V_62 < V_34 ) {
V_8 = - 1 ;
goto V_128;
}
} else if ( ( V_62 < V_34 ) ||
( V_62 >= ( V_34 + V_127 ) ) ) {
V_8 = - 1 ;
goto V_128;
}
}
if ( V_120 == V_125 )
V_62 = ( ( V_62 + V_39 ) - 1 ) & ( V_44 - 1 ) ;
if ( ( ( V_122 < V_34 ) &&
( V_62 < V_34 ) && ( V_62 > V_122 ) ) ||
( ( V_122 > V_34 ) && ( ( V_62 > V_122 ) ||
( V_62 < V_34 ) ) ) ) {
V_122 = V_62 ;
if ( ( ( V_122 - V_39 ) + 1 ) >= 0 )
V_34 = ( V_122 - V_39 ) + 1 ;
else
V_34 = ( V_44 - ( V_39 - V_122 ) ) + 1 ;
F_18 ( V_2 , V_33 , V_34 ) ;
}
if ( V_120 != V_125 ) {
if ( V_62 >= V_34 )
V_123 = V_62 - V_34 ;
else
V_123 = ( V_62 + V_44 ) - V_34 ;
if ( V_33 -> V_41 [ V_123 ] ) {
V_8 = - 1 ;
goto V_128;
}
V_33 -> V_41 [ V_123 ] = V_30 ;
}
F_22 ( V_2 , V_33 ) ;
V_128:
if ( ! V_33 -> V_49 . V_51 ||
V_121 != V_33 -> V_34 )
F_41 ( V_33 ) ;
return V_8 ;
}
void
F_50 ( struct V_1 * V_2 , int V_53 , V_26 * V_129 ,
V_26 type , int V_130 )
{
struct V_32 * V_33 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
V_26 V_135 ;
unsigned long V_38 ;
int V_136 ;
if ( type == V_137 )
V_135 = ( V_130 ) ? true : false ;
else
V_135 = ( V_130 ) ? false : true ;
F_14 ( V_2 -> V_21 , V_138 , L_9 ,
V_129 , V_53 , V_130 ) ;
if ( V_135 ) {
V_33 = F_28 ( V_2 , V_53 ,
V_129 ) ;
if ( ! V_33 ) {
F_14 ( V_2 -> V_21 , V_138 ,
L_10 ) ;
return;
}
F_23 ( V_2 , V_33 ) ;
} else {
V_132 = F_51 ( V_2 , V_53 , V_129 ) ;
if ( ! V_132 ) {
F_14 ( V_2 -> V_21 , V_138 ,
L_11 ) ;
return;
}
V_136 = F_52 ( V_2 , V_53 ) ;
V_134 = F_53 ( V_2 , V_136 , V_129 ) ;
if ( V_134 ) {
V_134 -> V_139 = false ;
V_134 -> V_140 = V_141 ;
}
F_20 ( & V_2 -> V_142 , V_38 ) ;
F_54 ( V_2 , V_132 ) ;
F_21 ( & V_2 -> V_142 , V_38 ) ;
}
}
int F_55 ( struct V_1 * V_2 ,
struct V_79 * V_143 )
{
struct V_90 * V_91 = & V_143 -> V_84 . V_91 ;
int V_53 , V_39 ;
struct V_32 * V_33 ;
T_3 V_95 ;
V_95 = F_2 ( V_91 -> V_95 ) ;
V_53 = ( V_95 & V_106 )
>> V_107 ;
if ( F_2 ( V_91 -> V_108 ) != V_144 ) {
F_14 ( V_2 -> V_21 , ERROR , L_12 ,
V_91 -> V_99 , V_53 ) ;
V_33 = F_28 ( V_2 , V_53 ,
V_91 -> V_99 ) ;
if ( V_33 )
F_23 ( V_2 , V_33 ) ;
return 0 ;
}
V_39 = ( V_95 & V_110 )
>> V_116 ;
V_33 = F_28 ( V_2 , V_53 ,
V_91 -> V_99 ) ;
if ( V_33 ) {
if ( ( V_95 & V_115 ) &&
V_2 -> V_94 . V_111 &&
( V_2 -> V_112 [ V_53 ] . V_113 != V_114 ) )
V_33 -> V_113 = true ;
else
V_33 -> V_113 = false ;
}
F_14 ( V_2 -> V_21 , V_145 ,
L_13 ,
V_91 -> V_99 , V_53 , V_91 -> V_105 , V_39 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_117 V_148 ;
memset ( & V_148 , 0 , sizeof( struct V_117 ) ) ;
memcpy ( V_148 . V_99 , V_147 -> V_99 , V_55 ) ;
V_148 . V_149 |=
F_45 ( ( T_1 ) V_147 -> V_53 << V_150 ) ;
V_148 . V_149 |= F_45 (
( T_1 ) V_147 -> V_151 << V_152 ) ;
V_148 . V_153 = F_45 ( V_154 ) ;
F_57 ( V_2 , V_119 , 0 , 0 , & V_148 , false ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_32 * V_155 , * V_156 ;
unsigned long V_38 ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
F_31 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_21 ( & V_2 -> V_52 , V_38 ) ;
F_23 ( V_2 , V_155 ) ;
F_20 ( & V_2 -> V_52 , V_38 ) ;
}
F_36 ( & V_2 -> V_59 ) ;
F_21 ( & V_2 -> V_52 , V_38 ) ;
F_59 ( V_2 ) ;
}
void F_60 ( struct V_157 * V_21 , V_26 V_38 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
unsigned long V_158 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_159 ; V_36 ++ ) {
V_2 = V_21 -> V_2 [ V_36 ] ;
if ( ! V_2 )
continue;
F_20 ( & V_2 -> V_52 , V_158 ) ;
if ( F_61 ( & V_2 -> V_59 ) ) {
F_21 ( & V_2 -> V_52 ,
V_158 ) ;
continue;
}
F_29 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_33 -> V_38 = V_38 ;
F_21 ( & V_2 -> V_52 , V_158 ) ;
}
return;
}
static void F_62 ( struct V_157 * V_21 ,
bool V_160 )
{
V_26 V_36 ;
T_2 V_93 ;
struct V_1 * V_2 ;
F_63 ( V_21 -> V_161 , L_14 , V_160 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_159 ; V_36 ++ ) {
if ( ! V_21 -> V_2 [ V_36 ] )
continue;
V_2 = V_21 -> V_2 [ V_36 ] ;
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
for ( V_36 = 0 ; V_36 < V_173 ; V_36 ++ )
F_64 ( V_2 , V_36 ) ;
}
}
}
void F_65 ( struct V_157 * V_21 )
{
V_26 V_36 ;
struct V_1 * V_2 ;
V_26 V_174 = 0 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_159 ; V_36 ++ ) {
if ( V_21 -> V_2 [ V_36 ] ) {
V_2 = V_21 -> V_2 [ V_36 ] ;
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
void F_66 ( struct V_1 * V_2 ,
V_26 * V_177 , T_1 V_27 )
{
struct V_178 * V_179 = ( void * ) V_177 ;
T_1 V_180 , V_181 ;
struct V_32 * V_182 ;
V_26 V_36 , V_42 ;
T_1 V_62 , V_183 , V_184 ;
int V_185 = V_27 ;
int V_8 ;
V_26 * V_56 ;
F_67 ( V_2 -> V_21 , V_186 , L_15 ,
V_177 , V_27 ) ;
while ( V_185 >= sizeof( * V_179 ) ) {
V_180 = F_2 ( V_179 -> V_187 . type ) ;
V_181 = F_2 ( V_179 -> V_187 . V_27 ) ;
if ( V_180 != V_188 ) {
F_14 ( V_2 -> V_21 , ERROR ,
L_16 , V_180 ) ;
return;
}
V_183 = F_2 ( V_179 -> V_62 ) ;
V_184 = F_2 ( V_179 -> V_189 ) ;
F_14 ( V_2 -> V_21 , V_31 ,
L_17 ,
V_179 -> V_190 , V_179 -> V_53 , V_183 ,
V_184 ) ;
V_182 =
F_28 ( V_2 , V_179 -> V_53 ,
V_179 -> V_190 ) ;
if ( ! V_182 ) {
F_14 ( V_2 -> V_21 , ERROR ,
L_18 ) ;
return;
}
for ( V_36 = 0 ; V_36 < V_184 ; V_36 ++ ) {
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
if ( V_179 -> V_191 [ V_36 ] & ( 1 << V_42 ) ) {
V_62 = ( V_44 - 1 ) &
( V_183 + V_36 * 8 + V_42 ) ;
F_14 ( V_2 -> V_21 , ERROR ,
L_19 ,
V_62 ) ;
V_8 = F_49
( V_2 , V_62 , V_179 -> V_53 ,
V_179 -> V_190 , 0 , NULL ) ;
if ( V_8 )
F_14 ( V_2 -> V_21 ,
ERROR ,
L_20 ) ;
}
}
}
V_185 -= ( sizeof( * V_179 ) + V_181 ) ;
V_56 = ( V_26 * ) V_179 + V_181 + sizeof( * V_179 ) ;
V_179 = (struct V_178 * ) V_56 ;
}
}
