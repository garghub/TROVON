T_1 F_1 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return F_2 ( V_5 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_4 ( V_8 , struct V_4 ,
V_9 ) ;
struct V_1 * V_2 = V_5 -> V_10 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_13 * V_14 ;
if ( V_12 -> V_15 ) {
F_5 (connector, &mode_config->connector_list, head)
F_6 ( V_14 ) ;
}
F_7 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned V_16 ;
V_5 -> V_17 . V_18 = false ;
V_5 -> V_17 . V_19 = false ;
for ( V_16 = 0 ; V_16 < V_5 -> V_20 ; V_16 ++ )
V_5 -> V_17 . V_21 [ V_16 ] = false ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_5 -> V_17 . V_22 [ V_16 ] = false ;
V_5 -> V_17 . V_23 [ V_16 ] = false ;
}
F_9 ( V_5 ) ;
F_2 ( V_5 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_2 -> V_24 = 0x001fffff ;
V_5 -> V_17 . V_18 = true ;
F_9 ( V_5 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned V_16 ;
if ( V_5 == NULL ) {
return;
}
V_5 -> V_17 . V_18 = false ;
V_5 -> V_17 . V_19 = false ;
for ( V_16 = 0 ; V_16 < V_5 -> V_20 ; V_16 ++ )
V_5 -> V_17 . V_21 [ V_16 ] = false ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_5 -> V_17 . V_22 [ V_16 ] = false ;
V_5 -> V_17 . V_23 [ V_16 ] = false ;
}
F_9 ( V_5 ) ;
}
int F_12 ( struct V_4 * V_5 )
{
int V_16 ;
int V_25 = 0 ;
F_13 ( & V_5 -> V_9 , F_3 ) ;
F_14 ( & V_5 -> V_17 . V_26 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_20 ; V_16 ++ )
F_14 ( & V_5 -> V_17 . V_27 [ V_16 ] ) ;
V_25 = F_15 ( V_5 -> V_10 , V_5 -> V_20 ) ;
if ( V_25 ) {
return V_25 ;
}
V_5 -> V_28 = 0 ;
if ( ( V_5 -> V_29 >= V_30 ) &&
( ( ! ( V_5 -> V_31 & V_32 ) ) || ( V_5 -> V_29 >= V_33 ) ) &&
( ! ( V_5 -> V_31 & V_34 ) ) ) {
int V_35 = F_16 ( V_5 -> V_36 ) ;
if ( ! V_35 ) {
V_5 -> V_28 = 1 ;
F_17 ( V_5 -> V_2 , L_1 ) ;
}
}
V_5 -> V_17 . V_37 = true ;
V_25 = F_18 ( V_5 -> V_10 ) ;
if ( V_25 ) {
V_5 -> V_17 . V_37 = false ;
return V_25 ;
}
F_19 ( L_2 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_5 )
{
F_21 ( V_5 -> V_10 ) ;
if ( V_5 -> V_17 . V_37 ) {
F_22 ( V_5 -> V_10 ) ;
V_5 -> V_17 . V_37 = false ;
if ( V_5 -> V_28 )
F_23 ( V_5 -> V_36 ) ;
}
F_24 ( & V_5 -> V_9 ) ;
}
void F_25 ( struct V_4 * V_5 )
{
unsigned long V_38 ;
F_26 ( & V_5 -> V_17 . V_26 , V_38 ) ;
if ( V_5 -> V_10 -> V_39 && ( ++ V_5 -> V_17 . V_40 == 1 ) ) {
V_5 -> V_17 . V_18 = true ;
F_9 ( V_5 ) ;
}
F_27 ( & V_5 -> V_17 . V_26 , V_38 ) ;
}
void F_28 ( struct V_4 * V_5 )
{
unsigned long V_38 ;
F_26 ( & V_5 -> V_17 . V_26 , V_38 ) ;
F_29 ( V_5 -> V_10 -> V_39 && V_5 -> V_17 . V_40 <= 0 ) ;
if ( V_5 -> V_10 -> V_39 && ( -- V_5 -> V_17 . V_40 == 0 ) ) {
V_5 -> V_17 . V_18 = false ;
F_9 ( V_5 ) ;
}
F_27 ( & V_5 -> V_17 . V_26 , V_38 ) ;
}
void F_30 ( struct V_4 * V_5 , int V_41 )
{
unsigned long V_38 ;
if ( V_41 < 0 || V_41 >= V_5 -> V_20 )
return;
F_26 ( & V_5 -> V_17 . V_27 [ V_41 ] , V_38 ) ;
if ( V_5 -> V_10 -> V_39 && ( ++ V_5 -> V_17 . V_42 [ V_41 ] == 1 ) ) {
V_5 -> V_17 . V_23 [ V_41 ] = true ;
F_9 ( V_5 ) ;
}
F_27 ( & V_5 -> V_17 . V_27 [ V_41 ] , V_38 ) ;
}
void F_31 ( struct V_4 * V_5 , int V_41 )
{
unsigned long V_38 ;
if ( V_41 < 0 || V_41 >= V_5 -> V_20 )
return;
F_26 ( & V_5 -> V_17 . V_27 [ V_41 ] , V_38 ) ;
F_29 ( V_5 -> V_10 -> V_39 && V_5 -> V_17 . V_42 [ V_41 ] <= 0 ) ;
if ( V_5 -> V_10 -> V_39 && ( -- V_5 -> V_17 . V_42 [ V_41 ] == 0 ) ) {
V_5 -> V_17 . V_23 [ V_41 ] = false ;
F_9 ( V_5 ) ;
}
F_27 ( & V_5 -> V_17 . V_27 [ V_41 ] , V_38 ) ;
}
