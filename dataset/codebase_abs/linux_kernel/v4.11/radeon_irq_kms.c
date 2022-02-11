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
V_12 . V_11 ) ;
struct V_3 * V_4 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 ;
if ( ! V_6 -> V_18 . V_19 )
return;
F_6 ( & V_15 -> V_20 ) ;
F_7 (connector, &mode_config->connector_list, head)
F_8 ( V_17 ) ;
F_9 ( & V_15 -> V_20 ) ;
F_10 ( V_4 ) ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_5 ( V_11 , struct V_5 ,
V_21 ) ;
struct V_3 * V_4 = V_6 -> V_13 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 ;
F_7 (connector, &mode_config->connector_list, head)
F_8 ( V_17 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_22 ;
unsigned V_23 ;
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ )
F_14 ( & V_6 -> V_1 . V_26 [ V_23 ] , 0 ) ;
V_6 -> V_1 . V_27 = false ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ )
V_6 -> V_1 . V_29 [ V_23 ] = false ;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ ) {
V_6 -> V_1 . V_31 [ V_23 ] = false ;
F_14 ( & V_6 -> V_1 . V_32 [ V_23 ] , 0 ) ;
V_6 -> V_1 . V_33 [ V_23 ] = false ;
}
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
F_2 ( V_6 ) ;
}
int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_18 ( V_6 ) )
V_4 -> V_34 = 0x00ffffff ;
else
V_4 -> V_34 = 0x001fffff ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_22 ;
unsigned V_23 ;
if ( V_6 == NULL ) {
return;
}
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ )
F_14 ( & V_6 -> V_1 . V_26 [ V_23 ] , 0 ) ;
V_6 -> V_1 . V_27 = false ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ )
V_6 -> V_1 . V_29 [ V_23 ] = false ;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ ) {
V_6 -> V_1 . V_31 [ V_23 ] = false ;
F_14 ( & V_6 -> V_1 . V_32 [ V_23 ] , 0 ) ;
V_6 -> V_1 . V_33 [ V_23 ] = false ;
}
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
static bool F_20 ( struct V_5 * V_6 )
{
if ( V_6 -> V_35 < V_36 )
return false ;
if ( V_6 -> V_37 & V_38 )
return false ;
if ( V_6 -> V_35 < V_39 ) {
F_21 ( V_6 -> V_4 , L_1 ) ;
V_6 -> V_40 -> V_41 = 1 ;
}
if ( V_42 == 1 )
return true ;
else if ( V_42 == 0 )
return false ;
if ( ( V_6 -> V_40 -> V_43 == 0x791f ) &&
( V_6 -> V_40 -> V_44 == 0x103c ) &&
( V_6 -> V_40 -> V_45 == 0x30c2 ) )
return true ;
if ( ( V_6 -> V_40 -> V_43 == 0x791f ) &&
( V_6 -> V_40 -> V_44 == 0x1028 ) &&
( V_6 -> V_40 -> V_45 == 0x01fc ) )
return true ;
if ( ( V_6 -> V_40 -> V_43 == 0x791f ) &&
( V_6 -> V_40 -> V_44 == 0x1028 ) &&
( V_6 -> V_40 -> V_45 == 0x01fd ) )
return true ;
if ( ( V_6 -> V_40 -> V_43 == 0x791f ) &&
( V_6 -> V_40 -> V_44 == 0x107b ) &&
( V_6 -> V_40 -> V_45 == 0x0185 ) )
return true ;
if ( V_6 -> V_35 == V_46 )
return true ;
if ( V_6 -> V_35 == V_47 )
return false ;
if ( V_6 -> V_37 & V_48 ) {
if ( V_6 -> V_35 >= V_49 )
return true ;
return false ;
}
return true ;
}
int F_22 ( struct V_5 * V_6 )
{
int V_50 = 0 ;
F_23 ( & V_6 -> V_1 . V_24 ) ;
V_50 = F_24 ( V_6 -> V_13 , V_6 -> V_51 ) ;
if ( V_50 ) {
return V_50 ;
}
V_6 -> V_52 = 0 ;
if ( F_20 ( V_6 ) ) {
int V_8 = F_25 ( V_6 -> V_40 ) ;
if ( ! V_8 ) {
V_6 -> V_52 = 1 ;
F_21 ( V_6 -> V_4 , L_2 ) ;
}
}
F_26 ( & V_6 -> V_12 , F_4 ) ;
F_27 ( & V_6 -> V_21 , F_11 ) ;
F_27 ( & V_6 -> V_53 , V_54 ) ;
V_6 -> V_1 . V_55 = true ;
V_50 = F_28 ( V_6 -> V_13 , V_6 -> V_13 -> V_40 -> V_1 ) ;
if ( V_50 ) {
V_6 -> V_1 . V_55 = false ;
F_29 ( & V_6 -> V_12 ) ;
return V_50 ;
}
F_30 ( L_3 ) ;
return 0 ;
}
void F_31 ( struct V_5 * V_6 )
{
F_32 ( V_6 -> V_13 ) ;
if ( V_6 -> V_1 . V_55 ) {
F_33 ( V_6 -> V_13 ) ;
V_6 -> V_1 . V_55 = false ;
if ( V_6 -> V_52 )
F_34 ( V_6 -> V_40 ) ;
F_29 ( & V_6 -> V_12 ) ;
}
}
void F_35 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_22 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
if ( F_36 ( & V_6 -> V_1 . V_26 [ V_56 ] ) == 1 ) {
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
}
bool F_37 ( struct V_5 * V_6 , int V_56 )
{
return F_36 ( & V_6 -> V_1 . V_26 [ V_56 ] ) == 1 ;
}
void F_38 ( struct V_5 * V_6 , int V_56 )
{
unsigned long V_22 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
if ( F_39 ( & V_6 -> V_1 . V_26 [ V_56 ] ) ) {
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
}
void F_40 ( struct V_5 * V_6 , int V_58 )
{
unsigned long V_22 ;
if ( V_58 < 0 || V_58 >= V_6 -> V_51 )
return;
if ( ! V_6 -> V_13 -> V_57 )
return;
if ( F_36 ( & V_6 -> V_1 . V_32 [ V_58 ] ) == 1 ) {
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
}
void F_41 ( struct V_5 * V_6 , int V_58 )
{
unsigned long V_22 ;
if ( V_58 < 0 || V_58 >= V_6 -> V_51 )
return;
if ( ! V_6 -> V_13 -> V_57 )
return;
if ( F_39 ( & V_6 -> V_1 . V_32 [ V_58 ] ) ) {
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
}
void F_42 ( struct V_5 * V_6 , int V_59 )
{
unsigned long V_22 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
V_6 -> V_1 . V_33 [ V_59 ] = true ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
void F_43 ( struct V_5 * V_6 , int V_59 )
{
unsigned long V_22 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
V_6 -> V_1 . V_33 [ V_59 ] = false ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
void F_44 ( struct V_5 * V_6 , unsigned V_60 )
{
unsigned long V_22 ;
int V_23 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_28 ; ++ V_23 )
V_6 -> V_1 . V_29 [ V_23 ] |= ! ! ( V_60 & ( 1 << V_23 ) ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
void F_45 ( struct V_5 * V_6 , unsigned V_60 )
{
unsigned long V_22 ;
int V_23 ;
if ( ! V_6 -> V_13 -> V_57 )
return;
F_13 ( & V_6 -> V_1 . V_24 , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_28 ; ++ V_23 )
V_6 -> V_1 . V_29 [ V_23 ] &= ! ( V_60 & ( 1 << V_23 ) ) ;
F_15 ( V_6 ) ;
F_16 ( & V_6 -> V_1 . V_24 , V_22 ) ;
}
