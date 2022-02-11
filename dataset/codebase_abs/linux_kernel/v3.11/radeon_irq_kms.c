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
static void F_8 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_4 ( V_8 , struct V_4 ,
V_16 ) ;
F_9 ( V_5 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_17 ;
unsigned V_18 ;
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ )
F_12 ( & V_5 -> V_19 . V_22 [ V_18 ] , 0 ) ;
V_5 -> V_19 . V_23 = false ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ )
V_5 -> V_19 . V_25 [ V_18 ] = false ;
for ( V_18 = 0 ; V_18 < V_26 ; V_18 ++ ) {
V_5 -> V_19 . V_27 [ V_18 ] = false ;
F_12 ( & V_5 -> V_19 . V_28 [ V_18 ] , 0 ) ;
V_5 -> V_19 . V_29 [ V_18 ] = false ;
}
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
F_2 ( V_5 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_30 = 0x001fffff ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_17 ;
unsigned V_18 ;
if ( V_5 == NULL ) {
return;
}
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ )
F_12 ( & V_5 -> V_19 . V_22 [ V_18 ] , 0 ) ;
V_5 -> V_19 . V_23 = false ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ )
V_5 -> V_19 . V_25 [ V_18 ] = false ;
for ( V_18 = 0 ; V_18 < V_26 ; V_18 ++ ) {
V_5 -> V_19 . V_27 [ V_18 ] = false ;
F_12 ( & V_5 -> V_19 . V_28 [ V_18 ] , 0 ) ;
V_5 -> V_19 . V_29 [ V_18 ] = false ;
}
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
static bool F_17 ( struct V_4 * V_5 )
{
if ( V_5 -> V_31 < V_32 )
return false ;
if ( V_5 -> V_33 & V_34 )
return false ;
if ( V_35 == 1 )
return true ;
else if ( V_35 == 0 )
return false ;
if ( ( V_5 -> V_36 -> V_37 == 0x791f ) &&
( V_5 -> V_36 -> V_38 == 0x103c ) &&
( V_5 -> V_36 -> V_39 == 0x30c2 ) )
return true ;
if ( ( V_5 -> V_36 -> V_37 == 0x791f ) &&
( V_5 -> V_36 -> V_38 == 0x1028 ) &&
( V_5 -> V_36 -> V_39 == 0x01fc ) )
return true ;
if ( ( V_5 -> V_36 -> V_37 == 0x791f ) &&
( V_5 -> V_36 -> V_38 == 0x1028 ) &&
( V_5 -> V_36 -> V_39 == 0x01fd ) )
return true ;
if ( ( V_5 -> V_36 -> V_37 == 0x791f ) &&
( V_5 -> V_36 -> V_38 == 0x107b ) &&
( V_5 -> V_36 -> V_39 == 0x0185 ) )
return true ;
if ( V_5 -> V_31 == V_40 )
return true ;
if ( V_5 -> V_31 == V_41 )
return false ;
if ( V_5 -> V_33 & V_42 ) {
if ( V_5 -> V_31 >= V_43 )
return true ;
return false ;
}
return true ;
}
int F_18 ( struct V_4 * V_5 )
{
int V_44 = 0 ;
F_19 ( & V_5 -> V_19 . V_20 ) ;
V_44 = F_20 ( V_5 -> V_10 , V_5 -> V_45 ) ;
if ( V_44 ) {
return V_44 ;
}
V_5 -> V_46 = 0 ;
if ( F_17 ( V_5 ) ) {
int V_47 = F_21 ( V_5 -> V_36 ) ;
if ( ! V_47 ) {
V_5 -> V_46 = 1 ;
F_22 ( V_5 -> V_2 , L_1 ) ;
}
}
V_5 -> V_19 . V_48 = true ;
V_44 = F_23 ( V_5 -> V_10 ) ;
if ( V_44 ) {
V_5 -> V_19 . V_48 = false ;
return V_44 ;
}
F_24 ( & V_5 -> V_9 , F_3 ) ;
F_24 ( & V_5 -> V_49 , V_50 ) ;
F_24 ( & V_5 -> V_16 , F_8 ) ;
F_25 ( L_2 ) ;
return 0 ;
}
void F_26 ( struct V_4 * V_5 )
{
F_27 ( V_5 -> V_10 ) ;
if ( V_5 -> V_19 . V_48 ) {
F_28 ( V_5 -> V_10 ) ;
V_5 -> V_19 . V_48 = false ;
if ( V_5 -> V_46 )
F_29 ( V_5 -> V_36 ) ;
F_30 ( & V_5 -> V_9 ) ;
}
}
void F_31 ( struct V_4 * V_5 , int V_51 )
{
unsigned long V_17 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
if ( F_32 ( & V_5 -> V_19 . V_22 [ V_51 ] ) == 1 ) {
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
}
void F_33 ( struct V_4 * V_5 , int V_51 )
{
unsigned long V_17 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
if ( F_34 ( & V_5 -> V_19 . V_22 [ V_51 ] ) ) {
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
}
void F_35 ( struct V_4 * V_5 , int V_53 )
{
unsigned long V_17 ;
if ( V_53 < 0 || V_53 >= V_5 -> V_45 )
return;
if ( ! V_5 -> V_10 -> V_52 )
return;
if ( F_32 ( & V_5 -> V_19 . V_28 [ V_53 ] ) == 1 ) {
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
}
void F_36 ( struct V_4 * V_5 , int V_53 )
{
unsigned long V_17 ;
if ( V_53 < 0 || V_53 >= V_5 -> V_45 )
return;
if ( ! V_5 -> V_10 -> V_52 )
return;
if ( F_34 ( & V_5 -> V_19 . V_28 [ V_53 ] ) ) {
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
}
void F_37 ( struct V_4 * V_5 , int V_54 )
{
unsigned long V_17 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
V_5 -> V_19 . V_29 [ V_54 ] = true ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
void F_38 ( struct V_4 * V_5 , int V_54 )
{
unsigned long V_17 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
V_5 -> V_19 . V_29 [ V_54 ] = false ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
void F_39 ( struct V_4 * V_5 , unsigned V_55 )
{
unsigned long V_17 ;
int V_18 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_24 ; ++ V_18 )
V_5 -> V_19 . V_25 [ V_18 ] |= ! ! ( V_55 & ( 1 << V_18 ) ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
void F_40 ( struct V_4 * V_5 , unsigned V_55 )
{
unsigned long V_17 ;
int V_18 ;
if ( ! V_5 -> V_10 -> V_52 )
return;
F_11 ( & V_5 -> V_19 . V_20 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_24 ; ++ V_18 )
V_5 -> V_19 . V_25 [ V_18 ] &= ! ( V_55 & ( 1 << V_18 ) ) ;
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_19 . V_20 , V_17 ) ;
}
