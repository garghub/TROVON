static struct V_1 * F_1 ( T_1 V_2 ,
struct V_1 * V_3 )
{
struct V_4 * * V_5 = & V_6 . V_4 ;
struct V_4 * V_7 = NULL ;
struct V_1 * V_8 ;
while ( * V_5 ) {
V_7 = * V_5 ;
V_8 = F_2 ( V_7 , struct V_1 , V_9 ) ;
if ( V_2 < V_8 -> V_10 )
V_5 = & ( * V_5 ) -> V_11 ;
else if ( V_2 > V_8 -> V_10 )
V_5 = & ( * V_5 ) -> V_12 ;
else
return V_8 ;
}
if ( V_3 ) {
F_3 ( & V_3 -> V_9 , V_7 , V_5 ) ;
F_4 ( & V_3 -> V_9 , & V_6 ) ;
}
return NULL ;
}
static struct V_1 * F_5 ( T_1 V_2 )
{
struct V_1 * V_8 ;
struct V_1 * V_13 = NULL ;
unsigned long V_14 ;
unsigned long V_15 ;
unsigned long V_16 ;
V_8 = F_6 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_10 = V_2 ;
F_7 ( & V_8 -> V_18 ) ;
F_8 ( & V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_14 = F_9 ( V_17 ) ;
if ( V_14 == 0 )
goto V_21;
V_8 -> V_22 [ V_15 ] = V_14 ;
}
F_10 ( & V_23 , V_16 ) ;
V_13 = F_1 ( V_2 , V_8 ) ;
F_11 ( & V_23 , V_16 ) ;
if ( ! V_13 ) {
V_13 = V_8 ;
V_8 = NULL ;
}
V_21:
if ( V_8 ) {
for ( V_15 = 0 ; V_15 < V_20 && V_8 -> V_22 [ V_15 ] ; V_15 ++ )
F_12 ( V_8 -> V_22 [ V_15 ] ) ;
F_13 ( V_8 ) ;
}
F_14 ( L_1 , V_13 , F_15 ( V_2 ) ) ;
return V_13 ;
}
void F_16 ( struct V_24 * V_25 )
{
unsigned long V_16 ;
F_14 ( L_2 , V_25 , V_25 -> V_26 ) ;
F_10 ( & V_23 , V_16 ) ;
F_17 ( & V_25 -> V_27 , & V_25 -> V_26 -> V_19 ) ;
F_11 ( & V_23 , V_16 ) ;
}
void F_18 ( struct V_24 * V_25 )
{
unsigned long V_16 ;
F_14 ( L_3 , V_25 , V_25 -> V_26 ) ;
F_10 ( & V_23 , V_16 ) ;
F_19 ( & V_25 -> V_27 ) ;
F_11 ( & V_23 , V_16 ) ;
}
int F_20 ( struct V_24 * V_25 )
{
V_25 -> V_26 = F_5 ( V_25 -> V_28 ) ;
V_25 -> V_29 = F_5 ( V_25 -> V_30 ) ;
if ( ! ( V_25 -> V_26 && V_25 -> V_29 ) )
return - V_31 ;
return 0 ;
}
void F_21 ( struct V_1 * V_8 )
{
struct V_24 * V_25 ;
unsigned long V_16 ;
F_10 ( & V_23 , V_16 ) ;
F_22 (conn, &map->m_conn_list, c_map_item) {
if ( ! F_23 ( 0 , & V_25 -> V_32 ) ) {
F_24 ( V_33 ) ;
F_25 ( V_25 ) ;
}
}
F_11 ( & V_23 , V_16 ) ;
}
void F_26 ( struct V_1 * V_8 , T_2 V_34 )
{
F_14 ( L_4 ,
V_8 , & V_8 -> V_10 ) ;
F_24 ( V_35 ) ;
F_27 ( & V_36 ) ;
if ( F_28 ( & V_8 -> V_18 ) )
F_29 ( & V_8 -> V_18 ) ;
if ( F_28 ( & V_37 ) )
F_30 ( & V_37 ) ;
if ( V_34 && ! F_31 ( & V_38 ) ) {
unsigned long V_16 ;
struct V_39 * V_40 ;
F_32 ( & V_41 , V_16 ) ;
F_22 (rs, &rds_cong_monitor, rs_cong_list) {
F_33 ( & V_40 -> V_42 ) ;
V_40 -> V_43 |= ( V_40 -> V_44 & V_34 ) ;
V_40 -> V_44 &= ~ V_34 ;
F_34 ( & V_40 -> V_42 ) ;
if ( V_40 -> V_43 )
F_35 ( V_40 ) ;
}
F_36 ( & V_41 , V_16 ) ;
}
}
int F_37 ( unsigned long * V_45 )
{
unsigned long V_46 = F_38 ( & V_36 ) ;
if ( F_39 ( * V_45 == V_46 ) )
return 0 ;
* V_45 = V_46 ;
return 1 ;
}
void F_40 ( struct V_1 * V_8 , T_3 V_47 )
{
unsigned long V_15 ;
unsigned long V_48 ;
F_14 ( L_5 ,
& V_8 -> V_10 , F_41 ( V_47 ) , V_8 ) ;
V_15 = F_42 ( V_47 ) / V_49 ;
V_48 = F_42 ( V_47 ) % V_49 ;
F_43 ( V_48 , ( void * ) V_8 -> V_22 [ V_15 ] ) ;
}
void F_44 ( struct V_1 * V_8 , T_3 V_47 )
{
unsigned long V_15 ;
unsigned long V_48 ;
F_14 ( L_6 ,
& V_8 -> V_10 , F_41 ( V_47 ) , V_8 ) ;
V_15 = F_42 ( V_47 ) / V_49 ;
V_48 = F_42 ( V_47 ) % V_49 ;
F_45 ( V_48 , ( void * ) V_8 -> V_22 [ V_15 ] ) ;
}
static int F_46 ( struct V_1 * V_8 , T_3 V_47 )
{
unsigned long V_15 ;
unsigned long V_48 ;
V_15 = F_42 ( V_47 ) / V_49 ;
V_48 = F_42 ( V_47 ) % V_49 ;
return F_47 ( V_48 , ( void * ) V_8 -> V_22 [ V_15 ] ) ;
}
void F_48 ( struct V_39 * V_40 )
{
unsigned long V_16 ;
F_49 ( & V_41 , V_16 ) ;
if ( F_31 ( & V_40 -> V_50 ) )
F_50 ( & V_40 -> V_50 , & V_38 ) ;
F_51 ( & V_41 , V_16 ) ;
}
void F_52 ( struct V_39 * V_40 )
{
unsigned long V_16 ;
struct V_1 * V_8 ;
F_49 ( & V_41 , V_16 ) ;
F_19 ( & V_40 -> V_50 ) ;
F_51 ( & V_41 , V_16 ) ;
F_10 ( & V_23 , V_16 ) ;
V_8 = F_1 ( V_40 -> V_51 , NULL ) ;
F_11 ( & V_23 , V_16 ) ;
if ( V_8 && F_46 ( V_8 , V_40 -> V_52 ) ) {
F_44 ( V_8 , V_40 -> V_52 ) ;
F_21 ( V_8 ) ;
}
}
int F_53 ( struct V_1 * V_8 , T_3 V_47 , int V_53 ,
struct V_39 * V_40 )
{
if ( ! F_46 ( V_8 , V_47 ) )
return 0 ;
if ( V_53 ) {
if ( V_40 && V_40 -> V_54 ) {
unsigned long V_16 ;
F_10 ( & V_40 -> V_42 , V_16 ) ;
V_40 -> V_44 |= F_54 ( F_41 ( V_47 ) ) ;
F_11 ( & V_40 -> V_42 , V_16 ) ;
if ( ! F_46 ( V_8 , V_47 ) )
return 0 ;
}
F_24 ( V_55 ) ;
return - V_56 ;
}
F_24 ( V_57 ) ;
F_14 ( L_7 , V_8 , F_42 ( V_47 ) ) ;
return F_55 ( V_8 -> V_18 ,
! F_46 ( V_8 , V_47 ) ) ;
}
void F_56 ( void )
{
struct V_4 * V_58 ;
struct V_1 * V_8 ;
unsigned long V_15 ;
while ( ( V_58 = F_57 ( & V_6 ) ) ) {
V_8 = F_2 ( V_58 , struct V_1 , V_9 ) ;
F_14 ( L_8 , V_8 ) ;
F_58 ( & V_8 -> V_9 , & V_6 ) ;
for ( V_15 = 0 ; V_15 < V_20 && V_8 -> V_22 [ V_15 ] ; V_15 ++ )
F_12 ( V_8 -> V_22 [ V_15 ] ) ;
F_13 ( V_8 ) ;
}
}
struct V_59 * F_59 ( struct V_24 * V_25 )
{
struct V_1 * V_8 = V_25 -> V_26 ;
struct V_59 * V_60 ;
V_60 = F_60 ( V_8 -> V_22 , V_61 ) ;
if ( ! F_61 ( V_60 ) )
V_60 -> V_62 . V_63 . V_64 = V_65 ;
return V_60 ;
}
