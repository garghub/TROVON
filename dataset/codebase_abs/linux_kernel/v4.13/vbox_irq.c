static void F_1 ( void )
{
F_2 ( ( V_1 ) ~ 0 , V_2 ) ;
}
static V_1 F_3 ( struct V_3 * V_4 )
{
return F_4 ( V_4 -> V_5 + V_6 ) ;
}
void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_7 ) ;
}
T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_11 -> V_12 ;
V_1 V_13 = F_3 ( V_4 ) ;
if ( ! ( V_13 & V_14 ) )
return V_15 ;
if ( V_13 &
( V_16 | V_17 ) &&
! ( V_13 & V_18 ) )
F_5 ( V_4 ) ;
F_1 () ;
return V_19 ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_20 * V_21 , * V_22 ;
bool V_23 = true ;
T_2 V_24 = 0 ;
int V_25 , V_26 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_27 ; ++ V_25 ) {
for ( V_26 = 0 ; V_26 < V_25 ; ++ V_26 ) {
V_21 = & V_4 -> V_28 [ V_25 ] ;
V_22 = & V_4 -> V_28 [ V_26 ] ;
if ( V_21 -> V_29 && V_22 -> V_29 ) {
if ( V_21 -> V_30 >= 0xffff ||
V_21 -> V_31 >= 0xffff ||
V_22 -> V_30 >= 0xffff ||
V_22 -> V_31 >= 0xffff ||
( V_21 -> V_30 <
V_22 -> V_30 + ( V_22 -> V_32 & 0x8fff ) &&
V_21 -> V_30 + ( V_21 -> V_32 & 0x8fff ) >
V_22 -> V_30 ) ||
( V_21 -> V_31 <
V_22 -> V_31 + ( V_22 -> V_33 & 0x8fff ) &&
V_21 -> V_31 + ( V_21 -> V_33 & 0x8fff ) >
V_22 -> V_31 ) )
V_23 = false ;
}
}
}
if ( ! V_23 )
for ( V_25 = 0 ; V_25 < V_4 -> V_27 ; ++ V_25 ) {
if ( V_4 -> V_28 [ V_25 ] . V_29 ) {
V_4 -> V_28 [ V_25 ] . V_30 = V_24 ;
V_4 -> V_28 [ V_25 ] . V_31 = 0 ;
V_24 +=
V_4 -> V_28 [ V_25 ] . V_32 & 0x8fff ;
}
}
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_20 * V_38 ;
T_2 V_39 ;
bool V_40 ;
unsigned int V_41 ;
int V_42 ;
V_42 = F_10 ( V_4 -> V_43 , V_4 -> V_27 ,
V_4 -> V_28 ) ;
if ( V_42 ) {
F_11 ( L_1 , V_42 ) ;
return;
}
F_8 ( V_4 ) ;
F_12 ( V_11 ) ;
F_13 (connector, &dev->mode_config.connector_list, head) {
V_37 = F_14 ( V_35 ) ;
V_38 = & V_4 -> V_28 [ V_37 -> V_44 -> V_41 ] ;
if ( V_38 -> V_45 != V_46 )
continue;
V_40 = ! ( V_38 -> V_29 ) ;
V_41 = V_37 -> V_44 -> V_41 ;
V_37 -> V_47 . V_48 = V_38 -> V_32 & 0x8fff ;
V_37 -> V_47 . V_49 = V_38 -> V_33 & 0x8fff ;
V_37 -> V_44 -> V_50 = V_38 -> V_30 ;
V_37 -> V_44 -> V_51 = V_38 -> V_31 ;
V_37 -> V_47 . V_40 = V_40 ;
if ( V_37 -> V_44 -> V_40 == V_40 )
continue;
if ( V_40 )
V_39 = V_52 | V_53 ;
else
V_39 = V_52 | V_54 ;
F_15 ( V_4 -> V_43 , V_41 , 0 , 0 , 0 ,
V_38 -> V_32 * 4 , V_38 -> V_32 ,
V_38 -> V_33 , 0 , V_39 ) ;
V_37 -> V_44 -> V_40 = V_40 ;
}
F_16 ( V_11 ) ;
}
static void F_17 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_18 ( V_56 , struct V_3 ,
V_7 ) ;
F_9 ( V_4 ) ;
F_19 ( V_4 -> V_11 ) ;
}
int F_20 ( struct V_3 * V_4 )
{
F_21 ( & V_4 -> V_7 , F_17 ) ;
F_9 ( V_4 ) ;
return F_22 ( V_4 -> V_11 , V_4 -> V_11 -> V_57 -> V_8 ) ;
}
void F_23 ( struct V_3 * V_4 )
{
F_24 ( V_4 -> V_11 ) ;
F_25 ( & V_4 -> V_7 ) ;
}
