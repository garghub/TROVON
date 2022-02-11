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
F_30 ( V_2 -> V_19 -> V_20 , L_3 ,
V_56 , V_55 -> V_26 ) ;
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
F_36 ( & V_55 -> V_41 . V_42 , F_29 ,
( unsigned long ) & V_55 -> V_41 ) ;
for ( V_28 = 0 ; V_28 < V_31 ; ++ V_28 )
V_55 -> V_33 [ V_28 ] = NULL ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_37 ( & V_55 -> V_12 , & V_2 -> V_51 ) ;
F_17 ( & V_2 -> V_44 , V_30 ) ;
}
static void
F_38 ( struct V_24 * V_25 )
{
T_3 V_66 ;
if ( V_25 -> V_31 >= V_67 )
V_66 = V_68 ;
else
V_66 = V_69 ;
F_39 ( & V_25 -> V_41 . V_42 ,
V_70 + F_40 ( V_66 * V_25 -> V_31 ) ) ;
V_25 -> V_41 . V_43 = true ;
}
int F_41 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = & V_72 -> V_76 . V_75 ;
V_72 -> V_77 = F_42 ( V_78 ) ;
V_72 -> V_79 = F_42 ( sizeof( * V_75 ) + V_80 ) ;
memcpy ( V_75 , V_73 , sizeof( * V_75 ) ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_74
* V_81 )
{
struct V_82 * V_83 = & V_72 -> V_76 . V_83 ;
struct V_57 * V_84 ;
T_3 V_85 = V_2 -> V_86 . V_85 ;
T_1 V_45 ;
int V_31 ;
unsigned long V_30 ;
T_4 V_87 ;
if ( ( F_44 ( V_2 ) == V_88 ) &&
F_45 ( V_2 -> V_19 -> V_89 ) &&
V_2 -> V_19 -> V_90 &&
memcmp ( V_2 -> V_91 , V_81 -> V_92 , V_47 ) ) {
F_16 ( & V_2 -> V_61 , V_30 ) ;
V_84 = F_35 ( V_2 ,
V_81 -> V_92 ) ;
if ( ! V_84 ) {
F_17 ( & V_2 -> V_61 , V_30 ) ;
F_46 ( V_2 -> V_19 -> V_20 ,
L_5 ,
V_81 -> V_92 ) ;
return - 1 ;
}
if ( V_84 -> V_93 )
V_85 = V_94 ;
F_17 ( & V_2 -> V_61 , V_30 ) ;
}
V_72 -> V_77 = F_42 ( V_95 ) ;
V_72 -> V_79 = F_42 ( sizeof( * V_83 ) + V_80 ) ;
memcpy ( V_83 -> V_92 , V_81 -> V_92 ,
V_47 ) ;
V_83 -> V_96 = V_81 -> V_96 ;
V_83 -> V_97 = V_81 -> V_97 ;
V_83 -> V_98 = V_81 -> V_98 ;
V_87 = F_2 ( V_81 -> V_87 ) ;
V_45 = ( V_87 & V_99 )
>> V_100 ;
V_83 -> V_101 = F_42 ( V_102 ) ;
V_87 &= ~ V_103 ;
if ( ! V_2 -> V_86 . V_104 ||
( V_2 -> V_105 [ V_45 ] . V_106 == V_107 ) )
V_87 &= ~ V_108 ;
V_87 |= V_85 << V_109 ;
V_83 -> V_87 = F_42 ( V_87 ) ;
V_31 = ( F_2 ( V_83 -> V_87 )
& V_103 )
>> V_109 ;
V_81 -> V_87 = F_42 ( V_87 ) ;
F_31 ( V_2 , V_81 -> V_92 ,
V_45 , V_31 ,
F_2 ( V_81 -> V_98 ) ) ;
return 0 ;
}
int F_47 ( struct V_71 * V_72 , void * V_73 )
{
struct V_110 * V_111 = & V_72 -> V_76 . V_111 ;
V_72 -> V_77 = F_42 ( V_112 ) ;
V_72 -> V_79 = F_42 ( sizeof( * V_111 ) + V_80 ) ;
memcpy ( V_111 , V_73 , sizeof( * V_111 ) ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
T_2 V_54 , T_2 V_45 ,
T_1 * V_46 , T_1 V_113 , void * V_21 )
{
struct V_24 * V_25 ;
int V_114 , V_26 , V_115 , V_31 ;
T_2 V_116 ;
bool V_117 = false ;
int V_8 = 0 ;
V_25 = F_24 ( V_2 , V_45 , V_46 ) ;
if ( ! V_25 ) {
if ( V_113 != V_118 )
F_11 ( V_2 , V_21 ) ;
return V_8 ;
}
if ( ( V_113 == V_10 ) && ! V_25 -> V_106 ) {
F_11 ( V_2 , V_21 ) ;
return V_8 ;
}
V_26 = V_25 -> V_26 ;
V_114 = V_26 ;
V_31 = V_25 -> V_31 ;
V_115 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( V_25 -> V_30 & V_64 ) {
V_117 = true ;
V_25 -> V_30 &= ~ V_64 ;
}
if ( V_25 -> V_30 & V_119 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_6 ) ;
V_25 -> V_30 &= ~ V_119 ;
} else if ( V_117 && V_54 < V_26 &&
V_54 >= V_25 -> V_60 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_7 ,
V_26 , V_54 , V_25 -> V_60 ) ;
V_25 -> V_26 = V_26 = V_54 ;
V_115 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
} else {
if ( ( V_26 + V_120 ) > ( V_36 - 1 ) ) {
if ( V_54 >= ( ( V_26 + V_120 ) &
( V_36 - 1 ) ) &&
V_54 < V_26 ) {
V_8 = - 1 ;
goto V_121;
}
} else if ( ( V_54 < V_26 ) ||
( V_54 >= ( V_26 + V_120 ) ) ) {
V_8 = - 1 ;
goto V_121;
}
}
if ( V_113 == V_118 )
V_54 = ( ( V_54 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( ( ( V_115 < V_26 ) &&
( V_54 < V_26 ) && ( V_54 > V_115 ) ) ||
( ( V_115 > V_26 ) && ( ( V_54 > V_115 ) ||
( V_54 < V_26 ) ) ) ) {
V_115 = V_54 ;
if ( ( ( V_54 - V_31 ) + 1 ) >= 0 )
V_26 = ( V_115 - V_31 ) + 1 ;
else
V_26 = ( V_36 - ( V_31 - V_54 ) ) + 1 ;
F_14 ( V_2 , V_25 , V_26 ) ;
}
if ( V_113 != V_118 ) {
if ( V_54 >= V_26 )
V_116 = V_54 - V_26 ;
else
V_116 = ( V_54 + V_36 ) - V_26 ;
if ( V_25 -> V_33 [ V_116 ] ) {
V_8 = - 1 ;
goto V_121;
}
V_25 -> V_33 [ V_116 ] = V_21 ;
}
F_18 ( V_2 , V_25 ) ;
V_121:
if ( ! V_25 -> V_41 . V_43 ||
V_114 != V_25 -> V_26 )
F_38 ( V_25 ) ;
return V_8 ;
}
void
F_49 ( struct V_1 * V_2 , int V_45 , T_1 * V_122 ,
T_1 type , int V_123 )
{
struct V_24 * V_25 ;
struct V_124 * V_125 ;
T_1 V_126 ;
unsigned long V_30 ;
if ( type == V_127 )
V_126 = ( V_123 ) ? true : false ;
else
V_126 = ( V_123 ) ? false : true ;
F_30 ( V_2 -> V_19 -> V_20 , L_8 ,
V_122 , V_45 , V_123 ) ;
if ( V_126 ) {
V_25 = F_24 ( V_2 , V_45 ,
V_122 ) ;
if ( ! V_25 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_9 ) ;
return;
}
F_19 ( V_2 , V_25 ) ;
} else {
V_125 = F_50 ( V_2 , V_45 , V_122 ) ;
if ( ! V_125 ) {
F_30 ( V_2 -> V_19 -> V_20 ,
L_10 ) ;
return;
}
F_16 ( & V_2 -> V_128 , V_30 ) ;
F_51 ( V_2 , V_125 ) ;
F_17 ( & V_2 -> V_128 , V_30 ) ;
}
}
int F_52 ( struct V_1 * V_2 ,
struct V_71 * V_129 )
{
struct V_82 * V_83 = & V_129 -> V_76 . V_83 ;
int V_45 , V_31 ;
struct V_24 * V_25 ;
T_4 V_87 ;
V_87 = F_2 ( V_83 -> V_87 ) ;
V_45 = ( V_87 & V_99 )
>> V_100 ;
if ( F_2 ( V_83 -> V_101 ) != V_130 ) {
F_10 ( V_2 -> V_19 -> V_20 , L_11 ,
V_83 -> V_92 , V_45 ) ;
V_25 = F_24 ( V_2 , V_45 ,
V_83 -> V_92 ) ;
if ( V_25 )
F_19 ( V_2 , V_25 ) ;
return 0 ;
}
V_31 = ( V_87 & V_103 )
>> V_109 ;
V_25 = F_24 ( V_2 , V_45 ,
V_83 -> V_92 ) ;
if ( V_25 ) {
if ( ( V_87 & V_108 ) &&
V_2 -> V_86 . V_104 &&
( V_2 -> V_105 [ V_45 ] . V_106 != V_107 ) )
V_25 -> V_106 = true ;
else
V_25 -> V_106 = false ;
}
F_30 ( V_2 -> V_19 -> V_20 ,
L_12 ,
V_83 -> V_92 , V_45 , V_83 -> V_98 , V_31 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_110 V_133 ;
memset ( & V_133 , 0 , sizeof( struct V_110 ) ) ;
memcpy ( V_133 . V_92 , V_132 -> V_92 , V_47 ) ;
V_133 . V_134 |=
F_42 ( ( T_2 ) V_132 -> V_45 << V_135 ) ;
V_133 . V_134 |= F_42 (
( T_2 ) V_132 -> V_136 << V_137 ) ;
V_133 . V_138 = F_42 ( V_139 ) ;
F_54 ( V_2 , V_112 , 0 , 0 , & V_133 , false ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_24 * V_140 , * V_141 ;
unsigned long V_30 ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
F_27 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_17 ( & V_2 -> V_44 , V_30 ) ;
F_19 ( V_2 , V_140 ) ;
F_16 ( & V_2 -> V_44 , V_30 ) ;
}
F_33 ( & V_2 -> V_51 ) ;
F_17 ( & V_2 -> V_44 , V_30 ) ;
F_56 ( V_2 ) ;
}
void F_57 ( struct V_142 * V_19 , T_1 V_30 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
unsigned long V_143 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_19 -> V_144 ; V_28 ++ ) {
V_2 = V_19 -> V_2 [ V_28 ] ;
if ( ! V_2 )
continue;
F_16 ( & V_2 -> V_44 , V_143 ) ;
if ( F_58 ( & V_2 -> V_51 ) ) {
F_17 ( & V_2 -> V_44 ,
V_143 ) ;
continue;
}
F_25 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_25 -> V_30 = V_30 ;
F_17 ( & V_2 -> V_44 , V_143 ) ;
}
return;
}
