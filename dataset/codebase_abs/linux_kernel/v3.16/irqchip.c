bool F_1 ( struct V_1 * V_1 , unsigned V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 ;
V_7 = F_2 ( & V_1 -> V_8 ) ;
V_6 = F_3 ( V_1 -> V_9 , & V_1 -> V_8 ) -> V_10 [ V_2 ] [ V_3 ] ;
if ( V_6 != - 1 )
F_4 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_5 -> V_6 == V_6 ) {
F_5 ( & V_1 -> V_8 , V_7 ) ;
return true ;
}
F_5 ( & V_1 -> V_8 , V_7 ) ;
return false ;
}
void F_6 ( struct V_1 * V_1 , unsigned V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 ;
F_7 ( V_2 , V_3 ) ;
V_7 = F_2 ( & V_1 -> V_8 ) ;
V_6 = F_3 ( V_1 -> V_9 , & V_1 -> V_8 ) -> V_10 [ V_2 ] [ V_3 ] ;
if ( V_6 != - 1 )
F_4 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_5 -> V_6 == V_6 )
V_5 -> V_11 ( V_5 ) ;
F_5 ( & V_1 -> V_8 , V_7 ) ;
}
void F_8 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_9 ( & V_1 -> V_12 ) ;
F_10 ( & V_5 -> V_13 , & V_1 -> V_14 ) ;
F_11 ( & V_1 -> V_12 ) ;
#ifdef F_12
F_13 ( V_1 ) ;
#endif
}
void F_14 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_9 ( & V_1 -> V_12 ) ;
F_15 ( & V_5 -> V_13 ) ;
F_11 ( & V_1 -> V_12 ) ;
F_16 ( & V_1 -> V_8 ) ;
#ifdef F_12
F_13 ( V_1 ) ;
#endif
}
int F_17 ( struct V_1 * V_1 , struct V_15 * V_16 )
{
struct V_17 V_18 ;
if ( ! F_18 ( V_1 ) || V_16 -> V_19 != 0 )
return - V_20 ;
V_18 . V_16 . V_21 = V_16 -> V_21 ;
V_18 . V_16 . V_22 = V_16 -> V_22 ;
V_18 . V_16 . V_23 = V_16 -> V_23 ;
return F_19 ( & V_18 , V_1 , V_24 , 1 , false ) ;
}
int F_20 ( struct V_1 * V_1 , int V_25 , T_1 V_26 , int V_27 ,
bool V_28 )
{
struct V_17 * V_29 , V_30 [ V_31 ] ;
int V_32 = - 1 , V_33 = 0 , V_7 ;
struct V_34 * V_35 ;
F_21 ( V_26 , V_27 , V_25 ) ;
V_7 = F_2 ( & V_1 -> V_8 ) ;
V_35 = F_3 ( V_1 -> V_9 , & V_1 -> V_8 ) ;
if ( V_26 < V_35 -> V_36 )
F_22 (e, &irq_rt->map[irq], link)
V_30 [ V_33 ++ ] = * V_29 ;
F_5 ( & V_1 -> V_8 , V_7 ) ;
while( V_33 -- ) {
int V_37 ;
V_37 = V_30 [ V_33 ] . F_23 ( & V_30 [ V_33 ] , V_1 , V_25 , V_27 ,
V_28 ) ;
if ( V_37 < 0 )
continue;
V_32 = V_37 + ( ( V_32 < 0 ) ? 0 : V_32 ) ;
}
return V_32 ;
}
void F_24 ( struct V_1 * V_1 )
{
F_25 ( V_1 -> V_9 ) ;
}
static int F_26 ( struct V_34 * V_38 ,
struct V_17 * V_29 ,
const struct V_39 * V_40 )
{
int V_37 = - V_20 ;
struct V_17 * V_41 ;
F_22 (ei, &rt->map[ue->gsi], link)
if ( V_41 -> type == V_42 ||
V_40 -> type == V_42 ||
V_40 -> V_43 . V_2 . V_2 == V_41 -> V_2 . V_2 )
return V_37 ;
V_29 -> V_6 = V_40 -> V_6 ;
V_29 -> type = V_40 -> type ;
V_37 = F_27 ( V_38 , V_29 , V_40 ) ;
if ( V_37 )
goto V_44;
F_28 ( & V_29 -> V_13 , & V_38 -> V_45 [ V_29 -> V_6 ] ) ;
V_37 = 0 ;
V_44:
return V_37 ;
}
int F_29 ( struct V_1 * V_1 ,
const struct V_39 * V_40 ,
unsigned V_46 ,
unsigned V_19 )
{
struct V_34 * V_47 , * V_48 ;
T_1 V_33 , V_49 , V_36 = 0 ;
int V_37 ;
for ( V_33 = 0 ; V_33 < V_46 ; ++ V_33 ) {
if ( V_40 [ V_33 ] . V_6 >= V_50 )
return - V_20 ;
V_36 = F_30 ( V_36 , V_40 [ V_33 ] . V_6 ) ;
}
V_36 += 1 ;
V_47 = F_31 ( sizeof( * V_47 ) + ( V_36 * sizeof( struct V_51 ) )
+ ( V_46 * sizeof( struct V_17 ) ) ,
V_52 ) ;
if ( ! V_47 )
return - V_53 ;
V_47 -> V_54 = ( void * ) & V_47 -> V_45 [ V_36 ] ;
V_47 -> V_36 = V_36 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
for ( V_49 = 0 ; V_49 < V_55 ; V_49 ++ )
V_47 -> V_10 [ V_33 ] [ V_49 ] = - 1 ;
for ( V_33 = 0 ; V_33 < V_46 ; ++ V_33 ) {
V_37 = - V_20 ;
if ( V_40 -> V_19 )
goto V_44;
V_37 = F_26 ( V_47 , & V_47 -> V_54 [ V_33 ] , V_40 ) ;
if ( V_37 )
goto V_44;
++ V_40 ;
}
F_9 ( & V_1 -> V_12 ) ;
V_48 = V_1 -> V_9 ;
F_32 ( V_1 , V_47 ) ;
F_11 ( & V_1 -> V_12 ) ;
F_33 ( & V_1 -> V_8 ) ;
V_47 = V_48 ;
V_37 = 0 ;
V_44:
F_25 ( V_47 ) ;
return V_37 ;
}
