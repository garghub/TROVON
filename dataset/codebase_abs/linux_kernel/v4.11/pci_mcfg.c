static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( ! memcmp ( V_2 -> V_6 , V_7 , V_8 ) &&
! memcmp ( V_2 -> V_9 , V_10 ,
V_11 ) &&
V_2 -> V_12 == V_13 &&
V_2 -> V_3 == V_3 &&
F_2 ( & V_2 -> V_5 , V_5 ) )
return 1 ;
return 0 ;
}
static void F_3 ( struct V_14 * V_15 ,
struct V_4 * V_16 ,
struct V_17 * * V_18 )
{
#ifdef F_4
T_1 V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = & V_15 -> V_19 ;
struct V_1 * V_2 ;
int V_20 ;
for ( V_20 = 0 , V_2 = V_21 ; V_20 < F_5 ( V_21 ) ; V_20 ++ , V_2 ++ ) {
if ( F_1 ( V_2 , V_3 , V_5 ) ) {
if ( V_2 -> V_16 . V_22 )
* V_16 = V_2 -> V_16 ;
if ( V_2 -> V_23 )
* V_18 = V_2 -> V_23 ;
F_6 ( & V_15 -> V_24 -> V_25 , L_1 ,
V_16 , V_5 , * V_18 ) ;
return;
}
}
#endif
}
int F_7 ( struct V_14 * V_15 , struct V_4 * V_16 ,
struct V_17 * * V_18 )
{
struct V_17 * V_23 = & V_26 ;
struct V_4 * V_27 = & V_15 -> V_19 ;
T_1 V_28 = V_15 -> V_3 ;
struct V_29 * V_30 ;
struct V_4 V_31 ;
if ( V_15 -> V_32 )
goto V_33;
F_8 (e, &pci_mcfg_list, list) {
if ( V_30 -> V_3 == V_28 && V_30 -> V_34 <= V_27 -> V_22 &&
V_30 -> V_35 >= V_27 -> V_36 ) {
V_15 -> V_32 = V_30 -> V_37 ;
}
}
V_33:
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( V_15 -> V_32 ) {
V_31 . V_22 = V_15 -> V_32 + ( V_27 -> V_22 << 20 ) ;
V_31 . V_36 = V_31 . V_22 + ( F_9 ( V_27 ) << 20 ) - 1 ;
V_31 . V_38 = V_39 ;
}
F_3 ( V_15 , & V_31 , & V_23 ) ;
if ( ! V_31 . V_22 )
return - V_40 ;
* V_16 = V_31 ;
* V_18 = V_23 ;
return 0 ;
}
static T_2 int F_10 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_29 * V_30 , * V_47 ;
int V_20 , V_48 ;
if ( V_42 -> V_49 < sizeof( struct V_43 ) )
return - V_50 ;
V_48 = ( V_42 -> V_49 - sizeof( struct V_43 ) ) /
sizeof( struct V_45 ) ;
V_44 = (struct V_43 * ) V_42 ;
V_46 = (struct V_45 * ) & V_44 [ 1 ] ;
V_47 = F_11 ( V_48 , sizeof( * V_47 ) , V_51 ) ;
if ( ! V_47 )
return - V_52 ;
for ( V_20 = 0 , V_30 = V_47 ; V_20 < V_48 ; V_20 ++ , V_46 ++ , V_30 ++ ) {
V_30 -> V_3 = V_46 -> V_53 ;
V_30 -> V_37 = V_46 -> V_54 ;
V_30 -> V_34 = V_46 -> V_55 ;
V_30 -> V_35 = V_46 -> V_56 ;
F_12 ( & V_30 -> V_57 , & V_58 ) ;
}
#ifdef F_4
memcpy ( V_7 , V_42 -> V_6 , V_8 ) ;
memcpy ( V_10 , V_42 -> V_9 , V_11 ) ;
V_13 = V_42 -> V_12 ;
#endif
F_13 ( L_2 , V_48 ) ;
return 0 ;
}
void T_2 F_14 ( void )
{
int V_59 = F_15 ( V_60 , F_10 ) ;
if ( V_59 )
F_16 ( L_3 , V_59 ) ;
}
