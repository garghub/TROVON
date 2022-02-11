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
if ( ! V_6 -> V_18 . V_19 )
return;
F_6 ( & V_15 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_7 (connector, &mode_config->connector_list, head)
F_8 ( V_17 ) ;
}
F_9 ( & V_15 -> V_20 ) ;
F_10 ( V_4 ) ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_5 ( V_11 , struct V_5 ,
V_22 ) ;
struct V_3 * V_4 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 ;
if ( V_15 -> V_21 ) {
F_7 (connector, &mode_config->connector_list, head)
F_8 ( V_17 ) ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_23 ;
unsigned V_24 ;
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
F_14 ( & V_6 -> V_1 . V_27 [ V_24 ] , 0 ) ;
V_6 -> V_1 . V_28 = false ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ )
V_6 -> V_1 . V_30 [ V_24 ] = false ;
for ( V_24 = 0 ; V_24 < V_31 ; V_24 ++ ) {
V_6 -> V_1 . V_32 [ V_24 ] = false ;
F_14 ( & V_6 -> V_1 . V_33 [ V_24 ] , 0 ) ;
V_6 -> V_1 . V_34 [ V_24 ] = false ;
}
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
F_2 ( V_6 ) ;
}
int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_18 ( V_6 ) )
V_4 -> V_35 = 0x00ffffff ;
else
V_4 -> V_35 = 0x001fffff ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_23 ;
unsigned V_24 ;
if ( V_6 == NULL ) {
return;
}
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
F_14 ( & V_6 -> V_1 . V_27 [ V_24 ] , 0 ) ;
V_6 -> V_1 . V_28 = false ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ )
V_6 -> V_1 . V_30 [ V_24 ] = false ;
for ( V_24 = 0 ; V_24 < V_31 ; V_24 ++ ) {
V_6 -> V_1 . V_32 [ V_24 ] = false ;
F_14 ( & V_6 -> V_1 . V_33 [ V_24 ] , 0 ) ;
V_6 -> V_1 . V_34 [ V_24 ] = false ;
}
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
static bool F_20 ( struct V_5 * V_6 )
{
if ( V_6 -> V_36 < V_37 )
return false ;
if ( V_6 -> V_38 & V_39 )
return false ;
if ( V_6 -> V_36 < V_40 ) {
F_21 ( V_6 -> V_4 , L_1 ) ;
V_6 -> V_41 -> V_42 = 1 ;
}
if ( V_43 == 1 )
return true ;
else if ( V_43 == 0 )
return false ;
if ( ( V_6 -> V_41 -> V_44 == 0x791f ) &&
( V_6 -> V_41 -> V_45 == 0x103c ) &&
( V_6 -> V_41 -> V_46 == 0x30c2 ) )
return true ;
if ( ( V_6 -> V_41 -> V_44 == 0x791f ) &&
( V_6 -> V_41 -> V_45 == 0x1028 ) &&
( V_6 -> V_41 -> V_46 == 0x01fc ) )
return true ;
if ( ( V_6 -> V_41 -> V_44 == 0x791f ) &&
( V_6 -> V_41 -> V_45 == 0x1028 ) &&
( V_6 -> V_41 -> V_46 == 0x01fd ) )
return true ;
if ( ( V_6 -> V_41 -> V_44 == 0x791f ) &&
( V_6 -> V_41 -> V_45 == 0x107b ) &&
( V_6 -> V_41 -> V_46 == 0x0185 ) )
return true ;
if ( V_6 -> V_36 == V_47 )
return true ;
if ( V_6 -> V_36 == V_48 )
return false ;
if ( V_6 -> V_38 & V_49 ) {
if ( V_6 -> V_36 >= V_50 )
return true ;
return false ;
}
return true ;
}
int F_22 ( struct V_5 * V_6 )
{
int V_51 = 0 ;
F_23 ( & V_6 -> V_1 . V_25 ) ;
V_51 = F_24 ( V_6 -> V_13 , V_6 -> V_52 ) ;
if ( V_51 ) {
return V_51 ;
}
V_6 -> V_53 = 0 ;
if ( F_20 ( V_6 ) ) {
int V_8 = F_25 ( V_6 -> V_41 ) ;
if ( ! V_8 ) {
V_6 -> V_53 = 1 ;
F_21 ( V_6 -> V_4 , L_2 ) ;
}
}
F_26 ( & V_6 -> V_12 , F_4 ) ;
F_26 ( & V_6 -> V_22 , F_11 ) ;
F_26 ( & V_6 -> V_54 , V_55 ) ;
V_6 -> V_1 . V_56 = true ;
V_51 = F_27 ( V_6 -> V_13 , V_6 -> V_13 -> V_41 -> V_1 ) ;
if ( V_51 ) {
V_6 -> V_1 . V_56 = false ;
F_28 ( & V_6 -> V_12 ) ;
return V_51 ;
}
F_29 ( L_3 ) ;
return 0 ;
}
void F_30 ( struct V_5 * V_6 )
{
F_31 ( V_6 -> V_13 ) ;
if ( V_6 -> V_1 . V_56 ) {
F_32 ( V_6 -> V_13 ) ;
V_6 -> V_1 . V_56 = false ;
if ( V_6 -> V_53 )
F_33 ( V_6 -> V_41 ) ;
F_28 ( & V_6 -> V_12 ) ;
}
}
void F_34 ( struct V_5 * V_6 , int V_57 )
{
unsigned long V_23 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
if ( F_35 ( & V_6 -> V_1 . V_27 [ V_57 ] ) == 1 ) {
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
}
bool F_36 ( struct V_5 * V_6 , int V_57 )
{
return F_35 ( & V_6 -> V_1 . V_27 [ V_57 ] ) == 1 ;
}
void F_37 ( struct V_5 * V_6 , int V_57 )
{
unsigned long V_23 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
if ( F_38 ( & V_6 -> V_1 . V_27 [ V_57 ] ) ) {
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
}
void F_39 ( struct V_5 * V_6 , int V_59 )
{
unsigned long V_23 ;
if ( V_59 < 0 || V_59 >= V_6 -> V_52 )
return;
if ( ! V_6 -> V_13 -> V_58 )
return;
if ( F_35 ( & V_6 -> V_1 . V_33 [ V_59 ] ) == 1 ) {
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
}
void F_40 ( struct V_5 * V_6 , int V_59 )
{
unsigned long V_23 ;
if ( V_59 < 0 || V_59 >= V_6 -> V_52 )
return;
if ( ! V_6 -> V_13 -> V_58 )
return;
if ( F_38 ( & V_6 -> V_1 . V_33 [ V_59 ] ) ) {
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
}
void F_41 ( struct V_5 * V_6 , int V_60 )
{
unsigned long V_23 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
V_6 -> V_1 . V_34 [ V_60 ] = true ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
void F_42 ( struct V_5 * V_6 , int V_60 )
{
unsigned long V_23 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
V_6 -> V_1 . V_34 [ V_60 ] = false ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
void F_43 ( struct V_5 * V_6 , unsigned V_61 )
{
unsigned long V_23 ;
int V_24 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
for ( V_24 = 0 ; V_24 < V_29 ; ++ V_24 )
V_6 -> V_1 . V_30 [ V_24 ] |= ! ! ( V_61 & ( 1 << V_24 ) ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
void F_44 ( struct V_5 * V_6 , unsigned V_61 )
{
unsigned long V_23 ;
int V_24 ;
if ( ! V_6 -> V_13 -> V_58 )
return;
F_13 ( & V_6 -> V_1 . V_25 , V_23 ) ;
for ( V_24 = 0 ; V_24 < V_29 ; ++ V_24 )
V_6 -> V_1 . V_30 [ V_24 ] &= ! ( V_61 & ( 1 << V_24 ) ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_25 , V_23 ) ;
}
