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
V_26 = ( V_25 -> V_26 + V_25 -> V_31 ) & ( V_36 - 1 ) ;
F_14 ( V_2 , V_25 , V_26 ) ;
F_20 ( & V_25 -> V_37 . V_38 ) ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
F_21 ( & V_25 -> V_12 ) ;
F_17 ( & V_2 -> V_39 , V_30 ) ;
F_22 ( V_25 -> V_33 ) ;
F_22 ( V_25 ) ;
}
struct V_24 *
F_23 ( struct V_1 * V_2 , int V_40 , T_1 * V_41 )
{
struct V_24 * V_25 ;
unsigned long V_30 ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
F_24 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_25 -> V_41 , V_41 , V_42 ) && V_25 -> V_40 == V_40 ) {
F_17 ( & V_2 -> V_39 ,
V_30 ) ;
return V_25 ;
}
}
F_17 ( & V_2 -> V_39 , V_30 ) ;
return NULL ;
}
void F_25 ( struct V_1 * V_2 , T_1 * V_41 )
{
struct V_24 * V_25 , * V_43 ;
unsigned long V_30 ;
if ( ! V_41 )
return;
F_16 ( & V_2 -> V_39 , V_30 ) ;
F_26 (tbl, tmp, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_25 -> V_41 , V_41 , V_42 ) ) {
F_17 ( & V_2 -> V_39 ,
V_30 ) ;
F_19 ( V_2 , V_25 ) ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
}
}
F_17 ( & V_2 -> V_39 , V_30 ) ;
return;
}
static int
F_27 ( struct V_24 * V_44 )
{
int V_28 ;
for ( V_28 = ( V_44 -> V_31 - 1 ) ; V_28 >= 0 ; -- V_28 )
if ( V_44 -> V_33 [ V_28 ] )
return V_28 ;
return - 1 ;
}
static void
F_28 ( unsigned long V_45 )
{
struct V_46 * V_47 =
(struct V_46 * ) V_45 ;
int V_26 , V_48 ;
V_48 = F_27 ( V_47 -> V_49 ) ;
if ( V_48 < 0 )
return;
F_29 ( V_47 -> V_2 -> V_19 -> V_20 , L_2 , V_48 ) ;
V_26 = ( V_47 -> V_49 -> V_26 + V_48 + 1 ) & ( V_36 - 1 ) ;
F_14 ( V_47 -> V_2 , V_47 -> V_49 ,
V_26 ) ;
}
static void
F_30 ( struct V_1 * V_2 , T_1 * V_41 ,
int V_40 , int V_31 , int V_48 )
{
int V_28 ;
struct V_24 * V_25 , * V_50 ;
T_2 V_51 = 0 ;
unsigned long V_30 ;
struct V_52 * V_53 ;
V_25 = F_23 ( V_2 , V_40 , V_41 ) ;
if ( V_25 ) {
F_14 ( V_2 , V_25 , V_48 ) ;
return;
}
V_50 = F_31 ( sizeof( struct V_24 ) , V_54 ) ;
if ( ! V_50 )
return;
F_32 ( & V_50 -> V_12 ) ;
V_50 -> V_40 = V_40 ;
memcpy ( V_50 -> V_41 , V_41 , V_42 ) ;
V_50 -> V_26 = V_48 ;
V_50 -> V_55 = V_48 ;
V_50 -> V_30 = 0 ;
if ( F_33 ( V_2 ) ) {
F_29 ( V_2 -> V_19 -> V_20 ,
L_3 ,
V_51 , V_50 -> V_26 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_53 = F_34 ( V_2 , V_41 ) ;
if ( V_53 )
V_51 = V_53 -> V_56 [ V_40 ] ;
}
} else {
V_53 = F_34 ( V_2 , V_41 ) ;
if ( V_53 )
V_51 = V_53 -> V_56 [ V_40 ] ;
else
V_51 = V_2 -> V_56 [ V_40 ] ;
}
if ( V_51 != V_57 &&
V_51 >= V_50 -> V_26 ) {
V_50 -> V_26 = V_51 + 1 ;
V_50 -> V_30 |= V_58 ;
}
V_50 -> V_31 = V_31 ;
V_50 -> V_33 = F_31 ( sizeof( void * ) * V_31 ,
V_54 ) ;
if ( ! V_50 -> V_33 ) {
F_22 ( ( T_1 * ) V_50 ) ;
F_10 ( V_2 -> V_19 -> V_20 ,
L_4 , V_59 ) ;
return;
}
V_50 -> V_37 . V_49 = V_50 ;
V_50 -> V_37 . V_2 = V_2 ;
F_35 ( & V_50 -> V_37 . V_38 ) ;
V_50 -> V_37 . V_38 . V_60 = F_28 ;
V_50 -> V_37 . V_38 . V_7 =
( unsigned long ) & V_50 -> V_37 ;
for ( V_28 = 0 ; V_28 < V_31 ; ++ V_28 )
V_50 -> V_33 [ V_28 ] = NULL ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
F_36 ( & V_50 -> V_12 , & V_2 -> V_44 ) ;
F_17 ( & V_2 -> V_39 , V_30 ) ;
}
int F_37 ( struct V_61 * V_62 , void * V_63 )
{
struct V_64 * V_65 = & V_62 -> V_66 . V_65 ;
V_62 -> V_67 = F_38 ( V_68 ) ;
V_62 -> V_69 = F_38 ( sizeof( * V_65 ) + V_70 ) ;
memcpy ( V_65 , V_63 , sizeof( * V_65 ) ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_64
* V_71 )
{
struct V_72 * V_73 = & V_62 -> V_66 . V_73 ;
struct V_52 * V_74 ;
T_3 V_75 = V_2 -> V_76 . V_75 ;
T_1 V_40 ;
int V_31 ;
T_4 V_77 ;
if ( ( F_40 ( V_2 ) == V_78 ) &&
F_41 ( V_2 -> V_19 -> V_79 ) &&
V_2 -> V_19 -> V_80 &&
memcmp ( V_2 -> V_81 , V_71 -> V_82 , V_42 ) ) {
V_74 = F_34 ( V_2 ,
V_71 -> V_82 ) ;
if ( ! V_74 ) {
F_42 ( V_2 -> V_19 -> V_20 ,
L_5 ,
V_71 -> V_82 ) ;
return - 1 ;
}
if ( V_74 -> V_83 )
V_75 = V_84 ;
}
V_62 -> V_67 = F_38 ( V_85 ) ;
V_62 -> V_69 = F_38 ( sizeof( * V_73 ) + V_70 ) ;
memcpy ( V_73 -> V_82 , V_71 -> V_82 ,
V_42 ) ;
V_73 -> V_86 = V_71 -> V_86 ;
V_73 -> V_87 = V_71 -> V_87 ;
V_73 -> V_88 = V_71 -> V_88 ;
V_77 = F_2 ( V_71 -> V_77 ) ;
V_40 = ( V_77 & V_89 )
>> V_90 ;
V_73 -> V_91 = F_38 ( V_92 ) ;
V_77 &= ~ V_93 ;
if ( ! V_2 -> V_76 . V_94 ||
( V_2 -> V_95 [ V_40 ] . V_96 == V_97 ) )
V_77 &= ~ V_98 ;
V_77 |= V_75 << V_99 ;
V_73 -> V_77 = F_38 ( V_77 ) ;
V_31 = ( F_2 ( V_73 -> V_77 )
& V_93 )
>> V_99 ;
V_71 -> V_77 = F_38 ( V_77 ) ;
F_30 ( V_2 , V_71 -> V_82 ,
V_40 , V_31 ,
F_2 ( V_71 -> V_88 ) ) ;
return 0 ;
}
int F_43 ( struct V_61 * V_62 , void * V_63 )
{
struct V_100 * V_101 = & V_62 -> V_66 . V_101 ;
V_62 -> V_67 = F_38 ( V_102 ) ;
V_62 -> V_69 = F_38 ( sizeof( * V_101 ) + V_70 ) ;
memcpy ( V_101 , V_63 , sizeof( * V_101 ) ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 ,
T_2 V_48 , T_2 V_40 ,
T_1 * V_41 , T_1 V_103 , void * V_21 )
{
struct V_24 * V_25 ;
int V_26 , V_104 , V_31 ;
T_2 V_105 ;
bool V_106 = false ;
V_25 = F_23 ( V_2 , V_40 , V_41 ) ;
if ( ! V_25 ) {
if ( V_103 != V_107 )
F_11 ( V_2 , V_21 ) ;
return 0 ;
}
if ( ( V_103 == V_10 ) && ! V_25 -> V_96 ) {
F_11 ( V_2 , V_21 ) ;
return 0 ;
}
V_26 = V_25 -> V_26 ;
V_31 = V_25 -> V_31 ;
V_104 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( V_25 -> V_30 & V_58 ) {
V_106 = true ;
V_25 -> V_30 &= ~ V_58 ;
}
F_45 ( & V_25 -> V_37 . V_38 ,
V_108 + F_46 ( V_109 * V_31 ) ) ;
if ( V_25 -> V_30 & V_110 ) {
F_29 ( V_2 -> V_19 -> V_20 ,
L_6 ) ;
V_25 -> V_30 &= ~ V_110 ;
} else if ( V_106 && V_48 < V_26 &&
V_48 >= V_25 -> V_55 ) {
F_29 ( V_2 -> V_19 -> V_20 ,
L_7 ,
V_26 , V_48 , V_25 -> V_55 ) ;
V_25 -> V_26 = V_26 = V_48 ;
V_104 = ( ( V_26 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
} else {
if ( ( V_26 + V_111 ) > ( V_36 - 1 ) ) {
if ( V_48 >= ( ( V_26 + V_111 ) &
( V_36 - 1 ) ) &&
V_48 < V_26 )
return - 1 ;
} else if ( ( V_48 < V_26 ) ||
( V_48 > ( V_26 + V_111 ) ) ) {
return - 1 ;
}
}
if ( V_103 == V_107 )
V_48 = ( ( V_48 + V_31 ) - 1 ) & ( V_36 - 1 ) ;
if ( ( ( V_104 < V_26 ) &&
( V_48 < V_26 ) && ( V_48 > V_104 ) ) ||
( ( V_104 > V_26 ) && ( ( V_48 > V_104 ) ||
( V_48 < V_26 ) ) ) ) {
V_104 = V_48 ;
if ( ( ( V_48 - V_31 ) + 1 ) >= 0 )
V_26 = ( V_104 - V_31 ) + 1 ;
else
V_26 = ( V_36 - ( V_31 - V_48 ) ) + 1 ;
F_14 ( V_2 , V_25 , V_26 ) ;
}
if ( V_103 != V_107 ) {
if ( V_48 >= V_26 )
V_105 = V_48 - V_26 ;
else
V_105 = ( V_48 + V_36 ) - V_26 ;
if ( V_25 -> V_33 [ V_105 ] )
return - 1 ;
V_25 -> V_33 [ V_105 ] = V_21 ;
}
F_18 ( V_2 , V_25 ) ;
return 0 ;
}
void
F_47 ( struct V_1 * V_2 , int V_40 , T_1 * V_112 ,
T_1 type , int V_113 )
{
struct V_24 * V_25 ;
struct V_114 * V_115 ;
T_1 V_116 ;
unsigned long V_30 ;
if ( type == V_117 )
V_116 = ( V_113 ) ? true : false ;
else
V_116 = ( V_113 ) ? false : true ;
F_29 ( V_2 -> V_19 -> V_20 , L_8 ,
V_112 , V_40 , V_113 ) ;
if ( V_116 ) {
V_25 = F_23 ( V_2 , V_40 ,
V_112 ) ;
if ( ! V_25 ) {
F_29 ( V_2 -> V_19 -> V_20 ,
L_9 ) ;
return;
}
F_19 ( V_2 , V_25 ) ;
} else {
V_115 = F_48 ( V_2 , V_40 , V_112 ) ;
if ( ! V_115 ) {
F_29 ( V_2 -> V_19 -> V_20 ,
L_10 ) ;
return;
}
F_16 ( & V_2 -> V_118 , V_30 ) ;
F_49 ( V_2 , V_115 ) ;
F_17 ( & V_2 -> V_118 , V_30 ) ;
}
}
int F_50 ( struct V_1 * V_2 ,
struct V_61 * V_119 )
{
struct V_72 * V_73 = & V_119 -> V_66 . V_73 ;
int V_40 , V_31 ;
struct V_24 * V_25 ;
T_4 V_77 ;
V_77 = F_2 ( V_73 -> V_77 ) ;
V_40 = ( V_77 & V_89 )
>> V_90 ;
if ( F_2 ( V_73 -> V_91 ) != V_120 ) {
F_10 ( V_2 -> V_19 -> V_20 , L_11 ,
V_73 -> V_82 , V_40 ) ;
V_25 = F_23 ( V_2 , V_40 ,
V_73 -> V_82 ) ;
if ( V_25 )
F_19 ( V_2 , V_25 ) ;
return 0 ;
}
V_31 = ( V_77 & V_93 )
>> V_99 ;
V_25 = F_23 ( V_2 , V_40 ,
V_73 -> V_82 ) ;
if ( V_25 ) {
if ( ( V_77 & V_98 ) &&
V_2 -> V_76 . V_94 &&
( V_2 -> V_95 [ V_40 ] . V_96 != V_97 ) )
V_25 -> V_96 = true ;
else
V_25 -> V_96 = false ;
}
F_29 ( V_2 -> V_19 -> V_20 ,
L_12 ,
V_73 -> V_82 , V_40 , V_73 -> V_88 , V_31 ) ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_100 V_123 ;
memset ( & V_123 , 0 , sizeof( struct V_100 ) ) ;
memcpy ( V_123 . V_82 , V_122 -> V_82 , V_42 ) ;
V_123 . V_124 |=
F_38 ( ( T_2 ) V_122 -> V_40 << V_125 ) ;
V_123 . V_124 |= F_38 (
( T_2 ) V_122 -> V_126 << V_127 ) ;
V_123 . V_128 = F_38 ( V_129 ) ;
F_52 ( V_2 , V_102 , 0 , 0 , & V_123 , false ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_24 * V_130 , * V_131 ;
unsigned long V_30 ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
F_26 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_17 ( & V_2 -> V_39 , V_30 ) ;
F_19 ( V_2 , V_130 ) ;
F_16 ( & V_2 -> V_39 , V_30 ) ;
}
F_17 ( & V_2 -> V_39 , V_30 ) ;
F_32 ( & V_2 -> V_44 ) ;
F_54 ( V_2 ) ;
}
void F_55 ( struct V_132 * V_19 , T_1 V_30 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
unsigned long V_133 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_19 -> V_134 ; V_28 ++ ) {
V_2 = V_19 -> V_2 [ V_28 ] ;
if ( ! V_2 )
continue;
if ( F_56 ( & V_2 -> V_44 ) )
continue;
F_16 ( & V_2 -> V_39 , V_133 ) ;
F_24 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_25 -> V_30 = V_30 ;
F_17 ( & V_2 -> V_39 , V_133 ) ;
}
return;
}
