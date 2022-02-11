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
static void F_9 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_5 ( V_11 , struct V_5 ,
V_19 ) ;
struct V_3 * V_4 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 ;
if ( V_15 -> V_18 ) {
F_6 (connector, &mode_config->connector_list, head)
F_7 ( V_17 ) ;
}
}
void F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_20 ;
unsigned V_21 ;
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ )
F_12 ( & V_6 -> V_1 . V_24 [ V_21 ] , 0 ) ;
V_6 -> V_1 . V_25 = false ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ )
V_6 -> V_1 . V_27 [ V_21 ] = false ;
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ ) {
V_6 -> V_1 . V_29 [ V_21 ] = false ;
F_12 ( & V_6 -> V_1 . V_30 [ V_21 ] , 0 ) ;
V_6 -> V_1 . V_31 [ V_21 ] = false ;
}
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
F_2 ( V_6 ) ;
}
int F_15 ( struct V_3 * V_4 )
{
V_4 -> V_32 = 0x001fffff ;
return 0 ;
}
void F_16 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_20 ;
unsigned V_21 ;
if ( V_6 == NULL ) {
return;
}
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ )
F_12 ( & V_6 -> V_1 . V_24 [ V_21 ] , 0 ) ;
V_6 -> V_1 . V_25 = false ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ )
V_6 -> V_1 . V_27 [ V_21 ] = false ;
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ ) {
V_6 -> V_1 . V_29 [ V_21 ] = false ;
F_12 ( & V_6 -> V_1 . V_30 [ V_21 ] , 0 ) ;
V_6 -> V_1 . V_31 [ V_21 ] = false ;
}
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
static bool F_17 ( struct V_5 * V_6 )
{
if ( V_6 -> V_33 < V_34 )
return false ;
if ( V_6 -> V_35 & V_36 )
return false ;
if ( V_6 -> V_33 < V_37 ) {
F_18 ( V_6 -> V_4 , L_1 ) ;
V_6 -> V_38 -> V_39 = 1 ;
}
if ( V_40 == 1 )
return true ;
else if ( V_40 == 0 )
return false ;
if ( ( V_6 -> V_38 -> V_41 == 0x791f ) &&
( V_6 -> V_38 -> V_42 == 0x103c ) &&
( V_6 -> V_38 -> V_43 == 0x30c2 ) )
return true ;
if ( ( V_6 -> V_38 -> V_41 == 0x791f ) &&
( V_6 -> V_38 -> V_42 == 0x1028 ) &&
( V_6 -> V_38 -> V_43 == 0x01fc ) )
return true ;
if ( ( V_6 -> V_38 -> V_41 == 0x791f ) &&
( V_6 -> V_38 -> V_42 == 0x1028 ) &&
( V_6 -> V_38 -> V_43 == 0x01fd ) )
return true ;
if ( ( V_6 -> V_38 -> V_41 == 0x791f ) &&
( V_6 -> V_38 -> V_42 == 0x107b ) &&
( V_6 -> V_38 -> V_43 == 0x0185 ) )
return true ;
if ( V_6 -> V_33 == V_44 )
return true ;
if ( V_6 -> V_33 == V_45 )
return false ;
if ( V_6 -> V_35 & V_46 ) {
if ( V_6 -> V_33 >= V_47 )
return true ;
return false ;
}
return true ;
}
int F_19 ( struct V_5 * V_6 )
{
int V_48 = 0 ;
F_20 ( & V_6 -> V_1 . V_22 ) ;
V_48 = F_21 ( V_6 -> V_13 , V_6 -> V_49 ) ;
if ( V_48 ) {
return V_48 ;
}
V_6 -> V_50 = 0 ;
if ( F_17 ( V_6 ) ) {
int V_8 = F_22 ( V_6 -> V_38 ) ;
if ( ! V_8 ) {
V_6 -> V_50 = 1 ;
F_18 ( V_6 -> V_4 , L_2 ) ;
}
}
F_23 ( & V_6 -> V_12 , F_4 ) ;
F_23 ( & V_6 -> V_19 , F_9 ) ;
F_23 ( & V_6 -> V_51 , V_52 ) ;
V_6 -> V_1 . V_53 = true ;
V_48 = F_24 ( V_6 -> V_13 , V_6 -> V_13 -> V_38 -> V_1 ) ;
if ( V_48 ) {
V_6 -> V_1 . V_53 = false ;
F_25 ( & V_6 -> V_12 ) ;
return V_48 ;
}
F_26 ( L_3 ) ;
return 0 ;
}
void F_27 ( struct V_5 * V_6 )
{
F_28 ( V_6 -> V_13 ) ;
if ( V_6 -> V_1 . V_53 ) {
F_29 ( V_6 -> V_13 ) ;
V_6 -> V_1 . V_53 = false ;
if ( V_6 -> V_50 )
F_30 ( V_6 -> V_38 ) ;
F_25 ( & V_6 -> V_12 ) ;
}
}
void F_31 ( struct V_5 * V_6 , int V_54 )
{
unsigned long V_20 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
if ( F_32 ( & V_6 -> V_1 . V_24 [ V_54 ] ) == 1 ) {
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
}
bool F_33 ( struct V_5 * V_6 , int V_54 )
{
return F_32 ( & V_6 -> V_1 . V_24 [ V_54 ] ) == 1 ;
}
void F_34 ( struct V_5 * V_6 , int V_54 )
{
unsigned long V_20 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
if ( F_35 ( & V_6 -> V_1 . V_24 [ V_54 ] ) ) {
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
}
void F_36 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_20 ;
if ( V_56 < 0 || V_56 >= V_6 -> V_49 )
return;
if ( ! V_6 -> V_13 -> V_55 )
return;
if ( F_32 ( & V_6 -> V_1 . V_30 [ V_56 ] ) == 1 ) {
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
}
void F_37 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_20 ;
if ( V_56 < 0 || V_56 >= V_6 -> V_49 )
return;
if ( ! V_6 -> V_13 -> V_55 )
return;
if ( F_35 ( & V_6 -> V_1 . V_30 [ V_56 ] ) ) {
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
}
void F_38 ( struct V_5 * V_6 , int V_57 )
{
unsigned long V_20 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
V_6 -> V_1 . V_31 [ V_57 ] = true ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
void F_39 ( struct V_5 * V_6 , int V_57 )
{
unsigned long V_20 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
V_6 -> V_1 . V_31 [ V_57 ] = false ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
void F_40 ( struct V_5 * V_6 , unsigned V_58 )
{
unsigned long V_20 ;
int V_21 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_26 ; ++ V_21 )
V_6 -> V_1 . V_27 [ V_21 ] |= ! ! ( V_58 & ( 1 << V_21 ) ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
void F_41 ( struct V_5 * V_6 , unsigned V_58 )
{
unsigned long V_20 ;
int V_21 ;
if ( ! V_6 -> V_13 -> V_55 )
return;
F_11 ( & V_6 -> V_1 . V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_26 ; ++ V_21 )
V_6 -> V_1 . V_27 [ V_21 ] &= ! ( V_58 & ( 1 << V_21 ) ) ;
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_1 . V_22 , V_20 ) ;
}
