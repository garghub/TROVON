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
if ( V_8 )
F_5 ( V_2 -> V_13 , V_8 ) ;
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
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 , V_14 , V_15 ;
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
F_5 ( V_2 -> V_13 , V_8 ) ;
}
F_3 ( & V_2 -> V_11 , V_9 ) ;
if ( V_7 > 0 ) {
V_15 = V_4 -> V_10 - V_7 ;
for ( V_14 = 0 ; V_14 < V_15 ; ++ V_14 ) {
V_4 -> V_12 [ V_14 ] = V_4 -> V_12 [ V_7 + V_14 ] ;
V_4 -> V_12 [ V_7 + V_14 ] = NULL ;
}
}
V_4 -> V_5 = ( V_4 -> V_5 + V_7 ) & ( V_16 - 1 ) ;
F_4 ( & V_2 -> V_11 , V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_9 ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 , ( V_4 -> V_5 + V_4 -> V_10 ) &
( V_16 - 1 ) ) ;
F_8 ( & V_4 -> V_17 . V_18 ) ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_9 ( & V_4 -> V_20 ) ;
F_4 ( & V_2 -> V_19 , V_9 ) ;
F_10 ( V_4 -> V_12 ) ;
F_10 ( V_4 ) ;
}
static struct V_3 *
F_11 ( struct V_1 * V_2 , int V_21 , T_1 * V_22 )
{
struct V_3 * V_4 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_12 (tbl, &priv->rx_reorder_tbl_ptr, list) {
if ( ! memcmp ( V_4 -> V_22 , V_22 , V_23 ) && V_4 -> V_21 == V_21 ) {
F_4 ( & V_2 -> V_19 ,
V_9 ) ;
return V_4 ;
}
}
F_4 ( & V_2 -> V_19 , V_9 ) ;
return NULL ;
}
static int
F_13 ( struct V_3 * V_24 )
{
int V_7 ;
for ( V_7 = ( V_24 -> V_10 - 1 ) ; V_7 >= 0 ; -- V_7 )
if ( V_24 -> V_12 [ V_7 ] )
return V_7 ;
return - 1 ;
}
static void
F_14 ( unsigned long V_25 )
{
struct V_26 * V_27 =
(struct V_26 * ) V_25 ;
int V_5 ;
V_5 = F_13 ( V_27 -> V_28 ) ;
if ( V_5 < 0 )
return;
F_15 ( V_27 -> V_2 -> V_13 -> V_29 , L_1 , V_5 ) ;
F_1 ( V_27 -> V_2 , V_27 -> V_28 ,
( V_27 -> V_28 -> V_5 + V_5 + 1 ) &
( V_16 - 1 ) ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 * V_22 ,
int V_21 , int V_10 , int V_30 )
{
int V_7 ;
struct V_3 * V_4 , * V_31 ;
T_2 V_32 = 0 ;
unsigned long V_9 ;
V_4 = F_11 ( V_2 , V_21 , V_22 ) ;
if ( V_4 ) {
F_1 ( V_2 , V_4 , V_30 ) ;
return;
}
V_31 = F_17 ( sizeof( struct V_3 ) , V_33 ) ;
if ( ! V_31 ) {
F_18 ( V_2 -> V_13 -> V_29 , L_2 ,
V_34 ) ;
return;
}
F_19 ( & V_31 -> V_20 ) ;
V_31 -> V_21 = V_21 ;
memcpy ( V_31 -> V_22 , V_22 , V_23 ) ;
V_31 -> V_5 = V_30 ;
if ( F_20 ( V_2 ) )
F_15 ( V_2 -> V_13 -> V_29 ,
L_3 ,
V_32 , V_31 -> V_5 ) ;
else
V_32 = V_2 -> V_35 [ V_21 ] ;
if ( V_32 != V_36 &&
V_32 >= V_31 -> V_5 )
V_31 -> V_5 = V_32 + 1 ;
V_31 -> V_10 = V_10 ;
V_31 -> V_12 = F_17 ( sizeof( void * ) * V_10 ,
V_33 ) ;
if ( ! V_31 -> V_12 ) {
F_10 ( ( T_1 * ) V_31 ) ;
F_18 ( V_2 -> V_13 -> V_29 ,
L_4 , V_34 ) ;
return;
}
V_31 -> V_17 . V_28 = V_31 ;
V_31 -> V_17 . V_2 = V_2 ;
F_21 ( & V_31 -> V_17 . V_18 ) ;
V_31 -> V_17 . V_18 . V_37 = F_14 ;
V_31 -> V_17 . V_18 . V_38 =
( unsigned long ) & V_31 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_31 -> V_12 [ V_7 ] = NULL ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_22 ( & V_31 -> V_20 , & V_2 -> V_24 ) ;
F_4 ( & V_2 -> V_19 , V_9 ) ;
}
int F_23 ( struct V_39 * V_40 , void * V_41 )
{
struct V_42 * V_43 =
(struct V_42 * )
& V_40 -> V_44 . V_43 ;
V_40 -> V_45 = F_24 ( V_46 ) ;
V_40 -> V_47 = F_24 ( sizeof( * V_43 ) + V_48 ) ;
memcpy ( V_43 , V_41 , sizeof( * V_43 ) ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_42
* V_49 )
{
struct V_50 * V_51 =
(struct V_50 * )
& V_40 -> V_44 . V_51 ;
T_1 V_21 ;
int V_10 ;
T_3 V_52 ;
V_40 -> V_45 = F_24 ( V_53 ) ;
V_40 -> V_47 = F_24 ( sizeof( * V_51 ) + V_48 ) ;
memcpy ( V_51 -> V_54 , V_49 -> V_54 ,
V_23 ) ;
V_51 -> V_55 = V_49 -> V_55 ;
V_51 -> V_56 = V_49 -> V_56 ;
V_51 -> V_57 = V_49 -> V_57 ;
V_52 = F_26 ( V_49 -> V_52 ) ;
V_21 = ( V_52 & V_58 )
>> V_59 ;
V_51 -> V_60 = F_24 ( V_61 ) ;
V_52 &= ~ V_62 ;
V_52 &= ~ V_63 ;
V_52 |= ( V_2 -> V_64 . V_65 <<
V_66 ) ;
V_51 -> V_52 = F_24 ( V_52 ) ;
V_10 = ( F_26 ( V_51 -> V_52 )
& V_62 )
>> V_66 ;
V_49 -> V_52 = F_24 ( V_52 ) ;
F_16 ( V_2 , V_49 -> V_54 ,
V_21 , V_10 ,
F_26 ( V_49 -> V_57 ) ) ;
return 0 ;
}
int F_27 ( struct V_39 * V_40 , void * V_41 )
{
struct V_67 * V_68 = (struct V_67 * )
& V_40 -> V_44 . V_68 ;
V_40 -> V_45 = F_24 ( V_69 ) ;
V_40 -> V_47 = F_24 ( sizeof( * V_68 ) + V_48 ) ;
memcpy ( V_68 , V_41 , sizeof( * V_68 ) ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
T_2 V_30 , T_2 V_21 ,
T_1 * V_22 , T_1 V_70 , void * V_71 )
{
struct V_3 * V_4 ;
int V_5 , V_72 , V_10 ;
T_2 V_73 ;
V_4 = F_11 ( (struct V_1 * ) V_2 ,
V_21 , V_22 ) ;
if ( ! V_4 ) {
if ( V_70 != V_74 )
F_5 ( V_2 -> V_13 , V_71 ) ;
return 0 ;
}
V_5 = V_4 -> V_5 ;
V_10 = V_4 -> V_10 ;
V_72 = ( ( V_5 + V_10 ) - 1 ) & ( V_16 - 1 ) ;
F_8 ( & V_4 -> V_17 . V_18 ) ;
F_29 ( & V_4 -> V_17 . V_18 ,
V_75 + ( V_76 * V_10 * V_77 ) / 1000 ) ;
if ( ( V_5 + V_78 ) > ( V_16 - 1 ) ) {
if ( V_30 >= ( ( V_5 + V_78 ) &
( V_16 - 1 ) ) && ( V_30 < V_5 ) )
return - 1 ;
} else if ( ( V_30 < V_5 ) ||
( V_30 > ( V_5 + V_78 ) ) ) {
return - 1 ;
}
if ( V_70 == V_74 )
V_30 = ( ( V_30 + V_10 ) - 1 ) & ( V_16 - 1 ) ;
if ( ( ( V_72 < V_5 ) &&
( V_30 < ( V_78 - ( V_16 - V_5 ) ) ) &&
( V_30 > V_72 ) ) ||
( ( V_72 > V_5 ) && ( ( V_30 > V_72 ) ||
( V_30 < V_5 ) ) ) ) {
V_72 = V_30 ;
if ( ( ( V_30 - V_10 ) + 1 ) >= 0 )
V_5 = ( V_72 - V_10 ) + 1 ;
else
V_5 = ( V_16 - ( V_10 - V_30 ) ) + 1 ;
F_1 ( V_2 , V_4 , V_5 ) ;
}
if ( V_70 != V_74 ) {
if ( V_30 >= V_5 )
V_73 = V_30 - V_5 ;
else
V_73 = ( V_30 + V_16 ) - V_5 ;
if ( V_4 -> V_12 [ V_73 ] )
return - 1 ;
V_4 -> V_12 [ V_73 ] = V_71 ;
}
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
void
F_30 ( struct V_1 * V_2 , int V_21 , T_1 * V_79 ,
T_1 type , int V_80 )
{
struct V_3 * V_4 ;
struct V_81 * V_82 ;
T_1 V_83 ;
unsigned long V_9 ;
if ( type == V_84 )
V_83 = ( V_80 ) ? true : false ;
else
V_83 = ( V_80 ) ? false : true ;
F_15 ( V_2 -> V_13 -> V_29 , L_5 ,
V_79 , V_21 , V_80 ) ;
if ( V_83 ) {
V_4 = F_11 ( V_2 , V_21 ,
V_79 ) ;
if ( ! V_4 ) {
F_15 ( V_2 -> V_13 -> V_29 ,
L_6 ) ;
return;
}
F_7 ( V_2 , V_4 ) ;
} else {
V_82 = F_31 ( V_2 , V_21 , V_79 ) ;
if ( ! V_82 ) {
F_15 ( V_2 -> V_13 -> V_29 ,
L_7 ) ;
return;
}
F_3 ( & V_2 -> V_85 , V_9 ) ;
F_32 ( V_2 , V_82 ) ;
F_4 ( & V_2 -> V_85 , V_9 ) ;
}
}
int F_33 ( struct V_1 * V_2 ,
struct V_39 * V_86 )
{
struct V_50 * V_51 =
(struct V_50 * )
& V_86 -> V_44 . V_51 ;
int V_21 , V_10 ;
struct V_3 * V_4 ;
T_3 V_52 ;
V_52 = F_26 ( V_51 -> V_52 ) ;
V_21 = ( V_52 & V_58 )
>> V_59 ;
if ( F_26 ( V_51 -> V_60 ) == V_87 ) {
V_10 = ( V_52 &
V_62 )
>> V_66 ;
F_15 ( V_2 -> V_13 -> V_29 ,
L_8 ,
V_51 -> V_54 , V_21 ,
V_51 -> V_57 , V_10 ) ;
} else {
F_18 ( V_2 -> V_13 -> V_29 , L_9 ,
V_51 -> V_54 , V_21 ) ;
V_4 = F_11 ( V_2 , V_21 ,
V_51 -> V_54 ) ;
if ( V_4 )
F_7 ( V_2 , V_4 ) ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_67 V_90 ;
memset ( & V_90 , 0 , sizeof( struct V_67 ) ) ;
memcpy ( V_90 . V_54 , V_89 -> V_54 , V_23 ) ;
V_90 . V_91 |=
F_24 ( ( T_2 ) V_89 -> V_21 << V_92 ) ;
V_90 . V_91 |= F_24 (
( T_2 ) V_89 -> V_93 << V_94 ) ;
V_90 . V_95 = F_24 ( V_96 ) ;
F_35 ( V_2 , V_69 , 0 , 0 , & V_90 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_97 , * V_98 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_37 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_4 ( & V_2 -> V_19 , V_9 ) ;
F_7 ( V_2 , V_97 ) ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
}
F_4 ( & V_2 -> V_19 , V_9 ) ;
F_19 ( & V_2 -> V_24 ) ;
F_38 ( V_2 ) ;
}
