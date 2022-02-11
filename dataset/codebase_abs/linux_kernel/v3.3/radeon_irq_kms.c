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
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_5 -> V_18 . V_19 [ V_16 ] = false ;
V_5 -> V_18 . V_20 = false ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ )
V_5 -> V_18 . V_22 [ V_16 ] = false ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_5 -> V_18 . V_24 [ V_16 ] = false ;
V_5 -> V_18 . V_25 [ V_16 ] = false ;
}
F_9 ( V_5 ) ;
F_2 ( V_5 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned V_16 ;
V_2 -> V_26 = 0x001fffff ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_5 -> V_18 . V_19 [ V_16 ] = true ;
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
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_5 -> V_18 . V_19 [ V_16 ] = false ;
V_5 -> V_18 . V_20 = false ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ )
V_5 -> V_18 . V_22 [ V_16 ] = false ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_5 -> V_18 . V_24 [ V_16 ] = false ;
V_5 -> V_18 . V_25 [ V_16 ] = false ;
}
F_9 ( V_5 ) ;
}
static bool F_12 ( struct V_4 * V_5 )
{
if ( V_5 -> V_27 < V_28 )
return false ;
if ( V_5 -> V_29 & V_30 )
return false ;
if ( V_31 == 1 )
return true ;
else if ( V_31 == 0 )
return false ;
if ( ( V_5 -> V_32 -> V_33 == 0x791f ) &&
( V_5 -> V_32 -> V_34 == 0x103c ) &&
( V_5 -> V_32 -> V_35 == 0x30c2 ) )
return true ;
if ( ( V_5 -> V_32 -> V_33 == 0x791f ) &&
( V_5 -> V_32 -> V_34 == 0x1028 ) &&
( V_5 -> V_32 -> V_35 == 0x01fc ) )
return true ;
if ( ( V_5 -> V_32 -> V_33 == 0x791f ) &&
( V_5 -> V_32 -> V_34 == 0x1028 ) &&
( V_5 -> V_32 -> V_35 == 0x01fd ) )
return true ;
if ( V_5 -> V_29 & V_36 ) {
if ( V_5 -> V_27 >= V_37 )
return true ;
return false ;
}
return true ;
}
int F_13 ( struct V_4 * V_5 )
{
int V_16 ;
int V_38 = 0 ;
F_14 ( & V_5 -> V_9 , F_3 ) ;
F_15 ( & V_5 -> V_18 . V_39 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_40 ; V_16 ++ )
F_15 ( & V_5 -> V_18 . V_41 [ V_16 ] ) ;
V_38 = F_16 ( V_5 -> V_10 , V_5 -> V_40 ) ;
if ( V_38 ) {
return V_38 ;
}
V_5 -> V_42 = 0 ;
if ( F_12 ( V_5 ) ) {
int V_43 = F_17 ( V_5 -> V_32 ) ;
if ( ! V_43 ) {
V_5 -> V_42 = 1 ;
F_18 ( V_5 -> V_2 , L_1 ) ;
}
}
V_5 -> V_18 . V_44 = true ;
V_38 = F_19 ( V_5 -> V_10 ) ;
if ( V_38 ) {
V_5 -> V_18 . V_44 = false ;
return V_38 ;
}
F_20 ( L_2 ) ;
return 0 ;
}
void F_21 ( struct V_4 * V_5 )
{
F_22 ( V_5 -> V_10 ) ;
if ( V_5 -> V_18 . V_44 ) {
F_23 ( V_5 -> V_10 ) ;
V_5 -> V_18 . V_44 = false ;
if ( V_5 -> V_42 )
F_24 ( V_5 -> V_32 ) ;
}
F_25 ( & V_5 -> V_9 ) ;
}
void F_26 ( struct V_4 * V_5 , int V_45 )
{
unsigned long V_46 ;
F_27 ( & V_5 -> V_18 . V_39 , V_46 ) ;
if ( V_5 -> V_10 -> V_47 && ( ++ V_5 -> V_18 . V_48 [ V_45 ] == 1 ) ) {
V_5 -> V_18 . V_19 [ V_45 ] = true ;
F_9 ( V_5 ) ;
}
F_28 ( & V_5 -> V_18 . V_39 , V_46 ) ;
}
void F_29 ( struct V_4 * V_5 , int V_45 )
{
unsigned long V_46 ;
F_27 ( & V_5 -> V_18 . V_39 , V_46 ) ;
F_30 ( V_5 -> V_10 -> V_47 && V_5 -> V_18 . V_48 [ V_45 ] <= 0 ) ;
if ( V_5 -> V_10 -> V_47 && ( -- V_5 -> V_18 . V_48 [ V_45 ] == 0 ) ) {
V_5 -> V_18 . V_19 [ V_45 ] = false ;
F_9 ( V_5 ) ;
}
F_28 ( & V_5 -> V_18 . V_39 , V_46 ) ;
}
void F_31 ( struct V_4 * V_5 , int V_49 )
{
unsigned long V_46 ;
if ( V_49 < 0 || V_49 >= V_5 -> V_40 )
return;
F_27 ( & V_5 -> V_18 . V_41 [ V_49 ] , V_46 ) ;
if ( V_5 -> V_10 -> V_47 && ( ++ V_5 -> V_18 . V_50 [ V_49 ] == 1 ) ) {
V_5 -> V_18 . V_25 [ V_49 ] = true ;
F_9 ( V_5 ) ;
}
F_28 ( & V_5 -> V_18 . V_41 [ V_49 ] , V_46 ) ;
}
void F_32 ( struct V_4 * V_5 , int V_49 )
{
unsigned long V_46 ;
if ( V_49 < 0 || V_49 >= V_5 -> V_40 )
return;
F_27 ( & V_5 -> V_18 . V_41 [ V_49 ] , V_46 ) ;
F_30 ( V_5 -> V_10 -> V_47 && V_5 -> V_18 . V_50 [ V_49 ] <= 0 ) ;
if ( V_5 -> V_10 -> V_47 && ( -- V_5 -> V_18 . V_50 [ V_49 ] == 0 ) ) {
V_5 -> V_18 . V_25 [ V_49 ] = false ;
F_9 ( V_5 ) ;
}
F_28 ( & V_5 -> V_18 . V_41 [ V_49 ] , V_46 ) ;
}
