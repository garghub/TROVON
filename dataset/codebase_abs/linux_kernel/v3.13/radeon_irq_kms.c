T_1 F_1 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_5 ) ;
if ( V_7 == V_8 )
F_3 ( V_2 -> V_2 ) ;
return V_7 ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_5 ( V_10 , struct V_4 ,
V_11 ) ;
struct V_1 * V_2 = V_5 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_15 * V_16 ;
if ( V_14 -> V_17 ) {
F_6 (connector, &mode_config->connector_list, head)
F_7 ( V_16 ) ;
}
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_5 ( V_10 , struct V_4 ,
V_18 ) ;
F_10 ( V_5 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_19 ;
unsigned V_20 ;
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ )
F_13 ( & V_5 -> V_21 . V_24 [ V_20 ] , 0 ) ;
V_5 -> V_21 . V_25 = false ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ )
V_5 -> V_21 . V_27 [ V_20 ] = false ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
V_5 -> V_21 . V_29 [ V_20 ] = false ;
F_13 ( & V_5 -> V_21 . V_30 [ V_20 ] , 0 ) ;
V_5 -> V_21 . V_31 [ V_20 ] = false ;
}
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
F_2 ( V_5 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_32 = 0x001fffff ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_19 ;
unsigned V_20 ;
if ( V_5 == NULL ) {
return;
}
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ )
F_13 ( & V_5 -> V_21 . V_24 [ V_20 ] , 0 ) ;
V_5 -> V_21 . V_25 = false ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ )
V_5 -> V_21 . V_27 [ V_20 ] = false ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
V_5 -> V_21 . V_29 [ V_20 ] = false ;
F_13 ( & V_5 -> V_21 . V_30 [ V_20 ] , 0 ) ;
V_5 -> V_21 . V_31 [ V_20 ] = false ;
}
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
static bool F_18 ( struct V_4 * V_5 )
{
if ( V_5 -> V_33 < V_34 )
return false ;
if ( V_5 -> V_35 & V_36 )
return false ;
if ( V_37 == 1 )
return true ;
else if ( V_37 == 0 )
return false ;
if ( ( V_5 -> V_38 -> V_39 == 0x791f ) &&
( V_5 -> V_38 -> V_40 == 0x103c ) &&
( V_5 -> V_38 -> V_41 == 0x30c2 ) )
return true ;
if ( ( V_5 -> V_38 -> V_39 == 0x791f ) &&
( V_5 -> V_38 -> V_40 == 0x1028 ) &&
( V_5 -> V_38 -> V_41 == 0x01fc ) )
return true ;
if ( ( V_5 -> V_38 -> V_39 == 0x791f ) &&
( V_5 -> V_38 -> V_40 == 0x1028 ) &&
( V_5 -> V_38 -> V_41 == 0x01fd ) )
return true ;
if ( ( V_5 -> V_38 -> V_39 == 0x791f ) &&
( V_5 -> V_38 -> V_40 == 0x107b ) &&
( V_5 -> V_38 -> V_41 == 0x0185 ) )
return true ;
if ( V_5 -> V_33 == V_42 )
return true ;
if ( V_5 -> V_33 == V_43 )
return false ;
if ( V_5 -> V_35 & V_44 ) {
if ( V_5 -> V_33 >= V_45 )
return true ;
return false ;
}
return true ;
}
int F_19 ( struct V_4 * V_5 )
{
int V_46 = 0 ;
F_20 ( & V_5 -> V_21 . V_22 ) ;
V_46 = F_21 ( V_5 -> V_12 , V_5 -> V_47 ) ;
if ( V_46 ) {
return V_46 ;
}
V_5 -> V_48 = 0 ;
if ( F_18 ( V_5 ) ) {
int V_7 = F_22 ( V_5 -> V_38 ) ;
if ( ! V_7 ) {
V_5 -> V_48 = 1 ;
F_23 ( V_5 -> V_2 , L_1 ) ;
}
}
F_24 ( & V_5 -> V_11 , F_4 ) ;
F_24 ( & V_5 -> V_49 , V_50 ) ;
F_24 ( & V_5 -> V_18 , F_9 ) ;
V_5 -> V_21 . V_51 = true ;
V_46 = F_25 ( V_5 -> V_12 ) ;
if ( V_46 ) {
V_5 -> V_21 . V_51 = false ;
F_26 ( & V_5 -> V_11 ) ;
return V_46 ;
}
F_27 ( L_2 ) ;
return 0 ;
}
void F_28 ( struct V_4 * V_5 )
{
F_29 ( V_5 -> V_12 ) ;
if ( V_5 -> V_21 . V_51 ) {
F_30 ( V_5 -> V_12 ) ;
V_5 -> V_21 . V_51 = false ;
if ( V_5 -> V_48 )
F_31 ( V_5 -> V_38 ) ;
F_26 ( & V_5 -> V_11 ) ;
}
}
void F_32 ( struct V_4 * V_5 , int V_52 )
{
unsigned long V_19 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
if ( F_33 ( & V_5 -> V_21 . V_24 [ V_52 ] ) == 1 ) {
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
}
void F_34 ( struct V_4 * V_5 , int V_52 )
{
unsigned long V_19 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
if ( F_35 ( & V_5 -> V_21 . V_24 [ V_52 ] ) ) {
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
}
void F_36 ( struct V_4 * V_5 , int V_54 )
{
unsigned long V_19 ;
if ( V_54 < 0 || V_54 >= V_5 -> V_47 )
return;
if ( ! V_5 -> V_12 -> V_53 )
return;
if ( F_33 ( & V_5 -> V_21 . V_30 [ V_54 ] ) == 1 ) {
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
}
void F_37 ( struct V_4 * V_5 , int V_54 )
{
unsigned long V_19 ;
if ( V_54 < 0 || V_54 >= V_5 -> V_47 )
return;
if ( ! V_5 -> V_12 -> V_53 )
return;
if ( F_35 ( & V_5 -> V_21 . V_30 [ V_54 ] ) ) {
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
}
void F_38 ( struct V_4 * V_5 , int V_55 )
{
unsigned long V_19 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
V_5 -> V_21 . V_31 [ V_55 ] = true ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
void F_39 ( struct V_4 * V_5 , int V_55 )
{
unsigned long V_19 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
V_5 -> V_21 . V_31 [ V_55 ] = false ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
void F_40 ( struct V_4 * V_5 , unsigned V_56 )
{
unsigned long V_19 ;
int V_20 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_5 -> V_21 . V_27 [ V_20 ] |= ! ! ( V_56 & ( 1 << V_20 ) ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
void F_41 ( struct V_4 * V_5 , unsigned V_56 )
{
unsigned long V_19 ;
int V_20 ;
if ( ! V_5 -> V_12 -> V_53 )
return;
F_12 ( & V_5 -> V_21 . V_22 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; ++ V_20 )
V_5 -> V_21 . V_27 [ V_20 ] &= ! ( V_56 & ( 1 << V_20 ) ) ;
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_21 . V_22 , V_19 ) ;
}
