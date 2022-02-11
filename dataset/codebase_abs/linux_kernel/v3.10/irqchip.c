bool F_1 ( struct V_1 * V_1 , unsigned V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
F_2 () ;
V_6 = F_3 ( V_1 -> V_7 ) -> V_8 [ V_2 ] [ V_3 ] ;
if ( V_6 != - 1 )
F_4 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_5 -> V_6 == V_6 ) {
F_5 () ;
return true ;
}
F_5 () ;
return false ;
}
void F_6 ( struct V_1 * V_1 , unsigned V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
F_7 ( V_2 , V_3 ) ;
F_2 () ;
V_6 = F_3 ( V_1 -> V_7 ) -> V_8 [ V_2 ] [ V_3 ] ;
if ( V_6 != - 1 )
F_4 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_5 -> V_6 == V_6 )
V_5 -> V_9 ( V_5 ) ;
F_5 () ;
}
void F_8 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_9 ( & V_1 -> V_10 ) ;
F_10 ( & V_5 -> V_11 , & V_1 -> V_12 ) ;
F_11 ( & V_1 -> V_10 ) ;
#ifdef F_12
F_13 ( V_1 ) ;
#endif
}
void F_14 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_9 ( & V_1 -> V_10 ) ;
F_15 ( & V_5 -> V_11 ) ;
F_11 ( & V_1 -> V_10 ) ;
F_16 () ;
#ifdef F_12
F_13 ( V_1 ) ;
#endif
}
int F_17 ( struct V_1 * V_1 , struct V_13 * V_14 )
{
struct V_15 V_16 ;
if ( ! F_18 ( V_1 ) || V_14 -> V_17 != 0 )
return - V_18 ;
V_16 . V_14 . V_19 = V_14 -> V_19 ;
V_16 . V_14 . V_20 = V_14 -> V_20 ;
V_16 . V_14 . V_21 = V_14 -> V_21 ;
return F_19 ( & V_16 , V_1 , V_22 , 1 , false ) ;
}
int F_20 ( struct V_1 * V_1 , int V_23 , T_1 V_24 , int V_25 ,
bool V_26 )
{
struct V_15 * V_27 , V_28 [ V_29 ] ;
int V_30 = - 1 , V_31 = 0 ;
struct V_32 * V_33 ;
F_21 ( V_24 , V_25 , V_23 ) ;
F_2 () ;
V_33 = F_3 ( V_1 -> V_7 ) ;
if ( V_24 < V_33 -> V_34 )
F_22 (e, &irq_rt->map[irq], link)
V_28 [ V_31 ++ ] = * V_27 ;
F_5 () ;
while( V_31 -- ) {
int V_35 ;
V_35 = V_28 [ V_31 ] . F_23 ( & V_28 [ V_31 ] , V_1 , V_23 , V_25 ,
V_26 ) ;
if ( V_35 < 0 )
continue;
V_30 = V_35 + ( ( V_30 < 0 ) ? 0 : V_30 ) ;
}
return V_30 ;
}
void F_24 ( struct V_1 * V_1 )
{
F_25 ( V_1 -> V_7 ) ;
}
static int F_26 ( struct V_32 * V_36 ,
struct V_15 * V_27 ,
const struct V_37 * V_38 )
{
int V_35 = - V_18 ;
struct V_15 * V_39 ;
F_22 (ei, &rt->map[ue->gsi], link)
if ( V_39 -> type == V_40 ||
V_38 -> type == V_40 ||
V_38 -> V_41 . V_2 . V_2 == V_39 -> V_2 . V_2 )
return V_35 ;
V_27 -> V_6 = V_38 -> V_6 ;
V_27 -> type = V_38 -> type ;
V_35 = F_27 ( V_36 , V_27 , V_38 ) ;
if ( V_35 )
goto V_42;
F_28 ( & V_27 -> V_11 , & V_36 -> V_43 [ V_27 -> V_6 ] ) ;
V_35 = 0 ;
V_42:
return V_35 ;
}
int F_29 ( struct V_1 * V_1 ,
const struct V_37 * V_38 ,
unsigned V_44 ,
unsigned V_17 )
{
struct V_32 * V_45 , * V_46 ;
T_1 V_31 , V_47 , V_34 = 0 ;
int V_35 ;
for ( V_31 = 0 ; V_31 < V_44 ; ++ V_31 ) {
if ( V_38 [ V_31 ] . V_6 >= V_48 )
return - V_18 ;
V_34 = F_30 ( V_34 , V_38 [ V_31 ] . V_6 ) ;
}
V_34 += 1 ;
V_45 = F_31 ( sizeof( * V_45 ) + ( V_34 * sizeof( struct V_49 ) )
+ ( V_44 * sizeof( struct V_15 ) ) ,
V_50 ) ;
if ( ! V_45 )
return - V_51 ;
V_45 -> V_52 = ( void * ) & V_45 -> V_43 [ V_34 ] ;
V_45 -> V_34 = V_34 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ )
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ )
V_45 -> V_8 [ V_31 ] [ V_47 ] = - 1 ;
for ( V_31 = 0 ; V_31 < V_44 ; ++ V_31 ) {
V_35 = - V_18 ;
if ( V_38 -> V_17 )
goto V_42;
V_35 = F_26 ( V_45 , & V_45 -> V_52 [ V_31 ] , V_38 ) ;
if ( V_35 )
goto V_42;
++ V_38 ;
}
F_9 ( & V_1 -> V_10 ) ;
V_46 = V_1 -> V_7 ;
F_32 ( V_1 , V_45 ) ;
F_11 ( & V_1 -> V_10 ) ;
F_16 () ;
V_45 = V_46 ;
V_35 = 0 ;
V_42:
F_25 ( V_45 ) ;
return V_35 ;
}
