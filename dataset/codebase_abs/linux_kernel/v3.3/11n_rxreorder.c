static void
F_1 ( struct V_1 * V_2 ,
struct V_3
* V_4 , int V_5 )
{
int V_6 , V_7 ;
void * V_8 ;
unsigned long V_9 ;
V_6 = ( V_5 > V_4 -> V_5 ) ?
F_2 ( ( V_5 - V_4 -> V_5 ) ,
V_4 -> V_10 ) : V_4 -> V_10 ;
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
V_4 -> V_12 [ V_7 ] =
V_4 -> V_12 [ V_6 + V_7 ] ;
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
V_4 -> V_12 [ V_14 ] =
V_4 -> V_12 [ V_7 + V_14 ] ;
V_4 -> V_12 [ V_7 + V_14 ] = NULL ;
}
}
V_4 -> V_5 = ( V_4 -> V_5 + V_7 )
& ( V_16 - 1 ) ;
F_4 ( & V_2 -> V_11 , V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_3
* V_4 )
{
unsigned long V_9 ;
if ( ! V_4 )
return;
F_1 ( V_2 , V_4 ,
( V_4 -> V_5 +
V_4 -> V_10 )
& ( V_16 - 1 ) ) ;
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
F_12 (rx_reor_tbl_ptr, &priv->rx_reorder_tbl_ptr, list) {
if ( ( ! memcmp ( V_4 -> V_22 , V_22 , V_23 ) )
&& ( V_4 -> V_21 == V_21 ) ) {
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
if ( V_5 >= 0 ) {
F_15 ( V_27 -> V_2 -> V_13 -> V_29 ,
L_1 , V_5 ) ;
F_1 ( V_27 -> V_2 ,
V_27 -> V_28 ,
( ( V_27 -> V_28 -> V_5 +
V_5 + 1 ) & ( V_16 - 1 ) ) ) ;
}
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
F_1 ( V_2 , V_4 ,
V_30 ) ;
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
if ( V_32 >= V_31 -> V_5 )
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
V_31 -> V_17 . V_18 . V_36 = F_14 ;
V_31 -> V_17 . V_18 . V_37 =
( unsigned long ) & V_31 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_31 -> V_12 [ V_7 ] = NULL ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_22 ( & V_31 -> V_20 , & V_2 -> V_24 ) ;
F_4 ( & V_2 -> V_19 , V_9 ) ;
}
int F_23 ( struct V_38 * V_39 , void * V_40 )
{
struct V_41 * V_42 =
(struct V_41 * )
& V_39 -> V_43 . V_42 ;
V_39 -> V_44 = F_24 ( V_45 ) ;
V_39 -> V_46 = F_24 ( sizeof( * V_42 ) + V_47 ) ;
memcpy ( V_42 , V_40 , sizeof( * V_42 ) ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_41
* V_48 )
{
struct V_49 * V_50 =
(struct V_49 * )
& V_39 -> V_43 . V_50 ;
T_1 V_21 ;
int V_10 ;
T_3 V_51 ;
V_39 -> V_44 = F_24 ( V_52 ) ;
V_39 -> V_46 = F_24 ( sizeof( * V_50 ) + V_47 ) ;
memcpy ( V_50 -> V_53 , V_48 -> V_53 ,
V_23 ) ;
V_50 -> V_54 = V_48 -> V_54 ;
V_50 -> V_55 = V_48 -> V_55 ;
V_50 -> V_56 = V_48 -> V_56 ;
V_51 = F_26 ( V_48 -> V_51 ) ;
V_21 = ( V_51 & V_57 )
>> V_58 ;
V_50 -> V_59 = F_24 ( V_60 ) ;
V_51 &= ~ V_61 ;
V_51 &= ~ V_62 ;
V_51 |= ( V_2 -> V_63 . V_64 <<
V_65 ) ;
V_50 -> V_51 = F_24 ( V_51 ) ;
V_10 = ( F_26 ( V_50 -> V_51 )
& V_61 )
>> V_65 ;
V_48 -> V_51 = F_24 ( V_51 ) ;
F_16 ( V_2 , V_48 -> V_53 ,
V_21 , V_10 , F_26 ( V_48 -> V_56 ) ) ;
return 0 ;
}
int F_27 ( struct V_38 * V_39 , void * V_40 )
{
struct V_66 * V_67 = (struct V_66 * )
& V_39 -> V_43 . V_67 ;
V_39 -> V_44 = F_24 ( V_68 ) ;
V_39 -> V_46 = F_24 ( sizeof( * V_67 ) + V_47 ) ;
memcpy ( V_67 , V_40 , sizeof( * V_67 ) ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
T_2 V_30 , T_2 V_21 ,
T_1 * V_22 , T_1 V_69 , void * V_70 )
{
struct V_3 * V_4 ;
int V_5 , V_71 , V_10 ;
T_2 V_72 ;
V_4 =
F_11 ( (struct V_1 * ) V_2 ,
V_21 , V_22 ) ;
if ( ! V_4 ) {
if ( V_69 != V_73 )
F_5 ( V_2 -> V_13 , V_70 ) ;
return 0 ;
}
V_5 = V_4 -> V_5 ;
V_10 = V_4 -> V_10 ;
V_71 = ( ( V_5 + V_10 ) - 1 ) & ( V_16 - 1 ) ;
F_8 ( & V_4 -> V_17 . V_18 ) ;
F_29 ( & V_4 -> V_17 . V_18 , V_74
+ ( V_75 * V_10 * V_76 ) / 1000 ) ;
if ( ( V_5 + V_77 ) > ( V_16 - 1 ) ) {
if ( V_30 >= ( ( V_5 + ( V_77 ) ) & ( V_16 - 1 ) )
&& ( V_30 < V_5 ) )
return - 1 ;
} else if ( ( V_30 < V_5 )
|| ( V_30 > ( V_5 + ( V_77 ) ) ) ) {
return - 1 ;
}
if ( V_69 == V_73 )
V_30 = ( ( V_30 + V_10 ) - 1 ) & ( V_16 - 1 ) ;
if ( ( ( V_71 < V_5 )
&& ( V_30 < ( V_77 - ( V_16 - V_5 ) ) )
&& ( V_30 > V_71 ) ) || ( ( V_71 > V_5 )
&& ( ( V_30 > V_71 ) || ( V_30 < V_5 ) ) ) ) {
V_71 = V_30 ;
if ( ( ( V_30 - V_10 ) + 1 ) >= 0 )
V_5 = ( V_71 - V_10 ) + 1 ;
else
V_5 = ( V_16 - ( V_10 - V_30 ) ) + 1 ;
F_1 ( V_2 ,
V_4 , V_5 ) ;
}
if ( V_69 != V_73 ) {
if ( V_30 >= V_5 )
V_72 = V_30 - V_5 ;
else
V_72 = ( V_30 + V_16 ) - V_5 ;
if ( V_4 -> V_12 [ V_72 ] )
return - 1 ;
V_4 -> V_12 [ V_72 ] = V_70 ;
}
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
void
F_30 ( struct V_1 * V_2 , int V_21 ,
T_1 * V_78 , T_1 type , int V_79 )
{
struct V_3 * V_4 ;
struct V_80 * V_81 ;
T_1 V_82 ;
unsigned long V_9 ;
if ( type == V_83 )
V_82 = ( V_79 ) ? true : false ;
else
V_82 = ( V_79 ) ? false : true ;
F_15 ( V_2 -> V_13 -> V_29 , L_5
L_6 , V_78 , V_21 , V_79 ) ;
if ( V_82 ) {
V_4 = F_11 ( V_2 , V_21 ,
V_78 ) ;
if ( ! V_4 ) {
F_15 ( V_2 -> V_13 -> V_29 ,
L_7 ) ;
return;
}
F_7 ( V_2 , V_4 ) ;
} else {
V_81 = F_31 ( V_2 , V_21 , V_78 ) ;
if ( ! V_81 ) {
F_15 ( V_2 -> V_13 -> V_29 ,
L_8 ) ;
return;
}
F_3 ( & V_2 -> V_84 , V_9 ) ;
F_32 ( V_2 , V_81 ) ;
F_4 ( & V_2 -> V_84 , V_9 ) ;
}
}
int F_33 ( struct V_1 * V_2 ,
struct V_38 * V_85 )
{
struct V_49 * V_50 =
(struct V_49 * )
& V_85 -> V_43 . V_50 ;
int V_21 , V_10 ;
struct V_3 * V_4 ;
T_3 V_51 ;
V_51 = F_26 ( V_50 -> V_51 ) ;
V_21 = ( V_51 & V_57 )
>> V_58 ;
if ( F_26 ( V_50 -> V_59 ) == V_86 ) {
V_10 = ( V_51 &
V_61 )
>> V_65 ;
F_15 ( V_2 -> V_13 -> V_29 , L_9
L_10 ,
V_50 -> V_53 ,
V_21 , V_50 -> V_56 , V_10 ) ;
} else {
F_18 ( V_2 -> V_13 -> V_29 , L_11 ,
V_50 -> V_53 , V_21 ) ;
V_4 = F_11 ( V_2 ,
V_21 , V_50 -> V_53 ) ;
if ( V_4 )
F_7 ( V_2 ,
V_4 ) ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_66 V_89 ;
memset ( & V_89 , 0 , sizeof( struct V_66 ) ) ;
memcpy ( V_89 . V_53 , V_88 -> V_53 , V_23 ) ;
V_89 . V_90 |=
F_24 ( ( T_2 ) V_88 -> V_21 << V_91 ) ;
V_89 . V_90 |= F_24 (
( T_2 ) V_88 -> V_92 << V_93 ) ;
V_89 . V_94 = F_24 ( V_95 ) ;
F_35 ( V_2 , V_68 , 0 , 0 , & V_89 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_96 , * V_97 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
F_37 (del_tbl_ptr, tmp_node,
&priv->rx_reorder_tbl_ptr, list) {
F_4 ( & V_2 -> V_19 , V_9 ) ;
F_7 ( V_2 , V_96 ) ;
F_3 ( & V_2 -> V_19 , V_9 ) ;
}
F_4 ( & V_2 -> V_19 , V_9 ) ;
F_19 ( & V_2 -> V_24 ) ;
memset ( V_2 -> V_35 , 0 , sizeof( V_2 -> V_35 ) ) ;
}
