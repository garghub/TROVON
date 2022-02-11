void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( V_4 -> V_6 . V_7 ) {
F_2 ( ( void * ) V_4 -> V_6 . V_7 ,
V_4 -> V_6 . V_8 , V_2 -> V_9 ) ;
V_4 -> V_6 . V_7 = NULL ;
}
if ( V_4 -> V_10 ) {
F_2 ( ( void * ) V_4 -> V_10 ,
sizeof( struct V_3 ) , V_2 -> V_9 ) ;
V_4 -> V_10 = NULL ;
}
if ( V_4 -> V_11 ) {
F_3 ( V_4 -> V_11 , V_2 -> V_9 ,
sizeof( struct V_3 ) ) ;
V_4 -> V_11 = 0x0 ;
}
if ( V_4 -> V_12 ) {
F_3 ( V_4 -> V_12 , V_2 -> V_9 ,
V_13 ) ;
V_4 -> V_12 = 0 ;
}
}
void F_4 ( void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( V_4 ) {
F_5 ( & V_2 -> V_15 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( V_4 -> V_16 . V_7 ) ;
F_7 ( V_4 ) ;
}
}
void F_8 ( struct V_1 * V_2 , bool V_17 )
{
if ( ! V_17 )
F_5 ( & V_18 . V_19 ) ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_20 = V_21 ;
F_6 ( & V_2 -> V_15 ) ;
F_9 ( & V_2 -> V_22 , & V_18 . V_23 ) ;
V_18 . V_24 ++ ;
if ( ! V_17 )
F_6 ( & V_18 . V_19 ) ;
F_10 ( & V_18 . V_25 ) ;
}
static struct V_1 * F_11 ( T_1 V_26 )
{
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 , * V_29 ;
F_5 ( & V_18 . V_19 ) ;
F_12 (pos, tmpq, &scif_info.listen) {
V_2 = F_13 ( V_28 , struct V_1 , V_22 ) ;
if ( V_2 -> V_26 . V_26 == V_26 ) {
F_5 ( & V_2 -> V_15 ) ;
F_6 ( & V_18 . V_19 ) ;
return V_2 ;
}
}
F_6 ( & V_18 . V_19 ) ;
return NULL ;
}
void F_14 ( void )
{
struct V_27 * V_28 , * V_29 ;
struct V_1 * V_2 ;
F_5 ( & V_18 . V_19 ) ;
F_12 (pos, tmpq, &scif_info.zombie) {
V_2 = F_13 ( V_28 , struct V_1 , V_22 ) ;
F_15 ( V_28 ) ;
V_18 . V_24 -- ;
F_7 ( V_2 ) ;
}
F_6 ( & V_18 . V_19 ) ;
}
void F_16 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = NULL ;
struct V_34 * V_35 ;
V_35 = F_17 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
goto V_37;
V_2 = F_11 ( V_33 -> V_38 . V_26 ) ;
if ( ! V_2 )
goto V_39;
if ( V_2 -> V_40 <= V_2 -> V_41 ) {
F_6 ( & V_2 -> V_15 ) ;
goto V_39;
}
V_35 -> V_33 = * V_33 ;
F_9 ( & V_35 -> V_22 , & V_2 -> V_42 ) ;
V_2 -> V_41 ++ ;
F_18 ( & V_2 -> V_43 ) ;
F_6 ( & V_2 -> V_15 ) ;
return;
V_39:
F_7 ( V_35 ) ;
V_37:
V_33 -> V_44 = V_45 ;
F_19 ( & V_30 [ V_33 -> V_46 . V_47 ] , V_33 ) ;
}
void F_20 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
if ( V_49 == V_2 -> V_20 ) {
V_2 -> V_50 . V_47 = V_33 -> V_46 . V_47 ;
V_2 -> V_50 . V_26 = V_33 -> V_46 . V_26 ;
V_2 -> V_5 . V_51 = V_33 -> V_48 [ 1 ] ;
V_2 -> V_52 = V_33 -> V_48 [ 2 ] ;
V_2 -> V_20 = V_53 ;
F_21 ( & V_2 -> V_43 ) ;
}
F_6 ( & V_2 -> V_15 ) ;
}
void F_22 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_23 ( & V_18 . V_54 ) ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_20 = V_55 ;
F_9 ( & V_2 -> V_22 , & V_18 . V_56 ) ;
F_21 ( & V_2 -> V_43 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_24 ( & V_18 . V_54 ) ;
}
void F_25 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_20 = V_57 ;
F_21 ( & V_2 -> V_43 ) ;
F_6 ( & V_2 -> V_15 ) ;
}
void F_26 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
if ( V_49 == V_2 -> V_20 ) {
V_2 -> V_20 = V_58 ;
F_21 ( & V_2 -> V_43 ) ;
}
F_6 ( & V_2 -> V_15 ) ;
}
void F_27 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_59 ;
struct V_27 * V_28 , * V_29 ;
F_23 ( & V_18 . V_54 ) ;
F_12 (pos, tmpq, &scif_info.connected) {
V_59 = F_13 ( V_28 , struct V_1 , V_22 ) ;
if ( ( ( V_60 ) V_59 == V_33 -> V_48 [ 1 ] ) &&
( ( V_60 ) V_59 -> V_52 == V_33 -> V_48 [ 0 ] ) ) {
F_15 ( V_28 ) ;
V_2 = V_59 ;
F_5 ( & V_2 -> V_15 ) ;
break;
}
}
if ( ! V_2 ) {
F_24 ( & V_18 . V_54 ) ;
goto V_61;
}
V_2 -> V_20 = V_62 ;
F_9 ( & V_2 -> V_22 , & V_18 . V_63 ) ;
F_18 ( & V_2 -> V_64 ) ;
F_18 ( & V_2 -> V_65 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_24 ( & V_18 . V_54 ) ;
V_61:
V_33 -> V_44 = V_66 ;
F_19 ( & V_30 [ V_33 -> V_46 . V_47 ] , V_33 ) ;
}
void F_28 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_20 = V_62 ;
F_6 ( & V_2 -> V_15 ) ;
F_29 ( & V_2 -> V_67 ) ;
}
void F_30 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
if ( V_55 == V_2 -> V_20 )
F_18 ( & V_2 -> V_65 ) ;
F_6 ( & V_2 -> V_15 ) ;
}
void F_31 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 -> V_48 [ 0 ] ;
F_5 ( & V_2 -> V_15 ) ;
if ( V_55 == V_2 -> V_20 )
F_18 ( & V_2 -> V_64 ) ;
F_6 ( & V_2 -> V_15 ) ;
}
