T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
V_8 = F_2 ( V_6 ) ;
if ( V_8 == V_9 )
F_3 ( V_4 -> V_4 ) ;
return V_8 ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_5 ( V_11 , struct V_5 ,
V_12 ) ;
struct V_3 * V_4 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 ;
if ( V_15 -> V_18 ) {
F_6 (connector, &mode_config->connector_list, head)
F_7 ( V_17 ) ;
}
F_8 ( V_4 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_19 ;
unsigned V_20 ;
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
F_11 ( & V_6 -> V_1 . V_23 [ V_20 ] , 0 ) ;
V_6 -> V_1 . V_24 = false ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_6 -> V_1 . V_26 [ V_20 ] = false ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_6 -> V_1 . V_28 [ V_20 ] = false ;
F_11 ( & V_6 -> V_1 . V_29 [ V_20 ] , 0 ) ;
V_6 -> V_1 . V_30 [ V_20 ] = false ;
}
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
F_2 ( V_6 ) ;
}
int F_14 ( struct V_3 * V_4 )
{
V_4 -> V_31 = 0x001fffff ;
return 0 ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_19 ;
unsigned V_20 ;
if ( V_6 == NULL ) {
return;
}
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
F_11 ( & V_6 -> V_1 . V_23 [ V_20 ] , 0 ) ;
V_6 -> V_1 . V_24 = false ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_6 -> V_1 . V_26 [ V_20 ] = false ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_6 -> V_1 . V_28 [ V_20 ] = false ;
F_11 ( & V_6 -> V_1 . V_29 [ V_20 ] , 0 ) ;
V_6 -> V_1 . V_30 [ V_20 ] = false ;
}
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
static bool F_16 ( struct V_5 * V_6 )
{
if ( V_6 -> V_32 < V_33 )
return false ;
if ( V_6 -> V_34 & V_35 )
return false ;
if ( V_6 -> V_32 < V_36 ) {
F_17 ( V_6 -> V_4 , L_1 ) ;
V_6 -> V_37 -> V_38 = 1 ;
}
if ( V_39 == 1 )
return true ;
else if ( V_39 == 0 )
return false ;
if ( ( V_6 -> V_37 -> V_40 == 0x791f ) &&
( V_6 -> V_37 -> V_41 == 0x103c ) &&
( V_6 -> V_37 -> V_42 == 0x30c2 ) )
return true ;
if ( ( V_6 -> V_37 -> V_40 == 0x791f ) &&
( V_6 -> V_37 -> V_41 == 0x1028 ) &&
( V_6 -> V_37 -> V_42 == 0x01fc ) )
return true ;
if ( ( V_6 -> V_37 -> V_40 == 0x791f ) &&
( V_6 -> V_37 -> V_41 == 0x1028 ) &&
( V_6 -> V_37 -> V_42 == 0x01fd ) )
return true ;
if ( ( V_6 -> V_37 -> V_40 == 0x791f ) &&
( V_6 -> V_37 -> V_41 == 0x107b ) &&
( V_6 -> V_37 -> V_42 == 0x0185 ) )
return true ;
if ( V_6 -> V_32 == V_43 )
return true ;
if ( V_6 -> V_32 == V_44 )
return false ;
if ( V_6 -> V_34 & V_45 ) {
if ( V_6 -> V_32 >= V_46 )
return true ;
return false ;
}
return true ;
}
int F_18 ( struct V_5 * V_6 )
{
int V_47 = 0 ;
F_19 ( & V_6 -> V_1 . V_21 ) ;
V_47 = F_20 ( V_6 -> V_13 , V_6 -> V_48 ) ;
if ( V_47 ) {
return V_47 ;
}
V_6 -> V_49 = 0 ;
if ( F_16 ( V_6 ) ) {
int V_8 = F_21 ( V_6 -> V_37 ) ;
if ( ! V_8 ) {
V_6 -> V_49 = 1 ;
F_17 ( V_6 -> V_4 , L_2 ) ;
}
}
F_22 ( & V_6 -> V_12 , F_4 ) ;
F_22 ( & V_6 -> V_50 , V_51 ) ;
V_6 -> V_1 . V_52 = true ;
V_47 = F_23 ( V_6 -> V_13 , V_6 -> V_13 -> V_37 -> V_1 ) ;
if ( V_47 ) {
V_6 -> V_1 . V_52 = false ;
F_24 ( & V_6 -> V_12 ) ;
return V_47 ;
}
F_25 ( L_3 ) ;
return 0 ;
}
void F_26 ( struct V_5 * V_6 )
{
F_27 ( V_6 -> V_13 ) ;
if ( V_6 -> V_1 . V_52 ) {
F_28 ( V_6 -> V_13 ) ;
V_6 -> V_1 . V_52 = false ;
if ( V_6 -> V_49 )
F_29 ( V_6 -> V_37 ) ;
F_24 ( & V_6 -> V_12 ) ;
}
}
void F_30 ( struct V_5 * V_6 , int V_53 )
{
unsigned long V_19 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
if ( F_31 ( & V_6 -> V_1 . V_23 [ V_53 ] ) == 1 ) {
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
}
bool F_32 ( struct V_5 * V_6 , int V_53 )
{
return F_31 ( & V_6 -> V_1 . V_23 [ V_53 ] ) == 1 ;
}
void F_33 ( struct V_5 * V_6 , int V_53 )
{
unsigned long V_19 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
if ( F_34 ( & V_6 -> V_1 . V_23 [ V_53 ] ) ) {
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
}
void F_35 ( struct V_5 * V_6 , int V_55 )
{
unsigned long V_19 ;
if ( V_55 < 0 || V_55 >= V_6 -> V_48 )
return;
if ( ! V_6 -> V_13 -> V_54 )
return;
if ( F_31 ( & V_6 -> V_1 . V_29 [ V_55 ] ) == 1 ) {
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
}
void F_36 ( struct V_5 * V_6 , int V_55 )
{
unsigned long V_19 ;
if ( V_55 < 0 || V_55 >= V_6 -> V_48 )
return;
if ( ! V_6 -> V_13 -> V_54 )
return;
if ( F_34 ( & V_6 -> V_1 . V_29 [ V_55 ] ) ) {
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
}
void F_37 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_19 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
V_6 -> V_1 . V_30 [ V_56 ] = true ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
void F_38 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_19 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
V_6 -> V_1 . V_30 [ V_56 ] = false ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
void F_39 ( struct V_5 * V_6 , unsigned V_57 )
{
unsigned long V_19 ;
int V_20 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; ++ V_20 )
V_6 -> V_1 . V_26 [ V_20 ] |= ! ! ( V_57 & ( 1 << V_20 ) ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
void F_40 ( struct V_5 * V_6 , unsigned V_57 )
{
unsigned long V_19 ;
int V_20 ;
if ( ! V_6 -> V_13 -> V_54 )
return;
F_10 ( & V_6 -> V_1 . V_21 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; ++ V_20 )
V_6 -> V_1 . V_26 [ V_20 ] &= ! ( V_57 & ( 1 << V_20 ) ) ;
F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_1 . V_21 , V_19 ) ;
}
