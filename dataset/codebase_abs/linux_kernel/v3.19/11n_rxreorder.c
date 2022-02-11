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
V_2 -> V_17 -> V_18 , 0 , false ) ;
while ( ! F_7 ( & V_12 ) ) {
V_13 = F_8 ( & V_12 ) ;
V_8 = F_9 ( V_2 , V_13 ) ;
if ( V_8 == - 1 )
F_10 ( V_2 -> V_19 -> V_20 ,
L_1 ) ;
}
return 0 ;
}
return - 1 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_21 )
{
int V_8 = F_1 ( V_2 , V_21 ) ;
if ( ! V_8 )
return 0 ;
if ( V_2 -> V_22 == V_23 )
return F_12 ( V_2 , V_21 ) ;
return F_13 ( V_2 , V_21 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_26 )
{
int V_27 , V_28 ;
void * V_29 ;
unsigned long V_30 ;
V_27 = ( V_26 > V_25 -> V_26 ) ?
F_15 ( ( V_26 - V_25 -> V_26 ) , V_25 -> V_31 ) :
V_25 -> V_31 ;
for ( V_28 = 0 ; V_28 < V_27 ; ++ V_28 ) {
F_16 ( & V_2 -> V_32 , V_30 ) ;
V_29 = NULL ;
if ( V_25 -> V_33 [ V_28 ] ) {
V_29 = V_25 -> V_33 [ V_28 ] ;
V_25 -> V_33 [ V_28 ] = NULL ;
}
F_17 ( & V_2 -> V_32 , V_30 ) ;
if ( V_29 )
F_11 ( V_2 , V_29 ) ;
}
F_16 ( & V_2 -> V_32 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_25 -> V_31 - V_27 ; ++ V_28 ) {
V_25 -> V_33 [ V_28 ] = V_25 -> V_33 [ V_27 + V_28 ] ;
V_25 -> V_33 [ V_27 + V_28 ] = NULL ;
}
V_25 -> V_26 = V_26 ;
F_17 ( & V_2 -> V_32 , V_30 ) ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_28 , V_34 , V_35 ;
void * V_29 ;
unsigned long V_30 ;
for ( V_28 = 0 ; V_28 < V_25 -> V_31 ; ++ V_28 ) {
F_16 ( & V_2 -> V_32 , V_30 ) ;
if ( ! V_25 -> V_33 [ V_28 ] ) {
F_17 ( & V_2 -> V_32 , V_30 ) ;
break;
}
V_29 = V_25 -> V_33 [ V_28 ] ;
V_25 -> V_33 [ V_28 ] = NULL ;
F_17 ( & V_2 -> V_32 , V_30 ) ;
F_11 ( V_2 , V_29 ) ;
}
F_16 ( & V_2 -> V_32 , V_30 ) ;
if ( V_28 > 0 ) {
V_35 = V_25 -> V_31 - V_28 ;
for ( V_34 = 0 ; V_34 < V_35 ; ++ V_34 ) {
V_25 -> V_33 [ V_34 ] = V_25 -> V_33 [ V_28 + V_34 ] ;
V_25 -> V_33 [ V_28 + V_34 ] = NULL ;
}
}
V_25 -> V_26 = ( V_25 -> V_26 + V_28 ) & ( V_36 - 1 ) ;
F_17 ( & V_2 -> V_32 , V_30 ) ;
}
static void
F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
unsigned long V_30 ;
int V_26 ;
if ( ! V_25 )
return;
F_16 ( & V_2 -> V_19 -> V_37 , V_30 ) ;
V_2 -> V_19 -> V_38 = true ;
if ( V_2 -> V_19 -> V_39 ) {
F_17 ( & V_2 -> V_19 -> V_37 , V_30 ) ;
F_20 ( V_2 -> V_19 -> V_40 ) ;
} else {
F_17 ( & V_2 -> V_19 -> V_37 , V_30 ) ;
}
V_26 = ( V_25 -> V_26 + V_25 -> V_31 ) & ( V_36 - 1 ) ;
F_14 ( V_2 , V_25 , V_26 ) ;
F_21 ( & V_25 -> V_41 . V_42 ) ;
V_25 -> V_41 . V_43 = false ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_22 ( & V_25 -> V_12 ) ;
F_17 ( & V_2 -> V_44 , V_30 ) ;
F_23 ( V_25 -> V_33 ) ;
F_23 ( V_25 ) ;
F_16 ( & V_2 -> V_19 -> V_37 , V_30 ) ;
V_2 -> V_19 -> V_38 = false ;
F_17 ( & V_2 -> V_19 -> V_37 , V_30 ) ;
}
struct V_24 *
F_24 ( struct V_1 * V_2 , int V_45 , T_1 * V_46 )
{
struct V_24 * V_25 ;
unsigned long V_30 ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_25 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_25 -> V_46 , V_46 , V_47 ) && V_25 -> V_45 == V_45 ) {
F_17 ( & V_2 -> V_44 ,
V_30 ) ;
return V_25 ;
}
}
F_17 ( & V_2 -> V_44 , V_30 ) ;
return NULL ;
}
void F_26 ( struct V_1 * V_2 , T_1 * V_46 )
{
struct V_24 * V_25 , * V_48 ;
unsigned long V_30 ;
if ( ! V_46 )
return;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_27 (tbl, tmp, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_25 -> V_46 , V_46 , V_47 ) ) {
F_17 ( & V_2 -> V_44 ,
V_30 ) ;
F_19 ( V_2 , V_25 ) ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
}
}
F_17 ( & V_2 -> V_44 , V_30 ) ;
return;
}
static int
F_28 ( struct V_49 * V_50 )
{
struct V_24 * V_51 = V_50 -> V_52 ;
struct V_1 * V_2 = V_50 -> V_2 ;
unsigned long V_30 ;
int V_28 ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
for ( V_28 = V_51 -> V_31 - 1 ; V_28 >= 0 ; -- V_28 ) {
if ( V_51 -> V_33 [ V_28 ] ) {
F_17 ( & V_2 -> V_44 ,
V_30 ) ;
return V_28 ;
}
}
F_17 ( & V_2 -> V_44 , V_30 ) ;
return - 1 ;
}
static void
F_29 ( unsigned long V_53 )
{
struct V_49 * V_50 =
(struct V_49 * ) V_53 ;
int V_26 , V_54 ;
V_50 -> V_43 = false ;
V_54 = F_28 ( V_50 ) ;
if ( V_54 < 0 )
return;
F_30 ( V_50 -> V_2 -> V_19 -> V_20 , L_2 , V_54 ) ;
V_26 = ( V_50 -> V_52 -> V_26 + V_54 + 1 ) & ( V_36 - 1 ) ;
F_14 ( V_50 -> V_2 , V_50 -> V_52 ,
V_26 ) ;
}
static void
F_31 ( struct V_1 * V_2 , T_1 * V_46 ,
int V_45 , int V_31 , int V_54 )
{
int V_28 ;
struct V_24 * V_25 , * V_55 ;
T_2 V_56 = 0 ;
unsigned long V_30 ;
struct V_57 * V_58 ;
V_25 = F_24 ( V_2 , V_45 , V_46 ) ;
if ( V_25 ) {
F_14 ( V_2 , V_25 , V_54 ) ;
return;
}
V_55 = F_32 ( sizeof( struct V_24 ) , V_59 ) ;
if ( ! V_55 )
return;
F_33 ( & V_55 -> V_12 ) ;
V_55 -> V_45 = V_45 ;
memcpy ( V_55 -> V_46 , V_46 , V_47 ) ;
V_55 -> V_26 = V_54 ;
V_55 -> V_60 = V_54 ;
V_55 -> V_30 = 0 ;
F_16 ( & V_2 -> V_61 , V_30 ) ;
if ( F_34 ( V_2 ) ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_3 ,
V_56 , V_55 -> V_26 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_58 = F_35 ( V_2 , V_46 ) ;
if ( V_58 )
V_56 = V_58 -> V_62 [ V_45 ] ;
}
} else {
V_58 = F_35 ( V_2 , V_46 ) ;
if ( V_58 )
V_56 = V_58 -> V_62 [ V_45 ] ;
else
V_56 = V_2 -> V_62 [ V_45 ] ;
}
F_17 ( & V_2 -> V_61 , V_30 ) ;
if ( V_56 != V_63 &&
V_56 >= V_55 -> V_26 ) {
V_55 -> V_26 = V_56 + 1 ;
V_55 -> V_30 |= V_64 ;
}
V_55 -> V_31 = V_31 ;
V_55 -> V_33 = F_32 ( sizeof( void * ) * V_31 ,
V_59 ) ;
if ( ! V_55 -> V_33 ) {
F_23 ( ( T_1 * ) V_55 ) ;
F_10 ( V_2 -> V_19 -> V_20 ,
L_4 , V_65 ) ;
return;
}
V_55 -> V_41 . V_52 = V_55 ;
V_55 -> V_41 . V_2 = V_2 ;
V_55 -> V_41 . V_43 = false ;
F_36 ( & V_55 -> V_41 . V_42 ) ;
V_55 -> V_41 . V_42 . V_66 = F_29 ;
V_55 -> V_41 . V_42 . V_7 =
( unsigned long ) & V_55 -> V_41 ;
for ( V_28 = 0 ; V_28 < V_31 ; ++ V_28 )
V_55 -> V_33 [ V_28 ] = NULL ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_37 ( & V_55 -> V_12 , & V_2 -> V_51 ) ;
F_17 ( & V_2 -> V_44 , V_30 ) ;
}
static void
F_38 ( struct V_24 * V_25 )
{
T_3 V_67 ;
if ( V_25 -> V_31 >= V_68 )
V_67 = V_69 ;
else
V_67 = V_70 ;
F_39 ( & V_25 -> V_41 . V_42 ,
V_71 + F_40 ( V_67 * V_25 -> V_31 ) ) ;
V_25 -> V_41 . V_43 = true ;
}
int F_41 ( struct V_72 * V_73 , void * V_74 )
{
struct V_75 * V_76 = & V_73 -> V_77 . V_76 ;
V_73 -> V_78 = F_42 ( V_79 ) ;
V_73 -> V_80 = F_42 ( sizeof( * V_76 ) + V_81 ) ;
memcpy ( V_76 , V_74 , sizeof( * V_76 ) ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
struct V_75
* V_82 )
{
struct V_83 * V_84 = & V_73 -> V_77 . V_84 ;
struct V_57 * V_85 ;
T_3 V_86 = V_2 -> V_87 . V_86 ;
T_1 V_45 ;
int V_31 ;
unsigned long V_30 ;
T_4 V_88 ;
if ( ( F_44 ( V_2 ) == V_89 ) &&
F_45 ( V_2 -> V_19 -> V_90 ) &&
V_2 -> V_19 -> V_91 &&
memcmp ( V_2 -> V_92 , V_82 -> V_93 , V_47 ) ) {
F_16 ( & V_2 -> V_61 , V_30 ) ;
V_85 = F_35 ( V_2 ,
V_82 -> V_93 ) ;
if ( ! V_85 ) {
F_46 ( V_2 -> V_19 -> V_20 ,
L_5 ,
V_82 -> V_93 ) ;
F_17 ( & V_2 -> V_61 , V_30 ) ;
return - 1 ;
}
if ( V_85 -> V_94 )
V_86 = V_95 ;
F_17 ( & V_2 -> V_61 , V_30 ) ;
}
V_73 -> V_78 = F_42 ( V_96 ) ;
V_73 -> V_80 = F_42 ( sizeof( * V_84 ) + V_81 ) ;
memcpy ( V_84 -> V_93 , V_82 -> V_93 ,
V_47 ) ;
V_84 -> V_97 = V_82 -> V_97 ;
V_84 -> V_98 = V_82 -> V_98 ;
V_84 -> V_99 = V_82 -> V_99 ;
V_88 = F_2 ( V_82 -> V_88 ) ;
V_45 = ( V_88 & V_100 )
>> V_101 ;
V_84 -> V_102 = F_42 ( V_103 ) ;
V_88 &= ~ V_104 ;
if ( ! V_2 -> V_87 . V_105 ||
( V_2 -> V_106 [ V_45 ] . V_107 == V_108 ) )
V_88 &= ~ V_109 ;
V_88 |= V_86 << V_110 ;
V_84 -> V_88 = F_42 ( V_88 ) ;
V_31 = ( F_2 ( V_84 -> V_88 )
& V_104 )
>> V_110 ;
V_82 -> V_88 = F_42 ( V_88 ) ;
F_31 ( V_2 , V_82 -> V_93 ,
V_45 , V_31 ,
F_2 ( V_82 -> V_99 ) ) ;
return 0 ;
}
int F_47 ( struct V_72 * V_73 , void * V_74 )
{
struct V_111 * V_112 = & V_73 -> V_77 . V_112 ;
V_73 -> V_78 = F_42 ( V_113 ) ;
V_73 -> V_80 = F_42 ( sizeof( * V_112 ) + V_81 ) ;
memcpy ( V_112 , V_74 , sizeof( * V_112 ) ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
T_2 V_54 , T_2 V_45 ,
T_1 * V_46 , T_1 V_114 , void * V_21 )
{
struct V_24 * V_25 ;
int V_115 , V_26 , V_116 , V_31 ;
T_2 V_117 ;
bool V_118 = false ;
int V_8 = 0 ;
V_25 = F_24 ( V_2 , V_45 , V_46 ) ;
if ( ! V_25 ) {
if ( V_114 != V_119 )
F_11 ( V_2 , V_21 ) ;
return V_8 ;
}
if ( ( V_114 == V_10 ) && ! V_25 -> V_107 ) {
F_11 ( V_2 , V_21 ) ;
return V_8 ;
}
V_26 = V_25 -> V_26 ;
V_115 = V_26 ;
V_31 = V_25 -> V_31 ;
V_116 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( V_25 -> V_30 & V_64 ) {
V_118 = true ;
V_25 -> V_30 &= ~ V_64 ;
}
if ( V_25 -> V_30 & V_120 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_6 ) ;
V_25 -> V_30 &= ~ V_120 ;
} else if ( V_118 && V_54 < V_26 &&
V_54 >= V_25 -> V_60 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_7 ,
V_26 , V_54 , V_25 -> V_60 ) ;
V_25 -> V_26 = V_26 = V_54 ;
V_116 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
} else {
if ( ( V_26 + V_121 ) > ( V_36 - 1 ) ) {
if ( V_54 >= ( ( V_26 + V_121 ) &
( V_36 - 1 ) ) &&
V_54 < V_26 ) {
V_8 = - 1 ;
goto V_122;
}
} else if ( ( V_54 < V_26 ) ||
( V_54 >= ( V_26 + V_121 ) ) ) {
V_8 = - 1 ;
goto V_122;
}
}
if ( V_114 == V_119 )
V_54 = ( ( V_54 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( ( ( V_116 < V_26 ) &&
( V_54 < V_26 ) && ( V_54 > V_116 ) ) ||
( ( V_116 > V_26 ) && ( ( V_54 > V_116 ) ||
( V_54 < V_26 ) ) ) ) {
V_116 = V_54 ;
if ( ( ( V_54 - V_31 ) + 1 ) >= 0 )
V_26 = ( V_116 - V_31 ) + 1 ;
else
V_26 = ( V_36 - ( V_31 - V_54 ) ) + 1 ;
F_14 ( V_2 , V_25 , V_26 ) ;
}
if ( V_114 != V_119 ) {
if ( V_54 >= V_26 )
V_117 = V_54 - V_26 ;
else
V_117 = ( V_54 + V_36 ) - V_26 ;
if ( V_25 -> V_33 [ V_117 ] ) {
V_8 = - 1 ;
goto V_122;
}
V_25 -> V_33 [ V_117 ] = V_21 ;
}
F_18 ( V_2 , V_25 ) ;
V_122:
if ( ! V_25 -> V_41 . V_43 ||
V_115 != V_25 -> V_26 )
F_38 ( V_25 ) ;
return V_8 ;
}
void
F_49 ( struct V_1 * V_2 , int V_45 , T_1 * V_123 ,
T_1 type , int V_124 )
{
struct V_24 * V_25 ;
struct V_125 * V_126 ;
T_1 V_127 ;
unsigned long V_30 ;
if ( type == V_128 )
V_127 = ( V_124 ) ? true : false ;
else
V_127 = ( V_124 ) ? false : true ;
F_30 ( V_2 -> V_19 -> V_20 , L_8 ,
V_123 , V_45 , V_124 ) ;
if ( V_127 ) {
V_25 = F_24 ( V_2 , V_45 ,
V_123 ) ;
if ( ! V_25 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_9 ) ;
return;
}
F_19 ( V_2 , V_25 ) ;
} else {
V_126 = F_50 ( V_2 , V_45 , V_123 ) ;
if ( ! V_126 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_10 ) ;
return;
}
F_16 ( & V_2 -> V_129 , V_30 ) ;
F_51 ( V_2 , V_126 ) ;
F_17 ( & V_2 -> V_129 , V_30 ) ;
}
}
int F_52 ( struct V_1 * V_2 ,
struct V_72 * V_130 )
{
struct V_83 * V_84 = & V_130 -> V_77 . V_84 ;
int V_45 , V_31 ;
struct V_24 * V_25 ;
T_4 V_88 ;
V_88 = F_2 ( V_84 -> V_88 ) ;
V_45 = ( V_88 & V_100 )
>> V_101 ;
if ( F_2 ( V_84 -> V_102 ) != V_131 ) {
F_10 ( V_2 -> V_19 -> V_20 , L_11 ,
V_84 -> V_93 , V_45 ) ;
V_25 = F_24 ( V_2 , V_45 ,
V_84 -> V_93 ) ;
if ( V_25 )
F_19 ( V_2 , V_25 ) ;
return 0 ;
}
V_31 = ( V_88 & V_104 )
>> V_110 ;
V_25 = F_24 ( V_2 , V_45 ,
V_84 -> V_93 ) ;
if ( V_25 ) {
if ( ( V_88 & V_109 ) &&
V_2 -> V_87 . V_105 &&
( V_2 -> V_106 [ V_45 ] . V_107 != V_108 ) )
V_25 -> V_107 = true ;
else
V_25 -> V_107 = false ;
}
F_30 ( V_2 -> V_19 -> V_20 ,
L_12 ,
V_84 -> V_93 , V_45 , V_84 -> V_99 , V_31 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_111 V_134 ;
memset ( & V_134 , 0 , sizeof( struct V_111 ) ) ;
memcpy ( V_134 . V_93 , V_133 -> V_93 , V_47 ) ;
V_134 . V_135 |=
F_42 ( ( T_2 ) V_133 -> V_45 << V_136 ) ;
V_134 . V_135 |= F_42 (
( T_2 ) V_133 -> V_137 << V_138 ) ;
V_134 . V_139 = F_42 ( V_140 ) ;
F_54 ( V_2 , V_113 , 0 , 0 , & V_134 , false ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_24 * V_141 , * V_142 ;
unsigned long V_30 ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_27 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_17 ( & V_2 -> V_44 , V_30 ) ;
F_19 ( V_2 , V_141 ) ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
}
F_33 ( & V_2 -> V_51 ) ;
F_17 ( & V_2 -> V_44 , V_30 ) ;
F_56 ( V_2 ) ;
}
void F_57 ( struct V_143 * V_19 , T_1 V_30 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
unsigned long V_144 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_19 -> V_145 ; V_28 ++ ) {
V_2 = V_19 -> V_2 [ V_28 ] ;
if ( ! V_2 )
continue;
F_16 ( & V_2 -> V_44 , V_144 ) ;
if ( F_58 ( & V_2 -> V_51 ) ) {
F_17 ( & V_2 -> V_44 ,
V_144 ) ;
continue;
}
F_25 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_25 -> V_30 = V_30 ;
F_17 ( & V_2 -> V_44 , V_144 ) ;
}
return;
}
