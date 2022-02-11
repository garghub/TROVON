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
unsigned long V_16 ;
unsigned V_17 ;
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
F_10 ( & V_5 -> V_18 . V_21 [ V_17 ] , 0 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ )
V_5 -> V_18 . V_23 [ V_17 ] = false ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_5 -> V_18 . V_25 [ V_17 ] = false ;
F_10 ( & V_5 -> V_18 . V_26 [ V_17 ] , 0 ) ;
V_5 -> V_18 . V_27 [ V_17 ] = false ;
}
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
F_2 ( V_5 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0x001fffff ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_16 ;
unsigned V_17 ;
if ( V_5 == NULL ) {
return;
}
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
F_10 ( & V_5 -> V_18 . V_21 [ V_17 ] , 0 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ )
V_5 -> V_18 . V_23 [ V_17 ] = false ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_5 -> V_18 . V_25 [ V_17 ] = false ;
F_10 ( & V_5 -> V_18 . V_26 [ V_17 ] , 0 ) ;
V_5 -> V_18 . V_27 [ V_17 ] = false ;
}
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
static bool F_15 ( struct V_4 * V_5 )
{
if ( V_5 -> V_29 < V_30 )
return false ;
if ( V_5 -> V_31 & V_32 )
return false ;
if ( V_33 == 1 )
return true ;
else if ( V_33 == 0 )
return false ;
if ( ( V_5 -> V_34 -> V_35 == 0x791f ) &&
( V_5 -> V_34 -> V_36 == 0x103c ) &&
( V_5 -> V_34 -> V_37 == 0x30c2 ) )
return true ;
if ( ( V_5 -> V_34 -> V_35 == 0x791f ) &&
( V_5 -> V_34 -> V_36 == 0x1028 ) &&
( V_5 -> V_34 -> V_37 == 0x01fc ) )
return true ;
if ( ( V_5 -> V_34 -> V_35 == 0x791f ) &&
( V_5 -> V_34 -> V_36 == 0x1028 ) &&
( V_5 -> V_34 -> V_37 == 0x01fd ) )
return true ;
if ( ( V_5 -> V_34 -> V_35 == 0x791f ) &&
( V_5 -> V_34 -> V_36 == 0x107b ) &&
( V_5 -> V_34 -> V_37 == 0x0185 ) )
return true ;
if ( V_5 -> V_29 == V_38 )
return true ;
if ( V_5 -> V_29 == V_39 )
return false ;
if ( V_5 -> V_31 & V_40 ) {
if ( V_5 -> V_29 >= V_41 )
return true ;
return false ;
}
return true ;
}
int F_16 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
F_17 ( & V_5 -> V_9 , F_3 ) ;
F_17 ( & V_5 -> V_43 , V_44 ) ;
F_18 ( & V_5 -> V_18 . V_19 ) ;
V_42 = F_19 ( V_5 -> V_10 , V_5 -> V_45 ) ;
if ( V_42 ) {
return V_42 ;
}
V_5 -> V_46 = 0 ;
if ( F_15 ( V_5 ) ) {
int V_47 = F_20 ( V_5 -> V_34 ) ;
if ( ! V_47 ) {
V_5 -> V_46 = 1 ;
F_21 ( V_5 -> V_2 , L_1 ) ;
}
}
V_5 -> V_18 . V_48 = true ;
V_42 = F_22 ( V_5 -> V_10 ) ;
if ( V_42 ) {
V_5 -> V_18 . V_48 = false ;
return V_42 ;
}
F_23 ( L_2 ) ;
return 0 ;
}
void F_24 ( struct V_4 * V_5 )
{
F_25 ( V_5 -> V_10 ) ;
if ( V_5 -> V_18 . V_48 ) {
F_26 ( V_5 -> V_10 ) ;
V_5 -> V_18 . V_48 = false ;
if ( V_5 -> V_46 )
F_27 ( V_5 -> V_34 ) ;
}
F_28 ( & V_5 -> V_9 ) ;
}
void F_29 ( struct V_4 * V_5 , int V_49 )
{
unsigned long V_16 ;
if ( ! V_5 -> V_10 -> V_50 )
return;
if ( F_30 ( & V_5 -> V_18 . V_21 [ V_49 ] ) == 1 ) {
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
}
void F_31 ( struct V_4 * V_5 , int V_49 )
{
unsigned long V_16 ;
if ( ! V_5 -> V_10 -> V_50 )
return;
if ( F_32 ( & V_5 -> V_18 . V_21 [ V_49 ] ) ) {
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
}
void F_33 ( struct V_4 * V_5 , int V_51 )
{
unsigned long V_16 ;
if ( V_51 < 0 || V_51 >= V_5 -> V_45 )
return;
if ( ! V_5 -> V_10 -> V_50 )
return;
if ( F_30 ( & V_5 -> V_18 . V_26 [ V_51 ] ) == 1 ) {
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
}
void F_34 ( struct V_4 * V_5 , int V_51 )
{
unsigned long V_16 ;
if ( V_51 < 0 || V_51 >= V_5 -> V_45 )
return;
if ( ! V_5 -> V_10 -> V_50 )
return;
if ( F_32 ( & V_5 -> V_18 . V_26 [ V_51 ] ) ) {
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
}
void F_35 ( struct V_4 * V_5 , int V_52 )
{
unsigned long V_16 ;
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
V_5 -> V_18 . V_27 [ V_52 ] = true ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
void F_36 ( struct V_4 * V_5 , int V_52 )
{
unsigned long V_16 ;
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
V_5 -> V_18 . V_27 [ V_52 ] = false ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
void F_37 ( struct V_4 * V_5 , unsigned V_53 )
{
unsigned long V_16 ;
int V_17 ;
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; ++ V_17 )
V_5 -> V_18 . V_23 [ V_17 ] |= ! ! ( V_53 & ( 1 << V_17 ) ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
void F_38 ( struct V_4 * V_5 , unsigned V_53 )
{
unsigned long V_16 ;
int V_17 ;
F_9 ( & V_5 -> V_18 . V_19 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; ++ V_17 )
V_5 -> V_18 . V_23 [ V_17 ] &= ! ( V_53 & ( 1 << V_17 ) ) ;
F_11 ( V_5 ) ;
F_12 ( & V_5 -> V_18 . V_19 , V_16 ) ;
}
