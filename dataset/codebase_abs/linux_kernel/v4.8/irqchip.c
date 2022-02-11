int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_2 * V_7 ;
int V_8 = 0 ;
V_6 = F_2 ( V_1 -> V_9 , & V_1 -> V_10 ,
F_3 ( & V_1 -> V_11 ) ) ;
if ( V_6 && V_4 < V_6 -> V_12 ) {
F_4 (e, &irq_rt->map[gsi], link) {
V_3 [ V_8 ] = * V_7 ;
++ V_8 ;
}
}
return V_8 ;
}
int F_5 ( struct V_1 * V_1 , unsigned V_13 , unsigned V_14 )
{
struct V_5 * V_6 ;
V_6 = F_6 ( V_1 -> V_9 , & V_1 -> V_10 ) ;
return V_6 -> V_15 [ V_13 ] [ V_14 ] ;
}
int F_7 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
struct V_2 V_18 ;
if ( ! F_8 ( V_1 ) || ( V_17 -> V_19 & ~ V_20 ) )
return - V_21 ;
V_18 . V_17 . V_22 = V_17 -> V_22 ;
V_18 . V_17 . V_23 = V_17 -> V_23 ;
V_18 . V_17 . V_24 = V_17 -> V_24 ;
V_18 . V_17 . V_19 = V_17 -> V_19 ;
V_18 . V_17 . V_25 = V_17 -> V_25 ;
return F_9 ( & V_18 , V_1 , V_26 , 1 , false ) ;
}
int F_10 ( struct V_1 * V_1 , int V_27 , T_1 V_28 , int V_29 ,
bool V_30 )
{
struct V_2 V_31 [ V_32 ] ;
int V_33 = - 1 , V_34 , V_35 ;
F_11 ( V_28 , V_29 , V_27 ) ;
V_35 = F_12 ( & V_1 -> V_10 ) ;
V_34 = F_1 ( V_1 , V_31 , V_28 ) ;
F_13 ( & V_1 -> V_10 , V_35 ) ;
while ( V_34 -- ) {
int V_36 ;
V_36 = V_31 [ V_34 ] . F_14 ( & V_31 [ V_34 ] , V_1 , V_27 , V_29 ,
V_30 ) ;
if ( V_36 < 0 )
continue;
V_33 = V_36 + ( ( V_33 < 0 ) ? 0 : V_33 ) ;
}
return V_33 ;
}
static void F_15 ( struct V_5 * V_37 )
{
int V_34 ;
if ( ! V_37 )
return;
for ( V_34 = 0 ; V_34 < V_37 -> V_12 ; ++ V_34 ) {
struct V_2 * V_7 ;
struct V_38 * V_8 ;
F_16 (e, n, &rt->map[i], link) {
F_17 ( & V_7 -> V_39 ) ;
F_18 ( V_7 ) ;
}
}
F_18 ( V_37 ) ;
}
void F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_37 = F_20 ( V_1 -> V_9 ) ;
F_15 ( V_37 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_5 * V_37 ,
struct V_2 * V_7 ,
const struct V_40 * V_41 )
{
int V_36 = - V_21 ;
struct V_2 * V_42 ;
F_4 (ei, &rt->map[ue->gsi], link)
if ( V_42 -> type != V_43 ||
V_41 -> type != V_43 ||
V_41 -> V_44 . V_13 . V_13 == V_42 -> V_13 . V_13 )
return V_36 ;
V_7 -> V_4 = V_41 -> V_4 ;
V_7 -> type = V_41 -> type ;
V_36 = F_22 ( V_1 , V_7 , V_41 ) ;
if ( V_36 )
goto V_45;
if ( V_7 -> type == V_43 )
V_37 -> V_15 [ V_7 -> V_13 . V_13 ] [ V_7 -> V_13 . V_14 ] = V_7 -> V_4 ;
F_23 ( & V_7 -> V_39 , & V_37 -> V_46 [ V_7 -> V_4 ] ) ;
V_36 = 0 ;
V_45:
return V_36 ;
}
int F_24 ( struct V_1 * V_1 ,
const struct V_40 * V_41 ,
unsigned V_47 ,
unsigned V_19 )
{
struct V_5 * V_48 , * V_49 ;
struct V_2 * V_7 ;
T_1 V_34 , V_50 , V_12 = 0 ;
int V_36 ;
for ( V_34 = 0 ; V_34 < V_47 ; ++ V_34 ) {
if ( V_41 [ V_34 ] . V_4 >= V_51 )
return - V_21 ;
V_12 = F_25 ( V_12 , V_41 [ V_34 ] . V_4 ) ;
}
V_12 += 1 ;
V_48 = F_26 ( sizeof( * V_48 ) + ( V_12 * sizeof( struct V_52 ) ) ,
V_53 ) ;
if ( ! V_48 )
return - V_54 ;
V_48 -> V_12 = V_12 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ )
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ )
V_48 -> V_15 [ V_34 ] [ V_50 ] = - 1 ;
for ( V_34 = 0 ; V_34 < V_47 ; ++ V_34 ) {
V_36 = - V_54 ;
V_7 = F_26 ( sizeof( * V_7 ) , V_53 ) ;
if ( ! V_7 )
goto V_45;
V_36 = - V_21 ;
switch ( V_41 -> type ) {
case V_56 :
if ( V_41 -> V_19 & ~ V_20 )
goto V_57;
break;
default:
if ( V_41 -> V_19 )
goto V_57;
break;
}
V_36 = F_21 ( V_1 , V_48 , V_7 , V_41 ) ;
if ( V_36 )
goto V_57;
++ V_41 ;
}
F_27 ( & V_1 -> V_11 ) ;
V_49 = V_1 -> V_9 ;
F_28 ( V_1 -> V_9 , V_48 ) ;
F_29 ( V_1 ) ;
F_30 ( V_1 ) ;
F_31 ( & V_1 -> V_11 ) ;
F_32 ( V_1 ) ;
F_33 ( & V_1 -> V_10 ) ;
V_48 = V_49 ;
V_36 = 0 ;
goto V_45;
V_57:
F_18 ( V_7 ) ;
V_45:
F_15 ( V_48 ) ;
return V_36 ;
}
