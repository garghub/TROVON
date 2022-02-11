static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 , V_7 ;
void * V_8 ;
unsigned long V_9 ;
V_6 = ( V_5 > V_4 -> V_5 ) ?
F_2 ( ( V_5 - V_4 -> V_5 ) , V_4 -> V_10 ) :
V_4 -> V_10 ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
F_3 ( & V_2 -> V_11 , V_9 ) ;
V_8 = NULL ;
if ( V_4 -> V_12 [ V_7 ] ) {
V_8 = V_4 -> V_12 [ V_7 ] ;
V_4 -> V_12 [ V_7 ] = NULL ;
}
F_4 ( & V_2 -> V_11 , V_9 ) ;
if ( V_8 ) {
if ( V_2 -> V_13 == V_14 )
F_5 ( V_2 , V_8 ) ;
else
F_6 ( V_2 , V_8 ) ;
}
}
F_3 ( & V_2 -> V_11 , V_9 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_10 - V_6 ; ++ V_7 ) {
V_4 -> V_12 [ V_7 ] = V_4 -> V_12 [ V_6 + V_7 ] ;
V_4 -> V_12 [ V_6 + V_7 ] = NULL ;
}
V_4 -> V_5 = V_5 ;
F_4 ( & V_2 -> V_11 , V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 , V_15 , V_16 ;
void * V_8 ;
unsigned long V_9 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_10 ; ++ V_7 ) {
F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( ! V_4 -> V_12 [ V_7 ] ) {
F_4 ( & V_2 -> V_11 , V_9 ) ;
break;
}
V_8 = V_4 -> V_12 [ V_7 ] ;
V_4 -> V_12 [ V_7 ] = NULL ;
F_4 ( & V_2 -> V_11 , V_9 ) ;
if ( V_2 -> V_13 == V_14 )
F_5 ( V_2 , V_8 ) ;
else
F_6 ( V_2 , V_8 ) ;
}
F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( V_7 > 0 ) {
V_16 = V_4 -> V_10 - V_7 ;
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
V_4 -> V_12 [ V_15 ] = V_4 -> V_12 [ V_7 + V_15 ] ;
V_4 -> V_12 [ V_7 + V_15 ] = NULL ;
}
}
V_4 -> V_5 = ( V_4 -> V_5 + V_7 ) & ( V_17 - 1 ) ;
F_4 ( & V_2 -> V_11 , V_9 ) ;
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_9 ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 , ( V_4 -> V_5 + V_4 -> V_10 ) &
( V_17 - 1 ) ) ;
F_9 ( & V_4 -> V_18 . V_19 ) ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
F_10 ( & V_4 -> V_21 ) ;
F_4 ( & V_2 -> V_20 , V_9 ) ;
F_11 ( V_4 -> V_12 ) ;
F_11 ( V_4 ) ;
}
struct V_3 *
F_12 ( struct V_1 * V_2 , int V_22 , T_1 * V_23 )
{
struct V_3 * V_4 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
F_13 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_4 -> V_23 , V_23 , V_24 ) && V_4 -> V_22 == V_22 ) {
F_4 ( & V_2 -> V_20 ,
V_9 ) ;
return V_4 ;
}
}
F_4 ( & V_2 -> V_20 , V_9 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_2 , T_1 * V_23 )
{
struct V_3 * V_4 , * V_25 ;
unsigned long V_9 ;
if ( ! V_23 )
return;
F_3 ( & V_2 -> V_20 , V_9 ) ;
F_15 (tbl, tmp, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_4 -> V_23 , V_23 , V_24 ) ) {
F_4 ( & V_2 -> V_20 ,
V_9 ) ;
F_8 ( V_2 , V_4 ) ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
}
}
F_4 ( & V_2 -> V_20 , V_9 ) ;
return;
}
static int
F_16 ( struct V_3 * V_26 )
{
int V_7 ;
for ( V_7 = ( V_26 -> V_10 - 1 ) ; V_7 >= 0 ; -- V_7 )
if ( V_26 -> V_12 [ V_7 ] )
return V_7 ;
return - 1 ;
}
static void
F_17 ( unsigned long V_27 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_27 ;
int V_5 ;
V_5 = F_16 ( V_29 -> V_30 ) ;
if ( V_5 < 0 )
return;
F_18 ( V_29 -> V_2 -> V_31 -> V_32 , L_1 , V_5 ) ;
F_1 ( V_29 -> V_2 , V_29 -> V_30 ,
( V_29 -> V_30 -> V_5 + V_5 + 1 ) &
( V_17 - 1 ) ) ;
}
static void
F_19 ( struct V_1 * V_2 , T_1 * V_23 ,
int V_22 , int V_10 , int V_33 )
{
int V_7 ;
struct V_3 * V_4 , * V_34 ;
T_2 V_35 = 0 ;
unsigned long V_9 ;
struct V_36 * V_37 ;
V_4 = F_12 ( V_2 , V_22 , V_23 ) ;
if ( V_4 ) {
F_1 ( V_2 , V_4 , V_33 ) ;
return;
}
V_34 = F_20 ( sizeof( struct V_3 ) , V_38 ) ;
if ( ! V_34 )
return;
F_21 ( & V_34 -> V_21 ) ;
V_34 -> V_22 = V_22 ;
memcpy ( V_34 -> V_23 , V_23 , V_24 ) ;
V_34 -> V_5 = V_33 ;
if ( F_22 ( V_2 ) ) {
F_18 ( V_2 -> V_31 -> V_32 ,
L_2 ,
V_35 , V_34 -> V_5 ) ;
if ( V_2 -> V_13 == V_14 ) {
V_37 = F_23 ( V_2 , V_23 ) ;
if ( V_37 )
V_35 = V_37 -> V_39 [ V_22 ] ;
}
} else {
V_35 = V_2 -> V_39 [ V_22 ] ;
}
if ( V_35 != V_40 &&
V_35 >= V_34 -> V_5 )
V_34 -> V_5 = V_35 + 1 ;
V_34 -> V_10 = V_10 ;
V_34 -> V_9 = 0 ;
V_34 -> V_12 = F_20 ( sizeof( void * ) * V_10 ,
V_38 ) ;
if ( ! V_34 -> V_12 ) {
F_11 ( ( T_1 * ) V_34 ) ;
F_24 ( V_2 -> V_31 -> V_32 ,
L_3 , V_41 ) ;
return;
}
V_34 -> V_18 . V_30 = V_34 ;
V_34 -> V_18 . V_2 = V_2 ;
F_25 ( & V_34 -> V_18 . V_19 ) ;
V_34 -> V_18 . V_19 . V_42 = F_17 ;
V_34 -> V_18 . V_19 . V_43 =
( unsigned long ) & V_34 -> V_18 ;
for ( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_34 -> V_12 [ V_7 ] = NULL ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
F_26 ( & V_34 -> V_21 , & V_2 -> V_26 ) ;
F_4 ( & V_2 -> V_20 , V_9 ) ;
}
int F_27 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_48 = & V_45 -> V_49 . V_48 ;
V_45 -> V_50 = F_28 ( V_51 ) ;
V_45 -> V_52 = F_28 ( sizeof( * V_48 ) + V_53 ) ;
memcpy ( V_48 , V_46 , sizeof( * V_48 ) ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_47
* V_54 )
{
struct V_55 * V_56 = & V_45 -> V_49 . V_56 ;
T_1 V_22 ;
int V_10 ;
T_3 V_57 ;
V_45 -> V_50 = F_28 ( V_58 ) ;
V_45 -> V_52 = F_28 ( sizeof( * V_56 ) + V_53 ) ;
memcpy ( V_56 -> V_59 , V_54 -> V_59 ,
V_24 ) ;
V_56 -> V_60 = V_54 -> V_60 ;
V_56 -> V_61 = V_54 -> V_61 ;
V_56 -> V_62 = V_54 -> V_62 ;
V_57 = F_30 ( V_54 -> V_57 ) ;
V_22 = ( V_57 & V_63 )
>> V_64 ;
V_56 -> V_65 = F_28 ( V_66 ) ;
V_57 &= ~ V_67 ;
V_57 &= ~ V_68 ;
V_57 |= ( V_2 -> V_69 . V_70 <<
V_71 ) ;
V_56 -> V_57 = F_28 ( V_57 ) ;
V_10 = ( F_30 ( V_56 -> V_57 )
& V_67 )
>> V_71 ;
V_54 -> V_57 = F_28 ( V_57 ) ;
F_19 ( V_2 , V_54 -> V_59 ,
V_22 , V_10 ,
F_30 ( V_54 -> V_62 ) ) ;
return 0 ;
}
int F_31 ( struct V_44 * V_45 , void * V_46 )
{
struct V_72 * V_73 = & V_45 -> V_49 . V_73 ;
V_45 -> V_50 = F_28 ( V_74 ) ;
V_45 -> V_52 = F_28 ( sizeof( * V_73 ) + V_53 ) ;
memcpy ( V_73 , V_46 , sizeof( * V_73 ) ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
T_2 V_33 , T_2 V_22 ,
T_1 * V_23 , T_1 V_75 , void * V_76 )
{
struct V_3 * V_4 ;
int V_5 , V_77 , V_10 ;
T_2 V_78 ;
V_4 = F_12 ( V_2 , V_22 , V_23 ) ;
if ( ! V_4 ) {
if ( V_75 != V_79 ) {
if ( V_2 -> V_13 == V_14 )
F_5 ( V_2 , V_76 ) ;
else
F_6 ( V_2 , V_76 ) ;
}
return 0 ;
}
V_5 = V_4 -> V_5 ;
V_10 = V_4 -> V_10 ;
V_77 = ( ( V_5 + V_10 ) - 1 ) & ( V_17 - 1 ) ;
F_9 ( & V_4 -> V_18 . V_19 ) ;
F_33 ( & V_4 -> V_18 . V_19 ,
V_80 + F_34 ( V_81 * V_10 ) ) ;
if ( V_4 -> V_9 & V_82 ) {
F_18 ( V_2 -> V_31 -> V_32 ,
L_4 ) ;
V_4 -> V_9 &= ~ V_82 ;
} else {
if ( ( V_5 + V_83 ) > ( V_17 - 1 ) ) {
if ( V_33 >= ( ( V_5 + V_83 ) &
( V_17 - 1 ) ) &&
V_33 < V_5 )
return - 1 ;
} else if ( ( V_33 < V_5 ) ||
( V_33 > ( V_5 + V_83 ) ) ) {
return - 1 ;
}
}
if ( V_75 == V_79 )
V_33 = ( ( V_33 + V_10 ) - 1 ) & ( V_17 - 1 ) ;
if ( ( ( V_77 < V_5 ) &&
( V_33 < V_5 ) && ( V_33 > V_77 ) ) ||
( ( V_77 > V_5 ) && ( ( V_33 > V_77 ) ||
( V_33 < V_5 ) ) ) ) {
V_77 = V_33 ;
if ( ( ( V_33 - V_10 ) + 1 ) >= 0 )
V_5 = ( V_77 - V_10 ) + 1 ;
else
V_5 = ( V_17 - ( V_10 - V_33 ) ) + 1 ;
F_1 ( V_2 , V_4 , V_5 ) ;
}
if ( V_75 != V_79 ) {
if ( V_33 >= V_5 )
V_78 = V_33 - V_5 ;
else
V_78 = ( V_33 + V_17 ) - V_5 ;
if ( V_4 -> V_12 [ V_78 ] )
return - 1 ;
V_4 -> V_12 [ V_78 ] = V_76 ;
}
F_7 ( V_2 , V_4 ) ;
return 0 ;
}
void
F_35 ( struct V_1 * V_2 , int V_22 , T_1 * V_84 ,
T_1 type , int V_85 )
{
struct V_3 * V_4 ;
struct V_86 * V_87 ;
T_1 V_88 ;
unsigned long V_9 ;
if ( type == V_89 )
V_88 = ( V_85 ) ? true : false ;
else
V_88 = ( V_85 ) ? false : true ;
F_18 ( V_2 -> V_31 -> V_32 , L_5 ,
V_84 , V_22 , V_85 ) ;
if ( V_88 ) {
V_4 = F_12 ( V_2 , V_22 ,
V_84 ) ;
if ( ! V_4 ) {
F_18 ( V_2 -> V_31 -> V_32 ,
L_6 ) ;
return;
}
F_8 ( V_2 , V_4 ) ;
} else {
V_87 = F_36 ( V_2 , V_22 , V_84 ) ;
if ( ! V_87 ) {
F_18 ( V_2 -> V_31 -> V_32 ,
L_7 ) ;
return;
}
F_3 ( & V_2 -> V_90 , V_9 ) ;
F_37 ( V_2 , V_87 ) ;
F_4 ( & V_2 -> V_90 , V_9 ) ;
}
}
int F_38 ( struct V_1 * V_2 ,
struct V_44 * V_91 )
{
struct V_55 * V_56 = & V_91 -> V_49 . V_56 ;
int V_22 , V_10 ;
struct V_3 * V_4 ;
T_3 V_57 ;
V_57 = F_30 ( V_56 -> V_57 ) ;
V_22 = ( V_57 & V_63 )
>> V_64 ;
if ( F_30 ( V_56 -> V_65 ) == V_92 ) {
V_10 = ( V_57 &
V_67 )
>> V_71 ;
F_18 ( V_2 -> V_31 -> V_32 ,
L_8 ,
V_56 -> V_59 , V_22 ,
V_56 -> V_62 , V_10 ) ;
} else {
F_24 ( V_2 -> V_31 -> V_32 , L_9 ,
V_56 -> V_59 , V_22 ) ;
V_4 = F_12 ( V_2 , V_22 ,
V_56 -> V_59 ) ;
if ( V_4 )
F_8 ( V_2 , V_4 ) ;
}
return 0 ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_72 V_95 ;
memset ( & V_95 , 0 , sizeof( struct V_72 ) ) ;
memcpy ( V_95 . V_59 , V_94 -> V_59 , V_24 ) ;
V_95 . V_96 |=
F_28 ( ( T_2 ) V_94 -> V_22 << V_97 ) ;
V_95 . V_96 |= F_28 (
( T_2 ) V_94 -> V_98 << V_99 ) ;
V_95 . V_100 = F_28 ( V_101 ) ;
F_40 ( V_2 , V_74 , 0 , 0 , & V_95 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_102 , * V_103 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
F_15 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_4 ( & V_2 -> V_20 , V_9 ) ;
F_8 ( V_2 , V_102 ) ;
F_3 ( & V_2 -> V_20 , V_9 ) ;
}
F_4 ( & V_2 -> V_20 , V_9 ) ;
F_21 ( & V_2 -> V_26 ) ;
F_42 ( V_2 ) ;
}
void F_43 ( struct V_104 * V_31 , T_1 V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned long V_105 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_31 -> V_106 ; V_7 ++ ) {
V_2 = V_31 -> V_2 [ V_7 ] ;
if ( ! V_2 )
continue;
if ( F_44 ( & V_2 -> V_26 ) )
continue;
F_3 ( & V_2 -> V_20 , V_105 ) ;
F_13 (tbl, &priv->rx_reorder_tbl_ptr, list)
V_4 -> V_9 = V_9 ;
F_4 ( & V_2 -> V_20 , V_105 ) ;
}
return;
}
