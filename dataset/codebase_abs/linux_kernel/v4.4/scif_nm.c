static void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 , * V_6 ;
F_2 ( & V_7 . V_8 ) ;
F_3 ( & V_7 . V_9 ) ;
F_4 (pos, tmpq, &scif_info.disconnected) {
V_3 = F_5 ( V_5 , struct V_2 , V_10 ) ;
if ( V_3 -> V_11 -> V_1 == V_1 ) {
F_6 ( V_3 ) ;
F_7 ( & V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_9 ( & V_3 -> V_12 ) ;
}
}
F_4 (pos, tmpq, &scif_info.connected) {
V_3 = F_5 ( V_5 , struct V_2 , V_10 ) ;
if ( V_3 -> V_11 -> V_1 == V_1 ) {
F_10 ( V_5 ) ;
F_7 ( & V_3 -> V_12 ) ;
V_3 -> V_13 = V_14 ;
F_11 ( & V_3 -> V_10 , & V_7 . V_15 ) ;
F_8 ( V_3 ) ;
F_12 ( & V_3 -> V_16 ) ;
F_12 ( & V_3 -> V_17 ) ;
F_9 ( & V_3 -> V_12 ) ;
F_6 ( V_3 ) ;
}
}
F_13 ( & V_7 . V_9 ) ;
}
void F_14 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
if ( ! V_21 )
return;
F_15 ( V_21 -> V_23 , V_19 , V_21 -> V_24 . V_25 ) ;
F_16 ( V_21 -> V_24 . V_26 ) ;
F_15 ( V_21 -> V_27 , V_19 , sizeof( struct V_20 ) ) ;
F_16 ( V_19 -> V_22 ) ;
V_19 -> V_22 = NULL ;
}
static void F_17 ( struct V_18 * V_28 )
{
struct V_20 * V_21 = & V_28 -> V_22 [ 0 ] ;
if ( ! V_21 )
return;
F_18 ( ( void * ) V_21 -> V_29 , sizeof( struct V_20 ) , V_28 ) ;
F_18 ( ( void * ) V_21 -> V_30 . V_26 ,
sizeof( struct V_20 ) , V_28 ) ;
V_21 -> V_29 = NULL ;
V_21 -> V_31 = 0 ;
V_21 -> V_24 . V_32 = 0 ;
V_21 -> V_24 . V_33 = 0 ;
if ( F_19 ( V_28 ) )
F_14 ( V_28 ) ;
}
void F_20 ( struct V_18 * V_28 )
{
struct V_34 V_35 ;
if ( V_28 -> V_36 ) {
V_35 . V_37 = V_38 ;
V_35 . V_39 . V_1 = V_7 . V_40 ;
V_35 . V_41 . V_1 = V_42 ;
V_35 . V_43 [ 0 ] = V_28 -> V_1 ;
F_21 ( & V_18 [ V_42 ] , & V_35 ) ;
V_28 -> V_36 = false ;
}
if ( V_28 -> V_44 ) {
V_35 . V_37 = V_45 ;
V_35 . V_39 . V_1 = V_7 . V_40 ;
V_35 . V_41 . V_1 = V_28 -> V_1 ;
F_21 ( V_28 , & V_35 ) ;
V_28 -> V_44 = false ;
}
}
void F_22 ( struct V_18 * V_28 )
{
struct V_46 * V_47 = V_28 -> V_47 ;
if ( ! V_28 -> V_47 )
return;
if ( F_19 ( V_28 ) ) {
if ( V_28 -> V_48 ) {
V_47 -> V_49 -> V_50 ( V_47 , V_28 -> V_48 , V_28 ) ;
V_28 -> V_48 = NULL ;
}
F_23 ( V_28 ) ;
}
F_2 ( & V_7 . V_51 ) ;
F_24 ( V_28 ) ;
F_1 ( V_28 -> V_1 ) ;
F_25 ( V_28 -> V_1 ) ;
F_26 ( V_28 -> V_1 ) ;
F_2 ( & V_7 . V_51 ) ;
F_20 ( V_28 ) ;
if ( ! V_28 -> V_1 && V_7 . V_52 ) {
F_27 ( V_28 ) ;
V_7 . V_52 = false ;
}
F_17 ( V_28 ) ;
}
void F_28 ( int V_1 )
{
struct V_18 * V_19 = & V_18 [ V_1 ] ;
if ( F_29 ( V_19 ) )
F_20 ( V_19 ) ;
}
static int F_30 ( int V_1 , int V_53 )
{
struct V_34 V_54 ;
struct V_18 * V_28 = & V_18 [ V_1 ] ;
V_54 . V_37 = V_55 ;
V_54 . V_39 . V_1 = V_7 . V_40 ;
V_54 . V_41 . V_1 = V_1 ;
V_54 . V_43 [ 0 ] = V_53 ;
return F_21 ( V_28 , & V_54 ) ;
}
void F_31 ( T_1 V_56 , bool V_57 )
{
int V_58 ;
int V_59 = 0 ;
T_1 V_60 = 0 ;
struct V_18 * V_19 = & V_18 [ V_56 ] ;
if ( ! V_56 )
return;
F_32 ( & V_19 -> V_61 , 0 ) ;
for ( V_60 = 1 ; V_60 <= V_7 . V_62 ; V_60 ++ ) {
if ( V_60 == V_56 )
continue;
V_58 = F_30 ( V_60 , V_56 ) ;
if ( ! V_58 )
V_59 ++ ;
}
V_58 = F_33 ( V_19 -> V_63 ,
( F_34 ( & V_19 -> V_61 )
== V_59 ) , V_64 ) ;
if ( V_57 && F_35 ( V_19 ) )
F_27 ( V_19 ) ;
F_32 ( & V_19 -> V_61 , 0 ) ;
V_58 = F_30 ( V_42 , V_56 ) ;
if ( ! V_58 )
F_33 ( V_19 -> V_63 ,
( F_34 ( & V_19 -> V_61 ) == 1 ) ,
V_64 ) ;
}
void F_36 ( void )
{
struct V_34 V_35 ;
F_37 ( V_65 ) ;
V_35 . V_37 = V_66 ;
V_35 . V_39 . V_1 = V_7 . V_40 ;
V_35 . V_41 . V_1 = V_42 ;
V_35 . V_43 [ 3 ] = ( V_67 ) & V_65 ;
if ( ( F_21 ( & V_18 [ V_42 ] , & V_35 ) ) )
return;
F_38 ( & V_65 ) ;
}
